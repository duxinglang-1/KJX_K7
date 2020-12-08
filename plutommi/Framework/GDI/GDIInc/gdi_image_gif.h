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
 *  gdi_image_gif.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Gif header file.
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
#ifndef _GDI_IMAGE_GIF_H_
#define _GDI_IMAGE_GIF_H_

#include "fs_type.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

/****************************************************************************
* Variable
*****************************************************************************/
extern gdi_color gdi_gif_local_palette[256];

/***************************************************************************** 
* HW Gif V1 and V2 Function
*****************************************************************************/

/***************************************************************************** 
* Gif Function 
*****************************************************************************/
extern GDI_RESULT gdi_image_gif_draw(S32 ox, S32 oy, U8 *GIF_src, U32 size, U16 frame_number);
extern GDI_RESULT gdi_image_gif_draw_file(S32 ox, S32 oy, const S8 *filename, U16 frame_number);
extern GDI_RESULT gdi_image_gif_draw_resized(
                    S32 ox,
                    S32 oy,
                    S32 resized_width,
                    S32 resized_height,
                    U8 *GIF_src,
                    U32 size,
                    U16 frame_number);
extern GDI_RESULT gdi_image_gif_draw_with_background_color(
                    U8 *GIF_src,
                    U32 size,
                    U16 frame_number,
                    gdi_color background_color,
                    BOOL *is_transparent);
extern GDI_RESULT gdi_image_gif_draw_resized_file(
                    S32 ox,
                    S32 oy,
                    S32 resized_width,
                    S32 resized_height,
                    const S8 *filename,
                    U16 frame_number);

extern GDI_RESULT gdi_image_gif_get_dimension(U8 *GIF_src, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_gif_get_dimension_file(const S8 *filename, S32 *width, S32 *height);

extern GDI_RESULT gdi_image_gif_draw_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT gdi_image_gif_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_is_gif_file(U8 *file_name);
extern GDI_RESULT gdi_image_gif_get_pos_info_handler(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    BOOL quick_mode,
                    S32 *total_pos,
                    gdi_anim_pos_type_enum *pos_type);

extern GDI_RESULT gdi_image_gif_get_frame_delay(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    S32 *frame_count,
                    U32 *frame_delay_array, 
                    U32 max_frame_count);
extern GDI_RESULT gdi_image_gif_get_frame_delay_from_file(
                    const S8 *filename, 
                    S32 *frame_count, 
                    U32 *frame_delay_array, 
                    U32 max_frame_count);
extern GDI_RESULT gdi_image_gif_get_frame_delay_from_mem(
                    U8 *data_ptr, 
                    U32 size, 
                    S32 *frame_count, 
                    U32 *frame_delay_array, 
                    U32 max_frame_count);
extern void gdi_image_gif_reset_entry_file(const S8* filename);

extern GDI_RESULT gdi_imgdec_gif_draw_internal(
                   gdi_handle output_layer_handle,
                   S32 ox,
                   S32 oy,
                   S32 resized_width,
                   S32 resized_height,
                   U8 *src,
                   U32 size,
                   U16 frame_number,
                   BOOL is_file,
                   kal_bool src_key_enable,
                   kal_uint32 src_key_value,
                   BOOL *is_aborted,
                   U32 flag,
                   S32 aspect_flag);

extern GDI_RESULT gdi_image_gif_check_animation(U8 *data_ptr, U32 size, MMI_BOOL *is_anim);
extern GDI_RESULT gdi_image_gif_check_animation_file(const S8 *filename, MMI_BOOL *is_anim);

extern GDI_RESULT gdi_image_gif_get_disposal(
                   U32 flag,
                   U8 *data_ptr,
                   U32 img_size,
                   S32 *frame_count,
                   GDI_GIF_DISPOSAL_ENUM *frame_disposal_array,
                   U32 max_frame_count);
extern GDI_RESULT gdi_image_gif_get_disposal_from_file(
                   const S8 *filename, 
                   S32 *frame_count, 
                   GDI_GIF_DISPOSAL_ENUM *frame_disposal_array, 
                   U32 max_frame_count);
extern GDI_RESULT gdi_image_gif_get_disposal_from_mem(
                   U8 *data_ptr, 
                   U32 size, 
                   S32 *frame_count, 
                   GDI_GIF_DISPOSAL_ENUM *frame_disposal_array,
                   U32 max_frame_count);
extern void gdi_image_gif_set_palette_color_format(gdi_color_format cf);
#endif /* _GDI_IMAGE_GIF_H_ */ 


