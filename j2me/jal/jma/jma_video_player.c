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
 *   jma_video_player.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines native JMA video player APIs
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**
 * @(#)jma_video_player.c  1.00 05/12/07
 *
 * Copyright (c) 2005 MediaTek Inc. All rights reserved.
 */

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "MMI_include.h"
#include "mmi_frm_gprot.h"

#include "jma_interface.h"
#include "jma_internal.h"
#include "jam_internal.h"
#include "jui_interface.h"  /* for virtual keypad */

#include "FileMgrGProt.h"
#include "app_mem.h"

#include "cbm_api.h"
#include "app2cbm_struct.h"

#include "mmi_features_mediaplayer.h"
#include "mmi_features_video.h"
#include "app_str.h"

/*****************************************************************************
 * Global Definition and Declaration
*****************************************************************************/
#ifdef SUPPORT_MMAPI
video_player_struct video_player[JVM_NUM]; 
video_ctrl_struct video_ctrl_info[JVM_NUM];
extern kal_bool g_jam_is_jvm_in_busy;
kal_uint32 jma_total_frames = 0;
GDI_HANDLE preview_layer_handle;
kal_uint16 *preview_buf_ptr = NULL;
kal_uint16 g_active_app_id = 0;
kal_int32 preview_buf_size = 0;
kal_uint32 preview_layer_flag;
kal_uint32 blt_layer_flag;
#define DEFAULT_WIDTH (128)
#define DEFAULT_HEIGHT (96)
kal_bool g_jma_is_bearer_deactivated[JVM_NUM];
#endif /* SUPPORT_MMAPI */

#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)

#define JMA_VIDEO_ELAPSE_TICKS  (10)
#define JMA_VIDEO_SLEEP_TICKS    (1)

kal_bool g_jma_is_stream_video = KAL_FALSE;
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
/*****************************************************************************
 * private functions
*****************************************************************************/
static void jma_video_player_get_display_full_screen(kal_int32 vm_id, kal_int32 *x, kal_int32 *y, kal_int32 *width, kal_int32 *height);
static void jma_video_player_redraw_video_region(kal_int32 vm_id);

void jma_video_player_play_finish_hdlr(MDI_RESULT result, void *user_data);
void jma_video_player_seek_result_hdlr(MDI_RESULT result, void *user_data);

#ifdef __MMI_VIDEO_STREAM__
static kal_bool jma_stream_player_refresh(kal_int32 vm_id, kal_int32 java_player);
void jma_stream_player_buffering_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data);
void jma_stream_player_connect_result_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data);
void jma_stream_player_play_finish_hdlr(MDI_RESULT result, void *user_data);
#endif

#ifdef __MMI_VIDEO_PDL__ 
void jma_video_player_cache_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data);
#endif
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
/*****************************************************************************
 * routine implementations
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  jma_video_player_finalize
 * DESCRIPTION
 *  Finalize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PDL__
    kal_int32 result = -1;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_PDL__
    if (video_player[vm_id].progressive_dl)
    {
        /* Close cache file */
        if (video_player[vm_id].cache_handle != NULL)
        {
            result = FS_Close(video_player[vm_id].cache_handle);
            video_player[vm_id].cache_handle = NULL;
        }
        /* Delete cache file */
        result = FS_Delete(video_player[vm_id].filename);
        if (result != FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        }
    }
#endif  

    /* Release buffer */
    if (video_player[vm_id].buffer != NULL)
    {
        jvm_free(video_player[vm_id].buffer);
        video_player[vm_id].buffer = NULL;
    }
    
    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);

        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }

    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
      
    jma_video_player_reset_parameter(vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_suspend_hdlr
 * DESCRIPTION
 *  This function handles before suspend
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int - result
 *****************************************************************************/
kal_int32 jma_video_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SUSPEND_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {   
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    /* Avoid interaction */
    j2me_lcd_mutex_lock();

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        ms = mdi_video_ply_stop();
		if(0 == ms)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D,156);
		}
        mdi_video_ply_get_cur_play_time(&video_player[vm_id].current_time);
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)
    {
        mdi_video_ply_stop_non_block_seek();

        /* Change state to the original state */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, video_player[vm_id].prev_state);
        video_player[vm_id].state = video_player[vm_id].prev_state;
    }
#ifdef __MMI_VIDEO_PDL__    
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);
    }
#endif    

    if (!video_player[vm_id].progressive_dl)
    {
        if (video_player[vm_id].buffer == NULL)
        {
            ms = mdi_video_ply_close_clip_file();
			if(0 == ms)
		    {
			     kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 456);
		    }
        }
        else
        {
            ms = mdi_video_ply_close_clip_buffer();
			if(0 == ms)
		    {
			     kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 654);
		    }
        }
    }    
#ifdef __MMI_VIDEO_PDL__
    else
    {
        mdi_video_progressive_close_file();            
    }
#endif

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }
    /* Stop double buffer when suspend video */
    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
    
    /* Avoid interaction */
    j2me_lcd_mutex_unlock();
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_resume_hdlr
 * DESCRIPTION
 *  This function is mpeg resume handler invoked when resumeAudio executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_video_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_VDOPLY_ERR_FAILED;
    mdi_video_info_struct vdo_clip;
    kal_bool ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_RESUME_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    /* Backlight control */
    jvm_force_backlight_on(KAL_TRUE);

    /* Open */
    if (!video_player[vm_id].progressive_dl)
    {
        /* If stopp_at_time before vm suspend, don't disable_consume_count when vm resume */
    #ifdef __DRM_SUPPORT__      
        if (video_player[vm_id].state != JAVA_MEDIA_STATE_STOPPED_PAUSED)
        {
            /* DRM does not consume count */          
            mdi_video_ply_drm_disable_consume_count();        
        }
    #endif        
        mdi_video_ply_enable_aud_only_video_clip();
    #ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
    #endif
        if (video_player[vm_id].buffer == NULL)
        {
            ms = mdi_video_ply_open_clip_file(JAVA_APP_ID_MED, (S8*) video_player[vm_id].filename, &vdo_clip);
        }
        else
        {
            ms = mdi_video_ply_open_clip_buffer(JAVA_APP_ID_MED, video_player[vm_id].buffer, video_player[vm_id].buffer_length, &vdo_clip);
        }
    }
#ifdef __MMI_VIDEO_PDL__      
    else
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
    #endif
        ms = mdi_video_progressive_open_file(
                JAVA_APP_ID_MED,
                (S8*) video_player[vm_id].filename, 
                jma_video_player_cache_open_done_hdlr,
                0);
    }
#endif    

    /* Open fail */
    if (ms != MDI_RES_VDOPLY_SUCCEED)
    {
        if (video_player[vm_id].is_double_buffer)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
            jui_widget_stop_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_FALSE;
        }
        jma_video_player_reset_parameter(vm_id);

        jma_deregister_device(JAVA_MEDIA_MPEG_PLAYER_DEVICE, vm_id, java_player);
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);     
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    if (!video_player[vm_id].is_double_buffer)
    {
        /* Start double buffer when resume video */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;    
    }
    
    /* Open successfully */
    if (!video_player[vm_id].progressive_dl)
    {
        /* MED would set mute when play dummy audio for pure video */
        jam_set_aud_volume_level(jam_get_aud_volume_level());      
        
        if (video_player[vm_id].stoptime != -1)
        {
            mdi_video_ply_set_stop_time(video_player[vm_id].stoptime);
        }

        /* stop loading animation */
        gdi_image_stop_animation_all();
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);

        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            if (video_player[vm_id].need_redraw == KAL_FALSE ||
                video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
            {
                ms = mdi_video_ply_non_block_seek(
                    video_player[vm_id].current_time, jma_video_player_seek_result_hdlr, 0);                
            }
            else
            {
                jma_video_player_refine_display_info(vm_id);
                ret = jma_video_player_process_layer(vm_id);
                if (!ret)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                    JMA_CS_LEAVE(RESOUCE_FAIL);
                }
                /* Seek to suspended time and Draw the layer */
                ms = mdi_video_ply_non_block_seek_and_get_frame(
                        video_player[vm_id].current_time, preview_layer_handle, jma_video_player_seek_result_hdlr, 0);  
            }
            if (ms == MED_RES_OK ||
                ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
                ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
            {
                video_player[vm_id].prev_state = video_player[vm_id].state;
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_SEEKING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_SEEKING;   
            }
            else
            {   
                video_player[vm_id].seek_error = KAL_TRUE;
                video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
                jma_mvm_video_player_play(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
            }
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {            
            if (video_player[vm_id].need_redraw == KAL_FALSE ||
                video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
            {
                ms = mdi_video_ply_non_block_seek(
                    video_player[vm_id].current_time, jma_video_player_seek_result_hdlr, 0);                
            }
            else
            {
                jma_video_player_refine_display_info(vm_id);
                ret = jma_video_player_process_layer(vm_id);
                if (!ret)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                    JMA_CS_LEAVE(RESOUCE_FAIL);
                }
                /* Seek to suspended time and Draw the layer */
                ms = mdi_video_ply_non_block_seek_and_get_frame(
                        video_player[vm_id].current_time, preview_layer_handle, jma_video_player_seek_result_hdlr, 0);  
            }

            if (ms == MED_RES_OK ||
                ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
                ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
            {
                video_player[vm_id].prev_state = video_player[vm_id].state;
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_SEEKING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_SEEKING;   
            }
            else
            {   
                video_player[vm_id].seek_error = KAL_TRUE;
            }
        }           
    }
#ifdef __MMI_VIDEO_PDL__      
    else
    {
        /* state when Suspended: PAUSED, PLAYING, BUFFERING. Need to prepare layer for draw frame */
        if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY &&
            ((video_player[vm_id].state != JAVA_MEDIA_STATE_READY && video_player[vm_id].state != JAVA_MEDIA_STATE_OPENING) ||
            (video_player[vm_id].need_redraw && video_player[vm_id].state == JAVA_MEDIA_STATE_READY)))
        {
            jma_video_player_refine_display_info(vm_id);
            ret = jma_video_player_process_layer(vm_id);
        }   
        
        /* Change state as OPENING */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_OPENING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_OPENING;
    }
#endif 
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_close_hdlr
 * DESCRIPTION
 *  This function is mpeg close handler invoked when finalizeResoueceMgr executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_video_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CLOSE_HDLR, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    /* With resource */
    if (!is_vm_suspend_media[vm_id])
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            ms = mdi_video_ply_stop();
			if(1 == ms)
			{
			    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 111);
			}
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)
        {
            mdi_video_ply_stop_non_block_seek();
        }
    #ifdef __MMI_VIDEO_PDL__    
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
        }
    #endif    

        if (!video_player[vm_id].progressive_dl)
        {
            if (video_player[vm_id].buffer == NULL)
            {
                ms = mdi_video_ply_close_clip_file();
				if(1 == ms)
			    {
			        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 111);
			    }
            }
            else
            {
                ms = mdi_video_ply_close_clip_buffer();
				if(1 == ms)
			    {
			        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 112);
			    }
            }
        }    
    #ifdef __MMI_VIDEO_PDL__
        else
        {
            mdi_video_progressive_close_file();            
        }
    #endif
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);
    }
    
    jma_deregister_device(video_player[vm_id].device_type, vm_id, java_player);
    jma_video_player_finalize(vm_id);
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_play_finish_hdlr
 * DESCRIPTION
 *  //mmi_vodply_player_play_finish_hdlr
 *  function to be called when play finished.
 * PARAMETERS
 *  result      [IN]        >=0, means successfully finished, if result < 0 measn some error happened)
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_play_finish_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    java_mma_type_enum event_type;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_PLAY_FINISH_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        JMA_CS_LEAVE(JMA_VOID); 
    }    
    
    mdi_video_ply_get_cur_play_time(&video_player[vm_id].current_time);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);

    if (result == MDI_RES_VDOPLY_ERR_DRM_DURATION_USED)
    {
        jma_video_player_close(MMA_TYPE_MPEG, video_player[vm_id].id);       
        jvm_post_mma_event(MMA_EVENT_ERROR, video_player[vm_id].id, MMA_ERR_DRM_RIGHT_EXPIRED);
        JMA_CS_LEAVE(JMA_VOID); 
    }
    else if (result == MDI_RES_VDOPLY_REACH_STOP_TIME)
    {
        video_player[vm_id].is_play_requested = KAL_FALSE;
        /* STOPPED_PAUSED should be the same as PAUSED state. 
           The only difference is whether to call drm_disable_Consume_Count() in play() */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_STOPPED_PAUSED;

        /* Clear stop time */
        mdi_video_ply_set_stop_time((U64) -1);
        video_player[vm_id].stoptime = -1;
        ms = mdi_video_ply_seek(video_player[vm_id].current_time);
        if (ms == MED_RES_OK ||
            ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
            ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
            ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
        {
            video_player[vm_id].seek_error = KAL_FALSE;
        }
        else
        {
            video_player[vm_id].seek_error = KAL_TRUE;
        }
        event_type = MMA_EVENT_STOPPED_AT_TIME;
    }  
#ifdef __MMI_VIDEO_PDL__  /* Underflow */      
    else if (result == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
    {
        /* change as buffering state directly */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;
        jma_video_player_cache_buffering_cyclic(vm_id);
        JMA_CS_LEAVE(JMA_VOID); 
    }
#endif  
    else if (result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
             result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        /* normal error code, which do not need to handle */
        JMA_CS_LEAVE(JMA_VOID);
    }
    else
    {
        video_player[vm_id].is_play_requested = KAL_FALSE;
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;        

        video_player[vm_id].play_finish_time = video_player[vm_id].current_time;
        /* set current time as 0 for playing at next time */
        video_player[vm_id].current_time = 0;
        ms = mdi_video_ply_seek(0);
        if (ms == MED_RES_OK ||
            ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
            ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
            ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
        {
            video_player[vm_id].seek_error = KAL_FALSE;
        }
        else
        {
            video_player[vm_id].seek_error = KAL_TRUE;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        }
        
        event_type = MMA_EVENT_END_OF_MEDIA;
    }
    /* enqueue to VM event queue */
    jvm_post_mma_event(event_type, video_player[vm_id].id, (kal_int64) video_player[vm_id].play_finish_time);
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_seek_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_seek_result_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SEEK_RESULT_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }
    
    EXT_ASSERT(video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING, 0, 0, 0);

    if (result == MED_RES_OK ||
        result == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
        result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
        result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        video_player[vm_id].seek_error = KAL_FALSE;
        
        /* 1. Video player is not at READY state and not pure-audio
           2. Blt for seek_and_get_frame() */
        if (preview_layer_handle != NULL && 
            video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY &&
            video_player[vm_id].state != JAVA_MEDIA_STATE_PLAYING)
        {
            jma_video_player_redraw_video_region(vm_id);
        }
    }
    else
    {
        video_player[vm_id].seek_error = KAL_TRUE;
    }
    
    mdi_video_ply_get_cur_play_time(&video_player[vm_id].current_time);
    
    /* for PAUSED or STOPPPED_PAUSED or READY state */
    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, video_player[vm_id].prev_state);
    video_player[vm_id].state = video_player[vm_id].prev_state;
    
    /* For BUFFERING, PLAYING state */
    if (video_player[vm_id].is_play_requested == KAL_TRUE)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        jma_mvm_video_player_play(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_file_open
 * DESCRIPTION
 *  This function opens video file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_video_player_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 length, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_VDOPLY_ERR_FAILED;
    mdi_video_info_struct vdo_clip;
    kal_int8 audio_state = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    /* find free player */
    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

//#ifdef __MMI_BACKGROUND_CALL__ 
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    audio_state = jma_mvm_audio_player_state(vm_id);
    if (jma_audio_recorder_is_active(vm_id) || JMA_AUDIO_ACTIVE == audio_state)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

#ifdef __JMA_PREEMPT_PLAYER__ /*this will not happen if VM instance is 1*/
    if (JMA_AUDIO_NON_ACTIVE == audio_state)
    {
        jma_video_notify_suspend_audio_player(vm_id);
    }
#endif
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {    
        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);

        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();

        /* Enable pure-audio */
        mdi_video_ply_enable_aud_only_video_clip();
        if (filename == NULL)
        {
            /* Copy Data from KNI Layer */
            video_player[vm_id].buffer = jvm_malloc(length);
            if (video_player[vm_id].buffer == NULL)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                
                JMA_CS_LEAVE(KAL_FALSE);
            }
            memcpy(video_player[vm_id].buffer, data, length);
            video_player[vm_id].buffer_length = length;
        #ifdef __COSMOS_MMI_PACKAGE__
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
        #endif
            ms = mdi_video_ply_open_clip_buffer(JAVA_APP_ID_MED, video_player[vm_id].buffer, video_player[vm_id].buffer_length, &vdo_clip);
        }
        else
        {
            /* Copy FileName from KNI Layer */
            mmi_ucs2ncpy((S8*) video_player[vm_id].filename, filename, J2ME_PATH_BUFFER_SIZE - 1);
        #ifdef __COSMOS_MMI_PACKAGE__
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
        #endif
            ms = mdi_video_ply_open_clip_file(JAVA_APP_ID_MED, (S8*) video_player[vm_id].filename, &vdo_clip);
        }

        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
            jui_widget_start_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_TRUE;
        }
        else if (ms == MDI_RES_VDOPLY_ERR_DRM_PROHIBITED)
        {
            /* Release buffer */
            if (video_player[vm_id].buffer != NULL)
            {
                jvm_free(video_player[vm_id].buffer);
                video_player[vm_id].buffer = NULL;
            }  
            
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            JMA_CS_LEAVE(KAL_FALSE);
        }
        else
        {
            /* Release buffer */
            if (video_player[vm_id].buffer != NULL)
            {
                jvm_free(video_player[vm_id].buffer);
                video_player[vm_id].buffer = NULL;
            } 
            
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            JMA_CS_LEAVE(KAL_FALSE);
        }

        /* MED would set mute when play dummy audio for pure video */
        jam_set_aud_volume_level(jam_get_aud_volume_level()); 

        if (vdo_clip.width == 0 && vdo_clip.height == 0)
        {
            mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_INSIDE);
            video_player[vm_id].video_width = DEFAULT_WIDTH;
            video_player[vm_id].video_height = DEFAULT_HEIGHT;
        }
        else
        {
            video_player[vm_id].video_width = vdo_clip.width;
            video_player[vm_id].video_height = vdo_clip.height;
        }
        video_player[vm_id].track = vdo_clip.track;
        video_player[vm_id].duration = vdo_clip.total_time_duration;

        mmi_ucs2ncpy(video_player[vm_id].title_desc, vdo_clip.title_desc, MDI_VIDEO_MAX_CONTENT_INFO_LEN);
        mmi_ucs2ncpy(video_player[vm_id].author_desc, vdo_clip.author_desc, MDI_VIDEO_MAX_CONTENT_INFO_LEN);
        mmi_ucs2ncpy(video_player[vm_id].date_desc, vdo_clip.date_desc, MDI_VIDEO_MAX_CONTENT_INFO_LEN);
        mmi_ucs2ncpy(video_player[vm_id].copyright_desc, vdo_clip.copyright_desc, MDI_VIDEO_MAX_CONTENT_INFO_LEN);
        
        EXT_ASSERT(video_player[vm_id].track != MDI_VIDEO_TRACK_NONE, 0, 0, 0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, (kal_uint32)video_player[vm_id].duration, (int) video_player[vm_id].track);
             
        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_MPEG_PLAYER_DEVICE,
            vm_id,
            java_player, 
            &jma_video_player_suspend_hdlr, 
            &jma_video_player_resume_hdlr, 
            &jma_video_player_close_hdlr);

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        video_player[vm_id].id = java_player;
        video_player[vm_id].stoptime = -1;
        video_player[vm_id].volume = DEFAULT_VIDEO_VOLUME;
        video_player[vm_id].current_time = 0;
        video_player[vm_id].progressive_dl = KAL_FALSE;
        video_player[vm_id].is_play_requested = KAL_FALSE;
        video_player[vm_id].device_type = JAVA_MEDIA_MPEG_PLAYER_DEVICE;

        /* Need to seek before calling play at the first time */        
        ms = mdi_video_ply_seek(video_player[vm_id].current_time);
        if (ms == MED_RES_OK ||
            ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
            ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
            ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
        {
            video_player[vm_id].seek_error = KAL_FALSE;
        }
        else
        {
            video_player[vm_id].seek_error = KAL_TRUE;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        }
        video_player[vm_id].scr_mem_max_size = JMA_VDOPLY_LAYER_BUFFER_SIZE;
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_pause
 * DESCRIPTION
 *  This function submit VideoPause request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_pause(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PDL__
    MDI_RESULT ms;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_PAUSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    video_player[vm_id].is_play_requested = KAL_FALSE;

//#ifdef __MMI_BACKGROUND_CALL__    
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING
    #ifdef __MMI_VIDEO_PDL__  
         || video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING        
    #endif /* __MMI_VIDEO_PDL__ */
           )
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
        JMA_CS_LEAVE(JMA_VOID);
    }   
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* If vm_id is not at FG state, then switch its state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING
    #ifdef __MMI_VIDEO_PDL__  
         || video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING        
    #endif /* __MMI_VIDEO_PDL__ */
           )
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_ply_stop();
        mdi_video_ply_get_cur_play_time(&video_player[vm_id].current_time);

        if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
        {
            /* Don't need to seek. Driver would leave the last frame onto preview layer */
            /* Draw the last frame onto screen to avoid discontinuity if MIDlet draws other things */
            jma_video_player_redraw_video_region(vm_id);
        }

        /* DRM does not consume count */
    #ifdef __DRM_SUPPORT__    
        mdi_video_ply_drm_disable_consume_count();
    #endif    
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
       
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)   
    {
        /* Modify prev_state for seek_result_hdlr */
        if (video_player[vm_id].prev_state == JAVA_MEDIA_STATE_PLAYING ||
            video_player[vm_id].prev_state == JAVA_MEDIA_STATE_BUFFERING)
        {
            video_player[vm_id].prev_state = JAVA_MEDIA_STATE_PAUSED;
        }       
    }
#ifdef __MMI_VIDEO_PDL__  
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);

        /* Clear layer in order to clean progress bar */
        if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
        {
            EXT_ASSERT(preview_layer_handle != NULL, 0, 0, 0);
            ms = mdi_video_ply_seek_and_get_frame(
                    video_player[vm_id].current_time, 
                    preview_layer_handle);
            if (ms == MED_RES_OK ||
                ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
                ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
            {
                video_player[vm_id].seek_error = KAL_FALSE;
            }
            else
            {
                video_player[vm_id].seek_error = KAL_TRUE;
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            }
            jma_video_player_redraw_video_region(vm_id);
        }
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
    }
#endif 

    JMA_CS_LEAVE(JMA_VOID);
}



/*****************************************************************************
 * FUNCTION
 *  jma_video_player_play_internal
 * DESCRIPTION
 *  This function plays video file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool jma_video_player_play_internal(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_VDOPLY_SUCCEED;
    kal_bool ret = KAL_FALSE;
    U16 rotate = MDI_VIDEO_LCD_ROTATE_0;
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the analog volume level to avoid no audio play out when replay */
    jam_set_aud_volume_level(jam_get_aud_volume_level()); 
    /* Set volume before playing */
    mdi_video_ply_set_audio_level(video_player[vm_id].volume);
    /* Set SW decode module's sleep time */
    mdi_video_ply_set_sleep_time(JMA_VIDEO_ELAPSE_TICKS, JMA_VIDEO_SLEEP_TICKS);

    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);

        if (ret == KAL_FALSE)
        {
            return ret;
        }

        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
        /* Not IDP rotate*/
    #ifndef __MDI_VIDEO_HW_ROTATOR_BY_IDP__
        if (video_ctrl_info[vm_id].fullscreen_rotate == KAL_TRUE)
        {
            rotate = MDI_VIDEO_LCD_ROTATE_270;
        }
    #endif /* !(__MDI_VIDEO_HW_ROTATOR_BY_IDP__) */
        
        mdi_video_ply_enable_partial_display();
        ms = mdi_video_ply_play(
                preview_layer_handle,
                blt_layer_flag,     /* blt layer */
                preview_layer_flag,   /* play_layer_flag */
                1,                    /* repeat */
                visible,        /* visual update */
                TRUE,
                MDI_DEVICE_SPEAKER2,
                rotate,     /* rotate */
                video_player[vm_id].play_speed,    /* VDOPLY_FEATURE_SPEED_1 */
                jma_video_player_play_finish_hdlr,
                0);
    }
    else
    {
        ms = mdi_video_ply_play(
                NULL,
                0,          /* blt layer */
                0,          /* play_layer_flag */
                1,          /* repeat */
                KAL_FALSE,  /* visual update */
                TRUE,
                MDI_DEVICE_SPEAKER2,
                MDI_VIDEO_LCD_ROTATE_0,     /* rotate */
                video_player[vm_id].play_speed,    /* VDOPLY_FEATURE_SPEED_1 */
                jma_video_player_play_finish_hdlr,
                0);
    }
    /* the two trace_error results do not affect playing */
    if (ms == MDI_RES_VDOPLY_SUCCEED ||
        ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
        ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;

        /* Connect BT when playing successfully */
    #if defined(__MMI_BT_AUDIO_VIA_SCO__)
        jma_media_player_connect_bt_via_sco(NULL);
    #endif
        video_player[vm_id].need_redraw = KAL_TRUE;
        ret = KAL_TRUE;
    }
    else if (ms == MDI_RES_VDOPLY_REACH_STOP_TIME ||
             ms == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
    {
        jma_video_player_play_finish_hdlr(ms,NULL);
        ret = KAL_TRUE;
    }
    else if (ms == MDI_RES_VDOPLY_ERR_DRM_PROHIBITED)
    {
        /* If video stay in READY state, in resume handler, disable_consume_count()
           will make the player can play again */
        jma_mvm_video_player_close(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        ret = KAL_FALSE;
    }
    else
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        ret = KAL_FALSE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_play
 * DESCRIPTION
 *  This function plays video file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_video_player_play(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* When state == OPENING, play() should return KAL_TRUE */
    kal_bool ret = KAL_TRUE; 
#ifdef __MMI_VIDEO_PDL__    
    kal_int32 dl_percentage;
    MDI_RESULT ms;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_PLAY, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    video_player[vm_id].is_play_requested = KAL_TRUE;

    /* Reset play finish time for the play of this time */
    video_player[vm_id].play_finish_time = 0;  

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
    {
        /* If seek error, video driver will assert if call play */
        if (video_player[vm_id].seek_error == KAL_TRUE)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        /* Video Player */
        if (!video_player[vm_id].progressive_dl)
        {
            ret = jma_video_player_play_internal(vm_id);
        }        
        /* Progressive Player */
    #ifdef __MMI_VIDEO_PDL__    
        else 
        {
            mdi_video_progressive_get_buf_percentage(&dl_percentage);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, dl_percentage);

            /* play directly: do not draw 100% progress bar */
            if (dl_percentage == 100)
            {
                ret = jma_video_player_play_internal(vm_id);
            }
            else
            {  
                /* Prepare layer with content to draw progress bar */
                if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY && 
                    preview_layer_handle == NULL)
                {
                    jma_video_player_refine_display_info(vm_id);
                    ret = jma_video_player_process_layer(vm_id);
                    ms = mdi_video_ply_seek_and_get_frame(
                                video_player[vm_id].current_time,
                                preview_layer_handle);
                    if (ms == MED_RES_OK ||
                        ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
                        ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                        ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
                    {
                        video_player[vm_id].seek_error = KAL_FALSE;
                    }
                    else
                    {
                        video_player[vm_id].seek_error = KAL_TRUE;
                        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
                    }
                    jma_video_player_redraw_video_region(vm_id);
                }
                /* change as buffering state directly */
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;
                ret = jma_video_player_cache_buffering_cyclic(vm_id);
            }
        } 
    #endif    
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)   
    {
        /* Modify prev_state for seek_result_hdlr */
        if (video_player[vm_id].prev_state == JAVA_MEDIA_STATE_READY ||
            video_player[vm_id].prev_state == JAVA_MEDIA_STATE_PAUSED ||
            video_player[vm_id].prev_state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
        {
            video_player[vm_id].prev_state = JAVA_MEDIA_STATE_PLAYING;
        }       
    }
    
    JMA_CS_LEAVE(ret);  
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_file_close
 * DESCRIPTION
 *  This function closes video file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
#ifdef __MMI_VIDEO_PDL__     
    kal_int32 result;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CLOSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);  
    }

    jma_deregister_device(JAVA_MEDIA_MPEG_PLAYER_DEVICE, vm_id, java_player);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        jma_video_player_finalize(vm_id);
        JMA_CS_LEAVE(JMA_VOID);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        jma_video_player_finalize(vm_id);
        JMA_CS_LEAVE(JMA_VOID);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        ms = mdi_video_ply_stop();
		if(1 == ms)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 113);
		}
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)
    {
        mdi_video_ply_stop_non_block_seek();
    }
#ifdef __MMI_VIDEO_PDL__    
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);
    }
#endif    

    if (!video_player[vm_id].progressive_dl)
    {
        if (video_player[vm_id].buffer == NULL)
        {
            ms = mdi_video_ply_close_clip_file();
        }
        else
        {
            ms = mdi_video_ply_close_clip_buffer();
            /* Release buffer */
            jvm_free(video_player[vm_id].buffer);
            video_player[vm_id].buffer = NULL;
        }
    }    
#ifdef __MMI_VIDEO_PDL__
    else
    {
        mdi_video_progressive_close_file();

        /* Close cache file */
        if (video_player[vm_id].cache_handle != NULL)
        {
            result = FS_Close(video_player[vm_id].cache_handle);
            video_player[vm_id].cache_handle = NULL;
        }
        /* Delete cache file */
        result = FS_Delete(video_player[vm_id].filename);
        if (result != FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        }
    }
#endif

    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);

        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }

    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
      
    jma_video_player_reset_parameter(vm_id);

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif
    
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_video_player_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]         
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PDL__
    kal_int32 result = -1;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CLEAR_JMADATA, vm_id, mma_type, java_player);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;
    }
    jma_deregister_device(JAVA_MEDIA_MPEG_PLAYER_DEVICE, vm_id, java_player);

#ifdef __MMI_VIDEO_PDL__
    if (video_player[vm_id].progressive_dl)
    {
        /* Close cache file */
        if (video_player[vm_id].cache_handle != NULL)
        {
            result = FS_Close(video_player[vm_id].cache_handle);
            video_player[vm_id].cache_handle = NULL;
        }
        /* Delete cache file */
        result = FS_Delete(video_player[vm_id].filename);
        if (result != FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        }
    }
#endif  

    /* Release buffer */
    if (video_player[vm_id].buffer != NULL)
    {
        jvm_free(video_player[vm_id].buffer);
        video_player[vm_id].buffer = NULL;
    }
    jma_video_player_reset_parameter(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_media_time
 * DESCRIPTION
 *  This function submit VideoSetStartTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  now             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jma_mvm_video_player_set_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_uint64 now)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms;
#ifdef __MMI_VIDEO_PDL__     
    kal_uint64 max_time;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state, now);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        /* seek time should be bound in duration */
        if (video_player[vm_id].duration != -1 && now > video_player[vm_id].duration)
        {
            now = video_player[vm_id].duration;            
        }
        video_player[vm_id].current_time = now; 
        
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/
    /* If vm_id is not at FG state, then just remember its time setting */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        /* seek time should be bound in duration */
        if (video_player[vm_id].duration != -1 && now > video_player[vm_id].duration)
        {
            now = video_player[vm_id].duration;            
        }
        video_player[vm_id].current_time = now; 
        
        JMA_CS_LEAVE(video_player[vm_id].current_time); 
    }
    
#ifdef __MMI_VIDEO_PDL__
    /* Restrict seek time */
    if (video_player[vm_id].progressive_dl)
    {    
        /* keep the seek time and restrict the time in open_done_hdlr() */
        /* Still have problem. seek successfully and delay restricting ? */
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
        {
            video_player[vm_id].current_time = now; 
            JMA_CS_LEAVE(now);
        }
        
        mdi_video_progressive_get_max_play_time(&max_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)max_time);
        if (now > max_time)
        {
            now = max_time;
        }
    }
#endif     

    /* BUFFERING state is for pdl player */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        jma_mvm_video_player_pause(vm_id, mma_type, java_player);

        /* For seek_result_hdlr to resume to BUFFERING or PLAYING state */
        video_player[vm_id].is_play_requested = KAL_TRUE;
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)   
    {
        /* Stop the original seek at first */
        mdi_video_ply_stop_non_block_seek();
        
        /* Change state to the original state */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, video_player[vm_id].prev_state);
        video_player[vm_id].state = video_player[vm_id].prev_state;
    }

    /* seek time should be bound in duration */
    if (video_player[vm_id].duration != -1 && now > video_player[vm_id].duration)
    {
        now = video_player[vm_id].duration;            
    }    

    /* state is READY or pure-audio */
    if (preview_layer_handle == NULL || video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
    {
        ms = (kal_int32)(mdi_video_ply_non_block_seek(now, jma_video_player_seek_result_hdlr, 0));
    }
    else
    {
        ms = (kal_int32)(mdi_video_ply_non_block_seek_and_get_frame(
                now, preview_layer_handle, jma_video_player_seek_result_hdlr, 0));   
    }

    if (ms == 0 ||
        ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
        ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
        ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {   
        /* Change current time */
        video_player[vm_id].current_time = now;
        
        if (video_player[vm_id].is_play_requested)
        {
            video_player[vm_id].prev_state = JAVA_MEDIA_STATE_PLAYING;
        }
        else
        {
            video_player[vm_id].prev_state = video_player[vm_id].state;
        }        
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_SEEKING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_SEEKING;  
    }
    else
    {   
        video_player[vm_id].seek_error = KAL_TRUE;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);

        if (video_player[vm_id].is_play_requested)
        {
            jma_mvm_video_player_play(vm_id, mma_type, java_player);
        }
    }
    
    JMA_CS_LEAVE(now);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_media_time
 * DESCRIPTION
 *  This function submit VideoGetMediaTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_uint64 jma_mvm_video_player_get_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 current_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_ply_get_cur_play_time(&current_time);
        /* MED does not seek precisely. To Avoid current time goes back */
        if (current_time >= video_player[vm_id].current_time)
        {
            video_player[vm_id].current_time = current_time;
        }
        else
        {
            current_time = video_player[vm_id].current_time;
        }
        
    }    
    else if (video_player[vm_id].play_finish_time != 0) /* for play finish */
    {
        current_time = video_player[vm_id].play_finish_time;
    }
    else 
    {
        current_time = video_player[vm_id].current_time;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)current_time);
    JMA_CS_LEAVE(current_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_duration
 * DESCRIPTION
 *  This function submit VideoGetDuration request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  count           [IN]        
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_int64 jma_mvm_video_player_get_duration(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 duration = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_DURATION, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, 0);
    
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    duration = video_player[vm_id].duration;
    if (duration == 0)
    {
        duration = -1;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)duration);
    JMA_CS_LEAVE(duration);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_volume
 * DESCRIPTION
 *  This function submit VideoSetVolume request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  vol             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_set_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_VOLUME, vm_id, java_player, video_player[vm_id].state, vol);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    video_player[vm_id].volume = vol;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_ply_set_audio_level((kal_uint16)vol);
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_stop_time
 * DESCRIPTION
 *  This function submit VideoSetStopTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_uint64 jma_mvm_video_player_set_stop_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_uint64 stime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_STOP_TIME, vm_id, java_player, video_player[vm_id].state, stime);
    JMA_CS_ENTER(vm_id, 0);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    video_player[vm_id].stoptime = stime;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(stime);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(stime);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_ply_set_stop_time(stime);
    JMA_CS_LEAVE(stime); 
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_rate
 * DESCRIPTION
 *  This function sets play speed, unit: millirate
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_int32 jma_mvm_video_player_set_rate(kal_int32 vm_id, kal_int32 java_player, kal_int32 rate)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_VIDEO__)
    kal_int32 play_speed[9] = {
        MEDPLY_FEATURE_VIDEO_SPEED_0,
        MEDPLY_FEATURE_VIDEO_SPEED_1,
        MEDPLY_FEATURE_VIDEO_SPEED_2,
        MEDPLY_FEATURE_VIDEO_SPEED_3,
        MEDPLY_FEATURE_VIDEO_SPEED_4,
        MEDPLY_FEATURE_VIDEO_SPEED_5,
        MEDPLY_FEATURE_VIDEO_SPEED_6,
        MEDPLY_FEATURE_VIDEO_SPEED_7,
        MEDPLY_FEATURE_VIDEO_SPEED_8};
    kal_int32 play_speed_count = MEDPLY_FEATURE_VIDEO_SPEED_COUNT;
#elif defined(__MMI_VIDEO_PLAYER__)
    kal_int32 play_speed[9] = {
        VDOPLY_FEATURE_SPEED_0,
        VDOPLY_FEATURE_SPEED_1,
        VDOPLY_FEATURE_SPEED_2,
        VDOPLY_FEATURE_SPEED_3,
        VDOPLY_FEATURE_SPEED_4,
        VDOPLY_FEATURE_SPEED_5,
        VDOPLY_FEATURE_SPEED_6,
        VDOPLY_FEATURE_SPEED_7,
        VDOPLY_FEATURE_SPEED_8};
    kal_int32 play_speed_count = VDOPLY_FEATURE_SPEED_COUNT;    
#else
    kal_int32 play_speed[9] = {100};
    kal_int32 play_speed_count = 1; 
#endif
    
    kal_int32 i, choose_speed = 0, diff, min_diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_RATE, vm_id, java_player, rate);
    JMA_CS_ENTER(vm_id, 0);
    /* Check if java_player id is valid */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    /* Only mp4, 3gp support RateControl */
    if (video_player[vm_id].device_type != JAVA_MEDIA_MPEG_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(0);
    }
    
    /* Change unit */
    rate /= 1000;
    
    /* Find the closest play speed */
    min_diff = 0x7fffffff;
    for (i=0; i < play_speed_count; i++)
    {
        diff = play_speed[i] - rate;
        diff = (diff > 0) ? diff : -diff;
        if (diff < min_diff)
        {
            min_diff = diff;
            choose_speed = play_speed[i];
        }
    }    

    /* Update parameter */
    video_player[vm_id].play_speed = choose_speed;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(1000 * choose_speed);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(1000 * choose_speed);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        /* Stop video player first */
        jma_mvm_video_player_pause(vm_id, MMA_TYPE_MPEG, java_player);
        /* Play again to update play speed */        
        jma_mvm_video_player_play(vm_id, MMA_TYPE_MPEG, java_player);
    }  

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 1000 * choose_speed);
    JMA_CS_LEAVE(1000 * choose_speed);
}



/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_rate
 * DESCRIPTION
 *  This function gets play speed, unit: millirate 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_rate(kal_int32 vm_id, kal_int32 java_player)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_RATE, vm_id, java_player);

    /* Check if java_player id is valid */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 1000 * video_player[vm_id].play_speed);
    return (1000 * video_player[vm_id].play_speed);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_max_rate
 * DESCRIPTION
 *  This function gets max play speed, unit: millirate 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_max_rate(kal_int32 vm_id, kal_int32 java_player)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_VIDEO__)
    kal_int32 play_speed[9] = {
        MEDPLY_FEATURE_VIDEO_SPEED_0,
        MEDPLY_FEATURE_VIDEO_SPEED_1,
        MEDPLY_FEATURE_VIDEO_SPEED_2,
        MEDPLY_FEATURE_VIDEO_SPEED_3,
        MEDPLY_FEATURE_VIDEO_SPEED_4,
        MEDPLY_FEATURE_VIDEO_SPEED_5,
        MEDPLY_FEATURE_VIDEO_SPEED_6,
        MEDPLY_FEATURE_VIDEO_SPEED_7,
        MEDPLY_FEATURE_VIDEO_SPEED_8};
    kal_int32 play_speed_count = MEDPLY_FEATURE_VIDEO_SPEED_COUNT;
#elif defined(__MMI_VIDEO_PLAYER__)
    kal_int32 play_speed[9] = {
        VDOPLY_FEATURE_SPEED_0,
        VDOPLY_FEATURE_SPEED_1,
        VDOPLY_FEATURE_SPEED_2,
        VDOPLY_FEATURE_SPEED_3,
        VDOPLY_FEATURE_SPEED_4,
        VDOPLY_FEATURE_SPEED_5,
        VDOPLY_FEATURE_SPEED_6,
        VDOPLY_FEATURE_SPEED_7,
        VDOPLY_FEATURE_SPEED_8};
    kal_int32 play_speed_count = VDOPLY_FEATURE_SPEED_COUNT;    
#else
    kal_int32 play_speed[9] = {100};
    kal_int32 play_speed_count = 1; 
#endif
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_MAX_RATE, vm_id, java_player);

    /* Check if java_player id is valid */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 1000 * play_speed[play_speed_count - 1]);
    return (1000 * play_speed[play_speed_count - 1]);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_min_rate
 * DESCRIPTION
 *  This function gets min play speed, unit: millirate 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_min_rate(kal_int32 vm_id, kal_int32 java_player)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_VIDEO__)
    kal_int32 min_speed = MEDPLY_FEATURE_VIDEO_SPEED_0;
#elif defined(__MMI_VIDEO_PLAYER__)
    kal_int32 min_speed = VDOPLY_FEATURE_SPEED_0;
#else
    kal_int32 min_speed = 100;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_MIN_RATE, vm_id, java_player);

    /* Check if java_player id is valid */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 1000 * min_speed);
    return (1000 * min_speed);
}


#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_VIDEO_STREAM__) 
/*****************************************************************************
 * FUNCTION
 *  jma_video_player_draw_progress_bar
 * DESCRIPTION
 *  This function is to draw progress bar 
 * PARAMETERS
 *  percentage          [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_draw_progress_bar(kal_int32 vm_id, kal_int32 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 layer_width, layer_height;
    kal_int32 bar_x, bar_y, bar_width, bar_height, current_progress;
    //kal_int32 vert_bar_x, vert_bar_y, vert_bar_width, vert_bar_height, vert_current_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(preview_layer_handle != NULL, 0, 0, 0);

    gdi_layer_push_and_set_active(preview_layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_pop_and_restore_active();
    
    bar_width = layer_width * 2 / 3;
    bar_height = (bar_width / 10);
    bar_height = (bar_height > 5) ? bar_height : 5;
    EXT_ASSERT(bar_width != 0 && bar_height != 0, 0, 0, 0);
    bar_x = (layer_width - bar_width) / 2;
    bar_y = (layer_height - bar_height) / 2;
    current_progress = bar_width * percentage / 100;
    
    gdi_layer_push_and_set_active(preview_layer_handle); 
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    gdi_layer_pop_and_restore_active();
    /* do not draw progressive bar on yuv layer which is displaying video frame */
    //return;
#endif

    gdi_draw_solid_rect(bar_x, bar_y, bar_x + bar_width - 1, bar_y + bar_height - 1, GDI_COLOR_BLACK);

    gdi_draw_solid_rect(bar_x, bar_y, bar_x + current_progress - 1, bar_y + bar_height - 1, GDI_COLOR_WHITE);

    gdi_draw_rect(bar_x, bar_y, bar_x + bar_width - 1, bar_y + bar_height - 1, GDI_COLOR_WHITE);
    gdi_draw_rect(bar_x + 1, bar_y + 1, bar_x + bar_width - 2, bar_y + bar_height - 2, GDI_COLOR_BLACK);
    
    gdi_layer_pop_and_restore_active();
    jma_video_player_redraw_video_region(vm_id);
}
#endif

#ifdef __MMI_VIDEO_PDL__ 
/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_open_done_hdlr
 * DESCRIPTION
 *  This function is progressive player open done handler
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
void jma_video_player_cache_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    kal_uint64 max_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_OPEN_DONE_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    /* Error happens */
    if (result < 0)
    {
        jma_mvm_video_player_close(vm_id, 0, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    /* MED would set mute when play dummy audio for pure video */
    jam_set_aud_volume_level(jam_get_aud_volume_level()); 
     
    /* stop loading animation */
    gdi_image_stop_animation_all();
    mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
    mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);
    
    video_player[vm_id].video_width = vdo_clip->width;
    video_player[vm_id].video_height = vdo_clip->height;
    video_player[vm_id].duration = vdo_clip->total_time_duration;
    video_player[vm_id].track = vdo_clip->track;
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, (kal_uint32)vdo_clip->total_time_duration, vdo_clip->track);

    mmi_ucs2ncpy(video_player[vm_id].title_desc, vdo_clip->title_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy(video_player[vm_id].author_desc, vdo_clip->author_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy(video_player[vm_id].date_desc, vdo_clip->date_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy(video_player[vm_id].copyright_desc, vdo_clip->copyright_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
   
        
    /* Avoid user seeks over max_time when video is at opening state */
    mdi_video_progressive_get_max_play_time(&max_time);
    if (video_player[vm_id].current_time > max_time)   
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, (kal_uint32)video_player[vm_id].current_time, (kal_uint32)max_time);
        video_player[vm_id].current_time = max_time;
    }
     
    /* Video player is at READY state or pure-audio */
    if (preview_layer_handle == NULL || video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;  
        /* Need to seek before calling play: cannot reset current if resume from MMI interrupt */
        ms = mdi_video_ply_non_block_seek(
            video_player[vm_id].current_time, jma_video_player_seek_result_hdlr, 0);
    }
    else
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED; 
        
        /* Seek to suspended time and Draw the layer */
        ms = mdi_video_ply_non_block_seek_and_get_frame(
                video_player[vm_id].current_time, preview_layer_handle, jma_video_player_seek_result_hdlr, 0);  
    }

    if (ms == MED_RES_OK ||
        ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
        ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
        ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        video_player[vm_id].prev_state = video_player[vm_id].state;
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_SEEKING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_SEEKING;   
    }
    else
    {   
        video_player[vm_id].seek_error = KAL_TRUE;
        if (video_player[vm_id].is_play_requested)
        {
            jma_mvm_video_player_play(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
        }
    }
    
    /* For resume from MMI interrupt */
    if (video_player[vm_id].stoptime != -1)
    {
        mdi_video_ply_set_stop_time(video_player[vm_id].stoptime);
    }
       
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_buffering_cyclic
 * DESCRIPTION
 *  This function is buffering cyclic handler 
 * PARAMETERS
 *  result          [IN] 
 *  video_clip      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_video_player_cache_buffering_cyclic(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dl_percentage;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    kal_bool ret = KAL_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_BUFFERING_CYCLIC, vm_id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    mdi_video_progressive_get_buf_percentage(&dl_percentage);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, dl_percentage);

    /* Draw progress bar */
    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jma_video_player_draw_progress_bar(vm_id, dl_percentage);
    }
    /* Buffer is enough, play directly */
    if (dl_percentage == 100)
    {
        ret = jma_video_player_play_internal(vm_id);
        if (ret == KAL_FALSE)
        {
            jma_mvm_video_player_close(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
        }
    }
    else
    {
        /* Start a timer to ask download percentage */
        EXT_ASSERT(video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING, 0, 0, 0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        /* To distinguish which vm time out, use different timer idx for different vm */
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_PDL_PLAYER + vm_id, ticks); 
    }
    JMA_CS_LEAVE(ret);
}

#endif /* __MMI_VIDEO_PDL__ */


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_is_pdl_format
 * DESCRIPTION
 *  This function checks progressive player's format
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
kal_bool jma_mvm_video_player_is_pdl_format(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count)
{
#ifdef __MMI_VIDEO_PDL__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_pdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_IS_PDL_FORMAT, vm_id, java_player);

    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_progressive_is_pdl_format((U8*) data, count, &is_pdl);
    JMA_CS_LEAVE(is_pdl);

#else  /* __MMI_VIDEO_PDL__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_PDL__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_is_opened
 * DESCRIPTION
 *  This function querys if progressive player is opened
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
kal_int32 jma_mvm_video_player_cache_is_opened(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_PDL__      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_IS_OPENED, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return -1;
    } 
    
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
        {
            return -1;
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING ||
                video_player[vm_id].state == JAVA_MEDIA_STATE_READY) 
        {
            return 1;
        }
        return -1;
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
        {
            return -1;
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_READY) 
        {
            return 1;
        }
        return -1;
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        return -1; /* Error */ 
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
    {
        return 0; /* Not yet done. */
    }
    else if (video_player[vm_id].state >= JAVA_MEDIA_STATE_READY)
    {
        return 1; /* OK */
    }
    return -1;
    
#else  /* __MMI_VIDEO_PDL__ */ 
    return -1;
#endif /* __MMI_VIDEO_PDL__ */     
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_open
 * DESCRIPTION
 *  This function opens progressive player
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
kal_bool jma_mvm_video_player_cache_open(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count)
{
#ifdef __MMI_VIDEO_PDL__     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 written;
    kal_uint32 size;
    MDI_RESULT ms = MDI_RES_VDOPLY_ERR_FAILED;
    U8 buf[(5 + 1) * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    /* find free player */
    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (jma_audio_recorder_is_active(vm_id) || jma_audio_player_is_really_active())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {      
        jma_video_player_get_hidden_folder(video_player[vm_id].filename);
        jma_video_player_encode_file_path_with_num(video_player[vm_id].filename, vm_id, (kal_char *)buf, 10);
        memset(buf, 0x00, sizeof(buf));
        jma_video_player_encode_file_path_with_num(video_player[vm_id].filename, java_player, (kal_char *)buf, 10);
        
        mmi_ucs2cat((PS8) video_player[vm_id].filename, (PS8) L"cache.3gp");
        
        /* Open cache file and write the first data package */
        video_player[vm_id].cache_handle = FS_Open(video_player[vm_id].filename, FS_READ_WRITE | FS_OPEN_SHARED | FS_CREATE_ALWAYS);
        if (video_player[vm_id].cache_handle <= 0)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_player[vm_id].cache_handle);

            JMA_CS_LEAVE(KAL_FALSE);
        }
        result = FS_Write(video_player[vm_id].cache_handle, (char*) data, count, &written);

        if (result != FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            /* Close cache file */
            result = FS_Close(video_player[vm_id].cache_handle);
            video_player[vm_id].cache_handle = NULL;
            /* Delete cache file */
            result = FS_Delete(video_player[vm_id].filename);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            }

            JMA_CS_LEAVE(KAL_FALSE);
        }
        result = FS_GetFileSize(video_player[vm_id].cache_handle, &size);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, count, written);

        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
    
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
    #ifdef __COSMOS_MMI_PACKAGE__
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_QVGA);
    #endif
        ms = mdi_video_progressive_open_file(
                JAVA_APP_ID_MED,
                (S8*) video_player[vm_id].filename, 
                jma_video_player_cache_open_done_hdlr,
                0);
        
        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
            jui_widget_start_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_TRUE;
        }
        else
        {
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            /* Close cache file */
            result = FS_Close(video_player[vm_id].cache_handle);
            video_player[vm_id].cache_handle = NULL;
            /* Delete cache file */
            result = FS_Delete(video_player[vm_id].filename);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            }

            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_MPEG_PLAYER_DEVICE,
            vm_id,
            java_player, 
            &jma_video_player_suspend_hdlr, 
            &jma_video_player_resume_hdlr, 
            &jma_video_player_close_hdlr);

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_OPENING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_OPENING;
        
        video_player[vm_id].id = java_player;
        video_player[vm_id].volume = DEFAULT_VIDEO_VOLUME;
        video_player[vm_id].current_time = 0;
        video_player[vm_id].device_type = JAVA_MEDIA_MPEG_PLAYER_DEVICE;
        video_player[vm_id].stoptime = -1;
        video_player[vm_id].progressive_dl = KAL_TRUE;
        
        video_ctrl_info[vm_id].set_display_location = KAL_FALSE;
        video_ctrl_info[vm_id].set_display_size = KAL_FALSE;
        video_ctrl_info[vm_id].is_visible = KAL_TRUE;
        video_ctrl_info[vm_id].is_full_screen = KAL_FALSE;
        video_ctrl_info[vm_id].offset_x = 0;
        video_ctrl_info[vm_id].offset_y = 0;
        video_ctrl_info[vm_id].width = 0;
        video_ctrl_info[vm_id].height = 0;
        video_player[vm_id].scr_mem_max_size = JMA_VDOPLY_LAYER_BUFFER_SIZE;
    }

    JMA_CS_LEAVE(KAL_TRUE);
#else  /* __MMI_VIDEO_PDL__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_PDL__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_write
 * DESCRIPTION
 *  This function writes data to cache file
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
kal_bool jma_mvm_video_player_cache_write(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count)
{
#ifdef __MMI_VIDEO_PDL__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 written;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_WRITE, vm_id, java_player, video_player[vm_id].state);
    /* find free player */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return KAL_FALSE;
    }
  
    if (video_player[vm_id].cache_handle == NULL)
    {
        return KAL_FALSE; 
    }
    
    result = FS_Write(video_player[vm_id].cache_handle, (char*) data, count, &written);
    if (result != FS_NO_ERROR)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        return KAL_FALSE;
    }
    result = FS_GetFileSize(video_player[vm_id].cache_handle, &size);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, count, size);
    return KAL_TRUE;
#else  /* __MMI_VIDEO_PDL__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_PDL__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_cache_close
 * DESCRIPTION
 *  This function closes cache file
 * PARAMETERS
 *         
 * RETURNS
 *  kal_bool - result
 *****************************************************************************/
kal_bool jma_mvm_video_player_cache_close(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_PDL__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CACHE_CLOSE, vm_id, java_player, video_player[vm_id].state);

    /* find free player */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return KAL_FALSE; 
    }

    if (video_player[vm_id].cache_handle == NULL)
    {
        return KAL_FALSE;    
    }
    
    result = FS_GetFileSize(video_player[vm_id].cache_handle, &size);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, size);
    
    /* close cache file */    
    result = FS_Close(video_player[vm_id].cache_handle);
    if (result == FS_NO_ERROR)
    {
        video_player[vm_id].cache_handle = NULL;
    }
    else
    {
        return KAL_FALSE; 
    }    
  
    return KAL_TRUE; 
#else  /* __MMI_VIDEO_PDL__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_PDL__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  jma_mvm_video_player_refresh
 * DESCRIPTION
 *  The function is used to refresh camera, video player to new location/size
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
static kal_bool jma_mvm_video_player_refresh(kal_int32 vm_id, kal_int32 java_player)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_REFRESH, vm_id, java_player, video_player[vm_id].state);

    EXT_ASSERT(video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY, 0, 0, 0);

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||        
        video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING ||
        (video_player[vm_id].state == JAVA_MEDIA_STATE_READY && preview_layer_handle != GDI_NULL_HANDLE))
    {
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            /* to enable blt rect been set successfully */
            gdi_layer_set_hw_update_layer(preview_layer_handle,KAL_FALSE);
        }
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);
        if (ret == KAL_TRUE)
        {           
            /* Draw video layer with new location/size on LCD */
            result = mdi_video_ply_seek_and_get_frame(
                        video_player[vm_id].current_time,
                        preview_layer_handle);
            if (result == MED_RES_OK ||
                result == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
                result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
                result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
            {
                video_player[vm_id].seek_error = KAL_FALSE;
            }
            else
            {
                video_player[vm_id].seek_error = KAL_TRUE;
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            }
            
            jma_video_player_update_blt_flag(vm_id, JMA_FORCE_BLT);
        }
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {      
        jma_mvm_video_player_pause(vm_id, MMA_TYPE_MPEG, java_player);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            /* to enable blt rect been set successfully */
            gdi_layer_set_hw_update_layer(preview_layer_handle,KAL_FALSE);
        }
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);
        if (ret == KAL_TRUE)
        {
            ret = jma_mvm_video_player_play(vm_id, MMA_TYPE_MPEG, java_player);
            if (ret == KAL_FALSE) /* Handle play fail case: close the player like MEDIA_ERROR */
            {
                jma_mvm_video_player_close(vm_id, MMA_TYPE_MPEG, java_player);
            }
        }
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING && preview_layer_handle != GDI_NULL_HANDLE)
    {
        /* Only update Visible now. Location and size needs to do more consideration */
        jma_video_player_update_blt_flag(vm_id, JMA_FORCE_NO_BLT);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_seek
 * DESCRIPTION
 *  function to be called for seeking to assigned frame number
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  frame_number            [IN]        
 *  frameNumber(?)          [IN]        Frame number
 * RETURNS
 *  actual frame number to seek to.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_seek(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = MED_RES_OK;
    kal_uint64 media_time = 0;
    kal_uint64 seek_time = 0;
    kal_int32 seeked_frame_number = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SEEK, vm_id, java_player, video_player[vm_id].state, frame_number);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(-1);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(-1);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* BUFFERING state is for pdl player */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        jma_mvm_video_player_pause(vm_id, mma_type, java_player);

        /* For seek_result_hdlr to resume to BUFFERING or PLAYING state */
        video_player[vm_id].is_play_requested = KAL_TRUE;
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_SEEKING)   
    {
        /* Stop the original seek at first */
        mdi_video_ply_stop_non_block_seek();
        
        /* Change state to the original state */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, video_player[vm_id].prev_state);
        video_player[vm_id].state = video_player[vm_id].prev_state;
    }
    
    jma_total_frames = jma_mvm_video_player_map_time_to_frame(vm_id, mma_type, java_player, video_player[vm_id].duration);

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, frame_number, jma_total_frames);

    /* set new position */
    if (frame_number < 0)
    {
        frame_number = 0;
    }
    
    if (frame_number > jma_total_frames)
    {
        media_time = jma_mvm_video_player_map_frame_to_time(vm_id, mma_type, java_player, jma_total_frames);
        seeked_frame_number = jma_total_frames;
    }
    else
    {
        media_time = jma_mvm_video_player_map_frame_to_time(vm_id, mma_type, java_player, frame_number);
        seeked_frame_number = frame_number;
    }

    /* state is READY or pure-audio */
    if (preview_layer_handle == NULL || video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
    {
        ms = (kal_int32)mdi_video_ply_non_block_seek(media_time, jma_video_player_seek_result_hdlr, 0);
    }
    else
    {
        ms = (kal_int32)mdi_video_ply_non_block_seek_and_get_frame(
                media_time, preview_layer_handle, jma_video_player_seek_result_hdlr, 0);   
    }

    if (ms == 0 ||
        ms == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED ||
        ms == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
        ms == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {    
        /* Change current time */
        video_player[vm_id].current_time = media_time;
        
        if (video_player[vm_id].is_play_requested)
        {
            video_player[vm_id].prev_state = JAVA_MEDIA_STATE_PLAYING;
        }
        else
        {
            video_player[vm_id].prev_state = video_player[vm_id].state;
        }        
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_SEEKING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_SEEKING;  
    }
    else
    {   
        video_player[vm_id].seek_error = KAL_TRUE;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);

        if (video_player[vm_id].is_play_requested)
        {
            jma_mvm_video_player_play(vm_id, mma_type, java_player);
        }
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, seeked_frame_number, (int)seek_time);
    JMA_CS_LEAVE(seeked_frame_number);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_skip
 * DESCRIPTION
 *  function to be called for skipping for assigned frame number from current position.
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  frames_to_skip          [IN]        
 *  framesToSkip(?)         [IN]        Frames to skip
 * RETURNS
 *  actual frame number to skip from current position.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_skip(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frames_to_skip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 current_frame, skip_frame, seek_frame;
    kal_int64 tmp_frame = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SKIP, vm_id, java_player, video_player[vm_id].state, frames_to_skip);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_ERROR, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(-1);
    }
    
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(-1);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    current_frame = jma_mvm_video_player_map_time_to_frame(vm_id, mma_type, java_player, video_player[vm_id].current_time);

    tmp_frame = current_frame + (S64) frames_to_skip;
    
    if (tmp_frame < 0)
    {
        seek_frame = 0; 
    }
    else if (tmp_frame > 0x7FFFFFFF) /* overflow case (int) */
    {
        seek_frame = 0x7FFFFFFF;
    }
    else
    {
        seek_frame = tmp_frame;
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, current_frame, seek_frame);
    
    seek_frame = jma_mvm_video_player_seek(vm_id, mma_type, java_player, seek_frame);
    skip_frame = seek_frame - current_frame;
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, skip_frame);
    JMA_CS_LEAVE(skip_frame);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_map_frame_to_time
 * DESCRIPTION
 *  function to be called to translate frame number into corresponding media time
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  frame_number            [IN]        Frame number to be translated to media time
 * RETURNS
 *  media time which corresponding to frame number
 *****************************************************************************/
kal_uint64 jma_mvm_video_player_map_frame_to_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 media_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_FRAME_TO_TIME, vm_id, java_player, video_player[vm_id].state, frame_number);
    JMA_CS_ENTER(vm_id, 0);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(0);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(0);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(0);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_ply_get_frame_to_time((kal_uint32) frame_number, &media_time);

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)media_time);
    JMA_CS_LEAVE(media_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_map_time_to_frame
 * DESCRIPTION
 *  function to be called to translate media time into corresponding frame number
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  media_time              [IN]        Media time to be translated to frame number
 * RETURNS
 *  frame number which corresponding to media time
 *****************************************************************************/
kal_int32 jma_mvm_video_player_map_time_to_frame(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int64 media_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 frame_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_TIME_TO_FRAME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)media_time);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(-1);
    }
    
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(-1);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_ply_get_time_to_frame(media_time, (kal_uint32*) & frame_number);

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, frame_number);
    JMA_CS_LEAVE(frame_number);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_info
 * DESCRIPTION
 *  This function gets video info
 * PARAMETERS    
 *  java_player     [IN]        
 *  audio_info      [OUT] the memory is allocated/de-allocated at kni level       
 * RETURNS
 *  true if success
 *****************************************************************************/
kal_bool jma_mvm_video_player_get_info(kal_int32 vm_id, int mma_type, int java_player, audInfoStruct *video_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_INFO, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, KAL_FALSE); 

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }   

    /* handle All NULL String case */
    if (mmi_ucs2strlen(video_player[vm_id].title_desc) == 0 && 
        mmi_ucs2strlen(video_player[vm_id].copyright_desc) == 0 &&
        mmi_ucs2strlen(video_player[vm_id].date_desc) == 0 && 
        mmi_ucs2strlen(video_player[vm_id].author_desc) == 0)
    {
        kal_wsprintf((WCHAR*)video_player[vm_id].title_desc, "unknown");        
    }        

    mmi_ucs2ncpy((S8*)video_info->title , video_player[vm_id].title_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy((S8*)video_info->author, video_player[vm_id].author_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy((S8*)video_info->date, video_player[vm_id].date_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    mmi_ucs2ncpy((S8*)video_info->copyright, video_player[vm_id].copyright_desc, MDI_VIDEO_CONTENT_BUFFER_SIZE);
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_is_active
 * DESCRIPTION
 *  This API is used to decide whether video is active or not
 * PARAMETERS   
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
kal_bool jma_video_player_is_active(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (SUPPORT_MMAPI)    
    if (INVALID_JVM_ID != vm_id &&
        JAVA_MEDIA_INVALID_DEVICE != video_player[vm_id].device_type)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
#else /* defined (SUPPORT_MMAPI) */
    return KAL_FALSE;
#endif /* defined (SUPPORT_MMAPI) */
}

#ifdef __MMI_VIDEO_STREAM__
/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_refresh
 * DESCRIPTION
 *  The function is used to refresh camera, video player to new location/size
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
static kal_bool jma_stream_player_refresh(kal_int32 vm_id, kal_int32 java_player)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    kal_bool ret = KAL_TRUE;
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_REFRESH, vm_id, java_player, video_player[vm_id].state);

    EXT_ASSERT(video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY, 0, 0, 0);
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        ms = mdi_video_stream_pause();        
        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_stream_player_close(video_player[vm_id].id);   
            return KAL_FALSE;
        }
            
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);        

        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
        ms = mdi_video_stream_resume(
                preview_layer_handle,
                blt_layer_flag,
                preview_layer_flag,
                visible,
                MDI_DEVICE_SPEAKER2, 
                MDI_VIDEO_LCD_ROTATE_0);

        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);   
            return KAL_FALSE;
        }
    }
    /* use this method to check if need refresh. OPENING, a part of READY */
    else if (preview_layer_handle != NULL) 
    {       
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);

        jma_video_player_update_blt_flag(vm_id, JMA_FORCE_BLT);
    }
    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_finalize
 * DESCRIPTION
 *  Finalize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_stream_player_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }

    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }

    jma_video_player_reset_parameter(vm_id);    
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_before_suspend_hdlr
 * DESCRIPTION
 *  This function is suspend handler 
 * PARAMETERS
 *  jplayer        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_stream_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_SUSPEND_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (g_jma_is_bearer_deactivated[vm_id])
    {
        jma_mvm_stream_player_close(vm_id, java_player);
        JMA_CS_LEAVE(RESOUCE_NO_ERROR);
    }
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING ||
             video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED)
    {
    #ifdef __TCPIP__
        cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));    
    #endif
        mdi_video_stream_disconnect();            
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        mdi_video_stream_stop_buffering();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_stream_stop();

        mdi_video_stream_get_cur_play_time(&video_player[vm_id].current_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
        
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
    }

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }

    /* Stop double buffer when suspend video */
    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_resume_hdlr
 * DESCRIPTION
 *  This function is resume handler 
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_stream_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_RESUME_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    /* Backlight control */
    jvm_force_backlight_on(KAL_TRUE);
    
    /* Init stream player */
    ms = mdi_video_stream_init(JAVA_APP_ID_MED);
    
    if (ms != MDI_RES_VDOPLY_SUCCEED)
    {
        if (video_player[vm_id].is_double_buffer)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
            jui_widget_stop_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_FALSE;
        }
        jma_video_player_reset_parameter(vm_id);

        jma_deregister_device(JAVA_MEDIA_STREAM_PLAYER_DEVICE, vm_id, java_player);
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    /* MED would set mute when play dummy audio for pure video */
    jam_set_aud_volume_level(jam_get_aud_volume_level()); 
        
    if (video_player[vm_id].stoptime != -1)
    {
        mdi_video_stream_set_stop_time(video_player[vm_id].stoptime);
    }

    if (!video_player[vm_id].is_double_buffer)
    {
        /* Start double buffer when resume video */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;    
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING ||        
        video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        
    {      
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_player[vm_id].is_play_requested);
        if (J2ME_active_nw_acc_id[vm_id] == 255)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            
            JMA_CS_LEAVE(RESOUCE_FAIL);
        }
        else
        {
            kal_int32 status = cbm_get_bearer_status(J2ME_active_nw_acc_id[vm_id]);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, status);
            if (status == CBM_DEACTIVATED ||
                status == CBM_DEACTIVATING)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, status);
            
                JMA_CS_LEAVE(RESOUCE_FAIL);
            }
        #ifdef __TCPIP__
            cbm_register_bearer_info_by_app_id(
                cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]),
                MOD_JASYN_D,
                CBM_PS | CBM_WIFI,
                CBM_DEACTIVATED | CBM_ACTIVATED | CBM_DEACTIVATING);
        #endif
            g_jma_is_stream_video = KAL_TRUE;
            g_jma_is_bearer_deactivated[vm_id] = KAL_FALSE;
        #ifdef __COSMOS_MMI_PACKAGE__
        	mdi_video_stream_set_scenario (MDI_VIDEO_SCENARIO_QVGA);
        #endif
            ms = mdi_video_stream_connect(
                    J2ME_active_nw_acc_id[vm_id], 
                    video_player[vm_id].stream_type,
                    (S8*) video_player[vm_id].filename, 
                    KAL_FALSE, 
                    NULL, 
                    0, 
                    KAL_FALSE,
                    0,
                    0,
                    jma_stream_player_connect_result_hdlr,
                    NULL);
            
            if (ms == MDI_RES_VDOPLY_SUCCEED)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTING;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
                
                JMA_CS_LEAVE(RESOUCE_FAIL);
            }
        }
    }

    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_close_hdlr
 * DESCRIPTION
 *  This function is close handler 
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_stream_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_CLOSE_HDLR, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    /* With resource */
    if (!is_vm_suspend_media[vm_id])
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            mdi_video_stream_deinit();
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED)
        {
            mdi_video_stream_disconnect();            
            mdi_video_stream_deinit();
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
        {
            mdi_video_stream_stop_buffering();
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);

            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            mdi_video_stream_stop();
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
        } 
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);
    }

    /* 20110608 MAUI_02955586 */
#ifdef __TCPIP__
    cbm_release_bearer(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
    cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
#endif
    jma_deregister_device(video_player[vm_id].device_type, vm_id, java_player);
    jma_stream_player_finalize(vm_id);
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_play_finish_hdlr
 * DESCRIPTION
 *  This function is play finish result handler 
 * PARAMETERS
 *  result          [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jma_stream_player_play_finish_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    java_mma_type_enum event_type;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_PLAY_FINISH_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);

    /* Error occurs */
    if (result < 0)
    {           
        mdi_video_stream_disconnect();            
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);   
        JMA_CS_LEAVE(JMA_VOID);
    }
    else if (result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
             result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        /* normal error code, which do not need to handle */
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    if (result == MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW ||
        result == MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW)
    {
        EXT_ASSERT(video_player[vm_id].is_play_requested == KAL_TRUE, 0, 0, 0);
        mdi_video_stream_get_cur_play_time(&video_player[vm_id].current_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
        if (video_player[vm_id].is_seekable)
        {     
            ms = mdi_video_stream_start_buffering(
                    video_player[vm_id].current_time, 
                    jma_stream_player_buffering_done_hdlr,
                    NULL);
            if (ms == MDI_RES_VDOPLY_SUCCEED)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
                stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);

                mdi_video_stream_disconnect();            
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
                video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
                jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
            }
        }
        else
        {
        #ifdef __TCPIP__
            cbm_register_bearer_info_by_app_id(
                cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]),
                MOD_JASYN_D,
                CBM_PS | CBM_WIFI,
                CBM_DEACTIVATED | CBM_ACTIVATED | CBM_DEACTIVATING);
        #endif
            g_jma_is_stream_video = KAL_TRUE;
            g_jma_is_bearer_deactivated[vm_id] = KAL_FALSE;
            mdi_video_stream_disconnect();
        #ifdef __COSMOS_MMI_PACKAGE__
            mdi_video_stream_set_scenario (MDI_VIDEO_SCENARIO_QVGA);
        #endif
            ms = mdi_video_stream_connect(
                    J2ME_active_nw_acc_id[vm_id], 
                    video_player[vm_id].stream_type,
                    (S8*) video_player[vm_id].filename, 
                    KAL_FALSE, 
                    NULL, 
                    0, 
                    KAL_FALSE,
                    0,
                    0,                    
                    jma_stream_player_connect_result_hdlr,
                    NULL);
            
            if (ms == MDI_RES_VDOPLY_SUCCEED)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTING;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
                video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
                jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
            }
        }
        JMA_CS_LEAVE(JMA_VOID);      
    }
    
    /* Play finish */
    EXT_ASSERT(result >= 0, 0, 0, 0);
    
    video_player[vm_id].is_play_requested = KAL_FALSE;

    /* Can get playing time only when stopped from PLAYING state */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_stream_get_cur_play_time(&video_player[vm_id].current_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
    }
    if (video_player[vm_id].is_seekable)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;            
    }
    else
    {
        mdi_video_stream_disconnect();
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    } 
        
    if (result == MDI_RES_VDOPLY_REACH_STOP_TIME)
    {       
        /* Clear stop time */
        video_player[vm_id].stoptime = -1;        
        mdi_video_stream_set_stop_time((U64) -1);
        
        event_type = MMA_EVENT_STOPPED_AT_TIME;
        jvm_post_mma_event(event_type, video_player[vm_id].id, (kal_int64) video_player[vm_id].current_time);
    
    }
    else
    {
        video_player[vm_id].play_finish_time = video_player[vm_id].current_time;
        /* set current time as 0 for playing at next time */
        video_player[vm_id].current_time = 0; 
        
        event_type = MMA_EVENT_END_OF_MEDIA;        
        jvm_post_mma_event(event_type, video_player[vm_id].id, (kal_int64) video_player[vm_id].play_finish_time);
    }
    JMA_CS_LEAVE(JMA_VOID);    
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_connect_result_hdlr
 * DESCRIPTION
 *  This function is invoked at JAVA context
 * PARAMETERS
 *  result          [IN] 
 *  video_clip      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_stream_player_connect_result_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    kal_bool ret, is_valid;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    kal_int32 str_len, i;    
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_CONNECT_RESULT_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    
    /* Network disconnects automatically, close player */
    /* result == MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT */
    if (result < 0)
    {
        /* The player has not been closed, avoid MED sends disconnect indication many times */
        if (video_player[vm_id].state != JAVA_MEDIA_STATE_NULL)
        {
            if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                stack_stop_timer(&java_media_timer);
            }
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
        }        
        JMA_CS_LEAVE(JMA_VOID);
    }    
    
    /* Below: handle no error case */  

    /* Connect Successfully, but Java does not support PDCF drm format */
    if (vdo_clip->is_drm_streaming)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;

        jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    /* Get information */
    video_player[vm_id].duration = vdo_clip->total_time_duration;
    video_player[vm_id].is_seekable = vdo_clip->is_seekable;
    video_player[vm_id].track = vdo_clip->track; 

    str_len = strlen((PS8)vdo_clip->title_desc);
    
    if (str_len != 0)
    {
        /* check if title is all space */
        is_valid = KAL_FALSE;
        for (i = 0; i < str_len; i++)
        {
            if (vdo_clip->title_desc[i] != ' ')
            {
                is_valid = KAL_TRUE;
                break;                    
            }
        }

        if (is_valid)
        {
           mmi_asc_n_to_ucs2(
                (PS8)video_player[vm_id].title_name, 
                (PS8)&vdo_clip->title_desc, 
                MDI_VIDEO_INFO_TITLE_CHAR_COUNT - 1);
        }
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDD, (kal_uint32)video_player[vm_id].duration,  video_player[vm_id].is_seekable, video_player[vm_id].track);
  
    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
    video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;

    /* Goal: go to PLAYING state or buffering a little to get width/height */
    if (video_player[vm_id].is_play_requested || !video_player[vm_id].is_stream_opened)
    {        
        if (!video_player[vm_id].is_seekable) 
        {
            /* (1) Reset current_time. So getMediaTime can return correctly */
            /* (2) If non-seekable, mdi_video_stream_start_buffering() should use 0 as 1st parameter */
            video_player[vm_id].current_time = 0;
        }
        
        /* Set stream SW decoder's sleep time */
        mdi_video_stream_set_sleep_time(JMA_VIDEO_ELAPSE_TICKS, JMA_VIDEO_SLEEP_TICKS);
        /* start buffering */     
        ms = mdi_video_stream_start_buffering(
                video_player[vm_id].current_time, 
                jma_stream_player_buffering_done_hdlr,
                NULL);

        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;

            /* Create layer for drawing progress bar */
            if (video_player[vm_id].is_stream_opened && video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
            {                
                jma_video_player_refine_display_info(vm_id);
                ret = jma_video_player_process_layer(vm_id);
				if(1 == ret)
				{
				    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
				}
            }
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
        }
        else if (ms == MDI_RES_VDOPLY_REACH_STOP_TIME)
        {
            jma_stream_player_play_finish_hdlr(ms, NULL);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
        }
    }
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_buffering_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN] 
 *  video_clip      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_stream_player_buffering_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    kal_bool ret;
    kal_bool visible;
    U16 rotate = MDI_VIDEO_LCD_ROTATE_0;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_BUFFERING_DONE_HDLR, vm_id, result, video_player[vm_id].state);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    /* stop timer used to get download percentage first */
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
    stack_stop_timer(&java_media_timer);

    /* Error occurs, close the player */
    if (result < 0) 
    {
        mdi_video_stream_disconnect();            
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }
    else if (result == MDI_RES_VDOPLY_REACH_STOP_TIME)
    {
        jma_stream_player_play_finish_hdlr(result, NULL);
        JMA_CS_LEAVE(JMA_VOID);     
    }
    else if (result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR ||
             result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        /* normal error code, which do not need to handle */
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    /* Buffering a little to get video width and video height */
    if (!video_player[vm_id].is_stream_opened)
    {
        /* Get info should be before stop buffering */
        ms = mdi_video_stream_get_dimension(&video_player[vm_id].video_width, &video_player[vm_id].video_height); 
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, video_player[vm_id].video_width, video_player[vm_id].video_height);
        if (video_player[vm_id].video_width == 0 && video_player[vm_id].video_height == 0)
        {
            video_player[vm_id].video_width = DEFAULT_WIDTH;
            video_player[vm_id].video_height = DEFAULT_HEIGHT;
        }
        mdi_video_stream_stop_buffering();
        /* Error handling */
        if (ms != MDI_RES_VDOPLY_SUCCEED)
        {
            mdi_video_stream_disconnect();            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            jma_stream_player_close(video_player[vm_id].id);
            JMA_CS_LEAVE(JMA_VOID);
        }
        
        if (video_player[vm_id].is_seekable)
        {           
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
        }
        else
        {
            mdi_video_stream_disconnect();               
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        /* set the flag as true when all things are done */
        video_player[vm_id].is_stream_opened = KAL_TRUE;
        JMA_CS_LEAVE(JMA_VOID);
    }    
    
    EXT_ASSERT(video_player[vm_id].is_play_requested, 0, 0, 0);

    gdi_image_stop_animation_all();
    mdi_video_stream_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
    mdi_video_stream_set_contrast(MDI_VIDEO_CONTRAST_0);      
        
    mdi_video_stream_set_audio_level(video_player[vm_id].volume);
    /* Below: handle no error case */
    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        /* Get Information */
        video_player[vm_id].video_width = vdo_clip->width;
        video_player[vm_id].video_height = vdo_clip->height;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, video_player[vm_id].video_width, video_player[vm_id].video_height);
        if (video_player[vm_id].video_width == 0 && video_player[vm_id].video_height == 0)
        {
            video_player[vm_id].video_width = DEFAULT_WIDTH;
            video_player[vm_id].video_height = DEFAULT_HEIGHT;
        }
        /* ConfigROI should be invoked after video_player_active is set */
        /* The two line may be redundant */
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);       
		if(1 == ret)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
	    }

        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
    /* Not IDP rotate*/
    #ifndef __MDI_VIDEO_HW_ROTATOR_BY_IDP__
        if (video_ctrl_info[vm_id].fullscreen_rotate == KAL_TRUE)
        {
            rotate = MDI_VIDEO_LCD_ROTATE_270;
        }
    #endif /* __MDI_VIDEO_HW_ROTATOR_BY_IDP__ */
        
        mdi_video_stream_enable_partial_display();
        ms = mdi_video_stream_play(
                preview_layer_handle, 
                blt_layer_flag,
                preview_layer_flag, 
                visible, 
                MDI_DEVICE_SPEAKER2, 
                rotate, 
                jma_stream_player_play_finish_hdlr,
                NULL);
    }
    else /* Only audio track */
    {
        ms = mdi_video_stream_play(
                NULL, 
                0,
                0, 
                KAL_FALSE, 
                MDI_DEVICE_SPEAKER2, 
                MDI_VIDEO_LCD_ROTATE_0, 
                jma_stream_player_play_finish_hdlr,
                NULL);
    }

    if (ms == MDI_RES_VDOPLY_SUCCEED)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;

        /* Connect BT when playing successfully */
    #if defined(__MMI_BT_AUDIO_VIA_SCO__)
        jma_media_player_connect_bt_via_sco(NULL);
    #endif    
    }
    else if (ms == MDI_RES_VDOPLY_REACH_STOP_TIME)
    {
        jma_stream_player_play_finish_hdlr(ms, NULL);
    }
    else
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);

        mdi_video_stream_disconnect();            
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        jma_mvm_stream_player_close(vm_id, video_player[vm_id].id);
    }
    JMA_CS_LEAVE(JMA_VOID);

}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_buffering_cyclic
 * DESCRIPTION
 *  This function is buffering cyclic handler 
 * PARAMETERS
 *  result          [IN] 
 *  video_clip      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_stream_player_buffering_cyclic(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dl_percentage;
    MDI_RESULT ms;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */   
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_BUFFERING_CYCLIC, vm_id, video_player[vm_id].state, video_player[vm_id].is_stream_opened);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    mdi_video_stream_get_buf_percentage(&dl_percentage);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, dl_percentage);

    /* Buffering a little to get video width and video height */
    if (!video_player[vm_id].is_stream_opened)
    {
        if (dl_percentage > 0)
        {
            /* Get info should be before stop buffering */
            ms = mdi_video_stream_get_dimension(&video_player[vm_id].video_width, &video_player[vm_id].video_height); 
            /* if fail, download percentage is not enough, go on downloading */
            if (ms == MDI_RES_VDOPLY_SUCCEED)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, video_player[vm_id].video_width, video_player[vm_id].video_height);
                /* buffering data is not enough to get dimention info */
                if (video_player[vm_id].video_width == 0 && video_player[vm_id].video_height == 0)
                {
                    if (dl_percentage < 100)
                    {
                        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
                        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
                    }
                    JMA_CS_LEAVE(JMA_VOID);
                }
                mdi_video_stream_stop_buffering();

                if (video_player[vm_id].is_seekable)
                {           
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
                    video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
                }
                else
                {
                    mdi_video_stream_disconnect();               
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
                    video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
                }

                /* set the flag as true when all things are done */
                video_player[vm_id].is_stream_opened = KAL_TRUE;
                JMA_CS_LEAVE(JMA_VOID);
            }      
        }
    }

    /* Draw progress bar: Don't draw it when buffering for open */
    if (video_player[vm_id].is_stream_opened && video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        jma_video_player_draw_progress_bar(vm_id, dl_percentage);
    }
    
    if (dl_percentage < 100)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
    }
    JMA_CS_LEAVE(JMA_VOID);

}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_open
 * DESCRIPTION
 *  This function opens streaming player
 * PARAMETERS  
 *  java_player     [IN]        
 *  url             [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_stream_player_open(kal_int32 vm_id, kal_int32 java_player, kal_char *url)
{
#ifdef __MMI_VIDEO_STREAM__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_VDOPLY_ERR_FAILED;
    kal_int32 length;
    kal_wchar *ext_name;
    kal_wchar protocol[4+1];
    kal_int8 audio_state = -1;
    
#ifdef __TCPIP__     
    cbm_bearer_enum bearer_type;
#endif
    kal_bool valid = KAL_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    audio_state = jma_mvm_audio_player_state(vm_id);
    if (jma_audio_recorder_is_active(vm_id) || JMA_AUDIO_ACTIVE == audio_state)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

#ifdef __JMA_PREEMPT_PLAYER__ /*this will not happen if VM instance is 1*/
    if (JMA_AUDIO_NON_ACTIVE == audio_state)
    {
        jma_video_notify_suspend_audio_player(vm_id);
    }
#endif
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        mmi_ucs2ncpy((S8*) video_player[vm_id].filename, url, J2ME_PATH_BUFFER_SIZE - 1);
        
        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
    
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();

        /* Init stream player */
        ms = mdi_video_stream_init(JAVA_APP_ID_MED);
         
        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            video_player[vm_id].is_play_requested = KAL_FALSE;
        
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
            jui_widget_start_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_TRUE;

            /* MED would set mute when play dummy audio for pure video */
            jam_set_aud_volume_level(jam_get_aud_volume_level()); 
        
            /* Check format */
            length = mmi_ucs2strlen((S8*) video_player[vm_id].filename);
            EXT_ASSERT(length >= 3, 0, 0, 0);
            ext_name = &video_player[vm_id].filename[length - 3];
            if (length >= 4)
            {
                memset((void*)protocol, 0, sizeof(protocol));
                mmi_ucs2ncpy((kal_char *) protocol,(const kal_char *)video_player[vm_id].filename, 4);
                if (mmi_ucs2icmp((const kal_char *) protocol, (const kal_char *) L"rtsp") != 0)
                {
                    video_player[vm_id].stream_type = MDI_VIDEO_STREAM_SDP_FILE;
                }
                
            }
            else if (mmi_ucs2icmp((const kal_char *) ext_name, (const kal_char *) L"sdp") == 0)
            {
                video_player[vm_id].stream_type = MDI_VIDEO_STREAM_SDP_FILE;
            }
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_player[vm_id].stream_type); 

          
            if (J2ME_active_nw_acc_id[vm_id] == 255)
            {
                valid = KAL_FALSE;
            }
        #ifdef __TCPIP__    
            else
            {
                cbm_get_bearer_type(J2ME_active_nw_acc_id[vm_id], &bearer_type);
                valid = (bearer_type == CBM_CSD)? KAL_FALSE : KAL_TRUE;
            }
        #endif /*__TCPIP__ */
               
            if (!valid)
            {                
                mdi_video_stream_deinit();
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_NULL);
                video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
                /* Backlight control */
                jvm_force_backlight_on(KAL_FALSE);

                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
                jui_widget_stop_double_buffer();
                video_player[vm_id].is_double_buffer = KAL_FALSE;
                
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, J2ME_active_nw_acc_id[vm_id]); 
                JMA_CS_LEAVE(KAL_FALSE);
            }
            else
            {
                /* 20110608 MAUI_02955586 */
            #ifdef __TCPIP__
                cbm_hold_bearer(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
                cbm_register_bearer_info_by_app_id(
                    cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]),
                    MOD_JASYN_D,
                    CBM_PS | CBM_WIFI,
                    CBM_DEACTIVATED | CBM_ACTIVATED | CBM_DEACTIVATING);
            #endif
				g_jma_is_stream_video = KAL_TRUE;
                g_jma_is_bearer_deactivated[vm_id] = KAL_FALSE;
            #ifdef __COSMOS_MMI_PACKAGE__
				mdi_video_stream_set_scenario(MDI_VIDEO_SCENARIO_QVGA);
            #endif
                ms = mdi_video_stream_connect(
                        J2ME_active_nw_acc_id[vm_id], 
                        video_player[vm_id].stream_type,
                        (S8*) video_player[vm_id].filename, 
                        KAL_FALSE, 
                        NULL, 
                        0, 
                        KAL_FALSE,
                        0,
                        0,                    
                        jma_stream_player_connect_result_hdlr,
                        NULL);
                
                if (ms == MDI_RES_VDOPLY_SUCCEED)
                {
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTING);
                    video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTING;
                }
                else
                {
                    mdi_video_stream_deinit();
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_NULL);
                    video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
                }
            }
        }
        
        if (ms != MDI_RES_VDOPLY_SUCCEED)
        {
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms); 
            JMA_CS_LEAVE(KAL_FALSE);
        }        
        
        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_STREAM_PLAYER_DEVICE,
            vm_id,
            java_player, 
            &jma_stream_player_suspend_hdlr, 
            &jma_stream_player_resume_hdlr, 
            &jma_stream_player_close_hdlr);
        
        mdi_video_stream_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_INSIDE);
        video_player[vm_id].id = java_player;
        video_player[vm_id].volume = DEFAULT_VIDEO_VOLUME;
        video_player[vm_id].current_time = 0;
        video_player[vm_id].is_seekable = KAL_FALSE;
        video_player[vm_id].is_stream_opened = KAL_FALSE;
        video_player[vm_id].play_finish_time = 0;
        video_player[vm_id].device_type = JAVA_MEDIA_STREAM_PLAYER_DEVICE;
        
        video_ctrl_info[vm_id].set_display_location = KAL_FALSE;
        video_ctrl_info[vm_id].set_display_size = KAL_FALSE;
        video_ctrl_info[vm_id].is_visible = KAL_TRUE;
        video_ctrl_info[vm_id].is_full_screen = KAL_FALSE;
        video_ctrl_info[vm_id].offset_x = 0;
        video_ctrl_info[vm_id].offset_y = 0;
        video_ctrl_info[vm_id].width = 0;
        video_ctrl_info[vm_id].height = 0;
        video_player[vm_id].scr_mem_max_size = JMA_VDOPLY_LAYER_BUFFER_SIZE;
    }

    JMA_CS_LEAVE(KAL_TRUE);
#else  /* __MMI_VIDEO_STREAM__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_STREAM__ */  

    
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_play
 * DESCRIPTION
 *  This function starts streaming player
 * PARAMETERS  
 *  java_player     [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_stream_player_play(kal_int32 vm_id, kal_int32 java_player)
{  
#ifdef __MMI_VIDEO_STREAM__     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_VDOPLY_SUCCEED;
    kal_bool ret = KAL_TRUE;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_PLAY, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* State will go to PLAYING step by step: used in CONNECTED state */
    video_player[vm_id].is_play_requested = KAL_TRUE;
    /* Reset play finish time for the play of this time */
    video_player[vm_id].play_finish_time = 0;  

    /* If vm_id not FG running, just swith the state to ensure resume normally */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    /* Notice that state will be changed in this block */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        if (J2ME_active_nw_acc_id[vm_id] == 255)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, J2ME_active_nw_acc_id[vm_id]);
            ret = KAL_FALSE;
        }
        else
        {
        #ifdef __COSMOS_MMI_PACKAGE__
            mdi_video_stream_set_scenario (MDI_VIDEO_SCENARIO_QVGA);
        #endif
        #ifdef __TCPIP__
            cbm_register_bearer_info_by_app_id(
                cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]),
                MOD_JASYN_D,
                CBM_PS | CBM_WIFI,
                CBM_DEACTIVATED | CBM_ACTIVATED | CBM_DEACTIVATING);
        #endif
            g_jma_is_stream_video = KAL_TRUE;
            g_jma_is_bearer_deactivated[vm_id] = KAL_FALSE;
            ms = mdi_video_stream_connect(
                J2ME_active_nw_acc_id[vm_id], 
                video_player[vm_id].stream_type,
                (S8*) video_player[vm_id].filename, 
                KAL_FALSE, 
                NULL, 
                0, 
                KAL_FALSE,
                0,
                0,            
                jma_stream_player_connect_result_hdlr,
                NULL);
            if (ms == MDI_RES_VDOPLY_SUCCEED)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTING);
                video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTING;
                ret = KAL_TRUE;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
                ret = KAL_FALSE;
            }
        }
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED)
    {
        if (!video_player[vm_id].is_seekable) 
        {
            /* (1) Reset current_time. So getMediaTime can return correctly */
            /* (2) If non-seekable, mdi_video_stream_start_buffering() should use 0 as 1st parameter */
            video_player[vm_id].current_time = 0;
        }
        
        /* start buffering */     
        ms = mdi_video_stream_start_buffering(
                video_player[vm_id].current_time, 
                jma_stream_player_buffering_done_hdlr,
                NULL);
        
        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;

            /* Create layer for drawing progress bar */
            if (video_player[vm_id].is_stream_opened && video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
            {                
                jma_video_player_refine_display_info(vm_id);
                ret = jma_video_player_process_layer(vm_id);
                if (ret == KAL_FALSE)
                {
                    JMA_CS_LEAVE(KAL_FALSE);
                }
            }
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
            ret = KAL_TRUE;
        }
        else if (ms == MDI_RES_VDOPLY_REACH_STOP_TIME)
        {
            jma_stream_player_play_finish_hdlr(ms, NULL);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            ret = KAL_FALSE;
        }
    }    
    JMA_CS_LEAVE(ret);
    
#else  /* __MMI_VIDEO_STREAM__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_STREAM__ */     
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_pause
 * DESCRIPTION
 *  This function pauses streaming player
 *  seekable content: go to READY, CONNECTED or PAUSED state
 *  live content: go to READY state
 * PARAMETERS  
 *  java_player     [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_stream_player_pause(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_STREAM__     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_PAUSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    video_player[vm_id].is_play_requested = KAL_FALSE;

    /* If vm_id not FG running, just swith the state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            if (video_player[vm_id].is_seekable)
            {           
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
                video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
                video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            }
        }
        
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            if (video_player[vm_id].is_seekable)
            {           
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
                video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
                video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            }
        }
        
        JMA_CS_LEAVE(KAL_TRUE);
    }  
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* PAUSED state: already connected */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING) 
    {
    
    #ifdef __TCPIP__
        cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));    
    #endif
        mdi_video_stream_disconnect();            
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        mdi_video_stream_stop_buffering();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);
        
        /* Clear layer in order to clean progress bar */
        if (video_player[vm_id].is_stream_opened && video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
        {
            gdi_layer_push_and_set_active(preview_layer_handle);
            gdi_layer_clear_background(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
            jma_video_player_redraw_video_region(vm_id);
        }
            
        if (video_player[vm_id].is_seekable)
        {           
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
        }
        else
        {       
            mdi_video_stream_disconnect();
       
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        /* Stop the player will automatically stop buffering */
        mdi_video_stream_stop();
        mdi_video_stream_get_cur_play_time(&video_player[vm_id].current_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);

        if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
        {
            /* Draw the last frame onto screen to avoid discontinuity if MIDlet draws other things */
            jma_video_player_redraw_video_region(vm_id);
        }
        if (video_player[vm_id].is_seekable)
        {            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
        }
        else
        {            
            mdi_video_stream_disconnect();
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }        
    }

    JMA_CS_LEAVE(KAL_TRUE);
#else /* __MMI_VIDEO_STREAM__ */ 
    return KAL_FALSE;
#endif /* __MMI_VIDEO_STREAM__ */
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_close
 * DESCRIPTION
 *  This function closes streaming player
 * PARAMETERS  
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_stream_player_close(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_STREAM__     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_CLOSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    jma_deregister_device(JAVA_MEDIA_STREAM_PLAYER_DEVICE, vm_id, java_player);
    
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        /* 20110608 MAUI_02955586 */
    #ifdef __TCPIP__
        cbm_release_bearer(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
        cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
    #endif
        jma_stream_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        /* 20110608 MAUI_02955586 */
    #ifdef __TCPIP__
        cbm_release_bearer(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
        cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
    #endif
        jma_stream_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTING ||
             video_player[vm_id].state == JAVA_MEDIA_STATE_CONNECTED)
    {
        mdi_video_stream_disconnect();            
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
    {
        mdi_video_stream_stop_buffering();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);

        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_stream_stop();
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
    }

    if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
    {
        /* stop double buffer */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jma_video_player_redraw_video_region(vm_id);

        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {        
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }
    /* 20110608 MAUI_02955586 */
#ifdef __TCPIP__
    cbm_release_bearer(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
    cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));    
#endif

    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_NULL);

    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }

    jma_video_player_reset_parameter(vm_id);    

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif    
    JMA_CS_LEAVE(KAL_TRUE);
    
#else /* __MMI_VIDEO_STREAM__*/
    return KAL_FALSE;
#endif /* __MMI_VIDEO_STREAM__*/
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_stream_player_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_stream_player_clear_jmadata(kal_int32 vm_id, kal_int32 java_player)
{
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_CLEAR_JMADATA, vm_id, java_player);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;
    }
    
    jma_deregister_device(JAVA_MEDIA_STREAM_PLAYER_DEVICE, vm_id, java_player);
    jma_video_player_reset_parameter(vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_is_opened
 * DESCRIPTION
 *  This function can be invoked ONLY after _open() is invoked
 * PARAMETERS  
 *  java_player     [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_int32 jma_mvm_stream_player_is_opened(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_IS_OPENED, vm_id, java_player, video_player[vm_id].state, video_player[vm_id].is_stream_opened);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return -1;
    }    

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL) 
        {
            return -1; /* Fail case */
        }
        else
        {
            return 1;
        }
        //return -1;
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL) 
        {
            return -1; /* Fail case */
        }
        else
        {
            return 1;
        }
        //return -1;
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL) 
    {
        return -1; /* Fail case */
    }
    else if (video_player[vm_id].is_stream_opened)
    {
        return 1; /* open successfully */
    }
    else
    {
        return 0; 
    }

    //return -1;
#else /* __MMI_VIDEO_STREAM__*/
    return -1;
#endif /* __MMI_VIDEO_STREAM__*/    
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_set_media_time
 * DESCRIPTION
 *  This function submit VideoSetStartTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  now             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jma_mvm_stream_player_set_media_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 now)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;
    int ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    kal_bool is_refresh = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_SET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)now);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    /* Non-seekable content: need to add: go to READY at the second time */
    if (!video_player[vm_id].is_seekable)
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);
    }

    /* Set parameter */
    video_player[vm_id].current_time = now;  

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* Seekable content: at the following two states */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        EXT_ASSERT(video_player[vm_id].is_seekable, 0, 0, 0);
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_BUFFERING)
        {
            /* Stop buffering */
            mdi_video_stream_stop_buffering();
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED; 
            is_refresh = KAL_TRUE;
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            /* Stop the player */
            mdi_video_stream_stop();            
            /* Draw the last frame onto screen to avoid discontinuity if MIDlet draws other things */
            if (video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
            {
                jma_video_player_redraw_video_region(vm_id);
            }
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_CONNECTED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_CONNECTED;
        }

        /* Re-start buffering from specific time */        
        ms = mdi_video_stream_start_buffering(
            video_player[vm_id].current_time, 
            jma_stream_player_buffering_done_hdlr,
            NULL);
        if (ms == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_BUFFERING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_BUFFERING;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_STREAM_PLAYER + vm_id, ticks); 
            JMA_CS_LEAVE(now);
        }
        else if (ms == MDI_RES_VDOPLY_REACH_STOP_TIME)
        {
            /* Clear layer in order to clean progress bar */
            if (is_refresh && video_player[vm_id].track != MDI_VIDEO_TRACK_A_ONLY)
            {
                gdi_layer_push_and_set_active(preview_layer_handle);
                gdi_layer_clear_background(GDI_COLOR_BLACK);
                gdi_layer_pop_and_restore_active();
                jma_video_player_redraw_video_region(vm_id);
            }
            jma_stream_player_play_finish_hdlr(ms, NULL);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            JMA_CS_LEAVE(-1);
        }
    }
    JMA_CS_LEAVE(now);
    
#else /* __MMI_VIDEO_STREAM__*/
    return 0;
#endif /* __MMI_VIDEO_STREAM__*/ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_get_media_time
 * DESCRIPTION
 *  This function submit VideoGetMediaTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_uint64 jma_mvm_stream_player_get_media_time(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 current_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_GET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)video_player[vm_id].play_finish_time);
    JMA_CS_ENTER(vm_id, 0);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_video_stream_get_cur_play_time(&current_time);
        /* MED does not seek precisely. To Avoid current time goes back */
        if (current_time >= video_player[vm_id].current_time)
        {
            video_player[vm_id].current_time = current_time;
        }
        else
        {
            current_time = video_player[vm_id].current_time;
        }
        
    }
    else if (video_player[vm_id].play_finish_time != 0) /* for play finish */
    {
        current_time = video_player[vm_id].play_finish_time;
    }
    else 
    {
        current_time = video_player[vm_id].current_time;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)current_time);
    JMA_CS_LEAVE(current_time);
#else /* __MMI_VIDEO_STREAM__*/
    return 0;
#endif /* __MMI_VIDEO_STREAM__*/ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_get_duration
 * DESCRIPTION
 *  This function submit VideoGetDuration request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  count           [IN]        
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_int64 jma_mvm_stream_player_get_duration(kal_int32 vm_id, kal_int32 java_player)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 duration = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_GET_DURATION, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    duration = video_player[vm_id].duration;

    if (duration == 0)
    {
        duration = -1;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)duration);
    JMA_CS_LEAVE(duration);

#else /* __MMI_VIDEO_STREAM__*/
    return -1;
#endif /* __MMI_VIDEO_STREAM__*/ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_stop_time
 * DESCRIPTION
 *  This function submit VideoSetStopTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_uint64 jma_mvm_stream_player_set_stop_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 stime)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_SET_STOP_TIME, vm_id, java_player, video_player[vm_id].state, stime);
    JMA_CS_ENTER(vm_id, 0);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    video_player[vm_id].stoptime = stime;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(stime);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(stime);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_stream_set_stop_time(stime);

    JMA_CS_LEAVE(stime);

#else /* __MMI_VIDEO_STREAM__*/
    return 0;
#endif /* __MMI_VIDEO_STREAM__*/ 

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_volume
 * DESCRIPTION
 *  This function submit VideoSetVolume request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  vol             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_stream_player_set_volume(kal_int32 vm_id, kal_int32 java_player, kal_int32 vol)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_SET_VOLUME, vm_id, java_player, video_player[vm_id].state, vol);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    video_player[vm_id].volume = vol;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    mdi_video_stream_set_audio_level((kal_uint16)vol);
    JMA_CS_LEAVE(JMA_VOID);
#endif /* __MMI_VIDEO_STREAM__*/ 
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_get_title
 * DESCRIPTION
 *  This function return title. 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  vol             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_stream_player_get_title(kal_int32 vm_id, kal_int32 java_player, kal_wchar *title)
{
#ifdef __MMI_VIDEO_STREAM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_GET_TITLE, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;
    }

    if (mmi_ucs2strlen((S8 *) video_player[vm_id].title_name) == 0)
    {
        kal_wsprintf(video_player[vm_id].title_name, "unknown"); 
    }
    
    mmi_ucs2cpy((PS8) title, (PS8) video_player[vm_id].title_name);
   
#endif /* __MMI_VIDEO_STREAM__*/ 
}


/*****************************************************************************
 * FUNCTION
 *  jma_stream_player_process_bearer_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_stream_player_process_bearer_event(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_cbm_bearer_info_ind_struct *ind_ptr = 
        (app_cbm_bearer_info_ind_struct *)ilm_ptr->local_para_ptr;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_STREAM_PLAYER_PROCESS_BEARER_EVENT, ilm_ptr->msg_id, ind_ptr->state, vm_id);
    if (INVALID_JVM_ID == vm_id)
    {
        //ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }
    
    if (MSG_ID_APP_CBM_BEARER_INFO_IND == ilm_ptr->msg_id)
    {
        switch (ind_ptr->state)
        {
            case CBM_ACTIVATED:
                g_jma_is_stream_video = KAL_FALSE;
                // deregister
                cbm_deregister_bearer_info_by_app_id(cbm_get_app_id(J2ME_active_nw_acc_id[vm_id]));
                break;
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
            default:
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_is_pure_audio
 * DESCRIPTION
 *  This function gets or creates hidden folder on max free drive
 * PARAMETERS
 *  mma_type    [IN]
 *  pathname    [IN]
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_mvm_video_player_is_pure_audio(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_IS_PURE_AUDIO, vm_id, video_player[vm_id].track);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return KAL_FALSE;
    }

    if (video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


#else /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */ 
kal_bool jma_mvm_stream_player_open(kal_int32 vm_id, kal_int32 java_player, kal_char *url){ return KAL_FALSE;}
kal_bool jma_mvm_stream_player_play(kal_int32 vm_id, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_stream_player_pause(kal_int32 vm_id, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_stream_player_close(kal_int32 vm_id, kal_int32 java_player){return KAL_FALSE;}
void jma_mvm_stream_player_clear_jmadata(kal_int32 vm_id, kal_int32 java_player){}
kal_int32 jma_mvm_stream_player_is_opened(kal_int32 vm_id, kal_int32 java_player){return -1;}
kal_int64 jma_mvm_stream_player_set_media_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 now){return 0;}
kal_uint64 jma_mvm_stream_player_get_media_time(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int64 jma_mvm_stream_player_get_duration(kal_int32 vm_id, kal_int32 java_player){return -1;}
kal_uint64 jma_mvm_stream_player_set_stop_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 stime){return 0;}
void jma_mvm_stream_player_set_volume(kal_int32 vm_id, kal_int32 java_player, kal_int32 vol){}
void jma_mvm_stream_player_get_title(kal_int32 vm_id, kal_int32 java_player, kal_wchar *title){}

kal_bool jma_mvm_video_player_is_pdl_format(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count){return KAL_FALSE;}
kal_int32 jma_mvm_video_player_cache_is_opened(kal_int32 vm_id, kal_int32 java_player){return -1;}
kal_bool jma_mvm_video_player_cache_open(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count){return KAL_FALSE;}
kal_bool jma_mvm_video_player_cache_write(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count){return KAL_FALSE;}
kal_bool jma_mvm_video_player_cache_close(kal_int32 vm_id, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_player_is_pure_audio(kal_int32 vm_id, kal_int32 java_player){return KAL_FALSE;}

kal_int32 jma_mvm_video_player_get_max_rate(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_get_min_rate(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_get_rate(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_set_rate(kal_int32 vm_id, kal_int32 java_player, kal_int32 rate){return 0;}

void jma_mvm_video_player_pause(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_bool jma_mvm_video_player_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 length, kal_char *filename){return KAL_FALSE;}
kal_bool jma_mvm_video_player_play(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
void jma_mvm_video_player_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
void jma_mvm_video_player_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int64 jma_mvm_video_player_set_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_uint64 now){return 0;}
kal_uint64 jma_mvm_video_player_get_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return 0;}
kal_int64 jma_mvm_video_player_get_duration(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return -1;}
void jma_mvm_video_player_set_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 vol){}
kal_uint64 jma_mvm_video_player_set_stop_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_uint64 stime){return 0;}

kal_int32 jma_mvm_video_player_seek(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frame_number){return -1;}
kal_int32 jma_mvm_video_player_skip(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frames_to_skip){return -1;}
kal_uint64 jma_mvm_video_player_map_frame_to_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 frame_number){return 0;}
kal_int32 jma_mvm_video_player_map_time_to_frame(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int64 media_time){return -1;}
kal_bool jma_mvm_video_player_get_info(kal_int32 vm_id, int mma_type, kal_int32 java_player, audInfoStruct *video_info){return KAL_FALSE;}
kal_bool jma_video_player_is_active(kal_int32 vm_id){return KAL_FALSE;}
#endif /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */ 

void jma_video_player_get_hidden_folder(kal_wchar* pathname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 phone_drive, card_drive, max_drive = -1;
    U64 phone_space = 0, card_space = 0;
    FS_DiskInfo DiskInfo;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_HIDDEN_FOLDER);

	#ifndef J2ME_SLIM_MEMORY_SUPPORT
    phone_drive = SRV_FMGR_PUBLIC_DRV; 
    if (phone_drive >= FS_NO_ERROR)
    {
        kal_wsprintf(pathname, "%c:\\", phone_drive); 
	    if (FS_GetDiskInfo(pathname, &DiskInfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= FS_NO_ERROR)
		{
			phone_space = (U64) DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
	    }
    }
	#endif/*J2ME_SLIM_MEMORY_SUPPORT */
        
    card_drive = SRV_FMGR_CARD_DRV; 
    if (card_drive >= FS_NO_ERROR)
    {
        kal_wsprintf(pathname, "%c:\\", card_drive); 
        if (FS_GetDiskInfo(pathname, &DiskInfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= FS_NO_ERROR)
        {
            card_space = (U64) DiskInfo.FreeClusters * DiskInfo.SectorsPerCluster* DiskInfo.BytesPerSector;
        }
    }

    /* Find max drive */
	#ifdef J2ME_SLIM_MEMORY_SUPPORT
	max_drive = card_drive;
	#else
    max_drive = (phone_space >= card_space) ? phone_drive : card_drive;
	#endif/*J2ME_SLIM_MEMORY_SUPPORT */

    /* Already find a drive */
    if(max_drive != -1)
    {
        kal_wsprintf(pathname, "%c:\\", max_drive); 
        mmi_ucs2cat((PS8) pathname, (PS8) L"@Java");
        /* Create @java folder if not exist */
        if (check_and_create_hidden_folder(pathname) == FS_NO_ERROR)
        {
            mmi_ucs2cat((PS8) pathname, (PS8) L"\\");
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  jma_video_player_encode_file_path_with_num
 * DESCRIPTION
 *  This function is used to encode either vm_id or java_player to PDL file_path
 * PARAMETERS
 *  file_path   [IN/OUT]
 *  value       [IN]
 *  buf         [IN]
 *  radix       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_encode_file_path_with_num(kal_wchar *file_path, kal_int32 value, kal_char *buf, kal_int32 radix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_ucs2_itoa(value, (kal_int8*)buf, radix);
    mmi_ucs2cat((PS8) file_path, (PS8) buf);
    mmi_ucs2cat((PS8) file_path, (PS8) L"_");    
}


#if defined (SUPPORT_MMAPI)
/*****************************************************************************
 * FUNCTION
 *  jma_video_player_reset_parameter
 * DESCRIPTION
 *  This function opens video file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_video_player_reset_parameter(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 current_vm_id;
    kal_int32 current_vm_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_RESET_PARAMETER, vm_id, video_player[vm_id].state);

    /* video_ctrl_struct */
    video_ctrl_info[vm_id].set_display_location = KAL_FALSE;
    video_ctrl_info[vm_id].set_display_size = KAL_FALSE;
    video_ctrl_info[vm_id].is_full_screen = KAL_FALSE;
    video_ctrl_info[vm_id].fullscreen_rotate = KAL_FALSE;
    video_ctrl_info[vm_id].is_visible = KAL_TRUE;
    video_ctrl_info[vm_id].offset_x = 0;
    video_ctrl_info[vm_id].offset_y = 0;
    video_ctrl_info[vm_id].width = 0;
    video_ctrl_info[vm_id].height = 0;
    video_ctrl_info[vm_id].region_x = 0;
    video_ctrl_info[vm_id].region_y = 0;
    video_ctrl_info[vm_id].region_width = 0;
    video_ctrl_info[vm_id].region_height = 0;

#if defined (SUPPORT_JSR_135_VIDEO) 
    /* jma_anima_info_struct */
    memset((kal_uint8 *) &anima_info, 0, sizeof(anima_info_struct) * JVM_NUM);
#endif /* defined (SUPPORT_JSR_135_VIDEO) */ 

    g_jma_is_bearer_deactivated[vm_id] = KAL_FALSE;

    /* video_player_struct */
    video_player[vm_id].id = INVALID_JPLAYER_ID;
    video_player[vm_id].device_type = JAVA_MEDIA_INVALID_DEVICE;      
    video_player[vm_id].duration = 0;
    video_player[vm_id].current_time = 0;
    video_player[vm_id].stoptime = (kal_int64)-1;
    video_player[vm_id].record_size_limit = -1;
    video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
    video_player[vm_id].prev_state = JAVA_MEDIA_STATE_NULL;
    video_player[vm_id].volume = DEFAULT_VIDEO_VOLUME;
    mmi_ucs2cpy((S8*) video_player[vm_id].filename, "");
    video_player[vm_id].buffer = NULL;
    video_player[vm_id].buffer_length = 0;
    video_player[vm_id].video_width = 0;
    video_player[vm_id].video_height = 0;
    video_player[vm_id].cache_handle = NULL;
    video_player[vm_id].progressive_dl = KAL_FALSE;

    video_player[vm_id].scr_mem_max_size = 0;
    
    video_player[vm_id].drm_id = -1;
    video_player[vm_id].drm_state = JAVA_DRM_STATE_NULL;
    video_player[vm_id].play_speed = 100;  /* Default speed */
    
    /* For streaming player */
    video_player[vm_id].stream_type = MDI_VIDEO_STREAM_RTSP_URL;
    video_player[vm_id].is_stream_opened = KAL_FALSE; 
    video_player[vm_id].is_seekable = KAL_FALSE;
    video_player[vm_id].seek_error = KAL_FALSE; 
    video_player[vm_id].is_double_buffer = KAL_FALSE;   
    video_player[vm_id].is_play_requested = KAL_FALSE; 
    video_player[vm_id].play_finish_time = 0;      
    video_player[vm_id].track = MDI_VIDEO_TRACK_NONE;
    mmi_ucs2cpy((S8*) video_player[vm_id].title_name, "");
    mmi_ucs2cpy(video_player[vm_id].title_desc, "");
    mmi_ucs2cpy(video_player[vm_id].author_desc, "");
    mmi_ucs2cpy(video_player[vm_id].copyright_desc, "");
    mmi_ucs2cpy(video_player[vm_id].date_desc, "");
    video_player[vm_id].need_redraw = KAL_FALSE;
#if defined (SUPPORT_JSR_135_VIDEO)     
    /* Animation player */
    anima_info[vm_id].delay_time = 0;
    anima_info[vm_id].current_frame = 0;
    anima_info[vm_id].start_tick = 0;
    anima_info[vm_id].current_tick = 0;
    anima_info[vm_id].frame_number = 0;    
    anima_info[vm_id].time_index = NULL;
    anima_info[vm_id].time_index_length = 0;
#endif /* defined (SUPPORT_JSR_135_VIDEO) */

    /* do not reset Global variable if fg video player active */
    current_vm_id = jam_mvm_get_current_vm_id();
    if (current_vm_id != INVALID_VM_ID && 
        current_vm_id != vm_id &&
        video_player[current_vm_id].device_type != JAVA_MEDIA_INVALID_DEVICE) 
    {
        current_vm_state = jam_mvm_get_vm_state(current_vm_id);
        if (current_vm_state == JVM_FG_RUNNING_STATE || current_vm_state == JVM_FG_MMI_RUNNING_STATE)
        {
            return;
        }
    }
    /* Global variable */
    preview_layer_handle = GDI_NULL_HANDLE;
    preview_buf_ptr = NULL;
    preview_buf_size = 0;    
}






/*****************************************************************************
 * FUNCTION
 *  jma_video_player_refine_display_info
 * DESCRIPTION
 * 
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_refine_display_info(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_REFINE_DISPLAY_INFO, vm_id, g_jui_screen_data[vm_id].screen_mode, video_ctrl_info[vm_id].set_display_location, video_ctrl_info[vm_id].set_display_size);

    /* if setDisplayLocation not invoked */
    if (video_ctrl_info[vm_id].set_display_location == KAL_FALSE)
    {
        video_ctrl_info[vm_id].offset_x = 0;
        if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
        {
            video_ctrl_info[vm_id].offset_y = 0;
        }
        else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
        {
            if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
            {
                video_ctrl_info[vm_id].offset_y = jui_widget_get_title_bar_height();
            }
            else
            {
                video_ctrl_info[vm_id].offset_y = 0;
            }
        /* Landscape: Title bar and status bar are merged together */
        //#ifndef __MMI_MAINLCD_320X240__
        #ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 80000);
            video_ctrl_info[vm_id].offset_y += MMI_status_bar_height;
        #endif
        }
    }

    /* if setDisplaySize not invoked */
    if (video_ctrl_info[vm_id].set_display_size == KAL_FALSE)
    {
        video_ctrl_info[vm_id].width  = LCD_WIDTH - 1;
        if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
        {
            video_ctrl_info[vm_id].height = LCD_HEIGHT - 1;
        }
        else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
        {
            if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
            {
                video_ctrl_info[vm_id].height = LCD_HEIGHT - 1 - jui_widget_get_title_bar_height() - MMI_button_bar_height;
                if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
                {
                    video_ctrl_info[vm_id].height -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
                }
            }
            else
            {
                video_ctrl_info[vm_id].height = LCD_HEIGHT - 1 - MMI_button_bar_height;
                if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
                {
                    video_ctrl_info[vm_id].height -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
                }
            }
        /* Landscape: Title bar and status bar are merged together */
        //#ifndef __MMI_MAINLCD_320X240__
        #ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
            video_ctrl_info[vm_id].height -= MMI_status_bar_height;
        #endif    
        }
#ifndef MJPG_ENCODE
#ifdef SUPPORT_JSR_135_VIDEO
        if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
        {
            jma_video_recorder_adjust_record_size(&video_ctrl_info[vm_id].width, &video_ctrl_info[vm_id].height);
        }
#endif /* SUPPORT_JSR_135_VIDEO */
#endif /* MJPG_ENCODE */
    }

    /* GIF display size is the same as image dimension */
    if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {
        video_ctrl_info[vm_id].width = video_player[vm_id].video_width;
        video_ctrl_info[vm_id].height = video_player[vm_id].video_height;
        return;
    }
#ifdef MJPG_ENCODE    
    /* AVI Recorder: The encode size should be the same as preview size */
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        video_ctrl_info[vm_id].width = 176;
        video_ctrl_info[vm_id].height = 144;
        return;    
    }
#endif /* MJPG_ENCODE */  
        
  
    /* Camera layer width and height can not be odd */
    if (video_ctrl_info[vm_id].width % 2 != 0)
    {
        video_ctrl_info[vm_id].width += 1;
    }
    if (video_ctrl_info[vm_id].height % 2 != 0)
    {
        video_ctrl_info[vm_id].height += 1;
    }

    if (video_ctrl_info[vm_id].offset_x % 2 != 0)
    {
        video_ctrl_info[vm_id].offset_x += 1;
    }
    if (video_ctrl_info[vm_id].offset_y % 2 != 0)
    {
        video_ctrl_info[vm_id].offset_y += 1;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, video_ctrl_info[vm_id].offset_x, video_ctrl_info[vm_id].offset_y, 
            video_ctrl_info[vm_id].width, video_ctrl_info[vm_id].height);
    if (video_ctrl_info[vm_id].width <= 0 || video_ctrl_info[vm_id].height <= 0)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_display_roi
 * DESCRIPTION
 *  This function gets roi region
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  width       [IN]
 *  height      [IN]
 *  preview_data[OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_config_roi(kal_int32 vm_id, kal_int32 x, kal_int32 y, kal_int32 width, kal_int32 height) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 v_x1, v_y1, v_x2, v_y2; /* valid display region: LCD coordinate */
    S32 c_x1, c_y1, c_x2, c_y2; /* cliped layer: LCD coordinate */
    kal_bool rotation = KAL_FALSE; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_CONFIG_ROI, vm_id, x, y, width, height);
/*
#if defined(HORIZONTAL_CAMERA)  && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__)
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        rotation = KAL_TRUE;
    }
#endif 

#if defined(HORIZONTAL_CAMERA) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__) 
    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        rotation = KAL_TRUE;
    }
#endif
*/
    /* Not IDP rotate */

    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)        
    {
        if (video_ctrl_info[vm_id].fullscreen_rotate)
        {
            rotation = KAL_TRUE;
        }
    }
  
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, 
              rotation, 
              g_jui_screen_data[vm_id].screen_mode,
              jui_widget_mvm_is_support_virtual_keypad(vm_id),
              jui_widget_mvm_get_virtual_keypad_height(vm_id));
    if (rotation == KAL_FALSE)
    {
        v_x1 = 0;
        v_x2 = LCD_WIDTH;
        v_y1 = v_y2 = 0;   
        if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
        {
            v_y1 = 0;
            v_y2 = LCD_HEIGHT;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                v_y2 -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
        }
        else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
        {
            v_y2 = LCD_HEIGHT - MMI_button_bar_height;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                v_y2 -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
            if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
            {
                v_y1 = jui_widget_get_title_bar_height();
            }
            else
            {
                v_y1 = 0;
            }
        /* Landscape: Title bar and status bar are merged together */
        //#ifndef __MMI_MAINLCD_320X240__
		#ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
            v_y1 += MMI_status_bar_height;
        #endif    
        }
    }
    else
    {
        v_y1 = 0;
        v_y2 = LCD_WIDTH;
        v_x1 = v_x2 = 0;
        if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
        {
            v_x1 = 0;
            v_x2 = LCD_HEIGHT;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                v_x2 -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
        }
        else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
        {
            v_x2 = LCD_HEIGHT - MMI_button_bar_height;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                v_x2 -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
            if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
            {
                v_x1 = jui_widget_get_title_bar_height();
            }
            else
            {
                v_x1 = 0;
            }
        /* Landscape: Title bar and status bar are merged together */
        //#ifndef __MMI_MAINLCD_320X240__
		#ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
            v_x1 += MMI_status_bar_height;
        #endif    
        }
    }
 
    /* Initialize cliped region to original layer */
    c_x1 = x;
    c_y1 = y;
    c_x2 = x + width;
    c_y2 = y + height;
    EXT_ASSERT(c_x1 < c_x2 || c_y1 < c_y2, 0, 0, 0);

    /* layer is in invalid region */
    if ( c_x2 < v_x1 ||  c_y2 < v_y1 || c_x1 > v_x2 || c_y1 > v_y2)
    {
        /* Set clip */
        gdi_layer_push_and_set_active(preview_layer_handle);
        //gdi_layer_set_clip(0, 0, 0, 0);
        
        gdi_layer_set_blt_rect(0, 0, 0, 0);
        gdi_layer_pop_and_restore_active();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, 0, 0, 0, 0);
    }
    else
    {
        /* Get clipped region in LCD coordinate */
        /*c_x1 = (c_x1 < v_x1) ? v_x1 : c_x1;
        c_y1 = (c_y1 < v_y1) ? v_y1 : c_y1;        
        c_x2 = (c_x2 > v_x2) ? v_x2 : c_x2;
        c_y2 = (c_y2 > v_y2) ? v_y2 : c_y2;*/
        /*do not config ROI cooridinate here*/

        /* Get clipped retion in Layer coordinate */
        c_x1 -= x;
        c_y1 -= y;
        c_x2 -= x;
        c_y2 -= y;
        
        /* Set clip */
        gdi_layer_push_and_set_active(preview_layer_handle);
        //gdi_layer_set_clip(c_x1, c_y1, c_x2, c_y2);
        
        gdi_layer_set_blt_rect(c_x1, c_y1, c_x2 - c_x1 + 1, c_y2 - c_y1 + 1);
        gdi_layer_pop_and_restore_active();
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, c_x1, c_y1, c_x2, c_y2);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_display_full_screen
 * DESCRIPTION
 *  function to be called to get full screen's offset_x, offset_y, width, height
 *  The function only be called if is_full_screen == KAL_TRUE
 * PARAMETERS
 *  x             [OUT]        
 *  y             [OUT]        
 *  width         [OUT]       
 *  height        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_get_display_full_screen(kal_int32 vm_id, kal_int32 *x, kal_int32 *y, kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_DISPLAY_FULL_SCREEN, vm_id);
    *x = 0;
    *width = LCD_WIDTH;
    if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
    {
        *y = 0;
        *height = LCD_HEIGHT;
        if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
        {
            *height -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
        }
    }
    else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
    {
        if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
        {
            *y = jui_widget_get_title_bar_height();
            *height = LCD_HEIGHT - jui_widget_get_title_bar_height() - MMI_button_bar_height;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                *height -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
        }
        else
        {
            *y = 0;
            *height = LCD_HEIGHT - MMI_button_bar_height;
            if (jui_widget_mvm_is_support_virtual_keypad(vm_id))
            {
                *height -= jui_widget_mvm_get_virtual_keypad_height(vm_id);
            }
        }
    /* Landscape: Title bar and status bar are merged together */
    //#ifndef __MMI_MAINLCD_320X240__
	#ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
        *y += MMI_status_bar_height;
        *height -= MMI_status_bar_height;   
    #endif    
    }

#ifndef MJPG_ENCODE
#ifdef SUPPORT_JSR_135_VIDEO

    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        jma_video_recorder_adjust_record_size(width, height);
    }
#endif
#endif /* MJPG_ENCODE */   

    /* Camera layer width and height can not be odd */
    if (*width % 2 != 0)
    {
        *width += 1;
    }
    if (*height % 2 != 0)
    {
        *height += 1;
    }

    /* GIF display size is the same as image dimension */
    if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {
        *width = video_player[vm_id].video_width;       
        *height = video_player[vm_id].video_height;
    }
#ifdef MJPG_ENCODE 
    /* AVI Recorder: The encode size should be the same as preview size */
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        *width = 176;
        *height = 144;
    }
#endif /* MJPG_ENCODE */   
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, (*x), (*y), (*width), (*height));
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_update_video_region
 * DESCRIPTION
 *  function to update region
 * PARAMETERS
 *  x1      [OUT]        
 *  y1      [OUT]        
 *  x2      [OUT]       
 *  y2      [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_update_video_region(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height, layer_x, layer_y;
    U8 rotate; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get parameter */
    gdi_layer_push_and_set_active(preview_layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_x, &layer_y);
    rotate = gdi_layer_get_rotate();
    gdi_layer_pop_and_restore_active();

    /* Origin: Top-left corner of LCD */
    if (rotate == LCD_LAYER_ROTATE_NORMAL)
    {
        video_ctrl_info[vm_id].region_x = layer_x;
        video_ctrl_info[vm_id].region_y = layer_y;
        video_ctrl_info[vm_id].region_width = layer_width;
        video_ctrl_info[vm_id].region_height = layer_height;
    }
    else
    {
        video_ctrl_info[vm_id].region_x = LCD_WIDTH - layer_y - layer_height;
        video_ctrl_info[vm_id].region_y = layer_x;
        video_ctrl_info[vm_id].region_width = layer_height;
        video_ctrl_info[vm_id].region_height = layer_width;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_redraw_video_region
 * DESCRIPTION
 *  function to redraw region
 * PARAMETERS
 *  x1      [OUT]        
 *  y1      [OUT]        
 *  x2      [OUT]       
 *  y2      [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_video_player_redraw_video_region(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 origin_y = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
    {
    /* Landscape: Title bar and status bar are merged together */
    //#ifndef __MMI_MAINLCD_320X240__
	#ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
        origin_y += MMI_status_bar_height;
    #endif    
    }        

    jui_widget_mvm_refresh_screen(
        video_ctrl_info[vm_id].region_x, 
        video_ctrl_info[vm_id].region_y - origin_y, 
        video_ctrl_info[vm_id].region_x + video_ctrl_info[vm_id].region_width - 1,
        video_ctrl_info[vm_id].region_y - origin_y + video_ctrl_info[vm_id].region_height - 1,
        vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_update_blt_flag
 * DESCRIPTION
 *  This function is to update visibility
 * PARAMETERS
 *  native_layer                [IN]        
 * RETURNS
 *  true if success.
 *****************************************************************************/
kal_bool jma_video_player_update_blt_flag(kal_int32 vm_id, java_video_blt_param blt_param)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (jam_mvm_get_vm_state(vm_id) == JVM_FG_MMI_RUNNING_STATE)
    {
        visible = KAL_FALSE;
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_3;
        /* Notify LCD the hw layer's parameters */
        jui_widget_set_hardware_layer(
            preview_layer_handle, preview_layer_flag, &blt_layer_flag);
        /* Avoid hw layer be blted out by MMI 
         * This would not cause hw layer's parameter cleaned */
        jui_widget_set_hardware_layer(NULL, 0, NULL);
    }
    else
    {
        visible = video_ctrl_info[vm_id].is_visible;
        preview_layer_flag = (visible) ? GDI_LAYER_ENABLE_LAYER_1 : GDI_LAYER_ENABLE_LAYER_0;

        jui_widget_set_hardware_layer(
            preview_layer_handle, preview_layer_flag, &blt_layer_flag);

        if (blt_param == JMA_FORCE_BLT || 
            (video_ctrl_info[vm_id].is_visible == KAL_FALSE && 
             blt_param != JMA_FORCE_NO_BLT))
        {
            if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE)
            {       
                jma_video_player_redraw_video_region(vm_id);
            }
            else
            {
                jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
            }
        }
    }
    
    return visible;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_process_layer
 * DESCRIPTION
 *  This function handles video layer
 * PARAMETERS
 *  native_layer                [IN]        
 * RETURNS
 *  true if success.
 *****************************************************************************/
kal_bool jma_video_player_process_layer(kal_int32 vm_id)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 adjusted_x = 0, adjusted_y = 0, adjusted_width = 0, adjusted_height = 0;
    S32 disp_x, disp_y, disp_width, disp_height;
    S32 layer_width, layer_height;
    S32 origin_x, origin_y;
    //S32 dummy;

    mdi_util_create_hw_layer_extmemory_in_struct play_layer_in;
    mdi_util_create_hw_layer_out_struct play_layer_out;
    kal_bool is_empty = KAL_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_PROCESS_LAYER, vm_id, preview_layer_handle, preview_buf_ptr);

    if (video_ctrl_info[vm_id].is_full_screen == KAL_TRUE)
    {
        jma_video_player_get_display_full_screen(vm_id, &disp_x, &disp_y, &disp_width, &disp_height);
    }
    else
    {
        disp_x = video_ctrl_info[vm_id].offset_x;
        disp_y = video_ctrl_info[vm_id].offset_y;
        disp_width = video_ctrl_info[vm_id].width;
        disp_height = video_ctrl_info[vm_id].height;
    }

    EXT_ASSERT(disp_width != 0 && disp_height != 0, 0, 0, 0);
    
    /* Calculate layer width and layer height */
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {        
        if (video_ctrl_info[vm_id].is_full_screen == KAL_TRUE)
        {
            if ((video_player[vm_id].video_height > video_player[vm_id].video_width && disp_height < disp_width) ||
                (video_player[vm_id].video_height < video_player[vm_id].video_width && disp_height > disp_width))
            {
                video_ctrl_info[vm_id].fullscreen_rotate = KAL_TRUE;
            }
            else
            {
                video_ctrl_info[vm_id].fullscreen_rotate = KAL_FALSE;
            }
        }
        else
        {
            video_ctrl_info[vm_id].fullscreen_rotate = KAL_FALSE;
        }
          
        if (video_ctrl_info[vm_id].fullscreen_rotate == KAL_TRUE) 
        {
            /* Maintain: the ratio of height to width */
            if (video_player[vm_id].video_width * disp_width > video_player[vm_id].video_height * disp_height)
            {
                adjusted_width = disp_height;
            #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
                adjusted_height = disp_width;
            #else
                adjusted_height = video_player[vm_id].video_height * disp_height / video_player[vm_id].video_width;
            #endif
                if (adjusted_height % 2 != 0)
                {
                    adjusted_height ++;
                }
            }
            else
            {
            #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
                adjusted_width = disp_height;
            #else
                adjusted_width = video_player[vm_id].video_width * disp_width / video_player[vm_id].video_height;
            #endif
                adjusted_height = disp_width;
                if (adjusted_width % 2 != 0)
                {
                    adjusted_width ++;
                }
            }
            adjusted_x = disp_y;
            adjusted_y = GDI_LCD_WIDTH - disp_x - adjusted_height;  
        }
        else          
        {
            adjusted_x = disp_x;
            adjusted_y = disp_y;
            EXT_ASSERT(video_player[vm_id].video_height != 0 && video_player[vm_id].video_width != 0, 0, 0, 0);

            /* Maintain: the ratio of height to width */
            if (video_player[vm_id].video_width * disp_height > video_player[vm_id].video_height * disp_width)
            {
                adjusted_width = disp_width;
            #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
                adjusted_height = disp_height;
            #else
                adjusted_height = video_player[vm_id].video_height * disp_width / video_player[vm_id].video_width;
            #endif
                if (adjusted_height % 2 != 0)
                {
                    adjusted_height ++;
                }
            }
            else
            {
            #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
                adjusted_width = disp_width;
            #else
                adjusted_width = video_player[vm_id].video_width * disp_height / video_player[vm_id].video_height;
            #endif
                adjusted_height = disp_height;
                if (adjusted_width % 2 != 0)
                {
                    adjusted_width ++;
                }
            }  
        }
        if (adjusted_width <= 0 || adjusted_height <= 0)
        {
            return KAL_FALSE;
        }
        play_layer_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
    }
    else if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        adjusted_x = disp_x;
        adjusted_y = disp_y;
        adjusted_width = disp_width;
        adjusted_height = disp_height;
        play_layer_in.scenario_id = MDI_MULTIMEDIA_CAMERA;
    } 
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        /* If horizontal camera, need rotate layer */        
        #if defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__)
            adjusted_x = disp_y;
            adjusted_y = GDI_LCD_WIDTH - disp_x - disp_width;
            adjusted_width = disp_height;
            adjusted_height = disp_width;
        #else /* defined(HORIZONTAL_CAMERA) */
            adjusted_x = disp_x;
            adjusted_y = disp_y;
            adjusted_width = disp_width;
            adjusted_height = disp_height;
        #endif /* defined(HORIZONTAL_CAMERA) */
        play_layer_in.scenario_id = MDI_MULTIMEDIA_RRECORD;
    }    
    else
    {
        EXT_ASSERT(0, 0, 0, 0);
    }
 
    /* Release the previous layer and clear handle if size is not the same */
    if (preview_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(preview_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_pop_and_restore_active();
        if (adjusted_width != layer_width || adjusted_height != layer_height)
        {
            jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
            jma_video_player_redraw_video_region(vm_id);
            
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_NULL_HANDLE;
            if (preview_buf_ptr)
            {
                jma_video_free_preveiw_layer_buffer(vm_id);
            }
        }
        else
        {
            is_empty = KAL_FALSE;
        }

    }
    if (is_empty == KAL_TRUE)
    {
        EXT_ASSERT(preview_buf_ptr == NULL, 0, 0, 0);
        /* layer size is not the same as previous one, so needs to create a new one */
        preview_buf_size = (((adjusted_width * adjusted_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3) + 15) / 16 * 16;
#ifdef __COSMOS_MMI_PACKAGE__
        preview_buf_ptr = (kal_uint16 *) mmi_frm_asm_alloc_nc_r(jma_app_id(vm_id), preview_buf_size);
#else
        preview_buf_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_JAVA,preview_buf_size);
#endif /* __COSMOS_MMI_PACKAGE__ */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_ALLOCATE_SCR_MEMORY, preview_buf_ptr, preview_buf_size);
        if (preview_buf_ptr == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
        if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
        {
            gdi_layer_create_using_outside_memory(
                adjusted_x, adjusted_y, adjusted_width, adjusted_height,
                &preview_layer_handle,
                (PU8) preview_buf_ptr, (S32) preview_buf_size);

            gdi_layer_push_and_set_active(preview_layer_handle);
            gdi_layer_clear_background(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }
        else 
        {
            play_layer_in.buffer = (U8 *)preview_buf_ptr;
            play_layer_in.buffer_size = preview_buf_size;
            play_layer_in.width = adjusted_width;
            play_layer_in.height = adjusted_height;
            play_layer_in.offset_x = adjusted_x;
            play_layer_in.offset_y = adjusted_y;
            preview_layer_handle = mdi_util_hw_layer_create_with_extmemory(&play_layer_in, &play_layer_out);
            gdi_layer_push_and_set_active(preview_layer_handle);
            gdi_layer_clear_background(GDI_COLOR_BLACK);
            if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
            {        
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
            }
       #if defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
       
            if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
            {        
        #if defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__)
                gdi_layer_set_rotate(LCD_LAYER_ROTATE_90);
                gdi_lcd_set_rotate_by_layer(KAL_TRUE);
        #elif defined(HORIZONTAL_CAMERA) && defined(__MDI_VIDEO_HW_ROTATOR_SUPPORT__) 
                //mdi_video_set_hw_rotator(MDI_VIDEO_LCD_ROTATE_90);
        #endif /* defined(HORIZONTAL_CAMERA) */
            }
            
            if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
                video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE)
            {
                if (video_ctrl_info[vm_id].fullscreen_rotate == KAL_TRUE)
                {
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
                    gdi_lcd_set_rotate_by_layer(KAL_TRUE);
                }
                else
                {
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                }         
            }
        #endif /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */   
            gdi_layer_pop_and_restore_active();
        }
        jma_video_player_update_video_region(vm_id);

        /* Animation player can not setClip */
        if (video_player[vm_id].device_type != JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
        {
            jma_video_player_config_roi(vm_id, adjusted_x, adjusted_y, adjusted_width, adjusted_height); 
        }

        /* Config hardware layer */
        jma_video_player_update_blt_flag(vm_id, JMA_FORCE_NO_BLT);
    }
    else
    {
        /* layer size is the same, only needs to change layer position */
        gdi_layer_push_and_set_active(preview_layer_handle);
        gdi_layer_get_position(&origin_x, &origin_y);
        if (video_player[vm_id].device_type != JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
        {    
        #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
            gdi_layer_clear(GDI_COLOR_BLACK);
        #endif
        }
        gdi_layer_pop_and_restore_active();

        if (origin_x != adjusted_x || origin_y != adjusted_y)
        {
            /* Clear screen */
            jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
            jma_video_player_redraw_video_region(vm_id);
            /* Config hardware layer */
            jma_video_player_update_blt_flag(vm_id, JMA_FORCE_NO_BLT);
        }       
        
        /* layer size is the same, only needs to change layer position */
        gdi_layer_push_and_set_active(preview_layer_handle);
        gdi_layer_set_position(adjusted_x, adjusted_y);
        gdi_layer_pop_and_restore_active();

        /* Animation player can not setClip */
        if (video_player[vm_id].device_type != JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
        {
            jma_video_player_config_roi(vm_id, adjusted_x, adjusted_y, adjusted_width, adjusted_height); 
        }

        jma_video_player_update_video_region(vm_id);
    }
  
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_update_layer
 * DESCRIPTION
 *  function to update layer's location/size/visibility
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool jma_video_player_update_layer(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SUPPORT_JSR_135_VIDEO    
    if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {
        ret = jma_anima_player_refresh(vm_id, video_player[vm_id].id);
    }
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    else if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE)
    {
        ret = jma_cam_player_refresh(vm_id, video_player[vm_id].id);
    }
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */    
#if defined(__MMI_VIDEO_RECORDER__)  || defined(__MMI_CAMCORDER__)
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        ret = jma_video_recorder_refresh(vm_id, video_player[vm_id].id);
    }
#endif /* __MMI_VIDEO_RECORDER__ */  
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE)
    {
        ret = jma_mvm_video_player_refresh(vm_id, video_player[vm_id].id);
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE)
    {
        ret = jma_stream_player_refresh(vm_id, video_player[vm_id].id);
    }
#endif /* __MMI_VIDEO_STREAM__ */   
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    else
#endif /* SUPPORT_JSR_135_VIDEO */
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_update_is_title_displayed
 * DESCRIPTION
 *  The function only be invoked by jui_widget_set_title()
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_update_is_title_displayed(kal_int32 vm_id, kal_bool is_title_displayed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_UPDATE_IS_TITLE_DISPLAYED, vm_id, is_title_displayed);

    if (!g_jam_is_jvm_in_busy || video_player[vm_id].device_type == JAVA_MEDIA_INVALID_DEVICE)
    {
        return;
    }
    
    /* Pure audio */
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE)
    {
        if (video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
        {
            return;
        }        
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, 666, is_title_displayed, video_ctrl_info[vm_id].offset_y, jui_widget_get_title_bar_height());
    if (is_title_displayed)
    {
        video_ctrl_info[vm_id].offset_y += jui_widget_get_title_bar_height(); /* Title appears */
        /* if title bar is odd, it will cause offset_y increase by 2 when switch title state for times */
        if (video_ctrl_info[vm_id].offset_y % 2 != 0)
        {
            video_ctrl_info[vm_id].offset_y -= 1;
        }
    }
    else
    {
        video_ctrl_info[vm_id].offset_y -= jui_widget_get_title_bar_height(); /* Title disappears */
        /* if title bar is odd, it will cause offset_y increase by 2 when switch title state for times */
        if (video_ctrl_info[vm_id].offset_y % 2 != 0)
        {
            video_ctrl_info[vm_id].offset_y += 1;
        }
    }

    if (kal_get_active_module_id() == MOD_MMI)
    {
        return; /* MMI always wait in JMA_CS_ENTER() */
    }
    if (jam_mvm_get_vm_state(vm_id) != JVM_FG_RUNNING_STATE &&
        jam_mvm_get_vm_state(vm_id) != JVM_FG_MMI_RUNNING_STATE)
    {
        return;
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        return;
    }
//#endif /*__MMI_BACKGROUND_CALL__*/


    /* check dependency mutex first */
    do
    {
        if (jma_mutex_lock_no_wait(KAL_TRUE))
        {
            break;
        }
    } while (1);

    if (jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE))
    {
        jma_video_player_update_layer(vm_id);

        jma_media_player_cs_leave();
    }

    /* Remember to unlock the additional lock. */
    jma_media_player_dependency_mutex_unlock();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_reconfig_layer
 * DESCRIPTION
 *  The function only be invoked 
 *  when layer config is changed or screen mode is changed
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_player_reconfig_layer(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 shift;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_RECONFIG_LAYER, vm_id, g_jui_screen_data[vm_id].screen_mode);

    if (!g_jam_is_jvm_in_busy || video_player[vm_id].device_type == JAVA_MEDIA_INVALID_DEVICE)
    {
        return;
    }     

    /* Pure audio */
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE)
    {
        if (video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
        {
            return;
        }
    }

    shift = 0;
    if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
    {
        shift += jui_widget_get_title_bar_height();
    }
    /* Landscape: Title bar and status bar are merged together */
//#ifndef __MMI_MAINLCD_320X240__
#ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
    shift += MMI_status_bar_height;
#endif

    if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
    {
        video_ctrl_info[vm_id].offset_y -= shift;
    }
    else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
    {
        video_ctrl_info[vm_id].offset_y += shift;
    }    
    
    if (kal_get_active_module_id() == MOD_MMI)
    {
        return; /* MMI always wait in JMA_CS_ENTER() */
    }
    
    if (jam_mvm_get_vm_state(vm_id) != JVM_FG_RUNNING_STATE &&
        jam_mvm_get_vm_state(vm_id) != JVM_FG_MMI_RUNNING_STATE)
    {
        return;
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        return;
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    /* check dependency mutex first */
    do
    {
        if (jma_mutex_lock_no_wait(KAL_TRUE))
        {
            break;
        }
    } while (1);

    if (jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE))
    {
        jma_video_player_update_layer(vm_id);

        jma_media_player_cs_leave();
    }

    /* Remember to unlock the additional lock. */
    jma_media_player_dependency_mutex_unlock();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_is_visible
 * DESCRIPTION
 *  function to be called to query visibility
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_mvm_video_player_is_visible(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
    }
    return video_ctrl_info[vm_id].is_visible;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_visible
 * DESCRIPTION
 *  function to be called to set visibility
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  is_visible              [IN]        Is visible
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_set_visible(kal_int32 vm_id, kal_int32 java_player, kal_bool is_visible)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_VISIBLE, vm_id, java_player, video_player[vm_id].state, is_visible);
    JMA_CS_ENTER(vm_id, JMA_VOID);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    /* Pure audio: For protection. VM internal may set visible when canvas change. */
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_STREAM_PLAYER_DEVICE)
    {
        if (video_player[vm_id].track == MDI_VIDEO_TRACK_A_ONLY)
        {
            JMA_CS_LEAVE(JMA_VOID);
        }        
    }
    
    if (video_ctrl_info[vm_id].is_visible == is_visible)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
  
    video_ctrl_info[vm_id].is_visible = is_visible;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    ret = jma_video_player_update_layer(vm_id);
    if(1 == ret)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 114);
    }

    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_display_location
 * DESCRIPTION
 *  function to be called to set display width and height
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
void jma_mvm_video_player_set_display_location(kal_int32 vm_id, kal_int32 java_player, kal_int32 x, kal_int32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;
    kal_int32 offset_x, offset_y = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_DISPLAY_LOCATION, vm_id, java_player, video_player[vm_id].state, x, y);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }


    video_ctrl_info[vm_id].set_display_location = KAL_TRUE;

    offset_x = x;
    if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
    {
        offset_y = y;
    }
    else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
    {
        if (jui_widget_mvm_is_title_displayed(vm_id) == KAL_TRUE)
        {
            offset_y = y + jui_widget_get_title_bar_height();
        }
        else
        {
            offset_y = y;
        }
    /* Landscape: Title bar and status bar are merged together */
    //#ifndef __MMI_MAINLCD_320X240__
    #ifndef MMI_SHOW_STATUS_ICON_IN_TITLE
        offset_y += MMI_status_bar_height;
    #endif     
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, offset_x, offset_y);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, GDI_LAYER_X_MIN, GDI_LAYER_X_MAX, GDI_LAYER_Y_MIN, GDI_LAYER_Y_MAX);
    /* Clip to GDI accepted valid value */
    if (offset_x < GDI_LAYER_X_MIN)
    {
        offset_x = GDI_LAYER_X_MIN;
    }
    if (offset_y < GDI_LAYER_Y_MIN)
    {
        offset_y = GDI_LAYER_Y_MIN;
    }
    
    /* Clip to reasonable value */
    if (offset_x >= GDI_LAYER_X_MAX)
    {
        offset_x = GDI_LAYER_X_MAX;
    }
    if (offset_y >= GDI_LAYER_Y_MAX)
    {
        offset_y = GDI_LAYER_Y_MAX;
    }
    
    if (offset_x % 2 != 0)
    {
        offset_x += 1;
    }
    if (offset_y % 2 != 0)
    {
        offset_y += 1;
    }

    /* Location is the same */
    if (video_ctrl_info[vm_id].offset_x == offset_x && video_ctrl_info[vm_id].offset_y == offset_y)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, 
            video_ctrl_info[vm_id].offset_x, offset_x, video_ctrl_info[vm_id].offset_y, offset_y);
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    video_ctrl_info[vm_id].offset_x = offset_x;
    video_ctrl_info[vm_id].offset_y = offset_y;
         
    /* If so, only save parameter, don't do anything */
    if (video_ctrl_info[vm_id].is_full_screen || !video_ctrl_info[vm_id].is_visible)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    ret = jma_video_player_update_layer(vm_id);
    if(1 == ret)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 115);
    }
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_display_size
 * DESCRIPTION
 *  function to be called to set display width and height
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
kal_bool jma_mvm_video_player_set_display_size(kal_int32 vm_id, kal_int32 java_player, kal_int32 width, kal_int32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;
    kal_uint32 size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_DISPLAY_SIZE, vm_id, java_player, video_player[vm_id].state, width, height);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, video_ctrl_info[vm_id].width, video_ctrl_info[vm_id].height);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(KAL_FALSE); /* GIF Player does not support resize */
    }
#ifdef MJPG_ENCODE
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        JMA_CS_LEAVE(KAL_FALSE); /* AVI Recorder does not support resize */
    }
#endif /* MJPG_ENCODE */  
    

    /* Limit to LCD size */
    width = (width > LCD_WIDTH) ? LCD_WIDTH : width;
    height = (height > LCD_HEIGHT) ? LCD_HEIGHT : height;

    /* Camera limitation: Can't be too small */
#if defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__)
    width = (width < 96) ? 96 : width;
    height = (height < 128) ? 128 : height;
#else /* defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__) */
    width = (width < 128) ? 128 : width;
    height = (height < 96) ? 96 : height;
#endif /* defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__) */

#ifndef MJPG_ENCODE
#ifdef SUPPORT_JSR_135_VIDEO
    if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        jma_video_recorder_adjust_record_size(&width, &height);
    }
#endif
#endif

    size = (((width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3) + 15) / 16 * 16;

    if (size > video_player[vm_id].scr_mem_max_size)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, size, video_player[vm_id].scr_mem_max_size);
        JMA_CS_LEAVE(KAL_TRUE);
    }

    video_ctrl_info[vm_id].set_display_size = KAL_TRUE;

    /* Size is the same */
    if (video_ctrl_info[vm_id].width == width && video_ctrl_info[vm_id].height == height)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, 
            video_ctrl_info[vm_id].width, width, video_ctrl_info[vm_id].height, height);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    video_ctrl_info[vm_id].width = width;
    video_ctrl_info[vm_id].height = height;

    /* If so, only save parameter, don't do anything */    
    if (video_ctrl_info[vm_id].is_full_screen || !video_ctrl_info[vm_id].is_visible)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_TRUE);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    ret = jma_video_player_update_layer(vm_id);
    JMA_CS_LEAVE(ret);    
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_display_full_screen
 * DESCRIPTION
 *  function to be called to set/unset full screen
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  is_full_screen          [IN]        Is full screen
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_player_set_display_full_screen(kal_int32 vm_id, kal_int32 java_player, kal_bool is_full_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_SET_DISPLAY_FULL_SCR, vm_id, java_player, video_player[vm_id].state, is_full_screen);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(JMA_VOID);
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_ANIMA_PLAYER_DEVICE)
    {
        JMA_CS_LEAVE(JMA_VOID); /* GIF Player does not support resize */
    }
#ifdef MJPG_ENCODE
    else if (video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        JMA_CS_LEAVE(JMA_VOID); /* AVI Recorder does not support resize */
    }
#endif /* MJPG_ENCODE */    
    
    
    if (video_ctrl_info[vm_id].is_full_screen == is_full_screen)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    video_ctrl_info[vm_id].is_full_screen = is_full_screen;


    /* If so, only save parameter, don't do anything */
    if (!video_ctrl_info[vm_id].is_visible)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);        
    }
//#endif /*__MMI_BACKGROUND_CALL__*/

    ret = jma_video_player_update_layer(vm_id);    
    if(KAL_FALSE == ret)
	{
		kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
	}

    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_source_width
 * DESCRIPTION
 *  function to be called to get source width
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  width of mpeg4 source.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_source_width(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 src_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_SRC_WIDTH, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        src_width = jma_mvm_video_player_get_display_width(vm_id, java_player);       
    }
    else
    {
        src_width = video_player[vm_id].video_width;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, src_width);
    return src_width;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_source_height
 * DESCRIPTION
 *  function to be called to get source height
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  height of mpeg4 source.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_source_height(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 src_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_SRC_HEIGHT, vm_id, java_player, video_player[vm_id].state);

    /* Check if java_player id is valid */
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    if (video_player[vm_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE ||
        video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
    {
        src_height = jma_mvm_video_player_get_display_height(vm_id, java_player);       
    }
    else
    {
        src_height = video_player[vm_id].video_height;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, src_height);
    return src_height;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_display_width
 * DESCRIPTION
 *  function to be called to get source width
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  width of mpeg4 source.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_display_width(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x, y, width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_DISPLAY_WIDTH, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }

    if (video_ctrl_info[vm_id].is_full_screen == KAL_TRUE)
    {
        jma_video_player_get_display_full_screen(vm_id, &x, &y, &width, &height);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, width);
        return width;
    }
    else
    {
        
        jma_video_player_refine_display_info(vm_id);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_ctrl_info[vm_id].width);
        return video_ctrl_info[vm_id].width;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_get_display_height
 * DESCRIPTION
 *  function to be called to get source height
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  height of mpeg4 source.
 *****************************************************************************/
kal_int32 jma_mvm_video_player_get_display_height(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x, y, width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_PLAYER_GET_DISPLAY_HEIGHT, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return 0;
    }
    
    if (video_ctrl_info[vm_id].is_full_screen == KAL_TRUE)
    {
        jma_video_player_get_display_full_screen(vm_id, &x, &y, &width, &height);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, height);
        return height;
    }
    else
    {
        /* Cannot return offset_x, offset_y. JAL coordinate is different from JAVA */
        jma_video_player_refine_display_info(vm_id);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_ctrl_info[vm_id].height);
        return video_ctrl_info[vm_id].height;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_get_active_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  app_id
 *****************************************************************************/
kal_uint16 jma_video_get_active_app_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_state;
    kal_bool is_pluto_scr = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_GET_ACTIVE_APP_ID, vm_id);
    vm_state = jam_mvm_get_vm_state(vm_id);
    is_pluto_scr = jam_is_enter_fg_mmi_pluto_screen();
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, vm_state, JAVA_APP_ID_COSMOS, JAVA_APP_ID_PLUTO, is_pluto_scr);
    
    if (JVM_FG_MMI_RUNNING_STATE == vm_state && !is_pluto_scr)
    {
        g_active_app_id = JAVA_APP_ID_COSMOS;
    }
    else
    {
        g_active_app_id = JAVA_APP_ID_PLUTO;
    }
    return g_active_app_id;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_free_preveiw_layer_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_free_preveiw_layer_buffer(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 vm_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(preview_buf_ptr != NULL, 0, 0, 0);
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_asm_free_r(g_active_app_id, preview_buf_ptr);
#else
    applib_mem_ap_free(preview_buf_ptr);
#endif
    preview_buf_ptr = NULL;
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RELEASE_SCR_MEMORY);
}

#else
void jma_mvm_video_player_set_visible(kal_int32 vm_id, kal_int32 java_player, kal_bool is_visible){}
void jma_mvm_video_player_set_display_location(kal_int32 vm_id, kal_int32 java_player, kal_int32 x, kal_int32 y){}
kal_bool jma_mvm_video_player_set_display_size(kal_int32 vm_id, kal_int32 java_player, kal_int32 width, kal_int32 height){return KAL_FALSE;}
void jma_mvm_video_player_set_display_full_screen(kal_int32 vm_id, kal_int32 java_player, kal_bool is_full_screen){}
kal_int32 jma_mvm_video_player_get_source_width(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_get_source_height(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_get_display_width(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_int32 jma_mvm_video_player_get_display_height(kal_int32 vm_id, kal_int32 java_player){return 0;}
kal_uint16 jma_video_get_active_app_id(kal_int32 vm_id){return 0;}
void jma_video_free_preveiw_layer_buffer(kal_int32 vm_id){}
#endif /* SUPPORT_MMAPI */

