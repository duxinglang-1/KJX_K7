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
 *  gdi_
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __GDI_UTIL_H__
#define __GDI_UTIL_H__

#include "MMIDataType.h"
#include "gdi_features.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#define GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS 7

extern const S16 gdi_alpha_inverse_table[];

/*
 * For a PARGB8888 element = (A, AR, AG, AB), use this macro to divide
 * PR, PG or PB by A to recover R, G, B.
 * That is, corresponding ARGB8888 = (A, GDI_DIVIDE_ALPHA_255(A, PR), ...)
 */
#define GDI_DIVIDE_ALPHA_255(a, pc) \
    (((pc) * gdi_alpha_inverse_table[(a)]) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS)


extern U32 gdi_fast_semi_crc(U8 *src, U32 size);


extern S32 gdi_ucs2_stricmp(U16 *s1,U16 *s2);

extern void gdi_util_convert_PARGB8888_to_ARGB8888_buf(
                U8 *buf_p, 
                S32 buf_width, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height);

extern void gdi_util_convert_ARGB8888_to_PARGB8888_buf(
                U8 *buf_p, 
                S32 buf_width, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height);

extern GDI_RESULT gdi_util_rotator(
                   GDI_ROTATOR_ENUM rotator_type,
                   U8 rotate_angle,
                   U8* src_ptr,
                   U8  src_cf,
                   U32 src_pitch,
                   U32 src_height,
                   S32 src_x,
                   S32 src_y,
                   U32 src_w,
                   U32 src_h,
                   U8* dst_ptr,
                   U8  dst_cf, 
                   U32 dst_pitch,
                   U32 dst_height,
                   S32 dst_x,
                   S32 dst_y,
                   U32 dst_w,
                   U32 dst_h);

extern GDI_RESULT gdi_util_layer_rotator(
                   GDI_ROTATOR_ENUM rotator_type,
                   U8 rotate_angle,
                   gdi_handle src_layer_handle,
                   S32 src_x,
                   S32 src_y,
                   U32 src_w,
                   U32 src_h,
                   S32 dst_x,
                   S32 dst_y,
                   U32 dst_w,
                   U32 dst_h);

extern GDI_RESULT gdi_bitblt_sw(
                gdi_handle src_layer_handle, 
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 dx1,
                S32 dy1);

#endif /* __GDI_UTIL_H__ */ 


