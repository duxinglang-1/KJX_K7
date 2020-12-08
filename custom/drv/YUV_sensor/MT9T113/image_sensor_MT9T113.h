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
 *   image_sensor_MT9T113.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_MT9T113_H
	#define _IMAGE_SENSOR_MT9T113_H

#include "sensor_comm_def.h"


//#define __MT9T113_DEBUG_TRACE__

//#define __MT9T113_TEST_PATTERN__

/* This used for debug phase use only, to speed up the initial setting modify, 
    NOTICE: It need to be marked when MP release version, or else it will effect the enter
    camera time and waste some ram. */
//#define MT9T113_LOAD_FROM_T_FLASH


/* SENSOR MASTER CLOCK */
#define MT9T113_MCLK                          26000000

/* ========================= code modify body start ========================= */

/* SENSOR PREVIEW/CAPTURE INTERNAL CLOCK */
#if (defined(MT6276) || defined(MT6236))
#define MT9T113_PREVIEW_CLK                   28000000
#define MT9T113_CAPTURE_CLK                   38500000
#elif (defined(MT6268) || defined(MT6253))
#define MT9T113_PREVIEW_CLK                   26000000
#define MT9T113_CAPTURE_CLK                   MT9T113_PREVIEW_CLK
#else
#define MT9T113_PREVIEW_CLK                   24000000
#define MT9T113_CAPTURE_CLK                   MT9T113_PREVIEW_CLK
#endif

/* SENSOR PREVIEW SIZE */
#define MT9T113_IMAGE_SENSOR_PV_WIDTH_DRV     (1024)
#define MT9T113_IMAGE_SENSOR_PV_HEIGHT_DRV    (768)
/* SENSOR FULL SIZE */
#define MT9T113_IMAGE_SENSOR_FULL_WIDTH_DRV   2048
#define MT9T113_IMAGE_SENSOR_FULL_HEIGHT_DRV  1536

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define MT9T113_PV_PERIOD_PIXEL_NUMS          3033
#define MT9T113_PV_PERIOD_LINE_NUMS           857

#define MT9T113_FULL_PERIOD_PIXEL_NUMS        4128
#define MT9T113_FULL_PERIOD_LINE_NUMS         1629


/* SENSOR LIMITATION */
//#define MT9T113_SHUTTER_MAX_MARGIN            5
#define MT9T113_MAX_LINELENGTH                0xFFFF /* register limitation */
#define MT9T113_MAX_FRAMEHEIGHT               0xFFFF /* register limitation */

/* SENSOR DELAY FRAME */
#define MT9T113_FIRST_PREVIEW_DELAY_FRAME     4
#define MT9T113_PREVIEW_DELAY_FRAME           2
#define MT9T113_CAPTURE_DELAY_FRAME           2

/* SENSOR WRITE ID */
#define MT9T113_WRITE_ID_0                    0x78
#define MT9T113_WRITE_ID_1                    0x7A
#define MT9T113_WRITE_ID_2                    0xFF
#define MT9T113_WRITE_ID_3                    0xFF

/* SENSOR I2C ADDR/DATA WIDTH */
#define MT9T113_I2C_ADDR_BITS                 CAMERA_SCCB_16BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */
#define MT9T113_I2C_DATA_BITS                 CAMERA_SCCB_16BIT /* CAMERA_SCCB_8BIT / CAMERA_SCCB_16BIT */

/* ========================= code modify body end ========================= */

/* SENSOR START/END POSITION */
#define MT9T113_PV_X_START                    0
#define MT9T113_PV_Y_START                    1
#define MT9T113_FULL_X_START                  0
#define MT9T113_FULL_Y_START                  1
#define MT9T113_IMAGE_SENSOR_PV_WIDTH         (MT9T113_IMAGE_SENSOR_PV_WIDTH_DRV - MT9T113_PV_X_START)
#define MT9T113_IMAGE_SENSOR_PV_HEIGHT        (MT9T113_IMAGE_SENSOR_PV_HEIGHT_DRV - 2) /* -2 for frame ready done */
#define MT9T113_IMAGE_SENSOR_FULL_WIDTH       (MT9T113_IMAGE_SENSOR_FULL_WIDTH_DRV - MT9T113_FULL_X_START)
#define MT9T113_IMAGE_SENSOR_FULL_HEIGHT      (MT9T113_IMAGE_SENSOR_FULL_HEIGHT_DRV - 2)

/* HW I2C SPEED */
#define MT9T113_HW_I2C_SPEED                   400 /* Kbps */

/* 50HZ/60HZ */
#define MT9T113_NUM_50HZ                      100
#define MT9T113_NUM_60HZ                      120

/* FRAME RATE UNIT */
#define MT9T113_FPS(x)                        ((kal_uint32)(10 * (x)))

/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM MT9T113SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM MT9T113WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif

