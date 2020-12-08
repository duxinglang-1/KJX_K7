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
 *   image_sensor_MT9D115.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Image sensor driver declare and macro define in the header file.
 *
 * Author:
 * -------
 *   
 *
 *=============================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================
 ******************************************************************************/

#ifndef _IMAGE_SENSOR_MT9D115_H
	#define _IMAGE_SENSOR_MT9D115_H

	#include "sensor_comm_def.h"

	/* Debug use only. */
	//#define __MT9D115_DEBUG_TRACE__

	/* This used for debug phase use only, to speed up the initial setting modify, 
		NOTICE: It need to be marked when MP release version, or else it will effect the enter
			camera time and waste some ram. */
	//#define MT9D115_LOAD_FROM_T_FLASH

	/* HW Produce I2C Signal to Control Sensor Register. */
	//#define MT9D115_HW_SCCB

	/* Sensor Read/Write ID */
	#define MT9D115_WRITE_ID			(0x78)
	//#define MT9D115_WRITE_ID_1			(0xFF)
	//#define MT9D115_WRITE_ID_2			(0xFF)
	//#define MT9D115_WRITE_ID_3			(0xFF)
	
	//#define MT9D115_I2C_8_8			/* I2C Register Address 8bits, Register Values 8bits */
	//#define MT9D115_I2C_8_16			/* I2C Register Address 8bits, Register Values 16bits */
	//#define MT9D115_I2C_16_8				/* I2C Register Address 16bits, Register Values 8bits */
	//#define MT9D115_I2C_16_16			/* I2C Register Address 16bits, Register Values 16bits */

	/*Important: If you use Nor Flash with Paging Mode PSRAM, you should use this Macro*/
	//#define MT9D115_MCP_NOR_PAGING_MODE_PSRAM

	/* Sesnor Pixel/Line Numbers in One Period */	
	#define MT9D115_PV_PERIOD_PIXEL_NUMS    		(1368)  		/* Default preview line length */
	#define MT9D115_PV_PERIOD_LINE_NUMS     		(691)   	/* Default preview frame length */
	#define MT9D115_FULL_PERIOD_PIXEL_NUMS  		(2116)  	/* Default full size line length */
	#define MT9D115_FULL_PERIOD_LINE_NUMS   		(1293)  	/* Default full size frame length */
	
	/* Sensor Exposure Line Limitation */
	#define MT9D115_PV_EXPOSURE_LIMITATION      	(618)
	#define MT9D115_FULL_EXPOSURE_LIMITATION    	(1236)

	/* Sensor Preview Size (3M: 1024x768 or 640x480, 2M: 800x600, 1,3M: 640x512, VGA: 640x480, CIF: 352x288) */
	#define MT9D115_IMAGE_SENSOR_PV_WIDTH   		(800)
	#define MT9D115_IMAGE_SENSOR_PV_HEIGHT  		(600)
	/* Sensor Capture Size (3M: 2048x1536, 2M: 1600x1200, 1.3M: 1280x1024, VGA: 640x480, CIF: 352x288) */
	#define MT9D115_IMAGE_SENSOR_FULL_WIDTH     	(1600)
	#define MT9D115_IMAGE_SENSOR_FULL_HEIGHT    	(1200)

	/* Config the ISP grab start x & start y, Config the ISP grab width & height */
	#define MT9D115_PV_GRAB_START_X 				(4)
	#define MT9D115_PV_GRAB_START_Y  				(3)
	#define MT9D115_PV_GRAB_WIDTH					(MT9D115_IMAGE_SENSOR_PV_WIDTH - 8)
	#define MT9D115_PV_GRAB_HEIGHT				(MT9D115_IMAGE_SENSOR_PV_HEIGHT - 6)

	#define MT9D115_FULL_GRAB_START_X   			(8)
	#define MT9D115_FULL_GRAB_START_Y	  			(6)
	#define MT9D115_FULL_GRAB_WIDTH				(MT9D115_IMAGE_SENSOR_FULL_WIDTH - 16)
	#define MT9D115_FULL_GRAB_HEIGHT				(MT9D115_IMAGE_SENSOR_FULL_HEIGHT - 12)

	
/************************************************************************/

#define MT9D115_FRAME_RATE_UNIT               10

kal_uint32 MT9D115PowerOn(void);
MM_ERROR_CODE_ENUM MT9D115SensorClose(void);

MM_ERROR_CODE_ENUM MT9D115SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM MT9D115WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);

/************************************************************************/


#endif	/* _IMAGE_SENSOR_MT9D115_H */
