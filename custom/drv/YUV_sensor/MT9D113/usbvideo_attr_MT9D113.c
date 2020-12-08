/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usbvideo_attr_MT9D113.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor webcam driver function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#include "drv_comm.h"
#include "stdio.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "mm_comm_def.h"
#include "sensor_comm_def.h"
#include "usbvideo_custom.h"
#include "jpeg_enum.h"

#if (defined(WEBCAM_SUPPORT))
MM_ERROR_CODE_ENUM MT9D113WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *in, void *out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
  /* supported feature list */
  static const USBVideo_Attr_Info MT9D113_ATTR_INFO[] =
	  {
		{USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, KAL_TRUE, KAL_TRUE},
		{USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION, KAL_TRUE, KAL_TRUE},
		{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP, KAL_TRUE, KAL_TRUE},
		{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO, KAL_TRUE, KAL_TRUE},
	  };

  /* supported video size list */
  static const USBVideo_Video_Size_Info MT9D113_VIDEO_SIZE[] =
  {
  {USBVIDEO_VIDEO_SIZE_1, 160, 120, 0xC000, 912382, 38012, 500000, 500000, 500000, 0},
  {USBVIDEO_VIDEO_SIZE_2, 320, 240, 0xC000, 912384, 38016, 500000, 500000, 500000, 0},
#if (defined(DRV_ISP_6238_SERIES))
  {USBVIDEO_VIDEO_SIZE_3, 640, 480, 0x18000, 912384, 38016, 500000, 500000, 500000, 0},
#elif (defined(MT6225))
  {USBVIDEO_VIDEO_SIZE_3, 640, 480, 0xC100, 912384, 38016, 500000, 500000, 500000, 0},
#else
  {USBVIDEO_VIDEO_SIZE_3, 640, 480, 0xC000, 912384, 38016, 500000, 500000, 500000, 0},
#endif
};
  /* supported still image size list */
  static const USBVideo_Still_Size_Info MT9D113_STILL_SIZE[] =
  {
  {USBVIDEO_STILL_SIZE_1, 160, 120, 0xC000},
  {USBVIDEO_STILL_SIZE_2, 320, 240, 0xC000},
#if (defined(DRV_ISP_6238_SERIES))
  {USBVIDEO_STILL_SIZE_3, 640, 480, 0x18000},
#else
  {USBVIDEO_STILL_SIZE_3, 640, 480, 0xC000},
#endif
};
  /* supported compression type list*/
  static const USBVideo_Compression_Info MT9D113_STILL_COMPRESSION[] =
  {
  //{USBVIDEO_COMPRESSION_1, JPEG_ENCODER_GOOD_QUALITY},
  {USBVIDEO_COMPRESSION_1, JPEG_ENCODE_QUALITY_LOW},
  {USBVIDEO_COMPRESSION_2, JPEG_ENCODE_QUALITY_FAIR},
};
static const USBVIDEO_VIDEO_SIZE_TYPE MT9D113_g_default_video_size = USBVIDEO_VIDEO_SIZE_1;
static const USBVIDEO_STILL_SIZE_TYPE MT9D113_g_default_still_size = USBVIDEO_STILL_SIZE_1;
static const USBVIDEO_COMPRESSION_TYPE MT9D113_g_default_compression = USBVIDEO_COMPRESSION_1;
  static const usbvideo_attr_struct MT9D113WebcamAttrPara =
  {
    /* min,  max,         res,        def */
    {
      {0,      4,    1,    0  },  /*0  USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION*/
      {0,      255,  1,    128 },  /*1  USBVIDEO_ATTRIBUTE_BRIGHTNESS*/
      {0,      255,  1,    64  },  /*2  USBVIDEO_ATTRIBUTE_CONTRAST*/
      {0,      255,  1,    127 },  /*3  USBVIDEO_ATTRIBUTE_GAIN*/
      {0,      2,    1,    1  },  /*4  USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, 0:Disable, 1:50, 2:60*/
      {0,      360,  1 ,      0  },  /*5  USBVIDEO_ATTRIBUTE_HUE*/
      {0,      255,  1,    64  },  /*6  USBVIDEO_ATTRIBUTE_SATURATION*/
      {0,      15,      1,    0  },  /*7  USBVIDEO_ATTRIBUTE_SHARPNESS*/
      {100,   220,  60,      160 },  /*8  USBVIDEO_ATTRIBUTE_GAMMA*/
      {2500,  6500,  500,  5500},  /*9 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP*/
      {0,      1,    1,    1  },  /*10 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO*/
      {0,      0,    0,    0  },  /*11 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP, NOT SUPPORT*/
      {0,      1,    1,    1  },  /*12 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP_AUTO*/
      {0,      0,    1,    0  },  /*13 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER, NOT SUPPORT*/
      {0,      0,    1,    0  },  /*14 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER_LIMIT, NOT SUPPORT*/
      {0,      1,      1,    0  },  /*15 USBVIDEO_ATTRIBUTE_HUE_AUTO*/
      {0,      0,    0,    0  }  /*16 USBVIDEO_ATTRIBUTE_MAX_MULTIPLIER, NOT SUPPORT*/
    }
  };
  MM_ERROR_CODE_ENUM err_code = MM_ERROR_NONE;
  
  switch(id)
  {
  case CAL_FEATURE_WEBCAM_GET_ATTR:
    {
      USBVideo_Attr_Value *pWebCamAttr = (USBVideo_Attr_Value *)out;
      USBVIDEO_ATTRIBUTE_TYPE AttrType = pWebCamAttr->type;
      
      if (AttrType <= USBVIDEO_ATTRIBUTE_CT_MAX)
      {
        pWebCamAttr->value = 0; /* CT currently is not support */
      }
      else
      {
        if (AttrType >= ATTR_PU_START)
        {
          switch(pWebCamAttr->req_type)
          {
          case USBVIDEO_REQUEST_GET_CUR:
            ASSERT(0); /* current value is maintained in ISP driver */
            break;
          case USBVIDEO_REQUEST_GET_MIN:
            pWebCamAttr->value = MT9D113WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].min;
            break;
          case USBVIDEO_REQUEST_GET_MAX:
            pWebCamAttr->value = MT9D113WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].max;
            break;
          case USBVIDEO_REQUEST_GET_DEF:
            pWebCamAttr->value = MT9D113WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].def;
            break;
          case USBVIDEO_REQUEST_GET_RES:
            pWebCamAttr->value = MT9D113WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].res;
            break;
          default:
            EXT_ASSERT(0, (kal_uint32)pWebCamAttr->req_type, 0, 0);
            break;
          }
        }
        else
        {
          ASSERT(0);
        }
      }
    }
    break;
  case CAL_FEATURE_WEBCAM_SET_ATTR:
    {
      const USBVIDEO_ATTRIBUTE_TYPE attr_type = ((USBVideo_Attr_Value *)in)->type;
      const kal_uint32 attr_value = ((USBVideo_Attr_Value *)in)->value;
      
      /* Sensor Attributes Set */
      // update attr PU current value
      //usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(attr_type)] = attr_value;
      switch(attr_type)
      {
      case USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY:
        //image_sensor_func->yuv_sensor_setting(CAM_PARAM_BANDING, attr_value ? CAM_BANDING_60HZ : CAM_BANDING_50HZ);
        break;
      case USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION:
        //image_sensor_func->yuv_sensor_setting(CAM_PARAM_EXPOSURE, attr_value);
        break;
      case USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO:
       // if (attr_value > 0) /* AUTO */
          //image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB, CAM_WB_AUTO);
      case USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP:
        break;
      }
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_ATTR_INFO:
    ((P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT)out)->pWebCamAttrInfo = MT9D113_ATTR_INFO;
    ((P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT)out)->WebCamAttrInfoNum = sizeof(MT9D113_ATTR_INFO) / sizeof(MT9D113_ATTR_INFO[0]);
    break;
  case CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE:
    ((P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT)out)->pWebCamVideoSizeInfo = MT9D113_VIDEO_SIZE;
    ((P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT)out)->WebCamVideoSizeInfoNum = sizeof(MT9D113_VIDEO_SIZE) / sizeof(MT9D113_VIDEO_SIZE[0]);
    break;
  case CAL_FEATURE_WEBCAM_GET_STILL_SIZE:
    ((P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT)out)->pWebCamStillSizeInfo = MT9D113_STILL_SIZE;
    ((P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT)out)->WebCamStillSizeInfoNum = sizeof(MT9D113_STILL_SIZE) / sizeof(MT9D113_STILL_SIZE[0]);
    break;
  case CAL_FEATURE_WEBCAM_GET_COMPRESSION:
    ((P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT)out)->pWebCamCompressionInfo = MT9D113_STILL_COMPRESSION;
    ((P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT)out)->WebCamCompressionInfoNum = sizeof(MT9D113_STILL_COMPRESSION) / sizeof(MT9D113_STILL_COMPRESSION[0]);
    break;
  case CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX:
    ((P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT)out)->WebCamVideoSizeIdx = MT9D113_g_default_video_size;
    ((P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT)out)->WebCamStillSizeIdx = MT9D113_g_default_still_size;
    ((P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT)out)->WebCamCompressionIdx = MT9D113_g_default_compression;
    break;
  default:
    err_code = MM_ERROR_INVALID_PARAMETER;
    break;
  }
  return err_code;
}

#else
MM_ERROR_CODE_ENUM MT9D113WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *in, void *out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
  return MM_ERROR_NONE;
}
#endif

