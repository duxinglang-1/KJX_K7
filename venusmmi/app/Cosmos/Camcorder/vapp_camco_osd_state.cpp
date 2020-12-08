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

#include "vapp_camco_osd_state.h"
#include "MMI_include.h"

#ifdef __VAPP_CAMCO__
extern vapp_camco_osd_skin g_vapp_camco_skin;

void CamcoOSDState::onInit(void)
{
    VfxControl::onInit();
    setPos(0, 0);
    setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
    setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    setBgColor(VRT_COLOR_TRANSPARENT);    
	evtHdlr = NULL;
    m_isHorz = VFX_TRUE;
};

void CamcoOSDState::updateScreen(void)
{
    // vrt should know where need to update automatically
    //invalidate();
}

void CamcoOSDState::clean(const VfxColor &value)
{
    setBgColor(value);
    // vrt should know where need to update automatically    
    //invalidate();
}

void CamcoOSDState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    setBgColor(VFX_COLOR_TRANSPARENT);
    // vrt should know where need to update automatically    
    //invalidate();

}

void CamcoOSDState::enterState(void* param)
{
    enableState(); 
    setFocused(VFX_TRUE);    
    m_autoExitTimer->m_signalTick.connect(this, &CamcoOSDState::onAutoExitTimerTick);    
    m_autoExitTimer->start();       
    m_isActive = VFX_TRUE;

    vapp_volume_dialog_block(MMI_TRUE);
};

void CamcoOSDState::exitState(void)
{
    disableState();
    setFocused(VFX_FALSE);        
    m_autoExitTimer->stop();    
    m_autoExitTimer->m_signalTick.disconnect(this, &CamcoOSDState::onAutoExitTimerTick);    
    m_isActive = VFX_FALSE;

    vapp_volume_dialog_block(MMI_FALSE);
};


VfxPoint CamcoOSDState::coordTransform2Vertical(VfxS32 x, VfxS32 y)
{
    return VfxPoint(GDI_LCD_WIDTH - y, x);
}

void CamcoOSDState::setAutoExitTimer(VfxTimer* t)
{
    m_autoExitTimer = t;
    m_autoExitTimer->setStartDelay(VAPP_CAMCO_OSD_AUTO_EXIT_TIME);
}

void CamcoOSDState::refreshAutoExitTimer(void)
{
    m_autoExitTimer->start();
}

void CamcoOSDState::onAutoExitTimerTick(VfxTimer *source)
{
    AutoExitTimoutProcess();
}

void CamcoOSDState::AutoExitTimoutProcess(void)
{
    evtHdlr->appGlobalEventHdlr(VAPP_CAMCO_EVT_AUTO_EXIT, NULL);        
}

VfxBool CamcoOSDState::onPenInput(VfxPenEvent & event)
{
    m_autoExitTimer->start();
        
    return VfxControl::onPenInput(event);
}

VfxBool CamcoOSDState::onKeyInput(VfxKeyEvent & event)
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

void CamcoOSDState::setHorz(VfxBool isHorz, VfxBool isMirror)
{
    m_isHorz = isHorz; 
    m_isMirror = isMirror;
    if(evtHdlr)
        rotateOSD(m_isHorz, m_isMirror);

    if(m_autoExitTimer->getIsEnabled())
        m_autoExitTimer->start();
};    

void CamcoOSDState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
}

void OSDStartingState::onInit(void)
{
    CamcoOSDState::onInit();
    m_state = VAPP_CAMCO_OSD_STATE_HIDE;    
};

void OSDStartingState::enterState(void* param)
{
    enableState();
    setFocused(VFX_TRUE);   

    setBgColor(VFX_COLOR_BLACK);
    
    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableImageFrame, this);   

    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);       
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableFrame, this);       
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableFrame, this);           
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);    
    VFX_OBJ_CREATE(m_usedSensor, VappCamcoCpRotatableImageButton, this); 
    VFX_OBJ_CREATE(m_unusedSensor, VappCamcoCpRotatableImageButton, this);           

    m_rightBar->setAnchor(0.5, 0.5);      
    m_rightBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));    
        
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON);
    m_gallery->setAnchor(0.5, 0.5);
    m_gallery->setImage(SI);
    m_gallery->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_gallery->setAutoAnimate(VFX_FALSE);
    m_gallery->setIsEffect(VFX_TRUE);
    m_gallery->setEffectSize(VfxSize(52, 52));        
    m_galleryContent->setIsUnhittable(VFX_TRUE);
    if(!((vapp_camco_osd_starting_param_struct*)param)->isExtCalling)    
        m_galleryContent->setBgColor(VFX_COLOR_BLACK);
    m_galleryContent->setAnchor(0.5, 0.5);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    if(!((vapp_camco_osd_starting_param_struct*)param)->isExtCalling)      
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContent->setHidden(VFX_FALSE);      
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);      
        m_galleryContent->setHidden(VFX_TRUE);      
    }  

    if(((vapp_camco_osd_starting_param_struct*)param)->isCamera)
        SI = VcpStateImage(IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON);   
    else
        SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON);   
    m_usedSensor->setAnchor(0.5, 0.5);
    m_usedSensor->setImage(SI);
    m_usedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_usedSensor->setAutoAnimate(VFX_FALSE);
    m_usedSensor->setIsEffect(VFX_TRUE);
    m_usedSensor->setEffectSize(VfxSize(110, 110));    

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR);
    m_unusedSensor->setAnchor(0.5, 0.5);
    m_unusedSensor->setImage(SI);
    m_unusedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);  
    m_unusedSensor->setAutoAnimate(VFX_FALSE);
    m_unusedSensor->setIsEffect(VFX_TRUE);
    m_unusedSensor->setEffectSize(VfxSize(52, 52));    
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);
#else
    m_unusedSensor->setHidden(VFX_TRUE);
#endif

    m_switcher->setAnchor(0.5, 0.5);
    if(((vapp_camco_osd_starting_param_struct*)param)->isCamera)
    {
        SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    }
    else
    {
        SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    }            
    m_switcher->setImage(SI);
    m_switcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);     
    m_switcher->setAutoAnimate(VFX_FALSE);
    m_switcher->setEffectSize(VfxSize(52, 52));   

    m_switcherRec->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC)); 
    m_switcherRec->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC).getSize());     
    m_switcherRec->setAnchor(0.5, 0.5);       
    m_switcherRec->setAutoAnimate(VFX_FALSE);
    m_switcherRec->setIsUnhittable(VFX_TRUE);

    m_switcherCam->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM));
    m_switcherCam->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM).getSize());     
    m_switcherCam->setAnchor(0.5, 0.5);    
    m_switcherCam->setAutoAnimate(VFX_FALSE);
    m_switcherCam->setIsUnhittable(VFX_TRUE);

    if(!((vapp_camco_osd_starting_param_struct*)param)->isExtCalling)      
    {
        m_switcher->setHidden(VFX_FALSE);      
        m_switcherRec->setHidden(VFX_FALSE);   
        m_switcherCam->setHidden(VFX_FALSE);           
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);        
        m_switcherRec->setHidden(VFX_TRUE);  
        m_switcherCam->setHidden(VFX_TRUE);          
    } 

    // layout    
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

    if(((vapp_camco_osd_starting_param_struct*)param)->isHorz)
    {
        setSize(LCD_HEIGHT, LCD_WIDTH);    
        
        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));               
        m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1);
        m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);

        m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);
        m_galleryContent->setPos(sp->galleryPos[0], sp->galleryPos[1]);
        m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
        m_unusedSensor->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);   
        m_switcher->setPos(sp->switchAppPos[0], sp->switchAppPos[1]);    
        m_switcherRec->setPos(m_switcher->getPos().x, m_switcher->getPos().y - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().height>>1));
        m_switcherCam->setPos(m_switcher->getPos().x, m_switcher->getPos().y + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().height>>1));

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_switcher->setTransform(t);        
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
 
        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));               
        m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1));
        m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
        
        m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
        m_galleryContent->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
        m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));    
        m_unusedSensor->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));   
        m_switcher->setPos(coordTransform2Vertical(sp->switchAppPos[0], sp->switchAppPos[1]));  
        m_switcherRec->setPos(m_switcher->getPos().x + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);
        m_switcherCam->setPos(m_switcher->getPos().x - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        m_switcher->setTransform(t);        
    }    

    VfxBool isEnvHorz = ((vapp_camco_osd_starting_param_struct*)param)->isHorz;
    VfxBool isCPHorz = ((vapp_camco_osd_starting_param_struct*)param)->isOSDHorz;
    VfxBool isMirror = ((vapp_camco_osd_starting_param_struct*)param)->isOSDMirror;
  
    m_gallery->setRot(isEnvHorz, isCPHorz, isMirror);
    m_galleryContent->setRot(isEnvHorz, isCPHorz, isMirror);
    m_usedSensor->setRot(isEnvHorz, isCPHorz, isMirror);
    m_unusedSensor->setRot(isEnvHorz, isCPHorz, isMirror);
    m_switcherRec->setRot(isEnvHorz, isCPHorz, isMirror);
    m_switcherCam->setRot(isEnvHorz, isCPHorz, isMirror);

};

void OSDStartingState::exitState(void)
{
    VFX_OBJ_CLOSE(m_rightBar);
    VFX_OBJ_CLOSE(m_switcher);
    VFX_OBJ_CLOSE(m_switcherRec);
    VFX_OBJ_CLOSE(m_switcherCam);
    VFX_OBJ_CLOSE(m_galleryContent);
    VFX_OBJ_CLOSE(m_gallery);
    VFX_OBJ_CLOSE(m_usedSensor);
    VFX_OBJ_CLOSE(m_unusedSensor);

    disableState();
    setFocused(VFX_FALSE);      
}

VfxBool OSDStartingState::onPenInput(VfxPenEvent & event)
{
    return VFX_TRUE;
}

VfxBool OSDStartingState::onKeyInput(VfxKeyEvent &event)
{
    return VFX_TRUE;
}

void OSDHideState::onInit(void)
{
    CamcoOSDState::onInit();
    m_state = VAPP_CAMCO_OSD_STATE_HIDE;    
};

void OSDHideState::enterState(void* param)
{
    ASSERT(param != NULL);
    enableState();
    setFocused(VFX_TRUE);   
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_hide_param_struct));
    setBgColor(VFX_COLOR_TRANSPARENT);
};


void OSDHinteState::onInit(void)
{
    CamcoOSDState::onInit();

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
#if defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(14);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
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
    m_IndicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON);
    m_IndicatorPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onBackClicked);
    m_IndicatorPopup->setAutoDestory(VFX_FALSE);   
    m_IndicatorPopup->setAutoAnimate(VFX_FALSE);   
    
    m_confirmPopup->setAnchor(0.5, 0.5);    
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);    
    m_confirmPopup->setAutoDestory(VFX_FALSE);    
    m_confirmPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onConfirmClicked);
    m_confirmPopup->setAutoAnimate(VFX_FALSE);

    m_notifyPopup->setAnchor(0.5, 0.5);    
    m_notifyPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    m_notifyPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);    
    m_notifyPopup->setAutoDestory(VFX_FALSE);    
    m_notifyPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onOkClicked);
    m_notifyPopup->setAutoAnimate(VFX_FALSE);

    m_background->setAnchor(0.5, 0.5);
    m_background->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));   
    m_background->setHidden(VFX_FALSE);        
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT); 

    m_icon->setAnchor(0.5, 0.5); 
    m_icon->setHidden(VFX_TRUE);           
    m_icon->setResId(MAIN_MENU_CAMCO_ICON);
    m_icon->setAutoAnimate(VFX_FALSE);
    
    m_state = VAPP_CAMCO_OSD_STATE_HINT;        
};

void OSDHinteState::enterState(void* param)
{
    ASSERT(param != NULL);

    CamcoOSDState::enterState(param);
     
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_hint_param_struct)); 

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
  
    if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING)
    {
        m_processingPopup->show(VFX_FALSE);    
    }
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_HINT)
    {
        m_IndicatorPopup->show(VFX_FALSE);
    }
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT)
    {
        m_hint->setHidden(VFX_FALSE);
    }    
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_HINT_ICON)
    {
        m_icon->setHidden(VFX_FALSE);
    }    
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM)        
    {
        m_confirmPopup->show(VFX_FALSE);    
        m_confirmPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onConfirmClicked);
    }              
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_NOTIFY)          
    {
        m_notifyPopup->show(VFX_FALSE);
    }        

    if(!m_cntx.isPreviewON)
        drawBase(m_cntx.bgContent);
    else
        clean(VFX_COLOR_TRANSPARENT);

    if(m_cntx.isFWHorz)
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

    rotateOSD(m_isHorz, m_isMirror);
};

void OSDHinteState::exitState(void)
{
    CamcoOSDState::exitState();
    m_hint->setHidden(VFX_TRUE);
    m_processingPopup->hide(VFX_FALSE);
    m_IndicatorPopup->hide(VFX_FALSE);
    m_confirmPopup->m_signalButtonClicked.disconnect(this, &OSDHinteState::onConfirmClicked);
    m_confirmPopup->hide(VFX_FALSE);   
    m_notifyPopup->hide(VFX_FALSE);   
}


void OSDHinteState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    // ============================================================
    // enable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {
        //m_hint->setAutoAnimate(VFX_TRUE);
        //m_processingPopup->setAutoAnimate(VFX_TRUE);
        //m_IndicatorPopup->setAutoAnimate(VFX_TRUE);
        //m_confirmPopup->setAutoAnimate(VFX_TRUE);
        //m_notifyPopup->setAutoAnimate(VFX_TRUE);
        //m_background->setAutoAnimate(VFX_TRUE);
        //m_icon->setAutoAnimate(VFX_TRUE);
    }    
    // ============================================================
    // enable autoanimation
    // ============================================================
    VfxTransform t;
    if(m_cntx.isFWHorz)
    {
        if(isHorz)
        {
            if(isMirror)
            {
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);            
            }
            else
            {           
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(0);            
            }
            // triger auto resize font, string need to be set after size is fixed
            m_hint->setBounds(VfxRect(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH));   
        }
        else
        {
            if(isMirror)
            {
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-270);            
            }
            else
            {                   
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);
            }
            // triger auto resize font, string need to be set after size is fixed
            m_hint->setBounds(VfxRect(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT));               
        }
    }
    else
    {
        if(isHorz)
        {
            if(isMirror)
            {
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);            
            }
            else
            {                   
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(90);
            }
            // triger auto resize font, string need to be set after size is fixed
            m_hint->setBounds(VfxRect(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH));   
        }
        else
        {
            if(isMirror)
            {
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);            
            }
            else
            {                   
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(0);
            }
            // triger auto resize font            
            m_hint->setBounds(VfxRect(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT));   
        }    
    }
    m_hint->setTransform(t);    
    m_processingPopup->setTransform(t);    
    m_IndicatorPopup->setTransform(t);    
    m_confirmPopup->setTransform(t);    
    m_notifyPopup->setTransform(t);    
    m_background->setTransform(t);    
    m_icon->setTransform(t);    

    // ============================================================
    // disable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        //m_hint->setAutoAnimate(VFX_FALSE);
        //m_processingPopup->setAutoAnimate(VFX_FALSE);
        //m_IndicatorPopup->setAutoAnimate(VFX_FALSE);
        //m_confirmPopup->setAutoAnimate(VFX_FALSE);
        //m_notifyPopup->setAutoAnimate(VFX_FALSE);
        //m_background->setAutoAnimate(VFX_FALSE);
        //m_icon->setAutoAnimate(VFX_FALSE);
    }
    // ============================================================
    // disable autoanimation
    // ============================================================
    
#endif
}

void OSDHinteState::onOkClicked(VfxObject *obj, VfxId id)
{
    if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_ERROR)
    {
        evtHdlr->errorPopupHdlr(VAPP_CAMCO_EVT_OK, NULL);    
    }
}

void OSDHinteState::onBackClicked(VfxObject *obj, VfxId id)
{
    if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_CAM_COUNT_DOWN)            
        evtHdlr->camCountdownHdlr(VAPP_CAMCO_EVT_BACK, NULL);  
    else if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_CAM_HDR_PROCESSING)            
        evtHdlr->camHDRShotHdlr(VAPP_CAMCO_EVT_BACK, NULL);         
}

void OSDHinteState::onConfirmClicked(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        m_cntx.setting->needRestartPreview();
        if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD)
        {
            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV));
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_OK, NULL);
        }
        else if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD)
        {
            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV));        
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_OK, NULL);            
        }        
    }
    else
    {
        if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD)
        {
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CANCEL, NULL);
        }
        else if(m_cntx.event == VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD)
        {
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_CANCEL, NULL);
        }        
    }        
}

void OSDHinteState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_FILE)
    {
        m_background->setPath(VfxWString().loadFromMem(param.srcFileName));            
    }            
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)param.srcBuffAdress;
        imageBuf.pitchBytes = param.srcWidth * 2;
        imageBuf.width = param.srcWidth;
        imageBuf.height = param.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        m_background->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_JPEG)
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
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_COLOR)        
    {
        setBgColor(param.bgColor);
    }
    else
    {
        ASSERT(0);
    }
    m_background->invalidate();

};  

void OSDHinteState::setHint(VfxWString hint)
{
    m_hint->setString(hint);   
    m_hint->setHidden(VFX_FALSE);
        
};

void OSDCamPreviewState::onInit(void)
{
    CamcoOSDState::onInit();

    // create UI   
    for(VfxU8 i = 0; i < 4; i++)
    {            
        VFX_OBJ_CREATE(m_auxiliary[i], VappCamcoCpRotatableFrame, this);                
    }
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_faceDetectRegion[i], VappCamcoCpRect, this);     
        VFX_OBJ_CREATE(m_smileDetectRegion[i], VappCamcoCpRect, this);          
    }      
    VFX_OBJ_CREATE(m_imageFrame, VappCamcoCpRotatableImageFrame, this);                  
    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableImageFrame, this);   
    
    VFX_OBJ_CREATE(m_zoomer, VappCamcoCpSlider, this);           
    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);  
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableFrame, this);       
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableFrame, this);           
    VFX_OBJ_CREATE(m_galleryContainer, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);     
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, m_galleryContainer);            
    VFX_OBJ_CREATE(m_usedSensor, VappCamcoCpRotatableButton, this);
    VFX_OBJ_CREATE(m_unusedSensor, VappCamcoCpRotatableImageButton, this);           

    VFX_OBJ_CREATE(m_indicatorMsgBg, VappCamcoCpRotatableImageFrame, this);   

    VFX_OBJ_CREATE(m_capturableNumber, VappCamcoCpRotatableTextFrame, this);   
    VFX_OBJ_CREATE(m_indicatorMsg, VappCamcoCpRotatableTextFrame, this);     

    VFX_OBJ_CREATE(m_coverFrame, VappCamcoCpRotatableFrame, this);    

    VFX_OBJ_CREATE(m_settingBar, VappCamcoCpBaseMenu, this);   
    VFX_OBJ_CREATE(m_directSettingControl, VappCamcoCpCircleMenu, this);   
    VFX_OBJ_CREATE(m_advanceSettingControl, VappCamcoCpAdvanceMenu, this);            

    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        VFX_OBJ_CREATE(m_statusInd[i], VappCamcoCpRotatableImageFrame, this);              
    }
    for(VfxU8 i = 0; i < VAPP_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        VFX_OBJ_CREATE(m_focusRegion[i], VappCamcoCpRect, this);
        m_focusRegion[i]->setAnchor(0.5, 0.5);
    }
    VFX_OBJ_CREATE(m_indicatorImage, VfxImageFrame, this);
    m_indicatorImage->setAnchor(0.5, 0.5);
    m_indicatorImage->setResId(IMG_ID_VAPP_CAMCO_STATUS_AF_MACRO_ICON);
    m_indicatorImage->setAutoAnimate(VFX_FALSE);
    m_indicatorImage->setHidden(VFX_TRUE);
    m_confirmPopup = NULL;

    // init UI
    for(VfxU8 i = 0; i < 4; i++)
    {            
        m_auxiliary[i]->setAnchor(0.5, 0.5);                
        m_auxiliary[i]->setBgColor(VFX_COLOR_GREEN);                        
        m_auxiliary[i]->setHidden(VFX_TRUE);
    }

    m_imageFrame->setAnchor(0.5, 0.5);  
    m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);
    m_imageFrame->setAutoAnimate(VFX_FALSE);

    m_rightBar->setAnchor(0.5, 0.5);      
    m_rightBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));    
        
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON);
    m_gallery->setAnchor(0.5, 0.5);
    m_gallery->setImage(SI);
    m_gallery->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_gallery->setAutoAnimate(VFX_FALSE);
    m_gallery->setIsEffect(VFX_TRUE);
    m_gallery->setEffectSize(VfxSize(52, 52)); 
    m_galleryContainer->setAnchor(0.5, 0.5);
    m_galleryContainer->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);        
    m_galleryContent->setIsUnhittable(VFX_TRUE);
    m_galleryContent->setBorderColor(VFX_COLOR_BLACK);
    m_galleryContent->setBorderWidth(0);
    m_galleryContent->setAnchor(0.5, 0.5);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_galleryContent->setPos(m_galleryContainer->getSize().width>>1, m_galleryContainer->getSize().height>>1);

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON);   
    m_usedSensor->setAnchor(0.5, 0.5);
    m_usedSensor->setImage(SI);
    m_usedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_usedSensor->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_usedSensor->setMargin(0, 0, 0, 0);
    m_usedSensor->setBgColor(VFX_COLOR_TRANSPARENT);
    m_usedSensor->setBgImageList(VcpStateImage(0));
    m_usedSensor->setAutoAnimate(VFX_FALSE);
    m_usedSensor->setFuzzy(VFX_TRUE);

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR);
    m_unusedSensor->setAnchor(0.5, 0.5);
    m_unusedSensor->setImage(SI);
    m_unusedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);  
    m_unusedSensor->setAutoAnimate(VFX_FALSE);
    m_unusedSensor->setIsEffect(VFX_TRUE);
    m_unusedSensor->setEffectSize(VfxSize(52, 52));    

    m_switcher->setAnchor(0.5, 0.5);
    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setImage(SI);
    m_switcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);     
    m_switcher->setAutoAnimate(VFX_FALSE);
    m_switcher->setEffectSize(VfxSize(52, 52));   
       
    m_switcherRec->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC));
    m_switcherRec->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC).getSize());     
    m_switcherRec->setAnchor(0.5, 0.5);       
    m_switcherRec->setAutoAnimate(VFX_FALSE);
    m_switcherRec->setIsUnhittable(VFX_TRUE);

    m_switcherCam->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM)); 
    m_switcherCam->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM).getSize());     
    m_switcherCam->setAnchor(0.5, 0.5);    
    m_switcherCam->setAutoAnimate(VFX_FALSE);
    m_switcherCam->setIsUnhittable(VFX_TRUE);

    m_zoomer->setCpImage(VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IND_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_BAR_ICON));
    m_zoomer->setAnchor(0.5, 0.5);    
    m_zoomer->setValueRange(0, 100);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setCurveR(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_coverFrame->setAnchor(0.5, 0.5);    
    m_coverFrame->setOpacity(0.5);
    m_coverFrame->setBgColor(VFX_COLOR_BLACK);

    m_settingBar->setFocused(VFX_TRUE);    
    m_settingBar->setAutoAnimate(VFX_FALSE);           
    m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL, VfxSize(0, 0));      
  
    m_directSettingControl->setAnchor(0, 0.5);
    m_directSettingControl->setAutoAnimate(VFX_FALSE);
    m_directSettingControl->setBgColor(VRT_COLOR_TRANSPARENT);
    m_directSettingControl->setFocused(VFX_TRUE);  

    m_advanceSettingControl->setAnchor(0, 0.5);
    m_advanceSettingControl->setAutoAnimate(VFX_FALSE);                
    m_advanceSettingControl->setBgColor(VRT_COLOR_TRANSPARENT);
    m_advanceSettingControl->setFocused(VFX_TRUE);   

    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        m_statusInd[i]->setAnchor(0.5, 0.5);
        m_statusInd[i]->setAutoAnimate(VFX_FALSE);            
    }      
    
    m_facedetect.isTracking = VFX_FALSE;
    m_facedetect.focusedColor = VfxColor(255, 0, 255, 0);
    m_facedetect.focusedBorderColor = VfxColor(255, 0, 0, 0);
    m_facedetect.trackingColor = VfxColor(255, 240, 228, 15);
    m_facedetect.trackingBorderColor = VfxColor(255, 240, 228, 15);
    m_facedetect.opacity = 200;

    m_smiledetect.isTracking = VFX_FALSE;
    m_smiledetect.focusedColor = VfxColor(255, 255, 128, 0);
    m_smiledetect.focusedBorderColor = VfxColor(255, 0, 0, 0);
    m_smiledetect.trackingColor = VfxColor(255, 255, 128, 15);
    m_smiledetect.trackingBorderColor = VfxColor(255, 240, 228, 15);
    m_smiledetect.opacity = 200;    

    VfxFontDesc font;    
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)    
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(25);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#else
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#endif
    font.effect = VFX_FE5_1;
    m_capturableNumber->setFont(font);   
    m_capturableNumber->setAnchor(0.5, 0.5);
    m_capturableNumber->setAutoAnimate(VFX_FALSE);
    m_capturableNumber->setColor(VFX_COLOR_WHITE);
    m_capturableNumber->setOpacity(0.8);

    m_indicatorMsg->setAnchor(0.5, 0.5);
    m_indicatorMsg->setAutoAnimate(VFX_FALSE);
    m_indicatorMsg->setColor(VFX_COLOR_WHITE);    
    m_indicatorMsg->setOpacity(0.8);

    m_indicatorMsgBg->setAnchor(0.5, 0.5);
    m_indicatorMsgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_indicatorMsgBg->setResId(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON);  

    m_state = VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW;     

    m_isdelaySD = VFX_FALSE;
    m_isdelayRestartPreview = VFX_FALSE;

    m_isClicking = VFX_FALSE;

    setAutoAnimate(VFX_FALSE);

    // Create an timer
    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_fadeOutScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_postProcessTimer, VfxTimer, this);            
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);                
   
    // set action handler
    m_settingBar->m_signalEnterEffectStart.connect(this, &OSDCamPreviewState::onBeforeSettingEnter);        
    m_settingBar->m_signalItemSelected.connect(this, &OSDCamPreviewState::onSettingEnter);
    m_settingBar->m_signalMenuMoved.connect(this, &OSDCamPreviewState::onSettingTraverse);     
    m_settingBar->m_signalLeaveEffectDone.connect(this, &OSDCamPreviewState::onCPEffctDoneTick2);     
    m_directSettingControl->m_signalClicked.connect(this, &OSDCamPreviewState::onDirectSettingLeave);    
    m_directSettingControl->m_signalItemSet.connect(this, &OSDCamPreviewState::onSettingSet);               
    m_directSettingControl->m_signalLeaveEffectDone.connect(this, &OSDCamPreviewState::onCPEffctDoneTick);           
    m_advanceSettingControl->m_signalClicked.connect(this, &OSDCamPreviewState::onAdvanceSettingLeave);
    m_advanceSettingControl->m_signalTraversed.connect(this, &OSDCamPreviewState::onAdvanceSettingTraverse);    
    m_advanceSettingControl->m_signalItemSelected.connect(this, &OSDCamPreviewState::onAdvanceSettingSelected);       
    m_advanceSettingControl->m_signalLeaveEffectDone.connect(this, &OSDCamPreviewState::onCPEffctDoneTick);       
        
    m_switcher->m_signalClicked.connect(this, &OSDCamPreviewState::onSwitchAppClicked);  
    m_gallery->m_signalClicked.connect(this, &OSDCamPreviewState::onGalleryClicked);   
    m_unusedSensor->m_signalClicked.connect(this, &OSDCamPreviewState::onSwitchSensorClicked);   
    m_usedSensor->m_signalStateChanged.connect(this, &OSDCamPreviewState::onCaptured);
    m_usedSensor->m_signalClicked.connect(this, &OSDCamPreviewState::onCaptureClicked);
    m_zoomer->m_signalValueChanged.connect(this, &OSDCamPreviewState::onZooming);

    m_resetScreenTimer->m_signalTick.connect(this, &OSDCamPreviewState::onResetTimerTick);
    m_fadeOutScreenTimer->m_signalTick.connect(this, &OSDCamPreviewState::setClearModeinternal);    
    m_postProcessTimer->m_signalTick.connect(this, &OSDCamPreviewState::onPostProcessTimerTick);  

};


void OSDCamPreviewState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_cam_preview_param_struct));

    cleanFaceDetect();
    cleanSmileDetect();    

    // updat UI depend setting
    updateSettingBar(0);

    updateIcon();

    updateRemainSizeParam(m_cntx.capturableNumber);

    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));  
    
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height);
        
    m_zoomer->setValueRange(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM), m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));
    // cannot zoom
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)  
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    m_imageFrame->setPos(m_cntx.previewWindow.getX(), m_cntx.previewWindow.getY());
    m_imageFrame->setSize(m_cntx.previewWindow.getWidth(), m_cntx.previewWindow.getHeight());
    m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);
    m_imageFrame->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_ADDFRAME_FRAME)));
    m_hiliteFrameIdx = m_cntx.setting->getValue(VAPP_CAMCO_SETTING_ADDFRAME_FRAME);

    if(!m_cntx.setting->IsExtSetting())
    {
        if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);        
            m_galleryContent->setImgContent(VfxImageSrc(VFX_WSTR_MEM(m_cntx.previousFileName)));
        }
        else
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
        }
    }
    m_resetScreenTimer->setStartDelay(CAMCO_CAM_PREVIEW_RESET_TIME);
    m_fadeOutScreenTimer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT || 
       m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_ENTER_SMILEDETECT, NULL);         
    }
    else
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_LEAVE_SMILEDETECT, NULL);                 
    }

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_START_SCN_DETECT, NULL);         
    }
    else
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_STOP_SCN_DETECT, NULL);                 
    }    
    
#ifndef __VAPP_CAMCO_ROTATABLE_UI__    
    if(m_CurrentCapmode != VAPP_CAMCO_CAPMODE_ADD_FRAME && 
       m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CAMCO_NOTIFY_ADDFRAME_IS_ACTIVE));    
    }
#endif    

    if(m_cntx.isCleanModeEnter)   
    {
        setClearModeinternal(NULL);
    }        
    else
    {
        setNormalMode();
        m_resetScreenTimer->start();
    }            

    if(m_confirmPopup != NULL)
        VFX_OBJ_CLOSE(m_confirmPopup);            
};

void OSDCamPreviewState::exitState(void)
{
    CamcoOSDState::exitState();

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_ADSETTING;        
    }
    else
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;    
    }    
    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;
    
    m_resetScreenTimer->stop();
    m_zoomingTimer->stop();        
    VFX_OBJ_CLOSE(m_confirmPopup);  

    m_usedSensor->setOpacity(1);
}

void OSDCamPreviewState::cleanFaceDetect(void)
{
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        m_facedetect.trackingRegion[i].type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_NULL;
        m_faceDetectRegion[i]->setSize(0, 0);
    }  

};

void OSDCamPreviewState::cleanSmileDetect(void)
{
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        m_smiledetect.trackingRegion[i].type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_NULL;
        m_smileDetectRegion[i]->setSize(0, 0);
    }  

};


void OSDCamPreviewState::setFaceDetect(VfxU32 idx, vapp_camco_osd_facedetect_region_struct region)
{
    memcpy(&m_facedetect.trackingRegion[idx], &region, sizeof(vapp_camco_osd_facedetect_region_struct)); 
    if(m_facedetect.trackingRegion[idx].type == VAPP_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
        m_faceDetectRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_FD, VAPP_CAMCO_CP_RECT_MODE_NORMAL);
    else if(m_facedetect.trackingRegion[idx].type == VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
        m_faceDetectRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_FD, VAPP_CAMCO_CP_RECT_MODE_SUCCESS);

    m_faceDetectRegion[idx]->setSize(m_facedetect.trackingRegion[idx].w, m_facedetect.trackingRegion[idx].h);
    m_faceDetectRegion[idx]->setPos(m_facedetect.trackingRegion[idx].x, m_facedetect.trackingRegion[idx].y);

};

void OSDCamPreviewState::setSmileDetect(VfxU32 idx, vapp_camco_osd_smiledetect_region_struct region)
{  
    memcpy(&m_smiledetect.trackingRegion[idx], &region, sizeof(vapp_camco_osd_smiledetect_region_struct)); 
    if(m_smiledetect.trackingRegion[idx].type == VAPP_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
        m_smileDetectRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_SD, VAPP_CAMCO_CP_RECT_MODE_NORMAL);
    else if(m_smiledetect.trackingRegion[idx].type == VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
        m_smileDetectRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_SD, VAPP_CAMCO_CP_RECT_MODE_SUCCESS);

    m_smileDetectRegion[idx]->setSize(m_smiledetect.trackingRegion[idx].w, m_smiledetect.trackingRegion[idx].h);
    m_smileDetectRegion[idx]->setPos(m_smiledetect.trackingRegion[idx].x, m_smiledetect.trackingRegion[idx].y);

};    

void OSDCamPreviewState::cleanFocus(void)
{
    for(VfxU8 i = 0; i < VAPP_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        m_focusRegion[i]->setSize(0, 0);
    }
    m_indicatorImage->setHidden(VFX_TRUE);
}
void OSDCamPreviewState::setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region)
{
    if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_NORMAL);
    else if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSED)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_SUCCESS);
    else if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_FAIL);
    if(region.type != VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO)
    {
        m_focusRegion[idx]->setSize(region.w, region.h);
        m_focusRegion[idx]->setPos(region.center_x, region.center_y);
        m_indicatorImage->setHidden(VFX_TRUE);
    }
    else
    {
        if(m_isHorz)
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
void OSDCamPreviewState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    // we dont do rotation when in advance setting
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;
    
    // ============================================================
    // enable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        m_settingBar->setAutoAnimate(VFX_TRUE);
        
        m_directSettingControl->setAutoAnimate(VFX_TRUE);
        m_advanceSettingControl->setAutoAnimate(VFX_TRUE);
        m_switcherRec->setAutoAnimate(VFX_TRUE);
        m_switcherCam->setAutoAnimate(VFX_TRUE);        
        m_zoomer->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_TRUE);
        m_galleryContent->setAutoAnimate(VFX_TRUE);

        m_usedSensor->setAutoAnimate(VFX_TRUE);
        m_unusedSensor->setAutoAnimate(VFX_TRUE);

        //m_rightBar->setAutoAnimate(VFX_TRUE);
        
        //m_imageFrame->setAutoAnimate(VFX_TRUE);

        for(VfxU32 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
        {
            m_statusInd[i]->setAutoAnimate(VFX_TRUE);
        }
        
        for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
        {    
            //m_faceDetectRegion[i]->setAutoAnimate(VFX_TRUE);
            //m_smileDetectRegion[i]->setAutoAnimate(VFX_TRUE);
        }
        m_capturableNumber->setAutoAnimate(VFX_TRUE);

        m_indicatorMsg->setAutoAnimate(VFX_TRUE);
        m_indicatorMsgBg->setAutoAnimate(VFX_TRUE);
    }    
    // ============================================================
    // enable autoanimation
    // ============================================================

    m_settingBar->setRot(isHorzUI(), isHorz, isMirror);  
    
    m_directSettingControl->setRot(isHorzUI(), isHorz, isMirror);  
    m_advanceSettingControl->setRot(isHorzUI(), isHorz, isMirror);  
    m_switcherRec->setRot(isHorzUI(), isHorz, isMirror);
    m_switcherCam->setRot(isHorzUI(), isHorz, isMirror);    
    m_zoomer->setRot(isHorzUI(), isHorz, isMirror);  

    //m_gallery->setRot(isHorzUI(), isHorz, isMirror);  
    if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setRot(isHorzUI(), isHorz, isMirror);  
    }
    
    m_usedSensor->setRot(isHorzUI(), isHorz, isMirror);  
    m_unusedSensor->setRot(isHorzUI(), isHorz, isMirror);  

    //m_rightBar->setRot(isHorzUI(), isHorz, isMirror);

    if(isHorzUI() == isHorz)
        m_imageFrame->setRot(isHorzUI(), isHorz, isMirror);
    else
        m_imageFrame->setRot(isHorzUI(), isHorzUI(), VFX_FALSE);

    for(VfxU32 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        m_statusInd[i]->setRot(isHorzUI(), isHorz, isMirror);
    }
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        //m_faceDetectRegion[i]->setRot(isHorzUI(), isHorz, isMirror);
        //m_smileDetectRegion[i]->setRot(isHorzUI(), isHorz, isMirror);
    }
    m_capturableNumber->setRot(isHorzUI(), isHorz, isMirror);

    m_indicatorMsg->setRot(isHorzUI(), isHorz, isMirror);
    m_indicatorMsgBg->setRot(isHorzUI(), isHorz, isMirror);

    // ============================================================
    // disable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        m_settingBar->setAutoAnimate(VFX_FALSE);

        m_directSettingControl->setAutoAnimate(VFX_FALSE);
        m_advanceSettingControl->setAutoAnimate(VFX_FALSE);
        m_switcherRec->setAutoAnimate(VFX_FALSE);
        m_switcherCam->setAutoAnimate(VFX_FALSE);    
        m_zoomer->setAutoAnimate(VFX_FALSE);

        m_gallery->setAutoAnimate(VFX_FALSE);
        m_galleryContent->setAutoAnimate(VFX_FALSE);

        m_usedSensor->setAutoAnimate(VFX_FALSE);
        m_unusedSensor->setAutoAnimate(VFX_FALSE);

        //m_rightBar->setAutoAnimate(VFX_FALSE);

        //m_imageFrame->setAutoAnimate(VFX_FALSE);

        for(VfxU32 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
        {
            m_statusInd[i]->setAutoAnimate(VFX_FALSE);
        }

        for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
        {    
            //m_faceDetectRegion[i]->setAutoAnimate(VFX_FALSE);
            //m_smileDetectRegion[i]->setAutoAnimate(VFX_FALSE);
        }
        m_capturableNumber->setAutoAnimate(VFX_FALSE);

        m_indicatorMsg->setAutoAnimate(VFX_FALSE);
        m_indicatorMsgBg->setAutoAnimate(VFX_FALSE);
    }
    // ============================================================
    // disable autoanimation
    // ============================================================
    
#endif
}


void OSDCamPreviewState::updateZoomParam(VfxU32 v)
{
    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, v);
    m_zoomer->setCurrentValue(v);
}

void OSDCamPreviewState::updateRemainSizeParam(VfxU32 v)
{
    if(v > 999)
        v = 999;
    
    VfxWChar caption[10] = {0};
    kal_wsprintf(caption, "%d", v);
    m_capturableNumber->setString(VFX_WSTR_MEM(caption));
}

void OSDCamPreviewState::updateIndicatorMsg(VfxU32 s)
{
    m_cntx.indicatorStringID = s;
    
    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));   
    
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height);

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
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


void OSDCamPreviewState::updateScnIcon(void)
{
    updateIcon();
}

void OSDCamPreviewState::enterSmileDetect(void)
{
    setSmileDetectMode();
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_START_SMILEDETECT, NULL);
    m_isFocussing = VFX_FALSE;
    m_autoExitTimer->stop();
    m_resetScreenTimer->stop();
}

void OSDCamPreviewState::setNormalMode(void)
{
    if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL || m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_COMMON_ONLY)
        m_settingBar->setHidden(VFX_FALSE);  
    else
        m_settingBar->setHidden(VFX_TRUE);          
    
    m_directSettingControl->setHidden(VFX_TRUE);             
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

    m_coverFrame->setHidden(VFX_TRUE);

    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);         
        m_switcherRec->setHidden(VFX_FALSE);  
        m_switcherCam->setHidden(VFX_FALSE);          
    }        
    else
    {
        m_switcher->setHidden(VFX_TRUE);                 
        m_switcherRec->setHidden(VFX_TRUE);  
        m_switcherCam->setHidden(VFX_TRUE);          
    }
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) != 1)  
        m_zoomer->setHidden(VFX_FALSE);             
    else
        m_zoomer->setHidden(VFX_TRUE);                     
    
    if(!m_cntx.setting->IsExtSetting())    
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContainer->setHidden(VFX_FALSE);
    }        
    else
    {
        m_gallery->setHidden(VFX_TRUE);              
        m_galleryContainer->setHidden(VFX_TRUE);
    }
    m_usedSensor->setHidden(VFX_FALSE);   
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif
    m_rightBar->setHidden(VFX_FALSE);
    
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        m_imageFrame->setHidden(VFX_FALSE);               
    else
        m_imageFrame->setHidden(VFX_TRUE);       


    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_FLASH) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {  
        m_statusInd[0]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[0]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {      
        m_statusInd[1]->setHidden(VFX_FALSE);        
    }    
    else
    {  
        m_statusInd[1]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED ||
       m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
    {     
        m_statusInd[2]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[2]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMEV) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[3]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[3]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_AFMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[4]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[4]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[5]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[5]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_SELFTIMER) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[6]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[6]->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_ISO) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[7]->setHidden(VFX_FALSE);        
    }
    else
    {  
        m_statusInd[7]->setHidden(VFX_TRUE);        
    }    
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        m_faceDetectRegion[i]->setHidden(VFX_FALSE);      
        m_smileDetectRegion[i]->setHidden(VFX_FALSE);      
    }
    m_capturableNumber->setHidden(VFX_FALSE);
    
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

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    rotateOSD(m_isHorz, m_isMirror);

}

void OSDCamPreviewState::setClearMode(void)
{
    m_previousMode = m_mode;
    m_mode = VAPP_CAMCO_PREVIEW_MODE_TRANSITION;

    VfxAutoAnimate::begin();    
        VfxAutoAnimate::setDuration(1500);
        layout();    
    VfxAutoAnimate::commit();


    m_fadeOutScreenTimer->start();   
    
}

void OSDCamPreviewState::setClearModeinternal(VfxTimer *source)
{

    m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_TRUE);     
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

    m_coverFrame->setHidden(VFX_TRUE);

    if(!m_cntx.setting->IsExtSetting())    
    {
        m_switcher->setHidden(VFX_FALSE);         
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);   
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);
    }        
    m_zoomer->setHidden(VFX_TRUE);             

    if(!m_cntx.setting->IsExtSetting())    
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContainer->setHidden(VFX_FALSE);
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);      
        m_galleryContainer->setHidden(VFX_TRUE);      
    }     
    
    m_usedSensor->setHidden(VFX_FALSE);      
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif

    m_rightBar->setHidden(VFX_FALSE);

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        m_imageFrame->setHidden(VFX_FALSE);               
    else
        m_imageFrame->setHidden(VFX_TRUE);   
    
    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }

#ifdef __VAPP_CAMCO_ASD_ALWAYS_SHOW_ICON__
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)            
    {
        m_statusInd[2]->setHidden(VFX_FALSE);        
    }
#endif     
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        m_faceDetectRegion[i]->setHidden(VFX_FALSE);      
        m_smileDetectRegion[i]->setHidden(VFX_FALSE);      
    }

    m_capturableNumber->setHidden(VFX_TRUE);

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

    m_mode = VAPP_CAMCO_PREVIEW_MODE_CLEAR;

    if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_CLEAR;
        m_cntx.setting->needRestartPreview();        
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL);       
    }

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();         
    m_settingBar->setFocusOnCenter();

    rotateOSD(m_isHorz, m_isMirror);

}

void OSDCamPreviewState::setAdvanceSettingMode(void)
{

    m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_TRUE);             
    m_advanceSettingControl->setHidden(VFX_FALSE);                  

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    m_coverFrame->setHidden(VFX_FALSE);
#else    
    m_coverFrame->setHidden(VFX_TRUE);
#endif
    
    m_switcher->setHidden(VFX_TRUE);  
    m_switcherRec->setHidden(VFX_TRUE);  
    m_switcherCam->setHidden(VFX_TRUE);  
    m_zoomer->setHidden(VFX_TRUE);             
    
    m_gallery->setHidden(VFX_TRUE);    
    m_galleryContainer->setHidden(VFX_TRUE);        
    m_usedSensor->setHidden(VFX_TRUE);      
    m_unusedSensor->setHidden(VFX_TRUE);     

    m_rightBar->setHidden(VFX_TRUE);
    
    m_imageFrame->setHidden(VFX_TRUE);       

    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        m_faceDetectRegion[i]->setHidden(VFX_TRUE);      
        m_smileDetectRegion[i]->setHidden(VFX_TRUE);      
    }
    m_capturableNumber->setHidden(VFX_TRUE);
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);          
    
    m_mode = VAPP_CAMCO_PREVIEW_MODE_ADSETTING;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    rotateOSD(m_isHorz, m_isMirror);

}
    
void OSDCamPreviewState::setDirectSettingMode(VfxObject * target)
{
    m_previousModeDirSettingObj = target;

    m_settingBar->setHidden(VFX_TRUE);     
    m_directSettingControl->setHidden(VFX_FALSE);             
    m_advanceSettingControl->setHidden(VFX_TRUE);      

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    m_coverFrame->setHidden(VFX_FALSE);
#else    
    m_coverFrame->setHidden(VFX_TRUE);
#endif
    
    m_rightBar->setHidden(VFX_FALSE);

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        m_imageFrame->setHidden(VFX_FALSE);               
    else
        m_imageFrame->setHidden(VFX_TRUE);    

    
    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);         
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);    
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);
    }     
    
    m_zoomer->setHidden(VFX_TRUE);             
    
    if(!m_cntx.setting->IsExtSetting())    
    {
        m_gallery->setHidden((VFX_FALSE));      
        m_galleryContainer->setHidden(VFX_FALSE);      
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);  
        m_galleryContainer->setHidden(VFX_TRUE);  
    }
    
    m_usedSensor->setHidden(VFX_FALSE);      
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif

    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        m_faceDetectRegion[i]->setHidden(VFX_TRUE);      
        m_smileDetectRegion[i]->setHidden(VFX_TRUE);      
    }

#if defined(VAPP_CAMCO_OSD_LAYOUT_QVGA) || defined (VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    m_capturableNumber->setHidden(VFX_TRUE);   
#else
    m_capturableNumber->setHidden(VFX_FALSE);
#endif    
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);          

    m_mode = VAPP_CAMCO_PREVIEW_MODE_DIRSETTING;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    rotateOSD(m_isHorz, m_isMirror);

}

void OSDCamPreviewState::setSmileDetectMode(void)
{

    m_settingBar->setHidden(VFX_TRUE);   
    m_directSettingControl->setHidden(VFX_TRUE);             
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

    m_coverFrame->setHidden(VFX_TRUE);

    m_switcher->setHidden(VFX_TRUE);  
    m_switcherRec->setHidden(VFX_TRUE);
    m_switcherCam->setHidden(VFX_TRUE);
    m_zoomer->setHidden(VFX_TRUE);             
    
    m_gallery->setHidden(VFX_TRUE);   
    m_galleryContainer->setHidden(VFX_TRUE);   
    m_usedSensor->setHidden(VFX_FALSE);      
    m_unusedSensor->setHidden(VFX_TRUE);     

    m_rightBar->setHidden(VFX_TRUE);

    m_imageFrame->setHidden(VFX_TRUE);       

    for(VfxU8 i = 0; i < CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }
    // this is capmode status icon
    m_statusInd[1]->setHidden(VFX_FALSE);        
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        m_faceDetectRegion[i]->setHidden(VFX_FALSE);      
        m_smileDetectRegion[i]->setHidden(VFX_FALSE);      
    }
    
    m_capturableNumber->setHidden(VFX_TRUE);
    m_indicatorMsg->setHidden(VFX_TRUE);

    m_mode = VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    rotateOSD(m_isHorz, m_isMirror);

}
    
void OSDCamPreviewState::layout(void)
{
     vapp_camco_osd_skin *sp = &g_vapp_camco_skin;
     
    if(isHorzUI())
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || 
           m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || 
           m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING ||
           m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT ||
           m_mode == VAPP_CAMCO_PREVIEW_MODE_FRAME_SELECT)
        {            
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));               
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1);
            m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_unusedSensor->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);   
            m_switcher->setPos(sp->switchAppPos[0], sp->switchAppPos[1]);    
            m_switcherRec->setPos(m_switcher->getPos().x, m_switcher->getPos().y - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().height>>1));
            m_switcherCam->setPos(m_switcher->getPos().x, m_switcher->getPos().y + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().height>>1));            
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(1);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            m_coverFrame->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL, VfxSize(sp->settingBarSize[0],sp->settingBarSize[1]));

            m_directSettingControl->setVerticalMode(VFX_TRUE);   
            m_directSettingControl->setAnchor(0, 0.5);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[0],sp->circleControlSize[1]);    
            m_directSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_capturableNumber->setPos(g_vapp_camco_skin.remainNuminfoHPos[0], g_vapp_camco_skin.remainNuminfoHPos[1]);
            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());            
            
            m_statusInd[0]->setPos(sp->statusIconPos[0][0],  sp->statusIconPos[0][1]);
            m_statusInd[1]->setPos(sp->statusIconPos[1][0],  sp->statusIconPos[1][1]);
            m_statusInd[2]->setPos(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]);
            m_statusInd[3]->setPos(sp->statusIconPos[3][0],  sp->statusIconPos[3][1]);    
            m_statusInd[4]->setPos(sp->statusIconPos[4][0],  sp->statusIconPos[4][1]);
            m_statusInd[5]->setPos(sp->statusIconPos[5][0],  sp->statusIconPos[5][1]);
            m_statusInd[6]->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
            m_statusInd[7]->setPos(sp->statusIconPos[7][0],  sp->statusIconPos[7][1]);   

            updateAuxiliary();

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
            
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR || m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));              
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1);
            m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);    
            m_galleryContainer->setPos(m_gallery->getPos());    
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_unusedSensor->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);   
            m_switcher->setPos(sp->switchAppPos[0], sp->switchAppPos[1]);    
            m_switcherRec->setPos(m_switcher->getPos().x, m_switcher->getPos().y - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().height>>1));
            m_switcherCam->setPos(m_switcher->getPos().x, m_switcher->getPos().y + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().height>>1));            
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(0);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            m_coverFrame->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0 - CAMCO_CAM_PREVIEW_SHIFT_DIS, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL, VfxSize(sp->settingBarSize[0],sp->settingBarSize[1])); 

            m_directSettingControl->setVerticalMode(VFX_TRUE);   
            m_directSettingControl->setAnchor(0, 0.5);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[0],sp->circleControlSize[1]);    
            m_directSettingControl->setPos(0 - CAMCO_CAM_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1);    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(0 - CAMCO_CAM_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   
            
            m_capturableNumber->setPos(g_vapp_camco_skin.remainNuminfoHPos[0], g_vapp_camco_skin.remainNuminfoHPos[1]);
            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_statusInd[0]->setPos(sp->statusIconPos[0][0],  sp->statusIconPos[0][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[1]->setPos(sp->statusIconPos[1][0],  sp->statusIconPos[1][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[2]->setPos(sp->statusIconPos[2][0],  sp->statusIconPos[2][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[3]->setPos(sp->statusIconPos[3][0],  sp->statusIconPos[3][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);    
            m_statusInd[4]->setPos(sp->statusIconPos[4][0],  sp->statusIconPos[4][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[5]->setPos(sp->statusIconPos[5][0],  sp->statusIconPos[5][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[6]->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_statusInd[7]->setPos(sp->statusIconPos[7][0],  sp->statusIconPos[7][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS);   

        #ifdef __VAPP_CAMCO_ASD_ALWAYS_SHOW_ICON__
            // for always show ASD icon, no shift icon's position
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)            
            {
                m_statusInd[2]->setPos(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]);
            }
        #endif

            updateAuxiliary();

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
            
        }
            
    }    
    else   
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || 
           m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || 
           m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT ||
           m_mode == VAPP_CAMCO_PREVIEW_MODE_FRAME_SELECT)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);   

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));               
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1));
            m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
            
            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));    
            m_unusedSensor->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));   
            m_switcher->setPos(coordTransform2Vertical(sp->switchAppPos[0], sp->switchAppPos[1]));    
            m_switcherRec->setPos(m_switcher->getPos().x + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);
            m_switcherCam->setPos(m_switcher->getPos().x - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);            
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0],sp->zoomControlPos[1]));
            m_zoomer->setOpacity(1);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            m_coverFrame->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_NONE, VfxSize(sp->settingBarSize[1],sp->settingBarSize[0]));

            m_directSettingControl->setVerticalMode(VFX_FALSE);   
            m_directSettingControl->setAnchor(0.5, 0);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[1],sp->circleControlSize[0]);    
            m_directSettingControl->setPos(coordTransform2Vertical(0, GDI_LCD_WIDTH>>1));    

            m_advanceSettingControl->setAnchor(0.5, 0);
            m_advanceSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_capturableNumber->setPos(coordTransform2Vertical(g_vapp_camco_skin.remainNuminfoVPos[0], g_vapp_camco_skin.remainNuminfoVPos[1]));
            m_indicatorMsg->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());
            
            updateAuxiliary();

            m_statusInd[0]->setPos(coordTransform2Vertical(sp->statusIconPos[0][0],  sp->statusIconPos[0][1]));
            m_statusInd[1]->setPos(coordTransform2Vertical(sp->statusIconPos[1][0],  sp->statusIconPos[1][1]));
            m_statusInd[2]->setPos(coordTransform2Vertical(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]));
            m_statusInd[3]->setPos(coordTransform2Vertical(sp->statusIconPos[3][0],  sp->statusIconPos[3][1]));    
            m_statusInd[4]->setPos(coordTransform2Vertical(sp->statusIconPos[4][0],  sp->statusIconPos[4][1]));
            m_statusInd[5]->setPos(coordTransform2Vertical(sp->statusIconPos[5][0],  sp->statusIconPos[5][1]));
            m_statusInd[6]->setPos(coordTransform2Vertical(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]));
            m_statusInd[7]->setPos(coordTransform2Vertical(sp->statusIconPos[7][0],  sp->statusIconPos[7][1]));   

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);           
            
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR || m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);   

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));             
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1));
            m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
            
            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));    
            m_unusedSensor->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));   
            m_switcher->setPos(coordTransform2Vertical(sp->switchAppPos[0], sp->switchAppPos[1]));    
            m_switcherRec->setPos(m_switcher->getPos().x + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);
            m_switcherCam->setPos(m_switcher->getPos().x - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);            
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0],sp->zoomControlPos[1]));
            m_zoomer->setOpacity(0);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            m_coverFrame->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0 - CAMCO_CAM_PREVIEW_SHIFT_DIS);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_NONE, VfxSize(sp->settingBarSize[1],sp->settingBarSize[0]));  

            m_directSettingControl->setVerticalMode(VFX_FALSE);   
            m_directSettingControl->setAnchor(0.5, 0);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[1],sp->circleControlSize[0]);    
            m_directSettingControl->setPos(coordTransform2Vertical(0 - CAMCO_CAM_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1));    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(coordTransform2Vertical(0 - CAMCO_CAM_PREVIEW_SHIFT_DIS, (GDI_LCD_WIDTH>>1)));    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_capturableNumber->setPos(coordTransform2Vertical(g_vapp_camco_skin.remainNuminfoVPos[0], g_vapp_camco_skin.remainNuminfoVPos[1]));
            m_indicatorMsg->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            updateAuxiliary();            

            m_statusInd[0]->setPos(coordTransform2Vertical(sp->statusIconPos[0][0],  sp->statusIconPos[0][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[1]->setPos(coordTransform2Vertical(sp->statusIconPos[1][0],  sp->statusIconPos[1][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[2]->setPos(coordTransform2Vertical(sp->statusIconPos[2][0],  sp->statusIconPos[2][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[3]->setPos(coordTransform2Vertical(sp->statusIconPos[3][0],  sp->statusIconPos[3][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));    
            m_statusInd[4]->setPos(coordTransform2Vertical(sp->statusIconPos[4][0],  sp->statusIconPos[4][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[5]->setPos(coordTransform2Vertical(sp->statusIconPos[5][0],  sp->statusIconPos[5][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[6]->setPos(coordTransform2Vertical(sp->statusIconPos[6][0],  sp->statusIconPos[6][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));
            m_statusInd[7]->setPos(coordTransform2Vertical(sp->statusIconPos[7][0],  sp->statusIconPos[7][1] + CAMCO_CAM_PREVIEW_SHIFT_DIS));   

        #ifdef __VAPP_CAMCO_ASD_ALWAYS_SHOW_ICON__
            // for always show ASD icon, no shift icon's position
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)            
            {
                m_statusInd[2]->setPos(coordTransform2Vertical(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]));                       
            }
        #endif

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);           

        }
    }

    invalidate();
}

void OSDCamPreviewState::updateIcon(void)
{
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_FLASH) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {  
        m_statusInd[0]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_FLASH)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPMODE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {      
        m_statusInd[1]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_CAPMODE)));
    }    
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
    {     
        m_statusInd[2]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_CAMSCENEMODE)));
    }    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMSCENEMODE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {     
        m_statusInd[2]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_CAMSCENEMODE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMEV) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[3]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_CAMEV)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_AFMODE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[4]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_AFMODE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPSIZE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[5]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_CAPSIZE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_SELFTIMER) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[6]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_SELFTIMER)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_ISO) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[7]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_ISO)));
    }

}

void OSDCamPreviewState::updateSettingBar(VfxS16 isForceDirection)
{
    VfxU32 prevFocusID = m_settingBar->getCellID(m_settingBar->getFocus());     
    VfxS32 prevFocusIdx = -1;    
    VfxU16 settingCount = 0;
    VcpStateImage     imgList;
    if((isHorzUI() && isForceDirection == 0) || (isForceDirection > 0))
    {
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_FLASH) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_FLASH) > 1)
        {       
            if(prevFocusID == VAPP_CAMCO_SETTING_FLASH)
            {
                prevFocusIdx = settingCount;
            }    
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_FLASH));
            imgList.setImage(is, is, is, is);
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_FLASH, imgList);   
        }         
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAMSCENEMODE) > 1)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_CAMSCENEMODE)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMSCENEMODE));            
            imgList.setImage(is, is, is, is);
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAMSCENEMODE, imgList);        
        }
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAPMODE) > 1)
        {    
            if(prevFocusID == VAPP_CAMCO_SETTING_CAPMODE)
            {
                prevFocusIdx = settingCount;
            }    
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAPMODE));                   
            imgList.setImage(is, is, is, is);      
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAPMODE, imgList);    
        }       
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_WB) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_WB) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_WB)
            {
                prevFocusIdx = settingCount;
            } 
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB));              
            imgList.setImage(is, is, is, is);     
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_WB, imgList);  
        }    
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMEV) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAMEV) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_CAMEV)
            {
                prevFocusIdx = settingCount;
            } 
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMEV));              
            imgList.setImage(is, is, is, is);           
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAMEV, imgList);  
        }        
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_SELFTIMER) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_SELFTIMER) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_SELFTIMER)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_SELFTIMER));              
            imgList.setImage(is, is, is, is);         
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_SELFTIMER, imgList);    
        }    
        if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_MISC)
            {
                prevFocusIdx = settingCount;
            } 
            VfxImageSrc is = VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_ICON);               
            imgList.setImage(is, is, is, is);            
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_MISC, imgList);                     
        } 
        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_ADDFRAME_FRAME)
            {
                prevFocusIdx = settingCount;
            }      
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_ADDFRAME_FRAME));                 
            imgList.setImage(is, is, is, is);         
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_ADDFRAME_FRAME, imgList);      
        }    
    }
    else
    {
                   
        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_ADDFRAME_FRAME)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_ADDFRAME_FRAME));               
            imgList.setImage(is, is, is, is);            
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_ADDFRAME_FRAME, imgList);      
        }  
        if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_MISC)
            {
                prevFocusIdx = settingCount;
            } 
            VfxImageSrc is = VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_ICON);              
            imgList.setImage(is, is, is, is);             
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_MISC, imgList);                  
        }          
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_SELFTIMER) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_SELFTIMER) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_SELFTIMER)
            {
                prevFocusIdx = settingCount;
            }    
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_SELFTIMER));              
            imgList.setImage(is, is, is, is);        
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_SELFTIMER, imgList);    
        }           
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMEV) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAMEV) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_CAMEV)
            {
                prevFocusIdx = settingCount;
            }   
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMEV));
            imgList.setImage(is, is, is, is);                    
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAMEV, imgList);  
        }         
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_WB) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_WB) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_WB)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB));            
            imgList.setImage(is, is, is, is);              
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_WB, imgList);  
        }          
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAPMODE) > 1)
        {    
            if(prevFocusID == VAPP_CAMCO_SETTING_CAPMODE)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAPMODE));   
            imgList.setImage(is, is, is, is);              
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAPMODE, imgList);    
        }         
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_CAMSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_CAMSCENEMODE) > 1)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_CAMSCENEMODE)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMSCENEMODE));               
            imgList.setImage(is, is, is, is);    
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_CAMSCENEMODE, imgList);        
        }        
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_FLASH) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_FLASH) > 1)
        {       
            if(prevFocusID == VAPP_CAMCO_SETTING_FLASH)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_FLASH));   
            imgList.setImage(is, is, is, is);             
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_FLASH, imgList);   
        }           
    }
    m_settingBar->setCount(settingCount);
    if(prevFocusIdx == -1 || prevFocusIdx > (settingCount >>1))
        m_settingBar->setFocusOnCenter();     
    else
        m_settingBar->setFocusandCheck(prevFocusIdx);     

}

void OSDCamPreviewState::updateAuxiliary(void)
{
    VfxBool shown = (m_cntx.setting->getValue(VAPP_CAMCO_SETTING_AUXILIARY) == VAPP_CAMCO_AUXILIRY_ON);
    VfxBool isHz = isHorzUI();
    for(VfxU8 i = 0; i < 4; i++)
    {            
        if(shown)    
        {
            m_auxiliary[i]->setHidden(VFX_FALSE);
        }
        else
        {
            m_auxiliary[i]->setHidden(VFX_TRUE);
        }       
        if(isHz)
        {
            if(i == 0)
            {
                m_auxiliary[i]->setSize(GDI_LCD_HEIGHT, 4);
                m_auxiliary[i]->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH/3);
            }
            else if(i == 1)
            {
                m_auxiliary[i]->setSize(GDI_LCD_HEIGHT, 4);            
                m_auxiliary[i]->setPos(GDI_LCD_HEIGHT>>1, 2*GDI_LCD_WIDTH/3);                
            }
            else if(i == 2)
            {
                m_auxiliary[i]->setSize(4, GDI_LCD_WIDTH);           
                m_auxiliary[i]->setPos(GDI_LCD_HEIGHT/3, GDI_LCD_WIDTH>>1);                
            }
            else if(i == 3)
            {
                m_auxiliary[i]->setSize(4, GDI_LCD_WIDTH);                      
                m_auxiliary[i]->setPos(2*GDI_LCD_HEIGHT/3, GDI_LCD_WIDTH>>1);                       
            }            
        }
        else
        {
            if(i == 0)
            {
                m_auxiliary[i]->setSize(GDI_LCD_WIDTH, 4);  
                m_auxiliary[i]->setPos(GDI_LCD_WIDTH>>1, GDI_LCD_HEIGHT/3); 
            }
            else if(i == 1)
            {
                m_auxiliary[i]->setSize(GDI_LCD_WIDTH, 4);  
                m_auxiliary[i]->setPos(GDI_LCD_WIDTH>>1, 2*GDI_LCD_HEIGHT/3);                                  
            }
            else if(i == 2)
            {
                m_auxiliary[i]->setSize(4, GDI_LCD_HEIGHT);       
                m_auxiliary[i]->setPos(GDI_LCD_WIDTH/3, GDI_LCD_HEIGHT>>1);                     
            }
            else if(i == 3)
            {
                m_auxiliary[i]->setSize(4, GDI_LCD_HEIGHT);  
                m_auxiliary[i]->setPos(2*GDI_LCD_WIDTH/3, GDI_LCD_HEIGHT>>1);                                     
            }            
        }
        
    }

}

void OSDCamPreviewState::onSettingTraverse(VfxU32 ID)
{    
    refreshAutoExitTimer();
    m_resetScreenTimer->start(); 
    m_fadeOutScreenTimer->stop();         
}

void OSDCamPreviewState::onBeforeSettingEnter(VfxU32 ID)
{
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_STOP, NULL);     
}

void OSDCamPreviewState::onSettingEnter(VfxU32 ID) 
{
    refreshAutoExitTimer();

    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_STOP, NULL);      

    m_CurrentCapmode = (vapp_camco_capmode_enum)m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE);    
    
    if(ID == VAPP_CAMCO_SETTING_MISC)
    {    
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_ENTER_ADVANCE_SETTING);      
        
        if(!isHorzUI())
        {
            m_cntx.setting->needRestartPreview();
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_FORCE_HORZ, NULL);       
        }
        else
        {
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_NOTIFY_HORZ, NULL);                     
        }
        
        // UI change    
        setAdvanceSettingMode();        

        // set setting content
        m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_CAMERA);     

        VcpStateImage     imgList;
        imgList.setImage(
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON));             
        m_advanceSettingControl->setSettingImg(imgList);    
        
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_advanceSettingControl->reset();          
        m_advanceSettingControl->setCount(settingList.settingCount);                
        for(VfxU8 i = 0; i < settingList.settingCount; i++)
        {        
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]));
            
            m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
        }      
        m_advanceSettingControl->setFocus(settingList.CurrentSettingIdx);           
        m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
        for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
        {        
            m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
        }   
        if(VAPP_CAMCO_SETTING_RESTOREDEFAULT == settingList.settingValue[settingList.CurrentSettingIdx])
        {
            m_advanceSettingControl->setItemFocus(1);           
        }
        else
        {
            m_advanceSettingControl->setItemFocus(settingList.CurrentSettingValueIdx);           
        }
        m_advanceSettingControl->updateItem();          
        
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_ENTER_SETTING, ID);      
        
        // UI change
        setDirectSettingMode((VfxObject*)m_directSettingControl);  

        // set setting content
        if(ID == VAPP_CAMCO_SETTING_CAMSCENEMODE)
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_CAMSCN_ONLY);   
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMSCENEMODE) + 1);               
            imgList.setImage(is, is, is, is);
            m_directSettingControl->setSettingImg(imgList);
        }
        else if(ID == VAPP_CAMCO_SETTING_CAMEV)     
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_CAMEV_ONLY);   
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMEV) + 1);               
            imgList.setImage(is, is, is, is);           
            m_directSettingControl->setSettingImg(imgList);            
        }        
        else if(ID == VAPP_CAMCO_SETTING_CAPMODE)    
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_CAPTUREMODE_ONLY);   
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAPMODE) + 1);               
            imgList.setImage(is, is, is, is);          
            m_directSettingControl->setSettingImg(imgList);            
        }
        else if(ID == VAPP_CAMCO_SETTING_SELFTIMER)    
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_TIMER_ONLY);        
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_SELFTIMER) + 1);                 
            imgList.setImage(is, is, is, is);               
            m_directSettingControl->setSettingImg(imgList);            
        }
        else if(ID == VAPP_CAMCO_SETTING_FLASH)   
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_FLASH_ONLY);   
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_FLASH) + 1);                    
            imgList.setImage(is, is, is, is);             
            m_directSettingControl->setSettingImg(imgList);            
        }
        else if(ID == VAPP_CAMCO_SETTING_WB)
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_AWB_ONLY);    
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB) + 1);              
            imgList.setImage(is, is, is, is);               
            m_directSettingControl->setSettingImg(imgList);            
        }
        else if(ID == VAPP_CAMCO_SETTING_ADDFRAME_FRAME)
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_IMAGEFRAME_ONLY);  
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_ADDFRAME_FRAME) + 1);               
            imgList.setImage(is, is, is, is);           
            m_directSettingControl->setSettingImg(imgList);            
        }
        else
        {
            ASSERT(0);
        }
            
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_directSettingControl->reset();        
        m_directSettingControl->setCount(settingList.settingItemCount);        
        for(VfxU32 i = 0; i < settingList.settingItemCount; i++)
        {
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]));
            
            m_directSettingControl->setCellData(i, settingList.settingItemValue[i], imgList, VFX_WSTR_RES(settingList.settingItemStrId[i]));
        }        
        m_directSettingControl->setFocus(settingList.CurrentSettingValueIdx);           

    }

    m_resetScreenTimer->stop();    
    m_fadeOutScreenTimer->stop();     
}


void OSDCamPreviewState::onSettingSet(VfxU32 ID)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_SET_SETTING); 
    
    refreshAutoExitTimer();
        
    m_cntx.setting->setValue(ID);
   
    m_imageFrame->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_ADDFRAME_FRAME)));   

    updateSettingBar(0);
    updateIcon();

    setDirectSettingMode((VfxObject*)m_directSettingControl);
}


void OSDCamPreviewState::onDirectSettingLeave(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_LEAVE_SETTING);  

    refreshAutoExitTimer();

    if(m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    } 

    m_cntx.setting->resetEffect();
    m_directSettingControl->recoverEffect();    
    refreshAutoExitTimer();    
    m_resetScreenTimer->start();        
    
}    

void OSDCamPreviewState::onAdvanceSettingLeave(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_LEAVE_ADVANCE_SETTING);  

    refreshAutoExitTimer();

    if(m_advanceSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    } 

    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
       m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
    {
        m_settingBar->setFocus(0, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                
    }
    else
    {
        m_settingBar->setFocus(m_settingBar->getCount() - 1, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                            
    }
    m_advanceSettingControl->recoverEffect();        
    
}  

void OSDCamPreviewState::onAdvanceSettingTraverse(VfxU32 id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_TRAVERSE_ADVANCE_SETTING, id);  

    refreshAutoExitTimer();

    m_cntx.setting->setCurrentSetting((vapp_camco_setting_enum)id);
    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);
    m_advanceSettingControl->reset();          
    m_advanceSettingControl->setCount(settingList.settingCount);                
    for(VfxU8 i = 0; i < settingList.settingCount; i++)
    {        
        VcpStateImage     imgList;
        imgList.setImage(
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]));
        
        m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
    }      
    m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
    for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
    {                
        m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
    }
    if(VAPP_CAMCO_SETTING_RESTOREDEFAULT == settingList.settingValue[settingList.CurrentSettingIdx])
    {
        m_advanceSettingControl->setItemFocus(1);           
    }
    else
    {
        m_advanceSettingControl->setItemFocus(settingList.CurrentSettingValueIdx);           
    }    
    m_advanceSettingControl->updateItem();
        
}

void OSDCamPreviewState::onAdvanceSettingSelected(VfxU32 id, VfxU32 idx)
{
    refreshAutoExitTimer();

    m_cntx.setting->setCurrentSetting((vapp_camco_setting_enum)id);
    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);

    if((vapp_camco_setting_enum)id == VAPP_CAMCO_SETTING_RESTOREDEFAULT)
    {
        if(idx != 0 || m_confirmPopup != NULL)
            return;

        VcpConfirmPopup *m_confirmRestorePopup;
        
        VFX_OBJ_CREATE(m_confirmRestorePopup, VcpConfirmPopup, this);
        m_confirmPopup = m_confirmRestorePopup;
        m_confirmRestorePopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmRestorePopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAMCO_DEFAULT_COMFIRM));
        m_confirmRestorePopup->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);
        m_confirmRestorePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmRestorePopup->setCustomButton(
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_WARNING,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        
        m_confirmRestorePopup->setAutoDestory(VFX_TRUE);    
        m_confirmRestorePopup->m_signalButtonClicked.connect(this, &OSDCamPreviewState::onRestoreConfirm);
        m_confirmRestorePopup->show(VFX_TRUE);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_SET_ADVANCE_SETTING);     
        m_cntx.setting->setValue((vapp_camco_setting_enum)id, idx);
        m_cntx.setting->resetEffect();    
    }
    updateIcon();  
    updateSettingBar(0);    

    // check storage
    if(srv_fmgr_drv_is_removable(m_cntx.setting->getStorage()) 
        && !srv_fmgr_drv_is_accessible(m_cntx.setting->getStorage()))
    {
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV)); 

        if(m_confirmPopup == NULL)
        {
            VcpConfirmPopup *m_confirmStoragePopup;
            
            VFX_OBJ_CREATE(m_confirmStoragePopup, VcpConfirmPopup, this);
            m_confirmPopup = m_confirmStoragePopup;        
            m_confirmStoragePopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmStoragePopup->setText(VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED));
            m_confirmStoragePopup->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);        
            m_confirmStoragePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);        
            m_confirmStoragePopup->setAutoDestory(VFX_TRUE);    
            m_confirmStoragePopup->m_signalButtonClicked.connect(this, &OSDCamPreviewState::onSettingError);
            m_confirmStoragePopup->show(VFX_TRUE);    
        }
    }
    
}

void OSDCamPreviewState::onZooming(VfxU32 value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_SET_ZOOM_SETTING);     
    
    refreshAutoExitTimer();   

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, value);
    m_resetScreenTimer->start();   
}

void OSDCamPreviewState::onSettingError(VfxObject* obj, VfxId id)
{
    refreshAutoExitTimer();   

    m_confirmPopup = NULL;

    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);
    m_advanceSettingControl->reset();          
    m_advanceSettingControl->setCount(settingList.settingCount);                
    for(VfxU8 i = 0; i < settingList.settingCount; i++)
    {        
        VcpStateImage     imgList;
        imgList.setImage(
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]));
        
        m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
    }      
    m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
    for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
    {                
        m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
    }
    m_advanceSettingControl->setItemFocus(0);       
    m_advanceSettingControl->updateItem();     

}

void OSDCamPreviewState::onRestoreConfirm(VfxObject* obj, VfxId id)
{   
    refreshAutoExitTimer();   

    m_confirmPopup = NULL;

    if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);        
        
        m_cntx.setting->restoreFactorySetting();
        setNormalMode();     
        m_resetScreenTimer->start();    
        m_cntx.setting->resetEffect();     
        m_settingBar->setFocusOnCenter();     
        m_cntx.setting->needRestartPreview();        
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL);            
    }
    else
    {        
        m_cntx.setting->setCurrentSetting(VAPP_CAMCO_SETTING_RESTOREDEFAULT);
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_advanceSettingControl->reset();          
        m_advanceSettingControl->setCount(settingList.settingCount);                
        for(VfxU8 i = 0; i < settingList.settingCount; i++)
        {        
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]));
            
            m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
        }      
        m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
        for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
        {                
            m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
        }
        m_advanceSettingControl->setItemFocus(1); 
        m_advanceSettingControl->updateItem();        
    }  
}

void OSDCamPreviewState::onGalleryClicked(VfxObject *obj, VfxId id)
{
    refreshAutoExitTimer();   

    if(!m_isActive)
        return;

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;
    
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_ENTER_GALLERY, NULL);
}

void OSDCamPreviewState::onCaptureClicked(VfxObject* obj, VfxId id)
{
    refreshAutoExitTimer();   

    if(!m_isActive)
        return;

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }   
    
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_CONT_SHOT)
    {
        return;
    }

    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            if(m_previousModeDirSettingObj == m_directSettingControl)
            {
                m_directSettingControl->recoverEffect();        
                m_resetScreenTimer->start();    
                m_isdelaySD = VFX_TRUE;
            }
        }
        else
        {
            setSmileDetectMode();   
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_START_SMILEDETECT, NULL);   
            m_isFocussing = VFX_FALSE;
            m_autoExitTimer->stop();                      
            m_resetScreenTimer->stop();
        }
    }  
    else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
    {
        CamcoSettingItem * setting_p = 0;
        m_cntx.setting->getGurrentSetting(&setting_p);
        if(m_previousModeDirSettingObj == m_directSettingControl && setting_p->getType() == VAPP_CAMCO_SETTING_CAPMODE)
        {   
            m_directSettingControl->recoverEffect();
            m_resetScreenTimer->start();
        }
        else
        {
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);                
        }
    }
    else
    {                
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
    }
    m_isFocussing = VFX_FALSE;
    m_usedSensor->setOpacity(1);
}

void OSDCamPreviewState::onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{
    refreshAutoExitTimer();   

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }   

#if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_CONT_SHOT)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    // for cont. shot
                    // pen event cannot pass to cont OSD state after set to normal shot
                    // so just back to normal state not start to shot or capture wont stop
                    CamcoSettingItem * setting_p = 0;
                    m_cntx.setting->getGurrentSetting(&setting_p);
                    if(m_previousModeDirSettingObj == m_directSettingControl && setting_p->getType() == VAPP_CAMCO_SETTING_CAPMODE)
                    {
                        m_directSettingControl->recoverEffect();
                        m_resetScreenTimer->start();
                    }
                    else
                    {
                        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                    }
                }
                else
                {
                    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                }
            }
            // when in direct setting , don't allow to focus
            // or it won't restart and update setting
            else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT)
            {
                break;
            }
            else
            {
            #if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
                evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_FOCUS, NULL);
                if(VappCamcoPage::m_errStr == 0)
                    m_isFocussing = VFX_TRUE;
                else
                    m_isFocussing = VFX_FALSE;
            #endif
            }
            m_usedSensor->setOpacity(0.5);        
            break;
        case VCP_BUTTON_STATE_NORMAL:
        #if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            if(m_isFocussing)
                evtHdlr->camFocusHdlr(VAPP_CAMCO_EVT_FOCUS_STOP, NULL);
            m_isFocussing = VFX_FALSE;
        #endif
            m_usedSensor->setOpacity(1);        
            break;
        default:
            break;
    }
#else
    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_CONT_SHOT)
            {    
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    // for cont. shot
                    // pen event cannot pass to cont OSD state after set to normal shot
                    // so just back to normal state not start to shot or capture wont stop
                    CamcoSettingItem * setting_p = 0;
                    m_cntx.setting->getGurrentSetting(&setting_p);
                    if(m_previousModeDirSettingObj == m_directSettingControl && setting_p->getType() == VAPP_CAMCO_SETTING_CAPMODE)
                    {   
                        m_directSettingControl->recoverEffect();        
                        m_resetScreenTimer->start();                    
                    }            
                    else
                    {
                        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                    }                    
                }
                else
                {
                    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                }
            }
            m_usedSensor->setOpacity(0.5);
            break;
        case VCP_BUTTON_STATE_NORMAL:
            m_usedSensor->setOpacity(1);
            break;
        default:
            break;
    }        
#endif
}


void OSDCamPreviewState::onSwitchSensorClicked(VfxObject *obj, VfxId id)
{
    refreshAutoExitTimer();   

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }       

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);    
    }
    
    m_settingBar->setFocusOnCenter();     

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    m_cntx.setting->storeSceneSetting();
    
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_LEAVE_SMILEDETECT, NULL);             

    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        m_cntx.setting->setCurrCam(VAPP_CAMCO_SENSOR_SUB_CAMERA);
    }            
    else if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
    {
        m_cntx.setting->setCurrCam(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
    }
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_SENSOR, NULL);
}

void OSDCamPreviewState::onSwitchAppClicked(VfxObject* obj, VfxId id)
{
#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }  

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);    
    }

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setImage(SI);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();             
    
    VFX_OBJ_CREATE(m_clickTimer, VfxTimer, this);
    m_clickTimer->setStartDelay(1);
    m_clickTimer->m_signalTick.connect(this, &OSDCamPreviewState::onSwitchAppTick);
    m_clickTimer->start();
    m_isClicking = VFX_TRUE;
}

void OSDCamPreviewState::onSwitchAppTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    m_isClicking = VFX_FALSE;

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setImage(SI);

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    m_settingBar->setFocusOnCenter();       

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    m_cntx.setting->storeSceneSetting();
    
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_LEAVE_SMILEDETECT, NULL);             

    if(m_cntx.setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        m_cntx.setting->setCurrApp(VAPP_CAMCO_APP_RECORDER);
    }            
    else 
    {
        ASSERT(0);
    }
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_APP, NULL);
}


void OSDCamPreviewState::onResetTimerTick(VfxTimer *source)
{
    setClearMode();
    m_resetScreenTimer->stop();    
}

void OSDCamPreviewState::onCPEffctDoneTick(VfxU32 ID)
{
    vapp_camco_cam_preview_mode_enum previousMode = m_mode;

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        #if defined (HORIZONTAL_CAMERA)    	
        if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
           m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
        #endif   
        {
            m_cntx.setting->needRestartPreview();    
        }
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL);         
    }
    else
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_DE_NOTIFY_HORZ, NULL);                         
        if(m_cntx.setting->isNeedRestartPreview())
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_RESTART, NULL);          
    }    
    
    m_settingBar->setHidden(VFX_FALSE);
    m_directSettingControl->setHidden(VFX_TRUE);
    m_advanceSettingControl->setHidden(VFX_TRUE);   
  
    if(previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)    
    {
        #if defined (HORIZONTAL_CAMERA)    	    	
        if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
           m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
        #endif
        {
            // vertical v.s. horizontal bar
            updateSettingBar(-1);
        }
        
        if(isHorzUI())
        {
            VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
            m_switcher->setImage(SI);
            m_switcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);         
        }
        else
        {
            VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
            m_switcher->setImage(SI);
            m_switcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);         
        }           
    }
    if(m_settingBar->getPostFocus() != m_settingBar->getFocus())
    {
        m_settingBar->setFocus(m_settingBar->getPostFocus(), VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);
    }    
    m_settingBar->recoverEffect();

    m_resetScreenTimer->start();      
}

void OSDCamPreviewState::onCPEffctDoneTick2(VfxU32 ID)
{
    // set back the focus(center) icon before tap 
    m_settingBar->setFocusandCheck(m_settingBar->getPrevFocus());    

    setNormalMode();    
    updateSettingBar(0);    
    m_resetScreenTimer->start();    


    m_postProcessTimer->setStartDelay(500);
    m_postProcessTimer->start();
}

void OSDCamPreviewState::onPostProcessTimerTick(VfxTimer *source)
{
    if(m_isdelaySD)
    {
        m_isdelaySD = VFX_FALSE;
        setSmileDetectMode();   
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_START_SMILEDETECT, NULL);
        m_isFocussing = VFX_FALSE;
        m_autoExitTimer->stop();                              
        m_resetScreenTimer->stop();    
    }
    else if(m_isdelayRestartPreview)
    {
        m_isdelayRestartPreview = VFX_FALSE;
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);        
    }
    
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);        
}

VfxBool OSDCamPreviewState::isHorzUI(void)
{
#if defined (HORIZONTAL_CAMERA)
    if((m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA && m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) != VAPP_CAMCO_CAPSIZE_WALLPAPER)
        || (m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION && m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }        
#else
    if((m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION && m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }   
#endif
}


void OSDCamPreviewState::ZoomingIn(VfxTimer *source)
{
    refreshAutoExitTimer();   

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM))
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) + 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                     
    m_resetScreenTimer->start();    
    m_zoomingTimer->start();                    

}

void OSDCamPreviewState::ZoomingOut(VfxTimer *source)
{
    refreshAutoExitTimer();   

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM))                                    
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) - 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                      
    m_resetScreenTimer->start();     
    m_zoomingTimer->start();
                 
}


VfxBool OSDCamPreviewState::onPenInput(VfxPenEvent & event)
{
    refreshAutoExitTimer();

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && 
       m_mode != VAPP_CAMCO_PREVIEW_MODE_DIRSETTING &&
       m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING) 
    {
        m_resetScreenTimer->start();   
    }

    if(m_postProcessTimer->getIsEnabled() || m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        m_isDownProcessed = VFX_TRUE;
        return VFX_TRUE;
    }    

    if(m_isClicking)
    {
        m_isDownProcessed = VFX_TRUE;    
        return VFX_TRUE;
    }

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                setNormalMode();            
            else if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                setAdvanceSettingMode();            
            else if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                setDirectSettingMode(m_previousModeDirSettingObj);          
            
            m_fadeOutScreenTimer->stop();                 
            m_isDownProcessed = VFX_TRUE;
        }                

        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT)
        {      
            m_isDownProcessed = VFX_TRUE;       
        }         
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            if((isHorzUI() && pos.x > 0.25 * m_advanceSettingControl->getSize().width) ||
               (!isHorzUI() && pos.y > 0.25 * m_advanceSettingControl->getSize().width))
            {           
                if(m_previousModeDirSettingObj == m_directSettingControl)
                {
                    m_settingBar->searchFocusItem(VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);            
                    m_directSettingControl->recoverEffect();        
                }
                else
                {
                    setNormalMode();    
                }
            }
            m_isDownProcessed = VFX_TRUE;                   
        }        
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        {
            if(pos.x > 0.3 * m_advanceSettingControl->getSize().width)
            {        
                if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
                   m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
                {
                    m_settingBar->setFocus(0, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                
                }
                else
                {
                    m_settingBar->setFocus(m_settingBar->getCount() - 1, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                            
                }
                m_advanceSettingControl->recoverEffect();        
            }
            m_isDownProcessed = VFX_TRUE;       
                     
        }           
        else if(m_mode != VAPP_CAMCO_PREVIEW_MODE_CLEAR) 
        {            
            m_lastX = pos.x;
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(m_rightBar->getBounds().contains(posR))
                m_isDownProcessed = VFX_TRUE;             
            else
                m_isDownProcessed = VFX_FALSE;                             
        }   
        else
        {
            m_lastX = pos.x;        
            m_isDownProcessed = VFX_FALSE; 
        }
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_isDownProcessed)
            return VFX_TRUE;

        if(m_lastX <= pos.x + CAMCO_CAM_PREVIEW_MOVE_THRESHOLD && m_lastX > pos.x - CAMCO_CAM_PREVIEW_MOVE_THRESHOLD)
        {
            if(m_mode != VAPP_CAMCO_PREVIEW_MODE_CLEAR)
            {
                setClearModeinternal(NULL);
                return VFX_TRUE;            
            }            
            else
            {
                setNormalMode();    
                return VFX_TRUE;                
            }
        }
        
        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {
            if(m_lastX > pos.x + CAMCO_CAM_PREVIEW_MOVE_THRESHOLD)
            {
                if(m_hiliteFrameIdx < VAPP_CAMCO_ADDFRAME_END - 1)
                {
                    m_hiliteFrameIdx++; 
                }
                else
                {
                    m_hiliteFrameIdx=0; 

                }
                AddFrameFrameSetting * settngPtr;

                m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, (CamcoSettingItem**) &settngPtr);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_SET_ADDFRAME_SETTING);     
                m_cntx.setting->setValue(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, m_hiliteFrameIdx);
                
                m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);                        
                m_imageFrame->setImgContent(VfxImageSrc(settngPtr->getItem(m_hiliteFrameIdx).getStatusIcon()));    

            }
            else if(m_lastX < pos.x - CAMCO_CAM_PREVIEW_MOVE_THRESHOLD)
            {
                if(m_hiliteFrameIdx > 0)
                {
                    m_hiliteFrameIdx--; 
                }
                else
                {
                    m_hiliteFrameIdx = (VAPP_CAMCO_ADDFRAME_END - 1);
                }
                AddFrameFrameSetting * settngPtr;

                m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, (CamcoSettingItem**) &settngPtr);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_SET_ADDFRAME_SETTING);                     
                m_cntx.setting->setValue(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, m_hiliteFrameIdx);
                
                m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);                        
                m_imageFrame->setImgContent(VfxImageSrc(settngPtr->getItem(m_hiliteFrameIdx).getStatusIcon()));                                 

            }  
            setNormalMode();    
            return VFX_TRUE;                  
        }
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return CamcoOSDState::onPenInput(event);

}


VfxBool OSDCamPreviewState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();
    
    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && 
       m_mode != VAPP_CAMCO_PREVIEW_MODE_DIRSETTING &&
       m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING) 
    {
        m_resetScreenTimer->start();   
    }


    if(m_postProcessTimer->getIsEnabled() || m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return VFX_TRUE;
    }    

    if(m_isBusy)
        return VFX_TRUE;

    if(m_isClicking)
        return VFX_TRUE;

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA:  
        case VFX_KEY_CODE_ENTER:              
        {
            // cannot capture in advance setting menu
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                return VFX_TRUE;    
            }            
            
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_DOWN)        
            {
                // when in direct setting , don't allow to focus
                // or it won't restart and update setting
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT)
                {
                    return VFX_TRUE;
                }
                
            #if defined(VAPP_CAMCO_AF_SUPPORT)
                evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_FOCUS, NULL);
                if(VappCamcoPage::m_errStr == 0)
                    m_isFocussing = VFX_TRUE;
                else
                    m_isFocussing = VFX_FALSE;
            #endif
            }            
            else if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {                
                if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
                {
                    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                    {
                        if(m_previousModeDirSettingObj == m_directSettingControl)
                        {
                            m_directSettingControl->recoverEffect();        
                            m_isdelaySD = VFX_TRUE;
                        }
                    }
                    else
                    {
                        setSmileDetectMode();   
                        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_START_SMILEDETECT, NULL);   
                        m_isFocussing = VFX_FALSE;
                        m_autoExitTimer->stop();                      
                        m_resetScreenTimer->stop();
                        return VFX_TRUE;                        
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    // for cont. shot
                    // pen event cannot pass to cont OSD state after set to normal shot
                    // so just back to normal state not start to shot or capture wont stop
                    CamcoSettingItem * setting_p = 0;
                    m_cntx.setting->getGurrentSetting(&setting_p);
                    if(m_previousModeDirSettingObj == m_directSettingControl && setting_p->getType() == VAPP_CAMCO_SETTING_CAPMODE)
                    {   
                        m_directSettingControl->recoverEffect();        
                        m_resetScreenTimer->start();                    
                    }            
                    else
                    {
                        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                    }                    
                }
                else
                {
                #if defined(VAPP_CAMCO_AF_SUPPORT)
                    if(m_isFocussing)
                        evtHdlr->camFocusHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                    else
                #endif
                    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
                    m_isFocussing = VFX_FALSE;
                }                
            }
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_UP)
            {
            #if defined(VAPP_CAMCO_AF_SUPPORT)
                if(m_isFocussing)
                    evtHdlr->camFocusHdlr(VAPP_CAMCO_EVT_FOCUS_STOP, NULL);
                m_isFocussing = VFX_FALSE;
            #endif
            }          
            return VFX_TRUE;
        } 
        case VFX_KEY_CODE_ARROW_LEFT:             
        {
            if(!isHorzUI())    
            {
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() - 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() - 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)  
                        return VFX_TRUE;           
                           
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM))                                    
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) - 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                      

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDCamPreviewState::ZoomingIn);                        
                        m_zoomingTimer->m_signalTick.connect(this, &OSDCamPreviewState::ZoomingOut);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                             
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();                      
                    }
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            else
            {
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {              
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
                    {            
                        if(m_hiliteFrameIdx > 0)
                        {
                            m_hiliteFrameIdx--; 
                        }
                        else
                        {
                            m_hiliteFrameIdx = (VAPP_CAMCO_ADDFRAME_END - 1);
                        }
                        AddFrameFrameSetting * settngPtr;

                        m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, (CamcoSettingItem**) &settngPtr);
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, m_hiliteFrameIdx);
                        
                        m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);                        
                        m_imageFrame->setImgContent(VfxImageSrc(settngPtr->getItem(m_hiliteFrameIdx).getStatusIcon()));                 
                    }            
                }
            }
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_RIGHT:            
        {
            if(!isHorzUI())    
            {            
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() + 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() + 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)  
                        return VFX_TRUE;         
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM))
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) + 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                     

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDCamPreviewState::ZoomingOut);                           
                        m_zoomingTimer->m_signalTick.connect(this, &OSDCamPreviewState::ZoomingIn);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                             
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();                      
                    }                        
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            else
            {
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {  
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ADD_FRAME)
                    {               
                        if(m_hiliteFrameIdx < VAPP_CAMCO_ADDFRAME_END - 1)
                        {
                            m_hiliteFrameIdx++; 
                        }
                        else
                        {
                            m_hiliteFrameIdx=0; 

                        }
                        AddFrameFrameSetting * settngPtr;

                        m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, (CamcoSettingItem**) &settngPtr);
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_ADDFRAME_FRAME, m_hiliteFrameIdx);
                        
                        m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);                        
                        m_imageFrame->setImgContent(VfxImageSrc(settngPtr->getItem(m_hiliteFrameIdx).getStatusIcon()));                
                    }            
                }
            }
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_UP:  
        case VFX_KEY_CODE_VOL_UP:            
        {
            if(isHorzUI() || event.keyCode == VFX_KEY_CODE_VOL_UP)    
            {               
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() - 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() - 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)  
                        return VFX_TRUE;         
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM))
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) + 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                     

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDCamPreviewState::ZoomingOut);                           
                        m_zoomingTimer->m_signalTick.connect(this, &OSDCamPreviewState::ZoomingIn);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                             
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();                      
                    }                        
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }   
            }
            return VFX_TRUE;             
        }            
        case VFX_KEY_CODE_ARROW_DOWN:  
        case VFX_KEY_CODE_VOL_DOWN:            
        {
            if(isHorzUI() || event.keyCode == VFX_KEY_CODE_VOL_DOWN)    
            {                 
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() + 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() + 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)  
                        return VFX_TRUE;         
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM))                                    
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM) - 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));                      

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDCamPreviewState::ZoomingIn);                           
                        m_zoomingTimer->m_signalTick.connect(this, &OSDCamPreviewState::ZoomingOut);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                             
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();                      
                    }
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }  
            }
            return VFX_TRUE;             
        }
        case VFX_KEY_CODE_BACK:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {       
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                {
                    onAdvanceSettingLeave(NULL, 0);
                    return VFX_TRUE;                                   
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    onDirectSettingLeave(NULL, 0);
                    return VFX_TRUE;                                                       
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    setClearModeinternal(NULL);                                     
                    return VFX_TRUE;                                                       
                }                   
            }
        }        
    }
    return CamcoOSDState::onKeyInput(event);
}


void OSDCamContShotState::onInit(void)
{
    CamcoOSDState::onInit();

    VFX_OBJ_CREATE(m_capture, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_captureTimer, VfxTimer, this);  
    VFX_OBJ_CREATE(m_stopTimer, VfxTimer, this);  
   
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON,IMG_ID_VAPP_CAMCO_CAPTURE_ICON);
    m_capture->setAnchor(0.5, 0.5);
    m_capture->setImage(SI);
    m_capture->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_capture->setAutoAnimate(VFX_FALSE);

    setBgColor(VFX_COLOR_BLACK);
    
    m_captureTimer->setStartDelay(VAPP_CAMCO_CONT_SHOT_FREQ);
    m_stopTimer->setStartDelay((VAPP_CAMCO_CONT_SHOT_FREQ>>1));
        
    m_state = VAPP_CAMCO_OSD_STATE_CAMERA_CONTSHOT;        

    m_captureTimer->m_signalTick.connect(this, &OSDCamContShotState::oncaptureTimerTick);
    m_stopTimer->m_signalTick.connect(this, &OSDCamContShotState::onStopTimerTick);
    m_capture->m_signalStateChanged.connect(this, &OSDCamContShotState::onCapture);

};

void OSDCamContShotState::enterState(void* param)
{
    CamcoOSDState::enterState(param);
    
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_cam_contshot_param_struct));
    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
        setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);       
        
        m_capture->setPos(g_vapp_camco_skin.capturePos[0], g_vapp_camco_skin.capturePos[1]);    
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
        setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);       
        
        m_capture->setPos(coordTransform2Vertical(g_vapp_camco_skin.capturePos[0], g_vapp_camco_skin.capturePos[1]));        
    }
    setBgColor(VFX_COLOR_TRANSPARENT);
    
    m_capture->capture();

    rotateOSD(m_isHorz, m_isMirror);

    m_keyDown = VFX_TRUE;

    if(m_capture->getState() == VCP_BUTTON_STATE_PRESSED)
        m_capture->setOpacity(0.5);

    evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);            
    m_captureTimer->start();        

};


void OSDCamContShotState::exitState(void)
{
    CamcoOSDState::exitState();
    m_captureTimer->stop();

    m_stopTimer->start();

    m_capture->setOpacity(1);
}

void OSDCamContShotState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    // do nothing
}

void OSDCamContShotState::onStopTimerTick(VfxTimer *source)
{
    // because key wont get up if error happen and exit cont OSDstate
    // (where button will get reset normal state)
    // so we simulate a up key for that
    if(m_keyDown && evtHdlr)
    {
        m_keyDown = VFX_FALSE;
        evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CONT_SHOT_FINISH, NULL);
    }
}

void OSDCamContShotState::oncaptureTimerTick(VfxTimer *source)
{
    refreshAutoExitTimer();

    if(!m_keyDown)
        return;

    evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
    
    m_captureTimer->start();    
}     

void OSDCamContShotState::onCapture(VcpImageButton* obj, VcpImageButtonStateEnum state)
{
    refreshAutoExitTimer();   

    switch (state)
    {
        case VCP_BUTTON_STATE_NORMAL:
            if(m_keyDown)
            {
                m_keyDown = VFX_FALSE;
                m_capture->setOpacity(1);
                evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CONT_SHOT_FINISH, NULL);
                m_captureTimer->stop();               
            }
            break;
        default:
            break;
    }        

}

void OSDCamContShotState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    if(m_keyDown)
    {
        m_keyDown = VFX_FALSE;                
        evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CONT_SHOT_FINISH, NULL);
        m_captureTimer->stop();      
        return;
    }
    m_capture->setRot(m_cntx.isHorzUI, isHorz, isMirror);

#endif
}

VfxBool OSDCamContShotState::onPenInput(VfxPenEvent & event)
{
    return CamcoOSDState::onPenInput(event);
}


VfxBool OSDCamContShotState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA: 
        case VFX_KEY_CODE_ENTER:              
        { 
            if(event.type == VFX_KEY_EVENT_TYPE_UP)        
            {
                if(m_keyDown)
                {            
                    m_keyDown = VFX_FALSE;              
                    evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_CONT_SHOT_FINISH, NULL);
                    m_captureTimer->stop();                 
                }
            }  

            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void OSDRecPreviewState::onInit(void)
{
    CamcoOSDState::onInit();

    // create UI
    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableImageFrame, this);         
      
    VFX_OBJ_CREATE(m_zoomer, VappCamcoCpSlider, this);  
    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableFrame, this);       
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableFrame, this);   
    VFX_OBJ_CREATE(m_galleryContainer, VappCamcoCpRotatableFrame, this);          
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);      
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, m_galleryContainer);    
    VFX_OBJ_CREATE(m_usedSensor, VappCamcoCpRotatableButton, this);
    VFX_OBJ_CREATE(m_unusedSensor, VappCamcoCpRotatableImageButton, this);           

    VFX_OBJ_CREATE(m_indicatorMsgBg, VappCamcoCpRotatableImageFrame, this); 

    VFX_OBJ_CREATE(m_recordableTime, VappCamcoCpRotatableTextFrame, this);           
    VFX_OBJ_CREATE(m_indicatorMsg, VappCamcoCpRotatableTextFrame, this);           

    VFX_OBJ_CREATE(m_coverFrame, VappCamcoCpRotatableFrame, this);     

    VFX_OBJ_CREATE(m_settingBar, VappCamcoCpBaseMenu, this);   
    VFX_OBJ_CREATE(m_directSettingControl, VappCamcoCpCircleMenu, this);   
    VFX_OBJ_CREATE(m_advanceSettingControl, VappCamcoCpAdvanceMenu, this);   
    
    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        VFX_OBJ_CREATE(m_statusInd[i], VappCamcoCpRotatableImageFrame, this);              
    }

    for(VfxU8 i = 0; i < VAPP_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        VFX_OBJ_CREATE(m_focusRegion[i], VappCamcoCpRect, this);
        m_focusRegion[i]->setAnchor(0.5, 0.5);
    }
    VFX_OBJ_CREATE(m_indicatorImage, VfxImageFrame, this);
    m_indicatorImage->setAnchor(0.5, 0.5);
    m_indicatorImage->setResId(IMG_ID_VAPP_CAMCO_STATUS_AF_MACRO_ICON);
    m_indicatorImage->setAutoAnimate(VFX_FALSE);
    m_indicatorImage->setHidden(VFX_TRUE);
    m_confirmPopup = NULL;
    
    
    // init UI
    m_rightBar->setAnchor(0.5, 0.5);      
    m_rightBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));   
    
    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON,IMG_ID_VAPP_CAMCO_GALLERY_ICON);
    m_gallery->setAnchor(0.5, 0.5);
    m_gallery->setImage(SI);
    m_gallery->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_gallery->setAutoAnimate(VFX_FALSE);
    m_gallery->setIsEffect(VFX_TRUE);
    m_gallery->setEffectSize(VfxSize(52, 52));    
    m_galleryContainer->setAnchor(0.5, 0.5);
    m_galleryContainer->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);    
    m_galleryContent->setIsUnhittable(VFX_TRUE);
    m_galleryContent->setBorderColor(VFX_COLOR_BLACK);
    m_galleryContent->setBorderWidth(0);    
    m_galleryContent->setAnchor(0.5, 0.5);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);   
    m_galleryContent->setPos(m_galleryContainer->getSize().width>>1, m_galleryContainer->getSize().height>>1);

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON,IMG_ID_VAPP_CAMCO_RECORD_REC_ICON);   
    m_usedSensor->setAnchor(0.5, 0.5);
    m_usedSensor->setImage(SI);
    m_usedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_usedSensor->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_usedSensor->setMargin(0, 0, 0, 0);
    m_usedSensor->setBgColor(VFX_COLOR_TRANSPARENT);
    m_usedSensor->setBgImageList(VcpStateImage(0));
    m_usedSensor->setAutoAnimate(VFX_FALSE);

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR,IMG_ID_VAPP_CAMCO_SWITCH_SENSOR);
    m_unusedSensor->setAnchor(0.5, 0.5);
    m_unusedSensor->setImage(SI);
    m_unusedSensor->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);  
    m_unusedSensor->setAutoAnimate(VFX_FALSE);
    m_unusedSensor->setIsEffect(VFX_TRUE);
    m_unusedSensor->setEffectSize(VfxSize(52, 52));    

    m_switcher->setAnchor(0.5, 0.5);
    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setImage(SI);
    m_switcher->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);  
    m_switcher->setAutoAnimate(VFX_FALSE);
    m_switcher->setEffectSize(VfxSize(52, 52));   

    m_switcherRec->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC)); 
    m_switcherRec->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_REC).getSize());     
    m_switcherRec->setAnchor(0.5, 0.5);       
    m_switcherRec->setAutoAnimate(VFX_FALSE);
    m_switcherRec->setIsUnhittable(VFX_TRUE);

    m_switcherCam->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM)); 
    m_switcherCam->setSize(VfxImageSrc(IMG_ID_VAPP_CAMCO_SWITCHER_CAM).getSize());     
    m_switcherCam->setAnchor(0.5, 0.5);    
    m_switcherCam->setAutoAnimate(VFX_FALSE);
    m_switcherCam->setIsUnhittable(VFX_TRUE);

    m_zoomer->setCpImage(VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IND_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_BAR_ICON));
    m_zoomer->setAnchor(0.5, 0.5);    
    m_zoomer->setValueRange(0, 100);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setCurveR(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_coverFrame->setAnchor(0.5, 0.5);    
    m_coverFrame->setOpacity(0.5);
    m_coverFrame->setBgColor(VFX_COLOR_BLACK);
    
    m_settingBar->setFocused(VFX_TRUE);    
    m_settingBar->setAutoAnimate(VFX_FALSE);           

    m_directSettingControl->setAnchor(0, 0.5);
    m_directSettingControl->setAutoAnimate(VFX_FALSE);
    m_directSettingControl->setBgColor(VRT_COLOR_TRANSPARENT);
    m_directSettingControl->setFocused(VFX_TRUE);  

    m_advanceSettingControl->setAnchor(0, 0.5);
    m_advanceSettingControl->setAutoAnimate(VFX_FALSE);                
    m_advanceSettingControl->setBgColor(VRT_COLOR_TRANSPARENT);
    m_advanceSettingControl->setFocused(VFX_TRUE);   

    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        m_statusInd[i]->setAnchor(0.5, 0.5);
        m_statusInd[i]->setAutoAnimate(VFX_FALSE);            
    }    

    VfxFontDesc font;    
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)    
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(25);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#else
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#endif
    font.effect = VFX_FE5_1;
    m_recordableTime->setFont(font);   
    m_recordableTime->setAnchor(0.5, 0.5);
    m_recordableTime->setAutoAnimate(VFX_FALSE);
    m_recordableTime->setColor(VFX_COLOR_WHITE);    
    m_recordableTime->setOpacity(0.8);

    m_indicatorMsg->setAnchor(0.5, 0.5);
    m_indicatorMsg->setAutoAnimate(VFX_FALSE);
    m_indicatorMsg->setColor(VFX_COLOR_WHITE);    
    m_indicatorMsg->setOpacity(0.8);

    m_indicatorMsgBg->setAnchor(0.5, 0.5);
    m_indicatorMsgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);        
    m_indicatorMsgBg->setResId(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON);

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW;      

    m_isClicking = VFX_FALSE;

    setAutoAnimate(VFX_FALSE);

    // Create an timer
    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_fadeOutScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);     
    
    // set action handler
    m_settingBar->m_signalEnterEffectStart.connect(this, &OSDRecPreviewState::onBeforeSettingEnter);    
    m_settingBar->m_signalItemSelected.connect(this, &OSDRecPreviewState::onSettingEnter);
    m_settingBar->m_signalMenuMoved.connect(this, &OSDRecPreviewState::onSettingTraverse);   
    m_settingBar->m_signalLeaveEffectDone.connect(this, &OSDRecPreviewState::onCPEffctDoneTick2);        
    m_directSettingControl->m_signalClicked.connect(this, &OSDRecPreviewState::onDirectSettingLeave);    
    m_directSettingControl->m_signalItemSet.connect(this, &OSDRecPreviewState::onSettingSet);   
    m_directSettingControl->m_signalLeaveEffectDone.connect(this, &OSDRecPreviewState::onCPEffctDoneTick);       
    m_advanceSettingControl->m_signalClicked.connect(this, &OSDRecPreviewState::onAdvanceSettingLeave);
    m_advanceSettingControl->m_signalTraversed.connect(this, &OSDRecPreviewState::onAdvanceSettingTraverse);    
    m_advanceSettingControl->m_signalItemSelected.connect(this, &OSDRecPreviewState::onAdvanceSettingSelected);          
    m_advanceSettingControl->m_signalLeaveEffectDone.connect(this, &OSDRecPreviewState::onCPEffctDoneTick);     
    
    m_switcher->m_signalClicked.connect(this, &OSDRecPreviewState::onSwitchAppClicked);   
    m_gallery->m_signalClicked.connect(this, &OSDRecPreviewState::onGalleryClicked);   
    m_unusedSensor->m_signalClicked.connect(this, &OSDRecPreviewState::onSwitchSensorClicked);   
    m_usedSensor->m_signalClicked.connect(this, &OSDRecPreviewState::onCaptureClicked);   
    m_usedSensor->m_signalStateChanged.connect(this, &OSDRecPreviewState::onCaptured);
    m_zoomer->m_signalValueChanged.connect(this, &OSDRecPreviewState::onZooming);

    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecPreviewState::onResetTimerTick);
    m_fadeOutScreenTimer->m_signalTick.connect(this, &OSDRecPreviewState::setClearModeinternal);    

};


void OSDRecPreviewState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    CamcoOSDState::enterState(param);
    
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_preview_param_struct));

    // updat UI depend setting
    updateSettingBar(0);

    updateIcon();
   
    updateRemainSizeParam(m_cntx.recordableTime);

    m_zoomer->setValueRange(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM), m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));
    // cannot zoom
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height);
    
    if(!m_cntx.setting->IsExtSetting())
    {

        if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L"") && m_cntx.isRestartEnter)
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);               

            // find the appid for mdi interface
            mmi_id appId = 0;
            VfxApp *pApp = NULL;
            for(VfxObject *pObj = this; pObj != NULL; pObj = pObj->getParent())
            {
                pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
                if(pApp != NULL)
                {
                    appId = pApp->getGroupId();
                }
            }       
            VFX_ASSERT(appId != 0);       

            // get the first frame of last rec video file
            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);  
            
            mdi_video_info_struct video_info;        
            MDI_RESULT ret = mdi_video_ply_open_clip_file(appId, (CHAR *)m_cntx.previousFileName, &video_info);  

            if (ret == MDI_RES_VDOPLY_SUCCEED)    
            {
                gdi_handle handleT;
                
                gdi_layer_create_cf_using_outside_memory(
                    GDI_COLOR_FORMAT_16,
                    0,
                    0,
                    m_galleryContent->getSize().width,
                    m_galleryContent->getSize().height,
                    &handleT,
                    (U8*)m_cntx.buffer,
                    m_galleryContent->getSize().width*m_galleryContent->getSize().height*2);   

                gdi_layer_push_and_set_active(handleT);    
        
                ret = mdi_video_ply_seek_and_get_frame(0, handleT);

                gdi_layer_pop_and_restore_active(); 
        
                mdi_video_ply_close_clip_file();
        
                gdi_layer_free(handleT);

            }
            else
            {
                memset(m_cntx.buffer, 0, m_galleryContent->getSize().width * m_galleryContent->getSize().height * 2);
            }  
            
            VfxImageBuffer imageBuf;
            imageBuf.ptr = (VfxU8*)m_cntx.buffer;
            imageBuf.pitchBytes = m_galleryContent->getSize().width * 2;
            imageBuf.width = m_galleryContent->getSize().width;
            imageBuf.height = m_galleryContent->getSize().height;
            imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;     

            m_galleryContent->setImgContent(VfxImageSrc(imageBuf));            


        }
        else
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
        }
    }
    m_resetScreenTimer->setStartDelay(CAMCO_REC_PREVIEW_RESET_TIME);
    m_resetScreenTimer->start();

    m_fadeOutScreenTimer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    
    if(m_cntx.isCleanModeEnter)   
    {
        setClearModeinternal(NULL);
    }        
    else
    {
        setNormalMode();
        m_resetScreenTimer->start();
    } 
    
    if(m_confirmPopup != NULL)
        VFX_OBJ_CLOSE(m_confirmPopup);      

    rotateOSD(m_isHorz, m_isMirror);

};

void OSDRecPreviewState::exitState(void)
{
    CamcoOSDState::exitState();

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_ADSETTING;        
    }
    else
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;    
    }  
    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;
    
    m_resetScreenTimer->stop();      
    m_zoomingTimer->stop();            
    VFX_OBJ_CLOSE(m_confirmPopup);

    m_usedSensor->setOpacity(1);
}

void OSDRecPreviewState::updateRemainSizeParam(VfxU32 v)
{
    if(v > (99 * 60 * 60 + 59 * 60 + 59))
        v = (99 * 60 * 60 + 59 * 60 + 59);
    
    VfxU32 ss = v%60;    
    VfxU32 mm = v/60;
    VfxU32 hh = mm/60;
    mm = mm%60;
    if(hh > 99) hh = 99;

    VfxWChar caption[10] = {0};
    kal_wsprintf(caption, "%02d:%02d:%02d", hh, mm, ss);
    m_recordableTime->setString(VFX_WSTR_MEM(caption));
}

void OSDRecPreviewState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    // we dont do rotation when in advance setting
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;

    // ============================================================
    // enable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        m_settingBar->setAutoAnimate(VFX_TRUE);
        
        m_directSettingControl->setAutoAnimate(VFX_TRUE);
        m_advanceSettingControl->setAutoAnimate(VFX_TRUE);
        m_switcherRec->setAutoAnimate(VFX_TRUE);
        m_switcherCam->setAutoAnimate(VFX_TRUE);  
        m_zoomer->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_TRUE);
        m_galleryContent->setAutoAnimate(VFX_TRUE);

        m_usedSensor->setAutoAnimate(VFX_TRUE);
        m_unusedSensor->setAutoAnimate(VFX_TRUE);

        //m_rightBar->setAutoAnimate(VFX_TRUE);
        
        //m_imageFrame->setAutoAnimate(VFX_TRUE);

        for(VfxU32 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
        {
            m_statusInd[i]->setAutoAnimate(VFX_TRUE);
        }
        
        for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
        {    
            //m_faceDetectRegion[i]->setAutoAnimate(VFX_TRUE);
            //m_smileDetectRegion[i]->setAutoAnimate(VFX_TRUE);
        }
        m_recordableTime->setAutoAnimate(VFX_TRUE);

        m_indicatorMsg->setAutoAnimate(VFX_TRUE);
        m_indicatorMsgBg->setAutoAnimate(VFX_TRUE);
    }    
    // ============================================================
    // enable autoanimation
    // ============================================================

    m_settingBar->setRot(isHorzUI(), isHorz, isMirror);  
    
    m_directSettingControl->setRot(isHorzUI(), isHorz, isMirror);  
    m_advanceSettingControl->setRot(isHorzUI(), isHorz, isMirror);  
    m_switcherRec->setRot(isHorzUI(), isHorz, isMirror);
    m_switcherCam->setRot(isHorzUI(), isHorz, isMirror);      
    m_zoomer->setRot(isHorzUI(), isHorz, isMirror);  

    //m_gallery->setRot(isHorzUI(), isHorz, isMirror);  
    if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setRot(isHorzUI(), isHorz, isMirror);  
    }
    
    m_usedSensor->setRot(isHorzUI(), isHorz, isMirror);  
    m_unusedSensor->setRot(isHorzUI(), isHorz, isMirror);  

    //m_rightBar->setRot(isHorzUI(), isHorz, isMirror);
    
    //m_imageFrame->setRot(isHorzUI(), isHorz, isMirror);

    for(VfxU32 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER ;i++)
    {
        m_statusInd[i]->setRot(isHorzUI(), isHorz, isMirror);
    }
    
    for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
    {    
        //m_faceDetectRegion[i]->setRot(isHorzUI(), isHorz, isMirror);
        //m_smileDetectRegion[i]->setRot(isHorzUI(), isHorz, isMirror);
    }
    m_recordableTime->setRot(isHorzUI(), isHorz, isMirror);

    m_indicatorMsg->setRot(isHorzUI(), isHorz, isMirror);
    m_indicatorMsgBg->setRot(isHorzUI(), isHorz, isMirror);

    // ============================================================
    // disable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        m_settingBar->setAutoAnimate(VFX_FALSE);

        m_directSettingControl->setAutoAnimate(VFX_FALSE);
        m_advanceSettingControl->setAutoAnimate(VFX_FALSE);
        m_switcherRec->setAutoAnimate(VFX_FALSE);
        m_switcherCam->setAutoAnimate(VFX_FALSE);      
        m_zoomer->setAutoAnimate(VFX_FALSE);

        m_gallery->setAutoAnimate(VFX_FALSE);
        m_galleryContent->setAutoAnimate(VFX_FALSE);

        m_usedSensor->setAutoAnimate(VFX_FALSE);
        m_unusedSensor->setAutoAnimate(VFX_FALSE);

        //m_rightBar->setAutoAnimate(VFX_FALSE);

        //m_imageFrame->setAutoAnimate(VFX_FALSE);

        for(VfxU32 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
        {
            m_statusInd[i]->setAutoAnimate(VFX_FALSE);
        }

        for(VfxU8 i = 0; i < VAPP_CAMCO_SUPPORT_FACE_NUM; i++)
        {    
            //m_faceDetectRegion[i]->setAutoAnimate(VFX_FALSE);
            //m_smileDetectRegion[i]->setAutoAnimate(VFX_FALSE);
        }
        m_recordableTime->setAutoAnimate(VFX_FALSE);

        m_indicatorMsg->setAutoAnimate(VFX_FALSE);
        m_indicatorMsgBg->setAutoAnimate(VFX_FALSE);
    }
    // ============================================================
    // disable autoanimation
    // ============================================================
#endif
}

void OSDRecPreviewState::updateIndicatorMsg(VfxU32 s)
{
    m_cntx.indicatorStringID = s;

    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));      

    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_NAME_ICON).getSize().height);

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
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

void OSDRecPreviewState::cleanFocus(void)
{
    for(VfxU8 i = 0; i < VAPP_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        m_focusRegion[i]->setSize(0, 0);
    }
    m_indicatorImage->setHidden(VFX_TRUE);
}
void OSDRecPreviewState::setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region)
{
    if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_NORMAL);
    else if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSED)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_SUCCESS);
    else if(region.type == VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL)
        m_focusRegion[idx]->setMode(VAPP_CAMCO_CP_RECT_TYPE_AF, VAPP_CAMCO_CP_RECT_MODE_FAIL);
    if(region.type != VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO)
    {
        m_focusRegion[idx]->setSize(region.w, region.h);
        m_focusRegion[idx]->setPos(region.center_x, region.center_y);
        m_indicatorImage->setHidden(VFX_TRUE);
    }
    else
    {
        if(m_isHorz)
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
void OSDRecPreviewState::setNormalMode(void)
{

    if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL || m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_COMMON_ONLY)
        m_settingBar->setHidden(VFX_FALSE);  
    else
        m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_TRUE);             
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

    m_coverFrame->setHidden(VFX_TRUE);
    
    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);    
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);        
    }
    
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)    
        m_zoomer->setHidden(VFX_FALSE);             
    else
        m_zoomer->setHidden(VFX_TRUE);                     
    
    if(!m_cntx.setting->IsExtSetting())    
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContainer->setHidden(VFX_FALSE);      
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);   
        m_galleryContainer->setHidden(VFX_TRUE);   
    }
    
    m_usedSensor->setHidden(VFX_FALSE);      

#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif

    m_rightBar->setHidden(VFX_FALSE);

    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {  
        m_statusInd[0]->setHidden(VFX_FALSE);    
    }
    else
    {  
        m_statusInd[0]->setHidden(VFX_TRUE);    
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOEV) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {      
        m_statusInd[1]->setHidden(VFX_FALSE);    
    }   
    else
    {  
        m_statusInd[1]->setHidden(VFX_TRUE);    
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_AFRANGE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {     
        m_statusInd[2]->setHidden(VFX_FALSE);    
    }
    else
    {  
        m_statusInd[2]->setHidden(VFX_TRUE);    
    }

    // rec size may disable due to custom config, always show
    //if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    //{ 
        m_statusInd[3]->setHidden(VFX_FALSE);    
    //}
    //else
    //{  
    //    m_statusInd[3]->setHidden(VFX_TRUE);    
    //}
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_ISO) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[4]->setHidden(VFX_FALSE);    
    }
    else
    {  
        m_statusInd[4]->setHidden(VFX_TRUE);    
    }
    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[5]->setHidden(VFX_FALSE);    
    }
    else
    {  
        m_statusInd[5]->setHidden(VFX_TRUE);    
    }

    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    { 
        m_statusInd[6]->setHidden(VFX_FALSE);    
    }
    else
    {  
        m_statusInd[6]->setHidden(VFX_TRUE);    
    }    
    
    m_recordableTime->setHidden(VFX_FALSE);
    
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

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;
    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();      

    rotateOSD(m_isHorz, m_isMirror);

}

void OSDRecPreviewState::setClearMode(void)
{
    m_previousMode = m_mode;
    m_mode = VAPP_CAMCO_PREVIEW_MODE_TRANSITION;

    VfxAutoAnimate::begin();    
        VfxAutoAnimate::setDuration(1500);
        layout();    
    VfxAutoAnimate::commit();

    m_fadeOutScreenTimer->start();   
      
}

void OSDRecPreviewState::setClearModeinternal(VfxTimer *source)
{

    m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_TRUE);       
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

    m_coverFrame->setHidden(VFX_TRUE);
    
    if(!m_cntx.setting->IsExtSetting())    
    {
        m_switcher->setHidden(VFX_FALSE); 
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);                
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);   
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);                
    }     
    m_zoomer->setHidden(VFX_TRUE);             

    if(!m_cntx.setting->IsExtSetting())    
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContainer->setHidden(VFX_FALSE);      
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);      
        m_galleryContainer->setHidden(VFX_TRUE);      
    }  

    m_usedSensor->setHidden(VFX_FALSE);      
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif

    m_rightBar->setHidden(VFX_FALSE);
    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }

    m_recordableTime->setHidden(VFX_TRUE);

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

    m_mode = VAPP_CAMCO_PREVIEW_MODE_CLEAR;
    
    layout();       
    
    if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_previousMode = VAPP_CAMCO_PREVIEW_MODE_CLEAR;
        m_cntx.setting->needRestartPreview();        
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL);             
    }
    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();       
    m_settingBar->setFocusOnCenter();

    rotateOSD(m_isHorz, m_isMirror);

}

void OSDRecPreviewState::setAdvanceSettingMode(void)
{

    m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_TRUE);             
    m_advanceSettingControl->setHidden(VFX_FALSE);                  

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    m_coverFrame->setHidden(VFX_FALSE);
#else    
    m_coverFrame->setHidden(VFX_TRUE);
#endif

    m_switcher->setHidden(VFX_TRUE); 
    m_switcherRec->setHidden(VFX_TRUE);
    m_switcherCam->setHidden(VFX_TRUE);   
    m_zoomer->setHidden(VFX_TRUE);             
    
    m_gallery->setHidden(VFX_TRUE); 
    m_galleryContainer->setHidden(VFX_TRUE); 
    m_usedSensor->setHidden(VFX_TRUE);      
    m_unusedSensor->setHidden(VFX_TRUE);
    
    m_rightBar->setHidden(VFX_TRUE);

    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }
    
    m_recordableTime->setHidden(VFX_TRUE);
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);          
    
    m_mode = VAPP_CAMCO_PREVIEW_MODE_ADSETTING;
   
    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();   
    
    rotateOSD(m_isHorz, m_isMirror);

}
    
void OSDRecPreviewState::setDirectSettingMode(VfxObject * target)
{
    m_previousModeDirSettingObj = target;

    m_settingBar->setHidden(VFX_TRUE);      
    m_directSettingControl->setHidden(VFX_FALSE);             
    m_advanceSettingControl->setHidden(VFX_TRUE);                  

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    m_coverFrame->setHidden(VFX_FALSE);
#else    
    m_coverFrame->setHidden(VFX_TRUE);
#endif

    
    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);         
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);      
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);
    }

    m_zoomer->setHidden(VFX_TRUE);             
    
    if(!m_cntx.setting->IsExtSetting()) 
    {
        m_gallery->setHidden(VFX_FALSE);      
        m_galleryContainer->setHidden(VFX_FALSE);      
    }
    else
    {
        m_gallery->setHidden(VFX_TRUE);   
        m_galleryContainer->setHidden(VFX_TRUE);   
    }
    
    m_usedSensor->setHidden(VFX_FALSE);      
#ifdef DUAL_CAMERA_SUPPORT    
    m_unusedSensor->setHidden(VFX_FALSE);    
#else
    m_unusedSensor->setHidden(VFX_TRUE);    
#endif

    m_rightBar->setHidden(VFX_FALSE);

    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {    
        m_statusInd[i]->setHidden(VFX_TRUE);        
    }

#if defined(VAPP_CAMCO_OSD_LAYOUT_QVGA) || defined (VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    m_recordableTime->setHidden(VFX_TRUE);
#else
    m_recordableTime->setHidden(VFX_FALSE);
#endif    
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);          

    m_mode = VAPP_CAMCO_PREVIEW_MODE_DIRSETTING;

    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();  

    rotateOSD(m_isHorz, m_isMirror);

}


void OSDRecPreviewState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

    if(isHorzUI())
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));               
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1);
            m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_unusedSensor->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);   
            m_switcher->setPos(sp->switchAppPos[0], sp->switchAppPos[1]);    
            m_switcherRec->setPos(m_switcher->getPos().x, m_switcher->getPos().y - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().height>>1));
            m_switcherCam->setPos(m_switcher->getPos().x, m_switcher->getPos().y + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().height>>1));            
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(1);
            
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            m_coverFrame->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL, VfxSize(sp->settingBarSize[0],sp->settingBarSize[1]));

            m_directSettingControl->setVerticalMode(VFX_TRUE);  
            m_directSettingControl->setAnchor(0, 0.5);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[0],sp->circleControlSize[1]);    
            m_directSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_recordableTime->setPos(g_vapp_camco_skin.remainNuminfoHPos[0], g_vapp_camco_skin.remainNuminfoHPos[1]);
            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_statusInd[0]->setPos(sp->statusIconPos[0][0],  sp->statusIconPos[0][1]);
            m_statusInd[1]->setPos(sp->statusIconPos[1][0],  sp->statusIconPos[1][1]);
            m_statusInd[2]->setPos(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]);
            m_statusInd[3]->setPos(sp->statusIconPos[3][0],  sp->statusIconPos[3][1]);    
            m_statusInd[4]->setPos(sp->statusIconPos[4][0],  sp->statusIconPos[4][1]);
            m_statusInd[5]->setPos(sp->statusIconPos[5][0],  sp->statusIconPos[5][1]);
            m_statusInd[6]->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);            

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
            
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR || m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            
            m_rightBar->setPos(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1);
            m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
            
            m_gallery->setPos(sp->galleryPos[0], sp->galleryPos[1]);    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(sp->capturePos[0], sp->capturePos[1]);    
            m_unusedSensor->setPos(sp->switchSensorPos[0], sp->switchSensorPos[1]);   
            m_switcher->setPos(sp->switchAppPos[0], sp->switchAppPos[1]);    
            m_switcherRec->setPos(m_switcher->getPos().x, m_switcher->getPos().y - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().height>>1));
            m_switcherCam->setPos(m_switcher->getPos().x, m_switcher->getPos().y + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().height>>1));            
            m_zoomer->setPos(sp->zoomControlPos[0],sp->zoomControlPos[1]);
            m_zoomer->setOpacity(0);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            m_coverFrame->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0 - CAMCO_REC_PREVIEW_SHIFT_DIS, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL, VfxSize(sp->settingBarSize[0],sp->settingBarSize[1]));
            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));   

            m_directSettingControl->setVerticalMode(VFX_TRUE);   
            m_directSettingControl->setAnchor(0, 0.5);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[0],sp->circleControlSize[1]);    
            m_directSettingControl->setPos(0 - CAMCO_REC_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1);    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(0 - CAMCO_REC_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_recordableTime->setPos(g_vapp_camco_skin.remainNuminfoHPos[0], g_vapp_camco_skin.remainNuminfoHPos[1]);            
            m_indicatorMsg->setPos(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2);
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_statusInd[0]->setPos(sp->statusIconPos[0][0],  sp->statusIconPos[0][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_statusInd[1]->setPos(sp->statusIconPos[1][0],  sp->statusIconPos[1][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_statusInd[2]->setPos(sp->statusIconPos[2][0],  sp->statusIconPos[2][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_statusInd[3]->setPos(sp->statusIconPos[3][0],  sp->statusIconPos[3][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);    
            m_statusInd[4]->setPos(sp->statusIconPos[4][0],  sp->statusIconPos[4][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_statusInd[5]->setPos(sp->statusIconPos[5][0],  sp->statusIconPos[5][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_statusInd[6]->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1] + CAMCO_REC_PREVIEW_SHIFT_DIS);

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);           
  
        }
            
    }    
    else       
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL || m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);   

            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));              
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1));
            m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
            
            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));    
            m_unusedSensor->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));   
            m_switcher->setPos(coordTransform2Vertical(sp->switchAppPos[0], sp->switchAppPos[1]));    
            m_switcherRec->setPos(m_switcher->getPos().x + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);
            m_switcherCam->setPos(m_switcher->getPos().x - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);            
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0],sp->zoomControlPos[1]));
            m_zoomer->setOpacity(1);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            m_coverFrame->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_NONE, VfxSize(sp->settingBarSize[1],sp->settingBarSize[0])); 

            m_directSettingControl->setVerticalMode(VFX_FALSE);   
            m_directSettingControl->setAnchor(0.5, 0);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[1],sp->circleControlSize[0]);    
            m_directSettingControl->setPos(coordTransform2Vertical(0, GDI_LCD_WIDTH>>1));    

            m_advanceSettingControl->setAnchor(0.5, 0);
            m_advanceSettingControl->setPos(0, GDI_LCD_WIDTH>>1);    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_recordableTime->setPos(coordTransform2Vertical(g_vapp_camco_skin.remainNuminfoVPos[0], g_vapp_camco_skin.remainNuminfoVPos[1]));            
            m_indicatorMsg->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_statusInd[0]->setPos(coordTransform2Vertical(sp->statusIconPos[0][0],  sp->statusIconPos[0][1]));
            m_statusInd[1]->setPos(coordTransform2Vertical(sp->statusIconPos[1][0],  sp->statusIconPos[1][1]));
            m_statusInd[2]->setPos(coordTransform2Vertical(sp->statusIconPos[2][0],  sp->statusIconPos[2][1]));
            m_statusInd[3]->setPos(coordTransform2Vertical(sp->statusIconPos[3][0],  sp->statusIconPos[3][1]));    
            m_statusInd[4]->setPos(coordTransform2Vertical(sp->statusIconPos[4][0],  sp->statusIconPos[4][1]));
            m_statusInd[5]->setPos(coordTransform2Vertical(sp->statusIconPos[5][0],  sp->statusIconPos[5][1]));
            m_statusInd[6]->setPos(coordTransform2Vertical(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]));

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);           
   
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR || m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);   
            
            m_rightBar->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1));
            m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
            
            m_gallery->setPos(coordTransform2Vertical(sp->galleryPos[0], sp->galleryPos[1]));    
            m_galleryContainer->setPos(m_gallery->getPos());
            m_usedSensor->setPos(coordTransform2Vertical(sp->capturePos[0], sp->capturePos[1]));    
            m_unusedSensor->setPos(coordTransform2Vertical(sp->switchSensorPos[0], sp->switchSensorPos[1]));   
            m_switcher->setPos(coordTransform2Vertical(sp->switchAppPos[0], sp->switchAppPos[1]));    
            m_switcherRec->setPos(m_switcher->getPos().x + (m_switcher->getSize().height>>1) + (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);
            m_switcherCam->setPos(m_switcher->getPos().x - (m_switcher->getSize().height>>1) - (m_switcherRec->getSize().width>>1), m_switcher->getPos().y);            
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0], sp->zoomControlPos[1]));
            m_zoomer->setOpacity(0);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);

            m_coverFrame->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            m_coverFrame->setPos(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2);    

            m_settingBar->setAnchor(0, 0);
            m_settingBar->setPos(0, 0 - CAMCO_REC_PREVIEW_SHIFT_DIS);
            m_settingBar->setMode(VAPP_CAMCO_CP_BM_MODE_IS_NONE, VfxSize(sp->settingBarSize[1],sp->settingBarSize[0]));
            m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));   

            m_directSettingControl->setVerticalMode(VFX_FALSE);   
            m_directSettingControl->setAnchor(0.5, 0);
            m_directSettingControl->setBounds(0,0,sp->circleControlSize[1],sp->circleControlSize[0]);    
            m_directSettingControl->setPos(coordTransform2Vertical(0 - CAMCO_REC_PREVIEW_SHIFT_DIS, GDI_LCD_WIDTH>>1));    

            m_advanceSettingControl->setAnchor(0, 0.5);
            m_advanceSettingControl->setPos(coordTransform2Vertical(0 - CAMCO_REC_PREVIEW_SHIFT_DIS, (GDI_LCD_WIDTH>>1)));    
            m_advanceSettingControl->setBounds(0, 0, sp->menuControlSize[0], sp->menuControlSize[1]);   

            m_recordableTime->setPos(coordTransform2Vertical(g_vapp_camco_skin.remainNuminfoVPos[0], g_vapp_camco_skin.remainNuminfoVPos[1]));            
            m_indicatorMsg->setPos(coordTransform2Vertical(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));
            m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

            m_statusInd[0]->setPos(coordTransform2Vertical(sp->statusIconPos[0][0],  sp->statusIconPos[0][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));
            m_statusInd[1]->setPos(coordTransform2Vertical(sp->statusIconPos[1][0],  sp->statusIconPos[1][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));
            m_statusInd[2]->setPos(coordTransform2Vertical(sp->statusIconPos[2][0],  sp->statusIconPos[2][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));
            m_statusInd[3]->setPos(coordTransform2Vertical(sp->statusIconPos[3][0],  sp->statusIconPos[3][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));    
            m_statusInd[4]->setPos(coordTransform2Vertical(sp->statusIconPos[4][0],  sp->statusIconPos[4][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));
            m_statusInd[5]->setPos(coordTransform2Vertical(sp->statusIconPos[5][0],  sp->statusIconPos[5][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));
            m_statusInd[6]->setPos(coordTransform2Vertical(sp->statusIconPos[6][0],  sp->statusIconPos[6][1] + CAMCO_REC_PREVIEW_SHIFT_DIS));

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);           

        }
    }

    invalidate();

}

void OSDRecPreviewState::updateIcon(void)
{

    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOSCENEMODE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {  
        m_statusInd[0]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_VDOSCENEMODE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOEV) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {      
        m_statusInd[1]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_VDOEV)));
    }    
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_AFRANGE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {     
        m_statusInd[2]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_AFRANGE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[3]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_RECSIZE)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_ISO) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[4]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_ISO)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_LIMIT) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[5]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_LIMIT)));
    }
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_TIMELAPSE) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    { 
        m_statusInd[6]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_TIMELAPSE)));
    }

}

void OSDRecPreviewState::updateSettingBar(VfxS16 isForceDirection)
{
    VfxU32 prevFocusID = m_settingBar->getCellID(m_settingBar->getFocus());     
    VfxS32 prevFocusIdx = -1;   
    VfxU16 settingCount = 0;
    VcpStateImage     imgList;
    if((isHorzUI() && isForceDirection == 0) || (isForceDirection > 0))
    {
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_VDOSCENEMODE) > 1)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_VDOSCENEMODE)
            {
                prevFocusIdx = settingCount;
            }        
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMSCENEMODE));                
            imgList.setImage(is, is, is, is);
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_VDOSCENEMODE, imgList);        
        }
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_WB) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_WB) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_WB)
            {
                prevFocusIdx = settingCount;
            }       
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB));              
            imgList.setImage(is, is, is, is);           
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_WB, imgList);  
        }   
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOEV) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_VDOEV) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_VDOEV)
            {
                prevFocusIdx = settingCount;
            }  
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_VDOEV));              
            imgList.setImage(is, is, is, is);     
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_VDOEV, imgList);  
        }         
        if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_MISC)
            {
                prevFocusIdx = settingCount;
            } 
            VfxImageSrc is = VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_ICON);                 
            imgList.setImage(is, is, is, is);               
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_MISC, imgList);          
        }    
    }
    else
    {     
        if(m_cntx.settingLevel == VAPP_CAMCO_OSD_SETTING_FULL)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_MISC)
            {
                prevFocusIdx = settingCount;
            }    
            VfxImageSrc is = VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_ICON);  
            imgList.setImage(is, is, is, is);                 
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_MISC, imgList);          
        }         
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOEV) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_VDOEV) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_VDOEV)
            {
                prevFocusIdx = settingCount;
            }        
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_VDOEV));               
            imgList.setImage(is, is, is, is);        
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_VDOEV, imgList);  
        }           
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_WB) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_WB) > 1)
        {   
            if(prevFocusID == VAPP_CAMCO_SETTING_WB)
            {
                prevFocusIdx = settingCount;
            }    
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB));                  
            imgList.setImage(is, is, is, is); 
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_WB, imgList);  
        }          
        if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_VDOSCENEMODE) == VAPP_CAMCO_SETTING_CAP_ENABLED && m_cntx.setting->getSettingCount(VAPP_CAMCO_SETTING_VDOSCENEMODE) > 1)
        {
            if(prevFocusID == VAPP_CAMCO_SETTING_VDOSCENEMODE)
            {
                prevFocusIdx = settingCount;
            }   
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_CAMSCENEMODE));             
            imgList.setImage(is, is, is, is); 
            m_settingBar->setCellData(settingCount++, VAPP_CAMCO_SETTING_VDOSCENEMODE, imgList);        
        }    
    }
    m_settingBar->setCount(settingCount);    
    if(prevFocusIdx == -1 || prevFocusIdx > (settingCount >>1))
        m_settingBar->setFocusOnCenter();     
    else
        m_settingBar->setFocusandCheck(prevFocusIdx);   

}

void OSDRecPreviewState::onSettingTraverse(VfxU32 ID)
{   
    refreshAutoExitTimer();   

    m_resetScreenTimer->start();     
    m_fadeOutScreenTimer->stop();         
}

void OSDRecPreviewState::onBeforeSettingEnter(VfxU32 ID)
{
    refreshAutoExitTimer();   

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_STOP, NULL);     
}

void OSDRecPreviewState::onSettingEnter(VfxU32 ID)
{  
    refreshAutoExitTimer();   

    if(ID == VAPP_CAMCO_SETTING_MISC)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_ENTER_ADVANCE_SETTING);     
        
        if(!isHorzUI())
        {    
            m_cntx.setting->needRestartPreview();    
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_FORCE_HORZ, NULL);       
        }
        else
        {
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_NOTIFY_HORZ, NULL);                     
        }
        
        // UI change    
        setAdvanceSettingMode();        

        // set setting content
        m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_RECORDER);    

        VcpStateImage     imgList;
        imgList.setImage(
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON),
            VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_AD_SETTING_HILITE_ICON));             
        m_advanceSettingControl->setSettingImg(imgList);    
        
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_advanceSettingControl->reset();          
        m_advanceSettingControl->setCount(settingList.settingCount);                
        for(VfxU8 i = 0; i < settingList.settingCount; i++)
        {        
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]));
            
            m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
        }      
        m_advanceSettingControl->setFocus(settingList.CurrentSettingIdx);           
        m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
        for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
        {        
            m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
        }  
        if(VAPP_CAMCO_SETTING_RESTOREDEFAULT == settingList.settingValue[settingList.CurrentSettingIdx])
        {
            m_advanceSettingControl->setItemFocus(1);           
        }
        else
        {
            m_advanceSettingControl->setItemFocus(settingList.CurrentSettingValueIdx);           
        }         
        m_advanceSettingControl->updateItem();        
        
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_ENTER_SETTING, ID);         
        
        // UI change
        setDirectSettingMode((VfxObject*)m_directSettingControl);  

        // set setting content
        if(ID == VAPP_CAMCO_SETTING_VDOSCENEMODE)
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_VDOSCN_ONLY);        
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_VDOSCENEMODE) + 1);                
            imgList.setImage(is, is, is, is);
            m_directSettingControl->setSettingImg(imgList);            
        }        
        else if(ID == VAPP_CAMCO_SETTING_VDOEV)     
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_VDOEV_ONLY); 
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_VDOEV) + 1);              
            imgList.setImage(is, is, is, is);           
            m_directSettingControl->setSettingImg(imgList);            
        }            
        else if(ID == VAPP_CAMCO_SETTING_WB)
        {
            m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_AWB_ONLY);  
            VcpStateImage     imgList;
            VfxImageSrc is = VfxImageSrc(m_cntx.setting->getSettingImg(VAPP_CAMCO_SETTING_WB) + 1);              
            imgList.setImage(is, is, is, is);         
            m_directSettingControl->setSettingImg(imgList);            
        }      
        else
        {
            ASSERT(0);
        }
            
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_directSettingControl->reset();        
        m_directSettingControl->setCount(settingList.settingItemCount);        
        for(VfxU32 i = 0; i < settingList.settingItemCount; i++)
        {
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]),
                    VfxImageSrc(settingList.settingItemImgId[i]));
            
            m_directSettingControl->setCellData(i, settingList.settingItemValue[i], imgList, VFX_WSTR_RES(settingList.settingItemStrId[i]));
        }        
        m_directSettingControl->setFocus(settingList.CurrentSettingValueIdx);           
                  
    }

    m_resetScreenTimer->stop();    
    m_fadeOutScreenTimer->stop();     
}

void OSDRecPreviewState::onSettingSet(VfxU32 ID)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_SET_SETTING);                 

    refreshAutoExitTimer();   

    m_cntx.setting->setValue(ID);

    updateIcon();    
    updateSettingBar(0);    
}


void OSDRecPreviewState::onDirectSettingLeave(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_LEAVE_SETTING, id);  

    refreshAutoExitTimer();   

    if(m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    } 

    m_directSettingControl->recoverEffect();

    m_resetScreenTimer->start();    
    m_cntx.setting->resetEffect();

}    

void OSDRecPreviewState::onAdvanceSettingLeave(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_LEAVE_ADVANCE_SETTING, id);  

    refreshAutoExitTimer();   

    if(m_advanceSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    } 

    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
       m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)
    {
        m_settingBar->setFocus(0, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                
    }
    else
    {
        m_settingBar->setFocus(m_settingBar->getCount() - 1, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                            
    }              
    m_advanceSettingControl->recoverEffect();
    
}  

void OSDRecPreviewState::onAdvanceSettingTraverse(VfxU32 id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_TRAVERSE_ADVANCE_SETTING, id);  

    refreshAutoExitTimer();   

    m_cntx.setting->setCurrentSetting((vapp_camco_setting_enum)id);
    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);
    m_advanceSettingControl->reset();          
    m_advanceSettingControl->setCount(settingList.settingCount);                
    for(VfxU8 i = 0; i < settingList.settingCount; i++)
    {        
        VcpStateImage     imgList;
        imgList.setImage(
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]));
        
        m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
    }      
    m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
    for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
    {                
        m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
    }
    if(VAPP_CAMCO_SETTING_RESTOREDEFAULT == settingList.settingValue[settingList.CurrentSettingIdx])
    {
        m_advanceSettingControl->setItemFocus(1);           
    }
    else
    {
        m_advanceSettingControl->setItemFocus(settingList.CurrentSettingValueIdx);           
    }    
    m_advanceSettingControl->updateItem();
    
}

void OSDRecPreviewState::onAdvanceSettingSelected(VfxU32 id, VfxU32 idx)
{
    refreshAutoExitTimer();   

    m_cntx.setting->setCurrentSetting((vapp_camco_setting_enum)id);
    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);

    if((vapp_camco_setting_enum)id == VAPP_CAMCO_SETTING_RESTOREDEFAULT)
    {
        if(idx != 0 || m_confirmPopup != NULL)
            return;

        VcpConfirmPopup *m_confirmRestorePopup;
        
        VFX_OBJ_CREATE(m_confirmRestorePopup, VcpConfirmPopup, this);
        m_confirmPopup = m_confirmRestorePopup;
        
        m_confirmRestorePopup->setHidden(VFX_FALSE);        
        m_confirmRestorePopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmRestorePopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAMCO_DEFAULT_COMFIRM));
        m_confirmRestorePopup->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);           
        m_confirmRestorePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmRestorePopup->setCustomButton(
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_WARNING,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        
        m_confirmRestorePopup->setAutoDestory(VFX_FALSE);    
        m_confirmRestorePopup->m_signalButtonClicked.connect(this, &OSDRecPreviewState::onRestoreConfirm);
        m_confirmRestorePopup->show(VFX_TRUE);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_SET_ADVANCE_SETTING);         
        m_cntx.setting->setValue((vapp_camco_setting_enum)id, idx);
        m_cntx.setting->resetEffect();    
    }
    updateIcon();    
    updateSettingBar(0);    

    // check storage
    if(srv_fmgr_drv_is_removable(m_cntx.setting->getStorage()) 
        && !srv_fmgr_drv_is_accessible(m_cntx.setting->getStorage()))

    {
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV)); 

        if(m_confirmPopup == NULL)
        {
            VcpConfirmPopup *m_confirmStoragePopup;
            
            VFX_OBJ_CREATE(m_confirmStoragePopup, VcpConfirmPopup, this);
            m_confirmPopup = m_confirmStoragePopup;                
            m_confirmStoragePopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmStoragePopup->setText(VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED));
            m_confirmStoragePopup->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);             
            m_confirmStoragePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);        
            m_confirmStoragePopup->setAutoDestory(VFX_TRUE);    
            m_confirmStoragePopup->m_signalButtonClicked.connect(this, &OSDRecPreviewState::onSettingError);
            m_confirmStoragePopup->show(VFX_TRUE);    
        }
    }    
    
}

void OSDRecPreviewState::onZooming(VfxU32 value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_SET_ZOOM_SETTING);         

    refreshAutoExitTimer();   

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();   
}

void OSDRecPreviewState::onSettingError(VfxObject* obj, VfxId id)
{
    refreshAutoExitTimer();   

    m_confirmPopup = NULL;

    vapp_camco_setting_list_struct settingList;
    m_cntx.setting->getSettingList(&settingList);
    m_advanceSettingControl->reset();          
    m_advanceSettingControl->setCount(settingList.settingCount);                
    for(VfxU8 i = 0; i < settingList.settingCount; i++)
    {        
        VcpStateImage     imgList;
        imgList.setImage(
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]),
                VfxImageSrc(settingList.settingImgId[i]));
        
        m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
    }      
    m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
    for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
    {                
        m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
    }
    m_advanceSettingControl->setItemFocus(0);       
    m_advanceSettingControl->updateItem();     

}

void OSDRecPreviewState::onRestoreConfirm(VfxObject* obj, VfxId id)
{  
    refreshAutoExitTimer();   

    m_confirmPopup = NULL;

    if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);   
        
        m_cntx.setting->restoreFactorySetting();
        setNormalMode();     
        m_resetScreenTimer->start();    
        m_cntx.setting->resetEffect();       
        m_settingBar->setFocusOnCenter();  
        m_cntx.setting->needRestartPreview();        
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL);            
    }
    else
    {        
        m_cntx.setting->setCurrentSetting(VAPP_CAMCO_SETTING_RESTOREDEFAULT);
        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        m_advanceSettingControl->reset();          
        m_advanceSettingControl->setCount(settingList.settingCount);                
        for(VfxU8 i = 0; i < settingList.settingCount; i++)
        {        
            VcpStateImage     imgList;
            imgList.setImage(
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]),
                    VfxImageSrc(settingList.settingImgId[i]));
            
            m_advanceSettingControl->setCellData(i, settingList.settingValue[i], imgList, VFX_WSTR_RES(settingList.settingStrId[i]));
        }      
        m_advanceSettingControl->setitemCount(settingList.settingItemCount);             
        for(VfxU8 i = 0; i < settingList.settingItemCount; i++)
        {                
            m_advanceSettingControl->setitemData(i, settingList.settingItemValue[i], settingList.settingItemImgId[i], settingList.settingItemStrId[i]);
        }
        m_advanceSettingControl->setItemFocus(1);  
        m_advanceSettingControl->updateItem();
    }
}

void OSDRecPreviewState::onGalleryClicked(VfxObject *obj, VfxId id)
{
    refreshAutoExitTimer();   

    if(!m_isActive)
        return;

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(m_isBusy)
        return;
    
    if(m_isClicking)
        return;

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_ENTER_GALLERY, NULL);
}

void OSDRecPreviewState::onCaptureClicked(VfxObject* obj, VfxId id)
{
    refreshAutoExitTimer();   

    if(!m_isActive)
        return;
    
#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }  

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RECORD, NULL);
    m_isFocussing = VFX_FALSE;
    m_usedSensor->setOpacity(1);
}

void OSDRecPreviewState::onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{
    refreshAutoExitTimer();
#ifdef __VAPP_CAMCO_3D_SPEEDUP__
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;
#endif

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_AFMODE) == VAPP_CAMCO_AFMODE_OFF)
    {
        return;
    }

    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
        #if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            // when in direct setting , don't allow to focus
            // or it won't restart and update setting
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
            {
                break;
            }
            else
            {
                evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_FOCUS, NULL);
                if(VappCamcoPage::m_errStr == 0)
                    m_isFocussing = VFX_TRUE;
                else
                    m_isFocussing = VFX_FALSE;
            }
        #endif
            m_usedSensor->setOpacity(0.5);
            break;
        case VCP_BUTTON_STATE_NORMAL:
        #if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            if(m_isFocussing)
                evtHdlr->recFocusHdlr(VAPP_CAMCO_EVT_FOCUS_STOP, NULL);
            m_isFocussing = VFX_FALSE;
        #endif
            m_usedSensor->setOpacity(1);
            break;
        default:
            break;
    }
}

void OSDRecPreviewState::onSwitchSensorClicked(VfxObject *obj, VfxId id)
{
    refreshAutoExitTimer();   

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }  

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
    {
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);    
    }

    m_settingBar->setFocusOnCenter();   

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    m_cntx.setting->storeSceneSetting();
    
    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        m_cntx.setting->setCurrCam(VAPP_CAMCO_SENSOR_SUB_CAMERA);
    }            
    else if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
    {
        m_cntx.setting->setCurrCam(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
    }
    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_SENSOR, NULL);
}

void OSDRecPreviewState::onSwitchAppClicked(VfxObject* obj, VfxId id)
{
    refreshAutoExitTimer();   

#ifdef __VAPP_CAMCO_3D_SPEEDUP__  
    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        return;        
#endif

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    if(m_isClicking)
        return;

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return;
    }  

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
    {
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);    
    }

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setImage(SI);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();             
    
    VFX_OBJ_CREATE(m_clickTimer, VfxTimer, this);
    m_clickTimer->setStartDelay(1);
    m_clickTimer->m_signalTick.connect(this, &OSDRecPreviewState::onSwitchAppTick);
    m_clickTimer->start();
    m_isClicking = VFX_TRUE;

}


void OSDRecPreviewState::onSwitchAppTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    m_isClicking = VFX_FALSE;

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setImage(SI);

    if(!m_isActive)
        return;

    if(m_isBusy)
        return;

    m_settingBar->setFocusOnCenter();   

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    m_cntx.setting->storeSceneSetting();
    
    if(m_cntx.setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        m_cntx.setting->setCurrApp(VAPP_CAMCO_APP_CAMERA);
    }            
    else 
    {
        ASSERT(0);
    }

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_APP, NULL);
}

void OSDRecPreviewState::onResetTimerTick(VfxTimer *source)
{
    setClearMode();
    m_resetScreenTimer->stop();    
}

void OSDRecPreviewState::onCPEffctDoneTick(VfxU32 ID)
{
    vapp_camco_rec_preview_mode_enum previousMode = m_mode;

    if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)    
    {
    #if defined (HORIZONTAL_CAMERA)    	    	
        if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
           m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)    
    #endif	
        {
            m_cntx.setting->needRestartPreview();    
        }    
        evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_DE_FORCE_HORZ, NULL); 
    }
    else
    {
        evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_DE_NOTIFY_HORZ, NULL);                         
        if(m_cntx.setting->isNeedRestartPreview())
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RESTART, NULL);          
    }
 
    m_settingBar->setHidden(VFX_FALSE);
    m_directSettingControl->setHidden(VFX_TRUE);
    m_advanceSettingControl->setHidden(VFX_TRUE);   

    if(previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)    
    {
    #if defined (HORIZONTAL_CAMERA)    	
        if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
           m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)        
    #endif	
        {
            // vertical v.s. horizontal bar
            updateSettingBar(-1);
        }
    }
    if(m_settingBar->getPostFocus() != m_settingBar->getFocus())
    {
        m_settingBar->setFocus(m_settingBar->getPostFocus(), VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);
    }
    m_settingBar->recoverEffect();

    m_resetScreenTimer->start();      
}

void OSDRecPreviewState::onCPEffctDoneTick2(VfxU32 ID)
{
    // set back the focus(center) icon before tap 
    m_settingBar->setFocusandCheck(m_settingBar->getPrevFocus());    

    setNormalMode();    
    updateSettingBar(0);    
    m_resetScreenTimer->start();    

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);   

}

VfxBool OSDRecPreviewState::isHorzUI(void)
{
#if defined (HORIZONTAL_CAMERA)
    if((m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA && m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER) 
       || (m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION && m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
       || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }        
#else
    if((m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION && m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
       || m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    } 

#endif
}

void OSDRecPreviewState::ZoomingIn(VfxTimer *source)
{
    refreshAutoExitTimer();   

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     
    m_resetScreenTimer->start();    
    m_zoomingTimer->start();                    

}

void OSDRecPreviewState::ZoomingOut(VfxTimer *source)
{
    refreshAutoExitTimer();   

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      
    m_resetScreenTimer->start();     
    m_zoomingTimer->start();
                 
}


VfxBool OSDRecPreviewState::onPenInput(VfxPenEvent & event)
{
    refreshAutoExitTimer();
    
    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_DIRSETTING && m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING) 
    {    
        m_resetScreenTimer->start();      
    }
    
    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        m_isDownProcessed = VFX_TRUE;
        return VFX_TRUE;
    }

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_TRANSITION)
        {
            if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                setNormalMode();            
            else if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                setAdvanceSettingMode();            
            else if(m_previousMode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                setDirectSettingMode(m_previousModeDirSettingObj);                 

            m_fadeOutScreenTimer->stop();                 

            m_isDownProcessed = VFX_TRUE;
                
        }    
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            if((isHorzUI() && pos.x > 0.25 * m_advanceSettingControl->getSize().width) ||
               (!isHorzUI() && pos.y > 0.25 * m_advanceSettingControl->getSize().width))
            {        
                if(m_previousModeDirSettingObj == m_directSettingControl)
                {
                    m_settingBar->searchFocusItem(VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);
                    m_directSettingControl->recoverEffect();        
                }
                else
                {
                    setNormalMode();    
                }   
            }                
            m_isDownProcessed = VFX_TRUE;            
        }        
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        {
            if(pos.x > 0.3 * m_advanceSettingControl->getSize().width)
            {
                if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || 
                   m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)            
                {
                    m_settingBar->setFocus(0, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                
                }
                else
                {
                    m_settingBar->setFocus(m_settingBar->getCount() - 1, VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE);                            
                }              
                m_advanceSettingControl->recoverEffect();        
            }            
            m_isDownProcessed = VFX_TRUE;                
        }           
        else if(m_mode != VAPP_CAMCO_PREVIEW_MODE_CLEAR)
        {                             
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(m_rightBar->getBounds().contains(posR))
                m_isDownProcessed = VFX_TRUE;             
            else
                m_isDownProcessed = VFX_FALSE;          
        }  
        else
        {
            m_isDownProcessed = VFX_FALSE; 
        }        
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(!m_isDownProcessed)
        {  
            if(m_mode != VAPP_CAMCO_PREVIEW_MODE_CLEAR)
            {
                setClearModeinternal(NULL);         
            }             
            else
            {
                setNormalMode();    
            }     
        }
        return VFX_TRUE;     
     
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return CamcoOSDState::onPenInput(event);

}


VfxBool OSDRecPreviewState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();
    
    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_DIRSETTING && m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING) 
    {    
        m_resetScreenTimer->start();      
    }
             

    if(m_advanceSettingControl->isAnimating() || m_directSettingControl->isAnimating() || m_settingBar->isAnimating())
    {
        return VFX_TRUE;
    }

    if(m_isBusy)
        return VFX_TRUE;

    if(m_isClicking)
        return VFX_TRUE;

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA:  
        case VFX_KEY_CODE_ENTER:             
        {
            // cannot record in advance setting menu
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                return VFX_TRUE;    
            }            
           
            
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_DOWN)        
            {
                // when in direct setting , don't allow to focus
                // or it won't restart and update setting
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    return VFX_TRUE;
                }
                
                if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_AFMODE) == VAPP_CAMCO_AFMODE_OFF)
                {
                    return VFX_TRUE;
                }
            #if defined(VAPP_CAMCO_AF_SUPPORT)
                evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_FOCUS, NULL);
                if(VappCamcoPage::m_errStr == 0)
                    m_isFocussing = VFX_TRUE;
                else
                    m_isFocussing = VFX_FALSE;
            #endif
            }            
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {            
            #if defined(VAPP_CAMCO_AF_SUPPORT)
                if(!m_isFocussing)
                    evtHdlr->recFocusHdlr(VAPP_CAMCO_EVT_RECORD, NULL);
                else
            #endif
                evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RECORD, NULL);     
                m_isFocussing = VFX_FALSE;
            }
            if(event.type == VFX_KEY_EVENT_TYPE_HALF_PRESS_UP)
            {
            #if defined(VAPP_CAMCO_AF_SUPPORT)
                if(m_isFocussing)
                    evtHdlr->recFocusHdlr(VAPP_CAMCO_EVT_FOCUS_STOP, NULL);
                m_isFocussing = VFX_FALSE;
            #endif
            }
            return VFX_TRUE;
        }         
        case VFX_KEY_CODE_ARROW_DOWN:   
        case VFX_KEY_CODE_VOL_DOWN:
        {
            if(isHorzUI() || event.keyCode == VFX_KEY_CODE_VOL_DOWN)
            {
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {  
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() + 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() + 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                        return VFX_TRUE;         
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPreviewState::ZoomingIn);   
                        m_zoomingTimer->m_signalTick.connect(this, &OSDRecPreviewState::ZoomingOut);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                                    
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();
                    }
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_UP:
        case VFX_KEY_CODE_VOL_UP:    
        {
            if(isHorzUI() || event.keyCode == VFX_KEY_CODE_VOL_UP)
            {            
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() - 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                         
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() - 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                        return VFX_TRUE;  
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPreviewState::ZoomingOut);   
                        m_zoomingTimer->m_signalTick.connect(this, &OSDRecPreviewState::ZoomingIn);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                                    
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();
                    }                    
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            return VFX_TRUE;             
        }         
        case VFX_KEY_CODE_ARROW_LEFT:                                    
        {
            if(!isHorzUI())
            {
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                     
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() - 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                         
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() - 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                        return VFX_TRUE;  
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPreviewState::ZoomingIn);   
                        m_zoomingTimer->m_signalTick.connect(this, &OSDRecPreviewState::ZoomingOut);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                                    
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();
                    }
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_RIGHT:         
        {
            if(!isHorzUI())
            {            
                if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_advanceSettingControl->setFocus(m_advanceSettingControl->getFocus() + 1,0);
                    }
                }
                else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)            
                {
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                  
                        m_directSettingControl->setFocus(m_directSettingControl->getFocus() + 1,0);            
                    }
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                        return VFX_TRUE;  
                                        
                    if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                    {                
                        if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                            m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                        m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     

                        m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPreviewState::ZoomingOut);   
                        m_zoomingTimer->m_signalTick.connect(this, &OSDRecPreviewState::ZoomingIn);
                        m_zoomingTimer->setStartDelay(100);
                        m_zoomingTimer->start();                                    
                    }
                    else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                    {
                        m_zoomingTimer->stop();
                    }                    
                }            
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
                {            
                    setNormalMode();    
                }            
            }
            return VFX_TRUE;             
        }               
        case VFX_KEY_CODE_BACK:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {       
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                {
                    onAdvanceSettingLeave(NULL, 0);
                    return VFX_TRUE;                                   
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
                {
                    onDirectSettingLeave(NULL, 0);
                    return VFX_TRUE;                                                       
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
                {
                    setClearModeinternal(NULL);                                     
                    return VFX_TRUE;                                                       
                }                
            }
        }
    }
    return CamcoOSDState::onKeyInput(event);
}


void OSDRecRecordingState::onInit(void)
{
    CamcoOSDState::onInit();

    VFX_OBJ_CREATE(m_zoomer, VappCamcoCpSlider, this);    
    VFX_OBJ_CREATE(m_recIcon, VappCamcoCpRotatableImageFrame, this);  
    VFX_OBJ_CREATE(m_recInfo, VappCamcoCpRotatableTextFrame, this);    
    VFX_OBJ_CREATE(m_stop, VappCamcoCpRotatableImageButton, this);      
    VFX_OBJ_CREATE(m_pause, VappCamcoCpRotatableImageButton, this);  
    VFX_OBJ_CREATE(m_timelapseIcon, VappCamcoCpRotatableImageFrame, this);

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON);   
    m_stop->setAnchor(0.5, 0.5);
    m_stop->setImage(SI);
    m_stop->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_stop->setAutoAnimate(VFX_FALSE);
    m_stop->setIsEffect(VFX_FALSE);
    m_stop->setEffectSize(VfxSize(110, 110));    

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_PAUSE_ICON,IMG_ID_VAPP_CAMCO_RECORD_PAUSE_ICON,IMG_ID_VAPP_CAMCO_RECORD_PAUSE_ICON,IMG_ID_VAPP_CAMCO_RECORD_PAUSE_ICON);   
    m_pause->setAnchor(0.5, 0.5);
    m_pause->setImage(SI);
    m_pause->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_pause->setAutoAnimate(VFX_FALSE);
    m_pause->setIsEffect(VFX_FALSE);
    m_pause->setEffectSize(VfxSize(52, 52));    

    m_zoomer->setCpImage(VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IND_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_BAR_ICON));
    m_zoomer->setAnchor(0.5, 0.5);    
    m_zoomer->setValueRange(0, 100);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setCurveR(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_recIcon->setResId(IMG_ID_VAPP_CAMCO_RECORD_REC_IND_ICON);
    m_recIcon->setAnchor(0.5, 0.5);
    m_recIcon->setAutoAnimate(VFX_FALSE);

    m_recInfo->setAnchor(0.5, 0.5);
    m_recInfo->setAutoAnimate(VFX_FALSE);
    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "00:00:00");
    m_recInfo->setString(VFX_WSTR_MEM(caption));
    VfxFontDesc font = m_recInfo->getFont();
    font.effect = VFX_FE5_1;
    font.attr |= VFX_FONT_DESC_ATTR_MONOSPACE;
    m_recInfo->setFont(font);   

    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);  
    VFX_OBJ_CREATE(m_fadeOutScreenTimer, VfxTimer, this);  
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);     

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING;        

    m_stop->m_signalClicked.connect(this, &OSDRecRecordingState::onStopClicked);   
    m_pause->m_signalClicked.connect(this, &OSDRecRecordingState::onPauseClicked);   
    m_zoomer->m_signalValueChanged.connect(this, &OSDRecRecordingState::onZooming);

    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecRecordingState::onResetTimerTick);
    m_fadeOutScreenTimer->m_signalTick.connect(this, &OSDRecRecordingState::setClearModeinternal);

};



void OSDRecRecordingState::enterState(void* param)
{
    ASSERT(param != NULL);
    CamcoOSDState::enterState(param);

    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_recording_param_struct));

    m_timelapseIcon->setResId(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_TIMELAPSE));
    m_timelapseIcon->setAnchor(0.5, 0.5);
    m_timelapseIcon->setAutoAnimate(VFX_FALSE);

    setNormalMode();

    m_zoomer->setValueRange(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM), m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
    {
        m_zoomer->setHidden(VFX_TRUE);
    }
    
    m_resetScreenTimer->setStartDelay(CAMCO_REC_RESET_TIME);
    m_resetScreenTimer->start();

    m_fadeOutScreenTimer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

    m_autoExitTimer->stop();  

};

void OSDRecRecordingState::exitState(void)
{
    CamcoOSDState::exitState();

    m_recInfo->setAutoResized(VFX_TRUE);
    
    m_resetScreenTimer->stop();      
    m_zoomingTimer->stop();            
}

void OSDRecRecordingState::setRotate(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    // ============================================================
    // enable autoanimation
    // ============================================================    

    //m_zoomer->setAutoAnimate(VFX_TRUE);
   
    //m_recIcon->setAutoAnimate(VFX_TRUE);
    //m_recInfo->setAutoAnimate(VFX_TRUE);
    //m_stop->setAutoAnimate(VFX_TRUE);
    //m_pause->setAutoAnimate(VFX_TRUE);
        
    // ============================================================
    // enable autoanimation
    // ============================================================    
    VfxBool isHorzUI = (m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA &&  m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER);
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;
    
    if(isHorzUI)
    {
        if(isHorz)
        {
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  

        }
        else
        {
            if(m_cntx.previewWindow.origin.x - (m_cntx.previewWindow.size.width>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(m_cntx.previewWindow.origin.x - (m_cntx.previewWindow.size.width>>1) + m_recInfo->getSize().height, GDI_LCD_WIDTH - sp->recIndicatorPos[0]);
            else
                m_recIcon->setPos(m_recInfo->getSize().height, GDI_LCD_WIDTH - sp->recIndicatorPos[0]);
            m_recInfo->setPos(m_recIcon->getPos().x, GDI_LCD_WIDTH - sp->recIndicatorPos[0] - (m_recInfo->getSize().width >> 1) - 20);       
        }
    }
    else
    {
        if(isHorz)
        {
            m_recIcon->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0], sp->recIndicatorPos[0]);
            m_recInfo->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0], m_recIcon->getPos().y + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8));    
        }
        else
        {
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        }    
    }

    m_zoomer->setRot(isHorzUI, isHorz, isMirror);  
   
    m_recIcon->setRot(isHorzUI, isHorz, isMirror);  
    m_recInfo->setRot(isHorzUI, isHorz, isMirror);  
    m_stop->setRot(isHorzUI, isHorz, isMirror);  
    m_pause->setRot(isHorzUI, isHorz, isMirror);  
    m_timelapseIcon->setRot(isHorzUI, isHorz, isMirror);

    // ============================================================
    // disable autoanimation
    // ============================================================    

    //m_zoomer->setAutoAnimate(VFX_FALSE);
   
    //m_recIcon->setAutoAnimate(VFX_FALSE);
    //m_recInfo->setAutoAnimate(VFX_FALSE);
    //m_stop->setAutoAnimate(VFX_FALSE);
    //m_pause->setAutoAnimate(VFX_FALSE);
        
    // ============================================================
    // disable autoanimation
    // ============================================================    
#endif
}


void OSDRecRecordingState::setNormalMode(void)
{
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)  
        m_zoomer->setHidden(VFX_FALSE);  
    else
        m_zoomer->setHidden(VFX_TRUE);          
    
    m_recIcon->setHidden(VFX_FALSE);      
    m_recInfo->setHidden(VFX_FALSE);      
    m_stop->setHidden(VFX_FALSE);      
    
 #ifdef __MMI_OP02_LEMEI_FTO__     
    if(m_cntx.setting->IsExtSetting())
        m_pause->setHidden(VFX_TRUE);      
    else
        m_pause->setHidden(VFX_FALSE);              
 #else
    m_pause->setHidden(VFX_FALSE);      
 #endif

    m_timelapseIcon->setHidden(VFX_FALSE);

    m_mode = VAPP_CAMCO_REC_MODE_NORMAL;
    
    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();   

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

}

void OSDRecRecordingState::setClearMode(void)
{
    m_mode = VAPP_CAMCO_REC_MODE_TRANSITION;

    VfxAutoAnimate::begin();    
        VfxAutoAnimate::setDuration(1500);
        layout();    
    VfxAutoAnimate::commit();
    
    m_fadeOutScreenTimer->start();   
    
}

void OSDRecRecordingState::setClearModeinternal(VfxTimer *source)
{
    m_zoomer->setHidden(VFX_TRUE);      
    m_recIcon->setHidden(VFX_FALSE);      
    m_recInfo->setHidden(VFX_FALSE);      
    m_stop->setHidden(VFX_FALSE);   
#ifdef __MMI_OP02_LEMEI_FTO__     
    if(m_cntx.setting->IsExtSetting())
        m_pause->setHidden(VFX_TRUE);      
    else
        m_pause->setHidden(VFX_FALSE);      
#else    
    m_pause->setHidden(VFX_FALSE);      
#endif

    m_timelapseIcon->setHidden(VFX_FALSE);

    m_mode = VAPP_CAMCO_REC_MODE_CLEAR;

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

}


void OSDRecRecordingState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

#if defined (HORIZONTAL_CAMERA)
    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA &&  m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
        {

            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);        
            
            m_stop->setPos(sp->recordPos[0], sp->recordPos[1]);   
            m_pause->setPos(sp->recPausePos[0], sp->recPausePos[1]);   
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0],  m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);                
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8) , m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(sp->zoomControlPos[0], sp->zoomControlPos[1]);                  

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);             
            m_zoomer->setOpacity(1);

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
        else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR || m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);        

            m_stop->setPos(sp->recordPos[0], sp->recordPos[1]);   
            m_pause->setPos(sp->recPausePos[0], sp->recPausePos[1]);            
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(sp->zoomControlPos[0], sp->zoomControlPos[1]);                  
            
            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);                 
            m_zoomer->setOpacity(0);                        

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
            
    }    
    else 
#endif        
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
        {

            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);        

            m_stop->setPos(coordTransform2Vertical(sp->recordPos[0], sp->recordPos[1]));   
            m_pause->setPos(coordTransform2Vertical(sp->recPausePos[0], sp->recPausePos[1]));    
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0], sp->zoomControlPos[1]));                  
              
            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);                  
            m_zoomer->setOpacity(1);

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
        else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR || m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);         
            
            m_stop->setPos(coordTransform2Vertical(sp->recordPos[0], sp->recordPos[1]));   
            m_pause->setPos(coordTransform2Vertical(sp->recPausePos[0], sp->recPausePos[1]));    
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif            
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0], sp->zoomControlPos[1]));                  

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE);                  
            m_zoomer->setOpacity(0);               

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
    }

};

void OSDRecRecordingState::onZooming(VfxU32 value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_RECORD_SET_ZOOM_SETTING);         

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();   
}


void OSDRecRecordingState::onResetTimerTick(VfxTimer *source)
{
    setClearMode();
    m_resetScreenTimer->stop();    
}

void OSDRecRecordingState::setRecParam(VfxU32 time, VfxU32 size)
{
    rec_time = time;
    rec_size = size;
    
    VfxWChar caption[30] = {0};
    VfxU32 ss, mm, hh;   
    VfxU32 limitedhh, limitedmm, limitedss = 0; 
    VfxU32 limitedsize = 0;
    VfxU32 limitedFrameNumber = 0;

    if(m_cntx.setting->IsExtSetting() && ((LimitSetting*)(m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getTimeLimit() > 0)
    {
        VfxU32 L = ((LimitSetting*)(m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getTimeLimit();    

        limitedss = L%60;            
        limitedmm = L/60;
        limitedhh = limitedmm/60;
        limitedmm= limitedmm%60;
        if(limitedhh > 99) limitedhh = 99;
        
        ss = time%60;            
        mm = time/60;
        hh = mm/60;
        mm = mm%60;
        if(hh > 99) hh = 99;

        kal_wsprintf(caption, "%02d:%02d:%02d/%02d:%02d:%02d", hh, mm, ss,limitedhh, limitedmm, limitedss);
        m_recInfo->setString(VFX_WSTR_MEM(caption));         
    }
    else if(m_cntx.setting->IsExtSetting() && ((LimitSetting*)(m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getSizeLimit() > 0)
    {
        limitedsize = ((LimitSetting*)(m_cntx.setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getSizeLimit();

        kal_wsprintf(caption, "%03dK/%03dK", size, limitedsize);
        m_recInfo->setString(VFX_WSTR_MEM(caption));
    }    
    else
    {
        switch ((vapp_camco_limit_enum)m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT))
        {
            case VAPP_CAMCO_LIMIT_NO_LIMIT:
                if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_OFF)
                {
                    ss = time%60;
                    mm = time/60;
                    hh = mm/60;
                    mm = mm%60;
                    if(hh > 99) hh = 99;

                    kal_wsprintf(caption, "%02d:%02d:%02d", hh, mm, ss);
                    m_recInfo->setString(VFX_WSTR_MEM(caption));
                }
                else
                {
                    kal_wsprintf(caption, "%05d", time);
                    m_recInfo->setString(VFX_WSTR_MEM(caption));
                }
                break;
            case VAPP_CAMCO_LIMIT_TIME_15S:
            case VAPP_CAMCO_LIMIT_TIME_30S:          
            case VAPP_CAMCO_LIMIT_TIME_60S:
            case VAPP_CAMCO_LIMIT_TIME_300S:
            case VAPP_CAMCO_LIMIT_TIME_600S:
                if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_OFF)
                {
                    limitedhh = 0;
                    limitedmm = 0;
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S)
                        limitedss = 15;
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S)
                        limitedss = 30;
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S)
                    {
                        limitedmm = 1;
                        limitedss = 0;
                    }
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S)
                    {
                        limitedmm = 5;
                        limitedss = 0;
                    }
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
                    {
                        limitedmm = 10;
                        limitedss = 0;
                    }

                    ss = time%60;
                    mm = time/60;
                    hh = mm/60;
                    mm = mm%60;
                    if(hh > 99) hh = 99;

                    kal_wsprintf(caption, "%02d:%02d:%02d/%02d:%02d:%02d", hh, mm, ss,limitedhh, limitedmm, limitedss);
                    m_recInfo->setString(VFX_WSTR_MEM(caption));
                }
                else
                {
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S)
                        limitedFrameNumber = (15 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S)
                        limitedFrameNumber = (30 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S)
                        limitedFrameNumber = (60 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S)
                        limitedFrameNumber = (300 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                    else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
                        limitedFrameNumber = (600 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);

                    kal_wsprintf(caption, "%05d/%05d", time, limitedFrameNumber);
                    m_recInfo->setString(VFX_WSTR_MEM(caption));
                }            
                break;

            case VAPP_CAMCO_LIMIT_SIZE_95K:           
            case VAPP_CAMCO_LIMIT_SIZE_195K:               
            case VAPP_CAMCO_LIMIT_SIZE_295K:    
                limitedsize = 95 + 100 * (m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) - VAPP_CAMCO_LIMIT_SIZE_95K);                            

                kal_wsprintf(caption, "%03dK/%03dK", rec_size, limitedsize);
                m_recInfo->setString(VFX_WSTR_MEM(caption));                     
                break;        
                
        }            
    }

    // fix text frame size or transform will cause text blightness change
    if(m_recInfo->getAutoResized())
    {
        VfxSize s = m_recInfo->getSize();
        m_recInfo->setAutoResized(VFX_FALSE);
        m_recInfo->setSize(s);
    }

#ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate    
    m_recInfo->setPos(g_vapp_camco_skin.recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);        
#else
    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);
#endif    
    
}

void OSDRecRecordingState::onStopClicked(VfxObject *obj, VfxId id)
{
    if(!m_isActive)
        return;

    evtHdlr->recRecordingHdlr(VAPP_CAMCO_EVT_REC_STOP, NULL);
}

void OSDRecRecordingState::onPauseClicked(VfxObject *obj, VfxId id)
{
    if(!m_isActive)
        return;

    evtHdlr->recRecordingHdlr(VAPP_CAMCO_EVT_REC_PAUSE, NULL);
}

void OSDRecRecordingState::ZoomingIn(VfxTimer *source)
{
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     
    m_resetScreenTimer->start();    
    m_zoomingTimer->start();                    

}

void OSDRecRecordingState::ZoomingOut(VfxTimer *source)
{

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      
    m_resetScreenTimer->start();     
    m_zoomingTimer->start();
                 
}

VfxBool OSDRecRecordingState::onPenInput(VfxPenEvent & event)
{
    m_resetScreenTimer->start(); 

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setNormalMode();            
                        
            m_fadeOutScreenTimer->stop();                  
        }                
        else if(m_mode != VAPP_CAMCO_REC_MODE_CLEAR)
        {
            setNormalMode();    
        }        
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
        {
            setNormalMode();    
        }     
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return VFX_TRUE;

}


VfxBool OSDRecRecordingState::onKeyInput(VfxKeyEvent &event)
{
    m_resetScreenTimer->start();    

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_ENTER:
        case VFX_KEY_CODE_CAMERA:        
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {            
                evtHdlr->recRecordingHdlr(VAPP_CAMCO_EVT_REC_STOP, NULL);            
            }
            break;
        }    
        case VFX_KEY_CODE_VOL_UP:
        case VFX_KEY_CODE_ARROW_UP:                
        {          

            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {  
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_RECORD_SET_ZOOM_SETTING);                      
                
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
                    
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {             
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecRecordingState::ZoomingOut);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecRecordingState::ZoomingIn);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                    
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }                
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }                      
            m_resetScreenTimer->start();               
            return VFX_TRUE;            
        }            
        case VFX_KEY_CODE_VOL_DOWN:
        case VFX_KEY_CODE_ARROW_DOWN:                
        {          
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {    
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
                                
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_RECORD_SET_ZOOM_SETTING);                                     
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
                {
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecRecordingState::ZoomingIn);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecRecordingState::ZoomingOut);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }                
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }                      
            return VFX_TRUE;            
        }    
        case VFX_KEY_CODE_ARROW_LEFT:                            
        {
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecRecordingState::ZoomingIn);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecRecordingState::ZoomingOut);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }            
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_RIGHT:                      
        {
           
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {             
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     
                    
                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecRecordingState::ZoomingOut);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecRecordingState::ZoomingIn);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                    
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }            
            return VFX_TRUE;             
        }             
        case VFX_KEY_CODE_BACK:
        {
            evtHdlr->recRecordingHdlr(VAPP_CAMCO_EVT_REC_STOP_EXIT, NULL);            
            return VFX_TRUE;             
        }
        case VFX_KEY_CODE_HOME:
        {
            return CamcoOSDState::onKeyInput(event);
        }
    }
    return VFX_TRUE;
}

void OSDRecPauseState::onInit(void)
{
    CamcoOSDState::onInit();

    VFX_OBJ_CREATE(m_zoomer, VappCamcoCpSlider, this);    
    VFX_OBJ_CREATE(m_recIcon, VappCamcoCpRotatableImageFrame, this);  
    VFX_OBJ_CREATE(m_recInfo, VappCamcoCpRotatableTextFrame, this);  
    VFX_OBJ_CREATE(m_stop, VappCamcoCpRotatableImageButton, this);      
    VFX_OBJ_CREATE(m_resume, VappCamcoCpRotatableImageButton, this);  
    VFX_OBJ_CREATE(m_timelapseIcon, VappCamcoCpRotatableImageFrame, this);

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON,IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON);   
    m_stop->setAnchor(0.5, 0.5);
    m_stop->setImage(SI);
    m_stop->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_stop->setAutoAnimate(VFX_FALSE);
    m_stop->setIsEffect(VFX_FALSE);
    m_stop->setEffectSize(VfxSize(110, 110));   

    SI = VcpStateImage(IMG_ID_VAPP_CAMCO_RECORD_RESUME_ICON,IMG_ID_VAPP_CAMCO_RECORD_RESUME_ICON,IMG_ID_VAPP_CAMCO_RECORD_RESUME_ICON,IMG_ID_VAPP_CAMCO_RECORD_RESUME_ICON);   
    m_resume->setAnchor(0.5, 0.5);
    m_resume->setImage(SI);
    m_resume->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_resume->setAutoAnimate(VFX_FALSE);
    m_resume->setIsEffect(VFX_FALSE);
    m_resume->setEffectSize(VfxSize(52, 52));   

    m_zoomer->setCpImage(VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_IND_ICON), VfxImageSrc(IMG_ID_VAPP_CAMCO_ZOOM_BAR_ICON));
    m_zoomer->setAnchor(0.5, 0.5);    
    m_zoomer->setValueRange(0, 100);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setCurveR(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_recIcon->setResId(IMG_ID_VAPP_CAMCO_RECORD_PAUSE_IND_ICON);
    m_recIcon->setAnchor(0.5, 0.5);
    m_recIcon->setAutoAnimate(VFX_FALSE);

    m_recInfo->setAnchor(0.5, 0.5);
    m_recInfo->setAutoAnimate(VFX_FALSE);
    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "00:00:00");
    m_recInfo->setString(VFX_WSTR_MEM(caption));
    VfxFontDesc font = m_recInfo->getFont();
    font.effect = VFX_FE5_1;
    font.attr |= VFX_FONT_DESC_ATTR_MONOSPACE;
    m_recInfo->setFont(font);   

    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);  
    VFX_OBJ_CREATE(m_fadeOutScreenTimer, VfxTimer, this);  
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);     

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_PAUSE;        

    m_stop->m_signalClicked.connect(this, &OSDRecPauseState::onStopClicked);   
    m_resume->m_signalClicked.connect(this, &OSDRecPauseState::onResumeClicked);   
    m_zoomer->m_signalValueChanged.connect(this, &OSDRecPauseState::onZooming);

    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecPauseState::onResetTimerTick);
    m_fadeOutScreenTimer->m_signalTick.connect(this, &OSDRecPauseState::setClearModeinternal);

};

void OSDRecPauseState::enterState(void* param)
{
    ASSERT(param != NULL);

    CamcoOSDState::enterState(param);   
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_pause_param_struct));

    VfxWChar caption[30] = {0};
    VfxU32 ss, mm, hh;   
    VfxU32 limitedhh, limitedmm, limitedss = 0; 
    VfxU32 limitedsize = 0;
    VfxU32 limitedFrameNumber = 0;
    
    switch ((vapp_camco_limit_enum)m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT))
    {
        case VAPP_CAMCO_LIMIT_NO_LIMIT:
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_OFF)
            {
                ss = m_cntx.recTime%60;
                mm = m_cntx.recTime/60;
                hh = mm/60;
                mm = mm%60;
                if(hh > 99) hh = 99;

                kal_wsprintf(caption, "%02d:%02d:%02d", hh, mm, ss);
                m_recInfo->setString(VFX_WSTR_MEM(caption));
            }
            else
            {
                kal_wsprintf(caption, "%05d", m_cntx.recTime);
                m_recInfo->setString(VFX_WSTR_MEM(caption));
            }
            break;

        case VAPP_CAMCO_LIMIT_TIME_15S:          
        case VAPP_CAMCO_LIMIT_TIME_30S:                    
        case VAPP_CAMCO_LIMIT_TIME_60S:    
        case VAPP_CAMCO_LIMIT_TIME_300S:
        case VAPP_CAMCO_LIMIT_TIME_600S:
            if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_OFF)
            {
                limitedhh = 0;
                limitedmm = 0;
                if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S)
                    limitedss = 15;
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S)
                    limitedss = 30;
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S)
                {
                    limitedmm = 1;
                    limitedss = 0;
                }
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S)
                {
                    limitedmm = 5;
                    limitedss = 0;
                }
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
                {
                    limitedmm = 10;
                    limitedss = 0;
                }

                ss = m_cntx.recTime%60;
                mm = m_cntx.recTime/60;
                hh = mm/60;
                mm = mm%60;
                if(hh > 99) hh = 99;

                kal_wsprintf(caption, "%02d:%02d:%02d/%02d:%02d:%02d", hh, mm, ss,limitedhh, limitedmm, limitedss);
                m_recInfo->setString(VFX_WSTR_MEM(caption));
            }
            else
            {
                if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S)
                    limitedFrameNumber = (15 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S)
                    limitedFrameNumber = (30 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S)
                    limitedFrameNumber = (60 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S)
                    limitedFrameNumber = (300 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);
                else if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
                    limitedFrameNumber = (600 / RECORDER_TIME_LAPSE_SAMPLE_PERIOD);

                kal_wsprintf(caption, "%05d/%05d", m_cntx.recTime, limitedFrameNumber);
                m_recInfo->setString(VFX_WSTR_MEM(caption));
            }      
            break;

        case VAPP_CAMCO_LIMIT_SIZE_95K:        
        case VAPP_CAMCO_LIMIT_SIZE_195K:               
        case VAPP_CAMCO_LIMIT_SIZE_295K:    
            limitedsize = 95 + 100 * (m_cntx.setting->getValue(VAPP_CAMCO_SETTING_LIMIT) - VAPP_CAMCO_LIMIT_SIZE_95K); 

            kal_wsprintf(caption, "%03dK/%03dK", m_cntx.recSize, limitedsize);
            m_recInfo->setString(VFX_WSTR_MEM(caption));                     
            break;        
            
    }

    // fix text frame size or transform will cause text blightness change
    if(m_recInfo->getAutoResized())
    {
        VfxSize s = m_recInfo->getSize();
        m_recInfo->setAutoResized(VFX_FALSE);
        m_recInfo->setSize(s);
    }

    m_timelapseIcon->setResId(m_cntx.setting->getSettingStatusImg(VAPP_CAMCO_SETTING_TIMELAPSE));
    m_timelapseIcon->setAnchor(0.5, 0.5);
    m_timelapseIcon->setAutoAnimate(VFX_FALSE);

    m_zoomer->setValueRange(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM), m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));    
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    setNormalMode();

    m_resetScreenTimer->setStartDelay(CAMCO_REC_RESET_TIME);
    m_resetScreenTimer->start();

    m_fadeOutScreenTimer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

    m_autoExitTimer->stop();  

};

void OSDRecPauseState::exitState(void)
{
    CamcoOSDState::exitState();

    m_recInfo->setAutoResized(VFX_TRUE);
    
    m_resetScreenTimer->stop();      
    m_zoomingTimer->stop();            
}

void OSDRecPauseState::setRotate(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    
    // ============================================================
    // enable autoanimation
    // ============================================================    

    //m_zoomer->setAutoAnimate(VFX_TRUE);
   
    //m_recIcon->setAutoAnimate(VFX_TRUE);
    //m_recInfo->setAutoAnimate(VFX_TRUE);
    //m_stop->setAutoAnimate(VFX_TRUE);
    //m_resume->setAutoAnimate(VFX_TRUE);
        
    // ============================================================
    // enable autoanimation
    // ============================================================    

    VfxBool isHorzUI = (m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA &&  m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER);
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;
    
    if(isHorzUI)
    {
        if(isHorz)
        {
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  

        }
        else
        {
            if(m_cntx.previewWindow.origin.x - (m_cntx.previewWindow.size.width>>1) + m_recInfo->getSize().height > 0)        
                m_recIcon->setPos(m_cntx.previewWindow.origin.x - (m_cntx.previewWindow.size.width>>1) + m_recInfo->getSize().height, GDI_LCD_WIDTH - sp->recIndicatorPos[0]);
            else
                m_recIcon->setPos(m_recInfo->getSize().height, GDI_LCD_WIDTH - sp->recIndicatorPos[0]);
            m_recInfo->setPos(m_recIcon->getPos().x, GDI_LCD_WIDTH - sp->recIndicatorPos[0] - (m_recInfo->getSize().width >> 1) - 20);       
        }
    }
    else
    {
        if(isHorz)
        {
            m_recIcon->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0], sp->recIndicatorPos[0]);
            m_recInfo->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0], m_recIcon->getPos().y + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8));    
        }
        else
        {
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        }    
    }

    m_zoomer->setRot(isHorzUI, isHorz, isMirror);  
   
    m_recIcon->setRot(isHorzUI, isHorz, isMirror);  
    m_recInfo->setRot(isHorzUI, isHorz, isMirror);  
    m_stop->setRot(isHorzUI, isHorz, isMirror);  
    m_resume->setRot(isHorzUI, isHorz, isMirror);  
    m_timelapseIcon->setRot(isHorzUI, isHorz, isMirror);

    // ============================================================
    // disable autoanimation
    // ============================================================    

    //m_zoomer->setAutoAnimate(VFX_FALSE);
   
    //m_recIcon->setAutoAnimate(VFX_FALSE);
    //m_recInfo->setAutoAnimate(VFX_FALSE);
    //m_stop->setAutoAnimate(VFX_FALSE);
    //m_resume->setAutoAnimate(VFX_FALSE);
        
    // ============================================================
    // disable autoanimation
    // ============================================================    
    
#endif
}


void OSDRecPauseState::setNormalMode(void)
{
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)  
        m_zoomer->setHidden(VFX_FALSE);      
    else
        m_zoomer->setHidden(VFX_TRUE);      
    
    m_recIcon->setHidden(VFX_FALSE);      
    m_recInfo->setHidden(VFX_FALSE);      
    m_stop->setHidden(VFX_FALSE);      
    m_resume->setHidden(VFX_FALSE);      

    m_timelapseIcon->setHidden(VFX_FALSE);

    m_mode = VAPP_CAMCO_REC_MODE_NORMAL;
    
    VfxAutoAnimate::begin();            
        VfxAutoAnimate::setDisable(VFX_TRUE);           
        layout();
    VfxAutoAnimate::commit();   

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

}

void OSDRecPauseState::setClearMode(void)
{
    m_mode = VAPP_CAMCO_REC_MODE_TRANSITION;

    VfxAutoAnimate::begin();    
        VfxAutoAnimate::setDuration(1500);
        layout();    
    VfxAutoAnimate::commit();
    
    m_fadeOutScreenTimer->start();   
    
}

void OSDRecPauseState::setClearModeinternal(VfxTimer *source)
{
    m_zoomer->setHidden(VFX_TRUE);      
    m_recIcon->setHidden(VFX_FALSE);      
    m_recInfo->setHidden(VFX_FALSE);      
    m_stop->setHidden(VFX_FALSE);      
    m_resume->setHidden(VFX_FALSE);      
 
    m_timelapseIcon->setHidden(VFX_FALSE);

    m_mode = VAPP_CAMCO_REC_MODE_CLEAR;

    setRotate(m_cntx.isPreviewHorz, m_cntx.isPreviewMirror);

}

void OSDRecPauseState::onZooming(VfxU32 value)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PAUSE_SET_ZOOM_SETTING);         

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();   
}

void OSDRecPauseState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

#if defined (HORIZONTAL_CAMERA)
    if(m_cntx.setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA && m_cntx.setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
        {

            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);        
            
            m_stop->setPos(sp->recordPos[0], sp->recordPos[1]);   
            m_resume->setPos(sp->recPausePos[0], sp->recPausePos[1]);    
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif            
            m_zoomer->setPos(sp->zoomControlPos[0], sp->zoomControlPos[1]);                  

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);     
            m_zoomer->setOpacity(1);            
        }
        else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR || m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
            setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);        

            m_stop->setPos(sp->recordPos[0], sp->recordPos[1]);   
            m_resume->setPos(sp->recPausePos[0], sp->recPausePos[1]);          
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) + m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(sp->zoomControlPos[0], sp->zoomControlPos[1]);                  

            m_zoomer->setVertical(VFX_TRUE);
            m_zoomer->setInverse(VFX_TRUE);       
            m_zoomer->setOpacity(0);            

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
            
    }    
    else 
#endif        
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
        {

            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);         
            
            m_stop->setPos(coordTransform2Vertical(sp->recordPos[0], sp->recordPos[1]));   
            m_resume->setPos(coordTransform2Vertical(sp->recPausePos[0], sp->recPausePos[1]));   
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0], sp->zoomControlPos[1]));                  

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE); 
            m_zoomer->setOpacity(1);   
        }
        else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR || m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
            setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);         
            
            m_stop->setPos(coordTransform2Vertical(sp->recordPos[0], sp->recordPos[1]));   
            m_resume->setPos(coordTransform2Vertical(sp->recPausePos[0], sp->recPausePos[1]));   
        #ifndef __VAPP_CAMCO_ROTATABLE_UI__    // when rotate UI is ON, location will be decided when call setRotate            
            if(m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height > 0)
                m_recIcon->setPos(sp->recIndicatorPos[0], m_cntx.previewWindow.origin.y - (m_cntx.previewWindow.size.height>>1) - m_recInfo->getSize().height);
            else
                m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
            m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);  
        #endif    
            m_zoomer->setPos(coordTransform2Vertical(sp->zoomControlPos[0], sp->zoomControlPos[1]));                  

            m_zoomer->setVertical(VFX_FALSE);
            m_zoomer->setInverse(VFX_FALSE); 
            m_zoomer->setOpacity(0);               

            m_timelapseIcon->setPos(sp->statusIconPos[6][0],  sp->statusIconPos[6][1]);
        }
    }


};


void OSDRecPauseState::onResetTimerTick(VfxTimer *source)
{
    setClearMode();
    m_resetScreenTimer->stop();    
}

void OSDRecPauseState::onResumeClicked(VfxObject *obj, VfxId id)
{
    if(!m_isActive)
        return;

    evtHdlr->recPauseHdlr(VAPP_CAMCO_EVT_REC_RESUME, NULL);
}

void OSDRecPauseState::onStopClicked(VfxObject *obj, VfxId id)
{
    if(!m_isActive)
        return;

    evtHdlr->recPauseHdlr(VAPP_CAMCO_EVT_REC_STOP, NULL);
}

void OSDRecPauseState::ZoomingIn(VfxTimer *source)
{
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     
    m_resetScreenTimer->start();    
    m_zoomingTimer->start();                    

}

void OSDRecPauseState::ZoomingOut(VfxTimer *source)
{

    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      
    m_resetScreenTimer->start();     
    m_zoomingTimer->start();
                 
}

VfxBool OSDRecPauseState::onPenInput(VfxPenEvent & event)
{
    m_resetScreenTimer->start();      

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_TRANSITION)
        {
            setNormalMode();            
                        
            m_fadeOutScreenTimer->stop();                 
        }                
        else if(m_mode != VAPP_CAMCO_REC_MODE_CLEAR)
        {
            setNormalMode();    
        }        
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
        {
            setNormalMode();    
        }   
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return VFX_TRUE;

}


VfxBool OSDRecPauseState::onKeyInput(VfxKeyEvent & event)
{
    m_resetScreenTimer->start();    

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_ENTER:
        case VFX_KEY_CODE_CAMERA:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {            
                evtHdlr->recPauseHdlr(VAPP_CAMCO_EVT_REC_STOP, NULL);            
            }
            break;
        }
        case VFX_KEY_CODE_VOL_UP:
        case VFX_KEY_CODE_ARROW_UP:               
        {          
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {      
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PAUSE_SET_ZOOM_SETTING);                                     
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {             
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPauseState::ZoomingOut);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecPauseState::ZoomingIn);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                    
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }                
             }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }                      
            return VFX_TRUE;            
        }            
        case VFX_KEY_CODE_VOL_DOWN:
        case VFX_KEY_CODE_ARROW_DOWN:                
        {          
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PAUSE_SET_ZOOM_SETTING);                   
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
                {
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPauseState::ZoomingIn);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecPauseState::ZoomingOut);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }                
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }                  
            return VFX_TRUE;            
        }    
        case VFX_KEY_CODE_ARROW_LEFT:                            
        {
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) > m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM))                                    
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) - 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                      

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPauseState::ZoomingIn);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecPauseState::ZoomingOut);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }            
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_ARROW_RIGHT:                      
        {
           
            if(m_mode == VAPP_CAMCO_REC_MODE_NORMAL)
            {
                if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)  
                    return VFX_TRUE;                  
            
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {             
                    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) < m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM))
                        m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM) + 1);
                    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));                     

                    m_zoomingTimer->m_signalTick.disconnect(this, &OSDRecPauseState::ZoomingOut);   
                    m_zoomingTimer->m_signalTick.connect(this, &OSDRecPauseState::ZoomingIn);
                    m_zoomingTimer->setStartDelay(100);
                    m_zoomingTimer->start();                    
                }
                else if(event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_zoomingTimer->stop();
                }
            }            
            else if(m_mode == VAPP_CAMCO_REC_MODE_CLEAR)
            {            
                setNormalMode();    
            }            
            return VFX_TRUE;             
        }           
        case VFX_KEY_CODE_BACK:
        {
            evtHdlr->recPauseHdlr(VAPP_CAMCO_EVT_REC_STOP_EXIT, NULL);            
            return VFX_TRUE;             
        }        
        case VFX_KEY_CODE_HOME:
        {
            return CamcoOSDState::onKeyInput(event);
    }
    }
    return VFX_TRUE;
}


void OSDCamQuickViewState::onInit(void)
{
    CamcoOSDState::onInit();
    
    VFX_OBJ_CREATE(m_shownImage, VfxImageFrame, this);  
    m_shownImage->setAnchor(0.5, 0.5);
    m_shownImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT); 

    VFX_OBJ_CREATE(m_effectTimer, VfxTimer, this);

    m_state = VAPP_CAMCO_OSD_STATE_CAMERA_QUICK_VIEW;        

    m_effectTimer->m_signalTick.connect(this, &OSDCamQuickViewState::onEffectTimerTick);    

};

void OSDCamQuickViewState::enterState(void* param)
{
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_cam_quick_view_param_struct));

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


    m_effectTimer->setStartDelay(1800);
    m_effectTimer->start();        

};

void OSDCamQuickViewState::onEffectTimerTick(VfxTimer *source)
{
    if(!VAPP_CAMCO_CAM_QK_VIEW_ANUMATE)
    {
        onEndOfTimeline(NULL, VFX_FALSE);    
        return;
    }
    /*    if you modify vapp_camco_cam_qk+view_anumate , you should enable this code.
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
        timeline->m_signalStopped.connect(this, &OSDCamQuickViewState::onEndOfTimeline);
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
        timeline->m_signalStopped.connect(this, &OSDCamQuickViewState::onEndOfTimeline);    
    }
     */
    
}

void OSDCamQuickViewState::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT)
        evtHdlr->camSaveDoneHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
    else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_CONT_SHOT)
        evtHdlr->camContshotHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
    
    if(timeline)
        VFX_OBJ_CLOSE(timeline);    
    
}

void OSDCamQuickViewState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    if(m_cntx.savedImg.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_FILE)
    {
        m_shownImage->setPath(VfxWString().loadFromMem(m_cntx.savedImg.srcFileName));            
    }            
    else if(m_cntx.savedImg.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)m_cntx.savedImg.srcBuffAdress;
        imageBuf.pitchBytes = m_cntx.savedImg.srcWidth * 2;
        imageBuf.width = m_cntx.savedImg.srcWidth;
        imageBuf.height = m_cntx.savedImg.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        m_shownImage->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_JPEG)
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

        result = gdi_image_jpeg_get_dimension(
                    (U8*)param.srcJpgBuffAdress,
                    param.srcSize,
                    &image_width,
                    &image_height);

        if (result >= 0)
        {
            if ((m_shownImage->getSize().width >= image_width) && (m_shownImage->getSize().height >= image_height))
            {
                /* align preview window at the center of screen */
                offset_x = ((m_shownImage->getSize().width - image_width) >> 1);
                offset_y = ((m_shownImage->getSize().height - image_height) >> 1);

                gdi_image_jpeg_draw(
                    offset_x, 
                    offset_y, 
                    (U8*)param.srcJpgBuffAdress, 
                    param.srcSize);
            }
            else
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
    else if(m_cntx.savedImg.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_COLOR)
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



void OSDRecQuickViewState::onInit(void)
{

    CamcoOSDState::onInit();

    VFX_OBJ_CREATE(m_shownImage, VfxImageFrame, this);  
    m_shownImage->setAnchor(0.5, 0.5);

    VFX_OBJ_CREATE(m_effectTimer, VfxTimer, this);

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_QUICK_VIEW;             

    m_effectTimer->m_signalTick.connect(this, &OSDRecQuickViewState::onEffectTimerTick);    


};

void OSDRecQuickViewState::enterState(void* param)
{
    
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_quick_view_param_struct));

    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
          m_shownImage->setPos(VfxPoint(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2));          
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);    
          m_shownImage->setPos(VfxPoint(GDI_LCD_WIDTH/2, GDI_LCD_HEIGHT/2));          
    }

    drawBase(m_cntx.savedImg);

    m_effectTimer->setStartDelay(1800);
    m_effectTimer->start();       

};


void OSDRecQuickViewState::onEffectTimerTick(VfxTimer *source)
{
    if(!VAPP_CAMCO_REC_QK_VIEW_ANUMATE)
    {
        onEndOfTimeline(NULL, VFX_FALSE);    
        return;
    }
    /*    if you modify vapp_camco_cam_qk+view_anumate , you should enable this code.

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
        timeline->m_signalStopped.connect(this, &OSDRecQuickViewState::onEndOfTimeline);
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
        timeline->m_signalStopped.connect(this, &OSDRecQuickViewState::onEndOfTimeline);    
    }
     */
    
}

void OSDRecQuickViewState::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    evtHdlr->recSaveDoneHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
    if(timeline)    
        VFX_OBJ_CLOSE(timeline);    
}

void OSDRecQuickViewState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    if(m_cntx.savedImg.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)m_cntx.savedImg.srcBuffAdress;
        imageBuf.pitchBytes = m_cntx.savedImg.srcWidth * 2;
        imageBuf.width = m_cntx.savedImg.srcWidth;
        imageBuf.height = m_cntx.savedImg.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        m_shownImage->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(m_cntx.savedImg.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_COLOR)
    {
        m_shownImage->setBgColor(param.bgColor);
        m_shownImage->setSize(getSize());
    }       
    else
    {
        ASSERT(0);
    }            
};  

void OSDCamMultiQuickViewState::onInit(void)
{
    CamcoOSDState::onInit();
    
    VFX_OBJ_CREATE(m_imageFlow[1], VfxImageFrame, this);          
    VFX_OBJ_CREATE(m_imageFlow[0], VfxImageFrame, this);       
    VFX_OBJ_CREATE(m_bar, VfxImageFrame, this);          
    VFX_OBJ_CREATE(m_save, VappCamcoCpRotatableImageButton, this);         
    for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
    {
        VFX_OBJ_CREATE(m_capturedPic[i], VfxImageFrame, this);              
    }         
    VFX_OBJ_CREATE(m_ind, VfxFrame, this);         
    for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
    {
        VFX_OBJ_CREATE(m_check[i], VappCamcoCpRotatableImageFrame, this);                      
    }     
    VFX_OBJ_CREATE(m_waittingIcon, VcpActivityIndicator, this);    

    m_imageFlow[0]->setAnchor(0.5, 0.5);  
    m_imageFlow[0]->setAutoAnimate(VFX_FALSE);    
    m_imageFlow[1]->setAnchor(0.5, 0.5);
    m_imageFlow[1]->setAutoAnimate(VFX_FALSE);    

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SAVE_ICON,IMG_ID_VAPP_CAMCO_SAVE_ICON,IMG_ID_VAPP_CAMCO_SAVE_ICON,IMG_ID_VAPP_CAMCO_SAVE_ICON);
    m_save->setAnchor(0.5, 0.5);
    m_save->setImage(SI);
    m_save->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_save->setAutoAnimate(VFX_FALSE);
    m_save->setIsEffect(VFX_TRUE);
    m_save->setEffectSize(VfxSize(110, 110));    
    
    for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
    {
        m_capturedPic[i]->setAnchor(0.5, 0.5);
        m_capturedPic[i]->setBorder(VFX_COLOR_WHITE);     
        
        m_check[i]->setAnchor(0.5, 0.5);
        m_check[i]->setResId(IMG_ID_VAPP_CAMCO_UNCHECK_ICON);
        m_check[i]->setHidden(VFX_FALSE);
        
        m_isChecked[i] = VFX_FALSE;        
    }        
    
    m_ind->setAnchor(0.5,0.5);
    m_ind->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_MULTI_SHOT_INDICATOR_ICON));
    m_ind->setAutoAnimate(VFX_FALSE);
    m_ind->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    
    
    m_bar->setAnchor(0.5,0.5);
    m_bar->setBgColor(VFX_COLOR_BLACK);
    m_bar->setOpacity(0.3);    
    
    m_waittingIcon->setAnchor(0.5, 0.5);
    m_waittingIcon->setSize(100, 100);    
    m_waittingIcon->setHiddenWhenStopped(VFX_FALSE);

    m_state = VAPP_CAMCO_OSD_STATE_CAMERA_MULTI_QUICK_VIEW;  

    m_save->m_signalClicked.connect(this, &OSDCamMultiQuickViewState::onSaveClicked);   

    rotateOSD(m_isHorz, m_isMirror);

};

void OSDCamMultiQuickViewState::enterState(void* param)
{
    ASSERT(param != NULL);
    
    CamcoOSDState::enterState(param);
    
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_cam_quick_view_param_struct));

    m_active = VFX_TRUE;

    for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
    {
        m_capturedPic[i]->setOpacity(0);       
        m_capturedPic[i]->setHidden(VFX_TRUE);        
        m_check[i]->setHidden(VFX_TRUE);        
        m_check[i]->setResId(IMG_ID_VAPP_CAMCO_UNCHECK_ICON);          
        m_isChecked[i] = VFX_FALSE;        
    }   

    m_bar->setHidden(VFX_FALSE);
    if(m_cntx.isHorzUI)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);          
        
        m_save->setPos(g_vapp_camco_skin.capturePos[0], g_vapp_camco_skin.capturePos[1]);
        VfxU16 shiftIdx = (VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM - m_cntx.count)>>1;
        for(VfxU16 i=0; i < m_cntx.count; i++)    
        {
            m_capturedPic[i]->setPos(g_vapp_camco_skin.multiFramePos[i + shiftIdx][0] , g_vapp_camco_skin.multiFramePos[i + shiftIdx][1]);
            m_capturedPic[i]->setSize(g_vapp_camco_skin.multiFrameSize[i + shiftIdx][0], g_vapp_camco_skin.multiFrameSize[i + shiftIdx][1]);    
            m_capturedPic[i]->setHidden(VFX_FALSE);     
            m_capturedPic[i]->setOpacity(1);                   
            m_check[i]->setHidden(VFX_FALSE);   
            m_check[i]->setPos(
                    g_vapp_camco_skin.multiFramePos[i + shiftIdx][0] - (g_vapp_camco_skin.multiFrameSize[i + shiftIdx][0]>>1) + g_vapp_camco_skin.multiFrameCheckPos[i + shiftIdx][0], 
                    g_vapp_camco_skin.multiFramePos[i + shiftIdx][1] - (g_vapp_camco_skin.multiFrameSize[i + shiftIdx][1]>>1) + g_vapp_camco_skin.multiFrameCheckPos[i + shiftIdx][1]);
        }
        m_imageFlow[0]->setSize(m_cntx.previewWindow.size.width, m_cntx.previewWindow.size.height);
        m_imageFlow[1]->setSize(m_cntx.previewWindow.size.width, m_cntx.previewWindow.size.height);
        m_imageFlow[0]->setPos(m_cntx.previewWindow.origin.x, m_cntx.previewWindow.origin.y);
        m_imageFlow[1]->setPos(m_cntx.previewWindow.origin.x, m_cntx.previewWindow.origin.y);

        m_bar->setSize(GDI_LCD_HEIGHT, g_vapp_camco_skin.multiFrameSize[0][1] + 20);            
        m_bar->setPos(GDI_LCD_HEIGHT>>1, g_vapp_camco_skin.multiFramePos[0][1]);       

        m_waittingIcon->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);        
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
        
        m_save->setPos(coordTransform2Vertical(g_vapp_camco_skin.capturePos[0], g_vapp_camco_skin.capturePos[1]));
        VfxU16 shiftIdx = (VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM - m_cntx.count)>>1;        
        for(VfxU16 i=0; i < m_cntx.count; i++)    
        {
            m_capturedPic[i]->setPos(g_vapp_camco_skin.multiFrameVPos[i + shiftIdx][0] , g_vapp_camco_skin.multiFrameVPos[i + shiftIdx][1]);
            m_capturedPic[i]->setSize(g_vapp_camco_skin.multiFrameSize[i + shiftIdx][0], g_vapp_camco_skin.multiFrameSize[i + shiftIdx][1]);    
            m_capturedPic[i]->setHidden(VFX_FALSE);   
            m_capturedPic[i]->setOpacity(1);              
            m_check[i]->setHidden(VFX_FALSE);               
            m_check[i]->setPos(
                g_vapp_camco_skin.multiFrameVPos[i + shiftIdx][0] - (g_vapp_camco_skin.multiFrameSize[i + shiftIdx][0]>>1) + g_vapp_camco_skin.multiFrameCheckPos[i + shiftIdx][0], 
                g_vapp_camco_skin.multiFrameVPos[i + shiftIdx][1] - (g_vapp_camco_skin.multiFrameSize[i + shiftIdx][1]>>1) + g_vapp_camco_skin.multiFrameCheckPos[i + shiftIdx][1]);
        }
        m_imageFlow[0]->setSize(m_cntx.previewWindow.size.width, m_cntx.previewWindow.size.height);
        m_imageFlow[1]->setSize(m_cntx.previewWindow.size.width, m_cntx.previewWindow.size.height);
        m_imageFlow[0]->setPos(m_cntx.previewWindow.origin.x, m_cntx.previewWindow.origin.y);
        m_imageFlow[1]->setPos(m_cntx.previewWindow.origin.x, m_cntx.previewWindow.origin.y);

        m_bar->setSize(GDI_LCD_HEIGHT, g_vapp_camco_skin.multiFrameVPos[0][1] + 20);            
        m_bar->setPos(GDI_LCD_HEIGHT>>1, g_vapp_camco_skin.multiFrameVPos[0][1]);      
        
        m_waittingIcon->setPos(GDI_LCD_WIDTH>>1, GDI_LCD_HEIGHT>>1);        
    }
    m_ind->setHidden(VFX_FALSE);    
    m_ind->setSize(m_capturedPic[m_cntx.hiliteIdx]->getSize());
    m_ind->setPos(m_capturedPic[m_cntx.hiliteIdx]->getPos());      
    
    m_imageFlow[0]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_imageFlow[1]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);  

    rotateQuickView(m_cntx.isHorzCapture, m_cntx.isMirrorCapture);

    for(VfxU16 i=0; i < m_cntx.count; i++)       
    {
        m_capturedPic[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);        
        
        drawBase(m_capturedPic[i], m_cntx.capturedMultiShotImg[i]);         
    }   
    
    m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].drawingType;
    m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].srcJpgBuffAdress;
    m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].srcSize;
    m_cntx.animationImg[1].drawingType = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].drawingType;
    m_cntx.animationImg[1].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].srcJpgBuffAdress;
    m_cntx.animationImg[1].srcSize = m_cntx.capturedMultiShotImg[m_cntx.hiliteIdx].srcSize;
    
    drawBase(m_imageFlow[0], m_cntx.animationImg[0]);    
    drawBase(m_imageFlow[1], m_cntx.animationImg[1]);    

    m_waittingIcon->setHidden(VFX_TRUE);

    m_hiliteIdx = m_cntx.hiliteIdx;

    m_isImageFrameMoving = VFX_FALSE;    
    m_isAnimating = VFX_FALSE;

    rotateOSD(m_isHorz, m_isMirror);

};

void OSDCamMultiQuickViewState::exitState(void)
{
    CamcoOSDState::exitState();

    m_active = VFX_FALSE;

    m_isImageFrameMoving = VFX_FALSE;        
}

void OSDCamMultiQuickViewState::rotateQuickView(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    if(m_cntx.isHorzUI)
    {
        if(isHorz)
        {
            if(isMirror)
            {
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[1]->setTransform(t);
            }
            else
            {          
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(0);

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[1]->setTransform(t);

            }
        }
        else
        {
            if(isMirror)
            {
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-270);

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                    m_capturedPic[i]->setSize(m_capturedPic[i]->getSize().height, m_capturedPic[i]->getSize().width);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[0]->setSize(m_imageFlow[0]->getSize().height, m_imageFlow[0]->getSize().width);
                m_imageFlow[1]->setTransform(t);
                m_imageFlow[1]->setSize(m_imageFlow[1]->getSize().height, m_imageFlow[1]->getSize().width);
            }
            else
            {          
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);
                
                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                    m_capturedPic[i]->setSize(m_capturedPic[i]->getSize().height, m_capturedPic[i]->getSize().width);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[0]->setSize(m_imageFlow[0]->getSize().height, m_imageFlow[0]->getSize().width);
                m_imageFlow[1]->setTransform(t);
                m_imageFlow[1]->setSize(m_imageFlow[1]->getSize().height, m_imageFlow[1]->getSize().width);    
            }
        }
    }
    else
    {
        if(isHorz)
        {
            if(isMirror)
            {
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-90);

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                    m_capturedPic[i]->setSize(m_capturedPic[i]->getSize().height, m_capturedPic[i]->getSize().width);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[0]->setSize(m_imageFlow[0]->getSize().height, m_imageFlow[0]->getSize().width);
                m_imageFlow[1]->setTransform(t);
                m_imageFlow[1]->setSize(m_imageFlow[1]->getSize().height, m_imageFlow[1]->getSize().width);                
            }
            else
            {          
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(90);
  
                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                    m_capturedPic[i]->setSize(m_capturedPic[i]->getSize().height, m_capturedPic[i]->getSize().width);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[0]->setSize(m_imageFlow[0]->getSize().height, m_imageFlow[0]->getSize().width);
                m_imageFlow[1]->setTransform(t);
                m_imageFlow[1]->setSize(m_imageFlow[1]->getSize().height, m_imageFlow[1]->getSize().width);                
            }
        }
        else
        {
            if(isMirror)
            {
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(-180);          

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[1]->setTransform(t);
            }
            else
            {          
                VfxTransform t;
                t.setIdentity();
                t.data.affine.rz = VFX_DEG_TO_RAD(0);

                for(VfxU16 i=0; i < m_cntx.count; i++)       
                {
                    m_capturedPic[i]->setTransform(t);
                }
                m_imageFlow[0]->setTransform(t);
                m_imageFlow[1]->setTransform(t);

            }
        }    
    }
#endif
}

void OSDCamMultiQuickViewState::rotateOSD(VfxBool isHorz, VfxBool isMirror)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    // ============================================================
    // enable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {    
        m_save->setAutoAnimate(VFX_TRUE);
        for(VfxU32 i = 0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM;i++)
        {
            m_check[i]->setAutoAnimate(VFX_TRUE);
        }
    }    
    // ============================================================
    // enable autoanimation
    // ============================================================    

    m_save->setRot(m_cntx.isHorzUI, isHorz, isMirror);  
    for(VfxU32 i = 0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM;i++)
    {
        m_check[i]->setRot(m_cntx.isHorzUI, isHorz, isMirror);
    }

    // ============================================================
    // disable autoanimation
    // ============================================================    
    if(!m_isOnEnter)
    {
        m_save->setAutoAnimate(VFX_FALSE);
        for(VfxU32 i = 0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM;i++)
        {
            m_check[i]->setAutoAnimate(VFX_FALSE);
        }        
    }
    // ============================================================
    // disable autoanimation
    // ============================================================    
    
#endif
}

void OSDCamMultiQuickViewState::drawBase(VfxImageFrame *target, vapp_camco_osd_draw_image_struct param)
{
    if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_FILE)
    {
        target->setPath(VfxWString().loadFromMem(param.srcFileName));            
    }            
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_BUFF)        
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)param.srcBuffAdress;
        imageBuf.pitchBytes = param.srcWidth * 2;
        imageBuf.width = param.srcWidth;
        imageBuf.height = param.srcHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
                
        target->setImgContent(VfxImageSrc(imageBuf));
    }
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_JPEG)
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

        gdi_layer_clear(GDI_COLOR_BLACK);
        
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
    else if(param.drawingType == VAPP_CAMCO_DRAW_IMG_SRC_COLOR)        
    {
        target->setBgColor(param.bgColor);
    }
    else
    {
        ASSERT(0);
    }
    target->invalidate();

};  

VfxBool OSDCamMultiQuickViewState::onPenInput(VfxPenEvent & event)
{
    refreshAutoExitTimer();
    
    if(!m_active)
    {  
        m_isDownProcessed = VFX_TRUE;    
        return VFX_TRUE;
    }
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {

        for(VfxU16 i=0; i < m_cntx.count; i++)       
        {
            VfxPoint pos(event.getRelPos(m_capturedPic[i]));        
            
            if(m_capturedPic[i]->getBounds().contains(pos))
            {
                m_isChecked[i] = !m_isChecked[i];
                if(m_isChecked[i])
                    m_check[i]->setResId(IMG_ID_VAPP_CAMCO_CHECK_ICON);
                else
                    m_check[i]->setResId(IMG_ID_VAPP_CAMCO_UNCHECK_ICON);                    
                m_hiliteIdx = i;
                
                m_ind->setPos(m_capturedPic[m_hiliteIdx]->getPos());      
                
                m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
                m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
                m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                
                drawBase(m_imageFlow[0], m_cntx.animationImg[0]);                        
                m_isDownProcessed = VFX_TRUE;
                return VFX_TRUE;
            }
        }      
        VfxPoint pos(event.getRelPos(this));        

        if((m_cntx.isHorzUI && pos.y > (m_capturedPic[0]->getPos().y - (m_capturedPic[0]->getSize().height>>1))) || (!m_cntx.isHorzUI && pos.y < m_capturedPic[0]->getPos().y + (m_capturedPic[0]->getSize().height>>1)))
        {
            m_isDownProcessed = VFX_TRUE;        
        }
        else
        {
            m_isDownProcessed = VFX_FALSE;        
        }
        m_lastX = event.getRelPos(this).x;
        m_lastY = event.getRelPos(this).y;        
      
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_isDownProcessed)
            return VFX_TRUE;
        
        VfxTransformTimeline *timeline;
        VfxTransformTimeline *timeline2;       
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
        timeline->setTarget(m_imageFlow[1]);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_imageFlow[1]->getTransform());
        timeline->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);        
        timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline);            

        VFX_OBJ_CREATE(timeline2, VfxTransformTimeline, this);
        timeline2->setTarget(m_imageFlow[0]);
        timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline2->setFromValue(m_imageFlow[0]->getTransform());
        timeline2->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
        timeline2->setRepeatCount(1);
        timeline2->setAutoReversed(VFX_TRUE);
        timeline2->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline); 

        VfxTransform T = m_imageFlow[0]->getTransform();

        if(m_lastX < event.getRelPos(this).x)
        {
            if(m_hiliteIdx == 0)
                return VFX_TRUE;
            
            if(m_cntx.isHorzUI)
            {        
                m_imageFlow[1]->setPos((GDI_LCD_HEIGHT>>1) - GDI_LCD_HEIGHT, (GDI_LCD_WIDTH>>1));
 
                T.data.affine.tx = GDI_LCD_HEIGHT;
                timeline->setToValue(T);
                timeline->start();  
                timeline2->setToValue(T);
                timeline2->start();  

            }
            else
            {        
                m_imageFlow[1]->setPos((GDI_LCD_WIDTH>>1) - GDI_LCD_WIDTH, (GDI_LCD_HEIGHT>>1));
                
                T.data.affine.tx = GDI_LCD_WIDTH;
                timeline->setToValue(T);
                timeline->start();  
                timeline2->setToValue(T);
                timeline2->start();                  
            } 
            m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
            m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
            m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                
            m_cntx.animationImg[1].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].drawingType;
            m_cntx.animationImg[1].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].srcJpgBuffAdress;
            m_cntx.animationImg[1].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].srcSize;                            
            drawBase(m_imageFlow[0], m_cntx.animationImg[0]);              
            drawBase(m_imageFlow[1], m_cntx.animationImg[1]);          
            m_hiliteIdx = m_hiliteIdx - 1;

            m_ind->setPos(m_capturedPic[m_hiliteIdx]->getPos());     

        }
        else
        {
            if(m_hiliteIdx == m_cntx.count - 1)
                return VFX_TRUE;
            
            if(m_cntx.isHorzUI)
            {        
                m_imageFlow[1]->setPos(GDI_LCD_HEIGHT + (GDI_LCD_HEIGHT>>1), (GDI_LCD_WIDTH>>1));
 
                T.data.affine.tx = -GDI_LCD_HEIGHT;
                timeline->setToValue(T);
                timeline->start();  
                timeline2->setToValue(T);
                timeline2->start();  

            }
            else
            {        
                m_imageFlow[1]->setPos(GDI_LCD_WIDTH + (GDI_LCD_WIDTH>>1), (GDI_LCD_HEIGHT>>1));
                
                T.data.affine.tx = -GDI_LCD_WIDTH;
                timeline->setToValue(T);
                timeline->start();  
                timeline2->setToValue(T);
                timeline2->start();  
                
            } 
            m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
            m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
            m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                
            m_cntx.animationImg[1].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].drawingType;
            m_cntx.animationImg[1].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].srcJpgBuffAdress;
            m_cntx.animationImg[1].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].srcSize;                                        
            drawBase(m_imageFlow[0], m_cntx.animationImg[0]);             
            drawBase(m_imageFlow[1], m_cntx.animationImg[1]);          
            m_hiliteIdx = m_hiliteIdx + 1;

            m_ind->setPos(m_capturedPic[m_hiliteIdx]->getPos());     

        }
        return VFX_TRUE;        
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
    }
    return CamcoOSDState::onPenInput(event);

}


VfxBool OSDCamMultiQuickViewState::onKeyInput(VfxKeyEvent &event)
{
    refreshAutoExitTimer();

    switch (event.keyCode)
    {        
        case VFX_KEY_CODE_CAMERA:  
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {               
                if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT)
                {
                    evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);        
                }
                else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT)
                {    
                    evtHdlr->camAebshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
                }            
            }
            return VFX_TRUE;
        }
        case VFX_KEY_CODE_BACK:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {       
                if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT)
                {
                    evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);        
                }
                else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT)
                {    
                    evtHdlr->camAebshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
                }                                                                                                       
            }
            return VFX_TRUE;               
        }     
        case VFX_KEY_CODE_ARROW_LEFT:  
        {

            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {                   
                if(m_hiliteIdx == 0 || m_isImageFrameMoving)
                    return VFX_TRUE;

                VfxTransformTimeline *timeline;
                VfxTransformTimeline *timeline2;       
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_imageFlow[1]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_imageFlow[1]->getTransform());
                timeline->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);        
                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline);            

                VFX_OBJ_CREATE(timeline2, VfxTransformTimeline, this);
                timeline2->setTarget(m_imageFlow[0]);
                timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline2->setFromValue(m_imageFlow[0]->getTransform());
                timeline2->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
                timeline2->setRepeatCount(1);
                timeline2->setAutoReversed(VFX_TRUE);
                timeline2->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline); 

                VfxTransform T  = m_imageFlow[0]->getTransform();
                
                if(m_cntx.isHorzUI)
                {        
                    m_imageFlow[1]->setPos((GDI_LCD_HEIGHT>>1) - GDI_LCD_HEIGHT, (GDI_LCD_WIDTH>>1));
     
                    T.data.affine.tx = GDI_LCD_HEIGHT;
                    timeline->setToValue(T);
                    timeline->start();  
                    timeline2->setToValue(T);
                    timeline2->start();  

                }
                else
                {        
                    m_imageFlow[1]->setPos((GDI_LCD_WIDTH>>1) - GDI_LCD_WIDTH, (GDI_LCD_HEIGHT>>1));
                    
                    T.data.affine.tx = GDI_LCD_WIDTH;
                    timeline->setToValue(T);
                    timeline->start();  
                    timeline2->setToValue(T);
                    timeline2->start();                  
                } 
                m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
                m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
                m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                
                m_cntx.animationImg[1].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].drawingType;
                m_cntx.animationImg[1].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].srcJpgBuffAdress;
                m_cntx.animationImg[1].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx - 1].srcSize;                            
                drawBase(m_imageFlow[0], m_cntx.animationImg[0]);              
                drawBase(m_imageFlow[1], m_cntx.animationImg[1]);          
                m_hiliteIdx = m_hiliteIdx - 1;

                m_ind->setPos(m_capturedPic[m_hiliteIdx]->getPos());     

                m_isImageFrameMoving = VFX_TRUE;
            }
            return VFX_TRUE;            
        }
        case VFX_KEY_CODE_ARROW_RIGHT:                    
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {                   
                if(m_hiliteIdx == m_cntx.count - 1 || m_isImageFrameMoving)
                    return VFX_TRUE;
                
                VfxTransformTimeline *timeline;
                VfxTransformTimeline *timeline2;       
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_imageFlow[1]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_imageFlow[1]->getTransform());
                timeline->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);        
                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline);            

                VFX_OBJ_CREATE(timeline2, VfxTransformTimeline, this);
                timeline2->setTarget(m_imageFlow[0]);
                timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline2->setFromValue(m_imageFlow[0]->getTransform());
                timeline2->setDurationTime(VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED);
                timeline2->setRepeatCount(1);
                timeline2->setAutoReversed(VFX_TRUE);
                timeline2->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSlideTimeline); 

                VfxTransform T = m_imageFlow[0]->getTransform();           
                
                if(m_cntx.isHorzUI)
                {        
                    m_imageFlow[1]->setPos(GDI_LCD_HEIGHT + (GDI_LCD_HEIGHT>>1), (GDI_LCD_WIDTH>>1));
     
                    T.data.affine.tx = -GDI_LCD_HEIGHT;
                    timeline->setToValue(T);
                    timeline->start();  
                    timeline2->setToValue(T);
                    timeline2->start();  

                }
                else
                {        
                    m_imageFlow[1]->setPos(GDI_LCD_WIDTH + (GDI_LCD_WIDTH>>1), (GDI_LCD_HEIGHT>>1));
                    
                    T.data.affine.tx = -GDI_LCD_WIDTH;
                    timeline->setToValue(T);
                    timeline->start();  
                    timeline2->setToValue(T);
                    timeline2->start();  
                    
                } 
                m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
                m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
                m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                
                m_cntx.animationImg[1].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].drawingType;
                m_cntx.animationImg[1].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].srcJpgBuffAdress;
                m_cntx.animationImg[1].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx + 1].srcSize;                                        
                drawBase(m_imageFlow[0], m_cntx.animationImg[0]);             
                drawBase(m_imageFlow[1], m_cntx.animationImg[1]);          
                m_hiliteIdx = m_hiliteIdx + 1;

                m_ind->setPos(m_capturedPic[m_hiliteIdx]->getPos());     

                m_isImageFrameMoving = VFX_TRUE;
            }            
            return VFX_TRUE;                     
        }
    }
    return CamcoOSDState::onKeyInput(event);
}


void OSDCamMultiQuickViewState::onEndOfSlideTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(!m_active)
    {
        VFX_OBJ_CLOSE(timeline); 
        return;
    }

    m_isImageFrameMoving = VFX_FALSE;    
           
    if(m_cntx.isHorzUI)
    {    
        m_imageFlow[0]->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);
    }
    else
    {    
        m_imageFlow[0]->setPos(GDI_LCD_WIDTH>>1, GDI_LCD_HEIGHT>>1);
    }      
    m_cntx.animationImg[0].drawingType = m_cntx.capturedMultiShotImg[m_hiliteIdx].drawingType;
    m_cntx.animationImg[0].srcJpgBuffAdress = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcJpgBuffAdress;
    m_cntx.animationImg[0].srcSize = m_cntx.capturedMultiShotImg[m_hiliteIdx].srcSize;                    
    drawBase(m_imageFlow[0], m_cntx.animationImg[0]);
    VFX_OBJ_CLOSE(timeline);    
}

void OSDCamMultiQuickViewState::onSaveClicked(VfxObject *obj, VfxId id)
{
    if(!m_isActive)
        return;

    if(m_isAnimating)
        return;

    VfxBool isSet = VFX_FALSE;
    
    m_ind->setHidden(VFX_TRUE);
    for(VfxU16 i=0; i < m_cntx.count; i++)       
    {                        
        if(m_isChecked[i])
        {                
            VfxTransformTimeline *timeline;
            VfxTransform T = m_capturedPic[i]->getTransform();
            
            VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
            timeline->setTarget(m_capturedPic[i]);
            timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            timeline->setFromValue(m_capturedPic[i]->getTransform());
                
            timeline->setToValue(T);
            timeline->setDurationTime(200);
            timeline->setRepeatCount(1);
            timeline->setAutoReversed(VFX_TRUE);
            timeline->start();        
            
            if(!isSet)
                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSelectEffectTimeline);  
            else
                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfTimeline);  
   
            isSet = VFX_TRUE;
    
            m_check[i]->setHidden(VFX_TRUE);                
        }
    } 
    if(!isSet)
    {
        if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT)
        {
            evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);        
        }
        else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT)
        {    
            evtHdlr->camAebshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
        }
    }
    else
    {
        m_isAnimating = VFX_TRUE;
    }

  
}

void OSDCamMultiQuickViewState::onEndOfSelectEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{

    VFX_OBJ_CLOSE(timeline);

    if(!m_active)
        return;
    
    if(m_cntx.isHorzUI)
    {
        for(VfxU16 i=0; i < m_cntx.count; i++)       
        {                        
            if(!m_isChecked[i])
            {                
                VfxTransformTimeline *timeline;
                VfxTransform T = m_capturedPic[i]->getTransform();
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_capturedPic[i]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_capturedPic[i]->getTransform());

                T.data.affine.ty = (m_capturedPic[i]->getPos().y + m_capturedPic[i]->getSize().height);
                
                timeline->setToValue(T);
                timeline->setDurationTime(800);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();        

                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfTimeline);  

                m_check[i]->setHidden(VFX_TRUE);                
            }
        }
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
        timeline->setTarget(m_bar);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_bar->getTransform());

        T.data.affine.sx = 1; 
        T.data.affine.sy = 1;
        T.data.affine.rz = 0; 
        T.data.affine.tx = 0;
        T.data.affine.ty= (m_bar->getPos().y + m_bar->getSize().height);
        
        timeline->setToValue(T);
        timeline->setDurationTime(400);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();        

        timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSelectEffectTimeline2);                 
    }
    else
    {
        for(VfxU16 i=0; i < m_cntx.count; i++)       
        {                        
            if(!m_isChecked[i])
            {                
                VfxTransformTimeline *timeline;
                VfxTransform T = m_capturedPic[i]->getTransform();
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_capturedPic[i]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_capturedPic[i]->getTransform());

                T.data.affine.ty= -1*(m_capturedPic[i]->getPos().y + m_capturedPic[i]->getSize().height);
                
                timeline->setToValue(T);
                timeline->setDurationTime(800);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();        

                timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfTimeline);  

                m_check[i]->setHidden(VFX_TRUE);                
            }
        }            
        VfxTransformTimeline *timeline;
        VfxTransform T;
        
        VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
        timeline->setTarget(m_bar);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        timeline->setFromValue(m_bar->getTransform());

        T.data.affine.sx = 1; 
        T.data.affine.sy = 1;
        T.data.affine.rz = 0; 
        T.data.affine.tx = 0;
        T.data.affine.ty= -1*(m_bar->getPos().y + m_bar->getSize().height);
        
        timeline->setToValue(T);
        timeline->setDurationTime(400);
        timeline->setRepeatCount(1);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();        

        timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSelectEffectTimeline2);     
    }
}

void OSDCamMultiQuickViewState::onEndOfSelectEffectTimeline2(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_OBJ_CLOSE(timeline);

    if(!m_active)
        return;

    if(!VAPP_CAMCO_MULTI_QK_VIEW_ANUMATE)
    {
        m_waittingIcon->setHidden(VFX_FALSE);        
        m_waittingIcon->start();      
        onEndOfSaveTimeline(NULL, VFX_FALSE);    
        return;
    }
     /*    if you modify vapp_camco_cam_qk+view_anumate , you should enable this code.
    VfxBool isSet = VFX_FALSE;

    if(m_cntx.isHorzUI)
    {
        for(VfxU16 i=0; i < m_cntx.count; i++)       
        {                        
            if(m_isChecked[i])
            {                
                VfxTransformTimeline *timeline;
                VfxTransform T = m_capturedPic[i]->getTransform();
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_capturedPic[i]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_capturedPic[i]->getTransform());

                T.data.affine.sx = 40.0 / m_capturedPic[i]->getSize().width; 
                T.data.affine.sy = 30.0 / m_capturedPic[i]->getSize().height;
                T.data.affine.rz = (((90) * VFX_PI)/180.0); 
                T.data.affine.tx = 450 - m_capturedPic[i]->getPos().x;
                T.data.affine.ty= 30 - m_capturedPic[i]->getPos().y;
                
                timeline->setToValue(T);
                timeline->setDurationTime(1100);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();                  
                if(!isSet)
                    timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSaveTimeline);  
                else
                    timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfTimeline);    

                isSet = VFX_TRUE;

                m_capturedPic[i]->setOpacity(0.7);    

                m_check[i]->setHidden(VFX_TRUE);                
            }
            else
            {
                m_capturedPic[i]->setHidden(VFX_TRUE);
            }
        } 
        m_bar->setHidden(VFX_TRUE);        
        if(!isSet)
        {
            evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
            return;
        }
        
        m_waittingIcon->setHidden(VFX_FALSE);        
        m_waittingIcon->start();  

    }        
    else
    {
        for(VfxU16 i=0; i < m_cntx.count; i++)       
        {                        
            if(m_isChecked[i])
            {                
                VfxTransformTimeline *timeline;
                VfxTransform T = m_capturedPic[i]->getTransform();
                
                VFX_OBJ_CREATE(timeline, VfxTransformTimeline, this);
                timeline->setTarget(m_capturedPic[i]);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                timeline->setFromValue(m_capturedPic[i]->getTransform());

                T.data.affine.sx = 30.0 / m_capturedPic[i]->getSize().width; 
                T.data.affine.sy = 40.0 / m_capturedPic[i]->getSize().height;
                T.data.affine.rz = 0; 
                T.data.affine.tx = (GDI_LCD_WIDTH - 30) - m_capturedPic[i]->getPos().x;
                T.data.affine.ty= 450 - m_capturedPic[i]->getPos().y;

                
                timeline->setToValue(T);
                timeline->setDurationTime(1100);
                timeline->setRepeatCount(1);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->start();    
                if(!isSet)
                    timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfSaveTimeline);  
                else
                    timeline->m_signalStopped.connect(this, &OSDCamMultiQuickViewState::onEndOfTimeline);                      
                                    
                isSet = VFX_TRUE;

                m_check[i]->setHidden(VFX_TRUE);
            }
            else
            {
                m_capturedPic[i]->setHidden(VFX_TRUE);
            }            
        }  
        m_bar->setHidden(VFX_TRUE);
        
        m_waittingIcon->setHidden(VFX_FALSE);
        m_waittingIcon->start();          
    }
    */


}

void OSDCamMultiQuickViewState::onEndOfSaveTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_isAnimating = VFX_FALSE;

    if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT)
    {
        for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
        {    
            if(m_isChecked[i])
            {
                evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_MULTISHOT_SAVE, &i);  
            }
        }
        m_waittingIcon->stop(); 
        
        evtHdlr->camBurstshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
    
    }
    else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT)
    {
        for(VfxU16 i=0; i < VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM; i++)       
        {    
            if(m_isChecked[i])
            {    
                evtHdlr->camAebshotSelectHdlr(VAPP_CAMCO_EVT_MULTISHOT_SAVE, &i);  
            }
        }        
        m_waittingIcon->stop(); 
        
        evtHdlr->camAebshotSelectHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);    
    }
    if(timeline)
        VFX_OBJ_CLOSE(timeline);
}

void OSDCamMultiQuickViewState::onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_OBJ_CLOSE(timeline);
}

#endif
