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
 *  wgui_video.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_VIDEO_H__
#define __WGUI_VIDEO_H__

/*****************************************************************************
 * include
 ****************************************************************************/
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "gdi_datatype.h"
#include "gui_typedef.h"

/*****************************************************************************
 * Define
 ****************************************************************************/


/*****************************************************************************
 * Typedef
 ****************************************************************************/

/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_create
 * DESCRIPTION
 *  Create a video component.
 * REMARKS
 *  1. User can use a video file or a video resource to create video component.
 *  If use both to create, video component will first use video resource.
 *  2. This API should be paired with wgui_video_close.
 * PARAMETERS
 *  target_layer     : [IN] Is the target layer handle that display video component
 *  x                : [IN] Is the x position of video component
 *  y                : [IN] Is the y position of video component
 *  width            : [IN] Is the width of video component
 *  height           : [IN] Is the height of video component
 *  file_name        : [IN] Is the file name of video file
 *  video_id         : [IN] Is the resource ID of video
 *  flag             : [IN] Is the flag that record infomation of audio path, loop, etc.
 * RETURNS
 * RETURNS
 *  MDI_RESULT
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : If create video component succeed.
 * SEE ALSO
 *  You should also know wgui_video_close as well.
 *****************************************************************************/
extern MDI_RESULT wgui_video_create(
                         gdi_handle target_layer,
                         S32 x,
                         S32 y,
                         S32 width,
                         S32 height,
                         S8 *file_name,
                         U16 video_id,
                         U32 flag);


/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_close
 * DESCRIPTION
 *  Close a video component
 * REMARKS
 *  This API should be paired with wgui_video_create.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE : If close succeed.
 * SEE ALSO
 *  You should also know wgui_video_create as well.
 *****************************************************************************/
extern MMI_BOOL wgui_video_close(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_play
 * DESCRIPTION
 *  Play the video of video component.
 * PARAMETERS
 *  blt_layer_flag       : [IN] Is the layers that should be blt by hardware
 *  play_layer_flag      : [IN] Is the layer that driver to update a video playback
 *  is_visible           : [IN] Is the flag of whether video to update visibility or not
 *  is_play_audio        : [IN] Is the attribute of whether to play audio or not
 * RETURNS
 *  MDI_RESULT
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : If play video succeed.
 *****************************************************************************/
extern MDI_RESULT wgui_video_play(
                         U32 blt_layer_flag,
                         U32 play_layer_flag,
                         MMI_BOOL is_visible,
                         MMI_BOOL is_play_audio);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_seek
 * DESCRIPTION
 *  Seek a time of video.
 * PARAMETERS
 *  time             : [IN] Is the time want to seek
 * REMARKS
 *  The time should be a value in millisecond.
 * RETURNS
 *  MDI_RESULT
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : If seek video succeed.
 *****************************************************************************/
extern MDI_RESULT wgui_video_seek(U64 time);


/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_stop
 * DESCRIPTION
 *  Stop the play of video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_stop(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_move
 * DESCRIPTION
 *  Move video component to a new position.
 * PARAMETERS
 *  x                : [IN] Is the new x position of video component
 *  y                : [IN] Is the new y position of component
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_move(S32 x, S32 y);


/*****************************************************************************
 * <group dom_video_wgui_layer_basic>
 * FUNCTION
 *  wgui_video_resize
 * DESCRIPTION
 *  Resize video component to a new dimension.
 * PARAMETERS
 *  width                : [IN] Is the new width of video component
 *  height               : [IN] Is the new height of video component
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_resize(S32 width, S32 height);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_clip
 * DESCRIPTION
 *  Set clip to video component.
 * REMARKS
 *  This clip should be a physical coordinate. Video component will help to
 *  convert it to logic coordinate of video's target layer.
 * PARAMETERS
 *  x1               : [IN] Is the physical x position of clip's left-top point
 *  y1               : [IN] Is the physical y position of clip's left-top point
 *  x2               : [IN] Is the physical x position of clip's rigth-bottom point
 *  y2               : [IN] Is the physical y position of clip's rigth-bottom point
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_stop_time
 * DESCRIPTION
 *  Set stop time to video component.
 * PARAMETERS
 *  stop_time               : [IN] Is the stop time of video
 * REMARKS
 *  The time should be a value in millisecond.
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE : if set stop time succeed.
 *****************************************************************************/
extern MMI_BOOL wgui_video_set_stop_time(U64 stop_time);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_volume
 * DESCRIPTION
 *  Set volume to video component.
 * PARAMETERS
 *  volume               : [IN] Is the new volume of video
 * REMARKS
 *  The volume should be a value between LEVEL1 ~ LEVEL7.
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_volume(U16 volume);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_get_volume
 * DESCRIPTION
 *  Get volume of video component.
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 * RETURN VALUES
 *  U16 : Is a value between LEVEL1 ~ LEVEL7.
 *****************************************************************************/
extern U16 wgui_video_get_volume(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_increase_volume
 * DESCRIPTION
 *  Increase volume of video component.
 * REMARKS
 *  The highest level is LEVEL7.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_increase_volume(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_decrease_volume
 * DESCRIPTION
 *  Decrease volume of video component.
 * REMARKS
 *  The lowest level is LEVEL1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_decrease_volume(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_repeat_count
 * DESCRIPTION
 *  Set video's repeat play count to video component.
 * PARAMETERS
 *  repeat_count          : [IN] Is the repeat play count
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_repeat_count(U16 repeat_count);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_play_callback
 * DESCRIPTION
 *  Set play callback function to video component.
 * PARAMETERS
 *  f               : [IN] Is the handler of play callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_play_callback(void (*f)(MDI_RESULT));


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_play_speed
 * DESCRIPTION
 *  Set play speed to video component.
 * PARAMETERS
 *  play_speed       : [IN] Is the play speed of video
 * REMARKS
 *  Play speed is a value between VDOPLY_FEATURE_SPEED_0 ~ VDOPLY_FEATURE_SPEED_8.
 *  Usually we use VDOPLY_FEATURE_SPEED_1.
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_play_speed(S16 play_speed);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_get_video_position
 * DESCRIPTION
 *  Get the position of video component.
 * PARAMETERS
 *  x                : [IN/OUT] Is the pointer of parameter to get x position
 *  y                : [IN/OUT] Is the pointer of parameter to get y position
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_get_video_position(S32 *x, S32 *y);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_get_current_time
 * DESCRIPTION
 *  Get current play time of video component.
 * PARAMETERS
 *  void
 * RETURNS
 *  U64
 * RETURN VALUES
 *  U64 : Is a value in millisecond.
 *****************************************************************************/
extern U64 wgui_video_get_current_time(void);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_get_video_info
 * DESCRIPTION
 *  Get video information of video component.
 * PARAMETERS
 *  total_frame_count            : [IN/OUT] Is the pointer of parameter to get total frame count
 *  total_time_duration          : [IN/OUT] Is the pointer of parameter to get total time duration
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_get_video_info(
             U32 *total_frame_count,
             U64 *total_time_duration);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_get_history
 * DESCRIPTION
 *  Get the history of video component.
 * PARAMETERS
 *  history      : [IN/OUT] Is the pointer of parameter to get history of video component
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_get_history(wgui_video_history_struct *history);


/*****************************************************************************
 * <group dom_video_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_video_set_history
 * DESCRIPTION
 *  Set the history of video
 * PARAMETERS
 *  history      : [IN] Is the history of video component
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_video_set_history(wgui_video_history_struct *history);

#endif /* __WGUI_VIDEO_H__ */

