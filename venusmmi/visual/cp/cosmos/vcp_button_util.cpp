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
 *  vcp_button_util.cpp
 *
 * Project:
 * --------
 *  Button Utility for Venus UI
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vcp_button_util.h"
#include "vcp_button.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "vcp_state_image.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"
#include "mmi_rp_app_cosmos_global_def.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

#define VCP_IMG_BUTTON_COMBO_N VCP_IMG_BUTTON_CHILD_BKG_N
#define VCP_IMG_BUTTON_COMBO_P VCP_IMG_BUTTON_CHILD_BKG_P
#define VCP_IMG_BUTTON_COMBO_D VCP_IMG_BUTTON_CHILD_BKG_D
#define VCP_IMG_BUTTON_COMBO_H VCP_IMG_BUTTON_CHILD_BKG_N

#define VCP_FORM_HINT_TEXT_COLOR            VFX_COLOR_RES(VCP_COL_FORM_HINT_TEXT)
#define TEXT_SEPARATION_GAP 5

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_COMBO_BTN_CHILD_WIDTH 47
#define VCP_ARROW_BTN_HINT_FONT 14
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_COMBO_BTN_CHILD_WIDTH 73
#define VCP_ARROW_BTN_HINT_FONT 22
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_COMBO_BTN_CHILD_WIDTH 40
#define VCP_ARROW_BTN_HINT_FONT 13
#else
#define VCP_COMBO_BTN_CHILD_WIDTH 47
#define VCP_ARROW_BTN_HINT_FONT 14
#endif

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
 * Global Variable
 *****************************************************************************/


/*****************************************************************************
 * Class VcpArrowButton
 *****************************************************************************/
VcpArrowButton::VcpArrowButton():
m_hintFrame(NULL)
{}

void VcpArrowButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("ArI", SA_start); 
#endif
    VcpButton::onInit();

    setPlacement(VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT);
    setImage(VcpStateImage(VCP_IMG_BUTTON_ARROW_WHITE) );

    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("ArI", SA_stop); 
#endif	
}

void VcpArrowButton::setHintText(VfxResId resId)
{    
    setHintText(VFX_WSTR_RES(resId));
}

void VcpArrowButton::setHintText(const VfxWChar *mem)
{    
    setHintText(VFX_WSTR_MEM(mem));
}

void VcpArrowButton::setHintText(const VfxWString &text)
{    
    if(text.isEmpty() || text.isNull())
    {
        if(m_hintFrame)
        {
            VFX_OBJ_CLOSE(m_hintFrame);
        }
        return;
    }

    if(!m_hintFrame)
    {
        VFX_OBJ_CREATE(m_hintFrame, VfxTextFrame, this);
        m_hintFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        m_hintFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));    
        m_hintFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_ARROW_BTN_HINT_FONT)));
        m_hintFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_hintFrame->setIsUnhittable(VFX_TRUE);
        m_hintFrame->setAnchor(1.0, 0.5);

    }
    m_hintFrame->setString(text);

    m_hintFrame->setAutoResized(VFX_TRUE);
    m_hintFrame->forceUpdate();
    m_hintFrame->setAutoResized(VFX_FALSE);
}
 
VfxWString VcpArrowButton::getHintText() const
{
    return m_hintFrame->getString();
}

void VcpArrowButton::onUpdate()
{
    VcpButton::onUpdate();

    if(m_hintFrame)
    {
            m_hintFrame->setPos(getButtonImageFrame()->getPos().x - getButtonImageFrame()->getBounds().size.width -  TEXT_SEPARATION_GAP, getInnerRect().size.height / 2 );
        
            m_hintFrame->setSize(m_hintFrame->getPos().x/3, m_hintFrame->getSize().height);
            m_hintFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_NONE);

            // Resize main text frame.
            VfxS32 left, top, right, bottom;
            getMargin(left, top, right, bottom);
            VfxTextFrame *mainText = getButtonTextFrame();
            mainText->setSize( m_hintFrame->getPos().x - (mainText->getPos().x + m_hintFrame->getSize().width + TEXT_SEPARATION_GAP), mainText->getSize().height);
    }


}



/*****************************************************************************
 * Class VcpAddButton
 *****************************************************************************/

void VcpAddButton::setText(VfxResId resId)
{
    setText(VFX_WSTR_RES(resId));
}

void VcpAddButton::setText(const VfxWChar *mem)
{
    setText(VFX_WSTR_MEM(mem));
}

void VcpAddButton::setText(const VfxWString &str)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("AdT", SA_start); 
#endif
    if (str.isEmpty() )
    {
        setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
        // set margin as square
        setMargin(m_defaultBoundary.origin.y, m_defaultBoundary.origin.y, 
                            m_defaultBoundary.size.height, m_defaultBoundary.size.height);
    }
    else
    {
        setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        getMargin(m_defaultBoundary.origin.x, m_defaultBoundary.origin.y, 
                            m_defaultBoundary.size.width, m_defaultBoundary.size.height);
    }
    VcpButton::setText(str);
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("AdT", SA_stop); 
#endif	
}

void VcpAddButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("AdI", SA_start); 
#endif
    VcpButton::onInit();

    setStyle(VCP_BUTTON_STYLE_DEFAULT_02);
    getMargin(m_defaultBoundary.origin.x, m_defaultBoundary.origin.y, 
                        m_defaultBoundary.size.width, m_defaultBoundary.size.height);
    // set margin as square
    setMargin(m_defaultBoundary.origin.y, m_defaultBoundary.origin.y, 
                        m_defaultBoundary.size.height, m_defaultBoundary.size.height);
    setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    setImage(VcpStateImage(VCP_IMG_BUTTON_PLUS));
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("AdI", SA_stop); 
#endif		
}

/*****************************************************************************
 * Class VcpSim1Button
 *****************************************************************************/

void VcpSim1Button::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("S1I", SA_start); 
#endif
    VcpButton::onInit();

    setStyle(VCP_BUTTON_STYLE_SIM1);
    setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("S1I", SA_stop); 
#endif	
}

/*****************************************************************************
 * Class VcpSim2Button
 *****************************************************************************/

void VcpSim2Button::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("S2I", SA_start); 
#endif
    VcpButton::onInit();

    setStyle(VCP_BUTTON_STYLE_SIM2);
    setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("S2I", SA_stop); 
#endif	
}

/*****************************************************************************
 * Class VcpCancelButton
 *****************************************************************************/

void VcpCancelButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("CnI", SA_start); 
#endif

    VcpButton::onInit();

    VfxRect defaultBoundary;
    getMargin(defaultBoundary.origin.x, defaultBoundary.origin.y, 
                        defaultBoundary.size.width, defaultBoundary.size.height);
    // set margin as square
    setMargin(defaultBoundary.origin.y, defaultBoundary.origin.y, 
                        defaultBoundary.size.height, defaultBoundary.size.height);
    setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    setImage(VcpStateImage(VCP_IMG_BUTTON_DELETE));
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("CnI", SA_stop); 
#endif	
}

/*****************************************************************************
 * Class VcpComboButton
 *****************************************************************************/
VcpComboButton::VcpComboButton():
m_childBtn(NULL),
m_hintTextFrame(NULL),
m_hintText(VFX_WSTR_NULL),
m_isOnlyMainBtnDisabled(VFX_FALSE)
{
}

void VcpComboButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("CmI", SA_start); 
#endif
    VcpButton::onInit();    
    setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
    setHasChildBtn(VFX_TRUE);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("CmI", SA_stop); 
#endif	
}

void VcpComboButton::setHasChildBtn(VfxBool value, VfxId id)
{
    if(value == VFX_TRUE && !m_childBtn)
    {
            VFX_OBJ_CREATE(m_childBtn, VcpButton, this); 
            m_childBtn->setAnchor(1.0, 0);            
            m_childBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
            m_childBtn->setInnerRect(VfxRect(VfxPoint(getSize().width - VCP_COMBO_BTN_CHILD_WIDTH, 0), VfxSize(VCP_COMBO_BTN_CHILD_WIDTH, getInnerRect().size.height)));
            m_childBtn->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

            m_childBtn->setBgImageList(VcpStateImage(VCP_IMG_BUTTON_COMBO_N, VCP_IMG_BUTTON_COMBO_P, VCP_IMG_BUTTON_COMBO_D, VCP_IMG_BUTTON_COMBO_H));
            m_childBtn->setImage(m_childBtnIcon);

            m_childBtn->m_signalClicked.connect(this, &VcpComboButton::onChildBtnClick);
    }
    else if(value == VFX_FALSE && m_childBtn)
    {
            VFX_OBJ_CLOSE(m_childBtn);
    }
    if(m_childBtn)
    {
        m_childBtn->setId(id);
    }
}

void VcpComboButton::onChildBtnClick(VfxObject *btn, VfxId id)
{
    VFX_ASSERT(m_childBtn);
    m_signalChildBtnClicked.emit(this, m_childBtn->getId());
}

void VcpComboButton::setChildButtonIcon(const VcpStateImage &icon)
{    
    m_childBtnIcon = icon;
    if(m_childBtn)
    {
        m_childBtn->setImage(icon);
    }
}

const VcpStateImage &VcpComboButton::getChildButtonIcon() const
{
    return m_childBtnIcon;
}


VfxBool VcpComboButton::onPenInput(VfxPenEvent &event)
{
    if(getIsOnlyMainBtnDisabled())
    {
        return VFX_FALSE;
    }
    return VcpButton::onPenInput(event);    
}

void VcpComboButton::updateItem()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("CmU", SA_start); 
#endif
    VcpButton::updateItem();
    if(getIsOnlyMainBtnDisabled())
    {
        VfxImageSrc image;
        image = m_iconImageList.getImageDisabled();
        m_frameImage->setOpacity(0.6f);
        m_frameText->setOpacity(0.6f);

        // set image
        if (!m_frameImage->getHidden() )
        {
            m_sizeImage = image.getSize();
            m_frameImage->setSize(m_sizeImage);
            m_frameImage->setImgContent(image);
        }
    }
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("CmU", SA_stop); 
#endif	
}

void VcpComboButton::layoutButton()
{
    VcpButton::layoutButton();
    if(m_childBtn)
    {
    if(m_placement == VCP_BUTTON_PLACEMENT_IMAGE_TEXT_CENTER)
    {
        VfxS32 shift = 0;
        // get size information
        VfxRect clientRect = getClientArea();
        
        VfxSize sizeText = m_sizeText;
        
        VfxS32 left, top, right, bottom ;
        getMargin(left, top, right, bottom);

        VfxS32 margin = (clientRect.size.width + (right - left) - VCP_COMBO_BTN_CHILD_WIDTH - sizeText.width - 
        m_frameImage->getSize().width - m_textImageGap) / 2;
        if (margin < 0)
        {
            margin = 0;
        }
        // set icon position
        m_frameImage->setAnchor(VfxFPoint(0.0, 0.5) );
        m_frameImage->setPos(VfxPoint(clientRect.getMinX() + margin, clientRect.getMidY() ) );

        shift = m_sizeImage.width + getTextImageGap();

        // set label position
        m_frameText->setAnchor(VfxFPoint(0.0, 0.5) );
        m_frameText->setPos(VfxPoint(clientRect.getMinX() + margin + shift, clientRect.getMidY() ) );
        }
    }
}

void VcpComboButton::setIsOnlyMainBtnDisabled(VfxBool state)
{
    m_isOnlyMainBtnDisabled = state;
    checkUpdate();
}

VfxBool VcpComboButton::getIsOnlyMainBtnDisabled() const
{
    return m_isOnlyMainBtnDisabled;
}

void VcpComboButton::setHintText(VfxResId resId)
{
    setHintText(VFX_WSTR_RES(resId));
}

void VcpComboButton::setHintText(const VfxWChar *mem)
{
    setHintText(VFX_WSTR_MEM(mem));
}

void VcpComboButton::setHintText(const VfxWString &hint)
{
    if(hint.isEmpty())
    {
        if(m_hintTextFrame)
        {
            VFX_OBJ_CLOSE(m_hintTextFrame);
        }
        return;
    }
    if(!m_hintTextFrame)
    {
        VFX_OBJ_CREATE(m_hintTextFrame, VfxTextFrame, this);
        m_hintTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_hintTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_hintTextFrame->setColor(VFX_COLOR_GREY);    
        m_hintTextFrame->setIsUnhittable(VFX_TRUE);        
        m_hintTextFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_frameText->getFont().size - 4)));    
    }
    VfxWString t = VFX_WSTR("(");
    t += hint;
    t += VFX_WSTR(")");
    m_hintTextFrame->setString(t);
    checkUpdate();
}


const VfxWString &VcpComboButton::getHintText()
{
    if(m_hintTextFrame)
    {
        return m_hintTextFrame->getString();
    }    
    return m_hintText;
}

void VcpComboButton::setIsDisabled (VfxBool isDisabled)
{
    VcpButton::setIsDisabled(isDisabled);
}

void VcpComboButton::setChildIsDisabled (VfxBool isDisabled)
{
    m_childBtn->setIsDisabled(isDisabled);
}
 
VfxBool VcpComboButton::getChildIsDisabled()
{
    return m_childBtn->getIsDisabled();
}

void VcpComboButton::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("Cmu", SA_start); 
#endif
    VcpButton::onUpdate();
    if(!m_hintTextFrame)
    {
        return;
    }
    m_hintTextFrame->setAnchor(0.0, m_frameText->getAnchor().y);
    VfxS32 x = m_frameText->getPos().x + m_frameText->getSize().width + 5;
    m_hintTextFrame->setPos(x, m_frameText->getPos().y);

    VfxS32 width = getSize().width - x;
    if(m_childBtn)
    {
        width -= m_childBtn->getSize().width;
    }  
    m_hintTextFrame->setSize(width, m_hintTextFrame->getSize().height);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("Cmu", SA_stop); 
#endif	
}

/*****************************************************************************
 * Global Functions
 *****************************************************************************/

VcpButton * vcpCreateArrowButton(VfxObject * parent)
{
    VcpButton * button;
    VFX_OBJ_CREATE(button, VcpButton, parent);

    button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT);
    button->setImage(VcpStateImage(VCP_IMG_BUTTON_ARROW_WHITE) );

    return button;
}

VcpButton * vcpCreateAddButton(VfxBool hasText, VfxObject * parent)
{
    VcpButton * button;
    VFX_OBJ_CREATE(button, VcpButton, parent);

    button->setStyle(VCP_BUTTON_STYLE_DEFAULT_02);
    button->setImage(VcpStateImage(VCP_IMG_BUTTON_PLUS) );

    if (!hasText)
    {
        button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);

        // set margin as square
        VfxRect defaultBoundary;
        button->getMargin(defaultBoundary.origin.x, defaultBoundary.origin.y, 
                            defaultBoundary.size.width, defaultBoundary.size.height);
        button->setMargin(defaultBoundary.origin.y, defaultBoundary.origin.y, 
                            defaultBoundary.size.height, defaultBoundary.size.height);
    }
    else
    {
        button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
    }

    return button;
}

VcpButton * vcpCreateCancelButton(VfxObject * parent)
{
    VcpButton * button;
    VFX_OBJ_CREATE(button, VcpButton, parent);

    // set margin as square
    VfxRect defaultBoundary;
    button->getMargin(defaultBoundary.origin.x, defaultBoundary.origin.y, 
                        defaultBoundary.size.width, defaultBoundary.size.height);
    button->setMargin(defaultBoundary.origin.y, defaultBoundary.origin.y, 
                        defaultBoundary.size.height, defaultBoundary.size.height);

    button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    button->setImage(VcpStateImage(VCP_IMG_BUTTON_DELETE));

    return button;
}
