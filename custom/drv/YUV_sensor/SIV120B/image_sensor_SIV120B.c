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
 *   image_sensor_SIV120B.c
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


static kal_uint8 SIV120B_Control = 0x00;

SIV120B_SENSOR_ST SIV120BSensor;

CAL_SCENARIO_ENUM SIV120BCurrScenario = CAL_SCENARIO_CAMERA_PREVIEW;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

static void SIV120B_set_page(kal_uint8 iPage)
{
    CamWriteCmosSensor(0x00,iPage);
}

/*************************************************************************
* FUNCTION
*   SIV120BSetBandingStep
*
* DESCRIPTION
*   This function is to calculate & set shutter step register .
*
*************************************************************************/
static void SIV120BSetBandingStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq)
{
    kal_uint8 banding = 0;
    kal_uint16 shutter_step = 0;
	kal_uint32 line_length = 0;

	if (SIV120BSensor.BandingFreq == BandingFreq)
		return ;

	SIV120BSensor.BandingFreq = BandingFreq;

	if (CAM_BANDING_50HZ == BandingFreq)
	{
		banding = 100;
	}
	else
	{
		banding = 120;
	}

	line_length = SIV120B_PERIOD_PIXEL_NUMS + SIV120BSensor.dummy_pixels;
	shutter_step = (SIV120BSensor.Pclk + (((line_length * 2) * banding)>>2)) / ((line_length * 2) * banding);

    ASSERT(shutter_step <= 0xFF);
    /* Block 1:0x34  shutter step*/
	CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x34, shutter_step);

	// AE Off
    CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x10, 0x00);

	//camera_wait_sensor_vd_done();
	kal_sleep_task(50);		// Wait the disable ae take effect.

	// AE on
    SIV120B_set_page(1);
	CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x10, 0x80);
	
    SIV120B_TRACE("Set Shutter Step:%x", shutter_step);
}/* SIV120BSetBandingStep */


/*************************************************************************
* FUNCTION
*   SIV120BSetDummy
*
* DESCRIPTION
*   This function is to set Blank size for Preview mode .
*
* PARAMETERS
*   iBlank: target HBlank size
*      iHz: banding frequency
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120BSetDummy(kal_uint16 dummy_pixels, kal_uint16 dummy_lines)
{
   /********************************************
    *   Register :0x20 - 0x22
    *  Block 00
    *  0x20  [7:4]:HBANK[9:8]; 0x20  [3:0]:VBANK[9:8]
    *  0x21 HBANK[7:0]
    *  0x23 VBANK[7:0]
    ********************************************/
    ASSERT(dummy_pixels <= SIV120B_BLANK_REGISTER_LIMITATION && dummy_lines <= SIV120B_BLANK_REGISTER_LIMITATION);

	SIV120BSensor.dummy_pixels = dummy_pixels;
	SIV120BSensor.dummy_lines = dummy_lines;

    SIV120B_set_page(0);
    CamWriteCmosSensor(0x20,((dummy_pixels>>4)&0xF0)|((dummy_lines>>8)&0x0F));
    CamWriteCmosSensor(0x21,dummy_pixels & 0xFF);
    CamWriteCmosSensor(0x23,dummy_lines & 0xFF);

	SIV120B_TRACE("dummy_pixels:%x,dummy_lines:%x",dummy_pixels,dummy_lines);
}   /* SIV120BSetDummy */


/*************************************************************************
* FUNCTION
*   SIV120BSetNightMode
*
* DESCRIPTION
*   This function switch on/off night mode of SIV120B.
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIV120BSetNightMode(CAL_SCENARIO_ENUM ScenarioId, 
								kal_bool night_enalbe)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
    SIV120B_TRACE("NightMode %d", night_enalbe);

	if (KAL_TRUE == night_enalbe)
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			SIV120B_set_page(1);
            CamWriteCmosSensor(0x40,0x6c); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
            SIV120B_set_page(3);
            CamWriteCmosSensor(0xB9,0x14); //Color Suppression Change Start State  0x17
            CamWriteCmosSensor(0xBA,0x40); //Slope
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
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			SIV120B_set_page(1);
            CamWriteCmosSensor(0x40,0x66);// 0x7F
            SIV120B_set_page(3);
            CamWriteCmosSensor(0xB9,0x18);
            CamWriteCmosSensor(0xBA,0x30); //Slope
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}

	return ErrCode;
}   /* SIV120BSetNightMode */

/*************************************************************************
* FUNCTION
*    SIV120BSceneMode
*
* DESCRIPTION
*    This function get/set scene mode of sensor.
*
* PARAMETERS
*    IsCam: camera scene mode or not
*    In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV120BSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_bool Enable;
    
    if (CAM_NIGHTSCENE == In->FeatureSetValue || CAM_VIDEO_NIGHT == In->FeatureSetValue)
    {
      Enable = KAL_TRUE;
    }
    else
    {
      Enable = KAL_FALSE;
    }
    SIV120BSetNightMode(SIV120BCurrScenario, Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIV120BSetMaxShutterStep
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void SIV120BSetMaxShutterStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq, kal_uint32 MinFrameRate)
{
    kal_uint8 banding = 100;
	kal_uint8 max_shutter_step = 0;

	if (CAM_BANDING_50HZ == BandingFreq)
	{
		banding = 100;
	}
	else
	{
		banding = 120;
	}

	max_shutter_step = banding * SIV120B_FRAME_RATE_UNIT / MinFrameRate;
	/*Block 01: 0x11  Max shutter step,for Min frame rate */
	//SIV120B_set_page(1);
	CamWriteCmosSensor(0x00, 0x01);
	CamWriteCmosSensor(0x11, max_shutter_step&0xFF);

	SIV120B_TRACE("MinFrameRate:%d, max_shutter_step:%x", MinFrameRate, max_shutter_step);
}/* SIV120BSetMaxShutterStep */



/*************************************************************************
* FUNCTION
*   SIV120BSetFixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
 static void SIV120BSetFixFrameRate(kal_bool IsFixFrameRate)
 {
	 if (IsFixFrameRate == KAL_TRUE)
	 {
		 SIV120B_Control |= 0xC0;
		 SIV120B_set_page(0);
		 CamWriteCmosSensor(0x04, SIV120B_Control);
	 }
	 else
	 {
		 SIV120B_Control &= 0x3F;
		 SIV120B_set_page(0);
		 CamWriteCmosSensor(0x04, SIV120B_Control);

	 }
 }	/* SIV120BSetFixFrameRate */


/*************************************************************************
* FUNCTION
*    SIV120BSetFrameRate
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER SIM120C_preview() !!!
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIV120BSetFrameRate(kal_uint32 MinFrameRate, kal_uint32 MaxFrameRate)
{
    kal_uint32 line_length = 0;
	kal_uint32 frame_length = 0;

	SIV120B_TRACE("[Target] MinFrameRate:%d, MaxFrameRate:%d", MinFrameRate, MaxFrameRate);
	
	//4 Step 1 Set the max frame rate
    line_length = SIV120B_PERIOD_PIXEL_NUMS + SIV120BSensor.dummy_pixels;

    frame_length = SIV120BSensor.Pclk * SIV120B_FRAME_RATE_UNIT / (2 * line_length * MaxFrameRate);
	if (frame_length < SIV120B_PERIOD_LINE_NUMS)
	{
		frame_length = SIV120B_PERIOD_LINE_NUMS;

		SIV120B_TRACE("Warining!!! Target frame rate exeed sensor limitation: tar=%d, lim=%d", \
			MaxFrameRate, SIV120BSensor.Pclk*SIV120B_FRAME_RATE_UNIT / line_length*2 / frame_length);

		MaxFrameRate = SIV120BSensor.Pclk*SIV120B_FRAME_RATE_UNIT / ((SIV120B_PERIOD_PIXEL_NUMS + SIV120BSensor.dummy_pixels) * 2) / (SIV120B_PERIOD_LINE_NUMS + SIV120BSensor.dummy_lines);
	}
	
    if (frame_length > (SIV120B_PERIOD_LINE_NUMS + 0xFFF))
    {
        frame_length = SIV120B_PERIOD_LINE_NUMS + 0xFFF;
        line_length = SIV120BSensor.Pclk * SIV120B_FRAME_RATE_UNIT / (2 * frame_length * MaxFrameRate);
    }

    SIV120BSetDummy(line_length-SIV120B_PERIOD_PIXEL_NUMS, frame_length-SIV120B_PERIOD_LINE_NUMS);

	//4 Step 2 Set the minmum frame rate
	SIV120BSetMaxShutterStep(SIV120BSensor.BandingFreq, MinFrameRate);

	//4 Step 3 Fix the frame rate.
	if (MinFrameRate == MaxFrameRate)
	{
		SIV120BSetFixFrameRate(KAL_TRUE);
	}
	else
	{
		SIV120BSetFixFrameRate(KAL_FALSE);
	}
}


/*************************************************************************
* FUNCTION
*   SIV120BInitialSetting
*
* DESCRIPTION
*   This function initialize the registers of CMOS sensor.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120BInitialSetting(void)
{
	// SNR block [Vendor recommended value ##Don't change##]
	CamWriteCmosSensor(0x00, 0x00);
	CamWriteCmosSensor(0x04, 0xc0);
	CamWriteCmosSensor(0x05, 0x07); //VGA Output
	CamWriteCmosSensor(0x10, 0x13);
	CamWriteCmosSensor(0x11, 0x25);
	CamWriteCmosSensor(0x12, 0x21);
	CamWriteCmosSensor(0x13, 0x17); // ABS
	CamWriteCmosSensor(0x16, 0xCF);
	CamWriteCmosSensor(0x17, 0xaa); //Internal LDO On: 0xaa
									  //Internal LDO off: 0x00 
					  
	// SIV120B 50Hz - 24MHz
	CamWriteCmosSensor(0x20, 0x00);
	CamWriteCmosSensor(0x21, 0x01);
	CamWriteCmosSensor(0x23, 0x01);
	CamWriteCmosSensor(0x00, 0x01);
	if (SIV120BSensor.BandingFreq == CAM_BANDING_50HZ)
	{
		CamWriteCmosSensor(0x34, 0x96);	//0x9D
	}
	else
	{
		CamWriteCmosSensor(0x34, 0x7D);	//0x83
	}

	// Vendor recommended value ##Don't change##
	CamWriteCmosSensor(0x00, 0x00);
	CamWriteCmosSensor(0x40, 0x00);
	CamWriteCmosSensor(0x41, 0x00);
	CamWriteCmosSensor(0x42, 0x00);
	CamWriteCmosSensor(0x43, 0x00);
					  
	// AE
	CamWriteCmosSensor(0x00, 0x01);
	CamWriteCmosSensor(0x11, 0x03);
	CamWriteCmosSensor(0x12, 0x80); // D65 target 0x84
	CamWriteCmosSensor(0x13, 0x80); // D30 target
	CamWriteCmosSensor(0x14, 0x80); // D20 target

	// Init shutter & gain
	CamWriteCmosSensor(0x1D, 0x02); //Initial shutter time
	CamWriteCmosSensor(0x1E, 0x08); //Initial analog gain

	CamWriteCmosSensor(0x40, 0x80); // Max gain 0x7F  //68
	CamWriteCmosSensor(0x41, 0x28);
	CamWriteCmosSensor(0x42, 0x28);
	CamWriteCmosSensor(0x43, 0x08);
	CamWriteCmosSensor(0x44, 0x08);
	CamWriteCmosSensor(0x45, 0x09);
	CamWriteCmosSensor(0x46, 0x17);
	CamWriteCmosSensor(0x47, 0x1D);
	CamWriteCmosSensor(0x48, 0x21);
	CamWriteCmosSensor(0x49, 0x23);
	CamWriteCmosSensor(0x4A, 0x24);
	CamWriteCmosSensor(0x4B, 0x26);
	CamWriteCmosSensor(0x4C, 0x27);
	CamWriteCmosSensor(0x4D, 0x27);
	CamWriteCmosSensor(0x4E, 0x1A);
	CamWriteCmosSensor(0x4F, 0x14);
	CamWriteCmosSensor(0x50, 0x11);
	CamWriteCmosSensor(0x51, 0x0F);
	CamWriteCmosSensor(0x52, 0x0D);
	CamWriteCmosSensor(0x53, 0x0C);
	CamWriteCmosSensor(0x54, 0x0A);
	CamWriteCmosSensor(0x55, 0x09);

	// AE Window
	CamWriteCmosSensor(0x60, 0xFF);
	CamWriteCmosSensor(0x61, 0xFF);
	CamWriteCmosSensor(0x62, 0xFF);
	CamWriteCmosSensor(0x63, 0xFF);
	CamWriteCmosSensor(0x64, 0xFF);
	CamWriteCmosSensor(0x65, 0xFF);
	CamWriteCmosSensor(0x66, 0x00);
	CamWriteCmosSensor(0x67, 0x50);
	CamWriteCmosSensor(0x68, 0x50);
	CamWriteCmosSensor(0x69, 0x50);
	CamWriteCmosSensor(0x6A, 0x50);
	CamWriteCmosSensor(0x6B, 0x00);
	CamWriteCmosSensor(0x6C, 0x06);

	//Anti Saturation
	CamWriteCmosSensor(0x70, 0xD4); //Anti Saturation On
	CamWriteCmosSensor(0x77, 0xB0);
	CamWriteCmosSensor(0x78, 0xB8);
	CamWriteCmosSensor(0x79, 0x6E); //Y Level 0x70 for gamma test

	CamWriteCmosSensor(0x90, 0xC8);

	// AWB					   
	CamWriteCmosSensor(0x00, 0x02);
	//CamWriteCmosSensor(0x10, 0xD3);
	CamWriteCmosSensor(0x11, 0xC0);
	CamWriteCmosSensor(0x12, 0x20);
	CamWriteCmosSensor(0x13, 0x80);
	CamWriteCmosSensor(0x14, 0x7F);
	CamWriteCmosSensor(0x15, 0xFE);
	CamWriteCmosSensor(0x16, 0x74); //2010-11-01 Hayes AWB issue
	CamWriteCmosSensor(0x17, 0xFE); //2010-11-01 Hayes AWB issue
	CamWriteCmosSensor(0x18, 0x80);
					  
	CamWriteCmosSensor(0x19, 0xB0);//0xA0
	CamWriteCmosSensor(0x1A, 0x50);//0x60
	CamWriteCmosSensor(0x1B, 0xB0);//0xA0
	CamWriteCmosSensor(0x1C, 0x50);//0x60
	CamWriteCmosSensor(0x1D, 0xA0);
	CamWriteCmosSensor(0x1E, 0x70);

	CamWriteCmosSensor(0x20, 0xE8);
	CamWriteCmosSensor(0x21, 0x20);
	CamWriteCmosSensor(0x22, 0xA4);
	CamWriteCmosSensor(0x23, 0x20);
	CamWriteCmosSensor(0x24, 0xFF);
	CamWriteCmosSensor(0x25, 0x20);
	CamWriteCmosSensor(0x26, 0x0F);
	CamWriteCmosSensor(0x27, 0x10);
	CamWriteCmosSensor(0x28, 0x1A);
	CamWriteCmosSensor(0x29, 0xB8);
	CamWriteCmosSensor(0x2A, 0x90);

	CamWriteCmosSensor(0x30, 0x00);
	CamWriteCmosSensor(0x31, 0x10);
	CamWriteCmosSensor(0x32, 0x00);
	CamWriteCmosSensor(0x33, 0x10);
	CamWriteCmosSensor(0x34, 0x02);
	CamWriteCmosSensor(0x35, 0x76);
	CamWriteCmosSensor(0x36, 0x01);
	CamWriteCmosSensor(0x37, 0xD6);
	CamWriteCmosSensor(0x40, 0x02);	// 0x01
	CamWriteCmosSensor(0x41, 0x04);
	CamWriteCmosSensor(0x42, 0x08);
	CamWriteCmosSensor(0x43, 0x10);
	CamWriteCmosSensor(0x44, 0x12);
	CamWriteCmosSensor(0x45, 0x35);
	CamWriteCmosSensor(0x46, 0x64);
	CamWriteCmosSensor(0x50, 0x33);
	CamWriteCmosSensor(0x51, 0x20);
	CamWriteCmosSensor(0x52, 0xE5);
	CamWriteCmosSensor(0x53, 0xFB);
	CamWriteCmosSensor(0x54, 0x13);
	CamWriteCmosSensor(0x55, 0x26);
	CamWriteCmosSensor(0x56, 0x07);
	CamWriteCmosSensor(0x57, 0xF5);
	CamWriteCmosSensor(0x58, 0xEA);
	CamWriteCmosSensor(0x59, 0x21);

	//CMA change  -D65~A
	CamWriteCmosSensor(0x63, 0x9D); //D30 to D20 for R
	CamWriteCmosSensor(0x64, 0xBE); //D30 to D20 for B
	CamWriteCmosSensor(0x65, 0x9D); //D20 to D30 for R
	CamWriteCmosSensor(0x66, 0xBE); //D20 to D30 for B
	CamWriteCmosSensor(0x67, 0xC2); //D65 to D30 for R
	CamWriteCmosSensor(0x68, 0x9C); //D65 to D30 for B
	CamWriteCmosSensor(0x69, 0xC2); //D30 to D65 for R
	CamWriteCmosSensor(0x6A, 0x9C); //D30 to D65 for B

	// IDP						
	CamWriteCmosSensor(0x00, 0x03);
	CamWriteCmosSensor(0x10, 0xFF); // IDP function enable
	CamWriteCmosSensor(0x11, 0x0D); // PCLK polarity
	CamWriteCmosSensor(0x12, 0xDD); // Y,Cb,Cr order sequence
	CamWriteCmosSensor(0x8C, 0x18); // Color matrix select at dark condition

	// DPCNR					  
	CamWriteCmosSensor(0x17, 0xB8);
	CamWriteCmosSensor(0x18, 0x18);
	CamWriteCmosSensor(0x19, 0x48);
	CamWriteCmosSensor(0x1A, 0x48);
	CamWriteCmosSensor(0x1B, 0x3F);
	CamWriteCmosSensor(0x1C, 0x10);
	CamWriteCmosSensor(0x1D, 0x60);
	CamWriteCmosSensor(0x1E, 0x60);
	CamWriteCmosSensor(0x1F, 0x4F);
	CamWriteCmosSensor(0x20, 0x03); // Normal illumiinfo start
	CamWriteCmosSensor(0x21, 0x0F); // Dark illumiinfo start

	// Gamma
	CamWriteCmosSensor(0x30, 0x00);
	CamWriteCmosSensor(0x31, 0x08);
	CamWriteCmosSensor(0x32, 0x0F);
	CamWriteCmosSensor(0x33, 0x20);
	CamWriteCmosSensor(0x34, 0x3B);
	CamWriteCmosSensor(0x35, 0x52);
	CamWriteCmosSensor(0x36, 0x66);
	CamWriteCmosSensor(0x37, 0x78);
	CamWriteCmosSensor(0x38, 0x89);
	CamWriteCmosSensor(0x39, 0x98);
	CamWriteCmosSensor(0x3A, 0xA4);
	CamWriteCmosSensor(0x3B, 0xBA);
	CamWriteCmosSensor(0x3C, 0xD4);
	CamWriteCmosSensor(0x3D, 0xEC);
	CamWriteCmosSensor(0x3E, 0xF6);
	CamWriteCmosSensor(0x3F, 0xFF);

	// Shading
	CamWriteCmosSensor(0x40, 0x00);
	CamWriteCmosSensor(0x41, 0xDC);
	CamWriteCmosSensor(0x42, 0xCB);
	CamWriteCmosSensor(0x43, 0xA8);
	CamWriteCmosSensor(0x44, 0x75);
	CamWriteCmosSensor(0x45, 0x31);
	CamWriteCmosSensor(0x46, 0x63);//0x44
	CamWriteCmosSensor(0x47, 0x45);//0x63
	CamWriteCmosSensor(0x48, 0x63);//0x44
	CamWriteCmosSensor(0x49, 0x43);//0x62
	CamWriteCmosSensor(0x4A, 0x63);//0x34
	CamWriteCmosSensor(0x4B, 0x42);//0x41
	CamWriteCmosSensor(0x4C, 0x52);//0x23
	CamWriteCmosSensor(0x4D, 0x31);//0x40
	CamWriteCmosSensor(0x4E, 0x04);
	CamWriteCmosSensor(0x4F, 0x44);//0x44
	CamWriteCmosSensor(0x50, 0xFE);//0xF6
	CamWriteCmosSensor(0x51, 0x88);	// QH, 0x80 --> 0x88, 10-22
	CamWriteCmosSensor(0x52, 0x00);
	CamWriteCmosSensor(0x53, 0x00);
	CamWriteCmosSensor(0x54, 0x00);
	CamWriteCmosSensor(0x55, 0x00);


	// Lowlux Shading
	CamWriteCmosSensor(0x56, 0x10);
	CamWriteCmosSensor(0x57, 0xDA);
	CamWriteCmosSensor(0x58, 0xFF);

	//Filter
	CamWriteCmosSensor(0x60, 0x2F);
	CamWriteCmosSensor(0x61, 0xB7);
	CamWriteCmosSensor(0x62, 0xB7);
	CamWriteCmosSensor(0x63, 0xB7);
	CamWriteCmosSensor(0x64, 0x0C);
	CamWriteCmosSensor(0x65, 0xFF);
	CamWriteCmosSensor(0x66, 0x08);
	CamWriteCmosSensor(0x67, 0xFF);
	CamWriteCmosSensor(0x68, 0x00);
	CamWriteCmosSensor(0x69, 0x00);
	CamWriteCmosSensor(0x6A, 0x00);
	CamWriteCmosSensor(0x6B, 0x00);
	CamWriteCmosSensor(0x6C, 0xA0);
	CamWriteCmosSensor(0x6D, 0x10);
	CamWriteCmosSensor(0x6E, 0x08);
	CamWriteCmosSensor(0x6F, 0x18);

	// Color Matrix (D65) - Daylight
	CamWriteCmosSensor(0x71, 0x3E);
	CamWriteCmosSensor(0x72, 0xBD);
	CamWriteCmosSensor(0x73, 0x05);
	CamWriteCmosSensor(0x74, 0x0F);
	CamWriteCmosSensor(0x75, 0x1E);
	CamWriteCmosSensor(0x76, 0x13);
	CamWriteCmosSensor(0x77, 0xF3);
	CamWriteCmosSensor(0x78, 0xD4); //2010-11-01 Hayes AWB issue
	CamWriteCmosSensor(0x79, 0x39); //2010-11-01 Hayes AWB issue

	// Color Matrix (D30) - CWF
	CamWriteCmosSensor(0x7A, 0x3D);
	CamWriteCmosSensor(0x7B, 0xC4);
	CamWriteCmosSensor(0x7C, 0xFF);
	CamWriteCmosSensor(0x7D, 0x10);
	CamWriteCmosSensor(0x7E, 0x1D);
	CamWriteCmosSensor(0x7F, 0x13);
	CamWriteCmosSensor(0x80, 0xF2);
	CamWriteCmosSensor(0x81, 0xC4);
	CamWriteCmosSensor(0x82, 0x4A);

	// Color Matrix (D20) - A
	CamWriteCmosSensor(0x83, 0x3C);
	CamWriteCmosSensor(0x84, 0xC2);
	CamWriteCmosSensor(0x85, 0x01);
	CamWriteCmosSensor(0x86, 0x10);
	CamWriteCmosSensor(0x87, 0x1F);
	CamWriteCmosSensor(0x88, 0x0F);
	CamWriteCmosSensor(0x89, 0xF6);
	CamWriteCmosSensor(0x8A, 0xD2);
	CamWriteCmosSensor(0x8B, 0x39);
					  
	// Edge - Green
	CamWriteCmosSensor(0x90, 0x18); //0x10 Up Gain
	CamWriteCmosSensor(0x91, 0x18); //0x10 Down Gain
	CamWriteCmosSensor(0x92, 0x04);
	CamWriteCmosSensor(0x93, 0x12);
	CamWriteCmosSensor(0x94, 0xFF);
	CamWriteCmosSensor(0x95, 0x20);
	CamWriteCmosSensor(0x96, 0x04);
	CamWriteCmosSensor(0x97, 0x12);
	CamWriteCmosSensor(0x98, 0xFF);
	CamWriteCmosSensor(0x99, 0x20);
	CamWriteCmosSensor(0x9A, 0x60);	//0x20
	CamWriteCmosSensor(0x9B, 0x60);	//0x20
	CamWriteCmosSensor(0x9C, 0x1A);
	CamWriteCmosSensor(0x9D, 0x40);
	CamWriteCmosSensor(0x9E, 0x00);

	// Edge - Luminance
	CamWriteCmosSensor(0x9F, 0x20);	//0x00
	CamWriteCmosSensor(0xA0, 0x20);	//0x00
	CamWriteCmosSensor(0xA1, 0x02);
	CamWriteCmosSensor(0xA2, 0x02);
	CamWriteCmosSensor(0xA3, 0x60);	//0x04
	CamWriteCmosSensor(0xA4, 0x60);	//0x20
	CamWriteCmosSensor(0xA5, 0x1A);
	CamWriteCmosSensor(0xA6, 0x40);
	CamWriteCmosSensor(0xA7, 0x00);

	// YCbCr Gain, Brightness, Contrast
	CamWriteCmosSensor(0xA8, 0x10);
	CamWriteCmosSensor(0xA9, 0x12); //2010-11-01 Hayes Saturation issue 
	CamWriteCmosSensor(0xAA, 0x12); //2010-11-01 Hayes Saturation issue
	CamWriteCmosSensor(0xAB, 0x04);
	CamWriteCmosSensor(0xAC, 0x10);

	CamWriteCmosSensor(0xB0, 0xFF); //Y Top
	CamWriteCmosSensor(0xB1, 0x00); //Y Bottom
	CamWriteCmosSensor(0xB2, 0xFF); 
	CamWriteCmosSensor(0xB3, 0x00);
	CamWriteCmosSensor(0xB4, 0xFF);
	CamWriteCmosSensor(0xB5, 0x00);
	CamWriteCmosSensor(0xB6, 0x00);

	// Color suppress					 
	CamWriteCmosSensor(0xB9, 0x1A); //Ilimininfo Start0 x1A
	CamWriteCmosSensor(0xBA, 0x30); //Slope

	// Window
	CamWriteCmosSensor(0xC0, 0x24); 
	CamWriteCmosSensor(0xC1, 0x00);
	CamWriteCmosSensor(0xC2, 0x80);
	CamWriteCmosSensor(0xC3, 0x00);
	CamWriteCmosSensor(0xC4, 0xE0);

	CamWriteCmosSensor(0xDD, 0x4F); // ENHCTRL
	CamWriteCmosSensor(0xDE, 0xBA); // NOIZCTRL
	CamWriteCmosSensor(0xDF, 0x28);
	CamWriteCmosSensor(0xE0, 0x70);
	CamWriteCmosSensor(0xE1, 0x90);
	CamWriteCmosSensor(0xE2, 0x08);
	CamWriteCmosSensor(0xE3, 0x10);
	CamWriteCmosSensor(0xE4, 0x40);

	// Memory speed control
	CamWriteCmosSensor(0xE5, 0x15);
	CamWriteCmosSensor(0xE6, 0x28);
	CamWriteCmosSensor(0xE7, 0x04); 

	// Sensor on
	CamWriteCmosSensor(0x00, 0x00);
	CamWriteCmosSensor(0x03, 0x35); //0x55 0x25
	//board 1  0x25
	//board 2  
	//board 3  0x05

	// AE on
	CamWriteCmosSensor(0x00, 0x01);
	CamWriteCmosSensor(0x10, 0x80);

	// AWB					   
	CamWriteCmosSensor(0x00, 0x02);
	CamWriteCmosSensor(0x60, 0x98);
	CamWriteCmosSensor(0x61, 0xB5);
	CamWriteCmosSensor(0x62, 0x83); 
	CamWriteCmosSensor(0x10, 0xC3);
	CamWriteCmosSensor(0x12, 0x20);	// Add for AWB Issue

	SIV120BSensor.Pclk = 24000000;	// No PLL, Equal MCLK 24Mhz
	SIV120BSensor.dummy_pixels = 0x01;
	SIV120BSensor.dummy_lines = 0x01;
}   /* SIV120BInitialSetting */

/*************************************************************************
* FUNCTION
*   SIV120BSetMirrorFlip
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
 static void SIV120BSetMirrorFlip(IMAGE_SENSOR_MIRROR_ENUM ImageMirrorFlip)
 {
	 SIV120B_Control = SIV120B_Control & 0xFC;

	 switch (ImageMirrorFlip)
	 {
	 case IMAGE_SENSOR_MIRROR_NORMAL:
		 SIV120B_Control |= 0x00;
		 break;
	 case IMAGE_SENSOR_MIRROR_H:
		 SIV120B_Control |= 0x01;
		 break;
	 case IMAGE_SENSOR_MIRROR_V:
		 SIV120B_Control |= 0x02;
		 break;
	 case IMAGE_SENSOR_MIRROR_HV:
		 SIV120B_Control |= 0x03;
		 break;
	 default:
		 ASSERT(0);
	 }

	 SIV120B_set_page(0);
	 CamWriteCmosSensor(0x04,SIV120B_Control);
 }   /* SIV120BSetMirrorFlip */


/*************************************************************************
* FUNCTION
*    SIV120BEV
*
* DESCRIPTION
*    SIV120B EV setting.
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
static MM_ERROR_CODE_ENUM SIV120BEV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    CamWriteCmosSensor(0x00, 0x03);
    switch (In->FeatureSetValue)
    {
        case CAM_EV_NEG_4_3:    // -2.0 EV
            CamWriteCmosSensor(0xAB, 0xd0); 
            break;
        case CAM_EV_NEG_3_3:    // -1.5 EV
            CamWriteCmosSensor(0xAB, 0xbc); 
            break;
        case CAM_EV_NEG_2_3:    // -1.0 EV
            CamWriteCmosSensor(0xAB, 0xa8); 
            break;
        case CAM_EV_NEG_1_3:    // -0.5 EV
            CamWriteCmosSensor(0xAB, 0x94); 
            break;
        case CAM_EV_ZERO:   	// +0 EV
            CamWriteCmosSensor(0xAB, 0x00); 
            break;
        case CAM_EV_POS_1_3:    // +0.5 EV
            CamWriteCmosSensor(0xAB, 0x14); 
            break;
        case CAM_EV_POS_2_3:    // +1.0 EV
            CamWriteCmosSensor(0xAB, 0x28); 
            break;
        case CAM_EV_POS_3_3:    // +1.5 EV
            CamWriteCmosSensor(0xAB, 0x3c); 
            break;
        case CAM_EV_POS_4_3:    // +2.0 EV
            CamWriteCmosSensor(0xAB, 0x50); 
            break;
        default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV120BWB
*
* DESCRIPTION
*    SIV120B WB setting.
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
static MM_ERROR_CODE_ENUM SIV120BWB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
	CamWriteCmosSensor(0x00, 0x02);
    switch (In->FeatureSetValue)
    {
        case CAM_WB_AUTO:   // enable AWB
            // CAM_WB_AUTO mode should not update R/G/B gains
            CamWriteCmosSensor(0x10, 0xC3);
            break;
        case CAM_WB_CLOUD:
            CamWriteCmosSensor(0x10, 0x00);  // disable AWB
            CamWriteCmosSensor(0x60, 0xD0);
            CamWriteCmosSensor(0x61, 0x88);
            break;
        case CAM_WB_DAYLIGHT:
            CamWriteCmosSensor(0x10, 0x00);  // disable AWB
            CamWriteCmosSensor(0x60, 0xC2);
            CamWriteCmosSensor(0x61, 0x9E);
            break;
        case CAM_WB_INCANDESCENCE:
            CamWriteCmosSensor(0x10, 0x00);  // disable AWB
            CamWriteCmosSensor(0x60, 0x98);
            CamWriteCmosSensor(0x61, 0xC8);
            break;
        case CAM_WB_FLUORESCENT:
            CamWriteCmosSensor(0x10, 0x00);  // disable AWB
            CamWriteCmosSensor(0x60, 0xAA);
            CamWriteCmosSensor(0x61, 0xBE);
            break;
        case CAM_WB_TUNGSTEN:
            CamWriteCmosSensor(0x10, 0x00);  // disable AWB
            CamWriteCmosSensor(0x60, 0x90);
            CamWriteCmosSensor(0x61, 0xC0);
            break;
        case CAM_WB_MANUAL:
        default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  
  return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    SIV120BEffect
*
* DESCRIPTION
*    SIV120B Effect setting.
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
static MM_ERROR_CODE_ENUM SIV120BEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 8;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
	SIV120B_set_page(3);  //bank 3
    switch (In->FeatureSetValue)
    {
        case CAM_EFFECT_ENC_NORMAL:
            CamWriteCmosSensor(0xB6, 0x00);
            break;
        case CAM_EFFECT_ENC_GRAYSCALE:
            CamWriteCmosSensor(0xB6, 0x40);
            break;
        case CAM_EFFECT_ENC_SEPIA:
            CamWriteCmosSensor(0xB6, 0x80); 
            CamWriteCmosSensor(0xB7, 0x60);
            //CamWriteCmosSensor(0xB8, 0xB8);
            CamWriteCmosSensor(0xB8, 0xCC);
            break;
        case CAM_EFFECT_ENC_SEPIAGREEN:
            CamWriteCmosSensor(0xB6, 0x80);
            CamWriteCmosSensor(0xB7, 0x50);
            CamWriteCmosSensor(0xB8, 0x50);
            break;
        case CAM_EFFECT_ENC_SEPIABLUE:
            CamWriteCmosSensor(0xB6, 0x80);
            CamWriteCmosSensor(0xB7, 0xC0);
            CamWriteCmosSensor(0xB8, 0x60);
            break;
        case CAM_EFFECT_ENC_COLORINV:
            CamWriteCmosSensor(0xB6, 0x10);
            break;
        case CAM_EFFECT_ENC_GRAYINV:
            CamWriteCmosSensor(0xB6, 0x20);
            break;
        case CAM_EFFECT_ENC_EMBOSSMENT:
            CamWriteCmosSensor(0xB6, 0x08);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }   
  
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV120BContrast
*
* DESCRIPTION
*    Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV120BContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Contrast->IsSupport = KAL_TRUE;
    Contrast->ItemCount = 3;
    Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
    Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
  	SIV120B_set_page(3);    //bank 3
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:
		CamWriteCmosSensor(0xA8, 0x16);
		break;
    case CAM_CONTRAST_MEDIUM: 
		CamWriteCmosSensor(0xA8, 0x0b);
		break;
    case CAM_CONTRAST_LOW:    
		CamWriteCmosSensor(0xA8, 0x04);
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV120BBanding
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
MM_ERROR_CODE_ENUM SIV120BBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
		SIV120BSetBandingStep((CAL_CAMERA_BANDING_FREQ_ENUM)(In->FeatureSetValue));
		break;
		
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV120BAeEnable
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
static MM_ERROR_CODE_ENUM SIV120BAeEnable(kal_bool Enable)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
  kal_uint8 seq_preview_ae = 0;

  if (SIV120BSensor.BypassAe)
    {
        Enable = KAL_FALSE;
    }

  if (Enable)
  {
	  seq_preview_ae = 0x80;
  }
  else
  {
	  seq_preview_ae = 0x00;
  }

  SIV120B_set_page(1);
  CamWriteCmosSensor(0x10, seq_preview_ae);

  return ErrCode;
}


/*************************************************************************
* FUNCTION
*    SIV120BAwbEnable
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
static MM_ERROR_CODE_ENUM SIV120BAwbEnable(kal_bool Enable)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
  kal_uint8 seq_preview_awb = 0;

  if (SIV120BSensor.BypassAwb)
    {
        Enable = KAL_FALSE;
    }

  if (Enable)
  {
	  seq_preview_awb = 0xC3;
  }
  else
  {
	  seq_preview_awb = 0x00;
  }

  SIV120B_set_page(2);
  CamWriteCmosSensor(0x10, seq_preview_awb);

  return ErrCode;
}

void SIV120BGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo)
{
	SensorInfo->SensorId			=	SIV120B_SENSOR_ID;
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

	SensorInfo->PreviewMclkFreq	=	24000000;
	SensorInfo->CaptureMclkFreq	=	24000000;
	SensorInfo->VideoMclkFreq		=	24000000;

	SensorInfo->PreviewWidth		=	SIV120B_PV_GRAB_WIDTH;
	SensorInfo->PreviewHeight		=	SIV120B_PV_GRAB_HEIGHT;
	SensorInfo->FullWidth			=	SIV120B_FULL_GRAB_WIDTH;
	SensorInfo->FullHeight			=	SIV120B_FULL_GRAB_WIDTH;

	SensorInfo->SensorAfSupport	=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
} /* SIV120BGetSensorInfo() */


MM_ERROR_CODE_ENUM SIV120BStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT Capsize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);

	switch (In->FeatureCtrlCode)
	{
	case CAL_FEATURE_QUERY_OPERATION:
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION 
									| CAL_FEATURE_GET_OPERATION 
									| CAL_FEATURE_QUERY_OPERATION;
		
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		
		Capsize->IsSupport = KAL_TRUE;
		Capsize->ItemCount = 2;
		Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
		Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	return ErrCode;
}   /* SIV120BStillCaptureSize() */

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
kal_uint32 SIV120BDetectSensorId(void)
{
    kal_uint32 SensorId=0;
	IMAGE_SENSOR_INDEX_ENUM ToPdnIdx = (IMAGE_SENSOR_MAIN == SIV120BSensor.SensorIdx ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = SIV120BPowerOn();
			
			SIV120BSensorClose();
			
			if (SIV120B_SENSOR_ID == SensorId)
			{
				return SIV120B_SENSOR_ID;
			}
		}
	}

    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* SIV120BDetectSensorId() */


void SIV120BInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;		/* wait stable frame when sensor change mode (cap to pre) */

} /* SIV120BInitOperationPara() */

kal_uint32 SIV120BPowerOn(void)
{
    kal_uint32 SensorId = 0;

#if (!defined(DUAL_CAMERA_SUPPORT))  ////S5K4ECGX+SIV120B

	/* Configure the default reset & power down state. */
	SIV120B_SET_RST_LOW;
	SIV120B_SET_PDN_LOW;
#endif
    /* PowerOn the sensor */
    CisModulePowerOn(SIV120BSensor.SensorIdx, KAL_TRUE);
	
#if (defined(DUAL_CAMERA_SUPPORT))
	{
		CamRstPinCtrl(IMAGE_SENSOR_MAIN, 0);
		CamPdnPinCtrl(IMAGE_SENSOR_MAIN, 0);
		CamPdnPinCtrl(IMAGE_SENSOR_SUB, 0);
	
		
		kal_sleep_task(1); /*delay  to wait for stable power*/
			
		CamPdnPinCtrl(IMAGE_SENSOR_MAIN, 1);
		
		CamPdnPinCtrl(IMAGE_SENSOR_SUB, 1);
		kal_sleep_task(1); 		/*>15us*/
		CamRstPinCtrl(IMAGE_SENSOR_MAIN, 1);
	
		kal_sleep_task(1); 		/*>15us*/

		if(SIV120BSensor.SensorIdx==IMAGE_SENSOR_SUB)
		{
			CamPdnPinCtrl(IMAGE_SENSOR_MAIN, 0);
		}
		else
		{
			CamPdnPinCtrl(IMAGE_SENSOR_SUB, 0);
		}
		kal_sleep_task(1); 		/*>15us*/
	
	
	}
#endif

    kal_sleep_task(1);  /* delay for power stable */
	CameraSccbOpen(CAMERA_SCCB_SENSOR, SIV120B_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);

	SIV120B_SET_PDN_HIGH;
	kal_sleep_task(1);

    /* Reset the sensor */

	
#if (!defined(DUAL_CAMERA_SUPPORT))
	SIV120B_SET_RST_HIGH;
    kal_sleep_task(2);  /* delay for stable sensor */
#endif

    /* Read Sensor ID  */
    SIV120B_set_page(0);
    SensorId = CamReadCmosSensor(0x01);

	SIV120B_TRACE("Sensor_id = %x", SensorId);

    return SensorId;
} /* SIV120BPowerOn() */

MM_ERROR_CODE_ENUM SIV120BPreview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

	SIV120B_TRACE("[SIV120BPreview] %dX%d, night=%d", \
		In->ImageTargetWidth, In->ImageTargetHeight, In->NightMode);
	SIV120BCurrScenario = ScenarioId;
	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		SIV120BSensor.MaxFrameRate = In->MaxVideoFrameRate;
		SIV120BSensor.MinFrameRate = In->MaxVideoFrameRate;

		Out->WaitStableFrameNum = 10;
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		SIV120BSensor.MaxFrameRate = SIV120B_MAX_CAMERA_FPS;
		SIV120BSensor.MinFrameRate = 10 *  SIV120B_FRAME_RATE_UNIT;
		if (In->NightMode)
		{
			SIV120BSensor.MinFrameRate = SIV120BSensor.MinFrameRate >> 1;
		}
		
		Out->WaitStableFrameNum = 10;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	SIV120BSetMirrorFlip(In->ImageMirror);
	
	SIV120BSetFrameRate(SIV120BSensor.MinFrameRate, SIV120BSensor.MaxFrameRate);
	SIV120BSetBandingStep(In->BandingFreq);

	SIV120BSetNightMode(ScenarioId, In->NightMode);

	Out->GrabStartX = SIV120B_PV_GRAB_START_X;
	Out->GrabStartY = SIV120B_PV_GRAB_START_Y;
	if(CAL_SCENARIO_VIDEO==ScenarioId)
	{
		Out->ExposureWindowWidth = SIV120B_PV_GRAB_WIDTH-8;
		Out->ExposureWindowHeight = SIV120B_PV_GRAB_HEIGHT-6;
	}
	else
	{
		Out->ExposureWindowWidth = SIV120B_PV_GRAB_WIDTH;
		Out->ExposureWindowHeight = SIV120B_PV_GRAB_HEIGHT;
	}
	return ErrCode;
} /* SIV120BPreview */

MM_ERROR_CODE_ENUM SIV120BCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	Out->GrabStartX = SIV120B_FULL_GRAB_START_X;
	Out->GrabStartY = SIV120B_FULL_GRAB_START_Y;
	Out->ExposureWindowWidth = SIV120B_FULL_GRAB_WIDTH;
	Out->ExposureWindowHeight = SIV120B_FULL_GRAB_HEIGHT;
	
	return MM_ERROR_NONE;
} /* SIV120BCapture() */

/*************************************************************************
* FUNCTION
*    SIV120BSensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIV120BSensorOpen(void)
{
    if (SIV120BPowerOn() != SIV120B_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }

	SIV120BSensor.MaxFrameRate = SIV120B_MAX_CAMERA_FPS;
	SIV120BSensor.MinFrameRate = SIV120B_MAX_CAMERA_FPS;
    SIV120BSensor.BandingFreq = CAM_BANDING_50HZ;
    SIV120B_Control = 0x00;

	SIV120BInitialSetting();
	
    //SIV120BSetFrameRate(SIV120BSensor.MinFrameRate, SIV120BSensor.MaxFrameRate);

    return MM_ERROR_NONE;
} /* SIV120BSensorOpen() */

/*************************************************************************
* FUNCTION
*    SIV120BSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM SIV120BSensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);	
	
	if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
	{
		return SIV120BWebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
	}
	
	if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
	}
	
	switch (id)
	{
		/* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
		ErrCode = SIV120BEV(In, Out);
		break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    	ErrCode = SIV120BContrast(In, Out);
    	break;
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
    case CAL_FEATURE_CAMERA_WB:
		ErrCode = SIV120BWB(In, Out);
		break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
		ErrCode = SIV120BEffect(In, Out);
		break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
		ErrCode = SIV120BStillCaptureSize(In, Out);
		break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
		ErrCode = SIV120BBanding(In, Out);
		break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
    	ErrCode = SIV120BSceneMode(KAL_TRUE, In, Out);
   		break;
  	case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
   		ErrCode = SIV120BSceneMode(KAL_FALSE, In, Out);
    break;	
    case CAL_FEATURE_CAMERA_FLASH_MODE:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
		
		/* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
		SIV120BGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV120BDetectSensorId();
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV120BSensor.MaxFrameRate;
		break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
		SIV120BInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
		break;
	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(SIV120BSensor.SensorIdx, 0);
		CamRstPinCtrl(SIV120BSensor.SensorIdx, 0);
		break;
		/* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
		SIV120BSensor.curr_frame_time = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
		break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
		SIV120BSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
		break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
		break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		SIV120BSensor.BypassAe = *(kal_bool *)In;
        SIV120BAeEnable(SIV120BSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		SIV120BSensor.BypassAwb = *(kal_bool *)In;
        SIV120BAwbEnable(SIV120BSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(SIV120BSensor.SensorIdx, Out);
	    break;
    default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}
	
	return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SIV120BSensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    out_len: Out parameter length
*    RealOutLen: Real out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV120BSensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *RealOutLen)
{
  switch (id)
  {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
		SIV120BPreview(id, In, Out);
		break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
		SIV120BCapture(id, In, Out);
		break;
    default:
		break;
  }
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV120BSensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIV120BSensorClose(void)
{
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
	CisModulePowerOn(SIV120BSensor.SensorIdx, KAL_FALSE);

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV120BSensorFunc
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
MM_ERROR_CODE_ENUM SIV120BSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIV120B=
	{
		SIV120BSensorOpen,
		SIV120BSensorFeatureCtrl,
		SIV120BSensorCtrl,
		SIV120BSensorClose,
	};

	*pfSensorFunc = &ImageSensorFuncSIV120B;

	return MM_ERROR_NONE;
}

#ifdef __SIV120B_DEBUG_TRACE__
static kal_bool SIV120BAtGetValue(char *Str, kal_uint32 *Data)
{
    extern int isdigit(int c);
    extern int isxdigit(int c);
    extern int tolower(int c);
    char CmdName[15];
    kal_uint8 TmpIdx = 0, Index = 3;
    kal_uint32 Value;

    while (Str[Index] != '=' && Str[Index] != 13)
    {
        CmdName[TmpIdx++] = Str[Index++];
    }
    CmdName[TmpIdx] = '\0';

    if (strcmp(CmdName, "DO"))
    {
        return KAL_FALSE;
    }
    Value = Data[0] = 0;
    while (1)
    {
        TmpIdx = Str[++Index];
        switch (TmpIdx)
        {
        case 13:
        case ',':
            Data[++Data[0]] = Value;
            if (Data[0] == 9 || TmpIdx == 13)
            {
                return KAL_TRUE;
            }
            Value = 0;
            break;
        default:
            if (isdigit(TmpIdx))
            {
                Value = Value * 16 + TmpIdx - '0';
            }
            else if (isxdigit(TmpIdx))
            {
                Value = Value * 16 + tolower(TmpIdx) - 'a' + 10;
            }
            else
            {
                return KAL_TRUE;
            }
            break;
        }
    }
}

kal_bool AtFuncTest(kal_char *Str)
{
    kal_uint32 Data[10];

    if (!SIV120BAtGetValue(Str, Data))
    {
        return KAL_FALSE;
    }
    if (!Data[0])
    {
        return KAL_TRUE;
    }
	
    switch (Data[1])
    {
    case 0x00:
        {
            extern kal_uint32 IspCurrentFrameRate;

            SIV120B_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
        }
        break;
    case 0x02:
        SIV120B_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        SIV120B_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        SIV120B_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        SIV120B_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        SIV120B_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        SIV120B_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x09:
        break;
    case 0x0A:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                SIV120B_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    case 0x0B:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                SIV120B_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    default:
        break;
    }
    return KAL_TRUE;
}
#endif


