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
 *   image_sensor_MT9D112.c
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

#ifndef MT9D112_HW_SCCB
#include "sccb.h"
#else
#include "sccb_v2.h"
#endif

/* #define __MT9D112_DEBUG_TRACE__ */
/* #define __MT9D112_TEST_PATTERN__ */

#ifndef CAM_PARAM_3A_ENABLE
#define CAM_PARAM_3A_ENABLE CAM_NO_OF_PARAM
#endif

#define MT9D112_DEBUG
/* #define MT9D112_DEBUG */
static struct
{
  kal_uint32  Banding;
  
  kal_uint32  Effect;
  kal_uint32  Exposure;	
  kal_uint32  Wb;	
  kal_uint8   Mirror;
  kal_bool    Enable3A;
  kal_bool    BypassAe;
  kal_bool    BypassAwb;
  kal_bool    PvMode;
  kal_bool    Initial;
  kal_bool    FirstPv;
  kal_uint16  NormalFps; /* normal mode min fps */
  kal_uint16  NightFps; /* night mode min fps */
#ifndef MT9D112_HW_SCCB
  kal_uint8   WriteId;
  kal_uint8   ReadId;
#endif

  kal_uint16  Shutter;
  kal_uint16  PvFrameHeight;
  kal_uint16  PvLineLength;
  kal_uint16  CapFrameHeight;
  kal_uint16  CapLineLength;

  
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_uint16  Fps;
  kal_uint32  Pclk;
  kal_uint16  DummyPixel; /* for user customization */
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} MT9D112Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    MT9D112WriteXDMA
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
static void MT9D112WriteXDMA(kal_uint16 Addr, kal_uint16 Para)
{
  CamWriteCmosSensor(0x338C, Addr);
  CamWriteCmosSensor(0x3390, Para);
}

/*************************************************************************
* FUNCTION
*    MT9D112ReadXDMA
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
static kal_uint16 MT9D112ReadXDMA(kal_uint16 Addr)
{
  CamWriteCmosSensor(0x338C, Addr);
  return CamReadCmosSensor(0x3390);
}

/*************************************************************************
* FUNCTION
*    MT9D112SetCmd
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
static void MT9D112SetCmd(kal_uint16 Cmd)
{
  const kal_uint8 Status = (Cmd == 1 ? 3 : 7);
  kal_uint8 Delay, i;
  
  if (MT9D112Sensor.Initial) return;
  if ((Cmd == 1 && MT9D112Sensor.PvMode) || (Cmd == 2 && !MT9D112Sensor.PvMode)) return;
  for (Delay = 10, i = 100; i > 0; i--) /* check if ready to set */
  {
    if (!MT9D112ReadXDMA(0xA103)) break;
    kal_sleep_task(Delay);
    Delay = 2;
  }
#ifdef MT9D112_DEBUG
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "sequencer time out");
#endif
  MT9D112WriteXDMA(0xA103, Cmd);
  if (Cmd >= 5) return;
  MT9D112Sensor.PvMode = !MT9D112Sensor.PvMode;
  for (Delay = 8, i = 100; i > 0; i--) /* wait for ready */
  {
    if (MT9D112ReadXDMA(0xA104) == Status) break;
    kal_sleep_task(Delay);
    Delay = 2;
  }
#ifdef MT9D112_DEBUG
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "set cmd: %d time out", Cmd);
#endif
}


/*************************************************************************
* FUNCTION
*    MT9D112ConfigContext
*
* DESCRIPTION
*    This function config the context A and context B.
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
static void MT9D112ConfigContext(void)
{
  /* Register wizard */
  CamWriteCmosSensor(0x338C, 0x2703); /* Output Width (A) */
  CamWriteCmosSensor(0x3390, 0x0320); /* 00 */
  CamWriteCmosSensor(0x338C, 0x2705); /* Output Height (A) */
  CamWriteCmosSensor(0x3390, 0x0258); /* 600 */
  CamWriteCmosSensor(0x338C, 0x2707); /* Output Width (B) */
  CamWriteCmosSensor(0x3390, 0x0640); /* 1600 */
  CamWriteCmosSensor(0x338C, 0x2709); /* Output Height (B) */
  CamWriteCmosSensor(0x3390, 0x04B0); /* 1200 */
  CamWriteCmosSensor(0x338C, 0x270D); /* Row Start (A) */
  CamWriteCmosSensor(0x3390, 0x000 ); /* 0 */
  CamWriteCmosSensor(0x338C, 0x270F); /* Column Start (A) */
  CamWriteCmosSensor(0x3390, 0x000 ); /* 0 */
  CamWriteCmosSensor(0x338C, 0x2711); /* Row End (A) */
  CamWriteCmosSensor(0x3390, 0x4BD ); /* 1213 */
  CamWriteCmosSensor(0x338C, 0x2713); /* Column End (A) */
  CamWriteCmosSensor(0x3390, 0x64D ); /* 1613 */
  CamWriteCmosSensor(0x338C, 0x2715); /* Extra Delay (A) */
#if (defined(DRV_ISP_6235_SERIES) || defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6276_SERIES))
  CamWriteCmosSensor(0x3390, 0x1AE ); /* 430 */
#else
  CamWriteCmosSensor(0x3390, 0x019 ); /* 25 */
#endif
  CamWriteCmosSensor(0x338C, 0x2717); /* Row Speed (A) */
  CamWriteCmosSensor(0x3390, 0x2111); /* 8465 */
  CamWriteCmosSensor(0x338C, 0x271B); /* sensor_sample_time_pck (A) */
  CamWriteCmosSensor(0x3390, 0x024F); /* 591 */
  CamWriteCmosSensor(0x338C, 0x271D); /* sensor_fine_correction (A) */
  CamWriteCmosSensor(0x3390, 0x0102); /* 258 */
  CamWriteCmosSensor(0x338C, 0x271F); /* sensor_fine_IT_min (A) */
  CamWriteCmosSensor(0x3390, 0x0279); /* 633 */
  CamWriteCmosSensor(0x338C, 0x2721); /* sensor_fine_IT_max_margin (A) */
  CamWriteCmosSensor(0x3390, 0x0155); /* 341 */
  CamWriteCmosSensor(0x338C, 0x2727); /* sensor_dac_id_4_5 (A) */
  CamWriteCmosSensor(0x3390, 0x2020); /* 8224 */
  CamWriteCmosSensor(0x338C, 0x2729); /* sensor_dac_id_6_7 (A) */
  CamWriteCmosSensor(0x3390, 0x2020); /* 8224 */
  CamWriteCmosSensor(0x338C, 0x272B); /* sensor_dac_id_8_9 (A) */
  CamWriteCmosSensor(0x3390, 0x1020); /* 4128 */
  CamWriteCmosSensor(0x338C, 0x272D); /* sensor_dac_id_10_11 (A) */
  CamWriteCmosSensor(0x3390, 0x2007); /* 8199 */
  CamWriteCmosSensor(0x338C, 0x272F); /* Row Start (B) */
  CamWriteCmosSensor(0x3390, 0x004 ); /* 4 */
  CamWriteCmosSensor(0x338C, 0x2731); /* Column Start (B) */
  CamWriteCmosSensor(0x3390, 0x004 ); /* 4 */
  CamWriteCmosSensor(0x338C, 0x2733); /* Row End (B) */
  CamWriteCmosSensor(0x3390, 0x4BB ); /* 1211 */
  CamWriteCmosSensor(0x338C, 0x2735); /* Column End (B) */
  CamWriteCmosSensor(0x3390, 0x64B ); /* 1611 */
  CamWriteCmosSensor(0x338C, 0x2737); /* Extra Delay (B) */
  CamWriteCmosSensor(0x3390, 0x44E ); /* 1102 */
  CamWriteCmosSensor(0x338C, 0x2739); /* Row Speed (B) */
  CamWriteCmosSensor(0x3390, 0x2111); /* 8465 */
  CamWriteCmosSensor(0x338C, 0x273B); /* Read Mode (B) */
  CamWriteCmosSensor(0x3390, 0x0024); /* 36 */
  CamWriteCmosSensor(0x338C, 0x273D); /* sensor_sample_time_pck (B) */
  CamWriteCmosSensor(0x3390, 0x0120); /* 288 */
  CamWriteCmosSensor(0x338C, 0x273F); /* sensor_fine_correction (B) */
  CamWriteCmosSensor(0x3390, 0x00A4); /* 164 */
  CamWriteCmosSensor(0x338C, 0x2741); /* sensor_fine_IT_min (B) */
  CamWriteCmosSensor(0x3390, 0x0169); /* 361 */
  CamWriteCmosSensor(0x338C, 0x2743); /* sensor_fine_IT_max_margin (B) */
  CamWriteCmosSensor(0x3390, 0x00A4); /* 164 */
  CamWriteCmosSensor(0x338C, 0x2751); /* Crop_X0 (A) */
  CamWriteCmosSensor(0x3390, 0x0000); /* 0 */
  CamWriteCmosSensor(0x338C, 0x2753); /* Crop_X1 (A) */
  CamWriteCmosSensor(0x3390, 0x0320); /* 800 */
  CamWriteCmosSensor(0x338C, 0x2755); /* Crop_Y0 (A) */
  CamWriteCmosSensor(0x3390, 0x0000); /* 0 */
  CamWriteCmosSensor(0x338C, 0x2757); /* Crop_Y1 (A) */
  CamWriteCmosSensor(0x3390, 0x0258); /* 600 */
  CamWriteCmosSensor(0x338C, 0x275F); /* Crop_X0 (B) */
  CamWriteCmosSensor(0x3390, 0x0000); /* 0 */
  CamWriteCmosSensor(0x338C, 0x2761); /* Crop_X1 (B) */
  CamWriteCmosSensor(0x3390, 0x0640); /* 1600 */
  CamWriteCmosSensor(0x338C, 0x2763); /* Crop_Y0 (B) */
  CamWriteCmosSensor(0x3390, 0x0000); /* 0 */
  CamWriteCmosSensor(0x338C, 0x2765); /* Crop_Y1 (B) */
  CamWriteCmosSensor(0x3390, 0x04B0); /* 1200 */
  /* no need config search_f1/f2_50/60, for they use in auto FD!!! */
  CamWriteCmosSensor(0x338C, 0xA40D); /* Stat_min */
  CamWriteCmosSensor(0x3390, 0x02  ); /* 2 */
  CamWriteCmosSensor(0x338C, 0xA410); /* Min_amplitude */
  CamWriteCmosSensor(0x3390, 0x01  ); /* 1 */
}

/*************************************************************************
* FUNCTION
*     MT9D112LscSsetting
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
static void MT9D112LscSetting(void)
{
#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x34CE, 0x81E8);
  CamWriteCmosSensor(0x34D0, 0x6432);
  CamWriteCmosSensor(0x34D2, 0x3296);
  CamWriteCmosSensor(0x34D4, 0x9664);
  CamWriteCmosSensor(0x34D6, 0x5028);
  CamWriteCmosSensor(0x34D8, 0x2878);
  CamWriteCmosSensor(0x34DA, 0x7850);
  CamWriteCmosSensor(0x34DC, 0x0000);
  CamWriteCmosSensor(0x34DE, 0x00C5);
  CamWriteCmosSensor(0x34E6, 0x00C2);
  CamWriteCmosSensor(0x34EE, 0x0D83);
  CamWriteCmosSensor(0x34F6, 0x0EDA);
  CamWriteCmosSensor(0x3500, 0xA011);
  CamWriteCmosSensor(0x3508, 0xFDCB);
  CamWriteCmosSensor(0x3510, 0x3D56);
  CamWriteCmosSensor(0x3518, 0x4348);
  CamWriteCmosSensor(0x3520, 0x5D61);
  CamWriteCmosSensor(0x3528, 0x6256);
  CamWriteCmosSensor(0x3530, 0x0891);
  CamWriteCmosSensor(0x3538, 0xDBB6);
  CamWriteCmosSensor(0x354C, 0x0696);
  CamWriteCmosSensor(0x3544, 0x0607);
  CamWriteCmosSensor(0x355C, 0x06D3);
  CamWriteCmosSensor(0x3554, 0x06E8);
  CamWriteCmosSensor(0x34E0, 0x00D3);
  CamWriteCmosSensor(0x34E8, 0x00B1);
  CamWriteCmosSensor(0x34F0, 0x0FD4);
  CamWriteCmosSensor(0x34F8, 0x0F45);
  CamWriteCmosSensor(0x3502, 0xAED6);
  CamWriteCmosSensor(0x350A, 0xF28B);
  CamWriteCmosSensor(0x3512, 0x1C3D);
  CamWriteCmosSensor(0x351A, 0x4F4B);
  CamWriteCmosSensor(0x3522, 0x7B69);
  CamWriteCmosSensor(0x352A, 0x3B39);
  CamWriteCmosSensor(0x3532, 0x05E3);
  CamWriteCmosSensor(0x353A, 0xF82E);
  CamWriteCmosSensor(0x354E, 0x06BE);
  CamWriteCmosSensor(0x3546, 0x065E);
  CamWriteCmosSensor(0x355E, 0x0701);
  CamWriteCmosSensor(0x3556, 0x0674);
  CamWriteCmosSensor(0x34E4, 0x00A2);
  CamWriteCmosSensor(0x34EC, 0x006C);
  CamWriteCmosSensor(0x34F4, 0x0E45);
  CamWriteCmosSensor(0x34FC, 0x0080);
  CamWriteCmosSensor(0x3506, 0x9A26);
  CamWriteCmosSensor(0x350E, 0x22AF);
  CamWriteCmosSensor(0x3516, 0x3528);
  CamWriteCmosSensor(0x351E, 0x4941);
  CamWriteCmosSensor(0x3526, 0x473A);
  CamWriteCmosSensor(0x352E, 0x012C);
  CamWriteCmosSensor(0x3536, 0xD7E2);
  CamWriteCmosSensor(0x353E, 0x1F5A);
  CamWriteCmosSensor(0x3552, 0x0798);
  CamWriteCmosSensor(0x354A, 0x06A3);
  CamWriteCmosSensor(0x3562, 0x07EC);
  CamWriteCmosSensor(0x355A, 0x07DC);
  CamWriteCmosSensor(0x34E2, 0x00D3);
  CamWriteCmosSensor(0x34EA, 0x0099);
  CamWriteCmosSensor(0x34F2, 0x0D1C);
  CamWriteCmosSensor(0x34FA, 0x0C6F);
  CamWriteCmosSensor(0x3504, 0xCF19);
  CamWriteCmosSensor(0x350C, 0x19DE);
  CamWriteCmosSensor(0x3514, 0x3D38);
  CamWriteCmosSensor(0x351C, 0x7061);
  CamWriteCmosSensor(0x3524, 0x595B);
  CamWriteCmosSensor(0x352C, 0x103A);
  CamWriteCmosSensor(0x3534, 0xE090);
  CamWriteCmosSensor(0x353C, 0xA9F0);
  CamWriteCmosSensor(0x3550, 0x0641);
  CamWriteCmosSensor(0x3548, 0x0684);
  CamWriteCmosSensor(0x3560, 0x06C8);
  CamWriteCmosSensor(0x3558, 0x06BB);
  CamWriteCmosSensor(0x3540, 0x0100);
  CamWriteCmosSensor(0x3542, 0x0000);
  CamWriteCmosSensor(0x3210, 0x01FC);
#else
  /* [Lens Correction 85% 01/11/10 14:16:53] */
  CamWriteCmosSensor(0x34CE, 0x2160); /* LENS_CORRECTION_CONTROL */
  CamWriteCmosSensor(0x34D0, 0x6532); /* ZONE_BOUNDS_X1_X2 */
  CamWriteCmosSensor(0x34D2, 0x3297); /* ZONE_BOUNDS_X0_X3 */
  CamWriteCmosSensor(0x34D4, 0x9563); /* ZONE_BOUNDS_X4_X5 */
  CamWriteCmosSensor(0x34D6, 0x4925); /* ZONE_BOUNDS_Y1_Y2 */
  CamWriteCmosSensor(0x34D8, 0x266E); /* ZONE_BOUNDS_Y0_Y3 */
  CamWriteCmosSensor(0x34DA, 0x734D); /* ZONE_BOUNDS_Y4_Y5 */
  CamWriteCmosSensor(0x34DC, 0xFD02); /* CENTER_OFFSET */
  CamWriteCmosSensor(0x34DE, 0x01F4); /* FX_RED */
  CamWriteCmosSensor(0x34E6, 0x01BA); /* FY_RED */
  CamWriteCmosSensor(0x34EE, 0x0C0D); /* DF_DX_RED */
  CamWriteCmosSensor(0x34F6, 0x0C11); /* DF_DY_RED */
  CamWriteCmosSensor(0x3500, 0xEE25); /* SECOND_DERIV_ZONE_0_RED */
  CamWriteCmosSensor(0x3508, 0x26F1); /* SECOND_DERIV_ZONE_1_RED */
  CamWriteCmosSensor(0x3510, 0x2549); /* SECOND_DERIV_ZONE_2_RED */
  CamWriteCmosSensor(0x3518, 0x294E); /* SECOND_DERIV_ZONE_3_RED */
  CamWriteCmosSensor(0x3520, 0x2D5E); /* SECOND_DERIV_ZONE_4_RED */
  CamWriteCmosSensor(0x3528, 0x367C); /* SECOND_DERIV_ZONE_5_RED */
  CamWriteCmosSensor(0x3530, 0x17B1); /* SECOND_DERIV_ZONE_6_RED */
  CamWriteCmosSensor(0x3538, 0xF61C); /* SECOND_DERIV_ZONE_7_RED */
  CamWriteCmosSensor(0x354C, 0x0610); /* K_FACTOR_IN_K_FX_FY_R_TL */
  CamWriteCmosSensor(0x3544, 0x05AE); /* K_FACTOR_IN_K_FX_FY_R_TR */
  CamWriteCmosSensor(0x355C, 0x0617); /* K_FACTOR_IN_K_FX_FY_R_BL */
  CamWriteCmosSensor(0x3554, 0x05E1); /* K_FACTOR_IN_K_FX_FY_R_BR */
  CamWriteCmosSensor(0x34E0, 0x0224); /* FX_GREEN */
  CamWriteCmosSensor(0x34E8, 0x011A); /* FY_GREEN */
  CamWriteCmosSensor(0x34F0, 0x0BED); /* DF_DX_GREEN */
  CamWriteCmosSensor(0x34F8, 0x0E08); /* DF_DY_GREEN */
  CamWriteCmosSensor(0x3502, 0xE728); /* SECOND_DERIV_ZONE_0_GREEN */
  CamWriteCmosSensor(0x350A, 0x14DF); /* SECOND_DERIV_ZONE_1_GREEN */
  CamWriteCmosSensor(0x3512, 0x155A); /* SECOND_DERIV_ZONE_2_GREEN */
  CamWriteCmosSensor(0x351A, 0x1F39); /* SECOND_DERIV_ZONE_3_GREEN */
  CamWriteCmosSensor(0x3522, 0x1E3D); /* SECOND_DERIV_ZONE_4_GREEN */
  CamWriteCmosSensor(0x352A, 0x2643); /* SECOND_DERIV_ZONE_5_GREEN */
  CamWriteCmosSensor(0x3532, 0x11E0); /* SECOND_DERIV_ZONE_6_GREEN */
  CamWriteCmosSensor(0x353A, 0xFB1D); /* SECOND_DERIV_ZONE_7_GREEN */
  CamWriteCmosSensor(0x354E, 0x0620); /* K_FACTOR_IN_K_FX_FY_G1_TL */
  CamWriteCmosSensor(0x3546, 0x06D5); /* K_FACTOR_IN_K_FX_FY_G1_TR */
  CamWriteCmosSensor(0x355E, 0x062B); /* K_FACTOR_IN_K_FX_FY_G1_BL */
  CamWriteCmosSensor(0x3556, 0x068F); /* K_FACTOR_IN_K_FX_FY_G1_BR */
  CamWriteCmosSensor(0x34E4, 0x01A0); /* FX_BLUE */
  CamWriteCmosSensor(0x34EC, 0x00C1); /* FY_BLUE */
  CamWriteCmosSensor(0x34F4, 0x0CA9); /* DF_DX_BLUE */
  CamWriteCmosSensor(0x34FC, 0x0DDC); /* DF_DY_BLUE */
  CamWriteCmosSensor(0x3506, 0x0128); /* SECOND_DERIV_ZONE_0_BLUE */
  CamWriteCmosSensor(0x350E, 0x13EC); /* SECOND_DERIV_ZONE_1_BLUE */
  CamWriteCmosSensor(0x3516, 0x1440); /* SECOND_DERIV_ZONE_2_BLUE */
  CamWriteCmosSensor(0x351E, 0x1D2C); /* SECOND_DERIV_ZONE_3_BLUE */
  CamWriteCmosSensor(0x3526, 0x1129); /* SECOND_DERIV_ZONE_4_BLUE */
  CamWriteCmosSensor(0x352E, 0x1435); /* SECOND_DERIV_ZONE_5_BLUE */
  CamWriteCmosSensor(0x3536, 0x0CE5); /* SECOND_DERIV_ZONE_6_BLUE */
  CamWriteCmosSensor(0x353E, 0x0630); /* SECOND_DERIV_ZONE_7_BLUE */
  CamWriteCmosSensor(0x3552, 0x0705); /* K_FACTOR_IN_K_FX_FY_B_TL */
  CamWriteCmosSensor(0x354A, 0x070A); /* K_FACTOR_IN_K_FX_FY_B_TR */
  CamWriteCmosSensor(0x3562, 0x05D1); /* K_FACTOR_IN_K_FX_FY_B_BL */
  CamWriteCmosSensor(0x355A, 0x06B2); /* K_FACTOR_IN_K_FX_FY_B_BR */
  CamWriteCmosSensor(0x34E2, 0x016A); /* FX_GREEN2 */
  CamWriteCmosSensor(0x34EA, 0x00F6); /* FY_GREEN2 */
  CamWriteCmosSensor(0x34F2, 0x0D53); /* DF_DX_GREEN2 */
  CamWriteCmosSensor(0x34FA, 0x0DF1); /* DF_DY_GREEN2 */
  CamWriteCmosSensor(0x3504, 0xEC15); /* SECOND_DERIV_ZONE_0_GREEN2 */
  CamWriteCmosSensor(0x350C, 0x17ED); /* SECOND_DERIV_ZONE_1_GREEN2 */
  CamWriteCmosSensor(0x3514, 0x1B3D); /* SECOND_DERIV_ZONE_2_GREEN2 */
  CamWriteCmosSensor(0x351C, 0x2537); /* SECOND_DERIV_ZONE_3_GREEN2 */
  CamWriteCmosSensor(0x3524, 0x1742); /* SECOND_DERIV_ZONE_4_GREEN2 */
  CamWriteCmosSensor(0x352C, 0x1F52); /* SECOND_DERIV_ZONE_5_GREEN2 */
  CamWriteCmosSensor(0x3534, 0x0EB3); /* SECOND_DERIV_ZONE_6_GREEN2 */
  CamWriteCmosSensor(0x353C, 0xF534); /* SECOND_DERIV_ZONE_7_GREEN2 */
  CamWriteCmosSensor(0x3550, 0x06A6); /* K_FACTOR_IN_K_FX_FY_G2_TL */
  CamWriteCmosSensor(0x3548, 0x0700); /* K_FACTOR_IN_K_FX_FY_G2_TR */
  CamWriteCmosSensor(0x3560, 0x05FD); /* K_FACTOR_IN_K_FX_FY_G2_BL */
  CamWriteCmosSensor(0x3558, 0x0613); /* K_FACTOR_IN_K_FX_FY_G2_BR */
  CamWriteCmosSensor(0x3540, 0x0000); /* X2_FACTORS */
  CamWriteCmosSensor(0x3542, 0x0000); /* GLOBAL_OFFSET_FXY_FUNCTION */
  CamWriteCmosSensor(0x3210, 0x01FC); /* LENS_CORRECTION */
#endif
}

/*************************************************************************
* FUNCTION
*    MT9D112GammaSetting
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
static void MT9D112GammaSetting(void)
{
#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  CamWriteCmosSensor(0x338C, 0xA352); /* seq_mode */
  CamWriteCmosSensor(0x3390,   0x64);
  CamWriteCmosSensor(0x338C, 0xA118); /* LL_sat1 */
  CamWriteCmosSensor(0x3390,   0x64);
  CamWriteCmosSensor(0x338C, 0xA119); /* LL_sat2 */
  CamWriteCmosSensor(0x3390,   0x19);
  CamWriteCmosSensor(0x338C, 0xA76D); /* gamma_cont_A */
  CamWriteCmosSensor(0x3390,   0x03);
  CamWriteCmosSensor(0x338C, 0xA76E); /* gamma_cont_B */
  CamWriteCmosSensor(0x3390,   0x03);
  CamWriteCmosSensor(0x338C, 0xA76F); /* gamma_table_A_0 */
  CamWriteCmosSensor(0x3390,   0x00);
  CamWriteCmosSensor(0x338C, 0xA770); /* gamma_table_A_1 */
  CamWriteCmosSensor(0x3390,   0x27);
  CamWriteCmosSensor(0x338C, 0xA771); /* gamma_table_A_2 */
  CamWriteCmosSensor(0x3390,   0x35);
  CamWriteCmosSensor(0x338C, 0xA772); /* gamma_table_A_3 */
  CamWriteCmosSensor(0x3390,   0x49);
  CamWriteCmosSensor(0x338C, 0xA773); /* gamma_table_A_4 */
  CamWriteCmosSensor(0x3390,   0x64);
  CamWriteCmosSensor(0x338C, 0xA774); /* gamma_table_A_5 */
  CamWriteCmosSensor(0x3390,   0x77);
  CamWriteCmosSensor(0x338C, 0xA775); /* gamma_table_A_6 */
  CamWriteCmosSensor(0x3390,   0x88);
  CamWriteCmosSensor(0x338C, 0xA776); /* gamma_table_A_7 */
  CamWriteCmosSensor(0x3390,   0x97);
  CamWriteCmosSensor(0x338C, 0xA777); /* gamma_table_A_8 */
  CamWriteCmosSensor(0x3390,   0xA4);
  CamWriteCmosSensor(0x338C, 0xA778); /* gamma_table_A_9 */
  CamWriteCmosSensor(0x3390,   0xAF);
  CamWriteCmosSensor(0x338C, 0xA779); /* gamma_table_A_10 */
  CamWriteCmosSensor(0x3390,   0xBA);
  CamWriteCmosSensor(0x338C, 0xA77A); /* gamma_table_A_11 */
  CamWriteCmosSensor(0x3390,   0xC5);
  CamWriteCmosSensor(0x338C, 0xA77B); /* gamma_table_A_12 */
  CamWriteCmosSensor(0x3390,   0xCE);
  CamWriteCmosSensor(0x338C, 0xA77C); /* gamma_table_A_13 */
  CamWriteCmosSensor(0x3390,   0xD8);
  CamWriteCmosSensor(0x338C, 0xA77D); /* gamma_table_A_14 */
  CamWriteCmosSensor(0x3390,   0xE0);
  CamWriteCmosSensor(0x338C, 0xA77E); /* gamma_table_A_15 */
  CamWriteCmosSensor(0x3390,   0xE8);
  CamWriteCmosSensor(0x338C, 0xA77F); /* gamma_table_A_16 */
  CamWriteCmosSensor(0x3390,   0xF1);
  CamWriteCmosSensor(0x338C, 0xA780); /* gamma_table_A_17 */
  CamWriteCmosSensor(0x3390,   0xF8);
  CamWriteCmosSensor(0x338C, 0xA781); /* gamma_table_A_18 */
  CamWriteCmosSensor(0x3390,   0xFF);
  CamWriteCmosSensor(0x338C, 0xA782); /* gamma_table_B_0 */
  CamWriteCmosSensor(0x3390,   0x00);
  CamWriteCmosSensor(0x338C, 0xA783); /* gamma_table_B_1 */
  CamWriteCmosSensor(0x3390,   0x27);
  CamWriteCmosSensor(0x338C, 0xA784); /* gamma_table_B_2 */
  CamWriteCmosSensor(0x3390,   0x35);
  CamWriteCmosSensor(0x338C, 0xA785); /* gamma_table_B_3 */
  CamWriteCmosSensor(0x3390,   0x49);
  CamWriteCmosSensor(0x338C, 0xA786); /* gamma_table_B_4 */
  CamWriteCmosSensor(0x3390,   0x64);
  CamWriteCmosSensor(0x338C, 0xA787); /* gamma_table_B_5 */
  CamWriteCmosSensor(0x3390,   0x77);
  CamWriteCmosSensor(0x338C, 0xA788); /* gamma_table_B_6 */
  CamWriteCmosSensor(0x3390,   0x88);
  CamWriteCmosSensor(0x338C, 0xA789); /* gamma_table_B_7 */
  CamWriteCmosSensor(0x3390,   0x97);
  CamWriteCmosSensor(0x338C, 0xA78A); /* gamma_table_B_8 */
  CamWriteCmosSensor(0x3390,   0xA4);
  CamWriteCmosSensor(0x338C, 0xA78B); /* gamma_table_B_9 */
  CamWriteCmosSensor(0x3390,   0xAF);
  CamWriteCmosSensor(0x338C, 0xA78C); /* gamma_table_B_10 */
  CamWriteCmosSensor(0x3390,   0xBA);
  CamWriteCmosSensor(0x338C, 0xA78D); /* gamma_table_B_11 */
  CamWriteCmosSensor(0x3390,   0xC5);
  CamWriteCmosSensor(0x338C, 0xA78E); /* gamma_table_B_12 */
  CamWriteCmosSensor(0x3390,   0xCE);
  CamWriteCmosSensor(0x338C, 0xA78F); /* gamma_table_B_13 */
  CamWriteCmosSensor(0x3390,   0xD8);
  CamWriteCmosSensor(0x338C, 0xA790); /* gamma_table_B_14 */
  CamWriteCmosSensor(0x3390,   0xE0);
  CamWriteCmosSensor(0x338C, 0xA791); /* gamma_table_B_15 */
  CamWriteCmosSensor(0x3390,   0xE8);
  CamWriteCmosSensor(0x338C, 0xA792); /* gamma_table_B_16 */
  CamWriteCmosSensor(0x3390,   0xF1);
  CamWriteCmosSensor(0x338C, 0xA793); /* gamma_table_B_17 */
  CamWriteCmosSensor(0x3390,   0xF8);
  CamWriteCmosSensor(0x338C, 0xA794); /* gamma_table_B_18 */
  CamWriteCmosSensor(0x3390,   0xFF);
#else
  CamWriteCmosSensor(0x338C, 0xAB05); /* percent */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA76D); /* gamma_cont_A */
  CamWriteCmosSensor(0x3390, 0x0042);
  CamWriteCmosSensor(0x338C, 0xA76E); /* gamma_cont_B */
  CamWriteCmosSensor(0x3390, 0x0042);
#endif
}
/*************************************************************************
* FUNCTION
*    MT9D112LowLight
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
static void MT9D112LowLight(void)
{
#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  MT9D112WriteXDMA(0xA20E, MT9D112_MAX_ANALOG_GAIN); /* ae_max_virt_gain */
  MT9D112WriteXDMA(0xA115, 0xED); /* LLmode */
#else
  CamWriteCmosSensor(0x35A4, 0x0595); /* BRIGHT_COLOR_KILL_CONTROLS */
  CamWriteCmosSensor(0x338C, 0xA115); /* LLmode */
  CamWriteCmosSensor(0x3390, 0x00EF);
  CamWriteCmosSensor(0x338C, 0xA116); /* LLvirtGain1 */
  CamWriteCmosSensor(0x3390, 0x0030);
  CamWriteCmosSensor(0x338C, 0xA117); /* LLvirtGain2 */
  CamWriteCmosSensor(0x3390, 0x0050);
  CamWriteCmosSensor(0x338C, 0xA118); /* LLSat1 */
  CamWriteCmosSensor(0x3390, 0x00FF);
  CamWriteCmosSensor(0x338C, 0xA119); /* LLSat2 */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA11A); /* LLInterpThresh1 */
  CamWriteCmosSensor(0x3390, 0x000A);
  CamWriteCmosSensor(0x338C, 0xA11B); /* LLInterpThresh2 */
  CamWriteCmosSensor(0x3390, 0x0020);
  CamWriteCmosSensor(0x338C, 0xA11C); /* LLApCorr1 */
  CamWriteCmosSensor(0x3390, 0x0002);
  CamWriteCmosSensor(0x338C, 0xA11D); /* LLApCorr2 */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA11E); /* LLApThresh1 */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA11F); /* LLApThresh2 */
  CamWriteCmosSensor(0x3390, 0x0004);
  CamWriteCmosSensor(0x338C, 0xA13E); /* NR_TH1_R */
  CamWriteCmosSensor(0x3390, 0x0004);
  CamWriteCmosSensor(0x338C, 0xA13F); /* NR_TH1_G */
  CamWriteCmosSensor(0x3390, 0x000E);
  CamWriteCmosSensor(0x338C, 0xA140); /* NR_TH1_B */
  CamWriteCmosSensor(0x3390, 0x0004);
  CamWriteCmosSensor(0x338C, 0xA141); /* NR_TH1_OL */
  CamWriteCmosSensor(0x3390, 0x0004);
  CamWriteCmosSensor(0x338C, 0xA142); /* NR_TH2_R */
  CamWriteCmosSensor(0x3390, 0x0032);
  CamWriteCmosSensor(0x338C, 0xA143); /* NR_TH2_G */
  CamWriteCmosSensor(0x3390, 0x000F);
  CamWriteCmosSensor(0x338C, 0xA144); /* NR_TH2_B */
  CamWriteCmosSensor(0x3390, 0x0032);
  CamWriteCmosSensor(0x338C, 0xA145); /* NR_TH2_OL */
  CamWriteCmosSensor(0x3390, 0x0032);
  CamWriteCmosSensor(0x338C, 0xA146); /* NR_GainTH1 */
  CamWriteCmosSensor(0x3390, 0x0005);
  CamWriteCmosSensor(0x338C, 0xA147); /* NR_GainTH2 */
  CamWriteCmosSensor(0x3390, 0x003A);
#endif
}

/*************************************************************************
* FUNCTION
*    MT9D112AwbCcms
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
static void MT9D112AwbCcms(void)
{
#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  /* AWB and CCMS */
  CamWriteCmosSensor(0x338C, 0x2306); /* AWB_CCM_L_0 */
  CamWriteCmosSensor(0x3390, 0x018D);
  CamWriteCmosSensor(0x338C, 0x2308); /* AWB_CCM_L_1 */
  CamWriteCmosSensor(0x3390, 0xFF3E);
  CamWriteCmosSensor(0x338C, 0x230A); /* AWB_CCM_L_2 */
  CamWriteCmosSensor(0x3390, 0x007B);
  CamWriteCmosSensor(0x338C, 0x230C); /* AWB_CCM_L_3 */
  CamWriteCmosSensor(0x3390, 0xFEE9);
  CamWriteCmosSensor(0x338C, 0x230E); /* AWB_CCM_L_4 */
  CamWriteCmosSensor(0x3390, 0x02F4);
  CamWriteCmosSensor(0x338C, 0x2310); /* AWB_CCM_L_5 */
  CamWriteCmosSensor(0x3390, 0xFF4F);
  CamWriteCmosSensor(0x338C, 0x2312); /* AWB_CCM_L_6 */
  CamWriteCmosSensor(0x3390, 0xFF1E);
  CamWriteCmosSensor(0x338C, 0x2314); /* AWB_CCM_L_7 */
  CamWriteCmosSensor(0x3390, 0xFE2C);
  CamWriteCmosSensor(0x338C, 0x2316); /* AWB_CCM_L_8 */
  CamWriteCmosSensor(0x3390, 0x0434);
  CamWriteCmosSensor(0x338C, 0x2318); /* AWB_CCM_L_9 */
  CamWriteCmosSensor(0x3390, 0x0023);
  CamWriteCmosSensor(0x338C, 0x231A); /* AWB_CCM_L_10 */
  CamWriteCmosSensor(0x3390, 0x0050);
  CamWriteCmosSensor(0x338C, 0x231C); /* AWB_CCM_RL_0 */
  CamWriteCmosSensor(0x3390, 0x0104);
  CamWriteCmosSensor(0x338C, 0x231E); /* AWB_CCM_RL_1 */
  CamWriteCmosSensor(0x3390, 0xFED0);
  CamWriteCmosSensor(0x338C, 0x2320); /* AWB_CCM_RL_2 */
  CamWriteCmosSensor(0x3390, 0x001F);
  CamWriteCmosSensor(0x338C, 0x2322); /* AWB_CCM_RL_3 */
  CamWriteCmosSensor(0x3390, 0x000D);
  CamWriteCmosSensor(0x338C, 0x2324); /* AWB_CCM_RL_4 */
  CamWriteCmosSensor(0x3390, 0x00A4);
  CamWriteCmosSensor(0x338C, 0x2326); /* AWB_CCM_RL_5 */
  CamWriteCmosSensor(0x3390, 0xFF80);
  CamWriteCmosSensor(0x338C, 0x2328); /* AWB_CCM_RL_6 */
  CamWriteCmosSensor(0x3390, 0x0082);
  CamWriteCmosSensor(0x338C, 0x232A); /* AWB_CCM_RL_7 */
  CamWriteCmosSensor(0x3390, 0x008F);
  CamWriteCmosSensor(0x338C, 0x232C); /* AWB_CCM_RL_8 */
  CamWriteCmosSensor(0x3390, 0xFEB6);
  CamWriteCmosSensor(0x338C, 0x232E); /* AWB_CCM_RL_9 */
  CamWriteCmosSensor(0x3390, 0x0015);
  CamWriteCmosSensor(0x338C, 0x2330); /* AWB_CCM_RL_10 */
  CamWriteCmosSensor(0x3390, 0xFFDC);
  CamWriteCmosSensor(0x338C, 0xA348); /* gain buffer speed */
  CamWriteCmosSensor(0x3390, 0x0008);
  CamWriteCmosSensor(0x338C, 0xA349); /* jump divisor */
  CamWriteCmosSensor(0x3390, 0x0002);
  CamWriteCmosSensor(0x338C, 0xA34A); /* gain min */
  CamWriteCmosSensor(0x3390, 0x0059);
  CamWriteCmosSensor(0x338C, 0xA34B); /* gain max */
  CamWriteCmosSensor(0x3390, 0x00A6);
  CamWriteCmosSensor(0x338C, 0xA34F); /* ccm position min */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA350); /* ccm position max */
  CamWriteCmosSensor(0x3390, 0x007F);
  CamWriteCmosSensor(0x338C, 0xA352); /* saturation */
  CamWriteCmosSensor(0x3390, 0x0037); /* default 0x50 change 20080122 */
  CamWriteCmosSensor(0x338C, 0xA353); /* awb_mode */
  CamWriteCmosSensor(0x3390, 0x0002);
  CamWriteCmosSensor(0x338C, 0xA35B); /* steady bgain out min */
  CamWriteCmosSensor(0x3390, 0x0078);
  CamWriteCmosSensor(0x338C, 0xA35C); /* steady bgain out max */
  CamWriteCmosSensor(0x3390, 0x0086);
  CamWriteCmosSensor(0x338C, 0xA35D); /* steady bgain in min */
  CamWriteCmosSensor(0x3390, 0x007E); 
  CamWriteCmosSensor(0x338C, 0xA35E); /* steady bgain in max */
  CamWriteCmosSensor(0x3390, 0x0082);
  CamWriteCmosSensor(0x338C, 0x235F); /* cntpcxith */
  CamWriteCmosSensor(0x3390, 0x0040);
  CamWriteCmosSensor(0x338C, 0xA361); /* TG_min0 */
  CamWriteCmosSensor(0x3390, 0x00D9);
  CamWriteCmosSensor(0x338C, 0xA362); /* TG_max0 */
  CamWriteCmosSensor(0x3390, 0x00E1);
  CamWriteCmosSensor(0x338C, 0xA302); /* window pos */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA303); /* window size */
  CamWriteCmosSensor(0x3390, 0x00EF);
#else
  CamWriteCmosSensor(0x338C, 0x2306); /* AWB_CCM_L_0 */
  CamWriteCmosSensor(0x3390, 0x01F3);
  CamWriteCmosSensor(0x338C, 0x2308); /* AWB_CCM_L_1 */
  CamWriteCmosSensor(0x3390, 0xFF31);
  CamWriteCmosSensor(0x338C, 0x230A); /* AWB_CCM_L_2 */
  CamWriteCmosSensor(0x3390, 0x0007);
  CamWriteCmosSensor(0x338C, 0x230C); /* AWB_CCM_L_3 */
  CamWriteCmosSensor(0x3390, 0xFFB5);
  CamWriteCmosSensor(0x338C, 0x230E); /* AWB_CCM_L_4 */
  CamWriteCmosSensor(0x3390, 0x01D0);
  CamWriteCmosSensor(0x338C, 0x2310); /* AWB_CCM_L_5 */
  CamWriteCmosSensor(0x3390, 0xFFA8);
  CamWriteCmosSensor(0x338C, 0x2312); /* AWB_CCM_L_6 */
  CamWriteCmosSensor(0x3390, 0xFFC8);
  CamWriteCmosSensor(0x338C, 0x2314); /* AWB_CCM_L_7 */
  CamWriteCmosSensor(0x3390, 0xFE9B);
  CamWriteCmosSensor(0x338C, 0x2316); /* AWB_CCM_L_8 */
  CamWriteCmosSensor(0x3390, 0x02EE);
  CamWriteCmosSensor(0x338C, 0x2318); /* AWB_CCM_L_9 */
  CamWriteCmosSensor(0x3390, 0x001E);
  CamWriteCmosSensor(0x338C, 0x231A); /* AWB_CCM_L_10 */
  CamWriteCmosSensor(0x3390, 0x003F);
  CamWriteCmosSensor(0x338C, 0x231C); /* AWB_CCM_RL_0 */
  CamWriteCmosSensor(0x3390, 0xFFC0);
  CamWriteCmosSensor(0x338C, 0x231E); /* AWB_CCM_RL_1 */
  CamWriteCmosSensor(0x3390, 0x0047);
  CamWriteCmosSensor(0x338C, 0x2320); /* AWB_CCM_RL_2 */
  CamWriteCmosSensor(0x3390, 0xFFF9);
  CamWriteCmosSensor(0x338C, 0x2322); /* AWB_CCM_RL_3 */
  CamWriteCmosSensor(0x3390, 0x0017);
  CamWriteCmosSensor(0x338C, 0x2324); /* AWB_CCM_RL_4 */
  CamWriteCmosSensor(0x3390, 0x0017);
  CamWriteCmosSensor(0x338C, 0x2326); /* AWB_CCM_RL_5 */
  CamWriteCmosSensor(0x3390, 0xFFDE);
  CamWriteCmosSensor(0x338C, 0x2328); /* AWB_CCM_RL_6 */
  CamWriteCmosSensor(0x3390, 0x003F);
  CamWriteCmosSensor(0x338C, 0x232A); /* AWB_CCM_RL_7 */
  CamWriteCmosSensor(0x3390, 0x00DB);
  CamWriteCmosSensor(0x338C, 0x232C); /* AWB_CCM_RL_8 */
  CamWriteCmosSensor(0x3390, 0xFEC5);
  CamWriteCmosSensor(0x338C, 0x232E); /* AWB_CCM_RL_9 */
  CamWriteCmosSensor(0x3390, 0x0017);
  CamWriteCmosSensor(0x338C, 0x2330); /* AWB_CCM_RL_10 */
  CamWriteCmosSensor(0x3390, 0xFFEA);
  CamWriteCmosSensor(0x338C, 0xA348); /* AWB_GAIN_BUFFER_SPEED */
  CamWriteCmosSensor(0x3390, 0x0008);
  CamWriteCmosSensor(0x338C, 0xA349); /* AWB_JUMP_DIVISOR */
  CamWriteCmosSensor(0x3390, 0x0002);
  CamWriteCmosSensor(0x338C, 0xA34A); /* AWB_GAIN_MIN */
  CamWriteCmosSensor(0x3390, 0x0059);
  CamWriteCmosSensor(0x338C, 0xA34B); /* AWB_GAIN_MAX */
  CamWriteCmosSensor(0x3390, 0x00A6);
  CamWriteCmosSensor(0x338C, 0xA34F); /* AWB_CCM_POSITION_MIN */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA350); /* AWB_CCM_POSITION_MAX */
  CamWriteCmosSensor(0x3390, 0x007F);
  CamWriteCmosSensor(0x338C, 0xA353); /* AWB_MODE */
  CamWriteCmosSensor(0x3390, 0x0001);
  CamWriteCmosSensor(0x338C, 0xA35B); /* AWB_STEADY_BGAIN_OUT_MIN */
  CamWriteCmosSensor(0x3390, 0x0078);
  CamWriteCmosSensor(0x338C, 0xA35C); /* AWB_STEADY_BGAIN_OUT_MAX */
  CamWriteCmosSensor(0x3390, 0x0086);
  CamWriteCmosSensor(0x338C, 0xA35D); /* AWB_STEADY_BGAIN_IN_MIN */
  CamWriteCmosSensor(0x3390, 0x007E);
  CamWriteCmosSensor(0x338C, 0xA35E); /* AWB_STEADY_BGAIN_IN_MAX */
  CamWriteCmosSensor(0x3390, 0x0082);
  CamWriteCmosSensor(0x338C, 0x235F); /* AWB_CNT_PXL_TH */
  CamWriteCmosSensor(0x3390, 0x0040);
  CamWriteCmosSensor(0x338C, 0xA361); /* AWB_TG_MIN0 */
  CamWriteCmosSensor(0x3390, 0x00D8);
  CamWriteCmosSensor(0x338C, 0xA362); /* AWB_TG_MAX0 */
  CamWriteCmosSensor(0x3390, 0x00E8);
  CamWriteCmosSensor(0x338C, 0xA302); /* AWB_WINDOW_POS */
  CamWriteCmosSensor(0x3390, 0x0000);
  CamWriteCmosSensor(0x338C, 0xA303); /* AWB_WINDOW_SIZE */
  CamWriteCmosSensor(0x3390, 0x00EF);
#endif
}
/*************************************************************************
* FUNCTION
*    MT9D112_set_param_3a_enable
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
static kal_uint32 MT9D112Set3AEnable(kal_uint32 Para)
{
  kal_uint8 SeqPreview1AE, SeqPreview1FD, SeqPreview1Awb, SeqPreview1Hg;
  
  if (MT9D112Sensor.Enable3A == Para) return KAL_TRUE;
  MT9D112Sensor.Enable3A = Para;
  if (MT9D112Sensor.Enable3A)
  {
    SeqPreview1FD = 2;
    SeqPreview1AE = SeqPreview1Awb = SeqPreview1Hg = 3;
  }
  else
  {
    SeqPreview1AE = SeqPreview1Awb = SeqPreview1Hg = SeqPreview1FD = 0;
  }
  MT9D112WriteXDMA(0xA129, SeqPreview1AE);
  MT9D112WriteXDMA(0xA12A, SeqPreview1FD);
  MT9D112WriteXDMA(0xA12B, SeqPreview1Awb);
  MT9D112WriteXDMA(0xA12D, SeqPreview1Hg);
  MT9D112SetCmd(6); /* refresh mode */
  
  return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*    MT9D112HalfAdjust
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
__inline static kal_uint32 MT9D112HalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    MT9D112WritePvBlank
*
* DESCRIPTION
*    This function add dummy_pixel and dummy_line in capture state.
*    MUST BE INVOKED BEFORE MT9D112_set_cmd(2) !!!
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

static void MT9D112WritePvBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
  const kal_uint16 FrameHeight = MT9D112_PV_PERIOD_LINE_NUMS + Vblank;
  const kal_uint16 LineLength = MT9D112_PV_PERIOD_PIXEL_NUMS + Hblank;

  #ifdef MT9D112_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HB:%x,VB:%x",Hblank,Vblank);
  #endif
  
  if (MT9D112Sensor.PvFrameHeight == FrameHeight && MT9D112Sensor.PvLineLength == LineLength) return;
  MT9D112Sensor.PvFrameHeight = FrameHeight;
  MT9D112Sensor.PvLineLength = LineLength;
  MT9D112WriteXDMA(0x2723, FrameHeight); /* preview frame length */
  MT9D112WriteXDMA(0x2725, LineLength); /* preview line length */
  MT9D112WriteXDMA(0x2411, MT9D112HalfAdjust(MT9D112Sensor.Pclk / 2, LineLength * MT9D112_NUM_60HZ * 2));/* preview fd_r9_step_f60 */
  MT9D112WriteXDMA(0x2413, MT9D112HalfAdjust(MT9D112Sensor.Pclk / 2, LineLength * MT9D112_NUM_50HZ * 2));/* preview fd_r9_step_f50 */
  MT9D112SetCmd(6); /* refresh mode */
}

/*************************************************************************
* FUNCTION
*    MT9D112WriteCapBlank
*
* DESCRIPTION
*    This function add dummy_pixel and dummy_line in capture state.
*    MUST BE INVOKED BEFORE MT9D112_set_cmd(2) !!!
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
static void MT9D112WriteCapBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
  const kal_uint16 FrameHeight = MT9D112_FULL_PERIOD_LINE_NUMS + Vblank;
  const kal_uint16 LineLength = MT9D112_FULL_PERIOD_PIXEL_NUMS + Hblank;

#ifdef MT9D112_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HB:%x,VB:%x",Hblank,Vblank);
#endif
  
  if (MT9D112Sensor.CapFrameHeight == FrameHeight && MT9D112Sensor.CapLineLength == LineLength) return;
  MT9D112Sensor.CapFrameHeight = FrameHeight;
  MT9D112Sensor.CapLineLength = LineLength;
  MT9D112WriteXDMA(0x2745, FrameHeight); /* preview frame length */
  MT9D112WriteXDMA(0x2747, LineLength); /* preview line length */
  MT9D112WriteXDMA(0x2415, MT9D112HalfAdjust(MT9D112Sensor.Pclk / 2, LineLength * MT9D112_NUM_60HZ * 2));/* preview fd_r9_step_f60 */
  MT9D112WriteXDMA(0x2417, MT9D112HalfAdjust(MT9D112Sensor.Pclk / 2, LineLength * MT9D112_NUM_50HZ * 2));/* preview fd_r9_step_f50 */
  MT9D112SetCmd(6); /* refresh mode */
}

    



/*************************************************************************
* FUNCTION
*    MT9D112SetShutterStep
*
* DESCRIPTION
*    This function is to calculate & set shutter step register .
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
static void MT9D112SetShutterStep(void)
{       
  const kal_uint8  Banding;// = ((MT9D112Sensor.Banding == CAM_BANDING_50HZ) ? MT9D112_NUM_50HZ : MT9D112_NUM_60HZ);
  const kal_uint16 ShutterStep; //= MT9D112HalfAdjust(MT9D112Sensor.Pclk / 2, (MT9D112Sensor.Hblank + MT9D112_PV_PERIOD_PIXEL_NUMS) * Banding);
  return;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MT9D112_DEBUG
/* under construction !*/
#endif
#endif

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
#ifdef MT9D112_DEBUG
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MT9D112_DEBUG
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

static void MT9D112CalFps(void)
{
  const kal_uint16 DummyPixel = MT9D112Sensor.PvLineLength - MT9D112_PV_PERIOD_PIXEL_NUMS;
  const kal_uint8 Banding = ((MT9D112Sensor.Banding == CAM_BANDING_50HZ) ? MT9D112_NUM_50HZ : MT9D112_NUM_60HZ);
  const kal_uint16 PvMaxFps = MT9D112Sensor.Pclk * MT9D112_FPS(1) / (2 * MT9D112Sensor.PvLineLength * MT9D112Sensor.PvFrameHeight);
  kal_uint16 PvMinFps = MT9D112Sensor.NightMode ? MT9D112Sensor.NightFps : MT9D112Sensor.NormalFps;
  kal_uint16 MaxExposureLines;
  
  if (PvMinFps > PvMaxFps) PvMinFps = PvMaxFps;
  kal_prompt_trace(MOD_ENG,"%d,%d,%d,%d",PvMinFps,PvMaxFps,MT9D112Sensor.VideoMode,MT9D112Sensor.Fps);
  if (MT9D112Sensor.VideoMode) /* fix frame rate when video mode */
  {
  	PvMinFps = MT9D112Sensor.Fps; 
  	kal_prompt_trace(MOD_ENG,"fix frame rate when video mode");
    MaxExposureLines = MT9D112Sensor.Pclk * MT9D112_FPS(1) / (2 * PvMinFps * MT9D112Sensor.PvLineLength);
    MT9D112WritePvBlank(DummyPixel, MaxExposureLines - MT9D112_PV_PERIOD_LINE_NUMS);
	kal_prompt_trace(MOD_ENG,"%d,%d",MaxExposureLines,PvMaxFps);
  }
  MT9D112WriteXDMA(0xA20C, Banding * 2 * MT9D112_FPS(1) / PvMinFps);
  MT9D112SetCmd(5); /* refresh */
}


/*************************************************************************
* FUNCTION
*    MT9D112SetHVMirror
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
static void MT9D112SetHVMirror(kal_uint8 Mirror)
{
  kal_uint8 Ctrl = 0;
#ifdef MT9D112_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 
  if (MT9D112Sensor.Mirror == Mirror) return;
	MT9D112Sensor.Mirror = Mirror;

  switch (MT9D112Sensor.Mirror)
  {
  case IMAGE_SENSOR_MIRROR_HV: Ctrl = 0x03; break;
  case IMAGE_SENSOR_MIRROR_H:  Ctrl = 0x01; break;
  case IMAGE_SENSOR_MIRROR_V:  Ctrl = 0x02; break;
  default: break;
  }
  SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
  MT9D112WriteXDMA(0x2719, 0x046C|Ctrl); /* preview read mode */
  MT9D112WriteXDMA(0x273B, 0x0024|Ctrl); /* snapshot/video read mode */
  MT9D112SetCmd(6); /* refresh mode */
  //CamWriteCmosSensor(0x04, Ctrl);
}

/*************************************************************************
* FUNCTION
*    MT9D112Ev
*
* DESCRIPTION
*    MT9D112 EV setting.
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
static MM_ERROR_CODE_ENUM MT9D112Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    kal_uint8 EvTemp = 0x00;
	if (MT9D112Sensor.Exposure == In->FeatureSetValue) return MM_ERROR_NONE;
  	MT9D112Sensor.Exposure = In->FeatureSetValue;
#ifdef MT9D112_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: EvTemp = MT9D112_AE_TARGET_ZERO - 40; break;
    case CAM_EV_NEG_3_3: EvTemp = MT9D112_AE_TARGET_ZERO - 30; break;
    case CAM_EV_NEG_2_3: EvTemp = MT9D112_AE_TARGET_ZERO - 20; break;
    case CAM_EV_NEG_1_3: EvTemp = MT9D112_AE_TARGET_ZERO - 10; break;
    case CAM_EV_ZERO:    EvTemp = MT9D112_AE_TARGET_ZERO; break;
    case CAM_EV_POS_1_3: EvTemp = MT9D112_AE_TARGET_ZERO + 10; break;
    case CAM_EV_POS_2_3: EvTemp = MT9D112_AE_TARGET_ZERO + 20; break;
    case CAM_EV_POS_3_3: EvTemp = MT9D112_AE_TARGET_ZERO + 30; break;
    case CAM_EV_POS_4_3: EvTemp = MT9D112_AE_TARGET_ZERO + 40; break;
    default: return MM_ERROR_INVALID_PARAMETER;//break;
    }
	MT9D112WriteXDMA(0xA206, EvTemp); /* ae_base_target */
    //CamWriteCmosSensor(0xd7, EvTemp);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112Contrast
*
* DESCRIPTION
*    MT9D112 Contrast setting.
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
static MM_ERROR_CODE_ENUM MT9D112Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_FALSE;
    EvPara->ItemCount = 3;
    EvPara->SupportItem[0] = CAM_CONTRAST_HIGH;
    EvPara->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    EvPara->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8 Contrast = 0x10;
	return MM_ERROR_NONE;
#ifdef MT9D112_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   Contrast = 0x18; break;
    case CAM_CONTRAST_MEDIUM: Contrast = 0x10; break;
    case CAM_CONTRAST_LOW:    Contrast = 0x08; break;
    default: break;
    }
    CamWriteCmosSensor(0xd4, Contrast);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112Wb
*
* DESCRIPTION
*    MT9D112 WB setting.
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
static MM_ERROR_CODE_ENUM MT9D112Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	kal_uint8 AwbCcmPosition;
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
#ifdef MT9D112_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
	if (MT9D112Sensor.Wb == In->FeatureSetValue) return MM_ERROR_NONE;
  	MT9D112Sensor.Wb = In->FeatureSetValue;
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      /* CAM_WB_AUTO mode should not update R/G/B gains */
      MT9D112WriteXDMA(0xA353, 0x02);
	  return MM_ERROR_NONE;
      
    case CAM_WB_CLOUD:
	  AwbCcmPosition = 0x6F;
      break;
    case CAM_WB_DAYLIGHT:
      AwbCcmPosition = 0x7F;
      break;
    case CAM_WB_INCANDESCENCE:
      AwbCcmPosition = 0x10;
      break;
    case CAM_WB_FLUORESCENT:
      AwbCcmPosition = 0x79;
      break;
    case CAM_WB_TUNGSTEN:
      AwbCcmPosition = 0x00;
      break;
    default:
	  return MM_ERROR_INVALID_PARAMETER;
      //break;
    }
	MT9D112WriteXDMA(0xA353, 0x22); /* awb_mode */
    MT9D112WriteXDMA(0xA351, AwbCcmPosition); /* awb_ccm_position */
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MT9D112Effect
*
* DESCRIPTION
*    MT9D112 Effect setting.
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
static MM_ERROR_CODE_ENUM MT9D112Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  kal_uint8 SpecEffects;
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
#ifdef MT9D112_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
	if (MT9D112Sensor.Effect == In->FeatureSetValue) return MM_ERROR_NONE;
	  MT9D112Sensor.Effect = In->FeatureSetValue;

    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL: /* normal */
    SpecEffects = 0;
    break;
  	case CAM_EFFECT_ENC_GRAYSCALE: /* Mono */
    SpecEffects = 1;
    break;
  	case CAM_EFFECT_ENC_SEPIA: /* sepia */
    SpecEffects = 2;
    CamWriteCmosSensor(0x334A, 0xB023); /* sepia constants */
    break;
  	case CAM_EFFECT_ENC_SEPIAGREEN: /* sepial-green */
    SpecEffects = 2;
    CamWriteCmosSensor(0x334A, 0xB0CD);
    break;
  	case CAM_EFFECT_ENC_SEPIABLUE: /* sepial-Blue */
    SpecEffects = 2;
    CamWriteCmosSensor(0x334A, 0x25F0);
    break;
  	case CAM_EFFECT_ENC_COLORINV: /* Negative */
    SpecEffects = 3;
    break;
  	default:
    return MM_ERROR_INVALID_PARAMETER;
  }
  MT9D112WriteXDMA(0x2799, 0x6440|SpecEffects); /* preview spec_effects */
  MT9D112WriteXDMA(0x279B, 0x6440|SpecEffects); /* snapshot/video spec_effects */
  MT9D112SetCmd(5); /* refresh */
  return MM_ERROR_NONE;
}
}
/*************************************************************************
* FUNCTION
*    MT9D112StillCaptureSize
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
static MM_ERROR_CODE_ENUM MT9D112StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 4;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
	CapSize->SupportItem[1] = CAM_IMAGE_SIZE_1M;
	CapSize->SupportItem[2] = CAM_IMAGE_SIZE_2M;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112Banding
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
static MM_ERROR_CODE_ENUM MT9D112Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef MT9D112_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
   
if (MT9D112Sensor.Banding == In->FeatureSetValue) return MM_ERROR_NONE;
  MT9D112Sensor.Banding = In->FeatureSetValue;
  switch (MT9D112Sensor.Banding)
  {
  case CAM_BANDING_50HZ:
    MT9D112WriteXDMA(0xA404, 0xC0); /* fd_mode */
    break;
  case CAM_BANDING_60HZ:
    MT9D112WriteXDMA(0xA404, 0x80); /* fd_mode */
    break;
  default:
    return MM_ERROR_INVALID_PARAMETER;
  }
  MT9D112SetCmd(6); /* refresh mode */
  MT9D112CalFps(); /* need cal new fps */
  
  return MM_ERROR_NONE;
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112GetSensorInfo
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
static void MT9D112GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = MT9D112_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
#if (defined(DRV_ISP_6276_SERIES))
  Info->PreviewMclkFreq = 12000000;
  Info->CaptureMclkFreq = 12000000;
  Info->VideoMclkFreq = 12000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  Info->PreviewWidth = MT9D112_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->PreviewHeight = MT9D112_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->FullWidth = MT9D112_IMAGE_SENSOR_FULL_WIDTH_DRV;
  Info->FullHeight = MT9D112_IMAGE_SENSOR_FULL_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    MT9D112DetectSensorId
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
static kal_uint32 MT9D112DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM MT9D112SensorClose(void);
  kal_uint16 MT9D112PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == MT9D112Sensor.SensorIdx)
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
      SensorId = MT9D112PowerOn();
      MT9D112SensorClose();
#ifdef MT9D112_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"MT9D112DetectSensorId:%x",SensorId);
#endif
      if (MT9D112_SENSOR_ID == SensorId)
      {
        return MT9D112_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    MT9D112InitOperationPara
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
static void MT9D112InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 3; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    MT9D112AeEnable
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
static void MT9D112AeEnable(kal_bool Enable)
{
  kal_uint8 AeTemp;
  
  if (MT9D112Sensor.BypassAe)
	  {
		  Enable = KAL_FALSE;
	  }

  if (Enable)
  {
    AeTemp = 0x80;
  }
  else
  {
    AeTemp = 0x00;
  }
#ifdef MT9D112_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x40, AeTemp);

  
}

/*************************************************************************
* FUNCTION
*    MT9D112AwbEnable
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
static void MT9D112AwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;

  if (MT9D112Sensor.BypassAwb)
  {
	  Enable = KAL_FALSE;
  }

  if (Enable)
  {
    AwbTemp = 0x02;
  }
  else
  {
    AwbTemp = 0x22;
  }
#ifdef MT9D112_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  MT9D112WriteXDMA(0xA353, AwbTemp);
 // CamWriteCmosSensor(0x60, AwbTemp);

}

/*************************************************************************
* FUNCTION
*    MT9D112NightMode
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
static void MT9D112NightMode(kal_bool Enable)
{   

#ifdef MT9D112_DEBUG
	kal_wap_trace(MOD_ENG,TRACE_INFO, "MT9D112 NightMode %d",Enable);
#endif


  if (MT9D112Sensor.NightMode == Enable && !MT9D112Sensor.VideoMode) return;
  MT9D112Sensor.NightMode = Enable;
  MT9D112CalFps(); /* need cal new fps */

}
/*************************************************************************
* FUNCTION
*    MT9D112SceneMode
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
static MM_ERROR_CODE_ENUM MT9D112SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    MT9D112NightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112InitialSetting
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
static void MT9D112InitialSetting(void)
{
	  MT9D112Sensor.Initial = MT9D112Sensor.FirstPv = KAL_TRUE;
	  CamWriteCmosSensor(0x3386, 0x0001); /* Reset */
	  kal_sleep_task(2);
	  CamWriteCmosSensor(0x3386, 0x0000);
	  kal_sleep_task(2);
	  CamWriteCmosSensor(0x301A, 0x0ACC); /* reset_register */
	  CamWriteCmosSensor(0x3202, 0x0008); /* standby control */
	  kal_sleep_task(5);
	  /* PLL VCO = MCLK * 2 * M / (N + 1), PCLK = VCO / (P1 + 1) */
	  /* MT9D112Sensor.pclk initial in MT9D112_init function */
	  CamWriteCmosSensor(0x341E, 0x8F09); /* PLL/ Clk_in control: BYPASS PLL */
#if (defined(DRV_ISP_6235_SERIES) || defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6276_SERIES))
	  CamWriteCmosSensor(0x341C, 0x0020); /* PLL Control */
	  kal_sleep_task(1); /* Allow PLL to lock */
	  CamWriteCmosSensor(0x341E, 0x8F09); /* PLL/ Clk_in control: PLL ON, bypassed */
	  kal_sleep_task(1);
	  CamWriteCmosSensor(0x341E, 0x8F08); /* PLL/ Clk_in control: USE PLL */
#elif(defined(DRV_ISP_6276_SERIES_1))
	/* 26M in ,52M out*/
	  CamWriteCmosSensor(0x341C, 0x0120); /* PLL Control */

	  //CamWriteCmosSensor(0x341C, 0x0120); /* PLL Control */
	  kal_sleep_task(1); /* Allow PLL to lock */
	  CamWriteCmosSensor(0x341E, 0x8F09); /* PLL/ Clk_in control: PLL ON, bypassed */
	  kal_sleep_task(1);
	  CamWriteCmosSensor(0x341E, 0x8F08); /* PLL/ Clk_in control: USE PLL */
#else
	  /* Bypass PLL */
#endif
	  CamWriteCmosSensor(0x3044, 0x0540);
	  CamWriteCmosSensor(0x3216, 0x02CF); /* Internal Clock Control */
	  CamWriteCmosSensor(0x321C, 0x0402); /* OF Control Status */
	  CamWriteCmosSensor(0x3212, 0x0001); /* Factory Bypass */
	  CamWriteCmosSensor(0x3214, 0x06E6); /* pad slew */
	  
	  MT9D112ConfigContext();
	  
	  MT9D112Sensor.PvFrameHeight = MT9D112Sensor.PvLineLength = 0; /* force config preview dummy */
	  MT9D112WritePvBlank(0, 0);
	  
	  MT9D112Sensor.CapFrameHeight = MT9D112Sensor.CapLineLength = 0; /* force config capture dummy */
	  MT9D112WriteCapBlank(0, 0);
	  
	  MT9D112LscSetting();
	  MT9D112GammaSetting();
	  MT9D112LowLight();
	  MT9D112AwbCcms();
	  
	  MT9D112WriteXDMA(0xA120, 0x02); /* seq_cap_mode */
	  MT9D112WriteXDMA(0xA130, 0x00); /* preview leave: AE off */
	  MT9D112WriteXDMA(0xA132, 0x00); /* preview leave: AWB off */
	  MT9D112WriteXDMA(0xA134, 0x00); /* preview leave: HG off */
	  
	  /* default setting */
	  MT9D112Sensor.VideoMode = KAL_FALSE;
	  MT9D112Sensor.NormalFps = MT9D112_FPS(10);
	  MT9D112Sensor.NightFps = MT9D112_FPS(5);
	  
	  MT9D112Sensor.Mirror = !IMAGE_SENSOR_MIRROR_NORMAL; /* force config mirror */
	  MT9D112SetHVMirror(IMAGE_SENSOR_MIRROR_NORMAL);

	  /*******************************************feature control*************************************/
	  MT9D112Sensor.Banding = !CAM_BANDING_50HZ; /* force config banding */
	  //MT9D112_yuv_sensor_setting(CAM_PARAM_BANDING, CAM_BANDING_50HZ);//*******************************************feature control
	  MT9D112Sensor.Banding = CAM_BANDING_50HZ; 
	  MT9D112WriteXDMA(0xA404, 0xC0); /* fd_mode */
  	  MT9D112SetCmd(6); /* refresh mode */
  	  MT9D112CalFps(); /* need cal new fps */
	  
	  MT9D112Sensor.Effect = !CAM_EFFECT_ENC_NORMAL; /* force config effect */
	  //MT9D112_yuv_sensor_setting(CAM_PARAM_EFFECT, CAM_EFFECT_ENC_NORMAL);
	  MT9D112Sensor.Effect = CAM_EFFECT_ENC_NORMAL;
	  MT9D112WriteXDMA(0x2799, 0x6440|CAM_EFFECT_ENC_NORMAL); /* preview spec_effects */
  	  MT9D112WriteXDMA(0x279B, 0x6440|CAM_EFFECT_ENC_NORMAL); /* snapshot/video spec_effects */
      MT9D112SetCmd(5); /* refresh */
	  
	  MT9D112Sensor.Exposure = !CAM_EV_ZERO; /* force config exposure */
	  //MT9D112_yuv_sensor_setting(CAM_PARAM_EXPOSURE, CAM_EV_ZERO);
	  MT9D112Sensor.Exposure = CAM_EV_ZERO;
	  MT9D112WriteXDMA(0xA206, MT9D112_AE_TARGET_ZERO);
	  
	  MT9D112Sensor.Wb = !CAM_WB_AUTO; /* force config wb */
	  //MT9D112_yuv_sensor_setting(CAM_PARAM_WB, CAM_WB_AUTO);
	  MT9D112Sensor.Wb = CAM_WB_AUTO;
	  MT9D112WriteXDMA(0xA353, 0x02);
	  
	  MT9D112Sensor.NightMode = !KAL_FALSE; /* force config night mode */
	  //MT9D112_yuv_sensor_setting(CAM_PARAM_NIGHT_MODE, KAL_FALSE);
	  MT9D112NightMode(KAL_FALSE);
	  
	  MT9D112Sensor.Enable3A = !KAL_TRUE; /* force config 3a */
	  MT9D112Set3AEnable(KAL_TRUE);
	  /*******************************************feature control**************************************/ 
//#ifdef __MT9D112_TEST_PATTERN__
	  /* 00: disabled 01: flat field 02: vertical ramp 03: color bar 04: vertical stripes 05: pseudo-random */
	  CamWriteCmosSensor(0x3290, 0x00);
//#endif
	  MT9D112Sensor.Initial = KAL_FALSE;
	  MT9D112SetCmd(6); /* refresh mode */
	  MT9D112SetCmd(5); /* refresh */
	  
	  MT9D112Sensor.PvMode = KAL_FALSE; /* force config pv mode */
	  MT9D112SetCmd(1); /* goto preview mode */


}                              

/*************************************************************************
* FUNCTION
*    MT9D112PowerOn
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
static kal_uint16 MT9D112PowerOn(void)
{
  kal_uint16 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(MT9D112Sensor.SensorIdx, KAL_TRUE);
  RESET_CMOS_SENSOR_MODE2;
  ENABLE_CAMERA_INDATA_FORMAT;
  SET_CAMERA_INPUT_TYPE(INPUT_YUV422);
  
  CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9D112_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 100);
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate MT9D112 */
  CamPdnPinCtrl(MT9D112Sensor.SensorIdx, 0);
  kal_sleep_task(1); 
  /* Reset the sensor */
  CamRstPinCtrl(MT9D112Sensor.SensorIdx, 1);
  CamRstPinCtrl(MT9D112Sensor.SensorIdx, 0);
  kal_sleep_task(2);
  CamRstPinCtrl(MT9D112Sensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(2);
  
  /* Read Sensor ID  */
  SensorId = CamReadCmosSensor(MT9D112_ID_REG);
  
#ifdef MT9D112_DEBUG
	kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D112 Sensor ID: %x ",SensorId);
#endif
  if (MT9D112_SENSOR_ID != SensorId)
  	{
  	CameraSccbClose(CAMERA_SCCB_SENSOR);
	//kal_sleep_task(2);	
    CameraSccbInit(CAMERA_HW_SCCB, 1, 1, 0xA0);
	CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9D112_SLAVE1_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 100);
	SensorId = CamReadCmosSensor(MT9D112_ID_REG);

	if (MT9D112_SENSOR_ID != SensorId)
  	{
  	
  	#ifdef MT9D112_DEBUG
 		 kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D112 Sensor ID: %x ",SensorId);
	#endif
  	}

  	}
  
#ifdef MT9D112_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D112 Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}


/*************************************************************************
* FUNCTION
*    MT9D112Preview
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
static void MT9D112Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;
  kal_uint16 DummyPixel;
  

#ifdef MT9D112_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "MT9D112 Preview %d ",In->MaxVideoFrameRate);
#endif

  MT9D112Sensor.Banding = In->BandingFreq;
  MT9D112Sensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
  	
    MT9D112Sensor.VideoMode = KAL_TRUE;
    MT9D112Sensor.Fps = In->MaxVideoFrameRate;// * MT9D112_FRAME_RATE_UNIT;
	MT9D112Sensor.NormalFps = MT9D112_FPS(10);
    MT9D112Sensor.NightFps = MT9D112_FPS(5);
	StartX = MT9D112_PV_X_START;
	StartY = MT9D112_PV_Y_START;
	DummyPixel = 0;
    break;
 default:
    MT9D112Sensor.VideoMode = KAL_FALSE;
    //MT9D112Sensor.Fps = MT9D112_MAX_CAMERA_FPS;//MT9D112_FRAME_RATE_UNIT * (30);
    MT9D112Sensor.Fps = In->NightMode ? MT9D112_FPS(15) : MT9D112_FPS(24);
	MT9D112Sensor.NormalFps = MT9D112_FPS(12);
    MT9D112Sensor.NightFps = MT9D112_FPS(5);
	StartX = MT9D112_PV_X_START;
	StartY = MT9D112_PV_Y_START;
	DummyPixel = 0;
	break;
  //case CAL_SCENARIO_WEBCAM_PREVIEW:
  //case CAL_SCENARIO_WEBCAM_CAPTURE:
    //StartX += 40;
    //StartY += 30;
    //MT9D112Sensor.VideoMode = KAL_FALSE;
    //MT9D112Sensor.Fps = MT9D112_FRAME_RATE_UNIT * (MT9D112Sensor.NightMode ? 5 : 10);
    //break;
  //default:
    //break;
  }

  MT9D112SetHVMirror(In->ImageMirror);

  //MT9D112SetFrameCount();
  if (!MT9D112Sensor.PvMode)
  {
    CamWriteCmosSensor(0x3012, MT9D112Sensor.Shutter); /* shutter */
  }
  MT9D112WritePvBlank(DummyPixel, 0);
  MT9D112SetCmd(1); /* seq_cmd: goto preview mode */

    if (CAM_BANDING_50HZ == In->BandingFreq)
	{
	  MT9D112WriteXDMA(0xA404, 0xC0);
	}
	else
	{
	  MT9D112WriteXDMA(0xA404, 0x80);
	}
  MT9D112SetCmd(6);
  MT9D112NightMode(MT9D112Sensor.NightMode);
  
  //MT9D112CalFps();	

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = MT9D112_IMAGE_SENSOR_PV_WIDTH; 
  Out->ExposureWindowHeight = MT9D112_IMAGE_SENSOR_PV_HEIGHT;
  kal_sleep_task(20);

  
}

/*************************************************************************
* FUNCTION
*    MT9D112Capture
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
static void MT9D112Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
kal_uint16 DummyPixel, Shutter;
 
 kal_wap_trace(MOD_ENG,TRACE_INFO, "MT9D112Capture function...");
 if (In->ImageTargetWidth <= MT9D112_IMAGE_SENSOR_PV_WIDTH_DRV && In->ImageTargetHeight <= MT9D112_IMAGE_SENSOR_PV_HEIGHT_DRV)
 {
   if (CAL_SCENARIO_WEBCAM_PREVIEW == Id || CAL_SCENARIO_WEBCAM_CAPTURE == Id) /* webcam mode */
   {
	 DummyPixel = 0;
   }
//#if (!(defined(DRV_ISP_6235_SERIES) || defined(DRV_ISP_6238_SERIES)))
#if (!(defined(DRV_ISP_6276_SERIES) || defined(DRV_ISP_6238_SERIES)))

	else if (In->ZoomFactor >= 10 * 2.8)
	{
	 DummyPixel = 0x300;
	}
#endif
   else
   {
	 DummyPixel = 0;
   }
   MT9D112WriteCapBlank(DummyPixel, 0);
   
   Out->WaitStableFrameNum = 0;
   Out->GrabStartX = MT9D112_PV_X_START;
   Out->GrabStartY = MT9D112_PV_Y_START;
   Out->ExposureWindowWidth = MT9D112_IMAGE_SENSOR_PV_WIDTH;
   Out->ExposureWindowHeight = MT9D112_IMAGE_SENSOR_PV_HEIGHT;
 }
 else
 {
   //const kal_uint32 PvClk = OV2643Sensor.IntClk;
   //const kal_uint16 PvLineLength = OV2643Sensor.LineLength;
   //kal_uint16 MaxCapFps;

#if (!defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
	   if (In->ImageTargetWidth > MT9D112_IMAGE_SENSOR_FULL_WIDTH_DRV &&
		   In->ImageTargetHeight > MT9D112_IMAGE_SENSOR_FULL_HEIGHT_DRV &&
		   In->ZoomFactor >= 10 * 1.2)
	   {
		 DummyPixel = 0x1100;
	   }
	   else if (In->ZoomFactor >= 10 * 1.9)
	   {
		 DummyPixel = 0x980;
	   }
	   else
#endif
	   {
		 DummyPixel = 0;
	   }

   MT9D112Sensor.Shutter = CamReadCmosSensor(0x3012); /* back up shutter */
   MT9D112WriteCapBlank(DummyPixel, 0);
   MT9D112SetCmd(2); /* seq_cmd: goto capture mode */
   Shutter = MT9D112HalfAdjust(MT9D112Sensor.PvLineLength * MT9D112Sensor.Shutter, MT9D112Sensor.CapLineLength);
   if (!Shutter) Shutter = 1; /* avoid shutter 0 */
   CamWriteCmosSensor(0x3012, Shutter);

   
   Out->WaitStableFrameNum = 3;
   Out->GrabStartX = MT9D112_FULL_X_START;
   Out->GrabStartY = MT9D112_FULL_Y_START;
   Out->ExposureWindowWidth = MT9D112_IMAGE_SENSOR_FULL_WIDTH;
   Out->ExposureWindowHeight = MT9D112_IMAGE_SENSOR_FULL_HEIGHT;
 }
}


/*************************************************************************
* FUNCTION
*    MT9D112SensorOpen
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
static MM_ERROR_CODE_ENUM MT9D112SensorOpen(void)
{
  if (MT9D112_SENSOR_ID != MT9D112PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  
//#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT_1))
//	MT9D112Sensor.Pclk = 26000000;
//#else
//	MT9D112Sensor.Pclk = 26000000;
//#endif

#if (defined(DRV_ISP_6235_SERIES) || defined(DRV_ISP_6238_SERIES)|| defined(DRV_ISP_6276_SERIES))
  #if (defined(DRV_ISP_6238_SERIES))
	  /* 13MHz CLKIN, 52 MHz PLL out */
	  MT9D112Sensor.Pclk = 52000000;
  #elif (defined(DRV_ISP_6276_SERIES))
  	  /* 26MHz CLKIN, 62 MHz PLL out */
  	  MT9D112Sensor.Pclk = 48000000;
  #elif (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
	  /* 13MHz CLKIN, 52 MHz PLL out */
	  MT9D112Sensor.Pclk = 52000000;
  #else
	  /* 12MHz CLKIN, 48 MHz PLL out */
	  MT9D112Sensor.Pclk = 48000000;
  #endif
#else
  #if defined(MT9D112_USE_48M)
	  MT9D112Sensor.Pclk = 24000000; /* use 24M MCLK */
  #else
	  MT9D112Sensor.Pclk = 26000000; /* use 26M MCLK */
  #endif
#endif


  MT9D112InitialSetting();
  MT9D112Sensor.VideoMode = KAL_FALSE;
  MT9D112Sensor.NightMode = KAL_FALSE;
  MT9D112Sensor.Banding = CAM_BANDING_60HZ;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  MT9D112Sensor.DummyPixel = 0x1c;
#else
  MT9D112Sensor.DummyPixel = 0x0;
#endif
  MT9D112Sensor.Fps = MT9D112_MAX_CAMERA_FPS;
  MT9D112Sensor.ShutterStep= 0x96;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM MT9D112SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef MT9D112_DEBUG
  //kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D112 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return MT9D112WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = MT9D112Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = MT9D112Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = MT9D112Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = MT9D112Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = MT9D112StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = MT9D112Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = MT9D112SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = MT9D112SceneMode(KAL_FALSE, In, Out);
	break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;


  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    MT9D112GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D112DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D112Sensor.Fps * 10 / MT9D112_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    MT9D112InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    //CamGetHWInfo(Out);
	CamGetHWInfo(MT9D112Sensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(MT9D112Sensor.SensorIdx, 1);   
    CamRstPinCtrl(MT9D112Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    MT9D112Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    MT9D112Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    MT9D112Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    MT9D112AeEnable(MT9D112Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    MT9D112Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    MT9D112AwbEnable(MT9D112Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    MT9D112SensorCtrl
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
static MM_ERROR_CODE_ENUM MT9D112SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    MT9D112Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    MT9D112Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112SensorClose
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
static MM_ERROR_CODE_ENUM MT9D112SensorClose(void)
{

  RESET_CMOS_SENSOR_MODE1;
//#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
//	/* do nothing */
//#elif (defined(DRV_ISP_6235_SERIES) || defined(MT9D112_USE_48M))
//	UPLL_Disable(UPLL_OWNER_ISP);
//#endif

  /* power down sensor */
  CamPdnPinCtrl(MT9D112Sensor.SensorIdx, 1);
  CamRstPinCtrl(MT9D112Sensor.SensorIdx, 0);
  CisModulePowerOn(MT9D112Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D112SensorFunc
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
MM_ERROR_CODE_ENUM MT9D112SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9D112 =
  {
    MT9D112SensorOpen,
    MT9D112SensorFeatureCtrl,
    MT9D112SensorCtrl,
    MT9D112SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncMT9D112;
  
  return MM_ERROR_NONE;
}


