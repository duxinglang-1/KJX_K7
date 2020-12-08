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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   image_sensor_MT9P015.h
 *
 * Project:
 * --------
 *   MT6268
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_MT9P015_H
#define _IMAGE_SENSOR_MT9P015_H

#include "drv_features.h"
#include "sensor_comm_def.h"

#define MT9P015_FACTORY_START_ADDR 0
#define MT9P015_ENGINEER_START_ADDR 39

typedef enum MT9P015_group_enum
{
  MT9P015_PRE_GAIN = 0,
  MT9P015_CMMCLK_CURRENT,
  MT9P015_FRAME_RATE_LIMITATION,
  MT9P015_REGISTER_EDITOR,
  MT9P015_GROUP_TOTAL_NUMS
} MT9P015_FACTORY_GROUP_ENUM;

typedef enum MT9P015_register_index
{
  MT9P015_SENSOR_BASEGAIN = MT9P015_FACTORY_START_ADDR,
  MT9P015_PRE_GAIN_R_INDEX,
  MT9P015_PRE_GAIN_Gr_INDEX,
  MT9P015_PRE_GAIN_Gb_INDEX,
  MT9P015_PRE_GAIN_B_INDEX,
  MT9P015_FACTORY_END_ADDR
} MT9P015_FACTORY_REGISTER_INDEX;

typedef enum MT9P015_engineer_index
{
  MT9P015_CMMCLK_CURRENT_INDEX = MT9P015_ENGINEER_START_ADDR,
  MT9P015_ENGINEER_END
} MT9P015_FACTORY_ENGINEER_INDEX;

#if (!(defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6235_SERIES)))
typedef struct _sensor_data_struct
{
  sensor_reg_struct reg[MT9P015_ENGINEER_END];
  sensor_reg_struct cct[MT9P015_FACTORY_END_ADDR];
} sensor_data_struct;
#endif

#define MT9P015_FIRST_GRAB_COLOR                BAYER_B
#define MT9P015_CURRENT_MAIN_SENSOR             MT9P015_MICRON

#define MT9P015_SET_RST_TO_LOW                  REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
#define MT9P015_SET_RST_TO_HIGH                 REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;

/* SENSOR FULL/PV SIZE */
#define MT9P015_IMAGE_SENSOR_FULL_WIDTH_DRV     2592
#define MT9P015_IMAGE_SENSOR_FULL_HEIGHT_DRV    1944
#define MT9P015_IMAGE_SENSOR_PV_WIDTH_DRV       (MT9P015_IMAGE_SENSOR_FULL_WIDTH_DRV / 2)
#define MT9P015_IMAGE_SENSOR_PV_HEIGHT_DRV      (MT9P015_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2)

/* SENSOR HORIZONTAL/VERTICAL ACTIVE REGION */
#define MT9P015_IMAGE_SENSOR_FULL_HACTIVE       MT9P015_IMAGE_SENSOR_FULL_WIDTH_DRV /* 2592 */
#define MT9P015_IMAGE_SENSOR_FULL_VACTIVE       MT9P015_IMAGE_SENSOR_FULL_HEIGHT_DRV /* 1944 */
#define MT9P015_IMAGE_SENSOR_PV_HACTIVE         MT9P015_IMAGE_SENSOR_PV_WIDTH_DRV /* 1296 */
#define MT9P015_IMAGE_SENSOR_PV_VACTIVE         MT9P015_IMAGE_SENSOR_PV_HEIGHT_DRV /* 972 */

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
//#define MT9P015_IMAGE_SENSOR_FULL_HBLANKING     1603 /*  1603  15 fps  128Mhz*/ 
#define MT9P015_IMAGE_SENSOR_FULL_HBLANKING     1800 /*  14.4 128Mhz*/
//#define MT9P015_IMAGE_SENSOR_FULL_HBLANKING     1813 /*  15 fps 134.4 Mhz */
#else
#define MT9P015_IMAGE_SENSOR_FULL_HBLANKING     3307 /* 3307 */
#endif
#define MT9P015_IMAGE_SENSOR_FULL_VBLANKING     90 /* 90 */
#define MT9P015_IMAGE_SENSOR_PV_HBLANKING       1717 /* 1717 */
#define MT9P015_IMAGE_SENSOR_PV_VBLANKING       90 /* 90 */

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define MT9P015_FULL_PERIOD_PIXEL_NUMS          (MT9P015_IMAGE_SENSOR_FULL_HACTIVE + MT9P015_IMAGE_SENSOR_FULL_HBLANKING) /* 38:5899 36:4195 */
#define MT9P015_FULL_PERIOD_LINE_NUMS           (MT9P015_IMAGE_SENSOR_FULL_VACTIVE + MT9P015_IMAGE_SENSOR_FULL_VBLANKING) /* 2034 */

//#define MT9P015_FULL_PERIOD_PIXEL_NUMS          4195 //3933 //4916 //120M 15fps 96M 12fps
//#define MT9P015_FULL_PERIOD_LINE_NUMS           2034 //2034

#define MT9P015_PV_PERIOD_PIXEL_NUMS            (MT9P015_IMAGE_SENSOR_PV_HACTIVE + MT9P015_IMAGE_SENSOR_PV_HBLANKING) /* 3013 */
#define MT9P015_PV_PERIOD_LINE_NUMS             (MT9P015_IMAGE_SENSOR_PV_VACTIVE + MT9P015_IMAGE_SENSOR_PV_VBLANKING) /* 1062 */

/* SENSOR START/END POSITION */
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define MT9P015_FULL_X_START                    6
#define MT9P015_FULL_Y_START                    6
#else
#define MT9P015_FULL_X_START                    4
#define MT9P015_FULL_Y_START                    4
#endif
#define MT9P015_IMAGE_SENSOR_FULL_WIDTH         (MT9P015_IMAGE_SENSOR_FULL_HACTIVE - 36) /* 2556 */
#define MT9P015_IMAGE_SENSOR_FULL_HEIGHT        (MT9P015_IMAGE_SENSOR_FULL_VACTIVE - 27) /* 1921 */
#define MT9P015_PV_X_START                      4
#define MT9P015_PV_Y_START                      4
#define MT9P015_IMAGE_SENSOR_PV_WIDTH           (MT9P015_IMAGE_SENSOR_PV_HACTIVE - 16) /* 1280 */
#define MT9P015_IMAGE_SENSOR_PV_HEIGHT          (MT9P015_IMAGE_SENSOR_PV_VACTIVE - 12) /* 960 */

/* SENSOR GAIN LIMITATION */
#define MT9P015_MIN_ANALOG_GAIN                 1 /* 1x analog gain */
#define MT9P015_MAX_ANALOG_GAIN                 12.7

/* SENSOR READ/WRITE ID */
#define MT9P015_SLV1_WRITE_ID                   0x20 /* SMIA */
#define MT9P015_SLV1_READ_ID                    0x21
#define MT9P015_SLV2_WRITE_ID                   0x30
#define MT9P015_SLV2_READ_ID                    0x31
#define MT9P015_SLV3_WRITE_ID                   0x6C /* MIPI */
#define MT9P015_SLV3_READ_ID                    0x6D
#define MT9P015_SLV4_WRITE_ID                   0x6E
#define MT9P015_SLV4_READ_ID                    0x6F

#define MT9P015_HW_SCCB /* if no define, means use SW SCCB */

#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define MT9P015_SCCB_FAST_MODE_SPEED            280 /* unit: Kb */
#else
#define MT9P015_SCCB_FAST_MODE_SPEED            350 /* unit: Kb */
#endif

struct MT9P015_sensor_STRUCT
{
  kal_uint8 Mirror;
  kal_bool PvMode;
  kal_uint16 NormalFps; /* video normal mode max fps */
  kal_uint16 NightFps; /* video night mode max fps */
  kal_uint8 WriteId;
  kal_uint8 ReadId;
  kal_uint32 VtClk;/* internal use */
  kal_uint32 ExposureLines;
  kal_uint16 CapShutter;
  kal_uint16 Gain;
  kal_uint16 DummyLines;
  kal_uint16 FrameHeight;
  kal_uint16 LineLength;
  kal_uint16 VideoCurrentFrameRate;
};
/*for MT6238 and MT6268,only use one clock MT9P015_PREVIEW_CLK 
    for MT6236, use MT9P015_PREVIEW_CLK preview and on the fly capture 
	               use MT9P015_CAPTURE_CLK off line capture                      */

#if (defined(DRV_ISP_6238_SERIES))
#define MT9P015_PREVIEW_CLK                     96000000
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define MT9P015_CAPTURE_CLK                     128000000   //Max capture frame rate 14.4 fps
//#define MT9P015_CAPTURE_CLK                     134400000 //Max capture frame rate  capture 15 fps
#endif
#endif

/* FRAME RATE UNIT */
#define MT9P015_FRAME_RATE_UNIT                 10

#define MT9P015_FPS(a)				((a) * MT9P015_FRAME_RATE_UNIT)

MM_ERROR_CODE_ENUM MT9P015SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM MT9P015WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);


void MT9P015GetAeLut(P_AE_LUT_INFO_STRUCT pFeatureParaIn,
                         P_IMAGE_SENSOR_AE_LUT_STRUCT pFeatureParaOut,
                         kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);

#endif /* _IMAGE_SENSOR_MT9P015_H */
