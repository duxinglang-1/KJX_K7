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
 *   mtv_sm.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"
#include "stack_timer.h"

#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)

#include "med_struct.h"
#include "med_trc.h"
#include "med_utility.h"

#include "mtv_sm.h"
#include "mtv_concealment.h"

#if defined(__MTK_TARGET__)
#include "SST_sla.h"
#endif

#include "kal_general_types.h"
#include "mtv_error.h"
#include "mtv_buffer_engine.h"
#include "kal_public_api.h"
#include "mtv_control.h"
#include "kal_trace.h"
#include "mtv_spi.h"
#include "mtv_codec.h"
#include "mtv_comm.h"
#include "mtv_player.h"
#include "mtv_recorder.h"
#include "mtv_src_stat.h"
#include "stack_config.h"
#include "fs_func.h"
#include "fs_type.h"
#include "mtv_custom.h"
#include "fs_errcode.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MEDMTV_ROCODE", rodata = "DYNAMIC_CODE_MEDMTV_RODATA"
#endif

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
mtv_result_t atv_sm_restart_chip(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id);
#endif

#define IS_ACCEPTABLE_QUALITY(q) (((q) <= MTV_SPI_RECEPTION_QUALITY_FAIR) ? 1 : 0)

#define RETURN_E(sid, err) \
    MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_ERROR, sid, err, __LINE__); \
    return err

#if defined(__MTV_REC_SUPPORT__)
static mtv_result_t sm_stop_recorder(mtv_sm_t* sm, kal_uint32 service_id);
static kal_wchar* mtv_get_be_dir(kal_wchar* record_dir);
#endif
static mtv_result_t sm_free_service_context_list(mtv_sm_t* sm);

/* unclosed BE list */

#if defined(__MTV_TS_SUPPORT__)
/**
  * @return whether the BE is pushed successfully.
  */
static kal_bool mtv_push_unclosed_be(mtv_unclosed_be_list_t* list, mtv_buffer_engine_t* be)
{
    kal_uint32 tail = list->tail;

    tail = ((tail + 1) & (MAX_UNCLOSED_BE - 1));
    if (tail == list->head)
    {
        return KAL_FALSE;
    }
    else
    {
        list->be[tail] = be;
        list->tail = tail;
        return KAL_TRUE;
    }
}

/**
  * @return the poped BE. NULL if the list is empty.
  */
static mtv_buffer_engine_t* mtv_pop_unclosed_be(mtv_unclosed_be_list_t* list)
{
    mtv_buffer_engine_t* be = NULL;
    kal_uint32 head = list->head;

    if (list->tail != head)
    {
        head = ((head + 1) & (MAX_UNCLOSED_BE - 1));
        be = list->be[head];
        list->head = head;
    }

    return be;
}

static void sm_close_buffer_engine_hdlr(void* param)
{
    mtv_result_t ret;
    mtv_unclosed_be_list_t* unclosed_be_list = (mtv_unclosed_be_list_t*) param;
    mtv_buffer_engine_t* be = mtv_pop_unclosed_be(unclosed_be_list);

    ASSERT(be != NULL);
    ret = be->close(be);
    ASSERT(ret >= 0);

    be->destroy(be);
}

static mtv_result_t sm_close_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc);
static mtv_result_t sm_close_unsaved_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_buffer_engine_discard_policy_t discard_policy, kal_bool async);
#endif //#if defined(__MTV_TS_SUPPORT__)

/* helper function for service callback */

static void sm_callback(mtv_sm_t* sm, mtv_service_event_t event, kal_uint32 event_param)
{
    mtv_service_callback_param_t param;

    param.sc = NULL;
    param.service_id = MTV_SERVICE_INVALID_ID;
    param.event = event;
    param.event_param = event_param;
    sm->service_callback(sm->service_callback_ctx, &param);
}

static void sm_callback_with_sc(mtv_sm_t* sm, mtv_service_context_t* sc, mtv_service_event_t event, kal_uint32 event_param, kal_uint32 session_id)
{
    mtv_service_callback_param_t param;

    param.sc = sc;
    param.service_id = MTV_SERVICE_INVALID_ID;
    param.event = event;
    param.event_param = event_param;
    param.session_id = session_id;
    sm->service_callback(sm->service_callback_ctx, &param);
}

static void sm_callback_with_id(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_event_t event, kal_uint32 event_param, kal_uint32 session_id)
{
    mtv_service_callback_param_t param;

    param.sc = NULL;
    param.service_id = service_id;
    param.event = event;
    param.event_param = event_param;
    param.session_id = session_id;
    sm->service_callback(sm->service_callback_ctx, &param);
}

/* service context private functions */

#if defined(__MTV_TS_SUPPORT__)
static mtv_result_t sc_timeshift_backoff(mtv_service_context_t* pthis, kal_int32 offset_ms)
{
    mtv_result_t ret;
    mtv_control_timeshift_t* ts = NULL;
    kal_uint32 delay;

    if (!pthis->be) {
        return MTV_S_FALSE;
    }

    ret = pthis->be->get_control(pthis->be, MTV_CONTROL_TIMESHIFT, (void**) &ts);
    ASSERT(ret >= 0 && ts);

    ret = ts->get_delay(ts, &delay);
    if (ret >= 0 && delay > 0 /* not in live mode */)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_TIMESHIFT_BACKOFF, offset_ms, delay);
        if (((kal_int64)delay + offset_ms) >= 0)
        {
            delay = delay + offset_ms;
        }
        else
        {
            delay = 0;
        }
        ret = ts->set_delay(ts, delay);
    }

    return ret;
}

static mtv_result_t sc_timeshift_jumpout_errorhole(mtv_service_context_t* pthis)
{
    kal_int32 offset_ms = -2000;
    mtv_result_t ret;

    //mtv_prompt_trace(TRACE_INFO, "[MTV][BE] sc_timeshift_jumpout_errorhole = %u ms", offset_ms);

    ret = sc_timeshift_backoff(pthis, offset_ms);

    return ret;
}
#endif //#if defined(__MTV_TS_SUPPORT__)

static kal_bool sc_is_player_started(mtv_service_context_t* sc)
{
    return (kal_bool)(sc->player && sc->player->get_state(sc->player) != MTV_PLAYER_STATE_STOPPED);
}

#if defined(__MTV_REC_SUPPORT__)
static mtv_recording_format_t sc_get_recording_format(mtv_service_context_t* sc)
{
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;
    mtv_recording_format_t rf;

    switch (sc->info.type)
    {
    case MTV_SPI_SERVICE_DIGITAL_TV:
        rf = MTV_RECORDING_FORMAT_MP4;
        break;

    case MTV_SPI_SERVICE_DIGITAL_RADIO: {

        kal_uint32 i;

        for (i = 0; i < sc->info.num_components; i++)
        {
            mtv_spi_component_info_t* comp = &sc->info.components[i];

            switch (comp->dec_config.codec)
            {
            case MTV_CODEC_DRA:
                return MTV_RECORDING_FORMAT_WAV;

            case MTV_CODEC_MUSICAM:
                return MTV_RECORDING_FORMAT_MP2;

            case MTV_CODEC_AAC:
            case MTV_CODEC_AAC_PLUS:
            case MTV_CODEC_AAC_PLUS_V2:
                return MTV_RECORDING_FORMAT_MP4;
            }
        }
        return MTV_RECORDING_FORMAT_INVALID;
        }

    case MTV_SPI_SERVICE_ANALOG_TV:
        if (sm->video_config.encode_format == MPL_RECORDER_FORMAT_MJPEG)
        {
            rf = MTV_RECORDING_FORMAT_AVI;
        }
        else
        {
            rf = MTV_RECORDING_FORMAT_3GP;
        }
        break;

    default:
        NOT_REACHED("Unsupported service type for recording!");
        rf = MTV_RECORDING_FORMAT_INVALID;
        break;
    }

	return rf;
}

    #if defined(__MED_MTV_MOD__)
        static kal_bool sc_is_recorder_started(mtv_service_context_t* sc)
        {
            kal_bool ret;

            ret = (sc->recorder && sc->recorder->get_state(sc->recorder) == MTV_RECORDER_STATE_STARTED) ? KAL_TRUE : KAL_FALSE;

            return ret;
        }
    #endif

#endif //#if defined(__MTV_REC_SUPPORT__)

static mtv_result_t sc_start_player(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    if (sc_is_player_started(sc)) {
        return MTV_S_FALSE;
    }
    else if (sc->player)
    {
        mtv_player_config_t cfg;

        cfg.info = &sc->info;
        cfg.client = &sc->player_client;
        cfg.audio_config = &sm->audio_config;
        cfg.video_config = &sm->video_config;

        #if defined(__MED_MTV_MOD__)
            cfg.audio_au_duration = &sc->audio_src_stat.au_duration;
            cfg.video_au_duration = &sc->video_src_stat.au_duration;
            #ifdef __CMMB_SUPPORT__
                cfg.min_buffer_ms = 2000;
            #else
                cfg.min_buffer_ms = 1000;
            #endif
        #endif  // #if defined(__MED_MTV_MOD__)

        return sc->player->start(sc->player, &cfg);
    }
    else {
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start player failed, no player", sc->info.id);
        return MTV_S_FALSE;
    }
}

static mtv_result_t sc_stop_player(mtv_service_context_t* sc, kal_uint32* buffered_ms)
{
    #if defined(__MTV_TS_SUPPORT__)
        if (buffered_ms) {
            *buffered_ms = 0;
        }
    #endif

    if (sc_is_player_started(sc))
    {
        #if defined(__MTV_TS_SUPPORT__)
            if (buffered_ms) {
                *buffered_ms = sc->player->get_buffer_duration(sc->player);
            }
        #endif

        return sc->player->stop(sc->player);
    }

    return MTV_S_FALSE;
}

#if defined(__MED_MTV_MOD__)
static mtv_result_t sc_player_resume_visual_update(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    mtv_player_config_t cfg;

    ASSERT(sc->player);

    cfg.info = &sc->info;
    cfg.client = &sc->player_client;
    cfg.audio_config = &sm->audio_config;
    cfg.video_config = &sm->video_config;
    cfg.audio_au_duration = &sc->audio_src_stat.au_duration;
    cfg.video_au_duration = &sc->video_src_stat.au_duration;
    #ifdef __CMMB_SUPPORT__
        cfg.min_buffer_ms = 2000;
    #else
        cfg.min_buffer_ms = 1000;
    #endif

    return sc->player->resume_visual_update(sc->player, &cfg);
}

static mtv_result_t sc_player_pause_visual_update(mtv_service_context_t* sc)
{
    return sc->player->pause_visual_update(sc->player);
}
#endif  // #if defined(__MED_MTV_MOD__)


typedef enum
{
    SC_NO_ACTION = 0x0,
    SC_RESET_PLAY_RATE = 0x01,
    SC_TIMESHIFT_BACKOFF = 0x02

} sc_restart_action_t;

static mtv_result_t sc_restart_player(mtv_sm_t* sm, mtv_service_context_t* sc, kal_uint32 other_actions)
{
    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_RESTART_PLAYER, sc->info.id, other_actions);

    #if defined(__MTV_TS_SUPPORT__)
        if (other_actions & SC_RESET_PLAY_RATE)
        {
            mtv_control_trick_mode_t* tm = NULL;
            mtv_result_t ret;

            if (!sc->player) {
                return MTV_S_FALSE;
            }

            ret = sc->player->get_control(sc->player, MTV_CONTROL_TRICK_MODE, (void**) &tm);
            if (tm) {
                ret = tm->set_rate(tm, 1000);
            }

            if (ret == MTV_S_OK)
            {
                /* after the rate is applied, the player will restart internally. */
                return MTV_S_OK;
            }
        }
    #endif // #if defined(__MTV_TS_SUPPORT__)

    if (sc_is_player_started(sc))
    {
        #if defined(__MTV_TS_SUPPORT__)
            kal_uint32 buffered_ms;

            /* we have to stop the player to release decoder resource */
            sc_stop_player(sc, &buffered_ms);

            if ((other_actions & SC_TIMESHIFT_BACKOFF) != 0 && buffered_ms > 0)
            {
                /*
                 * backoff timeshift position when restarting player; otherwise, buffered content in player will be
                 * flushed when resuming playback.
                 */
                sc_timeshift_backoff(sc, buffered_ms);
            }
        #else
            sc_stop_player(sc, NULL);
        #endif // #if defined(__MTV_TS_SUPPORT__)

        return sc_start_player(sm, sc);
    }

    return MTV_S_OK;
}

static mtv_result_t sc_player_snapshot(mtv_service_context_t* sc, void* param)
{
    mtv_result_t ret;

    if (sc_is_player_started(sc))
    {
        ret = sc->player->snapshot(sc->player, param);
    }
    else
    {
        /* player must in playing when snapshot! */
        ret = MTV_E_WRONG_STATE;
    }

    return ret;
}

#if defined(__MTV_REC_SUPPORT__)
static mtv_result_t sc_start_recorder(mtv_service_context_t* sc, const kal_wchar* service_name)
{
    mtv_result_t ret;
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;
    mtv_recording_format_t rf;
    kal_wchar* storing_dir;

#if defined(__MTV_TS_SUPPORT__)
    /* discard unsaved content */
    ret = sm_close_unsaved_buffer_engine(sm, sc, MTV_BE_DISCARD_FILES_AFTER_CLOSE, KAL_TRUE);

    if (sm->mode != MEDIA_MTV_OPEN_MODE_ATV &&
        sc->be == NULL)
    {
        /* The current recording implementation depends on buffer engine. */
        RETURN_E(sc->info.id, MTV_E_FAIL);
    }
#endif

    rf = sc_get_recording_format(sc);
    if (rf == MTV_RECORDING_FORMAT_INVALID) {
        RETURN_E(sc->info.id, MTV_E_INVALID_PARAM);
    }

    storing_dir = mtv_get_be_dir(sm->record_config.record_dir);

#if defined(__MTV_TS_SUPPORT__)
    if (service_name)
    {
        ret = sc->recorder->start(sc->recorder, sc->be, &sc->recorder_client, storing_dir, service_name, rf);
    }
    else
    {
        ret = sc->recorder->start(sc->recorder, sc->be, &sc->recorder_client, storing_dir, sc->info.name, rf);
    }
#else
    if (service_name)
    {
        ret = sc->recorder->start(sc->recorder, NULL, &sc->recorder_client, storing_dir, service_name, rf);
    }
    else
    {
        ret = sc->recorder->start(sc->recorder, NULL, &sc->recorder_client, storing_dir, sc->info.name, rf);
    }
#endif

    mtv_free_ext_mem((void**) &storing_dir);

    if (ret >= 0)
    {
        #if defined(__MTV_TS_SUPPORT__)
            /* save a checkpoint immediately after start the recording */
            sc->recorder->save_checkpoint(sc->recorder, sc->be->storing_dir);
        #endif

        /* The client has requested to start recording explicitly. */
        sc->activities |= MEDIA_MTV_SERVICE_ACTIVITY_RECORD;
    }

    return ret;
}
#endif //#if defined(__MTV_REC_SUPPORT__)


/* time-shift timer */

#if defined(__MTK_TARGET__)
  #define MTV_TIMESHIFT_TIMER_INTERVAL  (KAL_TICKS_1_SEC/16)
  #define MTV_MAX_DISPATCHED_BYTES      (16 * 1024)
#else
  #define MTV_TIMESHIFT_TIMER_INTERVAL  (KAL_TICKS_1_SEC)
  #define MTV_MAX_DISPATCHED_BYTES      (64 * 1024)
#endif /* defined(__MTK_TARGET__) */

#if defined(__MTV_TS_SUPPORT__)
static mtv_result_t sc_enter_live_mode(mtv_service_context_t* pthis)
{
    mtv_result_t ret;
    mtv_control_timeshift_t* ts = NULL;

    /* switch back to live broadcasting */
    ret = pthis->be->get_control(pthis->be, MTV_CONTROL_TIMESHIFT, (void**) &ts);
    ASSERT(ret >= 0 && ts);
    ret = ts->set_delay(ts, 0);

    /* cannot restart player in this function otherwise prebuffering won't work */

    return MTV_S_OK;
}

static void sm_process_timeshift_timer(void* param);

static void sc_stop_timeshift_timer(void)
{
    mtv_stop_timeshift_timer();
}

static void sc_start_timeshift_timer(mtv_service_context_t* sc, kal_uint32 interval, kal_uint32 dispatch_flags)
{
    sc_stop_timeshift_timer();

    sc->dispatch_flags = dispatch_flags;
    mtv_start_timeshift_timer(interval, sm_process_timeshift_timer, sc);
}

/* time-shift packet dispatching */

typedef enum
{
    UNTIL_BUFFER_IS_DRAINED    = 0x01,
    UNTIL_HIGH_BUFFER_LEVEL    = 0x02,
    UNTIL_MAX_DISPATCHED_BYTES = 0x04,
    UNTIL_COMMAND_INTERRUPT    = 0x08,
    UNTIL_DELIVERY_ERROR       = 0x10,
    USES_STREAM_TIME           = 0x20

} dispatch_packets_flags;

static dispatch_packets_flags sc_packet_dispatching_loop(mtv_service_context_t* pthis, kal_uint32 dispatch_flags)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_packet_t au;
    kal_uint32 stream_index;
    kal_uint32 dispatched_packets = 0;
    kal_uint32 dispatched_bytes = 0;
    mtv_player_t* player = pthis->player;
    mtv_player_buffer_level_t aud_buf_level, vid_buf_level;

#define EXIT_DISPATCH(flags) \
    MTV_TRACE(TRACE_INFO, MTV_TRC_SERVICE_PACKET_DISPATCHED, dispatched_packets); \
    return flags;

    for (;;)
    {
        if (dispatch_flags & UNTIL_COMMAND_INTERRUPT)
        {
            if (mtv_check_pending_requests()) {
                EXIT_DISPATCH(UNTIL_COMMAND_INTERRUPT);
            }
        }

        vid_buf_level = player->get_buffer_level(player, MTV_STREAM_VIDEO);
        aud_buf_level = player->get_buffer_level(player, MTV_STREAM_AUDIO);

        if (dispatch_flags & UNTIL_HIGH_BUFFER_LEVEL)
        {
            /* stop dispatching if either one of audio and video stream has high buffer level */
            if (vid_buf_level >= MTV_PLAYER_BUFFER_LEVEL_HIGH || aud_buf_level >= MTV_PLAYER_BUFFER_LEVEL_HIGH)
            {
                if ((vid_buf_level >= MTV_PLAYER_BUFFER_LEVEL_HIGH && aud_buf_level <= MTV_PLAYER_BUFFER_LEVEL_LOW) ||
                    (aud_buf_level >= MTV_PLAYER_BUFFER_LEVEL_HIGH && vid_buf_level <= MTV_PLAYER_BUFFER_LEVEL_LOW))
                {
                    /* error found in bitstream, try another seek point */
                    sc_timeshift_jumpout_errorhole(pthis);
                }
                EXIT_DISPATCH(UNTIL_HIGH_BUFFER_LEVEL);
            }
        }

        /* try to keep certain amount of data buffered */
        if (vid_buf_level > MTV_PLAYER_BUFFER_LEVEL_LOW && aud_buf_level > MTV_PLAYER_BUFFER_LEVEL_LOW)
        {
            if (dispatch_flags & UNTIL_MAX_DISPATCHED_BYTES)
            {
                /* stop when maximum number of bytes has dispatched */
                if (dispatched_bytes >= MTV_MAX_DISPATCHED_BYTES)
                {
                    EXIT_DISPATCH(UNTIL_MAX_DISPATCHED_BYTES);
                }
            }
        }

        ret = pthis->be->read_packet(pthis->be, &stream_index, &au);
        if (ret >= 0)
        {
            dispatched_packets++;
            dispatched_bytes += au.size;

            if (stream_index == pthis->be_audio_stream)
            {
                if (dispatch_flags & USES_STREAM_TIME) {
                    pthis->be->translate_to_stream_time(pthis->be, stream_index, &pthis->audio_src_stat, &au.timestamp);
                }

                ret = player->deliver_au(player, MTV_STREAM_AUDIO, &au);
            }
            else if (stream_index == pthis->be_video_stream)
            {
                if (dispatch_flags & USES_STREAM_TIME) {
                    pthis->be->translate_to_stream_time(pthis->be, stream_index, &pthis->video_src_stat, &au.timestamp);
                }

                ret = player->deliver_au(player, MTV_STREAM_VIDEO, &au);
            }

            if (ret < 0) {
                EXIT_DISPATCH(UNTIL_DELIVERY_ERROR); /* exit loop if failed to deliver packets */
            }
        }
        else /* reach end of content */
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_SERVICE_BUFFER_DRAINED);

            sc_enter_live_mode(pthis);

            EXIT_DISPATCH(UNTIL_BUFFER_IS_DRAINED);
        }
    }
}

static mtv_result_t sc_start_from_beginning_of_content(mtv_service_context_t* pthis)
{
    mtv_result_t ret;
    mtv_sm_t* sm = (mtv_sm_t*) pthis->owner;

    /* notify we have reached the beginning of content */
    sm_callback_with_sc(sm, pthis, MTV_SERVICE_EVENT_PLAYER_BEGINNING_OF_CONTENT, 0, pthis->player_client.session_id);

    ret = sc_restart_player(sm, pthis, SC_RESET_PLAY_RATE);

    return ret;
}

/**
  * @param drain_buffer [in] dispatch packets until the buffer is drained
  */
static mtv_result_t sc_dispatch_packets(mtv_service_context_t* pthis, kal_uint32 dispatch_flags)
{
    dispatch_packets_flags until_what;

    ASSERT(pthis->be != NULL);

	if (!sc_is_player_started(pthis))
    {
        /* Because the player may get started by the client later, we need to check it periodically. */
        sc_start_timeshift_timer(pthis, MTV_TIMESHIFT_TIMER_INTERVAL, dispatch_flags);
		return MTV_S_FALSE;
	}

    until_what = sc_packet_dispatching_loop(pthis, dispatch_flags);
    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_DISPATCH_STOPPED, pthis->info.id, until_what);
    if (until_what == UNTIL_MAX_DISPATCHED_BYTES || until_what == UNTIL_COMMAND_INTERRUPT || until_what == UNTIL_DELIVERY_ERROR)
    {
        /* start a short timer so that packets can be dispatched soon */
        sc_start_timeshift_timer(pthis, MTV_TIMESHIFT_TIMER_INTERVAL, dispatch_flags | UNTIL_MAX_DISPATCHED_BYTES);
    }
    else if (until_what == UNTIL_HIGH_BUFFER_LEVEL)
    {
        /*
         * - add UNTIL_MAX_DISPATCHED_BYTES because the buffer level is already high
         * - start a longer timer because the buffer level is high
         */
        sc_start_timeshift_timer(pthis, KAL_TICKS_1_SEC/2, dispatch_flags | UNTIL_MAX_DISPATCHED_BYTES);
    }

    return MTV_S_OK;
}

static void sm_process_timeshift_timer(void* param)
{
    mtv_service_context_t* sc = (mtv_service_context_t*) param;

    if (sc != NULL)
    {
        sc_dispatch_packets(sc, sc->dispatch_flags);
    }
}

static void sc_be_on_read_state_change(
    mtv_buffer_engine_client_t* client,
    mtv_buffer_engine_read_state_t old_state,
    mtv_buffer_engine_read_state_t new_state)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, be_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    ASSERT(old_state != new_state);

    switch (old_state)
    {
    case MTV_BE_READ_DELAYED:
    case MTV_BE_READ_PREBUFFERING:

        /* stop active timeshift timer */
        sc_stop_timeshift_timer();
        break;

    case MTV_BE_READ_PAUSED:

        if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0)
        {
            if (new_state == MTV_BE_READ_DELAYED || new_state == MTV_BE_READ_PREBUFFERING)
            {
                /* resume the playback automatically during PAUSED -> DELAYED or PREBUFFERING */
                sc_start_player(sm, sc);
            }
        }
        break;
    }

    switch (new_state)
    {
    case MTV_BE_READ_PREBUFFERING:

        if (sc_is_player_started(sc))
        {
            /* drain stream buffer and then enter LIVE mode */
            sc_dispatch_packets(sc, UNTIL_BUFFER_IS_DRAINED | UNTIL_COMMAND_INTERRUPT | USES_STREAM_TIME);
        }
        else
        {
            /* enter LIVE mode directly without prebuffering */
            sc_enter_live_mode(sc);
        }
        break;

    case MTV_BE_READ_LIVE:

        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_LIVE, MTV_S_OK, sc->player_client.session_id);
        break;

    case MTV_BE_READ_PAUSED: {

        kal_uint32 buffered_ms;

        /* we have to stop the player to release decoder resource */
        sc_stop_player(sc, &buffered_ms);
        if (buffered_ms > 0)
        {
            /*
             * backoff timeshift position when paused; otherwise, buffered content in player will be
             * flushed when resuming playback.
             */
            sc_timeshift_backoff(sc, buffered_ms);
        }

        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_PAUSED, MTV_S_OK, sc->player_client.session_id);
        break;
        }

    case MTV_BE_READ_DELAYED:

        /* send delay notification first because packet dispatching may change read state later */
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_DELAYED, MTV_S_OK, sc->player_client.session_id);

#if defined(__MTK_TARGET__)
        /* start a timer to dispatch packets in time-shift buffer */
        sc_dispatch_packets(sc, UNTIL_HIGH_BUFFER_LEVEL | UNTIL_COMMAND_INTERRUPT);
#else
        sc_dispatch_packets(sc, UNTIL_MAX_DISPATCHED_BYTES | UNTIL_COMMAND_INTERRUPT);
#endif
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }
}

static void sc_be_on_read_seek(mtv_buffer_engine_client_t* client, kal_uint32 target_time, kal_uint32 delay_ms)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, be_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    UNUSED(target_time);

    if (delay_ms == MTV_TIMESHIFT_DELAY_MAX)
    {
        /* need special handling for BOC */
        sc_start_from_beginning_of_content(sc);
    }
    else if (delay_ms == 0)
    {
        /* send EOC */
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_END_OF_CONTENT, 0, sc->player_client.session_id);

        sc_restart_player(sm, sc, SC_RESET_PLAY_RATE);
    }
    else
    {
        /* when seeking, to flush the buffer and start */
        sc_restart_player(sm, sc, SC_NO_ACTION);
    }
}
#endif // #if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
static void sc_player_on_audio_error(mtv_player_client_t* client, kal_int32 error)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    UNUSED(error);

    sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_ERROR, (kal_uint32) MTV_DEC_E_AUDIO, sc->player_client.session_id);
}

static void sc_player_on_video_error(mtv_player_client_t* client, kal_int32 error)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    MTV_TRACE(TRACE_ERROR, MTV_TRC_VIDEO_ERROR, error);

    sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_ERROR, (kal_uint32) MTV_DEC_E_VIDEO, sc->player_client.session_id);
}

static void sc_player_on_rate_change(mtv_player_client_t* client, kal_int32 new_rate)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_RATE_CHANGE, (kal_uint32) new_rate, sc->player_client.session_id);
}

static void sc_player_on_restart(mtv_player_client_t* client)
{
    UNUSED(client);
}

#endif // #if defined(__MED_MTV_MOD__)

static void sc_player_on_state_change(mtv_player_client_t* client, mtv_player_state_t state, mtv_result_t reason)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    switch (state)
    {
    case MTV_PLAYER_STATE_STOPPED:
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_STOPPED, reason, sc->player_client.session_id);
        break;

    case MTV_PLAYER_STATE_INITED:
        break;

    case MTV_PLAYER_STATE_STARTED:

        if (sc->player_started++ == 0)
        {
            kal_uint32 now;
            kal_uint32 zapping_time;

            kal_get_time(&now);
            zapping_time = now - sc->start_service_time;

            MTV_TRACE(TRACE_INFO, MTV_TRC_SM_ZAPPING_TIME, sc->info.id, kal_ticks_to_milli_secs(zapping_time));
        }

        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_PLAYER_STARTED, reason, sc->player_client.session_id);
        break;

    default:
        NOT_REACHED("Unhandled player state?!");
        break;
    }
}

#if defined(__MTV_REC_SUPPORT__)
static void sc_recorder_on_state_change(mtv_recorder_client_t* client, mtv_recorder_state_t state)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, recorder_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    switch (state)
    {
    case MTV_RECORDER_STATE_STOPPED:
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_STOPPED, MTV_S_OK, sc->recorder_client.session_id);
        break;

    case MTV_RECORDER_STATE_STARTED:
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_STARTED, MTV_S_OK, sc->recorder_client.session_id);
        break;

    case MTV_RECORDER_STATE_SAVING:
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING, MTV_S_OK, sc->recorder_client.session_id);
        break;

    default:
        NOT_REACHED("Unhandled recorder state?!");
        break;
    }
}

/* currently used by ATV only */
static void sc_recorder_on_error(mtv_recorder_client_t* client, mtv_result_t result)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, recorder_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    //MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, result, __LINE__);

    sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_ERROR, result, sc->recorder_client.session_id);
}

static void sc_recorder_on_save(mtv_recorder_client_t* client, mtv_result_t result)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, recorder_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    if (result >= 0)
    {
        #if defined(__MTV_TS_SUPPORT__)
            if (sc->unsaved_be)
            {
                sc->unsaved_be->destroy(sc->unsaved_be);
            }
        #endif
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED, result, sc->recorder_client.session_id);
    }
    else
    {
        sm_callback_with_sc(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED, result, sc->recorder_client.session_id);
    }
}
#endif // #if defined(__MTV_REC_SUPPORT__)

#if defined(__MED_MTV_MOD__)
static void sc_init_src_stat(mtv_service_context_t* pthis)
{
    kal_int32 i;

    /* initialize primary audio first */
    for (i = 0; i < ARRAY_SIZE(pthis->info.components); i++)
    {
        mtv_spi_component_info_t* comp = &pthis->info.components[i];

        if ((comp->type == MTV_SPI_COMPONENT_AUDIO) && ((comp->flags & MTV_SPI_COMPONENT_PRIMARY) != 0))
        {
            pthis->audio_comp = comp;

            mtv_source_stat_init(
                &pthis->audio_src_stat,
                comp->dec_config.timestamp_resolution * mtv_dec_config_get_audio_samples_per_frame(&comp->dec_config) / mtv_dec_config_get_audio_sample_rate(&comp->dec_config),
                MAKE_FOURCC('S','C','S','A'));
            break;
        }
    }

    for (i = 0; i < ARRAY_SIZE(pthis->info.components); i++)
    {
        mtv_spi_component_info_t* comp = &pthis->info.components[i];

        if ((comp->type == MTV_SPI_COMPONENT_VIDEO) && ((comp->flags & MTV_SPI_COMPONENT_PRIMARY) != 0))
        {
            pthis->video_comp = comp;

            mtv_source_stat_init(&pthis->video_src_stat, 0, MAKE_FOURCC('S','C','S','V'));
            break;
        }
    }

    pthis->av_offset_compensated = KAL_FALSE;
}

static mtv_service_context_t* sm_find_service_by_state(mtv_sm_t* pthis, mtv_service_state_t state)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sc->state == state) {
                return sc;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return NULL;
}
#endif // #if defined(__MED_MTV_MOD__)

/* service manager private functions */

static kal_bool sm_is_service_started(mtv_service_context_t* sc)
{
	return (kal_bool)(sc->state > MTV_SERVICE_STATE_STOPPED);
}

static mtv_service_context_t* sm_find_service_by_id(mtv_sm_t* pthis, kal_uint32 service_id)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sc->info.id == service_id) {
                return sc;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return NULL;
}

static mtv_service_context_t* sm_find_service_by_activities(mtv_sm_t* pthis, kal_uint32 activities)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if ((activities & sc->activities) != 0) {
                return sc;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return NULL;
}

static mtv_service_context_t* sm_find_service_by_index(mtv_sm_t* pthis, kal_uint32 index)
{
    kal_int32 i = 0;

    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (i == index) {
                return sc;
            }
            sc = sc->next;
            i++;
        } while (sc != head);
    }

    return NULL;
}

static kal_bool sm_is_any_service_started(mtv_sm_t* pthis)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sm_is_service_started(sc)) {
                return KAL_TRUE;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return KAL_FALSE;
}

static mtv_service_context_t* sm_alloc_service_context(mtv_sm_t* pthis)
{
    mtv_service_context_t* sc = mtv_alloc_ext_mem(sizeof(mtv_service_context_t), MAKE_FOURCC('S','C','T','X'));
    ASSERT(sc != NULL);
    kal_mem_set(sc, 0, sizeof(*sc));

    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        pthis->sc_tail->next = sc;
        sc->next = head;
    }
    else {
        sc->next = sc;
    }
    pthis->sc_tail = sc;

    return sc;
}

static mtv_service_context_t* sm_add_service_context(mtv_sm_t* pthis, mtv_spi_service_info_t* info)
{
    mtv_service_context_t* sc;

    ASSERT(info != NULL);

    if (sm_find_service_by_id(pthis, info->id) != NULL)
    {
        /*
         * For EVB without good shielding, it is possible that the
         * receiver will detect duplicate services. Just ignore it.
         */
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_ERROR, info->id, MTV_E_INVALID_PARAM, __LINE__);
        return NULL;
    }

    sc = sm_alloc_service_context(pthis);  /* create new service context */
    if (!sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_ERROR, info->id, MTV_E_FAIL, __LINE__);
        return NULL;
    }

    kal_mem_cpy(&sc->info, info, sizeof(sc->info));
    return sc;
}

static kal_bool sm_remove_service_context(mtv_sm_t* pthis, kal_uint32 service_id)
{
    if (pthis->sc_tail != NULL);
    {
        mtv_service_context_t* prev = pthis->sc_tail;
        mtv_service_context_t* curr = prev->next;
        mtv_service_context_t* head = curr;

        do
        {
            if (curr->info.id == service_id)
            {
                prev->next = curr->next;
                if (curr == pthis->sc_tail)
                {
                    if (prev == pthis->sc_tail) {
                        pthis->sc_tail = NULL;
                    }
                    else {
                        pthis->sc_tail = prev;
                    }
                }
                mtv_free_ext_mem((void**)&curr);
                return KAL_TRUE;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    return KAL_FALSE;
}

static mtv_service_context_t* sm_update_service_context(mtv_sm_t* pthis, mtv_spi_service_info_t* info)
{
    mtv_service_context_t* sc;

    ASSERT(info != NULL);

    sc = sm_find_service_by_id(pthis, info->id);
    if (sc != NULL)
    {
        kal_mem_cpy(&sc->info, info, sizeof(sc->info));
    }

    return sc;
}

static mtv_service_context_t* sm_set_service_started(mtv_sm_t* pthis, mtv_service_context_t* started_service_context, kal_uint32 activities, kal_uint32 session_id)
{
    mtv_service_context_t* tail = pthis->sc_tail;
    if (tail != NULL)
    {
        mtv_service_context_t* head = tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sc->next == started_service_context)
            {
                /* adjust tail pointer so that new started service can be found quickly */
                pthis->sc_tail = sc;
                break;
            }
            sc = sc->next;
        } while (sc != head);
    }

    started_service_context->state = MTV_SERVICE_STATE_STARTED;
    started_service_context->reception_state = MTV_RECEPTION_STATE_GOOD;
    started_service_context->activities = activities;
    started_service_context->owner = (kal_uint32) pthis;
    started_service_context->session_id = session_id;
    #if defined(__MTV_REC_SUPPORT__)
        started_service_context->saving_aborted = KAL_FALSE;
    #endif
    #if defined(__MED_MTV_MOD__)
        started_service_context->ca_state = MTV_SERVICE_CA_STATE_ACCESS_GRANTED;
        started_service_context->av_offset_compensated = KAL_FALSE;
    #endif
    started_service_context->player_started = 0;

    return started_service_context;
}

static mtv_service_context_t* sm_set_service_stopped(mtv_service_context_t* sc)
{
    sc->state = MTV_SERVICE_STATE_STOPPED;
    sc->owner = 0;
    sc->activities = 0;

    return sc;
}

/* mtv_sm_t public interface */

static mtv_result_t sm_open(mtv_sm_t* sm, media_mtv_mode_enum mode, kal_uint16 app_id, void *param, mtv_service_callback_t cb, void* context)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_OPEN);

    pthis->sc_tail = NULL;
    pthis->spi = NULL;
    pthis->app_id = app_id;

    kal_mem_set(&pthis->audio_config, 0, sizeof(pthis->audio_config));
    kal_mem_set(&pthis->video_config, 0, sizeof(pthis->video_config));
#if defined(__MTV_REC_SUPPORT__)
    kal_mem_set(&pthis->record_config, 0, sizeof(pthis->record_config));
#endif // #if defined(__MTV_REC_SUPPORT__)

    if (mode == MEDIA_MTV_OPEN_MODE_CMMB)
    {
#if defined(__CMMB_SUPPORT__)
        pthis->spi = construct_cmmb_sp();
#endif
    }
    else if (mode == MEDIA_MTV_OPEN_MODE_TDMB)
    {
#if defined(__TDMB_SUPPORT__)
      	pthis->spi = construct_tdmb_sp();
#endif
    }
    else if (mode == MEDIA_MTV_OPEN_MODE_ATV)
    {
#if defined(__ATV_SUPPORT__)
    #if defined(__ATV_CAMERA_SIM_SUPPORT__)
        if (g_mtv_atv_sim == KAL_TRUE)
        {
           	pthis->spi = construct_camera_sp();
        }
        else
    #endif  // #if defined(__ATV_CAMERA_SIM_SUPPORT__)
        {
            pthis->spi = construct_atv_sp();
        }
#endif
    }

    /* not supported standard */
    if (pthis->spi == NULL)
    {
        return MTV_E_FAIL;
    }

    /* open mode */
    pthis->mode = mode;

    /* open the service provider */
    ret = pthis->spi->open(pthis->spi, &pthis->spi_client, param);
    if (ret >= 0)
    {
        pthis->service_callback = cb;
        pthis->service_callback_ctx = context;
        #if defined(__MED_MTV_MOD__)
            pthis->esg_qe_state = MTV_ESG_QUERY_STATE_OPENED;
        #endif // #if defined(__MED_MTV_MOD__)
    }
    else
    {
        pthis->spi->destroy(pthis->spi);
        pthis->spi = NULL;
    }

    #if defined(__MED_MTV_MOD__)
        pthis->drop_packets = KAL_FALSE;
    #endif // #if defined(__MED_MTV_MOD__)

    pthis->rq.quality = MTV_SPI_RECEPTION_QUALITY_FAIR;
    pthis->rq.stable = 2;

    return ret;
}

static mtv_result_t sm_config(mtv_sm_t* sm, media_config_audio_struct* audio, media_config_video_struct* video, media_mtv_config_record_struct* record)
{
    mtv_sm_t* pthis = sm;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_CONFIG);

    /* TODO: check validility of specified configurations */

    if (audio != NULL) {
        kal_mem_cpy(&pthis->audio_config, audio, sizeof(pthis->audio_config));
    }
    if (video != NULL) {
        kal_mem_cpy(&pthis->video_config, video, sizeof(pthis->video_config));
    }

    /* recorder setting. */
    #if defined(__MTV_REC_SUPPORT__)
        if (record != NULL)
        {
            mtv_free_ext_mem((void**)&pthis->record_config.record_dir);

            kal_mem_cpy(&pthis->record_config, record, sizeof(pthis->record_config));
            if (record->record_dir != NULL) {
                pthis->record_config.record_dir = mtv_str_dup(record->record_dir, kal_wstrlen(record->record_dir) + 1, MAKE_FOURCC('F','L','N','M'));
            }
        }
    #endif

    return MTV_S_OK;
}

#if defined(__MTV_REC_SUPPORT__)
static kal_wchar* mtv_get_be_dir(kal_wchar* record_dir)
{
    kal_wchar* be_dir = mtv_alloc_filename();

    kal_wstrncpy(be_dir, record_dir, MAX_FILE_NAME_LEN - 1);
    kal_wstrcpy(be_dir + 3, L"@mtv\\");  /* keep the "X:\\" prefix */

    if (FS_GetAttributes(be_dir) < 0) {
        FS_CreateDir(be_dir);
    }
    #ifndef __LOW_COST_SUPPORT_ULC__
        FS_SetAttributes(be_dir, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    #endif

    return be_dir;
}

static mtv_result_t sm_find_unsaved_recording(mtv_sm_t* sm, kal_bool* found)
{
    mtv_sm_t* pthis = sm;

    if (pthis->record_config.record_dir == NULL) {
        *found = KAL_FALSE;
    }
    else
    {
        kal_wchar* be_dir = mtv_get_be_dir(pthis->record_config.record_dir);

        *found = mtv_recorder_find_checkpoints(pthis->app_id, be_dir);

        mtv_free_ext_mem((void**) &be_dir);
    }

    return MTV_S_OK;
}

static mtv_result_t sm_recover_recording(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    kal_wchar* be_dir;

    if (pthis->record_config.record_dir == NULL) {
        return MTV_E_FAIL;
    }

    be_dir = mtv_get_be_dir(pthis->record_config.record_dir);

    pthis->recovering_aborted = KAL_FALSE;

    ret = mtv_recorder_recover_recording(pthis->app_id, be_dir, pthis->record_config.record_dir, &pthis->recovering_aborted);

    mtv_free_ext_mem((void**) &be_dir);

    return ret;
}

static mtv_result_t sm_abort_recovering(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    pthis->recovering_aborted = KAL_TRUE;
    return MTV_S_OK;
}

static mtv_result_t sm_discard_unsaved_recording(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    if (pthis->record_config.record_dir != NULL)
    {
        kal_wchar* be_dir = mtv_get_be_dir(pthis->record_config.record_dir);

        mtv_recorder_discard_unsaved_recording(pthis->app_id, be_dir);

        mtv_free_ext_mem((void**) &be_dir);
    }

    return MTV_S_OK;
}
#endif // #if defined(__MTV_REC_SUPPORT__)

static mtv_result_t sm_abort_searching(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_ABORT_SEARCHING);

    return pthis->spi->abort_searching(pthis->spi);
}

static mtv_result_t sm_check_service_activities(mtv_sm_t* sm, mtv_service_context_t* sc, kal_uint32 activities)
{
    mtv_sm_t* pthis = sm;

    if ((activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0 &&      /* to turn it ON */
        (sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) == 0)    /* it is not ON yet */
    {
        if (
            #if defined(__MED_MTV_MOD__)
            sc->info.type != MTV_SPI_SERVICE_DIGITAL_RADIO &&
            sc->info.type != MTV_SPI_SERVICE_DIGITAL_TV &&
            #endif
            sc->info.type != MTV_SPI_SERVICE_ANALOG_TV)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_NOT_PLAYABLE, sc->info.id);
            return MTV_E_INVALID_PARAM;
        }

        if (sm_find_service_by_activities(pthis, MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != NULL)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_PLAYING_ALREADY, sc->info.id);
            return MTV_E_RESOURCE_CONFLICT;
        }
    }
    else if ((activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) != 0 &&
             (sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) == 0)
    {
        #if defined(__MTV_REC_SUPPORT__)
            if (sc->info.type != MTV_SPI_SERVICE_DIGITAL_RADIO &&
                sc->info.type != MTV_SPI_SERVICE_DIGITAL_TV &&
                sc->info.type != MTV_SPI_SERVICE_ANALOG_TV)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_NOT_RECORDABLE, sc->info.id);
                return MTV_E_INVALID_PARAM;
            }

            if (sm_find_service_by_activities(pthis, MEDIA_MTV_SERVICE_ACTIVITY_RECORD) != NULL)
            {
                /* OK to continue because multiple-service-receiving is supported */
            }
        #else
            MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_NOT_RECORDABLE, sc->info.id);
            return MTV_E_INVALID_PARAM;
        #endif
    }

    return MTV_S_OK;
}

static mtv_result_t sm_get_stream_info(mtv_stream_info_t* st, mtv_dec_config_t* dec_config)
{
    st->dec_config = *dec_config;

#if defined(__MED_MTV_MOD__)
    if (dec_config->codec == MTV_CODEC_BSAC ||
        dec_config->codec == MTV_CODEC_AAC ||
        dec_config->codec == MTV_CODEC_AAC_PLUS ||
        dec_config->codec == MTV_CODEC_AAC_PLUS_V2)
    {
        mtv_m4a_dec_config_t* m4a_dec_config = &dec_config->u.m4a;

        st->type = MTV_STREAM_AUDIO;
        st->format.audio.bits_per_sample = 16;
        ASSERT(m4a_dec_config->channel_configuration <= 6);
        st->format.audio.channels = m4a_dec_config->channel_configuration;
        st->format.audio.sample_rate = mp4a_get_sample_rate_from_index(m4a_dec_config->sampling_frequency_index);
    }
    else if (dec_config->codec == MTV_CODEC_MUSICAM)
    {
        mtv_musicam_dec_config_t* musicam_dec_config = &dec_config->u.musicam;

        st->type = MTV_STREAM_AUDIO;
        st->format.audio.bits_per_sample = musicam_dec_config->bits_per_sample;
        st->format.audio.channels = musicam_dec_config->channels;
        st->format.audio.sample_rate = musicam_dec_config->sample_rate;
    }
    else if (dec_config->codec == MTV_CODEC_DRA)
    {
        mtv_dra_dec_config_t* dra_dec_config = &dec_config->u.dra;

        st->type = MTV_STREAM_AUDIO;
        st->format.audio.bits_per_sample = 16;
        st->format.audio.channels = 2;
        st->format.audio.sample_rate = dra_dec_config->sample_rate;
    }
    else if (dec_config->codec == MTV_CODEC_H264)
    {
        st->type = MTV_STREAM_VIDEO;
        st->format.video.width = 320;
        st->format.video.height = 240;
        st->format.video.time_scale = st->dec_config.timestamp_resolution;
    }
    else
    {
        st->type = MTV_STREAM_INVALID;
        return MTV_E_FAIL;
    }
    return MTV_S_OK;

#elif defined(__MED_ATV_MOD__)

    if (dec_config->codec == MTV_CODEC_I2S)
    {
        mtv_i2s_dec_config_t* i2s_dec_config = &dec_config->u.i2s;

        st->type = MTV_STREAM_AUDIO;
        st->format.audio.bits_per_sample = i2s_dec_config->bits_per_sample;
        st->format.audio.channels = i2s_dec_config->channels;
        st->format.audio.sample_rate = i2s_dec_config->sample_rate;
    }
    else if (dec_config->codec == MTV_CODEC_LINEIN)
    {
        mtv_linein_dec_config_t* linein_dec_config = &dec_config->u.linein;

        st->type = MTV_STREAM_AUDIO;
        st->format.audio.bits_per_sample = linein_dec_config->bits_per_sample;
        st->format.audio.channels = linein_dec_config->channels;
        st->format.audio.sample_rate = linein_dec_config->sample_rate;
    }
    else
    {
        st->type = MTV_STREAM_INVALID;
        return MTV_E_FAIL;
    }
    return MTV_S_OK;

#else

    return MTV_E_FAIL;

#endif
}

static mtv_result_t sm_fill_media_info(mtv_service_media_info_t* mi, mtv_spi_service_info_t* info)
{
    kal_uint32 i;

    kal_mem_set(mi, 0, sizeof(*mi));
    mi->audio_st.type = MTV_STREAM_INVALID;
    mi->video_st.type = MTV_STREAM_INVALID;

    for (i = 0; i < info->num_components; i++)
    {
        mtv_spi_component_info_t* comp = &info->components[i];

        if (comp->type == MTV_SPI_COMPONENT_AUDIO)
        {
            sm_get_stream_info(&mi->audio_st, &comp->dec_config);
        }
        else if (comp->type == MTV_SPI_COMPONENT_VIDEO)
        {
            sm_get_stream_info(&mi->video_st, &comp->dec_config);
        }
        else
        {
            /* ignore other kinds of components */
            continue;
        }
    }

    return MTV_S_OK;
}

#if defined(__MTV_TS_SUPPORT__)
static mtv_result_t sm_close_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc)
{
    mtv_result_t ret;

    if (sc->be)
    {
        /* stop active timeshift timer (if the buffer engine is still in MTV_BE_READ_DELAYED state) */
        sc_stop_timeshift_timer();

        if (mtv_push_unclosed_be(&pthis->unclosed_be_list, sc->be))
        {
            /* if the queue is not full, do it asynchronously in the background */
            mtv_call_async(MTV_BACKGROUND_MOD, sm_close_buffer_engine_hdlr, &pthis->unclosed_be_list);
        }
        else /* close the buffer engine synchronously */
        {
            ret = sc->be->close(sc->be);
            ASSERT(ret >= 0);

            sc->be->destroy(sc->be);
        }

        sc->be = NULL;
    }

    sc_restart_player(pthis, sc, SC_RESET_PLAY_RATE);

    return MTV_S_OK;
}

static mtv_result_t sm_close_unsaved_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_buffer_engine_discard_policy_t discard_policy, kal_bool async)
{
    mtv_result_t ret = MTV_S_FALSE;

    if (sc->unsaved_be)
    {
        sc->unsaved_be->set_discard_policy(sc->unsaved_be, discard_policy);

        if (async && mtv_push_unclosed_be(&pthis->unclosed_be_list, sc->unsaved_be))
        {
            /* if the queue is not full, do it asynchronously in the background */
            mtv_call_async(MTV_BACKGROUND_MOD, sm_close_buffer_engine_hdlr, &pthis->unclosed_be_list);
            ret = MTV_S_ASYNC;
        }
        else /* close the buffer engine synchronously */
        {
            ret = sc->unsaved_be->close(sc->unsaved_be);
            ASSERT(ret >= 0);

            sc->unsaved_be->destroy(sc->unsaved_be);
        }

        sc->unsaved_be = NULL;
    }

    return ret;
}

static mtv_result_t sm_setup_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_spi_service_info_t* info)
{
	mtv_result_t ret;
    mtv_service_media_info_t* mi = NULL;
    mtv_buffer_engine_config_t config;
    kal_uint32 be_streams = 0;

    switch (info->type)
    {
    case MTV_SPI_SERVICE_DIGITAL_RADIO:
        config.estimated_bitrate = 128;
        break;

    case MTV_SPI_SERVICE_DIGITAL_TV:
        config.estimated_bitrate = 512;
        break;

    default:
        /* does not support recording */
        return MTV_E_INVALID_PARAM;
    }

    ASSERT(pthis->record_config.record_dir != NULL);
    config.storing_dir = mtv_get_be_dir(pthis->record_config.record_dir);
    config.max_buffer_kb = pthis->record_config.max_timeshift_buffer_kb;
    config.flags = MTV_BE_BUFFER_WRAPAROUND;

    if (sc->info.type == MTV_SPI_SERVICE_DIGITAL_RADIO) {
        config.flags |= MTV_BE_SEQUENTIAL_OUTPUT;
    }

    ASSERT(sc->be == NULL);
    sc->be = construct_mtv_buffer_engine();

    sc->be_client.on_read_state_change = sc_be_on_read_state_change;
    sc->be_client.on_read_seek = sc_be_on_read_seek;

    ret = sc->be->open(sc->be, &sc->be_client, &config);
    if (ret < 0)
    {
        mtv_free_ext_mem((void**) &config.storing_dir);

        sc->be->destroy(sc->be);
        sc->be = NULL;
        return ret;
    }
    mtv_free_ext_mem((void**) &config.storing_dir);

    mi = mtv_alloc_ext_mem(sizeof(*mi), MAKE_FOURCC('S','V','M','I'));

    sm_fill_media_info(mi, info);

    if (mi->audio_st.type == MTV_STREAM_AUDIO)
    {
        ret = sc->be->add_stream(sc->be, &mi->audio_st);
        if (ret < 0) {
            goto setup_failed;
        }
        sc->be_audio_stream = be_streams++;
    }
    if (mi->video_st.type == MTV_STREAM_VIDEO)
    {
        ret = sc->be->add_stream(sc->be, &mi->video_st);
        if (ret < 0) {
            goto setup_failed;
        }
        sc->be_video_stream = be_streams++;
    }

    mtv_free_ext_mem((void**)&mi);
    return MTV_S_OK;

setup_failed:

    mtv_free_ext_mem((void**)&mi);
    sm_close_buffer_engine(pthis, sc);

    return ret;
}

static mtv_result_t sm_start_buffer_engine(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret = MTV_S_FALSE;

    if (pthis->record_config.enable_timeshift && sc->be == NULL && !g_mtv_dump_service)
    {
        ret = sm_setup_buffer_engine(pthis, sc, &sc->info);
    }

    return ret;
}
#endif //#if defined(__MTV_TS_SUPPORT__)

static mtv_result_t sm_start_player(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;
#if defined(__MTV_TS_SUPPORT__)
    kal_bool timeshift_paused;
    mtv_control_timeshift_t* ts = NULL;
#endif

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_START, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state == MTV_SERVICE_STATE_STARTED) {
        return MTV_S_FALSE;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    ret = sm_check_service_activities(pthis, sc, MEDIA_MTV_SERVICE_ACTIVITY_PLAY);
    if (ret < 0) {
        return ret;
    }

    /* save new session ID */
    sc->player_client.session_id = session_id;

#if defined(__MTV_TS_SUPPORT__)
    /* start buffer engine if it not started yet */
    if (!sc->be)
    {
        sm_start_buffer_engine(pthis, sc);
        /* we can continue to play even when buffer engine is not available. */
    }
    pthis->get_control(pthis, service_id, MTV_CONTROL_TIMESHIFT, (void**) &ts);
#endif

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) == 0)
    {
        ret = sc_start_player(pthis, sc);
        if (ret < 0) {
            return ret;
        }

        /* The client has requested to start playing explicitly. */
        sc->activities |= MEDIA_MTV_SERVICE_ACTIVITY_PLAY;

        #if defined(__MTV_TS_SUPPORT__)
        {
            kal_uint32 delay = 0;

            /* for fresh start, set delay to 0 will trigger prebuffering and reduce the buffering time */
            if (ts && ts->get_delay(ts, &delay) >= 0 && delay == 0) {
                ts->set_prebuffering(ts, KAL_TRUE);
            }
        }
        #endif
    }

    #if defined(__MTV_TS_SUPPORT__)


        if (ts && ts->get_pause(ts, &timeshift_paused) >= 0 && timeshift_paused)
        {
            /* resume the time-shifted play */
            ret = ts->set_pause(ts, KAL_FALSE);
        }
        else
    #endif
    if (!sc_is_player_started(sc))
    {
        /* the player is waiting for user's explicit resume request. */
        ret = sc_start_player(pthis, sc);
    }

    return ret;
}

static mtv_result_t sm_stop_player(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_STOP, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || !sc_is_player_started(sc)) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    #if defined(__MTV_TS_SUPPORT__)
    {
        kal_uint32 buffered_ms;

        ret = sc_stop_player(sc, &buffered_ms);
        if (ret >= 0)
        {
            /* The client has requested to stop playing explicitly. */
            sc->activities &= ~MEDIA_MTV_SERVICE_ACTIVITY_PLAY;

            if (buffered_ms > 0)
            {
                /*
                 * backoff timeshift position when paused; otherwise, buffered content in player will be
                 * flushed when resuming playback.
                 */
                sc_timeshift_backoff(sc, buffered_ms);
            }
        }
    }
    #else
        ret = sc_stop_player(sc, NULL);
    #endif // #if defined(__MTV_TS_SUPPORT__)

	return ret;
}

#if defined(__MED_MTV_MOD__)
static mtv_result_t sm_pause_visual_update(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || !sc_is_player_started(sc)) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    ret = sc_player_pause_visual_update(sc);

	return ret;
}

static mtv_result_t sm_resume_visual_update(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state == MTV_SERVICE_STATE_STARTED) {
        return MTV_S_FALSE;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    ret = sm_check_service_activities(pthis, sc, MEDIA_MTV_SERVICE_ACTIVITY_PLAY);
    if (ret < 0) {
        return ret;
    }

    /* the player is waiting for user's explicit resume request. */
    ret = sc_player_resume_visual_update(pthis, sc);

    return ret;
}
#endif  // #if defined(__MED_MTV_MOD__)

static mtv_result_t sm_snapshot(mtv_sm_t* sm, kal_uint32 service_id, void* param)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    return sc_player_snapshot(sc, param);
}

static mtv_result_t sm_get_player_status(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_player_status_t* status)
{
    mtv_service_context_t* sc;
#if defined(__MTV_TS_SUPPORT__)
    mtv_sm_t* pthis = sm;
    mtv_control_trick_mode_t* ctm = NULL;
    mtv_control_timeshift_t* cts = NULL;
#endif


    sc = sm_find_service_by_id(sm, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

#if defined(__MTV_TS_SUPPORT__)
    pthis->get_control(pthis, service_id, MTV_CONTROL_TIMESHIFT, (void**) &cts);
    if (cts)
    {
        kal_bool timeshift_paused = KAL_FALSE;
        mtv_recorder_state_t rec_state = MTV_RECORDER_STATE_STOPPED;
        kal_uint32 dec_buf_duration = 0;

        cts->get_buffer_status(cts, &status->max_delay, &status->buffer_duration);

        cts->get_delay(cts, &status->play_delay);
        if (status->play_delay != 0)
        {
            dec_buf_duration = sc->player ? sc->player->get_buffer_duration(sc->player) : 0;

            /* consider the buffered content in decoder */
            status->play_delay += dec_buf_duration;

            if (status->play_delay > status->max_delay) {
                status->play_delay = status->max_delay;
            }
        }

        /* dispay full buffer when recording is started */
        pthis->get_recorder_state(pthis, service_id, &rec_state);
        if (rec_state == MTV_RECORDER_STATE_STARTED) {
            status->buffer_duration = status->max_delay;
        }

        cts->get_pause(cts, &timeshift_paused);
        status->state = timeshift_paused ? MEDIA_MTV_PLAYER_STATE_PAUSED : MEDIA_MTV_PLAYER_STATE_PLAYING;
    }
    else
#endif // #if defined(__MTV_TS_SUPPORT__)
    {
        mtv_player_state_t player_state;

        player_state = sc->player ? sc->player->get_state(sc->player) : MTV_PLAYER_STATE_STOPPED;
        status->state = (player_state == MTV_PLAYER_STATE_STARTED) ? MEDIA_MTV_PLAYER_STATE_PLAYING : MEDIA_MTV_PLAYER_STATE_STOPPED;
        status->play_delay = 0;
        status->max_delay = 0;
        status->buffer_duration = 0;
    }

#if defined(__MTV_TS_SUPPORT__)
    pthis->get_control(pthis, service_id, MTV_CONTROL_TRICK_MODE, (void**) &ctm);
    if (ctm) {
        ctm->get_rate(ctm, &status->play_rate);
    }
    else {
        status->play_rate = 1000;
    }
#endif

    return MTV_S_OK;
}

#if defined(__MTV_REC_SUPPORT__)
static mtv_result_t sm_check_recording_feasibility(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    kal_uint32 i;

    for (i = 0; i < sc->info.num_components; i++)
    {
        mtv_spi_component_info_t* comp = &sc->info.components[i];

        /* we don't support recording of TV channel with DRA into MP4 now */
        if (comp->dec_config.codec == MTV_CODEC_DRA && sc->info.num_components > 1) {
            RETURN_E(sc->info.id, MTV_E_UNSUPPORTED_FORMAT);
        }
    }

    return MTV_S_OK;
}

static mtv_result_t sm_start_recorder(mtv_sm_t* sm, kal_uint32 service_id, const kal_wchar* service_name, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_START, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    sc->recorder_client.session_id = session_id;

    ret = sm_check_service_activities(pthis, sc, MEDIA_MTV_SERVICE_ACTIVITY_RECORD);
    if (ret < 0) {
        return ret;
    }

    ret = sm_check_recording_feasibility(pthis, sc);
    if (ret < 0) {
        return ret;
    }

#if defined(__MTV_TS_SUPPORT__)
    /* start buffer engine if it not started yet */
    if (!sc->be)
    {
        ret = sm_start_buffer_engine(pthis, sc);
        if (ret < 0) {
            return ret;
        }
    }
#endif

    return sc_start_recorder(sc, service_name);
}

static mtv_result_t sm_get_recorder_state(mtv_sm_t* sm, kal_uint32 service_id, mtv_recorder_state_t* state)
{
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(sm, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    if (sc->recorder) {
        *state = sc->recorder->get_state(sc->recorder);
    }
    else
    {
        /* for unstarted service, return recorder state as STOPPED */
        *state = MTV_RECORDER_STATE_STOPPED;
    }

    return MTV_S_OK;
}

static mtv_result_t sc_stop_recorder(mtv_service_context_t* sc)
{
    mtv_result_t ret;

    if (!sc->recorder) {
        return MTV_S_FALSE;
    }

    ret = sc->recorder->stop(sc->recorder);
    if (ret != MTV_S_OK) {
        return ret;
    }

    /* The client has requested to stop recording explicitly. */
    sc->activities &= ~MEDIA_MTV_SERVICE_ACTIVITY_RECORD;

    #if defined(__MTV_TS_SUPPORT__)
        /* stop timeshift timer if there is one because current one will be detached */
        sc_stop_timeshift_timer();
        /* detach current BE for file saving */
        sc->unsaved_be = sc->be;
        sc->be = NULL;
    #endif

    return MTV_S_OK;
}

/*
 * This method is assumed to be called by another task for background file saving.
 */
static mtv_result_t sm_stop_recorder(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
	mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STOP, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    ret = sc_stop_recorder(sc);
    if (ret != MTV_S_OK) {
        return ret;
    }

    if (pthis->record_config.enable_timeshift)
    {
        sc_restart_player(sm, sc, SC_RESET_PLAY_RATE); /* reset play rate to 1X */
    }

#if defined(__MTV_TS_SUPPORT__)
    /* create a new BE for player */
    if (sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY)
    {
        ret = sm_start_buffer_engine(pthis, sc);
        if (sc->be)
        {
            sc_enter_live_mode(sc); /* switch back to live broadcasting */
        }
        else
        {
            /*
             * don't return error even when new BE cannot be started. the client should
             * check whether time-shift is available after recorder is stopped.
             */
        }
    }
#endif

	return MTV_S_OK;
}

static mtv_result_t sc_pause_recorder(mtv_service_context_t* sc)
{
    mtv_result_t ret;

    if (!sc->recorder) {
        return MTV_S_FALSE;
    }

    ret = sc->recorder->pause(sc->recorder);
    if (ret != MTV_S_OK) {
        return ret;
    }

    return MTV_S_OK;
}

static mtv_result_t sm_pause_recorder(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
	mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STOP, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    ret = sc_pause_recorder(sc);
    if (ret != MTV_S_OK) {
        return ret;
    }

	return MTV_S_OK;
}

static mtv_result_t sc_resume_recorder(mtv_service_context_t* sc)
{
    mtv_result_t ret;

    if (!sc->recorder) {
        return MTV_S_FALSE;
    }

    ret = sc->recorder->resume(sc->recorder);
    if (ret != MTV_S_OK) {
        return ret;
    }

    return MTV_S_OK;
}

static mtv_result_t sm_resume_recorder(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
	mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STOP, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    ret = sc_resume_recorder(sc);
    if (ret != MTV_S_OK) {
        return ret;
    }

	return MTV_S_OK;
}
#endif //#if defined(__MTV_REC_SUPPORT__)

#if defined(__MTV_TS_SUPPORT__)
static mtv_result_t sm_start_timeshift(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
	mtv_result_t ret;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    /* save new session ID */
    sc->player_client.session_id = session_id;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    if (sc->be)
    {
        /* it is already there */
        return MTV_S_FALSE;
    }

    ret = sm_start_buffer_engine(pthis, sc);
    if (ret < 0) {
        RETURN_E(sc->info.id, ret);
    }

    return ret;
}
#endif //#if defined(__MTV_TS_SUPPORT__)

#if defined(__MTV_REC_SUPPORT__)
static mtv_result_t sc_prepare_saving(mtv_service_context_t* sc)
{
    mtv_result_t ret = MTV_E_FAIL;

    #if defined(__MTV_TS_SUPPORT__)
    {
        mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

        if (sm->record_config.enable_timeshift && sc->unsaved_be == NULL)
        {
            return MTV_E_FAIL;
        }
    }
    #endif

    ret = sc->recorder->prepare_saving(sc->recorder);
    if (ret >= 0)
    {
        sc->saving_aborted = KAL_FALSE; /* reset abort flag */
    }

    return ret;
}

/**
  * Theoretically sm_close_unsaved_buffer_engine may happen at the same
  * time as sc_save_recording. However, it should be very hard to happen with
  * current MMI implementation.
  */
static mtv_result_t sc_save_recording(mtv_service_context_t* sc, kal_wchar* file_path)
{
    mtv_result_t ret = MTV_S_FALSE;
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

#if defined(__MTV_TS_SUPPORT__)
    mtv_buffer_engine_t* be = sc->unsaved_be;

    sc->unsaved_be = NULL; /* detach it immediately */
    if (sm->record_config.enable_timeshift && be == NULL)
    {
        /* impossible, should be checked in sc_prepare_saving() */
        ASSERT(0);
        return MTV_E_FAIL;
    }
#endif

    ret = sc->recorder->do_saving(sc->recorder, sm->record_config.record_dir, file_path, &sc->saving_aborted);

    return ret;
}

static mtv_result_t sm_prepare_saving(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    switch (sc->state)
    {
    case MTV_SERVICE_STATE_READY:
    case MTV_SERVICE_STATE_ABORTED:
    case MTV_SERVICE_STATE_REMOVED:
        /* OK to do saving */
        break;

    case MTV_SERVICE_STATE_STOPPED:
    case MTV_SERVICE_STATE_STARTED:
    default:
        return MTV_E_WRONG_STATE;
    }

    return sc_prepare_saving(sc);
}

static mtv_result_t sm_save_recording(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id, kal_wchar* file_path)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    switch (sc->state)
    {
    case MTV_SERVICE_STATE_READY:
    case MTV_SERVICE_STATE_ABORTED:
    case MTV_SERVICE_STATE_REMOVED:
        /* OK to do saving */
        break;

    case MTV_SERVICE_STATE_STOPPED:
    case MTV_SERVICE_STATE_STARTED:
    default:
        return MTV_E_WRONG_STATE;
    }

    sc->recorder_client.session_id = session_id;

    return sc_save_recording(sc, file_path);
}

static mtv_result_t sm_abort_saving(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    sc->saving_aborted = KAL_TRUE; /* trigger the abort */

    /* wait until the abort is done */
    while (sc->recorder->get_state(sc->recorder) == MTV_RECORDER_STATE_SAVING)
    {
        kal_sleep_task(KAL_TICKS_1_SEC / 2);
    }

    return MTV_S_OK;
}

static mtv_result_t sm_recorder_discard_recording(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret = MTV_S_OK;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    switch (sc->state)
    {
    case MTV_SERVICE_STATE_READY:
    case MTV_SERVICE_STATE_ABORTED:
    case MTV_SERVICE_STATE_REMOVED:
        /* OK to do saving */
        break;

    case MTV_SERVICE_STATE_STOPPED:
    case MTV_SERVICE_STATE_STARTED:
    default:
        return MTV_S_FALSE;
    }

    sc->recorder_client.session_id = session_id;

#if defined(__MED_MTV_MOD__)
    /* then discard the buffer files */
    #if defined(__MTV_TS_SUPPORT__)
        ret = sm_close_unsaved_buffer_engine(pthis, sc, MTV_BE_DISCARD_FILES_AFTER_CLOSE, KAL_FALSE);
        if (ret >= 0)
    #endif //#if defined(__MTV_TS_SUPPORT__)
        {
            ret = sc->recorder->delete_checkpoint(sc->recorder);
        }
#elif defined(__MED_ATV_MOD__)
    ret = sc->recorder->delete_checkpoint(sc->recorder);
#else
    ASSERT(0);
    ret = MTV_E_FAIL;
#endif
    sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_RECORDER_RECORDING_DISCARDED, ret, sc->recorder_client.session_id);
    return ret;
}
#endif //#if defined(__MTV_REC_SUPPORT__)

#if defined(__MED_MTV_MOD__)
static mtv_result_t sm_esg_download(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    return esgi->download(esgi);
}

static mtv_result_t sm_esg_abort_downloading(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    return esgi->abort_downloading(esgi);
}

static mtv_result_t sm_esg_query(mtv_sm_t* sm, kal_int32 type, media_mtv_esg_query_struct *query)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    if (pthis->esg_qe_state == MTV_ESG_QUERY_STATE_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    sm->qe_query_type = type;
    ret = esgi->query(esgi, type, query);

    if (ret >= 0) {
        pthis->esg_qe_state = MTV_ESG_QUERY_STATE_QUERY;
    }
    else {
        pthis->esg_qe_state = MTV_ESG_QUERY_STATE_OPENED;
    }

    return ret;
}

static mtv_result_t sm_esg_get_result(mtv_sm_t* sm, kal_int32 type, void **buf_p)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    if (pthis->esg_qe_state != MTV_ESG_QUERY_STATE_QUERY)
    {
        *buf_p = NULL;
        return MTV_E_WRONG_STATE;
    }

    if (sm->qe_query_type != type)
    {
        *buf_p = NULL;
        return MTV_E_INVALID_PARAM;
    }

    ret = esgi->get_result(esgi, type, buf_p);

    if ((*buf_p) == NULL)
    {
        pthis->esg_qe_state = MTV_ESG_QUERY_STATE_OPENED;
    }

    return ret;
}

static mtv_result_t sm_esg_query_finish(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    if (pthis->esg_qe_state == MTV_ESG_QUERY_STATE_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    ret = esgi->query_finish(esgi);

    pthis->esg_qe_state = MTV_ESG_QUERY_STATE_OPENED;

    return ret;
}

static mtv_result_t sm_esg_add_favorite(mtv_sm_t* sm, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    if (pthis->esg_qe_state == MTV_ESG_QUERY_STATE_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    ret = esgi->add_favorite(esgi, type, id, rid);

    return ret;
}

static mtv_result_t sm_esg_del_favorite(mtv_sm_t* sm, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret;

    if (pthis->esg_qe_state == MTV_ESG_QUERY_STATE_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    ret = esgi->del_favorite(esgi, type, id, rid);

    return ret;
}

static mtv_result_t sm_esg_free_result_buffer(mtv_sm_t* sm, void* buf_p)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_esg_t* esgi;
    mtv_result_t ret = MTV_S_OK;

    ret = pthis->spi->get_esg_interface(pthis->spi, &esgi);
    if (ret < 0) {
        return ret;
    }

    ret = esgi->free_result_buffer(esgi, sm->qe_query_type, buf_p);

    return ret;
}

static mtv_result_t sm_esg_get_qe_state(mtv_sm_t* sm, mtv_esg_query_state_enum* state)
{
    mtv_sm_t* pthis = sm;

    *state = pthis->esg_qe_state;
    return MTV_S_OK;
}

static mtv_result_t sm_ca_get_card_info(mtv_sm_t* sm, kal_char **card_number)
{
    mtv_sm_t* pthis = sm;
    mtv_spi_ca_t* cai;
    mtv_result_t ret;

    ret = pthis->spi->get_ca_interface(pthis->spi, &cai);
    if (ret < 0) {
        return ret;
    }

    ret = cai->get_card_info(cai, card_number);
    return ret;
}
#endif //#if defined(__MED_MTV_MOD__)

static mtv_result_t sm_start_service(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 activities, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_START_SERVICE, service_id, activities);
    mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start service", service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_INVALID_SERVICE_ID, service_id);
        return MTV_E_FAIL;
    }
    else if (sc->state != MTV_SERVICE_STATE_STOPPED)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_ALREADY_STARTED, service_id);
        return MTV_E_FAIL;
    }

    kal_get_time(&sc->start_service_time);

    ret = sm_check_service_activities(pthis, sc, activities);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_ACTIVITY_CHECK_FAILED, service_id);
        return ret;
    }

    ret = pthis->spi->start_service(pthis->spi, service_id);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SM_SP_FAIL_TO_START, service_id);
        return ret;
    }

    /* construct the player */
    ASSERT(sc->player == NULL);
#if defined(__MED_MTV_MOD__)
    sc->player = construct_mtv_streaming_player(pthis->app_id);
#elif defined(__MED_ATV_MOD__)
    sc->player = construct_atv_player(pthis->app_id);
#endif

    ASSERT(sc->player);
#if defined(__MED_MTV_MOD__)
    sc->player_client.on_audio_error = sc_player_on_audio_error;
    sc->player_client.on_video_error = sc_player_on_video_error;
    sc->player_client.on_rate_change = sc_player_on_rate_change;
    sc->player_client.on_restart = sc_player_on_restart;
#endif // #if defined(__MED_MTV_MOD__)
    sc->player_client.on_state_change = sc_player_on_state_change;

#if defined(__MTV_REC_SUPPORT__)

    /* construct the recorder */
    ASSERT(sc->recorder == NULL);
    #if defined(__MED_MTV_MOD__)
        sc->recorder = construct_mtv_recorder(pthis->app_id);
    #elif defined(__MED_ATV_MOD__)
        sc->recorder = construct_atv_recorder(pthis->app_id);
    #endif

    sc->recorder_client.on_state_change = sc_recorder_on_state_change;
    sc->recorder_client.on_error = sc_recorder_on_error;
    sc->recorder_client.on_save = sc_recorder_on_save;

#endif // #if defined(__MTV_REC_SUPPORT__)

    sc = sm_set_service_started(pthis, sc, activities, session_id);
    sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_STARTED, MTV_S_OK, sc->session_id);

    return MTV_S_OK;
}

static mtv_result_t sm_get_control(mtv_sm_t* sm, kal_uint32 service_id, mtv_control_t control_id, void** control)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    switch (control_id)
    {
#if defined(__MTV_REC_SUPPORT__)
    case MTV_CONTROL_RECORD:
        return sc->recorder ? sc->recorder->get_control(sc->recorder, control_id, control) : MTV_E_FAIL;
#endif

#if defined(__MTV_TS_SUPPORT__)
    case MTV_CONTROL_TIMESHIFT:
        return sc->be ? sc->be->get_control(sc->be, control_id, control) : MTV_E_FAIL;
#endif

    case MTV_CONTROL_VIDEO:
    case MTV_CONTROL_VOLUME:
#if defined(__MTV_TS_SUPPORT__)
    case MTV_CONTROL_TRICK_MODE:
#endif
        return sc->player ? sc->player->get_control(sc->player, control_id, control) : MTV_E_FAIL;

    default:
        return MTV_E_FAIL;
    }
}

static mtv_result_t sm_get_service_param(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_param_t param, kal_uint32* value)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    switch (param)
    {
    case MTV_SERVICE_PARAM_SIGNAL_STRENGTH:
        {
            mtv_spi_status_t spi_status;

            sc = sm_find_service_by_id(pthis, service_id);
            if (!sc)
            {
                return MTV_E_FAIL;
            }

            if (sc->state == MTV_SERVICE_STATE_STOPPED)
            {
                return MTV_E_FAIL;
            }
            pthis->spi->get_status(pthis->spi, &spi_status);
            *value = spi_status.signal_strength * 100 / MTV_SPI_MAX_SIGNAL_STRENGTH;
        }
        break;

#if defined(__MED_MTV_MOD__)
    case MTV_SERVICE_PARAM_SERVICE_CA:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_CA, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_IMD_COUNT:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_IMD_COUNT, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_IMD_DESC:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_IMD_DESC, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_IMD_DETAIL:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_IMD_DETAIL, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_ESG_SOURCE:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_ESG_SOURCE, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_NIT_TIME:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_NIT_TIME, (kal_uint32)value);
        }
        break;
    case MTV_SERVICE_PARAM_NIT_AREA:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_NIT_AREA, (kal_uint32)value);
        }
        break;
#endif // #if defined(__MED_MTV_MOD__)

    case MTV_SERVICE_PARAM_VIDEO_MODE:
        {
            pthis->spi->get_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_VIDEO_MODE, (kal_uint32)value);
        }
        break;

    default:
        return MTV_E_INVALID_PARAM;
    }

    return MTV_S_OK;
}


static mtv_result_t sm_get_service_context(mtv_sm_t* sm, mtv_get_sc_method_t method, kal_uint32 param, mtv_service_context_t* sc)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* service_context;

    if (method == MTV_GET_SC_METHOD_SERVICE_ID)
    {
        service_context = sm_find_service_by_id(pthis, param);
    }
    else if(method == MTV_GET_SC_METHOD_INDEX)
    {
        service_context = sm_find_service_by_index(pthis, param);
    }
    else
    {
        return MTV_E_INVALID_PARAM;
    }

    if (service_context)
    {
        *sc = *service_context;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t sm_close_service_context(mtv_sm_t* pthis, mtv_service_context_t* sc)
{
    mtv_result_t ret;

    ASSERT(sc && sc->state != MTV_SERVICE_STATE_STOPPED);

#if defined(__MTV_REC_SUPPORT__)
    ret = sc_stop_recorder(sc);
    if (ret < 0)
    {
        /* stopping a recorder may fail if saving recording is in progress */
        RETURN_E(sc->info.id, MTV_E_BUSY);
    }
#endif

    ret = sc_stop_player(sc, NULL);
    ASSERT(ret >= 0);

#if defined(__MTV_TS_SUPPORT__)
    ret = sm_close_buffer_engine(pthis, sc);
    ASSERT(ret >= 0);
    ret = sm_close_unsaved_buffer_engine(pthis, sc, MTV_BE_KEEP_FILES_AFTER_CLOSE, KAL_TRUE);
    ASSERT(ret >= 0);
#endif

    if (sc->state == MTV_SERVICE_STATE_REMOVED) {
        sm_remove_service_context(pthis, sc->info.id);
    }
    else {
        sc = sm_set_service_stopped(sc);
    }

#if defined(__MTV_REC_SUPPORT__)
    if (sc->recorder)
    {
        sc->recorder->destroy(sc->recorder);
        sc->recorder = NULL;
    }
#endif // #if defined(__MTV_REC_SUPPORT__)

    if (sc->player)
    {
        sc->player->destroy(sc->player);
        sc->player = NULL;
    }

    return ret;
}

static mtv_result_t sm_stop_service(mtv_sm_t* sm, mtv_service_context_t* sc, mtv_result_t cause)
{
	mtv_sm_t* pthis = sm;
	mtv_result_t ret;
    kal_uint32 sid;
    kal_uint32 session_id;

    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_S_FALSE; /* do nothing if the service has been removed or stopped */
    }

    sid = sc->info.id;
    session_id = sc->session_id;

    MTV_TRACE(TRACE_INFO, MTV_TRC_STOP_SERVICE, sid);

    ret = pthis->spi->stop_service(pthis->spi, sid);
    if (ret >= 0)
    {
        ret = sm_close_service_context(pthis, sc);
        if (ret >= 0)
        {
            /* notify the client about the stop */
            sm_callback_with_id(pthis, sid, MTV_SERVICE_EVENT_STOPPED, cause, session_id);
        }
    }

    return ret;
}

static mtv_result_t sm_stop_service_by_id(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    return sm_stop_service(pthis, sc, MTV_S_OK);
}

static mtv_result_t sm_free_service_context_list(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    /* abort all running services and free their context */
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;
        mtv_service_context_t* next;

        do
        {
            if (sm_is_service_started(sc)) {
                sm_stop_service(pthis, sc, MTV_S_OK);
            }
            next = sc->next;
            mtv_free_ext_mem((void**)&sc);
            sc = next;
        } while (sc != head);

        pthis->sc_tail = NULL;

        return MTV_S_OK;
    }

    return MTV_S_FALSE;
}

const kal_wchar* mtv_get_setting_dir(void)
{
    FS_HANDLE fh;

    fh = FS_Open(MTV_SETTING_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (fh >= FS_NO_ERROR) {
        FS_Close(fh);
    }
    else
    {
        kal_int32 ret = FS_CreateDir(MTV_SETTING_PATH);
        if (ret < FS_NO_ERROR) {
            return NULL;
        }
    }

    return MTV_SETTING_PATH;
}

static mtv_result_t sm_search_services(mtv_sm_t* sm, media_mtv_service_source_enum source, mtv_freq_band_t band, void *param)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SM_SEARCH_SERVICES, source, band);

    if (sm_is_any_service_started(pthis))
    {
        /* servic searching is mutually exclusive with service receiving. */
        RETURN_E(-1, MTV_E_RESOURCE_CONFLICT);
    }

    /* free existing list */
    sm_free_service_context_list(pthis);
    pthis->notify_service = KAL_TRUE;

    #if defined(__MED_MTV_MOD__)
        pthis->init_state = MTV_INIT_STATE_IDLE;
    #endif // #if defined(__MED_MTV_MOD__)

    if (source == MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL)
    {
        /* search service from service provider */
        ret = pthis->spi->search_services(pthis->spi, band, param);
    }
    else if (source == MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE)
    {
        /* load from database */
        const kal_wchar* setting_dir = mtv_get_setting_dir();
        if (setting_dir != NULL) {
            ret = pthis->spi->load_service_list(pthis->spi, setting_dir, band, param);
        }
        else {
            ret = MTV_E_FAIL;
        }
    }
    else
    {
        NOT_REACHED("Invalid service source is specified!");
        ret = MTV_E_FAIL;
    }

    return ret;
}

static mtv_result_t sm_get_media_info(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_media_info_t* mi)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    return sm_fill_media_info(mi, &sc->info);
}

static mtv_result_t sm_close(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
	mtv_result_t ret = MTV_S_FALSE;

    MTV_TRACE(TRACE_INFO, MTV_TRC_CLOSE);

    #if defined(__MTV_REC_SUPPORT__)
        mtv_free_ext_mem((void**)&pthis->record_config.record_dir);
    #endif

    sm_free_service_context_list(pthis);

    /* close service provider */
    if (pthis->spi)
    {
    	ret = pthis->spi->close(pthis->spi);
        #if defined(__MED_MTV_MOD__)
            pthis->esg_qe_state = MTV_ESG_QUERY_STATE_CLOSED;
        #endif // #if defined(__MED_MTV_MOD__)
	    ASSERT(ret >= 0);
    }

    return ret;
}

/* mtv_spi_client_t interface implementation */

static void sm_on_service(mtv_spi_client_t* client, mtv_spi_service_info_t* info)
{
	mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc;

    sc = sm_add_service_context(pthis, info);  /* find empty slot */
    if (sc && pthis->notify_service)
    {
        /* call-back to notify client about the new service */
        sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_FOUND, MTV_S_OK, sc->session_id);
    }
}

#if defined(__MTV_TS_SUPPORT__)
static mtv_result_t sm_write_be_packet(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_packet_t* au, kal_uint32 be_stream_index, mtv_source_stat_t* src_stat)
{
    mtv_result_t ret = MTV_S_FALSE;

    ASSERT(sc->be);
    if (au->timestamp != (kal_uint32) -1)
    {
        kal_uint32 be_events = 0;

        /*
         * save a checkpoint after a period of time.
         */
        if (sc_is_recorder_started(sc) &&
            sc->be->num_incoming % MTV_SAVE_CHECKPOINT_INTERVAL == (MTV_SAVE_CHECKPOINT_INTERVAL - 1))
        {
            sc->recorder->save_checkpoint(sc->recorder, sc->be->storing_dir);
        }

        ret = sc->be->write_packet(sc->be, be_stream_index, au, &be_events, src_stat);

        /* check events after the writing */
        if ((be_events & MTV_BE_EVENT_BOC) != 0)
        {
            /* the beginning may been overwritten when the player is paused */
            sc_start_from_beginning_of_content(sc);
        }
    }

	return ret;
}

static void sm_on_buffer_engine_error(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_result_t result)
{
    MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_ERROR, result);

    if (sc_is_recorder_started(sc))
    {
        /* stop the recorder automaticlly */
        sm_stop_recorder(pthis, sc->info.id);

        /* notify the client about the error */
        sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_RECORDER_ERROR, result, sc->recorder_client.session_id);

        /* the client should handle the error and save the recording */
    }

    /* the following processing applies both to time-shifted and recording */
    sm_close_buffer_engine(pthis, sc);

    /* notify the client about the error */
    sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_ERROR, result, sc->player_client.session_id);
}
#endif //#if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
static mtv_result_t sm_deliver_audio_au(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_packet_t* au)
{
    mtv_result_t ret = MTV_S_OK;

    #if defined(__MTV_TS_SUPPORT__)
        if (sc->be)
        {
            ret = sm_write_be_packet(pthis, sc, au, sc->be_audio_stream, &sc->audio_src_stat);
            if (ret < 0) {
                sm_on_buffer_engine_error(pthis, sc, ret);
            }
            else
            {
                switch (sc->be->get_read_state(sc->be))
                {
                case MTV_BE_READ_LIVE:
                    if (sc_is_player_started(sc))
                    {
                        /* deliver the AU to decoder directly in no-delay mode */
                        ret = sc->player->deliver_au(sc->player, MTV_STREAM_AUDIO, au);
                    }
                    break;
                }
            }
        }
        else
    #endif // #if defined(__MTV_TS_SUPPORT__)
    if (sc_is_player_started(sc))
    {
        ret = sc->player->deliver_au(sc->player, MTV_STREAM_AUDIO, au);
    }
    else
    {
        /* the packet is discarded */
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] packet discarded: %d bytes", sc->info.id, au->size);
    }

    return ret;
}

static void sm_fill_av_gap(void* param, mtv_packet_t* au)
{
    mtv_service_context_t* sc = (mtv_service_context_t*) param;
    mtv_sm_t* pthis = (mtv_sm_t*) sc->owner;

    sm_deliver_audio_au(pthis, sc, au);
}

static mtv_result_t sm_compensate_av_offset(mtv_service_context_t* sc, mtv_packet_t* au)
{
    if (sc->video_src_stat.probing)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_DISCARD_AUDIO_BEFORE_VIDEO_READY, sc->info.id, au->timestamp);
        return MTV_S_FALSE; /* wait until the probing is done */
    }
    else if (!sc->av_offset_compensated)
    {
        kal_uint32 timestamp_resolution = sc->audio_comp->dec_config.timestamp_resolution;

        if (au->timestamp < sc->video_src_stat.base_timestamp)
        {
            kal_uint32 offset = sc->video_src_stat.base_timestamp - au->timestamp;

            if (offset > MTV_MAX_ALLOWED_AV_OFFSET * timestamp_resolution)
            {
                /* maybe the audio/video timestamp base is not aligned?! */
                MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_NOT_NECESSARY_TO_COMPENSATE, sc->info.id, offset, timestamp_resolution);
            }
            else
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_DISCARD_EARLY_AUDIO, sc->info.id, au->timestamp);
                return MTV_S_FALSE; /* wait until audio sample with larger timestamp */
            }
        }
        else
        {
            kal_uint32 offset = au->timestamp - sc->video_src_stat.base_timestamp;

            if (offset > MTV_MAX_ALLOWED_AV_OFFSET * timestamp_resolution)
            {
                /* maybe the audio/video timestamp base is not aligned?! */
                MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_NOT_NECESSARY_TO_COMPENSATE, sc->info.id, offset, timestamp_resolution);
            }
            else if (offset >= sc->audio_src_stat.au_duration)
            {
                kal_uint32 au_count = offset / sc->audio_src_stat.au_duration;
                kal_uint32 ts = au->timestamp - sc->audio_src_stat.au_duration * au_count;

                MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_COMPENSATE_AV_OFFSET, sc->info.id, offset, timestamp_resolution);
                mtv_audio_add_silence(&sc->audio_comp->dec_config, ts, au_count, sc->audio_src_stat.au_duration,
                                            sm_fill_av_gap, sc);
            }
            else {
                MTV_TRACE(TRACE_INFO, MTV_TRC_AVSYNC_NOT_NECESSARY_TO_COMPENSATE, sc->info.id, offset, timestamp_resolution);
            }
        }

        sc->av_offset_compensated = KAL_TRUE;
    }

    return MTV_S_OK;
}

static kal_bool sm_check_timestamp_validility(mtv_service_context_t* sc, mtv_source_stat_t* src_stat, mtv_spi_component_info_t* comp, kal_uint32 timestamp)
{
    mtv_timestamp_status_t tss;

    tss = mtv_source_stat_update(src_stat, timestamp);
    if (tss < 0)
    {
        if (tss == MTV_TIMESTAMP_BIG_JUMP) {
            sc_init_src_stat(sc);   /* reset source stat to compensate A/V offset again */
        }

        return KAL_FALSE; /* drop the packet */
    }
    else if (src_stat->loss * src_stat->au_duration >=
             MTV_AUDIO_CONCEALMENT_THRESHOLD * comp->dec_config.timestamp_resolution)
    {
        sc_init_src_stat(sc);   /* reset source stat to compensate A/V offset again */
        tss = mtv_source_stat_update(src_stat, timestamp);
    }

    return KAL_TRUE;
}

/**
  * Common handling of new AU arrival.
  */
static void sm_on_new_au(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_packet_t* au)
{
    UNUSED(au);

    if (sc->ca_state == MTV_SERVICE_CA_STATE_ACCESS_DENIED)
    {
        sc->ca_state = MTV_SERVICE_CA_STATE_ACCESS_GRANTED;
        sm_callback_with_id(pthis, sc->info.id, MTV_SERVICE_EVENT_ACCESS_GRANTED, MTV_S_OK, sc->session_id);
    }
}

static void sm_on_audio_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        ASSERT(sc->state == MTV_SERVICE_STATE_READY);

        sm_on_new_au(pthis, sc, au);

        /* drop packet received during poor reception */
        if (pthis->drop_packets)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_SM_DROP_AUDIO, sc->info.id, au->size, au->timestamp);
            pthis->rq.dropped++;
            return;
        }

        if (!sm_check_timestamp_validility(sc, &sc->audio_src_stat, sc->audio_comp, au->timestamp)) {
            return; /* drop the packet */
        }

        if ((sc->info.flags & MTV_SPI_SERVICE_COMPENSATE_AV_OFFSET) != 0 && !sc->av_offset_compensated)
        {
            ret = sm_compensate_av_offset(sc, au);
            if (ret != MTV_S_OK) {
                return;
            }
        }

        ret = sm_deliver_audio_au(pthis, sc, au);
    }
    else
    {
        NOT_REACHED("AU comes from unknown service!");
    }
}

static mtv_result_t sm_deliver_video_au(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_packet_t* au)
{
    mtv_result_t ret = MTV_S_OK;

    #if defined(__MTV_TS_SUPPORT__)
        if (sc->be)
        {
            ret = sm_write_be_packet(pthis, sc, au, sc->be_video_stream, &sc->video_src_stat);
            if (ret < 0) {
                sm_on_buffer_engine_error(pthis, sc, ret);
            }
            else
            {
                switch (sc->be->get_read_state(sc->be))
                {
                case MTV_BE_READ_LIVE:
                    if (sc_is_player_started(sc))
                    {
                        /* deliver the AU to decoder directly in no-delay mode */
                        ret = sc->player->deliver_au(sc->player, MTV_STREAM_VIDEO, au);
                    }
                    break;
                }
            }
        }
        else
    #endif // #if defined(__MTV_TS_SUPPORT__)
        if (sc_is_player_started(sc))
        {
            ret = sc->player->deliver_au(sc->player, MTV_STREAM_VIDEO, au);
        }
        else
        {
            /* the packet is discarded */
            mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] packet discarded: %d bytes", sc->info.id, au->size);
        }

    return ret;
}

static void sm_on_video_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au)
{
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        ASSERT(sc->state == MTV_SERVICE_STATE_READY);

        sm_on_new_au(pthis, sc, au);

        /* drop packet received during poor reception */
        if (pthis->drop_packets)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_SM_DROP_VIDEO, sc->info.id, au->size, au->timestamp);
            pthis->rq.dropped++;
            return;
        }

        if (!sm_check_timestamp_validility(sc, &sc->video_src_stat, sc->video_comp, au->timestamp)) {
            return; /* drop the packet */
        }

        sm_deliver_video_au(pthis, sc, au);
    }
    else
    {
        NOT_REACHED("AU comes from unknown service!");
    }
}

static void sm_on_data_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_spi_service_data_type_t data_type, mtv_packet_t* au)
{
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        switch (data_type)
        {
        case MTV_SPI_DATA_DLS:

            if (!pthis->drop_packets)
            {
                /* assume AU data is a null-terminated wchar string */
                sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_DYNAMIC_LABEL, (kal_uint32) au->data, sc->player_client.session_id);
            }
            break;

        case MTV_SPI_DATA_PROGRAM_INFO:

            sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_PROGRAM_INFO, (kal_uint32) au->data, sc->session_id);
            break;

        default:
            break;
        }
    }

    if (au->flags & MTV_PACKET_RECEIVER_SHOULD_FREE)
    {
        mtv_free_ext_mem((void**) &au->data);
    }
}

static void sm_on_service_updated(mtv_sm_t* pthis, mtv_spi_service_info_t* info)
{
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, info->id);
    mtv_service_media_info_t* mi = NULL;

    ASSERT(sc != NULL);

    ASSERT(sc->state == MTV_SERVICE_STATE_READY);

    /* copy the info again because it contains new info */
    kal_mem_cpy(&sc->info, info, sizeof(sc->info));

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0)
    {
        sc_restart_player(pthis, sc, SC_TIMESHIFT_BACKOFF);
    }

    mi = mtv_alloc_ext_mem(sizeof(*mi), MAKE_FOURCC('S','V','M','I'));

    sm_fill_media_info(mi, &sc->info);

#if defined(__MTV_TS_SUPPORT__)
    if (sc->be && mi->video_st.type == MTV_STREAM_VIDEO)
    {
        sc->be->update_stream_info(sc->be, sc->be_video_stream, &mi->video_st);
    }
    if (sc->be && mi->audio_st.type == MTV_STREAM_AUDIO)
    {
        sc->be->update_stream_info(sc->be, sc->be_audio_stream, &mi->audio_st);
    }
#endif

    mtv_free_ext_mem((void**)&mi);
}
#endif //#if defined(__MED_MTV_MOD__)

static void sm_on_service_acquired(mtv_sm_t* pthis, mtv_spi_service_info_t* info)
{
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, info->id);
	mtv_result_t ret = MTV_S_OK;

    mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] stream acquired", info->id);

    ASSERT(sc != NULL);

    ASSERT(sc->state == MTV_SERVICE_STATE_STARTED);
    sc->state = MTV_SERVICE_STATE_READY;

    /* copy the info again because it contains new info */
    kal_mem_cpy(&sc->info, info, sizeof(sc->info));

#if defined(__MED_MTV_MOD__)
    /* initialize source statistics */
    sc_init_src_stat(sc);

    #if defined(__MTV_TS_SUPPORT__)
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start BE", info->id);
        ret = sm_start_buffer_engine(pthis, sc);
        if (ret < 0)
        {
            /* we can continue to play even when buffer engine is not available. */
            ret = MTV_S_OK;
        }
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start BE done", info->id);
    #endif
#endif // #if defined(__MED_MTV_MOD__)

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0)
    {
        if ((info->type == MTV_SPI_SERVICE_DIGITAL_TV || info->type == MTV_SPI_SERVICE_ANALOG_TV) && pthis->video_config.update_layer == 0)
        {
            /* if the video configuration is wrong, prevent to play it! */
            sc->activities &= ~MEDIA_MTV_SERVICE_ACTIVITY_PLAY;
            mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] video configuration is wrong, prevent to play it! type[%d], layer[%d]", info->id, info->type, pthis->video_config.update_layer);
        }
        else
        {
            sc->player_client.session_id = sc->session_id;

            mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start player", info->id);
            ret = sc_start_player(pthis, sc);
            if (ret < 0) {
                goto service_accquired_cleanup;
            }
            mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start player done", info->id);
        }
    }

#if defined(__MTV_REC_SUPPORT__)
    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) != 0)
    {
        sc->recorder_client.session_id = sc->session_id;
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] start recorder", info->id);
        ret = sc_start_recorder(sc, NULL);
        if (ret < 0) {
            goto service_accquired_cleanup;
        }
    }
#endif // #if defined(__MTV_REC_SUPPORT__)

service_accquired_cleanup:
    if (ret >= 0)
    {
        sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_READY, MTV_S_OK, sc->session_id);
    }
    else
    {
        /*
         * Stop the service for the possible following cases:
         *   - unsupport decoder
         *   - unsupport audio/video format
         *   - no audio/video streams can be found
         */
        mtv_zapping_trace(MOD_MED, "[MTV][esid:%d][ZAPPING] stop service..", info->id);
        ret = sm_stop_service(pthis, sc, ret);
    }
}

static void sm_on_event(mtv_spi_client_t* client, mtv_spi_event_t event, kal_uint32 param)
{
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);

    MTV_TRACE(TRACE_INFO, MTV_TRC_SERVICE_EVENT, event);

    switch (event)
    {
    case MTV_SPI_SERVICE_ACQUIRED:
        {
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) param;
            sm_on_service_acquired(pthis, info);
        }
        break;

    case MTV_SPI_SERVICE_UPDATED:
        {
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) param;
            mtv_service_context_t* sc;

            sc = sm_update_service_context(pthis, info);
            if (sc) {
                sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_UPDATED, MTV_S_OK, sc->session_id);
            }
        }
        break;

#if defined(__MED_MTV_MOD__)
    case MTV_SPI_SERVICE_UPDATE:
        {
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) param;
            sm_on_service_updated(pthis, info);
        }
        break;

    case MTV_SPI_RECEPTION_QUALITY:

        MTV_TRACE(TRACE_INFO, MTV_TRC_RECEPTION_QUALITY, param);
        {
            mtv_service_context_t* sc = sm_find_service_by_state(pthis, MTV_SERVICE_STATE_READY);

            if (IS_ACCEPTABLE_QUALITY(pthis->rq.quality) == IS_ACCEPTABLE_QUALITY(param)) {
                pthis->rq.stable++;
            }
            else {
                pthis->rq.stable = 1;
            }
            pthis->rq.quality = (mtv_spi_reception_quality_t)param;

            if (IS_ACCEPTABLE_QUALITY(pthis->rq.quality) && pthis->rq.stable == 2)
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_RECEPTION_BETTER, pthis->rq.dropped);

                if (sc) {
                    sc->reception_state = MTV_RECEPTION_STATE_GOOD;
                    sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_GOOD_RECEPTION, param, sc->session_id);
                }
            }
            else if (!IS_ACCEPTABLE_QUALITY(pthis->rq.quality) && pthis->rq.stable == 1)
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_RECEPTION_WORSE);

                if (sc) {
                    sc->reception_state = MTV_RECEPTION_STATE_BAD;
                    sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_BAD_RECEPTION, param, sc->session_id);
                }
            }
        }
        break;

    case MTV_SPI_SERVICE_ADDED:
        {
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) param;
            mtv_service_context_t* sc;

            sc = sm_add_service_context(pthis, info);
            if (sc) {
                sm_callback_with_sc(pthis, sc, MTV_SERVICE_EVENT_ADDED, MTV_S_OK, sc->session_id);
            }
        }
        break;

    case MTV_SPI_SERVICE_ABORTED:
        {
            kal_uint32 service_id = param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

            if (sc)
            {
                sc->state = MTV_SERVICE_STATE_ABORTED;
                sm_callback_with_id(pthis, service_id, MTV_SERVICE_EVENT_ABORTED, (kal_uint32) MTV_E_ABORTED, sc->session_id);
            }
        }
        break;

    case MTV_SPI_SERVICE_REMOVED:
        {
            kal_uint32 service_id = param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

            if (sc)
            {
                sc->state = MTV_SERVICE_STATE_REMOVED;
                sm_callback_with_id(pthis, service_id, MTV_SERVICE_EVENT_REMOVED, MTV_S_OK, sc->session_id);
            }
        }
        break;

    case MTV_SPI_SERVICE_ACCESS_DENIED:
        {
            kal_uint32 service_id = param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

            if (sc &&
                sc->reception_state == MTV_RECEPTION_STATE_GOOD &&
                sc->ca_state == MTV_SERVICE_CA_STATE_ACCESS_GRANTED)
            {
                sc->ca_state = MTV_SERVICE_CA_STATE_ACCESS_DENIED;
                sm_callback_with_id(pthis, service_id, MTV_SERVICE_EVENT_ACCESS_DENIED, MTV_S_OK, sc->session_id);
            }
        }
        break;

    case MTV_SPI_EMERGENCY_MSG_ARRIVED:

        sm_callback(pthis, MTV_SERVICE_EVENT_EMERGENCY_MSG, 0);
        break;

    case MTV_SPI_FATAL_ERROR:

        sm_callback(pthis, MTV_SERVICE_EVENT_FATAL_ERROR, 0);
        break;
#endif

    case MTV_SPI_SEARCH_PROGRESS:
        {
            kal_uint32 percentage = param;
            sm_callback(pthis, MTV_SERVICE_EVENT_SEARCH_PROGRESS, percentage);
        }
        break;

    case MTV_SPI_LIVE_SEARCH_DONE:
        {
            const kal_wchar* setting_dir = mtv_get_setting_dir();
            pthis->spi->save_service_list(pthis->spi, setting_dir);
        }
        break;

    case MTV_SPI_CLOSED:

        pthis->spi->destroy(pthis->spi);
        pthis->spi = NULL;
        sm_callback(pthis, MTV_SERVICE_EVENT_CLOSED, MTV_S_OK);
        break;

#ifdef __CMMB_SUPPORT__
    case MTV_SPI_ESG_UPDATED:
        sm_callback(pthis, MTV_SERVICE_EVENT_ESG_UPDATED, MTV_S_OK);
        break;

    case MTV_SPI_ESG_DOWNLOADED:
        sm_callback(pthis, MTV_SERVICE_EVENT_ESG_DOWNLOADED, MTV_S_OK);
        break;

    case MTV_SPI_ESG_NEW_AVAILABLE:
        sm_callback(pthis, MTV_SERVICE_EVENT_ESG_NEW_AVAILABLE, MTV_S_OK);
        break;

    case MTV_SPI_SG_UPDATE_RET:
        sm_callback(pthis, MTV_SERVICE_EVENT_SG_UPDATE_RET, param);
        break;

    case MTV_SPI_UPGRADE_RET:
        sm_callback(pthis, MTV_SERVICE_EVENT_UPGRADE_RET, param);
        break;

    case MTV_SPI_INTERACTIVITY_RETRIEVE_RET:
        sm_callback(pthis, MTV_SERVICE_EVENT_INTERACTIVITY_RETRIEVE_RET, param);
        break;

    case MTV_SPI_IMD_READY:
        sm_callback(pthis, MTV_SERVICE_EVENT_IMD_READY, param);
        break;

    case MTV_SPI_AREA_RETRIEVE_DATA:
        sm_callback(pthis, MTV_SERVICE_EVENT_AREA_RETRIEVE_DATA, param);
        break;

    case MTV_SPI_AREA_RETRIEVE_RET:
        sm_callback(pthis, MTV_SERVICE_EVENT_AREA_RETRIEVE_RET, param);
        break;

    case MTV_SPI_GBA_RET:
        if (pthis->init_state != MTV_INIT_STATE_IDLE)
        {
            pthis->hold_evt = MTV_SERVICE_EVENT_GBA_RET;
            pthis->hold_param = param;
            pthis->init_state = MTV_INIT_STATE_HOLD_EVT;
            MTV_TRACE(TRACE_INFO, MTV_TRC_SM_INIT_STATE, pthis->init_state, pthis->hold_evt, pthis->hold_param);
        }
        else
        {
            sm_callback(pthis, MTV_SERVICE_EVENT_GBA_RET, param);
        }
        break;

    case MTV_SPI_SUBSCRIPTION_UPDATE_RET:

        if (pthis->init_state != MTV_INIT_STATE_IDLE)
        {
            pthis->hold_evt = MTV_SERVICE_EVENT_SUBSCRIPTION_UPDATE_RET;
            pthis->hold_param = param;
            pthis->init_state = MTV_INIT_STATE_HOLD_EVT;
            MTV_TRACE(TRACE_INFO, MTV_TRC_SM_INIT_STATE, pthis->init_state, pthis->hold_evt, pthis->hold_param);
        }
        else
        {
            sm_callback_with_id(pthis, 0, MTV_SERVICE_EVENT_SUBSCRIPTION_UPDATE_RET, param, pthis->seq_no);
        }
        break;

    case MTV_SPI_PRE_TUNE_START:
        MTV_TRACE(TRACE_INFO, MTV_TRC_SM_INIT_STATE, pthis->init_state, pthis->hold_evt, pthis->hold_param);

        ASSERT(pthis->init_state == MTV_INIT_STATE_IDLE);
        pthis->init_state = MTV_INIT_STATE_PRE_TUNE;
        break;

    case MTV_SPI_PRE_TUNE_DONE:
        MTV_TRACE(TRACE_INFO, MTV_TRC_SM_INIT_STATE, pthis->init_state, pthis->hold_evt, pthis->hold_param);

        if (pthis->init_state == MTV_INIT_STATE_HOLD_EVT)
        {
            if (pthis->hold_evt == MTV_SERVICE_EVENT_GBA_RET)
            {
                sm_callback(pthis, pthis->hold_evt, pthis->hold_param);
            }
            else if (pthis->hold_evt == MTV_SERVICE_EVENT_SUBSCRIPTION_UPDATE_RET)
            {
                sm_callback_with_id(pthis, 0, pthis->hold_evt, pthis->hold_param, pthis->seq_no);
            }
        }
        pthis->init_state = MTV_INIT_STATE_IDLE;
        break;

    case MTV_SPI_ACCOUNT_INQUIRY_DATA:
        sm_callback(pthis, MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DATA, param);
        break;

    case MTV_SPI_ACCOUNT_INQUIRY_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_ACCOUNT_INQUIRY_DONE, param);
        break;

    case MTV_SPI_SUBSCRIBE_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_SUBSCRIBE_DONE, param);
        break;

    case MTV_SPI_UNSUBSCRIBE_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_UNSUBSCRIBE_DONE, param);
        break;
    case MTV_SPI_MSK_RETRIEVE_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_MSK_RETRIEVE_DONE, param);
        break;

    case MTV_SPI_SET_EMM_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_SET_EMM_DONE, param);
        break;

    case MTV_SPI_GET_CA_DONE:
        sm_callback(pthis, MTV_SERVICE_EVENT_GET_CA_DONE, param);
        break;

#endif /* __CMMB_SUPPORT__ */

    default:
        NOT_REACHED("Unhandled event!");
		break;
    }
}

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

static mtv_result_t sm_set_service_param(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_param_t param, kal_uint32 value)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    mtv_prompt_trace(MOD_MED, "[MTV] sm_set_service_param(id[%d], param[%d])", service_id, param);

    /* don't need service context parameters */
    switch (param)
    {
    case MTV_SERVICE_PARAM_PAUSE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_PAUSE, value);
        return ret;

    case MTV_SERVICE_PARAM_RESUME:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_RESUME, value);
        return ret;

#if defined(__MED_MTV_MOD__)
    case MTV_SERVICE_PARAM_EMM_INFO:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_EMM_INFO, value);
        return ret;
    case MTV_SERVICE_PARAM_CA_INFO:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_CA_INFO, value);
        return ret;
    case MTV_SERVICE_PARAM_SUBSCRIBE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_SUBSCRIBE, value);
        return ret;
    case MTV_SERVICE_PARAM_UNSUBSCRIBE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_UNSUBSCRIBE, value);
        return ret;
    case MTV_SERVICE_PARAM_ACCOUNT_INQUIRY:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_ACCOUNT_INQUIRY, value);
        return ret;
    case MTV_SERVICE_PARAM_UPGRADE_QUERY:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_UPGRADE_QUERY, value);
        return ret;
    case MTV_SERVICE_PARAM_AREA_SET_RETRIEVE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_AREA_SET_RETRIEVE, value);
        return ret;
    case MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_INTERACTIVITY_RETRIEVE, value);
        return ret;
    case MTV_SERVICE_PARAM_DOWNLOAD_SG:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_DOWNLOAD_SG, value);
        return ret;
    case MTV_SERVICE_PARAM_UPDATE_SG:
        if (sm_is_any_service_started(pthis))
        {
            /* servic searching is mutually exclusive with service receiving. */
            return MTV_E_RESOURCE_CONFLICT;
        }
        /* free existing list */
        sm_free_service_context_list(pthis);
        pthis->notify_service = KAL_FALSE;
        pthis->init_state = MTV_INIT_STATE_IDLE;
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_UPDATE_SG, value);
        return ret;
    case MTV_SERVICE_PARAM_SIM_INFO:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_SIM_INFO, value);
        return ret;
    case MTV_SERVICE_PARAM_NET_INFO:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_NET_INFO, value);
        return ret;
    case MTV_SERVICE_PARAM_GBA:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_GBA, value);
        return ret;
    case MTV_SERVICE_PARAM_SUBSCRIPTION_UPDATE:
        pthis->seq_no = value;
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_SUBSCRIPTION_UPDATE, value);
        return ret;
    case MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTION_UPDATE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_CANCEL_SUBSCRIPTION_UPDATE, value);
        return ret;
    case MTV_SERVICE_PARAM_MSK_RETRIEVE:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_MSK_RETRIEVE, value);
        return ret;
    case MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_PURIFY_PROG_REMINDER, value);
        return ret;
    case MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED:
        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED, value);
        return ret;
#endif // #if defined(__MED_MTV_MOD__)

    default:
        break;
    }

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_FAIL;
    }

    switch (param)
    {
    case MTV_SERVICE_PARAM_NAME:
        {
            const kal_wchar* str = (const kal_wchar*)value;

            /* over-write service info of service context */
            kal_wstrncpy(sc->info.name, str, MTV_MAX_SERVICE_NAME);

            ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_NAME, value);
        }
        break;

    case MTV_SERVICE_PARAM_DISABLE:

        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_DISABLE, value);

        break;

    case MTV_SERVICE_PARAM_AUDIO_MODE:

        ret = pthis->spi->set_param(pthis->spi, service_id, MTV_SPI_SERVICE_PARAM_AUDIO_MODE, value);

        break;

    default:
        return MTV_E_INVALID_PARAM;
    }

    return ret;
}

void construct_mtv_sm(mtv_sm_t* pthis)
{
    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->open = sm_open;
    pthis->config = sm_config;
    pthis->search_services = sm_search_services;
    pthis->abort_searching = sm_abort_searching;
    pthis->start_service = sm_start_service;
    pthis->start_player = sm_start_player;
    pthis->stop_player = sm_stop_player;
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    pthis->restart_chip = atv_sm_restart_chip;  
#endif
#if defined(__MED_MTV_MOD__)
    pthis->pause_visual_update = sm_pause_visual_update;
    pthis->resume_visual_update = sm_resume_visual_update;
#endif
    pthis->snapshot = sm_snapshot;
    pthis->get_player_status = sm_get_player_status;

    pthis->get_control = sm_get_control;
    pthis->get_service_param = sm_get_service_param;
    pthis->set_service_param = sm_set_service_param;
    pthis->get_service_context = sm_get_service_context;
    pthis->stop_service = sm_stop_service_by_id;
    pthis->get_media_info = sm_get_media_info;
    pthis->close = sm_close;

#if defined(__MTV_REC_SUPPORT__)
    pthis->find_unsaved_recording = sm_find_unsaved_recording;
    pthis->recover_recording = sm_recover_recording;
    pthis->abort_recovering = sm_abort_recovering;
    pthis->discard_unsaved_recording = sm_discard_unsaved_recording;

    pthis->start_recorder = sm_start_recorder;
    pthis->stop_recorder = sm_stop_recorder;
    pthis->pause_recorder = sm_pause_recorder;
    pthis->resume_recorder = sm_resume_recorder;
    pthis->prepare_saving = sm_prepare_saving;
    pthis->save_recording = sm_save_recording;
    pthis->abort_saving = sm_abort_saving;
    pthis->recorder_discard_recording = sm_recorder_discard_recording;
    pthis->get_recorder_state = sm_get_recorder_state;
#endif //#if defined(__MTV_REC_SUPPORT__)

#if defined(__MTV_TS_SUPPORT__)
    pthis->start_timeshift = sm_start_timeshift;
#endif //#if defined(__MTV_TS_SUPPORT__)

#if defined(__MED_MTV_MOD__)
    pthis->esg_download = sm_esg_download;
    pthis->esg_abort_downloading = sm_esg_abort_downloading;
    pthis->esg_query = sm_esg_query;
    pthis->esg_get_result = sm_esg_get_result;
    pthis->esg_query_finish = sm_esg_query_finish;
    pthis->esg_add_favorite = sm_esg_add_favorite;
    pthis->esg_del_favorite = sm_esg_del_favorite;
    pthis->esg_free_result_buffer = sm_esg_free_result_buffer;
    pthis->esg_get_qe_state = sm_esg_get_qe_state;

    pthis->ca_get_card_info = sm_ca_get_card_info;

    pthis->esg_qe_state = MTV_ESG_QUERY_STATE_CLOSED;

    pthis->spi_client.on_audio_au = sm_on_audio_au;
    pthis->spi_client.on_video_au = sm_on_video_au;
    pthis->spi_client.on_data_au = sm_on_data_au;
#endif //#if defined(__MED_MTV_MOD__)

    pthis->spi_client.on_service = sm_on_service;
    pthis->spi_client.on_event = sm_on_event;
}
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
mtv_result_t atv_sm_restart_chip(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 session_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    //  step 1: stop player
    sm_stop_player(sm,service_id);
    // step 2:  restart chip
    pthis->spi->restart_chip(pthis->spi, service_id);
    sc = sm_find_service_by_id(sm, service_id);
    sc->state = MTV_SERVICE_STATE_STARTED;
    //  step 3: start player
    sm_start_player(sm,service_id,session_id);

    return MTV_S_OK;
}
#endif

#endif /* defined(__MED_MTV_MOD__) */
