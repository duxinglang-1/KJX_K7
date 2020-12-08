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
 *  gif_decode_int_sw.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Gif related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SW_GIF_DECODER_H_
#define _SW_GIF_DECODER_H_

/****************************************************************************
* Define
*****************************************************************************/
/* color format */
#define GIF_SW_COLOR_FORMAT_1             0        /* 1-bit , black/white color */
#define GIF_SW_COLOR_FORMAT_8             1        /* 8-bit , index color */
#define GIF_SW_COLOR_FORMAT_16            2        /* 16-bit, rgb 565 */
#define GIF_SW_COLOR_FORMAT_24            3        /* 24-bit, B,G,R       8,8,8 */
#define GIF_SW_COLOR_FORMAT_32            4        /* 32-bit, B,G,R,A  8,8,8,8 */
#define GIF_SW_COLOR_FORMAT_STANDARD_END  5        /* standard color format end marker */
#define GIF_SW_COLOR_FORMAT_LCD0          5        /* this usually mapping to main lcd */
#define GIF_SW_COLOR_FORMAT_LCD1          6        /* this usually mapping to sub lcd */
#define GIF_SW_COLOR_FORMAT_END           7
#define GIF_SW_COLOR_FORMAT_MAINLCD       GIF_SW_COLOR_FORMAT_LCD0
#define GIF_SW_COLOR_FORMAT_SUBLCD        GIF_SW_COLOR_FORMAT_LCD1

/* return code */
#define GIF_SW_RET_SUCCEED          0
#define GIF_SW_RET_FAILED           -1
#define GIF_SW_RET_DECODE_TIME_OUT  -1416
#define GIF_SW_RET_PARA_ERROR       -1415
/* GIF_SW_CACHE_COUNT must >= animation playing number at the same time */
#ifndef LOW_COST_SUPPORT
#define GIF_SW_CACHE_COUNT (8)
#else
#define GIF_SW_CACHE_COUNT (2)
#endif

#define  MAX_GIF_FRAME_SUM  47  /* the size of gif frame cache of each gif image */

#if DRV_LAYER_TOTAL_COUNT == 6
    #define GIF_SW_USING_LAYER
#elif DRV_LAYER_TOTAL_COUNT == 4
    #define GIF_SW_USING_LAYER
#elif DRV_LAYER_TOTAL_COUNT == 2
    #define GIF_SW_USING_LAYER
#endif
/****************************************************************************
* Type Define
*****************************************************************************/
#include "drv_features.h"
#include "kal_general_types.h"
#ifndef SWGIF_VC_PROJ
#include "fs_type.h"
#include "kal_public_defs.h"
#endif
#include "fsal.h"
#include "gif_decode_api.h"

typedef kal_uint32 gif_sw_color;
/* clip region structure */
typedef struct
{
    kal_int32 x1;
    kal_int32 y1;
    kal_int32 x2;
    kal_int32 y2;
} gif_sw_rect_struct;

typedef void        (*gif_sw_bitblt_func)(
                        kal_uint8 *src_ptr, 
                        kal_int32 src_pitch, 
                        kal_int32 src_offset_x, 
                        kal_int32 src_offset_y, 
                        kal_int32 src_width, 
                        kal_int32 src_height, 
                        kal_uint8 *dest_ptr, 
                        kal_int32 dest_pitch, 
                        kal_int32 dest_offset_x, 
                        kal_int32 dest_offset_y, 
                        gif_sw_rect_struct dest_clip,
                        kal_int32 bits_per_pixel);
typedef kal_uint32  (*gif_sw_get_cache_key_from_file_func)(
                        FS_HANDLE file_handle, 
                        const kal_int8 *filename, 
                        kal_uint32 file_size);
typedef void        (*gif_sw_layer_set_palette_func)(kal_uint8 index, gif_sw_color color);     /* function to set gdi_layer_palette */    
typedef void        (*gif_sw_anim_set_delay_func)(kal_uint32 delay);                           /* set gdi animation delay time */
typedef kal_int32   (*gif_sw_image_progress_callback_func)(void);
typedef void        (*gif_sw_set_update_area_func)(
                        kal_int32 x1,
                        kal_int32 y1,
                        kal_int32 x2,
                        kal_int32 y2);
typedef void        (*gif_sw_resizer_put_func) (
                        kal_int32* want_sx,
                        gif_sw_color c, 
                        kal_bool want_draw);

typedef void        (*gif_sw_resizer_update_wantxy) (kal_int32* want_sx, kal_bool interlaced);

typedef kal_int32   (*gif_sw_draw_func) (
                        kal_int32 ox, 
                        kal_int32 oy,
                        kal_bool is_resized, 
                        kal_int32 resized_width, 
                        kal_int32 resized_height,
                        kal_uint8 *src, 
                        kal_uint32 size,
                        kal_uint32 cache_id,
                        kal_uint16 frame_number, 
                        kal_bool use_disposal_method, 
                        kal_bool transparent_enable);
typedef gif_sw_color(*gif_sw_color_from_rgb_func) (
                        kal_uint32 A, 
                        kal_uint32 R, 
                        kal_uint32 G, 
                        kal_uint32 B);
typedef gif_sw_color(*gif_sw_get_pixel_func) (
                        kal_int32 x, 
                        kal_int32 y);
typedef void        (*gif_sw_put_pixel_func) (
                        kal_int32 x, 
                        kal_int32 y, 
                        gif_sw_color c);

/****************************************************************************
* Struct
*****************************************************************************/
typedef struct
{
    kal_int32  disposal_method:2;       /* current frame disposal method */
    kal_int32  last_disposal_method:2;  /* previous frame disposal method */
    kal_uint32  has_gct:1;
	
	kal_uint16 image_width;
	kal_uint16 image_height;
	kal_uint16 latest_frame;	/* not used if total frame number is not larger than MAX_GIF_FRAME_SUM */

    kal_uint32 cache[MAX_GIF_FRAME_SUM + 1];
    kal_uint16 frame_disposal_method[MAX_GIF_FRAME_SUM + 1];

    gif_sw_color palette[256];          /* global palette */
    gif_sw_color original_background;
    kal_int32 x,y;    
    kal_int32 last_frame_x1;
    kal_int32 last_frame_y1;
    kal_int32 last_frame_x2;
    kal_int32 last_frame_y2;
    kal_uint8 *disposal_bg_buf;
    kal_int32 disposal_bg_buf_size;
    /* disposal_frame is the frame corresponds to last_disposal_method,
       add this to prevent using the wrong disposal method 
       when gdi draw single frame of gif animation */
    kal_int32 disposal_frame;
    kal_int32 final_frame_index;    
    kal_bool is_animation_file; //  0: still image; 1: animation file
    kal_bool animation_file_check_done; // 0: have not check; 1: check done.

} gif_sw_image_struct;

/****************************************************************************
* Variable
*****************************************************************************/
extern kal_uint8 *g_gif_sw_dest_buf_ptr;
extern kal_uint16 g_gif_sw_dest_buf_width;
//extern kal_uint8 g_gif_sw_dest_vcf;
//extern kal_uint8 g_gif_sw_dest_cf;
extern kal_int32 g_gif_sw_dest_clipx1;
extern kal_int32 g_gif_sw_dest_clipy1;
extern kal_int32 g_gif_sw_dest_clipx2;
extern kal_int32 g_gif_sw_dest_clipy2;
extern gif_sw_put_pixel_func g_gif_sw_act_put_pixel;
extern void (*g_gif_sw_set_update_area)(kal_int32 x1,kal_int32 y1,kal_int32 x2,kal_int32 y2);


/****************************************************************************
* Function
*****************************************************************************/
extern kal_int32 gif_sw_init(
                    kal_int16 *gif_sw_stack,
                    kal_int32 *gif_sw_tree_buffer,
                    gif_sw_color *gif_sw_local_palette,
                    gif_sw_layer_set_palette_func gif_sw_layer_set_palette,
                    gif_sw_anim_set_delay_func gif_sw_anim_set_delay,
                    gif_sw_set_update_area_func gif_sw_set_update_area,
                    gif_sw_image_progress_callback_func gif_sw_image_progress_callback,
                    gif_sw_get_cache_key_from_file_func gif_sw_get_cache_key_from_file,
                    kal_bool using_disposal,
                    KAL_ADM_ID gif_sw_disposal_buf_adm_id,
                    gif_sw_bitblt_func gif_sw_bitblt);
extern kal_int32 gif_sw_set_dest_buf(
                    kal_uint8 *gif_sw_dest_buf_ptr,
                    kal_uint16 gif_sw_dest_buf_width);
extern kal_int32 gif_sw_set_dest_color_format(
                    kal_uint8 gif_sw_dest_cf,
                    kal_uint8 gif_sw_dest_vcf);
extern kal_int32 gif_sw_set_dest_source_key(
                    kal_bool gif_sw_dest_source_key_enable,
                    kal_uint32 gif_sw_dest_source_key);
extern kal_int32 gif_sw_set_dest_clip(
                    kal_int16 gif_sw_dest_clipx1,
                    kal_int16 gif_sw_dest_clipy1,
                    kal_int16 gif_sw_dest_clipx2,
                    kal_int16 gif_sw_dest_clipy2);

extern kal_int32 gif_sw_get_image_dimension_internal(
                    STFSAL* pfsal,
                    kal_uint32 *width,
                    kal_uint32 *height);

extern kal_int32 gif_sw_get_dimension_mem(
                    kal_uint8 *src,
                    kal_int32 *width, 
                    kal_int32 *height);


extern GIF_STATUS_ENUM gif_sw_draw_resized(
                    kal_int32 ox,
                    kal_int32 oy,
                    kal_int32 resized_width,
                    kal_int32 resized_height,
                    kal_uint8 *src,
                    kal_uint32 size,
                    kal_uint16 frame_number,
                    kal_bool transparent_enable,
                    GIF_COLOR_FORMAT_ENUM output_format,
                    GIF_COLOR_FORMAT_ENUM palette_format);

extern GIF_STATUS_ENUM gif_sw_draw(
                    kal_int32 ox, 
                    kal_int32 oy, 
                    kal_uint8 *GIF_src, 
                    kal_uint32 size, 
                    kal_uint16 frame_number,
                    kal_bool transparent_enable,
                    GIF_COLOR_FORMAT_ENUM output_format,
                    GIF_COLOR_FORMAT_ENUM palette_format);

extern kal_bool gif_sw_gif_hit_cache(
                    kal_uint32 cache_id, 
                    kal_int32 x,
                    kal_int32 y,
                    kal_bool compare_xy,
                    kal_uint16 frame_number, 
                    kal_int16 *cache_index, 
                    kal_int32 *frame_counter, 
                    kal_int32 *offset, 
                    kal_bool update);

extern void gif_sw_cache_reset(void);
extern void gif_sw_cache_reset_entry(kal_uint32 cache_id);
extern kal_uint16 gif_sw_get_transparent_index(void);

kal_int32 gif_sw_get_all_frame_disposal_method( 
    STFSAL* fsal_handle,
    kal_int32 *frame_count,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method,
    kal_uint32 max_delay_count);

kal_int32 gif_sw_get_frame_n_disposal_method( 
    STFSAL* fsal_handle,
    kal_uint32 cache_id,
    kal_int32 frame_index,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method);

kal_int32 gif_sw_get_next_frame_disposal_method( 
    STFSAL* fsal_handle,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method);

gif_sw_image_struct* 
_gif_sw_get_cache_by_id(kal_uint32 cache_idx);

kal_int32 _gif_sw_offset_to_first_frame(STFSAL* pfsal);

kal_int32 gif_sw_get_n_frames_disposal_method( 
    STFSAL* fsal_handle,
    kal_int32 desired_n_frames, //input
    kal_int32 *rael_frame_count, //output
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method,
    kal_uint32 array_size);

#endif /* _SW_GIF_DECODER_H_ */ 


