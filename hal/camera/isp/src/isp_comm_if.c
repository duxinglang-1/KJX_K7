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
 *   isp_comm_if.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   ISP contorl flow for camera scenario
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"

#include "isp_comm_def.h"
#include "sensor_comm_def.h"
#include "cal_comm_def.h"

#include "isp_if.h"

#include "isp_pca.h" //PCA related 
#include "isp_comm_if.h"
#include "camera_tuning_para.h"
#include "aaa_awb.h"    

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif


CameraDriverOperationParaStruct CameraDriverOperParaBuffer;


void CameraDriverDefaultOperationPara(CameraDriverOperationParaStruct *p_oper_data)
{
    p_oper_data->yuv_af_timeout_frame = 20;
}


void CameraTuningDefaultOperationPara(CameraTuningOperationParaStruct *p_oper_data)
{
}


void CameraDriverCheckOperationPara(CameraDriverOperationParaStruct *p_oper_data)
{
    /* To protect invalide value */
    if(p_oper_data->capture_delay_frame > 3)
    {
        p_oper_data->capture_delay_frame=2;
    }
    /* To protect invalide value */
    if((p_oper_data->preview_delay_frame > 16) || (p_oper_data->preview_delay_frame == 0))
    {
        p_oper_data->preview_delay_frame = 2;
    }

#ifdef LED_FLASHLIGHT_SUPPORT
    if(p_oper_data->flashlight_prestrobe_frame == 0)
            p_oper_data->flashlight_prestrobe_frame = 8;

    if(p_oper_data->flashlight_prestrobe_to_redeyestrobe_delay_frame == 0)
            p_oper_data->flashlight_prestrobe_to_redeyestrobe_delay_frame = 2;

    if(p_oper_data->flashlight_redeyestrobe_frame == 0)
            p_oper_data->flashlight_redeyestrobe_frame = 2;

    if(p_oper_data->flashlight_mainstrobe_frame == 0)
            p_oper_data->flashlight_mainstrobe_frame = 2;
#endif
}


void CameraTuningCheckOperationPara(CameraTuningOperationParaStruct *p_oper_data)
{
}


void CameraInitOperationPara(void)
{
    // for camera HAL UT
    IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT CameraInitOperationPara;
    // for camera HAL UT
    register CameraDriverOperationParaStruct *p_driver_para = &CameraDriverOperParaBuffer;
    CameraDriverDefaultOperationPara(p_driver_para);
    //  marked for camera HAL UT
    //  CameraDriverInitOperationPara(p_driver_para);
    CustomDriverFunc.SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA, NULL, &CameraInitOperationPara,
                                       sizeof(IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT), &SensorFeatureParaOutLen);

    p_driver_para->capture_delay_frame =CameraInitOperationPara.CaptureDelayFrame;
    p_driver_para->preview_delay_frame =CameraInitOperationPara.PreviewDelayFrame;
    p_driver_para->preview_display_wait_frame =CameraInitOperationPara.PreviewDisplayWaitFrame;

#ifdef LED_FLASHLIGHT_SUPPORT
    ///For YUV LED Flashlight control
    p_driver_para->flashlight_prestrobe_frame = CameraInitOperationPara.FlashlightPrestrobeFrame;
    p_driver_para->flashlight_prestrobe_to_redeyestrobe_delay_frame = CameraInitOperationPara.FlashlightPrestrobeToRedeyeFrame;
    p_driver_para->flashlight_redeyestrobe_frame = CameraInitOperationPara.FlashlightRedeyeStrobeFrame;
    p_driver_para->flashlight_mainstrobe_frame = CameraInitOperationPara.FlashlightMainStrobeDelayFrame;
#endif

    CameraDriverCheckOperationPara(p_driver_para);

}


#if (defined(__ATV_SUPPORT__)&& defined(__MTK_TARGET__))
void MatvInitOperationPara(void)
{
    // for camera HAL UT
    IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT CameraInitOperationPara;
    // for camera HAL UT
    register CameraDriverOperationParaStruct *p_driver_para = &CameraDriverOperParaBuffer;
    CameraDriverDefaultOperationPara(p_driver_para);
    //  marked for camera HAL UT
    //  CameraDriverInitOperationPara(p_driver_para);
    CustomDriverFunc.SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA, NULL, &CameraInitOperationPara,
                                       sizeof(IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT), &SensorFeatureParaOutLen);

    p_driver_para->capture_delay_frame =CameraInitOperationPara.CaptureDelayFrame;
    p_driver_para->preview_delay_frame =CameraInitOperationPara.PreviewDelayFrame;
    p_driver_para->preview_display_wait_frame =CameraInitOperationPara.PreviewDisplayWaitFrame;

    CameraDriverCheckOperationPara(p_driver_para);

}
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

