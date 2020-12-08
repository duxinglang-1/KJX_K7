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
 *  gdi_linear_transform.h
 *
 * Project:
 * --------
 *  GDI linear transform
 *
 * Description:
 * ------------
 *  GDI linear transform
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_LINEAR_TRANSFORM_H__
#define __GDI_LINEAR_TRANSFORM_H__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

typedef struct
{
    float m[9];
} gdi_lt_matrix_struct;

/* integer range */
#define GDI_LT_INT_VALUE_MAX   0x7FFFFFFF
#define GDI_LT_INT_VALUE_MIN   0x80000000

/* pi */
#define GDI_LT_PI   	3.14159265358979323846
#define GDI_LT_SET_POINT(p, _x, _y)   do { (p).x = _x; (p).y = _y; } while (0)

/* fixed point transform related */
#define GDI_LT_TRANSFORM_PRECISION_BITS  16
#define GDI_LT_TRANSFORM_ROUNDING_VALUE  (1 << (GDI_LT_TRANSFORM_PRECISION_BITS - 1))
#define GDI_LT_TRANSFORM_BILINEAR_INTERPOLATE_BITS   7   /* max 7 */

extern gdi_result gdi_lt_projective_transform(
                    gdi_lt_matrix_struct *matrix, 
                    gdi_handle src_layer_handle,
                    kal_int32 src_rect_x,
                    kal_int32 src_rect_y,
                    kal_int32 src_rect_w,
                    kal_int32 src_rect_h,
                    GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,
                    kal_uint32 edge_filter_color,
                    GDI_LT_SAMPLE_MODE_ENUM sample_mode);

extern gdi_result gdi_lt_projective_transform_ext(
                    gdi_lt_matrix_struct *matrix,
                    gdi_handle src_layer_handle,
                    kal_int32 src_rect_x,
                    kal_int32 src_rect_y,
                    kal_int32 src_rect_w,
                    kal_int32 src_rect_h,
                    kal_int32 dst_rect_x,
                    kal_int32 dst_rect_y,
                    kal_int32 dst_rect_w,
                    kal_int32 dst_rect_h,
                    GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,
                    kal_uint32 edge_filter_color,
                    GDI_LT_SAMPLE_MODE_ENUM sample_mode,
                    kal_uint32 flag);

extern void gdi_lt_projective_transform_get_inverse_matrix(
                    gdi_lt_matrix_struct *in, 
                    gdi_lt_matrix_struct *out);

extern void gdi_lt_projective_transform_get_output_rect(
                    gdi_lt_matrix_struct *matrix, 
                    S32 in_width, 
                    S32 in_height, 
                    gdi_rect_struct *out_rect);

extern void gdi_lt_projective_transform_apply_point(
                    gdi_lt_matrix_struct *matrix, 
                    gdi_point_S32_struct *point);

extern kal_bool gdi_lt_projective_transform_hw_support(void);

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

#endif /* __GDI_LINEAR_TRANSFORM_H__ */



