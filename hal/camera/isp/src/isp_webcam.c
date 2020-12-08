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
*   cal_main.c
*
* Project:
* --------
*   All
*
* Description:
* ------------
*   CAL interface
*
* Author:
* -------
 * -------
*
****************************************************************************/
#include "kal_release.h"
#include "cal_api.h"
#include "cal_if.h"

#include "mm_intmem.h"

#include "isp_comm_def.h"

#include "isp_if.h"
#include "isp_comm_if.h"
#include "isp_hw_feature_def.h"
#include "usbvideo_custom.h"

#include "aaa_process.h"
#include "aaa_ae.h"
#include "aaa_awb.h"

#ifdef WEBCAM_SUPPORT

kal_uint32 IspMainWebcamAttrValues[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX)];
kal_uint32 IspSubWebcamAttrValues[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX)];
kal_uint32 *pIspWebcamAttrValues = IspMainWebcamAttrValues;

//kal_uint32 usbvideo_attr_setting_CT_index=0;
kal_uint32 IspWebcamAttrSettingIndex;
const usbvideo_attr_struct IspWebcamAttrPara=
{/* min,  max,  res,  def */
    {
        {0   ,4   ,1   ,0   },/*0  USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION*/
        {0   ,255 ,1   ,128 },/*1  USBVIDEO_ATTRIBUTE_BRIGHTNESS*/
        {0   ,255 ,1   ,64  },/*2  USBVIDEO_ATTRIBUTE_CONTRAST*/
        {0   ,255 ,1   ,127 },/*3  USBVIDEO_ATTRIBUTE_GAIN*/
        {0   ,2   ,1   ,1   },/*4  USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, 0:Disable, 1:50, 2:60*/
        {0   ,360 ,1   ,0   },/*5  USBVIDEO_ATTRIBUTE_HUE*/
        {0   ,255 ,1   ,64  },/*6  USBVIDEO_ATTRIBUTE_SATURATION*/
        {0   ,15  ,1   ,0   },/*7  USBVIDEO_ATTRIBUTE_SHARPNESS*/
        {100 ,220 ,60  ,160 },/*8  USBVIDEO_ATTRIBUTE_GAMMA*/
        {2500,6500,500 ,5500},/*9 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP*/
        {0   ,1   ,1   ,1   },/*10 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO*/
        {0   ,0   ,0   ,0   },/*11 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP, NOT SUPPORT*/
        {0   ,1   ,1   ,1   },/*12 USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP_AUTO*/
        {0   ,0   ,1   ,0   },/*13 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER, NOT SUPPORT*/
        {0   ,0   ,1   ,0   },/*14 USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER_LIMIT, NOT SUPPORT*/
        {0   ,1   ,1   ,0   },/*15 USBVIDEO_ATTRIBUTE_HUE_AUTO*/
        {0   ,0   ,0   ,0   }/*16 USBVIDEO_ATTRIBUTE_MAX_MULTIPLIER, NOT SUPPORT*/
    }
};
const kal_uint8 IspWebcamGammaAttr[3][20]=
{
    {2, 4, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 192, 208, 224, 240},
    {6, 12, 24, 48, 61, 73, 83, 93, 102, 111, 126, 141, 155, 169, 181, 192, 215, 225, 235, 245},
    {9, 18, 37, 73, 87, 100, 110, 120, 128, 136, 150, 164, 175, 186, 196, 206, 224, 232, 240, 248}
};


void IspWebcamInit()
{
    kal_uint32 i;
    kal_uint32 OutParaLen;

    if(pIspWebcamAttrValues[9] == 0)     ///color temp should not be 0
    {
        if(ISP_YUV_SUPPORT == IspInputDataFormat)          ///For YUV sensor
        {
            USBVideo_Attr_Value attr;

            attr.req_type = USBVIDEO_REQUEST_GET_DEF;
            attr.subtype = 0;

            for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)      
            {
                attr.type = (USBVIDEO_ATTRIBUTE_TYPE)(ATTR_PU_START+i);
                CustomDriverFunc.SensorFeatureCtrl(CAL_FEATURE_WEBCAM_GET_ATTR, NULL, &attr, sizeof(USBVideo_Attr_Value), &OutParaLen);
                pIspWebcamAttrValues[i] = attr.value;
            }
        }
    }
}


MM_ERROR_CODE_ENUM IspWebcamFeatureCtrl(kal_uint32 FeatureId, void *pIspParaIn,
                                        void *pIspParaOut, kal_uint16 IspParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 OutParaLen;

    switch (FeatureId)
    {
    case CAL_FEATURE_WEBCAM_GET_ATTR:
        {
            USBVideo_Attr_Value *pWebCamAttr = (USBVideo_Attr_Value *)pIspParaOut;
            USBVIDEO_ATTRIBUTE_TYPE AttrType = pWebCamAttr->type;

            if(AttrType<=USBVIDEO_ATTRIBUTE_CT_MAX)
            {
                pWebCamAttr->value = 0;    ///CT currently is not support
            }
            else
            {
                if (AttrType >= ATTR_PU_START)
                {
                    if(ISP_YUV_SUPPORT == IspInputDataFormat)    
                    {
                        ///for YUV sensor
                        switch(pWebCamAttr->req_type)
                        {
                        case USBVIDEO_REQUEST_GET_CUR:
                            pWebCamAttr->value = pIspWebcamAttrValues[GET_ATTR_PU_IDX(AttrType)];
                            break;
                        case USBVIDEO_REQUEST_GET_MIN:
                        case USBVIDEO_REQUEST_GET_MAX:
                        case USBVIDEO_REQUEST_GET_DEF:
                        case USBVIDEO_REQUEST_GET_RES:
                            ErrorCode = CustomDriverFunc.SensorFeatureCtrl(CAL_FEATURE_WEBCAM_GET_ATTR, NULL, pWebCamAttr, sizeof(USBVideo_Attr_Value), &OutParaLen);
                            break;
                        default:
                            ASSERT(0);
                            break;
                        }
                    }
                }
                else
                {
                    ASSERT(0);
                }
            }
        }
        break;

    case CAL_FEATURE_WEBCAM_SET_ATTR:
        {
            USBVideo_Attr_Value *pWebCamAttr = (USBVideo_Attr_Value *)pIspParaIn;
            USBVIDEO_ATTRIBUTE_TYPE AttrType = pWebCamAttr->type;

            if(AttrType<=USBVIDEO_ATTRIBUTE_CT_MAX)
            {
                ///CT currently is not support
            }
            else
            {
                if (AttrType >= ATTR_PU_START)
                {
                    kal_uint32 save_irq_mask;

                    save_irq_mask=SaveAndSetIRQMask();  
                    pIspWebcamAttrValues[GET_ATTR_PU_IDX(AttrType)] = pWebCamAttr->value;
                    if(AttrType == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)
                    {
                        if(pWebCamAttr->value == 0)  ///MAUNAL WB
                            IspWebcamAttrSettingIndex |= 1 << GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP); //need to update temp setting
                        else                         ///AUTO AWB
                            IspWebcamAttrSettingIndex |= 1 << GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO);                      
                    } 
                    else if(AttrType == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)
                    {
                        if(pIspWebcamAttrValues[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)] == 0)  ///MAUNAL WB
                            IspWebcamAttrSettingIndex |= 1 << GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP); //need to update temp setting
                    } 
                    else
                    {
                        IspWebcamAttrSettingIndex |= 1 << GET_ATTR_PU_IDX(AttrType);  
                    }
                    RestoreIRQMask(save_irq_mask);
                }
                else
                {
                    ASSERT(0);
                }
            }
        }
        break;

    default:
        ASSERT(0);
        break;
    }
    return ErrorCode;
}


void IspWebcamUpdateAttrSetting()
{
    kal_uint32 i;
    for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)
    {
        if(ISP_RAW_SUPPORT == IspInputDataFormat)          ///only For RAW sensor, ISP attributes
            IspWebcamAttrSettingIndex |= (1<<i);
    }
}


void IspWebcamYuvBackgroundSettingAttr()
{
    kal_uint32 i;
    USBVideo_Attr_Value AttrValue;

    AttrValue.req_type = USBVIDEO_REQUEST_INIT;
    AttrValue.subtype = 0;

    // No update
    if(IspWebcamAttrSettingIndex==0)
        return;

    for (i=0;i<GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_PU_MAX);i++)
    {
        if (IspWebcamAttrSettingIndex & (1<<i))
        {
            AttrValue.value= pIspWebcamAttrValues[i];
            AttrValue.type = (USBVIDEO_ATTRIBUTE_TYPE)(ATTR_PU_START+i);

            CustomDriverFunc.SensorFeatureCtrl(CAL_FEATURE_WEBCAM_SET_ATTR, &AttrValue, NULL, 0, NULL);
            IspWebcamAttrSettingIndex &=~(1<<i);
        }
    }
}


void IspWebcamBackgroundSettingAttr()
{
    if(ISP_YUV_SUPPORT == IspInputDataFormat)          ///For RAW sensor
    {
        IspWebcamYuvBackgroundSettingAttr();
    }
}


MM_ERROR_CODE_ENUM IspWebcam(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,
                             void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_ISP_CAMERA_STILL_CAPTURE_STRUCT pIspCapturePara=(P_ISP_CAMERA_STILL_CAPTURE_STRUCT)pCtrlPara;
#if defined(MIPI_SENSOR_SUPPORT)    
    static kal_bool   MipiInterfaceEnableFlag = KAL_FALSE;
#endif

    if (CAL_CTRL_CODE_STOP & CtrlCode)      ///STOP ISP
    {
        /* stop isp engine */
        IspStopInput(IspOperationState);
    }
    else if (CAL_CTRL_CODE_INIT & CtrlCode)   ///First config ISP
    {
        ASSERT(IspOperationState == ISP_STANDBY_STATE);

    #if defined(MIPI_SENSOR_SUPPORT)
        if ((IMAGE_SENSOR_IF_MIPI == SensorInfo1.SensorIf) && (KAL_FALSE == MipiInterfaceEnableFlag))
        { 
            IMAGE_SENSOR_MIPI_PARA_IN_STRUCT MipiParaIn;

            MipiParaIn.ScenarioMode = CAL_SCENARIO_CAMERA_PREVIEW;
            MipiParaIn.NightModeEnable = KAL_FALSE;
            MipiParaIn.DigitalZoomFactor = 100; //temporary solution
            MipiParaIn.TargetWidth = IspGlobalInfo.TargetWidth;
            MipiParaIn.TargetHeight = IspGlobalInfo.TargetHeight;        
            MipiInterfaceEnable(KAL_TRUE, &MipiParaIn);
            MipiInterfaceEnableFlag = KAL_TRUE;
        }
    #endif    

        /// save capture config data
        kal_mem_cpy(&IspCaptureConfigData, pIspCapturePara, sizeof(ISP_CAMERA_STILL_CAPTURE_STRUCT));

        //reset_raw_cal_error_handling();
        IspOperationState = ISP_PREVIEW_WEBCAM_STATE;

        /* drop few unstable frames while changing sensor setting */
        IspWaitCaptureDelayFrame();                 ///because CRZ disconnect can not work, therefore before this can not trigger MDP

        /* update attr */
        IspWebcamUpdateAttrSetting();  
        IspWebcamBackgroundSettingAttr();
        
    }
    else if (CAL_CTRL_CODE_START & CtrlCode)
    {
        IspOperationState = ISP_CAPTURE_WEBCAM_STATE;
    #if defined(MIPI_SENSOR_SUPPORT)
        if ((IMAGE_SENSOR_IF_MIPI == SensorInfo1.SensorIf) && (KAL_FALSE == MipiInterfaceEnableFlag))
        { 
            IMAGE_SENSOR_MIPI_PARA_IN_STRUCT MipiParaIn;

            MipiParaIn.ScenarioMode = CAL_SCENARIO_CAMERA_PREVIEW;
            MipiParaIn.NightModeEnable = KAL_FALSE;
            MipiParaIn.DigitalZoomFactor = 100; //temporary solution
            MipiParaIn.TargetWidth = IspGlobalInfo.TargetWidth;
            MipiParaIn.TargetHeight = IspGlobalInfo.TargetHeight;        
            MipiInterfaceEnable(KAL_TRUE, &MipiParaIn);
            MipiInterfaceEnableFlag = KAL_TRUE;
        }
    #endif    
        IspStartInput(IspOperationState);
    }
    else if (CAL_CTRL_CODE_DEINIT & CtrlCode)       ///Deinit to release working memory
    {
    #if defined(MIPI_SENSOR_SUPPORT)
        if (IMAGE_SENSOR_IF_MIPI==SensorInfo1.SensorIf)
        {   
            MipiInterfaceEnable(KAL_FALSE, NULL);
            MipiInterfaceEnableFlag = KAL_FALSE;

        }
    #endif

        /* update isp operation state */
        IspOperationState=ISP_STANDBY_STATE;

        /* stop 3a algorithm */
        ///        AaaConfigExitPreview();    
    }

    return ErrorCode;
}

#else

void IspWebcamInit()
{
    return;
}

void IspWebcamBackgroundSettingAttr()
{
    return;
}

MM_ERROR_CODE_ENUM IspWebcamFeatureCtrl(kal_uint32 FeatureId, void *pIspParaIn,
                                        void *pIspParaOut, kal_uint16 IspParaOutLen)
{
    return MM_ERROR_NONE;
}

MM_ERROR_CODE_ENUM IspWebcam(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,void *pCtrlPara, kal_uint16 CtrlParaLen)
{   
    return MM_ERROR_NONE;
}
#endif  ///#ifdef WEBCAM_SUPPORT

