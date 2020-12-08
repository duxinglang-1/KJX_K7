/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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

/*******************************************************************************
* Filename:
* ---------
*  vcp_segment_button.cpp
*
* Project:
* --------
*  Venus UI Components
*
* Description:
* ------------
*  Segment Button component
*
* Author:
* -------
 * -------
*
*============================================================================
*****************************************************************************/

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_segment_button.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_top_level.h"
#include "vfx_signal.h"
#include "vfx_object_list.h"
#include "vcp_button.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "mmi_rp_srv_venus_component_segment_button_def.h"

#define VCP_SEGMENT_BTN_CONTENT_MARGIN  4

#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/***************************************************************************** 
* Class VcpSegmentButton
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpSegmentButton", VcpSegmentButton, VfxControl);


VcpSegmentButton::VcpSegmentButton() :
m_count(0),
#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
m_ortn(VCP_SEGMENT_BUTTON_ORTN_HORIZONTAL),
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */
m_type(VCP_SEGMENT_BUTTON_TYPE_GROUP),
m_style(VCP_SEGMENT_BUTTON_STYLE_IMAGE_ONLY),
    m_highlightedId(INVALID_BUTTON_ID),
    m_fontSize(TEXT_FONT_SIZE)
{
}


void VcpSegmentButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgI", SA_start); 
#endif
    VfxControl::onInit();

    // set default size
    setSize(VfxSize(VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width, DEFAULT_HEIGHT));

    // register signal
    m_signalBoundsChanged.connect(this, &VcpSegmentButton::onBoundsChanged);
    setAutoAnimate(VFX_TRUE);
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgI", SA_stop); 
#endif
	
}


void VcpSegmentButton::onDeinit()
{
    VfxControl::onDeinit();
}

void VcpSegmentButton::setWidth(VfxS32 width)
{
#if defined(__MMI_VUI_COSMOS_CP__)
    width  = width < MINIMUM_WIDTH ? MINIMUM_WIDTH : width;
#endif /* defined(__MMI_VUI_COSMOS_CP__) */
    setSize(width, DEFAULT_HEIGHT);
    checkUpdate();
}

VfxS32 VcpSegmentButton::getWidth() const
{
    return getSize().width;
}

void VcpSegmentButton::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgU", SA_start); 
#endif
    if (m_count > 0)
    {
        VfxSize size = getSize();
        VfxS32 w=0, x=0;
#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
        VfxS32 h=0, y=0;
        if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_VERTICAL)
        {
            h = size.height / m_count;
            y = 0;
        }
        else if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_HORIZONTAL)
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */
        {
            w = size.width / m_count;
            x = 0;
        }


        for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
        {
            VcpButton *pButton = (VcpButton *)i->get();
            if(pButton->getIsHighlighted() == VFX_TRUE)
            {
            
#if defined(__MMI_VUI_COSMOS_CP__)
                pButton->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_fontSize), (VfxFontDescEffectEnum)((VFX_FONT_RES(VCP_FONT_SEG_BTN_HLTD)).effect)));
            }
            else
            {
                pButton->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_fontSize), (VfxFontDescEffectEnum)((VFX_FONT_RES(VCP_FONT_SEG_BTN_NRML)).effect)));
#else
                pButton->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_fontSize), VFX_FE1_1));
            }
            else
            {
                pButton->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_fontSize), VFX_FE1_4));
#endif
            }
            VfxSize s = pButton->getSize();
            VfxPoint p = pButton->getPos();
#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
            if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_VERTICAL)
            {
                // set button size
                s.width = size.width;
                s.height = h;

                // set button position
                p.y = y;
            }
            else if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_HORIZONTAL)
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */
            {
                // set button size
                s.width = w;
                s.height = size.height;

                // set button position
                p.x = x;
            }
            pButton->setSize(s);
            pButton->setPos(p);

#if defined(MULTI_LAYOUT_SEGBTN_SUPPORT)
            if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_VERTICAL)
            {
                y += h;
            }
            else if(m_ortn == VCP_SEGMENT_BUTTON_ORTN_HORIZONTAL)
#endif /* defined(MULTI_LAYOUT_SEGBTN_SUPPORT) */
            {
                x += w;
            }

            // configure button
            if (m_style == VCP_SEGMENT_BUTTON_STYLE_IMAGE_ONLY)
            {
                pButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
            }
            else
            {
                pButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            }

            // set button bg image
            if (m_count > 1)
            {
                if (i == m_list.getValidHead())
                {
                    pButton->setBgImageList(VcpStateImage(VCP_IMG_SEGMENT_BUTTON_LEFT_N, VCP_IMG_SEGMENT_BUTTON_LEFT_P, VCP_IMG_SEGMENT_BUTTON_LEFT_D, VCP_IMG_SEGMENT_BUTTON_LEFT_H));
                    pButton->setMargin(VCP_SEGMENT_BTN_CONTENT_MARGIN, 0, VCP_SEGMENT_BTN_CONTENT_MARGIN, 0);
                }
                else if (i == m_list.getValidTail())
                {
		    pButton->setBgImageList(VcpStateImage(VCP_IMG_SEGMENT_BUTTON_RIGHT_N, VCP_IMG_SEGMENT_BUTTON_RIGHT_P, VCP_IMG_SEGMENT_BUTTON_RIGHT_D, VCP_IMG_SEGMENT_BUTTON_RIGHT_H));
                    pButton->setMargin(VCP_SEGMENT_BTN_CONTENT_MARGIN, 0, VCP_SEGMENT_BTN_CONTENT_MARGIN, 0);
                }
                else
                {
		    pButton->setBgImageList(VcpStateImage(VCP_IMG_SEGMENT_BUTTON_MIDDLE_N, VCP_IMG_SEGMENT_BUTTON_MIDDLE_P, VCP_IMG_SEGMENT_BUTTON_MIDDLE_D, VCP_IMG_SEGMENT_BUTTON_MIDDLE_H));
                    pButton->setMargin(VCP_SEGMENT_BTN_CONTENT_MARGIN, 0, VCP_SEGMENT_BTN_CONTENT_MARGIN, 0);
                }
            }
        }
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgU", SA_stop); 
#endif
	
}

void VcpSegmentButton::addButton2(VfxId id, const VcpStateImage &imageList, VfxResId resId, VfxId beforeId)
{
    addButton(id, imageList, VFX_WSTR_RES(resId), beforeId);

}

void VcpSegmentButton::addButton2(VfxId id, const VcpStateImage &imageList, const VfxWChar *mem, VfxId beforeId)
{
    addButton(id, imageList, VFX_WSTR_MEM(mem), beforeId);
}

void VcpSegmentButton::addButton(VfxId id, const VcpStateImage &imageList, const VfxWString &text, VfxId beforeId)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgA", SA_start); 
#endif
    VcpButton *button;

    VFX_OBJ_CREATE(button, VcpButton, this);

    button->setId(id);
    button->setImage(imageList);
    button->setText(text);
	button->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_fontSize), VFX_FE1_4));
    button->setTextColor(VCP_SEG_BTN_TEXT_COLOR_NORMAL, VCP_SEG_BTN_TEXT_COLOR_NORMAL, VCP_SEG_BTN_TEXT_COLOR_NORMAL, VCP_SEG_BTN_TEXT_COLOR_PRESSED);
    button->m_signalClicked.connect(this, &VcpSegmentButton::onButtonClicked);

    VfxBool isEnd = VFX_TRUE;
    if (beforeId != INVALID_BUTTON_ID)
    {
        for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
        {
            VcpButton *pButton = (VcpButton *)i->get();

            if (pButton->getId() == beforeId)
            {   // insert item before beforeId
                m_list.insertBefore(i, button);
                isEnd = VFX_FALSE;
            }
        }
    }

    if (isEnd)
    {   // add item to the end
        m_list.append(button);
    }

    m_count ++;

    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgA", SA_stop); 
#endif
	
}


void VcpSegmentButton::removeButton (VfxId id)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgR", SA_start); 
#endif
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {   // insert item before beforeId
            m_list.removeOne(pButton);
            VFX_OBJ_CLOSE(pButton);
            m_count --;
            break;
        }
    }

    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SgR", SA_stop); 
#endif	
}

void VcpSegmentButton::removeAllButtons ()
{
    VfxObjListEntry *j;
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = j)
    {
        j = i->getValidNext();          
        VcpButton *pButton = (VcpButton *)i->get();    
        m_list.removeOne(pButton);
        VFX_OBJ_CLOSE(pButton);
        m_count--;
    }  
    checkUpdate();

}

void VcpSegmentButton::setButtonIsDisabled (VfxId id, VfxBool isDisabled)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            pButton->setIsDisabled(isDisabled);
        }
    }
    checkUpdate();
}


VfxBool VcpSegmentButton::getButtonIsDisabled (VfxId id) const
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            return pButton->getIsDisabled();
        }
    }

    return VFX_FALSE;
}


void VcpSegmentButton::setButtonIsHighlighted(VfxId id, VfxBool isHighlighted)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            pButton->setIsHighlighted(isHighlighted);
        }
        else if(isHighlighted == VFX_TRUE)
        {
            // reset other buttons
            if (m_type == VCP_SEGMENT_BUTTON_TYPE_RADIO)
            {
                pButton->setIsHighlighted(VFX_FALSE);
            }
        }
    }
    checkUpdate();
}


VfxBool VcpSegmentButton::getButtonIsHighlighted (VfxId id) const
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            return pButton->getIsHighlighted();
        }
    }
    return VFX_FALSE;
}

void VcpSegmentButton::setButtonImage(VfxId id, const VcpStateImage &imageList)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpButton *pButton = (VcpButton *)i->get();

        if (pButton->getId() == id)
        {
            pButton->setImage(imageList);
        }
    }

}


void VcpSegmentButton::onButtonClicked (VfxObject* sender, VfxId Id)
{

#if defined(__MMI_VUI_SHELL_CP__)
        // auto highlight for radio segment button
    if (m_type == VCP_SEGMENT_BUTTON_TYPE_RADIO)
    {
        setButtonIsHighlighted(Id, VFX_TRUE);
    }
#else
    if(getButtonIsHighlighted(Id) && m_type == VCP_SEGMENT_BUTTON_TYPE_RADIO)
    {
        return;
    }
    setButtonIsHighlighted(Id, !(((VcpButton*)sender)->getIsHighlighted()));
#endif
    m_signalButtonClicked.postEmit(this, Id);
}


void VcpSegmentButton::setFontSize(VfxS32 fontsize)
{
    m_fontSize = fontsize;
    checkUpdate();
}

