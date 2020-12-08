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
 *  vapp_search_widget_base_class.cpp
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

#include "MMI_features.h" 

#if defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined (__MMI_VUI_WIDGET_GOOGLE__)

#include "vapp_widget_def.h" 
#include "vcp_include.h"
#include "vapp_search_widget_base_class.h"

extern "C"
{
#include "AppMgrSrvGprot.h"
#include "Browser_api.h"
}



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
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_VIRTUAL_CLASS("VappWidgetSearchEditor", VappWidgetSearchEditor, VappWidget);


VappWidgetSearchEditor::VappWidgetSearchEditor():
	m_button(NULL),
	m_icon(NULL),
	m_text(NULL)
{
	// Do nothing.
}

void VappWidgetSearchEditor::onCreateView()
{
	VappWidget::onCreateView();
	setBounds(VfxRect(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT));
	
	VFX_OBJ_CREATE(m_button, VcpImageButton, this);
	m_button->setBounds(VfxRect(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT));
	m_button->setAnchor(0.5, 0.5);
	m_button->setPos(IMAGE_WIDTH/2, IMAGE_HEIGHT/2);
	m_button->m_signalClicked.connect(this, &VappWidgetSearchEditor::onWidgetClick);

	VFX_OBJ_CREATE(m_text, VfxTextFrame, m_button);
	m_text->setBounds(VfxRect(HINT_POS_X , HINT_POS_Y ,TEXT_WIDTH, TEXT_HEIGHT));
	m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_text->setAutoFontSize(VFX_TRUE);
	m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(HINT_SIZE)));
	m_text->setColor(VFX_COLOR_GREY);
	m_text->setPos(HINT_POS_X, HINT_POS_Y);
	m_text->setIsUnhittable(VFX_TRUE);
	
}

void VappWidgetSearchEditor::onReleaseView()
{
	VFX_OBJ_CLOSE(m_button);
	VFX_OBJ_CLOSE(m_icon);
	VappWidget::onReleaseView();
}

void VappWidgetSearchEditor::onCreate2ndIcon(VfxBool setIcon)
{
	if(setIcon)
	{
		m_button->setBounds(VfxRect(0, 0, IMAGE1_WIDTH, IMAGE1_HEIGHT));
		m_button->setAnchor(0.0, 0.0);
		m_button->setPos(0, 0);		

		VFX_OBJ_CREATE(m_icon, VcpImageButton, this);
		m_icon->setBounds(VfxRect(IMAGE1_WIDTH + IMAGE2_GAP, 0, IMAGE2_WIDTH, IMAGE2_HEIGHT));
		m_icon->setPos(IMAGE1_WIDTH + IMAGE2_GAP, 0);
		m_icon->m_signalClicked.connect(this, &VappWidgetSearchEditor::onWidgetIconClick);

		VFX_OBJ_CREATE(m_icon2, VcpImageButton, m_icon);
		m_icon2->setBounds(VfxRect(0, 0, GPLUS_SIZE, GPLUS_SIZE + IMAGE2_GAP));
		m_icon2->setPos(IMAGE1_WIDTH + IMAGE2_GAP + GPLUS_GAP, GPLUS_GAP);
		m_icon2->m_signalClicked.connect(this, &VappWidgetSearchEditor::onWidgetIconClick);
		m_text->setBounds(VfxRect(HINT_POS_X, HINT_POS_Y,TEXT1_WIDTH, TEXT_HEIGHT));
	}
}

void VappWidgetSearchEditor::setOnWidgetIconClick()
{
    // Be called only when G+ exists. So this func can't be set as a pure virtual func.
}
void VappWidgetSearchEditor::setWidgetImage(VfxResId resId)
{
	m_button->setImage(VcpStateImage(resId));
	m_button->setIsStretchMode(VFX_TRUE);
}

void VappWidgetSearchEditor::setWidgetImage(VcpStateImage imagelist)
{
	m_button->setImage(imagelist);
	m_button->setIsStretchMode(VFX_TRUE);
}

void VappWidgetSearchEditor::setWidgetIconImage(VfxResId resId)
{
	m_icon->setImage(VcpStateImage(resId));
	m_icon->setIsStretchMode(VFX_TRUE);
}

void VappWidgetSearchEditor::setWidgetIconImage(VcpStateImage imagelist)
{
	m_icon->setImage(imagelist);
	m_icon->setIsStretchMode(VFX_TRUE);
}

void VappWidgetSearchEditor::setWidgetIcon2Image(VcpStateImage imagelist)
{
	m_icon2->setImage(imagelist);
	m_icon2->setIsStretchMode(VFX_TRUE);
}

void VappWidgetSearchEditor::setWidgetHint(VfxResId resId)
{
	m_text->setString(VFX_WSTR_RES(resId));
}

void VappWidgetSearchEditor::onWidgetClick(VfxObject *obj, VfxId id)
{
	setOnWidgetClick();
}

void VappWidgetSearchEditor::onWidgetIconClick(VfxObject *obj, VfxId id)
{
	setOnWidgetIconClick();
}

VfxPoint VappWidgetSearchEditor::onGetEditButtonOffset()
{
	return VfxPoint(IMAGE_WIDTH - OFFSET_X, OFFSET_Y);
}

#endif /* defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined (__MMI_VUI_WIDGET_GOOGLE__) */
