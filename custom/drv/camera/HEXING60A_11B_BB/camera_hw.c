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
 *   camera_hw.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Image sensor hardware and power control
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================
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
 * removed!
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================
 ****************************************************************************/

#if defined(ISP_SUPPORT)

#include "dcl.h"
#include "sensor_comm_def.h"
#include "isp_comm_def.h"
#include "image_sensor.h"
#include "camera_sccb.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

extern const char gpio_camera_reset_pin;
extern const char gpio_camera_cmpdn_pin;

#define CAMERA_MAIN_RST_PIN   		gpio_camera_reset_pin
#define CAMERA_MAIN_PDN_PIN   		gpio_camera_cmpdn_pin
#define CAMERA_SUB_RST_PIN    		-1 /* -1: indicate not support */
#define CAMERA_SUB_PDN_PIN    		-1 /* -1: indicate not support */

//extern const char gpio_flashlight_en_pin;

#define FLASHLIGHT_EN_PIN   -		1 /* -1: indicate not support */

#if (defined(AF_SUPPORT))
	extern const char gpio_af_enable_pin;

	#define CAMERA_AF_PDN_PIN   	gpio_af_enable_pin /* -1: indicate not support */
#endif

	#define CAM_SCCB_SCL_MODE 			(1)//(4)
	#define CAM_SCCB_SDA_MODE 			(1)//(3)

	#define CAM_SCCB_SW_I2C_DELAY		(0xA0)



void CamDclPMU_Enable(PMU_LDO_BUCK_LIST_ENUM VCamera, PMU_VOLTAGE_ENUM Voltage)
{
	DCL_HANDLE Handle = DCL_HANDLE_INVALID;
	PMU_CTRL_LDO_BUCK_SET_EN PmuEn;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE PmuVol;

	Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	PmuVol.voltage = Voltage;
	PmuVol.mod = VCamera;
	DclPMU_Control(Handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&PmuVol);
	
	PmuEn.enable = DCL_TRUE;
	PmuEn.mod = VCamera;
	DclPMU_Control(Handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&PmuEn);

	DclPMU_Close(Handle);
}

void CamDclPMU_Disable(PMU_LDO_BUCK_LIST_ENUM VCamera)
{
	DCL_HANDLE Handle = DCL_HANDLE_INVALID;
	PMU_CTRL_LDO_BUCK_SET_EN PmuEn;

	Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	PmuEn.enable 	= DCL_FALSE;
	PmuEn.mod 		= VCamera;
	DclPMU_Control(Handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&PmuEn);

	DclPMU_Close(Handle);
}


/*************************************************************************
* FUNCTION
*    CameraPinCtrl
*
* DESCRIPTION
*    this function contrl camera pin high or low
*
* PARAMETERS
*    Pin: gpio pin, -1: just return
*    Data: 0: low, 1: high, -1: just return
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void CameraPinCtrl(kal_int16 Pin, kal_int8 Data)
{
  if (Pin != -1 && Data != -1)
  {
    const DCL_HANDLE Handle = DclGPIO_Open(DCL_GPIO, Pin);
    
    DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Control(Handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Control(Handle, Data ? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(Handle);
  }
}

/*************************************************************************
* FUNCTION
*    CamRstPinCtrl
*
* DESCRIPTION
*    this function contrl camera reset pin high or low
*
* PARAMETERS
*    Idx: IMAGE_SENSOR_MAIN or IMAGE_SENSOR_SUB
*    Data: 0: low, 1: high
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data)
{
	switch (Idx)
	{
		case IMAGE_SENSOR_MAIN:
		case IMAGE_SENSOR_BAK1:
			CameraPinCtrl(CAMERA_MAIN_RST_PIN, Data);
	#if 0 // Removed
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
			break;
#if (defined(DUAL_CAMERA_SUPPORT))
		case IMAGE_SENSOR_SUB:
		case IMAGE_SENSOR_SUB_BAK1:
			CameraPinCtrl(CAMERA_SUB_RST_PIN, Data);
			break;
#endif
	}
}


/*************************************************************************
* FUNCTION
*    CamPdnPinCtrl
*
* DESCRIPTION
*    this function contrl camera power down pin high or low
*
* PARAMETERS
*    Idx: IMAGE_SENSOR_MAIN or IMAGE_SENSOR_SUB
*    Data: 0: low, 1: high
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data)
{
	 switch (Idx)
	{
		case IMAGE_SENSOR_MAIN:
		case IMAGE_SENSOR_BAK1:
			CameraPinCtrl(CAMERA_MAIN_PDN_PIN, Data);
			break;
#if (defined(DUAL_CAMERA_SUPPORT))
		case IMAGE_SENSOR_SUB:
		case IMAGE_SENSOR_SUB_BAK1:
			CameraPinCtrl(CAMERA_SUB_PDN_PIN, Data);
			break;
#endif
	}

}


/*************************************************************************
* FUNCTION
*    CamGetHWInfo
*
* DESCRIPTION
*    this function get current HW configuration
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CamGetHWInfo(IMAGE_SENSOR_INDEX_ENUM Idx, P_IMAGE_SENSOR_HW_DEPENDENT_STRUCT Info)
{
	Info->DataPinConnection = DATA_PIN_CONNECT_BIT7_0; /*[Hesong 0303] For MT6250/6252,data pin fixed*/
	switch (Idx)
	{
	case IMAGE_SENSOR_MAIN:
	case IMAGE_SENSOR_BAK1:
		Info->IspDrivingCurrent = ISP_DRIVING_8MA;
		break;
#if (defined(DUAL_CAMERA_SUPPORT))
	case IMAGE_SENSOR_SUB:
	case IMAGE_SENSOR_SUB_BAK1:
		Info->IspDrivingCurrent = ISP_DRIVING_4MA;
		break;
#endif
	}
}


// Compact Image Sensor Module Power ON/OFF
#if (defined(__SERIAL_SENSOR_V1_SUPPORT__) && defined(__MTK_TARGET__))
extern IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT CurrentSensorInfo;
#endif
void CisModulePowerOn(IMAGE_SENSOR_INDEX_ENUM SensorIdx, kal_bool On)
{
	if(On == KAL_TRUE)
	{
		{
		#if (defined(__ATV_SUPPORT__))
			#if (!(defined(MT6223P) || defined(MT6223) || defined(__DIRECT_SENSOR_V2_SUPPORT__)))
				extern kal_bool matvdrv_ps_init(kal_bool on);
				//matvdrv_ps_init(KAL_TRUE);
			#endif
		#endif	/* #if (defined(__ATV_SUPPORT__)) */
		}

		#if (defined(__SERIAL_SENSOR_V1_SUPPORT__) && defined(__MTK_TARGET__))
		if (CurrentSensorInfo.SensorIf == IMAGE_SENSOR_IF_SERIAL)
		{
			GPIO_ModeSetup(47, 2);
			GPIO_ModeSetup(48, 2);
			GPIO_ModeSetup(59, 2);
		}
		else
		{
			GPIO_ModeSetup(47, 1);
			GPIO_ModeSetup(48, 1);
			GPIO_ModeSetup(59, 1);
		}
		#endif
	
		CameraSccbInit(CAMERA_HW_SCCB, CAM_SCCB_SCL_MODE, CAM_SCCB_SDA_MODE, CAM_SCCB_SW_I2C_DELAY);

		CamDclPMU_Enable(VCAMD, PMU_VOLT_02_800000_V);	/* PMU Enable VCAM_D, 2.8V */ /*camera interface fix 2.8V. DOVDD= 2.8,DVDD = 1.5 (LDO)*/
		CamDclPMU_Enable(VCAMA, PMU_VOLT_02_800000_V);	/* PMU Enable VCAM_A, 2.8V */
	}
	else
	{
		CamDclPMU_Disable(VCAMD);		/* PMU Disable VCAM_D, 2.8V */
		CamDclPMU_Disable(VCAMA);		/* PMU Disable VCAM_A, 2.8V */

		/* output low to avoid electric leakage */
		CamPdnPinCtrl(IMAGE_SENSOR_MAIN, 1);
		CamRstPinCtrl(IMAGE_SENSOR_MAIN, 0);
	#if (defined(DUAL_CAMERA_SUPPORT))
		CamPdnPinCtrl(IMAGE_SENSOR_SUB, 0);
		CamRstPinCtrl(IMAGE_SENSOR_SUB, 0);
	#endif

		{
		#if (defined(__ATV_SUPPORT__))
			#if (!(defined(MT6223P) || defined(MT6223) || defined(__DIRECT_SENSOR_V2_SUPPORT__)))
				extern kal_bool matvdrv_ps_init(kal_bool on);
				//matvdrv_ps_init(KAL_FALSE);
			#else
				extern kal_bool matvdrv_ps_init(kal_bool on);
				//matvdrv_ps_init(KAL_TRUE);
			#endif
		#endif	/* #if (defined(__ATV_SUPPORT__)) */
		}
	}
}

void FlashlightPowerOn(IMAGE_SENSOR_INDEX_ENUM Idx, kal_bool On)
{
	if (On)
	{
		CameraPinCtrl(FLASHLIGHT_EN_PIN, (kal_uint8)On);
	}
	else
	{
		CameraPinCtrl(FLASHLIGHT_EN_PIN, (kal_uint8)On);
	}
}

#if (defined(AF_SUPPORT))
void LensAfPowerOn(IMAGE_SENSOR_INDEX_ENUM Idx, kal_bool On)
{
	if (On)
	{
		CameraPinCtrl(CAMERA_AF_PDN_PIN, (kal_uint8)On);
	}
	else
	{
		CameraPinCtrl(CAMERA_AF_PDN_PIN, (kal_uint8)On);
	}
}
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif
