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
 *  gui_image.h
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
#ifndef __GUI_IMAGE_H__
#define __GUI_IMAGE_H__

/*****************************************************************************
 * include
 ****************************************************************************/
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "Gui_Setting.h"
#include "gui_typedef.h"

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * Define
 ****************************************************************************/
#define MMI_IMAGE_COMPONENT_BUF_SIZE ((MAIN_LCD_DEVICE_HEIGHT * MAIN_LCD_DEVICE_WIDTH * GDI_MAINLCD_BIT_PER_PIXEL)>>3)

#define GUI_IMAGE_ANIM_RESUME_DISABLE   0xffffffff


/*****************************************************************************
 * Typedef
 ****************************************************************************/
typedef struct
{
    gui_image_align_enum image_h_align_type;
    gui_image_align_enum image_v_align_type;

    /* position and dimension of image component */
    S32 x, y;
    S32 width, height;

    /* logic position of the image */
    S32 image_display_x, image_display_y;
    /* the display dimension of the image, it will changed when some attribute 
     * be set, such as enable_stretch
     */
    S32 image_display_width, image_display_height;
    /* the dimension of image, it is read from image data */
    S32 image_width, image_height;

    /* some attribute of image component */
    U32 flags;

    /* the handle of image's target layer */
    GDI_HANDLE target_layer;
    /* the handle get from show anim APIs, which will be used when stop anim */
    GDI_HANDLE image_handle;

    /* buffer that record image data */
    PU8 image_buffer;
    U32 buffer_size;
    
    /* memory pointer, the memory used for save anim's N frame's content */
    PU8 anim_layer_ptr;
    gdi_handle anim_layer_handle;
    
    /* hide func of the image */
    void (*hide_callback) (S32 x1, S32 y1, S32 x2, S32 y2);

    /* the start frame of the anim */
    U32 start_frame;
    /* pause frame of the anim */
    U32 pause_frame;
    /* count of the anim */
    S32 frame_count;
    /* image is from file or resource or memory */
    gdi_image_src_enum image_scr;
    /* image type, for GDI */
    U16 image_type;    
    /* whether this component is in using */
    MMI_BOOL active;
    /* whether to stretch image to fill image component */
    MMI_BOOL enable_stretch;
    /* the handle of paused anim */
    GDI_HANDLE paused_handle;

    /* whether to show an anim in non blocking */
    MMI_BOOL is_non_blocking;
} gui_image_struct;

/*****************************************************************************
 * Global Function
 ****************************************************************************/
extern GDI_RESULT gui_image_create_from_file(
                   gui_image_struct *image,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 file_name,
                   U32 flags,
                   gdi_handle target_layer);
extern GDI_RESULT gui_image_create_from_res(
                   gui_image_struct *image,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 image_res,
                   U32 flags,
                   gdi_handle target_layer);
extern GDI_RESULT gui_image_create_from_mem(
                   gui_image_struct *image,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   U32 image_type,
                   const PU8 image_data,
                   U32 flags,
                   gdi_handle target_layer);
extern void gui_image_close(gui_image_struct *image);
extern void gui_image_move(gui_image_struct *image, S32 x, S32 y);
extern void gui_image_resize(gui_image_struct *image, S32 width, S32 height);
extern GDI_RESULT gui_image_show(gui_image_struct *image);
extern void gui_image_pause(gui_image_struct *image);
extern GDI_RESULT gui_image_resume(gui_image_struct *image);
extern GDI_RESULT gui_image_set_image_from_file(
                   gui_image_struct *image,
                   const PU8 file_name);
extern GDI_RESULT gui_image_set_image_from_res(
                   gui_image_struct *image,
                   const PU8 image_res);
extern GDI_RESULT gui_image_set_image_from_mem(
                   gui_image_struct *image,
                   U32 image_type,
                   const PU8 image_data);
extern void gui_image_register_hide_function(
             gui_image_struct *image,
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_image_set_layer(gui_image_struct *image, gdi_handle target_layer);
extern void gui_image_set_anim_start_frame(gui_image_struct *image, U32 start_frame);
extern void gui_image_set_stretch_enable(
             gui_image_struct *image,
             MMI_BOOL enable_stretch);
extern void gui_image_set_align(
             gui_image_struct *image,
             gui_image_align_enum image_h_align_type,
             gui_image_align_enum image_v_align_type);
extern void gui_image_get_layer(gui_image_struct *image, gdi_handle *target_layer);
extern void gui_image_get_position(gui_image_struct *image, S32 *x, S32 *y);
extern void gui_image_get_dimension(
             gui_image_struct *image,
             S32 *width,
             S32 *height,
             S32 *display_width,
             S32 *display_height);
extern void gui_image_get_anim_start_frame(gui_image_struct *image, U32 *start_frame);
extern GDI_RESULT gui_image_show_nb(
                   gui_image_struct *image,
                   void (*decode_done_callback)(GDI_RESULT result, GDI_HANDLE handle));
extern GDI_RESULT gui_image_stop_nb_show(gui_image_struct *image);

/* DOM-NOT_FOR_SDK-END */

#endif /* __GUI_IMAGE_H__ */ 

