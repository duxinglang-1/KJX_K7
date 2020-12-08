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
 *   image_sensor.h
 *
 * Project:
 * --------
 *   MT6219
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV2655_H
#define _IMAGE_SENSOR_OV2655_H

#include "sensor_comm_def.h"

//#define __OV2655_DEBUG_TRACE__

/* MAXIMUM EXPLOSURE LINES USED BY AE */
extern kal_uint16 OV2655_MAX_EXPOSURE_LINES;
extern kal_uint8  OV2655_MIN_EXPOSURE_LINES;

//#define OV2655_LOAD_FROM_T_FLASH
   
#define BANDING50_30HZ
// anti flicker = 50Hz, camera preview Frame rate Max to 30 Fps or 25Fps
// if defined=>30Fps, else, =>25Fps
// It doesn't do effect on anti filcker = 60Hz

 /* START GRAB PIXEL OFFSET */
#define IMAGE_SENSOR_START_GRAB_X		        2	// 0 or 1 recommended
#define IMAGE_SENSOR_START_GRAB_Y		        2	// 0 or 1 recommended

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define MAX_FRAME_RATE							15		// Limitation for MPEG4 Encode Only
#define MIN_FRAME_RATE							12

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV2655_FULL_PERIOD_PIXEL_NUMS  (1940)  // default pixel#(w/o dummy pixels) in UXGA mode
#define OV2655_FULL_PERIOD_LINE_NUMS   (1236)  // default line#(w/o dummy lines) in UXGA mode
#define OV2655_PV_PERIOD_PIXEL_NUMS    (970)  // default pixel#(w/o dummy pixels) in SVGA mode
#define OV2655_PV_PERIOD_LINE_NUMS     (618)   // default line#(w/o dummy lines) in SVGA mode

/* SENSOR EXPOSURE LINE LIMITATION */
#define OV2655_FULL_EXPOSURE_LIMITATION    (1236)
#define OV2655_PV_EXPOSURE_LIMITATION      (618)

/* SENSOR FULL SIZE */
#define OV2655_IMAGE_SENSOR_FULL_WIDTH	   (1600)
#define OV2655_IMAGE_SENSOR_FULL_HEIGHT	  (1200)


/* SENSOR PV SIZE */
#define OV2655_IMAGE_SENSOR_PV_WIDTH   (800)
#define OV2655_IMAGE_SENSOR_PV_HEIGHT  (600)

#define OV2655_VIDEO_QCIF_WIDTH   (176)
#define OV2655_VIDEO_QCIF_HEIGHT  (144)

#define OV2655_VIDEO_30FPS_FRAME_LENGTH   (0x29E)
#define OV2655_VIDEO_20FPS_FRAME_LENGTH   (0x3ED)
#define OV2655_VIDEO_15FPS_FRAME_LENGTH   (0x53C)
#define OV2655_VIDEO_10FPS_FRAME_LENGTH   (0x7DA)

// SETUP TIME NEED TO BE INSERTED
#define OV2655_IMAGE_SENSOR_PV_INSERTED_PIXELS (390)
#define OV2655_IMAGE_SENSOR_PV_INSERTED_LINES  (9 - 6)

#define OV2655_IMAGE_SENSOR_FULL_INSERTED_PIXELS   (248)
#define OV2655_IMAGE_SENSOR_FULL_INSERTED_LINES    (11 - 2)

#define OV2655_PV_DUMMY_PIXELS			(600)
#define OV2655_VIDEO__CIF_DUMMY_PIXELS  (100)
#define OV2655_VIDEO__QCIF_DUMMY_PIXELS (0)

/* SENSOR SCALER FACTOR */
#define PV_SCALER_FACTOR					    3
#define FULL_SCALER_FACTOR					    1


/* DUMMY NEEDS TO BE INSERTED */
/* SETUP TIME NEED TO BE INSERTED */


/* SENSOR READ/WRITE ID */
#define OV2655_WRITE_ID							    0x60
#define OV2655_READ_ID								0x61

kal_uint32 OV2655PowerOn(void);
MM_ERROR_CODE_ENUM OV2655SensorClose(void);

MM_ERROR_CODE_ENUM OV2655SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_OV2655.c
/* IMPORT FUNC */
MM_ERROR_CODE_ENUM OV5640WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);


#ifdef __OV2655_DEBUG_TRACE__
    #define OV2655_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[OV2655]"__VA_ARGS__)
#else
    #define OV2655_TRACE(...)
#endif  /* #ifdef __OV2655_DEBUG_TRACE__ */


#endif	/* #ifndef _IMAGE_SENSOR_SIV120B_H */

   
