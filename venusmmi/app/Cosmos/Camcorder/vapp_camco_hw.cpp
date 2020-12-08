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
#include "iul_csc_y2r.h"
#ifdef __cplusplus
}
#endif

#include "MMI_include.h"
#include "MMI_features_camcorder.h"     /* features */
#include "vapp_camco_gprot.h"
#include "vapp_camco_hw.h"
#include "gdi_include.h"


#ifdef __VAPP_CAMCO__
VappCamcoPage* vapp_camco_hw_object; 

MDI_RESULT vapp_camco_reset_hw_obj(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_RESET_HW_OBJ, 1);    

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
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_PREVIEW_START, param->flag->isPreviewStart);    

    vapp_camco_hw_object = param->obj;
    
#if defined(__MTK_TARGET__) 

    if(param->flag->isPreviewStart)
        return MDI_RES_CAMERA_SUCCEED;

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
    camera_setting_data.ev = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAMEV);
    camera_setting_data.banding = param->Setting->getMappingID(VAPP_CAMCO_SETTING_BANDING);
    if(param->Setting->getStatus(VAPP_CAMCO_SETTING_FLASH) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        camera_setting_data.flash = param->Setting->getMappingID(VAPP_CAMCO_SETTING_FLASH);
    }        
    else
    {
        if(param->Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT) == VAPP_CAMCO_HIGHLIGHT_OFF)
            camera_setting_data.flash = param->Setting->getMappingID(VAPP_CAMCO_SETTING_FLASH, VAPP_CAMCO_FLASH_OFF);        
        else
            camera_setting_data.flash = param->Setting->getMappingID(VAPP_CAMCO_SETTING_FLASH, VAPP_CAMCO_FLASH_FORCE_ON);                
    }   

    camera_setting_data.iso = param->Setting->getMappingID(VAPP_CAMCO_SETTING_ISO);
    camera_setting_data.ae_meter = param->Setting->getMappingID(VAPP_CAMCO_SETTING_AEMETER);
    camera_setting_data.scene_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAMSCENEMODE);

    camera_setting_data.effect = param->Setting->getMappingID(VAPP_CAMCO_SETTING_EFFECT);
    camera_setting_data.saturation = param->Setting->getMappingID(VAPP_CAMCO_SETTING_SATURATION);
    camera_setting_data.contrast = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CONTRAST);
    camera_setting_data.hue = 0;
                
    camera_setting_data.overlay_frame_mode = FALSE;
    camera_setting_data.overlay_frame_depth = 0;
    camera_setting_data.overlay_frame_width = 0;
    camera_setting_data.overlay_frame_height = 0;
    camera_setting_data.overlay_frame_source_key = 0;
    camera_setting_data.overlay_frame_buffer_address = 0;

    camera_setting_data.overlay_palette_size = 0;
    camera_setting_data.overlay_palette_addr = NULL;
    
    camera_setting_data.preview_width = param->previewWindow->getWidth();
    camera_setting_data.preview_height = param->previewWindow->getHeight();

    /* capture parameters */
    camera_setting_data.image_qty = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAPQTY);
    
    ((CapSizeSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE),
        &camera_setting_data.image_width, 
        &camera_setting_data.image_height);
    
    camera_setting_data.xenon_flash_status_callback = NULL;

    if (((FlashSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_FLASH)))->getFlashType() == VAPP_CAMCO_FLASH_TYPE_LED &&
        (param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL ||
         param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_HDR_SHOT ||
         param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT )
       )
    {
        camera_setting_data.flash = param->Setting->getMappingID(VAPP_CAMCO_SETTING_FLASH, VAPP_CAMCO_FLASH_OFF);
    }
    
#ifdef __FACE_DETECTION_SUPPORT__
    if (param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT ||
        param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
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

    camera_setting_data.af_range = param->Setting->getMappingID(VAPP_CAMCO_SETTING_AFRANGE);
    camera_setting_data.af_operation_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_AFZONE);
    camera_setting_data.sharpness = param->Setting->getMappingID(VAPP_CAMCO_SETTING_SHARPNESS);

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

    result = mdi_camera_preview_start_with_capmode(
        &camera_preview_data, 
        &camera_setting_data, 
        param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAPMODE),
        (void*)param->obj);

    if(result == MDI_RES_CAMERA_SUCCEED)
        param->flag->isPreviewStart = VFX_TRUE;
    else
        param->flag->isPreviewStart = VFX_FALSE;    

    param->flag->isTakepicFailed = VFX_FALSE;    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_PREVIEW_START, result);  
    
    return result;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif    

}

MDI_RESULT vapp_camco_cam_preview_stop(vapp_camco_cam_preview_stop_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_PREVIEW_STOP, param->flag->isPreviewStart);    

#if defined(__MTK_TARGET__) 

    if(param->flag->isPreviewStart)
    {
        if(param->Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
        {
            vapp_camco_cam_sd_param_struct p;
            p.flag = param->flag;
            vapp_camco_cam_sd_stop(&p);
        }
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
#endif    
    return MDI_RES_CAMERA_SUCCEED;
}


MDI_RESULT vapp_camco_rec_preview_start(vapp_camco_rec_preview_start_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_PREVIEW_START, param->flag->isPreviewStart);   

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
    video_preview_data.ev = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VDOEV);
    video_preview_data.banding = param->Setting->getMappingID(VAPP_CAMCO_SETTING_BANDING);
    video_preview_data.video_qty = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISQTY);
    video_preview_data.video_format = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VISCODEC);
    video_preview_data.effect = param->Setting->getMappingID(VAPP_CAMCO_SETTING_EFFECT);
    video_preview_data.video_size = param->Setting->getMappingID(VAPP_CAMCO_SETTING_RECSIZE);
    video_preview_data.user_def_width = 0;
    video_preview_data.user_def_height = 0;

    video_preview_data.zoom = param->Setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM); 
    video_preview_data.dsc_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_VDOSCENEMODE);

    video_preview_data.contrast = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CONTRAST);
    video_preview_data.saturation = param->Setting->getMappingID(VAPP_CAMCO_SETTING_SATURATION);
    video_preview_data.sharpness = param->Setting->getMappingID(VAPP_CAMCO_SETTING_SHARPNESS);
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

    video_preview_data.af_range = param->Setting->getMappingID(VAPP_CAMCO_SETTING_AFRANGE);
    video_preview_data.af_operation_mode = param->Setting->getMappingID(VAPP_CAMCO_SETTING_AFMODE);
    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;

#if defined(HORIZONTAL_CAMERA)
    video_preview_data.ui_rotate = GDI_LAYER_ROTATE_90;
#else
    video_preview_data.ui_rotate = GDI_LAYER_ROTATE_0;
#endif

    video_preview_data.size_limit = ((LimitSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getSizeLimit();
    video_preview_data.time_limit = ((LimitSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getTimeLimit() * 1000;
    video_preview_data.record_aud = param->Setting->getMappingID(VAPP_CAMCO_SETTING_RECAUD);

#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    if(param->Setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_ON)
    {
        video_preview_data.encode_one_frame_duration =  param->Setting->getMappingID(VAPP_CAMCO_SETTING_TIMELAPSEPERIOD);
    }
    else
    {
        video_preview_data.encode_one_frame_duration =  0;
    }
#else
    video_preview_data.encode_one_frame_duration =  0;
#endif

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

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_PREVIEW_START, result);       
    
    return result;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif


}

MDI_RESULT vapp_camco_rec_preview_stop(vapp_camco_rec_preview_stop_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_PREVIEW_STOP, param->flag->isPreviewStart);       

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
#endif    
    return MDI_RES_VDOREC_SUCCEED;    
}


MDI_RESULT vapp_camco_cam_power_on(vapp_camco_cam_power_on_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_POWER_ON, param->flag->isPowerOn);   

#if defined(__MTK_TARGET__) 
    if(!param->flag->isPowerOn)
    {
        mdi_camera_set_camera_id(param->Setting->getMappingID(VAPP_CAMCO_SETTING_ACT_CAM));
        MDI_RESULT ret = mdi_camera_power_on(param->obj->m_appID);
        
        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->flag->isPowerOn = VFX_TRUE;
        }
        
        MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_POWER_ON, ret);         
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
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_POWER_OFF, param->flag->isPowerOn);    

#if defined(__MTK_TARGET__) 

    if (param->flag->isPowerOn)
    {
        mdi_camera_power_off();
        param->flag->isPowerOn = VFX_FALSE;
    }

    vapp_camco_general_param_struct p;
    p.obj = param->obj;
    p.flag = param->flag;    
    vapp_camco_highlight_turn_off(&p);
#endif    
    return MDI_RES_CAMERA_SUCCEED;  

}

MDI_RESULT vapp_camco_rec_power_on(vapp_camco_rec_power_on_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_POWER_ON, param->flag->isPowerOn);    

#if defined(__MTK_TARGET__) 

    if(!param->flag->isPowerOn)
    {
        mdi_video_set_camera_id(param->Setting->getMappingID(VAPP_CAMCO_SETTING_ACT_CAM));
        MDI_RESULT ret = mdi_video_rec_power_on(param->obj->m_appID);
        
        if (ret == MDI_RES_VDOREC_SUCCEED)
        {
            param->flag->isPowerOn = VFX_TRUE;
        }
        MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_POWER_ON, ret);            
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
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_POWER_OFF, param->flag->isPowerOn);    

#if defined(__MTK_TARGET__) 

    if (param->flag->isPowerOn)
    {
        mdi_video_rec_power_off();
        param->flag->isPowerOn = VFX_FALSE;
    }

    vapp_camco_general_param_struct p;
    p.obj = param->obj;
    p.flag = param->flag;    
    vapp_camco_highlight_turn_off(&p);

#endif
    return MDI_RES_VDOREC_SUCCEED;  
}



MDI_RESULT vapp_camco_cam_normal_shot(vapp_camco_cam_capture_param_struct *param)
{

    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;

#if defined(__MTK_TARGET__)    

    if (mdi_camera_is_ready_to_capture())
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();       
        gdi_layer_push_and_set_active(handleT);

        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

        mdi_camera_set_quickview_rotation(MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG);

    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        if(param->obj->isHorzUI() == param->obj->m_isOSDHorz)
        {
    #endif
            ret = mdi_camera_capture_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewWindow->getWidth(),
                param->previewWindow->getHeight(),
                (CHAR *)param->fileName);
    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        }
        else
        {
            ret = mdi_camera_capture_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewWindow->getHeight(),
                param->previewWindow->getWidth(),
                (CHAR *)param->fileName);
        }
    #endif

        if (ret == MDI_RES_CAMERA_SUCCEED)
            ret = mdi_camera_encode_capture_image((U8**)&param->capture_buf_ptr, &param->capture_size);

        //mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();        
    }
#endif

#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW

        WCHAR fileName[30];
        CHAR fileNameAsc[15] = "";
        
        sprintf(fileNameAsc, "%c:\\5.bmp", SRV_FMGR_CARD_DRV);    
        mmi_asc_to_wcs(fileName, fileNameAsc);
        
        VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));
        
        param->obj->m_picturePreviewFrame->setImgContent(s);
            
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_NORMAL_SHOT, ret);    

    if(ret != MDI_RES_CAMERA_SUCCEED)
        param->flag->isTakepicFailed = VFX_TRUE;       
    
    return ret;
    
}

MDI_RESULT vapp_camco_cam_addframe_shot(vapp_camco_cam_capture_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    
    
#if defined(__MTK_TARGET__) 
    if (mdi_camera_is_ready_to_capture())
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();   
        gdi_layer_push_and_set_active(handleT);    
                
        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);
        mdi_camera_set_quickview_rotation(MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG);

    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        if(param->obj->isHorzUI() == param->obj->m_isOSDHorz)
        {
    #endif
            ret = mdi_camera_capture_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewWindow->getWidth(),
                param->previewWindow->getHeight(),
                (CHAR *)param->fileName);
    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        }
        else
        {
            ret = mdi_camera_capture_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewWindow->getHeight(),
                param->previewWindow->getWidth(),
                (CHAR *)param->fileName);
        }
    #endif

        if (ret == MDI_RES_CAMERA_SUCCEED)
            ret = mdi_camera_encode_capture_image((U8**)&param->capture_buf_ptr, &param->capture_size);
        //mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();           

    }
#endif
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_ADDFRAME_SHOT, ret);    

    if(ret != MDI_RES_CAMERA_SUCCEED)
        param->flag->isTakepicFailed = VFX_TRUE;       
    
    return ret;

}

MDI_RESULT vapp_camco_cam_bestshot(vapp_camco_cam_capture_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    
    
#if defined(__MTK_TARGET__) 
    if (mdi_camera_is_ready_to_capture())
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);

        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

        ret = mdi_camera_capture_to_memory_best_shot(
                (U8**)&param->capture_buf_ptr, 
                &param->capture_size,
                (U8*)param->buffer,
                param->buffer_size);   
            
        
        gdi_lcd_lock_mutex();
        gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
        gdi_layer_clear(GDI_COLOR_BLACK);                
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();
    }
#endif 
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_BESTSHOT, ret);    

    if(ret != MDI_RES_CAMERA_SUCCEED)
        param->flag->isTakepicFailed = VFX_TRUE;       
    
    return ret;


}

MDI_RESULT vapp_camco_cam_contshot(vapp_camco_cam_capture_param_struct *param)
{
#if defined(__MTK_TARGET__) 

    MDI_RESULT ret = VAPP_CAMCO_CAM_NOT_READY;


    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

    mdi_camera_set_quickview_rotation(MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG);

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    if(param->obj->isHorzUI() == param->obj->m_isOSDHorz)
    {
#endif    
        ret = mdi_camera_capture_continuous_shot_with_quickview(
                    (U32)param->obj->m_prepareFramePtr,
                    (U32)param->obj->m_prepareFrameSize,
                    param->previewWindow->getWidth(),
                    param->previewWindow->getHeight(),
                    (CHAR *)param->fileName);
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    }
    else
    {
        ret = mdi_camera_capture_continuous_shot_with_quickview(
                    (U32)param->obj->m_prepareFramePtr,
                    (U32)param->obj->m_prepareFrameSize,
                    param->previewWindow->getHeight(),
                    param->previewWindow->getWidth(),
                    (CHAR *)param->fileName);
    }
#endif

    if (ret == MDI_RES_CAMERA_SUCCEED)
    {
        ret = vapp_camco_cam_save_capture_image(NULL);
    }
    else
    {
        param->flag->isTakepicFailed = VFX_TRUE;        
    }        

    //mdi_util_hw_layer_switch_to_sw_layer(handleT);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_CONTSHOT, ret);    

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}


static void vapp_camco_cam_burstshot_result_hdlr(MDI_RESULT ret, U16 captured_count, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_BURSTSHOT;
    param.burstShotRet = ret;
    param.burstShotCapturedCount = captured_count;    

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_BURSTSHOT_CALLBACK, ret);    

    if(vapp_camco_hw_object)
        vapp_camco_hw_object->resultHWCallback(param);

    if(captured_count == MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT)
    {
        gdi_handle handleT = vapp_camco_hw_object->m_previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);
        gdi_lcd_lock_mutex();
        gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();
    }
}

MDI_RESULT vapp_camco_cam_burstshot(vapp_camco_cam_capture_param_struct *param)
{
    vapp_camco_hw_object = param->obj;

    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    

    MDI_RESULT ret = VAPP_CAMCO_CAM_NOT_READY;

#if defined(__MTK_TARGET__) 
#if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__)
    if (mdi_camera_is_ready_to_capture())
    {
        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        if(param->obj->isHorzUI() == param->obj->m_isOSDHorz)
        {
    #endif
            ret = mdi_camera_capture_to_memory_burst_shot_with_quickview(
                    MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT,
                    param->burstShotJpgData,
                    vapp_camco_cam_burstshot_result_hdlr,
                    (U8*) param->buffer,
                    param->buffer_size,
                    (U32)param->obj->m_prepareFramePtr,
                    (U32)param->obj->m_prepareFrameSize,
                    param->previewWindow->getWidth(),
                    param->previewWindow->getHeight(),
                    (void*)vapp_camco_hw_object);
    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        }
        else
        {
            ret = mdi_camera_capture_to_memory_burst_shot_with_quickview(
                    MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT,
                    param->burstShotJpgData,
                    vapp_camco_cam_burstshot_result_hdlr,
                    (U8*) param->buffer,
                    param->buffer_size,
                    (U32)param->obj->m_prepareFramePtr,
                    (U32)param->obj->m_prepareFrameSize,
                    param->previewWindow->getHeight(),
                    param->previewWindow->getWidth(),
                    (void*)vapp_camco_hw_object);
        }
    #endif
    }

    if(ret == MDI_RES_CAMERA_SUCCEED)
    {
        param->flag->isBurstshotFinish = VFX_FALSE;
    }    
    else
    {
        param->flag->isTakepicFailed = VFX_TRUE;   
    }
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_BURSTSHOT, ret);    

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
}

MDI_RESULT vapp_camco_cam_burstshot_stop(vapp_camco_cam_capture_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_BURSTSHOT_STOP, 0);    

    mdi_camera_stop_non_block_burst_capture();

    return MDI_RES_CAMERA_SUCCEED;
}


MDI_RESULT vapp_camco_cam_aebshot(vapp_camco_cam_capture_param_struct *param)
{
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    

#if defined(__MTK_TARGET__) 
#if defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
    MDI_RESULT ret = VAPP_CAMCO_CAM_NOT_READY;

    if (mdi_camera_is_ready_to_capture())
    {
        vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);
        
        ret = mdi_camera_capture_to_memory_bracketing(
                param->aebShotJpgData,        
                (U8*) param->buffer,
                param->buffer_size);        

        gdi_handle handleT = param->previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);
        gdi_lcd_lock_mutex();
        gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();
    }
    if(ret != MDI_RES_CAMERA_SUCCEED)
    {
        param->flag->isTakepicFailed = VFX_TRUE;    
    }
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_AEBSHOT, ret);       
    
    return ret;    
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif         
}

MDI_RESULT vapp_camco_cam_smiledetect_get_result(vapp_camco_cam_sd_param_struct *param)
{
#if defined(__MTK_TARGET__) 
#if defined(__SMILE_SHUTTER_SUPPORT__)  
    param->fd_result = MDI_RES_CAMERA_ERR_FAILED;
    param->sd_end_flag = KAL_FALSE;

    mdi_camera_fd_result_struct fdResult;
    
    mdi_camera_get_fd_result(&fdResult);

    param->fd_result = fdResult.fd_result;
    param->fd_searched_num = fdResult.fd_searched_num;
    param->sd_end_flag = fdResult.sd_end_flag;
    param->sd_searched_num = fdResult.sd_searched_num;

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SMILEDETECT_GET_RESULT, param->fd_result);    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SMILEDETECT_GET_RESULT, param->fd_searched_num);    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SMILEDETECT_GET_RESULT, param->sd_end_flag);    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SMILEDETECT_GET_RESULT, param->sd_searched_num);        

    for(VfxU32 i = 0; i < MDI_CAMERA_FD_MAX_NO; i++)
    {
        memcpy((void*)(&param->fd_zone[i]), (void*)(&fdResult.fd_zone[i]), sizeof(mdi_camera_fd_zone_struct));
    }
    
    return MDI_RES_CAMERA_SUCCEED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}

MDI_RESULT vapp_camco_cam_scenedetect_get_result(vapp_camco_cam_scene_param_struct *param)
{
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    param->currentScene = mdi_camera_get_detected_scene_mode();
#endif
    return MDI_RES_CAMERA_SUCCEED;    
}

void vapp_camco_cam_hdr_shot_result_callback(mdi_camera_hdr_result_struct* result_ind, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    if(result_ind->buffer_type == MDI_CAMERA_HDR_CAPTURE_QUICKVIEW)
        param.type = VAPP_CAMCO_CB_TYPE_HDRSHOT_CAPTURE;  
    else if(result_ind->buffer_type == MDI_CAMERA_HDR_PROCESSED_QUICKVIEW)
        param.type = VAPP_CAMCO_CB_TYPE_HDRSHOT_PROCESS;          
    else if(result_ind->buffer_type == MDI_CAMERA_HDR_PROCESSED_MAINIMAGE)
        param.type = VAPP_CAMCO_CB_TYPE_HDRSHOT_DONE;                  
    else
        return;
    
    param.buffer_address = result_ind->buffer_address;
    param.buffer_size = result_ind->buffer_size;    
    param.HDRresult = result_ind->result;
    
    vapp_camco_hw_object->m_previewFrame->setHidden(VFX_FALSE);

    if(vapp_camco_hw_object)
        vapp_camco_hw_object->resultHWCallback(param);

}

MDI_RESULT vapp_camco_cam_hdr_shot_stop(vapp_camco_cam_hdr_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    vapp_camco_hw_object->m_previewFrame->setHidden(VFX_FALSE);

    ret = mdi_camera_stop_non_blocking_hdr_shot((CHAR *)param->fileNameOrigin);

    param->flag->isHDRing = VFX_FALSE;
    
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_cam_hdr_shot_save(vapp_camco_cam_hdr_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    ret = mdi_camera_save_hdr_images((CHAR *)param->fileNameOrigin, (CHAR *)param->fileNameHDR);

    param->flag->isHDRing = VFX_FALSE;    
    
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_cam_hdr_shot_start(vapp_camco_cam_hdr_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    param->previewFrame->setHidden(VFX_TRUE);

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);

    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;

    vapp_camco_set_rotation(param->obj->m_Setting, VFX_TRUE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

    mdi_camera_set_quickview_rotation(MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG);

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    if(param->obj->isHorzUI() == param->obj->m_isOSDHorz)
    {
#endif
        ret = mdi_camera_capture_hdr_shot_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewFrame->getSize().width,
                param->previewFrame->getSize().height,
                vapp_camco_cam_hdr_shot_result_callback,
                (void*)vapp_camco_hw_object);
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    }
    else
    {
        ret = mdi_camera_capture_hdr_shot_with_quickview(
                (U32)param->obj->m_prepareFramePtr,
                (U32)param->obj->m_prepareFrameSize,
                param->previewFrame->getSize().height,
                param->previewFrame->getSize().width,
                vapp_camco_cam_hdr_shot_result_callback,
                (void*)vapp_camco_hw_object);
    }
#endif

    if(ret == MDI_RES_CAMERA_SUCCEED)
        param->flag->isHDRing = VFX_TRUE;

    //mdi_util_hw_layer_switch_to_sw_layer(handleT);
    gdi_layer_pop_and_restore_active();

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SAVE_CAPTURE_IMAGE, ret);   

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}    

MDI_RESULT vapp_camco_cam_save_capture_image(vapp_camco_cam_capture_save_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret;

    ret = mdi_camera_save_captured_image();
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SAVE_CAPTURE_IMAGE, ret);   

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

void vapp_camco_cam_sd_result_hdlr(mdi_camera_sd_event_struct* sd_event_p, void* user_data)
{
}

MDI_RESULT vapp_camco_cam_sd_start(vapp_camco_cam_sd_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SD_START, param->flag->isSmiledetectStart);   

#ifdef __SMILE_SHUTTER_SUPPORT__
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    if(!param->flag->isSmiledetectStart)
    {
        ret = mdi_camera_start_sd(vapp_camco_cam_sd_result_hdlr, (void*)param->obj);
        if(ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->flag->isSmiledetectStart = VFX_TRUE;
        }
    }    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SD_START, ret);       
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_cam_sd_stop(vapp_camco_cam_sd_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SD_STOP, param->flag->isSmiledetectStart);      

#ifdef __SMILE_SHUTTER_SUPPORT__
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

    if(param->flag->isSmiledetectStart)
    {
        ret = mdi_camera_stop_sd();
        if(ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->flag->isSmiledetectStart = VFX_FALSE;
        }
    }     
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_SD_STOP, ret);          
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif


}

void vapp_camco_rec_record_result_hdlr(MDI_RESULT result, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_RECORD_FINISH;
    param.recordRet = result;

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_CALLBACK, result);        
    
    if(vapp_camco_hw_object)
        vapp_camco_hw_object->resultHWCallback(param);   
}

MDI_RESULT vapp_camco_rec_preview_set_rot(VfxS32 flag)
{
    mdi_video_rec_force_set_ui_rotate(flag);    

    return MDI_RES_VDOREC_SUCCEED;
}


MDI_RESULT vapp_camco_rec_record_start(vapp_camco_rec_record_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_START, param->flag->isPreviewStart);  

#if defined(__MTK_TARGET__) 
    MDI_RESULT ret;

    vapp_camco_hw_object = param->obj;
    
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    

    vapp_camco_set_rotation(param->obj->m_Setting, VFX_FALSE, param->obj->isHorzUI(), param->obj->m_isOSDHorz, param->obj->m_isOSDMirror);

    ret = mdi_video_rec_record_start((CHAR *)param->fileName, vapp_camco_rec_record_result_hdlr, vapp_camco_hw_object);
    
    if(ret == MDI_RES_VDOREC_SUCCEED)
    {
        param->flag->isOnRecord = VFX_TRUE;        
    }
    else
    {
        param->flag->isRecordFailed = VFX_TRUE;        
    }
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_START, ret);      
    return ret;
#else
    param->flag->isOnRecord = VFX_TRUE;
    return MDI_RES_VDOREC_SUCCEED;
#endif    
}

MDI_RESULT vapp_camco_rec_record_stop(vapp_camco_rec_record_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_STOP, param->flag->isOnRecord);      

#if defined(__MTK_TARGET__) 
    MDI_RESULT ret = MDI_RES_VDOREC_SUCCEED;    

    if (param->flag->isOnRecord)
    {
        gdi_handle handleT = param->previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);    
        
        ret  = mdi_video_rec_record_stop();

        gdi_layer_pop_and_restore_active();         

        param->flag->isOnRecord = VFX_FALSE;
        param->flag->isPreviewStart = VFX_FALSE;        
    }
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_STOP, ret);          
    return ret;
    
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif
}

MDI_RESULT vapp_camco_rec_record_pause(vapp_camco_rec_record_param_struct *param)
{
#if defined(__MTK_TARGET__) 

    MDI_RESULT ret;

    ret = mdi_video_rec_record_pause(KAL_FALSE);

    param->flag->isPreviewStart = VFX_TRUE;
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_PAUSE, ret);        

    return ret;
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif

}

MDI_RESULT vapp_camco_rec_record_resume(vapp_camco_rec_record_param_struct *param)
{
#if defined(__MTK_TARGET__) 

    MDI_RESULT ret;

    ret = mdi_video_rec_record_resume();

    param->flag->isPreviewStart = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_RECORD_RESUME, ret);        

    return ret;
    
#else
    return MDI_RES_VDOREC_SUCCEED;
#endif

}

MDI_RESULT vapp_camco_rec_record_get_time(VfxU64 *time)
{
    mdi_video_rec_get_cur_record_time((U64*)time);
    
    return MDI_RES_VDOREC_SUCCEED;    
}

MDI_RESULT vapp_camco_rec_record_get_size(VfxU64 *size)
{
    (*size) = mdi_video_rec_get_record_file_size();
    
    return MDI_RES_VDOREC_SUCCEED;    
}

MDI_RESULT vapp_camco_rec_record_get_count(VfxU64 *count)
{
#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    mdi_video_rec_get_record_frame_num((U64*)count);
#else
    mdi_video_rec_get_cur_record_time((U64*)count);
#endif

    return MDI_RES_VDOREC_SUCCEED;
}

static void vapp_camco_rec_save_result_hdlr(MDI_RESULT result, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_RECORD_SAVE;
    param.recordRet = result;

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_SAVE_VIDEO_RESULT, result);  
    
    if(vapp_camco_hw_object)                 
        vapp_camco_hw_object->resultHWCallback(param);   
}

MDI_RESULT vapp_camco_rec_stop_save_video(void)
{
#if defined(__MTK_TARGET__) 
    mdi_video_rec_stop_save();
#endif
    return MDI_RES_VDOREC_SUCCEED;
}


MDI_RESULT vapp_camco_rec_save_video(vapp_camco_rec_record_save_param_struct *param)
{

#if defined(__MTK_TARGET__) 
    MDI_RESULT result = MDI_RES_VDOREC_SUCCEED;

    vapp_camco_hw_object = param->obj;

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
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_SAVE_VIDEO, result);    
    
    return result;
#else

    param->flag->isRecSaveSuccess = VFX_TRUE;
    
    param->save_timer->setStartDelay(2000);
    param->save_timer->start();

    return MDI_RES_VDOREC_SUCCEED;
#endif

}


MDI_RESULT vapp_camco_rec_fetch_frame(vapp_camco_rec_fetch_param_struct *param)
{    
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

#if defined(__MTK_TARGET__) 
    mdi_video_info_struct video_info;

    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);      
    
    ret = mdi_video_ply_open_clip_file(param->obj->m_appID, (CHAR *)param->fileName, &video_info);  
    
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_FETCH_FRAME, ret);      
        return ret;
    }
    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);    
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);    

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // draw on a temp layer to make sure the content is full size cliping    
    gdi_handle handleS;
    VfxU16 width, height;
    if(param->obj->isHorzUI() != param->isRecWithHorzUI)
    {
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
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
            GDI_COLOR_FORMAT_16,
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

    gdi_layer_pop_and_restore_active(); 
    
    mdi_video_ply_close_clip_file();

    mdi_util_hw_layer_switch_to_sw_layer(handleT);    

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // rotate the layer on preview layer 
    if(param->obj->isHorzUI())
    {
        if(param->isRecWithHorzUI)
        {
            if(param->isRecWithMirrorUI)
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_180);
            }
            else
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_0);            
            }
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
            if(param->isRecWithMirrorUI)
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_180);             
            }
            else
            {
                mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_0);             
            }        
        }    
    }  
    gdi_layer_free(handleS);
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_FETCH_FRAME, ret);      

    return ret;    
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif

};


MDI_RESULT vapp_camco_bk_turn_on(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_BK_TURN_ON, 0);     

    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    return MDI_RES_CAMERA_SUCCEED;    
}

MDI_RESULT vapp_camco_bk_turn_off(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_BK_TURN_OFF, 0);

    srv_backlight_turn_off();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);    
    return MDI_RES_CAMERA_SUCCEED;    
}

MDI_RESULT vapp_camco_highlight_turn_on(vapp_camco_general_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_HIGHLIGHT_TURN_ON, 0);

#if defined(__MTK_TARGET__) 

    if (!param->flag->isHightlightOn)
    {
        mdi_camera_flash_setting(TRUE);
        param->flag->isHightlightOn = VFX_TRUE;
    }
    return MDI_RES_CAMERA_SUCCEED;    
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
};

MDI_RESULT vapp_camco_highlight_turn_off(vapp_camco_general_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_HIGHLIGHT_TURN_OFF, 0);

#if defined(__MTK_TARGET__) 

    if (param->flag->isHightlightOn)
    {
        mdi_camera_flash_setting(FALSE);
        param->flag->isHightlightOn = VFX_FALSE;
    }
    return MDI_RES_CAMERA_SUCCEED;    
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif

};

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
static void vapp_camco_cam_autofocus_result_hdlr(mdi_camera_af_result_struct result_ind, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;
    
    memcpy(&param.afRet, &result_ind, sizeof(mdi_camera_af_result_struct));
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_GET_AUTOFOCUS_RESULT, param.afRet.af_success_zone);

    param.type = VAPP_CAMCO_CB_TYPE_CAM_AF;
    if(vapp_camco_hw_object)    
        vapp_camco_hw_object->resultHWCallback(param);
}
#endif

MDI_RESULT vapp_camco_cam_autofocus_start(vapp_camco_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_AUTOFOCUS_START, param->flag->isAFon);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    vapp_camco_hw_object = param->obj;
    
    if(!param->flag->isAFon)
    {
        mdi_camera_start_autofocus_process(vapp_camco_cam_autofocus_result_hdlr, (void*)vapp_camco_hw_object);

        param->flag->isAFon = VFX_TRUE;

    }
    param->flag->isAFsuccess = VFX_FALSE;
#else    
    param->flag->isAFon = VFX_TRUE;    
    param->af_timer->setStartDelay(3000);
    param->af_timer->start();
    param->flag->isAFsuccess = VFX_FALSE;
#endif   
#endif
    return MDI_RES_CAMERA_SUCCEED;

};


MDI_RESULT vapp_camco_cam_autofocus_stop(vapp_camco_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_AUTOFOCUS_STOP, param->flag->isAFon);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    if (param->flag->isAFon)
    {
        mdi_camera_stop_autofocus_process();

        param->flag->isAFon = VFX_FALSE;
    }
#else    
    param->af_timer->stop();
#endif
#endif
    return MDI_RES_CAMERA_SUCCEED;
}


MDI_RESULT vapp_camco_cam_get_autofocus_result(vapp_camco_autofocus_param_struct *param)
{

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    mdi_camera_get_focus_zone(&param->af_zone);
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_GET_AUTOFOCUS_RESULT, param->af_zone.af_active_zone);
#else    
    param->af_zone.af_active_zone = 1;
    param->af_zone.af_zone[0].af_zone_h = 50;
    param->af_zone.af_zone[0].af_zone_w = 50;    
    param->af_zone.af_zone[0].af_zone_x = 200;    
    param->af_zone.af_zone[0].af_zone_y = 150;        
#endif    
#endif    
    return MDI_RES_CAMERA_ERR_FAILED;

};

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
static void vapp_camco_rec_autofocus_result_hdlr(mdi_video_rec_af_result_struct result_ind, void* user_data)
{
    vapp_camco_hw_result_callback_param_struct param;
    
    memcpy(&param.recAfRet, &result_ind, sizeof(mdi_video_rec_af_result_struct));

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_GET_AUTOFOCUS_RESULT, param.recAfRet.af_success_zone);

    param.type = VAPP_CAMCO_CB_TYPE_REC_AF;
    if(vapp_camco_hw_object)    
        vapp_camco_hw_object->resultHWCallback(param);
}
#endif

MDI_RESULT vapp_camco_rec_autofocus_start(vapp_camco_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_AUTOFOCUS_START, param->flag->isAFon);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    vapp_camco_hw_object = param->obj;

    if(!param->flag->isAFon)
    {
        mdi_video_rec_start_autofocus_process(vapp_camco_rec_autofocus_result_hdlr, (void*)vapp_camco_hw_object);

        param->flag->isAFon = VFX_TRUE;        
    }
    param->flag->isAFsuccess = VFX_FALSE;    
#else    
    param->flag->isAFon = VFX_TRUE;
    param->af_timer->setStartDelay(3000);
    param->af_timer->start();    
    param->flag->isAFsuccess = VFX_FALSE;        
#endif   
#endif
    return MDI_RES_VDOREC_SUCCEED;
};


MDI_RESULT vapp_camco_rec_autofocus_stop(vapp_camco_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_AUTOFOCUS_STOP, param->flag->isAFon);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 

    if (param->flag->isAFon)
    {
        mdi_video_rec_stop_autofocus_process();

        param->flag->isAFon = VFX_FALSE;
    }
#else    
    param->af_timer->stop();    
#endif
#endif
    return MDI_RES_VDOREC_SUCCEED;
}


MDI_RESULT vapp_camco_rec_get_autofocus_result(vapp_camco_autofocus_param_struct *param)
{
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    mdi_video_rec_get_focus_zone(&param->rec_af_zone);
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_GET_AUTOFOCUS_RESULT, param->rec_af_zone.af_active_zone);
#else    
    param->rec_af_zone.af_active_zone = 1;
    param->rec_af_zone.af_zone[0].af_zone_h = 50;
    param->rec_af_zone.af_zone[0].af_zone_w = 50;    
    param->rec_af_zone.af_zone[0].af_zone_x = 200;    
    param->rec_af_zone.af_zone[0].af_zone_y = 150;        
#endif    
#endif  
    return MDI_RES_CAMERA_ERR_FAILED;
 
};

MDI_RESULT vapp_camco_cam_get_estimated_picture_size(vapp_camco_estimate_size_param_struct *param)
{
    U16 image_qty;
    U16 image_width; 
    U16 image_height;
    MDI_RESULT ret;

    image_qty = param->Setting->getMappingID(VAPP_CAMCO_SETTING_CAPQTY);
    
    ((CapSizeSetting*)(param->Setting->getSetting(VAPP_CAMCO_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE),
        &image_width, 
        &image_height);

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_GET_EST_SIZE, param->size, param->reserve_size);

    ret =  mdi_camera_get_predicted_image_size(image_qty, image_width, image_height, &param->size);

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_CAM_GET_EST_SIZE, 
        image_qty,
        image_width,
        image_height,
        param->size);

    return ret;
    
}

MDI_RESULT vapp_camco_rec_get_estimated_video_size(vapp_camco_estimate_size_param_struct *param)
{
    mdi_video_rec_query_bitrate_struct spec;

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

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_REC_GET_EST_SIZE, 
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
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_BG_CAL_START, param->flag->isCalBgProcessOn);

    if(!param->flag->isCalBgProcessOn)
    {
        mdi_camera_resume_preview_post_process();
        param->flag->isCalBgProcessOn = VFX_TRUE;
    }
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_camco_background_calculation_stop(vapp_camco_cal_background_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_BG_CAL_STOP, param->flag->isCalBgProcessOn);

    if(param->flag->isCalBgProcessOn)
    {
        mdi_camera_pause_preview_post_process();
        param->flag->isCalBgProcessOn = VFX_FALSE;        
    }

    return MDI_RES_CAMERA_SUCCEED;
}

void vapp_camco_draw_add_frame(
    void* buffer, 
    VfxU32* overlay_palette,     
    VfxU16 image_idx, 
    VfxU8 *palette_size, 
    VfxU32 **palette_address)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_DRAW_ADD_FRAME, image_idx);

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__

    gdi_color *p_gdi_palette;
    VfxU16 i;
    VfxU32 Y, U, V;
    VfxU32 R, G, B;
    VfxU32 *p_overlay_palette;
    GDI_RESULT result;
    VfxS32 image_width;
    VfxS32 image_height;
    
    gdi_handle handleT;

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)       
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
        MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
        &handleT,
        (PU8) ((PU8)buffer + ((MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4)),
        (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);
#else
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
        MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
        &handleT,
        (PU8) buffer,
        (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);

#endif
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    gdi_layer_resize(MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result < 0)
    {
        return;
    }

    if ((MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH >= image_width) && (MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT >= image_height))
    {
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
    }
    else
    {
        gdi_image_draw_resized_id_with_transparent_color(
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            (U16) (image_idx));
    }

    p_gdi_palette = gdi_layer_get_palette();

    *palette_size = gdi_image_gif_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = overlay_palette;
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((128 - 38 * R - 74 * G + 112 * B ) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_address = overlay_palette;

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)   
    // rotate to dst buffer
    gdi_handle handleS;
    if(vapp_camco_hw_object->isHorzUI() != vapp_camco_hw_object->m_isOSDHorz)
    {
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_8,
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            &handleS,
            (U8*)buffer,
            (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);
    }
    else
    {
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_8,
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            &handleS,
            (U8*)buffer,
            (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);
    }   
    
    if(vapp_camco_hw_object->isHorzUI())
    {
        if(vapp_camco_hw_object->m_isOSDHorz)
            if(vapp_camco_hw_object->m_isOSDMirror)
                mdi_util_rotate_layer_partial_region(handleT, 0, 0, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT, handleS, GDI_LAYER_ROTATE_0);
            else
                mdi_util_rotate_layer_partial_region(handleT, 0, 0, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT, handleS, GDI_LAYER_ROTATE_0);            
        else
            if(vapp_camco_hw_object->m_isOSDMirror)
                mdi_util_rotate_layer_partial_region(handleT, 0, 0, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT, handleS, GDI_LAYER_ROTATE_270);             
            else
                mdi_util_rotate_layer_partial_region(handleT, 0, 0, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT, handleS, GDI_LAYER_ROTATE_90);               
    }
    else
    {
        ASSERT(0);
    }  
    gdi_layer_free(handleS);

#endif

    gdi_layer_pop_and_restore_active();

    gdi_layer_free(handleT);
    
#endif
}


void vapp_camco_set_add_frame(VfxU32* palette_address, void* buffer)
{
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__

    mdi_camera_overlay_struct addframe_overlay;
 

    addframe_overlay.overlay_frame_mode = TRUE;
    addframe_overlay.overlay_frame_depth = MDI_CAMERA_OVERLAY_8BPP;
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)    
    if(vapp_camco_hw_object->isHorzUI() == vapp_camco_hw_object->m_isOSDHorz)
    {    
        addframe_overlay.overlay_frame_width = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH;
        addframe_overlay.overlay_frame_height = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT;
    }
    else        
    {    
        addframe_overlay.overlay_frame_width = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT;
        addframe_overlay.overlay_frame_height = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH;
    }   
#else
    addframe_overlay.overlay_frame_width = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH;
    addframe_overlay.overlay_frame_height = MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT;
#endif
    addframe_overlay.overlay_frame_source_key = gdi_image_gif_get_transparent_index();
    addframe_overlay.overlay_frame_buffer_address = (U32) buffer;

    addframe_overlay.overlay_palette_size = 255;
    addframe_overlay.overlay_palette_addr = palette_address;

    mdi_camera_update_overlay_data(&addframe_overlay);

#endif
}

#endif
