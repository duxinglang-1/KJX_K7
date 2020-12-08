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
 *   mtv_main.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_timer.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"

#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_datetime.h"

#include "med_main.h"		/* error codes */
#include "med_struct.h"		/* message struct */
#include "mtv_main.h"
#include "med_trc.h"
#include "med_utility.h"
#include "mtv_debug_event.h"
#include "med_api.h"

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#include "mtv_sm.h"
#include "mtv_async_io.h"

#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "med_smalloc.h"
#include "mtv_error.h"
#include "mtv_spi.h"
#include "stack_ltlcom.h"
#include "mtv_custom.h"
#include "mtv_control.h"
#include "mtv_recorder.h"
#include "kal_trace.h"
#include "mtv_codec.h"
#include "task_main_func.h"
#include "kal_active_module.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "mtv_player.h"

#define MSG_STRUCT(type, name, ilm) \
    type* name  = (type*) ilm->local_para_ptr

#if defined(WIN32)
    #define _MTV_FORCE_NOINLINE_
#else
    #define _MTV_FORCE_NOINLINE_ __attribute__((noinline))
#endif

#if defined(__TDMB_SUPPORT__)
#include "tdmb_sp.h"
#include "tdmb_demod.h"
#include "cyberlink_tdmb_demux.h"
#endif /* __TDMB_SUPPORT__ */

#if defined(__CMMB_SUPPORT__)
#include "cmmb_hostlib_hal.h"
#include "cmmb_rx.h"
#include "cmmb_esg.h"
#include "cmmb_esg_parser.h"
#include "cmmb_ca.h"
#include "cmmb_sp.h"
#include "mbbms_main.h"
#endif /* __CMMB_SUPPORT__ */

#if defined(__ATV_SUPPORT__)
#include "atv_sp.h"
#include "camera_sp.h"

#ifndef _ATV_PLAY_CTRL_H
#include "atv_play_ctrl.h"
#endif

#endif /* __ATV_SUPPORT__ */

#include "mtv_esg_define.h"
#include "mtv_esg_query_datatype.h"
#include "mpl_common.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

//#define ATV_SIMULATION

typedef enum
{
    MTV_STATE_CLOSED,
    MTV_STATE_OPENED,
    MTV_STATE_CLOSING,

    MTV_STATE_ESG_ONLY,
    MTV_STATE_BUFFER_ENGINE_ONLY

} mtv_state_t;

typedef enum
{
    MTV_EVT_OPEN_REQ                                = 1 <<  0,
    MTV_EVT_CONFIG_REQ                              = 1 <<  1,
    MTV_EVT_FIND_UNSAVED_RECORDING_REQ              = 1 <<  2,
    MTV_EVT_RECOVER_RECORDING_REQ                   = 1 <<  3,
    MTV_EVT_ABORT_RECOVERING_REQ                    = 1 <<  4,
    MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ           = 1 <<  5,
    MTV_EVT_SEARCH_SERVICES_REQ                     = 1 <<  6,
    MTV_EVT_ABORT_SEARCHING_REQ                     = 1 <<  7,
    MTV_EVT_SERVICE_REQ                             = 1 <<  8,
    MTV_EVT_PLAYER_REQ                              = 1 <<  9,
    MTV_EVT_RECORDER_REQ                            = 1 << 10,
    MTV_EVT_TIMESHIFT_REQ                           = 1 << 11,
    MTV_EVT_SET_PARAM_REQ                           = 1 << 22,
    MTV_EVT_GET_PARAM_REQ                           = 1 << 23,
    MTV_EVT_CLOSE_REQ                               = 1 << 27,
    MTV_EVT_ESG_QUERY_REQ                           = 1 << 28,
    MTV_EVT_CAS_INFO_REQ                            = 1 << 29,
    MTV_EVT_CHIP_RESTART_REQ						= 1 << 30
} mtv_wait_event_enum;

/* Provide timer service for MTV implementation */
typedef struct
{
    stack_timer_struct timer;
    mtv_timer_callback_t callback;
    void* param;
} mtv_timer_service_t;

/**
  * Mobile TV engine context.
  */
typedef struct
{
    kal_eventgrpid req_events;  /* event group for blocking request */
    mtv_state_t state;          /* context state */
    module_type src_mod;        /* the source module for sending indication message */
    kal_uint32 pending_msgs;    /* to record how many MTV messages are pending for processing */

    kal_uint16 app_id;
    mtv_sm_t sm;                /* service manager */

    kal_uint32 session_id_of_search_services;
    kal_int32* req_async_result;   /* the result of async request */

    media_mtv_service_found_ind_struct* pending_service_found_ind;
    media_mtv_city_found_ind_struct *pending_city_found_ind;
    /* memory pool */
    kal_uint8* mtv_mem;
    KAL_ADM_ID mtv_adm;
    kal_mutexid mtv_adm_lock;

    #if defined(__MED_MTV_MOD__)
        mtv_timer_service_t transport_timer;
        mtv_timer_service_t timeshift_timer;

        /* MBBMS ESG QUERY */
        kal_uint8* mtv_ext_db_mem;
        mtv_esg_db_t* mtv_ext_db;

        void* esg_results;
        esg_query_type_enum query_type;
        media_mtv_program_info_struct* program_info;
    #endif

} mtv_context_t;

static mtv_context_t g_mtv_context;

/*
 * there are some difficulties to allocate the context dynamically because
 * some resource is required to be allocated during system initialization.
 * therefore, a global context is used.
 */
static void mtv_init_global_context(void)
{
	  g_mtv_context.state = MTV_STATE_CLOSED;

    /*
     * create a global transport lock so that we can run mobile TV in two threads, one
     * for controlling the engine and the other for transporting media data.
     */
    g_mtv_context.mtv_adm_lock = kal_create_mutex("MTVADML");
}

static mtv_result_t mtv_init_shared_mem_pool(kal_uint32 pool_size)
{
    ASSERT(g_mtv_context.mtv_mem == NULL);
    g_mtv_context.mtv_mem = med_alloc_asm_mem(g_mtv_context.app_id, pool_size);
    if (g_mtv_context.mtv_mem == NULL)
    {
        return MTV_E_OUT_OF_MEMORY;
    }
    g_mtv_context.mtv_adm = kal_adm_create(g_mtv_context.mtv_mem, pool_size, NULL, KAL_FALSE);
    ASSERT(g_mtv_context.mtv_adm != NULL);

    return MTV_S_OK;
}

static void mtv_uninit_shared_mem_pool(void)
{
    if (g_mtv_context.mtv_adm != NULL)
    {
        kal_adm_delete(g_mtv_context.mtv_adm);
        g_mtv_context.mtv_adm = NULL;
    }
    med_free_asm_mem(g_mtv_context.app_id, (void**)&g_mtv_context.mtv_mem);
}

#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)

#if defined(__MED_MTV_MOD__)
    /**
      * Can be enabled in EM to do demodulator simulation.
      */
#ifdef __MTK_TARGET__
    kal_uint32 g_mtv_demod_sim = 0;
#else
    kal_uint32 g_mtv_demod_sim = 1;  /* MFS */
#endif

    /**
      * Can be enabled in EM to dump DAB/DMB service stream into file.
      */
    kal_bool g_mtv_dump_service = KAL_FALSE;

    /**
      * Can be enabled in EM to dump ESG XML file into Memory Card
      */
    kal_bool g_mtv_dump_esg_xml_file = KAL_FALSE;

    kal_bool g_mtv_mts_command = KAL_FALSE;

    /**
      * Can be enabled in EM to send demod status notification text.
      */
    kal_bool g_mtv_show_demod_status = KAL_FALSE;

    /**
      * EM: set cat, emm service id, ecm data type, emm data type
      */
    kal_bool g_mtv_em_set_cat = KAL_FALSE;
    kal_uint32 g_mtv_em_emm_service_id = 602;
    kal_uint32 g_mtv_em_ecm_data_type = 130;
    kal_uint32 g_mtv_em_emm_data_type = 129;
#endif // #if defined(__MED_MTV_MOD__)

#if defined(__MED_ATV_MOD__)
    /**
      * Factory Mode: set quick scan for ATV.
      */
    kal_bool g_mtv_atv_default_chlist = KAL_FALSE;
#endif // #if defined(__MED_MTV_MOD__)

#if defined(__ATV_CAMERA_SIM_SUPPORT__)
/**
  * Can be enabled in sm.open() when mode = MEDIA_MTV_OPEN_MODE_CAMERA.
  */
    #ifdef ATV_SIMULATION
        kal_bool g_mtv_atv_sim = KAL_TRUE;
    #else
        kal_bool g_mtv_atv_sim = KAL_FALSE;
    #endif
#endif // #if defined(__ATV_CAMERA_SIM_SUPPORT__)

#if defined(__TDMB_SUPPORT__)
    kal_uint32 g_mtv_fair_reception_threshold = 3;  /* BER < 3.0 * 10^-6 */    //kal_uint32 g_mtv_fair_reception_threshold = 60000;  /* BER < 6.0 * 10^-2 */
#endif

/* forward declaration */

static void mtv_service_callback(void* context, mtv_service_callback_param_t* param);
#if defined(__MED_MTV_MOD__)
    static void mtv_esg_query_free_buffer(mtv_context_t *ctx, media_mtv_esg_source_enum source, void** buf_head);
#endif

#ifdef __MM_DCM_SUPPORT__
void media_mtv_dcm_load(void)
{
    DCM_Load(DYNAMIC_CODE_COMPRESS_MEDMTV, NULL, NULL);
}

void media_mtv_dcm_unload(void)
{
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MEDMTV);
}

kal_bool media_mtv_dcm_is_loaded(void)
{
    return DCM_Isloaded(DYNAMIC_CODE_COMPRESS_MEDMTV);
}
#endif


/* private functions */
static void mtv_init_service_manager(void)
{
    g_mtv_context.req_events = kal_create_event_group("mtv_events");
    g_mtv_context.pending_msgs = 0;

#if defined(__MED_MTV_MOD__)
    /* initialize the timer for demodulator emulation */
    stack_init_timer(&g_mtv_context.transport_timer.timer, "mtv_transport_timer", MTV_TRANSPORT_MOD);

    /* initialize the timer for time-shift mode */
    stack_init_timer(&g_mtv_context.timeshift_timer.timer, "mtv_timeshift_timer", MTV_TRANSPORT_MOD);
#endif // #if defined(__MED_MTV_MOD__)

    /* construct the service manager in global context */
    construct_mtv_sm(&g_mtv_context.sm);

#if defined(__MED_MTV_MOD__)
    mtv_init_aio();
#endif
}

static kal_int32 mtv_error_to_med_error(kal_int32 mtv_error)
{
    switch (mtv_error)
    {
    case MTV_S_OK_UPGRADE_NONE:
        return MED_RES_UPGRADE_NONE;
    case MTV_S_OK_UPGRADE_NEED:
        return MED_RES_UPGRADE_NEED;
    case MTV_S_OK_UPGRADE_MANDATORY:
        return MED_RES_UPGRADE_MANDATORY;
    case MTV_S_COMPLETE:
        return MED_RES_FILE_EXIST;
    }

    if (mtv_error >= 0) {
        return MED_RES_OK;
    }

    switch (mtv_error)
    {
    case MTV_IO_E_DISK_FULL:
        return MED_RES_DISC_FULL;

    case MTV_IO_E_DEVICE_BUSY:
        return MED_RES_BUSY;

    case MTV_IO_E_MEDIA_CHANGED:
    case MTV_IO_E_INVALID_FILE_HANDLE:
        return MED_RES_NO_DISC;

    case MTV_IO_E_WRITE_TOO_SLOW:
    case MTV_IO_E_READ_ERROR:
    case MTV_IO_E_WRITE_ERROR:
        return MED_RES_DISK_IO_ERROR;

    case MTV_DEC_E_VIDEO:
        return MED_RES_VIDEO_ERROR;

    case MTV_DEC_E_AUDIO:
        return MED_RES_AUDIO_ERROR;

    case MTV_E_BUSY:
        return MED_RES_BUSY;

    case MTV_E_UNSUPPORTED_FORMAT:
        return MED_RES_INVALID_FORMAT;

    case MTV_E_OVER_LIMIT:
        return MED_RES_OVER_LIMIT;
    }

    return MED_RES_FAIL;
}

static media_mtv_service_type_enum map_to_med_mtv_service_type(mtv_spi_service_type_t st)
{
    switch (st)
    {
    case MTV_SPI_SERVICE_DIGITAL_RADIO:
        return MEDIA_MTV_SERVICE_DIGITAL_RADIO;

    case MTV_SPI_SERVICE_DIGITAL_TV:
        return MEDIA_MTV_SERVICE_DIGITAL_TV;

    case MTV_SPI_SERVICE_ANALOG_TV:
        return MEDIA_MTV_SERVICE_ANALOG_TV;

    case MTV_SPI_SERVICE_MOT_SLIDESHOW:
        return MEDIA_MTV_SERVICE_MOT_SLIDESHOW;

    case MTV_SPI_SERVICE_MOT_BWS:
        return MEDIA_MTV_SERVICE_BWS;

    case MTV_SPI_SERVICE_TPEG:
        return MEDIA_MTV_SERVICE_TPEG;

    case MTV_SPI_SERVICE_FILE_DOWNLOAD:
        return MEDIA_MTV_SERVICE_FILE_DOWNLOAD;

    case MTV_SPI_SERVICE_CA:
        return MEDIA_MTV_SERVICE_CA;

    default:
        return MEDIA_MTV_SERVICE_UNKNOWN;
    }
}

static kal_uint32 map_to_med_mtv_service_flags(kal_uint32 spi_service_flags)
{
    kal_uint32 service_flags = 0;

    if ((spi_service_flags & MTV_SPI_SERVICE_FREE) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_FREE;
    }
    if ((spi_service_flags & MTV_SPI_SERVICE_CLEAR_TO_AIR) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_CLEAR_TO_AIR;
    }
    if ((spi_service_flags & MTV_SPI_SERVICE_UNSUBSCRIBED) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_UNSUBSCRIBED;
    }
    if ((spi_service_flags & MTV_SPI_SERVICE_SUBSCRIBED) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_SUBSCRIBED;
    }

    return service_flags;
}

static void mtv_fill_service_info(media_mtv_service_info_struct* info, mtv_service_context_t* sc)
{
    ASSERT(sc != NULL);
    ASSERT(info != NULL);

    info->service_id = sc->info.id;
    info->service_number = sc->info.number;

    /*
     * The service context will exist until service manager is closed or
     * channels are re-scanned. therefore, it should be okay to send string
     * pointer direcly without the overhead to copy it.
     */
    info->service_name = sc->info.name;
    info->service_flags = map_to_med_mtv_service_flags(sc->info.flags);
    info->service_type = map_to_med_mtv_service_type(sc->info.type);
    info->service_freq = sc->info.freq;

#ifdef __MED_ATV_MOD__
    ASSERT(sc->info.components[0].type == MTV_SPI_COMPONENT_AUDIO);

    info->audio_mode = sc->info.components[0].mode;
    info->supported_audio_mode = sc->info.components[0].flags;
#endif
}

static void mtv_send_incoming_ilm(module_type src_mod_id, module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    ilm_struct* ilm = NULL;

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->dest_mod_id = dest_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    g_mtv_context.pending_msgs++;
    msg_send_ext_queue(ilm);
}

static void mtv_flush_service_found_ind(module_type src_mod_id, void* context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;

    if (ctx->pending_service_found_ind != NULL)
    {
        ASSERT(ctx->pending_service_found_ind->service_count > 0);
        mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND, ctx->pending_service_found_ind);

        ctx->pending_service_found_ind = NULL;
    }
}

static void mtv_send_service_found_ind(module_type src_mod_id, void* context, mtv_service_context_t* sc)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    kal_uint32 i;

    if (ctx->pending_service_found_ind == NULL)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_service_found_ind_struct, ind);

        ASSERT(ind != NULL);

        ind->context = (kal_uint32) context;
        ind->seq_no = ctx->session_id_of_search_services;
        ind->service_count = 0;

        ctx->pending_service_found_ind = ind;
    }

    i = ctx->pending_service_found_ind->service_count++;

    ASSERT(i < ARRAY_SIZE(ctx->pending_service_found_ind->service_info));
    mtv_fill_service_info(&ctx->pending_service_found_ind->service_info[i], sc);

    if (ctx->pending_service_found_ind->service_count == ARRAY_SIZE(ctx->pending_service_found_ind->service_info))
    {
        mtv_flush_service_found_ind(src_mod_id, context);
    }
}

static void mtv_send_search_progress_ind(module_type src_mod_id, void* context, kal_uint32 percentage, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    CONSTRUCT_LOCAL_PARAM(media_mtv_search_progress_ind_struct, ind);

    if (percentage == 100) {
        mtv_flush_service_found_ind(src_mod_id, context);
    }

    ind->context = (kal_uint32) ctx;
    ind->seq_no = seq_no;
    ind->percentage = percentage;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND, ind);
}

#if defined(__MTV_REC_SUPPORT__)
static void mtv_send_complete_recovering_ind(module_type src_mod_id, void* context, kal_uint32 error, kal_uint32 seq_no)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_complete_recovering_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->seq_no = seq_no;
    ind->error = error;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND, ind);
}
#endif // #if defined(__MTV_REC_SUPPORT__)

static void mtv_send_system_event_ind(module_type src_mod_id, void* context, kal_uint32 event, kal_uint32 parameter)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_system_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SYSTEM_EVENT_IND, ind);
}

static void mtv_send_service_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter, kal_uint32 seq_no)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_service_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->seq_no = seq_no;
    ind->service_id = service_id;
    ind->event = event;
#if defined(__CMMB_SUPPORT__)
    if (event == MEDIA_MTV_SERVICE_SUBSCRIBE_DONE || event == MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE)
    {
        cmmb_subscribe_info_t *p_subs_info = (cmmb_subscribe_info_t*)parameter;
        ind->parameter = p_subs_info->result;
        if (p_subs_info->desc != NULL && p_subs_info != NULL)
        {
            wcsncpy(ind->append_data, p_subs_info->desc, MEDIA_MTV_MAX_APPEND_LEN - 1);
        }
    }
    else if (event == MEDIA_MTV_SERVICE_GET_CA_DONE)
    {
        cmmb_demod_ca_info_struct *p_ca_info = (cmmb_demod_ca_info_struct*)parameter;
        ind->parameter = 0;
        ASSERT(sizeof(cmmb_demod_ca_info_struct) <= MEDIA_MTV_MAX_APPEND_LEN);
        memcpy(ind->append_data, p_ca_info, sizeof(cmmb_demod_ca_info_struct));
        kal_wap_trace(MOD_MED, TRACE_INFO, "[lry]MTV get ca info: randvalue=%x|%x, demodType=%d, caType=%d, result=%d", 
                      p_ca_info->randvalue[0], p_ca_info->randvalue[1], p_ca_info->demodType, p_ca_info->caType, p_ca_info->result);
        kal_wap_trace(MOD_MED, TRACE_INFO, "[lry]MTV cardSN=%x|%x|%x|%x|%x|%x|%x|%x", 
                      p_ca_info->cardSN[0], p_ca_info->cardSN[1], p_ca_info->cardSN[2], p_ca_info->cardSN[3],
                      p_ca_info->cardSN[4], p_ca_info->cardSN[5], p_ca_info->cardSN[6], p_ca_info->cardSN[7]);
    }
    else
#endif /* defined(__CMMB_SUPPORT__) */
    {
        ind->parameter = parameter;
    }
    mtv_zapping_trace(MOD_MED, "[MTV] mtv_send_service_event_ind. parameter[%d]", ind->parameter);

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND, ind);
}

static void mtv_send_player_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter, kal_uint32 seq_no)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_player_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->seq_no = seq_no;
    ind->service_id = service_id;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND, ind);
}

#if defined(__MTV_REC_SUPPORT__)
static void mtv_send_recorder_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter, kal_uint32 seq_no)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->seq_no = seq_no;
    ind->service_id = service_id;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND, ind);
}
#endif // #if defined(__MTV_REC_SUPPORT__)

#if defined(__MED_MTV_MOD__) && defined(__CMMB_CAS_MBBMS_SUPPORT__)
static void mtv_send_account_inquiry_ind(module_type src_mod_id, void* context, kal_uint32 parameter)
{
    mbbms_account_inquiry_done_evt_struct *evt;
    kal_int32 sent_count, i, total;
    media_mtv_fragment_struct *frag_p;
    mbbms_purchaseitem_fragment_struct *item_p;

    evt = (mbbms_account_inquiry_done_evt_struct *)parameter;
    total = evt->purchaseitem_count;

    sent_count = 0;
    while (sent_count < total)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_account_inquiry_ind_struct, ind);

        ind->context = (kal_uint32) context;
        ind->purchase_count = 0;
        for (i = 0; i < 5 && sent_count < total; i ++)
        {
            frag_p = &ind->purchase_info[i];
            item_p = &evt->fragment_list[sent_count];

            kal_mem_set(frag_p, 0, sizeof(media_mtv_fragment_struct));
            frag_p->type = item_p->subscriptionType;
            frag_p->price = item_p->price;
            frag_p->period = item_p->period;

            kal_mem_cpy(frag_p->fragment_id, item_p->fragment_id, 20);
            kal_mem_cpy(frag_p->purchaseitem_id, item_p->purchaseitem_id, 30);
            kal_wstrncpy(
                frag_p->purchaseitem_name, item_p->purchaseitem_name, 32);
            kal_wstrncpy(
                frag_p->purchaseitem_desc, item_p->purchaseitem_desc, 32);
            ind->purchase_count ++;
            sent_count ++;
        }
        mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_ACCOUNT_INQUIRY_IND, ind);
    }
}

static void mtv_flush_city_found_ind(module_type src_mod_id, void* context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;

    if (ctx->pending_city_found_ind != NULL)
    {
        ASSERT(ctx->pending_city_found_ind->city_count > 0);
        mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_CITY_FOUND_IND, ctx->pending_city_found_ind);

        ctx->pending_city_found_ind = NULL;
    }
}

static void mtv_send_recommend_city_found_ind(module_type src_mod_id, void* context, kal_wchar *city_name)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    kal_uint32 i;

    if (ctx->pending_city_found_ind == NULL)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_city_found_ind_struct, ind);

        ASSERT(ind != NULL);

        ind->context = (kal_uint32) context;
        ind->city_count = 0;

        ctx->pending_city_found_ind = ind;
    }

    i = ctx->pending_city_found_ind->city_count++;

    ASSERT(i < ARRAY_SIZE(ctx->pending_city_found_ind->city_info));
    kal_wstrncpy(
        ctx->pending_city_found_ind->city_info[i].city_name,
        city_name, 32);

    if (ctx->pending_city_found_ind->city_count == ARRAY_SIZE(ctx->pending_city_found_ind->city_info))
    {
        mtv_flush_city_found_ind(src_mod_id, context);
    }
}
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */


/* public API */

#define MTV_WAIT_EVENT(evt) \
    do { \
        kal_uint32 retrieved_events; \
        kal_retrieve_eg_events(ctx->req_events, (evt), \
            KAL_OR_CONSUME, &retrieved_events, (kal_uint32) KAL_SUSPEND); \
    } while (0)

#define REQ_CONSTRUCT_LOCAL_PARAM(st, name) \
    kal_int32 req_result; \
    CONSTRUCT_LOCAL_PARAM(st, name); \
    name->result = &req_result;

kal_int32 media_mtv_open(module_type src_mod_id, kal_uint32* context, media_mtv_mode_enum mode, kal_uint16 app_id, void *init_param)
{
	mtv_context_t* ctx = &g_mtv_context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_open_req_struct, req);

    req->context = context;
    req->mode = mode;
    req->init_param = init_param;
    req->app_id = app_id;
    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_OPEN_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_OPEN_REQ);

    return req_result;
}

kal_int32 media_mtv_close(module_type src_mod_id, kal_uint32 context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_close_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_CLOSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CLOSE_REQ);

    return req_result;
}

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MEDMTV_ROCODE", rodata = "DYNAMIC_CODE_MEDMTV_RODATA"
#endif

kal_int32 media_mtv_config(module_type src_mod_id, kal_uint32 context, media_config_video_struct* video, media_config_audio_struct* audio, media_mtv_config_record_struct* record)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_config_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;

    req->fields = 0;
    if (video != NULL)
    {
        req->fields |= MEDIA_MTV_CONFIG_VIDEO;
        req->video = *video;
    }
    if (audio != NULL)
    {
        req->fields |= MEDIA_MTV_CONFIG_AUDIO;
        req->audio = *audio;
    }
    if (record != NULL)
    {
        req->fields |= MEDIA_MTV_CONFIG_RECORD;
        req->record = *record;
    }

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_CONFIG_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CONFIG_REQ);

    return req_result;
}

kal_int32 media_mtv_search_services(module_type src_mod_id, kal_uint32 context, kal_uint32 source, kal_uint32 band, void *param, kal_uint32 seq_no)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_search_services_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->source = source;
    req->band = band;
    req->param = param;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SEARCH_SERVICES_REQ);

    return req_result;
}

kal_int32 media_mtv_abort_searching(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_search_services_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ABORT_SEARCHING_REQ);

    return req_result;
}

kal_int32 media_mtv_service_get_info(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_service_info_struct* info)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_service_get_info_req_struct, req);

	req->context = context;
    req->service_id = service_id;
    req->info = info;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SERVICE_GET_INFO_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SERVICE_REQ);

    return req_result;
}

kal_int32 media_mtv_start_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 activities, kal_uint32 seq_no)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_start_service_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->activities = activities;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_START_SERVICE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SERVICE_REQ);

    return req_result;
}

#if defined(__MTV_TS_SUPPORT__)
kal_int32 media_mtv_start_timeshift(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_start_timeshift_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_START_TIMESHIFT_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_TIMESHIFT_REQ);

    return req_result;
}
#endif

kal_int32 media_mtv_player_play(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_play_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

kal_int32 media_mtv_player_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_stop_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

#if defined(__MED_MTV_MOD__)
kal_int32 media_mtv_player_pause_visual_update(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_pause_visual_update_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_PAUSE_VISUAL_UPDATE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

kal_int32 media_mtv_player_resume_visual_update(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_resume_visual_update_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_RESUME_VISUAL_UPDATE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}
#endif  // #if defined(__MED_MTV_MOD__)

#if defined(__MTV_TS_SUPPORT__)
kal_int32 media_mtv_player_pause(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_pause_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

kal_int32 media_mtv_player_seek(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 delay)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_seek_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->delay = delay;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

kal_int32 media_mtv_player_set_rate(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_int32 rate)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_set_rate_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->rate = rate;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

#endif // #if defined(__MTV_TS_SUPPORT__)

kal_int32 media_mtv_player_snapshot(
            module_type src_mod_id,
            kal_uint32 context,
            kal_uint32 service_id,
            kal_wchar* file_path,
            media_mtv_buf_content_struct *buf_content)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_snapshot_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->file_path = file_path;
    req->buf = buf_content;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

kal_int32 media_mtv_player_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_player_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_get_status_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_REQ);

    return req_result;
}

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
kal_int32 media_mtv_player_restart_chip(module_type src_mod_id, kal_uint32 context,kal_uint32 service_id, kal_uint32 seq_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_restart_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->seq_no = seq_id;
    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RESTART_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CHIP_RESTART_REQ);  

    return req_result;
}
#endif

#if defined(__MTV_REC_SUPPORT__)
kal_int32 media_mtv_find_unsaved_recording(module_type src_mod_id, kal_uint32 context, kal_bool* found)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_find_unsaved_recording_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->found = found;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_FIND_UNSAVED_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_recover_recording(module_type src_mod_id, kal_uint32 context, kal_uint32 seq_no)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recover_recording_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_BACKGROUND_MOD, MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECOVER_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_abort_recovering(module_type src_mod_id, kal_uint32 context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_abort_recovering_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ABORT_RECOVERING_REQ);

    return req_result;
}

kal_int32 media_mtv_discard_unsaved_recording(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_discard_unsaved_recording_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_BACKGROUND_MOD, MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_start(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, const kal_wchar *service_name, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_start_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->service_name = service_name;
    req->seq_no = seq_no;

    /* we use "const kal_wchar* service_name" to pass the service name to recorder,
       please note this if change to non-blocking api */

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_START_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_stop_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_pause(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_pause_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_PAUSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_resume(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_resume_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_RESUME_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_save(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_wchar *file_path, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_save_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->seq_no = seq_no;
    req->file_path = file_path;

    mtv_send_incoming_ilm(src_mod_id, MTV_BACKGROUND_MOD, MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return MED_RES_OK;
}

kal_int32 media_mtv_recorder_abort_saving(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_abort_saving_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_discard_recording(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_discard_recording_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->seq_no = seq_no;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_recorder_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_get_status_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_REQ);

    return req_result;
}
#endif // #if defined(__MTV_REC_SUPPORT__)

kal_int32 media_mtv_service_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_service_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_service_get_status_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SERVICE_REQ);

    return req_result;
}

kal_int32 media_mtv_stop_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    kal_int32 req_result = MTV_E_FAIL;
    kal_int32 retries;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    /*
     * Retries stopping the services when it is busy:
     *   - the tuner has not finished its tuning to specified frequency.
     *   - the aborting of recorder saving is still in progress (typically takes 4 retries)
     */
    for (retries = 0; retries < 8; retries++)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_stop_service_req_struct, req);

        req->result = &req_result;
        req->context = context;
        req->service_id = service_id;

        mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ, req);
        MTV_WAIT_EVENT(MTV_EVT_SERVICE_REQ);
        if (req_result == MED_RES_BUSY)
        {
            kal_sleep_task(KAL_TICKS_1_SEC);
            continue;
        }

        break;
    }

    return req_result;
}


kal_int32 media_mtv_get_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32* value)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_get_param_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->param = param;
    req->value = value;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_GET_PARAM_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_GET_PARAM_REQ);

    return req_result;
}

#if defined(__MED_MTV_MOD__)
kal_int32 media_mtv_media_mtv_esg_download(module_type src_mod_id, kal_uint32 context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_media_mtv_esg_download_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_DOWNLOAD_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_media_mtv_esg_abort_downloading(module_type src_mod_id, kal_uint32 context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_media_mtv_esg_abort_downloading_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_ABORT_DOWNLOADING_REQ, req);

    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_open(module_type src_mod_id, kal_uint32* context, media_mtv_esg_source_enum source, kal_uint16 app_id)
{
    mtv_context_t* ctx = &g_mtv_context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_open_req_struct, req);

    req->context = context;
    req->source = source;
    req->app_id = app_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_OPEN_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_close(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_close_req_struct, req);

    req->context = context;
    req->source = source;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_CLOSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_query(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source, kal_int32 type, media_mtv_esg_query_struct *query)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_query_req_struct, req);

    req->context = context;
    req->source = source;
    req->type = type;
    req->query = query;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_QUERY_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_get_results(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source, kal_int32 type, void **buf_p)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_get_results_req_struct, req);

    req->context = context;
    req->source = source;
    req->type = (kal_int32)type;
    req->buf_p = buf_p;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_GET_RESULTS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_query_finish(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_query_finish_req_struct, req);

    req->context = context;
    req->source = source;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_QUERY_FINISH_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_add_favorite(
            module_type src_mod_id, kal_uint32 context, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_add_favorite_req_struct, req);

    ASSERT(ctx->state != MTV_STATE_CLOSED);

    req->context = context;
    req->type = type;
    req->id = id;
    req->rid = rid;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_ADD_FAVORITE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_esg_del_favorite(
            module_type src_mod_id, kal_uint32 context, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_esg_del_favorite_req_struct, req);

    ASSERT(ctx->state != MTV_STATE_CLOSED);

    req->context = context;
    req->type = type;
    req->id = id;
    req->rid = rid;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ESG_DEL_FAVORITE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ESG_QUERY_REQ);

    return req_result;
}

kal_int32 media_mtv_get_cas_card_info(module_type src_mod_id, kal_uint32 context, media_mtv_cas_card_info_struct* card_info)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_cas_get_card_info_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->card_info = card_info;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_CAS_GET_CARD_INFO_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CAS_INFO_REQ);

    return req_result;
}
#endif // #if defined(__MED_MTV_MOD__)

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif


/* message handlers */
/* MTV service */

#define MTV_SET_RESULT(ctx, req, ret, event) \
    ctx->pending_msgs--; \
    *req->result = ret; \
    kal_set_eg_events(ctx->req_events, event, KAL_OR);

_MTV_FORCE_NOINLINE_
static void mtv_open_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_open_req_struct, req, ilm);
    mtv_context_t* ctx = &g_mtv_context;    /* currently use the global context */
    kal_int32 ret;

    #ifdef __MM_DCM_SUPPORT__
        media_mtv_dcm_load();
    #endif

    *(req->context) = (kal_uint32) NULL;

    if (ctx->state == MTV_STATE_CLOSED)
    {
        ctx->app_id = req->app_id;
        ret = mtv_init_shared_mem_pool(MAX_MED_MTV_MEMORY);
        if (ret != MTV_S_OK)
        {
            goto mtv_open_fail;
        }

        ret = ctx->sm.open(&ctx->sm, req->mode, ctx->app_id, req->init_param, mtv_service_callback, ctx);
        if (ret >= 0)
        {
            *(req->context) = (kal_uint32) ctx;
            ctx->state = MTV_STATE_OPENED;
            ctx->src_mod = ilm->src_mod_id;
        }
        else
        {
            mtv_uninit_shared_mem_pool();
        }
        #if defined(__MED_MTV_MOD__)
            ctx->esg_results = NULL;
        #endif
    }
    else if (ctx->state == MTV_STATE_OPENED)
    {
        ret = MTV_E_WRONG_STATE;
    }
    else if (ctx->state == MTV_STATE_CLOSING)
    {
        ret = MTV_E_BUSY;
    }
    else
    {
        ret = MTV_E_WRONG_STATE;
        NOT_REACHED("Invalid context state!");
    }

    if (ret >= 0) {
        mtv_send_system_event_ind(ctx->src_mod, ctx, MEDIA_MTV_SYSTEM_OPENED, 0);
    }

mtv_open_fail:

    #ifdef __MM_DCM_SUPPORT__
    if (ret < 0)
    {
        media_mtv_dcm_unload();
    }
    #endif

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_OPEN_REQ);
}

static void mtv_final_close(void* param)
{
    mtv_context_t* ctx = (mtv_context_t*) param;

    ASSERT(ctx->state == MTV_STATE_CLOSING);

    /* free system resources */
#if defined(__MED_MTV_MOD__)
    mtv_free_aio_resource();
    mtv_free_ext_mem((void**)&g_mtv_context.program_info);
#endif
    mtv_uninit_shared_mem_pool();

    /* send CLOSED event */
    mtv_send_system_event_ind(ctx->src_mod, ctx, MEDIA_MTV_SYSTEM_CLOSED, 0);

    ctx->state = MTV_STATE_CLOSED;

    #ifdef __MM_DCM_SUPPORT__
        media_mtv_dcm_unload();
    #endif
}

_MTV_FORCE_NOINLINE_
static void mtv_close_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_close_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    /* find available service manager */
    if (ctx->state == MTV_STATE_OPENED)
    {
        ctx->state = MTV_STATE_CLOSING;
        ctx->req_async_result = req->result;

        #if defined(__MED_MTV_MOD__)
            /* free pending query results before SM is closed */
            mtv_esg_query_free_buffer(ctx, MEDIA_MTV_ESG_SOURCE_DEFAULT, &ctx->esg_results);
        #endif //#if defined(__MED_MTV_MOD__)

        ret = ctx->sm.close(&ctx->sm);
        ASSERT(ret >= 0);
    }
    else if (ctx->state == MTV_STATE_CLOSED)
    {
        ret = MTV_E_WRONG_STATE;
        SHOULD_NOT_HAPPEN("Try to close an unopen context!");
    }
    else
    {
        ret = MTV_E_FAIL;
        NOT_REACHED("Invalid context state!");
    }

    /* let the client proceed because close is asynchronous */
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CLOSE_REQ);
}

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MEDMTV_ROCODE", rodata = "DYNAMIC_CODE_MEDMTV_RODATA"
#endif

_MTV_FORCE_NOINLINE_
static void mtv_config_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_config_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.config(&ctx->sm,
        (req->fields & MEDIA_MTV_CONFIG_AUDIO) != 0 ? &req->audio : NULL,
        (req->fields & MEDIA_MTV_CONFIG_VIDEO) != 0 ? &req->video : NULL,
        (req->fields & MEDIA_MTV_CONFIG_RECORD) != 0 ? &req->record : NULL);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CONFIG_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_search_services_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_search_services_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;
    mtv_freq_band_t band;

    ASSERT(ctx->state == MTV_STATE_OPENED);
    if (MEDIA_MTV_ATV_BEGIN <= req->band && req->band <= MEDIA_MTV_ATV_END)
    {
        band = (mtv_freq_band_t)(MTV_FREQ_ATV_BEGIN + ((media_mtv_band_enum)req->band - MEDIA_MTV_ATV_BEGIN));
    }
    else
    {
        switch ((media_mtv_band_enum)req->band)
        {
        case MEDIA_MTV_INVALID_BAND:
            band = MTV_FREQ_INVALID_BAND;
            break;
        case MEDIA_MTV_TDMB_KOREA_BAND:
            band = MTV_FREQ_KOREA_BAND;
            break;
        case MEDIA_MTV_TDMB_BAND_III:
            band = MTV_FREQ_BAND_III;
            break;
        case MEDIA_MTV_TDMB_L_BAND:
            band = MTV_FREQ_L_BAND;
            break;
        case MEDIA_MTV_TDMB_CANADA_BAND:
            band = MTV_FREQ_CANADA_BAND;
            break;
        case MEDIA_MTV_TDMB_CHINESE_BAND:
            band = MTV_FREQ_CHINESE_BAND;
            break;
        case MEDIA_MTV_TDMB_BAND_II:
            band = MTV_FREQ_BAND_II;
            break;
        case MEDIA_MTV_TDMB_BAND_IF:
            band = MTV_FREQ_BAND_IF;
            break;
        case MEDIA_MTV_CMMB_U_BAND:
            band = MTV_FREQ_CHINESE_BAND;
            break;
        case MEDIA_MTV_ANY_BAND:
            band = MTV_FREQ_ANY_BAND;
            break;
        default:
            NOT_REACHED("Invalid frequency band?!");
            band = MTV_FREQ_INVALID_BAND;
            break;
        }
    }

    ctx->session_id_of_search_services = req->seq_no;
    ret = ctx->sm.search_services(&ctx->sm, (media_mtv_service_source_enum)req->source, band, req->param);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SEARCH_SERVICES_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_abort_searching_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_abort_searching_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.abort_searching(&ctx->sm);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ABORT_SEARCHING_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_service_get_info_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_service_get_info_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_service_context_t sc;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.get_service_context(&ctx->sm, MTV_GET_SC_METHOD_SERVICE_ID, req->service_id, &sc);
    if (ret >= 0) {
        mtv_fill_service_info(req->info, &sc);
    }

    MTV_SET_RESULT(ctx, req, ret >= 0 ? MED_RES_OK : MED_RES_FAIL, MTV_EVT_SERVICE_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_start_service_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_start_service_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.start_service(&ctx->sm, req->service_id, req->activities, req->seq_no);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SERVICE_REQ);
}

#if defined(__MTV_TS_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_start_timeshift_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_start_timeshift_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.start_timeshift(&ctx->sm, req->service_id, req->seq_no);

    MTV_SET_RESULT(ctx, req, ret >= 0 ? MED_RES_OK : MED_RES_FAIL, MTV_EVT_TIMESHIFT_REQ);
}
#endif //#if defined(__MTV_TS_SUPPORT__)

_MTV_FORCE_NOINLINE_
static void mtv_player_play_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_play_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.start_player(&ctx->sm, req->service_id, req->seq_no);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_player_stop_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_stop_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.stop_player(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

#if defined(__MED_MTV_MOD__)
_MTV_FORCE_NOINLINE_
static void mtv_player_pause_visual_update_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_pause_visual_update_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.pause_visual_update(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_player_resume_visual_update_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_resume_visual_update_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.resume_visual_update(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}
#endif  // #if defined(__MED_MTV_MOD__)

#if defined(__MTV_TS_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_player_pause_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_pause_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    {
        mtv_control_timeshift_t* control = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->set_pause(control, KAL_TRUE);
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_player_seek_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_seek_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    {
        mtv_control_timeshift_t* control = NULL;
        ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->set_delay(control, req->delay);
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_player_set_rate_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_set_rate_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    {
        mtv_control_trick_mode_t* control = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TRICK_MODE, (void**) &control);
        if (control) {
            ret = control->set_rate(control, req->rate);
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}
#endif

_MTV_FORCE_NOINLINE_
static void mtv_player_snapshot_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_snapshot_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.snapshot(&ctx->sm, req->service_id, req->buf);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_player_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    {
        mtv_service_player_status_t player_status;

        ret = ctx->sm.get_player_status(&ctx->sm, req->service_id, &player_status);
        if (ret >= 0)
        {
            req->status->state = player_status.state;
            req->status->play_delay = player_status.play_delay;
            req->status->max_delay = player_status.max_delay;
            req->status->buffer_duration = player_status.buffer_duration;
            req->status->play_rate = player_status.play_rate;
        }
        else
        {
            req->status->state = MEDIA_MTV_PLAYER_STATE_STOPPED;
            req->status->play_delay = 0;
            req->status->max_delay = 0;
            req->status->buffer_duration = 0;
            req->status->play_rate = 1000;
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_REQ);
}

#if defined(__MTV_REC_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_find_unsaved_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_find_unsaved_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.find_unsaved_recording(&ctx->sm, req->found);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_FIND_UNSAVED_RECORDING_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recover_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recover_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;
    kal_uint32 seq_no = req->seq_no;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    /* let the requesting task continue to run */
    MTV_SET_RESULT(ctx, req, MED_RES_OK, MTV_EVT_RECOVER_RECORDING_REQ);

    ret = ctx->sm.recover_recording(&ctx->sm);

    mtv_send_complete_recovering_ind(ctx->src_mod, ctx, mtv_error_to_med_error(ret), seq_no);
}

_MTV_FORCE_NOINLINE_
static void mtv_abort_recovering_req_hdlr(ilm_struct *ilm)
{
    media_mtv_abort_recovering_req_struct* req = (media_mtv_abort_recovering_req_struct*) ilm->local_para_ptr;
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.abort_recovering(&ctx->sm);
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ABORT_RECOVERING_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_discard_unsaved_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_discard_unsaved_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    /* asynchronous operation */
    MTV_SET_RESULT(ctx, req, MED_RES_OK, MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ);

    ret = ctx->sm.discard_unsaved_recording(&ctx->sm);
    mtv_send_system_event_ind(ctx->src_mod, ctx, MEDIA_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED, mtv_error_to_med_error(ret));
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_start_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_start_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.start_recorder(&ctx->sm, req->service_id, req->service_name, req->seq_no);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_stop_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_stop_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.stop_recorder(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_pause_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_pause_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.pause_recorder(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_resume_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_resume_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.resume_recorder(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_save_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_save_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.prepare_saving(&ctx->sm, req->service_id);

    /* let the requesting task continue to run */
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);

    /* then do the actual saving */
    if (ret >= 0) {
        ret = ctx->sm.save_recording(&ctx->sm, req->service_id, req->seq_no, req->file_path);
    }
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_abort_saving_req_hdlr(ilm_struct *ilm)
{
    media_mtv_recorder_abort_saving_req_struct* req = (media_mtv_recorder_abort_saving_req_struct*) ilm->local_para_ptr;

    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.abort_saving(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_discard_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_discard_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    /* asynchronous operation */
    MTV_SET_RESULT(ctx, req, MED_RES_OK, MTV_EVT_RECORDER_REQ);

    ctx->sm.recorder_discard_recording(&ctx->sm, req->service_id, req->seq_no);
}

_MTV_FORCE_NOINLINE_
static void mtv_recorder_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    {
        mtv_recorder_state_t rec_state = MTV_RECORDER_STATE_STOPPED;

        ret = ctx->sm.get_recorder_state(&ctx->sm, req->service_id, &rec_state);
        switch (rec_state)
        {
        case MTV_RECORDER_STATE_STARTED:
            {
                mtv_control_record_t* control = NULL;
                ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_RECORD, (void**) &control);
                ASSERT(control != NULL);

                req->status->state = MEDIA_MTV_RECORDER_STATE_STARTED;
                ret = control->get_recorded_duration(control, &req->status->recorded_duration);
                break;
            }

        case MTV_RECORDER_STATE_STOPPED:
            req->status->state = MEDIA_MTV_RECORDER_STATE_STOPPED;
            req->status->recorded_duration = 0;
            break;

        case MTV_RECORDER_STATE_SAVING:
            req->status->state = MEDIA_MTV_RECORDER_STATE_SAVING;
            req->status->recorded_duration = 0;
            ret = MTV_S_OK;
            break;

        default:
            NOT_REACHED("Unhandled recorder state?!");
            ret = MTV_E_FAIL;
            break;
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_REQ);
}
#endif //#if defined(__MTV_REC_SUPPORT__)

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_restart_chip_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_restart_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.restart_chip(&ctx->sm, req->service_id, req->seq_no);
    
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CHIP_RESTART_REQ);
}
#endif

_MTV_FORCE_NOINLINE_
static void mtv_get_param_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_get_param_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_sm_t* sm = &ctx->sm;
    mtv_result_t ret = MTV_E_INVALID_PARAM;
    mtv_service_context_t *sc;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    switch (req->param)
    {
    case MEDIA_MTV_SERVICE_PARAM_AUDIO_SAMPLE_RATE:
    {
        mtv_service_media_info_t mi;
        ret = sm->get_media_info(sm, req->service_id, &mi);
        if (ret >= 0)
        {
            *req->value = mi.audio_st.format.audio.sample_rate;
        }
        break;
    }
    case MEDIA_MTV_SERVICE_PARAM_AUDIO_CHANNEL_NUMBER:
    {
        mtv_service_media_info_t mi;
        ret = sm->get_media_info(sm, req->service_id, &mi);
        if (ret >= 0)
        {
            *req->value = mi.audio_st.format.audio.channels;
        }
        break;
    }
    case MEDIA_MTV_SERVICE_PARAM_SERVICE_INFO_BY_INDEX:

        sc = mtv_alloc_ext_mem(sizeof(mtv_service_context_t), MAKE_FOURCC('M','S','C','T'));
        kal_mem_set(sc, 0, sizeof(mtv_service_context_t));

        ret = sm->get_service_context(&ctx->sm, MTV_GET_SC_METHOD_INDEX, req->service_id, sc);
        if (ret >= 0) {
            mtv_fill_service_info((media_mtv_service_info_struct*)req->value, sc);
        }
        mtv_free_ext_mem((void **)&sc);
        break;

#if defined(__MED_MTV_MOD__)
    case MEDIA_MTV_SERVICE_PARAM_SERVICE_CA:
        ASSERT(ctx->state == MTV_STATE_OPENED);

        sc = mtv_alloc_ext_mem(sizeof(mtv_service_context_t), MAKE_FOURCC('M','S','C','T'));
        kal_mem_set(sc, 0, sizeof(mtv_service_context_t));

        ret = sm->get_service_context(sm, MTV_GET_SC_METHOD_SERVICE_ID, req->service_id, sc);
        mtv_free_ext_mem((void **)&sc);

        if (ret >= 0)
        {
            media_mtv_service_ca_struct ca = {0};
            media_mtv_service_ca_struct *req_ca;

            /* Use local variable to get ca */
            ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SERVICE_CA, (kal_uint32 *)&ca);
            ca.flag = map_to_med_mtv_service_flags(ca.flag);
            /* Assign to mmi pointer */
            req_ca = (media_mtv_service_ca_struct *) req->value;
            req_ca->flag = ca.flag;
        }
        break;

    case MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC, (kal_uint32 *)req->value);
        break;
#endif

    case MEDIA_MTV_SERVICE_PARAM_VIDEO_MODE:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_VIDEO_MODE, req->value);
        break;

    case MEDIA_MTV_SERVICE_PARAM_IMD_COUNT:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_IMD_COUNT, (kal_uint32 *)req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_IMD_DESC:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_IMD_DESC, (kal_uint32 *)req->value);
        break;
     case MEDIA_MTV_SERVICE_PARAM_IMD_DETAIL:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_IMD_DETAIL, (kal_uint32 *)req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_NIT_AREA:
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_NIT_AREA, (kal_uint32 *)req->value);
        break;

    case MEDIA_MTV_SERVICE_PARAM_NIT_TIME:
        ret= sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_NIT_TIME, (kal_uint32 *)req->value);
        break;
    default:
        break;
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_GET_PARAM_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_service_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_service_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_sm_t* sm = &ctx->sm;
    mtv_result_t ret = MTV_S_OK;
    mtv_service_context_t sc;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = sm->get_service_context(sm, MTV_GET_SC_METHOD_SERVICE_ID, req->service_id, &sc);
    if (ret >= 0)
    {
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SIGNAL_STRENGTH, &req->status->signal_strength);
        if (ret < 0)
        {
            req->status->signal_strength = 0;
            ret = MTV_S_OK;
        }
        #if defined(__MTV_TS_SUPPORT__)
            req->status->timeshift_available = (kal_bool)(sc.be != NULL);
        #else
            req->status->timeshift_available = KAL_FALSE;
        #endif

        switch (sc.state)
        {
        case MTV_SERVICE_STATE_STOPPED:
        case MTV_SERVICE_STATE_ABORTED:
        case MTV_SERVICE_STATE_REMOVED:
            req->status->state = MEDIA_MTV_SERVICE_STATE_STOPPED;
            break;

        case MTV_SERVICE_STATE_STARTED:
            req->status->state = MEDIA_MTV_SERVICE_STATE_STARTED;
            break;

        case MTV_SERVICE_STATE_READY:
            req->status->state = MEDIA_MTV_SERVICE_STATE_READY;
            break;

        default:
            NOT_REACHED("Unhandled service state?!");
            ret = MTV_E_FAIL;
            break;
        }
    }
    else
    {
        req->status->state = MEDIA_MTV_SERVICE_STATE_STOPPED;
        req->status->signal_strength = 0;
        req->status->timeshift_available = KAL_FALSE;
        ret = MTV_S_OK;
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SERVICE_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_stop_service_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_stop_service_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = ctx->sm.stop_service(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SERVICE_REQ);
}

#if defined(__MED_MTV_MOD__)
static void mtv_esg_query_free_buffer(mtv_context_t *ctx, media_mtv_esg_source_enum source, void** buf_head)
{
    mtv_sm_t *sm = &ctx->sm;
    void *curr_p = (void*)*buf_head;
    void *next_p = NULL;

    if (source == MEDIA_MTV_ESG_SOURCE_MBBMS)
    {
        while (curr_p)
        {
            next_p = ((esg_query_service_struct*)curr_p)->next_p;

            ctx->mtv_ext_db->free_buffer(ctx->mtv_ext_db, (void*)curr_p);
            curr_p = next_p;
        }
    }
    else
    {
        while (curr_p)
        {
            next_p = ((esg_query_service_struct*)curr_p)->next_p;

            sm->esg_free_result_buffer(sm, (void*)curr_p);
            curr_p = next_p;
        }
    }

    *buf_head = NULL;
}
#endif //#if defined(__MED_MTV_MOD__)

#if defined(__MED_MTV_MOD__)
_MTV_FORCE_NOINLINE_
static void mtv_media_mtv_esg_download_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_media_mtv_esg_download_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.esg_download(&ctx->sm);

    MTV_SET_RESULT(ctx, req, ret >= 0 ? MED_RES_OK : MED_RES_FAIL, MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_media_mtv_esg_abort_downloading_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_media_mtv_esg_abort_downloading_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.esg_abort_downloading(&ctx->sm);

    MTV_SET_RESULT(ctx, req, ret >= 0 ? MED_RES_OK : MED_RES_FAIL, MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_open_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_open_req_struct, req, ilm);
    mtv_context_t* ctx = &g_mtv_context;
    mtv_result_t ret = MTV_E_FAIL;

    *(req->context) = (kal_uint32) NULL;

    ASSERT(req->source == MEDIA_MTV_ESG_SOURCE_MBBMS);
    if (ctx->state == MTV_STATE_CLOSED)
    {
        ctx->app_id = req->app_id;

        ret = mtv_init_shared_mem_pool(MAX_MED_MTV_ESG_MEMORY);
        if (ret != MTV_S_OK)
        {
            goto esg_open_fail;
        }

        ctx->state = MTV_STATE_ESG_ONLY;
    }

    /* free pending query results before another ESG DB open */
    mtv_esg_query_free_buffer(ctx, MEDIA_MTV_ESG_SOURCE_DEFAULT, &ctx->esg_results);

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
    ASSERT(ctx->mtv_ext_db == NULL);
    ctx->mtv_ext_db = construct_mbbms_sg_db();
    ASSERT(ctx->mtv_ext_db);
    ret = ctx->mtv_ext_db->open(ctx->mtv_ext_db, mtv_get_setting_dir());
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */
    *(req->context) = (kal_uint32)ctx;

esg_open_fail:

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_close_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_close_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    ASSERT(req->source == MEDIA_MTV_ESG_SOURCE_MBBMS);

    ASSERT(ctx->mtv_ext_db);

    mtv_esg_query_free_buffer(ctx, req->source, &ctx->esg_results);

    ret = ctx->mtv_ext_db->close(ctx->mtv_ext_db);
    ASSERT(ret >= 0);
    ctx->mtv_ext_db->destroy(ctx->mtv_ext_db);
    ctx->mtv_ext_db = NULL;

    if (ctx->state == MTV_STATE_ESG_ONLY)
    {
        mtv_uninit_shared_mem_pool();
        ctx->state = MTV_STATE_CLOSED;
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_query_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_query_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    media_mtv_esg_source_enum source = req->source;
    mtv_result_t ret = MTV_E_FAIL;

    mtv_esg_query_free_buffer(ctx, req->source, &ctx->esg_results);

    if (source == MEDIA_MTV_ESG_SOURCE_MBBMS)
    {
        mtv_esg_query_param param = {0};


        param.applib_time = req->query->applib_time;
        param.lang_type = (esg_query_language_type_enum)req->query->lang_type;
        param.ref_id = req->query->ref_id;
        param.rid = req->query->rid;
        param.keyword = req->query->keyword;
        param.start_idx = req->query->start_idx;
        param.query_num = req->query->query_num;

        ret = ctx->mtv_ext_db->query(ctx->mtv_ext_db, (esg_query_type_enum)req->type, &param);
    }
    else
    {
        ret = ctx->sm.esg_query(&ctx->sm, (esg_query_type_enum)req->type, req->query);
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_get_results_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_get_results_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    media_mtv_esg_source_enum source = req->source;
    mtv_result_t ret = MTV_S_OK;
    mtv_result_t res;

    esg_query_type_enum type = (esg_query_type_enum)req->type;
    void** buf_p = req->buf_p;
    void *curr_p = NULL;
    void *next_p = NULL;
    kal_int32 cnt = ESG_MAX_GET_RESULTS_SIZE;

    ASSERT((*buf_p == NULL));

    mtv_esg_query_free_buffer(ctx, source, &ctx->esg_results);

    if (source == MEDIA_MTV_ESG_SOURCE_MBBMS)
    {
        if (MTV_S_OK == ctx->mtv_ext_db->get_result(ctx->mtv_ext_db, type, buf_p))
        {
            /* Store the type of get result */
            ctx->query_type = type;
            cnt--;
            curr_p = *buf_p;
            while ((cnt > 0))
            {
                res = ctx->mtv_ext_db->get_result(ctx->mtv_ext_db, type, (void**)&next_p);
                if (res == MTV_S_OK)
                {
                    ((esg_query_service_struct*)curr_p)->next_p = next_p;
                    curr_p = next_p;
                    next_p = NULL;
                    cnt--;
                }
                else
                    cnt = 0;
            }
            ret = MTV_S_OK;
        }
    }
    else
    {
        if (MTV_S_OK == ctx->sm.esg_get_result(&ctx->sm, type, buf_p))
        {
            /* Store the type of get result */
            ctx->query_type = type;
            cnt--;
            curr_p = *buf_p;
            while ((cnt > 0))
            {
                res = ctx->sm.esg_get_result(&ctx->sm, type, (void**)&next_p);
                if (res == MTV_S_OK)
                {
                    ((esg_query_service_struct*)curr_p)->next_p = next_p;
                    curr_p = next_p;
                    next_p = NULL;
                    cnt--;
                }
                else
                    cnt = 0;
            }
            ret = MTV_S_OK;
        }
    }

    ctx->esg_results = *buf_p;

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_query_finish_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_query_finish_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    media_mtv_esg_source_enum source = req->source;
    mtv_result_t ret = MTV_E_FAIL;

    mtv_esg_query_free_buffer(ctx, req->source, &ctx->esg_results);

    if (source == MEDIA_MTV_ESG_SOURCE_MBBMS)
    {
        ret = ctx->mtv_ext_db->query_finish(ctx->mtv_ext_db);
    }
    else
    {
        ret = ctx->sm.esg_query_finish(&ctx->sm);
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_add_favorite_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_add_favorite_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    ret = ctx->sm.esg_add_favorite(&ctx->sm, req->type, req->id, req->rid);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_esg_del_favorite_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_esg_del_favorite_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    ret = ctx->sm.esg_del_favorite(&ctx->sm, req->type, req->id, req->rid);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ESG_QUERY_REQ);
}

_MTV_FORCE_NOINLINE_
static void mtv_cas_get_card_info_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_cas_get_card_info_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_sm_t* sm = &ctx->sm;
    mtv_result_t ret = MTV_S_OK;
    kal_char *card_ptr;
    ASSERT(ctx->state == MTV_STATE_OPENED);

    ret = sm->ca_get_card_info(sm, &card_ptr);
    kal_mem_cpy(req->card_info->number, card_ptr, 16);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CAS_INFO_REQ);
}
#endif //#if defined(__MED_MTV_MOD__)

#if defined(__MTV_TS_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_async_write_req_hdlr(ilm_struct *ilm)
{
    media_mtv_async_write_req_struct* req = (media_mtv_async_write_req_struct*) ilm->local_para_ptr;
    async_io_process_writing(req->io);
}
#endif // #if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
/* will be called in MED-V task */
static void mtv_on_async_mod_closed(void* param)
{
    mtv_context_t* ctx = (mtv_context_t*) param;

    mtv_call_async(MTV_CONTROL_MOD, mtv_final_close, ctx);
}

/* will be called in MTV task */
static void mtv_on_background_mod_closed(void* param)
{
    mtv_context_t* ctx = (mtv_context_t*) param;

    async_io_register_notification(mtv_on_async_mod_closed, ctx);
}
#endif // #if defined(__MED_MTV_MOD__)

#if defined(__MED_MTV_MOD__) || defined(__MTV_REC_SUPPORT__)
void mtv_call_async(module_type src_mod_id, void (*proc)(void* param), void* param)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_async_callback_req_struct, req);
    req->callback = proc;
    req->param = param;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_ASYNC_CALLBACK_REQ, req);
}

_MTV_FORCE_NOINLINE_
static void mtv_async_callback_req_hdlr(ilm_struct *ilm)
{
    media_mtv_async_callback_req_struct* req = (media_mtv_async_callback_req_struct*) ilm->local_para_ptr;

    /* invoke the callback directly */
    req->callback(req->param);
}
#endif  // #if defined(__MED_MTV_MOD__) || defined(__MTV_REC_SUPPORT__)

static void mtv_service_callback(void* context, mtv_service_callback_param_t* param)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    mtv_service_context_t* sc;
    kal_uint32 sid = MTV_SERVICE_INVALID_ID;

    ASSERT(param != NULL);
    sc = param->sc;

    /* get service id, from callback service context or service id */
    if (sc)
    {
        sid = sc->info.id;
    }
    else
    {
        sid = param->service_id;
    }

    switch (param->event)
    {
    case MTV_SERVICE_EVENT_FOUND:
        mtv_send_service_found_ind(ctx->src_mod, context, sc);
        break;

    case MTV_SERVICE_EVENT_STARTED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_STARTED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_READY:

        mtv_fill_service_info(&sc->public_info, sc);
        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_READY, (kal_uint32)&sc->public_info, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_STARTED:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_STARTED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

#if defined(__MTV_TS_SUPPORT__)
    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_PAUSED:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_DELAYED:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_LIVE:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_TIMESHIFT_LIVE, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_ERROR:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_TIMESHIFT_ERROR, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_BEGINNING_OF_CONTENT:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_END_OF_CONTENT:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_END_OF_CONTENT, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_RATE_CHANGE:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_RATE_CHANGE, param->event_param, param->session_id);
        break;
#endif

    case MTV_SERVICE_EVENT_PLAYER_ERROR:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_ERROR, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_PLAYER_STOPPED:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_STOPPED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

#if defined(__MTV_REC_SUPPORT__)
    case MTV_SERVICE_EVENT_RECORDER_STARTED:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_STARTED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_SAVING:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_SAVING, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_RECORDING_DISCARDED:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_RECORDING_DISCARDED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_SAVING_SUCCEEDED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_SAVING_FAILED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_ERROR:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_ERROR, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_RECORDER_STOPPED:

        mtv_send_recorder_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_RECORDER_STOPPED, param->event_param, param->session_id);
        break;
#endif // #if defined(__MTV_REC_SUPPORT__)

    case MTV_SERVICE_EVENT_STOPPED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_STOPPED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_ABORTED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_ABORTED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_ADDED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_ADDED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_UPDATED:

        mtv_fill_service_info(&sc->public_info, sc);
        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_UPDATED, (kal_uint32)&sc->public_info, param->session_id);
        break;

    case MTV_SERVICE_EVENT_REMOVED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_REMOVED, mtv_error_to_med_error(param->event_param), param->session_id);
        break;

    case MTV_SERVICE_EVENT_SEARCH_PROGRESS:

        ASSERT(sc == NULL);
        mtv_send_search_progress_ind(ctx->src_mod, context, param->event_param, ctx->session_id_of_search_services);
        break;

    case MTV_SERVICE_EVENT_FATAL_ERROR:

        /* to be implemented */
        break;

    case MTV_SERVICE_EVENT_CLOSED:

        #if defined(__MED_ATV_MOD__)

            /* ATV do not have async task jobs, close it directly */
            mtv_final_close(ctx);

        #else // #if defined(__MED_MTV_MOD__)

            /**
              * Since MTV may still be busy with some stuff. Need to wait until it handles this
              * message and then MED can do the final close.
              */
            mtv_call_async(MTV_BACKGROUND_MOD, mtv_on_background_mod_closed, ctx);

        #endif // #if defined(__MED_ATV_MOD__)

        break;

#if defined(__MED_MTV_MOD__)

    case MTV_SERVICE_EVENT_BAD_RECEPTION:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_BAD_RECEPTION, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_GOOD_RECEPTION:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_GOOD_RECEPTION, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_PROGRAM_INFO: {
        kal_uint32 i;
        mtv_spi_program_info_t* pi = (mtv_spi_program_info_t*) param->event_param;
        if (!ctx->program_info) {
            ctx->program_info = mtv_alloc_ext_mem(sizeof(media_mtv_program_info_struct), MAKE_FOURCC('M','E','P','I'));
        }

        ctx->program_info->record_count = pi->record_count;
        for (i = 0; i < pi->record_count; i++)
        {
            ctx->program_info->records[i].date = pi->records[i].date;
            ctx->program_info->records[i].time = pi->records[i].time;
            ctx->program_info->records[i].duration = pi->records[i].duration;
            kal_wstrncpy(ctx->program_info->records[i].title, pi->records[i].title, ARRAY_SIZE(ctx->program_info->records[i].title) - 1);
        }

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_PROGRAM_INFO, (kal_uint32) ctx->program_info, param->session_id);
        break;
        }

    case MTV_SERVICE_EVENT_DYNAMIC_LABEL:

        mtv_send_player_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_PLAYER_DYNAMIC_LABEL, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_ACCESS_GRANTED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_ACCESS_GRANTED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_ACCESS_DENIED:

        mtv_send_service_event_ind(ctx->src_mod, context, sid, MEDIA_MTV_SERVICE_ACCESS_DENIED, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_EMERGENCY_MSG:

        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_EMERGENCY_MSG, 0, 0);
        break;

    case MTV_SERVICE_EVENT_ESG_NEW_AVAILABLE:

        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_ESG_NEW_AVAILABLE, 0, 0);
        break;

    case MTV_SERVICE_EVENT_ESG_DOWNLOADED:

        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_ESG_DOWNLOADED, 0, 0);
        break;

    case MTV_SERVICE_EVENT_ESG_UPDATED:

        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_ESG_UPDATED, 0, 0);
        break;

    case MTV_SERVICE_EVENT_SET_EMM_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_SET_EMM_DONE, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_GET_CA_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_GET_CA_DONE, param->event_param, 0);
        break;

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
    case MTV_SERVICE_EVENT_SG_UPDATE_RET:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_SG_UPDATE_RET, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_UPGRADE_RET:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_UPGRADE_RET, mtv_error_to_med_error(param->event_param), 0);
        break;

    case MTV_SERVICE_EVENT_INTERACTIVITY_RETRIEVE_RET:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET, mtv_error_to_med_error(param->event_param), 0);
        break;

    case MTV_SERVICE_EVENT_IMD_READY:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_IMD_READY, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_AREA_RETRIEVE_DATA:
        ASSERT(sc == NULL);
        mtv_send_recommend_city_found_ind(ctx->src_mod, context, (kal_wchar *)param->event_param);
        break;

    case MTV_SERVICE_EVENT_AREA_RETRIEVE_RET:
        ASSERT(sc == NULL);
        mtv_flush_city_found_ind(ctx->src_mod, context);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_AREA_RETRIEVE_RET, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_GBA_RET:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_GBA_RET, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DATA:
        ASSERT(sc == NULL);
        mtv_send_account_inquiry_ind(ctx->src_mod, context, param->event_param);
        break;

    case MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_ACCOUNT_INQUIRY_DONE, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_SUBSCRIPTION_UPDATE_RET:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_SUBSCRIPTION_UPDATE_RET, param->event_param, param->session_id);
        break;

    case MTV_SERVICE_EVENT_SUBSCRIBE_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_SUBSCRIBE_DONE, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_UNSUBSCRIBE_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE, param->event_param, 0);
        break;

    case MTV_SERVICE_EVENT_MSK_RETRIEVE_DONE:
        ASSERT(sc == NULL);
        mtv_send_service_event_ind(ctx->src_mod, context, 0, MEDIA_MTV_SERVICE_MSK_RETRIEVE_DONE, param->event_param, 0);
        break;
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */
#endif // #if defined(__MED_MTV_MOD__)
    default:
        NOT_REACHED("Unhandled event!");
        break;
    }
}

#endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) */


#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)

/* the size should be 4x bytes */
typedef struct
{
    kal_uint32 fourcc;
    kal_uint32 size;

} mtv_mem_block_hdr_t;

void* mtv_alloc_ext_mem_impl(kal_int32 size, kal_uint32 fourcc, char* file_p, long line_p)
{
    kal_uint8* block;
    mtv_mem_block_hdr_t* hdr;
    kal_char* cc = (kal_char*) &fourcc;

    MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_ALLOC, cc[0], cc[1], cc[2], cc[3], size);
    mtv_prompt_trace(MOD_MED, "[MTV][MEM] at %s, %d", file_p, line_p);

    kal_take_mutex(g_mtv_context.mtv_adm_lock);

        block = (kal_uint8*) kal_adm_alloc(g_mtv_context.mtv_adm, size + sizeof(mtv_mem_block_hdr_t));
        MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_LEFT, kal_adm_get_total_left_size(g_mtv_context.mtv_adm));

    kal_give_mutex(g_mtv_context.mtv_adm_lock);

    ASSERT(block != NULL);

    hdr = (mtv_mem_block_hdr_t*) block;
    hdr->fourcc = fourcc;
    hdr->size = size;

    UNUSED(cc);

    return (block + sizeof(mtv_mem_block_hdr_t));
}

void* mtv_alloc_ext_mem_cache_impl(kal_int32 size, kal_uint32 fourcc, char* file_p, long line_p)
{
    kal_uint8* block;
    mtv_mem_block_hdr_t* hdr;
    kal_char* cc = (kal_char*) &fourcc;

    MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_ALLOC, cc[0], cc[1], cc[2], cc[3], size);
    mtv_prompt_trace(MOD_MED, "[MTV][MEM] at %s, %d", file_p, line_p);

    kal_take_mutex(g_mtv_context.mtv_adm_lock);

        block = (kal_uint8*) kal_adm_alloc_cacheable(g_mtv_context.mtv_adm, size + sizeof(mtv_mem_block_hdr_t), PAGE_SIZE_4KB);
        MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_LEFT, kal_adm_get_total_left_size(g_mtv_context.mtv_adm));

    kal_give_mutex(g_mtv_context.mtv_adm_lock);

    ASSERT(block != NULL);

    hdr = (mtv_mem_block_hdr_t*) block;
    hdr->fourcc = fourcc;
    hdr->size = size;

    UNUSED(cc);

    return (block + sizeof(mtv_mem_block_hdr_t));
}

void mtv_free_ext_mem_impl(void** p, char* file_p, long line_p)
{
    if (*p)
    {
        mtv_mem_block_hdr_t* hdr = (mtv_mem_block_hdr_t*)(((kal_uint8*)*p) - sizeof(mtv_mem_block_hdr_t));
        kal_char* cc = (kal_char*) &hdr->fourcc;

        MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_FREE, cc[0], cc[1], cc[2], cc[3], hdr->size);
        mtv_prompt_trace(MOD_MED, "[MTV][MEM] at %s, %d", file_p, line_p);

        kal_take_mutex(g_mtv_context.mtv_adm_lock);

            kal_adm_free(g_mtv_context.mtv_adm, hdr);
            MTV_TRACE(TRACE_INFO, MTV_TRC_EXT_MEM_LEFT, kal_adm_get_total_left_size(g_mtv_context.mtv_adm));

        kal_give_mutex(g_mtv_context.mtv_adm_lock);

        UNUSED(cc);

        *p = NULL;
    }
}

kal_wchar* mtv_alloc_filename(void)
{
    return (kal_wchar*) mtv_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar), MAKE_FOURCC('F','L','N','M'));
}

void mtv_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    ilm_struct* ilm = NULL;
    module_type src_mod_id = stack_get_active_module_id();

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    ilm->dest_mod_id = dest_mod_id;

    msg_send_ext_queue(ilm);
}

#endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */

/**
  * Buffer Engine Service
  */
#if defined(__STREAM_REC_SUPPORT__)

#define MAX_MED_MTV_BE_MEMORY (64 * 1024)

kal_bool mtv_bes_init(void)
{
    mtv_init_global_context();
    return KAL_TRUE;
}

mtv_result_t mtv_bes_start(void)
{
    if (g_mtv_context.state != MTV_STATE_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    mtv_init_shared_mem_pool(MAX_MED_MTV_BE_MEMORY);
    g_mtv_context.state = MTV_STATE_BUFFER_ENGINE_ONLY;

    return MTV_S_OK;
}

static void mtv_bes_final_close(void* param)
{
    mtv_context_t* ctx = (mtv_context_t*) param;

    ASSERT(ctx->state == MTV_STATE_BUFFER_ENGINE_ONLY);
    ctx->state = MTV_STATE_CLOSED;

    //mtv_free_aio_resource();
    mtv_uninit_shared_mem_pool();
}

/* will be called in MED-V task */
static void mtv_bes_on_asyncio_mod_closed(void* param)
{
    mtv_context_t* ctx = (mtv_context_t*) param;

    mtv_call_async(MTV_CONTROL_MOD, mtv_bes_final_close, ctx);
}

mtv_result_t mtv_bes_stop(void)
{
    if (g_mtv_context.state != MTV_STATE_BUFFER_ENGINE_ONLY) {
        return MTV_E_WRONG_STATE;
    }

    /* the uninitialization will be done after all async I/O operations */
    //async_io_register_notification(mtv_bes_on_asyncio_mod_closed, &g_mtv_context);

    mtv_bes_final_close(&g_mtv_context);

    return MTV_S_OK;
}

static void mtv_bes_ut_on_read_state_change(
    mtv_buffer_engine_client_t* client,
    mtv_buffer_engine_read_state_t old_state,
    mtv_buffer_engine_read_state_t new_state)
{
}

static void mtv_bes_ut_on_read_seek(mtv_buffer_engine_client_t* client, kal_uint32 target_time, kal_uint32 delay_ms)
{
}

static void mtv_bes_unit_test(void)
{
    mtv_result_t ret;
    mtv_buffer_engine_t* be;
    mtv_buffer_engine_config_t config;
    mtv_buffer_engine_client_t client;
    mtv_stream_info_t stream;
    mtv_source_stat_t src_stat;
    mtv_packet_t packet;
    kal_uint8 video_data[16];
    kal_uint32 events;

    ret = mtv_bes_start();
    ASSERT(ret >= 0);

    be = construct_mtv_buffer_engine();
    ASSERT(be != NULL);

    config.storing_dir = L"d:\\";
    config.max_buffer_kb = 1024;
    config.estimated_bitrate = 512;
    config.flags = MTV_BE_BUFFER_WRAPAROUND;

    client.on_read_state_change = mtv_bes_ut_on_read_state_change;
    client.on_read_seek = mtv_bes_ut_on_read_seek;

    ret = be->open(be, &client, &config);
    ASSERT(ret >= 0);

    stream.type = MTV_STREAM_VIDEO;
    stream.format.video.width = 320;
    stream.format.video.height = 240;
    stream.format.video.time_scale = 90000;
    stream.dec_config.codec = MTV_CODEC_H264;
    stream.dec_config.timestamp_resolution = stream.format.video.time_scale;

    kal_mem_set(&stream.dec_config.u.h264, 0, sizeof(stream.dec_config.u.h264));

    ret = be->add_stream(be, &stream);
    ASSERT(ret >= 0);

    packet.data = video_data;
    packet.size = sizeof(video_data);
    packet.timestamp = 0;
    packet.flags = MTV_PACKET_WITH_RANDOM_ACCESS_POINT;

    ret = be->write_packet(be, 0, &packet, &events, &src_stat);
    ASSERT(ret >= 0);

    ret = be->close(be);
    ASSERT(ret >= 0);

    ret = mtv_bes_stop();
    ASSERT(ret >= 0);
}

#endif /* defined(__STREAM_REC_SUPPORT__) */

#if defined(__MTV_TS_SUPPORT__)
void mtv_start_timeshift_timer(kal_uint32 init_time, mtv_timer_callback_t callback, void* param)
{
    g_mtv_context.timeshift_timer.callback = callback;
    g_mtv_context.timeshift_timer.param = param;

    stack_start_timer(&g_mtv_context.timeshift_timer.timer, 0, init_time);
}

void mtv_stop_timeshift_timer(void)
{
    stack_stop_timer(&g_mtv_context.timeshift_timer.timer);
}
#endif // #if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
void mtv_start_transport_timer(kal_uint32 init_time, mtv_timer_callback_t callback, void* param)
{
    g_mtv_context.transport_timer.callback = callback;
    g_mtv_context.transport_timer.param = param;

    stack_start_timer(&g_mtv_context.transport_timer.timer, 0, init_time);
}

void mtv_stop_transport_timer(void)
{
    stack_stop_timer(&g_mtv_context.transport_timer.timer);
}

static void mtv_timer_callback(mtv_timer_service_t* t)
{
    t->callback(t->param);
}

void mtv_process_time_out(stack_timer_struct* stack_timer_ptr)
{
    if (stack_timer_ptr == &g_mtv_context.timeshift_timer.timer)
    {
        if (stack_is_time_out_valid(stack_timer_ptr))
        {
            #if defined(__MTV_TS_SUPPORT__)
                mtv_timer_callback(&g_mtv_context.timeshift_timer);
            #endif
        }
        stack_process_time_out(stack_timer_ptr);
    }
    else if (stack_timer_ptr == &g_mtv_context.transport_timer.timer)
    {
        if (stack_is_time_out_valid(stack_timer_ptr))
        {
            mtv_timer_callback(&g_mtv_context.transport_timer);
        }
        stack_process_time_out(stack_timer_ptr);
    }
    #if defined(__CMMB_CAS_SMD_SUPPORT__) && defined(__MTK_TARGET__)
        else
        {
            cmmb_ca_os_nagra_timer_timeout(stack_timer_ptr);
        }
    #endif
}

kal_bool mtv_check_pending_requests(void)
{
    return (kal_bool)(g_mtv_context.pending_msgs > 0);
}

kal_int32 mtv_get_service_dump_drive(void)
{
    kal_int32 drive;

    drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_DRIVE_V_NORMAL);
	if (drive > FS_NO_ERROR && FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) >= 0) {
        return drive;
	}

    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    if (drive > FS_NO_ERROR && FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) >= 0) {
        return drive;
	}

    return FS_DRIVE_NOT_FOUND;
}

kal_uint32 mtv_copy_str_with_escape_keyword(kal_wchar* str_dst, kal_wchar* str_src, const kal_wchar* invalid_chars, kal_wchar keyword)
{
    const kal_wchar* ic;
    kal_wchar* p;
    kal_uint32 str_len = 0;

    for (p = str_src; *p != 0; p++)
    {
        for (ic = invalid_chars; *ic != 0; ic++)
        {
            if (*ic == *p)
            {
                *str_dst = keyword;
                str_dst++;
                str_len++;
            }
        }
        *str_dst = *p;
        str_dst++;
        str_len++;
    }

    return str_len;
}
#endif // #if defined(__MED_MTV_MOD__)

#if defined(__ATV_SUPPORT__)
void mtv_atv_set_channel_scan_mode(kal_bool enable)
{
    if (enable == KAL_TRUE)
    {
        g_mtv_atv_default_chlist = KAL_FALSE;
    }
    else
    {
        g_mtv_atv_default_chlist = KAL_TRUE;
    }
}

kal_bool mtv_atv_get_channel_scan_mode(void)
{
    kal_bool ret;

    if (g_mtv_atv_default_chlist == KAL_TRUE)
    {
        ret = KAL_FALSE;
    }
    else
    {
        ret = KAL_TRUE;
    }

    return ret;
}
#endif // #if defined(__ATV_SUPPORT__)

#if defined(__MED_MTV_MOD__) || defined(__MTV_REC_SUPPORT__)
kal_wchar* mtv_str_dup(const kal_wchar* from, kal_uint32 max_len, kal_uint32 usage)
{
    kal_wchar* str = (kal_wchar*) mtv_alloc_ext_mem(max_len * sizeof(kal_wchar), usage);
    kal_wstrncpy(str, from, max_len - 1);

    return str;
}
#endif

mtv_result_t mpl_media_error_to_mtv_result(media_error_t ret)
{
    if (ret == MED_S_ASYNC)
    {
        return MTV_S_ASYNC;
    }
    else if (ret == MED_E_CORRUPTED_DATA)
    {
        return MTV_E_CORRUPTED_DATA;
    }
    else if (ret == MED_E_OVER_LIMIT)
    {
        return MTV_E_OVER_LIMIT;
    }
    else if (ret == MED_E_FRAME_RATE_TOO_HIGH)
    {
        return MTV_E_FRAME_RATE_TOO_HIGH;
    }
    else if (ret == MED_E_MEM_INSUFFICIENT)
    {
        return MTV_E_OUT_OF_MEMORY;
    }
    else if (ret == MED_E_BAD_FORMAT)
    {
        return MTV_E_UNSUPPORTED_FORMAT;
    }
    else if (ret == MED_E_OPEN_FILE_FAIL)
    {
        return MTV_IO_E_INVALID_FILE_HANDLE;
    }
    else if (ret == MED_E_FSAL_ERROR)
    {
        return MTV_IO_E_WRITE_ERROR;
    }
    else if (ret == MED_E_DISC_FULL ||
             ret == MED_E_SIZE_LIMIT_LESS_THAN_MIN_SIZE)
    {
        return MTV_IO_E_DISK_FULL;
    }
    else if (ret == MED_E_NO_DISC ||
             ret == MED_E_MASS_STORAGE_MODE)
    {
        return MTV_IO_E_MEDIA_CHANGED;
    }
    else if (ret >= 0)
    {
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#if defined(__TDMB_SUPPORT__)
static void mtv_tdmb_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
    case MSG_ID_TDMB_DATA_INDICATION:
        {
            MSG_STRUCT(media_mtv_demod_data_ind_struct, ind, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->demod;

		    tdmb_demod->send_tdmb_data(tdmb_demod, ind);
        }
		break;

    case MSG_ID_TDMB_TURN_ON_CONFIRM:
        {
            MSG_STRUCT(tdmb_turn_on_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_turn_on_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_TURN_OFF_CONFIRM:
        {
            MSG_STRUCT(tdmb_turn_off_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_turn_off_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_SET_BAND_CONFIRM:
        {
            MSG_STRUCT(tdmb_set_band_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			tdmb_demod->on_set_band_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_AUTO_SCAN_CONFIRM:
        {
            MSG_STRUCT(tdmb_auto_scan_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_auto_scan_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_STOP_AUTO_SCAN_CONFIRM:
        {
            MSG_STRUCT(tdmb_stop_auto_scan_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_stop_auto_scan_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_SET_FREQUENCY_CONFIRM:
        {
            MSG_STRUCT(tdmb_set_frequency_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_set_frequency_confirm(tdmb_demod, confirm);
        }
    	break;

    case MSG_ID_TDMB_SELECT_SERVICE_CONFIRM:
        {
            MSG_STRUCT(tdmb_select_service_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_select_service_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_GET_SIGNAL_CONFIRM:
        {
            MSG_STRUCT(tdmb_get_signal_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_get_signal_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_SET_IDLE_CONFIRM:
        {
            MSG_STRUCT(tdmb_set_idle_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_set_idle_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_MCI_RECONFIG_INDICATION:
        {
            MSG_STRUCT(tdmb_mci_reconfig_indication_struct, ind, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->cb_para;

		    tdmb_demod->on_mci_reconfig_indication(tdmb_demod, ind);
        }
		break;

    case MSG_ID_TDMB_GET_ENSEMBLE_INFO_CONFIRM:
        {
            MSG_STRUCT(tdmb_get_ensemble_info_confirm_struct, confirm, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

		    tdmb_demod->on_get_ensemble_info_confirm(tdmb_demod, confirm);
        }
		break;

    case MSG_ID_TDMB_ANNOUNCEMENT_INDICATION:
        {
            MSG_STRUCT(tdmb_announcement_indication_struct, ind, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->cb_para;

		    tdmb_demod->on_announcement_indication(tdmb_demod, ind);
        }
		break;

    case MSG_ID_TDMB_GET_TS_DATA_ERROR:
        {
            MSG_STRUCT(tdmb_get_ts_data_error_struct, ind, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->cb_para;

		    tdmb_demod->on_get_ts_data_error(tdmb_demod, ind);
        }
        break;

    default:
        break;
    }
}
#endif /* __TDMB_SUPPORT__ */

#if defined(__CMMB_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_cmmb_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
    case MSG_ID_CMMB_DATA_INDICATION:
        {
            MSG_STRUCT(media_mtv_demod_data_ind_struct, ind, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) ind->demod;

		    rx->on_data_indication(rx, ind);
        }
        break;

    case MSG_ID_CMMB_TURN_ON_CONFIRM:
        {
            MSG_STRUCT(cmmb_turn_on_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_turn_on_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_TURN_OFF_CONFIRM:
        {
            MSG_STRUCT(cmmb_turn_off_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_turn_off_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_SET_BAND_CONFIRM:
        {
            MSG_STRUCT(cmmb_set_band_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_set_band_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_AUTO_SCAN_CONFIRM:
        {
            MSG_STRUCT(cmmb_auto_scan_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_auto_scan_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_STOP_AUTO_SCAN_CONFIRM:
        {
            MSG_STRUCT(cmmb_stop_auto_scan_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_stop_auto_scan_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_SET_FREQUENCY_CONFIRM:
        {
            MSG_STRUCT(cmmb_set_frequency_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_set_frequency_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_SELECT_SERVICE_CONFIRM:
        {
            MSG_STRUCT(cmmb_select_service_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_select_service_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_PAUSE_SERVICE_CONFIRM:
        {
            MSG_STRUCT(cmmb_pause_service_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_pause_service_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_GET_SIGNAL_CONFIRM:
        {
            MSG_STRUCT(cmmb_get_signal_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_get_signal_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_GET_TABLE_CONFIRM:
        {
            MSG_STRUCT(cmmb_get_table_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_get_table_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_STREAM_INFO_TABLE_UPDATE_INDICATION:
        {
            MSG_STRUCT(cmmb_update_table_indication_struct, ind, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) ind->cb_para;

		    rx->on_cit_updating_indication(rx, ind);
        }
        break;

    case MSG_ID_CMMB_CONTROL_INFO_TABLE_UPDATE_INDICATION:
        {
            MSG_STRUCT(cmmb_update_table_indication_struct, ind, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) ind->cb_para;

		    rx->on_cit_updated_indication(rx, ind);
        }
        break;

    case MSG_ID_CMMB_SAVE_STREAM_TO_FILE_CONFIRM:
        {
            MSG_STRUCT(cmmb_save_stream_to_file_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_save_stream_to_file_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_STOP_SAVE_STREAM_TO_FILE_CONFIRM:
        {
            MSG_STRUCT(cmmb_stop_save_stream_to_file_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_stop_save_stream_to_file_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_GET_STREAM_FROM_FILE_CONFIRM:
        {
            MSG_STRUCT(cmmb_get_stream_from_file_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_get_stream_from_file_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_STOP_GET_STREAM_FROM_FILE_CONFIRM:
        {
            MSG_STRUCT(cmmb_stop_get_stream_from_file_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_stop_get_stream_from_file_confirm(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_UAM_ERROR_INDICATION:
        {
            MSG_STRUCT(cmmb_select_service_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

            rx->on_stream_access_denied(rx, confirm);
        }
        break;

    case MSG_ID_CMMB_SET_EMM_CONFIRM:
        {
            MSG_STRUCT(cmmb_set_emm_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

            rx->on_set_emm_confirm(rx, confirm);
        }
        break;
        
#ifdef __CMMB_CAS_MBBMS_SUPPORT__
    case MSG_ID_CMMB_UAM_CHECK_SUPPORT_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_check_support_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_check_support_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_SET_SIMTYPE_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_set_simtype_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_set_symtype_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_GET_CMMBSN_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_get_cmmbsn_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_get_cmmbsn_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_CHECK_GBAISNEED_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_check_gbaisneed_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_check_gbaisneed_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_GET_KEY_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_get_key_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_get_key_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_SET_KEY_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_set_key_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_set_key_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_CHECK_MSKISVALID_CONFIRM:
        {
            MSG_STRUCT(cmmb_uam_check_mskisvalid_confirm_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_check_mskisvalid_confirm(rx, confirm);
        }
        break;
    case MSG_ID_CMMB_UAM_MSK_CHANGE_INDICATION:
        {
            MSG_STRUCT(cmmb_uam_msk_change_indication_struct, confirm, ilm);
            cmmb_rx_t* rx = (cmmb_rx_t*) confirm->cb_para;

		    rx->on_uam_msk_change_indication(rx, confirm);
        }
        break;
#endif
    default:
        break;
    }
}
#endif /* __CMMB_SUPPORT__ */

#if defined(__ATV_SUPPORT__)
_MTV_FORCE_NOINLINE_
static void mtv_atv_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
    case MSG_ID_MEDIA_ATV_SCAN_PROGRESS_IND:
        {
            MSG_STRUCT(media_atv_scan_progress_ind_struct, ind, ilm);
            atv_sp_t* sp = (atv_sp_t*) ind->context;

            sp->on_scan_progress_ind(sp, ind);
        }
        break;

    case MSG_ID_MEDIA_ATV_EVENT_IND:
        {
            MSG_STRUCT(media_atv_event_ind_struct, ind, ilm);
            atv_sp_t* sp = (atv_sp_t*) ind->context;

            sp->on_event(sp, ind);
        }
        break;

#if defined(__ATV_CAMERA_SIM_SUPPORT__)
    case MSG_ID_MEDIA_CAMERA_SCAN_PROGRESS_IND:
        {
            MSG_STRUCT(media_camera_scan_progress_ind_struct, ind, ilm);
            camera_sp_t* sp = (camera_sp_t*) ind->context;

            sp->on_scan_progress_ind(sp, ind);
        }
        break;

    case MSG_ID_MEDIA_CAMERA_EVENT_IND:
        {
            MSG_STRUCT(media_camera_event_ind_struct, ind, ilm);
            camera_sp_t* sp = (camera_sp_t*) ind->context;

            sp->on_event(sp, ind);
        }
        break;
#endif

    default:
        break;
    }
}
#endif /* __ATV_SUPPORT__ */

_MTV_FORCE_NOINLINE_
static void mtv_set_param_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_set_param_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_sm_t* sm = &ctx->sm;
    mtv_result_t ret = MTV_S_OK;
    mtv_control_video_t* control = NULL;

    ASSERT(ctx->state == MTV_STATE_OPENED);

    switch (req->param)
    {
    case MEDIA_MTV_SERVICE_PARAM_PAUSE:
#ifdef __MM_DCM_SUPPORT__
        media_mtv_dcm_unload();
#endif
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_PAUSE, 0);
        break;

    case MEDIA_MTV_SERVICE_PARAM_RESUME:
#ifdef __MM_DCM_SUPPORT__
        media_mtv_dcm_load();
#endif
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_RESUME, 0);
        break;

    case MEDIA_MTV_SERVICE_PARAM_DISABLE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_DISABLE, 0);
        break;

    case MEDIA_MTV_SERVICE_PARAM_NAME:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_NAME, req->value);
        break;

    case MEDIA_MTV_SERVICE_PARAM_AUDIO_MODE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_AUDIO_MODE, req->value);
        break;

#if defined(__MED_ATV_MOD__)
    case MEDIA_MTV_SERVICE_PARAM_BRIGHTNESS:
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_VIDEO, (void**) &control);
        if (control) {
            ret = control->set_brightness(control, req->value);
        }
        break;

    case MEDIA_MTV_SERVICE_PARAM_CONTRAST:
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_VIDEO, (void**) &control);
        if (control) {
            ret = control->set_contrast(control, req->value);
        }
        break;

    case MEDIA_MTV_SERVICE_PARAM_SATURATION:
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_VIDEO, (void**) &control);
        if (control) {
            ret = control->set_gamma(control, req->value);
        }
        break;
#endif

#if defined(__MED_MTV_MOD__)
    case MEDIA_MTV_SERVICE_PARAM_SET_EMM:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_EMM_INFO, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_CA_QUERY:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_CA_INFO, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SUBSCRIBE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_UNSUBSCRIBE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_UNSUBSCRIBE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_ACCOUNT_INQUIRY:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_ACCOUNT_INQUIRY, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_UPGRADE_QUERY:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_UPGRADE_QUERY, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_AREA_SET_RETRIEVE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_AREA_SET_RETRIEVE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_SIM_INFO:
        if (req->value == NULL)
        {
            /* free pending query results before change to CMMB mode */
            mtv_esg_query_free_buffer(ctx, MEDIA_MTV_ESG_SOURCE_DEFAULT, &ctx->esg_results);
        }
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SIM_INFO, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_DOWNLOAD_SG:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_DOWNLOAD_SG, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_UPDATE_SG:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_UPDATE_SG, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_NET_INFO:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_NET_INFO, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_GBA:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_GBA, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_SUBSCRIPTOIN_UPDATE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SUBSCRIPTION_UPDATE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTOIN_UPDATE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTION_UPDATE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_MSK_RETRIEVE:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_MSK_RETRIEVE, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED:
        ret = sm->set_service_param(sm, req->service_id, MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED, req->value);
        break;
    case MEDIA_MTV_SERVICE_PARAM_PLAYER_SET_SLEEP_TIME:
        {
            media_mtv_player_sleep_time_struct* sleep_time = (media_mtv_player_sleep_time_struct*)req->value;

            ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_VIDEO, (void**) &control);
            if (control) {
                ret = control->set_sleep_time(control, sleep_time->elapse_ticks, sleep_time->sleep_ticks);
            }
        }
        break;
#endif // #if defined(__MED_MTV_MOD__)

    default:
        ret = MTV_E_INVALID_PARAM;
        break;
    }

    mtv_zapping_trace(MOD_MED, "[MTV] mtv_set_param_req_hdlr ret[%d]", ret);
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SET_PARAM_REQ);
}

kal_int32 media_mtv_set_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32 value)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_set_param_req_struct, req);

    ASSERT(ctx->state == MTV_STATE_OPENED);

    req->context = context;
    req->service_id = service_id;
    req->param = param;
    req->value = value;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SET_PARAM_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SET_PARAM_REQ);

    return req_result;
}


void mtv_main(ilm_struct* ilm)
{
#if defined(__TDMB_SUPPORT__)
    if (ilm->msg_id >= MSG_ID_TDMB_CODE_BEGIN && ilm->msg_id <= MSG_ID_TDMB_CODE_END) {
        mtv_tdmb_main(ilm);
    }
    else
#endif
#if defined(__CMMB_SUPPORT__)
    if (ilm->msg_id >= MSG_ID_CMMB_CODE_BEGIN && ilm->msg_id <= MSG_ID_CMMB_CODE_END) {
        mtv_cmmb_main(ilm);
    }
    else
#endif /* __CMMB_SUPPORT__ */
#if defined(__ATV_SUPPORT__)
    if (ilm->msg_id >= MSG_ID_ATV_CODE_BEGIN && ilm->msg_id <= MSG_ID_ATV_CODE_END) {
        mtv_atv_main(ilm);
    }
    else
#endif /* __ATV_SUPPORT__ */
    {
        switch (ilm->msg_id)
        {
    #if defined(__MED_MTV_MOD__) || defined(__MTV_REC_SUPPORT__)
        case MSG_ID_MEDIA_MTV_ASYNC_CALLBACK_REQ:
            mtv_async_callback_req_hdlr(ilm);
            break;
    #endif // #if defined(__MED_MTV_MOD__)

        case MSG_ID_MEDIA_MTV_OPEN_REQ:
            mtv_open_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_CONFIG_REQ:
            mtv_config_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ:
            mtv_search_services_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ:
            mtv_abort_searching_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_SERVICE_GET_INFO_REQ:
            mtv_service_get_info_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_START_SERVICE_REQ:
            mtv_start_service_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ:
            mtv_player_play_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ:
            mtv_player_stop_req_hdlr(ilm);
            break;
    #if defined(__MED_MTV_MOD__)
        case MSG_ID_MEDIA_MTV_PLAYER_PAUSE_VISUAL_UPDATE_REQ:
            mtv_player_pause_visual_update_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_RESUME_VISUAL_UPDATE_REQ:
            mtv_player_resume_visual_update_req_hdlr(ilm);
            break;
    #endif  // #if defined(__MED_MTV_MOD__)

    #if defined(__MTV_TS_SUPPORT__)
        case MSG_ID_MEDIA_MTV_ASYNC_WRITE_REQ:
            mtv_async_write_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_START_TIMESHIFT_REQ:
            mtv_start_timeshift_req_hdlr(ilm);

            break;
        case MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ:
            mtv_player_pause_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ:
            mtv_player_seek_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ:
            mtv_player_set_rate_req_hdlr(ilm);
            break;
    #endif // #if defined(__MTV_TS_SUPPORT__)

        case MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ:
            mtv_player_snapshot_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ:
            mtv_player_get_status_req_hdlr(ilm);
            break;
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)            
        case MSG_ID_MEDIA_MTV_RESTART_REQ:
            mtv_restart_chip_req_hdlr(ilm);
            break;
#endif


    #if defined(__MTV_REC_SUPPORT__)
        case MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ:
            mtv_find_unsaved_recording_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ:
            mtv_recover_recording_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ:
            mtv_abort_recovering_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ:
            mtv_discard_unsaved_recording_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_START_REQ:
            mtv_recorder_start_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ:
            mtv_recorder_stop_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_PAUSE_REQ:
            mtv_recorder_pause_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_RESUME_REQ:
            mtv_recorder_resume_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ:
            mtv_recorder_save_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ:
            mtv_recorder_abort_saving_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ:
            mtv_recorder_discard_recording_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ:
            mtv_recorder_get_status_req_hdlr(ilm);
            break;
    #endif  // #if defined(__MTV_REC_SUPPORT__)

        case MSG_ID_MEDIA_MTV_SET_PARAM_REQ:
            mtv_set_param_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_GET_PARAM_REQ:
            mtv_get_param_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ:
            mtv_service_get_status_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ:
            mtv_stop_service_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_CLOSE_REQ:
            mtv_close_req_hdlr(ilm);
            break;

    #if defined(__MED_MTV_MOD__)
        case MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_DOWNLOAD_REQ:
            mtv_media_mtv_esg_download_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_ABORT_DOWNLOADING_REQ:
            mtv_media_mtv_esg_abort_downloading_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_OPEN_REQ:
            mtv_esg_open_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_CLOSE_REQ:
            mtv_esg_close_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_QUERY_REQ:
            mtv_esg_query_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_GET_RESULTS_REQ:
            mtv_esg_get_results_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_QUERY_FINISH_REQ:
            mtv_esg_query_finish_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_ADD_FAVORITE_REQ:
            mtv_esg_add_favorite_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_ESG_DEL_FAVORITE_REQ:
            mtv_esg_del_favorite_req_hdlr(ilm);
            break;

        case MSG_ID_MEDIA_MTV_CAS_GET_CARD_INFO_REQ:
            mtv_cas_get_card_info_req_hdlr(ilm);
            break;
    #endif  // #if defined(__MED_MTV_MOD__)
        default:
            break;
        }
    }
}

kal_bool mtv_init(task_indx_type task_indx)
{
    UNUSED(task_indx);

    mtv_init_global_context();
    mtv_init_service_manager();

#if defined(__CMMB_CAS_SMD_SUPPORT__) && defined(__MTK_TARGET__)
    cmmb_ca_os_nagra_init();
#endif

    return KAL_TRUE;
}

#if defined(__MED_MTV_MOD__)
void mtv_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    kal_uint32 task_index;

    kal_get_my_task_index(&task_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(task_index, current_ilm.dest_mod_id);

        mtv_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }
}

static kal_bool mtv_reset(task_indx_type task_indx)
{
    UNUSED(task_indx);

    return KAL_TRUE;
}

kal_bool mtv_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct mtv_handler_info =
    {
        mtv_task_main,    /* task entry function */
        mtv_init,         /* task initialization function */
        NULL,             /* task configuration function */
        mtv_reset,        /* task reset handler */
        NULL,             /* task termination handler */
    };

    *handle = (comptask_handler_struct*) &mtv_handler_info;
    return KAL_TRUE;
}
#endif // #if defined(__MED_MTV_MOD__)

#if defined(__CMMB_SUPPORT__)
/* ESG task */

void esg_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
    case MSG_ID_MEDIA_MTV_ASYNC_CALLBACK_REQ:
        mtv_async_callback_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_ESG_ADD_PARSE_COMMAND:
        cmmb_sp_esg_on_parse_command(ilm);
        break;
    }
}

static kal_bool esg_init(task_indx_type task_indx)
{
    UNUSED(task_indx);

    cmmb_esg_init();
    cmmb_esg_parser_init();

    return KAL_TRUE;
}

static kal_bool esg_reset(task_indx_type task_indx)
{
    UNUSED(task_indx);

    return KAL_TRUE;
}

void esg_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    kal_uint32 task_index;

    kal_get_my_task_index(&task_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(task_index, current_ilm.dest_mod_id);

        //mtv_main((void*)&current_ilm);
        esg_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }
}

kal_bool esg_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct esg_handler_info =
    {
        esg_task_main,    /* task entry function */
        esg_init,         /* task initialization function */
        NULL,             /* task configuration function */
        esg_reset,        /* task reset handler */
        NULL,             /* task termination handler */
    };

    *handle = (comptask_handler_struct*) &esg_handler_info;
    return KAL_TRUE;
}
#endif // #if defined(__CMMB_SUPPORT__)

#if defined(__CMMB_CAS_SMD_SUPPORT__) && defined(__MTK_TARGET__)
/* CAS task */
void cas_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
        case MSG_ID_MEDIA_MTV_CAS_TASK_START_REQ:
            mtv_cas_task_start_req_hdlr(ilm);
            break;

        default:
            break;
    }
}

void cas_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    kal_uint32 task_index;

    kal_get_my_task_index(&task_index);

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(task_index, current_ilm.dest_mod_id);

        cas_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }
}

static kal_bool cas_init(task_indx_type task_indx)
{
    UNUSED(task_indx);

    return KAL_TRUE;
}

static kal_bool cas_reset(task_indx_type task_indx)
{
    UNUSED(task_indx);

    return KAL_TRUE;
}

kal_bool cas_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct cas_handler_info =
    {
        cas_task_main,    /* task entry function */
        cas_init,         /* task initialization function */
        NULL,             /* task configuration function */
        cas_reset,        /* task reset handler */
        NULL,             /* task termination handler */
    };

    *handle = (comptask_handler_struct*) &cas_handler_info;
    return KAL_TRUE;
}
#endif

kal_bool mtv_is_audio_channel_available(void)
{
    mtv_context_t* ctx = &g_mtv_context;

    MTV_TRACE(TRACE_FUNC, MTV_TRC_IS_AUDIO_CHANNEL_ABALIABLE);

    if (ctx->state == MTV_STATE_OPENED)
    {
        if (ctx->sm.sc_tail != NULL)
        {
            mtv_service_context_t* head = ctx->sm.sc_tail->next;
            mtv_service_context_t* sc = head;

            do
            {
                if (sc->player)
                {
                    mtv_player_state_t player_state;

                    player_state = sc->player->get_state(sc->player);

                    if (player_state != MTV_PLAYER_STATE_STOPPED)
                    {
                        MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_FALSE, __LINE__);
                        return KAL_FALSE;
                    }
                }
            } while (sc != head);
        }
    }

    MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_TRUE, __LINE__);
    return KAL_TRUE;
}

kal_bool mtv_is_audio_record_resource_available(void)
{
#if defined(__MTV_REC_SUPPORT__)
    mtv_context_t* ctx = &g_mtv_context;

    MTV_TRACE(TRACE_FUNC, MTV_TRC_IS_AUDIO_CHANNEL_ABALIABLE);

    if (ctx->state == MTV_STATE_OPENED)
    {
        if (ctx->sm.sc_tail != NULL)
        {
            mtv_service_context_t* head = ctx->sm.sc_tail->next;
            mtv_service_context_t* sc = head;

            do
            {
                if (sc->recorder)
                {
                    mtv_recorder_state_t recorder_state;

                    recorder_state = sc->recorder->get_state(sc->recorder);

                    if (recorder_state == MTV_RECORDER_STATE_STARTED)
                    {
                        MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_FALSE, __LINE__);
                        return KAL_FALSE;
                    }
                }
            } while (sc != head);
        }
    }
#else
    MTV_TRACE(TRACE_FUNC, MTV_TRC_IS_AUDIO_CHANNEL_ABALIABLE);
#endif

    MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_TRUE, __LINE__);
    return KAL_TRUE;
}

#else /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */

kal_bool mtv_is_audio_channel_available(void)
{
    MTV_TRACE(TRACE_FUNC, MTV_TRC_IS_AUDIO_CHANNEL_ABALIABLE);

    MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_TRUE, __LINE__);

    return KAL_TRUE;
}

kal_bool mtv_is_audio_record_resource_available(void)
{
    MTV_TRACE(TRACE_FUNC, MTV_TRC_IS_AUDIO_CHANNEL_ABALIABLE);

    MTV_TRACE(TRACE_FUNC, MTV_TRC_RETURN, KAL_TRUE, __LINE__);

    return KAL_TRUE;
}

#endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */

