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

#ifndef __VAPP_AUTOCAP_HW__
#define __VAPP_AUTOCAP_HW__

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"
#include "MMI_features_camcorder.h"     /* features */

#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"
#include "mdi_video.h"  /* mdi video library */
#ifdef __cplusplus
}
#endif

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
#include "vapp_autocap_setting_mgr.h"
#include "vapp_autocap_app.h"

MDI_RESULT vapp_autocap_reset_hw_obj(void);

MDI_RESULT vapp_autocap_preview_start(vapp_autocap_preview_start_param_struct *param);
MDI_RESULT vapp_autocap_preview_stop(vapp_autocap_preview_stop_param_struct *param);
MDI_RESULT vapp_autocap_power_on(vapp_autocap_power_on_param_struct *param);
MDI_RESULT vapp_autocap_power_off(vapp_autocap_power_off_param_struct *param);

MDI_RESULT vapp_autocap_panorama_shot(vapp_autocap_capture_param_struct *param);
MDI_RESULT vapp_autocap_panorama_stitch(vapp_autocap_panorama_stitch_param_struct *param);
MDI_RESULT vapp_autocap_panorama_encode(vapp_autocap_panorama_encode_param_struct *param);
MDI_RESULT vapp_autocap_panorama_stop_stitch(void);
MDI_RESULT vapp_autocap_panorama_pause_stitch(void);
MDI_RESULT vapp_autocap_panorama_resume_stitch(void);
MDI_RESULT vapp_autocap_reset_panorama_3a(void);

MDI_RESULT vapp_autocap_mav_shot(vapp_autocap_capture_param_struct *param);
MDI_RESULT vapp_autocap_mav_stop(void);
MDI_RESULT vapp_autocap_mav_save(void);

MDI_RESULT vapp_autocap_save_capture_image(vapp_autocap_capture_save_param_struct *param);

MDI_RESULT vapp_autocap_autofocus_start(vapp_autocap_autofocus_param_struct *param);
MDI_RESULT vapp_autocap_autofocus_stop(vapp_autocap_autofocus_param_struct *param);
MDI_RESULT vapp_autocap_get_autofocus_result(vapp_autocap_autofocus_param_struct *param);

MDI_RESULT vapp_autocap_bk_turn_on(void);
MDI_RESULT vapp_autocap_bk_turn_off(void);

MDI_RESULT vapp_autocap_highlight_turn_on(vapp_autocap_general_param_struct *param);
MDI_RESULT vapp_autocap_highlight_turn_off(vapp_autocap_general_param_struct *param);

MDI_RESULT vapp_autocap_get_estimated_picture_size(vapp_autocap_estimate_size_param_struct *param);

MDI_RESULT vapp_autocap_background_calculation_start(void);
MDI_RESULT vapp_autocap_background_calculation_stop(void);

#endif
#endif
