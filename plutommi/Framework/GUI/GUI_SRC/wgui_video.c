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
 *  wgui_video.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "mdi_datatype.h"
#include "gdi_datatype.h"
#include "gui_typedef.h"
#include "gui_video.h"
#include "wgui_video.h"


/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

/* Declare your local function here */

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */
gui_video_struct g_wgui_video;

/*****************************************************************************
 * Local Function
 ****************************************************************************/



/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */

/*****************************************************************************
 * FUNCTION
 *  wgui_video_create
 * DESCRIPTION
 *  create a video component
 *  User can use a video file or a video res to create
 *  If user use both to create, video component will first use res to create.
 * PARAMETERS
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
MDI_RESULT wgui_video_create(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_create(
               &g_wgui_video,
               target_layer,
               x,
               y,
               width,
               height,
               file_name,
               video_id,
               flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_close
 * DESCRIPTION
 *  close a video component
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_video_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_close(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_play
 * DESCRIPTION
 *  play a video component
 * PARAMETERS
 *  blt_layer_flag      [IN]    layer should be blt by hardware
 *  play_layer_flag     [IN]    layer that driver to update a video playback
 *  is_visible          [IN]    visibility
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT wgui_video_play(
                  U32 blt_layer_flag,
                  U32 play_layer_flag,
                  MMI_BOOL is_visible,
                  MMI_BOOL is_play_audio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_play(
               &g_wgui_video,
               blt_layer_flag,
               play_layer_flag,
               is_visible,
               is_play_audio);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_seek
 * DESCRIPTION
 *  seek a time of video
 * PARAMETERS
 *  time            [IN]        time want seek
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT wgui_video_seek(U64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_seek(&g_wgui_video, time);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_stop
 * DESCRIPTION
 *  stop display of video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_stop(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_move
 * DESCRIPTION
 *  move video component
 * PARAMETERS
 *  x               [IN]        new x pos of component
 *  y               [IN]        new y pos of component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_move(&g_wgui_video, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_resize
 * DESCRIPTION
 *  resize video component
 * PARAMETERS
 *  width               [IN]        width of component
 *  height              [IN]        height pos of component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_resize(&g_wgui_video, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_clip
 * DESCRIPTION
 *  set video component's clip
 * PARAMETERS
 *  x1              [IN]    physical coordinate x1 of video clip
 *  y1              [IN]    physical coordinate y1 of video clip
 *  x2              [IN]    physical coordinate x2 of video clip
 *  y2              [IN]    physical coordinate y2 of video clip
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_set_clip(&g_wgui_video, x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_stop_time
 * DESCRIPTION
 *  set video component's stop time
 * PARAMETERS
 *  stop_time              [IN]    stop time of video
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_video_set_stop_time(U64 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_set_stop_time(&g_wgui_video, stop_time);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_volume
 * DESCRIPTION
 *  set video component's volume
 * PARAMETERS
 *  volume              [IN]    volume of video, it shoud be a value between 
 *                              LEVEL1 ~ LEVEL7
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_volume(U16 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_set_volume(&g_wgui_video, volume);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_play_speed
 * DESCRIPTION
 *  set video component's play speed
 * PARAMETERS
 *  play_speed                  [IN]    play speed of video
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_play_speed(S16 play_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_set_play_speed(&g_wgui_video, play_speed);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_get_volume
 * DESCRIPTION
 *  get video component's volume
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 wgui_video_get_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_get_volume(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_increase_volume
 * DESCRIPTION
 *  increase video component's volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_increase_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_increase_volume(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_decrease_volume
 * DESCRIPTION
 *  decrease video component's volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_decrease_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_decrease_volume(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_repeat_count
 * DESCRIPTION
 *  set video component's repeat_count
 * PARAMETERS
 *  repeat_count              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_repeat_count(U16 repeat_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_set_repeat_count(&g_wgui_video, repeat_count);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_play_callback
 * DESCRIPTION
 *  set video component's play callback
 * PARAMETERS
 *  f              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_play_callback(void (*f)(MDI_RESULT))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_set_play_callback(&g_wgui_video, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_get_video_position
 * DESCRIPTION
 *  get video component's video position
 * PARAMETERS
 *  x               [IN]        pointer of x pos
 *  y               [IN]        pointer of y pos
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_get_video_position(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_get_video_position(&g_wgui_video, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_get_current_time
 * DESCRIPTION
 *  get video component's current time
 * PARAMETERS
 *  void
 * RETURNS
 *  U64
 *****************************************************************************/
U64 wgui_video_get_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_video_get_current_time(&g_wgui_video);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_get_video_info
 * DESCRIPTION
 *  get video component's video info
 * PARAMETERS
 *  total_frame_count                   [IN]    total frame count
 *  total_time_duration                 [IN]    total time duration
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_get_video_info(U32 *total_frame_count, U64 *total_time_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_video_get_video_info(&g_wgui_video, total_frame_count, total_time_duration);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_get_history
 * DESCRIPTION
 *  get the history of video component
 * PARAMETERS
 *  history     [OUT]   store video history
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_get_history(wgui_video_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->volume = g_wgui_video.volume;
    history->current_play_time = g_wgui_video.current_play_time;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_video_set_history
 * DESCRIPTION
 *  set the history of video
 * PARAMETERS
 *  history     [IN] history of video
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_video_set_history(wgui_video_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_video.volume = history->volume;
    g_wgui_video.current_play_time = history->current_play_time;
}




