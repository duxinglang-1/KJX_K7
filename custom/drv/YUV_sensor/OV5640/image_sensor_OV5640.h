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
 *   image_sensor_OV5640.h
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV5640_H
#define _IMAGE_SENSOR_OV5640_H

#include "sensor_comm_def.h"

/* This used for debug phase use only, to speed up the initial setting modify, 
    NOTICE: It need to be marked when MP release version, or else it will effect the enter
    camera time and waste some ram. */
//#define OV5640_LOAD_FROM_T_FLASH

/* DEBUG USE ONLY */
//#define __OV5640_DEBUG_TRACE__

#ifdef __OV5640_DEBUG_TRACE__
#include "kal_trace.h"

#define OV5640_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[OV5640]"__VA_ARGS__)
#else
#define OV5640_TRACE(...)
#endif

/* SENSOR MASTER CLOCK */
#ifdef DRV_ISP_MT6236_HW_SUPPORT
#define OV5640_MCLK                          24000000
#else
#define OV5640_MCLK                          26000000
#endif

// TODO: modify sensor dependent macro value here
#if (defined(__JPEG_SENSOR_SUPPORT__) && defined(DRV_ISP_6276_SERIES))
#define OV5640_DYNAMIC_SIZE /* support jpeg dynamic size output (fixed width, dynamic height) */
#endif

/* SENSOR I2C WRITE ID */
#define OV5640_WRITE_ID_0                    (0x78)
#define OV5640_WRITE_ID_1                    (0xFF)
#define OV5640_WRITE_ID_2                    (0xFF)
#define OV5640_WRITE_ID_3                    (0xFF)

/* SENSOR I2C ADDR/DATA WIDTH */
#define OV5640_I2C_ADDR_BITS                 CAMERA_SCCB_16BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */
#define OV5640_I2C_DATA_BITS                 CAMERA_SCCB_8BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */

/* SENSOR PREVIEW SIZE (5M:1296x972 or 640x480, 3M: 1024x768 or 640x480, 2M: 800x600, 1.3M: 640x512, VGA: 640x480, CIF: 352x288) */
#define OV5640_IMAGE_SENSOR_PV_WIDTH         (640)
#define OV5640_IMAGE_SENSOR_PV_HEIGHT        (480)
/* SENSOR CAPTURE SIZE (5M: 2592x1944, 3M: 2048x1536, 2M: 1600x1200, 1.3M: 1280x1024, VGA: 640x480, CIF: 352x288) */
#define OV5640_IMAGE_SENSOR_FULL_WIDTH       (2592)
#define OV5640_IMAGE_SENSOR_FULL_HEIGHT      (1944)

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV5640_PV_PERIOD_PIXEL_NUMS          (1624 + 50) /* +50 for some image yellow in preview */
#define OV5640_PV_PERIOD_LINE_NUMS           (984)
#define OV5640_FULL_PERIOD_PIXEL_NUMS        (2844)
#define OV5640_FULL_PERIOD_LINE_NUMS         (1968)

/* SENSOR LINELENGTH&FRAMELENGTH LIMITATION */
#define OV5640_MAX_PV_LINELENGTH             (0xFFF) /* register limitation */
#define OV5640_MAX_PV_FRAMELENGTH            (0xFFF) /* register limitation */
#define OV5640_MAX_CAP_LINELENGTH            (OV5640_MAX_PV_LINELENGTH) /* register limitation */
#define OV5640_MAX_CAP_FRAMELENGTH           (OV5640_MAX_PV_FRAMELENGTH) /* register limitation */

/* SENSOR JPEG OUTPUT SIZE */
#define OV5640_SPOOF_WIDTH                   2048
#define OV5640_SPOOF_HEIGHT                  1536

/* SENSOR SHUTTER MARGIN */
#define OV5640_SHUTTER_MARGIN                (4)

/* SENSOR DELAY FRAME */
#define OV5640_FIRST_PREVIEW_DELAY_FRAME     (5)
#define OV5640_PREVIEW_DELAY_FRAME           (3)
#define OV5640_CAPTURE_DELAY_FRAME           (3)

/* SENSOR PREVIEW/CAPTURE INTERNAL CLOCK */
#if OV5640_MCLK == 24000000
    #if (defined(DRV_ISP_6276_SERIES) || defined(DRV_ISP_MT6236_HW_SUPPORT))
    /* pclk limitation is 96MHz, preview pclk = min(pclk@30fps,96MHz), capture pclk = min(pclk@15fps,96MHz) */
    #define OV5640_PV_INTERNAL_CLK           49500000
    #define OV5640_CAP_INTERNAL_CLK          48000001
    #define OV5640_CAP_INTERNAL_CLK_2X       26000000
    #define OV5640_CAP_INTERNAL_CLK_4X       20750000
    #define OV5640_CAP_INTERNAL_CLK_8X       10375000
    #elif (defined(DRV_ISP_MT6268_HW_SUPPORT))
    /* pclk limitation is 52MHz, preview pclk = min(pclk@30fps,52MHz), capture pclk = min(pclk@15fps,52MHz) */
    #define OV5640_PV_INTERNAL_CLK           49500000
    #define OV5640_CAP_INTERNAL_CLK          26000000
    #else
    /* pclk limitation is 48MHz, preview pclk = min(pclk@30fps,48MHz), capture pclk = min(pclk@15fps,48MHz) */
    #define OV5640_PV_INTERNAL_CLK           48000000
    #define OV5640_CAP_INTERNAL_CLK          24000000
    #endif
    #ifdef __JPEG_SENSOR_SUPPORT__ /* redefine capture clock for jpeg capture */
    #undef OV5640_CAP_INTERNAL_CLK
    #define OV5640_CAP_INTERNAL_CLK          84000000
    #endif
#else
    #if (defined(DRV_ISP_6276_SERIES) || defined(DRV_ISP_MT6236_HW_SUPPORT))
    /* pclk limitation is 96MHz, preview pclk = min(pclk@30fps,96MHz), capture pclk = min(pclk@15fps,96MHz) */
    #define OV5640_PV_INTERNAL_CLK           49688889
    #define OV5640_CAP_INTERNAL_CLK          47960001
    #define OV5640_CAP_INTERNAL_CLK_2X       26000000
    #define OV5640_CAP_INTERNAL_CLK_4X       20800000
    #define OV5640_CAP_INTERNAL_CLK_8X       10400000
    #elif (defined(DRV_ISP_MT6268_HW_SUPPORT))
    /* pclk limitation is 52MHz, preview pclk = min(pclk@30fps,52MHz), capture pclk = min(pclk@15fps,52MHz) */
    #define OV5640_PV_INTERNAL_CLK           49688889
    #define OV5640_CAP_INTERNAL_CLK          26000000
    #else
    /* pclk limitation is 48MHz, preview pclk = min(pclk@30fps,48MHz), capture pclk = min(pclk@15fps,48MHz) */
    #define OV5640_PV_INTERNAL_CLK           47960000
    #define OV5640_CAP_INTERNAL_CLK          23980000
    #endif
    #ifdef __JPEG_SENSOR_SUPPORT__ /* redefine capture clock for jpeg capture */
    #undef OV5640_CAP_INTERNAL_CLK
    #define OV5640_CAP_INTERNAL_CLK          84070000
    #endif
#endif

/* ===============================================================================
   ========================= No Changing The Macro Below =========================
   ===============================================================================
*/

/* CONFIG THE ISP GRAB START X & START Y, CONFIG THE ISP GRAB WIDTH & HEIGHT */
#define OV5640_PV_GRAB_START_X               (0)
#define OV5640_PV_GRAB_START_Y               (1)
#define OV5640_FULL_GRAB_START_X             (0)
#define OV5640_FULL_GRAB_START_Y             (1)
#define OV5640_PV_GRAB_WIDTH                 (OV5640_IMAGE_SENSOR_PV_WIDTH - OV5640_PV_GRAB_START_X)
#define OV5640_PV_GRAB_HEIGHT                (OV5640_IMAGE_SENSOR_PV_HEIGHT - 2)
#define OV5640_FULL_GRAB_WIDTH               (OV5640_IMAGE_SENSOR_FULL_WIDTH - OV5640_FULL_GRAB_START_X)
#define OV5640_FULL_GRAB_HEIGHT              (OV5640_IMAGE_SENSOR_FULL_HEIGHT - 2)

/* FLICKER OF FREQUENCY */
#define OV5640_50HZ                          100
#define OV5640_60HZ                          120

/* RESET/POWER DOWN PIN CONTROL */
#define OV5640_SET_RST_LOW                   CamRstPinCtrl(OV5640Sensor.SensorIdx, 0)
#define OV5640_SET_RST_HIGH                  CamRstPinCtrl(OV5640Sensor.SensorIdx, 1)
#define OV5640_SET_PDN_LOW                   CamPdnPinCtrl(OV5640Sensor.SensorIdx, 0)
#define OV5640_SET_PDN_HIGH                  CamPdnPinCtrl(OV5640Sensor.SensorIdx, 1)

/* HW I2C SPEED */
#define OV5640_HW_I2C_SPEED                  400 /* Kbps */

/* FRAME RATE UNIT */
#define OV5640_FPS(x)                        ((kal_uint32)(10 * (x)))

/* --------------------------------- common eara --------------------------------- */

/* EXPORT FUNC */
MM_ERROR_CODE_ENUM OV5640SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM OV5640WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif

