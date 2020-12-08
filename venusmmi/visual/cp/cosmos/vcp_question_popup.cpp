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
 *  vcp_question_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Question popup
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
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup_data_type.h"
#include "vcp_popup.h"
#include "vadp_mmi_frm.h"
#include "vcp_res.h"
extern "C"
{
#include "custom_events_notify.h"
#include "profilesSrvGprot.h"
}
#include "vcp_question_popup.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/



/*****************************************************************************
 * Class VcpQuestionPopup
 *****************************************************************************/
VcpQuestionPopup::VcpQuestionPopup() :
    m_backgroundTop(NULL),
    m_backgroundBottom(NULL),
    m_backgroundBottomImage(NULL),
    m_icon(NULL),
    m_textFrame(NULL),
    m_buttonCount(0),
    m_textHeight(0),
    m_panelHeight(0),
    m_upRegionHeight(0),
    m_bottomRegionHeight(0),
    m_cancelButtonIndex(-1),
    m_buttonPressed(VFX_FALSE)
{
    VfxS32 i;
    for (i = 0; i < VCP_QUESTION_POPUP_BUTTON_MAX_COUNT; i++)
    {
        m_button[i] = NULL;
    }
}


void VcpQuestionPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, VCP_QUESTION_POPUP_WIDTH_PORTRAIT, VCP_QUESTION_POPUP_UP_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this);
    m_backgroundTop->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_TOP));
    m_backgroundTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundTop->setIsCached(VFX_TRUE);
    m_backgroundTop->setBounds(0, 0, VCP_QUESTION_POPUP_WIDTH_PORTRAIT, VCP_QUESTION_POPUP_UP_HEIGHT);
    m_backgroundTop->setAutoAnimate(VFX_TRUE);
    m_backgroundTop->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_buttonPanel, VcpScrollable, m_backgroundBottom);
    m_buttonPanel->setAutoAnimate(VFX_TRUE);
    m_buttonPanel->setBounds(VfxRect(0, 0, VCP_QUESTION_POPUP_WIDTH_PORTRAIT, VCP_QUESTION_POPUP_BOTTOM_HEIGHT));
    m_buttonPanel->setViewRect(VfxRect(0, 0, VCP_QUESTION_POPUP_WIDTH_PORTRAIT, VCP_QUESTION_POPUP_BOTTOM_HEIGHT)); 

    VFX_OBJ_CREATE(m_icon, VfxFrame, m_backgroundTop);
    m_icon->setAnchor(0.5, 0.5);
    m_icon->setBounds(0,0,VCP_QUESTION_POPUP_ICON_WIDTH,VCP_QUESTION_POPUP_ICON_HEIGHT);
    m_icon->setHidden(VFX_TRUE);
    m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_QUESTION_CONFIRM));
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_backgroundTop);
    m_textFrame->setRect(VCP_QUESTION_POPUP_TEXT_X, VCP_QUESTION_POPUP_TEXT_Y, VCP_QUESTION_POPUP_TEXT_WIDTH, 20);
    m_textFrame->setAnchor(0,0);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_QUESTION_POPUP_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textFrame->setMaxLines(4);

    m_buttonWidth = VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT;

    checkUpdate();
}



void VcpQuestionPopup::onEnter()
{
    VfxBasePopup::onEnter();
    onUpdate();
    m_buttonPressed = VFX_FALSE;
}


void VcpQuestionPopup::onExit()
{
    if (!m_buttonPressed)
    {
         m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    } 
    VfxBasePopup::onExit();
}


void VcpQuestionPopup::onRotate(const VfxScreenRotateParam &param)
{
    checkUpdate();
    processUpdate();
    VfxBasePopup::onRotate(param);
}


void VcpQuestionPopup::onUpdate()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 maxPanelHeight;
    VfxS32 finalPanelHeight;
    VfxS32 popupWidth;
    VfxS32 textWidth;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        maxPanelHeight = VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_PORTRAIT;
        popupWidth = VCP_QUESTION_POPUP_WIDTH_PORTRAIT;
        m_buttonWidth = VCP_QUESTION_POPUP_BUTTON_WIDTH_PORTRAIT;
        textWidth = VCP_QUESTION_POPUP_TEXT_WIDTH;
        m_textFrame->setMaxLines(4);
    }
    else
    {
        maxPanelHeight = VCP_QUESTION_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE;
        popupWidth = VCP_QUESTION_POPUP_WIDTH_LANDSCAPE;
        m_buttonWidth = VCP_QUESTION_POPUP_BUTTON_WIDTH_LANDSCAPE;
        textWidth = VCP_QUESTION_POPUP_TEXT_WIDTH_LS;
        m_textFrame->setMaxLines(2);
    }
    
    if (m_panelHeight > maxPanelHeight)
    {
        m_buttonPanel->setContentSize(VfxSize(popupWidth, m_panelHeight));
        m_buttonPanel->setValidContentRect(VfxRect(0, 0, popupWidth, m_panelHeight));
        m_buttonPanel->setWarningContentRect(VfxRect(0, 0, popupWidth, m_panelHeight));
        finalPanelHeight = maxPanelHeight;    
    }
    else
    {
        m_buttonPanel->setContentSize(VfxSize(popupWidth, m_panelHeight));
        m_buttonPanel->setValidContentRect(VfxRect(0, 0, popupWidth, m_panelHeight));
        m_buttonPanel->setWarningContentRect(VfxRect(0, 0, popupWidth, m_panelHeight));
        finalPanelHeight = m_panelHeight;
    }
    
    m_buttonPanel->setBounds(0, 0, popupWidth, finalPanelHeight);
    m_buttonPanel->setPos(0, VCP_QUESTION_POPUP_BUTTON_Y_SHIFT);

    VfxS32 viewOrigin = m_buttonPanel->getViewBounds().origin.y;
    if(viewOrigin > 0)
    {
        m_buttonPanel->setContentOffset(VfxPoint(0, 0), VFX_TRUE);
    }

    m_bottomRegionHeight = VCP_QUESTION_POPUP_BUTTON_Y_SHIFT + finalPanelHeight + VCP_QUESTION_POPUP_BOTTOM_HEIGHT;

    // Updating text width and height
    m_icon->setHidden(VFX_FALSE);
    m_textFrame->forceUpdate();
    m_textHeight = m_textFrame->getSize().height;
    if (m_textHeight < VCP_QUESTION_POPUP_ICON_HEIGHT)
    {
        // text area is smaller then image
        m_textHeight = VCP_QUESTION_POPUP_ICON_HEIGHT;
        m_textFrame->setAnchor(0,0.5);
        m_textFrame->setPos(VCP_QUESTION_POPUP_TEXT_X, VCP_QUESTION_POPUP_ICON_Y);
        m_textFrame->setSize(textWidth, m_textHeight);
        m_icon->setPos(VCP_QUESTION_POPUP_ICON_X, VCP_QUESTION_POPUP_ICON_Y);
    }
    else
    {
        m_textFrame->setAnchor(0,0);
        m_textFrame->setPos(VCP_QUESTION_POPUP_TEXT_X, VCP_QUESTION_POPUP_TEXT_Y);
        m_textFrame->setSize(textWidth, m_textHeight);    
        m_icon->setPos(VCP_QUESTION_POPUP_ICON_X, VCP_QUESTION_POPUP_TEXT_Y + m_textHeight/2);
    } 

    m_upRegionHeight = VCP_QUESTION_POPUP_UP_HEIGHT + m_textHeight;
    m_backgroundTop->setBounds(0,0,popupWidth,m_upRegionHeight);

    m_backgroundBottom->setPos(0,m_upRegionHeight);
    m_backgroundBottom->setBounds(0,0,popupWidth,m_bottomRegionHeight);

    m_backgroundBottomImage->setBounds(0, 0, popupWidth, m_upRegionHeight + m_bottomRegionHeight);

    {
        for (VfxS32 i = 0; i < m_buttonCount; i++)
        {
            m_button[i]->setInnerRect(VfxRect(m_button[i]->getPos().x, m_button[i]->getPos().y, m_buttonWidth, VCP_QUESTION_POPUP_BUTTON_HEIGHT));
        }
    }

    setBounds(0,0,popupWidth, m_upRegionHeight + m_bottomRegionHeight);
}


VfxBool VcpQuestionPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                if (m_cancelButtonIndex != -1)
                {
                    m_signalButtonClicked.postEmit(this, m_button[m_cancelButtonIndex]->getId());
                    m_buttonPressed = VFX_TRUE;
                }
                leave(VFX_TRUE);
                return VFX_TRUE;
                //break;
            case VFX_KEY_CODE_POWER:
            case VFX_KEY_CODE_HOME:
            case VFX_KEY_CODE_VOL_UP:
            case VFX_KEY_CODE_VOL_DOWN:
                break;
            default:
                break;
        }
    }
    return VfxBasePopup::onKeyInput(event);
}

/* vaib mem reduction*/
void VcpQuestionPopup::addItem(VfxId id, VfxResId text_id, VcpPopupButtonTypeEnum type)
{
	addItem(id, VFX_WSTR_RES(text_id), type);
}

/* vaib mem reduction*/
void VcpQuestionPopup::addItem(VfxId id, const VfxWChar* text_buf, VcpPopupButtonTypeEnum type)
{
	addItem(id, VFX_WSTR_MEM(text_buf), type);
}

void VcpQuestionPopup::addItem(VfxId id, const VfxWString &text, VcpPopupButtonTypeEnum type)
{
    if (m_buttonCount >= VCP_QUESTION_POPUP_BUTTON_MAX_COUNT)
    {
        return;
    }

    VFX_OBJ_CREATE(m_button[m_buttonCount], VcpButton, m_buttonPanel);
    m_button[m_buttonCount]->setText(text);
    m_button[m_buttonCount]->setInnerRect(VfxRect(
                                        VCP_QUESTION_POPUP_BUTTON_X, 
                                        VCP_QUESTION_POPUP_BUTTON_Y + m_buttonCount * (VCP_QUESTION_POPUP_BUTTON_HEIGHT + VCP_QUESTION_POPUP_BUTTON_GAP),
                                        m_buttonWidth, 
                                        VCP_QUESTION_POPUP_BUTTON_HEIGHT
                                     ));
    m_button[m_buttonCount]->m_signalClicked.connect(this, &VcpQuestionPopup::onButtonClick);
    m_button[m_buttonCount]->setId(id);
    m_button[m_buttonCount]->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_button[m_buttonCount]->setAutoAnimate(VFX_TRUE);
    
    switch (type)
    {
        case VCP_POPUP_BUTTON_TYPE_NORMAL:
            break;
        case VCP_POPUP_BUTTON_TYPE_WARNING:
            m_button[m_buttonCount]->setStyle(VCP_BUTTON_STYLE_RED);
            break;
        case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
            
            break;
        case VCP_POPUP_BUTTON_TYPE_CANCEL:
            m_button[m_buttonCount]->setStyle(VCP_BUTTON_STYLE_GREY);
            m_cancelButtonIndex = m_buttonCount;
            break;
        default:
            VFX_ASSERT(0);
    }
    m_buttonCount ++;

    m_panelHeight = m_buttonCount * (VCP_QUESTION_POPUP_BUTTON_HEIGHT + VCP_QUESTION_POPUP_BUTTON_GAP) - VCP_QUESTION_POPUP_BUTTON_GAP;
    
    checkUpdate();
}


void VcpQuestionPopup::disableItem(VfxId id)
{
    for (VfxS32 i = 0; i < m_buttonCount; i++)
    {
        if (m_button[i]->getId() == id)
        {
            m_button[i]->setIsDisabled(VFX_TRUE);
        }
    }
}


void VcpQuestionPopup::enableItem(VfxId id)
{
    for (VfxS32 i = 0; i < m_buttonCount; i++)
    {
        if (m_button[i]->getId() == id)
        {
            m_button[i]->setIsDisabled(VFX_FALSE);
        }
    }
}

/* vaib mem reduction*/
void VcpQuestionPopup::setText(VfxResId text_id)
{
	m_textFrame->setString(VFX_WSTR_RES(text_id));
	checkUpdate();
}

/* vaib mem reduction*/
void VcpQuestionPopup::setText(const VfxWChar* text_buf)
{
	m_textFrame->setString(VFX_WSTR_MEM(text_buf));
	checkUpdate();
}

void VcpQuestionPopup::setText(const VfxWString &text)
{
    m_textFrame->setString(text);
    checkUpdate();
}


void VcpQuestionPopup::resetButton()
{
    for (VfxS32 i = 0; i < VCP_QUESTION_POPUP_BUTTON_MAX_COUNT; i++)
    {
        if (m_button[i])
        {
            VFX_OBJ_CLOSE(m_button[i]);
            m_button[i] = NULL;
        }
    }
}


void VcpQuestionPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (m_buttonPressed)
    {
        return;
    }
    m_buttonPressed = VFX_TRUE;
    VfxS32 i;
    for (i = 0; i < VCP_QUESTION_POPUP_BUTTON_MAX_COUNT; i++)
    {
        if (m_button[i] == sender)
        {
            m_signalButtonClicked.postEmit(this, id);
            break;
        }
    }

    leave(VFX_TRUE);
}

#endif
