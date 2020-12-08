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
 *   autocap_if.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   autocap process header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _AUTOCAP_IF_H_
#define _AUTOCAP_IF_H_

#include "pp_comm_def.h"
#include "mm_comm_def.h"
#include "autocap_comm_def.h"
#include "pp_if.h"

typedef enum
{
    AUTOCAP_IDLE_STATE=0,
    AUTOCAP_CONFIG_STATE,
    AUTOCAP_READY_STATE,
    AUTOCAP_MEM_PROCESS_STATE,
    AUTOCAP_PROCESS_STATE
} AUTOCAP_STATE_ENUM;

typedef enum
{
    AUTOCAP_FEATURE_BEGIN,
    AUTOCAP_FEATURE_GET_ENV_INFO,
    AUTOCAP_FEATURE_SET_ENV_INFO,
    AUTOCAP_FEATURE_SET_PROC_INFO,
    AUTOCAP_FEATURE_GET_STATE,
    AUTOCAP_FEATURE_GET_RESULT,
    AUTOCAP_FEATURE_SET_LOG_INFO,
    AUTOCAP_FEATURE_MAX
}	AUTOCAP_FEATURE_ENUM;

typedef struct
{
    kal_uint16  ImageWidth;               // processing image width
    kal_uint16  ImageHeight;              // processing image height
    kal_uint32  WorkingBufSize;           // required working buffer size
    MM_IMAGE_FORMAT_ENUM SrcImgFormat;    // supported input image format, currently only RGB565 is supported.
} AUTOCAP_GET_ENV_INFO_STRUCT, *P_AUTOCAP_GET_ENV_INFO_STRUCT;

typedef struct
{
    kal_uint16 target_width;                        // lcd width
    kal_uint16 target_height;                       // lcd height
    MM_IMAGE_FORMAT_ENUM image_format;                // image format RGB565 or YUV420
    AUTOCAP_TUNING_PARA_STRUCT autocap_tuning_data; //tunning parameters
    kal_bool dir_decided;                           // if true, this is not the first autocap image and driver only refreshs mv, and keeps direction
} AUTOCAP_SET_ENV_INFO_STRUCT, *P_AUTOCAP_SET_ENV_INFO_STRUCT;

typedef struct
{
    kal_uint32  PpSrcBufAddr;              // source image address
    kal_uint32  PpSrcBufSize;	           // source image size
    PP_MEM_OP_TYPE_ENUM	PpMemOpType;   // check if the source image needs bilinear resize or just memory copy				
    kal_uint32  PpProcBufAddr;             // working buffer address
    kal_uint32 	PpProcBufSize;             // working buffer size
    MM_IMAGE_FORMAT_ENUM  PpProcFmt;	   // source image format, currently only RGB565 is supported			
} AUTOCAP_SET_MEM_INFO_STRUCT, *P_AUTOCAP_SET_MEM_INFO_STRUCT;

typedef struct
{
    MM_ERROR_CODE_ENUM (* AutoCapOpen)(void);
    MM_ERROR_CODE_ENUM (* AutoCapFeatureCtrl) (AUTOCAP_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* AutoCapCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* AutoCapClose)(void);
} AUTOCAP_FUNCTION_STRUCT, *P_AUTOCAP_FUNCTION_STRUCT;

MM_ERROR_CODE_ENUM AutoCapInit(MM_ERROR_CODE_ENUM (* pfAutoCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_AUTOCAP_FUNCTION_STRUCT *pfAutoCapFunc);

#endif	// _AUTOCAP_IF_H_

