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
 *   Hdr_core.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   HDR core header
 *
 * Author:
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
 
#ifndef _HDR_CORE_H_
#define _HDR_CORE_H_

#define SWHDR_INPUT_YUV420
#ifdef SWHDR_SIM_MODE
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
#else
#include "kal_release.h"
#include "Hdr_comm_def.h"
#endif

#define SWHDR_LOG_VERSION (10)

typedef enum
{
    SWHDR_STATE_STANDBY =   0,
    SWHDR_STATE_INIT,       //1
    SWHDR_STATE_LRZ,        // 2
    SWHDR_STATE_SA,         // 3
    //SWHDR_STATE_DEGAMMA,    // 4
    SWHDR_STATE_LPF,        // 5
    SWHDR_STATE_HDR,        // 6
    //SWHDR_STATE_GAMMA,      // 7
    SWHDR_STATE_READY,      // 8    
    SWHDR_STATE_MAX,
}   SWHDR_STATE_ENUM;

typedef enum
{
    SWHDR_INFO_PA   =   SWHDR_STATE_MAX,
    SWHDR_INFO_PB,
    SWHDR_INFO_BA,            
    SWHDR_INFO_O1,
    SWHDR_INFO_O2,
    SWHDR_INFO_V1,
    SWHDR_INFO_V2,
    SWHDR_INFO_HIST,
    SWHDR_INFO_MAX = SWHDR_INFO_HIST+8,
}   SWHDR_INFO_ENUM;



/* HDR_FEATURE_UPDATE_TUNING */
typedef struct
{
    kal_int32 Hdr_Sw_O2_0;
    kal_int32 Hdr_Sw_O2_1;
    kal_int32 Hdr_Sw_O2_2;
    kal_int32 Hdr_Sw_O2_3;
    kal_int32 Hdr_Sw_O2_4;
    kal_int32 Hdr_Sw_O2_5;
    kal_int32 Hdr_Sw_O2_6;
    kal_int32 Hdr_Sw_O2_7;
    kal_int32 Hdr_Sw_O2_8;
    kal_int32 Hdr_Sw_O2_9;
    kal_int32 Hdr_Sw_O2_10;
    kal_int32 Hdr_Sw_Ba_0;
    kal_int32 Hdr_Sw_Ba_1;
    kal_int32 Hdr_Sw_Ba_2;
    kal_int32 Hdr_Sw_Ba_3;
    kal_int32 Hdr_Sw_Ba_4;
    kal_int32 Hdr_Sw_Ba_5;
    kal_int32 Hdr_Sw_Ba_6;
}HDR_STRENGTH_PARA_STRUCT, *HDR_STRENGTH_PARA_STRUCT_P;

typedef struct
{
	HDR_LEVEL_ENUM 		HdrLevel;
	kal_uint16 		    HdrMinBa;           /* 0~255 */
	kal_uint16 		    HdrSatLevel;        /* 0~255 */
}	HDR_TUNING_PARA_STRUCT, *P_HDR_TUNING_PARA_STRUCT;


/* HDR_FEATURE_GET_INFO */
typedef struct
{
	kal_uint16 			Width;
	kal_uint16 			Height;	
    kal_uint32          WorkingBufSize;
	MM_IMAGE_FORMAT_ENUM		SrcImgFormat;
}	HDR_GET_INFO_STRUCT, *P_HDR_GET_INFO_STRUCT;


/* HDR_FEATURE_SET_INFO */
typedef struct
{
    kal_uint16 			Width;
    kal_uint16 			Height;	
    kal_uint32          WorkingBufSize;
//    kal_uint32          JpegDecWorkBufferSize;
    MM_IMAGE_FORMAT_ENUM 	SrcImgFormat;
}	HDR_SET_INFO_STRUCT, *P_HDR_SET_INFO_STRUCT;



typedef struct
{
    kal_uint32      CtrlCode;	
//    kal_uint32      JpegAddr;
    kal_uint32      SrcImgAddr;
    kal_uint32      SrcImgSize; 
    kal_uint32      WorkingBufAddr;
    kal_uint32      MaxWorkingBufSize;    
    kal_uint32      MaxProcTime;    	
}	HDR_SET_PROC_INFO_STRUCT, *P_HDR_SET_PROC_INFO_STRUCT;

kal_uint32 SwHdrGetUseWorkingBufferSize(void);
void SwHdrCoreOpen(void);
void SwHdrCoreClose(void);
void SwHdrCoreGetInfo(HDR_GET_INFO_STRUCT *pSwHdrInfo);
void SwHdrCoreSetInfo(HDR_SET_INFO_STRUCT *pSwHdrInfo);
void SwHdrCoreUpdateTuning(HDR_TUNING_PARA_STRUCT *pSwHdrInfo);   
void SwHdrCoreUpdateStrengthPara(HDR_STRENGTH_PARA_STRUCT_P pHdrPara);
void SwHdrCoreProc(void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
#endif	//_HDR_CORE_H_
