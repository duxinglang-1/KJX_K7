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
 *  vcp_command_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Command popup
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
 * removed!
 *
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
 * removed!
 * removed!
 *
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

#include"mmi_rp_srv_venus_component_popup_def.h"
#include "vcp_command_popup.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/



/*****************************************************************************
 * Class VcpCommandPopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpCommandPopup", VcpCommandPopup, VfxBasePopup);

VcpCommandPopup::VcpCommandPopup() :
    m_backgroundTop(NULL),
    m_backgroundBottom(NULL),
    m_icon(NULL),
    m_textFrame(NULL),
    m_infoType(VCP_POPUP_TYPE_END_OF_ENUM),
    m_buttonCount(0),
    m_buttonWidth(0),
    m_hasTitle(VFX_FALSE),
    m_hasIcon(VFX_FALSE),
    m_textHeight(0),
    m_upRegionHeight(0),
    m_bottomRegionHeight(0),
    m_cancelButtonIndex(-1),
#if defined(__MMI_VUI_COSMOS_CP__)
    m_isPlayTone(VFX_TRUE),
    m_needToRotate(VFX_FALSE),
#endif
    m_buttonPressed(VFX_FALSE)
{
    VfxS32 i;
    for (i = 0; i < VCP_COMMAND_POPUP_BUTTON_MAX_COUNT; i++)
    {
        m_button[i] = NULL;
    }
}


void VcpCommandPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    setIsCached(VFX_FALSE);

#if defined(__MMI_VUI_COSMOS_CP__) 
    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_COMMAND_BACKGROUND));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);
#endif

    VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this);
#if !defined(__MMI_VUI_COSMOS_CP__)  
    m_backgroundTop->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_TOP));
    m_backgroundTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundTop->setIsCached(VFX_TRUE);
#endif


    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
#if !defined(__MMI_VUI_COSMOS_CP__)  
    m_backgroundBottom->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_BOTTOM));
    m_backgroundBottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    //m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setAutoAnimate(VFX_TRUE);
#endif


    VFX_OBJ_CREATE(m_buttonPanel, VcpScrollable, m_backgroundBottom);
#if !defined(__MMI_VUI_COSMOS_CP__) 
    m_buttonPanel->setAutoAnimate(VFX_TRUE);
#endif
    m_buttonPanel->enableBoundaryLight(VFX_FALSE);
    m_buttonPanel->setCacheMode(VFX_CACHE_MODE_PREVENT);

    VFX_OBJ_CREATE(m_icon, VfxFrame, m_backgroundTop);
    m_icon->setAnchor(0.5, 0.5);
    m_icon->setBounds(0,0,VCP_COMMAND_POPUP_ICON_WIDTH,VCP_COMMAND_POPUP_ICON_HEIGHT);
    m_icon->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_backgroundTop);
    m_textFrame->setRect(VCP_COMMAND_POPUP_TEXT_X, VCP_COMMAND_POPUP_TEXT_Y, VCP_COMMAND_POPUP_TEXT_WIDTH, 20);
    m_textFrame->setAnchor(0,0);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
#if defined(__MMI_VUI_COSMOS_CP__) 
    m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_COMMAND_POPUP_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#else
    m_textFrame->setColor(VfxColor(255,34,34,34));
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#endif
    m_buttonWidth = VCP_COMMAND_POPUP_BUTTON_WIDTH;

    checkUpdate();
}


void VcpCommandPopup::onEnter()
{
#if defined(__MMI_VUI_COSMOS_CP__) 
    onUpdate();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setAnchor(0, 0);
    setPos(0, getTargetScreen()->getBounds().getHeight() - getBounds().getHeight());
    VfxAutoAnimate::commit();
#else
    VfxBasePopup::onEnter();
#endif
    m_buttonPressed = VFX_FALSE;
}


void VcpCommandPopup::onExit()
{
    VfxBasePopup::onExit();
}


void VcpCommandPopup::onLeaveStack()
{
    if (!m_buttonPressed)
    {
         m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    }
    VfxBasePopup::onLeaveStack();
}


void VcpCommandPopup::onRotate(const VfxScreenRotateParam &param)
{
    #if defined(__MMI_VUI_COSMOS_CP__)
        VfxAutoAnimate::begin();
		VfxAutoAnimate::setDisable(VFX_TRUE);
    	setAnchor(0, 0);
		setPos(0, getTargetScreen()->getBounds().getHeight());
		VfxAutoAnimate::commit();

        m_needToRotate = VFX_TRUE;
        checkUpdate();
    #else
        processUpdate();
        VfxBasePopup::onRotate(param);
    #endif
}


void VcpCommandPopup::onUpdate()
{
#if defined(__MMI_VUI_COSMOS_CP__) 
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 maxPanelHeight;
    VfxS32 finalPanelHeight;
    VfxS32 popupWidth, textWidth;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        maxPanelHeight = VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT;
        popupWidth = VCP_COMMAND_POPUP_WIDTH;
        m_buttonWidth =  VCP_COMMAND_POPUP_BUTTON_WIDTH;
        textWidth = VCP_COMMAND_POPUP_TEXT_WIDTH_ICON;
        m_textFrame->setMaxLines(4);
    }
    else
    {
        maxPanelHeight = VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE;
        popupWidth = VCP_COMMAND_POPUP_WIDTH_LANDSCAPE;
        m_buttonWidth =  VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE;
        textWidth = VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE;
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
    m_buttonPanel->setPos(0, VCP_COMMAND_POPUP_BUTTON_Y_SHIFT);

    VfxS32 viewOrigin = m_buttonPanel->getViewBounds().origin.y;
    if(viewOrigin > 0)
    {
        m_buttonPanel->setContentOffset(VfxPoint(0, 0), VFX_TRUE);
    }

    m_bottomRegionHeight = VCP_COMMAND_POPUP_BUTTON_Y_SHIFT + finalPanelHeight;
#else
    if (m_hasTitle || m_hasIcon)
    {
        m_bottomRegionHeight = m_panelHeight + VCP_COMMAND_POPUP_BOTTOM_HEIGHT - VCP_COMMAND_POPUP_BUTTON_GAP;
    }
    else
    {
        m_bottomRegionHeight = m_panelHeight + VCP_COMMAND_POPUP_BOTTOM_HEIGHT - VCP_COMMAND_POPUP_BUTTON_GAP + VCP_COMMAND_POPUP_BUTTON_Y_SHIFT;
    }
#endif
    if (m_hasTitle || m_hasIcon)
    {
        if (m_hasIcon)
        {
            m_icon->setHidden(VFX_FALSE);
            m_textFrame->forceUpdate();
            m_textHeight = m_textFrame->getSize().height;
            if (m_textHeight < VCP_COMMAND_POPUP_ICON_HEIGHT)
            {
                // text area is smaller then image
                m_textHeight = VCP_COMMAND_POPUP_ICON_HEIGHT;
                m_textFrame->setAnchor(0,0.5);
                m_textFrame->setPos(VCP_COMMAND_POPUP_TEXT_X_ICON, VCP_COMMAND_POPUP_ICON_Y);
#if defined(__MMI_VUI_COSMOS_CP__) 
                m_textFrame->setSize(textWidth, VCP_COMMAND_POPUP_TEXT_HEIGHT);
#else
                m_textFrame->setSize(VCP_COMMAND_POPUP_TEXT_WIDTH_ICON, 20);
#endif
                m_icon->setPos(VCP_COMMAND_POPUP_ICON_X, VCP_COMMAND_POPUP_ICON_Y);
            }
            else
            {
                m_textFrame->setAnchor(0,0);
                m_textFrame->setPos(VCP_COMMAND_POPUP_TEXT_X_ICON, VCP_COMMAND_POPUP_TEXT_Y);
#if defined(__MMI_VUI_COSMOS_CP__) 
                m_textFrame->setSize(textWidth, VCP_COMMAND_POPUP_TEXT_HEIGHT);    
#else
                m_textFrame->setSize(VCP_COMMAND_POPUP_TEXT_WIDTH_ICON, 20);    
#endif
                m_icon->setPos(VCP_COMMAND_POPUP_ICON_X, VCP_COMMAND_POPUP_TEXT_Y + m_textHeight/2);
            } 

        }
        else
        {
#if defined(__MMI_VUI_COSMOS_CP__) 
            m_textFrame->setRect(VCP_COMMAND_POPUP_TEXT_X, VCP_COMMAND_POPUP_TEXT_Y, textWidth, VCP_COMMAND_POPUP_TEXT_HEIGHT);
#else
            m_textFrame->setRect(VCP_COMMAND_POPUP_TEXT_X, VCP_COMMAND_POPUP_TEXT_Y, VCP_COMMAND_POPUP_TEXT_WIDTH, 20);
#endif
            m_textFrame->forceUpdate();
            m_textHeight = m_textFrame->getSize().height;
        }
        
        m_backgroundTop->setHidden(VFX_FALSE);
        m_upRegionHeight = VCP_COMMAND_POPUP_UP_HEIGHT + m_textHeight;
#if defined(__MMI_VUI_COSMOS_CP__) 
        m_backgroundTop->setBounds(0,0,popupWidth,m_upRegionHeight);
#else
        m_backgroundTop->setBounds(0,0,VCP_COMMAND_POPUP_WIDTH,m_upRegionHeight);
#endif

        m_backgroundBottom->setPos(0,m_upRegionHeight);
#if defined(__MMI_VUI_COSMOS_CP__) 
        m_backgroundBottom->setBounds(0,0,popupWidth,m_bottomRegionHeight);
#else
        m_backgroundBottom->setBounds(0,0,VCP_COMMAND_POPUP_WIDTH,m_bottomRegionHeight);
#endif
    #if !defined(__MMI_VUI_COSMOS_CP__) 
        m_backgroundBottom->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_BOTTOM));
    #endif
#if defined(__MMI_VUI_COSMOS_CP__) 
        for (VfxS32 i = 0; i < m_buttonCount; i++)
        {
            m_button[i]->setBounds(0, 0, m_buttonWidth, VCP_COMMAND_POPUP_BUTTON_HEIGHT);
        }
#endif
    }
    else
    {
        m_backgroundTop->setHidden(VFX_TRUE);
        m_upRegionHeight = 0;
        m_backgroundBottom->setPos(0,m_upRegionHeight);
#if defined(__MMI_VUI_COSMOS_CP__) 
        m_backgroundBottom->setBounds(0,0,popupWidth,m_bottomRegionHeight);
#else
        m_backgroundBottom->setBounds(0,0,VCP_COMMAND_POPUP_WIDTH,m_bottomRegionHeight);
#endif
    #if !defined(__MMI_VUI_COSMOS_CP__) 
        m_backgroundBottom->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    #endif
#if defined(__MMI_VUI_COSMOS_CP__) 
        for (VfxS32 i = 0; i < m_buttonCount; i++)
        {
            m_button[i]->setBounds(0, 0, m_buttonWidth, VCP_COMMAND_POPUP_BUTTON_HEIGHT);
        }
#endif
    }

#if defined(__MMI_VUI_COSMOS_CP__) 
    VfxAutoAnimate::begin();
	VfxAutoAnimate::setDisable(VFX_TRUE);
    setBounds(0,0,popupWidth, m_upRegionHeight + m_bottomRegionHeight);
    m_backgroundBottomImage->setSize(popupWidth, m_upRegionHeight + m_bottomRegionHeight);
	VfxAutoAnimate::commit();
#else
    setBounds(0,0,VCP_COMMAND_POPUP_WIDTH, m_upRegionHeight + m_bottomRegionHeight);
#endif

#if defined(__MMI_VUI_COSMOS_CP__)  
    VcpEffectMorphFadeInData data;
    data.fromRect.origin.x = 0;
    data.fromRect.origin.y = getTargetScreen()->getBounds().getHeight();
    data.fromRect.size.width = getBounds().getWidth();
    data.fromRect.size.height = getBounds().getHeight();
    setFrameEffect(VCP_EFFECT_MORPH_FADE_IN, 300, VCP_EFFECT_DIRECTION_FROM_BOTTOM, &data, sizeof(data));
#endif

#if defined(__MMI_VUI_COSMOS_CP__)      
    if(m_needToRotate)
    {
        setAnchor(0, 0);
        setPos(0, getTargetScreen()->getBounds().getHeight() - getBounds().getHeight());
        m_needToRotate  = VFX_FALSE;
    }
#endif
}


VfxBool VcpCommandPopup::onKeyInput(VfxKeyEvent &event)
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


void VcpCommandPopup::setInfoType(VcpPopupTypeEnum type)
{
    m_infoType = type;
    m_hasTitle = VFX_TRUE;
    #if defined(__MMI_VUI_COSMOS_CP__)
        m_hasIcon = VFX_FALSE;
    #else
        m_hasIcon = VFX_TRUE;
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    #endif

    switch (type)
    {
        case VCP_POPUP_TYPE_FAILURE:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_FAILURE_CONFIRM));
            break;
        case VCP_POPUP_TYPE_INFO:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_INFO_CONFIRM));
            break;
        case VCP_POPUP_TYPE_WARNING:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_WARNING_CONFIRM));
            break;
        case VCP_POPUP_TYPE_SUCCESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_SUCCESS_CONFIRMT));
            break;
        case VCP_POPUP_TYPE_PROGRESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_PROGRESS_CONFIRM));
            break;
        case VCP_POPUP_TYPE_QUESTION:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_QUESTION_CONFIRM));
            break;
        default:
            VFX_ASSERT(0);
    }
    checkUpdate();
}

/* vaib mem reduction*/
void VcpCommandPopup::addItem(VfxId id, VfxResId text_id, VcpPopupButtonTypeEnum type)
{
	addItem(id,VFX_WSTR_RES(text_id),type);
}

/* vaib mem reduction*/
void VcpCommandPopup::addItem(VfxId id, const VfxWChar* text_buf, VcpPopupButtonTypeEnum type)
{
	addItem(id,VFX_WSTR_MEM(text_buf),type);
}

void VcpCommandPopup::addItem(VfxId id, const VfxWString &text, VcpPopupButtonTypeEnum type)
{
    if (m_buttonCount >= VCP_COMMAND_POPUP_BUTTON_MAX_COUNT)
    {
        return;
    }

    VfxS32 shift = VCP_COMMAND_POPUP_BUTTON_Y_SHIFT;

#if defined(__MMI_VUI_COSMOS_CP__)
    shift = 0;
    VFX_OBJ_CREATE(m_button[m_buttonCount], VcpButton, m_buttonPanel);
    m_button[m_buttonCount]->setCacheMode(VFX_CACHE_MODE_FREEZE);
    m_button[m_buttonCount]->setText(text);
    m_button[m_buttonCount]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_button[m_buttonCount]->setInnerRect(VfxRect(
                                        VCP_COMMAND_POPUP_BUTTON_X, 
                                        VCP_COMMAND_POPUP_BUTTON_Y + m_buttonCount * (VCP_COMMAND_POPUP_BUTTON_HEIGHT + VCP_COMMAND_POPUP_BUTTON_GAP) + shift,
                                        m_buttonWidth, 
                                        VCP_COMMAND_POPUP_BUTTON_HEIGHT
                                     ));
    m_button[m_buttonCount]->m_signalClicked.connect(this, &VcpCommandPopup::onButtonClick);
    m_button[m_buttonCount]->setId(id);
    m_button[m_buttonCount]->setAutoAnimate(VFX_FALSE);
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
    
#else
    if (m_hasTitle || m_hasIcon)
    {
        shift = 0;
    }
    VFX_OBJ_CREATE(m_button[m_buttonCount], VcpButton, m_backgroundBottom);
    m_button[m_buttonCount]->setCacheMode(VFX_CACHE_MODE_FREEZE);
    m_button[m_buttonCount]->setText(text);
    m_button[m_buttonCount]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_button[m_buttonCount]->setInnerRect(VfxRect(
                                        VCP_COMMAND_POPUP_BUTTON_X, 
                                        VCP_COMMAND_POPUP_BUTTON_Y + m_buttonCount * (VCP_COMMAND_POPUP_BUTTON_HEIGHT + VCP_COMMAND_POPUP_BUTTON_GAP) + shift,
                                        m_buttonWidth, 
                                        VCP_COMMAND_POPUP_BUTTON_HEIGHT
                                     ));
    m_button[m_buttonCount]->m_signalClicked.connect(this, &VcpCommandPopup::onButtonClick);
    m_button[m_buttonCount]->setId(id);
    m_button[m_buttonCount]->setMargin(6, 5, 7, 7);

    switch (type)
    {
        case VCP_POPUP_BUTTON_TYPE_NORMAL:
                m_button[m_buttonCount]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                             ));
                m_button[m_buttonCount]->setTextColor(VfxColor(255,0,0,0));
            break;

        case VCP_POPUP_BUTTON_TYPE_WARNING:
                m_button[m_buttonCount]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL
                                             ));
                m_button[m_buttonCount]->setTextColor(VfxColor(255,255,255,255));
            break;

        case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
                m_button[m_buttonCount]->setBgImageList(VcpStateImage(
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                    VCP_IMG_POPUP_BUTTON_PRESSED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                                 ));
                m_button[m_buttonCount]->setTextColor(VfxColor(255,0,0,0));
            break;

        case VCP_POPUP_BUTTON_TYPE_CANCEL:
            m_cancelButtonIndex = m_buttonCount;
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                             ));
            m_button[m_buttonCount]->setTextColor(VfxColor(255,255,255,255));
            break;
        default:
            VFX_ASSERT(0);
    }
#endif
    m_buttonCount ++;

    m_panelHeight = m_buttonCount * (VCP_COMMAND_POPUP_BUTTON_HEIGHT + VCP_COMMAND_POPUP_BUTTON_GAP);
    
    checkUpdate();
}


void VcpCommandPopup::disableItem(VfxId id)
{
    VfxS32 i;
    for (i = 0; i < m_buttonCount; i++)
    {
        if (m_button[i]->getId() == id)
        {
            m_button[i]->setIsDisabled(VFX_TRUE);
        }
    }
}


void VcpCommandPopup::enableItem(VfxId id)
{
    VfxS32 i;
    for (i = 0; i < m_buttonCount; i++)
    {
        if (m_button[i]->getId() == id)
        {
            m_button[i]->setIsDisabled(VFX_FALSE);
        }
    }
}


void VcpCommandPopup::setImage(const VfxImageSrc &imgScr)
{
    if (imgScr.isNull())
    {
        m_hasIcon = VFX_FALSE;
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }
    else
    {
        m_icon->setImgContent(imgScr);
        m_hasIcon = VFX_TRUE;
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    }
    checkUpdate();
}


void VcpCommandPopup::setTextAlignMode(VfxTextFrame::AlignModeEnum value)
{
    m_textFrame->setAlignMode(value);
    checkUpdate();
}

/* vaib mem reduction*/
void VcpCommandPopup::setText(VfxResId text_id)
{
	setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpCommandPopup::setText(const VfxWChar* text_buf)
{
	setText(VFX_WSTR_MEM(text_buf));
}

void VcpCommandPopup::setText(const VfxWString &text)
{
    if (text.isNull())
    {
        m_hasTitle = VFX_FALSE;
    }
    else
    {
        m_textFrame->setString(text);
        m_hasTitle = VFX_TRUE;
    }
    checkUpdate();
}


void VcpCommandPopup::setTextFont(const VfxFontDesc &font)
{
    m_textFrame->setFont(font);
    checkUpdate();
}


void VcpCommandPopup::resetButton()
{
    for (VfxS32 i = 0; i < VCP_COMMAND_POPUP_BUTTON_MAX_COUNT; i++)
    {
        if (m_button[i])
        {
            VFX_OBJ_CLOSE(m_button[i]);
            m_button[i] = NULL;
        }
    }
}


void VcpCommandPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (m_buttonPressed)
    {
        return;
    }
    m_buttonPressed = VFX_TRUE;
    for (VfxS32 i = 0; i < VCP_COMMAND_POPUP_BUTTON_MAX_COUNT; i++)
    {
        if (m_button[i] == sender)
        {
            m_signalButtonClicked.postEmit(this, id);
            break;
        }
    }

    leave(VFX_TRUE);
}


#if defined(__MMI_VUI_COSMOS_CP__)
void VcpCommandPopup::setIsPlayTone(VfxBool option)
{
    m_isPlayTone = option;
}
#endif


void VcpCommandPopup::onPlayTone()
{
    #if defined(__MMI_VUI_COSMOS_CP__)
        if(!m_isPlayTone)
        {
            return;
        }
        switch (m_infoType)
        {
            case VCP_POPUP_TYPE_FAILURE:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);
                break;
            case VCP_POPUP_TYPE_INFO:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_WARNING:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING), NULL);
                break;
            case VCP_POPUP_TYPE_SUCCESS:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_PROGRESS:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_QUESTION:
                // Question must no sound according rule
                //srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
                break;
        }
    #else
        switch (m_infoType)
        {
            case VCP_POPUP_TYPE_FAILURE:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);
                break;
            case VCP_POPUP_TYPE_INFO:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
                break;
            case VCP_POPUP_TYPE_WARNING:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING), NULL);
                break;
            case VCP_POPUP_TYPE_SUCCESS:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_SUCCESS), NULL);
                break;
            case VCP_POPUP_TYPE_PROGRESS:
                srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_PROGRESS), NULL);
                break;
            case VCP_POPUP_TYPE_QUESTION:
                // Question must no sound according rule
                //srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
                break;
        }
    #endif
}


void VcpCommandPopup::onStopTone()
{
    #if defined(__MMI_VUI_COSMOS_CP__)
        switch (m_infoType)
        {
            case VCP_POPUP_TYPE_FAILURE:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));
                break;
            case VCP_POPUP_TYPE_INFO:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_WARNING:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING));
                break;
            case VCP_POPUP_TYPE_SUCCESS:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_PROGRESS:
                // No ringtone for COSMOS
                break;
            case VCP_POPUP_TYPE_QUESTION:
                // Question must no sound according rule
                //srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_INFO));
                break;
        }
    #else
        switch (m_infoType)
        {
            case VCP_POPUP_TYPE_FAILURE:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));
                break;
            case VCP_POPUP_TYPE_INFO:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_INFO));
                break;
            case VCP_POPUP_TYPE_WARNING:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING));
                break;
            case VCP_POPUP_TYPE_SUCCESS:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_SUCCESS));
                break;
            case VCP_POPUP_TYPE_PROGRESS:
                srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_PROGRESS));
                break;
            case VCP_POPUP_TYPE_QUESTION:
                // Question must no sound according rule
                //srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_INFO));
                break;
        }
    #endif
}

