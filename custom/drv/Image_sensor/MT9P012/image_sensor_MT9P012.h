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
 *   image_sensor.h
 *
 * Project:
 * --------
 *   MT6228
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_MT9P012_H
#define _IMAGE_SENSOR_MT9P012_H

#include "drv_features.h"
//#include "sensor_struct.h"
#include "sensor_comm_def.h"
#include "image_sensor_nvram.h"


	//------------------------Engineer mode---------------------------------
	#define MT9P012_FACTORY_START_ADDR 0
	#define MT9P012_ENGINEER_START_ADDR 10
	#define MT9P012_compensetion_number 152
	
	typedef enum MT9P012_group_enum {
	   MT9P012_PRE_GAIN=0,
	   MT9P012_CMMCLK_CURRENT,
	   MT9P012_FRAME_RATE_LIMITATION,
	   MT9P012_REGISTER_EDITOR,
	   MT9P012_GROUP_TOTAL_NUMS
	} MT9P012_FACTORY_GROUP_ENUM;
	
	typedef enum MT9P012_register_index {
	   MT9P012_SENSOR_BASEGAIN=MT9P012_FACTORY_START_ADDR,
	   MT9P012_PRE_GAIN_R_INDEX,
	   MT9P012_PRE_GAIN_Gr_INDEX,
	   MT9P012_PRE_GAIN_Gb_INDEX,
	   MT9P012_PRE_GAIN_B_INDEX,	   
	   MT9P012_FACTORY_END_ADDR
	} MT9P012_FACTORY_REGISTER_INDEX;
	
	typedef enum MT9P012_engineer_index {
	   MT9P012_CMMCLK_CURRENT_INDEX=MT9P012_ENGINEER_START_ADDR,
	   MT9P012_ENGINEER_END
	} MT9P012_FACTORY_ENGINEER_INDEX;
	
  
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))
  
	  typedef struct {
		  sensor_reg_struct   reg[MT9P012_ENGINEER_END];
		sensor_reg_struct  cct[MT9P012_FACTORY_END_ADDR];
	  } sensor_data_struct;
#endif
  
	  typedef struct {
		  sensor_reg_struct   compenset[MT9P012_compensetion_number];
	  } MT9P012_sensor_shading_compenset;
  
	  extern const MT9P012_sensor_shading_compenset  MT9P012_sensor_shading;

    // CURRENT MAIN SENSOR 
    #define MT9P012_CURRENT_MAIN_SENSOR	            MT9P012_MICRON//MT9D011_MICRON

    /* START GRAB PIXEL OFFSET */
    #define MT9P012_IMAGE_SENSOR_START_GRAB_X       0	// 0 or 1 recommended
    #define MT9P012_IMAGE_SENSOR_START_GRAB_Y       0	// 0 or 1 recommended

    /* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
    #define MT9P012_MAX_FRAME_RATE                  15		// Limitation for MPEG4 Encode Only
    #define MT9P012_MIN_FRAME_RATE                  12

    /* SENSOR GLOBAL GAIN AT NIGHT MODE */
    #define MT9P012_SENSOR_NIGHT_MODE_GAIN          0xC0

    /* SENSOR FULL SIZE */
    #define MT9P012_IMAGE_SENSOR_FULL_WIDTH         (2592-16)	
    #define MT9P012_IMAGE_SENSOR_FULL_HEIGHT        (1944-14)

    /* SENSOR PV SIZE */
    #define MT9P012_IMAGE_SENSOR_PV_WIDTH           (1296-8)//(1280-4)
    #define MT9P012_IMAGE_SENSOR_PV_HEIGHT          (972-8)//(960-4)
    #define MT9P012_IMAGE_SENSOR_PV_WIDTH_DRV           (1296)
    #define MT9P012_IMAGE_SENSOR_PV_HEIGHT_DRV          (972)

    /* SENSOR SCALER FACTOR */
    #define MT9P012_PV_SCALER_FACTOR                3
    #define MT9P012_FULL_SCALER_FACTOR              1
	                                        	
    /* SENSOR START/EDE POSITION */         	
    #define MT9P012_FULL_X_START                    8
    #define MT9P012_FULL_Y_START                    8
    #define MT9P012_FULL_X_END                      2601
    #define MT9P012_FULL_Y_END                      1953
    #define MT9P012_FULL_HS_X_END                   2599
    #define MT9P012_FULL_HS_Y_END                   1951
    #define MT9P012_PV_X_START                      8
    #define MT9P012_PV_Y_START                      8
    #define MT9P012_PV_X_END                        2597//2597
    #define MT9P012_PV_Y_END                        1953//1949
	
    /* SENSOR HORIZONTAL/VERTICAL BLANKING */	
    #define MT9P012_IMAGE_SENSOR_FULL_HBLANKING	    (30)
    #define MT9P012_IMAGE_SENSOR_FULL_VBLANKING     (126)			

    #define MT9P012_IMAGE_SENSOR_FULL_HS_HBLANKING          (1856)
    #define MT9P012_IMAGE_SENSOR_FULL_HS_VBLANKING          (85)
	
    #define MT9P012_IMAGE_SENSOR_PV_HBLANKING        (160)	
    #define MT9P012_IMAGE_SENSOR_PV_VBLANKING        (130)			

    /* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
    #define MT9P012_FULL_ACTIVE_PIXEL_NUMS           (MT9P012_FULL_X_END-MT9P012_FULL_X_START+1-2)//2594 
    #define MT9P012_FULL_ACTIVE_LINE_NUMS            (MT9P012_FULL_Y_END-MT9P012_FULL_Y_START+1-2)//1946

    #define MT9P012_FULL_HS_ACTIVE_PIXEL_NUMS        (MT9P012_FULL_HS_X_END-MT9P012_FULL_X_START+1)//2592 
    #define MT9P012_FULL_HS_ACTIVE_LINE_NUMS         (MT9P012_FULL_HS_Y_END-MT9P012_FULL_Y_START+1)//1944	
	
    #define MT9P012_PV_ACTIVE_PIXEL_NUMS             ((MT9P012_PV_X_END-MT9P012_PV_X_START+1)/((MT9P012_PV_SCALER_FACTOR+1)/2))//1295
    #define MT9P012_PV_ACTIVE_LINE_NUMS	             ((MT9P012_PV_Y_END-MT9P012_PV_Y_START+1)/((MT9P012_PV_SCALER_FACTOR+1)/2))//976

    #define MT9P012_FULL_PERIOD_PIXEL_NUMS           (MT9P012_FULL_ACTIVE_PIXEL_NUMS+MT9P012_IMAGE_SENSOR_FULL_HBLANKING)//(2624)
    #define MT9P012_FULL_PERIOD_LINE_NUMS            (MT9P012_FULL_ACTIVE_LINE_NUMS+MT9P012_IMAGE_SENSOR_FULL_VBLANKING)//(2072)
    #define MT9P012_PV_PERIOD_PIXEL_NUMS             (MT9P012_PV_ACTIVE_PIXEL_NUMS+MT9P012_IMAGE_SENSOR_PV_HBLANKING)//(1455)
    #define MT9P012_PV_PERIOD_LINE_NUMS	             (MT9P012_PV_ACTIVE_LINE_NUMS+MT9P012_IMAGE_SENSOR_PV_VBLANKING)//(1106)

    #define MT9P012_FULL_HS_PERIOD_PIXEL_NUMS        (MT9P012_FULL_HS_ACTIVE_PIXEL_NUMS+MT9P012_IMAGE_SENSOR_FULL_HS_HBLANKING)//4448
    #define MT9P012_FULL_HS_PERIOD_LINE_NUMS         (MT9P012_FULL_HS_ACTIVE_LINE_NUMS+MT9P012_IMAGE_SENSOR_FULL_HS_VBLANKING)//2029

    /* DUMMY NEEDS TO BE INSERTED */
    /* SETUP TIME NEED TO BE INSERTED */
    #define MT9P012_IMAGE_SENSOR_PV_INSERTED_PIXELS          2	// Sync, Nosync=2
    #define MT9P012_IMAGE_SENSOR_PV_INSERTED_LINES           2

    #define MT9P012_IMAGE_SENSOR_FULL_INSERTED_PIXELS        2
    #define MT9P012_IMAGE_SENSOR_FULL_INSERTED_LINES         2

    //On the fly capture
    #define MT9P012_2X_ZOOM_IN_CAPTURE_FRAME                 (6)
    #define MT9P012_4X_ZOOM_IN_CAPTURE_FRAME                 (3)
    #define MT9P012_8X_ZOOM_IN_CAPTURE_FRAME                 (15/10)

    #define MT9P012_LIMIT_EXPOSURE_LINES                     (1253)

    #define MT9P012_VIDEO_FIX_30FRAME_RATE                   (300)
    #define MT9P012_VIDEO_FIX_15FRAME_RATE                   (150)
    #define MT9P012_VIDEO_FIX_12FRAME_RATE                   (120)	
    #define MT9P012_VIDEO_FIX_8FRAME_RATE                    (80)	
    #define MT9P012_VIDEO_FIX_7_5FRAME_RATE                  (75)
    #define MT9P012_VIDEO_FIX_5FRAME_RATE                    (50)	

    #define MT9P012_REV8_SUPPORT
	
    #define MT9P012_SENSOR_ID_REV7                           0x2801

#ifdef MT9P012_REV8_SUPPORT
    #define MT9P012_REV7										0x07
    #define MT9P012_REV8										0x08
#endif

    /* SENSOR READ/WRITE ID */
    #define MT9P012_SLV1_WRITE_ID                   0x20 /* SMIA */
    #define MT9P012_SLV1_READ_ID                    0x21
    #define MT9P012_SLV2_WRITE_ID                   0x30
    #define MT9P012_SLV2_READ_ID                    0x31
    #define MT9P012_SLV3_WRITE_ID                   0x6C /* MIPI */
    #define MT9P012_SLV3_READ_ID                    0x6D
    #define MT9P012_SLV4_WRITE_ID                   0x6E
    #define MT9P012_SLV4_READ_ID                    0x6F


    #define MT9P012_HW_SCCB_FAST_MODE_SPEED            320 /* unit: Kb */
    #define MT9P012_SCCB_FAST_MODE_SPEED_2            380 /* unit: Kb */

        /* SENSOR I2C DELAY*/
        #if defined(DRV_ISP_MT6236_HW_SUPPORT)
            #define MT9P012_SENSOR_I2C_DELAY                38
        #else
            #define MT9P012_SENSOR_I2C_DELAY                22
        #endif

    /* I2C FAIL TRY NUMBER */
    #define MT9P012_MAX_I2C_FAIL_TRY_NO             10

struct MT9P012_SENSOR_STRUCT
{
  kal_bool PvMode;
  kal_uint16 PvDummyPixels;
  kal_uint16 PvDummyLines;
  kal_uint16 CapDummyPixels;
  kal_uint16 CapDummyLines;
  kal_uint16 ExposureLines;
  kal_uint16 MaxExposureLines;
  kal_uint16 CapShutter;
  kal_uint16 SensorExpoWidth;
  kal_uint16 CurrentSensorExpoWidth;
  kal_uint16 SensorGainBase;
  kal_uint16 GlobalGain;
  kal_uint16 PrvPclk;
  kal_uint16 CapPclk;
  kal_bool HighSpeedCapture;
  kal_uint16 VideoMaxLineLength;
  kal_uint16 VideoCurrentFrameRate;
};

MM_ERROR_CODE_ENUM MT9P012SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM MT9P012WebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
	

#endif /* _IMAGE_SENSOR_MT9P012_H */
