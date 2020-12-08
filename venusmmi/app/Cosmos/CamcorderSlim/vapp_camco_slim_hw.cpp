/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
#include "gpiosrvgprot.h"
#include "mdi_include.h"
#include "gdi_lcd.h"

// color transform
#include "iul_csc_y2r.h"

// get_audio
#include "Wgui_categories_util.h"

#ifdef __cplusplus
}
#endif

#include "MMI_include.h"
#include "MMI_features_camcorder.h"
#include "vapp_camco_express_gprot.h"
#include "vapp_camco_slim_hw.h"
#include "gdi_include.h"

#ifdef __VAPP_CAMCO_SLIM__

extern VfxU32 camSceneTable[4][VAPP_CAMCO_CAMSCENEMODE_ASD_AUTO];
extern VfxU32 vdoSceneTable[4][VAPP_CAMCO_VDOSCENEMODE_END];

#pragma arm section code = "DYNAMIC_CODE_CAMCO_ROCODE", rodata = "DYNAMIC_CODE_CAMCO_RODATA"


VappCamcoPage* vapp_camco_hw_object;

MDI_RESULT vapp_camco_reset_hw_obj(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESET_HW_OBJ, 1);

    vapp_camco_hw_object = NULL;
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_camco_set_rotation(CamcoSettingMgr *setting, VfxBool isCapture, VfxBool isHorz, VfxBool isOSDHorz, VfxBool isMirror)
{
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)

    if(isCapture)
    {
        if(isOSDHorz)
        {
            if(isMirror)
                mdi_camera_set_capture_rotation(MDI_CAMERA_UI_ROTATE_270);
            else
                mdi_camera_set_capture_rotation(MDI_CAMERA_UI_ROTATE_90);
        }
        else
        {
            if(isMirror)
                mdi_camera_set_capture_rotation(MDI_CAMERA_UI_ROTATE_180);
            else
                mdi_camera_set_capture_rotation(MDI_CAMERA_UI_ROTATE_0);
        }
        if(isHorz != isOSDHorz)
        {
            VfxU16 image_width, image_height;

            ((CapSizeSetting*)(setting->getSetting(VAPP_CAMCO_SETTING_CAPSIZE)))->getMappingSize(
                setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE),
                &image_width,
                &image_height);

            VfxU16 t = image_width;
            image_width = image_height;
            image_height = t;

            mdi_camera_update_para_image_size(image_width, image_height);
        }
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        if(isOSDHorz)
        {
            if(isMirror)
                mdi_video_rec_set_record_rotation(MDI_CAMERA_UI_ROTATE_270);
            else
                mdi_video_rec_set_record_rotation(MDI_CAMERA_UI_ROTATE_90);
        }
        else
        {
            if(isMirror)
                mdi_video_rec_set_record_rotation(MDI_CAMERA_UI_ROTATE_180);
            else
                mdi_video_rec_set_record_rotation(MDI_CAMERA_UI_ROTATE_0);
        }
        if(isHorz != isOSDHorz)
        {
            VfxSize image_size;

            image_size = ((RecSizeSetting*)(setting->getSetting(VAPP_CAMCO_SETTING_RECSIZE)))->getSize(
                setting->getValue(VAPP_CAMCO_SETTING_RECSIZE));

            VfxU16 t = image_size.width;
            image_size.width = image_size.height;
            image_size.height = t;

            mdi_video_rec_update_rec_size(image_size.width, image_size.height);
        }
        return MDI_RES_VDOREC_SUCCEED;
    }
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_cam_preview_start(vapp_camco_cam_preview_start_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_PREVIEW_START, param->flag->isPreviewStart);

    VAPP_CAMCO_START_LOGGING("ACS");

    vapp_camco_hw_object = param->obj;

#if defined(__MTK_TARGET__)

    if(param->flag->isPreviewStart)
        return MDI_RES_CAMERA_SUCCEED;
        
    if(param->flag->isEnablePQ)
    {
        mdi_camera_color_engine_disable();
        mdi_camera_color_engine_close();
        param->flag->isEnablePQ = VFX_FALSE;
    }        

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    MDI_RESULT result;
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;

    /* preview parametes */
    camera_setting_data.zoom = param->Setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM);
    camera_setting_data.wb = param->Setting->getMappingID(VAPP_CAMCO_SETTING_WB);
    camera_setting_data.ev = MDI_CAMERA_EV_0;
    if (g_vapp_camco_banding_setting == 0)
    {
        camera_setting_data.banding = MDI_CAMERA_BANDING_50HZ;
    }
    else
    {
        camera_setting_data.banding = MDI_CAMERA_BANDING_60HZ;
    }
    

    camera_setting_data.iso = param->Setting->getMappingID(VAPP_CAMCO_SETTING_ISO);
    camera_setting_data.ae_meter = MDI_CAMERA_AE_METER_AUTO;
    camera_setting_data.scene_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAMSCENEMODE);

    camera_setting_data.effect = param->Setting->getMappingID(VAPP_CAMCO_SETTING_EFFECT);
    camera_setting_data.sharpness = camSceneTable[1][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]; ;
    camera_setting_data.contrast = camSceneTable[2][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]; ;
    camera_setting_data.saturation = camSceneTable[3][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];
    camera_setting_data.hue = 0;

    camera_setting_data.overlay_frame_mode = FALSE;
    camera_setting_data.overlay_frame_depth = 0;
    camera_setting_data.overlay_frame_width = 0;
    camera_setting_data.overlay_frame_height = 0;
    camera_setting_data.overlay_frame_source_key = 0;
    camera_setting_data.overlay_frame_buffer_address = 0;

    camera_setting_data.overlay_palette_size = 0;
    camera_setting_data.overlay_palette_addr = NULL;

    camera_setting_data.preview_width = param->obj->m_previewWindow.getWidth();
    camera_setting_data.preview_height = param->obj->m_previewWindow.getHeight();

    /* capture parameters */
    camera_setting_data.image_qty = MDI_CAMERA_JPG_QTY_HIGH;

    ((CapSizeSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE),
        &camera_setting_data.image_width,
        &camera_setting_data.image_height);

    camera_setting_data.xenon_flash_status_callback = NULL;

    

#ifdef __FACE_DETECTION_SUPPORT__
    if (param->Setting->getValue(VAPP_CAMCO_SETTING_EFFECT) != VAPP_CAMCO_EFFECT_LOMO &&
        param->Setting->getValue(VAPP_CAMCO_SETTING_EFFECT) != VAPP_CAMCO_EFFECT_COLOR_BLUE &&
        param->Setting->getValue(VAPP_CAMCO_SETTING_EFFECT) != VAPP_CAMCO_EFFECT_COLOR_GREEN &&
        param->Setting->getValue(VAPP_CAMCO_SETTING_EFFECT) != VAPP_CAMCO_EFFECT_COLOR_YELLOW &&
        param->Setting->getValue(VAPP_CAMCO_SETTING_EFFECT) != VAPP_CAMCO_EFFECT_COLOR_RED)
    {
        camera_setting_data.fd_enable = TRUE;
        camera_setting_data.fd_callback = NULL;
    }
    else
    {
        camera_setting_data.fd_enable = FALSE;
        camera_setting_data.fd_callback = NULL;
    }
#endif /* __FACE_DETECTION_SUPPORT__ */
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;

    camera_setting_data.af_range = camSceneTable[0][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];;
    if(param->Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON)
    {
        if(camera_setting_data.af_range == MDI_CAMERA_AF_RANGE_LANDSCAPE)
            camera_setting_data.af_range = MDI_CAMERA_AF_RANGE_AUTO;
    }

#if (AF_SUPPORT)
    if(param->Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON)
        camera_setting_data.af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS;
    else
        camera_setting_data.af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
#else
    camera_setting_data.af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_OFF;
#endif

    camera_preview_data.preview_layer_handle = param->previewFrame->getLayerHandle();
    camera_preview_data.blt_layer_flag = param->previewFrame->getDisplayLayerFlag();
    camera_preview_data.preview_layer_flag = param->previewFrame->getHwLayerFlag();
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = FALSE;

    if(param->isResetZoom)
        camera_setting_data.zoom = ((CamZoomSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_CAMZOOM)))->getMinValue();
    else
        camera_setting_data.zoom = param->Setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM);

    U8 capture_mode;
    if(param->Setting->getValue(VAPP_CAMCO_SETTING_ASD) == VAPP_CAMCO_SCENE_DETECT_ON)
    {
        capture_mode = MDI_CAMERA_CAP_MODE_ASD;
    }
    else if(param->Setting->getValue(VAPP_CAMCO_SETTING_ZSD) == VAPP_CAMCO_ZERO_DELAY_ON)
    {
        capture_mode = MDI_CAMERA_CAP_MODE_ZSD;
    }
    else
    {
        capture_mode = MDI_CAMERA_CAP_MODE_NORMAL;
    }

    result = mdi_camera_preview_start_with_capmode(
        &camera_preview_data,
        &camera_setting_data,
        capture_mode,
        (void*)param->obj);

    if(result == MDI_RES_CAMERA_SUCCEED)
        param->flag->isPreviewStart = VFX_TRUE;
    else
        param->flag->isPreviewStart = VFX_FALSE;

    param->flag->isTakepicFailed = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_PREVIEW_START_F, result);

    VAPP_CAMCO_STOP_LOGGING("ACS");

    return result;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_cam_preview_stop(vapp_camco_cam_preview_stop_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_PREVIEW_STOP, param->flag->isPreviewStart);
    VAPP_CAMCO_START_LOGGING("ACC");

#if defined(__MTK_TARGET__)
    if(param->flag->isPreviewStart)
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
        if(param->Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            vapp_camco_cam_sd_param_struct p;
            p.flag = param->flag;
            vapp_camco_cam_sd_stop(&p);
        }
    #endif
        mdi_camera_preview_stop();

        gdi_handle handleT = param->obj->m_previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);
        gdi_lcd_lock_mutex();
        gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();

        param->flag->isPreviewStart = VFX_FALSE;
    }
    VAPP_CAMCO_STOP_LOGGING("ACC");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_PREVIEW_STOP_F);
#endif
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_camco_rec_preview_start(vapp_camco_rec_preview_start_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PREVIEW_START, param->flag->isPreviewStart);

    VAPP_CAMCO_START_LOGGING("ARS");

    vapp_camco_hw_object = param->obj;

#if defined(__MTK_TARGET__)

    if(param->flag->isPreviewStart)
        return MDI_RES_VDOREC_SUCCEED;

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    MDI_RESULT result;
    mdi_video_setting_struct video_preview_data;

    video_preview_data.wb = param->Setting->getMappingID(VAPP_CAMCO_SETTING_WB);
    video_preview_data.ev = MDI_CAMERA_EV_0;
    if (g_vapp_camco_banding_setting == 0)
    {
        video_preview_data.banding = MDI_CAMERA_BANDING_50HZ;
    }
    else
    {
        video_preview_data.banding = MDI_CAMERA_BANDING_60HZ;
    }
    video_preview_data.video_qty = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISQTY);
    video_preview_data.video_format = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISCODEC);
    video_preview_data.effect = param->Setting->getMappingID(VAPP_CAMCO_SETTING_EFFECT);
    video_preview_data.video_size = param->Setting->getMappingID(VAPP_CAMCO_SETTING_RECSIZE);
    video_preview_data.user_def_width = 0;
    video_preview_data.user_def_height = 0;

    video_preview_data.zoom = param->Setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM);
    video_preview_data.dsc_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VDOSCENEMODE);

    video_preview_data.contrast = vdoSceneTable[2][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];
    video_preview_data.saturation = vdoSceneTable[3][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];
    video_preview_data.sharpness = vdoSceneTable[1][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];

    video_preview_data.hue = 0;

    if (param->Setting->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE) == VAPP_CAMCO_VDOSCENEMODE_NIGHT)
    {
        video_preview_data.night = 1;
    }
    else
    {
        video_preview_data.night = 0;
    }

    if(param->Setting->getValue(VAPP_CAMCO_SETTING_VDOSTORAGE) == SRV_FMGR_DRV_CARD_TYPE)
    {
        video_preview_data.storage = MDI_VIDEO_REC_STORAGE_SD;
    }
    else
    {
        video_preview_data.storage = MDI_VIDEO_REC_STORAGE_PHONE;
    }

    video_preview_data.af_range = vdoSceneTable[0][param->Setting->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)];
#if (AF_SUPPORT)
    video_preview_data.af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
#else
    video_preview_data.af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_OFF;
#endif
    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;
    video_preview_data.record_aud = 1;
    video_preview_data.encode_one_frame_duration =  0;


    result = mdi_video_rec_preview_start(
                param->previewFrame->getLayerHandle(),
                param->previewFrame->getDisplayLayerFlag(),
                param->previewFrame->getHwLayerFlag(),
                KAL_TRUE,
                &video_preview_data);

    if(result == MDI_RES_VDOREC_SUCCEED)
        param->flag->isPreviewStart = VFX_TRUE;
    else
        param->flag->isPreviewStart = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PREVIEW_START_F, result);

    VAPP_CAMCO_STOP_LOGGING("ARS");

    return result;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_preview_stop(vapp_camco_rec_preview_stop_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PREVIEW_STOP, param->flag->isPreviewStart);
    VAPP_CAMCO_START_LOGGING("ARC");
#if defined(__MTK_TARGET__)
    if(param->flag->isPreviewStart)
    {
        mdi_video_rec_preview_stop();

        gdi_handle handleT = param->obj->m_previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);
        gdi_lcd_lock_mutex();
        gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();

        param->flag->isPreviewStart = VFX_FALSE;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PREVIEW_STOP_F);
    VAPP_CAMCO_STOP_LOGGING("ARC");
#endif
    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_cam_power_on(vapp_camco_cam_power_on_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_POWER_ON, param->flag->isPowerOn);

#if defined(__MTK_TARGET__)
    if(!param->flag->isPowerOn)
    {
        VAPP_CAMCO_START_LOGGING("ACN");
        mdi_camera_set_camera_id(param->Setting->getMappingID(VAPP_CAMCO_SETTING_ACT_CAM));
        MDI_RESULT ret = mdi_camera_power_on(param->obj->m_appID);

        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->flag->isPowerOn = VFX_TRUE;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_POWER_ON_F, ret);
        VAPP_CAMCO_STOP_LOGGING("ACN");
        return ret;
    }
    else
#endif
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
}

MDI_RESULT vapp_camco_cam_power_off(vapp_camco_cam_power_off_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_POWER_OFF, param->flag->isPowerOn);

#if defined(__MTK_TARGET__)
    VAPP_CAMCO_START_LOGGING("ACF");

    if (param->flag->isPowerOn)
    {
        mdi_camera_power_off();
        param->flag->isPowerOn = VFX_FALSE;
    }
    if(param->flag->isEnablePQ)
    {
        mdi_camera_color_engine_disable();
        mdi_camera_color_engine_close();
        param->flag->isEnablePQ = VFX_FALSE;
    } 

    VAPP_CAMCO_STOP_LOGGING("ACF");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_POWER_OFF_F);
#endif
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_camco_rec_power_on(vapp_camco_rec_power_on_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_POWER_ON, param->flag->isPowerOn);

#if defined(__MTK_TARGET__)

    if(!param->flag->isPowerOn)
    {
        VAPP_CAMCO_START_LOGGING("ARN");
        mdi_video_set_camera_id(param->Setting->getMappingID(VAPP_CAMCO_SETTING_ACT_CAM));
        MDI_RESULT ret = mdi_video_rec_power_on(param->obj->m_appID);

        if (ret == MDI_RES_VDOREC_SUCCEED)
        {
            param->flag->isPowerOn = VFX_TRUE;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_POWER_ON_F, ret);
        VAPP_CAMCO_STOP_LOGGING("ARN");
        return ret;
    }
    else
#endif
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
}

MDI_RESULT vapp_camco_rec_power_off(vapp_camco_rec_power_off_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_POWER_OFF, param->flag->isPowerOn);

#if defined(__MTK_TARGET__)
    VAPP_CAMCO_START_LOGGING("ARF");

    if (param->flag->isPowerOn)
    {
        mdi_video_rec_power_off();
        param->flag->isPowerOn = VFX_FALSE;
    }
    if(param->flag->isEnablePQ)
    {
        mdi_camera_color_engine_disable();
        mdi_camera_color_engine_close();
        param->flag->isEnablePQ = VFX_FALSE;
    } 

    VAPP_CAMCO_STOP_LOGGING("ARF");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_POWER_OFF_F);
#endif
    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_cam_normal_shot(vapp_camco_cam_capture_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;

#if defined(__MTK_TARGET__)
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_NORMAL_SHOT);

    if (mdi_camera_is_ready_to_capture())
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);

        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->m_isVideoLayerHorz, param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

        mdi_camera_set_quickview_rotation(MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG);

        ret = mdi_camera_capture_with_quickview(
            (U32)param->obj->m_prepareFramePtr,
            (U32)param->obj->m_prepareFrameSize,
            param->previewFrame->getSize().width,
            param->previewFrame->getSize().height,
            (CHAR *)param->fileName);

        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->obj->playCatureSound(ret);

            ret = mdi_camera_encode_capture_image((U8**)&param->capture_buf_ptr, &param->capture_size);
        }

        if(!param->flag->isEnablePQ)
        {
            mdi_camera_color_engine_open();
            mdi_camera_color_engine_enable();
            param->flag->isEnablePQ = VFX_TRUE;
        }

        // content has been modified by driver with QV, need to force update
        param->previewFrame->setContentDirty();

        gdi_layer_pop_and_restore_active();
    }
#endif

#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW
    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";

    sprintf(fileNameAsc, "%c:\\1.jpg", SRV_FMGR_CARD_DRV);
    mmi_asc_to_wcs(fileName, fileNameAsc);

    VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));

    param->obj->m_picturePreviewFrame->setImgContent(s);
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_NORMAL_SHOT_F, ret);

    if(ret != MDI_RES_CAMERA_SUCCEED)
        param->flag->isTakepicFailed = VFX_TRUE;

    return ret;
}

MDI_RESULT vapp_camco_cam_save_capture_image(vapp_camco_cam_capture_save_param_struct *param)
{
#if defined(__MTK_TARGET__)
    MDI_RESULT ret;

    ret = mdi_camera_save_captured_image();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_SAVE_CAPTURE_IMAGE, ret);

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}


void vapp_camco_rec_record_result_hdlr(MDI_RESULT result, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_RECORD_FINISH;
    param.recordRet = result;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_CALLBACK, result);

    if(vapp_camco_hw_object)
        vapp_camco_hw_object->resultHWCallback(param);
}

MDI_RESULT vapp_camco_rec_record_start(vapp_camco_rec_record_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_START, param->flag->isPreviewStart);

#if defined(__MTK_TARGET__)
    MDI_RESULT ret;

    vapp_camco_hw_object = param->obj;

    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;
    vapp_camco_set_rotation(param->obj->m_Setting, VFX_FALSE, param->obj->m_isVideoLayerHorz, param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

    ret = mdi_video_rec_record_start((CHAR *)param->fileName, vapp_camco_rec_record_result_hdlr, vapp_camco_hw_object);

    if(ret == MDI_RES_VDOREC_SUCCEED)
    {
        param->flag->isOnRecord = VFX_TRUE;
    }
    else
    {
        param->flag->isRecordFailed = VFX_TRUE;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_START, ret);
    return ret;
#else
    param->flag->isOnRecord = VFX_TRUE;
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_record_stop(vapp_camco_rec_record_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_STOP, param->flag->isOnRecord);

#if defined(__MTK_TARGET__)
    MDI_RESULT ret = MDI_RES_VDOREC_SUCCEED;
    VAPP_CAMCO_START_LOGGING("ARE");
    if (param->flag->isOnRecord)
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);

        ret  = mdi_video_rec_record_stop();

        gdi_layer_pop_and_restore_active();

        param->flag->isOnRecord = VFX_FALSE;
        param->flag->isPreviewStart = VFX_FALSE;
    }
    VAPP_CAMCO_STOP_LOGGING("ARE");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_STOP, ret);
    return ret;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_record_pause(vapp_camco_rec_record_param_struct *param)
{
#if defined(__MTK_TARGET__)
    MDI_RESULT ret;

    VAPP_CAMCO_START_LOGGING("ARP");
    ret = mdi_video_rec_record_pause(KAL_FALSE);
    VAPP_CAMCO_STOP_LOGGING("ARP");

    param->flag->isPreviewStart = VFX_TRUE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_PAUSE, ret);

    return ret;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_record_resume(vapp_camco_rec_record_param_struct *param)
{
#if defined(__MTK_TARGET__)
    MDI_RESULT ret;

    VAPP_CAMCO_START_LOGGING("ARR");
    ret = mdi_video_rec_record_resume();
    VAPP_CAMCO_STOP_LOGGING("ARR");

    param->flag->isPreviewStart = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_RESUME, ret);

    return ret;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_record_get_time(VfxU64 *time)
{
    mdi_video_rec_get_cur_record_time((U64*)time);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_GET_TIME, (*time));

    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_rec_record_get_size(VfxU64 *size)
{
    (*size) = mdi_video_rec_get_record_file_size();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_GET_SIZE, (*size));

    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_rec_record_get_count(VfxU64 *count)
{
#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    mdi_video_rec_get_record_frame_num((U64*)count);
#else
    mdi_video_rec_get_cur_record_time((U64*)count);
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_GET_COUNT, (*count));

    return MDI_RES_VDOREC_SUCCEED;
}

static void vapp_camco_rec_save_result_hdlr(MDI_RESULT result, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_RECORD_SAVE;
    param.recordRet = result;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_SAVE_VIDEO_RESULT, result);

    if(vapp_camco_hw_object)
        vapp_camco_hw_object->resultHWCallback(param);
}

MDI_RESULT vapp_camco_rec_stop_save_video(void)
{
#if defined(__MTK_TARGET__)
    mdi_video_rec_stop_save();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_STOP_SAVE_VIDEO);
#endif
    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_rec_save_video(vapp_camco_rec_record_save_param_struct *param)
{
#if defined(__MTK_TARGET__)
    MDI_RESULT result = MDI_RES_VDOREC_SUCCEED;

    vapp_camco_hw_object = param->obj;

    VAPP_CAMCO_START_LOGGING("ARS");
    param->flag->isRecSaveCallback = VFX_FALSE;

    result = mdi_video_rec_save_file((CHAR *)param->fileName, vapp_camco_rec_save_result_hdlr, (void*)param->obj);

    if (result == MDI_RES_VDOREC_SUCCEED)
    {
        param->flag->isRecSaveSuccess = VFX_TRUE;
    }
    else
    {
        param->flag->isRecSaveSuccess = VFX_FALSE;
        mdi_video_rec_delete_unsaved_file((CHAR *)param->fileName);
    }
    VAPP_CAMCO_STOP_LOGGING("ARS");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_SAVE_VIDEO, result);

    return result;
#else
    param->flag->isRecSaveSuccess = VFX_TRUE;
    return MDI_RES_VDOREC_SUCCEED;
#endif

}

MDI_RESULT vapp_camco_rec_fetch_frame(vapp_camco_rec_fetch_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

#if defined(__MTK_TARGET__)
    mdi_video_info_struct video_info;

    VAPP_CAMCO_START_LOGGING("ARF");

    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);

    ret = mdi_video_ply_open_clip_file(param->obj->m_appID, (CHAR *)param->fileName, &video_info);

    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_FETCH_FRAME, ret);
        return ret;
    }
    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_set_color_format(mdi_video_ply_get_default_frame_color_format());

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // draw on a temp layer to make sure the content is full size cliping
    gdi_handle handleS;
    VfxU16 width, height;
    if(param->obj->m_isOSDHorz != param->isRecWithHorzUI)
    {
        gdi_layer_create_cf_using_outside_memory(
            mdi_video_ply_get_default_frame_color_format(),
            0,
            0,
            param->previewFrame->getSize().height,
            param->previewFrame->getSize().width,
            &handleS,
            (U8*)param->quickviewBuffer,
            param->previewFrame->getSize().width*param->previewFrame->getSize().height*2);
        width = param->previewFrame->getSize().height;
        height = param->previewFrame->getSize().width;
    }
    else
    {
        gdi_layer_create_cf_using_outside_memory(
            mdi_video_ply_get_default_frame_color_format(),
            0,
            0,
            param->previewFrame->getSize().width,
            param->previewFrame->getSize().height,
            &handleS,
            (U8*)param->quickviewBuffer,
            param->previewFrame->getSize().width*param->previewFrame->getSize().height*2);

        width = param->previewFrame->getSize().width;
        height = param->previewFrame->getSize().height;
    }

    ret = mdi_video_ply_seek_and_get_frame(0, handleS);
#else
    ret = mdi_video_ply_seek_and_get_frame(0, handleT);
#endif

    mdi_video_ply_close_clip_file();

    mdi_util_hw_layer_switch_to_sw_layer(handleT);

    gdi_layer_pop_and_restore_active();

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_resize(param->previewFrame->getSize().width, param->previewFrame->getSize().height);
    gdi_layer_set_position(0, 0);
    gdi_layer_pop_and_restore_active();

    // rotate the layer on preview layer
    if(param->obj->m_isOSDHorz)
    {
        if(param->isRecWithHorzUI)
        {
            mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_0);
        }
        else
        {
            if(param->isRecWithMirrorUI)
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_90);
            }
            else
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_270);
            }
        }
    }
    else
    {
        if(param->isRecWithHorzUI)
        {
            if(param->isRecWithMirrorUI)
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_270);
            }
            else
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_90);
            }
        }
        else
        {
            mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_0);
        }
    }
    gdi_layer_free(handleS);
#endif
    VAPP_CAMCO_STOP_LOGGING("ARF");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_FETCH_FRAME, ret);

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
};


MDI_RESULT vapp_camco_cam_get_estimated_picture_size(vapp_camco_estimate_size_param_struct *param)
{
    U16 image_qty;
    U16 image_width;
    U16 image_height;
    MDI_RESULT ret;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_GET_EST_SIZE);

    image_qty = MDI_CAMERA_JPG_QTY_HIGH;

    ((CapSizeSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE),
        &image_width,
        &image_height);

    ret =  mdi_camera_get_predicted_image_size(image_qty, image_width, image_height, &param->size);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_GET_EST_SIZE_F,
        image_qty,
        image_width,
        image_height,
        param->size);

    return ret;
}

MDI_RESULT vapp_camco_rec_get_estimated_video_size(vapp_camco_estimate_size_param_struct *param)
{
    mdi_video_rec_query_bitrate_struct spec;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_GET_EST_SIZE);

    spec.quality = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISQTY);
    spec.video_format = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISCODEC);
    spec.video_size = param->Setting->getMappingID(VAPP_CAMCO_SETTING_RECSIZE);
    if(param->Setting->getValue(VAPP_CAMCO_SETTING_VDOSTORAGE) == SRV_FMGR_DRV_CARD_TYPE)
    {
        spec.storage = MDI_VIDEO_REC_STORAGE_SD;
    }
    else
    {
        spec.storage = MDI_VIDEO_REC_STORAGE_PHONE;
    }

    mdi_video_rec_query_bitrate(&spec, &param->size);

    // make the unit is byte
    param->size /= 8;

    mdi_video_rec_get_reserved_disc_size(&param->reserve_size);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_GET_EST_SIZE_F,
        spec.quality,
        spec.video_format,
        spec.video_size,
        spec.storage,
        param->size,
        param->reserve_size);

    return MDI_RES_VDOREC_SUCCEED;
}

MDI_RESULT vapp_camco_background_calculation_start(vapp_camco_cal_background_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_BG_CAL_START, param->flag->isCalBgProcessOn);

    if(!param->flag->isCalBgProcessOn)
    {
        mdi_camera_resume_preview_post_process();
        param->flag->isCalBgProcessOn = VFX_TRUE;
    }
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_camco_background_calculation_stop(vapp_camco_cal_background_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_BG_CAL_STOP, param->flag->isCalBgProcessOn);

    if(param->flag->isCalBgProcessOn)
    {
        mdi_camera_pause_preview_post_process();
        param->flag->isCalBgProcessOn = VFX_FALSE;
    }

    return MDI_RES_CAMERA_SUCCEED;
}
#pragma arm section code, rodata


#endif /*__VAPP_CAMCO_SLIM__*/
