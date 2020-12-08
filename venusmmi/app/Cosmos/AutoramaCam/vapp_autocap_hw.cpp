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
#ifdef __cplusplus
}
#endif

#include "MMI_include.h"
#include "MMI_features_camcorder.h"     /* features */
#include "vapp_autocap_gprot.h"
#include "vapp_autocap_hw.h"
#include "gdi_include.h"


#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
VappAutoCapPage* vapp_autocap_hw_object; 

MDI_RESULT vapp_autocap_reset_hw_obj(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_RESET_HW_OBJ, 1);    

    vapp_autocap_hw_object = NULL;
    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_autocap_preview_start(vapp_autocap_preview_start_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PREVIEW_START, param->flag->isPreviewStart);    

    vapp_autocap_hw_object = param->obj;
    
#if defined(__MTK_TARGET__) 

    if(param->flag->isPreviewStart)
        return MDI_RES_CAMERA_SUCCEED;

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_lcd_lock_mutex();        
    gdi_waiting_blt_finish();
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_unlock_mutex();  
    gdi_layer_pop_and_restore_active();

    MDI_RESULT result;
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;

    /* preview parametes */
    camera_setting_data.zoom = param->Setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM);
    camera_setting_data.wb = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_WB);
    camera_setting_data.ev = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_CAMEV);
    camera_setting_data.banding = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_BANDING);
    camera_setting_data.flash = MDI_CAMERA_FLASH_OFF;
    camera_setting_data.iso = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_ISO);
    camera_setting_data.ae_meter = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_AEMETER);
    camera_setting_data.scene_mode = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);

    camera_setting_data.effect = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_EFFECT);
    camera_setting_data.saturation = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_SATURATION);
    camera_setting_data.contrast = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_CONTRAST);
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
    camera_setting_data.image_qty = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_CAPQTY);
    
    ((AutoCapCapSizeSetting*)(param->Setting->getSetting(VAPP_AUTOCAP_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE),
        &camera_setting_data.image_width, 
        &camera_setting_data.image_height);
        
    camera_setting_data.xenon_flash_status_callback = NULL;

#ifdef __FACE_DETECTION_SUPPORT__    
    camera_setting_data.fd_enable = FALSE;
    camera_setting_data.fd_callback = NULL;
#endif

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;

    camera_setting_data.af_range = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_AFRANGE);
    camera_setting_data.af_operation_mode = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_AFZONE);
    camera_setting_data.sharpness = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_SHARPNESS);

    camera_preview_data.preview_layer_handle = param->previewFrame->getLayerHandle();
    camera_preview_data.blt_layer_flag = param->previewFrame->getDisplayLayerFlag();
    camera_preview_data.preview_layer_flag = param->previewFrame->getHwLayerFlag();
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = FALSE;
    
    if(param->isResetZoom)        
        camera_setting_data.zoom = ((AutoCapCamZoomSetting*)(param->Setting->getSetting(VAPP_AUTOCAP_SETTING_CAMZOOM)))->getMinValue();
    else
        camera_setting_data.zoom = param->Setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM);
    
    if(!param->obj->m_param.isMultiAngleViewMode)
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__
        result = mdi_camera_preview_start_with_capmode(
            &camera_preview_data,
            &camera_setting_data,
            MDI_CAMERA_CAP_MODE_PANORAMA,
            (void*)param->obj);
    #else
        result = MDI_RES_CAMERA_ERR_CAPTURE_FAILED;
    #endif
    }
    else
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
        if(!param->obj->m_param.is3DCameraMode)
        {
            result = mdi_camera_preview_start_with_capmode(
                &camera_preview_data,
                &camera_setting_data,
                MDI_CAMERA_CAP_MODE_MAV,
                (void*)param->obj);
        }
    #else
        if(!param->obj->m_param.is3DCameraMode)
        {
            result = MDI_RES_CAMERA_ERR_CAPTURE_FAILED;
        }
    #endif
    #ifdef __MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__
        if(param->obj->m_param.is3DCameraMode)
        {
            result = mdi_camera_preview_start_with_capmode(
                &camera_preview_data,
                &camera_setting_data,
                MDI_CAMERA_CAP_MODE_3D_IMAGE,
                (void*)param->obj);
        }
    #else
        if(param->obj->m_param.is3DCameraMode)
        {
            result = MDI_RES_CAMERA_ERR_CAPTURE_FAILED;
        }
    #endif
    }

    if(result == MDI_RES_CAMERA_SUCCEED)
        param->flag->isPreviewStart = VFX_TRUE;
    else
        param->flag->isPreviewStart = VFX_FALSE;    

    param->flag->isTakepicFailed = VFX_FALSE;    
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PREVIEW_START, result);  
    
    return result;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif    

}

MDI_RESULT vapp_autocap_preview_stop(vapp_autocap_preview_stop_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PREVIEW_STOP, param->flag->isPreviewStart);    

#if defined(__MTK_TARGET__) 

    if(param->flag->isPreviewStart)
    {
        mdi_camera_preview_stop();
        
        param->flag->isPreviewStart = VFX_FALSE;
    }
#endif    
    return MDI_RES_CAMERA_SUCCEED;
}


MDI_RESULT vapp_autocap_power_on(vapp_autocap_power_on_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_POWER_ON, param->flag->isPowerOn);   

#if defined(__MTK_TARGET__) 
    if(!param->flag->isPowerOn)
    {
        mdi_camera_set_camera_id(param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_ACT_CAM));
        MDI_RESULT ret = mdi_camera_power_on(param->obj->m_appID);
        
        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            param->flag->isPowerOn = VFX_TRUE;
        }
        
        MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_POWER_ON, ret);         
        return ret;

    }
    else
#endif        
    {
        return MDI_RES_CAMERA_SUCCEED;    
    }

}

MDI_RESULT vapp_autocap_power_off(vapp_autocap_power_off_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_POWER_OFF, param->flag->isPowerOn);    

#if defined(__MTK_TARGET__) 

    if (param->flag->isPowerOn)
    {
        mdi_camera_power_off();
        param->flag->isPowerOn = VFX_FALSE;
    }

    vapp_autocap_general_param_struct p;
    p.obj = param->obj;
    p.flag = param->flag;    
    vapp_autocap_highlight_turn_off(&p);
#endif    
    return MDI_RES_CAMERA_SUCCEED;  

}


MDI_RESULT vapp_autocap_panorama_shot(vapp_autocap_capture_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;    

    MDI_RESULT ret = VAPP_AUTOCAP_NOT_READY;
    VfxU32 buffer_size = MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_MEM_SIZE / MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT;    

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_SHOT, param->panoramaShotData->capture_count);    

    mdi_camera_set_capture_rotation(MDI_CAMERA_UI_ROTATE_90);
    if (param->panoramaShotData->capture_count < MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT - 1)
    {
        ret = mdi_camera_capture_to_memory_panorama_with_quickview(
                (U8*)param->panoramaShotData->capture_buffer_p[param->panoramaShotData->capture_count],
                buffer_size,
                (U8**)&param->panoramaShotData->capture_buffer_p[param->panoramaShotData->capture_count],
                &param->panoramaShotData->capture_img_size[param->panoramaShotData->capture_count],
                param->panoramaShotData->capture_count + 1,
                param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION),
                (U32)param->quickviewBuffer + (param->panoramaShotData->capture_count) * ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * AUTOCAP_OSD_BYTE_PER_PIXEL * 2) / MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT),
                g_vapp_autocap_skin.previousIconSize[0] * g_vapp_autocap_skin.previousIconSize[1] * 2,
                g_vapp_autocap_skin.previousIconSize[0],
                g_vapp_autocap_skin.previousIconSize[1]);
    }
    else
    {
        ret = mdi_camera_capture_to_memory_panorama_with_quickview(
                (U8*)param->panoramaShotData->capture_buffer_p[param->panoramaShotData->capture_count],
                buffer_size,
                (U8**)&param->panoramaShotData->capture_buffer_p[param->panoramaShotData->capture_count],
                &param->panoramaShotData->capture_img_size[param->panoramaShotData->capture_count],
                param->panoramaShotData->capture_count + 1,
                param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION),
                NULL,
                0,
                0,
                0);
    }
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_SHOT, ret);    

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    
    gdi_layer_push_and_set_active(handleT);    
    gdi_lcd_lock_mutex();        
    gdi_waiting_blt_finish();           
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);    
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_unlock_mutex();        
    mdi_util_hw_layer_switch_to_sw_layer(handleT);
    gdi_layer_pop_and_restore_active();     

    if(ret != MDI_RES_CAMERA_SUCCEED)
        param->flag->isTakepicFailed = VFX_TRUE;
    
    return ret;
#else

#ifdef VAPP_AUTOCAP_MODIS_PIC_PREVIEW
        gdi_handle handleT;
    
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            g_vapp_autocap_skin.previousIconSize[0],
            g_vapp_autocap_skin.previousIconSize[1],
            &handleT,
            (U8*)param->quickviewBuffer,
            g_vapp_autocap_skin.previousIconSize[0]*g_vapp_autocap_skin.previousIconSize[1]*2);    
    
        gdi_layer_push_and_set_active(handleT);
    
        gdi_layer_clear(GDI_COLOR_BLACK);
    
        S32 image_width;
        S32 image_height;
        S32 result;
    
        WCHAR fileName[30];
        CHAR fileNameAsc[15] = "";
        
        sprintf(fileNameAsc, "%c:\\1.bmp", SRV_FMGR_CARD_DRV);    
        mmi_asc_to_wcs(fileName, fileNameAsc);
    
        result = gdi_image_get_dimension_file(
                    (CHAR*)fileName,
                    &image_width,
                    &image_height);
    
        if (result >= 0)
        {
            S32 offset_x;
            S32 offset_y;
            S32 resized_offset_x;
            S32 resized_offset_y;
            S32 resized_width;
            S32 resized_height;    
            
            gdi_image_util_fit_bbox(
                g_vapp_autocap_skin.previousIconSize[0],
                g_vapp_autocap_skin.previousIconSize[1],
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
    
            gdi_image_draw_resized_file(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                (U8*)fileName);
        }
        gdi_layer_pop_and_restore_active();    
        gdi_layer_free(handleT);
    
#endif

    return MDI_RES_CAMERA_SUCCEED;
#endif

}

static void vapp_autocap_panorama_stitch_result_hdlr(mdi_camera_panorama_stitch_result_struct* result_ind_p, void* user_data)
{
    vapp_autocap_hw_result_callback_param_struct param;

    param.type = VAPP_AUTOCAP_CB_TYPE_PANORAMA_STITCH;
    
    param.stitchRet.stitch_ind.result = result_ind_p->result;

    if (result_ind_p->result == MDI_RES_CAMERA_SUCCEED)
    {
        param.stitchRet.stitch_ind.jpeg_buffer_address = result_ind_p->jpeg_buffer_address;
        param.stitchRet.stitch_ind.jpeg_buffer_size = result_ind_p->jpeg_buffer_size;
        param.stitchRet.stitch_ind.jpeg_image_width = result_ind_p->jpeg_image_width;
        param.stitchRet.stitch_ind.jpeg_image_height = result_ind_p->jpeg_image_height;
    }

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_STITCH_RESULT, 
        0,
        result_ind_p->result,
        param.stitchRet.stitch_ind.jpeg_buffer_address,
        param.stitchRet.stitch_ind.jpeg_buffer_size,
        param.stitchRet.stitch_ind.jpeg_image_width,
        param.stitchRet.stitch_ind.jpeg_image_height);   
    
    if(vapp_autocap_hw_object)
        vapp_autocap_hw_object->resultHWCallback(param);
    
}

void vapp_autocap_panorama_quick_view_hdlr(mdi_camera_panorama_stitch_quickview_struct* result_ind, void* user_data)
{
    vapp_autocap_hw_result_callback_param_struct param;

    param.type = VAPP_AUTOCAP_CB_TYPE_PANORAMA_QUICK_VIEW;
    
    param.stitchRet.stitch_ind.result = result_ind->result;

    if (result_ind->result == MDI_RES_CAMERA_SUCCEED)
    {
        param.quickViewRet.quickview_start_x = 0;
        param.quickViewRet.quickview_start_y = 0;
        param.quickViewRet.quickview_width = result_ind->quickview_width;
        param.quickViewRet.quickview_height = result_ind->quickview_height;
        param.quickViewRet.result = result_ind->result;
    }

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_STITCH_RESULT, result_ind->result);   

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_STITCH_RESULT, 
        1,
        result_ind->result,
        param.quickViewRet.quickview_start_x,
        param.quickViewRet.quickview_start_y,
        param.quickViewRet.quickview_width,
        param.quickViewRet.quickview_height);  
    
    if(vapp_autocap_hw_object)
        vapp_autocap_hw_object->resultHWCallback(param);

}

MDI_RESULT vapp_autocap_panorama_stitch(vapp_autocap_panorama_stitch_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    U8 *dst_p;
    S32 width, height;
    S32 buf_size;

#if defined(__MTK_TARGET__) 
    vapp_autocap_hw_object = param->obj;

    mdi_camera_panorama_struct panorama_data;

    gdi_handle handleT = param->previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_get_dimension(&width, &height);
    buf_size = MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_CLIP_MEM_SIZE;
    gdi_layer_get_buffer_ptr(&dst_p);
    gdi_layer_pop_and_restore_active();

    panorama_data.image_num = param->panoramaShotData->capture_count;
    panorama_data.direction = (mdi_camera_panorama_direciton_enum)param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION);
    panorama_data.dest_jpeg_buffer_address = (U32) param->workingBuffer;
    panorama_data.dest_jpeg_buffer_size = param->workingBufferSize;

    for (VfxU32 idx = 0; idx < panorama_data.image_num; idx++)
    {
        panorama_data.src_jpeg_buffer_address[idx] = (U32) param->panoramaShotData->capture_buffer_p[idx];
        panorama_data.src_jpeg_buffer_size[idx] = param->panoramaShotData->capture_img_size[idx];
    }
    
    gdi_layer_push_and_set_active(handleT);

    ret = mdi_camera_start_stitching_panorama_with_quickview(
        &panorama_data, 
        vapp_autocap_panorama_quick_view_hdlr,
        vapp_autocap_panorama_stitch_result_hdlr, 
        (U32)param->quickViewBuffer,
        (U32)buf_size,
        width,
        height,       
        MMI_TRUE,
        (void*)vapp_autocap_hw_object);

    gdi_lcd_lock_mutex();    
    gdi_waiting_blt_finish();    
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
    gdi_layer_clear(GDI_COLOR_BLACK);    
    gdi_lcd_unlock_mutex();        
    mdi_util_hw_layer_switch_to_sw_layer(handleT);
    gdi_layer_pop_and_restore_active();       

#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_STITCH, ret);   

    return ret;

}


MDI_RESULT vapp_autocap_panorama_stop_stitch(void)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
#if defined(__MTK_TARGET__) 
    ret = mdi_camera_stop_stitching_panorama();
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_STOP_STITCH, ret);   

    return ret;
}

MDI_RESULT vapp_autocap_panorama_pause_stitch(void)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
#if defined(__MTK_TARGET__) 
    ret = mdi_camera_pause_stitching_panorama();
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_PAUSE_STITCH, ret);   

    return ret;
}

MDI_RESULT vapp_autocap_panorama_resume_stitch(void)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
#if defined(__MTK_TARGET__) 
    ret = mdi_camera_resume_stitching_panorama();
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_RESUME_STITCH, ret);   

    return ret;
}

MDI_RESULT vapp_autocap_panorama_encode(vapp_autocap_panorama_encode_param_struct *param)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;

#if defined(__MTK_TARGET__) 
    mdi_camera_panorama_stitch_encode_struct encode_info;

    encode_info.quickview_roi_x = param->encodeRoiX;
    encode_info.quickview_roi_y = param->encodeRoiY;
    encode_info.quickview_roi_width = param->encodeRoiW;
    encode_info.quickview_roi_height = param->encodeRoiH;  
    encode_info.is_quickview_centred = MMI_FALSE;

    ret = mdi_camera_encode_panorama_stitch_image(&encode_info);

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_PANORAMA_encode, ret);   

#endif
    
    return ret;

}

MDI_RESULT vapp_autocap_reset_panorama_3a(void)
{
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
#if defined(__MTK_TARGET__) 
    ret = mdi_camera_reset_panorama_3a();
#endif

    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_RESET_PANORAMA_3A, ret);   

    return ret;
}

MDI_RESULT vapp_autocap_save_capture_image(vapp_autocap_capture_save_param_struct *param)
{
#if defined(__MTK_TARGET__) 
    MDI_RESULT ret;

    ret = mdi_camera_save_captured_image();
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SAVE_CAPTURE_IMAGE, ret);   

    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

static void vapp_autocap_mav_capture_result_hdlr(mdi_camera_mav_capture_struct* result_ind, void* user_data)
{
    vapp_autocap_hw_result_callback_param_struct param;

    param.type = VAPP_AUTOCAP_CB_TYPE_MAV_CAPTURED;
    param.mavRet.total_count = result_ind->total_count;
    param.mavRet.captured_count = result_ind->capture_count;

    if(param.mavRet.total_count == param.mavRet.captured_count)
    {
        gdi_handle handleT = vapp_autocap_hw_object->m_previewFrame->getLayerHandle();
        gdi_layer_push_and_set_active(handleT);

        gdi_lcd_lock_mutex();
        gdi_waiting_blt_finish();
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_unlock_mutex();
        mdi_util_hw_layer_switch_to_sw_layer(handleT);
        gdi_layer_pop_and_restore_active();

        vapp_autocap_hw_object->m_hwFlag.isPreviewStart = VFX_FALSE;
    }

    if(vapp_autocap_hw_object)
        vapp_autocap_hw_object->resultHWCallback(param);
}

static void vapp_autocap_mav_save_result_hdlr(mdi_camera_mav_result_struct* result_ind, void* user_data)
{
    vapp_autocap_hw_result_callback_param_struct param;

    param.type = VAPP_AUTOCAP_CB_TYPE_MAV_SAVE_DONE;
    param.mavRet.result = result_ind->result;
    param.mavRet.qv_size = result_ind->buffer_size;
    param.mavRet.qv_buffer = (void*)result_ind->buffer_address;

    if(vapp_autocap_hw_object)
        vapp_autocap_hw_object->resultHWCallback(param);
}

MDI_RESULT vapp_autocap_mav_shot(vapp_autocap_capture_param_struct *param)
{
    param->flag->isPreviewStart = VFX_FALSE;
    param->flag->isAFon = VFX_FALSE;
#if defined(__MTK_TARGET__)
    return mdi_camera_capture_mav_shot(
            (CHAR*)param->fileName,
            vapp_autocap_mav_capture_result_hdlr,
            vapp_autocap_mav_save_result_hdlr,
            (void *)vapp_autocap_hw_object);
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_autocap_mav_save(void)
{
#if defined(__MTK_TARGET__)
    return  mdi_camera_save_captured_image();
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_autocap_mav_stop(void)
{
#if defined(__MTK_TARGET__)
    return mdi_camera_stop_non_blocking_mav_shot();
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif
}

MDI_RESULT vapp_autocap_bk_turn_on(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_BK_TURN_ON, 0);     

    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    return MDI_RES_CAMERA_SUCCEED;    
}

MDI_RESULT vapp_autocap_bk_turn_off(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_BK_TURN_OFF, 0);

    srv_backlight_turn_off();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);    
    return MDI_RES_CAMERA_SUCCEED;    
}

MDI_RESULT vapp_autocap_highlight_turn_on(vapp_autocap_general_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_HIGHLIGHT_TURN_ON, 0);

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

MDI_RESULT vapp_autocap_highlight_turn_off(vapp_autocap_general_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_HIGHLIGHT_TURN_OFF, 0);

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

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
static void vapp_autocap_autofocus_result_hdlr(mdi_camera_af_result_struct result_ind, void* user_data)
{
    vapp_autocap_hw_result_callback_param_struct param;
    
    memcpy(&param.afRet, &result_ind, sizeof(mdi_camera_af_result_struct));
    
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_GET_AUTOFOCUS_RESULT, param.afRet.af_success_zone);

    param.type = VAPP_AUTOCAP_CB_TYPE_CAM_AF;
    if(vapp_autocap_hw_object)    
        vapp_autocap_hw_object->resultHWCallback(param);
}
#endif


MDI_RESULT vapp_autocap_autofocus_start(vapp_autocap_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_AUTOFOCUS_START, param->flag->isAFon);

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    vapp_autocap_hw_object = param->obj;
    
    if(!param->flag->isAFon)
    {
        mdi_camera_start_autofocus_process(vapp_autocap_autofocus_result_hdlr, (void*)vapp_autocap_hw_object);

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


MDI_RESULT vapp_autocap_autofocus_stop(vapp_autocap_autofocus_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_AUTOFOCUS_STOP, param->flag->isAFon);

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
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


MDI_RESULT vapp_autocap_get_autofocus_result(vapp_autocap_autofocus_param_struct *param)
{

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
#if defined(__MTK_TARGET__) 
    mdi_camera_get_focus_zone(&param->af_zone);
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_GET_AUTOFOCUS_RESULT, param->af_zone.af_active_zone);
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


MDI_RESULT vapp_autocap_get_estimated_picture_size(vapp_autocap_estimate_size_param_struct *param)
{
    U16 image_qty;
    U16 image_width; 
    U16 image_height;

    image_qty = param->Setting->getMappingID(VAPP_AUTOCAP_SETTING_CAPQTY);
    
    ((AutoCapCapSizeSetting*)(param->Setting->getSetting(VAPP_AUTOCAP_SETTING_CAPSIZE)))->getMappingSize(
        param->Setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE),
        &image_width, 
        &image_height);

    return mdi_camera_get_predicted_image_size(image_qty, image_width, image_height, &param->size);
}

MDI_RESULT vapp_autocap_background_calculation_start(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_BG_CAL_START);

    mdi_camera_resume_preview_post_process();

    return MDI_RES_CAMERA_SUCCEED;
}

MDI_RESULT vapp_autocap_background_calculation_stop(void)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_BG_CAL_STOP);

    mdi_camera_pause_preview_post_process();

    return MDI_RES_CAMERA_SUCCEED;
}

#endif
