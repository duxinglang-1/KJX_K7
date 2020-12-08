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
 *   cal_cb.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   CAL interface
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "kal_release.h"
#include "cal_api.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"
#include "cal_mem_def.h"

#include "isp_comm_def.h"
#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "sensor_comm_def.h"
#include "image_sensor.h"
#include "idp_cam_if.h"

#include "pp_api.h"
#include "pp_comm_def.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

#include "drv_features.h"
#include "drv_sw_features_mdp.h"

#include "wfc\wfc.h" // The include path is "mcu\interface\hal\display\api"
#include "common\owftypes.h" // The include path is "mcu\interface\hal\display\api"
#include "common\owfnativestream.h" // The include path is "mcu\interface\hal\display\api"

// rotator
#include "rotator_enum.h"
#include "yuv_rotator_api.h"
#include "rgb_rotator_api.h"

#include "visualhisr.h"

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
#include "mav_encoder.h"
#endif
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
#if defined(EXIF_SUPPORT)
#include "exif.h"   // to save debug info in exif
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

#if defined(MT6250) || defined(MT6260)
#define CAL_MAV_CAPTURE_TIMEOUT_FRAME_CNT 22
#else
#define CAL_MAV_CAPTURE_TIMEOUT_FRAME_CNT 45
#endif
#endif

#if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
#endif

// That I can turn it all off here...
#ifndef CAL_DD_ASSERT
#define CAL_DD_ASSERT(_expr_) ASSERT(_expr_)
#endif

#if defined(EXIF_SUPPORT)
CAL_JAIA_MERGE_REQ_MSG_STRUCT JaiaMergePara;
#endif

#ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
CAL_IMAGE_Y2R_DITHERING_STRUCT ImageY2RDitheringPara;
#endif

kal_uint32  gMdpPostProcFrmStableState =0;
#define MDP_POSTPROC_FRM_UNSTABLE       (2)
#define MDP_POSTPROC_FRM_STABLE         (0)
kal_bool    gCalPreviewPostProcPaused = KAL_FALSE;

// display driver
extern OWFNativeStreamType CalDisplayStream;
extern kal_uint32 CalDisplayFBs[3][2];
extern kal_uint32 Newest_FrameBuf_Addr;

kal_uint8 DisplayImageSwRotatorIdx=0;

#if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
    CAL_MDP_STILL_CAPTURE_STRUCT MdpZsdResizePara;
#endif

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    CAL_BUFFER_CB_STRUCT PanoCbPara;
#endif

#if defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__)
kal_uint8 DisplayImageEffectIdx=0;
extern kal_bool IsImageEffectBusy;
CAL_BUFFER_CB_STRUCT DisplayCbPara;
void (*pMdpCropBufferCb) (void*);
kal_uint32 DisplayImageEffectBufferAddr=0;
#endif

#if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
extern CAL_CAMERA_STILL_CAPTURE_ENUM CalStillCaptureMode;
#endif

void SendMsgToCal(msg_type MsgId, void *pLocalData)
{
    local_para_struct *pLocalPara;

#if (defined(__POSTPROC_SUPPORT__))
    PP_PROC_REQ_STRUCT* pMsg;
#endif

    switch (MsgId)
    {
#if defined(__JPEG_SENSOR_SUPPORT__)
        case MSG_ID_CAL_JPEG_SENSOR_PARSE_REQ:

            pLocalPara = construct_local_para(sizeof(CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
#endif
        case MSG_ID_CAL_INFORM_MDP_FRAME_RATE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;

        case MSG_ID_CAL_JAIA_MERGE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_JAIA_MERGE_REQ_MSG_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_JAIA_MERGE_REQ_MSG_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
        case MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #ifdef __CAL_IMAGE_ROTATE_SUPPORT__
        case MSG_ID_CAL_ROTATE_IMAGE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_ROTATE_IMAGE_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_ROTATE_IMAGE_REQ_STRUCT)-sizeof(local_para_struct));

        #ifdef __CAL_NEED_SW_ROTATE__
            CalSendIlm(MOD_CAL_HIGH, MOD_CAL_HIGH, MsgId, pLocalPara, NULL, KAL_FALSE);
        #else
            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        #endif
        break;
    #endif
    #ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
        case MSG_ID_CAL_GET_PREVIEW_IMAGE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_GET_PREVIEW_IMAGE_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_GET_PREVIEW_IMAGE_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
    #ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
        case MSG_ID_CAL_SW_Y2R_DITHERING_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_IMAGE_Y2R_DITHERING_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_IMAGE_Y2R_DITHERING_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
        case MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_SW_JPEG_ENCODE_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_SW_JPEG_ENCODE_REQ_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
        case MSG_ID_CAL_LOW_JPEG_DECODE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_JPEG_DECODE_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_JPEG_DECODE_REQ_STRUCT)-sizeof(local_para_struct));
            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        case MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_SW_JPEG_ENCODE_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_SW_JPEG_ENCODE_REQ_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
    #if (defined(__POSTPROC_SUPPORT__))
        case MSG_ID_CAL_LOW_PP_START_REQ:
            pMsg = (P_PP_PROC_REQ_STRUCT) construct_local_para(sizeof(PP_PROC_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy(
                ((kal_uint8*) pMsg) + sizeof(local_para_struct),
                ((kal_uint8*) pLocalData) + sizeof(local_para_struct),
                sizeof(PP_PROC_REQ_STRUCT) - sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, (void*)pMsg, NULL, KAL_FALSE);  //MOD_CAL_LOW
        break;
        case MSG_ID_CAL_LOW_PP_START_TIMER_REQ:
            pMsg = (P_PP_PROC_REQ_STRUCT) construct_local_para(sizeof(PP_PROC_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy(
                ((kal_uint8*) pMsg) + sizeof(local_para_struct),
                ((kal_uint8*) pLocalData) + sizeof(local_para_struct),
                sizeof(PP_PROC_REQ_STRUCT) - sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, (void*)pMsg, NULL, KAL_FALSE);  //MOD_CAL_LOW
        break;
        case MSG_ID_CAL_LOW_PP_STOP_REQ:
            pMsg = (P_PP_PROC_REQ_STRUCT) construct_local_para(sizeof(PP_PROC_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy(
                ((kal_uint8*) pMsg) + sizeof(local_para_struct),
                ((kal_uint8*) pLocalData) + sizeof(local_para_struct),
                sizeof(PP_PROC_REQ_STRUCT) - sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, (void*)pMsg, NULL, KAL_FALSE);     //MOD_CAL_LOW
        break;
        case MSG_ID_CAL_PP_START_REQ:
            pMsg = (P_PP_PROC_REQ_STRUCT) construct_local_para(sizeof(PP_PROC_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy(
                ((kal_uint8*) pMsg) + sizeof(local_para_struct),
                ((kal_uint8*) pLocalData) + sizeof(local_para_struct),
                sizeof(PP_PROC_REQ_STRUCT) - sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, (void*)pMsg, NULL, KAL_FALSE);
    break;
    #endif /* defined(__POSTPROC_SUPPORT__) */
    #ifdef WEBCAM_SUPPORT
        case MSG_ID_CAL_WEBCAM_FRAME_READY_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_WEBCAM_FRAME_READY_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_WEBCAM_FRAME_READY_REQ_STRUCT)-sizeof(local_para_struct));

            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
    #if defined(__CAL_CAMERA_AF_SUPPORT__)
        case MSG_ID_CAL_LOW_GET_AF_RESULT:
            CalSendIlm(MOD_CAL, MOD_CAL_LOW, MsgId, NULL, NULL, KAL_FALSE);
        break;
    #endif
    #if defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__)
        case MSG_ID_CAL_SW_IMAGE_EFFECT_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_IMAGE_EFFECT_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_IMAGE_EFFECT_REQ_STRUCT)-sizeof(local_para_struct));
            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        case MSG_ID_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT), TD_CTRL);
            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT)-sizeof(local_para_struct));
            CalSendIlm(MOD_CAL, MOD_CAL, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
        case MSG_ID_CAL_LOW_ROTATE_IMAGE_LIST_REQ:
            pLocalPara = construct_local_para(sizeof(CAL_ROTATE_IMAGE_LIST_REQ_STRUCT), TD_CTRL);

            kal_mem_cpy((kal_uint8 *)pLocalPara+sizeof(local_para_struct), (kal_uint8 *)pLocalData+sizeof(local_para_struct),
                        sizeof(CAL_ROTATE_IMAGE_LIST_REQ_STRUCT)-sizeof(local_para_struct));
            CalSendIlm(MOD_CAL_LOW, MOD_CAL_LOW, MsgId, pLocalPara, NULL, KAL_FALSE);
        break;
    #endif
        default:
            ASSERT(0);
    }
} /* SendMsgToCal() */

#if defined(EXIF_SUPPORT)
void SendJaiaMergeMsg(void)
{
    if ((CurrentStillCaptureStatus & CAL_STILL_CAPTURE_IMAGE_MASK) == CurrentStillCaptureMask)
    {   // send a meesage to CAL task to start JAIA merge
        CurrentStillCaptureStatus=0;
        JaiaMergePara.MainImageStartAddr=(kal_uint32)pJpegEncodedDataAddr;
        JaiaMergePara.MainImageSize=JpegEncodedDataSize;
        JaiaMergePara.JaiaCbId=CAL_CBID_STILL_IMAGE_READY;
        JaiaMergePara.pCalStillCapPara=&CalStillCaptureInfo;
        SendMsgToCal(MSG_ID_CAL_JAIA_MERGE_REQ, &JaiaMergePara);
    }
}   /* SendJaiaMergeMsg() */
#endif

MM_ERROR_CODE_ENUM CameraImageDisplay(P_CAL_BUFFER_CB_STRUCT pCbBuff)
{
#if (defined(__MTK_TARGET__))
    kal_uint32 bufaddr, i;
    volatile OWFNativeStreamBuffer buf;
    //pCbBuff->NextFrameBufferAddr = pCbBuff->ImageBuffAddr;

    if (KAL_FALSE == DisplayPreviewFrameFlag ||
        OWF_INVALID_HANDLE == CalDisplayStream)
    {
        return MM_ERROR_MDP_BUFFER_NO_SYNC;
    }

    if (KAL_TRUE == pCbBuff->EnableReleaseWriteBuffer)
    {
        for (i=0; i<=2 ;i++)
        {
            if (pCbBuff->ImageBuffAddr == CalDisplayFBs[i][0])
            {
                // find the index of current display buffer
                buf = (OWFNativeStreamBuffer) CalDisplayFBs[i][1];
                // if current display buffer was locked by WFC, drop this frame
                if (0x0 == buf)
                    return MM_ERROR_MDP_BUFFER_NO_SYNC;

                // send current display buffer to LCD for update
                owfNativeStreamReleaseWriteBuffer(CalDisplayStream,
                                                buf/* (OWFNativeStreamBuffer) 0x100 */,
                                                NULL /* (EGLDisplay) */,
                                                NULL /* (EGLSyncKHR) */);
                CalDisplayFBs[i][1] = 0x0;
                break;
            }
        }
        Newest_FrameBuf_Addr = pCbBuff->ImageBuffAddr;
    }

    if (KAL_TRUE == pCbBuff->EnableAcquireWriteBuffer)
    {
        pCbBuff->NextFrameBufferAddr = pCbBuff->ImageBuffAddr;
        // acquire next display buffer
        buf = (kal_uint32) owfNativeStreamAcquireWriteBuffer(CalDisplayStream);
        // if buf == NULL, currently no display buffer is available, use current display buffer to draw
        // if buf != NULL, get the buffer pointer for MDP to draw
        if (NULL != buf)
        {
            bufaddr = (kal_uint32)owfNativeStreamGetBufferPtr(CalDisplayStream,buf);

            for (i=0; i<=2 ;i++)
            {
                if (bufaddr == CalDisplayFBs[i][0])
                {
                  CalDisplayFBs[i][1] = buf;
                  break;
                }
            }

            pCbBuff->NextFrameBufferAddr = bufaddr;
        }
        else
        {
            // next buffer is unavailable, set to INVALID HANDLE
            pCbBuff->NextFrameBufferAddr = WFC_INVALID_HANDLE;
        }
    }
    return MM_ERROR_NONE;
#endif
}   /* CameraImageDisplay() */

#if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
/*ASD_DECIDER_UI_AUTO=0=CAM_AUTO_DSC,
    ASD_DECIDER_UI_N   =1=CAM_NIGHTSCENE,
    ASD_DECIDER_UI_B   =2=CAM_BACKLIGHT,
    ASD_DECIDER_UI_P   =3=CAM_PORTRAIT,
    ASD_DECIDER_UI_L   =4=CAM_LANDSCAPE,
    ASD_DECIDER_UI_NB  =5,
    ASD_DECIDER_UI_NP  =6=CAM_NIGHT_PORTRAIT,
    ASD_DECIDER_UI_NL  =7,
    ASD_DECIDER_UI_BP  =8=CAM_BACKLIGHT_PORTRAIT,
    ASD_DECIDER_UI_BL  =9,
    ASD_DECIDER_UI_PL  =10,
    ASD_DECIDER_UI_NBP =11,
    ASD_DECIDER_UI_NBL =12,
    ASD_DECIDER_UI_NPL =13,
    ASD_DECIDER_UI_BPL =14,
    ASD_DECIDER_UI_NBPL=15,
    ASD_DECIDER_UI_SCENE_NUM*/
const CAL_CAMERA_SCENE_MODE_ENUM CalAsdSceneLut[ASD_DECIDER_UI_SCENE_NUM] =
{
    CAM_AUTO_DSC,
    CAM_NIGHTSCENE, CAM_BACKLIGHT, CAM_PORTRAIT, CAM_LANDSCAPE,
    CAM_NO_OF_SCENE_MODE, CAM_NIGHT_PORTRAIT, CAM_NO_OF_SCENE_MODE, CAM_BACKLIGHT_PORTRAIT,
    CAM_NO_OF_SCENE_MODE, CAM_NO_OF_SCENE_MODE, CAM_NO_OF_SCENE_MODE, CAM_NO_OF_SCENE_MODE,
    CAM_NO_OF_SCENE_MODE, CAM_NO_OF_SCENE_MODE, CAM_NO_OF_SCENE_MODE
};
void CalSceneCompensationConfig(CAL_SCENARIO_ENUM ScenarioId, CAL_CAMERA_SCENE_MODE_ENUM SceneType
                                                                            , P_ISP_CAMERA_SCENE_COMPENSATION_STRUCT pPara)
{
    pPara->SceneType = SceneType;

    // default setting
    pPara->SceneContrast = CAM_CONTRAST_MEDIUM;
    pPara->SceneSaturation = CAM_SATURATION_MEDIUM;
    pPara->SceneSharpness = CAM_SHARPNESS_MEDIUM;
    pPara->NightModeEnable = KAL_FALSE;
    pPara->SkinColorEnhanceEnable = KAL_FALSE;
    pPara->FaceEVBiosEnable = KAL_FALSE;
    pPara->AsdEnabled = CalAsdEnabled;

    if( (!IspAwbAfRefBuff.AaaInfoFromRaw)&&(CAL_SCENARIO_CAMERA_PREVIEW == ScenarioId) )
    {   // no compensation in yuv preview
    }
    else
    {   // for raw preview/capture and yuv capture
         switch(SceneType)
        {
            case CAM_PORTRAIT:
            case CAM_NIGHTSCENE:
            case CAM_NIGHT_PORTRAIT:
            case CAM_BACKLIGHT_PORTRAIT:
                pPara->SceneContrast = CAM_CONTRAST_LOW;
                pPara->SceneSharpness = CAM_SHARPNESS_LOW;
                if(CAM_NIGHTSCENE!=SceneType)
                {
                    if(IspAwbAfRefBuff.AaaInfoFromRaw)
                    {   // for raw portrait-related
                        pPara->SkinColorEnhanceEnable = KAL_TRUE;
                    }
                    else
                    {   // for yuv portrait-related
                        pPara->FaceEVBiosEnable = KAL_TRUE;
                        pPara->FaceLuminance = IspSceneCompensationParaIn.FaceLuminance;
                    }
                }
                if( (CAM_NIGHTSCENE==SceneType)||(CAM_NIGHT_PORTRAIT==SceneType) )
                {   // for nightmode-related
                    pPara->NightModeEnable = KAL_TRUE;
                }
                break;
            case CAM_LANDSCAPE:
                pPara->SceneSaturation = CAM_SATURATION_HIGH;
                pPara->SceneSharpness = CAM_SHARPNESS_HIGH;
                break;
            case CAM_DOCUMENT:          //
                pPara->SceneContrast = CAM_CONTRAST_HIGH;
                pPara->SceneSharpness = CAM_SHARPNESS_HIGH;
                break;
            case CAM_BACKLIGHT:
            case CAM_AUTO_DSC:
            default:
                break;
        }
    }

    // if non-asd mode, do not compensate on these UI switchable setting
    if(!CalAsdEnabled)
    {
        pPara->SceneContrast = CAM_CONTRAST_MAX;
        pPara->SceneSaturation = CAM_SATURATION_MAX;
        pPara->SceneSharpness = CAM_SHARPNESS_MAX;
    }

    return;
}
#endif //__AUTO_SCENE_DETECT_SUPPORT__

MM_ERROR_CODE_ENUM IspCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    CalTrace(CAL_TRACE_CBF,CAL_CBF_ISP,CbId,drv_get_current_time());
    switch (CbId)
    {
    #ifdef __CAL_CAMERA_AF_SUPPORT__
        case CAL_CBID_AF_RESULT:
            pfCalCallback(CAL_CBID_AF_RESULT, pCallbackPara, CallbackParaLen);
        break;
    #endif
        default:
        break;
    }

    return ErrorCode;
} /* IspCallback() */
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
    CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT ImageCopyAndResizePara;
#endif
#if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
    ASD_PROC_AAA_PARA                                   AsdProcAaaPara;
#endif //__AUTO_SCENE_DETECT_SUPPORT__
#ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
    CAL_GET_PREVIEW_IMAGE_STRUCT GetPreviewImageMsgPara;
#endif
CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT MainImageResizePara;
#ifdef __CAL_IMAGE_ROTATE_SUPPORT__
    CAL_ROTATE_IMAGE_REQ_STRUCT ImageRotatePara;
#endif
#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
    CAL_IMAGE_EFFECT_REQ_STRUCT ImageEffectPara;
#endif
MM_ERROR_CODE_ENUM MdpCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;
    Digital_Zoom_Crop_Ctrl_Struct MdpDigitalZoomPara;
    P_ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT pIspDigitalZoomResParaIn;
    P_ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT pIspDigitalZoomResParaOut;
    kal_uint32 FeatureOutLen, ImageResolution;
    kal_bool ZoomEnable=KAL_FALSE;
    kal_bool EnableCrzCb=KAL_FALSE;
    kal_bool EnableSwRotator=KAL_FALSE;
    kal_bool EnableImgPostProc=KAL_FALSE;

    #if defined(MT6235) || defined(MT6235B) || defined(MT6253) ||defined(MT6252)||defined(MT6252H)||defined(MT6255)||defined(MT6250)||defined(MT6260)
    CAL_SW_JPEG_ENCODE_REQ_STRUCT JpegEncPara;
    #endif

    Camera_Capture_Crop_Buffer_Struct *pCbCropBuff=(Camera_Capture_Crop_Buffer_Struct*) pCallbackPara;
#if (defined(__POSTPROC_SUPPORT__))
    PP_SCENARIO_CONF_IN_STRUCT_UNION    PpConfInPara;
    PP_PROC_INFO_STRUCT                 PpProcInfoPara;
#endif /* defined(__POSTPROC_SUPPORT__) */
#if (defined(__PANORAMA_VIEW_SUPPORT__)&&defined(PANORAMA_INPUT_IMAGE_FORMAT_YUV420))
    CAL_BUFFER_CB_STRUCT PanoCbPara;
#endif

    CalTrace(CAL_TRACE_CBF,CAL_CBF_MDP,CbId,drv_get_current_time());
    switch (CbId)
    {
        #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        case IDPCAL_CBID_CAM_PREVIEW_ZSD_YUV_IMG_DONE:
        #endif  //__ZERO_SHUTTER_DELAY_SUPPORT__
        case IDPCAL_CBID_CAM_CAPTURE_YUV_IMG_DONE:
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_DISABLE_VIEWFINDER, NULL, NULL, 0, 0);
        break;
        case IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE:
        case IDPCAL_CBID_VIDEO_ENCODE_PREVIEW_DISPLAY_FRM_DONE:
        #ifdef __CAL_NEED_SW_ROTATE__
            if ((KAL_TRUE == DisplayPreviewFrameFlag) && (KAL_TRUE==PostProcImageFromDisplayImage))
            {
                // send a meesage to rotate the display image to diaply image buffer
                if (MM_IMAGE_ROTATE_0!=ImageSwRotateAngleForDisplay)
                {
                    ImageRotatePara.ImageDataFormat=CalPreviewInfo.ImageDataFormat;
                    ImageRotatePara.ImageRotAngle=ImageSwRotateAngleForDisplay;
                    ImageRotatePara.SrcImageWidth=CalPreviewInfo.DisplayImageWidth;
                    ImageRotatePara.SrcImageHeight=CalPreviewInfo.DisplayImageHeight;
                    ImageRotatePara.ImageRotCbId=CAL_CBID_DISPLAY_IMAGE_ROTATE_READY;

                    ImageResolution = CalPreviewInfo.DisplayImageWidth * CalPreviewInfo.DisplayImageHeight;

                    ImageRotatePara.SrcImageYBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr;
                    ImageRotatePara.ImageYBuffSize=CalPreviewInfo.FrameBuffSize;
                    if (DisplayImageSwRotatorIdx & 0x1)
                        ImageRotatePara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr1;
                    else
                        ImageRotatePara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr2;
                    DisplayImageSwRotatorIdx ++;

                    ImageRotatePara.WorkingBuffAddr=0;
                    ImageRotatePara.WorkingBuffSize=0;
                    SendMsgToCal(MSG_ID_CAL_ROTATE_IMAGE_REQ, &ImageRotatePara);
                    EnableSwRotator=KAL_TRUE;
                }
            }
        #endif
        #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
            if (KAL_TRUE == DisplayPreviewFrameFlag && KAL_TRUE == CalImageEffectEnable)
            {
                if (!IsImageEffectBusy)
                {
                    ImageEffectPara.ImageDataFormat=CalPreviewInfo.ImageDataFormat;
                    if (MdpDisplayImageRotAngle & 0x01)
                    {
                        ImageEffectPara.SrcImageWidth=CalPreviewInfo.DisplayImageHeight;
                        ImageEffectPara.SrcImageHeight=CalPreviewInfo.DisplayImageWidth;
                    }
                    else
                    {
                        ImageEffectPara.SrcImageWidth=CalPreviewInfo.DisplayImageWidth;
                        ImageEffectPara.SrcImageHeight=CalPreviewInfo.DisplayImageHeight;
                    }
                    ImageEffectPara.ImageEffectCbId=CAL_CBID_PREVIEW_IMAGE_EFFECT_READY;
                    ImageEffectPara.ImageEffectId=CalImageEffect;
                    ImageEffectPara.SrcImageYBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr;
                    ImageEffectPara.ImageYBuffSize=pCbBuff->ImageBuffSize;
                    ImageEffectPara.ImageRotateAngle = pCbBuff->ImageRotateAngle;
                 #ifdef MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER
                    if (NULL != CalDisplayFBs[2][0]) // triple buffer
                    {
                        if (DisplayImageEffectIdx == 0)
                        {
                            ImageEffectPara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr1;
                        }
                        else if (DisplayImageEffectIdx == 1)
                        {
                            ImageEffectPara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr2;
                        }
                        else
                        {
                            if (DisplayImageEffectBufferAddr!=0)
                            {
                                ImageEffectPara.DestImageYBuffAddr=DisplayImageEffectBufferAddr;
                            }
                            else
                            {
                                ImageEffectPara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr3;
                            }

                        }
                    }
                    else // double buffer
                 #endif
                    {
                        if (DisplayImageEffectIdx & 0x1)
                            ImageEffectPara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr1;
                        else
                            ImageEffectPara.DestImageYBuffAddr=CalPreviewInfo.FrameBuffAddr2;
                    }
                    //DisplayImageEffectIdx ++;
                    IsImageEffectBusy = KAL_TRUE;
                    SendMsgToCal(MSG_ID_CAL_SW_IMAGE_EFFECT_REQ, &ImageEffectPara);
                }
                EnableImgPostProc=KAL_TRUE;
            }
        #endif  /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
        #if defined(__CAMERA_GYRO_SUPPORT__)
        if (CalCamGyroEnabled)
        {
            ImageCopyAndResizePara.ImageDataFormat = pCbBuff->ImageBuffFormat;
            ImageCopyAndResizePara.SrcImageBuffAddr = pCbBuff->ImageBuffAddr;
            ImageCopyAndResizePara.SrcImageBuffSize = CalPreviewInfo.DisplayImageWidth*CalPreviewInfo.DisplayImageHeight;
            ImageCopyAndResizePara.SrcImageWidth = CalPreviewInfo.DisplayImageWidth;
            ImageCopyAndResizePara.SrcImageHeight = CalPreviewInfo.DisplayImageHeight;
            ImageCopyAndResizePara.IsCopyEnable = KAL_TRUE;
            ImageCopyAndResizePara.IsResizeEnable = KAL_FALSE;
            ImageCopyAndResizePara.CopyImageBuffAddr = CalCamGyroCopyBuffAddr;
            ImageCopyAndResizePara.CopyImageBuffSize = CalPreviewInfo.DisplayImageWidth*CalPreviewInfo.DisplayImageHeight;
            SendMsgToCal(MSG_ID_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ, &ImageCopyAndResizePara);

            PpProcInfoPara.PpSrcBufAddr = ImageCopyAndResizePara.CopyImageBuffAddr;
            PpProcInfoPara.PpSrcBufSize = ImageCopyAndResizePara.CopyImageBuffSize;
            PpProcInfoPara.PpProcPara = (void*)KAL_FALSE;
            PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);
            break;
        }
        #endif /* defined(__CAMERA_GYRO_SUPPORT__) */

            if ((KAL_FALSE==EnableSwRotator)&&(KAL_FALSE==EnableImgPostProc))
                ErrorCode = CameraImageDisplay(pCbBuff);

        #ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
            if (KAL_TRUE==GetPreviewImageEnable)
            {   // AP would like to get the preview image buffer
                GetPreviewImageMsgPara.SrcImageBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr;
                GetPreviewImageMsgPara.pGetPreviewImagePara=&CamPreviewImageInfo;
                if (IMAGE_SENSOR_MIRROR_HV==SensorScenarioParaIn.ImageMirror)
                    GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle=GetRestRotAngle(GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle, MM_IMAGE_ROTATE_180);
                else if (IMAGE_SENSOR_MIRROR_H==SensorScenarioParaIn.ImageMirror)
                    GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle=GetRestRotAngle(GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle, MM_IMAGE_H_MIRROR);
                else if (IMAGE_SENSOR_MIRROR_V==SensorScenarioParaIn.ImageMirror)
                    GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle=GetRestRotAngle(GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);

                if (CAL_SCENARIO_CAMERA_PREVIEW==CurrentScenarioId)
                {
                    GetPreviewImageMsgPara.SrcImageDataFormat=CalPreviewInfo.ImageDataFormat;

                    if (MdpDisplayImageRotAngle & 0x01)
                    {
                        GetPreviewImageMsgPara.SrcImageWidth=CalPreviewInfo.DisplayImageHeight;
                        GetPreviewImageMsgPara.SrcImageHeight=CalPreviewInfo.DisplayImageWidth;
                    }
                    else
                    {
                        GetPreviewImageMsgPara.SrcImageWidth=CalPreviewInfo.DisplayImageWidth;
                        GetPreviewImageMsgPara.SrcImageHeight=CalPreviewInfo.DisplayImageHeight;
                    }

                    GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle=GetRestRotAngle(GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle, MdpDisplayImageRotAngle);
                }
                else
                {
                    GetPreviewImageMsgPara.SrcImageDataFormat=CalVideoInfo.DisplayImageDataFormat;

                    if (MdpDisplayImageRotAngle & 0x01)
                    {
                        GetPreviewImageMsgPara.SrcImageWidth=CalVideoInfo.DisplayImageWidth;
                        GetPreviewImageMsgPara.SrcImageHeight=CalVideoInfo.DisplayImageHeight;
                    }
                    else
                    {
                        GetPreviewImageMsgPara.SrcImageWidth=CalVideoInfo.DisplayImageWidth;
                        GetPreviewImageMsgPara.SrcImageHeight=CalVideoInfo.DisplayImageHeight;
                    }

                    GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle=GetRestRotAngle(GetPreviewImageMsgPara.pGetPreviewImagePara->ImageRotAngle, MdpDisplayImageRotAngle);
                }
                GetPreviewImageMsgPara.WorkingBuffAddr=0;
                GetPreviewImageMsgPara.WorkingBuffSize=0;
                GetPreviewImageMsgPara.GetPreviewImageCbId=CAL_CBID_PREVIEW_IMAGE_READY;
                SendMsgToCal(MSG_ID_CAL_GET_PREVIEW_IMAGE_REQ, &GetPreviewImageMsgPara);
                GetPreviewImageEnable = KAL_FALSE;
            }
        #endif
        #if (defined(__POSTPROC_SUPPORT__))
            if (KAL_TRUE == DisplayPreviewFrameFlag)
            {
                if (KAL_TRUE==PostProcImageFromDisplayImage)
                {
                    // pass the image buffer to start post process flow
                    if(gMdpPostProcFrmStableState==MDP_POSTPROC_FRM_STABLE)
                    {
                        if (gCalPreviewPostProcPaused)
                        {   /* to avoid CPU resource conflict between CAL & VRT task */
                            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_RESET, 0, 0, 0);
                        }
                        else
                        {
                            if (KAL_TRUE == gMdpPostProcTrigger)
                            {   /* reduce dummy PpCtrl() calls to optimize SD capture performance */
                                PpProcInfoPara.PpSrcBufAddr = pCbBuff->ImageBuffAddr;
                                PpProcInfoPara.PpSrcBufSize = pCbBuff->ImageBuffSize;
                                PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
                                PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);
                            }
                        }
                    }
                    else
                    {
                        gMdpPostProcFrmStableState--;
                    }
                }
            }
        #endif /* defined(__POSTPROC_SUPPORT__) */
        break;
    #if (defined(__POSTPROC_SUPPORT__))
        case IDPCAL_CBID_CAM_PREVIEW_POSTPROC_FRM_DONE:
            if(gMdpPostProcFrmStableState==MDP_POSTPROC_FRM_STABLE)
            {
                if (gCalPreviewPostProcPaused)
                {   /* to avoid CPU resource conflict between CAL & VRT task */
                    PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_RESET, 0, 0, 0);
                }
                else
                {
                    if (KAL_TRUE == gMdpPostProcTrigger)
                    {   /* reduce dummy PpCtrl() calls to optimize SD capture performance */
                        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
                        if(CalAsdEnabled)
                        {
                            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_3A_INFO, NULL, &IspInfoAaaBuff, sizeof(ISP_CAMERA_INFO_3A_STRUCT), &FeatureOutLen);
                            AsdProcAaaPara.AeIsStable = IspInfoAaaBuff.AeIsStable;
                            AsdProcAaaPara.AeIsBacklit = IspInfoAaaBuff.AeIsBacklit;
                            AsdProcAaaPara.AeEv = IspInfoAaaBuff.AeEv;
                            AsdProcAaaPara.AeFaceEnhanceEv= IspInfoAaaBuff.AeFaceEnhanceEv;
                            AsdProcAaaPara.AwbIsStable = IspInfoAaaBuff.AwbIsStable;
                            AsdProcAaaPara.AwbCurRgain = IspInfoAaaBuff.AwbCurRgain;
                            AsdProcAaaPara.AwbCurBgain = IspInfoAaaBuff.AwbCurBgain;
                            AsdProcAaaPara.AfIsStable = IspInfoAaaBuff.AfIsStable;
                            AsdProcAaaPara.AfPosition = IspInfoAaaBuff.AfPosition;
                            PpProcInfoPara.PpProcPara = &AsdProcAaaPara;
                        }
                        #endif // __AUTO_SCENE_DETECT_SUPPORT__
                        #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
                        if (CalMavEnabled&&CAL_MAV_CAPTURE_STATE == CalMavState)
                        {
                            kal_uint32 MaxImageNumber = MAV_IMAGE_NUM;
                            #if defined(__3D_IMAGE_SUPPORT__)
                            if (KAL_TRUE==CalMav3DImageMode)
                                MaxImageNumber = 2;
                            #endif
                            if (CalMavPostProcPara.ImageNumber<MaxImageNumber)
                            {
                                // copy and resize mdp buffer for postproc
                                kal_uint32 CopyBufferSize = (CalMavSrcImageWidth*CalMavSrcImageHeight*3)/2;
                                ASSERT(pCbBuff->ImageBuffSize == CopyBufferSize);
                                ImageCopyAndResizePara.ImageDataFormat = pCbBuff->ImageBuffFormat;
                                ImageCopyAndResizePara.SrcImageBuffAddr = pCbBuff->ImageBuffAddr;
                                ImageCopyAndResizePara.SrcImageBuffSize = pCbBuff->ImageBuffSize;
                                ImageCopyAndResizePara.SrcImageWidth = CalMavSrcImageWidth;
                                ImageCopyAndResizePara.SrcImageHeight = CalMavSrcImageHeight;
                                ImageCopyAndResizePara.IsCopyEnable = IsMavReadyToShot;
                                ImageCopyAndResizePara.IsResizeEnable = KAL_TRUE;
                                if (ImageCopyAndResizePara.IsResizeEnable)
                                {
                                    ImageCopyAndResizePara.ResizeImageBuffAddr = CalMavResizeImageBufferAddr;
                                    ImageCopyAndResizePara.ResizeImageBuffSize = (CalMavResizeImageWidth*CalMavResizeImageHeight*3)/2;
                                    ImageCopyAndResizePara.ResizeImageWidth = CalMavResizeImageWidth;
                                    ImageCopyAndResizePara.ResizeImageHeight = CalMavResizeImageHeight;
                                }
                                if (ImageCopyAndResizePara.IsCopyEnable)
                                {
                                    CAL_MAV_CAP_RESULT_STRUCT CbPara;
                                    ASSERT(CalMavPostProcPara.ImageNumber<MAV_IMAGE_NUM);
                                    ImageCopyAndResizePara.CopyImageBuffAddr
                                        = CalMavPostProcPara.ImageBufferAddr + CalMavPostProcPara.ImageNumber*CopyBufferSize;
                                    ImageCopyAndResizePara.CopyImageBuffSize
                                        = CopyBufferSize;
                                    CalMavPostProcPara.ImageMV[CalMavPostProcPara.ImageNumber][0] = CalMavMV[0];
                                    CalMavPostProcPara.ImageMV[CalMavPostProcPara.ImageNumber][1] = CalMavMV[1];
                                    CalMavPostProcPara.ImageNumber++;
                                    // callback to MED to indicate capture ready
                                    CbPara.TotalImageNumber = MAV_IMAGE_NUM;
                                    #if defined(__3D_IMAGE_SUPPORT__)
                                    if (KAL_TRUE==CalMav3DImageMode)
                                    {
                                        CbPara.TotalImageNumber = 2;
                                    }
                                    #endif
                                    CbPara.CurrentImageNumber = CalMavPostProcPara.ImageNumber;
                                    pfCalCallback(CAL_CBID_MAV_CAPTURE_IMAGE_READY, &CbPara, sizeof(CAL_MAV_CAP_RESULT_STRUCT));

                                }
                                SendMsgToCal(MSG_ID_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ, &ImageCopyAndResizePara);
                                if (ImageCopyAndResizePara.IsResizeEnable)
                                {
                                    kal_bool IsForceCapture = KAL_FALSE;
                                    if ((CalMavPostProcPara.ImageNumber==0)
                                        &&(IsMavReadyToShot==KAL_FALSE)
                                        &&(++CalMavCaptureTimeoutFrameCount>=CAL_MAV_CAPTURE_TIMEOUT_FRAME_CNT))
                                    {
                                        // force to capture when timeout before first capture
                                        IsForceCapture = KAL_TRUE;
                                    }
                                    // config postproc source buffer info & trigger postproc
                                    PpProcInfoPara.PpSrcBufAddr = ImageCopyAndResizePara.ResizeImageBuffAddr;
                                    PpProcInfoPara.PpSrcBufSize = ImageCopyAndResizePara.ResizeImageBuffSize;
                                    PpProcInfoPara.PpProcPara = (void*)IsForceCapture;
                                    PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
                                    PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);
                                }
                            }
                        }
                        else
                        #endif
                        {
                            PpProcInfoPara.PpSrcBufAddr = pCbBuff->ImageBuffAddr;
                            PpProcInfoPara.PpSrcBufSize = pCbBuff->ImageBuffSize;
                            PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
                            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);
                        }

                    }
                }
            }
            else
            {
                gMdpPostProcFrmStableState--;
            }
        break;
    #endif
        case IDPCAL_CBID_VIDEO_ENCODE_GET_ENC_BUF:
            //*((kal_uint32 *) pCallbackPara)=(kal_uint32) CalVideoInfo.pfGetVideoBuff();
            MplBuffInfo = CalVideoInfo.pfGetVideoBuff();
            *((kal_uint32 *) pCallbackPara) = (kal_uint32) MplBuffInfo.pu1Address;
        break;
        case IDPCAL_CBID_VIDEO_ENCODE_RET_ENC_BUF:
        #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
            if (MM_IMAGE_ROTATE_0!=CalVideoInfo.VideoImageRotAngle)
            {
                ImageRotatePara.ImageDataFormat=CalVideoInfo.VideoImageDataFormat;
                ImageRotatePara.ImageRotAngle=CalVideoInfo.VideoImageRotAngle;
                ImageRotatePara.SrcImageWidth=CalVideoInfo.VideoImageWidth;
                ImageRotatePara.SrcImageHeight=CalVideoInfo.VideoImageHeight;
                ImageRotatePara.ImageRotCbId=CAL_CBID_VIDEO_IMAGE_READY;

                ImageResolution = CalVideoInfo.VideoImageWidth * CalVideoInfo.VideoImageHeight;

                if (MM_IMAGE_FORMAT_YUV420==CalVideoInfo.VideoImageDataFormat)
                {
                    ImageRotatePara.SrcImageYBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr;
                    ImageRotatePara.SrcImageUBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr + ImageResolution;
                    ImageRotatePara.SrcImageVBuffAddr=(kal_uint32) pCbBuff->ImageBuffAddr + ImageResolution*5/4;

                    ImageRotatePara.DestImageYBuffAddr=VideoRotBuffAddr;
                    ImageRotatePara.DestImageUBuffAddr=VideoRotBuffAddr + ImageResolution;
                    ImageRotatePara.DestImageVBuffAddr=VideoRotBuffAddr + ImageResolution*5/4;

                    ImageRotatePara.ImageYBuffSize=ImageResolution;
                    ImageRotatePara.ImageUBuffSize=ImageResolution/4;
                    ImageRotatePara.ImageVBuffSize=ImageResolution/4;

                    VideoRotBuffAddr = (kal_uint32) pCbBuff->ImageBuffAddr;
                }
                else
                    ASSERT(0);
                // the working buffer is not necessary
                ImageRotatePara.WorkingBuffAddr=0;
                ImageRotatePara.WorkingBuffSize=0;
                SendMsgToCal(MSG_ID_CAL_ROTATE_IMAGE_REQ, &ImageRotatePara);
            }
            else
        #endif
            {
            #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
                if (CAL_CAMERA_SOURCE_MATV == CurrentCameraId)
                {
                    // matv do not support motion sensor, always return MPL_Ok to MPL
                    MplBuffInfo.eStatus = MPL_OK;
                }
                else
                {
                    if (KAL_TRUE == pCbBuff->IsVideoImageBuffRotReady)
                        MplBuffInfo.eStatus = MPL_OK;
                    else
                        MplBuffInfo.eStatus = MPL_INVALID_FRAME;
                }
            #else
                MplBuffInfo.eStatus = MPL_OK;
            #endif
                MplBuffInfo.pu1Address = (kal_uint8*) pCbBuff->ImageBuffAddr;
                CalVideoInfo.pfRetVideoBuff(MplBuffInfo);
            }
        break;
        case IDPCAL_CBID_CAM_PREVIEW_CRZ_FRM_START:
        case IDPCAL_CBID_VIDEO_ENCODE_CRZ_FRM_START:
        // 2. Notify ISP to set the result window, execute in MdpCallback()
            pIspDigitalZoomResParaIn=(P_ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT) CalFeatureCtrlBuff1;
            pIspDigitalZoomResParaOut=(P_ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT) CalFeatureCtrlBuff2;

        #ifdef __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
            if (KAL_TRUE==FastDigitalZoomPara.ZoomStart)
            {   // fast zoom
                if (KAL_TRUE==FastDigitalZoomPara.ZoomIn)
                {   // zoom in
                    if ((FastDigitalZoomPara.ZoomStep+CurrentZoomInfo.CurrentZoomStep)<=FastDigitalZoomPara.ZoomLimit)
                    {
                        CurrentZoomInfo.CurrentZoomStep+=FastDigitalZoomPara.ZoomStep;
                        pIspDigitalZoomResParaIn->ZoomStep=CurrentZoomInfo.CurrentZoomStep;
                        ZoomEnable=KAL_TRUE;
                        EnableCrzCb=KAL_TRUE;
                    }
                }
                else
                {   // zoom out
                    if (CurrentZoomInfo.CurrentZoomStep>=FastDigitalZoomPara.ZoomStep)
                    {
                        CurrentZoomInfo.CurrentZoomStep-=FastDigitalZoomPara.ZoomStep;
                        pIspDigitalZoomResParaIn->ZoomStep=CurrentZoomInfo.CurrentZoomStep;
                        ZoomEnable=KAL_TRUE;
                        EnableCrzCb=KAL_TRUE;
                    }
                }
            }
            else
        #endif
            {   // single step zoom
                pIspDigitalZoomResParaIn->ZoomStep=NextDigitalZoomStep;
                CurrentZoomInfo.CurrentZoomStep=NextDigitalZoomStep;
                ZoomEnable=KAL_TRUE;
            }

            if (KAL_TRUE==ZoomEnable)
            {
                ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, pIspDigitalZoomResParaIn,
                                                    pIspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                                    &FeatureOutLen);

                // 3. Notify MDP to configure CRZ, execute in MdpCallback()
                MdpDigitalZoomPara.mdp_crop_enable=pIspDigitalZoomResParaOut->MdpCropEnable;
                MdpDigitalZoomPara.updated_source_width=pIspDigitalZoomResParaOut->IspOutWidth;
                MdpDigitalZoomPara.updated_source_height=pIspDigitalZoomResParaOut->IspOutHeight;
                MdpDigitalZoomPara.cropped_width=pIspDigitalZoomResParaOut->DigitalZoomWidth;
                MdpDigitalZoomPara.cropped_height=pIspDigitalZoomResParaOut->DigitalZoomHeight;
                ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey, IDP_CAL_SET_ZOOM_PARAM, &MdpDigitalZoomPara);
            }

            if (KAL_FALSE==EnableCrzCb)
            {   // stop CRZ callback here
                ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey,  IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE, &EnableCrzCb);
            }
        #if (defined(__POSTPROC_SUPPORT__))
            if(gMdpPostProcFrmStableState==MDP_POSTPROC_FRM_STABLE)
            {
                PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_RESET, 0, 0, 0);
            }
            gMdpPostProcFrmStableState = MDP_POSTPROC_FRM_UNSTABLE;
        #endif /* defined(__POSTPROC_SUPPORT__) */
        break;
        case IDPCAL_CBID_CAM_CAPTURE_MAIN_IMAGE_DONE:
            if(CAL_CAMERA_CAPTURE_STATE == CalState)
            {
              stack_stop_timer(&CalTaskStackTimer);
            #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
              if (CAM_STILL_CAPTURE_RAW_DATA != CalStillCaptureMode)
            #endif
              {
            #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
            #endif
                {   // 1. stop timeout timer.
                    #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    if(!CalPanoEnabled)
                    #endif
                    {
                    // 2. if capture to memory is applied, rotate the main image first
                    // send a message to CAL task to rotate main image
                    if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                    {
                        ImageRotatePara.ImageRotAngle=CalStillCaptureInfo.MainImageRotAngle;
                        ImageRotatePara.SrcImageWidth=MdpStillCapturePara.fullsize_image_width;
                        ImageRotatePara.SrcImageHeight=MdpStillCapturePara.fullsize_image_height;

                        // dummy callback ID sncie is not necessary to do anything while callback
                        ImageRotatePara.ImageRotCbId=CAL_CBID_BEGIN;

                        ImageResolution = CalStillCaptureInfo.MainImageWidth * CalStillCaptureInfo.MainImageHeight;
                        ImageRotatePara.SrcImageYBuffAddr=pCbBuff->ImageBuffYAddr;
                        ImageRotatePara.SrcImageUBuffAddr=pCbBuff->ImageBuffUAddr;
                        ImageRotatePara.SrcImageVBuffAddr=pCbBuff->ImageBuffVAddr;

                        ImageRotatePara.DestImageYBuffAddr=pCbBuff->ImageBuffYAddr - ImageResolution *3/2;
                        // dest is 2nd buffer
                        if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE)
                        {
                            ImageRotatePara.DestImageYBuffAddr=pCbBuff->ImageBuffYAddr + ImageResolution *3/2;
                        }

                        ImageRotatePara.DestImageUBuffAddr=ImageRotatePara.DestImageYBuffAddr + ImageResolution;
                        ImageRotatePara.DestImageVBuffAddr=ImageRotatePara.DestImageUBuffAddr + (ImageResolution>>2);

                        ImageRotatePara.ImageYBuffSize=ImageResolution;
                        ImageRotatePara.ImageUBuffSize=ImageResolution/4;
                        ImageRotatePara.ImageVBuffSize=ImageResolution/4;

                        ImageRotatePara.ImageDataFormat=MM_IMAGE_FORMAT_YUV420;

                    #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
                        ImageRotatePara.ImageDataFormat=MM_IMAGE_FORMAT_RGB565;
                        ImageRotatePara.ImageYBuffSize=ImageResolution * 2;
                        ImageRotatePara.DestImageYBuffAddr=pCbBuff->ImageBuffYAddr - ImageResolution *2;
                    #elif defined(MT6235) || defined(MT6235B) || defined(MT6253)
                        if (MM_IMAGE_FORMAT_RGB565==CalStillCaptureInfo.MainImageJpegYuvSampleFormat)
                        {
                            ImageRotatePara.ImageDataFormat=MM_IMAGE_FORMAT_RGB565;
                            ImageRotatePara.ImageYBuffSize=ImageResolution * 2;
                            ImageRotatePara.DestImageYBuffAddr=pCbBuff->ImageBuffYAddr - ImageResolution *2;
                        }
                    #endif
                        pCbBuff->ImageBuffYAddr=ImageRotatePara.DestImageYBuffAddr;
                        pCbBuff->ImageBuffUAddr=ImageRotatePara.DestImageUBuffAddr;
                        pCbBuff->ImageBuffVAddr=ImageRotatePara.DestImageVBuffAddr;

                        // the working buffer is not necessary
                        ImageRotatePara.WorkingBuffAddr=0;
                        ImageRotatePara.WorkingBuffSize=0;
                        SendMsgToCal(MSG_ID_CAL_ROTATE_IMAGE_REQ, &ImageRotatePara);
                    }
                    }
                    #ifdef __CAL_QUICKVIEW_THUMBNAIL_HW_SUPPORT_ON_SW_JPEG_ENCODE__
                    if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                    #endif
                    {
                        // QVI rotate first.
                        if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE)
                        {
                            ImageRotatePara.ImageRotAngle=CalStillCaptureInfo.QuickViewImageRotAngle;
                            ImageRotatePara.SrcImageWidth=MdpStillCapturePara.fullsize_image_width;
                            ImageRotatePara.SrcImageHeight=MdpStillCapturePara.fullsize_image_height;

                            ImageRotatePara.ImageRotCbId=CAL_CBID_QUICK_VIEW_IMAGE_READY;

                            ImageResolution = CalStillCaptureInfo.MainImageWidth * CalStillCaptureInfo.MainImageHeight;
                            ImageRotatePara.SrcImageYBuffAddr=pCbBuff->ImageBuffYAddr;
                            ImageRotatePara.SrcImageUBuffAddr=pCbBuff->ImageBuffUAddr;
                            ImageRotatePara.SrcImageVBuffAddr=pCbBuff->ImageBuffVAddr;

                            // dest is 1st buffer
                            ImageRotatePara.DestImageYBuffAddr=pCbBuff->ImageBuffYAddr - ImageResolution *3/2;
                            ImageRotatePara.DestImageUBuffAddr=ImageRotatePara.DestImageYBuffAddr + ImageResolution;
                            ImageRotatePara.DestImageVBuffAddr=ImageRotatePara.DestImageUBuffAddr + (ImageResolution>>2);

                            ImageRotatePara.ImageYBuffSize=ImageResolution;
                            ImageRotatePara.ImageUBuffSize=ImageResolution/4;
                            ImageRotatePara.ImageVBuffSize=ImageResolution/4;

                            ImageRotatePara.ImageDataFormat=MM_IMAGE_FORMAT_YUV420;

                            // the working buffer is not necessary
                            ImageRotatePara.WorkingBuffAddr=0;
                            ImageRotatePara.WorkingBuffSize=0;
                            SendMsgToCal(MSG_ID_CAL_ROTATE_IMAGE_REQ, &ImageRotatePara);
                        }
                        else
                        {
                            // 3. send a meesage to CAL task to resize Main image as Quick view and thumbnail image.
                            MainImageResizePara.pCalStillCapPara=&CalStillCaptureInfo;
                            MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_QUICK_VIEW_IMAGE_READY;
                            MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_THUMBNAIL_IMAGE_READY;

                            MainImageResizePara.MainImageBuffAddr=pCbBuff->ImageBuffYAddr;
                            MainImageResizePara.MainImageBuffAddrU=pCbBuff->ImageBuffUAddr;
                            MainImageResizePara.MainImageBuffAddrV=pCbBuff->ImageBuffVAddr;

                            MainImageResizePara.pCalStillCapPara=&CalStillCaptureInfo;
                            MainImageResizePara.IsSrcClip=KAL_FALSE;

                            SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);
                        }
                    }
                #if ((defined(__PANORAMA_VIEW_SUPPORT__)&&defined(PANORAMA_INPUT_IMAGE_FORMAT_YUV420))||defined(__AUTOCAP_PANORAMA_SUPPORT__))
                    if(CalPanoEnabled)
                    {
                        PanoCbPara.ErrorStatus=MM_ERROR_NONE;
                        PanoCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_YUV420;
                        PanoCbPara.ImageBuffYAddr=pCbBuff->ImageBuffYAddr;
                        PanoCbPara.ImageBuffUAddr=pCbBuff->ImageBuffUAddr;
                        PanoCbPara.ImageBuffVAddr=pCbBuff->ImageBuffVAddr;
                        PanoCbPara.ImageBuffYSize=CalStillCaptureInfo.MainImageWidth*CalStillCaptureInfo.MainImageHeight;
                        PanoCbPara.ImageBuffUSize=PanoCbPara.ImageBuffVSize=PanoCbPara.ImageBuffYSize/4;

                    #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                        if(KAL_FALSE==MdpStillCapturePara.quickview_image_enable)
                    #endif
                        {
                            pfCalCallback(CAL_CBID_PANO_IMAGE_READY, &PanoCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
                        }

                        return ErrorCode;
                    }
                    else
                #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
                    {
                        // 4. send a message to CAL-LOW task to do SW JPEG encode operation
                        //SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ,NULL);
                        /* Send JpegEncodeMsg to low task after MdpClose in ImageResizeCallback */
                    #if defined(MT6235) || defined(MT6235B) || defined(MT6253) ||defined(MT6252)||defined(MT6252H)||defined(MT6255)||defined(MT6250)||defined(MT6260)
                        #if defined(MT6255)
                        if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
                        #endif
                        {
                        JpegEncPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
                        JpegEncPara.pJpegWrapperPara=&JpegWrapper;
                    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                        SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #else
                        JpegWrapper.callback_function=NULL;
                        SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #endif
                        }
                  #endif
                    }
                }
              }
              #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
              else // Capture Mode == CAM_STILL_CAPTURE_RAW_DATA
              {
                CAL_BUFFER_CB_STRUCT MainImageCbPara;

                MainImageCbPara.ErrorStatus=MM_ERROR_NONE;
                MainImageCbPara.ImageBuffFormat=CalStillCaptureInfo.MainImageDataFormat;
                MainImageCbPara.ImageBuffAddr=CalStillCaptureInfo.MainImageBuffAddr;
                MainImageCbPara.ImageBuffSize= CalStillCaptureInfo.MainImageBuffSize;
                pfCalCallback(CAL_CBID_STILL_IMAGE_READY, &MainImageCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
              }
              #endif
            }
        #ifdef WEBCAM_SUPPORT
            else if (CAL_WEBCAM_PREVIEW_STATE == CalState || CAL_WEBCAM_CAPTURE_STATE == CalState)
            {
                #ifdef WEBCAM_SUPPORT
                    ///Bin: this is only for SW JPEG Encoder platform
                    CalWebcamSendFrameReadyRequest(JPEG_CODEC_STATE_FREE);
                #else
                    ASSERT(0);
                #endif
            }
        #endif
        break;
    #ifdef __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
        case IDPCAL_CBID_CAM_CAPTURE_QUICKVIEW_IMAGE_DONE:
        #ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
            if (MM_IMAGE_COLOR_FORMAT_RGB565==CalStillCaptureInfo.QuickViewImageFormat)
            {   // send a message to do Y2R and dithering
                ImageY2RDitheringPara.ImageWidth=CalStillCaptureInfo.QuickViewImageWidth;
                ImageY2RDitheringPara.ImageHeight=CalStillCaptureInfo.QuickViewImageHeight;
                ImageY2RDitheringPara.ImageBuffAddr=pCbBuff->ImageBuffAddr;
                SendMsgToCal(MSG_ID_CAL_SW_Y2R_DITHERING_REQ, &ImageY2RDitheringPara);
                break;
            }
        #endif
            CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT;

                // callback to MED for quick view display.
                pCbBuff->ErrorStatus=MM_ERROR_NONE;
        #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
            if((CAL_SCENARIO_CAMERA_ZSD_CAPTURE==CurrentStillScenarioId)&&(CalStillCaptureInfo.ThumbnailImageEnable))
            {
                kal_mem_cpy(&MdpZsdResizePara, &CalStillCaptureInfo, sizeof(CAL_MDP_STILL_CAPTURE_STRUCT));
                MdpZsdResizePara.QuickViewImageEnable=KAL_FALSE;
                MdpZsdResizePara.MainImageWidth=CalStillCaptureInfo.QuickViewImageWidth;
                MdpZsdResizePara.MainImageHeight=CalStillCaptureInfo.QuickViewImageHeight;
                MdpZsdResizePara.MainImageBuffAddr=pCbBuff->ImageBuffAddr;
                MdpZsdResizePara.MainImageBuffSize=CalStillCaptureInfo.QuickViewImageBuffSize;
                MdpZsdResizePara.MainImageJpegYuvSampleFormat=CalStillCaptureInfo.QuickViewImageFormat;
                MainImageResizePara.pCalStillCapPara=&MdpZsdResizePara;
                MainImageResizePara.MainImageBuffAddr=pCbBuff->ImageBuffAddr;
                MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_THUMBNAIL_IMAGE_READY;
                MainImageResizePara.IsSrcClip=KAL_FALSE;

                if(MM_IMAGE_FORMAT_RGB565==CalStillCaptureInfo.QuickViewImageFormat)
                {
                    //Working memory for RGB565 to RGB565
                    MainImageResizePara.WorkingBuffAddr=MdpStillCapturePara.extmem_start_address;
                    MainImageResizePara.WorkingBuffSize=MdpStillCapturePara.extmem_size;
                }
                SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);
            }
        #endif /* __ZERO_SHUTTER_DELAY_SUPPORT__ */
            // check whether to rotate quick view image or not
            if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
            {
                ImageRotatePara.ImageDataFormat=CalStillCaptureInfo.QuickViewImageFormat;
                ImageRotatePara.ImageRotAngle=CalStillCaptureInfo.QuickViewImageRotAngle;
                ImageRotatePara.SrcImageWidth=CalStillCaptureInfo.QuickViewImageWidth;
                ImageRotatePara.SrcImageHeight=CalStillCaptureInfo.QuickViewImageHeight;
                ImageRotatePara.ImageRotCbId=CAL_CBID_QUICK_VIEW_IMAGE_READY;

                ImageResolution = CalStillCaptureInfo.QuickViewImageWidth * CalStillCaptureInfo.QuickViewImageHeight;

                ImageRotatePara.SrcImageYBuffAddr=pCbBuff->ImageBuffAddr;
                ImageRotatePara.DestImageYBuffAddr=QuickViewImageDestBuffAddr;//CalStillCaptureInfo.QuickViewImageBuffAddr;
                ImageRotatePara.ImageYBuffSize=ImageResolution*2;

                // the working buffer is not necessary
                ImageRotatePara.WorkingBuffAddr=0;
                ImageRotatePara.WorkingBuffSize=0;
                SendMsgToCal(MSG_ID_CAL_ROTATE_IMAGE_REQ, &ImageRotatePara);

                // since the quick view image will rotate to another buffer, the source of
                // JAIA quick view image should be the image before rotate.
                CalStillCaptureInfo.QuickViewImageBuffAddr=pCbBuff->ImageBuffAddr;
            }
            else
            {
                pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        break;
        case IDPCAL_CBID_CAM_CAPTURE_THUMBNAIL_IMAGE_DONE:
            CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT;
        break;
    #endif  // __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
        case IDPCAL_CBID_CAM_CAPTURE_CROP_SIZE_IMAGE_DONE:
        #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
            if ((MM_ERROR_NONE == pCbCropBuff->ErrorStatus) &&
                (CAM_EFFECT_ENC_LOMO <= CalImageEffect))
            {
                ImageEffectPara.SrcImageWidth=pCbCropBuff->ImageBuffWidth;
                ImageEffectPara.SrcImageHeight=pCbCropBuff->ImageBuffHeight;
                ImageEffectPara.ImageEffectCbId=CAL_CBID_CAPTURE_IMAGE_EFFECT_READY;
                ImageEffectPara.SrcImageYBuffAddr=pCbCropBuff->ImageBuffYAddr;
                ImageEffectPara.SrcImageUBuffAddr=pCbCropBuff->ImageBuffUAddr;
                ImageEffectPara.SrcImageVBuffAddr=pCbCropBuff->ImageBuffVAddr;
                ImageEffectPara.DestImageYBuffAddr=pCbCropBuff->ImageBuffYAddr;
                ImageEffectPara.DestImageUBuffAddr=pCbCropBuff->ImageBuffUAddr;
                ImageEffectPara.DestImageVBuffAddr=pCbCropBuff->ImageBuffVAddr;
                if (MM_IMAGE_FORMAT_PACKET_UYVY422 == pCbCropBuff->ImageBuffFormat)
                {
                    ImageEffectPara.ImageYBuffSize=pCbCropBuff->ImageBuffWidth*pCbCropBuff->ImageBuffHeight*2;
                }
                else if (MM_IMAGE_FORMAT_YUV420 == pCbCropBuff->ImageBuffFormat)
                {
                    ImageEffectPara.ImageYBuffSize=pCbCropBuff->ImageBuffWidth*pCbCropBuff->ImageBuffHeight;
                    ImageEffectPara.ImageUBuffSize=ImageEffectPara.ImageYBuffSize/4;
                    ImageEffectPara.ImageVBuffSize=ImageEffectPara.ImageYBuffSize/4;
                }
                ImageEffectPara.ImageDataFormat=pCbCropBuff->ImageBuffFormat;
                ImageEffectPara.ImageEffectId=CalImageEffect;
                pMdpCropBufferCb = pCbCropBuff->CropBufferCbfn;
                SendMsgToCal(MSG_ID_CAL_SW_IMAGE_EFFECT_REQ, &ImageEffectPara);
            }
            else
        #endif  /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
            {
                if (pCbCropBuff->CropBufferCbfn)
                    pCbCropBuff->CropBufferCbfn(0);
            }
        break;
        default:
        break;
    }

    if (CAL_CAMERA_CAPTURE_STATE==CalState)
    {
        #ifdef LED_FLASHLIGHT_SUPPORT
        if (CurrentStillCaptureStatus & CAL_STILL_CAPTURE_IMAGE_MASK)
        {
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_STOP_FLASHLIGHT_PROCESS_AFTER_CAPTURE_DONE, NULL, NULL, 0, 0);
        }
        #endif
        #if defined(EXIF_SUPPORT)
        SendJaiaMergeMsg();
        #endif
    }

    return ErrorCode;
} /* MdpCallback() */

#if defined(__POSTPROC_SUPPORT__)
void CalConfigJpgEnc(P_CAL_PP_CB_JPG_INFO_CONFIG pCalCbConfig)
{
    JpegWrapper.srcWidth=pCalCbConfig->ImgWidth;
    JpegWrapper.srcHeight=pCalCbConfig->ImgHeight;
    JpegWrapper.dstWidth=pCalCbConfig->ImgWidth;
    JpegWrapper.dstHeight=pCalCbConfig->ImgHeight;

    if(MM_IMAGE_FORMAT_YUV420==pCalCbConfig->ImgFormat)
    {
        JpegWrapper.srcSamplingFormat=JPEG_YUV_FORMAT_YUV420;
        if(KAL_TRUE==IsHwJpegEncSupport)
            JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV422;
        else
            JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV420;
    }
    else if(MM_IMAGE_FORMAT_RGB565 == pCalCbConfig->ImgFormat)
    {
        JpegWrapper.srcSamplingFormat=JPEG_YUV_FORMAT_YUV422;     //Don't care
        JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV422;
    }
    else
        ASSERT(0);
    JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_EXIF;

    JpegWrapper.enableThumbnail=pCalCbConfig->ThumbnailEnable;
    JpegWrapper.callback_function=JpegEncCallback;

    if (MM_IMAGE_FORMAT_YUV420 == pCalCbConfig->ImgFormat)
    {
        JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_YUV_BUFFER;
        JpegWrapper.srcYUVBuffer[0]=(void *)pCalCbConfig->ImgBufferAddr;
        JpegWrapper.srcBufferSize[0]=pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight;
        JpegWrapper.srcYUVBuffer[1]=(void *)(pCalCbConfig->ImgBufferAddr+pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight);
        JpegWrapper.srcBufferSize[1]=(pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight)/4;
        JpegWrapper.srcYUVBuffer[2]=(void *)(pCalCbConfig->ImgBufferAddr+(pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight*5)/4);
        JpegWrapper.srcBufferSize[2]=(pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight)/4;
    }
    else if(MM_IMAGE_FORMAT_RGB565 == pCalCbConfig->ImgFormat)
    {
        JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_RGB_BUFFER;
        JpegWrapper.srcRGBFormat=JPEG_RGB_FORMAT_RGB565;
        JpegWrapper.srcRGBBuffer =(void *)pCalCbConfig->ImgBufferAddr;
        JpegWrapper.srcBufferSize[0]=pCalCbConfig->ImgWidth*pCalCbConfig->ImgHeight*2;
    }
    else
        ASSERT(0);
}
#endif

#if (defined(EXIF_SUPPORT)&&defined(__3D_IMAGE_SUPPORT__))
static void ExifUpdate3DCamParaStruct(exif_cam_para_struct *exif_cam_para_ptr)
{
    extern kal_uint8 IspAeMeteringModeTbl[CAM_NO_OF_AE_METERING];
    extern kal_uint8 IspLightSourceModeTbl[CAM_NO_OF_WB];
    extern kal_uint32 IspGetDigitalZoomFactor(void);
    extern CAL_ISP_PREVIEW_STRUCT CalMavIspPreviewPara;
    kal_uint8 meteringmode=0,lightsource=0,scenetype=0;

    exif_cam_para_ptr->Orientation = MM_IMAGE_ROTATE_0;
    exif_cam_para_ptr->ImageDescription = "3D";
    exif_cam_para_ptr->FNumber[0] = 28;
    exif_cam_para_ptr->FNumber[1] = 10;
    exif_cam_para_ptr->ExposureProgram = 2;
    exif_cam_para_ptr->PixelXDimension = JpegWrapper.dstWidth;/* global variable */
    exif_cam_para_ptr->PixelYDimension = JpegWrapper.dstHeight;/* global variable */
    exif_cam_para_ptr->DigitalZoomRatio[0] = IspGetDigitalZoomFactor();/* global variable */
    exif_cam_para_ptr->DigitalZoomRatio[1] = 100;
    exif_cam_para_ptr->ExposureBiasValue[0] = 5*((kal_int8)CalMavIspPreviewPara.EvValue- 4);
    exif_cam_para_ptr->ExposureBiasValue[1] = 10;
    exif_cam_para_ptr->ISOSpeedRatings = 100;
    exif_cam_para_ptr->Flash = 0;
    if(CAM_NO_OF_AE_METERING > CalMavIspPreviewPara.AeMeteringMode)
    {
        meteringmode= IspAeMeteringModeTbl[CalMavIspPreviewPara.AeMeteringMode] ;
    }
    else
    {
        meteringmode=0;
    }
    /* awb setting */
    if(CAM_NO_OF_WB > CalMavIspPreviewPara.WbMode)
    {
        lightsource = IspLightSourceModeTbl[CalMavIspPreviewPara.WbMode];
    }
    else
    {
        lightsource=0;
    }

    if(CAM_AUTO_DSC == CalMavIspPreviewPara.SceneMode)
    {
        scenetype=0;
    }
    else if(CAM_LANDSCAPE == CalMavIspPreviewPara.SceneMode)
    {
        scenetype=1;
    }
    else if(CAM_PORTRAIT == CalMavIspPreviewPara.SceneMode)
    {
        scenetype=2;
    }
    else if(CAM_NIGHTSCENE == CalMavIspPreviewPara.SceneMode)
    {
        scenetype=3;
    }
    else
    {
        scenetype=0;
    }
    exif_cam_para_ptr->SceneCaptureType=scenetype;
    exif_cam_para_ptr->MeteringMode = meteringmode;
    exif_cam_para_ptr->LightSource = lightsource;
}
#endif /* EXIF_SUPPORT && __3D_IMAGE_SUPPORT__ */

MM_ERROR_CODE_ENUM PpCallback(PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if (defined(__POSTPROC_SUPPORT__))
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    AAA_FACE_INFO_STRUCT FaceInfo;
    P_FD_RESULT_STRUCT pFdResult;
    P_SD_RESULT_STRUCT pSdResult;
    #if (defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__))
    P_PANO_RESULT_STRUCT pPanoResult;
    kal_uint32 Offset;
    PP_FEATURE_CTRL_STRUCT_UNION PpFeaturePara;
    PP_FEATURE_CONFIG_INFO_STRUCT    PpFeatureMemPara;
    kal_uint32 Temp;
    const kal_uint16 Divider=16;
    kal_uint16 i;
    #endif
    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    P_HDR_RESULT_STRUCT pHdrResult;
    #endif
    #if defined(__AUTO_SCENE_DETECT_SUPPORT__ )
    P_ASD_FINAL_RESULT_STRUCT pAsdResult;
    #endif
    kal_uint32 FeatureOutLen;
    #if (defined(__PANORAMA_VIEW_SUPPORT__) || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
    CAL_SW_JPEG_ENCODE_REQ_STRUCT LocalPara;
    #endif
    PP_FEATURE_CTRL_STRUCT_UNION FeatureOut;
    PP_FEATURE_GET_OPMODE_STRUCT FuncOpMode;
    /* Send Message */
    P_PP_PROC_REQ_STRUCT            pPpProcReq;

    #if (defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)|| defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
    CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT MainImageResizePara;
    CAL_PP_CB_JPG_INFO_CONFIG JpgInfo;
    #endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
    CAL_MAV_RESULT_STRUCT MavCbPara;
    P_MAVCAP_RESULT_STRUCT pMavCapResult;
    P_MAV_RESULT_STRUCT pMavResult;
#endif

    CalTrace(CAL_TRACE_CBF,CAL_CBF_PP,CbId,drv_get_current_time());
    switch (CbId)
    {
        case PP_CBID_POSTPROC_START:
            pPpProcReq = (P_PP_PROC_REQ_STRUCT)pCallbackPara;
            FeatureOut.pFuncOpMode = &FuncOpMode;

            //PpFeatureCtrl((PP_FUNC_ENUM)pPpProcReq->FuncId, PP_FEATURE_GET_OPMODE, 0, &FeatureOut, 0);
            PpFeatureCtrl((PP_FUNC_ENUM)pPpProcReq->FuncId, PP_FEATURE_GET_OPMODE, pPpProcReq->pParaIn, &FeatureOut, 0);

            if (PP_PROC_PRIORITY_HIGH == FuncOpMode.Priority)
            {
                if (PP_PROC_TYPE_TRIGGER == FuncOpMode.Type)
                {
                    SendMsgToCal(MSG_ID_CAL_PP_START_REQ, pPpProcReq);
                }
                else
                {
                    ASSERT(0);
                }
            }
            else    /* PP_PRCO_PRIORITY_LOW */
            {
                if (PP_PROC_TYPE_TIMER == FuncOpMode.Type)
                {
                    SendMsgToCal(MSG_ID_CAL_LOW_PP_START_TIMER_REQ, pPpProcReq);
                }
                else
                {
                    SendMsgToCal(MSG_ID_CAL_LOW_PP_START_REQ, pPpProcReq);
                }
            }
        break;
        case PP_CBID_POSTPROC_STOP:
            pPpProcReq = (P_PP_PROC_REQ_STRUCT)pCallbackPara;
            FeatureOut.pFuncOpMode = &FuncOpMode;

            PpFeatureCtrl((PP_FUNC_ENUM)pPpProcReq->FuncId, PP_FEATURE_GET_OPMODE, pPpProcReq->pParaIn, &FeatureOut, 0);
            if (PP_PROC_PRIORITY_HIGH == FuncOpMode.Priority)
            {
                SendMsgToCal(MSG_ID_CAL_PP_START_REQ, pPpProcReq);
            }
            else    /* PP_PRCO_PRIORITY_LOW */
            {
                SendMsgToCal(MSG_ID_CAL_LOW_PP_STOP_REQ, pPpProcReq);
            }
        break;
    #if (defined(__FACE_DETECTION_SUPPORT__))
        case PP_CBID_FD_RESULT:
            pfCalCallback(CAL_CBID_FD_RESULT, pCallbackPara, CallbackParaLen);
            //Update FD result by ISP feature control
            pFdResult = (P_FD_RESULT_STRUCT)pCallbackPara;
            FaceInfo.FaceNo = pFdResult->face_no;
            FaceInfo.FaceLum = pFdResult->rect_lum[0];
            FaceInfo.FdEnable = KAL_TRUE;
            FaceInfo.SdEnable = KAL_FALSE;
            FaceInfo.ResultCounter = pFdResult->result_counter;
            FaceInfo.FaceX0 = pFdResult->detect_x0[0];
            FaceInfo.FaceY0 = pFdResult->detect_y0[0];
            FaceInfo.FaceX1 = pFdResult->detect_x1[0];
            FaceInfo.FaceY1 = pFdResult->detect_y1[0];
            FaceInfo.ImgSrcWidth = pFdResult->image_width;
            FaceInfo.ImgSrcHeight = pFdResult->image_height;
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_FACE_INFO, (void *) &FaceInfo, NULL, 0, &FeatureOutLen);
            #if defined(__AUTO_SCENE_DETECT_SUPPORT__)
            if(CalAsdEnabled)
            {
                IspSceneCompensationParaIn.FaceLuminance = FaceInfo.FaceLum;
            }
            #endif
        break;
    #endif /* defined(__FACE_DETECTION_SUPPORT__) */
    #if (defined(__SMILE_SHUTTER_SUPPORT__))
        case PP_CBID_SD_RESULT:
            if (KAL_TRUE==((P_SD_RESULT_STRUCT)pCallbackPara)->sd_end_flag)
            {
                gMdpPostProcTrigger = KAL_FALSE;
            }
            pfCalCallback(CAL_CBID_SD_RESULT, pCallbackPara, CallbackParaLen);  // MMI/MED
            //Update SD result by ISP feature control
            pSdResult = (P_SD_RESULT_STRUCT)pCallbackPara;
            FaceInfo.FaceNo = pSdResult->face_no;
            FaceInfo.FaceLum = pSdResult->rect_lum[0];
            FaceInfo.FdEnable = KAL_TRUE;
            FaceInfo.SdEnable = KAL_TRUE;

            FaceInfo.FaceX0 = pSdResult->sd_rect_x0[0];
            FaceInfo.FaceY0 = pSdResult->sd_rect_y0[0];
            FaceInfo.FaceX1 = pSdResult->sd_rect_x1[0];
            FaceInfo.FaceY1 = pSdResult->sd_rect_y1[0];
            FaceInfo.ImgSrcWidth = pSdResult->image_width;
            FaceInfo.ImgSrcHeight = pSdResult->image_height;
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_FACE_INFO, (void *) &FaceInfo, NULL, 0, &FeatureOutLen);
        break;
    #endif /* defined(__SMILE_SHUTTER_SUPPORT__) */
    #if (defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__))
        case PP_CBID_PANO_RESULT:
            // For panorama stitched imgae ready. And will start to do quick view and JPEG encode handle

            if(IsPanoPaused) //Pano callback after pause, boundary case
            {
                //Skip any activity due to pause by MED
                return ErrorCode;
            }
            if(CAL_PANO_STITCHING_STATE==CalPanoState)  //Normal case
                CalPanoState = CAL_PANO_STITCHED_STATE;
            else if(CAL_PANO_STOPPING_STATE==CalPanoState)  //PpCallback occurs after CalPostProcCtrl stop, do nothing
                return ErrorCode;
            else
                ASSERT(0);

            pPanoResult = (P_PANO_RESULT_STRUCT)pCallbackPara;
            CalPanoPostProcPara.MainImageWidth = pPanoResult->ImgWidth;
            CalPanoPostProcPara.MainImageHeight = pPanoResult->ImgHeight;
            //========================== For quick view ===================================
            if(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageEnable)
            {
                MainImageResizePara.pCalStillCapPara = &CalStillCaptureInfo;
                MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY;
                MainImageResizePara.MainImageBuffAddr = pPanoResult->ImgBufferAddr;
                MainImageResizePara.pCalStillCapPara->MainImageWidth = pPanoResult->ImgWidth;
                MainImageResizePara.pCalStillCapPara->MainImageHeight = pPanoResult->ImgHeight;
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = pPanoResult->ImgFormat;
                //These two attributes only for Jaia
                MainImageResizePara.pCalStillCapPara->MainImageBuffAddr = (kal_uint32)(JpegWrapper.dstBufferAddr)-CAL_JAIA_MEMORY_OFFSET;
                MainImageResizePara.pCalStillCapPara->MainImageBuffSize = JpegWrapper.dstBufferSize+CAL_JAIA_MEMORY_OFFSET;
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                if(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageResizeByBuffSizeEnable)
                {
                    Temp=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffSize*Divider*Divider)/(pPanoResult->ImgHeight*pPanoResult->ImgWidth*2);
                    for(i=Divider; i>0; i--)
                    {
                        if(i*i<=Temp)
                            break;
                    }
                    CalPanoPostProcPara.QuickViewPanoImageWidth=pPanoResult->ImgWidth*i/Divider;
                    CalPanoPostProcPara.QuickViewPanoImageHeight=pPanoResult->ImgHeight*i/Divider;

                    MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr=CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr;

                    if(pPanoResult->ImgWidth*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight>=
                            pPanoResult->ImgHeight*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth)
                    {
                        CalPanoPostProcPara.ImageAlignmentHandle=KAL_FALSE;
                    }
                    else
                    {
                        CalPanoPostProcPara.ImageAlignmentHandle=KAL_TRUE;
                    }
                }
                else
                {
            #endif /* defined(__AUTOCAP_PANORAMA_SUPPORT__) */
                if(pPanoResult->ImgWidth*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight>=
                        pPanoResult->ImgHeight*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth)
                {
                    CalPanoPostProcPara.QuickViewPanoImageWidth = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth;
                    CalPanoPostProcPara.QuickViewPanoImageHeight = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*pPanoResult->ImgHeight/pPanoResult->ImgWidth;
                    CalPanoPostProcPara.ImageAlignmentHandle=KAL_FALSE;
                }
                else
                {
                    CalPanoPostProcPara.QuickViewPanoImageWidth = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight*pPanoResult->ImgWidth/pPanoResult->ImgHeight;
                    CalPanoPostProcPara.QuickViewPanoImageHeight = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight;
                    CalPanoPostProcPara.ImageAlignmentHandle=KAL_TRUE;
                }

                if((MM_IMAGE_FORMAT_RGB565==CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat)||
                   (MM_IMAGE_FORMAT_PACKET_UYVY422==CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat))
                {
                    if(!CalPanoPostProcPara.ImageAlignmentHandle)
                    {
                        Offset=((CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight-CalPanoPostProcPara.QuickViewPanoImageHeight)/2)*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*2;
                        MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+Offset;
                    }
                    else
                    {
                        Offset = (CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight-
                                    CalPanoPostProcPara.QuickViewPanoImageWidth*CalPanoPostProcPara.QuickViewPanoImageHeight)*2;
                        MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+Offset;
                    }
                }
                else if(MM_IMAGE_FORMAT_YUV420==CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat)
                {
                    Offset = (CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight-
                              CalPanoPostProcPara.QuickViewPanoImageWidth*CalPanoPostProcPara.QuickViewPanoImageHeight)*3/2;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+Offset;
                }
                else
                    ASSERT(0);
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                }
            #endif
                MainImageResizePara.pCalStillCapPara->QuickViewImageBuffSize = CalPanoPostProcPara.QuickViewPanoImageWidth*CalPanoPostProcPara.QuickViewPanoImageHeight*2;
                MainImageResizePara.pCalStillCapPara->QuickViewImageEnable = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageEnable;
                MainImageResizePara.pCalStillCapPara->QuickViewImageFormat = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat;
                MainImageResizePara.pCalStillCapPara->QuickViewImageRotAngle = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageRotAngle;
                MainImageResizePara.pCalStillCapPara->QuickViewImageWidth = CalPanoPostProcPara.QuickViewPanoImageWidth;
                MainImageResizePara.pCalStillCapPara->QuickViewImageHeight = CalPanoPostProcPara.QuickViewPanoImageHeight;
                MainImageResizePara.pCalStillCapPara->ThumbnailImageEnable = KAL_FALSE;     //Panorama stitch image don't support Thumbnail

                //Working memory only for RGB565 to RGB565 (MT6268)
                if(MM_IMAGE_FORMAT_RGB565==pPanoResult->ImgFormat)
                {
                    //RGB SW resizer working memory (same with JPEG working memory) = total - Pano stitch used(JPEG decode)
                    PpFeaturePara.pConfigInfo = &PpFeatureMemPara;
                    PpFeatureCtrl(PP_FUNC_PANORAMA, PP_FEATURE_GET_ENV_INFO, 0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));
                    MainImageResizePara.WorkingBuffAddr=(kal_uint32)JpegWrapper.extMemoryAddr+PpFeatureMemPara.ExtmemSize;
                    MainImageResizePara.WorkingBuffSize=JpegWrapper.extMemorySize-PpFeatureMemPara.ExtmemSize;
                }
                if(MM_IMAGE_FORMAT_RGB565==CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat)
                    MainImageResizePara.IsSrcClip=KAL_FALSE;
                else //UYVY422
                {
                    MainImageResizePara.IsSrcClip=KAL_TRUE;

                    JpegWrapper.srcWindow.x=0;
                    JpegWrapper.srcWindow.y=0;
                    JpegWrapper.srcWindow.w=MainImageResizePara.pCalStillCapPara->MainImageWidth & ~0x00000001;
                    JpegWrapper.srcWindow.h=MainImageResizePara.pCalStillCapPara->MainImageHeight& ~0x00000001;
                    CalPanoPostProcPara.QuickViewPanoImageWidth  &= ~0x00000001;
                    CalPanoPostProcPara.QuickViewPanoImageHeight &= ~0x00000001;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageWidth = CalPanoPostProcPara.QuickViewPanoImageWidth;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageHeight = CalPanoPostProcPara.QuickViewPanoImageHeight;
                    MainImageResizePara.pSrcWindow = (iul_rect *)(&JpegWrapper.srcWindow);
                }

            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                //Put Jpeg Encode info. handle prior to send message to CAL task for the case of PLUTO MMI
                JpgInfo.ImgBufferAddr = pPanoResult->ImgBufferAddr;
                JpgInfo.ImgFormat = pPanoResult->ImgFormat;
                JpgInfo.ImgWidth = pPanoResult->ImgWidth;
                JpgInfo.ImgHeight = pPanoResult->ImgHeight;
                JpgInfo.ThumbnailEnable = KAL_FALSE; //Panorama stitch image don't support Thumbnail

                CalConfigJpgEnc(&JpgInfo);

                JpegWrapper.extMemoryAddr=(void *)((kal_uint32)JpegWrapper.dstBufferAddr+JpegWrapper.dstBufferSize-JPEG_ENC_PANORAMA_YUV420_EXT_MIN_MEM_SIZE);
                JpegWrapper.extMemorySize=JPEG_ENC_PANORAMA_YUV420_EXT_MIN_MEM_SIZE; //200000;   // tmp (JPEG_ENC_PANORAMA_YUV420_EXT_MIN_MEM_SIZE)
            #endif

                SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);
            }
            //========================== For JPEG Encode ===================================
        #if defined(__PANORAMA_VIEW_SUPPORT__)
            JpgInfo.ImgBufferAddr = pPanoResult->ImgBufferAddr;
            JpgInfo.ImgFormat = pPanoResult->ImgFormat;
            JpgInfo.ImgWidth = pPanoResult->ImgWidth;
            JpgInfo.ImgHeight = pPanoResult->ImgHeight;
            JpgInfo.ThumbnailEnable = KAL_FALSE; //Panorama stitch image don't support Thumbnail

            CalConfigJpgEnc(&JpgInfo);

            //JPEG encode working memory = total - Pano stitch used(JPEG decode)
            PpFeaturePara.pConfigInfo = &PpFeatureMemPara;
            PpFeatureCtrl(PP_FUNC_PANORAMA, PP_FEATURE_GET_ENV_INFO, 0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));
            JpegWrapper.extMemoryAddr=(void *)((kal_uint32)JpegWrapper.extMemoryAddr+PpFeatureMemPara.ExtmemSize);
            JpegWrapper.extMemorySize=JpegWrapper.extMemorySize-PpFeatureMemPara.ExtmemSize;

            LocalPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
            LocalPara.pJpegWrapperPara = &JpegWrapper;

        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if (KAL_TRUE==IsHwJpegEncSupport)
                SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &LocalPara);
            else
        #endif
                SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &LocalPara);

            CalPanoState=CAL_PANO_ENCODING_STATE;
        #endif /* defined(__PANORAMA_VIEW_SUPPORT__) */
        break;
        case PP_CBID_PANO_BG_STITCH_READY:
            pfCalCallback(CAL_CBID_PANO_BG_ADD_IMAGE_READY, pCallbackPara, CallbackParaLen);
        break;
    #endif //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
    #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
        case PP_CBID_AUTOCAP_RESULT:
            pfCalCallback(CAL_CBID_AUTOCAP_RESULT, pCallbackPara, CallbackParaLen);
        break;
    #endif // __AUTOCAP_PANORAMA_SUPPORT__
    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        case PP_CBID_HDR_RESULT:
            // abort handling
            if (IsHdrAborted )
            {
                if(CalEventId!=NULL)
                    kal_set_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT,KAL_OR);
                return ErrorCode;
            }
            CalHdrState = CAL_HDR_QVI_STATE;

            // HDR ready, start to quick view and JPEG encode
            pHdrResult = (P_HDR_RESULT_STRUCT)pCallbackPara;

            ASSERT(pHdrResult->ImgWidth == CalMdpPostProcPara.MainImageWidth);
            ASSERT(pHdrResult->ImgHeight == CalMdpPostProcPara.MainImageHeight);
            //========================== For quick view & thumbnail ===================================
            if(CalMdpPostProcPara.QuickViewImageEnable || CalMdpPostProcPara.ThumbnailImageEnable)
            {
                // switch src to cacheable. for SW QVI
                CalExtMemSwitchCachableRegion(&(pHdrResult->ImgBufferAddr), pHdrResult->ImgWidth*pHdrResult->ImgHeight*3/2 , KAL_TRUE);

                // fill main image info (as src)
                MainImageResizePara.pCalStillCapPara = &CalStillCaptureInfo;
                MainImageResizePara.MainImageBuffAddr = pHdrResult->ImgBufferAddr;                    // main image(src) addr
                MainImageResizePara.pCalStillCapPara->MainImageWidth = pHdrResult->ImgWidth;    // main width
                MainImageResizePara.pCalStillCapPara->MainImageHeight = pHdrResult->ImgHeight;  // main height
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = pHdrResult->ImgFormat;

                // fill jaia result image info
                MainImageResizePara.pCalStillCapPara->MainImageBuffAddr = (kal_uint32)(JpegWrapper.dstBufferAddr)-CAL_JAIA_MEMORY_OFFSET;
                MainImageResizePara.pCalStillCapPara->MainImageBuffSize = JpegWrapper.dstBufferSize+CAL_JAIA_MEMORY_OFFSET;

                if(CalMdpPostProcPara.QuickViewImageEnable)
                {
                    // fill quickview image info (as dst)
                    MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageEnable = CalMdpPostProcPara.QuickViewImageEnable;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr = CalMdpPostProcPara.QuickViewImageBuffAddr;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageWidth = CalMdpPostProcPara.QuickViewImageWidth;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageHeight = CalMdpPostProcPara.QuickViewImageHeight;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageFormat = CalMdpPostProcPara.QuickViewImageFormat;
                    MainImageResizePara.pCalStillCapPara->QuickViewImageRotAngle = CalMdpPostProcPara.QuickViewImageRotAngle;
                }

                if(CalMdpPostProcPara.ThumbnailImageEnable)
                {
                    // fill thumbnail image info (as dst)
                    MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_THUMBNAIL_IMAGE_READY;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageEnable = CalMdpPostProcPara.ThumbnailImageEnable;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageBuffAddr = CalMdpPostProcPara.ThumbnailImageBuffAddr;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageWidth = CalMdpPostProcPara.ThumbnailImageWidth;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageHeight = CalMdpPostProcPara.ThumbnailImageHeight;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageFormat = CalMdpPostProcPara.ThumbnailImageFormat;
                    MainImageResizePara.pCalStillCapPara->ThumbnailImageRotAngle = CalMdpPostProcPara.ThumbnailImageRotAngle;
                }
                MainImageResizePara.IsSrcClip=KAL_FALSE;
                SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);
            }

            //========================== For JPEG Encode ===================================
            // set jpeg wrapper
            CalExtMemSwitchCachableRegion(&(pHdrResult->ImgBufferAddr), pHdrResult->ImgWidth*pHdrResult->ImgHeight*3/2 , CalHdrUseSwEncoder);
            CalExtMemSwitchCachableRegion((kal_uint32*)&(JpegWrapper.dstBufferAddr), JpegWrapper.dstBufferSize, CalHdrUseSwEncoder);

            JpgInfo.ImgBufferAddr = pHdrResult->ImgBufferAddr;
            JpgInfo.ImgFormat = pHdrResult->ImgFormat;
            JpgInfo.ImgWidth = pHdrResult->ImgWidth;
            JpgInfo.ImgHeight = pHdrResult->ImgHeight;
            JpgInfo.ThumbnailEnable = KAL_FALSE;
            CalConfigJpgEnc(&JpgInfo);

            if(CalHdrUseSwEncoder)  // dst format should be YUV420 same with src
            {
                JpegWrapper.dstSamplingFormat = JpegWrapper.srcSamplingFormat;
            }

            LocalPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
            LocalPara.pJpegWrapperPara = &JpegWrapper;
            if(CalHdrUseSwEncoder)
                SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &LocalPara);
            else
                SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &LocalPara);

            CalHdrState = CAL_HDR_ENCODING_STATE;
        break;
    #endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

    #if defined(__AUTO_SCENE_DETECT_SUPPORT__ )
        case PP_CBID_ASD_RESULT:
            pAsdResult = (P_ASD_FINAL_RESULT_STRUCT)pCallbackPara;
            CalAsdSceneType = CalAsdSceneLut[pAsdResult->AsdScene];

            // do compensation when scene changed
            if(CalAsdSceneType != CalAsdBackupSceneType)
            {
                    CalSceneCompensationConfig(CAL_SCENARIO_CAMERA_PREVIEW, CalAsdSceneType, &IspSceneCompensationParaIn);
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_SCENE_COMPENSATION, &IspSceneCompensationParaIn, NULL, 0, &FeatureOutLen);
            }
            CalAsdBackupSceneType = CalAsdSceneType;

            // callback to MED
            pfCalCallback(CAL_CBID_ASD_RESULT, &CalAsdSceneType, sizeof(CAL_CAMERA_SCENE_MODE_ENUM));
        break;
    #endif //__AUTO_SCENE_DETECT_SUPPORT__

    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        case PP_CBID_MAVCAP_RESULT:
            pMavCapResult = (P_MAVCAP_RESULT_STRUCT)pCallbackPara;
            // save readyToShot & MV to global which will be reference in MdpCallback
            IsMavReadyToShot = pMavCapResult->ReadyToShot;
            CalMavMV[0] = pMavCapResult->MV_X;
            CalMavMV[1] = pMavCapResult->MV_Y;
            #if defined(__CAMERA_GYRO_SUPPORT__)
            if (CalCamGyroEnabled)
            {
                pfCalCallback(CAL_CBID_CAM_GYRO_RESULT, pCallbackPara, CallbackParaLen);
            }
            #endif
        break;
        case PP_CBID_MAV_RESULT:
            // 1. enter encode state
            // 2. copy first warped image to qvi buffer
            // 3. do mpo encode
            // 4. callback to MED with qvi buffer
            CalMavState = CAL_MAV_ENCODE_STATE;
            pMavResult = (P_MAV_RESULT_STRUCT)pCallbackPara;
            // call mpo_wrapper_open/start/close
            if ((pMavResult->ClipWidth>0)&&(pMavResult->ClipHeight>0))
            {
                if (KAL_TRUE == CalMav3DImageMode)
                {
                    #if (defined(__3D_IMAGE_SUPPORT__))
                    // jpeg encode
                    JPEG_STATUS_ENUM JpegStatus;
                    JpegStatus = jpeg_wrapper_open(&JpegWrapperHandle, JPEG_CODEC_TYPE_SW);
                    ASSERT(JpegStatus == JPEG_STATUS_OK);
                    JpegWrapper.srcWidth = pMavResult->ClipWidth;
                    JpegWrapper.srcHeight = pMavResult->ClipHeight;
                    JpegWrapper.dstWidth = pMavResult->ClipWidth;
                    JpegWrapper.dstHeight = pMavResult->ClipHeight;
                    JpegWrapper.srcWindow.x=0;
                    JpegWrapper.srcWindow.y=0;
                    JpegWrapper.srcWindow.w=0;
                    JpegWrapper.srcWindow.h=0;
                    JpegWrapper.srcYUVBuffer[0]=(void *)pMavResult->PpImgBufAddr;
                    JpegWrapper.srcBufferSize[0]=pMavResult->ClipWidth*pMavResult->ClipHeight;
                    JpegWrapper.srcYUVBuffer[1]=(void *)(pMavResult->PpImgBufAddr+pMavResult->ClipWidth*pMavResult->ClipHeight);
                    JpegWrapper.srcBufferSize[1]=(pMavResult->ClipWidth*pMavResult->ClipHeight)/4;
                    JpegWrapper.srcYUVBuffer[2]=(void *)(pMavResult->PpImgBufAddr+(pMavResult->ClipWidth*pMavResult->ClipHeight*5)/4);
                    JpegWrapper.srcBufferSize[2]=(pMavResult->ClipWidth*pMavResult->ClipHeight)/4;
                    #if defined(EXIF_SUPPORT)
                    {
                        exif_cam_para_struct* exif_cam_para_ptr = exif_get_cam_para_struct();
                        exif_MTK_para_struct* exif_mtk_para_ptr = exif_get_MTK_para_struct();
                        ExifUpdate3DCamParaStruct(exif_cam_para_ptr);
                        exif_mtk_para_ptr->mtk_para[0] = CalMavCaptureTimeoutFrameCount;
                        JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_EXIF;
                    }
                    #else
                    JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_JPEG;
                    #endif
                    JpegStatus = jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
                    ASSERT(JpegStatus == JPEG_STATUS_OK);
                    JpegStatus = jpeg_wrapper_get_encoded_data(JpegWrapperHandle,(kal_uint8**)&MavCbPara.EncodeDstBufferAddr,&MavCbPara.EncodeDstBufferSize);
                    ASSERT(JpegStatus == JPEG_STATUS_OK);
                    jpeg_wrapper_close(JpegWrapperHandle);
                    #endif /* __3D_IMAGE_SUPPORT__ */
                }
                else
                {
                    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
                    MAV_ENC_STATUS status;
                    status = mavEncWrapperOpen(&MavEncWrapperHandle);
                    if (MAV_ENC_STATUS_OK != status)
                    {
                        ASSERT(0);
                    }
                    MavEncWrapper.srcWidth = pMavResult->ClipWidth;
                    MavEncWrapper.srcHeight = pMavResult->ClipHeight;
                    #if defined(EXIF_SUPPORT)
                    {
                        exif_cam_para_struct* exif_cam_para_ptr = exif_get_cam_para_struct();
                        exif_MTK_para_struct* exif_mtk_para_ptr = exif_get_MTK_para_struct();
                        exif_cam_para_ptr->Orientation = MM_IMAGE_ROTATE_0;
                        exif_mtk_para_ptr->mtk_para[0] = CalMavCaptureTimeoutFrameCount;
                        MavEncWrapper.dstFileFormat=JPEG_FILE_FORMAT_EXIF;
                    }
                    #else
                    MavEncWrapper.dstFileFormat=JPEG_FILE_FORMAT_JPEG;
                    #endif
                    status = mavEncWrapperStart(MavEncWrapperHandle, &MavEncWrapper);
                    if (MAV_ENC_STATUS_OK != status)
                    {
                        ASSERT(0);
                    }
                    status = mavEncWrapperGetEncodedData(MavEncWrapperHandle, (kal_uint8 **) &MavCbPara.EncodeDstBufferAddr, &MavCbPara.EncodeDstBufferSize);
                    if (MAV_ENC_STATUS_OK != status)
                    {
                        ASSERT(0);
                    }
                    status = mavEncWrapperClose(MavEncWrapperHandle);
                    if (MAV_ENC_STATUS_OK != status)
                    {
                        ASSERT(0);
                    }
                    #endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
                }
                MavCbPara.ErrorStatus = MM_ERROR_NONE;
            }
            else
            {
                MavCbPara.ErrorStatus = MM_ERROR_INVALID_PARAMETER;
            }
            pfCalCallback(CAL_CBID_MAV_STITCH_IMAGE_READY, &MavCbPara, sizeof(CAL_MAV_RESULT_STRUCT));
            CalMavState = CAL_MAV_COMPLETE_STATE;
            break;
    #endif /*  __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
        default:
        break;
    }

    return ErrorCode;
#else
    return MM_ERROR_NONE;
#endif /* defined(__POSTPROC_SUPPORT__) */
} /* PpCallback() */

MM_ERROR_CODE_ENUM JaiaCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    CAL_PANO_RESULT_STRUCT CalPanoResult;
#endif

#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    CAL_HDR_RESULT_STRUCT CalHdrResult;
#endif

    switch (CbId)
    {
        case CAL_CBID_STILL_IMAGE_READY:
        #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
            if (CalPanoEnabled)
                CbId=CAL_CBID_PANO_IMAGE_READY;
        #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

        #ifdef __CAL_PROFILING_ENABLE__
            CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_JAIA_DONE);
        #endif
            pfCalCallback(CbId, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
        break;
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        case CAL_CBID_PANO_RESULT:
            CalPanoResult.ErrorStatus=MM_ERROR_NONE;
            CalPanoResult.ImageBuffAddr=pCbBuff->ImageBuffAddr;
            CalPanoResult.ImageBuffSize=pCbBuff->ImageBuffSize;
        #if defined(__PANORAMA_VIEW_SUPPORT__)
            CalPanoResult.ImgWidth=CalPanoPostProcPara.MainImageWidth;
            CalPanoResult.ImgHeight=CalPanoPostProcPara.MainImageHeight;
        #else

            CalPanoResult.ImgWidth=JpegWrapper.srcWindow.w;
            CalPanoResult.ImgHeight=JpegWrapper.srcWindow.h;
            //Reset JpegWrapper.srcWindow to avoid wrong info afterward
            JpegWrapper.srcWindow.x=0;
            JpegWrapper.srcWindow.y=0;
            JpegWrapper.srcWindow.w=0;
            JpegWrapper.srcWindow.h=0;
        #endif
            pfCalCallback(CbId, &CalPanoResult, sizeof(CAL_PANO_RESULT_STRUCT));
        break;
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        case CAL_CBID_HDR_RESULT:
            CalHdrResult.ErrorStatus = pCbBuff->ErrorStatus;
            CalHdrResult.ImageBuffFormat= pCbBuff->ImageBuffFormat;
            CalHdrResult.ImageBuffAddr = pCbBuff->ImageBuffAddr;
            CalHdrResult.ImageBuffSize = pCbBuff->ImageBuffSize;
            pfCalCallback(CbId, &CalHdrResult, sizeof(CAL_HDR_RESULT_STRUCT));
        break;
    #endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* JaiaCallback() */

#ifdef __CAL_IMAGE_ROTATE_SUPPORT__
MM_ERROR_CODE_ENUM ImageRotCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

    switch (CbId)
    {
        case CAL_CBID_QUICK_VIEW_IMAGE_READY:
            if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE)
            {
                CalStillCaptureInfo.QuickViewImageBuffAddr = QuickViewImageDestBuffAddr;

                if (CalStillCaptureInfo.QuickViewImageRotAngle & 0x01)
                {
                    kal_uint16 tmp;
                    tmp = CalStillCaptureInfo.QuickViewImageWidth;
                    CalStillCaptureInfo.QuickViewImageWidth = CalStillCaptureInfo.QuickViewImageHeight;
                    CalStillCaptureInfo.QuickViewImageHeight = tmp;

                    tmp = CalStillCaptureInfo.MainImageWidth;
                    CalStillCaptureInfo.MainImageWidth = CalStillCaptureInfo.MainImageHeight;
                    CalStillCaptureInfo.MainImageHeight = tmp;
                }

                MainImageResizePara.pCalStillCapPara=&CalStillCaptureInfo;
                MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_QUICK_VIEW_IMAGE_READY;
                MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_THUMBNAIL_IMAGE_READY;

                if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
                {
                    MainImageResizePara.MainImageBuffAddr=ImageRotatePara.DestImageYBuffAddr;
                    MainImageResizePara.MainImageBuffAddrU=ImageRotatePara.DestImageUBuffAddr;
                    MainImageResizePara.MainImageBuffAddrV=ImageRotatePara.DestImageVBuffAddr;
                }
                else
                {
                    MainImageResizePara.MainImageBuffAddr=ImageRotatePara.SrcImageYBuffAddr;
                    MainImageResizePara.MainImageBuffAddrU=ImageRotatePara.SrcImageUBuffAddr;
                    MainImageResizePara.MainImageBuffAddrV=ImageRotatePara.SrcImageVBuffAddr;
                }

                MainImageResizePara.pCalStillCapPara=&CalStillCaptureInfo;
                MainImageResizePara.IsSrcClip=KAL_FALSE;

                SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);
            }
            else
            {
                pfCalCallback(CbId, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        break;
    #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
        case CAL_CBID_VIDEO_IMAGE_READY:
        #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
            if (SwVideoRotAngle==CalVideoInfo.VideoImageRotAngle)
                MplBuffInfo.eStatus = MPL_OK;
            else
                MplBuffInfo.eStatus = MPL_INVALID_FRAME;
        #else
            MplBuffInfo.eStatus = MPL_OK;
        #endif
            MplBuffInfo.pu1Address = (kal_uint8*)pCbBuff->ImageBuffAddr;
            CalVideoInfo.pfRetVideoBuff(MplBuffInfo);
        break;
    #endif
    #ifdef __CAL_NEED_SW_ROTATE__
        case CAL_CBID_DISPLAY_IMAGE_ROTATE_READY:
            CameraImageDisplay(pCbBuff);
        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            if (NULL != CalPreviewInfo.FrameBuffAddr3)
            {
                if (DisplayImageSwRotatorIdx & 0x1)
                    CalPreviewInfo.FrameBuffAddr2 = pCbBuff->NextFrameBufferAddr;
                else
                    CalPreviewInfo.FrameBuffAddr1 = pCbBuff->NextFrameBufferAddr;
            }
        #endif
        break;
    #endif
        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* ImageRotCallback() */
#endif

#ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
MM_ERROR_CODE_ENUM PreviewImageCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    switch (CbId)
    {
        case CAL_CBID_PREVIEW_IMAGE_READY:
            if (CalEventId!=NULL)
                kal_set_eg_events(CalEventId,CAL_GET_PREVIEW_IMAGE_EVENT,KAL_OR);
        break;
        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* ImageRotCallback() */
#endif

#ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
MM_ERROR_CODE_ENUM Y2RDitheringCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

    CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT;
    pCbBuff->ErrorStatus=MM_ERROR_NONE;

    pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));

    #if defined(EXIF_SUPPORT)
    SendJaiaMergeMsg();
    #endif
}   /* Y2RDitheringCallback()*/
#endif

void QuickViewImageRotate(kal_uint16 SrcWidth, kal_uint16 SrcHeight, kal_uint32 SrcBuffAddr,
                          kal_uint32 DestBuffAddr, MM_IMAGE_ROTATE_ENUM RotAngle)
{
    ROTATOR_STATUS_ENUM RotatorStatus;
    YUV_ROTATOR_HANDLE_STRUCT *pYuvRotHandle;
    kal_uint32 IntMemBest, IntMemMin, ExtMemBest, ExtMemMin;
    kal_uint16 DestImageWidth, DestImageHeight;

    if (RotAngle & 0x01)
    {
        DestImageHeight = SrcWidth;
        DestImageWidth = SrcHeight;
    }
    else
    {
        DestImageWidth = SrcWidth;
        DestImageHeight = SrcHeight;
    }
    RotatorStatus=yuvRotatorGetHandle(&pYuvRotHandle, ROTATOR_MODE_AUTO);
    ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

    yuvRotatorSetCallbackFunction(pYuvRotHandle, NULL);     // use polling mode instead of interrupt mode

    yuvRotatorSetSrcBufferInfo(pYuvRotHandle, ROTATOR_COLOR_FORMAT_ENUM_UYVY422,
                               (void *) SrcBuffAddr,
                               (void *) 0, (void *) 0,
                               SrcWidth*SrcHeight*2,
                               0, 0,
                               SrcWidth, SrcHeight);

    yuvRotatorSetDstBufferInfo(pYuvRotHandle, ROTATOR_COLOR_FORMAT_ENUM_UYVY422,
                               (void *) DestBuffAddr,
                               (void *) 0, (void *) 0,
                               SrcWidth*SrcHeight*2,
                               0, 0,
                               DestImageWidth, DestImageHeight);

    yuvRotatorSetSrcWindow(pYuvRotHandle, 0, 0, SrcWidth, SrcHeight);

    yuvRotatorSetDstWindow(pYuvRotHandle, 0, 0, DestImageWidth, DestImageHeight);

    yuvRotatorSetRotation(pYuvRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) RotAngle);

    yuvRotatorCheckAbortFunction(pYuvRotHandle, NULL);

    yuvRotatorQueryWorkingMemory(pYuvRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

    ASSERT(0==IntMemMin);
    ASSERT(0==ExtMemMin);

    yuvRotatorSetWorkingMemory(pYuvRotHandle, NULL, 0, (kal_uint32 *) 0, 0);

    yuvRotatorStart(&pYuvRotHandle);

    while ((yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_OK)&&
           (yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_COMPLETE));

    yuvRotatorReleaseHandle(pYuvRotHandle);
} /* QuickViewImageRotate() */


#if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

MM_ERROR_CODE_ENUM ImageResizeCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

    kal_uint32 CtrlOutLen;
#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    kal_uint32 ImageResolution;
    kal_uint32 DstOffset, SrcOffset, BlackOffset;
    kal_uint16 i;
#endif
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    CAL_BUFFER_CB_STRUCT_AUTORAMA CbBuffAutoRama;
#endif
#if !(defined(MT6235) || defined(MT6235B) || defined(MT6253)||defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260))
    CAL_SW_JPEG_ENCODE_REQ_STRUCT JpegEncPara;
#endif

    switch (CbId)
    {
        case CAL_CBID_QUICK_VIEW_IMAGE_READY:
             // rotate quick view image
            if ((MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle) && (CalStillCaptureInfo.ImageJaiaDisable == KAL_FALSE))
            {
                QuickViewImageRotate(CalStillCaptureInfo.QuickViewImageWidth, CalStillCaptureInfo.QuickViewImageHeight,
                                     pCbBuff->ImageBuffAddr, QuickViewImageDestBuffAddr, CalStillCaptureInfo.QuickViewImageRotAngle);
            }

            CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT;
            pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
            if ((CurrentStillCaptureStatus & (CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT|CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT)) ==
                (CurrentStillCaptureMask&(CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT|CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT)))
            {
                if (
                #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    (!CalPanoEnabled) &&
                #endif
                    (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId))
                {
                    pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
                    pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_STILL_CAPTURE, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

                #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
                    if (KAL_TRUE == IsZsdScenario)
                        MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_ZSD_CAPTURE, IdpCalKey);
                    else
                #endif
                    MdpFunc.pfnIdpCalClose(CurrentStillScenarioId, IdpCalKey);

                  #if !(defined(MT6235) || defined(MT6235B) || defined(MT6253)||defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260))
                    JpegEncPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
                    JpegEncPara.pJpegWrapperPara=&JpegWrapper;
                    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                        SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #else
                        JpegWrapper.callback_function=NULL;
                        SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #endif
                  #endif
                  #if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                  #endif
                }
            }
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            if(CalPanoEnabled)
                pfCalCallback(CAL_CBID_PANO_IMAGE_READY, &PanoCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
        #endif
        break;
        case CAL_CBID_THUMBNAIL_IMAGE_READY:
            CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT;
            if ((CurrentStillCaptureStatus & (CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT|CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT)) ==
                (CurrentStillCaptureMask&(CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT|CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT)))
            {
                if (
                #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    (!CalPanoEnabled) &&
                #endif
                    (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId))
                {
                    pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
                    pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_STILL_CAPTURE, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

                #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
                    if (KAL_TRUE == IsZsdScenario)
                        MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_ZSD_CAPTURE, IdpCalKey);
                    else
                #endif
                    MdpFunc.pfnIdpCalClose(CurrentStillScenarioId, IdpCalKey);

                  #if !(defined(MT6235) || defined(MT6235B) || defined(MT6253)||defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260))
                    JpegEncPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
                    JpegEncPara.pJpegWrapperPara=&JpegWrapper;
                    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                        SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #else
                        JpegWrapper.callback_function=NULL;
                        SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &JpegEncPara);
                    #endif
                  #endif
                  #if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                  #endif
                }
            }

          #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
            if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==CurrentStillScenarioId)
            {
              #if defined(EXIF_SUPPORT)
                SendJaiaMergeMsg();
              #endif
            }
          #endif /*__ZERO_SHUTTER_DELAY_SUPPORT__*/
        break;
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        case CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY:

            if((MM_IMAGE_FORMAT_RGB565==pCbBuff->ImageBuffFormat)||(MM_IMAGE_FORMAT_PACKET_UYVY422==pCbBuff->ImageBuffFormat))
            {
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                if(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageResizeByBuffSizeEnable)
                {
                    CbBuffAutoRama.PanoStartX=0;
                    CbBuffAutoRama.PanoStartY=0;
                }
                else
            #endif
                {
                //Memory copy for Panorama quick view image
                if(CalPanoPostProcPara.ImageAlignmentHandle)
                {
                    BlackOffset=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth-CalPanoPostProcPara.QuickViewPanoImageWidth)/2;
                #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    CbBuffAutoRama.PanoStartX=BlackOffset;
                    CbBuffAutoRama.PanoStartY=0;
                #endif
                    for(i=0; i<CalPanoPostProcPara.QuickViewPanoImageHeight; i++)
                    {
                        DstOffset = (BlackOffset+CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*i)*2;
                        SrcOffset = CalPanoPostProcPara.QuickViewPanoImageWidth*i*2;
                        kal_mem_cpy((kal_uint8 *)(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+DstOffset),
                                    (kal_uint8 *)(pCbBuff->ImageBuffAddr+SrcOffset),
                                    CalPanoPostProcPara.QuickViewPanoImageWidth*2);

                        if(CalPanoPostProcPara.QuickViewPanoImageHeight-1==i)    //Last line
                        {
                            kal_mem_set((kal_uint8 *)(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+DstOffset+CalPanoPostProcPara.QuickViewPanoImageWidth*2), 0,
                                        (CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth-CalPanoPostProcPara.QuickViewPanoImageWidth-BlackOffset)*2);
                        }
                        else
                            kal_mem_set((kal_uint8 *)(pCbBuff->ImageBuffAddr+SrcOffset), 0, CalPanoPostProcPara.QuickViewPanoImageWidth*2);
                    }
                }
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                else
                {
                    CbBuffAutoRama.PanoStartX=0;
                    CbBuffAutoRama.PanoStartY=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight-CalPanoPostProcPara.QuickViewPanoImageHeight)/2;
                }
            #endif
                #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    if(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageResizeByBuffSizeEnable)
                        ImageResolution = CalPanoPostProcPara.QuickViewPanoImageWidth * CalPanoPostProcPara.QuickViewPanoImageHeight * 2;
                    else
                #endif
                ImageResolution = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth * CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight * 2;

                pCbBuff->ImageBuffAddr = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr;
                pCbBuff->ImageBuffSize = ImageResolution;
                }
            }
            else
                ASSERT(0);  //Shouldn't reach here. QuickView only support RGB565
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            CbBuffAutoRama.pCalBufferCB=pCbBuff;
            CbBuffAutoRama.PanoWidth=CalPanoPostProcPara.QuickViewPanoImageWidth;
            CbBuffAutoRama.PanoHeight=CalPanoPostProcPara.QuickViewPanoImageHeight;
        #endif
            if(IsPanoPaused)
                return MM_ERROR_NONE;
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            pfCalCallback(CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY, &CbBuffAutoRama, sizeof(CAL_BUFFER_CB_STRUCT_AUTORAMA));
        #else
            pfCalCallback(CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
        #endif
        break;
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
        case CAL_CBID_PANO_QVI_FOR_JAIA_READY:
            JaiaMergePara.MainImageStartAddr=(kal_uint32)pJpegEncodedDataAddr;
            JaiaMergePara.MainImageSize=JpegEncodedDataSize;
            JaiaMergePara.JaiaCbId=CAL_CBID_PANO_RESULT;
            JaiaMergePara.pCalStillCapPara=&CalStillCaptureInfo;
            SendMsgToCal(MSG_ID_CAL_JAIA_MERGE_REQ, &JaiaMergePara);
        break;
        #endif /* defined(__AUTOCAP_PANORAMA_SUPPORT__) */
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        case CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY:
            if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
            {
                QuickViewImageRotate(CalStillCaptureInfo.QuickViewImageWidth, CalStillCaptureInfo.QuickViewImageHeight,
                                     pCbBuff->ImageBuffAddr, QuickViewImageDestBuffAddr, CalStillCaptureInfo.QuickViewImageRotAngle);
            }
            CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT;

            // abort handling
            if (IsHdrAborted )
                return MM_ERROR_NONE;

            pfCalCallback(CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
        break;
    #endif //__HIGH_DYNAMIC_RANGE_SUPPORT__

        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* ImageResizeCallback() */

MM_ERROR_CODE_ENUM StackTimeOutCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

    switch (CbId)
    {
        case CAL_CBID_STILL_IMAGE_TIMEOUT:
            pfCalCallback(CAL_CBID_STILL_IMAGE_READY, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
        break;
        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* StackTimeOutCallback() */

kal_int32 JpegEncCallback(JPEG_CODEC_STATE_ENUM State)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    CAL_BUFFER_CB_STRUCT JpegCbPara;
    #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    JPEG_STATUS_ENUM JpegStatus;
    #endif

#if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    CAL_CALLBACK_ID_ENUM CalCbId = CAL_CBID_BEGIN;
    CAL_POSTPROC_CB_UNION CalPostprocCbPara;
    kal_bool JaiaQuickViewImageMerge = KAL_FALSE;
    kal_bool JaiaThumbnailImageMerge = KAL_FALSE;
#endif
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT MainImageResizePara;
#endif

    if (CAL_CAMERA_CAPTURE_STATE==CalState)
    {
    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_JPEG_DONE);
    #endif
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if (KAL_TRUE==IsHwJpegEncSupport)
        {
            stack_stop_timer(&CalTaskStackTimer);
            jpeg_wrapper_get_encoded_data(JpegWrapperHandle, &pJpegEncodedDataAddr, &JpegEncodedDataSize);
        }
    #endif
        #ifdef LED_FLASHLIGHT_SUPPORT
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_STOP_FLASHLIGHT_PROCESS_AFTER_CAPTURE_DONE, NULL, NULL, 0, 0);
        #endif

        // The callback function will be put after JAIA integration done.
        if (CAL_STILL_CAPTURE_MAIN_IMAGE_BIT==CurrentStillCaptureMask)
        {   // JPEG file only, without thumbnail and quick view image.
        #ifdef __CAL_PROFILING_ENABLE__
            CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_JPEG_DONE);
        #endif
            if (JPEG_CODEC_STATE_COMPLETE==State)
                JpegCbPara.ErrorStatus=MM_ERROR_NONE;
            else
                JpegCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CATPURE_OUT_OF_MEMORY;
            JpegCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_JPEG;
            JpegCbPara.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
            JpegCbPara.ImageBuffSize= JpegEncodedDataSize;
        #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if (CalPanoEnabled&&(KAL_TRUE==IsHwJpegEncSupport))
                pfCalCallback(CAL_CBID_PANO_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
            else
        #endif
        #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
                pfCalCallback(CAL_CBID_STILL_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
        }
        else
        {
            if (JPEG_CODEC_STATE_COMPLETE==State)
            {
                CurrentStillCaptureStatus |= CAL_STILL_CAPTURE_MAIN_IMAGE_BIT;
                #if defined(EXIF_SUPPORT)
                if (CalStillCaptureInfo.ImageJaiaDisable == KAL_FALSE)
                {
                    SendJaiaMergeMsg();
                }
                else
                #endif
                {
                    JpegCbPara.ErrorStatus=MM_ERROR_NONE;
                    JpegCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_JPEG;
                    JpegCbPara.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
                    JpegCbPara.ImageBuffSize= JpegEncodedDataSize;
                    pfCalCallback(CAL_CBID_STILL_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
                }
            }
        }
        return KAL_TRUE;
    }
#if (defined(__POSTPROC_SUPPORT__))
    else if(CAL_POSTPROC_STATE==CalState)
    {
    #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        // 1. Get JPEG result (HW or SW)
        JpegStatus=jpeg_wrapper_get_encoded_data(JpegWrapperHandle, &pJpegEncodedDataAddr, &JpegEncodedDataSize);
        ASSERT(JpegStatus == JPEG_STATUS_OK);

        // 2. Fill callback para by each feature
        /* for PANORAMA */
        #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if(CAL_PANO_ENCODING_STATE==CalPanoState)
        {
            CalPanoState = CAL_PANO_ENCODED_STATE;

            CalPostprocCbPara.PanoResult.ErrorStatus=MM_ERROR_NONE;
            CalPostprocCbPara.PanoResult.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
            CalPostprocCbPara.PanoResult.ImageBuffSize=JpegEncodedDataSize;
            CalPostprocCbPara.PanoResult.ImgWidth=CalPanoPostProcPara.MainImageWidth;
            CalPostprocCbPara.PanoResult.ImgHeight=CalPanoPostProcPara.MainImageHeight;
            CalCbId = CAL_CBID_PANO_RESULT;

            JaiaQuickViewImageMerge = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageEnable;
            JaiaThumbnailImageMerge = KAL_FALSE;

            if(IsPanoPaused)
                return ErrorCode;

        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)

            //Check if need to do image resize for QVI
            MainImageResizePara.pCalStillCapPara = &CalStillCaptureInfo;
            MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_PANO_QVI_FOR_JAIA_READY;
            MainImageResizePara.pCalStillCapPara->MainImageWidth = JpegWrapper.srcWidth;
            MainImageResizePara.pCalStillCapPara->MainImageHeight = JpegWrapper.srcHeight;

            if(JPEG_ENCODE_SOURCE_YUV_BUFFER==JpegWrapper.srcMode)
            {
                MainImageResizePara.MainImageBuffAddr = (kal_uint32)JpegWrapper.srcYUVBuffer[0];
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV420;
            }
            else if (JPEG_ENCODE_SOURCE_RGB_BUFFER==JpegWrapper.srcMode)
            {
                MainImageResizePara.MainImageBuffAddr = (kal_uint32)JpegWrapper.srcRGBBuffer;
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;
            }
            else
                ASSERT(0);

            MainImageResizePara.pCalStillCapPara->QuickViewImageEnable = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageEnable;
            MainImageResizePara.pCalStillCapPara->QuickViewImageFormat = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageFormat;
            MainImageResizePara.pCalStillCapPara->QuickViewImageRotAngle = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageRotAngle;
            MainImageResizePara.pCalStillCapPara->QuickViewImageWidth = CalPanoPostProcPara.QuickViewPanoImageWidth;
            MainImageResizePara.pCalStillCapPara->QuickViewImageHeight = CalPanoPostProcPara.QuickViewPanoImageHeight;
            MainImageResizePara.pCalStillCapPara->QuickViewImageBuffSize = CalPanoPostProcPara.QuickViewPanoImageWidth*CalPanoPostProcPara.QuickViewPanoImageHeight*2;
            MainImageResizePara.pCalStillCapPara->QuickViewImageBuffAddr = (kal_uint32)JpegWrapper.dstBufferAddr+JpegWrapper.dstBufferSize
                                                                           -MainImageResizePara.pCalStillCapPara->QuickViewImageBuffSize;
            MainImageResizePara.pCalStillCapPara->ThumbnailImageEnable = KAL_FALSE;     //Panorama stitch image don't support Thumbnail

            //Config source image ROI
            MainImageResizePara.IsSrcClip=KAL_TRUE;
            MainImageResizePara.pSrcWindow = (iul_rect *)(&JpegWrapper.srcWindow);

            SendMsgToCal(MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ, &MainImageResizePara);

            return ErrorCode;
        }
        #endif /* defined(__AUTOCAP_PANORAMA_SUPPORT__) */
        #if defined(__PANORAMA_VIEW_SUPPORT__)

            if(CalPanoPostProcPara.ImageAlignmentHandle)
            {
                kal_uint32 DstOffset, SrcOffset, BlackOffset;
                kal_uint16 i;

                //Use the memory which is released from JPEG encoding as temp buffer for JAIA QVI
                CalStillCaptureInfo.QuickViewImageBuffAddr=JaiaMergePara.WorkingBuffAddr+JaiaMergePara.WorkingBuffSize;

                BlackOffset=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth-CalPanoPostProcPara.QuickViewPanoImageWidth)/2;
                for(i=0; i<CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight; i++)
                {
                    DstOffset = CalPanoPostProcPara.QuickViewPanoImageWidth*i*2;
                    SrcOffset = (BlackOffset+CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*i)*2;
                    kal_mem_cpy((kal_uint8 *)(CalStillCaptureInfo.QuickViewImageBuffAddr+DstOffset),
                                (kal_uint8 *)(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr+SrcOffset),
                                CalPanoPostProcPara.QuickViewPanoImageWidth*2);
                }
            }

        }
        #endif /* defined(__PANORAMA_VIEW_SUPPORT__) */
        #endif /* (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__)) */

        /* for HDR */
        #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        if(CAL_HDR_ENCODING_STATE==CalHdrState)
        {
            // abort handling
            CalHdrState = CAL_HDR_ENCODED_STATE;
            if (IsHdrAborted && (CalEventId!=NULL))
            {
                kal_set_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT,KAL_OR);
                return ErrorCode;
            }

            CalPostprocCbPara.HdrResult.ErrorStatus=MM_ERROR_NONE;
            CalPostprocCbPara.HdrResult.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
            CalPostprocCbPara.HdrResult.ImageBuffSize= JpegEncodedDataSize;
            CalPostprocCbPara.HdrResult.ImageBuffFormat=MM_IMAGE_FORMAT_JPEG;
            CalCbId = CAL_CBID_HDR_RESULT;

            JaiaQuickViewImageMerge = CalMdpPostProcPara.QuickViewImageEnable;
            JaiaThumbnailImageMerge = CalMdpPostProcPara.ThumbnailImageEnable;
        }
        #endif

        // 3. Do JAIA merge or callback to MED
        if(JaiaQuickViewImageMerge || JaiaThumbnailImageMerge )
        {   //send a meesage to CAL task to start JAIA merge
            JaiaMergePara.MainImageStartAddr=(kal_uint32)pJpegEncodedDataAddr;
            JaiaMergePara.MainImageSize=JpegEncodedDataSize;
            JaiaMergePara.JaiaCbId=CalCbId;
            JaiaMergePara.pCalStillCapPara=&CalStillCaptureInfo;
            SendMsgToCal(MSG_ID_CAL_JAIA_MERGE_REQ, &JaiaMergePara);
        }
        else
        {
            pfCalCallback(CalCbId, &CalPostprocCbPara, sizeof(CAL_POSTPROC_CB_UNION));
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __HIGH_DYNAMIC_RANGE_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

        return ErrorCode;
    }
#endif
    else // CalState not in CAL_POSTPROC_STATE)
    {
        return ErrorCode;
    }
} /* JpegEncCallback() */


MM_ERROR_CODE_ENUM JpegCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_JPEG_ENCODE_CB_STRUCT pSwJpegCbStruct = (P_CAL_JPEG_ENCODE_CB_STRUCT)pCallbackPara;
    CalTrace(CAL_TRACE_CBF,CAL_CBF_JPEG,CbId,drv_get_current_time());
    pJpegEncodedDataAddr = pSwJpegCbStruct->pJpegDataAddr;       ///update encode result to global variable
    JpegEncodedDataSize = pSwJpegCbStruct->JpegDataSize;

    if (CAL_CBID_MAIN_IMAGE_READY==CbId)
    {
        ASSERT(pSwJpegCbStruct->JpegStatus == JPEG_STATUS_OK);
        JpegEncCallback(JPEG_CODEC_STATE_COMPLETE);
    }
    return MM_ERROR_NONE;
}

#ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
kal_int32 MjpegEncCallback(JPEG_CODEC_STATE_ENUM State)
{
    if (CAL_VIDEO_MJPEG_STASTE==CalState)
    {
        jpeg_wrapper_get_encoded_data(JpegWrapperHandle, &pJpegEncodedDataAddr, &JpegEncodedDataSize);

        // 1. callback to MPL for passing the image information
        MplBuffInfo.pu1Address = (kal_uint8*)pJpegEncodedDataAddr;
        MplBuffInfo.u4Size=JpegEncodedDataSize;
        if (JPEG_CODEC_STATE_COMPLETE==State)
            MplBuffInfo.eStatus=MPL_OK;
        else
            MplBuffInfo.eStatus=MPL_BISTREAM_SHORTAGE;
        CalVideoInfo.pfRetVideoBuff(MplBuffInfo);

        // 2. get another JPEG bit stream buffer
        MplBuffInfo = CalVideoInfo.pfGetVideoBuff();
        JpegWrapper.dstBufferAddr=(void *)MplBuffInfo.pu1Address;
        // 3. Reset JPEG encoder then restart JPEG encoder

        jpegEncReset(JpegWrapperHandle);
        jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);

        return MM_ERROR_NONE;
    }
    else
        return KAL_FALSE;
}   /* MjpegEncCallback() */
#endif

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
MM_ERROR_CODE_ENUM ImageEffectCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    P_CAL_BUFFER_CB_STRUCT pCbBuff=(P_CAL_BUFFER_CB_STRUCT) pCallbackPara;

    switch (CbId)
    {
        case CAL_CBID_PREVIEW_IMAGE_EFFECT_READY:
            kal_mem_cpy(&DisplayCbPara, pCbBuff, sizeof(CAL_BUFFER_CB_STRUCT));
            visual_active_hisr(VISUAL_CAL_HISR_ID);
        break;
        case CAL_CBID_CAPTURE_IMAGE_EFFECT_READY:
            pMdpCropBufferCb(0);
        break;
        default:
        break;
    }
    return MM_ERROR_NONE;
}   /* ImageEffectCallback() */
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
void CalHISR(void)
{
    if (NULL == CalDisplayFBs[2][0] &&
        WFC_TRUE == wfcMMCheckBusy())
    {
        IsImageEffectBusy = KAL_FALSE;
        return;
    }
    if (NULL == CalDisplayFBs[2][0])
    {
        DisplayImageEffectIdx ++;
    }
    else
    {
        if (DisplayImageEffectIdx<2)
        {
            DisplayImageEffectIdx ++;
        }
    }
    IsImageEffectBusy = KAL_FALSE;
    DisplayCbPara.EnableReleaseWriteBuffer = KAL_TRUE;
    DisplayCbPara.EnableAcquireWriteBuffer = KAL_FALSE;
    CameraImageDisplay(&DisplayCbPara);
}
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
void DisplayBufferAcquireCallback(void)
{
    CAL_BUFFER_CB_STRUCT DisplayPara;
    DisplayPara.EnableReleaseWriteBuffer = KAL_FALSE;
    DisplayPara.EnableAcquireWriteBuffer = KAL_TRUE;
    CameraImageDisplay(&DisplayPara);
    DisplayImageEffectBufferAddr = DisplayPara.NextFrameBufferAddr;
    ASSERT(DisplayImageEffectBufferAddr!=0);
}
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif



