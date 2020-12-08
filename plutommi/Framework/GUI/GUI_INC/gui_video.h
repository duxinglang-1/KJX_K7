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
 *  gui_video.h
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
#ifndef __GUI_VIDEO_H__
#define __GUI_VIDEO_H__

/*****************************************************************************
 * include
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "mdi_datatype.h"
#include "mdi_video.h"
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * Define
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_video_macro>
 *  A flag which represents the path type of audio. */
#define GUI_VIDEO_AUDIO_PATH_TYPE               0x0000000f
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_video_macro>
 *  Is a flag which represents to send keypad sound on audio device. */
#define GUI_VIDEO_AUDIO_PATH_SPEAKER            0x00000000
/* <group dom_video_macro>
 *  Is a flag flag which represents to send microphone sound on audio device. */
#define GUI_VIDEO_AUDIO_PATH_MICROPHONE         0x00000001
/* <group dom_video_macro>
 *  Is a flag flag which represents to send earphone sound on audio device. */
#define GUI_VIDEO_AUDIO_PATH_SPEAKER2           0x00000002
/* <group dom_video_macro>
 *  Is a flag flag which represents loudspeaker for free sound. */
#define GUI_VIDEO_AUDIO_PATH_LOUDSPEAKER        0x00000003

#define GUI_VIDEO_AUDIO_PATH_SPEAKER_BOTH       0x00000004
/* <group dom_video_macro>
 *  Is a flag flag which represents to OR bitwise with above audio output devices */
#define GUI_VIDEO_AUDIO_PATH_BT_HEADSET         0x00000005

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_video_macro>
 *  Is a flag flag which represents the rotate type. */
#define GUI_VIDEO_ROTATE_TYPE                   0x00000f00
/* DOM-NOT_FOR_SDK-END */

/* <group dom_video_macro_flags>
 *  Is a flag flag which represents video to apply LCD rotate by 0 angle. */
#define GUI_VIDEO_ROTATE_0                      0x00000000
/* <group dom_video_macro_flags>
 *  Is a flag flag which represents video to apply LCD rotate by 90 angle. Not support at present. */
#define GUI_VIDEO_ROTATE_90                     0x00000100
/* <group dom_video_macro_flags>
 *  Is a flag flag which represents video to apply LCD rotate by 180 angle. Not support at present. */
#define GUI_VIDEO_ROTATE_180                    0x00000200
/* <group dom_video_macro_flags>
 *  Is a flag flag which represents video to apply LCD rotate by 270 angle. Not support at present. */
#define GUI_VIDEO_ROTATE_270                    0x00000300

/* <group dom_video_macro>
 *  DOM-NOT_FOR_SDK-BEGIN */
#define GUI_VIDEO_ROTATE_0_MIRROR               0x00000400
/* <group dom_video_macro> */
#define GUI_VIDEO_ROTATE_90_MIRROR              0x00000500
/* <group dom_video_macro> */
#define GUI_VIDEO_ROTATE_180_MIRROR             0x00000600
/* <group dom_video_macro> */
#define GUI_VIDEO_ROTATE_270_MIRROR             0x00000700
/* DOM-NOT_FOR_SDK-END */

/* <group dom_video_macro>
 *  DOM-NOT_FOR_SDK-BEGIN */
#define GUI_VIDEO_PLAY_STATE    1
/* <group dom_video_macro> */
#define GUI_VIDEO_STOP_STATE    0

/* <group dom_video_macro> */
#define GUI_VIDEO_DEFAULT_PLAY_SPEED        100
/* <group dom_video_macro> */
#define GUI_VIDEO_DEFAULT_REPEAT_COUNT      1
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * Typedef
 ****************************************************************************/
/* <group dom_video_macro> */
typedef struct
{
    /* position and dimension of component, physical coordinate */
    S32 x, y, width, height;
    /* record target layer's dimension, it will not change
     * after component be created
     */
    S32 layer_width, layer_height;
    /* clip area of video component, physical coordinate */
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    /* video's pos and size, physical coordinate */
    S32 video_x, video_y, video_width, video_height;

    /* layer that video will play */
    gdi_handle target_layer;
    U64 current_play_time;
    U32 flag; /* information of audio path, loop, etc */

    void (*play_callback)(MDI_RESULT);

    PS8 file_name; /* video from file */
    U16 video_id; /* video from id */

    U16 volume;
    U16 repeat_count;
    U16 rotate;
    S16 play_speed;
    U16 video_state; /* record play/stop state of video */
    /* use stop_time_set as a flag, when user set stop time after
     * video play, it will be set to prevent user to set it second time
     */
    MMI_BOOL stop_time_setted;
    MMI_BOOL active; /* is video component be create or not */

    mdi_video_info_struct video_info;
    U8 audio_path;
} gui_video_struct;

/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* APIs for category screen */
extern MDI_RESULT gui_video_create(
                   gui_video_struct *video,
                   gdi_handle target_layer,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   S8 *file_name,
                   U16 video_id,
                   U32 flag);
extern MMI_BOOL gui_video_close(gui_video_struct *video);
extern MDI_RESULT gui_video_play(
                   gui_video_struct *video,
                   U32 blt_layer_flag,
                   U32 play_layer_flag,
                   MMI_BOOL is_visible,
                   MMI_BOOL is_play_audio);
extern MDI_RESULT gui_video_seek(gui_video_struct *video, U64 time);
extern void gui_video_stop(gui_video_struct *video);
extern void gui_video_move(gui_video_struct *video, S32 x, S32 y);
extern void gui_video_resize(gui_video_struct *video, S32 width, S32 height);
extern MMI_BOOL gui_video_set_stop_time(gui_video_struct *video, U64 stop_time);
extern void gui_video_set_volume(gui_video_struct *video, U16 volume);
extern U16 gui_video_get_volume(gui_video_struct *video);
extern void gui_video_increase_volume(gui_video_struct *video);
extern void gui_video_decrease_volume(gui_video_struct *video);
extern void gui_video_set_repeat_count(gui_video_struct *video, U16 repeat_count);
extern void gui_video_set_play_callback(gui_video_struct *video, void (*f)(MDI_RESULT));
extern void gui_video_get_video_position(gui_video_struct *video, S32 *x, S32 *y);
extern U64 gui_video_get_current_time(gui_video_struct *video);
extern void gui_video_get_video_info(
             gui_video_struct *video,
             U32 *total_frame_count,
             U64 *total_time_duration);
extern void gui_video_set_clip(gui_video_struct *video, S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_video_set_play_speed(gui_video_struct *video, S16 play_speed);

/* DOM-NOT_FOR_SDK-END */

#endif /* __GUI_VIDEO_H__ */

