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
 *   image_sensor_GC0308.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_GC0308_H
#define _IMAGE_SENSOR_GC0308_H

#include "sensor_comm_def.h"

/* SENSOR PREVIEW/CAPTURE VT CLOCK */
#define GC0308_MCLK                          26000000
#define GC0308_PREVIEW_CLK                   (GC0308_MCLK / 2)
#define GC0308_VIDEO_LOW_CLK                 (GC0308_MCLK / 2)
#define GC0308_CAPTURE_CLK                   (GC0308_MCLK / 2)

/* SENSOR SIZE */
#define GC0308_IMAGE_SENSOR_WIDTH_DRV        640
#define GC0308_IMAGE_SENSOR_HEIGHT_DRV       480

/* SENSOR HORIZONTAL/VERTICAL ACTIVE REGION */
#define GC0308_IMAGE_SENSOR_HACTIVE          (GC0308_IMAGE_SENSOR_WIDTH_DRV + 8)
#define GC0308_IMAGE_SENSOR_VACTIVE          (GC0308_IMAGE_SENSOR_HEIGHT_DRV + 8)

/* SENSOR HORIZONTAL/VERTICAL BLANKING IN ONE PERIOD */
#define GC0308_IMAGE_SENSOR_HBLANKING        194 /* if < 192, will cause left black block in image when high  */
/* GC0308_IMAGE_SENSOR_VBLANKING should be = Bt + St + Et > St + Et + 6, St = Reg[0x0D], Et = Reg[0x0E] */
#define GC0308_IMAGE_SENSOR_VBLANKING        11

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
/* ACTIVE + HBLANKING + SH_DELAY(reg0x12) + 4 */
#define GC0308_PERIOD_PIXEL_NUMS             (GC0308_IMAGE_SENSOR_HACTIVE + GC0308_IMAGE_SENSOR_HBLANKING + 42 + 4) /* 888 */
#define GC0308_PERIOD_LINE_NUMS              (GC0308_IMAGE_SENSOR_VACTIVE + GC0308_IMAGE_SENSOR_VBLANKING) /* 499 */

/* SENSOR START/END POSITION */
#define GC0308_X_START                       0
#define GC0308_Y_START                       1
#define GC0308_IMAGE_SENSOR_WIDTH            GC0308_IMAGE_SENSOR_WIDTH_DRV
#define GC0308_IMAGE_SENSOR_HEIGHT           (GC0308_IMAGE_SENSOR_HEIGHT_DRV - 2) /* -2 for frame ready done */

/* 50HZ/60HZ */
#define GC0308_NUM_50HZ                      50
#define GC0308_NUM_60HZ                      60

/* SENSOR LIMITATION */
#define GC0308_SHUTTER_MAX_MARGIN            0
#define GC0308_MAX_LINELENGTH                (GC0308_IMAGE_SENSOR_HACTIVE + 0xFFF + 42 + 4)
#define GC0308_MAX_FRAMEHEIGHT               (GC0308_IMAGE_SENSOR_VACTIVE + 0xFFF)

/* SENSOR READ/WRITE ID */
#define GC0308_WRITE_ID                      0x42
#define GC0308_READ_ID                       0x43

/* FRAME RATE UNIT */
#define GC0308_FPS(x)                        ((kal_uint32)(10 * (x)))

/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM GC0308SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM GC0308WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#endif

