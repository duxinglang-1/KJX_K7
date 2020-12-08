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
 *  gdi_imgdec_bmp.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC BMP header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _GDI_IMGDEC_BMP_H_
#define _GDI_IMGDEC_BMP_H_

#include "gdi_imgdec.h"
#include "gdi_imgdec_internal.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_resizer.h"

typedef enum
{
    GDI_IMGDEC_BMP_DITHER_DISABLE,
    GDI_IMGDEC_BMP_DITHER_RGB565,
    GDI_IMGDEC_BMP_DITHER_RGB8882BITS,
    GDI_IMGDEC_BMP_DITHER_END_OF_ENUM
} gdi_imgdec_bmp_dithering_enum;

typedef struct
{
    GDI_IMGDEC_BASE_STRUCT

    gdi_imgdec_resizer_struct resizer;
    
    gdi_imgdec_bytestream_struct bs;
    U8 *bs_buf_ptr;
    U32 bs_buf_size;

    gdi_color *palette;
    U32 palette_size;
    BOOL compression;
    S32 width;
    S32 height;
    S32 src_x;
    S32 src_y;
    S32 run_length;
    S32 run_length_used;
    S32 run_length_odd;
    U8 code;
    BOOL is_raw_mode;
    BOOL is_from_file;
    gdi_imgdec_bmp_dithering_enum dither_mode;    
} gdi_imgdec_bmp_struct;


/****************************************************************************
* Function                                                               
*****************************************************************************/
extern void gdi_imgdec_bmp_init(gdi_imgdec_bmp_struct *dec, gdi_handle out_layer, void *bs_buf, U32 bs_buf_size, BOOL *is_aborted, U32 flag);
extern void gdi_imgdec_bmp_deinit(gdi_imgdec_bmp_struct *dec);
extern GDI_RESULT gdi_imgdec_bmp_draw_resized_file(
            gdi_imgdec_bmp_struct *dec,
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,            
            S32 resized_width,
            S32 resized_height,
            S8 *filename,
            U32 aspect_flag);
extern GDI_RESULT gdi_imgdec_bmp_draw_resized(
            gdi_imgdec_bmp_struct *dec,
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,
            S32 resized_width,
            S32 resized_height,
            U8 *BMP_src,
            U32 size,
            U32 aspect_flag);
extern GDI_RESULT gdi_imgdec_bmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_imgdec_bmp_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag);

#endif /* _GDI_IMGDEC_BMP_H_ */ 


