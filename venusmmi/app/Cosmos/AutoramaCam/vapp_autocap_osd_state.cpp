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
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "mdi_video.h"

// for block vol dialog appear on popup screen
#include "vapp_vol_dialog_gprot.h"

#ifdef __cplusplus
}
#endif

#include "vapp_autocap_osd_state.h"
#include "MMI_include.h"
#include "MMI_features.h"
#include "MMI_features_camcorder.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
extern vapp_autocap_osd_skin g_vapp_autocap_skin;

void AutoCapOSDState::onInit(void)
{
    VfxControl::onInit();
    setPos(0, 0);
    setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
    setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    setBgColor(VRT_COLOR_TRANSPARENT);    
};

void AutoCapOSDState::updateScreen(void)
{
    invalidate();
}

void AutoCapOSDState::clean(const VfxColor &value)
{
    setBgColor(value);
    invalidate();
}

void AutoCapOSDState::drawBase(vapp_autocap_osd_draw_image_struct param)
{
    setBgColor(VFX_COLOR_TRANSPARENT);
    invalidate();

}

void AutoCapOSDState::enterState(void* param)
{
    enableState(); 
    setFocused(VFX_TRUE);    
    m_autoExitTimer->m_signalTick.connect(this, &AutoCapOSDState::onAutoExitTimerTick);    
    m_autoExitTimer->start();       

    vapp_volume_dialog_block(MMI_TRUE);
};

void AutoCapOSDState::exitState(void)
{
    disableState();
    setFocused(VFX_FALSE);        
    m_autoExitTimer->stop();    
    m_autoExitTimer->m_signalTick.disconnect(this, &AutoCapOSDState::onAutoExitTimerTick);    

    vapp_volume_dialog_block(MMI_FALSE);
};  


VfxPoint AutoCapOSDState::coordTransform2Vertical(VfxU32 x, VfxU32 y)
{
    return VfxPoint(GDI_LCD_WIDTH - y, x);
}

void AutoCapOSDState::setAutoExitTimer(VfxTimer* t)
{
    m_autoExitTimer = t;
    m_autoExitTimer->setStartDelay(VAPP_AUTOCAP_OSD_AUTO_EXIT_TIME);
}

void AutoCapOSDState::refreshAutoExitTimer(void)
{
    m_autoExitTimer->start();
}

void AutoCapOSDState::onAutoExitTimerTick(VfxTimer *source)
{
    AutoExitTimoutProcess();
}

void AutoCapOSDState::AutoExitTimoutProcess(void)
{
    evtHdlr->appGlobalEventHdlr(VAPP_AUTOCAP_EVT_AUTO_EXIT, NULL);        
}

VfxBool AutoCapOSDState::onPenInput(VfxPenEvent & event)
{
    m_autoExitTimer->start();
        
    return VfxControl::onPenInput(event);
}

VfxBool AutoCapOSDState::onKeyInput(VfxKeyEvent & event)
{
    m_autoExitTimer->start();
    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_VOL_UP:    
        case VFX_KEY_CODE_VOL_DOWN:                
            return VFX_TRUE;
    }        
    return VfxControl::onKeyInput(event);
}

void AutoCapOSDStartingState::onInit(void)
{
    AutoCapOSDState::onInit();
    m_state = VAPP_AUTOCAP_OSD_STATE_HIDE;    
};

void AutoCapOSDStartingState::enterState(void* param)
{
    VfxU8 isVerticalMode = (*((VfxU8*)param));

    enableState();
    setFocused(VFX_TRUE);   

    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_viewSwitcher, VcpImageButton, this);
    VFX_OBJ_CREATE(m_storageSetting, VcpImageButton, this);       
    VFX_OBJ_CREATE(m_rightBar, VfxImageFrame, this);   
    VFX_OBJ_CREATE(m_gallery, VcpImageButton, this);     
    VFX_OBJ_CREATE(m_galleryContent, VfxFrame, this);            
    VFX_OBJ_CREATE(m_usedSensor, VcpImageButton, this); 

    m_rightBar->setAnchor(0.5, 0.5);      
    m_rightBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));    
    m_rightBar->setIsUnhittable(VFX_TRUE);
    
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON);
    m_gallery->setAnchor(0.5, 0.5);
    m_gallery->setImage(SI);
    m_gallery->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_gallery->setAutoAnimate(VFX_FALSE);
    m_gallery->setIsEffect(VFX_TRUE);
    m_gallery->setEffectSize(VfxSize(52, 52));        
    m_galleryContent->setIsUnhittable(VFX_TRUE);
    m_galleryContent->setBorderColor(VFX_COLOR_BLACK);
    m_galleryContent->setBgColor(VFX_COLOR_BLACK);    
    m_galleryContent->setBorderWidth(2);
    m_galleryContent->setAnchor(0.5, 0.5);
    m_galleryContent->setSize(m_gallery->getSize());
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON);   
    m_usedSensor->setAnchor(0.5, 0.5);
    m_usedSensor->setImage(SI);
    m_usedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_usedSensor->setAutoAnimate(VFX_FALSE);
    m_usedSensor->setIsEffect(VFX_TRUE);
    m_usedSensor->setEffectSize(VfxSize(110, 110));

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON);
    m_viewSwitcher->setAnchor(0.5, 0.5);
    m_viewSwitcher->setImage(SI);
    m_viewSwitcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_viewSwitcher->setAutoAnimate(VFX_FALSE);
    m_viewSwitcher->setIsEffect(VFX_TRUE);
    m_viewSwitcher->setEffectSize(VfxSize(52, 52));
    if(isVerticalMode & 0x2)
    {
    #if defined(MOTION_SENSOR_SUPPORT)
        m_viewSwitcher->setHidden(VFX_FALSE);
    #else
        m_viewSwitcher->setHidden(VFX_TRUE);
    #endif
    }
    else
    {
        m_viewSwitcher->setHidden(VFX_TRUE);
    }

    SI = VcpStateImage(
            IMG_ID_VAPP_AUTOCAP_WHEEL_AD_STORAGE_ICON,
            IMG_ID_VAPP_AUTOCAP_WHEEL_AD_STORAGE_ICON,
            IMG_ID_VAPP_AUTOCAP_WHEEL_AD_STORAGE_ICON,
            IMG_ID_VAPP_AUTOCAP_WHEEL_AD_STORAGE_ICON);       
    m_storageSetting->setAutoAnimate(VFX_FALSE);
    m_storageSetting->setIsEffect(VFX_TRUE);
    m_storageSetting->setEffectSize(VfxSize(52, 52));     
    m_storageSetting->setAnchor(0.5, 0.5);
    m_storageSetting->setImage(SI);
    m_storageSetting->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
#if defined(__LOW_COST_SUPPORT_COMMON__)
    m_storageSetting->setHidden(VFX_TRUE);
#else
    m_storageSetting->setHidden(VFX_FALSE);
#endif

    // layout        
    vapp_autocap_osd_skin *sp = &g_vapp_autocap_skin;

    if(!(isVerticalMode & 0x1))
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
        setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));
        m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
        m_rightBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);

        m_storageSetting->setPos(m_rightBar->getPos().x, GDI_LCD_WIDTH - sp->galleryPos[1]);

        m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);
        m_galleryContent->setPos(sp->galleryPos[0], sp->galleryPos[1]);
        m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);

        m_viewSwitcher->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
        setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_V_RIGHT_BAR_ICON));
        m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1));
        m_rightBar->setSize(sp->SideBarSize[1],sp->SideBarSize[0]);

        m_storageSetting->setPos(sp->galleryPos[1], m_rightBar->getPos().y);

        m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
        m_galleryContent->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
        m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));

        m_viewSwitcher->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));
    }
};

void AutoCapOSDStartingState::exitState(void)
{
    VFX_OBJ_CLOSE(m_rightBar);
    VFX_OBJ_CLOSE(m_storageSetting);
    VFX_OBJ_CLOSE(m_rightBar);
    VFX_OBJ_CLOSE(m_gallery);
    VFX_OBJ_CLOSE(m_galleryContent);
    VFX_OBJ_CLOSE(m_usedSensor);

    disableState();
    setFocused(VFX_FALSE);      
}

VfxBool AutoCapOSDStartingState::onPenInput(VfxPenEvent & event)
{
    return VFX_TRUE;
}

VfxBool AutoCapOSDStartingState::onKeyInput(VfxKeyEvent &event)
{
    return VFX_TRUE;
}

void AutoCapOSDHideState::onInit(void)
{
    AutoCapOSDState::onInit();
    m_state = VAPP_AUTOCAP_OSD_STATE_HIDE;    
};

void AutoCapOSDHideState::enterState(void* param)
{
    ASSERT(param != NULL);
    enableState();
    setFocused(VFX_TRUE);   
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_hide_param_struct));
    setBgColor(VFX_COLOR_TRANSPARENT);
};


void AutoCapOSDHinteState::onInit(void)
{
    AutoCapOSDState::onInit();

    VFX_OBJ_CREATE(m_hint, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_background, VfxImageFrame, this);    
    VFX_OBJ_CREATE(m_processingPopup, VcpIndicatorPopup,this);       
    VFX_OBJ_CREATE(m_IndicatorPopup, VcpIndicatorPopup,this);       
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup,this);     
    VFX_OBJ_CREATE(m_notifyPopup, VcpConfirmPopup,this);         
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);        
    
    m_hint->setAnchor(0.5, 0.5);
    m_hint->setColor(VFX_COLOR_WHITE); 
    m_hint->setAutoAnimate(VFX_FALSE);
    m_hint->setAutoFontSize(VFX_TRUE);    
    m_hint->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);    
    VfxFontDesc font = m_hint->getFont();
#if defined(VAPP_AUTOCAP_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(14);
#elif defined(VAPP_AUTOCAP_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#elif defined(VAPP_AUTOCAP_OSD_LAYOUT_HVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#else
    font.size = VFX_FONT_DESC_VF_SIZE(35);
#endif  
    m_hint->setFont(font); 

    m_processingPopup->setAnchor(0.5, 0.5);
    m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_processingPopup->setAutoDestory(VFX_FALSE);
    m_processingPopup->setAutoAnimate(VFX_FALSE);

    m_IndicatorPopup->setAnchor(0.5, 0.5);
    m_IndicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_IndicatorPopup->m_signalCanceled.connect(this, &AutoCapOSDHinteState::onBackClicked);
    m_IndicatorPopup->setAutoAnimate(VFX_FALSE);   
    
    m_confirmPopup->setAnchor(0.5, 0.5);    
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);    
    m_confirmPopup->setAutoDestory(VFX_FALSE);    
    m_confirmPopup->m_signalButtonClicked.connect(this, &AutoCapOSDHinteState::onConfirmClicked);
    m_confirmPopup->setAutoAnimate(VFX_FALSE);

    m_notifyPopup->setAnchor(0.5, 0.5);    
    m_notifyPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    m_notifyPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);    
    m_notifyPopup->setAutoDestory(VFX_FALSE);    
    m_notifyPopup->m_signalButtonClicked.connect(this, &AutoCapOSDHinteState::onOkClicked);
    m_notifyPopup->setAutoAnimate(VFX_FALSE);

    m_background->setAnchor(0.5, 0.5);
    m_background->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));   
    m_background->setHidden(VFX_FALSE);        
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT); 

    m_icon->setAnchor(0.5, 0.5); 
    m_icon->setHidden(VFX_TRUE);           
    m_icon->setResId(MAIN_MENU_CAMCO_ICON);
    m_icon->setAutoAnimate(VFX_FALSE);    
    
    m_state = VAPP_AUTOCAP_OSD_STATE_HINT;        
};

void AutoCapOSDHinteState::enterState(void* param)
{
    ASSERT(param != NULL);

    AutoCapOSDState::enterState(param);
     
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_hint_param_struct)); 
    
    m_hint->setString(m_cntx.hintText);  
    m_processingPopup->setText(m_cntx.hintText);
    m_IndicatorPopup->setText(m_cntx.hintText);
    m_confirmPopup->setText(m_cntx.hintText); 
    m_notifyPopup->setText(m_cntx.hintText); 
    m_icon->setResId(m_cntx.hintIcon);        

    m_hint->setHidden(VFX_TRUE);
    m_processingPopup->hide(VFX_FALSE);
    m_IndicatorPopup->hide(VFX_FALSE);
    m_confirmPopup->hide(VFX_FALSE);   
    m_notifyPopup->hide(VFX_FALSE);   
    m_icon->setHidden(VFX_TRUE);   
  
    if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_PROCESSING)
    {
        m_processingPopup->show(VFX_FALSE);    
    }
    else if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_HINT)
    {
        m_IndicatorPopup->show(VFX_FALSE);
    }
    else if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_TEXT)
    {
        m_hint->setHidden(VFX_FALSE);
    }        
    else if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_ICON)
    {
        m_icon->setHidden(VFX_FALSE);
    }        
    else if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_CONFIRM)        
    {
        m_confirmPopup->show(VFX_FALSE);    
        m_confirmPopup->m_signalButtonClicked.connect(this, &AutoCapOSDHinteState::onConfirmClicked);
    }              
    else if(m_cntx.type == VAPP_AUTOCAP_OSD_HINT_TYPE_NOTIFY)          
    {
        m_notifyPopup->show(VFX_FALSE);
    }        

    if(!m_cntx.isPreviewON)
        drawBase(m_cntx.bgContent);
    else
        clean(VFX_COLOR_TRANSPARENT);

    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
        m_hint->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));            
        m_hint->setBounds(VfxRect(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH));           
        m_processingPopup->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));            
        m_IndicatorPopup->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));       
        m_confirmPopup->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));    
        m_notifyPopup->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));  
        m_background->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
        m_icon->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));         
        
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
        m_hint->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));            
        m_hint->setBounds(VfxRect(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT));
        m_processingPopup->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));            
        m_IndicatorPopup->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));      
        m_confirmPopup->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));   
        m_notifyPopup->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));  
        m_background->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
        m_icon->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));         
        
    }


    drawBase(m_cntx.bgContent);
};

void AutoCapOSDHinteState::exitState(void)
{
    AutoCapOSDState::exitState();
    m_hint->setHidden(VFX_TRUE);
    m_processingPopup->hide(VFX_FALSE);
    m_IndicatorPopup->hide(VFX_FALSE);
    m_confirmPopup->m_signalButtonClicked.disconnect(this, &AutoCapOSDHinteState::onConfirmClicked);
    m_confirmPopup->hide(VFX_FALSE);   
    m_notifyPopup->hide(VFX_FALSE);   
}


void AutoCapOSDHinteState::onOkClicked(VfxObject *obj, VfxId id)
{
    if(m_cntx.event == VAPP_AUTOCAP_OSD_HINT_EVT_ERROR)
    {
        if(id != VCP_POPUP_BUTTON_NO_PRESSED)
            evtHdlr->errorPopupHdlr(VAPP_AUTOCAP_EVT_OK, NULL);    
    }
}

void AutoCapOSDHinteState::onBackClicked(VfxObject *obj, VfxFloat id)
{
    if(m_cntx.event == VAPP_AUTOCAP_OSD_HINT_EVT_CAM_STITCHING)            
        evtHdlr->AutoramaStitchHdlr(VAPP_AUTOCAP_EVT_BACK, NULL);    
}

void AutoCapOSDHinteState::onConfirmClicked(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        m_cntx.setting->needRestartPreview();
        if(m_cntx.event == VAPP_AUTOCAP_OSD_HINT_EVT_CAM_NO_CARD)
        {
            m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV));
            evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_OK, NULL);
        }
    }
    else
    {
        if(m_cntx.event == VAPP_AUTOCAP_OSD_HINT_EVT_CAM_NO_CARD)
        {
            evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_CANCEL, NULL);
        }    
    }        
}

void AutoCapOSDHinteState::drawBase(vapp_autocap_osd_draw_image_struct param)
{
    if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_FILE)
    {
        m_background->setPath(VfxWString().loadFromMem(param.srcFileName));            
    }            
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)param.srcBuffAdress;
        imageBuf.pitchBytes = param.srcWidth * 2;
        imageBuf.width = param.srcWidth;
        imageBuf.height = param.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        m_background->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_JPEG)
    {
        S32 image_width;
        S32 image_height;
        S32 result;
        S32 offset_x;
        S32 offset_y;
        S32 resized_offset_x;
        S32 resized_offset_y;
        S32 resized_width;
        S32 resized_height;

        m_background->setBgColor(VFX_COLOR_BLACK);
        
        gdi_handle handleT;

        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            m_background->getSize().width,
            m_background->getSize().height,
            &handleT,
            (U8*)param.cacheBuffAdress,
            m_background->getSize().width*m_background->getSize().height*2);      
        
        gdi_layer_push_and_set_active(handleT);

        result = gdi_image_jpeg_get_dimension(
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize,
                    &image_width,
                    &image_height);

        if (result >= 0)
        {
            if ((m_background->getSize().width >= image_width) && (m_background->getSize().height >= image_height))
            {
                /* align preview window at the center of screen */
                offset_x = ((m_background->getSize().width - image_width) >> 1);
                offset_y = ((m_background->getSize().height - image_height) >> 1);

                gdi_image_jpeg_draw(
                    offset_x, 
                    offset_y, 
                    (U8*)param.srcJpgBuffAdress, 
                    param.srcSize);
            }
            else
            {
                gdi_image_util_fit_bbox(
                    m_background->getSize().width,
                    m_background->getSize().height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_jpeg_draw_resized(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize);
            }
        }
        gdi_layer_pop_and_restore_active();   
        gdi_layer_free(handleT);
        
        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8*)param.cacheBuffAdress;
        imageBuf.pitchBytes = m_background->getSize().width * 2;
        imageBuf.width = m_background->getSize().width;
        imageBuf.height = m_background->getSize().height;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        
        m_background->setImgContent(VfxImageSrc(imageBuf));
        
    }
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR)        
    {
        setBgColor(param.bgColor);
    }
    else
    {
        ASSERT(0);
    }
    m_background->invalidate();

};  

void AutoCapOSDHinteState::setHint(VfxWString hint)
{
    m_hint->setString(hint);   
    m_hint->setHidden(VFX_FALSE);
        
};

void AutoCapOSDCamPreviewState::onInit(void)
{
    AutoCapOSDState::onInit();

    // create UI   
    VFX_OBJ_CREATE(m_rightBar, VfxImageFrame, this);   
    VFX_OBJ_CREATE(m_storageSetting, VcpImageButton, this);   
    
    VFX_OBJ_CREATE(m_zoomer, VappAutoCapCpSlider, this);           
    VFX_OBJ_CREATE(m_gallery, VcpImageButton, this);     
    VFX_OBJ_CREATE(m_galleryContent, VfxFrame, this);            
    VFX_OBJ_CREATE(m_usedSensor, VcpButton, this);
    VFX_OBJ_CREATE(m_viewSwitcher, VcpImageButton, this);

    VFX_OBJ_CREATE(m_modeIcon, VfxImageFrame, this);  

    VFX_OBJ_CREATE(m_indicatorMsgBg, VfxImageFrame, this);   
    VFX_OBJ_CREATE(m_indicatorMsg, VfxTextFrame, this);       

    for(VfxS16 i = 0; i < 4; i++)
    {
        VFX_OBJ_CREATE(m_indIcon[i], VfxImageFrame, this);            
    }  

    for(VfxU8 i = 0; i < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; i++)
    {
        VFX_OBJ_CREATE(m_focusRegion[i], VappAutoCapCpRect, this);
        m_focusRegion[i]->setAnchor(0.5, 0.5);
    }
    VFX_OBJ_CREATE(m_indicatorImage, VfxImageFrame, this);
    m_indicatorImage->setAnchor(0.5, 0.5);
    m_indicatorImage->setResId(IMG_ID_VAPP_AUTOCAP_STATUS_AF_MACRO_ICON);
    m_indicatorImage->setAutoAnimate(VFX_FALSE);
    m_indicatorImage->setHidden(VFX_TRUE);

    m_rightBar->setAnchor(0.5, 0.5);      
    m_rightBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));    
    m_rightBar->setIsUnhittable(VFX_TRUE);
    
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON,IMG_ID_VAPP_AUTOCAP_GALLERY_ICON);
    m_gallery->setAnchor(0.5, 0.5);
    m_gallery->setImage(SI);
    m_gallery->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_gallery->setAutoAnimate(VFX_FALSE);
    m_gallery->setIsEffect(VFX_TRUE);
    m_gallery->setEffectSize(VfxSize(52, 52));        
    m_galleryContent->setIsUnhittable(VFX_TRUE);
    m_galleryContent->setBorderColor(VFX_COLOR_BLACK);
    m_galleryContent->setBorderWidth(2);
    m_galleryContent->setAnchor(0.5, 0.5);
    m_galleryContent->setSize(m_gallery->getSize());
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON,IMG_ID_VAPP_AUTOCAP_CAPTURE_ICON);   
    m_usedSensor->setAnchor(0.5, 0.5);
    m_usedSensor->setImage(SI);
    m_usedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_usedSensor->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_usedSensor->setMargin(0, 0, 0, 0);
    m_usedSensor->setBgColor(VFX_COLOR_TRANSPARENT);
    m_usedSensor->setBgImageList(VcpStateImage(0));
    m_usedSensor->setAutoAnimate(VFX_FALSE);

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON,IMG_ID_VAPP_AUTOCAP_VIEW_SWITCH_ICON);
    m_viewSwitcher->setAnchor(0.5, 0.5);
    m_viewSwitcher->setImage(SI);
    m_viewSwitcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_viewSwitcher->setAutoAnimate(VFX_FALSE);
    m_viewSwitcher->setIsEffect(VFX_TRUE);
    m_viewSwitcher->setEffectSize(VfxSize(52, 52));

    m_storageSetting->setAutoAnimate(VFX_FALSE);
    m_storageSetting->setIsEffect(VFX_TRUE);
    m_storageSetting->setEffectSize(VfxSize(52, 52));        

    m_modeIcon->setAnchor(0.5, 0.5);
    m_modeIcon->setAutoAnimate(VFX_FALSE);
    m_modeIcon->setResId(0);

    m_zoomer->setCpImage(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_ZOOM_OUT_ICON), VfxImageSrc(IMG_ID_VAPP_AUTOCAP_ZOOM_IN_ICON), VfxImageSrc(IMG_ID_VAPP_AUTOCAP_ZOOM_IND_ICON), VfxImageSrc(IMG_ID_VAPP_AUTOCAP_ZOOM_BAR_ICON));
    m_zoomer->setAnchor(0.5, 0.5);    
    m_zoomer->setValueRange(0, 100);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setCurveR(g_vapp_autocap_skin.zoomCurveR);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_indicatorMsg->setAnchor(0.5, 0.5);
    m_indicatorMsg->setAutoAnimate(VFX_FALSE);
    m_indicatorMsg->setColor(VFX_COLOR_WHITE);    
    m_indicatorMsg->setOpacity(0.8);

    m_indicatorMsgBg->setAnchor(0.5, 0.5);
    m_indicatorMsgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_indicatorMsgBg->setResId(IMG_ID_VAPP_AUTOCAP_SETTING_NAME_ICON);  

    m_indIcon[0]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS1_ICON));
    m_indIcon[0]->setAnchor(0,0);
    m_indIcon[1]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS2_ICON));
    m_indIcon[1]->setAnchor(1,0);
    m_indIcon[2]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS4_ICON));
    m_indIcon[2]->setAnchor(0,1);
    m_indIcon[3]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS3_ICON));
    m_indIcon[3]->setAnchor(1,1);

    m_state = VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW;     

    setAutoAnimate(VFX_FALSE);

    m_StoragePopup = NULL;

    // Create an timer      
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);    

    m_storageSetting->m_signalClicked.connect(this, &AutoCapOSDCamPreviewState::onStorageSettingClicked);   
    m_viewSwitcher->m_signalClicked.connect(this, &AutoCapOSDCamPreviewState::onViewSwitchClicked);
    m_gallery->m_signalClicked.connect(this, &AutoCapOSDCamPreviewState::onGalleryClicked);   
    m_usedSensor->m_signalClicked.connect(this, &AutoCapOSDCamPreviewState::onCaptureClicked);
    m_usedSensor->m_signalStateChanged.connect(this, &AutoCapOSDCamPreviewState::onCaptured);
    m_zoomer->m_signalValueChanged.connect(this, &AutoCapOSDCamPreviewState::onZooming);

};


void AutoCapOSDCamPreviewState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    AutoCapOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_cam_preview_param_struct));

    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));  
    
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_AUTOCAP_SETTING_NAME_ICON).getSize().height);
        
    m_zoomer->setValueRange(m_cntx.setting->getMinValue(VAPP_AUTOCAP_SETTING_CAMZOOM), m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM));

    // dont support zoom both autorama and mav
    m_zoomer->setHidden(VFX_TRUE);

    // init setting (because list menu will call related interface when it is created)
    m_cntx.setting->genMainList(VAPP_AUTOCAP_SETTING_MAINLIST_STIRAGE_ONLY);  
    m_cntx.setting->getSettingList(&m_settingList);
        
    VcpStateImage SI = VcpStateImage(
            m_cntx.setting->getSettingImg(VAPP_AUTOCAP_SETTING_CAMSTORAGE),
            m_cntx.setting->getSettingImg(VAPP_AUTOCAP_SETTING_CAMSTORAGE),
            m_cntx.setting->getSettingImg(VAPP_AUTOCAP_SETTING_CAMSTORAGE),
            m_cntx.setting->getSettingImg(VAPP_AUTOCAP_SETTING_CAMSTORAGE));            
    m_storageSetting->setAnchor(0.5, 0.5);
    m_storageSetting->setImage(SI);
    m_storageSetting->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);

    if(mmi_ucs2cmp((const CHAR *) m_cntx.previousFileName, (const CHAR *) L""))
    {
        m_galleryContent->setBgColor(VFX_COLOR_BLACK);        
        m_galleryContent->setImgContent(VfxImageSrc(VFX_WSTR_MEM(m_cntx.previousFileName)));
    }
    else
    {
        m_galleryContent->setBgColor(VFX_COLOR_BLACK);
    }

    if(m_cntx.isMavMode)
    {
    #if defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__)
        if(m_cntx.is3DCameraMode)
        {
            m_modeIcon->setResId(IMG_ID_3D_IMAGE_MODE_ICON);
        }
        else
        {
            m_modeIcon->setResId(IMG_ID_MAV_MODE_ICON);
        }
    #else
        if(m_cntx.is3DCameraMode)
        {
            m_modeIcon->setResId(0);
        }
        else
        {
            m_modeIcon->setResId(0);
        }
    #endif
    }
    else
    {
        m_modeIcon->setResId(0);
    }
    
    if(m_cntx.isCleanModeEnter)   
    {
        setClearMode();
    }        
    else
    {
        setNormalMode();
    }

    if(m_StoragePopup != NULL)
    {
        VFX_OBJ_CLOSE(m_StoragePopup);
        m_StoragePopup = NULL;
        /*
        m_cntx.setting->genMainList(VAPP_AUTOCAP_SETTING_MAINLIST_STIRAGE_ONLY);
        m_cntx.setting->getSettingList(&m_settingList);

        for(VfxU32 i = 0; i < m_settingList.settingItemCount; i++)
        {
            U8 drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_settingList.settingItemValue[i]);
            if(srv_fmgr_drv_is_removable(drv_letter) && !srv_fmgr_drv_is_accessible(drv_letter))
            {
                m_StoragePopup->setIsDisableItem(m_settingList.settingItemValue[i], VFX_TRUE);
            }
            else
            {
                m_StoragePopup->setIsDisableItem(m_settingList.settingItemValue[i], VFX_FALSE);
            }
            m_StoragePopup->checkUpdate();
        }
        */
    }
};

void AutoCapOSDCamPreviewState::exitState(void)
{
    AutoCapOSDState::exitState();

    m_mode = VAPP_AUTOCAP_PREVIEW_MODE_NORMAL;

    m_zoomingTimer->stop();  

    if(m_StoragePopup != NULL)
    {
        VFX_OBJ_CLOSE(m_StoragePopup);       
        m_StoragePopup = NULL;
    }
    m_usedSensor->setOpacity(1);
}

void AutoCapOSDCamPreviewState::cleanFocus(void)
{
    for(VfxU8 i = 0; i < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; i++)
    {
        m_focusRegion[i]->setSize(0, 0);
    }
    m_indicatorImage->setHidden(VFX_TRUE);
}

void AutoCapOSDCamPreviewState::setFocus(VfxU32 idx, vapp_autocap_osd_focus_struct region)
{
    if(region.type == VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING)
        m_focusRegion[idx]->setMode(VAPP_AUTOCAP_CP_RECT_TYPE_AF, VAPP_AUTOCAP_CP_RECT_MODE_NORMAL);
    else if(region.type == VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSED)
        m_focusRegion[idx]->setMode(VAPP_AUTOCAP_CP_RECT_TYPE_AF, VAPP_AUTOCAP_CP_RECT_MODE_SUCCESS);
    else if(region.type == VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING_FAIL)
        m_focusRegion[idx]->setMode(VAPP_AUTOCAP_CP_RECT_TYPE_AF, VAPP_AUTOCAP_CP_RECT_MODE_FAIL);
    if(region.type != VAPP_AUTOCAP_OSD_FOCUS_TYPE_MACRO)
    {
        m_focusRegion[idx]->setSize(region.w, region.h);
        m_focusRegion[idx]->setPos(region.center_x, region.center_y);
        m_indicatorImage->setHidden(VFX_TRUE);
    }
    else
    {
        if(isHorzUI())
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
            m_indicatorImage->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);
        }
        else
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
            m_indicatorImage->setPos(GDI_LCD_WIDTH>>1, GDI_LCD_HEIGHT>>1);
        }
        m_indicatorImage->setHidden(VFX_FALSE);
    }
}


void AutoCapOSDCamPreviewState::updateZoomParam(VfxU32 v)
{
    m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, v);
    m_zoomer->setCurrentValue(v);
}

void AutoCapOSDCamPreviewState::updateIndicatorMsg(VfxU32 s)
{
    m_cntx.indicatorStringID = s;
    
    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));   
    
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_AUTOCAP_SETTING_NAME_ICON).getSize().height);

    if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL || m_mode == VAPP_AUTOCAP_PREVIEW_MODE_CLEAR)
    {
        if(m_cntx.indicatorStringID != 0)  
        {
            m_indicatorMsg->setHidden(VFX_FALSE);
            m_indicatorMsgBg->setHidden(VFX_FALSE);
        }
        else
        {
            m_indicatorMsg->setHidden(VFX_TRUE);
            m_indicatorMsgBg->setHidden(VFX_TRUE);
        }    
    }
    else
    {
        m_indicatorMsg->setHidden(VFX_TRUE);
        m_indicatorMsgBg->setHidden(VFX_TRUE);    
    }    
}


void AutoCapOSDCamPreviewState::setNormalMode(void)
{
#if defined(__LOW_COST_SUPPORT_COMMON__)
    m_storageSetting->setHidden(VFX_TRUE);
#else
    m_storageSetting->setHidden(VFX_FALSE);
#endif

    // dont support zoom both autorama and mav
    //if(m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM) != 1 && !m_cntx.isMavMode)
    //    m_zoomer->setHidden(VFX_FALSE);             
    //else
        m_zoomer->setHidden(VFX_TRUE);                     

    if(!m_cntx.isMavMode)
    {
        m_indIcon[0]->setHidden(VFX_TRUE);
        m_indIcon[1]->setHidden(VFX_TRUE);
        m_indIcon[2]->setHidden(VFX_TRUE);
        m_indIcon[3]->setHidden(VFX_TRUE);
        m_viewSwitcher->setHidden(VFX_TRUE);
    }
    else
    {
        if(!m_isFocussing)
        {
            m_indIcon[0]->setHidden(VFX_FALSE);
            m_indIcon[1]->setHidden(VFX_FALSE);
            m_indIcon[2]->setHidden(VFX_FALSE);
            m_indIcon[3]->setHidden(VFX_FALSE);
        }
        else
        {
            m_indIcon[0]->setHidden(VFX_TRUE);
            m_indIcon[1]->setHidden(VFX_TRUE);
            m_indIcon[2]->setHidden(VFX_TRUE);
            m_indIcon[3]->setHidden(VFX_TRUE);
        }
    #if defined(MOTION_SENSOR_SUPPORT)
        m_viewSwitcher->setHidden(VFX_FALSE);
    #else
        m_viewSwitcher->setHidden(VFX_TRUE);
    #endif
    }

    m_modeIcon->setHidden(VFX_FALSE);
    m_gallery->setHidden(VFX_FALSE);      
    m_galleryContent->setHidden(VFX_FALSE);      
    m_usedSensor->setHidden(VFX_FALSE);   
    m_rightBar->setHidden(VFX_FALSE);
    
    if(m_cntx.indicatorStringID != 0)  
    {
        m_indicatorMsg->setHidden(VFX_FALSE);
        m_indicatorMsgBg->setHidden(VFX_FALSE);
    }
    else
    {
        m_indicatorMsg->setHidden(VFX_TRUE);
        m_indicatorMsgBg->setHidden(VFX_TRUE);
    }

    m_mode = VAPP_AUTOCAP_PREVIEW_MODE_NORMAL;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    vapp_volume_dialog_block(MMI_FALSE);   

}

void AutoCapOSDCamPreviewState::setClearMode(void)
{
#if defined(__LOW_COST_SUPPORT_COMMON__)
    m_storageSetting->setHidden(VFX_TRUE);
#else
    m_storageSetting->setHidden(VFX_FALSE);
#endif

    m_zoomer->setHidden(VFX_TRUE);             

    if(!m_cntx.isMavMode)
    {
        m_indIcon[0]->setHidden(VFX_TRUE);
        m_indIcon[1]->setHidden(VFX_TRUE);
        m_indIcon[2]->setHidden(VFX_TRUE);
        m_indIcon[3]->setHidden(VFX_TRUE);
        m_viewSwitcher->setHidden(VFX_TRUE);
    }
    else
    {
        if(!m_isFocussing)
        {
            m_indIcon[0]->setHidden(VFX_FALSE);
            m_indIcon[1]->setHidden(VFX_FALSE);
            m_indIcon[2]->setHidden(VFX_FALSE);
            m_indIcon[3]->setHidden(VFX_FALSE);
        }
        else
        {
            m_indIcon[0]->setHidden(VFX_TRUE);
            m_indIcon[1]->setHidden(VFX_TRUE);
            m_indIcon[2]->setHidden(VFX_TRUE);
            m_indIcon[3]->setHidden(VFX_TRUE);
        }
    #if defined(MOTION_SENSOR_SUPPORT)
        m_viewSwitcher->setHidden(VFX_FALSE);
    #else
        m_viewSwitcher->setHidden(VFX_TRUE);
    #endif
    }

    m_modeIcon->setHidden(VFX_FALSE);
    m_gallery->setHidden(VFX_FALSE);      
    m_galleryContent->setHidden(VFX_FALSE);      

    m_usedSensor->setHidden(VFX_FALSE);      
    m_rightBar->setHidden(VFX_FALSE);

    if(m_cntx.indicatorStringID != 0)   
    {
        m_indicatorMsg->setHidden(VFX_FALSE);
        m_indicatorMsgBg->setHidden(VFX_FALSE);        
    }
    else
    {
        m_indicatorMsg->setHidden(VFX_TRUE);
        m_indicatorMsgBg->setHidden(VFX_TRUE);        
    }

    m_mode = VAPP_AUTOCAP_PREVIEW_MODE_CLEAR;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

}
    
void AutoCapOSDCamPreviewState::layout(void)
{
     vapp_autocap_osd_skin *sp = &g_vapp_autocap_skin;
     
    if(isHorzUI())
    {
        if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL)
        {            
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));               
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
            m_rightBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);

            m_modeIcon->setPos(m_modeIcon->getSize().width, m_modeIcon->getSize().height);

            m_storageSetting->setPos(m_rightBar->getPos().x, GDI_LCD_WIDTH - sp->galleryPos[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);
            m_galleryContent->setPos(sp->galleryPos[0], sp->galleryPos[1]);
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_viewSwitcher->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(1);

            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());            
            
            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
            
        }
        else if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_CLEAR)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));              
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
            m_rightBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);

            m_modeIcon->setPos(m_modeIcon->getSize().width, m_modeIcon->getSize().height);

            m_storageSetting->setPos(m_rightBar->getPos().x, GDI_LCD_WIDTH - sp->galleryPos[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);    
            m_galleryContent->setPos(sp->galleryPos[0], sp->galleryPos[1]);    
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_viewSwitcher->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(0);

            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
            
        }           
        m_indIcon[0]->setPos(GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4, GDI_LCD_WIDTH/4);
        m_indIcon[1]->setPos(GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4, GDI_LCD_WIDTH/4);
        m_indIcon[2]->setPos(GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4, GDI_LCD_WIDTH*3/4);
        m_indIcon[3]->setPos(GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4, GDI_LCD_WIDTH*3/4);
    }    
    else   
    {
        if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_V_RIGHT_BAR_ICON));
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1));
            m_rightBar->setSize(sp->SideBarSize[1],sp->SideBarSize[0]);

            m_modeIcon->setPos(m_modeIcon->getSize().width, m_modeIcon->getSize().height);

            m_storageSetting->setPos(sp->galleryPos[1], m_rightBar->getPos().y);

            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
            m_galleryContent->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));
            m_viewSwitcher->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0],sp->zoomControlPos[1]));
            m_zoomer->setOpacity(1);

            m_indicatorMsg->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);

        }
        else if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_CLEAR)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_V_RIGHT_BAR_ICON));
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1));
            m_rightBar->setSize(sp->SideBarSize[1],sp->SideBarSize[0]);

            m_modeIcon->setPos(m_modeIcon->getSize().width, m_modeIcon->getSize().height);

            m_storageSetting->setPos(sp->galleryPos[1], m_rightBar->getPos().y);

            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
            m_galleryContent->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));
            m_viewSwitcher->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0],sp->zoomControlPos[1]));
            m_zoomer->setOpacity(0);

            m_indicatorMsg->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);

        }         
        m_indIcon[0]->setPos(GDI_LCD_WIDTH/4, GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4);
        m_indIcon[1]->setPos(GDI_LCD_WIDTH*3/4, GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4);
        m_indIcon[2]->setPos(GDI_LCD_WIDTH/4, GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4);
        m_indIcon[3]->setPos(GDI_LCD_WIDTH*3/4, GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4);
    }

    invalidate();
}

void AutoCapOSDCamPreviewState::onZooming(VfxU32 value)
{
    m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, value);
}

void AutoCapOSDCamPreviewState::onGalleryClicked(VfxObject *obj, VfxId id)
{
    if(m_isBusy)
        return;

    evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_ENTER_GALLERY, NULL);
}

void AutoCapOSDCamPreviewState::onCaptureClicked(VfxObject* obj, VfxId id)
{
    if(m_isBusy)
        return;
    
    evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_CAPTURE, NULL);                
    m_isFocussing = VFX_FALSE;
    m_usedSensor->setOpacity(1);
}

void AutoCapOSDCamPreviewState::onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{
    refreshAutoExitTimer();

    if(m_isBusy)
        return;

    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
        #if defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
            evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_FOCUS, NULL);
            if(VappAutoCapPage::m_errStr == 0)
                m_isFocussing = VFX_TRUE;
            else
                m_isFocussing = VFX_FALSE;
            if(m_cntx.isMavMode)
            {
                m_indIcon[0]->setHidden(VFX_TRUE);
                m_indIcon[1]->setHidden(VFX_TRUE);
                m_indIcon[2]->setHidden(VFX_TRUE);
                m_indIcon[3]->setHidden(VFX_TRUE);
            }
        #endif
            m_usedSensor->setOpacity(0.5);
            break;
        case VCP_BUTTON_STATE_NORMAL:
        #if defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
            if(m_isFocussing)
                evtHdlr->FocusHdlr(VAPP_AUTOCAP_EVT_FOCUS_STOP, NULL);
            m_isFocussing = VFX_FALSE;
            if(m_cntx.isMavMode)
            {
                m_indIcon[0]->setHidden(VFX_FALSE);
                m_indIcon[1]->setHidden(VFX_FALSE);
                m_indIcon[2]->setHidden(VFX_FALSE);
                m_indIcon[3]->setHidden(VFX_FALSE);
            }
        #endif
            m_usedSensor->setOpacity(1);
            break;
        default:
            break;
    }
}


void AutoCapOSDCamPreviewState::onViewSwitchClicked(VfxObject *obj, VfxId id)
{
    if(m_isBusy)
        return;

    evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_VIEW_SWITCH, NULL);
}

void AutoCapOSDCamPreviewState::onStorageSettingClicked(VfxObject *obj, VfxId id)
{
    if(m_isBusy)
        return;

    m_cntx.setting->genMainList(VAPP_AUTOCAP_SETTING_MAINLIST_STIRAGE_ONLY);  
    m_cntx.setting->getSettingList(&m_settingList);

    vapp_volume_dialog_block(MMI_TRUE);   

    VFX_OBJ_CREATE(m_StoragePopup, VcpSelectPopup, this);
    
    m_StoragePopup->setText(VFX_WSTR_RES(m_settingList.settingStrId[m_settingList.CurrentSettingIdx]));
    m_StoragePopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    m_StoragePopup->setAutoAnimate(VFX_FALSE);
    m_StoragePopup->setAutoDestory(VFX_TRUE); 
    
    m_StoragePopup->m_signalPopupState.connect(this, &AutoCapOSDCamPreviewState::onSettingSelectionChanged);

    for(VfxU32 i = 0; i < m_settingList.settingItemCount; i++)
    {
        if(i == m_settingList.CurrentSettingValueIdx)
        {
            m_StoragePopup->addItem(
                m_settingList.settingItemValue[i], 
                VFX_WSTR_RES(m_settingList.settingItemStrId[i]), 
                VFX_TRUE);            
        }
        else
        {
            m_StoragePopup->addItem(
                m_settingList.settingItemValue[i], 
                VFX_WSTR_RES(m_settingList.settingItemStrId[i]));
        }

        U8 drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_settingList.settingItemValue[i]);
        if(srv_fmgr_drv_is_removable(drv_letter) && !srv_fmgr_drv_is_accessible(drv_letter))
        {
            m_StoragePopup->setIsDisableItem(m_settingList.settingItemValue[i], VFX_TRUE);
        }
        
    }
    
    m_StoragePopup->show(VFX_TRUE);

}

void AutoCapOSDCamPreviewState::onSettingSelectionChanged(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{

    if(m_StoragePopup && state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        m_StoragePopup = NULL;    
        
        VcpSelectPopup *senderPopup = (VcpSelectPopup*)sender;
        m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMSTORAGE, senderPopup->getFirstSeletedId());        
        evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_RESTART, NULL);             
        
    }
}

VfxBool AutoCapOSDCamPreviewState::isHorzUI(void)
{
#if defined (HORIZONTAL_CAMERA)
    if((m_cntx.setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA && m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE) != VAPP_AUTOCAP_CAPSIZE_WALLPAPER))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }        
#else
    {
        return VFX_FALSE;
    }   
#endif
}

void AutoCapOSDCamPreviewState::ZoomingIn(VfxTimer *source)
{
    if(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) < m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM))
        m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) + 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM));                     
    m_zoomingTimer->start();                    

}

void AutoCapOSDCamPreviewState::ZoomingOut(VfxTimer *source)
{

    if(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) > m_cntx.setting->getMinValue(VAPP_AUTOCAP_SETTING_CAMZOOM))                                    
        m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) - 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM));                         
    m_zoomingTimer->start();
                 
}


VfxBool AutoCapOSDCamPreviewState::onPenInput(VfxPenEvent & event)
{
    refreshAutoExitTimer();

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode != VAPP_AUTOCAP_PREVIEW_MODE_CLEAR) 
        {
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(!m_rightBar->getBounds().contains(posR))            
                setClearMode();                
        }   
        else
        {
            setNormalMode();           
        }
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return AutoCapOSDState::onPenInput(event);

}


VfxBool AutoCapOSDCamPreviewState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();

    // when storage screen is shown, no need to resp key event
    // App screen is not active
    if(m_StoragePopup)
        return AutoCapOSDState::onKeyInput(event);        
    
    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA:  
        case VFX_KEY_CODE_ENTER:              
        {
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_DOWN)        
            {
            #if defined(VAPP_AUTOCAP_AF_SUPPORT)
                evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_FOCUS, NULL);
                if(VappAutoCapPage::m_errStr == 0)
                    m_isFocussing = VFX_TRUE;
                else
                    m_isFocussing = VFX_FALSE;
                if(m_cntx.isMavMode)
                {
                    m_indIcon[0]->setHidden(VFX_TRUE);
                    m_indIcon[1]->setHidden(VFX_TRUE);
                    m_indIcon[2]->setHidden(VFX_TRUE);
                    m_indIcon[3]->setHidden(VFX_TRUE);
                }
            #endif
            }
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
            #if defined(VAPP_AUTOCAP_AF_SUPPORT)
                if(m_isFocussing)
                    evtHdlr->FocusHdlr(VAPP_AUTOCAP_EVT_CAPTURE, NULL);
                else
            #endif
                evtHdlr->PreviewHdlr(VAPP_AUTOCAP_EVT_CAPTURE, NULL);
                m_isFocussing = VFX_FALSE;
                if(m_cntx.isMavMode)
                {
                    m_indIcon[0]->setHidden(VFX_FALSE);
                    m_indIcon[1]->setHidden(VFX_FALSE);
                    m_indIcon[2]->setHidden(VFX_FALSE);
                    m_indIcon[3]->setHidden(VFX_FALSE);
                }
            }
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_UP)
            {
            #if defined(VAPP_AUTOCAP_AF_SUPPORT)
                if(m_isFocussing)
                    evtHdlr->FocusHdlr(VAPP_AUTOCAP_EVT_FOCUS_STOP, NULL);
                m_isFocussing = VFX_FALSE;
                if(m_cntx.isMavMode)
                {
                    m_indIcon[0]->setHidden(VFX_FALSE);
                    m_indIcon[1]->setHidden(VFX_FALSE);
                    m_indIcon[2]->setHidden(VFX_FALSE);
                    m_indIcon[3]->setHidden(VFX_FALSE);
                }
            #endif
            }
            return VFX_TRUE;
        }
        case VFX_KEY_CODE_ARROW_UP:          
        case VFX_KEY_CODE_VOL_UP:
        {   
            // dont support zoom both autorama and mav
            //if(!isHorzUI())
               // return VFX_TRUE;

            if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL)            
            {     
                if(m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM) == 1)  
                    return VFX_TRUE;           
                                   
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
                {            
                    if(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) < m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM))
                        m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) + 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM));     

                    m_zoomingTimer->m_signalTick.disconnect(this, &AutoCapOSDCamPreviewState::ZoomingOut);                           
                    m_zoomingTimer->m_signalTick.connect(this, &AutoCapOSDCamPreviewState::ZoomingIn);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                  
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();                      
                }
            }                
            else if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_CLEAR)
            {            
                setNormalMode();    
            }  
            return VFX_TRUE;            
        }            
        case VFX_KEY_CODE_ARROW_DOWN:          
        case VFX_KEY_CODE_VOL_DOWN:
        {     
            // dont support zoom both autorama and mav             
            //if(!isHorzUI())
               // return VFX_TRUE;

            if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL)            
            {
                if(m_cntx.setting->getMaxValue(VAPP_AUTOCAP_SETTING_CAMZOOM) == 1)  
                    return VFX_TRUE;       
                
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
                {       
                    if(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) > m_cntx.setting->getMinValue(VAPP_AUTOCAP_SETTING_CAMZOOM))                                    
                        m_cntx.setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM) - 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM));      
                    
                    m_zoomingTimer->m_signalTick.disconnect(this, &AutoCapOSDCamPreviewState::ZoomingIn);                           
                    m_zoomingTimer->m_signalTick.connect(this, &AutoCapOSDCamPreviewState::ZoomingOut);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                             
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();                      
                }
            }                
            else if(m_mode == VAPP_AUTOCAP_PREVIEW_MODE_CLEAR)
            {            
                setNormalMode();    
            }  

            return VFX_TRUE;            
        }  
        case VFX_KEY_CODE_BACK:
        {
            // dont support zoom both autorama and mav
            //if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            //{
            //    if(!m_cntx.isMavMode && m_mode == VAPP_AUTOCAP_PREVIEW_MODE_NORMAL)
            //    {
            //        setClearMode();
            //        return VFX_TRUE;
            //    }
            //}
        }        
    }
    return AutoCapOSDState::onKeyInput(event);
}

void AutoCapOSDCamQuickViewState::onInit(void)
{
    AutoCapOSDState::onInit();
    
    VFX_OBJ_CREATE(m_shownImage, VfxFrame, this);  
    m_shownImage->setAnchor(0.5, 0.5);
    m_shownImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT); 
    m_shownImage->setAutoAnimate(VFX_FALSE);

    VFX_OBJ_CREATE(m_effectTimer, VfxTimer, this);

    m_state = VAPP_AUTOCAP_OSD_STATE_CAMERA_QUICK_VIEW;        

    m_effectTimer->m_signalTick.connect(this, &AutoCapOSDCamQuickViewState::onEffectTimerTick);    

};

void AutoCapOSDCamQuickViewState::enterState(void* param)
{
    AutoCapOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_cam_quick_view_param_struct));

    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
        m_shownImage->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);                          
        m_shownImage->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));          
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
        m_shownImage->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);                  
        m_shownImage->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));          
    }

    drawBase(m_cntx.savedImg);


    m_effectTimer->setStartDelay(800);
    m_effectTimer->start();        

};

void AutoCapOSDCamQuickViewState::onEffectTimerTick(VfxTimer *source)
{
    if(!VAPP_AUTOCAP_QK_VIEW_ANUMATE)
    {
        onEndOfTimeline(NULL, VFX_FALSE);    
        return;
    }
    /*
    if(m_cntx.isHorzUI)
    {
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
        timeline->setTarget(m_shownImage);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_shownImage->getTransform());

        T.data.affine.sx = 40.0 / m_shownImage->getSize().width; 
        T.data.affine.sy = 30.0 / m_shownImage->getSize().height;
        T.data.affine.rz = (((90) * VFX_PI)/180.0); 
        T.data.affine.tx = 450 - m_shownImage->getPos().x;
        T.data.affine.ty= 30 - m_shownImage->getPos().y;
        
        timeline->setToValue(T);
        timeline->setDurationTime(500);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &AutoCapOSDCamQuickViewState::onEndOfTimeline);
    }        
    else
    {
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
        timeline->setTarget(m_shownImage);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_shownImage->getTransform());

        T.data.affine.sx = 30.0 / m_shownImage->getSize().width; 
        T.data.affine.sy = 40.0 / m_shownImage->getSize().height;
        T.data.affine.rz = 0; 
        T.data.affine.tx = (GDI_LCD_WIDTH - 30) - m_shownImage->getPos().x;
        T.data.affine.ty= 450 - m_shownImage->getPos().y;
        
        timeline->setToValue(T);
        timeline->setDurationTime(500);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();  
        timeline->m_signalStopped.connect(this, &AutoCapOSDCamQuickViewState::onEndOfTimeline);    
    }*/
    
}

void AutoCapOSDCamQuickViewState::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_cntx.type == VAPP_AUTOCAP_OSD_QV_EVT_PANORAMA_SHOT)
        evtHdlr->AutoramaDoneHdlr(VAPP_AUTOCAP_EVT_VIEW_STOP, NULL);
    
    if(timeline)
        VFX_OBJ_CLOSE(timeline);    
    
}

void AutoCapOSDCamQuickViewState::drawBase(vapp_autocap_osd_draw_image_struct param)
{
    if(m_cntx.savedImg.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)m_cntx.savedImg.srcBuffAdress;
        imageBuf.pitchBytes = m_cntx.savedImg.srcWidth * 2;
        imageBuf.width = m_cntx.savedImg.srcWidth;
        imageBuf.height = m_cntx.savedImg.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        m_shownImage->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_JPEG)
    {
        S32 image_width;
        S32 image_height;
        S32 result;
       //S32 offset_x = 0;
       //S32 offset_y = 0;
        S32 resized_offset_x;
        S32 resized_offset_y;
        S32 resized_width;
        S32 resized_height;

        m_shownImage->setBgColor(VFX_COLOR_BLACK);
        
        gdi_handle handleT;

        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            m_shownImage->getSize().width,
            m_shownImage->getSize().height,
            &handleT,
            (U8*)param.cacheBuffAdress,
            m_shownImage->getSize().width*m_shownImage->getSize().height*2);    
        
        gdi_layer_push_and_set_active(handleT);

        gdi_layer_clear(GDI_COLOR_BLACK);
        
        result = gdi_image_jpeg_get_dimension(
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize,
                    &image_width,
                    &image_height);

        if (result >= 0)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            {
                gdi_image_util_fit_bbox(
                    m_shownImage->getSize().width,
                    m_shownImage->getSize().height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_jpeg_draw_resized(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize);
            }
        }
        gdi_layer_pop_and_restore_active();    
        gdi_layer_free(handleT);

        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8*)param.cacheBuffAdress;
        imageBuf.pitchBytes = m_shownImage->getSize().width * 2;
        imageBuf.width = m_shownImage->getSize().width;
        imageBuf.height = m_shownImage->getSize().height;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        
        m_shownImage->setImgContent(VfxImageSrc(imageBuf));        
    }    
    else if(m_cntx.savedImg.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR)
    {
        m_shownImage->setBgColor(param.bgColor);
        m_shownImage->setSize(getSize());
    }   
    else
    {
        ASSERT(0);
    }        
    m_shownImage->invalidate();    
};  

void AutoCapOSDCamPanoramaShotState::onInit(void)
{
    AutoCapOSDState::onInit();
    
    for(VfxS16 i = 0; i < CAMCO_CAM_MAX_MAV_NUM; i++)
    {
        VFX_OBJ_CREATE(m_prevIcon[i], VfxFrame, this);            
    }
    VFX_OBJ_CREATE(m_targetIcon, VfxFrame, this);
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
    {
        VFX_OBJ_CREATE(m_directionIcon[i], VfxImageFrame, this);            
    }   
    for(VfxS16 i = 0; i < 4; i++)
    {
        VFX_OBJ_CREATE(m_indIcon[i], VfxImageFrame, this);            
    }       
    VFX_OBJ_CREATE(m_realDirection, VfxImageFrame, this);               
    VFX_OBJ_CREATE(m_directionHint, VfxTextFrame, this);               
      
    VFX_OBJ_CREATE(m_rect, VfxFrame, this);        
    VFX_OBJ_CREATE(m_softkeyBar, VfxImageFrame, this);     
    VFX_OBJ_CREATE(m_cancel, VcpImageButton, this);  
    VFX_OBJ_CREATE(m_stitch, VcpImageButton, this);      
    VFX_OBJ_CREATE(m_div, VfxImageFrame, this); 

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_PANO_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CANCEL_ICON);
    m_cancel->setAnchor(0.5, 0.5);
    m_cancel->setImage(SI);
    m_cancel->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_cancel->setAutoAnimate(VFX_FALSE);
    m_cancel->setIsEffect(VFX_TRUE);
    m_cancel->setEffectSize(VfxSize(52, 52));    

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_PANO_OK_ICON,IMG_ID_VAPP_AUTOCAP_PANO_OK_ICON,IMG_ID_VAPP_AUTOCAP_PANO_OK_ICON,IMG_ID_VAPP_AUTOCAP_PANO_OK_ICON);
    m_stitch->setAnchor(0.5, 0.5);
    m_stitch->setImage(SI);
    m_stitch->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_stitch->setAutoAnimate(VFX_FALSE);
    m_stitch->setIsEffect(VFX_TRUE);
    m_stitch->setEffectSize(VfxSize(52, 52));    

    m_div->setAnchor(0.5, 0.5);
    m_div->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIV_ICON));
    m_div->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);           
    m_div->setAutoAnimate(VFX_FALSE);

    m_softkeyBar->setAnchor(0.5, 0.5);      
    m_softkeyBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_softkeyBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RIGHT_BAR_ICON));    
    m_softkeyBar->setAutoAnimate(VFX_FALSE);
    m_softkeyBar->setIsUnhittable(VFX_TRUE);

    m_directionHint->setAnchor(0.5, 0.5);
    m_directionHint->setFont(VFX_FONT_DESC_LARGE);  
    m_directionHint->setColor(VFX_COLOR_WHITE); 
    m_directionHint->setAutoAnimate(VFX_FALSE);
    VfxFontDesc font = m_directionHint->getFont();
#if defined(VAPP_AUTOCAP_OSD_LAYOUT_HVGA)    
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#elif defined(VAPP_AUTOCAP_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(14);
#elif defined(VAPP_AUTOCAP_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(14);
#endif            
    m_directionHint->setFont(font); 
    m_directionHint->setString(VfxWString(STR_ID_VAPP_AUTOCAP_MOVE_TO_START_CAPTURE));  
    m_directionHint->setHidden(VFX_TRUE);

    m_indIcon[0]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS1_ICON));
    m_indIcon[0]->setAnchor(0,0);
    m_indIcon[1]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS2_ICON));
    m_indIcon[1]->setAnchor(1,0);
    m_indIcon[2]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS4_ICON));
    m_indIcon[2]->setAnchor(0,1);
    m_indIcon[3]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_RECT_AF_SUCCESS3_ICON));
    m_indIcon[3]->setAnchor(1,1);

    for(VfxU16 i = 0; i < CAMCO_CAM_MAX_MAV_NUM; i++)
    {
        m_prevIcon[i]->setAnchor(0.5,0.5);
        m_prevIcon[i]->setSize(g_vapp_autocap_skin.previousIconSize[0], g_vapp_autocap_skin.previousIconSize[1]);
        m_prevIcon[i]->setBgColor(VFX_COLOR_GREY);
        m_prevIcon[i]->setBorderWidth(3);        
        m_prevIcon[i]->setBorderColor(VFX_COLOR_GREY);                
        m_prevIcon[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);     
        m_prevIcon[i]->setHidden(VFX_TRUE);           
    }  
    m_targetIcon->setAnchor(0.5,0.5);
    m_targetIcon->setSize(g_vapp_autocap_skin.previousIconSize[0], g_vapp_autocap_skin.previousIconSize[1]);
    m_targetIcon->setBgColor(VFX_COLOR_TRANSPARENT);
    m_targetIcon->setBorderWidth(3);        
    m_targetIcon->setOpacity(0.8);
    m_targetIcon->setBorderColor(VFX_COLOR_WHITE);                
    m_targetIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);     
    m_targetIcon->setHidden(VFX_TRUE);           
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
    {
        m_directionIcon[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_U_ICON + i));
        m_directionIcon[i]->setAnchor(0.5,0.5);
        m_directionIcon[i]->setHidden(VFX_TRUE);         
    }  
    m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_U_ICON));
    m_realDirection->setAnchor(0.5,0.5);
    m_realDirection->setHidden(VFX_TRUE);             

    m_rect->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_FOCUS_ICON));
    m_rect->setAnchor(0.5,0.5);
    m_rect->setSize(g_vapp_autocap_skin.nextFocusSize[0], g_vapp_autocap_skin.nextFocusSize[1]);    
 
    m_state = VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT;  

    m_cancel->m_signalClicked.connect(this, &AutoCapOSDCamPanoramaShotState::onCancelClicked); 
    m_stitch->m_signalClicked.connect(this, &AutoCapOSDCamPanoramaShotState::onStitchClicked);     

}

void AutoCapOSDCamPanoramaShotState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    AutoCapOSDState::enterState(param);
    
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_cam_panoramashot_param_struct));

    // when all UI CP at the first time 
    if(m_cntx.count == 1)
    {
        for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
        {
            m_directionIcon[i]->setHidden(VFX_TRUE);         
        }  
        m_targetIcon->setHidden(VFX_TRUE);
        for(VfxU16 i = 0; i < CAMCO_CAM_MAX_MAV_NUM; i++)
        {
            m_prevIcon[i]->setHidden(VFX_TRUE);           
        }     
        m_rect->setHidden(VFX_TRUE);           
        m_cancel->setHidden(VFX_TRUE);           
        m_stitch->setHidden(VFX_TRUE);   
        m_realDirection->setHidden(VFX_TRUE);          
    }

    if(!m_cntx.isMavMode)
    {
        for(VfxU32 i = 0; i < m_cntx.count; i++)
        {
            drawBase(m_prevIcon[i], m_cntx.capturedPicture[i]);
        }
        for(VfxU32 i = m_cntx.count; i < CAMCO_CAM_MAX_MAV_NUM; i++)
        {
            m_prevIcon[i]->setImgContent(VfxImageSrc());
        }
        m_indIcon[0]->setHidden(VFX_TRUE);
        m_indIcon[1]->setHidden(VFX_TRUE);
        m_indIcon[2]->setHidden(VFX_TRUE);
        m_indIcon[3]->setHidden(VFX_TRUE);       
    }
    else
    {
        for(VfxU16 i = 0; i < m_cntx.count; i++)
        {
            m_prevIcon[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_CAPTURED_ICON));
            m_prevIcon[i]->setSize(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_CAPTURED_ICON).getSize());
            m_prevIcon[i]->setBgColor(VFX_COLOR_TRANSPARENT);
            m_prevIcon[i]->setBorderWidth(0);
        }
        for(VfxU16 i = m_cntx.count; i < CAMCO_CAM_MAX_MAV_NUM; i++)
        {
            m_prevIcon[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_CAPTURING_ICON));
            m_prevIcon[i]->setSize(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_CAPTURING_ICON).getSize());
            m_prevIcon[i]->setBgColor(VFX_COLOR_TRANSPARENT);
            m_prevIcon[i]->setBorderWidth(0);
        }
        m_indIcon[0]->setHidden(VFX_FALSE);
        m_indIcon[1]->setHidden(VFX_FALSE);
        m_indIcon[2]->setHidden(VFX_FALSE);
        m_indIcon[3]->setHidden(VFX_FALSE);
    }
};

void AutoCapOSDCamPanoramaShotState::setDirection(vapp_autocap_panorama_direction_enum dir)
{
    m_cntx.direction = dir;
        
    updateIcon();
    updateProgress();
}

void AutoCapOSDCamPanoramaShotState::setMotion(VfxS32 x, VfxS32 y)
{
    if(!m_cntx.isMavMode)
    {
        VfxFloat rX, rY;
        rX = x * m_prevIcon[m_cntx.count - 1]->getSize().width / m_cntx.previewWindow.size.width;
        rY = y * m_prevIcon[m_cntx.count - 1]->getSize().height/ m_cntx.previewWindow.size.height;        
        
        m_rect->setPos(
            m_prevIcon[m_cntx.count - 1]->getPos().x + rX,
            m_prevIcon[m_cntx.count - 1]->getPos().y + rY);
    }
    else
    {
        VfxFloat rX, rY;
        rX = x * m_prevIcon[m_cntx.count - 1]->getSize().width / m_cntx.previewWindow.size.width;
        rY = y * m_prevIcon[m_cntx.count - 1]->getSize().height/ m_cntx.previewWindow.size.height;

        m_rect->setPos(
            m_prevIcon[m_cntx.count - 1]->getPos().x + rX,
            m_prevIcon[m_cntx.count - 1]->getPos().y + rY);
    }

    updateProgress();    
}

void AutoCapOSDCamPanoramaShotState::setRatio(VfxFloat r)
{
    m_cntx.overlapRatio = r;
}

void AutoCapOSDCamPanoramaShotState::updateIcon(void)
{
    if(!m_cntx.isMavMode)
    {
        if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_END)
        {
            for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
            {
                m_directionIcon[i]->setHidden(VFX_FALSE);
            }
            m_directionHint->setHidden(VFX_FALSE);
            m_targetIcon->setHidden(VFX_TRUE);
            for(VfxU16 i = 0; i < CAMCO_CAM_MAX_MAV_NUM; i++)
            {
                m_prevIcon[i]->setHidden(VFX_TRUE);
            }
            m_prevIcon[0]->setHidden(VFX_FALSE);
            m_rect->setHidden(VFX_FALSE);
            m_cancel->setHidden(VFX_TRUE);
            m_stitch->setHidden(VFX_TRUE);
            m_div->setHidden(VFX_TRUE);
            m_softkeyBar->setHidden(VFX_TRUE);
            m_realDirection->setHidden(VFX_TRUE);
        }
        else
        {
            for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
            {
                m_directionIcon[i]->setHidden(VFX_TRUE);
            }
            m_directionHint->setHidden(VFX_TRUE);
            m_targetIcon->setHidden(VFX_FALSE);
            for(VfxU16 i = 0; i < m_cntx.totalCount; i++)
            {
                if(i >= m_cntx.count)
                    m_prevIcon[i]->setHidden(VFX_TRUE);
                else
                    m_prevIcon[i]->setHidden(VFX_FALSE);
            }
            m_rect->setHidden(VFX_FALSE);
            m_cancel->setHidden(VFX_FALSE);
        #if !defined(__LOW_COST_SUPPORT_COMMON__)
            m_stitch->setHidden(VFX_FALSE);
            m_div->setHidden(VFX_FALSE);
        #else
            m_stitch->setHidden(VFX_TRUE);
            m_div->setHidden(VFX_TRUE);
        #endif
            m_softkeyBar->setHidden(VFX_FALSE);
            m_realDirection->setHidden(VFX_FALSE);
        }
    }
    // MAV mode
    else
    {
        for(VfxU16 i = 0; i < VAPP_AUTOCAP_PANORAMA_DIRECTION_END; i++)
        {
            m_directionIcon[i]->setHidden(VFX_TRUE);
        }
        m_directionHint->setHidden(VFX_TRUE);
        m_targetIcon->setHidden(VFX_TRUE);
        for(VfxU16 i = 0; i < m_cntx.totalCount; i++)
        {
            m_prevIcon[i]->setHidden(VFX_FALSE);
        }
        m_rect->setHidden(VFX_TRUE);
        m_cancel->setHidden(VFX_TRUE);
        m_stitch->setHidden(VFX_TRUE);
        m_div->setHidden(VFX_TRUE);
        m_softkeyBar->setHidden(VFX_TRUE);
        m_realDirection->setHidden(VFX_FALSE);
    }
}

void AutoCapOSDCamPanoramaShotState::updateProgress(void)
{
    if(!m_cntx.isMavMode)
    {
        vapp_autocap_osd_skin *sp = &g_vapp_autocap_skin;     
        
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);

        if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_END)
        {  
            #define directionConditionShift 35
            
            m_directionIcon[VAPP_AUTOCAP_PANORAMA_DIRECTION_UP]->setPos(sp->upDirection[0], sp->upDirection[1]);
            m_directionIcon[VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN]->setPos(sp->downDirection[0], sp->downDirection[1]);
            m_directionIcon[VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT]->setPos(sp->leftDirection[0], sp->leftDirection[1]);
            m_directionIcon[VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT]->setPos(sp->rightDirection[0], sp->rightDirection[1]);    
            m_directionHint->setPos(
                (sp->leftDirection[0] + sp->rightDirection[0]) / 2,
                (GDI_LCD_WIDTH + sp->downDirection[1]) / 2);
            m_prevIcon[0]->setPos((m_prevIcon[1]->getSize().width>>1) + directionConditionShift, GDI_LCD_WIDTH - (m_prevIcon[1]->getSize().height>>1) - directionConditionShift);     
        }        
        else
        {           
            if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_UP)
            {
                m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_U_ICON));            
                m_realDirection->setPos(sp->upIndicatorDirection[0], sp->upIndicatorDirection[1]); 
                
                for(VfxS16 i = 0; i < (m_cntx.count) + 1; i++)
                {
                    m_prevIcon[i]->setPos(
                        (m_prevIcon[1]->getSize().width>>1) + 5, 
                        (GDI_LCD_WIDTH>>1) + m_prevIcon[1]->getSize().height * m_cntx.overlapRatio * ((VfxS32)((m_cntx.count + 1)>>1) - (i + 1)) + (m_prevIcon[1]->getSize().height >>2));
                }  
                    
                m_softkeyBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
                m_softkeyBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);  

            #if !defined(__LOW_COST_SUPPORT_COMMON__)
                m_div->setPos(m_softkeyBar->getPos().x, (GDI_LCD_WIDTH>>1));
                m_div->setSize(m_softkeyBar->getSize().width, 5);
                
                m_cancel->setPos(sp->captureVertDirBack[0], sp->captureVertDirBack[1]);    
                m_stitch->setPos(sp->captureVertDirStitch[0], sp->captureVertDirStitch[1]);
            #else
                m_cancel->setPos(sp->captureVertDirBack[0], (GDI_LCD_WIDTH>>1));
            #endif
            }
            else if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN)
            {
                m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_D_ICON));            
                m_realDirection->setPos(sp->downIndicatorDirection[0], sp->downIndicatorDirection[1]);
                
                for(VfxS16 i = 0; i < (m_cntx.count) + 1; i++)
                {
                    m_prevIcon[i]->setPos(
                        (m_prevIcon[1]->getSize().width>>1) + 5, 
                        (GDI_LCD_WIDTH>>1) + m_prevIcon[1]->getSize().height * m_cntx.overlapRatio * ((i + 1) - (VfxS32)((m_cntx.count + 1)>>1)) - (m_prevIcon[1]->getSize().height >>2));
                }  

                m_softkeyBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
                m_softkeyBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);  

            #if !defined(__LOW_COST_SUPPORT_COMMON__)
                m_div->setPos(m_softkeyBar->getPos().x, (GDI_LCD_WIDTH>>1));
                m_div->setSize(m_softkeyBar->getSize().width, 5);

                m_cancel->setPos(sp->captureVertDirBack[0], sp->captureVertDirBack[1]);    
                m_stitch->setPos(sp->captureVertDirStitch[0], sp->captureVertDirStitch[1]);
            #else
                m_cancel->setPos(sp->captureVertDirBack[0], (GDI_LCD_WIDTH>>1));
            #endif
            }
            else if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT)
            {
                m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_L_ICON));            
                m_realDirection->setPos(sp->leftIndicatorDirection[0], sp->leftIndicatorDirection[1]); 
                
                for(VfxS16 i = 0; i < (m_cntx.count) + 1; i++)
                {
                    m_prevIcon[i]->setPos(
                        (m_cntx.previewWindow.size.width>>1) + m_prevIcon[1]->getSize().width * m_cntx.overlapRatio * ((VfxS32)((m_cntx.count + 1)>>1) - (i + 1)) + (m_prevIcon[1]->getSize().width >>2),
                        GDI_LCD_WIDTH - (m_prevIcon[1]->getSize().height>>1) - 5); 
                }  

                m_softkeyBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
                m_softkeyBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);  

            #if !defined(__LOW_COST_SUPPORT_COMMON__)
                m_div->setPos(m_softkeyBar->getPos().x, (GDI_LCD_WIDTH>>1));
                m_div->setSize(m_softkeyBar->getSize().width, 5);

                m_cancel->setPos(sp->captureHorzDirback[0], sp->captureHorzDirback[1]);    
                m_stitch->setPos(sp->captureHorzDirStitch[0], sp->captureHorzDirStitch[1]);
            #else
                m_cancel->setPos(sp->captureVertDirBack[0], (GDI_LCD_WIDTH>>1));
            #endif
            }
            else if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
            {
                m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIR_R_ICON));            
                m_realDirection->setPos(sp->rightIndicatorDirection[0], sp->rightIndicatorDirection[1]);             

                for(VfxS16 i = 0; i < (m_cntx.count) + 1; i++)
                {
                    m_prevIcon[i]->setPos(
                        (m_cntx.previewWindow.size.width>>1) + m_prevIcon[1]->getSize().width * m_cntx.overlapRatio * ((i + 1) - (VfxS32)((m_cntx.count + 1)>>1)) - (m_prevIcon[1]->getSize().width >>2),
                        GDI_LCD_WIDTH - (m_prevIcon[1]->getSize().height>>1) - 5); 
                }  

                m_softkeyBar->setPos(GDI_LCD_HEIGHT - (sp->SideBarSize[0]>>1), sp->SideBarSize[1]>>1);
                m_softkeyBar->setSize(sp->SideBarSize[0],sp->SideBarSize[1]);  

            #if !defined(__LOW_COST_SUPPORT_COMMON__)
                m_div->setPos(m_softkeyBar->getPos().x, (GDI_LCD_WIDTH>>1));
                m_div->setSize(m_softkeyBar->getSize().width, 5);

                m_cancel->setPos(sp->captureHorzDirback[0], sp->captureHorzDirback[1]);    
                m_stitch->setPos(sp->captureHorzDirStitch[0], sp->captureHorzDirStitch[1]);
            #else
                m_cancel->setPos(sp->captureVertDirBack[0], (GDI_LCD_WIDTH>>1));
            #endif
            }
            else
            {
                ASSERT(0);
            }

            for(VfxU16 i = 0; i < m_cntx.totalCount; i++)
            {
                if(m_cntx.count == i)
                {
                    m_targetIcon->setPos(m_prevIcon[i]->getPos());
                }                           
            }          
                        
        }       
    }
    else
    {
        //vapp_autocap_osd_skin *sp = &g_vapp_autocap_skin;
        if(m_cntx.isHorzUI)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);

            if(m_cntx.direction != VAPP_AUTOCAP_PANORAMA_DIRECTION_END)
            {
                if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
                {
                    VfxU32 N = (m_cntx.totalCount + 2);
                    for(VfxS16 i = 0; i < (m_cntx.totalCount) + 1; i++)
                    {
                        m_prevIcon[i]->setPos(
                            (m_cntx.previewWindow.size.width>>1) - (m_prevIcon[1]->getSize().width + 5) * (VfxS32)((N>>1) - i),
                            GDI_LCD_WIDTH - (VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON).getSize().height)*1.5);
                    }

                    m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON));
                    m_realDirection->setPos(
                        (m_cntx.previewWindow.size.width>>1) - (m_prevIcon[1]->getSize().width + 5) * (VfxS32)((N>>1) - (N-1)),
                        GDI_LCD_WIDTH - (VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON).getSize().height)*1.5);
                }
                else
                {
                    ASSERT(0);
                }
            }
            m_indIcon[0]->setPos(GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4, GDI_LCD_WIDTH/4);
            m_indIcon[1]->setPos(GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4, GDI_LCD_WIDTH/4);
            m_indIcon[2]->setPos(GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4, GDI_LCD_WIDTH*3/4);
            m_indIcon[3]->setPos(GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4, GDI_LCD_WIDTH*3/4);

        }
        else
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

            if(m_cntx.direction != VAPP_AUTOCAP_PANORAMA_DIRECTION_END)
            {
                if(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
                {
                    VfxU32 N = (m_cntx.totalCount + 2);
                    for(VfxS16 i = 0; i < (m_cntx.totalCount) + 1; i++)
                    {
                        m_prevIcon[i]->setPos(
                            (m_cntx.previewWindow.size.width>>1) - (m_prevIcon[1]->getSize().width + 5) * (VfxS32)((N>>1) - i),
                            GDI_LCD_HEIGHT - (VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON).getSize().height)*1.5);
                    }

                    m_realDirection->setImgContent(VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON));
                    m_realDirection->setPos(
                        (m_cntx.previewWindow.size.width>>1) - (m_prevIcon[1]->getSize().width + 5) * (VfxS32)((N>>1) - (N-1)),
                        GDI_LCD_HEIGHT - (VfxImageSrc(IMG_ID_VAPP_3D_CAMERA_RIGHT_ARROW_ICON).getSize().height)*1.5);
                }
                else
                {
                    ASSERT(0);
                }
            }
            m_indIcon[0]->setPos(GDI_LCD_WIDTH/4, GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4);
            m_indIcon[1]->setPos(GDI_LCD_WIDTH*3/4, GDI_LCD_HEIGHT/2 - GDI_LCD_WIDTH/4);
            m_indIcon[2]->setPos(GDI_LCD_WIDTH/4, GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4);
            m_indIcon[3]->setPos(GDI_LCD_WIDTH*3/4, GDI_LCD_HEIGHT/2 + GDI_LCD_WIDTH/4);
        }
    }
}


void AutoCapOSDCamPanoramaShotState::drawBase(VfxFrame *target, vapp_autocap_osd_draw_image_struct param)
{
    if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)param.srcBuffAdress;
        imageBuf.pitchBytes = param.srcWidth * 2;
        imageBuf.width = param.srcWidth;
        imageBuf.height = param.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        target->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_JPEG)
    {
        S32 image_width;
        S32 image_height;
        S32 result;
        S32 offset_x;
        S32 offset_y;
        S32 resized_offset_x;
        S32 resized_offset_y;
        S32 resized_width;
        S32 resized_height;

        target->setBgColor(VFX_COLOR_BLACK);
        
        gdi_handle handleT;

        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            target->getSize().width,
            target->getSize().height,
            &handleT,
            (U8*)param.cacheBuffAdress,
            target->getSize().width*target->getSize().height*2);   
        
        gdi_layer_push_and_set_active(handleT);

        result = gdi_image_jpeg_get_dimension(
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize,
                    &image_width,
                    &image_height);

        if (result >= 0)
        {
            if ((target->getSize().width >= image_width) && (target->getSize().height >= image_height))
            {
                /* align preview window at the center of screen */
                offset_x = ((target->getSize().width - image_width) >> 1);
                offset_y = ((target->getSize().height - image_height) >> 1);

                gdi_image_jpeg_draw(
                    offset_x, 
                    offset_y, 
                    (U8*)param.srcJpgBuffAdress, 
                    param.srcSize);
            }
            else
            {
                gdi_image_util_fit_bbox(
                    target->getSize().width,
                    target->getSize().height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_jpeg_draw_resized(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize);
            }
        }
        gdi_layer_pop_and_restore_active();  
        gdi_layer_free(handleT);

        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8*)param.cacheBuffAdress;
        imageBuf.pitchBytes = target->getSize().width * 2;
        imageBuf.width = target->getSize().width;
        imageBuf.height = target->getSize().height;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        
        target->setImgContent(VfxImageSrc(imageBuf));           
    }       
    else if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR)
    {
        target->setBgColor(param.bgColor);
    }      
    else
    {
        ASSERT(0);
    }  
    target->invalidate();

}

void AutoCapOSDCamPanoramaShotState::onCancelClicked(VfxObject *obj, VfxId id)
{
    evtHdlr->AutoramaShotHdlr(VAPP_AUTOCAP_EVT_BACK, NULL);
}

void AutoCapOSDCamPanoramaShotState::onStitchClicked(VfxObject *obj, VfxId id)
{
    evtHdlr->AutoramaShotHdlr(VAPP_AUTOCAP_EVT_STITCH, NULL);
}

VfxBool AutoCapOSDCamPanoramaShotState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA:  
        case VFX_KEY_CODE_ENTER:            
        {
        #if !defined(__LOW_COST_SUPPORT_COMMON__)
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
                if(!m_cntx.isMavMode)
                    evtHdlr->AutoramaShotHdlr(VAPP_AUTOCAP_EVT_STITCH, NULL);
            }
        #endif
            return VFX_TRUE;
        }       
        case VFX_KEY_CODE_BACK: 
        {           
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
                if(!m_cntx.isMavMode)
                    evtHdlr->AutoramaShotHdlr(VAPP_AUTOCAP_EVT_BACK, NULL);
            }             
            return VFX_TRUE;
        }               
    }
    return AutoCapOSDState::onKeyInput(event);
}


void AutoCapOSDCamPanoramaClipState::onInit(void)
{
    AutoCapOSDState::onInit();

    VFX_OBJ_CREATE(m_clipResultImage, VfxFrame, this);  
    VFX_OBJ_CREATE(m_sourceBg, VfxFrame, this);  
    VFX_OBJ_CREATE(m_clipSourceImage, VfxFrame, this);  
    VFX_OBJ_CREATE(m_leftCover, VfxFrame, this);  
    VFX_OBJ_CREATE(m_rightCover, VfxFrame, this);       
    VFX_OBJ_CREATE(m_leftBound, VfxFrame, this);  
    VFX_OBJ_CREATE(m_rightBound, VfxFrame, this);     
    VFX_OBJ_CREATE(m_horzSplit, VfxFrame, this);     
    VFX_OBJ_CREATE(m_vertBg, VfxFrame, this);         
    VFX_OBJ_CREATE(m_save, VcpImageButton, this);  
    VFX_OBJ_CREATE(m_delete, VcpImageButton, this);      

    m_sourceBg->setAnchor(0.5, 0.5);
    m_sourceBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));
    m_sourceBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_sourceBg->setAutoAnimate(VFX_FALSE);    
    m_sourceBg->setIsUnhittable(VFX_TRUE);
    
    m_leftBound->setAnchor(0.5, 0.5);
    m_leftBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_LB_ICON));
    m_leftBound->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_leftBound->setAutoAnimate(VFX_FALSE);

    m_rightBound->setAnchor(0.5, 0.5);
    m_rightBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_RB_ICON));
    m_rightBound->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);           
    m_rightBound->setAutoAnimate(VFX_FALSE);

    m_leftCover->setAnchor(0.5, 0.5);
    m_leftCover->setOpacity(0.7);
    m_leftCover->setBgColor(VFX_COLOR_BLACK);    
    m_leftCover->setAutoAnimate(VFX_FALSE);
    m_leftCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));
    m_leftCover->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);  

    m_rightCover->setAnchor(0.5, 0.5);
    m_rightCover->setOpacity(0.7);    
    m_rightCover->setBgColor(VFX_COLOR_BLACK);    
    m_rightCover->setAutoAnimate(VFX_FALSE);
    m_rightCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));
    m_rightCover->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);      

    m_clipResultImage->setAnchor(0.5, 0.5);
    m_clipResultImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);      
    m_clipSourceImage->setAnchor(0.5, 0.5);
    m_clipSourceImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);          
    m_clipSourceImage->setBgColor(VFX_COLOR_TRANSPARENT);

    m_horzSplit->setAnchor(0.5, 0.5);
    m_horzSplit->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIV_ICON));
    m_horzSplit->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);           
    m_horzSplit->setAutoAnimate(VFX_FALSE);
    m_horzSplit->setSize(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_DIV_ICON).getSize());

    m_vertBg->setAnchor(0.5, 0.5);
    m_vertBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_BG_ICON));
    m_vertBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);           
    m_vertBg->setAutoAnimate(VFX_FALSE);    
    m_vertBg->setIsUnhittable(VFX_TRUE);    

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_SAVE_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_SAVE_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_SAVE_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_SAVE_ICON);
    m_save->setAnchor(0.5, 0.5);
    m_save->setImage(SI);
    m_save->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_save->setAutoAnimate(VFX_FALSE);
    m_save->setHidden(VFX_FALSE);    
    m_save->setIsEffect(VFX_TRUE);
    m_save->setEffectSize(VfxSize(52, 52));  

    SI = VcpStateImage(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_CANCEL_ICON,IMG_ID_VAPP_AUTOCAP_PANO_CLIP_CANCEL_ICON);
    m_delete->setAnchor(0.5, 0.5);
    m_delete->setImage(SI);
    m_delete->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_delete->setAutoAnimate(VFX_FALSE);
    m_delete->setHidden(VFX_FALSE);    
    m_delete->setIsEffect(VFX_TRUE);
    m_delete->setEffectSize(VfxSize(52, 52));  

    m_save->m_signalClicked.connect(this, &AutoCapOSDCamPanoramaClipState::onSaveClicked); 
    m_delete->m_signalClicked.connect(this, &AutoCapOSDCamPanoramaClipState::onDeleteClicked);   

    m_state = VAPP_AUTOCAP_OSD_STATE_PANORAMA_CLIP;  

}

void AutoCapOSDCamPanoramaClipState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    AutoCapOSDState::enterState(param);
    
    memcpy(&m_cntx, param, sizeof(vapp_autocap_osd_cam_panoramashot_clip_param_struct));

    m_isHorzClip = (VfxBool)(m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT || m_cntx.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT);

    vapp_autocap_osd_draw_image_struct drawParam;
    drawParam.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF;
    drawParam.srcBuffAdress = m_cntx.quickViewSourceBuffer;
    drawParam.srcWidth = m_cntx.quickViewSize[0];
    drawParam.srcHeight = m_cntx.quickViewSize[1];    
    drawBase(m_clipSourceImage, drawParam);

    drawParam.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF;
    drawParam.srcBuffAdress = m_cntx.quickViewBuffer;
    drawParam.srcWidth = m_cntx.quickViewSize[0];
    drawParam.srcHeight = m_cntx.quickViewSize[1];    
    drawBase(m_clipResultImage, drawParam);    

    layout();

    m_touchObject = vapp_autocap_PANO_CLIP_TOUCH_OBJ_NONE;    
}

void AutoCapOSDCamPanoramaClipState::layout(void)
{
#define OFFSET (50)

    vapp_autocap_osd_skin *sp = &g_vapp_autocap_skin;

    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);                 
        if(m_isHorzClip)
        {
            VfxSize s = VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_LB_ICON).getSize();        
            
            m_sourceBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));
            m_sourceBg->setPos((sp->clipHorzDirBar[0]>>1), GDI_LCD_WIDTH- (sp->clipHorzDirBar[1]>>1));
            m_sourceBg->setSize(sp->clipHorzDirBar[0], sp->clipHorzDirBar[1]);

            m_vertBg->setPos(
                GDI_LCD_HEIGHT - (VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_BG_ICON).getSize().width / 2),
                (GDI_LCD_WIDTH - VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON).getSize().height) >>1);
            
            m_vertBg->setSize(
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_BG_ICON).getSize().width, 
                sp->clipBg[1]);

            m_horzSplit->setPos(m_vertBg->getPos());

            m_save->setPos(m_vertBg->getPos().x, m_vertBg->getPos().y + (m_vertBg->getSize().height >>2));
            m_delete->setPos(m_vertBg->getPos().x, m_vertBg->getPos().y - (m_vertBg->getSize().height >>2));                            

            if(m_cntx.quickViewSize[0]*1.0/m_cntx.quickViewSize[1] < 8)
            {
                m_clipSourceImage->setSize((s.height)*(m_cntx.quickViewSize[0]*1.0/m_cntx.quickViewSize[1]), s.height);
                m_clipSourceImage->setPos((GDI_LCD_HEIGHT>>1), m_sourceBg->getPos().y);
            }
            else
            {
                s.height = ((GDI_LCD_HEIGHT - OFFSET) * m_cntx.quickViewSize[1] * 1.0)/m_cntx.quickViewSize[0];
                m_clipSourceImage->setSize((s.height * m_cntx.quickViewSize[0] * 1.0)/m_cntx.quickViewSize[1], s.height);
                m_clipSourceImage->setPos((GDI_LCD_HEIGHT>>1), m_sourceBg->getPos().y);
            }            

            m_leftBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_LB_ICON));
            m_leftBound->setAnchor(1, 0.5);
            m_rightBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_RB_ICON));            
            m_rightBound->setAnchor(0, 0.5);            
    
            m_leftBound->setSize(
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_LB_ICON).getSize().width * m_clipSourceImage->getSize().height / VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_LB_ICON).getSize().height, 
                m_clipSourceImage->getSize().height);       
            /* avoid the floating calculation miss
            m_leftBound->setPos(
                m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width>>1) + (((*m_cntx.leftBound) * m_clipSourceImage->getSize().width) / m_cntx.quickViewSize[0]),
                m_clipSourceImage->getPos().y);
            */
            m_leftBound->setPos(
                m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width>>1) + (((*m_cntx.leftBound) * s.height) / m_cntx.quickViewSize[1]),
                m_clipSourceImage->getPos().y);

            m_rightBound->setSize(
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_RB_ICON).getSize().width * m_clipSourceImage->getSize().height / VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_RB_ICON).getSize().height, 
                m_clipSourceImage->getSize().height);        
            /* avoid the floating calculation miss
            m_rightBound->setPos(
                m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width>>1) + (((*m_cntx.rightBound) * m_clipSourceImage->getSize().width) / m_cntx.quickViewSize[0]),
                m_clipSourceImage->getPos().y);
            */
            m_rightBound->setPos(
                m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width>>1) + (((*m_cntx.rightBound) * s.height) / m_cntx.quickViewSize[1]),
                m_clipSourceImage->getPos().y);

            VfxU32 lenInSourceImg = (m_rightBound->getPos().x - m_leftBound->getPos().x);
            VfxS32 centerInSourceImg = (m_rightBound->getPos().x + m_leftBound->getPos().x) / 2;            
            m_clipResultImage->setSize(
                (m_clipSourceImage->getSize().width * GDI_LCD_HEIGHT) / lenInSourceImg, 
                (m_clipSourceImage->getSize().height * GDI_LCD_HEIGHT) / lenInSourceImg);
            m_clipResultImage->setPos(
                (GDI_LCD_HEIGHT>>1) - (((VfxS32)(centerInSourceImg - m_clipSourceImage->getPos().x) * 1.0 * GDI_LCD_HEIGHT) / lenInSourceImg), 
                (GDI_LCD_WIDTH>>1));

            m_leftCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));   
            
            m_leftCover->setSize(
                m_leftBound->getPos().x - (m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width>>1)), 
                m_leftBound->getSize().height);    // because the BG picture has shadow, doen cover it on source picture
            
            VfxU32 t = m_leftBound->getPos().x - (m_leftCover->getSize().width >>1);
            if(t != 0) t--;            
            m_leftCover->setPos(
                t, 
                m_sourceBg->getPos().y);

            m_rightCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_ICON));  
            
            m_rightCover->setSize(
                (m_clipSourceImage->getPos().x + (m_clipSourceImage->getSize().width>>1)) + 1 - m_rightBound->getPos().x, 
                m_rightBound->getSize().height);    // because the BG picture has shadow, doen cover it on source picture  
            
            m_rightCover->setPos(
                m_rightBound->getPos().x + (m_rightCover->getSize().width >>1), 
                m_sourceBg->getPos().y);
            
        }
        else
        {
            VfxSize s = VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_UB_ICON).getSize();        
            
            m_sourceBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_ICON));
            m_sourceBg->setPos((sp->clipVertDirBar[0]>>1), (sp->clipVertDirBar[1]>>1));
            m_sourceBg->setSize(sp->clipVertDirBar[0], sp->clipVertDirBar[1]);

            m_vertBg->setPos(
                GDI_LCD_HEIGHT - (VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_BG_ICON).getSize().width / 2),
                GDI_LCD_WIDTH >>1);
            
            m_vertBg->setSize(
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_BG_ICON).getSize().width, 
                sp->clipBg[1]);

            m_horzSplit->setPos(m_vertBg->getPos());

            m_save->setPos(m_vertBg->getPos().x, m_vertBg->getPos().y + (m_vertBg->getSize().height >>2));
            m_delete->setPos(m_vertBg->getPos().x, m_vertBg->getPos().y - (m_vertBg->getSize().height >>2));       

            if(m_cntx.quickViewSize[1]*1.0/m_cntx.quickViewSize[0] < 6)
            {
                m_clipSourceImage->setSize(s.width, (s.width)*(m_cntx.quickViewSize[1]*1.0/m_cntx.quickViewSize[0]));
                m_clipSourceImage->setPos(m_sourceBg->getPos());
            }
            else            
            {
                s.width = ((GDI_LCD_WIDTH - OFFSET) * m_cntx.quickViewSize[0] * 1.0)/m_cntx.quickViewSize[1];
                m_clipSourceImage->setSize(s.width, (s.width * m_cntx.quickViewSize[1] * 1.0)/m_cntx.quickViewSize[0]);
                m_clipSourceImage->setPos(m_sourceBg->getPos());
            }            

            m_leftBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_UB_ICON));
            m_leftBound->setAnchor(0.5, 1);            
            m_rightBound->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_DB_ICON));              
            m_rightBound->setAnchor(0.5, 0);           
            
            m_leftBound->setSize(
                m_clipSourceImage->getSize().width, 
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_UB_ICON).getSize().height * m_clipSourceImage->getSize().width / VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_UB_ICON).getSize().width);       
            /* avoid the floating calculation miss
            m_leftBound->setPos(
                m_clipSourceImage->getPos().x,
                m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height >>1) + (((*m_cntx.leftBound) * m_clipSourceImage->getSize().height) / m_cntx.quickViewSize[1]));
            */
            m_leftBound->setPos(
                m_clipSourceImage->getPos().x,
                m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height >>1) + (((*m_cntx.leftBound) * s.width) / m_cntx.quickViewSize[0]));

            m_rightBound->setSize(
                m_clipSourceImage->getSize().width, 
                VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_DB_ICON).getSize().height * m_clipSourceImage->getSize().width / VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_DB_ICON).getSize().width);       
            /* avoid the floating calculation miss
            m_rightBound->setPos(
                m_clipSourceImage->getPos().x,
                m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height >>1) + (((*m_cntx.rightBound) * m_clipSourceImage->getSize().height) / m_cntx.quickViewSize[1]));
            */
            m_rightBound->setPos(
                m_clipSourceImage->getPos().x,
                m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height >>1) + (((*m_cntx.rightBound) * s.width) / m_cntx.quickViewSize[0]));

            VfxU32 lenInSourceImg = (m_rightBound->getPos().y - m_leftBound->getPos().y);
            VfxS32 centerInSourceImg = (m_rightBound->getPos().y + m_leftBound->getPos().y) / 2;            
            m_clipResultImage->setSize(
                (m_clipSourceImage->getSize().width * GDI_LCD_WIDTH) / lenInSourceImg, 
                (m_clipSourceImage->getSize().height * GDI_LCD_WIDTH) / lenInSourceImg);
            m_clipResultImage->setPos(
                (GDI_LCD_HEIGHT>>1), 
                (GDI_LCD_WIDTH>>1) - (((VfxS32)(centerInSourceImg - m_clipSourceImage->getPos().y) * 1.0 * GDI_LCD_WIDTH) / lenInSourceImg));

            m_leftCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_ICON));            
                    
            m_leftCover->setSize(
                m_leftBound->getSize().width,
                m_leftBound->getPos().y - (m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height>>1))); 

            VfxU32 t = m_leftBound->getPos().y - (m_leftCover->getSize().height>>1);
            if(t != 0) t--;    
            m_leftCover->setPos(
                m_sourceBg->getPos().x,                
                t); 
            
            m_rightCover->setImgContent(VfxImageSrc(IMG_ID_VAPP_AUTOCAP_PANO_CLIP_BG_V_ICON));
            
            m_rightCover->setSize(
                m_rightBound->getSize().width,                
                (m_clipSourceImage->getPos().y + (m_clipSourceImage->getSize().height>>1)) + 1 - m_rightBound->getPos().y); 

            m_rightCover->setPos(
                m_sourceBg->getPos().x,                
                m_rightBound->getPos().y + (m_rightCover->getSize().height >>1)); 
                    
        }
    }
    else
    {
        ASSERT(0);
    }

}

void AutoCapOSDCamPanoramaClipState::updateClipBound(VfxU32 pos, vapp_autocap_panorama_clip_touch_obj_enum obj)
{
    if(m_isHorzClip)
    {           
        VfxU32 predict_pos;
        VfxU32 predict_w;        
        VfxU32 L = (m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width >>1));
        VfxFloat F = m_cntx.quickViewSize[0] / (m_clipSourceImage->getSize().width * 1.0);         
        
        if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
        {            
            if(pos > m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width >>1) &&
               pos < m_rightBound->getPos().x)
            {                    
                predict_pos = (VfxU32)((pos - L) * F);  
            }
            else if(pos < m_clipSourceImage->getPos().x - (m_clipSourceImage->getSize().width >>1))
            {
                predict_pos = 0;               
            }    
            else
            {
                predict_pos = (*m_cntx.leftBound);
            }
            predict_w = (*m_cntx.rightBound) - predict_pos;                 
        }
        else
        {            
            if(pos < m_clipSourceImage->getPos().x + (m_clipSourceImage->getSize().width >>1) &&
               pos > m_leftBound->getPos().x)
            {                  
                predict_pos = (VfxU32)((pos - L) * F);
            }
            else if(pos > m_clipSourceImage->getPos().x + (m_clipSourceImage->getSize().width >>1))
            {
                predict_pos = m_cntx.quickViewSize[0];              
            }  
            else
            {
                predict_pos =(*m_cntx.rightBound);          
            }
            predict_w = predict_pos - (*m_cntx.leftBound);              
        }
        
        // to avoid size less than LCD size 
        //needCheck is TRUE mean this movement will make ratio decrease            
        if(((predict_w * 1.0) / m_cntx.quickViewSize[1]) < ((getSize().width * 1.0) / getSize().height)) 
        {
            predict_w = ((getSize().width * 1.0) / getSize().height) *m_cntx.quickViewSize[1];
            if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
                predict_pos = (*m_cntx.rightBound) - predict_w;
            else
                predict_pos = (*m_cntx.leftBound) + predict_w;                
        }

        if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
        { 
            (*m_cntx.leftBound) = predict_pos;             
        }
        else
        {
            (*m_cntx.rightBound) = predict_pos;        
        }

    }
    else
    {
        VfxU32 predict_pos;        
        VfxU32 predict_h;            
        VfxU32 L = (m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height>>1));
        VfxFloat F = m_cntx.quickViewSize[1] / (m_clipSourceImage->getSize().height * 1.0);           
        
        if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
        {            
            if(pos > m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height>>1) &&
               pos < m_rightBound->getPos().y)
            {                         
                predict_pos = (VfxU32)((pos - L) * F);       
            }
            else if(pos < m_clipSourceImage->getPos().y - (m_clipSourceImage->getSize().height>>1))
            {
                predict_pos = 0;                         
            }    
            else
            {
                predict_pos = (*m_cntx.leftBound);
            }
            predict_h = (*m_cntx.rightBound) - predict_pos;                 
        }
        else
        {            
            if(pos < m_clipSourceImage->getPos().y + (m_clipSourceImage->getSize().height>>1) &&
               pos > m_leftBound->getPos().y)
            {                  
                predict_pos = (VfxU32)((pos - L) * F);
            }
            else if(pos > m_clipSourceImage->getPos().y + (m_clipSourceImage->getSize().height>>1))
            {
                predict_pos = m_cntx.quickViewSize[1];
            } 
            else
            {
                predict_pos = (*m_cntx.rightBound);              
            }
            predict_h = predict_pos - (*m_cntx.leftBound);                                  
        }   
        
        // to avoid size less than LCD size         
        //needCheck is TRUE mean this movement will make ratio increase                
        if(((m_cntx.quickViewSize[0] * 1.0) /predict_h) > ((getSize().width * 1.0) / getSize().height)) 
        {
            predict_h = ((getSize().height * 1.0) / getSize().width) *m_cntx.quickViewSize[0];
            if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
                predict_pos = (*m_cntx.rightBound) - predict_h;
            else
                predict_pos = (*m_cntx.leftBound) + predict_h;           
        }  

        if(obj == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
        { 
            (*m_cntx.leftBound) = predict_pos;             
        }
        else
        {
            (*m_cntx.rightBound) = predict_pos;        
        }

    }

}

void AutoCapOSDCamPanoramaClipState::updateClipResult(void)
{
    return;
}

void AutoCapOSDCamPanoramaClipState::drawBase(VfxFrame *target, vapp_autocap_osd_draw_image_struct param)
{
    if(param.drawingType == VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)param.srcBuffAdress;
        imageBuf.pitchBytes = param.srcWidth * 2;
        imageBuf.width = param.srcWidth;
        imageBuf.height = param.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        target->setImgContent(VfxImageSrc(imageBuf));
    }

}

void AutoCapOSDCamPanoramaClipState::onSaveClicked(VfxObject *obj, VfxId id)
{
    evtHdlr->AutoramaClipHdlr(VAPP_AUTOCAP_EVT_CLIP, NULL);
}

void AutoCapOSDCamPanoramaClipState::onDeleteClicked(VfxObject *obj, VfxId id)
{
    evtHdlr->AutoramaClipHdlr(VAPP_AUTOCAP_EVT_CANCEL, NULL);
}

VfxBool AutoCapOSDCamPanoramaClipState::onPenInput(VfxPenEvent & event)
{
    refreshAutoExitTimer();

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        pos = (event.getRelPos(m_leftBound)); 
        
        VfxRect BB = m_leftBound->getBounds();
        BB.origin.x -= (BB.size.width>>1);
        BB.origin.y -= (BB.size.height>>1);        
        BB.size.height = BB.getHeight() * 2;
        BB.size.width = BB.getWidth() * 2;
        
        if(BB.contains(pos))    
        {
            m_touchObject = vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND;
        }

        pos = (event.getRelPos(m_rightBound)); 
        
        BB = m_rightBound->getBounds();
        BB.origin.x -= (BB.size.width>>1);
        BB.origin.y -= (BB.size.height>>1);        
        BB.size.height = BB.getHeight() * 2;
        BB.size.width = BB.getWidth() * 2;
        
        if(BB.contains(pos))    
        {
            m_touchObject = vapp_autocap_PANO_CLIP_TOUCH_OBJ_RIGHT_BOUND;
        }    

        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if(m_touchObject == vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND)
        {
            // prevent litle moving cause cliper left-right shake
            // ====================================================        
            VfxPoint ppos = (event.getRelPos(m_leftBound)); 
            
            VfxRect BB = m_leftBound->getBounds();
            BB.origin.x -= (BB.size.width>>1);
            BB.origin.y -= (BB.size.height>>1);        
            BB.size.height = BB.getHeight() * 2;
            BB.size.width = BB.getWidth() * 2;
            
            if(BB.contains(ppos))    
            {
                return VFX_TRUE; 
            }    
            // ====================================================
            
            if(m_isHorzClip)
                updateClipBound(pos.x, vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND);
            else
                updateClipBound(pos.y, vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND);                
            layout();
            updateClipResult();            
        }
        else if(m_touchObject == vapp_autocap_PANO_CLIP_TOUCH_OBJ_RIGHT_BOUND)
        {
            // prevent litle moving cause cliper left-right shake
            // ====================================================            
            VfxPoint ppos = (event.getRelPos(m_rightBound)); 
            
            VfxRect BB = m_rightBound->getBounds();
            BB.origin.x -= (BB.size.width>>1);
            BB.origin.y -= (BB.size.height>>1);        
            BB.size.height = BB.getHeight() * 2;
            BB.size.width = BB.getWidth() * 2;
            
            if(BB.contains(ppos))    
            {
                 return VFX_TRUE; 
            }          
            // ====================================================
            
            if(m_isHorzClip)
                updateClipBound(pos.x, vapp_autocap_PANO_CLIP_TOUCH_OBJ_RIGHT_BOUND);
            else
                updateClipBound(pos.y, vapp_autocap_PANO_CLIP_TOUCH_OBJ_RIGHT_BOUND);               
            layout();                      
            updateClipResult();            
        }
        return VFX_TRUE;        
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_touchObject = vapp_autocap_PANO_CLIP_TOUCH_OBJ_NONE;       
        return VFX_TRUE;        
    }
    
    return AutoCapOSDState::onPenInput(event);

}

VfxBool AutoCapOSDCamPanoramaClipState::onKeyInput(VfxKeyEvent & event)
{
    refreshAutoExitTimer();
    switch (event.keyCode)
    {          
        case VFX_KEY_CODE_BACK: 
        {           
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
                evtHdlr->AutoramaClipHdlr(VAPP_AUTOCAP_EVT_BACK, NULL);
            }             
            return VFX_TRUE;
        }               
    }

    return AutoCapOSDState::onKeyInput(event);

}

#endif
