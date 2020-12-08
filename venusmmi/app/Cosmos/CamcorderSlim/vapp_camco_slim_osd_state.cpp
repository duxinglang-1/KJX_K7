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

#include "vapp_camco_slim_osd_state.h"
#include "MMI_include.h"
#include "FileMgrResDef.h"


#ifdef __VAPP_CAMCO_SLIM__
extern vapp_camco_osd_skin g_vapp_camco_skin;

#pragma arm section code = "DYNAMIC_CODE_CAMCO_ROCODE", rodata = "DYNAMIC_CODE_CAMCO_RODATA"


void CamcoOSDState::onInit(void)
{
    VfxControl::onInit();

    setPos(0, 0);
    setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    setBgColor(VRT_COLOR_TRANSPARENT);
    evtHdlr = NULL;
    m_isHorz = VFX_TRUE;
    setAutoAnimate(VFX_FALSE);

    m_status = 0;
    setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_INACTIVE);
}

void CamcoOSDState::drawBase(vapp_camco_osd_draw_image_struct param)
{
    setBgColor(VFX_COLOR_TRANSPARENT);
}

void CamcoOSDState::enterState(void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_OSD_ENTER_STATE, m_state);

    ASSERT(param != NULL);

    setHidden(VFX_FALSE);
    setFocused(VFX_TRUE);
    m_autoExitTimer->m_signalTick.connect(this, &CamcoOSDState::onAutoExitTimerTick);
    m_autoExitTimer->start();
    setStatus(VFX_FALSE, VAPP_CAMCO_OSD_STATE_STATUS_INACTIVE);

    vapp_volume_dialog_block(MMI_TRUE);
}

void CamcoOSDState::exitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_OSD_EXIT_STATE, m_state);

    setHidden(VFX_TRUE);
    setFocused(VFX_FALSE);
    m_autoExitTimer->stop();
    m_autoExitTimer->m_signalTick.disconnect(this, &CamcoOSDState::onAutoExitTimerTick);
    setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_INACTIVE);

    vapp_volume_dialog_block(MMI_FALSE);
}

VfxPoint CamcoOSDState::coordTransform(VfxS32 x, VfxS32 y, VfxScrRotateTypeEnum targetAngle)
{
    if(targetAngle == VFX_SCR_ROTATE_TYPE_0)
        return VfxPoint(GDI_LCD_WIDTH - y, x);
    else if(targetAngle == VFX_SCR_ROTATE_TYPE_90)
        return VfxPoint(GDI_LCD_HEIGHT - x, GDI_LCD_WIDTH - y);
    else if(targetAngle == VFX_SCR_ROTATE_TYPE_180)
        return VfxPoint(y, GDI_LCD_HEIGHT - x);
    else if(targetAngle == VFX_SCR_ROTATE_TYPE_270)
        return VfxPoint(x, y);

    return VfxPoint(x, y);
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

void CamcoOSDState::setStatus(VfxBool isSet, vapp_camco_osd_state_status_enum type)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_STATUS, isSet, type);

    if(isSet)
    {
        m_status |= (1<<type);
    }
    else
    {
        m_status &= ~(1 << type);
    }
}

VfxBool CamcoOSDState::getStatus(vapp_camco_osd_state_status_enum type)
{
    if(m_status & (1<<type))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool CamcoOSDState::isUsableStatus(void)
{
    if(m_status == VAPP_CAMCO_OSD_STATE_STATUS_NORMAL)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
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
    VfxScrRotateTypeEnum fromAngle;
    VfxScrRotateTypeEnum toAngle = VFX_SCR_ROTATE_TYPE_0;

    if(!m_isHorz && !m_isMirror)
        fromAngle = VFX_SCR_ROTATE_TYPE_0;
    else if(m_isHorz && m_isMirror)
        fromAngle = VFX_SCR_ROTATE_TYPE_90;
    else if(!m_isHorz && m_isMirror)
        fromAngle = VFX_SCR_ROTATE_TYPE_180;
    else if(m_isHorz && !m_isMirror)
        fromAngle = VFX_SCR_ROTATE_TYPE_270;

    if(!isHorz && !isMirror)
        toAngle = VFX_SCR_ROTATE_TYPE_0;
    else if(isHorz && isMirror)
        toAngle = VFX_SCR_ROTATE_TYPE_90;
    else if(!isHorz && isMirror)
        toAngle = VFX_SCR_ROTATE_TYPE_180;
    else if(isHorz && !isMirror)
        toAngle = VFX_SCR_ROTATE_TYPE_270;

    m_isHorz = isHorz;
    m_isMirror = isMirror;
    m_scrnAngle = toAngle;

    if(evtHdlr)
        rotateOSD(fromAngle, toAngle);

    if(m_autoExitTimer->getIsEnabled())
        m_autoExitTimer->start();
}

void CamcoOSDState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
}

void OSDStartingState::onInit(void)
{
    CamcoOSDState::onInit();
    m_state = VAPP_CAMCO_OSD_STATE_HIDE;
}

void OSDStartingState::enterState(void* param)
{
    setHidden(VFX_FALSE);
    setFocused(VFX_TRUE);

    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableFrame, this);
   
    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_galleryContainer, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, m_galleryContainer);
    VFX_OBJ_CREATE(m_capture, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_captureContent, VappCamcoCpRotatableImageButton, m_capture);
    VFX_OBJ_CREATE(m_phone, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_card, VappCamcoCpRotatableImageButton, this);

    m_rightBar->initProperty(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON);
   
    m_gallery->initProperty(IMG_ID_VAPP_CAMCO_GALLERY_ICON);

    m_galleryContainer->setAnchor(0.5, 0.5);
    m_galleryContainer->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->initProperty(0);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setPos(m_galleryContainer->getSize().width>>1, m_galleryContainer->getSize().height>>1);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    if(!((vapp_camco_osd_starting_param_struct*)param)->isExtCalling)
        m_galleryContent->setBgColor(VFX_COLOR_BLACK);

    m_phone->initProperty(IMG_ID_VAPP_CAMCO_PHONEDRIVE);
    m_card->initProperty(IMG_ID_VAPP_CAMCO_MEMORYCARD);

    if(((vapp_camco_osd_starting_param_struct*)param)->isCamera)
    {
        m_switcher->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
        m_capture->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
        m_captureContent->initProperty(IMG_ID_VAPP_CAMCO_CAPTURE_ICON);
        m_captureContent->setPos(m_capture->getSize().width/2, m_capture->getSize().height/2);
    }
    else
    {
        m_switcher->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
        m_capture->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
        m_captureContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_REC_ICON);
        m_captureContent->setPos(m_capture->getSize().width/2, m_capture->getSize().height/2);
    }
    m_switcherRec->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_REC);
    m_switcherCam->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_CAM);

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

#ifndef __VAPP_CAMCO_NO_PUBLIC_DRV__
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
#else
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
#endif

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

    m_rightBar->setPos(coordTransform(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1, ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_gallery->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_galleryContainer->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_capture->setPos(coordTransform(sp->capturePos[0], sp->capturePos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_phone->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_card->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));
    m_switcher->setPos(coordTransform(sp->switchAppPos[0], sp->switchAppPos[1], ((vapp_camco_osd_starting_param_struct*)param)->scrnAngle));

    if(((vapp_camco_osd_starting_param_struct*)param)->isOSDHorz)
    {
        setSize(LCD_HEIGHT, LCD_WIDTH);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
       
        m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
        m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_switcher->setTransform(t);
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
       
        m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
        m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        m_switcher->setTransform(t);
    }
}

void OSDStartingState::exitState(void)
{
    VFX_OBJ_CLOSE(m_rightBar);
    VFX_OBJ_CLOSE(m_switcher);
    VFX_OBJ_CLOSE(m_switcherRec);
    VFX_OBJ_CLOSE(m_switcherCam);
    VFX_OBJ_CLOSE(m_galleryContainer);
    VFX_OBJ_CLOSE(m_gallery);
    VFX_OBJ_CLOSE(m_capture);
    VFX_OBJ_CLOSE(m_phone);
    VFX_OBJ_CLOSE(m_card);
    

    setHidden(VFX_TRUE);
    setFocused(VFX_FALSE);
}

void OSDStartingState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

    m_rightBar->setPos(coordTransform(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1, toAngle));
   m_gallery->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], toAngle));
    m_galleryContainer->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], toAngle));
    m_capture->setPos(coordTransform(sp->capturePos[0], sp->capturePos[1], toAngle));
    m_phone->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], toAngle));
    m_card->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], toAngle));
    m_switcher->setPos(coordTransform(sp->switchAppPos[0], sp->switchAppPos[1], toAngle));

    if(toAngle == VRT_SYS_SCREEN_ROTATE_90 || toAngle == VRT_SYS_SCREEN_ROTATE_270)
    {
        setSize(LCD_HEIGHT, LCD_WIDTH);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
        
        m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
        m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_switcher->setTransform(t);
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
        
        m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
        m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);

        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        m_switcher->setTransform(t);
    }
#endif
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
}

void OSDHideState::enterState(void* param)
{
    ASSERT(param != NULL);

    setHidden(VFX_TRUE);
    setFocused(VFX_TRUE);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_hide_param_struct));
    setBgColor(VFX_COLOR_TRANSPARENT);
}

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
    m_IndicatorPopup->setAutoDestory(VFX_FALSE);
    m_IndicatorPopup->setAutoAnimate(VFX_FALSE);

    m_confirmPopup->setAnchor(0.5, 0.5);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    m_confirmPopup->setAutoDestory(VFX_FALSE);
    m_confirmPopup->setAutoAnimate(VFX_FALSE);

    m_notifyPopup->setAnchor(0.5, 0.5);
    m_notifyPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    m_notifyPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    m_notifyPopup->setAutoDestory(VFX_FALSE);
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
}

void OSDHinteState::enterState(void* param)
{
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

    if(m_isHorz)
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

    rotateOSD(m_scrnAngle, m_scrnAngle);

    if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING)
    {
        m_processingPopup->show(VFX_FALSE);
    }
    else if(m_cntx.type == VAPP_CAMCO_OSD_HINT_TYPE_HINT)
    {
        m_IndicatorPopup->show(VFX_FALSE);
        m_IndicatorPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onBackClicked);
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
        m_notifyPopup->m_signalButtonClicked.connect(this, &OSDHinteState::onOkClicked);
    }

    if(!m_cntx.isPreviewON)
        drawBase(m_cntx.bgContent);
    else
        setBgColor(VFX_COLOR_TRANSPARENT);

    drawBase(m_cntx.bgContent);
}

void OSDHinteState::exitState(void)
{
    CamcoOSDState::exitState();

    m_IndicatorPopup->m_signalButtonClicked.disconnect(this, &OSDHinteState::onBackClicked);
    m_confirmPopup->m_signalButtonClicked.disconnect(this, &OSDHinteState::onConfirmClicked);
    m_notifyPopup->m_signalButtonClicked.disconnect(this, &OSDHinteState::onOkClicked);

    m_hint->setHidden(VFX_TRUE);
    m_processingPopup->hide(VFX_FALSE);
    m_IndicatorPopup->hide(VFX_FALSE);
    m_confirmPopup->hide(VFX_FALSE);
    m_notifyPopup->hide(VFX_FALSE);
}

void OSDHinteState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    if(toAngle == VRT_SYS_SCREEN_ROTATE_90 || toAngle == VRT_SYS_SCREEN_ROTATE_270)
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
}

void OSDHinteState::setHint(VfxWString hint)
{
    m_hint->setString(hint);
    m_hint->setHidden(VFX_FALSE);
}

void OSDCamPreviewState::onInit(void)
{
    CamcoOSDState::onInit();

    // create UI
    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_zoomer, VcpSlider, this);

    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom_, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_galleryContainer, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, m_galleryContainer);
    VFX_OBJ_CREATE(m_capture, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_captureContent, VappCamcoCpRotatableButton, m_capture);
    VFX_OBJ_CREATE(m_phone, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_card, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_indicatorMsgBg, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_indicatorMsg, VappCamcoCpRotatableTextFrame, this);

    m_rightBar->initProperty(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON);

    m_gallery->initProperty(IMG_ID_VAPP_CAMCO_GALLERY_ICON);

    m_galleryContainer->setAnchor(0.5, 0.5);
    m_galleryContainer->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->initProperty(0);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setPos(m_galleryContainer->getSize().width>>1, m_galleryContainer->getSize().height>>1);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    m_capture->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
    m_captureContent->initProperty(IMG_ID_VAPP_CAMCO_CAPTURE_ICON);
    m_captureContent->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_captureContent->setMargin(0, 0, 0, 0);
    m_captureContent->setBgColor(VFX_COLOR_TRANSPARENT);
    m_captureContent->setBgImageList(VcpStateImage(0));
    m_captureContent->setPos(m_capture->getSize().width/2, m_capture->getSize().height/2);

    m_phone->initProperty(IMG_ID_VAPP_CAMCO_PHONEDRIVE);
    m_card->initProperty(IMG_ID_VAPP_CAMCO_MEMORYCARD);


    m_switcher->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setIsEffect(VFX_FALSE);
    m_switcherRec->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_REC);
    m_switcherRec->setIsUnhittable(VFX_TRUE);
    m_switcherCam->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_CAM);
    m_switcherCam->setIsUnhittable(VFX_TRUE);
    m_zoom->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON);
    m_zoom->setIsUnhittable(VFX_TRUE);
    m_zoom->setOpacity(0.6);
    m_zoom_->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON);
    m_zoom_->setIsUnhittable(VFX_TRUE);
    m_zoom_->setOpacity(0.6);

   
    m_zoomer->setAnchor(0.5, 0.5);
    m_zoomer->setMaxValue(100);
    m_zoomer->setMinValue(0);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_zoomer->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_zoomer->setLength(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setLayout(VCP_SLIDER_LAYOUT_VERT);
  
    VfxFontDesc font;
    font = m_indicatorMsg->getFont();
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(25);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#else
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#endif
    m_indicatorMsg->initProperty(font);
    m_indicatorMsg->setIsUnhittable(VFX_TRUE);

    m_indicatorMsgBg->setAnchor(0.5, 0.5);
    m_indicatorMsgBg->setBgColor(VFX_COLOR_BLACK);
    m_indicatorMsgBg->setOpacity(0.5);
    m_indicatorMsgBg->setIsUnhittable(VFX_TRUE);
    m_state = VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW;

    // Create an timer
    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);

    // set action handler
   
    m_switcher->m_signalClicked.connect(this, &OSDCamPreviewState::onSwitchAppClicked);
    m_gallery->m_signalClicked.connect(this, &OSDCamPreviewState::onGalleryClicked);
    m_phone->m_signalClicked.connect(this, &OSDCamPreviewState::onSwitchDriveClicked);
    m_card->m_signalClicked.connect(this, &OSDCamPreviewState::onSwitchDriveClicked);
    m_captureContent->m_signalClicked.connect(this, &OSDCamPreviewState::onCaptureClicked);
    m_captureContent->m_signalStateChanged.connect(this, &OSDCamPreviewState::onCaptured);
    m_zoomer->m_signalThumbDrag.connect(this, &OSDCamPreviewState::onZooming);
   
    m_resetScreenTimer->m_signalTick.connect(this, &OSDCamPreviewState::onResetTimerTick);

    m_isFirstEnter = VFX_TRUE;
    m_isFocussing  = VFX_FALSE;
}

void OSDCamPreviewState::enterState(void* param)
{
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_cam_preview_param_struct));


    if(m_cntx.indicatorStringID != 0)
            m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));
    
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, m_indicatorMsg->getSize().height);

    m_zoomer->setMaxValue(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM));
    m_zoomer->setMinValue(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM));
    // cannot zoom
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) == 1)
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    if(!m_cntx.setting->IsExtSetting())
    {
        if(m_cntx.isRestartEnter)
        {
            m_galleryContent->setImgContent(VfxImageSrc());
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
            m_galleryContent->setContentDirty();
        }
    }

    m_resetScreenTimer->setStartDelay(CAMCO_CAM_PREVIEW_RESET_TIME);



    setNormalMode();
    m_resetScreenTimer->start();

    rotateOSD(m_scrnAngle, m_scrnAngle);

    // make sure form size is set and config form data
    if(m_isFirstEnter)
    {
        // =====================================================================
        // gen setting list and fill to advance setting UI
        //
        // set setting content
        m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_CAMERA);

        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);

        // =====================================================================
    }

    m_isFirstEnter = VFX_FALSE;

    // avoid to show wrong number
    
}

void OSDCamPreviewState::exitState(void)
{
    CamcoOSDState::exitState();

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;

    m_resetScreenTimer->stop();
    m_zoomingTimer->stop();

    m_isFirstEnter = VFX_TRUE;

    m_captureContent->setOpacity(1);
}



void OSDCamPreviewState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__

    layout();

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

    // ============================================================
    // set the
    // ============================================================
    // From
    VfxTransform t;
    t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) *
        (((VfxU32)toAngle - (VfxU32)fromAngle + 4) % 4);
    if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
    {
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
    }

    m_switcherRec->setTransform(t);
    m_switcherCam->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
    VfxBool isZoomerHidden = m_zoomer->getHidden();
    m_zoomer->setHidden(VFX_TRUE);

    if(m_cntx.previousFileName && mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setTransform(t);
    }

    m_capture->setTransform(t);
    m_phone->setTransform(t);
    m_card->setTransform(t);
    
    VfxBool isindicatorHidden = m_indicatorMsg->getHidden();
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);

    // ============================================================
    // enable autoanimation
    // ============================================================
    if(!m_isOnEnter)
    {
        m_switcherRec->setAutoAnimate(VFX_TRUE);
        m_switcherCam->setAutoAnimate(VFX_TRUE);
        m_zoom->setAutoAnimate(VFX_TRUE);
        m_zoom_->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_TRUE);
        m_galleryContent->setAutoAnimate(VFX_TRUE);

        m_capture->setAutoAnimate(VFX_TRUE);
        m_phone->setAutoAnimate(VFX_TRUE);
        m_card->setAutoAnimate(VFX_TRUE);
    }
    // ============================================================
    // enable autoanimation
    // ============================================================
    t.setIdentity();
   
    m_switcherRec->setTransform(t);
    m_switcherCam->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
    m_zoomer->setHidden(isZoomerHidden);
    if(m_cntx.previousFileName && mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setTransform(t);
    }

    m_capture->setTransform(t);
    m_phone->setTransform(t);
    m_card->setTransform(t);

    m_indicatorMsg->setHidden(isindicatorHidden);
    m_indicatorMsgBg->setHidden(isindicatorHidden);
    
    if(m_isMirror)
    {
        t.data.affine.sx = -1;
    }
    m_rightBar->setTransform(t);
    m_zoomer->setTransform(t);

    // ============================================================
    // disable autoanimation
    // ============================================================
    if(!m_isOnEnter)
    {
        m_switcherRec->setAutoAnimate(VFX_FALSE);
        m_switcherCam->setAutoAnimate(VFX_FALSE);
        m_zoom->setAutoAnimate(VFX_TRUE);
        m_zoom_->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_FALSE);
        m_galleryContent->setAutoAnimate(VFX_FALSE);

        m_capture->setAutoAnimate(VFX_FALSE);
        m_phone->setAutoAnimate(VFX_FALSE);
        m_card->setAutoAnimate(VFX_FALSE);
    }
    // ============================================================
    // disable autoanimation
    // ============================================================
#endif
}

void OSDCamPreviewState::updateThumbnail(WCHAR *previousFileName)
{
    m_cntx.previousFileName = previousFileName;

    if(!m_cntx.setting->IsExtSetting())
    {
        if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
        {
            S32 image_width;
            S32 image_height;
            S32 result;
            S32 resized_offset_x;
            S32 resized_offset_y;
            S32 resized_width;
            S32 resized_height;

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

            result = gdi_image_jpeg_get_dimension_file(
                        (CHAR *)m_cntx.previousFileName,
                        &image_width,
                        &image_height);

            if (result >= 0)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT,
                    m_galleryContent->getSize().width,
                    m_galleryContent->getSize().height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_jpeg_draw_resized_file(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (S8*)m_cntx.previousFileName);
            }
            else
            {
                gdi_layer_pop_and_restore_active();
                gdi_layer_free(handleT);

                m_galleryContent->setImgContent(VfxImageSrc());
                m_galleryContent->setBgColor(VFX_COLOR_BLACK);
                m_galleryContent->setContentDirty();
                return;
            }
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(handleT);

            VfxImageBuffer imageBuf;
            imageBuf.ptr = (VfxU8*)m_cntx.buffer;
            imageBuf.pitchBytes = m_galleryContent->getSize().width * 2;
            imageBuf.width = m_galleryContent->getSize().width;
            imageBuf.height = m_galleryContent->getSize().height;
            imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

            m_galleryContent->setImgContent(VfxImageSrc(imageBuf));
            m_galleryContent->setContentDirty();
        }
        else
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
        }
    }
}

void OSDCamPreviewState::updateZoomParam(VfxU32 v)
{
    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, v);
    m_zoomer->setCurrentValue(v);
}

void OSDCamPreviewState::updateIndicatorMsg(VfxU32 s)
{
    m_cntx.indicatorStringID = s;

    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));

    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, m_indicatorMsg->getSize().height);

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

void OSDCamPreviewState::setNormalMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_NORMAL_MODE, m_mode);

    m_switcher->setHidden(VFX_FALSE);
    m_switcherRec->setHidden(VFX_FALSE);
    m_switcherCam->setHidden(VFX_FALSE);
    m_zoom->setHidden(VFX_FALSE);
    m_zoom_->setHidden(VFX_FALSE);
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_CAMZOOM) != 1)
    {
        m_zoomer->setHidden(VFX_FALSE);
    }
    else
    {
       m_zoomer->setHidden(VFX_TRUE);
    }

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
    m_capture->setHidden(VFX_FALSE);
#ifndef __VAPP_CAMCO_NO_PUBLIC_DRV__
    if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE))
    {
       m_phone->setHidden(VFX_FALSE);
       m_card->setHidden(VFX_TRUE);
    }
    else if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))
    {
       m_card->setHidden(VFX_FALSE);
       m_phone->setHidden(VFX_TRUE);
    }
#else
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
#endif


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
    
   // vapp_camco_cam_preview_mode_enum preMode = m_mode;

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;

    layout();

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDCamPreviewState::setClearMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_CLEAR_MODE, m_mode);

 
    m_switcher->setHidden(VFX_FALSE);
    m_switcherRec->setHidden(VFX_FALSE);
    m_switcherCam->setHidden(VFX_FALSE);
    m_zoom->setHidden(VFX_TRUE);
    m_zoom_->setHidden(VFX_TRUE);
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

    m_capture->setHidden(VFX_FALSE);
#ifndef __VAPP_CAMCO_NO_PUBLIC_DRV__
    if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE))
    {
       m_phone->setHidden(VFX_FALSE);
       m_card->setHidden(VFX_TRUE);
    }
    else if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))
    {
       m_card->setHidden(VFX_FALSE);
       m_phone->setHidden(VFX_TRUE);
    }
#else
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
#endif


    m_rightBar->setHidden(VFX_FALSE);

#ifdef __VAPP_CAMCO_ASD_ALWAYS_SHOW_ICON__
    if(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_ASD) == VAPP_CAMCO_SCENE_DETECT_ON)
    {
        m_statusInd[1]->setHidden(VFX_FALSE);
    }
#endif

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

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDCamPreviewState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

    m_rightBar->setPos(coordTransform(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1, m_scrnAngle));
    m_gallery->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], m_scrnAngle));
    m_galleryContainer->setPos(m_gallery->getPos());
    m_capture->setPos(coordTransform(sp->capturePos[0], sp->capturePos[1], m_scrnAngle));
    m_phone->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], m_scrnAngle));
    m_card->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], m_scrnAngle));
    m_switcher->setPos(coordTransform(sp->switchAppPos[0], sp->switchAppPos[1], m_scrnAngle));
    m_zoomer->setPos(coordTransform(sp->zoomControlPos[0],sp->zoomControlPos[1], m_scrnAngle));
  
    m_indicatorMsg->setPos(coordTransform(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2, m_scrnAngle));
    m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());
    if(m_isHorz)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
      
        // switcher
        if(!m_isMirror)
        {
            m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);
            m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
            m_zoom->setPos(sp->directControlSize[0],sp->directControlSize[1]);
            m_zoom_->setPos(sp->menuControlSize[0],sp->menuControlSize[1]);
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);
        }
        else
        {
            m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);
            m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
            m_zoom->setPos(sp->directControlSize[1],sp->directControlSize[0]);
            m_zoom_->setPos(sp->menuControlSize[1],sp->menuControlSize[0]);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(180);
            m_switcher->setTransform(t);
        }


    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
     
        //switcher
        if(!m_isMirror)
        {
            m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);
            m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
            m_zoom->setPos(sp->directControlSize[0],sp->directControlSize[1]);
            m_zoom_->setPos(sp->menuControlSize[0],sp->menuControlSize[1]);
            
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);
        }
        else
        {
            m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);
            m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
            m_zoom->setPos(sp->directControlSize[1],sp->directControlSize[0]);
            m_zoom_->setPos(sp->menuControlSize[1],sp->menuControlSize[0]);
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(270);
            m_switcher->setTransform(t);
        }

    }
}



void OSDCamPreviewState::onZooming(VcpSlider *obj, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAM_PREVIEW_SET_ZOOM_SETTING, value);

    refreshAutoExitTimer();

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, value);
    m_resetScreenTimer->start();
}

void OSDCamPreviewState::onGalleryClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_GALLERY_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_ENTER_GALLERY, NULL);
}

void OSDCamPreviewState::onCaptureClicked(VfxObject* obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAPTURE_CLICK);
       refreshAutoExitTimer();
    
       if(!isUsableStatus())
           return;
       
       if(!m_indicatorMsg->getHidden())
       {    
           mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, m_indicatorMsg->getString());
           return;
       }
       else
       {
           m_switcher->setHidden(VFX_TRUE);
           m_switcherRec->setHidden(VFX_TRUE);
           m_switcherCam->setHidden(VFX_TRUE);
           m_capture->setHidden(VFX_TRUE);
           m_zoom->setHidden(VFX_TRUE);
           m_zoom_->setHidden(VFX_TRUE);
           m_zoomer->setHidden(VFX_TRUE);
           m_gallery->setHidden(VFX_TRUE);
           m_galleryContainer->setHidden(VFX_TRUE);
           m_rightBar->setHidden(VFX_TRUE);
           m_indicatorMsg->setHidden(VFX_TRUE);
           m_indicatorMsgBg->setHidden(VFX_TRUE);
           m_card->setHidden(VFX_TRUE);
           m_phone->setHidden(VFX_TRUE);
       }

       VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
       renderer->mustShowNextFrame();
    
       VfxTimer *m_captureTimer;
       VFX_OBJ_CREATE(m_captureTimer, VfxTimer, this);
       m_captureTimer->setStartDelay(1);
       m_captureTimer->m_signalTick.connect(this, &OSDCamPreviewState::onCaptureTick);
       m_captureTimer->start();
       setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);

}

void OSDCamPreviewState::onCaptureTick(VfxTimer * source)
{
    VFX_OBJ_CLOSE(source);

    setStatus(VFX_FALSE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);
    VAPP_CAMCO_START_LOGGING("ACP");
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_CAPTURE, NULL);
    m_isFocussing = VFX_FALSE;
    m_captureContent->setOpacity(1);
    VAPP_CAMCO_STOP_LOGGING("ACP");
}

void OSDCamPreviewState::onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAPTURE_STATE_CHANGE, state);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
        
            m_captureContent->setOpacity(0.5);
            break;
        case VCP_BUTTON_STATE_NORMAL:
            m_captureContent->setOpacity(1);
            break;
        default:
            break;
    }
}

void OSDCamPreviewState::onSwitchDriveClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SWITCH_SENSOR_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    if(m_phone->getHidden())
    {
      m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV));
    }
    else if(m_card->getHidden())
    {
      m_cntx.setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_CARD_DRV));
    } 
    setNormalMode();
    m_cntx.setting->needRestartPreview();
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_RESTART_PREVIEW, NULL);
}

void OSDCamPreviewState::onSwitchAppClicked(VfxObject* obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SWITCH_APP_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    VAPP_CAMCO_START_LOGGING("ASA");

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setImage(SI);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();

    VfxTimer *m_clickTimer;
    VFX_OBJ_CREATE(m_clickTimer, VfxTimer, this);
    m_clickTimer->setStartDelay(1);
    m_clickTimer->m_signalTick.connect(this, &OSDCamPreviewState::onSwitchAppTick);
    m_clickTimer->start();
    setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);
}

void OSDCamPreviewState::onSwitchAppTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    setStatus(VFX_FALSE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setImage(SI);

    if(!isUsableStatus())
        return;

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();

    if(m_cntx.setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        m_cntx.setting->setCurrApp(VAPP_CAMCO_APP_RECORDER);
    }
    else
    {
        ASSERT(0);
    }
    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_APP, NULL);
    VAPP_CAMCO_STOP_LOGGING("ASA");
}

void OSDCamPreviewState::onResetTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESET_TIMER);

    if(!isUsableStatus())
        return;

    setClearMode();
    m_resetScreenTimer->stop();
}

void OSDCamPreviewState::onDelayRestartPreviewTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    refreshAutoExitTimer();
    m_resetScreenTimer->start();

    if(!isUsableStatus())
        return;

    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_RESTART_PREVIEW, NULL);
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_PEN_INPUT, m_mode, event.type);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return VFX_TRUE;

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT && m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT)
        {
        }
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            setNormalMode();
        }
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        {
            evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);

            setNormalMode();
            if(m_cntx.setting->isNeedRestartPreview())
            {
                VfxTimer *timer;
                VFX_OBJ_CREATE(timer, VfxTimer, this);
                timer->setStartDelay(250);
                timer->m_signalTick.connect(this, &OSDCamPreviewState::onDelayRestartPreviewTick);
                timer->start();
            }
            VAPP_CAMCO_STOP_LOGGING("AAD");
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
        {
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(!m_rightBar->getBounds().contains(posR))
                setClearMode();
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
        {
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(!m_rightBar->getBounds().contains(posR))
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
    return CamcoOSDState::onPenInput(event);
}

VfxBool OSDCamPreviewState::onKeyInput(VfxKeyEvent &event)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_KEY_INPUT, m_mode, event.keyCode, event.type);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return VFX_TRUE;

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT &&
       m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

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


            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {         
                   MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAPTURE_CLICK);
                   refreshAutoExitTimer();
                
                   if(!isUsableStatus())
                       return VFX_TRUE;

                   if(!m_indicatorMsg->getHidden())
                   {    
                       mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, m_indicatorMsg->getString());
                       return VFX_TRUE;
                   }
                   else
                   {
                       m_switcher->setHidden(VFX_TRUE);
                       m_switcherRec->setHidden(VFX_TRUE);
                       m_switcherCam->setHidden(VFX_TRUE);
                       m_capture->setHidden(VFX_TRUE);
                       m_zoom->setHidden(VFX_TRUE);
                       m_zoom_->setHidden(VFX_TRUE);
                       m_zoomer->setHidden(VFX_TRUE);
                       m_gallery->setHidden(VFX_TRUE);
                       m_galleryContainer->setHidden(VFX_TRUE);
                       m_rightBar->setHidden(VFX_TRUE);
                       m_indicatorMsg->setHidden(VFX_TRUE);
                       m_indicatorMsgBg->setHidden(VFX_TRUE);
                       m_card->setHidden(VFX_TRUE);
                       m_phone->setHidden(VFX_TRUE);
                   }
                   
                   VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                   renderer->mustShowNextFrame();
                
                   VfxTimer *m_captureTimer;
                   VFX_OBJ_CREATE(m_captureTimer, VfxTimer, this);
                   m_captureTimer->setStartDelay(1);
                   m_captureTimer->m_signalTick.connect(this, &OSDCamPreviewState::onCaptureTick);
                   m_captureTimer->start();
                   setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);
                    
                
		           m_isFocussing = VFX_FALSE;
		           return VFX_TRUE;
            }
        }
        case VFX_KEY_CODE_ARROW_UP:
        case VFX_KEY_CODE_VOL_UP:
        {
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                // pass to form
                return CamcoOSDState::onKeyInput(event);
            }

            if(m_isHorz || event.keyCode == VFX_KEY_CODE_VOL_UP)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                // pass to form
                return CamcoOSDState::onKeyInput(event);
            }

            if(m_isHorz || event.keyCode == VFX_KEY_CODE_VOL_DOWN)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
        case VFX_KEY_CODE_ARROW_LEFT:
        {
            if(!m_isHorz)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
        case VFX_KEY_CODE_ARROW_RIGHT:
        {
            if(!m_isHorz)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
        case VFX_KEY_CODE_BACK:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
                {
                    evtHdlr->camPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);

                    setNormalMode();
                    if(m_cntx.setting->isNeedRestartPreview())
                    {
                        VfxTimer *timer;
                        VFX_OBJ_CREATE(timer, VfxTimer, this);
                        timer->setStartDelay(250);
                        timer->m_signalTick.connect(this, &OSDCamPreviewState::onDelayRestartPreviewTick);
                        timer->start();
                    }
                    VAPP_CAMCO_STOP_LOGGING("AAD");
                    return VFX_TRUE;
                }
                else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT)
                {
                    return VFX_TRUE;
                }
            }
        }
    }
    return CamcoOSDState::onKeyInput(event);
}

void OSDRecPreviewState::onInit(void)
{
    CamcoOSDState::onInit();

    // create UI
    VFX_OBJ_CREATE(m_rightBar, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_zoomer, VcpSlider, this);
    VFX_OBJ_CREATE(m_switcher, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_switcherRec, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_switcherCam, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom_, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_galleryContainer, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_gallery, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_galleryContent, VappCamcoCpRotatableFrame, m_galleryContainer);
    VFX_OBJ_CREATE(m_record, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_recordContent, VappCamcoCpRotatableButton, m_record);
    VFX_OBJ_CREATE(m_phone, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_card, VappCamcoCpRotatableImageButton, this);



    VFX_OBJ_CREATE(m_indicatorMsgBg, VappCamcoCpRotatableFrame, this);
    VFX_OBJ_CREATE(m_indicatorMsg, VappCamcoCpRotatableTextFrame, this);

    VFX_OBJ_CREATE(m_recordableTime, VappCamcoCpRotatableTextFrame, this);


    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        VFX_OBJ_CREATE(m_statusInd[i], VappCamcoCpRotatableImageFrame, this);
    }

    // init UI
    m_rightBar->initProperty(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON);
   
    m_gallery->initProperty(IMG_ID_VAPP_CAMCO_GALLERY_ICON);
    m_galleryContainer->setAnchor(0.5, 0.5);
    m_galleryContainer->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->initProperty(0);
    m_galleryContent->setSize(m_gallery->getSize().width - 4, m_gallery->getSize().height- 4);
    m_galleryContent->setPos(m_galleryContainer->getSize().width>>1, m_galleryContainer->getSize().height>>1);
    m_galleryContent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    m_record->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
    m_recordContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_REC_ICON);
    m_recordContent->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_recordContent->setMargin(0, 0, 0, 0);
    m_recordContent->setBgColor(VFX_COLOR_TRANSPARENT);
    m_recordContent->setBgImageList(VcpStateImage(0));
    m_recordContent->setPos(m_record->getSize().width/2, m_record->getSize().height/2);

    m_phone->initProperty(IMG_ID_VAPP_CAMCO_PHONEDRIVE);
    m_card->initProperty(IMG_ID_VAPP_CAMCO_MEMORYCARD);

    m_switcher->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setIsEffect(VFX_FALSE);
    m_switcherRec->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_REC);
    m_switcherRec->setIsUnhittable(VFX_TRUE);
    m_switcherCam->initProperty(IMG_ID_VAPP_CAMCO_SWITCHER_CAM);
    m_switcherCam->setIsUnhittable(VFX_TRUE);

    m_zoom->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON);
    m_zoom->setIsUnhittable(VFX_TRUE);
    m_zoom->setOpacity(0.6);
    m_zoom_->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON);
    m_zoom_->setIsUnhittable(VFX_TRUE);
    m_zoom_->setOpacity(0.6);

    m_zoomer->setAnchor(0.5, 0.5);
    m_zoomer->setMaxValue(100);
    m_zoomer->setMinValue(0);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_zoomer->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_zoomer->setLength(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setLayout(VCP_SLIDER_LAYOUT_VERT);

   
    for(VfxU8 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER; i++)
    {
        m_statusInd[i]->initProperty(0);
    }

    VfxFontDesc font;
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
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
    m_recordableTime->initProperty(font);
    m_recordableTime->setIsUnhittable(VFX_TRUE);

    font = m_indicatorMsg->getFont();
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(20);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(25);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#else
    font.size = VFX_FONT_DESC_VF_SIZE(16);
#endif
    m_indicatorMsg->initProperty(font);
    m_indicatorMsg->setIsUnhittable(VFX_TRUE);

    m_indicatorMsgBg->setAnchor(0.5, 0.5);
    m_indicatorMsgBg->setBgColor(VFX_COLOR_BLACK);
    m_indicatorMsgBg->setOpacity(0.5);
    m_indicatorMsgBg->setIsUnhittable(VFX_TRUE);

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW;

    // Create an timer
    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);

    // set action handler
   
    m_switcher->m_signalClicked.connect(this, &OSDRecPreviewState::onSwitchAppClicked);
    m_gallery->m_signalClicked.connect(this, &OSDRecPreviewState::onGalleryClicked);
    m_phone->m_signalClicked.connect(this, &OSDRecPreviewState::onSwitchDriveClicked);
    m_card->m_signalClicked.connect(this, &OSDRecPreviewState::onSwitchDriveClicked);
    m_recordContent->m_signalClicked.connect(this, &OSDRecPreviewState::onCaptureClicked);
    m_recordContent->m_signalStateChanged.connect(this, &OSDRecPreviewState::onCaptured);
    m_zoomer->m_signalThumbDrag.connect(this, &OSDRecPreviewState::onZooming);
   
    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecPreviewState::onResetTimerTick);

    m_isFirstEnter = VFX_TRUE;
    m_isFocussing  = VFX_FALSE;
}

void OSDRecPreviewState::enterState(void* param)
{
    CamcoOSDState::enterState(param);

    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_preview_param_struct));

    updateIcon();

    updateRemainSizeParam(m_cntx.recordableTime);

    m_zoomer->setMaxValue(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setMinValue(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));
    // cannot zoom
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    if(m_cntx.indicatorStringID != 0)
        m_indicatorMsg->setString(VFX_WSTR_RES(m_cntx.indicatorStringID));
    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20,  m_indicatorMsg->getSize().height);

    if(!m_cntx.setting->IsExtSetting())
    {
        if(m_cntx.isRestartEnter)
        {
            m_galleryContent->setImgContent(VfxImageSrc());
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
            m_galleryContent->setContentDirty();
        }
    }

    m_resetScreenTimer->setStartDelay(CAMCO_REC_PREVIEW_RESET_TIME);
    m_resetScreenTimer->start();

   

   

    setNormalMode();
    m_resetScreenTimer->start();

    rotateOSD(m_scrnAngle, m_scrnAngle);

    // make sure form size is set and config form data
    if(m_isFirstEnter)
    {
        // =====================================================================
        // gen setting list and fill to advance setting UI
        // set setting content
        m_cntx.setting->genMainList(VAPP_CAMCO_SETTING_MAINLIST_RECORDER);

        vapp_camco_setting_list_struct settingList;
        m_cntx.setting->getSettingList(&settingList);
        // =====================================================================
    }

    m_isFirstEnter = VFX_FALSE;

    // avoid to show wrong number
    if(m_cntx.isRestartEnter)
    {
        m_recordableTime->setHidden(VFX_TRUE);
    }
}

void OSDRecPreviewState::exitState(void)
{
    CamcoOSDState::exitState();

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;

    m_resetScreenTimer->stop();
    m_zoomingTimer->stop();

    m_isFirstEnter = VFX_TRUE;

    m_recordContent->setOpacity(1);
}

void OSDRecPreviewState::updateThumbnail(WCHAR *previousFileName)
{
    m_cntx.previousFileName = previousFileName;

    if(!m_cntx.setting->IsExtSetting())
    {
        memset(m_cntx.buffer, 0, m_galleryContent->getSize().width * m_galleryContent->getSize().height * 2);

        if(mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
        {
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

            if(ret == MDI_RES_VDOPLY_SUCCEED)
            {
                gdi_handle handleT;

                gdi_layer_create_cf_using_outside_memory(
                    mdi_video_ply_get_default_frame_color_format(),
                    0,
                    0,
                    m_galleryContent->getSize().width,
                    m_galleryContent->getSize().height,
                    &handleT,
                    (U8*)m_cntx.buffer,
                    m_galleryContent->getSize().width*m_galleryContent->getSize().height*2);

                gdi_layer_push_and_set_active(handleT);

                mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);

                ret = mdi_video_ply_seek_and_get_frame(0, handleT);

                gdi_layer_pop_and_restore_active();

                mdi_video_ply_close_clip_file();

                gdi_layer_free(handleT);

                if(ret != MDI_RES_VDOPLY_SUCCEED)
                {
                    m_galleryContent->setImgContent(VfxImageSrc());
                    m_galleryContent->setBgColor(VFX_COLOR_BLACK);
                    m_galleryContent->setContentDirty();
                    return;
                }
            }
            else
            {
                m_galleryContent->setImgContent(VfxImageSrc());
                m_galleryContent->setBgColor(VFX_COLOR_BLACK);
                m_galleryContent->setContentDirty();
                return;
            }

            VfxImageBuffer imageBuf;
            imageBuf.ptr = (VfxU8*)m_cntx.buffer;
            imageBuf.pitchBytes = m_galleryContent->getSize().width * 2;
            imageBuf.width = m_galleryContent->getSize().width;
            imageBuf.height = m_galleryContent->getSize().height;
            if(mdi_video_ply_get_default_frame_color_format() == GDI_COLOR_FORMAT_16)
                imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
            else
                imageBuf.colorFormat = VRT_COLOR_TYPE_UYVY422;

            m_galleryContent->setImgContent(VfxImageSrc(imageBuf));
            m_galleryContent->setContentDirty();
        }
        else
        {
            m_galleryContent->setBgColor(VFX_COLOR_BLACK);
        }
    }
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
    m_recordableTime->setHidden(VFX_FALSE);
   
}


void OSDRecPreviewState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    layout();

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

    // ============================================================
    // set the
    // ============================================================
    // From
    VfxTransform t;
    t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) *
        (((VfxU32)toAngle - (VfxU32)fromAngle + 4) % 4);
    if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
    {
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
    }

   
    m_switcherRec->setTransform(t);
    m_switcherCam->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
    VfxBool isZoomerHidden = m_zoomer->getHidden();
    m_zoomer->setHidden(VFX_TRUE);
    
    if(m_cntx.previousFileName && mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setTransform(t);
    }

    m_record->setTransform(t);
    m_phone->setTransform(t);
    m_card->setTransform(t);

    for(VfxU32 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER ;i++)
    {
        m_statusInd[i]->setTransform(t);
    }

    VfxBool isNumberHidden = m_recordableTime->getHidden();
    m_recordableTime->setHidden(VFX_TRUE);

    VfxBool isindicatorHidden = m_indicatorMsg->getHidden();
    m_indicatorMsg->setHidden(VFX_TRUE);
    m_indicatorMsgBg->setHidden(VFX_TRUE);

    // ============================================================
    // enable autoanimation
    // ============================================================
    if(!m_isOnEnter)
    {
        
        m_switcherRec->setAutoAnimate(VFX_TRUE);
        m_switcherCam->setAutoAnimate(VFX_TRUE);
        m_zoom->setAutoAnimate(VFX_TRUE);
        m_zoom_->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_TRUE);
        m_galleryContent->setAutoAnimate(VFX_TRUE);

        m_record->setAutoAnimate(VFX_TRUE);
        m_phone->setAutoAnimate(VFX_TRUE);
        m_card->setAutoAnimate(VFX_TRUE);
    }
    // ============================================================
    // enable autoanimation
    // ============================================================
    t.setIdentity();

   
    m_switcherRec->setTransform(t);
    m_switcherCam->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
    m_zoomer->setHidden(isZoomerHidden);

    if(m_cntx.previousFileName && mmi_wcscmp(m_cntx.previousFileName, (const WCHAR *) L""))
    {
        m_galleryContent->setTransform(t);
    }

    m_record->setTransform(t);
    m_phone->setTransform(t);
    m_card->setTransform(t);

    for(VfxU32 i = 0; i < CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER ;i++)
    {
        m_statusInd[i]->setTransform(t);
    }

    m_recordableTime->setHidden(isNumberHidden);

    m_indicatorMsg->setHidden(isindicatorHidden);
    m_indicatorMsgBg->setHidden(isindicatorHidden);

    if(m_isMirror)
    {
        t.data.affine.sx = -1;
    }
    m_rightBar->setTransform(t);
    m_zoomer->setTransform(t);

    // ============================================================
    // disable autoanimation
    // ============================================================
    if(!m_isOnEnter)
    {
        
        m_switcherRec->setAutoAnimate(VFX_FALSE);
        m_switcherCam->setAutoAnimate(VFX_FALSE);
        m_zoom->setAutoAnimate(VFX_TRUE);
        m_zoom_->setAutoAnimate(VFX_TRUE);

        m_gallery->setAutoAnimate(VFX_FALSE);
        m_galleryContent->setAutoAnimate(VFX_FALSE);

        m_record->setAutoAnimate(VFX_FALSE);
        m_phone->setAutoAnimate(VFX_FALSE);
        m_card->setAutoAnimate(VFX_FALSE);
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

    m_indicatorMsgBg->setSize(m_indicatorMsg->getSize().width + 20, m_indicatorMsg->getSize().height);

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

void OSDRecPreviewState::setNormalMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_NORMAL_MODE, m_mode);

   
    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
        m_zoom->setHidden(VFX_FALSE);
        m_zoom_->setHidden(VFX_FALSE);
    }
    else
    {
        m_switcher->setHidden(VFX_TRUE);
        m_switcherRec->setHidden(VFX_TRUE);
        m_switcherCam->setHidden(VFX_TRUE);
        
    }

    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)
    {
        m_zoomer->setHidden(VFX_FALSE);
    }
    else
    {
       m_zoomer->setHidden(VFX_TRUE);
    }

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

    m_record->setHidden(VFX_FALSE);
#ifndef __VAPP_CAMCO_NO_PUBLIC_DRV__
    if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE))
    {
       m_phone->setHidden(VFX_FALSE);
       m_card->setHidden(VFX_TRUE);
    }
    else if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))
    {
       m_card->setHidden(VFX_FALSE);
       m_phone->setHidden(VFX_TRUE);
    }
#else
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
#endif


    m_rightBar->setHidden(VFX_FALSE);

    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_statusInd[0]->setHidden(VFX_FALSE);
    }
    else
    {
        m_statusInd[0]->setHidden(VFX_TRUE);
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

//    vapp_camco_rec_preview_mode_enum preMode = m_mode;

    m_mode = VAPP_CAMCO_PREVIEW_MODE_NORMAL;

    layout();

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDRecPreviewState::setClearMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_CLEAR_MODE, m_mode);

   
    if(!m_cntx.setting->IsExtSetting())
    {
        m_switcher->setHidden(VFX_FALSE);
        m_switcherRec->setHidden(VFX_FALSE);
        m_switcherCam->setHidden(VFX_FALSE);
        m_zoom->setHidden(VFX_TRUE);
        m_zoom_->setHidden(VFX_TRUE);
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

    m_record->setHidden(VFX_FALSE);
#ifndef __VAPP_CAMCO_NO_PUBLIC_DRV__
    if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE))
    {
       m_phone->setHidden(VFX_FALSE);
       m_card->setHidden(VFX_TRUE);
    }
    else if(m_cntx.setting->getStorage() == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))
    {
       m_card->setHidden(VFX_FALSE);
       m_phone->setHidden(VFX_TRUE);
    }
#else
    m_phone->setHidden(VFX_TRUE);
    m_card->setHidden(VFX_TRUE);
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

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDRecPreviewState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;

    m_rightBar->setPos(coordTransform(GDI_LCD_HEIGHT - (sp->softkeyBarSize[0]>>1), sp->softkeyBarSize[1]>>1, m_scrnAngle));
    m_gallery->setPos(coordTransform(sp->galleryPos[0], sp->galleryPos[1], m_scrnAngle));
    m_galleryContainer->setPos(m_gallery->getPos());
    m_record->setPos(coordTransform(sp->capturePos[0], sp->capturePos[1], m_scrnAngle));
    m_phone->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], m_scrnAngle));
    m_card->setPos(coordTransform(sp->switchSensorPos[0], sp->switchSensorPos[1], m_scrnAngle));
    m_switcher->setPos(coordTransform(sp->switchAppPos[0], sp->switchAppPos[1], m_scrnAngle));
    m_zoomer->setPos(coordTransform(sp->zoomControlPos[0],sp->zoomControlPos[1], m_scrnAngle));  
    m_indicatorMsg->setPos(coordTransform(GDI_LCD_HEIGHT/2, GDI_LCD_WIDTH/2, m_scrnAngle));
    m_indicatorMsgBg->setPos(m_indicatorMsg->getPos());

    if(m_isHorz)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[0],sp->softkeyBarSize[1]);
        
        //switcher
        if(!m_isMirror)
        {
            m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);
            m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
            m_zoom->setPos(sp->directControlSize[0],sp->directControlSize[1]);
            m_zoom_->setPos(sp->menuControlSize[0],sp->menuControlSize[1]);
            
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_switcher->setTransform(t);
        }
        else
        {
            m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);
            m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
            m_zoom->setPos(sp->directControlSize[1],sp->directControlSize[0]);
            m_zoom_->setPos(sp->menuControlSize[1],sp->menuControlSize[0]);
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(180);
            m_switcher->setTransform(t);
        }

        
        // direct setting
       
        // advance setting enter animation
        
        // status icon and remain number
        if(!m_isMirror)
        {
            m_recordableTime->setAnchor(0, 0.5);
            VfxPoint p = VfxPoint(sp->remainNuminfoPos[0], sp->remainNuminfoPos[1]);
           
            m_recordableTime->setPos(p.x, p.y);
            m_statusInd[0]->setPos(m_recordableTime->getPos().x + m_recordableTime->getSize().width + m_statusInd[0]->getSize().width,  m_recordableTime->getPos().y);
        }
        else
        {
            m_recordableTime->setAnchor(1, 0.5);
            VfxPoint p = VfxPoint(GDI_LCD_HEIGHT - sp->remainNuminfoPos[0], GDI_LCD_WIDTH - sp->remainNuminfoPos[1]);
           
            m_statusInd[0]->setPos(p.x, p.y);
            m_recordableTime->setPos(m_statusInd[0]->getPos().x - m_statusInd[0]->getSize().width,  m_statusInd[0]->getPos().y);
        }
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);

        m_rightBar->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_V_RIGHT_BAR_ICON));
        m_rightBar->setSize(sp->softkeyBarSize[1],sp->softkeyBarSize[0]);
    
        //switcher
        if(!m_isMirror)
        {
            m_switcherCam->setPos(sp->flashSettingPos[0],sp->flashSettingPos[1]);
            m_switcherRec->setPos(sp->advanceSettingPos[0],sp->advanceSettingPos[1]);
            m_zoom->setPos(sp->directControlSize[0],sp->directControlSize[1]);
            m_zoom_->setPos(sp->menuControlSize[0],sp->menuControlSize[1]);
            
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_switcher->setTransform(t);
        }
        else
        {
            m_switcherCam->setPos(sp->flashSettingPos[1],sp->flashSettingPos[0]);
            m_switcherRec->setPos(sp->advanceSettingPos[1],sp->advanceSettingPos[0]);
            m_zoom->setPos(sp->directControlSize[1],sp->directControlSize[0]);
            m_zoom_->setPos(sp->menuControlSize[1],sp->menuControlSize[0]);
            
            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(270);
            m_switcher->setTransform(t);
        }

        // direct setting
        
        // status icon and remain number
        if(!m_isMirror)
        {
            m_recordableTime->setAnchor(1, 0.5);
            VfxPoint p = VfxPoint(GDI_LCD_WIDTH - sp->remainNuminfoPos[1], sp->remainNuminfoPos[0] + (m_recordableTime->getSize().height/2));
            
            m_statusInd[0]->setPos(p.x, p.y);
            m_recordableTime->setPos(m_statusInd[0]->getPos().x - m_statusInd[0]->getSize().width,  m_statusInd[0]->getPos().y);
        }
        else
        {
            m_recordableTime->setAnchor(0, 0.5);
            VfxPoint p = VfxPoint(sp->remainNuminfoPos[1], GDI_LCD_HEIGHT - sp->remainNuminfoPos[0] - (m_recordableTime->getSize().height/2));
           
            m_recordableTime->setPos(p.x, p.y);
            m_statusInd[0]->setPos(m_recordableTime->getPos().x + m_recordableTime->getSize().width + m_statusInd[0]->getSize().width,  m_recordableTime->getPos().y);
        }
    }
}

void OSDRecPreviewState::updateIcon(void)
{
    if(m_cntx.setting->getStatus(VAPP_CAMCO_SETTING_LIMIT) != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        m_statusInd[0]->setImgContent(VfxImageSrc(m_cntx.setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_LIMIT)));
    }
}


void OSDRecPreviewState::onZooming(VcpSlider *obj, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PREVIEW_SET_ZOOM_SETTING);

    refreshAutoExitTimer();

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();
}

void OSDRecPreviewState::onGalleryClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_GALLERY_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_ENTER_GALLERY, NULL);
}

void OSDRecPreviewState::onCaptureClicked(VfxObject* obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_CAPTURE_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RECORD, NULL);
    m_isFocussing = VFX_FALSE;
    m_recordContent->setOpacity(1);
}

void OSDRecPreviewState::onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{
    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    switch (state)
    {
        case VCP_BUTTON_STATE_PRESSED:
            m_recordContent->setOpacity(0.5);
            break;
        case VCP_BUTTON_STATE_NORMAL:
            m_recordContent->setOpacity(1);
            break;
        default:
            break;
    }
}

void OSDRecPreviewState::onSwitchDriveClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SWITCH_SENSOR_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();
    if(m_phone->getHidden())
    {
      m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_PHONE_DRV));
    }
    else if(m_card->getHidden())
    {
      m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(SRV_FMGR_CARD_DRV));
    } 
    setNormalMode();
    m_cntx.setting->needRestartPreview();
    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RESTART_PREVIEW, NULL);
}

void OSDRecPreviewState::onSwitchAppClicked(VfxObject* obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SWITCH_APP_CLICK);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return;

    VAPP_CAMCO_START_LOGGING("ASA");

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_D);
    m_switcher->setImage(SI);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();

    VfxTimer *m_clickTimer;
    VFX_OBJ_CREATE(m_clickTimer, VfxTimer, this);
    m_clickTimer->setStartDelay(1);
    m_clickTimer->m_signalTick.connect(this, &OSDRecPreviewState::onSwitchAppTick);
    m_clickTimer->start();
    setStatus(VFX_TRUE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);
}

void OSDRecPreviewState::onSwitchAppTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    setStatus(VFX_FALSE, VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING);

    VcpStateImage SI = VcpStateImage(IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U,IMG_ID_VAPP_CAMCO_SWITCHER_BAR_U);
    m_switcher->setImage(SI);

    if(!isUsableStatus())
        return;

    // need to save setting for this sensor and no let sensor setting reset in initSetting();
    m_cntx.setting->storeSetting();

    if(m_cntx.setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        m_cntx.setting->setCurrApp(VAPP_CAMCO_APP_CAMERA);
    }
    else
    {
        ASSERT(0);
    }

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_SWITCH_APP, NULL);

    VAPP_CAMCO_STOP_LOGGING("ASA");
}

void OSDRecPreviewState::onResetTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESET_TIMER);

    if(!isUsableStatus())
        return;

    setClearMode();
    m_resetScreenTimer->stop();
}

void OSDRecPreviewState::onDelayRestartPreviewTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    refreshAutoExitTimer();
    m_resetScreenTimer->start();

    if(!isUsableStatus())
        return;

    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RESTART_PREVIEW, NULL);
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_PEN_INPUT, m_mode, event.type);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return VFX_TRUE;

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (m_mode == VAPP_CAMCO_PREVIEW_MODE_DIRSETTING)
        {
            setNormalMode();
        }
        else if (m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
        {
            evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);

            setNormalMode();
            if(m_cntx.setting->isNeedRestartPreview())
            {
                VfxTimer *timer;
                VFX_OBJ_CREATE(timer, VfxTimer, this);
                timer->setStartDelay(250);
                timer->m_signalTick.connect(this, &OSDRecPreviewState::onDelayRestartPreviewTick);
                timer->start();
            }
            VAPP_CAMCO_STOP_LOGGING("AAD");
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
        {
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(!m_rightBar->getBounds().contains(posR))
                setClearMode();
        }
        else if(m_mode == VAPP_CAMCO_PREVIEW_MODE_CLEAR)
        {
            VfxPoint posR  = event.getRelPos(m_rightBar);
            if(!m_rightBar->getBounds().contains(posR))
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
    return CamcoOSDState::onPenInput(event);
}

VfxBool OSDRecPreviewState::onKeyInput(VfxKeyEvent &event)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_KEY_INPUT, m_mode, event.keyCode, event.type);

    refreshAutoExitTimer();

    if(!isUsableStatus())
        return VFX_TRUE;

    // some mode no need to start fadeout timer
    if(m_mode != VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
    {
        m_resetScreenTimer->start();
    }

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

            
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN )
            {
            
                evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_RECORD, NULL);
                m_isFocussing = VFX_FALSE;
            }

            return VFX_TRUE;
        }
        case VFX_KEY_CODE_ARROW_DOWN:
        case VFX_KEY_CODE_VOL_DOWN:
        {
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                // pass to form
                return CamcoOSDState::onKeyInput(event);
            }

            if(m_isHorz || event.keyCode == VFX_KEY_CODE_VOL_DOWN)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
            if(m_mode == VAPP_CAMCO_PREVIEW_MODE_ADSETTING)
            {
                // pass to form
                return CamcoOSDState::onKeyInput(event);
            }

            if(m_isHorz || event.keyCode == VFX_KEY_CODE_VOL_UP)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
            if(!m_isHorz)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
            if(!m_isHorz)
            {
                if(m_mode == VAPP_CAMCO_PREVIEW_MODE_NORMAL)
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
                    setNormalMode();

                    evtHdlr->recPreviewHdlr(VAPP_CAMCO_EVT_BG_CAL_START, NULL);

                    if(m_cntx.setting->isNeedRestartPreview())
                    {
                        VfxTimer *timer;
                        VFX_OBJ_CREATE(timer, VfxTimer, this);
                        timer->setStartDelay(250);
                        timer->m_signalTick.connect(this, &OSDRecPreviewState::onDelayRestartPreviewTick);
                        timer->start();
                    }
                    VAPP_CAMCO_STOP_LOGGING("AAD");
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
 
    VFX_OBJ_CREATE(m_zoomer, VcpSlider, this);
    VFX_OBJ_CREATE(m_zoom, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom_, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_recIcon, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_recInfo, VappCamcoCpRotatableTextFrame, this);
    VFX_OBJ_CREATE(m_stop, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_stopContent, VappCamcoCpRotatableImageButton, m_stop);
    VFX_OBJ_CREATE(m_pause, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_pauseContent, VappCamcoCpRotatableImageButton, m_pause);
    VFX_OBJ_CREATE(m_timelapseIcon, VappCamcoCpRotatableImageFrame, this);

    m_stop->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
    m_stop->setIsEffect(VFX_FALSE);
    m_stopContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON);
    m_stopContent->setIsEffect(VFX_FALSE);
    m_stopContent->setPos(m_stop->getSize().width/2, m_stop->getSize().height/2);

    m_pause->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG2_ICON);
    m_pause->setIsEffect(VFX_FALSE);
    m_pauseContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_PAUSE_ICON);
    m_pauseContent->setIsEffect(VFX_FALSE);
    m_pauseContent->setPos(m_pause->getSize().width/2, m_pause->getSize().height/2);

    m_zoom->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON);
    m_zoom->setIsUnhittable(VFX_TRUE);
    m_zoom->setOpacity(0.6);
    m_zoom_->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON);
    m_zoom_->setIsUnhittable(VFX_TRUE);
    m_zoom_->setOpacity(0.6);

    m_zoomer->setAnchor(0.5, 0.5);
    m_zoomer->setMaxValue(100);
    m_zoomer->setMinValue(0);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_zoomer->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_zoomer->setLength(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setLayout(VCP_SLIDER_LAYOUT_VERT);

    m_recIcon->initProperty(IMG_ID_VAPP_CAMCO_RECORD_REC_IND_ICON);

    VfxFontDesc font = m_recInfo->getFont();
    font.effect = VFX_FE5_1;
    m_recInfo->initProperty(font);

    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "00:00:00");
    m_recInfo->setString(VFX_WSTR_MEM(caption));

    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING;

    m_stopContent->m_signalClicked.connect(this, &OSDRecRecordingState::onStopClicked);
    m_pauseContent->m_signalClicked.connect(this, &OSDRecRecordingState::onPauseClicked);
    m_zoomer->m_signalThumbDrag.connect(this, &OSDRecRecordingState::onZooming);
   
    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecRecordingState::onResetTimerTick);
}

void OSDRecRecordingState::enterState(void* param)
{
    CamcoOSDState::enterState(param);

    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_recording_param_struct));

    setNormalMode();

    m_zoomer->setMaxValue(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setMinValue(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    m_resetScreenTimer->setStartDelay(CAMCO_REC_RESET_TIME);
    m_resetScreenTimer->start();

    m_autoExitTimer->stop();

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDRecRecordingState::exitState(void)
{
    CamcoOSDState::exitState();

    m_resetScreenTimer->stop();
    m_zoomingTimer->stop();
}

void OSDRecRecordingState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    layout();

    VfxTransform t;
    t.setIdentity();

    if(m_isMirror)
    {
        t.data.affine.sx = -1;
    }
    m_zoomer->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
#endif
}

void OSDRecRecordingState::setNormalMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_NORMAL_MODE, m_mode);

    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)
    {
        m_zoom->setHidden(VFX_FALSE);
        m_zoom_->setHidden(VFX_FALSE);
        m_zoomer->setHidden(VFX_FALSE);
    }
    else
    {
        m_zoomer->setHidden(VFX_TRUE);
        m_zoom->setHidden(VFX_TRUE);
        m_zoom_->setHidden(VFX_TRUE);
    }


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
}

void OSDRecRecordingState::setClearMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_CLEAR_MODE, m_mode);

    m_zoomer->setHidden(VFX_TRUE);
    m_zoom->setHidden(VFX_TRUE);
    m_zoom_->setHidden(VFX_TRUE);
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
}

void OSDRecRecordingState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;
    m_stop->setPos(coordTransform(sp->recordPos[0], sp->recordPos[1], m_scrnAngle));
    m_pause->setPos(coordTransform(sp->recPausePos[0], sp->recPausePos[1], m_scrnAngle));
    if(m_isMirror)
    {
        if(!m_isHorz)
        {
            m_recIcon->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0] - m_recInfo->getSize().width - (m_recIcon->getSize().width * 0.8), sp->recIndicatorPos[1]);
            m_recInfo->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0] - (m_recInfo->getSize().width>>1), m_recIcon->getPos().y);
        }
        else
        {
            m_recIcon->setPos(GDI_LCD_HEIGHT - sp->recIndicatorPos[0] - m_recInfo->getSize().width - (m_recIcon->getSize().width * 0.8), sp->recIndicatorPos[1]);
            m_recInfo->setPos(GDI_LCD_HEIGHT - sp->recIndicatorPos[0] - (m_recInfo->getSize().width>>1), m_recIcon->getPos().y);
          
        }
        
    }
    else
    {
        m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
        m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);
     }

    m_zoomer->setPos(coordTransform(sp->zoomControlPos[0], sp->zoomControlPos[1], m_scrnAngle));
    m_zoom->setPos(coordTransform(sp->directControlSize[0],sp->directControlSize[1],m_scrnAngle));
    m_zoom_->setPos(coordTransform(sp->menuControlSize[0],sp->menuControlSize[1],m_scrnAngle));

    if(m_isHorz)
    {   
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);  
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }

    if(m_isHorz)
        m_timelapseIcon->setPos(getSize().width / 2, getSize().height - m_timelapseIcon->getSize().height);
    else
        m_timelapseIcon->setPos(m_timelapseIcon->getSize().width, getSize().height / 2);
}

void OSDRecRecordingState::onZooming(VcpSlider *obj, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_SET_ZOOM_SETTING, value);

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();
}

void OSDRecRecordingState::onResetTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESET_TIMER);

    setClearMode();
    m_resetScreenTimer->stop();
}

void OSDRecRecordingState::setRecParam(VfxU32 time, VfxU32 size)
{
    VfxWChar caption[30] = {0};
    VfxU32 ss, mm, hh;
//    VfxU32 limitedhh, limitedmm, limitedss = 0;
//    VfxU32 limitedsize = 0;
//    VfxU32 limitedFrameNumber = 0;


    ss = time%60;
    mm = time/60;
    hh = mm/60;
    mm = mm%60;
    if(hh > 99) hh = 99;

    kal_wsprintf(caption, "%02d:%02d:%02d", hh, mm, ss);
    m_recInfo->setString(VFX_WSTR_MEM(caption));

    layout();
}

void OSDRecRecordingState::onStopClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_STOP_CLICK);

    if(!isUsableStatus())
        return;

    evtHdlr->recRecordingHdlr(VAPP_CAMCO_EVT_REC_STOP, NULL);
}

void OSDRecRecordingState::onPauseClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_PAUSE_CLICK);

    if(!isUsableStatus())
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_PEN_INPUT, m_mode, event.type);

    m_resetScreenTimer->start();

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {   
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_KEY_INPUT, m_mode, event.keyCode, event.type);

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
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_SET_ZOOM_SETTING);

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

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_RECORD_SET_ZOOM_SETTING);
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
   
    VFX_OBJ_CREATE(m_zoomer, VcpSlider, this);
    VFX_OBJ_CREATE(m_zoom, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_zoom_, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_recIcon, VappCamcoCpRotatableImageFrame, this);
    VFX_OBJ_CREATE(m_recInfo, VappCamcoCpRotatableTextFrame, this);
    VFX_OBJ_CREATE(m_stop, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_stopContent, VappCamcoCpRotatableImageButton, m_stop);
    VFX_OBJ_CREATE(m_resume, VappCamcoCpRotatableImageButton, this);
    VFX_OBJ_CREATE(m_resumeContent, VappCamcoCpRotatableImageButton, m_resume);
    VFX_OBJ_CREATE(m_timelapseIcon, VappCamcoCpRotatableImageFrame, this);

    m_stop->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG1_ICON);
    m_stop->setIsEffect(VFX_FALSE);
    m_stopContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_STOP_ICON);
    m_stopContent->setIsEffect(VFX_FALSE);
    m_stopContent->setPos(m_stop->getSize().width/2, m_stop->getSize().height/2);

    m_resume->initProperty(IMG_ID_VAPP_CAMCO_BTN_BG2_ICON);
    m_resume->setIsEffect(VFX_FALSE);
    m_resumeContent->initProperty(IMG_ID_VAPP_CAMCO_RECORD_RESUME_ICON);
    m_resumeContent->setIsEffect(VFX_FALSE);
    m_resumeContent->setPos(m_resume->getSize().width/2, m_resume->getSize().height/2);

    m_zoom->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_IN_ICON);
    m_zoom->setIsUnhittable(VFX_TRUE);
    m_zoom->setOpacity(0.6);
    m_zoom_->initProperty(IMG_ID_VAPP_CAMCO_ZOOM_OUT_ICON);
    m_zoom_->setIsUnhittable(VFX_TRUE);
    m_zoom->setOpacity(0.6);

    m_zoomer->setAnchor(0.5, 0.5);
    m_zoomer->setMaxValue(100);
    m_zoomer->setMinValue(0);
    m_zoomer->setCurrentValue(50);
    m_zoomer->setAutoAnimate(VFX_FALSE);

    m_zoomer->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_zoomer->setLength(g_vapp_camco_skin.zoomCurveR);
    m_zoomer->setLayout(VCP_SLIDER_LAYOUT_VERT);

    m_recIcon->initProperty(IMG_ID_VAPP_CAMCO_RECORD_PAUSE_IND_ICON);

    VfxFontDesc font = m_recInfo->getFont();
    font.effect = VFX_FE5_1;
    m_recInfo->setFont(font);
    m_recInfo->initProperty(font);

    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "00:00:00");
    m_recInfo->setString(VFX_WSTR_MEM(caption));

    VFX_OBJ_CREATE(m_resetScreenTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_zoomingTimer, VfxTimer, this);

    m_state = VAPP_CAMCO_OSD_STATE_VIDEO_PAUSE;

    m_stopContent->m_signalClicked.connect(this, &OSDRecPauseState::onStopClicked);
    m_resumeContent->m_signalClicked.connect(this, &OSDRecPauseState::onResumeClicked);
    m_zoomer->m_signalThumbDrag.connect(this, &OSDRecPauseState::onZooming);

    m_resetScreenTimer->m_signalTick.connect(this, &OSDRecPauseState::onResetTimerTick);
}

void OSDRecPauseState::enterState(void* param)
{
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_rec_pause_param_struct));

    VfxWChar caption[30] = {0};
    VfxU32 ss, mm, hh;
//    VfxU32 limitedhh, limitedmm, limitedss = 0;
//    VfxU32 limitedsize = 0;
//    VfxU32 limitedFrameNumber = 0;

    ss = m_cntx.recTime%60;
    mm = m_cntx.recTime/60;
    hh = mm/60;
    mm = mm%60;
    if(hh > 99) hh = 99;

    kal_wsprintf(caption, "%02d:%02d:%02d", hh, mm, ss);
    m_recInfo->setString(VFX_WSTR_MEM(caption));
            
    m_zoomer->setMaxValue(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setMinValue(m_cntx.setting->getMinValue(VAPP_CAMCO_SETTING_VDOZOOM));
    m_zoomer->setCurrentValue(m_cntx.setting->getValue(VAPP_CAMCO_SETTING_VDOZOOM));
    if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) == 1)
    {
        m_zoomer->setHidden(VFX_TRUE);
    }

    setNormalMode();

    m_resetScreenTimer->setStartDelay(CAMCO_REC_RESET_TIME);
    m_resetScreenTimer->start();

    m_autoExitTimer->stop();

    rotateOSD(m_scrnAngle, m_scrnAngle);
}

void OSDRecPauseState::exitState(void)
{
    CamcoOSDState::exitState();

    m_resetScreenTimer->stop();
    m_zoomingTimer->stop();
}

void OSDRecPauseState::rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle)
{
#ifdef __VAPP_CAMCO_ROTATABLE_UI__
    layout();

    VfxTransform t;
    t.setIdentity();

    if(m_isMirror)
    {
        t.data.affine.sx = -1;
    }
    m_zoomer->setTransform(t);
    m_zoom->setTransform(t);
    m_zoom_->setTransform(t);
#endif
}

void OSDRecPauseState::setNormalMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_NORMAL_MODE, m_mode);

     if(m_cntx.setting->getMaxValue(VAPP_CAMCO_SETTING_VDOZOOM) != 1)
    {
        m_zoom->setHidden(VFX_FALSE);
        m_zoom_->setHidden(VFX_FALSE);
        m_zoomer->setHidden(VFX_FALSE);
    }
    else
    {
        m_zoomer->setHidden(VFX_TRUE);
        m_zoom->setHidden(VFX_TRUE);
        m_zoom_->setHidden(VFX_TRUE);
    }

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
}

void OSDRecPauseState::setClearMode(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SET_CLEAR_MODE, m_mode);

    m_zoomer->setHidden(VFX_TRUE);
    m_zoom->setHidden(VFX_TRUE);
    m_zoom_->setHidden(VFX_TRUE);
    m_recIcon->setHidden(VFX_FALSE);
    m_recInfo->setHidden(VFX_FALSE);
    m_stop->setHidden(VFX_FALSE);
    m_resume->setHidden(VFX_FALSE);

    m_timelapseIcon->setHidden(VFX_FALSE);

    m_mode = VAPP_CAMCO_REC_MODE_CLEAR;
}

void OSDRecPauseState::onZooming(VcpSlider *obj, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PAUSE_SET_ZOOM_SETTING, value);

    m_cntx.setting->setValue(VAPP_CAMCO_SETTING_VDOZOOM, value);
    m_resetScreenTimer->start();
}

void OSDRecPauseState::layout(void)
{
    vapp_camco_osd_skin *sp = &g_vapp_camco_skin;
    m_stop->setPos(coordTransform(sp->recordPos[0], sp->recordPos[1], m_scrnAngle));
    m_resume->setPos(coordTransform(sp->recPausePos[0], sp->recPausePos[1], m_scrnAngle));
    if(m_isMirror)
    {
        if(!m_isHorz)
        {
            m_recIcon->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0] - m_recInfo->getSize().width - (m_recIcon->getSize().width * 0.8), sp->recIndicatorPos[1]);
            m_recInfo->setPos(GDI_LCD_WIDTH - sp->recIndicatorPos[0] - (m_recInfo->getSize().width>>1), m_recIcon->getPos().y);
        }
        else
        {
            m_recIcon->setPos(GDI_LCD_HEIGHT - sp->recIndicatorPos[0] - m_recInfo->getSize().width - (m_recIcon->getSize().width * 0.8), sp->recIndicatorPos[1]);
            m_recInfo->setPos(GDI_LCD_HEIGHT - sp->recIndicatorPos[0] - (m_recInfo->getSize().width>>1), m_recIcon->getPos().y);
        }
    }
    else
    {
        m_recIcon->setPos(sp->recIndicatorPos[0], sp->recIndicatorPos[1]);
        m_recInfo->setPos(sp->recIndicatorPos[0] + (m_recInfo->getSize().width >> 1) + (m_recIcon->getSize().width * 0.8), m_recIcon->getPos().y);
    }
    m_zoomer->setPos(coordTransform(sp->zoomControlPos[0], sp->zoomControlPos[1], m_scrnAngle));
    m_zoom->setPos(coordTransform(sp->directControlSize[0],sp->directControlSize[1],m_scrnAngle));
    m_zoom_->setPos(coordTransform(sp->menuControlSize[0],sp->menuControlSize[1],m_scrnAngle));

    if(m_isHorz)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }

    if(m_isHorz)
        m_timelapseIcon->setPos(getSize().width / 2, getSize().height - m_timelapseIcon->getSize().height);
    else
        m_timelapseIcon->setPos(m_timelapseIcon->getSize().width, getSize().height / 2);
}

void OSDRecPauseState::onResetTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESET_TIMER);

    setClearMode();
    m_resetScreenTimer->stop();
}

void OSDRecPauseState::onResumeClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_RESUME_CLICK);

    if(!isUsableStatus())
        return;

    evtHdlr->recPauseHdlr(VAPP_CAMCO_EVT_REC_RESUME, NULL);
}

void OSDRecPauseState::onStopClicked(VfxObject *obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_STOP_CLICK);

    if(!isUsableStatus())
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_PEN_INPUT, m_mode, event.type);

    m_resetScreenTimer->start();

    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_ON_KEY_INPUT, m_mode, event.keyCode, event.type);

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

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PAUSE_SET_ZOOM_SETTING);
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

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_REC_PAUSE_SET_ZOOM_SETTING);
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

void OSDQuickViewState::onInit(void)
{
    CamcoOSDState::onInit();

    VFX_OBJ_CREATE(m_shownImage, VfxImageFrame, this);
    m_shownImage->setAnchor(0.5, 0.5);
    m_shownImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);

    VFX_OBJ_CREATE(m_effectTimer, VfxTimer, this);

    m_state = VAPP_CAMCO_OSD_STATE_QUICK_VIEW;

    m_effectTimer->m_signalTick.connect(this, &OSDQuickViewState::onEffectTimerTick);
}

void OSDQuickViewState::enterState(void* param)
{
    CamcoOSDState::enterState(param);
    memcpy(&m_cntx, param, sizeof(vapp_camco_osd_quick_view_param_struct));

    if(m_isHorz)
    {
        setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }
    else
    {
        setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }
    m_shownImage->setSize(getSize());
    m_shownImage->setPos(VfxPoint(getSize().width/2, getSize().height/2));

    drawBase(m_cntx.savedImg);

    
    m_effectTimer->setStartDelay(500);
    m_effectTimer->start();
}

void OSDQuickViewState::exitState(void)
{
    CamcoOSDState::exitState();

    m_effectTimer->stop();
}

void OSDQuickViewState::onEffectTimerTick(VfxTimer *source)
{
    if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT)
        evtHdlr->camSaveDoneHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
    else if(m_cntx.type == VAPP_CAMCO_OSD_QV_EVT_RECORD)
        evtHdlr->recSaveDoneHdlr(VAPP_CAMCO_EVT_VIEW_STOP, NULL);
   
}

void OSDQuickViewState::drawBase(vapp_camco_osd_draw_image_struct param)
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
}
#pragma arm section code, rodata

#endif /*__VAPP_CAMCO_SLIM__*/
