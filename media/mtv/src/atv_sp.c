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
 *   atv_sp.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "med_global.h"

#if defined(__MED_ATV_MOD__)

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

#include "stack_config.h"
#include "stack_ltlcom.h"

#include "med_utility.h"
#include "med_trc.h"

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#include "mtv_spi.h"
#include "atv_sp.h"

#include "atv_api.h"

#include "app_str.h"
#include "cal_api.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MEDMTV_ROCODE", rodata = "DYNAMIC_CODE_MEDMTV_RODATA"
#endif

#define ATV_SERVICE_DB_NAME        L"atv.sdb"
#define ATV_SERVICE_DB_VER         1
#define ATV_SERVICE_DB_SIGNATURE   MAKE_FOURCC('C','H','D','B')

#define RETURN_E(err) \
    MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, err, __LINE__); \
    return err

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
static mtv_result_t atv_sp_close_core(atv_sp_t* self);
#endif

/**
  * ATV load db action.
  */
typedef enum
{
    DB_LOAD_ACT_SCAN,
    DB_LOAD_ACT_FIND_AND_DISABLE,
    DB_LOAD_ACT_FIND_AND_RENAME
} db_load_act_enum;

typedef enum
{
    ATV_EVENT_SERVICE_READY,
    ATV_EVENT_SERVICE_AUDIO_CHANGE,

    ATV_EVENT_END
} atv_event_enum;

typedef struct
{
    kal_uint32 signature;
    kal_uint32 version;
    kal_uint32 flags;
    kal_uint32 reserved;

} atv_sp_service_db_header_t;

typedef struct
{
    mtv_spi_service_info_t spi;
    atv_ch_info ch_info;
    kal_bool valid;
} atv_sp_service_info_t;

static mtv_result_t atv_sp_set_param(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value);

static void atv_sp_set_state(atv_sp_t* self, atv_sp_state_t new_state)
{
    self->state = new_state;
    MTV_TRACE(TRACE_STATE, MTV_TRC_SP_STATE, new_state);
}

static void send_atv_sp_msg(kal_uint16 msg_id, void* local_param_ptr)
{
    module_type src_mod_id = stack_get_active_module_id();
    ilm_struct* ilm = allocate_ilm(src_mod_id);

    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = INVALID_SAP;
    ilm->dest_mod_id = MOD_MED;
    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;

    msg_send_ext_queue(ilm);
}

static void atv_sp_send_scan_progress_ind(atv_sp_t* self, kal_uint8 percentage, kal_uint8 ch_num)
{
    CONSTRUCT_LOCAL_PARAM(media_atv_scan_progress_ind_struct, req);

    self->scan_progress = percentage;

    req->context = (kal_uint32)self;
    req->percentage = percentage;
    req->ch_num = ch_num;

    send_atv_sp_msg(MSG_ID_MEDIA_ATV_SCAN_PROGRESS_IND, req);
}

static void atv_sp_send_event_ind(atv_sp_t* self, kal_uint32 event, kal_uint32 param)
{
    CONSTRUCT_LOCAL_PARAM(media_atv_event_ind_struct, req);

    req->context = (kal_uint32)self;
    req->event = event;
    req->param = param;

    send_atv_sp_msg(MSG_ID_MEDIA_ATV_EVENT_IND, req);
}

static void atv_reset_service_context(atv_service_context_t* sc)
{
    sc->state = ATV_SERVICE_STOPPED;
}

static void atv_reset_all_services(atv_sp_t* self)
{
    atv_reset_service_context(&self->curr_srv);
}


static kal_bool atv_sp_is_service_started(atv_service_context_t* sc)
{
    kal_bool ret;

    ret = (sc->state != ATV_SERVICE_STOPPED) ? KAL_TRUE : KAL_FALSE;

    return ret;
}

static atv_service_context_t* atv_sp_find_service_context(atv_sp_t* self, kal_uint32 sid)
{
    /* find specified service slot */
    if (atv_sp_is_service_started(&self->curr_srv) && self->curr_srv.sid == sid)
    {
        return &self->curr_srv;
    }

    return NULL;
}

static atv_service_context_t* atv_find_empty_service_context(atv_sp_t* self)
{
    if (!atv_sp_is_service_started(&self->curr_srv)) {
        return &self->curr_srv;
    }

    return NULL;
}

static atv_service_context_t* atv_find_active_service_context(atv_sp_t* self)
{
    if (atv_sp_is_service_started(&self->curr_srv)) {
        return &self->curr_srv;
    }

    return NULL;
}

static void atv_sp_autoscan_progress_cb(void* cb_param, kal_uint8 percentage, kal_uint8 ch, kal_uint8 chnum)
{
    atv_sp_t* self = (atv_sp_t*)cb_param;

    if ((self->state == ATV_SP_STATE_SCANNING) &&
        (self->scan_progress < percentage) &&
        (percentage > 0) &&
        (percentage < 100))
    {
        atv_sp_send_scan_progress_ind(self, percentage, 0);
    }
}

static void atv_sp_fullscan_progress_cb(void *cb_param, kal_uint8 percentage, kal_uint32 freq,
                                     kal_uint32 freq_start, kal_uint32 freq_end)
{
    atv_sp_t* self = (atv_sp_t*)cb_param;

    if ((self->state == ATV_SP_STATE_SCANNING) &&
        (self->scan_progress < percentage) &&
        (percentage > 0) &&
        (percentage < 100))
    {
        atv_sp_send_scan_progress_ind(self, percentage, 0);
    }
}

static void atv_sp_scanfinish_cb(void *cb_param, kal_uint8 chnum)
{
    atv_sp_t* self = (atv_sp_t*)cb_param;

    /* send 100% progress */
    if (self->state == ATV_SP_STATE_SCANNING)
    {
        atv_sp_send_scan_progress_ind(self, 100, chnum);
    }
}

static void atv_sp_audioformat_cb(void *cb_param, kal_uint32 format)
{
    atv_sp_t* self = (atv_sp_t*)cb_param;

    if (self->state == ATV_SP_STATE_OPENED)
    {
        atv_sp_send_event_ind(self, ATV_EVENT_SERVICE_AUDIO_CHANGE, format);
    }
}


static void atv_sp_fill_service_info(mtv_spi_service_info_t* info, kal_uint32 sid,
                                    kal_uint32 audio_mode, kal_uint32 audio_flags, kal_uint32 freq)
{
    kal_int32 value;

    kal_mem_set(info, 0, sizeof(mtv_spi_service_info_t));

    info->id = sid;

    kal_wsprintf(info->name, "Channel %d", sid);

    info->number = sid;
    info->type = MTV_SPI_SERVICE_ANALOG_TV;
    info->flags = MTV_SPI_SERVICE_CLEAR_TO_AIR;     // mtv_spi_service_flag_t
    info->freq = freq;

    info->num_components = 2;
    info->components[0].type = MTV_SPI_COMPONENT_AUDIO;
    info->components[0].mode = audio_mode;
    info->components[0].flags = audio_flags;

    /* it's a trick for I2S and LINEIN, because they are with same struct in the union. */
    ATV_GetAudioParam(ATV_AUD_CHANNEL_NUM, &value);
    info->components[0].dec_config.u.i2s.channels = (kal_uint16)value;
    ATV_GetAudioParam(ATV_AUD_BITS_PER_SAMPLE, &value);
    info->components[0].dec_config.u.i2s.bits_per_sample = (kal_uint16)value;
    ATV_GetAudioParam(ATV_AUD_SAMPLING_RATE, &value);
    info->components[0].dec_config.u.i2s.sample_rate = (kal_uint32)value;

    ATV_GetAudioParam(ATV_AUD_TYPE, &value);
    if (value == ATV_AUD_TYPE_I2S)
    {
        info->components[0].dec_config.codec = MTV_CODEC_I2S;
    }
    else if (value == ATV_AUD_TYPE_LINEIN)
    {
        info->components[0].dec_config.codec = MTV_CODEC_LINEIN;
    }
    else
    {
        ASSERT(0);
    }

    info->components[1].type = MTV_SPI_COMPONENT_VIDEO;
}

static void atv_live_scan_done(atv_sp_t* self)
{
    atv_ch_info ch_info;
    mtv_spi_service_info_t *info;

    kal_uint32 i = 1, found = 1;
    info = (mtv_spi_service_info_t*) mtv_alloc_ext_mem(sizeof(mtv_spi_service_info_t), MAKE_FOURCC('S','P','I','F'));

    while ((ATV_GetChannelTable(i, &ch_info) == KAL_TRUE) && (found <= MTV_MAX_SERVICE_NUM))
    {
        if (ch_info.valid == KAL_TRUE)
        {
            atv_sp_fill_service_info(info, i, 0, 0, ch_info.freq);
            MTV_TRACE(TRACE_FUNC, MTV_TRC_SP_SERVICE_FOUND, info->id, info->type, info->flags, info->num_components);
            self->client->on_service(self->client, info);
            found++;
        }
        i++;
    }

    mtv_free_ext_mem((void**)&info);

    /* MTV_SPI_LIVE_SEARCH_DONE for save service list by sm */
    self->client->on_event(self->client, MTV_SPI_LIVE_SEARCH_DONE, self->scan_aborted);
}

static mtv_result_t atv_on_scan_progress_ind(atv_sp_t* self, media_atv_scan_progress_ind_struct* param)
{
    mtv_result_t ret = MTV_S_COMPLETE;
    kal_uint32 percentage = param->percentage;

    if (self->state == ATV_SP_STATE_SCANNING)
    {
        if (param->percentage > 100)
        {
            percentage = 100;
        }

        if (param->percentage == 100)
        {
            atv_sp_set_state(self, ATV_SP_STATE_OPENED);

            atv_live_scan_done(self);
        }

        self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, percentage);


        ret = MTV_S_OK;
    }

    return ret;
}

static kal_uint32 atv_sp_set_audio_mode(kal_uint32 selected_audio_mode, kal_uint32 supported_audio_mode)
{
    kal_uint32 prefer_audio_mode = 0xFFFFFFFF;

    if (selected_audio_mode & supported_audio_mode)
    {
        prefer_audio_mode = selected_audio_mode;
    }
    else
    {
        if (supported_audio_mode & ATV_API_AUDIO_MASK_MTS)
        {
            prefer_audio_mode = ATV_API_MTS_MONO;
        }
        else if (supported_audio_mode & ATV_API_AUDIO_MASK_NICAM)
        {
            prefer_audio_mode = ATV_API_NICAM_MONO;
        }
        else if (supported_audio_mode & ATV_API_AUDIO_MASK_A2)
        {
            prefer_audio_mode = ATV_API_FMRDO_MONO;
        }
        else if (supported_audio_mode & ATV_API_AUDIO_MASK_FM)
        {
            prefer_audio_mode = ATV_API_FM_MONO;
        }
        else if (supported_audio_mode & ATV_API_AUDIO_MASK_FMRDO)
        {
            prefer_audio_mode = ATV_API_FMRDO_MONO;
        }
        else
        {
            ASSERT(0);
        }
    }

    ATV_SetAudioFormat(prefer_audio_mode);

    return prefer_audio_mode;
}

static mtv_result_t atv_on_event(atv_sp_t* self, media_atv_event_ind_struct* ind)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_spi_service_info_t* info;
    kal_uint32 supported_audio_mode, curr_audio_mode;
    atv_service_context_t* sc = atv_find_active_service_context(self);

    if (sc == NULL)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, MTV_E_FAIL, __LINE__);
        return MTV_E_FAIL;
    }

    info = (mtv_spi_service_info_t*) mtv_alloc_ext_mem(sizeof(mtv_spi_service_info_t), MAKE_FOURCC('S','P','I','F'));

    switch (ind->event)
    {
    case ATV_EVENT_SERVICE_READY:
    case ATV_EVENT_SERVICE_AUDIO_CHANGE:
        supported_audio_mode = ATV_GetAudioFormat();
        /* query/set prefer audio mode */
        curr_audio_mode = atv_sp_set_audio_mode(self->selected_audio_mode, supported_audio_mode);

        atv_sp_fill_service_info(info, sc->sid, curr_audio_mode, supported_audio_mode, sc->freq);

        if (ind->event == ATV_EVENT_SERVICE_READY)
        {
            /* notify the client about service info */
            self->client->on_event(self->client, MTV_SPI_SERVICE_ACQUIRED, (kal_uint32) info);
            /* Note that the service may be stopped in ACQUIRED callback. Check whether the state is still in STARTED here. */
            if (sc->state == ATV_SERVICE_STARTED) {
                sc->state = ATV_SERVICE_READY;
            }
        }
        else
        {
            self->client->on_event(self->client, MTV_SPI_SERVICE_UPDATED, (kal_uint32) info);
        }

        break;

    default:
        ASSERT(0);
        break;
    }

    mtv_free_ext_mem((void**)&info);

    return ret;
}

static MM_ERROR_CODE_ENUM atv_sp_cam_preview_callback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /* mATV should not enter this callback. */
    ASSERT(0);

    return MM_ERROR_INVALID_PARAMETER;
}

static void atv_sp_cal_open(void)
{
    CAL_FEATURE_CTRL_STRUCT CalInParam;

    #ifdef __MM_DCM_SUPPORT__
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    #endif

    // select mATV sensor
    CalInParam.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
    CalInParam.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInParam.FeatureSetValue = (kal_uint32)CAL_CAMERA_SOURCE_MATV;
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInParam, NULL, 0, NULL);

    CalOpen(atv_sp_cam_preview_callback);
}

static void atv_sp_cal_close(void)
{
    CalClose();

    #ifdef __MM_DCM_SUPPORT__
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    #endif

}

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
mtv_result_t atv_sp_open_core(mtv_spi_t* spi)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    kal_bool matv_ret;
    ATV_RegisterCallback((void*)self, atv_sp_autoscan_progress_cb, atv_sp_fullscan_progress_cb,
                                atv_sp_scanfinish_cb, atv_sp_audioformat_cb);
    
    matv_ret = ATV_PowerOn();
    if (matv_ret == KAL_FALSE)
    {
        mtv_zapping_trace(MOD_MED, "[ATV][SP] matv_init fail!!");
        RETURN_E(MTV_E_RESOURCE_CONFLICT);
    }

    atv_sp_cal_open();

    /* reset service context */
    atv_reset_all_services(self);
    self->service_paused = KAL_FALSE;
    self->selected_audio_mode = ATV_DEFAULT_MODE;

    mtv_zapping_trace(MOD_MED, "[ATV][SP] opened)");
    atv_sp_set_state(self, ATV_SP_STATE_OPENED);
    return MTV_S_OK;

}
#endif



/* Service Provider public methods */
static mtv_result_t atv_sp_open(mtv_spi_t* spi, mtv_spi_client_t* client, void *param)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    kal_bool matv_ret;

    if (self->state != ATV_SP_STATE_CLOSED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    self->client = client;
    self->db_dir = NULL;

    ATV_RegisterCallback((void*)self, atv_sp_autoscan_progress_cb, atv_sp_fullscan_progress_cb,
                            atv_sp_scanfinish_cb, atv_sp_audioformat_cb);

    matv_ret = ATV_PowerOn();
    if (matv_ret == KAL_FALSE)
    {
        mtv_zapping_trace(MOD_MED, "[ATV][SP] matv_init fail!!");
        RETURN_E(MTV_E_RESOURCE_CONFLICT);
    }

    atv_sp_cal_open();

    /* reset service context */
    atv_reset_all_services(self);
    self->service_paused = KAL_FALSE;
    self->selected_audio_mode = ATV_DEFAULT_MODE;

    mtv_zapping_trace(MOD_MED, "[ATV][SP] opened)");
    atv_sp_set_state(self, ATV_SP_STATE_OPENED);

    return MTV_S_OK;
}

static mtv_result_t atv_sp_search_services_core(atv_sp_t* self)
{
    mtv_result_t ret;

    /* check if in supported country list */
    if (MTV_FREQ_ATV_BEGIN <= self->band_to_scan && self->band_to_scan <= MTV_FREQ_ATV_END)
    {
        kal_uint8 country = (kal_uint8)(ATV_API_COUNTRY_START + (self->band_to_scan - MTV_FREQ_ATV_BEGIN));

        self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 0);

        if (g_mtv_atv_default_chlist == KAL_TRUE)
        {
            ATV_Scan(country, ATV_QUICKSCAN);
        }
        else
        {
            ATV_Scan(country, ATV_AUTOSCAN);
        }

        ret = MTV_S_OK;
    }
    else
    {
        ret = MTV_E_INVALID_PARAM;
    }

    return ret;
}

static mtv_result_t atv_sp_search_services(mtv_spi_t* spi, mtv_freq_band_t band, void *param)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    if (self->state != ATV_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    atv_sp_set_state(self, ATV_SP_STATE_SCANNING);

    self->band_to_scan = band;
    self->scan_progress = 0;
    self->scan_aborted = KAL_FALSE;

    ret = atv_sp_search_services_core(self);

    if (ret < 0)
    {
        /* scan failed, back to opened state */
        atv_sp_set_state(self, ATV_SP_STATE_OPENED);
    }

    return ret;
}

static mtv_result_t atv_sp_abort_searching(mtv_spi_t* spi)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_FUNC, MTV_TRC_SP_ABORT_SEARCHING, self->state);

    if (self->state == ATV_SP_STATE_SCANNING)
    {
        self->scan_aborted = KAL_TRUE;

        ATV_StopScan(); /* async function, maybe lost 1 ch before scanfinish cb arrived. */

        atv_sp_set_state(self, ATV_SP_STATE_OPENED);
        /* save ch list */
        atv_live_scan_done(self);
        /* send 100 to trigger update ch list */
        self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 100);

        ret = MTV_S_OK;

    }
    else
    {
        ret = MTV_S_FALSE;
    }

    return ret;
}

static mtv_result_t atv_sp_save_service_db(atv_sp_t* self, const kal_wchar* dir)
{
    kal_int32 fserr;
    kal_uint32 i, found = 1;
    mtv_result_t ret = MTV_S_OK;
    atv_sp_service_db_header_t header;
    atv_ch_info ch_info;
    atv_sp_service_info_t* atv_info;
    kal_wchar* fname = mtv_alloc_filename();
    FS_HANDLE fh;

    atv_info = (atv_sp_service_info_t*) mtv_alloc_ext_mem(sizeof(atv_sp_service_info_t), MAKE_FOURCC('A','T','I','F'));

    kal_wstrcpy(fname, dir);
    kal_wstrcat(fname, ATV_SERVICE_DB_NAME);
    fh = FS_Open(fname, FS_READ_WRITE | FS_CREATE_ALWAYS);
    mtv_free_ext_mem((void**) &fname);
    if (fh < 0)
    {
        ret = (mtv_result_t)mtv_error_from_fs(fh);
        goto cleanup;
    }

    /* write file header */
    header.signature = ATV_SERVICE_DB_SIGNATURE;
    header.version = ATV_SERVICE_DB_VER;
    header.flags = 0;
    header.reserved = 0;

    fserr = FS_Write(fh, &header, sizeof(header), NULL);
    if (fserr < 0)
    {
        ret = (mtv_result_t)mtv_error_from_fs(fserr);
        goto cleanup;
    }

    i = 1;
    while ((ATV_GetChannelTable(i, &ch_info) == KAL_TRUE) && (found <= MTV_MAX_SERVICE_NUM))
    {
        if (ch_info.valid == KAL_TRUE)
        {
            mtv_zapping_trace(MOD_MED, "[ATV][SP] ch[%d] valid... line[%d]", i, __LINE__);
            atv_sp_fill_service_info(&atv_info->spi, i, 0, 0, ch_info.freq);
            kal_mem_cpy(&atv_info->ch_info, &ch_info, sizeof(atv_ch_info));
            atv_info->valid = KAL_TRUE;

            fserr = FS_Write(fh, atv_info, sizeof(atv_sp_service_info_t), NULL);
            if (fserr < 0)
            {
                ret = (mtv_result_t)mtv_error_from_fs(fserr);
                goto cleanup;
            }
            found++;
        }

        i++;
    }

cleanup:
    mtv_free_ext_mem((void**) &atv_info);
    if (fh >= 0)
    {
        FS_Close(fh);
    }

    return ret;
}

static mtv_result_t atv_sp_save_service_list(mtv_spi_t* spi, const kal_wchar* dir)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    if (self->state != ATV_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    if (g_mtv_atv_default_chlist == KAL_TRUE)
    {
        return MTV_S_OK;
    }

    self->db_dir = dir;

    /* save service list into specified directory */
    ret = atv_sp_save_service_db(self, dir);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
    }

    return ret;
}

static mtv_result_t atv_sp_load_service_db(atv_sp_t* self, const kal_wchar* dir,
                                            db_load_act_enum act, kal_uint32 sid, kal_uint32 param)
{
    mtv_result_t ret = MTV_S_OK;
    kal_int32 fserr;
    kal_uint32 len;
    atv_sp_service_db_header_t header;
    atv_sp_service_info_t* atv_info;
    kal_uint32 curr_pos;
    kal_wchar* fname = mtv_alloc_filename();
    kal_bool matv_ret;
    FS_HANDLE fh;

    atv_info = (atv_sp_service_info_t*) mtv_alloc_ext_mem(sizeof(atv_sp_service_info_t), MAKE_FOURCC('A','T','I','F'));

    kal_wstrcpy(fname, dir);
    kal_wstrcat(fname, ATV_SERVICE_DB_NAME);

    fh = FS_Open(fname, FS_READ_WRITE);

    mtv_free_ext_mem((void**) &fname);
    if (fh < 0)
    {
        ret = (mtv_result_t)mtv_error_from_fs(fh);
        goto cleanup;
    }

    /* read file header */
    fserr = FS_Read(fh, &header, sizeof(header), &len);
    if (fserr < 0)
    {
        ret = (mtv_result_t)mtv_error_from_fs(fserr);
        goto cleanup;
    }
    else if (len != sizeof(header))
    {
        ret = MTV_E_NO_MORE_DATA;
        goto cleanup;
    }
    else if (header.signature != ATV_SERVICE_DB_SIGNATURE || header.version != ATV_SERVICE_DB_VER)
    {
        ret = MTV_E_CORRUPTED_DATA;
        goto cleanup;
    }
    else
    {
        switch (act)
        {
        case DB_LOAD_ACT_SCAN:

            /* clear ch table*/
            matv_ret = ATV_ClearChannelTable();

            /* load service list */
            self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 0);
            do
            {
                fserr = FS_Read(fh, atv_info, sizeof(atv_sp_service_info_t), &len);

                if ((fserr >= 0) &&
                    (len == sizeof(atv_sp_service_info_t)) &&
                    (atv_info->valid == KAL_TRUE)) // ignore invalid service
                {
                    mtv_zapping_trace(MOD_MED, "[ATV][SP] matv_set_chtable...ch[%d] line[%d])", atv_info->spi.id, __LINE__);
                    matv_ret = ATV_SetChannelTable(atv_info->spi.id, &atv_info->ch_info);
                    if (matv_ret)
                    {
                        MTV_TRACE(TRACE_FUNC, MTV_TRC_SP_SERVICE_FOUND, atv_info->spi.id, atv_info->spi.type, atv_info->spi.flags, atv_info->spi.num_components);
                        self->client->on_service(self->client, &atv_info->spi);
                    }
                    else
                    {
                        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, matv_ret, __LINE__);
                    }
                }

            }while (fserr >= 0 && len == sizeof(atv_sp_service_info_t));

            self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 100);

            break;

        case DB_LOAD_ACT_FIND_AND_DISABLE:
        case DB_LOAD_ACT_FIND_AND_RENAME:
            ret = MTV_E_FAIL;
            do
            {
                FS_GetFilePosition(fh, &curr_pos);
                fserr = FS_Read(fh, atv_info, sizeof(atv_sp_service_info_t), &len);

                if ((fserr >= 0) &&
                    (len == sizeof(atv_sp_service_info_t)) &&
                    (atv_info->spi.id == sid))
                {
                    if (atv_info->valid == KAL_TRUE)
                    {
                        if (act == DB_LOAD_ACT_FIND_AND_DISABLE)
                        {
                            atv_info->valid = KAL_FALSE;
                        }
                        else if (act == DB_LOAD_ACT_FIND_AND_RENAME)
                        {
                            kal_wstrncpy(atv_info->spi.name, (const kal_wchar*)param, MTV_MAX_SERVICE_NAME);
                        }
                        fserr = FS_Seek(fh, curr_pos, FS_FILE_BEGIN);
                        fserr = FS_Write(fh, atv_info, sizeof(atv_sp_service_info_t), NULL);
                    }
                    ret = MTV_S_OK;

                    break;
                }
            }while (fserr >= 0 && len == sizeof(atv_sp_service_info_t));

            break;

        default:
            ret = MTV_E_INVALID_PARAM;
            break;
        }

    }

cleanup:

    mtv_free_ext_mem((void**) &atv_info);
    if (fh >= 0)
    {
        FS_Close(fh);
    }
    return ret;
}

static mtv_result_t atv_sp_load_service_list(mtv_spi_t* spi, const kal_wchar* dir, mtv_freq_band_t band, void *param)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    if (self->state != ATV_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    self->db_dir = dir;

    /* enter SCANNING state as real scanning */
    atv_sp_set_state(self, ATV_SP_STATE_SCANNING);

    ret = atv_sp_load_service_db(self, dir, DB_LOAD_ACT_SCAN, 0, 0);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
    }

    /* back to OPENED state even loading service list failed */
    atv_sp_set_state(self, ATV_SP_STATE_OPENED);

    return ret;
}

/**
  * private function to select/start a analog tv channel.
  */
static mtv_result_t atv_sp_start_service_core(atv_sp_t* self, kal_uint32 sid)
{
    mtv_result_t ret = MTV_S_OK;
    kal_bool matv_ret;
    atv_service_context_t* sc;
    atv_ch_info ch_info;
//    kal_uint32 supported_audio_mode, curr_audio_mode;

    sc = atv_sp_find_service_context(self, sid);
    if (sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_STARTED_ALREADY, sid);
        return MTV_SPI_E_ALREADY_STARTED;
    }

    /* allocate service context */
    sc = atv_find_empty_service_context(self);
    if (!sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_NO_EMPTY_SC, sid);
        return MTV_SPI_E_NO_MORE_SERVICE;
    }

    matv_ret = ATV_GetChannelTable(sid, &ch_info);
    if ((matv_ret != KAL_TRUE) || (ch_info.valid == KAL_FALSE))
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_FAIL_TO_GET_SERVICE_INFO, sid);
        return MTV_E_FAIL;
    }

    /* command demod to start the service */
    ATV_ChangeChannel(sid);

    sc->sid = sid;
    sc->freq = ch_info.freq;
    sc->state = ATV_SERVICE_STARTED;

    self->selected_audio_mode = ATV_DEFAULT_MODE;

    /* a trick to simulate demod service ready */
    {
        atv_sp_send_event_ind(self, ATV_EVENT_SERVICE_READY, 0);
    }

    return ret;
}

/**
  * pubic function to start a TV service.
  */
static mtv_result_t atv_sp_start_service(mtv_spi_t* spi, kal_uint32 sid)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    if (self->state != ATV_SP_STATE_OPENED)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_WASNOT_OPENED, sid);
        return MTV_E_WRONG_STATE;
    }

    /* start specified service */
    ret = atv_sp_start_service_core(self, sid);

    return ret;
}

/**
  * To release all resources after a service is stopped or aborted.
  */
static void atv_sp_close_service_context(atv_service_context_t* sc)
{
    atv_reset_service_context(sc);
}

/**
  * private function to stop a service including TV, EMM, and ESG sevice.
  */
static mtv_result_t atv_sp_stop_service_core(atv_sp_t* self, kal_uint32 sid)
{
    atv_service_context_t* sc;

    /* find specified service slot */
    sc = atv_sp_find_service_context(self, sid);
    if (!sc) {
        RETURN_E(MTV_S_FALSE); /* the service is already stopped */
    }

    atv_sp_close_service_context(sc);

    return MTV_S_OK;
}

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
void atv_sp_restart_chip(mtv_spi_t* spi, kal_uint32 sid)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    kal_bool matv_ret;

    // step 1: stop service
    //atv_sp_stop_service(sp_save, sid_save);
    // steep 2 : poweroff chip
    atv_sp_close_core(self);
    kal_sleep_task(100);
    //  step 3: poweron chip
    atv_sp_open_core(spi);
    //  step 4: start service
    atv_sp_start_service(spi, sid);
}
#endif

/**
  * public fuction to stop a TV service.
  */
static mtv_result_t atv_sp_stop_service(mtv_spi_t* spi, kal_uint32 sid)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret;

    if (self->state != ATV_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    /* stop specified service first */
    ret = atv_sp_stop_service_core(self, sid);

    return ret;
}

static mtv_result_t atv_sp_get_status(mtv_spi_t* spi, mtv_spi_status_t* status)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret = MTV_S_OK;
    kal_int32 signal_strength = 100;

    if (self->service_paused == KAL_TRUE)
    {
        status->signal_strength = self->last_signal_strength;
    }
    else
    {
        // matv_get_signal_status
        signal_strength = ATV_GetSignalStrength();

        status->signal_strength = signal_strength * MTV_SPI_MAX_SIGNAL_STRENGTH / ATV_MAX_SIGNAL_STRENGTH;
    }

    return ret;
}


static mtv_result_t atv_sp_get_param(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value)
{
    mtv_result_t ret = MTV_S_OK;

    switch (param)
    {
    case MTV_SPI_SERVICE_PARAM_VIDEO_MODE:
        {
            atv_video_color_system_t video_cs;

            video_cs = (atv_video_color_system_t)ATV_GetVideoColorSystem();
            if (video_cs == ATV_SV_CS_NTSC)
            {
                *((kal_uint32*)value) = ATV_VIDEO_NTSC;
            }
            else if (video_cs == ATV_SV_CS_PAL)
            {
                *((kal_uint32*)value) = ATV_VIDEO_PAL;
            }

        }
        break;

    default:
        ret = MTV_E_INVALID_PARAM;
        break;
    }

    return ret;
}

static mtv_result_t atv_sp_stop_started_services(atv_sp_t* self)
{
    mtv_result_t ret = MTV_S_OK;

    if (atv_sp_is_service_started(&self->curr_srv))
    {
        ret = atv_sp_stop_service_core(self, self->curr_srv.sid);
    }

    return ret;
}

static mtv_result_t atv_sp_close_core(atv_sp_t* self)
{
    mtv_result_t ret;

    ret = atv_sp_stop_started_services(self);

    atv_sp_cal_close();

    ATV_PowerOff();

    return ret;
}

static mtv_result_t atv_sp_close(mtv_spi_t* spi)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);

    if (self->state == ATV_SP_STATE_SCANNING)
    {
        ATV_StopScan();
    }

    atv_sp_close_core(self);

    atv_sp_set_state(self, ATV_SP_STATE_CLOSED);
    self->client->on_event(self->client, MTV_SPI_CLOSED, 0);

    return MTV_S_OK;
}

static void atv_sp_destroy(mtv_spi_t* spi)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_free_ext_mem((void**) &self);
}

mtv_spi_t* construct_atv_sp(void)
{
    atv_sp_t* self = (atv_sp_t*) mtv_alloc_ext_mem(sizeof(*self), MAKE_FOURCC('T','V','S','P'));

    self->itf.open = atv_sp_open;
    self->itf.search_services = atv_sp_search_services;
    self->itf.abort_searching = atv_sp_abort_searching;
    self->itf.save_service_list = atv_sp_save_service_list;
    self->itf.load_service_list = atv_sp_load_service_list;
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    self->itf.restart_chip = atv_sp_restart_chip;
#endif

    self->itf.start_service = atv_sp_start_service;
    self->itf.stop_service = atv_sp_stop_service;
    self->itf.get_status = atv_sp_get_status;
    self->itf.set_param = atv_sp_set_param;
    self->itf.get_param = atv_sp_get_param;
    self->itf.close = atv_sp_close;
    self->itf.destroy = atv_sp_destroy;

    self->on_scan_progress_ind = atv_on_scan_progress_ind;
    self->on_event = atv_on_event;

    self->client = NULL;
    atv_sp_set_state(self, ATV_SP_STATE_CLOSED);

    return &self->itf;
}

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

static mtv_result_t atv_sp_set_param(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value)
{
    atv_sp_t* self = PTHIS(spi, atv_sp_t, itf);
    mtv_result_t ret = MTV_S_OK;

    switch (param)
    {
    case MTV_SPI_SERVICE_PARAM_PAUSE:
        {
            self->service_paused = KAL_TRUE;
            atv_sp_cal_close();
            ATV_PowerOff();
        }
        break;

    case MTV_SPI_SERVICE_PARAM_RESUME:
        {
            atv_service_context_t* sc = atv_find_active_service_context(self);

            self->service_paused = KAL_FALSE;

            ATV_RegisterCallback((void*)self, atv_sp_autoscan_progress_cb, atv_sp_fullscan_progress_cb,
                            atv_sp_scanfinish_cb, atv_sp_audioformat_cb);
            ATV_PowerOn();
            atv_sp_cal_open();

            if (sc)
            {
                ATV_ChangeChannel(sc->sid);
            }
            else
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, 0, __LINE__);
            }
        }
        break;

    case MTV_SPI_SERVICE_PARAM_DISABLE:
    case MTV_SPI_SERVICE_PARAM_NAME:
        if (self->db_dir)
        {
            if (param == MTV_SPI_SERVICE_PARAM_DISABLE)
            {
                atv_sp_load_service_db(self, self->db_dir, DB_LOAD_ACT_FIND_AND_DISABLE, service_id, value);
            }
            else
            {
                atv_sp_load_service_db(self, self->db_dir, DB_LOAD_ACT_FIND_AND_RENAME, service_id, value);
            }
        }
        else
        {
            ret = MTV_E_INVALID_PARAM;
        }
        break;

    case MTV_SPI_SERVICE_PARAM_AUDIO_MODE:
        self->selected_audio_mode = value;
        atv_sp_set_audio_mode(self->selected_audio_mode, ATV_GetAudioFormat());

        break;

    default:
        ret = MTV_E_INVALID_PARAM;
        break;
    }

    UNUSED(self);

    return ret;
}

#endif /* defined(__MED_ATV_MOD__) */
