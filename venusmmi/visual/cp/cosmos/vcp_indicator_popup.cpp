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
 *  vcp_indicator_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Indicator Popup
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
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
#include "vcp_indicator_popup.h"

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
 * Class VcpIndicatorPopup
 *****************************************************************************/

VcpIndicatorPopup::VcpIndicatorPopup() :
    m_backgroundTop(NULL),
    m_backgroundBottom(NULL),
    m_textFrame(NULL),
    m_popupType(VCP_INDICATOR_POPUP_STYLE_NONE),
    m_button(NULL),
    m_progressInd(NULL),
    m_actInd(NULL),
    m_buttonPressed(VFX_FALSE)
{
}


void VcpIndicatorPopup::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP0", SA_start);
#endif
    VfxBasePopup::onInit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP0", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP1", SA_start);
#endif

    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this); 

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_backgroundTop);
    m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));    
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);  /* set truncate mode*/
    m_textFrame->setMaxLines(4);
    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_INDICATOR_POPUP_FONT_SIZE)));
    m_textFrame->setAutoAnimate(VFX_TRUE);

    setSize(VCP_INDICATOR_POPUP_WIDTH, VCP_INDICATOR_POPUP_MIN_HEIGHT);
    
    checkUpdate();    
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("IP1", SA_stop);
#endif
}


VfxBool VcpIndicatorPopup::onKeyInput(VfxKeyEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP2", SA_start);
#endif
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                if((m_popupType == VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON) ||
                    (m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON) ||
                    (m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
                {
                    if (!m_buttonPressed)
                    {
                        m_signalCanceled.postEmit(this, getProgress());
                        m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_CANCEL_PRESSED);
                        m_buttonPressed = VFX_TRUE;
                    } 
                    leave(VFX_TRUE);
                }
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IP2", SA_stop);
#endif
                return VFX_TRUE;
            case VFX_KEY_CODE_POWER:
                break;
            case VFX_KEY_CODE_HOME:
                if((m_popupType == VCP_INDICATOR_POPUP_STYLE_TEXT) ||
                    (m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY) ||
                    (m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS))
                {
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("IP2", SA_stop);
#endif
                    return VFX_TRUE;
                }
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
    SLA_CustomLogging("IP2", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP3", SA_start);
#endif
    VfxBool result = VfxBasePopup::onKeyInput(event);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP3", SA_stop);
#endif
    return result;
}


void VcpIndicatorPopup::onEnter()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP4", SA_start);
#endif
    VfxBasePopup::onEnter();
    m_textFrame->setAutoAnimate(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP4", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP5", SA_start);
#endif
    switch (m_popupType)
    {
        case VCP_INDICATOR_POPUP_STYLE_ACTIVITY:
        case VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON:
        if(m_actInd)
        {
            m_actInd->start();
        }
        break;
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS:
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON:
            if(m_progressInd)
            {
                m_progressInd->setHidden(VFX_FALSE);
            }
            break;
        default:
            break;
    }
    m_buttonPressed = VFX_FALSE;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP5", SA_stop);
#endif
}


void VcpIndicatorPopup::onExit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP6", SA_start);
#endif    
    m_textFrame->setAutoAnimate(VFX_FALSE);

    if((m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS) ||
        (m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
    {
        m_progressInd->setIsAnimate(VFX_FALSE);
        m_progressInd->setProgress(m_progressInd->getProgress());
    }
    else
    {
        if(m_actInd)
        {
            m_actInd->stop();
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP6", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP7", SA_start);
#endif
    VfxBasePopup::onExit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP7", SA_stop);
#endif
}


void VcpIndicatorPopup::onLeaveStack()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP8", SA_start);
#endif
    if((m_popupType == VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON) ||
        (m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON) ||
        (m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
    {
        if (!m_buttonPressed)
        {
             m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP8", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP9", SA_start);
#endif
    VfxBasePopup::onLeaveStack();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IP9", SA_stop);
#endif
}

/* vaib mem reduction */
void VcpIndicatorPopup::setText(VfxResId text_id)
{
	setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction */
void VcpIndicatorPopup::setText(const VfxWChar* text_buf)
{
	setText(VFX_WSTR_MEM(text_buf));
}

void VcpIndicatorPopup::setText(const VfxWString &text)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPa", SA_start);
#endif
    if((m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY) ||
        (m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON))
    {
    	VfxS32 textW = (getSize().width - 
					(VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN + 
						VCP_INDICATOR_POPUP_ACT_IND_SIZE + 
						VCP_INDICATOR_POPUP_SIDE_GAP + 
						VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN));
        m_textFrame->setString(text);
	    m_textFrame->setBounds(0, 0, textW, VCP_INDICATOR_POPUP_TEXT_HEIGHT);
    }
    else
    {
        m_textFrame->setString(text);
    }

    if(getHidden()) 
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        onUpdate();
        VfxAutoAnimate::commit();
    }
    else 
    {
        checkUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPa", SA_stop);
#endif
}


const VfxWString& VcpIndicatorPopup::getText() const
{
    return m_textFrame->getString();
}


void VcpIndicatorPopup::setInfoType(VcpIndicatorPopupStyleEnum type)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPb", SA_start);
#endif

    m_popupType = type;
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_NONE)
    {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("IPb", SA_stop);
#endif
        // Indicator already created.
        return;
    }
    
    if(m_actInd)
    {
        m_actInd->stop();
    }
    if(m_progressInd)
    {
        m_progressInd->setHidden(VFX_TRUE);
    }
    
    switch (type)
    {
        case VCP_INDICATOR_POPUP_STYLE_TEXT:
        case VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON:
			{
                VfxS32 textX = VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN;                
                m_textFrame->setRect(
                    textX, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN,
                    getSize().width - (textX + VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN), 
                    VCP_INDICATOR_POPUP_TEXT_HEIGHT);
                m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
				break;
			}
		case VCP_INDICATOR_POPUP_STYLE_ACTIVITY:
		case VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON:
            {                
                if(!m_actInd)
                {
                    VFX_OBJ_CREATE(m_actInd, VcpActivityIndicator, m_backgroundTop);
                }
                VfxS32 textX = VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN + VCP_INDICATOR_POPUP_ACT_IND_SIZE + VCP_INDICATOR_POPUP_SIDE_GAP;                
                m_textFrame->setRect(
                    textX, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN,
                    getSize().width - (textX + VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN), 
                    VCP_INDICATOR_POPUP_TEXT_HEIGHT);
                m_actInd->setAnchor(0,0.5);
                m_actInd->setPos(VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN, m_textFrame->getPos().y + (VCP_INDICATOR_POPUP_TEXT_HEIGHT/2));
                m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
                break;
            }
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS:
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON:
            {
                if(!m_progressInd)
                {
                    VFX_OBJ_CREATE(m_progressInd, VcpProgressIndicator, m_backgroundTop);                
                }
                m_textFrame->setRect(
                    VCP_INDICATOR_POPUP_LEFT_MARGIN, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN, 
                    VCP_INDICATOR_POPUP_CONTENT_WIDTH, 
                    VCP_INDICATOR_POPUP_TEXT_HEIGHT);                   
                m_progressInd->setWidth(VCP_INDICATOR_POPUP_CONTENT_WIDTH);
                m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
                break;
            }        
        default:
            VFX_ASSERT(0);
    }

    switch (type)
    {
        case VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON:
		case VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON:
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON:
            if(!m_button)
            {
                VFX_OBJ_CREATE(m_button, VcpButton, m_backgroundBottom);                       
                m_button->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
                m_button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                m_button->setInnerRect(VfxRect(
                    VCP_INDICATOR_POPUP_LEFT_MARGIN, 
                    VCP_INDICATOR_POPUP_VERT_GAP, 
                    VCP_INDICATOR_POPUP_BUTTON_WIDTH, 
                    VCP_INDICATOR_POPUP_BUTTON_HEIGHT
                ));
            m_button->m_signalClicked.connect(this, &VcpIndicatorPopup::onButtonClick);
            m_button->setStyle(VCP_BUTTON_STYLE_GREY);
            }            
            break;

        default:
            if(m_button)
            {
                VFX_OBJ_CLOSE(m_button);
            }            
            break;
    }
    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPb", SA_stop);
#endif
}


void VcpIndicatorPopup::onRotate(const VfxScreenRotateParam &param)
{
    processUpdate();    
    VfxBasePopup::onRotate(param);
}


void VcpIndicatorPopup::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPc", SA_start);
#endif
    VfxBasePopup::onUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPc", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPd", SA_start);
#endif

    VfxS32 topHeight = 0;

    switch (m_popupType)
    {
        case VCP_INDICATOR_POPUP_STYLE_TEXT:
        case VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON:
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPm", SA_start);
#endif
                m_textFrame->forceUpdate();    
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("IPm", SA_stop);
#endif
                VfxS32 textHeight = m_textFrame->getSize().height;

                if (textHeight < VCP_INDICATOR_POPUP_TEXT_HEIGHT)
                {
                    // text area is smaller then image
                    textHeight = VCP_INDICATOR_POPUP_TEXT_HEIGHT;
                }

                m_textFrame->setRect(
                    VCP_INDICATOR_POPUP_LEFT_MARGIN, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN, 
                    VCP_INDICATOR_POPUP_CONTENT_WIDTH, 
                    textHeight);

                topHeight = VCP_INDICATOR_POPUP_TOP_MARGIN + textHeight;
                break;
            }

        case VCP_INDICATOR_POPUP_STYLE_ACTIVITY:
        case VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON:
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPr", SA_start);
#endif
	            m_textFrame->setBestFitWidth(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPr", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPn", SA_start);
#endif
                m_textFrame->forceUpdate();    
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPn", SA_stop);
#endif
                VfxS32 textHeight = m_textFrame->getSize().height;
                VfxS32 textWidth = m_textFrame->getSize().width;
                VfxS32 actX = VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN + (
                                (VCP_INDICATOR_POPUP_WIDTH - 
								(VCP_INDICATOR_POPUP_ACT_LEFT_MARGIN + 
								VCP_INDICATOR_POPUP_ACT_IND_SIZE + 
								VCP_INDICATOR_POPUP_SIDE_GAP + 
								textWidth + 
			    					VCP_INDICATOR_POPUP_ACT_RIGHT_MARGIN)
			    				) / 2);
                VfxS32 textX = actX + VCP_INDICATOR_POPUP_ACT_IND_SIZE + VCP_INDICATOR_POPUP_SIDE_GAP;

                if (textHeight < VCP_INDICATOR_POPUP_TEXT_HEIGHT)
                {
                    // text area is smaller then image
                    textHeight = VCP_INDICATOR_POPUP_TEXT_HEIGHT;
                    m_textFrame->setAnchor(0,0.5);
                    m_textFrame->setPos(textX, VCP_INDICATOR_POPUP_TOP_MARGIN + VCP_INDICATOR_POPUP_ACT_IND_SIZE/2);
					topHeight = VCP_INDICATOR_POPUP_TOP_MARGIN + VCP_INDICATOR_POPUP_ACT_IND_SIZE;
                }
                else
                {
                    m_textFrame->setAnchor(0,0);
                    m_textFrame->setPos(textX, VCP_INDICATOR_POPUP_TOP_MARGIN);
					topHeight = VCP_INDICATOR_POPUP_TOP_MARGIN + textHeight;
                }

                m_actInd->setAnchor(0,0.5);
                m_actInd->setPos(actX, VCP_INDICATOR_POPUP_TOP_MARGIN + (textHeight/2));
                break;
            }

        case VCP_INDICATOR_POPUP_STYLE_PROGRESS:
        case VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON:
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPq", SA_start);
#endif
	        m_textFrame->setBestFitWidth(VFX_FALSE);
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPq", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPp", SA_start);
#endif
                m_textFrame->forceUpdate();    
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("IPp", SA_stop);
#endif
                VfxS32 textHeight = m_textFrame->getSize().height;

                if (textHeight < VCP_INDICATOR_POPUP_TEXT_HEIGHT)
                {
                    // text area is smaller then image
                    textHeight = VCP_INDICATOR_POPUP_TEXT_HEIGHT;
                }

                m_textFrame->setRect(
                    VCP_INDICATOR_POPUP_LEFT_MARGIN, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN, 
                    VCP_INDICATOR_POPUP_CONTENT_WIDTH, 
                    textHeight);
                m_progressInd->setPos(
                    VCP_INDICATOR_POPUP_LEFT_MARGIN, 
                    VCP_INDICATOR_POPUP_TOP_MARGIN + textHeight + VCP_INDICATOR_POPUP_VERT_GAP);

                topHeight = VCP_INDICATOR_POPUP_TOP_MARGIN + textHeight;

                if(m_progressInd)
                {
                    topHeight += VCP_INDICATOR_POPUP_VERT_GAP + m_progressInd->getSize().height;
                }
                break;
            }
    }
    
    m_backgroundTop->setSize(getSize().width, topHeight);    
    
    VfxS32 bottomHeight = VCP_INDICATOR_POPUP_BOTTOM_MARGIN;
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON)
    {
        if(m_button)
        {
            bottomHeight += VCP_INDICATOR_POPUP_VERT_GAP + VCP_INDICATOR_POPUP_BUTTON_HEIGHT;
        }
    }
    
    m_backgroundBottom->setPos(0, m_backgroundTop->getSize().height);
    m_backgroundBottom->setSize(getSize().width, bottomHeight);

    m_backgroundBottomImage->setSize(VCP_INDICATOR_POPUP_WIDTH, topHeight + bottomHeight);
    
    setSize(VCP_INDICATOR_POPUP_WIDTH, topHeight + bottomHeight);    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPd", SA_stop);
#endif
}


void VcpIndicatorPopup::onButtonClick(VfxObject* sender, VfxId id)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPe", SA_start);
#endif
    if (m_buttonPressed)
    {
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPe", SA_stop);
#endif
        return;
    }
    m_buttonPressed = VFX_TRUE;

    m_signalCanceled.postEmit(this, getProgress());
    m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_CANCEL_PRESSED);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPe", SA_stop);
#endif
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPf", SA_start);
#endif
    leave(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("IPf", SA_stop);
#endif
}


VcpIndicatorPopupStyleEnum VcpIndicatorPopup::getInfoType(void) const
{
    return m_popupType;
}


VfxBool VcpIndicatorPopup::setProgress(VfxFloat progress_value)
{
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON)
    {
        return ((VcpProgressIndicator*)m_progressInd)->setProgress(progress_value);
    }
    return VFX_FALSE;
}


VfxFloat VcpIndicatorPopup::getProgress(void) const
{
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON)
    {
        return ((VcpProgressIndicator*)m_progressInd)->getProgress();
    }
    return -1.0;
}


VfxBool  VcpIndicatorPopup::setMaxProgress(VfxFloat progress_value)
{
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON)
    {
        return ((VcpProgressIndicator*)m_progressInd)->setMaxProgressValue(progress_value);
    }
    return VFX_FALSE;
}


VfxFloat VcpIndicatorPopup::getMaxProgress(void) const
{
    if(m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS ||
        m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON)
    {
        return ((VcpProgressIndicator*)m_progressInd)->getMaxProgressValue();
    }
    return -1.0;
}


void VcpIndicatorPopup::setIsAnimate(VfxBool isAnim)
{
    if(m_progressInd)
    {
        m_progressInd->setIsAnimate(isAnim);
    }
}


VfxBool VcpIndicatorPopup::getIsAnimate() const
{
    if(m_progressInd)
    {
        return m_progressInd->getIsAnimate();
    }
    // Warning removal
    return VFX_FALSE;
}


void VcpIndicatorPopup::pauseProgress()
{
    if(m_progressInd)
    {
        m_progressInd->pauseProgress();
    }
}


void VcpIndicatorPopup::resumeProgress() 
{
    if(m_progressInd)
    {
        m_progressInd->resumeProgress();
    }
}


