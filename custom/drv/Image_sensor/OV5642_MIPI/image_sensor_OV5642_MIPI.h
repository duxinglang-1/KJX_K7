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
 *   image_sensor_OV5642_MIPI.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   OV5642 MIPI driver header.
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
 *----------------------------------------------------------------------------
  * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
  *============================================================================
  ****************************************************************************/

#ifndef _IMAGE_SENSOR_OV5642_MIPI_H
	#define _IMAGE_SENSOR_OV5642_MIPI_H

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "image_sensor_nvram.h"

    //------------------------Engineer mode---------------------------------
    #define OV5642_MIPI_FACTORY_START_ADDR  (39)

    typedef enum OV5642_MIPI_group_enum {
        OV5642_MIPI_PRE_GAIN = 0,
        OV5642_MIPI_CMMCLK_CURRENT,
        OV5642_MIPI_REGISTER_EDITOR,
        OV5642_MIPI_GROUP_TOTAL_NUMS
    } OV5642_MIPI_FACTORY_GROUP_ENUM;

    typedef enum OV5642_MIPI_register_index {
        OV5642_MIPI_INDEX_CMMCLK_CURRENT = OV5642_MIPI_FACTORY_START_ADDR,
        OV5642_MIPI_FACTORY_END_ADDR
    } OV5642_MIPI_FACTORY_REGISTER_INDEX;

    typedef enum OV5642_MIPI_cct_register_index {
        OV5642_MIPI_INDEX_BASE_GAIN = 0,
        OV5642_MIPI_INDEX_PRE_GAIN_R,
        OV5642_MIPI_INDEX_PRE_GAIN_G,
        OV5642_MIPI_INDEX_PRE_GAIN_B,
		OV5642_MIPI_PRE_GAIN_Gb_INDEX,	//Add 2008-09-05
        OV5642_MIPI_CCT_END_ADDR
    } OV5642_MIPI_CCT_REGISTER_INDEX;

    //------------------------Engineer mode---------------------------------
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))	
    typedef struct {
        sensor_reg_struct reg[OV5642_MIPI_FACTORY_END_ADDR];
        sensor_reg_struct cct[OV5642_MIPI_CCT_END_ADDR];
    } sensor_data_struct;
#endif

    typedef enum _OV5642_MIPI_OP_TYPE {
        OV5642_MIPI_MODE_NONE,
        OV5642_MIPI_MODE_PREVIEW,
        OV5642_MIPI_MODE_CAPTURE,
        OV5642_MIPI_MODE_QCIF_VIDEO,
        OV5642_MIPI_MODE_CIF_VIDEO
    } OV5642_MIPI_OP_TYPE;

    typedef enum OV5642_MIPI_RAW_BIT{ 
        OV5642_MIPI_8BIT_RAW,
        OV5642_MIPI_10BIT_RAW	
    } OV5642_RAW_BIT;

    extern OV5642_MIPI_OP_TYPE OV5642_MIPI_g_iOV5642_MIPI_Mode;

    /* MAXIMUM EXPLOSURE LINES USED BY AE */
    extern kal_uint16 OV5642_MIPI_MAX_EXPOSURE_LINES;
    extern kal_uint8  OV5642_MIPI_MIN_EXPOSURE_LINES;

    /* DEFINITION USED BY CCT */
    extern SensorInfo OV5642_MIPI_g_CCT_MainSensor;
    extern kal_uint8 OV5642_MIPI_g_CCT_FirstGrabColor;

	#define OV5642_MIPI_VIDEO_NORMALMODE_FRAME_RATE		(27)
	#define OV5642_MIPI_VIDEO_NIGHTMODE_FRAME_RATE		(15)

    #define OV5642_MIPI_XGA_MODE_WITHOUT_DUMMY_PIXELS   (OV5642_MIPI_QXGA_MODE_WITHOUT_DUMMY_PIXELS / 2)    /* XGA mode's pixel # in one HSYNC w/o dummy pixels */
    #define OV5642_MIPI_XGA_MODE_WITHOUT_DUMMY_LINES	(972)	/* XGA mode's HSYNC # in one HSYNC w/o dummy lines */

    #define OV5642_MIPI_QXGA_MODE_WITHOUT_DUMMY_PIXELS	(2592)	/* QXGA mode's pixel # in one HSYNC w/o dummy pixels */
    #define OV5642_MIPI_QXGA_MODE_WITHOUT_DUMMY_LINES   (1944)  /* QXGA mode's HSYNC # in one HSYNC w/o dummy lines */

    #define OV5642_MIPI_PV_PERIOD_PIXEL_NUMS			(1746) 
    #define OV5642_MIPI_PV_PERIOD_LINE_NUMS 	        (1000) 

    #define OV5642_MIPI_FULL_PERIOD_PIXEL_NUMS			(3200) 
    #define OV5642_MIPI_FULL_PERIOD_LINE_NUMS 			(2000) 

    // SENSOR EXPOSURE LINE LIMITATION
    #define OV5642_MIPI_FULL_MAX_LINES_PER_FRAME        (1944)  // QXGA mode
    #define OV5642_MIPI_FULL_EXPOSURE_LIMITATION        (OV5642_MIPI_FULL_MAX_LINES_PER_FRAME)//1944
    #define OV5642_MIPI_PV_MAX_LINES_PER_FRAME          (OV5642_MIPI_XGA_MODE_WITHOUT_DUMMY_LINES)  // 972 # of lines in one XGA frame
    #define OV5642_MIPI_PV_EXPOSURE_LIMITATION          (OV5642_MIPI_PV_MAX_LINES_PER_FRAME)//972
 
    #define OV5642_MIPI_SHUTTER_MAX_MARGIN             (10)

    // resolution for preview
    #define OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH          (1296-36)//1276
    #define OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT         (972-27)//957

    #define OV5642_MIPI_IMAGE_SENSOR_FULL_WIDTH        (2560-16)//2584
    #define OV5642_MIPI_IMAGE_SENSOR_FULL_HEIGHT       (1920-12)//1936	

    #define OV5642_MIPI_ISP_INTERPOLATIO_FILTER_WIDTH   (5)
    #define OV5642_MIPI_ISP_INTERPOLATIO_FILTER_HEIGHT  (7)

	/*Video Fix Framerate*/
    #define OV5642_MIPI_VIDEO_FRAME_RATE_30fps 				 (300)
    #define OV5642_MIPI_VIDEO_FRAME_RATE_15fps 				 (150)	
    #define OV5642_MIPI_VIDEO_FRAME_RATE_12fps 				 (120)	
    #define OV5642_MIPI_VIDEO_FRAME_RATE_7_5fps				 (75)
    #define OV5642_MIPI_VIDEO_FRAME_RATE_5fps			     (50)
	
	 /*On the fly capture*/
    #define OV5642_MIPI_1X_ZOOM_IN_CAPTURE_FRAME		     (8) 
    #define OV5642_MIPI_2X_ZOOM_IN_CAPTURE_FRAME		     (6)
    #define OV5642_MIPI_4X_ZOOM_IN_CAPTURE_FRAME			 (3)
    #define OV5642_MIPI_8X_ZOOM_IN_CAPTURE_FRAME			 (15/10)

    #define OV5642_MIPI_HORIZONTAL_BINNING                   0x80

	/* HW SCCB*/
    #define OV5642_MIPI_HW_SCCB_SLAVE_ADDR 				(0x78)
    #define OV5642_MIPI_HW_SCCB_FAST_MODE_SPEED			(300)	 //The speed of sccb fast mode(Kb)

    /* SENSOR READ/WRITE ID */
    #define OV5642_MIPI_WRITE_ID                             (0x78)
    #define OV5642_MIPI_READ_ID                              (0x79)  

	/* FIRST GRAB COLOR */
    #define OV5642_MIPI_FIRST_GRAB_COLOR                     (BAYER_Gr)
	
	// CURRENT MAIN SENSOR 
	#define OV5642_MIPI_CURRENT_MAIN_SENSOR				     OV5642_OMNIVISION

    #define OV5642_MIPI_SET_RESET_CMOS_SENSOR_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
    #define OV5642_MIPI_SET_RESET_CMOS_SENSOR_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
    #define OV5642_MIPI_SET_PDN_TO_LOW             (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT)

#if (defined(DRV_ISP_6238_SERIES))
    #define OV5642_MIPI_SENSOR_I2C_DELAY    (0x26)
#elif (defined(MCU_104M))
    #define OV5642_MIPI_SENSOR_I2C_DELAY    (0x40)
#endif

struct OV5642_MIPI_SENSOR_STRUCT
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
};


MM_ERROR_CODE_ENUM OV5642MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_OV5642_mipi.c
extern MM_ERROR_CODE_ENUM OV5642MipiWebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                    void* pFeatureParaIn, void* pFeatureParaOut,
                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);



#endif /* _IMAGE_SENSOR_OV5642_MIPI_H */
