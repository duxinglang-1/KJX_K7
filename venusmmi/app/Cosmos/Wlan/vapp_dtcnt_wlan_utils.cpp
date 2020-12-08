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
 *  vapp_dtcnt_wlan_utils.cpp
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
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#ifdef __MMI_WLAN_FEATURES__
#include "GlobalResDef.h"
#include "vapp_dtcnt_wlan_utils.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Class
 *****************************************************************************/

/***************************************************************************** 
 * Class VappProfileInfoPopup
 *****************************************************************************/
VappProfileInfoPopup::VappProfileInfoPopup() :
    m_background(NULL),
    m_titleBg(NULL),
    m_titleFrame(NULL),
    m_textFrame(NULL),
    m_discButton(NULL),
    m_cancelButton(NULL)
{
    m_title = VFX_WSTR_EMPTY;
}


void VappProfileInfoPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);

    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_titleBg->setSize(CONNECTED_AP_INFO_POPUP_WIDTH, CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);
    m_titleBg->setAutoAnimate(VFX_TRUE);

    // popup background
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsCached(VFX_TRUE);
    m_background->setPos(0, CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);
    m_background->setAutoAnimate(VFX_TRUE);

    // title frame
    VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, this);
    m_titleFrame->setString(m_title);
    m_titleFrame->setColor(VFX_COLOR_BLACK);
    m_titleFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_titleFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	//m_titleFrame->setColor(VfxColor(255,255,255,255));
    m_titleFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_BAR));
    m_titleFrame->setAnchor(0.5f, 0.5f);
    m_titleFrame->setPos(CONNECTED_AP_INFO_POPUP_WIDTH / 2, CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT / 2);
    m_titleFrame->setSize(
        CONNECTED_AP_INFO_POPUP_WIDTH,
        CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(CONNECTED_AP_INFO_POPUP_TITLE_FONT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    m_titleFrame->setFont(fontDesc);
    m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_titleFrame->setAutoAnimate(VFX_TRUE);

    // info text frame
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setPos(
        CONNECTED_AP_INFO_POPUP_LR_GAP, 
        CONNECTED_AP_INFO_POPUP_TITLE_Y + CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT + CONNECTED_AP_INFO_POPUP_TD_GAP);
    m_textFrame->setAnchor(0,0);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
#if defined(__MMI_VUI_COSMOS_CP__) || defined(__VRE_SDK__)
    //m_textFrame->setColor(VfxColor(255,15,15,15));
    m_textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(CONNECTED_AP_INFO_POPUP_FONT_SIZE);
    fontDesc.effect = VFX_FONT_DESC_EFFECT_NONE;
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
#else
    m_textFrame->setColor(VfxColor(255,34,34,34));
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#endif

#ifdef __MMI_OP01_WIFI__
    m_textFrame->setMaxLines(8);
#else
    m_textFrame->setMaxLines(5);
#endif

    // Ok button
    VFX_OBJ_CREATE(m_discButton, VcpButton, this);
    m_discButton->setText(VFX_WSTR_RES(STR_GLOBAL_DISCONNECT));
    m_discButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_discButton->m_signalClicked.connect(this, &VappProfileInfoPopup::onButtonClick);
    m_discButton->setId(0);
    m_discButton->setAutoAnimate(VFX_TRUE);

    // Cancel button
    VFX_OBJ_CREATE(m_cancelButton, VcpButton, this);
    m_cancelButton->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_cancelButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_cancelButton->m_signalClicked.connect(this, &VappProfileInfoPopup::onButtonClick);
    m_cancelButton->setStyle(VCP_BUTTON_STYLE_GREY);
    m_cancelButton->setId(1);
    m_cancelButton->setAutoAnimate(VFX_TRUE);
    
    checkUpdate();
}


void VappProfileInfoPopup::onEnter()
{
    VfxBasePopup::onEnter();
}


void VappProfileInfoPopup::onExit()
{
    VfxBasePopup::onExit();
}


void VappProfileInfoPopup::onRotate(const VfxScreenRotateParam &param)
{
    processUpdate();
    VfxBasePopup::onRotate(param);
}


void VappProfileInfoPopup::onUpdate()
{
    VfxS32 popupWidth;
    VfxS32 textHeight;
    VfxS32 xPos = CONNECTED_AP_INFO_POPUP_LR_GAP;
    VfxS32 yPos = CONNECTED_AP_INFO_POPUP_TITLE_Y + CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT + CONNECTED_AP_INFO_POPUP_TD_GAP;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || 
        topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        popupWidth = CONNECTED_AP_INFO_POPUP_WIDTH;
    }
    else
    {
        popupWidth = CONNECTED_AP_INFO_POPUP_LANDSCAPE_WIDTH;
    }
    VfxS32 contentWidth = (popupWidth - 2 * CONNECTED_AP_INFO_POPUP_LR_GAP);

    // resize title
    m_titleBg->setSize(popupWidth, CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);
    m_titleFrame->setSize(contentWidth, CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);

    // resize info text frame
	m_textFrame->setSize(contentWidth, 0);
    textHeight = m_textFrame->getSize().height;
    
    m_textFrame->setAnchor(0,0);
    m_textFrame->setPos(xPos, yPos);
    yPos = yPos + textHeight + CONNECTED_AP_INFO_POPUP_BUTTON_TOP;

    // set button pos
    VfxS32 buttonWidth = CONNECTED_AP_INFO_POPUP_BUTTON_WIDTH;

    m_discButton->setInnerRect(VfxRect(
        CONNECTED_AP_INFO_POPUP_LR_GAP,
        yPos,
        buttonWidth,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT));
    m_cancelButton->setInnerRect(VfxRect(
        CONNECTED_AP_INFO_POPUP_LR_GAP + buttonWidth + CONNECTED_AP_INFO_POPUP_BUTTON_GAP,
        yPos,
        buttonWidth,
        CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT));

    yPos = yPos + CONNECTED_AP_INFO_POPUP_BUTTON_HEIGHT + CONNECTED_AP_INFO_POPUP_BOTTOM_GAP;

    // set background bounds
    m_background->setBounds(0, 0, popupWidth, yPos - CONNECTED_AP_INFO_POPUP_TITLE_HEIGHT);

    // set Popup bounds
    setBounds(0, 0, popupWidth, yPos);
}


void VappProfileInfoPopup::onPenInputOnOutside(VfxPenEvent &event)
{
    VfxBasePopup::onPenInputOnOutside(event);
}

void VappProfileInfoPopup::setTitle(const VfxWString &title)
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

void VappProfileInfoPopup::setText(const VfxWString &text)
{
    m_textFrame->setString(text);
    checkUpdate();
}


void VappProfileInfoPopup::setTextFont(const VfxFontDesc &font)
{
    m_textFrame->setFont(font);
    checkUpdate();
}

void VappProfileInfoPopup::setTextAlignMode(VfxTextFrame::AlignModeEnum value)
{
    m_textFrame->setAlignMode(value);
    checkUpdate();
}

void VappProfileInfoPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    m_signalButtonClicked.emit(this, (VcpInputPopupButtonEnum)id);
}

VfxBool VappProfileInfoPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_signalButtonClicked.emit(this, CONNECTED_AP_INFO_POPUP_BTN_CANCEL);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}

/***************************************************************************** 
 * Class VappWlanTimeLeftPopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWlanTimeLeftPopup", VappWlanTimeLeftPopup, VcpConfirmPopup);

VappWlanTimeLeftPopup::VappWlanTimeLeftPopup() {}

VfxBool VappWlanTimeLeftPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                break;
            case VFX_KEY_CODE_POWER:
                break;
            case VFX_KEY_CODE_HOME:
                m_signalHomeKeyClicked.postEmit (0);
                break;
            case VFX_KEY_CODE_VOL_UP:
                break;
            case VFX_KEY_CODE_VOL_DOWN:
                break;
            default:
                break;
        }
    }
    return VcpConfirmPopup::onKeyInput(event);
}


/***************************************************************************** 
 * Class VappWlanApListMenuCell
 *****************************************************************************/
VappWlanApListMenuCell::VappWlanApListMenuCell()
{
    
}

void VappWlanApListMenuCell::onCreateElements()
{
    VcpListMenuCellMultiTextFrame::onCreateElements ();
    
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
}

void VappWlanApListMenuCell::onCloseElements()
{
    if (m_imageFrame && getContentProvider())
    {
        VfxImageSrc img = m_imageFrame->getImgContent();
        
        getContentProvider()->closeItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, img);

        getContentProvider()->closeItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG, img);		
    }
    
    VcpListMenuCellMultiTextFrame::onCloseElements();
}

void VappWlanApListMenuCell::onLayoutElements()
{
    //W1203_UI_PERFORMANCE_BEGIN
    //VcpListMenuCellMultiTextFrame::onLayoutElements ();
    //W1203_UI_PERFORMANCE_END

    if (m_textFrame1)
    {
        m_textFrame1->setRect(VfxRect(TEXT1_LEFT_GAPS, 
                                      TEXT1_TOP_GAPS,
                                      getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS - IMG_LEFT_GAPS - IMG_RIGHT_GAPS - IMG_MAX_WIDTH,
                                      m_textFrame1->getRect().getHeight()));

        /* vertical center alignment text 1 if no text 2 */
        if (!m_textFrame2)
        {
            m_textFrame1->setPos(m_textFrame1->getPos().x, (getRect().getHeight() - m_textFrame1->getRect().getHeight()) / 2);
        }

        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    
    if (m_textFrame2)
    {
        m_textFrame2->setRect(VfxRect(TEXT2_LEFT_GAPS, 
                              getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_textFrame2->getRect().getHeight(),
                              getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS  - IMG_LEFT_GAPS - IMG_RIGHT_GAPS - IMG_MAX_WIDTH,
                              m_textFrame2->getRect().getHeight()));

        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    
    if (m_imageFrame)
    {
    /*
        m_imageFrame->setRect(getRect().getWidth() - 1 - IMG_RIGHT_GAPS - IMG_MAX_WIDTH, 
                              (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                              IMG_MAX_WIDTH, m_imageFrame->getBounds().getHeight());
     */                         
        m_imageFrame->setRect(getRect().getWidth() - 1 - IMG_RIGHT_GAPS - m_imageFrame->getRect().getWidth(), 
                              (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                              m_imageFrame->getRect().getWidth(), m_imageFrame->getRect().getHeight());

        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}

void VappWlanApListMenuCell::onUpdateElements()
{
    VcpListMenuCellMultiTextFrame::onUpdateElements();
    
    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    if (contentProvider)
    {
        VfxImageSrc img;
        
        if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, img))
        {
            m_imageFrame->setImgContent(img);
        }
		
		if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG, img))
        {
            m_imageFrame->setImgContent(img);
        }		
    }

}

/*****************************************************************************
 * Class VappWlanSettingSwitchButton Function
 *****************************************************************************/
// #ifdef	__CBM_BEARER_SWITCH__
VFX_IMPLEMENT_CLASS("VappWlanSettingSwitchButton", VappWlanSettingSwitchButton, VcpListMenuCellBaseControl);
void VappWlanSettingSwitchButton::onInit()
{
    VcpListMenuCellBaseControl::onInit();

    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);

    m_switch->setChecked(VFX_TRUE, VFX_TRUE);
    setSize(m_switch->getSize());
    m_switch->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_MID);
    m_switch->m_signalSwitchChanged.connect(this, &VappWlanSettingSwitchButton::OnSwitchSignal);
}

void VappWlanSettingSwitchButton::onDeinit()
{
    m_switch->m_signalSwitchChanged.disconnect(this, &VappWlanSettingSwitchButton::OnSwitchSignal);
    VFX_OBJ_CLOSE(m_switch);
    VcpListMenuCellBaseControl::onDeinit();
}

void VappWlanSettingSwitchButton::setSwitchStatus(VfxBool checked)
{
    m_switchStatus = checked;
    m_switch->setChecked(checked, VFX_TRUE);
}

void VappWlanSettingSwitchButton::OnSwitchSignal(VcpSwitch *sw, VfxBool isChecked)
{
    m_signalSwitchChanged.postEmit(this, isChecked);
}

void VappWlanSettingSwitchButton::setId(VfxId id)
{
    m_id = id;
}

VfxId VappWlanSettingSwitchButton::getId() const
{
    return m_id;
}
// #endif /* __CBM_BEARER_SWITCH__ */

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

