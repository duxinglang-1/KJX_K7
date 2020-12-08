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
 *   usbvideo_attr_OV2655.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "stdio.h"
#include "drv_features.h"
#include "image_sensor.h"
#include "mm_comm_def.h"
#include "sensor_comm_def.h"
#include "usbvideo_custom.h"
#include "jpeg_enum.h"
#include "isp_if.h"

#if (defined(WEBCAM_SUPPORT))
/* supported feature list */
static const USBVideo_Attr_Info OV2655WebcamAttrInfo[11] =
{
  {USBVIDEO_ATTRIBUTE_BRIGHTNESS, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_CONTRAST, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_HUE, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_HUE_AUTO, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_SATURATION, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_SHARPNESS, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_GAMMA, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP, KAL_TRUE, KAL_TRUE},
  {USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO, KAL_TRUE, KAL_TRUE},
};

/* supported video size list */
static const USBVideo_Video_Size_Info OV2655WebcamVideoSize[3] = // for size customization
{
  {USBVIDEO_VIDEO_SIZE_1, 160, 120, 0xC000, 912382, 38012, 500000, 500000, 500000, 0},
  {USBVIDEO_VIDEO_SIZE_2, 320, 240, 0xC000, 912384, 38016, 500000, 500000, 500000, 0},
#if (defined(__JPEG_HW_SUPPORTED__))
  {USBVIDEO_VIDEO_SIZE_3, 640, 480, 0x18000, 912384, 38016, 500000, 500000, 500000, 0}
#else
  {USBVIDEO_VIDEO_SIZE_3, 640, 480, 0xC100, 912384, 38016, 500000, 500000, 500000, 0}
#endif
};

/* supported still image size list */
static const USBVideo_Still_Size_Info OV2655WebcamStillSize[3] = // for size customization
{
  {USBVIDEO_STILL_SIZE_1, 160, 120, 0xC000},
  {USBVIDEO_STILL_SIZE_2, 320, 240, 0xC000},
#if (defined(__JPEG_HW_SUPPORTED__))
  {USBVIDEO_STILL_SIZE_3, 640, 480, 0x18000}
#else
  {USBVIDEO_STILL_SIZE_3, 640, 480, 0xC100}
#endif
};

/* supported compression type list*/
static const USBVideo_Compression_Info OV2655WebcamStillCompression[2] = // for compression customization
{
  {USBVIDEO_COMPRESSION_1, JPEG_ENCODE_QUALITY_LOW},
  {USBVIDEO_COMPRESSION_2, JPEG_ENCODE_QUALITY_FAIR}
};

static const USBVIDEO_VIDEO_SIZE_TYPE OV2655WebcamDefaultVideoSize = USBVIDEO_VIDEO_SIZE_1;
static const USBVIDEO_STILL_SIZE_TYPE OV2655WebcamDefaultStillSize = USBVIDEO_STILL_SIZE_1;
static const USBVIDEO_COMPRESSION_TYPE OV2655WebcamDefaultCompression = USBVIDEO_COMPRESSION_1;

static const usbvideo_attr_struct OV2655WebcamAttrPara =
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

MM_ERROR_CODE_ENUM OV2655WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  switch(FeatureId)
  {
  case CAL_FEATURE_WEBCAM_GET_ATTR:
    {
      USBVideo_Attr_Value *pWebCamAttr = (USBVideo_Attr_Value *)pFeatureParaOut;
      USBVIDEO_ATTRIBUTE_TYPE AttrType = pWebCamAttr->type;

      if (AttrType <= USBVIDEO_ATTRIBUTE_CT_MAX)
      {
        pWebCamAttr->value = 0;    ///CT currently is not support
      }
      else
      {
        if (AttrType >= ATTR_PU_START)
        {
            switch (pWebCamAttr->req_type)
            {
            case USBVIDEO_REQUEST_GET_CUR:
                ASSERT(0);          ///current value is maintained in ISP driver
                break;
            case USBVIDEO_REQUEST_GET_MIN:
                pWebCamAttr->value = OV2655WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].min;
                break;
            case USBVIDEO_REQUEST_GET_MAX:
                pWebCamAttr->value = OV2655WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].max;
                break;
            case USBVIDEO_REQUEST_GET_DEF:
                pWebCamAttr->value = OV2655WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].def;
                break;
            case USBVIDEO_REQUEST_GET_RES:
                pWebCamAttr->value = OV2655WebcamAttrPara.attr_info[GET_ATTR_PU_IDX(AttrType)].res;
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
      // Only for YUV sensor
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_ATTR_INFO:
    {
      P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT pWebCamAttrInfo = (P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT)pFeatureParaOut;

      pWebCamAttrInfo->pWebCamAttrInfo = OV2655WebcamAttrInfo;
      pWebCamAttrInfo->WebCamAttrInfoNum = sizeof(OV2655WebcamAttrInfo) / sizeof(USBVideo_Attr_Info);
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE:
    {
      P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT pWebCamVideoSize = (P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT)pFeatureParaOut;

      pWebCamVideoSize->pWebCamVideoSizeInfo = OV2655WebcamVideoSize;
      pWebCamVideoSize->WebCamVideoSizeInfoNum = sizeof(OV2655WebcamVideoSize) / sizeof(USBVideo_Video_Size_Info);
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_STILL_SIZE:
    {
      P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT pWebCamStillSize = (P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT)pFeatureParaOut;

      pWebCamStillSize->pWebCamStillSizeInfo = OV2655WebcamStillSize;
      pWebCamStillSize->WebCamStillSizeInfoNum = sizeof(OV2655WebcamStillSize) / sizeof(USBVideo_Still_Size_Info);
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_COMPRESSION:
    {
      P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT pWebCamCompression = (P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT)pFeatureParaOut;

      pWebCamCompression->pWebCamCompressionInfo = OV2655WebcamStillCompression;
      pWebCamCompression->WebCamCompressionInfoNum = sizeof(OV2655WebcamStillCompression) / sizeof(USBVideo_Compression_Info);
    }
    break;
  case CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX:
    {
      P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT pWebCamDeafultIdx = (P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT)pFeatureParaOut;

      pWebCamDeafultIdx->WebCamVideoSizeIdx = OV2655WebcamDefaultVideoSize;
      pWebCamDeafultIdx->WebCamStillSizeIdx = OV2655WebcamDefaultStillSize;
      pWebCamDeafultIdx->WebCamCompressionIdx = OV2655WebcamDefaultCompression;
    }
    break;
  default :
    ErrorCode = MM_ERROR_INVALID_PARAMETER;
    break;
  }
  return ErrorCode;
}

#else
MM_ERROR_CODE_ENUM OV2655WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  return MM_ERROR_NONE;
}

#endif /* END_OF_WEBCAM_SUPPORT */

