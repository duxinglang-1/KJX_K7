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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   idp_cam_if.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   IDP-Camera HAL interface
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 11 2013 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 *
 * 06 19 2012 peter.wang
 * removed!
 * .
 *
 * 06 13 2012 peter.wang
 * removed!
 * .
 *
 * 06 01 2012 shouchun.liao
 * removed!
 * Check-in 3D Image/MAV/AutoRama/FSD for MT6250.
 *
 * 05 25 2012 peter.wang
 * removed!
 * .
 *
 * 04 16 2012 chrono.wu
 * removed!
 * .
 *
 * 03 15 2012 peter.wang
 * removed!
 * .
 *
 * 03 09 2012 chrono.wu
 * removed!
 * .
 *
 * 02 23 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 02 22 2012 chrono.wu
 * removed!
 * .
 *
 * 02 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 12 20 2011 chrono.wu
 * removed!
 * .
 *
 * 12 16 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 14 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 07 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 09 26 2011 chrono.wu
 * removed!
 * .
 *
 * 09 23 2011 chelun.tsai
 * removed!
 * .
 *
 * 09 21 2011 chrono.wu
 * removed!
 * .
 *
 * 08 24 2011 chrono.wu
 * removed!
 * .
 *
 * 08 19 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 26 2011 peter.wang
 * removed!
 * .
 *
 * 06 27 2011 peter.wang
 * removed!
 * .
 *
 * 06 17 2011 chrono.wu
 * removed!
 * .
 *
 * 05 09 2011 chrono.wu
 * removed!
 * .
 *
 * 04 27 2011 chrono.wu
 * removed!
 * .
 *
 * 03 24 2011 chrono.wu
 * removed!
 * .
 *
 * 03 04 2011 chrono.wu
 * removed!
 * .
 *
 * 01 28 2011 chrono.wu
 * removed!
 * .
 *
 * 01 27 2011 chrono.wu
 * removed!
 * .
 *
 * 01 21 2011 cm.huang
 * removed!
 * .
 *
 * 01 20 2011 chrono.wu
 * removed!
 * .
 *
 * 01 20 2011 cm.huang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "drv_sw_features_mdp.h"

#if defined(DRV_IDP_SUPPORT)
#include "mm_comm_def.h"
#include "cal_comm_def.h"
#include "idp_cam_if.h"

#include "idp_camera_preview.h"
#include "idp_camera_capture_to_jpeg.h"
#include "idp_video_encode.h"
#include "idp_camera_capture_to_mem.h"

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
#include "idp_mjpeg_encode.h"
#endif

//#include "idp_video_call_decode.h"

#if defined(__MEDIA_VT__)
/* under construction !*/
#endif

// EMI BW limitor...
#if defined(__MTK_TARGET__)
#include "emi_sw.h"
#endif // #if defined(__MTK_TARGET__)

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

MM_ERROR_CODE_ENUM (*pfIDP_CAL_CB)(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);


static MM_ERROR_CODE_ENUM Idp_Cal_Open(
        CAL_SCENARIO_ENUM eCalScenID,
        kal_uint32 * const key,
        char const * const filename,
        kal_uint32 const lineno)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_FALSE;

    switch(eCalScenID)
    {
      case CAL_SCENARIO_CAMERA_PREVIEW:
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
      case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
#endif
        result = idp_camera_preview_open_real(key, filename, lineno);
        break;
      case CAL_SCENARIO_VIDEO:
        result = idp_video_encode_open_real(key, filename, lineno);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        result = idp_camera_capture_to_jpeg_open_real(key, filename, lineno);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
        result = idp_camera_capture_to_jpeg_open_real(key, filename, lineno);
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
        result = idp_camera_capture_to_mem_open_real(key, filename, lineno);
#else
       Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;
#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
      case CAL_SCENARIO_VIDEO_MJPEG:
        result = idp_mjpeg_encode_open_real(key, filename, lineno);
        break;
#endif
      default:
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_MDP_BEGIN;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
}


static MM_ERROR_CODE_ENUM Idp_Cal_Close(
        CAL_SCENARIO_ENUM eCalScenID,
        kal_uint32 const key)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_FALSE;

    switch(eCalScenID)
    {
      case CAL_SCENARIO_CAMERA_PREVIEW:
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
      case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
      case CAL_SCENARIO_CAMERA_ZSD_CAPTURE:
#endif
        result = idp_camera_preview_close(key);
        break;
      case CAL_SCENARIO_VIDEO:
        result = idp_video_encode_close(key);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        result = idp_camera_capture_to_jpeg_close(key);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
        result = idp_camera_capture_to_jpeg_close(key);
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
        result = idp_camera_capture_to_mem_close(key);
#else
       Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;

#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
      case CAL_SCENARIO_VIDEO_MJPEG:
        result = idp_mjpeg_encode_close(key);
        break;
#endif
      default:
        break;
    }
    if (result == KAL_FALSE)
    // temp solution, need to modify error type to MM_ERROR_MDP_CLOSE
    {eRet = MM_ERROR_MDP_BEGIN;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
}


static MM_ERROR_CODE_ENUM Idp_Cal_Start(
        CAL_SCENARIO_ENUM eCalScenID,
        kal_uint32 const key)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_FALSE;

    switch(eCalScenID)
    {
      case CAL_SCENARIO_CAMERA_PREVIEW:
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
      case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
#endif
        result = idp_camera_preview_start_all(key);
        break;
      case CAL_SCENARIO_VIDEO:
        result = idp_video_encode_start_all(key);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        result = idp_camera_capture_to_jpeg_start_all(key);
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
        result = idp_camera_capture_to_jpeg_start_all(key);
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
        result = idp_camera_capture_to_mem_start_all(key);
#else
       Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;
#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
      case CAL_SCENARIO_VIDEO_MJPEG:
        result = idp_mjpeg_encode_start_all(key);
        break;
#endif
      default:
        break;
    }
    if (result == KAL_FALSE)
    // temp solution, need to modify error type to MM_ERROR_MDP_START
    {eRet = MM_ERROR_MDP_BEGIN;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
}


static MM_ERROR_CODE_ENUM Idp_Cal_Stop(
        CAL_SCENARIO_ENUM eCalScenID,
        kal_uint32 const key)
{
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
#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MM_ERROR_NONE;
}


static kal_bool Idp_Cal_Is_In_Use(
        CAL_SCENARIO_ENUM eCalScenID)
{
    kal_bool result;
    switch(eCalScenID)
    {
      case CAL_SCENARIO_CAMERA_PREVIEW:
        result = idp_camera_preview_is_in_use();
        break;
      case CAL_SCENARIO_VIDEO:
        result = idp_video_encode_is_in_use();
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        result = idp_camera_capture_to_jpeg_is_in_use();
        break;
      case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
        result = idp_camera_capture_to_jpeg_is_in_use();
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
        result = idp_camera_capture_to_mem_is_in_use();
#else
        Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;
#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
      case CAL_SCENARIO_VIDEO_MJPEG:
        result = idp_mjpeg_encode_is_in_use();
        break;
#endif
      default:
        result = KAL_FALSE;
        break;
    }

    return result;
}


static MM_ERROR_CODE_ENUM Idp_Cal_Camera_Preview_Set(
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_TRUE;
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
    kal_bool bCapturetojpeg = KAL_TRUE;
#endif

    switch(eSetType)
    {
      case IDP_CAL_SET_CONFIG:
        {
          Camera_Preview_Idp_Cal_Struct *prCamPrev;
          prCamPrev = (Camera_Preview_Idp_Cal_Struct*) pvParam;

          result &= idp_camera_preview_config(
            key,

#if (!defined(DRV_IDP_6252_SERIES))
            IDP_CAMERA_PREVIEW_EXTMEM_START_ADDRESS, prCamPrev->extmem_start_address,
            IDP_CAMERA_PREVIEW_EXTMEM_SIZE, prCamPrev->extmem_size,
#endif

            IDP_CAMERA_PREVIEW_IMAGE_SRC_WIDTH, prCamPrev->source_width,
            IDP_CAMERA_PREVIEW_IMAGE_SRC_HEIGHT, prCamPrev->source_height,
            IDP_CAMERA_PREVIEW_PREVIEW_WIDTH, prCamPrev->display_width,
            IDP_CAMERA_PREVIEW_PREVIEW_HEIGHT, prCamPrev->display_height,

#if (!defined(DRV_IDP_6252_SERIES))
            IDP_CAMERA_PREVIEW_ENABLE_PREVIEW_PITCH, prCamPrev->preview_pitch_enable,
            IDP_CAMERA_PREVIEW_PREVIEW_PITCH_WIDTH, prCamPrev->preview_pitch_width,

            IDP_CAMERA_PREVIEW_ENABLE_OVERLAY, prCamPrev->enable_overlay,
#endif
            IDP_CAMERA_PREVIEW_PREVIEW_IMAGE_COLOR_FORMAT, prCamPrev->preview_image_color_format,

            IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS, prCamPrev->frame_buffer_address1,
            IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS1, prCamPrev->frame_buffer_address2,
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS2, prCamPrev->frame_buffer_address3,
#endif

            IDP_CAMERA_PREVIEW_POSTPROC_PATH_ENABLE, prCamPrev->postproc_image_enable,

            IDP_CAMERA_PREVIEW_DISPLAY_ROT_ANGLE, prCamPrev->display_rot_angle,

            IDP_CAMERA_PREVIEW_ENABLE_TRIGGER_LCD, prCamPrev->lcd_update_enable,

#if defined(__MTK_TARGET__)
            //IDP_CAMERA_PREVIEW_RESIZER_U_VALUE, 8,
            //IDP_CAMERA_PREVIEW_RESIZER_D_VALUE, 15,
#endif

            IDP_CAMERA_PREVIEW_FRAME_START_HISR_CB_ENABLE, prCamPrev->digital_zoom_frame_start_hisr_cb_enable,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_ENABLE,   prCamPrev->mdp_crop_enable,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_WIDTH,    prCamPrev->cropped_width,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_HEIGHT,   prCamPrev->cropped_height,
            IDP_CAMERA_PREVIEW_ENABLE_DOUBLE_BUFFER_TEARING_FREE,   prCamPrev->dbuf_tearing_free_enable,
            //In general matv receive data in crz frame to mdp frame done(rotdma done). for example MT5192.
            //MT5193 changes the original design, it will receive data about 16~20ms before frame start.
            //So, in order to aovid LCD interference MATV, we will delay trigger display in next frame start.
            IDP_CAMERA_PREVIEW_ENABLE_TRIGGER_DISPLAY_DELAY_TO_FRAME_START, prCamPrev->trigger_display_delay_to_frame_start_enable,
            0);
          //ASSERT(KAL_TRUE == result);

          if(prCamPrev->postproc_image_enable == KAL_TRUE)
          {
            result &= idp_camera_preview_config(
              key,
              IDP_CAMERA_PREVIEW_POSTPROC_ROT_ANGLE, prCamPrev->postproc_image_rot_angle,
              IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_COLOR_FORMAT, prCamPrev->postproc_image_color_format,
              IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_WIDTH, prCamPrev->postproc_image_width,
              IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_HEIGHT, prCamPrev->postproc_image_height,
              IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_1, prCamPrev->postproc_image_buffer_address_1,
              IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_2, prCamPrev->postproc_image_buffer_address_2,
              IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_3, prCamPrev->postproc_image_buffer_address_3,
              IDP_CAMERA_PREVIEW_ENG_CONFIG, KAL_TRUE,
              0);
          }
#if (defined(DRV_IDP_6252_SERIES))
          else
          {
            result &= idp_camera_preview_config(
              key,
              IDP_CAMERA_PREVIEW_ENG_CONFIG, KAL_TRUE,
              0);
          }
#endif

#if (!defined(DRV_IDP_6252_SERIES))
          if (KAL_TRUE == prCamPrev->enable_overlay)
          {
            result &= idp_camera_preview_config(
              key,
              IDP_CAMERA_PREVIEW_OVERLAY_FRAME_SOURCE_KEY, prCamPrev->overlay_frame_source_key,
              IDP_CAMERA_PREVIEW_OVERLAY_FRAME_WIDTH, prCamPrev->overlay_frame_width,
              IDP_CAMERA_PREVIEW_OVERLAY_FRAME_HEIGHT, prCamPrev->overlay_frame_height,
              IDP_CAMERA_PREVIEW_OVERLAY_FRAME_BUFFER_ADDRESS, prCamPrev->overlay_frame_buffer_address,
              IDP_CAMERA_PREVIEW_SET_OVERLAY_PALETTE_SIZE_AND_ADDR, prCamPrev->overlay_palette_size, prCamPrev->overlay_palette_addr,
              IDP_CAMERA_PREVIEW_OVERLAY_PALETTE_MODE, prCamPrev->overlay_color_depth,
              0);
          }
#endif // #if (!defined(DRV_IDP_6252_SERIES))
        }
        break;

      case IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE:
        result &= idp_camera_preview_config_fast(key, IDP_CAMERA_PREVIEW_FRAME_START_HISR_CB_ENABLE,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_DISPLAY_UPDATE:
        result &= idp_camera_preview_config_fast(key, IDP_CAMERA_PREVIEW_ENABLE_TRIGGER_LCD,  *(kal_uint32*)pvParam);
        break;

#if (defined (__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
      case IDP_CAL_SET_MAV_CAPTURE_ENABLE:
        result &= idp_camera_preview_config(key, IDP_CAMERA_PREVIEW_ENABLE_MAV_CAPTURE,  *(kal_uint32*)pvParam);
        break;
#endif
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
      case IDP_CAL_SET_ZSD_CAPTURE_TO_MEM_START:
        {
          bCapturetojpeg = KAL_FALSE;
        }
      case IDP_CAL_SET_ZSD_CAPTURE_TO_JPEG_START:
        {
          Camera_Capture_Idp_Cal_Struct *prCamCap = (Camera_Capture_Idp_Cal_Struct*) pvParam;
          result &= idp_camera_preview_config(
            key,
            IDP_CAMERA_PREVIEW_ZSD_CAPTURE_START, bCapturetojpeg, prCamCap->extmem_start_address,
            prCamCap->extmem_size, prCamCap->fullsize_image_format,
            prCamCap->fullsize_image_jpeg_yuv_mode, prCamCap->fullsize_image_width,
            prCamCap->fullsize_image_height, prCamCap->fullsize_image_buffer_y_addr,
            prCamCap->fullsize_image_buffer_u_addr, prCamCap->fullsize_image_buffer_v_addr,
            prCamCap->fullsize_image_rot_angle, prCamCap->quickview_image_enable,
            prCamCap->quickview_image_color_format, prCamCap->quickview_image_width,
            prCamCap->quickview_image_height, prCamCap->quickview_image_buffer_addr,
            prCamCap->thumbnail_image_enable, prCamCap->thumbnail_image_color_format,
            prCamCap->thumbnail_image_width, prCamCap->thumbnail_image_height,
            prCamCap->thumbnail_image_buffer_addr, prCamCap->enable_overlay,
            prCamCap->overlay_palette_size, prCamCap->overlay_palette_addr,
            prCamCap->overlay_color_depth, prCamCap->overlay_frame_source_key,
            prCamCap->overlay_frame_width, prCamCap->overlay_frame_height,
            prCamCap->overlay_frame_buffer_address, KAL_TRUE,
            0);
        }
        break;
#endif

      case IDP_CAL_SET_ZOOM_PARAM:
        {
          Digital_Zoom_Crop_Ctrl_Struct *prCamPrev = (Digital_Zoom_Crop_Ctrl_Struct*) pvParam;
          result &= idp_camera_preview_config(
            key,
            IDP_CAMERA_PREVIEW_IMAGE_SRC_WIDTH,       prCamPrev->updated_source_width,
            IDP_CAMERA_PREVIEW_IMAGE_SRC_HEIGHT,      prCamPrev->updated_source_height,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_ENABLE,   prCamPrev->mdp_crop_enable,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_WIDTH,    prCamPrev->cropped_width,
            IDP_CAMERA_PREVIEW_PREVIEW_CROP_HEIGHT,   prCamPrev->cropped_height,
            0);
        }
        break;

      default:
        //ASSERT(0);
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_INVALID_PARAMETER;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
} // end of Idp_Cal_Camera_Preview_Set()

static MM_ERROR_CODE_ENUM Idp_Cal_Capture_Set(
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_TRUE;

    switch(eSetType)
    {
      case IDP_CAL_SET_CONFIG:
        {
          Camera_Capture_Idp_Cal_Struct *prCamCapt;

          prCamCapt = (Camera_Capture_Idp_Cal_Struct*) pvParam;
          {
            result &= idp_camera_capture_to_jpeg_config(
              key,
#if (!defined(DRV_IDP_6252_SERIES))
              IDP_CAMERA_CAPTURE_TO_JPEG_EXTMEM_START_ADDRESS, prCamCapt->extmem_start_address,
              IDP_CAMERA_CAPTURE_TO_JPEG_EXTMEM_SIZE, prCamCapt->extmem_size,
#endif

              IDP_CAMERA_CAPTURE_TO_JPEG_IMAGE_SRC_WIDTH, prCamCapt->source_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_IMAGE_SRC_HEIGHT, prCamCapt->source_height,

              IDP_CAMERA_CAPTURE_TO_JPEG_CROP_ENABLE,   prCamCapt->mdp_crop_enable,
              IDP_CAMERA_CAPTURE_TO_JPEG_CROP_WIDTH,    prCamCapt->cropped_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_CROP_HEIGHT,   prCamCapt->cropped_height,

#if (!defined(DRV_IDP_6252_SERIES))
              // fullsize image configuration
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_ROT_ANGLE, prCamCapt->fullsize_image_rot_angle,

#if defined(DRV_IDP_6235_SERIES) || defined(DRV_IDP_6253_SERIES)
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_FORMAT, prCamCapt->fullsize_image_format,
#else
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_FORMAT, MM_IMAGE_FORMAT_JPEG,
#endif
#endif

              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_CAPTURE_WIDTH, prCamCapt->fullsize_image_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_CAPTURE_HEIGHT, prCamCapt->fullsize_image_height,
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_JPEG_YUV_MODE, prCamCapt->fullsize_image_jpeg_yuv_mode,
              IDP_CAMERA_CAPTURE_TO_JPEG_FULLSIZE_IMAGE_YUV_ADDRESSES, prCamCapt->fullsize_image_buffer_y_addr,
              prCamCapt->fullsize_image_buffer_u_addr, prCamCapt->fullsize_image_buffer_v_addr,

#if (!defined(DRV_IDP_6252_SERIES))
              // quickview image configuration
              IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_QUICKVIEW, prCamCapt->quickview_image_enable,

              // thumbnail image configuration
              IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_THUMBNAIL, prCamCapt->thumbnail_image_enable,

              IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_OVERLAY, prCamCapt->enable_overlay,

#if defined(__MTK_TARGET__)
              //IDP_CAMERA_CAPTURE_TO_JPEG_RESIZER_U_VALUE, 8,
              //IDP_CAMERA_CAPTURE_TO_JPEG_RESIZER_D_VALUE, 15,
#endif // #if defined(__MTK_TARGET__)
#endif
              0);
            //ASSERT(KAL_TRUE == result);
          }

#if (!defined(DRV_IDP_6252_SERIES))
          if (KAL_TRUE == prCamCapt->quickview_image_enable)
          {
            result &= idp_camera_capture_to_jpeg_config(
              key,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_ROT_ANGLE, prCamCapt->quickview_image_rot_angle,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_WIDTH, prCamCapt->quickview_image_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_HEIGHT, prCamCapt->quickview_image_height,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_FRAME_BUFFER_ADDRESS, prCamCapt->quickview_image_buffer_addr,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_IMAGE_COLOR_FORMAT, prCamCapt->quickview_image_color_format,
              IDP_CAMERA_CAPTURE_TO_JPEG_ENABLE_QUICKVIEW_PITCH, prCamCapt->quickview_pitch_enable,
              IDP_CAMERA_CAPTURE_TO_JPEG_QUICKVIEW_PITCH_WIDTH, prCamCapt->quickview_pitch_width,
              0);
            //ASSERT(KAL_TRUE == result);
          }

          if (KAL_TRUE == prCamCapt->thumbnail_image_enable)
          {
            result &= idp_camera_capture_to_jpeg_config(
              key,
              IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_ROT_ANGLE, prCamCapt->thumbnail_image_rot_angle,
              IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_IMAGE_COLOR_FORMAT, prCamCapt->thumbnail_image_color_format,
              IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_WIDTH, prCamCapt->thumbnail_image_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_HEIGHT, prCamCapt->thumbnail_image_height,
              IDP_CAMERA_CAPTURE_TO_JPEG_THUMBNAIL_BUFFER_ADDRESS, prCamCapt->thumbnail_image_buffer_addr,
              // the +14 was come from JPEG JFXX format, and now we insert thumbnail through JAIA,
              // so +14 will cause the memory passed from upper layer to be overwritten. Thus we remove +14.
              0);
            //ASSERT(KAL_TRUE == result);
          }

          if (KAL_TRUE == prCamCapt->enable_overlay)
          {
            result &= idp_camera_capture_to_jpeg_config(
              key,
              IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_SOURCE_KEY, prCamCapt->overlay_frame_source_key,
              IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_WIDTH, prCamCapt->overlay_frame_width,
              IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_HEIGHT, prCamCapt->overlay_frame_height,
              IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_FRAME_BUFFER_ADDRESS, prCamCapt->overlay_frame_buffer_address,
              IDP_CAMERA_CAPTURE_TO_JPEG_SET_OVERLAY_PALETTE_SIZE_AND_ADDR, prCamCapt->overlay_palette_size, prCamCapt->overlay_palette_addr,
              IDP_CAMERA_CAPTURE_TO_JPEG_OVERLAY_PALETTE_MODE, prCamCapt->overlay_color_depth,
              0);
            //ASSERT(KAL_TRUE == result);

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
#endif
          }
#endif // #if (!defined(DRV_IDP_6252_SERIES))
        }
        break;

#if defined(DRV_IDP_MT6236_SERIES)
      case IDP_CAL_SET_OVERRIDE_EMI_BW_TO_RAW_CAPTURE_MODE:
        {
#if defined(__MTK_TARGET__)
          EMI_SetScenarioBW(MM_CSE_CAP_OFFLINE); // IC2
#endif // #if defined(__MTK_TARGET__)
        }
        break;
#endif // #if defined(DRV_IDP_MT6236_SERIES)

      default:
        //ASSERT(0);
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_INVALID_PARAMETER;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
} // end of Idp_Cal_Capture_Set()


#if defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES)  || defined(DRV_IDP_MT6255_SERIES)
static MM_ERROR_CODE_ENUM Idp_Cal_Capture_Memory_Set(
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_TRUE;

    switch(eSetType)
    {
      case IDP_CAL_SET_CONFIG:
        {
          Camera_Capture_Idp_Cal_Struct *prCamCapt;

          prCamCapt = (Camera_Capture_Idp_Cal_Struct*) pvParam;
          {
            result &= idp_camera_capture_to_mem_config(
              key,

              IDP_CAMERA_CAPTURE_TO_MEM_EXTMEM_START_ADDRESS, prCamCapt->extmem_start_address,
              IDP_CAMERA_CAPTURE_TO_MEM_EXTMEM_SIZE, prCamCapt->extmem_size,

              IDP_CAMERA_CAPTURE_TO_MEM_IMAGE_SRC_WIDTH, prCamCapt->source_width,
              IDP_CAMERA_CAPTURE_TO_MEM_IMAGE_SRC_HEIGHT, prCamCapt->source_height,
              IDP_CAMERA_CAPTURE_TO_MEM_IMAGE_CAPTURE_WIDTH, prCamCapt->fullsize_image_width,
              IDP_CAMERA_CAPTURE_TO_MEM_IMAGE_CAPTURE_HEIGHT, prCamCapt->fullsize_image_height,

              IDP_CAMERA_CAPTURE_TO_MEM_CROP_ENABLE,   prCamCapt->mdp_crop_enable,
              IDP_CAMERA_CAPTURE_TO_MEM_CROP_WIDTH,    prCamCapt->cropped_width,
              IDP_CAMERA_CAPTURE_TO_MEM_CROP_HEIGHT,   prCamCapt->cropped_height,

              IDP_CAMERA_CAPTURE_TO_MEM_ENABLE_OVERLAY, prCamCapt->enable_overlay,

              IDP_CAMERA_CAPTURE_TO_MEM_ENABLE_PITCH, KAL_FALSE,
              IDP_CAMERA_CAPTURE_TO_MEM_BG_IMAGE_WIDTH, 0,
              IDP_CAMERA_CAPTURE_TO_MEM_IMAGE_DATA_FORMAT, prCamCapt->fullsize_image_format,

              IDP_CAMERA_CAPTURE_TO_MEM_Y_FRAME_BUFFER_ADDRESS, prCamCapt->fullsize_image_buffer_y_addr,
              IDP_CAMERA_CAPTURE_TO_MEM_U_FRAME_BUFFER_ADDRESS, prCamCapt->fullsize_image_buffer_u_addr,
              IDP_CAMERA_CAPTURE_TO_MEM_V_FRAME_BUFFER_ADDRESS, prCamCapt->fullsize_image_buffer_v_addr,

              IDP_CAMERA_CAPTURE_TO_MEM_ROT_ANGLE, prCamCapt->fullsize_image_rot_angle,

              // [capture to mem i/f expansion configurable lcd trigger]
              //IDP_CAMERA_CAPTURE_TO_MEM_TRIGGER_LCD, prCamCapt->trigger_lcd,

#if defined(__MTK_TARGET__)
              //IDP_CAMERA_CAPTURE_TO_MEM_RESIZER_U_VALUE, 8,
              //IDP_CAMERA_CAPTURE_TO_MEM_RESIZER_V_VALUE, 15,
#endif  // #if defined(__MTK_TARGET__)

              0);
            //ASSERT(KAL_TRUE == result);
          }
            if (KAL_TRUE == prCamCapt->enable_overlay)
            {
              result &= idp_camera_capture_to_mem_config(
                key,

                IDP_CAMERA_CAPTURE_TO_MEM_OVERLAY_FRAME_SOURCE_KEY, prCamCapt->overlay_frame_source_key,
                IDP_CAMERA_CAPTURE_TO_MEM_OVERLAY_FRAME_WIDTH, prCamCapt->overlay_frame_width,
                IDP_CAMERA_CAPTURE_TO_MEM_OVERLAY_FRAME_HEIGHT, prCamCapt->overlay_frame_height,
                IDP_CAMERA_CAPTURE_TO_MEM_OVERLAY_FRAME_BUFFER_ADDRESS, prCamCapt->overlay_frame_buffer_address,
                IDP_CAMERA_CAPTURE_TO_MEM_SET_OVERLAY_PALETTE_SIZE_AND_ADDR, prCamCapt->overlay_palette_size, prCamCapt->overlay_palette_addr,
                IDP_CAMERA_CAPTURE_TO_MEM_OVERLAY_PALETTE_MODE, prCamCapt->overlay_color_depth,

                0);
              //ASSERT(KAL_TRUE == result);
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
#endif
            }
        }
        break;

#if defined(DRV_IDP_MT6236_SERIES)
      case IDP_CAL_SET_OVERRIDE_EMI_BW_TO_RAW_CAPTURE_MODE:
        {
#if defined(__MTK_TARGET__)
          EMI_SetScenarioBW(MM_CSE_CAP_OFFLINE); // IC2
#endif
        }
        break;
#endif // #if defined(DRV_IDP_MT6236_SERIES)

      default:
        //ASSERT(0);
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_INVALID_PARAMETER;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
}
#endif //#if defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)


static MM_ERROR_CODE_ENUM Idp_Cal_Video_Encode_Set(
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_bool result = KAL_TRUE;

    switch(eSetType)
    {
      case IDP_CAL_SET_CONFIG:
        {
          Video_Encode_Idp_Cal_Struct* prVdoEnc;
          prVdoEnc = (Video_Encode_Idp_Cal_Struct*) pvParam;

          result &= idp_video_encode_config(
            key,

#if (!defined(DRV_IDP_6252_SERIES))
            IDP_VIDEO_ENCODE_EXTMEM_START_ADDRESS, prVdoEnc->extmem_start_address,
            IDP_VIDEO_ENCODE_EXTMEM_SIZE, prVdoEnc->extmem_size,
#endif

            IDP_VIDEO_ENCODE_IMAGE_SRC_WIDTH, prVdoEnc->source_width,
            IDP_VIDEO_ENCODE_IMAGE_SRC_HEIGHT, prVdoEnc->source_height,
            IDP_VIDEO_ENCODE_DISPLAY_ROT_ANGLE, prVdoEnc->display_rot_angle,
            IDP_VIDEO_ENCODE_DISPLAY_WIDTH, prVdoEnc->display_width,
            IDP_VIDEO_ENCODE_DISPLAY_HEIGHT, prVdoEnc->display_height,
#if (!defined(DRV_IDP_6252_SERIES))
            IDP_VIDEO_ENCODE_ENCODE_ROT_ANGLE, prVdoEnc->video_encode_image_rot_angle,
#endif
            IDP_VIDEO_ENCODE_ENCODE_WIDTH, prVdoEnc->video_encode_image_width,
            IDP_VIDEO_ENCODE_ENCODE_HEIGHT, prVdoEnc->video_encode_image_height,

            IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS1, prVdoEnc->frame_buffer_address1,
            IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS2, prVdoEnc->frame_buffer_address2,
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            IDP_VIDEO_ENCODE_FRAME_BUFFER_ADDRESS3, prVdoEnc->frame_buffer_address3,
#endif

#if (!defined(DRV_IDP_6252_SERIES))
            IDP_VIDEO_ENCODE_ENABLE_PITCH, prVdoEnc->preview_pitch_enable,
            IDP_VIDEO_ENCODE_DISPLAY_PITCH_WIDTH, prVdoEnc->preview_pitch_width,
            IDP_VIDEO_ENCODE_IMAGE_COLOR_FORMAT, prVdoEnc->preview_image_color_format,

            IDP_VIDEO_ENCODE_ENABLE_OVERLAY, prVdoEnc->enable_overlay,
#endif

            //IDP_VIDEO_ENCODE_ALLOCATE_VIDEO_ENCODER_INPUT_BUFFER, KAL_TRUE,

            IDP_VIDEO_ENCODE_FRAME_START_HISR_CB_ENABLE, prVdoEnc->video_encode_frame_start_hisr_cb_enable,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_ENABLE,   prVdoEnc->mdp_crop_enable,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_WIDTH,    prVdoEnc->cropped_width,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_HEIGHT,   prVdoEnc->cropped_height,

#if (!defined(DRV_IDP_6252_SERIES))
#if defined(__MTK_TARGET__)
            //IDP_VIDEO_ENCODE_RESIZER_U_VALUE, 8,
            //IDP_VIDEO_ENCODE_RESIZER_D_VALUE, 15,
#endif  // #if defined(__MTK_TARGET__)
#endif

            IDP_VIDEO_ENCODE_UPDATE_TO_LCD, prVdoEnc->lcd_update_enable,
#if (!defined(DRV_IDP_6252_SERIES))
            IDP_VIDEO_ENCODE_FORCE_LCD_HW_TRIGGER, prVdoEnc->force_lcd_hw_trigger,
#endif
            IDP_VIDEO_ENCODE_SENSOR_FPS_VIDEO_FPS, prVdoEnc->sensor_fps, prVdoEnc->video_fps,
            //In general matv receive data in crz frame to mdp frame done(rotdma done). for example MT5192.
            //MT5193 changes the original design, it will receive data about 16~20ms before frame start.
            //So, in order to aovid LCD interference MATV, we will delay trigger display in next frame start.
            IDP_VIDEO_ENCODE_ENABLE_TRIGGER_DISPLAY_DELAY_TO_FRAME_START, prVdoEnc->trigger_display_delay_to_frame_start_enable,
#if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
            IDP_VIDEO_ENCODE_QUALITY_LEVEL, prVdoEnc->quality_level,
#endif
            0);

          //ASSERT(KAL_TRUE == result);

#if (!defined(DRV_IDP_6252_SERIES))
          if (KAL_TRUE == prVdoEnc->enable_overlay)
          {
            result &= idp_video_encode_config(
              key,
              IDP_VIDEO_ENCODE_OVERLAY_FRAME_SOURCE_KEY, prVdoEnc->overlay_frame_source_key,
              IDP_VIDEO_ENCODE_OVERLAY_FRAME_WIDTH, prVdoEnc->overlay_frame_width,
              IDP_VIDEO_ENCODE_OVERLAY_FRAME_HEIGHT, prVdoEnc->overlay_frame_height,
              IDP_VIDEO_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS, prVdoEnc->overlay_frame_buffer_address,
              IDP_VIDEO_ENCODE_SET_OVERLAY_PALETTE_SIZE_AND_ADDR, prVdoEnc->overlay_palette_size, prVdoEnc->overlay_palette_addr,
              IDP_VIDEO_ENCODE_OVERLAY_PALETTE_MODE, prVdoEnc->overlay_color_depth,
              0);
            //ASSERT(KAL_TRUE == result);

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
#endif
          }
#endif
        }
        break;

      case IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE:
        result &= idp_video_encode_config_fast(key, IDP_VIDEO_ENCODE_FRAME_START_HISR_CB_ENABLE,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_ENCODE_ROTATION:
        result &= idp_video_encode_config_fast(key, IDP_VIDEO_ENCODE_ENCODE_DYNAMIC_ROT_ANGLE,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_DISPLAY_UPDATE:
        result &= idp_video_encode_config_fast(key, IDP_VIDEO_ENCODE_UPDATE_TO_LCD,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_ZOOM_PARAM:
        {
          Digital_Zoom_Crop_Ctrl_Struct *prCamPrev = (Digital_Zoom_Crop_Ctrl_Struct*) pvParam;
          result &= idp_video_encode_config(
            key,
            IDP_VIDEO_ENCODE_IMAGE_SRC_WIDTH,       prCamPrev->updated_source_width,
            IDP_VIDEO_ENCODE_IMAGE_SRC_HEIGHT,      prCamPrev->updated_source_height,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_ENABLE,   prCamPrev->mdp_crop_enable,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_WIDTH,    prCamPrev->cropped_width,
            IDP_VIDEO_ENCODE_PREVIEW_CROP_HEIGHT,   prCamPrev->cropped_height,
            0);
        }
        break;

      case IDP_CAL_SET_VT_SENSOR_FPS_VIDEO_FPS:
        {
          VT_Sensor_Fps_Video_Fps_Info_Struct *prFpsInfo= (VT_Sensor_Fps_Video_Fps_Info_Struct*) pvParam;
          result &= idp_video_encode_config(
                     key,
                     IDP_VIDEO_ENCODE_SENSOR_FPS_VIDEO_FPS, prFpsInfo->sensor_fps, prFpsInfo->video_fps,
                     0);
        }
        break;

      default:
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_INVALID_PARAMETER;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
} // end of Idp_Cal_Video_Encode_Set()

#if defined(__MEDIA_VT__)
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
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
#endif  // #if defined(__MTK_TARGET__)
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
#endif
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

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
static MM_ERROR_CODE_ENUM Idp_Cal_Mjpeg_Encode_Set(
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet;
    kal_bool result = KAL_TRUE;

    switch(eSetType)
    {
      case IDP_CAL_SET_CONFIG:
        {
          //kal_bool result;
          Mjpeg_Encode_Idp_Cal_Struct* prVdoEnc;
          prVdoEnc = (Mjpeg_Encode_Idp_Cal_Struct*) pvParam;

          result &= idp_mjpeg_encode_config(
            key,

            IDP_MJPEG_ENCODE_EXTMEM_START_ADDRESS, prVdoEnc->extmem_start_address,
            IDP_MJPEG_ENCODE_EXTMEM_SIZE, prVdoEnc->extmem_size,

            IDP_MJPEG_ENCODE_IMAGE_SRC_WIDTH, prVdoEnc->source_width,
            IDP_MJPEG_ENCODE_IMAGE_SRC_HEIGHT, prVdoEnc->source_height,
            IDP_MJPEG_ENCODE_DISPLAY_ROT_ANGLE, prVdoEnc->display_rot_angle,
            IDP_MJPEG_ENCODE_DISPLAY_WIDTH, prVdoEnc->display_width,
            IDP_MJPEG_ENCODE_DISPLAY_HEIGHT, prVdoEnc->display_height,

            IDP_MJPEG_ENCODE_JPEG_YUV_MODE, prVdoEnc->mjpeg_yuv_mode,
            IDP_MJPEG_ENCODE_ENCODE_WIDTH, prVdoEnc->mjpeg_encode_image_width,
            IDP_MJPEG_ENCODE_ENCODE_HEIGHT, prVdoEnc->mjpeg_encode_image_height,

            IDP_MJPEG_ENCODE_FRAME_BUFFER_ADDRESS1, prVdoEnc->frame_buffer_address1,
            IDP_MJPEG_ENCODE_FRAME_BUFFER_ADDRESS2, prVdoEnc->frame_buffer_address2,

            IDP_MJPEG_ENCODE_ENABLE_PITCH, prVdoEnc->preview_pitch_enable,
            IDP_MJPEG_ENCODE_DISPLAY_PITCH_WIDTH, prVdoEnc->preview_pitch_width,
            IDP_MJPEG_ENCODE_IMAGE_COLOR_FORMAT, prVdoEnc->preview_image_color_format,

            IDP_MJPEG_ENCODE_ENABLE_OVERLAY, prVdoEnc->enable_overlay,

            //IDP_VIDEO_ENCODE_ALLOCATE_VIDEO_ENCODER_INPUT_BUFFER, KAL_TRUE,

            IDP_MJPEG_ENCODE_FRAME_START_HISR_CB_ENABLE, prVdoEnc->video_encode_frame_start_hisr_cb_enable,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_ENABLE,   prVdoEnc->mdp_crop_enable,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_WIDTH,    prVdoEnc->cropped_width,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_HEIGHT,   prVdoEnc->cropped_height,

#if defined(__MTK_TARGET__)
            //IDP_MJPEG_ENCODE_RESIZER_U_VALUE, 8,
            //IDP_MJPEG_ENCODE_RESIZER_D_VALUE, 15,
#endif  // #if defined(__MTK_TARGET__)

            IDP_MJPEG_ENCODE_UPDATE_TO_LCD, prVdoEnc->lcd_update_enable,
            IDP_MJPEG_ENCODE_ENABLE_TRIGGER_DISPLAY_DELAY_TO_FRAME_START, prVdoEnc->trigger_display_delay_to_frame_start_enable,
            0);

          //ASSERT(KAL_TRUE == result);

          if (KAL_TRUE == prVdoEnc->enable_overlay)
          {
            result &= idp_video_encode_config(
              key,
              IDP_MJPEG_ENCODE_OVERLAY_FRAME_SOURCE_KEY, prVdoEnc->overlay_frame_source_key,
              IDP_MJPEG_ENCODE_OVERLAY_FRAME_WIDTH, prVdoEnc->overlay_frame_width,
              IDP_MJPEG_ENCODE_OVERLAY_FRAME_HEIGHT, prVdoEnc->overlay_frame_height,
              IDP_MJPEG_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS, prVdoEnc->overlay_frame_buffer_address,
              IDP_MJPEG_ENCODE_SET_OVERLAY_PALETTE_SIZE_AND_ADDR, prVdoEnc->overlay_palette_size, prVdoEnc->overlay_palette_addr,
              IDP_MJPEG_ENCODE_OVERLAY_PALETTE_MODE, prVdoEnc->overlay_color_depth,
              0);
            //ASSERT(KAL_TRUE == result);

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
#endif
          }
        }
        break;

      case IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE:
        result &= idp_mjpeg_encode_config_fast(key, IDP_MJPEG_ENCODE_FRAME_START_HISR_CB_ENABLE,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_DISPLAY_UPDATE:
        result &= idp_mjpeg_encode_config_fast(key, IDP_MJPEG_ENCODE_UPDATE_TO_LCD,  *(kal_uint32*)pvParam);
        break;

      case IDP_CAL_SET_ZOOM_PARAM:
        {
          Digital_Zoom_Crop_Ctrl_Struct *prCamPrev = (Digital_Zoom_Crop_Ctrl_Struct*) pvParam;
          result &= idp_mjpeg_encode_config(
            key,
            IDP_MJPEG_ENCODE_IMAGE_SRC_WIDTH,       prCamPrev->updated_source_width,
            IDP_MJPEG_ENCODE_IMAGE_SRC_HEIGHT,      prCamPrev->updated_source_height,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_ENABLE,   prCamPrev->mdp_crop_enable,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_WIDTH,    prCamPrev->cropped_width,
            IDP_MJPEG_ENCODE_PREVIEW_CROP_HEIGHT,   prCamPrev->cropped_height,
            0);
        }
        break;

      case IDP_CAL_SET_OVERRIDE_EMI_BW_TO_RAW_CAPTURE_MODE:
        break;

      default:
        break;
    }
    if (result == KAL_FALSE)
    {eRet = MM_ERROR_INVALID_PARAMETER;}
    else
    {eRet = MM_ERROR_NONE;}

    return eRet;
} // end of Idp_Cal_Video_Encode_Set()
#endif

static MM_ERROR_CODE_ENUM Idp_Cal_Set(
        CAL_SCENARIO_ENUM eCalScenID,
        kal_uint32 const key,
        IDP_CAL_SET_TYPE_T eSetType,
        void *pvParam)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;

    switch(eCalScenID)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
        case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
#endif
          eRet = Idp_Cal_Camera_Preview_Set(key, eSetType, pvParam);
          break;
        case CAL_SCENARIO_VIDEO:
          eRet = Idp_Cal_Video_Encode_Set(key, eSetType, pvParam);
          break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
          eRet = Idp_Cal_Capture_Set(key, eSetType, pvParam);
          break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
          eRet = Idp_Cal_Capture_Set(key, eSetType, pvParam);
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
          eRet = Idp_Cal_Capture_Memory_Set(key, eSetType, pvParam);
#else
       Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;
#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
        case CAL_SCENARIO_VIDEO_MJPEG:
          eRet = Idp_Cal_Mjpeg_Encode_Set(key, eSetType, pvParam);
          break;
#endif
        default:
          break;
    }
    return eRet;
}


/* Note: The query function is designed for selected capabilities. Not all combinations can be queried, but it is
 *       definitely possible to extend for general capabilities.
 *       Please refer to the comment of IDP_CAL_QUERY_TYPE_T for the usage of different query types.
 */
static MM_ERROR_CODE_ENUM Idp_Cal_Query(
        const CAL_SCENARIO_ENUM eCalScenID,
        const kal_uint32 key,
        const IDP_CAL_QUERY_TYPE_T eQryType,
        const IDP_CAL_QUERY_ARG_T *prArg,
        void *pvResult)
{
    MM_ERROR_CODE_ENUM eRet = MM_ERROR_NONE;
    kal_uint32 u4QueryResult;

    switch(eCalScenID)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
#if defined (__ZERO_SHUTTER_DELAY_SUPPORT__)
        case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
#endif
            idp_camera_preview_query(key,
                IDP_CAMERA_PREVIEW_QUERY_TYPE, eQryType,
                IDP_CAMERA_PREVIEW_QUERY_ARG_PATH, prArg->ePath,
                IDP_CAMERA_PREVIEW_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
                IDP_CAMERA_PREVIEW_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
                IDP_CAMERA_PREVIEW_QUERY_RESULT, &u4QueryResult,
                0
                );
            break;

        case CAL_SCENARIO_VIDEO:
            idp_video_encode_query(key,
                IDP_VIDEO_ENCODE_QUERY_TYPE, eQryType,
                IDP_VIDEO_ENCODE_QUERY_ARG_PATH, prArg->ePath,
                IDP_VIDEO_ENCODE_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
// to support flexible video record, query need to add rotation width parameter
#if defined(DRV_IDP_MT6255_SERIES) || defined(DRV_IDP_MT6256_E2_SERIES)
                IDP_VIDEO_ENCODE_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle, prArg->eRotateWidth,
#else
                IDP_VIDEO_ENCODE_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
#endif
                IDP_VIDEO_ENCODE_QUERY_RESULT, &u4QueryResult,
                0
                );
            break;

        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            idp_camera_capture_to_jpeg_query(key,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_TYPE, eQryType,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_PATH, prArg->ePath,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_RESULT, &u4QueryResult,
                0
                );
            break;

        case CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM:
#if defined(DRV_IDP_6235_SERIES) ||defined(DRV_IDP_6252_SERIES) || defined(DRV_IDP_6253_SERIES)
            idp_camera_capture_to_jpeg_query(key,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_TYPE, eQryType,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_PATH, prArg->ePath,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
                IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_RESULT, &u4QueryResult,
                0
                );
#elif defined(DRV_IDP_MT6236_SERIES) ||defined(DRV_IDP_6238_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6255_SERIES)
            idp_camera_capture_to_mem_query(key,
                IDP_CAMERA_CAPTURE_TO_MEM_QUERY_TYPE, eQryType,
                IDP_CAMERA_CAPTURE_TO_MEM_QUERY_ARG_PATH, prArg->ePath,
                IDP_CAMERA_CAPTURE_TO_MEM_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
                IDP_CAMERA_CAPTURE_TO_MEM_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
                IDP_CAMERA_CAPTURE_TO_MEM_QUERY_RESULT, &u4QueryResult,
                0
                );
#else
       Error, Please add DRV_IDP_MT62xx_SERIES
#endif
        break;

#if defined(__MEDIA_VT__)
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

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_ENCODE)
        case CAL_SCENARIO_VIDEO_MJPEG:
            idp_mjpeg_encode_query(key,
                IDP_MJPEG_ENCODE_QUERY_TYPE, eQryType,
                IDP_MJPEG_ENCODE_QUERY_ARG_PATH, prArg->ePath,
                IDP_MJPEG_ENCODE_QUERY_ARG_CLR_FMT, prArg->eClrFmt,
                IDP_MJPEG_ENCODE_QUERY_ARG_DESIRED_ANGLE,  prArg->eDesiredAngle,
                IDP_MJPEG_ENCODE_QUERY_RESULT, &u4QueryResult,
                0
                );
            break;
#endif

        default:
            //ASSERT(0);
            break;
    }
    *((kal_uint32 *)pvResult) = u4QueryResult;

    return eRet;
}  // end of Idp_Cal_Query

MM_ERROR_CODE_ENUM Idp_Cal_If_Init(
    MM_ERROR_CODE_ENUM (*pfnCallback)(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen),
    IDP_CAL_INTF_FUNC_T *prIdpCalFuncPtrTbl)
{
    prIdpCalFuncPtrTbl->pfnIdpCalOpen    = Idp_Cal_Open;
    prIdpCalFuncPtrTbl->pfnIdpCalClose   = Idp_Cal_Close;
    prIdpCalFuncPtrTbl->pfnIdpCalStart   = Idp_Cal_Start;
    prIdpCalFuncPtrTbl->pfnIdpCalStop    = Idp_Cal_Stop;
    prIdpCalFuncPtrTbl->pfnIdpCalIsBusy  = NULL;
    prIdpCalFuncPtrTbl->pfnIdpCalIsInUse = (PFN_IDPCAL_IS_INUSE) Idp_Cal_Is_In_Use;
    prIdpCalFuncPtrTbl->pfnIdpCalSet     = Idp_Cal_Set;
    prIdpCalFuncPtrTbl->pfnIdpCalGet     = NULL;
    prIdpCalFuncPtrTbl->pfnIdpCalQuery   = (PFN_IDPCAL_QUERY_T) Idp_Cal_Query;

    pfIDP_CAL_CB = pfnCallback;
    return MM_ERROR_NONE;
}

#endif //#if defined(DRV_IDP_SUPPORT)

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

