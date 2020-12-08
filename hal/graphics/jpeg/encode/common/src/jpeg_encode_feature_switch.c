/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_encode_function.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/// check options
#include "drv_features_jpeg.h"

#include "swje_structure.h"
#include "swje_sw_resize_r2y_888.h"
#include "swje_sw_resize_r2y_565.h"
#include "swje_sw_resize_uyvy_yuv.h"
#include "swje_sw_resize_yuv.h"
#include "swje_sw_rotate.h"

const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_csc_no_resize_no_pad_array[SWJE_FRAG_PROC_SRC_RGB_FORMAT_TOTAL_NUMBER][SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   {
      swje_frag_proc_func_rgb565_to_yuv420_csc_no_resize_no_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_rgb565_to_yuv422_csc_no_resize_no_pad
      #else
         NULL
      #endif
   },
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888)
   {
      swje_frag_proc_func_rgb888_to_yuv420_csc_no_resize_no_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_rgb888_to_yuv422_csc_no_resize_no_pad
      #else
         NULL
      #endif
   },
   #else
   {
      NULL,
      NULL
   },
   #endif
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_BGR888)
   {
      swje_frag_proc_func_bgr888_to_yuv420_csc_no_resize_no_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_bgr888_to_yuv422_csc_no_resize_no_pad
      #else
         NULL
      #endif
   },
   #else
   {
      NULL,
      NULL
   },
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_csc_no_resize_pad_array[SWJE_FRAG_PROC_SRC_RGB_FORMAT_TOTAL_NUMBER][SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   {
      swje_frag_proc_func_rgb565_to_yuv420_csc_no_resize_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_rgb565_to_yuv422_csc_no_resize_pad
      #else
         NULL
      #endif
   },
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888)
   {
      swje_frag_proc_func_rgb888_to_yuv420_csc_no_resize_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_rgb888_to_yuv422_csc_no_resize_pad
      #else
         NULL
      #endif
   },
   #else
   {
      NULL,
      NULL
   },
   #endif
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_BGR888)
   {
      swje_frag_proc_func_bgr888_to_yuv420_csc_no_resize_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_bgr888_to_yuv422_csc_no_resize_pad
      #else
         NULL
      #endif
   },
   #else
   {
      NULL,
      NULL
   },
   #endif
};


const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_csc_resize_pad_array[SWJE_FRAG_PROC_SRC_RGB_FORMAT_TOTAL_NUMBER][SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
      {
         swje_frag_proc_func_rgb565_to_yuv420_csc_resize_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_rgb565_to_yuv422_csc_resize_pad
         #else
            NULL
         #endif
      },
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888)
      {
         swje_frag_proc_func_rgb888_to_yuv420_csc_resize_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_rgb888_to_yuv422_csc_resize_pad
         #else
            NULL
         #endif
      },
      #else
      {
         NULL,
         NULL
      },
      #endif
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_BGR888)
      {
         swje_frag_proc_func_bgr888_to_yuv420_csc_resize_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_bgr888_to_yuv422_csc_resize_pad
         #else
            NULL
         #endif
      },
      #else
      {
         NULL,
         NULL
      },
      #endif
   #else
   {
      NULL,
      NULL
   },
   {
      NULL,
      NULL
   },
   {
      NULL,
      NULL
   },
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_csc_resize_no_pad_array[SWJE_FRAG_PROC_SRC_RGB_FORMAT_TOTAL_NUMBER][SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
      {
         swje_frag_proc_func_rgb565_to_yuv420_csc_resize_no_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_rgb565_to_yuv422_csc_resize_no_pad
         #else
            NULL
         #endif
      },
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888)
      {
         swje_frag_proc_func_rgb888_to_yuv420_csc_resize_no_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_rgb888_to_yuv422_csc_resize_no_pad
         #else
            NULL
         #endif
      },
      #else
      {
         NULL,
         NULL
      },
      #endif
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_BGR888)
      {
         swje_frag_proc_func_bgr888_to_yuv420_csc_resize_no_pad,
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
            swje_frag_proc_func_bgr888_to_yuv422_csc_resize_no_pad
         #else
            NULL
         #endif
      },
      #else
      {
         NULL,
         NULL
      },
      #endif
   #else
   {
      NULL,
      NULL
   },
   {
      NULL,
      NULL
   },
   {
      NULL,
      NULL
   },
   #endif
};


const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_no_csc_resize_no_pad_array[SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
      swje_frag_proc_func_yuv420_no_csc_resize_no_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_yuv422_no_csc_resize_no_pad
      #else
         NULL
      #endif
   #else
      NULL,
      NULL
   #endif      
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_no_csc_resize_pad_array[SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
      swje_frag_proc_func_yuv420_no_csc_resize_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_yuv422_no_csc_resize_pad
      #else
         NULL
      #endif
   #else
      NULL,
      NULL
   #endif   
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_no_csc_no_resize_pad_array[SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   swje_frag_proc_func_yuv420_no_csc_no_resize_pad,
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
      swje_frag_proc_func_yuv422_no_csc_no_resize_pad
   #else
      NULL
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_csc_no_resize_no_pad_array[SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
      swje_frag_proc_func_uyvy_to_yuv420_csc_no_resize_no_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_uyvy_to_yuv422_csc_no_resize_no_pad
      #else
         NULL
      #endif
   #else
      NULL,
      NULL
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_csc_no_resize_pad_array[SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER] =
{
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
      swje_frag_proc_func_uyvy_to_yuv420_csc_no_resize_pad,
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422)
         swje_frag_proc_func_uyvy_to_yuv422_csc_no_resize_pad
      #else
         NULL
      #endif
   #else
      NULL,
      NULL
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_yuv_rotate_array[SWJE_FRAG_PROC_ROTATE_ANGLE_TOTAL_NUMBER] =
{
   swje_frag_proc_func_rotate_000,
   
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
      swje_frag_proc_func_yuv_rotate_090,
      swje_frag_proc_func_yuv_rotate_270
   #else
      NULL,
      NULL
   #endif
};



const SWJE_FRAG_PROC_FUNC swje_frag_proc_func_rgb_rotate_array[SWJE_FRAG_PROC_ROTATE_ANGLE_TOTAL_NUMBER] =
{
   swje_frag_proc_func_rotate_000,
   
   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
      swje_frag_proc_func_rgb_rotate_090,
      swje_frag_proc_func_rgb_rotate_270
   #else
      NULL,
      NULL
   #endif
};
