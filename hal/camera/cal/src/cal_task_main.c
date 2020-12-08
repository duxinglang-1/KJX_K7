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
 *   cal_task_main.c
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_timer.h"        /* Stack timer */
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "kal_public_api.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */

#include "camera_nvram_def.h"
#include "nvram_struct.h"
#include "nvram_interface.h"

#include "fsal.h"

#include "jaia_enum.h"
#include "jaia_mem.h"
#include "jaia_structure.h"
#include "jaia_api.h"

// CAL API include
#include "cal_api.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"

#include "isp_if.h"

// Image resizer
#include "iul_csc_y2y.h"
#include "iul_csc_y2r.h"
#include "rgb_resizer_api.h"

// rotator
#include "rotator_enum.h"
#include "yuv_rotator_api.h"
#include "rgb_rotator_api.h"

#include "pp_api.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

//#include "wfc.h" // The include path is "mcu\interface\hal\display\api"
#include "wfc\inc\wfc_mm_api.h"     // The include path is "mcu\hal\display\wfc\inc"
#include "wfcplatform.h"

#include "cal_mem_def.h"
#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_decode_api.h"
#include "common\owfnativestream.h" // The include path is "mcu\interface\hal\display\api"

// sw image effect (lomo effect + color accent)
#include "image_effect.h"
// dynamic cacheable switch
#include "cache_sw.h"
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
#include "mmu.h"
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

stack_timer_struct CalTaskStackTimer;
kal_bool WaitStartupCnfFlag=KAL_FALSE;

extern WFCDevice CalDisplayDevice ;
extern WFCContext CalDisplayContext ;
extern WFCElement CalDisplayElement ;
extern OWFNativeStreamType CalDisplayStream;

#if defined(__JPEG_SENSOR_SUPPORT__)
ilm_struct  TmpIlmInfo;
JPEG_SENSOR_SRC_BUFFER_STRUCT JpegSensorParaIn;
JPEG_SENSOR_PARSE_DATA_STRUCT JpegSensorParaOut;
CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT JpegSensorInfo;
extern kal_uint8 CalJpegCaptureRetry;
#endif

#if defined(MT6235) || defined(MT6235B)
#if defined(__VIDEO_ARCHI_V2__)
extern void idp_sw_resizer_start_req_hdlr(ilm_struct *ilm_msg);
#endif
#endif

#if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
extern void idp_sw_yuv_2_rgb_dithering_start_req_hdlr(ilm_struct *ilm_msg);
#endif

#if (!defined(DRV_IDP_6252_SERIES))
// for video renderer sw request.
extern void video_renderer_task_req_hdlr(ilm_struct *ilm_msg);
#endif

#if defined(EXIF_SUPPORT)
extern CAL_JAIA_MERGE_REQ_MSG_STRUCT JaiaMergePara;
#endif

extern JPEG_ENCODER_HANDLE JpegWrapperHandle;
extern JPEG_WRAPPER JpegWrapper;
extern kal_uint8 *pJpegEncodedDataAddr;
extern kal_uint32 JpegEncodedDataSize;

#ifdef ISP_SUPPORT
    extern nvram_ltable_entry_struct logical_data_item_table_camera[];
#endif  /* ISP_SUPPORT */

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
kal_bool IsImageEffectBusy = KAL_FALSE;
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

#if defined(__JPEG_SENSOR_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
extern JPEG_STATUS_ENUM jpegDecSetRotation(JPEG_DECODER_HANDLE handle,JPEG_DECODE_ROTATE_ANGLE_ENUM angle);
#endif

void CalSendIlm(module_type SrcModId, module_type DestModId, kal_uint16 MsgId,
                void *pLocalPara, void *pPeerBuff, kal_bool FixSrcModId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *pIlm = NULL;
    //module_type SrcModId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SrcModId = stack_int_get_active_module_id();
    //SrcModId = MOD_CAL;

    if (KAL_TRUE==FixSrcModId)
    {
        pIlm = allocate_ilm(SrcModId);
        pIlm->src_mod_id = SrcModId;
    }
    else
    {
        pIlm = allocate_ilm(stack_get_active_module_id());
        pIlm->src_mod_id = stack_get_active_module_id();
    }

    switch (DestModId)
    {
        case MOD_NVRAM:
            pIlm->sap_id = PS_NVRAM_SAP;
        break;
        case MOD_CAL:
        default:
            pIlm->sap_id = CAL_SAP;
        break;
    }

    pIlm->msg_id = (msg_type) MsgId;
    pIlm->local_para_ptr = (local_para_struct*) pLocalPara;
    pIlm->peer_buff_ptr = (peer_buff_struct*) pPeerBuff;

    pIlm->dest_mod_id = DestModId;

    msg_send_ext_queue(pIlm);
} /* CalSendIlm() */

JAIA_IMAGE_COLOR_FORMAT_ENUM GetJaiaFormat(MM_IMAGE_FORMAT_ENUM ImageFormat)
{
    JAIA_IMAGE_COLOR_FORMAT_ENUM JaiaDataFormat=JAIA_IMAGE_TYPE_RGB565;

    switch (ImageFormat)
    {
        case MM_IMAGE_FORMAT_RGB565:
            JaiaDataFormat=JAIA_IMAGE_TYPE_RGB565;
        break;
    #if 0 // never used for thumbnail and quickview.
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        case MM_IMAGE_FORMAT_YUV420:
            JaiaDataFormat=JAIA_IMAGE_TYPE_YUV420;
        break;
        case MM_IMAGE_FORMAT_PACKET_UYVY422:
            JaiaDataFormat=JAIA_IMAGE_TYPE_PACKED_UYVY422;
        break;
        default:
            ASSERT(0);
        break;
    }
    return JaiaDataFormat;
}   /* GetJaiaFormat() */

#if defined(EXIF_SUPPORT)
void JaiaMergeHandle(ilm_struct *pIlmPtr)
{
    P_CAL_JAIA_MERGE_REQ_MSG_STRUCT pStillCaptureImageInfo;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pStillCaptureInfo;
    kal_uint32 JaiaWorkingBuffSize;
    JAIA_HANDLE pJaiaWorkspacePara;
    JAIA_RETURN_STATUS_ENUM JaiaErrorCode;
    STFSAL SrcFileHandle;
    kal_uint32 IntWorkingMemSize, ExtWorkingMemSize;
    CAL_BUFFER_CB_STRUCT JaiaImagePara;
    kal_uint32 WorkingBuffAddr, WorkingBuffSize;

    JAIA_BUFFER JaiaWorkBuff, JaiaIntMem, JaiaExtMem, JaiaDestBuffer;
    JAIA_IMAGE_INFO JaiaImageInfo;

    pStillCaptureImageInfo = (P_CAL_JAIA_MERGE_REQ_MSG_STRUCT) pIlmPtr->local_para_ptr;

    pStillCaptureInfo=pStillCaptureImageInfo->pCalStillCapPara;
    WorkingBuffAddr=pStillCaptureImageInfo->WorkingBuffAddr;
    WorkingBuffSize=pStillCaptureImageInfo->WorkingBuffSize;

    JaiaErrorCode=jaiaQueryWorkspaceBuffer(&JaiaWorkingBuffSize);

    ASSERT(WorkingBuffSize>JaiaWorkingBuffSize);

    JaiaWorkBuff.buff_addr=(void *) WorkingBuffAddr;
    JaiaWorkBuff.buff_size=JaiaWorkingBuffSize;
    WorkingBuffAddr += JaiaWorkingBuffSize;
    WorkingBuffSize -= JaiaWorkingBuffSize;

    JaiaErrorCode=jaiaCreateWorkspace(&pJaiaWorkspacePara, &JaiaWorkBuff);

    ASSERT(JAIA_RETURN_OK==JaiaErrorCode);

    FSAL_Direct_SetRamFileSize(&SrcFileHandle, pStillCaptureImageInfo->MainImageSize);
    FSAL_Open(&SrcFileHandle, (void *)(pStillCaptureImageInfo->MainImageStartAddr), FSAL_ROMFILE);
    jaiaSetSourceFile(pJaiaWorkspacePara, &SrcFileHandle);

#if defined(__JPEG_SENSOR_SUPPORT__)
    if(KAL_TRUE == pStillCaptureImageInfo->ExifWholeInfoAttach)
        jaiaUpdateAllExifEntry(pJaiaWorkspacePara);
#endif

    JaiaImageInfo.type = JAIA_IMAGE_TYPE_UNCOMPRESSED;
    if (KAL_TRUE==pStillCaptureInfo->ThumbnailImageEnable)
    {
        //JaiaImageInfo.type = JAIA_IMAGE_TYPE_UNCOMPRESSED;
        JaiaImageInfo.color_format = GetJaiaFormat(pStillCaptureInfo->ThumbnailImageFormat);
        JaiaImageInfo.buff_rgb_y.buff_addr = (void *) pStillCaptureInfo->ThumbnailImageBuffAddr;
        JaiaImageInfo.buff_rgb_y.buff_size = pStillCaptureInfo->ThumbnailImageBuffSize;
        if (pStillCaptureInfo->ThumbnailImageFormat == MM_IMAGE_FORMAT_YUV420)
        {
            kal_uint32 y_size = pStillCaptureInfo->ThumbnailImageWidth * pStillCaptureInfo->ThumbnailImageHeight;

            JaiaImageInfo.buff_u.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_rgb_y.buff_addr + y_size);
            JaiaImageInfo.buff_u.buff_size = y_size >> 2;

            JaiaImageInfo.buff_v.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_u.buff_addr + JaiaImageInfo.buff_u.buff_size);
            JaiaImageInfo.buff_v.buff_size = y_size >> 2;
        }
        else if (pStillCaptureInfo->ThumbnailImageFormat == MM_IMAGE_FORMAT_YUV422)
        {
            kal_uint32 y_size = pStillCaptureInfo->ThumbnailImageWidth * pStillCaptureInfo->ThumbnailImageHeight;

            JaiaImageInfo.buff_u.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_rgb_y.buff_addr + y_size);
            JaiaImageInfo.buff_u.buff_size = y_size >> 1;

            JaiaImageInfo.buff_v.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_u.buff_addr + JaiaImageInfo.buff_u.buff_size);
            JaiaImageInfo.buff_v.buff_size = y_size >> 1;
        }

        JaiaImageInfo.width = pStillCaptureInfo->ThumbnailImageWidth;
        JaiaImageInfo.height = pStillCaptureInfo->ThumbnailImageHeight;
        JaiaImageInfo.size = pStillCaptureInfo->ThumbnailImageWidth*
                             pStillCaptureInfo->ThumbnailImageHeight*3;
        jaiaAddThumbnail(pJaiaWorkspacePara, &JaiaImageInfo,
                         pStillCaptureInfo->ThumbnailImageWidth,
                         pStillCaptureInfo->ThumbnailImageHeight);
    }

    if (KAL_TRUE==pStillCaptureInfo->QuickViewImageEnable)
    {
        JaiaImageInfo.color_format = GetJaiaFormat(pStillCaptureInfo->QuickViewImageFormat);
        JaiaImageInfo.buff_rgb_y.buff_addr = (void *) pStillCaptureInfo->QuickViewImageBuffAddr;
        JaiaImageInfo.buff_rgb_y.buff_size = pStillCaptureInfo->QuickViewImageBuffSize;
        if (pStillCaptureInfo->QuickViewImageFormat == MM_IMAGE_FORMAT_YUV420)
        {
            kal_uint32 y_size = pStillCaptureInfo->QuickViewImageWidth * pStillCaptureInfo->QuickViewImageHeight;

            JaiaImageInfo.buff_u.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_rgb_y.buff_addr + y_size);
            JaiaImageInfo.buff_u.buff_size = y_size >> 2;

            JaiaImageInfo.buff_v.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_u.buff_addr + JaiaImageInfo.buff_u.buff_size);
            JaiaImageInfo.buff_v.buff_size = y_size >> 2;
        }
        else if (pStillCaptureInfo->QuickViewImageFormat == MM_IMAGE_FORMAT_YUV422)
        {
            kal_uint32 y_size = pStillCaptureInfo->QuickViewImageWidth * pStillCaptureInfo->QuickViewImageHeight;

            JaiaImageInfo.buff_u.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_rgb_y.buff_addr + y_size);
            JaiaImageInfo.buff_u.buff_size = y_size >> 1;

            JaiaImageInfo.buff_v.buff_addr = (void *) ((kal_uint32)JaiaImageInfo.buff_u.buff_addr + JaiaImageInfo.buff_u.buff_size);
            JaiaImageInfo.buff_v.buff_size = y_size >> 1;
        }

        JaiaImageInfo.width = pStillCaptureInfo->QuickViewImageWidth;
        JaiaImageInfo.height = pStillCaptureInfo->QuickViewImageHeight;
        JaiaImageInfo.size = pStillCaptureInfo->QuickViewImageWidth*
                             pStillCaptureInfo->QuickViewImageHeight*2;
        jaiaAddQVI(pJaiaWorkspacePara, &JaiaImageInfo,
                   pStillCaptureInfo->QuickViewImageWidth,
                   pStillCaptureInfo->QuickViewImageHeight);
    }

    // Set destination buffer
    JaiaDestBuffer.buff_addr = (void *)(pStillCaptureInfo->MainImageBuffAddr);
    JaiaDestBuffer.buff_size = pStillCaptureInfo->MainImageBuffSize;
    jaiaSetDestinationBuffer(pJaiaWorkspacePara, &JaiaDestBuffer);

    jaiaQueryWorkingMemory(pJaiaWorkspacePara, &IntWorkingMemSize, &ExtWorkingMemSize);

    JaiaIntMem.buff_addr =(void *) WorkingBuffAddr;
    JaiaIntMem.buff_size = IntWorkingMemSize;
    WorkingBuffAddr+=IntWorkingMemSize;
    JaiaExtMem.buff_addr = (void *) WorkingBuffAddr;
    JaiaExtMem.buff_size = ExtWorkingMemSize;

    ASSERT(WorkingBuffSize > (IntWorkingMemSize+ExtWorkingMemSize));

    jaiaSetWorkingMemory(pJaiaWorkspacePara, &JaiaIntMem, &JaiaExtMem);
    JaiaErrorCode=jaiaStart(pJaiaWorkspacePara);

    jaiaGetResult(pJaiaWorkspacePara, (void *) &pJpegEncodedDataAddr, &JpegEncodedDataSize);

    FSAL_Close(&SrcFileHandle);

    // callback to CAL to notify MED that JPEG capture complete
    if (JAIA_RETURN_OK==JaiaErrorCode)
    {
        JaiaImagePara.ErrorStatus=MM_ERROR_NONE;
        JaiaImagePara.ImageBuffFormat=MM_IMAGE_FORMAT_JPEG;
        JaiaImagePara.ImageBuffAddr=(kal_uint32) pJpegEncodedDataAddr;
        JaiaImagePara.ImageBuffSize=JpegEncodedDataSize;
        JaiaCallback(pStillCaptureImageInfo->JaiaCbId, &JaiaImagePara, sizeof(CAL_BUFFER_CB_STRUCT));
    }
    else
        ASSERT(0);

    jaiaReleaseWorkspace(pJaiaWorkspacePara);
}   /* JaiaMergeHandle() */
#endif

#if (defined(__CAL_GET_PREVIEW_IMAGE_SUPPORT__)||defined(__CAL_IMAGE_ROTATE_RGB_SUPPORT__))
ROTATOR_COLOR_FORMAT_ENUM GetRotatorFormat(MM_IMAGE_FORMAT_ENUM ImageFormat)
{
    ROTATOR_COLOR_FORMAT_ENUM RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_RGB565;

    switch (ImageFormat)
    {
    #ifdef __CAL_IMAGE_ROTATE_RGB_SUPPORT__
        case MM_IMAGE_FORMAT_RGB565:
            RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_RGB565;
        break;
        case MM_IMAGE_FORMAT_RGB888:
            RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_RGB888;
        break;
    #endif
        case MM_IMAGE_FORMAT_YUV420:
            #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_YUV420_B4x4_P;
            #else
            RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_YUV420_P;
            #endif
        break;
        case MM_IMAGE_FORMAT_PACKET_UYVY422:
            RotatorDataFormat=ROTATOR_COLOR_FORMAT_ENUM_UYVY422;
        break;
        default:
            ASSERT(0);
        break;
    }
    return RotatorDataFormat;
}   /* GetRotatorFormat() */
#endif

#ifdef __CAL_IMAGE_ROTATE_SUPPORT__
void ImageRotHandle(ilm_struct *pIlmPtr)
{
    P_CAL_ROTATE_IMAGE_REQ_STRUCT pImageRotateInfo;
    CAL_BUFFER_CB_STRUCT ImageRotPara;

    ROTATOR_STATUS_ENUM RotatorStatus;
    ROTATOR_COLOR_FORMAT_ENUM RotatorColorFormat;
    YUV_ROTATOR_HANDLE_STRUCT *pYuvRotHandle;
    kal_uint32 DestImageWidth, DestImageHeight;
    kal_uint32 ExtMemMin, ExtMemBest, IntMemMin, IntMemBest;

#ifdef __CAL_IMAGE_ROTATE_RGB_SUPPORT__
    RGB_ROTATOR_HANDLE_STRUCT *pRgbRotHandle;
#endif

    pImageRotateInfo = (P_CAL_ROTATE_IMAGE_REQ_STRUCT) pIlmPtr->local_para_ptr;

    if (pImageRotateInfo->ImageRotAngle & 0x1)
    {
        DestImageWidth=pImageRotateInfo->SrcImageHeight;
        DestImageHeight=pImageRotateInfo->SrcImageWidth;
    }
    else
    {
        DestImageWidth=pImageRotateInfo->SrcImageWidth;
        DestImageHeight=pImageRotateInfo->SrcImageHeight;
    }

    ImageRotPara.ImageBuffSize=DestImageWidth*DestImageHeight*3/2;
    ImageRotPara.ErrorStatus=MM_ERROR_NONE;
    ImageRotPara.ImageBuffAddr=pImageRotateInfo->DestImageYBuffAddr;
    ImageRotPara.ImageBuffFormat=pImageRotateInfo->ImageDataFormat;

    if ((MM_IMAGE_FORMAT_YUV420==pImageRotateInfo->ImageDataFormat)||
        (MM_IMAGE_FORMAT_PACKET_UYVY422==pImageRotateInfo->ImageDataFormat))
    {
        if (MM_IMAGE_FORMAT_YUV420==pImageRotateInfo->ImageDataFormat)
        {
            #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            RotatorColorFormat=ROTATOR_COLOR_FORMAT_ENUM_YUV420_B4x4_P;
            #else
            RotatorColorFormat=ROTATOR_COLOR_FORMAT_ENUM_YUV420_P;
            #endif
        }
        else
        {
            RotatorColorFormat = ROTATOR_COLOR_FORMAT_ENUM_UYVY422;
        }

        RotatorStatus=yuvRotatorGetHandle(&pYuvRotHandle, ROTATOR_MODE_AUTO);
        ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

        yuvRotatorSetCallbackFunction(pYuvRotHandle, NULL);     // use polling mode instead of interrupt mode

        if (MM_IMAGE_FORMAT_YUV420==pImageRotateInfo->ImageDataFormat)
        {
            yuvRotatorSetSrcBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                       (void *) pImageRotateInfo->SrcImageYBuffAddr,
                                       (void *) pImageRotateInfo->SrcImageUBuffAddr,
                                       (void *) pImageRotateInfo->SrcImageVBuffAddr,
                                       pImageRotateInfo->ImageYBuffSize, pImageRotateInfo->ImageUBuffSize,
                                       pImageRotateInfo->ImageVBuffSize,
                                       pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

            yuvRotatorSetDstBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                       (void *) pImageRotateInfo->DestImageYBuffAddr,
                                       (void *) pImageRotateInfo->DestImageUBuffAddr,
                                       (void *) pImageRotateInfo->DestImageVBuffAddr,
                                       pImageRotateInfo->ImageYBuffSize, pImageRotateInfo->ImageUBuffSize,
                                       pImageRotateInfo->ImageVBuffSize,
                                       DestImageWidth, DestImageHeight);
        }
        else
        {
            yuvRotatorSetSrcBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                       (void *) pImageRotateInfo->SrcImageYBuffAddr,
                                       (void *) 0, (void *) 0,
                                       pImageRotateInfo->SrcImageWidth*pImageRotateInfo->SrcImageHeight*2,
                                       0, 0,
                                       pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

            yuvRotatorSetDstBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                       (void *) pImageRotateInfo->DestImageYBuffAddr,
                                       (void *) 0, (void *) 0,
                                       pImageRotateInfo->SrcImageWidth*pImageRotateInfo->SrcImageHeight*2,
                                       0, 0,
                                       DestImageWidth, DestImageHeight);
        }

        yuvRotatorSetSrcWindow(pYuvRotHandle, 0, 0, pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

        yuvRotatorSetDstWindow(pYuvRotHandle, 0, 0, DestImageWidth, DestImageHeight);

        yuvRotatorSetRotation(pYuvRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) pImageRotateInfo->ImageRotAngle);

        yuvRotatorCheckAbortFunction(pYuvRotHandle, NULL);

        yuvRotatorQueryWorkingMemory(pYuvRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

        ASSERT(0==IntMemMin);
        ASSERT(ExtMemMin<=pImageRotateInfo->WorkingBuffSize);

        yuvRotatorSetWorkingMemory(pYuvRotHandle, NULL, 0, (kal_uint32 *) pImageRotateInfo->WorkingBuffAddr,
                                   pImageRotateInfo->WorkingBuffSize);

        yuvRotatorStart(&pYuvRotHandle);

        while ((yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_OK)&&
               (yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_COMPLETE));

        yuvRotatorReleaseHandle(pYuvRotHandle);
    }
#ifdef __CAL_IMAGE_ROTATE_RGB_SUPPORT__
    else if ((MM_IMAGE_FORMAT_RGB565==pImageRotateInfo->ImageDataFormat)||
             (MM_IMAGE_FORMAT_RGB888==pImageRotateInfo->ImageDataFormat))
    {
        if (MM_IMAGE_FORMAT_RGB565==pImageRotateInfo->ImageDataFormat)
        {
            ImageRotPara.ImageBuffSize=DestImageWidth*DestImageHeight*2;
        }
        else if (MM_IMAGE_FORMAT_RGB888==pImageRotateInfo->ImageDataFormat)
        {
            ImageRotPara.ImageBuffSize=DestImageWidth*DestImageHeight*3;
        }
        RotatorColorFormat=GetRotatorFormat(pImageRotateInfo->ImageDataFormat);

        RotatorStatus=rgbRotatorGetHandle(&pRgbRotHandle, ROTATOR_MODE_AUTO);
        ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

        rgbRotatorSetCallbackFunction(pRgbRotHandle, NULL);     // use polling mode instead of interrupt mode

        rgbRotatorSetSrcBufferInfo(pRgbRotHandle, RotatorColorFormat,
                                   (void *) pImageRotateInfo->SrcImageYBuffAddr,
                                   pImageRotateInfo->ImageYBuffSize,
                                   pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

        rgbRotatorSetDstBufferInfo(pRgbRotHandle, RotatorColorFormat,
                                   (void *) pImageRotateInfo->DestImageYBuffAddr,
                                   pImageRotateInfo->ImageYBuffSize,
                                   DestImageWidth, DestImageHeight);

        rgbRotatorSetSrcWindow(pRgbRotHandle, 0, 0, pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

        rgbRotatorSetDstWindow(pRgbRotHandle, 0, 0, DestImageWidth, DestImageHeight);

        rgbRotatorSetRotation(pRgbRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) pImageRotateInfo->ImageRotAngle);

        rgbRotatorCheckAbortFunction(pRgbRotHandle, NULL);

        rgbRotatorQueryWorkingMemory(pRgbRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

        ASSERT(IntMemMin==0);
        ASSERT(ExtMemMin<=pImageRotateInfo->WorkingBuffSize);

        rgbRotatorSetWorkingMemory(pRgbRotHandle, NULL, 0, (kal_uint32 *) pImageRotateInfo->WorkingBuffAddr,
                                   pImageRotateInfo->WorkingBuffSize);

        rgbRotatorStart(&pRgbRotHandle);

        while ((rgbRotatorGetStatus(pRgbRotHandle)!=ROTATOR_STATUS_OK)&&
               (rgbRotatorGetStatus(pRgbRotHandle)!=ROTATOR_STATUS_COMPLETE));

        rgbRotatorReleaseHandle(pRgbRotHandle);
    }
#endif
    else
        ASSERT(0);

    ImageRotCallback(pImageRotateInfo->ImageRotCbId, &ImageRotPara, sizeof(CAL_BUFFER_CB_STRUCT));
}   /* ImageRotHandle() */
#endif

void ImageResizeHandle(ilm_struct *pIlmPtr)
{
    P_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT pImageResizeInfo;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pStillCaptureInfo;

#if (!defined(DRV_IDP_6252_SERIES) || defined(__AUTOCAP_PANORAMA_SUPPORT__)  || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__) )
    kal_uint32 YSrcBuffSize;
#endif
#if (!defined(__CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)  || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__) || defined(EXIF_SUPPORT) )
    kal_uint32 YDestBuffSize;
#endif

    CAL_BUFFER_CB_STRUCT ImageResizePara;

#ifdef __CAL_IMAGE_RESIZE_RGB_SUPPORT__
    RESIZER_STATUS_ENUM status;
#endif
#ifdef __CAL_IMAGE_RESIZE_RGB_SUPPORT__
    kal_uint32 RGBSrcBuffSize, RGBDestBuffSize;
    RGB_RESIZER_HANDLE_STRUCT *ResizerHandle;
    kal_uint32 IntMemBest, IntMemMin, ExtMemBest, ExtMemMin;
#endif

    pImageResizeInfo = (P_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT) pIlmPtr->local_para_ptr;

    pStillCaptureInfo=pImageResizeInfo->pCalStillCapPara;

    if (MM_IMAGE_FORMAT_YUV420==pStillCaptureInfo->MainImageJpegYuvSampleFormat)
    {
        #if (!defined(DRV_IDP_6252_SERIES) || defined(__AUTOCAP_PANORAMA_SUPPORT__)  || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__) )
        YSrcBuffSize = pStillCaptureInfo->MainImageWidth*pStillCaptureInfo->MainImageHeight;
        #endif
        ImageResizePara.ErrorStatus=MM_ERROR_NONE;
        if (pStillCaptureInfo->QuickViewImageEnable)
        {
            ImageResizePara.ImageBuffFormat=pStillCaptureInfo->QuickViewImageFormat;
        #if (!defined(__CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)  || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__) )
            YDestBuffSize = pStillCaptureInfo->QuickViewImageWidth*pStillCaptureInfo->QuickViewImageHeight;

            if (MM_IMAGE_FORMAT_YUV420==pStillCaptureInfo->QuickViewImageFormat)
            {   // YUV420 ==> YUV420
                #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                if(pImageResizeInfo->IsSrcClip)
                {
                    iul_csc_yuv420_to_yuv420_resize_with_src_clip((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint8 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                (kal_uint8 *) (pStillCaptureInfo->QuickViewImageBuffAddr+YDestBuffSize),
                                                (kal_uint8 *) (pStillCaptureInfo->QuickViewImageBuffAddr+YDestBuffSize+(YDestBuffSize>>2)),
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight,
                                                pImageResizeInfo->pSrcWindow);
                }
                else
                #endif
                {
                    iul_csc_yuv420_to_yuv420_resize((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint8 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                (kal_uint8 *) (pStillCaptureInfo->QuickViewImageBuffAddr+YDestBuffSize),
                                                (kal_uint8 *) (pStillCaptureInfo->QuickViewImageBuffAddr+YDestBuffSize+(YDestBuffSize>>2)),
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight);
                }

                ImageResizePara.ImageBuffYAddr=pStillCaptureInfo->QuickViewImageBuffAddr;
                ImageResizePara.ImageBuffUAddr=ImageResizePara.ImageBuffYAddr+YDestBuffSize;
                ImageResizePara.ImageBuffVAddr=ImageResizePara.ImageBuffUAddr+(YDestBuffSize>>2);
                ImageResizePara.ImageBuffUSize=YDestBuffSize>>2;
                ImageResizePara.ImageBuffVSize=YDestBuffSize>>2;
                ImageResizePara.ImageBuffYSize=YDestBuffSize;
                ImageResizeCallback(pImageResizeInfo->QuickViewImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
            else if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->QuickViewImageFormat)
            {
                #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
                if( (CalHdrQviDitheringOn)&&(CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY == pImageResizeInfo->QuickViewImageResizeCbId) )
                {
                    iul_csc_yuv420_to_yuv420_resize((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)+YDestBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)+YDestBuffSize+(YDestBuffSize>>2)),
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight);

                    iul_csc_yuv420_to_rgb565_mwc_dithering((kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)+YDestBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>1)+YDestBuffSize+(YDestBuffSize>>2)),
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageWidth>>1,
                                                (kal_uint16 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                pStillCaptureInfo->QuickViewImageWidth*2,
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight);
                }
                else
                #endif
                {
                    #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    if(pImageResizeInfo->IsSrcClip)
                    {
                        iul_csc_yuv420_to_rgb565_resize_with_src_clip((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint16 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight,
                                                pImageResizeInfo->pSrcWindow);
                    }
                    else
                    #endif
                    {
                        iul_csc_yuv420_to_rgb565_resize((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint16 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                pStillCaptureInfo->QuickViewImageWidth,
                                                pStillCaptureInfo->QuickViewImageHeight);
                    }
                }
                ImageResizePara.ImageBuffAddr=pStillCaptureInfo->QuickViewImageBuffAddr;
                ImageResizePara.ImageBuffSize=pStillCaptureInfo->QuickViewImageWidth*pStillCaptureInfo->QuickViewImageHeight*2;
                ImageResizeCallback(pImageResizeInfo->QuickViewImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
            else if (MM_IMAGE_FORMAT_PACKET_UYVY422==pStillCaptureInfo->QuickViewImageFormat)
        #else // __CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__
            if (MM_IMAGE_FORMAT_PACKET_UYVY422==pStillCaptureInfo->QuickViewImageFormat)
        #endif
            { // YUV420==>UYVY422
                iul_rect TempRect;

                if(pImageResizeInfo->IsSrcClip)
                {
                    TempRect.offsetX=pImageResizeInfo->pSrcWindow->offsetX;
                    TempRect.offsetY=pImageResizeInfo->pSrcWindow->offsetY;
                    TempRect.width=pImageResizeInfo->pSrcWindow->width;
                    TempRect.height=pImageResizeInfo->pSrcWindow->height;
                }
                else
                {
                    TempRect.offsetX=0;
                    TempRect.offsetY=0;
                    TempRect.width=pStillCaptureInfo->MainImageWidth& ~0x00000001;
                    TempRect.height=pStillCaptureInfo->MainImageHeight& ~0x00000001;
                }

                iul_csc_yuv420_to_yuv422itlv_resize_with_src_clip((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                                #if defined(DRV_IDP_6252_SERIES) // Because 52 series uv maybe not continus.
                                                                 (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddrU),
                                                                 (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddrV),
                                                                #else
                                                                 (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                                 (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                                #endif
                                                                  pStillCaptureInfo->MainImageWidth,
                                                                  pStillCaptureInfo->MainImageHeight,
                                                                  (kal_uint32 *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                                                  pStillCaptureInfo->QuickViewImageWidth,
                                                                  pStillCaptureInfo->QuickViewImageHeight,
                                                                  &TempRect);
                ImageResizePara.ImageBuffAddr=pStillCaptureInfo->QuickViewImageBuffAddr;
                ImageResizePara.ImageBuffSize=pStillCaptureInfo->QuickViewImageWidth*pStillCaptureInfo->QuickViewImageHeight*2;
                ImageResizeCallback(pImageResizeInfo->QuickViewImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        }

        #if defined(EXIF_SUPPORT)
        if (pStillCaptureInfo->ThumbnailImageEnable)
        {
            YDestBuffSize = pStillCaptureInfo->ThumbnailImageWidth*pStillCaptureInfo->ThumbnailImageHeight;

            ImageResizePara.ImageBuffFormat = pStillCaptureInfo->ThumbnailImageFormat;
            if (MM_IMAGE_FORMAT_YUV420==pStillCaptureInfo->ThumbnailImageFormat)
            {   // YUV420 ==> YUV420
                iul_csc_yuv420_to_yuv420_resize((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                              #if defined(DRV_IDP_6252_SERIES) // Because 52 series uv maybe not continus.
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddrU),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddrV),
                                              #else
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                              #endif
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint8 *) pStillCaptureInfo->ThumbnailImageBuffAddr,
                                                (kal_uint8 *) (pStillCaptureInfo->ThumbnailImageBuffAddr+YDestBuffSize),
                                                (kal_uint8 *) (pStillCaptureInfo->ThumbnailImageBuffAddr+YDestBuffSize+(YDestBuffSize>>2)),
                                                pStillCaptureInfo->ThumbnailImageWidth,
                                                pStillCaptureInfo->ThumbnailImageHeight);

                ImageResizePara.ImageBuffYAddr=pStillCaptureInfo->ThumbnailImageBuffAddr;
                ImageResizePara.ImageBuffUAddr=ImageResizePara.ImageBuffYAddr+YDestBuffSize;
                ImageResizePara.ImageBuffVAddr=ImageResizePara.ImageBuffUAddr+(YDestBuffSize>>2);
                ImageResizePara.ImageBuffYSize=YDestBuffSize;
                ImageResizePara.ImageBuffUSize=YDestBuffSize>>2;
                ImageResizePara.ImageBuffVSize=YDestBuffSize>>2;
                ImageResizeCallback(pImageResizeInfo->ThumbnailImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
            #if ( !defined(__CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__) )
            else if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->ThumbnailImageFormat)
            {
                ImageResizePara.ImageBuffAddr=pStillCaptureInfo->ThumbnailImageBuffAddr;
                ImageResizePara.ImageBuffSize=pStillCaptureInfo->ThumbnailImageWidth*
                                              pStillCaptureInfo->ThumbnailImageHeight*2;
                iul_csc_yuv420_to_rgb565_resize((kal_uint8 *) pImageResizeInfo->MainImageBuffAddr,
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageResizeInfo->MainImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pStillCaptureInfo->MainImageWidth,
                                                pStillCaptureInfo->MainImageHeight,
                                                (kal_uint16 *) pStillCaptureInfo->ThumbnailImageBuffAddr,
                                                pStillCaptureInfo->ThumbnailImageWidth,
                                                pStillCaptureInfo->ThumbnailImageHeight);

                ImageResizeCallback(pImageResizeInfo->ThumbnailImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
            #endif
        }
        #endif
    }
#ifdef __CAL_IMAGE_RESIZE_RGB_SUPPORT__
    else if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->MainImageJpegYuvSampleFormat)
    {
        //Only for QuickView, without Thumbnail
        RGBSrcBuffSize = pStillCaptureInfo->MainImageWidth*pStillCaptureInfo->MainImageHeight*2;

        if (pStillCaptureInfo->QuickViewImageEnable)
        {
            if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->QuickViewImageFormat)
            {
                status = RESIZER_STATUS_OK;
                RGBDestBuffSize = pStillCaptureInfo->QuickViewImageWidth*pStillCaptureInfo->QuickViewImageHeight*2;

                rgbResizerGetHandle(&ResizerHandle, RESIZER_MODE_SW, RESIZER_QUALITY_MEDIUM);
                rgbResizerSetCallbackFunction(ResizerHandle, NULL);

                rgbResizerSetSrcBufferInfo(ResizerHandle, RESIZER_COLOR_FORMAT_ENUM_RGB565, (void *) pImageResizeInfo->MainImageBuffAddr,
                                           RGBSrcBuffSize, pStillCaptureInfo->MainImageWidth, pStillCaptureInfo->MainImageHeight);
                rgbResizerSetDstBufferInfo(ResizerHandle, RESIZER_COLOR_FORMAT_ENUM_RGB565, (void *) pStillCaptureInfo->QuickViewImageBuffAddr,
                                           RGBDestBuffSize, pStillCaptureInfo->QuickViewImageWidth, pStillCaptureInfo->QuickViewImageHeight);

                rgbResizerSetSrcWindow(ResizerHandle, 0, 0, pStillCaptureInfo->MainImageWidth, pStillCaptureInfo->MainImageHeight);
                rgbResizerSetDstWindow(ResizerHandle, 0, 0, pStillCaptureInfo->QuickViewImageWidth, pStillCaptureInfo->QuickViewImageHeight);
                rgbResizerSetDstClipWindow(ResizerHandle, KAL_FALSE, 0, 0, pStillCaptureInfo->QuickViewImageWidth, pStillCaptureInfo->QuickViewImageHeight);
                rgbResizerSetSrcKey(ResizerHandle, KAL_FALSE, 0xFFFF);
                rgbResizerSetColorReplacement(ResizerHandle, KAL_FALSE, 0x0, 0xFFFF);
                rgbResizerSetDithering(ResizerHandle, KAL_FALSE);
                rgbResizerCheckAbortFunction(ResizerHandle, NULL);
                rgbResizerQueryWorkingMemory(ResizerHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

                ASSERT(0==IntMemMin);
                ASSERT(ExtMemMin<=pImageResizeInfo->WorkingBuffSize);

                rgbResizerSetWorkingMemory(ResizerHandle, NULL, 0, (kal_uint32 *) pImageResizeInfo->WorkingBuffAddr,
                                           pImageResizeInfo->WorkingBuffSize);

                rgbResizerStart(&ResizerHandle);

                status = RESIZER_STATUS_BUSY;
                while(RESIZER_STATUS_BUSY == status)
                {
                   status = rgbResizerGetStatus(ResizerHandle);
                   switch(status)
                   {
                      case RESIZER_STATUS_BUSY:
                         /// resizing is on-going
                      break;
                      case RESIZER_STATUS_COMPLETE:
                         /// resizing is done
                      break;
                      default:
                         /// there are some error with this resizing
                      break;
                   }
                }
                rgbResizerReleaseHandle(ResizerHandle);

                ImageResizePara.ImageBuffFormat=MM_IMAGE_FORMAT_RGB565;
                ImageResizePara.ErrorStatus=MM_ERROR_NONE;
                ImageResizePara.ImageBuffAddr=pStillCaptureInfo->QuickViewImageBuffAddr;
                ImageResizePara.ImageBuffSize=pStillCaptureInfo->QuickViewImageWidth*
                                              pStillCaptureInfo->QuickViewImageHeight*2;
                ImageResizeCallback(pImageResizeInfo->QuickViewImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        }

        if (pStillCaptureInfo->ThumbnailImageEnable)
        {
            if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->ThumbnailImageFormat)
            {
                status = RESIZER_STATUS_OK;
                RGBDestBuffSize = pStillCaptureInfo->ThumbnailImageWidth*pStillCaptureInfo->ThumbnailImageHeight*2;

                rgbResizerGetHandle(&ResizerHandle, RESIZER_MODE_SW, RESIZER_QUALITY_MEDIUM);
                rgbResizerSetCallbackFunction(ResizerHandle, NULL);

                rgbResizerSetSrcBufferInfo(ResizerHandle, RESIZER_COLOR_FORMAT_ENUM_RGB565, (void *) pImageResizeInfo->MainImageBuffAddr,
                                           RGBSrcBuffSize, pStillCaptureInfo->MainImageWidth, pStillCaptureInfo->MainImageHeight);
                rgbResizerSetDstBufferInfo(ResizerHandle, RESIZER_COLOR_FORMAT_ENUM_RGB565, (void *) pStillCaptureInfo->ThumbnailImageBuffAddr,
                                           RGBDestBuffSize, pStillCaptureInfo->ThumbnailImageWidth, pStillCaptureInfo->ThumbnailImageHeight);

                rgbResizerSetSrcWindow(ResizerHandle, 0, 0, pStillCaptureInfo->MainImageWidth, pStillCaptureInfo->MainImageHeight);
                rgbResizerSetDstWindow(ResizerHandle, 0, 0, pStillCaptureInfo->ThumbnailImageWidth, pStillCaptureInfo->ThumbnailImageHeight);
                rgbResizerSetDstClipWindow(ResizerHandle, KAL_FALSE, 0, 0, pStillCaptureInfo->ThumbnailImageWidth, pStillCaptureInfo->ThumbnailImageHeight);
                rgbResizerSetSrcKey(ResizerHandle, KAL_FALSE, 0xFFFF);
                rgbResizerSetColorReplacement(ResizerHandle, KAL_FALSE, 0x0, 0xFFFF);
                rgbResizerSetDithering(ResizerHandle, KAL_FALSE);
                rgbResizerCheckAbortFunction(ResizerHandle, NULL);
                rgbResizerQueryWorkingMemory(ResizerHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

                ASSERT(0==IntMemMin);
                ASSERT(ExtMemMin<=pImageResizeInfo->WorkingBuffSize);

                rgbResizerSetWorkingMemory(ResizerHandle, NULL, 0, (kal_uint32 *) pImageResizeInfo->WorkingBuffAddr,
                                           pImageResizeInfo->WorkingBuffSize);

                rgbResizerStart(&ResizerHandle);

                status = RESIZER_STATUS_BUSY;
                while(RESIZER_STATUS_BUSY == status)
                {
                   status = rgbResizerGetStatus(ResizerHandle);
                   switch(status)
                   {
                      case RESIZER_STATUS_BUSY:
                         /// resizing is on-going
                      break;
                      case RESIZER_STATUS_COMPLETE:
                         /// resizing is done
                      break;
                      default:
                         /// there are some error with this resizing
                      break;
                   }
                }
                rgbResizerReleaseHandle(ResizerHandle);

                ImageResizePara.ImageBuffFormat=MM_IMAGE_FORMAT_RGB565;
                ImageResizePara.ErrorStatus=MM_ERROR_NONE;
                ImageResizePara.ImageBuffAddr=pStillCaptureInfo->ThumbnailImageBuffAddr;
                ImageResizePara.ImageBuffSize=pStillCaptureInfo->ThumbnailImageWidth*
                                              pStillCaptureInfo->ThumbnailImageHeight*2;
                ImageResizeCallback(pImageResizeInfo->ThumbnailImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        }
    }
#endif
#ifdef __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
    else if (MM_IMAGE_FORMAT_PACKET_UYVY422==pStillCaptureInfo->MainImageJpegYuvSampleFormat)
    {
        if (pStillCaptureInfo->ThumbnailImageEnable)
        {
            ImageResizePara.ImageBuffAddr=pStillCaptureInfo->ThumbnailImageBuffAddr;
            ImageResizePara.ImageBuffSize=pStillCaptureInfo->ThumbnailImageWidth*
                                          pStillCaptureInfo->ThumbnailImageHeight*2;
            if (MM_IMAGE_FORMAT_RGB565==pStillCaptureInfo->ThumbnailImageFormat)
            {   // UYVY422 ==> RGB565
                iul_csc_yuv422itlv_to_rgb565_resize((kal_uint32 *) pImageResizeInfo->MainImageBuffAddr,
                                                    pStillCaptureInfo->MainImageWidth,
                                                    pStillCaptureInfo->MainImageHeight,
                                                    (kal_uint16 *) pStillCaptureInfo->ThumbnailImageBuffAddr,
                                                    pStillCaptureInfo->ThumbnailImageWidth,
                                                    pStillCaptureInfo->ThumbnailImageHeight);

                ImageResizeCallback(pImageResizeInfo->ThumbnailImageResizeCbId, &ImageResizePara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        }
    }
#endif /* __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__ */
    else
        ASSERT(0);

    //ImageResizeCallback();
}   /* ImageResizeHandle() */

#ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
void GetPreviewImageHandle(ilm_struct *pIlmPtr)
{
    P_CAL_GET_PREVIEW_IMAGE_STRUCT pPreviewImageInfo;
    CAL_BUFFER_CB_STRUCT PreviewImageBuffCbPara;

    YUV_ROTATOR_HANDLE_STRUCT *pYuvRotHandle;

    ROTATOR_STATUS_ENUM RotatorStatus;
    kal_uint32 DestImageWidth, DestImageHeight;
    kal_uint32 ExtMemMin, ExtMemBest, IntMemMin, IntMemBest;

    #if (defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H) || defined(MT6253))
    RGB_ROTATOR_HANDLE_STRUCT *pRgbRotHandle;
    #endif

    // 1. rotate the preview image
    pPreviewImageInfo = (P_CAL_GET_PREVIEW_IMAGE_STRUCT) pIlmPtr->local_para_ptr;

    if ((pPreviewImageInfo->SrcImageDataFormat==pPreviewImageInfo->pGetPreviewImagePara->ImageDataFormat)&&
        ((MM_IMAGE_FORMAT_RGB565==pPreviewImageInfo->SrcImageDataFormat)||
         (MM_IMAGE_FORMAT_PACKET_UYVY422==pPreviewImageInfo->SrcImageDataFormat)))
    {
        if (pPreviewImageInfo->pGetPreviewImagePara->ImageBuffSize<pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2)
            ASSERT(0);

        if (pPreviewImageInfo->pGetPreviewImagePara->ImageRotAngle & 0x01)
        {
            DestImageWidth = pPreviewImageInfo->SrcImageHeight;
            DestImageHeight = pPreviewImageInfo->SrcImageWidth;
        }
        else
        {
            DestImageWidth = pPreviewImageInfo->SrcImageWidth;
            DestImageHeight = pPreviewImageInfo->SrcImageHeight;
        }

        if (MM_IMAGE_ROTATE_0!=pPreviewImageInfo->pGetPreviewImagePara->ImageRotAngle)
        {
            if ((DestImageWidth==pPreviewImageInfo->pGetPreviewImagePara->ImageWidth)&&
                (DestImageHeight==pPreviewImageInfo->pGetPreviewImagePara->ImageHeight))
            {   // rotate the image from source to destination.
            #if (defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H) || defined(MT6253))
                RotatorStatus=rgbRotatorGetHandle(&pRgbRotHandle, ROTATOR_MODE_AUTO);
                ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

                rgbRotatorSetCallbackFunction(pRgbRotHandle, NULL);     // use polling mode instead of interrupt mode

                rgbRotatorSetSrcBufferInfo(pRgbRotHandle, ROTATOR_COLOR_FORMAT_ENUM_RGB565,
                                           (void *) pPreviewImageInfo->SrcImageBuffAddr,
                                           pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2,
                                           pPreviewImageInfo->SrcImageWidth, pPreviewImageInfo->SrcImageHeight);

                rgbRotatorSetDstBufferInfo(pRgbRotHandle, ROTATOR_COLOR_FORMAT_ENUM_RGB565,
                                           (void *) pPreviewImageInfo->pGetPreviewImagePara->ImageBuffAddr,
                                           pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2,
                                           DestImageWidth, DestImageHeight);

                rgbRotatorSetSrcWindow(pRgbRotHandle, 0, 0, pPreviewImageInfo->SrcImageWidth, pPreviewImageInfo->SrcImageHeight);

                rgbRotatorSetDstWindow(pRgbRotHandle, 0, 0, DestImageWidth, DestImageHeight);

                rgbRotatorSetRotation(pRgbRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) pPreviewImageInfo->pGetPreviewImagePara->ImageRotAngle);

                rgbRotatorCheckAbortFunction(pRgbRotHandle, NULL);

                rgbRotatorQueryWorkingMemory(pRgbRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

                ASSERT(IntMemMin==0);
                ASSERT(ExtMemMin<=pPreviewImageInfo->WorkingBuffSize);

                rgbRotatorSetWorkingMemory(pRgbRotHandle, NULL, 0, (kal_uint32 *) pPreviewImageInfo->WorkingBuffAddr,
                                           pPreviewImageInfo->WorkingBuffSize);

                rgbRotatorStart(&pRgbRotHandle);

                while ((rgbRotatorGetStatus(pRgbRotHandle)!=ROTATOR_STATUS_OK)&&
                       (rgbRotatorGetStatus(pRgbRotHandle)!=ROTATOR_STATUS_COMPLETE));

                rgbRotatorReleaseHandle(pRgbRotHandle);
            #else
                RotatorStatus=yuvRotatorGetHandle(&pYuvRotHandle, ROTATOR_MODE_AUTO);
                ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

                yuvRotatorSetCallbackFunction(pYuvRotHandle, NULL);     // use polling mode instead of interrupt mode

                //yuvRotatorSetSrcBufferInfo(pYuvRotHandle, GetRotatorFormat(pPreviewImageInfo->SrcImageDataFormat),
                yuvRotatorSetSrcBufferInfo(pYuvRotHandle, ROTATOR_COLOR_FORMAT_ENUM_UYVY422,
                                           (void *) pPreviewImageInfo->SrcImageBuffAddr,
                                           (void *) 0, (void *) 0,
                                           pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2,
                                           0, 0,
                                           pPreviewImageInfo->SrcImageWidth, pPreviewImageInfo->SrcImageHeight);

                //yuvRotatorSetDstBufferInfo(pYuvRotHandle, GetRotatorFormat(pPreviewImageInfo->SrcImageDataFormat),
                yuvRotatorSetDstBufferInfo(pYuvRotHandle, ROTATOR_COLOR_FORMAT_ENUM_UYVY422,
                                           (void *) pPreviewImageInfo->pGetPreviewImagePara->ImageBuffAddr,
                                           (void *) 0, (void *) 0,
                                           pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2,
                                           0, 0,
                                           DestImageWidth, DestImageHeight);

                yuvRotatorSetSrcWindow(pYuvRotHandle, 0, 0, pPreviewImageInfo->SrcImageWidth, pPreviewImageInfo->SrcImageHeight);

                yuvRotatorSetDstWindow(pYuvRotHandle, 0, 0, DestImageWidth, DestImageHeight);

                yuvRotatorSetRotation(pYuvRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) pPreviewImageInfo->pGetPreviewImagePara->ImageRotAngle);

                yuvRotatorCheckAbortFunction(pYuvRotHandle, NULL);

                yuvRotatorQueryWorkingMemory(pYuvRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

                ASSERT(0==IntMemMin);
                ASSERT(ExtMemMin<=pPreviewImageInfo->WorkingBuffSize);

                yuvRotatorSetWorkingMemory(pYuvRotHandle, NULL, 0, (kal_uint32 *) pPreviewImageInfo->WorkingBuffAddr,
                                           pPreviewImageInfo->WorkingBuffSize);

                yuvRotatorStart(&pYuvRotHandle);

                while ((yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_OK)&&
                       (yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_COMPLETE));

                yuvRotatorReleaseHandle(pYuvRotHandle);
            #endif
            }
            else
            {   // currently, we do not support image resize.
                ASSERT(0);
            }
        }
        else
        {
            if ((pPreviewImageInfo->SrcImageWidth==pPreviewImageInfo->pGetPreviewImagePara->ImageWidth)&&
                (pPreviewImageInfo->SrcImageHeight==pPreviewImageInfo->pGetPreviewImagePara->ImageHeight))
            {   // copy the source to destination buffer
                kal_mem_cpy((void *) pPreviewImageInfo->pGetPreviewImagePara->ImageBuffAddr,
                            (void *) pPreviewImageInfo->SrcImageBuffAddr,
                            pPreviewImageInfo->SrcImageWidth*pPreviewImageInfo->SrcImageHeight*2);
            }
            else
            {   // currently, we do not support image resize.
                ASSERT(0);
            }
        }
        // callback
        PreviewImageBuffCbPara.ErrorStatus=MM_ERROR_NONE;
        PreviewImageBuffCbPara.ImageBuffFormat=pPreviewImageInfo->SrcImageDataFormat;
        PreviewImageBuffCbPara.ImageBuffAddr=pPreviewImageInfo->pGetPreviewImagePara->ImageBuffAddr;
        PreviewImageBuffCbPara.ImageBuffSize=DestImageWidth*DestImageHeight*2;
        PreviewImageCallback(pPreviewImageInfo->GetPreviewImageCbId, &PreviewImageBuffCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
    }
    else
    {   // currently, we do not support color transform and support RGB565 and UYVY422 only
        ASSERT(0);
    }
}   /* GetPreviewImageHandle() */
#endif

#ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
void ImageY2RDitheringHandle(ilm_struct *pIlmPtr)
{
    P_CAL_IMAGE_Y2R_DITHERING_STRUCT pImageInfo;
    CAL_BUFFER_CB_STRUCT ImageBuffCbPara;

    pImageInfo = (P_CAL_IMAGE_Y2R_DITHERING_STRUCT) pIlmPtr->local_para_ptr;

    iul_csc_yuv422itlv_to_rgb565_mwc_dithering((unsigned int *) pImageInfo->ImageBuffAddr,
                                               (unsigned short *) pImageInfo->ImageBuffAddr,
                                               pImageInfo->ImageWidth, pImageInfo->ImageHeight);

    ImageBuffCbPara.ErrorStatus=MM_ERROR_NONE;
    ImageBuffCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_RGB565;
    ImageBuffCbPara.ImageBuffAddr=pImageInfo->ImageBuffAddr;
    ImageBuffCbPara.ImageBuffSize=pImageInfo->ImageWidth*pImageInfo->ImageHeight*2;
    Y2RDitheringCallback((CAL_CALLBACK_ID_ENUM) 0, &ImageBuffCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
} /* ImageY2RDitheringHandle() */
#endif
#if (defined(__POSTPROC_SUPPORT__))
MM_ERROR_CODE_ENUM CalPpStartReqHdlr(ilm_struct *pIlmPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_PP_PROC_REQ_STRUCT pMsg = (P_PP_PROC_REQ_STRUCT) pIlmPtr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pMsg->Func != NULL);

    pMsg->Func(pMsg->ScenarioId, pMsg->CtrlCode, pMsg->pParaIn, pMsg->pParaOut, pMsg->ParaOutLen);

    return MM_ERROR_NONE;
}
#endif /* defined(__POSTPROC_SUPPORT__) */

void CalTimeOutHandle(ilm_struct *pIlmPtr)
{
    CAL_BUFFER_CB_STRUCT JpegCbPara;
    stack_timer_struct *pStackTimerInfo=(stack_timer_struct *) pIlmPtr->local_para_ptr;

    switch (pStackTimerInfo->timer_indx)
    {
        case CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT:
            JpegCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT;
            StackTimeOutCallback(CAL_CBID_STILL_IMAGE_TIMEOUT, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
        break;
        default:
        break;
    }
}  /* CalTimeOutHandle() */

#if defined(__JPEG_SENSOR_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
void CalJpegDecode(P_CAL_JPEG_DECODE_STRUCT pClipInfo)
{
    JPEG_DECODER_HANDLE JpegHandle;
    kal_int32  JpegDecResult;
    STFSAL JpegSrc;
    kal_uint32 ReadBufferSizeBest = 0, ReadBufferSizeMinimum = 0;
    kal_uint32 FsalCacheSizeBest = 0, FsalCacheSizeMinimum = 0;
    void *pReadBuffer = NULL;
    void *pFsalCacheAddr = NULL;
    kal_uint32 IntMemSizeBest = 0, IntMemSizeMinimum = 0;
    kal_uint32 ExtMemSizeBest = 0, ExtMemSizeMinimum = 0;
    kal_uint32 *pIntMemAddr = NULL;
    kal_uint32 *pExtMemAddr = NULL;
    //UTL_SWITCH_CACHE_STRUCT CacheSwitch;
    //UTL_SWITCH_CACHE_RESULT_STRUCT SwitchRet;
    kal_bool ExtSwitchFlag = KAL_FALSE;

    kal_int32   RetValue;
    kal_uint8 CodecType = JPEG_CODEC_TYPE_HW;
    kal_uint32 ClipExtMemAddr = pClipInfo->ExtMemAddr;
    JPEG_CODEC_STATE_ENUM CurrentJpegDecState;

    /* create jpeg decoder handler */
    JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_HW, &JpegHandle);
    if (JPEG_STATUS_OK != JpegDecResult)
    {
        JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &JpegHandle);
        CodecType= JPEG_CODEC_TYPE_SW;
        if (JPEG_STATUS_OK != JpegDecResult)
        {
            ASSERT(0);
        }
    }

    /* set canvas window */
    if (MM_IMAGE_FORMAT_RGB565 == pClipInfo->ImageDstFormat)
    {
        //if (JPEG_CODEC_TYPE_HW == CodecType)
        //{
            /* switch to noncache */
        //}
        jpegDecSetRGBCanvas(JpegHandle,
            pClipInfo->ImageDstBuffer, pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_RGB_FORMAT_RGB565);
    }
    else if (MM_IMAGE_FORMAT_YUV420 == pClipInfo->ImageDstFormat)
    {
        JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight + (pClipInfo->DstWidth*pClipInfo->DstHeight)/4,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_YUV420);
        /* mt6268 HW jpeg dec not support YUV420 */
        if (JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT == JpegDecResult)
        {
            jpegDecReleaseDecoder(JpegHandle);
            JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &JpegHandle);
            CodecType= JPEG_CODEC_TYPE_SW;
            if (JPEG_STATUS_OK != JpegDecResult)
            {
                ASSERT(0);
            }

            JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight + (pClipInfo->DstWidth*pClipInfo->DstHeight)/4,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_YUV420);
        }

        if (JPEG_CODEC_TYPE_HW == CodecType)
        {
            /* switch to noncache */
            JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                    pClipInfo->ImageDstBuffer,
                                    pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight,
                                    pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight + (pClipInfo->DstWidth*pClipInfo->DstHeight)/4,
                                    pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_YUV420);
        }
    }
    else if (MM_IMAGE_FORMAT_PACKET_UYVY422 == pClipInfo->ImageDstFormat)
    {
        JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer,
                                NULL,
                                NULL,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_PACKED_UYVY422);
        /* mt6268 HW jpeg dec not support YUV420 */
        if (JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT == JpegDecResult)
        {
            jpegDecReleaseDecoder(JpegHandle);
            JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &JpegHandle);
            CodecType= JPEG_CODEC_TYPE_SW;
            if (JPEG_STATUS_OK != JpegDecResult)
            {
                ASSERT(0);
            }

            JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer,
                                NULL,
                                NULL,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_PACKED_UYVY422);
        }

        if (JPEG_CODEC_TYPE_HW == CodecType)
        {
            /* switch to noncache */
            JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                    pClipInfo->ImageDstBuffer,
                                    NULL,
                                    NULL,
                                    pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_PACKED_UYVY422);
        }
    }
    else
    {
        ASSERT(0);
    }

    /* Switch cacheability for working buffer */
    if (JPEG_CODEC_TYPE_SW == CodecType)
    {
        ExtSwitchFlag = CalExtMemSwitchCachableRegion(&(pClipInfo->ExtMemAddr), pClipInfo->ExtMemSize, KAL_TRUE);
        ClipExtMemAddr = pClipInfo->ExtMemAddr;
    }


    /* Set source image */
    JpegDecResult = jpegDecQueryFileBuffer( JpegHandle,
        &ReadBufferSizeBest, &ReadBufferSizeMinimum,
        &FsalCacheSizeBest, &FsalCacheSizeMinimum);

    /* allocate file buffer */
    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pReadBuffer = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pReadBuffer = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += ReadBufferSizeMinimum;

    if ((pReadBuffer == NULL) || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    /* allocate fsal cache */
    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pFsalCacheAddr = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pFsalCacheAddr = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += FsalCacheSizeMinimum;

    if ((pFsalCacheAddr == NULL) || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    /* open file */
    FSAL_Direct_SetRamFileSize(&JpegSrc, pClipInfo->ImageSrcBufferSize);
    RetValue = FSAL_Open(&JpegSrc, (void *)pClipInfo->ImageSrcBuffer, FSAL_ROMFILE);

    /* set source file */
    if (FSAL_OK != RetValue)
    {
        // ERR_OPEN_FILE_FAILED;
        ASSERT(0);
    }
    else
    {
        JpegDecResult = jpegDecSetSourceFile(JpegHandle,
            &JpegSrc, pReadBuffer, ReadBufferSizeMinimum, pFsalCacheAddr, FsalCacheSizeMinimum);
    }

    if (JPEG_STATUS_OK != JpegDecResult)
    {
        ASSERT(0);
    }

    /* set callback function*/
    //if (JPEG_CODEC_TYPE_HW == CodecType)
    //{
    //    JpegDecResult = jpegDecSetCallbackFunction(JpegHandle, UtlJpegDecCallback);
    //}
    //else
    //{
        JpegDecResult = jpegDecSetCallbackFunction(JpegHandle, NULL);
    //}


    jpegDecSetClipWindow(JpegHandle,
        pClipInfo->DstRoiX, pClipInfo->DstRoiY, pClipInfo->RoiWidth, pClipInfo->RoiHeight);
    jpegDecSetOutputWindow(JpegHandle,
        (kal_int32)(pClipInfo->DstRoiX-pClipInfo->SrcRoiX),
        (kal_int32)(pClipInfo->DstRoiY-pClipInfo->SrcRoiY),
        pClipInfo->DstWidth, pClipInfo->DstHeight);
    jpegDecSetDecodeMode(JpegHandle, JPEG_DECODE_MODE_MAIN_IMAGE);

    /* query working buffer */
    JpegDecResult = jpegDecQueryWorkingMemory(JpegHandle,
        &IntMemSizeBest, &IntMemSizeMinimum,
        &ExtMemSizeBest, &ExtMemSizeMinimum);

    pIntMemAddr = (void *)ClipExtMemAddr;
    ClipExtMemAddr += IntMemSizeMinimum;

    if (NULL == pIntMemAddr || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pExtMemAddr = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pExtMemAddr = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += ExtMemSizeMinimum;

    if (NULL == pExtMemAddr || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    /* set working buffer */
    JpegDecResult = jpegDecSetWorkingMemory(JpegHandle,
        pIntMemAddr, IntMemSizeMinimum,
        pExtMemAddr, ExtMemSizeMinimum);

    if (JPEG_STATUS_OK != JpegDecResult)
    {
        ASSERT(0);
    }

    // do not rotate the decoded image.
    jpegDecSetRotation(JpegHandle, JPEG_DECODE_NO_FLIP_ROTATE_CW_0);

    /* run decoder*/
    JpegDecResult = jpegDecStart(JpegHandle);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    do
    {
        jpegDecGetDecoderState(JpegHandle,&CurrentJpegDecState);

        if (CurrentJpegDecState == JPEG_CODEC_STATE_ERROR)
        {
            ASSERT(0);
            break;  // need to do error handling ...
        }
        else if (CurrentJpegDecState == JPEG_CODEC_STATE_PAUSED)
        {
            jpegDecResume(JpegHandle);  // decode not finished
        }

    }while(JPEG_CODEC_STATE_COMPLETE != CurrentJpegDecState);
#endif

    if(JPEG_CODEC_STATE_COMPLETE != CurrentJpegDecState)
    {
        ASSERT(0);
    }

    if (JPEG_STATUS_OK != jpegDecGetLastError(JpegHandle))
    {
        ASSERT(0);
    }

    jpegDecReleaseDecoder(JpegHandle);
    FSAL_Close(&JpegSrc);

    //if ((JPEG_CODEC_TYPE_HW == CodecType)&&(KAL_TRUE == pClipInfo->IsSwitchCachable)&&(KAL_TRUE == SwitchRet.Ret))
    //{
        //CacheSwitch.CacheableFlag = KAL_TRUE;
        //UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
    //}

    if(ExtSwitchFlag)
    {
        CalExtMemSwitchCachableRegion(&(pClipInfo->ExtMemAddr), pClipInfo->ExtMemSize, KAL_FALSE);
    }
}
#endif
#if defined(__JPEG_SENSOR_SUPPORT__)
//kal_uint8 tmperrcnt = 0;
void CalJpegSensorParseHandle(ilm_struct *pIlmPtr)
{
    #define CAM_RECAPTURE_FAIL 3

    kal_uint32 JpegSensorDecodeWorkSize , JpegSensorDecodeWorkBuf;
    kal_uint32 CtrlOutLen;
    CAL_JPEG_DECODE_STRUCT pJpegInfo;
    CAL_BUFFER_CB_STRUCT JpegCbPara;
    CAL_BUFFER_CB_STRUCT QuickViewCbPara;
    CAL_MDP_STILL_CAPTURE_STRUCT TmpCalStillCaptureInfo;
    CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT MainImageResizePara;

    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_bool ExtSwitchFlag = KAL_FALSE;
    kal_mem_set(&JpegSensorParaOut, 0, sizeof(JPEG_SENSOR_PARSE_DATA_STRUCT));

    JpegSensorDecodeWorkBuf  = JpegSensorParaIn.WorkingBuffAddress+ ISP_JPEG_SENSOR_PARSE_BUF_SIZE;
    JpegSensorDecodeWorkSize = MdpStillCapturePara.extmem_size -ISP_JPEG_SENSOR_PARSE_BUF_SIZE;

    ExtSwitchFlag = CalExtMemSwitchCachableRegion(&(JpegSensorParaIn.ImageBuffAddress), JpegSensorParaIn.ImageBuffSize, KAL_TRUE);

    ErrorCode =  pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_JPEG_INFO, &JpegSensorParaIn, &JpegSensorParaOut,
                                    sizeof(JPEG_SENSOR_PARSE_DATA_STRUCT),&CtrlOutLen);

    if(ExtSwitchFlag)
    {
        CalExtMemSwitchCachableRegion(&(JpegSensorParaIn.ImageBuffAddress), JpegSensorParaIn.ImageBuffSize, KAL_FALSE);
    }

    kal_mem_cpy(&TmpCalStillCaptureInfo, &CalStillCaptureInfo, sizeof(CAL_MDP_STILL_CAPTURE_STRUCT));

    if(MM_ERROR_NONE== ErrorCode)
    {
        if(JpegSensorParaOut.IsThumbnailSupport)//(JpegSensorParaOut.IsThumbnailSupport)//jpeg with thumbnail image for quick view
        {
            // 1.decode for quick view
            if(CalStillCaptureInfo.QuickViewImageEnable || CalStillCaptureInfo.ThumbnailImageEnable)
            {
                // 2.encode for thumbnail
                // 2-1. send a meesage to CAL task to resize Main image as Quick view and thumbnail image.
                MainImageResizePara.pCalStillCapPara=&TmpCalStillCaptureInfo;
                MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_BEGIN;//0;//CAL_CBID_QUICK_VIEW_IMAGE_READY;
                MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_BEGIN;//0;//CAL_CBID_THUMBNAIL_IMAGE_READY;

                MainImageResizePara.MainImageBuffAddr=JpegSensorParaOut.ThumbnailAddress;
                MainImageResizePara.pCalStillCapPara->MainImageWidth = JpegSensorParaOut.ThumbnailWidth;
                MainImageResizePara.pCalStillCapPara->MainImageHeight = JpegSensorParaOut.ThumbnailHeight;
                MainImageResizePara.pCalStillCapPara->MainImageBuffAddr = JpegSensorParaOut.ThumbnailAddress;
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;//JpegSensorParaOut.ThumbnailFormat;

                TmpIlmInfo.local_para_ptr =  (local_para_struct *)&MainImageResizePara;
                ImageResizeHandle(&TmpIlmInfo);  //toDo

                // 4.callback to MED
                QuickViewCbPara.ErrorStatus=MM_ERROR_NONE;
                QuickViewCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_RGB565;
                QuickViewCbPara.ImageBuffAddr= TmpCalStillCaptureInfo.QuickViewImageBuffAddr;
                QuickViewCbPara.ImageBuffSize= TmpCalStillCaptureInfo.QuickViewImageBuffSize;
                pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, &QuickViewCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
        }
        else//jpeg without thumbnail image for quick view , need to decode while image for quick view
        {
            if(TmpCalStillCaptureInfo.QuickViewImageEnable== KAL_FALSE)
            {   // for resize as thumbnail
                TmpCalStillCaptureInfo.QuickViewImageEnable = KAL_TRUE;
                TmpCalStillCaptureInfo.QuickViewImageBuffAddr = JpegSensorParaIn.WorkingBuffAddress;
                TmpCalStillCaptureInfo.QuickViewImageBuffSize = JpegSensorParaIn.WorkingBuffSize;
                TmpCalStillCaptureInfo.QuickViewImageFormat = MM_IMAGE_FORMAT_RGB565;
                TmpCalStillCaptureInfo.QuickViewImageRotAngle= MM_IMAGE_ROTATE_0;
                TmpCalStillCaptureInfo.QuickViewImageWidth = TmpCalStillCaptureInfo.ThumbnailImageWidth;
                TmpCalStillCaptureInfo.QuickViewImageHeight= TmpCalStillCaptureInfo.ThumbnailImageHeight;
            }

            // 1.decode for quick view
            if(TmpCalStillCaptureInfo.QuickViewImageEnable)
            {
                pJpegInfo.ImageSrcBuffer = (kal_uint8 *)JpegSensorParaOut.JpegDataAddress;
                pJpegInfo.ImageSrcBufferSize =JpegSensorParaOut.JpegDataSize;
                pJpegInfo.SrcWidth =JpegSensorParaOut.JpegImageWidth;
                pJpegInfo.SrcHeight =JpegSensorParaOut.JpegImageHeight;
                pJpegInfo.SrcRoiX =0;
                pJpegInfo.SrcRoiY =0;
                pJpegInfo.RoiWidth =pJpegInfo.SrcWidth;
                pJpegInfo.RoiHeight = pJpegInfo.SrcHeight;
                pJpegInfo.ImageDstBuffer =  (kal_uint8 *)TmpCalStillCaptureInfo.QuickViewImageBuffAddr;
                pJpegInfo.ImageSrcFormat = MM_IMAGE_FORMAT_JPEG;
                pJpegInfo.ImageDstFormat = TmpCalStillCaptureInfo.QuickViewImageFormat;
                pJpegInfo.DstWidth =TmpCalStillCaptureInfo.QuickViewImageWidth;
                pJpegInfo.DstHeight =TmpCalStillCaptureInfo.QuickViewImageHeight;
                pJpegInfo.DstWidth =TmpCalStillCaptureInfo.QuickViewImageWidth;
                pJpegInfo.DstHeight =TmpCalStillCaptureInfo.QuickViewImageHeight;
                pJpegInfo.DstRoiX =0;
                pJpegInfo.DstRoiY =0;
                pJpegInfo.IsSwitchCachable = KAL_FALSE;
                pJpegInfo.ExtMemAddr = JpegSensorDecodeWorkBuf;
                pJpegInfo.ExtMemSize = JpegSensorDecodeWorkSize;

                CalJpegDecode(&pJpegInfo);

                QuickViewCbPara.ImageBuffAddr= TmpCalStillCaptureInfo.QuickViewImageBuffAddr;
                if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
                {   // rotate the quick view image for returning to MED
                    QuickViewImageRotate(CalStillCaptureInfo.QuickViewImageWidth, CalStillCaptureInfo.QuickViewImageHeight,
                                         TmpCalStillCaptureInfo.QuickViewImageBuffAddr, QuickViewImageDestBuffAddr, CalStillCaptureInfo.QuickViewImageRotAngle);
                    QuickViewCbPara.ImageBuffAddr= QuickViewImageDestBuffAddr;
                }

                // 4.callback to MED
                QuickViewCbPara.ErrorStatus=MM_ERROR_NONE;
                //QuickViewCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_RGB565;

                QuickViewCbPara.ImageBuffSize= TmpCalStillCaptureInfo.QuickViewImageBuffSize;
                pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, &QuickViewCbPara, sizeof(CAL_BUFFER_CB_STRUCT));

            }

            if(CalStillCaptureInfo.ThumbnailImageEnable)
            {
                // 2.encode for thumbnail
                // 2-1. send a meesage to CAL task to resize Main image as Quick view and thumbnail image.
                MainImageResizePara.pCalStillCapPara=&TmpCalStillCaptureInfo;
                MainImageResizePara.QuickViewImageResizeCbId = CAL_CBID_BEGIN;//0;//CAL_CBID_QUICK_VIEW_IMAGE_READY;
                MainImageResizePara.ThumbnailImageResizeCbId = CAL_CBID_BEGIN;//0;//CAL_CBID_THUMBNAIL_IMAGE_READY;

                MainImageResizePara.MainImageBuffAddr=TmpCalStillCaptureInfo.QuickViewImageBuffAddr;
                MainImageResizePara.pCalStillCapPara->MainImageWidth = TmpCalStillCaptureInfo.QuickViewImageWidth;
                MainImageResizePara.pCalStillCapPara->MainImageHeight = TmpCalStillCaptureInfo.QuickViewImageHeight;
                MainImageResizePara.pCalStillCapPara->MainImageBuffAddr = TmpCalStillCaptureInfo.QuickViewImageBuffAddr;
                MainImageResizePara.pCalStillCapPara->MainImageJpegYuvSampleFormat = TmpCalStillCaptureInfo.QuickViewImageFormat;

                MainImageResizePara.pCalStillCapPara->QuickViewImageEnable = KAL_FALSE;


                TmpIlmInfo.local_para_ptr =  (local_para_struct*) &MainImageResizePara;
                ImageResizeHandle(&TmpIlmInfo);  //toDo
            }
        }

        // 3.jaia combine to full jpeg file
        #if defined(EXIF_SUPPORT)
        JaiaMergePara.MainImageStartAddr=JpegSensorParaOut.JpegDataAddress;
        JaiaMergePara.MainImageSize=JpegSensorParaOut.JpegDataSize;
        JaiaMergePara.JaiaCbId= CAL_CBID_BEGIN;//0;//CAL_CBID_STILL_IMAGE_READY;
        JaiaMergePara.pCalStillCapPara=&CalStillCaptureInfo;

        TmpIlmInfo.local_para_ptr = (local_para_struct *)&JaiaMergePara;
        JaiaMergeHandle(&TmpIlmInfo);
        #endif

        // 4.callback to MED
        JpegCbPara.ErrorStatus=MM_ERROR_NONE;
        JpegCbPara.ImageBuffFormat=MM_IMAGE_FORMAT_JPEG;
        JpegCbPara.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
        JpegCbPara.ImageBuffSize= JpegEncodedDataSize;
        //stack_start_timer(&CalTaskStackTimer, CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT, 1100);
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if (CalPanoEnabled)
            pfCalCallback(CAL_CBID_PANO_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
        else
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
            pfCalCallback(CAL_CBID_STILL_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
    }
    else
    {
        if(CalJpegCaptureRetry>=2)
        {
            stack_start_timer(&CalTaskStackTimer, CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT, 500);
            if(CalStillCaptureInfo.QuickViewImageEnable)
            {
                // 4.callback to MED
                QuickViewCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT;
                pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, &QuickViewCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
            }
            JpegCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT;
            pfCalCallback(CAL_CBID_MAIN_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
        }
        else
        {
            //trigger re-capture
            CalJpegCaptureRetry++;
            IspJpegSensorCaptureStop();
            stack_start_timer(&CalTaskStackTimer, CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT, 1100);
            JpegSensorParaIn.ImageBuffSize =SensorScenarioParaIn.JpegSensorBufferSize;
            IspJpegSensorCaptureStart(JpegSensorParaIn.ImageBuffAddress);
        }
        //trigger MSG_ID_CAL_JPEG_SENSOR_PARSE_REQ again
    }

}  /* CalJpegSensorParseHandle() */
#endif

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
void ImageEffectHandle(ilm_struct *pIlmPtr)
{
    P_CAL_IMAGE_EFFECT_REQ_STRUCT pImageEffectInfo;
    CAL_BUFFER_CB_STRUCT ImageEffectCbPara;
#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
    kal_bool SrcDynamicSwitch = KAL_FALSE;
    kal_bool DstDynamicSwitch = KAL_FALSE;
    kal_bool TheSameBuffer = KAL_FALSE;
#endif
    pImageEffectInfo = (P_CAL_IMAGE_EFFECT_REQ_STRUCT) pIlmPtr->local_para_ptr;


#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
    if (pImageEffectInfo->SrcImageYBuffAddr==pImageEffectInfo->DestImageYBuffAddr)
    {
        TheSameBuffer = KAL_TRUE;
    }
    if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
    {
        if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->SrcImageYBuffAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageYBuffSize)) &&
            (is_predef_dyna_c_region(pImageEffectInfo->SrcImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)))
        {
            if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->SrcImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)))
            {
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_CACHEABLE);
                SrcDynamicSwitch = KAL_TRUE;
            }
        }
        if (TheSameBuffer)
        {
            DstDynamicSwitch = SrcDynamicSwitch;
            pImageEffectInfo->DestImageYBuffAddr = pImageEffectInfo->SrcImageYBuffAddr;
        }
        else
        {
            if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->DestImageYBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageYBuffSize)) &&
                (is_predef_dyna_c_region(pImageEffectInfo->DestImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)))
            {
                if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->DestImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)))
                {
                    dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_CACHEABLE);
                    DstDynamicSwitch = KAL_TRUE;
                }
            }
        }
    }
    else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
    {
        if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->SrcImageYBuffAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageYBuffSize)) &&
            (is_predef_dyna_c_region(pImageEffectInfo->SrcImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->SrcImageUBuffAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageUBuffSize)) &&
            (is_predef_dyna_c_region(pImageEffectInfo->SrcImageUBuffAddr, pImageEffectInfo->ImageUBuffSize)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->SrcImageVBuffAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageVBuffSize)) &&
            (is_predef_dyna_c_region(pImageEffectInfo->SrcImageVBuffAddr, pImageEffectInfo->ImageVBuffSize)))
        {
            if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->SrcImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)) &&
               (KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->SrcImageUBuffAddr, pImageEffectInfo->ImageUBuffSize)) &&
               (KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->SrcImageVBuffAddr, pImageEffectInfo->ImageVBuffSize)))
            {
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_CACHEABLE);
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageUBuffAddr), pImageEffectInfo->ImageUBuffSize, PAGE_CACHEABLE);
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageVBuffAddr), pImageEffectInfo->ImageVBuffSize, PAGE_CACHEABLE);
                SrcDynamicSwitch = KAL_TRUE;
            }
        }
        if (TheSameBuffer)
        {
            DstDynamicSwitch = SrcDynamicSwitch;
            pImageEffectInfo->DestImageYBuffAddr = pImageEffectInfo->SrcImageYBuffAddr;
            pImageEffectInfo->DestImageUBuffAddr = pImageEffectInfo->SrcImageUBuffAddr;
            pImageEffectInfo->DestImageVBuffAddr = pImageEffectInfo->SrcImageVBuffAddr;
        }
        else
        {
            if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->DestImageYBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageYBuffSize)) &&
                (is_predef_dyna_c_region(pImageEffectInfo->DestImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->DestImageUBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageUBuffSize)) &&
                (is_predef_dyna_c_region(pImageEffectInfo->DestImageUBuffAddr, pImageEffectInfo->ImageUBuffSize)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->DestImageVBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageEffectInfo->ImageVBuffSize)) &&
                (is_predef_dyna_c_region(pImageEffectInfo->DestImageVBuffAddr, pImageEffectInfo->ImageVBuffSize)))
            {
                if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->DestImageYBuffAddr, pImageEffectInfo->ImageYBuffSize)) &&
                   (KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->DestImageUBuffAddr, pImageEffectInfo->ImageUBuffSize)) &&
                   (KAL_TRUE == INT_QueryIsNonCachedRAM(pImageEffectInfo->DestImageVBuffAddr, pImageEffectInfo->ImageVBuffSize)))
                {
                    dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_CACHEABLE);
                    dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageUBuffAddr), pImageEffectInfo->ImageUBuffSize, PAGE_CACHEABLE);
                    dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageVBuffAddr), pImageEffectInfo->ImageVBuffSize, PAGE_CACHEABLE);
                    DstDynamicSwitch = KAL_TRUE;
                }
            }
        }
    }
#endif /* (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)) */
    if (CAM_EFFECT_ENC_LOMO == pImageEffectInfo->ImageEffectId)
    {
        if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreLomo_YUV422(pImageEffectInfo->SrcImageYBuffAddr,
                                    pImageEffectInfo->DestImageYBuffAddr,
                                    pImageEffectInfo->SrcImageWidth,
                                    pImageEffectInfo->SrcImageHeight);
        }
        else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreLomo_YUV420(pImageEffectInfo->SrcImageYBuffAddr,
                                    pImageEffectInfo->SrcImageUBuffAddr,
                                    pImageEffectInfo->SrcImageVBuffAddr,
                                    pImageEffectInfo->DestImageYBuffAddr,
                                    pImageEffectInfo->DestImageUBuffAddr,
                                    pImageEffectInfo->DestImageVBuffAddr,
                                    pImageEffectInfo->SrcImageWidth,
                                    pImageEffectInfo->SrcImageHeight);
        }
    }
    else if (CAM_EFFECT_ENC_COLOR_RED == pImageEffectInfo->ImageEffectId)
    {
        if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV422(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_RED);
        }
        else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV420(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->SrcImageUBuffAddr,
                                        pImageEffectInfo->SrcImageVBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->DestImageUBuffAddr,
                                        pImageEffectInfo->DestImageVBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_RED);
        }
    }
    else if (CAM_EFFECT_ENC_COLOR_YELLOW == pImageEffectInfo->ImageEffectId)
    {
        if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV422(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_YELLOW);
        }
        else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV420(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->SrcImageUBuffAddr,
                                        pImageEffectInfo->SrcImageVBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->DestImageUBuffAddr,
                                        pImageEffectInfo->DestImageVBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_YELLOW);
        }
    }
    else if (CAM_EFFECT_ENC_COLOR_BLUE == pImageEffectInfo->ImageEffectId)
    {
        if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV422(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_BLUE);
        }
        else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV420(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->SrcImageUBuffAddr,
                                        pImageEffectInfo->SrcImageVBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->DestImageUBuffAddr,
                                        pImageEffectInfo->DestImageVBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_BLUE);
        }
    }
    else if (CAM_EFFECT_ENC_COLOR_GREEN == pImageEffectInfo->ImageEffectId)
    {
        if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV422(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_GREEN);
        }
        else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
        {
            ImageEffectCoreColorAccent_YUV420(pImageEffectInfo->SrcImageYBuffAddr,
                                        pImageEffectInfo->SrcImageUBuffAddr,
                                        pImageEffectInfo->SrcImageVBuffAddr,
                                        pImageEffectInfo->DestImageYBuffAddr,
                                        pImageEffectInfo->DestImageUBuffAddr,
                                        pImageEffectInfo->DestImageVBuffAddr,
                                        pImageEffectInfo->SrcImageWidth,
                                        pImageEffectInfo->SrcImageHeight,
                                        COLOR_ACCENT_GREEN);
        }
    }
    else
    {
        if (pImageEffectInfo->DestImageYBuffAddr != pImageEffectInfo->SrcImageYBuffAddr)
        {
            if (MM_IMAGE_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
            {
                kal_mem_cpy((void *)pImageEffectInfo->DestImageYBuffAddr, (void *)pImageEffectInfo->SrcImageYBuffAddr,pImageEffectInfo->ImageYBuffSize);
            }
            else if (MM_IMAGE_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
            {
                kal_mem_cpy((void *)pImageEffectInfo->DestImageYBuffAddr, (void *)pImageEffectInfo->SrcImageYBuffAddr,pImageEffectInfo->ImageYBuffSize);
                kal_mem_cpy((void *)pImageEffectInfo->DestImageUBuffAddr, (void *)pImageEffectInfo->SrcImageUBuffAddr,pImageEffectInfo->ImageUBuffSize);
                kal_mem_cpy((void *)pImageEffectInfo->DestImageVBuffAddr, (void *)pImageEffectInfo->SrcImageVBuffAddr,pImageEffectInfo->ImageVBuffSize);
            }
        }
    }

#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
    if (MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422 == pImageEffectInfo->ImageDataFormat)
    {
        if(KAL_TRUE == SrcDynamicSwitch)
        {
            dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_NO_CACHE);
        }
        if (TheSameBuffer)
        {
            pImageEffectInfo->DestImageYBuffAddr = pImageEffectInfo->SrcImageYBuffAddr;
        }
        else
        {
            if (KAL_TRUE == DstDynamicSwitch)
            {
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_NO_CACHE);
            }
        }
    }
    else if (MM_IMAGE_COLOR_FORMAT_YUV420 == pImageEffectInfo->ImageDataFormat)
    {
        if(KAL_TRUE == SrcDynamicSwitch)
        {
            dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_NO_CACHE);
            dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageUBuffAddr), pImageEffectInfo->ImageUBuffSize, PAGE_NO_CACHE);
            dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->SrcImageVBuffAddr), pImageEffectInfo->ImageVBuffSize, PAGE_NO_CACHE);
        }
        if (TheSameBuffer)
        {
            pImageEffectInfo->DestImageYBuffAddr = pImageEffectInfo->SrcImageYBuffAddr;
            pImageEffectInfo->DestImageUBuffAddr = pImageEffectInfo->SrcImageUBuffAddr;
            pImageEffectInfo->DestImageVBuffAddr = pImageEffectInfo->SrcImageVBuffAddr;
        }
        else
        {
            if (KAL_TRUE == DstDynamicSwitch)
            {
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageYBuffAddr), pImageEffectInfo->ImageYBuffSize, PAGE_NO_CACHE);
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageUBuffAddr), pImageEffectInfo->ImageUBuffSize, PAGE_NO_CACHE);
                dynamic_switch_cacheable_region((void*)&(pImageEffectInfo->DestImageVBuffAddr), pImageEffectInfo->ImageVBuffSize, PAGE_NO_CACHE);
            }
        }
    }
#endif /* (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)) */

    ImageEffectCbPara.ImageBuffAddr = pImageEffectInfo->DestImageYBuffAddr;
    ImageEffectCbPara.ImageBuffSize = pImageEffectInfo->ImageYBuffSize;
    ImageEffectCbPara.ImageBuffYAddr = pImageEffectInfo->DestImageYBuffAddr;
    ImageEffectCbPara.ImageBuffUAddr = pImageEffectInfo->DestImageUBuffAddr;
    ImageEffectCbPara.ImageBuffVAddr = pImageEffectInfo->DestImageVBuffAddr;
    ImageEffectCbPara.ImageBuffYSize = pImageEffectInfo->ImageYBuffSize;
    ImageEffectCbPara.ImageBuffUSize = pImageEffectInfo->ImageUBuffSize;
    ImageEffectCbPara.ImageBuffVSize = pImageEffectInfo->ImageVBuffSize;
    ImageEffectCbPara.ImageBuffFormat = pImageEffectInfo->ImageDataFormat;
    ImageEffectCbPara.ErrorStatus = MM_ERROR_NONE;
    ImageEffectCbPara.ImageRotateAngle = pImageEffectInfo->ImageRotateAngle;
    ImageEffectCallback(pImageEffectInfo->ImageEffectCbId, &ImageEffectCbPara, sizeof(CAL_BUFFER_CB_STRUCT));

}   /* ImageEffectHandle() */
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
void ImageCopyAndResizeHandle(ilm_struct *pIlmPtr)
{
    P_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT pImageCopyResizeInfo;
    kal_uint32 YSrcBuffSize, YDestBuffSize;
#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
    kal_bool SrcDynamicSwitch=KAL_FALSE;
    kal_bool DstResizeDynamicSwitch=KAL_FALSE;
    kal_bool DstCopyDynamicSwitch=KAL_FALSE;
#endif

    pImageCopyResizeInfo = (P_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT) pIlmPtr->local_para_ptr;
    YSrcBuffSize = pImageCopyResizeInfo->SrcImageWidth*pImageCopyResizeInfo->SrcImageHeight;
    YDestBuffSize = pImageCopyResizeInfo->ResizeImageWidth*pImageCopyResizeInfo->ResizeImageHeight;


    if (MM_IMAGE_FORMAT_YUV420 == pImageCopyResizeInfo->ImageDataFormat)
    {
        #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
        if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->SrcImageBuffAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->SrcImageBuffSize)) &&
            (is_predef_dyna_c_region(pImageCopyResizeInfo->SrcImageBuffAddr, pImageCopyResizeInfo->SrcImageBuffSize)))
        {
            if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageCopyResizeInfo->SrcImageBuffAddr, pImageCopyResizeInfo->SrcImageBuffSize)))
            {
                dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->SrcImageBuffAddr), pImageCopyResizeInfo->SrcImageBuffSize, PAGE_CACHEABLE);
                SrcDynamicSwitch = KAL_TRUE;
            }
        }
        if (pImageCopyResizeInfo->IsResizeEnable)
        {
            if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->ResizeImageBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->ResizeImageBuffSize)) &&
                (is_predef_dyna_c_region(pImageCopyResizeInfo->ResizeImageBuffAddr, pImageCopyResizeInfo->ResizeImageBuffSize)))
            {
                if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageCopyResizeInfo->ResizeImageBuffAddr, pImageCopyResizeInfo->ResizeImageBuffSize)))
                {
                    dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->ResizeImageBuffAddr), pImageCopyResizeInfo->ResizeImageBuffSize, PAGE_CACHEABLE);
                    DstResizeDynamicSwitch = KAL_TRUE;
                }
            }
        }
        if (pImageCopyResizeInfo->IsCopyEnable)
        {
            if ((IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->CopyImageBuffAddr)) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(pImageCopyResizeInfo->CopyImageBuffSize)) &&
                (is_predef_dyna_c_region(pImageCopyResizeInfo->CopyImageBuffAddr, pImageCopyResizeInfo->CopyImageBuffSize)))
            {
                if((KAL_TRUE == INT_QueryIsNonCachedRAM(pImageCopyResizeInfo->CopyImageBuffAddr, pImageCopyResizeInfo->CopyImageBuffSize)))
                {
                    dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->CopyImageBuffAddr), pImageCopyResizeInfo->CopyImageBuffSize, PAGE_CACHEABLE);
                    DstCopyDynamicSwitch = KAL_TRUE;
                }
            }
        }
        #endif

        if (pImageCopyResizeInfo->IsResizeEnable)
        {
            ASSERT(pImageCopyResizeInfo->ResizeImageBuffSize==(YDestBuffSize+(YDestBuffSize>>1)));
            iul_csc_yuv420_to_yuv420_resize((kal_uint8 *) pImageCopyResizeInfo->SrcImageBuffAddr,
                                                (kal_uint8 *) (pImageCopyResizeInfo->SrcImageBuffAddr+YSrcBuffSize),
                                                (kal_uint8 *) (pImageCopyResizeInfo->SrcImageBuffAddr+YSrcBuffSize+(YSrcBuffSize>>2)),
                                                pImageCopyResizeInfo->SrcImageWidth,
                                                pImageCopyResizeInfo->SrcImageHeight,
                                                (kal_uint8 *) pImageCopyResizeInfo->ResizeImageBuffAddr,
                                                (kal_uint8 *) (pImageCopyResizeInfo->ResizeImageBuffAddr+YDestBuffSize),
                                                (kal_uint8 *) (pImageCopyResizeInfo->ResizeImageBuffAddr+YDestBuffSize+(YDestBuffSize>>2)),
                                                pImageCopyResizeInfo->ResizeImageWidth,
                                                pImageCopyResizeInfo->ResizeImageHeight);
        }
        if (pImageCopyResizeInfo->IsCopyEnable)
        {
            ASSERT(pImageCopyResizeInfo->CopyImageBuffSize>=pImageCopyResizeInfo->SrcImageBuffSize);
            kal_mem_cpy((void*)pImageCopyResizeInfo->CopyImageBuffAddr, (void*)pImageCopyResizeInfo->SrcImageBuffAddr, pImageCopyResizeInfo->SrcImageBuffSize);
        }
        #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
        if (SrcDynamicSwitch)
        {
            dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->SrcImageBuffAddr), pImageCopyResizeInfo->SrcImageBuffSize, PAGE_NO_CACHE);
        }
        if (DstResizeDynamicSwitch)
        {
            dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->ResizeImageBuffAddr), pImageCopyResizeInfo->ResizeImageBuffSize, PAGE_NO_CACHE);
        }
        if (DstCopyDynamicSwitch)
        {
            dynamic_switch_cacheable_region((void*)&(pImageCopyResizeInfo->CopyImageBuffAddr), pImageCopyResizeInfo->CopyImageBuffSize, PAGE_NO_CACHE);
        }
        #endif


    }
    else
    {   // not support
        ASSERT(0);
    }
}   /* ImageCopyAndResizeHandle() */
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  CalMsgHandle
 * DESCRIPTION
 *  This function is main message dispatching function of CAL task.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalMsgHandle(ilm_struct *pIlmPtr)
{
    switch (pIlmPtr->msg_id)
    {
        case MSG_ID_CAL_INFORM_MDP_FRAME_RATE_REQ:
        #if (defined(__MTK_TARGET__))
            //JaiaMergeHandle(pIlmPtr);
            if (NULL != CalDisplayStream)
            {
                P_CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT pLocalPara;
                pLocalPara = (P_CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT) pIlmPtr->local_para_ptr;

                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) pLocalPara->CurrentFrameTime);
                wfcMMCommit(CalDisplayDevice, CalDisplayContext, CalDisplayElement, WFC_COMMIT_CONTEXT);
            }
        #endif
        break;

        #if defined(EXIF_SUPPORT)
        case MSG_ID_CAL_JAIA_MERGE_REQ:
            JaiaMergeHandle(pIlmPtr);
        break;
        #endif
        case MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ:
            ImageResizeHandle(pIlmPtr);
        break;
    #ifdef __CAL_IMAGE_ROTATE_SUPPORT__
        case MSG_ID_CAL_ROTATE_IMAGE_REQ:
            ImageRotHandle(pIlmPtr);
        break;
    #endif
    #ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
        case MSG_ID_CAL_GET_PREVIEW_IMAGE_REQ:
            GetPreviewImageHandle(pIlmPtr);
        break;
    #endif
        case MSG_ID_CAL_SW_Y2R_DITHERING_REQ:
#ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
            ImageY2RDitheringHandle(pIlmPtr);
#elif defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
            idp_sw_yuv_2_rgb_dithering_start_req_hdlr(pIlmPtr);
#endif
        break;
        case MSG_ID_CAL_STARTUP_REQ:
        {
        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            IsHwJpegEncSupport=KAL_TRUE;
        #endif

            // read main sensor ID
            {
                CalSendMsgToNvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID,0,0 );
                WaitStartupCnfFlag=KAL_TRUE;
            }
        }
        break;
        case MSG_ID_NVRAM_READ_CNF:
            CalNvramReadCnfHandle(pIlmPtr);
        break;
        case MSG_ID_NVRAM_WRITE_CNF:
            CalNvramWriteCnfHandle(pIlmPtr);
        break;
    #if (defined(__POSTPROC_SUPPORT__))
        case MSG_ID_CAL_PP_START_REQ:
            CalPpStartReqHdlr(pIlmPtr);
        break;
    #endif /* defined(__POSTPROC_SUPPORT__) */
        case MSG_ID_TIMER_EXPIRY:
            CalTimeOutHandle(pIlmPtr);
        break;
    #ifdef WEBCAM_SUPPORT
        case MSG_ID_CAL_WEBCAM_FRAME_READY_REQ:
            {
                P_CAL_WEBCAM_FRAME_READY_REQ_STRUCT pWebcamFrameReadyReqStruct =  (P_CAL_WEBCAM_FRAME_READY_REQ_STRUCT)pIlmPtr->local_para_ptr;

                CalWebcamCallback(pWebcamFrameReadyReqStruct->Param);
            }
        break;
    #endif
#if defined(MT6235) || defined(MT6235B)
#if defined(__VIDEO_ARCHI_V2__)
        case MSG_ID_CAL_SW_RESIZER_START_REQ:
           idp_sw_resizer_start_req_hdlr(pIlmPtr);
        break;
#endif
#endif

#if (!defined(DRV_IDP_6252_SERIES))
       case MSG_ID_CAL_VIDEO_RENDERER_REQ:
           video_renderer_task_req_hdlr(pIlmPtr);
       break;
#endif

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
        case MSG_ID_CAL_SW_IMAGE_EFFECT_REQ:
            ImageEffectHandle(pIlmPtr);
        break;
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        case MSG_ID_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ:
            ImageCopyAndResizeHandle(pIlmPtr);
        break;
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */

        default:
        break;
    }
} /* CalMsgHandle() */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

/*****************************************************************************
 * FUNCTION
 *  CalTaskMain
 * DESCRIPTION
 *  This function is main function of CAL task.
 * PARAMETERS
 *  task_entry_ptr      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalTaskMain(task_entry_struct *pTaskEntry)
{
    ilm_struct CurrentIlm;
    kal_uint32 CalTaskIndex;

    kal_get_my_task_index(&CalTaskIndex);

    stack_init_timer(&CalTaskStackTimer, "CAL Timer", MOD_CAL );

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[CalTaskIndex].task_ext_qid, &CurrentIlm);
        stack_set_active_module_id(CalTaskIndex, CurrentIlm.dest_mod_id);

        CalMsgHandle(&CurrentIlm);

        free_ilm(&CurrentIlm);
    }
} /* CalTaskMain() */

/*****************************************************************************
 * FUNCTION
 *  CalTaskInit
 * DESCRIPTION
 *  This function is used to init CAL task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalTaskInit(task_indx_type task_indx)
{
#ifdef ISP_SUPPORT
    nvram_ltable_register(logical_data_item_table_camera);
#endif
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalTaskReset
 * DESCRIPTION
 *  This function is used to reset CAL task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalTaskReset(task_indx_type task_indx)
{
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalTaskCreate
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalHandlerInfo =
    {
        CalTaskMain,    /* task entry function */
        CalTaskInit,    /* task initialization function */
        NULL,           /* task configuration function */
        CalTaskReset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalHandlerInfo;

    return KAL_TRUE;
}
