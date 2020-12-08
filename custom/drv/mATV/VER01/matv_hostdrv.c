/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   matv_hostdrv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   implement atv function just like sensor
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================

 *****************************************************************************
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__ATV_SUPPORT__)
#if defined(MT6250)|| defined(MT6260)
#undef __SERIAL_SENSOR_V1_SUPPORT__
#endif

#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
//#include "gpio_sw.h"
#include "dcl.h"
#include "kal_release.h"
#include "matv_hostdrv.h"
#include "isp_comm_if.h"
#include "upll_ctrl.h"
#include "med_api.h"
#include "matvctrl.h"
#include "hostlib.h"
#include "camera_sccb.h"

#include "lcd_if_manager.h"
#ifndef  _MATV_NOT_REF_MCLK_
  #define _MATV_NOT_REF_MCLK_
#endif

extern void ATV_sccb_write(kal_uint32 addr, kal_uint32 para);
extern kal_uint16 ATV_sccb_read(kal_uint16 addr);
extern kal_uint8 matv_get_customization_frame_rate(void);
extern void ATVSccbInit (void);
extern void MatvGetHWInfo(P_IMAGE_SENSOR_HW_DEPENDENT_STRUCT Info);
extern void lcd_power_ctrl(kal_bool enable);

extern void matv_kal_take_sem(void);
extern void matv_kal_give_sem(void);

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
void ATV_sccb_multi_write(kal_uint8 dev,kal_uint32 addr, kal_uint16 num,kal_uint8 *param)
{
	kal_uint32 i;
//	   volatile kal_uint32 j;  
	   for(i=0;i<num;i++,param++)
	   {
//		ATV_sccb_write((addr&0xFF), (*param));
		 MatvWriteCmosSensor((addr&0xFF), (*param));
	   // addr++;
		}

}	

kal_uint32 ATV_sccb_multi_read(kal_uint8 dev,kal_uint32 addr,kal_uint8 num,kal_uint8 *param)
{
      kal_uint32 i;
//	volatile kal_uint32 j;	
	for(i=0;i<num;i++,param++)
	{
     //*param = ATV_sccb_read((addr&0xFF));
	 *param = MatvReadCmosSensor((addr&0xFF));
	 
	// addr++;
	}
	return num;
}	

kal_bool bIsI2CInit = KAL_FALSE;	
/*************************************************************************
* FUNCTION
*	init_ATV
*
* DESCRIPTION
*	This function initialize the registers of CMOS sensor and ISP control register.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void ATV_i2c_init(void)
{
  	if(bIsI2CInit)
         return;
	ATVSccbInit();

	#if defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260)
	{
		CameraSccbOpen(CAMERA_SCCB_MATV, ATV_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 400);
	}
	#else
	    CameraSccbOpen(CAMERA_SCCB_MATV, ATV_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 200);
	#endif
	bIsI2CInit = KAL_TRUE;
}
void ATV_i2c_deinit(void)
{
	CameraSccbClose(CAMERA_SCCB_MATV);
	 bIsI2CInit = KAL_FALSE;
}

extern kal_semid 	matv_sem_id;
/*************************************************************************
* FUNCTION
*	ATV_night_mode
*
* DESCRIPTION
*	This function night mode of ATV.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void mATV_night_mode(kal_bool enable)
{ 

}	/* ATV_night_mode */



void mATV_CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{

} /* mATV_CameraParaToSensor() */

// update camera_para from sensor register
void mATV_SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{

} /* mATV_SensorToCameraPara() */

void mATV_GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=mATV_SENSOR_ID;
  //  pSensorInfo->ResetActiveHigh=KAL_FALSE;
 //   pSensorInfo->PowerOnActiveHigh=KAL_FALSE;
    #if defined(__SERIAL_SENSOR_V1_SUPPORT__)
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_SERIAL;
    #else
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_PARALLEL;
    #endif
	pSensorInfo->PixelClkInv = KAL_FALSE;
    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    #if defined(__SERIAL_SENSOR_V1_SUPPORT__)
    pSensorInfo->VsyncPolarity=POLARITY_LOW;
    #else
    pSensorInfo->VsyncPolarity=POLARITY_HIGH;
    #endif
 //   pSensorInfo->DrivingCurrent=ISP_DRIVING_8MA;
    pSensorInfo->PreviewMclkFreq = 0;
    pSensorInfo->CaptureMclkFreq = 0;
    pSensorInfo->VideoMclkFreq = 0;
    pSensorInfo->PreviewWidth=ATV_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->PreviewHeight=ATV_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->FullWidth=ATV_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=ATV_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* mATV_GetSensorInfo() */
//#if 0
static kal_uint16 mATV_PowerOn(void)
{

//	volatile signed char i,j;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return mATV_SENSOR_ID;
} /* mATV_PowerOn() */
//#endif

//kal_uint32 mATV_DetectSensorId(void)
//{
//    return mATV_SENSOR_ID;
//}   /* mATV_DetectSensorId() */

MM_ERROR_CODE_ENUM mATV_SensorOpen(void)
{


//    if (mATV_PowerOn()!= mATV_SENSOR_ID)
//        return MM_ERROR_SENSOR_READ_ID_FAIL;
    return MM_ERROR_NONE;
} /* mATV_SensorOpen() */

kal_uint16 mATV_get_NTSC_Framerate(kal_uint16 framerateIn)
{
    kal_uint16 return_value=ATV_15FPS;
	if(framerateIn > 200)
	{
        return_value = ATV_30FPS;
	}
    else if(framerateIn > 150)
    {
       return_value = ATV_20FPS;
	}
	/*else
	{
        return_value = ATV_15FPS;
	}*/
	return return_value;
}
/*****************************************************************************
 * FUNCTION
 *	matv_get_LCM_WriteCycle
 * DESCRIPTION
 *	get LCM Write cycle for matv hopping table
 * PARAMETERS
 *	0
 * RETURNS
  *	LCM Writecycle:  unit:  1T(for example if LCD IF Clock is 52MHZ, 1T = 19.2ns)
 *****************************************************************************/  
kal_uint16 matv_get_LCM_WriteCycle(void)
{
kal_uint16 lcm_write_cycle;
#if (defined(MT6253E) || defined(MT6253L)||defined(MT6253) || defined(MT6253D)  || defined(MT6253T) || defined(MT6252) || defined(MT6252H) || defined(MT6258) || defined(MT6258H))
kal_uint32 main_lcd_if_handle;
LCD_IOCTRL_LCD_SETTING_T main_lcd_setting; 
LCD_IOCTRL_RESULT_E result;
main_lcd_if_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_MATV); 
lcm_write_cycle = 0xffff;

lcd_power_ctrl(KAL_TRUE);
result = lcd_ioctrl_device_if_settings(main_lcd_if_handle, LCD_IOCTRL_QUERY_MAIN_LCD_IF, &main_lcd_setting, sizeof(LCD_IOCTRL_LCD_SETTING_T)); 
lcd_power_ctrl(KAL_FALSE);
if(result != LCD_IOCTRL_OK)
{
//   lcm_write_cycle = 0xffff;
}
else
{
  if(main_lcd_setting.lcd_if_setting.if_type == LCD_IF_TYPE_DBI_PARALLEL)
  {
       kal_uint8 tempCycle = main_lcd_setting.lcd_if_setting.if_settings.dbi_parallel_if.if_total_write_cycles; // mostly lcm write cycle shouldn't more than 255
       kal_uint8 magicBit = 0;  // platform bit
#if (defined(MT6253) || defined(MT6253D)  || defined(MT6253T))
       magicBit = 0;
#elif (defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) || defined(MT6258) || defined(MT6258H))
       magicBit = 1;
#endif
lcm_write_cycle = (magicBit<<8)|(tempCycle&0xff);
  }
  else
  {
  //     lcm_write_cycle = 0xffff;
  }
}

#else
 lcm_write_cycle = 0xffff;
#endif
  return lcm_write_cycle;
}

static void mATV_Preview_Capture_Setting(CAL_SCENARIO_ENUM ScenarioId,
								   P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
								   P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)

{
	kal_uint32 IsCaptureMode = 0;
		  kal_wap_trace(MOD_MATV, TRACE_INFO, "mATV_Preview\n");

	matv_kal_take_sem();
	
	pParaOut->GrabStartX=ATV_IMAGE_SENSOR_PV_INSERTED_PIXELS;
	pParaOut->GrabStartY=ATV_IMAGE_SENSOR_PV_INSERTED_LINES;
	pParaOut->ExposureWindowWidth=ATV_IMAGE_SENSOR_FULL_WIDTH;
	pParaOut->ExposureWindowHeight=ATV_IMAGE_SENSOR_FULL_HEIGHT;

	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
	if (ScenarioId==CAL_SCENARIO_CAMERA_STILL_CAPTURE)
	{
		DrvSetChipDep(MTK_TVD_CamIFCaptureMode,1);
	}
	else
	{
		if(0 == matv_get_customization_frame_rate()) // it means use default frame rate
			DrvSetChipDep(MTK_TVD_MaxFrameRate, (mATV_get_NTSC_Framerate(pParaIn->MaxVideoFrameRate)));
		else
		   DrvSetChipDep(MTK_TVD_MaxFrameRate, (matv_get_customization_frame_rate()));
		DrvSetChipDep(MTK_TVD_CamIFCaptureMode,0);
	}
	#endif
	
	
	DrvSetChipDep(MTK_TVD_CamIFResolution,(( pParaOut->ExposureWindowWidth)<<16)|pParaOut->ExposureWindowHeight);
	matv_kal_give_sem();

}
static void mATV_Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	  pParaOut->GrabStartX=ATV_IMAGE_SENSOR_PV_INSERTED_PIXELS;
	  pParaOut->GrabStartY=ATV_IMAGE_SENSOR_PV_INSERTED_LINES;
	  pParaOut->ExposureWindowWidth=ATV_IMAGE_SENSOR_FULL_WIDTH;
	  pParaOut->ExposureWindowHeight=ATV_IMAGE_SENSOR_FULL_HEIGHT;
	  kal_wap_trace(MOD_MATV, TRACE_INFO, "mATV_Preview\n");
	  


        matv_kal_take_sem();
		if(0 == matv_get_customization_frame_rate()) // it means use default frame rate
        DrvSetChipDep(MTK_TVD_MaxFrameRate, (mATV_get_NTSC_Framerate(pParaIn->MaxVideoFrameRate)));
        else
		   DrvSetChipDep(MTK_TVD_MaxFrameRate, (matv_get_customization_frame_rate()));
		DrvSetChipDep(MTK_TVD_CamIFCaptureMode,0);
		DrvSetChipDep(MTK_TVD_CamIFResolution,(( pParaOut->ExposureWindowWidth)<<16)|pParaOut->ExposureWindowHeight);
		matv_kal_give_sem();


}/* mATV_Preview */

static void mATV_Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{


	  pParaOut->GrabStartX=ATV_IMAGE_SENSOR_PV_INSERTED_PIXELS;
	  pParaOut->GrabStartY=ATV_IMAGE_SENSOR_PV_INSERTED_LINES;
	  pParaOut->ExposureWindowWidth=ATV_IMAGE_SENSOR_FULL_WIDTH;
	  pParaOut->ExposureWindowHeight=ATV_IMAGE_SENSOR_FULL_HEIGHT;
		matv_kal_take_sem();
		DrvSetChipDep(MTK_TVD_CamIFCaptureMode,1);
		DrvSetChipDep(MTK_TVD_CamIFResolution,(( pParaOut->ExposureWindowWidth)<<16)|pParaOut->ExposureWindowHeight);
		matv_kal_give_sem();
} /* mATV_Capture() */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//void mATV_InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
//{
//	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
//	pInitOperPara->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
//	pInitOperPara->PreviewDisplayWaitFrame = 2;	/* wait stable frame when sensor change mode (cap to pre) */

//} /* mATV_InitOperationPara() */

//void mATV_DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
//{

//} /* mATV_DscSupportInfo() */

// for YUV sensor sample code
//MM_ERROR_CODE_ENUM mATV_Sharpness(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
//                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
//                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
//{

//    return MM_ERROR_NONE;
//}   /* mATV_Sharpness() */


MM_ERROR_CODE_ENUM mATV_SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

//    if ((FeatureId>=CAL_FEATURE_WEBCAM_BEGIN)&&
//        (FeatureId<=CAL_FEATURE_WEBCAM_END))
//    {
//        ErrorCode = MM_ERROR_INVALID_PARAMETER;
//        return ErrorCode;
//    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {

        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            mATV_GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=mATV_SENSOR_ID;//mATV_DetectSensorId();
        break;
//        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
         //   CameraSource_mATV = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        //break;
//        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
        //    mATV_night_mode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
//        break;

        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
			if(0 == matv_get_customization_frame_rate())
			 ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			else
             ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue = matv_get_customization_frame_rate();
        break;

        // customized by customer
//        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
        //    ErrorCode=mATV_StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
        //                                 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        //break;
        // for YUV sensor sample code
        // the following are for YUV sensor only
//        case CAL_FEATURE_CAMERA_SHARPNESS:
        // please refer the sample code of mATV_Sharpness();
        //    ErrorCode=mATV_Sharpness((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
        //                                   (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        //break;
//        case CAL_FEATURE_CAMERA_EV_VALUE:
//        case CAL_FEATURE_CAMERA_BANDING_FREQ:
//        case CAL_FEATURE_CAMERA_WB:
//        case CAL_FEATURE_CAMERA_HUE:
//        case CAL_FEATURE_CAMERA_BRIGHTNESS:
//        case CAL_FEATURE_CAMERA_CONTRAST:
//        case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
//        case CAL_FEATURE_CAMERA_SATURATION:
//        break;
//        case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
//        case CAL_FEATURE_CAMERA_FLASH_MODE:
            // These features are supported in YUV sensor only.
            // Put here just for notifying DD colleagues. Should be removed later for MT9P012. PC Huang 20100903
//            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
//        break;
        // the above are for YUV sensor only

        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            //mATV_InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);

	((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut)->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut)->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
	((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut)->PreviewDisplayWaitFrame = 2;	/* wait stable frame when sensor change mode (cap to pre) */
			
        break;
        //case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            //mATV_DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        //break;
//        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            //pNvramSensorData_mATV = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
//        break;
		case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
            MatvGetHWInfo(pFeatureParaOut);
         break;
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* mATV_SensorFeatureCtrl() */

MM_ERROR_CODE_ENUM mATV_SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint32 ParaOutLen, kal_uint32 *pRealParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_VIDEO:
            mATV_Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            mATV_Capture(ScenarioId, pParaIn, pParaOut);
		//mATV_Preview_Capture_Setting(ScenarioId, pParaIn, pParaOut);
		break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM mATV_SensorClose(void)
{
	//cis_module_power_on(KAL_FALSE);      // Power Off CIS Power
#ifdef ATV_USE_48MHZ
	UPLL_Disable(UPLL_OWNER_ISP);
#endif
    return MM_ERROR_NONE;
}


IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFunc_mATV=
{
    mATV_SensorOpen,
    mATV_SensorFeatureCtrl,
    mATV_SensorCtrl,
    mATV_SensorClose,
};

MM_ERROR_CODE_ENUM mATV_SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFunc_mATV;
    return MM_ERROR_NONE;
}	/* cam_module_func_config() */
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
#endif /* __MTK_TARGET__ && __ATV_SUPPORT__ */
