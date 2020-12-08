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
 *   image_sensor_OV7670.c
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

#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"

OV7670_SENSOR_ST OV7670Sensor;


static kal_bool OV7670_VIDEO_MPEG4_QVGA=KAL_FALSE;//Soso Add for QVGA 10fps
static kal_bool OV7670_s_bMPEG4_encode_mode=KAL_FALSE, OV7670_s_bMJPEG_mode = KAL_FALSE; // to distinguish between MPEG4 and MJPEG
static kal_bool  OV7670_s_bNight_mode =KAL_FALSE; // to distinguish night mode or auto mode, default: auto mode setting
static CAL_CAMERA_BANDING_FREQ_ENUM  OV7670_s_bBanding_value = CAM_BANDING_50HZ; // to distinguish between 50HZ and 60HZ.
// Pclk, dummy, exposue related variables.
static kal_uint16 OV7670_dummy_pixels=0, OV7670_dummy_lines=0;
/* Image Sensor ID */
static kal_uint32 OV7670_video_frame_rate = 150;
static kal_uint16 OV7670_sensor_id=0;

//HAL
IMAGE_SENSOR_INDEX_ENUM SensorIdxOV7670;


void OV7670SetDummy(kal_uint16 pixels, kal_uint16 lines)
{
	CamWriteCmosSensor(0x2A, ((pixels&0xF00)>>4));
	CamWriteCmosSensor(0x2B, (pixels&0xFF));
	
	CamWriteCmosSensor(0x92, (lines&0xFF));
	CamWriteCmosSensor(0x93, ((lines&0xFF00)>>8));
}	/* set_OV7670_dummy */

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*	OV7670SetMirrorFlip
*
* DESCRIPTION
*	This function mirror, flip or mirror & flip the sensor output image.
*
*	IMPORTANT NOTICE: For some sensor, it need re-set the output order Y1CbY2Cr after
*	mirror or flip.
*
* PARAMETERS
*	1. kal_uint16 : horizontal mirror or vertical flip direction.
*
* RETURNS
*	None
*
*************************************************************************/
static void OV7670SetMirrorFlip(kal_uint16 image_mirror)
{
	switch (image_mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
			CamWriteCmosSensor(0x1E, 0x07);
			CamWriteCmosSensor(0x78, 0x04); // 0x78[6] must be equal to 0x1E[5]
		break;
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0x1E, 0x27);
			CamWriteCmosSensor(0x78, 0x44);  // 0x78[6] must be equal to 0x1E[5]
		break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0x1E, 0x17);
			CamWriteCmosSensor(0x78, 0x04);  // 0x78[6] must be equal to 0x1E[5]
		break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0x1E, 0x37);
			CamWriteCmosSensor(0x78, 0x44);  // 0x78[6] must be equal to 0x1E[5]
		break;
	}
}

kal_uint16 OV7670SetVideoFrameRate(kal_uint32 frame_rate)
{
	/*The real frame rate need /10*/
	kal_uint32 line_length = OV7670_VGA_PERIOD_PIXEL_NUMS;
	kal_uint32 frame_length = OV7670_VGA_PERIOD_LINE_NUMS;
	kal_uint16 night_mode = CamReadCmosSensor(0x3B);
	kal_uint32 sensor_pclk = 0;

	sensor_pclk = 240;
	
	frame_length = sensor_pclk*100000*10/frame_rate/((OV7670_VGA_PERIOD_PIXEL_NUMS + OV7670_dummy_pixels) * 2);

	if (frame_length < OV7670_VGA_PERIOD_LINE_NUMS)
	{
		frame_length = OV7670_VGA_PERIOD_LINE_NUMS;

		OV7670_TRACE("Warining!!! Target frame rate exeed sensor limitation: tar=%d, lim=%d", \
			frame_rate, sensor_pclk*100000*10 / line_length*2 / frame_length);

		frame_rate = sensor_pclk*100000*10 / ((OV7670_VGA_PERIOD_PIXEL_NUMS + OV7670_dummy_pixels) * 2) / (OV7670_VGA_PERIOD_LINE_NUMS + OV7670_dummy_lines);
	}
	
	OV7670_dummy_lines = frame_length - OV7670_VGA_PERIOD_LINE_NUMS;
	OV7670SetDummy(OV7670_dummy_pixels, OV7670_dummy_lines);

	OV7670_TRACE("Dummy pixels=%d, Dummy lines = %d", OV7670_dummy_pixels, OV7670_dummy_lines);

	/* Fix frame rate, limit the max exposure time to frame length. */
	CamWriteCmosSensor(0x3B,(night_mode&0x1F)); // fixed frame rate
	CamWriteCmosSensor(0x2d, 0); // if not set to zero, maybe AE osillation
	CamWriteCmosSensor(0x2e, 0);

	OV7670_video_frame_rate = frame_rate;
}

kal_uint16 OV7670SetBandingFreq(kal_uint32 Banding)
{
	kal_uint32 base_shutter = 0;
	kal_uint32 shutter_step = 0;

	switch (Banding)
	{
	case CAM_BANDING_50HZ:
		base_shutter = OV7670Sensor.Pclk / ((OV7670_VGA_PERIOD_PIXEL_NUMS + OV7670_dummy_pixels) * 2) / 100;
		break;
		
	case CAM_BANDING_60HZ:
		base_shutter = OV7670Sensor.Pclk / ((OV7670_VGA_PERIOD_PIXEL_NUMS + OV7670_dummy_pixels) * 2) / 120;
		break;
		
	default:
		/* Enable Auto Anti-Flicker if the sensor support it. */
		return KAL_FALSE;
	}

	CamWriteCmosSensor(0x9E, base_shutter);

	shutter_step = ((OV7670_VGA_PERIOD_LINE_NUMS + OV7670_dummy_lines) / base_shutter) - 1;
	CamWriteCmosSensor(0xAB, shutter_step);

	OV7670_TRACE("Banding[0:50, 1:60]=%d, base_shutter=%x, shutter_step=%d", Banding, base_shutter, shutter_step);
}


/*************************************************************************
* FUNCTION
*    OV7670AeEnable
*
* DESCRIPTION
*    disable/enable AE
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670AeEnable(kal_bool Enable)
{
  	kal_uint16 temp_reg = 0;

	if (OV7670Sensor.BypassAe)
    {
        Enable = KAL_FALSE;
    }
	
	temp_reg = CamReadCmosSensor(0x13);
	
  	if (Enable)	
	{
		CamWriteCmosSensor(0x13, (temp_reg | 0x05));  // Turn ON AEC/AGC/AWB
	}
	else
	{
		CamWriteCmosSensor(0x13, (temp_reg&(~0x05)));  // Turn ON AEC/AGC/AWB
	}

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7670AwbEnable
*
* DESCRIPTION
*    disable/enable awb
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670AwbEnable(kal_bool Enable)
{
	kal_uint16 temp_reg = 0;

	if (OV7670Sensor.BypassAwb)
    {
        Enable = KAL_FALSE;
    }
	
	temp_reg = CamReadCmosSensor(0x13);
	
  	if (Enable)	
	{
		CamWriteCmosSensor(0x13, (temp_reg | 0x02));  // Turn ON AEC/AGC/AWB
	}
	else
	{
		CamWriteCmosSensor(0x13, (temp_reg&(~0x02)));  // Turn ON AEC/AGC/AWB
	}

  return MM_ERROR_NONE;
}

void OV7670InitializeSetting(void)
{
	CamWriteCmosSensor(0x11,0x80);
    CamWriteCmosSensor(0x3a,0x0C);
    CamWriteCmosSensor(0x3D,0xC0);
    CamWriteCmosSensor(0x12,0x00);
    CamWriteCmosSensor(0x15,0x40);
    
    CamWriteCmosSensor(0x17,0x13);
    CamWriteCmosSensor(0x18,0x63);
//    CamWriteCmosSensor(0x18,0x01);
    CamWriteCmosSensor(0x32,0xbF);
    CamWriteCmosSensor(0x19,0x02);
    CamWriteCmosSensor(0x1a,0x7a);
    CamWriteCmosSensor(0x03,0x0a);
    
    CamWriteCmosSensor(0x0c,0x00);
    CamWriteCmosSensor(0x3e,0x00);
    CamWriteCmosSensor(0x70,0x3a);
    CamWriteCmosSensor(0x71,0x35);
    CamWriteCmosSensor(0x72,0x11);
    CamWriteCmosSensor(0x73,0xf0);
    CamWriteCmosSensor(0xa2,0x02);

// add by joe ovt 12/14/2006
    CamWriteCmosSensor(0x7a,0x20);
    CamWriteCmosSensor(0x7b,0x03);
    CamWriteCmosSensor(0x7c,0x0a);
    CamWriteCmosSensor(0x7d,0x1a);
    CamWriteCmosSensor(0x7e,0x3f);
    CamWriteCmosSensor(0x7f,0x4e);
    CamWriteCmosSensor(0x80,0x5b);
    CamWriteCmosSensor(0x81,0x68);
    CamWriteCmosSensor(0x82,0x75);
    CamWriteCmosSensor(0x83,0x7f);
    CamWriteCmosSensor(0x84,0x89);
    CamWriteCmosSensor(0x85,0x9a);
    CamWriteCmosSensor(0x86,0xa6);
    CamWriteCmosSensor(0x87,0xbd);
    CamWriteCmosSensor(0x88,0xd3);
    CamWriteCmosSensor(0x89,0xe8);

    CamWriteCmosSensor(0x13,0xe0);
    CamWriteCmosSensor(0x00,0x00);
    CamWriteCmosSensor(0x10,0x00);
    CamWriteCmosSensor(0x0d,0x40);
    CamWriteCmosSensor(0x14,0x28);
    CamWriteCmosSensor(0xa5,0x02);  
    CamWriteCmosSensor(0xab,0x02);  
    CamWriteCmosSensor(0x24,0x68);
    CamWriteCmosSensor(0x25,0x58);
    CamWriteCmosSensor(0x26,0xc2);   //e3
    CamWriteCmosSensor(0x9f,0x78);
    CamWriteCmosSensor(0xa0,0x68);
    CamWriteCmosSensor(0xa1,0x03);
    CamWriteCmosSensor(0xa6,0xD8);
    CamWriteCmosSensor(0xa7,0xD8);
    CamWriteCmosSensor(0xa8,0xf0);
    CamWriteCmosSensor(0xa9,0x90);
    CamWriteCmosSensor(0xaa,0x14);
    CamWriteCmosSensor(0x13,0xe5);
    
    CamWriteCmosSensor(0x0e,0x61);
    CamWriteCmosSensor(0x0f,0x4b);
    CamWriteCmosSensor(0x16,0x02);
    CamWriteCmosSensor(0x1e,0x07);
    CamWriteCmosSensor(0x21,0x02);
    CamWriteCmosSensor(0x22,0x91);
    CamWriteCmosSensor(0x29,0x07);
    CamWriteCmosSensor(0x33,0x0b);
    CamWriteCmosSensor(0x35,0x0b);
    CamWriteCmosSensor(0x37,0x1d);
    CamWriteCmosSensor(0x38,0x71);
    CamWriteCmosSensor(0x39,0x2a);
    CamWriteCmosSensor(0x3c,0x78);
    CamWriteCmosSensor(0x4d,0x40);
    CamWriteCmosSensor(0x4e,0x20);
    CamWriteCmosSensor(0x69,0x00);
    CamWriteCmosSensor(0x6b,0x0a);
    CamWriteCmosSensor(0x74,0x10);	

    CamWriteCmosSensor(0x8d,0x4f);
    CamWriteCmosSensor(0x8e,0x00);
    CamWriteCmosSensor(0x8f,0x20);
//    CamWriteCmosSensor(0x8f,0x00);
    CamWriteCmosSensor(0x90,0x00);
    CamWriteCmosSensor(0x91,0x00);
    CamWriteCmosSensor(0x96,0x00);
    CamWriteCmosSensor(0x9a,0x80);
    CamWriteCmosSensor(0xb0,0x84);
    CamWriteCmosSensor(0xb1,0x0c);
    CamWriteCmosSensor(0xb2,0x0e);
    CamWriteCmosSensor(0xb3,0x82);
    CamWriteCmosSensor(0xb8,0x0a);

   CamWriteCmosSensor (0x43,0x0a);
    CamWriteCmosSensor(0x44,0xf2);
    CamWriteCmosSensor(0x45,0x39);
    CamWriteCmosSensor(0x46,0x62);
    CamWriteCmosSensor(0x47,0x3d);
    CamWriteCmosSensor(0x48,0x55);
    CamWriteCmosSensor(0x59,0x83);
    CamWriteCmosSensor(0x5a,0x0d);
    CamWriteCmosSensor(0x5b,0xcd);
    CamWriteCmosSensor(0x5c,0x8c);
    CamWriteCmosSensor(0x5d,0x77);
    CamWriteCmosSensor(0x5e,0x16);
    CamWriteCmosSensor(0x6c,0x0a);
    CamWriteCmosSensor(0x6d,0x65);
    CamWriteCmosSensor(0x6e,0x11);
    CamWriteCmosSensor(0x6f,0x9e);

    CamWriteCmosSensor(0x6a,0x40);
    CamWriteCmosSensor(0x01,0x56);
    CamWriteCmosSensor(0x02,0x44);
    CamWriteCmosSensor(0x13,0xF7);		//0xe7-> 0xF7 Enable the fast AEC/AGC algorithm.
    
    /* Color Matrix */

    CamWriteCmosSensor(0x4f,0x88);
    CamWriteCmosSensor(0x50,0x8B);
    CamWriteCmosSensor(0x51,0x04);
    CamWriteCmosSensor(0x52,0x11);
    CamWriteCmosSensor(0x53,0x8C);
    CamWriteCmosSensor(0x54,0x9D);
    CamWriteCmosSensor(0x55,0x00);
    CamWriteCmosSensor(0x56,0x40);
    CamWriteCmosSensor(0x57,0x80);
    CamWriteCmosSensor(0x58,0x9A);

    CamWriteCmosSensor(0x41,0x08);
    CamWriteCmosSensor(0x3f,0x00);
    CamWriteCmosSensor(0x75,0x04);
    CamWriteCmosSensor(0x76,0x60);
    CamWriteCmosSensor(0x4c,0x00);
    CamWriteCmosSensor(0x77,0x01);
    CamWriteCmosSensor(0x3D,0xC2);
    CamWriteCmosSensor(0x4b,0x09);
    CamWriteCmosSensor(0xc9,0x30);
    CamWriteCmosSensor(0x41,0x38);
    CamWriteCmosSensor(0x56,0x40);
    
    CamWriteCmosSensor(0x34,0x11);
    CamWriteCmosSensor(0x3b,0x02);    // disable auto banding
    CamWriteCmosSensor(0xa4,0x88);
    CamWriteCmosSensor(0x96,0x00);
    CamWriteCmosSensor(0x97,0x30);
    CamWriteCmosSensor(0x98,0x20);
    CamWriteCmosSensor(0x99,0x30);
    CamWriteCmosSensor(0x9a,0x84);
    CamWriteCmosSensor(0x9b,0x29);
    CamWriteCmosSensor(0x9c,0x03);
    CamWriteCmosSensor(0x9d,0x99);
    CamWriteCmosSensor(0x9e,0x7f);
    CamWriteCmosSensor(0x78,0x04);
    
    CamWriteCmosSensor(0x79,0x01);
    CamWriteCmosSensor(0xc8,0xf0);
    CamWriteCmosSensor(0x79,0x0f);
    CamWriteCmosSensor(0xc8,0x00);
    CamWriteCmosSensor(0x79,0x10);
    CamWriteCmosSensor(0xc8,0x7e);
    CamWriteCmosSensor(0x79,0x0a);
    CamWriteCmosSensor(0xc8,0x80);
    CamWriteCmosSensor(0x79,0x0b);
    CamWriteCmosSensor(0xc8,0x01);
    CamWriteCmosSensor(0x79,0x0c);
    CamWriteCmosSensor(0xc8,0x0f);
    CamWriteCmosSensor(0x79,0x0d);
    CamWriteCmosSensor(0xc8,0x20);
    CamWriteCmosSensor(0x79,0x09);
    CamWriteCmosSensor(0xc8,0x80);
    CamWriteCmosSensor(0x79,0x02);
    CamWriteCmosSensor(0xc8,0xc0);
    CamWriteCmosSensor(0x79,0x03);
    CamWriteCmosSensor(0xc8,0x40);
    CamWriteCmosSensor(0x79,0x05);
    CamWriteCmosSensor(0xc8,0x30);
    CamWriteCmosSensor(0x79,0x26);
    
    //L99 LENS
    CamWriteCmosSensor(0x62,0x00);
    CamWriteCmosSensor(0x63,0x00);
    CamWriteCmosSensor(0x64,0x06);
    CamWriteCmosSensor(0x65,0x00);
    CamWriteCmosSensor(0x66,0x05);
    CamWriteCmosSensor(0x94,0x05);

    CamWriteCmosSensor(0x95,0x09);	//OVT joe 12/14/2006

	OV7670Sensor.Pclk = 24000000;	/* 24.0MHz Pixcel Clock. */
}

/*************************************************************************
* FUNCTION
*	OV7670SetNightMode
*
* DESCRIPTION
*	This function night mode of OV7670.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV7670SetNightMode(CAL_SCENARIO_ENUM ScenarioId, 
								kal_bool night_enalbe)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	kal_uint8 night = CamReadCmosSensor(0x3B);
	
	if (night_enalbe == KAL_TRUE) 
	{	
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			CamWriteCmosSensor(0x3B, night & 0x1F);
			CamWriteCmosSensor(0x14, 0x38);
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0x3B,night&0x1F);
			CamWriteCmosSensor(0x14, 0x4C);
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}
	else 
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			CamWriteCmosSensor(0x3B, night & 0x1F);
			CamWriteCmosSensor(0x14, 0x28);
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0x3B,night&0x1F);
			CamWriteCmosSensor(0x14,0x2C);
			CamWriteCmosSensor(0x2D,0x00);
			CamWriteCmosSensor(0x2E,0x00);
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}

	return ErrCode;
}	/* OV7670_night_mode */


/*************************************************************************
* FUNCTION
*    OV7670EV
*
* DESCRIPTION
*    OV7670 EV setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 9;
    EvPara->SupportItem[0] = CAM_EV_NEG_4_3;
    EvPara->SupportItem[1] = CAM_EV_NEG_3_3;
    EvPara->SupportItem[2] = CAM_EV_NEG_2_3;
    EvPara->SupportItem[3] = CAM_EV_NEG_1_3;
    EvPara->SupportItem[4] = CAM_EV_ZERO;
    EvPara->SupportItem[5] = CAM_EV_POS_1_3;
    EvPara->SupportItem[6] = CAM_EV_POS_2_3;
    EvPara->SupportItem[7] = CAM_EV_POS_3_3;
    EvPara->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    switch (In->FeatureSetValue)
	{
		case CAM_EV_NEG_4_3:    
            CamWriteCmosSensor(0x55, 0xF8);		
			break;		
		case CAM_EV_NEG_3_3:
            CamWriteCmosSensor(0x55, 0xD8);
			break;		
		case CAM_EV_NEG_2_3:
            CamWriteCmosSensor(0x55, 0xB8);
			break;				
		case CAM_EV_NEG_1_3:
            CamWriteCmosSensor(0x55, 0x98);
			break;				
		case CAM_EV_ZERO:
            CamWriteCmosSensor(0x55, 0x00);
			break;				
		case CAM_EV_POS_1_3:
            CamWriteCmosSensor(0x55, 0x18);
			break;				
		case CAM_EV_POS_2_3:
            CamWriteCmosSensor(0x55, 0x38);
			break;				
		case CAM_EV_POS_3_3:
            CamWriteCmosSensor(0x55, 0x58);
			break;				
		case CAM_EV_POS_4_3:	
            CamWriteCmosSensor(0x55, 0x78);
			break;
		default:
			break;    
	}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7670WB
*
* DESCRIPTION
*    OV7670 WB setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT WBPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    WBPara->IsSupport = KAL_TRUE;
    WBPara->ItemCount = 6;
    WBPara->SupportItem[0] = CAM_WB_AUTO;
    WBPara->SupportItem[1] = CAM_WB_CLOUD;
    WBPara->SupportItem[2] = CAM_WB_DAYLIGHT;
    WBPara->SupportItem[3] = CAM_WB_INCANDESCENCE;
    WBPara->SupportItem[4] = CAM_WB_FLUORESCENT;
    WBPara->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
	switch (In->FeatureSetValue)
	{
		case CAM_WB_AUTO:
			OV7670AwbEnable(KAL_TRUE);
			break;

		case CAM_WB_CLOUD:
			OV7670AwbEnable(KAL_FALSE);
			
			CamWriteCmosSensor(0x01, 0x58);
			CamWriteCmosSensor(0x02, 0x60);
            CamWriteCmosSensor(0x6A, 0x40);
			break;		

		case CAM_WB_DAYLIGHT:
			OV7670AwbEnable(KAL_FALSE);
			
			CamWriteCmosSensor(0x01, 0x56);
			CamWriteCmosSensor(0x02, 0x5C);
            CamWriteCmosSensor(0x6A, 0x42);
			break;		

		case CAM_WB_INCANDESCENCE:
			OV7670AwbEnable(KAL_FALSE);
			
			CamWriteCmosSensor(0x01, 0x9A);
			CamWriteCmosSensor(0x02, 0x40);
			CamWriteCmosSensor(0x6A, 0x48);
			break;		

		case CAM_WB_FLUORESCENT:
			OV7670AwbEnable(KAL_FALSE);
			
			CamWriteCmosSensor(0x01, 0x8B);
			CamWriteCmosSensor(0x02, 0x42);
			CamWriteCmosSensor(0x6A, 0x40);
			break;		

		case CAM_WB_TUNGSTEN:
			OV7670AwbEnable(KAL_FALSE);
			
			CamWriteCmosSensor(0x01, 0xB8);
			CamWriteCmosSensor(0x02, 0x40);
			CamWriteCmosSensor(0x6A, 0x4F);
			break;

		case CAM_WB_MANUAL:		
		    // TODO
			break;		

		default:
			break;	;			
	}
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    OV7670Effect
*
* DESCRIPTION
*    OV7670 Effect setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 6;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
	switch (In->FeatureSetValue)
	{	
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x3A,0x0C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x40);		
			CamWriteCmosSensor(0x68,0xA0);
			CamWriteCmosSensor(0x56,0x40);
			break;		
		case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x40);		
			CamWriteCmosSensor(0x68,0x40);
			CamWriteCmosSensor(0x56,0x40);		
			break;					
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0xA0);		
			CamWriteCmosSensor(0x68,0x40);
			CamWriteCmosSensor(0x56,0x40);
			break;
		case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x3A,0x2C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		default:
			break;
	}
  }   
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7670Banding
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, out_len, r_out_len
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV7670Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);

	switch (In->FeatureCtrlCode)
	{
	case CAL_FEATURE_QUERY_OPERATION:
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
		                   CAL_FEATURE_GET_OPERATION|
		                   CAL_FEATURE_QUERY_OPERATION;
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
		Banding->IsSupport = KAL_TRUE;
		Banding->ItemCount = 2;
		Banding->SupportItem[0] = CAM_BANDING_50HZ;
		Banding->SupportItem[1] = CAM_BANDING_60HZ;
		break;
	case CAL_FEATURE_SET_OPERATION:	
		OV7670SetBandingFreq(In->FeatureSetValue);
		break;
	}
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   OV7670SceneMode
*
* DESCRIPTION
*   This function get/set scene mode of sensor.
*
* PARAMETERS
*   IsCam: camera scene mode or not
*   In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    SceneMode->IsSupport = KAL_TRUE;
    SceneMode->ItemCount = 2;
    if (IsCam)
    {
      SceneMode->SupportItem[0] = CAM_AUTO_DSC;
      SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
      SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
      SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;
    }
  }
  return MM_ERROR_NONE;
}


void OV7670GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo) 
{
	SensorInfo->SensorId			=	OV7670_SENSOR_ID;

	SensorInfo->SensorIf			=	IMAGE_SENSOR_IF_PARALLEL;
	SensorInfo->PreviewNormalDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY; 
	SensorInfo->CaptureDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;

	SensorInfo->PixelClkInv			=	KAL_FALSE;
	SensorInfo->PixelClkPolarity	=	POLARITY_LOW;
	SensorInfo->HsyncPolarity		=	POLARITY_LOW;	/* Active High, it's inversed. */
	SensorInfo->VsyncPolarity		=	POLARITY_LOW;

	SensorInfo->PreviewMclkFreq 	= 	24000000;
	SensorInfo->CaptureMclkFreq 	= 	24000000;
	SensorInfo->VideoMclkFreq 		= 	24000000;

	SensorInfo->PreviewWidth		=	OV7670_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->PreviewHeight		=	OV7670_IMAGE_SENSOR_VGA_HEIGHT;
	SensorInfo->FullWidth			=	OV7670_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->FullHeight			=	OV7670_IMAGE_SENSOR_VGA_HEIGHT;

	SensorInfo->SensorAfSupport		=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
}	/* OV7670GetSensorInfo() */


static kal_uint16 OV7670PowerOn(void)
{
	OV7670_SET_RST_LOW;			/* Set Power Down Low */

	CisModulePowerOn(SensorIdxOV7670, KAL_TRUE);
	kal_sleep_task(2);				    // To wait for Stable Power, at least 5ms

	CameraSccbOpen(CAMERA_SCCB_SENSOR, OV7670_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);
	CameraSccbDisWR(CAMERA_SCCB_SENSOR);	// Stop then Start, not support Repeat Start mode.

	OV7670_SET_PDN_HIGH;			/* Set Power Down High */
	kal_sleep_task(1);
	OV7670_SET_PDN_LOW;			/* Set Power Down Low */
	kal_sleep_task(3); //it should wait at least 10ms before starting I2C

	OV7670_SET_RST_HIGH;			/* Set Power Down Low */
	kal_sleep_task(3); //it should wait at least 10ms before starting I2C

	// SW Reset Sensor
	CamWriteCmosSensor(0x12, 0x80);
	kal_sleep_task(2); //it should wiate at least 3ms after software reset and start init

	OV7670_sensor_id = (CamReadCmosSensor(0x0A)<<8)|CamReadCmosSensor(0x0B);	

	OV7670_TRACE("OV7670_sensor_id = %x", OV7670_sensor_id);

	return OV7670_sensor_id;
} /* OV7670PowerOn() */

/*************************************************************************
* FUNCTION
*    MC501CBDetectSensorId
*
* DESCRIPTION
*    This function detect sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
kal_uint32 OV7670DetectSensorId(void)
{
    kal_uint32 SensorId=0;
	IMAGE_SENSOR_INDEX_ENUM ToPdnIdx = (IMAGE_SENSOR_MAIN == SensorIdxOV7670 ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = OV7670PowerOn();
			
			OV7670SensorClose();
			
			if (OV7670_SENSOR_ID == SensorId)
			{
				return OV7670_SENSOR_ID;
			}
		}
	}

    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* OV7670DetectSensorId() */


MM_ERROR_CODE_ENUM OV7670StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In,
										   P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pStillCaptureSize = NULL;

	pStillCaptureSize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(Out->FeatureInfo.FeatureEnum);

	switch (In->FeatureCtrlCode)
	{
	case CAL_FEATURE_QUERY_OPERATION:
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION 
									| CAL_FEATURE_GET_OPERATION 
									| CAL_FEATURE_QUERY_OPERATION;
		
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		
		pStillCaptureSize->IsSupport = KAL_TRUE;
		pStillCaptureSize->ItemCount = 2;
		pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
		pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
		ErrCode = MM_ERROR_NONE;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	return ErrCode;
}   /* OV7670StillCaptureSize() */

void OV7670InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
	Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
	Para->PreviewDelayFrame = 5; /* wait stable frame when sensor change mode (cap to pre) */
	Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
} /* OV7670InitOperationPara() */


MM_ERROR_CODE_ENUM OV7670Preview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		OV7670_dummy_pixels = 0;
		OV7670_dummy_lines = 0;
			
		out->WaitStableFrameNum = 10;
		OV7670SetVideoFrameRate(in->MaxVideoFrameRate);
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		OV7670_dummy_pixels = 0;
		OV7670_dummy_lines = 0;
		
		out->WaitStableFrameNum = 10;
		break;
	default:
		ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	OV7670SetNightMode(ScenarioId, in->NightMode);

	OV7670SetBandingFreq(in->BandingFreq);

	OV7670SetMirrorFlip(in->ImageMirror);

	OV7670AeEnable(KAL_TRUE);
	OV7670AwbEnable(KAL_TRUE);

	out->GrabStartX = OV7670_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = OV7670_IMAGE_SENSOR_VGA_INSERTED_LINES + OV7670_dummy_lines;
	out->ExposureWindowWidth = OV7670_IMAGE_SENSOR_VGA_WIDTH;
	out->ExposureWindowHeight = OV7670_IMAGE_SENSOR_VGA_HEIGHT;

	return ErrorCode;
} /* OV7670Preview */

MM_ERROR_CODE_ENUM OV7670Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	out->GrabStartX = OV7670_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = OV7670_IMAGE_SENSOR_VGA_INSERTED_LINES;
	out->ExposureWindowWidth = OV7670_IMAGE_SENSOR_VGA_WIDTH;
	out->ExposureWindowHeight = OV7670_IMAGE_SENSOR_VGA_HEIGHT;
	
	return ErrorCode;
} 	/* OV7670Capture() */

MM_ERROR_CODE_ENUM OV7670SensorOpen(void)
{
	kal_uint16 SensorId;
  
	SensorId = OV7670PowerOn();
	if (OV7670_SENSOR_ID != SensorId)
		return MM_ERROR_SENSOR_READ_ID_FAIL;

	OV7670InitializeSetting();
  
	return MM_ERROR_NONE;
} /* OV7670SensorOpen() */

/*************************************************************************
* FUNCTION
*    OV7670SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7670SensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);

  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return OV7670WebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
  }

  if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
  }

  switch (id)
  {
     /* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
      ErrCode = OV7670EV(In, Out);
      break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    case CAL_FEATURE_CAMERA_WB:
      ErrCode = OV7670WB(In, Out);
      break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
      ErrCode = OV7670Effect(In, Out);
      break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
      ErrCode = OV7670StillCaptureSize(In, Out);
      break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
      ErrCode = OV7670Banding(In, Out);
      break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
		ErrCode = OV7670SceneMode(KAL_TRUE, In, Out);
		break;
	case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
		ErrCode = OV7670SceneMode(KAL_FALSE, In, Out);
		break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
		FlashlightPowerOn(SensorIdxOV7670, (kal_bool )(((P_CAL_FEATURE_CTRL_STRUCT)In)->FeatureSetValue));
		break;

    /* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
      OV7670GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV7670DetectSensorId();
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV7670_video_frame_rate;
      break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
      OV7670InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
      break;

	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		OV7670_SET_PDN_HIGH;
		break;
    /* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
      SensorIdxOV7670 = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
      break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
      break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		OV7670Sensor.BypassAe = *(kal_bool *)In;
        OV7670AeEnable(OV7670Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		OV7670Sensor.BypassAwb = *(kal_bool *)In;
        OV7670AwbEnable(OV7670Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(SensorIdxOV7670, Out);
	    break;
    default:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
  }
  return ErrCode;
}

MM_ERROR_CODE_ENUM OV7670SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint32 ParaOutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_VIDEO:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            OV7670Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            OV7670Capture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM OV7670SensorClose(void)
{
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
    CisModulePowerOn(SensorIdxOV7670, KAL_FALSE);

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7670SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV7670SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV7670=
	{
		OV7670SensorOpen,
		OV7670SensorFeatureCtrl,
		OV7670SensorCtrl,
		OV7670SensorClose,
	};

	*pfSensorFunc = &ImageSensorFuncOV7670;

	return MM_ERROR_NONE;
}




