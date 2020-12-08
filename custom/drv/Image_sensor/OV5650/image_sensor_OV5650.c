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
*   image_sensor_OV5650.c
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
 *
 * removed!
 * removed!
 * removed!
 *

 * removed!
*
*
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
#include "image_sensor_OV5650.h"

#define __OV5650_DEBUG_TRACE__

kal_bool OV5650_gVGAmode = KAL_TRUE, OV5650_MPEG4_encode_mode = KAL_FALSE;
#ifdef __MEDIA_VT__
/* under construction !*/
/* under construction !*/
#endif
static kal_uint8  g_iPV_PCLK_Divider = 1;
kal_uint16 OV5650_extra_exposure_lines = 0;
static kal_uint16 OV5650_g_iBackupExtraExp = 0;
static kal_uint16 OV5650_ExpLines = 0;
kal_uint16 OV5650_sensor_global_gain=BASEGAIN, OV5650_sensor_gain_base=0x0;
OV5650_OP_TYPE g_iOV5650_Mode = OV5650_MODE_NONE;
/* MAX/MIN Explosure Lines Used By AE Algorithm */
kal_uint16 OV5650_MAX_EXPOSURE_LINES = 1000;
kal_uint8  OV5650_MIN_EXPOSURE_LINES = 2;
static kal_uint16 g_iPreview_Column_Pixel = 0;

static kal_uint32 OV5650_g_fPV_PCLK = 52 * 1000000;//24
static kal_uint32 OV5650_g_fCP_PCLK = 52 * 1000000;

static kal_uint16 OV5650_dummy_pixels=0, OV5650_dummy_lines=0;

static kal_uint32 OV5650_fix_video_frame_rate=300;
kal_uint8 OV5650StartX=0, OV5650StartY=0;
kal_uint16 OV5650CapShutter=0;

IMAGE_SENSOR_INDEX_ENUM OV5650SensorIdx;
CAL_CAMERA_SOURCE_ENUM CameraSource;
sensor_data_struct *pNvramSensorData;
extern camcorder_info_struct OV5650_dsc_support_info;

static void OV5650PageWriteCmosSensor(kal_uint32 iAddr, kal_uint32 iPara)
{
  kal_uint16 iRegPage, iRegAddr;

  iRegPage = iAddr >> 8;
  iRegAddr = iAddr & 0x000000FF;

  CamWriteCmosSensor(OV5650_PAGE_SETTING_REG, iRegPage);
  CamWriteCmosSensor(iRegAddr, iPara);
}

static kal_uint32 OV5650PageReadCmosSensor(const kal_uint32 iAddr)
{
  kal_uint16 iRegPage, iRegAddr;
  kal_uint8 iValue = 0x00;

  iRegPage = iAddr >> 8;
  iRegAddr = iAddr & 0x000000FF;

  CamWriteCmosSensor(OV5650_PAGE_SETTING_REG, iRegPage);
  iValue = CamReadCmosSensor(iRegAddr);

  return iValue;
}

static void OV5650WriteShutter(kal_uint16 shutter)
{
 
	 kal_uint16 iExp = shutter;
	 kal_uint16 Total_line;

	 if (OV5650_gVGAmode) {
		 if (iExp <= OV5650_PV_PERIOD_LINE_NUMS + OV5650_dummy_lines) {
			 Total_line = OV5650_PV_PERIOD_LINE_NUMS + OV5650_dummy_lines;
		 }else {
			 Total_line = iExp+28;
		 }
 
	 }else {
		 if (iExp <= OV5650_FULL_PERIOD_LINE_NUMS + OV5650_dummy_lines) {
			 Total_line = OV5650_FULL_PERIOD_LINE_NUMS+ OV5650_dummy_lines;
		 }else {
			 Total_line = iExp+28;
		 }
	 }
 
	 CamWriteCmosSensor(0x380e, Total_line >> 8);
	 CamWriteCmosSensor(0x380f, Total_line & 0x00FF);
	 
	 CamWriteCmosSensor(0x3500, (iExp>> 12) & 0xFF);
	 CamWriteCmosSensor(0x3501, (iExp >> 4 ) & 0xFF);
	 CamWriteCmosSensor(0x3502, (iExp<<4 ) & 0xFF);

}   /* write_OV5650_shutter */

static kal_uint16 OV5650Reg2Gain(const kal_uint8 iReg)
{
  kal_uint8 iI;
  kal_uint16 iGain = BASEGAIN;    // 1x-gain base

  // Range: 1x to 32x
  // Gain = (GAIN[7] + 1) * (GAIN[6] + 1) * (GAIN[5] + 1) * (GAIN[4] + 1) * (1 + GAIN[3:0] / 16)
  for (iI = 7; iI >= 4; iI--)
  {
    iGain *= (((iReg >> iI) & 0x01) + 1);
  }

  return iGain +  iGain * (iReg & 0x0F) / 16;
}

static kal_uint8 OV5650Gain2Reg(const kal_uint16 iGain)
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

/*************************************************************************
* FUNCTION
*    OV5650SetDummy
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
static void OV5650SetDummy(const kal_uint16 iPixels, const kal_uint16 iLines)
{
     kal_uint16 iTotalLines,iTotapixels;
   
	if(OV5650_gVGAmode == KAL_TRUE)
		{
		iTotalLines=OV5650_XGA_MODE_WITHOUT_DUMMY_LINES + iLines;
		iTotapixels=OV5650_XGA_MODE_WITHOUT_DUMMY_PIXELS+ iPixels;
		}
	else
		{
		iTotalLines=OV5650_QXGA_MODE_WITHOUT_DUMMY_LINES + iLines;
		iTotapixels=OV5650_QXGA_MODE_WITHOUT_DUMMY_PIXELS+ iPixels;
		}
	CamWriteCmosSensor(0x380c, (iTotapixels >> 8) & 0xFF);
	CamWriteCmosSensor(0x380d, iTotapixels & 0xFF);

	//Set dummy lines.
	//The maximum shutter value = Line_Without_Dummy + Dummy_lines
	CamWriteCmosSensor(0x380e, (iTotalLines >> 8) & 0xFF);
	CamWriteCmosSensor(0x380f, iTotalLines & 0xFF);
}

/*************************************************************************
* FUNCTION
*    OV5650InitialSetting
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
static void OV5650InitialSetting(void)
{
	CamWriteCmosSensor(0x3008,0x82);
	kal_sleep_task(5);
	CamWriteCmosSensor(0x3008,0x42);
	//CamWriteCmosSensor(0x302C,0x22);  //add
	CamWriteCmosSensor(0x3103,0x93);
	CamWriteCmosSensor(0x3b07,0x0d);
	CamWriteCmosSensor(0x3017,0x7f);
	CamWriteCmosSensor(0x3018,0xfc);
	CamWriteCmosSensor(0x3706,0x41);
	CamWriteCmosSensor(0x3703,0x9a);
	CamWriteCmosSensor(0x3613,0x44);
	CamWriteCmosSensor(0x3630,0x22);
	CamWriteCmosSensor(0x3605,0x04);
	CamWriteCmosSensor(0x3606,0x3f);
	CamWriteCmosSensor(0x3712,0x13);
	CamWriteCmosSensor(0x370e,0x00);
	CamWriteCmosSensor(0x370b,0x40);
	CamWriteCmosSensor(0x3600,0x54);
	CamWriteCmosSensor(0x3601,0x05);
	CamWriteCmosSensor(0x3713,0x92);
	CamWriteCmosSensor(0x3714,0x17);
	CamWriteCmosSensor(0x3631,0x22);
	CamWriteCmosSensor(0x3612,0x1a);
	CamWriteCmosSensor(0x3604,0x40);
	CamWriteCmosSensor(0x3705,0xda);
	CamWriteCmosSensor(0x370a,0x80);
	CamWriteCmosSensor(0x370c,0xa0);
	CamWriteCmosSensor(0x3710,0x28);
	CamWriteCmosSensor(0x3702,0x3a);
	CamWriteCmosSensor(0x3704,0x18);
	CamWriteCmosSensor(0x3a18,0x00);
	CamWriteCmosSensor(0x3a19,0xf8);
	CamWriteCmosSensor(0x3a00,0x38);
	CamWriteCmosSensor(0x3800,0x03);
	CamWriteCmosSensor(0x3801,0x2c);
	CamWriteCmosSensor(0x3803,0x0c);
	CamWriteCmosSensor(0x3804,0x05);
	CamWriteCmosSensor(0x3805,0x00);
	CamWriteCmosSensor(0x3806,0x03);
	CamWriteCmosSensor(0x3807,0xc0);
	CamWriteCmosSensor(0x3808,0x05);
	CamWriteCmosSensor(0x3809,0x00);
	CamWriteCmosSensor(0x380a,0x03);
	CamWriteCmosSensor(0x380b,0xc0);
	CamWriteCmosSensor(0x380c,0x0a);
	CamWriteCmosSensor(0x380d,0x3C);
	CamWriteCmosSensor(0x380e,0x04);
	CamWriteCmosSensor(0x380f,0xC4);
	CamWriteCmosSensor(0x3830,0x50);
	CamWriteCmosSensor(0x3a08,0x12);
	CamWriteCmosSensor(0x3a09,0x70);
	CamWriteCmosSensor(0x3a0a,0x0f);
	CamWriteCmosSensor(0x3a0b,0x60);
	CamWriteCmosSensor(0x3a0d,0x06);
	CamWriteCmosSensor(0x3a0e,0x06);
	CamWriteCmosSensor(0x3a13,0x54);
	CamWriteCmosSensor(0x3815,0x82);
	CamWriteCmosSensor(0x5059,0x80);
	CamWriteCmosSensor(0x505a,0x0a);
	CamWriteCmosSensor(0x505b,0x2e);
	CamWriteCmosSensor(0x3a1a,0x06);
	CamWriteCmosSensor(0x3503,0x00);
	CamWriteCmosSensor(0x3623,0x01);
	CamWriteCmosSensor(0x3633,0x24);
	CamWriteCmosSensor(0x3c01,0x34);
	CamWriteCmosSensor(0x3c04,0x28);
	CamWriteCmosSensor(0x3c05,0x98);
	CamWriteCmosSensor(0x3c07,0x07);
	CamWriteCmosSensor(0x3c09,0xc2);
	CamWriteCmosSensor(0x401d,0x28);    //modify from 0x28
	//CamWriteCmosSensor(0x4708,0x00);     //add for pclk inverse 
	CamWriteCmosSensor(0x5046,0x09);
	CamWriteCmosSensor(0x3810,0x40);
	CamWriteCmosSensor(0x3836,0x41);
	CamWriteCmosSensor(0x5000,0xfe);
	CamWriteCmosSensor(0x5001,0x01);
	CamWriteCmosSensor(0x5002,0x00);
	CamWriteCmosSensor(0x503d,0x00);
	CamWriteCmosSensor(0x5901,0x00);
	CamWriteCmosSensor(0x585a,0x01);
	CamWriteCmosSensor(0x585b,0x2c);
	CamWriteCmosSensor(0x585c,0x01);
	CamWriteCmosSensor(0x585d,0x93);
	CamWriteCmosSensor(0x585e,0x01);
	CamWriteCmosSensor(0x585f,0x90);
	CamWriteCmosSensor(0x5860,0x01);
	CamWriteCmosSensor(0x5861,0x0d);
	CamWriteCmosSensor(0x5180,0xc0);
	CamWriteCmosSensor(0x5184,0x00);
	CamWriteCmosSensor(0x470a,0x00);
	CamWriteCmosSensor(0x470b,0x00);
	CamWriteCmosSensor(0x470c,0x00);
	CamWriteCmosSensor(0x300f,0x8e);
	CamWriteCmosSensor(0x3603,0xa7);
	CamWriteCmosSensor(0x3615,0x50);
	CamWriteCmosSensor(0x3632,0x55);
	CamWriteCmosSensor(0x3620,0x56);
	CamWriteCmosSensor(0x3621,0xAf);
	CamWriteCmosSensor(0x381a,0x3c);
	CamWriteCmosSensor(0x3818,0xc0);
	CamWriteCmosSensor(0x3631,0x36);
	CamWriteCmosSensor(0x3632,0x5f);
	CamWriteCmosSensor(0x3711,0x24);
	CamWriteCmosSensor(0x370D,0x42);
	CamWriteCmosSensor(0x3818,0xC1);
	CamWriteCmosSensor(0x3010,0x30);
	CamWriteCmosSensor(0x3A08,0x16);
	CamWriteCmosSensor(0x3A09,0xE0);
	CamWriteCmosSensor(0x3A0A,0x13);
	CamWriteCmosSensor(0x3A0B,0x10);
	CamWriteCmosSensor(0x3A0D,0x03);
	CamWriteCmosSensor(0x3A0E,0x03);
	CamWriteCmosSensor(0x401f,0x03);
	CamWriteCmosSensor(0x4000,0x05);
	CamWriteCmosSensor(0x4001,0x02);
	CamWriteCmosSensor(0x401c,0x42);
	CamWriteCmosSensor(0x3008,0x02);
										  
	CamWriteCmosSensor(0x380c,0x08);
	CamWriteCmosSensor(0x380d,0x3C);
	CamWriteCmosSensor(0x380e,0x03);
	CamWriteCmosSensor(0x380f,0xD0);
										  
	CamWriteCmosSensor(0x3503,0x03);
	CamWriteCmosSensor(0x3501,0x44);
	CamWriteCmosSensor(0x3502,0xa0);
	CamWriteCmosSensor(0x350b,0x3d);
	CamWriteCmosSensor(0x5001,0x01);
	CamWriteCmosSensor(0x5046,0x09);
	CamWriteCmosSensor(0x3406,0x01);
	CamWriteCmosSensor(0x3400,0x04);
	CamWriteCmosSensor(0x3401,0x00);
	CamWriteCmosSensor(0x3402,0x04);
	CamWriteCmosSensor(0x3403,0x00);
	CamWriteCmosSensor(0x3404,0x04);
	CamWriteCmosSensor(0x3405,0x00);
	CamWriteCmosSensor(0x5000,0x06);
	CamWriteCmosSensor(0x3621,0xbf);
	CamWriteCmosSensor(0x3818,0x81);

} 

/*************************************************************************
* FUNCTION
*  OV5650_GetID
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
static void OV5650_GetID(kal_uint8 *pWriteID, kal_uint8 *pReadID)
{
  *pWriteID = OV5650_SW_SCCB_WRITE_ID;
  *pReadID = OV5650_SW_SCCB_READ_ID;
}

/*************************************************************************
* FUNCTION
*  OV5650_GetSize
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
static void OV5650_GetSize(kal_uint16 *pWidth, kal_uint16 *pHeight)
{
  *pWidth = OV5650_IMAGE_SENSOR_FULL_WIDTH;
  *pHeight = OV5650_IMAGE_SENSOR_FULL_HEIGHT;
}

/*************************************************************************
* FUNCTION
*  OV5650_get_period
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
static void OV5650_GetPeriod(kal_uint16 *pPixels, kal_uint16 *pLines)
{
#if (defined(DRV_ISP_6238_SERIES))
  *pPixels = OV5650_PV_PERIOD_PIXEL_NUMS + OV5650_dummy_pixels;
  *pLines =  OV5650_PV_PERIOD_LINE_NUMS + OV5650_dummy_lines;
#else
  *pPixels = OV5650_PV_PERIOD_PIXEL_NUMS;
  *pLines = OV5650_PV_PERIOD_LINE_NUMS;
#endif
}

static void OV5650SetSXVGA (void)
{

CamWriteCmosSensor(0x3b07,0x0d);
CamWriteCmosSensor(0x3017,0x7f);
CamWriteCmosSensor(0x3703,0x9a);

CamWriteCmosSensor(0x3713,0x92);
CamWriteCmosSensor(0x3714,0x17);
CamWriteCmosSensor(0x370c,0xa0);

CamWriteCmosSensor(0x3800,0x03);
CamWriteCmosSensor(0x3801,0x2c);
CamWriteCmosSensor(0x3803,0x0c);
CamWriteCmosSensor(0x3804,0x05);
CamWriteCmosSensor(0x3805,0x00);
CamWriteCmosSensor(0x3806,0x03);
CamWriteCmosSensor(0x3807,0xc0);
CamWriteCmosSensor(0x3808,0x05);
CamWriteCmosSensor(0x3809,0x00);
CamWriteCmosSensor(0x380a,0x03);
CamWriteCmosSensor(0x380b,0xc0);
CamWriteCmosSensor(0x380c,0x08);
CamWriteCmosSensor(0x380d,0x3C);
CamWriteCmosSensor(0x380e,0x03);
CamWriteCmosSensor(0x380f,0xD0);

CamWriteCmosSensor(0x401c,0x42);
CamWriteCmosSensor(0x505f,0x05);

CamWriteCmosSensor(0x370D,0x42);
CamWriteCmosSensor(0x300F,0x8E);	//ADD
CamWriteCmosSensor(0x3010,0x30);
CamWriteCmosSensor(0x3A08,0x16);
CamWriteCmosSensor(0x3A09,0xE0);
CamWriteCmosSensor(0x3A0A,0x13);
CamWriteCmosSensor(0x3A0B,0x10);
CamWriteCmosSensor(0x3A0D,0x03);
CamWriteCmosSensor(0x3A0E,0x03);
CamWriteCmosSensor(0x3621,0xbf); //CamWriteCmosSensor(0x3621,0xbf); 
CamWriteCmosSensor(0x3818,0x81);

}

static void OV5650SetPvMirrorFlip(kal_uint8 image_mirror)
{
  switch (image_mirror)
  {
	  case IMAGE_SENSOR_MIRROR_NORMAL://h_mirror 
		  CamWriteCmosSensor(0x3621, 0xaf);
		  CamWriteCmosSensor(0x505a, 0x0a);//add hmirror
		  CamWriteCmosSensor(0x505b, 0x2e);//
		  CamWriteCmosSensor(0x3827, 0x0c);
		  CamWriteCmosSensor(0x3818, 0xc1);
		  kal_prompt_trace(MOD_ENG,"IMAGE_NORMAL");
		  break;
	  case IMAGE_SENSOR_MIRROR_H:
		  CamWriteCmosSensor(0x3621, 0xaf);
		  CamWriteCmosSensor(0x505a, 0x0a);//add hmirror
		  CamWriteCmosSensor(0x505b, 0x2e);//
		  CamWriteCmosSensor(0x3827, 0x0c);
		  CamWriteCmosSensor(0x3818, 0xc1);
		  kal_prompt_trace(MOD_ENG,"IMAGE_H_MIRROR");
		  break;
	  case IMAGE_SENSOR_MIRROR_V:
 		  CamWriteCmosSensor(0x3621, 0xbf);
		  CamWriteCmosSensor(0x505a, 0x00);//add hmirror
		  CamWriteCmosSensor(0x505b, 0x12);//
		  CamWriteCmosSensor(0x3827, 0x0b);
		  CamWriteCmosSensor(0x3818, 0xa1);
		  kal_prompt_trace(MOD_ENG,"IMAGE_V_MIRROR");
		  break;
	  case IMAGE_SENSOR_MIRROR_HV:
		  CamWriteCmosSensor(0x3621, 0xaf);
		  CamWriteCmosSensor(0x505a, 0x0a);//add hmirror
		  CamWriteCmosSensor(0x505b, 0x2e);//
		  CamWriteCmosSensor(0x3827, 0x0b);
		  CamWriteCmosSensor(0x3818, 0xe1);
		  kal_prompt_trace(MOD_ENG,"IMAGE_HV_MIRROR");
		  break;
	  default:
		  ASSERT(0);
  }

} 

static void OV5650SetCapMirrorFlip(kal_uint8 image_mirror)
{
  switch (image_mirror)
  {
	  case IMAGE_SENSOR_MIRROR_NORMAL://h_mirror 
		  CamWriteCmosSensor(0x3621, 0x2f);
		  CamWriteCmosSensor(0x505a, 0x0a);
		  CamWriteCmosSensor(0x505b, 0x2e);
		  CamWriteCmosSensor(0x3827, 0x0c);
		  CamWriteCmosSensor(0x3818, 0xc0);
		  kal_prompt_trace(MOD_ENG,"IMAGE_NORMAL");
		  break;
	  case IMAGE_SENSOR_MIRROR_H:
		  CamWriteCmosSensor(0x3621, 0x2f);
		  CamWriteCmosSensor(0x505a, 0x0a);
		  CamWriteCmosSensor(0x505b, 0x2e);
		  CamWriteCmosSensor(0x3827, 0x0c);
		  CamWriteCmosSensor(0x3818, 0xc0);
		  kal_prompt_trace(MOD_ENG,"IMAGE_H_MIRROR");
		  break;
	  case IMAGE_SENSOR_MIRROR_V:
		  CamWriteCmosSensor(0x3621, 0x3f);
		  CamWriteCmosSensor(0x505a, 0x00);
		  CamWriteCmosSensor(0x505b, 0x12);
		  CamWriteCmosSensor(0x3827, 0x0b);
		  CamWriteCmosSensor(0x3818, 0xa0);
		  kal_prompt_trace(MOD_ENG,"IMAGE_V_MIRROR");
		  break;
	  case IMAGE_SENSOR_MIRROR_HV:
		  CamWriteCmosSensor(0x3621, 0x2f);
		  CamWriteCmosSensor(0x505a, 0x0a);
		  CamWriteCmosSensor(0x505b, 0x2e);
		  CamWriteCmosSensor(0x3827, 0x0b);
		  CamWriteCmosSensor(0x3818, 0xe0);
		  kal_prompt_trace(MOD_ENG,"IMAGE_HV_MIRROR");
		  break;
	  default:
		  ASSERT(0);
  }

} 

static void OV5650SetUXGA(void)
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
#if 0 	  
#ifdef OV5650_52M_CAP_PCLK
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
#endif
/* under construction !*/
/* under construction !*/
#else
     CamWriteCmosSensor(0x3008,0x42);
	 CamWriteCmosSensor(0x3b07,0x0c);
	 CamWriteCmosSensor(0x3017,0xff);
     CamWriteCmosSensor(0x3613,0x44);
     CamWriteCmosSensor(0x3705,0xda);
     CamWriteCmosSensor(0x370a,0x80);
     CamWriteCmosSensor(0x370c,0x00);
     CamWriteCmosSensor(0x3800,0x02);
     CamWriteCmosSensor(0x3703,0xe6);   
     CamWriteCmosSensor(0x3010,0x70);
     CamWriteCmosSensor(0x3713,0x22);
     CamWriteCmosSensor(0x3714,0x27);
     CamWriteCmosSensor(0x3803,0x0c);
     CamWriteCmosSensor(0x3804,0x0a);
     CamWriteCmosSensor(0x3805,0x20);
     CamWriteCmosSensor(0x3806,0x07);
     CamWriteCmosSensor(0x3807,0x98);
     CamWriteCmosSensor(0x3808,0x0a);
     CamWriteCmosSensor(0x3809,0x20);
     CamWriteCmosSensor(0x380a,0x07);
     CamWriteCmosSensor(0x380b,0x98);
     CamWriteCmosSensor(0x380c,0x0c);
     CamWriteCmosSensor(0x380d,0xb4);
     CamWriteCmosSensor(0x380e,0x07);
     CamWriteCmosSensor(0x380f,0xb0);
     CamWriteCmosSensor(0x3801,0x54);
     CamWriteCmosSensor(0x3815,0x82);
     CamWriteCmosSensor(0x381c,0x20);
     CamWriteCmosSensor(0x381d,0x0a);
     CamWriteCmosSensor(0x381e,0x01);
     CamWriteCmosSensor(0x381f,0x20);
     CamWriteCmosSensor(0x3820,0x00);
     CamWriteCmosSensor(0x3821,0x00);
     CamWriteCmosSensor(0x3824,0x01);
     CamWriteCmosSensor(0x3825,0xb4);
     CamWriteCmosSensor(0x3827,0x0c);
     CamWriteCmosSensor(0x370D,0x04);
     CamWriteCmosSensor(0x3A08,0x12);
     CamWriteCmosSensor(0x3A09,0x70);
     CamWriteCmosSensor(0x3A0A,0x0f);
     CamWriteCmosSensor(0x3A0B,0x60);
     CamWriteCmosSensor(0x3A0D,0x06);
     CamWriteCmosSensor(0x3A0E,0x06);
     CamWriteCmosSensor(0x3a00,0x38);
     CamWriteCmosSensor(0x401c,0x46);
     CamWriteCmosSensor(0x505f,0x04);
     CamWriteCmosSensor(0x5002,0x00);
     CamWriteCmosSensor(0x5901,0x00);
     CamWriteCmosSensor(0x3621,0x2f);
     CamWriteCmosSensor(0x381a,0x3c);
     CamWriteCmosSensor(0x370d,0x04);
     CamWriteCmosSensor(0x3010,0x30);
     CamWriteCmosSensor(0x3621,0x3f);
     CamWriteCmosSensor(0x3827,0x0c);
     CamWriteCmosSensor(0x3818,0x80);
     CamWriteCmosSensor(0x3008,0x02);

#endif 
}

static void OV5650SetCAPPCLK(kal_uint32 Clk)
{
  static const kal_uint8 ClkSetting[][3] =
  {
    {0x8E,0x30}, /* MCLK: 26M, SYS CLK: 52M, PCLK: 52M  */
    {0x8E,0x20}, /* MCLK: 26M, SYS CLK: 70M, PCLK: 70M */
    {0x8D,0x40}, /* MCLK: 26M, SYS CLK: 83.2M, PCLK: 83.2M */
    {0x8E,0x70}, /* MCLK: 26M, SYS CLK: 26M, PCLK: 26M*/
    {0x8E,0x50}, /* MCLK: 26M, SYS CLK: 34.6M, PCLK: 34.6M */
    {0x8E,0xc0}, /* MCLK: 26M, SYS CLK: 17.3M, PCLK: 17.3M */
  };
  kal_uint8 i = 0;

  OV5650_g_fCP_PCLK = Clk;
  switch (OV5650_g_fCP_PCLK)
  {
  case 52000000: i = 0; break;
  case 69333333: i = 1; break;
  case 83200000: i = 2; break;
  case 26000000: i = 3; break;
  case 34666666: i = 4; break;
  case 17333333: i = 5; break;
  default: ASSERT(0);
  }
/*VCO = MCLK*R_SELD5*R_DIVP/R_PREDIV 
   R_SELD5 =bypass,1,4,5 for 300f[7:6] = 0~3, respectively
   R_DIVP : 3011[5:0] , pll_div   default 16
   R_PREDIV = 1,1.5,2,2.5,3,4,6,8 for 3012[2:0] = 0~7, respectively   default 2
       
      we don't modify above setting normally,so VCO = 32*MCLK

    pclk = VCO/((divs+1)*div1*seld2p5*2)
    divs : 3010[7:4],   default 1
    div1 = 2,1 for 300f[2] = 0,1     default 1
    seld2p5 =0,1,2,2.5 for 300f[1:0] = 0~3, respectively  default 2

*/
  CamWriteCmosSensor(0x300F, ClkSetting[i][0]);
  CamWriteCmosSensor(0x3010, ClkSetting[i][1]);

}


/*************************************************************************
* FUNCTION
*  OV5650SetShutter
*
* DESCRIPTION
*  This function set e-shutter of OV5650 to change exposure time.
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
static void OV5650SetShutter(kal_uint16 iShutter)
{
  OV5650_ExpLines = iShutter;
  
  OV5650WriteShutter(iShutter);
 
#ifdef __OV5650_DEBUG_TRACE__
   kal_prompt_trace(MOD_ENG,"OV5650SetShutter ...........iShutter = %d",iShutter);
#endif 
}

/*************************************************************************
* FUNCTION
*  OV5650SetGain
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
static kal_uint16 OV5650SetGain(kal_uint16 iGain)
{
  const kal_uint16 iBaseGain = OV5650Reg2Gain(pNvramSensorData->cct[OV5650_INDEX_BASE_GAIN].para);
  const kal_uint16 iGain2Set = iGain * iBaseGain / BASEGAIN;
  kal_uint8 iReg = OV5650Gain2Reg(iGain2Set);

  CamWriteCmosSensor(0x350b, iReg);//CamWriteCmosSensor(0x3001, iReg);
  
#ifdef __OV5650_DEBUG_TRACE__
  kal_prompt_trace(MOD_ENG,"OV5650_SetGain ...........iGain = %d,iReg = %x",iGain,iReg);
#endif 
  
  return OV5650Reg2Gain(iReg) * BASEGAIN / iBaseGain;  
}

static kal_uint16 OV5650ReadGain(void)
{  
  kal_uint8 iReg = 0;

 iReg = CamReadCmosSensor(0x350b);

  return OV5650Reg2Gain(iReg);
}

static void OV5650SetFlashlight (kal_bool enable)
{
  //flashlight_power_on(enable);
  FlashlightPowerOn(OV5650SensorIdx, enable);
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
static void OV5650CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;
  
  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    OV5650PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    OV5650PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=0; i<FACTORY_END_ADDR; i++)
  {
    OV5650PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr,pCameraPara->SENSOR.reg[i].para);
  }
}

// update camera_para from sensor register
static void OV5650SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;

  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_START_ADDR); i++)
  {
    pCameraPara->SENSOR.reg[i].para = OV5650PageReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    pCameraPara->SENSOR.reg[i].para = OV5650PageReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
}

//------------------------Engineer mode---------------------------------
extern int sprintf(char *buffer, const char *format, ... );

static void  OV5650GetSensorGroupCount(kal_int32* sensor_count_ptr)
{
  *sensor_count_ptr = OV5650_GROUP_TOTAL_NUMS;
}

static void OV5650GetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
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
static void OV5650GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
  kal_uint8 temp_reg=0x00;
  kal_uint16 temp_gain=0;

  CamWriteCmosSensor(OV5650_PAGE_SETTING_REG,0x01);
  switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:
          sprintf((char *) (info_ptr->ItemNamePtr), "SENSOR_BASEGAIN");
          
          temp_gain = OV5650Reg2Gain(pNvramSensorData->cct[SENSOR_BASEGAIN].para);
        
          info_ptr->ItemValue=(temp_gain*1000)/BASEGAIN;
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1*1000; //Min global gain = 1x base gain
          info_ptr->Max=16*1000;//Max global gain = 16x base gain
        break;
        
        case PRE_GAIN_R_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-R");

		  // R, G, B gain = reg / 0x400
		  info_ptr->ItemValue = pNvramSensorData->cct[PRE_GAIN_R_INDEX].para * 1000 / 0x400;

          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000; //Min pre-gain
          info_ptr->Max=0xfff * 1000 / 0x400; //Max pre-gaim 
          break;
        case PRE_GAIN_B_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-B");          
		  // R, G, B gain = reg / 0x400
		  info_ptr->ItemValue = pNvramSensorData->cct[PRE_GAIN_B_INDEX].para * 1000 / 0x400;

          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000; //Min pre-gain
          info_ptr->Max=0xfff * 1000 / 0x400; //Max pre-gaim 

        break;
        
      case PRE_GAIN_Gr_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
          
		  // R, G, B gain = reg / 0x400
		  info_ptr->ItemValue = pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].para * 1000 / 0x400;

          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000; //Min pre-gain
          info_ptr->Max=0xfff * 1000 / 0x400; //Max pre-gaim

          break;
      case PRE_GAIN_Gb_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gb");  
        
		// R, G, B gain = reg / 0x400
		info_ptr->ItemValue = pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para * 1000 / 0x400;
		
		info_ptr->IsTrueFalse=KAL_FALSE;
		info_ptr->IsReadOnly=KAL_FALSE;
		info_ptr->IsNeedRestart=KAL_FALSE;
		info_ptr->Min=1000; //Min pre-gain
		info_ptr->Max=0xfff * 1000 / 0x400; //Max pre-gaim

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
      
    case FRAME_RATE_LIMITATION:
    break;   
    case REGISTER_EDITOR:
    break;  

    default:
      ASSERT(0);
    }  
    break;
    default:
      ASSERT(0); 

  }
}


static kal_bool OV5650SetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
   kal_uint8 temp_reg;
   kal_uint16 temp_gain;
   
   
   switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:
          temp_gain = (ItemValue * BASEGAIN)/1000;
          temp_reg = OV5650Gain2Reg(temp_gain);        

          pNvramSensorData->cct[SENSOR_BASEGAIN].para = temp_reg;
          CamWriteCmosSensor(pNvramSensorData->cct[SENSOR_BASEGAIN].addr,temp_reg);
          break;
          
        case PRE_GAIN_R_INDEX:
        case PRE_GAIN_B_INDEX:
        case PRE_GAIN_Gr_INDEX:
        case PRE_GAIN_Gb_INDEX:
		  if (ItemValue < 1 * 1000 || ItemValue > (kal_uint32) (1000 * 0xfff / 0x400)) {
			    return KAL_FALSE;
			  }

		  temp_gain = ItemValue * 0x400 / 1000;  // R, G, B gain = reg. / 0x400
	    
          pNvramSensorData->cct[item_idx].para = temp_gain;
		  CamWriteCmosSensor((pNvramSensorData->cct[item_idx].addr>>16)&0xffff, (temp_gain>>8)&0xff);
		  CamWriteCmosSensor(pNvramSensorData->cct[item_idx].addr&0xffff, temp_gain&0xff);

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
    break;  

    default:
       ASSERT(0);


  }
  
  return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    OV5650GetSensorInfo
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
static void OV5650GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
  pSensorInfo->SensorId = OV5650_SENSOR_ID;
  pSensorInfo->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  pSensorInfo->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;    
  pSensorInfo->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  pSensorInfo->PixelClkInv = KAL_FALSE;
  pSensorInfo->PixelClkPolarity = POLARITY_LOW;
  pSensorInfo->HsyncPolarity = POLARITY_LOW;
  pSensorInfo->VsyncPolarity = POLARITY_LOW;
  pSensorInfo->PreviewMclkFreq = 26000000;
  pSensorInfo->CaptureMclkFreq = 26000000;
  pSensorInfo->VideoMclkFreq = 26000000;
  pSensorInfo->PreviewWidth = OV5650_IMAGE_SENSOR_PV_WIDTH;
  pSensorInfo->PreviewHeight = OV5650_IMAGE_SENSOR_PV_HEIGHT;
  pSensorInfo->FullWidth = OV5650_IMAGE_SENSOR_FULL_WIDTH;
  pSensorInfo->FullHeight = OV5650_IMAGE_SENSOR_FULL_HEIGHT;
  pSensorInfo->SensorAfSupport = KAL_FALSE;
  pSensorInfo->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    OV5650PowerOn
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
static kal_uint16 OV5650PowerOn(void)
{
  kal_uint16 SensorId = NULL_SENSOR_ID;
  kal_uint8 i = 0;
  CamPdnPinCtrl(OV5650SensorIdx, 1);
  CisModulePowerOn(OV5650SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV5650_HW_SCCB_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
  
  kal_sleep_task(2); // To wait for Stable Power

  CamPdnPinCtrl(OV5650SensorIdx, 0);

  /* Reset the sensor */
  CamRstPinCtrl(OV5650SensorIdx, 1); //Sensor RESET pin high
  kal_sleep_task(4);

  CamRstPinCtrl(OV5650SensorIdx, 0); //Sensor RESET pin low
      
  kal_sleep_task(4);

 CamRstPinCtrl(OV5650SensorIdx, 1);  //Sensor RESET pin high
  kal_sleep_task(8);

  /* Check ID */
  for (i=0;i<3;i++)
  {
    SensorId=(CamReadCmosSensor(0x300A) << 8) | CamReadCmosSensor(0x300B);

    if (SensorId==OV5650_SENSOR_ID)
    break;
  }
  
#ifdef __OV5650_DEBUG_TRACE__
	 kal_prompt_trace(MOD_ENG,"OV5650PowerOn ...........SensorId = %x",SensorId);
#endif 
  return SensorId;
} /* OV5650PowerOn() */

/*************************************************************************
* FUNCTION
*    OV5650DetectSensorId
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
static kal_uint32 OV5650DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM OV5650SensorClose(void);
  kal_uint16 OVOV5650PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == OV5650SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(AnotherSensorIdx, i);
      CamPdnPinCtrl(AnotherSensorIdx, j);
      SensorId = OV5650PowerOn();
      OV5650SensorClose();
#ifdef __OV5650_DEBUG_TRACE__
      kal_wap_trace(MOD_ENG,TRACE_INFO,"OV5650DetectSensorId:%x",SensorId);
#endif
      if (OV5650_SENSOR_ID == SensorId)
      {
        return OV5650_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;

}

static MM_ERROR_CODE_ENUM OV5650SensorOpen(void)
{
  IspSetInterruptTriggerDelayLines(1);  // 0: VD INT, others: TG INT & start line
  
  if (OV5650_SENSOR_ID != OV5650PowerOn()) 
  	return MM_ERROR_SENSOR_READ_ID_FAIL;
  
  OV5650InitialSetting();
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV5650Preview
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
static void OV5650Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    OV5650StartX = 2;
	OV5650StartY = 2;
	OV5650_gVGAmode = KAL_TRUE;

    OV5650SetSXVGA();  //set preview mode 
  
    OV5650SetPvMirrorFlip(pParaIn->ImageMirror);

    OV5650_dummy_pixels = 555;    //don't modify this dummy 
    OV5650_dummy_lines = 0; 

    g_iOV5650_Mode = OV5650_MODE_PREVIEW;

    OV5650SetDummy(OV5650_dummy_pixels, OV5650_dummy_lines);
	
	g_iPreview_Column_Pixel = OV5650_XGA_MODE_WITHOUT_DUMMY_PIXELS + OV5650_dummy_pixels;

    pParaOut->GrabStartX = OV5650StartX;
    pParaOut->GrabStartY = OV5650StartY;
    pParaOut->ExposureWindowWidth = OV5650_IMAGE_SENSOR_PV_WIDTH - OV5650StartX  - 8;
    pParaOut->ExposureWindowHeight = OV5650_IMAGE_SENSOR_PV_HEIGHT - OV5650StartY - 6;

    //OV5650WriteShutter(OV5650_ExpLines);
#ifdef __OV5650_DEBUG_TRACE__
		 kal_prompt_trace(MOD_ENG,"OV5650Preview ...........OV5650_ExpLines = %d",OV5650_ExpLines);
#endif 


}

static void OV5650GetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
  pPreviewInfo->pixels = OV5650_PV_PERIOD_PIXEL_NUMS;
  pPreviewInfo->lines = OV5650_IMAGE_SENSOR_PV_HEIGHT;
  pPreviewInfo->frame_lines = OV5650_PV_PERIOD_LINE_NUMS;
}

/*************************************************************************
* FUNCTION
*    OV5650Capture
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
static void OV5650Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    volatile kal_uint16 Shutter=OV5650_ExpLines;	
	float temp_iShutter = OV5650_ExpLines;
    kal_uint16 iCapture_Column_Pixel = 0, iShutter = OV5650_ExpLines;
    kal_uint16 iDummyPixels = 0, iDummyLines = 0;
    kal_uint8 iTemp, iCP_PCLK_Div = 1;
    kal_uint16 iGrabWidth = 0, iGrabHeight = 0;
    OV5650StartX = 2;
	OV5650StartY = 2;

    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        Shutter=pParaIn->CaptureShutter;
    }

    if ((pParaIn->ImageTargetWidth<=OV5650_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=OV5650_IMAGE_SENSOR_PV_HEIGHT))
    {
      OV5650_gVGAmode = KAL_TRUE;
	  
      OV5650_dummy_pixels= 555;         
      OV5650_dummy_lines = 0;

      g_iOV5650_Mode = OV5650_MODE_CAPTURE;
  	  
	  iCapture_Column_Pixel = OV5650_XGA_MODE_WITHOUT_DUMMY_PIXELS + OV5650_dummy_pixels;
	  
	  pParaOut->GrabStartX = OV5650StartX;
	  pParaOut->GrabStartY = OV5650StartY;
	  pParaOut->ExposureWindowWidth = OV5650_IMAGE_SENSOR_PV_WIDTH - OV5650StartX  - 14;
	  pParaOut->ExposureWindowHeight = OV5650_IMAGE_SENSOR_PV_HEIGHT - OV5650StartY - 10;
   
    }   
    
    else 
    {
     OV5650_gVGAmode = KAL_FALSE;
	 
     OV5650SetUXGA();
     OV5650SetCapMirrorFlip(pParaIn->ImageMirror);
     OV5650SetCAPPCLK(69333333);
     #ifdef CAM_OTF_CAPTURE
       
      if (100==pParaIn->ZoomFactor) /* 1x capture */
        {
          OV5650_dummy_pixels= 555;        
        }
      else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
        {
          OV5650_dummy_pixels= 1100;        
        }
      else if(pParaIn->ZoomFactor<=400)/* 2x~4x capture */
        {
          OV5650_dummy_pixels= 4000;           
        }
      else /* 4x~8x capture */
        {
          OV5650_dummy_pixels= 8000;            
        }
        
	 #elif CAM_OFFLINE_CAPTURE
       if (pParaIn->ZoomFactor<=200) 
        {
  	      OV5650_dummy_pixels = 140;
        }
  	   else
  	    {
  	      OV5650_dummy_pixels = 1100;  
  	    }
	 
     #else
       if (pParaIn->ZoomFactor<=200) 
        {
  	      OV5650_dummy_pixels = 140;
        }
  	   else
  	    {
  	      OV5650_dummy_pixels = 2000;  
  	    }
     #endif
     OV5650_dummy_lines = 24;  
	 
    iGrabWidth = OV5650_IMAGE_SENSOR_FULL_WIDTH - OV5650StartX  - 16;
    iGrabHeight = OV5650_IMAGE_SENSOR_FULL_HEIGHT- OV5650StartY - 12;
   
    iCapture_Column_Pixel = OV5650_QXGA_MODE_WITHOUT_DUMMY_PIXELS + OV5650_dummy_pixels;
  
    pParaOut->GrabStartX = OV5650StartX;
    pParaOut->GrabStartY = OV5650StartY;
    pParaOut->ExposureWindowWidth = iGrabWidth;
    pParaOut->ExposureWindowHeight = iGrabHeight;

  }
 
#ifdef __OV5650_DEBUG_TRACE__
  kal_prompt_trace(MOD_ENG,"iShutter before calc = %d,temp_iShutter = %d",iShutter,temp_iShutter);
#endif 
  
  temp_iShutter = temp_iShutter * (OV5650_g_fCP_PCLK / OV5650_g_fPV_PCLK) * g_iPreview_Column_Pixel / iCapture_Column_Pixel;
  
  if(OV5650_gVGAmode == KAL_FALSE)
	  temp_iShutter *= 2;
  
  iShutter=temp_iShutter+0.5;
  
  if(iShutter<1)
	  iShutter=1;
	  
#ifdef __OV5650_DEBUG_TRACE__
	  kal_prompt_trace(MOD_ENG,"iShutter after calc = %d",iShutter);
#endif 

  OV5650SetDummy(OV5650_dummy_pixels, OV5650_dummy_lines);

  OV5650WriteShutter(iShutter);

  OV5650CapShutter=iShutter;
}

static void OV5650GetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    
    pCaptureInfo->default_pclk=52000000;

    pCaptureInfo->pixels = OV5650_QXGA_MODE_WITHOUT_DUMMY_PIXELS + OV5650_dummy_pixels;
    pCaptureInfo->frame_lines = OV5650_FULL_PERIOD_LINE_NUMS+OV5650_dummy_lines;
    pCaptureInfo->lines = OV5650_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = OV5650CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    

}

static void OV5650Video(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    OV5650StartX = 2;
	OV5650StartY = 2;

    OV5650SetSXVGA();

    OV5650_gVGAmode = KAL_TRUE;
	OV5650_dummy_pixels = 555;    //don't modify this dummy 
    OV5650_dummy_lines = 0; 
  
    OV5650SetPvMirrorFlip(pParaIn->ImageMirror);

    OV5650_fix_video_frame_rate = pParaIn->MaxVideoFrameRate;
	
    OV5650_MAX_EXPOSURE_LINES = (kal_uint16)(((52000000*10)/OV5650_fix_video_frame_rate)/(OV5650_PV_PERIOD_PIXEL_NUMS+OV5650_dummy_pixels));      
  if((OV5650_MAX_EXPOSURE_LINES>OV5650_PV_PERIOD_LINE_NUMS)&&(OV5650_dummy_lines<(OV5650_MAX_EXPOSURE_LINES - OV5650_PV_PERIOD_LINE_NUMS)))    
    OV5650_dummy_lines = OV5650_MAX_EXPOSURE_LINES - OV5650_PV_PERIOD_LINE_NUMS;
      
  CamWriteCmosSensor(0x380e, (OV5650_MAX_EXPOSURE_LINES >> 8) & 0xFF);
  CamWriteCmosSensor(0x380f, OV5650_MAX_EXPOSURE_LINES & 0xFF);
  
  pParaOut->GrabStartX = OV5650StartX;
  pParaOut->GrabStartY = OV5650StartY;
  pParaOut->ExposureWindowWidth = OV5650_IMAGE_SENSOR_PV_WIDTH - OV5650StartX  - 14;
  pParaOut->ExposureWindowHeight = OV5650_IMAGE_SENSOR_PV_HEIGHT - OV5650StartY - 10;

}

static MM_ERROR_CODE_ENUM OV5650BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo = pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
  kal_uint8 i;
  
  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    for (i = CAM_ISO_AUTO; i <= CAM_ISO_400; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_5M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_TRUE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
    }
    for (;i <= CAM_ISO_1600; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_1M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_TRUE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_TRUE;
    }
  break;
  }
}

/*************************************************************************
* FUNCTION
*    OV5650StillCaptureSize
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
static MM_ERROR_CODE_ENUM OV5650StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
    pStillCaptureSize->ItemCount = 7;
    pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    pStillCaptureSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
    pStillCaptureSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
	pStillCaptureSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
	pStillCaptureSize->SupportItem[5] = CAM_IMAGE_SIZE_4M;
	pStillCaptureSize->SupportItem[6] = CAM_IMAGE_SIZE_5M;
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV5650InitOperationPara
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
static void OV5650InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
  pInitOperPara->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  pInitOperPara->PreviewDelayFrame = 1; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->AeCalDelayFrame = 0; /* The frame of calculation default 0 */
  pInitOperPara->AeShutDelayFrame = 0; /* The frame of setting shutter default 0 for TG int */
  pInitOperPara->AeSensorGainDelayFrame = 2; /* The frame of setting sensor gain */
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
*    OV5650DscSupportInfo
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
static void OV5650DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
  kal_mem_cpy(pDscSupportInfo, &OV5650_dsc_support_info, sizeof(camcorder_info_struct));
}

static MM_ERROR_CODE_ENUM OV5650Sharpness(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
*    OV5650SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV5650SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  if (FeatureId >= CAL_FEATURE_WEBCAM_BEGIN && FeatureId <= CAL_FEATURE_WEBCAM_END)
  {
    return OV5650WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                   FeatureParaOutLen, pRealFeatureParaOutLen);
  }
  // for the features that not support in the sensor, then it is not necessary to implement it.
  switch (FeatureId)
  {
  case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
    OV5650SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_SET_GAIN:
    OV5650SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV5650GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
    FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
    *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV5650DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV5650SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
    break;
  case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
    OV5650GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
    OV5650GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
    OV5650SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
    OV5650GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                        FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_BINNING_INFO:
    ErrorCode=OV5650BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                     (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // customized by customer
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrorCode=OV5650StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // for YUV sensor sample code
  // the following are for YUV sensor only
  case CAL_FEATURE_CAMERA_SHARPNESS:
  // please refer the sample code of OV5650Sharpness();
    ErrorCode=OV5650Sharpness((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
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
  case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    // These features are supported in YUV sensor only.
    // Put here just for notifying DD colleagues. Should be removed later for MT9P012. PC Huang 20100903
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  // the above are for YUV sensor only
  case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
    OV5650CameraParaToSensor(pFeatureParaIn);
    break;
  case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
    OV5650SensorToCameraPara(pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV5650InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    OV5650DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
	CamPdnPinCtrl(OV5650SensorIdx,0);
	CamRstPinCtrl(OV5650SensorIdx,0);
	break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    pNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_GET_GAIN:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=OV5650ReadGain();
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(OV5650SensorIdx, pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 147;
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
    OV5650GetSensorGroupCount((kal_int32 *)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
    OV5650GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
    break;  
  case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
    OV5650GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
    OV5650SetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
    break;
  default:
    ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrorCode;
}

/*************************************************************************
* FUNCTION
*    OV5650SensorCtrl
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
static MM_ERROR_CODE_ENUM OV5650SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
  switch (ScenarioId)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    OV5650Preview(ScenarioId, pParaIn, pParaOut);
    break;
  case CAL_SCENARIO_VIDEO:
    OV5650Video(ScenarioId, pParaIn, pParaOut);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    OV5650Capture(ScenarioId, pParaIn, pParaOut);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV5650SensorClose
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
static MM_ERROR_CODE_ENUM OV5650SensorClose(void)
{
  CisModulePowerOn(OV5650SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV5650SensorFunc
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
MM_ERROR_CODE_ENUM OV5650SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV5650 =
  {
    OV5650SensorOpen,
    OV5650SensorFeatureCtrl,
    OV5650SensorCtrl,
    OV5650SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV5650;
}


/* AT COMMAND USE */
static kal_bool OV5650AtGetValue(char *Str, kal_uint32 *Data)
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

#ifdef __OV5650_DEBUG_TRACE__
kal_bool AtFuncTest(kal_char *Str)
{
      kal_uint32 Data[10];

    kal_int32 i;
      
    if (!OV5650AtGetValue(Str, Data))
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

