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
 *   isp_flashlight_if.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for flashlight Interface.
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
 ****************************************************************************/
#ifndef _ISP_FLASHLIGHT_V2_H
#define _ISP_FLASHLIGHT_V2_H

#include "drv_features.h" 
#include "isp_hw_feature_def.h"

#include "mm_comm_def.h"

#define MAX_TIME_FLASH_LNUNIT (10082)  /*2^20/104MHz = 10082(us)*/
#define FLASH_CLK (104) /*MHz*/
#define FLASH_READ_MIN_SHUTTER_FRAME (1)
#define FLASH_READ_PREFLASH_FRAME (2)


typedef struct
{
	kal_bool		enable_shutter_tansfer;	/* capture only */
	kal_uint16	capture_shutter;			/* capture only */
	kal_bool		enable_flashlight_tansfer;	/* flash light capture only */	
	kal_uint16	flashlight_duty;				/* flash light capture only */	
	kal_uint16	flashlight_offset;			/* flash light capture only */		
	kal_uint32      flashlight_min_shutter;    /*minimum shutter for common exposure zone*/
}FLASHLIGHT_INFO_WITH_SENSOR_STRUCT, *P_FLASHLIGHT_INFO_WITH_SENSOR_STRUCT;


typedef enum
{
	FLASHLIGHT_STANDBY_STATE=0,
	FLASHLIGHT_CHARGE_STATE,        // XENON FLASHLIGHT ONLY	
	FLASHLIGHT_READY_STATE,		    // XENON FLASHLIGHT ONLY
	FLASHLIGHT_RECHARGE_STATE,		// XENON FLASHLIGHT ONLY	
	FLASHLIGHT_PRE_STROBE_STATE,		
	FLASHLIGHT_PRE_STROBE_DONE_STATE,			
	FLASHLIGHT_TRIGGER_STATE,		
	FLASHLIGHT_TRIGGER_DONE_STATE,
	FLASHLIGHT_MAIN_STROBE_STATE	
} FLASHLIGHT_OPERATION_STATE_ENUM;

extern FLASHLIGHT_INFO_WITH_SENSOR_STRUCT FlashlightInfo;
extern FLASHLIGHT_OPERATION_STATE_ENUM FlashlightOperationState;
extern kal_uint16	AwbRgainBak,AwbGRgainBak,AwbBgainBak,AwbGBgainBak;
extern kal_bool MainFlashFrameFlag;
extern kal_uint8 FlashAfResult;
extern kal_uint8 CdtFlashFlag;

typedef struct 
{
    kal_bool flashTrigFlag;
    kal_bool flashRedeyeTrigFlag;
}flash_trig_struct, FLASH_TRIGGER_STRUCT, *P_FLASH_TRIGGER_STRUCT;

flash_trig_struct *FlashGetTrigStatus(void);
void FlashConfig(kal_uint16 start_line,  kal_uint32 duty_time);
void InitFlashlight(void);
void FlashlightPreProcess(void);
void FlashlightPostProcess(void);
kal_bool FlashlightRedeyeProcess(kal_uint32  capture_delay_frame);
void FlashlightTriggerProcess(void);
#if(!defined(LED_FLASHLIGHT_SUPPORT))
void FlashlightStopProcess(void);
#endif
void FlashlightHisr(void);

void FlashlightPreStrobe(kal_uint8 shutter_delay_frame);
void FlashlightPostStrobe(void);
kal_bool FlashlightRedeye(kal_uint32  capture_delay_frame);
void FlashlightTrigger(void);


#if(defined(LED_FLASHLIGHT_SUPPORT))
void FlashlightPostStrobeStop(void);
void FlashlightTriggerStop(void);
void FlashlightStopProcess(MULTISHOT_INFO_ENUM snapshot_number);
#endif

typedef enum
{
    FLASHLIGHT_NONE = 0,
	FLASHLIGHT_LED_ONOFF,           // LED always on/off
	FLASHLIGHT_LED_CONSTANT,	    // CONSTANT type LED
}	FLASHLIGHT_TYPE;

/////////////For YUV LED flashlight//////////////////////
typedef struct
{
    FLASHLIGHT_TYPE FlashlightType;
}FLASHLIGHT_HW_INFO_STRUCT, *P_FLASHLIGHT_HW_INFO_STRUCT;
////////////////////////////////////////////////////

// Interface for customize sensor driver
typedef struct 
{
    kal_uint32  pixels;             // Sensor active pixel number
    kal_uint32  lines;              // Sensor active line number
    kal_uint32  frame_lines;   //valid+dummy lines for minimum shutter
} flashlight_preview_para_struct, FLASHLIGHT_PREVIEW_PARA_STURCT, *P_FLASHLIGHT_PREVIEW_PARA_STURCT;
typedef struct 
{
    kal_uint32  default_pclk;       // Sensor pixel clock(Ex:24000000)
    kal_uint32  pixels;             // Sensor active pixel number
    kal_uint32  lines;              // Sensor active line number
    kal_uint32  shutter;            // Sensor current shutter
    kal_uint32  frame_lines;      //valid+dummy lines for minimum shutter
} flashlight_capture_para_struct, FLASHLIGHT_CAPTURE_PARA_STRUCT, *P_FLASHLIGHT_CAPTURE_PARA_STRUCT;
typedef struct
{
    CAL_RAW_CAPTURE_MODE_ENUM CaptureScenario;  // for Raw sensor only
    kal_uint32 DigitalZoomFactor;
}FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT, *P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT;

extern FLASHLIGHT_PREVIEW_PARA_STURCT FlashightPreviewPara;
extern FLASHLIGHT_CAPTURE_PARA_STRUCT FlashlightCapturePara;

kal_uint16 XenonTriggerDurationEfficiency(kal_uint16 required_duration);
kal_uint16 XenonTriggerDurationInverse(kal_uint16 required_duration);
void FlashlightSensorPreviewConfig( flashlight_preview_para_struct *para, FLASHLIGHT_INFO_WITH_SENSOR_STRUCT *sensor_config_data);
kal_uint32 FlashlightSensorCaptureConfig(   flashlight_capture_para_struct *para,  FLASHLIGHT_INFO_WITH_SENSOR_STRUCT *sensor_config_data);
////////////YUV FLASHLIGHT SUPPORT//////////////////
#define FLASHLIGHT_NULL_MODE         0x0
#define FLASHLIGHT_PULSE_MODE        0x1        ///LED1&2
#define FLASHLIGHT_CONTINUOUS_MODE   0x2        ///LED3 or GPIO control

void IspYuvFlashlightConfig(P_ISP_FEATURE_CONFIG_3A_BEFORE_CAPTURE_STRUCT pIspPara);
void IspYuvFlashlightPrestrobeProcess(void);
void IspYuvFlashlightRedeyeStrobeProcess(void);
void IspYuvFlashlightMainStrobeProcess(kal_bool On);
void IspYuvFlashlightRestore3AProcess(void);

//////////////END//////////////////////////


#endif /* _ISP_FLASHLIGHT_H */

