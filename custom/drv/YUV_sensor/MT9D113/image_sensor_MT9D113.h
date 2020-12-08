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
 *   image_sensor_OV3640.h
 *
 * Project:
 * --------
 *   MAUI_sw
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_MT9D113_H
#define _IMAGE_SENSOR_MT9D113_H

#include "sensor_comm_def.h"


#define MT9D113_IMAGE_SENSOR_FULL_WIDTH_DRV   1600
#define MT9D113_IMAGE_SENSOR_FULL_HEIGHT_DRV  1200
#define MT9D113_IMAGE_SENSOR_PV_WIDTH_DRV     (MT9D113_IMAGE_SENSOR_FULL_WIDTH_DRV / 2)
#define MT9D113_IMAGE_SENSOR_PV_HEIGHT_DRV    (MT9D113_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2)

/* SENSOR HORIZONTAL/VERTICAL ACTIVE REGION */
#define MT9D113_IMAGE_SENSOR_FULL_HACTIVE     MT9D113_IMAGE_SENSOR_FULL_WIDTH_DRV /* 1600 */
#define MT9D113_IMAGE_SENSOR_FULL_VACTIVE     MT9D113_IMAGE_SENSOR_FULL_HEIGHT_DRV /* 1200 */
#define MT9D113_IMAGE_SENSOR_PV_HACTIVE       MT9D113_IMAGE_SENSOR_PV_WIDTH_DRV /* 800 */
#define MT9D113_IMAGE_SENSOR_PV_VACTIVE       MT9D113_IMAGE_SENSOR_PV_HEIGHT_DRV /* 600 */

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#define MT9D113_IMAGE_SENSOR_FULL_HBLANKING   634 /* MT6253 capture frame rate limit to 9fps */
#else
#define MT9D113_IMAGE_SENSOR_FULL_HBLANKING   380
#endif
#define MT9D113_IMAGE_SENSOR_FULL_VBLANKING   93
#if (defined(DRV_ISP_MT6236_HW_SUPPORT)||defined(MT6276))
#define MT9D113_IMAGE_SENSOR_PV_HBLANKING     1057
#else
#define MT9D113_IMAGE_SENSOR_PV_HBLANKING     550
#endif
#define MT9D113_IMAGE_SENSOR_PV_VBLANKING     91

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define MT9D113_FULL_PERIOD_PIXEL_NUMS        (MT9D113_IMAGE_SENSOR_FULL_HACTIVE + MT9D113_IMAGE_SENSOR_FULL_HBLANKING) /* 53: 2234, other: 1980 */
#define MT9D113_FULL_PERIOD_LINE_NUMS         (MT9D113_IMAGE_SENSOR_FULL_VACTIVE + MT9D113_IMAGE_SENSOR_FULL_VBLANKING) /* 1293 */
#define MT9D113_PV_PERIOD_PIXEL_NUMS          (MT9D113_IMAGE_SENSOR_PV_HACTIVE + MT9D113_IMAGE_SENSOR_PV_HBLANKING) /* 36: 1857, other: 1350 */
#define MT9D113_PV_PERIOD_LINE_NUMS           (MT9D113_IMAGE_SENSOR_PV_VACTIVE + MT9D113_IMAGE_SENSOR_PV_VBLANKING) /* 691 */

/* SENSOR START/END POSITION */
#define MT9D113_FULL_X_START                  8
#define MT9D113_FULL_Y_START                  6
#define MT9D113_IMAGE_SENSOR_FULL_WIDTH       (MT9D113_IMAGE_SENSOR_FULL_HACTIVE - MT9D113_FULL_X_START * 2) /* 1584 */
#define MT9D113_IMAGE_SENSOR_FULL_HEIGHT      (MT9D113_IMAGE_SENSOR_FULL_VACTIVE - MT9D113_FULL_Y_START * 2) /* 1188 */
#define MT9D113_PV_X_START                    (MT9D113_FULL_X_START / 2) /* 4 */
#define MT9D113_PV_Y_START                    (MT9D113_FULL_Y_START / 2) /* 3 */
#define MT9D113_IMAGE_SENSOR_PV_WIDTH         (MT9D113_IMAGE_SENSOR_PV_HACTIVE - MT9D113_PV_X_START * 2) /* 792 */
#define MT9D113_IMAGE_SENSOR_PV_HEIGHT        (MT9D113_IMAGE_SENSOR_PV_VACTIVE - MT9D113_PV_Y_START * 2) /* 594 */

/* AE TARGET ZERO when EV = 0 */
#define MT9D113_AE_TARGET_ZERO                67

/* ANALOG GAIN BASE */
#define MT9D113_ANALOG_GAIN_BASE              0x10 /* 1x: reg / 0x10 */

/* LIMIT OF ANALOG GAIN: if too large will cause yellow frame!!! */
#define MT9D113_MAX_ANALOG_GAIN               (MT9D113_ANALOG_GAIN_BASE * 10)

/* 50HZ/60HZ */
#define MT9D113_NUM_50HZ                      50
#define MT9D113_NUM_60HZ                      60

/* SUPPORT SENSOR VERSION */
#define MT9D113_REV2
#define MT9D113_REV3

/* SENSOR READ/WRITE ID */
#define MT9D113_SLV1_WRITE_ID                 0x78
#define MT9D113_SLV1_READ_ID                  0x79
#define MT9D113_SLV2_WRITE_ID                 0x7A
#define MT9D113_SLV2_READ_ID                  0x7B

#define MT9D113_HW_SCCB /* if no define, means use SW SCCB */

#ifdef MT9D113_HW_SCCB
#define MT9D113_SCCB_FAST_MODE_SPEED          350 /* unit: Kb */
#else
/* SENSOR I2C DELAY*/
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define MT9D113_SENSOR_I2C_DELAY              60
#else
#define MT9D113_SENSOR_I2C_DELAY              22
#endif

/* I2C FAIL TRY NUMBER */
#define MT9D113_MAX_I2C_FAIL_TRY_NO           10

#define MT9D113_I2C_START_TRANSMISSION \
{ \
  volatile kal_uint32 j; \
  SET_SCCB_CLK_OUTPUT; \
  SET_SCCB_DATA_OUTPUT; \
  SET_SCCB_DATA_HIGH; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_HIGH; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_DATA_LOW; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_LOW; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
}

#define MT9D113_I2C_STOP_TRANSMISSION \
{ \
  volatile kal_uint32 j; \
  SET_SCCB_CLK_OUTPUT; \
  SET_SCCB_DATA_OUTPUT; \
  SET_SCCB_CLK_LOW; \
  SET_SCCB_DATA_LOW; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_HIGH; \
  for (j = MT9D113_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_DATA_HIGH; \
}
#endif


/* if defined, means use internal DVDD, and DOVDD should be 1.8V */
//#define OV3640_INTERNAL_DVDD

/* if defined, means reduce gain and increase exposure to reduce noise when capture */
//#define OV3640_GAIN2SHUTTER

/* SENSOR PREVIEW/CAPTURE ISP CLOCK */


/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM MT9D113SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM MT9D113WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *in, void *out, kal_uint32 out_len, kal_uint32 *r_out_len);

#endif
