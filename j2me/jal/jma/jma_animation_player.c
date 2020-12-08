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
 *   jma_animation_player.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JMA Image Animation APIs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Header Files
 *************************************************************************/
/* Java Header */
#include "MMI_include.h"

#include "jma_interface.h"
#include "jma_internal.h"
#include "app_mem.h"

#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO)
/*************************************************************************
 * Global Variable
 *************************************************************************/
#define JMA_ANIMA_FRAME_NUM_STEP (1000)
#define JMA_ANIMA_MIN_TICK (3)
anima_info_struct anima_info[JVM_NUM];
stack_timer_struct java_stop_time_timer;

/*************************************************************************
 * Function
 *************************************************************************/
static kal_bool jma_anima_player_draw_current_frame(kal_int32 vm_id);

/*************************************************************************
 * Function Implementation
 *************************************************************************/

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_drm_expired_hdlr
 * DESCRIPTION
 *  This function is callback handler for drm expired
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_anima_player_drm_expired_hdlr(kal_int32 result, kal_int32 drm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 java_player;
    kal_int32 i = 0;
    kal_int32 vm_id = INVALID_JVM_ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_DRM_EXPIRED_HDLR, result, drm_id);

    for (i = 0; i < JVM_NUM; i++)
    {
        if (video_player[i].drm_id == drm_id)
            break;
    }
    if (INVALID_JVM_ID == vm_id)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, i);
        return;
    }
    
    jam_drm_stop_consume(video_player[vm_id].drm_id);
    video_player[vm_id].drm_state = JAVA_DRM_STATE_EXPIRED;
    video_player[vm_id].drm_id = -1;
    
    /* If fail, resource is occupied by MMI, do nothing */
    JMA_CS_ENTER(vm_id, JMA_VOID);
    java_player = video_player[vm_id].id;         
    jma_mvm_anima_player_close(vm_id, java_player);  
	jvm_post_mma_event(MMA_EVENT_ERROR, java_player, MMA_ERR_DRM_RIGHT_EXPIRED);
    JMA_CS_LEAVE(JMA_VOID); 
    
}
#endif



/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_finalize
 * DESCRIPTION
 *  The function is to finialize animation player
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void jma_anima_player_finalize(kal_int32 vm_id)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (video_player[vm_id].buffer != NULL)
    {
        jvm_free(video_player[vm_id].buffer);
        video_player[vm_id].buffer = NULL;
    }  

    if (anima_info[vm_id].time_index != NULL)
    {
        jvm_free(anima_info[vm_id].time_index);
        anima_info[vm_id].time_index = NULL;
    }
    
#ifdef __DRM_SUPPORT__    
    /* stop consume drm right */
    if (video_player[vm_id].drm_state == JAVA_DRM_STATE_CONSUMING ||
        video_player[vm_id].drm_state == JAVA_DRM_STATE_PAUSED)
    {    
        jam_drm_stop_consume(video_player[vm_id].drm_id);            
    }
#endif 
    
    jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
    jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);

    if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(preview_layer_handle);
        preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        
        jma_video_free_preveiw_layer_buffer(vm_id);
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
 *  jma_anima_player_suspend_hdlr
 * DESCRIPTION
 *  The function is animation player's suspend handler
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_int32 jma_anima_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_SUSPEND_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);      
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        /* (1) Keep current_time & delay time. */
        /* (2) Stop java_media_timer, java_stop_time_timer */
        jma_mvm_anima_player_pause(vm_id, java_player);

        /* Keep original state */
        video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
    }

#ifdef __DRM_SUPPORT__
    /* pause consume drm right */
    if (video_player[vm_id].drm_state == JAVA_DRM_STATE_CONSUMING)
    {    
        jam_drm_pause_consume(video_player[vm_id].drm_id);
        video_player[vm_id].drm_state = JAVA_DRM_STATE_PAUSED;
    }
#endif 
    
    /* free layers */
    jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
    jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
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
 *  jma_anima_player_resume_hdlr
 * DESCRIPTION
 *  The function is animation player's resume handler
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_int32 jma_anima_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
#ifdef __DRM_SUPPORT__
    kal_int32 drm_result;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_RESUME_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }
    
    if (!video_player[vm_id].is_double_buffer)
    {
        /* Start double buffer when resume video */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;    
    }
    
    /* Reset animation cache when buffer content is changed */
    gdi_image_cache_reset();

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
    {
        jma_anima_player_parse_info_cyclic(vm_id);
        JMA_CS_LEAVE(RESOUCE_NO_ERROR);
    }
    
    /* Including 3 states: PLAYING, PAUSE, READY after play finish */
    if (video_player[vm_id].need_redraw) 
    {
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);

		if(KAL_FALSE == ret)
		{
		    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 123);
		}

        /* Config hardware layer */
        jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
                
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            /* Use delay_time stored at suspend handler */
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
            jma_mvm_anima_player_play(vm_id, java_player);
        }
        else /* PAUSED state or READY state after play finish */
        {
            /* Draw paused frame on the screen */
            if(!jma_anima_player_draw_current_frame(vm_id))
            {
                JMA_CS_LEAVE(RESOUCE_FAIL);
            }
        }    
    }

#ifdef __DRM_SUPPORT__    
    if (video_player[vm_id].drm_state == JAVA_DRM_STATE_PAUSED)
    {
        drm_result = jam_drm_resume_consume(video_player[vm_id].drm_id);
        if (drm_result == J2ME_NO_ERROR)
        {
            video_player[vm_id].drm_state = JAVA_DRM_STATE_CONSUMING;
        }
        else
        {
            jma_mvm_anima_player_close(vm_id, java_player);
            jvm_post_mma_event(MMA_EVENT_ERROR, java_player, MMA_ERR_DRM_RIGHT_EXPIRED);
            JMA_CS_LEAVE(RESOUCE_FAIL);
        }        
    }
#endif 
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_close_hdlr
 * DESCRIPTION
 *  The function is animation player's close handler
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_int32 jma_anima_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_CLOSE_HDLR, vm_id, java_player, video_player[vm_id].state);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return RESOUCE_FAIL;
    }

    /* With resource */
    if (jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE))
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);      
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);  

            if (video_player[vm_id].stoptime != (U64)-1)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                stack_stop_timer(&java_stop_time_timer); 
            }
        }
        
        jma_media_player_cs_leave();
    }

    jma_deregister_device(video_player[vm_id].device_type, vm_id, java_player);
    jma_anima_player_finalize(vm_id);
    return RESOUCE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_parse_info_cyclic
 * DESCRIPTION
 *  This function construct the mapping between frame and time
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE or FALSE
 *****************************************************************************/
kal_bool jma_anima_player_parse_info_cyclic(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    kal_uint32 *original_time_index;
    kal_uint32 original_time_index_length;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_PARSE_INFO_CYCLIC, vm_id, video_player[vm_id].state, anima_info[vm_id].current_frame);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    /****************************************************    
     * time_index: an array to store gif info
     ****************************************************/
     
    /* if delay_time == 0, stack_stop_timer() can not prevent time out callback */
    if (video_player[vm_id].state != JAVA_MEDIA_STATE_OPENING)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* Create layer for GIF decode use */
    if (preview_layer_handle == NULL)
    {
        preview_buf_size = (((video_player[vm_id].video_width * video_player[vm_id].video_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3));
        //preview_buf_ptr = (kal_uint16*) applib_mem_screen_alloc_framebuffer(preview_buf_size);

    #ifdef __COSMOS_MMI_PACKAGE__
        preview_buf_ptr = (kal_uint16 *) mmi_frm_asm_alloc_nc_r(jma_app_id(vm_id), preview_buf_size);
    #else
        preview_buf_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_JAVA,preview_buf_size);
    #endif /* __COSMOS_MMI_PACKAGE__ */

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_ALLOCATE_SCR_MEMORY, preview_buf_ptr, preview_buf_size);
        if (preview_buf_ptr == NULL)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }

        gdi_layer_create_using_outside_memory(
                    0, 0, video_player[vm_id].video_width, video_player[vm_id].video_height,
                    &preview_layer_handle,
                    (PU8) preview_buf_ptr, (S32) preview_buf_size);
    }
        
    EXT_ASSERT(preview_layer_handle != NULL, 0, 0, 0);

    /* Allocate memory to parse info */
    if (anima_info[vm_id].time_index == NULL)
    {
        EXT_ASSERT(anima_info[vm_id].time_index_length == 0, 0, 0, 0);
        anima_info[vm_id].time_index_length = JMA_ANIMA_FRAME_NUM_STEP;
        anima_info[vm_id].time_index = jvm_malloc(anima_info[vm_id].time_index_length * sizeof(kal_uint32));
    }
    
    /* Enlarte memory to parse info */
    if (anima_info[vm_id].current_frame >= anima_info[vm_id].time_index_length)
    {        
        original_time_index = anima_info[vm_id].time_index;
        original_time_index_length = anima_info[vm_id].time_index_length;

        anima_info[vm_id].time_index_length += JMA_ANIMA_FRAME_NUM_STEP;        
        anima_info[vm_id].time_index = jvm_malloc(anima_info[vm_id].time_index_length * sizeof(kal_uint32));

        if (anima_info[vm_id].time_index == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            jvm_free(original_time_index); 
            
            jma_mvm_anima_player_close(vm_id, video_player[vm_id].id);      
            JMA_CS_LEAVE(KAL_FALSE);
        }

        memcpy(anima_info[vm_id].time_index, original_time_index, original_time_index_length * sizeof(kal_uint32));
        jvm_free(original_time_index);       
    }
    
    /* Decode frame */
    gdi_layer_push_and_set_active(preview_layer_handle);

    if (video_player[vm_id].buffer != NULL)
    {
        ret = gdi_image_draw_resized_mem_frames(
                0, 
                0,
                video_player[vm_id].video_width,
                video_player[vm_id].video_height,
                video_player[vm_id].buffer, 
                GDI_IMAGE_TYPE_GIF, 
                video_player[vm_id].buffer_length, 
                anima_info[vm_id].current_frame);
    }
    else
    {
        ret = gdi_image_draw_resized_file_frames(
                0,
                0,
                video_player[vm_id].video_width,
                video_player[vm_id].video_height,
                video_player[vm_id].filename,
                anima_info[vm_id].current_frame);
    }
    gdi_layer_pop_and_restore_active();
    
    if (ret == GDI_SUCCEED)
    {
        anima_info[vm_id].delay_time = gdi_anim_get_delay();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, anima_info[vm_id].current_frame, anima_info[vm_id].delay_time);
        anima_info[vm_id].delay_time = (anima_info[vm_id].delay_time == 0) ? 1 : anima_info[vm_id].delay_time;

        /* Calculate duraion */
        video_player[vm_id].duration += anima_info[vm_id].delay_time;

        /* Store delay time to the array of scan_time */
        anima_info[vm_id].time_index[anima_info[vm_id].current_frame] = anima_info[vm_id].delay_time;
        
        anima_info[vm_id].current_frame ++;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_ANIMA_PARSE_INFO + vm_id, JMA_ANIMA_MIN_TICK);  
    } 
    else 
    {
        /* Invalid format */
        if (anima_info[vm_id].current_frame == 0)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            
            jma_mvm_anima_player_close(vm_id, video_player[vm_id].id);
            
            JMA_CS_LEAVE(KAL_FALSE);
        }

        /* The following: Media End */
        
        /* Assign total frame number */
        anima_info[vm_id].frame_number = anima_info[vm_id].current_frame;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, anima_info[vm_id].frame_number);

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;

        /* Reset current frame for play */
        anima_info[vm_id].current_frame = 0;

        /* Reset animation cache when for play */
        gdi_image_cache_reset();
        
        /* Free layer for GIF decode use */
        gdi_layer_free(preview_layer_handle);
        preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        jma_video_free_preveiw_layer_buffer(vm_id);
    }    
        
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_play_finish_hdlr
 * DESCRIPTION
 *  The function is play finish handler
 * PARAMETERS
 *  event_type      [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
void jma_anima_player_check_stop_time_cyclic(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 current_time;
    kal_int32 ticks = kal_milli_secs_to_ticks(300); /* 300 ms */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_CHECK_STOP_TIME_CYCLIC, vm_id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);
    
    if (video_player[vm_id].state != JAVA_MEDIA_STATE_PLAYING)
    {
        kal_print("Animation player FAIL: state is not right!");
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    EXT_ASSERT(video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING, 0, 0, 0);

    current_time = jma_mvm_anima_player_get_media_time(vm_id, video_player[vm_id].id);

    /* Reach stop time */
    if (current_time >= video_player[vm_id].stoptime)
    {
        /* State will change to PAUSED in this function */
        jma_mvm_anima_player_pause(vm_id, video_player[vm_id].id);

        /* Reset stop time */
        video_player[vm_id].stoptime = (kal_int64) -1;
        jvm_post_mma_event(MMA_EVENT_STOPPED_AT_TIME, video_player[vm_id].id, (kal_int64) video_player[vm_id].current_time);    
    }
    /* Restart timer again */
    else 
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_stop_time_timer, JAVA_MEDIA_TIMER_ANIMA_PLAYER + vm_id, ticks);
    }    
    
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_draw_frame_cyclic
 * DESCRIPTION
 *  This function draws a single frame to LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_anima_player_draw_frame_cyclic(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ticks, current_tick, tick_before_decode, tick_after_decode;
    kal_int64 elapse_tick, adjusted_delay_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_DRAW_FRAME_CYCLIC, vm_id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    /* if delay_time == 0, stack_stop_timer() can not prevent time out callback */
    if (video_player[vm_id].state != JAVA_MEDIA_STATE_PLAYING)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    /* Draw next frame */
    anima_info[vm_id].current_frame ++;
    kal_get_time(&tick_before_decode);
    if (!jma_anima_player_draw_current_frame(vm_id))
    {     
        /* Media End */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;

        /* Does not reach stop time yet */
        if (video_player[vm_id].stoptime != (U64)-1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_stop_time_timer); 
        }
        
        /* Update current time */
        kal_get_time(&current_tick);
        elapse_tick = current_tick - anima_info[vm_id].start_tick;
        if (elapse_tick < 0)
        {
            elapse_tick = 0xffffffff - anima_info[vm_id].start_tick + current_tick;
        }
        video_player[vm_id].current_time += kal_ticks_to_milli_secs((kal_uint32) elapse_tick);

        /* Reset current frame index to the last frame */
        anima_info[vm_id].current_frame --;
        
        jvm_post_mma_event(MMA_EVENT_END_OF_MEDIA, video_player[vm_id].id, (kal_int64) video_player[vm_id].current_time);    

        JMA_CS_LEAVE(JMA_VOID);
    }
    kal_get_time(&tick_after_decode);
    

    anima_info[vm_id].delay_time = gdi_anim_get_delay();
    /* Calculate adjusted delay time: Include decode time */
    elapse_tick = (S64) tick_after_decode - tick_before_decode;
    if (elapse_tick < 0)
    {
        elapse_tick = 0xffffffff - tick_before_decode + tick_after_decode;
    }
    adjusted_delay_time = (S64) anima_info[vm_id].delay_time - kal_ticks_to_milli_secs((kal_uint32) elapse_tick);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, anima_info[vm_id].delay_time, (kal_uint32)adjusted_delay_time);
    anima_info[vm_id].delay_time = (adjusted_delay_time >= 0) ? adjusted_delay_time : 0;

    /* Start timer again to draw next frame */
    ticks = kal_milli_secs_to_ticks(anima_info[vm_id].delay_time);
    /* To avoid JVM being too busy */
    ticks = (ticks < JMA_ANIMA_MIN_TICK) ? JMA_ANIMA_MIN_TICK: ticks;

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
    stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_ANIMA_PLAYER + vm_id, ticks);        
    
    JMA_CS_LEAVE(JMA_VOID);
}

/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_draw_current_frame
 * DESCRIPTION
 *  This function draws a single frame to LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool jma_anima_player_draw_current_frame(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 layer_x, layer_y, layer_width, layer_height;
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_DRAW_CURRENT_FRAME, vm_id, video_player[vm_id].state, anima_info[vm_id].current_frame);

    EXT_ASSERT(preview_layer_handle != NULL, 0, 0, 0);
    /* draw the first frame to layer */
    gdi_layer_push_and_set_active(preview_layer_handle);

    if (video_player[vm_id].buffer != NULL)
    {
        ret = gdi_image_draw_resized_mem_frames(
                0, 
                0,
                video_player[vm_id].video_width,
                video_player[vm_id].video_height,
                video_player[vm_id].buffer, 
                GDI_IMAGE_TYPE_GIF, 
                video_player[vm_id].buffer_length, 
                anima_info[vm_id].current_frame);
    }
    else
    {
        ret = gdi_image_draw_resized_file_frames(
                0,
                0,
                video_player[vm_id].video_width,
                video_player[vm_id].video_height,
                video_player[vm_id].filename,
                anima_info[vm_id].current_frame);
    }
    gdi_layer_pop_and_restore_active();
    
    if (ret != GDI_SUCCEED)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
        return KAL_FALSE;
    }    


    gdi_layer_push_and_set_active(preview_layer_handle);
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_pop_and_restore_active();
    
    /* Refresh layer region */
    if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_FULL)
    {
        /* LCD top-left corner: (0, 0) */
        jui_widget_mvm_refresh_screen(
            layer_x, 
            layer_y, 
            layer_x + layer_width - 1, 
            layer_y + layer_height - 1,
            vm_id);
    }
    else if (g_jui_screen_data[vm_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
    {        
    /* Landscape: Title bar and status bar are merged together */
    #ifndef __MMI_MAINLCD_320X240__
        /* LCD top-left corner: (0, -MMI_status_bar_height) */
        jui_widget_mvm_refresh_screen(
            layer_x, 
            layer_y - MMI_status_bar_height, 
            layer_x + layer_width - 1, 
            layer_y + layer_height - 1 - MMI_status_bar_height,
            vm_id);
    #else
        /* LCD top-left corner: (0, -MMI_status_bar_height) */
        jui_widget_mvm_refresh_screen(
            layer_x, 
            layer_y, 
            layer_x + layer_width - 1, 
            layer_y + layer_height - 1,
            vm_id);
    #endif     
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_refresh
 * DESCRIPTION
 *  The function is used to refresh animation player to new location/visibility
 * PARAMETERS      
 *  java_player             [IN]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_anima_player_refresh(kal_int32 vm_id, kal_int32 java_player)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_REFRESH, vm_id, java_player, video_player[vm_id].state);

    /* PLAYING, PAUSED, READY after play to end */
    if (video_player[vm_id].need_redraw)
    {
        //EXT_ASSERT(preview_layer_handle != GDI_NULL_HANDLE, 0, 0, 0);
        
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);
        if (ret == KAL_FALSE)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
        
        jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
        /* Update layer again when ROI has changed because GDI only updates ROI region */
        ret = jma_anima_player_draw_current_frame(vm_id);
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_open
 * DESCRIPTION
 *  The function opens an animation player
 * PARAMETERS
 *  java_player [IN]
 *  data        [IN]
 *  length      [IN]
 *  filename    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_anima_player_open(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 length, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__    
    kal_bool is_permitted;
#endif
    kal_int8 audio_state = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);
    
    /* find free player */
    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
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

            /* Reset animation cache when buffer content is changed */
            gdi_image_cache_reset();
            
            /* Get image width & height */
            gdi_image_get_dimension_mem(
                GDI_IMAGE_TYPE_GIF, 
                video_player[vm_id].buffer,
                video_player[vm_id].buffer_length,
                &video_player[vm_id].video_width,
                &video_player[vm_id].video_height);
        }
        else
        {
        #ifdef __DRM_SUPPORT__            
            /* Check drm right */
            if (jam_drm_is_drm_file((kal_wchar*)filename))
            {
                is_permitted = jam_drm_check_right(
                                (kal_wchar*)filename, 
                                DRM_PERMISSION_DISPLAY);
                if (!is_permitted)
                {                        
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                    JMA_CS_LEAVE(KAL_FALSE);
                }
            }                            
        #endif /* __DRM_SUPPORT__ */    
            
            /* Copy FileName from KNI Layer */
            mmi_ucs2cpy((S8*) video_player[vm_id].filename, filename);

            /* Get image width & height */
            gdi_image_get_dimension_file(
                (S8*) video_player[vm_id].filename,
                &video_player[vm_id].video_width,
                &video_player[vm_id].video_height);  
        }

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, video_player[vm_id].video_width, video_player[vm_id].video_height);

        if (video_player[vm_id].video_width == 0 || video_player[vm_id].video_height == 0)
        {
            if (video_player[vm_id].buffer != NULL)
            {
                jvm_free(video_player[vm_id].buffer);
                video_player[vm_id].buffer = NULL;
            }
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    #ifndef __JBLENDIA__
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_OPENING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_OPENING;
    #else
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    #endif

        anima_info[vm_id].current_frame = 0;
        anima_info[vm_id].frame_number = 0;
        
        video_player[vm_id].id = java_player;
        video_player[vm_id].stoptime = -1;
        video_player[vm_id].current_time = 0;
        video_player[vm_id].duration = 0;
        video_player[vm_id].device_type = JAVA_MEDIA_ANIMA_PLAYER_DEVICE; 

        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_ANIMA_PLAYER_DEVICE,
            vm_id,
            java_player, 
            &jma_anima_player_suspend_hdlr, 
            &jma_anima_player_resume_hdlr, 
            &jma_anima_player_close_hdlr); 
        
    #ifndef __JBLENDIA__
        /* Start to parse GIF info */
        if (!jma_anima_player_parse_info_cyclic(vm_id))
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
    #endif       

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;   
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_play
 * DESCRIPTION
 *  The function plays an animation player
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_anima_player_play(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ticks, tick_before_decode, tick_after_decode;
    S64 elapse_tick, adjusted_delay_time;
    kal_bool ret;
    kal_int32 stop_time_ticks = kal_milli_secs_to_ticks(300); /* 300 ms */
#ifdef __DRM_SUPPORT__
    kal_int32 drm_id;
    kal_bool is_permitted;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_PLAY, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }    

#ifdef __DRM_SUPPORT__
    /* Check drm right */
    if (video_player[vm_id].buffer == NULL &&
        video_player[vm_id].drm_state == JAVA_DRM_STATE_NULL)
    {
        /* Check drm right */
        if (jam_drm_is_drm_file(video_player[vm_id].filename))
        {
            is_permitted = jam_drm_check_right(
                            video_player[vm_id].filename, 
                            DRM_PERMISSION_DISPLAY);
            if (is_permitted)
            {
                video_player[vm_id].drm_state = JAVA_DRM_STATE_PERMITTED;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }
        else
        {
            video_player[vm_id].drm_state = JAVA_DRM_STATE_NORMAL_FILE;
        }
    }                  
#endif 

    /* If vm_id not FG running, just swithch the state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
            video_player[vm_id].need_redraw = KAL_TRUE;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            jma_video_player_refine_display_info(vm_id);
            ret = jma_video_player_process_layer(vm_id);
            if (ret == KAL_FALSE)
            {
                JMA_CS_LEAVE(KAL_FALSE);
            }

            jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
                   
            /* Do not support setMediaTime(). So set current time == 0 when READY -> PLAYING */
            video_player[vm_id].current_time = 0;
            anima_info[vm_id].current_frame = 0;
        }

        kal_get_time(&tick_before_decode);
        if(!jma_anima_player_draw_current_frame(vm_id))
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
        kal_get_time(&tick_after_decode);

        /* Remeber do not get delay at PAUSED state */
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            anima_info[vm_id].delay_time = gdi_anim_get_delay();

            /* Calculate adjusted delay time: Include decode time */
            elapse_tick = (S64) tick_after_decode - tick_before_decode;
            if (elapse_tick < 0)
            {
                elapse_tick = 0xffffffff - tick_before_decode + tick_after_decode;
            }
            adjusted_delay_time = (S64) anima_info[vm_id].delay_time - kal_ticks_to_milli_secs((kal_uint32) elapse_tick);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, anima_info[vm_id].delay_time, (kal_uint32)adjusted_delay_time);
            anima_info[vm_id].delay_time = (adjusted_delay_time >= 0) ? adjusted_delay_time : 0;
        }
        
        kal_get_time(&anima_info[vm_id].start_tick);        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;               

        ticks = kal_milli_secs_to_ticks(anima_info[vm_id].delay_time);
        /* To avoid JVM being too busy */
        ticks = (ticks < JMA_ANIMA_MIN_TICK) ? JMA_ANIMA_MIN_TICK: ticks;
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_ANIMA_PLAYER + vm_id, ticks);        

        if (video_player[vm_id].stoptime != (U64)-1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_stop_time_timer, JAVA_MEDIA_TIMER_ANIMA_PLAYER + vm_id, stop_time_ticks);
        }

    #ifdef __DRM_SUPPORT__
        /* consume drm right */
        if (video_player[vm_id].drm_state == JAVA_DRM_STATE_PERMITTED)
        {
            drm_id = jam_drm_start_consume(
                        video_player[vm_id].filename, 
                        DRM_PERMISSION_DISPLAY, 
                        jma_anima_player_drm_expired_hdlr);
            if (drm_id >= 0)
            {
                video_player[vm_id].drm_id = drm_id;
                video_player[vm_id].drm_state = JAVA_DRM_STATE_CONSUMING;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }  
    #endif 

        video_player[vm_id].need_redraw = KAL_TRUE;
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_pause
 * DESCRIPTION
 *  The function pauses an animation player
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_anima_player_pause(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 remaining_ticks, current_tick;
    kal_int64 elapse_tick;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_PAUSE, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, KAL_FALSE);
    
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {        
        if (stack_timer_status(&java_media_timer, &remaining_ticks) != STACK_TIMER_NOT_TIMED_OUT)  
        {
            remaining_ticks = 0; 
        }
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);   

        if (video_player[vm_id].stoptime != (U64)-1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_stop_time_timer); 
        }
        
        /* Update delay_time */
        anima_info[vm_id].delay_time = kal_ticks_to_milli_secs(remaining_ticks);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, anima_info[vm_id].delay_time);
        
        /* Update current time */
        kal_get_time(&current_tick);
        elapse_tick = current_tick - anima_info[vm_id].start_tick;
        if (elapse_tick < 0)
        {
            elapse_tick = 0xffffffff - anima_info[vm_id].start_tick + current_tick;
        }
        video_player[vm_id].current_time += kal_ticks_to_milli_secs((kal_uint32) elapse_tick);
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_close
 * DESCRIPTION
 *  The function closes an animation player
 * PARAMETERS
 *  java_player [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_anima_player_close(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_CLOSE, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, KAL_FALSE);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);  
    }

    jma_deregister_device(JAVA_MEDIA_ANIMA_PLAYER_DEVICE, vm_id, java_player);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        jma_anima_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        jma_anima_player_finalize(vm_id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);      
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
        stack_stop_timer(&java_media_timer);

        if (video_player[vm_id].stoptime != (U64)-1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_stop_time_timer); 
        }
    }

    jma_anima_player_finalize(vm_id);

#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif
    
    JMA_CS_LEAVE(KAL_TRUE);  
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_anima_player_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]          
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_anima_player_clear_jmadata(kal_int32 vm_id, kal_int32 java_player)
{
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_ANIMA_PLAYER_CLEAR_JMADATA, vm_id, java_player);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;  
    }

    jma_deregister_device(JAVA_MEDIA_ANIMA_PLAYER_DEVICE, vm_id, java_player);

    if (video_player[vm_id].buffer != NULL)
    {
        jvm_free(video_player[vm_id].buffer);
        video_player[vm_id].buffer = NULL;
    }  

    if (anima_info[vm_id].time_index != NULL)
    {
        jvm_free(anima_info[vm_id].time_index);
        anima_info[vm_id].time_index = NULL;
    }
    
#ifdef __DRM_SUPPORT__    
    /* stop consume drm right */
    if (video_player[vm_id].drm_state == JAVA_DRM_STATE_CONSUMING ||
        video_player[vm_id].drm_state == JAVA_DRM_STATE_PAUSED)
    {    
        jam_drm_stop_consume(video_player[vm_id].drm_id);            
    }
#endif 
    
    jma_video_player_reset_parameter(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_is_opened
 * DESCRIPTION
 *  This function can be invoked ONLY after _open() is invoked
 * PARAMETERS  
 *  java_player     [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_int32 jma_mvm_anima_player_is_opened(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_IS_OPENED, vm_id, java_player, video_player[vm_id].state);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return -1;
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
        {
            return -1; /* Error */ 
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            return 1; /* OK */
        }
        return -1;
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
        {
            return -1; /* Error */ 
        }
        else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING ||
                 video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            return 1; /* OK */
        }
        return -1;
    }
//#endif /* __MMI_BACKGROUND_CALL__ */
        
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        return -1; /* Error */ 
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_OPENING)
    {
        return 0; /* Not yet done. */
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        return 1; /* OK */
    }

    return -1;

}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_get_media_time
 * DESCRIPTION
 *  This function gets media time
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_int64 jma_mvm_anima_player_get_media_time(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_tick;
    kal_int64 elapse_tick;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_GET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE((long)video_player[vm_id].current_time);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE((long)video_player[vm_id].current_time);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */  

    /* Update current time only when player is at PLAYING state */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        kal_get_time(&current_tick);
        elapse_tick = current_tick - anima_info[vm_id].start_tick;
        if (elapse_tick < 0)
        {
            elapse_tick = 0xffffffff - anima_info[vm_id].start_tick + current_tick;
        }
        video_player[vm_id].current_time += kal_ticks_to_milli_secs((kal_uint32) elapse_tick);
        anima_info[vm_id].start_tick = current_tick;
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
    JMA_CS_LEAVE((long)video_player[vm_id].current_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_get_duration
 * DESCRIPTION
 *  This function gets duration 
 * PARAMETERS    
 *  java_player     [IN]
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_int64 jma_mvm_anima_player_get_duration(kal_int32 vm_id, kal_int32 java_player)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 duration = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_GET_DURATION, vm_id, java_player, video_player[vm_id].state);

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
    JMA_CS_LEAVE((S64)duration);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_set_media_time
 * DESCRIPTION
 *  This function sets media time
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  now             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jma_mvm_anima_player_set_media_time(kal_int32 vm_id, kal_int32 java_player, kal_int64 now)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_playing = KAL_FALSE;
    kal_int32 i, cumulate_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_SET_MEDIA_TIME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)now);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(-1);
    }

    EXT_ASSERT(anima_info[vm_id].time_index != NULL, 0, 0, 0);
    EXT_ASSERT(anima_info[vm_id].frame_number != 0, 0, 0, 0);
    
    /* seek time should be bound in duration */
    if (video_player[vm_id].duration != -1 && now > video_player[vm_id].duration)
    {
        now = video_player[vm_id].duration;            
    }
    
    /* Modify delay_time & current frame */    
    cumulate_time = 0;
    for (i=0; i < anima_info[vm_id].frame_number; i++)
    {
        cumulate_time += anima_info[vm_id].time_index[i];
        if (cumulate_time >= now)
        {
            break;
        }
    }
    
    EXT_ASSERT(i < anima_info[vm_id].frame_number, 0, 0, 0);

    anima_info[vm_id].current_frame = i;
    anima_info[vm_id].delay_time = cumulate_time - now;
    video_player[vm_id].current_time = now;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE((long)video_player[vm_id].current_time);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE((long)video_player[vm_id].current_time);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        is_playing = KAL_TRUE;
    }     

    if (is_playing == KAL_TRUE)
    {
        jma_mvm_anima_player_pause(vm_id, java_player);
    }
    
    /* Reset animation cache when buffer content is changed */
    gdi_image_cache_reset();
    
    /* Including 3 states: PLAYING, PAUSED, READY after Media End */
    if (preview_layer_handle != NULL)
    {
        /* Draw seeked frame on the screen */
        if(!jma_anima_player_draw_current_frame(vm_id))
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(-1);
        }
    }
    
    if (is_playing == KAL_TRUE)
    {
        jma_mvm_anima_player_play(vm_id, java_player);
    }
    
    JMA_CS_LEAVE((S64) video_player[vm_id].current_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_set_stop_time
 * DESCRIPTION
 *  The function sets stop time to an animation player
 * PARAMETERS
 *  java_player [IN]
 *  stop_time   [IN]
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_int64 jma_mvm_anima_player_set_stop_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ticks = kal_milli_secs_to_ticks(300); /* 300 ms */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_SET_STOP_TIME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)stop_time);
    JMA_CS_ENTER(vm_id, 0);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    /* Save parameter */
    video_player[vm_id].stoptime = stop_time;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE((long)stop_time);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE((long)stop_time);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    /* start timer */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        if(video_player[vm_id].stoptime != (U64)-1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_stop_time_timer, JAVA_MEDIA_TIMER_ANIMA_PLAYER + vm_id, ticks);
        }
    }

    JMA_CS_LEAVE(stop_time);    
}

/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_map_frame_to_time
 * DESCRIPTION
 *  The function maps frame to time
 * PARAMETERS   
 *  java_player             [IN]        
 *  frame_number            [IN]     
 * RETURNS
 *  media time which corresponding to frame number
 *****************************************************************************/
kal_int64 jma_mvm_anima_player_map_frame_to_time(kal_int32 vm_id, kal_int32 java_player, kal_int32 frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 cumulate_time = 0;
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_FRAME_TO_TIME, vm_id, java_player, video_player[vm_id].state, frame);

    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
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
//#endif /* __MMI_BACKGROUND_CALL__ */

    EXT_ASSERT(anima_info[vm_id].time_index != NULL, 0, 0, 0);
    EXT_ASSERT(anima_info[vm_id].frame_number != 0, 0, 0, 0);
    
    /* Bound to valid range. Frame number starts from 0 according to JSR 135 spec */
    if (frame < 0)
    {
        frame = 0;
    }
    else if (frame >= anima_info[vm_id].frame_number)
    {
        frame = anima_info[vm_id].frame_number - 1;
    }

    /* frame == 0, return 0 */
    /* frame == n, return time_index[n-1] + 1 */
    cumulate_time = 0;
    if (frame != 0)
    {
        for (i=0; i < frame; i++)
        {
            cumulate_time += anima_info[vm_id].time_index[i];
        }
        cumulate_time += 1; 
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)cumulate_time);
    JMA_CS_LEAVE(cumulate_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_map_time_to_frame
 * DESCRIPTION
 *  The function maps time to frame
 * PARAMETERS     
 *  java_player             [IN]        
 *  media_time              [IN]     
 * RETURNS
 *  frame number which corresponding to media time
 *****************************************************************************/
kal_int32 jma_mvm_anima_player_map_time_to_frame(kal_int32 vm_id, kal_int32 java_player, kal_int64 media_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 frame;
    kal_int64 cumulate_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_TIME_TO_FRAME, vm_id, java_player, video_player[vm_id].state, (kal_uint32)media_time);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
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
//#endif /* __MMI_BACKGROUND_CALL__ */

    EXT_ASSERT(anima_info[vm_id].time_index != NULL, 0, 0, 0);
    EXT_ASSERT(anima_info[vm_id].frame_number != 0, 0, 0, 0);

    /* Bound to valid range */
    if (video_player[vm_id].duration != -1 && media_time > video_player[vm_id].duration)
    {
        media_time = video_player[vm_id].duration;            
    }
    
    /* Calculate the mapping frame index */    
    cumulate_time = 0;
    for (frame = 0; frame < anima_info[vm_id].frame_number; frame ++)
    {
        cumulate_time += anima_info[vm_id].time_index[frame];
        if (cumulate_time >= media_time)
        {
            break;
        }
    }

    EXT_ASSERT(frame < anima_info[vm_id].frame_number, 0, 0, 0);
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, frame);
    JMA_CS_LEAVE(frame);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_seek
 * DESCRIPTION
 *  function to seek to assigned frame number
 * PARAMETERS     
 *  java_player             [IN]        
 *  frame_number            [IN]
 * RETURNS
 *  actual frame number to seek to.
 *****************************************************************************/
kal_int32 jma_mvm_anima_player_seek(kal_int32 vm_id, kal_int32 java_player, kal_int32 frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 media_time = 0;  
    kal_bool is_playing = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_SEEK, vm_id, java_player, video_player[vm_id].state, frame);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
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
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        is_playing = KAL_TRUE;
        jma_mvm_anima_player_pause(vm_id, java_player);
    }

    /* Bound to valid range. Frame number starts from 0 according to JSR 135 spec */
    if (frame < 0)
    {
        frame = 0;
    }
    else if (frame >= anima_info[vm_id].frame_number)
    {
        frame = anima_info[vm_id].frame_number - 1;
    }

    media_time = jma_mvm_anima_player_map_frame_to_time(vm_id, java_player, frame);
    jma_mvm_anima_player_set_media_time(vm_id, java_player, media_time);

    if (is_playing == KAL_TRUE)
    {
        jma_mvm_anima_player_play(vm_id, java_player);
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, anima_info[vm_id].current_frame);
    JMA_CS_LEAVE(anima_info[vm_id].current_frame);
}


/*****************************************************************************
 * FUNCTION
 *  jma_anima_player_skip
 * DESCRIPTION
 *  function to skip some frame number from current position.
 * PARAMETERS      
 *  java_player             [IN]        
 *  frames_to_skip          [IN]        
 * RETURNS
 *  actual frame number to skip from current position.
 *****************************************************************************/
kal_int32 jma_mvm_anima_player_skip(kal_int32 vm_id, kal_int32 java_player, kal_int32 frames_to_skip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 original_frame, skip_frame;
    kal_int64 seek_frame = 0;
    kal_bool is_playing = KAL_FALSE;
    kal_uint64 media_time = 0;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_ANIMA_PLAYER_SKIP, vm_id, java_player, video_player[vm_id].state, frames_to_skip);
    JMA_CS_ENTER(vm_id, -1);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_ERROR, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
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
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        is_playing = KAL_TRUE;
        jma_mvm_anima_player_pause(vm_id, java_player);
    }

    seek_frame = anima_info[vm_id].current_frame + (S64) frames_to_skip;

    /* Bound to valid range */
    if (seek_frame < 0)
    {
        seek_frame = 0; 
    }
    else if (seek_frame >= anima_info[vm_id].frame_number) /* overflow case (int) */
    {
        seek_frame = anima_info[vm_id].frame_number - 1;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, anima_info[vm_id].current_frame, seek_frame);

    media_time = jma_mvm_anima_player_map_frame_to_time(vm_id, java_player, (kal_int32) seek_frame);

    original_frame = anima_info[vm_id].current_frame;
    jma_mvm_anima_player_set_media_time(vm_id, java_player, media_time);
    skip_frame = anima_info[vm_id].current_frame - original_frame;
    
    if (is_playing == KAL_TRUE)
    {
        jma_mvm_anima_player_play(vm_id, java_player);
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, skip_frame);
    JMA_CS_LEAVE(skip_frame);
}


#else
kal_bool jma_mvm_anima_player_open(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 length, kal_char *filename){}
kal_bool jma_mvm_anima_player_play(kal_int32 vm_id, kal_int32 java_player){}
kal_bool jma_mvm_anima_player_pause(kal_int32 vm_id, kal_int32 java_player){}
kal_bool jma_mvm_anima_player_close(kal_int32 vm_id, kal_int32 java_player){}
void jma_mvm_anima_player_clear_jmadata(kal_int32 vm_id, kal_int32 java_player){}
kal_int64 jma_mvm_anima_player_get_media_time(kal_int32 vm_id, kal_int32 java_player){}
kal_int64 jma_mvm_anima_player_get_duration(kal_int32 vm_id, kal_int32 java_player){}
kal_int64 jma_mvm_anima_player_set_media_time(kal_int32 vm_id, kal_int32 java_player, kal_int64 now){}
kal_int64 jma_mvm_anima_player_set_stop_time(kal_int32 vm_id, kal_int32 java_player, kal_uint64 stop_time){}
kal_int32 jma_mvm_anima_player_is_opened(kal_int32 vm_id, kal_int32 java_player){}
kal_int64 jma_mvm_anima_player_map_frame_to_time(kal_int32 vm_id, kal_int32 java_player, kal_int32 frame){}
int jma_mvm_anima_player_map_time_to_frame(kal_int32 vm_id, kal_int32 java_player, kal_int64 media_time){}
int jma_mvm_anima_player_seek(kal_int32 vm_id, kal_int32 java_player, kal_int32 frame){}
int jma_mvm_anima_player_skip(kal_int32 vm_id, kal_int32 java_player, kal_int32 frames_to_skip){}
#endif
