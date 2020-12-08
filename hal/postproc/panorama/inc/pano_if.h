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
 *  pano_if.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for Panorama Control Interface.
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
#ifndef __PANO_IF_H__
#define __PANO_IF_H__

#include "pp_comm_def.h"
#include "mm_comm_def.h"

/****************************************************************************
 *          Pano Process Macro
 ****************************************************************************/
#define PANORAMA_VIEW_VERSION 201101

/****************************************************************************
 *          Pano Process Data Structure
 ****************************************************************************/
/* internal control state */
typedef enum
{
    PANO_IDLE_STATE = 0,		// before initialize state
    PANO_ADD_IMAGE_STATE,		// add images for pano algo
    PANO_ADD_IMAGE_READY_STATE,	// add images for pano algo	
    PANO_STITCH_STATE,			// initialize for stitch
	PANO_STITCH_READY_STATE,			// finish panorama process
    PANO_RESET_STATE,			// Pano reset state
} PANO_STATE_ENUM;

/* control state for ppi */
typedef enum
{
    PANO_STATE_IDLE,        // PANO driver is closed
    PANO_STATE_STANDBY, // PANO driver is opened
    PANO_STATE_READY,       // PANO driver is waiting data for processing
    PANO_STATE_BGSTITCH,    // PANO driver in background stitch
    PANO_STATE_PROCESSING,     // PANO driver in stitch processing
    PANO_STATE_STITCH_DONE,
    PANO_STATE_PAUSE
} PANO_STATUS_ENUM; 

/* PANORAMA features */
typedef enum
{
    PANO_FEATURE_GET_ENV_INFO,
    PANO_FEATURE_SET_ENV_INFO,    
    PANO_FEATURE_SET_PROC_INFO,
    PANO_FEATURE_GET_STATE,
    PANO_FEATURE_GET_RESULT,
    PANO_FEATURE_SET_LOG_INFO,
    PANO_FEATURE_MAX
} PANO_FEATURE_ENUM;

/* panorama control enum */
typedef enum
{
    PANO_CTRL_ADD_IMAGE,
    PANO_CTRL_STITCH,
    PANO_CTRL_MAX
} PANO_CTRL_ENUM;

typedef struct
{
    PANO_CTRL_ENUM  PanoCtrl; /* PANO_CTRL_ADD_IMAGE, PANO_CTRL_STITCH */    
    kal_uint32  WorkingBufAddr; /* diff by PANO_CTRL_ENUM */
    kal_uint32  WorkingBufSize;
    kal_uint32  SrcImgAddr;     
    kal_uint32  SrcImgSize;
} PANO_SET_PROC_INFO_STRUCT, *P_PANO_SET_PROC_INFO_STRUCT;

typedef struct
{
    MM_ERROR_CODE_ENUM (* PanoOpen)(void);
    MM_ERROR_CODE_ENUM (* PanoFeatureCtrl) (PANO_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* PanoCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* PanoClose)(void);
} PANO_FUNCTION_STRUCT, *P_PANO_FUNCTION_STRUCT;

MM_ERROR_CODE_ENUM PanoInit(MM_ERROR_CODE_ENUM (* pfPanoCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_PANO_FUNCTION_STRUCT *pfPanoFunc);

#endif /* __PANO_IF_H__ */
