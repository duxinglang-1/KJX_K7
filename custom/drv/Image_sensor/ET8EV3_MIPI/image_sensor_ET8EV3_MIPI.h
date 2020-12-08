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
 *   image_sensor_ET8EV3_MIPI.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   ET8EV3 MIPI driver header.
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
 *----------------------------------------------------------------------------
  * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
  *============================================================================
  ****************************************************************************/

#ifndef _IMAGE_SENSOR_ET8EV3_MIPI_H
	#define _IMAGE_SENSOR_ET8EV3_MIPI_H
	
	//#define __PREVIEW_720P__

	#define __PREVIEW_1_4_FULL_SIZE   // 1270*950

	#define  _SENSOR_CLOSE_AWB_  //Close Sensor  AWB

	#define  _CAPURE_12_FPS_

	//#define  _CAPURE_10_FPS_

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "image_sensor_nvram.h"

    //------------------------Engineer mode---------------------------------
    #define ET8EV3_MIPI_FACTORY_START_ADDR  (39)

    typedef enum ET8EV3_MIPI_group_enum {
        ET8EV3_MIPI_PRE_GAIN = 0,
        ET8EV3_MIPI_CMMCLK_CURRENT,
        ET8EV3_MIPI_REGISTER_EDITOR,
        ET8EV3_MIPI_GROUP_TOTAL_NUMS
    } ET8EV3_MIPI_FACTORY_GROUP_ENUM;

    typedef enum ET8EV3_MIPI_register_index {
        ET8EV3_MIPI_INDEX_CMMCLK_CURRENT = ET8EV3_MIPI_FACTORY_START_ADDR,
        ET8EV3_MIPI_FACTORY_END_ADDR
    } ET8EV3_MIPI_FACTORY_REGISTER_INDEX;

    typedef enum ET8EV3_MIPI_cct_register_index {
        ET8EV3_MIPI_INDEX_BASE_GAIN = 0,
        ET8EV3_MIPI_INDEX_PRE_GAIN_R,
        ET8EV3_MIPI_INDEX_PRE_GAIN_Gr,
        ET8EV3_MIPI_INDEX_PRE_GAIN_B,
		ET8EV3_MIPI_INDEX_PRE_GAIN_Gb,	
        ET8EV3_MIPI_CCT_END_ADDR
    } ET8EV3_MIPI_CCT_REGISTER_INDEX;

    //------------------------Engineer mode---------------------------------
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))	
    typedef struct {
        sensor_reg_struct reg[ET8EV3_MIPI_FACTORY_END_ADDR];
        sensor_reg_struct cct[ET8EV3_MIPI_CCT_END_ADDR];
    } sensor_data_struct;
#endif

    typedef enum _ET8EV3_MIPI_OP_TYPE {
        ET8EV3_MIPI_MODE_NONE,
        ET8EV3_MIPI_MODE_PREVIEW,
        ET8EV3_MIPI_MODE_CAPTURE,
        ET8EV3_MIPI_MODE_QCIF_VIDEO,
        ET8EV3_MIPI_MODE_CIF_VIDEO
    } ET8EV3_MIPI_OP_TYPE;

    typedef enum ET8EV3_MIPI_RAW_BIT{ 
        ET8EV3_MIPI_8BIT_RAW,
        ET8EV3_MIPI_10BIT_RAW	
    } ET8EV3_RAW_BIT;

    extern ET8EV3_MIPI_OP_TYPE ET8EV3_MIPI_g_iET8EV3_MIPI_Mode;

    /* MAXIMUM EXPLOSURE LINES USED BY AE */
    extern kal_uint16 ET8EV3_MIPI_MAX_EXPOSURE_LINES;
    extern kal_uint8  ET8EV3_MIPI_MIN_EXPOSURE_LINES;

    /* DEFINITION USED BY CCT */
    extern SensorInfo ET8EV3_MIPI_g_CCT_MainSensor;
    extern kal_uint8 ET8EV3_MIPI_g_CCT_FirstGrabColor;

    //danbo Note: This sensro Analog gain 1X is 44.  but In 450 Lux has Banding
    //So Change SensorBase Gain 44 to 22, Reduce Banding  At about 800Lux.
	#define ET8EV3_BASE_GAIN 44  

	#define ET8EV3_BASE_GAIN_APPLY_SENSOR 22//44


//Preview Setting
#ifdef __PREVIEW_1_4_FULL_SIZE

     // Toshiba FAE suggest Pixe nums is 2210,but webcamera has shading block,So add 100.
//    #define ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS			(2210)//(1280)//(1304) 
	#define ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS			(2210+100)//(1280)//(1304) 
    #define ET8EV3_MIPI_PV_PERIOD_LINE_NUMS 	        (1020)//(720)//(980) 

	#define ET8EV3_MIPI_CA_PERIOD_PIXEL_NUMS			(2210)// Please refer to TTLDOT[13:0]
	#define ET8EV3_MIPI_CA_PERIOD_LINE_NUMS 			(1020)// Please refer to TTLLINE[15:0]

    // resolution for preview
	#define ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH		   (1280-10)//(1288-64)//(1304)
	#define ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT		   (950)//(988-48)//(980)	
#else
	#ifdef __PREVIEW_720P__
	    #define ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS			(2200)//(1280)//(1304) 
	    #define ET8EV3_MIPI_PV_PERIOD_LINE_NUMS 	        (1020)//(720)//(980) 
		
		#define ET8EV3_MIPI_CA_PERIOD_PIXEL_NUMS			(2200)// Please refer to TTLDOT[13:0]
		#define ET8EV3_MIPI_CA_PERIOD_LINE_NUMS			(1020)// Please refer to TTLLINE[15:0]

		// resolution for preview
		#define ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH		   (1280-10)//(1304)
		#define ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT		   (720-10)//(980)	
	#else
		#define ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS			(3310)//(1280)//(1304) 
		#define ET8EV3_MIPI_PV_PERIOD_LINE_NUMS 			(516)//(720)//(980) 
	    // resolution for preview

		#define ET8EV3_MIPI_CA_PERIOD_PIXEL_NUMS			(2168)//(1280)//(1304) 
		#define ET8EV3_MIPI_CA_PERIOD_LINE_NUMS 			(516)//(720)//(980) 

		#define ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH		   (640-8)//(1280)//(1304)
		#define ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT		   (480-6)//(720)//(980)	
	#endif
#endif


//Capture Setting
    //Capture 14fps Pixel Num and Line Num
    // Toshiba FAE suggest Pixe nums is 3400 ,but Capture has shading block,So add 200.
	#define ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_14_FPS			(3400+200)//(2608)	//ttldot
	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_14_FPS			(2012)//(1960)	 //ttline

    //Capture 12fps Pixel Num and Line Num
    // Toshiba FAE suggest Pixe nums is 3400 ,but Capture has shading block,So add 200.
	#define ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_12_FPS			(3400+200)//(2608)	//ttldot
	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_12_FPS			(2012)//(1960)	 //ttline

    //Capture 10.8fps Pixel Num and Line Num
    // Toshiba FAE suggest Pixe nums is 3400 ,but Capture has shading block,So add 200.
	#define ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_10_8_FPS			(3400+200)//(2608)	//ttldot
	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_10_8_FPS			(2012)//(1960)	 //ttline

    //Capture 8fps Pixel Num and Line Num
    // Toshiba FAE suggest Pixe nums is 4410 ,but Capture has shading block,So add 200.
	#define ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_8_FPS			(4410+200)//(2608)	//ttldot
	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_8_FPS			(2012)//(1960)	 //ttline

    //Capture 3.5fps Pixel Num and Line Num
    // Toshiba FAE suggest Pixe nums is 3400 ,but Capture has shading block,So add 200.
	#define ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_3_5_FPS			(3400+200)//(2608)	//ttldot
	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_3_5_FPS			(2012)//(1960)	 //ttline

	#define ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS			(2012)//(1960)	 //ttline

	#define ET8EV3_MIPI_3M_WIDTH					 (2048)
	#define ET8EV3_MIPI_3M_HEIGHT					 (1536)

	#define ET8EV3_MIPI_4M_WIDTH                     (2304)
	#define ET8EV3_MIPI_4M_HEIGHT                    (1728)

	#define ET8EV3_MIPI_5M_WIDTH					 (2592)
	#define ET8EV3_MIPI_5M_HEIGHT					 (1944)
    
	#define ET8EV3_MIPI_IMAGE_SENSOR_FULL_WIDTH 	   (2600-40)//(2560)
	#define ET8EV3_MIPI_IMAGE_SENSOR_FULL_HEIGHT	   (1950-30)//(1920)	

	/*Video Fix Framerate*/
    #define ET8EV3_MIPI_VIDEO_FRAME_RATE_30fps 				 (300)
    #define ET8EV3_MIPI_VIDEO_FRAME_RATE_15fps 				 (150)	
    #define ET8EV3_MIPI_VIDEO_FRAME_RATE_12fps 				 (120)	
    #define ET8EV3_MIPI_VIDEO_FRAME_RATE_7_5fps				 (75)
    #define ET8EV3_MIPI_VIDEO_FRAME_RATE_5fps			     (50)
	
	 /*On the fly capture*/
    #define ET8EV3_MIPI_1X_ZOOM_IN_CAPTURE_FRAME		     (8) 
    #define ET8EV3_MIPI_2X_ZOOM_IN_CAPTURE_FRAME		     (8)
    #define ET8EV3_MIPI_4X_ZOOM_IN_CAPTURE_FRAME			 (3.5)
    #define ET8EV3_MIPI_8X_ZOOM_IN_CAPTURE_FRAME			 (2)

    #define ET8EV3_MIPI_HORIZONTAL_BINNING                   0x80

	/* HW SCCB*/
    #define ET8EV3_MIPI_HW_SCCB_SLAVE_ADDR 				(0x6C)
	#define ET8EV3_MIPI_HW_SCCB_SLAVE_ADDR_1		    (0x6E)
    #define ET8EV3_MIPI_HW_SCCB_FAST_MODE_SPEED			(300)	 //The speed of sccb fast mode(Kb)

    /* SENSOR READ/WRITE ID */
    #define ET8EV3_MIPI_WRITE_ID                             (0x6C)
    #define ET8EV3_MIPI_READ_ID                              (0x6D)  

	/* FIRST GRAB COLOR */
    #define ET8EV3_MIPI_FIRST_GRAB_COLOR                     (BAYER_B)
	
	// CURRENT MAIN SENSOR 
	#define ET8EV3_MIPI_CURRENT_MAIN_SENSOR				     ET8EV3_MICRON

    #define ET8EV3_MIPI_SET_RESET_CMOS_SENSOR_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
    #define ET8EV3_MIPI_SET_RESET_CMOS_SENSOR_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
    #define ET8EV3_MIPI_SET_PDN_TO_LOW             (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT)

#if (defined(DRV_ISP_6238_SERIES))
    #define ET8EV3_MIPI_SENSOR_I2C_DELAY    (0x26)
#elif (defined(MCU_104M))
    #define ET8EV3_MIPI_SENSOR_I2C_DELAY    (0x40)
#endif

struct ET8EV3_MIPI_SENSOR_STRUCT
{
  kal_bool PvMode;  
  kal_uint16 PvDummyPixels;
  kal_uint16 PvDummyLines;
  kal_uint16 CapDummyPixels;
  kal_uint16 CapDummyLines;
  kal_uint16 PvLineLength;
  kal_uint16 PvFrameLength;
  kal_uint16 CapLineLength;
  kal_uint16 CapFrameLength;
  kal_uint16 ExposureLines;
  kal_uint16 BackupExposureLines;
  kal_uint16 CapShutter;
  kal_uint16 PrvPclk;
  kal_uint16 CapPclk;
  kal_uint16 VideoMaxLineLength;
  kal_uint16 VideoCurrentFrameRate;
  kal_bool HighSpeedCapture;

};


MM_ERROR_CODE_ENUM ET8EV3MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_ET8EV3_mipi.c
extern MM_ERROR_CODE_ENUM ET8EV3MipiWebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                    void* pFeatureParaIn, void* pFeatureParaOut,
                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);



#endif /* _IMAGE_SENSOR_ET8EV3_MIPI_H */
