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
 *   image_sensor_HI253.h
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
 *  
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

#ifndef _IMAGE_SENSOR_HI253_H
#define _IMAGE_SENSOR_HI253_H

#include "sensor_comm_def.h"

#define HI253_SLAVE_ADDR                      (0x40)

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
#endif

 /* Sesnor Pixel/Line Numbers in One Period */	 
#define HI253_PV_PERIOD_PIXEL_NUMS			(824)		/* Default preview line length */
#define HI253_PV_PERIOD_LINE_NUMS			(632)		/* Default preview frame length */
#define HI253_FULL_PERIOD_PIXEL_NUMS		(1640)		/* Default full size line length */
#define HI253_FULL_PERIOD_LINE_NUMS 		(1248)		/* Default full size frame length */
 
 /* Sensor Exposure Line Limitation */
#define HI253_PV_EXPOSURE_LIMITATION		(0x750)
#define HI253_FULL_EXPOSURE_LIMITATION	(0xfa0)
 
 /* Sensor Preview Size (3M: 1024x768 or 640x480, 2M: 800x600, 1,3M: 640x512, VGA: 640x480, CIF: 352x288) */
#define HI253_IMAGE_SENSOR_PV_WIDTH 		(800)
#define HI253_IMAGE_SENSOR_PV_HEIGHT		(600)
 /* Sensor Capture Size (3M: 2048x1536, 2M: 1600x1200, 1.3M: 1280x1024, VGA: 640x480, CIF: 352x288) */
#define HI253_IMAGE_SENSOR_FULL_WIDTH		(1600)
#define HI253_IMAGE_SENSOR_FULL_HEIGHT	(1200)
 
 /* Config the ISP grab start x & start y, Config the ISP grab width & height */
#define HI253_PV_GRAB_START_X				(1+4+8)
#define HI253_PV_GRAB_START_Y				(1)
#define HI253_PV_GRAB_WIDTH 				(HI253_IMAGE_SENSOR_PV_WIDTH - 8 - 8)
#define HI253_PV_GRAB_HEIGHT				(HI253_IMAGE_SENSOR_PV_HEIGHT - 6)
 
#define HI253_FULL_GRAB_START_X 			(1)
#define HI253_FULL_GRAB_START_Y 			(1)
#define HI253_FULL_GRAB_WIDTH				(HI253_IMAGE_SENSOR_FULL_WIDTH - 16)
#define HI253_FULL_GRAB_HEIGHT			(HI253_IMAGE_SENSOR_FULL_HEIGHT - 12)



 /* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define HI253_PERIOD_PIXEL_NUMS               (652 + 147 + 1)/* Active + HST + 1 */
#define HI253_PERIOD_LINE_NUMS                (492 + 9)      /* Active + 9 */

#define HI253_BLANK_REGISTER_LIMITATION       0x3FF

/*50Hz,60Hz*/
#define HI253_NUM_50HZ                        (50 * 2)
#define HI253_NUM_60HZ                        (60 * 2)

/* FRAME RATE UNIT */
#define HI253_FRAME_RATE_UNIT                 (10)

/* MAX CAMERA FRAME RATE */
#define HI253_MAX_CAMERA_FPS                  (HI253_FRAME_RATE_UNIT * 30)
 
MM_ERROR_CODE_ENUM HI253SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM HI253WebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
#endif /* _IMAGE_SENSOR_H */ 
