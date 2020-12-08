/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAL_DRV_FEATURES_H__
#define __CAL_DRV_FEATURES_H__

#include "isp_hw_feature_def.h"
#include "drv_sw_features_jpeg.h"

#define __CAL_PROFILING_ENABLE__
#define __CAL_TRACE_ENABLE__
#undef __CAL_DUAL_CAMERA_SUPPORT__
#undef __CAL_CAMERA_OVERLAY_SUPPORT__
#undef __CAL_CAMERA_AF_SUPPORT__
#undef __CAL_CAMERA_LENS_SUPPORT__
#undef __CAL_HW_JPEG_ENCODE_SUPPORT__
#undef __CAL_CAMERA_RAW_SENSOR_SUPPORT__
#undef __CAL_CAMERA_CCT_SUPPORT__
#undef __CAL_CAMERA_BINNING_SUPPORT__
#undef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
#undef __CAL_NEED_SW_ROTATE__
#undef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
#undef __CAL_MATV_SUPPORT__
#undef __CAL_NVRAM_NEED_READ__
#undef __CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__
#undef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#undef __CAL_IMAGE_ROTATE_SUPPORT__
#define __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
#define __CAL_IMAGE_RESIZE_RGB_SUPPORT__
#define __CAL_IMAGE_ROTATE_RGB_SUPPORT__
#define __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
#define __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
#undef __CAL_MINIMIZE_GLOBAL_VARIABLE__
#undef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
#undef __CAL_STILL_CAPTURE_ROTATE_SUPPORT__
#undef __CAL_QUICK_VIEW_IMAGE_ROTATE_SUPPORT__
#define __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
#undef __CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__
#undef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
#undef __CAL_IMAGE_ROTATE_ONLY_UYVY422_SUPPORT__  // ????

#if defined(USE_UYVY422_BETWEEN_MDP_LCD)
#define __CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__
#endif

#if (defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260))
    #undef __CAL_PROFILING_ENABLE__
    #undef __CAL_TRACE_ENABLE__
    #undef __CAL_IMAGE_RESIZE_RGB_SUPPORT__
    #undef __CAL_IMAGE_ROTATE_RGB_SUPPORT__
    #undef __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
    #undef __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
    #define __CAL_MINIMIZE_GLOBAL_VARIABLE__
    #undef __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
    #define __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
    #define __CAL_IMAGE_ROTATE_ONLY_UYVY422_SUPPORT__
#endif

#if (defined(MT6253))
    #undef __CAL_PROFILING_ENABLE__
    #undef __CAL_TRACE_ENABLE__
    #undef __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
    #undef __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
    #define __CAL_MINIMIZE_GLOBAL_VARIABLE__
#endif

#ifdef DUAL_CAMERA_SUPPORT
    #define __CAL_DUAL_CAMERA_SUPPORT__
#endif

#ifdef __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__
    #define __CAL_CAMERA_OVERLAY_SUPPORT__
#endif

#ifdef AF_SUPPORT
    #define __CAL_CAMERA_AF_SUPPORT__
    #ifdef RAW_MAIN_CAMERA
        #define __CAL_CAMERA_LENS_SUPPORT__
    #endif
#endif

#ifdef __JPEG_ENC_HW_SUPPORTED__
    #define __CAL_HW_JPEG_ENCODE_SUPPORT__
#endif

#if (defined(MT6255))
    #define __CAL_QUICKVIEW_THUMBNAIL_HW_SUPPORT_ON_SW_JPEG_ENCODE__	
#endif

#ifdef RAW_MAIN_CAMERA
    #define __CAL_CAMERA_RAW_SENSOR_SUPPORT__
    #define __CAL_CAMERA_CCT_SUPPORT__
    #define __CAL_CAMERA_BINNING_SUPPORT__
#endif

#if (defined(MT6236) || defined(MT6236B))
    #define __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
#endif

#if ((defined(__FACE_DETECTION_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__)) && defined(MT6235))
    #define __CAL_NEED_SW_ROTATE__
#endif

#ifdef __ATV_SUPPORT__
    #define __CAL_MATV_SUPPORT__
#endif

#if (defined(MT6235)||defined(MT6236)||defined(MT6268)||defined(MT6276)||defined(MT6256)||defined(MT6255)||defined(__CAL_MATV_SUPPORT__))
    #define __CAL_GET_PREVIEW_IMAGE_SUPPORT__
#endif
#ifndef __LOW_COST_SUPPORT_ULC__
    #define __CAL_GET_PREVIEW_IMAGE_SUPPORT__
#endif

#ifndef __CAMERA_NVRAM_REDUCTION__
    #define __CAL_NVRAM_NEED_READ__
#endif

#define __CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__

#if (defined(MT6252)||defined(MT6252H)||defined(MT6253)||defined(MT6250)||defined(MT6260))
    #undef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#else
    #define __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#endif

#if (defined(__CAL_NEED_SW_ROTATE__)||defined(__CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__)||defined(__CAL_CAMERA_VIDEO_ROTATE_SUPPORT__))
    #define __CAL_IMAGE_ROTATE_SUPPORT__
#endif

#if (defined(MT6256) && defined(__MJPEG_ENC_SUPPORT__))
    #define __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
#endif

#if ((defined(MT6276)||defined(MT6256)||defined(MT6255)) && (defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)))
    #define __CAL_STILL_CAPTURE_ROTATE_SUPPORT__
#endif

#define __CAL_QUICK_VIEW_IMAGE_ROTATE_SUPPORT__

// 50 or 60 with Low cost support common will not support raw data (MRE get YUV for barcode)
#if (!((defined(MT6250) || defined(MT6260)) && defined(__LOW_COST_SUPPORT_COMMON__)))
   #define __CAL_CAPTURE_RAW_DATA_SUPPORT__
#endif

#endif /* __CAL_DRV_FEATURES_H__ */

