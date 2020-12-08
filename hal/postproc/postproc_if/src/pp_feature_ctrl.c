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
 *   pp_feature_ctrl.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */
#include "kal_release.h"
#include "feature_comm_def.h"
#include "pp_api.h"
#include "pp_comm_def.h"
#include "fd_comm_def.h"
#include "pano_comm_def.h"
#include "hdr_comm_def.h"
#include "autocap_comm_def.h"
#include "asd_comm_def.h"    
#include "mavcap_comm_def.h"    
#include "mav_comm_def.h"    
#include "pp_if.h"
#include "fd_if.h"
#include "sd_if.h"
#include "pano_if.h"
#include "hdr_if.h"
#include "autocap_if.h"
#include "asd_if.h"   
#include "mavcap_if.h"   
#include "mav_if.h"   
#include "fd_core.h"
#include "sd_core.h"
#include "pano_core.h"
#include "autocap_core.h"
#include "hdr_core.h"
#include "asd_core.h"    
#include "MavMotionCore.h"    
#include "mav_core.h"    

#if (defined(__POSTPROC_SUPPORT__))

/* extern Function Points */
extern P_FD_FUNCTION_STRUCT pfFdFunc;
extern P_SD_FUNCTION_STRUCT pfSdFunc;
extern P_PANO_FUNCTION_STRUCT pfPanoFunc;
extern P_HDR_FUNCTION_STRUCT pfHdrFunc;
extern P_AUTOCAP_FUNCTION_STRUCT pfAutoCapFunc;
extern P_ASD_FUNCTION_STRUCT pfAsdFunc;   
extern P_MAVCAP_FUNCTION_STRUCT pfMavCapFunc;   
extern P_MAV_FUNCTION_STRUCT pfMavFunc;   

PP_PROC_INFO_STRUCT	gPpProcInfoPara;

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
kal_bool gPanoStitchDirDecided = KAL_FALSE;
#endif

#if defined(__3D_IMAGE_SUPPORT__)
kal_bool gMavEnable3D = KAL_FALSE;
#endif
#if defined(__CAMERA_GYRO_SUPPORT__)
kal_bool gMavEnableGyro = KAL_FALSE;
#endif

MM_ERROR_CODE_ENUM PpFdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{	
#if defined(__FACE_DETECTION_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;
	/* Set/Get Env Info */
	FD_SET_ENV_INFO_STRUCT	FdSetEnvInfo;
	FD_GET_ENV_INFO_STRUCT	FdGetEnvInfo;	
    switch(CtrlId)
    { 		
	    case PP_FEATURE_SET_ENABLE:	    
			pfFdFunc->FdOpen();	    	
			break;			
	    case PP_FEATURE_SET_DISABLE:	    				
			pfFdFunc->FdClose();	    						
	    	break;						
		case PP_FEATURE_GET_STATE:		
			pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
			break;
	    case PP_FEATURE_SET_ENV_INFO:	    	    	    	
			/* update working buffer */	    	
	    	gPpProcInfoPara.PpProcBufAddr = pFeatureIn->pConfigInfo->ExtmemStartAddress;	
	    	gPpProcInfoPara.PpProcBufSize = pFeatureIn->pConfigInfo->ExtmemSize;		    	
			gPpProcInfoPara.PpProcFmt = pFeatureIn->pConfigInfo->ImgFmtCurr;
			/* check Info */
			FdSetEnvInfo.target_width = pFeatureIn->pConfigInfo->ImgWidth;
			FdSetEnvInfo.target_height =pFeatureIn->pConfigInfo->ImgHeight; 
			FdSetEnvInfo.ImgFmtList = pFeatureIn->pConfigInfo->ImgFmtList;

			FdSetEnvInfo.fd_tuning_data.box_vibration_tolerance = PpTuningOperPara.fd_box_vibration_tolerance; /* 0 - 6 */
			FdSetEnvInfo.fd_tuning_data.min_detect_face_size_index_00 = PpTuningOperPara.fd_min_detect_face_size_index_00; /* 0 - 8 */
			FdSetEnvInfo.fd_tuning_data.min_detect_face_size_index_30 = PpTuningOperPara.fd_min_detect_face_size_index_30; /* 0 - 8 */
			FdSetEnvInfo.fd_tuning_data.frame_detect_division = PpTuningOperPara.fd_frame_detect_division; /* 1 - 20 */
			FdSetEnvInfo.fd_tuning_data.max_tracking_face_num = PpTuningOperPara.fd_max_tracking_face_num; /* 1 - 9 */
			FdSetEnvInfo.fd_tuning_data.error_box_closing_time = PpTuningOperPara.fd_error_box_closing_time; /* 15 - 110 */
			FdSetEnvInfo.fd_tuning_data.phone_rotation_mode = PpTuningOperPara.fd_phone_rotation_mode; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
			FdSetEnvInfo.fd_tuning_data.support_direction_num = PpTuningOperPara.fd_support_direction_num; /* 1 - 4 */
			FdSetEnvInfo.fd_tuning_data.support_rip_num = PpTuningOperPara.fd_support_rip_num; /* RIP_00 or RIP_00_30 */
			FdSetEnvInfo.fd_tuning_data.color_check_threshold = PpTuningOperPara.fd_color_check_threshold;	 /* 30 - 60 */
			FdSetEnvInfo.fd_tuning_data.priority_mode = PpTuningOperPara.fd_priority_mode; /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
			FdSetEnvInfo.fd_tuning_data.priority_weight = PpTuningOperPara.fd_priority_weight; /* 0 - 256, the value is for size*/				
			FdSetEnvInfo.fd_tuning_data.direction_offset_horizontal = PpTuningOperPara.fd_direction_offset_horizontal; 	/* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
			FdSetEnvInfo.fd_tuning_data.direction_offset_vertical = PpTuningOperPara.fd_direction_offset_horizontal; 			
			
			FdSetEnvInfo.fd_tuning_data.hori_top_det_cycle = PpTuningOperPara.fd_hori_top_det_cycle;				/* 1- 10, detection cycles in top direction */
			FdSetEnvInfo.fd_tuning_data.hori_bot_det_cycle = PpTuningOperPara.fd_hori_bot_det_cycle;				/* 1- 10, detection cycles in bottom direction */
			FdSetEnvInfo.fd_tuning_data.hori_lft_det_cycle = PpTuningOperPara.fd_hori_lft_det_cycle;				/* 1- 10, detection cycles in left direction */
			FdSetEnvInfo.fd_tuning_data.hori_rgt_det_cycle = PpTuningOperPara.fd_hori_rgt_det_cycle;				/* 1- 10, detection cycles in right direction */       			

			pfFdFunc->FdFeatureCtrl(FD_FEATURE_SET_ENV_INFO, &FdSetEnvInfo, NULL, 0);
			break;
	    case PP_FEATURE_GET_ENV_INFO:	    	    	    				
			pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_ENV_INFO, NULL, &FdGetEnvInfo, 0);		
			pConfigInfo->ImgFmtCurr = FdGetEnvInfo.SrcImgFormat;
			pConfigInfo->ExtmemSize = FdGetEnvInfo.WorkingBufSize;
			pConfigInfo->MdpConfigFlag=KAL_TRUE;
			pConfigInfo->ImgWidth = FdGetEnvInfo.ImageWidth;	    	
			pConfigInfo->ImgHeight = FdGetEnvInfo.ImageHeight;	    	
			pConfigInfo->MaxImgWidth = FD_IMAGE_XS;	    	
			pConfigInfo->MaxImgHeight = FD_IMAGE_YS;	  	    	
			pConfigInfo->IspConfigFlag=KAL_FALSE;
	    	break;			
	    case PP_FEATURE_GET_RESULT:
	    	pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_RESULT, NULL, pFeatureIn->pFdResult, OutParaLen);
	    	break;	    	    	
            case PP_FEATURE_SET_LOG_INFO:	
              pfFdFunc->FdFeatureCtrl(FD_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
	    	
	    case PP_FEATURE_GET_OPMODE:	    
			pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_HIGH;
			pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TRIGGER;	    	
	    	break;	    	
	}
    return ErrorCode;	
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpSdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
#if defined(__SMILE_SHUTTER_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;
	
	/* Set/Get Env Info */
	SD_SET_ENV_INFO_STRUCT	SdSetEnvInfo;
	SD_GET_ENV_INFO_STRUCT	SdGetEnvInfo;	
	/* Get State */
    switch(CtrlId)
    { 		
	    case PP_FEATURE_SET_ENABLE:	    
			pfSdFunc->SdOpen();	    	
			break;			
	    case PP_FEATURE_SET_DISABLE:	    				
			pfSdFunc->SdClose();	    						
	    	break;						
		case PP_FEATURE_GET_STATE:		
			pfSdFunc->SdFeatureCtrl(SD_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
			break;
	    case PP_FEATURE_SET_ENV_INFO:	    	    	    	
			/* update working buffer */	    	
	    	gPpProcInfoPara.PpProcBufAddr = pFeatureIn->pConfigInfo->ExtmemStartAddress;	
	    	gPpProcInfoPara.PpProcBufSize = pFeatureIn->pConfigInfo->ExtmemSize;		    	
	    	gPpProcInfoPara.PpProcFmt = pFeatureIn->pConfigInfo->ImgFmtCurr;
			/* check Info */
			SdSetEnvInfo.target_width = pFeatureIn->pConfigInfo->ImgWidth;
			SdSetEnvInfo.target_height =pFeatureIn->pConfigInfo->ImgHeight; 
			SdSetEnvInfo.ImgFmtList = pFeatureIn->pConfigInfo->ImgFmtList;

			SdSetEnvInfo.sd_tuning_data.sd_end_count_threshold = 1; /*SD_END_COUNT_THRRESHOLD*//* 0:once smile detected, enter capture, N:"continue" N smile detectedcam_fd_process to end the sd and enter capture */
			SdSetEnvInfo.sd_tuning_data.sd_max_detect_smile_per_round = PpTuningOperPara.sd_max_detect_smile_per_round; /* 1-9, max smiles for detecting in a fd process */		
			SdSetEnvInfo.sd_tuning_data.sd_tolerance_count = PpTuningOperPara.sd_tolerance_count;
			SdSetEnvInfo.sd_tuning_data.sd_smile_required_num = PpTuningOperPara.sd_smile_required_num; 
			SdSetEnvInfo.sd_tuning_data.sd_main_face_must_flag = PpTuningOperPara.sd_main_face_must_flag;

			pfSdFunc->SdFeatureCtrl(SD_FEATURE_SET_ENV_INFO, &SdSetEnvInfo, NULL, 0);
	    	break;
	    case PP_FEATURE_GET_ENV_INFO:	    	    	    				
			pfSdFunc->SdFeatureCtrl(SD_FEATURE_GET_ENV_INFO, NULL, &SdGetEnvInfo, 0);	
			pConfigInfo->ImgFmtCurr = SdGetEnvInfo.SrcImgFormat;
			pConfigInfo->ExtmemSize = SdGetEnvInfo.WorkingBufSize;
			pConfigInfo->MdpConfigFlag=KAL_TRUE;
			pConfigInfo->ImgWidth = SdGetEnvInfo.ImageWidth;	    	
			pConfigInfo->ImgHeight = SdGetEnvInfo.ImageHeight;	    	
			pConfigInfo->MaxImgWidth = SD_IMAGE_XS;	    	
			pConfigInfo->MaxImgHeight = SD_IMAGE_YS;	  	    	
			pConfigInfo->IspConfigFlag=KAL_FALSE;
	    	break;			
	    case PP_FEATURE_GET_RESULT:
	    	pfSdFunc->SdFeatureCtrl(SD_FEATURE_GET_RESULT, NULL, pFeatureIn->pSdResult, OutParaLen);
	    	break;	    	      
            case PP_FEATURE_SET_LOG_INFO:	
              pfSdFunc->SdFeatureCtrl(SD_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;

	    case PP_FEATURE_GET_OPMODE:	    
			pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_HIGH;
			pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TRIGGER;
	    	break;	    	
	}
    return ErrorCode;
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpPanoFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;
    /* Set Env Info */
    PANO_ENV_INFO_STRUCT    PanoEnvInfo;
    /* Get Env Info */
    PANO_GET_INFO_STRUCT    PanoGetEnvInfo;
    static PP_TIMER_PROC_INFO_STRUCT PanoTimerProcInfo = {0};
    
    switch(CtrlId)
    { 		
        case PP_FEATURE_SET_ENABLE:	    
            pfPanoFunc->PanoOpen();	    	
            break;			
        case PP_FEATURE_SET_DISABLE:
            pfPanoFunc->PanoClose();	    						
            break;	
        case PP_FEATURE_GET_STATE:		
        	pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
        	break;
        case PP_FEATURE_SET_ENV_INFO:	    	    	    	
            /* get Info from cal */
            PanoEnvInfo.SrcImgWidth = pFeatureIn->pPanoSetEnvInfo->SrcImgWidth;
            PanoEnvInfo.SrcImgHeight =pFeatureIn->pPanoSetEnvInfo->SrcImgHeight; 
            PanoEnvInfo.SrcImgFormat = pFeatureIn->pPanoSetEnvInfo->SrcImgFormat;
            PanoEnvInfo.StitchDirection = pFeatureIn->pPanoSetEnvInfo->StitchDirection;
            if (PANO_DIR_NO == PanoEnvInfo.StitchDirection)
            {   /* info for autocap */
                gPanoStitchDirDecided = KAL_FALSE;
            }
            else
            {
                gPanoStitchDirDecided = KAL_TRUE;
            }
            PanoEnvInfo.MaxPanoImgWidth = PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH;
            PanoEnvInfo.MaxSnapshotNumber = PANORAMA_MAX_INPUT_IMAGE_NUM;
            PanoEnvInfo.DstImgFormat = MM_IMAGE_FORMAT_YUV420;

            
            PanoEnvInfo.FixAe= PpTuningOperPara.pano_fix_ae;
            PanoEnvInfo.FocalLength = PpTuningOperPara.pano_focal_length;
            PanoEnvInfo.GPUWarp = KAL_FALSE;                           
			
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_ENV_INFO, &PanoEnvInfo, NULL, 0);
            break;
        case PP_FEATURE_GET_ENV_INFO:
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_ENV_INFO, 0, &PanoGetEnvInfo, 0);
            pConfigInfo->ExtmemSize =  PanoGetEnvInfo.StitchWorkingBufSize;
            pConfigInfo->MdpConfigFlag = KAL_FALSE;	    		    		  	    	
            pConfigInfo->IspConfigFlag = KAL_TRUE;
            pConfigInfo->FixAe = PpTuningOperPara.pano_fix_ae;
            pConfigInfo->FixAwb = PpTuningOperPara.pano_fix_awb;
            break;
        case PP_FEATURE_GET_RESULT:
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_RESULT, NULL, pFeatureIn->pPanoResult, OutParaLen);
            break;	    		
        case PP_FEATURE_SET_LOG_INFO:	
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
        case PP_FEATURE_GET_OPMODE:	    
            pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_LOW;
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TIMER;
            PanoTimerProcInfo.TimerProcPeriod = 500;	    // ms
            PanoTimerProcInfo.TimerSuspPeriod = 20;		// ms
            pFeatureOut->pFuncOpMode->pTimerProcInfo = &PanoTimerProcInfo;
            break;	    	
	}
    return ErrorCode;
#elif defined(__PANORAMA_VIEW_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;
    /* Set Env Info */
    PANO_ENV_INFO_STRUCT    PanoEnvInfo;
    /* Get Env Info */
    PANO_GET_INFO_STRUCT    PanoGetEnvInfo;
    static PP_TIMER_PROC_INFO_STRUCT PanoTimerProcInfo = {0};
    
    switch(CtrlId)
    { 		
        case PP_FEATURE_SET_ENABLE:	    
            pfPanoFunc->PanoOpen();	    	
            break;			
        case PP_FEATURE_SET_DISABLE:
            pfPanoFunc->PanoClose();	    						
            break;	
        case PP_FEATURE_GET_STATE:		
        	pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
        	break;
        case PP_FEATURE_SET_ENV_INFO:	    	    	    	
            /* get Info from cal */
            PanoEnvInfo.SrcImgWidth = pFeatureIn->pPanoSetEnvInfo->SrcImgWidth;
            PanoEnvInfo.SrcImgHeight =pFeatureIn->pPanoSetEnvInfo->SrcImgHeight; 
            PanoEnvInfo.SrcImgFormat = pFeatureIn->pPanoSetEnvInfo->SrcImgFormat;
            PanoEnvInfo.StitchDirection = pFeatureIn->pPanoSetEnvInfo->StitchDirection;
            
            PanoEnvInfo.MaxPanoImgWidth = PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH;
            PanoEnvInfo.MaxSnapshotNumber = PANORAMA_MAX_INPUT_IMAGE_NUM;
            #if (defined(PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420))
            PanoEnvInfo.DstImgFormat = MM_IMAGE_FORMAT_YUV420;
            #elif (defined(PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_RGB565))
            PanoEnvInfo.DstImgFormat = MM_IMAGE_FORMAT_RGB565;
            #else
            ASSERT(0);
            #endif
            
            PanoEnvInfo.BlendScale = PpTuningOperPara.pano_blend_scale; 
            PanoEnvInfo.UpperMargin = PpTuningOperPara.pano_upper_margin; 
            PanoEnvInfo.LowerMargin = PpTuningOperPara.pano_lower_margin; 
            PanoEnvInfo.LeftMargin = PpTuningOperPara.pano_left_margin;	
            PanoEnvInfo.RightMargin = PpTuningOperPara.pano_right_margin;
            PanoEnvInfo.FixAe= PpTuningOperPara.pano_fix_ae;
            PanoEnvInfo.FixAwb= PpTuningOperPara.pano_fix_awb;
			
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_ENV_INFO, &PanoEnvInfo, NULL, 0);
            break;
        case PP_FEATURE_GET_ENV_INFO:
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_ENV_INFO, 0, &PanoGetEnvInfo, 0);
            pConfigInfo->ExtmemSize =  PanoGetEnvInfo.StitchWorkingBufSize;
            pConfigInfo->MdpConfigFlag = KAL_FALSE;	    		    		  	    	
            pConfigInfo->IspConfigFlag = KAL_TRUE;
            pConfigInfo->FixAe = PpTuningOperPara.pano_fix_ae;
            pConfigInfo->FixAwb = PpTuningOperPara.pano_fix_awb;
            break;
        case PP_FEATURE_GET_RESULT:
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_GET_RESULT, NULL, pFeatureIn->pPanoResult, OutParaLen);
            break;	    		
        case PP_FEATURE_SET_LOG_INFO:	
            pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
        case PP_FEATURE_GET_OPMODE:	    
            pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_LOW;
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TIMER;
            PanoTimerProcInfo.TimerProcPeriod = 500;	    // ms
            PanoTimerProcInfo.TimerSuspPeriod = 20;		// ms
            pFeatureOut->pFuncOpMode->pTimerProcInfo = &PanoTimerProcInfo;
            break;	    	
	}
    return ErrorCode;
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpAutoCapFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{	
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;

	AUTOCAP_SET_ENV_INFO_STRUCT AutoCapSetEnvInfo; 
	AUTOCAP_GET_ENV_INFO_STRUCT AutoCapGetEnvInfo;

    switch(CtrlId)
    { 		
	    case PP_FEATURE_SET_ENABLE:	    
			pfAutoCapFunc->AutoCapOpen();	    	
			break;			
	    case PP_FEATURE_SET_DISABLE:	    				
			pfAutoCapFunc->AutoCapClose();	    						
	    	break;						
		case PP_FEATURE_GET_STATE:		
			pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
			break;
	    case PP_FEATURE_SET_ENV_INFO:	    	    	    	
			/* update working buffer */	    	
	    	gPpProcInfoPara.PpProcBufAddr = pFeatureIn->pConfigInfo->ExtmemStartAddress;	
	    	gPpProcInfoPara.PpProcBufSize = pFeatureIn->pConfigInfo->ExtmemSize;		    	
	    	gPpProcInfoPara.PpProcFmt = pFeatureIn->pConfigInfo->ImgFmtCurr;

			/* check Info */
			AutoCapSetEnvInfo.target_width = pFeatureIn->pConfigInfo->ImgWidth;
			AutoCapSetEnvInfo.target_height =pFeatureIn->pConfigInfo->ImgHeight; 
			AutoCapSetEnvInfo.image_format = pFeatureIn->pConfigInfo->ImgFmtCurr;
			AutoCapSetEnvInfo.autocap_tuning_data.tolerance_x = PpTuningOperPara.pano_tolerance_x;
			AutoCapSetEnvInfo.autocap_tuning_data.tolerance_y = PpTuningOperPara.pano_tolerance_y;
            AutoCapSetEnvInfo.dir_decided = gPanoStitchDirDecided;
			pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_SET_ENV_INFO, &AutoCapSetEnvInfo, NULL, 0);
			break;
	    case PP_FEATURE_GET_ENV_INFO:	    	    	    				
			pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_GET_ENV_INFO, NULL, &AutoCapGetEnvInfo, 0);		
			pConfigInfo->ImgFmtCurr = AutoCapGetEnvInfo.SrcImgFormat;
			pConfigInfo->ExtmemSize = AutoCapGetEnvInfo.WorkingBufSize;
			pConfigInfo->MdpConfigFlag=KAL_TRUE;
			pConfigInfo->ImgWidth = AutoCapGetEnvInfo.ImageWidth;	    	
			pConfigInfo->ImgHeight = AutoCapGetEnvInfo.ImageHeight;	    	
			pConfigInfo->MaxImgWidth = AUTOCAP_IMAGE_XS;	    	
			pConfigInfo->MaxImgHeight = AUTOCAP_IMAGE_YS;	  	    	
			pConfigInfo->IspConfigFlag = KAL_TRUE;
            pConfigInfo->FixAe = PpTuningOperPara.pano_fix_ae;
            pConfigInfo->FixAwb = PpTuningOperPara.pano_fix_awb;
	    	break;			
	    case PP_FEATURE_GET_RESULT:
	    	pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_GET_RESULT, NULL, pFeatureIn->pAutoCapResult, OutParaLen);
	    	break;
	    case PP_FEATURE_SET_LOG_INFO:
	        pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
	    case PP_FEATURE_GET_OPMODE:	    
			pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_HIGH;
			pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TRIGGER;	    	
	    	break;	    	
	}
    return ErrorCode;	
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpHdrFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{	
#if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;    
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;        

    /* Set/Get Env Info */
    HDR_SET_INFO_STRUCT	HdrSetEnvInfo;
    HDR_GET_INFO_STRUCT	HdrGetEnvInfo;
    HDR_TUNING_PARA_STRUCT HdrTuningPara;
    static PP_TIMER_PROC_INFO_STRUCT HdrTimerProcInfo = {0};
    
    switch(CtrlId)
    { 		
        case PP_FEATURE_SET_ENABLE:	    
            pfHdrFunc->HdrOpen();
            break;			
        case PP_FEATURE_SET_DISABLE:
            pfHdrFunc->HdrClose();
            break;	
        case PP_FEATURE_GET_STATE:		
        	pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);
        	break;
        case PP_FEATURE_SET_ENV_INFO:	    	    	    	
            /* check Info */
            HdrSetEnvInfo.SrcImgFormat = (MM_IMAGE_FORMAT_ENUM)pFeatureIn->pConfigInfo->ImgFmtCurr;            
            HdrSetEnvInfo.Width = (kal_uint16)pFeatureIn->pConfigInfo->ImgWidth;
            HdrSetEnvInfo.Height = (kal_uint16)pFeatureIn->pConfigInfo->ImgHeight;
            HdrSetEnvInfo.WorkingBufSize= pFeatureIn->pConfigInfo->ExtmemSize;
            pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_SET_ENV_INFO, &HdrSetEnvInfo, NULL, 0);

            HdrTuningPara.HdrLevel = (HDR_LEVEL_ENUM)(PpTuningOperPara.hdr_level);
            HdrTuningPara.HdrMinBa = PpTuningOperPara.hdr_min_ba;
            HdrTuningPara.HdrSatLevel = PpTuningOperPara.hdr_sat_level;
            pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_UPDATE_TUNING, &HdrTuningPara, NULL, 0);
            break;			
	    case PP_FEATURE_GET_ENV_INFO:	    	    	    				
            pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_GET_ENV_INFO, NULL, &HdrGetEnvInfo, 0);
            pFeatureOut->pConfigInfo->ImgFmtCurr = HdrGetEnvInfo.SrcImgFormat;
	    pFeatureOut->pConfigInfo->ImgWidth = HdrGetEnvInfo.Width;
	    pFeatureOut->pConfigInfo->ImgHeight = HdrGetEnvInfo.Height;
            pFeatureOut->pConfigInfo->ExtmemSize= HdrGetEnvInfo.WorkingBufSize;
	    break;				    				            
        case PP_FEATURE_GET_RESULT:
            pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_GET_RESULT, NULL, pFeatureIn->pHdrResult, OutParaLen);
            break;	    		    	
        case PP_FEATURE_GET_OPMODE:	    
            pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_LOW;
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TIMER;
            HdrTimerProcInfo.TimerProcPeriod = 500;	    // ms
            HdrTimerProcInfo.TimerSuspPeriod = 20;		// ms
            pFeatureOut->pFuncOpMode->pTimerProcInfo = &HdrTimerProcInfo;
            break;	    	
	}
    return ErrorCode;	
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpAsdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
#if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;

    ASD_GET_ENV_INFO_STRUCT AsdGetEnvInfo;
    ASD_SET_ENV_INFO_STRUCT AsdSetEnvInfo;
    DECIDER_INIT_STRUCT DeciderInitInfo;
    DECIDER_REF_STRUCT  *pDeciderRefData;
    DECIDER_TUNING_PARA_STRUCT *pDeciderTuneData;

    P_ASD_PROCESS_STRUCT pAsdProcessInfo;    

    switch(CtrlId)
    {
        case PP_FEATURE_SET_ENABLE:
            pfAsdFunc->AsdOpen();
            break;
        case PP_FEATURE_SET_DISABLE:            
            pfAsdFunc->AsdClose();
            break;
        case PP_FEATURE_GET_STATE:
            //pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_GET_ASD_STATE, NULL, pFeatureOut->pFuncState, 0);
            break;
        case PP_FEATURE_SET_ENV_INFO:
            // set scd env info
            AsdSetEnvInfo.image_width = pFeatureIn->pConfigInfo->ImgWidth;
            AsdSetEnvInfo.image_height = pFeatureIn->pConfigInfo->ImgHeight;
            AsdSetEnvInfo.ImgFmtList = pFeatureIn->pConfigInfo->ImgFmtList;
            AsdSetEnvInfo.ext_mem_start_addr = pFeatureIn->pConfigInfo->ExtmemStartAddress;
            AsdSetEnvInfo.ext_mem_size = pFeatureIn->pConfigInfo->ExtmemSize;
            //AsdSetEnvInfo.asd_tuning_data.num_of_ort = PpTuningOperPara.asd_num_of_ort;   // fixed to 4 in ASD core
            pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_SCD_ENV_INFO, &AsdSetEnvInfo, NULL, 0);

            // set decider env info
            pDeciderRefData = &DeciderInitInfo.DeciderRefData;
            pDeciderRefData->DeciderInfoVer = (pFeatureIn->pConfigInfo->AaaInfoFromRaw)? (DECIDER_INFO_SRC_FP_RAW):(DECIDER_INFO_SRC_YUV);
            pDeciderRefData->RefAwbD65Rgain = pFeatureIn->pConfigInfo->AwbRefD65Rgain;
            pDeciderRefData->RefAwbD65Bgain = pFeatureIn->pConfigInfo->AwbRefD65Bgain;
            pDeciderRefData->RefAwbCwfRgain = pFeatureIn->pConfigInfo->AwbRefCwfRgain;
            pDeciderRefData->RefAwbCwfBgain = pFeatureIn->pConfigInfo->AwbRefCwfBgain;
            pDeciderRefData->RefAfTbl = pFeatureIn->pConfigInfo->AfTblParam;        // AF_LUT_FP_STRUCT

            pDeciderTuneData = &DeciderInitInfo.DeciderTuneData;
            pDeciderTuneData->TimeWeightType = (ASD_DECIDER_TIME_WEIGHT_TYPE_ENUM) (PpTuningOperPara.asd_decider_time_weight_type);
            pDeciderTuneData->TimeWeightRange= (ASD_DECIDER_TIME_WEIGHT_RANGE_ENUM) (PpTuningOperPara.asd_decider_time_weight_range);
            pDeciderTuneData->IdxWeightBlAe = PpTuningOperPara.asd_idx_weight_bl_ae;
            pDeciderTuneData->IdxWeightBlScd = PpTuningOperPara.asd_idx_weight_bl_scd;
            pDeciderTuneData->IdxWeightLsAe = PpTuningOperPara.asd_idx_weight_ls_ae;
            pDeciderTuneData->IdxWeightLsAwb = PpTuningOperPara.asd_idx_weight_ls_awb;
            pDeciderTuneData->IdxWeightLsAf = PpTuningOperPara.asd_idx_weight_ls_af;
            pDeciderTuneData->IdxWeightLsScd = PpTuningOperPara.asd_idx_weight_ls_scd;
            pDeciderTuneData->EvLoThrNight = PpTuningOperPara.asd_ev_lo_thr_night;
            pDeciderTuneData->EvHiThrNight = PpTuningOperPara.asd_ev_hi_thr_night;
            pDeciderTuneData->EvLoThrOutdoor = PpTuningOperPara.asd_ev_lo_thr_outdoor;
            pDeciderTuneData->EvHiThrOutdoor = PpTuningOperPara.asd_ev_hi_thr_outdoor;
            pDeciderTuneData->ScoreThrNight = PpTuningOperPara.asd_score_thr_night;
            pDeciderTuneData->ScoreThrBacklit = PpTuningOperPara.asd_score_thr_backlit;
            pDeciderTuneData->ScoreThrPortrait = PpTuningOperPara.asd_score_thr_portrait;            
            pDeciderTuneData->ScoreThrLandscape = PpTuningOperPara.asd_score_thr_landscape;
            pDeciderTuneData->BacklitLockEnable = PpTuningOperPara.asd_backlit_lock_enable;
            pDeciderTuneData->BacklitLockEvDiff = PpTuningOperPara.asd_backlit_lock_ev_diff;               
            pDeciderTuneData->bReserved = KAL_FALSE;
            pDeciderTuneData->pReserved = NULL;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_AUTO]=ASD_DECIDER_UI_AUTO;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_N   ]=ASD_DECIDER_UI_N;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_B   ]=ASD_DECIDER_UI_B;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_P   ]=ASD_DECIDER_UI_P;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_L   ]=ASD_DECIDER_UI_L;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NB  ]=ASD_DECIDER_UI_N;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NP  ]=ASD_DECIDER_UI_NP;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NL  ]=ASD_DECIDER_UI_N;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_BP  ]=ASD_DECIDER_UI_BP;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_BL  ]=ASD_DECIDER_UI_B;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_PL  ]=ASD_DECIDER_UI_P;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NBP ]=ASD_DECIDER_UI_NP;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NBL ]=ASD_DECIDER_UI_N;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NPL ]=ASD_DECIDER_UI_NP;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_BPL ]=ASD_DECIDER_UI_BP;
            pDeciderTuneData->UiSceneLut[ASD_DECIDER_UI_NBPL]=ASD_DECIDER_UI_NP;
            pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_DECIDER_ENV_INFO, &DeciderInitInfo, NULL, 0);
            break;
        case PP_FEATURE_GET_ENV_INFO:
            pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_GET_ASD_ENV_INFO, NULL, &AsdGetEnvInfo, 0);
            pFeatureOut->pConfigInfo->ExtmemSize = AsdGetEnvInfo.WorkingBufSize;
            pFeatureOut->pConfigInfo->MdpConfigFlag=KAL_TRUE;
            pFeatureOut->pConfigInfo->IspConfigFlag=KAL_FALSE;
            break;
        case PP_FEATURE_GET_RESULT:
            pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_GET_ASD_RESULT, NULL, &(pFeatureOut->pAsdResult->AsdScene), OutParaLen);
            break;
        case PP_FEATURE_SET_LOG_INFO:
//            pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
        case PP_FEATURE_GET_OPMODE:
            pAsdProcessInfo = (P_ASD_PROCESS_STRUCT) pInPara;
            if(ASD_PROC_DECIDER==pAsdProcessInfo->ProcId)
            {
                pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_HIGH;  // Decider run at cal
            }
            else //if(ASD_PROC_MAIN==pAsdProcessInfo->ProcId)
            {
                pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_LOW;  // Scd run at cal_low                
            }
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TRIGGER;
            pFeatureOut->pFuncOpMode->pTimerProcInfo = NULL;
            break;
    }
    return ErrorCode;
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpMavCapFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{	
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;

    MAVCAP_GET_ENV_INFO_STRUCT MavCapGetEnvInfo;
    MAVCAP_SET_ENV_INFO_STRUCT MavCapSetEnvInfo;
    MAVCAP_TUNING_PARA_STRUCT MavCapTuningPara;
	    
    switch(CtrlId)
    { 		
        case PP_FEATURE_SET_ENABLE:	    
            pfMavCapFunc->MavCapOpen();         
            break;			
        case PP_FEATURE_SET_DISABLE:	    				
            pfMavCapFunc->MavCapClose();	    						
            break;						
        case PP_FEATURE_GET_STATE:		
            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
            break;
        case PP_FEATURE_SET_ENV_INFO:	 
            /* update working buffer */         
            gPpProcInfoPara.PpProcBufAddr = pFeatureIn->pConfigInfo->ExtmemStartAddress;	
            gPpProcInfoPara.PpProcBufSize = pFeatureIn->pConfigInfo->ExtmemSize;		    	

            // set tuning data
            MavCapTuningPara.tolerance_x = PpTuningOperPara.mavcap_tolerance_x;
            MavCapTuningPara.tolerance_y = PpTuningOperPara.mavcap_tolerance_y;     
            MavCapTuningPara.MaxMV = PpTuningOperPara.mavcap_MaxMV;
            MavCapTuningPara.StepLB= PpTuningOperPara.mavcap_StepLB;
            MavCapTuningPara.StepUB= PpTuningOperPara.mavcap_StepUB;       

	    // camera gyro
	    #ifdef __CAMERA_GYRO_SUPPORT__
	    if(gMavEnableGyro)
	    {
		MavCapTuningPara.tolerance_x = PpTuningOperPara.mavcap_tolerance_x;
		MavCapTuningPara.tolerance_y = PpTuningOperPara.mavcap_tolerance_y; 	
                MavCapTuningPara.MaxMV = -1;	// flag for gyro
		MavCapTuningPara.StepLB= (-1)*PpTuningOperPara.mavcap_GyroMvBound;		// min dist
		MavCapTuningPara.StepUB= PpTuningOperPara.mavcap_GyroMvBound;  	// max dist
	    }
	    #endif

            // 3D image
            #ifdef __3D_IMAGE_SUPPORT__
            if(gMavEnable3D) 
            {
            MavCapTuningPara.tolerance_x = PpTuningOperPara.mavcap_tolerance_x;
            MavCapTuningPara.tolerance_y = PpTuningOperPara.mavcap_tolerance_y; 	
            MavCapTuningPara.MaxMV = 1;
            MavCapTuningPara.StepLB= 6;
            MavCapTuningPara.StepUB= 6;  
				#if defined(MT6250)				
	            MavCapTuningPara.StepLB >>= 1;
	            MavCapTuningPara.StepUB >>= 1;
				#endif
            }
            #endif

            /* check Info */
            MavCapSetEnvInfo.p_tuning_data = &MavCapTuningPara;                                                
            MavCapSetEnvInfo.target_width = pFeatureIn->pConfigInfo->ImgWidth;
            MavCapSetEnvInfo.target_height =pFeatureIn->pConfigInfo->ImgHeight; 
            MavCapSetEnvInfo.dir_decided = KAL_FALSE;            
            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_SET_ENV_INFO, &MavCapSetEnvInfo, NULL, 0);
            break;
        case PP_FEATURE_GET_ENV_INFO:	    	    	    				
            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_GET_ENV_INFO, NULL, &MavCapGetEnvInfo, 0);					
            pConfigInfo->ImgFmtCurr = MavCapGetEnvInfo.SrcImgFormat;
            pConfigInfo->ExtmemSize = MavCapGetEnvInfo.WorkingBufSize;    
            pConfigInfo->ImgWidth = MavCapGetEnvInfo.ImageWidth;	    	
            pConfigInfo->ImgHeight = MavCapGetEnvInfo.ImageHeight;	    	
            pConfigInfo->MaxImgWidth = MAVCAP_IMAGE_XS;	    	
            pConfigInfo->MaxImgHeight = MAVCAP_IMAGE_YS;	  	    	
            pConfigInfo->MdpConfigFlag=KAL_TRUE;
            pConfigInfo->IspConfigFlag = KAL_TRUE;            
            pConfigInfo->FixAe = KAL_TRUE;
            pConfigInfo->FixAwb = KAL_TRUE;
            break;			
        case PP_FEATURE_GET_RESULT:
            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_GET_RESULT, NULL, pFeatureIn->pMavCapResult, OutParaLen);
            break;
        case PP_FEATURE_SET_LOG_INFO:
            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
        case PP_FEATURE_GET_OPMODE:	    
            pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_HIGH;
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TRIGGER;	    	
            break;	    	
        default:            
            break;
    }
    return ErrorCode;	
#else
    return MM_ERROR_NONE;
#endif
}

MM_ERROR_CODE_ENUM PpMavFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{	
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureOut=(P_PP_FEATURE_CTRL_STRUCT_UNION) pOutPara;
    P_PP_FEATURE_CTRL_STRUCT_UNION pFeatureIn=(P_PP_FEATURE_CTRL_STRUCT_UNION) pInPara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT pConfigInfo = (P_PP_FEATURE_CONFIG_INFO_STRUCT) pFeatureOut->pConfigInfo;

    MAV_GET_ENV_INFO_STRUCT MavGetEnvInfo;
    MAV_SET_ENV_INFO_STRUCT MavSetEnvInfo;
    MavTuningInfo MavTuningPara;
    static PP_TIMER_PROC_INFO_STRUCT MavTimerProcInfo = {0};
    
    switch(CtrlId)
    { 		
        case PP_FEATURE_SET_ENABLE:	    
            pfMavFunc->MavOpen();         
            break;			
        case PP_FEATURE_SET_DISABLE:	    				
            pfMavFunc->MavClose();	    						
            break;						
        case PP_FEATURE_GET_STATE:		
            pfMavFunc->MavFeatureCtrl(MAV_FEATURE_GET_STATE, NULL, pFeatureOut->pFuncState, 0);					
            break;
        case PP_FEATURE_SET_ENV_INFO:	 
            // set tuning data
            MavTuningPara.RCWinBound = PpTuningOperPara.mav_RCWinBound;
            MavTuningPara.SearchRange= PpTuningOperPara.mav_SearchRange;
            MavTuningPara.MatchRate= PpTuningOperPara.mav_MatchRate;            
            MavTuningPara.RectErrThre= PpTuningOperPara.mav_RectErrThre;            
            MavTuningPara.IterNum = PpTuningOperPara.mav_IterNum;            
            MavTuningPara.MaxAngle= PpTuningOperPara.mav_MaxAngle;            
            MavTuningPara.ClipRatio= PpTuningOperPara.mav_ClipRatio;            
            			
			#ifdef __3D_IMAGE_SUPPORT__
			if(gMavEnable3D)
			{
				MavTuningPara.RCWinBound = 8;
				MavTuningPara.SearchRange = 20;
				MavTuningPara.MatchRate = 48;
				MavTuningPara.RectErrThre = 64;
				MavTuningPara.IterNum = 0; //30;
				MavTuningPara.MaxAngle = 10;
				MavTuningPara.ClipRatio = 154;
			}
			#endif
            
            /* get Info from cal */
            MavSetEnvInfo.pTuningInfo = &MavTuningPara;            
            MavSetEnvInfo.ImageWidth = pFeatureIn->pConfigInfo->ImgWidth;
            MavSetEnvInfo.ImageHeight = pFeatureIn->pConfigInfo->ImgHeight;
            MavSetEnvInfo.WorkingBuffAddr = pFeatureIn->pConfigInfo->ExtmemStartAddress;
            MavSetEnvInfo.WorkingBufSize = pFeatureIn->pConfigInfo->ExtmemSize;
            pfMavFunc->MavFeatureCtrl(MAV_FEATURE_SET_ENV_INFO, &MavSetEnvInfo, NULL, 0);
            break;
        case PP_FEATURE_GET_ENV_INFO:	    	    	    				
            pfMavFunc->MavFeatureCtrl(MAV_FEATURE_GET_ENV_INFO, NULL, &MavGetEnvInfo, 0);					
            pConfigInfo->ExtmemSize =  MavGetEnvInfo.WorkingBufSize;
            break;			
        case PP_FEATURE_GET_RESULT:
            pfMavFunc->MavFeatureCtrl(MAV_FEATURE_GET_RESULT, NULL, pFeatureIn->pMavResult, OutParaLen);
            break;
        case PP_FEATURE_SET_LOG_INFO:
            pfMavFunc->MavFeatureCtrl(MAV_FEATURE_SET_LOG_INFO, &pFeatureIn->pLogInfo->ExtmemStartAddress, pOutPara, OutParaLen);
            break;
        case PP_FEATURE_GET_OPMODE:	    
            pFeatureOut->pFuncOpMode->Priority = PP_PROC_PRIORITY_LOW;
            pFeatureOut->pFuncOpMode->Type = PP_PROC_TYPE_TIMER;

            MavTimerProcInfo.TimerProcPeriod = 500;	    // ms
            MavTimerProcInfo.TimerSuspPeriod = 20;	    // ms
            pFeatureOut->pFuncOpMode->pTimerProcInfo = &MavTimerProcInfo;                        
            break;	    	
        default:            
            break;
    }
    return ErrorCode;	
#else
    return MM_ERROR_NONE;
#endif

}

#endif
