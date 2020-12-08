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
*#80FF80
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
 *   image_sensor.c
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

/* image_sensor_MT9P015.h's macro mapping to image_sensor.h's macro */
#if defined(__CAMERA_NVRAM_REDUCTION__)
#ifndef FACTORY_START_ADDR
#define FACTORY_START_ADDR MT9P015_FACTORY_START_ADDR
#endif
#ifndef PRE_GAIN
#define PRE_GAIN MT9P015_PRE_GAIN
#endif
#ifndef CMMCLK_CURRENT
#define CMMCLK_CURRENT MT9P015_CMMCLK_CURRENT
#endif
#ifndef FRAME_RATE_LIMITATION
#define FRAME_RATE_LIMITATION MT9P015_FRAME_RATE_LIMITATION
#endif
#ifndef REGISTER_EDITOR
#define REGISTER_EDITOR MT9P015_REGISTER_EDITOR
#endif
#ifndef GROUP_TOTAL_NUMS
#define GROUP_TOTAL_NUMS MT9P015_GROUP_TOTAL_NUMS
#endif
#ifndef SENSOR_BASEGAIN
#define SENSOR_BASEGAIN MT9P015_SENSOR_BASEGAIN
#endif
#ifndef PRE_GAIN_R_INDEX
#define PRE_GAIN_R_INDEX MT9P015_PRE_GAIN_R_INDEX
#endif
#ifndef PRE_GAIN_Gr_INDEX
#define PRE_GAIN_Gr_INDEX MT9P015_PRE_GAIN_Gr_INDEX
#endif
#ifndef PRE_GAIN_Gb_INDEX
#define PRE_GAIN_Gb_INDEX MT9P015_PRE_GAIN_Gb_INDEX
#endif
#ifndef PRE_GAIN_B_INDEX
#define PRE_GAIN_B_INDEX MT9P015_PRE_GAIN_B_INDEX
#endif
#ifndef CMMCLK_CURRENT_INDEX
#define CMMCLK_CURRENT_INDEX MT9P015_CMMCLK_CURRENT_INDEX
#endif
#endif

//#define __MT9P015_DEBUG_TRACE__

static struct MT9P015_sensor_STRUCT Mt9p015Sensor;
IMAGE_SENSOR_INDEX_ENUM MT9P015SensorIdx;
sensor_data_struct *pMT9P015NvramSensorData;
extern camcorder_info_struct	MT9P015_dsc_support_info;
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
extern void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);

/*************************************************************************
* FUNCTION
*    MT9P015PowerOn
*
* DESCRIPTION
*    This function set the mirror to the CMOS sensor
*
* PARAMETERS
*    mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015SetMirror(kal_uint8 mirror)
{
  kal_uint8 sensor_mirror = 0;
  
 // if (Mt9p015Sensor.Mirror == mirror) return;
 // Mt9p015Sensor.Mirror = mirror;
  switch (mirror)
  {
  case IMAGE_SENSOR_MIRROR_NORMAL:
	sensor_mirror = 3;
	break;
  case IMAGE_SENSOR_MIRROR_H:
    sensor_mirror = 2;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    sensor_mirror = 1;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    sensor_mirror = 0;
    break;
  default:
    break;
  }
  //SET_FIRST_GRAB_COLOR((MT9P015_FIRST_GRAB_COLOR + sensor_mirror)&0x03);
  CamWriteCmosSensor(0x0101, sensor_mirror);
}

/*************************************************************************
* FUNCTION
*    MT9P015Gain2Reg
*
* DESCRIPTION
*    This function translate gain to sensor register value
*
* PARAMETERS
*    gain: sensor gain, base(0x40)
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint16 MT9P015Gain2Reg(kal_uint16 gain)
{
  kal_uint16 reg;
  
  reg = (gain * 20 + BASEGAIN) / BASEGAIN / 2;
  /* Max gain is 12.7x */
  return reg > 0x7F ? 0x7F : reg;
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
/*************************************************************************
* FUNCTION
*    MT9P015WriteShutter
*
* DESCRIPTION
*    This function apply shutter to sensor
*
* PARAMETERS
*    course: course integration time
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015WriteShutter(kal_uint16 course)
{
#ifdef __MT9P015_DEBUG_TRACE__
	kal_prompt_trace(MOD_ENG, "MT9P015WriteShutter: %d ",course);
#endif
  if (!course) course = 1; /* avoid 0 */
  CamWriteCmosSensor(0x0104, 0x01); /* grouped_parameter_hold */
  CamWriteCmosSensor(0x0202, course >> 8); /* course_integration_time */
  CamWriteCmosSensor(0x0203, course);
  CamWriteCmosSensor(0x0104, 0x00);
}

/*************************************************************************
* FUNCTION
*    MT9P015ArrayWindow
*
* DESCRIPTION
*    This function config sensor array window
*
* PARAMETERS
*    startx, starty, width, height
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015ArrayWindow(kal_uint16 startx, kal_uint16 starty, kal_uint16 width, kal_uint16 height)
{
  const kal_uint16 endx = startx + width - 1;
  const kal_uint16 endy = starty + height - 1;
  
  CamWriteCmosSensor(0x0344, startx >> 8); /* x_addr_start */
  CamWriteCmosSensor(0x0345, startx);
  CamWriteCmosSensor(0x0346, starty >> 8); /* y_addr_start */
  CamWriteCmosSensor(0x0347, starty);
  CamWriteCmosSensor(0x0348, endx >> 8); /* x_addr_end */
  CamWriteCmosSensor(0x0349, endx);
  CamWriteCmosSensor(0x034A, endy >> 8); /* y_addr_end */
  CamWriteCmosSensor(0x034B, endy);
}

/*************************************************************************
* FUNCTION
*    MT9P015OutputWindow
*
* DESCRIPTION
*    This function config output window
*
* PARAMETERS
*    PvMode: KAL_TRUE means switch to 1/4 size to preview, KAL_FALSE means switch to full size to caputre
*    DummyPixel, DummyLines
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015OutputWindow(kal_bool PvMode, kal_uint16 DummyPixel, kal_uint16 DummyLines)
{
  kal_uint16 hactive, vactive, LineLength, FrameHeight;
  kal_uint8 inc;
  
  if (PvMode)
  {
    inc = 3;
    hactive = MT9P015_IMAGE_SENSOR_PV_HACTIVE;
    vactive = MT9P015_IMAGE_SENSOR_PV_VACTIVE;
    LineLength = MT9P015_PV_PERIOD_PIXEL_NUMS + DummyPixel;
    FrameHeight = MT9P015_PV_PERIOD_LINE_NUMS + DummyLines;
  }
  else
  {
    inc = 1;
    hactive = MT9P015_IMAGE_SENSOR_FULL_HACTIVE;
    vactive = MT9P015_IMAGE_SENSOR_FULL_VACTIVE;
    LineLength = MT9P015_FULL_PERIOD_PIXEL_NUMS + DummyPixel;
    FrameHeight = MT9P015_FULL_PERIOD_LINE_NUMS + DummyLines;
  }
  CamWriteCmosSensor(0x0104, 0x01);
  /* config line length */
  if (LineLength != Mt9p015Sensor.LineLength)
  {
    Mt9p015Sensor.LineLength = LineLength;
#ifdef __MT9P015_DEBUG_TRACE__
    kal_prompt_trace(MOD_ENG, "LineLength: %x;%d", LineLength,LineLength);
#endif
    CamWriteCmosSensor(0x0342, LineLength >> 8); /* LineLength_pck */
    CamWriteCmosSensor(0x0343, LineLength);	
	
  }
  /* config frame height */
  if (FrameHeight != Mt9p015Sensor.FrameHeight)
  {
    Mt9p015Sensor.FrameHeight = FrameHeight;
#ifdef __MT9P015_DEBUG_TRACE__
    kal_prompt_trace(MOD_ENG, "frame_length: %x;%d", FrameHeight,FrameHeight);
#endif
    CamWriteCmosSensor(0x0340, Mt9p015Sensor.FrameHeight >> 8); /* frame_length_lines */
    CamWriteCmosSensor(0x0341, Mt9p015Sensor.FrameHeight);
  }
  /* config output window */
  if (Mt9p015Sensor.PvMode != PvMode)
  {
    Mt9p015Sensor.PvMode = PvMode;
    MT9P015ArrayWindow(8, 8, MT9P015_IMAGE_SENSOR_FULL_HACTIVE + (Mt9p015Sensor.PvMode ? -2 : 2), MT9P015_IMAGE_SENSOR_FULL_VACTIVE + 2);
    CamWriteCmosSensor(0x0383, inc); /* x_odd_inc */
    CamWriteCmosSensor(0x0387, inc); /* y_odd_inc */
    CamWriteCmosSensor(0x034C, hactive >> 8); /* x_output_size */
    CamWriteCmosSensor(0x034D, hactive);
    CamWriteCmosSensor(0x034E, vactive >> 8); /* y_output_size */
    CamWriteCmosSensor(0x034F, vactive);
  }
  CamWriteCmosSensor(0x0104, 0x00);
}

/*************************************************************************
* FUNCTION
*    MT9P015SetClock
*
* DESCRIPTION
*    This function set sensor vt clock and op clock, before call this function, must be sure
*    sensor is in standby state!!!
*
* PARAMETERS
*    clk: vt clock
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015SetClock(kal_uint32 clk)
{
  kal_uint8 i=0xf;
  static const kal_uint8 clk_setting[][6] =
  {
    {0x08,0x01,0x02,0x20,0x08,0x02}, /* MCLK: 48M, VT CLK: 96M, PCLK: 48M */
	//{0x08,0x01,0x02,0x20,0x08,0x02}, /* MCLK: 48M, VT CLK: 96M, PCLK: 48M */
	//{0x06,0x01,0x03,0x24,0x08,0x01}, /* MCLK: 48M, VT CLK: 96M, PCLK: 72M */
	//{0x04,0x01,0x0d,0x60,0x08,0x01}, /* MCLK: 52M, VT CLK: 96M, PCLK: 48M */
    {0x05,0x01,0x03,0x28,0x08,0x01}, /* MCLK: 48M, VT CLK: 128M, PCLK: 80M */
    //{0x06,0x01,0x04,0x3C,0x08,0x01}, /* MCLK: 48M, VT CLK: 120M, PCLK: 90M */
	//{0x06,0x01,0x04,0x3C,0x0A,0x01}, /* MCLK: 48M, VT CLK: 120M, PCLK: 72M */
	//{0x05,0x01,0x0d,0xa0,0x08,0x01}, /* MCLK: 52M, VT CLK: 128M, PCLK: 80M */
    {0x05,0x01,0x03,0x2A,0x08,0x01}, /* MCLK: 48M, VT CLK: 134.4M, PCLK: 84M */
  };
  
  if (Mt9p015Sensor.VtClk == clk) return;
  Mt9p015Sensor.VtClk = clk;
  switch (Mt9p015Sensor.VtClk)
  {
  case 96000000: i = 0; break;
  case 128000000: i = 1; break;
  case 134400000: i = 2; break;
  default:
    ASSERT(0);
  }
  /* VtClk = mclk * pll_multipler / (pre_pll_div * op_sys_clk_div * op_pix_clk_div * row_speed[10:8]) */
  /* vtclk =mclk * pll_multipler / (pre_pll_div * vt_sys_div * vt_pix_clk_div * row_speed[2:0]) */
  CamWriteCmosSensor(0x0100, 0x00); /* standby */
  
  CamWriteCmosSensor(0x0301, clk_setting[i][0]); /* vt_pix_clk_div, (Internal used to control the tiMing of the pixel array) */
  CamWriteCmosSensor(0x0303, clk_setting[i][1]); /* vt_sys_div (For SIMA) */
  CamWriteCmosSensor(0x0305, clk_setting[i][2]); /* pre_pll_div */
  CamWriteCmosSensor(0x0307, clk_setting[i][3]); /* pll_multipler */
  CamWriteCmosSensor(0x0309, clk_setting[i][4]); /* op_pix_clk_div (Pixel clock) */
  CamWriteCmosSensor(0x030B, clk_setting[i][5]); /* op_sys_clk_div */
//  kal_sleep_task(1); /* allow PLL to lock */
  
//  CamWriteCmosSensor(0x0100, 0x01); /* streaMing */
//  kal_sleep_task(1);
}


/*************************************************************************
* FUNCTION
*    MT9P015InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor
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
static void MT9P015InitialSetting(void)
{
  CamWriteCmosSensor(0x0103, 0x01); /* software reset */
  kal_sleep_task(5); /* wait for reset done */
  CamWriteCmosSensor(0x301A, 0x10); /* RESET_REGISTER, enable parallel interface and disable serialiser */
  CamWriteCmosSensor(0x301B, 0xC8); /* software standby */
  CamWriteCmosSensor(0x3064, 0x08); /* smia test:[0:3]smia_test_pfd,[4]smia_test_dp_bypass,[5]smia_test_scaler_pattern_test,[6]smia_test_scaler_bist */
  CamWriteCmosSensor(0x3065, 0x05); /* [7]smia_test_fifo_sam_bist,[8]smia_test_embedded_data,[9]smia_test_pll_bypass,[10:11]smia_test_pll_lock_mode */
  CamWriteCmosSensor(0x0104, 0x01);

  /* parallel recommended setting */
  CamWriteCmosSensor(0x3094, 0x46);
  CamWriteCmosSensor(0x3095, 0x56);
  CamWriteCmosSensor(0x309E, 0x5D);
  CamWriteCmosSensor(0x309F, 0x00);
  
  CamWriteCmosSensor(0x3088, 0x6F); /* dac_ld_8_9:[0:3]ana_sreg_vdac_vtx_lo,[4:7]ana_sreg_vdac_vtx_hi */
  CamWriteCmosSensor(0x3089, 0xFF); /* [8:11]ana_sreg_vdac_vrst_lo,[12:15]ana_sreg_vdac_vrst_hi */
  CamWriteCmosSensor(0x3086, 0x24); 
  CamWriteCmosSensor(0x3087, 0x68);
 
  Mt9p015Sensor.VtClk = 0; /* force config clock */
  MT9P015SetClock(MT9P015_PREVIEW_CLK);
  
  CamWriteCmosSensor(0x301A, 0x10);
  CamWriteCmosSensor(0x301B, 0xCC); /* StreaMing start  */
  CamWriteCmosSensor(0x316C, 0xA4);	/* relate to ADC, with1.4X as Min gain */
  CamWriteCmosSensor(0x316D, 0xF0);
  
  CamWriteCmosSensor(0x306E, 0x34);	/* slew rate */
  CamWriteCmosSensor(0x306F, 0x80);	
  
  /* default setting */
  //Mt9p015Sensor.Mirror = !IMAGE_SENSOR_MIRROR_NORMAL; /* force config sensor mirror */
  //MT9P015SetMirror(IMAGE_SENSOR_MIRROR_NORMAL);
  CamWriteCmosSensor(0x0104, 0x00);
  Mt9p015Sensor.PvMode = KAL_FALSE; /* force config pv mode */
  Mt9p015Sensor.LineLength = Mt9p015Sensor.FrameHeight = 0; /* force config line length & frame height */
  MT9P015OutputWindow(KAL_TRUE, 0, 0);
  Mt9p015Sensor.Gain = 0x100; /* 4x */
  //weiyu testMT9P015CameraParaToSensor();
  CamWriteCmosSensor(0x0100, 0x01); /* streaMing */
}

/*************************************************************************
* FUNCTION
*    MT9P015PowerOn
*
* DESCRIPTION
*    This function power on CMOS sensor and check sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor ID
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 MT9P015PowerOn(void)
{
  //const kal_uint8 i2c_addr[] = {MT9P015_SLV1_WRITE_ID, MT9P015_SLV2_WRITE_ID, MT9P015_SLV3_WRITE_ID, MT9P015_SLV4_WRITE_ID};
  kal_uint8 i;
  kal_uint16 sensor_id;
  
  CisModulePowerOn(MT9P015SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9P015_SLV3_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 400);

 /* Reset the sensor */
 CamRstPinCtrl(MT9P015SensorIdx, 1);
 kal_sleep_task(22);
 CamRstPinCtrl(MT9P015SensorIdx, 0);
 kal_sleep_task(22);
 CamRstPinCtrl(MT9P015SensorIdx, 1);
  
  //for (i = 0; i < sizeof(i2c_addr) / sizeof(i2c_addr[0]); i++)
  for(i=0;i<3;i++)
  {
/*    Mt9p015Sensor.WriteId = i2c_addr[i];
    Mt9p015Sensor.ReadId = i2c_addr[i]|1;
	CameraSccbOpen(CAMERA_SCCB_SENSOR, i2c_addr[i], i2c_addr[i]|1, CAMERA_SCCB_8BIT, 320);*/
#ifdef __MT9P015_DEBUG_TRACE__
	kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C address: %x", Mt9p015Sensor.WriteId);
#endif
    sensor_id = (CamReadCmosSensor(0x0000) << 8)|CamReadCmosSensor(0x0001);
    if (MT9P015_SENSOR_ID == sensor_id) 
    {
#ifdef __MT9P015_DEBUG_TRACE__
	  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", sensor_id);
#endif
      return MT9P015_SENSOR_ID;
    }
/*	else
	   CameraSccbClose(CAMERA_SCCB_SENSOR);*/
  } 
  
#ifdef __MT9P015_DEBUG_TRACE__
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", sensor_id);
#endif
  return sensor_id;
}

/*************************************************************************
* FUNCTION
*    MT9P015CapFps
*
* DESCRIPTION
*    This function get capture frame rate
*
* PARAMETERS
*    image_window
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 MT9P015CapFps(kal_uint32 zoom_factor, kal_uint32 image_width)
{
#if (defined(CAM_OTF_CAPTURE) || defined(CAM_STANDARD_CAPTURE))
  static const kal_uint16 _cap_fps[5][4] =
  {
    /* 1x, (1x, 2x], (2x,4x], (4x,8x] */
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
    {MT9P015_FPS(30),MT9P015_FPS(23.5),MT9P015_FPS(13.5),MT9P015_FPS(12.5)}, /* 1M */
    {MT9P015_FPS(9),MT9P015_FPS(9),MT9P015_FPS(7.5),MT9P015_FPS(4)},       /* 2M */
    {MT9P015_FPS(9),MT9P015_FPS(9),MT9P015_FPS(4.5),MT9P015_FPS(2)},        /* 3M */
    {MT9P015_FPS(9),MT9P015_FPS(7),MT9P015_FPS(3),MT9P015_FPS(2)},          /* 4M */
    {MT9P015_FPS(9),MT9P015_FPS(5),MT9P015_FPS(2.5),MT9P015_FPS(1)},        /* 5M */
#else
    {MT9P015_FPS(30),MT9P015_FPS(25),MT9P015_FPS(16),MT9P015_FPS(15)},       /* 1M */
    {MT9P015_FPS(8),MT9P015_FPS(8),MT9P015_FPS(8),MT9P015_FPS(5)},           /* 2M */
    {MT9P015_FPS(8),MT9P015_FPS(8),MT9P015_FPS(5),MT9P015_FPS(2.5)},         /* 3M */
    {MT9P015_FPS(8),MT9P015_FPS(8),MT9P015_FPS(4),MT9P015_FPS(2)},           /* 4M */
    {MT9P015_FPS(8),MT9P015_FPS(6.5),MT9P015_FPS(3),MT9P015_FPS(1.5)},       /* 5M */
#endif
  };
#endif

#if (defined(CAM_OFFLINE_CAPTURE) || defined(CAM_STANDARD_CAPTURE))
  static const kal_uint16 offline_cap_fps[2] =
  {
    /* 1M,  2M - 5M */
  #if (defined(DRV_ISP_MT6236_HW_SUPPORT))
    MT9P015_FPS(30),MT9P015_FPS(15)
  #else
    MT9P015_FPS(30),MT9P015_FPS(8)
  #endif
  };
#endif

  kal_uint16 cap_fps, i = 0;
  
#if (defined(CAM_OTF_CAPTURE) || defined(CAM_STANDARD_CAPTURE))
  if (image_width >= 2592) /* 5M */
  {
    i = 4;
  }
  else if (image_width >= 2304) /* 4M */
  {
    i = 3;
  }
  else if (image_width >= 2048) /* 3M */
  {
    i = 2;
  }
  else if (image_width >= 1600) /* 2M */
  {
    i = 1;
  }
#else
  if (image_width >= 1600) /* 2M */
  {
    i = 1;
  }
#endif
  
#if (defined(CAM_OTF_CAPTURE) || defined(CAM_STANDARD_CAPTURE))
  if (zoom_factor > 400) /* (4x ~ 8x] */
  {
    cap_fps = _cap_fps[i][3];
  }
  else if (zoom_factor > 200) /* (2x ~ 4x] */
  {
    cap_fps = _cap_fps[i][2];
  }
  else if (zoom_factor > 100) /* (1x ~ 2x] */
  {
    cap_fps = _cap_fps[i][1];
  }
  else						  /* 1x */
  {
	cap_fps = _cap_fps[i][0];
  }
#endif

#if (defined(CAM_OFFLINE_CAPTURE) || defined(CAM_STANDARD_CAPTURE))
#if (defined(CAM_STANDARD_CAPTURE))
	if (zoom_factor > 100)
#endif
	cap_fps = offline_cap_fps[i]; 
#endif

  return cap_fps;
}

/*************************************************************************
* FUNCTION
*    MT9P015SetShutter
*
* DESCRIPTION
*    This function set e-shutter of MT9P015 to change exposure time.
*
* PARAMETERS
*    shutter : exposured lines
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015SetShutter(kal_uint16 shutter)
{
#ifdef __MT9P015_DEBUG_TRACE__
	kal_prompt_trace(MOD_ENG, "shutter:%d", shutter);
#endif
  Mt9p015Sensor.ExposureLines = shutter;
  MT9P015WriteShutter(Mt9p015Sensor.ExposureLines);
}

/*************************************************************************
* FUNCTION
*    MT9P015NightMode
*
* DESCRIPTION
*    This function night mode of MT9P015.
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
static void MT9P015NightMode(kal_bool enable)
{

}  

void MT9P015FixVideoFrameRate(kal_uint16 framerate)  
{
kal_uint16 DummyPixel = Mt9p015Sensor.LineLength - MT9P015_PV_PERIOD_PIXEL_NUMS;
kal_uint16 DummyLines = Mt9p015Sensor.FrameHeight - MT9P015_PV_PERIOD_LINE_NUMS;
kal_uint16 Max_exposure_pixels;

if (framerate>=300)
	Mt9p015Sensor.VideoCurrentFrameRate=300;/*line length:3013*/
else if(framerate>=240)
	Mt9p015Sensor.VideoCurrentFrameRate=240;/*line length:3766*/
else if(framerate>=200)
	Mt9p015Sensor.VideoCurrentFrameRate=200;/*line length:4519*/
else if(framerate>=150)
	Mt9p015Sensor.VideoCurrentFrameRate=150;/*line length:6026*/
else if(framerate>=120)
	Mt9p015Sensor.VideoCurrentFrameRate=120;/*line length:7532*/
else if(framerate>=100)
	Mt9p015Sensor.VideoCurrentFrameRate=100;/*line length:9039*/
else if(framerate>=75)
	Mt9p015Sensor.VideoCurrentFrameRate=75;/*line length:12052*/
else if(framerate>=50)
	Mt9p015Sensor.VideoCurrentFrameRate=50;/*line length:18097*/

  Max_exposure_pixels = Mt9p015Sensor.VtClk * MT9P015_FRAME_RATE_UNIT / (Mt9p015Sensor.VideoCurrentFrameRate * Mt9p015Sensor.FrameHeight);
  if (Max_exposure_pixels > Mt9p015Sensor.LineLength) /* fix Max frame rate, AE table will fix Min frame rate */
  {
    DummyPixel = Max_exposure_pixels - MT9P015_PV_PERIOD_PIXEL_NUMS;
  }
 
  MT9P015OutputWindow(KAL_TRUE, DummyPixel, DummyLines);
}


/*************************************************************************
* FUNCTION
*    MT9P015SetGain
*
* DESCRIPTION
*    This function is to set global gain to sensor.
*
* PARAMETERS
*    gain : sensor global gain(base: 0x40)
*
* RETURNS
*    the actually gain set to sensor.
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 MT9P015SetGain(kal_uint16 gain)
{
  kal_uint16 reg, new_gain;
#ifdef __MT9P015_DEBUG_TRACE__
	  kal_prompt_trace(MOD_ENG, "gain:%d", gain);
#endif
  Mt9p015Sensor.Gain = gain * pMT9P015NvramSensorData->cct[SENSOR_BASEGAIN].para / BASEGAIN;
  
  CamWriteCmosSensor(0x0104, 0x01);
  new_gain = Mt9p015Sensor.Gain * pMT9P015NvramSensorData->cct[PRE_GAIN_R_INDEX].para / BASEGAIN;
  reg = MT9P015Gain2Reg(new_gain);
  CamWriteCmosSensor(0x0209, reg&0xFF);
  
  new_gain = Mt9p015Sensor.Gain * pMT9P015NvramSensorData->cct[PRE_GAIN_Gr_INDEX].para / BASEGAIN;
  reg = MT9P015Gain2Reg(new_gain);
  CamWriteCmosSensor(0x0207, reg&0xFF);
  
  new_gain = Mt9p015Sensor.Gain * pMT9P015NvramSensorData->cct[PRE_GAIN_Gb_INDEX].para / BASEGAIN;
  reg = MT9P015Gain2Reg(new_gain);
  CamWriteCmosSensor(0x020D, reg&0xFF);
  
  new_gain = Mt9p015Sensor.Gain * pMT9P015NvramSensorData->cct[PRE_GAIN_B_INDEX].para / BASEGAIN;
  reg = MT9P015Gain2Reg(new_gain);
  CamWriteCmosSensor(0x020B, reg&0xFF);
  CamWriteCmosSensor(0x0104, 0x00);
  
  return gain;
}

kal_uint16 MT9P015ReadGain()
{
kal_uint16 gain=64;

return gain;
}
/*************************************************************************
* FUNCTION
*    MT9P015_Set_Flashlight
*
* DESCRIPTION
*    turn on/off MT9P015 flashlight.
*
* PARAMETERS
*    bEnable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9P015SetFlashlight(kal_bool enable)
{  
  FlashlightPowerOn(MT9P015SensorIdx,enable);
}   

/*************************************************************************
* FUNCTION
*    MT9P015GetSensorAeInfo
*
* DESCRIPTION
*    get sensor ae information
*
* PARAMETERS
*    pInfo
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void MT9P015GetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *pInfo)
{
    pInfo->DefaultPrevLinePixels = MT9P015_IMAGE_SENSOR_PV_HACTIVE;
    pInfo->CurrentPrevLinePixels =MT9P015_IMAGE_SENSOR_PV_HACTIVE;
    pInfo->CurrentPclk=MT9P015_PREVIEW_CLK/2;
}

/*************************************************************************
* FUNCTION
*    MT9P015_detect_sensor_id
*
* DESCRIPTION
*    This function detect id of CMOS sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor ID
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 MT9P015DetectSensorId(void)
	{
	  MM_ERROR_CODE_ENUM MT9P015SensorClose(void);
	  kal_uint16 MT9P015PowerOn();
	  kal_uint16 sensorId; 
	  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
	  kal_int8 i, j;
	  
	  if (IMAGE_SENSOR_MAIN == MT9P015SensorIdx)
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
		  sensorId = MT9P015PowerOn();
		  MT9P015SensorClose();
#ifdef MT9P015_DBG
		  kal_wap_trace(MOD_ENG,TRACE_INFO,"MT9P015 DetectSensorId:%x",sensorId);
#endif
		  if (MT9P015_SENSOR_ID == sensorId)
		  {
			return MT9P015_SENSOR_ID;
		  }
		}
	  }
	  return MM_ERROR_SENSOR_READ_ID_FAIL;
	}


/* write camera_para to sensor register */
void MT9P015CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32 i;
  
  for (i = 0; 0xFFFFFFFF != pCameraPara->SENSOR.reg[i].addr; i++)
  {
    CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for (i = FACTORY_START_ADDR; 0xFFFFFFFF != pCameraPara->SENSOR.reg[i].addr; i++)
  {
    CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  MT9P015SetGain(Mt9p015Sensor.Gain); /* update gain */
}

/* update camera_para from sensor register */
void MT9P015SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32 i;
  
  for (i = 0; 0xFFFFFFFF != pCameraPara->SENSOR.reg[i].addr; i++)
  {
    pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
  for (i = FACTORY_START_ADDR; 0xFFFFFFFF != pMT9P015NvramSensorData->reg[i].addr; i++)
  {
    pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
}

//------------------------Engineer mode---------------------------------
void  MT9P015GetSensorGroupCount(kal_int32* sensor_count_ptr)
{
  *sensor_count_ptr = GROUP_TOTAL_NUMS;
}

void MT9P015GetSensorGroupInfo(kal_uint16 group_idx, kal_uint8* group_name_ptr, kal_uint32* item_count_ptr)
{

  switch (group_idx)
  {
  case PRE_GAIN:
    sprintf((kal_char *)group_name_ptr, "CCT");
    *item_count_ptr = 5;
    break;
  case CMMCLK_CURRENT:
    sprintf((kal_char *)group_name_ptr, "CMMCLK Current");
    *item_count_ptr = 1;
    break;
  case FRAME_RATE_LIMITATION:
    sprintf((kal_char *)group_name_ptr, "Frame Rate Limitation");
    *item_count_ptr = 2;
    break;
  case REGISTER_EDITOR:
    sprintf((kal_char *)group_name_ptr, "Register Editor");
    *item_count_ptr = 2;
    break;
  default:
    ASSERT(0);
  }
}

void MT9P015GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{

  const static kal_char *cct_item_name[] = {"SENSOR_BASEGAIN", "Pregain-R", "Pregain-Gr", "Pregain-Gb", "Pregain-B"};
  const static kal_char *editer_item_name[] = {"REG addr", "REG value"};
  
  switch (group_idx)
  {
  case PRE_GAIN:
    switch (item_idx)
    {
    case SENSOR_BASEGAIN:
    case PRE_GAIN_R_INDEX:
    case PRE_GAIN_Gr_INDEX:
    case PRE_GAIN_Gb_INDEX:
    case PRE_GAIN_B_INDEX:
      break;
    default:
      ASSERT(0);
    }
    sprintf((kal_char *)info_ptr->ItemNamePtr, cct_item_name[item_idx - SENSOR_BASEGAIN]);
    info_ptr->ItemValue = pMT9P015NvramSensorData->cct[item_idx].para * 1000 / BASEGAIN;
    info_ptr->IsTrueFalse = info_ptr->IsReadOnly = info_ptr->IsNeedRestart = KAL_FALSE;
    info_ptr->Min = MT9P015_MIN_ANALOG_GAIN * 1000;
    info_ptr->Max = MT9P015_MAX_ANALOG_GAIN * 1000;
    break;
  case CMMCLK_CURRENT:
    switch (item_idx)
    {
    case 0:
      sprintf((kal_char *)info_ptr->ItemNamePtr, "Drv Cur[2,4,6,8]mA");
      switch (pMT9P015NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para)
      {
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
      info_ptr->IsTrueFalse = info_ptr->IsReadOnly = KAL_FALSE;
      info_ptr->IsNeedRestart = KAL_TRUE;
      info_ptr->Min = 2;
      info_ptr->Max = 8;
      break;
    default:
      ASSERT(0);
    }
    break;
  case FRAME_RATE_LIMITATION:
    switch (item_idx)
    {
    case 0:
      sprintf((kal_char *)info_ptr->ItemNamePtr, "Max Exposure Lines");
      info_ptr->ItemValue = 5998;
      break;
    case 1:
      sprintf((kal_char *)info_ptr->ItemNamePtr, "Min Frame Rate");
      info_ptr->ItemValue = 5;
      break;
    default:
      ASSERT(0);
    }
    info_ptr->IsTrueFalse = info_ptr->IsNeedRestart = KAL_FALSE;
    info_ptr->IsReadOnly = KAL_TRUE;
    info_ptr->Min = info_ptr->Max = 0;
    break;
  case REGISTER_EDITOR:
    switch (item_idx)
    {
    case 0:
    case 1:
      sprintf((kal_char *)info_ptr->ItemNamePtr, editer_item_name[item_idx]);
      info_ptr->ItemValue = 0;
      info_ptr->IsTrueFalse = info_ptr->IsReadOnly = info_ptr->IsNeedRestart = KAL_FALSE;
      info_ptr->Min = 0;
      info_ptr->Max = (item_idx == 0 ? 0xFFFF : 0xFF);
      break;
    default:
      ASSERT(0);
    }
    break;
  default:
    ASSERT(0);
  }
}

kal_bool MT9P015SetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
  kal_uint16 temp_para;
  
  switch (group_idx)
  {
  case PRE_GAIN:
    switch (item_idx)
    {
    case SENSOR_BASEGAIN:
    case PRE_GAIN_R_INDEX:
    case PRE_GAIN_Gr_INDEX:
    case PRE_GAIN_Gb_INDEX:
    case PRE_GAIN_B_INDEX:
      pMT9P015NvramSensorData->cct[item_idx].para = ItemValue * BASEGAIN / 1000;
      MT9P015SetGain(Mt9p015Sensor.Gain); /* update gain */
      break;
    default:
      ASSERT(0);
    }
    break;
  case CMMCLK_CURRENT:
    switch (item_idx)
    {
    case 0:
      switch (ItemValue)
      {
      case 2:
        temp_para = ISP_DRIVING_2MA;
        break;
      case 3:
      case 4:
        temp_para = ISP_DRIVING_4MA;
        break;
      case 5:
      case 6:
        temp_para = ISP_DRIVING_6MA;
        break;
      default:
        temp_para = ISP_DRIVING_8MA;
        break;
      }
      SetIspDrivingCurrent(temp_para);
      pMT9P015NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = temp_para;
      break;
    default:
      ASSERT(0);
    }
    break;
  case FRAME_RATE_LIMITATION:
    ASSERT(0);
    break;
  case REGISTER_EDITOR:
    switch (item_idx)
    {
      static kal_uint32 fac_sensor_reg;
    case 0:
      if (ItemValue < 0 || ItemValue > 0xFFFF) return KAL_FALSE;
      fac_sensor_reg = ItemValue;
      break;
    case 1:
      if (ItemValue < 0 || ItemValue > 0xFF) return KAL_FALSE;
      CamWriteCmosSensor(fac_sensor_reg, ItemValue);
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

void MT9P015GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=MT9P015_SENSOR_ID;
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_PARALLEL;
    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
    pSensorInfo->PreviewHMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
    pSensorInfo->PreviewVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
    pSensorInfo->PreviewHVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;    
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PixelClkInv=KAL_FALSE;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    pSensorInfo->VsyncPolarity=POLARITY_HIGH;
    pSensorInfo->PreviewMclkFreq = 48000000;
    pSensorInfo->CaptureMclkFreq = 48000000;
    pSensorInfo->VideoMclkFreq = 48000000;
    pSensorInfo->PreviewWidth=MT9P015_IMAGE_SENSOR_PV_WIDTH;
    pSensorInfo->PreviewHeight=MT9P015_IMAGE_SENSOR_PV_HEIGHT;
    pSensorInfo->FullWidth=MT9P015_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=MT9P015_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* MT9P015GetSensorInfo() */    


MM_ERROR_CODE_ENUM MT9P015BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo=pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
    kal_uint8 i;

    switch (pFeatureParaIn->FeatureCtrlCode)
    {
        case CAL_FEATURE_QUERY_OPERATION:
            for (i=CAM_ISO_AUTO;i<=CAM_ISO_400;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_5M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_FALSE;
            }
            for (;i<=CAM_ISO_1600;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_1M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_TRUE;
            }
        break;
    }
	return MM_ERROR_NONE;
}   /* MT9P015BinningInfo() */

MM_ERROR_CODE_ENUM MT9P015StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
}   /* MT9P015StillCaptureSize() */

void MT9P015InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 2;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;	/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->AeCalDelayFrame = 0;			/* The frame of calculation default 0 */
	pInitOperPara->AeShutDelayFrame = 0;			/* The frame of setting shutter default 0 for TG int */
	pInitOperPara->AeSensorGainDelayFrame = 1;	/* The frame of setting sensor gain */
	pInitOperPara->AeIspGainDelayFrame = 2;		/* The frame of setting gain */
	pInitOperPara->AeCalPeriod = 3;				/* AE AWB calculation period */
	#if(defined(LED_FLASHLIGHT_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
	#elif(defined(LED_ONOFF_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_ONOFF;
	#else
       	pInitOperPara->FlashlightMode = FLASHLIGHT_NONE;
	#endif
  pInitOperPara->FlashlightDeltaMainLum = 65;    // 1.015*64(1.015X)

   pInitOperPara->LedFlashlightRedeyeDelayFrame = 4;   ///Bin added: must init to a valid value, since REDEYE stobe need it
} /* MT9P015InitOperationPara() */

void MT9P015DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
    kal_mem_cpy(pDscSupportInfo, &MT9P015_dsc_support_info, sizeof(camcorder_info_struct));
} /* MT9P015MipiDscSupportInfo() */

static void MT9P015Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

#ifdef __MT9P015_DEBUG_TRACE__
		  kal_prompt_trace(MOD_ENG, "MT9P015_preview");
#endif
	  MT9P015SetClock(MT9P015_PREVIEW_CLK);
	  MT9P015SetMirror(pParaIn->ImageMirror);
		Mt9p015Sensor.NormalFps = MT9P015_FPS(30);
		Mt9p015Sensor.DummyLines = 0;

	  MT9P015OutputWindow(KAL_TRUE, 0, Mt9p015Sensor.DummyLines); /* modify DummyPixel must gen AE table again */
	  
    pParaOut->GrabStartX = MT9P015_PV_X_START;
    pParaOut->GrabStartY = MT9P015_PV_Y_START;
    pParaOut->ExposureWindowWidth = MT9P015_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P015_IMAGE_SENSOR_PV_HEIGHT;

	MT9P015WriteShutter(Mt9p015Sensor.ExposureLines);
	CamWriteCmosSensor(0x0100, 0x01); /* streaMing */

}/* MT9P015Preview */


void MT9P015GetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
    pPreviewInfo->pixels = Mt9p015Sensor.LineLength;
    pPreviewInfo->lines = Mt9p015Sensor.FrameHeight+Mt9p015Sensor.DummyLines;
    pPreviewInfo->frame_lines = Mt9p015Sensor.FrameHeight;
}

static void MT9P015Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

	  const kal_uint16 pv_LineLength = MT9P015_PV_PERIOD_PIXEL_NUMS;
	  const kal_uint32 pv_VtClk = MT9P015_PREVIEW_CLK;
	  kal_uint32 shutter = Mt9p015Sensor.ExposureLines;
	  kal_uint16 DummyPixel, cap_fps;
#ifdef __MT9P015_DEBUG_TRACE__
			kal_prompt_trace(MOD_ENG, "MT9P015_capture");
#endif

    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        shutter=pParaIn->CaptureShutter;
    } 

    if ((pParaIn->ImageTargetWidth<=MT9P015_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=MT9P015_IMAGE_SENSOR_PV_HEIGHT))
    {

			if (pParaIn->ImageTargetWidth >= 1280 )
				cap_fps = MT9P015CapFps(pParaIn->ZoomFactor,pParaIn->ImageTargetWidth);
			else 
				cap_fps = MT9P015_FPS(30);

			DummyPixel = Mt9p015Sensor.VtClk * MT9P015_FRAME_RATE_UNIT / (MT9P015_PV_PERIOD_LINE_NUMS * cap_fps);
			DummyPixel = DummyPixel < MT9P015_PV_PERIOD_PIXEL_NUMS ? 0 : DummyPixel - MT9P015_PV_PERIOD_PIXEL_NUMS;
#ifdef __MT9P015_DEBUG_TRACE__
			kal_prompt_trace(MOD_ENG, "cap_fps: %d", cap_fps/10);
			kal_prompt_trace(MOD_ENG, "DummyPixel: %d", DummyPixel);
#endif
					
			MT9P015OutputWindow(KAL_TRUE, DummyPixel, 0);	
	
            pParaOut->GrabStartX = MT9P015_PV_X_START;
            pParaOut->GrabStartY = MT9P015_PV_Y_START;
            pParaOut->ExposureWindowWidth = MT9P015_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = MT9P015_IMAGE_SENSOR_PV_HEIGHT;
        }
    
    else  //>1.3M
    {
    #if (defined(DRV_ISP_MT6236_HW_SUPPORT))&&(defined(CAM_OFFLINE_CAPTURE)||defined(CAM_STANDARD_CAPTURE))
#if (defined(CAM_STANDARD_CAPTURE))
		if(pParaIn->ZoomFactor >100)
#endif
		{
		  MT9P015SetClock(MT9P015_CAPTURE_CLK);
		}
#endif
		cap_fps = MT9P015CapFps(pParaIn->ZoomFactor, pParaIn->ImageTargetWidth);
		DummyPixel = Mt9p015Sensor.VtClk * MT9P015_FRAME_RATE_UNIT / (MT9P015_FULL_PERIOD_LINE_NUMS * cap_fps);
		DummyPixel = DummyPixel < MT9P015_FULL_PERIOD_PIXEL_NUMS ? 0 : DummyPixel - MT9P015_FULL_PERIOD_PIXEL_NUMS;
#ifdef __MT9P015_DEBUG_TRACE__
		kal_prompt_trace(MOD_ENG, "cap_fps: %d", cap_fps/10);
		cap_fps = Mt9p015Sensor.VtClk*MT9P015_FRAME_RATE_UNIT/MT9P015_FULL_PERIOD_LINE_NUMS/(MT9P015_FULL_PERIOD_PIXEL_NUMS+DummyPixel);
		kal_prompt_trace(MOD_ENG, "real cap_fps: %d", cap_fps/10);
		kal_prompt_trace(MOD_ENG, "DummyPixel2: %d", DummyPixel);
#endif
		MT9P015OutputWindow(KAL_FALSE, DummyPixel, 0);
        /* shutter translation */  
	  shutter = Mt9p015Sensor.VtClk / (pv_VtClk >> 7) * shutter * pv_LineLength / (Mt9p015Sensor.LineLength << 7);

        pParaOut->GrabStartX = MT9P015_FULL_X_START;
        pParaOut->GrabStartY = MT9P015_FULL_Y_START;
        pParaOut->ExposureWindowWidth = MT9P015_IMAGE_SENSOR_FULL_WIDTH;
        pParaOut->ExposureWindowHeight = MT9P015_IMAGE_SENSOR_FULL_HEIGHT;
    }

   Mt9p015Sensor.CapShutter=shutter;
   MT9P015WriteShutter(shutter);   

   CamWriteCmosSensor(0x0100, 0x01); /* streaMing */

} /* MT9P015Capture() */


void MT9P015GetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
   
    pCaptureInfo->default_pclk=Mt9p015Sensor.VtClk;
    pCaptureInfo->pixels = Mt9p015Sensor.LineLength;
    pCaptureInfo->frame_lines = Mt9p015Sensor.FrameHeight;
    pCaptureInfo->lines = MT9P015_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = Mt9p015Sensor.CapShutter;	 
    
}

static void MT9P015Video(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

#ifdef __MT9P015_DEBUG_TRACE__
		  kal_prompt_trace(MOD_ENG, "MT9P015_preview");
#endif
	  MT9P015SetClock(MT9P015_PREVIEW_CLK);
	  MT9P015SetMirror(pParaIn->ImageMirror);
	  Mt9p015Sensor.DummyLines = 0;

	  MT9P015OutputWindow(KAL_TRUE, 0, Mt9p015Sensor.DummyLines); /* modify DummyPixel must gen AE table again */
	  MT9P015FixVideoFrameRate(pParaIn->MaxVideoFrameRate);
	  
    pParaOut->GrabStartX = MT9P015_PV_X_START;
    pParaOut->GrabStartY = MT9P015_PV_Y_START;
    pParaOut->ExposureWindowWidth = MT9P015_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P015_IMAGE_SENSOR_PV_HEIGHT;

	MT9P015WriteShutter(Mt9p015Sensor.ExposureLines);

}/* MT9P015Preview */


MM_ERROR_CODE_ENUM MT9P015SensorOpen(void)
{
    IspSetInterruptTriggerDelayLines(1);	// 0: VD INT, others: TG INT & start line

    if (MT9P015PowerOn()!= MT9P015_SENSOR_ID)
        return MM_ERROR_SENSOR_READ_ID_FAIL;

	MT9P015InitialSetting();

    return MM_ERROR_NONE;
} /* MT9P015SensorOpen() */


MM_ERROR_CODE_ENUM MT9P015SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    if (FeatureId>=CAL_FEATURE_WEBCAM_BEGIN && FeatureId<=CAL_FEATURE_WEBCAM_END)
    {
        return MT9P015WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                               FeatureParaOutLen, pRealFeatureParaOutLen);
    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {
        /*get*/
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            MT9P015GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;            
        break;        
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=MT9P015DetectSensorId();
        break;
        case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
            MT9P015GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
            MT9P015GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
            MT9P015GetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
            MT9P015GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                                FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=Mt9p015Sensor.VideoCurrentFrameRate;
        break;
        case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            MT9P015InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            MT9P015DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_GAIN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=MT9P015ReadGain();
        break;
        case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 147;
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
            MT9P015GetSensorGroupCount((kal_int32*)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
            MT9P015GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
        break;  
        case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
            MT9P015GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
        break;		
		
		/*set*/
        case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
            MT9P015SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_GAIN:
            MT9P015SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            MT9P015SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        break;
	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamRstPinCtrl(MT9P015SensorIdx, 0);
	    CamPdnPinCtrl(MT9P015SensorIdx, 0);
        break;
        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            pMT9P015NvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
            MT9P015SetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
        break;
		
		
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
            MT9P015NightMode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
            MT9P015SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;

        case CAL_FEATURE_CAMERA_BINNING_INFO:
            ErrorCode=MT9P015BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                             (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // customized by customer
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrorCode=MT9P015StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                         (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // for YUV sensor sample code
        // the following are for YUV sensor only
        case CAL_FEATURE_CAMERA_SHARPNESS:
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
            // Put here just for notifying DD colleagues. Should be removed later for MT9P015. PC Huang 20100903
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        // the above are for YUV sensor only
        case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
            MT9P015CameraParaToSensor(pFeatureParaIn);
        break;
        case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
            MT9P015SensorToCameraPara(pFeatureParaOut);
        break;
        
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* MT9P015SensorFeatureCtrl() */

MM_ERROR_CODE_ENUM MT9P015SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            MT9P015Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_VIDEO:
			MT9P015Video(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            MT9P015Capture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM MT9P015SensorClose(void)
{
    CamRstPinCtrl(MT9P015SensorIdx, 0);
    CisModulePowerOn(MT9P015SensorIdx, KAL_FALSE);
    CameraSccbClose(CAMERA_SCCB_SENSOR);
	
    return MM_ERROR_NONE;
}


IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9P015=
{
    MT9P015SensorOpen,
    MT9P015SensorFeatureCtrl,
    MT9P015SensorCtrl,
    MT9P015SensorClose,
};

MM_ERROR_CODE_ENUM MT9P015SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFuncMT9P015;
}	/* cam_module_func_config() */

