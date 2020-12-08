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
 *  vcp_more_popup.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup_data_type.h"
#include "vcp_more_command_popup.h"
#include "vadp_mmi_frm.h"
extern "C"
{
#include "custom_events_notify.h"
#include "profilesSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
}

#include "vfx_base_popup.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vfx_image_src.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vcp_button.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/




/*****************************************************************************
 * Class VcpMoreCommandPopup
 *****************************************************************************/

VcpMoreCommandPopup::VcpMoreCommandPopup() :
    m_backgroundBottom(NULL),
    m_buttonCount(0),    
    m_buttonPressed(VFX_FALSE),
    m_cancelButtonIndex(-1)
{
    VfxS32 i;
    for (i = 0; i < 7; i++)
    {
        m_button[i] = NULL;
    }
}


void VcpMoreCommandPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT, VCP_MORE_COMMAND_POPUP_UP_HEIGHT);

	VfxFrame *backgroundTop;

    VFX_OBJ_CREATE(backgroundTop, VfxFrame, this);
    backgroundTop->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    backgroundTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    backgroundTop->setIsCached(VFX_TRUE);
    backgroundTop->setBounds(0, 0, VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT, VCP_MORE_COMMAND_POPUP_UP_HEIGHT);
    backgroundTop->setAutoAnimate(VFX_TRUE);
    backgroundTop->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_buttonPanel, VcpScrollable, m_backgroundBottom);
    m_buttonPanel->setAutoAnimate(VFX_TRUE);
    m_buttonPanel->setBounds(VfxRect(0, 0, VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT, VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT));
    m_buttonPanel->setViewRect(VfxRect(0, 0, VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT, VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT)); 
    
    VfxTextFrame *textFrame;
	VFX_OBJ_CREATE(textFrame, VfxTextFrame, backgroundTop);
    textFrame->setFullLineHeightMode(VFX_FALSE);
    textFrame->setAnchor(0.5,0.5);
    textFrame->setPos(VCP_MORE_COMMAND_POPUP_TEXT_X, (VCP_MORE_COMMAND_POPUP_UP_HEIGHT + 1) / 2);
    textFrame->setSize(VCP_MORE_COMMAND_POPUP_TEXT_WIDTH, 20);
    
    textFrame->setString(VFX_WSTR_RES(STR_GLOBAL_MORE));
    textFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    textFrame->setAutoAnimate(VFX_TRUE);
    
    textFrame->setColor(VfxColor(255,255,255,255));
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_MORE_COMMAND_POPUP_TEXT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    textFrame->setFont(fontDesc);
    textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    checkUpdate();
}


void VcpMoreCommandPopup::onEnter()
{
    VfxBasePopup::onEnter();
    onUpdate();
    m_buttonPressed = VFX_FALSE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


void VcpMoreCommandPopup::onLeaveStack()
{
    if (!m_buttonPressed)
    {
         m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    }
    VfxBasePopup::onLeaveStack();
}

void VcpMoreCommandPopup::onRotate(const VfxScreenRotateParam &param)
{
    checkUpdate();
    processUpdate();
    VfxBasePopup::onRotate(param);
}


VfxBool VcpMoreCommandPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (m_cancelButtonIndex != -1)
        {
            m_signalButtonClicked.postEmit(this, m_button[m_cancelButtonIndex]->getId());
            m_buttonPressed = VFX_TRUE;
        }
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}


void VcpMoreCommandPopup::onUpdate()
{

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 maxPanelHeight;
    VfxS32 finalPanelHeight;
    VfxS32 finalPanelWidth;
	VfxS32 panelHeight = m_buttonCount * (VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT + VCP_MORE_COMMAND_POPUP_BUTTON_GAP) - VCP_MORE_COMMAND_POPUP_BUTTON_GAP + VCP_BUTTON_SHADOW_MARGIN_BOTTOM;

    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        maxPanelHeight = VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT;
        finalPanelWidth = VCP_MORE_COMMAND_POPUP_WIDTH_PORTRAIT;
    }
    else
    {
        maxPanelHeight = VCP_MORE_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE;
        finalPanelWidth = VCP_MORE_COMMAND_POPUP_WIDTH_LANDSCAPE;
    }
    m_buttonPanel->setContentSize(VfxSize(finalPanelWidth, panelHeight));
    m_buttonPanel->setValidContentRect(VfxRect(0, 0, finalPanelWidth, panelHeight));
    m_buttonPanel->setWarningContentRect(VfxRect(0, 0, finalPanelWidth, panelHeight));

    if (panelHeight > maxPanelHeight)
    {
        finalPanelHeight = maxPanelHeight;    
    }
	else
	{
		finalPanelHeight = panelHeight;
	}
    
    m_buttonPanel->setViewRect(VfxRect(0, 0, finalPanelWidth, finalPanelHeight)); 
    m_buttonPanel->setBounds(VfxRect(0, 0, finalPanelWidth, finalPanelHeight));
    m_buttonPanel->setPos(0, VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT);
    m_buttonPanel->scrollRectToVisible(VfxRect(0, 0, finalPanelWidth, finalPanelHeight));

    VfxS32 bottomRegionHeight = VCP_MORE_COMMAND_POPUP_BOTTOM_HEIGHT + finalPanelHeight + VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT;
    
    m_backgroundBottom->setPos(0, VCP_MORE_COMMAND_POPUP_UP_HEIGHT);
    m_backgroundBottom->setBounds(0, 0, finalPanelWidth, bottomRegionHeight);

    m_backgroundBottomImage->setPos(0, VCP_MORE_COMMAND_POPUP_UP_HEIGHT);
    m_backgroundBottomImage->setBounds(0, 0, finalPanelWidth, bottomRegionHeight);
        
    setBounds(0, 0, finalPanelWidth, VCP_MORE_COMMAND_POPUP_UP_HEIGHT + bottomRegionHeight);
}

/* vaib mem reduction*/
void VcpMoreCommandPopup::addItem(VfxId id, VfxResId text_id, VcpPopupButtonTypeEnum type)
{
	addItem(id,VFX_WSTR_RES(text_id),type);
}

/* vaib mem reduction*/
void VcpMoreCommandPopup::addItem(VfxId id, const VfxWChar* text_buf, VcpPopupButtonTypeEnum type)
{
	addItem(id,VFX_WSTR_MEM(text_buf),type);
}


void VcpMoreCommandPopup::addItem(VfxId id, const VfxWString &text, VcpPopupButtonTypeEnum type)
{
    if (m_buttonCount >= 7)
    {
        return;
    }

    //VfxS32 shift = VCP_MORE_COMMAND_POPUP_BUTTON_Y_SHIFT;
    
    VFX_OBJ_CREATE(m_button[m_buttonCount], VcpButton, m_buttonPanel);
    m_button[m_buttonCount]->setText(text);
    //m_button[m_buttonCount]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    m_button[m_buttonCount]->setInnerRect(VfxRect(
                                        VCP_MORE_COMMAND_POPUP_BUTTON_X, 
                                        VCP_MORE_COMMAND_POPUP_BUTTON_Y + m_buttonCount * (VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT + VCP_MORE_COMMAND_POPUP_BUTTON_GAP),
                                        VCP_MORE_COMMAND_POPUP_BUTTON_WIDTH, 
                                        VCP_MORE_COMMAND_POPUP_BUTTON_HEIGHT
                                     ));
    m_button[m_buttonCount]->m_signalClicked.connect(this, &VcpMoreCommandPopup::onButtonClick);
    m_button[m_buttonCount]->setId(id);
    m_button[m_buttonCount]->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_button[m_buttonCount]->setAutoAnimate(VFX_TRUE);
    

	switch (type)
    {
        case VCP_POPUP_BUTTON_TYPE_WARNING:
            m_button[m_buttonCount]->setStyle(VCP_BUTTON_STYLE_RED);
            break;
        case VCP_POPUP_BUTTON_TYPE_CANCEL:
            m_button[m_buttonCount]->setStyle(VCP_BUTTON_STYLE_GREY);
            m_cancelButtonIndex = m_buttonCount;
            break;
       // default: 
            //VFX_ASSERT(0);
    }
    m_buttonCount ++;
    
    checkUpdate();
}


void VcpMoreCommandPopup::disableItem(VfxId id)
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
#endif

void VcpMoreCommandPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (m_buttonPressed)
    {
        return;
    }
    m_buttonPressed = VFX_TRUE;
    VfxS32 i;
    for (i = 0; i < 7; i++)
    {
        if (m_button[i] == sender)
        {
            m_signalButtonClicked.postEmit(this, id);
            break;
        }
    }

    leave(VFX_TRUE);
}



