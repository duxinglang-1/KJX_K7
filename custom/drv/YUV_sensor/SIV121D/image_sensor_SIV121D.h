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
 *   image_sensor_SIV121D.h
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

 *
 *=============================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 
 *=============================================================
 ****************************************************************************/

#ifndef _IMAGE_SENSOR_SIV121D_H
	#define _IMAGE_SENSOR_SIV121D_H

	#include "sensor_comm_def.h"

#define SIV121D_IMAGE_SENSOR_VGA_WIDTH                  (640)
#define SIV121D_IMAGE_SENSOR_VGA_HEIGHT                 (480)

#define SIV121D_IMAGE_SENSOR_SXGA_WITDH                (1280) 
#define SIV121D_IMAGE_SENSOR_SXGA_HEIGHT               (1024)

#define SIV121D_PV_GRAB_START_X 		(0)
#define SIV121D_PV_GRAB_START_Y  		(1)
#define SIV121D_PV_GRAB_WIDTH			(SIV121D_IMAGE_SENSOR_VGA_WIDTH - (2*SIV121D_PV_GRAB_START_X))
#define SIV121D_PV_GRAB_HEIGHT			(SIV121D_IMAGE_SENSOR_VGA_HEIGHT - (2*SIV121D_PV_GRAB_START_Y))

#define SIV121D_FULL_GRAB_START_X   	(0)
#define SIV121D_FULL_GRAB_START_Y	  	(1)
#define SIV121D_FULL_GRAB_WIDTH			(SIV121D_IMAGE_SENSOR_VGA_WIDTH - (2*SIV121D_FULL_GRAB_START_X))
#define SIV121D_FULL_GRAB_HEIGHT		(SIV121D_IMAGE_SENSOR_VGA_HEIGHT - (2*SIV121D_FULL_GRAB_START_Y))

#define SIV121D_SET_RESET_LOW		(REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
#define SIV121D_SET_RESET_HIGH		(REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
#define SIV121D_SET_PDN_LOW			(REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT)
#define SIV121D_SET_PDN_HIGH			(REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_POWER_ON_BIT)

// sensor's I2C read/write IDs    
#define SIV121D_WRITE_ID                (0x66)
#define SIV121D_READ_ID                 (0x67)

#if (!defined(MT6253E) && !defined(MT6253L))
#define SIV121D_HW_SCCB /* if no define, means use SW SCCB */
#endif
    
    /* SENSOR I2C DELAY*/
#define SIV121D_SENSOR_I2C_DELAY        0xE0


/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define SIV121D_PERIOD_PIXEL_NUMS          (652 + 144 + 3)/* Active + HST + 3 */
#define SIV121D_PERIOD_LINE_NUMS           (490 + 9)      /* Active + 9 */

#define SIV121D_BLANK_REGISTER_LIMITATION   0xFFF

/*50Hz,60Hz*/
#define SIV121D_NUM_50HZ    50 * 2
#define SIV121D_NUM_60HZ    60 * 2

/* FRAME RATE UNIT */
#define SIV121D_FRAME_RATE_UNIT               10
#define SIV121D_Min_Fps_Normal
#define SIV121D_Min_Fps_Night



/* MAX CAMERA FRAME RATE */
#define SIV121D_MAX_CAMERA_FPS         (SIV121D_FRAME_RATE_UNIT * 30)

kal_uint32 SIV121DPowerOn(void);
MM_ERROR_CODE_ENUM SIV121DSensorClose(void);

MM_ERROR_CODE_ENUM SIV121DSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM SIV121DWebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);

typedef struct
	{
		kal_uint8	sccb_write_id;
		kal_uint8	sccb_read_id;

		kal_uint32	pv_shutter;
		kal_uint32	pv_extra_shutter;
		kal_uint32	pv_sensor_gain;

		kal_uint32	pv_dummy_pixels;
		kal_uint32	pv_dummy_lines;
		kal_uint32	cap_dummy_pixels;
		kal_uint32	cap_dummy_lines;

		/* Preview & Capture Pixel Clock, 360 means 36.0MHz. Unit Multiple 10. */
		kal_uint32	preview_pclk;
		kal_uint32	capture_pclk;

		/* Video frame rate 300 means 30.0fps. Unit Multiple 10. */
		kal_uint32	video_frame_rate;	
		kal_bool CaptureMode;
		kal_bool PreviewMode;
		kal_bool NightMode;
		kal_uint8 curr_banding;
		kal_uint16	video_target_width;
		kal_uint16	video_target_height;

		kal_bool	MJPEG_encode_mode;			/* Motion JPEG */
		kal_bool	MPEG4_encode_mode;			/* MJPEG4 JPEG */
		kal_bool	FULLVIDEO_encode_mode;		/* 3G Video Call */
		
		
	}SIV121D_SENSOR_INFO_ST;

#endif	/* #ifndef _IMAGE_SENSOR_SIV121D_H */
