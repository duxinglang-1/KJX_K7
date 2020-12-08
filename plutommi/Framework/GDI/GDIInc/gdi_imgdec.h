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
 *  gdi_imgdec.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC interface for GDI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMGDEC_H__
#define __GDI_IMGDEC_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GDI_IMGDEC_START_LOGGING(_symbol_)
#define GDI_IMGDEC_STOP_LOGGING(_symbol_)
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/*
 * IMGDEC APIs
 */
typedef void (*gdi_imgdec_nb_done_callback_funcptr)(GDI_RESULT result, gdi_handle handle);

#define gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, src_type, frame_index) \
            gdi_imgdec_draw_internal( \
                output_layer, \
                GDI_NULL_HANDLE, \
                src_type, \
                img_ptr, \
                img_type, \
                img_size, \
                x, \
                y, \
                w, \
                h, \
                frame_index, \
                NULL, \
                0, \
                0)

#define gdi_imgdec_draw(output_layer, x, y, img_ptr) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, 0)
#define gdi_imgdec_draw_resized(output_layer, x, y, w, h, img_ptr) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, 0)
#define gdi_imgdec_draw_mem(output_layer, x, y, img_ptr, img_type, img_size) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, 0)
#define gdi_imgdec_draw_resized_mem(output_layer, x, y, w, h, img_ptr, img_type, img_size) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, 0)
#define gdi_imgdec_draw_file(output_layer, x, y, filename_ptr) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, filename_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, 0)
#define gdi_imgdec_draw_resized_file(output_layer, x, y, w, h, filename_ptr) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, filename_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, 0)

#define gdi_imgdec_draw_frames(output_layer, x, y, img_ptr, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, frame_index)
#define gdi_imgdec_draw_resized_frames(output_layer, x, y, w, h, img_ptr, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, frame_index)
#define gdi_imgdec_draw_mem_frames(output_layer, x, y, img_ptr, img_type, img_size, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, frame_index)
#define gdi_imgdec_draw_resized_mem_frames(output_layer, x, y, w, h, img_ptr, img_type, img_size, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, frame_index)
#define gdi_imgdec_draw_file_frames(output_layer, x, y, filename_ptr, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, 0, 0, filename_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, frame_index)
#define gdi_imgdec_draw_resized_file_frames(output_layer, x, y, w, h, filename_ptr, frame_index) gdi_imgdec_draw_resized_frames_internal(output_layer, x, y, w, h, filename_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, frame_index)

/*
 * get dimension
 */
#define gdi_imgdec_get_dimension(src, width, height) gdi_imgdec_get_dimension_internal(GDI_IMAGE_SRC_FROM_RESOURCE, (U8*)src, 0, 0, width, height)
#define gdi_imgdec_get_dimension_file(filename, width, height) gdi_imgdec_get_dimension_internal(GDI_IMAGE_SRC_FROM_FILE, (U8*)filename, 0, 0, width, height)
#define gdi_imgdec_get_dimension_mem(src, img_type, img_size, width, height) gdi_imgdec_get_dimension_internal(GDI_IMAGE_SRC_FROM_FILE, (U8*)src, img_type, img_size, width, height)



/*
 * IMGDEC nonblocking
 */
#define gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, src_type, frame_index, done_callback) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                src_type, \
                img_ptr, \
                img_type, \
                img_size, \
                x, \
                y, \
                w, \
                h, \
                frame_index, \
                done_callback, \
                0, \
                0)

#define gdi_imgdec_nb_draw(output_layer, x, y, img_ptr, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, 0, done_callback)
#define gdi_imgdec_nb_draw_resized(output_layer, x, y, w, h, img_ptr, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, 0, done_callback)
#define gdi_imgdec_nb_draw_mem(output_layer, x, y, img_ptr, img_type, img_size, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, 0, done_callback)
#define gdi_imgdec_nb_draw_resized_mem(output_layer, x, y, w, h, img_type, img_size, img_ptr, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, 0, done_callback)
#define gdi_imgdec_nb_draw_file(output_layer, x, y, img_ptr, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, 0, done_callback)
#define gdi_imgdec_nb_draw_resized_file(output_layer, x, y, w, h, img_ptr, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, 0, done_callback)

#define gdi_imgdec_nb_draw_frames(output_layer, x, y, img_ptr, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, frame_index, done_callback)
#define gdi_imgdec_nb_draw_resized_frames(output_layer, x, y, w, h, img_ptr, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_RESOURCE, frame_index, done_callback)
#define gdi_imgdec_nb_draw_mem_frames(output_layer, x, y, img_ptr, img_type, img_size, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, frame_index, done_callback)
#define gdi_imgdec_nb_draw_resized_mem_frames(output_layer, x, y, w, h, img_ptr, img_type, img_size, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, img_type, img_size, GDI_IMAGE_SRC_FROM_MEMORY, frame_index, done_callback)
#define gdi_imgdec_nb_draw_file_frames(output_layer, x, y, img_ptr, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, 0, 0, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, frame_index, done_callback)
#define gdi_imgdec_nb_draw_resized_file_frames(output_layer, x, y, w, h, img_ptr, frame_index, done_callback) gdi_imgdec_nb_draw_resized_frames_internal(output_layer, x, y, w, h, img_ptr, 0, 0, GDI_IMAGE_SRC_FROM_FILE, frame_index, done_callback)

#define gdi_imgdec_nb_draw_resized_mem_with_flag(output_layer, x, y, w, h, img_type, img_size, img_ptr, done_callback, flag) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_MEMORY, \
                img_ptr, \
                img_type, \
                img_size, \
                x, \
                y, \
                w, \
                h, \
                0, \
                done_callback, \
                flag, \
                0)

#define gdi_imgdec_nb_draw_resized_file_with_flag(output_layer, x, y, w, h, img_ptr, done_callback, flag) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_FILE, \
                img_ptr, \
                0, \
                0, \
                x, \
                y, \
                w, \
                h, \
                0, \
                done_callback, \
                flag, \
                0)

#define gdi_imgdec_nb_aspect_draw_resized_with_flag(output_layer, x, y, w, h, img_ptr, done_callback, flag, aspect) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_RESOURCE, \
                img_ptr, \
                0, \
                0, \
                x, \
                y, \
                w, \
                h, \
                0, \
                done_callback, \
                flag, \
                aspect)

#define gdi_imgdec_nb_aspect_draw_resized_mem_with_flag(output_layer, x, y, w, h, img_type, img_size, img_ptr, done_callback, flag, aspect) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_MEMORY, \
                img_ptr, \
                img_type, \
                img_size, \
                x, \
                y, \
                w, \
                h, \
                0, \
                done_callback, \
                flag, \
                aspect)

#define gdi_imgdec_nb_aspect_draw_resized_file_with_flag(output_layer, x, y, w, h, img_ptr, done_callback, flag, aspect) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_FILE, \
                img_ptr, \
                0, \
                0, \
                x, \
                y, \
                w, \
                h, \
                0, \
                done_callback, \
                flag, \
                aspect)

#define gdi_imgdec_nb_aspect_draw_resized_file_frames_with_flag(output_layer, x, y, w, h, img_ptr, frame_index, done_callback, flag, aspect) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_FILE, \
                img_ptr, \
                0, \
                0, \
                x, \
                y, \
                w, \
                h, \
                frame_index, \
                done_callback, \
                flag, \
                aspect)

#define gdi_imgdec_nb_aspect_draw_resized_mem_frames_with_flag(output_layer, x, y, w, h, img_ptr, img_type, img_size, frame_index, done_callback, flag, aspect) \
            gdi_imgdec_nb_draw_internal( \
                output_layer, \
                GDI_IMAGE_SRC_FROM_MEMORY, \
                img_ptr, \
                img_type, \
                img_size, \
                x, \
                y, \
                w, \
                h, \
                frame_index, \
                done_callback, \
                flag, \
                aspect)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern kal_bool g_imgdec_timer_timeout_flag;
extern GDI_RESULT gdi_imgdec_draw_internal(
            gdi_handle output_layer,
            gdi_handle source_layer,
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            U32 resize_width,
            U32 resize_height,
            U32 frame_index,
            BOOL *is_aborted,
            U32 flag,
            U32 aspect_flag);

extern gdi_handle gdi_imgdec_nb_draw_internal(
            gdi_handle output_layer,
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 frame_index,
            gdi_imgdec_nb_done_callback_funcptr done_callback,
            U32 img_flag,
            U32 aspect_flag);
extern GDI_RESULT gdi_imgdec_nb_stop_all(void);
extern GDI_RESULT gdi_imgdec_nb_stop(gdi_handle job);
extern GDI_RESULT gdi_imgdec_get_dimension_internal(gdi_image_src_enum src_type, U8 *img_src, U8 img_type, U32 img_size, S32 *width, S32 *height);

#endif /* __GDI_IMGDEC_H__ */


