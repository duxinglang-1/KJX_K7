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
 *   camera_sensor_para.c
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Camera Operation Parameter for sensor driver related.
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
 * removed!
 * removed!
 *
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"

#if (defined(DRV_ISP_6238_SERIES))


#include "camera_para.h"
#include "isp_flashlight.h"
#include "med_api.h"
#include "camera_info_SIV120B_DIRECT.h"
	



void SIV120B_DIRECT_CameraDriverInitOperationPara(CameraDriverOperationParaStruct *p_oper_data)
{
    p_oper_data->capture_delay_frame = 1;   /* wait stable frame when sensor change mode (pre to cap) */
    p_oper_data->preview_delay_frame = 3;   /* wait stable frame when sensor change mode (cap to pre) */

}

void SIV120B_DIRECT_get_capture_mode_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 4;
    p_info->support_item[0] = CAM_MODE_NORMAL;
    p_info->support_item[1] = CAM_MODE_CONT_SHOT;
    p_info->support_item[2] = CAM_MODE_BURST_SHOT;
    p_info->support_item[3] = CAM_MODE_ADD_FRAME;
}

void SIV120B_DIRECT_get_camera_scene_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_AUTO_DSC;
    p_info->support_item[1] = CAM_NIGHTSCENE;
}

void SIV120B_DIRECT_get_capture_size_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
#if (defined(__YUVCAM_INTERPOLATION_SW__)||defined(__YUVCAM_INTERPOLATION_HW__))
	p_info->item_count = 3;
	p_info->support_item[0] = CAM_SIZE_WALLPAPER;
	p_info->support_item[1] = CAM_SIZE_VGA;
	p_info->support_item[2] = CAM_SIZE_1M;
#else
	p_info->item_count = 2;
	p_info->support_item[0] = CAM_SIZE_WALLPAPER;
	p_info->support_item[1] = CAM_SIZE_VGA;
#endif
}

void SIV120B_DIRECT_get_flashlight_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_af_range_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;	
}

void SIV120B_DIRECT_get_iso_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_binning_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_wb_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 6;
    p_info->support_item[0] = CAM_WB_AUTO;
    p_info->support_item[1] = CAM_WB_CLOUD;
    p_info->support_item[2] = CAM_WB_DAYLIGHT;
    p_info->support_item[3] = CAM_WB_INCANDESCENCE;
    p_info->support_item[4] = CAM_WB_TUNGSTEN;
    p_info->support_item[5] = CAM_WB_FLUORESCENT;
}

void SIV120B_DIRECT_get_effect_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 8;
    p_info->support_item[0] = CAM_EFFECT_ENC_NORMAL; 
    p_info->support_item[1] = CAM_EFFECT_ENC_GRAYSCALE;
    p_info->support_item[2] = CAM_EFFECT_ENC_SEPIA;
    p_info->support_item[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    p_info->support_item[4] = CAM_EFFECT_ENC_SEPIABLUE;
    p_info->support_item[5] = CAM_EFFECT_ENC_COLORINV;
    p_info->support_item[6] = CAM_EFFECT_ENC_GRAYINV;    
    p_info->support_item[7] = CAM_EFFECT_ENC_EMBOSSMENT;
}

void SIV120B_DIRECT_get_af_mode_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_ae_meter_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_sharpness_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_contrast_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_saturation_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;	
}

void SIV120B_DIRECT_get_ev_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 9;
    p_info->support_item[0] = CAM_EV_NEG_4_3;
    p_info->support_item[1] = CAM_EV_NEG_3_3;
    p_info->support_item[2] = CAM_EV_NEG_2_3;
    p_info->support_item[3] = CAM_EV_NEG_1_3;
    p_info->support_item[4] = CAM_EV_ZERO;
    p_info->support_item[5] = CAM_EV_POS_1_3;
    p_info->support_item[6] = CAM_EV_POS_2_3;
    p_info->support_item[7] = CAM_EV_POS_3_3;
    p_info->support_item[8] = CAM_EV_POS_4_3;
}

void SIV120B_DIRECT_get_banding_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_BANDING_50HZ;
    p_info->support_item[1] = CAM_BANDING_60HZ;		
}

void SIV120B_DIRECT_get_zoom_ability(cam_zoom_info *p_info){ //different structure
    p_info->is_support = KAL_TRUE;
    p_info->zoom_steps = 40;
    p_info->max_zoom_factor = 800;
}

void SIV120B_DIRECT_get_video_scene_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_VIDEO_AUTO;
    p_info->support_item[1] = CAM_VIDEO_NIGHT;	
}

void SIV120B_DIRECT_get_video_codec_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_VIDEO_CODEDEC_MPEG;
    p_info->support_item[1] = CAM_VIDEO_CODEDEV_H263;
}

void SIV120B_DIRECT_get_video_size_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
#if(!defined(MT6238_PRES00))//6238 E3
    p_info->item_count = 4;
    p_info->support_item[0] = CAM_VIDEO_SIZE_QCIF;
    p_info->support_item[1] = CAM_VIDEO_SIZE_D1;
    p_info->support_item[2] = CAM_VIDEO_SIZE_QVGA;
    	p_info->support_item[3] = CAM_VIDEO_SIZE_VGA;
#else
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_VIDEO_SIZE_QCIF;
    p_info->support_item[1] = CAM_VIDEO_SIZE_QVGA;
#endif    

}

camera_capability_func_struct SIV120B_DIRECT_camera_capability = {
    SIV120B_DIRECT_get_capture_mode_ability,
    SIV120B_DIRECT_get_camera_scene_ability,
    SIV120B_DIRECT_get_capture_size_ability,
    SIV120B_DIRECT_get_flashlight_ability,
    SIV120B_DIRECT_get_af_range_ability,
    SIV120B_DIRECT_get_iso_ability,
    SIV120B_DIRECT_get_binning_ability,
    SIV120B_DIRECT_get_wb_ability,
    SIV120B_DIRECT_get_effect_ability,
    SIV120B_DIRECT_get_af_mode_ability,
    SIV120B_DIRECT_get_ae_meter_ability,
    SIV120B_DIRECT_get_sharpness_ability,
    SIV120B_DIRECT_get_contrast_ability,
    SIV120B_DIRECT_get_saturation_ability,
    SIV120B_DIRECT_get_ev_ability,
    SIV120B_DIRECT_get_banding_ability,
    SIV120B_DIRECT_get_zoom_ability,
    SIV120B_DIRECT_get_video_scene_ability,
    SIV120B_DIRECT_get_video_codec_ability,
    SIV120B_DIRECT_get_video_size_ability
};



CAP_SIZE SIV120B_DIRECT_camera_iso_imgsize_upperbound(CAM_SCENE_MODE iso_value)
{
    switch (iso_value)
    {
        case CAM_ISO800:
            return CAM_SIZE_VGA;
            break;
        case CAM_ISO1600:
            return CAM_SIZE_VGA;
            break;
        default:
            return CAM_SIZE_VGA;
            break;
    }
}

CAMERA_INTERFACE_ENUM SIV120B_DIRECT_camera_interface_support(void) {
    return CAM_YUV_SUPPORT;
}

camera_module_info_func_struct SIV120B_DIRECT_camera_module_info = {
    SIV120B_DIRECT_camera_interface_support
};

#elif (defined(DRV_ISP_6235_SERIES))


#include "camera_para.h"
#include "isp_flashlight.h"
#include "med_api.h"
#include "camera_info_SIV120B_DIRECT.h"

void SIV120B_DIRECT_get_capture_mode_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 4;
    p_info->support_item[0] = CAM_MODE_NORMAL;
    p_info->support_item[1] = CAM_MODE_CONT_SHOT;
    p_info->support_item[2] = CAM_MODE_BURST_SHOT;
    p_info->support_item[3] = CAM_MODE_ADD_FRAME;
}

void SIV120B_DIRECT_get_camera_scene_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_AUTO_DSC;
    p_info->support_item[1] = CAM_NIGHTSCENE;
}

void SIV120B_DIRECT_get_capture_size_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
#if (defined(__YUVCAM_INTERPOLATION_SW__)||defined(__YUVCAM_INTERPOLATION_HW__))
	p_info->item_count = 3;
	p_info->support_item[0] = CAM_SIZE_WALLPAPER;
	p_info->support_item[1] = CAM_SIZE_VGA;
	p_info->support_item[2] = CAM_SIZE_1M;
#else
	p_info->item_count = 2;
	p_info->support_item[0] = CAM_SIZE_WALLPAPER;
	p_info->support_item[1] = CAM_SIZE_VGA;
#endif
}

void SIV120B_DIRECT_get_flashlight_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_af_range_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_iso_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_binning_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_wb_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 6;
    p_info->support_item[0] = CAM_WB_AUTO;
    p_info->support_item[1] = CAM_WB_CLOUD;
    p_info->support_item[2] = CAM_WB_DAYLIGHT;
    p_info->support_item[3] = CAM_WB_INCANDESCENCE;
    p_info->support_item[4] = CAM_WB_FLUORESCENT;
    p_info->support_item[5] = CAM_WB_TUNGSTEN;
}

void SIV120B_DIRECT_get_effect_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 8;
    p_info->support_item[0] = CAM_EFFECT_ENC_NORMAL;
    p_info->support_item[1] = CAM_EFFECT_ENC_GRAYSCALE;
    p_info->support_item[2] = CAM_EFFECT_ENC_SEPIA;
    p_info->support_item[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    p_info->support_item[4] = CAM_EFFECT_ENC_SEPIABLUE;
    p_info->support_item[5] = CAM_EFFECT_ENC_COLORINV;
    p_info->support_item[6] = CAM_EFFECT_ENC_GRAYINV;
    p_info->support_item[7] = CAM_EFFECT_ENC_EMBOSSMENT;
}

void SIV120B_DIRECT_get_af_mode_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_ae_meter_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_sharpness_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_contrast_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_saturation_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_FALSE;
    p_info->item_count = 0;
}

void SIV120B_DIRECT_get_ev_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 9;
    p_info->support_item[0] = CAM_EV_NEG_4_3;
    p_info->support_item[1] = CAM_EV_NEG_3_3;
    p_info->support_item[2] = CAM_EV_NEG_2_3;
    p_info->support_item[3] = CAM_EV_NEG_1_3;
    p_info->support_item[4] = CAM_EV_ZERO;
    p_info->support_item[5] = CAM_EV_POS_1_3;
    p_info->support_item[6] = CAM_EV_POS_2_3;
    p_info->support_item[7] = CAM_EV_POS_3_3;
    p_info->support_item[8] = CAM_EV_POS_4_3;
}

void SIV120B_DIRECT_get_banding_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_BANDING_50HZ;
    p_info->support_item[1] = CAM_BANDING_60HZ;		
}

void SIV120B_DIRECT_get_zoom_ability(cam_zoom_info *p_info){ //different structure
    p_info->is_support = KAL_TRUE;
	
    p_info->zoom_steps = 40;
    p_info->max_zoom_factor = 40;

}

void SIV120B_DIRECT_get_video_scene_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_AUTO_DSC;
    p_info->support_item[1] = CAM_NIGHTSCENE;
}

void SIV120B_DIRECT_get_video_codec_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
    p_info->item_count = 2;
    p_info->support_item[0] = CAM_VIDEO_CODEDEC_MPEG;
    p_info->support_item[1] = CAM_VIDEO_CODEDEV_H263;
}

void SIV120B_DIRECT_get_video_size_ability(cam_fun_info *p_info){
    p_info->is_support = KAL_TRUE;
#if(defined(MP4_ENCODE))
	p_info->item_count = 2;
	p_info->support_item[0] = CAM_VIDEO_SIZE_QCIF;
	p_info->support_item[1] = CAM_VIDEO_SIZE_QVGA; 
#else
	p_info->item_count = 1;
	p_info->support_item[0] = CAM_VIDEO_SIZE_QCIF;
#endif			
}

camera_capability_func_struct SIV120B_DIRECT_camera_capability = {
    SIV120B_DIRECT_get_capture_mode_ability,
    SIV120B_DIRECT_get_camera_scene_ability,
    SIV120B_DIRECT_get_capture_size_ability,
    SIV120B_DIRECT_get_flashlight_ability,
    SIV120B_DIRECT_get_af_range_ability,
    SIV120B_DIRECT_get_iso_ability,
    SIV120B_DIRECT_get_binning_ability,
    SIV120B_DIRECT_get_wb_ability,
    SIV120B_DIRECT_get_effect_ability,
    SIV120B_DIRECT_get_af_mode_ability,
    SIV120B_DIRECT_get_ae_meter_ability,
    SIV120B_DIRECT_get_sharpness_ability,
    SIV120B_DIRECT_get_contrast_ability,
    SIV120B_DIRECT_get_saturation_ability,
    SIV120B_DIRECT_get_ev_ability,
    SIV120B_DIRECT_get_banding_ability,
    SIV120B_DIRECT_get_zoom_ability,
    SIV120B_DIRECT_get_video_scene_ability,
    SIV120B_DIRECT_get_video_codec_ability,
    SIV120B_DIRECT_get_video_size_ability
};


CAP_SIZE SIV120B_DIRECT_camera_iso_imgsize_upperbound(CAM_SCENE_MODE iso_value)
{
    switch (iso_value)
    {
        case CAM_ISO800:
            return CAM_SIZE_VGA;
            break;
        case CAM_ISO1600:
            return CAM_SIZE_VGA;
            break;
        default:
            return CAM_SIZE_VGA;
            break;
    }
}

#endif //#if (defined(DRV_ISP_6235_SERIES))
