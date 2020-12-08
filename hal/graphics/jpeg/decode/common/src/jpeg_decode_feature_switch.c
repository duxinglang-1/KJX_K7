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
 *   jpeg_decode_feature_switch.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_jpeg.h"
#include "swjd_huffman_decoder.h"
#include "swjd_sw_resize_y2r_565.h"
#include "swjd_sw_resize_y2r_888.h"
#include "swjd_sw_resize_y2r_8888.h"
#include "swjd_sw_resize_y2r_6666.h"
#include "swjd_sw_resize_y2y_420.h"
#include "swjd_sw_resize_y2y_422.h"
#include "swjd_post_itpl.h"

const HUFFMAN_DEC_FUNC _huffman_decode_func_array[4] =
{
   huffmanDecDecodeOneMCU,

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
   huffmanDecDecodeACFirst,
   huffmanDecDecodeDCRefine,
   huffmanDecDecodeACRefine
#else
   NULL,
   NULL,
   NULL
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
};


const FRAG_PROC_FUNC _frag_proc_func_rgb565_array[2][6] =
{
   {
      _frag_proc_func_yuv4xx_to_rgb565_no_resize,  /// for 400
      _frag_proc_func_yuv4xx_to_rgb565_no_resize,  /// for 444
      _frag_proc_func_yuv4xx_to_rgb565_no_resize,  /// for 422
      _frag_proc_func_yuv4xx_to_rgb565_no_resize,  /// for 422V
      _frag_proc_func_yuv4xx_to_rgb565_no_resize,  /// for 420
      _frag_proc_func_yuv4xx_to_rgb565_no_resize   /// for 411
   },
   {
      _frag_proc_func_yuv4xx_to_rgb565_bilinear,   /// for 400
      _frag_proc_func_yuv4xx_to_rgb565_bilinear,   /// for 444
      _frag_proc_func_yuv4xx_to_rgb565_bilinear,   /// for 422
      _frag_proc_func_yuv4xx_to_rgb565_bilinear,   /// for 422V
      _frag_proc_func_yuv4xx_to_rgb565_bilinear,   /// for 420
      _frag_proc_func_yuv4xx_to_rgb565_bilinear    /// for 411
   }
};


const FRAG_PROC_FUNC _frag_proc_func_argb8888_array[2][6] =
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888)
   {
      _frag_proc_func_yuv4xx_to_argb8888_no_resize,   /// for 400
      _frag_proc_func_yuv4xx_to_argb8888_no_resize,   /// for 444
      _frag_proc_func_yuv4xx_to_argb8888_no_resize,   /// for 422
      _frag_proc_func_yuv4xx_to_argb8888_no_resize,   /// for 422V
      _frag_proc_func_yuv4xx_to_argb8888_no_resize,   /// for 420
      _frag_proc_func_yuv4xx_to_argb8888_no_resize    /// for 411
   },
   {
      _frag_proc_func_yuv4xx_to_argb8888_bilinear,    /// for 400
      _frag_proc_func_yuv4xx_to_argb8888_bilinear,    /// for 444
      _frag_proc_func_yuv4xx_to_argb8888_bilinear,    /// for 422
      _frag_proc_func_yuv4xx_to_argb8888_bilinear,    /// for 422V
      _frag_proc_func_yuv4xx_to_argb8888_bilinear,    /// for 420
      _frag_proc_func_yuv4xx_to_argb8888_bilinear     /// for 411
   }
#else
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   },
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888
};


const FRAG_PROC_FUNC _frag_proc_func_argb6666_array[2][6] =
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666)
   {
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for y only
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for yuv444
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for yuv422
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for yuv422v
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for yuv420
      _frag_proc_func_yuv4xx_to_argb6666_no_resize,  /// for yuv411
   },
   {
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for y only
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for yuv444
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for yuv422
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for yuv422v
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for yuv420
      _frag_proc_func_yuv4xx_to_argb6666_bilinear,   /// for yuv411
   }
#else
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   },
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666
};


const FRAG_PROC_FUNC _frag_proc_func_rgb888_array[2][6] =
{
#if (defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888) || defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888))
   {
      _frag_proc_func_yuv4xx_to_rgb888_no_resize,  /// for 400
      _frag_proc_func_yuv4xx_to_rgb888_no_resize,  /// for 444
      _frag_proc_func_yuv4xx_to_rgb888_no_resize,  /// for 422
      _frag_proc_func_yuv4xx_to_rgb888_no_resize,  /// for 422V
      _frag_proc_func_yuv4xx_to_rgb888_no_resize,  /// for 420
      _frag_proc_func_yuv4xx_to_rgb888_no_resize   /// for 411
   },
   {
      _frag_proc_func_yuv4xx_to_rgb888_bilinear,   /// for 400
      _frag_proc_func_yuv4xx_to_rgb888_bilinear,   /// for 444
      _frag_proc_func_yuv4xx_to_rgb888_bilinear,   /// for 422
      _frag_proc_func_yuv4xx_to_rgb888_bilinear,   /// for 422V
      _frag_proc_func_yuv4xx_to_rgb888_bilinear,   /// for 420
      _frag_proc_func_yuv4xx_to_rgb888_bilinear    /// for 411
   }
#else
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   },
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888 || SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888
};


const FRAG_PROC_FUNC _frag_proc_func_yuv420_array[2][6] =
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420)
   {
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 400
      _frag_proc_func_yuv444_to_yuv420_no_resize,  /// for 444
      _frag_proc_func_yuv422_to_yuv420_no_resize,  /// for 422
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 422v
      _frag_proc_func_yuv420_to_yuv420_no_resize,  /// for 420
      _frag_proc_func_yuv4xx_to_yuv420_nearest     /// for 411
   },
   {
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 400
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 444
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 422
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 422v
      _frag_proc_func_yuv4xx_to_yuv420_nearest,    /// for 420
      _frag_proc_func_yuv4xx_to_yuv420_nearest     /// for 411
   }
#else
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   },
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420
};


const FRAG_PROC_FUNC _frag_proc_func_uyvy422_array[2][6] =
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422)
   {
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 400
      _frag_proc_func_yuv444_to_uyvy422_no_resize, /// for 444
      _frag_proc_func_yuv422_to_uyvy422_no_resize, /// for 422
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 422v
      _frag_proc_func_yuv420_to_uyvy422_no_resize, /// for 420
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear   /// for 411
   },
   {
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 400
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 444
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 422
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 422v
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear,  /// for 420
      _frag_proc_func_yuv4xx_to_uyvy422_bilinear   /// for 411
   }
#else
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   },
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422
};


const POST_ITPL_FUNC _post_itpl_func_rgb565_array[2] = 
{
   _post_itpl_func_rgb565_horizontal, _post_itpl_func_rgb565_vertical
};


const POST_ITPL_FUNC _post_itpl_func_argb8888_array[2] = 
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888)
   _post_itpl_func_argb8888_horizontal, _post_itpl_func_argb8888_vertical
#else
   NULL, NULL
#endif
};


const POST_ITPL_FUNC _post_itpl_func_argb6666_array[2] = 
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666)
   _post_itpl_func_argb6666_horizontal, _post_itpl_func_argb6666_vertical
#else
   NULL, NULL
#endif
};


const POST_ITPL_FUNC _post_itpl_func_uyvy422_array[2] = 
{
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422)
   _post_itpl_func_uyvy422_horizontal, _post_itpl_func_uyvy422_vertical
#else
   NULL, NULL
#endif
};


const POST_ITPL_FUNC _post_itpl_func_rgb888_array[2] = 
{
#if (defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888) || defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888))
   _post_itpl_func_rgb888_horizontal, _post_itpl_func_rgb888_vertical
#else
   NULL, NULL
#endif
};
