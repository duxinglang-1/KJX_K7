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
 *   image_sensor.h
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV5650_H
#define _IMAGE_SENSOR_OV5650_H

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "isp_if.h"

/*****************************************************************************/
#define OV5650_PROCESSING_RAW
#define OV5650_WPC_BPC_CTRL 0x50 //OV 0x87 control register

#define OV5650_QVGA_LCM // define this option when LCM size >= QVGA resolution
//    #define MAX_ZOOM_FACTOR_2X  // zoom factor <= 2x. If this option is defined, the driver
// supports up to 2x zoom factor. If not defined, it supports
// up to 3x zoom factor

/*****************************************************************************/
//------------------------Engineer mode---------------------------------
#define OV5650_FACTORY_START_ADDR 5

typedef enum OV5650_group_enum
{
  OV5650_PRE_GAIN,
  OV5650_CMMCLK_CURRENT,
  OV5650_GROUP_TOTAL_NUMS
} OV5650_FACTORY_GROUP_ENUM;

typedef enum OV5650_register_index
{
  OV5650_CMMCLK_CURRENT_INDEX = OV5650_FACTORY_START_ADDR,
  OV5650_FACTORY_END_ADDR
} OV5650_FACTORY_REGISTER_INDEX;

typedef enum OV5650_cct_register_index
{
	OV5650_INDEX_BASE_GAIN = 0,
	OV5650_INDEX_PRE_GAIN_R,
	OV5650_INDEX_PRE_GAIN_G,
	OV5650_INDEX_PRE_GAIN_B,
	OV5650_PRE_GAIN_Gb_INDEX,
    OV5650_CCT_END_ADDR
} OV5650_CCT_REGISTER_INDEX;

// API FOR ENGINEER FACTORY MODE
void OV5650_get_sensor_group_count(kal_int32* sensor_count_ptr);
void OV5650_get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr);
void OV5650_get_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr);
kal_bool OV5650_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value);
//------------------------Engineer mode---------------------------------  
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))  
typedef struct
{
  sensor_reg_struct reg[OV5650_FACTORY_END_ADDR];
  sensor_reg_struct cct[OV5650_CCT_END_ADDR + 3];
} sensor_data_struct;
#endif


// write camera_para to sensor register 
void OV5650_camera_para_to_sensor(void);
// update camera_para from sensor register 
void OV5650_sensor_to_camera_para(void);
// config sensor callback function 
void OV5650_image_sensor_func_config(void);

// detect sensor id
kal_uint32 OV5650_detect_sensor_id(void);
void OV5650_get_sensor_prefix_name(kal_char* buf);
void OV5650_cct_global_variable_init(void);
kal_uint16 OV5650_get_max_exposure_lines(void);
void OV5650_set_max_exposure_lines(kal_uint32 shutter_lines);
kal_uint16 OV5650_get_min_exposure_lines(void);
void  OV5650_dispatch_camera_info(void);
kal_uint32 OV5650_get_valid_camera_type(void);    

/* MAXIMUM EXPLOSURE LINES USED BY AE */
extern kal_uint16 OV5650_MAX_EXPOSURE_LINES;
extern kal_uint8  OV5650_MIN_EXPOSURE_LINES;

/* DEFINITION USED BY CCT */
extern SensorInfo  OV5650_g_CCT_MainSensor;
extern kal_uint8  OV5650_g_CCT_FirstGrabColor;

typedef enum _OV5650_OP_TYPE_
{
  OV5650_MODE_NONE,
  OV5650_MODE_PREVIEW,
  OV5650_MODE_CAPTURE,
        OV5650_MODE_OTHER_VIDEO,
        OV5650_MODE_HVGA_VIDEO,
        OV5650_MODE_D1_VIDEO,
  OV5650_MODE_QCIF_VIDEO,
  OV5650_MODE_CIF_VIDEO
} OV5650_OP_TYPE;

extern OV5650_OP_TYPE g_iOV5650_Mode;

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define OV5650_MAX_FRAME_RATE  (15)    // Limitation for MPEG4 Encode Only
#define OV5650_MIN_FRAME_RATE  (12)    // Limitation for Camera Preiview

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV5650_FULL_PERIOD_PIXEL_NUMS  (3252)  // default pixel#(w/o dummy pixels) in UXGA mode
#define OV5650_FULL_PERIOD_LINE_NUMS   (1944)  // default line#(w/o dummy lines) in UXGA mode
//#define OV5650_PV_PERIOD_PIXEL_NUMS    (2111)  // default pixel#(w/o dummy pixels) in SVGA mode
//#define OV5650_PV_PERIOD_LINE_NUMS     (984)   // default line#(w/o dummy lines) in SVGA mode


/* SENSOR EXPOSURE LINE LIMITATION */
#define OV5650_FULL_EXPOSURE_LIMITATION    (1944)
#define OV5650_PV_EXPOSURE_LIMITATION      (984)

// sensor's full resolution
#define OV5650_IMAGE_SENSOR_FULL_WIDTH	   (2592) 
#define OV5650_IMAGE_SENSOR_FULL_HEIGHT    (1944)

// resolution for preview
#define OV5650_IMAGE_SENSOR_PV_WIDTH   (1280)
#define OV5650_IMAGE_SENSOR_PV_HEIGHT  (960)

#define OV5650_QXGA_MODE_WITHOUT_DUMMY_PIXELS  (3112)  
#define OV5650_XGA_MODE_WITHOUT_DUMMY_PIXELS   (OV5650_QXGA_MODE_WITHOUT_DUMMY_PIXELS / 2)	  
#define OV5650_PV_PERIOD_PIXEL_NUMS    (OV5650_XGA_MODE_WITHOUT_DUMMY_PIXELS) 

#define OV5650_QXGA_MODE_WITHOUT_DUMMY_LINES   (1968)
#define OV5650_XGA_MODE_WITHOUT_DUMMY_LINES    (984)
#define OV5650_PV_PERIOD_LINE_NUMS	   (OV5650_XGA_MODE_WITHOUT_DUMMY_LINES) 


// SETUP TIME NEED TO BE INSERTED
#define OV5650_IMAGE_SENSOR_PV_INSERTED_PIXELS (390)
#define OV5650_IMAGE_SENSOR_PV_INSERTED_LINES  (9 - 6)

#define OV5650_IMAGE_SENSOR_FULL_INSERTED_PIXELS   (248)
#define OV5650_IMAGE_SENSOR_FULL_INSERTED_LINES    (11 - 2)


#ifdef OV5650_QVGA_LCM
  #ifdef MAX_ZOOM_FACTOR_2X
  #define OV5650_PV_DUMMY_PIXELS          (400)
  #define OV5650_VIDEO_CIF_DUMMY_PIXELS  (0)
  #define OV5650_VIDEO_QCIF_DUMMY_PIXELS (0)
  #else   // #ifdef MAX_ZOOM_FACTOR_2X
  #define OV5650_PV_DUMMY_PIXELS          (600)
  #define OV5650_VIDEO_CIF_DUMMY_PIXELS  (100)
  #define OV5650_VIDEO_QCIF_DUMMY_PIXELS (0)
  #endif
#else   // #ifdef OV5650_QVGA_LCM
  #ifdef MAX_ZOOM_FACTOR_2X
  #define OV5650_PV_DUMMY_PIXELS          (400)
  #define OV5650_VIDEO_CIF_DUMMY_PIXELS  (0)
  #define OV5650_VIDEO_QCIF_DUMMY_PIXELS (0)
  #else   // #ifdef MAX_ZOOM_FACTOR_2X
  #define OV5650_PV_DUMMY_PIXELS          (600)
  #define OV5650_VIDEO_CIF_DUMMY_PIXELS  (100)
  #define OV5650_VIDEO_QCIF_DUMMY_PIXELS (0)
  #endif
#endif

// SENSOR READ/WRITE ID
#define OV5650_SW_SCCB_WRITE_ID (0x60)
#define OV5650_SW_SCCB_READ_ID  (0x61)

// SENSOR CHIP VERSION
#define OV5650_SENSOR_ID_2C (0x2642)
#define OV5650_SENSOR_ID_2B (0x2641)

#define OV5650_PAGE_SETTING_REG    (0xFF)

#define OV5650_SET_RESET_CMOS_SENSOR_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
#define OV5650_SET_RESET_CMOS_SENSOR_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
#define OV5650_SET_PDN_CMOS_SENSOR_LOW          REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT;

/* I2C FAIL TRY NUMBER */
#define OV5650_MAX_I2C_FAIL_TRY_NO       5

/* SENSOR I2C DELAY*/
#define OV5650_SENSOR_SW_SCCB_DELAY    (0x20)


#define OV5650_HW_SCCB_SLAVE_ADDR   0x6C

MM_ERROR_CODE_ENUM OV5650SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

#endif

