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
 *  gdi_imgdec_gif.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC GIF decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "drm_gprot.h"

#include "gdi_internal.h"


#include "med_utility.h"

#include "gdi_imgdec_internal.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_gif.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "setjmp.h"
#include "lcd_if.h"
#include "string.h"
#include "med_smalloc.h"
#include "MMIDataType.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"

#include "gdi_datatype.h"
#include "gdi_image_gif.h"
#include "gdi_bytestream.h"
#include "gdi_primitive.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_animate.h"
#include "gdi_layer.h"



/****************************************************************************
* Variable ( will extern )
*****************************************************************************/

/*
 * NOTICE: to make a region ARM9 D-cacheable, it must comply with some rules.
 * If we make other variables D-cacheable without checking these rules, 
 * it may have potential issues.
 * 
 * The current implementation also uses gdi_gif_local_palette[], gdi_gif_stack[] and GDI_TREE_BUFFER[] as HW GIF buffer.
 * However, since MT623X does not have HW GIF decoder, the check is redundant.
 */

/****************************************************************************
* Local Variable
*****************************************************************************/

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
 
/***************************************************************************** 
 * Global Function
 *****************************************************************************/
 


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_gif_draw_handler
 * DESCRIPTION
 *  IMGDEC GIF draw handler
 * PARAMETERS
 *  out_layer        [IN]   output layer
 *  frame_pos        [IN]   frame index
 *  x                [IN]   x
 *  y                [IN]   y
 *  w                [IN]   width
 *  h                [IN]   height
 *  data_ptr         [IN]   image pointer
 *  img_size         [IN]   image size
 *  is_aborted       [IN]   aborted flag
 *  flag             [IN]   flag
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_gif_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 frame_number = (U16) frame_pos;
    GDI_RESULT result = GDI_FAILED;
	gdi_layer_struct *temp_layer;
	gdi_lcd_layer_struct *layer_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE;
    temp_layer = (gdi_layer_struct*)out_layer;
    layer_info = &gdi_layer_info[temp_layer->id];
    
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        result = gdi_imgdec_gif_draw_internal(
                     out_layer,
                     x,
                     y,
                     w,
                     h,
                     data_ptr,
                     img_size,
                     frame_number,
                     (BOOL)1,
                     layer_info->source_key_enable,
                     layer_info->source_key,
                     is_aborted,
                     flag,
                     aspect_flag);
    }
    else
    {
        result = gdi_imgdec_gif_draw_internal(
                     out_layer,
                     x,
                     y,
                     w,
                     h,
                     data_ptr,
                     img_size,
                     frame_number,
                     (BOOL)0,
                     layer_info->source_key_enable,
                     layer_info->source_key,
                     is_aborted,
                     flag,
                     aspect_flag);
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_gif_get_dimension
 * DESCRIPTION
 *  Gets GIF dimension.
 * PARAMETERS
 *  src          [IN]   image source pointer
 *  size         [IN]   image size
 *  width        [OUT]  width
 *  height       [OUT]  height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_gif_get_dimension(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    gdi_imgdec_bytestream_struct bs;

    U32 header;
    S32 img_width, img_height;
    
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = GDI_SUCCEED;
    img_width = 0;
    img_height = 0;

    gdi_imgdec_bytestream_init(&bs, src, size);

    do
    {
        header = 0;
        gdi_imgdec_bytestream_read(&bs, &header, 3);
        
        if (header != 0x464947) /* 'GIF' */
        {
            ret = GDI_FAILED;
            
            break;
        }

        /*
         * read the GIF dimention 
         */
        gdi_imgdec_bytestream_seek(&bs, 3);     

        /* read file header */
        
        gdi_imgdec_bytestream_read(&bs, &img_width, 2);
        gdi_imgdec_bytestream_read(&bs, &img_height, 2);   
    } while (0);

    *width = img_width;
    *height = img_height;

    gdi_imgdec_bytestream_deinit(&bs);

    return ret;
}



