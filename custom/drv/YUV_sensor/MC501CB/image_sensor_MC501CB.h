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
 *   image_sensor.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _IMAGE_SENSOR_MC501CB_H
#define _IMAGE_SENSOR_MC501CB_H

#include "sensor_comm_def.h"
//#define __IMAGE_SENSOR_03M__  // VGA
// #define __IMAGE_SENSOR_1M__   // 1.3M
// #define __IMAGE_SENSOR_2M__   // 2M
// #define __IMAGE_SENSOR_3M__   // 3M
// #define __IMAGE_SENSOR_5M__   // 5M
// #define __IMAGE_SENSOR_8M__   // 8M

/* API FOR ENGINEER FACTORY MODE */
void MC501CB_get_sensor_group_count(kal_int32 *sensor_count_ptr);
void MC501CB_get_sensor_group_info(kal_uint16 group_idx, kal_int8 *group_name_ptr, kal_int32 *item_count_ptr);
void MC501CB_get_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT *info_ptr);
kal_bool MC501CB_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value);


/* ------------------------Engineer mode--------------------------------- */
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES)||defined(DRV_ISP_6276_SERIES)))	
#if (!(defined(__CAMERA_NVRAM_REDUCTION__) && defined(DRV_ISP_6225_SERIES)))


#define MC501CB_FACTORY_START_ADDR 70

typedef enum MC501CB_group_enum {
    MC501CB_AWB_GAIN = 0,
    MC501CB_PRE_GAIN,
    MC501CB_SENSOR_DBLC,
    MC501CB_GAMMA_ENABLE,
    MC501CB_CMMCLK_CURRENT,
    MC501CB_FRAME_RATE_LIMITATION,
    MC501CB_REGISTER_EDITOR,
    MC501CB_GROUP_TOTAL_NUMS
} MC501CB_FACTORY_CCT_GROUP_ENUM;

typedef enum MC501CB_register_index {
    MC501CB_AWB_GAIN_R_INDEX = MC501CB_FACTORY_START_ADDR,
    MC501CB_AWB_GAIN_B_INDEX,
    MC501CB_SENSOR_DBLC_INDEX,
    MC501CB_GAMMA_ENABLE_INDEX,
    MC501CB_CMMCLK_CURRENT_INDEX,
    MC501CB_FACTORY_END_ADDR
} MC501CB_FACTORY_REGISTER_INDEX;

typedef enum MC501CB_cct_register_index {
    MC501CB_GLOBAL_GAIN_INDEX = 0,
    MC501CB_PRE_GAIN_R_INDEX,
    MC501CB_PRE_GAIN_B_INDEX,
    MC501CB_CCT_END_ADDR
} MC501CB_CCT_REGISTER_INDEX;


/* ------------------------Engineer mode--------------------------------- */
typedef struct {
    sensor_reg_struct reg[MC501CB_FACTORY_END_ADDR];
    sensor_reg_struct cct[MC501CB_CCT_END_ADDR];
} sensor_data_struct;
#endif
#endif



#if (!(defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6276_SERIES)))
/* AE CONTROL CRITERION */
extern kal_uint8    AE_AWB_CAL_PERIOD;
extern kal_uint8    AE_GAIN_DELAY_PERIOD;
extern kal_uint8    AE_SHUTTER_DELAY_PERIOD;
#endif

/* DEFINITION USED BY CCT */
//extern SensorInfo   g_CCT_MainSensor;
//extern kal_uint8    g_CCT_FirstGrabColor;

/* CAMERA PREVIEW FRAME RATE DEFINITION */
#define MC501CB_CAM_PREVIEW_15FPS
//#define CAM_PREVIEW_22FPS
//#define CAM_PREVIEW_30FPS

#define MC501CB_SYSTEM_CLK                          (48*1000*1000)

/* PIXEL CLOCK USED BY BANDING FILTER CACULATION */
#if defined(MC501CB_CAM_PREVIEW_15FPS)
    #define MC501CB_PIXEL_CLK                       (MC501CB_SYSTEM_CLK/8)     /* 52/8 MHz */
#elif defined(MC501CB_CAM_PREVIEW_22FPS)
    #define MC501CB_PIXEL_CLK                       (MC501CB_SYSTEM_CLK/6)     /* 52/6 MHz */
#elif defined(MC501CB_CAM_PREVIEW_30FPS)
    #define MC501CB_PIXEL_CLK                       (MC501CB_SYSTEM_CLK/4)     /* 52/4 MHz */
#endif

/* MAX/MIN FRAME RATE (FRAMES PER SEC.) */
#define MC501CB_MAX_FRAME_RATE                      15 /* Limitation for MPEG4 Encode Only */
#define MC501CB_MIN_FRAME_RATE                      12

#define MC501CB_MAX_PREVIEW_FRAME_RATE_30				//For max preview frame rate 30fps
//#define MC501CB_MAX_PREVIEW_PRAME_RATE_20			//For max preview frame rate 20fps

/* LINE NUMBERS IN MAX_FRAME_RATE */
#define MC501CB_MIN_LINES_PER_FRAME                 ((MC501CB_SYSTEM_CLK/8/MC501CB_MAX_FRAME_RATE)/MC501CB_VGA_PERIOD_PIXEL_NUMS)

/* SENSOR GLOBAL GAIN AT NIGHT MODE */
#define MC501CB_SENSOR_NIGHT_MODE_GAIN              0x08        /* Please refer to OV7660 Implementation Guide for suitable value. */

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define MC501CB_VGA_PERIOD_PIXEL_NUMS               656         /* 656 */
#define MC501CB_VGA_PERIOD_LINE_NUMS                496         /* 496 */

#ifdef MC501CB_MAX_PREVIEW_FRAME_RATE_30
#define MC501CB_VGA_DEFAULT_H_BLANK					158
#define MC501CB_VGA_DEFAULT_V_BLANK					55
#else
#define MC501CB_VGA_DEFAULT_H_BLANK					158
#define MC501CB_VGA_DEFAULT_V_BLANK					51
#endif

#define MC501CB_PAGE_0								0x00
#define MC501CB_PAGE_1								0x01
#define MC501CB_PAGE_2								0x02
#define MC501CB_PAGE_3								0x03

#define MC501CB_MAX_H_BLANK							5000
#define MC501CB_MAX_V_BLANK							2000

#define MC501CB_PV_PERIOD_PIXEL_NUMS		(MC501CB_VGA_PERIOD_PIXEL_NUMS + MC501CB_VGA_DEFAULT_H_BLANK)
#define MC501CB_PV_PERIOD_LINE_NUMS			(MC501CB_VGA_PERIOD_LINE_NUMS + MC501CB_VGA_DEFAULT_V_BLANK)

#define MC501CB_CAP_PERIOD_PIXEL_NUMS		(MC501CB_VGA_PERIOD_PIXEL_NUMS + MC501CB_VGA_DEFAULT_H_BLANK)
#define MC501CB_CAP_PERIOD_LINE_NUMS		(MC501CB_VGA_PERIOD_LINE_NUMS + MC501CB_VGA_DEFAULT_V_BLANK)


/* SENSOR EXPOSURE LINE LIMITATION */
#define MC501CB_VGA_EXPOSURE_LIMITATION             400         /* 510 //509//508 */

/* 1M RESOLUTION SIZE */
#define MC501CB_IMAGE_SENSOR_1M_WIDTH               1280
#define MC501CB_IMAGE_SENSOR_1M_HEIGHT              960

/* SENSOR VGA SIZE */
#define MC501CB_IMAGE_SENSOR_VGA_WIDTH              640
#define MC501CB_IMAGE_SENSOR_VGA_HEIGHT             480

#define MC501CB_IMAGE_SENSOR_PV_WIDTH				(640 - 16)
#define MC501CB_IMAGE_SENSOR_PV_HEIGHT				(480 - 16)

#define MC501CB_IMAGE_SENSOR_FULL_WIDTH			(640 - 16)
#define MC501CB_IMAGE_SENSOR_FULL_HEIGHT			(480 - 16)


//#define IMAGE_SENSOR_FULL_WIDTH              640
//#define IMAGE_SENSOR_FULL_HEIGHT             480

/* SETUP TIME NEED TO BE INSERTED */
#define MC501CB_IMAGE_SENSOR_VGA_INSERTED_PIXELS    128         /* 56//(0) */
#define MC501CB_IMAGE_SENSOR_VGA_INSERTED_LINES     17          /* (1) */

/* SENSOR READ/WRITE ID */
#define MC501CB_WRITE_ID                   0xc4
#define MC501CB_READ_ID                    0xc5

/* SENSOR CHIP VERSION */
//#define MC501CB_SENSOR_ID                  0xAB
#if defined(MCU_245_76M) //Wonder 
	#define MC501CB_SENSOR_I2C_DELAY                0xFF
    #define MC501CB_SENSOR_I2C_DELAY_T8             0xA00
#elif defined(MCU_208M)
	#define MC501CB_SENSOR_I2C_DELAY                0xA0
    #define MC501CB_SENSOR_I2C_DELAY_T8             0xFF
#elif defined(MCU_104M)
    #define MC501CB_SENSOR_I2C_DELAY                0x40
    #define MC501CB_SENSOR_I2C_DELAY_T8             0x800
#else
    #define MC501CB_SENSOR_I2C_DELAY                0x20
    #define MC501CB_SENSOR_I2C_DELAY_T8             0x400
#endif

#define MC501CB_SCCB_SLAVE_ADDR			(0xc4)
#define MC501CB_SCCB_FAST_MODE_SPEED			(300)		//The speed of sccb fast mode(Kb)


MM_ERROR_CODE_ENUM MC501CBSensorClose(void);


MM_ERROR_CODE_ENUM MC501CBSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

MM_ERROR_CODE_ENUM MC501CBWebcamFeatureCtrl(kal_uint32 FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);



#endif /* _IMAGE_SENSOR_MC501CB_H */

