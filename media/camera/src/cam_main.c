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

/*******************************************************************************
 * Filename:
 * ---------
 *   cam_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of camera module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_context.h"
#include "cam_main.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
    
#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif

#ifdef __MED_CAM_MOD__

#if defined(__MM_DCM_SUPPORT__)
#include "dcmgr.h" 
#endif

cam_context_struct *cam_context_p = &(med_context.cam_context);

/*==== FUNCTIONS ===========*/
extern void aud_send_startup_cnf(kal_uint8 result);

/*****************************************************************************
 * FUNCTION
 *  cam_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of camera module.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
}


/*****************************************************************************
 * FUNCTION
 *  cam_power_up_req_hdlr
 * DESCRIPTION
 *  This function is to handle power up request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_nvram_end_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    aud_send_startup_cnf(MED_RES_OK);
    med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;    

#if defined(__MM_DCM_SUPPORT__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  cam_main
 * DESCRIPTION
 *  This function is main message dispatching function of camera module.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)        
        case MSG_ID_MEDIA_CAM_PAUSE_STITCH_REQ:
            cam_pause_stitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_RESUME_STITCH_REQ:
            cam_resume_stitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_START_STITCH_REQ:
            cam_start_stitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_STITCH_REQ:
            cam_stop_stitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PANORAMA_RESET_3A_REQ:
            cam_reset_panorama_3a_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_PANORAMA_STITCH_MEM_REQ:
            cam_set_stitch_mem_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PANORAMA_ENCODE_REQ:
            cam_encode_panorama_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_GET_AUTOCAP_RESULT_REQ:
            cam_get_autocap_result_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
        case MSG_ID_CAL_STARTUP_CNF:
            cam_nvram_end_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_POWER_UP_REQ:
            cam_power_up_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_POWER_DOWN_REQ:
            cam_power_down_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PREVIEW_REQ:
            cam_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_PREVIEW_REQ:
            cam_stop_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_REQ:
            cam_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_CAPTURE_REQ:
            cam_capture_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_ENCODE_IMG_REQ:
            cam_encode_capture_image_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_PARAM_REQ:
            cam_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_FLASH_REQ:
            cam_set_flash_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_CAP_RESOLUTION_REQ:
            cam_set_cap_resolution_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_CAM_SAVE_REQ:
            cam_save_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PAUSE_PREVIEW_PP_REQ:
            cam_pause_preview_postproc_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_CAM_RESUME_PREVIEW_PP_REQ:
            cam_resume_preview_postproc_req_hdlr(ilm_ptr);
            break;
    #if defined(__MED_CAM_FD_SUPPORT__)            
        case MSG_ID_MEDIA_CAM_SET_FD_ID_REQ:
            cam_set_fd_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_UNSET_FD_ID_REQ:
            cam_unset_fd_id_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_CAM_GET_FD_RESULT_REQ:
            cam_get_fd_result_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_CAM_FD_SUPPORT__ */            
        case MSG_ID_MEDIA_CAM_SET_CAMERA_ID_REQ:
            cam_set_camera_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SENSOR_QUERY_CAPBILITY_REQ:
            cam_sensor_query_capability_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SENSOR_QUERY_ZOOM_REQ:
            cam_sensor_query_zoom_info_req_hdlr(ilm_ptr);
            break;
    #ifdef __MED_CAM_GET_BUFFER_CONTENT_SUPPORT__         
        case MSG_ID_MEDIA_CAM_GET_BUFFER_CONTENT_REQ:
            cam_get_buffer_content_req_hdlr(ilm_ptr);
            break;
    #endif          
    #ifdef __MED_CAM_GET_PREDICT_IMGSIZE_SUPPORT__         
        case MSG_ID_MEDIA_CAM_GET_PREDICTED_IMAGE_SIZE_REQ:
            cam_get_predicted_image_size_req_hdlr(ilm_ptr);
            break;
    #endif        
    #if defined(__MED_CAM_HDR_SUPPORT__)            
        case MSG_ID_MEDIA_CAM_STOP_HDR_REQ:
            cam_hdr_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SAVE_HDR_IMG_REQ:
            cam_hdr_save_images_req_hdlr(ilm_ptr);
            break;
    #endif          
    #ifdef __MED_CAM_PROFILING_SUPPORT__            
        case MSG_ID_MEDIA_CAM_PROFILING_SET_ACTIVE_REQ:
            cam_profiling_set_active_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PROFILING_SET_BUFFER_REQ:
            cam_profiling_set_buffer_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PROFILING_LOG_REQ:
            cam_profiling_log_req_hdlr(ilm_ptr);
            break;        
        case MSG_ID_MEDIA_CAM_PROFILING_GET_APPEND_REQ:
            cam_profiling_get_append_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_CAM_PROFILING_SUPPORT__ */         
    #if defined (ISP_SUPPORT)
        case MSG_ID_MEDIA_CAM_GET_FOCUS_ZONE_REQ:
            cam_get_focus_zone_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_EVENT_IND:
            cam_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_START_FAST_ZOOM_REQ:
            cam_start_fast_zoom_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_FAST_ZOOM_REQ:
            cam_stop_fast_zoom_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_GET_ZOOM_STEP_FACTOR_REQ:
            cam_get_zoom_step_factor_req_hdlr(ilm_ptr);
            break;
    #endif /* defined (ISP_SUPPORT) */ 
    #if defined (__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
        case MSG_ID_MEDIA_CAM_START_MAV_STITCH_REQ:
            cam_start_mav_stitch_req_hdlr(ilm_ptr);
            break;
    #endif /* defined (__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__) */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_init
 * DESCRIPTION
 *  This function is used to init camera module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool cam_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->state = CAM_IDLE;
    cam_context_p->capture_buffer_p = 0;
    cam_context_p->cam_event = kal_create_event_group("cam_events");

    cam_context_p->pano_state = CAM_PANO_IDLE;
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    cam_context_p->stitch_seq_no = 0;
    cam_context_p->is_stitch_done = KAL_FALSE;
#endif
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    cam_context_p->mav_seq_num = 0;
#endif
    cam_context_p->extmem_start_address = 0;
    return KAL_TRUE;
}

#endif /* __MED_CAM_MOD__ */
#endif /* MED_NOT_PRESENT */

