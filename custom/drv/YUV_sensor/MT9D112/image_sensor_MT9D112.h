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
 *   image_sensor_MT9D112.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
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
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

#ifndef _IMAGE_SENSOR_MT9D112_H
#define _IMAGE_SENSOR_MT9D112_H

#include "sensor_comm_def.h"

#include "isp_if.h"
#include "drv_features.h"
//#include "sensor_struct.h"


#define MT9D112_SLAVE_ADDR                      (0x78)
#define MT9D112_SLAVE1_ADDR                      (0x7A)


/* SENSOR REGISTER DEFINE */
#define MT9D112_ID_REG                          (0x3000)
//#define MT9D112_INFO_REG                        (0x02)
 
/* sensor size */
//#define MT9D112_IMAGE_SENSOR_VGA_WIDTH          (600)
//#define MT9D112_IMAGE_SENSOR_VGA_HEIGHT         (800)
//#define MT9D112_IMAGE_SENSOR_SXVGA_WITDH        (1280) 
//#define MT9D112_IMAGE_SENSOR_SXVGA_HEIGHT       (1024)

 /* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
//#define MT9D112_PERIOD_PIXEL_NUMS               (652 + 147 + 1)/* Active + HST + 1 */
//#define MT9D112_PERIOD_LINE_NUMS                (492 + 9)      /* Active + 9 */

#define MT9D112_BLANK_REGISTER_LIMITATION       0x3FF

/*50Hz,60Hz*/
#define MT9D112_NUM_50HZ                        (50 )
#define MT9D112_NUM_60HZ                        (60 )

/* FRAME RATE UNIT */
#define MT9D112_FRAME_RATE_UNIT                 (10)

/* MAX CAMERA FRAME RATE */
#define MT9D112_MAX_CAMERA_FPS                  (MT9D112_FRAME_RATE_UNIT * 30)
 
MM_ERROR_CODE_ENUM MT9D112SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM MT9D112WebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);



//------------------------Engineer mode---------------------------------
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES)))	
#if (!(defined(__CAMERA_NVRAM_REDUCTION__) && defined(DRV_ISP_6225_SERIES)))

#define MT9D112_FACTORY_START_ADDR  0
#define MT9D112_ENGINEER_START_ADDR 0

typedef enum MT9D112_group_enum
{
  MT9D112_CMMCLK_CURRENT = 0,
  MT9D112_GROUP_TOTAL_NUMS
} MT9D112_FACTORY_GROUP_ENUM;

typedef enum MT9D112_register_index
{
  MT9D112_SENSOR_BASEGAIN = MT9D112_FACTORY_START_ADDR,
  MT9D112_FACTORY_END_ADDR
} MT9D112_FACTORY_REGISTER_INDEX;

typedef enum MT9D112_engineer_index
{
  MT9D112_CMMCLK_CURRENT_INDEX = MT9D112_ENGINEER_START_ADDR,
  MT9D112_ENGINEER_END
} MT9D112_FACTORY_ENGINEER_INDEX;

//typedef struct _sensor_data_struct
//{
//  sensor_reg_struct reg[MT9D112_ENGINEER_END];
//  sensor_reg_struct cct[MT9D112_FACTORY_END_ADDR];
//} sensor_data_struct;
#endif
#endif
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
#endif
/* SENSOR FULL/PV SIZE */
#define MT9D112_IMAGE_SENSOR_FULL_WIDTH_DRV   1600
#define MT9D112_IMAGE_SENSOR_FULL_HEIGHT_DRV  1200
#define MT9D112_IMAGE_SENSOR_PV_WIDTH_DRV     (MT9D112_IMAGE_SENSOR_FULL_WIDTH_DRV / 2)
#define MT9D112_IMAGE_SENSOR_PV_HEIGHT_DRV    (MT9D112_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2)

/* SENSOR HORIZONTAL/VERTICAL ACTIVE REGION */
#define MT9D112_IMAGE_SENSOR_FULL_HACTIVE     MT9D112_IMAGE_SENSOR_FULL_WIDTH_DRV /* 1600 */
#define MT9D112_IMAGE_SENSOR_FULL_VACTIVE     MT9D112_IMAGE_SENSOR_FULL_HEIGHT_DRV /* 1200 */
#define MT9D112_IMAGE_SENSOR_PV_HACTIVE       MT9D112_IMAGE_SENSOR_PV_WIDTH_DRV /* 800 */
#define MT9D112_IMAGE_SENSOR_PV_VACTIVE       MT9D112_IMAGE_SENSOR_PV_HEIGHT_DRV /* 600 */

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#define MT9D112_IMAGE_SENSOR_FULL_HBLANKING   684 /* MT6253 capture frame rate limit to 9fps */
#else
#define MT9D112_IMAGE_SENSOR_FULL_HBLANKING   484
#endif
#define MT9D112_IMAGE_SENSOR_FULL_VBLANKING   65
#define MT9D112_IMAGE_SENSOR_PV_HBLANKING     751
#define MT9D112_IMAGE_SENSOR_PV_VBLANKING     61

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define MT9D112_FULL_PERIOD_PIXEL_NUMS        (MT9D112_IMAGE_SENSOR_FULL_HACTIVE + MT9D112_IMAGE_SENSOR_FULL_HBLANKING) /* 53: 2284, other: 2084 */
#define MT9D112_FULL_PERIOD_LINE_NUMS         (MT9D112_IMAGE_SENSOR_FULL_VACTIVE + MT9D112_IMAGE_SENSOR_FULL_VBLANKING) /* 1265 */
#define MT9D112_PV_PERIOD_PIXEL_NUMS          (MT9D112_IMAGE_SENSOR_PV_HACTIVE + MT9D112_IMAGE_SENSOR_PV_HBLANKING) /* 1551 */
#define MT9D112_PV_PERIOD_LINE_NUMS           (MT9D112_IMAGE_SENSOR_PV_VACTIVE + MT9D112_IMAGE_SENSOR_PV_VBLANKING) /* 661 */

/* SENSOR START/END POSITION */
#define MT9D112_FULL_X_START                  8
#define MT9D112_FULL_Y_START                  6
#define MT9D112_IMAGE_SENSOR_FULL_WIDTH       (MT9D112_IMAGE_SENSOR_FULL_HACTIVE - MT9D112_FULL_X_START * 2) /* 1584 */
#define MT9D112_IMAGE_SENSOR_FULL_HEIGHT      (MT9D112_IMAGE_SENSOR_FULL_VACTIVE - MT9D112_FULL_Y_START * 2) /* 1188 */
#define MT9D112_PV_X_START                    (MT9D112_FULL_X_START / 2) /* 4 */
#define MT9D112_PV_Y_START                    (MT9D112_FULL_Y_START / 2) /* 3 */
#define MT9D112_IMAGE_SENSOR_PV_WIDTH         (MT9D112_IMAGE_SENSOR_PV_HACTIVE - MT9D112_PV_X_START * 2) /* 792 */
#define MT9D112_IMAGE_SENSOR_PV_HEIGHT        (MT9D112_IMAGE_SENSOR_PV_VACTIVE - MT9D112_PV_Y_START * 2) /* 594 */

/* AE TARGET ZERO when EV = 0. MUST BE > 40 !!! */
#define MT9D112_AE_TARGET_ZERO                68

/* ANALOG GAIN BASE */
#define MT9D112_ANALOG_GAIN_BASE              0x10 /* 1x: reg / 16 */

/* LIMIT OF ANALOG GAIN: if too large will cause yellow frame!!! */
#define MT9D112_MAX_ANALOG_GAIN               (MT9D112_ANALOG_GAIN_BASE * 7.5) /* max: 8x */

/* 50HZ/60HZ */
//#define MT9D112_NUM_50HZ                      50
//#define MT9D112_NUM_60HZ                      60

/* SENSOR READ/WRITE ID */
#define MT9D112_SLV1_WRITE_ID                 0x78
#define MT9D112_SLV1_READ_ID                  0x79
#define MT9D112_SLV2_WRITE_ID                 0x7A
#define MT9D112_SLV2_READ_ID                  0x7B

// #define MT9D112_USE_48M /* noly use in MT622X series */

#define MT9D112_HW_SCCB /* if not define, means use SW SCCB */

#ifdef MT9D112_HW_SCCB
#define MT9D112_SCCB_FAST_MODE_SPEED          350 /* unit: Kb */
#else
/* SENSOR I2C DELAY*/
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define MT9D112_SENSOR_I2C_DELAY              60
#else
#define MT9D112_SENSOR_I2C_DELAY              22
#endif

/* I2C FAIL TRY NUMBER */
#define MT9D112_MAX_I2C_FAIL_TRY_NO           10

/*#define MT9D112_I2C_START_TRANSMISSION \
{ \
  volatile kal_uint32 j; \
  SET_SCCB_CLK_OUTPUT; \
  SET_SCCB_DATA_OUTPUT; \
  SET_SCCB_DATA_HIGH; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_HIGH; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_DATA_LOW; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_LOW; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
}

#define MT9D112_I2C_STOP_TRANSMISSION \
{ \
  volatile kal_uint32 j; \
  SET_SCCB_CLK_OUTPUT; \
  SET_SCCB_DATA_OUTPUT; \
  SET_SCCB_CLK_LOW; \
  SET_SCCB_DATA_LOW; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_CLK_HIGH; \
  for (j = MT9D112_SENSOR_I2C_DELAY; j > 0; j--); \
  SET_SCCB_DATA_HIGH; \
}
*/

#endif
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
#ifndef MT9D112_HW_SCCB
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
#endif
/* FRAME RATE UNIT */
#define MT9D112_FPS(x)                        (10 * (x))

/* frame rate please refer to preview function */

#endif /* _IMAGE_SENSOR_H */ 
