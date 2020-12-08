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
 *  gdi_2d_engine.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  2D functions including 2D bitblt (rotation, mirror) and font
 *
 *  This file is not included in gdi_include.h. To use 2D engine functions, 
 *  application need to include the file separately.
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
 *==============================================================================
 *******************************************************************************/

#ifndef __GDI_2D_ENGINE_H__
#define __GDI_2D_ENGINE_H__



#if defined(GDI_USING_2D_ENGINE_V3)
#include "g2d_enum.h"
#endif

#include "kal_general_types.h"
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "gdi_const.h"

#define GDI_MAX_TILT_TABLE_SIZE 31  /* Hardware limitation */

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GDI_G2D_START_LOGGING(_symbol_)
#define GDI_G2D_STOP_LOGGING(_symbol_)
#endif

typedef struct
{
    U8   cf;                     /* color format of the specified layer */   
    gdi_color   fill_color;             /* fill color of the specified layer */    
    kal_uint8   opacity_value;          /* (keep)opacity value for specified layer */
    kal_bool    opacity_enable;         /* (keep)enable/disable opacity for specified layer */
} gdi_lt_fill_color_src_struct;


#if defined(GDI_USING_2D_ENGINE_V3)

#define GDI_TRANSFORM_NONE                  G2D_CW_ROTATE_ANGLE_000
#define GDI_TRANSFORM_MIRROR                G2D_CW_ROTATE_ANGLE_MIRROR_000

#define GDI_TRANSFORM_MIRROR_ROTATE_90      G2D_CW_ROTATE_ANGLE_MIRROR_090
#define GDI_TRANSFORM_MIRROR_ROTATE_180     G2D_CW_ROTATE_ANGLE_MIRROR_180
#define GDI_TRANSFORM_MIRROR_ROTATE_270     G2D_CW_ROTATE_ANGLE_MIRROR_270

#define GDI_TRANSFORM_ROTATE_90             G2D_CW_ROTATE_ANGLE_090
#define GDI_TRANSFORM_ROTATE_180            G2D_CW_ROTATE_ANGLE_180
#define GDI_TRANSFORM_ROTATE_270            G2D_CW_ROTATE_ANGLE_270

/* Start the operation from the right-bottom */
#define GDI_TRANSFORM_DIRECTION_RB          FROM_LOWER_RIGHT_CORNER
#define GDI_TRANSFORM_DIRECTION_LB          FROM_LOWER_LEFT_CORNER
#define GDI_TRANSFORM_DIRECTION_RT          FROM_UPPER_RIGHT_CORNER
#define GDI_TRANSFORM_DIRECTION_LT          FROM_UPPER_LEFT_CORNER

/* V2-compatible API */
extern void gdi_2d_begin(void);
extern void gdi_2d_end(void);
extern void gdi_2d_set_layer_as_dest_buffer(gdi_handle handle);

/* V3 API */
extern gdi_result gdi_2d_set_layer_as_src_bitblt_buffer(gdi_handle handle);
extern void gdi_2d_rotate(U8 rotate_value);
extern gdi_result gdi_2d_draw_font_v3(
                MMI_BOOL is_border,
                gdi_color fg_color,
                gdi_color bg_color,
                MMI_BOOL is_tilt,                    
                const S32 *tilt_table, 
                U32 tilt_table_size,
                const U8 *font_addr, 
                U32 font_data_size,
                U32 bit_offset,
                S32 x, 
                S32 y, 
                U32 font_width, 
                U32 font_height);
extern gdi_result gdi_2d_draw_AA_font(
                   MMI_BOOL is_border,
                   gdi_color fg_color,
                   gdi_color bg_color,
                   gdi_handle src_layer_handle,
                   const U8 *font_addr,
                   U32 font_data_size,
                   U32 bit_offset,
                   S32 x,
                   S32 y,
                   U32 font_width,
                   U32 font_height);
extern gdi_result gdi_2d_set_src_bitblt_rect(
             S32 x,
             S32 y,
             S32 width,
             S32 height);
extern void gdi_2d_set_dest_bitblt_rect(
             S32 x,
             S32 y,
             S32 width,
             S32 height);
#endif /* defined(GDI_USING_2D_ENGINE_V3) */

extern void gdi_2d_engine_init(void);

extern gdi_result gdi_2d_linear_transfrom(
                    float *matrix, 
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

extern gdi_result gdi_2d_linear_transfrom_fill_color(
            float *matrix,
            gdi_lt_fill_color_src_struct *src_info,
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


extern kal_bool gdi_2d_linear_transform_hw_support(void);
extern void gdi_2d_linear_transform_wait_for_finish(void);

extern kal_bool gdi_2d_query_hw_capability(GDI_G2D_CAPABILITY_ENUM capability);

/*****************************************************************************
 * FUNCTION
 *  gdi_2d_LT_nb_release_handle
 * DESCRIPTION
 *  Release g2d linear transform handle.
 *  Be aware that this function will be called by GDI task(with high priority).
 *  Work in this function should be short.
 * PARAMETERS
 *  matrix      [IN]  transform matrix, gdi 
 * RETURNS
 *  gdi_result
 *****************************************************************************/
extern void gdi_2d_LT_nb_release_g2d_handle(void);

/*****************************************************************************
 * FUNCTION
 *  gdi_2d_LT_wait_for_current_finish
 * DESCRIPTION
 *  Thread will be block on this function to wait for current linear transform finish.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void gdi_2d_LT_wait_for_current_finish(void);



/*****************************************************************************
 * [Fill rectangle]
 *
 *****************************************************************************/

typedef enum
{
    GDI_2D_FILL_FLAG_NON_BLOCKING = 0x1,
    GDI_2D_FILL_FLAG_ALPHA_BLENDING = 0x2,

    GDI_2D_FILL_FLAG_END_OF_ENUM
} gdi_2d_fill_flag_enum;

/* Bit combination of gdi_2d_fill_flag_enum */
typedef kal_uint32 gdi_2d_fill_flag_bitset;

extern GDI_RESULT gdi_2d_fill_rect(
            gdi_handle src_layer_handle,
            gdi_handle dest_layer_handle,
            kal_int32 x,
            kal_int32 y,
            kal_int32 width,
            kal_int32 height,
            kal_int32 color_alpha, /* 0 ~ 255; valid only if flag with ALPHA_BLENDING */
            gdi_color color_in_src_cf, /* Please get color from gdi_cf_get_color */
            gdi_2d_fill_flag_bitset flag,
            const gdi_callback_struct* nb_callback);

extern GDI_RESULT gdi_2d_fill_rect_to_act_layer(
            gdi_handle src_layer_handle,
            kal_int32 x,
            kal_int32 y,
            kal_int32 width,
            kal_int32 height,
            kal_int32 color_alpha, /* 0 ~ 255; valid only if flag with ALPHA_BLENDING */
            gdi_color color_in_src_cf, /* Please get color from gdi_cf_get_color */
            gdi_2d_fill_flag_bitset flag,
            const gdi_callback_struct* nb_callback);

extern void gdi_2d_fill_rect_wait_for_finish(void);

extern void gdi_2d_fill_rect_callback_ind_handler(void);

#endif /* __GDI_2D_ENGINE_H__ */

