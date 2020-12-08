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
 *   camera_sp.c
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

#if defined(__ATV_CAMERA_SIM_SUPPORT__)

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

#include "stack_config.h"
#include "stack_ltlcom.h"

#include "med_utility.h"
#include "med_trc.h"
#include "med_struct.h"     // for media_mtv_atv_audio_mode_enum
#include "mtv_spi.h"
#include "camera_sp.h"

#include "app_str.h"

#define CAMERA_SERVICE_MAX_CH_NUM     (10)
#define CAMERA_SERVICE_DB_NAME         L"camera.sdb"
#define CAMERA_SERVICE_DB_VER         (1)
#define CAMERA_SERVICE_DB_SIGNATURE   MAKE_FOURCC('C','H','D','B')

#define SP_CHANGE_STATE(s,v) \
    s = v; \
    MTV_TRACE(TRACE_STATE, MTV_TRC_SP_STATE, s)

#define RETURN_E(err) \
    MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, err, __LINE__); \
    return err

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

#define MSG_STRUCT(type, name, ilm) \
    type* name  = (type*) ilm->local_para_ptr

#define AUDIO_MASK_MTS      (ATV_MTS_MONO | ATV_MTS_STEREO | ATV_MTS_SAP)
#define AUDIO_MASK_MPX      (ATV_MPX_MONO | ATV_MPX_STEREO | ATV_MPX_SUB | ATV_MPX_MAIN_SUB |ATV_MPX_MAIN)
#define AUDIO_MASK_FM       (ATV_FM_MONO)
#define AUDIO_MASK_A2       (ATV_A2_STEREO | ATV_A2_DUAL1 | ATV_A2_DUAL2)
#define AUDIO_MASK_NICAM    (ATV_NICAM_MONO | ATV_NICAM_STEREO | ATV_NICAM_DUAL1 | ATV_NICAM_DUAL2)
#define AUDIO_MASK_FMRDO    (ATV_FMRDO_MONO | ATV_FMRDO_STEREO)

#define CAMERA_MAX_SIGNAL_STRENGTH    (100)

/**
  * Camera load db action.
  */
typedef enum
{
    DB_LOAD_ACT_SCAN,
    DB_LOAD_ACT_FIND_AND_DISABLE,
    DB_LOAD_ACT_FIND_AND_RENAME
} db_load_act_enum;

typedef enum
{
    CAMERA_EVENT_SERVICE_READY,
    CAMERA_EVENT_SERVICE_AUDIO_CHANGE,

    CAMERA_EVENT_END
} camera_event_enum;


typedef enum
{
    ATV_SOUND_SYSTEM_MTS = 0,
    ATV_SOUND_SYSTEM_MPX = 1,
    ATV_SOUND_SYSTEM_A2 = 2,
    ATV_SOUND_SYSTEM_NICAM = 3,
    ATV_SOUND_SYSTEM_FMRDO = 4

} atv_sound_system_t;

#define CAMERA_CURRENT_SOUND_SYSTEM (ATV_SOUND_SYSTEM_MTS) // refer to atv_sound_system_t

typedef struct
{
    kal_uint32 sid;                    /**< external service ID */
    kal_uint32 audio_mode;                 /**< frequency point */
    kal_uint32 audio_flags;                 /**< frequency point */
    kal_uint32 freq;

} mcamera_service_t;

typedef struct
{
    kal_uint32 signature;
    kal_uint32 version;
    kal_uint32 flags;
    kal_uint32 reserved;

} camera_sp_service_db_header_t;

typedef struct
{
    mtv_spi_service_info_t spi;
    kal_bool valid;
} camera_sp_service_info_t;

static void send_camera_sp_msg(kal_uint16 msg_id, void* local_param_ptr)
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

static kal_bool camera_sp_is_service_started(camera_service_context_t* sc)
{
    return (sc->state != CAMERA_SERVICE_STOPPED);
}

static camera_service_context_t* camera_sp_find_service_context(camera_sp_t* self, kal_uint32 sid)
{
    kal_int32 i;

    /* find specified service slot */
    for (i = 0; i < ARRAY_SIZE(self->services); i++)
    {
        if (camera_sp_is_service_started(&self->services[i]) && self->services[i].sid == sid)
        {
            return &self->services[i];
        }
    }

    return NULL;
}

static camera_service_context_t* camera_find_empty_service_context(camera_sp_t* self)
{
    kal_int32 i;

    /* find specified service slot */
    for (i = 0; i < ARRAY_SIZE(self->services); i++)
    {
        if (!camera_sp_is_service_started(&self->services[i])) {
            return &self->services[i];
        }
    }

    return NULL;
}

static camera_service_context_t* camera_find_active_service_context(camera_sp_t* self)
{
    kal_int32 i;

    /* find specified service slot */
    for (i = 0; i < ARRAY_SIZE(self->services); i++)
    {
        if (camera_sp_is_service_started(&self->services[i])) {
            return &self->services[i];
        }
    }

    return NULL;
}

static void camera_autoscan_progress_cb(void* cb_param, kal_uint8 percentage, kal_uint8 ch, kal_uint8 chnum)
{
    camera_sp_t* self = (camera_sp_t*)cb_param;

    if ((self->state == CAMERA_SP_STATE_SCANNING) &&
        (self->scan_progress < percentage) &&
        (percentage > 0) &&
        (percentage < 100))
    {
        CONSTRUCT_LOCAL_PARAM(media_camera_scan_progress_ind_struct, req);

        self->scan_progress = percentage;

        req->context = (kal_uint32)self;
        req->percentage = percentage;
        req->ch_num = 0;
        send_camera_sp_msg(MSG_ID_MEDIA_CAMERA_SCAN_PROGRESS_IND, req);
    }
}

static void camera_scanfinish_cb(void *cb_param, kal_uint8 chnum)
{
    camera_sp_t* self = (camera_sp_t*)cb_param;

    /* send 100% progress */
    if (self->state == CAMERA_SP_STATE_SCANNING)
    {
        CONSTRUCT_LOCAL_PARAM(media_camera_scan_progress_ind_struct, req);

        self->scan_progress = 100;

        req->context = (kal_uint32)self;
        req->percentage = 100;
        req->ch_num = chnum;

        send_camera_sp_msg(MSG_ID_MEDIA_CAMERA_SCAN_PROGRESS_IND, req);
    }
}

static kal_uint32 camera_sp_get_audio_mode(atv_sound_system_t system)
{
    kal_uint32 ret;

    switch (system)
    {
    case ATV_SOUND_SYSTEM_MTS:
        ret = (ATV_MTS_MONO | ATV_MTS_STEREO | ATV_MTS_SAP);
        break;

    case ATV_SOUND_SYSTEM_MPX:
        ret = (ATV_MPX_MONO | ATV_MPX_STEREO | ATV_MPX_SUB);
        break;

    case ATV_SOUND_SYSTEM_A2:
        ret = (ATV_FM_MONO | ATV_A2_STEREO| ATV_A2_DUAL1);
        break;

    case ATV_SOUND_SYSTEM_NICAM:
        ret = (ATV_NICAM_MONO | ATV_NICAM_STEREO| ATV_NICAM_DUAL1);
        break;

    case ATV_SOUND_SYSTEM_FMRDO:
        ret = (ATV_FMRDO_MONO | ATV_FMRDO_STEREO);
        break;

    default:
        ret = (ATV_MTS_MONO | ATV_MTS_STEREO | ATV_MTS_SAP);
        break;
    }

    return ret;
}

static kal_uint32 camera_sp_set_prefer_audio_mode(kal_uint32 audio_format)
{
    kal_uint32 prefer_audio_mode = 0xFFFFFFFF;
    if (audio_format & AUDIO_MASK_MTS)
    {
        /* MTS SYSTEM */
        prefer_audio_mode = ATV_MTS_MONO;
    }
    else if (audio_format & AUDIO_MASK_NICAM)
    {
        /* NICAM, DUAL1 > STEREO > MONO */
        if (audio_format & ATV_NICAM_DUAL1)
        {
            prefer_audio_mode = ATV_NICAM_DUAL1;
        }
        else if (audio_format & ATV_NICAM_STEREO)
        {
            prefer_audio_mode = ATV_NICAM_STEREO;
        }
        else if (audio_format & ATV_NICAM_MONO)
        {
            prefer_audio_mode = ATV_NICAM_MONO;
        }
    }
    else if (audio_format & AUDIO_MASK_A2)
    {
        /* A2, DUAL1 > STEREO*/
        if (audio_format & ATV_A2_DUAL1)
        {
            prefer_audio_mode = ATV_A2_DUAL1;
        }
        else if (audio_format & ATV_A2_STEREO)
        {
            prefer_audio_mode = ATV_A2_STEREO;
        }
    }
    else if (audio_format & AUDIO_MASK_FM)
    {
        /* FM, MONO only (NICAM & A2 first) */
        if (audio_format & ATV_FM_MONO)
        {
            prefer_audio_mode = ATV_FM_MONO;
        }
    }
    else if (audio_format & AUDIO_MASK_FMRDO)
    {
        /* FMRDO, STEREO > MONO */
        if (audio_format & ATV_FMRDO_STEREO)
        {
            prefer_audio_mode = ATV_FMRDO_STEREO;
        }
        else if (audio_format & ATV_FMRDO_MONO)
        {
            prefer_audio_mode = ATV_FMRDO_MONO;
        }
    }

    ASSERT(prefer_audio_mode != 0xFFFFFFFF);

    return prefer_audio_mode;
}

static void camera_sp_fill_service_info(mtv_spi_service_info_t* info, kal_uint32 sid,
                                    kal_uint32 audio_mode, kal_uint32 audio_flags, kal_uint32 freq)
{
    kal_mem_set(info, 0, sizeof(mtv_spi_service_info_t));

    info->id = sid;

    kal_mem_set(info->name, 0, sizeof(info->name));
    kal_wsprintf(info->name, "Channel %d", sid + 1);

    info->number = sid;
    info->type = MTV_SPI_SERVICE_ANALOG_TV;
    info->flags = MTV_SPI_SERVICE_CLEAR_TO_AIR;     // mtv_spi_service_flag_t
    info->freq = freq;

    info->num_components = 2;
    info->components[0].type = MTV_SPI_COMPONENT_AUDIO;
    info->components[0].mode = audio_mode;
    info->components[0].flags = audio_flags;

    info->components[1].type = MTV_SPI_COMPONENT_VIDEO;
}

static void camera_live_scan_done(camera_sp_t* self)
{
    kal_uint32 i;

    for (i = 0; i < CAMERA_SERVICE_MAX_CH_NUM; i++)
    {
        mtv_spi_service_info_t info;

        camera_sp_fill_service_info(&info, i, camera_sp_get_audio_mode(ATV_SOUND_SYSTEM_MTS), ATV_MTS_MONO, i);
        MTV_TRACE(TRACE_FUNC, MTV_TRC_SP_SERVICE_FOUND, info.id, info.type, info.flags, info.num_components);
        self->client->on_service(self->client, &info);
    }
    /* MTV_SPI_LIVE_SEARCH_DONE for save service list by sm */
    self->client->on_event(self->client, MTV_SPI_LIVE_SEARCH_DONE, self->scan_aborted);
}

static mtv_result_t camera_on_scan_progress_ind(camera_sp_t* self, media_camera_scan_progress_ind_struct* param)
{
    mtv_result_t ret = MTV_S_COMPLETE;
    kal_uint32 percentage = param->percentage;

    if (self->state == CAMERA_SP_STATE_SCANNING)
    {
        if (param->percentage > 100)
        {
            percentage = 100;
        }

        if (param->percentage == 100)
        {
            SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_OPENED);
            camera_live_scan_done(self);
        }

        self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, percentage);

        ret = MTV_S_OK;
    }

    return ret;
}

static mtv_result_t camera_on_event(camera_sp_t* self, media_camera_event_ind_struct* ind)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_spi_service_info_t info;
    kal_uint32 supported_audio_mode, curr_audio_mode;
    camera_service_context_t* sc = camera_find_active_service_context(self);

    ASSERT(sc);

    switch (ind->event)
    {
    case CAMERA_EVENT_SERVICE_READY:

        /* query/set prefer audio mode */
        supported_audio_mode = camera_sp_get_audio_mode(CAMERA_CURRENT_SOUND_SYSTEM);
        ASSERT(supported_audio_mode != 0);
        curr_audio_mode = camera_sp_set_prefer_audio_mode(supported_audio_mode);

        camera_sp_fill_service_info(&info, sc->sid, curr_audio_mode, supported_audio_mode, sc->freq);

        /* notify the client about service info */
        self->client->on_event(self->client, MTV_SPI_SERVICE_ACQUIRED, (kal_uint32) &info);

        /* Note that the service may be stopped in ACQUIRED callback. Check whether the state is still in STARTED here. */
        if (sc->state == CAMERA_SERVICE_STARTED) {
            sc->state = CAMERA_SERVICE_READY;
        }
        else
        {
            ret = MTV_E_WRONG_STATE;
            MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
        }

        break;

    case CAMERA_EVENT_SERVICE_AUDIO_CHANGE:

        supported_audio_mode = camera_sp_get_audio_mode(CAMERA_CURRENT_SOUND_SYSTEM);
        ASSERT(supported_audio_mode != 0);
        curr_audio_mode = camera_sp_set_prefer_audio_mode(supported_audio_mode);

        camera_sp_fill_service_info(&info, sc->sid, curr_audio_mode, supported_audio_mode, sc->freq);

        /* notify the client about service info */
        self->client->on_event(self->client, MTV_SPI_SERVICE_UPDATED, (kal_uint32) &info);
        if (sc->state != CAMERA_SERVICE_READY)
        {
            ret = MTV_E_WRONG_STATE;
            MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
        }

        break;

    default:
        ASSERT(0);
        break;
    }

    return ret;
}

/* Service Provider public methods */
static mtv_result_t camera_sp_open(mtv_spi_t* spi, mtv_spi_client_t* client, void *param)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);

    if (self->state != CAMERA_SP_STATE_CLOSED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }
    if (client == NULL) {
        RETURN_E(MTV_E_INVALID_PARAM);
    }

    self->client = client;
    self->db_dir = NULL;

    /* suspend matv to free camera bus, only resume it when start service. */
    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_OPENED);

    return MTV_S_OK;
}

static mtv_result_t camera_sp_get_esg_interface(mtv_spi_t* spi, mtv_spi_esg_t** esg)
{
    *esg = NULL;
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t camera_sp_get_ca_interface(mtv_spi_t* spi, mtv_spi_ca_t** ca)
{
    *ca = NULL;
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t camera_sp_search_services_core(camera_sp_t* self)
{
    mtv_result_t ret;

    /* check if in supported country list */
    /* atv simulator */
    if (MTV_FREQ_ATV_BEGIN <= self->band_to_scan && self->band_to_scan <= MTV_FREQ_ATV_END)
    {
        self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 0);

        camera_autoscan_progress_cb(self, 50, 0, 1);
        camera_scanfinish_cb(self, 1);

        ret = MTV_S_OK;
    }
    else
    {
        ret = MTV_E_INVALID_PARAM;
    }

    return ret;
}

static mtv_result_t camera_sp_search_services(mtv_spi_t* spi, mtv_freq_band_t band, void *param)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;

    if (self->state == CAMERA_SP_STATE_SCANNING) {
        RETURN_E(MTV_E_RESOURCE_CONFLICT); /* searching in progress */
    }
    else if (self->state != CAMERA_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_SCANNING);

    self->band_to_scan = band;
    self->scan_progress = 0;
    self->scan_aborted = KAL_FALSE;

    ret = camera_sp_search_services_core(self);

    if (ret < 0)
    {
        /* scan failed, back to opened state */
        SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_OPENED);
    }

    return ret;
}

static mtv_result_t camera_sp_abort_searching(mtv_spi_t* spi)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_FUNC, MTV_TRC_SP_ABORT_SEARCHING, self->state);

    if (self->state == CAMERA_SP_STATE_SCANNING)
    {
        self->scan_aborted = KAL_TRUE;

        SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_OPENED);
        camera_live_scan_done(self);
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

static mtv_result_t camera_sp_save_service_db(camera_sp_t* self, const kal_wchar* dir, FS_HANDLE* fh)
{
    kal_int32 fserr;
    kal_uint32 i;
    mtv_result_t ret;
    camera_sp_service_db_header_t header;
    kal_wchar* fname = mtv_alloc_filename();

    kal_wstrcpy(fname, dir);
    kal_wstrcat(fname, CAMERA_SERVICE_DB_NAME);
    *fh = FS_Open(fname, FS_READ_WRITE | FS_CREATE_ALWAYS);
    mtv_free_ext_mem((void**) &fname);
    if (*fh < 0)
    {
        ret = mtv_error_from_fs(*fh);
        goto cleanup;
    }

    /* write file header */
    header.signature = CAMERA_SERVICE_DB_SIGNATURE;
    header.version = CAMERA_SERVICE_DB_VER;
    header.flags = 0;
    header.reserved = 0;

    fserr = FS_Write(*fh, &header, sizeof(header), NULL);
    if (fserr < 0)
    {
        ret = mtv_error_from_fs(fserr);
        goto cleanup;
    }

    for (i = 0; i < CAMERA_SERVICE_MAX_CH_NUM; i++)
    {
        camera_sp_service_info_t info;

        camera_sp_fill_service_info(&info.spi, i, 0, 0, i);
        info.valid = KAL_TRUE;

        fserr = FS_Write(*fh, &info, sizeof(info), NULL);
        if (fserr < 0)
        {
            ret = mtv_error_from_fs(fserr);
            goto cleanup;
        }
    }

    return MTV_S_OK;

cleanup:

    if (*fh >= 0)
    {
        FS_Close(*fh);
        *fh = -1;
    }
    RETURN_E(ret);
}

static mtv_result_t camera_sp_save_service_list(mtv_spi_t* spi, const kal_wchar* dir)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;
    FS_HANDLE fh;

    if (self->state != CAMERA_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    self->db_dir = dir;

    /* save service list into specified directory */
    ret = camera_sp_save_service_db(self, dir, &fh);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
    }

    if (fh >= 0) {
        FS_Close(fh);
    }
    return ret;
}

static mtv_result_t camera_sp_load_service_db(camera_sp_t* self, const kal_wchar* dir, FS_HANDLE* fh,
                                            db_load_act_enum act, kal_uint32 sid, kal_uint32 param)
{
    mtv_result_t ret;
    kal_int32 fserr;
    kal_uint32 len;
    camera_sp_service_db_header_t header;
    camera_sp_service_info_t info;
    kal_uint32 curr_pos;
    kal_wchar* fname = mtv_alloc_filename();

    kal_wstrcpy(fname, dir);
    kal_wstrcat(fname, CAMERA_SERVICE_DB_NAME);
    if (act == DB_LOAD_ACT_SCAN)
    {
        *fh = FS_Open(fname, FS_READ_ONLY);
    }
    else
    {
        *fh = FS_Open(fname, FS_READ_WRITE);
    }
    mtv_free_ext_mem((void**) &fname);
    if (*fh < 0)
    {
        ret = mtv_error_from_fs(*fh);
        goto cleanup;
    }

    /* read file header */
    fserr = FS_Read(*fh, &header, sizeof(header), &len);
    if (fserr < 0)
    {
        ret = mtv_error_from_fs(fserr);
        goto cleanup;
    }
    else if (len != sizeof(header))
    {
        ret = MTV_E_NO_MORE_DATA;
        goto cleanup;
    }
    else if (header.signature != CAMERA_SERVICE_DB_SIGNATURE || header.version != CAMERA_SERVICE_DB_VER)
    {
        ret = MTV_E_CORRUPTED_DATA;
        goto cleanup;
    }
    else
    {
        ret = MTV_S_OK;

        switch (act)
        {
        case DB_LOAD_ACT_SCAN:

            /* load service list */
            self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 0);
            do
            {
                fserr = FS_Read(*fh, &info, sizeof(info), &len);

                if ((fserr >= 0) &&
                    (len == sizeof(info)) &&
                    (info.valid == KAL_TRUE)) // ignore invalid service
                {
                    self->client->on_service(self->client, &info.spi);
                }

            }while (fserr >= 0 && len == sizeof(info));
            self->client->on_event(self->client, MTV_SPI_SEARCH_PROGRESS, 100);

            break;
        case DB_LOAD_ACT_FIND_AND_DISABLE:
            ret = MTV_E_FAIL;
            do
            {
                FS_GetFilePosition(*fh, &curr_pos);
                fserr = FS_Read(*fh, &info, sizeof(info), &len);

                if ((fserr >= 0) &&
                    (len == sizeof(info)) &&
                    (info.spi.id == sid))
                {
                    if (info.valid == KAL_TRUE)
                    {
                        info.valid = KAL_FALSE;
                        fserr = FS_Seek(*fh, curr_pos, FS_FILE_BEGIN);
                        fserr = FS_Write(*fh, &info, sizeof(camera_sp_service_info_t), NULL);
                    }
                    ret = MTV_S_OK;

                    break;
                }
            }while (fserr >= 0 && len == sizeof(info));

            break;

        case DB_LOAD_ACT_FIND_AND_RENAME:
            ret = MTV_E_FAIL;
            do
            {
                FS_GetFilePosition(*fh, &curr_pos);
                fserr = FS_Read(*fh, &info, sizeof(info), &len);

                if ((fserr >= 0) &&
                    (len == sizeof(info)) &&
                    (info.spi.id == sid))
                {
                    if (info.valid == KAL_TRUE)
                    {
                        kal_wstrncpy(info.spi.name, (const kal_wchar*)param, MTV_MAX_SERVICE_NAME);
                        fserr = FS_Seek(*fh, curr_pos, FS_FILE_BEGIN);
                        fserr = FS_Write(*fh, &info, sizeof(info), NULL);
                    }
                    ret = MTV_S_OK;

                    break;
                }
            }while (fserr >= 0 && len == sizeof(info));

            break;

        default:
            ret = MTV_E_INVALID_PARAM;
            break;
        }

    }

cleanup:

    if (*fh >= 0)
    {
        FS_Close(*fh);
        *fh = -1;
    }
    return ret;
}

static mtv_result_t camera_sp_load_service_list(mtv_spi_t* spi, const kal_wchar* dir, mtv_freq_band_t band, void *param)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;
    FS_HANDLE fh;

    if (self->state != CAMERA_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    self->db_dir = dir;

    /* enter SCANNING state as real scanning */
    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_SCANNING);

    ret = camera_sp_load_service_db(self, dir, &fh, DB_LOAD_ACT_SCAN, 0, 0);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_ERROR, ret, __LINE__);
    }

    if (fh >= 0) {
        FS_Close(fh);
    }

    /* back to OPENED state even loading service list failed */
    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_OPENED);

    return ret;
}

/**
  * private function to select/start a analog tv channel.
  */
static mtv_result_t camera_sp_start_service_core(camera_sp_t* self, kal_uint32 sid)
{
    camera_service_context_t* sc;

    sc = camera_sp_find_service_context(self, sid);
    if (sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_STARTED_ALREADY, sid);
        return MTV_SPI_E_ALREADY_STARTED;
    }

    /* allocate service context */
    sc = camera_find_empty_service_context(self);
    if (!sc)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_NO_EMPTY_SC, sid);
        return MTV_SPI_E_NO_MORE_SERVICE;
    }

    sc->sid = sid;
    sc->sp = self;
    sc->freq = sid;
    sc->state = CAMERA_SERVICE_STARTED;

    kal_get_time(&sc->start_time);

    /* a trick to simulate demod service ready */
    {
        CONSTRUCT_LOCAL_PARAM(media_camera_event_ind_struct, req);

        req->context = (kal_uint32)self;
        req->event = CAMERA_EVENT_SERVICE_READY;
        req->param = 0;

        send_camera_sp_msg(MSG_ID_MEDIA_CAMERA_EVENT_IND, req);
    }

    return MTV_S_OK;
}

/**
  * pubic function to start a TV service.
  */
static mtv_result_t camera_sp_start_service(mtv_spi_t* spi, kal_uint32 sid)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;

    if (self->state == CAMERA_SP_STATE_SCANNING)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_CANNOT_START_WHILE_SEARCHING, sid);
        RETURN_E(MTV_E_RESOURCE_CONFLICT);
    }
    else if (self->state != CAMERA_SP_STATE_OPENED)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_SP_WASNOT_OPENED, sid);
        RETURN_E(MTV_E_WRONG_STATE);
    }

    /* start specified service */
    ret = camera_sp_start_service_core(self, sid);

    return ret;
}

static void camera_reset_service_context(camera_service_context_t* sc)
{
    kal_mem_set(sc->streams, 0, sizeof(sc->streams));

    sc->num_streams = 0;
    sc->start_time = 0;

    sc->sp = NULL; /* mark this context as free */
    sc->state = CAMERA_SERVICE_STOPPED;
}

/**
  * To release all resources after a service is stopped or aborted.
  */
static void camera_sp_close_service_context(camera_service_context_t* sc)
{
    camera_reset_service_context(sc);
}

/**
  * private function to stop a service including TV, EMM, and ESG sevice.
  */
static mtv_result_t camera_sp_stop_service_core(camera_sp_t* self, kal_uint32 sid)
{
    camera_service_context_t* sc;

    /* find specified service slot */
    sc = camera_sp_find_service_context(self, sid);
    if (!sc) {
        RETURN_E(MTV_S_FALSE); /* the service is already stopped */
    }

    camera_sp_close_service_context(sc);

    return MTV_S_OK;
}

/**
  * public fuction to stop a TV service.
  */
static mtv_result_t camera_sp_stop_service(mtv_spi_t* spi, kal_uint32 sid)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret;

    if (self->state != CAMERA_SP_STATE_OPENED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    /* stop specified service first */
    ret = camera_sp_stop_service_core(self, sid);

    return ret;
}

static mtv_result_t camera_sp_get_status(mtv_spi_t* spi, mtv_spi_status_t* status)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret = MTV_S_OK;
    kal_uint32 signal_strength = 100;

    status->signal_strength = signal_strength * MTV_SPI_MAX_SIGNAL_STRENGTH / CAMERA_MAX_SIGNAL_STRENGTH;

    return ret;
}

static mtv_result_t camera_sp_set_param(mtv_spi_t* spi, kal_uint32 service_id, mtv_spi_service_param_t param, kal_uint32 value)
{
    FS_HANDLE fh;
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_result_t ret = MTV_S_OK;

    mtv_prompt_trace(MOD_MED, "[ATV] camera_sp_set_param(id[%d], param[%d])", service_id, param);

    switch (param)
    {
    case MTV_SPI_SERVICE_PARAM_DISABLE:
        if (self->db_dir)
        {
            ret = camera_sp_load_service_db(self, self->db_dir, &fh, DB_LOAD_ACT_FIND_AND_DISABLE, service_id, value);
        }
        else
        {
            mtv_prompt_trace(MOD_MED, "[ATV] set param fail, no db!!)");
            ret = MTV_E_INVALID_PARAM;
        }
        break;

    case MTV_SPI_SERVICE_PARAM_NAME:
        if (self->db_dir)
        {
            ret = camera_sp_load_service_db(self, self->db_dir, &fh, DB_LOAD_ACT_FIND_AND_RENAME, service_id, value);
        }
        else
        {
            mtv_prompt_trace(MOD_MED, "[ATV] set param fail, no db!!)");
            ret = MTV_E_INVALID_PARAM;
        }
        break;

    default:
        ret = MTV_E_INVALID_PARAM;
        break;
    }

    mtv_prompt_trace(MOD_MED, "[ATV] camera_sp_set_param return [%d]", ret);
    return ret;
}

static mtv_result_t camera_sp_stop_started_services(camera_sp_t* self)
{
    kal_int32 i;
    mtv_result_t ret;

    for (i = 0; i < ARRAY_SIZE(self->services); i++)
    {
        if (camera_sp_is_service_started(&self->services[i]))
        {
            ret = camera_sp_stop_service_core(self, self->services[i].sid);
        }
    }

    return MTV_S_OK;
}

static mtv_result_t camera_sp_close_core(camera_sp_t* self)
{
    mtv_result_t ret;

    ret = camera_sp_stop_started_services(self);
    ASSERT(ret >= 0);

    return MTV_S_OK;
}

static mtv_result_t camera_sp_close(mtv_spi_t* spi)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);

    if (self->state == CAMERA_SP_STATE_CLOSED) {
        RETURN_E(MTV_E_WRONG_STATE);
    }

    camera_sp_close_core(self);

    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_CLOSED);
    self->client->on_event(self->client, MTV_SPI_CLOSED, 0);

    return MTV_S_OK;
}

static void camera_sp_destroy(mtv_spi_t* spi)
{
    camera_sp_t* self = PTHIS(spi, camera_sp_t, itf);
    mtv_free_ext_mem((void**) &self);
}

mtv_spi_t* construct_camera_sp(void)
{
    camera_sp_t* self = (camera_sp_t*) mtv_alloc_ext_mem(sizeof(*self), MAKE_FOURCC('C','M','S','P'));

    kal_mem_set(self, 0, sizeof(camera_sp_t));

    self->itf.open = camera_sp_open;
    self->itf.get_esg_interface = camera_sp_get_esg_interface;
    self->itf.get_ca_interface = camera_sp_get_ca_interface;
    self->itf.search_services = camera_sp_search_services;
    self->itf.abort_searching = camera_sp_abort_searching;
    self->itf.save_service_list = camera_sp_save_service_list;
    self->itf.load_service_list = camera_sp_load_service_list;

    self->itf.start_service = camera_sp_start_service;
    self->itf.stop_service = camera_sp_stop_service;
    self->itf.get_status = camera_sp_get_status;
    self->itf.set_param = camera_sp_set_param;
    self->itf.close = camera_sp_close;
    self->itf.destroy = camera_sp_destroy;

    self->on_scan_progress_ind = camera_on_scan_progress_ind;
    self->on_event = camera_on_event;

    self->client = NULL;
    SP_CHANGE_STATE(self->state, CAMERA_SP_STATE_CLOSED);

    return &self->itf;
}

#endif /* defined(__ATV_CAMERA_SIM_SUPPORT__) */
