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
 *   cam_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_context.h"
#include "cam_main.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
    
#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_CAM_MOD__

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMMED_ROCODE", rodata = "DYNAMIC_CODE_CAMMED_ROCODE"
#endif

static kal_int32 cam_result;

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  cam_set_result
 * DESCRIPTION
 *  This function is to set return result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_RESULT_TRACE(result, cam_context_p->state, cam_context_p->seq_num) cam_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_cam_id
 * DESCRIPTION
 *  This function is to detect camera sensor.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  detect          [IN]        
 * RETURNS
 *  result          [OUT]
 *****************************************************************************/
kal_int32 media_cam_set_cam_id(module_type src_mod_id, void *cam_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_set_camera_id_req(src_mod_id, cam_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_sensor_query_capability
 * DESCRIPTION
 *  This function is to query camera sensor capability.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  query_p         [IN]        
 * RETURNS
 *  result          [OUT]
 *****************************************************************************/
kal_int32 media_cam_sensor_query_capability(module_type src_mod_id, void *query_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_sensor_query_capability_req(src_mod_id, query_p);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_sensor_query_zoom_info
 * DESCRIPTION
 *  This function is to query camera zoom information.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  query_p         [IN]        
 * RETURNS
 *  result          [OUT]
 *****************************************************************************/
kal_int32 media_cam_sensor_query_zoom_info(module_type src_mod_id, void *query_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_sensor_query_zoom_req(src_mod_id, query_p);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_power_up
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_power_up(module_type src_mod_id, void *power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_power_up_req(src_mod_id, power_on);
    CAM_WAIT_EVENT(CAM_EVT_POWER_UP);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_power_down
 * DESCRIPTION
 *  This function is to power down camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_power_down(module_type src_mod_id, kal_int16 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_power_down_req(src_mod_id, delay_time);
    CAM_WAIT_EVENT(CAM_EVT_POWER_DOWN);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_preview
 * DESCRIPTION
 *  This function is to start camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_preview(module_type src_mod_id, void *preview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_preview_req(src_mod_id, preview);
    CAM_WAIT_EVENT(CAM_EVT_PREVIEW);
    return cam_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_cam_stop_preview
 * DESCRIPTION
 *  This function is to stop camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_stop_preview(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_stop_preview_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_stop
 * DESCRIPTION
 *  This function is to stop camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_stop_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_capture
 * DESCRIPTION
 *  This function is to capture the image.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  capture         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_capture(module_type src_mod_id, void *capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_capture_req(src_mod_id, capture);
    CAM_WAIT_EVENT(CAM_EVT_CAPTURE);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_capture
 * DESCRIPTION
 *  This function is to capture the image.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  capture         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_encode_capture_image(module_type src_mod_id, kal_uint8 **buf_pp, kal_uint32 *buf_size_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_encode_capture_image_req(src_mod_id, buf_pp, buf_size_p);
    CAM_WAIT_EVENT(CAM_EVT_ENCODE_JPEG);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_param
 * DESCRIPTION
 *  This function is to set the parameter of camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_param(module_type src_mod_id, kal_uint16 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_param_req(src_mod_id, param_id, value);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_flash
 * DESCRIPTION
 *  This function is to set the flash for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  flash_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_flash(module_type src_mod_id, kal_int16 flash_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_flash_req(src_mod_id, flash_mode);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_cap_resolution
 * DESCRIPTION
 *  This function is to set cap size
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  img_resolution      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_cap_resolution(module_type src_mod_id, media_cam_cap_resolution_struct *img_resolution)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_cap_resolution_req(src_mod_id, (void*)img_resolution);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_af
 * DESCRIPTION
 *  This function is to set the parameter of AF.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_af(module_type src_mod_id, kal_uint16 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_param_req(src_mod_id, param_id, value);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_start_fast_zoom
 * DESCRIPTION
 *  This function is to start fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  zoom_in         [IN]        
 *  zoom_limit      [IN]        
 *  zoom_step       [IN]        
 *  zoom_speed      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_start_fast_zoom(
        module_type src_mod_id,
        kal_bool zoom_in,
        kal_uint8 zoom_limit,
        kal_uint8 zoom_step,
        kal_uint8 zoom_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_start_fast_zoom_req(src_mod_id, zoom_in, zoom_limit, zoom_step, zoom_speed);
    CAM_WAIT_EVENT(CAM_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_stop_fast_zoom
 * DESCRIPTION
 *  This function is to stop fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_stop_fast_zoom(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_stop_fast_zoom_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_zoom_step_factor
 * DESCRIPTION
 *  This function is to get the fast zoom factor for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  factor          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_zoom_step_factor(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_zoom_step_factor_req(src_mod_id, factor, step);
    CAM_WAIT_EVENT(CAM_EVT_GET_FAST_ZOOM_FACTOR);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_flash_setting
 * DESCRIPTION
 *  This function is to set ledlight on/off
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  flag            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_flash_setting(module_type src_mod_id, kal_bool flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_max_zoom_factor
 * DESCRIPTION
 *  This function is to get the max zoom factor
 * PARAMETERS
 *  target_width        [IN]        
 *  target_height       [IN]        
 * RETURNS
 *  kal_uint8 max_zoom_factor
 *****************************************************************************/
kal_uint8 media_cam_get_max_zoom_factor(kal_uint16 target_width, kal_uint16 target_height)
{
#ifdef ISP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#endif /* ISP_SUPPORT */
    return 0; 
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_focus_zone
 * DESCRIPTION
 *  This function is to get the focus zone.
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_focus_zone(module_type src_mod_id, media_cam_af_zone_para_struct *zone_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_focus_zone_req(src_mod_id, zone_p);
    CAM_WAIT_EVENT(CAM_EVT_GET_FOCUS_ZONE);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_save_image
 * DESCRIPTION
 *  This function is to ask MED CAM to save image to file
 *  src_mod_id          [IN]        
 * PARAMETERS
 * RETURNS
 *  kal_uint8 max_zoom_factor
 *****************************************************************************/
kal_uint8 media_cam_save_image(module_type src_mod_id, kal_wchar* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_save_req(src_mod_id, filepath);
    CAM_WAIT_EVENT(CAM_EVT_SAVE);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_buffer_content
 * DESCRIPTION
 *  This function is to ask MED CAM to get buffer_content
 *  src_mod_id          [IN]        
 * PARAMETERS
 * RETURNS
 *  kal_uint8 max_zoom_factor
 *****************************************************************************/
kal_uint8 media_cam_get_buffer_content(module_type src_mod_id, void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_get_buffer_content_req(src_mod_id, data);
    CAM_WAIT_EVENT(CAM_EVT_GET_BUFF_CONTENT);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_predicted_image_size
 * DESCRIPTION
 *  This function is to ask MED CAM to save image to file
 *  src_mod_id          [IN]        
 * PARAMETERS
 * RETURNS
 *  kal_uint8 max_zoom_factor
 *****************************************************************************/
kal_uint8 media_cam_get_predicted_image_size(module_type src_mod_id, void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_get_predicted_image_size_req(src_mod_id, data);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}

#if defined(__MED_CAM_FD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  media_cam_get_focus_zone
 * DESCRIPTION
 *  This function is to get the focus zone.
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_fd_result(module_type src_mod_id, media_cam_fd_result_struct *fd_result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_fd_result_req(src_mod_id, fd_result_p);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_fd_id
 * DESCRIPTION
 *  This function is to set fd id as focus zone
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 media_cam_set_fd_id (module_type src_mod_id, kal_uint32 fd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_set_fd_id_req(src_mod_id, fd_id);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_unset_fd_id 
 * DESCRIPTION
 *  This function is to reset fd id as focus zone.
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 media_cam_unset_fd_id (module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_unset_fd_id_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
    return cam_result;
}
#endif /* defined(__MED_CAM_FD_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  media_cam_pause_preview_postproc 
 * DESCRIPTION
 *  This function is to pause fd process (to release T-DCM)
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 media_cam_pause_preview_postproc(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_pause_preview_postproc_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_resume_preview_postproc 
 * DESCRIPTION
 *  This function is to resume fd process 
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 media_cam_resume_preview_postproc(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_resume_preview_postproc_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
    return cam_result;
}


#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  media_cam_stitch_panorama
 * DESCRIPTION
 *  This function is to stitch panorama images
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  panorama_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_stitch_panorama(module_type src_mod_id, media_cam_start_stitch_req_struct *panorama_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_start_stitch_req(src_mod_id, panorama_data);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_cam_abort_panorama
 * DESCRIPTION
 *  This function is to abort panorama process
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_abort_panorama(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_abort_stitch_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_abort_panorama
 * DESCRIPTION
 *  This function is to pause panorama process
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_pause_panorama(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_pause_stitch_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_resume_panorama
 * DESCRIPTION
 *  This function is to resume panorama process
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_resume_panorama(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_resume_stitch_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_panorama_reset_3a
 * DESCRIPTION
 *  This function is to reset 3a calculate of MED Camera module
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_reset_panorama_3a(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_reset_panorama_3a_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_panorama_stitch_memory
 * DESCRIPTION
 *  This function is to set panorama stitch memory
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_set_panorama_stitch_memory(module_type src_mod_id, media_cam_set_stitch_mem_req_struct *stitch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_stitch_memory_req(src_mod_id, stitch_data);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_cam_encode_panorama
 * DESCRIPTION
 *  This function is to encode panorama image
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_encode_panorama(module_type src_mod_id, media_cam_panorama_encode_req_struct *encode_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_encode_panorama_req(src_mod_id, encode_data);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_autocap_result
 * DESCRIPTION
 *  This function is to get autocap tracking result.
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_autocap_result(module_type src_mod_id, media_cam_autocap_result_struct *autocap_result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_autocap_result_req(src_mod_id, autocap_result_p);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
}
#endif /*__MED_CAM_PANORAMA_VIEW_SUPPORT__*/

#ifdef __MED_CAM_HDR_SUPPORT__
kal_int32 media_cam_stop_hdr(module_type src_mod_id, kal_wchar* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_stop_hdr_req(src_mod_id, filepath);
    CAM_WAIT_EVENT(CAM_EVT_SAVE);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_save_hdr_images
 * DESCRIPTION
 *  This function is to ask MED CAM to save image to file
 *  src_mod_id          [IN]        
 * PARAMETERS
 * RETURNS
 *  result
 *****************************************************************************/
kal_int32 media_cam_save_hdr_images(module_type src_mod_id, kal_wchar* captured_filepath, kal_wchar* hdr_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_save_hdr_images_req(src_mod_id, captured_filepath, hdr_filepath);
    CAM_WAIT_EVENT(CAM_EVT_HDR_SAVE);
    return cam_result;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  media_cam_profiling_set_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_active       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_profiling_set_active(module_type src_mod_id, kal_bool is_active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_profiling_set_active_req(src_mod_id, is_active);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);   
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_profiling_set_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_active       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_profiling_set_buffer(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_profiling_set_buffer_req(src_mod_id, buf_address, buf_size);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);  
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_profiling_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_active       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_profiling_log(module_type src_mod_id, kal_uint32 log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_profiling_log_req(src_mod_id, log_id);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);  
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_profiling_get_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_active       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_profiling_get_append(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_profiling_get_append_req(src_mod_id, buf_address);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);  
}

#if defined (__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  media_cam_stitch_mav
 * DESCRIPTION
 *  This function is to stitch mav images
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  panorama_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_stitch_mav(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_start_mav_stitch_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_BLOCK);
    return cam_result;
}
#endif /* defined (__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__) */

/*****************************************************************************
 * FUNCTION
 *  media_cam_set_extra_qvi_buffer
 * DESCRIPTION
 *  This function is to set extra qvi buffer, the buffer is shared from APP
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  buf_address       [IN]         
 *  buf_size       [IN]
 * RETURNS
 *  void
 *****************************************************************************/

void media_cam_set_extra_qvi_buffer(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_param_req(src_mod_id, CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_ADDR, buf_address);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);

    cam_send_set_param_req(src_mod_id, CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_SIZE, buf_size);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);	
}

#if defined (__MED_CAM_CAMERA_GYRO_SUPPORT__)
#include "SensorSrvGport.h"
#include "pp_comm_def.h"
#include "cal_mem_def.h"
#include "pp_mem_def.h"
#include "cal_api.h"
#include "mm_comm_def.h"
#include "mavcap_comm_def.h"

#define CAMERA_GYRO_HANDLE  1
#define GSENSOR_BOUND_VALUE 100

kal_bool cam_gyro_srv_init = KAL_FALSE;
kal_uint32 cam_gyro_srv_ext_mem_addr = 0;
kal_uint32 cam_gyro_srv_ext_mem_size = 0;
SRV_SENSOR_EVENT_HDLR cam_gyro_callback = NULL;
//srv_sensor_motion_tilt_struct cam_gyro_motion_data;
void *cam_gyro_user_data = NULL;
kal_bool cam_gyro_is_msg_send = KAL_FALSE;

static void cam_gyro_result_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_gyro_result_ind_struct *msg_p = (media_cam_gyro_result_ind_struct*) msg_ptr;
    srv_sensor_motion_tilt_struct result_ind = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_gyro_srv_init&&cam_gyro_is_msg_send)
    {  
        result_ind.acc.x = msg_p->acc_x;
        result_ind.acc.y = msg_p->acc_y;

        if (cam_gyro_callback)
            cam_gyro_callback(SRV_SENSOR_MOTION_TILT, &result_ind, cam_gyro_user_data);

        cam_gyro_is_msg_send = KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cam_gyro_cal_callback
 * DESCRIPTION
 *  This function is callback registered to CAL 
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  panorama_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MM_ERROR_CODE_ENUM cam_gyro_cal_callback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    // call cam_gyro_callback
    if (NULL!=cam_gyro_callback)
    {
        P_MAVCAP_RESULT_STRUCT motion_result = (P_MAVCAP_RESULT_STRUCT)pCallbackPara;

        /* initial acc as scaling value */ 
        kal_int32 acc_x, acc_y;
        acc_x = acc_y = 1;//GSENSOR_BOUND_VALUE/motion_result->OverlapRatio; /* OverlapRatio is bound value */;
        
        #ifdef DUAL_CAMERA_SUPPORT  /* need to mirror */
            #if defined(SUB_SENSOR_ROTATE_0)
            {
                acc_x *= motion_result->MV_X;
                acc_y *= -motion_result->MV_Y;
            }
            #elif defined(SUB_SENSOR_ROTATE_90)
            {
                acc_x *= motion_result->MV_Y;
                acc_y *= -motion_result->MV_X;
            }
            #elif defined(SUB_SENSOR_ROTATE_180)
            {
                acc_x *= -motion_result->MV_X;
                acc_y *= motion_result->MV_Y;
            }
            #elif defined(SUB_SENSOR_ROTATE_270)
            {
                acc_x *= -motion_result->MV_Y;
                acc_y *= motion_result->MV_X;
            }
            #endif
        #else
            #if defined(SENSOR_ON_BODY)
                #if defined(SENSOR_ROTATE_0)
                {
                    acc_x *= -motion_result->MV_X;
                    acc_y *= -motion_result->MV_Y;
                }
                #elif defined(SENSOR_ROTATE_90)
                {
                    acc_x *= -motion_result->MV_Y;
                    acc_y *= -motion_result->MV_X;
                }
                #elif defined(SENSOR_ROTATE_180)
                {
                    acc_x *= motion_result->MV_X;
                    acc_y *= motion_result->MV_Y;
                }
                #elif defined(SENSOR_ROTATE_270)
                {
                    acc_x *= motion_result->MV_Y;
                    acc_y *= motion_result->MV_X;
                }
                #endif
            #else   /* need to mirror */
                #if defined(SENSOR_ROTATE_0)
                {
                    acc_x *= motion_result->MV_X;
                    acc_y *= -motion_result->MV_Y;
                }
                #elif defined(SENSOR_ROTATE_90)
                {
                    acc_x *= motion_result->MV_Y;
                    acc_y *= -motion_result->MV_X;
                }
                #elif defined(SENSOR_ROTATE_180)
                {
                    acc_x *= -motion_result->MV_X;
                    acc_y *= motion_result->MV_Y;
                }
                #elif defined(SENSOR_ROTATE_270)
                {
                    acc_x *= -motion_result->MV_Y;
                    acc_y *= motion_result->MV_X;
                }
                #endif
            #endif
        #endif

        // transform to angle (-180*10~180*10)
        acc_x = ((acc_x * 50 * 10)+MAVCAP_IMAGE_YS/2)/MAVCAP_IMAGE_YS;
        acc_y = ((acc_y * 50 * 10)+MAVCAP_IMAGE_XS/2)/MAVCAP_IMAGE_XS;

        if (KAL_FALSE == cam_gyro_is_msg_send)
        {
            cam_send_camera_gyro_result_ind(acc_x, acc_y);
            cam_gyro_is_msg_send = KAL_TRUE;
        }
    }
    return MM_ERROR_NONE;
}

SRV_SENSOR_HANDLE srv_sensor_start_listen(srv_sensor_type_enum type, void *option, 
                                                 SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data)
{
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_SCENARIO_CTRL_STRUCT CalPreviewScenarioPara;
    CAL_CAMERA_PREVIEW_STRUCT CalPreviewPara;
    CAL_LCD_STRUCT CalLcdPara;
    CAL_ISP_PREVIEW_STRUCT CalIspPreviewPara;
    CAL_POSTPROC_STRUCT CalPostProcPara;
    CAL_MDP_PREVIEW_STRUCT CalMdpPreviewPara;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    kal_uint32 ExtMemAddr;

    if (cam_gyro_srv_init)
    {
        return SRV_SENSOR_MOTION_SUCCEED;
    }

    if (SRV_SENSOR_MOTION_TILT != type)
    {
        return SRV_SENSOR_MOTION_NOT_SUPPORT_GESTURE;
    }

    ASSERT(event_hdlr != NULL);

    cam_gyro_is_msg_send = KAL_FALSE;

    ExtMemAddr = cam_gyro_srv_ext_mem_addr;
    
    cam_gyro_callback = event_hdlr;

    cam_gyro_user_data = user_data;

    /* register handler */
    SetProtocolEventHandler(cam_gyro_result_hdlr, MSG_ID_MEDIA_CAM_CAMERA_GYRO_RESULT_IND);


    /* power on camera */
    // Select main or sub sensor (sub in default if avaliable)
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    #ifdef DUAL_CAMERA_SUPPORT
    CalInPara.FeatureSetValue = (kal_uint32)CAL_CAMERA_SOURCE_SUB;
    #else
    CalInPara.FeatureSetValue = (kal_uint32)CAL_CAMERA_SOURCE_MAIN;
    #endif
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        
    if (MM_ERROR_NONE != CalOpen(cam_gyro_cal_callback))
    {
        return SRV_SENSOR_MOTION_NO_SLOT;
    }

    /* enter camera preview */   
    CalMdpPreviewPara.LcdUpdateEnable = KAL_FALSE;        
    CalMdpPreviewPara.DisplayImageWidth = MAVCAP_IMAGE_XS;
    CalMdpPreviewPara.DisplayImageHeight = MAVCAP_IMAGE_YS;
    CalMdpPreviewPara.FrameBuffAddr1 = ExtMemAddr;
    CalMdpPreviewPara.FrameBuffAddr2 = ExtMemAddr+MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*3/2;
    ExtMemAddr += MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*3;
    CalMdpPreviewPara.FrameBuffAddr3 = 0;
    CalMdpPreviewPara.CameraAppFrameBuffAddr = 0;
    CalMdpPreviewPara.FrameBuffSize = MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*3/2;
    CalMdpPreviewPara.OverlayEnable = KAL_FALSE;
    CalMdpPreviewPara.ImageRotAngle = MM_IMAGE_ROTATE_0;
    CalMdpPreviewPara.StillImageRotAngle = MM_IMAGE_ROTATE_0;
    CalMdpPreviewPara.ImageDataFormat = MM_IMAGE_FORMAT_YUV420;
    
    CalIspPreviewPara.ZoomStep = 10;
    CalIspPreviewPara.ContrastLevel = CAM_CONTRAST_HIGH;
    CalIspPreviewPara.SaturationLevel = CAM_SATURATION_MEDIUM;
    CalIspPreviewPara.SharpnessLevel = CAM_SHARPNESS_HIGH;
    CalIspPreviewPara.WbMode = CAM_WB_AUTO;
    CalIspPreviewPara.EvValue = CAM_EV_ZERO;
    CalIspPreviewPara.BandingFreq = CAM_BANDING_60HZ;
    CalIspPreviewPara.ImageEffect = CAM_EFFECT_ENC_NORMAL;
    CalIspPreviewPara.SceneMode = CAM_AUTO_DSC;
    CalIspPreviewPara.AeMeteringMode = CAM_AE_METER_AUTO;
    CalIspPreviewPara.FlashMode = CAM_FLASH_OFF;
    CalIspPreviewPara.AfOperationMode = CAM_AF_OFF;
    CalIspPreviewPara.AfRange = CAM_AF_RANGE_AUTO;

    CalLcdPara.WfcElementHandle = 0;
    CalLcdPara.WfcContextHandle = 0;
    CalLcdPara.WfcDeviceHandle = 0;

    CalPostProcPara.PostProcMode = PP_MODE_MAVCAP_GYRO;

    CalPreviewPara.ExtmemStartAddress = ExtMemAddr;
    CalPreviewPara.ExtmemSize = PP_PREVIEW_CAMERA_GYRO_EXT_WORKING_MEM_SIZE;
    CalPreviewPara.pLcdPara = &CalLcdPara;
    CalPreviewPara.pMdpPara = &CalMdpPreviewPara;
    CalPreviewPara.pIspPara = &CalIspPreviewPara;
    CalPreviewPara.pPostProcPara = &CalPostProcPara;

    CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_GYRO_PREVIEW;
    CalPreviewScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalPreviewScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_PREVIEW_STRUCT);
    CalPreviewScenarioPara.pScenarioCtrlPara = &CalPreviewPara;

    if (MM_ERROR_NONE != CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalPreviewScenarioPara, NULL, 0, NULL))
    {
        return SRV_SENSOR_MOTION_NO_SLOT;
    }

    cam_gyro_srv_init = KAL_TRUE;
    
    return CAMERA_GYRO_HANDLE;
}

SRV_SENSOR_RESULT srv_sensor_stop_listen(SRV_SENSOR_HANDLE handle)
{
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;

    if (CAMERA_GYRO_HANDLE != handle)
    {
        return SRV_SENSOR_MOTION_INVALID_PARAM;
    }
    
    if (!cam_gyro_srv_init)
    {
        return SRV_SENSOR_MOTION_SUCCEED;
    }
    
    /* exit camera preview */
    CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_GYRO_PREVIEW;
    CalScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    CalScenarioPara.ScenarioCtrlParaLen=0;
    CalScenarioPara.pScenarioCtrlPara=NULL;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);

    /* power down camera */
    CalClose();

    cam_gyro_srv_ext_mem_addr = 0;
    cam_gyro_srv_ext_mem_size = 0;
    cam_gyro_srv_init = KAL_FALSE;
    cam_gyro_user_data = NULL;
    
    return SRV_SENSOR_MOTION_SUCCEED;
}

SRV_SENSOR_RESULT srv_sensor_set_ext_mem(kal_uint32 ext_mem_addr, kal_uint32 ext_mem_size)
{
    cam_gyro_srv_ext_mem_addr = ext_mem_addr;
    cam_gyro_srv_ext_mem_size = ext_mem_size;
    ASSERT(CAL_PP_CAMERA_GYRO_SCENARIO_EXT_MEMORY_SIZE<=ext_mem_size);

    return SRV_SENSOR_MOTION_SUCCEED;
}
#endif /* __MED_CAM_CAMERA_GYRO_SUPPORT__ */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif /* __MED_CAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

