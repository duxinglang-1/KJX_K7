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
 *  gui_video.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Source
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "MMI_trc_Int.h"
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "lcd_if.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "mdi_audio.h"
#include "gui_video.h"
#include "custom_srv_prof_defs.h"
#include "ProfilesSrvGprot.h"
/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */
static gui_video_struct *current_video_pointer;

/* Declare your local function here */
static void gui_video_get_layer_info(gui_video_struct *video);
static void gui_video_parse_flag(gui_video_struct *video);
static void gui_video_adjust_target_layer(gui_video_struct *video);
static void gui_video_default_play_callback(MDI_RESULT result, void *user_data);

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */



/*****************************************************************************
 * Local Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gui_video_get_layer_info
 * DESCRIPTION
 *  get layer info of the video component, this API need to call once in
 *  create function, used to get the original size of layer
 * PARAMETERS
 *  video           [IN]    pointer of video component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void gui_video_get_layer_info(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    gdi_layer_push_and_set_active(video->target_layer);
    gdi_layer_get_dimension(&video->layer_width, &video->layer_height);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_parse_flag
 * DESCRIPTION
 *  parse video's flag
 * PARAMETERS
 *  video           [IN]    pointer of video component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_video_parse_flag(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    switch(video->flag & GUI_VIDEO_AUDIO_PATH_TYPE)
    {
        case GUI_VIDEO_AUDIO_PATH_SPEAKER:
            {
                video->audio_path = (U8)MDI_DEVICE_SPEAKER;
            }
            break;

        case GUI_VIDEO_AUDIO_PATH_MICROPHONE:
            {
                video->audio_path = (U8)MDI_DEVICE_MICROPHONE;
            }
            break;

        case GUI_VIDEO_AUDIO_PATH_SPEAKER2:
            {
                video->audio_path = (U8)MDI_DEVICE_SPEAKER2;
            }
            break;

        case GUI_VIDEO_AUDIO_PATH_LOUDSPEAKER:
            {
                video->audio_path = (U8)MDI_DEVICE_LOUDSPEAKER;
            }
            break;

        case GUI_VIDEO_AUDIO_PATH_SPEAKER_BOTH:
            {
                video->audio_path = (U8)MDI_DEVICE_SPEAKER_BOTH;
            }
            break;

        case GUI_VIDEO_AUDIO_PATH_BT_HEADSET:
            {
                video->audio_path = (U8)MDI_DEVICE_BT_HEADSET;
            }
            break;

        default:
            {
                video->audio_path = (U8)MDI_DEVICE_SPEAKER;
            }
            break;
    }

    switch(video->flag & GUI_VIDEO_ROTATE_TYPE)
    {
        case GUI_VIDEO_ROTATE_0:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_0;
            }
            break;

        case GUI_VIDEO_ROTATE_90:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_90;
            }
            break;

        case GUI_VIDEO_ROTATE_180:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_180;
            }
            break;

        case GUI_VIDEO_ROTATE_270:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_270;
            }
            break;

        case GUI_VIDEO_ROTATE_0_MIRROR:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_0_MIRROR;
            }
            break;

        case GUI_VIDEO_ROTATE_90_MIRROR:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_90_MIRROR;
            }
            break;

        case GUI_VIDEO_ROTATE_180_MIRROR:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_180_MIRROR;
            }
            break;

        case GUI_VIDEO_ROTATE_270_MIRROR:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_270_MIRROR;
            }
            break;

        default:
            {
                video->rotate = (U16)MDI_VIDEO_LCD_ROTATE_0;
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_adjust_target_layer
 * DESCRIPTION
 *  adjust target layer of the video component, this API need to call before
 *  show video component
 * PARAMETERS
 *  video           [IN]    pointer of video component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void gui_video_adjust_target_layer(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x, offset_y, resized_width, resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);

    /* get the suitable size of video by layer's max size */
    gdi_image_util_fit_bbox(
        video->layer_width,
        video->layer_height,
        video->video_info.width,
        video->video_info.height,
        &offset_x,
        &offset_y,
        &resized_width,
        &resized_height);
    /* if resized video size is larger than component's size */
    if (resized_width > video->width || resized_height > video->height)
    {
        gdi_image_util_fit_bbox(
            video->width,
            video->height,
            resized_width,
            resized_height,
            &offset_x,
            &offset_y,
            &resized_width,
            &resized_height);
    }

    /* calculate video component's physical coordinate */
    video->video_x = video->x + video->width / 2 - resized_width / 2;
    video->video_y = video->y + video->height / 2 - resized_height / 2;
    /* adjust layer's offset_x to an even value for 6238 chip */
    if (video->video_x % 2 != 0)
    {
        video->video_x++;
    }
    video->video_width = resized_width;
    video->video_height = resized_height;
    /* move and resize layer */
    gdi_layer_push_and_set_active(video->target_layer);
    gdi_layer_resize(resized_width, resized_height);
    gdi_layer_set_position(video->video_x, video->video_y);
    gdi_layer_clear(GDI_COLOR_BLACK);
    /* we need blt this layer to set offset to hardware */
    gdi_layer_blt_previous(
        video->video_x,
        video->video_y,
        video->video_x + resized_width - 1,
        video->video_y + resized_height - 1);
    /* set clip */
    if (video->clip_x1 != 0 || video->clip_y1 != 0 ||
        video->clip_x2 != 0 || video->clip_y2 != 0)
    {
        gdi_layer_set_clip(
            video->clip_x1 - video->video_x,
            video->clip_y1 - video->video_y,
            video->clip_x2 - video->video_x,
            video->clip_y2 - video->video_y);
    }
    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_default_play_callback
 * DESCRIPTION
 *  default play callback of video component
 * PARAMETERS
 *  result          [IN]    result of video play
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_video_default_play_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(current_video_pointer != NULL);

    current_video_pointer->current_play_time = 0;
    current_video_pointer->video_state = GUI_VIDEO_STOP_STATE;
    /* reset stop_time_setted flag */
    if (current_video_pointer->stop_time_setted == MMI_TRUE)
    {
        current_video_pointer->stop_time_setted = MMI_FALSE;
    }

    if (result != MDI_RES_VDOPLY_SUCCEED)
    {
        /* reset stop time */
        mdi_video_ply_set_stop_time((U64)(-1));
    }

    if (current_video_pointer->play_callback != NULL)
    {
         current_video_pointer->play_callback(result);
    }
}


/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */
/*****************************************************************************
 * FUNCTION
 *  gui_video_create
 * DESCRIPTION
 *  create a video component
 *  User can use a video file or a video res to create
 *  If user use both to create, video component will first use file to create.
 * PARAMETERS
 *  video           [IN]    pointer of video component
 *  target_layer    [IN]    target layer that display video component
 *  x               [IN]    x pos of component
 *  y               [IN]    y pos of component
 *  width           [IN]    width of component
 *  height          [IN]    height of component
 *  file_name       [IN]    file name of video file
 *  video_id        [IN]    res ID of video
 *  flag            [IN]    flag that record info of audio path, loop, etc.
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT gui_video_create(
                  gui_video_struct *video,
                  gdi_handle target_layer,
                  S32 x,
                  S32 y,
                  S32 width,
                  S32 height,
                  S8 *file_name,
                  U16 video_id,
                  U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret = MDI_RES_VDOPLY_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(!(file_name == NULL && video_id == NULL));

    MMI_DBG_ASSERT(target_layer != GDI_NULL_HANDLE);
    /* if file name is not null, open video from file first */    
    if (file_name != NULL)
    {
        /* open with audio is on */
        video_ret = mdi_video_ply_open_clip_file(0, file_name, &(video->video_info));
        
        if (video_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            video->file_name = file_name;
        }
    }

    /* if video id not null, create from res */
    if (video_id != NULL && (file_name == NULL || video_ret != MDI_RES_VDOPLY_SUCCEED))
    {
        /* source from id */
        video_ret = mdi_video_ply_open_clip_id(0, video_id, &(video->video_info));
        if (video_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            video->video_id = video_id;
        }
    }

    if (video_ret == MDI_RES_VDOPLY_SUCCEED)
    {
        /* set ring volume as default volume */
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,(void*)(video->volume));
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)video->volume);
        video->target_layer = target_layer;
        gui_video_get_layer_info(video);
        video->x = x;
        video->y = y;
        video->width = width;
        video->height = height;
        video->clip_x1 = 0;
        video->clip_y1 = 0;
        video->clip_x2 = 0;
        video->clip_y2 = 0;
        video->flag = flag;
        video->play_speed = GUI_VIDEO_DEFAULT_PLAY_SPEED;
        video->repeat_count = GUI_VIDEO_DEFAULT_REPEAT_COUNT;
        video->current_play_time = 0;
        video->active = MMI_TRUE;
        current_video_pointer = video;
    }

    return video_ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_close
 * DESCRIPTION
 *  close a video component
 * PARAMETERS
 *  video           [IN]    pointer of video component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_video_close(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result = MDI_RES_VDOPLY_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->video_state == GUI_VIDEO_PLAY_STATE)
    {
        mdi_video_ply_get_cur_play_time(&(video->current_play_time));
        mdi_video_ply_stop();
    }
    else
    {
        video->current_play_time = 0;
    }

    /* reset stop time */
    mdi_video_ply_set_stop_time((U64)(-1));
    
    /* only one of file and video_id will be not null */
    if (video->file_name != NULL)
    {
        result = mdi_video_ply_close_clip_file();
        video->file_name = NULL;
    }
    if (video->video_id != NULL)
    {
        result = mdi_video_ply_close_clip_id();
        video->video_id = NULL;
    }

    video->target_layer = GDI_NULL_HANDLE;
    video->play_callback = NULL;
    video->video_state = GUI_VIDEO_STOP_STATE;
    video->stop_time_setted = MMI_FALSE;
    video->active = MMI_FALSE;
    current_video_pointer = NULL;
    if (result != MDI_RES_VDOPLY_SUCCEED)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_play
 * DESCRIPTION
 *  play a video component
 * PARAMETERS
 *  video               [IN]    pointer of video component
 *  blt_layer_flag      [IN]    layer should be blt by hardware
 *  play_layer_flag     [IN]    layer that driver to update a video playback
 *  is_visible          [IN]    visibility
 *  is_play_audio       [IN]    is play audio
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT gui_video_play(
                  gui_video_struct *video,
                  U32 blt_layer_flag,
                  U32 play_layer_flag,
                  MMI_BOOL is_visible,
                  MMI_BOOL is_play_audio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->video_state == GUI_VIDEO_PLAY_STATE)
    {
        gui_video_stop(video);
    }

    gui_video_parse_flag(video);
    gui_video_adjust_target_layer(video);

    /* enable video to play in clip area */
    mdi_video_ply_enable_partial_display();

    /* Get first frame and start to play */
    result = mdi_video_ply_seek_and_get_frame(
                 video->current_play_time,
                 video->target_layer);
    if (result == MDI_RES_VDOPLY_SUCCEED)
    {
        result = mdi_video_ply_play(
                     video->target_layer,
                     blt_layer_flag,
                     play_layer_flag,
                     video->repeat_count,
                     (BOOL)is_visible,
                     TRUE, /* play_audio */
                     video->audio_path,
                     video->rotate,
                     video->play_speed,
                     gui_video_default_play_callback,
                     0);
    }
    
    if (result == MDI_RES_VDOPLY_SUCCEED)
    {
        video->video_state = GUI_VIDEO_PLAY_STATE;
    }
    else
    {
        if (video->play_callback != NULL)
        {
            video->play_callback(result);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_seek
 * DESCRIPTION
 *  seek a time of video
 * PARAMETERS
 *  video           [IN]        pointer of video component
 *  time            [IN]        time want seek
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT gui_video_seek(gui_video_struct *video, U64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    ret = mdi_video_ply_seek(time);
    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        video->current_play_time = time;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_stop
 * DESCRIPTION
 *  stop display of video
 * PARAMETERS
 *  video           [IN]        pointer of video component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_stop(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->video_state == GUI_VIDEO_PLAY_STATE)
    {
        mdi_video_ply_get_cur_play_time(&(video->current_play_time));
        mdi_video_ply_stop();
        video->video_state = GUI_VIDEO_STOP_STATE;
        /* reset stop_time_setted flag */
        if (video->stop_time_setted == MMI_TRUE)
        {
            video->stop_time_setted = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_move
 * DESCRIPTION
 *  move video component
 * PARAMETERS
 *  video           [IN]        pointer of video component
 *  x               [IN]        new x pos of component
 *  y               [IN]        new y pos of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_move(gui_video_struct *video, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->x = x;
    video->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_resize
 * DESCRIPTION
 *  resize video component
 * PARAMETERS
 *  video               [IN]        pointer of video component
 *  width               [IN]        width of component
 *  height              [IN]        height pos of component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_resize(gui_video_struct *video, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->width = width;
    video->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_clip
 * DESCRIPTION
 *  set video component's clip
 *  this clip is physical coordinate of the video component, it should be
 *  converted to logic coordiante of video's target layer when video play
 * PARAMETERS
 *  video           [IN]    pointer of video component
 *  x1              [IN]    physical coordinate x1 of video clip
 *  y1              [IN]    physical coordinate y1 of video clip
 *  x2              [IN]    physical coordinate x2 of video clip
 *  y2              [IN]    physical coordinate y2 of video clip
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_set_clip(gui_video_struct *video, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->clip_x1 = x1;
    video->clip_y1 = y1;
    video->clip_x2 = x2;
    video->clip_y2 = y2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_stop_time
 * DESCRIPTION
 *  set video component's stop time
 * PARAMETERS
 *  video                   [IN]        pointer of video component
 *  stop_time               [IN]        stop time of video
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_video_set_stop_time(gui_video_struct *video, U64 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    /* if user has set stop time once after video play */
    if (video->video_state == GUI_VIDEO_PLAY_STATE &&
        video->stop_time_setted == MMI_TRUE)
    {
        return MMI_FALSE;
    }
    mdi_video_ply_set_stop_time(stop_time);
    if (video->video_state == GUI_VIDEO_PLAY_STATE)
    {
        video->stop_time_setted = MMI_TRUE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_volume
 * DESCRIPTION
 *  set video component's volume
 * PARAMETERS
 *  video                   [IN]    pointer of video component
 *  volume                  [IN]    volume of video, it shoud be a value between 
 *                                  LEVEL1 ~ LEVEL7
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_set_volume(gui_video_struct *video, U16 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (volume <= SRV_PROF_VOL_LEVEL_7) /* LEVEL1 value is 0 */
    {
        video->volume = volume;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)video->volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_get_volume
 * DESCRIPTION
 *  get video component's volume
 * PARAMETERS
 *  video                   [IN]        pointer of video component
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gui_video_get_volume(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    return video->volume;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_increase_volume
 * DESCRIPTION
 *  increase video component's volume
 * PARAMETERS
 *  video                   [IN]        pointer of video component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_increase_volume(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->volume < SRV_PROF_VOL_LEVEL_7)
    {
        video->volume++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)video->volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_decrease_volume
 * DESCRIPTION
 *  decrease video component's volume
 * PARAMETERS
 *  video                   [IN]        pointer of video component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_decrease_volume(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->volume > SRV_PROF_VOL_LEVEL_1)
    {
        video->volume--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)video->volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_repeat_count
 * DESCRIPTION
 *  set video component's repeat_count
 * PARAMETERS
 *  video                       [IN]        pointer of video component
 *  repeat_count                [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_set_repeat_count(gui_video_struct *video, U16 repeat_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->repeat_count = repeat_count;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_play_callback
 * DESCRIPTION
 *  set video component's play callback
 * PARAMETERS
 *  video          [IN]        pointer of video component
 *  f              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_set_play_callback(gui_video_struct *video, void (*f)(MDI_RESULT))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->play_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_set_play_speed
 * DESCRIPTION
 *  set video component's play speed
 * PARAMETERS
 *  video                       [IN]        pointer of video component
 *  play_speed                  [IN]        play speed of video
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_set_play_speed(gui_video_struct *video, S16 play_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    video->play_speed = play_speed;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_get_video_position
 * DESCRIPTION
 *  get video component's video position
 * PARAMETERS
 *  video           [IN]        pointer of video component
 *  x               [IN]        pointer of x pos
 *  y               [IN]        pointer of y pos
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_get_video_position(gui_video_struct *video, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    *x = video->video_x;
    *y = video->video_y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_get_current_time
 * DESCRIPTION
 *  get video component's current time
 * PARAMETERS
 *  video           [IN]        pointer of video component
 * RETURNS
 *  U64
 *****************************************************************************/
U64 gui_video_get_current_time(gui_video_struct *video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    if (video->video_state == GUI_VIDEO_PLAY_STATE)
    {
        mdi_video_ply_get_cur_play_time(&(video->current_play_time));
    }
    return(video->current_play_time);
}


/*****************************************************************************
 * FUNCTION
 *  gui_video_get_video_info
 * DESCRIPTION
 *  get video component's video info
 * PARAMETERS
 *  video                               [IN]        pointer of video component
 *  total_frame_count                   [IN]
 *  total_time_duration                 [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_video_get_video_info(
      gui_video_struct *video,
      U32 *total_frame_count,
      U64 *total_time_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(video != NULL);
    MMI_DBG_ASSERT(video->active == MMI_TRUE);
    *total_frame_count = video->video_info.total_frame_count;
    *total_time_duration = video->video_info.total_time_duration;
}



