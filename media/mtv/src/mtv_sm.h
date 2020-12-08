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
 *   mtv_sm.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#ifndef _MTV_SM_H
#define _MTV_SM_H

#ifndef _MTV_SPI_H
#include "mtv_spi.h"
#endif

#ifndef _MTV_CONTROL_H
#include "mtv_control.h"
#endif

#ifndef _MTV_PLAYER_H
#include "mtv_player.h"
#endif

#ifndef _MTV_RECORDER_H
#include "mtv_recorder.h"
#endif

#if defined(__MED_ATV_MOD__)
#ifndef _ATV_PLAY_CTRL_H
#include "atv_play_ctrl.h"
#endif
#endif

#ifndef _MTV_BUFFER_ENGINE_H
#include "mtv_buffer_engine.h"
#endif

#ifndef _MTV_SRC_STAT_H
#include "mtv_src_stat.h"
#endif

#include "mtv_codec.h"
#include "kal_general_types.h"
#include "med_struct.h"
#include "med_global.h"
#include "mtv_error.h"
#include "mtv_comm.h"

#define MTV_SERVICE_INVALID_ID  0xFFFFFFFF

/**
  * Service state.
  */
typedef enum
{
    MTV_SERVICE_STATE_STOPPED,
    MTV_SERVICE_STATE_STARTED,
    MTV_SERVICE_STATE_READY,

    /**
      * The service failed to send any data. The client should stop it explicitly.
      */
    MTV_SERVICE_STATE_ABORTED,

    /**
      * The service has been removed. Its context should be removed after it is stopped.
      */
    MTV_SERVICE_STATE_REMOVED

} mtv_service_state_t;

/**
  * Service CA state.
  */
typedef enum
{
    MTV_SERVICE_CA_STATE_ACCESS_DENIED,  /**< access to the service is denied */
    MTV_SERVICE_CA_STATE_ACCESS_GRANTED /**< access to the service is granted */

} mtv_service_ca_state_t;

/**
  * Service CA state.
  */
typedef enum
{
    MTV_RECEPTION_STATE_BAD,
    MTV_RECEPTION_STATE_GOOD

} mtv_service_reception_state_t;

/**
  * Get service context method.
  */
typedef enum
{
    MTV_GET_SC_METHOD_SERVICE_ID,       /**< get service context by service id */
    MTV_GET_SC_METHOD_INDEX             /**< get service context by sc list index */

} mtv_get_sc_method_t;

/**
  * Media information of a TV service.
  */
typedef struct
{
    mtv_stream_info_t audio_st;
    mtv_stream_info_t video_st;

} mtv_service_media_info_t;

/**
  * Running service context
  */
typedef struct mtv_service_context_t
{
    struct mtv_service_context_t* next;     /**< next context in chain */

    kal_uint32 owner;                       /**< service manager that owns this service */
    kal_uint32 session_id;                  /**< client-specified session ID */

    mtv_spi_service_info_t info;            /**< service info */
    mtv_service_state_t state;              /**< service state */
#if defined(__MED_MTV_MOD__)
    mtv_service_ca_state_t ca_state;        /**< CA state */
#endif
    mtv_service_reception_state_t reception_state;

    media_mtv_service_info_struct public_info;

    mtv_spi_component_info_t* audio_comp;
    mtv_spi_component_info_t* video_comp;

    mtv_player_t* player;                   /**< player for this service */
    mtv_player_client_t player_client;      /**< client interface for the player */

#if defined(__MTV_REC_SUPPORT__)
    mtv_recorder_t* recorder;               /**< recorder for this service */
    mtv_recorder_client_t recorder_client;  /**< client interface for the recorder */

    volatile kal_bool saving_aborted;       /**< whether the saving should be aborted */
#endif

    /**
      * Indicates the activities this service is performing such as play or record.
      * One purpose of these activity flags are to indicate the required H/W resource
      * is allocated. The other purpose is to 'reserve' the required resource. For example,
      * when the player is in PAUSED state, it will not use any decoder resource but we
      * need to guarantee it can acquire the resource when it is unpaused. Therefore,
      * we need to exclude other services from playing by setting the PLAY activity flag.
      *
      * @see media_mtv_service_activity_enum
      * @see sm_check_service_activities
      */
    kal_uint32 activities;

#if defined(__MED_MTV_MOD__)
    mtv_buffer_engine_t* be;                /**< buffer engine */
    mtv_buffer_engine_client_t be_client;   /**< client interface for the buffer engine */

    mtv_buffer_engine_t* unsaved_be;        /**< the buffer engine to save later */

    kal_uint32 be_audio_stream;             /**< the audio stream index for buffer engine */
    kal_uint32 be_video_stream;             /**< the video stream index for buffer engine */

    mtv_source_stat_t video_src_stat;       /**< maintain statistics about video data */
    mtv_source_stat_t audio_src_stat;       /**< maintain statistics about audio data */

    kal_bool av_offset_compensated;         /**< indicates whether A/V offset have been compensated */
    kal_uint32 dispatch_flags;              /**< for delayed playback */
#endif

    kal_uint32 start_service_time;          /**< the time a service is started */
    kal_uint32 player_started;              /**< the count a service has been played */

} mtv_service_context_t;

/**
  * Additional read-only service parameter can be queried by mtv_sm_t.get_service_param.
  */
typedef enum
{
    MTV_SERVICE_PARAM_SIGNAL_STRENGTH,      /**< signal strength. valid range is 0 to 100. */
    MTV_SERVICE_PARAM_SRC_WIDTH,            /**< the width of the source picture in pixels */
    MTV_SERVICE_PARAM_SRC_HEIGHT,           /**< the height of the source picture in pixels */
    MTV_SERVICE_PARAM_SRC_ASPECT_RATIO_X,   /**< the x part of source aspect ratio such as 4 for 4:3 */
    MTV_SERVICE_PARAM_SRC_ASPECT_RATIO_Y,    /**< the y part of source aspect ratio such as 3 for 4:3 */

    /* AnalogTV */
    MTV_SERVICE_PARAM_PAUSE,
    MTV_SERVICE_PARAM_RESUME,
    MTV_SERVICE_PARAM_DISABLE,
    MTV_SERVICE_PARAM_NAME,
    MTV_SERVICE_PARAM_AUDIO_MODE,
    MTV_SERVICE_PARAM_VIDEO_MODE,

    /* CMMB */
    MTV_SERVICE_PARAM_SUBSCRIBE,
    MTV_SERVICE_PARAM_UNSUBSCRIBE,
    MTV_SERVICE_PARAM_ACCOUNT_INQUIRY,
    MTV_SERVICE_PARAM_SERVICE_CA,
    MTV_SERVICE_PARAM_DOWNLOAD_SG,
    MTV_SERVICE_PARAM_UPDATE_SG,
    MTV_SERVICE_PARAM_ESG_SOURCE,
    MTV_SERVICE_PARAM_SIM_INFO,
    MTV_SERVICE_PARAM_NET_INFO,
    MTV_SERVICE_PARAM_GBA,
    MTV_SERVICE_PARAM_SUBSCRIPTION_UPDATE,
    MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTION_UPDATE,
    MTV_SERVICE_PARAM_MSK_RETRIEVE,
    MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER,
    MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED,
    MTV_SERVICE_PARAM_UPGRADE_QUERY,
    MTV_SERVICE_PARAM_AREA_SET_RETRIEVE,
    MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE,
    MTV_SERVICE_PARAM_IMD_COUNT,
    MTV_SERVICE_PARAM_IMD_DESC,
    MTV_SERVICE_PARAM_IMD_DETAIL,
    MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC,
    MTV_SERVICE_PARAM_EMM_INFO,
    MTV_SERVICE_PARAM_CA_INFO,
    MTV_SERVICE_PARAM_NIT_TIME,
    MTV_SERVICE_PARAM_NIT_AREA
} mtv_service_param_t;

/**
  * Service event code.
  */
typedef enum
{
    MTV_SERVICE_EVENT_SEARCH_PROGRESS,  /**< notify about the progress of service searching */

    MTV_SERVICE_EVENT_CLOSED,           /**< service manager has been closed */
    MTV_SERVICE_EVENT_FATAL_ERROR,      /**< fatal error */

    MTV_SERVICE_EVENT_FOUND,            /**< a new service is found */
    MTV_SERVICE_EVENT_STARTED,          /**< a service is statted */
    MTV_SERVICE_EVENT_READY,            /**< a started service is ready to run */
    MTV_SERVICE_EVENT_ADDED,            /**< a new service is added */
    MTV_SERVICE_EVENT_UPDATED,          /**< an existing service is updated */
    MTV_SERVICE_EVENT_STOPPED,          /**< a service has been stopped */
    MTV_SERVICE_EVENT_ABORTED,          /**< a service has been aborted */
    MTV_SERVICE_EVENT_REMOVED,          /**< an existing service will be removed */
    MTV_SERVICE_EVENT_ACCESS_GRANTED,   /**< access to a service is denied */
    MTV_SERVICE_EVENT_ACCESS_DENIED,    /**< access to a service is denied */

    MTV_SERVICE_EVENT_BAD_RECEPTION,    /**< signal reception is bad */
    MTV_SERVICE_EVENT_GOOD_RECEPTION,   /**< signal reception is good */

    MTV_SERVICE_EVENT_PLAYER_STARTED,
    MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_PAUSED,
    MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_DELAYED,
    MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_LIVE,
    MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_ERROR,
    MTV_SERVICE_EVENT_PLAYER_BEGINNING_OF_CONTENT,
    MTV_SERVICE_EVENT_PLAYER_END_OF_CONTENT,
    MTV_SERVICE_EVENT_PLAYER_ERROR,
    MTV_SERVICE_EVENT_PLAYER_STOPPED,
    MTV_SERVICE_EVENT_PLAYER_RATE_CHANGE,

    MTV_SERVICE_EVENT_RECORDER_STARTED,
    MTV_SERVICE_EVENT_RECORDER_SAVING,
    MTV_SERVICE_EVENT_RECORDER_STOPPED,
    MTV_SERVICE_EVENT_RECORDER_ERROR,
    MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED,
    MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED,
    MTV_SERVICE_EVENT_RECORDER_RECORDING_DISCARDED,

    MTV_SERVICE_EVENT_DYNAMIC_LABEL,
    MTV_SERVICE_EVENT_PROGRAM_INFO,
    MTV_SERVICE_EVENT_EMERGENCY_MSG,

    MTV_SERVICE_EVENT_ESG_NEW_AVAILABLE,
    MTV_SERVICE_EVENT_ESG_DOWNLOADED,
    MTV_SERVICE_EVENT_ESG_UPDATED,

    MTV_SERVICE_EVENT_SG_UPDATE_RET,
    MTV_SERVICE_EVENT_UPGRADE_RET,
    MTV_SERVICE_EVENT_INTERACTIVITY_RETRIEVE_RET,
    MTV_SERVICE_EVENT_AREA_RETRIEVE_DATA,
    MTV_SERVICE_EVENT_AREA_RETRIEVE_RET,
    MTV_SERVICE_EVENT_GBA_RET,
    MTV_SERVICE_EVENT_SUBSCRIPTION_UPDATE_RET,
    MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DATA,
    MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DONE,
    MTV_SERVICE_EVENT_SUBSCRIBE_DONE,
    MTV_SERVICE_EVENT_UNSUBSCRIBE_DONE,
    MTV_SERVICE_EVENT_MSK_RETRIEVE_DONE,
    MTV_SERVICE_EVENT_IMD_READY,
    MTV_SERVICE_EVENT_SET_EMM_DONE,
    MTV_SERVICE_EVENT_GET_CA_DONE
} mtv_service_event_t;

typedef enum
{
    MTV_INIT_STATE_IDLE,
    MTV_INIT_STATE_PRE_TUNE,
    MTV_INIT_STATE_HOLD_EVT
} mtv_init_state_t;

typedef struct
{
    mtv_service_context_t* sc;  /**< service context from which the event is generated */
    kal_uint32 service_id;      /**< valid only when sc == NULL */

    mtv_service_event_t event;
    kal_uint32 event_param;
    kal_uint32 session_id;

} mtv_service_callback_param_t;

typedef void (*mtv_service_callback_t)(void* context, mtv_service_callback_param_t* param);

/**
  * Service player status.
  */
typedef struct
{
    kal_uint32 state;           /**< @see media_mtv_player_state_enum */
    kal_uint32 play_delay;      /**< playback delay in milliseconds */
    kal_uint32 max_delay;       /**< maximum delay in milliseconds */
    kal_uint32 buffer_duration; /**< allowable buffer duration in milliseconds. buffer_duration will always be larger than max_delay. */
    kal_int32 play_rate;        /**< current play rate */

} mtv_service_player_status_t;

/* reception quality */

typedef struct
{
    mtv_spi_reception_quality_t quality;    /**< the latest reception quality reported from SP */
    kal_uint32 stable;                      /**< indicate how long the quality is in/out acceptable range */

    kal_uint32 dropped;

} mtv_reception_quality_stat_t;

/* unclosed BE list */

#define MAX_UNCLOSED_BE 2

/**
  * Note that the list only works for one reader thread and one writer thread.
  */
typedef struct
{
    mtv_buffer_engine_t* be[MAX_UNCLOSED_BE];
    kal_uint32 head;
    kal_uint32 tail;

} mtv_unclosed_be_list_t;

typedef enum
{
    MTV_ESG_QUERY_STATE_CLOSED,
    MTV_ESG_QUERY_STATE_OPENED,
    MTV_ESG_QUERY_STATE_QUERY

} mtv_esg_query_state_enum;

/* service manager */

typedef struct mtv_sm_t mtv_sm_t;

/**
  * Mobile TV service manager which has the following responsibilities:
  *
  * - maintains a list of running services.
  * - create decoder for different service type.
  * - configure decoder for different service mode.
  * - pass AUs to player/recorder.
  *
  * The memory space of an instance of service manager is prepared by
  * the client and initialized by construct_mtv_sm.
  */
struct mtv_sm_t
{
    /**
      * Open service manager
      *
      * @param cb [in] client call-back function pointer.
      * @param context [in] opaque client context pointer.
      */
    mtv_result_t (*open)(mtv_sm_t* sm, media_mtv_mode_enum mode, kal_uint16 app_id, void *param, mtv_service_callback_t cb, void* context);

    /**
      * Configure audio and video display settings for different modes.
      *
      * @param audio [in] audio output configuration
      * @param video [in] video display configuration
      * @param record [in] recording configuration
      */
    mtv_result_t (*config)(mtv_sm_t* sm, media_config_audio_struct* audio, media_config_video_struct* video, media_mtv_config_record_struct* record);
        
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    mtv_result_t (*restart_chip)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id);
#endif

    /**
      * Search available services. Note that servic searching is mutually exclusive with
      * service receiving. Therefore, you may get MTV_E_RESOURCE_CONFLICT when some service
      * is already started.
      *
      * @param source [in] specified where to find service list.
      * @return MTV_E_RESOURCE_CONFLICT
      */
    mtv_result_t (*search_services)(mtv_sm_t* sm, media_mtv_service_source_enum source, mtv_freq_band_t band, void *param);

    /**
      * Aborting service searching immediately.
      *
      * @return MTV_S_OK always
      */
    mtv_result_t (*abort_searching)(mtv_sm_t* sm);

    /**
      * Start a service with specified mode.
      *
      * @param service_id [in] service to start
      * @param activities [in] activities to start
      * @param session_id [in] client-specified session_id
      * @see media_mtv_service_mode_enum
      */
    mtv_result_t (*start_service)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 activities, kal_uint32 session_id);

    /**
      * Start the player for specified service.
      *
      * @param service_id [in] the service to start player for
      * @param session_id [in] client-specified session_id
      */
    mtv_result_t (*start_player)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id);

    /**
      * Stop the player for specified service.
      *
      * @param service_id [in] the service to stop player for
      */
    mtv_result_t (*stop_player)(mtv_sm_t* sm, kal_uint32 service_id);

#if defined(__MED_MTV_MOD__)
    mtv_result_t (*pause_visual_update)(mtv_sm_t* sm, kal_uint32 service_id);
    mtv_result_t (*resume_visual_update)(mtv_sm_t* sm, kal_uint32 service_id);
#endif
    /**
      * Snapshot for specified service.
      *
      * @param service_id [in] the service to snapshot
      */
    mtv_result_t (*snapshot)(mtv_sm_t* sm, kal_uint32 service_id, void* param);

    /**
      * Get player state.
      *
      * @param service_id [in] the service to get recorder state
      * @param state [out] the recorder state
      */
    mtv_result_t (*get_player_status)(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_player_status_t* status);

    /**
      * Query specified control interface for a service.
      *
      * @param control_id [in] the control interface to query. @see mtv_control_t
      * @param control [out] the returned control interface
      */
    mtv_result_t (*get_control)(mtv_sm_t* sm, kal_uint32 service_id, mtv_control_t control_id, void** control);

    /**
      * Get service parameter.
      *
      * @param service_id [in] service to get parameter
      * @param param [in] parameter ID
      * @param value [out] address to receive parameter value
      * @see mtv_service_param_t
      */
    mtv_result_t (*get_service_param)(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_param_t param, kal_uint32* value);

    /**
      * Set service parameter.
      *
      * @param service_id [in] service to set parameter
      * @param param [in] parameter ID
      * @param value [in] parameter value
      * @see mtv_service_param_t
      */
    mtv_result_t (*set_service_param)(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_param_t param, kal_uint32 value);


    /**
      * Get a copy of service context.
      *
      * @param service_id [in] service to find
      * @param sc [out] the address of returned context structure
      */
    mtv_result_t (*get_service_context)(mtv_sm_t* sm, mtv_get_sc_method_t method, kal_uint32 param, mtv_service_context_t* sc);

    /**
      * Stop specified service.
      *
      * @param service_id [in] service to stop
      */
    mtv_result_t (*stop_service)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Get media info of specified service.
      * @param service_id [in] service to query
      */
    mtv_result_t (*get_media_info)(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_media_info_t* mi);

    /**
      * Close service manager.
      */
    mtv_result_t (*close)(mtv_sm_t* sm);


#if defined(__MTV_REC_SUPPORT__)
    /**
      * To find unsaved recording in recording directory.
      *
      * @param found [out] KAL_TRUE if there is a unsaved recording. KAL_FALSE otherwise.
      */
    mtv_result_t (*find_unsaved_recording)(mtv_sm_t* sm, kal_bool* found);

    /**
      * Recover unsaved recording.
      */
    mtv_result_t (*recover_recording)(mtv_sm_t* sm);

    /**
      * Abort ongoing recovering of recording file.
      */
    mtv_result_t (*abort_recovering)(mtv_sm_t* sm);

    /**
      * Discard unsaved recording permanently.
      */
    mtv_result_t (*discard_unsaved_recording)(mtv_sm_t* sm);

    /**
      * Start the recorder for specified service.
      *
      * @param service_id [in] the service to start recorder for
      * @param session_id [in] client-specified session_id
      */
    mtv_result_t (*start_recorder)(mtv_sm_t* sm, kal_uint32 service_id, const kal_wchar* service_name, kal_uint32 session_id);

    /**
      * Stop the recorder for specified service.
      *
      * @param service_id [in] the service to stop recorder for
      */
    mtv_result_t (*stop_recorder)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Pause the recorder for specified service.
      *
      * @param service_id [in] the service to pause recorder for
      */
    mtv_result_t (*pause_recorder)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Resume the recorder for specified service.
      *
      * @param service_id [in] the service to resume recorder for
      */
    mtv_result_t (*resume_recorder)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Should be called before saving a recording. Should be called by MTV_CONTROL_MOD.
      *
      * @param service_id [in] the service to save recording for
      */
    mtv_result_t (*prepare_saving)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Convert unsaved buffer into video file. Can be called in MTV_BACKGROUND_MOD.
      *
      * @param service_id [in] the service to save recording for
      */
    mtv_result_t (*save_recording)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id, kal_wchar* file_path);

    /**
      * Abort ongoing saving of recording file.
      *
      * @return MTV_S_OK always
      */
    mtv_result_t (*abort_saving)(mtv_sm_t* sm, kal_uint32 service_id);

    /**
      * Discard unsaved recording.
      *
      * @param service_id [in] the service to discard recording for
      */
    mtv_result_t (*recorder_discard_recording)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id);

    /**
      * Get recorder state.
      *
      * @param service_id [in] the service to get recorder state
      * @param state [out] the recorder state
      */
    mtv_result_t (*get_recorder_state)(mtv_sm_t* sm, kal_uint32 service_id, mtv_recorder_state_t* state);
#endif // #if defined(__MTV_REC_SUPPORT__)

#if defined(__MTV_TS_SUPPORT__)
    /**
      * Allow to explicitly start time-shift. Typically time-shift will be started when player or
      * recorder is started. However, in some scenario, time-shift will be needed when player and
      * recorder are both stopped.
      *
      * @param service_id [in] the service to start time-shift for
      */
    mtv_result_t (*start_timeshift)(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id);
#endif // #if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
    mtv_result_t (*ca_get_card_info)(mtv_sm_t* sm, kal_char **card_number);

    /**
      * Start ESG download.
      */
    mtv_result_t (*esg_download)(mtv_sm_t* sm);

    /**
      * Stop ESG download.
      */
    mtv_result_t (*esg_abort_downloading)(mtv_sm_t* sm);

    /**
      * Send query of esg data to query engine.
      * @param type [in] type of query.
      */
    mtv_result_t (*esg_query)(mtv_sm_t* sm, kal_int32 type, media_mtv_esg_query_struct *query);

    /**
      * Get esg data depend on previous query.
      * @param type [in] type of query.
      */
    mtv_result_t (*esg_get_result)(mtv_sm_t* sm, kal_int32 type, void **buf_p);

    /**
      * Finish previous query.
      */
    mtv_result_t (*esg_query_finish)(mtv_sm_t* sm);

    /**
      * Add one service into my favorite.
      */
    mtv_result_t (*esg_add_favorite)(mtv_sm_t* sm, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

    /**
      * Delete one service from my favorite.
      */
    mtv_result_t (*esg_del_favorite)(mtv_sm_t* sm, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

    /**
      * free memory which get from esg query engine
      *
      */
    mtv_result_t (*esg_free_result_buffer)(mtv_sm_t* sm, void* buf_p);

    /**
      * Get esg query engine state.
      *
      * @param service_id [in] the service to get recorder state
      * @param state [out] the esg query engine state
      */
    mtv_result_t (*esg_get_qe_state)(mtv_sm_t* sm, mtv_esg_query_state_enum* state);
#endif // #if defined(__MED_MTV_MOD__)

/* private data members */

    mtv_spi_client_t spi_client;
	mtv_spi_t* spi;

    mtv_service_callback_t service_callback;
    void* service_callback_ctx;

    media_config_audio_struct audio_config;
    media_config_video_struct video_config;

#if defined(__MTV_REC_SUPPORT__)
    media_mtv_config_record_struct record_config;
    volatile kal_bool recovering_aborted;   /**< whether to abort recovering */
#endif

    mtv_service_context_t* sc_tail; /**< the tail of servic context list */

    mtv_reception_quality_stat_t rq;        /**< current reception quality */

    kal_int32 seq_no;
    media_mtv_mode_enum mode;
    kal_uint16 app_id;
    kal_bool notify_service;

#if defined(__MED_MTV_MOD__)
    kal_bool drop_packets;                  /**< whether to drop incoming packets */
    mtv_unclosed_be_list_t unclosed_be_list; /**< to manage the list of BE waiting to be closed */

    mtv_esg_query_state_enum esg_qe_state;
    kal_int32 qe_query_type;

    mtv_init_state_t init_state;
    mtv_service_event_t hold_evt;
    kal_uint32 hold_param;
#endif

};

/**
  * Construct an instance of service manager in specified memory address.
  */
extern void construct_mtv_sm(mtv_sm_t* pthis);

#endif /* _MTV_SM_H */
