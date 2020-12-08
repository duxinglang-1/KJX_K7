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
 *  gui_effect_arm_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI effect engine in ARM code 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#include "gui_effect_oem.h"

#if defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)

 
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "kal_public_api.h"
#include "MMI_fw_trc.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "DebugInitDef_Int.h"

#include <math.h>
#include "gui.h"
#include "gdi_include.h"
#include "gui_effect_oem.h"

#include "gdi_linear_transform.h"
#include "init_memory_stack.h"

/* no SSE delay for MT6228 and upper */
#define GUI_SCREEN_SWITCH_EFFECT_MIN_CAPABLE_CHIP_ID    6228

/* SSE penality delay in milli-seconds for low-end chips */
#define GUI_SCREEN_SWITCH_EFFECT_DELIBERATE_DELAY_IN_MS 100

/* RGB565 macros for transform */
#define R_OF_RGB565(c)              (((c) << 16) >> 27)
#define G_OF_RGB565(c)              (((c) << 21) >> 26)
#define B_OF_RGB565(c)              (((c) << 27) >> 27)
#define RGB565(r, g, b)             (((r) << 11) | ((g) << 5) | (b))

#define GUI_SCREEN_SWITCH_EFFECT_CACHED_STACK_SIZE  4096

/* fast point in rect check */
#define GUI_SSE_IS_POINT_IN_RECT(x, y, rect_x, rect_y, rect_w, rect_h)  (((U32)((x) - (rect_x)) < (rect_w)) && ((U32)((y) - (rect_y)) < (rect_h)))

#define GUI_SSE_USE_HW_LT

#define GUI_SSE_FSWAP(_x, _y) \
do \
{ \
    float _temp; \
    _temp = _x; \
    _x = _y; \
    _y = _temp; \
} while (0)

#define GUI_SSE_TO_FP(x)  ((float)(x) / (float)(1 << GUI_EFFECT_TRANSFORM_PRECISION_BITS))

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if defined(__ARM9_MMU__) && defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI", rwdata = "CACHEDRW" 
/* L1$ed stack for ARM9 */
// TODO: remove this when MMI stack is L1$ed.
static U32 g_gui_screen_switch_effect_cached_stack[GUI_SCREEN_SWITCH_EFFECT_CACHED_STACK_SIZE / 4];
#pragma arm section zidata, rwdata
#endif /* defined(__ARM9_MMU__) && defined(__MTK_TARGET__) */

extern S32 g_gui_screen_switch_effect_type;
extern S32 g_gui_screen_switch_effect_frames;
extern S32 g_gui_screen_switch_effect_current_frame_index;
extern S32 g_gui_screen_switch_effect_frame_duration;
extern gui_rect g_gui_screen_switch_effect_world_view_rect;

extern S32 g_gui_screen_switch_effect_object_num;
extern gui_screen_switch_effect_object_struct g_gui_screen_switch_effect_object[];

extern gui_screen_switch_effect_finish_callback_funcptr_type g_gui_screen_switch_effect_finish_callback;

extern MMI_BOOL g_gui_screen_switch_effect_enable_early_key_break;
extern MMI_BOOL gui_screen_switch_effect_is_key_pressed(void);

static gui_effect_projective_transform_subsample_mode_enum g_gui_effect_projective_transform_subsample_mode;
static gui_effect_affine_transform_subsample_mode_enum g_gui_effect_affine_transform_subsample_mode;

extern gui_effect_memory_manager_struct g_gui_screen_switch_effect_tmp_mem;
extern void *gui_effect_mem_manager_mem_alloc(gui_effect_memory_manager_struct *mem_manager, S32 size);
extern void gui_effect_mem_manager_free_all(gui_effect_memory_manager_struct *mem_manager);

// extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

/* SSE world structure */
extern gui_screen_switch_effect_world_struct g_gui_sse_world;

/*****************************************************************************
 * FUNCTION
 *  GUI_EFFECT_TRANSFORM_MUL
 * DESCRIPTION
 *  result = a * b
 * PARAMETERS
 *  a       [IN]    a
 *  b       [IN]    b
 * RETURNS
 *  a * b
 *****************************************************************************/
#ifdef __MTK_TARGET__

static S32 GUI_EFFECT_TRANSFORM_MUL(S32 a, S32 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lo, hi, result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lo = GUI_EFFECT_TRANSFORM_ROUNDING_VALUE;    
    hi = 0;

    __asm
    {
        SMLAL   lo, hi, a, b        
        MOV     lo, lo, LSR GUI_EFFECT_TRANSFORM_PRECISION_BITS
        ORR     result, lo, hi, LSL (32 - GUI_EFFECT_TRANSFORM_PRECISION_BITS)
    }

    return result;
}


#else /* __MTK_TARGET__ */

static S32 GUI_EFFECT_TRANSFORM_MUL(S32 a, S32 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ((kal_int64)a * (kal_int64)b  + GUI_EFFECT_TRANSFORM_ROUNDING_VALUE) >> GUI_EFFECT_TRANSFORM_PRECISION_BITS;    

    return (S32)result;
}


#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  GUI_EFFECT_TRANSFORM_AB_PLUS_CD
 * DESCRIPTION
 *  result = a * b + c * d
 * PARAMETERS
 *  a       [IN]    a
 *  b       [IN]    b
 *  c       [IN]    c
 *  d       [IN]    d
 * RETURNS
 *  a * b + c * d
 *****************************************************************************/
#ifdef __MTK_TARGET__

static S32 GUI_EFFECT_TRANSFORM_AB_PLUS_CD(S32 a, S32 b, S32 c, S32 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     lo, hi, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lo = GUI_EFFECT_TRANSFORM_ROUNDING_VALUE;    
    hi = 0;
    
    __asm
    {     
        SMLAL   lo, hi, a, b
        SMLAL   lo, hi, c, d        
        MOV     lo, lo, LSR GUI_EFFECT_TRANSFORM_PRECISION_BITS
        ORR     result, lo, hi, LSL (32 - GUI_EFFECT_TRANSFORM_PRECISION_BITS)
    }

    return result;
}


#else /* __MTK_TARGET__ */

static S32 GUI_EFFECT_TRANSFORM_AB_PLUS_CD(S32 a, S32 b, S32 c, S32 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ((kal_int64)a * (kal_int64)b + (kal_int64)c * (kal_int64)d + GUI_EFFECT_TRANSFORM_ROUNDING_VALUE) >> GUI_EFFECT_TRANSFORM_PRECISION_BITS;

    return (S32)result;
}


#endif /* __MTK_TARGET__ */


/*
 *  AFFINE TRANSFORM
 */

/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_get_inverse_matrix
 * DESCRIPTION
 *  Gets the inverse affine transform matrix. matrix = inv(matrix).
 * PARAMETERS
 *  matrix       [IN/OUT]   affine transform matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_get_inverse_matrix(gui_effect_affine_transform_matrix_struct *matrix) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    S32     m0, m1, m2, m3, m4, m5;
    S32     det, inv_det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *  m0 m1 0
     *  m2 m3 0
     *  m4 m5 1
     */    
    m0 = m[0];
    m1 = m[1];
    m2 = m[2];
    m3 = m[3];
    m4 = m[4];
    m5 = m[5];

    det = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m0, m3, -m1, m2);

    /* prevent divided by zero */
    // TODO: should assert
    if (det == 0)
    {
        det = 1;
    }
           
    inv_det = ((kal_int64)1 << (GUI_EFFECT_TRANSFORM_PRECISION_BITS * 2)) / det;

    m[0] = GUI_EFFECT_TRANSFORM_MUL(inv_det, m3);
    m[1] = -GUI_EFFECT_TRANSFORM_MUL(inv_det, m1);
    m[2] = -GUI_EFFECT_TRANSFORM_MUL(inv_det, m2);
    m[3] = GUI_EFFECT_TRANSFORM_MUL(inv_det, m0);
    m[4] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m2, m5, -m3, m4));
    m[5] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m1, m4, -m0, m5));
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_multiply_matrix
 * DESCRIPTION
 *  Multiplies two affine transform matrices. matrix_a = matrix_a * matrix_b.
 * PARAMETERS
 *  matrix_a       [IN/OUT] multiplicand matrix 
 *  matrix_b       [IN]     multiplier matrix
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_multiply_matrix(gui_effect_affine_transform_matrix_struct *matrix_a, gui_effect_affine_transform_matrix_struct *matrix_b) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix_a->m;
    S32     *a = matrix_b->m;
    S32     m0, m1, m2, m3, m4, m5, a0, a1, a2, a3, a4, a5;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    m0 = m[0];
    m1 = m[1];
    m2 = m[2];
    m3 = m[3];
    a0 = a[0];
    a1 = a[1];
    a2 = a[2];
    a3 = a[3];      
    
    m[0] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m0, a0, m1, a2);
    m[1] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m0, a1, m1, a3);
    m[2] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m2, a0, m3, a2);
    m[3] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m2, a1, m3, a3);

    m4 = m[4];
    m5 = m[5];
    a4 = a[4];
    a5 = a[5];
    
    m[4] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m4, a0, m5, a2) + a4;
    m[5] = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(m4, a1, m5, a3) + a5;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_apply_point
 * DESCRIPTION
 *  Applies the affine transform to a point.
 * PARAMETERS
 *  matrix      [IN]        affine transform matrix
 *  point       [IN/OUT]    point
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_apply_point(gui_effect_affine_transform_matrix_struct *matrix, gui_effect_point_struct *point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     px, py;
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    px = point->x;
    py = point->y;

    /* 1-bit for rounding */
    px <<= 1;
    py <<= 1;

    point->x = (GUI_EFFECT_TRANSFORM_AB_PLUS_CD(px, m[0], py, m[2]) + (m[4] >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - 1)) + 1) >> 1;
    point->y = (GUI_EFFECT_TRANSFORM_AB_PLUS_CD(px, m[1], py, m[3]) + (m[5] >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - 1)) + 1) >> 1;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_make_rotate_matrix
 * DESCRIPTION
 *  Makes an affine transform rotation matrix.
 * PARAMETERS
 *  matrix       [OUT]  affine transform matrix
 *  degree       [IN]   degrees in integer
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_make_rotate_matrix(gui_effect_affine_transform_matrix_struct *matrix, S32 degree)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     cosine, sine;
    float   rad;
    float   c, s;
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: do not use C math library cos() and sin()
    rad = (float)degree * (GUI_EFFECT_PI / 180.0);    
    c = cos(rad);
    s = sin(rad);

    cosine = GUI_EFFECT_TRANSFORM_FP(c);
    sine = GUI_EFFECT_TRANSFORM_FP(s);    

    m[0] = cosine;
    m[1] = -sine;
    m[2] = sine;
    m[3] = cosine;
    m[4] = 0;
    m[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_make_translate_matrix
 * DESCRIPTION
 *  Makes an affine transform translation matrix.
 * PARAMETERS
 *  matrix         [OUT]    affine transform matrix
 *  offset_x       [IN]     offset x
 *  offset_y       [IN]     offset y
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_make_translate_matrix(gui_effect_affine_transform_matrix_struct *matrix, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m[0] = GUI_EFFECT_TRANSFORM_FP(1);
    m[1] = 0;
    m[2] = 0;
    m[3] = GUI_EFFECT_TRANSFORM_FP(1);
    m[4] = offset_x << GUI_EFFECT_TRANSFORM_PRECISION_BITS;
    m[5] = offset_y << GUI_EFFECT_TRANSFORM_PRECISION_BITS;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_make_identity_matrix
 * DESCRIPTION
 *  Makes an affine transform identity matrix.
 * PARAMETERS
 *  matrix       [OUT]  affine transform identity matrix
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_make_identity_matrix(gui_effect_affine_transform_matrix_struct *matrix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m[0] = GUI_EFFECT_TRANSFORM_FP(1);
    m[1] = 0;
    m[2] = 0;
    m[3] = GUI_EFFECT_TRANSFORM_FP(1);
    m[4] = 0;
    m[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_make_shear_matrix
 * DESCRIPTION
 *  Makes an affine transform shear matrix.
 * PARAMETERS
 *  matrix        [OUT] affine transform matrix
 *  shear_x       [IN]  x shear ratio
 *  shear_y       [IN]  y shear ratio
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_make_shear_matrix(gui_effect_affine_transform_matrix_struct *matrix, S32 shear_x, S32 shear_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m[0] = GUI_EFFECT_TRANSFORM_FP(1);
    m[1] = shear_y;
    m[2] = shear_x;
    m[3] = GUI_EFFECT_TRANSFORM_FP(1);
    m[4] = 0;
    m[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_make_scale_matrix
 * DESCRIPTION
 *  Makes an affine transform scale matrix.
 * PARAMETERS
 *  matrix        [OUT] affine transform matrix
 *  scale_x       [IN]  x scale ratio
 *  scale_y       [IN]  y scale ratio
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_make_scale_matrix(gui_effect_affine_transform_matrix_struct *matrix, S32 scale_x, S32 scale_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m[0] = scale_x;
    m[1] = 0;
    m[2] = 0;
    m[3] = scale_y;
    m[4] = 0;
    m[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_translate
 * DESCRIPTION
 *  Translates an affine transform matrix.
 * PARAMETERS
 *  ctm             [IN/OUT]    affine transform matrix
 *  offset_x        [IN]        offset x
 *  offset_y        [IN]        offset y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_translate(gui_effect_affine_transform_matrix_struct *ctm, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_matrix_struct   m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_make_translate_matrix(&m, offset_x, offset_y);
    gui_effect_affine_transform_multiply_matrix(ctm, &m);      
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_rotate
 * DESCRIPTION
 *  Rotates an affine transform matrix.
 * PARAMETERS
 *  ctm             [IN/OUT]    affine transform matrix
 *  degree          [IN]        degree in integer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_rotate(gui_effect_affine_transform_matrix_struct *ctm, S32 degree)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_matrix_struct   m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_make_rotate_matrix(&m, degree);
    gui_effect_affine_transform_multiply_matrix(ctm, &m);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_scale
 * DESCRIPTION
 *  Scales an affine transform matrix.
 * PARAMETERS
 *  ctm             [IN/OUT]    affine transform matrix
 *  scale_x         [IN]        x scale ratio
 *  scale_y         [IN]        y scale ratio
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_scale(gui_effect_affine_transform_matrix_struct *ctm, S32 scale_x, S32 scale_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_matrix_struct   m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_make_scale_matrix(&m, scale_x, scale_y);
    gui_effect_affine_transform_multiply_matrix(ctm, &m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_shear
 * DESCRIPTION
 *  Shears an affine transform matrix.
 * PARAMETERS
 *  ctm             [IN/OUT]    affine transform matrix
 *  shear_x         [IN]        x shear ratio
 *  shear_y         [IN]        y shear ratio
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_shear(gui_effect_affine_transform_matrix_struct *ctm, S32 shear_x, S32 shear_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_matrix_struct   m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_affine_transform_make_shear_matrix(&m, shear_x, shear_y);
    gui_effect_affine_transform_multiply_matrix(ctm, &m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_set_subsample_mode
 * DESCRIPTION
 *  Sets the affine transform pixel subsample mode.
 * PARAMETERS
 *  mode       [IN] subsample mode
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_set_subsample_mode(gui_effect_affine_transform_subsample_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_effect_affine_transform_subsample_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_get_subsample_mode
 * DESCRIPTION
 *  Gets the affine transform pixel subsample mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  pixel subsample mode
 *****************************************************************************/
gui_effect_affine_transform_subsample_mode_enum gui_effect_affine_transform_get_subsample_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gui_effect_affine_transform_subsample_mode;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_apply_image_by_nearest
 * DESCRIPTION
 *  Applies the affine transform to an image by nearest subsampling.
 * PARAMETERS
 *  matrix              [IN]    affine transform matrix
 *  src_buf_p           [IN]    source buffer pointer
 *  src_width           [IN]    source width
 *  src_height          [IN]    source height
 *  out_buf_p           [IN]    output buffer pointer
 *  out_width           [IN]    output width
 *  out_height          [IN]    output height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_apply_image_by_nearest(S32 *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, U16 *out_buf_p, S32 out_width, S32 out_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x;
    S32     y;
    S32     src_x, src_y;
    S32     x_pre, y_pre;
    S32     l_x_pre, l_y_pre;
    S32     m0, m1, m2, m3;
    U16     *src_buf_16_p = (U16*)src_buf_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m0 = matrix[0];
    m1 = matrix[1];
    m2 = matrix[2];
    m3 = matrix[3];    

    /* pre-add .5 rounding */
    l_x_pre = matrix[4] + GUI_EFFECT_TRANSFORM_ROUNDING_VALUE;
    l_y_pre = matrix[5] + GUI_EFFECT_TRANSFORM_ROUNDING_VALUE;
   
    for (y = out_height - 1; y >= 0; y--)
    {
        x_pre = l_x_pre;
        y_pre = l_y_pre;

        l_x_pre += m2;
        l_y_pre += m3;
        
        for (x = out_width - 1; x >= 0; x--)
        {
            src_x = x_pre >> GUI_EFFECT_TRANSFORM_PRECISION_BITS;
            src_y = y_pre >> GUI_EFFECT_TRANSFORM_PRECISION_BITS;

            /* valid source image rect check */
            if (GUI_SSE_IS_POINT_IN_RECT(src_x, src_y, 0, 0, src_width, src_height))
            {
                *out_buf_p = src_buf_16_p[src_x + src_y * src_width];
            }

            out_buf_p++;

            x_pre += m0;
            y_pre += m1;            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_apply_image_by_bilinear
 * DESCRIPTION
 *  Applies the affine transform to an image by bilinear subsampling.
 * PARAMETERS
 *  matrix              [IN]    affine transform matrix
 *  src_buf_p           [IN]    source buffer pointer
 *  src_width           [IN]    source width
 *  src_height          [IN]    source height
 *  out_buf_p           [IN]    output buffer pointer
 *  out_width           [IN]    output width
 *  out_height          [IN]    output height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_affine_transform_apply_image_by_bilinear(S32 *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, U16 *out_buf_p, S32 out_width, S32 out_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x;
    S32     y;
    S32     src_x, src_y;
    S32     x_pre, y_pre;
    S32     l_x_pre, l_y_pre;
    S32     m0, m1, m2, m3;    
    U16     *src_buf_16_p = (U16*)src_buf_p;

    U32     p00, p10, p01, p11;
    U32     u, v, uv;
    U16     *src_pixel_p;            
    U32     pixel_bi;                
    S32     b0, b1, b2, b3;
    
    /* blue source key */
    // TODO: variable source key color is necessary?
    const U32   source_key_color = 0x1F;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m0 = matrix[0];
    m1 = matrix[1];
    m2 = matrix[2];
    m3 = matrix[3];    

    l_x_pre = matrix[4];
    l_y_pre = matrix[5];
   
    for (y = out_height - 1; y >= 0; y--)
    {    
        x_pre = l_x_pre;
        y_pre = l_y_pre;

        l_x_pre += m2;
        l_y_pre += m3;        
                 
        for (x = out_width - 1; x >= 0; x--)
        {                                   
            src_x = x_pre >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS);
            src_y = y_pre >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS);

            /* get bilinear interpolation fraction bits */                         
            u = src_x & ((1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - 1);
            v = src_y & ((1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - 1);
            uv = (u << 16) | v;

            /* integer part */
            src_x >>= GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS;
            src_y >>= GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS;

            if ((src_x >= -1) && (src_y >= -1) && (src_x < src_width) && (src_y < src_height))
            {                 
                src_pixel_p = src_buf_16_p + src_x + src_y * src_width;

                p00 = src_pixel_p[0];
                
                if (src_x + 1 == src_width)
                {
                    p10 = 0;
                }
                else
                {
                    p10 = src_pixel_p[1];
                }

                if (src_y + 1 == src_height)
                {
                    p01 = 0;
                }
                else
                {
                    p01 = src_pixel_p[src_width];
                }

                if ((src_x + 1 == src_width) || (src_y + 1 == src_height))
                {
                    p11 = 0;
                }
                else
                {
                    p11 = src_pixel_p[src_width + 1];
                }       
                         
                /* 
                 * treat pixels out of the source image rect as black 
                 */
                // TODO: This is not a perfect solution. 
                /* out of left */
                if (src_x < 0)
                {   
                    p00 = p01 = 0;
                }

                /* out of top */
                if (src_y < 0)
                {
                    p00 = p10 = 0;
                }

                /* replace neighbor transparent pixels with black if the output pixel is a pure trasparent pixel */
                // TODO: This is not a perfect solution.                
                if (!((p00 == source_key_color) && (p10 == source_key_color) && (p01 == source_key_color) && (p11 == source_key_color)))
                {
                    if (p00 == source_key_color)
                    {
                        p00 = 0;
                    }

                    if (p10 == source_key_color)
                    {
                        p10 = 0;
                    }

                    if (p01 == source_key_color)
                    {
                        p01 = 0;
                    }

                    if (p11 == source_key_color)
                    {
                        p11 = 0;
                    }
                }


            #ifdef __TARGET_FEATURE_DSPMUL 

                /* 
                 * optimized by DSP extension and fewer stack variables
                 */
                {
                    U32     l0, l1;
                    S32     line0, line1, mask;
                    S32     b0_b1, b2_b3;     
                    U32     red, green, blue;          
                    U32     opp_uv;
                    
                    /* put 4 16-bit neighbor pixels into 2 32-bit registers */
                    l0 = (p00 << 16) | p10;
                    l1 = (p01 << 16) | p11;

                    /* 
                     * put 4 coefficients into 2 32-bit registers:
                     *
                     * b0 = opp_u * opp_v;
                     * b1 = u * opp_v;
                     * b2 = opp_u * v;
                     * b3 = u * v;
                     */
                    opp_uv = 0x00800080 - uv;
                    __asm
                    {
                        SMULTB b0, opp_uv, opp_uv
                        SMULTB b1, uv, opp_uv
                        SMULTB b2, opp_uv, uv
                        SMULTB b3, uv, uv
                    }                
                    b0_b1 = (b0 << 16) | b1;
                    b2_b3 = (b2 << 16) | b3;
                    
                    __asm
                    {
                        /* 5-bit blue and red mask 0x001F001F */
                        MOV     mask, 0x1F
                        ORR     mask, mask, mask, LSL 16

                        /* calculate B */
                        AND     line0, l0, mask
                        AND     line1, l1, mask
                        SMULTT  blue, b0_b1, line0
                        SMLABB  blue, b0_b1, line0, blue
                        SMLATT  blue, b2_b3, line1, blue
                        SMLABB  blue, b2_b3, line1, blue                                        
                        MOV     pixel_bi, blue, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)

                        /* calculate R */
                        AND     line0, l0, mask, LSL 11
                        AND     line1, l1, mask, LSL 11
                        MOV     line0, line0, LSR 11
                        MOV     line1, line1, LSR 11
                        SMULTT  red, b0_b1, line0
                        SMLABB  red, b0_b1, line0, red
                        SMLATT  red, b2_b3, line1, red
                        SMLABB  red, b2_b3, line1, red
                        MOV     red, red, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)
                        ORR     pixel_bi, pixel_bi, red, LSL 11

                        /* 6-bit green mask 0x003F003F */
                        MOV     mask, 0x3F
                        ORR     mask, mask, mask, LSL 16

                        /* calculate G */
                        AND     line0, l0, mask, LSL 5
                        AND     line1, l1, mask, LSL 5
                        SMULTT  green, b0_b1, line0
                        SMLABB  green, b0_b1, line0, green
                        SMLATT  green, b2_b3, line1, green
                        SMLABB  green, b2_b3, line1, green
                        MOV     green, green, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2 + 5)
                        ORR     pixel_bi, pixel_bi, green, LSL 5
                    }   
                }
                
            #else /* __TARGET_FEATURE_DSPMUL */
                
                /* 
                 * the straight-forward method
                 */
                {
                    U32     opp_u, opp_v;
                    
                    u = uv >> 16;
                    v = uv & 0xFFFF;
                        
                    opp_u = (1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - u;
                    opp_v = (1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - v;
                        
                    b0 = opp_u * opp_v;
                    b1 = u * opp_v;
                    b2 = opp_u * v;
                    b3 = u * v;

                    pixel_bi = (b0 * B_OF_RGB565(p00) + b1 * B_OF_RGB565(p10) + b2 * B_OF_RGB565(p01) + b3 * B_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);
                    pixel_bi |= ((b0 * G_OF_RGB565(p00) + b1 * G_OF_RGB565(p10) + b2 * G_OF_RGB565(p01) + b3 * G_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 5;
                    pixel_bi |= ((b0 * R_OF_RGB565(p00) + b1 * R_OF_RGB565(p10) + b2 * R_OF_RGB565(p01) + b3 * R_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 11;               
                }
                
            #endif /* __TARGET_FEATURE_DSPMUL */
            
                *out_buf_p = pixel_bi;
            }

            out_buf_p++;

            x_pre += m0;
            y_pre += m1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_get_output_rect
 * DESCRIPTION
 *  Gets the output rectangle for an input image rect which begins with (0, 0).
 * PARAMETERS
 *  matrix          [IN]    affine transform matrix
 *  in_width        [IN]    input image width
 *  in_height       [IN]    input image height
 *  out_rect        [OUT]   output rect
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_get_output_rect(gui_effect_affine_transform_matrix_struct *matrix, S32 in_width, S32 in_height, gui_rect *out_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     x1, y1, x2, y2;
    S32     x, y;
    
    gui_effect_point_struct vertex[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* top-left point */
    GUI_EFFECT_SET_POINT(vertex[0], 0, 0);
    /* top-right point */
    GUI_EFFECT_SET_POINT(vertex[1], in_width - 1, 0);
    /* bottom-left point */
    GUI_EFFECT_SET_POINT(vertex[2], 0, in_height - 1);
    /* bottom-right point */
    GUI_EFFECT_SET_POINT(vertex[3], in_width - 1, in_height - 1);

    x1 = GUI_EFFECT_INT_VALUE_MAX;
    y1 = GUI_EFFECT_INT_VALUE_MAX;
    x2 = GUI_EFFECT_INT_VALUE_MIN;
    y2 = GUI_EFFECT_INT_VALUE_MIN;

    /* get the output rect */
    for (i = 0; i < 4; i++)
    {        
        gui_effect_affine_transform_apply_point(matrix, &vertex[i]);
        
        x = vertex[i].x;
        y = vertex[i].y;

        if (x < x1)
        {
            x1 = x;
        }

        if (x > x2)
        {
            x2 = x;
        }
        
        if (y < y1)
        {
            y1 = y;
        }

        if (y > y2)
        {
            y2 = y;
        }        
    }

    /* enlarge the output rect a little to be safer from errors */
    // TODO: These are experiment values...
    x1 -= 1;
    y1 -= 1;    
    x2 += 1;    
    y2 += 1;

    GUI_RECT(*out_rect, x1, y1, x2 - x1 + 1, y2 - y1 + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_affine_transform_apply_image
 * DESCRIPTION
 *  Applies the affine transform to an image
 * PARAMETERS
 *  matrix           [IN]   affine transform matrix
 *  src_buf_p        [IN]   source buffer pointer
 *  src_width        [IN]   source width
 *  src_height       [IN]   source height
 *  out_buf_p        [IN]   output buffer pointer
 *  out_rect         [IN]   output rect
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_affine_transform_apply_image(gui_effect_affine_transform_matrix_struct *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, PU8 out_buf_p, gui_rect *out_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y;
    S32     out_w, out_h;
    S32     *m;
    gui_effect_affine_transform_matrix_struct inverse_matrix;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = out_rect->x;
    y = out_rect->y;
    out_w = out_rect->width;
    out_h = out_rect->height;    
 
    /* get the inverse matrix */
    inverse_matrix = *matrix;
    gui_effect_affine_transform_get_inverse_matrix(&inverse_matrix);
    m = inverse_matrix.m;

    /* offset output rect to the origin */
    m[4] += GUI_EFFECT_TRANSFORM_AB_PLUS_CD(GUI_EFFECT_TRANSFORM_INT(x), m[0], GUI_EFFECT_TRANSFORM_INT(y), m[2]);
    m[5] += GUI_EFFECT_TRANSFORM_AB_PLUS_CD(GUI_EFFECT_TRANSFORM_INT(x), m[1], GUI_EFFECT_TRANSFORM_INT(y), m[3]);

    if (gui_effect_affine_transform_get_subsample_mode() == GUI_EFFECT_AFFINE_TRANSFORM_SUBSAMPLE_MODE_NEAREST)
    {
        gui_effect_affine_transform_apply_image_by_nearest(m, src_buf_p, src_width, src_height, (U16*)out_buf_p, out_w, out_h);
    }
    else
    {
        gui_effect_affine_transform_apply_image_by_bilinear(m, src_buf_p, src_width, src_height, (U16*)out_buf_p, out_w, out_h);
    }    
}


/*
 *  PROJECTIVE TRANSFORM
 */

/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_set_subsample_mode
 * DESCRIPTION
 *  Sets the projective transform pixel subsample mode.
 * PARAMETERS
 *  mode       [IN] subsample mode
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_projective_transform_set_subsample_mode(gui_effect_projective_transform_subsample_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_effect_projective_transform_subsample_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_get_subsample_mode
 * DESCRIPTION
 *  Gets the projective transform pixel subsample mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  pixel subsample mode
 *****************************************************************************/
gui_effect_projective_transform_subsample_mode_enum gui_effect_projective_transform_get_subsample_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gui_effect_projective_transform_subsample_mode;
}



/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_get_inverse_matrix
 * DESCRIPTION
 *  Gets the inverse projective transform matrix. matrix = inv(matrix).
 * PARAMETERS
 *  matrix       [IN/OUT]   projective transform matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_projective_transform_get_inverse_matrix(gui_effect_projective_transform_matrix_struct *matrix) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     *m = matrix->m;
    S32     a, b, c, d, e, f, g, h, i;
    S32     det, inv_det;
    S32     m0, m3, m6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * a d g
     * b e h
     * c f i
     */
    a = m[0];
    b = m[3];
    c = m[6];
    d = m[1];
    e = m[4];
    f = m[7];
    g = m[2];
    h = m[5];
    i = m[8];

    m0 = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(e, i, -h, f);
    m3 = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(h, c, -b, i);
    m6 = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(b, f, -e, c);

    det = GUI_EFFECT_TRANSFORM_MUL(a, m0);
    det += GUI_EFFECT_TRANSFORM_MUL(d, m3);
    det += GUI_EFFECT_TRANSFORM_MUL(g, m6);

    /* prevent divided by zero */
    // TODO: should assert
    if (!det)
    {
        det = 1;        
    }

    inv_det = ((kal_int64)1 << (GUI_EFFECT_TRANSFORM_PRECISION_BITS * 2)) / det;

    m[0] = GUI_EFFECT_TRANSFORM_MUL(inv_det, m0);
    m[3] = GUI_EFFECT_TRANSFORM_MUL(inv_det, m3);
    m[6] = GUI_EFFECT_TRANSFORM_MUL(inv_det, m6);
    
    m[1] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(g, f, -d, i));
    m[2] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(d, h, -g, e));

    m[4] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(a, i, -c, g));
    m[5] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(g, b, -a, h));

    m[7] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(d, c, -a, f));
    m[8] = GUI_EFFECT_TRANSFORM_MUL(inv_det, GUI_EFFECT_TRANSFORM_AB_PLUS_CD(a, e, -b, d));
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_apply_point
 * DESCRIPTION
 *  Applies the projective transform to a point.
 * PARAMETERS
 *  matrix      [IN]        affine transform matrix
 *  point       [IN/OUT]    point
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_projective_transform_apply_point(gui_effect_projective_transform_matrix_struct *matrix, gui_effect_point_struct *point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     px, py, u, v, w;
    S32     *m = matrix->m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    px = point->x;
    py = point->y;

    /* increase the precision temporarily to be more precise */
    // TODO: may overflow
    px <<= 6;
    py <<= 6;

    u = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(px, m[0], py, m[3]) + (m[6] >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - 6));
    v = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(px, m[1], py, m[4]) + (m[7] >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - 6));
    w = GUI_EFFECT_TRANSFORM_AB_PLUS_CD(px, m[2], py, m[5]) + (m[8] >> (GUI_EFFECT_TRANSFORM_PRECISION_BITS - 6));

    /* get rid of divided by zero */
    // TODO: maybe assert...
    if (w == 0)
    {
        w = 1;
    }

    GUI_EFFECT_SET_POINT(*point, u / w, v / w);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_get_output_rect
 * DESCRIPTION
 *  Gets the output rectangle for an input image rect which begins with (0, 0).
 * PARAMETERS
 *  matrix          [IN]    projective transform matrix
 *  in_width        [IN]    input image width
 *  in_height       [IN]    input image height
 *  out_rect        [IN]    output rect
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_projective_transform_get_output_rect(gui_effect_projective_transform_matrix_struct *matrix, S32 in_width, S32 in_height, gui_rect *out_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     x1, y1, x2, y2;
    S32     x, y;
    
    gui_effect_point_struct vertex[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* top-left point */
    GUI_EFFECT_SET_POINT(vertex[0], 0, 0);
    /* top-right point */
    GUI_EFFECT_SET_POINT(vertex[1], in_width - 1, 0);
    /* bottom-left point */
    GUI_EFFECT_SET_POINT(vertex[2], 0, in_height - 1);
    /* bottom-right point */
    GUI_EFFECT_SET_POINT(vertex[3], in_width - 1, in_height - 1);

    x1 = GUI_EFFECT_INT_VALUE_MAX;
    y1 = GUI_EFFECT_INT_VALUE_MAX;
    x2 = GUI_EFFECT_INT_VALUE_MIN;
    y2 = GUI_EFFECT_INT_VALUE_MIN;

    /* get the output rect */
    for (i = 0; i < 4; i++)
    {        
        gui_effect_projective_transform_apply_point(matrix, &vertex[i]);
        
        x = vertex[i].x;
        y = vertex[i].y;

        if (x < x1)
        {
            x1 = x;
        }

        if (x > x2)
        {
            x2 = x;
        }
        
        if (y < y1)
        {
            y1 = y;
        }

        if (y > y2)
        {
            y2 = y;
        }        
    }

    /* enlarge the output rect a little to be safer from errors */
    // TODO: These are experiment values...
    x1 -= 4;
    y1 -= 4;    
    x2 += 4;    
    y2 += 4;

    GUI_RECT(*out_rect, x1, y1, x2 - x1 + 1, y2 - y1 + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_apply_image_by_nearest
 * DESCRIPTION
 *  Applies the projective transform to an image by nearest subsampling.
 * PARAMETERS
 *  matrix              [IN]    projective transform matrix
 *  src_buf_p           [IN]    source buffer pointer
 *  src_width           [IN]    source width
 *  src_height          [IN]    source height
 *  out_buf_p           [IN]    output buffer pointer
 *  out_width           [IN]    output width
 *  out_height          [IN]    output height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_projective_transform_apply_image_by_nearest(S32 *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, U16 *out_buf_p, S32 out_width, S32 out_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x;
    S32     y;
    S32     src_x, src_y;
    S32     x_pre, y_pre, w_pre;
    S32     l_x_pre, l_y_pre, l_w_pre;
    S32     a, b, c, d, e, f, g, h, i;
    U16     *src_buf_16_p = (U16*)src_buf_p;
    S32     inv, inv_next;
    S32     inv_step;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    a = matrix[0];
    b = matrix[3];
    c = matrix[6];
    d = matrix[1];
    e = matrix[4];
    f = matrix[7];
    g = matrix[2];
    h = matrix[5];
    i = matrix[8];

    l_x_pre = c;
    l_y_pre = f;
    l_w_pre = i;

    for (y = out_height - 1; y >= 0; y--)
    {
        x_pre = l_x_pre;
        y_pre = l_y_pre;
        w_pre = l_w_pre;

        l_x_pre += b;
        l_y_pre += e;
        l_w_pre += h;

        inv = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;
        w_pre += g * 4;
        inv_next = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;        
        inv_step = (inv_next - inv) / 4;

        inv -= inv_step;

        for (x = out_width - 1; x >= 0; x--)
        {
            /*     
             *  reduce divisions to 1/4 by interpolate 1/w
             */        
            if (x & 3)
            {
                inv += inv_step;
            }
            else
            {
                w_pre += g * 4;
                inv_next = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;
                inv_step = (inv_next - inv) / 4;
            }

            src_x = GUI_EFFECT_TRANSFORM_MUL(x_pre, inv) >> (GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS - GUI_EFFECT_TRANSFORM_PRECISION_BITS);
            x_pre += a;            
            src_y = GUI_EFFECT_TRANSFORM_MUL(y_pre, inv) >> (GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS - GUI_EFFECT_TRANSFORM_PRECISION_BITS);
            y_pre += d; 

            /* valid source image rect check */
            if (GUI_SSE_IS_POINT_IN_RECT(src_x, src_y, 0, 0, src_width, src_height))
            {
                *out_buf_p = src_buf_16_p[src_x + src_y * src_width];         
            }

            out_buf_p++;         
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_apply_image_by_bilinear
 * DESCRIPTION
 *  Applies the projective transform to an image by bilinear subsampling.
 * PARAMETERS
 *  matrix              [IN]    projective transform matrix
 *  src_buf_p           [IN]    source buffer pointer
 *  src_width           [IN]    source width
 *  src_height          [IN]    source height
 *  out_buf_p           [IN]    output buffer pointer
 *  out_width           [IN]    output width
 *  out_height          [IN]    output height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_projective_transform_apply_image_by_bilinear(S32 *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, U16 *out_buf_p, S32 out_width, S32 out_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x;
    S32     y;
    S32     src_x, src_y;
    S32     x_pre, y_pre, w_pre;
    S32     l_x_pre, l_y_pre, l_w_pre;
    S32     a, b, c, d, e, f, g, h, i;
    U16     *src_buf_16_p = (U16*)src_buf_p;
    S32     inv, inv_next;
    S32     inv_step;

    U32     p00, p10, p01, p11;
    U32     u, v, uv;
    U16     *src_pixel_p;            
    U32     pixel_bi;                
    S32     b0, b1, b2, b3;        

    /* blue source key */
    // TODO: variable source key color is necessary?
    const U32   source_key_color = 0x1F;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    a = matrix[0];
    b = matrix[3];
    c = matrix[6];
    d = matrix[1];
    e = matrix[4];
    f = matrix[7];
    g = matrix[2];
    h = matrix[5];
    i = matrix[8];

    l_x_pre = c;
    l_y_pre = f;
    l_w_pre = i;

    for (y = out_height - 1; y >= 0; y--)
    {
        x_pre = l_x_pre;
        y_pre = l_y_pre;
        w_pre = l_w_pre;

        l_x_pre += b;
        l_y_pre += e;
        l_w_pre += h;

        inv = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;
        w_pre += g * 4;
        inv_next = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;        
        inv_step = (inv_next - inv) / 4;

        inv -= inv_step;

        for (x = out_width - 1; x >= 0; x--)
        {
            /*     
             *  reduce divisions to 1/4 by interpolation
             */        
            if (x & 3)
            {
                inv += inv_step;
            }
            else
            {
                w_pre += g * 4;
                inv_next = (1 << GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS) / w_pre;
                inv_step = (inv_next - inv) / 4;
            }

            src_x = GUI_EFFECT_TRANSFORM_MUL(x_pre, inv) >> (GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS - GUI_EFFECT_TRANSFORM_PRECISION_BITS - GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS);
            x_pre += a;            
            src_y = GUI_EFFECT_TRANSFORM_MUL(y_pre, inv) >> (GUI_EFFECT_TRANSFORM_INV_DIV_PRECISION_BITS - GUI_EFFECT_TRANSFORM_PRECISION_BITS - GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS);
            y_pre += d; 

            u = src_x & ((1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - 1);
            v = src_y & ((1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - 1);
            uv = (u << 16) | v;

            src_x >>= GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS;
            src_y >>= GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS;

            /* valid source image rect check */
            if (GUI_SSE_IS_POINT_IN_RECT(src_x, src_y, 0, 0, src_width, src_height))
            {            
                src_pixel_p = src_buf_16_p + src_x + src_y * src_width;
                
                p00 = src_pixel_p[0];

                if (src_x + 1 == src_width)
                {
                    p10 = 0;
                }
                else
                {
                    p10 = src_pixel_p[1];
                }

                if (src_y + 1 == src_height)
                {
                    p01 = 0;
                }
                else
                {
                    p01 = src_pixel_p[src_width];
                }

                if ((src_x + 1 == src_width) || (src_y + 1 == src_height))
                {
                    p11 = 0;
                }
                else
                {
                    p11 = src_pixel_p[src_width + 1];
                }                    

                /* 
                 * treat pixels out of the source image rect as black 
                 */
                // TODO: This is not a perfect solution. 

                /* out of left */
                if (src_x < 0)
                {   
                    p00 = p01 = 0;
                }

                /* out of top */
                if (src_y < 0)
                {
                    p00 = p10 = 0;
                }

                /* replace neighbor transparent pixels with black if the output pixel is a pure trasparent pixel */
                // TODO: This is not a perfect solution.                
                if (!((p00 == source_key_color) && (p10 == source_key_color) && (p01 == source_key_color) && (p11 == source_key_color)))
                {
                    if (p00 == source_key_color)
                    {
                        p00 = 0;
                    }

                    if (p10 == source_key_color)
                    {
                        p10 = 0;
                    }

                    if (p01 == source_key_color)
                    {
                        p01 = 0;
                    }

                    if (p11 == source_key_color)
                    {
                        p11 = 0;
                    }
                }


            #ifdef __TARGET_FEATURE_DSPMUL 

                /* 
                 * optimized by DSP extension and fewer stack variables
                 */
                {
                    U32     l0, l1;
                    S32     line0, line1, mask;
                    S32     b0_b1, b2_b3;     
                    U32     red, green, blue;          
                    U32     opp_uv;
                    
                    /* put 4 16-bit neighbor pixels into 2 32-bit registers */
                    l0 = (p00 << 16) | p10;
                    l1 = (p01 << 16) | p11;

                    /* 
                     * put 4 coefficients into 2 32-bit registers:
                     *
                     * b0 = opp_u * opp_v;
                     * b1 = u * opp_v;
                     * b2 = opp_u * v;
                     * b3 = u * v;
                     */
                    opp_uv = 0x00800080 - uv;
                    __asm
                    {
                        SMULTB b0, opp_uv, opp_uv
                        SMULTB b1, uv, opp_uv
                        SMULTB b2, opp_uv, uv
                        SMULTB b3, uv, uv
                    }                
                    b0_b1 = (b0 << 16) | b1;
                    b2_b3 = (b2 << 16) | b3;
                    
                    __asm
                    {
                        /* 5-bit blue and red mask 0x001F001F */
                        MOV     mask, 0x1F
                        ORR     mask, mask, mask, LSL 16

                        /* calculate B */
                        AND     line0, l0, mask
                        AND     line1, l1, mask
                        SMULTT  blue, b0_b1, line0
                        SMLABB  blue, b0_b1, line0, blue
                        SMLATT  blue, b2_b3, line1, blue
                        SMLABB  blue, b2_b3, line1, blue                                        
                        MOV     pixel_bi, blue, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)

                        /* calculate R */
                        AND     line0, l0, mask, LSL 11
                        AND     line1, l1, mask, LSL 11
                        MOV     line0, line0, LSR 11
                        MOV     line1, line1, LSR 11
                        SMULTT  red, b0_b1, line0
                        SMLABB  red, b0_b1, line0, red
                        SMLATT  red, b2_b3, line1, red
                        SMLABB  red, b2_b3, line1, red
                        MOV     red, red, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)
                        ORR     pixel_bi, pixel_bi, red, LSL 11

                        /* 6-bit green mask 0x003F003F */
                        MOV     mask, 0x3F
                        ORR     mask, mask, mask, LSL 16

                        /* calculate G */
                        AND     line0, l0, mask, LSL 5
                        AND     line1, l1, mask, LSL 5
                        SMULTT  green, b0_b1, line0
                        SMLABB  green, b0_b1, line0, green
                        SMLATT  green, b2_b3, line1, green
                        SMLABB  green, b2_b3, line1, green
                        MOV     green, green, LSR (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2 + 5)
                        ORR     pixel_bi, pixel_bi, green, LSL 5
                    }   
                }
                
            #else /* __TARGET_FEATURE_DSPMUL */
                
                /* 
                 * the straight-forward method
                 */
                {
                    U32     opp_u, opp_v;
                    
                    u = uv >> 16;
                    v = uv & 0xFFFF;
                        
                    opp_u = (1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - u;
                    opp_v = (1 << GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - v;
                        
                    b0 = opp_u * opp_v;
                    b1 = u * opp_v;
                    b2 = opp_u * v;
                    b3 = u * v;

                    pixel_bi = (b0 * B_OF_RGB565(p00) + b1 * B_OF_RGB565(p10) + b2 * B_OF_RGB565(p01) + b3 * B_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);
                    pixel_bi |= ((b0 * G_OF_RGB565(p00) + b1 * G_OF_RGB565(p10) + b2 * G_OF_RGB565(p01) + b3 * G_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 5;
                    pixel_bi |= ((b0 * R_OF_RGB565(p00) + b1 * R_OF_RGB565(p10) + b2 * R_OF_RGB565(p01) + b3 * R_OF_RGB565(p11)) >> (GUI_EFFECT_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 11;               
                }
                
            #endif /* __TARGET_FEATURE_DSPMUL */
            
                *out_buf_p = pixel_bi;
            }

            out_buf_p++;         
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_projective_transform_apply_image
 * DESCRIPTION
 *  Applies the projective transform to an image
 * PARAMETERS
 *  matrix           [IN]   projective transform matrix
 *  src_buf_p        [IN]   source buffer pointer
 *  src_width        [IN]   source width
 *  src_height       [IN]   source height
 *  out_buf_p        [IN]   output buffer pointer
 *  out_rect         [IN]   output rect
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_projective_transform_apply_image(gui_effect_projective_transform_matrix_struct *matrix, PU8 src_buf_p, S32 src_width, S32 src_height, PU8 out_buf_p, gui_rect *out_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y;
    S32     out_w, out_h;
    S32     *m;
    gui_effect_projective_transform_matrix_struct inverse_matrix;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = out_rect->x;
    y = out_rect->y;
    out_w = out_rect->width;
    out_h = out_rect->height;    
 
    /* get the inverse matrix */
    inverse_matrix = *matrix;
    gui_effect_projective_transform_get_inverse_matrix(&inverse_matrix);
    m = inverse_matrix.m;

    /* offset output rect to the origin */
    m[6] += GUI_EFFECT_TRANSFORM_AB_PLUS_CD(GUI_EFFECT_TRANSFORM_INT(x), m[0], GUI_EFFECT_TRANSFORM_INT(y), m[3]);
    m[7] += GUI_EFFECT_TRANSFORM_AB_PLUS_CD(GUI_EFFECT_TRANSFORM_INT(x), m[1], GUI_EFFECT_TRANSFORM_INT(y), m[4]);
    m[8] += GUI_EFFECT_TRANSFORM_AB_PLUS_CD(GUI_EFFECT_TRANSFORM_INT(x), m[2], GUI_EFFECT_TRANSFORM_INT(y), m[5]);

    if (gui_effect_projective_transform_get_subsample_mode() == GUI_EFFECT_PROJECTIVE_TRANSFORM_SUBSAMPLE_MODE_NEAREST)
    {
        gui_effect_projective_transform_apply_image_by_nearest(m, src_buf_p, src_width, src_height, (U16*)out_buf_p, out_w, out_h);
    }
    else
    {
        gui_effect_projective_transform_apply_image_by_bilinear(m, src_buf_p, src_width, src_height, (U16*)out_buf_p, out_w, out_h);
    }    
}


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_resizer
 * DESCRIPTION
 *  Nearest neighborhood resizer. Same argument with gdi_resizer().
 *  NOTE: the dest. clip differs to gdi_resizer().
 * PARAMETERS
 *  src_buffer            [IN]      input source buffer
 *  src_x                 [IN]      source rect x
 *  src_y                 [IN]      source rect y
 *  src_w                 [IN]      source rect width
 *  src_h                 [IN]      source rect height
 *  src_layer_width       [IN]      source layer width
 *  dst_buffer            [OUT]     output dest. buffer
 *  dst_w                 [IN]      dest. rect width
 *  dst_h                 [IN]      dest. rect height
 *  dst_clip_x1           [IN]      dest. clip x1
 *  dst_clip_y1           [IN]      dest. clip y1
 *  dst_clip_x2           [IN]      dest. clip x2
 *  dst_clip_y2           [IN]      dest. clip y2
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_resizer(
                U8 *src_buffer, 
                S32 src_x,
                S32 src_y,
                S32 src_w,
                S32 src_h,
                S32 src_layer_width,
                U8 *dst_buffer, 
                S32 dst_w,
                S32 dst_h,
                S32 dst_clip_x1,
                S32 dst_clip_y1,
                S32 dst_clip_x2,
                S32 dst_clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 sy;
    S32 old_src_y;
    S32 dx, dy;
    U16 *dst_16_ptr, *src_16_ptr;
    S32 clip_w, clip_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing if the destination width or height is zero */
    if (!dst_w || !dst_h)
    {
        return;
    }

    dx = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(1.0) * src_w / dst_w;
    dy = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT(1.0) * src_h / dst_h;

    src_16_ptr = ((U16*)src_buffer) + src_y * src_layer_width + src_x;
    dst_16_ptr = (U16*)dst_buffer;

    clip_w = dst_clip_x2 - dst_clip_x1 + 1;
    clip_h = dst_clip_y2 - dst_clip_y1 + 1;

    src_y = dst_clip_y1 * dy;
    old_src_y = 0;

    dst_w = clip_w;
    dst_h = clip_h;

    for (y = dst_h - 1; y >= 0; y--)
    {
        sy = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_TO_ROUND_INT(src_y);
        src_y += dy;        
        if (old_src_y != sy)
        {
            src_16_ptr += (sy - old_src_y) * src_layer_width;            
            old_src_y = sy;
        }         

        src_x = dst_clip_x1 * dx;
   
        for (x = dst_w - 1; x >= 0; x--)
        {
            *dst_16_ptr++ = src_16_ptr[GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_TO_ROUND_INT(src_x)];
            
            src_x += dx;
        }               
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_frame_sort_z_order
 * DESCRIPTION
 *  Sort all object z in a frame.
 * PARAMETERS
 *  frame_index       [IN]      frame index
 *  z_order           [IN/OUT]  z array
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_frame_sort_z_order(S32 frame_index, S32 *z_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 min, temp;
    S32 object_z[GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM];
    gui_screen_switch_effect_object_struct *object;
    gui_screen_switch_effect_param_struct param;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    /* initialize z to infinite */
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM; i++)
    {
        object_z[i] = GUI_EFFECT_INT_VALUE_MAX;
    }

    /* get z values from all objects */
    for (i = 0; i < g_gui_screen_switch_effect_object_num; i++)
    {
        object = g_gui_screen_switch_effect_object + i;
        object->get_param_callback(object, &param, frame_index);
        object_z[i] = param.z;
    }

    /* Sort z order. A stable sort is necessary. */
    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM - 1; i++)
    {   /* simple selection sort */
        min = i;

        for (j = i + 1; j < GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM; j++)
        {
            if (object_z[j] < object_z[min])
            {
                min = j;
            }
        }

        temp = object_z[i];
        object_z[i] = object_z[min];
        object_z[min] = temp;
        
        temp = z_order[i];
        z_order[i] = z_order[min];
        z_order[min] = temp;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gui_sse_lt_transform
 * DESCRIPTION
 *  Transforms an SSE object by the GDI LT transform API.
 * PARAMETERS
 *  object         [IN] object 
 *  matrix_3x3     [IN] 3x3 transform matrix
 *  out_rect       [IN] output rect
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_lt_transform(gui_screen_switch_effect_object_struct *object, float *matrix_3x3, gui_rect *out_rect, MMI_BOOL is_affine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_lt_matrix_struct matrix;
    gdi_handle src_layer;
    S32 i;
    
    float ox, oy;

	GDI_LT_SAMPLE_MODE_ENUM sample_mode = (is_affine || gdi_lt_projective_transform_hw_support()) ? (GDI_LT_SAMPLE_MODE_BILINEAR_WITHOUT_EDGE_FILTER) : (GDI_LT_SAMPLE_MODE_NEAREST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_create_cf_using_outside_memory(
        (gdi_color_format)(object->bpp / 8),    // TODO: should use CF
        0,
        0,
        object->width,
        object->height,
        &src_layer,
        (PU8)object->buf,
        (S32)(object->width * object->height * (object->bpp / 8)));   

    /* assign 3x3 matrix */
    for (i = 0; i < 8; i++)
    {                
        matrix.m[i] = matrix_3x3[i];
    }

    ox = (float)out_rect->x;
    oy = (float)out_rect->y;

    /* SSE assumes the last element is always 1.0f */
    // TODO: to remove this limit?
    matrix.m[8] = 1.0f;

    /* turn the output rect offset to (0, 0) */
    matrix.m[0] -= ox * matrix.m[2];
    matrix.m[3] -= ox * matrix.m[5];
    matrix.m[6] -= ox * matrix.m[8];                
    matrix.m[1] -= oy * matrix.m[2];
    matrix.m[4] -= oy * matrix.m[5];
    matrix.m[7] -= oy * matrix.m[8];

    /* transpose the matrix required by LT HW */
    GUI_SSE_FSWAP(matrix.m[1], matrix.m[3]);
    GUI_SSE_FSWAP(matrix.m[2], matrix.m[6]);
    GUI_SSE_FSWAP(matrix.m[5], matrix.m[7]);

    gdi_lt_projective_transform(
        &matrix, 
        src_layer,
        0,
        0,
        object->width,
        object->height,
        GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
        GDI_COLOR_TRANSPARENT,
        sample_mode);

    gdi_layer_free(src_layer);                    
}            


/*****************************************************************************
 * FUNCTION
 *  gui_sse_convert_affine_to_projective_matrix
 * DESCRIPTION
 *  Expands the affine matrix (3x2) to the general 3x3 matrix.
 * PARAMETERS
 *  matrix_3x3          [IN]    3x3 matrix
 *  matrix_affine       [IN]    affine matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sse_convert_affine_to_projective_matrix(float *matrix_3x3, gui_effect_affine_transform_matrix_struct *matrix_affine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 *m;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m = matrix_affine->m;
    
    matrix_3x3[0] = GUI_SSE_TO_FP(m[0]);
    matrix_3x3[1] = GUI_SSE_TO_FP(m[1]);
    matrix_3x3[2] = 0;
    matrix_3x3[3] = GUI_SSE_TO_FP(m[2]);
    matrix_3x3[4] = GUI_SSE_TO_FP(m[3]);
    matrix_3x3[5] = 0;
    matrix_3x3[6] = GUI_SSE_TO_FP(m[4]);
    matrix_3x3[7] = GUI_SSE_TO_FP(m[5]);
    matrix_3x3[8] = 1.0f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_draw_world_frame
 * DESCRIPTION
 *  Displays all effect objects at a given frame index
 * PARAMETERS
 *  frame_index     [IN]      frame index
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_screen_switch_effect_draw_world_frame(S32 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    gdi_handle layers[GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM];
    S32 z_order[GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM];

    gdi_handle old_blt_layer[4];
    gui_screen_switch_effect_object_struct *object;
    gui_screen_switch_effect_param_struct param;
    S32 new_w, new_h;
    S32 pixel_size;
    S32 layer_w, layer_h;
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 x1, y1, x2, y2;

    MMI_BOOL is_scale_needed;
    MMI_BOOL use_hw_resizer;

    PU8 tmp_buf;

    gui_rect out_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remove warnings */
    clip_x1 = clip_y1 = clip_x2 = clip_y2 = 0;
    use_hw_resizer = MMI_TRUE;
    tmp_buf = NULL;

    /* blt the last frame from DM layers because the hw resizer would cause color banding */
    if (frame_index >= g_gui_screen_switch_effect_frames)
    {
        if (g_gui_screen_switch_effect_finish_callback)
        {
            g_gui_screen_switch_effect_finish_callback(frame_index);
        }

        return;
    }

    for (i = 0; i < GUI_SCREEN_SWITCH_EFFECT_MAX_OBJECT_NUM; i++)
    {
        layers[i] = GDI_NULL_HANDLE;
        z_order[i] = i;
    }

    /* create layers */
    for (i = 0; i < g_gui_screen_switch_effect_object_num; i++)
    {
        object = g_gui_screen_switch_effect_object + i;
        object->get_param_callback(object, &param, frame_index);

        new_w = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(param.scale_x, object->width);
        new_h = GUI_SCREEN_SWITCH_EFFECT_FIXED_POINT_MUL(param.scale_y, object->height);

        /* ignore HIDDEN objects */
        if (!new_w || !new_h)
        {
            continue;
        }

        if ((new_w != object->width) || (new_h != object->height))
        {
            is_scale_needed = MMI_TRUE;
            use_hw_resizer = MMI_TRUE;

            if (new_w > UI_device_width)
            {
                clip_x1 = (new_w - UI_device_width) / 2;
                clip_x2 = clip_x1 + UI_device_width - 1;     

                layer_w = UI_device_width;

                use_hw_resizer = MMI_FALSE; 
            }                
            else
            {
                clip_x1 = 0;
                clip_x2 = new_w - 1;

                layer_w = new_w;
            }           

            if (new_h > UI_device_height)
            {
                clip_y1 = (new_h - UI_device_height) / 2;
                clip_y2 = clip_y1 + UI_device_height - 1;                

                layer_h = UI_device_height;
                
                use_hw_resizer = MMI_FALSE;                
            }                
            else
            {
                clip_y1 = 0;
                clip_y2 = new_h - 1;

                layer_h = new_h;
            }
        }
        else
        {
            is_scale_needed = MMI_FALSE;

            layer_w = object->width;
            layer_h = object->height;
        }

        pixel_size = object->bpp / 8;

        if (param.transform_matrix)
        {   /* projective transform */
            gui_effect_projective_transform_matrix_struct ctm;
            S32 j;

            for (j = 0; j < 8; j++)
            {
                ctm.m[j] = GUI_EFFECT_TRANSFORM_FP(param.transform_matrix[j]);                
            }

            /* the last element must be 1 */
            ctm.m[8] = GUI_EFFECT_TRANSFORM_FP(1.0);

            /* calculate the output rect */
            gui_effect_projective_transform_get_output_rect(&ctm, object->width, object->height, &out_rect);
            if (!gui_rect_get_intersection(&out_rect, &g_gui_screen_switch_effect_world_view_rect, &out_rect))
            {
                continue;
            }

            layer_w = out_rect.width;
            layer_h = out_rect.height;      

            /* The width must be multiples of 4. */
            layer_w = (layer_w + 3) / 4 * 4;
            out_rect.width = layer_w;

            tmp_buf = (PU8)gui_effect_mem_manager_mem_alloc(&g_gui_screen_switch_effect_tmp_mem, layer_w * layer_h * pixel_size);

            gdi_layer_create_cf_using_outside_memory(
                    (gdi_color_format)pixel_size,
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &layers[i],
                    tmp_buf,
                    (S32)(layer_w * layer_h * pixel_size));   

            gdi_layer_push_and_set_active(layers[i]);
            if (object->enable_source_key)
            {
			    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
			}
			else
			{
			    gdi_layer_clear(param.bg_color);
			}

        #ifdef GUI_SSE_USE_HW_LT
            gui_sse_lt_transform(object, param.transform_matrix, &out_rect, MMI_FALSE);       
        #endif
            
            gdi_layer_pop_and_restore_active();

        #ifndef GUI_SSE_USE_HW_LT            
            gui_effect_projective_transform_apply_image(&ctm, object->buf, object->width, object->height, tmp_buf, &out_rect);
        #endif
        
            /* The object offset position is applied after the transform. */
            param.offset_x += out_rect.x;
            param.offset_y += out_rect.y;
        }
        else if (param.rotation)
        {   /* affine transform */
            gui_effect_affine_transform_matrix_struct ctm;        

            gui_effect_affine_transform_make_identity_matrix(&ctm);

            gui_effect_affine_transform_translate(&ctm, -object->width / 2, -object->height / 2);
            gui_effect_affine_transform_rotate(&ctm, param.rotation);
            gui_effect_affine_transform_translate(&ctm, object->width / 2, object->height / 2);
            
            gui_effect_affine_transform_scale(&ctm, param.scale_x << 4, param.scale_y << 4);
            gui_effect_affine_transform_translate(&ctm, param.offset_x, param.offset_y);
        
            /* calculate the output rect */
            gui_effect_affine_transform_get_output_rect(&ctm, object->width, object->height, &out_rect);
            if (!gui_rect_get_intersection(&out_rect, &g_gui_screen_switch_effect_world_view_rect, &out_rect))
            {
                continue;
            }

            param.offset_x = out_rect.x;
            param.offset_y = out_rect.y;            
            layer_w = out_rect.width;
            layer_h = out_rect.height;

            if (!layer_w || !layer_h)
            {
                continue;
            }

            tmp_buf = (PU8)gui_effect_mem_manager_mem_alloc(&g_gui_screen_switch_effect_tmp_mem, layer_w * layer_h * pixel_size);

            gdi_layer_create_cf_using_outside_memory(
                    (gdi_color_format)pixel_size,
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &layers[i],
                    tmp_buf,
                    (S32)(layer_w * layer_h * pixel_size));   

            gdi_layer_push_and_set_active(layers[i]);
            if (object->enable_source_key)
            {
			    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
			}
			else
			{
			    gdi_layer_clear(param.bg_color);
			}
            
        #ifdef GUI_SSE_USE_HW_LT
            {
                float matrix[9];

                gui_sse_convert_affine_to_projective_matrix(matrix, &ctm);
                gui_sse_lt_transform(object, matrix, &out_rect, MMI_TRUE);       
            }                
        #endif
        
            gdi_layer_pop_and_restore_active();

        #ifndef GUI_SSE_USE_HW_LT
            gui_effect_affine_transform_apply_image(&ctm, object->buf, object->width, object->height, (PU8)tmp_buf, &out_rect);                                
        #endif            
        }
        else
        {   /* normal layer operation */
            if (is_scale_needed)
            {
                tmp_buf = (PU8)gui_effect_mem_manager_mem_alloc(&g_gui_screen_switch_effect_tmp_mem, layer_w * layer_h * pixel_size);
            }

            gdi_layer_create_cf_using_outside_memory(
                    (gdi_color_format)pixel_size,
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &layers[i],
                    is_scale_needed ? tmp_buf : object->buf,
                    (S32)(layer_w * layer_h * pixel_size)); 

            /* scale */
            if (is_scale_needed && (new_w && new_h))
            {        
            #ifdef GUI_SSE_USE_HW_LT
                {
                    /* scale by transform */
                    gui_effect_affine_transform_matrix_struct ctm;        
                    float matrix[9];            
                    gui_effect_affine_transform_make_identity_matrix(&ctm);
                    gui_effect_affine_transform_scale(&ctm, param.scale_x << 4, param.scale_y << 4);
                    gui_sse_convert_affine_to_projective_matrix(matrix, &ctm);
                    
                    out_rect.x = 0;
                    out_rect.y = 0;

                    gdi_layer_push_and_set_active(layers[i]);
                    gui_sse_lt_transform(object, matrix, &out_rect, MMI_FALSE);       
                    gdi_layer_pop_and_restore_active();
                }
            #else /* GUI_SSE_USE_HW_LT */
                {
                    gui_screen_switch_effect_resizer(
                        object->buf, 
                        0,
                        0,
                        object->width,
                        object->height,
                        object->width,
                        tmp_buf,
                        new_w,
                        new_h,
                        clip_x1,
                        clip_y1,
                        clip_x2,
                        clip_y2);        
                }
            #endif /* GUI_SSE_USE_HW_LT */
            }                        
        }
        
        /* 
         * setup each layer 
         */
        gdi_layer_push_and_set_active(layers[i]);

        /* offset */    
        gdi_layer_set_position(param.offset_x, param.offset_y);

        /* enable source key */
        gdi_layer_set_source_key((BOOL)object->enable_source_key, GDI_COLOR_TRANSPARENT);
       
        /* opacity */
        gdi_layer_set_opacity(TRUE, (U8)param.opacity);

        /* background color */
        gdi_layer_set_background(param.bg_color);

        /* owner draw */
        // TODO: only lower ID object layers are valid now.
        if (object->draw_callback)
        {
            object->draw_callback(object, &param, frame_index, layers);
        }

        gdi_layer_pop_and_restore_active();       
    }   

    /* set GDI_LAYER_FLAG_FROZEN for each layer to use non-blocking blt */
    // TODO: This is tricky?
    if (g_gui_sse_world.enable_non_blocking_blt)
    {
        for (i = 0; i < g_gui_screen_switch_effect_object_num; i++)
        {
            /* set GDI_LAYER_FLAG_FROZEN for valid object layers */
            if (layers[i])
            {
                gdi_layer_push_and_set_active(layers[i]);
                gdi_layer_enter_draw_section();
                gdi_layer_exit_draw_section();
                gdi_layer_pop_and_restore_active();
            }

            /* swap double buffer */
            if (g_gui_screen_switch_effect_object[i].buf2)
            {
                PU8 temp_buf_p;

                temp_buf_p = g_gui_screen_switch_effect_object[i].buf2;
                g_gui_screen_switch_effect_object[i].buf2 = g_gui_screen_switch_effect_object[i].buf;
                g_gui_screen_switch_effect_object[i].buf = temp_buf_p;
            }            
        }
    }
    
    /* blt to the lcd */
    gdi_lcd_freeze(FALSE);
    GUI_RECT_TO_POINT(g_gui_screen_switch_effect_world_view_rect, x1, y1, x2, y2);
    gdi_layer_get_blt_layer(old_blt_layer + 0, old_blt_layer + 1, old_blt_layer + 2, old_blt_layer + 3);    

    /* sort object z order */
    gui_sse_frame_sort_z_order(frame_index, z_order);

#ifdef GDI_6_LAYERS
    gdi_layer_blt_ext(layers[z_order[0]], layers[z_order[1]], layers[z_order[2]], layers[z_order[3]], layers[z_order[4]], layers[z_order[5]], x1, y1, x2, y2);    
#else /* GDI_6_LAYERS */
    gdi_layer_blt(layers[z_order[0]], layers[z_order[1]], layers[z_order[2]], layers[z_order[3]], x1, y1, x2, y2);
#endif /* GDI_6_LAYERS */ 
    
    gdi_layer_set_blt_layer(old_blt_layer[0], old_blt_layer[1], old_blt_layer[2], old_blt_layer[3]);
    gdi_lcd_freeze(TRUE);

    /* free layers */    
    for (i = 0; i < g_gui_screen_switch_effect_object_num; i++)
    {
        if (layers[i])
        {
            gdi_layer_free(layers[i]);
        }
    }    

    /* free all temp memory */
    gui_effect_mem_manager_free_all(&g_gui_screen_switch_effect_tmp_mem);
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_screen_switch_effect_draw_world
 * DESCRIPTION
 *  Displays all screen switch effect frames.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_screen_switch_effect_draw_world(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    kal_uint32 start_time, end_time, elapsed_ms;    
    S32 next_timer_duration;
    PU8 old_tmp_mem_buf_p;
    BOOL is_non_block_blt = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid warning */
    old_tmp_mem_buf_p = NULL;
    
    /* lock the GDI mutex to prevent any intervention from other tasks */
    GDI_LOCK;

    /* enable non-blocking blt if tmp buffer size is enough */
    if (g_gui_sse_world.enable_non_blocking_blt && 
        g_gui_sse_world.tmp_buffer_p &&
        (g_gui_sse_world.tmp_buffer_size >= g_gui_screen_switch_effect_tmp_mem.free_size))
    {   /* save old tmp memory buffer for double buffer */

        /* cannot enable the non-blocking blt if the object is owner-drawn and without double buffer */
        for (i = 0; i < g_gui_screen_switch_effect_object_num; i++)
        {
            if (g_gui_screen_switch_effect_object[i].draw_callback && 
                (g_gui_screen_switch_effect_object[i].buf2 == NULL))
            {
                g_gui_sse_world.enable_non_blocking_blt = MMI_FALSE;                
                break;
            }
        }
    
        old_tmp_mem_buf_p = g_gui_screen_switch_effect_tmp_mem.buf;        
    }
    else
    {   /* disable non-blocking if not available */
        g_gui_sse_world.enable_non_blocking_blt = MMI_FALSE;
    }        

    /* enable non-blocking if conditions are met */
    if (g_gui_sse_world.enable_non_blocking_blt)
    {
        is_non_block_blt = gdi_layer_get_enable_non_block_blt();
        gdi_enable_non_block_blt();
    }        
   

    for (i = 0; i < g_gui_screen_switch_effect_frames; i++)
    {
        kal_get_time(&start_time);
   
    #if defined(__ARM9_MMU__) && defined(__MTK_TARGET__)
        INT_SwitchStackToRun(g_gui_screen_switch_effect_cached_stack, GUI_SCREEN_SWITCH_EFFECT_CACHED_STACK_SIZE, (kal_func_ptr)gui_screen_switch_effect_draw_world_frame, 1, g_gui_screen_switch_effect_current_frame_index);
        g_gui_screen_switch_effect_current_frame_index++;    
    #else /* defined(__ARM9_MMU__) && defined(__MTK_TARGET__) */
        gui_screen_switch_effect_draw_world_frame(g_gui_screen_switch_effect_current_frame_index++);  
    #endif /* defined(__ARM9_MMU__) && defined(__MTK_TARGET__) */
    
        kal_get_time(&end_time);
        
        elapsed_ms = kal_ticks_to_milli_secs(end_time - start_time);
        MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_GUI_SCREEN_SWITCH_EFFECT_PERFORMANCE, g_gui_screen_switch_effect_type, i, elapsed_ms);

        if (elapsed_ms > g_gui_screen_switch_effect_frame_duration)
        {
            next_timer_duration = 0;
        }
        else
        {
            next_timer_duration = g_gui_screen_switch_effect_frame_duration - elapsed_ms; 
        }

        /* handle early key break for some instant */        
        if (g_gui_screen_switch_effect_enable_early_key_break && gui_screen_switch_effect_is_key_pressed())
        {
            g_gui_screen_switch_effect_current_frame_index = g_gui_screen_switch_effect_frames;
            break;
        }

        /* swap tmp memory dobule buffer */
        if (g_gui_sse_world.enable_non_blocking_blt)
        {
            if (i & 1)
            {   /* Odd frames use old buffer. */
                g_gui_screen_switch_effect_tmp_mem.buf = old_tmp_mem_buf_p;            
            }
            else
            {   /* Even frames use tmp buffer.*/
                g_gui_screen_switch_effect_tmp_mem.buf = (PU8)g_gui_sse_world.tmp_buffer_p;
            }
        }

        /* sleep for time left */
        kal_sleep_task(kal_milli_secs_to_ticks(next_timer_duration));
    }         

    /* last frame */
    gui_screen_switch_effect_draw_world_frame(g_gui_screen_switch_effect_current_frame_index++);          
    
    /* disable non-blocking blt */
    if (g_gui_sse_world.enable_non_blocking_blt)
    {
        if (!is_non_block_blt)
        {
            gdi_disable_non_block_blt();
        }
    }

    /* unlock GDI mutex */
    GDI_UNLOCK;
}

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_PLUTO__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) */


