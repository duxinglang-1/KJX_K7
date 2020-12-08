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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"

/* #define __MT9D113_DEBUG_TRACE__ */
/* #define __MT9D113_TEST_PATTERN__ */


struct MT9D113_sensor_STRUCT
{
  kal_uint32 banding;
  kal_uint32 effect;
  kal_uint32 exposure;
  kal_uint32 wb;
  kal_uint8 mirror;
  kal_bool night_mode;
  kal_bool enable_3a;
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_bool pv_mode;
  kal_bool video_mode;
  kal_bool initial;
  kal_bool first_pv;
  kal_uint16 normal_fps; /* normal mode min fps */
  kal_uint16 night_fps; /* night mode min fps */
  kal_uint16 Fps;//add by zhou
#ifndef MT9D113_HW_SCCB
  kal_uint8 write_id;
  kal_uint8 read_id;
#endif
  kal_uint32 pclk;
  kal_uint16 shutter;
  kal_uint16 pv_frame_height;
  kal_uint16 pv_line_length;
  kal_uint16 cap_frame_height;
  kal_uint16 cap_line_length;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
};

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/* FRAME RATE UNIT */
#define MT9D113_FPS(x)                        (10 * (x))
static struct MT9D113_sensor_STRUCT MT9D113_sensor;
static void MT9D113_write_XDMA(kal_uint16 addr, kal_uint16 para);
static void MT9D113_set_cmd(kal_uint16 cmd);
//static kal_uint32 MT9D113_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para);


/*************************************************************************
* FUNCTION
*    MT9D113_half_adjust
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
__inline static kal_uint16 MT9D113_half_adjust(kal_uint32 dividend, kal_uint32 divisor)
{
  return ((dividend * 2 + divisor) / (divisor * 2)); /* that is [dividend / divisor + 0.5]*/
}



/*************************************************************************
* FUNCTION
*    MT9D113SetMirror
*
* DESCRIPTION
*    This function set the mirror to the CMOS sensor
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
	static void MT9D113_config_context(void)
	{
	  /* Register wizard */
	  CamWriteCmosSensor(0x98C, 0x2703); /* Output Width(A) */
	  CamWriteCmosSensor(0x990, 0x0320); /* 800 */
	  CamWriteCmosSensor(0x98C, 0x2705); /* Output Height(A) */
	  CamWriteCmosSensor(0x990, 0x0258); /* 600 */
	  CamWriteCmosSensor(0x98C, 0x2707); /* Output Width(B) */
	  CamWriteCmosSensor(0x990, 0x0640); /* 1600 */
	  CamWriteCmosSensor(0x98C, 0x2709); /* Output Height(B) */
	  CamWriteCmosSensor(0x990, 0x04B0); /* 1200 */
	  CamWriteCmosSensor(0x98C, 0x270D); /* Row Start(A) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x270F); /* Column Start(A) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x2711); /* Row End(A) */
	  CamWriteCmosSensor(0x990, 0x04BD); /* 1213 */
	  CamWriteCmosSensor(0x98C, 0x2713); /* Column End(A) */
	  CamWriteCmosSensor(0x990, 0x064D); /* 1613 */
	  CamWriteCmosSensor(0x98C, 0x2715); /* Row Speed(A) */
	  CamWriteCmosSensor(0x990, 0x0111); /* 273 */
	  CamWriteCmosSensor(0x98C, 0x2719); /* sensor_fine_correction(A) */
	  CamWriteCmosSensor(0x990, 0x005A); /* 90 */
	  CamWriteCmosSensor(0x98C, 0x271B); /* sensor_fine_IT_min(A) */
	  CamWriteCmosSensor(0x990, 0x01BE); /* 446 */
	  CamWriteCmosSensor(0x98C, 0x271D); /* sensor_fine_IT_max_margin(A) */
	  CamWriteCmosSensor(0x990, 0x0131); /* 305 */
	  CamWriteCmosSensor(0x98C, 0x2723); /* Row Start(B) */
	  CamWriteCmosSensor(0x990, 0x0004); /* 4 */
	  CamWriteCmosSensor(0x98C, 0x2725); /* Column Start(B) */
	  CamWriteCmosSensor(0x990, 0x0004); /* 4 */
	  CamWriteCmosSensor(0x98C, 0x2727); /* Row End(B) */
	  CamWriteCmosSensor(0x990, 0x04BB); /* 1211 */
	  CamWriteCmosSensor(0x98C, 0x2729); /* Column End(B) */
	  CamWriteCmosSensor(0x990, 0x064B); /* 1611 */
	  CamWriteCmosSensor(0x98C, 0x272B); /* Row Speed(B) */
	  CamWriteCmosSensor(0x990, 0x0111); /* 273 */
	  CamWriteCmosSensor(0x98C, 0x272F); /* sensor_fine_correction(B) */
	  CamWriteCmosSensor(0x990, 0x003A); /* 58 */
	  CamWriteCmosSensor(0x98C, 0x2731); /* sensor_fine_IT_min(B) */
	  CamWriteCmosSensor(0x990, 0x00F6); /* 246 */
	  CamWriteCmosSensor(0x98C, 0x2733); /* sensor_fine_IT_max_margin(B) */
	  CamWriteCmosSensor(0x990, 0x008B); /* 139 */
	  CamWriteCmosSensor(0x98C, 0x2739); /* Crop_X0(A) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x273B); /* Crop_X1(A) */
	  CamWriteCmosSensor(0x990, 0x031F); /* 799 */
	  CamWriteCmosSensor(0x98C, 0x273D); /* Crop_Y0(A) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x273F); /* Crop_Y1(A) */
	  CamWriteCmosSensor(0x990, 0x0257); /* 599 */
	  CamWriteCmosSensor(0x98C, 0x2747); /* Crop_X0(B) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x2749); /* Crop_X1(B) */
	  CamWriteCmosSensor(0x990, 0x063F); /* 1599 */
	  CamWriteCmosSensor(0x98C, 0x274B); /* Crop_Y0(B) */
	  CamWriteCmosSensor(0x990, 0x0000); /* 0 */
	  CamWriteCmosSensor(0x98C, 0x274D); /* Crop_Y1(B) */
	  CamWriteCmosSensor(0x990, 0x04AF); /* 1199 */
	  /* no need config search_f1/f2_50/60, for they use in auto FD!!! */
	  CamWriteCmosSensor(0x98C, 0xA404); /* FD Mode */
	  CamWriteCmosSensor(0x990, 0x10  ); /* 16 */
	  CamWriteCmosSensor(0x98C, 0xA40D); /* Stat_min */
	  CamWriteCmosSensor(0x990, 0x02  ); /* 2 */
	  CamWriteCmosSensor(0x98C, 0xA40E); /* Stat_max */
	  CamWriteCmosSensor(0x990, 0x03  ); /* 3 */
	  CamWriteCmosSensor(0x98C, 0xA410); /* Min_amplitude */
	  CamWriteCmosSensor(0x990, 0x0A  ); /* 10 */
	}
static void MT9D113_set_pv_dummy(kal_uint16 dummy_pixel, kal_uint16 dummy_line)
{
  const kal_uint16 frame_height = MT9D113_PV_PERIOD_LINE_NUMS + dummy_line;
  const kal_uint16 line_length = MT9D113_PV_PERIOD_PIXEL_NUMS + dummy_pixel;
  
  if (MT9D113_sensor.pv_frame_height == frame_height && MT9D113_sensor.pv_line_length == line_length) return;
  MT9D113_sensor.pv_frame_height = frame_height;
  MT9D113_sensor.pv_line_length = line_length;
  MT9D113_write_XDMA(0x271F, frame_height); /* preview frame length */
  MT9D113_write_XDMA(0x2721, line_length); /* preview line length */
  MT9D113_write_XDMA(0x2411, MT9D113_half_adjust(MT9D113_sensor.pclk / 2, line_length * MT9D113_NUM_60HZ * 2));/* preview fd_r9_step_f60 */
  MT9D113_write_XDMA(0x2413, MT9D113_half_adjust(MT9D113_sensor.pclk / 2, line_length * MT9D113_NUM_50HZ * 2));/* preview fd_r9_step_f50 */
  MT9D113_set_cmd(6); /* refresh mode */
}

/*************************************************************************
* FUNCTION
*    MT9D113_cal_fps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER MT9D113_preview() !!!
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
static void MT9D113_cal_fps(void)
{
  const kal_uint16 dummy_pixel = MT9D113_sensor.pv_line_length - MT9D113_PV_PERIOD_PIXEL_NUMS;
  const kal_uint8 banding = MT9D113_sensor.banding == CAM_BANDING_50HZ ? MT9D113_NUM_50HZ : MT9D113_NUM_60HZ;
  const kal_uint16 pv_max_fps = MT9D113_sensor.pclk * MT9D113_FPS(1) / (2 * MT9D113_sensor.pv_line_length * MT9D113_sensor.pv_frame_height);
  kal_uint16 pv_min_fps = MT9D113_sensor.Fps;//.night_mode ? MT9D113_sensor.night_fps : MT9D113_sensor.normal_fps;
  kal_uint16 max_exposure_lines;
  
  if (pv_min_fps > pv_max_fps) pv_min_fps = pv_max_fps;
  if (MT9D113_sensor.video_mode) /* fix frame rate when video mode */
  {
    max_exposure_lines = MT9D113_sensor.pclk * MT9D113_FPS(1) / (2 * pv_min_fps * MT9D113_sensor.pv_line_length);
    MT9D113_set_pv_dummy(dummy_pixel, max_exposure_lines - MT9D113_PV_PERIOD_LINE_NUMS);
  }
  MT9D113_write_XDMA(0xA20C, banding * 2 * MT9D113_FPS(1) / pv_min_fps);
  MT9D113_set_cmd(5); /* refresh */
}

/*************************************************************************
* FUNCTION
*    MT9D113_set_cap_dummy
*
* DESCRIPTION
*    This function add dummy_pixel and dummy_line in capture state.
*    MUST BE INVOKED BEFORE MT9D113_set_cmd(2) !!!
*
* PARAMETERS
*    dummy_pixel
*    dummy_line
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113_set_cap_dummy(kal_uint16 dummy_pixel, kal_uint16 dummy_line)
{
  const kal_uint16 frame_height = MT9D113_FULL_PERIOD_LINE_NUMS + dummy_line;
  const kal_uint16 line_length = MT9D113_FULL_PERIOD_PIXEL_NUMS + dummy_pixel;
  
  if (MT9D113_sensor.cap_frame_height == frame_height && MT9D113_sensor.cap_line_length == line_length) return;
  MT9D113_sensor.cap_frame_height = frame_height;
  MT9D113_sensor.cap_line_length = line_length;
  MT9D113_write_XDMA(0x2735, frame_height); /* snapshot/video frame length */
  MT9D113_write_XDMA(0x2737, line_length); /* snapshot/video line length */
  MT9D113_write_XDMA(0x2415, MT9D113_half_adjust(MT9D113_sensor.pclk / 2, line_length * MT9D113_NUM_60HZ * 2));/* snapshot/video fd_r9_step_f60 */
  MT9D113_write_XDMA(0x2417, MT9D113_half_adjust(MT9D113_sensor.pclk / 2, line_length * MT9D113_NUM_50HZ * 2));/* snapshot/video fd_r9_step_f50 */
  MT9D113_set_cmd(6); /* refresh mode */
}
/*************************************************************************
* FUNCTION
*    MT9D113_LSC_setting
*
* DESCRIPTION
*    This function set Lens Shading Correction.
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
static void MT9D113_LSC_setting(void)
{
  /* [Register Log 12/22/08 16:42:15] */
  CamWriteCmosSensor(0x3658, 0x00B0); /* P_RD_P0Q0 */
  CamWriteCmosSensor(0x365A, 0xB3A8); /* P_RD_P0Q1 */
  CamWriteCmosSensor(0x365C, 0x4992); /* P_RD_P0Q2 */
  CamWriteCmosSensor(0x365E, 0xA74D); /* P_RD_P0Q3 */
  CamWriteCmosSensor(0x3660, 0x9C93); /* P_RD_P0Q4 */
  CamWriteCmosSensor(0x3680, 0x872D); /* P_RD_P1Q0 */
  CamWriteCmosSensor(0x3682, 0x1E50); /* P_RD_P1Q1 */
  CamWriteCmosSensor(0x3684, 0xD7D0); /* P_RD_P1Q2 */
  CamWriteCmosSensor(0x3686, 0xE352); /* P_RD_P1Q3 */
  CamWriteCmosSensor(0x3688, 0x2832); /* P_RD_P1Q4 */
  CamWriteCmosSensor(0x36A8, 0x27B3); /* P_RD_P2Q0 */
  CamWriteCmosSensor(0x36AA, 0x5FF0); /* P_RD_P2Q1 */
  CamWriteCmosSensor(0x36AC, 0x7C70); /* P_RD_P2Q2 */
  CamWriteCmosSensor(0x36AE, 0xD894); /* P_RD_P2Q3 */
  CamWriteCmosSensor(0x36B0, 0xEDB7); /* P_RD_P2Q4 */
  CamWriteCmosSensor(0x36D0, 0xE6CF); /* P_RD_P3Q0 */
  CamWriteCmosSensor(0x36D2, 0x9731); /* P_RD_P3Q1 */
  CamWriteCmosSensor(0x36D4, 0x69D4); /* P_RD_P3Q2 */
  CamWriteCmosSensor(0x36D6, 0x2B34); /* P_RD_P3Q3 */
  CamWriteCmosSensor(0x36D8, 0x9BB6); /* P_RD_P3Q4 */
  CamWriteCmosSensor(0x36F8, 0xB714); /* P_RD_P4Q0 */
  CamWriteCmosSensor(0x36FA, 0xC9F4); /* P_RD_P4Q1 */
  CamWriteCmosSensor(0x36FC, 0xA7F9); /* P_RD_P4Q2 */
  CamWriteCmosSensor(0x36FE, 0x39D8); /* P_RD_P4Q3 */
  CamWriteCmosSensor(0x3700, 0x2ADC); /* P_RD_P4Q4 */
  CamWriteCmosSensor(0x364E, 0x0630); /* P_GR_P0Q0 */
  CamWriteCmosSensor(0x3650, 0x0DEB); /* P_GR_P0Q1 */
  CamWriteCmosSensor(0x3652, 0x1772); /* P_GR_P0Q2 */
  CamWriteCmosSensor(0x3654, 0x824E); /* P_GR_P0Q3 */
  CamWriteCmosSensor(0x3656, 0x99F3); /* P_GR_P0Q4 */
  CamWriteCmosSensor(0x3676, 0xE98C); /* P_GR_P1Q0 */
  CamWriteCmosSensor(0x3678, 0x8230); /* P_GR_P1Q1 */
  CamWriteCmosSensor(0x367A, 0x81B1); /* P_GR_P1Q2 */
  CamWriteCmosSensor(0x367C, 0x6D71); /* P_GR_P1Q3 */
  CamWriteCmosSensor(0x367E, 0x7CF2); /* P_GR_P1Q4 */
  CamWriteCmosSensor(0x369E, 0x0B53); /* P_GR_P2Q0 */
  CamWriteCmosSensor(0x36A0, 0x2370); /* P_GR_P2Q1 */
  CamWriteCmosSensor(0x36A2, 0xCA74); /* P_GR_P2Q2 */
  CamWriteCmosSensor(0x36A4, 0x9774); /* P_GR_P2Q3 */
  CamWriteCmosSensor(0x36A6, 0x9234); /* P_GR_P2Q4 */
  CamWriteCmosSensor(0x36C6, 0xCD6F); /* P_GR_P3Q0 */
  CamWriteCmosSensor(0x36C8, 0x9FD0); /* P_GR_P3Q1 */
  CamWriteCmosSensor(0x36CA, 0x70D4); /* P_GR_P3Q2 */
  CamWriteCmosSensor(0x36CC, 0x64F4); /* P_GR_P3Q3 */
  CamWriteCmosSensor(0x36CE, 0x98F6); /* P_GR_P3Q4 */
  CamWriteCmosSensor(0x36EE, 0xA914); /* P_GR_P4Q0 */
  CamWriteCmosSensor(0x36F0, 0x98B4); /* P_GR_P4Q1 */
  CamWriteCmosSensor(0x36F2, 0xA138); /* P_GR_P4Q2 */
  CamWriteCmosSensor(0x36F4, 0x77D7); /* P_GR_P4Q3 */
  CamWriteCmosSensor(0x36F6, 0x4E5B); /* P_GR_P4Q4 */
  CamWriteCmosSensor(0x3662, 0x00D0); /* P_BL_P0Q0 */
  CamWriteCmosSensor(0x3664, 0x04E9); /* P_BL_P0Q1 */
  CamWriteCmosSensor(0x3666, 0x0572); /* P_BL_P0Q2 */
  CamWriteCmosSensor(0x3668, 0x28AC); /* P_BL_P0Q3 */
  CamWriteCmosSensor(0x366A, 0x84D3); /* P_BL_P0Q4 */
  CamWriteCmosSensor(0x368A, 0x90ED); /* P_BL_P1Q0 */
  CamWriteCmosSensor(0x368C, 0xDA0F); /* P_BL_P1Q1 */
  CamWriteCmosSensor(0x368E, 0xD42F); /* P_BL_P1Q2 */
  CamWriteCmosSensor(0x3690, 0x6691); /* P_BL_P1Q3 */
  CamWriteCmosSensor(0x3692, 0x5430); /* P_BL_P1Q4 */
  CamWriteCmosSensor(0x36B2, 0x0A13); /* P_BL_P2Q0 */
  CamWriteCmosSensor(0x36B4, 0x2A0E); /* P_BL_P2Q1 */
  CamWriteCmosSensor(0x36B6, 0xC054); /* P_BL_P2Q2 */
  CamWriteCmosSensor(0x36B8, 0x9513); /* P_BL_P2Q3 */
  CamWriteCmosSensor(0x36BA, 0x8635); /* P_BL_P2Q4 */
  CamWriteCmosSensor(0x36DA, 0x7F2D); /* P_BL_P3Q0 */
  CamWriteCmosSensor(0x36DC, 0xE690); /* P_BL_P3Q1 */
  CamWriteCmosSensor(0x36DE, 0x1DB3); /* P_BL_P3Q2 */
  CamWriteCmosSensor(0x36E0, 0x63D4); /* P_BL_P3Q3 */
  CamWriteCmosSensor(0x36E2, 0x09F3); /* P_BL_P3Q4 */
  CamWriteCmosSensor(0x3702, 0xB634); /* P_BL_P4Q0 */
  CamWriteCmosSensor(0x3704, 0xAFF3); /* P_BL_P4Q1 */
  CamWriteCmosSensor(0x3706, 0xA8D8); /* P_BL_P4Q2 */
  CamWriteCmosSensor(0x3708, 0x29B7); /* P_BL_P4Q3 */
  CamWriteCmosSensor(0x370A, 0x5F9B); /* P_BL_P4Q4 */
  CamWriteCmosSensor(0x366C, 0x0170); /* P_GB_P0Q0 */
  CamWriteCmosSensor(0x366E, 0x034A); /* P_GB_P0Q1 */
  CamWriteCmosSensor(0x3670, 0x1192); /* P_GB_P0Q2 */
  CamWriteCmosSensor(0x3672, 0xBACD); /* P_GB_P0Q3 */
  CamWriteCmosSensor(0x3674, 0x9EB3); /* P_GB_P0Q4 */
  CamWriteCmosSensor(0x3694, 0xCAAC); /* P_GB_P1Q0 */
  CamWriteCmosSensor(0x3696, 0x7A6F); /* P_GB_P1Q1 */
  CamWriteCmosSensor(0x3698, 0xB210); /* P_GB_P1Q2 */
  CamWriteCmosSensor(0x369A, 0xF191); /* P_GB_P1Q3 */
  CamWriteCmosSensor(0x369C, 0x02B2); /* P_GB_P1Q4 */
  CamWriteCmosSensor(0x36BC, 0x0FF3); /* P_GB_P2Q0 */
  CamWriteCmosSensor(0x36BE, 0x0B6F); /* P_GB_P2Q1 */
  CamWriteCmosSensor(0x36C0, 0xD794); /* P_GB_P2Q2 */
  CamWriteCmosSensor(0x36C2, 0xD813); /* P_GB_P2Q3 */
  CamWriteCmosSensor(0x36C4, 0xCED2); /* P_GB_P2Q4 */
  CamWriteCmosSensor(0x36E4, 0x974D); /* P_GB_P3Q0 */
  CamWriteCmosSensor(0x36E6, 0x1991); /* P_GB_P3Q1 */
  CamWriteCmosSensor(0x36E8, 0x2074); /* P_GB_P3Q2 */
  CamWriteCmosSensor(0x36EA, 0xE054); /* P_GB_P3Q3 */
  CamWriteCmosSensor(0x36EC, 0x9FB5); /* P_GB_P3Q4 */
  CamWriteCmosSensor(0x370C, 0xB254); /* P_GB_P4Q0 */
  CamWriteCmosSensor(0x370E, 0xA493); /* P_GB_P4Q1 */
  CamWriteCmosSensor(0x3710, 0x9B18); /* P_GB_P4Q2 */
  CamWriteCmosSensor(0x3712, 0x3C37); /* P_GB_P4Q3 */
  CamWriteCmosSensor(0x3714, 0x43FB); /* P_GB_P4Q4 */
  CamWriteCmosSensor(0x3644, 0x0320); /* POLY_ORIGIN_C */
  CamWriteCmosSensor(0x3642, 0x0258); /* POLY_ORIGIN_R */
  CamWriteCmosSensor(0x3210, 0x01B8); /* COLOR_PIPELINE_CONTROL */
  CamWriteCmosSensor(0x3644, 0x0324); /* POLY_ORIGIN_C */
  CamWriteCmosSensor(0x3642, 0x025C); /* POLY_ORIGIN_R */
}
/*************************************************************************
* FUNCTION
*    MT9D113_burst_write_XDMA
*
* DESCRIPTION
*    This function burst wirte XDMA to CMOS sensor through I2C
*    MT9D113_MAX_I2C_FAIL_TRY_NO is the max try number. when write fail, the function retry again until
*    try times reach MT9D113_MAX_I2C_FAIL_TRY_NO.
*
* PARAMETERS
*    addr    : the 16bit address of register
*    data    : pointer of data
*    len      : length of data
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113_burst_write_XDMA(kal_uint16 addr, const kal_uint16 *data, kal_uint16 len)
{
  kal_uint16 i, j = 0;
  
  for (i = 0; i < len; i++, j += 2)
  {
    if (!(i&7))
    {
      j = 0;
      CamWriteCmosSensor(0x098C, addr + i * 2);
    }
    CamWriteCmosSensor(0x0990 + j, data[i]);
  }
}

/*************************************************************************
* FUNCTION
*    MT9D113_cap_fps
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
static kal_uint16 MT9D113_cap_fps(kal_uint32 zoom_factor, kal_uint32 image_width)
{
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT)) /* MT6253 */
  return MT9D113_FPS(9); /* only support 9 fps */
#else
  kal_uint16 cap_fps, i = 0;

  static const kal_uint16 _cap_fps[5][4] =
  {
    /* 1x, (1x, 2x], (2x,4x], (4x,8x] */
#if (defined(DRV_ISP_MT6236_HW_SUPPORT)||defined(MT6276)) /* MT6236 */
    {MT9D113_FPS(15),MT9D113_FPS(15),MT9D113_FPS(12.7),MT9D113_FPS(11.8)}, /* 1M */
    {MT9D113_FPS(15),MT9D113_FPS(15),MT9D113_FPS(8),MT9D113_FPS(7.5)}, /* 2M */
    {MT9D113_FPS(15),MT9D113_FPS(9.2),MT9D113_FPS(4.8),MT9D113_FPS(4.4)}, /* 3M */
#elif (defined(DRV_ISP_6238_SERIES))  /* MT6238/39/68 */
    {MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(13)}, /* 1M */
    {MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(9.4),MT9D113_FPS(8.7)}, /* 2M */
    {MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(5.7),MT9D113_FPS(5.2)}, /* 3M */
#elif (defined(DRV_ISP_6235_SERIES)) /* MT6235 */
    {MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(0)}, /* 1M */
    {MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(5.8),MT9D113_FPS(0)}, /* 2M */
    {MT9D113_FPS(13),MT9D113_FPS(6.8),MT9D113_FPS(3.5),MT9D113_FPS(0)}, /* 3M */
#else
	{MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(0)}, /* 1M */
	{MT9D113_FPS(13),MT9D113_FPS(13),MT9D113_FPS(5.8),MT9D113_FPS(0)}, /* 2M */
	{MT9D113_FPS(13),MT9D113_FPS(6.8),MT9D113_FPS(3.5),MT9D113_FPS(0)}, /* 3M */

#endif

  };
  
  
#if (!defined(DRV_ISP_6238_SERIES))
  zoom_factor *= 10;
#endif
  if (image_width >= 2048) /* 3M */
  {
    i = 2;
  }
  else if (image_width >= 1600) /* 2M */
  {
    i = 1;
  }
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
  else
  {
    cap_fps = _cap_fps[i][0]; /* 1x */
  }
  return cap_fps;
#endif
}

static kal_uint16 MT9D113_gain2shutter(kal_bool enable)
{
  static kal_uint16 gain_r, gain_gr, gain_gb, gain_b;
  kal_uint8 mul = 2; /* multiple of gain */
  
  if (enable)
  {
    gain_gr = CamReadCmosSensor(0x32D6);
    /* convert digital gain(isp gain. sensor core digital gain no use) */
    while (gain_gr >= mul * 0x80) mul++;
    if (--mul > 1)
    {
      gain_r = CamReadCmosSensor(0x32D4);
      gain_gb = CamReadCmosSensor(0x32D8);
      gain_b = CamReadCmosSensor(0x32DA);
      CamWriteCmosSensor(0x32D4, MT9D113_half_adjust(gain_r, mul));
      CamWriteCmosSensor(0x32D6, MT9D113_half_adjust(gain_gr, mul));
      CamWriteCmosSensor(0x32D8, MT9D113_half_adjust(gain_gr, mul));
      CamWriteCmosSensor(0x32DA, MT9D113_half_adjust(gain_b * gain_gr, mul * gain_gb));
      
      return mul;
    }
    gain_gr = 0;
  }
  if (gain_r)  CamWriteCmosSensor(0x32D4, gain_r);
  if (gain_gr) CamWriteCmosSensor(0x32D6, gain_gr);
  if (gain_gb) CamWriteCmosSensor(0x32D8, gain_gr);
  if (gain_b)  CamWriteCmosSensor(0x32DA, gain_b);
  gain_r = gain_gr = gain_gb = gain_b = 0;
  
  return 1;
}



/*************************************************************************
* FUNCTION
*    MT9D113_read_XDMA
*
* DESCRIPTION
*    This function read XDMA
*
* PARAMETERS
*    addr    : the 16bit address of XDMA
*
* RETURNS
*    The 16bit data frome XDMA
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 MT9D113_read_XDMA(kal_uint16 addr)
{
  CamWriteCmosSensor(0x098C, addr);
  return CamReadCmosSensor(0x0990);
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
#endif
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
#endif 

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
#endif


static void MT9D113AeEnable(kal_bool Enable)
{


	if (MT9D113_sensor.BypassAe)
	{
		Enable = KAL_FALSE;
	}

	if (Enable)
	{
		MT9D113_write_XDMA(0xA11D, 2);
		MT9D113_write_XDMA(0xA11E, 2);
		MT9D113_sensor.BypassAe = KAL_TRUE;
	}
	else
	{
		MT9D113_write_XDMA(0xA11D, 0);
		MT9D113_write_XDMA(0xA11E, 0);
		MT9D113_sensor.BypassAe = KAL_FALSE;
	}
	MT9D113_set_cmd(6); /* refresh mode */
}

static void MT9D113AwbEnable(kal_bool Enable)
{


	if (MT9D113_sensor.BypassAwb)
	{
		Enable = KAL_FALSE;
	}

	if (Enable)
	{
		MT9D113_write_XDMA(0xA11F, 1);
		MT9D113_write_XDMA(0xA120, 1);
		MT9D113_sensor.BypassAwb = KAL_TRUE;
	}
	else
	{
		MT9D113_write_XDMA(0xA11F, 0);
		MT9D113_write_XDMA(0xA120, 0);
		MT9D113_sensor.BypassAwb = KAL_FALSE;
	}
	MT9D113_set_cmd(6); /* refresh mode */
}

/*************************************************************************
* FUNCTION
*    MT9D113_set_param_3a_enable
*
* DESCRIPTION
*    disable/enable 3a
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
static kal_uint32 MT9D113_set_param_3a_enable(kal_uint32 para)
{
  kal_uint8 seq_preview_1_ae, seq_preview_1_fd, seq_preview_1_awb, seq_preview_1_hg;
  
  if (MT9D113_sensor.enable_3a == para) return KAL_TRUE;
  MT9D113_sensor.enable_3a = para;
  if (MT9D113_sensor.enable_3a)
  {
    seq_preview_1_ae = seq_preview_1_fd = 2;
    seq_preview_1_awb = seq_preview_1_hg = 1;
  }
  else
  {
    seq_preview_1_ae = seq_preview_1_fd = seq_preview_1_awb = seq_preview_1_hg = 0;
  }
  MT9D113_write_XDMA(0xA11D, seq_preview_1_ae);
  MT9D113_write_XDMA(0xA11E, seq_preview_1_fd);
  MT9D113_write_XDMA(0xA11F, seq_preview_1_awb);
  MT9D113_write_XDMA(0xA120, seq_preview_1_hg);
  MT9D113_set_cmd(6); /* refresh mode */
  
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
*    MT9D113_night_mode
*
* DESCRIPTION
*    This function night mode of MT9D113.
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
static void MT9D113_night_mode(kal_bool enable)
{
  kal_uint8 y_rgb_offset, awb_gain_max_r;
  kal_uint16 limit_of_digital_gain;
  
  if (MT9D113_sensor.night_mode == enable && !MT9D113_sensor.video_mode) return;
  MT9D113_sensor.night_mode = enable;
  if (MT9D113_sensor.night_mode)
  {
    MT9D113_write_XDMA(0xAB37, 0x02); /* use GAMMA TABLE B */
    y_rgb_offset = 20;
    awb_gain_max_r = 0xA0;
    limit_of_digital_gain = 0x0100;
  }
  else
  {
    MT9D113_write_XDMA(0xAB37, 0x01); /* use GAMMA TABLE A */
    y_rgb_offset = 0;
    awb_gain_max_r = 0xC8;
    limit_of_digital_gain = 0x00EE;
  }
  MT9D113_write_XDMA(0x2212, limit_of_digital_gain);
  MT9D113_write_XDMA(0xA34B, awb_gain_max_r);
  MT9D113_write_XDMA(0xA75D, y_rgb_offset); /* mode_y_rgb_offset_a */
  MT9D113_write_XDMA(0xA75E, y_rgb_offset); /* mode_y_rgb_offset_b */
  
  MT9D113_cal_fps(); /* need cal new fps */
}

/*************************************************************************
* FUNCTION
*    MT9D113_set_param_nightmode
*
* DESCRIPTION
*    night mode setting.
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
static kal_uint32 MT9D113_set_param_nightmode(kal_uint32 para)
{
  MT9D113_night_mode((kal_bool)para);
  
  return KAL_TRUE;
}





/*************************************************************************
* FUNCTION
*    MT9D113_gamma_setting
*
* DESCRIPTION
*    This function set two context of gamma.
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
static void MT9D113_gamma_setting(void)
{
  CamWriteCmosSensor(0x098C, 0xAB3C); /* HG_GAMMA_TABLE_A_0 */
  CamWriteCmosSensor(0x0990, 0x0000); /* #24 */
  CamWriteCmosSensor(0x098C, 0xAB3D); /* HG_GAMMA_TABLE_A_1 */
  CamWriteCmosSensor(0x0990, 0x0010); /* #23 */
  CamWriteCmosSensor(0x098C, 0xAB3E); /* HG_GAMMA_TABLE_A_2 */
  CamWriteCmosSensor(0x0990, 0x002E); /* #22 */
  CamWriteCmosSensor(0x098C, 0xAB3F); /* HG_GAMMA_TABLE_A_3 */
  CamWriteCmosSensor(0x0990, 0x004C); /* #21 */
  CamWriteCmosSensor(0x098C, 0xAB40); /* HG_GAMMA_TABLE_A_4 */
  CamWriteCmosSensor(0x0990, 0x0078); /* #20 */
  CamWriteCmosSensor(0x098C, 0xAB41); /* HG_GAMMA_TABLE_A_5 */
  CamWriteCmosSensor(0x0990, 0x0098); /* #19 */
  CamWriteCmosSensor(0x098C, 0xAB42); /* HG_GAMMA_TABLE_A_6 */
  CamWriteCmosSensor(0x0990, 0x00B0);
  CamWriteCmosSensor(0x098C, 0xAB43); /* HG_GAMMA_TABLE_A_7 */
  CamWriteCmosSensor(0x0990, 0x00C1);
  CamWriteCmosSensor(0x098C, 0xAB44); /* HG_GAMMA_TABLE_A_8 */
  CamWriteCmosSensor(0x0990, 0x00CF);
  CamWriteCmosSensor(0x098C, 0xAB45); /* HG_GAMMA_TABLE_A_9 */
  CamWriteCmosSensor(0x0990, 0x00D9);
  CamWriteCmosSensor(0x098C, 0xAB46); /* HG_GAMMA_TABLE_A_10 */
  CamWriteCmosSensor(0x0990, 0x00E1);
  CamWriteCmosSensor(0x098C, 0xAB47); /* HG_GAMMA_TABLE_A_11 */
  CamWriteCmosSensor(0x0990, 0x00E8);
  CamWriteCmosSensor(0x098C, 0xAB48); /* HG_GAMMA_TABLE_A_12 */
  CamWriteCmosSensor(0x0990, 0x00EE);
  CamWriteCmosSensor(0x098C, 0xAB49); /* HG_GAMMA_TABLE_A_13 */
  CamWriteCmosSensor(0x0990, 0x00F2);
  CamWriteCmosSensor(0x098C, 0xAB4A); /* HG_GAMMA_TABLE_A_14 */
  CamWriteCmosSensor(0x0990, 0x00F6);
  CamWriteCmosSensor(0x098C, 0xAB4B); /* HG_GAMMA_TABLE_A_15 */
  CamWriteCmosSensor(0x0990, 0x00F9);
  CamWriteCmosSensor(0x098C, 0xAB4C); /* HG_GAMMA_TABLE_A_16 */
  CamWriteCmosSensor(0x0990, 0x00FB);
  CamWriteCmosSensor(0x098C, 0xAB4D); /* HG_GAMMA_TABLE_A_17 */
  CamWriteCmosSensor(0x0990, 0x00FD);
  CamWriteCmosSensor(0x098C, 0xAB4E); /* HG_GAMMA_TABLE_A_18 */
  CamWriteCmosSensor(0x0990, 0x00FF);

  CamWriteCmosSensor(0x098C, 0xAB4F); /* HG_GAMMA_TABLE_B_0 */
  CamWriteCmosSensor(0x0990, 0x0000); /* #24 */
  CamWriteCmosSensor(0x098C, 0xAB50); /* HG_GAMMA_TABLE_B_1 */
  CamWriteCmosSensor(0x0990, 0x0002); /* #23 */
  CamWriteCmosSensor(0x098C, 0xAB51); /* HG_GAMMA_TABLE_B_2 */
  CamWriteCmosSensor(0x0990, 0x0010); /* #22 */
  CamWriteCmosSensor(0x098C, 0xAB52); /* HG_GAMMA_TABLE_B_3 */
  CamWriteCmosSensor(0x0990, 0x002E); /* #21 */
  CamWriteCmosSensor(0x098C, 0xAB53); /* HG_GAMMA_TABLE_B_4 */
  CamWriteCmosSensor(0x0990, 0x005A); /* #20 */
  CamWriteCmosSensor(0x098C, 0xAB54); /* HG_GAMMA_TABLE_B_5 */
  CamWriteCmosSensor(0x0990, 0x006A); /* #19 */
  CamWriteCmosSensor(0x098C, 0xAB55); /* HG_GAMMA_TABLE_B_6 */
  CamWriteCmosSensor(0x0990, 0x0080);
  CamWriteCmosSensor(0x098C, 0xAB56); /* HG_GAMMA_TABLE_B_7 */
  CamWriteCmosSensor(0x0990, 0x0091);
  CamWriteCmosSensor(0x098C, 0xAB57); /* HG_GAMMA_TABLE_B_8 */
  CamWriteCmosSensor(0x0990, 0x00A1);
  CamWriteCmosSensor(0x098C, 0xAB58); /* HG_GAMMA_TABLE_B_9 */
  CamWriteCmosSensor(0x0990, 0x00AF);
  CamWriteCmosSensor(0x098C, 0xAB59); /* HG_GAMMA_TABLE_B_10 */
  CamWriteCmosSensor(0x0990, 0x00BB);
  CamWriteCmosSensor(0x098C, 0xAB5A); /* HG_GAMMA_TABLE_B_11 */
  CamWriteCmosSensor(0x0990, 0x00C6);
  CamWriteCmosSensor(0x098C, 0xAB5B); /* HG_GAMMA_TABLE_B_12 */
  CamWriteCmosSensor(0x0990, 0x00D0);
  CamWriteCmosSensor(0x098C, 0xAB5C); /* HG_GAMMA_TABLE_B_13 */
  CamWriteCmosSensor(0x0990, 0x00D9);
  CamWriteCmosSensor(0x098C, 0xAB5D); /* HG_GAMMA_TABLE_B_14 */
  CamWriteCmosSensor(0x0990, 0x00E2);
  CamWriteCmosSensor(0x098C, 0xAB5E); /* HG_GAMMA_TABLE_B_15 */
  CamWriteCmosSensor(0x0990, 0x00EA);
  CamWriteCmosSensor(0x098C, 0xAB5F); /* HG_GAMMA_TABLE_B_16 */
  CamWriteCmosSensor(0x0990, 0x00F1);
  CamWriteCmosSensor(0x098C, 0xAB60); /* HG_GAMMA_TABLE_B_17 */
  CamWriteCmosSensor(0x0990, 0x00F9);
  CamWriteCmosSensor(0x098C, 0xAB61); /* HG_GAMMA_TABLE_B_18 */
  CamWriteCmosSensor(0x0990, 0x00FF);
}
/*************************************************************************
* FUNCTION
*    MT9D113_low_light
*
* DESCRIPTION
*    This function set low light performance.
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
static void MT9D113_low_light(void)
{
  CamWriteCmosSensor(0x098C, 0x2B1B); /* HG_BRIGHTNESSMETRIC */
  CamWriteCmosSensor(0x0990, 0x392D);
  CamWriteCmosSensor(0x098C, 0x2B1D); /* HG_LASTBRIGHTNESSMETRIC */
  CamWriteCmosSensor(0x0990, 0x392D);
  CamWriteCmosSensor(0x098C, 0xAB1F); /* HG_LLMODE */
  CamWriteCmosSensor(0x0990, 0x00C5);
  /* saturation setting: 0xAB20*/
  CamWriteCmosSensor(0x098C, 0xAB20); /* HG_LL_SAT1 */
#if (defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_YUV_BURST_MODE_SUPPORT)||defined(MT6276))
  CamWriteCmosSensor(0x0990, 0x003B);
#else
  CamWriteCmosSensor(0x0990, 0x0043);
#endif
  CamWriteCmosSensor(0x098C, 0xAB21); /* HG_LL_INTERPTHRESH1 */
  CamWriteCmosSensor(0x0990, 0x0010);
  CamWriteCmosSensor(0x098C, 0xAB22); /* HG_LL_APCORR1 */
  CamWriteCmosSensor(0x0990, 0x0004);
  CamWriteCmosSensor(0x098C, 0xAB23); /* HG_LL_APTHRESH1 */
  CamWriteCmosSensor(0x0990, 0x0004);
  CamWriteCmosSensor(0x098C, 0xAB24); /* HG_LL_SAT2 */
  CamWriteCmosSensor(0x0990, 0x0000);
  CamWriteCmosSensor(0x098C, 0xAB25); /* HG_LL_INTERPTHRESH2 */
  CamWriteCmosSensor(0x0990, 0x0032);
  CamWriteCmosSensor(0x098C, 0xAB26); /* HG_LL_APCORR2 */
  CamWriteCmosSensor(0x0990, 0x0000);
  CamWriteCmosSensor(0x098C, 0xAB27); /* HG_LL_APTHRESH2 */
  CamWriteCmosSensor(0x0990, 0x0008);
  CamWriteCmosSensor(0x098C, 0x2B28); /* HG_LL_BRIGHTNESSSTART */
  CamWriteCmosSensor(0x0990, 0x1E14);
  CamWriteCmosSensor(0x098C, 0x2B2A); /* HG_LL_BRIGHTNESSSTOP */
  CamWriteCmosSensor(0x0990, 0x3A98);
  CamWriteCmosSensor(0x098C, 0xAB2C); /* HG_NR_START_R */
  CamWriteCmosSensor(0x0990, 0x0001);
  CamWriteCmosSensor(0x098C, 0xAB2D); /* HG_NR_START_G */
  CamWriteCmosSensor(0x0990, 0x0001);
  CamWriteCmosSensor(0x098C, 0xAB2E); /* HG_NR_START_B */
  CamWriteCmosSensor(0x0990, 0x0001);
  CamWriteCmosSensor(0x098C, 0xAB2F); /* HG_NR_START_OL */
  CamWriteCmosSensor(0x0990, 0x0001);
  CamWriteCmosSensor(0x098C, 0xAB30); /* HG_NR_STOP_R */
  CamWriteCmosSensor(0x0990, 0x00F0);
  CamWriteCmosSensor(0x098C, 0xAB31); /* HG_NR_STOP_G */
  CamWriteCmosSensor(0x0990, 0x00F0);
  CamWriteCmosSensor(0x098C, 0xAB32); /* HG_NR_STOP_B */
  CamWriteCmosSensor(0x0990, 0x00F0);
  CamWriteCmosSensor(0x098C, 0xAB33); /* HG_NR_STOP_OL */
  CamWriteCmosSensor(0x0990, 0x00F0);
  CamWriteCmosSensor(0x098C, 0xAB36); /* HG_CLUSTERDC_TH */
  CamWriteCmosSensor(0x0990, 0x002D);
  CamWriteCmosSensor(0x098C, 0x2B62); /* HG_FTB_START_BM */
  CamWriteCmosSensor(0x0990, 0xFFFF);
  CamWriteCmosSensor(0x098C, 0x2B64); /* HG_FTB_STOP_BM */
  CamWriteCmosSensor(0x0990, 0xFFFF);
  CamWriteCmosSensor(0x098C, 0x2B66); /* HG_CLUSTER_DC_BM */
  CamWriteCmosSensor(0x0990, 0x3A98);
  CamWriteCmosSensor(0x098C, 0x275F); /* MODE_COMMONMODESETTINGS_BRIGHT_COLOR_KILL */
#if (defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_YUV_BURST_MODE_SUPPORT)||defined(MT6276))
  CamWriteCmosSensor(0x0990, 0x0595);
#else
  CamWriteCmosSensor(0x0990, 0x0596);
#endif
  CamWriteCmosSensor(0x098C, 0x2761); /* MODE_COMMONMODESETTINGS_DARK_COLOR_KILL */
  CamWriteCmosSensor(0x0990, 0x0080);
  CamWriteCmosSensor(0x098C, 0xA765); /* MODE_COMMONMODESETTINGS_FILTER_MODE */
  CamWriteCmosSensor(0x0990, 0x00A4);
  CamWriteCmosSensor(0x098C, 0xAB34); /* HG_NR_GAINSTART */
  CamWriteCmosSensor(0x0990, 0x0008);
  CamWriteCmosSensor(0x098C, 0xAB35); /* HG_NR_GAINSTOP */
  CamWriteCmosSensor(0x0990, 0x0078);
}
/*************************************************************************
* FUNCTION
*    MT9D113_awb_ccms
*
* DESCRIPTION
*    This function set awb and ccms.
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
static void MT9D113_awb_ccms(void)
{
  CamWriteCmosSensor(0x098C, 0x2306); /* AWB_CCM_L_0 */
  CamWriteCmosSensor(0x0990, 0x0180);
  CamWriteCmosSensor(0x098C, 0x2308); /* AWB_CCM_L_1 */
  CamWriteCmosSensor(0x0990, 0xFF00);
  CamWriteCmosSensor(0x098C, 0x230A); /* AWB_CCM_L_2 */
  CamWriteCmosSensor(0x0990, 0x0080);
  CamWriteCmosSensor(0x098C, 0x230C); /* AWB_CCM_L_3 */
  CamWriteCmosSensor(0x0990, 0xFF66);
  CamWriteCmosSensor(0x098C, 0x230E); /* AWB_CCM_L_4 */
  CamWriteCmosSensor(0x0990, 0x0180);
  CamWriteCmosSensor(0x098C, 0x2310); /* AWB_CCM_L_5 */
  CamWriteCmosSensor(0x0990, 0xFFEE);
  CamWriteCmosSensor(0x098C, 0x2312); /* AWB_CCM_L_6 */
  CamWriteCmosSensor(0x0990, 0xFFCD);
  CamWriteCmosSensor(0x098C, 0x2314); /* AWB_CCM_L_7 */
  CamWriteCmosSensor(0x0990, 0xFECD);
  CamWriteCmosSensor(0x098C, 0x2316); /* AWB_CCM_L_8 */
  CamWriteCmosSensor(0x0990, 0x019A);
  CamWriteCmosSensor(0x098C, 0x2318); /* AWB_CCM_L_9 */
  CamWriteCmosSensor(0x0990, 0x0020);
  CamWriteCmosSensor(0x098C, 0x231A); /* AWB_CCM_L_10 */
  CamWriteCmosSensor(0x0990, 0x0033);
  CamWriteCmosSensor(0x098C, 0x231C); /* AWB_CCM_RL_0 */
  CamWriteCmosSensor(0x0990, 0x0100);
  CamWriteCmosSensor(0x098C, 0x231E); /* AWB_CCM_RL_1 */
  CamWriteCmosSensor(0x0990, 0xFF9A);
  CamWriteCmosSensor(0x098C, 0x2320); /* AWB_CCM_RL_2 */
  CamWriteCmosSensor(0x0990, 0x0000);
  CamWriteCmosSensor(0x098C, 0x2322); /* AWB_CCM_RL_3 */
  CamWriteCmosSensor(0x0990, 0x004D);
  CamWriteCmosSensor(0x098C, 0x2324); /* AWB_CCM_RL_4 */
  CamWriteCmosSensor(0x0990, 0xFFCD);
  CamWriteCmosSensor(0x098C, 0x2326); /* AWB_CCM_RL_5 */
  CamWriteCmosSensor(0x0990, 0xFFB8);
  CamWriteCmosSensor(0x098C, 0x2328); /* AWB_CCM_RL_6 */
  CamWriteCmosSensor(0x0990, 0x004D);
  CamWriteCmosSensor(0x098C, 0x232A); /* AWB_CCM_RL_7 */
  CamWriteCmosSensor(0x0990, 0x0080);
  CamWriteCmosSensor(0x098C, 0x232C); /* AWB_CCM_RL_8 */
  CamWriteCmosSensor(0x0990, 0xFF66);
  CamWriteCmosSensor(0x098C, 0x232E); /* AWB_CCM_RL_9 */
  CamWriteCmosSensor(0x0990, 0x0010);
  CamWriteCmosSensor(0x098C, 0x2330); /* AWB_CCM_RL_10 */
  CamWriteCmosSensor(0x0990, 0xFFF7);
  CamWriteCmosSensor(0x098C, 0xA363); /* AWB_TG_MIN0 */
  CamWriteCmosSensor(0x0990, 0x00D2);
  CamWriteCmosSensor(0x098C, 0xA364); /* AWB_TG_MAX0 */
  CamWriteCmosSensor(0x0990, 0x00EE);
  
  CamWriteCmosSensor(0x3244, 0x0302); /* AWB_CONFIG4: change AWB: 0x0328 */
  CamWriteCmosSensor(0x323E, 0xC22C); /* AWB_CONFIG1 */
}
/*************************************************************************
* FUNCTION
*    MT9D113_write_XDMA
*
* DESCRIPTION
*    This function write XMDA
*
* PARAMETERS
*    addr    : the 16bit address of XDMA
*    para    : the 16bit value of XDMA
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113_write_XDMA(kal_uint16 addr, kal_uint16 para)
{
  CamWriteCmosSensor(0x098C, addr);
  CamWriteCmosSensor(0x0990, para);
}
/*************************************************************************
* FUNCTION
*    MT9D113_set_mirror
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
static void MT9D113_set_mirror(kal_uint8 mirror)
{
  kal_uint8 sensor_mirror = 0;
  
  if (MT9D113_sensor.mirror == mirror) return;
  MT9D113_sensor.mirror = mirror;
  switch (MT9D113_sensor.mirror)
  {
  case IMAGE_SENSOR_MIRROR_H:
    sensor_mirror = 1;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    sensor_mirror = 2;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    sensor_mirror = 3;
    break;
  default:
    break;
  }
  SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
  MT9D113_write_XDMA(0x2717, 0x046C|sensor_mirror); /* preview read mode */
  MT9D113_write_XDMA(0x272D, 0x0024|sensor_mirror); /* snapshot/video read mode */
  MT9D113_set_cmd(6); /* refresh mode */
}


/*************************************************************************
* FUNCTION
*    MT9D113_patch
*
* DESCRIPTION
*    This function Patch the MT9D113 which provided by Micron
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
static void MT9D113_patch(void)
{
  const kal_uint8 rev = CamReadCmosSensor(0x31FE)&0x000F;
  
#ifdef __MT9D113_DEBUG_TRACE__
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Rev: %d", rev);
#endif
  switch (rev)
  {
#if (defined(MT9D113_REV2))
  case 0x02:
  {
    /* 2030SOC_REV02_PATCH02_REV9 */
    const static kal_uint16 patch_data[]=
    {
      0xF601,0x42C1,0x0226,0x11F6,0x0143,0xC102,0x260A,0xCC04,0x33BD,0xA365,0xBD04,0x3339,0xC6FF,0xF701,0x6439,0xFE02,
      0x5418,0xCE03,0x42CC,0x000B,0xBDC2,0xBFCC,0x04BF,0xFD03,0x4CCC,0x0342,0xFD02,0x545F,0x4FFD,0x025F,0xFE02,0xBD18,
      0xCE03,0x30C6,0x11BD,0xC2BF,0xCC05,0x03FD,0x033A,0xCC05,0xB5FD,0x033E,0xCC03,0x30FD,0x02BD,0xDE00,0x18CE,0x00C2,
      0xCC00,0x37BD,0xC2BF,0xCC06,0xAEDD,0xC4CC,0x06B4,0xDDD6,0xCC00,0xC2DD,0x00B6,0x02C3,0x810A,0x2407,0x1686,0x0A3D,
      0xF702,0xC3B6,0x02C4,0x810A,0x2407,0x1686,0x0A3D,0xF702,0xC4CC,0x02BD,0xFD03,0x4EFE,0x034E,0xCC4A,0x38ED,0x66C6,
      0x02F7,0x0164,0xC609,0xF701,0x6539,0x3C3C,0x34BD,0xCDCF,0x7D02,0x5626,0x05F6,0x025F,0x2003,0xF602,0x6030,0xE704,
      0xCC34,0x00BD,0xA55B,0xC43F,0x84FE,0x30ED,0x02E6,0x044F,0x0505,0x0505,0x0505,0xC4C0,0x8401,0xEA03,0xAA02,0xED02,
      0xCC34,0x00ED,0x00EC,0x02BD,0xA547,0x3838,0x3139,0x3CF6,0x02C3,0xF102,0xC423,0x08F0,0x02C4,0x30E7,0x0020,0x0330,
      0x6F00,0xF602,0xC3FB,0x02C4,0xE701,0x4FB3,0x02C8,0x2415,0xF602,0xC5F1,0x02C2,0x2308,0xF002,0xC2F7,0x02C5,0x2016,
      0x7F02,0xC520,0x11E6,0x004F,0xB302,0xC823,0x09F6,0x02C5,0xFB02,0xC2F7,0x02C5,0xF602,0xC5F1,0x02C1,0x2306,0xF602,
      0xC1F7,0x02C5,0x3839,0x3736,0x3C3C,0x3C3C,0x3C34,0x30EC,0x0FBD,0xA55B,0x30ED,0x0617,0x847F,0xA70A,0xEC06,0xC480,
      0x8401,0xED08,0x2709,0x8301,0x8026,0x0668,0x0A20,0x0264,0x0AEC,0x0BBD,0xA55B,0x30ED,0x06E6,0x0A4F,0xED02,0xEC06,
      0xED00,0xCC00,0x80BD,0xA409,0x30EC,0x02ED,0x046D,0x0427,0x05CC,0x00FF,0xED04,0xE605,0x308F,0xC300,0x0D8F,0x3539,
      0x308F,0xC3FF,0xF38F,0x35CC,0x3210,0xBDA5,0x5B30,0xED06,0xBDD6,0x54CC,0x3210,0x30ED,0x00EC,0x06BD,0xA547,0xCC30,
      0x5A30,0xED00,0xCC32,0xD4BD,0x055B,0x30E7,0x08CC,0x3056,0xED00,0xCC32,0xD6BD,0x055B,0x30E7,0x09CC,0x3058,0xED00,
      0xCC32,0xDABD,0x055B,0x30E7,0x0AE6,0x09E7,0x0B6F,0x0CE6,0x0C4F,0x05C3,0x33F6,0xED00,0xE60C,0x4FED,0x028F,0xC300,
      0x0830,0xE302,0x188F,0x3C18,0xE600,0x4F30,0xED00,0x3CF6,0x02F1,0x30ED,0x003C,0xF602,0xF230,0xED00,0xE612,0xC302,
      0xE98F,0x34E6,0x0030,0xE700,0xE613,0x4FC3,0x02ED,0x8FE6,0x00BD,0xA4EE,0x3838,0x3831,0x4FBD,0xA547,0x306C,0x0CE6,
      0x0CC1,0x0425,0xAACE,0x02BD,0x1F1F,0x8047,0xCC33,0xF4BD,0xA55B,0xC4BF,0x30ED,0x04FE,0x034E,0xFC02,0xD8A3,0x6625,
      0x0430,0x1C05,0x40CE,0x02BD,0x1F1F,0x401C,0xCC32,0x10BD,0xA55B,0xC4EF,0x30ED,0x061E,0x0540,0x031C,0x0710,0xCC32,
      0x10ED,0x00EC,0x06BD,0xA547,0xCC33,0xF430,0xED00,0xEC04,0xBDA5,0x4730,0xC60D,0x3A35,0x39BD,0xA705,0xBDA7,0x613C,
      0x3C3C,0x122F,0x0203,0x5F20,0x02C6,0x0130,0xE702,0xCC00,0x18BD,0xA55B,0x8580,0x2603,0x5F20,0x02C6,0x0130,0xE703,
      0xD604,0xF704,0x13CC,0x0016,0xBDA5,0x5BFD,0x040F,0xCC00,0x14BD,0xA55B,0xFD04,0x0DCC,0x001A,0xBDA5,0x5BFD,0x0411,
      0xDE00,0xEE24,0xAD00,0xCC00,0x1630,0xED00,0xDC30,0xBDA5,0x47CC,0x001A,0xBDA5,0x5B30,0xED04,0x1F04,0x020C,0xCC00,
      0x1AED,0x00EC,0x0484,0xFDBD,0xA547,0xDE00,0xEE36,0xC605,0xAD00,0xCC07,0xFFFD,0x1042,0xC603,0xF710,0x44F6,0x104D,
      0xC4F0,0xCA09,0xF710,0x4DCC,0x0020,0x30ED,0x00CC,0x0001,0xBDA5,0x47CC,0x0026,0x30ED,0x0034,0xBDA5,0x5BCA,0x0231,
      0xBDA5,0x47CC,0x0018,0x30ED,0x0034,0xBDA5,0x5B8A,0x4031,0xBDA5,0x4720,0x11C6,0xFFF7,0x1040,0xB610,0x40FE,0x0140,
      0xEE00,0xC620,0xAD00,0x306D,0x0227,0x0FCC,0x0018,0xBDA5,0x5BC4,0x0184,0x8083,0x0000,0x26DB,0x306D,0x0226,0x06D6,
      0x03C1,0x0126,0xD0CC,0x0016,0xED00,0xFC04,0x0FCA,0x20BD,0xA547,0xDE00,0xEE30,0xAD00,0xCC00,0x2630,0xED00,0x34BD,
      0xA55B,0xC4FD,0x31BD,0xA547,0xCC00,0x1A30,0xED00,0xEC04,0x8A08,0xBDA5,0x47CC,0x001A,0x30ED,0x00EC,0x04BD,0xA547,
      0xCC00,0x1630,0xED00,0xFC04,0x0FBD,0xA547,0xDE00,0xEE2E,0xAD00,0x306D,0x0226,0x06DE,0x00EE,0x2CAD,0x00F6,0x104D,
      0xC4F0,0xCA0A,0xF710,0x4D38,0x3838
    };
    MT9D113_burst_write_XDMA(0x0415, patch_data, sizeof(patch_data) / sizeof(patch_data[0]));
    MT9D113_write_XDMA(0x87FF, 0x0039);
    break;
  }
#endif
#if (defined(MT9D113_REV3))
  case 0x03:
  {
    /* K25A_REV03_PATCH01_REV2 */
    const static kal_uint16 patch_data[]=
    {
      0xF601,0x42C1,0x0326,0x11F6,0x0143,0xC104,0x260A,0xCC04,0x33BD,0xA362,0xBD04,0x3339,0xC6FF,0xF701,0x6439,0xFE02,
      0xBD18,0xCE03,0x25CC,0x0011,0xBDC2,0xB8CC,0x0470,0xFD03,0x33CC,0x0325,0xFD02,0xBDDE,0x0018,0xCE03,0x37CC,0x0037,
      0xBDC2,0xB8CC,0x0497,0xFD03,0x5BCC,0x0337,0xDD00,0xC601,0xF701,0x645C,0xF701,0x657F,0x0166,0x39BD,0xD661,0xF602,
      0xF4C1,0x0126,0x0BFE,0x02BD,0xEE10,0xFC02,0xF5AD,0x0039,0xF602,0xF4C1,0x0226,0x0AFE,0x02BD,0xEE10,0xFC02,0xF7AD,
      0x0039,0x3CBD,0xB059,0xCC00,0x28BD,0xA558,0x8300,0x0027,0x0BCC,0x0026,0x30ED,0x00C6,0x03BD,0xA544,0x3839
    };
    MT9D113_burst_write_XDMA(0x0415, patch_data, sizeof(patch_data) / sizeof(patch_data[0]));
    break;
  }
#endif
  default:
    ASSERT(0);
  }
  MT9D113_write_XDMA(0x2006, 0x0415); /* MON_ARG1 */
  MT9D113_write_XDMA(0xA005, 0x01); /* MON_CMD */
  kal_sleep_task(1); /* wait for the patch to complete initialization */
}

/*************************************************************************
* FUNCTION
*    MT9D113_set_cmd
*
* DESCRIPTION
*    This function set command to the sequencer to change the state.
*    when set cmd fail, the function retry again until try times reach 200.
*
* PARAMETERS
*    cmd    : command, MUST BE 1, 2, 5, 6 !!!
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113_set_cmd(kal_uint16 cmd)
{
  const kal_uint8 status = (cmd == 1 ? 3 : 7);
  kal_uint8 delay, i;
  
  if (MT9D113_sensor.initial) return;
  if ((cmd == 1 && MT9D113_sensor.pv_mode) || (cmd == 2 && !MT9D113_sensor.pv_mode)) return;
  for (delay = 8, i = 100; i > 0; i--) /* check if ready to set */
  {
    if (!MT9D113_read_XDMA(0xA103)) break;
    kal_sleep_task(delay);
    delay = 2;
  }
#ifdef __MT9D113_DEBUG_TRACE__
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "sequencer time out");
#endif
  MT9D113_write_XDMA(0xA103, cmd);
  if (cmd >= 5) return;
  MT9D113_sensor.pv_mode = !MT9D113_sensor.pv_mode;
  for (delay = 8, i = 100; i > 0; i--) /* wait for ready */
  {
    if (MT9D113_read_XDMA(0xA104) == status) break;
    kal_sleep_task(delay);
    delay = 2;
  }
#ifdef __MT9D113_DEBUG_TRACE__
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "set cmd: %d time out", cmd);
#endif
}





/*************************************************************************
* FUNCTION
*    MT9D113Contrast
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
static MM_ERROR_CODE_ENUM MT9D113Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
#if 0   //zhou
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
  #endif
}



/*************************************************************************
* FUNCTION
*    MT9D113SceneMode
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
static MM_ERROR_CODE_ENUM MT9D113SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    MT9D113_night_mode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D113Ev
*
* DESCRIPTION
*    Exposure setting.
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
static MM_ERROR_CODE_ENUM MT9D113Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	kal_uint8 ae_base_target;
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Exposure->IsSupport = KAL_TRUE;
    Exposure->ItemCount = 9;
    Exposure->SupportItem[0] = CAM_EV_NEG_4_3;
    Exposure->SupportItem[1] = CAM_EV_NEG_3_3;
    Exposure->SupportItem[2] = CAM_EV_NEG_2_3;
    Exposure->SupportItem[3] = CAM_EV_NEG_1_3;
    Exposure->SupportItem[4] = CAM_EV_ZERO;
    Exposure->SupportItem[5] = CAM_EV_POS_1_3;
    Exposure->SupportItem[6] = CAM_EV_POS_2_3;
    Exposure->SupportItem[7] = CAM_EV_POS_3_3;
    Exposure->SupportItem[8] = CAM_EV_POS_4_3;
    
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    

    if (MT9D113_sensor.exposure == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    MT9D113_sensor.exposure = In->FeatureSetValue;
    switch (MT9D113_sensor.exposure)
    {
    case CAM_EV_NEG_4_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO - 24;
    break;
  case CAM_EV_NEG_3_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO - 18;
    break;
  case CAM_EV_NEG_2_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO - 12;
    break;
  case CAM_EV_NEG_1_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO - 6;
    break;
  case CAM_EV_ZERO:
    ae_base_target = MT9D113_AE_TARGET_ZERO;
    break;
  case CAM_EV_POS_1_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO + 6;
    break;
  case CAM_EV_POS_2_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO + 12;
    break;
  case CAM_EV_POS_3_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO + 18;
    break;
  case CAM_EV_POS_4_3:
    ae_base_target = MT9D113_AE_TARGET_ZERO + 24;
    break;
	default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    
	MT9D113_write_XDMA(0xA24F, ae_base_target); /* ae_base_target */
  }
  return MM_ERROR_NONE;
}




/*************************************************************************
* FUNCTION
*    MT9D113Wb
*
* DESCRIPTION
*    Wb setting.
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
static MM_ERROR_CODE_ENUM MT9D113Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{

	kal_uint8 awb_ccm_position;
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Wb = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Wb->IsSupport = KAL_TRUE;
    Wb->ItemCount = 6;
    Wb->SupportItem[0] = CAM_WB_AUTO;
    Wb->SupportItem[1] = CAM_WB_CLOUD;
    Wb->SupportItem[2] = CAM_WB_DAYLIGHT;
    Wb->SupportItem[3] = CAM_WB_INCANDESCENCE;
    Wb->SupportItem[4] = CAM_WB_FLUORESCENT;
    Wb->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {


    if (MT9D113_sensor.wb == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    MT9D113_sensor.wb = In->FeatureSetValue;
    switch (MT9D113_sensor.wb)
    {
    case CAM_WB_AUTO:
    MT9D113_write_XDMA(0xA355, 0x02);
    return MM_ERROR_NONE;
  case CAM_WB_CLOUD:
    awb_ccm_position = 0x6F;
    break;
  case CAM_WB_DAYLIGHT:
    awb_ccm_position = 0x7F;
     break;
  case CAM_WB_INCANDESCENCE:
    awb_ccm_position = 0x10;
    break;
  case CAM_WB_FLUORESCENT:
    awb_ccm_position = 0x79;
    break;
  case CAM_WB_TUNGSTEN:
    awb_ccm_position = 0x00;
    break;
  default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
	
  MT9D113_write_XDMA(0xA355, 0x22); /* awb_mode */
  MT9D113_write_XDMA(0xA353, awb_ccm_position); /* awb_ccm_position */
  }
  return MM_ERROR_NONE;
 
}

/*************************************************************************
* FUNCTION
*    MT9D113Effect
*
* DESCRIPTION
*    Effect setting.
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
static MM_ERROR_CODE_ENUM MT9D113Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	kal_uint8 spec_effects;
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 6;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    Effect->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    Effect->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    
    
    if (MT9D113_sensor.effect == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    MT9D113_sensor.effect = In->FeatureSetValue;
    switch (MT9D113_sensor.effect)
    {
    case CAM_EFFECT_ENC_NORMAL: /* normal */
    spec_effects = 0;
    break;
  case CAM_EFFECT_ENC_GRAYSCALE: /* Mono */
    spec_effects = 1;
    break;
  case CAM_EFFECT_ENC_SEPIA: /* sepia */
    spec_effects = 2;
    MT9D113_write_XDMA(0x2763, 0xB023); /* mode_common_mode_settings_fx_sepia_settings */
    break;
  case CAM_EFFECT_ENC_SEPIAGREEN: /* sepial-green */
    spec_effects = 2;
    MT9D113_write_XDMA(0x2763, 0xB0CD);
    break;
  case CAM_EFFECT_ENC_SEPIABLUE: /* sepial-Blue */
    spec_effects = 2;
    MT9D113_write_XDMA(0x2763, 0x25F0);
    break;
  case CAM_EFFECT_ENC_COLORINV: /* Negative */
    spec_effects = 3;
    break;
  default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  MT9D113_write_XDMA(0x2759, 0x6440|spec_effects); /* preview spec_effects */
  MT9D113_write_XDMA(0x275B, 0x6440|spec_effects); /* snapshot/video spec_effects */
  MT9D113_set_cmd(5); /* refresh */
  }
  return MM_ERROR_NONE;

}




/*************************************************************************
* FUNCTION
*    MT9D113InitialSetting
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
static void MT9D113InitialSetting(void)
{
  //CamWriteCmosSensor(0x3012, 0x80); /* [7]: software reset */
  MT9D113_sensor.initial = MT9D113_sensor.first_pv = KAL_TRUE;
  /* Reset */

  
#if (defined(MT6236)||defined(MT6276))
  
	  MT9D113_sensor.pclk = 77000000; /* 26MHz CLKIN, 77 MHz PLL out */
 
#else
	  MT9D113_sensor.pclk = 52000000; /* 26MHz CLKIN, 52 MHz PLL out */
#endif
  CamWriteCmosSensor(0x001A, 0x0051);
  kal_sleep_task(1);
  CamWriteCmosSensor(0x001A, 0x0050);
  kal_sleep_task(1);
  
  /* PLL VCO = MCLK * 2 * M / (N + 1), PCLK = VCO / (P1 + 1) */
  CamWriteCmosSensor(0x0014, 0x21F9); /* PLL control: BYPASS PLL */
#if (defined(MT6236)||defined(MT6276))
  
    CamWriteCmosSensor(0x0010, 0x0C9A); /* PLL Dividers [7~0]: m, [13~8]: n */
    CamWriteCmosSensor(0x0012, 0x1FF7); /* PLL P Dividers [3~0]: p1, [7~4]: p2, [11~8]: p3 */

#else
  CamWriteCmosSensor(0x0010, 0x0010);
  CamWriteCmosSensor(0x0012, 0x00F7);
#endif
  CamWriteCmosSensor(0x0014, 0x21FB);  /* PLL control: PLL_ENABLE on = 8699 */
  CamWriteCmosSensor(0x0014, 0x20FB);  /* PLL control: SEL_LOCK_DET on = 8443 */
  kal_sleep_task(1); /* Allow PLL to lock */
  CamWriteCmosSensor(0x0014, 0x20FA);  /* PLL control: PLL_BYPASS off = 8442 */
  CamWriteCmosSensor(0x321C, 0x0003);  /* By Pass TxFIFO = 3 */
#if (defined(MT6236)||defined(MT6276))
  CamWriteCmosSensor(0x001E, 0x0403); /* PAD_SLEW */
#else
  CamWriteCmosSensor(0x001E, 0x0700);
#endif
  CamWriteCmosSensor(0x0018, 0x402D); /* MCU Powerup stop enable */
  CamWriteCmosSensor(0x0018, 0x402C); /* GO */
  kal_sleep_task(4); /* wait for R20B to come out of standby */
  
  MT9D113_config_context();
  
  MT9D113_sensor.pv_frame_height = MT9D113_sensor.pv_line_length = 0; /* force config preview dummy */
  MT9D113_set_pv_dummy(0, 0);
  
  MT9D113_sensor.cap_frame_height = MT9D113_sensor.cap_line_length = 0; /* force config capture dummy */
  MT9D113_set_cap_dummy(0, 0);
  
  /* Errata for Rev2 */
  CamWriteCmosSensor(0x3084, 0x240C);
  CamWriteCmosSensor(0x3092, 0x0A4C);
  CamWriteCmosSensor(0x3094, 0x4C4C);
  CamWriteCmosSensor(0x3096, 0x4C54);
  
  MT9D113_LSC_setting();
  MT9D113_gamma_setting();
  MT9D113_low_light();
  MT9D113_awb_ccms();
  
  CamWriteCmosSensor(0x3240, 0xC807); /* LUM_LIMITS_WB_STATS: change AWB */
  MT9D113_write_XDMA(0xA768, 0x05); /* highlight capture look like purple issue, default is 4 */
  MT9D113_write_XDMA(0xA115, 0x02); /* seq_cap_mode */
  MT9D113_write_XDMA(0xA117, 0x00); /* seq_preview_0_ae */
  MT9D113_write_XDMA(0xA129, 0x00); /* seq_preview_3_ae */
  MT9D113_write_XDMA(0xA209, 0x20); /* AE */
  MT9D113_write_XDMA(0xA20A, 0x03); /* AE */
  MT9D113_write_XDMA(0xA109, 0x08); /* seq_ae_fast_buff */
  MT9D113_write_XDMA(0xA10A, 0x01); /* seq_ae_fast_step */
  MT9D113_write_XDMA(0xA20E, MT9D113_MAX_ANALOG_GAIN); /* ae_max_virt_gain */
  
  /* default setting */
  MT9D113_sensor.video_mode = KAL_FALSE;
  MT9D113_sensor.normal_fps = MT9D113_FPS(10);
  MT9D113_sensor.night_fps = MT9D113_FPS(5);
  MT9D113_sensor.Fps = MT9D113_FPS(10);
  
  MT9D113_sensor.mirror = !IMAGE_SENSOR_MIRROR_NORMAL; /* force config mirror */
  MT9D113_set_mirror(IMAGE_SENSOR_MIRROR_NORMAL);
  
  //MT9D113_sensor.banding = !CAM_BANDING_50HZ; /* force config banding */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_BANDING, CAM_BANDING_50HZ);
  
  MT9D113_sensor.banding = CAM_BANDING_50HZ;
  MT9D113_write_XDMA(0xA404, 0xC0); /* fd_mode */
  MT9D113_set_cmd(6); /* refresh mode */
  MT9D113_cal_fps(); /* need cal new fps */
  
  //MT9D113_sensor.effect = !CAM_EFFECT_ENC_NORMAL; /* force config effect */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_EFFECT, CAM_EFFECT_ENC_NORMAL);


  MT9D113_sensor.effect = CAM_EFFECT_ENC_NORMAL;
  MT9D113_write_XDMA(0x2759, 0x6440); /* preview spec_effects */
  MT9D113_write_XDMA(0x275B, 0x6440); /* snapshot/video spec_effects */
  MT9D113_set_cmd(5); /* refresh */

  
  //MT9D113_sensor.exposure = !CAM_EV_ZERO; /* force config exposure */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_EXPOSURE, CAM_EV_ZERO);

  MT9D113_sensor.exposure = CAM_EV_ZERO;
  MT9D113_write_XDMA(0xA24F, MT9D113_AE_TARGET_ZERO); /* ae_base_target */
  
  //MT9D113_sensor.wb = !CAM_WB_AUTO; /* force config wb */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_WB, CAM_WB_AUTO);

  MT9D113_sensor.wb = CAM_WB_AUTO;
  MT9D113_write_XDMA(0xA355, 0x02);
  
  MT9D113_sensor.night_mode = !KAL_FALSE; /* force config night mode */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_NIGHT_MODE, KAL_FALSE);
  MT9D113_night_mode(KAL_FALSE);
  
  
  MT9D113_sensor.enable_3a = !KAL_TRUE; /* force config 3a */
  //MT9D113_yuv_sensor_setting(CAM_PARAM_3A_ENABLE, KAL_TRUE);
  MT9D113_set_param_3a_enable(KAL_TRUE);
  
  MT9D113_patch();
  
#ifdef __MT9D113_TEST_PATTERN__
  /* 00: disabled 01: solid white 02: grey ramp 03: color bar ramp 04: solid white (color bars) 05: noise */
  MT9D113_write_XDMA(0xA766, 0x03);
#endif
  CamWriteCmosSensor(0x0018, 0x0028); /* Continue */
  kal_sleep_task(5); /* wait for sequencer to enter preview state */
  MT9D113_sensor.initial = KAL_FALSE;
  MT9D113_set_cmd(6); /* refresh mode */
  MT9D113_set_cmd(5); /* refresh */
  
  MT9D113_sensor.pv_mode = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    MT9D113GetSensorInfo
*
* DESCRIPTION
*    This function set sensor infomation
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = MT9D113_SENSOR_ID;
  
  
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
#if (defined(MT6276))
  Info->PixelClkInv = KAL_TRUE;
#else
  Info->PixelClkInv = KAL_FALSE;
#endif
  
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
  
  Info->PreviewMclkFreq = Info->CaptureMclkFreq = Info->VideoMclkFreq = 26000000;
  Info->PreviewWidth = MT9D113_IMAGE_SENSOR_PV_WIDTH;
  Info->PreviewHeight = MT9D113_IMAGE_SENSOR_PV_HEIGHT;
  Info->FullWidth = MT9D113_IMAGE_SENSOR_FULL_WIDTH_DRV;
  Info->FullHeight = MT9D113_IMAGE_SENSOR_FULL_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    MT9D113PowerOn
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
static kal_uint16 MT9D113PowerOn(void)
{
  kal_uint16 SensorId;
  
  CisModulePowerOn(MT9D113_sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9D113_SLV1_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 300);
  CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 1);
  CamRstPinCtrl(MT9D113_sensor.SensorIdx, 0);
  kal_sleep_task(2); /* >= 5ms */
  
  CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 0);
  kal_sleep_task(1); /* >= 1ms */
  CamRstPinCtrl(MT9D113_sensor.SensorIdx, 1);
  kal_sleep_task(5); /* >= 20ms */
  
 
  SensorId = CamReadCmosSensor(0x0000);
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
  if (SensorId != MT9D113_SENSOR_ID) /* READ SENSOR ID */
  {
  	kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#if defined(__MT9D113_DEBUG_TRACE__)
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
	CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9D113_SLV2_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 320);
  CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 1);
  CamRstPinCtrl(MT9D113_sensor.SensorIdx, 0);
  kal_sleep_task(2); /* >= 5ms */
  
  CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 0);
  kal_sleep_task(1); /* >= 1ms */
  CamRstPinCtrl(MT9D113_sensor.SensorIdx, 1);
  kal_sleep_task(5); /* >= 20ms */
  SensorId = CamReadCmosSensor(0x0000);
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    MT9D113DetectSensorId
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
static kal_uint32 MT9D113DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM MT9D113SensorClose(void);
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (MT9D113_sensor.SensorIdx)
  {
  case IMAGE_SENSOR_MAIN:
  case IMAGE_SENSOR_BAK1:
    InvIdx = IMAGE_SENSOR_SUB;
    break;
  default:
    InvIdx = IMAGE_SENSOR_MAIN;
    break;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(InvIdx, i);
      CamPdnPinCtrl(InvIdx, j);
      SensorId = MT9D113PowerOn();
      MT9D113SensorClose();
      if (MT9D113_SENSOR_ID == SensorId)
      {
        return MT9D113_SENSOR_ID;
      }
    }
  }
  
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    MT9D113StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
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
MM_ERROR_CODE_ENUM MT9D113StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 4;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
    CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
    
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D113Banding
*
* DESCRIPTION
*    This function get banding setting
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
static MM_ERROR_CODE_ENUM MT9D113Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  }else if(CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    if (MT9D113_sensor.banding== In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    MT9D113_sensor.banding= In->FeatureSetValue;
	switch (MT9D113_sensor.banding)
  	{
  	case CAM_BANDING_50HZ:
    MT9D113_write_XDMA(0xA404, 0xC0); /* fd_mode */
    break;
  	case CAM_BANDING_60HZ:
    MT9D113_write_XDMA(0xA404, 0x80); /* fd_mode */
    break;
  	default:
    return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
  	}
	MT9D113_set_cmd(6); /* refresh mode */
  	MT9D113_cal_fps(); /* need cal new fps */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D113InitOperationPara
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
static void MT9D113InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT para)
{
  para->CaptureDelayFrame = 3; /* use WaitStableFrameNum instead of this */
  para->PreviewDelayFrame = 4;
  para->PreviewDisplayWaitFrame = 14;
}

/*************************************************************************
* FUNCTION
*    MT9D113DscSupportInfo
*
* DESCRIPTION
*    This function get dsc support Info
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT Info)
{
#if defined(DRV_ISP_6238_SERIES)
  //kal_mem_cpy(Info, &MT9D113_dsc_support_info, sizeof(camcorder_info_struct));
#endif
}

/*************************************************************************
* FUNCTION
*    MT9D113Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113Preview(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{

  kal_uint16 dummy_pixel;
	
	MT9D113_set_mirror(In->ImageMirror);
	switch (id)
	{
	//case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	  MT9D113_sensor.video_mode = KAL_TRUE;
	  MT9D113_sensor.normal_fps = MT9D113_FPS(10);
	  MT9D113_sensor.night_fps = MT9D113_FPS(5);
	  dummy_pixel = 0;
	  break;
	//case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_VIDEO:
	  MT9D113_sensor.video_mode = KAL_TRUE;
	  MT9D113_sensor.normal_fps = MT9D113_FPS(15);
	  MT9D113_sensor.night_fps = MT9D113_FPS(7.5);
	  MT9D113_sensor.Fps= In->MaxVideoFrameRate;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
	  if (In->ImageTargetWidth>= 320 && In->ImageTargetHeight >= 240)
	  {
		MT9D113_sensor.normal_fps = MT9D113_FPS(10);
		MT9D113_sensor.night_fps = MT9D113_FPS(5);
	  }
#endif
#if (defined(__SW_VIDEO_ADV_RESIZER_SUPPORT__) || defined(DRV_ISP_YUV_BURST_MODE_SUPPORT) || defined(DRV_ISP_6238_SERIES)||defined(MT6276))
	  MT9D113_sensor.normal_fps <<= 1;
	  MT9D113_sensor.night_fps <<= 1;
#endif
	  dummy_pixel = 0;
	  break;
#if (defined(__MEDIA_VT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(DRV_ISP_MT6236_HW_SUPPORT)||defined(MT6276))
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
	default: /* ISP_PREVIEW_MODE */
	  MT9D113_sensor.video_mode = KAL_FALSE;
	  MT9D113_sensor.normal_fps = MT9D113_FPS(10);
	  MT9D113_sensor.night_fps = MT9D113_FPS(5);
	  MT9D113_sensor.Fps= In->NightMode ? MT9D113_FPS(5) : MT9D113_FPS(10);
	  dummy_pixel = 0;
	}
	if (!MT9D113_sensor.pv_mode)
	{
	  CamWriteCmosSensor(0x3012, MT9D113_sensor.shutter); /* shutter */
	  MT9D113_gain2shutter(KAL_FALSE);
	}
	MT9D113_set_pv_dummy(dummy_pixel, 0);
	MT9D113_set_cmd(1); /* seq_cmd: goto preview mode */
	//MT9D113_night_mode(In->NightMode);
	Out->GrabStartX = MT9D113_PV_X_START;
	Out->GrabStartY = MT9D113_PV_Y_START;
	Out->ExposureWindowWidth = MT9D113_IMAGE_SENSOR_PV_WIDTH;
	Out->ExposureWindowHeight = MT9D113_IMAGE_SENSOR_PV_HEIGHT;
#if (defined(__DYNAMIC_SENSOR_DELAY__))
	if (MT9D113_sensor.first_pv)
	{
	  MT9D113_sensor.first_pv = KAL_FALSE;
	  Out->WaitStableFrameNum = 4; /* first enter preview */
	}
	else
	{
	  Out->WaitStableFrameNum = 2;
	}
#endif


}

/*************************************************************************
* FUNCTION
*    MT9D113Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D113Capture(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{

    kal_uint16 cap_fps, dummy_pixel;
  kal_uint16 shutter;
  kal_uint8 mul = 1; /* multiple of gain to shutter */
  
  if (In->ImageTargetWidth <= MT9D113_IMAGE_SENSOR_PV_WIDTH_DRV &&
      In->ImageTargetHeight <= MT9D113_IMAGE_SENSOR_PV_HEIGHT_DRV)
  {
    if (CAL_SCENARIO_WEBCAM_PREVIEW == id || CAL_SCENARIO_WEBCAM_CAPTURE == id) /* webcam mode */
    {
      dummy_pixel = 0;
    }
    else
    {
      dummy_pixel = 0;
    }
    MT9D113_set_pv_dummy(dummy_pixel, 0);
    Out->GrabStartX = MT9D113_PV_X_START;
    Out->GrabStartY = MT9D113_PV_Y_START;
    Out->ExposureWindowWidth = MT9D113_IMAGE_SENSOR_PV_WIDTH;
    Out->ExposureWindowHeight = MT9D113_IMAGE_SENSOR_PV_HEIGHT;
#if (defined(__DYNAMIC_SENSOR_DELAY__))
    Out->WaitStableFrameNum = 2;
#endif
  }
  else
  {
    MT9D113_sensor.shutter = CamReadCmosSensor(0x3012); /* back up shutter */
    
    cap_fps = MT9D113_cap_fps(In->ZoomFactor, In->ImageTargetWidth);
    dummy_pixel = MT9D113_sensor.pclk * MT9D113_FPS(1) / (2 * MT9D113_FULL_PERIOD_LINE_NUMS * cap_fps);
    dummy_pixel = dummy_pixel < MT9D113_FULL_PERIOD_PIXEL_NUMS ? 0 : dummy_pixel - MT9D113_FULL_PERIOD_PIXEL_NUMS;
    MT9D113_set_cap_dummy(dummy_pixel, 0);
    
    MT9D113_set_cmd(2); /* seq_cmd: goto capture mode */
    
    shutter = MT9D113_half_adjust(MT9D113_sensor.pv_line_length * MT9D113_sensor.shutter, MT9D113_sensor.cap_line_length);
    mul = MT9D113_gain2shutter(KAL_TRUE); /* transfer gain to shutter */
    if (!shutter) shutter = 1; /* avoid shutter 0 */
    CamWriteCmosSensor(0x3012, shutter * mul);
    
    Out->GrabStartX= MT9D113_FULL_X_START;
    Out->GrabStartY= MT9D113_FULL_Y_START;
    Out->ExposureWindowWidth= MT9D113_IMAGE_SENSOR_FULL_WIDTH;
    Out->ExposureWindowHeight= MT9D113_IMAGE_SENSOR_FULL_HEIGHT;
#if (defined(__DYNAMIC_SENSOR_DELAY__))
    Out->WaitStableFrameNum= 3; /* if 2, it will cause preview&capture brightness different in EV12 */
#endif
  }

}

/*************************************************************************
* FUNCTION
*    MT9P113SensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D113SensorOpen(void)
{
  if (MT9D113PowerOn() != MT9D113_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  
  
  
  /* default setting */
  {
    IMAGE_SENSOR_INDEX_ENUM SensorIdx = MT9D113_sensor.SensorIdx;
    sensor_data_struct *NvramData = MT9D113_sensor.NvramData;
    
    kal_mem_set(&MT9D113_sensor, 0xFF, sizeof(MT9D113_sensor));
	MT9D113InitialSetting();

    MT9D113_sensor.SensorIdx = SensorIdx;
    MT9D113_sensor.NvramData = NvramData;
  }
  
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MT9D113SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D113SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 tmpFrameRate;
  
  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return MT9D113WebcamFeatureCtrl(id, In, Out, OutLen, RealOutLen);
  }
  switch (id)
  {
  /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = MT9D113Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = MT9D113Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = MT9D113Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = MT9D113Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = MT9D113StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
    ErrCode = MT9D113Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = MT9D113SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = MT9D113SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    MT9D113GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D113DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    //((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D113_sensor.Fps * 10 / MT9D113_FPS(1);
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    MT9D113InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    MT9D113DscSupportInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(MT9D113_sensor.SensorIdx,Out);
    break;
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 1);
    CamRstPinCtrl(MT9D113_sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    MT9D113_sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    tmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    MT9D113_sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    MT9D113_sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    MT9D113AeEnable(MT9D113_sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    MT9D113_sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    MT9D113AwbEnable(MT9D113_sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    MT9D113SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    OutLen: Out parameter length
*    RealOutLen: Real out parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D113SensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    MT9D113Preview(id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    MT9D113Capture(id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D113SensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D113SensorClose(void)
{
  CamPdnPinCtrl(MT9D113_sensor.SensorIdx, 1); /* goto standby */
  CamRstPinCtrl(MT9D113_sensor.SensorIdx, 0);
  CisModulePowerOn(MT9D113_sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D113SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    Error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9D113SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9D113 =
  {
    MT9D113SensorOpen,
    MT9D113SensorFeatureCtrl,
    MT9D113SensorCtrl,
    MT9D113SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncMT9D113;
  
  return MM_ERROR_NONE;
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
