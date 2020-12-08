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
 *   image_sensor_SIV100B.h
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

#ifndef _IMAGE_SENSOR_SIV100B_H
#define _IMAGE_SENSOR_SIV100B_H

#include "sensor_comm_def.h"

typedef enum _SID130B_OP_TYPE_ {
        SID130B_MODE_NONE,
        SID130B_MODE_PREVIEW,
        SID130B_MODE_CAPTURE,
        SID130B_MODE_QCIF_VIDEO,
        SID130B_MODE_CIF_VIDEO,
        SID130B_MODE_QVGA_VIDEO
    } SID130B_OP_TYPE;

extern SID130B_OP_TYPE SID130B_g_iSID130B_Mode;

/* START GRAB PIXEL OFFSET */
#define IMAGE_SENSOR_START_GRAB_X		        2	// 0 or 1 recommended
#define IMAGE_SENSOR_START_GRAB_Y		        2	// 0 or 1 recommended

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define MAX_FRAME_RATE							15		// Limitation for MPEG4 Encode Only
#define MIN_FRAME_RATE							12

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
    #define SID130B_FULL_PERIOD_PIXEL_NUMS  (2376)  // default pixel#(w/o dummy pixels) in UXGA mode
    #define SID130B_FULL_PERIOD_LINE_NUMS   (1568)  // default line#(w/o dummy lines) in UXGA mode
    #define SID130B_PV_PERIOD_PIXEL_NUMS    (SID130B_FULL_PERIOD_PIXEL_NUMS / 2)  // default pixel#(w/o dummy pixels) in SVGA mode
    #define SID130B_PV_PERIOD_LINE_NUMS     (784)   // default line#(w/o dummy lines) in SVGA mode

    /* SENSOR EXPOSURE LINE LIMITATION */
    #define SID130B_FULL_MAX_LINES_PER_FRAME    (1568)  // QXGA mode    
    #define SID130B_FULL_EXPOSURE_LIMITATION    (SID130B_FULL_MAX_LINES_PER_FRAME)
    #define SID130B_PV_MAX_LINES_PER_FRAME      (784)  // # of lines in one XGA frame    
    #define SID130B_PV_EXPOSURE_LIMITATION      (SID130B_PV_MAX_LINES_PER_FRAME)

/* SENSOR FULL SIZE */
   #define SID130B_IMAGE_SENSOR_FULL_WIDTH	   (1600)  
   #define SID130B_IMAGE_SENSOR_FULL_HEIGHT	 (1200)    



/* SENSOR PV SIZE */
#define SID130B_IMAGE_SENSOR_PV_WIDTH   (800)   
#define SID130B_IMAGE_SENSOR_PV_HEIGHT (600)


//SENSOR 3M size
#define SID130B_IMAGE_SENSOR_3M_WIDTH 	   (2048)	  
#define SID130B_IMAGE_SENSOR_3M_HEIGHT	   (1536)


/* SENSOR READ/WRITE ID */
#define SID130B_WRITE_ID					0x6E
#define SID130B_READ_ID						0x6F

/* SENSOR CHIP VERSION */
#define SID130B_SENSOR_ID					0x1B

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define SID130B_PV_PERIOD_PIXEL_NUMS          (816 + 359 + 7 + 2)/* Active + HST + Row fill+ 2 */
#define SID130B_PV_PERIOD_LINE_NUMS           (616 + 9)      /* Active + 9 */

#define SID130B_CAP_PERIOD_PIXEL_NUMS          (1630 + 359 + 7 + 2)/* Active + HST + Row fill+ 2 */
#define SID130B_CAP_PERIOD_LINE_NUMS           (1230 + 9)      /* Active + 9 */


#define SID130B_BLANK_REGISTER_LIMITATION   0xFFF

/*50Hz,60Hz*/
#define SID130B_NUM_50HZ    50 * 2
#define SID130B_NUM_60HZ    60 * 2

/* FRAME RATE UNIT */
#define SID130B_FRAME_RATE_UNIT               10

/* MAX CAMERA FRAME RATE */
#define SID130B_MAX_CAMERA_FPS         (SID130B_FRAME_RATE_UNIT * 30)


MM_ERROR_CODE_ENUM SID130BSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM SID130BWebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
#endif /* _IMAGE_SENSOR_H */ 
