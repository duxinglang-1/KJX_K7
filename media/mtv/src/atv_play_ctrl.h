/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ATV_player.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ATV_PLAY_CTRL_H
#define _ATV_PLAY_CTRL_H

#ifndef _MED_GLOBAL_H
#include "med_global.h"
#endif

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#ifndef _MTV_PLAYER_H
#include "mtv_player.h"
#endif

#ifndef _MTV_RECORDER_H
#include "mtv_recorder.h"
#endif

#ifdef __ATV_RECORD_SUPPORT__
    #include "mpl_recorder.h"
#endif

typedef enum
{
    ATV_PLAYER_STATE_STOPPED,
    ATV_PLAYER_STATE_INITED,
    ATV_PLAYER_STATE_STARTED,
    ATV_PLAYER_STATE_CLOSED     // for destructor

} atv_player_state_t;

typedef enum
{
    ATV_RECORDER_STATE_STOPPED,
    ATV_RECORDER_STATE_STARTED,
    ATV_RECORDER_STATE_UPDATE_BLT_PAUSED,
    ATV_RECORDER_STATE_PAUSED,
    ATV_RECORDER_STATE_SAVING,
    ATV_RECORDER_STATE_CLOSED   // for destructor

} atv_recorder_state_t;

typedef enum
{
    ATV_STREAM_REC_STATE_STOPPED,
    ATV_STREAM_REC_STATE_STARTED,
    ATV_STREAM_REC_STATE_PAUSED

} atv_stream_rec_state_t;

typedef enum
{
    ATV_REC_PAUSED_BY_PLAYER,
    ATV_REC_PAUSED_BY_RECORDER

} atv_rec_pause_reason_t;


typedef struct atv_play_ctrl_t atv_play_ctrl_t;
/**
  * Analog TV playback controller based on mtv player / recorder API.
  */
struct atv_play_ctrl_t
{
    /* interface */
    mtv_player_t player_itf;

    kal_uint16 app_id;

    /* player related */
    mtv_control_video_t player_video_ctrl;
    mtv_player_config_t player_config;
    atv_player_state_t player_state;

    /* others */
    kal_bool player_video_inited;
    kal_bool player_video_started;
    kal_bool player_audio_inited;
    kal_uint8* player_buffer2;
    kal_uint8* player_buffer3;

#ifdef __ATV_RECORD_SUPPORT__
    /* recorder related */
    mtv_recorder_t recorder_itf;
    atv_recorder_state_t recorder_state;
    atv_rec_pause_reason_t recorder_pause_reason;

    mpl_recorder_t *mpl_recorder;
    mpl_recorder_client_t mpl_recorder_client;
    media_error_t last_mpl_error;

    void* rec_allocated_ext_mem;
    kal_bool record_audio;

    kal_wchar storing_path[MAX_FILE_NAME_LEN + 1];
#endif
};

/* instance creation */
extern mtv_player_t* construct_atv_player(kal_uint16 app_id);

/* instance creation */
extern mtv_recorder_t* construct_atv_recorder(kal_uint16 app_id);

#endif /* _ATV_PLAY_CTRL_H */


