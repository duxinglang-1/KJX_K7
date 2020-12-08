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
 *   image_sensor_SIV121D.c
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

 *
 *=============================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-
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


//#define __SIV121D_DEBUG_INFO__

/* Global Valuable */
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#define SIV121D_SOURCE_CLK      52000000
#else
#define SIV121D_SOURCE_CLK      48000000
#endif
#define SIV121D_PCLK        (SIV121D_SOURCE_CLK / SIV121D_mclk_div)

static kal_uint8 SIV121D_g_iBanding = CAM_BANDING_50HZ;

static kal_uint8 SIV121D_Control = 0x00;
static kal_uint16 SIV121D_Dummy_Pixel = 0x1c; // for user customization
static kal_uint16 SIV121D_Hblank = 0x1c;       //for calculating shutter step

static kal_uint8 SIV121D_mclk_div = 2;

kal_uint32 SIV121DMaxFrameRate = SIV121D_MAX_CAMERA_FPS;
kal_uint32 SIV121DMinFrameRate = SIV121D_MAX_CAMERA_FPS;

CAL_SCENARIO_ENUM SIV121DCurrScenario = CAL_SCENARIO_CAMERA_PREVIEW;
SIV121D_SENSOR_INFO_ST SIV121D_sensor; 

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

// for HAL
IMAGE_SENSOR_INDEX_ENUM SensorIdxSIV121D;

static void SIV121D_set_page(kal_uint8 iPage)
{
    CamWriteCmosSensor(0x00,iPage);
}
 
/*************************************************************************
* FUNCTION
*    SIV121D_half_adjust
*
* DESCRIPTION
*    This function dividend / divisor and use round-up.
*
* PARAMETERS
*    dividend
*    divisor
*
* RETURNS
*    [dividend / divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 SIV121D_half_adjust(kal_uint32 dividend, kal_uint32 divisor)
{
  return (dividend * 2 + divisor) / (divisor * 2); /* that is [dividend / divisor + 0.5]*/
}


/*************************************************************************
* FUNCTION
*   SIV121DSetShutterStep
*
* DESCRIPTION
*   This function is to calculate & set shutter step register .
*
*************************************************************************/
static void SIV121DSetShutterStep(void)
{
    const kal_uint8 banding = SIV121D_g_iBanding == CAM_BANDING_50HZ ? SIV121D_NUM_50HZ : SIV121D_NUM_60HZ;
    const kal_uint16 shutter_step = SIV121D_half_adjust(SIV121D_PCLK / 2, (SIV121D_Hblank + SIV121D_PERIOD_PIXEL_NUMS) * banding);

    ASSERT(shutter_step <= 0xFF);
    /* Block 1:0x34  shutter step*/
    SIV121D_set_page(2);
    CamWriteCmosSensor(0x34,shutter_step);
#ifdef __SIV121D_DEBUG_INFO__
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",shutter_step);
#endif
}/* SIV121DSetShutterStep */


/*************************************************************************
* FUNCTION
*   SIV121DConfigHVBlanking
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
static void SIV121DConfigHVBlanking(kal_uint16 hblank,kal_uint16 vblank)
{
#ifdef __SIV121D_DEBUG_INFO__
    kal_wap_trace(MOD_ENG,TRACE_INFO,"hblank:%x,vblank:%x",hblank,vblank);
#endif
   /********************************************
    *   Register :0x20 - 0x22
    *  Block 00
    *  0x20  [7:4]:HBANK[9:8]; 0x20  [3:0]:VBANK[9:8]
    *  0x21 HBANK[7:0]
    *  0x23 VBANK[7:0]
    ********************************************/
    ASSERT(hblank <= SIV121D_BLANK_REGISTER_LIMITATION && vblank <= SIV121D_BLANK_REGISTER_LIMITATION);
    SIV121D_set_page(1);
    CamWriteCmosSensor(0x20,((hblank>>4)&0xF0)|((vblank>>8)&0x0F));
    CamWriteCmosSensor(0x21,hblank & 0xFF);
    CamWriteCmosSensor(0x23,vblank & 0xFF);
    SIV121DSetShutterStep();
}   /* SIV121DConfigHVBlanking */






/*************************************************************************
* FUNCTION
*	SIV121D_set_dummy
*
* DESCRIPTION
*	This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*	used to adjust the frame rate or gain more time for back-end process.
*	
*	IMPORTANT NOTICE: the base shutter need re-calculate for some sensor, or else flicker may occur.
*
* PARAMETERS
*	1. kal_uint32 : Dummy Pixels (Horizontal Blanking)
*	2. kal_uint32 : Dummy Lines (Vertical Blanking)
*
* RETURNS
*	None
*
*************************************************************************/
static void SIV121D_set_dummy(kal_uint32 dummy_pixels, kal_uint32 dummy_lines)
{

	
	kal_uint32 temp_reg1, temp_reg2;
		//kal_uint32 temp_reg, base_shutter = 0xa2;
		CamWriteCmosSensor(0x00,01);
     CamWriteCmosSensor(0x20,((dummy_pixels>>4)&0xF0)|((dummy_lines>>8)&0x0F));
     CamWriteCmosSensor(0x21,dummy_pixels & 0xFF);
     CamWriteCmosSensor(0x23,dummy_lines & 0xFF);

    kal_wap_trace(MOD_ENG, TRACE_INFO, "20'h =%x, 21'h=%x, 22'h=%x\r\n", CamReadCmosSensor(0x20),CamReadCmosSensor(0x21),CamReadCmosSensor(0x22));	 
      CamWriteCmosSensor(0x00,02);
		
	kal_wap_trace(MOD_ENG,TRACE_INFO,"34'h =%x\r\r",CamReadCmosSensor(0x34));
     
	
	
}    /* SIV121D_set_dummy */


/*************************************************************************
* FUNCTION
*	SIV121D_read_shutter
*
* DESCRIPTION
*	This function read current shutter for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current shutter value.
*
*************************************************************************/
static kal_uint32 SIV121D_read_shutter(void)
{
#if 1
	kal_uint16 temp_reg1, temp_reg2;
	SIV121D_write_cmos_sensor(0x00,0x02);
	temp_reg1 = CamReadCmosSensor(0x30);    // AEC[b7~b0]
	temp_reg2 = CamReadCmosSensor(0x31);    // AEC[b15~b8]
	/* Backup the preview mode last shutter & sensor gain. */
	SIV121D_sensor.pv_shutter = (temp_reg1 <<8)  | (temp_reg2 & 0xFF);
	
   
	
	return SIV121D_sensor.pv_shutter ;
	#endif
}    /* SIV121D_read_shutter */


/*************************************************************************
* FUNCTION
*   SIV121DSetAeBaseShutter
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void SIV121DSetAeBaseShutter(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq, kal_uint32 MinFrameRate)
{
    kal_uint16 Frame_Count = 0;
	kal_uint32 banding = SIV121D_NUM_50HZ;

	// TODO: Right   ???

	if (BandingFreq == CAM_BANDING_50HZ)
	{
		banding = SIV121D_NUM_50HZ;
	}
	else
	{
		banding = SIV121D_NUM_60HZ;
	}

    Frame_Count = banding * SIV121D_FRAME_RATE_UNIT / MinFrameRate;
	
#ifdef __SIV121D_DEBUG_INFO__
    kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,Frame_Count:%x",MinFrameRate/SIV121D_FRAME_RATE_UNIT,Frame_Count);
#endif

    /*Block 01: 0x11  Max shutter step,for Min frame rate */
    SIV121D_set_page(2);
    CamWriteCmosSensor(0x11,Frame_Count&0xFF);
}/* SIV121DSetAeBaseShutter */


/*************************************************************************
* FUNCTION
*    SIV121DCalculateFrameRate
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
static void SIV121DCalculateFrameRate(kal_uint32 MinFrameRate, kal_uint32 MaxFrameRate)
{
    kal_int16 Line_length,Dummy_Line;

	// TODO: dummy pixels.
    Line_length = SIV121D_Dummy_Pixel + SIV121D_PERIOD_PIXEL_NUMS;

    Dummy_Line = SIV121D_PCLK * SIV121D_FRAME_RATE_UNIT / (2 * Line_length * MaxFrameRate) - SIV121D_PERIOD_LINE_NUMS;
    if(Dummy_Line > SIV121D_BLANK_REGISTER_LIMITATION)
    {
        Dummy_Line = SIV121D_BLANK_REGISTER_LIMITATION;
        Line_length = SIV121D_PCLK * SIV121D_FRAME_RATE_UNIT / (2 * (Dummy_Line + SIV121D_PERIOD_LINE_NUMS) * MaxFrameRate);
    }
    SIV121D_Hblank = Line_length -  SIV121D_PERIOD_PIXEL_NUMS;
#ifdef __SIV121D_DEBUG_INFO__
   kal_wap_trace(MOD_ENG,TRACE_INFO, "MaxFrameRate:%d",MaxFrameRate/SIV121D_FRAME_RATE_UNIT);
   kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,Hblank:%x,Vblank:%x",SIV121D_Dummy_Pixel,SIV121D_Hblank,Dummy_Line);
#endif
    SIV121DConfigHVBlanking((SIV121D_Hblank > 0) ? SIV121D_Hblank : 0, (Dummy_Line > 0) ? Dummy_Line : 0);

}


/*************************************************************************
* FUNCTION
*   SIV121DSetFixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
 static void SIV121DSetFixFrameRate(kal_bool IsFixFrameRate)
 {
	 if (IsFixFrameRate == KAL_TRUE)
	 {
		 SIV121D_Control |= 0xC0;
		 SIV121D_set_page(1);
		 CamWriteCmosSensor(0x04, SIV121D_Control);
	 }
	 else
	 {
		 SIV121D_Control &= 0x3F;
		 SIV121D_set_page(1);
		 CamWriteCmosSensor(0x04, SIV121D_Control);

	 }
 }	/* SIV121DSetFixFrameRate */


/*************************************************************************
* FUNCTION
*   SIV121DSetNightMode
*
* DESCRIPTION
*   This function switch on/off night mode of SIV121D.
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIV121DSetNightMode(CAL_SCENARIO_ENUM ScenarioId, 
								kal_bool night_enalbe)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
#ifdef    __SIV121D_DEBUG_INFO__
    kal_wap_trace(MOD_ENG,TRACE_INFO, "NightMode %d", night_enalbe);
#endif

	if (night_enalbe == KAL_TRUE)
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			SIV121DSetFixFrameRate(KAL_TRUE);
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			//SIV121DSetFixFrameRate(KAL_FALSE);
			SIV121D_set_page(2);
            CamWriteCmosSensor(0x40,0x6c); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
            SIV121D_set_page(4);
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
			SIV121DSetFixFrameRate(KAL_TRUE);
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			//SIV121DSetFixFrameRate(KAL_FALSE);
			SIV121D_set_page(2);
            CamWriteCmosSensor(0x40,0x66);// 0x7F
            SIV121D_set_page(4);
            CamWriteCmosSensor(0xB9,0x18);
            CamWriteCmosSensor(0xBA,0x30); //Slope
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}

	//SIV121DCalculateFrameRate(SIV121DMinFrameRate, SIV121DMaxFrameRate);
	//SIV121DSetAeBaseShutter(In->BandingFreq, SIV121DMinFrameRate);

	return ErrCode;
}   /* SIV121DSetNightMode */

/*************************************************************************
* FUNCTION
*   SIV121DWriteInitialSetting
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
static void SIV121DWriteInitialSetting(void)
{
	//ChipID SIV121D // Don't delete or edit this line !!!
	// This file is for "Internal V1.3". ================
	// SIV121D_090914.txt
	//[Addr] [Data]
	
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
	
	
		// IO & Clock & Analog Setup
		//Sensor On
		// PMU
		CamWriteCmosSensor(0x00, 0x00);
		CamWriteCmosSensor(0x03, 0x04);
		CamWriteCmosSensor(0x10, 0x85);
		CamWriteCmosSensor(0x11, 0x11);	
	 
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x04, 0x00); 
		CamWriteCmosSensor(0x06, 0x04); 
			 
		CamWriteCmosSensor(0x10, 0x43); 
		CamWriteCmosSensor(0x11, 0x23); 
		CamWriteCmosSensor(0x12, 0x21);
			 
		CamWriteCmosSensor(0x17, 0x86); //ABS 1.74V
		CamWriteCmosSensor(0x18, 0x00);
			  
		CamWriteCmosSensor(0x20, 0x00);
		CamWriteCmosSensor(0x21, 0x05);
		CamWriteCmosSensor(0x22, 0x01);
		CamWriteCmosSensor(0x23, 0x69);
			 
		CamWriteCmosSensor(0x40, 0x0F); 
		CamWriteCmosSensor(0x41, 0x10);//0x90
		CamWriteCmosSensor(0x42, 0x52);//0xd2
		CamWriteCmosSensor(0x43, 0x00);
		
	// AE
		CamWriteCmosSensor(0x00, 0x02);
		CamWriteCmosSensor(0x10, 0x80);
		CamWriteCmosSensor(0x11, 0x0d);		
		CamWriteCmosSensor(0x12, 0x60); // D65 target 
		CamWriteCmosSensor(0x14, 0x5c); // A target
		CamWriteCmosSensor(0x16, 0x00);
		CamWriteCmosSensor(0x19, 0xca);		
		CamWriteCmosSensor(0x1a, 0x02);		
		CamWriteCmosSensor(0x34, 0x96);
		CamWriteCmosSensor(0x40, 0x40); // Max x6
		CamWriteCmosSensor(0x5f, 0x01);
		CamWriteCmosSensor(0x90, 0x80);
		CamWriteCmosSensor(0x91, 0x80);
		
	// AWB
		CamWriteCmosSensor(0x00, 0x03);
		CamWriteCmosSensor(0x10, 0xd3);
		CamWriteCmosSensor(0x11, 0xc0);
		CamWriteCmosSensor(0x13, 0x7f); //Cr target
		CamWriteCmosSensor(0x14, 0x7f); //Cb target
		CamWriteCmosSensor(0x15, 0xd8); // R gain Top
		CamWriteCmosSensor(0x16, 0x7c); // R gain bottom 
		CamWriteCmosSensor(0x17, 0xe5); // B gain Top
		CamWriteCmosSensor(0x18, 0x80); // B gain bottom 0x80
		CamWriteCmosSensor(0x19, 0x8c); // Cr top value 0x90
		CamWriteCmosSensor(0x1a, 0x64); // Cr bottom value 0x70
		CamWriteCmosSensor(0x1b, 0x9c); // Cb top value 0x90
		CamWriteCmosSensor(0x1c, 0x72); // Cb bottom value 0x70
		CamWriteCmosSensor(0x1d, 0x94); // 0xa0
		CamWriteCmosSensor(0x1e, 0x6c); // 0x60
		CamWriteCmosSensor(0x20, 0xe8); // AWB luminous top value
		CamWriteCmosSensor(0x21, 0x30); // AWB luminous bottom value 0x20
		CamWriteCmosSensor(0x22, 0xb8);
		CamWriteCmosSensor(0x23, 0x10);
		CamWriteCmosSensor(0x25, 0x20);
		CamWriteCmosSensor(0x26, 0x0f);
		CamWriteCmosSensor(0x27, 0x10); // BRTSRT 
		CamWriteCmosSensor(0x28, 0x20); // BRTEND
		CamWriteCmosSensor(0x29, 0xd8); // BRTRGNBOT 
		CamWriteCmosSensor(0x2a, 0x90); // BRTBGNTOP
											
		CamWriteCmosSensor(0x40, 0x01);
		CamWriteCmosSensor(0x41, 0x04);
		CamWriteCmosSensor(0x42, 0x08);
		CamWriteCmosSensor(0x43, 0x10);
		CamWriteCmosSensor(0x44, 0x12);
		CamWriteCmosSensor(0x45, 0x35);
		CamWriteCmosSensor(0x46, 0x86);
	
		CamWriteCmosSensor(0x63, 0x90); // R D30 to D20
		CamWriteCmosSensor(0x64, 0xe0); // B D30 to D20
		CamWriteCmosSensor(0x65, 0x90); // R D20 to D30
		CamWriteCmosSensor(0x66, 0xe0); // B D20 to D30
		
	// IDP
		CamWriteCmosSensor(0x00, 0x04);
		CamWriteCmosSensor(0x10, 0xff);
		CamWriteCmosSensor(0x11, 0x1d);
		CamWriteCmosSensor(0x12, 0xfd);
		
	// DPCBNR
		CamWriteCmosSensor(0x18, 0xfe);	// DPCNRCTRL
		CamWriteCmosSensor(0x19, 0x04);	// DPCTHV
		CamWriteCmosSensor(0x1A, 0x01);	// DPCTHVSLP
		CamWriteCmosSensor(0x1B, 0x08);	// DPCTHVDIFSRT
		CamWriteCmosSensor(0x1C, 0x08);	// DPCTHVDIFSLP
		CamWriteCmosSensor(0x1d, 0xFF);	// DPCTHVMAX
		
		CamWriteCmosSensor(0x1E, 0x04);	// BNRTHV  0c
		CamWriteCmosSensor(0x1F, 0x04);	// BNRTHVSLPN 10
		CamWriteCmosSensor(0x20, 0x10);	// BNRTHVSLPD
		CamWriteCmosSensor(0x21, 0x00);	// BNRNEICNT
		CamWriteCmosSensor(0x22, 0x10);	// STRTNOR
		CamWriteCmosSensor(0x23, 0x40);	// STRTDRK
		
	// Gamma
		CamWriteCmosSensor(0x31, 0x04); //0x08
		CamWriteCmosSensor(0x32, 0x0f); //0x10
		CamWriteCmosSensor(0x33, 0x24); //0x1B
		CamWriteCmosSensor(0x34, 0x46); //0x37
		CamWriteCmosSensor(0x35, 0x62); //0x4D
		CamWriteCmosSensor(0x36, 0x78); //0x60
		CamWriteCmosSensor(0x37, 0x8b); //0x72
		CamWriteCmosSensor(0x38, 0x9B); //0x82
		CamWriteCmosSensor(0x39, 0xA8); //0x91
		CamWriteCmosSensor(0x3a, 0xb6); //0xA0
		CamWriteCmosSensor(0x3b, 0xcc); //0xBA
		CamWriteCmosSensor(0x3c, 0xe0); //0xD3
		CamWriteCmosSensor(0x3d, 0xf0); //0xEA
		
	// Shading Register Setting 				 
		CamWriteCmosSensor(0x40, 0x0a);						   
		CamWriteCmosSensor(0x41, 0x66);						   
		CamWriteCmosSensor(0x42, 0x66);						   
		CamWriteCmosSensor(0x43, 0x55);						   
		CamWriteCmosSensor(0x44, 0x33); // left R gain[7:4], right R gain[3:0] 						
		CamWriteCmosSensor(0x45, 0x11); // top R gain[7:4], bottom R gain[3:0] 						 
		CamWriteCmosSensor(0x46, 0x00); // left G gain[7:4], right G gain[3:0] 	  
		CamWriteCmosSensor(0x47, 0x00); // top G gain[7:4], bottom G gain[3:0] 	  
		CamWriteCmosSensor(0x48, 0x10); // left B gain[7:4], right B gain[3:0] 	  
		CamWriteCmosSensor(0x49, 0x10); // top B gain[7:4], bottom B gain[3:0] 	 
		CamWriteCmosSensor(0x4a, 0x04); // X-axis center high[3:2], Y-axis center high[1:0]	 
		CamWriteCmosSensor(0x4b, 0x50); // X-axis center low[7:0]						
		CamWriteCmosSensor(0x4c, 0xe0); // Y-axis center low[7:0]					   
		CamWriteCmosSensor(0x4d, 0x80); // Shading Center Gain
		CamWriteCmosSensor(0x4e, 0x00); // Shading R Offset   
		CamWriteCmosSensor(0x4f, 0x00); // Shading Gr Offset  
		CamWriteCmosSensor(0x50, 0x00); // Shading B Offset  
		
	// Interpolation
		CamWriteCmosSensor(0x60,  0x7f);
		CamWriteCmosSensor(0x61,  0x08);	// INTCTRL outdoor
		
	// Color matrix (D65) - Daylight
		CamWriteCmosSensor(0x71, 0x38);	 
		CamWriteCmosSensor(0x72, 0xCa);	 
		CamWriteCmosSensor(0x73, 0xFe);	 
		CamWriteCmosSensor(0x74, 0x13);	 
		CamWriteCmosSensor(0x75, 0x2b);	 
		CamWriteCmosSensor(0x76, 0x02);	 
		CamWriteCmosSensor(0x77, 0xF2);	
		CamWriteCmosSensor(0x78, 0xC7);	 
		CamWriteCmosSensor(0x79, 0x47);	 
		
	// Color matrix (D20) - A
		CamWriteCmosSensor(0x83, 0x38); //0x3c 	
		CamWriteCmosSensor(0x84, 0xd1); //0xc6 	
		CamWriteCmosSensor(0x85, 0xf7); //0xff   
		CamWriteCmosSensor(0x86, 0x12); //0x12    
		CamWriteCmosSensor(0x87, 0x25); //0x24 	
		CamWriteCmosSensor(0x88, 0x09); //0x0a 	
		CamWriteCmosSensor(0x89, 0xed); //0xed   
		CamWriteCmosSensor(0x8a, 0xbb); //0xc2 	
		CamWriteCmosSensor(0x8b, 0x58); //0x51
		
		CamWriteCmosSensor(0x8c, 0x10); //CMA select	  
		
	//G Edge
		CamWriteCmosSensor(0x90, 0x14); //Upper gain
		CamWriteCmosSensor(0x91, 0x18); //down gain
		CamWriteCmosSensor(0x92, 0x22); //[7:4] upper coring [3:0] down coring
		CamWriteCmosSensor(0x9c, 0x38); //edge suppress start
		CamWriteCmosSensor(0x9d, 0x30); //edge suppress slope
		
		CamWriteCmosSensor(0xa9, 0x11);
		CamWriteCmosSensor(0xaa, 0x11);
		
		CamWriteCmosSensor(0xb9, 0x38); // nightmode 38 at gain 0x48 5fps
		CamWriteCmosSensor(0xba, 0x35); // nightmode 80 at gain 0x48 5fps
	
		CamWriteCmosSensor(0xc0, 0x24);	 
		CamWriteCmosSensor(0xc1, 0x00);	 
		CamWriteCmosSensor(0xc2, 0x80);	
		CamWriteCmosSensor(0xc3, 0x00);	 
		CamWriteCmosSensor(0xc4, 0xe0);	 
		
		CamWriteCmosSensor(0xde, 0x80);
		
		CamWriteCmosSensor(0xe5, 0x15); //MEMSPDA
		CamWriteCmosSensor(0xe6, 0x02); //MEMSPDB
		CamWriteCmosSensor(0xe7, 0x04); //MEMSPDC
		
	//Sensor On  
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x03, 0x01); // SNR Enable
	
	
	#endif
	

	//SIV121D_sensor.preview_pclk = 240;

}   /* SIV121DWriteInitialSetting */

/*************************************************************************
* FUNCTION
*   SIV121DSetMirrorFlip
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
 static void SIV121DSetMirrorFlip(IMAGE_SENSOR_MIRROR_ENUM ImageMirrorFlip)
 {
	 SIV121D_Control = SIV121D_Control & 0xFC;

	 switch (ImageMirrorFlip)
	 {
	 case IMAGE_SENSOR_MIRROR_NORMAL:
		 SIV121D_Control |= 0x00;
		 break;
	 case IMAGE_SENSOR_MIRROR_H:
		 SIV121D_Control |= 0x01;
		 break;
	 case IMAGE_SENSOR_MIRROR_V:
		 SIV121D_Control |= 0x02;
		 break;
	 case IMAGE_SENSOR_MIRROR_HV:
		 SIV121D_Control |= 0x03;
		 break;
	 default:
		 ASSERT(0);
	 }

	 SIV121D_set_page(1);
	 CamWriteCmosSensor(0x04,SIV121D_Control);
 }   /* SIV121DSetMirrorFlip */


/*************************************************************************
* FUNCTION
*    SIV121DSceneMode
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
static MM_ERROR_CODE_ENUM SIV121DSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    if (SIV121D_sensor.NightMode != Enable)
    {
      
	SIV121DSetNightMode(SIV121DCurrScenario, Enable);
      
      SIV121D_sensor.NightMode = Enable;
    }   
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV121DEV
*
* DESCRIPTION
*    SIV121D EV setting.
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
static MM_ERROR_CODE_ENUM SIV121DEV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV121D_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"EV:%d",iEvTemp);
#endif

    SIV121D_set_page(4); //bank 4
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3:    // -4 EV
        CamWriteCmosSensor(0xab,0xc0); 
        break;

    case CAM_EV_NEG_3_3:    // -3 EV
          CamWriteCmosSensor(0xab,0xb0); 
        break;

    case CAM_EV_NEG_2_3:    // -2 EV
          CamWriteCmosSensor(0xab,0xa0); 
        break;

    case CAM_EV_NEG_1_3:    // -1 EV
         CamWriteCmosSensor(0xab,0x90); 
        break;

    case CAM_EV_ZERO:   // +0 EV
          CamWriteCmosSensor(0xab,0x00); 
        break;
		
    case CAM_EV_POS_1_3:    // +1 EV
          CamWriteCmosSensor(0xab,0x10); 
        break;

    case CAM_EV_POS_2_3:    // +2 EV
          CamWriteCmosSensor(0xab,0x20); 
        break;

    case CAM_EV_POS_3_3:    // +3 EV
          CamWriteCmosSensor(0xab,0x30); 
        break;

    case CAM_EV_POS_4_3:    // +4 EV
          CamWriteCmosSensor(0xab,0x40); 
        break;

    default:
        return KAL_FALSE;    
    }
  
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV121DWB
*
* DESCRIPTION
*    SIV121D WB setting.
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
static MM_ERROR_CODE_ENUM SIV121DWB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV121D_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif

  // SIV121D_set_page(2);    //bank 2
    switch (In->FeatureSetValue)
    {
	case CAM_WB_AUTO:
		
		//if (SIV121D_op_state.is_panorama_capturing != KAL_TRUE)
		{
		    
		    CamWriteCmosSensor(0x00,	0x03);
			CamWriteCmosSensor(0x72, 0xa8); // 0xb4 manual R G B
		    CamWriteCmosSensor(0x73, 0xa8); //0x74
			kal_sleep_task(20);
			CamWriteCmosSensor(0x10, 0xd3); 
					
			}
        break;
	case CAM_WB_CLOUD:
		
	
		CamWriteCmosSensor(0x00,0x03);
		CamWriteCmosSensor(0x72, 0xb4); // 0xb4 manual R G B
		CamWriteCmosSensor(0x73, 0x74); //0x74
		CamWriteCmosSensor(0x10, 0xd5);  // Disable AWB
			
		break;
	case CAM_WB_DAYLIGHT:
		
		CamWriteCmosSensor(0x00,0x03);
		CamWriteCmosSensor(0x72, 0xd8); // 0xd4manual R G B
		CamWriteCmosSensor(0x73, 0x90);
		CamWriteCmosSensor(0x10, 0xd5);  // Disable AWB
				
		break;
	case CAM_WB_INCANDESCENCE: //A
		
		CamWriteCmosSensor(0x00,0x03);
		CamWriteCmosSensor(0x72, 0x80); // 0x6e manual R G B
		CamWriteCmosSensor(0x73, 0xe0); //0xbf
		CamWriteCmosSensor(0x10, 0xd5); // Disable AWB		
	
		break;
	case CAM_WB_TUNGSTEN:  
			
		CamWriteCmosSensor(0x00,0x03);
		CamWriteCmosSensor(0x72, 0x7b); //manual R G B
		CamWriteCmosSensor(0x73, 0xa0);
		CamWriteCmosSensor(0x10, 0xd5);  // Disable AWB
	
		break;
	case CAM_WB_FLUORESCENT:
				
		CamWriteCmosSensor(0x00,0x03);
		
		CamWriteCmosSensor(0x72, 0xb8); //manual R G B
		CamWriteCmosSensor(0x73, 0xcc);
		CamWriteCmosSensor(0x10, 0xd5); // Disable AWB
		
	
		break;
	//case CAM_WB_MANUAL:
	//	ret = KAL_FALSE;
	//	break;
	default:
		 return KAL_FALSE;
	}
  }
  
  return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    SIV121DEffect
*
* DESCRIPTION
*    SIV121D Effect setting.
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
static MM_ERROR_CODE_ENUM SIV121DEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
	SIV121D_set_page(4);  //bank 4
    switch (In->FeatureSetValue)
    {
        case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
            		CamWriteCmosSensor(0xB6, 0x00);
            break;

        case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
 			CamWriteCmosSensor(0xB6, 0x40);
            break;

        case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
			CamWriteCmosSensor(0xB7, 0x58); //0x60
			CamWriteCmosSensor(0xB8, 0x98); //0xa0
			CamWriteCmosSensor(0xB6, 0x80);
            break;

        case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
            		CamWriteCmosSensor(0xB7, 0x68);//0x50
            		CamWriteCmosSensor(0xB8, 0x68);//0x50
			CamWriteCmosSensor(0xB6, 0x80);
            break;

        case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
            		CamWriteCmosSensor(0xB7, 0xb8);//0xc0
            		CamWriteCmosSensor(0xB8, 0x50);//0x60
			CamWriteCmosSensor(0xB6, 0x80);		
            break;
     
        case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
         		CamWriteCmosSensor(0xB6, 0x10);
            break;
            
        case CAM_EFFECT_ENC_GRAYINV:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
          		CamWriteCmosSensor(0xB6, 0x20);
            break;

        case CAM_EFFECT_ENC_EMBOSSMENT:
			CamWriteCmosSensor(0x90, 0x14);
			CamWriteCmosSensor(0x91, 0x18);
          		CamWriteCmosSensor(0xB6, 0x08);
            break;
        
        case CAM_EFFECT_ENC_SKETCH:
			CamWriteCmosSensor(0x90, 0x30);
			CamWriteCmosSensor(0x91, 0x30);
           		CamWriteCmosSensor(0xB6, 0x04);
             break;
             
        case CAM_EFFECT_ENC_WHITEBOARD:
        case CAM_EFFECT_ENC_COPPERCARVING:
        case CAM_EFFECT_ENC_BLUECARVING:
        case CAM_EFFECT_ENC_CONTRAST:
        case CAM_EFFECT_ENC_JEAN:
        case CAM_EFFECT_ENC_OIL:
        default:
            return KAL_FALSE;
    }
  }   
  
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV121DBanding
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
MM_ERROR_CODE_ENUM SIV121DBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
		if(SIV121D_g_iBanding == In->FeatureSetValue)
        	return MM_ERROR_NONE;

		SIV121D_g_iBanding = In->FeatureSetValue;
		SIV121DSetShutterStep();
		SIV121DSetAeBaseShutter((CAL_CAMERA_BANDING_FREQ_ENUM)(In->FeatureSetValue), SIV121DMinFrameRate);

		break;
		
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV121DAeEnable
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
static MM_ERROR_CODE_ENUM SIV121DAeEnable(kal_bool Enable)
	{	
		kal_uint16 temp_AE_reg = 0;
	
		//if (SIV121D_op_state.is_panorama_capturing == KAL_TRUE && Enable == KAL_TRUE)
		//{
		//	/* When capture mode is panorama capture, then sensor driver should not control it agian... */
		//	return KAL_FALSE;
		//}
		CamWriteCmosSensor(0x00,0x02);
		temp_AE_reg = CamReadCmosSensor(0x10);
		
		if (Enable)   
		{
			CamWriteCmosSensor(0x10, (temp_AE_reg| 0x80)); /* Turn ON AEC/AGC*/
		}
		else
		{
			CamWriteCmosSensor(0x10, (temp_AE_reg & 0x00)); /* Turn OFF AEC/AGC*/
		}
	
		return KAL_TRUE;		  
	}




/*************************************************************************
* FUNCTION
*    SIV121DAwbEnable
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
static MM_ERROR_CODE_ENUM SIV121DAwbEnable(kal_bool Enable)
	{	
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
		return KAL_TRUE;
	}




/*************************************************************************
* FUNCTION
 *  SIV121DSetFlashLight
*
* DESCRIPTION
*   turn on/off SIV121D flashlight .
*
* PARAMETERS
*   bEnable:
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIV121DSetFlashLight(kal_bool bEnable)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
	FlashlightPowerOn(SensorIdxSIV121D, bEnable);

	return ErrCode;
}   /* SIV121DSetFlashLight */

void SIV121DGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo)
{
	SensorInfo->SensorId			=	SIV121D_SENSOR_ID;

	SensorInfo->SensorIf			=	IMAGE_SENSOR_IF_PARALLEL;
	SensorInfo->PreviewNormalDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	SensorInfo->PreviewHMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	SensorInfo->PreviewVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	SensorInfo->PreviewHVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;  

	SensorInfo->CaptureDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;

	SensorInfo->PixelClkInv			=	KAL_FALSE;
	SensorInfo->PixelClkPolarity	=	POLARITY_LOW;
	SensorInfo->HsyncPolarity		=	POLARITY_LOW;	/* Active High, it's inversed. */
	SensorInfo->VsyncPolarity		=	POLARITY_LOW;

#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
	SensorInfo->PreviewMclkFreq 	= 	24000000;
	SensorInfo->CaptureMclkFreq 	= 	24000000;
	SensorInfo->VideoMclkFreq 		= 	24000000;
#else
	SensorInfo->PreviewMclkFreq	=	24000000;
	SensorInfo->CaptureMclkFreq	=	24000000;
	SensorInfo->VideoMclkFreq		=	24000000;
#endif

	SensorInfo->PreviewWidth		=	SIV121D_PV_GRAB_WIDTH;
	SensorInfo->PreviewHeight		=	SIV121D_PV_GRAB_HEIGHT;
	SensorInfo->FullWidth			=	SIV121D_FULL_GRAB_WIDTH;
	SensorInfo->FullHeight			=	SIV121D_FULL_GRAB_WIDTH;

	SensorInfo->SensorAfSupport	=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
} /* SIV121DGetSensorInfo() */


MM_ERROR_CODE_ENUM SIV121DStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
}   /* SIV121DStillCaptureSize() */

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
kal_uint32 SIV121DDetectSensorId(void)
{
    kal_uint32 SensorId=0;
	IMAGE_SENSOR_INDEX_ENUM ToPdnIdx = (IMAGE_SENSOR_MAIN == SensorIdxSIV121D ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = SIV121DPowerOn();
			
			SIV121DSensorClose();
			
			if (SIV121D_SENSOR_ID == SensorId)
			{
				return SIV121D_SENSOR_ID;
			}
		}
	}

    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* SIV121DDetectSensorId() */


void SIV121DInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;		/* wait stable frame when sensor change mode (cap to pre) */

} /* SIV121DInitOperationPara() */

kal_uint32 SIV121DPowerOn(void)
{
    kal_uint32 SensorId = 0;

    /* PowerOn the sensor */
    CisModulePowerOn(SensorIdxSIV121D, KAL_TRUE);
    kal_sleep_task(2);  /* delay for power stable */

	CameraSccbOpen(CAMERA_SCCB_SENSOR, SIV121D_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 400);

	//CamPdnPinCtrl(SensorIdxSIV121D, 1);	/* Set Power Down High */
	//kal_sleep_task(1);

    /* Reset the sensor */
	//CamRstPinCtrl(SensorIdxSIV121D, 0);	/* Set Reset Pin Low */
   // kal_sleep_task(1);
	//CamRstPinCtrl(SensorIdxSIV121D, 1);	/* Set Reset Pin High */
   // kal_sleep_task(1);  /* delay for stable sensor */

    /* Read Sensor ID  */
    SIV121D_set_page(0);
    SensorId = CamReadCmosSensor(0x01);
#ifdef __SIV121D_DEBUG_INFO__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "Sensor_id = %x", SensorId);
#endif
	
    return SensorId;
} /* SIV121DPowerOn() */

MM_ERROR_CODE_ENUM SIV121DPreview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

	SIV121DCurrScenario = ScenarioId;

	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		SIV121DMaxFrameRate = In->MaxVideoFrameRate;
		SIV121DMinFrameRate = In->MaxVideoFrameRate;
		
		SIV121DSetFixFrameRate(KAL_TRUE);

		Out->WaitStableFrameNum = 3;
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		SIV121DMaxFrameRate = SIV121D_MAX_CAMERA_FPS;
		SIV121DMinFrameRate = 10 *  SIV121D_FRAME_RATE_UNIT;
		if (In->NightMode)
		{ 
			SIV121DMinFrameRate = SIV121DMinFrameRate >> 1;
		}
		
		SIV121DSetFixFrameRate(KAL_FALSE);

		Out->WaitStableFrameNum = 3;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	SIV121DSetMirrorFlip(In->ImageMirror);
	
	SIV121DCalculateFrameRate(SIV121DMinFrameRate, SIV121DMaxFrameRate);

	SIV121DSetNightMode(SIV121DCurrScenario, In->NightMode);

	SIV121DSetAeBaseShutter(In->BandingFreq, SIV121DMinFrameRate);

	Out->GrabStartX = SIV121D_PV_GRAB_START_X;
	Out->GrabStartY = SIV121D_PV_GRAB_START_Y;
	Out->ExposureWindowWidth = SIV121D_PV_GRAB_WIDTH;
	Out->ExposureWindowHeight = SIV121D_PV_GRAB_HEIGHT;

	return ErrCode;
} /* SIV121DPreview */

MM_ERROR_CODE_ENUM SIV121DCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100B Capture");
#endif
  SIV121D_sensor.CaptureMode = KAL_TRUE;
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = SIV121D_IMAGE_SENSOR_VGA_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = SIV121D_IMAGE_SENSOR_VGA_HEIGHT- 2 * StartY;
} /* SIV121DCapture() */

/*************************************************************************
* FUNCTION
*    SIV121DSensorOpen
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
MM_ERROR_CODE_ENUM SIV121DSensorOpen(void)
{
    if (SIV121DPowerOn() != SIV121D_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }

    SIV121D_g_iBanding = CAM_BANDING_50HZ;
    SIV121D_Control = 0x00;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
    SIV121D_Dummy_Pixel = 0x1d;
#else
    SIV121D_Dummy_Pixel = 0x01;
#endif

	SIV121DWriteInitialSetting();
	
    SIV121DCalculateFrameRate(SIV121DMinFrameRate, SIV121DMaxFrameRate);

    return MM_ERROR_NONE;
} /* SIV121DSensorOpen() */

/*************************************************************************
* FUNCTION
*    SIV121DSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM SIV121DSensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	kal_uint32 TmpFrameRate;
	
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
    // for camera HAL UT only
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=pCameraFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;
	
	
	if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
	{
		return SIV121DWebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
	}
	
	if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        //pCamFeatureEnum->IsSupport = KAL_FALSE;
	}
	
	switch (id)
	{
		/* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
		ErrCode = SIV121DEV(In, Out);
		break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
    case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = SIV121DSceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = SIV121DSceneMode(KAL_FALSE, In, Out);
    break;
    case CAL_FEATURE_CAMERA_WB:
		ErrCode = SIV121DWB(In, Out);
		break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
		ErrCode = SIV121DEffect(In, Out);
		break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
		ErrCode = SIV121DStillCaptureSize(In, Out);
		break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
		ErrCode = SIV121DBanding(In, Out);
		break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
		
		/* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
		SIV121DGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV121DDetectSensorId();
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV121DMaxFrameRate * 10 / SIV121D_FRAME_RATE_UNIT;
		break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
		SIV121DInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
		break;
	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(SensorIdxSIV121D, 0);
		CamRstPinCtrl(SensorIdxSIV121D, 0);
		break;
		/* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
		TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
		break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
		SensorIdxSIV121D = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
		break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
		break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		ErrCode = SIV121DAeEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		ErrCode = SIV121DAwbEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(SensorIdxSIV121D, Out);
	    break;
    default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}
	
	return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SIV121DSensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    out_len: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV121DSensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint16 out_len)
{
  switch (id)
  {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE: SIV121DPreview(id, In, Out); break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE: SIV121DCapture(id, In, Out); break;
    default: break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV121DSensorClose
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
MM_ERROR_CODE_ENUM SIV121DSensorClose(void)
{
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
	CisModulePowerOn(SensorIdxSIV121D, KAL_FALSE);

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV121DSensorFunc
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
MM_ERROR_CODE_ENUM SIV121DSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIV121D=
  {
    SIV121DSensorOpen,
    SIV121DSensorFeatureCtrl,
    SIV121DSensorCtrl,
    SIV121DSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSIV121D;
}



