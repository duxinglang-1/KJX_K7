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
 * gdi_image_wbmp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  WBMP image decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMAGE_WBMP_H_
#define _GDI_IMAGE_WBMP_H_

#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

/***************************************************************************** 
* Function 
*****************************************************************************/
extern GDI_RESULT gdi_image_wbmp_draw_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT gdi_image_wbmp_get_dimension_handler(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    S32 *width,
                    S32 *height);
extern GDI_RESULT gdi_image_is_wbmp_file(U8 *file_name);

#define gdi_image_wbmp_draw( ox,  oy, WBMP_src,  size) \
    gdi_image_wbmp_draw_handler(0, 0, ox, oy, 0, 0, WBMP_src, size)

#define gdi_image_wbmp_draw_file( ox,  oy, filename) \
    gdi_image_wbmp_draw_handler(GDI_IMAGE_CODEC_FLAG_IS_FILE, 0, ox, oy, 0, 0,filename, 0)    

#define gdi_image_wbmp_draw_resized(ox, oy, resized_width, resized_height, WBMP_src, size) \
    gdi_image_wbmp_draw_handler(0, 0, ox, oy, resized_width, resized_height, WBMP_src, size)
    
#define gdi_image_wbmp_draw_resized_file( ox, oy, resized_width, resized_height, filename) \
    gdi_image_wbmp_draw_handler(GDI_IMAGE_CODEC_FLAG_IS_FILE, 0, ox, oy, resized_width, resized_height,filename, 0) 

#define gdi_image_wbmp_get_dimension(WBMP_src, width, height) \
    gdi_image_wbmp_get_dimension_handler(0, WBMP_src, 1, width, height) 
#define gdi_image_wbmp_get_dimension_file(filename, width, height) \
    gdi_image_wbmp_get_dimension_handler(GDI_IMAGE_CODEC_FLAG_IS_FILE, filename, 0, width, height) 


#endif /* _GDI_IMAGE_WBMP_H_ */ 


