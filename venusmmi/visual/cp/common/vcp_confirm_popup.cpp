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
 *  vcp_confirm_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
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
#include "GlobalResDef.h"
}

#include "vcp_confirm_popup.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

// SWLA logs
#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__ && __VENUS_SWLA_DBG_ON__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/


/*****************************************************************************
 * Class VcpConfirmPopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpConfirmPopup", VcpConfirmPopup, VfxBasePopup);

VcpConfirmPopup::VcpConfirmPopup() :
    m_backgroundTop(NULL),
    m_backgroundBottom(NULL),
#if defined(__MMI_VUI_COSMOS_CP__) 
    m_backgroundBottomImage(NULL),
#endif
    m_icon(NULL),
    m_textFrame(NULL),
    m_infoType(VCP_POPUP_TYPE_END_OF_ENUM),
    m_buttonSet(VCP_CONFIRM_BUTTON_SET_NONE),
    m_textHeight(0),
    m_upRegionHeight(0),
    m_bottomRegionHeight(0),
    m_cancelButtonIndex(-1),
#if defined(__MMI_VUI_COSMOS_CP__)
    m_isPlayTone(VFX_TRUE),
#endif
    m_buttonPressed(VFX_FALSE)
{
    VfxS32 i;
    for (i = 0; i < 2; i++)
    {
        m_button[i] = NULL;
    }
}


void VcpConfirmPopup::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP0", SA_start);
#endif
    VfxBasePopup::onInit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP0", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP1", SA_start);
#endif
    setAutoAnimate(VFX_TRUE);

#if defined(__MMI_VUI_COSMOS_CP__)
    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    //m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);
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
    m_backgroundBottom->setIsCached(VFX_TRUE);
    //m_backgroundBottom->setAutoAnimate(VFX_TRUE);
#endif

    VFX_OBJ_CREATE(m_icon, VfxFrame, m_backgroundTop);
    m_icon->setAnchor(0.5, 0.5);
    m_icon->setBounds(0,0,VCP_CONFIRM_POPUP_ICON_WIDTH,VCP_CONFIRM_POPUP_ICON_HEIGHT);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_backgroundTop);
    m_textFrame->setRect(VCP_CONFIRM_POPUP_TEXT_X, VCP_CONFIRM_POPUP_TEXT_Y, VCP_CONFIRM_POPUP_TEXT_WIDTH, 20);
    m_textFrame->setAnchor(0,0);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
#if defined(__MMI_VUI_COSMOS_CP__)
    m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_COMMAND_POPUP_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
#else
    m_textFrame->setColor(VfxColor(255,34,34,34));
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#endif  
    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP1", SA_stop);
#endif
}


void VcpConfirmPopup::onEnter()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP2", SA_start);
#endif
    VfxBasePopup::onEnter();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP2", SA_stop);
#endif
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP3", SA_start);
#endif
    m_buttonPressed = VFX_FALSE;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP3", SA_stop);
#endif
}


void VcpConfirmPopup::onExit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP4", SA_start);
#endif
    VfxBasePopup::onExit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP4", SA_stop);
#endif
}


void VcpConfirmPopup::onLeaveStack()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP5", SA_start);
#endif
    if (!m_buttonPressed)
    {
         m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP5", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP6", SA_start);
#endif
    VfxBasePopup::onLeaveStack();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP6", SA_stop);
#endif
}


void VcpConfirmPopup::onRotate(const VfxScreenRotateParam &param)
{
#if defined(__MMI_VUI_COSMOS_CP__)
    onUpdate();
#else
    processUpdate();
#endif
    VfxBasePopup::onRotate(param);
}


void VcpConfirmPopup::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP7", SA_start);
#endif

VfxU32 MaxLinesCount = 4;
#if defined(__MMI_VUI_COSMOS_CP__)
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxU32 height;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        height = VCP_CONFIRM_POPUP_CALC_HEIGHT_PORTRAIT; 
    }
    else
    {
        height = VCP_CONFIRM_POPUP_CALC_HEIGHT_LANDSCAPE;
    }

    if(m_button[1]) 
    {
        height -= (VCP_CONFIRM_POPUP_BUTTON_GAP + VCP_CONFIRM_POPUP_BUTTON_HEIGHT);
    }

    // Create another textframe object similar to m_textFrame to judge how many lines can be fit in 
    // depening upon max height and width (according to rotation) and currenlty set Font size.
    VfxTextFrame *temp_textFrame;
    VFX_OBJ_CREATE(temp_textFrame, VfxTextFrame, this);
    temp_textFrame->setSize(VCP_CONFIRM_POPUP_TEXT_WIDTH, height);
    temp_textFrame->setLineMode(m_textFrame->getLineMode());
    temp_textFrame->setFont(m_textFrame->getFont());
    temp_textFrame->setAlignMode(m_textFrame->getAlignMode());
    temp_textFrame->setAutoResized(VFX_FALSE);
    temp_textFrame->setString(m_textFrame->getString());
    
    // Just use the following Max line count that could fit with the current popup configuration (1 or 2 button)
    MaxLinesCount = temp_textFrame->getLineCount();
    VFX_OBJ_CLOSE(temp_textFrame);
#endif

    // Set calculated max line height
    m_textFrame->setMaxLines(MaxLinesCount);
    m_textFrame->forceUpdate();
    m_textHeight = m_textFrame->getSize().height;
    
    if (m_textHeight < VCP_CONFIRM_POPUP_ICON_HEIGHT)
    {
        // text area is smaller then image
        m_textHeight = VCP_CONFIRM_POPUP_ICON_HEIGHT;
        m_textFrame->setAnchor(0,0.5);
        m_textFrame->setPos(VCP_CONFIRM_POPUP_TEXT_X, VCP_CONFIRM_POPUP_ICON_Y);
        m_textFrame->setSize(VCP_CONFIRM_POPUP_TEXT_WIDTH, 20);
        m_icon->setPos(VCP_CONFIRM_POPUP_ICON_X, VCP_CONFIRM_POPUP_ICON_Y - 1);

        m_upRegionHeight = VCP_CONFIRM_POPUP_UP_HEIGHT + VCP_CONFIRM_POPUP_ICON_HEIGHT;
    }
    else
    {
        m_textFrame->setAnchor(0,0);
        m_textFrame->setPos(VCP_CONFIRM_POPUP_TEXT_X, VCP_CONFIRM_POPUP_TEXT_Y);
        m_textFrame->setSize(VCP_CONFIRM_POPUP_TEXT_WIDTH, 20);    
        m_icon->setPos(VCP_CONFIRM_POPUP_ICON_X, VCP_CONFIRM_POPUP_TEXT_Y + m_textHeight/2);
        m_upRegionHeight = VCP_CONFIRM_POPUP_UP_HEIGHT + m_textHeight;
    }

    m_upRegionHeight += (m_bottomRegionHeight ? 0 : VCP_CONFIRM_POPUP_BOTTOM_HEIGHT);
    m_backgroundTop->setBounds(0,0,VCP_CONFIRM_POPUP_WIDTH,m_upRegionHeight);

    m_backgroundBottom->setPos(0, m_upRegionHeight);
    m_backgroundBottom->setBounds(0,0,VCP_CONFIRM_POPUP_WIDTH, m_bottomRegionHeight + (m_bottomRegionHeight ? VCP_CONFIRM_POPUP_BOTTOM_HEIGHT : 0));
    
    setBounds(0, 0, VCP_CONFIRM_POPUP_WIDTH, m_upRegionHeight + m_bottomRegionHeight + (m_bottomRegionHeight ? VCP_CONFIRM_POPUP_BOTTOM_HEIGHT : 0));
#if defined(__MMI_VUI_COSMOS_CP__)
    m_backgroundBottomImage->setSize(VCP_CONFIRM_POPUP_WIDTH, m_upRegionHeight + m_bottomRegionHeight + (m_bottomRegionHeight ? VCP_CONFIRM_POPUP_BOTTOM_HEIGHT : 0));
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP7", SA_stop);
#endif
}


void VcpConfirmPopup::onPenInputOnOutside(VfxPenEvent &event)
{
    VfxBasePopup::onPenInputOnOutside(event);
}


VfxBool VcpConfirmPopup::onKeyInput(VfxKeyEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP8", SA_start);
#endif
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_CANCEL)
                {
                    m_signalButtonClicked.postEmit(this, VCP_CONFIRM_POPUP_BUTTON_CANCEL);
                    m_buttonPressed = VFX_TRUE;
                }
                else if (m_cancelButtonIndex != -1)
                {
                    m_signalButtonClicked.postEmit(this, m_cancelButtonIndex ? VCP_CONFIRM_POPUP_BUTTON_USER_2 : VCP_CONFIRM_POPUP_BUTTON_USER_1);
                    m_buttonPressed = VFX_TRUE;
                }
                leave(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("FP8", SA_stop);
#endif
                return VFX_TRUE;            
            case VFX_KEY_CODE_POWER:
                break;
            case VFX_KEY_CODE_HOME:
                break;
            case VFX_KEY_CODE_VOL_UP:
                break;
            case VFX_KEY_CODE_VOL_DOWN:
                break;
            default:
                break;
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP8", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP9", SA_start);
#endif
    VfxBool res = VfxBasePopup::onKeyInput(event);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FP9", SA_stop);
#endif
    return res;
}

/* vaib mem reduction*/
void VcpConfirmPopup::setText(VfxResId text_id)
{
	setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpConfirmPopup::setText(const VfxWChar* text_buf)
{
	setText(VFX_WSTR_MEM(text_buf));
}

void VcpConfirmPopup::setText(const VfxWString &text)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPa", SA_start);
#endif
    m_textFrame->setString(text);
    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPa", SA_stop);
#endif
}


void VcpConfirmPopup::setTextFont(const VfxFontDesc &font)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPb", SA_start);
#endif
    m_textFrame->setFont(font);
    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPb", SA_stop);
#endif
}


void VcpConfirmPopup::setInfoType(VcpPopupTypeEnum type)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPc", SA_start);
#endif
    m_infoType = type;
    switch (type)
    {
        case VCP_POPUP_TYPE_FAILURE:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_FAILURE_CONFIRM));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        case VCP_POPUP_TYPE_INFO:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_INFO_CONFIRM));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        case VCP_POPUP_TYPE_WARNING:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_WARNING_CONFIRM));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        case VCP_POPUP_TYPE_SUCCESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_SUCCESS_CONFIRMT));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        case VCP_POPUP_TYPE_PROGRESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_PROGRESS_CONFIRM));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        case VCP_POPUP_TYPE_QUESTION:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_QUESTION_CONFIRM));
            m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            break;
        default:
            VFX_ASSERT(0);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPc", SA_stop);
#endif
}

/* vaib mem reduction*/
void VcpConfirmPopup::setCustomButton(
        VfxResId btnText1_id, 
        VfxResId btnText2_id,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2
        )
{
	setCustomButton(VFX_WSTR_RES(btnText1_id),VFX_WSTR_RES(btnText2_id),type1,type2);	
}

/* vaib mem reduction*/
void VcpConfirmPopup::setCustomButton(
        const VfxWChar* btnText1_buf, 
        const VfxWChar* btnText2_buf,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2
        )
{
	setCustomButton(VFX_WSTR_MEM(btnText1_buf),VFX_WSTR_MEM(btnText2_buf),type1,type2);	
}

void VcpConfirmPopup::setCustomButton(
        const VfxWString &btnText1, 
        const VfxWString &btnText2,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2
        )
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPd", SA_start);
#endif
    if (btnText1)
    {
        if(!m_button[0])
        {
            VFX_OBJ_CREATE(m_button[0], VcpButton, m_backgroundBottom);
            m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[0]->setInnerRect(VfxRect(
                                        VCP_CONFIRM_POPUP_BUTTON_X, 
                                        VCP_CONFIRM_POPUP_BUTTON_Y, 
                                        VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                        VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                 ));
            m_button[0]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
        }
        m_button[0]->setText(btnText1);

        m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
        checkUpdate();

#if defined(__MMI_VUI_COSMOS_CP__)
        switch (type1)
        {
            case VCP_POPUP_BUTTON_TYPE_NORMAL:
                break;

            case VCP_POPUP_BUTTON_TYPE_WARNING:
                    m_button[0]->setStyle(VCP_BUTTON_STYLE_RED);
                break;

            case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
                break;

            case VCP_POPUP_BUTTON_TYPE_CANCEL:
                m_cancelButtonIndex = 0;
                m_button[0]->setStyle(VCP_BUTTON_STYLE_GREY);
                break;
            default:
                VFX_ASSERT(0);
        }
#else
        m_button[0]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
        switch (type1)
        {
            case VCP_POPUP_BUTTON_TYPE_NORMAL:
                m_button[0]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                            ));
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_BLACK));
                break;

            case VCP_POPUP_BUTTON_TYPE_WARNING:
                m_button[0]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL
                                             ));
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_WHITE));
                break;

            case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
                m_button[0]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                            ));
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_BLACK));
                break;

            case VCP_POPUP_BUTTON_TYPE_CANCEL:
                m_button[0]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                             ));
                m_cancelButtonIndex = 0;
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_WHITE));
                break;
            default:
                VFX_ASSERT(0);
        }
#endif
    }
    else
    {
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPd", SA_stop);
#endif
        return;
    }

    if (btnText2)
    {
        if(!m_button[1])
        {
            VFX_OBJ_CREATE(m_button[1], VcpButton, m_backgroundBottom);
            m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[1]->setInnerRect(VfxRect(
                                        VCP_CONFIRM_POPUP_BUTTON_X, 
                                        VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP, 
                                        VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                        VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                    ));
            m_button[1]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
        }
        m_button[1]->setText(btnText2);
        
        m_bottomRegionHeight = 2 * VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
        checkUpdate();
        
#if defined(__MMI_VUI_COSMOS_CP__)
        switch (type2)
        {
            case VCP_POPUP_BUTTON_TYPE_NORMAL:
                break;

            case VCP_POPUP_BUTTON_TYPE_WARNING:
                    m_button[1]->setStyle(VCP_BUTTON_STYLE_RED);
                break;

            case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
                break;

            case VCP_POPUP_BUTTON_TYPE_CANCEL:
                m_cancelButtonIndex = 1;
                m_button[1]->setStyle(VCP_BUTTON_STYLE_GREY);
                break;
            default:
                VFX_ASSERT(0);
        }
#else
        m_button[1]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
        switch (type2)
        {
            case VCP_POPUP_BUTTON_TYPE_NORMAL:
                m_button[1]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                            ));
                m_button[1]->setTextColor(VfxColor(VFX_COLOR_BLACK));
                break;

            case VCP_POPUP_BUTTON_TYPE_WARNING:
                m_button[1]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_WARNING_NORMAL
                                             ));
                m_button[1]->setTextColor(VfxColor(VFX_COLOR_WHITE));
                break;

            case VCP_POPUP_BUTTON_TYPE_RECOMMEND:
                m_button[1]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                            ));
                m_button[1]->setTextColor(VfxColor(VFX_COLOR_BLACK));
                break;

            case VCP_POPUP_BUTTON_TYPE_CANCEL:
                m_button[1]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                             ));
                m_cancelButtonIndex = 1;
                m_button[1]->setTextColor(VfxColor(VFX_COLOR_WHITE));
                break;
            default:
                VFX_ASSERT(0);
        }
#endif
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPd", SA_stop);
#endif
}


void VcpConfirmPopup::setButtonSet(VcpConfirmPopupButtonSetEnum buttonSet)
{
    resetButton();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPe", SA_start);
#endif
    switch (buttonSet)
    {
        case VCP_CONFIRM_BUTTON_SET_OK:
            m_buttonSet = VCP_CONFIRM_BUTTON_SET_OK;

            // "Ok" button
            VFX_OBJ_CREATE(m_button[0], VcpButton, m_backgroundBottom);
            m_button[0]->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
            m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[0]->setInnerRect(VfxRect(
                                    VCP_CONFIRM_POPUP_BUTTON_X, 
                                    VCP_CONFIRM_POPUP_BUTTON_Y, 
                                    VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                    VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                 ));
            m_button[0]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
            #if !defined(__MMI_VUI_COSMOS_CP__)
                m_button[0]->setBgImageList(VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                             ));
                m_button[0]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_BLACK));
            #endif
            m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
            break;

        case VCP_CONFIRM_BUTTON_SET_CANCEL:
            m_buttonSet = VCP_CONFIRM_BUTTON_SET_CANCEL;

            // "Cancel" button
            VFX_OBJ_CREATE(m_button[0], VcpButton, m_backgroundBottom);
            m_button[0]->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
            m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[0]->setInnerRect(VfxRect(
                                    VCP_CONFIRM_POPUP_BUTTON_X, 
                                    VCP_CONFIRM_POPUP_BUTTON_Y, 
                                    VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                    VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                 ));
            m_button[0]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
            #if defined(__MMI_VUI_COSMOS_CP__)
                m_button[0]->setStyle(VCP_BUTTON_STYLE_GREY);
            #else
                m_button[0]->setBgImageList(VcpStateImage(
                                                    VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                    VCP_IMG_POPUP_BUTTON_PRESSED,
                                                    VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                    VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                                 ));
                m_button[0]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_WHITE));
            #endif
            m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
            break;

        case VCP_CONFIRM_BUTTON_SET_YES_NO:
            m_buttonSet = VCP_CONFIRM_BUTTON_SET_YES_NO;

            // "Yes" button
            VFX_OBJ_CREATE(m_button[0], VcpButton, m_backgroundBottom);
            m_button[0]->setText(VFX_WSTR_RES(STR_GLOBAL_YES));
            m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[0]->setInnerRect(VfxRect(
                                    VCP_CONFIRM_POPUP_BUTTON_X, 
                                    VCP_CONFIRM_POPUP_BUTTON_Y, 
                                    VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                    VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                 ));
            m_button[0]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
            #if !defined(__MMI_VUI_COSMOS_CP__)
                m_button[0]->setBgImageList(VcpStateImage(
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                    VCP_IMG_POPUP_BUTTON_PRESSED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                                 ));
                m_button[0]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
                m_button[0]->setTextColor(VfxColor(VFX_COLOR_BLACK));
            #endif

            // "No" Button
            VFX_OBJ_CREATE(m_button[1], VcpButton, m_backgroundBottom);
            m_button[1]->setText(VFX_WSTR_RES(STR_GLOBAL_NO));
            m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_button[1]->setInnerRect(VfxRect(
                                    VCP_CONFIRM_POPUP_BUTTON_X, 
                                    VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP, 
                                    VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                    VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                                ));
            m_button[1]->m_signalClicked.connect(this, &VcpConfirmPopup::onButtonClick);
            #if !defined(__MMI_VUI_COSMOS_CP__)
                m_button[1]->setBgImageList(VcpStateImage(
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL,
                                                    VCP_IMG_POPUP_BUTTON_PRESSED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_DISABLED,
                                                    VCP_IMG_POPUP_BUTTON_NORMAL_NORMAL
                                                 ));
                m_button[1]->setMargin(VCP_CONFIRM_POPUP_BUTTON_MARGIN_SET);
                m_button[1]->setTextColor(VfxColor(VFX_COLOR_BLACK));
            #endif
            m_bottomRegionHeight = 2 * VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
            break;

        case VCP_CONFIRM_BUTTON_SET_USER_DEFINE:
            m_buttonSet = VCP_CONFIRM_BUTTON_SET_USER_DEFINE;
            break;

        default:
            VFX_ASSERT(0);
    }

    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPe", SA_stop);
#endif
}


void VcpConfirmPopup::setImage(const VfxImageSrc &imgScr)
{
    m_icon->setImgContent(imgScr);
}


void VcpConfirmPopup::setTextAlignMode(VfxTextFrame::AlignModeEnum value)
{
    m_textFrame->setAlignMode(value);
    checkUpdate();
}


void VcpConfirmPopup::resetButton()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPg", SA_start);
#endif
    if (m_button[0])
    {
        VFX_OBJ_CLOSE(m_button[0]);
    }
    if (m_button[1])
    {
        VFX_OBJ_CLOSE(m_button[1]);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPg", SA_stop);
#endif
}


void VcpConfirmPopup::onButtonClick(VfxObject* sender, VfxId id)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPh", SA_start);
#endif
    VFX_UNUSED(id);
    if (m_buttonPressed)
    {
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPh", SA_stop);
#endif
        return;
    }

    m_buttonPressed = VFX_TRUE; 

    switch (m_buttonSet)
    {
        case VCP_CONFIRM_BUTTON_SET_OK:
            if (sender == m_button[0])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_OK);
            }
            else
            {
                VFX_ASSERT(0);
            }
            break;
        case VCP_CONFIRM_BUTTON_SET_CANCEL:
            if (sender == m_button[0])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_CANCEL);
            }
            else
            {
                VFX_ASSERT(0);
            }
            break;
        case VCP_CONFIRM_BUTTON_SET_YES_NO:
            if (sender == m_button[0])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_YES);
            }
            else if (sender == m_button[1])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_NO);
            }
            else
            {
                VFX_ASSERT(0);
            }
            break;
        case VCP_CONFIRM_BUTTON_SET_USER_DEFINE:
            if (sender == m_button[0])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_USER_1);
            }
            else if (sender == m_button[1])
            {
                m_signalButtonClicked.postEmit(this,VCP_CONFIRM_POPUP_BUTTON_USER_2);
            }
            else
            {
                VFX_ASSERT(0);
            }
            break;
        default:
            VFX_ASSERT(0);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPh", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPi", SA_start);
#endif
    leave(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPi", SA_stop);
#endif
}


#if defined(__MMI_VUI_COSMOS_CP__)
void VcpConfirmPopup::setIsPlayTone(VfxBool option)
{
    m_isPlayTone = option;
}
#endif


void VcpConfirmPopup::onPlayTone()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPj", SA_start);
#endif
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
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPj", SA_stop);
#endif
}


void VcpConfirmPopup::onStopTone()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPk", SA_start);
#endif
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
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FPk", SA_stop);
#endif
}


