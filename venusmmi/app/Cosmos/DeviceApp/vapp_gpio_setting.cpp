/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gpio_setting.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "GlobalResdef.h"
#include "mmi_features.h"
#include "gpiosrvgprot.h"
}
#endif

#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vapp_gpio_gprot.h"
#include "mmi_rp_vapp_device_def.h"

#ifndef UNUSED
#define UNUSED(p) ((void)(p))
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern "C" void vapp_gpio_setting_launch(VfxMainScr * scr)
{
    VappGPIOSettingPopup *Popup;
    VFX_OBJ_CREATE(Popup, VappGPIOSettingPopup, scr);
    UNUSED(Popup);
    return;
 /*   
    VappGPIOSettingPage *page;
    VFX_OBJ_CREATE(page, VappGPIOSettingPage, scr);
    scr->pushPage(0, page);
*/
}


/***************************************************************************** 
 * Function
 *****************************************************************************/


/***************************************************************************** 
 * VappBrightnessCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappBrightnessCell", VappBrightnessCell, VcpFormItemLauncherCell);


VappBrightnessCell::VappBrightnessCell()
{
}


void VappBrightnessCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_GPIO_BRIGHTNESS);
    m_signalTap.connect(this, &VappBrightnessCell::onTap);
}


void VappBrightnessCell::onTap(VcpFormItemCell *cell, VfxId id)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        // Entry a new page 
        VappGPIOSettingPopup *Popup;
        VFX_OBJ_CREATE(Popup, VappGPIOSettingPopup, mainScr);
        UNUSED(Popup);
    }
}

#ifdef __MMI_CABC__

/***************************************************************************** 
 * VappGpioCABCCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGpioCABCCell", VappGpioCABCCell, VcpFormItemSwitchCell);


void VappGpioCABCCell::onInit()
{
    VcpFormItemSwitchCell::onInit();
    setMainText(STR_ID_VAPP_GPIO_CABC);
    m_signalSwitchChangeReq.connect(this, &VappGpioCABCCell::onSwitch);
    if (g_phnset_gpio_cntx_p->cabc == 1)
        setSwitchStatus(VFX_TRUE);
    else
        setSwitchStatus(VFX_FALSE);
}


void VappGpioCABCCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
    setSwitchStatus(status);
    srv_gpio_setting_set_cabc((VfxU8) status);
}

#endif /* __MMI_CABC__ */

/*****************************************************************************
* Class VappGPIOSettingPopup
*****************************************************************************/ 

void VappGPIOSettingPopup::onInit()
{
    VcpSliderPopup *Popup;
    VFX_OBJ_CREATE(Popup, VcpSliderPopup, getParent());//don't this
    Popup->setTitle(STR_ID_VAPP_GPIO_BRIGHTNESS);
    Popup->m_slider->m_signalThumbReleased.connect(this, &VappGPIOSettingPopup::onSliderChange);
    Popup->m_slider->m_signalThumbDrag.connect(this, &VappGPIOSettingPopup::onSliderChange);
    Popup->m_slider->m_signalThumbPressed.connect(this, &VappGPIOSettingPopup::onSliderChange);
    Popup->m_signalButtonClicked.connect(this, &VappGPIOSettingPopup::onKeyPenInput);
    Popup->show(VFX_TRUE);
}


void VappGPIOSettingPopup::onSliderChange(VcpSlider * obj, VfxFloat newlevel)
{
    VfxS32 newVaule = (VfxS32)(newlevel + 0.4999);
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_SETTING_SLIDER_CHANGE, newVaule);
    
    srv_gpio_setting_set_bl_level((VfxS32)newVaule, MMI_FALSE);
}


void VappGPIOSettingPopup::onKeyPenInput(VfxObject* sender, VfxId id)
{
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_SETTING_SLIDER_CHANGE, 100+id);
    
    if (VCP_SLIDER_POPUP_BTN_OK == id)
    {
        srv_gpio_setting_set_bl_level(g_phnset_gpio_cntx_p->bl_setting_level, MMI_TRUE);
    }
    else if (VCP_SLIDER_POPUP_BTN_CANCEL == id)
    {
        srv_gpio_setting_bl_restore();
    }
}

/*****************************************************************************
* Class VappGPIOSettingPage
*****************************************************************************/ 

void VappGPIOSettingPage::onInit()
{
    VfxPage::onInit();  // call base class
   
    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_GPIO_BRIGHTNESS);    // set title text
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemCustomFrame *customItemSlider;
	VFX_OBJ_CREATE(customItemSlider, VcpFormItemCustomFrame, m_form);

    VfxFrame *frame;
    VFX_OBJ_CREATE(frame, VfxFrame, customItemSlider);
    frame->setSize(LCD_WIDTH, CELL_HEIGHT);
    
    VFX_OBJ_CREATE(m_slider, VcpSlider, frame);    
    m_slider->setPos(CELL_WIDTH / 2, CELL_HEIGHT / 2);
    m_slider->setAnchor(0.5, 0.5);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(SLIDER_LEN);
    m_slider->setMaxValue(5);
	m_slider->setMinValue(1);
    m_slider->setCurrentValue(g_phnset_gpio_cntx_p->bl_setting_level);
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_SETTING_CURR_VALUE, g_phnset_gpio_cntx_p->bl_setting_level);
    
    m_slider->setTotalDiscreteStepsForPen(5-1);
	m_slider->m_signalThumbReleased.connect(this, &VappGPIOSettingPage::onSliderChange);
    m_slider->m_signalThumbDrag.connect(this, &VappGPIOSettingPage::onSliderChange);
    m_slider->m_signalThumbPressed.connect(this, &VappGPIOSettingPage::onSliderChange);

    VfxImageFrame *brighness_min;
    VFX_OBJ_CREATE(brighness_min, VfxImageFrame, frame);
    brighness_min->setAnchor(0, 0.5);
    brighness_min->setPos(MIN_IMG_LEFT_TAP, CELL_HEIGHT / 2);
    brighness_min->setResId(IMG_ID_VAPP_DEVICE_BRIGHTNESS_MIN);
    
    VfxImageFrame *brighness_max;
    VFX_OBJ_CREATE(brighness_max, VfxImageFrame, frame);
    brighness_max->setAnchor(1, 0.5);
    brighness_max->setPos(CELL_WIDTH - MAX_IMG_RIGHT_TAP, CELL_HEIGHT / 2);
    brighness_max->setResId(IMG_ID_VAPP_DEVICE_BRIGHTNESS_MAX);
    
	customItemSlider->attachCustomFrame(frame);
    customItemSlider->setHeight(CELL_HEIGHT);
	m_form->addItem(customItemSlider, 0);
}


void VappGPIOSettingPage::onSliderChange(VcpSlider * obj, VfxFloat newlevel)
{
    VfxS32 newVaule = (VfxS32)(newlevel + 0.4999);
    m_slider->setCurrentValue(newVaule);
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_SETTING_SLIDER_CHANGE, newVaule);
    
	srv_gpio_setting_set_bl_level((VfxS32)newlevel, MMI_TRUE);
}


/*****************************************************************************
 * Class VcpSliderPopup
 *****************************************************************************/
VcpSliderPopup::VcpSliderPopup()
{
    m_background = NULL;
    m_okButton = NULL;
}


void VcpSliderPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);

    setPosZ(VFX_TOP_LEVEL_Z_INPUT_POPUP); 
    setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setIsCached(VFX_TRUE);
    setSize(VCP_SLIDER_POPUP_WIDTH, VCP_SLIDER_POPUP_HEIGHT + 10);
    
    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_titleBg->setSize(VCP_SLIDER_POPUP_WIDTH, VCP_SLIDER_POPUP_TITLE_HEIGHT);
    m_titleBg->setAutoAnimate(VFX_TRUE);

    // popup background
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsCached(VFX_TRUE);
    m_background->setPos(0, VCP_SLIDER_POPUP_TITLE_HEIGHT);
    m_background->setAutoAnimate(VFX_TRUE);

    // title frame
    VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, this);
    m_titleFrame->setString(m_title);
    m_titleFrame->setRect(
        VCP_SLIDER_POPUP_TITLE_X,
        VCP_SLIDER_POPUP_TITLE_Y,
        VCP_SLIDER_POPUP_WIDTH,
        VCP_SLIDER_POPUP_TITLE_HEIGHT);
    m_titleFrame->setColor(VFX_COLOR_BLACK);
    m_titleFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_titleFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_titleFrame->setColor(VfxColor(255,255,255,255));
    m_titleFrame->setAnchor(0, 0.5f);
    m_titleFrame->setPos(0, VCP_SLIDER_POPUP_TITLE_HEIGHT / 2);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_SLIDER_POPUP_TITLE_FONT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    m_titleFrame->setFont(fontDesc);
    m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_titleFrame->setAutoAnimate(VFX_TRUE);

    // brightness image
    VfxImageFrame *brighness_max;
    VFX_OBJ_CREATE(brighness_max, VfxImageFrame, this);
    brighness_max->setAnchor(0, 0.5);
    brighness_max->setPos(VCP_SLIDER_POPUP_LEFT_MARGIN, VCP_SLIDER_POPUP_CNTX_Y);
    brighness_max->setResId(IMG_ID_VAPP_DEVICE_BRIGHTNESS_MAX);

    // brightness slider
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);    
    m_slider->setPos(VCP_SLIDER_POPUP_WIDTH - VCP_SLIDER_POPUP_RIGHT_MARGIN, VCP_SLIDER_POPUP_CNTX_Y);
    m_slider->setAnchor(1, 0.5);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(VCP_SLIDER_POPUP_SLIER_LEN);
    m_slider->setMaxValue(SRV_GPIO_BACKLIGHT_MAX_LEVEL);
    m_slider->setMinValue(SRV_GPIO_BACKLIGHT_MIN_LEVEL);
    m_slider->setTotalDiscreteStepsForPen(SRV_GPIO_BACKLIGHT_MAX_LEVEL-SRV_GPIO_BACKLIGHT_MIN_LEVEL);
    
    m_slider->setCurrentValue(g_phnset_gpio_cntx_p->bl_setting_level);
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_SETTING_CURR_VALUE, g_phnset_gpio_cntx_p->bl_setting_level);

    // Ok button
    VFX_OBJ_CREATE(m_okButton, VcpButton, this);
    m_okButton->setText(STR_GLOBAL_OK);
    m_okButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_okButton->setInnerRect(VfxRect(
                VCP_SLIDER_POPUP_LEFT_MARGIN,
                VCP_SLIDER_POPUP_BUTTON_Y, 
                VCP_SLIDER_POPUP_BUTTON_WIDTH,
                VCP_SLIDER_POPUP_BUTTON_HEIGHT
                ));
    m_okButton->m_signalClicked.connect(this, &VcpSliderPopup::onButtonClick);
    VfxFontDesc btnfontDesc;
    btnfontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_SLIDER_POPUP_BTN_FONT_SIZE);
    btnfontDesc.effect = VFX_FE1_4;
    m_okButton->setTextFont(btnfontDesc);
    m_okButton->setId(VCP_SLIDER_POPUP_BTN_OK);
    m_okButton->setAutoAnimate(VFX_TRUE);

    btnfontDesc.effect = VFX_FE1_3;

    checkUpdate();
}


void VcpSliderPopup::onLeaveStack()
{
    // restore when press Home key, when popup is no-active screen.
    m_signalButtonClicked.emit(this, VCP_SLIDER_POPUP_BTN_CANCEL);
    VfxBasePopup::onLeaveStack();
}

void VcpSliderPopup::onUpdate()
{
}


void VcpSliderPopup::setTitle(const VfxWString &title)
{
    if (m_title != title)
    {
        if (m_titleFrame)
        {
            m_titleFrame->setString(title);
            m_title = title;
            checkUpdate();
        }
    }
}


void VcpSliderPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    m_signalButtonClicked.emit(this, id);
    leave(VFX_TRUE);
}


void VcpSliderPopup::onRotate(const VfxScreenRotateParam &param)
{
   // processUpdate();
    checkUpdate();
    VfxBasePopup::onRotate(param);
}


VfxBool VcpSliderPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_HOME && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_signalButtonClicked.emit(this, VCP_SLIDER_POPUP_BTN_CANCEL);
        //return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}

void VcpSliderPopup::show(VfxBool isAnim)
{
    VfxBasePopup::show(isAnim);
}


