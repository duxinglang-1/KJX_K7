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
 *  gdi_image.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMAGE_H_
#define _GDI_IMAGE_H_

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

/****************************************************************************
* Define                                                              
*****************************************************************************/
#define GDI_IMAGE_CODEC_TIMEOUT  6 // seconds

/****************************************************************************
* Struct / Typedef                                                                 
*****************************************************************************/

typedef struct
{
    GDI_RESULT(*draw_before) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*draw) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*draw_after) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*get_dimension) (U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height);
    GDI_RESULT(*get_pos_info) (U32 flag, U8 *data_ptr, U32 img_size, BOOL quick_mode, S32 *total_pos,
                               gdi_anim_pos_type_enum *pos_type);
    GDI_RESULT(*is_match_file_type) (U8 *file_name);
    BOOL is_animation;
} gdi_image_codecs_struct;

extern const gdi_image_codecs_struct gdi_image_codecs[GDI_IMAGE_TYPE_SUM + 1];
extern  U16 *const gdi_image_ext_name[];
extern BOOL gdi_memory_output;
extern U16 gdi_memory_output_width;
extern U16 gdi_memory_output_height;
extern U32 gdi_memory_output_buffer_address;
extern U32 gdi_memory_output_buffer_size;

/****************************************************************************
* Function Declar                                                              
*****************************************************************************/
/* init function */
extern GDI_RESULT gdi_image_init(void);
extern void gdi_image_parse_resource_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size, S32 *frame_number, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_parse_info(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 **data_ptr,
                    U8 *img_type,
                    S32 *img_size,
                    S32 *frame_number,
                    S32 *width,
                    S32 *height);

extern GDI_RESULT gdi_image_codec_get_dimension(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 *width,
                    S32 *height,
                    U32 flag);
extern GDI_RESULT gdi_image_codec_get_frame_count(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 *frame_count,
                    U32 flag);
extern U32 gdi_image_codec_get_flag(void);
extern void gdi_image_codec_set_flag(U32 flag);

extern GDI_RESULT gdi_image_single_bank_cache_load(const U8 *img_src, S32 img_size, BOOL *reloaded);
extern U8 *gdi_image_single_bank_cache_get_buffer(void);
extern void gdi_image_single_bank_cache_reset(void);
extern void gdi_image_single_bank_cache_reset_entry(const U8 *img_src, S32 img_size);

extern void gdi_image_set_timeout(S32 seconds);
extern void gdi_image_clear_timeout(void);
extern BOOL gdi_image_is_timeout(void);
extern void gdi_image_set_abort(BOOL is_abort);
extern BOOL gdi_image_is_abort(void);
extern BOOL gdi_nb_is_high_priority(void);

/* 
 * Image Helper functions 
 */
extern GDI_RESULT gdi_image_create_temp_layer(
    gdi_handle *temp_layer_handle,
    gdi_color_format cf,
    S32 x,
    S32 y,
    S32 width,
    S32 height);
    
extern void gdi_image_free_temp_layer(gdi_handle temp_layer_handle);

#define gdi_image_resize_and_blending(layer_handle, dst_x, dst_y, resized_width, resized_height) \
    gdi_image_resize_and_blending_ex(layer_handle, dst_x, dst_y, resized_width, resized_height, MMI_FALSE);

extern GDI_RESULT gdi_image_resize_and_blending_ex(
    gdi_handle layer_handle, 
    S32 dst_x, 
    S32 dst_y, 
    S32 resized_width, 
    S32 resized_height,
    MMI_BOOL always_blending);

extern GDI_RESULT gdi_image_bitlit_PARGB8888(gdi_handle img_layer);

extern GDI_RESULT gdi_image_blending_32_to_16(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height);

extern GDI_RESULT gdi_image_blending_32_to_24(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height);

extern GDI_RESULT gdi_image_blending_32_to_32(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height);

extern GDI_RESULT gdi_image_blending_PARGB8888_to_PARGB6666(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height);

#endif /* _GDI_IMAGE_H_ */ 


