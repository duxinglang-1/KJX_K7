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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_mav.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MAV image type 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMAGE_MAV_H__
#define __GDI_IMAGE_MAV_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "mav_decoder.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GDI_MAV_LOCK_MUTEX      gdi_mav_lock_mutex()
#define GDI_MAV_UNLOCK_MUTEX    gdi_mav_unlock_mutex()

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    MAV_DECODER_HANDLE *handle;     /* mav decoder handle pointer */
    MAV_DEC_STATUS status;          /* mav decode status */
    gdi_handle out_layer;           /* mav output layer handle */
    GDI_RESULT result;              /* mav decode result */
    BOOL *is_aborted;               /* mav abort flag */
    BOOL *is_timeout;               /* mav time out flag */
    JPEG_CODEC_TYPE_ENUM type;      /* decoder type of JPEG */
    JPEG_CODEC_STATE_ENUM decode_state;
} gdi_image_mav_decoder_struct;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void gdi_mav_lock_mutex(void);
extern void gdi_mav_unlock_mutex(void);

extern GDI_RESULT gdi_image_mav_draw_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);

extern GDI_RESULT gdi_image_mav_get_dimension_handler(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    S32 *width,
                    S32 *height);

extern GDI_RESULT gdi_image_is_mav_file(U8 *file_name);
extern GDI_RESULT gdi_image_is_mav_mem(U8 *data_ptr, U32 img_size);
extern void gdi_image_mav_init(void);
extern GDI_RESULT gdi_image_mav_get_pos_info_handler(
                   U32 flag,
                   U8 *data_ptr,
                   U32 img_size,
                   BOOL quick_mode,
                   S32 *total_pos,
                   gdi_anim_pos_type_enum *pos_type);

extern GDI_RESULT gdi_imgdec_mav_draw_internal(
                   gdi_handle output_layer_handle,
                   S32 ox,
                   S32 oy,
                   S32 resized_width,
                   S32 resized_height,
                   U32 frame_pos,
                   U8 *src,
                   U32 size,
                   BOOL *is_aborted,
                   U32 flag,
                   S32 aspect_flag);

#endif /* __GDI_IMAGE_MAV_H__ */

