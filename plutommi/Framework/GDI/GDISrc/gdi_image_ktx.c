/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_ktx.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  KTX image type 
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_internal.h"
#include "gdi_image.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_mutex.h"
#include "gd_include.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "MMIDataType.h"

#include "med_utility.h"
#include "med_smalloc.h"

#include "drm_gprot.h"
#if defined(__MMI_VUI_ENGINE__)

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
// TODO: remove this
U8 debug_ktx = 0;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_draw_mem
 * DESCRIPTION
 *  draw ktx image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_draw_mem(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *data_ptr, 
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_draw_file
 * DESCRIPTION
 *  draw ktx image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_draw_file(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *file_name)
{
    return GDI_SUCCEED;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_draw_handler
 * DESCRIPTION
 *  draw ktx image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_draw_handler(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *data_ptr, 
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        ret = gdi_image_ktx_draw_file(
                flag, 
                frame_pos, 
                x, 
                y, 
                w, 
                h, 
                data_ptr);
    }
    else
    {   
        if (debug_ktx==1)
        {
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (PS8)L"E:\\ktx_act_01_before.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (PS8)L"D:\\ktx_act_01_before.bmp");
            #endif
        }
        ret = gdi_image_ktx_draw_mem(
                flag, 
                frame_pos, 
                x, 
                y, 
                w, 
                h, 
                data_ptr, 
                img_size);
        if (debug_ktx==1)
        {
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (PS8)L"E:\\ktx_act_02_after.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (PS8)L"D:\\ktx_act_02_after.bmp");
            #endif
        }

    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_get_dimension_mem
 * DESCRIPTION
 *  get dimension of the ktx image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_get_dimension_mem(
            U32 flag, 
            U8 *data_ptr, 
            U32 img_size, 
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_size < 44)
    {
        return GDI_FAILED;
    }
    
    data_ptr += 36;
    *width = (data_ptr[3] << 24) | (data_ptr[2] << 16) | (data_ptr[1] << 8) | (data_ptr[0]);
    data_ptr += 4;
    *height = (data_ptr[3] << 24) | (data_ptr[2] << 16) | (data_ptr[1] << 8) | (data_ptr[0]);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_get_dimension_file
 * DESCRIPTION
 *  get dimension of the ktx image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_get_dimension_file(
            U32 flag, 
            U8 *file_name,
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE  file_handle = 0;
    U32        read_len = 0;
    U8         buf[44];
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* open file */
        file_handle = FS_Open((U16*)file_name, FS_READ_ONLY | FS_OPEN_NO_DIR);
        
        if (file_handle < 0)
        {
            ret = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
            break;
        }

        /* read data to buf for width and height from the file */
        if (FS_Read(file_handle, buf, 44, &read_len) != FS_NO_ERROR)
        {
            ret = GDI_IMAGE_ERR_INVALID_FILE;
            break;
        }

        ret = gdi_image_ktx_get_dimension_mem(
                flag, 
                buf, 
                read_len, 
                width, 
                height);
    }while(0);
    
    /* close file */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ktx_get_dimension_handler
 * DESCRIPTION
 *  get dimension of the ktx image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_ktx_get_dimension_handler(
            U32 flag, 
            U8 *data_ptr, 
            U32 img_size, 
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        ret = gdi_image_ktx_get_dimension_file(
                flag, 
                data_ptr,
                width, 
                height);
    }
    else
    {
        ret = gdi_image_ktx_get_dimension_mem(
                flag, 
                data_ptr, 
                img_size, 
                width, 
                height);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_ktx_file
 * DESCRIPTION
 *  is ktx image file
 * PARAMETERS
 *  file_name           [IN]     file name
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_is_ktx_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buf[12];
    U32 i;
    U32 result;
    FS_HANDLE handle;

    U8 ktx_header[12] = {0xAB, 'K', 'T', 'X', ' ', '1', '1', 0xBB, '\r', '\n', '\x1A', '\n'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(
                 (U16*)file_name,
                 FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
                 DRM_PERMISSION_DISPLAY);

    if (handle < 0) return GDI_IMAGE_ERR_INVALID_FILE;

    result = DRM_read_file(handle, buf, 12, &i);

    DRM_close_file(handle);

    if ((result == FS_NO_ERROR) && (i == 12))
    {
        for(i = 0 ; i < 12 ; i++)
        {
            if (buf[i] != ktx_header[i])
            {
                return GDI_FAILED;
            }
        }
        return GDI_SUCCEED;
    }
    return GDI_FAILED;
}

#endif
