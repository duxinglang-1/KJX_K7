/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vrt_draw_cmd_queue_gprot.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Venus Rendering Task exported interface of draw command queue
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_DRAW_CMD_QUEUE_GPROT_H__
#define __VRT_DRAW_CMD_QUEUE_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vrt_frame_gprot.h"
#include "vrt_datatype.h"
#include "vrt_system.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef vrt_u32 vrt_string_union;

/* draw command */
typedef struct 
{
    vrt_u32 draw_cmd_type    :11;       /* draw command type */
    vrt_u32 draw_cmd_size    :20;       /* draw command size */
    vrt_u32 do_pop           :1;        /* pop flag */
} vrt_draw_cmd_struct;


/* draw command queue by array */
typedef struct
{
    vrt_s32 block_count;                /* current total command queue count */
    vrt_s32 draw_cmd_count;             /* the total draw command count */
    vrt_s32 max_cmd_count;              /* current max command queue count */
    vrt_draw_cmd_struct **queue_list;   /* queue block array */
    vrt_draw_cmd_struct *queue_tail;    /* the first empty place to insert draw command */
} vrt_draw_cmd_queue_struct;

typedef struct
{
    vrt_u8 **data_buf_array;
    vrt_u8 *current_data_buf;
    vrt_u8 *pre_data_ptr;
    vrt_u8 *data_tail_ptr;
    vrt_u32 data_tail_index;
    vrt_s32 data_buf_count;
    vrt_s32 draw_cmd_count;
} vrt_canvas_draw_cmd_queue_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_u32 string_offset;
} vrt_draw_cmd_comment_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_frame_property_struct *active_properties;
    vrt_s32 frame_cmd_size;
    vrt_frame_handle frame;
    vrt_u32 jump_index           :16;
    vrt_u32 next_jump_index      :16;
} vrt_draw_cmd_push_and_set_active_frame_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_u8 *image_ptr;
    vrt_frame_content_placement_type_enum place_type;
} vrt_draw_cmd_draw_img_content_from_mem_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_res_id res_id;
    vrt_frame_content_placement_type_enum place_type;
} vrt_draw_cmd_draw_img_content_from_res_id_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_u32 filename_offset;
    vrt_frame_content_placement_type_enum place_type;
    vrt_sys_image_info_struct info;
} vrt_draw_cmd_draw_img_content_from_file_struct;


typedef struct
{
    vrt_draw_cmd_struct draw_cmd;
    vrt_s32 x, y, width;
    vrt_string_union string;
} vrt_draw_cmd_draw_text_struct;


typedef struct
{ 
    vrt_draw_cmd_struct draw_cmd;
    vrt_point_struct pos;
    vrt_string_union string;
    vrt_u32 stringLen;
} vrt_draw_cmd_draw_text_n_struct;


typedef struct
{ 
    vrt_draw_cmd_struct draw_cmd;
    vrt_rect_struct rect;
    vrt_s32 baseline;
    vrt_string_union string;
    vrt_s32 width;
    vrt_u32 stringLen;
} vrt_draw_cmd_draw_text_n_baseline_struct;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void *vrt_draw_cmd_queue_get_args(vrt_canvas_draw_cmd_queue_struct *queue, vrt_s32 index);

extern vrt_u32 vrt_draw_cmd_queue_get_tail_index(vrt_canvas_draw_cmd_queue_struct *queue);

#ifdef __cplusplus
}
#endif

#endif /* __VRT_DRAW_CMD_QUEUE_GPROT_H__ */

