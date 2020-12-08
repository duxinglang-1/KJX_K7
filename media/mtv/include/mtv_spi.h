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
 *   mtv_spi.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#ifndef _MTV_SPI_H
#define _MTV_SPI_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#ifndef _MTV_CODEC_H
#include "mtv_codec.h"
#endif

#ifndef __APP_DATETIME_H__
#include "app_datetime.h"
#endif
#include "med_struct.h"
#include "kal_general_types.h"
#include "mtv_custom.h"
#include "mtv_error.h"
#include "med_global.h"

#define MTV_SPI_INVALID_SID 0xFFFFFFFF

/**
  * Flags to indicate different component attributes.
  */
typedef enum
{
    MTV_SPI_COMPONENT_PRIMARY = 0x01,           /**< It is a primary component */
    MTV_SPI_COMPONENT_ACCESS_CONTROL = 0x02     /**< Access control applies to this component */

} mtv_spi_component_flag_t;

typedef enum
{
    MTV_SPI_COMPONENT_INVALID,  /**< invalid component */
    MTV_SPI_COMPONENT_AUDIO,    /**< audio component */
    MTV_SPI_COMPONENT_VIDEO,    /**< video component */
    MTV_SPI_COMPONENT_DATA      /**< data component */

} mtv_spi_component_type_t;

/**
  * Information about a service component.
  */
typedef struct
{
    mtv_spi_component_type_t type;  /**< component type */
    kal_uint32 flags;               /**< @see mtv_spi_component_flag_t */
    kal_uint32 mode;                /**< current audio mode for ATV */
    mtv_dec_config_t dec_config;

} mtv_spi_component_info_t;

/**
  * Service type
  */
typedef enum
{
    MTV_SPI_SERVICE_UNKNOWN,
    MTV_SPI_SERVICE_DIGITAL_RADIO,
    MTV_SPI_SERVICE_DIGITAL_TV,
    MTV_SPI_SERVICE_ANALOG_TV,
    MTV_SPI_SERVICE_MOT_SLIDESHOW,
    MTV_SPI_SERVICE_MOT_BWS,
    MTV_SPI_SERVICE_TPEG,               /**< Transport Protocol Experts Group */
    MTV_SPI_SERVICE_EPG,
    MTV_SPI_SERVICE_FILE_DOWNLOAD,
    MTV_SPI_SERVICE_CA

} mtv_spi_service_type_t;

/**
  * Additional service parameter can be set by mtv_spi_t.set_service_param.
  */
typedef enum
{
    /* AnalogTV */
    MTV_SPI_SERVICE_PARAM_PAUSE,
    MTV_SPI_SERVICE_PARAM_RESUME,
    MTV_SPI_SERVICE_PARAM_DISABLE,
    MTV_SPI_SERVICE_PARAM_NAME,
    MTV_SPI_SERVICE_PARAM_AUDIO_MODE,
    MTV_SPI_SERVICE_PARAM_VIDEO_MODE,

    /* CMMB */
    MTV_SPI_SERVICE_PARAM_SUBSCRIBE,
    MTV_SPI_SERVICE_PARAM_UNSUBSCRIBE,
    MTV_SPI_SERVICE_PARAM_ACCOUNT_INQUIRY,
    MTV_SPI_SERVICE_PARAM_CA,
    MTV_SPI_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC,
    MTV_SPI_SERVICE_PARAM_DOWNLOAD_SG,
    MTV_SPI_SERVICE_PARAM_UPDATE_SG,
    MTV_SPI_SERVICE_PARAM_ESG_SOURCE,
    MTV_SPI_SERVICE_PARAM_SIM_INFO,
    MTV_SPI_SERVICE_PARAM_NET_INFO,
    MTV_SPI_SERVICE_PARAM_GBA,
    MTV_SPI_SERVICE_PARAM_SUBSCRIPTION_UPDATE,
    MTV_SPI_SERVICE_PARAM_CANCEL_SUBSCRIPTION_UPDATE,
    MTV_SPI_SERVICE_PARAM_MSK_RETRIEVE,
    MTV_SPI_SERVICE_PARAM_PURIFY_PROG_REMINDER,
    MTV_SPI_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED,
    MTV_SPI_SERVICE_PARAM_UPGRADE_QUERY,
    MTV_SPI_SERVICE_PARAM_AREA_SET_RETRIEVE,
    MTV_SPI_SERVICE_PARAM_INTERACTIVITY_RETRIEVE,
    MTV_SPI_SERVICE_PARAM_IMD_COUNT,
    MTV_SPI_SERVICE_PARAM_IMD_DESC,
    MTV_SPI_SERVICE_PARAM_IMD_DETAIL,
    //EMM
    MTV_SPI_SERVICE_PARAM_EMM_INFO,
    MTV_SPI_SERVICE_PARAM_CA_INFO,
    MTV_SPI_SERVICE_PARAM_NIT_TIME,
    MTV_SPI_SERVICE_PARAM_NIT_AREA
} mtv_spi_service_param_t;

/**
  * Flags to indicate different service attributes.
  */
typedef enum
{
    MTV_SPI_SERVICE_FREE = 0x01,         /**< the service is available for free */
    MTV_SPI_SERVICE_CLEAR_TO_AIR = 0x02, /**< the service is not scrambled */

    MTV_SPI_SERVICE_COMPENSATE_AV_OFFSET = 0x04, /**< the service requires compensation for audio/video time offset */
    MTV_SPI_SERVICE_UNMATCHED_APP_TYPE = 0x08,    /**< indicates the real app type is not the same as it was declared */

    /* review map_to_med_mtv_service_flags() if any new flag is added! */
    MTV_SPI_SERVICE_UNSUBSCRIBED = 0x10,
    MTV_SPI_SERVICE_SUBSCRIBED = 0x20
} mtv_spi_service_flag_t;

/**
  * SPI service info. A service can be audio-only, video, or data-only.
  * @see mtv_spi_client_t.on_service
  */
typedef struct
{
    kal_uint32 id;                  /**< An opaque ID to identify a service uniquely in a service provider */
    kal_wchar name[MTV_MAX_SERVICE_NAME + 1];   /**< The service name */
    kal_uint32 number;              /**< the service number for easy access */
    mtv_spi_service_type_t type;    /**< service type */
    kal_uint32 flags;               /**< @see mtv_spi_service_flag_t */
    kal_uint32 freq;               /**< freqence */

    kal_uint32 num_components;
    mtv_spi_component_info_t components[MAX_SPI_SERVICE_COMPONENTS];    /**< list of enabled components */

} mtv_spi_service_info_t;

/**
  * Values to indicate the reception quality.
  */
typedef enum
{
    MTV_SPI_RECEPTION_QUALITY_EXCELLENT,
    MTV_SPI_RECEPTION_QUALITY_GOOD,
    MTV_SPI_RECEPTION_QUALITY_FAIR,
    MTV_SPI_RECEPTION_QUALITY_POOR,
    MTV_SPI_RECEPTION_QUALITY_UNUSABLE

} mtv_spi_reception_quality_t;

/**
  * Service event code.
  * @see mtv_spi_client_t.on_event
  */
typedef enum
{
    /**
      * The decoding info is ready. The client can start to play this service.
      * @param mtv_spi_service_info_t*
      */
    MTV_SPI_SERVICE_ACQUIRED,
    MTV_SPI_SERVICE_UPDATE,

    /**
      * A new service is added. The client should add this service to its service list.
      * @param mtv_spi_service_info_t*
      */
    MTV_SPI_SERVICE_ADDED,

    /**
      * Information of a service is updated.
      * @param mtv_spi_service_info_t*
      */
    MTV_SPI_SERVICE_UPDATED,

    /**
      * Some started service has been aborted because of fatal error. It is not
      * not necessary to stop the service after receiving this event.
      * @param kal_uint32 service_id
      */
    MTV_SPI_SERVICE_ABORTED,

    /**
      * A service is removed. The client should remove this service from its service list.
      * @param kal_uint32 service_id
      */
    MTV_SPI_SERVICE_REMOVED,

    /**
      * To notify access to a service is granted.
      * @param kal_uint32 service_id
      */
    MTV_SPI_SERVICE_ACCESS_GRANTED,

    /**
      * To notify access to a service is denied.
      * @param kal_uint32 service_id
      */
    MTV_SPI_SERVICE_ACCESS_DENIED,

    /**
      * Search progress in percentage.
      * @param kal_uint32 progress in percentage
      */
    MTV_SPI_SEARCH_PROGRESS,

    /**
      * Live seaching is done.
      * @param kal_uint32 the result code
      */
    MTV_SPI_LIVE_SEARCH_DONE,

    /**
      * Pre Tune is started.
      * @param kal_uint32 the result code
      */
    MTV_SPI_PRE_TUNE_START,
    /**
      * Pre Tune is done.
      * @param kal_uint32 the result code
      */
    MTV_SPI_PRE_TUNE_DONE,
    /**
      * To notify reception quality.
      * @param mtv_spi_reception_quality_t
      */
    MTV_SPI_RECEPTION_QUALITY,

    /**
      * To notify some emergency message has arrived.
      */
    MTV_SPI_EMERGENCY_MSG_ARRIVED,

    /**
      * To notify new ESG data is available.
      */
    MTV_SPI_ESG_NEW_AVAILABLE,

    /**
      * To notify new ESG is downloaded.
      */
    MTV_SPI_ESG_DOWNLOADED,

    /**
      * To notify ESG update is completed.
      */
    MTV_SPI_ESG_UPDATED,

    /**
      * To notify SG update result
      */
    MTV_SPI_SG_UPDATE_RET,

    /**
      * To notify upgrade result
      */
    MTV_SPI_UPGRADE_RET,

    /**
      * To notify upgrade result
      */
    MTV_SPI_INTERACTIVITY_RETRIEVE_RET,

    /**
      * To notify new IMD is downloaded.
      */
    MTV_SPI_IMD_READY,

    /**
      * To notify area retrieve data
      */
    MTV_SPI_AREA_RETRIEVE_DATA,

    /**
      * To notify area retrieve result
      */
    MTV_SPI_AREA_RETRIEVE_RET,

    /**
      * To notify subscription update result
      */
    MTV_SPI_SUBSCRIPTION_UPDATE_RET,

    /**
      * To notify GBA result
      */
    MTV_SPI_GBA_RET,

    /**
      * To notify account inquiry result
      */
    MTV_SPI_ACCOUNT_INQUIRY_DATA,
    /**
      * To notify account inquiry result
      */
    MTV_SPI_ACCOUNT_INQUIRY_DONE,

    /**
      * To notify subscribe result
      */
    MTV_SPI_SUBSCRIBE_DONE,

    /**
      * To notify unsubscribe result
      */
    MTV_SPI_UNSUBSCRIBE_DONE,

    /**
      * To notify msk retrieve result
      */
    MTV_SPI_MSK_RETRIEVE_DONE,
    /**
      * Fatal error happened. For example, HW cannot function correctly.
      * The client should handle this event and shut down everything.
      * @param mtv_result_t
      */
    MTV_SPI_FATAL_ERROR,

    /**
      * The service provider has been closed.
      */
    MTV_SPI_CLOSED,

    /* emm */
    MTV_SPI_SET_EMM_DONE,
    MTV_SPI_GET_CA_DONE

} mtv_spi_event_t;

/**
  * Service data type.
  */
typedef enum
{
    MTV_SPI_DATA_DLS,                       /**< for DAB DLS */
    MTV_SPI_DATA_MPEG4_SCENE_DESCRIPTION,   /**< for T-DMB BIFS */
    MTV_SPI_DATA_PROGRAM_INFO,              /**< Program info. @see mtv_spi_program_info_t */
    MTV_SPI_DATA_TOD                        /**< Time Of Date */

} mtv_spi_service_data_type_t;

/**
  * TOD to synchronize with server's time.
  */
typedef struct
{
    kal_uint32 date;        /* 16-bit MJD */
    kal_uint32 time;        /* 24-bit UTC */

} mtv_spi_tod_t;

/**
  * Basic info about a TV program.
  */
typedef struct
{
    kal_uint32 date;        /* 16-bit MJD */
    kal_uint32 time;        /* 24-bit UTC */
    kal_uint32 duration;    /* in seconds */
    kal_wchar title[256];   /* program title */

} mtv_spi_program_info_rec_t;

/**
  * Generic program info.
  */
typedef struct
{
    kal_uint32 record_count;

    /** 0 is for current program and 1 for next program */
    mtv_spi_program_info_rec_t records[2];

} mtv_spi_program_info_t;

/**
  * Generic emergency message sent from a service provider.
  */
typedef struct
{
    kal_uint32 start_date;
    kal_uint32 start_time;
    kal_uint32 duration;
    kal_wchar text[8192];

} mtv_spi_emergency_msg_t;

/**
  * Service Provider status.
  */
typedef struct
{
    #define MTV_SPI_MAX_SIGNAL_STRENGTH 255
    kal_uint32 signal_strength; /**< valid range is 0 to MTV_SPI_MAX_SIGNAL_STRENGTH */

} mtv_spi_status_t;


typedef struct mtv_spi_client_t mtv_spi_client_t;

/**
  * The SPI client.
  */
struct mtv_spi_client_t
{
    /**
      * Called to notify some service is found.
      * @param service [in] service info. This pointer does not guarantee to be valid after the call-back returns.
      */
    void (*on_service)(mtv_spi_client_t* client, mtv_spi_service_info_t* info);

    /**
      * Called to notify an audio AU of some service has arrived.
      * @param au [in] AU data. The AU does not guarantee to be valid after the call-back returns.
      */
    void (*on_audio_au)(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au);

    /**
      * Called to notify a video AU of some service has arrived.
      * @param au [in] AU data. The AU does not guarantee to be valid after the call-back returns.
      */
    void (*on_video_au)(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au);

    /**
      * Called to notify a data AU (other than audio and video) of some service has arrived.
      * @param data_type [in] to indicate the type of data.
      * @param au [in] AU data. The AU does not guarantee to be valid after the call-back returns.
      */
    void (*on_data_au)(mtv_spi_client_t* client, kal_uint32 service_id, mtv_spi_service_data_type_t data_type, mtv_packet_t* au);

    /**
      * Called to notify some asynchronous abnormal conditions.
      * @param event [in] event code
      * @param param [in] the content depends on the event code
      * @see mtv_spi_event_t
      */
    void (*on_event)(mtv_spi_client_t* client, mtv_spi_event_t event, kal_uint32 param);

};

typedef struct mtv_spi_esg_t mtv_spi_esg_t;

/**
  * If a SP support ESG functionality, it should return this interface in get_esg_interface.
  */
struct mtv_spi_esg_t
{
    /**
      * Download ESG content. This is an asynchronous operation.
      */
    mtv_result_t (*download)(mtv_spi_esg_t* esgi);

    /**
      * Abort downloading ESG content.
      */
    mtv_result_t (*abort_downloading)(mtv_spi_esg_t* esgi);

    /**
      * Send query of esg data to query engine.
      * @param type [in] type of query.
      */
    mtv_result_t (*query)(mtv_spi_esg_t* esgi, kal_int32 type, media_mtv_esg_query_struct *query);

    /**
      * Get esg data depend on previous query.
      * @param type [in] type of query.
      */
    mtv_result_t (*get_result)(mtv_spi_esg_t* esgi, kal_int32 type, void **buf_p);

    /**
      * Finish previous query.
      */
    mtv_result_t (*query_finish)(mtv_spi_esg_t* esgi);

    /**
      * Add one service into my favorite.
      * @param type [in] service id.
      */
    mtv_result_t (*add_favorite)(mtv_spi_esg_t* esgi, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

    /**
      * Delete one service from my favorite.
      * @param type [in] service id.
      */
    mtv_result_t (*del_favorite)(mtv_spi_esg_t* esgi, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

    /**
      * Delete one service from my favorite.
      * @param type [in] service id.
      */
    mtv_result_t (*free_result_buffer)(mtv_spi_esg_t* esgi, kal_int32 query_type, void *buf_p);
};

typedef struct mtv_spi_ca_t mtv_spi_ca_t;

/**
  * If a SP support CA functionality, it should return this interface in get_ca_interface.
  */

struct mtv_spi_ca_t
{
    /**
      * Get CA info
      */
    mtv_result_t (*get_card_info)(mtv_spi_ca_t* ca, kal_char** card_number);
};

typedef struct mtv_spi_t mtv_spi_t;

/**
  * Mobile TV Service Provider Interface (SPI). The implementation behide this interface can be
  * any mobile TV standard, such as DVB-H, T-DMB, or 1-Seg DTV.
  */
struct mtv_spi_t
{
    /**
      * Open this service provider with specified client call-backs.
      * @param client [in] client call-backs
      */
    mtv_result_t (*open)(mtv_spi_t* spi, mtv_spi_client_t* client, void *param);
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    mtv_result_t (*restart_chip)(mtv_spi_t* spi, kal_uint32 sid);
#endif

#if defined(__MED_MTV_MOD__)
    /**
      * Get ESG interface. Note that this method will fail if the SP does not support ESG function.
      * @param esg [out] the returned esg interface.
      */
    mtv_result_t (*get_esg_interface)(mtv_spi_t* spi, mtv_spi_esg_t** esg);

    /**
      * Get CA interface. Note that this method will fail if the SP does not support CA function.
      * @param esg [out] the returned esg interface.
      */
    mtv_result_t (*get_ca_interface)(mtv_spi_t* spi, mtv_spi_ca_t** ca);
#endif  // #if defined(__MED_MTV_MOD__)

    /**
      * Start service searching. The client will be notified the found service by on_service callback.
      * @see MTV_SPI_SEARCH_PROGRESS
      */
    mtv_result_t (*search_services)(mtv_spi_t* spi, mtv_freq_band_t band, void *param);

    /**
      * Abort service searching.
      */
    mtv_result_t (*abort_searching)(mtv_spi_t* spi);

    /**
      * Save current service list into specified directory.
      * @param dir [in] directory to save service data.
      */
    mtv_result_t (*save_service_list)(mtv_spi_t* spi, const kal_wchar* dir);

    /**
      * Load service list from specified directory.
      * @param dir [in] directory to load service data.
      */
    mtv_result_t (*load_service_list)(mtv_spi_t* spi, const kal_wchar* dir, mtv_freq_band_t band, void *param);

    /**
      * Start the specified service once you know what services are available. You can start more
      * than one service at the same time if the underlying platform allows. Note that you cannot
      * start a service while service searching is in progress.
      *
      * You should wait until MTV_SPI_SERVICE_READY before presenting a service.
      *
      * @return MTV_S_OK if the the service is started successfully.
      * @return MTV_SPI_E_NO_MORE_SERVICE
      * @return MTV_SPI_E_ALREADY_STARTED
      * @return MTV_E_RESOURCE_CONFLICT
      * @see MTV_SPI_SERVICE_READY
      */
    mtv_result_t (*start_service)(mtv_spi_t* spi, kal_uint32 service_id);

    /**
      * Stop the specified service.
      *
      * @return MTV_S_OK if the the service is stopped successfully.
      * @return MTV_SPI_E_INVALID_SERVICE
      */
    mtv_result_t (*stop_service)(mtv_spi_t* spi, kal_uint32 service_id);

    /**
      * Get provider status.
      */
    mtv_result_t (*get_status)(mtv_spi_t* spi, mtv_spi_status_t* status);

    /**
      * Set param to provider. @param: see mtv_service_param_t
      */
    mtv_result_t (*set_param)(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value);


    /**
      * Get param from provider. @param: see mtv_service_param_t
      */
    mtv_result_t (*get_param)(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value);

    /**
      * Close this service provider. If there are any active services, they will be aborted.
      */
    mtv_result_t (*close)(mtv_spi_t* spi);

    /**
      * Destroy the instance.
      */
    void (*destroy)(mtv_spi_t* spi);

};

extern mtv_spi_t* construct_tdmb_sp(void);
extern mtv_spi_t* construct_cmmb_sp(void);
extern mtv_spi_t* construct_dvbh_sp(void);
extern mtv_spi_t* construct_atv_sp(void);
extern mtv_spi_t* construct_camera_sp(void);

#endif /* _MTV_SPI_H */
