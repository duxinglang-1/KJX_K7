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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  wgui_image.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Header
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_IMAGE_H__
#define __WGUI_IMAGE_H__

/*****************************************************************************
 * include
 ****************************************************************************/
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_typedef.h"

/*****************************************************************************
 * Define
 ****************************************************************************/
#define WGUI_IMAGE_MAX_COUNT    2

/* reason of creation fail */
#define WGUI_IMAGE_CREATE_NO_AVAILABLE_INDEX    -1
#define WGUI_IMAGE_CREATE_GDI_FAIL              -2
/*****************************************************************************
 * Typedef
 ****************************************************************************/


/*****************************************************************************
 * Global Function
 ****************************************************************************/
extern GDI_RESULT wgui_image_create_from_file(
                   S32 *image_index,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 file_name,
                   U32 flags,
                   gdi_handle target_layer);
extern GDI_RESULT wgui_image_create_from_res(
                   S32 *image_index,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 image_res,
                   U32 flags,
                   gdi_handle target_layer);
extern GDI_RESULT wgui_image_create_from_mem(
                   S32 *image_index,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   U32 image_type,
                   const PU8 image_mem,
                   U32 flags,
                   gdi_handle target_layer);
extern void wgui_image_close(S32 image_index);
extern void wgui_image_close_all(void);
extern void wgui_image_move(S32 image_index, S32 x, S32 y);
extern void wgui_image_resize(S32 image_index, S32 width, S32 height);
extern GDI_RESULT wgui_image_show(S32 image_index);
extern void wgui_image_pause(S32 image_index);
extern GDI_RESULT wgui_image_resume(S32 image_index);
extern GDI_RESULT wgui_image_set_image_from_mem(
                   S32 image_index,
                   U32 image_type,
                   const PU8 image_data);
extern GDI_RESULT wgui_image_set_image_from_res(
                   S32 image_index,
                   const PU8 image_res);
extern GDI_RESULT wgui_image_set_image_from_file(
                   S32 image_index,
                   const PU8 file_name);
extern void wgui_image_register_hide_function(
             S32 image_index,
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void wgui_image_set_layer(S32 image_index, gdi_handle target_layer);
extern void wgui_image_set_anim_start_frame(S32 image_index, U32 start_frame);
extern void wgui_image_set_stretch_enable(S32 image_index, MMI_BOOL enable_stretch);
extern void wgui_image_set_align(
             S32 image_index, 
             gui_image_align_enum image_h_align_type,
             gui_image_align_enum text_v_align_type);
extern void wgui_image_get_layer(S32 image_index, gdi_handle *target_layer);
extern void wgui_image_get_position(S32 image_index, S32 *x, S32 *y);
extern void wgui_image_get_dimension(
             S32 image_index,
             S32 *width,
             S32 *height,
             S32 *display_width,
             S32 *display_height);
extern void wgui_image_get_anim_start_frame(S32 image_index, U32 *start_frame);
extern GDI_RESULT wgui_image_show_nb(
                   S32 image_index,
                   void (*decode_done_callback)(GDI_RESULT result, GDI_HANDLE handle));
extern GDI_RESULT wgui_image_stop_nb_show(S32 image_index);
#endif /* __WGUI_IMAGE_H__ */



