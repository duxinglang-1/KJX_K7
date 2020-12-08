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
 *   image_sensor_SIV120B.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================
 ****************************************************************************/

#ifndef _IMAGE_SENSOR_SIV120B_H
	#define _IMAGE_SENSOR_SIV120B_H

	#include "sensor_comm_def.h"

	//#define __SIV120B_DEBUG_TRACE__

#define SIV120B_IMAGE_SENSOR_VGA_WIDTH                  (640)
#define SIV120B_IMAGE_SENSOR_VGA_HEIGHT                 (480)

#define SIV120B_IMAGE_SENSOR_SXGA_WITDH                (1280) 
#define SIV120B_IMAGE_SENSOR_SXGA_HEIGHT               (1024)

#define SIV120B_PV_GRAB_START_X 		(0)
#define SIV120B_PV_GRAB_START_Y  		(1)
#define SIV120B_PV_GRAB_WIDTH			(SIV120B_IMAGE_SENSOR_VGA_WIDTH - (2*SIV120B_PV_GRAB_START_X))
#define SIV120B_PV_GRAB_HEIGHT			(SIV120B_IMAGE_SENSOR_VGA_HEIGHT - (2*SIV120B_PV_GRAB_START_Y))

#define SIV120B_FULL_GRAB_START_X   	(0)
#define SIV120B_FULL_GRAB_START_Y	  	(1)
#define SIV120B_FULL_GRAB_WIDTH			(SIV120B_IMAGE_SENSOR_VGA_WIDTH - (2*SIV120B_FULL_GRAB_START_X))
#define SIV120B_FULL_GRAB_HEIGHT		(SIV120B_IMAGE_SENSOR_VGA_HEIGHT - (2*SIV120B_FULL_GRAB_START_Y))

// sensor's I2C read/write IDs    
#define SIV120B_WRITE_ID                (0x66)
#define SIV120B_READ_ID                 (0x67)


/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define SIV120B_PERIOD_PIXEL_NUMS          (652 + 144 + 3)/* Active + HST + 3 */
#define SIV120B_PERIOD_LINE_NUMS           (490 + 9)      /* Active + 9 */

#define SIV120B_BLANK_REGISTER_LIMITATION   (0xFFF)

/*50Hz,60Hz*/
#define SIV120B_NUM_50HZ    50 * 2
#define SIV120B_NUM_60HZ    60 * 2

/* FRAME RATE UNIT */
#define SIV120B_FRAME_RATE_UNIT               10

/* MAX CAMERA FRAME RATE */
#define SIV120B_MAX_CAMERA_FPS         (SIV120B_FRAME_RATE_UNIT * 30)

/* ===============================================================================
   ========================= No Changing The Macro Below =========================
   ===============================================================================
*/

#ifdef __SIV120B_DEBUG_TRACE__
#include "kal_trace.h"

#define SIV120B_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[SIV120B]"__VA_ARGS__)
#else
#define SIV120B_TRACE(...)
#endif

	#define SIV120B_SET_RST_LOW                   CamRstPinCtrl(SIV120BSensor.SensorIdx, 0)
	#define SIV120B_SET_RST_HIGH                  CamRstPinCtrl(SIV120BSensor.SensorIdx, 1)
	#define SIV120B_SET_PDN_LOW                   CamPdnPinCtrl(SIV120BSensor.SensorIdx, 0)
	#define SIV120B_SET_PDN_HIGH                  CamPdnPinCtrl(SIV120BSensor.SensorIdx, 1)


typedef struct
{
    kal_bool BypassAe;
    kal_bool BypassAwb;
	
    kal_bool CapState; /* KAL_TRUE: in capture state, else in preview state */
    kal_bool PvMode; /* KAL_TRUE: preview size output, else full size output */
	
    kal_uint32 InternalClock; /* internal clock which using process pixel(for exposure) */
    kal_uint32 Pclk; /* output clock which output to baseband */
    kal_uint32 Gain; /* base on 0x40 */
    kal_uint32 Shutter; /* unit is (linelength / internal clock) s */

	kal_uint16 MinFrameRate;	/* 150 means 15.0fps. */
	kal_uint16 MaxFrameRate;	/* 300 means 30.0fps. */
	
    kal_uint32 dummy_lines;
    kal_uint32 dummy_pixels;

	kal_uint32 curr_frame_time;	/* It's get from the TG Int. */
	
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
	CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq; /* SIV120B_50HZ or SIV120B_60HZ for 50Hz/60Hz */
} SIV120B_SENSOR_ST;


kal_uint32 SIV120BPowerOn(void);
MM_ERROR_CODE_ENUM SIV120BSensorClose(void);

MM_ERROR_CODE_ENUM SIV120BSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM SIV120BWebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);


#endif	/* #ifndef _IMAGE_SENSOR_SIV120B_H */
