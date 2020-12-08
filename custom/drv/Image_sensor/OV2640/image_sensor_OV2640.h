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
 *   image_sensor_OV2640.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV2640_H
#define _IMAGE_SENSOR_OV2640_H

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "isp_if.h"

/*****************************************************************************/
#define OV2640_PROCESSING_RAW
#define OV2640_WPC_BPC_CTRL 0x50 //OV 0x87 control register

#define OV2640_QVGA_LCM // define this option when LCM size >= QVGA resolution
//    #define MAX_ZOOM_FACTOR_2X  // zoom factor <= 2x. If this option is defined, the driver
// supports up to 2x zoom factor. If not defined, it supports
// up to 3x zoom factor

/*****************************************************************************/
//------------------------Engineer mode---------------------------------
#define OV2640_FACTORY_START_ADDR 5

typedef enum OV2640_group_enum
{
  OV2640_PRE_GAIN,
  OV2640_CMMCLK_CURRENT,
  OV2640_GROUP_TOTAL_NUMS
} OV2640_FACTORY_GROUP_ENUM;

typedef enum OV2640_register_index
{
  OV2640_CMMCLK_CURRENT_INDEX = OV2640_FACTORY_START_ADDR,
  OV2640_FACTORY_END_ADDR
} OV2640_FACTORY_REGISTER_INDEX;

typedef enum OV2640_cct_register_index
{
  OV2640_GLOBAL_GAIN_INDEX = 0,
  OV2640_PRE_GAIN_RB_INDEX,
  OV2640_PRE_GAIN_G_INDEX,
  OV2640_CCT_END_ADDR
} OV2640_CCT_REGISTER_INDEX;

// API FOR ENGINEER FACTORY MODE
void OV2640_get_sensor_group_count(kal_int32* sensor_count_ptr);
void OV2640_get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr);
void OV2640_get_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr);
kal_bool OV2640_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value);
//------------------------Engineer mode---------------------------------  
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))  
typedef struct
{
  sensor_reg_struct reg[OV2640_FACTORY_END_ADDR];
  sensor_reg_struct cct[OV2640_CCT_END_ADDR + 3];
} sensor_data_struct;
#endif


// write camera_para to sensor register 
void OV2640_camera_para_to_sensor(void);
// update camera_para from sensor register 
void OV2640_sensor_to_camera_para(void);
// config sensor callback function 
void OV2640_image_sensor_func_config(void);

// detect sensor id
kal_uint32 OV2640_detect_sensor_id(void);
void OV2640_get_sensor_prefix_name(kal_char* buf);
void OV2640_cct_global_variable_init(void);
kal_uint16 OV2640_get_max_exposure_lines(void);
void OV2640_set_max_exposure_lines(kal_uint32 shutter_lines);
kal_uint16 OV2640_get_min_exposure_lines(void);
void  OV2640_dispatch_camera_info(void);
kal_uint32 OV2640_get_valid_camera_type(void);    

/* MAXIMUM EXPLOSURE LINES USED BY AE */
extern kal_uint16 OV2640_MAX_EXPOSURE_LINES;
extern kal_uint8  OV2640_MIN_EXPOSURE_LINES;

/* DEFINITION USED BY CCT */
extern SensorInfo  OV2640_g_CCT_MainSensor;
extern kal_uint8  OV2640_g_CCT_FirstGrabColor;

typedef enum _OV2640_OP_TYPE_
{
  OV2640_MODE_NONE,
  OV2640_MODE_PREVIEW,
  OV2640_MODE_CAPTURE,
  OV2640_MODE_QCIF_VIDEO,
  OV2640_MODE_CIF_VIDEO
} OV2640_OP_TYPE;

extern OV2640_OP_TYPE g_iOV2640_Mode;

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define OV2640_MAX_FRAME_RATE  (15)    // Limitation for MPEG4 Encode Only
#define OV2640_MIN_FRAME_RATE  (12)    // Limitation for Camera Preiview

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV2640_FULL_PERIOD_PIXEL_NUMS  (1922)  // default pixel#(w/o dummy pixels) in UXGA mode
#define OV2640_FULL_PERIOD_LINE_NUMS   (1248)  // default line#(w/o dummy lines) in UXGA mode
#define OV2640_PV_PERIOD_PIXEL_NUMS    (1190)  // default pixel#(w/o dummy pixels) in SVGA mode
#define OV2640_PV_PERIOD_LINE_NUMS     (672)   // default line#(w/o dummy lines) in SVGA mode


/* SENSOR EXPOSURE LINE LIMITATION */
#define OV2640_FULL_EXPOSURE_LIMITATION    (1248)
#define OV2640_PV_EXPOSURE_LIMITATION      (672)

// SENSOR VGA SIZE
#define OV2640_IMAGE_SENSOR_PV_WIDTH   (800-8)
#define OV2640_IMAGE_SENSOR_PV_HEIGHT  (600-6)

// SENSOR UXGA SIZE
#define OV2640_IMAGE_SENSOR_FULL_WIDTH     (1600-16)
#define OV2640_IMAGE_SENSOR_FULL_HEIGHT    (1200-12)

// SETUP TIME NEED TO BE INSERTED
#define OV2640_IMAGE_SENSOR_PV_INSERTED_PIXELS (390)
#define OV2640_IMAGE_SENSOR_PV_INSERTED_LINES  (9 - 6)

#define OV2640_IMAGE_SENSOR_FULL_INSERTED_PIXELS   (248)
#define OV2640_IMAGE_SENSOR_FULL_INSERTED_LINES    (11 - 2)


#ifdef OV2640_QVGA_LCM
  #ifdef MAX_ZOOM_FACTOR_2X
  #define OV2640_PV_DUMMY_PIXELS          (400)
  #define OV2640_VIDEO_CIF_DUMMY_PIXELS  (0)
  #define OV2640_VIDEO_QCIF_DUMMY_PIXELS (0)
  #else   // #ifdef MAX_ZOOM_FACTOR_2X
  #define OV2640_PV_DUMMY_PIXELS          (600)
  #define OV2640_VIDEO_CIF_DUMMY_PIXELS  (100)
  #define OV2640_VIDEO_QCIF_DUMMY_PIXELS (0)
  #endif
#else   // #ifdef OV2640_QVGA_LCM
  #ifdef MAX_ZOOM_FACTOR_2X
  #define OV2640_PV_DUMMY_PIXELS          (400)
  #define OV2640_VIDEO_CIF_DUMMY_PIXELS  (0)
  #define OV2640_VIDEO_QCIF_DUMMY_PIXELS (0)
  #else   // #ifdef MAX_ZOOM_FACTOR_2X
  #define OV2640_PV_DUMMY_PIXELS          (600)
  #define OV2640_VIDEO_CIF_DUMMY_PIXELS  (100)
  #define OV2640_VIDEO_QCIF_DUMMY_PIXELS (0)
  #endif
#endif

// SENSOR READ/WRITE ID
#define OV2640_SW_SCCB_WRITE_ID (0x60)
#define OV2640_SW_SCCB_READ_ID  (0x61)

// SENSOR CHIP VERSION
#define OV2640_SENSOR_ID_2C (0x2642)
#define OV2640_SENSOR_ID_2B (0x2641)

#define OV2640_PAGE_SETTING_REG    (0xFF)

#define OV2640_SET_RESET_CMOS_SENSOR_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)
#define OV2640_SET_RESET_CMOS_SENSOR_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
#define OV2640_SET_PDN_CMOS_SENSOR_LOW          REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT;

/* I2C FAIL TRY NUMBER */
#define OV2640_MAX_I2C_FAIL_TRY_NO       5

/* SENSOR I2C DELAY*/
#define OV2640_SENSOR_SW_SCCB_DELAY    (0x20)


#define OV2640_HW_SCCB_SLAVE_ADDR   0x60

MM_ERROR_CODE_ENUM OV2640SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

#endif

