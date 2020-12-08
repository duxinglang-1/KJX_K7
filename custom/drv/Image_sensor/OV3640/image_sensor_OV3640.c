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
*   image_sensor_OV3640.c
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
#include "image_sensor_OV3640.h"

kal_bool OV3640_gVGAmode = KAL_TRUE, OV3640_MPEG4_encode_mode = KAL_FALSE;
#ifdef __MEDIA_VT__
/* under construction !*/
/* under construction !*/
#endif
static kal_uint8  g_iPV_PCLK_Divider = 1;
kal_uint16 OV3640_extra_exposure_lines = 0;
static kal_uint16 OV3640_g_iBackupExtraExp = 0;
static kal_uint16 OV3640_ExpLines = 0;
kal_uint16 OV3640_sensor_global_gain=BASEGAIN, OV3640_sensor_gain_base=0x0;
OV3640_OP_TYPE g_iOV3640_Mode = OV3640_MODE_NONE;
/* MAX/MIN Explosure Lines Used By AE Algorithm */
kal_uint16 OV3640_MAX_EXPOSURE_LINES = 1000;
kal_uint8  OV3640_MIN_EXPOSURE_LINES = 2;
static kal_uint16 g_iPreview_Column_Pixel = 0;

static kal_uint16 OV3640_dummy_pixels=0, OV3640_dummy_lines=0;

static kal_uint32 OV3640_fix_video_frame_rate=300;
kal_uint8 OV3640StartX=0, OV3640StartY=0;
kal_uint16 OV3640CapShutter=0;

IMAGE_SENSOR_INDEX_ENUM OV3640SensorIdx;
CAL_CAMERA_SOURCE_ENUM CameraSource;
sensor_data_struct *pNvramSensorData;
extern camcorder_info_struct OV3640_dsc_support_info;

static void OV3640PageWriteCmosSensor(kal_uint32 iAddr, kal_uint32 iPara)
{
  kal_uint16 iRegPage, iRegAddr;

  iRegPage = iAddr >> 8;
  iRegAddr = iAddr & 0x000000FF;

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, iRegPage);
  CamWriteCmosSensor(iRegAddr, iPara);
}

static kal_uint32 OV3640PageReadCmosSensor(const kal_uint32 iAddr)
{
  kal_uint16 iRegPage, iRegAddr;
  kal_uint8 iValue = 0x00;

  iRegPage = iAddr >> 8;
  iRegAddr = iAddr & 0x000000FF;

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, iRegPage);
  iValue = CamReadCmosSensor(iRegAddr);

  return iValue;
}

static void OV3640WriteShutter(kal_uint16 shutter)
{
  kal_uint8 iTemp;

  kal_uint16 extra_exposure_lines = 0;
  kal_uint16 Max_shutter = 0;

  if (OV3640_gVGAmode)
  {
    Max_shutter = OV3640_PV_PERIOD_LINE_NUMS + OV3640_dummy_lines;
  }
  else
  {
    Max_shutter = OV3640_FULL_PERIOD_LINE_NUMS +OV3640_dummy_lines;
  }

  if (shutter > Max_shutter)
  {
    OV3640_extra_exposure_lines = shutter - Max_shutter;
    shutter = Max_shutter;
  }
  else
  {
    OV3640_extra_exposure_lines = 0;
  }

    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
 
    iTemp = CamReadCmosSensor(0x04);
    CamWriteCmosSensor(0x04, ((iTemp & 0xFC) | (shutter & 0x3)));  // AEC[b1~b0]
    CamWriteCmosSensor(0x10, ((shutter & 0x3FC) >> 2));        // AEC[b9~b2]
    CamWriteCmosSensor(0x45, ((shutter & 0xFC00) >> 10));      // AEC[b10]/AEC[b15~b10]

  if ((OV3640_g_iBackupExtraExp == 0 && OV3640_extra_exposure_lines > 0)||
     g_iOV3640_Mode == OV3640_MODE_CAPTURE )
  {
    CamWriteCmosSensor(0x2D, OV3640_extra_exposure_lines & 0xFF);             // ADVFL(LSB of extra exposure lines)
      CamWriteCmosSensor(0x2E, (OV3640_extra_exposure_lines & 0xFF00) >> 8);    // ADVFH(MSB of extra exposure lines)
  }
  
  OV3640_g_iBackupExtraExp = OV3640_extra_exposure_lines;
}   /* write_OV3640_shutter */

static kal_uint16 OV3640Reg2Gain(const kal_uint8 iReg)
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

static kal_uint8 OV3640Gain2Reg(const kal_uint16 iGain)
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
*    OV3640SetDummy
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
static void OV3640SetDummy(const kal_uint16 iPixels, const kal_uint16 iLines)
{
  ASSERT(iPixels < 4096);
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x2A, (iPixels & 0x0F00) >> 4);
  CamWriteCmosSensor(0x2B, iPixels & 0x00FF);
  CamWriteCmosSensor(0x46, iLines & 0x00FF);
  CamWriteCmosSensor(0x47, iLines >> 8);
}

/*************************************************************************
* FUNCTION
*    OV3640InitialSetting
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
static void OV3640InitialSetting(void)
{
#ifdef OV3640_PROCESSING_RAW
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0x2C, 0xFF);
    CamWriteCmosSensor(0x2E, 0xDF);
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x3C, 0x32);
    //
    CamWriteCmosSensor(0x11, 0x00); // clk divider
    CamWriteCmosSensor(0x09, 0x02);
    CamWriteCmosSensor(0x04, 0x28);
    CamWriteCmosSensor(0x13, 0xE0); // AEC/AGC off
    CamWriteCmosSensor(0x14, 0x48);
    CamWriteCmosSensor(0x2C, 0x0C); // reserved
    CamWriteCmosSensor(0x33, 0x78); // reserved
    CamWriteCmosSensor(0x3A, 0x33); // reserved
    CamWriteCmosSensor(0x3B, 0xFB); // reserved
    CamWriteCmosSensor(0x3E, 0x00); // reserved
    CamWriteCmosSensor(0x43, 0x11); // reserved
    CamWriteCmosSensor(0x16, 0x10); // reserved
    //
    CamWriteCmosSensor(0x39, 0x02); // reserved
    //
    CamWriteCmosSensor(0x35, 0xDA); // reserved
    CamWriteCmosSensor(0x22, 0x1A); // reserved
    CamWriteCmosSensor(0x37, 0xC3); // reserved
    CamWriteCmosSensor(0x23, 0x00); // reserved
    CamWriteCmosSensor(0x34, 0xC0); // reserved
    CamWriteCmosSensor(0x36, 0x1A); // reserved
    CamWriteCmosSensor(0x06, 0x88); // reserved
    CamWriteCmosSensor(0x07, 0xC0); // reserved
    CamWriteCmosSensor(0x0D, 0x87);
    CamWriteCmosSensor(0x0E, 0x41); // reserved
    CamWriteCmosSensor(0x4C, 0x00); // reserved
    //
    CamWriteCmosSensor(0x4A, 0x81); // reserved
    CamWriteCmosSensor(0x21, 0x99); // reserved
    //
    CamWriteCmosSensor(0x24, 0x40);
    CamWriteCmosSensor(0x25, 0x38);
    CamWriteCmosSensor(0x26, 0x82);
    CamWriteCmosSensor(0x5C, 0x00);
    CamWriteCmosSensor(0x63, 0x00);
    //
    CamWriteCmosSensor(0x61, 0x70);
    CamWriteCmosSensor(0x62, 0x80);
    CamWriteCmosSensor(0x7C, 0x05); // reserved
    //
    CamWriteCmosSensor(0x20, 0x80); // reserved
    CamWriteCmosSensor(0x28, 0x30); // reserved
    CamWriteCmosSensor(0x6C, 0x00); // reserved
    CamWriteCmosSensor(0x6E, 0x00); // reserved
    CamWriteCmosSensor(0x70, 0x02); // reserved
    CamWriteCmosSensor(0x71, 0x94); // reserved
    CamWriteCmosSensor(0x73, 0xc1); // reserved
    //
    //CamWriteCmosSensor(0x3D, 0x34);
    CamWriteCmosSensor(0x5A, 0x57);
    CamWriteCmosSensor(0x4F, 0xBB);
    CamWriteCmosSensor(0x50, 0x9C);
    //
    //
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0xE5, 0x7F); // Bypass DSP
    CamWriteCmosSensor(0xF9, 0xC0); // Bypass DSP
    CamWriteCmosSensor(0x41, 0x24);
    CamWriteCmosSensor(0xE0, 0x14);
    CamWriteCmosSensor(0x76, 0xFF); // Bypass DSP
    CamWriteCmosSensor(0x33, 0xA0);
    CamWriteCmosSensor(0x42, 0x20);
    CamWriteCmosSensor(0x43, 0x18);
    CamWriteCmosSensor(0x4C, 0x00);
    //write_cmos_sensor(0x87, 0xD0);
    CamWriteCmosSensor(0x88, 0x3F);
    CamWriteCmosSensor(0xD7, 0x03);
    CamWriteCmosSensor(0xD9, 0x10);
    CamWriteCmosSensor(0xD3, 0x82);
    //
    CamWriteCmosSensor(0xC8, 0x08);
    CamWriteCmosSensor(0xC9, 0x80);
    //
    CamWriteCmosSensor(0x7C, 0x00);// SDE command
    CamWriteCmosSensor(0x7D, 0x00);
    CamWriteCmosSensor(0x7C, 0x03);
    CamWriteCmosSensor(0x7D, 0x48);
    CamWriteCmosSensor(0x7D, 0x48);
    CamWriteCmosSensor(0x7C, 0x08);
    CamWriteCmosSensor(0x7D, 0x20);
    CamWriteCmosSensor(0x7D, 0x10);
    CamWriteCmosSensor(0x7D, 0x0E);
    //
    CamWriteCmosSensor(0x92, 0x00);
    CamWriteCmosSensor(0x93, 0x06);
    CamWriteCmosSensor(0x93, 0xE4);
    CamWriteCmosSensor(0x93, 0x05);
    CamWriteCmosSensor(0x93, 0x05);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x04);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x93, 0x00);
    //
    CamWriteCmosSensor(0xC3, 0xED);
    CamWriteCmosSensor(0xA4, 0x00);
    CamWriteCmosSensor(0xA8, 0x00);
    CamWriteCmosSensor(0xC5, 0x11);
    CamWriteCmosSensor(0xC6, 0x51);
    CamWriteCmosSensor(0xBF, 0x80);
    CamWriteCmosSensor(0xC7, 0x10);
    CamWriteCmosSensor(0xB6, 0x66);
    CamWriteCmosSensor(0xB8, 0xA5);
    CamWriteCmosSensor(0xB7, 0x64);
    CamWriteCmosSensor(0xB9, 0x7C);
    CamWriteCmosSensor(0xB3, 0xAF);
    CamWriteCmosSensor(0xB4, 0x97);
    CamWriteCmosSensor(0xB5, 0xFF);
    CamWriteCmosSensor(0xB0, 0xC5);
    CamWriteCmosSensor(0xB1, 0x94);
    CamWriteCmosSensor(0xB2, 0x0F);
    CamWriteCmosSensor(0xB4, 0x5C);
    //
    CamWriteCmosSensor(0xC0, 0xC8);
    CamWriteCmosSensor(0xC1, 0x96);
    CamWriteCmosSensor(0x86, 0x1D);
    CamWriteCmosSensor(0x50, 0x00);
    CamWriteCmosSensor(0x51, 0x90);
    CamWriteCmosSensor(0x52, 0x18);
    CamWriteCmosSensor(0x53, 0x00);
    CamWriteCmosSensor(0x54, 0x00);
    CamWriteCmosSensor(0x55, 0x88);
    CamWriteCmosSensor(0x57, 0x00);
    CamWriteCmosSensor(0x5A, 0x90);
    CamWriteCmosSensor(0x5B, 0x18);
    CamWriteCmosSensor(0x5C, 0x05);
    //
    CamWriteCmosSensor(0xC3, 0xED);
    CamWriteCmosSensor(0x7F, 0x00);
    //
    CamWriteCmosSensor(0xDA, 0x04);
    //
    CamWriteCmosSensor(0xE5, 0x1F);
    CamWriteCmosSensor(0xE1, 0x67);
    CamWriteCmosSensor(0xE0, 0x00);
    CamWriteCmosSensor(0xDD, 0x7F);
    CamWriteCmosSensor(0x05, 0x00);

    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);

    CamWriteCmosSensor(0x2A, 0x30);
    CamWriteCmosSensor(0x2B, 0x00);

  CamWriteCmosSensor(0x11, 0x00);
  CamWriteCmosSensor(0x12, 0x40); // SVGA mode

    // setup windowing
    CamWriteCmosSensor(0x17, 0x11);
    CamWriteCmosSensor(0x18, 0x43);
    CamWriteCmosSensor(0x19, 0x00);
    CamWriteCmosSensor(0x1A, 0x4B);
    CamWriteCmosSensor(0x32, 0x09);

    CamWriteCmosSensor(0x03, 0x04);
    CamWriteCmosSensor(0x3D, 0x38);
    CamWriteCmosSensor(0x39, 0x12);
    CamWriteCmosSensor(0x35, 0xDA);
    CamWriteCmosSensor(0x22, 0x1A);
    CamWriteCmosSensor(0x37, 0xC3);
    CamWriteCmosSensor(0x23, 0x00);
    CamWriteCmosSensor(0x34, 0xA0);
    CamWriteCmosSensor(0x36, 0x1A);
    CamWriteCmosSensor(0x06, 0x88);
    CamWriteCmosSensor(0x07, 0xC0);
    CamWriteCmosSensor(0x0D, 0x87);
    CamWriteCmosSensor(0x0E, 0x41);
    CamWriteCmosSensor(0x4C, 0x00);
    //
    CamWriteCmosSensor(0x63, 0x20);// CIP RAW
    //
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0xC0, 0x66);
    CamWriteCmosSensor(0xC1, 0x4C);
    CamWriteCmosSensor(0x8C, 0x06);
    CamWriteCmosSensor(0x86, 0x35);
    CamWriteCmosSensor(0x50, 0x00);
    CamWriteCmosSensor(0x51, 0xCC);
    CamWriteCmosSensor(0x52, 0x99);
    CamWriteCmosSensor(0x53, 0x00);
    CamWriteCmosSensor(0x54, 0x00);
    CamWriteCmosSensor(0x55, 0x00);
    CamWriteCmosSensor(0x5A, 0xCC);
    CamWriteCmosSensor(0x5B, 0x99);

    CamWriteCmosSensor(0x5C, 0x00);
    CamWriteCmosSensor(0xD3, 0x82);
    //
    CamWriteCmosSensor(0xDA, 0x04);
    //
    CamWriteCmosSensor(0xE5, 0x1F);
    CamWriteCmosSensor(0xE1, 0x67);
    CamWriteCmosSensor(0xE0, 0x00);
    CamWriteCmosSensor(0xDD, 0x7F);
    CamWriteCmosSensor(0x05, 0x00);
    //
    CamWriteCmosSensor(0x87, OV3640_WPC_BPC_CTRL);// Pixel correction on
    CamWriteCmosSensor(0xC3, 0x81);
    CamWriteCmosSensor(0xC2, 0x01);// raw

    CamWriteCmosSensor(0x92, 0x71);
    CamWriteCmosSensor(0x93, 0x00);
    CamWriteCmosSensor(0x92, 0x00);
    CamWriteCmosSensor(0x93, 0x00);

    CamWriteCmosSensor(0x4F, 0xCA); // 50Hz banding
    CamWriteCmosSensor(0x50, 0xA8); // 60Hz banding


//    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);

#else
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0x2C, 0xFF);
    CamWriteCmosSensor(0x2E, 0xDF);
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0xE5, 0x7F); // Bypass DSP
    CamWriteCmosSensor(0xF9, 0xC0); // Bypass DSP
    CamWriteCmosSensor(0x05, 0x01); // Bypass DSP
    CamWriteCmosSensor(0x88, 0x00); // Bypass DSP
    CamWriteCmosSensor(0x89, 0x00); // Bypass DSP
    CamWriteCmosSensor(0x76, 0x00); // Bypass DSP
    CamWriteCmosSensor(0x85, 0x1F); // Bypass DSP
    CamWriteCmosSensor(0x7F, 0x0F); // Bypass DSP

    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x3C, 0x32);  // reserved

    CamWriteCmosSensor(0x2A, 0x30);
    CamWriteCmosSensor(0x2B, 0x00);

    CamWriteCmosSensor(0x11, 0x00); // clk divider
    CamWriteCmosSensor(0x09, 0x02);
    CamWriteCmosSensor(0x04, 0x28);
    CamWriteCmosSensor(0x13, 0xE0); // AEC/AGC off
    CamWriteCmosSensor(0x14, 0x48);
    CamWriteCmosSensor(0x2C, 0x0C); // reserved
    CamWriteCmosSensor(0x33, 0x78); // reserved
    CamWriteCmosSensor(0x3A, 0x33); // reserved
    CamWriteCmosSensor(0x3B, 0xFB); // reserved

    CamWriteCmosSensor(0x3E, 0x00); // reserved
    CamWriteCmosSensor(0x43, 0x11); // reserved
    CamWriteCmosSensor(0x16, 0x10); // reserved

    CamWriteCmosSensor(0x12, 0x40); // SVGA mode

    // setup windowing
    CamWriteCmosSensor(0x17, 0x11);
    CamWriteCmosSensor(0x18, 0x43);
    CamWriteCmosSensor(0x19, 0x00);
    CamWriteCmosSensor(0x1A, 0x4B);
    CamWriteCmosSensor(0x32, 0x09);
    CamWriteCmosSensor(0x4F, 0xCA); // 50Hz banding
    CamWriteCmosSensor(0x50, 0xA8); // 60Hz banding
    CamWriteCmosSensor(0x5A, 0x23); // reserved
    CamWriteCmosSensor(0x6D, 0x00); // reserved
    CamWriteCmosSensor(0x3D, 0x38); // reserved

    CamWriteCmosSensor(0x39, 0x12); // reserved
    CamWriteCmosSensor(0x35, 0xDA); // reserved
    CamWriteCmosSensor(0x22, 0x1A); // reserved
    CamWriteCmosSensor(0x37, 0xC3); // reserved
    CamWriteCmosSensor(0x23, 0x00); // reserved
    CamWriteCmosSensor(0x34, 0xC0); // reserved
    CamWriteCmosSensor(0x36, 0x1A); // reserved
    CamWriteCmosSensor(0x06, 0x88); // reserved
    CamWriteCmosSensor(0x07, 0xC0); // reserved
    CamWriteCmosSensor(0x0D, 0x87);
    CamWriteCmosSensor(0x0E, 0x41); // reserved
    CamWriteCmosSensor(0x4C, 0x00); // reserved

    CamWriteCmosSensor(0x4A, 0x81); // reserved
    CamWriteCmosSensor(0x21, 0x99); // reserved

    CamWriteCmosSensor(0x5C, 0x00); // reserved
    CamWriteCmosSensor(0x63, 0x00); // reserved
    CamWriteCmosSensor(0x61, 0x70); // histogram low
    CamWriteCmosSensor(0x62, 0x80); // histogram high

    CamWriteCmosSensor(0x7C, 0x05); // reserved
    CamWriteCmosSensor(0x20, 0x80); // reserved
    CamWriteCmosSensor(0x28, 0x30); // reserved
    CamWriteCmosSensor(0x6C, 0x00); // reserved
    CamWriteCmosSensor(0x6E, 0x00); // reserved
    CamWriteCmosSensor(0x70, 0x02); // reserved
    CamWriteCmosSensor(0x71, 0x94); // reserved
    CamWriteCmosSensor(0x73, 0xc1); // reserved

    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
    CamWriteCmosSensor(0x05, 0x01); // bypass DSP, sensor output directly

#endif
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x0F, 0x43); // reserved
    CamWriteCmosSensor(0x2D, 0x00); // VSYNC pulse width
    CamWriteCmosSensor(0x2E, 0x00); // VSYNC pulse width

    CamWriteCmosSensor(0x11,0x00); // clock divider
    CamWriteCmosSensor(0x12,0x40); // SVGA mode

    // setup windowing
    CamWriteCmosSensor(0x17, 0x10);
    CamWriteCmosSensor(0x18, 0x43);
    CamWriteCmosSensor(0x19, 0x00);
    CamWriteCmosSensor(0x1A, 0x4d);

    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x11, 0x00); // clock divider
    
//#if (defined(DRV_ISP_6238_SERIES))
//  CamWriteCmosSensor(0x3D, 0x38); // reserved
//#else
    CamWriteCmosSensor(0x3D, 0x38); // reserved
//#endif
    CamWriteCmosSensor(0x13, 0xC0); // turn off AGC/AEC
    CamWriteCmosSensor(0x00, 0x00); // global gain
    CamWriteCmosSensor(0x04, 0x28);
    CamWriteCmosSensor(0x10, 0x33); // exposure line
    CamWriteCmosSensor(0x45, 0x00); // AGC/AEC
} 

/*************************************************************************
* FUNCTION
*  OV3640_GetID
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
static void OV3640_GetID(kal_uint8 *pWriteID, kal_uint8 *pReadID)
{
  *pWriteID = OV3640_SW_SCCB_WRITE_ID;
  *pReadID = OV3640_SW_SCCB_READ_ID;
}

/*************************************************************************
* FUNCTION
*  OV3640_GetSize
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
static void OV3640_GetSize(kal_uint16 *pWidth, kal_uint16 *pHeight)
{
  *pWidth = OV3640_IMAGE_SENSOR_FULL_WIDTH;
  *pHeight = OV3640_IMAGE_SENSOR_FULL_HEIGHT;
}

/*************************************************************************
* FUNCTION
*  OV3640_get_period
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
static void OV3640_GetPeriod(kal_uint16 *pPixels, kal_uint16 *pLines)
{
#if (defined(DRV_ISP_6238_SERIES))
  *pPixels = OV3640_PV_PERIOD_PIXEL_NUMS + OV3640_dummy_pixels;
  *pLines =  OV3640_PV_PERIOD_LINE_NUMS + OV3640_dummy_lines;
#else
  *pPixels = OV3640_PV_PERIOD_PIXEL_NUMS;
  *pLines = OV3640_PV_PERIOD_LINE_NUMS;
#endif
}

static void OV3640SetSXVGA (void)
{
kal_uint8 iTemp=0;
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x12, 0x40);  // change to SVGA(800x600) mode

#ifdef OV3640_PROCESSING_RAW
  // setup sensor output ROI
  CamWriteCmosSensor(0x17, 0x11);
  CamWriteCmosSensor(0x18, 0x44);
  CamWriteCmosSensor(0x32, 0x09);
  CamWriteCmosSensor(0x19, 0x00);
  CamWriteCmosSensor(0x1A, 0x4D);
  CamWriteCmosSensor(0x03, 0x04);

  CamWriteCmosSensor(0x4F, 0xCA);  // 50Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x50, 0xA8);  // 60Hz banding AEC 8 LSBs

  CamWriteCmosSensor(0x6D, 0x00);  // reserved //????

//#if (defined(DRV_ISP_6238_SERIES))
//  CamWriteCmosSensor(0x3D, 0x30); //framrate=30
//#else
  CamWriteCmosSensor(0x3D, 0x38); // reserved
//#endif

  CamWriteCmosSensor(0x39, 0x12);  // PWCOM1, reserved
  CamWriteCmosSensor(0x35, 0xDA);  // reserved
  iTemp = CamReadCmosSensor(0x22); // ANCOM3
  CamWriteCmosSensor(0x22, iTemp | 0x10);
  CamWriteCmosSensor(0x37, 0xC3);  // reserved
  CamWriteCmosSensor(0x23, 0x00);  // reserved
  CamWriteCmosSensor(0x34, 0xA0);  // ARCOM2, reserved
  CamWriteCmosSensor(0x36, 0x1A);  // reserved
  CamWriteCmosSensor(0x06, 0x88);  // reserved
  CamWriteCmosSensor(0x07, 0xC0);  // reserved
  CamWriteCmosSensor(0x0D, 0x87);  // reserved
  CamWriteCmosSensor(0x0E, 0x41);  // reserved
  CamWriteCmosSensor(0x4C, 0x00);  // reserved

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
  CamWriteCmosSensor(0xC0, 0x66);
  CamWriteCmosSensor(0xC1, 0x4C);
  CamWriteCmosSensor(0x8C, 0x06);
  CamWriteCmosSensor(0x86, 0x35);
  CamWriteCmosSensor(0x50, 0x00);

  CamWriteCmosSensor(0x51, 0xCC);
  CamWriteCmosSensor(0x52, 0x99);

  CamWriteCmosSensor(0x53, 0x00);
  CamWriteCmosSensor(0x54, 0x00);
  CamWriteCmosSensor(0x55, 0x00);


  CamWriteCmosSensor(0x5A, 0xCC);
  CamWriteCmosSensor(0x5B, 0x99);
  CamWriteCmosSensor(0x5C, 0x00);
  CamWriteCmosSensor(0xD3, 0x82);

  CamWriteCmosSensor(0xE5, 0x1F);
  CamWriteCmosSensor(0xE1, 0x67);
  CamWriteCmosSensor(0xE0, 0x00);
  CamWriteCmosSensor(0xDD, 0x7F);
  CamWriteCmosSensor(0x05, 0x00);

  //write_cmos_sensor(0x87, 0xD0);
  CamWriteCmosSensor(0xC3, 0x81);
  CamWriteCmosSensor(0xC2, 0x01);
  CamWriteCmosSensor(0x92, 0x01);
  CamWriteCmosSensor(0x93, 0x00);
  CamWriteCmosSensor(0x92, 0x00);
  CamWriteCmosSensor(0x93, 0x00);
#else
  // setup sensor output ROI
  CamWriteCmosSensor(0x17, 0x10);
  CamWriteCmosSensor(0x18, 0x43);
  CamWriteCmosSensor(0x32, 0x36);
  CamWriteCmosSensor(0x19, 0x00);
  CamWriteCmosSensor(0x1A, 0x4D);
  CamWriteCmosSensor(0x03, 0x00);

  CamWriteCmosSensor(0x4F, 0xCA);  // 50Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x50, 0xA8);  // 60Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x5A, 0x23);  // 50/60Hz banding AEC Maximum steps
  CamWriteCmosSensor(0x6D, 0x00);  // reserved
  CamWriteCmosSensor(0x3D, 0x38);  // PLL/divider setting
  CamWriteCmosSensor(0x39, 0x12);  // PWCOM1, reserved
  CamWriteCmosSensor(0x35, 0xDA);  // reserved
  iTemp = CamReadCmosSensor(0x22); // ANCOM3
  CamWriteCmosSensor(0x22, iTemp | 0x10);
  CamWriteCmosSensor(0x37, 0xC3);  // reserved
  CamWriteCmosSensor(0x23, 0x00);  // reserved
  CamWriteCmosSensor(0x34, 0xC0);  // ARCOM2, reserved
  CamWriteCmosSensor(0x36, 0x1A);  // reserved
  CamWriteCmosSensor(0x06, 0x88);  // reserved
  CamWriteCmosSensor(0x07, 0xC0);  // reserved
  CamWriteCmosSensor(0x0D, 0x87);  // reserved
  CamWriteCmosSensor(0x0E, 0x41);  // reserved
  CamWriteCmosSensor(0x4C, 0x00);  // reserved
#endif
}

static void OV3640SetMirrorFlip(kal_uint8 image_mirror)
{
  kal_uint8 iTemp;
  
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  iTemp = CamReadCmosSensor(0x04) & 0x3F;//0x2F->0X3F
  switch (image_mirror)
  {
  case IMAGE_SENSOR_MIRROR_NORMAL:
    OV3640StartX = 4;
    OV3640StartY = 6;
    //iTemp |= 0x00; // do nothing 
    break;
  case IMAGE_SENSOR_MIRROR_H:
    OV3640StartX = 4;
    OV3640StartY = 6;
    iTemp |= 0x80; 
    break;
  case IMAGE_SENSOR_MIRROR_V:
    OV3640StartX = 4;
    OV3640StartY = 5;
    iTemp |= 0x40;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    OV3640StartX = 4;
    OV3640StartY = 5;
    iTemp |= 0xC0;
    break;
  default:
    ASSERT(0);
  }
  CamWriteCmosSensor(0x04, iTemp);
  //For image mirror
}
 
static void OV3640SetUXGA(void)
{
  kal_uint8 iTemp=0;
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x71,0x00);//freeze blc

#ifdef OV3640_PROCESSING_RAW
  /*Switch mode to 1610x1210*/
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG,0x01);
  CamWriteCmosSensor(0x12, 0x00);  // switch to UXGA(1600x1200) mode

  // setup sensor output ROI
  CamWriteCmosSensor(0x17, 0x11);
  CamWriteCmosSensor(0x18, 0x76);
  CamWriteCmosSensor(0x32, 0x24);
  CamWriteCmosSensor(0x19, 0x01);
  CamWriteCmosSensor(0x1A, 0x99);
  CamWriteCmosSensor(0x03, 0x0E);

  CamWriteCmosSensor(0x4F, 0xBB);  // 50Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x50, 0x9C);  // 60Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x5A, 0x57);  // 50/60Hz banding AEC Maximum steps
  CamWriteCmosSensor(0x6D, 0x80);  // reserved

  //    CamWriteCmosSensor(0x3D, 0x28); //capture frame rate 15fps
  CamWriteCmosSensor(0x3D, 0x34); //capture frame rate 15fps

  CamWriteCmosSensor(0x39, 0x02);  // PWCOM1, reserved
  CamWriteCmosSensor(0x35, 0x88);  // reserved
  iTemp = CamReadCmosSensor(0x22); // ANCOM3
  CamWriteCmosSensor(0x22, iTemp & 0xEF);

  CamWriteCmosSensor(0x37, 0x40);  // reserved
  CamWriteCmosSensor(0x23, 0x00);  // reserved
  CamWriteCmosSensor(0x34, 0xA0);  // ARCOM2, reserved
  CamWriteCmosSensor(0x36, 0x1A);  // reserved
  CamWriteCmosSensor(0x06, 0x02);  // reserved
  CamWriteCmosSensor(0x07, 0xC0);  // reserved
  CamWriteCmosSensor(0x0D, 0xB7);  // reserved
  CamWriteCmosSensor(0x0E, 0x01);  // reserved
  CamWriteCmosSensor(0x4C, 0x00);  // reserved

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x00);
  CamWriteCmosSensor(0xC0, 0xCA);
  CamWriteCmosSensor(0xC1, 0x98);
  CamWriteCmosSensor(0x8C, 0x02);
  CamWriteCmosSensor(0x86, 0x35);
  CamWriteCmosSensor(0x50, 0x00);

  CamWriteCmosSensor(0x51, 0x94);
  CamWriteCmosSensor(0x52, 0x30);

  CamWriteCmosSensor(0x53, 0x00);
  CamWriteCmosSensor(0x54, 0x00);
  CamWriteCmosSensor(0x55, 0x88);
  CamWriteCmosSensor(0x57, 0x00);

  CamWriteCmosSensor(0x5A, 0x94);
  CamWriteCmosSensor(0x5B, 0x30);
  CamWriteCmosSensor(0x5C, 0x05);
  CamWriteCmosSensor(0xD3, 0x82);

  CamWriteCmosSensor(0xE5, 0x1F);
  CamWriteCmosSensor(0xE1, 0x67);
  CamWriteCmosSensor(0xE0, 0x00);
  CamWriteCmosSensor(0xDD, 0x7F);
  CamWriteCmosSensor(0x05, 0x00);

  CamWriteCmosSensor(0x87, OV3640_WPC_BPC_CTRL);

  CamWriteCmosSensor(0xC3, 0x01);
  CamWriteCmosSensor(0xC2, 0x81);
  CamWriteCmosSensor(0x92, 0x01);
  CamWriteCmosSensor(0x93, 0x00);
  CamWriteCmosSensor(0x92, 0x00);
  CamWriteCmosSensor(0x93, 0x00);
#else
  /*Switch mode to 1610x1210*/
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG,0x01);
  CamWriteCmosSensor(0x12, 0x00);  // switch to UXGA(1600x1200) mode

  // setup sensor output ROI
  CamWriteCmosSensor(0x17, 0x11);
  CamWriteCmosSensor(0x18, 0x75);
  CamWriteCmosSensor(0x32, 0x3A);
  CamWriteCmosSensor(0x19, 0x01);
  CamWriteCmosSensor(0x1A, 0x98);
  CamWriteCmosSensor(0x03, 0x84);

  CamWriteCmosSensor(0x4F, 0xBB);  // 50Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x50, 0x9C);  // 60Hz banding AEC 8 LSBs
  CamWriteCmosSensor(0x5A, 0x57);  // 50/60Hz banding AEC Maximum steps
  CamWriteCmosSensor(0x6D, 0x80);  // reserved

  CamWriteCmosSensor(0x3D, 0x34);  // PLL/divider setting
  CamWriteCmosSensor(0x39, 0x02);  // PWCOM1, reserved
  CamWriteCmosSensor(0x35, 0x88);  // reserved
  iTemp = CamReadCmosSensor(0x22); // ANCOM3
  CamWriteCmosSensor(0x22, iTemp & 0xEF);

  CamWriteCmosSensor(0x37, 0x40);  // reserved
  CamWriteCmosSensor(0x23, 0x00);  // reserved
  CamWriteCmosSensor(0x34, 0xA0);  // ARCOM2, reserved
  CamWriteCmosSensor(0x36, 0x1A);  // reserved
  CamWriteCmosSensor(0x06, 0x02);  // reserved
  CamWriteCmosSensor(0x07, 0xC0);  // reserved
  CamWriteCmosSensor(0x0D, 0xB7);  // reserved
  CamWriteCmosSensor(0x0E, 0x01);  // reserved
  CamWriteCmosSensor(0x4C, 0x00);  // reserved
#endif
}

/*************************************************************************
* FUNCTION
*  OV3640SetShutter
*
* DESCRIPTION
*  This function set e-shutter of OV3640 to change exposure time.
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
static void OV3640SetShutter(kal_uint16 iShutter)
{
  OV3640_ExpLines = iShutter;
  
  OV3640WriteShutter(iShutter);
}

/*************************************************************************
* FUNCTION
*  OV3640SetGain
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
static kal_uint16 OV3640SetGain(kal_uint16 iGain)
{
  const kal_uint16 iBaseGain = OV3640Reg2Gain(pNvramSensorData->cct[OV3640_GLOBAL_GAIN_INDEX].para);

  const kal_uint16 iGain2Set = iGain * iBaseGain / BASEGAIN;
  kal_uint8 iReg = OV3640Gain2Reg(iGain2Set);

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x00, iReg);
  CamWriteCmosSensor(0x2D, OV3640_extra_exposure_lines & 0xFF);             // ADVFL(LSB of extra exposure lines)
  CamWriteCmosSensor(0x2E, (OV3640_extra_exposure_lines & 0xFF00) >> 8);    // ADVFH(MSB of extra exposure lines)
  
  return OV3640Reg2Gain(iReg) * BASEGAIN / iBaseGain;
}

static kal_uint16 OV3640ReadGain(void)
{  
  kal_uint8 iReg = 0;

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  iReg = CamReadCmosSensor(0x00);

  return OV3640Reg2Gain(iReg);
}

static void OV3640SetFlashlight (kal_bool enable)
{
  //flashlight_power_on(enable);
  FlashlightPowerOn(OV3640SensorIdx, enable);
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
static void OV3640CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;
  
  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    OV3640PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    OV3640PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=0; i<FACTORY_END_ADDR; i++)
  {
    OV3640PageWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr,pCameraPara->SENSOR.reg[i].para);
  }
}

// update camera_para from sensor register
static void OV3640SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;

  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_START_ADDR); i++)
  {
    pCameraPara->SENSOR.reg[i].para = OV3640PageReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    pCameraPara->SENSOR.reg[i].para = OV3640PageReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
}

//------------------------Engineer mode---------------------------------
extern int sprintf(char *buffer, const char *format, ... );

static void  OV3640GetSensorGroupCount(kal_int32* sensor_count_ptr)
{
  *sensor_count_ptr = OV3640_GROUP_TOTAL_NUMS;
}

static void OV3640GetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
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
static void OV3640GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
  kal_uint8 temp_reg=0x00;
  kal_uint16 temp_gain=0;

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG,0x01);
  switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:
          sprintf((char *) (info_ptr->ItemNamePtr), "SENSOR_BASEGAIN");
          
          temp_gain = OV3640Reg2Gain(pNvramSensorData->cct[SENSOR_BASEGAIN].para);
        
          info_ptr->ItemValue=(temp_gain*1000)/BASEGAIN;
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1*1000; //Min global gain = 1x base gain
          info_ptr->Max=16*1000;//Max global gain = 16x base gain
        break;
        
        case PRE_GAIN_R_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-R");
          temp_reg = pNvramSensorData->cct[PRE_GAIN_R_INDEX].para;
          temp_reg &= 0x0C;
          temp_reg >>= 2; 
          
          if(temp_reg==0)
            info_ptr->ItemValue=1000;
          else if(temp_reg==1)
            info_ptr->ItemValue=1250;
          else if(temp_reg==2)
            info_ptr->ItemValue=1500;
          else if(temp_reg==3)
            info_ptr->ItemValue=1750;
          
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000; //Min pre-gain
          info_ptr->Max=1875; //Max pre-gaim 
          break;
        case PRE_GAIN_B_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-B");          
          temp_reg = pNvramSensorData->cct[PRE_GAIN_B_INDEX].para;
          temp_reg &= 0x0C;
          temp_reg >>= 2; 
          
          if(temp_reg==0)
            info_ptr->ItemValue=1000;
          else if(temp_reg==1)
            info_ptr->ItemValue=1250;
          else if(temp_reg==2)
            info_ptr->ItemValue=1500;
          else if(temp_reg==3)
            info_ptr->ItemValue=1750;
          
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000; //Min pre-gain
          info_ptr->Max=1875; //Max pre-gaim 
          
        break;
        
      case PRE_GAIN_Gr_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
          temp_reg = pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].para;
          temp_reg &= 0x03;
                
          if(temp_reg==0)
            info_ptr->ItemValue=1000;
          else if(temp_reg==1)
            info_ptr->ItemValue=1250;
          else if(temp_reg==2)
            info_ptr->ItemValue=1500;
          else if(temp_reg==3)
            info_ptr->ItemValue=1750;
            
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000;
          info_ptr->Max=1875;  
          break;
      case PRE_GAIN_Gb_INDEX:
          sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gb");  
        
          temp_reg = pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para;
          temp_reg &= 0x03;
                
          if(temp_reg==0)
            info_ptr->ItemValue=1000;
          else if(temp_reg==1)
            info_ptr->ItemValue=1250;
          else if(temp_reg==2)
            info_ptr->ItemValue=1500;
          else if(temp_reg==3)
            info_ptr->ItemValue=1750;
            
          info_ptr->IsTrueFalse=KAL_FALSE;
          info_ptr->IsReadOnly=KAL_FALSE;
          info_ptr->IsNeedRestart=KAL_FALSE;
          info_ptr->Min=1000;
          info_ptr->Max=1875;
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


static kal_bool OV3640SetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
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
          temp_reg = OV3640Gain2Reg(temp_gain);        

          pNvramSensorData->cct[SENSOR_BASEGAIN].para = temp_reg;
          OV3640PageWriteCmosSensor(pNvramSensorData->cct[SENSOR_BASEGAIN].addr,temp_reg);
          break;
          
        case PRE_GAIN_R_INDEX:
          temp_reg = pNvramSensorData->cct[PRE_GAIN_R_INDEX].para;
          temp_reg &= ~0x0C;
          
          if(ItemValue>=1000 && ItemValue<=1125)
            temp_reg |= 0x00;
          else if(ItemValue>1125 && ItemValue<=1375)
            temp_reg |= 0x04;
          else if(ItemValue>1375 && ItemValue<=1625)
            temp_reg |= 0x08;
          else if(ItemValue>1625 && ItemValue<=1875)
            temp_reg |= 0x0C;
          else
              return KAL_FALSE;
              
          pNvramSensorData->cct[PRE_GAIN_R_INDEX].para = temp_reg;
          OV3640PageWriteCmosSensor(pNvramSensorData->cct[PRE_GAIN_R_INDEX].addr,temp_reg);
          break;
        case PRE_GAIN_B_INDEX:
          temp_reg = pNvramSensorData->cct[PRE_GAIN_B_INDEX].para;
          temp_reg &= ~0x0C;
          
          if(ItemValue>=1000 && ItemValue<=1125)
            temp_reg |= 0x00;
          else if(ItemValue>1125 && ItemValue<=1375)
            temp_reg |= 0x04;
          else if(ItemValue>1375 && ItemValue<=1625)
            temp_reg |= 0x08;
          else if(ItemValue>1625 && ItemValue<=1875)
            temp_reg |= 0x0C;
          else
              return KAL_FALSE;
              
          pNvramSensorData->cct[PRE_GAIN_B_INDEX].para = temp_reg;
          OV3640PageWriteCmosSensor(pNvramSensorData->cct[PRE_GAIN_B_INDEX].addr,temp_reg);
        break;
        
        case PRE_GAIN_Gr_INDEX:
          temp_reg = pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].para;          
          temp_reg &= ~0x03;
          
          if(ItemValue>=1000 && ItemValue<=1125)
            temp_reg |= 0x00;
          else if(ItemValue>1125 && ItemValue<=1375)
            temp_reg |= 0x01;
          else if(ItemValue>1375 && ItemValue<=1625)
            temp_reg |= 0x02;
          else if(ItemValue>1625 && ItemValue<=1875)
            temp_reg |= 0x03;
          else
              return KAL_FALSE;
        
          pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].para = temp_reg;
          OV3640PageWriteCmosSensor(pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].addr,temp_reg);
          break;
        case PRE_GAIN_Gb_INDEX:
          temp_reg = pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para;          
          temp_reg &= ~0x03;
          
          if(ItemValue>=1000 && ItemValue<=1125)
            temp_reg |= 0x00;
          else if(ItemValue>1125 && ItemValue<=1375)
            temp_reg |= 0x01;
          else if(ItemValue>1375 && ItemValue<=1625)
            temp_reg |= 0x02;
          else if(ItemValue>1625 && ItemValue<=1875)
            temp_reg |= 0x03;
          else
              return KAL_FALSE;
        
          pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para = temp_reg;
          OV3640PageWriteCmosSensor(pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].addr,temp_reg);
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
*    OV3640GetSensorInfo
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
static void OV3640GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
  pSensorInfo->SensorId = OV3640_SENSOR_ID;
  pSensorInfo->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  pSensorInfo->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
  pSensorInfo->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;    
  pSensorInfo->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  pSensorInfo->PixelClkInv = KAL_FALSE;
  pSensorInfo->PixelClkPolarity = POLARITY_LOW;
  pSensorInfo->HsyncPolarity = POLARITY_LOW;
  pSensorInfo->VsyncPolarity = POLARITY_HIGH;
  pSensorInfo->PreviewMclkFreq = 26000000;
  pSensorInfo->CaptureMclkFreq = 26000000;
  pSensorInfo->VideoMclkFreq = 26000000;
  pSensorInfo->PreviewWidth = OV3640_IMAGE_SENSOR_PV_WIDTH;
  pSensorInfo->PreviewHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT;
  pSensorInfo->FullWidth = OV3640_IMAGE_SENSOR_FULL_WIDTH;
  pSensorInfo->FullHeight = OV3640_IMAGE_SENSOR_FULL_HEIGHT;
  pSensorInfo->SensorAfSupport = KAL_FALSE;
  pSensorInfo->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    OV3640PowerOn
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
static kal_uint16 OV3640PowerOn(void)
{
  kal_uint16 SensorId = NULL_SENSOR_ID;
  kal_uint8 i = 0;
  
  CisModulePowerOn(OV3640SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV3640_HW_SCCB_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  
  kal_sleep_task(3); // To wait for Stable Power

  CamPdnPinCtrl(OV3640SensorIdx, 0);

  /* Reset the sensor */
  CamRstPinCtrl(OV3640SensorIdx, 1); //Sensor RESET pin high
  kal_sleep_task(4);

  CamRstPinCtrl(OV3640SensorIdx, 0); //Sensor RESET pin low
      
  kal_sleep_task(4);

 CamRstPinCtrl(OV3640SensorIdx, 1);  //Sensor RESET pin high
  kal_sleep_task(4);

  // Reset Sensor
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x12, 0x80);
  kal_sleep_task(2);// at least one frame delay time needed after SW reset
  /* Check ID */
  for (i=0;i<3;i++)
  {
    SensorId=(CamReadCmosSensor(0x0A) << 8) | CamReadCmosSensor(0x0B);

    if (SensorId==OV3640_SENSOR_ID)
    break;
  }
  return SensorId;
} /* OV3640PowerOn() */

/*************************************************************************
* FUNCTION
*    OV3640DetectSensorId
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
static kal_uint32 OV3640DetectSensorId(void)
{
  kal_uint16 SensorId;

  SensorId = OV3640PowerOn();

  CisModulePowerOn(OV3640SensorIdx, KAL_FALSE);

  return SensorId;
}

static MM_ERROR_CODE_ENUM OV3640SensorOpen(void)
{
  IspSetInterruptTriggerDelayLines(1);  // 0: VD INT, others: TG INT & start line
  
  if (OV3640_SENSOR_ID != OV3640PowerOn()) return MM_ERROR_SENSOR_READ_ID_FAIL;
  
  OV3640InitialSetting();
  //set sensor driving capacity 0x0==>1x  0x1==>3x  0x2==>2x  0x03==>4x 
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x09, 0x03); //PCLK Driving current

  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  OV3640_sensor_gain_base = CamReadCmosSensor(0x00);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640Preview
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
static void OV3640Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

    OV3640SetSXVGA();

  OV3640_gVGAmode = KAL_TRUE;
  
    OV3640SetMirrorFlip(pParaIn->ImageMirror);

    // compensate OV3640 ABLC for every frame
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x71, 0x94);  // reserved register

    OV3640_dummy_pixels = OV3640_PV_DUMMY_PIXELS;
    OV3640_dummy_lines = 0; 

    g_iOV3640_Mode = OV3640_MODE_PREVIEW;

    OV3640SetDummy(OV3640_dummy_pixels, OV3640_dummy_lines);
  g_iPV_PCLK_Divider = ((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG) >> 4) & 0x0000000F) + 1;
  g_iPreview_Column_Pixel = OV3640_PV_PERIOD_PIXEL_NUMS + OV3640_dummy_pixels;

    pParaOut->GrabStartX = OV3640StartX;
    pParaOut->GrabStartY = OV3640StartY;
    pParaOut->ExposureWindowWidth = OV3640_IMAGE_SENSOR_PV_WIDTH-OV3640StartX;
    pParaOut->ExposureWindowHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT-OV3640StartY;

    OV3640WriteShutter(OV3640_ExpLines);

}

static void OV3640GetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
  pPreviewInfo->pixels = OV3640_PV_PERIOD_PIXEL_NUMS;
  pPreviewInfo->lines = OV3640_IMAGE_SENSOR_PV_HEIGHT;
  pPreviewInfo->frame_lines = OV3640_PV_PERIOD_LINE_NUMS;
}

/*************************************************************************
* FUNCTION
*    OV3640Capture
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
static void OV3640Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    volatile kal_uint16 Shutter=OV3640_ExpLines;
    kal_uint16 iCapture_Column_Pixel = 0, iShutter = OV3640_ExpLines;
    kal_uint16 iDummyPixels = 0, iDummyLines = 0;
    kal_uint8 iTemp, iCP_PCLK_Div = 1;
    kal_uint16 iGrabWidth = 0, iGrabHeight = 0;

    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        Shutter=pParaIn->CaptureShutter;
    }

    if ((pParaIn->ImageTargetWidth<=OV3640_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=OV3640_IMAGE_SENSOR_PV_HEIGHT))
    {
    
            OV3640_dummy_pixels= 0;         
      OV3640_dummy_lines = 0;

      iGrabWidth = OV3640_IMAGE_SENSOR_PV_WIDTH - OV3640StartX;
      iGrabHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT - OV3640StartY;
      g_iOV3640_Mode = OV3640_MODE_CAPTURE;
            pParaOut->GrabStartX = 0;
            pParaOut->GrabStartY = 2;
            pParaOut->ExposureWindowWidth = OV3640_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT;

    iCapture_Column_Pixel = OV3640_PV_PERIOD_PIXEL_NUMS + OV3640_dummy_pixels;
        iCP_PCLK_Div = ((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG) >> 4) & 0x0000000F) + 1;
        iShutter = iShutter * g_iPreview_Column_Pixel / iCapture_Column_Pixel;
        iShutter = iShutter * g_iPV_PCLK_Divider / iCP_PCLK_Div;
            }   
    
    else  //>1.3M
    {

     OV3640SetUXGA();
   OV3640SetMirrorFlip(pParaIn->ImageMirror);
   
     #ifdef CAM_OTF_CAPTURE
  
    //OV3640SensorStatus.CapPclk=96;//000000Hz
    //OV3640SensorStatus.CapDummyLines = 0;
  
    if (100==pParaIn->ZoomFactor) /* 1x capture */
      {
      OV3640_dummy_pixels= 0;        
      OV3640_dummy_lines = 0;
      }
    else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
      {
        OV3640_dummy_pixels= 700;        
        OV3640_dummy_lines = 0;      
      }
    else if(pParaIn->ZoomFactor<=400)/* 2x~4x capture */
      {
        OV3640_dummy_pixels= 1200;        
        OV3640_dummy_lines = 0;      
      }
    else /* 4x~8x capture */
      {
        OV3640_dummy_pixels= 1600;        
        OV3640_dummy_lines = 0;      
      }
    
  
     #else
   OV3640_dummy_pixels= 0;        
   OV3640_dummy_lines = 0;
#endif

   
   iGrabWidth = OV3640_IMAGE_SENSOR_FULL_WIDTH;
   iGrabHeight = OV3640_IMAGE_SENSOR_FULL_HEIGHT;
   
   iCapture_Column_Pixel = OV3640_FULL_PERIOD_PIXEL_NUMS + OV3640_dummy_pixels;
   iCP_PCLK_Div = ((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG) >> 4) & 0x0000000F) + 1;
   iShutter = iShutter * g_iPreview_Column_Pixel / iCapture_Column_Pixel;
   iShutter = iShutter * 2 * g_iPV_PCLK_Divider / iCP_PCLK_Div;   // x2 for SVGA -> UXGA switch

  //  To force OV3640 re-calibrate ABLC by chaning global gain
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG,0x01);
  iTemp = CamReadCmosSensor(0x00);

   if (iTemp == 0xFF)        
    iTemp = iTemp - 0x1;    
   else                 
    iTemp = iTemp + 0x1;
   
    CamWriteCmosSensor(0x00,iTemp);
   
  /*if (bMetaMode == KAL_TRUE)  // CCT mode
  {
    iTemp = CamReadCmosSensor(0x00);
    kal_sleep_task(500);    // wait at least one frame
    if (iTemp == 0xFF)       
         iTemp = iTemp - 0x1;    
    else                
         iTemp = iTemp + 0x1;
    CamWriteCmosSensor(0x00, iTemp);
    kal_sleep_task(500);  // wait at least one frame
  }*/
  CamWriteCmosSensor(0x71,0x96);        //compensate OV3640 ABLC for every frame   

    pParaOut->GrabStartX = OV3640StartX;
    pParaOut->GrabStartY = OV3640StartY;
    pParaOut->ExposureWindowWidth = iGrabWidth;
    pParaOut->ExposureWindowHeight = iGrabHeight;

    OV3640WriteShutter(Shutter);
  OV3640CapShutter=Shutter;
  }
}

static void OV3640GetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    
    pCaptureInfo->default_pclk=26000000;

    pCaptureInfo->pixels = OV3640_FULL_PERIOD_PIXEL_NUMS + OV3640_dummy_pixels;
    pCaptureInfo->frame_lines = OV3640_FULL_PERIOD_LINE_NUMS+OV3640_dummy_lines;
    pCaptureInfo->lines = OV3640_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = OV3640CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    

}

static void OV3640Video(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

    OV3640SetSXVGA();

  OV3640_gVGAmode = KAL_TRUE;
  
    OV3640SetMirrorFlip(pParaIn->ImageMirror);

    // compensate OV3640 ABLC for every frame
    CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
    CamWriteCmosSensor(0x71, 0x94);  // reserved register

  OV3640_fix_video_frame_rate = pParaIn->MaxVideoFrameRate;
  OV3640_MAX_EXPOSURE_LINES = (kal_uint16)((26000000/OV3640_fix_video_frame_rate)/(OV3640_PV_PERIOD_PIXEL_NUMS+OV3640_dummy_pixels));      
  if((OV3640_MAX_EXPOSURE_LINES>OV3640_PV_PERIOD_LINE_NUMS)&&(OV3640_dummy_lines<(OV3640_MAX_EXPOSURE_LINES - OV3640_PV_PERIOD_LINE_NUMS)))    
    OV3640_dummy_lines = OV3640_MAX_EXPOSURE_LINES - OV3640_PV_PERIOD_LINE_NUMS;
      
  CamWriteCmosSensor(OV3640_PAGE_SETTING_REG, 0x01);
  CamWriteCmosSensor(0x46, OV3640_dummy_lines & 0x00FF);
  CamWriteCmosSensor(0x47, OV3640_dummy_lines >> 8);
 
    pParaOut->GrabStartX = OV3640StartX;
    pParaOut->GrabStartY = OV3640StartY;
    pParaOut->ExposureWindowWidth = OV3640_IMAGE_SENSOR_PV_WIDTH-OV3640StartX;
    pParaOut->ExposureWindowHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT-OV3640StartY;


}

static MM_ERROR_CODE_ENUM OV3640BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
*    OV3640StillCaptureSize
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
static MM_ERROR_CODE_ENUM OV3640StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
    pStillCaptureSize->ItemCount = 4;
    pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    pStillCaptureSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
    pStillCaptureSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640InitOperationPara
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
static void OV3640InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
  pInitOperPara->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  pInitOperPara->PreviewDelayFrame = 1; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  pInitOperPara->AeCalDelayFrame = 0; /* The frame of calculation default 0 */
  pInitOperPara->AeShutDelayFrame = 0; /* The frame of setting shutter default 0 for TG int */
  pInitOperPara->AeSensorGainDelayFrame = 1; /* The frame of setting sensor gain */
  pInitOperPara->AeIspGainDelayFrame = 2; /* The frame of setting gain */
  pInitOperPara->AeCalPeriod = 3; /* AE AWB calculation period */
#if(defined(LED_FLASHLIGHT_SUPPORT))
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
*    OV3640DscSupportInfo
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
static void OV3640DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
  kal_mem_cpy(pDscSupportInfo, &OV3640_dsc_support_info, sizeof(camcorder_info_struct));
}

static MM_ERROR_CODE_ENUM OV3640Sharpness(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
*    OV3640SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV3640SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  if (FeatureId >= CAL_FEATURE_WEBCAM_BEGIN && FeatureId <= CAL_FEATURE_WEBCAM_END)
  {
    return OV3640WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                   FeatureParaOutLen, pRealFeatureParaOutLen);
  }
  // for the features that not support in the sensor, then it is not necessary to implement it.
  switch (FeatureId)
  {
  case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
    OV3640SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_SET_GAIN:
    OV3640SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV3640GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
    FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
    *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV3640DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV3640SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
    break;
  case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
    OV3640GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
    OV3640GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
    OV3640SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
    break;
  case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
    OV3640GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                        FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
    ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_BINNING_INFO:
    ErrorCode=OV3640BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                     (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // customized by customer
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrorCode=OV3640StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
    break;
  // for YUV sensor sample code
  // the following are for YUV sensor only
  case CAL_FEATURE_CAMERA_SHARPNESS:
  // please refer the sample code of OV3640Sharpness();
    ErrorCode=OV3640Sharpness((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
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
    OV3640CameraParaToSensor(pFeatureParaIn);
    break;
  case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
    OV3640SensorToCameraPara(pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV3640InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    OV3640DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
	CamPdnPinCtrl(OV3640SensorIdx,0);
	CamRstPinCtrl(OV3640SensorIdx,0);
	break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    pNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_GET_GAIN:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=OV3640ReadGain();
    break;
  case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 120;
    ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
    OV3640GetSensorGroupCount((kal_int32 *)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
    OV3640GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
    break;  
  case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
    OV3640GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
    OV3640SetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
    break;
  default:
    ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrorCode;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorCtrl
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
static MM_ERROR_CODE_ENUM OV3640SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
  switch (ScenarioId)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    OV3640Preview(ScenarioId, pParaIn, pParaOut);
    break;
  case CAL_SCENARIO_VIDEO:
    OV3640Video(ScenarioId, pParaIn, pParaOut);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    OV3640Capture(ScenarioId, pParaIn, pParaOut);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorClose
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
static MM_ERROR_CODE_ENUM OV3640SensorClose(void)
{
  CisModulePowerOn(CameraSource, KAL_FALSE);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorFunc
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
MM_ERROR_CODE_ENUM OV3640SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV3640 =
  {
    OV3640SensorOpen,
    OV3640SensorFeatureCtrl,
    OV3640SensorCtrl,
    OV3640SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV3640;
}

