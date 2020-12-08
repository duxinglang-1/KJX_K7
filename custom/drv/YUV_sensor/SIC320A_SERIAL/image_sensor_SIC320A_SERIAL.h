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
 *   image_sensor_SIC320A_SERIAL.h
 *
 * Project:
 * --------
 *   MAUI_sw
 *
 * Description:
 * ------------
 *   CMOS sensor header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_SIC320A_SERIAL_H
	#define _IMAGE_SENSOR_SIC320A_SERIAL_H

#include "sensor_comm_def.h"

/* This used for debug phase use only, to speed up the initial setting modify, 
    NOTICE: It need to be marked when MP release version, or else it will effect the enter
    camera time and waste some ram. */
//#define SIC320A_SERIAL_LOAD_FROM_T_FLASH

/* DEBUG USE ONLY */
//#define __SIC320A_SERIAL_DEBUG_TRACE__

/* SENSOR MASTER CLOCK, SIC320A have no PLL, so need 48Mhz for high frame rate. */
#define SIC320A_SERIAL_MCLK                         48000000

/* Pclk limitation is 96MHz, preview pclk = min(pclk@30fps,96MHz), capture pclk = min(pclk@15fps,96MHz) */
#define SIC320A_SERIAL_PV_INTERNAL_CLK             	48000000
#define SIC320A_SERIAL_CAP_INTERNAL_CLK            	48000000

/* SENSOR PREVIEW SIZE (3M: 1024x768 or 640x480, 2M: 800x600, 1.3M: 640x512, VGA: 640x480, CIF: 352x288) */
#define SIC320A_SERIAL_IMAGE_SENSOR_PV_WIDTH         (352)
#define SIC320A_SERIAL_IMAGE_SENSOR_PV_HEIGHT        (288)
/* SENSOR CAPTURE SIZE (3M: 2048x1536, 2M: 1600x1200, 1.3M: 1280x1024, VGA: 640x480, CIF: 352x288) */
#define SIC320A_SERIAL_IMAGE_SENSOR_FULL_WIDTH       (352)
#define SIC320A_SERIAL_IMAGE_SENSOR_FULL_HEIGHT      (288)

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS          (358 + 65 + 2) /* Active + HST + HFT */
#define SIC320A_SERIAL_PV_PERIOD_LINE_NUMS           (294 + 9)		/* Active + 9 */
#define SIC320A_SERIAL_FULL_PERIOD_PIXEL_NUMS        (358 + 65 + 2) /* Active + HST + HFT */
#define SIC320A_SERIAL_FULL_PERIOD_LINE_NUMS         (294 + 9)		/* Active + 9 */

/* SENSOR SHUTTER MARGIN */
#define SIC320A_SERIAL_SHUTTER_MAX_MARGIN            (5)

/* SENSOR LINELENGTH&FRAMELENGTH LIMITATION */
#define SIC320A_SERIAL_MAX_LINELENGTH                (0xFFFF) /* register limitation */
#define SIC320A_SERIAL_MAX_FRAMELENGTH               (0xFFFF) /* register limitation */

/* SENSOR DELAY FRAME */
#define SIC320A_SERIAL_FIRST_PREVIEW_DELAY_FRAME     (7)
#define SIC320A_SERIAL_PREVIEW_DELAY_FRAME           (3)
#define SIC320A_SERIAL_CAPTURE_DELAY_FRAME           (1)

/* SENSOR I2C WRITE ID */
#define SIC320A_SERIAL_WRITE_ID_0                    (0x62)
#define SIC320A_SERIAL_WRITE_ID_1                    (0xFF)
#define SIC320A_SERIAL_WRITE_ID_2                    (0xFF)
#define SIC320A_SERIAL_WRITE_ID_3                    (0xFF)

/* SENSOR I2C ADDR/DATA WIDTH */
#define SIC320A_SERIAL_I2C_ADDR_BITS                 CAMERA_SCCB_8BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */
#define SIC320A_SERIAL_I2C_DATA_BITS                 CAMERA_SCCB_8BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */

/* FRAME RATE UNIT */
#define SIC320A_SERIAL_FRAME_RATE_UNIT               10

/* MAX CAMERA FRAME RATE */
#define SIC320A_SERIAL_MAX_CAMERA_FPS         (SIC320A_SERIAL_FRAME_RATE_UNIT * 20)


/* ===============================================================================
   ========================= No Changing The Macro Below =========================
   ===============================================================================
*/

#ifdef __SIC320A_SERIAL_DEBUG_TRACE__
#include "kal_trace.h"

#define SIC320A_SERIAL_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[SIC320A_SERIAL]"__VA_ARGS__)
#else
#define SIC320A_SERIAL_TRACE(...)
#endif


/* CONFIG THE ISP GRAB START X & START Y, CONFIG THE ISP GRAB WIDTH & HEIGHT */
#define SIC320A_SERIAL_PV_GRAB_START_X               (0)
#define SIC320A_SERIAL_PV_GRAB_START_Y               (1)
#define SIC320A_SERIAL_FULL_GRAB_START_X             (0)
#define SIC320A_SERIAL_FULL_GRAB_START_Y             (1)
#define SIC320A_SERIAL_PV_GRAB_WIDTH                 (SIC320A_SERIAL_IMAGE_SENSOR_PV_WIDTH - 2)
#define SIC320A_SERIAL_PV_GRAB_HEIGHT                (SIC320A_SERIAL_IMAGE_SENSOR_PV_HEIGHT - 2)
#define SIC320A_SERIAL_FULL_GRAB_WIDTH               (SIC320A_SERIAL_IMAGE_SENSOR_FULL_WIDTH - 2)
#define SIC320A_SERIAL_FULL_GRAB_HEIGHT              (SIC320A_SERIAL_IMAGE_SENSOR_FULL_HEIGHT - 2)

#define SIC320A_SERIAL_SET_RST_LOW                   CamRstPinCtrl(SIC320A_SERIALSensor.SensorIdx, 0)
#define SIC320A_SERIAL_SET_RST_HIGH                  CamRstPinCtrl(SIC320A_SERIALSensor.SensorIdx, 1)
#define SIC320A_SERIAL_SET_PDN_LOW                   CamPdnPinCtrl(SIC320A_SERIALSensor.SensorIdx, 0)
#define SIC320A_SERIAL_SET_PDN_HIGH                  CamPdnPinCtrl(SIC320A_SERIALSensor.SensorIdx, 1)

/* HW I2C SPEED */
#define SIC320A_SERIAL_HW_I2C_SPEED                  300 /* Kbps */

/* FRAME RATE UNIT */
#define SIC320A_SERIAL_FPS(x)                        ((kal_uint32)(10 * (x)))

/* CHECK AND SET LOCK */
#define SIC320A_SERIAL_CHECK_AND_SET(x, y, z)        do { \
    if (SIC320A_SERIALSensor.##x == (y)) \
    { \
      return z; \
    } \
    SIC320A_SERIALSensor.##x = (y); \
  } while(0)

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM SIC320A_SERIALSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM SIC320A_SERIALWebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif

