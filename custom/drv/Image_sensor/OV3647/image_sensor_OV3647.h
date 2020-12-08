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
 *   image_sensor_OV3647.h
 *
 * Project:
 * --------
 *   Maui_sw
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV3647_H
#define _IMAGE_SENSOR_OV3647_H

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "isp_if.h"

/*****************************************************************************/

//added by mandrave
//#define __OV3647_DEBUG_TRACE__
#define OV3647_DUAL_CAMERA

//#define OV3647_FIRST_GRAB_COLOR    (BAYER_Gr)


//
#define OV3647_OUTPUT_DEBUG_INFO


#define OV3647_PROCESSING_RAW
#define OV3647_WPC_BPC_CTRL 0x50 //OV 0x87 control register

#define OV3647_QVGA_LCM // define this option when LCM size >= QVGA resolution
//    #define MAX_ZOOM_FACTOR_2X  // zoom factor <= 2x. If this option is defined, the driver
// supports up to 2x zoom factor. If not defined, it supports
// up to 3x zoom factor

/*****************************************************************************/
//------------------------Engineer mode---------------------------------
#define OV3647_FACTORY_START_ADDR 5

//********************************** OV3647 *********************************//

//#if (defined(DRV_ISP_6238_SERIES))
//	extern kal_bool aeIsEnable(void);
//#endif //DRV_ISP_6238_SERIES


#define OV3647_FACTORY_START_ADDR  (39)

typedef enum OV3647_group_enum {
        OV3647_PRE_GAIN = 0,
        OV3647_CMMCLK_CURRENT,
        OV3647_FRAME_RATE_LIMITATION,   //For OV3647 Connect to CDT
        OV3647_REGISTER_EDITOR,
        OV3647_GROUP_TOTAL_NUMS
    } OV3647_FACTORY_GROUP_ENUM;

    typedef enum OV3647_register_index {
        OV3647_INDEX_CMMCLK_CURRENT = OV3647_FACTORY_START_ADDR,
        OV3647_FACTORY_END_ADDR
    } OV3647_FACTORY_REGISTER_INDEX;

    typedef enum OV3647_cct_register_index {
        OV3647_INDEX_BASE_GAIN = 0,
        OV3647_INDEX_PRE_GAIN_R,
        OV3647_INDEX_PRE_GAIN_Gr,
        OV3647_INDEX_PRE_GAIN_Gb,
        OV3647_INDEX_PRE_GAIN_B,
        OV3647_CCT_END_ADDR
    } OV3647_CCT_REGISTER_INDEX;

	
    #if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))	
			typedef struct {
				  sensor_reg_struct reg[OV3647_FACTORY_END_ADDR];
				  sensor_reg_struct cct[OV3647_CCT_END_ADDR];
			  } sensor_data_struct;
	#endif

	
	typedef enum _OV3647_OP_TYPE {
		 OV3647_MODE_NONE,
		 OV3647_MODE_PREVIEW,
		 OV3647_MODE_CAPTURE,
		 OV3647_MODE_QCIF_VIDEO,
		 OV3647_MODE_CIF_VIDEO,
		 OV3647_MODE_D1_VIDEO,
		 OV3647_MODE_HVGA_VIDEO,
		 OV3647_MODE_MPEG4,
		 OV3647_MODE_WEBCAM
	 } OV3647_OP_TYPE;


	//Use to Fix video Framerate for 3X serise
#define OV3647_VIDEO_FIX_FRAMERATE_5                                (50)
#define OV3647_VIDEO_FIX_FRAMERATE_7_5                              (75)
#define OV3647_VIDEO_FIX_FRAMERATE_12                               (120)
#define OV3647_VIDEO_FIX_FRAMERATE_15                               (150)
#define OV3647_VIDEO_FIX_FRAMERATE_30                               (300)

#define	OV3647_VIDEO_NORMALMODE_FRAME_RATE         (30)
#define	OV3647_VIDEO_NIGHTMODE_FRAME_RATE          (15)

	/* Use the default dummy pixels and dummy lines to adjust the frame rate. */
#if (defined(DRV_ISP_6229_SERIES))
	/*	MCLK: 24M		PCLK:  24M(XGA)
			dummy pixel (126) reg0x0e(36),reg0x0f(c),reg0x11(0) 20fps */
	#define OV3647_XGA_DEFAULT_DUMMY_PIXELS		(180)//(16)	
	#define OV3647_XGA_DEFAULT_DUMMY_LINES			(0)
#elif (defined(DRV_ISP_6238_SERIES))
	/*	MCLK: 26M       PCLK:  34.66667M(XGA)
		dummy pixel (126) reg0x0e(36),reg0x0f(d),reg0x11(40) 30fps */
		//Use 48MHz PCLK, add the line XGA size to 1600*1000
	#define OV3647_XGA_DEFAULT_DUMMY_PIXELS		(260)	//1340 + 260 = 1600 to avoid the banding.
	#define OV3647_XGA_DEFAULT_DUMMY_LINES			(212)	//788 + 212 = 1000
#endif
	
#if (defined(DRV_ISP_6229_SERIES))
	/*	MCLK: 24M		PCLK:  24M(XGA)
			dummy pixel (126) reg0x0e(36),reg0x0f(c),reg0x11(0) 11.5fps */
	#define OV3647_QXGA_DEFAULT_DUMMY_PIXELS		(76)
	#define OV3647_QXGA_DEFAULT_DUMMY_LINES		(0)
#elif (defined(DRV_ISP_6238_SERIES))
	/*	MCLK: 26M       PCLK:  34.66667M(QXGA)
		dummy pixel (102) reg0x0e(32),reg0x0f(d),reg0x11(40) 12.5fps */
	#define OV3647_QXGA_DEFAULT_DUMMY_PIXELS		(0)//(300)//(500)	//500 for To solve the CCT capture JPEG time out problem after modify the banding problem.
	#define OV3647_QXGA_DEFAULT_DUMMY_LINES		(0)
#endif

    // 0x28, 0x29 defines the PCLKs in one line of OV3647
    // If [0x28:0x29] = N, the total PCLKs in one line of QXGA(3M full mode) is (N+1), and
    // total PCLKs in one line of XGA subsampling mode is (N+1) / 2
    // If need to add dummy pixels, just increase 0x28 and 0x29 directly
    #define OV3647_QXGA_MODE_WITHOUT_DUMMY_PIXELS  (2364)  // QXGA mode's pixel # in one HSYNC w/o dummy pixels
    #define OV3647_XGA_MODE_WITHOUT_DUMMY_PIXELS   (1340)    // XGA mode's pixel # in one HSYNC w/o dummy pixels
    #define OV3647_PV_PERIOD_PIXEL_NUMS    (OV3647_XGA_MODE_WITHOUT_DUMMY_PIXELS + OV3647_XGA_DEFAULT_DUMMY_PIXELS) // dummy pixels is down sampled by half in XGA mode
    #define OV3647_CAP_PERIOD_PIXEL_NUMS    (OV3647_QXGA_MODE_WITHOUT_DUMMY_PIXELS + OV3647_QXGA_DEFAULT_DUMMY_PIXELS) // dummy pixels is down sampled by half in XGA mode

    // 0x2A,0x2B defines total lines in one frame of OV3647
    // If [0x2A,0x2B] = N, the total lines in one is N in dependent of resolution setting
    // Even in XGA subsampling mode, total lines defined by 0x302A, 0x302B is not subsampled.
    // If need dummy lines, just increase 0x2A and 0x2B directly
    #define OV3647_QXGA_MODE_WITHOUT_DUMMY_LINES   (1574)  // QXGA mode's HSYNC # in one HSYNC w/o dummy lines
    #define OV3647_XGA_MODE_WITHOUT_DUMMY_LINES    (788)   // XGA mode's HSYNC # in one HSYNC w/o dummy lines
    #define OV3647_PV_PERIOD_LINE_NUMS     (OV3647_XGA_MODE_WITHOUT_DUMMY_LINES + OV3647_XGA_DEFAULT_DUMMY_LINES)  // XGA mode's HSYNC # in one VSYNC period
    #define OV3647_CAP_PERIOD_LINE_NUMS    (OV3647_QXGA_MODE_WITHOUT_DUMMY_LINES + OV3647_QXGA_DEFAULT_DUMMY_LINES) // dummy pixels is down sampled by half in XGA mode

    // SENSOR EXPOSURE LINE LIMITATION
    #define OV3647_FULL_MAX_LINES_PER_FRAME    (1568)  // QXGA mode
    #define OV3647_FULL_EXPOSURE_LIMITATION    (OV3647_FULL_MAX_LINES_PER_FRAME)
    #define OV3647_PV_MAX_LINES_PER_FRAME  (OV3647_XGA_MODE_WITHOUT_DUMMY_LINES)  // # of lines in one XGA frame
    #define OV3647_PV_EXPOSURE_LIMITATION  (OV3647_PV_MAX_LINES_PER_FRAME)
	
    // sensor's full resolution
    #define OV3647_IMAGE_SENSOR_FULL_WIDTH     (2048 - 16)//(2048 - 32)		//For the shading parameter.
    #define OV3647_IMAGE_SENSOR_FULL_HEIGHT    (1536 - 12)//(1536 - 24)

	//Interpolate to 5M size.
	#define OV3647_IMAGE_SENSOR_5M_WIDTH		(2592) //(2560)
	#define OV3647_IMAGE_SENSOR_5M_HEIGHT		(1944) //(1920)

	// 3M capture size
	#define OV3647_IMAGE_SENSOR_3M_WIDTH		2048
	#define OV3647_IMAGE_SENSOR_3M_HEIGHT		1536

    // resolution for preview
    #define OV3647_IMAGE_SENSOR_PV_WIDTH   (1024 - 16)
    #define OV3647_IMAGE_SENSOR_PV_HEIGHT  (768 - 12)

	#define OV3647_IMAGE_SENSOR_PV_INSERT_START_X		2
	#define OV3647_IMAGE_SENSOR_PV_INSERT_START_Y		2

	#define OV3647_IMAGE_SENSOR_FULL_INSERT_START_X		2
	#define OV3647_IMAGE_SENSOR_FULL_INSERT_START_Y		2

	/* SENSOR FULL/PV SIZE */
    #define OV3647_IMAGE_SENSOR_FULL_WIDTH_DRV   2048
    #define OV3647_IMAGE_SENSOR_FULL_HEIGHT_DRV  1536
    #define OV3647_IMAGE_SENSOR_PV_WIDTH_DRV     (OV3647_IMAGE_SENSOR_FULL_WIDTH_DRV / 2)
    #define OV3647_IMAGE_SENSOR_PV_HEIGHT_DRV    (OV3647_IMAGE_SENSOR_FULL_HEIGHT_DRV / 2)

	//On the fly capture


    #if (defined(DRV_ISP_6228_SERIES) || defined(DRV_ISP_6229_SERIES))
        #define OV3647_ISP_INTERPOLATIO_FILTER_WIDTH   (7)
        #define OV3647_ISP_INTERPOLATIO_FILTER_HEIGHT  (7)
    #elif (defined(DRV_ISP_6238_SERIES))
        #define OV3647_ISP_INTERPOLATIO_FILTER_WIDTH   (5)
        #define OV3647_ISP_INTERPOLATIO_FILTER_HEIGHT  (7)
		#if 0
/* under construction !*/
/* under construction !*/
		#endif
    #else
        #error "The Platform Does Not Support 3M Sensor!!"
    #endif

    /* SENSOR READ/WRITE ID */
    #define OV3647_WRITE_ID (0x90)
    #define OV3647_READ_ID  (0x91)

    /* SENSOR CHIP VERSION */
    //#define OV3647_SENSOR_ID    (0x364A)		//Need read out to check.

    #define OV3647_FIRST_GRAB_COLOR    (BAYER_Gr)

//********************************** OV3647 END****************************//


 
// API FOR ENGINEER FACTORY MODE
void OV3647_get_sensor_group_count(kal_int32* sensor_count_ptr);
void OV3647_get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr);
void OV3647_get_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr);
kal_bool OV3647_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value);
//------------------------Engineer mode---------------------------------  
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))  
typedef struct
{
  sensor_reg_struct reg[OV3647_FACTORY_END_ADDR];
  sensor_reg_struct cct[OV3647_CCT_END_ADDR + 3];
} sensor_data_struct;
#endif


// write camera_para to sensor register 
void OV3647_camera_para_to_sensor(void);
// update camera_para from sensor register 
void OV3647_sensor_to_camera_para(void);
// config sensor callback function 
void OV3647_image_sensor_func_config(void);

// detect sensor id
kal_uint32 OV3647_detect_sensor_id(void);
void OV3647_get_sensor_prefix_name(kal_char* buf);
void OV3647_cct_global_variable_init(void);
kal_uint16 OV3647_get_max_exposure_lines(void);
void OV3647_set_max_exposure_lines(kal_uint32 shutter_lines);
kal_uint16 OV3647_get_min_exposure_lines(void);
void  OV3647_dispatch_camera_info(void);
kal_uint32 OV3647_get_valid_camera_type(void);    

/* MAXIMUM EXPLOSURE LINES USED BY AE */
extern kal_uint16 OV3647_MAX_EXPOSURE_LINES;
extern kal_uint8  OV3647_MIN_EXPOSURE_LINES;

/* DEFINITION USED BY CCT */
extern SensorInfo  OV3647_g_CCT_MainSensor;
extern kal_uint8  OV3647_g_CCT_FirstGrabColor;
//OV3647_g_CCT_MainSensor =  OV3647_OMNIVISION;

//OV3647_g_CCT_FirstGrabColor = BAYER_Gr;

 

//tern OV3647_OP_TYPE g_iOV3647_Mode;

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
 

#define OV3647_PAGE_SETTING_REG    (0xFF)

#define OV3647_SET_RESET_CMOS_SENSOR_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
#define OV3647_SET_RESET_CMOS_SENSOR_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
#define OV3647_SET_PDN_CMOS_SENSOR_LOW          REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT;

/* I2C FAIL TRY NUMBER */
#define OV3647_MAX_I2C_FAIL_TRY_NO       5

/* SENSOR I2C DELAY*/
#define OV3647_SENSOR_SW_SCCB_DELAY    (0x20)


#define OV3647_HW_SCCB_SLAVE_ADDR   0x60

MM_ERROR_CODE_ENUM OV3647SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

#endif

