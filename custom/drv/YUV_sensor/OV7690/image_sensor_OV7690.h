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
 *   image_sensor_OV7690.h
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
#ifndef _IMAGE_SENSOR_OV7690_H
#define _IMAGE_SENSOR_OV7690_H

#include "sensor_comm_def.h"

/* SENSOR PREVIEW/CAPTURE ISP CLOCK */
#define OV7690_PREVIEW_CLK                   13000000
#define OV7690_VIDEO_LOW_CLK                 6500000
#define OV7690_CAPTURE_CLK                   13000000

/* SENSOR SIZE */
#define OV7690_IMAGE_SENSOR_WIDTH_DRV        640
#define OV7690_IMAGE_SENSOR_HEIGHT_DRV       480

/* SENSOR HORIZONTAL/VERTICAL ACTIVE REGION */
#define OV7690_IMAGE_SENSOR_HSTART           105
#define OV7690_IMAGE_SENSOR_VSTART           12
#define OV7690_IMAGE_SENSOR_HACTIVE          OV7690_IMAGE_SENSOR_WIDTH_DRV
#define OV7690_IMAGE_SENSOR_VACTIVE          OV7690_IMAGE_SENSOR_HEIGHT_DRV

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#define OV7690_IMAGE_SENSOR_HBLANKING        206
#define OV7690_IMAGE_SENSOR_VBLANKING        32

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV7690_PERIOD_PIXEL_NUMS             (OV7690_IMAGE_SENSOR_HACTIVE + OV7690_IMAGE_SENSOR_HBLANKING) /* 846 */
#define OV7690_PERIOD_LINE_NUMS              (OV7690_IMAGE_SENSOR_VACTIVE + OV7690_IMAGE_SENSOR_VBLANKING) /* 512 */

/* SENSOR START/END POSITION */
#define OV7690_X_START                       0
#define OV7690_Y_START                       1
#define OV7690_IMAGE_SENSOR_WIDTH            OV7690_IMAGE_SENSOR_WIDTH_DRV
#define OV7690_IMAGE_SENSOR_HEIGHT           (OV7690_IMAGE_SENSOR_HEIGHT_DRV - 2) /* -2 for frame ready done */

/* 50HZ/60HZ */
#define OV7690_NUM_50HZ                      50
#define OV7690_NUM_60HZ                      60

/* SENSOR LIMITATION */
#define OV7690_SHUTTER_MAX_MARGIN            10
#define OV7690_MAX_LINELENGTH                0x7FF
#define OV7690_MAX_FRAMEHEIGHT               0xFFF

/* SENSOR READ/WRITE ID */
#define OV7690_WRITE_ID                      0x42
#define OV7690_READ_ID                       0x43

/* FRAME RATE UNIT */
#define OV7690_FPS(x)                        ((kal_uint32)(10 * (x)))

/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM OV7690SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM OV7690WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif

