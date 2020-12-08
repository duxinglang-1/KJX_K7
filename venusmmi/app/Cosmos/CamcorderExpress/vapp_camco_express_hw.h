/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef __VAPP_CAMCO_EXPRESS_HW__
#define __VAPP_CAMCO_EXPRESS_HW__

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"
#include "MMI_features_camcorder.h"

#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#ifdef __cplusplus
}
#endif

#ifdef __VAPP_CAMCO_EXPRESS__
#include "vapp_camco_express_setting_mgr.h"
#include "vapp_camco_express_app.h"

MDI_RESULT vapp_camco_reset_hw_obj(void);

MDI_RESULT vapp_camco_cam_preview_start(vapp_camco_cam_preview_start_param_struct *param);
MDI_RESULT vapp_camco_cam_preview_stop(vapp_camco_cam_preview_stop_param_struct *param);

MDI_RESULT vapp_camco_rec_preview_start(vapp_camco_rec_preview_start_param_struct *param);
MDI_RESULT vapp_camco_rec_preview_stop(vapp_camco_rec_preview_stop_param_struct *param);

MDI_RESULT vapp_camco_cam_power_on(vapp_camco_cam_power_on_param_struct *param);
MDI_RESULT vapp_camco_cam_power_off(vapp_camco_cam_power_off_param_struct *param);
MDI_RESULT vapp_camco_rec_power_on(vapp_camco_rec_power_on_param_struct *param);
MDI_RESULT vapp_camco_rec_power_off(vapp_camco_rec_power_off_param_struct *param);

MDI_RESULT vapp_camco_cam_normal_shot(vapp_camco_cam_capture_param_struct *param);
MDI_RESULT vapp_camco_cam_save_capture_image(vapp_camco_cam_capture_save_param_struct *param);

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
MDI_RESULT vapp_camco_cam_smiledetect_get_result(vapp_camco_cam_sd_param_struct *param);
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
MDI_RESULT vapp_camco_cam_scenedetect_get_result(vapp_camco_cam_scene_param_struct *param);
#endif

MDI_RESULT vapp_camco_rec_record_start(vapp_camco_rec_record_param_struct *param);
MDI_RESULT vapp_camco_rec_record_stop(vapp_camco_rec_record_param_struct *param);
MDI_RESULT vapp_camco_rec_record_pause(vapp_camco_rec_record_param_struct *param);
MDI_RESULT vapp_camco_rec_record_resume(vapp_camco_rec_record_param_struct *param);

MDI_RESULT vapp_camco_rec_record_get_time(VfxU64 *time);
MDI_RESULT vapp_camco_rec_record_get_size(VfxU64 *size);
MDI_RESULT vapp_camco_rec_record_get_count(VfxU64 *count);

MDI_RESULT vapp_camco_rec_save_video(vapp_camco_rec_record_save_param_struct *param);
MDI_RESULT vapp_camco_rec_stop_save_video(void);
MDI_RESULT vapp_camco_rec_fetch_frame(vapp_camco_rec_fetch_param_struct *param);

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
MDI_RESULT vapp_camco_cam_sd_start(vapp_camco_cam_sd_param_struct *param);
MDI_RESULT vapp_camco_cam_sd_stop(vapp_camco_cam_sd_param_struct *param);
#endif

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
MDI_RESULT vapp_camco_cam_autofocus_start(vapp_camco_autofocus_param_struct *param);
MDI_RESULT vapp_camco_cam_autofocus_stop(vapp_camco_autofocus_param_struct *param);
MDI_RESULT vapp_camco_cam_get_autofocus_result(vapp_camco_autofocus_param_struct *param);

MDI_RESULT vapp_camco_rec_autofocus_start(vapp_camco_autofocus_param_struct *param);
MDI_RESULT vapp_camco_rec_autofocus_stop(vapp_camco_autofocus_param_struct *param);
MDI_RESULT vapp_camco_rec_get_autofocus_result(vapp_camco_autofocus_param_struct *param);
#endif

MDI_RESULT vapp_camco_cam_get_estimated_picture_size(vapp_camco_estimate_size_param_struct *param);
MDI_RESULT vapp_camco_rec_get_estimated_video_size(vapp_camco_estimate_size_param_struct *param);

MDI_RESULT vapp_camco_background_calculation_start(vapp_camco_cal_background_param_struct *param);
MDI_RESULT vapp_camco_background_calculation_stop(vapp_camco_cal_background_param_struct *param);

#endif /*__VAPP_CAMCO_EXPRESS__*/
#endif /*__VAPP_CAMCO_EXPRESS_HW__*/
