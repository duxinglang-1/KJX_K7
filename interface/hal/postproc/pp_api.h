/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	pp_api.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for post process api.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PP_API_H__
#define __PP_API_H__

#include "mm_comm_def.h"
#include "pp_comm_def.h"
#include "fd_comm_def.h"
#include "sd_comm_def.h"
#include "pano_comm_def.h"
#include "hdr_comm_def.h"
#include "autocap_comm_def.h"
#include "asd_comm_def.h"     
#include "mavcap_comm_def.h"
#include "mav_comm_def.h"
#include "app_ltlcom.h"

/* 0. PP request message structure */
typedef MM_ERROR_CODE_ENUM (* PPCtrlType) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);

typedef struct
{
    LOCAL_PARA_HDR
    PPCtrlType Func;    /* 1. func ptr */
    kal_uint32 FuncId;			/* 2. feature id */    
    PP_SCENARIO_ENUM ScenarioId;	/* 3. scenario id */
    PP_SCENARIO_CTRL_ENUM CtrlCode;	         /* 4. control code */
    void *pParaIn;					/* 5. parameter in defined by pp function */
    void *pParaOut;					/* 6. parameter out defined by pp function*/
    kal_uint16 ParaOutLen;	
} PP_PROC_REQ_STRUCT, *P_PP_PROC_REQ_STRUCT;	

/* 1. PpCtrl related structure */
typedef struct
{
	kal_uint32			PpSrcBufAddr;
	kal_uint32 			PpSrcBufSize;	
	kal_uint32			PpProcBufAddr;
	kal_uint32 			PpProcBufSize;						
	MM_IMAGE_FORMAT_ENUM	PpProcFmt;			
        // Para which customized for different algorithm	
	void *PpProcPara;    
} PP_PROC_INFO_STRUCT, *P_PP_PROC_INFO_STRUCT;

typedef union
{   	
	P_PP_PROC_INFO_STRUCT   pFuncProcParaIn;
} PP_SCENARIO_CONF_IN_STRUCT_UNION, *P_PP_SCENARIO_CONF_IN_STRUCT_UNION;

typedef union
{    
	MM_ERROR_CODE_ENUM	ErrorCode;
} PP_SCENARIO_CONF_OUT_STRUCT_UNION, *P_PP_SCENARIO_CONF_OUT_STRUCT_UNION;

/* 2. PpFeatureCtrl related structure */

/* ------ PP_FEATURE_GET_OPMODE ------	*/
typedef enum
{
    PP_PROC_PRIORITY_HIGH=0,
    PP_PROC_PRIORITY_LOW,
    PP_PROC_PRIORITY_MAX    
} PP_PROC_PRIORITY_ENUM;

typedef enum
{
    PP_PROC_TYPE_TIMER=0,
    PP_PROC_TYPE_TRIGGER,
    PP_PROC_TYPE_CONTINUOUS,    
    PP_PROC_TYPE_MAX
} PP_PROC_TYPE_ENUM;

typedef struct
{
    PPCtrlType      Func;    
    kal_uint32      FuncId;	
    PP_SCENARIO_ENUM      ScenarioId;	
    PP_SCENARIO_CTRL_ENUM      CtrlCode;	       
    void            *pParaIn;					
    void            *pParaOut;				
    kal_uint16      ParaOutLen;	
    kal_uint8       TimerId;   
    kal_uint32      TimerProcPeriod;
    kal_uint32      TimerSuspPeriod;
} PP_TIMER_PROC_INFO_STRUCT, *P_PP_TIMER_PROC_INFO_STRUCT;

typedef struct
{
	PP_PROC_PRIORITY_ENUM		Priority;
	PP_PROC_TYPE_ENUM			Type;
	P_PP_TIMER_PROC_INFO_STRUCT pTimerProcInfo;
} PP_FEATURE_GET_OPMODE_STRUCT, *P_PP_FEATURE_GET_OPMODE_STRUCT;

/* ------ PP_FEATURE_SET(GET)_ENV_INFO ------	*/
typedef struct
{
	kal_uint32 		PostProcMode;
	/* External memory config */
	kal_uint32 		ExtmemStartAddress;		/* external memroy start address for algorithm engine buffer */
	kal_uint32 		ExtmemSize;	/* external memory size for algorithm engine buffer */
	MM_IMAGE_FORMAT_ENUM	ImgFmtCurr;		
	/* MDP config */
	kal_bool        MdpConfigFlag;
	kal_uint32		ImgWidth;
	kal_uint32		ImgHeight;	
	kal_uint32		MaxImgWidth;
	kal_uint32		MaxImgHeight;	
	kal_uint32		ImgFmtList;		
	/* ISP config */
	kal_bool        IspConfigFlag;
	kal_bool        FixAe;
	kal_bool        FixAwb;
       /* 3A reference info to PP */
       kal_bool AaaInfoFromRaw;    /* Raw or Yuv 3A */
       kal_uint16 AwbRefD65Rgain;  /* D65 R channel gain */
       kal_uint16 AwbRefD65Bgain;  /* D65 B channel gain */
       kal_uint16 AwbRefCwfRgain;  /* CWF R channel gain */
       kal_uint16 AwbRefCwfBgain;  /* CWF B channel gain */
       void  *AfTblParam;      /* the whole AF table including macro index & total number of the table */
} PP_FEATURE_CONFIG_INFO_STRUCT, *P_PP_FEATURE_CONFIG_INFO_STRUCT;

/* ------ PP_FEATURE_SET_LOG_INFO ------	*/
typedef struct
{
    PP_SCENARIO_ENUM ScenarioId;
    kal_uint32 ExtmemStartAddress;
    kal_uint32 ExtmemSize;
} PP_LOG_INFO_STRUCT, *P_PP_LOG_INFO_STRUCT; 

/* ------ PpFeatureCtrl related structure union ------	*/
typedef union
{
	/* PP_FEATURE_SET_SENSOR_IDX*/	
	kal_uint32								SensorIdx;
	/* PP_FEATURE_SET_LOG_INFO */
	P_PP_LOG_INFO_STRUCT                    pLogInfo;
	/* PP_FEATURE_GET_STATE*/	
	PP_STATE_ENUM							*pFuncState;			
	/* PP_FEATURE_GET_OPMODE */
	P_PP_FEATURE_GET_OPMODE_STRUCT			pFuncOpMode;	
	/* PP_FEATURE_SET_ENV_INFO / PP_FEATURE_GET_ENV_INFO (common) */
	P_PP_FEATURE_CONFIG_INFO_STRUCT			pConfigInfo;
	/* PP_FEATURE_SET_ENV_INFO (panorama) */
	P_PANO_SET_INFO_STRUCT                  pPanoSetEnvInfo;					
	/* PP_FEATURE_GET_RESULT */
	P_FD_RESULT_STRUCT						pFdResult;		
	P_SD_RESULT_STRUCT						pSdResult;
	P_PANO_RESULT_STRUCT                    pPanoResult;
	P_HDR_RESULT_STRUCT						pHdrResult;		
        P_AUTOCAP_RESULT_STRUCT                 pAutoCapResult;		
        P_ASD_FINAL_RESULT_STRUCT		pAsdResult;  
        P_MAVCAP_RESULT_STRUCT      pMavCapResult;
        P_MAV_RESULT_STRUCT     pMavResult;
} PP_FEATURE_CTRL_STRUCT_UNION, *P_PP_FEATURE_CTRL_STRUCT_UNION;

/* Post Process Exposed API */
MM_ERROR_CODE_ENUM PpOpen(MM_ERROR_CODE_ENUM (* pPplback) (	
							PP_CALLBACK_ID_ENUM CbId, void *pPplbackPara, kal_uint16 PplbackParaLen));
MM_ERROR_CODE_ENUM PpCtrl(PP_SCENARIO_ENUM PpScenarioCtrl, PP_SCENARIO_CTRL_ENUM CtrlId, void *pPpInPara,
                           void *pPpOutPara, kal_uint32 PpOutParaLen);
MM_ERROR_CODE_ENUM PpFeatureCtrl(PP_FUNC_ENUM FuncId, PP_FEATURE_ENUM PpFeatureCtrl, void *pPpInPara,
                           void *pPpOutPara, kal_uint32 PpOutParaLen);                           
MM_ERROR_CODE_ENUM PpClose(void);
#endif /* __CAL_API_H__ */

