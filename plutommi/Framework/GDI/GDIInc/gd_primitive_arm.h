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
 *  gd_primitive_arm.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_primitive.h"

#ifndef __GD_PRIMITIVE_ARM__
#define __GD_PRIMITIVE_ARM__

extern int GDI_GRAY16SET(int add_end, int add);

/* fast sw resizer */
//extern GDI_RESULT gdi_bitblt_resized_sw(gdi_handle src_layer_handle, S32 sx1, S32 sy1, S32 sx2, S32 sy2, S32 dx1, S32 dy1, S32 dx2, S32 dy2, BOOL is_high_quality);


extern gdi_color gdi_img_buf_convert_color(
    gdi_color from_color, 
    gdi_img_buf_color_format_enum to_format,
    gdi_img_buf_color_format_enum from_format);

extern void gdi_img_buf_fill_byte(
    gdi_img_buf_struct *dst_buf, 
    U8 dst_byte,
    S32 width,
    S32 height);

extern void gdi_img_buf_fill_color_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_fill_color_24(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_fill_color_32(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_color_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_color_24(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_color_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_flatten_16_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_flatten_general(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_copy_same_format(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_copy_general(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_16_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_24_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_PARGB8888_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_PARGB8888_to_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_convert_PARGB8888_from_ARGB8888(
    gdi_img_buf_struct *buf, 
    S32 width,
    S32 height);

extern void gdi_img_buf_convert_ARGB8888_from_PARGB8888(
    gdi_img_buf_struct *buf, 
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_PARGB6666_to_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_PARGB6666_to_RGB565(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

#endif /* __GD_PRIMITIVE_ARM__ */

