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
 *   image_sensor_MT9P012_MIPI.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_MT9P012_MIPI_H//dual camera
#define _IMAGE_SENSOR_MT9P012_MIPI_H//dual camera

	#include "drv_features.h"
	//#include "sensor_struct.h"
	#include "sensor_comm_def.h"
	#include "image_sensor_nvram.h"

	//------------------------Engineer mode---------------------------------
	#define MT9P012_MIPI_FACTORY_START_ADDR 0
	#define MT9P012_MIPI_ENGINEER_START_ADDR 10
	#define MT9P012_MIPI_compensetion_number 152

	typedef enum MT9P012_MIPI_group_enum {
	   MT9P012_MIPI_PRE_GAIN=0,
	   MT9P012_MIPI_CMMCLK_CURRENT,
	   MT9P012_MIPI_FRAME_RATE_LIMITATION,
	   MT9P012_MIPI_REGISTER_EDITOR,
	   MT9P012_MIPI_GROUP_TOTAL_NUMS
	} MT9P012_MIPI_FACTORY_GROUP_ENUM;

	typedef enum MT9P012_MIPI_register_index {
	   MT9P012_MIPI_SENSOR_BASEGAIN=MT9P012_MIPI_FACTORY_START_ADDR,
	   MT9P012_MIPI_PRE_GAIN_R_INDEX,
	   MT9P012_MIPI_PRE_GAIN_Gr_INDEX,
	   MT9P012_MIPI_PRE_GAIN_Gb_INDEX,
	   MT9P012_MIPI_PRE_GAIN_B_INDEX,
	   MT9P012_MIPI_FACTORY_END_ADDR
	} MT9P012_MIPI_FACTORY_REGISTER_INDEX;



	typedef enum MT9P012_MIPI_engineer_index {
	   MT9P012_MIPI_CMMCLK_CURRENT_INDEX=MT9P012_MIPI_ENGINEER_START_ADDR,
	   MT9P012_MIPI_ENGINEER_END
	} MT9P012_MIPI_FACTORY_ENGINEER_INDEX;

#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))

	typedef struct {
		sensor_reg_struct	reg[MT9P012_MIPI_ENGINEER_END];
	  sensor_reg_struct	 cct[MT9P012_MIPI_FACTORY_END_ADDR];
	} sensor_data_struct;
#endif



    typedef struct {
        sensor_reg_struct   compenset[MT9P012_MIPI_compensetion_number];
    } MT9P012_MIPI_sensor_shading_compenset;

    extern const MT9P012_MIPI_sensor_shading_compenset  MT9P012_MIPI_sensor_shading;

    #define MT9P012_MIPI_CURRENT_MAIN_SENSOR                MT9P012_MICRON

	/* HW SCCB*/
    #define MT9P012_MIPI_HW_SCCB_SLAVE_ADDR                 (0x6C)
    #define MT9P012_MIPI_HW_SCCB_FAST_MODE_SPEED            (300)    //The speed of sccb fast mode(Kb)

	/* SW SCCB*/
    #define MT9P012_MIPI_SENSOR_I2C_DELAY					 38
    #define MT9P012_MIPI_SW_SCCB_WRITE_ID                    (0x6c)
    #define MT9P012_MIPI_SW_SCCB_READ_ID                     (0x6d)

    #define MT9P012_MIPI_MAX_FRAME_RATE 					 (15)    // Limitation for MPEG4 Encode Only
    #define MT9P012_MIPI_MIN_FRAME_RATE 					 (12)

    #define MT9P012_MIPI_LIMIT_EXPOSURE_LINES                (1055)

    /* SENSOR GLOBAL GAIN AT NIGHT MODE */
    #define MT9P012_MIPI_SENSOR_NIGHT_MODE_GAIN	             (0xC0)

    #define MT9P012_MIPI_PV_X_START                          (8)
    #define MT9P012_MIPI_PV_Y_START                          (8)
    #define MT9P012_MIPI_PV_X_END                            (2597)
    #define MT9P012_MIPI_PV_Y_END                            (1949)

    #define MT9P012_MIPI_FULL_X_START                        (8)
    #define MT9P012_MIPI_FULL_Y_START                        (8)
    #define MT9P012_MIPI_FULL_X_END                          (2599)
    #define MT9P012_MIPI_FULL_Y_END                          (1951)

    #define MT9P012_MIPI_PV_ACTIVE_PIXEL_NUMS                (MT9P012_MIPI_PV_X_END-MT9P012_MIPI_PV_X_START+2+1)//2592   //Preview binning mode
    #define MT9P012_MIPI_PV_ACTIVE_LINE_NUMS                 ((MT9P012_MIPI_PV_Y_END-MT9P012_MIPI_PV_Y_START+2+1)/2)//972

    #define MT9P012_MIPI_FULL_ACTIVE_PIXEL_NUMS              (MT9P012_MIPI_FULL_X_END-MT9P012_MIPI_FULL_X_START+1)//2592
    #define MT9P012_MIPI_FULL_ACTIVE_LINE_NUMS               (MT9P012_MIPI_FULL_Y_END-MT9P012_MIPI_FULL_Y_START+1)//1944

    #define MT9P012_MIPI_IMAGE_SENSOR_PV_HBLANKING           (808)
    #define MT9P012_MIPI_IMAGE_SENSOR_PV_VBLANKING           (83)

    #define MT9P012_MIPI_IMAGE_SENSOR_VGA_CAP_HBLANKING      (1038)
    #define MT9P012_MIPI_IMAGE_SENSOR_VGA_CAP_VBLANKING      (128)

    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_HS_HBLANKING      (1972)
    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_HS_VBLANKING      (85)

    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_OTF_HBLANKING     (3258)
    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_OTF_VBLANKING     (96)

    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_11FPS_HBLANKING   (2892)
    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_11FPS_VBLANKING   (85)

    /* LINE_LENGTH_PCK=Reg(0x300c)<<8|Reg(0x300d) */
    /* FRAME_LENGTH_LINES=Reg(0x300a)<<8|Reg(0x300b) */
    #define MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS                (MT9P012_MIPI_PV_ACTIVE_PIXEL_NUMS+MT9P012_MIPI_IMAGE_SENSOR_PV_HBLANKING)//(3400)
    #define MT9P012_MIPI_PV_PERIOD_LINE_NUMS                 (MT9P012_MIPI_PV_ACTIVE_LINE_NUMS+MT9P012_MIPI_IMAGE_SENSOR_PV_VBLANKING)//(1055)

    #define MT9P012_MIPI_VGA_CAP_PERIOD_PIXEL_NUMS           (MT9P012_MIPI_PV_ACTIVE_PIXEL_NUMS+MT9P012_MIPI_IMAGE_SENSOR_VGA_CAP_HBLANKING)//(3630)
    #define MT9P012_MIPI_VGA_CAP_PERIOD_LINE_NUMS            (MT9P012_MIPI_PV_ACTIVE_LINE_NUMS+MT9P012_MIPI_IMAGE_SENSOR_VGA_CAP_VBLANKING)//(1100)

    #define MT9P012_MIPI_FULL_HS_PERIOD_PIXEL_NUMS           (MT9P012_MIPI_FULL_ACTIVE_PIXEL_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_HS_HBLANKING)//(4564)
    #define MT9P012_MIPI_FULL_HS_PERIOD_LINE_NUMS            (MT9P012_MIPI_FULL_ACTIVE_LINE_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_HS_VBLANKING)//(2030)

    #define MT9P012_MIPI_FULL_OTF_PERIOD_PIXEL_NUMS          (MT9P012_MIPI_FULL_ACTIVE_PIXEL_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_OTF_HBLANKING)//(5850)
    #define MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS           (MT9P012_MIPI_FULL_ACTIVE_LINE_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_OTF_VBLANKING)//(2040)

    #define MT9P012_MIPI_FULL_11FPS_PERIOD_PIXEL_NUMS 	     (MT9P012_MIPI_FULL_ACTIVE_PIXEL_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_11FPS_HBLANKING)//(5484)
    #define MT9P012_MIPI_FULL_11FPS_PERIOD_LINE_NUMS	     (MT9P012_MIPI_FULL_ACTIVE_LINE_NUMS+MT9P012_MIPI_IMAGE_SENSOR_FULL_11FPS_VBLANKING)//(2029)

    /* SENSOR FULL SIZE */
    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_WIDTH             (2592-23)//2569
    #define MT9P012_MIPI_IMAGE_SENSOR_FULL_HEIGHT            (1944-16)//1928

    /* SENSOR PV SIZE */
    #define MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH               (1284)
    #define MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT	             (965)

    /*Video Fix Framerate*/
    #define MT9P012_MIPI_VIDEO_FRAME_RATE_30fps              (300)
    #define MT9P012_MIPI_VIDEO_FRAME_RATE_15fps              (150)
    #define MT9P012_MIPI_VIDEO_FRAME_RATE_12fps                  (120)
    #define MT9P012_MIPI_VIDEO_FRAME_RATE_7_5fps             (75)
    #define MT9P012_MIPI_VIDEO_FRAME_RATE_5fps               (50)

    /*On the fly capture*/
    #define MT9P012_MIPI_1X_ZOOM_IN_CAPTURE_FRAME            (8)
    #define MT9P012_MIPI_2X_ZOOM_IN_CAPTURE_FRAME            (6)
    #define MT9P012_MIPI_4X_ZOOM_IN_CAPTURE_FRAME            (3)
    #define MT9P012_MIPI_8X_ZOOM_IN_CAPTURE_FRAME            (15/10)

struct MT9P012_MIPI_SENSOR_STRUCT
{
  kal_bool PvMode;
  kal_uint16 PvDummyPixels;
  kal_uint16 PvDummyLines;
  kal_uint16 PvLineLength;
  kal_uint16 PvFrameLength;
  kal_uint16 CapDummyPixels;
  kal_uint16 CapDummyLines;
  kal_uint16 CapLineLength;
  kal_uint16 CapFrameLength;
  kal_uint16 CapShutter;
  kal_uint16 ExposureLines;
  kal_uint16 SensorGainBase;
  kal_uint16 GlobalGain;
  kal_uint16 PvPclk;
  kal_uint16 CapPclk;
  kal_uint16 VideoMaxLineLength;
  kal_uint16 VideoCurrentFrameRate;
  kal_bool HighSpeedCapture;
};


MM_ERROR_CODE_ENUM MT9P012MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

// usbvideo_attr_mt9p012_mipi.c
MM_ERROR_CODE_ENUM MT9P012MipiWebcamFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);

#endif /* _IMAGE_SENSOR_MT9P012_MIPI_H */
