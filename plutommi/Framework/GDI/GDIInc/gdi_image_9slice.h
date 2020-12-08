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
 *  gdi_image_9slice.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Alpha BitMap (ABM) external interface  
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
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMAGE_9SLICE_H__
#define __GDI_IMAGE_9SLICE_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#if defined(GDI_USING_DITHERING) && defined(__COSMOS_MMI__)
#define GDI_9SLICE_USING_DITHERING
#elif defined(__HW_G2D_DITHERING_SUPPORT__) && defined(__COSMOS_MMI__)
#define GDI_9SLICE_USING_DITHERING
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    GDI_IMAGE_9SLICE_FILL_MODE_STRETCH,
    GDI_IMAGE_9SLICE_FILL_MODE_REPEAT,
    GDI_IMAGE_9SLICE_FILL_MODE_END
}gdi_image_9slice_fill_mode_enum;

typedef struct _gdi_image_9slice_cntx_struct
{
    gdi_handle src_layer;
    U8 *img_ptr;
    U32 img_size;
    U32 img_type;
    S32 img_w;
    S32 img_h;
    kal_bool do_alpha_blending;
    gdi_image_9slice_fill_mode_enum fill_mode;
    kal_bool do_dithering;
    kal_bool force_alpha_blending;
} gdi_image_9slice_cntx_struct;
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern GDI_RESULT gdi_image_9slice_draw_handler(
                    U32 flag, 
                    U32 frame_pos, 
                    S32 x, 
                    S32 y, 
                    S32 w, 
                    S32 h, 
                    U8 *data_ptr, 
                    U32 img_size);

extern GDI_RESULT gdi_image_9slice_get_dimension_handler(
                    U32 flag, 
                    U8 *data_ptr, 
                    U32 img_size, 
                    S32 *width, 
                    S32 *height);

extern GDI_RESULT gdi_image_is_9slice_file(U8 *file_name);

extern GDI_RESULT gdi_image_9slice_set_fill_mode(S32 fill_mode);

extern S32 gdi_image_9slice_get_fill_mode(void);

extern void gdi_image_9slice_handle_scrn_exit_proc();

#endif /* __GDI_IMAGE_9SLICE_H__ */

