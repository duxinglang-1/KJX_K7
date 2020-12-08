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
 *   image_sensor_GC0307.h
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
 *
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#ifndef _IMAGE_SENSOR_GC0307_H
#define _IMAGE_SENSOR_GC0307_H

#include "sensor_comm_def.h"

#define GC0307_USE_13M_MCLK

#define GC0307_BLANK_REGISTER_LIMITATION    0x3FF

/* 1M RESOLUTION SIZE */
#define GC0307_IMAGE_SENSOR_1M_WIDTH        1280
#define GC0307_IMAGE_SENSOR_1M_HEIGHT       1024


/* SENSOR VGA SIZE */
#define GC0307_IMAGE_SENSOR_VGA_WIDTH       (640)
#define GC0307_IMAGE_SENSOR_VGA_HEIGHT      (480)

/* SETUP TIME NEED TO BE INSERTED */
#define GC0307_IMAGE_SENSOR_VGA_INSERTED_PIXELS     72//128//56//(0)   
#define GC0307_IMAGE_SENSOR_VGA_INSERTED_LINES      34//17//(1)

/*50Hz,60Hz*/
#define GC0307_NUM_50HZ                     50 * 2
#define GC0307_NUM_60HZ                     60 * 2

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define GC0307_PERIOD_PIXEL_NUMS            (640 + 50 + 4)/* Active + sh_delay + 1 */
#define GC0307_PERIOD_LINE_NUMS             (488)      /* Active */

/* FRAME RATE UNIT */
#define GC0307_FRAME_RATE_UNIT              10

#ifndef GC0307_USE_13M_MCLK
#define GC0307_SYSCLK                       (18000000)
#else
#define GC0307_SYSCLK                       (13000000)
#endif

#ifndef GC0307_USE_13M_MCLK
/* MAX CAMERA FRAME RATE */
#define GC0307_MAX_CAMERA_FPS               (GC0307_FRAME_RATE_UNIT * 20)

/* MED CAMERA FRAME RATE */
#define GC0307_MED_CAMERA_FPS               (GC0307_FRAME_RATE_UNIT * 15)

/* MIN CAMERA NORMAL FRAME RATE */
#define GC0307_MIN_CAMERA_NORMAL_FPS        (GC0307_FRAME_RATE_UNIT * 10)

/* MIN CAMERA NIGHT FRAME RATE */
#define GC0307_MIN_CAMERA_NIGHT_FPS         (GC0307_FRAME_RATE_UNIT * 5)

/* FIX VIDEO NORMAL FRAME RATE */
#define GC0307_FIX_VIDEO_NORMAL_FP          (GC0307_FRAME_RATE_UNIT * 20)

/* FIX VIDEO NIGHT MODE FRAME RATE */
#define GC0307_FIX_VIDEO_NIGHT_FPS          (GC0307_FRAME_RATE_UNIT * 10)
#else
/* MAX CAMERA FRAME RATE */
#define GC0307_MAX_CAMERA_FPS               (GC0307_FRAME_RATE_UNIT * 15)

/* MED CAMERA FRAME RATE */
#define GC0307_MED_CAMERA_FPS               (GC0307_FRAME_RATE_UNIT * 10)

/* MIN CAMERA NORMAL FRAME RATE */
#define GC0307_MIN_CAMERA_NORMAL_FPS        (GC0307_FRAME_RATE_UNIT * 7.5)

/* MIN CAMERA NIGHT FRAME RATE */
#define GC0307_MIN_CAMERA_NIGHT_FPS         (GC0307_FRAME_RATE_UNIT * 5)

/* FIX VIDEO NORMAL FRAME RATE */
#define GC0307_FIX_VIDEO_NORMAL_FPS         (GC0307_FRAME_RATE_UNIT * 15)

/* FIX VIDEO NIGHT MODE FRAME RATE */
#define GC0307_FIX_VIDEO_NIGHT_FPS          (GC0307_FRAME_RATE_UNIT * 7.5)
#endif

/* SENSOR I2C ADDRESS */
#define GC0307_SLAVE_ADDR                   (0x42)
#define GC0307_HW_SCCB_FAST_MODE_SPEED      (300) //The speed of sccb fast mode(Kb)

/* SENSOR I2C DELAY*/
#define GC0307_SENSOR_SW_SCCB_DELAY         38

MM_ERROR_CODE_ENUM GC0307SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM GC0307WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
#endif /* _IMAGE_SENSOR_H */
