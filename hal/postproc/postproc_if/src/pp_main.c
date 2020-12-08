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
 *   pp_main.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   Post Process interface
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
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */
#if (defined(__POSTPROC_SUPPORT__))
#include "kal_release.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"
#include "pp_api.h"
#include "pp_if.h"
#include "sensor_comm_def.h"	/* for MAIN/SUB SENSOR */
#include "pano_if.h"
#include "fd_if.h"
#include "sd_if.h"
#include "hdr_if.h"
#include "autocap_if.h"
#include "asd_if.h"   
#include "mavcap_if.h"   
#include "mav_if.h"   
#include "fd_comm_def.h"
#include "hdr_comm_def.h"
#include "autocap_comm_def.h"
#include "asd_comm_def.h"    
#include "mavcap_comm_def.h"    
#include "mav_comm_def.h"    

#if defined(__3D_IMAGE_SUPPORT__)
extern kal_bool gMavEnable3D;
#endif
#if defined(__CAMERA_GYRO_SUPPORT__)
extern kal_bool gMavEnableGyro;
#endif

/* State Control */
PP_STATE_ENUM 	gPpState = PP_STATE_IDLE;
PP_STATE_ENUM	gPpStateList[PP_FUNC_MAX];
kal_uint32		gPpEnableList;

/* Scenario Control */
PP_SCENARIO_ENUM 	gPpScenarioId;

/* Function Control */
P_FD_FUNCTION_STRUCT pfFdFunc=NULL;
P_SD_FUNCTION_STRUCT pfSdFunc=NULL;
P_PANO_FUNCTION_STRUCT pfPanoFunc=NULL;
P_HDR_FUNCTION_STRUCT pfHdrFunc=NULL;
P_AUTOCAP_FUNCTION_STRUCT pfAutoCapFunc=NULL;
P_ASD_FUNCTION_STRUCT pfAsdFunc=NULL;    
P_MAVCAP_FUNCTION_STRUCT pfMavCapFunc=NULL;
P_MAV_FUNCTION_STRUCT pfMavFunc=NULL;

/* Custom Tuning Parameters */
CAMERA_POST_PROCESS_PARA_STRUCT PpTuningOperPara;

/* Event group */
kal_eventgrpid gPpEvent = NULL;

/* Feature Control */        
static PpFunc gPpFuncMap[] = 
{
	PP_FUNC_FACE_DETECT,		&PpFdFeatureCtrl,	/* FaceDetection Feature Control */	
	PP_FUNC_SMILE_DETECT,		&PpSdFeatureCtrl,	
	PP_FUNC_BLINK_DETECT,		0,	
	PP_FUNC_PANORAMA,			&PpPanoFeatureCtrl,	
	PP_FUNC_AUTOCAP_PANORAMA,	&PpAutoCapFeatureCtrl,	
	PP_FUNC_HDR,		        &PpHdrFeatureCtrl,	
        PP_FUNC_ASD,		        &PpAsdFeatureCtrl,  
	PP_FUNC_MAVCAP,		       &PpMavCapFeatureCtrl,	
	PP_FUNC_MAV,		              &PpMavFeatureCtrl,	
};

/* Callback function */
MM_ERROR_CODE_ENUM (* pfPpCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

/* Custom Tuning Parameter Custom Init Interface */
extern void InitCameraPostProcessPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx, P_CAMERA_POST_PROCESS_PARA_STRUCT pData);

/* Custom Tuning Parameter Default Init Interface */
void DefaultCameraPostprocessPara(CAMERA_POST_PROCESS_PARA_STRUCT *pp_data)
{
    pp_data->fd_box_vibration_tolerance = 4; /* 0 - 6 */
    pp_data->fd_min_detect_face_size_index_00 = 1; /* 0 - 8 */
    pp_data->fd_min_detect_face_size_index_30 = 1; /* 0 - 8 */
    pp_data->fd_frame_detect_division = 10; /* 1 - 20 */
    pp_data->fd_max_tracking_face_num = 9; /* 1 - 9 */
    pp_data->fd_error_box_closing_time = 30; /* 15 - 110 */
    pp_data->fd_phone_rotation_mode = H_CR_CCR_MODE; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
    pp_data->fd_support_direction_num = 3; /* 1 - 4 */
    pp_data->fd_support_rip_num = RIP_00_30; /* RIP_00 or RIP_00_30 */
    pp_data->fd_color_check_threshold = 30;	 /* 30 - 60 */
    pp_data->fd_priority_mode = PRIOR_TO_CENTER; /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
    pp_data->fd_priority_weight = 128; /* 0 - 256, the value is for size*/
    pp_data->fd_hori_top_det_cycle = 5;		/* 1- 10, detection cycles in top direction */
    pp_data->fd_hori_bot_det_cycle = 1;		/* 1- 10, detection cycles in bottom direction */
    pp_data->fd_hori_lft_det_cycle = 1;		/* 1- 10, detection cycles in left direction */
    pp_data->fd_hori_rgt_det_cycle = 1;		/* 1- 10, detection cycles in right direction */
    pp_data->fd_direction_offset_horizontal = FACE_DIR_OFST_0; 	/* 0-3 */
    pp_data->fd_direction_offset_vertical = FACE_DIR_OFST_0;	/* 0-3 */
    pp_data->sd_max_detect_smile_per_round = 3;
    pp_data->sd_tolerance_count = 3;
    pp_data->sd_smile_required_num = 1;
    pp_data->sd_main_face_must_flag = KAL_TRUE;
    pp_data->pano_blend_scale = 8;
    pp_data->pano_upper_margin = 0;	/* work around for worse lens shading (upper + lower < height) */
    pp_data->pano_lower_margin = 0;
    pp_data->pano_left_margin = 0;	/* work around for worse lens shading (left + right < overlap width) */
    pp_data->pano_right_margin = 0;
#if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
#if (defined(YUV_MAIN_CAMERA))
    pp_data->pano_fix_ae = KAL_TRUE;    /* whether to fix ae after first capture */
#else
    pp_data->pano_fix_ae = KAL_FALSE;    /* whether to fix ae after first capture */
#endif
#if (defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M))
    pp_data->pano_focal_length = 1200;
#else
    pp_data->pano_focal_length = 750;
#endif
    pp_data->pano_tolerance_x = 8;
    pp_data->pano_tolerance_y = 8;
#else
    pp_data->pano_fix_ae = KAL_TRUE;    /* whether to fix ae after first capture */
#endif
    pp_data->pano_fix_awb = KAL_TRUE;   /* whether to fix awb after first capture */
    pp_data->hdr_level = HDR_LEVEL_4;
    pp_data->hdr_min_ba = 8;
    pp_data->hdr_sat_level = HDR_LEVEL_4;
    pp_data->hdr_qvi_dithering_flag = KAL_FALSE;
    pp_data->asd_fd_frame_period = 2; /* 1~3 */
    pp_data->asd_idx_weight_bl_ae = 1; /*0~10 */
    pp_data->asd_idx_weight_bl_scd= 8; /*0~10 */
    pp_data->asd_idx_weight_ls_ae = 1; /*0~10 */
    pp_data->asd_idx_weight_ls_awb= 1; /*0~10 */
    pp_data->asd_idx_weight_ls_af = 1; /*0~10 */
    pp_data->asd_idx_weight_ls_scd= 2; /*0~10 */
    pp_data->asd_decider_time_weight_type = ASD_TIME_WEIGHT_LATER_HIGHER; /*0:ASD_TIME_WEIGHT_AVERAGE, 1:ASD_TIME_WEIGHT_LATER_HIGHER*/
    pp_data->asd_decider_time_weight_range = ASD_TIME_WEIGHT_RANGE_10CYCLE; /*1~10, ASD_TIME_WEIGHT_RANGE_1CYCLE ~ ASD_TIME_WEIGHT_RANGE_10CYCLE*/
    pp_data->asd_ev_lo_thr_night = 50; /* 50 -> Lv=5 */
    pp_data->asd_ev_hi_thr_night = 80; /* 70 -> Lv=7 */
    pp_data->asd_ev_lo_thr_outdoor= 90; /*110 -> Lv=11 */
    pp_data->asd_ev_hi_thr_outdoor= 130; /*140 -> Lv=14 */
    pp_data->asd_score_thr_night = 60; /* 40~100 */
    pp_data->asd_score_thr_backlit = 40; /* 40~100 */
    pp_data->asd_score_thr_portrait= 45; /* 40~100 */    
    pp_data->asd_score_thr_landscape = 55; /* 40~100 */
    pp_data->asd_backlit_lock_enable = KAL_TRUE;
    pp_data->asd_backlit_lock_ev_diff= -10; /* -50~0 */    
    pp_data->mavcap_tolerance_x = 8; /* 7~9 */
    pp_data->mavcap_tolerance_y = 8; /* 7~9 */
    pp_data->mavcap_MaxMV = 7; /* 7~15 */
    pp_data->mavcap_StepLB = 8; /* 2~10 */
    pp_data->mavcap_StepUB = 15; /* 7~15 */
#if defined(MT6250)
    pp_data->mavcap_StepLB >>= 1;  // preview in 50 is 15fps
    pp_data->mavcap_StepUB >>= 1;  // preview in 50 is 15fps
#endif
    pp_data->mav_RCWinBound = 30; /* 20~40 */
    pp_data->mav_SearchRange = 15; /* 13~18 */
    pp_data->mav_MatchRate = 48; /* 45~51 */
    pp_data->mav_RectErrThre = 8; /* 7~9 */
    pp_data->mav_IterNum = 5; /* 3~7 */
    pp_data->mav_MaxAngle = 10; /* 7~13 */
    pp_data->mav_ClipRatio = 154; /* 140~165 */
#ifdef __CAMERA_GYRO_SUPPORT__
    pp_data->mavcap_GyroMvBound = 432;
#endif
}

/* Custom Tuning Parameter Check Interface */
void CheckCameraPostprocessPara(CAMERA_POST_PROCESS_PARA_STRUCT *pp_data)
{
    /* FD */
    if (pp_data->fd_max_tracking_face_num > 9)
    {
    	pp_data->fd_max_tracking_face_num = 9;
    }
    if (pp_data->fd_max_tracking_face_num == 0)
    {
    	pp_data->fd_max_tracking_face_num = 1;
    }
    if (pp_data->fd_phone_rotation_mode >= ROTATE_MODE_NUM)
    {
    	pp_data->fd_phone_rotation_mode = H_CR_CCR_MODE;
    }
    if (pp_data->fd_support_direction_num > 4)
    {
    	pp_data->fd_support_direction_num = 4;
    }
    if (pp_data->fd_support_direction_num == 0)
    {
    	pp_data->fd_support_direction_num = 1;
    }
    if (pp_data->fd_error_box_closing_time < 15)
    {
    	pp_data->fd_error_box_closing_time = 15;
    }
    if (pp_data->fd_error_box_closing_time > 110)
    {
    	pp_data->fd_error_box_closing_time = 110;
    }
    if (pp_data->fd_color_check_threshold < 30)
    {
    	pp_data->fd_color_check_threshold = 30;
    }
    if (pp_data->fd_color_check_threshold > 60)
    {
    	pp_data->fd_color_check_threshold = 60;
    }
    if (pp_data->fd_priority_mode >= PRIOR_NUM)
    {
    	pp_data->fd_priority_mode = PRIOR_TO_CENTER;
    }
    if (pp_data->fd_priority_weight > 256)
    {
    	pp_data->fd_priority_weight = 256;
    }
    if (pp_data->fd_frame_detect_division > 20)
    {
    	pp_data->fd_frame_detect_division = 20;
    }
    if (pp_data->fd_frame_detect_division < 1)
    {
    	pp_data->fd_frame_detect_division = 1;
    }
    if (pp_data->fd_min_detect_face_size_index_00 > 8)
    {
    	pp_data->fd_min_detect_face_size_index_00 = 8;
    }
    if (pp_data->fd_min_detect_face_size_index_30 > 8)
    {
    	pp_data->fd_min_detect_face_size_index_30 = 8;
    }
    if (pp_data->fd_box_vibration_tolerance > 6)
    {
    	pp_data->fd_box_vibration_tolerance = 6;
    }
    if (pp_data->fd_hori_top_det_cycle > 10)
    {
    	pp_data->fd_hori_top_det_cycle = 10;
    }
    else if (pp_data->fd_hori_top_det_cycle < 1)
    {
    	pp_data->fd_hori_top_det_cycle = 1;
    }
    if (pp_data->fd_hori_bot_det_cycle > 10)
    {
    	pp_data->fd_hori_bot_det_cycle = 10;
    }
    else if (pp_data->fd_hori_bot_det_cycle < 1)
    {
    	pp_data->fd_hori_bot_det_cycle = 1;
    }
    if (pp_data->fd_hori_lft_det_cycle > 10)
    {
    	pp_data->fd_hori_lft_det_cycle = 10;
    }
    else if (pp_data->fd_hori_lft_det_cycle < 1)
    {
    	pp_data->fd_hori_lft_det_cycle = 1;
    }
    if (pp_data->fd_hori_rgt_det_cycle > 10)
    {
    	pp_data->fd_hori_rgt_det_cycle = 10;
    }
    else if (pp_data->fd_hori_rgt_det_cycle < 1)
    {
    	pp_data->fd_hori_rgt_det_cycle = 1;
    }
    if (pp_data->fd_direction_offset_vertical>= FACE_DIR_OFST_NUM)
    {
    	pp_data->fd_direction_offset_vertical= FACE_DIR_OFST_90;
    }
    if (pp_data->fd_direction_offset_horizontal>= FACE_DIR_OFST_NUM)
    {
    	pp_data->fd_direction_offset_horizontal=  FACE_DIR_OFST_90;
    }
    /* SD */
    if (pp_data->sd_main_face_must_flag == KAL_TRUE)
    {
    	pp_data->sd_smile_required_num = 1;
    }
    if (pp_data->sd_smile_required_num > 3)
    {
    	pp_data->sd_smile_required_num = 3;
    }
    if (pp_data->sd_smile_required_num < 1)
    {
    	pp_data->sd_smile_required_num = 1;
    }
    /* HDR */
    if(pp_data->hdr_level > 10)
    {
        pp_data->hdr_level = 10;
    }
    if(pp_data->hdr_min_ba> 128)
    {
        pp_data->hdr_min_ba = 128;
    }
    if(pp_data->hdr_sat_level > 10)
    {
        pp_data->hdr_sat_level = 10;
    }
    /* ASD */
    if(pp_data->asd_fd_frame_period>3 || pp_data->asd_fd_frame_period<1)
    {
        pp_data->asd_fd_frame_period = 2;
    }
    if(pp_data->asd_idx_weight_bl_ae>10)
    {
        pp_data->asd_idx_weight_bl_ae = 10;
    }
    if(pp_data->asd_idx_weight_bl_ae<1)
    {
        pp_data->asd_idx_weight_bl_ae = 0;
    }
    if(pp_data->asd_idx_weight_bl_scd>10)
    {
        pp_data->asd_idx_weight_bl_scd = 10;
    }
    if(pp_data->asd_idx_weight_bl_scd<1)
    {
        pp_data->asd_idx_weight_bl_scd = 0;
    }
    if(pp_data->asd_idx_weight_ls_ae>10)
    {
        pp_data->asd_idx_weight_ls_ae = 10;
    }
    if(pp_data->asd_idx_weight_ls_ae<1)
    {
        pp_data->asd_idx_weight_ls_ae = 0;
    }
    if(pp_data->asd_idx_weight_ls_awb>10)
    {
        pp_data->asd_idx_weight_ls_awb = 10;
    }
    if(pp_data->asd_idx_weight_ls_awb<1)
    {
        pp_data->asd_idx_weight_ls_awb = 0;
    }
    if(pp_data->asd_idx_weight_ls_af>10)
    {
        pp_data->asd_idx_weight_ls_af = 10;
    }
    if(pp_data->asd_idx_weight_ls_af<1)
    {
        pp_data->asd_idx_weight_ls_af = 0;
    }
    if(pp_data->asd_idx_weight_ls_scd>10)
    {
        pp_data->asd_idx_weight_ls_scd = 10;
    }
    if(pp_data->asd_idx_weight_ls_scd<1)
    {
        pp_data->asd_idx_weight_ls_scd = 0;
    }
    if(pp_data->asd_decider_time_weight_type>=ASD_TIME_WEIGHT_IDX_WEIGHT_TYPE_NUM)
    {
        pp_data->asd_decider_time_weight_type = ASD_TIME_WEIGHT_AVERAGE;
    }
    if(pp_data->asd_decider_time_weight_range< ASD_TIME_WEIGHT_RANGE_1CYCLE)
    {
        pp_data->asd_decider_time_weight_range = ASD_TIME_WEIGHT_RANGE_1CYCLE;
    }
    if(pp_data->asd_decider_time_weight_range>=ASD_TIME_WEIGHT_RANGE_CYCLE_MAX)
    {
        pp_data->asd_decider_time_weight_range = ASD_TIME_WEIGHT_RANGE_10CYCLE;
    }
    if(pp_data->asd_ev_lo_thr_night>=pp_data->asd_ev_hi_thr_night )
    {
        pp_data->asd_ev_lo_thr_night = 50;
        pp_data->asd_ev_hi_thr_night  = 80;
    }
    if(pp_data->asd_ev_lo_thr_outdoor>=pp_data->asd_ev_hi_thr_outdoor )
    {
        pp_data->asd_ev_lo_thr_outdoor= 90;
        pp_data->asd_ev_hi_thr_outdoor= 130;
    }
    if(pp_data->asd_score_thr_night<40 ||pp_data->asd_score_thr_night>100 )
    {
        pp_data->asd_score_thr_night = 60;
    }
    if(pp_data->asd_score_thr_backlit<40 ||pp_data->asd_score_thr_backlit>100 )
    {
        pp_data->asd_score_thr_backlit = 40;
    }
    if(pp_data->asd_score_thr_portrait<40 ||pp_data->asd_score_thr_portrait>100 )
    {
        pp_data->asd_score_thr_portrait = 45;
    }    
    if(pp_data->asd_score_thr_landscape<40 ||pp_data->asd_score_thr_landscape>100 )
    {
        pp_data->asd_score_thr_landscape = 60;
    }
    if(pp_data->asd_backlit_lock_ev_diff<-50 || pp_data->asd_backlit_lock_ev_diff>0)
    {
        pp_data->asd_backlit_lock_ev_diff = -10;
    }    
    /* MAV */
    if (pp_data->mavcap_tolerance_x > 9)
    {
        pp_data->mavcap_tolerance_x = 9;
    }
    if (pp_data->mavcap_tolerance_x < 7)
    {
        pp_data->mavcap_tolerance_x = 7;        
    }    
    if (pp_data->mavcap_tolerance_y > 9)
    {
        pp_data->mavcap_tolerance_y = 9;
    }
    if (pp_data->mavcap_tolerance_y < 7)
    {
        pp_data->mavcap_tolerance_y = 7;        
    }    
    if (pp_data->mavcap_MaxMV > 15)
    {
        pp_data->mavcap_MaxMV = 15;
    }
    if (pp_data->mavcap_MaxMV < 7)
    {
        pp_data->mavcap_MaxMV = 7;        
    }        
    if (pp_data->mavcap_StepLB > 10)
    {
        pp_data->mavcap_StepLB = 10;
    }
    if (pp_data->mavcap_StepLB < 2)
    {
        pp_data->mavcap_StepLB = 2;        
    }          
    if (pp_data->mavcap_StepUB > 15)
    {
        pp_data->mavcap_StepUB = 15;
    }
    if (pp_data->mavcap_StepUB < 7)
    {
        pp_data->mavcap_StepUB = 7;        
    }      
    if (pp_data->mav_RCWinBound > 40)
    {
        pp_data->mav_RCWinBound = 40;
    }
    if (pp_data->mav_RCWinBound < 20)
    {
        pp_data->mav_RCWinBound = 20;   
    }    
    if (pp_data->mav_SearchRange > 18)
    {
        pp_data->mav_SearchRange = 18;
    }
    if (pp_data->mav_SearchRange < 13)
    {
        pp_data->mav_SearchRange = 13;    
    }      
    if (pp_data->mav_MatchRate > 51)
    {
        pp_data->mav_MatchRate = 51;
    }
    if (pp_data->mav_MatchRate < 45)
    {
        pp_data->mav_MatchRate = 45;    
    }      
    if (pp_data->mav_RectErrThre > 9)
    {
        pp_data->mav_RectErrThre = 9;
    }
    if (pp_data->mav_RectErrThre < 7)
    {
        pp_data->mav_RectErrThre = 7;    
    }     
    if (pp_data->mav_IterNum > 7)
    {
        pp_data->mav_IterNum = 7;
    }
    if (pp_data->mav_IterNum < 3)
    {
        pp_data->mav_IterNum = 3;    
    }     
    if (pp_data->mav_MaxAngle > 13)
    {
        pp_data->mav_MaxAngle = 13;
    }
    if (pp_data->mav_MaxAngle < 7)
    {
        pp_data->mav_MaxAngle = 7;    
    }     
    if (pp_data->mav_ClipRatio > 165)
    {
        pp_data->mav_ClipRatio = 165;
    }
    if (pp_data->mav_ClipRatio < 140)
    {
        pp_data->mav_ClipRatio = 140;    
    }          
}

MM_ERROR_CODE_ENUM PpCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
	gPpScenarioId = ScenarioId;

	if(PP_SCENARIO_CAMERA_PREVIEW == gPpScenarioId)
	{
		PpPreviewCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
	}
	else if(PP_SCENARIO_CAMERA_STILL_CAPTURE == gPpScenarioId)
	{
		PpCaptureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
	}
	else if (PP_SCENARIO_BG_POSTPROC == gPpScenarioId)
	{
		PpBgPostProcCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
	} 
	else if (PP_SCENARIO_POSTPROC == gPpScenarioId)
	{
		PpPostProcCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
	}
	else
	{
		ErrorCode =	MM_ERROR_INVALID_PARAMETER;
	}	
    return ErrorCode;
} /* PpCtrl() */

MM_ERROR_CODE_ENUM PpFeatureCtrl(PP_FUNC_ENUM FuncId, PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pPpFeatureParaIn =(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;
    kal_uint32 LogSize = 0;
    kal_uint32 TotalLogSize = 0;
    
#if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
    P_PP_FEATURE_CTRL_STRUCT_UNION	pPpFeatureParaTmp;
    PP_FEATURE_CTRL_STRUCT_UNION	PpFeatureParaTmp;
    PP_FEATURE_CONFIG_INFO_STRUCT	PpFeatureConfigParaTmp;

    PpFeatureParaTmp.pConfigInfo = &PpFeatureConfigParaTmp;
#endif    

    switch(CtrlId)
    { 	
        case PP_FEATURE_SET_SENSOR_IDX:
             /* init post process para from customer tuning parameters */
            DefaultCameraPostprocessPara(&PpTuningOperPara); 	
            InitCameraPostProcessPara((IMAGE_SENSOR_INDEX_ENUM)pPpFeatureParaIn->SensorIdx, &PpTuningOperPara);
            CheckCameraPostprocessPara(&PpTuningOperPara);  
            break;
        case PP_FEATURE_SET_ENABLE:	    	
            if(PP_IS_FEATURE_ENABLE(FuncId)==KAL_FALSE)
            {
                gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);	
                PP_SET_FEATURE_ENABLE(FuncId);	    									
            }
            break;
        case PP_FEATURE_SET_DISABLE:
            if(PP_IS_FEATURE_ENABLE(FuncId))
            {
                gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
                PP_SET_FEATURE_DISABLE(FuncId);					
            }
            break;           
        case PP_FEATURE_SET_ENV_INFO:	 
            if(FuncId==PP_FUNC_ALL)
            {
                 if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_FACE_DETECT)
                 {   
                     gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE, 0, 0, 0);	
                     gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn, 0, 0);	
                     PP_SET_FEATURE_ENABLE(PP_FUNC_FACE_DETECT);	    									
                 }                 
                 if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_SMILE_DETECT)
                 {   
                     gPpFuncMap[PP_FUNC_SMILE_DETECT].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE, 0, 0, 0);	
                     gPpFuncMap[PP_FUNC_SMILE_DETECT].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn, 0, 0);	
                     PP_SET_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT);	    									
                 }                 
                 #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                 if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_PANORAMA)
                 {
                    gPpFuncMap[PP_FUNC_AUTOCAP_PANORAMA].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE,0,0,0);
                    gPpFuncMap[PP_FUNC_AUTOCAP_PANORAMA].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn,0,0);
                    PP_SET_FEATURE_ENABLE(PP_FUNC_AUTOCAP_PANORAMA);	    									
                 }
                 #endif
                 #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
                 if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_ASD)
                 {
                    // turn on FD
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE, 0, 0, 0);
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn, 0, 0);
                    PP_SET_FEATURE_ENABLE(PP_FUNC_FACE_DETECT);

                    //get FD's env info ; to set the correct image W/H and ext memory offset for ASD
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(PP_FEATURE_GET_ENV_INFO, 0, &PpFeatureParaTmp, 0);
                    pPpFeatureParaIn->pConfigInfo->ImgWidth = PpFeatureConfigParaTmp.ImgWidth;
                    pPpFeatureParaIn->pConfigInfo->ImgHeight = PpFeatureConfigParaTmp.ImgHeight;
                    // shift FD part for ASD
                    pPpFeatureParaIn->pConfigInfo->ExtmemStartAddress += PpFeatureConfigParaTmp.ExtmemSize;
                    pPpFeatureParaIn->pConfigInfo->ExtmemSize -= PpFeatureConfigParaTmp.ExtmemSize;

                    // turn on ASD
                    gPpFuncMap[PP_FUNC_ASD].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE, 0, 0, 0);
                    gPpFuncMap[PP_FUNC_ASD].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn, 0, 0);
                    PP_SET_FEATURE_ENABLE(PP_FUNC_ASD);

                    // restore info for caller
                    pPpFeatureParaIn->pConfigInfo->ExtmemStartAddress -= PpFeatureConfigParaTmp.ExtmemSize;
                    pPpFeatureParaIn->pConfigInfo->ExtmemSize += PpFeatureConfigParaTmp.ExtmemSize;
                }
                #endif //__AUTO_SCENE_DETECT_SUPPORT__
                // 3D image
                #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))||(defined(__3D_IMAGE_SUPPORT__))||(defined(__CAMERA_GYRO_SUPPORT__))
                if( (pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAVCAP)
				   ||(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAVCAP_3D)
				   ||(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAVCAP_GYRO) )
                {
                	#ifdef __3D_IMAGE_SUPPORT__
	                gMavEnable3D = KAL_FALSE;
			if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAVCAP_3D)
				gMavEnable3D = KAL_TRUE;
			#endif
			#ifdef __CAMERA_GYRO_SUPPORT__
			gMavEnableGyro = KAL_FALSE;
			if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAVCAP_GYRO)
				gMavEnableGyro = KAL_TRUE;
			#endif
				
                    gPpFuncMap[PP_FUNC_MAVCAP].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE,0,0,0);
                    gPpFuncMap[PP_FUNC_MAVCAP].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn,0,0);
                    PP_SET_FEATURE_ENABLE(PP_FUNC_MAVCAP);	    									
                }
                if(pPpFeatureParaIn->pConfigInfo->PostProcMode == PP_MODE_MAV)
                {
                    gPpFuncMap[PP_FUNC_MAV].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE,0,0,0);
                    gPpFuncMap[PP_FUNC_MAV].fPFuncFeatureCtrl(CtrlId, pPpFeatureParaIn,0,0);
                    PP_SET_FEATURE_ENABLE(PP_FUNC_MAV);	    									
                }
                #endif
            }
            else
            {
                if(!PP_IS_FEATURE_ENABLE(FuncId))
                {
                    gPpFuncMap[FuncId].fPFuncFeatureCtrl(PP_FEATURE_SET_ENABLE, 0, 0, 0);	
                    gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
                    PP_SET_FEATURE_ENABLE(FuncId);
                }
                else    /* already set enabled */
                {
                    gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);
                }
            }
            break;
        case PP_FEATURE_GET_ENV_INFO:	
            if(FuncId==PP_FUNC_ALL)
            {                
              #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
                if(PP_IS_FEATURE_ENABLE(PP_FUNC_ASD))
                {
                    // get FD's info
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(CtrlId, 0, &PpFeatureParaTmp, 0);
                    // get ASD's info
                    gPpFuncMap[PP_FUNC_ASD].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);

                    // calculate both FD&ASD ext mem usage for output to CAL
                    pPpFeatureParaTmp = (P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;
                    pPpFeatureParaTmp->pConfigInfo->ExtmemSize += PpFeatureParaTmp.pConfigInfo->ExtmemSize;
                }
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT))
              #else
                if(PP_IS_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT))
              #endif //__AUTO_SCENE_DETECT_SUPPORT__
                {
                     gPpFuncMap[PP_FUNC_SMILE_DETECT].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);	
                }
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_FACE_DETECT))
                {
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);	
                }     
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
                {
                    gPpFuncMap[PP_FUNC_PANORAMA].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);	
                #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                    gPpFuncMap[PP_FUNC_AUTOCAP_PANORAMA].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);		    									
                #endif
                }       
              #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))||(defined(__3D_IMAGE_SUPPORT__))||(defined(__CAMERA_GYRO_SUPPORT__))
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAVCAP))     
                {
                    gPpFuncMap[PP_FUNC_MAVCAP].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);	                
                } 
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAV))     
                {
                    gPpFuncMap[PP_FUNC_MAV].fPFuncFeatureCtrl(CtrlId, 0, pOutPara, 0);	                
                } 
              #endif                         
            }
            else
            {
                gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);	
            }
            break;
        case PP_FEATURE_SET_LOG_INFO:
            switch (pPpFeatureParaIn->pLogInfo->ScenarioId)
            {
                case PP_SCENARIO_CAMERA_PREVIEW:
                    gPpFuncMap[PP_FUNC_FACE_DETECT].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);    
                    pPpFeatureParaIn->pLogInfo->ExtmemStartAddress += LogSize;
                    gPpFuncMap[PP_FUNC_SMILE_DETECT].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);
                    #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                    pPpFeatureParaIn->pLogInfo->ExtmemStartAddress += LogSize;
                    gPpFuncMap[PP_FUNC_AUTOCAP_PANORAMA].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);
                    #endif
		    #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
                    pPpFeatureParaIn->pLogInfo->ExtmemStartAddress += LogSize;
                    gPpFuncMap[PP_FUNC_MAVCAP].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);
                    #endif                     
                    break;
                case PP_SCENARIO_CAMERA_STILL_CAPTURE:
                    #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))                           
                    pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SAVE_DECIDER_LOG_INFO, NULL, NULL, 0);
                    #endif                              
                    break;
                case PP_SCENARIO_BG_POSTPROC:
                    break;
                case PP_SCENARIO_POSTPROC:
                    gPpFuncMap[PP_FUNC_PANORAMA].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);

                    #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
                    gPpFuncMap[PP_FUNC_MAV].fPFuncFeatureCtrl(CtrlId, pInPara, &LogSize, sizeof(LogSize));
                    TotalLogSize += LogSize;
                    ASSERT(pPpFeatureParaIn->pLogInfo->ExtmemSize>=TotalLogSize);                   
                    #endif                

                    break;
                default:    // Unknown scenario id
                    ASSERT(0);
            } 	
            if (pOutPara) *((kal_uint32*)pOutPara) = TotalLogSize;
            break;
            
        default:
            if( FuncId != gPpFuncMap[FuncId].FuncID )
            {   // ASSERT(INCORRECT MAPPING)
                ErrorCode = MM_ERROR_INVALID_PARAMETER;
            }
            else
            {
                gPpFuncMap[FuncId].fPFuncFeatureCtrl(CtrlId, pInPara, pOutPara, OutParaLen);	
            }
		break;			
    }
    return ErrorCode;
} /* PpFeatureCtrl() */

MM_ERROR_CODE_ENUM PpOpen(MM_ERROR_CODE_ENUM (* pPplback) (	
							PP_CALLBACK_ID_ENUM CbId, void *pPplbackPara, kal_uint16 PplbackParaLen))
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

     if(gPpState != PP_STATE_IDLE)  // should Close before Open
    {
    	ASSERT(0);
    }

    if (gPpEvent==NULL)
    {
        gPpEvent = kal_create_event_group("PP_EVT");
    }
    kal_set_eg_events(gPpEvent,0,KAL_AND);

    pfPpCb = pPplback;
       
    FdInit(pPplback, &pfFdFunc);    
    SdInit(pPplback, &pfSdFunc);        
    PanoInit(pPplback, &pfPanoFunc);
    HdrInit(pPplback, &pfHdrFunc);
    AutoCapInit(pPplback, &pfAutoCapFunc);
    AsdInit(pPplback, &pfAsdFunc);   
    MavCapInit(pPplback, &pfMavCapFunc);   
    MavInit(pPplback, &pfMavFunc);   
    
    gPpState = PP_STATE_STANDBY;    
    return ErrorCode;
} /* PpOpen() */

MM_ERROR_CODE_ENUM PpClose(void)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    gPpState = PP_STATE_IDLE;
    return ErrorCode;
} /* PpClose() */
#endif /* defined(__POSTPROC_SUPPORT__) */

