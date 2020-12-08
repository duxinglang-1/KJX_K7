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
 *   image_sensor_HM0356.h
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

#ifndef _IMAGE_SENSOR_HM0356_H
#define _IMAGE_SENSOR_HM0356_H

#include "sensor_comm_def.h"

#define HM0356_SLAVE_ADDR                      (0x68)

/* SENSOR REGISTER DEFINE */
#define HM0356_ID_REG                          (0x01)
#define HM0356_INFO_REG                        (0x02)
 
/* sensor size */


/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define HM0356_MAX_FRAME_RATE  (15)    // Limitation for MPEG4 Encode Only
#define HM0356_MIN_FRAME_RATE  (12)    // Limitation for Camera Preiview

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define HM0356_FULL_PERIOD_PIXEL_NUMS  (648)  // default pixel#(w/o dummy pixels) in UXGA mode
#define HM0356_FULL_PERIOD_LINE_NUMS   (488)  // default line#(w/o dummy lines) in UXGA mode
#define HM0356_PV_PERIOD_PIXEL_NUMS    (648)  // default pixel#(w/o dummy pixels) in SVGA mode
#define HM0356_PV_PERIOD_LINE_NUMS	   (488)   // default line#(w/o dummy lines) in SVGA mode

/* SENSOR EXPOSURE LINE LIMITATION */
//#define HM0356_FULL_EXPOSURE_LIMITATION    (640)
//#define HM0356_PV_EXPOSURE_LIMITATION	   (480)

// SENSOR UXGA SIZE
#define HM0356_IMAGE_SENSOR_FULL_WIDTH	   (640)
#define HM0356_IMAGE_SENSOR_FULL_HEIGHT    (480)

// SENSOR VGA SIZE
#define HM0356_IMAGE_SENSOR_PV_WIDTH   (640)
#define HM0356_IMAGE_SENSOR_PV_HEIGHT  (480)

//Capture image size
//#define HM0356_IMAGE_SENSOR_2M_WIDTH	(1600)
//#define HM0356_IMAGE_SENSOR_2M_HEIGHT	 (1200)

// SETUP TIME NEED TO BE INSERTED
//#define HM0356_IMAGE_SENSOR_PV_INSERTED_PIXELS (390)
//#define HM0356_IMAGE_SENSOR_PV_INSERTED_LINES  (9 - 6)

//#define HM0356_IMAGE_SENSOR_FULL_INSERTED_PIXELS   (248)
//#define HM0356_IMAGE_SENSOR_FULL_INSERTED_LINES    (11 - 2)


#define HM0356_IMAGE_SENSOR_VGA_WIDTH          (640)
#define HM0356_IMAGE_SENSOR_VGA_HEIGHT         (480)


 /* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
//#define HM0356_PERIOD_PIXEL_NUMS               (652 + 147 + 1)/* Active + HST + 1 */
//#define HM0356_PERIOD_LINE_NUMS                (492 + 9)      /* Active + 9 */

#define HM0356_BLANK_REGISTER_LIMITATION       0x3FF

/*50Hz,60Hz*/
#define HM0356_NUM_50HZ                        (50 * 2)
#define HM0356_NUM_60HZ                        (60 * 2)

/* FRAME RATE UNIT */
#define HM0356_FRAME_RATE_UNIT                 (10)

/* MAX CAMERA FRAME RATE */
#define HM0356_MAX_CAMERA_FPS                  (HM0356_FRAME_RATE_UNIT * 30)
 
MM_ERROR_CODE_ENUM HM0356SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM HM0356WebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
typedef struct _SENSOR_INIT_INFO
{
	kal_uint8 address;
	kal_uint8 data;
}HM0356_SENSOR_INIT_INFO;




#endif /* _IMAGE_SENSOR_H */ 
