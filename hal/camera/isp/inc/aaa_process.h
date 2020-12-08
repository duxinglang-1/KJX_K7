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
 *  aaa_process.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for ISP 3A Interface.
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
#ifndef __AAA_PROCESS_H__
#define __AAA_PROCESS_H__

#include "kal_release.h"
#include "isp_comm_def.h"

/******* temp macro mapping ***********************************************/
//#define AaaSaveLog aaa_save_log
//#define AaaSetEm aaa_set_em
/**********************************************************************/

/* dsc operation structure -------------------------------------------------------------------------------------*/
// move to isp_if_hal.h
/*typedef struct
{
    kal_uint8 Metering;
    kal_uint16  TV;
    kal_uint8 AV;
    kal_uint8 ISO;
    kal_uint8 Flash;
} AE_OPERATION_STRUCT;

typedef struct
{
    kal_uint8 Trigger;
    kal_uint8 Mode;
    kal_uint8 Range;
    kal_uint8 Mfdir;
} AF_OPERATION_STRUCT;

typedef struct
{
    kal_uint8       DscMode;
    AE_OPERATION_STRUCT Ae;
    AF_OPERATION_STRUCT Af;
} DSC_OPERATION_STRUCT;
*/
/* AAA Data Structure -------------------------------------------------------------------------------------*/
typedef struct
{ 
    kal_uint16  GrabW;        /* Grab Window Width */
    kal_uint16  GrabH;        /* Grab Window Height */
    kal_uint16  ResultStartX; /* Result Window X offset */
    kal_uint16  ResultStartY; /* Result Window Y offset */
    kal_uint16  ResultW;      /* Result Window Width */
    kal_uint16  ResultH;      /* Result Window Height */
    kal_uint16  TargetW;      /* LCM width */
    kal_uint16  TargetH;      /* LCM height */
//  kal_uint8   PreviewRotateValue; /* rotate select for sensor preview(enum) */  // not used
    kal_bool    Bypass3aStable;     /* enable/disable wait 3a stable in entry process*///VT feature 
//    void (*pfCamFocusCb) (kal_uint8 ReturnCode);
} AAA_PREVIEW_PROCESS_STRUCT, *P_AAA_PREVIEW_PROCESS_STRUCT;

typedef struct
{ 
    MULTISHOT_INFO_ENUM   MultishotInfo;     /* Snapshot number 0: no limit, 1~n: cont' shot num */
    kal_bool    AeBraketingEnable;  /* AE Braketing Enable */
    kal_uint8   ExpoBracketLevel;   /* AE Braketing value */
    kal_bool    BinningEnable;      /* bining enable flag */
    kal_uint8   ImageEffect;        /* bining enable flag */ 
} AAA_CAPTURE_COMPENSATE_PROCESS_STRUCT, *P_AAA_CAPTURE_COMPENSATE_PROCESS_STRUCT;

typedef struct
{ 
    kal_uint16  GrabW;          /* Grab Window Width */
    kal_uint16  GrabH;          /* Grab Window Height */
    kal_uint16  ResultStartX;   /* Result Window X offset */
    kal_uint16  ResultStartY;   /* Result Window Y offset */
    kal_uint16  ResultW;        /* Result Window Width */
    kal_uint16  ResultH;        /* Result Window Height */
    MULTISHOT_INFO_ENUM MultishotInfo; /* Snapshot number 0: no limit, 1~n: cont' shot num */
    CAL_CAMERA_STILL_CAPTURE_ENUM StillCaptureMode;
} AAA_CAPTURE_PROCESS_STRUCT, *P_AAA_CAPTURE_PROCESS_STRUCT;



typedef struct
{ 
    kal_uint16  GrabW;        /* Grab Window Width */
    kal_uint16  GrabH;        /* Grab Window Height */
    kal_uint16  ResultStartX; /* Result Window X offset */
    kal_uint16  ResultStartY; /* Result Window Y offset */
    kal_uint16  ResultW;      /* Result Window Width */
    kal_uint16  ResultH;      /* Result Window Height */
    kal_uint16  TargetW;      /* LCM width */
    kal_uint16  TargetH;      /* LCM height */
//  kal_uint8   PreviewRotateValue; /* rotate select for sensor preview(enum) */    // not used
    kal_bool    Bypass3aStable;     /* enable/disable wait 3a stable in entry process*///VT feature   
//  void (*pfCamFocusCb) (kal_uint8 ReturnCode);
} AAA_VIDEO_PROCESS_STRUCT, *P_AAA_VIDEO_PROCESS_STRUCT;

typedef struct
{ 
    kal_uint16 GrabW;         /* Grab Window Width */
    kal_uint16 GrabH;         /* Grab Window Height */
    kal_uint16 ResultStartX;  /* Result Window X offset */
    kal_uint16 ResultStartY;  /* Result Window Y offset */
    kal_uint16 ResultW;       /* Result Window Width */
    kal_uint16 ResultH;       /* Result Window Height */
    kal_uint16 TargetW;       /* LCM width */
    kal_uint16 TargetH;       /* LCM height */
} AAA_WINDOW_CONFIG_STRUCT, *P_AAA_WINDOW_CONFIG_STRUCT;

extern AAA_PREVIEW_PROCESS_STRUCT         AaaPreviewConfigData;
extern AAA_CAPTURE_COMPENSATE_PROCESS_STRUCT  AaaCaptureCompensateConfigData;
extern AAA_CAPTURE_PROCESS_STRUCT       AaaCaptureConfigData;
extern AAA_VIDEO_PROCESS_STRUCT         AaaVideoConfigData;
/* AAA Function Interface -------------------------------------------------------------------------------------*/
// AAA Init Interface
void AaaInit(void); //init_aaa
void AaaInitPara(void);
void AaaBypassAe(kal_bool En);
void AaaBypassAwb(kal_bool En);
void AaaBypassAf(kal_bool En);
void AaaPowerOff(void);
void AaaConfigWindow(kal_uint32 StartX,kal_uint32 StartY,kal_uint32 ResultW,kal_uint32 ResultH);
void AaaUpdateResultWindow(void);
void AaaSetFaceInfo(P_AAA_FACE_INFO_STRUCT pFaceInfo);
void AaaGetObjData(void);
P_AAA_WINDOW_CONFIG_STRUCT AaaGetWindowConfigData(void);

// AAA isr
void AaaMain(void);

// AAA Flow Control Interface
void AaaWaitAeAwbStable(void);
void AaaStartStable(void);
kal_bool AaaIsStable(void);
void AaaEnable(kal_bool AeEnable, kal_bool AwbEnable, kal_bool AfEnable);

void AaaConfigPreview(P_AAA_PREVIEW_PROCESS_STRUCT pAaaData);
void AaaConfigCaptureCompensate(P_AAA_CAPTURE_COMPENSATE_PROCESS_STRUCT pAaaData);            
void AaaConfigCapture(P_AAA_CAPTURE_PROCESS_STRUCT pAaaData);
void AaaConfigVideo(P_AAA_VIDEO_PROCESS_STRUCT pAaaData);
void AaaConfigExitPreview(void);
void AaaConfigExitCapture(void);
void AaaConfigExitVideo(void);

void AaaSetSceneMode(kal_uint16 Para);

/* BSS interface */
void AaaBssConfig(P_AAA_CAPTURE_PROCESS_STRUCT pAaaData);
kal_uint8 AaaGetBssResult(kal_uint8 SnapshotNumber, kal_uint32 JpegLength);


void AaaSetFrameValid(void);
void AaaClearFrameValid(void);
kal_bool AaaGetFrameValid(void);

/* Exif interface */
//void AaaExifUpdateMtkParaStruct(P_EXIF_MTK_CAMERA_PARA_STRUCT pPara);

/* aaa debug and engineer mode mode*/
//#define AAA_ENGINEER_MODE // enable engineer mode
#define AAA_LOG_LINE_LEN		(64*4)
#define AAA_LOG_DUMMY		    (32)
#define AAA_LOG_BUFF_SIZE		(AAA_LOG_LINE_LEN*(150+AAA_LOG_DUMMY))

AAA_EM_MODE_ENUM AaaGetEmMode(void);
kal_bool AaaIsEmMode(void);

/* string routine */
extern kal_int8 *aaa_ucs2_strcpy(kal_int8 *strDestination, const kal_int8 *strSource);
extern kal_int8 *aaa_ucs2_strcat(kal_int8 *strDestination, const kal_int8 *strSource);
extern kal_int8 *aaa_ucs2_strrchr(const kal_int8 * string, kal_wchar ch);
extern kal_uint16 aaa_ucs2_str_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);
extern kal_uint16 aaa_asc_str_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);

#endif /* __AAA_PROCESS_H__ */

