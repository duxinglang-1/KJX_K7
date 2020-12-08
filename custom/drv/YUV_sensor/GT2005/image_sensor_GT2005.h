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
 *   image_sensor_GT2005.h
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
#ifndef _IMAGE_SENSOR_GT2005_H
#define _IMAGE_SENSOR_GT2005_H

#include "sensor_comm_def.h"

/* if defined, means use internal DVDD, and DOVDD should be 1.8V */
#define GT2005_INTERNAL_DVDD

/* if defined, means reduce gain and increase exposure to reduce noise when capture */
//#define GT2005_GAIN2SHUTTER

/* SENSOR PREVIEW/CAPTURE ISP CLOCK */
#define GT2005_PREVIEW_CLK                   39000000
#define GT2005_VIDEO_LOW_CLK                 19500000
#if (defined(MT6276) || defined(MT6236))
#define GT2005_CAPTURE_CLK                   39000001
#else
#define GT2005_CAPTURE_CLK                   23970000
#endif

/* SENSOR FULL/PV SIZE */
#define GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV   1600
#define GT2005_IMAGE_SENSOR_FULL_HEIGHT_DRV  1200
#define GT2005_IMAGE_SENSOR_PV_WIDTH_DRV     (GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV / 2)
#define GT2005_IMAGE_SENSOR_PV_HEIGHT_DRV    (GT2005_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2)

/* SENSOR ISP INPUT HORIZONTAL/VERTICAL ACTIVE REGION & OFFSET */
#define GT2005_IMAGE_SENSOR_FULL_HSTART      285
#define GT2005_IMAGE_SENSOR_FULL_VSTART      10 /* must be even */
#define GT2005_IMAGE_SENSOR_FULL_HACTIVE     2072
#define GT2005_IMAGE_SENSOR_FULL_VACTIVE     1548
#define GT2005_IMAGE_SENSOR_PV_HSTART        GT2005_IMAGE_SENSOR_FULL_HSTART
#define GT2005_IMAGE_SENSOR_PV_VSTART        6 /* must be even */
#define GT2005_IMAGE_SENSOR_PV_HACTIVE       GT2005_IMAGE_SENSOR_FULL_HACTIVE
#define GT2005_IMAGE_SENSOR_PV_VACTIVE       772

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#define GT2005_IMAGE_SENSOR_FULL_HBLANKING   320
#define GT2005_IMAGE_SENSOR_FULL_VBLANKING   144
#define GT2005_IMAGE_SENSOR_PV_HBLANKING     320 
#define GT2005_IMAGE_SENSOR_PV_VBLANKING     72

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define GT2005_FULL_PERIOD_PIXEL_NUMS        (GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV + GT2005_IMAGE_SENSOR_FULL_HBLANKING) /* 1920, must be 8x */
#define GT2005_FULL_PERIOD_LINE_NUMS         (GT2005_IMAGE_SENSOR_FULL_HEIGHT_DRV + GT2005_IMAGE_SENSOR_FULL_VBLANKING) /* 1344, must be 48x */
#define GT2005_PV_PERIOD_PIXEL_NUMS          (GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV + GT2005_IMAGE_SENSOR_PV_HBLANKING) /* 1920, must be 8x */
#define GT2005_PV_PERIOD_LINE_NUMS           (GT2005_IMAGE_SENSOR_PV_HEIGHT_DRV + GT2005_IMAGE_SENSOR_PV_VBLANKING) /* 672, must be 24x */

/* SENSOR START/END POSITION */
#define GT2005_FULL_X_START                  0
#define GT2005_FULL_Y_START                  1
#define GT2005_PV_X_START                    0
#define GT2005_PV_Y_START                    1
#define GT2005_IMAGE_SENSOR_PV_WIDTH         (GT2005_IMAGE_SENSOR_PV_WIDTH_DRV - GT2005_PV_X_START)
#define GT2005_IMAGE_SENSOR_PV_HEIGHT        (GT2005_IMAGE_SENSOR_PV_HEIGHT_DRV - 2) /* -2 for frame ready done */
#define GT2005_IMAGE_SENSOR_FULL_WIDTH       (GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV - GT2005_FULL_X_START)
#define GT2005_IMAGE_SENSOR_FULL_HEIGHT      (GT2005_IMAGE_SENSOR_FULL_HEIGHT_DRV - 6)

/* SENSOR LIMITATION */
#define GT2005_SHUTTER_MAX_MARGIN            5
#define GT2005_MAX_LINELENGTH                (0x1FF * 8) /* register limitation */
#define GT2005_MAX_FRAMEHEIGHT               (0x7FF * 48) /* register limitation */

/* SENSOR READ/WRITE ID */
#define GT2005_WRITE_ID                      0x78
#define GT2005_READ_ID                       0x79

/* FRAME RATE UNIT */
#define GT2005_FPS(x)                        ((kal_uint32)(10 * (x)))

/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM GT2005SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM GT2005WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif
