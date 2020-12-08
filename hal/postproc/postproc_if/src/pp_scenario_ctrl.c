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
 *   pp_scenario_ctrl.c
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
#include "feature_comm_def.h"
#include "pp_api.h"
#include "pp_comm_def.h"
#include "pp_if.h"
#include "fd_if.h"
#include "sd_if.h"
#include "pano_if.h"
#include "hdr_if.h"
#include "hdr_core.h"
#include "autocap_if.h"
#include "asd_if.h"    
#include "asd_core.h"    
#include "mavcap_if.h"    
#include "MavMotionCore.h"
#include "mav_if.h"    
#include "mav_core.h"

/* extern Function Points */
extern P_FD_FUNCTION_STRUCT pfFdFunc;
extern P_SD_FUNCTION_STRUCT pfSdFunc;
extern P_PANO_FUNCTION_STRUCT pfPanoFunc;
extern P_HDR_FUNCTION_STRUCT pfHdrFunc;
extern P_AUTOCAP_FUNCTION_STRUCT pfAutoCapFunc;
extern P_ASD_FUNCTION_STRUCT pfAsdFunc;    
extern P_MAVCAP_FUNCTION_STRUCT pfMavCapFunc;    
extern P_MAV_FUNCTION_STRUCT pfMavFunc;    

PP_STATE_ENUM   gPpPreviewState = PP_STATE_READY;    

typedef union
{
    FD_SET_MEM_INFO_STRUCT			FdSetMemInfoPara;
    SD_SET_MEM_INFO_STRUCT			SdSetMemInfoPara;
    AUTOCAP_SET_MEM_INFO_STRUCT		AutoCapSetMemInfoPara;
    PANO_SET_PROC_INFO_STRUCT       PanoSetProcInfoPara;
    HDR_SET_PROC_INFO_STRUCT        HdrSetProcInfoPara;
    MAVCAP_SET_MEM_INFO_STRUCT         MavCapSetMemInfoPara;
    MAV_SET_PROC_INFO_STRUCT             MavSetProcInfoPara;
} PP_SET_PROC_STRUCT_UNION, *P_PP_SET_PROC_STRUCT_UNION;

/* global union set proc data except for bg postproc */
PP_SET_PROC_STRUCT_UNION gPpSetProcPara;

#if defined(__AUTO_SCENE_DETECT_SUPPORT__)
/* for ASD ctrl usage */
ASD_PROCESS_STRUCT gAsdMainParaIn;
ASD_PROCESS_STRUCT gAsdDeciderParaIn;
DECIDER_INFO_STRUCT gDeciderInfoPara;

ASD_PROC_AAA_PARA gAsdAaaPara;
ASD_RESULT_STRUCT gAsdScdResult;
FD_RESULT_STRUCT gAsdFdResult;

// mapping from fd result to asd input
const FD_FACE_POSE_ENUM FdPoseIndexLut[] =
{   // fd feature set idx = 1~12
    // 1,2,3 => FD_FACE_POSE_0
    // 4,6,8 => FD_FACE_POSE_90
    // 10,11,12 => FD_FACE_POSE_180
    // 5,7,9 => FD_FACE_POSE_270
    FD_FACE_POSE_NUM,
    FD_FACE_POSE_0, FD_FACE_POSE_0, FD_FACE_POSE_0, FD_FACE_POSE_90,
    FD_FACE_POSE_270, FD_FACE_POSE_90, FD_FACE_POSE_270, FD_FACE_POSE_90,
    FD_FACE_POSE_270, FD_FACE_POSE_180, FD_FACE_POSE_180, FD_FACE_POSE_180
};

/* for ASD scheduler usage */
const kal_uint8 PP_ASD_FD_PERIOD_MS_BASE = 30;
const kal_uint8 PP_ASD_DECIDER_PERIOD_FRAME = 3;
kal_uint8 PpAsdFrameCounter = 0;
kal_uint32 PpAsdTimeStick = 0;
kal_bool PpAsdScheDeciderOn = KAL_FALSE;
kal_bool PpAsdScheFdOn = KAL_FALSE;
kal_bool PpAsdScheScdOn = KAL_FALSE;

void PpAsdScheduler(P_ASD_PROC_AAA_PARA pAsdAaaPara,
                                        P_FD_RESULT_STRUCT pAsdFdResult, P_ASD_RESULT_STRUCT pAsdScdResult)
{
    PpAsdScheFdOn = PpAsdScheDeciderOn = PpAsdScheScdOn = KAL_FALSE;

    // trigger Fd ?
        pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_STATE, NULL, &gPpPreviewState, 0);
        if(PP_STATE_BUSY!=gPpPreviewState)
        {
        pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_RESULT, NULL, pAsdFdResult, 0);
        if(PP_ASD_FD_PERIOD_MS_BASE*PpTuningOperPara.asd_fd_frame_period < drv_get_duration_ms(PpAsdTimeStick))
        {
            PpAsdScheFdOn = KAL_TRUE;
        PpAsdTimeStick = drv_get_current_time();
    }
    }

    // trigger Scd ?
        pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_GET_SCD_STATUS, NULL, &gPpPreviewState, 0);
        if(PP_STATE_BUSY!=gPpPreviewState)
        {
        pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_GET_SCD_RESULT, NULL, pAsdScdResult, 0);
        if(pAsdAaaPara->AeIsStable)
        {
            PpAsdScheScdOn = KAL_TRUE;
	        pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_SCD_STATUS, NULL, NULL, 0);	// set asd to wait proc state
        }
    }    
   
    // trigger Decider ?
    if(PP_ASD_DECIDER_PERIOD_FRAME == (++PpAsdFrameCounter))
    {
        PpAsdScheDeciderOn = KAL_TRUE;
        PpAsdFrameCounter = 0;
}
}
#endif //__AUTO_SCENE_DETECT_SUPPORT__

MM_ERROR_CODE_ENUM PpPreviewCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_SCENARIO_CONF_IN_STRUCT_UNION pConfIn=(P_PP_SCENARIO_CONF_IN_STRUCT_UNION) pInPara;    		

	/* Send Message */
    P_FD_SET_MEM_INFO_STRUCT			pFdSetMemInfoPara = &gPpSetProcPara.FdSetMemInfoPara;
    P_SD_SET_MEM_INFO_STRUCT			pSdSetMemInfoPara = &gPpSetProcPara.SdSetMemInfoPara;
	#if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
    P_AUTOCAP_SET_MEM_INFO_STRUCT		pAutoCapSetMemInfoPara = &gPpSetProcPara.AutoCapSetMemInfoPara;
    #endif    
    #if defined(__AUTO_SCENE_DETECT_SUPPORT__)
    DECIDER_INFO_STRUCT* pAsdDeciderCtrlInfoPara = &gDeciderInfoPara;
    kal_bool AsdAbortFlag = KAL_FALSE;
    #endif
    #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
    P_MAVCAP_SET_MEM_INFO_STRUCT		pMavCapSetMemInfoPara = &gPpSetProcPara.MavCapSetMemInfoPara;
    #endif

	PP_PROC_REQ_STRUCT			PpProcReq;
	
    switch(CtrlId)
    { 	
    	case PP_CTRL_CODE_START:                
        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
                if(PP_IS_FEATURE_ENABLE(PP_FUNC_ASD))
                {
                        PP_SET_FEATURE_STATE(PP_FUNC_ASD, PP_STATE_BUSY);
                        PP_SET_FEATURE_STATE(PP_FUNC_FACE_DETECT, PP_STATE_BUSY);

                kal_mem_cpy(&gAsdAaaPara, (P_ASD_PROC_AAA_PARA)(pConfIn->pFuncProcParaIn->PpProcPara), sizeof(ASD_PROC_AAA_PARA));

                // update Fd/Scd result and do scheduling
                PpAsdScheduler(&gAsdAaaPara, &gAsdFdResult, &gAsdScdResult);

                        // trigger
                        if(PpAsdScheDeciderOn)
                    {   /* update 3a/fd/scd results to decider */
                            // 3a
                        pAsdDeciderCtrlInfoPara->InfoAaa.AeEv = gAsdAaaPara.AeEv;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AeFaceEnhanceEv= gAsdAaaPara.AeFaceEnhanceEv;    
                        pAsdDeciderCtrlInfoPara->InfoAaa.AeIsBacklit = gAsdAaaPara.AeIsBacklit;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AeIsStable = gAsdAaaPara.AeIsStable;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AwbCurRgain = gAsdAaaPara.AwbCurRgain;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AwbCurBgain = gAsdAaaPara.AwbCurBgain;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AwbIsStable = gAsdAaaPara.AwbIsStable;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AfPosition = gAsdAaaPara.AfPosition;
                        pAsdDeciderCtrlInfoPara->InfoAaa.AfIsStable = gAsdAaaPara.AfIsStable;
                            // fd
                        pAsdDeciderCtrlInfoPara->InfoFd.FdProcTimeStart = gAsdFdResult.fd_start_time;
                        pAsdDeciderCtrlInfoPara->InfoFd.FdProcTimeEnd = gAsdFdResult.fd_end_time;
                        pAsdDeciderCtrlInfoPara->InfoFd.FdFaceNum = gAsdFdResult.face_no;
                        if(gAsdFdResult.face_no >= 1)
                            {
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFaceLuma = gAsdFdResult.rect_lum[0];
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFaceX0 = gAsdFdResult.rect_x0[0];
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFaceX1 = gAsdFdResult.rect_x1[0];
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFaceY0 = gAsdFdResult.rect_y0[0];
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFaceY1 = gAsdFdResult.rect_y1[0];
                            pAsdDeciderCtrlInfoPara->InfoFd.FdMainFacePose = (kal_uint8)FdPoseIndexLut[gAsdFdResult.face_feature_set_index[0]];
                            }
                            // scd
                        pAsdDeciderCtrlInfoPara->InfoScd.ScdProcTimeStart = gAsdScdResult.asd_start_time;
                        pAsdDeciderCtrlInfoPara->InfoScd.ScdProcTimeEnd = gAsdScdResult.asd_end_time;
                        pAsdDeciderCtrlInfoPara->InfoScd.ScdScore[ASD_SCENE_LANDSCAPE] = gAsdScdResult.asd_score[ASD_SCENE_LANDSCAPE];
                        pAsdDeciderCtrlInfoPara->InfoScd.ScdScore[ASD_SCENE_BACKLIT] = gAsdScdResult.asd_score[ASD_SCENE_BACKLIT];                            
                    }
                    if(PpAsdScheDeciderOn||PpAsdScheScdOn)
                    {  /* trigger asd decider || copy buffer for scd */
                    gAsdDeciderParaIn.ProcId = ASD_PROC_DECIDER;
                        gAsdDeciderParaIn.pDeciderInfo = (PpAsdScheDeciderOn) ? pAsdDeciderCtrlInfoPara : NULL;
                        gAsdDeciderParaIn.src_buffer_addr = (PpAsdScheScdOn) ? pConfIn->pFuncProcParaIn->PpSrcBufAddr : NULL;         

                    // Send Func running at CAL task
                            PpProcReq.Func = pfAsdFunc->AsdCtrl;
                            PpProcReq.FuncId = PP_FUNC_ASD;
                            PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
                            PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                    PpProcReq.pParaIn = &gAsdDeciderParaIn;
                            PpProcReq.pParaOut = 0;
                            PpProcReq.ParaOutLen = 0;
                            pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                    }
                            if(PpAsdScheScdOn)
                    {   /* trigger asd scd */
                        AsdAbortFlag = KAL_FALSE;
                        pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_SCD_ABORT, &AsdAbortFlag, 0, 0);

                        // asd main run at low task
                        gAsdMainParaIn.ProcId = ASD_PROC_MAIN;
                                
                        //Send Func running at CAL_Low task
                            PpProcReq.Func = pfAsdFunc->AsdCtrl;
                            PpProcReq.FuncId = PP_FUNC_ASD;
                            PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
                            PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                        PpProcReq.pParaIn = &gAsdMainParaIn;
                            PpProcReq.pParaOut = 0;
                            PpProcReq.ParaOutLen = 0;
                            pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                        }
                        if(PpAsdScheFdOn)
                        {   /* get info and update source memory, add image buffer for ALG usagememory copy */
                        // fd main ; Send Func running at CAL task
                    pFdSetMemInfoPara->PpProcBufAddr = gPpProcInfoPara.PpProcBufAddr;
                    pFdSetMemInfoPara->PpProcBufSize = gPpProcInfoPara.PpProcBufSize;
                    pFdSetMemInfoPara->PpProcFmt = gPpProcInfoPara.PpProcFmt;
                    pFdSetMemInfoPara->PpSrcBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                    pFdSetMemInfoPara->PpSrcBufSize = pConfIn->pFuncProcParaIn->PpSrcBufSize;
                    pFdSetMemInfoPara->PpMemOpType =  PP_MEM_OP_COPY_TO_PROC_BUF;
                    pfFdFunc->FdFeatureCtrl(FD_FEATURE_SET_PROC_INFO, pFdSetMemInfoPara, 0, 0);
                            
                            PpProcReq.Func = pfFdFunc->FdCtrl;
                            PpProcReq.FuncId = PP_FUNC_FACE_DETECT;
                            PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
                            PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                            PpProcReq.pParaIn =  0;
                            PpProcReq.pParaOut = 0;
                            PpProcReq.ParaOutLen = 0;
                            pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                        }                    
                }
                else if(PP_IS_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT)&&PP_CHECK_FEATURE_STATE(PP_FUNC_FACE_DETECT, PP_STATE_BUSY))
        #else // !__AUTO_SCENE_DETECT_SUPPORT__
			if(PP_IS_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT)&&PP_CHECK_FEATURE_STATE(PP_FUNC_FACE_DETECT, PP_STATE_BUSY))
        #endif
			{	/* SD Process */				
				PP_SET_FEATURE_STATE(PP_FUNC_SMILE_DETECT, PP_STATE_BUSY);
		        // Check State				 
		        pfSdFunc->SdFeatureCtrl(SD_FEATURE_GET_STATE, NULL, &gPpPreviewState, 0);
		        if(gPpPreviewState!=PP_STATE_BUSY)
		        {	/* get info and update source memory, add image buffer copy for ALG usagememory copy */		        	
                    pSdSetMemInfoPara->PpProcBufAddr = gPpProcInfoPara.PpProcBufAddr;
                    pSdSetMemInfoPara->PpProcBufSize = gPpProcInfoPara.PpProcBufSize;
                    pSdSetMemInfoPara->PpProcFmt = gPpProcInfoPara.PpProcFmt;
                    pSdSetMemInfoPara->PpSrcBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                    pSdSetMemInfoPara->PpSrcBufSize = pConfIn->pFuncProcParaIn->PpSrcBufSize;
					#if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 
                    pSdSetMemInfoPara->PpMemOpType =  PP_MEM_OP_RESIZE_TO_PROC_BUF;
					#else
                    pSdSetMemInfoPara->PpMemOpType =  PP_MEM_OP_COPY_TO_PROC_BUF;
					#endif
                    pfSdFunc->SdFeatureCtrl(SD_FEATURE_SET_PROC_INFO, pSdSetMemInfoPara, 0, 0);
					/* Send message to CAL task */						
					PpProcReq.Func = pfSdFunc->SdCtrl;
					PpProcReq.FuncId = PP_FUNC_SMILE_DETECT;
					PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
					PpProcReq.CtrlCode = PP_CTRL_CODE_START;
					PpProcReq.pParaIn =  0;
					PpProcReq.pParaOut = 0;
					PpProcReq.ParaOutLen = 0;
					pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
				}
			}
			else if(PP_IS_FEATURE_ENABLE(PP_FUNC_FACE_DETECT))
			{	/* FD Process */				
				PP_SET_FEATURE_STATE(PP_FUNC_FACE_DETECT, PP_STATE_BUSY);
			    // Check State
			    pfFdFunc->FdFeatureCtrl(FD_FEATURE_GET_STATE, NULL, &gPpPreviewState, 0);
		        if(gPpPreviewState!=PP_STATE_BUSY)
		        {	/* get info and update source memory, add image buffer copy for ALG usagememory copy */	    	
                    pFdSetMemInfoPara->PpProcBufAddr = gPpProcInfoPara.PpProcBufAddr;
                    pFdSetMemInfoPara->PpProcBufSize = gPpProcInfoPara.PpProcBufSize;
                    pFdSetMemInfoPara->PpProcFmt = gPpProcInfoPara.PpProcFmt;
                    pFdSetMemInfoPara->PpSrcBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                    pFdSetMemInfoPara->PpSrcBufSize = pConfIn->pFuncProcParaIn->PpSrcBufSize;
					#if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 
                    pFdSetMemInfoPara->PpMemOpType =  PP_MEM_OP_RESIZE_TO_PROC_BUF;
					#else
                    pFdSetMemInfoPara->PpMemOpType =  PP_MEM_OP_COPY_TO_PROC_BUF;
					#endif
                    pfFdFunc->FdFeatureCtrl(FD_FEATURE_SET_PROC_INFO, pFdSetMemInfoPara, 0, 0);
					/* Send message to CAL task */						
					PpProcReq.Func = pfFdFunc->FdCtrl;
					PpProcReq.FuncId = PP_FUNC_FACE_DETECT;
					PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
					PpProcReq.CtrlCode = PP_CTRL_CODE_START;
					PpProcReq.pParaIn =  0;
					PpProcReq.pParaOut = 0;
					PpProcReq.ParaOutLen = 0;
					pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
				}
			}
			#if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
			else if(PP_IS_FEATURE_ENABLE(PP_FUNC_AUTOCAP_PANORAMA))
			{	/* AutoCap Process */				
				PP_SET_FEATURE_STATE(PP_FUNC_AUTOCAP_PANORAMA, PP_STATE_BUSY);
			    // Check State
			    pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_GET_STATE, NULL, &gPpPreviewState, 0);
		        if(gPpPreviewState!=PP_STATE_BUSY)
		        {	/* get info and update source memory, add image buffer copy for ALG usagememory copy */	    	
                    pAutoCapSetMemInfoPara->PpProcBufAddr = gPpProcInfoPara.PpProcBufAddr;
                    pAutoCapSetMemInfoPara->PpProcBufSize = gPpProcInfoPara.PpProcBufSize;
                    pAutoCapSetMemInfoPara->PpProcFmt = gPpProcInfoPara.PpProcFmt;
                    pAutoCapSetMemInfoPara->PpSrcBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                    pAutoCapSetMemInfoPara->PpSrcBufSize = pConfIn->pFuncProcParaIn->PpSrcBufSize;
					#if(defined(AUTOCAP_SOURCE_IMAGE_FROM_CRZ)) 
                    pAutoCapSetMemInfoPara->PpMemOpType =  PP_MEM_OP_RESIZE_TO_PROC_BUF;
					#else
                    pAutoCapSetMemInfoPara->PpMemOpType =  PP_MEM_OP_COPY_TO_PROC_BUF;
					#endif
                    pfAutoCapFunc->AutoCapFeatureCtrl(AUTOCAP_FEATURE_SET_PROC_INFO, pAutoCapSetMemInfoPara, 0, 0);
					/* Send message to CAL task */						
					PpProcReq.Func = pfAutoCapFunc->AutoCapCtrl;
					PpProcReq.FuncId = PP_FUNC_AUTOCAP_PANORAMA;
					PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
					PpProcReq.CtrlCode = PP_CTRL_CODE_START;
					PpProcReq.pParaIn =  0;
					PpProcReq.pParaOut = 0;
					PpProcReq.ParaOutLen = 0;
					pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
				}
			}
			#endif  
                    #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
                    else if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAVCAP))
                    {	/* MavCap Process */				
                            PP_SET_FEATURE_STATE(PP_FUNC_MAVCAP, PP_STATE_BUSY);
                            // Check State
                            pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_GET_STATE, NULL, &gPpPreviewState, 0);
                            if(gPpPreviewState!=PP_STATE_BUSY)
                            {  /* get info and update source memory, add image buffer copy for ALG usagememory copy */	    	
                                pMavCapSetMemInfoPara->PpProcBufAddr = gPpProcInfoPara.PpProcBufAddr;
                                pMavCapSetMemInfoPara->PpProcBufSize = gPpProcInfoPara.PpProcBufSize;
                                pMavCapSetMemInfoPara->PpProcFmt = gPpProcInfoPara.PpProcFmt;
                                pMavCapSetMemInfoPara->PpSrcBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                                pMavCapSetMemInfoPara->PpSrcBufSize = pConfIn->pFuncProcParaIn->PpSrcBufSize;                                
                                pMavCapSetMemInfoPara->PpMemOpType = PP_MEM_OP_COPY_TO_PROC_BUF;
                                pMavCapSetMemInfoPara->PpForceToShot = (kal_bool) (pConfIn->pFuncProcParaIn->PpProcPara);    // force to shot flag
                                pfMavCapFunc->MavCapFeatureCtrl(MAVCAP_FEATURE_SET_PROC_INFO, pMavCapSetMemInfoPara, 0, 0);
                                /* Send message to CAL task */						
                                PpProcReq.Func = pfMavCapFunc->MavCapCtrl;
                                PpProcReq.FuncId = PP_FUNC_MAVCAP;
                                PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
                                PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                                PpProcReq.pParaIn =  0;
                                PpProcReq.pParaOut = 0;
                                PpProcReq.ParaOutLen = 0;
                                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                            }
                     }
                     #endif  
		break;    	
    	case PP_CTRL_CODE_STOP:
			if(PP_IS_FEATURE_ENABLE(PP_FUNC_SMILE_DETECT))
			{	/* SD Process */
				PpFeatureCtrl(PP_FUNC_SMILE_DETECT, PP_FEATURE_SET_DISABLE,0, 0, 0);
				PP_SET_FEATURE_STATE(PP_FUNC_SMILE_DETECT, PP_STATE_STANDBY);				
			}	
			if(PP_IS_FEATURE_ENABLE(PP_FUNC_FACE_DETECT))
			{	/* FD Process */
				PpFeatureCtrl(PP_FUNC_FACE_DETECT, PP_FEATURE_SET_DISABLE,0, 0, 0);
				PP_SET_FEATURE_STATE(PP_FUNC_FACE_DETECT, PP_STATE_STANDBY);				
			}
                        #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
			if(PP_IS_FEATURE_ENABLE(PP_FUNC_AUTOCAP_PANORAMA))
			{	/* AutoCap Process */
				PpFeatureCtrl(PP_FUNC_AUTOCAP_PANORAMA, PP_FEATURE_SET_DISABLE,0, 0, 0);
				PP_SET_FEATURE_STATE(PP_FUNC_AUTOCAP_PANORAMA, PP_STATE_STANDBY);				
			}
                        #endif								            
            #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
                        if(PP_IS_FEATURE_ENABLE(PP_FUNC_ASD))
                        {	/* ASD Process */
                        if(!PP_CHECK_FEATURE_STATE(PP_FUNC_ASD, PP_STATE_STANDBY))
                        {
                            /* Asd Exit */
                            /* Send message to CAL_LOW task */
                            gAsdMainParaIn.ProcId = ASD_PROC_MAIN;
                            PpProcReq.Func = pfAsdFunc->AsdCtrl;
                            PpProcReq.FuncId = PP_FUNC_ASD;
                            PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
                            PpProcReq.CtrlCode = PP_CTRL_CODE_STOP;
                            PpProcReq.pParaIn = &gAsdMainParaIn;
                            PpProcReq.pParaOut = 0;
                            PpProcReq.ParaOutLen = 0;
                            pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                            /* wait asd stop complete */
                            PP_WAIT_EVENT(PP_EVENT_ASD_STOP_CNF);
                        }
                                PpFeatureCtrl(PP_FUNC_ASD, PP_FEATURE_SET_DISABLE,0, 0, 0);
                                PP_SET_FEATURE_STATE(PP_FUNC_ASD, PP_STATE_STANDBY);
                        }
            #endif //__AUTO_SCENE_DETECT_SUPPORT__
                #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
                    if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAVCAP))
                    {	/* MavCap Process */
                    	PpFeatureCtrl(PP_FUNC_MAVCAP, PP_FEATURE_SET_DISABLE,0, 0, 0);
                    	PP_SET_FEATURE_STATE(PP_FUNC_MAVCAP, PP_STATE_STANDBY);				
                    }
                #endif //__MULTIPLE_ANGLE_VIEW_SUPPORT__
		break;			
    	case PP_CTRL_CODE_RESET:
    	          #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
		  	if(PP_IS_FEATURE_ENABLE(PP_FUNC_ASD))
			{
				AsdAbortFlag = KAL_TRUE;
				pfAsdFunc->AsdFeatureCtrl(ASD_FEATURE_SET_SCD_ABORT, &AsdAbortFlag, 0, 0);
			}
    		        else if(PP_IS_FEATURE_ENABLE(PP_FUNC_FACE_DETECT))
		  #else
			if(PP_IS_FEATURE_ENABLE(PP_FUNC_FACE_DETECT))
		  #endif
			{	/* FD Process */
				PpProcReq.Func = pfFdFunc->FdCtrl;
				PpProcReq.FuncId = PP_FUNC_FACE_DETECT;
				PpProcReq.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
				PpProcReq.CtrlCode = PP_CTRL_CODE_RESET;
				PpProcReq.pParaIn =  0;
				PpProcReq.pParaOut = 0;
				PpProcReq.ParaOutLen = sizeof(FD_RESULT_STRUCT);	
				pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
			}								    		
		break;		
    	case PP_CTRL_CODE_PAUSE:
    	case PP_CTRL_CODE_RESUME:    	
		break;		    	
		default:
		break;
    }
    return ErrorCode;
} /* PpPreviewCtrl() */

MM_ERROR_CODE_ENUM PpCaptureCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
	
    switch(CtrlId)
    {
        case PP_CTRL_CODE_START:
		    break;
        case PP_CTRL_CODE_STOP:
            break;			
        case PP_CTRL_CODE_RESET:
            break;		
        case PP_CTRL_CODE_PAUSE:
            break;
        case PP_CTRL_CODE_RESUME:    	
            break;		    	
        default:
            break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM PpBgPostProcCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_SCENARIO_CONF_IN_STRUCT_UNION pConfIn=(P_PP_SCENARIO_CONF_IN_STRUCT_UNION) pInPara;

    /* Set Proc Info */
    PANO_SET_PROC_INFO_STRUCT   PanoSetProcInfoPara;

    /* Send Message */	
    PP_PROC_REQ_STRUCT			PpProcReq;
	
    switch(CtrlId)
    {
        case PP_CTRL_CODE_START:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {
                /* Pano Process */
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY);
                /* Pano Add Image */
                PanoSetProcInfoPara.WorkingBufAddr = pConfIn->pFuncProcParaIn->PpProcBufAddr;
                PanoSetProcInfoPara.WorkingBufSize = pConfIn->pFuncProcParaIn->PpProcBufSize;
                PanoSetProcInfoPara.PanoCtrl       = PANO_CTRL_ADD_IMAGE;
                PanoSetProcInfoPara.SrcImgAddr     = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                PanoSetProcInfoPara.SrcImgSize     = pConfIn->pFuncProcParaIn->PpSrcBufSize;
                #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                PanoSetProcInfoPara.EV             = (kal_int32)pConfIn->pFuncProcParaIn->PpProcPara;
                #endif
                pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_PROC_INFO, &PanoSetProcInfoPara, 0, 0);
                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfPanoFunc->PanoCtrl;
                PpProcReq.FuncId = PP_FUNC_PANORAMA;
                PpProcReq.ScenarioId = PP_SCENARIO_BG_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }				
		break;
        case PP_CTRL_CODE_STOP:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {   /* Pano Process */
                if(!PP_CHECK_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_STANDBY))
                {   
                    /* Pano Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfPanoFunc->PanoCtrl;
                    PpProcReq.FuncId = PP_FUNC_PANORAMA;
                    PpProcReq.ScenarioId = PP_SCENARIO_BG_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_STOP;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                    /* wait pano stop complete */
                    PP_WAIT_EVENT(PP_EVENT_PANO_STOP_CNF);
                }	
                PpFeatureCtrl(PP_FUNC_PANORAMA, PP_FEATURE_SET_DISABLE,0, 0, 0);
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_STANDBY);				
            }
            break;			
        case PP_CTRL_CODE_RESET:
            break;		
        case PP_CTRL_CODE_PAUSE:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {   /* Pano Process */
                if(PP_CHECK_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY))
                {   
                    /* Pano Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfPanoFunc->PanoCtrl;
                    PpProcReq.FuncId = PP_FUNC_PANORAMA;
                    PpProcReq.ScenarioId = PP_SCENARIO_BG_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_PAUSE;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                     /* wait pano pause complete */
                    PP_WAIT_EVENT(PP_EVENT_PANO_PAUSE_CNF);
                }							
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_PAUSE);				
            }
            break;
        case PP_CTRL_CODE_RESUME:    	
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {
                /* Pano Process */
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY);
                /* Pano Stitch */
                PanoSetProcInfoPara.WorkingBufAddr = pConfIn->pFuncProcParaIn->PpProcBufAddr;
                PanoSetProcInfoPara.WorkingBufSize = pConfIn->pFuncProcParaIn->PpProcBufSize;            
                PanoSetProcInfoPara.PanoCtrl = PANO_CTRL_ADD_IMAGE;
                pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_PROC_INFO, &PanoSetProcInfoPara, 0, 0);
                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfPanoFunc->PanoCtrl;
                PpProcReq.FuncId = PP_FUNC_PANORAMA;
                PpProcReq.ScenarioId = PP_SCENARIO_BG_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_RESUME;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }				
		break;		    	
        default:
            break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM PpPostProcCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_PP_SCENARIO_CONF_IN_STRUCT_UNION pConfIn=(P_PP_SCENARIO_CONF_IN_STRUCT_UNION) pInPara;    		
    
    /* Set Proc Info */
    P_PANO_SET_PROC_INFO_STRUCT   pPanoSetProcInfoPara = &gPpSetProcPara.PanoSetProcInfoPara;
    P_HDR_SET_PROC_INFO_STRUCT    pHdrSetProcInfoPara = &gPpSetProcPara.HdrSetProcInfoPara;
    P_MAV_SET_PROC_INFO_STRUCT   pMavSetProcInfoPara = &gPpSetProcPara.MavSetProcInfoPara;
    P_MAV_PROC_PARA pMavProcPara;

    /* Send Message */	
    PP_PROC_REQ_STRUCT			PpProcReq;
	
    switch(CtrlId)
    {
        case PP_CTRL_CODE_START:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_HDR))
            {
                /* Hdr Process */
                PP_SET_FEATURE_STATE(PP_FUNC_HDR, PP_STATE_BUSY);                

                pHdrSetProcInfoPara->SrcImgAddr= pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                pHdrSetProcInfoPara->SrcImgSize  = pConfIn->pFuncProcParaIn->PpSrcBufSize;
                pHdrSetProcInfoPara->WorkingBufAddr = pConfIn->pFuncProcParaIn->PpProcBufAddr;
                pHdrSetProcInfoPara->MaxWorkingBufSize = pConfIn->pFuncProcParaIn->PpProcBufSize;
                pfHdrFunc->HdrFeatureCtrl(HDR_FEATURE_SET_PROC_INFO, pHdrSetProcInfoPara, 0, 0);

                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfHdrFunc->HdrCtrl;
                PpProcReq.FuncId = PP_FUNC_HDR;
                PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {
                /* Pano Process */
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY);
                /* Pano Stitch */
                pPanoSetProcInfoPara->WorkingBufAddr = pConfIn->pFuncProcParaIn->PpProcBufAddr;
                pPanoSetProcInfoPara->WorkingBufSize = pConfIn->pFuncProcParaIn->PpProcBufSize;
                pPanoSetProcInfoPara->PanoCtrl = PANO_CTRL_STITCH;
                pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_PROC_INFO, pPanoSetProcInfoPara, 0, 0);
                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfPanoFunc->PanoCtrl;
                PpProcReq.FuncId = PP_FUNC_PANORAMA;
                PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }				
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAV))
            {
                /* Mav Process */
                PP_SET_FEATURE_STATE(PP_FUNC_MAV, PP_STATE_BUSY);
                pMavSetProcInfoPara->PpImgBufAddr = pConfIn->pFuncProcParaIn->PpSrcBufAddr;
                pMavSetProcInfoPara->PpImgBufSize= pConfIn->pFuncProcParaIn->PpSrcBufSize;
                
                pMavProcPara = (P_MAV_PROC_PARA)(pConfIn->pFuncProcParaIn->PpProcPara);
                {
                    int i;
                    for(i = 0; i < pMavProcPara->ProcImageNum ; i++)
                    {
                        pMavSetProcInfoPara->GlobalMotion[i][0] = (kal_int32)(pMavProcPara->GlobalMotion[i][0]);
                        pMavSetProcInfoPara->GlobalMotion[i][1] = (kal_int32)(pMavProcPara->GlobalMotion[i][1]);
                    }
                }
                pMavSetProcInfoPara->TotalImgNumber = pMavProcPara->ProcImageNum;
                pfMavFunc->MavFeatureCtrl(MAV_FEATURE_SET_PROC_INFO, pMavSetProcInfoPara, 0, 0);
                
                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfMavFunc->MavCtrl;
                PpProcReq.FuncId = PP_FUNC_MAV;
                PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_START;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }		
		break;
        case PP_CTRL_CODE_STOP:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_HDR))
            {   /* HDR Process */
                if(!PP_CHECK_FEATURE_STATE(PP_FUNC_HDR, PP_STATE_STANDBY))
                {   
                    /* Hdr Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfHdrFunc->HdrCtrl;
                    PpProcReq.FuncId = PP_FUNC_HDR;
                    PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_STOP;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                     /* wait hdr stop complete */                     
                     PP_WAIT_EVENT(PP_EVENT_HDR_STOP_CNF);                     
                }		
                PpFeatureCtrl(PP_FUNC_HDR, PP_FEATURE_SET_DISABLE,0, 0, 0);
                PP_SET_FEATURE_STATE(PP_FUNC_HDR, PP_STATE_STANDBY);				
            }
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {   /* Pano Process */
                if(!PP_CHECK_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_STANDBY))
                {   
                    /* Pano Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfPanoFunc->PanoCtrl;
                    PpProcReq.FuncId = PP_FUNC_PANORAMA;
                    PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_STOP;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                     /* wait pano stop complete */
                    PP_WAIT_EVENT(PP_EVENT_PANO_STOP_CNF);
                }		
                PpFeatureCtrl(PP_FUNC_PANORAMA, PP_FEATURE_SET_DISABLE,0, 0, 0);
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_STANDBY);				
            }
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_MAV))
            {   /* Mav Process */
                if(!PP_CHECK_FEATURE_STATE(PP_FUNC_MAV, PP_STATE_STANDBY))
                {   
                    /* Mav Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfMavFunc->MavCtrl;
                    PpProcReq.FuncId = PP_FUNC_MAV;
                    PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_STOP;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                     /* wait mav stop complete */
                    PP_WAIT_EVENT(PP_EVENT_MAV_STOP_CNF);
                }		
                PpFeatureCtrl(PP_FUNC_MAV, PP_FEATURE_SET_DISABLE,0, 0, 0);
                PP_SET_FEATURE_STATE(PP_FUNC_MAV, PP_STATE_STANDBY);				
            }
            break;			
        case PP_CTRL_CODE_RESET:
            break;		
        case PP_CTRL_CODE_PAUSE:
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {   /* Pano Process */
                if(PP_CHECK_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY))
                {   
                    /* Pano Exit */
                    /* Send message to CAL_LOW task */						
                    PpProcReq.Func = pfPanoFunc->PanoCtrl;
                    PpProcReq.FuncId = PP_FUNC_PANORAMA;
                    PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                    PpProcReq.CtrlCode = PP_CTRL_CODE_PAUSE;
                    PpProcReq.pParaIn = 0;
                    PpProcReq.pParaOut = 0;
                    PpProcReq.ParaOutLen = 0;
                    pfPpCb(PP_CBID_POSTPROC_STOP, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
                     /* wait pano pause complete */
                    PP_WAIT_EVENT(PP_EVENT_PANO_PAUSE_CNF);
                }							
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_PAUSE);				
            }
            break;
        case PP_CTRL_CODE_RESUME:    	
            if(PP_IS_FEATURE_ENABLE(PP_FUNC_PANORAMA))
            {
                /* Pano Process */
                PP_SET_FEATURE_STATE(PP_FUNC_PANORAMA, PP_STATE_BUSY);
                /* Pano Stitch */
                pPanoSetProcInfoPara->WorkingBufAddr = pConfIn->pFuncProcParaIn->PpProcBufAddr;
                pPanoSetProcInfoPara->WorkingBufSize = pConfIn->pFuncProcParaIn->PpProcBufSize;
                pPanoSetProcInfoPara->PanoCtrl = PANO_CTRL_STITCH;
                pfPanoFunc->PanoFeatureCtrl(PANO_FEATURE_SET_PROC_INFO, pPanoSetProcInfoPara, 0, 0);
                /* Send message to CAL_LOW task */						
                PpProcReq.Func = pfPanoFunc->PanoCtrl;
                PpProcReq.FuncId = PP_FUNC_PANORAMA;
                PpProcReq.ScenarioId = PP_SCENARIO_POSTPROC;
                PpProcReq.CtrlCode = PP_CTRL_CODE_RESUME;
                PpProcReq.pParaIn = 0;
                PpProcReq.pParaOut = 0;
                PpProcReq.ParaOutLen = 0;
                pfPpCb(PP_CBID_POSTPROC_START, &PpProcReq, sizeof(PP_PROC_REQ_STRUCT));
            }				
		break;		    	
        default:
            break;
    }
    return ErrorCode;
}
#endif
