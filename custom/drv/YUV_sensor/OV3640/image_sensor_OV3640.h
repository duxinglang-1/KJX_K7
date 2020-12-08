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
 *   image_sensor_OV3640.h
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
#ifndef _IMAGE_SENSOR_OV3640_H
#define _IMAGE_SENSOR_OV3640_H

#include "sensor_comm_def.h"

/* if defined, means use internal DVDD, and DOVDD should be 1.8V */
#define OV3640_INTERNAL_DVDD

/* if defined, means reduce gain and increase exposure to reduce noise when capture */
#define OV3640_GAIN2SHUTTER

/* if defined, means 1/4 full size preview */
#if (defined(LUFFY76V2_1G512_BB) && (defined(__FLAVOR_CU20_COSMOS_WVGA_11B__) || defined(__FLAVOR_CU20_COSMOS_WVGA__)))
#define OV3640_QUARTER_PREVIEW
#endif

/* SENSOR PREVIEW/CAPTURE ISP CLOCK */
#define OV3640_PREVIEW_CLK                   56333333
#define OV3640_VIDEO_LOW_CLK                 34666667
#if (defined(DRV_ISP_6276_SERIES) || defined(DRV_ISP_MT6236_HW_SUPPORT))
#define OV3640_CAPTURE_CLK                   45500000
#else
#define OV3640_CAPTURE_CLK                   23833333
#endif

/* SENSOR FULL/PV SIZE */
#define OV3640_IMAGE_SENSOR_FULL_WIDTH_DRV   2048
#define OV3640_IMAGE_SENSOR_FULL_HEIGHT_DRV  1536
#ifdef OV3640_QUARTER_PREVIEW
#define OV3640_IMAGE_SENSOR_PV_WIDTH_DRV     (OV3640_IMAGE_SENSOR_FULL_WIDTH_DRV / 2) /* 1024 */
#define OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV    (OV3640_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2) /* 768 */
#else
#define OV3640_IMAGE_SENSOR_PV_WIDTH_DRV     640
#define OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV    480
#endif

/* SENSOR ISP INPUT HORIZONTAL/VERTICAL ACTIVE REGION & OFFSET */
#define OV3640_IMAGE_SENSOR_FULL_HSTART      285
#define OV3640_IMAGE_SENSOR_FULL_VSTART      10 /* must be even */
#define OV3640_IMAGE_SENSOR_FULL_HACTIVE     2072
#define OV3640_IMAGE_SENSOR_FULL_VACTIVE     1548
#define OV3640_IMAGE_SENSOR_PV_HSTART        OV3640_IMAGE_SENSOR_FULL_HSTART
#define OV3640_IMAGE_SENSOR_PV_VSTART        6 /* must be even */
#define OV3640_IMAGE_SENSOR_PV_HACTIVE       OV3640_IMAGE_SENSOR_FULL_HACTIVE
#define OV3640_IMAGE_SENSOR_PV_VACTIVE       772

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#define OV3640_IMAGE_SENSOR_FULL_HBLANKING   304
#define OV3640_IMAGE_SENSOR_FULL_VBLANKING   20
#define OV3640_IMAGE_SENSOR_PV_HBLANKING     304
#define OV3640_IMAGE_SENSOR_PV_VBLANKING     20

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV3640_FULL_PERIOD_PIXEL_NUMS        (OV3640_IMAGE_SENSOR_FULL_HACTIVE + OV3640_IMAGE_SENSOR_FULL_HBLANKING) /* 2376, must be even */
#define OV3640_FULL_PERIOD_LINE_NUMS         (OV3640_IMAGE_SENSOR_FULL_VACTIVE + OV3640_IMAGE_SENSOR_FULL_VBLANKING) /* 1568 */
#define OV3640_PV_PERIOD_PIXEL_NUMS          (OV3640_IMAGE_SENSOR_PV_HACTIVE + OV3640_IMAGE_SENSOR_PV_HBLANKING) /* 2376, must be even */
#define OV3640_PV_PERIOD_LINE_NUMS           (OV3640_IMAGE_SENSOR_PV_VACTIVE + OV3640_IMAGE_SENSOR_PV_VBLANKING) /* 792 */

/* SENSOR START/END POSITION */
#define OV3640_FULL_X_START                  300 /* avoid left rectangle image color abnormal */
#define OV3640_FULL_Y_START                  1
#define OV3640_PV_X_START                    ((OV3640_FULL_X_START * OV3640_IMAGE_SENSOR_PV_WIDTH_DRV / OV3640_IMAGE_SENSOR_FULL_WIDTH_DRV)&0xFFFC)
#define OV3640_PV_Y_START                    1
#define OV3640_IMAGE_SENSOR_PV_WIDTH         (OV3640_IMAGE_SENSOR_PV_WIDTH_DRV - OV3640_PV_X_START)
#define OV3640_IMAGE_SENSOR_PV_HEIGHT        (OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV - 2) /* -2 for frame ready done */
#define OV3640_IMAGE_SENSOR_FULL_WIDTH       (OV3640_IMAGE_SENSOR_FULL_WIDTH_DRV - OV3640_FULL_X_START)
#define OV3640_IMAGE_SENSOR_FULL_HEIGHT      (OV3640_IMAGE_SENSOR_FULL_HEIGHT_DRV - 6)

/* 50HZ/60HZ */
#define OV3640_NUM_50HZ                      50
#define OV3640_NUM_60HZ                      60

/* SENSOR LIMITATION */
#define OV3640_SHUTTER_MAX_MARGIN            5
#define OV3640_MAX_LINELENGTH                0x1000 /* register limitation */

/* SENSOR READ/WRITE ID */
#define OV3640_WRITE_ID                      0x78
#define OV3640_READ_ID                       0x79

/* FRAME RATE UNIT */
#define OV3640_FPS(x)                        ((kal_uint32)(10 * (x)))

/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM OV3640SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM OV3640WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif
