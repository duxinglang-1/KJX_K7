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
 *   jma_cam_player.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * @(#)jma_cam_player.c  1.00 05/12/07
 *
 * Copyright (c) 2005 MediaTek Inc. All rights reserved.
 */

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "jma_interface.h"
#include "jma_internal.h"

/*************************************************************************
 * bluetooth headers
 *************************************************************************/
#ifdef __MMI_BT_SUPPORT__
    #include "BTMMIObexGprots.h"
#endif

/*****************************************************************************
 * Global Definition and Declaration
*****************************************************************************/
#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__))

/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_finalize
 * DESCRIPTION
 *  This function is camera close handler invoked when finalizeResoueceMgr executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
static void jma_cam_player_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_state; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_state = jam_mvm_get_vm_state(vm_id);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, vm_state);
    if (vm_state == JVM_FG_RUNNING_STATE || vm_state == JVM_FG_MMI_RUNNING_STATE)
    {
        /* free layers */
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
            jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
            
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
 *  jma_cam_player_suspend_hdlr
 * DESCRIPTION
 *  This function handles before suspend
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int - result
 *****************************************************************************/
kal_int32 jma_cam_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_SUSPEND_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }


    /* Avoid data abort when release screen memory */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        //ASSERT(preview_layer_handle != GDI_LAYER_EMPTY_HANDLE);
        if((preview_layer_handle != GDI_LAYER_EMPTY_HANDLE))
        {
            mdi_camera_preview_stop();
            mdi_camera_power_off();
        }
		else
		{
		    video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
		    mdi_camera_power_off();
		}
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_camera_power_off();
    }

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);
#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();
#endif   
    jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
    jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);

    /* free layers */
    if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(preview_layer_handle);
        preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

        jma_video_free_preveiw_layer_buffer(vm_id);
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
 *  jma_cam_player_resume_hdlr
 * DESCRIPTION
 *  This function is camera resume handler invoked when resumeAudio executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_cam_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_RESUME_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }
    
    /* Backlight control */
    jvm_force_backlight_on(KAL_TRUE);

    if (!video_player[vm_id].is_double_buffer)
    {
        /* Start double buffer when resume video */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;    
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_camera_set_camera_id(MDI_CAMERA_MAIN);
        ms = mdi_camera_power_on(JAVA_APP_ID_MED);
        if (ms == MDI_RES_CAMERA_SUCCEED)
        {
            ret = KAL_TRUE;
        }
		/* MAUI_03183568 wenmin begin */
		else
		{
		    video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
		}
		/* MAUI_03183568 wenmin end */
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        mdi_camera_set_camera_id(MDI_CAMERA_MAIN);
        ms = mdi_camera_power_on(JAVA_APP_ID_MED);
        if (ms == MDI_RES_CAMERA_SUCCEED)
        {
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            ret = jma_mvm_cam_player_preview_start(vm_id, MMA_TYPE_CAM, video_player[vm_id].id);

            if (ret == KAL_FALSE)
            {
                ms = mdi_camera_power_off();
                if (video_player[vm_id].is_double_buffer)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
                    jui_widget_stop_double_buffer();
                    video_player[vm_id].is_double_buffer = KAL_FALSE;
                }
                jma_video_player_reset_parameter(vm_id);

                jma_deregister_device(JAVA_MEDIA_CAM_PLAYER_DEVICE, vm_id, java_player);
                /* Backlight control */
                jvm_force_backlight_on(KAL_FALSE);
            }
        }
		/* MAUI_03183568 wenmin begin */
		else
		{
		    video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
		}
		/* MAUI_03183568 wenmin end */
    }
    
    if (ret == KAL_TRUE)
    {
    #ifdef __MMI_BT_SUPPORT__
        mmi_bt_disable_receiving();
    #endif  
        JMA_CS_LEAVE(RESOUCE_NO_ERROR);
    }
    else
    {
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_close_hdlr
 * DESCRIPTION
 *  This function is camera close handler invoked when finalizeResoueceMgr executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_cam_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_CLOSE_HDLR, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    if (!is_vm_suspend_media[vm_id])
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            ret = jma_mvm_cam_player_preview_stop(vm_id, MMA_TYPE_MPEG, java_player);
			if(KAL_FALSE == ret)
			{
			     kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 555);
			}
            ms = mdi_camera_power_off();
			if(0 == ms)
			{
			     kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
			}
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            ms = mdi_camera_power_off();
			if(0 == ms)
			{
			     kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 777);
			}
        }
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);
    #ifdef __MMI_BT_SUPPORT__
        mmi_bt_enable_receiving();
    #endif
    }

    jma_deregister_device(video_player[vm_id].device_type, vm_id, java_player);
    jma_cam_player_finalize(vm_id);

    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_open
 * DESCRIPTION
 *  function to be called to power on camera
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_mvm_cam_player_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    kal_int8 audio_state = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_CAM_PLAYER_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    /* Check if Bluetooth is in use now */
#ifdef __MMI_BT_SUPPORT__
    if (mmi_bt_is_receiving())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, -1);
        JMA_CS_LEAVE(KAL_FALSE);
    }
#endif

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */    

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

#ifdef __MMI_BT_SUPPORT__
        mmi_bt_disable_receiving();
#endif
        mdi_camera_set_camera_id(MDI_CAMERA_MAIN);
        ret = mdi_camera_power_on(JAVA_APP_ID_MED);
        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
            jui_widget_start_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_TRUE;            
        }
        else
        {
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);

            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;

        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_CAM_PLAYER_DEVICE,
            vm_id,
            java_player, 
            &jma_cam_player_suspend_hdlr, 
            &jma_cam_player_resume_hdlr, 
            &jma_cam_player_close_hdlr);
        
        video_player[vm_id].id = java_player;
        video_player[vm_id].device_type = JAVA_MEDIA_CAM_PLAYER_DEVICE;
        video_player[vm_id].scr_mem_max_size = JMA_VDOPLY_LAYER_BUFFER_SIZE;
    }
    
    JMA_CS_LEAVE(KAL_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_close
 * DESCRIPTION
 *  function to be called to power off camera
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_mvm_cam_player_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    MDI_RESULT ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_CAM_PLAYER_CLOSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    jma_deregister_device(JAVA_MEDIA_CAM_PLAYER_DEVICE, vm_id, java_player);
    
    /* If vm does not at FG/FG_MMI state, finalize it */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        jma_cam_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        jma_cam_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        ret = jma_mvm_cam_player_preview_stop(vm_id, mma_type, java_player);
		if(1 == ret)
	    {
	        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 220);
	    }
        ms = mdi_camera_power_off();
		if(1 == ms)
	    {
	        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 330);
	    }
		
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        ms = mdi_camera_power_off();
		if(1 == ms)
	    {
	        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 440);
	    }
    }

    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();
#endif
    
    jma_cam_player_finalize(vm_id);

#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_cam_player_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]         
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_cam_player_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_CLEAR_JMADATA, vm_id, mma_type, java_player);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;
    }

    jma_deregister_device(JAVA_MEDIA_CAM_PLAYER_DEVICE, vm_id, java_player);
    jma_cam_player_finalize(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_review_start
 * DESCRIPTION
 *  function to be called to start preview
 * PARAMETERS
 *  void
 *  int mma_type(?)
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_mvm_cam_player_preview_start(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    kal_bool result;
    kal_int32 layer_width, layer_height;
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_CAM_PLAYER_PREVIEW_START, vm_id, java_player, video_player[vm_id].state);
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

    /* Once vm does not at FG/FG_MMI state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */     

    if (video_player[vm_id].state != JAVA_MEDIA_STATE_READY)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

    jma_video_player_refine_display_info(vm_id);
    result = jma_video_player_process_layer(vm_id);
    if (result == KAL_FALSE)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* get layer width and layer height */
    gdi_layer_push_and_set_active(preview_layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_pop_and_restore_active();
    
    mdi_camera_load_default_setting(&camera_setting_data);
    /* preview parametes */
    camera_setting_data.banding = MDI_VIDEO_BANDING_60HZ;
    camera_setting_data.flash = MDI_CAMERA_FLASH_OFF;
//    camera_setting_data.osd_rotate = 0;

/* #if defined(HORIZONTAL_CAMERA) && defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__)
    camera_setting_data.preview_width = layer_height;
    camera_setting_data.preview_height = layer_width;    
#else*/ /*  defined(HORIZONTAL_CAMERA) && defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__) */
    camera_setting_data.preview_width = layer_width;
    camera_setting_data.preview_height = layer_height;
//#endif /*  defined(HORIZONTAL_CAMERA) && defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__) */

#if defined(HORIZONTAL_CAMERA) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
//    mdi_camera_set_hw_rotator(MDI_CAMERA_PREVIEW_ROTATE_90);
#endif /*  defined(HORIZONTAL_CAMERA) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */

    camera_setting_data.image_width = layer_width;
    camera_setting_data.image_height = layer_height;

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
//    camera_setting_data.preview_rotate = J2ME_PREVIEW_MAINLCD_ROTATE; //MDI_CAMERA_PREVIEW_ROTATE_0;

#if defined(HORIZONTAL_CAMERA) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__)
//    camera_setting_data.lcm_rotate = MDI_CAMERA_LCM_ROTATE_270;
#else /* defined(HORIZONTAL_CAMERA) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__) */
//    camera_setting_data.lcm_rotate = MDI_CAMERA_LCM_ROTATE_0;
#endif /* defined(HORIZONTAL_CAMERA) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__) */
    camera_setting_data.xenon_flash_status_callback = NULL;   

    visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);       
    
    /* preview data for preview start */
    camera_preview_data.preview_layer_handle = preview_layer_handle;
//    camera_preview_data.preview_wnd_offset_x = 0;
//    camera_preview_data.preview_wnd_offset_y = 0;
//    camera_preview_data.preview_wnd_width = layer_width;
//    camera_preview_data.preview_wnd_height = layer_height;
    camera_preview_data.blt_layer_flag = blt_layer_flag;
    camera_preview_data.preview_layer_flag = preview_layer_flag;
    camera_preview_data.is_lcd_update = visible;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = TRUE;
    
    ret = mdi_camera_preview_start(&camera_preview_data, &camera_setting_data, NULL);        

    if (ret == MDI_RES_CAMERA_SUCCEED)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
        JMA_CS_LEAVE(KAL_TRUE);
    }
    else
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
        
        /* free layers */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        } 
        //JMA_CS_LEAVE(KAL_FALSE);
    }

   JMA_CS_LEAVE(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_preview_stop
 * DESCRIPTION
 *  function to be called to stop preview
 * PARAMETERS
 *  void
 *  int mma_type(?)
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_mvm_cam_player_preview_stop(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_CAM_PLAYER_PREVIEW_STOP, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        ASSERT(preview_layer_handle != GDI_LAYER_EMPTY_HANDLE);
        ret = mdi_camera_preview_stop();
        if (ret != MDI_RES_CAMERA_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        /* free layers */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        } 
       
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_preview_stop_keep_layer
 * DESCRIPTION
 *  function does not free layer and must be paired with jma_cam_player_preview_start(). 
 *  Otherwise, when java is paused/resumed, assert will occur.
 * PARAMETERS
 *  void
 *  int mma_type(?)
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_cam_player_preview_stop_keep_layer(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_PREVIEW_STOP_KEEP_LAYER, vm_id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    /* Don't need to change state as READY in background call */
//#ifdef __MMI_BACKGROUND_CALL__    
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    ASSERT(preview_layer_handle != GDI_LAYER_EMPTY_HANDLE);
    /* Does not free layer */
    ret = mdi_camera_preview_stop();
    if (ret != MDI_RES_CAMERA_SUCCEED)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
    video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_cam_player_get_snapshot
 * DESCRIPTION
 *  This function get a image from camera preview screen
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 *  mode            [IN]        
 * RETURNS
 *  int - 0(?)
 *****************************************************************************/
kal_bool jma_mvm_cam_player_get_snapshot(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms = MDI_RES_CAMERA_ERR_FAILED;
    kal_int32 result, file_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_CAM_PLAYER_GET_SNAPSHOT, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* Once vm does not at FG/FG_MMI state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING) 
    {
        /* Check if valid file path and delete the file */
        result = FS_GetDevStatus(filename[0], FS_MOUNT_STATE_ENUM);
        if (result == FS_NO_ERROR) 
        {
            file_handle = FS_Open((kal_wchar *) filename, FS_READ_ONLY);
            if (file_handle > 0) /* Check if file exist */
            {
                result = FS_Close(file_handle); /* need to close file before delete */
                result = FS_Delete((kal_wchar *) filename);
                if (result != FS_NO_ERROR)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
                    JMA_CS_LEAVE(KAL_FALSE);
                }
            }
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        j2me_lcd_mutex_lock();
        GDI_LOCK;
        ms = mdi_camera_capture(filename);
        if (ms == MDI_RES_CAMERA_SUCCEED)
        {
            ms = mdi_camera_save_captured_image(); 
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        }
        GDI_UNLOCK;
        j2me_lcd_mutex_unlock();

        /* free layers */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

            jma_video_free_preveiw_layer_buffer(vm_id);
        } 
       
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;

        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    /* State is wrong */
    JMA_CS_LEAVE(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_refresh
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
kal_bool jma_cam_player_refresh(kal_int32 vm_id, kal_int32 java_player)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_CAM_PLAYER_REFRESH, vm_id, java_player, video_player[vm_id].state);

    /* Handle camera player: start preview again */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        /* Do not free the layer if only position is changed. Avoid flash problem */
        ret = jma_cam_player_preview_stop_keep_layer(vm_id);
        ret = jma_mvm_cam_player_preview_start(vm_id, MMA_TYPE_CAM, java_player);
    }
    return ret;
}
#else /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_CAMERA__) */ 
kal_bool jma_mvm_cam_player_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_cam_player_preview_stop(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_cam_player_preview_start(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_cam_player_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
void jma_mvm_cam_player_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_bool jma_mvm_cam_player_get_snapshot(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *filename){return KAL_FALSE;}
#endif /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_CAMERA__) */ 


