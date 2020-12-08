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
 *   image_sensor_S5K5CAGA.h
 *
 * Project:
 * --------
 *   MAUI_sw
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 * Author: Qihao Geng (mtk70548)
 *   
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_S5K5CAGA_H
    #define _IMAGE_SENSOR_S5K5CAGA_H

    #include "sensor_comm_def.h"
    #include "isp_nvram.h"

    //#define S5K5CAGA_LOAD_FROM_T_FLASH

    #define __S5K5CAGA_DEBUG_TRACE__

    // The active sate of STBYN is determined by the TST pin, TST pin state is sampled for STANDBY polarity when RSTN goes high.
	// TST:0, STBYN is active low
	// TST:1, STBYN is active high.
	//#define S5K5CAGA_TST_PIN_HIGH 

    #define S5K5CAGA_CAM_NOM_MAX_FPS				300		// 30fps
	#define S5K5CAGA_CAM_NOM_MIN_FPS				100		// 10fps
	#define S5K5CAGA_CAM_NIT_MAX_FPS				300		// 30fps
	#define S5K5CAGA_CAM_NIT_MIN_FPS				50		// 5.0fps


/* SENSOR FULL/PV SIZE */
#define S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH_DRV   (2048)
#define S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT_DRV  (1536)

#define S5K5CAGA_IMAGE_SENSOR_PV_WIDTH_DRV     (800)
#define S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT_DRV    (600)

/* SENSOR START/END POSITION */
#define S5K5CAGA_PV_X_START                    (0)
#define S5K5CAGA_PV_Y_START                    (1)
#define S5K5CAGA_IMAGE_SENSOR_PV_WIDTH         (S5K5CAGA_IMAGE_SENSOR_PV_WIDTH_DRV)
#define S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT        (S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT_DRV) 
#define S5K5CAGA_FULL_X_START                  (0)
#define S5K5CAGA_FULL_Y_START                  (1)
#define S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH       (S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH_DRV)
#define S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT      (S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT_DRV)

///////////////////////////////////////////////////////////////////////////////
//					Notices: Please don't modify the macro below this line
///////////////////////////////////////////////////////////////////////////////


// Msec / 10 is the actual frame time, 1000 means 100ms.
#define S5K5CAGA_CAM_NOM_MIN_FR_TIME			((1000 * 10 * 10) / S5K5CAGA_CAM_NOM_MAX_FPS)
#define S5K5CAGA_CAM_NOM_MAX_FR_TIME			((1000 * 10 * 10) / S5K5CAGA_CAM_NOM_MIN_FPS)
#define S5K5CAGA_CAM_NIT_MIN_FR_TIME			((1000 * 10 * 10) / S5K5CAGA_CAM_NIT_MAX_FPS)
#define S5K5CAGA_CAM_NIT_MAX_FR_TIME			((1000 * 10 * 10) / S5K5CAGA_CAM_NIT_MIN_FPS)


/* 50HZ/60HZ */
#define S5K5CAGA_NUM_50HZ                      50
#define S5K5CAGA_NUM_60HZ                      60

/* SENSOR LIMITATION */
#define S5K5CAGA_SHUTTER_MAX_MARGIN            5
#define S5K5CAGA_MAX_LINELENGTH                0x1000 /* register limitation */

/* SENSOR READ/WRITE ID */

#define S5K5CAGA_WRITE_ID					   0x78 //0x5A		
#define S5K5CAGA_READ_ID					   0x79 //0x5B

#define S5K5CAGA_WRITE_ID_1                    0x5A //0x78
#define S5K5CAGA_READ_ID_2                     0x5B //0x79

/* FRAME RATE UNIT */
#define S5K5CAGA_FPS(x)                        ((kal_uint32)(10 * (x)))

// Reminder: Just can un-mask one macro of these 2 macros. if mask these 2 macros, then use mclk 24Mhz, pclk 48Mhz 
// for preview & capture

//#define S5K5CAGA_JPEG_MCLK24M_PCLK36M 	
#define S5K5CAGA_JPEG_MCLK24M_PCLK40M		

#define S5K5CAGA_PV_BEST_FRAME_RATE_BINNING
#define S5K5CAGA_CAM_MAX_FPS                   (300)

#define S5K5CAGA_VID_FIX_FR_TIME(fPS)       ((1000 * 10 * 10) /(fPS))

#define S5K5CAGA_CAM_MIN_FR_TIME           ((1000*10*10)/S5K5CAGA_CAM_MAX_FPS)


/* Define the YUV Capture PCLK and Frame Rate.  */

#define S5K5CAGA_YUV_CAP_PCLK_60Mhz_8fps
//#define S5K5CAGA_YUV_CAP_PCLK_86Mhz_12fps
//#define S5K5CAGA_YUV_CAP_PCLK_96Mhz_14fps

#ifdef S5K5CAGA_LOAD_FROM_T_FLASH

	typedef struct
	{
		kal_uint16 init_reg;
		kal_uint16 init_val;	/* Save the register value and delay tick */
		kal_uint8 op_code;		/* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
	} S5K5CAGA_initial_set_struct;
	
	#define S5K5CAGA_REG_SKIP		0x08
	#define S5K5CAGA_VAL_SKIP		0x08
	

	/* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
	#define S5K5CAGA_OP_CODE_INI		0x00		/* Initial value. */
	#define S5K5CAGA_OP_CODE_REG		0x01		/* Register */
	#define S5K5CAGA_OP_CODE_DLY		0x02		/* Delay */
	#define S5K5CAGA_OP_CODE_END		0x03		
#endif

static struct
{
    kal_uint16 SensorId;
    
    kal_uint16 Contrast;
    kal_uint16 Saturation;
    kal_uint16 Sharpness;
    kal_uint16 Effect;
    kal_uint16 Exposure;
    kal_uint16 Wb;
    kal_uint8 Mirror;
    kal_bool BypassAe;
    kal_bool BypassAwb;
    kal_bool NightMode;
    kal_bool VideoMode;
    kal_bool PvMode;
    kal_bool FirstPv;

    kal_bool OutTestPattern;      /* It can used to verify the HW. */

    kal_uint16 Fps;
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
    sensor_data_struct *NvramData;
} S5K5CAGASensor;


/* frame rate please refer to preview function */

/* --------------------------------- common eara --------------------------------- */
/* EXPORT FUNC */
MM_ERROR_CODE_ENUM S5K5CAGASensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

/* IMPORT FUNC */
MM_ERROR_CODE_ENUM S5K5CAGAWebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);

#ifdef __S5K5CAGA_DEBUG_TRACE__
	#define S5K5CAGA_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[S5K5CAGA]"__VA_ARGS__)
#else
	#define S5K5CAGA_TRACE(...)
#endif  /* #ifdef __S5K5CAGA_DEBUG_TRACE__ */

#endif  /* #ifndef _IMAGE_SENSOR_S5K5CAGA_H */
