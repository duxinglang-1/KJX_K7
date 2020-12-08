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
 * Filename:
 * ---------
 *   image_sensor_SIM120C.c
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

static struct 
{
  kal_uint32 banding;
  kal_uint32 effect;
  kal_uint32 exposure;
  kal_uint32 wb;
  kal_uint8 mirror;
  kal_bool night_mode;
  kal_bool video_mode;
  kal_uint16 normal_fps;
  kal_uint16 night_fps;
  kal_uint8 cntr_b;
  kal_uint32 pv_pclk;
  kal_uint32 cap_pclk;
  kal_uint16 def_pv_dummy_pixel; /* default preview dummy pixel to avoid register value over flow */
  kal_uint16 pv_frame_height;
  kal_uint16 pv_line_length;
  kal_uint16 cap_frame_height;
  kal_uint16 cap_line_length;
  
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
  
  kal_bool BypassAe;
  kal_bool BypassAwb;
}SIM120CSensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    SIM120CHalfAdjust
*
* DESCRIPTION
*    This function Dividend / Divisor and use round-up.
*
* PARAMETERS
*    Dividend
*    Divisor
*
* RETURNS
*    [Dividend / Divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 SIM120CHalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    SIM120CSetBaseShutter   
*
* DESCRIPTION
*    This function set base shutter to the CMOS sensor, include group A and B
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
static void SIM120CSetBaseShutter(void)
{
  const kal_uint8 banding = SIM120CSensor.banding == CAM_BANDING_50HZ ? SIM120C_NUM_50HZ : SIM120C_NUM_60HZ;
  const kal_uint16 stst_s = SIM120CHalfAdjust(SIM120CSensor.cap_pclk / 2, SIM120CSensor.cap_line_length * banding * 2);
  const kal_uint16 stst_p = SIM120CHalfAdjust(SIM120CSensor.pv_pclk / 2, SIM120CSensor.pv_line_length * banding * 2);
  const kal_uint16 sf_p2s = SIM120CHalfAdjust(stst_s << 6, stst_p);
  const kal_uint16 sf_s2p = SIM120CHalfAdjust(stst_p << 6, stst_s);
  
  ASSERT(stst_p < 0x100 && stst_s < 0x100 && sf_p2s < 0x100 && sf_s2p < 0x100);
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x34, stst_p); /* preview base shutter */
  CamWriteCmosSensor(0x35, stst_s); /* capture base shutter */
  CamWriteCmosSensor(0x36, sf_p2s); /* capture shutter = preview shutter * sf_p2s / 64 */
  CamWriteCmosSensor(0x37, sf_s2p); /* preview shutter = capture shutter * sf_s2p / 64 */
}

/*************************************************************************
* FUNCTION
*    SIM120CSetPVDummy    
*
* DESCRIPTION
*    This function add dummy_pixel and dummy_line in preview state.
*
* PARAMETERS
*    dummy_pixel, MUST BE <= 0xFFF!!!
*    dummy_line, MUST BE <= 0xFFF!!!
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CSetPVDummy(kal_uint16 dummy_pixel, kal_uint16 dummy_line)
{
  const kal_uint16 frame_height = SIM120C_PV_PERIOD_LINE_NUMS + dummy_line;
  const kal_uint16 line_length = SIM120C_PV_PERIOD_PIXEL_NUMS + dummy_pixel;
  
  ASSERT(dummy_pixel <= 0xFFF && dummy_line <= 0xFFF);
  SIM120CSensor.pv_frame_height = frame_height;
  SIM120CSensor.pv_line_length = line_length;
  CamWriteCmosSensor(0x00, 0x00);
  CamWriteCmosSensor(0x24,((dummy_pixel >> 4)&0xF0)|((dummy_line >> 8)&0x0F));
  CamWriteCmosSensor(0x25, dummy_pixel);
  CamWriteCmosSensor(0x27, dummy_line);
  SIM120CSetBaseShutter();
}
/*************************************************************************
* FUNCTION
*    SIM120CSetCapDummy   
*
* DESCRIPTION
*    This function add dummy_pixel and dummy_line in capture state.
*
* PARAMETERS
*    dummy_pixel, MUST BE <= 0xFFF!!!
*    dummy_line, MUST BE <= 0xFFF!!!
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CSetCapDummy(kal_uint16 dummy_pixel, kal_uint16 dummy_line)
{
  const kal_uint16 frame_height = SIM120C_FULL_PERIOD_LINE_NUMS + dummy_line;
  const kal_uint16 line_length = SIM120C_FULL_PERIOD_PIXEL_NUMS + dummy_pixel;
  
  ASSERT(dummy_pixel <= 0xFFF && dummy_line <= 0xFFF);
  if (SIM120CSensor.cap_frame_height == frame_height && SIM120CSensor.cap_line_length == line_length) return;
  SIM120CSensor.cap_frame_height = frame_height;
  SIM120CSensor.cap_line_length = line_length;
  CamWriteCmosSensor(0x00, 0x00);
  CamWriteCmosSensor(0x20, ((dummy_pixel >> 4)&0xF0)|((dummy_line >> 8)&0x0F));
  CamWriteCmosSensor(0x21, dummy_pixel);
  CamWriteCmosSensor(0x23, dummy_line);
  SIM120CSetBaseShutter();
}

/*************************************************************************
* FUNCTION
*    SIM120CCalFps   
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
static void SIM120CCalFps(void)
{
  const kal_uint16 dummy_line = SIM120CSensor.pv_frame_height - SIM120C_PV_PERIOD_LINE_NUMS;
  const kal_uint8 banding = SIM120CSensor.banding == CAM_BANDING_50HZ ? SIM120C_NUM_50HZ : SIM120C_NUM_60HZ;
  const kal_uint16 pv_max_fps = SIM120CSensor.pv_pclk * SIM120C_FPS(1) / (2 * SIM120CSensor.pv_line_length * SIM120CSensor.pv_frame_height);
  kal_uint16 pv_min_fps = SIM120CSensor.night_mode ? SIM120CSensor.night_fps : SIM120CSensor.normal_fps;
  kal_uint16 line_length;
  
  if (pv_min_fps > pv_max_fps) pv_min_fps = pv_max_fps;
  if (SIM120CSensor.video_mode) /* fix frame rate when video mode */
  {
    line_length = SIM120CSensor.pv_pclk * SIM120C_FPS(1) / (2 * pv_min_fps * SIM120CSensor.pv_frame_height);
    SIM120CSetPVDummy(line_length - SIM120C_PV_PERIOD_PIXEL_NUMS, dummy_line);
  }
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x11, banding * 2 * SIM120C_FPS(1) / pv_min_fps);  
}


/*************************************************************************
* FUNCTION
*    SIM120CInitialSetting
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
static void SIM120CInitialSetting(void)
{ 

   kal_int16 dummy_pixel;
  //Sensor Control
  CamWriteCmosSensor(0x00, 0x00);
  SIM120CSensor.cntr_b = 0x10;
  CamWriteCmosSensor(0x04, SIM120CSensor.cntr_b);
  CamWriteCmosSensor(0x05, SIM120C_FULL_OUTPUT_MODE); /* SXGA Output */
  CamWriteCmosSensor(0x06, SIM120C_PV_OUTPUT_MODE); /* VGA Output, Sub-sample */
  
  // SNR Block [Vendor recommended value ##Don't change##]
  /* PCLK = MCLK * 2 */
  CamWriteCmosSensor(0x07, 0x88);
  CamWriteCmosSensor(0x08, 0xA2);
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  SIM120CSensor.cap_pclk = 52000000; /* PCLK_A: 52M */
  SIM120CSensor.pv_pclk = 26000000; /* PCLK_B: 26M */
  CamWriteCmosSensor(0x09, 0x11); /* group A */
  CamWriteCmosSensor(0x0A, 0x13); /* group B */
#else
  SIM120CSensor.cap_pclk = SIM120CSensor.pv_pclk = 48000000; /* PCLK_A, PCLK_B: 48M */
  CamWriteCmosSensor(0x09, 0x11);
  CamWriteCmosSensor(0x0A, 0x11);
#endif
  CamWriteCmosSensor(0x10, 0x04);
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x11, 0x26); //2009-10-23
  CamWriteCmosSensor(0x12, 0x11); //2009-10-23
#else
  CamWriteCmosSensor(0x12, 0x21);
#endif
  CamWriteCmosSensor(0x13, 0x18);
  CamWriteCmosSensor(0x16, 0xCE);
  CamWriteCmosSensor(0x32, 0x32);
  CamWriteCmosSensor(0x40, 0x0B);
  CamWriteCmosSensor(0x41, 0x00);
  CamWriteCmosSensor(0x42, 0x32);
  CamWriteCmosSensor(0x43, 0x40);
  CamWriteCmosSensor(0x57, 0x20);
  
  SIM120CSensor.def_pv_dummy_pixel = 0;
  /* min fps needed dummy pixel */
  dummy_pixel = SIM120CSensor.pv_pclk / (2 * 5 * (SIM120C_PV_PERIOD_LINE_NUMS + 0xFFF));
  dummy_pixel -= (SIM120C_PV_PERIOD_PIXEL_NUMS - 1);
  if (dummy_pixel > SIM120CSensor.def_pv_dummy_pixel) SIM120CSensor.def_pv_dummy_pixel = dummy_pixel;
  /* max base shutter needed dummy pixel */
  dummy_pixel = SIM120CSensor.pv_pclk / (2 * SIM120C_NUM_50HZ * 2 * 0xFF);
  dummy_pixel -= (SIM120C_PV_PERIOD_PIXEL_NUMS - 1);
  if (dummy_pixel > SIM120CSensor.def_pv_dummy_pixel) SIM120CSensor.def_pv_dummy_pixel = dummy_pixel;
  SIM120CSensor.pv_frame_height = SIM120CSensor.cap_frame_height = 0; /* force config dummy */
  SIM120CSensor.pv_line_length = SIM120C_PV_PERIOD_PIXEL_NUMS;
  SIM120CSensor.cap_line_length = SIM120C_FULL_PERIOD_PIXEL_NUMS;
  SIM120CSensor.banding = CAM_BANDING_50HZ;
  SIM120CSetPVDummy(SIM120CSensor.def_pv_dummy_pixel, 0);
  SIM120CSetCapDummy(0, 0);
  
  //AE Block
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x10, 0x00);
  CamWriteCmosSensor(0x11, 0x0A);
  CamWriteCmosSensor(0x12, 0x80);
  CamWriteCmosSensor(0x13, 0x80);
  CamWriteCmosSensor(0x14, 0x7D);
  CamWriteCmosSensor(0x15, 0x7F);//0x50
  CamWriteCmosSensor(0x16, 0x00);
  CamWriteCmosSensor(0x17, 0x00);
  CamWriteCmosSensor(0x19, 0xC8);
  CamWriteCmosSensor(0x1A, 0x04);
  CamWriteCmosSensor(0x1B, 0xCA);
  CamWriteCmosSensor(0x1C, 0x03);
  CamWriteCmosSensor(0x1E, 0x05); /* initial shutter */
  CamWriteCmosSensor(0x1F, 0x28); /* initial gain */
  CamWriteCmosSensor(0x21, 0x1D);
  
  CamWriteCmosSensor(0x24, 0x10);
  CamWriteCmosSensor(0x25, 0x05);
  CamWriteCmosSensor(0x40, 0x6A); //MAX Analog Gain   0x6C
  
  //AE Window
  CamWriteCmosSensor(0x60, 0xFF);
  CamWriteCmosSensor(0x61, 0xFF);
  CamWriteCmosSensor(0x62, 0xFF);
  CamWriteCmosSensor(0x63, 0xFF);
  CamWriteCmosSensor(0x64, 0xFF);
  CamWriteCmosSensor(0x65, 0xFF);
  CamWriteCmosSensor(0x66, 0x55);
  CamWriteCmosSensor(0x67, 0x01);
  CamWriteCmosSensor(0x68, 0x01);
  CamWriteCmosSensor(0x69, 0x01);
  CamWriteCmosSensor(0x6A, 0x01);
  CamWriteCmosSensor(0x6B, 0x00);
  CamWriteCmosSensor(0x6C, 0x06);

  //Anti saturation
  CamWriteCmosSensor(0x70, 0x04);
  CamWriteCmosSensor(0x71, 0x34);
  CamWriteCmosSensor(0x72, 0x0A);
  CamWriteCmosSensor(0x73, 0x22);
  CamWriteCmosSensor(0x74, 0xB7);
  CamWriteCmosSensor(0x75, 0x7F);
  CamWriteCmosSensor(0x76, 0x7F);
  CamWriteCmosSensor(0x77, 0xD0);
  CamWriteCmosSensor(0x78, 0xD8);
  CamWriteCmosSensor(0x79, 0x60);
  CamWriteCmosSensor(0x7A, 0xD0);
  CamWriteCmosSensor(0x7B, 0xD8);
  CamWriteCmosSensor(0x7C, 0x06);
  CamWriteCmosSensor(0x7D, 0xA0);
  CamWriteCmosSensor(0x7E, 0xA5);
  CamWriteCmosSensor(0x7F, 0x22);
  
  CamWriteCmosSensor(0x83, 0x68); //Y Gamma Target
  
  //G3 Gamma Enable
  CamWriteCmosSensor(0x90, 0x6F);
  CamWriteCmosSensor(0x92, 0x30);
  CamWriteCmosSensor(0x94, 0x10);
  CamWriteCmosSensor(0x96, 0x0E);
  CamWriteCmosSensor(0x97, 0x60);
  CamWriteCmosSensor(0x98, 0x10);
  CamWriteCmosSensor(0x9A, 0x30);
  CamWriteCmosSensor(0x9C, 0x10);
  
  //Wrapping
  CamWriteCmosSensor(0xA0, 0x80);
  CamWriteCmosSensor(0xA1, 0xA0);
  CamWriteCmosSensor(0xA2, 0x28);
  CamWriteCmosSensor(0xA3, 0xC2);
  
  //AWB Block
  CamWriteCmosSensor(0x00, 0x02);
  CamWriteCmosSensor(0x10, 0x13);
  CamWriteCmosSensor(0x11, 0xC0);
  CamWriteCmosSensor(0x12, 0x00);
  CamWriteCmosSensor(0x15, 0xFE);
  CamWriteCmosSensor(0x16, 0x8D);
  CamWriteCmosSensor(0x17, 0xEA);
  CamWriteCmosSensor(0x18, 0x85);
  CamWriteCmosSensor(0x19, 0xA0);
  CamWriteCmosSensor(0x1A, 0x67);
  CamWriteCmosSensor(0x1B, 0xA0);
  CamWriteCmosSensor(0x1C, 0x6A);
  CamWriteCmosSensor(0x1D, 0xB0);
  CamWriteCmosSensor(0x1E, 0x70);
  CamWriteCmosSensor(0x20, 0xFF);
  CamWriteCmosSensor(0x21, 0x90);
  CamWriteCmosSensor(0x22, 0xCD);
  CamWriteCmosSensor(0x23, 0x20);
  CamWriteCmosSensor(0x25, 0x20);
  CamWriteCmosSensor(0x26, 0x05);
  CamWriteCmosSensor(0x27, 0x05);
  CamWriteCmosSensor(0x28, 0xD0);
  CamWriteCmosSensor(0x29, 0xC5); //Fix R Gain @ Very Bright condition
  CamWriteCmosSensor(0x2A, 0x90); //Fix B Gain @ Very Bright condition 0x99
  CamWriteCmosSensor(0x41, 0x02);
  CamWriteCmosSensor(0x44, 0x13);
  CamWriteCmosSensor(0x45, 0x6A);
  CamWriteCmosSensor(0x46, 0x82);
  
  //RGB to YCbCr (CSC) no used
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
  CamWriteCmosSensor(0x63, 0xAD);
  CamWriteCmosSensor(0x64, 0xD0);
  CamWriteCmosSensor(0x65, 0xAD);
  CamWriteCmosSensor(0x66, 0xD0);
  CamWriteCmosSensor(0x67, 0xBA); //0xd2
  CamWriteCmosSensor(0x68, 0xA0); //0x9e
  CamWriteCmosSensor(0x69, 0xBA); //0xd2
  CamWriteCmosSensor(0x6A, 0xA0); //0x9e 
  
  //IDP 1
  //Output Signal Control
  CamWriteCmosSensor(0x00, 0x03);
  CamWriteCmosSensor(0x11, 0x1D);
  CamWriteCmosSensor(0x12, 0x1D);
  CamWriteCmosSensor(0x13, 0xD1); //Hue on
  CamWriteCmosSensor(0x14, 0xF9);
  
  //DPC
  CamWriteCmosSensor(0x16, 0xA1);
  CamWriteCmosSensor(0x18, 0x2C);
  CamWriteCmosSensor(0x19, 0x08);
  
  //Gamma - R
  CamWriteCmosSensor(0x30, 0x00);
  CamWriteCmosSensor(0x31, 0x04);
  CamWriteCmosSensor(0x32, 0x0E);
  CamWriteCmosSensor(0x33, 0x25);
  CamWriteCmosSensor(0x34, 0x4D);
  CamWriteCmosSensor(0x35, 0x6C);
  CamWriteCmosSensor(0x36, 0x83);
  CamWriteCmosSensor(0x37, 0x95);
  CamWriteCmosSensor(0x38, 0xA3);
  CamWriteCmosSensor(0x39, 0xAF);
  CamWriteCmosSensor(0x3A, 0xBA);
  CamWriteCmosSensor(0x3B, 0xCE);
  CamWriteCmosSensor(0x3C, 0xE0);
  CamWriteCmosSensor(0x3D, 0xF0);
  CamWriteCmosSensor(0x3E, 0xF7);
  CamWriteCmosSensor(0x3F, 0xFE);
  
  //Gamma - G
  CamWriteCmosSensor(0x40, 0x00);
  CamWriteCmosSensor(0x41, 0x04);
  CamWriteCmosSensor(0x42, 0x0E);
  CamWriteCmosSensor(0x43, 0x25);
  CamWriteCmosSensor(0x44, 0x4D);
  CamWriteCmosSensor(0x45, 0x6C);
  CamWriteCmosSensor(0x46, 0x83);
  CamWriteCmosSensor(0x47, 0x95);
  CamWriteCmosSensor(0x48, 0xA3);
  CamWriteCmosSensor(0x49, 0xAF);
  CamWriteCmosSensor(0x4A, 0xBA);
  CamWriteCmosSensor(0x4B, 0xCE);
  CamWriteCmosSensor(0x4C, 0xE0);
  CamWriteCmosSensor(0x4D, 0xF0);
  CamWriteCmosSensor(0x4E, 0xF7);
  CamWriteCmosSensor(0x4F, 0xFE);
  
  //Gamma - B
  CamWriteCmosSensor(0x50, 0x00);
  CamWriteCmosSensor(0x51, 0x04);
  CamWriteCmosSensor(0x52, 0x0E);
  CamWriteCmosSensor(0x53, 0x25);
  CamWriteCmosSensor(0x54, 0x4D);
  CamWriteCmosSensor(0x55, 0x6C);
  CamWriteCmosSensor(0x56, 0x83);
  CamWriteCmosSensor(0x57, 0x95);
  CamWriteCmosSensor(0x58, 0xA3);
  CamWriteCmosSensor(0x59, 0xAF);
  CamWriteCmosSensor(0x5A, 0xBA);
  CamWriteCmosSensor(0x5B, 0xCE);
  CamWriteCmosSensor(0x5C, 0xE0);
  CamWriteCmosSensor(0x5D, 0xF0);
  CamWriteCmosSensor(0x5E, 0xF7);
  CamWriteCmosSensor(0x5F, 0xFE);
  
  //CMA A
  CamWriteCmosSensor(0x60, 0xAF);
  CamWriteCmosSensor(0x61, 0x78); //0x77
  CamWriteCmosSensor(0x62, 0xC4); //0xc5
  CamWriteCmosSensor(0x63, 0x04); //0x05
  CamWriteCmosSensor(0x64, 0xE7);
  CamWriteCmosSensor(0x65, 0x75);
  CamWriteCmosSensor(0x66, 0xE4);
  CamWriteCmosSensor(0x67, 0xFB); //0xfd
  CamWriteCmosSensor(0x68, 0xBD); //0xbe
  CamWriteCmosSensor(0x69, 0x88); //0x87
  
  //CMA B
  CamWriteCmosSensor(0x6A, 0x2F);
  CamWriteCmosSensor(0x6B, 0x73);
  CamWriteCmosSensor(0x6C, 0xC1);
  CamWriteCmosSensor(0x6D, 0x0C);
  CamWriteCmosSensor(0x6E, 0xE0);
  CamWriteCmosSensor(0x6F, 0x74);
  CamWriteCmosSensor(0x70, 0xEC);
  CamWriteCmosSensor(0x71, 0xF3);
  CamWriteCmosSensor(0x72, 0xCB);
  CamWriteCmosSensor(0x73, 0x82);
  
  //CMA C
  CamWriteCmosSensor(0x74, 0x2F);
  CamWriteCmosSensor(0x75, 0x66);
  CamWriteCmosSensor(0x76, 0xD4);
  CamWriteCmosSensor(0x77, 0x06);
  CamWriteCmosSensor(0x78, 0xEA);
  CamWriteCmosSensor(0x79, 0x62);
  CamWriteCmosSensor(0x7A, 0xF4);
  CamWriteCmosSensor(0x7B, 0xF2);
  CamWriteCmosSensor(0x7C, 0x99);
  CamWriteCmosSensor(0x7D, 0xB5);
  
  //Window Size
  CamWriteCmosSensor(0x94, 0x05);
  CamWriteCmosSensor(0x95, 0x00);
  CamWriteCmosSensor(0x96, 0x04);
  CamWriteCmosSensor(0x97, 0x00);
  
  //Contrast & Color Saturation
  CamWriteCmosSensor(0x80, 0x12);
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x81, 0x18);
  CamWriteCmosSensor(0x82, 0x18);
#else
  CamWriteCmosSensor(0x81, 0x15);
  CamWriteCmosSensor(0x82, 0x15);
#endif
  CamWriteCmosSensor(0x83, 0x00);
  
  //Color suppress
  CamWriteCmosSensor(0x8A, 0x2C);
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x8B, 0x33);
#else
  CamWriteCmosSensor(0x8B, 0x93); //0x2D
#endif
  //Shading Center
  CamWriteCmosSensor(0xA0, 0xA9);
  CamWriteCmosSensor(0xA1, 0x82);
  
  //Shading Offset
  CamWriteCmosSensor(0xA2, 0x00);
  CamWriteCmosSensor(0xA3, 0x00);
  CamWriteCmosSensor(0xA4, 0x00);
  CamWriteCmosSensor(0xA5, 0x00);
  
  //Shading R Pixel Horizontal Vertical Gain
  CamWriteCmosSensor(0xA6, 0xFF); //0xf6
  CamWriteCmosSensor(0xA7, 0xCE);
  CamWriteCmosSensor(0xA8, 0xFD); //0xe6
  CamWriteCmosSensor(0xA9, 0xA0); //0xea
  
  //Shading Gr Pixel Horizontal Vertical Gain
  CamWriteCmosSensor(0xAA, 0xD8);
  CamWriteCmosSensor(0xAB, 0x90); //0x80
  CamWriteCmosSensor(0xAC, 0xF0); //0xd0
  CamWriteCmosSensor(0xAD, 0x70);
  
  //Shading Gb Pixel Horizontal, Vertical Gain
  CamWriteCmosSensor(0xAE, 0xD8);
  CamWriteCmosSensor(0xAF, 0x90); //0x80
  CamWriteCmosSensor(0xB0, 0xF0); //0xd0
  CamWriteCmosSensor(0xB1, 0x70);
  
  //Shading B Pixel Horizontal, Vertical Gain
  CamWriteCmosSensor(0xB2, 0xF0);
  CamWriteCmosSensor(0xB3, 0xA2);
  CamWriteCmosSensor(0xB4, 0xFD); //0xd6
  CamWriteCmosSensor(0xB5, 0xA0); //0xaa
  
  //Shading Start Gain
  CamWriteCmosSensor(0xB6, 0x88);
  CamWriteCmosSensor(0xB7, 0x90);
  CamWriteCmosSensor(0xB8, 0x90);
  CamWriteCmosSensor(0xB9, 0x90);
  
  //R Shading Position Gain
  CamWriteCmosSensor(0xBA, 0x66); //0x55
  CamWriteCmosSensor(0xBB, 0xBC); //0xab
  CamWriteCmosSensor(0xBC, 0x9B); //0x8a
  CamWriteCmosSensor(0xBD, 0xFF); //0xfe
  CamWriteCmosSensor(0xBE, 0xED); //0xdc
  
  //Gr Shading Position Gain
  CamWriteCmosSensor(0xBF, 0x76); //0x65
  CamWriteCmosSensor(0xC0, 0x89); //0x78
  CamWriteCmosSensor(0xC1, 0xAB); //0x9a
  CamWriteCmosSensor(0xC2, 0xCB); //0xba
  CamWriteCmosSensor(0xC3, 0xA9); //0x98
  
  //Gb Shading Position Gain
  CamWriteCmosSensor(0xC4, 0x76); //0x65
  CamWriteCmosSensor(0xC5, 0x89); //0x78
  CamWriteCmosSensor(0xC6, 0xAB); //0x9a
  CamWriteCmosSensor(0xC7, 0xCB); //0xba
  CamWriteCmosSensor(0xC8, 0xA9); //0x98
  
  //B  Shading Position Gain
  CamWriteCmosSensor(0xC9, 0x76); //0x65
  CamWriteCmosSensor(0xCA, 0x87); //0x76
  CamWriteCmosSensor(0xCB, 0x9A); //0x89
  CamWriteCmosSensor(0xCC, 0xBA); //0xa9
  CamWriteCmosSensor(0xCD, 0x87); //0x76
  
  //Shading Dark Control
  CamWriteCmosSensor(0xCE, 0x00);
  CamWriteCmosSensor(0xCF, 0x42);
  CamWriteCmosSensor(0xD0, 0x08);
  CamWriteCmosSensor(0xD1, 0x00);
  
  //Hue control
  CamWriteCmosSensor(0xE0, 0x3F);
  CamWriteCmosSensor(0xE1, 0x3F);
  CamWriteCmosSensor(0xE2, 0x85);
  CamWriteCmosSensor(0xE3, 0x05);
  
  //IDP 2
  //Low Pass Filter
  CamWriteCmosSensor(0x00, 0x04);
  CamWriteCmosSensor(0x1C, 0xE0);
  CamWriteCmosSensor(0x1E, 0x60);
  CamWriteCmosSensor(0x1F, 0x06);
  CamWriteCmosSensor(0x20, 0xFD); 
  CamWriteCmosSensor(0x21, 0x10);
  CamWriteCmosSensor(0x22, 0x02);
  CamWriteCmosSensor(0x23, 0x00);
  CamWriteCmosSensor(0x24, 0x06);
  CamWriteCmosSensor(0x25, 0x02);
  CamWriteCmosSensor(0x27, 0x08);
  CamWriteCmosSensor(0x28, 0x34);
  CamWriteCmosSensor(0x2A, 0xE1);
  CamWriteCmosSensor(0x2B, 0x02);
  CamWriteCmosSensor(0x2C, 0x02);
  
  //Interploation
  CamWriteCmosSensor(0x10, 0x49);
  CamWriteCmosSensor(0x11, 0x0C);
  
  //Sigma Filter
  CamWriteCmosSensor(0x30, 0x00);
  CamWriteCmosSensor(0x31, 0x22);
  CamWriteCmosSensor(0x32, 0x5D);
  CamWriteCmosSensor(0x33, 0x14);
  CamWriteCmosSensor(0x34, 0x05);
  CamWriteCmosSensor(0x35, 0x28);
  CamWriteCmosSensor(0x36, 0x1F);
  CamWriteCmosSensor(0x37, 0x04);
  CamWriteCmosSensor(0x38, 0x04);
  CamWriteCmosSensor(0x39, 0x34);
  CamWriteCmosSensor(0x3B, 0x1F);
  CamWriteCmosSensor(0x3C, 0x08);
  CamWriteCmosSensor(0x3E, 0x80);
  CamWriteCmosSensor(0x41, 0x0F);
  CamWriteCmosSensor(0x43, 0x00);
  CamWriteCmosSensor(0x44, 0x34);
  CamWriteCmosSensor(0x45, 0x12);
  CamWriteCmosSensor(0x46, 0x10);
  CamWriteCmosSensor(0x53, 0x10);
  
  //C filter10
  CamWriteCmosSensor(0x67, 0x20);
  CamWriteCmosSensor(0x68, 0x10);
  CamWriteCmosSensor(0x69, 0x0F);
  CamWriteCmosSensor(0x6A, 0x30);
  
  //Edge Control
  CamWriteCmosSensor(0x70, 0xD2);
  CamWriteCmosSensor(0x71, 0x11);
  CamWriteCmosSensor(0x72, 0x10);
  CamWriteCmosSensor(0x73, 0x04);
  CamWriteCmosSensor(0x74, 0x34); 
  CamWriteCmosSensor(0x75, 0xFF);
  CamWriteCmosSensor(0x76, 0x20);
  CamWriteCmosSensor(0x77, 0x04);
  CamWriteCmosSensor(0x78, 0x34);
  CamWriteCmosSensor(0x79, 0xFF);
  CamWriteCmosSensor(0x7A, 0x20);
  CamWriteCmosSensor(0x7D, 0x34);
  CamWriteCmosSensor(0x7E, 0x30);
  
  //CSC 
  CamWriteCmosSensor(0x80, 0x33);
  CamWriteCmosSensor(0x81, 0x21);
  CamWriteCmosSensor(0x82, 0xE5);
  CamWriteCmosSensor(0x83, 0xFA);
  CamWriteCmosSensor(0x84, 0x13);
  CamWriteCmosSensor(0x85, 0x26);
  CamWriteCmosSensor(0x86, 0x07);
  CamWriteCmosSensor(0x87, 0xF5);
  CamWriteCmosSensor(0x88, 0xEA);
  CamWriteCmosSensor(0x89, 0x21);
  CamWriteCmosSensor(0x8A, 0x00);
  
  //ADGain
  CamWriteCmosSensor(0x8B, 0xE0); //Oudoor mode enable
  CamWriteCmosSensor(0x8C, 0x0C);
  CamWriteCmosSensor(0x8D, 0x0E);
  CamWriteCmosSensor(0x8E, 0x42);
  CamWriteCmosSensor(0x8F, 0x42);
  
  //ADG Y Point
  CamWriteCmosSensor(0x90, 0x10);
  CamWriteCmosSensor(0x91, 0x22);
  CamWriteCmosSensor(0x92, 0x36);
  CamWriteCmosSensor(0x93, 0x49);
  CamWriteCmosSensor(0x94, 0x5D);
  CamWriteCmosSensor(0x95, 0x70);
  CamWriteCmosSensor(0x96, 0x82);
  CamWriteCmosSensor(0x97, 0x94);
  CamWriteCmosSensor(0x98, 0xA5);
  CamWriteCmosSensor(0x99, 0xB5);
  CamWriteCmosSensor(0x9A, 0xC3);
  CamWriteCmosSensor(0x9B, 0xD1);
  CamWriteCmosSensor(0x9C, 0xDE);
  CamWriteCmosSensor(0x9D, 0xEA);
  CamWriteCmosSensor(0x9E, 0xF5);
  CamWriteCmosSensor(0x9F, 0xFF);
  
  //Dark Gamma
  CamWriteCmosSensor(0xA0, 0x00);
  CamWriteCmosSensor(0xA1, 0x05);
  CamWriteCmosSensor(0xA2, 0x0E);
  CamWriteCmosSensor(0xA3, 0x1D);
  CamWriteCmosSensor(0xA4, 0x38);
  CamWriteCmosSensor(0xA5, 0x53);
  CamWriteCmosSensor(0xA6, 0x69);
  CamWriteCmosSensor(0xA7, 0x7C);
  CamWriteCmosSensor(0xA8, 0x8C);
  CamWriteCmosSensor(0xA9, 0x9B);
  CamWriteCmosSensor(0xAA, 0xAA);
  CamWriteCmosSensor(0xAB, 0xC2);
  CamWriteCmosSensor(0xAC, 0xD7);
  CamWriteCmosSensor(0xAD, 0xEB);
  CamWriteCmosSensor(0xAE, 0xF5);
  CamWriteCmosSensor(0xAF, 0xFF);
  
  //G-Edge Control
  CamWriteCmosSensor(0xB0, 0x60);
  CamWriteCmosSensor(0xB1, 0x10);
  CamWriteCmosSensor(0xB2, 0x10);
  CamWriteCmosSensor(0xB3, 0x05);
  CamWriteCmosSensor(0xB4, 0x05);
  CamWriteCmosSensor(0xB5, 0x13);
  CamWriteCmosSensor(0xB6, 0x05);
  CamWriteCmosSensor(0xB8, 0x10);
  CamWriteCmosSensor(0xB9, 0x10);
  CamWriteCmosSensor(0xBA, 0x34);
  CamWriteCmosSensor(0xBB, 0x40);
  CamWriteCmosSensor(0xBC, 0x00);
  CamWriteCmosSensor(0xBD, 0x00);
  
  //Y Gamma Control
  CamWriteCmosSensor(0xC7, 0xC0);
  CamWriteCmosSensor(0xC8, 0x00);
  CamWriteCmosSensor(0xC9, 0x04);
  CamWriteCmosSensor(0xCA, 0x00);
  CamWriteCmosSensor(0xCB, 0x36);
  CamWriteCmosSensor(0xCC, 0x0C);
  CamWriteCmosSensor(0xCD, 0x0E);
  CamWriteCmosSensor(0xD0, 0x00);
  CamWriteCmosSensor(0xD1, 0x04);
  CamWriteCmosSensor(0xD2, 0x08);
  CamWriteCmosSensor(0xD3, 0x10);
  CamWriteCmosSensor(0xD4, 0x20);
  CamWriteCmosSensor(0xD5, 0x35);
  CamWriteCmosSensor(0xD6, 0x4E);
  CamWriteCmosSensor(0xD7, 0x62);
  CamWriteCmosSensor(0xD8, 0x76);
  CamWriteCmosSensor(0xD9, 0x85);
  CamWriteCmosSensor(0xDA, 0x95);
  CamWriteCmosSensor(0xDB, 0xB2);
  CamWriteCmosSensor(0xDC, 0xCA);
  CamWriteCmosSensor(0xDD, 0xE3);
  CamWriteCmosSensor(0xDE, 0xF1);
  CamWriteCmosSensor(0xDF, 0xFF);
  
  //Memory Speed Control Addr : D0 ~ D5 => EA ~ EF
  CamWriteCmosSensor(0xEA, 0x15);
  CamWriteCmosSensor(0xEB, 0x02);
  CamWriteCmosSensor(0xEC, 0x04);
  CamWriteCmosSensor(0xED, 0x15);
  CamWriteCmosSensor(0xEE, 0x02);
  CamWriteCmosSensor(0xEF, 0x04);
  
  // default setting
  
  SIM120CSensor.video_mode = KAL_FALSE;
  SIM120CSensor.night_mode = KAL_FALSE;
  SIM120CSensor.normal_fps = SIM120C_FPS(10);
  SIM120CSensor.night_fps = SIM120C_FPS(5);
  
  //Sensor On
  CamWriteCmosSensor(0x00, 0x00);
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x03, 0x85);
#else
  CamWriteCmosSensor(0x03, 0x55);
#endif
  
  //AE On
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x10, 0xC4);
  
  //AWB On
  CamWriteCmosSensor(0x00, 0x02);
  CamWriteCmosSensor(0x10, 0xC3);

}                                  

/*************************************************************************
* FUNCTION
*    SIM120CSetHVMirror
*
* DESCRIPTION
*    This function set sensor Mirror
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CSetHVMirror(kal_uint8 Mirror)
{
    #ifdef SIM120C_DEBUG
    	  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
    #endif 

	  SIM120CSensor.mirror = Mirror;
	  SIM120CSensor.cntr_b &= 0xFC;
	  switch (SIM120CSensor.mirror)
	  {
	  case IMAGE_SENSOR_MIRROR_H:
		SIM120CSensor.cntr_b |= 1;
		break;
	  case IMAGE_SENSOR_MIRROR_V:
		SIM120CSensor.cntr_b |= 2;
		break;
	  case IMAGE_SENSOR_MIRROR_HV:
		SIM120CSensor.cntr_b |= 3;
		break;
	  default:
		break;
	  }
	  SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
	  CamWriteCmosSensor(0x00, 0x00);
	  CamWriteCmosSensor(0x04, SIM120CSensor.cntr_b); 
}

/*************************************************************************
* FUNCTION
*    SIM120CNightMode   
*
* DESCRIPTION
*    This function switch on/off night mode
*
* PARAMETERS
*    enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CNightMode(kal_bool Enable)
{    
#ifdef SIM120C_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIM120C NightMode %d",Enable);
#endif

SIM120CSensor.night_mode = Enable;

SIM120CCalFps(); /* need cal new fps */
}

/*************************************************************************
* FUNCTION
*    SIM120CSceneMode    
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
static MM_ERROR_CODE_ENUM SIM120CSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    SIM120CNightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CEv        
*
* DESCRIPTION
*    SIM120C EV setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
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
	kal_uint8 t_d65, t_cwf, t_a;
#ifdef SIM120C_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif    
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: 
	  t_d65 = t_cwf = t_a = 0x40;
      break;
    case CAM_EV_NEG_3_3: 
	  t_d65 = t_cwf = t_a = 0x48;
      break;
    case CAM_EV_NEG_2_3: 	  
	  t_d65 = t_cwf = t_a = 0x50;
	  break;
    case CAM_EV_NEG_1_3: 	  
	  t_d65 = t_cwf = t_a = 0x60;
	  break;
    case CAM_EV_ZERO:    	  
	  t_d65 = t_cwf = 0x80;
	  t_a = 0x7D;
	  break;
    case CAM_EV_POS_1_3: 	  
	  t_d65 = t_cwf = t_a = 0x88;
	  break;
    case CAM_EV_POS_2_3: 	  
	  t_d65 = t_cwf = t_a = 0x90;
	  break;
    case CAM_EV_POS_3_3: 	  
	  t_d65 = t_cwf = t_a = 0xA0;
	  break;
    case CAM_EV_POS_4_3: 	  
	  t_d65 = t_cwf = t_a = 0xB0;
	  break;
    default: break;
    }
	
	CamWriteCmosSensor(0x00, 0x01);
	CamWriteCmosSensor(0x12, t_d65); /* AE target for D65 */
	CamWriteCmosSensor(0x13, t_cwf); /* AE target for CWF */
	CamWriteCmosSensor(0x14, t_a); /* AE target for A light */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CContrast
*
* DESCRIPTION
*    SIM120C Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_FALSE;  //KAL_TRUE
    EvPara->ItemCount = 3;
    EvPara->SupportItem[0] = CAM_CONTRAST_HIGH;
    EvPara->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    EvPara->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef SIM120C_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CWb
*
* DESCRIPTION
*    SIM120C WB setting.
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
static MM_ERROR_CODE_ENUM SIM120CWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIM120C_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
    
	CamWriteCmosSensor(0x00, 0x02);
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      /* CAM_WB_AUTO mode should not update R/G/B gains */	  
	  CamWriteCmosSensor(0x10, 0xC3);
      break;
    case CAM_WB_CLOUD:
	  CamWriteCmosSensor(0x10, 0x00); /* disable AWB */      
	  CamWriteCmosSensor(0x60, 0xD0); /* AWB R gain */
	  CamWriteCmosSensor(0x61, 0x88); /* AWB B gain */      
      break;
    case CAM_WB_DAYLIGHT:
	  CamWriteCmosSensor(0x10, 0x00); /* disable AWB */	   
	  CamWriteCmosSensor(0x60, 0xC2); /* AWB R gain */
	  CamWriteCmosSensor(0x61, 0x9E); /* AWB B gain */
      break;
    case CAM_WB_INCANDESCENCE:
	  CamWriteCmosSensor(0x10, 0x00); /* disable AWB */	 
	  CamWriteCmosSensor(0x60, 0x98); /* AWB R gain */
	  CamWriteCmosSensor(0x61, 0xC8); /* AWB B gain */
      break;
    case CAM_WB_FLUORESCENT:
	  CamWriteCmosSensor(0x10, 0x00); /* disable AWB */  
	  CamWriteCmosSensor(0x60, 0xAA); /* AWB R gain */
	  CamWriteCmosSensor(0x61, 0xBE); /* AWB B gain */
      break;
    case CAM_WB_TUNGSTEN:
	  CamWriteCmosSensor(0x10, 0x00); /* disable AWB */  
	  CamWriteCmosSensor(0x60, 0x90); /* AWB R gain */
	  CamWriteCmosSensor(0x61, 0xC0); /* AWB B gain */
      break;
    default:
      break;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIM120CEffect
*
* DESCRIPTION
*    SIM120C Effect setting.
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
static MM_ERROR_CODE_ENUM SIM120CEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 9;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef SIM120C_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif

	CamWriteCmosSensor(0x00, 0x03);
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
	  CamWriteCmosSensor(0x8C, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
	  CamWriteCmosSensor(0x8C, 0x40);
      break;
    case CAM_EFFECT_ENC_SEPIA:
      CamWriteCmosSensor(0x8D, 0x60);
      CamWriteCmosSensor(0x8E, 0xA0);
      CamWriteCmosSensor(0x8C, 0x80);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
      CamWriteCmosSensor(0x8D, 0x50);
      CamWriteCmosSensor(0x8E, 0x50);
      CamWriteCmosSensor(0x8C, 0x80);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
      CamWriteCmosSensor(0x8D, 0xC0);
      CamWriteCmosSensor(0x8E, 0x60);
      CamWriteCmosSensor(0x8C, 0x80);
      break;
    case CAM_EFFECT_ENC_COLORINV:
      CamWriteCmosSensor(0x8C, 0x10);
      break;
    case CAM_EFFECT_ENC_GRAYINV:
      CamWriteCmosSensor(0x8C, 0x20);
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
      CamWriteCmosSensor(0x8C, 0x08);
      break;
    case CAM_EFFECT_ENC_SKETCH:
      CamWriteCmosSensor(0x8C, 0x04);
      break;
    default:
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CStillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 2;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_QVGA;	
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_1M;	
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CBanding
*
* DESCRIPTION
*    This function get banding setting
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Banding->IsSupport = KAL_TRUE;
    Banding->ItemCount = 2;
    Banding->SupportItem[0] = CAM_BANDING_50HZ;
    Banding->SupportItem[1] = CAM_BANDING_60HZ;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef SIM120C_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif

    SIM120CSensor.banding = In->FeatureSetValue;

	SIM120CCalFps(); /* need cal new fps */
	SIM120CSetBaseShutter(); /* update base shutter */

  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CGetSensorInfo
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
static void SIM120CGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = SIM120C_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  
  Info->PreviewWidth = SIM120C_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->PreviewHeight = SIM120C_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->FullWidth = SIM120C_IMAGE_SENSOR_FULL_WIDTH_DRV;
  Info->FullHeight = SIM120C_IMAGE_SENSOR_FULL_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    SIM120CDetectSensorId
*
* DESCRIPTION
*    This function detect sensor Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 SIM120CDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM SIM120CSensorClose(void);
  kal_uint16 SIM120CPowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == SIM120CSensor.SensorIdx)
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
      SensorId = SIM120CPowerOn();
      SIM120CSensorClose();
#ifdef SIM120C_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"SIM120CDetectSensorId:%x",SensorId);
#endif
      if (SIM120C_SENSOR_ID == SensorId)
      {
        return SIM120C_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    SIM120CInitOperationPara
*
* DESCRIPTION
*    This function set sensor operation Para
*
* PARAMETERS
*    Para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    SIM120CAeEnable
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
static MM_ERROR_CODE_ENUM SIM120CAeEnable(kal_bool Enable)
{
  kal_uint8 AeTemp;

   if (SIM120CSensor.BypassAe)
  {
    Enable = KAL_FALSE;
  }

  if (Enable)
  {
    AeTemp = 0xC4;
  }
  else
  {
    AeTemp = 0x00;
  }
#ifdef SIM120C_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x10, AeTemp);
 
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CAwbEnable
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
static MM_ERROR_CODE_ENUM SIM120CAwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;
  
  if (SIM120CSensor.BypassAwb)
	{
	  Enable = KAL_FALSE;
	}

  if (Enable)
  {
    AwbTemp = 0xC3;
  }
  else
  {
    AwbTemp = 0x00;
  }
#ifdef SIM120C_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x00, 0x02);
  CamWriteCmosSensor(0x10, AwbTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CPowerOn
*
* DESCRIPTION
*    This function reset sensor and read Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 SIM120CPowerOn(void)
{
  kal_uint16 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(SIM120CSensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, SIM120C_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to high to activate SIM120C */
  CamPdnPinCtrl(SIM120CSensor.SensorIdx, 1);
  kal_sleep_task(1);
 
  /* Reset the sensor */
  CamRstPinCtrl(SIM120CSensor.SensorIdx, 1);
  CamRstPinCtrl(SIM120CSensor.SensorIdx, 0);
  kal_sleep_task(1);
  CamRstPinCtrl(SIM120CSensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(1);
  
  /* Read Sensor ID  */
  CamWriteCmosSensor(0x00,0x00);  
  SensorId = CamReadCmosSensor(0x01);
#ifdef SIM120C_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIM120C Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    SIM120CPreview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 cntr_b = 0xC0; /* fixed frame rate */
  kal_uint16 dummy_pixel, dummy_line;
  kal_int16 def_dummy_line;

#ifdef SIM120C_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIM120C Preview");
#endif

  SIM120CSensor.banding = In->BandingFreq;  //????
  SIM120CSensor.night_mode = In->NightMode;

  
  SIM120CSetHVMirror(In->ImageMirror);
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    SIM120CSensor.video_mode = KAL_TRUE;
	if(SIM120CSensor.night_mode)
		{ 
		  SIM120CSensor.night_fps=In->MaxVideoFrameRate * SIM120C_FRAME_RATE_UNIT/ 10;
		}
	else
		{		  
		  SIM120CSensor.normal_fps=In->MaxVideoFrameRate * SIM120C_FRAME_RATE_UNIT/ 10;
		}

	dummy_pixel = 0;
    dummy_line = 0;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    SIM120CSensor.video_mode = KAL_FALSE;
	
    SIM120CSensor.normal_fps = SIM120C_FPS(10);
    SIM120CSensor.night_fps = SIM120C_FPS(5);
	
    cntr_b = 0;
    dummy_pixel = 0;
    dummy_line = 0;
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    break;
  default:
    break;
  }
   
   dummy_pixel += SIM120CSensor.def_pv_dummy_pixel;
   /* limit frame rate to SIM120C_MAX_FPS */
   def_dummy_line = (SIM120CSensor.pv_pclk * SIM120C_FPS(1)) / (2 * SIM120C_MAX_FPS * (SIM120C_PV_PERIOD_PIXEL_NUMS + dummy_pixel));
   def_dummy_line -= SIM120C_PV_PERIOD_LINE_NUMS;
   ASSERT(def_dummy_line >= 0);
   SIM120CSetPVDummy(dummy_pixel, dummy_line + def_dummy_line);
   CamWriteCmosSensor(0x00, 0x00);
   SIM120CSensor.cntr_b = (SIM120CSensor.cntr_b&0x2F)|cntr_b;
   CamWriteCmosSensor(0x04, SIM120CSensor.cntr_b); /* switch to group B */
   
   SIM120CNightMode(SIM120CSensor.night_mode);
   
   Out->GrabStartX = SIM120C_PV_X_START;
   Out->GrabStartY = SIM120C_PV_Y_START;
   Out->ExposureWindowWidth = SIM120C_IMAGE_SENSOR_PV_WIDTH;
   Out->ExposureWindowHeight = SIM120C_IMAGE_SENSOR_PV_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    SIM120CCapture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIM120CCapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 dummy_pixel;
  
  if (In->ImageTargetWidth <= SIM120C_IMAGE_SENSOR_PV_WIDTH_DRV &&
      In->ImageTargetHeight <= SIM120C_IMAGE_SENSOR_PV_HEIGHT_DRV)
  {
    dummy_pixel = 0;    
    dummy_pixel += (SIM120CSensor.pv_line_length - SIM120C_PV_PERIOD_PIXEL_NUMS);
    SIM120CSetPVDummy(dummy_pixel, SIM120CSensor.pv_frame_height - SIM120C_PV_PERIOD_LINE_NUMS);
    Out->GrabStartX = SIM120C_PV_X_START;
    Out->GrabStartY= SIM120C_PV_Y_START;
    Out->ExposureWindowWidth = SIM120C_IMAGE_SENSOR_PV_WIDTH;
    Out->ExposureWindowHeight = SIM120C_IMAGE_SENSOR_PV_HEIGHT;
  }
  else
  {
#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
    if (In->ImageTargetWidth > SIM120C_IMAGE_SENSOR_FULL_WIDTH_DRV &&
        In->ImageTargetHeight > SIM120C_IMAGE_SENSOR_FULL_HEIGHT_DRV &&
        In->ZoomFactor >= ISP_DIGITAL_ZOOM_INTERVAL * 1.6)
    {
      dummy_pixel = 0x800;
    }
    else if (In->ImageTargetWidth == SIM120C_IMAGE_SENSOR_FULL_WIDTH_DRV &&
             In->ImageTargetHeight == SIM120C_IMAGE_SENSOR_FULL_HEIGHT_DRV &&
             In->ZoomFactor >= ISP_DIGITAL_ZOOM_INTERVAL * 2.3)
    {
      dummy_pixel = 0x400;
    }
    else
#endif
    {
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
      dummy_pixel = 571; /* limit to 12 fps for MT6253's bandwidth */
#else
      dummy_pixel = 0;
#endif
    }
    SIM120CSetCapDummy(dummy_pixel, 0);
    CamWriteCmosSensor(0x00, 0x00);
    SIM120CSensor.cntr_b |= 0x10; /* switch to group A */
    CamWriteCmosSensor(0x04, SIM120CSensor.cntr_b);
    if (In->ImageTargetWidth == SIM120C_IMAGE_SENSOR_FULL_WIDTH_DRV &&
        In->ImageTargetHeight == SIM120C_IMAGE_SENSOR_FULL_HEIGHT_DRV) /* for view angle */
    {
      Out->GrabStartX = 48;
      Out->GrabStartY = 32;
      Out->ExposureWindowWidth = 1248;
      Out->ExposureWindowHeight = 956;
    }
    else
    {
      Out->GrabStartX = SIM120C_FULL_X_START;
      Out->GrabStartY = SIM120C_FULL_Y_START;
      Out->ExposureWindowWidth = SIM120C_IMAGE_SENSOR_FULL_WIDTH;
      Out->ExposureWindowHeight = SIM120C_IMAGE_SENSOR_FULL_HEIGHT;
    }
  }

}

/*************************************************************************
* FUNCTION
*    SIM120CSensorOpen
*
* DESCRIPTION
*    This function read sensor Id and init sensor
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
static MM_ERROR_CODE_ENUM SIM120CSensorOpen(void)
{
  if (SIM120C_SENSOR_ID != SIM120CPowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  SIM120CInitialSetting(); 
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CSensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    Id: scenario Id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CSensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef SIM120C_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIM120C FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return SIM120CWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = SIM120CEv(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = SIM120CContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = SIM120CWb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = SIM120CEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = SIM120CStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = SIM120CBanding(In, Out);
    break;
	#if 1
  case CAL_FEATURE_CAMERA_SCENE_MODE:
	ErrCode = SIM120CSceneMode(KAL_TRUE, In, Out);
	break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
	ErrCode = SIM120CSceneMode(KAL_FALSE, In, Out);
	break;
    #endif
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    SIM120CGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIM120CDetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
  	((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIM120C_MAX_FPS * SIM120C_FRAME_RATE_UNIT / 10;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    SIM120CInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:    
    CamGetHWInfo(SIM120CSensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(SIM120CSensor.SensorIdx, 1);   
    CamRstPinCtrl(SIM120CSensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    SIM120CSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    SIM120CSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:  	
	SIM120CSensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
	SIM120CAeEnable(SIM120CSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
	SIM120CSensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
	SIM120CAwbEnable(SIM120CSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SIM120CSensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario Id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIM120CSensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SIM120CPreview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    SIM120CCapture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CSensorClose   
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
static MM_ERROR_CODE_ENUM SIM120CSensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(SIM120CSensor.SensorIdx, 0);
  CisModulePowerOn(SIM120CSensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIM120CSensorFunc
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
MM_ERROR_CODE_ENUM SIM120CSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIM120C =
  {
    SIM120CSensorOpen,
    SIM120CSensorFeatureCtrl,
    SIM120CSensorCtrl,
    SIM120CSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSIM120C;
  
  return MM_ERROR_NONE;
}

