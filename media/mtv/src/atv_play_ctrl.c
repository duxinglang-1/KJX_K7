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
 *   atv_play_ctrl.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"
#include "med_trc.h"

#if defined(__MED_ATV_MOD__)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "med_struct.h"     /* message struct */
#include "med_utility.h"
#include "stack_config.h"
#include "stack_ltlcom.h"

#include "mtv_comm.h"
#include "atv_play_ctrl.h"
#include "med_main.h"
#include "med_status.h"
#include "med_api.h"        // VID_3GP_BIT_STREAM and VID_MP4_BIT_STREAM

/* BT */
#include "aud_main.h"
#include "cal_api.h"
#include "atv_api.h"
#include "mm_comm_def.h"
#include "app_datetime.h"
#include "custom_video_enc_if.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MEDMTV_ROCODE", rodata = "DYNAMIC_CODE_MEDMTV_RODATA"
#endif

#if defined(__MAIN_LCM_SCANLINE_ROTATION_0__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_0)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_90__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_270)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_180__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_180)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_270__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_90)
#else
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (0)
#endif

#define ATV_INVALID_PARAM (0);

#define ATV_RECORDER_MAX_PREFIX_LEN (MTV_MAX_SERVICE_NAME - 12) /* 12 for appending "-yymmdd-hhmm" */

typedef struct
{
    atv_play_ctrl_t* context;
    mpl_recorder_event_enum_t event_id;
    media_error_t result;
} atv_mpl_event_cb_param_t;

static atv_play_ctrl_t* atv_play_ctrl_p = NULL;

#ifdef __ATV_RECORD_SUPPORT__
static mtv_result_t atv_rec_pause_core(atv_play_ctrl_t* self, atv_rec_pause_reason_t reason);
static mtv_result_t atv_rec_resume_core(atv_play_ctrl_t* self);
static mtv_result_t atv_rec_start_preview(atv_play_ctrl_t* self, media_config_video_struct* video_config);
#endif

static void atv_player_set_state(atv_play_ctrl_t* self, atv_player_state_t new_state)
{
    if (self->player_state == new_state) {
        return;
    }

    self->player_state = new_state;

    switch (self->player_state)
    {
    case ATV_PLAYER_STATE_STOPPED:
        self->player_config.client->on_state_change(self->player_config.client, MTV_PLAYER_STATE_STOPPED, MTV_S_OK);
        break;

/*
    case ATV_PLAYER_STATE_INITED:
        self->player_config.client->on_state_change(self->player_config.client, MTV_PLAYER_STATE_INITED);
        break;
*/
    case ATV_PLAYER_STATE_STARTED:
        self->player_config.client->on_state_change(self->player_config.client, MTV_PLAYER_STATE_STARTED, MTV_S_OK);
        break;

    default:
        break;
    }
}

static mtv_result_t atv_player_init_video(atv_play_ctrl_t* self, media_config_video_struct* video_config)
{
    mtv_result_t ret = MTV_S_OK;
    CAL_FEATURE_CTRL_STRUCT CalInParam;

    if (self->player_video_inited == KAL_TRUE)
    {
        return MTV_S_FALSE;
    }

    ATV_SetVideoParam(ATV_VDO_CONTRAST, video_config->contrast);
    ATV_SetVideoParam(ATV_VDO_BRIGHTNESS, video_config->brightness);
    ATV_SetVideoParam(ATV_VDO_SATURATION, video_config->saturation);

    // select mATV sensor
    CalInParam.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
    CalInParam.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInParam.FeatureSetValue = (kal_uint32)CAL_CAMERA_SOURCE_MATV;
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInParam, NULL, 0, NULL);

    /* power on camera interface */
    ATV_VideoOpen();

    self->player_video_inited = KAL_TRUE;

    return ret;
}

static mtv_result_t atv_player_start_video(atv_play_ctrl_t* self, media_config_video_struct* video_config)
{
    CAL_CAMERA_PREVIEW_STRUCT CalPreviewPara;
    CAL_LCD_STRUCT CalLcdPara;
    CAL_ISP_PREVIEW_STRUCT CalIspPreviewPara;
    CAL_MDP_PREVIEW_STRUCT CalMdpPreviewPara;
    CAL_SCENARIO_CTRL_STRUCT CalPreviewScenarioPara;
    MM_IMAGE_ROTATE_ENUM PreviewRotate;
    mtv_result_t ret;
    MM_ERROR_CODE_ENUM cal_ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_START_VIDEO);

    if (self->player_video_started == KAL_TRUE)
    {
        return MTV_S_FALSE;
    }

    kal_mem_set(&CalMdpPreviewPara, 0, sizeof(CAL_MDP_PREVIEW_STRUCT));
    kal_mem_set(&CalIspPreviewPara, 0, sizeof(CAL_ISP_PREVIEW_STRUCT));
    kal_mem_set(&CalLcdPara, 0, sizeof(CAL_LCD_STRUCT));
    kal_mem_set(&CalPreviewPara, 0, sizeof(CAL_CAMERA_PREVIEW_STRUCT));

    PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((MM_IMAGE_ROTATE_0 + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);
    if (video_config->idp_rotate == 90)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_90) % 4);
    }
    else if (video_config->idp_rotate == 180)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_180) % 4);
    }
    else if (video_config->idp_rotate == 270)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_270) % 4);
    }

    self->player_buffer2 = med_alloc_asm_mem(self->app_id, video_config->image_buffer_size);
    self->player_buffer3 = med_alloc_asm_mem(self->app_id, video_config->image_buffer_size);

    CalMdpPreviewPara.LcdUpdateEnable = (video_config->display_device == MED_DISPLAY_NONE) ? KAL_FALSE : KAL_TRUE;
    CalMdpPreviewPara.DisplayImageWidth = video_config->display_width;
    CalMdpPreviewPara.DisplayImageHeight = video_config->display_height;
    CalMdpPreviewPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)video_config->image_data_format;
    CalMdpPreviewPara.FrameBuffAddr1 = (kal_uint32)video_config->image_buffer_p;
    CalMdpPreviewPara.FrameBuffAddr2 = (kal_uint32)self->player_buffer2;
    CalMdpPreviewPara.FrameBuffAddr3 = (kal_uint32)self->player_buffer3;
    CalMdpPreviewPara.FrameBuffSize = video_config->image_buffer_size;
    CalMdpPreviewPara.ImageRotAngle = PreviewRotate;
    CalMdpPreviewPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)video_config->image_data_format;

    CalLcdPara.WfcElementHandle = video_config->layer_element;
    CalLcdPara.WfcContextHandle = video_config->blt_ctx;
    CalLcdPara.WfcDeviceHandle = video_config->blt_dev;

    CalPreviewPara.ExtmemStartAddress = NULL;
    CalPreviewPara.ExtmemSize = 0;
    CalPreviewPara.pLcdPara = &CalLcdPara;
    CalPreviewPara.pMdpPara = &CalMdpPreviewPara;
    CalPreviewPara.pIspPara = &CalIspPreviewPara;
    //CalPreviewPara.pFdSdPara = NULL;

    CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
    CalPreviewScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalPreviewScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_PREVIEW_STRUCT);
    CalPreviewScenarioPara.pScenarioCtrlPara = &CalPreviewPara;

    cal_ret = CalCtrl(CAL_SCENARIO_CTRL, (void *)&CalPreviewScenarioPara, NULL, 0, NULL);

    if (cal_ret != MM_ERROR_NONE)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_VIDEO_INIT_ERROR, cal_ret, __LINE__);

        ret = MTV_E_FAIL;
    }
    else
    {
        self->player_video_started = KAL_TRUE;
        ret = MTV_S_OK;
    }

    return ret;
}

static mtv_result_t atv_player_start_audio(atv_play_ctrl_t* self, media_config_audio_struct* audio_config)
{
    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_START_AUDIO);

    if (self->player_audio_inited == KAL_TRUE)
    {
        return MTV_S_FALSE;
    }

    if (audio_config->play_audio)
    {
        aud_stop_unfinished_audio();

        if (aud_atv_is_mute() == KAL_TRUE)
        {
            /* switch audio path to the specified one */
            aud_get_active_device_path_by_mode(audio_config->audio_path, aud_atv_set_output_device);

            aud_atv_open();
        }
        else
        {
            aud_atv_mute(KAL_TRUE);

            /* switch audio path to the specified one */
            aud_get_active_device_path_by_mode(audio_config->audio_path, aud_atv_set_output_device);

            aud_atv_open();

            aud_atv_mute(KAL_FALSE);
        }

        self->player_audio_inited = KAL_TRUE;
    }

    return MTV_S_OK;
}

static mtv_result_t atv_player_deinit_video(atv_play_ctrl_t* self)
{
    if (self->player_video_inited == KAL_TRUE)
    {
        ATV_VideoClose();

        self->player_video_inited = KAL_FALSE;
    }

    return MTV_S_OK;
}

static mtv_result_t atv_player_stop_video(atv_play_ctrl_t* self)
{
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_STOP_VIDEO);
    if (self->player_video_started == KAL_TRUE)
    {
        CalScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
        CalScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        CalScenarioPara.ScenarioCtrlParaLen=0;
        CalScenarioPara.pScenarioCtrlPara=NULL;
        CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);

        if (self->player_buffer2)
        {
            med_free_asm_mem(self->app_id, (void**)&self->player_buffer2);
        }
        if (self->player_buffer3)
        {
            med_free_asm_mem(self->app_id, (void**)&self->player_buffer3);
        }

        mtv_zapping_trace(MOD_MED, "[ATV][PLAYER] exit cam preview process.. ");
#if defined(__DIRECT_SENSOR_SUPPORT__)
{
        ATV_VideoClose();
}
#endif
        self->player_video_started = KAL_FALSE;
    }

    return MTV_S_OK;
}

static mtv_result_t atv_player_stop_audio(atv_play_ctrl_t* self)
{
    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_STOP_AUDIO);

    if (aud_atv_is_mute() == KAL_TRUE)
    {
        if (self->player_audio_inited == KAL_TRUE)
        {
            aud_atv_close();
            self->player_audio_inited = KAL_FALSE;
        }
    }
    else
    {
        if (self->player_audio_inited == KAL_TRUE)
        {
            aud_atv_mute(KAL_TRUE);

            aud_atv_close();
            self->player_audio_inited = KAL_FALSE;

            aud_atv_mute(KAL_FALSE);
        }
    }

    return MTV_S_OK;
}

static mtv_result_t atv_player_start(mtv_player_t* player, mtv_player_config_t* cfg)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_START);

    if (cfg != &self->player_config) {
        self->player_config = *cfg;
    }

#ifdef __ATV_RECORD_SUPPORT__
    /* start video */
    if (self->recorder_itf.state == MTV_RECORDER_STATE_STARTED)
    {
        ret = atv_rec_start_preview(self, cfg->video_config);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_VIDEO_INIT_ERROR, ret, __LINE__);

            /* if assert, push isp guys to handle it */
            /* or we have to handle paused but resume fail issue */
            ASSERT(0);

            goto start_fail;
        }

        /* check if recorder paused by update layer? */
        if (self->recorder_state == ATV_RECORDER_STATE_UPDATE_BLT_PAUSED)
        {
            ret = atv_rec_resume_core(self);
        }
    }
    else
#endif // #ifdef __ATV_RECORD_SUPPORT__
    {
        /* initialize video */
        ret = atv_player_init_video(self, cfg->video_config);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_VIDEO_INIT_ERROR, ret, __LINE__);
            goto start_fail;
        }

        ret = atv_player_start_video(self, cfg->video_config);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_VIDEO_INIT_ERROR, ret, __LINE__);
            goto start_fail;
        }

        ret = atv_player_start_audio(self, cfg->audio_config);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_AUDIO_INIT_ERROR, ret, __LINE__);
            goto start_fail;
        }
    }

    atv_player_set_state(self, ATV_PLAYER_STATE_STARTED);

    return ret;

start_fail:
    atv_player_stop_video(self);
    atv_player_stop_audio(self);
    atv_player_deinit_video(self);

    return ret;
}

static mtv_result_t atv_player_get_control(mtv_player_t* player, mtv_control_t control_id, void** control)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);
    mtv_result_t ret = MTV_S_OK;

    if (control_id == MTV_CONTROL_VIDEO)
    {
        *control = &self->player_video_ctrl;
    }
    else
    {
       *control = NULL;
       ret = MTV_E_NOT_IMPLEMENTED;
    }

    return ret;
}

static mtv_player_state_t atv_player_get_state(mtv_player_t* player)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);
    mtv_player_state_t state;

    state = (self->player_state == ATV_PLAYER_STATE_STOPPED) ? MTV_PLAYER_STATE_STOPPED : MTV_PLAYER_STATE_STARTED;

    return state;
}

#if defined(__MTV_TS_SUPPORT__)
static  mtv_player_buffer_level_t atv_player_get_buffer_level(mtv_player_t* player, mtv_stream_type_t st)
{
    //atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);

    return MTV_PLAYER_BUFFER_LEVEL_NORMAL;
}

static  kal_uint32 atv_player_get_buffer_duration(mtv_player_t* player)
{
    //atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);

    return 0;   // live!!
}
#endif

static mtv_result_t atv_player_stop(mtv_player_t* player)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);

    MTV_TRACE(TRACE_INFO, MTV_TRC_PLAYER_STOP);

#ifdef __ATV_RECORD_SUPPORT__
    if (self->recorder_itf.state == MTV_RECORDER_STATE_STARTED)
    {
        mtv_result_t ret = MTV_S_OK;

        ret = atv_rec_pause_core(self, ATV_REC_PAUSED_BY_PLAYER);
        if (ret != MTV_S_OK)
        {
            /* error when pausing, recorder stopped */

            /* player must stop video/audio if recorder stopped. */

            /* video stopped in recorder pause */

            atv_player_stop_audio(self);

            atv_player_deinit_video(self);

            ret = MTV_S_OK;
        }
    }
    else
#endif // #ifdef __ATV_RECORD_SUPPORT__
    {
        /* stop player */
        atv_player_stop_video(self);

        /* only close audio and deinit isp when player stop */
        /* close audio */
        atv_player_stop_audio(self);

        /* deinit ISP */
        atv_player_deinit_video(self);
    }

    atv_player_set_state(self, ATV_PLAYER_STATE_STOPPED);

    return MTV_S_OK;
}

mtv_result_t atv_player_snapshot(mtv_player_t* player, void* param)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);
    media_mtv_buf_content_struct* param_p = (media_mtv_buf_content_struct*)param;
    mtv_result_t ret = MTV_S_OK;

    CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT GetBuffPara;
    CAL_FEATURE_CTRL_STRUCT CalInPara;

    if (self->player_state == ATV_PLAYER_STATE_STARTED)
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalInPara.FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara = &GetBuffPara;

        GetBuffPara.ImageRotAngle = MM_IMAGE_ROTATE_0; //(MM_IMAGE_ROTATE_ENUM)self->preview_rotate;
        GetBuffPara.ImageBuffAddr = (kal_uint32)param_p->buffer_address;
        GetBuffPara.ImageBuffSize = param_p->buffer_size;
        GetBuffPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)self->player_config.video_config->image_data_format;
        GetBuffPara.ImageWidth = param_p->buffer_width;
        GetBuffPara.ImageHeight = param_p->buffer_height;

        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
    }
    else
    {
        kal_trace(TRACE_ERROR, MTV_TRC_PLAYER_ERROR, self->player_state, __LINE__);
        ret = MTV_E_WRONG_STATE;
    }


    return ret;
}

static mtv_result_t atv_player_ctrl_set_brightness(mtv_control_video_t* control, kal_int32 brightness)
{
    //atv_play_ctrl_t* self = PTHIS(control, atv_play_ctrl_t, player_video_ctrl);

    ATV_SetVideoParam(ATV_VDO_BRIGHTNESS, brightness);

    return MTV_S_OK;
}

static mtv_result_t atv_player_ctrl_set_contrast(mtv_control_video_t* control, kal_int32 contrast)
{
    //atv_play_ctrl_t* self = PTHIS(control, atv_play_ctrl_t, player_video_ctrl);

    ATV_SetVideoParam(ATV_VDO_CONTRAST, contrast);

    return MTV_S_OK;
}

static mtv_result_t atv_player_ctrl_set_gamma(mtv_control_video_t* control, kal_int32 gamma)
{
    //atv_play_ctrl_t* self = PTHIS(control, atv_play_ctrl_t, player_video_ctrl);

    ATV_SetVideoParam(ATV_VDO_SATURATION, gamma);

    return MTV_S_OK;
}

#ifdef __ATV_RECORD_SUPPORT__

static void atv_rec_set_state(atv_play_ctrl_t* self, atv_recorder_state_t new_state, kal_int32 line);
static mtv_result_t atv_rec_stop_preview(atv_play_ctrl_t* self);
static mtv_result_t atv_mpl_recoder_stop(atv_play_ctrl_t* self);
static mtv_result_t atv_mpl_recorder_deinit(atv_play_ctrl_t* self);
static void atv_play_crtl_destroy(atv_play_ctrl_t* self);
//static mtv_result_t atv_mpl_recorder_get_current_record_time(atv_play_ctrl_t* self, kal_uint64 *current_record_time_p);

static void* atv_mpl_recorder_mem_alloc(mpl_recorder_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p)
{
    atv_play_ctrl_t* self = PTHIS(client, atv_play_ctrl_t, mpl_recorder_client);
    void* mem_p = NULL;

    switch(type)
    {
        case MED_MEM_NONCACHE:
            mem_p = (void*) med_alloc_mem(self->app_id, size, file_p, line_p);
            break;

        case MED_MEM_CACHE:
            mem_p = (void*) med_alloc_mem_cacheable(self->app_id, size, file_p, line_p);
            break;

        case MED_MEM_AUD_RINGBUFF:
            aud_util_alloc_ring_buffer_w_log(file_p, line_p, size, (kal_uint16**)&mem_p);
            break;

        default:
            break;
    }

    UNUSED(self);

    return (mem_p);
}

static void atv_mpl_recorder_mem_free(mpl_recorder_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p)
{
    atv_play_ctrl_t* self = PTHIS(client, atv_play_ctrl_t, mpl_recorder_client);

    if (*p)
    {
        switch(type)
        {
            case MED_MEM_NONCACHE:
            case MED_MEM_CACHE:
                med_free_mem(self->app_id, p, file_p, line_p);
                break;

            case MED_MEM_AUD_RINGBUFF:
                aud_util_free_ring_buffer_w_log(file_p,line_p,(kal_uint16**)p);
                break;
            default:
                break;
        }

        *p = NULL;
    }

    UNUSED(self);
}

static void _atv_mpl_recorder_on_stop(atv_play_ctrl_t* self, media_error_t result)
{
    kal_trace(TRACE_FUNC, MTV_TRC_RECORDER_ON_STOP, self->recorder_state, (kal_int32)result);
    /* there is no async stop now. */
    ASSERT(0);
}

static void _atv_mpl_recorder_on_save(atv_play_ctrl_t* self, media_error_t result)
{
    kal_trace(TRACE_FUNC, MTV_TRC_RECORDER_ON_SAVE, self->recorder_state, (kal_int32)result);

    atv_mpl_recorder_deinit(self);
    atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

    self->recorder_itf.client->on_save(self->recorder_itf.client, mpl_media_error_to_mtv_result(result));
    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_SAVED);
}

static void _atv_mpl_recorder_on_event_hdlr(void* param)
{
    atv_mpl_event_cb_param_t* param_p = (atv_mpl_event_cb_param_t*)param;
    atv_play_ctrl_t* self = param_p->context;
    mpl_recorder_event_enum_t event_id = param_p->event_id;
    media_error_t result = param_p->result;

    if (self->recorder_state != ATV_RECORDER_STATE_STOPPED &&
        self->recorder_state != ATV_RECORDER_STATE_CLOSED)
    {
        if (event_id == MPL_RECORDER_EVENT_STOP)
        {
            _atv_mpl_recorder_on_stop(self, result);
        }
        else if (event_id == MPL_RECORDER_EVENT_SAVE)
        {
            _atv_mpl_recorder_on_save(self, result);
        }
        else if (event_id == MPL_RECORDER_EVENT_GENERAL)
        {
            if (self->recorder_state == ATV_RECORDER_STATE_STARTED ||
                self->recorder_state == ATV_RECORDER_STATE_UPDATE_BLT_PAUSED)
            {
                self->last_mpl_error = result;

                atv_mpl_recoder_stop(self);

                if (self->recorder_state == ATV_RECORDER_STATE_STARTED)
                {
                    atv_rec_stop_preview(self);
                }

                atv_mpl_recorder_deinit(self);

                atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

                /* finished by disk full!? */
                kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, result, __LINE__);
                if (result == MED_E_DISC_FULL)
                {
                    /* disk full */
                    self->recorder_itf.client->on_error(self->recorder_itf.client, MTV_IO_E_DISK_FULL);
                }
                else if (result == MED_E_NO_DISC)
                {
                    /* card removed!? */
                    self->recorder_itf.client->on_error(self->recorder_itf.client, MTV_IO_E_MEDIA_CHANGED);
                }
                else
                {
                    /* IO error??? */
                    self->recorder_itf.client->on_error(self->recorder_itf.client, MTV_IO_E_WRITE_ERROR);
                }
            }
            else
            {
                /* unhandled state !? */
                kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, MTV_IO_E_DISK_FULL, __LINE__);
            }
        }
        else
        {
            /* unhandled case !? */
            kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, MTV_E_FAIL, __LINE__);
        }
    }

    mtv_free_ext_mem((void**)&param);
}


static void atv_mpl_recorder_on_event(mpl_recorder_client_t *client, mpl_recorder_event_enum_t event_id, media_error_t result)
{
    atv_play_ctrl_t* self = PTHIS(client, atv_play_ctrl_t, mpl_recorder_client);
    atv_mpl_event_cb_param_t* cb_param;

    kal_trace(TRACE_FUNC, MTV_TRC_RECORDER_ON_EVENT, self->recorder_state, (kal_int32)result);

    cb_param = (atv_mpl_event_cb_param_t*) mtv_alloc_ext_mem(sizeof(atv_mpl_event_cb_param_t), MAKE_FOURCC('E','V','C','P'));

    cb_param->context = self;
    cb_param->event_id = event_id;
    cb_param->result = result;

    mtv_call_async(MTV_CONTROL_MOD, _atv_mpl_recorder_on_event_hdlr, (void*)cb_param);
}

static mtv_result_t atv_mpl_recorder_init(atv_play_ctrl_t* self)
{
    CUSTOM_VENC_USER_T eUser;
    kal_uint32 num_of_entry = 0;

    if (self->player_config.video_config->encode_format == MPL_RECORDER_FORMAT_MJPEG)
    {
        if (self->player_config.video_config->video_mode == ATV_VIDEO_NTSC)
        {
            eUser = CUSTOM_VENC_USER_MATV_MJPEG_NTSC;
        }
        else
        {
            eUser = CUSTOM_VENC_USER_MATV_MJPEG_PAL;
        }
    }
    else
    {
        if (self->player_config.video_config->video_mode == ATV_VIDEO_NTSC)
        {
            eUser = CUSTOM_VENC_USER_MATV_MPEG4_NTSC;
        }
        else
        {
            eUser = CUSTOM_VENC_USER_MATV_MPEG4_PAL;
        }
    }

    CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER, &eUser, sizeof(eUser), NULL, 0);
    CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES, NULL, 0, &num_of_entry, sizeof(num_of_entry));

    ASSERT(self->mpl_recorder == NULL);

    self->mpl_recorder_client.mpl_mem_alloc_func_t = atv_mpl_recorder_mem_alloc;
    self->mpl_recorder_client.mpl_mem_free_func_t = atv_mpl_recorder_mem_free;
    self->mpl_recorder_client.on_event_callback = atv_mpl_recorder_on_event;

    if (self->player_config.video_config->encode_format == MPL_RECORDER_FORMAT_MJPEG)
    {
        self->mpl_recorder = construct_avi_recorder(&self->mpl_recorder_client);
    }
    else
    {
        self->mpl_recorder = construct_mp4_recorder(&self->mpl_recorder_client);
    }


    if (self->mpl_recorder == NULL)
    {
        return MTV_E_FAIL;
    }

    return MTV_S_OK;
}

static mtv_result_t atv_mpl_recorder_open(atv_play_ctrl_t* self, media_config_video_struct* video_config)
{
    mpl_recorder_open_param_t open_param;
    media_error_t ret = MED_S_OK;

    self->mpl_recorder->get_default(self->mpl_recorder, MPL_RECORDER_PARAM_TYPE_OPEN, &open_param, sizeof(open_param));

    open_param.image_width = video_config->image_width;
    open_param.image_height = video_config->image_height;
    open_param.format = video_config->encode_format;
    open_param.quality = video_config->encode_quality;
    open_param.storage = video_config->storage;
    if (video_config->video_mode == ATV_VIDEO_NTSC)
    {
        open_param.user = MPL_RECORDER_USER_MATV_NTSC;
    }
    else
    {
        open_param.user = MPL_RECORDER_USER_MATV_PAL;
    }

    ret = self->mpl_recorder->open(self->mpl_recorder, &open_param);

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recorder_deinit(atv_play_ctrl_t* self)
{
    if (self->mpl_recorder != NULL)
    {
        self->mpl_recorder->close(self->mpl_recorder);
        self->mpl_recorder->destroy(self->mpl_recorder);
        self->mpl_recorder = NULL;
    }

    return MTV_S_OK;
}

static mtv_result_t atv_mpl_recoder_start(atv_play_ctrl_t* self)
{
    mpl_recorder_record_param_t record_param;
    media_error_t ret = MED_S_OK;

    self->mpl_recorder->get_default(self->mpl_recorder, MPL_RECORDER_PARAM_TYPE_START, &record_param, sizeof(record_param));

    /* do not support now record time limit now. */
    record_param.record_time_limit = 0;
    record_param.record_file_size_limit = 0;
    record_param.record_audio = self->record_audio;
    record_param.working_path = self->storing_path;

    ret = self->mpl_recorder->start(self->mpl_recorder, &record_param);

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recoder_stop(atv_play_ctrl_t* self)
{
    media_error_t ret = MED_S_OK;

    ret = self->mpl_recorder->stop(self->mpl_recorder);

    if (ret != MED_S_OK)
    {
        /* IO error!? */
        kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        self->recorder_itf.client->on_error(self->recorder_itf.client, mpl_media_error_to_mtv_result(ret));
    }

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recoder_pause(atv_play_ctrl_t* self)
{
    media_error_t ret = MED_S_OK;

    ret = self->mpl_recorder->pause(self->mpl_recorder);

    if (ret != MED_S_OK)
    {
        /* IO error!? */
        kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        self->recorder_itf.client->on_error(self->recorder_itf.client, mpl_media_error_to_mtv_result(ret));
    }

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recoder_resume(atv_play_ctrl_t* self)
{
    media_error_t ret = MED_S_OK;

    ret = self->mpl_recorder->resume(self->mpl_recorder);

    if (ret != MED_S_OK)
    {
        /* IO error!? */
        kal_trace(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        self->recorder_itf.client->on_error(self->recorder_itf.client, mpl_media_error_to_mtv_result(ret));
    }

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recoder_save(atv_play_ctrl_t* self, kal_wchar* recording_file)
{
    mpl_recorder_save_param_t save_param;
    media_error_t ret = MED_S_OK;

    self->mpl_recorder->get_default(self->mpl_recorder, MPL_RECORDER_PARAM_TYPE_SAVE, &save_param, sizeof(save_param));

    save_param.working_path = self->storing_path;
    save_param.file_path = recording_file;

    ret = self->mpl_recorder->save(self->mpl_recorder, &save_param);

    return mpl_media_error_to_mtv_result(ret);
}

static mtv_result_t atv_mpl_recoder_discard(atv_play_ctrl_t* self, const kal_wchar* dir)
{
    mpl_recorder_discard_param_t discard_param;
    media_error_t ret = MED_S_OK;

    ASSERT(self->mpl_recorder == NULL);

    self->mpl_recorder_client.mpl_mem_alloc_func_t = atv_mpl_recorder_mem_alloc;
    self->mpl_recorder_client.mpl_mem_free_func_t = atv_mpl_recorder_mem_free;
    self->mpl_recorder_client.on_event_callback = atv_mpl_recorder_on_event;

    if (self->player_config.video_config->encode_format == MPL_RECORDER_FORMAT_MJPEG)
    {
        self->mpl_recorder = construct_avi_recorder(&self->mpl_recorder_client);
    }
    else
    {
        self->mpl_recorder = construct_mp4_recorder(&self->mpl_recorder_client);
    }

    self->mpl_recorder->get_default(self->mpl_recorder, MPL_RECORDER_PARAM_TYPE_DISCARD, &discard_param, sizeof(discard_param));

    discard_param.working_path = (kal_wchar*)dir;

    ret = self->mpl_recorder->discard(self->mpl_recorder, &discard_param);

    self->mpl_recorder->destroy(self->mpl_recorder);
    self->mpl_recorder = NULL;

    return mpl_media_error_to_mtv_result(ret);
}

/*
static mtv_result_t atv_mpl_recorder_get_current_record_time(atv_play_ctrl_t* self, kal_uint64 *current_record_time_p)
{
    media_error_t ret;

    ASSERT(self->mpl_recorder);
    ret = self->mpl_recorder->get_param(self->mpl_recorder, MPL_RECORDER_PARAM_RECORDED_TIME, current_record_time_p, sizeof(current_record_time_p));

    return mpl_media_error_to_mtv_result(ret);
}
*/

static kal_wchar* atv_rec_generate_new_filename(const kal_wchar* dir, const kal_wchar* basename, const kal_wchar* extname)
{
    kal_uint32 i;
    kal_wchar* fname;
    kal_wchar serial_num[7];

    fname = mtv_alloc_filename();
    for (i = 0; i < 10000; i++)
    {
        if (i == 0)
        {
            kal_wstrncpy(fname, dir, MAX_FILE_NAME_LEN - 1);
            kal_wstrcat(fname, basename);
            kal_wstrcat(fname, extname);
        }
        else
        {
            kal_wstrncpy(fname, dir, MAX_FILE_NAME_LEN - 1);
            kal_wstrcat(fname, basename);
            kal_wsprintf(serial_num, "(%d)", i);
            kal_wstrcat(fname, serial_num);
            kal_wstrcat(fname, extname);
        }

        if (FS_GetAttributes(fname) < 0) {
            return fname; /* this file does not exist! */
        }
    }

    return NULL;
}

static const kal_wchar* atv_rec_get_format_extension_name(mtv_recording_format_t format)
{
    switch (format)
    {
    case MTV_RECORDING_FORMAT_MP4:
        return L".mp4";

    case MTV_RECORDING_FORMAT_MP2:
        return L".mp2";

    case MTV_RECORDING_FORMAT_3GP:
        return L".3gp";

    case MTV_RECORDING_FORMAT_WAV:
        return L".wav";

    case MTV_RECORDING_FORMAT_AVI:
        return L".avi";

    default:
        return L"";
    }
}

static void atv_rec_set_state(atv_play_ctrl_t* self, atv_recorder_state_t new_state, kal_int32 line)
{
    mtv_recorder_state_t mtv_rec_new_state;

    self->recorder_state = new_state;
    kal_trace(TRACE_GROUP_4, MTV_TRC_RECORDER_STATE, new_state, line);

    if (self->recorder_itf.client)
    {
        /* convert to mtv recorder state */
        if (self->recorder_state == ATV_RECORDER_STATE_SAVING)
        {
            mtv_rec_new_state = MTV_RECORDER_STATE_SAVING;
        }
        else if (self->recorder_state == ATV_RECORDER_STATE_STARTED ||
                 self->recorder_state == ATV_RECORDER_STATE_UPDATE_BLT_PAUSED ||
                 self->recorder_state == ATV_RECORDER_STATE_PAUSED)
        {
            mtv_rec_new_state = MTV_RECORDER_STATE_STARTED;
        }
        else if (self->recorder_state == ATV_RECORDER_STATE_STOPPED)
        {
            mtv_rec_new_state = MTV_RECORDER_STATE_STOPPED;
        }
        else
        {
            /* should not happen */
            ASSERT(self->recorder_state == ATV_RECORDER_STATE_CLOSED);
            mtv_rec_new_state = MTV_RECORDER_STATE_STOPPED;
        }

        /* notify client if state changed */
        if (self->recorder_itf.state != mtv_rec_new_state)
        {
            self->recorder_itf.state = mtv_rec_new_state;
            self->recorder_itf.client->on_state_change(self->recorder_itf.client, self->recorder_itf.state);
        }
    }
}

static mtv_result_t atv_rec_start_preview(atv_play_ctrl_t* self, media_config_video_struct* video_config)
{
    CAL_LCD_STRUCT cal_lcd_data;
    CAL_MDP_VIDEO_STRUCT cal_mdp_video_data;
    CAL_ISP_VIDEO_STRUCT cal_isp_video_data;
    CAL_CAMERA_VIDEO_RECORD_STRUCT cal_video_recorder_data;
    CAL_SCENARIO_CTRL_STRUCT cal_video_scenario_para;
    mpl_get_buffer_pfn_t pfVideoGetBuff;
    mpl_return_buffer_pfn_t pfVideoRetBuff;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    MM_IMAGE_ROTATE_ENUM PreviewRotate;
    kal_uint32 fps;

    kal_mem_set(&cal_lcd_data, 0, sizeof(CAL_LCD_STRUCT));
    kal_mem_set(&cal_mdp_video_data, 0, sizeof(CAL_MDP_VIDEO_STRUCT));
    kal_mem_set(&cal_isp_video_data, 0, sizeof(CAL_ISP_VIDEO_STRUCT));
    kal_mem_set(&cal_video_recorder_data, 0, sizeof(CAL_CAMERA_VIDEO_RECORD_STRUCT));
    kal_mem_set(&pfVideoGetBuff, 0, sizeof(mpl_get_buffer_pfn_t));
    kal_mem_set(&pfVideoRetBuff, 0, sizeof(mpl_return_buffer_pfn_t));

    PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((MM_IMAGE_ROTATE_0 + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);
    if (video_config->idp_rotate == 90)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_90) % 4);
    }
    else if (video_config->idp_rotate == 180)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_180) % 4);
    }
    else if (video_config->idp_rotate == 270)
    {
        PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MM_IMAGE_ROTATE_270) % 4);
    }

    self->player_buffer2 = med_alloc_asm_mem(self->app_id, video_config->image_buffer_size);
    self->player_buffer3 = med_alloc_asm_mem(self->app_id, video_config->image_buffer_size);

    self->mpl_recorder->get_param(self->mpl_recorder, MPL_RECORDER_PARAM_GET_BUFFER_PFN, (void*)&pfVideoGetBuff, sizeof(mpl_get_buffer_pfn_t));
    self->mpl_recorder->get_param(self->mpl_recorder, MPL_RECORDER_PARAM_RETURN_BUFFER_PFN, (void*)&pfVideoRetBuff, sizeof(mpl_return_buffer_pfn_t));

    cal_mdp_video_data.pfGetVideoBuff = pfVideoGetBuff;
    cal_mdp_video_data.pfRetVideoBuff = pfVideoRetBuff;
    cal_mdp_video_data.DisplayImageRotAngle = PreviewRotate;
    cal_mdp_video_data.DisplayImageDataFormat = (MM_IMAGE_FORMAT_ENUM)video_config->image_data_format;
    cal_mdp_video_data.DisplayImageWidth = video_config->display_width;
    cal_mdp_video_data.DisplayImageHeight = video_config->display_height;
    cal_mdp_video_data.FrameBuffAddr1 = (kal_uint32)video_config->image_buffer_p;
    cal_mdp_video_data.FrameBuffAddr2 = (kal_uint32)self->player_buffer2;
    cal_mdp_video_data.FrameBuffAddr3 = (kal_uint32)self->player_buffer3;
    cal_mdp_video_data.FrameBuffSize = video_config->image_buffer_size;
    cal_mdp_video_data.VideoEncodeEnable = KAL_TRUE;
    cal_mdp_video_data.VideoImageRotAngle = MM_IMAGE_ROTATE_0;  // assume mATV sensor is 0 degree.
    if (self->player_config.video_config->encode_format == MPL_RECORDER_FORMAT_MJPEG)
    {
        cal_mdp_video_data.VideoImageDataFormat = MM_IMAGE_FORMAT_JPEG;
    }
    else
    {
        cal_mdp_video_data.VideoImageDataFormat = MM_IMAGE_FORMAT_YUV420;
    }
    cal_mdp_video_data.VideoImageWidth = video_config->image_width;
    cal_mdp_video_data.VideoImageHeight = video_config->image_height;
    cal_mdp_video_data.LcdUpdateEnable = (video_config->display_device == MED_DISPLAY_NONE) ? KAL_FALSE : KAL_TRUE;;
    cal_mdp_video_data.ForceLcdHwTrigger = video_config->force_lcd_hw_trigger;

    /* get FPS after mpl recorder opened!!! */
    CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE, NULL, 0, &fps, sizeof(fps));
    cal_mdp_video_data.VtEncodeFrameRate = fps;
    MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, fps, __LINE__);

    CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE, NULL, 0, &fps, sizeof(fps));
    cal_isp_video_data.MaxVideoFrameRate = fps;   // the frame rate should be query from video frame rate table by MMI and pass to CAL
    MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, fps, __LINE__);

    if ((CAL_VIDEO_EXT_MEMORY_SIZE) > 0)
    {
        if (self->rec_allocated_ext_mem == NULL)
        {
            self->rec_allocated_ext_mem = med_alloc_asm_mem(self->app_id, CAL_VIDEO_EXT_MEMORY_SIZE);

            if (self->rec_allocated_ext_mem == NULL)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, MTV_E_OUT_OF_MEMORY, __LINE__);
                return MTV_E_OUT_OF_MEMORY;
            }
        }
    }
    cal_video_recorder_data.ExtmemStartAddress = (kal_uint32)self->rec_allocated_ext_mem;
    cal_video_recorder_data.ExtmemSize = CAL_VIDEO_EXT_MEMORY_SIZE;

    cal_lcd_data.WfcElementHandle = video_config->layer_element;
    cal_lcd_data.WfcContextHandle = video_config->blt_ctx;
    cal_lcd_data.WfcDeviceHandle = video_config->blt_dev;

    cal_video_recorder_data.pLcdPara = &cal_lcd_data;
    cal_video_recorder_data.pMdpPara = &cal_mdp_video_data;
    cal_video_recorder_data.pIspPara = &cal_isp_video_data;

    cal_video_scenario_para.ScenarioId = CAL_SCENARIO_VIDEO;
    cal_video_scenario_para.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    cal_video_scenario_para.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_VIDEO_RECORD_STRUCT);
    cal_video_scenario_para.pScenarioCtrlPara = &cal_video_recorder_data;

    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &cal_video_scenario_para, NULL, 0, NULL);

    ASSERT(ret == MM_ERROR_NONE);

    return MTV_S_OK;
}

static void atv_rec_release_memory(atv_play_ctrl_t* self)
{
    if (self->rec_allocated_ext_mem)
    {
        med_free_asm_mem(self->app_id, (void **)&self->rec_allocated_ext_mem);
        self->rec_allocated_ext_mem = NULL;
    }

    if (self->player_buffer2)
    {
        med_free_asm_mem(self->app_id, (void **)&self->player_buffer2);
        self->player_buffer2 = NULL;
    }

    if (self->player_buffer3)
    {
        med_free_asm_mem(self->app_id, (void **)&self->player_buffer3);
        self->player_buffer3 = NULL;
    }
}

static mtv_result_t atv_rec_stop_preview(atv_play_ctrl_t* self)
{
    CAL_SCENARIO_CTRL_STRUCT stopPreviewCtrl;

    stopPreviewCtrl.ScenarioId = CAL_SCENARIO_VIDEO;
    stopPreviewCtrl.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
    stopPreviewCtrl.ScenarioCtrlParaLen = 0;
    stopPreviewCtrl.pScenarioCtrlPara = NULL;

    CalCtrl(CAL_SCENARIO_CTRL, (void *) &stopPreviewCtrl, NULL, 0, NULL);

    atv_rec_release_memory(self);

    return MTV_S_OK;
}

static void atv_rec_stop_core(atv_play_ctrl_t* self)
{
    /* for saving the final recording time */
    //atv_mpl_recorder_get_current_record_time(self, &self->current_time);
    //kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)self->current_time, __LINE__);

    atv_mpl_recoder_stop(self);

    atv_rec_stop_preview(self);

    atv_mpl_recorder_deinit(self);

    atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);
}

static mtv_result_t atv_rec_pause_core(atv_play_ctrl_t* self, atv_rec_pause_reason_t reason)
{
    mtv_result_t ret = MTV_S_OK;

    mtv_zapping_trace(MOD_MED, "[ATV][REC] current state = %d, line = %d", self->recorder_state, __LINE__);

    self->recorder_pause_reason = reason;

    if (self->recorder_itf.state == MTV_RECORDER_STATE_STARTED)
    {
        /* video recorder pause req case */
        if (self->recorder_pause_reason == ATV_REC_PAUSED_BY_RECORDER)
        {
            kal_trace(TRACE_GROUP_4, VID_TRC_PAUSE_REQ_HDLR);

            ret = atv_mpl_recoder_pause(self);

            if (ret == MTV_S_OK)
            {
                atv_rec_set_state(self, ATV_RECORDER_STATE_PAUSED, __LINE__);
            }
            else
            {
                atv_rec_stop_preview(self);
                atv_mpl_recorder_deinit(self);

                atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);
            }
        }
        else if (self->recorder_pause_reason == ATV_REC_PAUSED_BY_PLAYER)
        {
            if (self->recorder_state == ATV_RECORDER_STATE_STARTED)
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_PAUSE_REQ_HDLR);

                atv_rec_stop_preview(self);

                atv_rec_set_state(self, ATV_RECORDER_STATE_UPDATE_BLT_PAUSED, __LINE__);
            }
            else
            {
                ASSERT(self->recorder_state == ATV_RECORDER_STATE_PAUSED);

                atv_rec_stop_preview(self);
            }
        }
        else
        {
            ASSERT(0);
        }

        ret = MTV_S_OK;

        return ret;
    }
    else
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, self->recorder_state, __LINE__);

        ret = mpl_media_error_to_mtv_result(self->last_mpl_error);

        return ret;
    }
}

static mtv_result_t atv_rec_resume_core(atv_play_ctrl_t* self)
{
    mtv_result_t ret = MTV_E_FAIL;

    mtv_zapping_trace(MOD_MED, "[ATV][REC] current state = %, line = %d", self->recorder_state, __LINE__);

    if (self->recorder_state == ATV_RECORDER_STATE_PAUSED)
    {
        ret = atv_mpl_recoder_resume(self);
    }
    else if (self->recorder_state == ATV_RECORDER_STATE_UPDATE_BLT_PAUSED)
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_RESUME_REQ_HDLR);

        /* resume encode */
        ret = MTV_S_OK;
    }
    else
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, self->recorder_state, __LINE__);
        return MTV_E_WRONG_STATE;
    }

    if (ret < 0)
    {
        atv_rec_stop_preview(self);

        atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

        return MTV_E_FAIL;
    }
    else
    {
        atv_rec_set_state(self, ATV_RECORDER_STATE_STARTED, __LINE__);

        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_RESUMED);

        return MTV_S_OK;
    }
}

static mtv_result_t atv_rec_start_core(atv_play_ctrl_t* self)
{
    mtv_result_t ret;

    ret = atv_mpl_recorder_init(self);

    if (ret == MTV_S_OK)
    {
        ret = atv_mpl_recorder_open(self, self->player_config.video_config);
    }

    if (ret == MTV_S_OK)
    {
        ret = atv_rec_start_preview(self, self->player_config.video_config);
    }

    if (ret != MTV_S_OK)
    {
        atv_mpl_recorder_deinit(self);

        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);

        return ret;
    }

    ret = atv_mpl_recoder_start(self);
    if (ret != MTV_S_OK)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        goto recorder_start_core_fail;
    }

    return MTV_S_OK;

recorder_start_core_fail:

    /* close outside */
    atv_rec_stop_preview(self);

    atv_mpl_recorder_deinit(self);

    atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

    return ret;
}

static void atv_rec_replace_invalid_chars(kal_wchar* str, const kal_wchar* invalid_chars, kal_wchar replacement)
{
    const kal_wchar* ic;
    kal_wchar* p;
    for (ic = invalid_chars; *ic != 0; ic++)
    {
        for (p = str; *p != 0; p++)
        {
            if (*p == *ic) {
                *p = replacement;
            }
        }
    }
}

static void atv_rec_generate_recording_name(kal_wchar* name, kal_wchar* prefix)
{
    applib_time_struct date_time;

    applib_dt_get_date_time(&date_time);

    if (prefix)
    {
        kal_wsprintf(name, "%w-%02d%02d%02d-%02d%02d", prefix, date_time.nYear, date_time.nMonth, date_time.nDay, date_time.nHour, date_time.nMin);
    }
    else
    {
        kal_wsprintf(name, "REC-%02d%02d%02d-%02d%02d", date_time.nYear, date_time.nMonth, date_time.nDay, date_time.nHour, date_time.nMin);
    }
}

static mtv_result_t atv_rec_get_recorded_duration(mtv_control_record_t* control, kal_uint32* seconds)
{
    // mtv_recorder_t* recorder = PTHIS(control, mtv_recorder_t, record_ctrl);
    // atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);
    mtv_result_t ret = MTV_S_OK;

    /* MMI do not need this in ATV record, always 0 for temp solution */
    *seconds = 0;

    return ret;
}

static mtv_result_t atv_recorder_start(mtv_recorder_t* recorder, mtv_buffer_engine_t* be, mtv_recorder_client_t* client,
                                       const kal_wchar* recording_dir, const kal_wchar* recording_name, mtv_recording_format_t recording_format)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);
    mtv_result_t ret = MTV_S_OK;
    kal_wchar prefix_name[ATV_RECORDER_MAX_PREFIX_LEN];

    ASSERT(self->player_state == ATV_PLAYER_STATE_STARTED);

    if (self->recorder_state == ATV_RECORDER_STATE_SAVING) {
        return MTV_E_BUSY;
    }
    else if (self->recorder_state == ATV_RECORDER_STATE_SAVING) {
        return MTV_S_FALSE;
    }
    else if (self->recorder_state != ATV_RECORDER_STATE_STOPPED) {
        return MTV_E_WRONG_STATE;
    }

    if (KAL_FALSE == aud_atv_is_recorder_resource_available())
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, self->recorder_state, __LINE__);
        return MTV_E_RESOURCE_CONFLICT;
    }

    self->recorder_itf.client = client;
    kal_wstrncpy(self->storing_path, recording_dir, MTV_MAX_SERVICE_NAME);
    self->recorder_itf.recording_format = recording_format;

    if (recording_name && kal_wstrlen(recording_name) > 0)
    {
        memset((void*)prefix_name, 0, ATV_RECORDER_MAX_PREFIX_LEN * sizeof(kal_wchar));
        kal_wstrncpy(prefix_name, recording_name, ATV_RECORDER_MAX_PREFIX_LEN);
        atv_rec_replace_invalid_chars(prefix_name, L"\\/:*?\"<>|", L'_');
        atv_rec_generate_recording_name(self->recorder_itf.recording_name, prefix_name);
    }
    else
    {
        atv_rec_generate_recording_name(self->recorder_itf.recording_name, NULL);
    }

    /* always record audio in ATV case */
    if (self->player_config.audio_config->play_audio)
    {
        self->record_audio = KAL_TRUE;
    }
    else
    {
        self->record_audio = KAL_FALSE;
        ASSERT(0);
    }

    /* stop player preview */
    atv_player_stop_video(self);
    aud_atv_set_input_device();
    ret = atv_rec_start_core(self);

    if (ret == MTV_S_OK)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STARTED);
        atv_rec_set_state(self, ATV_RECORDER_STATE_STARTED, __LINE__);
    }
    else
    {
        mtv_result_t player_ret;

        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);

        /* if fail, resume player. */
        player_ret = atv_player_start_video(self, self->player_config.video_config);
        ASSERT(player_ret == MTV_S_OK);
    }

    return ret;
}

static mtv_result_t atv_recorder_get_control(mtv_recorder_t* recorder, mtv_control_t control_id, void** control)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    *control = &self->recorder_itf.record_ctrl;

    return MTV_S_OK;
}

static mtv_recorder_state_t atv_recorder_get_state(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    return self->recorder_itf.state;
}

static mtv_result_t atv_recorder_stop(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STATE, self->recorder_state, __LINE__);

    if (self->recorder_itf.state != MTV_RECORDER_STATE_STARTED)
    {
        mtv_zapping_trace(MOD_MED, "[ATV][RECORDER] recorder not started! ");
        return MTV_S_FALSE;
    }

    if (self->recorder_state == ATV_RECORDER_STATE_STARTED)
    {
        atv_rec_stop_core(self);
    }
    else if (self->recorder_state == ATV_RECORDER_STATE_PAUSED)
    {
        atv_rec_stop_core(self);
    }
    else if (self->recorder_state == ATV_RECORDER_STATE_UPDATE_BLT_PAUSED)
    {
        /* impossible */
        ASSERT(0);
    }
    else
    {
        ASSERT(0);
    }

    return MTV_S_OK;
}

static mtv_result_t atv_recorder_pause(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_PAUSING);

    ret = atv_rec_pause_core(self, ATV_REC_PAUSED_BY_RECORDER);

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_PAUSED);

    return ret;
}

static mtv_result_t atv_recorder_resume(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_RESUMING);

    if (KAL_FALSE == aud_atv_is_recorder_resource_available())
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, self->recorder_state, __LINE__);
        ret = MTV_E_RESOURCE_CONFLICT;
    }
    else
    {
        ret = atv_rec_resume_core(self);
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_RESUMED);

    return ret;
}

static mtv_result_t atv_recorder_prepare_saving(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_SAVING);

    if (self->recorder_state != ATV_RECORDER_STATE_STOPPED) {

        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, self->recorder_state, __LINE__);
        return MTV_E_WRONG_STATE;
    }

    atv_rec_set_state(self, ATV_RECORDER_STATE_SAVING, __LINE__);

    return MTV_S_OK;
}

static mtv_result_t atv_recorder_do_saving(mtv_recorder_t* recorder, const kal_wchar* record_dir, kal_wchar* file_path, volatile kal_bool* aborted)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);
    kal_int32 fs_ret;
    kal_wchar* recording_file;
    mtv_result_t ret;

    ASSERT(self->recorder_state == ATV_RECORDER_STATE_SAVING);

    /* Ensure that record directory exists */
    if (FS_GetAttributes(record_dir) < 0)
    {
        fs_ret = FS_CreateDir(record_dir);
        if (fs_ret < 0)
        {
            ret = (mtv_result_t)mtv_error_from_fs(fs_ret);
            atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

            self->recorder_itf.client->on_save(self->recorder_itf.client, ret);

            MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
            return ret;
        }
    }

    /* save the recording that may take a long time */
    if (file_path)
    {
        recording_file = file_path;
    }
    else
    {
        recording_file = atv_rec_generate_new_filename(record_dir, self->recorder_itf.recording_name,
                                                    atv_rec_get_format_extension_name(self->recorder_itf.recording_format));
    }

    ret = atv_mpl_recorder_init(self);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        goto atv_do_saving_end;
    }

    /* merge file here!, already in MED_V task */
    ret = atv_mpl_recoder_save(self, recording_file);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_RECORDER_ERROR, ret, __LINE__);
        goto atv_do_saving_end;
    }

    if (file_path == NULL)
    {
        mtv_free_ext_mem((void**) &recording_file);
    }

    return ret;

atv_do_saving_end:

    atv_mpl_recorder_deinit(self);
    if (file_path == NULL)
    {
        mtv_free_ext_mem((void**) &recording_file);
    }
    atv_rec_set_state(self, ATV_RECORDER_STATE_STOPPED, __LINE__);

    return ret;
}

static mtv_result_t atv_recorder_save_checkpoint(mtv_recorder_t* recorder, const kal_wchar* dir)
{
    //atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    return MTV_S_FALSE;
}

static mtv_result_t atv_recorder_recover_from_checkpoint(mtv_recorder_t* recorder, const kal_wchar* checkpoint, const kal_wchar* record_dir,volatile kal_bool* aborted)
{
    //atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    /* merge files */

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t atv_recorder_delete_checkpoint(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    atv_mpl_recoder_discard(self, self->storing_path);

    return MTV_S_OK;
}

kal_bool mtv_recorder_find_checkpoints(kal_uint16 app_id, const kal_wchar* dir)
{
    mtv_recorder_t* recorder;
    atv_play_ctrl_t* self;

    recorder = construct_atv_recorder(app_id);

    self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    /* we did not support recover now, delete all temp file. */
    atv_mpl_recoder_discard(self, dir);

    recorder->destroy(recorder);

    return KAL_FALSE;
}

void mtv_recorder_discard_unsaved_recording(kal_uint16 app_id, const kal_wchar* dir)
{
}

mtv_result_t mtv_recorder_recover_recording(kal_uint16 app_id, const kal_wchar* dir, const kal_wchar* record_dir, volatile kal_bool* aborted)
{
    return MTV_E_NOT_IMPLEMENTED;
}

static void atv_recorder_destroy(mtv_recorder_t* recorder)
{
    atv_play_ctrl_t* self = PTHIS(recorder, atv_play_ctrl_t, recorder_itf);

    ASSERT(self->recorder_state == ATV_RECORDER_STATE_STOPPED);

    self->recorder_state = ATV_RECORDER_STATE_CLOSED;

    atv_play_crtl_destroy(self);
}

#endif


static void atv_play_crtl_destroy(atv_play_ctrl_t* self)
{
    if (self->player_state == ATV_PLAYER_STATE_CLOSED)
    {
        #ifdef __ATV_RECORD_SUPPORT__
            if (self->recorder_state == ATV_RECORDER_STATE_CLOSED)
            {
                mtv_free_ext_mem((void**) &self);
                atv_play_ctrl_p = NULL;
            }
        #else
            mtv_free_ext_mem((void**) &self);
            atv_play_ctrl_p = NULL;
        #endif
    }
}

static void atv_player_destroy(mtv_player_t* player)
{
    atv_play_ctrl_t* self = PTHIS(player, atv_play_ctrl_t, player_itf);

    self->player_state = ATV_PLAYER_STATE_CLOSED;

    atv_play_crtl_destroy(self);
}

static atv_play_ctrl_t* atv_play_crtl_construct(void)
{
    atv_play_ctrl_t* self;

    /* currently use global variable */
    if (atv_play_ctrl_p)
    {
        /* exist already */
        return atv_play_ctrl_p;
    }

    self = atv_play_ctrl_p = (atv_play_ctrl_t*) mtv_alloc_ext_mem(sizeof(atv_play_ctrl_t), MAKE_FOURCC('T','V','P','L'));
    kal_mem_set(self, 0, sizeof(*self));

    /* player setup */
    self->player_itf.start = atv_player_start;
    self->player_itf.get_control = atv_player_get_control;
    self->player_itf.get_state = atv_player_get_state;
#if defined(__MTV_TS_SUPPORT__)
    self->player_itf.get_buffer_level = atv_player_get_buffer_level;
    self->player_itf.get_buffer_duration = atv_player_get_buffer_duration;
#endif
    self->player_itf.stop = atv_player_stop;
    self->player_itf.snapshot = atv_player_snapshot;
    self->player_itf.destroy = atv_player_destroy;

    self->player_video_ctrl.set_brightness = atv_player_ctrl_set_brightness;
    self->player_video_ctrl.set_contrast = atv_player_ctrl_set_contrast;
    self->player_video_ctrl.set_gamma = atv_player_ctrl_set_gamma;

    self->player_state = ATV_PLAYER_STATE_CLOSED;

#ifdef __ATV_RECORD_SUPPORT__
    /* recorder setup */
    self->recorder_itf.start = atv_recorder_start;
    self->recorder_itf.get_control = atv_recorder_get_control;
    self->recorder_itf.get_state = atv_recorder_get_state;
    self->recorder_itf.stop = atv_recorder_stop;
    self->recorder_itf.pause = atv_recorder_pause;
    self->recorder_itf.resume = atv_recorder_resume;
    self->recorder_itf.prepare_saving = atv_recorder_prepare_saving;
    self->recorder_itf.do_saving = atv_recorder_do_saving;
    self->recorder_itf.save_checkpoint = atv_recorder_save_checkpoint;
    self->recorder_itf.recover_from_checkpoint = atv_recorder_recover_from_checkpoint;
    self->recorder_itf.delete_checkpoint = atv_recorder_delete_checkpoint;
    self->recorder_itf.destroy = atv_recorder_destroy;

    self->recorder_itf.record_ctrl.get_recorded_duration = atv_rec_get_recorded_duration;

    self->recorder_state = ATV_RECORDER_STATE_CLOSED;
#endif

    return self;
}

mtv_player_t* construct_atv_player(kal_uint16 app_id)
{
    atv_play_ctrl_t* self;

    self = atv_play_crtl_construct();

    self->player_state = ATV_PLAYER_STATE_STOPPED;
    self->player_video_inited = KAL_FALSE;
    self->player_video_started = KAL_FALSE;
    self->player_audio_inited = KAL_FALSE;
    self->player_buffer2 = NULL;
    self->player_buffer3 = NULL;
    self->app_id = app_id;

    return &self->player_itf;
}

#ifdef __ATV_RECORD_SUPPORT__
mtv_recorder_t* construct_atv_recorder(kal_uint16 app_id)
{
    atv_play_ctrl_t* self;

    self = atv_play_crtl_construct();

    self->recorder_state = ATV_RECORDER_STATE_STOPPED;
    self->app_id = app_id;

    return &self->recorder_itf;
}
#endif // #ifdef __ATV_RECORD_SUPPORT__

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif /* defined(__MED_ATV_MOD__) */
