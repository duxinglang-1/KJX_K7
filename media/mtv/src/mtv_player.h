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
 *   mtv_player.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_PLAYER_H
#define _MTV_PLAYER_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#ifndef _MTV_SPI_H
#include "mtv_spi.h"
#endif

#ifndef _MTV_CONTROL_H
#include "mtv_control.h"
#endif

#ifndef _MTV_SRC_STAT_H
#include "mtv_src_stat.h"
#endif

#include "kal_general_types.h"
#include "med_struct.h"
#include "mtv_error.h"
#include "mtv_codec.h"
#include "med_global.h"

/**
  * Mobile TV player state.
  */
typedef enum
{
    MTV_PLAYER_STATE_STOPPED,   /**< the player is stopped */
    MTV_PLAYER_STATE_INITED,    /**< the player is initialized and ready to play */
    MTV_PLAYER_STATE_STARTED    /**< the player is playing */

} mtv_player_state_t;

/**
  * Indicates the current buffering level of media decoder.
  */
typedef enum
{
    MTV_PLAYER_BUFFER_LEVEL_FAMINE,
    MTV_PLAYER_BUFFER_LEVEL_LOW,
    MTV_PLAYER_BUFFER_LEVEL_NORMAL,
    MTV_PLAYER_BUFFER_LEVEL_HIGH,
    MTV_PLAYER_BUFFER_LEVEL_FLOOD

} mtv_player_buffer_level_t;

typedef struct mtv_player_client_t mtv_player_client_t;

/**
  * Client interface of player.
  */
struct mtv_player_client_t
{
    kal_uint32 session_id;

    /**
      * Notify the client about audio related error.
      */
    void (*on_audio_error)(mtv_player_client_t* client, kal_int32 error);

    /**
      * Notify the client about video related error.
      */
    void (*on_video_error)(mtv_player_client_t* client, kal_int32 error);

    /**
      * Notify the client about state change.
      */
    void (*on_state_change)(mtv_player_client_t* client, mtv_player_state_t state, mtv_result_t reason);

    /**
      * Notify the client about rate change.
      */
    void (*on_rate_change)(mtv_player_client_t* client, kal_int32 new_rate);

    /**
      * Notify the client about the restart of player.
      */
    void (*on_restart)(mtv_player_client_t* client);
};

typedef struct mtv_player_config_t
{
    mtv_player_client_t* client;    /**< the client who uses this interface */
    mtv_spi_service_info_t* info;   /**< service information which is necessary for initialization of decoders. */

    media_config_audio_struct* audio_config;    /**< audio configuration */
    media_config_video_struct* video_config;    /**< video configuration */

#if defined(__MED_MTV_MOD__)
    kal_uint32* audio_au_duration;  /**< duration of audio AU */
    kal_uint32* video_au_duration;  /**< duration of video AU */

    kal_uint32 min_buffer_ms;       /**< indicates the minimum duration (in milliseconds) of buffered audio/video data to start play */
#endif  // #if defined(__MED_MTV_MOD__)

} mtv_player_config_t;

typedef struct mtv_player_t mtv_player_t;

/**
  * Abstract Mobile TV player interface. The same interface is used for MoDIS and target.
  */
struct mtv_player_t
{
    /**
      * Allocate HW resource and start playback. Note that the playback will started only after
      * enough AUs are delivered. After a player is started, it may restart itself if any decoder
      * error occurred.
      *
      * @param cfg [in] player configuration
      * @see deliver_au
      */
    mtv_result_t (*start)(
        mtv_player_t* player, mtv_player_config_t* cfg);

#if defined(__MED_MTV_MOD__)
    mtv_result_t (*pause_visual_update)(
        mtv_player_t* player);

    mtv_result_t (*resume_visual_update)(
        mtv_player_t* player, mtv_player_config_t* cfg);
#endif

    /**
      * Query specified control interface.
      *
      * @param control_id [in] control ID
      * @param control [out] to receive specified control
      */
    mtv_result_t (*get_control)(mtv_player_t* player, mtv_control_t control_id, void** control);

    /**
      * Snapshot.
      *
      * @param control_id [in] the image file path to store current screen.
      */
    mtv_result_t (*snapshot)(mtv_player_t* player, void* param);

    /**
      * Query player state.
      *
      * @return current player state
      */
    mtv_player_state_t (*get_state)(mtv_player_t* pthis);

#if defined(__MED_MTV_MOD__)
    /**
      * Deliver an AU to the player.
      *
      * @param st [in] stream type of AU
      * @param au [in] AU data
      */
    mtv_result_t (*deliver_au)(mtv_player_t* player, mtv_stream_type_t st, mtv_packet_t* au);
#endif

#if defined(__MTV_TS_SUPPORT__)
    /**
      * Get buffer level of specified stream type.
      *
      * @param st [in] stream type to query
      * @return buffer level of specified stream type
      */
    mtv_player_buffer_level_t (*get_buffer_level)(mtv_player_t* player, mtv_stream_type_t st);

    /**
      * Get duration of buffered audio/video data.
      *
      * @return duration in milliseconds
      */
    kal_uint32 (*get_buffer_duration)(mtv_player_t* player);
#endif

    /**
      * Stop playback and release all required HW resources.
      */
    mtv_result_t (*stop)(mtv_player_t* player);

    /**
      * Destroy the instance.
      */
    void (*destroy)(mtv_player_t* player);

    kal_uint16 app_id;
};

extern mtv_player_t* construct_cyberlink_player(kal_uint16 app_id);
extern mtv_player_t* construct_mtv_streaming_player(kal_uint16 app_id);

#endif /* _MTV_PLAYER_H */

