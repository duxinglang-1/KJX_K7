/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   image_sensor_OV3647.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "cal_comm_def.h"
#include "isp_if.h"
#include "isp_comm_if.h"
#include "isp_flashlight_if.h"
#include "aaa_ae.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "image_sensor_OV3647.h"



//****************added by mandrave **********************************//
//Commonly turn on this macro for debug.

//#define OV3647_OUTPUT_DEBUG_INFO

#define OV3647_USE_48MHZ_CLK_SRC		//Set the camera source clock to 48MHz
//#define OV3647_AVERAGE_MODE
#define OV3647_ABLC_LOW_LIGHT_GAIN_TRIGGER		//Solve the low light brightness change problem.
#define OV3647_SHUTTER_LIKE_OV3640

// Try to solve the green frame when from high light to low light.
//#define OV3647_GAIN_2_REG93_REGD4

//#define OV3647_COMPENSATE_BLC_LIKE_OV2640
#define OV3647_CAP_USE48MHZ_PCLK
//#define OV3647_CAP_USE_48MHZ_MCLK_BYPASS_PLL

static kal_uint16 g_iBackupExtraExp = 0;

#ifndef OV3647_DUAL_CAMERA
/* Global Valuable */
SensorInfo g_CCT_MainSensor = OV3647_OMNIVISION;	//OV3647_OMNIVISION;
kal_uint8 g_CCT_FirstGrabColor = OV3647_FIRST_GRAB_COLOR;
#else
/* Global Valuable */
SensorInfo OV3647_g_CCT_MainSensor = OV3647_OMNIVISION;	//OV3647_OMNIVISION;
kal_uint8 OV3647_g_CCT_FirstGrabColor = OV3647_FIRST_GRAB_COLOR;
#endif


static kal_uint16 OV3647_g_iExpLines = 0, OV3647_g_iExtra_ExpLines = 0;

OV3647_OP_TYPE OV3647_g_iOV3647_Mode = OV3647_MODE_NONE;

static kal_bool OV3647_g_bXGA_Mode = KAL_TRUE;

//static kal_uint16 OV3647_g_iExpLines = 0, OV3647_g_iExtra_ExpLines = 0;

//OV3647_OP_TYPE OV3647_g_iOV3647_Mode = OV3647_MODE_NONE;

kal_uint8 OV3647_MIN_EXPOSURE_LINES = 1;
kal_uint16 OV3647_MAX_EXPOSURE_LINES = OV3647_PV_EXPOSURE_LIMITATION;
kal_uint16 OV3647_g_iDummyLines = 0;
#if (defined(DRV_ISP_6228_SERIES) || defined(DRV_ISP_6229_SERIES))
kal_uint8 OV3647_g_iPV_PCLK_Divider = 0;
#endif
kal_uint16 OV3647_g_iPV_Pixels_Per_Line = 0;

kal_uint32 OV3647_CAP_dummy_pixels = 0;
kal_uint32 OV3647_CAP_dummy_lines = 0;
kal_uint32 OV3647_PV_dummy_pixels = 0;
kal_uint32 OV3647_PV_dummy_lines = 0;

#if (defined(DRV_ISP_6229_SERIES))
static float OV3647_g_fCap_PCLK = 24000000;			//24.0MHz
static float OV3647_g_fPV_PCLK = 24000000;				//24.0MHz
#elif (defined(DRV_ISP_6238_SERIES))
static float OV3647_g_fCap_PCLK = 48000000;			//32.000MHz
static float OV3647_g_fPV_PCLK = 48000000;				//32.000MHz
#endif

kal_uint16 OV3647_Video_Max_Line_Length;
kal_uint16 OV3647_video_current_frame_rate;

static kal_uint16 OV3647_dummy_pixels=0, OV3647_dummy_lines=0,OV3647_dummy_lines_backup = 0;

sensor_data_struct *pNvramSensorData;

IMAGE_SENSOR_INDEX_ENUM OV3647SensorIdx;

static kal_uint32 OV3647_fix_video_frame_rate=300;

extern camcorder_info_struct OV3647_dsc_support_info;





//*************************end *************************************//




kal_bool aeIsEnable(void)
{
 return KAL_TRUE;
}

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
#endif

static void OV3647WriteShutter(kal_uint16 shutter)
{
    kal_uint16 extra_line = 0;
	kal_uint16 OV3647_maximum_shutter = 0;

//#ifdef OV3647_OUTPUT_DEBUG_INFO
//	kal_prompt_trace(MOD_ENG, "WR_shutter1:shutter=%x,OV3647_maximum_shutter=%x,extra_line=%x", shutter, OV3647_maximum_shutter, extra_line);
//#endif

	if (shutter < 1)
		shutter = 1;

	if (OV3647_g_bXGA_Mode == KAL_TRUE)
	{
		if (OV3647_MODE_CAPTURE == OV3647_g_iOV3647_Mode)
		{
			OV3647_maximum_shutter = OV3647_PV_PERIOD_LINE_NUMS + OV3647_CAP_dummy_lines;
		}
		else
		{
			OV3647_maximum_shutter = OV3647_PV_PERIOD_LINE_NUMS + OV3647_PV_dummy_lines;
		}
	}
	else
	{
		if (OV3647_MODE_CAPTURE == OV3647_g_iOV3647_Mode)
		{
			OV3647_maximum_shutter = OV3647_CAP_PERIOD_LINE_NUMS + OV3647_CAP_dummy_lines;
		}
		else
		{
			OV3647_maximum_shutter = OV3647_CAP_PERIOD_LINE_NUMS + OV3647_PV_dummy_lines;
		}
	}

	//It will dark when shutter == Frame length -1
	//It will blue when shutter ==  Frame length - 2
	OV3647_maximum_shutter -= 3;	// Max shutter = Frame length - 3

	if (shutter >= OV3647_maximum_shutter)
	{
		OV3647_g_iExtra_ExpLines = shutter - OV3647_maximum_shutter;
		shutter = OV3647_maximum_shutter;
	}
	else
	{
		OV3647_g_iExtra_ExpLines = 0;
	}

	CamWriteCmosSensor(0x02, (shutter >> 8) & 0xFF);
	CamWriteCmosSensor(0x03, shutter & 0xFF);

	#ifdef OV3647_SHUTTER_LIKE_OV3640
	// 0x2D, 0x2E will increase VBLANK to get exposure larger than frame exposure
    // limitation. 0x2D, 0x2E must update at the same frame as sensor gain update.
    // AE doesn't update sensor gain at capture mode, thus extra exposure lines must be
    // updated here.
	#if (defined(DRV_ISP_6228_SERIES) || defined(DRV_ISP_6229_SERIES))
	    if (OV3647_g_iOV3647_Mode == OV3647_MODE_CAPTURE) 
		{
			CamWriteCmosSensor(0x2d, (OV3647_g_iExtra_ExpLines >> 8) & 0xFF);	// ADVFL(MSB of extra exposure lines)
			CamWriteCmosSensor(0x2e, OV3647_g_iExtra_ExpLines & 0xFF);			// ADVFH(LSB of extra exposure lines)
		}
	#elif (defined(DRV_ISP_6238_SERIES))
	// @frame rate change point, the extra exposure lines must be updated with ordinary
    // exposure line registers. I don't know why!
		if ((g_iBackupExtraExp == 0 && OV3647_g_iExtra_ExpLines > 0) ||
	         OV3647_g_iOV3647_Mode == OV3647_MODE_CAPTURE ||
	         aeIsEnable() == KAL_FALSE)
		{
			CamWriteCmosSensor(0x2d, (OV3647_g_iExtra_ExpLines >> 8) & 0xFF);	// ADVFL(MSB of extra exposure lines)
			CamWriteCmosSensor(0x2e, OV3647_g_iExtra_ExpLines & 0xFF);			// ADVFH(LSB of extra exposure lines)
		}
	#endif
		
		
		g_iBackupExtraExp = OV3647_g_iExtra_ExpLines;
	#else
		CamWriteCmosSensor(0x2d, (OV3647_g_iExtra_ExpLines >> 8) & 0xFF);	// ADVFL(MSB of extra exposure lines)
		CamWriteCmosSensor(0x2e, OV3647_g_iExtra_ExpLines & 0xFF);			// ADVFH(LSB of extra exposure lines)
	#endif

#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_prompt_trace(MOD_ENG, "WR_shutter2:shutter=%x,OV3647_g_iExtra_ExpLines=%x,OV3647_maximum_shutter=%x", shutter, OV3647_g_iExtra_ExpLines, OV3647_maximum_shutter);
#endif
}   /* write_OV3647_shutter */

static kal_uint16 OV3647Reg2Gain(const kal_uint8 iReg)
{
    kal_uint8 iI;
    kal_uint16 iGain = BASEGAIN;    // 1x-gain base

    // Range: 1x to 32x
    // Gain = (GAIN[7] + 1) * (GAIN[6] + 1) * (GAIN[5] + 1) * (GAIN[4] + 1) * (1 + GAIN[3:0] / 16)
    for (iI = 7; iI >= 4; iI--) {
        iGain *= (((iReg >> iI) & 0x01) + 1);
    }

    return iGain +  iGain * (iReg & 0x0F) / 16; 
}

static kal_uint8 OV3647Gain2Reg(const kal_uint16 iGain)
{
    
    kal_uint8 iReg = 0x00;

    if (iGain < 2 * BASEGAIN) {
        // Gain = 1 + GAIN[3:0](0x00) / 16
        iReg = 16 * (iGain - BASEGAIN) / BASEGAIN;
    }else if (iGain < 4 * BASEGAIN) {
        // Gain = 2 * (1 + GAIN[3:0](0x00) / 16)
        iReg |= 0x10;
        iReg |= 8 * (iGain - 2 * BASEGAIN) / BASEGAIN;
    }else if (iGain < 8 * BASEGAIN) {
        // Gain = 4 * (1 + GAIN[3:0](0x00) / 16)
        iReg |= 0x30;
        iReg |= 4 * (iGain - 4 * BASEGAIN) / BASEGAIN;
    }else if (iGain < 16 * BASEGAIN) {
        // Gain = 8 * (1 + GAIN[3:0](0x00) / 16)
        iReg |= 0x70;
        iReg |= 2 * (iGain - 8 * BASEGAIN) / BASEGAIN;
    }else if (iGain < 32 * BASEGAIN) {
        // Gain = 16 * (1 + GAIN[3:0](0x00) / 16)
        iReg |= 0xF0;
        iReg |= (iGain - 16 * BASEGAIN) / BASEGAIN;
    }else {
        ASSERT(0);
    }

    return iReg;

}

void OV3647_WriteReg(kal_uint32 iAddr, kal_uint32 iPara)
{
    CamWriteCmosSensor(iAddr, iPara);
}   /*	OV3647_WriteReg()	*/

kal_uint32 OV3647_ReadReg(kal_uint32 iAddr)
{
    return CamReadCmosSensor(iAddr);
}   /*  OV3647_ReadReg()    */



/*************************************************************************
* FUNCTION
*    OV3647SetDummy
*
* DESCRIPTION
*    This function set dummy pixel and dummy line.
*
* PARAMETERS
*    dummy pixel
*    dummy line
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647SetDummy( kal_uint16 iPixels,  kal_uint16 iLines)
{
  kal_uint16 line_pixels= 0;
	kal_uint16 frame_lines = 0;

#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_prompt_trace(MOD_ENG, "Set_Dummy:pixels=%x,lines=%x", iPixels, iLines);
#endif

	if (OV3647_g_bXGA_Mode)
	{
		line_pixels = OV3647_PV_PERIOD_PIXEL_NUMS + iPixels;
		frame_lines = OV3647_PV_PERIOD_LINE_NUMS + iLines;
	}
	else
	{
		line_pixels = OV3647_CAP_PERIOD_PIXEL_NUMS + iPixels;
		frame_lines = OV3647_CAP_PERIOD_LINE_NUMS + iLines;
	}

	//Set dummy pixels.
	CamWriteCmosSensor(0x28, (line_pixels >> 8) & 0xFF);
	CamWriteCmosSensor(0x29, line_pixels & 0xFF);

	//Set dummy lines.
	//The maximum shutter value = Line_Without_Dummy + Dummy_lines
	CamWriteCmosSensor(0x2A, (frame_lines >> 8) & 0xFF);
	CamWriteCmosSensor(0x2B, frame_lines & 0xFF);

	OV3647_dummy_pixels = iPixels;
		
	OV3647_dummy_lines = iLines;
  
}

/*************************************************************************
* FUNCTION
*    OV3647InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor.
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
static void OV3647InitialSetting(void)
{
	//@@ Res 1024x768-Ken
	//;Input XCLK 24MHz, PCLK =32Mhz @30fps
	//;Disable AWB/AEC/AGC, [0x13]= 0xf0
	//;Disable LENC Reg0xB1[2], [0xB1] = 0xfb.
	//
	//
	//;88 00 90

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647InitialSetting");
#endif

	
	CamWriteCmosSensor(0x12, 0x80);	//
	kal_sleep_task(3);		//At least >= 2ms

	CamWriteCmosSensor(0x01, 0x3f);	//
	CamWriteCmosSensor(0x0c, 0x0c);	//


	CamWriteCmosSensor(0x0e, 0x36);	//MCLK is 26MHz, PCLK is 34.666667MHz
#ifdef OV3647_CAP_USE48MHZ_PCLK
	CamWriteCmosSensor(0x0f, 0x0c);	//48MHz
#else
	CamWriteCmosSensor(0x0f, 0x0d);	//32MHz
#endif
	CamWriteCmosSensor(0x11, 0x40);
	kal_sleep_task(2);
		
	//Adjust the PCLK delay bit[3],bit[2]
#if defined(DRV_ISP_MT6236_HW_SUPPORT)
	CamWriteCmosSensor(0x0d, 0x0a);   //0x08 -> 0x0a---20100401:For Capture Drop Frame(56M)
#else
    CamWriteCmosSensor(0x0d, 0x08);
#endif

	CamWriteCmosSensor(0x13, 0xf0);	//; ff;Disable AWB,AEC/AGC.
	CamWriteCmosSensor(0x15, 0x82);	//
	CamWriteCmosSensor(0x16, 0x83);	//

	CamWriteCmosSensor(0xb1, 0xfb);	//;Disable LENC

	CamWriteCmosSensor(0x72, 0x02);	//
	CamWriteCmosSensor(0x75, 0x06);	//
	CamWriteCmosSensor(0x7a, 0x08);	//
	
	//CamWriteCmosSensor(0x7b, 0x10);	//
	//CamWriteCmosSensor(0x7b, 0x12);	//Advised by OV FAE in America
	CamWriteCmosSensor(0x7b, 0x02);	//Solve vertical line in the left side.
	
	CamWriteCmosSensor(0x91, 0x4a);	//
	CamWriteCmosSensor(0x99, 0x4c);	//
	
	//CamWriteCmosSensor(0x9b, 0xf0);	//
	CamWriteCmosSensor(0x9b, 0x00);	//Advised by OV FAE in America
	
	CamWriteCmosSensor(0x9c, 0x18);	//
	CamWriteCmosSensor(0xd8, 0x0d);	//
	//CamWriteCmosSensor(0xd9, 0x8e);	//; 8d
	CamWriteCmosSensor(0xd9, 0x8a);	//Solve vertical line in the left side.

	CamWriteCmosSensor(0x77, 0x00);	//
	CamWriteCmosSensor(0x78, 0x60);	//

	//bit[7], 0:disable ABLC, 1: Enalbe ABLC
	CamWriteCmosSensor(0x67, 0xcc);	// bit[6]: 1, frame trigger, 0, gian trigger
	
	CamWriteCmosSensor(0x66, 0x0f);	//
	//CamWriteCmosSensor(0x66, 0x00);	//		Modified 2008-12-18, From KenAE.

	CamWriteCmosSensor(0x21, 0x33);	// meimei modify
	CamWriteCmosSensor(0x23, 0x06);	//
	CamWriteCmosSensor(0x24, 0x40);	//
	CamWriteCmosSensor(0x25, 0x08);	//
	CamWriteCmosSensor(0x26, 0x30);	//
	CamWriteCmosSensor(0x28, 0x05);	//
	CamWriteCmosSensor(0x29, 0x4c);	//;3c ;insert 16 dummy pixel
	CamWriteCmosSensor(0x2a, 0x03);	//
	CamWriteCmosSensor(0x2b, 0x14);	//
	CamWriteCmosSensor(0x92, 0x80);	//
	CamWriteCmosSensor(0x12, 0x10);	//

	CamWriteCmosSensor(0x18, 0x48);	//
	CamWriteCmosSensor(0x19, 0x38);	//
	CamWriteCmosSensor(0x1a, 0xa2);	//

	CamWriteCmosSensor(0x50, 0x03);	//bit7, 50Hz/60Hz light detection, 1: On, 0: Off

    // sensor's internal tuning parameter write in
    
} 

/*************************************************************************
* FUNCTION
*  OV3647_GetID
*
* DESCRIPTION
*  This function return the sensor read/write id of SCCB interface.
*
* PARAMETERS
*  *pWriteID: address pointer of sensor write id
*   *pReadID: address pointer of sensor read id
*
* RETURNS
*  None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647_GetID(kal_uint8 *pWriteID, kal_uint8 *pReadID)
{

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647_GetID");
#endif
  
  *pWriteID = OV3647_WRITE_ID;
  *pReadID = OV3647_READ_ID;
}

/*************************************************************************
* FUNCTION
*  OV3647_GetSize
*
* DESCRIPTION
*  This function return the image width and height of image sensor.
*
* PARAMETERS
*  *pWidth : address pointer of horizontal effect pixels of image sensor
*  *pHeight : address pointer of vertical effect pixels of image sensor
*
* RETURNS
*  None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647_GetSize(kal_uint16 *pWidth, kal_uint16 *pHeight)
{
#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647_GetSize");
#endif

  *pWidth = OV3647_IMAGE_SENSOR_FULL_WIDTH;
  *pHeight = OV3647_IMAGE_SENSOR_FULL_HEIGHT;
}

/*************************************************************************
* FUNCTION
*  OV3647_get_period
*
* DESCRIPTION
*  This function return the image width and height of image sensor.
*
* PARAMETERS
*  *pixel_number : address pointer of pixel numbers in one period of HSYNC
*  *line_number : address pointer of line numbers in one period of VSYNC
*
* RETURNS
*  None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647_GetPeriod(kal_uint16 *pPixels, kal_uint16 *pLines)
{

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647_GetPeriod");
#endif


#if (defined(DRV_ISP_6238_SERIES))
  *pPixels = OV3647_PV_PERIOD_PIXEL_NUMS + OV3647_dummy_pixels;
  *pLines =  OV3647_PV_PERIOD_LINE_NUMS + OV3647_dummy_lines;
#else
  *pPixels = OV3647_PV_PERIOD_PIXEL_NUMS;
  *pLines = OV3647_PV_PERIOD_LINE_NUMS;
#endif
}



static void OV3647SetMirrorFlip(kal_uint8 image_mirror)
{
   
   kal_uint8 iTemp = 0;


#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647SetMirrorFlip :%d",image_mirror);
#endif
   
   //MOD1[0x03],
   //Sensor mirror image control, bit[1]
   //Sensor flip image control, bit[0];
   iTemp = CamReadCmosSensor(0x0c) & 0xFC;   //Clear the mirror and flip bits.
   switch (image_mirror)
   {
	   case IMAGE_SENSOR_MIRROR_NORMAL:
		   CamWriteCmosSensor(0x0C, iTemp | 0x00);   //Set normal
		   //SET_FIRST_GRAB_COLOR(BAYER_B);
		   SET_FIRST_GRAB_COLOR(BAYER_Gr);
		   break;
   
	   case IMAGE_SENSOR_MIRROR_V:
		   CamWriteCmosSensor(0x0C, iTemp | 0x01);   //Set flip
		   //SET_FIRST_GRAB_COLOR(BAYER_Gr);
		   SET_FIRST_GRAB_COLOR(BAYER_Gb);
		   break;
		   
	   case IMAGE_SENSOR_MIRROR_H:
		   CamWriteCmosSensor(0x0C, iTemp | 0x02);   //Set mirror
		   //SET_FIRST_GRAB_COLOR(BAYER_B);
		   SET_FIRST_GRAB_COLOR(BAYER_R);
		   break;
			   
	   case IMAGE_SENSOR_MIRROR_HV:
		   CamWriteCmosSensor(0x0C, iTemp | 0x03);   //Set mirror and flip
		   //SET_FIRST_GRAB_COLOR(BAYER_Gr);
		   SET_FIRST_GRAB_COLOR(BAYER_Gb);
		   break;
   }
}
 


/*************************************************************************
* FUNCTION
*  OV3647SetShutter
*
* DESCRIPTION
*  This function set e-shutter of OV3647 to change exposure time.
*
* PARAMETERS
*  shutter : exposured lines
*
* RETURNS
*  None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647SetShutter(kal_uint16 iShutter)
{

	OV3647_g_iExpLines = iShutter;
	OV3647WriteShutter(iShutter);

#ifdef OV3647_OUTPUT_DEBUG_INFO
    kal_prompt_trace(MOD_ENG, "[Shut]iShutter=%x", iShutter);
#endif

}

/*************************************************************************
* FUNCTION
*  OV3647SetGain
*
* DESCRIPTION
*  This function is to set global gain to sensor.
*
* PARAMETERS
*  gain : sensor global gain(base: 0x40)
*
* RETURNS
*  the actually gain set to sensor.
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 OV3647SetGain(kal_uint16 iGain)
{
  const kal_uint16 iBaseGain = OV3647Reg2Gain(pNvramSensorData->cct[OV3647_INDEX_BASE_GAIN].para);
    const kal_uint16 iGain2Set = iBaseGain * iGain / BASEGAIN;
    const kal_uint8 iReg = OV3647Gain2Reg(iGain2Set);

#ifdef OV3647_ABLC_LOW_LIGHT_GAIN_TRIGGER
	//Reg 0x67, BLC control
	//	bit[7], 0:disable ABLC, 1: Enalbe ABLC
	//	bit[6]: 1, frame trigger 0, 0, gian trigger
	if (iGain2Set >= 496)
	{
		//Because the brightness will change ervery frame when use frame tigger(Reg, 0x60~0x64 will change).
		//It looks like AE OSC, so use gain trigger method when low light.
		CamWriteCmosSensor(0x67, 0x8c);	//ABLC triggered by gain change, low light.
	}
	else
	{
		CamWriteCmosSensor(0x67, 0xcc);	//ABLC triggered by each frame, normal light
	}
#endif

    CamWriteCmosSensor(0x01, iReg);	//Set the global gain.

	#ifdef OV3647_SHUTTER_LIKE_OV3640
	    // 0x2D, 0x2E will increase VBLANK to get exposure larger than frame exposure
	    // limitation. 0x2D, 0x2E must update at the same frame as sensor gain update.
		CamWriteCmosSensor(0x2d, (OV3647_g_iExtra_ExpLines >> 8) & 0xFF);	// ADVFL(MSB of extra exposure lines)
		CamWriteCmosSensor(0x2e, OV3647_g_iExtra_ExpLines & 0xFF);			// ADVFH(LSB of extra exposure lines)
	#endif
	
#ifdef OV3647_OUTPUT_DEBUG_INFO
	//kal_prompt_trace(MOD_ENG, "[Gain]iReg=%x,iGain2Set=%x,Gain=%x,iGain2Set=%x", iReg, iGain2Set, iGain, iGain2Set);
    //kal_prompt_trace(MOD_ENG, "[Gain]extra_line=%x,Shut=%x,YAvg=%x", OV3647_g_iExtra_ExpLines, OV3647_g_iExpLines, CamReadCmosSensor(0x1B));
    kal_prompt_trace(MOD_ENG, "[GAIN]Shut: %d, Gain: %d, YAvg: %x", OV3647_g_iExpLines, iGain, CamReadCmosSensor(0x1B));
#endif

    return OV3647Reg2Gain(iReg) * BASEGAIN / iBaseGain;
	
}

static kal_uint16 OV3647ReadGain(void)
{  
  kal_uint8 iReg = 0;
  iReg = CamReadCmosSensor(0x01);
  return OV3647Reg2Gain(iReg);
}

static void OV3647SetFlashlight (kal_bool enable)
{

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647SetFlashlight :%d",enable);
#endif
  //flashlight_power_on(enable);
  //FlashlightPowerOn(OV3647SensorIdx, enable);
}

/*************************************************************************
* FUNCTION
*  image_sensor_func_config
*
* DESCRIPTION
*  This function maps the camera module function API structure.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
// write camera_para to sensor register
static void OV3647CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32	i;

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647CameraParaToSensor");
#endif
	
#if (defined(DRV_ISP_6238_SERIES))  
	for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_START_ADDR); i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
	}
	for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_END_ADDR); i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
	}
	for(i=0; i<FACTORY_END_ADDR; i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.cct[i].addr, pCameraPara->SENSOR.cct[i].para);
	}
#else
	for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<OV3647_FACTORY_START_ADDR); i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
	}
	for(i=OV3647_FACTORY_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<OV3647_FACTORY_END_ADDR); i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
	}
	for(i=0; i<OV3647_CCT_END_ADDR; i++)
	{
		OV3647_WriteReg(pCameraPara->SENSOR.cct[i].addr, pCameraPara->SENSOR.cct[i].para);
	}
#endif
}

// update camera_para from sensor register
static void OV3647SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32	i;


#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "OV3647SensorToCameraPara");
#endif

#if (defined(DRV_ISP_6238_SERIES))  	
	for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_START_ADDR); i++)
	{
		pCameraPara->SENSOR.reg[i].para = OV3647_ReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
	for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_END_ADDR); i++)
	{
		pCameraPara->SENSOR.reg[i].para = OV3647_ReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
#else
	for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<OV3647_FACTORY_START_ADDR); i++)
	{
		pCameraPara->SENSOR.reg[i].para = OV3647_ReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
	for(i=OV3647_FACTORY_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<OV3647_FACTORY_END_ADDR); i++)
	{
		pCameraPara->SENSOR.reg[i].para = OV3647_ReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
#endif
}

//------------------------Engineer mode---------------------------------
extern int sprintf(char *buffer, const char *format, ... );

static void  OV3647GetSensorGroupCount(kal_int32* sensor_count_ptr)
{

#ifdef OV3647_OUTPUT_DEBUG_INFO
		  kal_prompt_trace(MOD_ENG, "OV3647GetSensorGroupCount");
#endif

  *sensor_count_ptr = OV3647_GROUP_TOTAL_NUMS;
}

static void OV3647GetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{


#ifdef OV3647_OUTPUT_DEBUG_INFO
			 kal_prompt_trace(MOD_ENG, "OV3647GetSensorGroupInfo");
#endif

	
   switch (group_idx)
   {
  case PRE_GAIN:
    sprintf((char *) group_name_ptr, "CCT");
    *item_count_ptr = 5;
  break;
  case CMMCLK_CURRENT:
    sprintf((char *) group_name_ptr, "CMMCLK Current");
    *item_count_ptr = 1;
  break;  
  case FRAME_RATE_LIMITATION:
    sprintf((char *) group_name_ptr, "FRAME_RATE_LIMITATION ");
   break;   
  case REGISTER_EDITOR:
    sprintf((char *) group_name_ptr, "REGISTER_EDITOR ");
  break;     
  default:
     ASSERT(0);
  }
}
static void OV3647GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
  kal_uint8 temp_reg=0x00;
  kal_uint32 temp_gain=0;
  
  //CamWriteCmosSensor(OV3647_PAGE_SETTING_REG,0x01);

#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_prompt_trace(MOD_ENG, "OV3647GetSensorItemInfo");
#endif
  
  switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:
           sprintf((char *) (info_ptr->ItemNamePtr), "SENSOR_BASEGAIN");
            info_ptr->ItemValue = 1000 * OV3647Reg2Gain(pNvramSensorData->cct[OV3647_INDEX_BASE_GAIN].para) / BASEGAIN;
            info_ptr->IsTrueFalse = KAL_FALSE;
            info_ptr->IsReadOnly= KAL_FALSE;
            info_ptr->IsNeedRestart= KAL_FALSE;
            info_ptr->Min= 1 * 1000;  // MIN. global gain = 1x gain
            info_ptr->Max= 32 * 1000; // MAX. global gain = 32x gain
        break;
        
        case PRE_GAIN_R_INDEX:
        case PRE_GAIN_B_INDEX:
        case PRE_GAIN_Gr_INDEX:
        case PRE_GAIN_Gb_INDEX:
          if (item_idx == OV3647_INDEX_PRE_GAIN_R) {
                sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-R");
            }else if (item_idx == OV3647_INDEX_PRE_GAIN_Gr) {
                sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
			}else if (item_idx == OV3647_INDEX_PRE_GAIN_Gb) {
                sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gb");
            }else if (item_idx == OV3647_INDEX_PRE_GAIN_B) {
                sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-B");
            }else {
                ASSERT(0);
            }

            // R, G, B gain = reg / 0x40
            info_ptr->ItemValue= pNvramSensorData->cct[item_idx].para * 1000 / 0x40;
            info_ptr->IsTrueFalse= KAL_FALSE;
            info_ptr->IsReadOnly= KAL_FALSE;
            info_ptr->IsNeedRestart= KAL_FALSE;
            info_ptr->Min= 1 * 1000;  // MIN. pre-gain
            info_ptr->Max= 255 * 1000 / 0x40; // MAX. pre-gain
            break;
        default:
           ASSERT(0);    
      }
    break;

    case CMMCLK_CURRENT:
    switch (item_idx) {
    case 0:
      sprintf((char *) info_ptr->ItemNamePtr, "Drv Current[2,4,6,8]mA");
      switch (pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para) {
      case ISP_DRIVING_2MA:
        info_ptr->ItemValue = 2;
        break;

      case ISP_DRIVING_4MA:
        info_ptr->ItemValue = 4;
        break;

      case ISP_DRIVING_6MA:
        info_ptr->ItemValue = 6;
        break;

      case ISP_DRIVING_8MA:
        info_ptr->ItemValue = 8;
        break;

      default:
        ASSERT(0);
      }  

      info_ptr->IsTrueFalse = KAL_FALSE;
      info_ptr->IsReadOnly = KAL_FALSE;
      info_ptr->IsNeedRestart = KAL_TRUE;
      info_ptr->Min = 2;
      info_ptr->Max = 8;
      break;
	default:
	 	ASSERT(0);
    }
      
    case FRAME_RATE_LIMITATION:
    break;   
    case REGISTER_EDITOR:
		switch (item_idx)
			{
				case 0:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"REG Addr.");
				  info_ptr->ItemValue=0;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0xFFFF;
				break;
				case 1:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"REG Value");
				  info_ptr->ItemValue=0;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0xFFFF;
				break;
				default:
				   ASSERT(0);		
			}
		
    break;  

    default:
      ASSERT(0);
    }  
}


static kal_bool OV3647SetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
   kal_uint8 temp_reg;
   kal_uint32 temp_gain;

   kal_uint8 iTemp = 0x00;
    static kal_uint32 iFAC_SENSOR_REG = 0x00;
   
#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_prompt_trace(MOD_ENG, "OV3647SetSensorItemInfo");
#endif


   switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:

		  if(ItemValue <1 * 1000 || ItemValue >= 32 *1000)
		  	{
		  	   return KAL_FALSE;
		  	}
          temp_gain = (ItemValue * BASEGAIN)/1000;
          temp_reg = OV3647Gain2Reg(temp_gain);        

          pNvramSensorData->cct[SENSOR_BASEGAIN].para = temp_reg;
          CamWriteCmosSensor(pNvramSensorData->cct[SENSOR_BASEGAIN].addr,temp_reg);
          break;
          
        case PRE_GAIN_R_INDEX:
        case PRE_GAIN_B_INDEX:   
        case PRE_GAIN_Gr_INDEX:
        case PRE_GAIN_Gb_INDEX:
			if(ItemValue < 1 *1000 || ItemValue > (kal_uint32)(1000 * 255 / 0x40))
				{
				   return KAL_FALSE;
				}
          //temp_reg = pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para;          
          
          temp_gain = (ItemValue * 0x40) / 1000;
          temp_reg  = temp_gain;
                
          pNvramSensorData->cct[item_idx].para = temp_reg;
          CamWriteCmosSensor(pNvramSensorData->cct[item_idx].addr,temp_reg);
        break;
        
        default:
           ASSERT(0);  
      }      
    break;

    case CMMCLK_CURRENT:
      switch (item_idx) {
      case 0:
              if(ItemValue==2)
                 {
                    pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
                    SetIspDrivingCurrent(ISP_DRIVING_2MA);
                 }
               else if(ItemValue==3 || ItemValue==4)
                 {
                     pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
                     SetIspDrivingCurrent(ISP_DRIVING_4MA);   
                 }
                else if(ItemValue==5 || ItemValue==6)
                 {
                      pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
                      SetIspDrivingCurrent(ISP_DRIVING_6MA);
                 }
                else
                 {
                      pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
                      SetIspDrivingCurrent(ISP_DRIVING_8MA);
                	}
        break;

      default:
        ASSERT(0);
      }  
    break;
    
    case FRAME_RATE_LIMITATION:
    break;   
    case REGISTER_EDITOR:
		switch (item_idx)
			{
				case 0:
				  //2643_FAC_SENSOR_REG=ItemValue;
				   if (ItemValue < 0 || ItemValue > 0xFF)
				   	{
                       return KAL_FALSE;
                    }
                   iFAC_SENSOR_REG = ItemValue;
				break;
				case 1:
				  //CamWriteCmosSensor(OV3647_FAC_SENSOR_REG,ItemValue);
				   if (ItemValue < 0 || ItemValue > 0xFF)
					{
                      return KAL_FALSE;
                    }
                   CamWriteCmosSensor(iFAC_SENSOR_REG, ItemValue);
				break;
				default:
				   ASSERT(0);		
			}
    break;  
    default:
       ASSERT(0);
  }
  
  return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    OV3647GetSensorInfo
*
* DESCRIPTION
*    This function get sensor infomation
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
static void OV3647GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{




  kal_int8  Pixel = POLARITY_LOW;
  kal_int8  Hsync = POLARITY_LOW;
  kal_int8  Vsync = POLARITY_LOW;
  pSensorInfo->SensorId = OV3647_SENSOR_ID;
  pSensorInfo->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  pSensorInfo->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  pSensorInfo->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;    
  pSensorInfo->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
  pSensorInfo->PixelClkInv = KAL_FALSE;
  pSensorInfo->PixelClkPolarity = Pixel;
  pSensorInfo->HsyncPolarity = Hsync;
  pSensorInfo->VsyncPolarity = Vsync;
  pSensorInfo->PreviewMclkFreq = 24000000;
  pSensorInfo->CaptureMclkFreq = 24000000;
  pSensorInfo->VideoMclkFreq = 24000000;
  pSensorInfo->PreviewWidth = OV3647_IMAGE_SENSOR_PV_WIDTH;
  pSensorInfo->PreviewHeight = OV3647_IMAGE_SENSOR_PV_HEIGHT;
  pSensorInfo->FullWidth = OV3647_IMAGE_SENSOR_FULL_WIDTH;
  pSensorInfo->FullHeight = OV3647_IMAGE_SENSOR_FULL_HEIGHT;
  pSensorInfo->SensorAfSupport = KAL_FALSE;
  pSensorInfo->SensorFlashSupport = KAL_FALSE;

#ifdef OV3647_OUTPUT_DEBUG_INFO
	  kal_prompt_trace(MOD_ENG, "OV3647GetSensorInfo");
#endif
}

/*************************************************************************
* FUNCTION
*    OV3647PowerOn
*
* DESCRIPTION
*    This function reset sensor and read id
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
static kal_uint16 OV3647PowerOn(void)
{
  kal_uint16 SensorId = NULL_SENSOR_ID;
  kal_uint8 i = 0;
  

#ifdef OV3647_OUTPUT_DEBUG_INFO
		  kal_prompt_trace(MOD_ENG, "OV3647GetSensorInfo");
#endif


	 CisModulePowerOn(OV3647SensorIdx, KAL_TRUE);
	  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV3647_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 260);
	  
	  CamPdnPinCtrl(OV3647SensorIdx, 1); 
	  
	  CamRstPinCtrl(OV3647SensorIdx, 0);
	  kal_sleep_task(3);

	  //disable PDN
	  CamPdnPinCtrl(OV3647SensorIdx, 0);// OV3647's PDN mode is active high, set low to disable PDN mode
	  kal_sleep_task(1);

	  //RST
	  CamRstPinCtrl(OV3647SensorIdx, 1);
	  kal_sleep_task(3);
	  CamRstPinCtrl(OV3647SensorIdx, 0);
	  kal_sleep_task(10);
	  CamRstPinCtrl(OV3647SensorIdx, 1);
	  kal_sleep_task(3);

	  // SW reset  sent to OV3647
      CamWriteCmosSensor(0x12, 0x80);
      kal_sleep_task(2); // at least one frame delay time needed after SW reset >= 2ms
	  
	  SensorId = (CamReadCmosSensor(0x0A) << 8)|CamReadCmosSensor(0x0B);
	  if (SensorId != OV3647_SENSOR_ID) /* READ SENSOR ID */
	  {
	  
#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
	  }

  return SensorId;
} /* OV3647PowerOn() */


/*************************************************************************
* FUNCTION
*    OV3647DetectSensorId
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
static kal_uint32 OV3647DetectSensorId(void)
{


  MM_ERROR_CODE_ENUM OV3647SensorClose(void);
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;



//fdef OV3647_OUTPUT_DEBUG_INFO
//  kal_prompt_trace(MOD_ENG, "OV3647DetectSensorId");
//ndif
  
  if (IMAGE_SENSOR_MAIN == OV3647SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }

  
  //for (i = 1; i >= 0; i--)
  {
    
  //  for (j = 1; j >= 0; j--)
    {
   //   CamRstPinCtrl(AnotherSensorIdx, i);
   //   CamPdnPinCtrl(AnotherSensorIdx, j);
      sensorId = OV3647PowerOn();
      OV3647SensorClose();
#ifdef OV3647_OUTPUT_DEBUG_INFO
      kal_wap_trace(MOD_ENG,TRACE_INFO,"OV3647DetectSensorId:%x",sensorId);
#endif
      if (OV3647_SENSOR_ID == sensorId)
      {
        return OV3647_SENSOR_ID;
      }
    }
  }
  return -1;
}


static MM_ERROR_CODE_ENUM OV3647SensorOpen(void)
{
#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_wap_trace(MOD_ENG, TRACE_INFO, "enter OV3647SensorOpen");
#endif
	IspSetInterruptTriggerDelayLines(4);  // 0: VD INT, others: TG INT & start line
  
    if (OV3647_SENSOR_ID != OV3647PowerOn()) 
  	{
    	return MM_ERROR_SENSOR_READ_ID_FAIL;
  	}
  
    OV3647InitialSetting();
  
	#ifdef OV3647_DEBUG
		kal_wap_trace(MOD_ENG, TRACE_INFO, "exit OV3647SensorOpen");
	#endif
  return MM_ERROR_NONE;
}




static void OV3647_Set_XGA_Mode()
{

	//;clock configuration
	//;based on 24Mhz input , PCLK is 32Mhz.
	//;90 0e 36
	//;90 0f  0d
	//;90 11 40 ;40/00/01 for 30/15/7.5fps

#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_wap_trace(MOD_ENG, TRACE_INFO, "OV3647_Set_XGA_Mode");
#endif


	CamWriteCmosSensor(0x0e, 0x36);	//MCLK is 26MHz, PCLK is 34.666667MHz
#ifdef OV3647_CAP_USE48MHZ_PCLK
	CamWriteCmosSensor(0x0f, 0x0c);	//48MHz
#else
	CamWriteCmosSensor(0x0f, 0x0d);	//32MHz
#endif
	CamWriteCmosSensor(0x11, 0x40);
	kal_sleep_task(2);

	CamWriteCmosSensor(0x21, 0x33);		//meimei modify
	CamWriteCmosSensor(0x23, 0x06);		//
	CamWriteCmosSensor(0x24, 0x40);		//
	CamWriteCmosSensor(0x25, 0x08);		//
	CamWriteCmosSensor(0x26, 0x30);		//
	CamWriteCmosSensor(0x28, 0x05);		//
	CamWriteCmosSensor(0x29, 0x3c);		//
	CamWriteCmosSensor(0x2a, 0x03);		//
	CamWriteCmosSensor(0x2b, 0x14);		//
	kal_sleep_task(3);

	//Add for the 350lux problem.
	#ifdef OV3647_AVERAGE_MODE
	CamWriteCmosSensor(0x93, 0x00);	//Average mode
	#else
	CamWriteCmosSensor(0x93, 0x01);	//Subsamble, mode, 1600lux
	#endif
	
	CamWriteCmosSensor(0xd4, 0x20);	//
	//kal_sleep_task(1);
	
	CamWriteCmosSensor(0x92, 0x80);		//
	CamWriteCmosSensor(0x12, 0x10);		//
	kal_sleep_task(5);

	OV3647_g_bXGA_Mode = KAL_TRUE; //1024x768 output
	
}

/*************************************************************************
* FUNCTION
*	OV3647_Fix_Video_Frame_Rate
*
* DESCRIPTION
*	This function is to set dummy line to sensor for video fixed frame rate.
*
* PARAMETERS
*	framerate : Video Fix frame rate 
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

static void OV3647_Fix_Video_Frame_Rate(kal_uint16 framerate)
{    
    OV3647_Video_Max_Line_Length = (kal_uint16)((OV3647_g_fPV_PCLK*10/framerate)/(OV3647_PV_PERIOD_LINE_NUMS+OV3647_PV_dummy_lines));
	
    if (OV3647_Video_Max_Line_Length < (OV3647_PV_PERIOD_PIXEL_NUMS))			
	    OV3647_Video_Max_Line_Length = OV3647_PV_PERIOD_PIXEL_NUMS ;	

    //Dummy pixels
    OV3647_PV_dummy_pixels = OV3647_Video_Max_Line_Length - OV3647_PV_PERIOD_PIXEL_NUMS;

    OV3647SetDummy(OV3647_PV_dummy_pixels, OV3647_PV_dummy_lines);

#ifdef OV3647_OUTPUT_DEBUG_INFO
	kal_wap_trace(MOD_ENG, TRACE_INFO, "[OV3647] OV3647_Fix_Video_Frame_Rate = %d...", framerate);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "[OV3647] OV3647_PV_dummy_pixels = %d...", OV3647_PV_dummy_pixels);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "[OV3647] OV3647_dummy_lines = %d...", OV3647_PV_dummy_lines);
#endif

}





/*************************************************************************
* FUNCTION
*    OV3647Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, in, out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

    kal_uint32 iTemp;
    kal_uint16 iStartX = 0, iStartY = 1;
    kal_uint16 iDummyPixels = 0;    // in XGA mode, dummy pixels must be even number

	#ifdef OV3647_OUTPUT_DEBUG_INFO
        kal_prompt_trace(MOD_ENG, "[OV3647] OV3647_Preview...");
    #endif
	OV3647InitialSetting();	//Solve the vsync low after back from cpature sometimes.

	OV3647_Set_XGA_Mode();
	
	switch (ScenarioId)
		{
			case CAL_SCENARIO_CAMERA_PREVIEW:
			case CAL_SCENARIO_WEBCAM_PREVIEW:
			case CAL_SCENARIO_WEBCAM_CAPTURE:
				
				break;
			case CAL_SCENARIO_VIDEO:
				//OV3647_fix_video_frame_rate = pParaIn->MaxVideoFrameRate;
				//OV3647_MAX_EXPOSURE_LINES = (kal_uint16)((35750000/OV3647_fix_video_frame_rate)/(800+OV3647_dummy_pixels)); 	 
				//if((OV3647_MAX_EXPOSURE_LINES>650)&&(OV3647_dummy_lines<(OV3647_MAX_EXPOSURE_LINES - 650)))    
				//OV3647_dummy_lines = OV3647_MAX_EXPOSURE_LINES - 650;
				//OV3647_dummy_lines_backup = OV3647_dummy_lines;
					
					
				//OV3647SetDummy(OV3647_dummy_pixels,OV3647_dummy_lines);

				//OV3647_Fix_Video_Frame_Rate(OV3647_fix_video_frame_rate);

	
				
				break;
       #ifdef __MEDIA_VT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif			
			default:

				break;
		}

	
	//g_iPV_PCLK_Divider = ((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG) >> 4) & 0x0000000F) + 1;
	//g_iPreview_Column_Pixel  = 0x5dc;
    OV3647_PV_dummy_pixels = 0;
	OV3647_PV_dummy_lines = 0;

	/* Set mirror & flip. */
	OV3647SetMirrorFlip(pParaIn->ImageMirror);
	
	pParaOut->GrabStartX = OV3647_IMAGE_SENSOR_PV_INSERT_START_X;
	pParaOut->GrabStartY = OV3647_IMAGE_SENSOR_PV_INSERT_START_Y;
	pParaOut->ExposureWindowWidth = OV3647_IMAGE_SENSOR_PV_WIDTH;
	pParaOut->ExposureWindowHeight = OV3647_IMAGE_SENSOR_PV_HEIGHT;
	//pParaOut->WaitStableFrameNum = 3;

	OV3647SetDummy(OV3647_PV_dummy_pixels, OV3647_PV_dummy_lines);
    OV3647SetShutter(OV3647_g_iExpLines);
	
	#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG, TRACE_INFO, "exit OV3647Preview");
	#endif
}

static void OV3647GetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG, TRACE_INFO, "OV3647GetPreviewFlashlightInfo");
#endif

  pPreviewInfo->pixels = OV3647_PV_PERIOD_PIXEL_NUMS;
  pPreviewInfo->lines = OV3647_IMAGE_SENSOR_PV_HEIGHT;
  pPreviewInfo->frame_lines = OV3647_PV_PERIOD_LINE_NUMS;
}




static void OV3647_Set_QXGA_Mode()
{
	//;Clock configration based on 24Mhz input.
	//;48MHz PCLK output
	//;90 0e 36
	//;90 0f  0c
	//;90 11 40
	//;window configuration

#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG, TRACE_INFO, "OV3647_Set_QXGA_Mode");
#endif
	
	CamWriteCmosSensor(0x21, 0x33);		//meimei modify
	CamWriteCmosSensor(0x23, 0x0a);		//
	CamWriteCmosSensor(0x24, 0x80);		//
	CamWriteCmosSensor(0x25, 0x08);		//
	CamWriteCmosSensor(0x26, 0x60);		//
	CamWriteCmosSensor(0x28, 0x09);		//
	CamWriteCmosSensor(0x29, 0x88);		//
	CamWriteCmosSensor(0x2a, 0x06);		//
	CamWriteCmosSensor(0x2b, 0x26);		//
	kal_sleep_task(3);

	//Add for 350lux problem.
	CamWriteCmosSensor(0x93, 0x00);	//
	CamWriteCmosSensor(0xd4, 0x00);	//
	//kal_sleep_task(1);
	
	CamWriteCmosSensor(0x92, 0x00);		//
	CamWriteCmosSensor(0x12, 0x00);		//
	kal_sleep_task(5);

	//Michael add for 25fps preview, and use the pclk is 32MHz
	CamWriteCmosSensor(0x0e, 0x36);	//MCLK is 26MHz, PCLK is 34.666667MHz
#ifdef OV3647_CAP_USE48MHZ_PCLK
	CamWriteCmosSensor(0x0f, 0x0c);	//48MHz
#else
	CamWriteCmosSensor(0x0f, 0x0d);	//32MHz
#endif
	CamWriteCmosSensor(0x11, 0x40);
	kal_sleep_task(2);
	
	//CamWriteCmosSensor(0x0d, 0x01);		//2x drive capability
	//kal_sleep_task(1);

	OV3647_g_bXGA_Mode = KAL_FALSE;	//2048x1536 output
}







/*************************************************************************
* FUNCTION
*    OV3647Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    id, in, out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
  //  kal_uint16 iCapture_Column_Pixel = 0, iShutter = OV3647_ExpLines;
  //  kal_uint16 iDummyPixels = 0, iDummyLines = 0;
  //  kal_uint8 iTemp, iCP_PCLK_Div = 1;
  //  kal_uint16 iGrabWidth = 0, iGrabHeight = 0;


	//************************************OV3647**********************************//
	#if (defined(DRV_ISP_6228_SERIES) || defined(DRV_ISP_6229_SERIES))
    kal_uint8 iCP_PCLK_Divider = 1;
    #endif
    const kal_bool bMetaMode = pParaIn->MetaMode != CAMERA_SYSTEM_NORMAL_MODE;
    kal_uint16 iStartX = 0, iStartY = 0, iGrabWidth = 0, iGrabHeight = 0;
    kal_uint16 iDummyPixels = 0;
    kal_uint16 iCP_Pixels_Per_Line = 0;
#if (defined(DRV_ISP_6238_SERIES))
    static float fCP_PCLK = 0;
#elif (defined(DRV_ISP_6229_SERIES))
	static float fCP_PCLK = 0;
#endif
	kal_uint32 iShutter = 0;
	kal_uint16 prev_line_len = 0;
	kal_uint16 cap_line_len = 0;

	#ifdef OV3647_OUTPUT_DEBUG_INFO
	//kal_prompt_trace(MOD_ENG, "Cap:Zoom=%dSize=%dX%d", pImage_Window->digital_zoom_factor, pImage_Window->image_target_width, pImage_Window->image_target_height);
	#endif

    #ifdef OV3647_OUTPUT_DEBUG_INFO
        kal_prompt_trace(MOD_ENG, "[OV3647] OV3647_Capture...");

	    kal_prompt_trace(MOD_ENG, "width: %d, height: %d",pParaIn->ImageTargetWidth,pParaIn->ImageTargetHeight);
    #endif

	//************************************OV3647**********************************//
	

	//#ifdef OV3647_DEBUG
	//	kal_wap_trace(MOD_ENG, TRACE_INFO, "exit OV3647Capture");
	//#endif

    OV3647_g_iOV3647_Mode = OV3647_MODE_CAPTURE;
	
    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
		iShutter=pParaIn->CaptureShutter;
    }
	else
	{
	   iShutter = OV3647_g_iExpLines;
	}

    if ((pParaIn->ImageTargetWidth <= OV3647_IMAGE_SENSOR_PV_WIDTH_DRV)&&
        (pParaIn->ImageTargetHeight <= OV3647_IMAGE_SENSOR_PV_HEIGHT_DRV))
    {

		#ifdef OV3647_OUTPUT_DEBUG_INFO
		  kal_prompt_trace(MOD_ENG, "XGA mode.");
		#endif

		if((pParaIn->ZoomFactor >= (10 <<1)) || bMetaMode == KAL_TRUE)
			{
			    OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;

				OV3647_CAP_dummy_pixels = 0;
				OV3647_CAP_dummy_lines = 0;
			}
		else
			{
			   OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;

				OV3647_CAP_dummy_pixels = 0;
				OV3647_CAP_dummy_lines = 0;
			}

		prev_line_len = OV3647_PV_PERIOD_PIXEL_NUMS + OV3647_PV_dummy_pixels;
		cap_line_len = OV3647_PV_PERIOD_PIXEL_NUMS + OV3647_CAP_dummy_pixels;
		iShutter = iShutter * (OV3647_g_fCap_PCLK / OV3647_g_fPV_PCLK) * prev_line_len / cap_line_len;

		pParaOut->GrabStartX = OV3647_IMAGE_SENSOR_FULL_INSERT_START_X;//4;
		pParaOut->GrabStartY = OV3647_IMAGE_SENSOR_FULL_INSERT_START_Y;//3;
		pParaOut->ExposureWindowWidth = OV3647_IMAGE_SENSOR_PV_WIDTH;// - 15;
		pParaOut->ExposureWindowHeight = OV3647_IMAGE_SENSOR_PV_HEIGHT;// - 9;	// avoid black lines at bottom
	

	}
	else
	{
	
	
      #ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "QXGA mode.");
	  #endif
	
		OV3647_Set_QXGA_Mode();


	  if ((pParaIn->ImageTargetWidth<=OV3647_IMAGE_SENSOR_3M_WIDTH)&&
        (pParaIn->ImageTargetHeight<=OV3647_IMAGE_SENSOR_3M_HEIGHT))
	  	{
	  	   #ifdef CAM_OTF_CAPTURE
               #ifdef OV3647_CAP_USE48MHZ_PCLK
					OV3647_g_fCap_PCLK = 48000000;
					//OV3647_g_fCap_PCLK = 38400000;
				#else
					OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
				#endif

                if(pParaIn->ZoomFactor<200)//1x~2x capture
			              OV3647_CAP_dummy_pixels = 500;  // 10fps
			   else if(pParaIn->ZoomFactor<=400)//2x~4x capture
			               OV3647_CAP_dummy_pixels = 5277; // 4fps
		       else //4x~8x capture
		         OV3647_CAP_dummy_pixels = 17984; // 1.5fps
				OV3647_CAP_dummy_lines = 0;
          #else
             if ((pParaIn->ZoomFactor >= (10 << 1)) \
				|| bMetaMode == KAL_TRUE) 
				{
		            #ifdef OV3647_CAP_USE48MHZ_PCLK
						OV3647_g_fCap_PCLK = 48000000;
						//OV3647_g_fCap_PCLK = 38400000;
					#else
						OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
					#endif

					OV3647_CAP_dummy_pixels = 0;
					OV3647_CAP_dummy_lines = 0;
	            }
			 else
			    {
		            #ifdef OV3647_CAP_USE48MHZ_PCLK
						OV3647_g_fCap_PCLK = 48000000;
						//OV3647_g_fCap_PCLK = 38400000;
					#else
						OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
					#endif

					OV3647_CAP_dummy_pixels = 0;		//12.89fps
					OV3647_CAP_dummy_lines = 0;
	            }
		  #endif
		  
	  	}
	    else if ((pParaIn->ImageTargetWidth<=OV3647_IMAGE_SENSOR_5M_WIDTH)&&
                     (pParaIn->ImageTargetHeight<=OV3647_IMAGE_SENSOR_5M_HEIGHT))
	  	{
	  	#ifdef CAM_OTF_CAPTURE
		   #ifdef OV3647_CAP_USE48MHZ_PCLK
					OV3647_g_fCap_PCLK = 48000000;
					//OV3647_g_fCap_PCLK = 38400000;
				#else
					OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
		   #endif
		
           	if (pParaIn->ZoomFactor == 100)  //1x capture
		            OV3647_CAP_dummy_pixels = 500;  // 10fps

			else if(pParaIn->ZoomFactor < 200)//1x~2x capture

				    OV3647_CAP_dummy_pixels = 1466;  // 8fps

			else if(pParaIn->ZoomFactor <= 400)//2x~4x capture

				    OV3647_CAP_dummy_pixels = 5277; // 4fps

			else //4x~8x capture

			      OV3647_CAP_dummy_pixels = 17984; // 1.5fps

		#else

		  if ((pParaIn->ZoomFactor >= (10 << 1)) \
				|| bMetaMode == KAL_TRUE) {

	            #ifdef OV3647_CAP_USE48MHZ_PCLK
					OV3647_g_fCap_PCLK = 48000000;
					//OV3647_g_fCap_PCLK = 38400000;
				#else
	            OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
				#endif

				OV3647_CAP_dummy_pixels = 500;		//10fps.
				OV3647_CAP_dummy_lines = 0;
	        }
			else
			{
				#ifdef OV3647_CAP_USE48MHZ_PCLK
					OV3647_g_fCap_PCLK = 48000000;
					//OV3647_g_fCap_PCLK = 38400000;
				#else
					OV3647_g_fCap_PCLK = OV3647_g_fPV_PCLK;
				#endif
	            

				OV3647_CAP_dummy_pixels = 500;		//10fps.
				OV3647_CAP_dummy_lines = 0;
	        }
		#endif
	    }
		else
		{
			/* Invalid capture size. */
			kal_prompt_trace(MOD_ENG, "Oh,Invalid capture size.!!!!!");
			//ASSERT(0);
		}

        if (bMetaMode == KAL_TRUE)
        {
			pParaOut->GrabStartX = OV3647_IMAGE_SENSOR_FULL_INSERT_START_X;//12;//t[35];
			pParaOut->GrabStartY = OV3647_IMAGE_SENSOR_FULL_INSERT_START_Y;//11;//t[36];//t[8] - 10;
			pParaOut->ExposureWindowWidth = OV3647_IMAGE_SENSOR_FULL_WIDTH;//t[37];
			pParaOut->ExposureWindowHeight = OV3647_IMAGE_SENSOR_FULL_HEIGHT;//t[38];	// avoid black lines at bottom
        }
		else
		{
		    pParaOut->GrabStartX = OV3647_IMAGE_SENSOR_FULL_INSERT_START_X;//12;//t[35];
			pParaOut->GrabStartY = OV3647_IMAGE_SENSOR_FULL_INSERT_START_Y;//11;//t[36];//t[8] - 10;
			pParaOut->ExposureWindowWidth = OV3647_IMAGE_SENSOR_FULL_WIDTH;//t[37];
			pParaOut->ExposureWindowHeight = OV3647_IMAGE_SENSOR_FULL_HEIGHT;//t[38];	// avoid black lines at bottom
		}


		prev_line_len = OV3647_PV_PERIOD_PIXEL_NUMS + OV3647_PV_dummy_pixels;
		cap_line_len = OV3647_CAP_PERIOD_PIXEL_NUMS + OV3647_CAP_dummy_pixels;
		iShutter = iShutter * (OV3647_g_fCap_PCLK / OV3647_g_fPV_PCLK) * prev_line_len / cap_line_len;

		//Masked for the banding 350lux problem.
		#ifdef OV3647_AVERAGE_MODE
			iShutter <<= 1;		//Need X2 for the average mode for preview.
		#endif

   
	}
	#ifdef OV3647_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "CAP:Set_Dummy:pixels=%x,lines=%x, iShutter=%x", iDummyPixels, OV3647_g_iDummyLines, iShutter);
	#endif

	OV3647SetDummy(OV3647_CAP_dummy_pixels, OV3647_CAP_dummy_lines);
	OV3647WriteShutter(iShutter);

	if (bMetaMode == KAL_TRUE)
	{
		/* When capture raw data format, the first bar is dark then following, so delay several frame to
			make sure the shutter take effect before TG start grab data. */
		kal_sleep_task(100);	
	}

}

static void OV3647GetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    
    //pCaptureInfo->default_pclk=26000000;

    //pCaptureInfo->pixels = OV3647_CAP_PERIOD_PIXEL_NUMS + OV3647_dummy_pixels;
    //pCaptureInfo->frame_lines = OV3647_CAP_PERIOD_LINE_NUMS+OV3647_dummy_lines;
    //pCaptureInfo->lines = OV3647_IMAGE_SENSOR_FULL_HEIGHT;
    //pCaptureInfo->shutter = OV3647_g_iExpLines;   //OV3647CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    

}

static void OV3647Video(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	#ifdef OV3647_DEBUG
		kal_wap_trace(MOD_ENG, TRACE_INFO, "enter OV3647Video MaxVideoFrameRate=%d",pParaIn->MaxVideoFrameRate);
	#endif
//	g_iOV3647_Mode = OV3647_MODE_VIDEO;

	//enter  standby
    OV3647_fix_video_frame_rate = pParaIn->MaxVideoFrameRate;

	OV3647_Fix_Video_Frame_Rate(OV3647_fix_video_frame_rate);
	
	pParaOut->GrabStartX = OV3647_IMAGE_SENSOR_PV_INSERT_START_X;
	pParaOut->GrabStartY = OV3647_IMAGE_SENSOR_PV_INSERT_START_Y;
	pParaOut->ExposureWindowWidth = OV3647_IMAGE_SENSOR_PV_WIDTH;
	pParaOut->ExposureWindowHeight = OV3647_IMAGE_SENSOR_PV_HEIGHT;
	pParaOut->WaitStableFrameNum = 3;
#ifdef OV3647_DEBUG
			kal_wap_trace(MOD_ENG, TRACE_INFO, "enter OV3647Video");
#endif
    
}

static MM_ERROR_CODE_ENUM OV3647BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo = pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
  kal_uint8 i;
  
  	#ifdef OV3647_DEBUG
	kal_wap_trace(MOD_ENG, TRACE_INFO, "enter OV3647BinningInfo");
	#endif
  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    for (i = CAM_ISO_AUTO; i <= CAM_ISO_200; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_3M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_TRUE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
    }
    for (;i <= CAM_ISO_1600; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_3M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_FALSE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
    }
  break;
  }
}

/*************************************************************************
* FUNCTION
*    OV3647StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    in, out, out_len, r_out_len
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV3647StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                               P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                               kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT pStillCaptureSize=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureParaOut->FeatureInfo.FeatureEnum);

  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    pFeatureParaOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
    pFeatureParaOut->FeatureOperationSupport=CAL_FEATURE_SET_OPERATION|
                                             CAL_FEATURE_GET_OPERATION|
                                             CAL_FEATURE_QUERY_OPERATION;
    pFeatureParaOut->FeatureModeSupport=CAL_FEATURE_CAMERA_SUPPORT;
    pStillCaptureSize->IsSupport=KAL_TRUE;
    pStillCaptureSize->ItemCount = 5;
    pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    pStillCaptureSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
    pStillCaptureSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
	pStillCaptureSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3647InitOperationPara
*
* DESCRIPTION
*    This function set sensor operation para
*
* PARAMETERS
*    para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3647InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
  pInitOperPara->CaptureDelayFrame = 3; /* wait stable frame when sensor change mode (pre to cap) */
  pInitOperPara->PreviewDelayFrame = 4; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->AeCalDelayFrame = 0; /* The frame of calculation default 0 */
  pInitOperPara->AeShutDelayFrame = 0; /* The frame of setting shutter default 0 for TG int */
  pInitOperPara->AeSensorGainDelayFrame = 1; /* The frame of setting sensor gain */
  pInitOperPara->AeIspGainDelayFrame = 2; /* The frame of setting gain */
  pInitOperPara->AeCalPeriod = 3; /* AE AWB calculation period */
#if(defined(XENON_FLASHLIGHT_ANTI_RED_EYE))
  pInitOperPara->FlashlightMode = FLASHLIGHT_XENON_IGBT;
#elif(defined(XENON_FLASHLIGHT))
  pInitOperPara->FlashlightMode = FLASHLIGHT_XENON_SCR;
#elif(defined(LED_FLASHLIGHT_SUPPORT))
  pInitOperPara->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
#elif(defined(LED_ONOFF_SUPPORT))
  pInitOperPara->FlashlightMode = FLASHLIGHT_LED_ONOFF;
#else
  pInitOperPara->FlashlightMode = FLASHLIGHT_NONE;
#endif
  pInitOperPara->FlashlightDeltaMainLum = 65; // 1.015*64(1.015X)
}

/*************************************************************************
* FUNCTION
*    OV3647DscSupportInfo
*
* DESCRIPTION
*    This function get dsc support info
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
static void OV3647DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
  kal_mem_cpy(pDscSupportInfo, &OV3647_dsc_support_info, sizeof(camcorder_info_struct));
}

static MM_ERROR_CODE_ENUM OV3647Sharpness(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT pSharpnessSel=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureParaOut->FeatureInfo.FeatureEnum);

  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_SET_OPERATION:
    // set the value pFeatureParaOut->FeatureSetValue as the value of new sharpness
    break;
  case CAL_FEATURE_QUERY_OPERATION:
    pFeatureParaOut->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    pFeatureParaOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                              CAL_FEATURE_GET_OPERATION|
                                              CAL_FEATURE_QUERY_OPERATION;
    pFeatureParaOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    pSharpnessSel->IsSupport = KAL_TRUE;
    pSharpnessSel->ItemCount = 3;
    pSharpnessSel->SupportItem[0] = CAM_SHARPNESS_HIGH;
    pSharpnessSel->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
    pSharpnessSel->SupportItem[2] = CAM_SHARPNESS_LOW;
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3647SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV3647SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  if (FeatureId >= CAL_FEATURE_WEBCAM_BEGIN && FeatureId <= CAL_FEATURE_WEBCAM_END)
  {
    return OV3647WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                   FeatureParaOutLen, pRealFeatureParaOutLen);
  }
  // for the features that not support in the sensor, then it is not necessary to implement it.
  switch (FeatureId)
  {
  case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
    OV3647SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_SET_GAIN:
    OV3647SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV3647GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
    FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
    *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV3647DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV3647SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
    break;
  case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
    OV3647GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
    OV3647GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
    OV3647SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
    OV3647GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                        FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_BINNING_INFO:
    ErrorCode=OV3647BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                     (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // customized by customer
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrorCode=OV3647StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // for YUV sensor sample code
  // the following are for YUV sensor only
  case CAL_FEATURE_CAMERA_SHARPNESS:
  // please refer the sample code of OV3647Sharpness();
    ErrorCode=OV3647Sharpness((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                   (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  case CAL_FEATURE_CAMERA_EV_VALUE:
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
  case CAL_FEATURE_CAMERA_WB:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
  case CAL_FEATURE_CAMERA_SATURATION:
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    // These features are supported in YUV sensor only.
    // Put here just for notifying DD colleagues. Should be removed later for MT9P012. PC Huang 20100903
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  // the above are for YUV sensor only
  case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
    OV3647CameraParaToSensor(pFeatureParaIn);
    break;
  case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
    OV3647SensorToCameraPara(pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV3647InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    OV3647DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
    break;

  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
	CamPdnPinCtrl(OV3647SensorIdx,1);
	CamRstPinCtrl(OV3647SensorIdx,0);
	break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    pNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_GET_GAIN:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=OV3647ReadGain();
    break;
  case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 149;
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
    OV3647GetSensorGroupCount((kal_int32 *)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
    OV3647GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
    break;  
  case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
    OV3647GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
    OV3647SetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
    break;
  default:
    ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrorCode;
}

/*************************************************************************
* FUNCTION
*    OV3647SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    in/out: parameter
*    out_len: out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV3647SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
  switch (ScenarioId)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    OV3647Preview(ScenarioId, pParaIn, pParaOut);
    break;
  case CAL_SCENARIO_VIDEO:
    OV3647Video(ScenarioId, pParaIn, pParaOut);
   //OV3647Preview(ScenarioId, pParaIn, pParaOut);
    break;
  
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    OV3647Capture(ScenarioId, pParaIn, pParaOut);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3647SensorClose
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
static MM_ERROR_CODE_ENUM OV3647SensorClose(void)
{
	#ifdef OV3647_DEBUG
		kal_wap_trace(MOD_ENG, TRACE_INFO, "enter OV3647SensorClose");
	#endif

	CamPdnPinCtrl(OV3647SensorIdx, 1);

	CisModulePowerOn(OV3647SensorIdx, KAL_FALSE);

	CameraSccbClose(CAMERA_SCCB_SENSOR);
  
	#ifdef OV3647_DEBUG
	  kal_wap_trace(MOD_ENG, TRACE_INFO, "exit OV3647SensorClose");
	#endif
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3647SensorFunc
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
MM_ERROR_CODE_ENUM OV3647SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV3647 =
  {
    OV3647SensorOpen,
    OV3647SensorFeatureCtrl,
    OV3647SensorCtrl,
    OV3647SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV3647;
}

/* AT COMMAND USE */
static kal_bool OV3647AtGetValue(char *Str, kal_uint32 *Data)
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

#ifdef OV3647_OUTPUT_DEBUG_INFO
kal_bool AtFuncTest(kal_char *Str)
{
      kal_uint32 Data[10];

    kal_int32 i;
      
    if (!OV3647AtGetValue(Str, Data))
    {
        return KAL_FALSE;
    }
    if (!Data[0])
    {
        return KAL_TRUE;
    }
      
    switch (Data[1])
    {
      case 0:
               break;
      case 1:
               break;
      case 2:
               kal_prompt_trace(MOD_ENG,"Read BB CamWriteCmosSensor %x = %x", Data[2], DRV_Reg32((Data[2])));
               break;
      case 3:
               DRV_Reg32((Data[2])) = Data[3];
               kal_prompt_trace(MOD_ENG,"Write BB CamWriteCmosSensor %x = %x", Data[2], DRV_Reg32((Data[2])));
               break;
      case 4:
               kal_prompt_trace(MOD_ENG,"Read Sensor %x = %x", Data[2], CamReadCmosSensor(Data[2]));
               break;
      case 5:
               CamWriteCmosSensor(Data[2], Data[3]);
               kal_prompt_trace(MOD_ENG,"Write Sensor %x = %x", Data[2], CamReadCmosSensor(Data[2]));
               break;
	  case 6:
			kal_prompt_trace(MOD_ENG, "Read Sensor 0x380c = %x", CamReadCmosSensor(0x380c));
			kal_prompt_trace(MOD_ENG, "Read Sensor 0x380d = %x", CamReadCmosSensor(0x380d));
			kal_prompt_trace(MOD_ENG, "Read Sensor 0x380e = %x", CamReadCmosSensor(0x380e));
			kal_prompt_trace(MOD_ENG, "Read Sensor 0x380f = %x", CamReadCmosSensor(0x380f));
	   
			break;
	  case 7:
			 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3500 = %x", CamReadCmosSensor(0x3500));
			 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3501 = %x", CamReadCmosSensor(0x3501));
			 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3502 = %x", CamReadCmosSensor(0x3502));
			 kal_prompt_trace(MOD_ENG, "Read Sensor 0x350b = %x", CamReadCmosSensor(0x350b));
			 kal_prompt_trace(MOD_ENG, "Read Sensor 0x301b = %x", CamReadCmosSensor(0x301b));
	   
			break;
	  case 8:
	  	       kal_prompt_trace(MOD_ENG, "Read Sensor 0x3b07 = %x", CamReadCmosSensor(0x3b07));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3017 = %x", CamReadCmosSensor(0x3017));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3613 = %x", CamReadCmosSensor(0x3613));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3705 = %x", CamReadCmosSensor(0x3705));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x370a = %x", CamReadCmosSensor(0x370a));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x370c = %x", CamReadCmosSensor(0x370c));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3800 = %x", CamReadCmosSensor(0x3800));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3703 = %x", CamReadCmosSensor(0x3703));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3010 = %x", CamReadCmosSensor(0x3010));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3713 = %x", CamReadCmosSensor(0x3713));
        	   kal_prompt_trace(MOD_ENG, "Read Sensor 0x3714 = %x", CamReadCmosSensor(0x3714));  
               for(i=3;i<=0x27;i++)
               	{
                  kal_prompt_trace(MOD_ENG, "Read Sensor %x = %x",(0x3800+i), CamReadCmosSensor(0x3800+i));
               	}
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x370D = %x", CamReadCmosSensor(0x370D));

			 for(i=8;i<=0x0e;i++)
			  {
				kal_prompt_trace(MOD_ENG, "Read Sensor %x = %x",(0x3a00+i), CamReadCmosSensor(0x3800+i));
			  }

        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3a00 = %x", CamReadCmosSensor(0x3a00));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x401c = %x", CamReadCmosSensor(0x401c));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x505f = %x", CamReadCmosSensor(0x505f));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x5002 = %x", CamReadCmosSensor(0x5002));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x5901 = %x", CamReadCmosSensor(0x5901));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3621 = %x", CamReadCmosSensor(0x3621));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x381a = %x", CamReadCmosSensor(0x381a));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x370d = %x", CamReadCmosSensor(0x370d));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3010 = %x", CamReadCmosSensor(0x3010));
        	 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3621 = %x", CamReadCmosSensor(0x3621));  

	         kal_prompt_trace(MOD_ENG, "Read Sensor 0x3827 = %x", CamReadCmosSensor(0x3827));
	 		 kal_prompt_trace(MOD_ENG, "Read Sensor 0x3818 = %x", CamReadCmosSensor(0x3818));


        	  break;


      case 15:
               break;
    }
      return KAL_TRUE;
}

#endif
//END




