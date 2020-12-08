
#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "vapp_ucm_video_frame.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "mdi_video.h"
#include "mdi_camera.h"
#include "UcmResDef.h" 
#include "mdi_video.h"          /* video lib */
#include "mdi_camera.h"         /* camera lib */
#ifdef __cplusplus
}
#endif

static void VappVtVideoFrameSetCB(VappVtVideoFrame * VideoFrame);
static void VappVtVideoFrameCB(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data);

VappVtVideoFrame* g_vapp_vt_frame_obj;

void VappVtVideoFrame::onInit(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_ONINIT); 

    VfxControl::onInit();

    setBgColor(VFX_COLOR_TRANSPARENT);
    
    m_appId = 0;
    m_sensorId = VAPP_VT_VIDEOFRAME_CAMERA_FRONT;    

    mdi_video_tel_load_default_setting(&m_videoSetting);

    m_videoSetting.display_mirror = MMI_TRUE;        
    
#ifdef __VAPP_VT_VF_DUAL_CAMERA__
    mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */    

    mdi_camera_fun_info ev_cap;
    mdi_camera_zoom_info zoom_info;
    
    // get EV cap
    mdi_video_tel_query_support_info(MDI_CAMERA_SETTING_EV, &ev_cap);
    MMI_ASSERT(ev_cap.is_support);
    m_evCap.count = ev_cap.item_count;
    for(VfxU32 idx = 0; idx < ev_cap.item_count; idx++)
    {
        m_evCap.supportItem[idx] = (VappVtVideoFrameEvEnum)ev_cap.support_item[idx];
    }
    
    // get Zoom cap
    mdi_video_tel_query_zoom_info(&zoom_info);
    m_zoomCap.stepNumber = zoom_info.zoom_steps;

    VFX_OBJ_CREATE(m_peerFrame, VfxVideoFrame, this);
    m_peerFrame->setBgColor(VFX_COLOR_BLACK);
    m_peerFrame->setHidden(VFX_TRUE);
    m_peerFrame->setPos(0, 0);
    m_peerFrame->setAnchor(0.5, 0.5);        
    m_peerFrame->setSize(176, 144);    
    m_peerFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_VIDEOPHONE);
    m_peerFrame->setBorder(VFX_COLOR_WHITE, 0);
    m_peerFrame->m_signalPlayReady.connect(this, &VappVtVideoFrame::videoFramePrepareDone);    

    VFX_OBJ_CREATE(m_peerBgFrame, VfxFrame, this);
    m_peerBgFrame->setBgColor(VFX_COLOR_BLACK);
    m_peerBgFrame->setHidden(VFX_FALSE);
    m_peerBgFrame->setPos(0, 0);
    m_peerBgFrame->setAnchor(0.5, 0.5);        
    m_peerBgFrame->setSize(176, 144);    
    m_peerBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);   

    VFX_OBJ_CREATE(m_peerCoverFrame, VfxImageFrame, this);
    m_peerCoverFrame->setHidden(VFX_FALSE);
    m_peerCoverFrame->setPos(0, 0);
    m_peerCoverFrame->setAnchor(0.5, 0.5);        
    m_peerCoverFrame->setSize(176, 144); 
    m_peerCoverFrame->setBgColor(VFX_COLOR_BLACK);
    m_peerCoverFrame->setOpacity(0.6);
    m_peerCoverFrame->setHidden(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_peerBorderFrame, VfxImageFrame, this);
    m_peerBorderFrame->setHidden(VFX_FALSE);
    m_peerBorderFrame->setPos(0, 0);
    m_peerBorderFrame->setAnchor(0.5, 0.5);        
    m_peerBorderFrame->setSize(176, 144);    
    m_peerBorderFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);       
    m_peerBorderFrame->setResId(VAPP_UCM_VT_VFRAME_DEFAULT_BORDER);

    VFX_OBJ_CREATE(m_localFrame, VfxVideoFrame, this);
    m_localFrame->setBgColor(VFX_COLOR_BLACK);
    m_localFrame->setHidden(VFX_TRUE);
    m_localFrame->setPos(0, 0);
    m_localFrame->setAnchor(0.5, 0.5);    
    m_localFrame->setSize(176, 144);  
    m_localFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_VIDEOPHONE);
    m_localFrame->setBorder(VFX_COLOR_WHITE, 0);
    m_localFrame->m_signalPlayReady.connect(this, &VappVtVideoFrame::videoFramePrepareDone);    

    VFX_OBJ_CREATE(m_localBgFrame, VfxFrame, this);
    m_localBgFrame->setBgColor(VFX_COLOR_BLACK);
    m_localBgFrame->setHidden(VFX_FALSE);
    m_localBgFrame->setPos(0, 0);
    m_localBgFrame->setAnchor(0.5, 0.5);        
    m_localBgFrame->setSize(176, 144);  
    m_localBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);   

    VFX_OBJ_CREATE(m_localCoverFrame, VfxImageFrame, this);
    m_localCoverFrame->setHidden(VFX_FALSE);
    m_localCoverFrame->setPos(0, 0);
    m_localCoverFrame->setAnchor(0.5, 0.5);        
    m_localCoverFrame->setSize(176, 144); 
    m_localCoverFrame->setBgColor(VFX_COLOR_BLACK);
    m_localCoverFrame->setOpacity(0.6);
    m_localCoverFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_localBorderFrame, VfxImageFrame, this);
    m_localBorderFrame->setHidden(VFX_FALSE);
    m_localBorderFrame->setPos(0, 0);
    m_localBorderFrame->setAnchor(0.5, 0.5);        
    m_localBorderFrame->setSize(176, 144);    
    m_localBorderFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);       
    m_localBorderFrame->setResId(VAPP_UCM_VT_VFRAME_DEFAULT_BORDER);

    m_isMEDBuilt = VFX_FALSE;
    m_isMMIOpen = VFX_FALSE;
    
    VappVtVideoFrameSetCB(this);

    m_localFrameType = VAPP_VT_VIDEOFRAME_SRC_IMAGE;    
    m_localPreFrameType = VAPP_VT_VIDEOFRAME_SRC_IMAGE;    
    m_peerFrameType = VAPP_VT_VIDEOFRAME_SRC_IMAGE;    
    m_peerPreFrameType = VAPP_VT_VIDEOFRAME_SRC_IMAGE;    

    m_state = VAPP_VT_VIDEOFRAME_STATE_STOP;

    m_encodeBuffer = NULL;
    m_cachedLocolLayer = 0;
    m_cachedPeerLayer = 0;
    m_encodeLayer = 0;
    m_cacheBuffer = NULL;

    setIsZSortChild(VFX_TRUE);

    g_vapp_vt_frame_obj = this;

}

void VappVtVideoFrame::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_ONDEINIT);

    if(m_encodeLayer)
    {
        gdi_layer_free(m_encodeLayer);
        m_encodeLayer = 0;
    }
    if(m_cachedPeerLayer)
    {
        gdi_layer_free(m_cachedPeerLayer);    
        m_cachedPeerLayer = 0;
    }
    if(m_cachedLocolLayer)
    {
        gdi_layer_free(m_cachedLocolLayer);    
        m_cachedLocolLayer = 0;
    }    
    if(m_encodeBuffer)
    {
        applib_asm_free_r(m_appId, m_encodeBuffer);
    }
    if(m_cacheBuffer)
    {
        applib_asm_free_r(m_appId, m_cacheBuffer);
    }   
    
    if(m_state != VAPP_VT_VIDEOFRAME_STATE_STOP)
    {
        stop();
    }
    
    VappVtVideoFrameSetCB(NULL);    
    VfxControl::onDeinit();    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamMaxWndSize(VfxSize PeerMaxWnd, VfxSize LocalMaxWnd,VfxSize PeerMinWnd, VfxSize LocalMinWnd)
{
    if(mdi_video_tel_set_memory_param(KAL_TRUE, PeerMaxWnd.width, PeerMaxWnd.height, LocalMaxWnd.width, LocalMaxWnd.height))
    {
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    }
    else
    {
        return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;
    }        
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamAppId(VfxU32 id)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_APP_ID, id);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
    
    m_appId = id;

    m_peerFrame->setBuffer(m_appId);
    m_localFrame->setBuffer(m_appId);    

    if(!m_encodeBuffer && !m_encodeLayer)
    {
        m_encodeBuffer = (void*)applib_asm_alloc_nc_r(m_appId, 176*144*2);

        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            176,
            144,
            &m_encodeLayer,
            (U8*)m_encodeBuffer,
            176*144*2);        
    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamSensorId(VappVtVideoFrameSensorEnum sensor)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_SENSOR_ID, sensor);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    m_sensorId = sensor;

#ifdef __VAPP_VT_VF_DUAL_CAMERA__
    if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
        m_videoSetting.display_mirror = MMI_FALSE;             
        m_localFrameType = VAPP_VT_VIDEOFRAME_SRC_VIDEO;        
    }
    else if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
        m_videoSetting.display_mirror = MMI_TRUE;           
        m_localFrameType = VAPP_VT_VIDEOFRAME_SRC_VIDEO;
    }
    else
    {
        m_localFrameType = VAPP_VT_VIDEOFRAME_SRC_IMAGE;    
        
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */

    if(m_localFrameType == VAPP_VT_VIDEOFRAME_SRC_VIDEO)
    {
        mdi_camera_fun_info ev_cap;
        mdi_camera_zoom_info zoom_info;
        VfxU32 real_idx = 0;

        // get EV cap
        mdi_video_tel_query_support_info(MDI_CAMERA_SETTING_EV, &ev_cap);
        MMI_ASSERT(ev_cap.is_support);
        m_evCap.count = ev_cap.item_count;
        for(VfxU32 idx = 0; idx < ev_cap.item_count; idx++)
        {
            if(ev_cap.support_item[idx] < VAPP_VT_VIDEOFRAME_EV_TOTAL)
            {
                m_evCap.supportItem[real_idx] = (VappVtVideoFrameEvEnum)ev_cap.support_item[idx];
                real_idx++;
            }
        }
        m_evCap.count = real_idx;

        // get Zoom cap
        mdi_video_tel_query_zoom_info(&zoom_info);
        m_zoomCap.stepNumber = zoom_info.zoom_steps;
    }    
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;        

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setFrameRect(VappVtVideoFrameTypeEnum type, VfxRect rect)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_FRAME_RECT, type, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);

    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        m_peerFrame->setPos(rect.origin);
        m_peerFrame->setSize(rect.size);
        m_peerBgFrame->setPos(rect.origin);
        m_peerBgFrame->setSize(rect.size);
        m_peerCoverFrame->setPos(rect.origin);
        m_peerCoverFrame->setSize(rect.size);        
        m_peerBorderFrame->setPos(rect.origin);        
        m_peerBorderFrame->setSize(VfxSize(rect.size.width + VAPP_VT_VIDEOFRAME_FRAME_MARGIN*2, rect.size.height + VAPP_VT_VIDEOFRAME_FRAME_MARGIN*2));
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        m_localFrame->setPos(rect.origin);
        m_localFrame->setSize(rect.size);
        m_localBgFrame->setPos(rect.origin);
        m_localBgFrame->setSize(rect.size);
        m_localCoverFrame->setPos(rect.origin);
        m_localCoverFrame->setSize(rect.size);        
        m_localBorderFrame->setPos(rect.origin);        
        m_localBorderFrame->setSize(VfxSize(rect.size.width + VAPP_VT_VIDEOFRAME_FRAME_MARGIN*2, rect.size.height + VAPP_VT_VIDEOFRAME_FRAME_MARGIN*2));
    }
    else
    {
        ASSERT(0);
    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamMirror(VfxBool isMirror)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_MIRROR, isMirror);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    m_videoSetting.display_mirror = isMirror;   
    
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;        
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamHide(VappVtVideoFrameTypeEnum type, VfxBool isHidden)    
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_HIDE, type, isHidden);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        if(m_peerFrameType == VAPP_VT_VIDEOFRAME_SRC_VIDEO)            
            m_peerFrame->setHidden(isHidden);
        else
            m_peerBgFrame->setHidden(isHidden);    
        m_peerBorderFrame->setHidden(isHidden);            
        m_peerFrameHidden = isHidden;
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        if(m_localFrameType == VAPP_VT_VIDEOFRAME_SRC_VIDEO)                
            m_localFrame->setHidden(isHidden);
        else        
            m_localBgFrame->setHidden(isHidden);    
        m_localBorderFrame->setHidden(isHidden);              
        m_localFrameHidden = isHidden;        
    }
    else
    {
        ASSERT(0);
    }      
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;        
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamLocalQty(VappVtVideoFrameEncQualityEnum value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_LOCAL_QTY, value);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    switch (value)
    {
        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_SHARP:
            m_videoSetting.video_qty = MDI_VIDEO_TEL_ENC_QTY_FINE;            
            break;

        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_NORMAL:
            m_videoSetting.video_qty = MDI_VIDEO_TEL_ENC_QTY_NORMAL;
            break;

        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_SMOOTH:
            m_videoSetting.video_qty = MDI_VIDEO_TEL_ENC_QTY_LOW;
            break;

        default:
            /* wrong value */
            MMI_ASSERT(0);
    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamPeerQty(VappVtVideoFrameEncQualityEnum value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_PEER_QTY, value);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    switch (value)
    {
        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_SHARP:
            m_videoSetting.peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_FINE;            
            break;

        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_NORMAL:
            m_videoSetting.peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_NORMAL;
            break;

        case VAPP_VT_VIDEOFRAME_ENC_QUALITY_SMOOTH:
            m_videoSetting.peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_LOW;
            break;

        default:
            /* wrong value */
            MMI_ASSERT(0);
    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamEncSize(VappVtVideoFrameEncSizeEnum value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_ENC_SIZE, value);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    switch (value)
    {
        case VAPP_VT_VIDEOFRAME_ENC_SIZE_QCIF:
            m_videoSetting.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
            break;

        case VAPP_VT_VIDEOFRAME_ENC_SIZE_SQCIF:
            m_videoSetting.video_size = MDI_VIDEO_VIDEO_SIZE_SQCIF;
            break;
            
        default:
            /* wrong value */
            MMI_ASSERT(0);
    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamNightMode(VfxBool isNightMode)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_NIGHT_MODE, isNightMode);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    if(isNightMode)
    {
        m_videoSetting.night = 1;
    }
    else
    {
        m_videoSetting.night = 0;
    }
    
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;        

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamFrameMode(VappVtVideoFrameTypeEnum type, VappVtVideoFrameSrcEnum mode)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_FRAME_MODE, type, mode);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        if(mode == VAPP_VT_VIDEOFRAME_SRC_VIDEO)                   
        {
            if(m_peerFrameHidden)
                m_peerFrame->setHidden(VFX_TRUE);
            else
                m_peerFrame->setHidden(VFX_FALSE);              
            m_peerBgFrame->setHidden(VFX_TRUE);           
        }            
        else if(mode == VAPP_VT_VIDEOFRAME_SRC_IMAGE)                   
        {
            if(m_peerFrameHidden)
                m_peerBgFrame->setHidden(VFX_TRUE);
            else
                m_peerBgFrame->setHidden(VFX_FALSE);                      
            m_peerFrame->setHidden(VFX_TRUE);           
        }                 
        m_peerFrameType = mode;
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        if(mode == VAPP_VT_VIDEOFRAME_SRC_VIDEO)                   
        {
            if(m_localFrameHidden)
                m_localFrame->setHidden(VFX_TRUE);
            else
                m_localFrame->setHidden(VFX_FALSE);                
            m_localBgFrame->setHidden(VFX_TRUE);           
        }            
        else if(mode == VAPP_VT_VIDEOFRAME_SRC_IMAGE)                   
        {
            if(m_localFrameHidden)
                m_localBgFrame->setHidden(VFX_TRUE);
            else
                m_localBgFrame->setHidden(VFX_FALSE);           
            m_localFrame->setHidden(VFX_TRUE);           
        }      
        m_localFrameType = mode;

    }
    else
    {
        ASSERT(0);
    }   
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;           
}   

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamFrameFront(VappVtVideoFrameTypeEnum type)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_FRAME_FRONT, type);

    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
 
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        m_peerFrame->bringToFront();
        m_peerBgFrame->bringToFront();   
        m_peerCoverFrame->bringToFront();           
        m_peerBorderFrame->bringToFront();   
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        m_localFrame->bringToFront();
        m_localBgFrame->bringToFront();        
        m_localCoverFrame->bringToFront();            
        m_localBorderFrame->bringToFront();           
    }
    else
    {
        ASSERT(0);
    }     
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamFrameBorder(VappVtVideoFrameTypeEnum type, VfxImageFrame* f)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_FRAME_BORDER, type);

    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER )
    {        
        m_peerBorderFrame = f;             
        m_peerBorderFrame->setPosZ(m_peerFrame->getPosZ() + 1);
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
        
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        m_localBorderFrame = f;            
        m_localBorderFrame->setPosZ(m_localFrame->getPosZ() + 1);
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    }

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamFrameContent(VappVtVideoFrameTypeEnum type, const VfxImageSrc &value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_PARA_FRAME_CONTENT, type, value.getType());

    VfxS32 image_width;
    VfxS32 image_height;
    VfxS32 resized_width;
    VfxS32 resized_height;
    VfxS32 resized_offset_x;
    VfxS32 resized_offset_y;
    GDI_RESULT ret;
    
    ASSERT(m_state != VAPP_VT_VIDEOFRAME_STATE_START);
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER )
    {        
        m_peerBgFrame->setImgContent(value);             
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
        
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
    
        m_localBgFrame->setImgContent(value);
        m_localBgFrame->setBgColor(VRT_COLOR_SILVER);
        
        gdi_layer_push_and_set_active(m_encodeLayer);                   
        if(value.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
        {
            gdi_image_get_dimension_id(value.getResId(), &image_width, &image_height);

            if(image_width < 176 && image_height < 144)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    176,
                    144,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);            
            }                    
            else
            {         
                gdi_image_util_fit_bbox(
                    176,
                    144,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            }
            
            gdi_layer_clear((gdi_act_color_from_rgb(255, 189, 189, 189)));     
            
            /* to prevent image to blending with wrong layer */
            gdi_push_and_set_alpha_blending_source_layer(m_encodeLayer);

            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                value.getResId());                

            gdi_pop_and_restore_alpha_blending_source_layer();                 
            
        }
        else if(value.getType() == VFX_IMAGE_SRC_TYPE_PATH)
        {
            ret = gdi_image_get_dimension_file((CHAR*)value.getPath().getBuf(), &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {
                if(image_width < 176 && image_height < 144)
                {
                    gdi_util_fit_box(
                        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                        176,
                        144,
                        image_width,
                        image_height,
                        &resized_offset_x,
                        &resized_offset_y,
                        &resized_width,
                        &resized_height);            
                }                    
                else
                {         
                    gdi_image_util_fit_bbox(
                        176,
                        144,
                        image_width,
                        image_height,
                        &resized_offset_x,
                        &resized_offset_y,
                        &resized_width,
                        &resized_height);
                }
                gdi_layer_clear((gdi_act_color_from_rgb(255, 189, 189, 189)));     

                /* to prevent image to blending with wrong layer */
                gdi_push_and_set_alpha_blending_source_layer(m_encodeLayer);
    				
                ret= gdi_image_draw_resized_file(
                        resized_offset_x, 
                        resized_offset_y, 
                        resized_width, 
                        resized_height,
                        (CHAR*)value.getPath().getBuf());         
                        
                gdi_pop_and_restore_alpha_blending_source_layer();       
                
                if(ret != GDI_SUCCEED)
                {
                    gdi_layer_pop_and_restore_active();                      
                    return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;
                }
            }
            else
            {
                gdi_layer_pop_and_restore_active();                         
                return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;                
            }                
        }
        else
        {
            ASSERT(0);
        }            
        gdi_layer_pop_and_restore_active();                   
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
     
    }
    else
    {
        ASSERT(0);
    }     
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setParamPeerDefaultContent(const VfxImageSrc &value)
{
    VfxS32 image_width;
    VfxS32 image_height;
    VfxS32 resized_width;
    VfxS32 resized_height;
    VfxS32 resized_offset_x;
    VfxS32 resized_offset_y;
    VfxS32 width, height;
    GDI_RESULT ret;
            
    gdi_handle handleT = m_peerFrame->getLayerHandle();    
    
    gdi_layer_push_and_set_active(handleT);   
    gdi_layer_get_dimension(&width, &height);
    
    if(value.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        gdi_image_get_dimension_id(value.getResId(), &image_width, &image_height);

        if(image_width < width && image_height < height)
        {
            gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                width,
                height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);            
        }                    
        else
        {         
            gdi_image_util_fit_bbox(
                width,
                height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
        }
                
        gdi_image_draw_resized_id(
            resized_offset_x, 
            resized_offset_y, 
            resized_width, 
            resized_height,
            value.getResId());                                    
    }
    else if(value.getType() == VFX_IMAGE_SRC_TYPE_PATH)
    {
        ret = gdi_image_get_dimension_file((CHAR*)value.getPath().getBuf(), &image_width, &image_height);

        if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
        {
            if(image_width < width  && image_height < height)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    width,
                    height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);            
            }                    
            else
            {         
                gdi_image_util_fit_bbox(
                    width ,
                    height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            }
				
            ret= gdi_image_draw_resized_file(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    (CHAR*)value.getPath().getBuf());         
            
            if(ret != GDI_SUCCEED)
            {
                gdi_layer_pop_and_restore_active();                      
                return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;
            }
        }
        else
        {
            gdi_layer_pop_and_restore_active();                         
            return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;                
        }                
    }
    else
    {
        ASSERT(0);
    }       
    
    gdi_layer_pop_and_restore_active();                   
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
 
}

void VappVtVideoFrame::videoFramePrepareDone(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_VIDEO_FRAME_PREPARE_DONE, m_prepareCount, m_prepareExpectCount, m_prepareMode, m_isMMIOpen);

    m_prepareCount++;

    if(m_prepareCount == m_prepareExpectCount)
    {
        if(m_prepareMode == 0)
        {
            VfxS32 ret;
            gdi_handle peer_layer_handle = m_peerFrame->getLayerHandle();
            gdi_handle local_layer_handle = m_localFrame->getLayerHandle();
            mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;    
            U32 blt_layer_flag = m_peerFrame->getDisplayLayerFlag() | m_localFrame->getDisplayLayerFlag();
            U32 peer_layer_flag = m_peerFrame->getDisplayLayerFlag();
            U32 local_layer_flag = m_localFrame->getDisplayLayerFlag();       

            if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_BACK)
            {
                mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
                m_videoSetting.display_mirror = MMI_FALSE;             
            }
            else if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_FRONT)
            {
                mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
                m_videoSetting.display_mirror = MMI_TRUE;           
            }       
            
            switch (m_localFrameType)
            {
                case VAPP_VT_VIDEOFRAME_SRC_VIDEO: 
                    local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
                    break;
                case VAPP_VT_VIDEOFRAME_SRC_IMAGE: 
                    local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
                    break;                              
            }   

            switch (m_peerFrameType)
            {
                case VAPP_VT_VIDEOFRAME_SRC_VIDEO: 
                    peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
                    break;
                case VAPP_VT_VIDEOFRAME_SRC_IMAGE: 
                    peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
                    break;                              
            }   
            
            if(m_localFrameType == VAPP_VT_VIDEOFRAME_SRC_IMAGE)
            {
                local_layer_handle = m_encodeLayer;
            }
            
            ret = mdi_video_tel_start(
                        peer_layer_handle,         
                        local_layer_handle,        
                        peer_type,                 
                        local_type,  
                        blt_layer_flag,
                        peer_layer_flag,
                        local_layer_flag,
                        &m_videoSetting,
                        m_appId,
                        VappVtVideoFrameCB,
                        NULL);  
            m_isMMIOpen = VFX_TRUE;
            
            m_state = VAPP_VT_VIDEOFRAME_STATE_START;   
            
            if(ret != MDI_RES_VDOTEL_SUCCEED)
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_START, 0);            
            else
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_START, 1);            
            
        }
        else if(m_prepareMode == 1)
        {
            VfxS32 ret;
            gdi_handle peer_layer_handle = m_peerFrame->getLayerHandle();
            gdi_handle local_layer_handle = m_localFrame->getLayerHandle();
            mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;    
            U32 blt_layer_flag = m_peerFrame->getDisplayLayerFlag() | m_localFrame->getDisplayLayerFlag();
            U32 peer_layer_flag = m_peerFrame->getDisplayLayerFlag();
            U32 local_layer_flag = m_localFrame->getDisplayLayerFlag();        

            if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_BACK)
            {
                mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
                m_videoSetting.display_mirror = MMI_FALSE;             
            }
            else if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_FRONT)
            {
                mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
                m_videoSetting.display_mirror = MMI_TRUE;           
            }           
            
            switch (m_localFrameType)
            {
                case VAPP_VT_VIDEOFRAME_SRC_VIDEO: 
                    local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
                    break;
                case VAPP_VT_VIDEOFRAME_SRC_IMAGE: 
                    local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
                    break;                              
            }   

            switch (m_peerFrameType)
            {
                case VAPP_VT_VIDEOFRAME_SRC_VIDEO: 
                    peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
                    break;
                case VAPP_VT_VIDEOFRAME_SRC_IMAGE: 
                    peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
                    break;                              
            }        
            
            if(m_localFrameType == VAPP_VT_VIDEOFRAME_SRC_IMAGE)
            {
                local_layer_handle = m_encodeLayer;
            }        
            
            if(m_isMMIOpen)   
            {                 
                ret = mdi_video_tel_resume(
                            peer_layer_handle,         
                            local_layer_handle,        
                            peer_type,                 
                            local_type,  
                            blt_layer_flag,
                            peer_layer_flag,
                            local_layer_flag,
                            &m_videoSetting,
                            VappVtVideoFrameCB,
                            NULL);  
            }                        
            else
            {
                ret = mdi_video_tel_start(
                            peer_layer_handle,         
                            local_layer_handle,        
                            peer_type,                 
                            local_type,  
                            blt_layer_flag,
                            peer_layer_flag,
                            local_layer_flag,
                            &m_videoSetting,
                            m_appId,
                            VappVtVideoFrameCB,              
                            NULL);  
                            
                m_isMMIOpen = VFX_TRUE;
            }            
                                    
            m_state = VAPP_VT_VIDEOFRAME_STATE_START;         

            if(ret != MDI_RES_VDOTEL_SUCCEED)
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_RESUME, 0);            
            else
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_RESUME, 1);              
        }
    }

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::start(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_START, m_peerFrameType, m_localFrameType);

    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_STOP);
    ASSERT(m_localFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_OFF);
    m_peerPreFrameType = m_peerFrameType;
    m_localPreFrameType = m_localFrameType;        
    
    if(m_peerFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {

        m_prepareCount = 0;
        m_prepareMode = 0;
        m_prepareExpectCount = 2;
        
        m_peerFrame->prepare();
        m_localFrame->prepare();

        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;

    }
    else
    {
        m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_START, 1);  
        m_state = VAPP_VT_VIDEOFRAME_STATE_START; 
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    }


};

VappVtVideoFrameErrorEnum VappVtVideoFrame::resume(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_RESUME, m_peerFrameType, m_localFrameType);

    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_PAUSE);

    m_peerPreFrameType = m_peerFrameType;
    m_localPreFrameType = m_localFrameType;    
    
    if(m_peerFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {

        m_prepareCount = 0;
        m_prepareMode = 1;
        m_prepareExpectCount = 2;
        
        m_peerFrame->prepare();
        m_localFrame->prepare();

        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;                  
    }
    else
    {    
        mdi_video_tel_stop();
		        
        m_isMMIOpen = VFX_FALSE;   
        
        m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_RESUME, 1);  
        m_state = VAPP_VT_VIDEOFRAME_STATE_START; 
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    }

};
VappVtVideoFrameErrorEnum VappVtVideoFrame::pause(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_PAUSE, m_peerFrameType, m_localFrameType, m_prepareCount, m_prepareExpectCount);

    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_START);

    ASSERT(m_peerPreFrameType == m_peerFrameType);
    ASSERT(m_localPreFrameType == m_localFrameType);           
    
    if(m_peerPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {
        // prepare done
        if(m_prepareCount == m_prepareExpectCount)
        {
            mdi_video_tel_pause();

            // keep video frame content, if need capture
            gdi_handle g = m_peerFrame->getLayerHandle();
            S32 width, height, buf_size;
            U8* dst_p;
          
            gdi_layer_push_and_set_active(g);
            gdi_layer_get_dimension(&width, &height);
            buf_size = (width * height * gdi_layer_get_bit_per_pixel()) >> 3;
            gdi_layer_get_buffer_ptr(&dst_p);        
            gdi_layer_pop_and_restore_active();

            if(m_cachedPeerLayer)
                gdi_layer_free(m_cachedPeerLayer);
            
            if(m_cacheBuffer)
                applib_asm_free_r(m_appId, m_cacheBuffer);   
            
            m_cacheBuffer = (void*)applib_asm_alloc_nc_r(m_appId, buf_size);
            m_cacheBufferSize = buf_size;
            
            gdi_layer_create_cf_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                0,
                0,
                width,
                height,
                &m_cachedPeerLayer,
                (U8*)m_cacheBuffer,
                buf_size);                             
            
            memcpy(m_cacheBuffer, dst_p, buf_size);

        }        
        
        m_peerFrame->unPrepare();
        m_localFrame->unPrepare();            
    }
    m_state = VAPP_VT_VIDEOFRAME_STATE_PAUSE;     
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
};

VappVtVideoFrameErrorEnum VappVtVideoFrame::stop(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_STOP, m_peerFrameType, m_localFrameType, m_prepareCount, m_prepareExpectCount, m_isMMIOpen);

    ASSERT(m_peerPreFrameType == m_peerFrameType);
    ASSERT(m_localPreFrameType == m_localFrameType);           
    
    if(m_peerPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {
        // prepare done
        if(m_prepareCount == m_prepareExpectCount || m_isMMIOpen)
        {
            mdi_video_tel_stop();
        }
        
        m_isMMIOpen = VFX_FALSE;        
        
        m_peerFrame->unPrepare();
        m_localFrame->unPrepare();              
    }
    m_state = VAPP_VT_VIDEOFRAME_STATE_STOP;         
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;

};

VappVtVideoFrameErrorEnum VappVtVideoFrame::abortStart(void)
{
    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_STOP);
    ASSERT(m_prepareMode == 0);
    
    m_prepareMode = 2;
    m_peerFrame->unPrepare();
    m_localFrame->unPrepare();

    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;

}

VappVtVideoFrameErrorEnum VappVtVideoFrame::abortResume(void)
{
    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_PAUSE);
    ASSERT(m_prepareMode == 1);
    
    m_prepareMode = 2;
    m_peerFrame->unPrepare();
    m_localFrame->unPrepare();

    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;

}


VappVtVideoFrameErrorEnum VappVtVideoFrame::backgroundPause(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_BG_PAUSE, m_peerFrameType, m_localFrameType);

    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_START);

    ASSERT(m_peerPreFrameType == m_peerFrameType);
    ASSERT(m_localPreFrameType == m_localFrameType);           
    
    if(m_peerPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localPreFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {
        mdi_video_tel_pause();
    }
    m_state = VAPP_VT_VIDEOFRAME_STATE_PAUSE;     
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
};


VappVtVideoFrameErrorEnum VappVtVideoFrame::backgroundResume(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_BG_RESUME, m_peerFrameType, m_localFrameType, m_isMMIOpen);

    ASSERT(m_state == VAPP_VT_VIDEOFRAME_STATE_PAUSE);

    m_peerPreFrameType = m_peerFrameType;
    m_localPreFrameType = m_localFrameType;    
    
    if(m_peerFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE || m_localFrameType != VAPP_VT_VIDEOFRAME_SRC_IMAGE)
    {

        //m_peerFrame->prepare();
        //m_localFrame->prepare();
        VfxS32 ret;
        gdi_handle peer_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        gdi_handle local_layer_handle = m_encodeLayer;
        mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
        mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;    
        U32 blt_layer_flag = 0;
        U32 peer_layer_flag = 0;
        U32 local_layer_flag = 0;        

        if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_BACK)
        {
            mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
            m_videoSetting.display_mirror = MMI_FALSE;             
        }
        else if (m_sensorId == VAPP_VT_VIDEOFRAME_CAMERA_FRONT)
        {
            mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
            m_videoSetting.display_mirror = MMI_TRUE;           
        }           
        
        switch (m_localFrameType)
        {
            case VAPP_VT_VIDEOFRAME_SRC_VIDEO: 
                local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
                break;
            case VAPP_VT_VIDEOFRAME_SRC_IMAGE: 
                local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
                break;                              
        }    
        
        if(m_isMMIOpen)   
        {                 
            ret = mdi_video_tel_resume(
                        peer_layer_handle,         
                        local_layer_handle,        
                        peer_type,                 
                        local_type,  
                        blt_layer_flag,
                        peer_layer_flag,
                        local_layer_flag,
                        &m_videoSetting,
                        VappVtVideoFrameCB,
                        NULL);  
        }                        
        else
        {
            ret = mdi_video_tel_start(
                        peer_layer_handle,         
                        local_layer_handle,        
                        peer_type,                 
                        local_type,  
                        blt_layer_flag,
                        peer_layer_flag,
                        local_layer_flag,
                        &m_videoSetting,
                        m_appId,
                        VappVtVideoFrameCB,              
                        NULL);  
                        
            m_isMMIOpen = VFX_TRUE;
        }            
        
                    
        m_state = VAPP_VT_VIDEOFRAME_STATE_START; 
        m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_RESUME, 1); 
        if(ret != MDI_RES_VDOTEL_SUCCEED)
            return VAPP_VT_VIDEOFRAME_ERROR_DRIVER_ERROR;
        else
            return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
                  
        m_state = VAPP_VT_VIDEOFRAME_STATE_START;     
        
    }
    else
    {    
        mdi_video_tel_stop();
		        
        m_isMMIOpen = VFX_FALSE;   
        m_state = VAPP_VT_VIDEOFRAME_STATE_START; 
        m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_RESUME, 1); 
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    }

};

VappVtVideoFrameErrorEnum VappVtVideoFrame::capture(VappVtVideoFrameTypeEnum type, CHAR* fileName)
{

    MDI_RESULT snap_ret = MDI_RES_VDOPLY_ERR_FAILED;

    /* snapshot - save to file */
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
	{
		mdi_video_tel_get_peer_content((kal_uint8*)m_cacheBuffer, m_cacheBufferSize);
        snap_ret = mdi_video_ply_snapshot(m_cachedPeerLayer, fileName);
	}

    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_CAPTURE, type, snap_ret);
    
    if(snap_ret == MDI_RES_VDOPLY_SUCCEED)
        return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
    else if (snap_ret == MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL)
        return VAPP_VT_VIDEOFRAME_ERROR_CAPTURE_DISK_FULL;        
    else
        return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;

};

VappVtVideoFrameErrorEnum VappVtVideoFrame::setZoomValue(VfxU16 value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_ZOOM, value, m_isMEDBuilt);

    if(!m_isMEDBuilt)
        return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;

    m_videoSetting.zoom = value;

    mdi_video_tel_update_para_zoom(value); 
    
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;    
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::setEVValue(VappVtVideoFrameEvEnum value)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SET_EV, value, m_isMEDBuilt);

    if(!m_isMEDBuilt)
        return VAPP_VT_VIDEOFRAME_ERROR_INVALIDE_INPUT;

    m_videoSetting.ev = value;

    switch(value)
    {
        case VAPP_VT_VIDEOFRAME_EV_N4:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_N4);
            break;
        case VAPP_VT_VIDEOFRAME_EV_N3:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_N3);
            break;
        case VAPP_VT_VIDEOFRAME_EV_N2:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_N2);
            break;
        case VAPP_VT_VIDEOFRAME_EV_N1:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_N1);
            break;  
        case VAPP_VT_VIDEOFRAME_EV_0:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_0);
            break;    
        case VAPP_VT_VIDEOFRAME_EV_P1:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_P1);
            break;    
        case VAPP_VT_VIDEOFRAME_EV_P2:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_P2);
            break;    
        case VAPP_VT_VIDEOFRAME_EV_P3:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_P3);
            break;                
        case VAPP_VT_VIDEOFRAME_EV_P4:
            mdi_video_tel_update_para_ev(MDI_VIDEO_EV_P4);
            break; 
        default:
            /* wrong value */
            MMI_ASSERT(0);

    }
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
}
    

VappVtVideoFrameErrorEnum VappVtVideoFrame::getZoomCap(VappVtVideoFrameZoomCapStruct *cap)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_GET_ZOOM_CAP);

    memcpy(cap, &m_zoomCap, sizeof(VappVtVideoFrameZoomCapStruct));
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::getEVCap(VappVtVideoFrameEvCapStruct *cap)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_GET_EV_CAP);

    memcpy(cap, &m_evCap, sizeof(VappVtVideoFrameEvCapStruct));
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;
}

VappVtVideoFrameErrorEnum VappVtVideoFrame::getFrameData(VappVtVideoFrameTypeEnum type, VfxImageFrame* imageDst)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_GET_FRAME_DATA, type);

    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        imageDst->setImgContent(m_peerBgFrame->getImgContent());        
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        imageDst->setImgContent(m_localBgFrame->getImgContent());    
    }
    else
    {
        ASSERT(0);
    }  
    return VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR;

}    

gdi_handle VappVtVideoFrame::getFrameHandle(VappVtVideoFrameTypeEnum type)
{
    if(type == VAPP_VT_VIDEOFRAME_TYPE_PEER)
    {
        if(m_peerFrameType == VAPP_VT_VIDEOFRAME_SRC_VIDEO)
            return m_peerFrame->getLayerHandle();
        else
            return 0;
    }
    else if(type == VAPP_VT_VIDEOFRAME_TYPE_LOCAL)
    {
        if(m_localFrameType == VAPP_VT_VIDEOFRAME_SRC_VIDEO)
            return m_localFrame->getLayerHandle();
        else
            return 0;
    }
    else
    {
        ASSERT(0);
    }  
}


VfxU32 VappVtVideoFrame::getFrameMargin(void)
{
    return VAPP_VT_VIDEOFRAME_FRAME_MARGIN;
}

VfxU32 VappVtVideoFrame::getFrameBorder(void)
{
    return VAPP_UCM_VT_VFRAME_DEFAULT_BORDER;
}

void VappVtVideoFrame::showCover(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_SHOW_COVER);

    if(!m_localFrame->getHidden() || !m_localBgFrame->getHidden())
        m_localCoverFrame->setHidden(VFX_FALSE);
    if(!m_peerFrame->getHidden() || !m_peerBgFrame->getHidden())    
        m_peerCoverFrame->setHidden(VFX_FALSE);
}

void VappVtVideoFrame::hideCover(void)
{
    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_HIDE_COVER);

    m_localCoverFrame->setHidden(VFX_TRUE);
    m_peerCoverFrame->setHidden(VFX_TRUE);
}

VfxBool VappVtVideoFrame::hitTest(VfxPoint pos, VfxRect rect)
{
    if(rect.contains(pos))
        return VFX_TRUE;
    else
        return VFX_FALSE;
}


VfxBool VappVtVideoFrame::onPenInput(VfxPenEvent &event)    
{
    VfxPoint pos(event.getRelPos(this));
	
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_peerFrame->getPosZ() > m_localFrame->getPosZ() )
        {
            if (hitTest(pos, m_peerFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_DOWN, VAPP_VT_VIDEOFRAME_TYPE_PEER);
            }
            else if (hitTest(pos, m_localFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_DOWN, VAPP_VT_VIDEOFRAME_TYPE_LOCAL);
            }
        }
        else if(m_localFrame->getPosZ() > m_peerFrame->getPosZ() )
        {
            if (hitTest(pos, m_localFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_DOWN, VAPP_VT_VIDEOFRAME_TYPE_LOCAL);
            }
            else if (hitTest(pos, m_peerFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_DOWN, VAPP_VT_VIDEOFRAME_TYPE_PEER);
            }
        }
        			
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_peerFrame->getPosZ() > m_localFrame->getPosZ() )
        {
            if (hitTest(pos, m_peerFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_UP, VAPP_VT_VIDEOFRAME_TYPE_PEER);
            }
            else if (hitTest(pos, m_localFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_UP, VAPP_VT_VIDEOFRAME_TYPE_LOCAL);
            }            
        }
        else if(m_localFrame->getPosZ() > m_peerFrame->getPosZ() )
        {
            if (hitTest(pos, m_localFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_UP, VAPP_VT_VIDEOFRAME_TYPE_LOCAL);
            }
            else if (hitTest(pos, m_peerFrame->getRect()))
            {
                m_signalVtVideoFramePenEvent.postEmit(VFX_PEN_EVENT_TYPE_UP, VAPP_VT_VIDEOFRAME_TYPE_PEER);
            }            
        }

    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }

    return VFX_TRUE;;

}


void VappVtVideoFrame::eventCallbackHdlr(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data)
{

    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_VT_EVENT_CALLBACK, tel_event, para, user_data);
    	
    switch(tel_event)
    {
        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE:

            if (para == MDI_VIDEO_VIDEO_SIZE_QCIF)
            {
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_SIZE, VAPP_VT_VIDEOFRAME_ENC_SIZE_QCIF);
            }
            else if (para == MDI_VIDEO_VIDEO_SIZE_SQCIF)
            {
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_SIZE, VAPP_VT_VIDEOFRAME_ENC_SIZE_SQCIF);

            }
            else
            {
                ASSERT(0);
            }

            break;

        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY:

            if(m_videoSetting.night == 1)
            {
                break;            
            }
            if (para == MDI_VIDEO_TEL_ENC_QTY_FINE)
            {
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_QUALITY, VAPP_VT_VIDEOFRAME_ENC_QUALITY_SHARP);
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_NORMAL)
            {
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_QUALITY, VAPP_VT_VIDEOFRAME_ENC_QUALITY_NORMAL);
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_LOW)
            {
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_CHANGE_ENCODE_QUALITY, VAPP_VT_VIDEOFRAME_ENC_QUALITY_SMOOTH);        
            }                       
            else
            {
                ASSERT(0);
            }

            break;
            
        case MDI_VIDEO_TEL_EVENT_UPDATE_LCD:        	
            break;        	
            
        case MDI_VIDEO_TEL_EVENT_ENC_PATH_BUILT:            
            if(!para)
            {
                m_isMEDBuilt = VFX_TRUE;
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_ENC_PATH_BUILT, 1);                        
            }
            else
            {
                m_isMEDBuilt = VFX_FALSE;
                m_signalVtEvent.postEmit(VAPP_VT_VIDEOFRAME_EVENT_ENC_PATH_BUILT, 0);                                        
            }
            break;        	            
        default:
            ASSERT(0);
    
    }
    
}


VappVtVideoFrame * CurrentVideoFrame;
static void VappVtVideoFrameSetCB(VappVtVideoFrame * VideoFrame)
{
    CurrentVideoFrame = VideoFrame;
}

static void VappVtVideoFrameCB(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data)
{
    if(CurrentVideoFrame != NULL)
        CurrentVideoFrame->eventCallbackHdlr(tel_event, para, user_data);
}


#endif
