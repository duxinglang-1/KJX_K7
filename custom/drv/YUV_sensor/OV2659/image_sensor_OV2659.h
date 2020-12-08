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
 *   image_sensor_OV2659.h
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

#ifndef _IMAGE_SENSOR_OV2659_H
#define _IMAGE_SENSOR_OV2659_H

#include "sensor_comm_def.h"

//#define OV2659_LOAD_FROM_T_FLASH
#define OV2659_SLAVE_ADDR                      (0x60)

/* SENSOR REGISTER DEFINE */
#define OV2659_ID_REG                          (0x300A)
#define OV2659_INFO_REG                        (0x300B)
 
/* sensor size */
#define OV2659_IMAGE_SENSOR_SVGA_WIDTH          (800)
#define OV2659_IMAGE_SENSOR_SVGA_HEIGHT         (600)
#define OV2659_IMAGE_SENSOR_UVGA_WITDH        (1600) 
#define OV2659_IMAGE_SENSOR_UVGA_HEIGHT       (1200)

/* Sesnor Pixel/Line Numbers in One Period */	
#define OV2659_PV_PERIOD_PIXEL_NUMS    		(1300)  		/* Default preview line length */
#define OV2659_PV_PERIOD_LINE_NUMS     		(616)   	/* Default preview frame length */
#define OV2659_FULL_PERIOD_PIXEL_NUMS  		(1951)  	/* Default full size line length */
#define OV2659_FULL_PERIOD_LINE_NUMS   		(1232)  	/* Default full size frame length */

/* Sensor Exposure Line Limitation */
#define OV2659_PV_EXPOSURE_LIMITATION      	(616-4)
#define OV2659_FULL_EXPOSURE_LIMITATION    	(1232-4)

/* Config the ISP grab start x & start y, Config the ISP grab width & height */
#define OV2659_PV_GRAB_START_X 				(1)
#define OV2659_PV_GRAB_START_Y  			(1)
#define OV2659_PV_GRAB_WIDTH				(OV2659_IMAGE_SENSOR_SVGA_WIDTH - 8)
#define OV2659_PV_GRAB_HEIGHT				(OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 6)

#define OV2659_FULL_GRAB_START_X   			(1)
#define OV2659_FULL_GRAB_START_Y	  		(1)
#define OV2659_FULL_GRAB_WIDTH				(OV2659_IMAGE_SENSOR_UVGA_WITDH - 16)
#define OV2659_FULL_GRAB_HEIGHT				(OV2659_IMAGE_SENSOR_UVGA_HEIGHT - 12)

/*50Hz,60Hz*/
#define OV2659_NUM_50HZ                        (50 * 2)
#define OV2659_NUM_60HZ                        (60 * 2)

/* FRAME RATE UNIT */
#define OV2659_FRAME_RATE_UNIT                 (10)

/* MAX CAMERA FRAME RATE */
#define OV2659_MAX_CAMERA_FPS                  (OV2659_FRAME_RATE_UNIT * 30)
 
MM_ERROR_CODE_ENUM OV2659SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM OV2659WebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
#endif /* _IMAGE_SENSOR_H */ 
