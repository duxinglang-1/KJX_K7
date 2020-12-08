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
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor header file
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
#ifndef _IMAGE_SENSOR_SIV120B_DIRECT_H
#define _IMAGE_SENSOR_SIV120B_DIRECT_H

#include "isp_if.h"
#include "drv_features.h"
#include "sensor_struct.h"

typedef enum SIV120B_DIRECT_OutPutFormat_group_enum{
	SIV120B_DIRECT_QCIF_FORMAT = 0,
	SIV120B_DIRECT_QVGA_FORMAT,
	SIV120B_DIRECT_CIF_FORMAT,
	SIV120B_DIRECT_VGA_FORMAT
}SIV120B_DIRECT_OUTPUT_SIZE;

typedef enum SensorDriving {
SENSOR_LEVEL0 = 0,
SENSOR_LEVEL1,
SENSOR_LEVEL2,         
SENSOR_LEVEL3       
};

//------------------------Engineer mode---------------------------------
#if (!(defined(DRV_ISP_6238_SERIES) ||defined(DRV_ISP_6235_SERIES) ))
#if (!(defined(__CAMERA_NVRAM_REDUCTION__) && defined(DRV_ISP_6225_SERIES)))
#define SIV120B_DIRECT_FACTORY_START_ADDR (70)

typedef enum SIV120B_DIRECT_group_enum {
    SIV120B_DIRECT_AWB_GAIN = 0,
    SIV120B_DIRECT_PRE_GAIN,
    SIV120B_DIRECT_SENSOR_DBLC,
    SIV120B_DIRECT_GAMMA_ENABLE,
    SIV120B_DIRECT_CMMCLK_CURRENT,
    SIV120B_DIRECT_FRAME_RATE_LIMITATION,
    SIV120B_DIRECT_REGISTER_EDITOR,
    SIV120B_DIRECT_GROUP_TOTAL_NUMS
} SIV120B_DIRECT_FACTORY_CCT_GROUP_ENUM;

typedef enum SIV120B_DIRECT_register_index {
   SIV120B_DIRECT_AWB_GAIN_R_INDEX=SIV120B_DIRECT_FACTORY_START_ADDR,
   SIV120B_DIRECT_AWB_GAIN_B_INDEX,
   SIV120B_DIRECT_SENSOR_DBLC_INDEX,
   SIV120B_DIRECT_GAMMA_ENABLE_INDEX,
   SIV120B_DIRECT_CMMCLK_CURRENT_INDEX,
   SIV120B_DIRECT_FACTORY_END_ADDR
} SIV120B_DIRECT_FACTORY_REGISTER_INDEX;

typedef enum SIV120B_DIRECT_cct_register_index {
   SIV120B_DIRECT_GLOBAL_GAIN_INDEX = 0,
   SIV120B_DIRECT_PRE_GAIN_R_INDEX,
   SIV120B_DIRECT_PRE_GAIN_B_INDEX,
   SIV120B_DIRECT_CCT_END_ADDR
} SIV120B_DIRECT_CCT_REGISTER_INDEX; 

typedef struct {
	sensor_reg_struct reg[SIV120B_DIRECT_FACTORY_END_ADDR];
	sensor_reg_struct cct[SIV120B_DIRECT_CCT_END_ADDR];
} sensor_data_struct;
#endif
#endif	

// Prototypes FOR ENGINEER FACTORY MODE
void  SIV120B_DIRECT_get_sensor_group_count(kal_int32* sensor_count_ptr);
void  SIV120B_DIRECT_get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr);
void  SIV120B_DIRECT_get_sensor_item_info(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr);
kal_bool SIV120B_DIRECT_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value);

//------------------------Engineer mode---------------------------------
// write camera_para to sensor register 
void SIV120B_DIRECT_camera_para_to_sensor(void);
// update camera_para from sensor register 
void SIV120B_DIRECT_sensor_to_camera_para(void);
// config sensor callback function 
void SIV120B_DIRECT_image_sensor_func_config(void);
// detect sensor id
kal_uint32 SIV120B_DIRECT_detect_sensor_id(void);

void SIV120B_DIRECT_get_sensor_prefix_name(kal_char* buf);
void  SIV120B_DIRECT_dispatch_camera_info(void);
kal_uint32 SIV120B_DIRECT_get_valid_camera_type(void);


/* MAXIMUM EXPLOSURE LINES USED BY AE */
extern kal_uint16 SIV120B_DIRECT_MAX_EXPOSURE_LINES;   // must be defined but not referenced by YUV driver
extern kal_uint8  SIV120B_DIRECT_MIN_EXPOSURE_LINES;   // must be defined but not referenced by YUV driver

#if (defined(SIV120B_DIRECT_YUV_MAIN)||defined(SIV120B_DIRECT_YUV_BAK1))
// BB's reset pin high low control MACROs
#define SIV120B_DIRECT_RESET_PIN_LOW   (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT)
#define SIV120B_DIRECT_RESET_PIN_HIGH  (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT)

#define SIV120B_DIRECT_PWRDN_PIN_LOW           (REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT)
#define SIV120B_DIRECT_PWRDN_PIN_HIGH          (REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_POWER_ON_BIT)
#else
#define SIV120B_DIRECT_RESET_PIN_LOW   
#define SIV120B_DIRECT_RESET_PIN_HIGH  

#define SIV120B_DIRECT_PWRDN_PIN_LOW   
#define SIV120B_DIRECT_PWRDN_PIN_HIGH  
#endif

// sensor's chip ID and version
#define SIV120B_DIRECT_SENSOR_VERSION              (0x11)

// sensor's I2C read/write IDs    
#define SIV120B_DIRECT_I2C_WRITE_ID                (0x66)
#define SIV120B_DIRECT_I2C_READ_ID                 (0x67)
   
//#define SIV120B_DIRECT_HW_SCCB /* if no define, means use SW SCCB */
    
#ifndef SIV120B_DIRECT_HW_SCCB
    /* I2C FAIL TRY NUMBER */
#define SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO     5
    
    /* SENSOR I2C DELAY*/
#define SIV120B_DIRECT_SENSOR_I2C_DELAY        0xE0
    
#define SIV120B_DIRECT_I2C_START_TRANSMISSION \
    { \
        volatile kal_uint32 j; \
        SET_SCCB_CLK_OUTPUT; \
        SET_SCCB_DATA_OUTPUT; \
        SET_SCCB_DATA_HIGH; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
        SET_SCCB_CLK_HIGH; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
        SET_SCCB_DATA_LOW; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
        SET_SCCB_CLK_LOW; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
    }
    
#define SIV120B_DIRECT_I2C_STOP_TRANSMISSION \
    { \
        volatile kal_uint32 j; \
        SET_SCCB_CLK_OUTPUT; \
        SET_SCCB_DATA_OUTPUT; \
        SET_SCCB_CLK_LOW; \
        SET_SCCB_DATA_LOW; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
        SET_SCCB_CLK_HIGH; \
        for (j = SIV120B_DIRECT_SENSOR_I2C_DELAY; j > 0; j--); \
        SET_SCCB_DATA_HIGH; \
    }
#endif

#define SIV120B_DIRECT_PERIOD_PIXEL_NUMS_VGA      (652 + 144 + 3)/* Active + HST + 3 */  //hunk
#define SIV120B_DIRECT_PERIOD_LINE_NUMS_VGA      (490 + 9)/* Active + 9 *///hunk

#define SIV120B_DIRECT_PERIOD_PIXEL_NUMS_QVGA      (652 + 144 + 3)/* Active + HST + 3 */  //hunk
#define SIV120B_DIRECT_PERIOD_LINE_NUMS_QVGA       (258 + 9 )// (240 + 9 + 13 + 5)/* Active + 13 *///hunk

#define SIV120B_DIRECT_PERIOD_PIXEL_NUMS_CIF      (364 + 144 + 3)/* Active + HST + 3 *///hunk
#define SIV120B_DIRECT_PERIOD_LINE_NUMS_CIF      (300 + 9)/* Active + 9 *///hunk

#define SIV120B_DIRECT_PERIOD_PIXEL_NUMS_QCIF      (364 + 144 + 3)/* Active + HST + 3 *///hunk
#define SIV120B_DIRECT_PERIOD_LINE_NUMS_QCIF      (144 + 9)/* Active + 9 *///hunk



/* sensor size */
#define SIV120B_DIRECT_IMAGE_SENSOR_QCIF_WIDTH			(176)
#define SIV120B_DIRECT_IMAGE_SENSOR_QCIF_HEIGHT               (144)

#define SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH			(320)
#define SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT              (240)

#define SIV120B_DIRECT_IMAGE_SENSOR_VGA_WIDTH                  (640)
#define SIV120B_DIRECT_IMAGE_SENSOR_VGA_HEIGHT                 (480)

#define SIV120B_DIRECT_IMAGE_SENSOR_SXGA_WITDH                (1280) 
#define SIV120B_DIRECT_IMAGE_SENSOR_SXGA_HEIGHT               (1024)

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
static kal_uint16 SIV120B_DIRECT_PERIOD_PIXEL_NUMS  = SIV120B_DIRECT_PERIOD_PIXEL_NUMS_VGA;/* Active + HST + 3 *///hunk
static kal_uint16 SIV120B_DIRECT_PERIOD_LINE_NUMS   = SIV120B_DIRECT_PERIOD_LINE_NUMS_VGA;      /* Active + 9 *///hunk

#define SIV120B_DIRECT_BLANK_REGISTER_LIMITATION   0xFFF

/*50Hz,60Hz*/
#define SIV120B_DIRECT_NUM_50HZ    50 * 2
#define SIV120B_DIRECT_NUM_60HZ    60 * 2

/* FRAME RATE UNIT */
#define SIV120B_DIRECT_FRAME_RATE_UNIT               10

#define BANK_SETTING_REG				(0x00)

/* MAX CAMERA FRAME RATE */
#if !defined(MT6225)
#define SIV120B_DIRECT_MAX_CAMERA_FPS         (SIV120B_DIRECT_FRAME_RATE_UNIT * 15)
#else
#define SIV120B_DIRECT_MAX_CAMERA_FPS         (SIV120B_DIRECT_FRAME_RATE_UNIT * 15)
#endif

extern MM_ERROR_CODE_ENUM SIV120B_DIRECT_set_interface_info(kal_uint8 *para_in);
extern MM_ERROR_CODE_ENUM SIV120B_DIRECT_get_interface_info(kal_uint8 *para_out);
#endif 
