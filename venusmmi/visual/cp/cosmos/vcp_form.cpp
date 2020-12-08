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
*  vcp_form.cpp
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  Form menu source file
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
#include "vcp_form.h"
#include "vfx_cpp_base.h"
#include "mmi_rp_srv_venus_component_form_def.h"

#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_scrollable.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
#include "vfx_frame_aligner.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vfx_string.h"
#include "vfx_object_list.h"
#include "vcp_button.h"
#include "vfx_font_desc.h"
#include "vcp_image_button.h"
#include "vcp_text_editor.h"
#include "vcp_text_view.h"
#include "vfx_control.h"
#include "vfx_text_frame.h"
#include "vfx_draw_context.h"

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "vcp_activity_indicator.h"
#include "vcp_button_util.h"
#include "vfx_keypad.h"
#include "vadp_sys_trc.h"

#include "string.h"
#include "vfx_system.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"
#include "vcp_switch.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 

/* SWLA tags:
------------
VcpForm::onInit                      FoI
VcpForm::insertItem                  FaI
VcpForm::removeItem                  FrI
VcpForm::onItemHeightChange          FhC
VcpForm::scrollItemToView            FsV

VcpFormLayouter::updatePositions     FuP

void VcpFormItemBase::onUpdate       FBU

VcpFormItemLabeledControl::onUpdate  FIL

VcpFormItemCell::onUpdate            FCU
VcpFormItemCell::setMainText         FCM
VcpFormItemCell::setHintText         FCH

VcpFormItemLauncherCell::onInit      FIC
VcpFormItemLauncherCell::onUpdate    FLU

VcpFormItemSwitchCell::onUpdate      FSU

VcpFormItemAidButtonCell::onUpdate   FAU

*/

#define VCP_FORM_MUST_STAY_FOCUSSED_TIME 100

/***************************************************************************** 
* Class VcpForm
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpForm", VcpForm, VcpScrollable);

VcpForm::VcpForm():
m_itemCount(0),
m_formWidth(0),
m_formHeight(0),
#if  defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING)
m_currentKeyFocusIndex(-1),
#endif /* defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) */
m_topShadow(NULL),
#if defined(VCP_FORM_STRETCHES_ON_SCROLL_END)
m_stretchingEffectIsEnabled(VFX_FALSE),
#endif
m_contentTopGap(VCPFRM_ITEM_HORZ_GAP_2),
m_isAnimEnabled(VFX_TRUE)
{}

void VcpForm::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FoI", SA_start); 
#endif
    VcpScrollable::onInit();    
    enableVerticalScrollIndicator(VFX_TRUE);
    m_signalBoundsChanged.connect((VfxFrame*)this, &VcpForm::onBoundsChange);
    setBgColor(VCP_FORM_BG_COLOR);

    setAutoAnimate(VFX_TRUE);
    setContentSize(VfxSize(m_formWidth, m_formHeight));

    setTopShadowIsHidden(VFX_FALSE);

#if defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) || defined(__MMI_VUI_COSMOS_CP__)
		VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this);
		VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_DOWN, this);
#endif

    m_layouter.attachMasterForm(this);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FoI", SA_stop); 
#endif
}

#if defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING)
VfxBool VcpForm::onKeyInput(VfxKeyEvent &event)
{
    if (event.type != VFX_KEY_EVENT_TYPE_UP)
    {
        return VFX_FALSE;
    }
    VcpFormItemBase *nextPossibleItem  = NULL;
    VfxS32 itr = m_currentKeyFocusIndex;
    switch (event.keyCode)
    {    
    case VFX_KEY_CODE_ARROW_DOWN:        
        {
            // route to next editor item
            nextPossibleItem = m_indexer.getItemAtIndex(++itr);
            for ( ;(nextPossibleItem) && !nextPossibleItem->canHandleKeyEvent();
                nextPossibleItem = m_indexer.getItemAtIndex(++itr));       
        }
        break;
    case VFX_KEY_CODE_ARROW_UP:     
        {
            // Route to previous editor item
            nextPossibleItem = m_indexer.getItemAtIndex(--itr);
            for ( ;(nextPossibleItem) && !nextPossibleItem->canHandleKeyEvent();
                nextPossibleItem = m_indexer.getItemAtIndex(--itr));       
        }
        break;
    default:
        return VFX_FALSE;        
    }
    if(nextPossibleItem)
    {
        nextPossibleItem->setFocused(VFX_TRUE);
        m_currentKeyFocusIndex = itr;
    }                   

	return VFX_TRUE;
}
#elif defined(__MMI_VUI_COSMOS_CP__)
VfxBool VcpForm::onKeyInput(VfxKeyEvent &event)
{
    if (event.type != VFX_KEY_EVENT_TYPE_DOWN && event.type != VFX_KEY_EVENT_TYPE_REPEAT)
    {
        return VFX_FALSE;
    }
    VfxS32 contentHeight = getContentSize().height;
    VfxS32 viewOrigin = getViewBounds().origin.y;
    VfxS32 viewHeight = getSize().height;

    VfxS32 itr = 0;
    VcpFormItemBase *item  = m_indexer.getItemAtIndex(itr);
    VfxS32 startPoint = viewOrigin;
    VfxS32 endPoint = (viewOrigin + viewHeight);

    switch (event.keyCode)
    {    
    case VFX_KEY_CODE_ARROW_DOWN:        
            for( ; (item); item = m_indexer.getItemAtIndex(++itr))
            {
                if(item->getPos().y + item->getSize().height > endPoint )
                {
                    if(item->getPos().y <= endPoint)
                    {
                        if(item->getPos().y <= startPoint)
                        {
                            setContentOffset(VfxPoint(item->getPos().x, viewOrigin + (viewHeight>>1)), VFX_TRUE);
                            adjustContentOffsetPosition(contentHeight, viewOrigin + (viewHeight>>1), viewHeight);
                        }
                        else
                        {
                            scrollItemToView(item, VCPFORM_SCROLL_TOP, VFX_TRUE);
                        }
                        break;
                    }                 
                }
            }
            break;
    case VFX_KEY_CODE_ARROW_UP:     
            for( ; (item); item = m_indexer.getItemAtIndex(++itr))
            {
                if(item->getPos().y + item->getSize().height >= startPoint )
                {  
                    if(item->getPos().y <= startPoint)
                    {
                        if(item->getPos().y + item->getSize().height >= endPoint )
                        {
                            setContentOffset(VfxPoint(item->getPos().x, viewOrigin - (viewHeight>>1)), VFX_TRUE);
                            adjustContentOffsetPosition(contentHeight, viewOrigin - (viewHeight>>1), viewHeight);
                        }
                        else
                        {
                            scrollItemToView(item, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
                        }
                        break;
                    }                 
                }
            }
            break;
    default:
        return VFX_FALSE;      
    }
    return VFX_TRUE;
}
#endif 


void VcpForm::onUpdate()
{
	adjustContentOffsetPosition();
	VcpScrollable::onUpdate();	
}

void VcpForm::onBoundsChange(VfxFrame *frm, const VfxRect &rect)
{
    m_formWidth = frm->getSize().width;
    setContentSize(VfxSize(m_formWidth, m_formHeight)); 
    if(m_topShadow)
    {
    m_topShadow->setSize(getSize().width, 50);
    }
	
    VFX_LOG(VFX_INFO2, VCP_FORM_CHANGE_VIEW_BOUNDS, m_formWidth, frm->getSize().height); 		
	
    adjustContentOffsetPosition(); 
    checkUpdate();
}

void VcpForm::adjustContentOffsetPosition()
{
    VfxS32 contentHeight = getContentSize().height;
    VfxS32 viewOrigin = m_view->getBounds().origin.y;
    VfxS32 viewHeight = getSize().height;

    adjustContentOffsetPosition(contentHeight, viewOrigin, viewHeight);
}

void VcpForm::adjustContentOffsetPosition(VfxS32 contentHeight, VfxS32 viewOrigin, VfxS32 viewHeight)
{
	VFX_LOG(VFX_INFO2, VCP_FORM_ADJUST_VIEW, contentHeight, viewOrigin, viewHeight);

    if(viewHeight + viewOrigin > contentHeight)
    {
        if(contentHeight < viewHeight)
        {
            setContentOffset(VfxPoint(0, 0), VFX_TRUE);
			VFX_LOG(VFX_INFO2, VCP_FORM_ADJUST_VIEW_TO, 0);			
        }
        else
        {
            setContentOffset(VfxPoint(0, contentHeight - viewHeight), VFX_TRUE);
			VFX_LOG(VFX_INFO2, VCP_FORM_ADJUST_VIEW_TO, contentHeight - viewHeight);
        }
    }
    else if(viewOrigin < 0)
    {
        setContentOffset(VfxPoint(0, 0), VFX_TRUE);
		VFX_LOG(VFX_INFO2, VCP_FORM_ADJUST_VIEW_TO, 0);					
    }
}

#if defined(VCP_FORM_STRETCHES_ON_SCROLL_END)
VfxBool VcpForm::onPreviewPenInput(VfxPenEvent &event)
{
    if(!m_stretchingEffectIsEnabled)
    {
        return VFX_FALSE;
    }
    VfxPoint pos(event.getRelPos(this));
    static VfxS32 oldPosY;
    VfxS32 newPosY = pos.y;
    VfxRect rect = getViewBounds();
    if(m_formHeight  <= rect.size.height)
    {
        return VFX_FALSE;
    }

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        m_layouter.m_scrollState = VCPFRM_STATE_DRAGGING;
        m_layouter.m_scrollVelocity = 0;
        break;
    case VFX_PEN_EVENT_TYPE_MOVE:
        m_layouter.m_scrollVelocity = newPosY - oldPosY;
        if(m_layouter.m_scrollState == VCPFRM_STATE_DRAGGING)
        {
            if(rect.origin.y == 0 && m_layouter.m_scrollVelocity > 0)
            {
                m_layouter.m_scrollState = VCPFRM_STATE_TOP_STRETCHING;
                m_layouter.m_stretchStartPosY = newPosY;
                setBgColor(VCP_FORM_HIDDEN_BG_COLOR);
            }
            else if(rect.origin.y + rect.size.height >= m_formHeight  && m_layouter.m_scrollVelocity < 0)
            {
                m_layouter.m_scrollState = VCPFRM_STATE_BOTTOM_STRETCHING;               
                m_layouter.m_stretchStartPosY = newPosY;
                setBgColor(VCP_FORM_HIDDEN_BG_COLOR);
            }
        }
        break;
    case VFX_PEN_EVENT_TYPE_UP:        
    case VFX_PEN_EVENT_TYPE_ABORT:     
        m_layouter.m_scrollVelocity = newPosY - oldPosY;
        if(m_layouter.m_scrollState == VCPFRM_STATE_TOP_STRETCHING)
        {
            m_layouter.m_scrollState = VCPFRM_STATE_TOP_RECOILING;
        }
        else if(m_layouter.m_scrollState == VCPFRM_STATE_BOTTOM_STRETCHING)
        {
             m_layouter.m_scrollState  = VCPFRM_STATE_BOTTOM_RECOILING;
        }
        else
        {
            m_layouter.m_scrollState = VCPFRM_STATE_GLIDING;
            setBgColor(VCP_FORM_BG_COLOR);
        }
        break;
    default:
        break;
    }
    oldPosY = newPosY;

    if(m_layouter.m_scrollState == VCPFRM_STATE_TOP_STRETCHING ||
        m_layouter.m_scrollState == VCPFRM_STATE_BOTTOM_STRETCHING ||
         m_layouter.m_scrollState == VCPFRM_STATE_TOP_RECOILING ||
          m_layouter.m_scrollState == VCPFRM_STATE_BOTTOM_RECOILING)
    {
        m_layouter.executeStretchingEffect(newPosY, m_indexer);
        
        if (m_layouter.m_scrollState == VCPFRM_STATE_BOTTOM_RECOILING)
        {
            setContentOffset(VfxPoint(0, m_formHeight - rect.size.height));
        }

    }
    return VFX_FALSE;
}
#endif

void VcpForm::addItem(VcpFormItemBase *item, VfxId itemId)
{    
    insertItem(item, VCPFRM_ITEMID_INVALID, itemId);    
}

void VcpForm::addItemFromXML(VcpFormItemBase *item)
{
    addItem(item);
}

void VcpForm::insertItem(VcpFormItemBase *item, VfxId ReferenceId , VfxId itemId, VfxBool addBeforeRefId)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FaI", SA_start); 
#endif
	VFX_LOG(VFX_INFO2, VCP_FORM_INSERT_ITEM_CALLED, itemId, ReferenceId, addBeforeRefId);
    m_view->addChildFrame(item);
    if(VCPFRM_ITEMID_INVALID == item->getId() )
    {
        item->setId(itemId);
    }
    item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);

    m_indexer.insert(itemId, item, this, ReferenceId, addBeforeRefId);	
    
    m_itemCount++;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);   
    VfxAutoAnimate::setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_formHeight = m_layouter.updatePositions(itemId, m_indexer);
    VfxAutoAnimate::commit();

   m_signalBoundsChanged.connect(item, &VcpFormItemBase::onFormBoundsChanged);

    setContentSize(VfxSize(m_formWidth, m_formHeight)); 
    item->m_signalHeightChange.connect(this, &VcpForm::onItemHeightChange);
    checkUpdate();

	VFX_LOG(VFX_INFO2, VCP_FORM_INSERT_ITEM_ENDS, itemId, m_itemCount, m_formHeight);	
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FaI", SA_stop); 
#endif
}

void VcpForm::removeItem(VfxId itemId)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FrI", SA_start); 
#endif
	VFX_LOG(VFX_INFO2, VCP_FORM_REMOVE_ITEM_CALLED, itemId);
    VfxId nextId = m_indexer.getNextId(itemId);
    VcpFormItemBase *item = m_indexer.get(itemId);
    VFX_OBJ_CLOSE(item);
    m_indexer.remove(itemId);
    m_itemCount--;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);   
    VfxAutoAnimate::setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_formHeight = m_layouter.updatePositions(nextId, m_indexer);
    VfxAutoAnimate::commit();

    setContentSize(VfxSize(m_formWidth, m_formHeight));
    checkUpdate();

	VFX_LOG(VFX_INFO2, VCP_FORM_REMOVE_ITEM_ENDS, itemId, m_itemCount, m_formHeight);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FrI", SA_stop); 
#endif
	
}


VcpFormItemBase *VcpForm::getItem(VfxId id)
{
    return m_indexer.get(id);
}

void VcpForm::onItemHeightChange(VfxId id)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FhC", SA_start); 
#endif
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);   
    VfxAutoAnimate::setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_formHeight = m_layouter.updatePositions(id, m_indexer);
    setContentSize(VfxSize(m_formWidth, m_formHeight));

	VFX_LOG(VFX_INFO2, VCP_FORM_ON_ITEM_HEIGHT_CHNG, id, m_formHeight);    

    checkUpdate();
    VfxAutoAnimate::commit();    
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FhC", SA_stop); 
#endif	
}


void VcpForm::insertSeparator(VfxId afterId)
{          
    VcpFormItemBase *item = NULL;
    if(afterId != VCPFRM_ITEMID_INVALID)
    {
      item = m_indexer.get(afterId);            
    }
    else
    {
       item = m_indexer.getLastItem();
    }
    VFX_ASSERT(item); // VFX_ASSERT if no item is found with 'afterId'
    insertSeparator(item);
}

void VcpForm::insertSeparator(VcpFormItemBase *target)
{
    target->setHasSeparator(VFX_TRUE);
}

void VcpForm::removeSeparator(VfxId afterId)
{          
    VcpFormItemBase *item = NULL;
    if(afterId != VCPFRM_ITEMID_INVALID)
    {
        item = m_indexer.get(afterId);            
    }
    else
    {
        item = m_indexer.getLastItem();
    }
    VFX_ASSERT(item); // VFX_ASSERT if no item is found with 'afterId'
    removeSeparator(item);
}

void VcpForm::removeSeparator(VcpFormItemBase *target)
{
    target->setHasSeparator(VFX_FALSE);
}

/* vaib mem reduction */
void VcpForm::addCaption(VfxResId text_id, VfxId id)
{
	addCaption(VFX_WSTR_RES(text_id),id);
}

/* vaib mem reduction */
void VcpForm::addCaption(const VfxWChar* text_buf, VfxId id)
{
	addCaption(VFX_WSTR_MEM(text_buf),id);
}

void VcpForm::addCaption(VfxWString text, VfxId id)
{
    VcpFormItemCaption *capItem;
    VFX_OBJ_CREATE(capItem,  VcpFormItemCaption, this);
    capItem->setText(text);
    addItem(capItem, id);
}

void VcpForm::scrollItemToView(VcpFormItemBase *item, VcpFormScrollViewPosition pos, VfxBool isAnim)
{
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FsV", SA_start); 
#endif
    if(getSize().height >= m_formHeight)
    {
        return; // Content too short for any scrolling
    }

    VfxS32 item_y = item->getPos().y;
    VfxS32 item_height =  item->getSize().height;
    VfxS32 formHeight = getSize().height;
	VFX_LOG(VFX_INFO2, VCP_FORM_SCROLL_TO_VIEW_REQ, item->getId(), pos, item_y, item_height, formHeight );

    VfxS32 finalYOffset = 0;
    switch(pos)
    {
    case VCPFORM_SCROLL_TOP:
        finalYOffset = item_y < m_formHeight - formHeight ? item_y : m_formHeight - formHeight;
        break;
    case VCPFORM_SCROLL_BOTTOM:
        finalYOffset = item_y + item_height < formHeight ? 0 : item_y - (formHeight - item_height);
        break;
    case VCPFORM_SCROLL_CENTER:
        finalYOffset = item_y + (item_height/2) < formHeight/2 ? 0 : item_y - (formHeight - item_height)/2;
        finalYOffset = item_y + (item_height/2) < m_formHeight - (formHeight/2) ? finalYOffset : m_formHeight - formHeight;
        break;
    default:
        return;				
    }
    setContentOffset(VfxPoint(item->getPos().x, finalYOffset), isAnim);
	VFX_LOG(VFX_INFO2, VCP_FORM_SCROLL_TO_VIEW_ENDS, item->getId(), finalYOffset);
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("FsV", SA_stop); 
#endif	
}

void VcpForm::scrollItemToView(VfxId id, VcpFormScrollViewPosition pos, VfxBool isAnim)
{
    VcpFormItemBase *item = getItem(id);
    scrollItemToView(item, pos, isAnim);
}

void VcpForm::setContentTopGap(VfxS32 gap)
{
    m_contentTopGap = gap;
}


void VcpForm::setIsAnimWaitEnabled(VfxBool state)
{
}

void VcpForm::setIsAnimEnabled(VfxBool state)
{
    m_isAnimEnabled = state;  
    
    VcpFormItemBase *curItem;
    VfxObjListEntry *i = m_indexer.m_mappingList.getValidHead() ;
    for ( ; i != NULL; i = i->getValidNext())
    {
       curItem = ((VcpFormIndexer::VcpFormItemdata *)i->get())->item;
       curItem->setAutoAnimate(state);
    }    
}

VfxBool VcpForm::getIsAnimWaitEnabled() const
{
    return VFX_FALSE;
}

VfxBool VcpForm::getIsAnimEnabled() const
{
    return m_isAnimEnabled;
}

    
void VcpForm::setTopShadowIsHidden(VfxBool state)
{
    if(VFX_TRUE == state)
    {
        if(m_topShadow)
        {
            VFX_OBJ_CLOSE(m_topShadow);
        }
    }
    else
    {
        if(!m_topShadow)
        {
            VFX_OBJ_CREATE(m_topShadow, VfxFrame, this);
            m_topShadow->setPos(0,0);
            m_topShadow->setImgContent(VfxImageSrc(VCP_IMG_TOP_SHADOW));
            m_topShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);	
        }
    }
}

VfxBool VcpForm::getTopShadowIsHidden() const
{
    return !(VfxBool(m_topShadow));
}

/***************************************************************************** 
* Class VcpFormIndexer
*****************************************************************************/
VcpFormIndexer::VcpFormIndexer():
m_count(0)
{}

VfxBool VcpFormIndexer::insert(VfxId id, VcpFormItemBase *frame, VfxObject *parent, VfxId refId, VfxBool addBeforeRefId)
{
    VcpFormItemdata  *newEntry;            
    VFX_OBJ_CREATE(newEntry, VcpFormIndexer::VcpFormItemdata, parent);

    newEntry->itemId = id;
    newEntry->item = frame;
    if (refId == VCPFRM_ITEMID_INVALID)
    {
        m_mappingList.append(newEntry);    
        m_count++;
        return VFX_TRUE;    
    }
    for (VfxObjListEntry *i = m_mappingList.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        if( refId == ((VcpFormItemdata *)(i->get()))->itemId)
        {	
            if(addBeforeRefId)
        {    
            m_mappingList.insertBefore(i, newEntry);
            }
            else
            {
                m_mappingList.insertAfter(i, newEntry);
            }
            m_count++;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;        
}

VfxBool VcpFormIndexer::remove(VfxId id)
{
    for (VfxObjListEntry *i = m_mappingList.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpFormItemdata *itemData = (VcpFormItemdata*)(i->get());
        if( id == itemData->itemId)
        {    
            m_mappingList.removePos(i);
            VFX_OBJ_CLOSE(itemData);
            m_count--;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VcpFormItemBase *VcpFormIndexer::get(VfxId id)
{
    for (VfxObjListEntry *i = m_mappingList.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        if( id == ((VcpFormItemdata *)i->get())->itemId)
        {    
            return (VcpFormItemBase *)(((VcpFormItemdata *)(i->get()))->item);
        }
    }
    return NULL;
}

VcpFormItemBase *VcpFormIndexer::getLastItem()
{
    return (VcpFormItemBase *)
        (((VcpFormItemdata *)
        (m_mappingList.getValidTail()->get()))->item);
}

VfxId VcpFormIndexer::getNextId(VfxId id)
{
    for (VfxObjListEntry *i = m_mappingList.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        if( id == ((VcpFormItemdata *)i->get())->itemId)
        {    
            i = i->getValidNext();
            if(i)
            {
                return (VfxId)(((VcpFormItemdata *)(i->get()))->itemId);
            }
            else
            {
                break;
            }
        }
    }
    return VCPFRM_ITEMID_INVALID;
}

VcpFormItemBase *VcpFormIndexer::getItemAtIndex(VfxS32 index)
{
    VfxS32 ctr = 0;
    VfxObjListEntry *i = m_mappingList.getValidHead();
    while(i && ctr < index)
    {
        i = i->getValidNext();
        ctr++;        
    }
    if(index < 0)
    {
        return NULL;
    }    
    return (i) ? (((VcpFormItemdata *)i->get())->item) : NULL;
}

/***************************************************************************** 
* Class VcpFormLayouter
*****************************************************************************/
VcpFormLayouter::VcpFormLayouter():
m_itemHorzGap(0),
m_parentForm(NULL),
 m_scrollState(VCPFRM_STATE_DRAGGING),
    m_scrollVelocity(0),
    m_recoilTime(100),
    m_stretchStartPosY(0)
{
}

void VcpFormLayouter::attachMasterForm(VcpForm *parentForm)
{
    m_parentForm =  parentForm;
}
#if defined(VCP_FORM_STRETCHES_ON_SCROLL_END)
VfxS32 VcpFormLayouter::executeStretchingEffect(VfxS32 newPosY, VcpFormIndexer m_indexer)
{
    VfxS32 formHeight  = 0;
    VfxS32 maxItemGap  = 0;    

    VfxS32 ctr = 0;
    VfxS32 lastPos = 0;


    switch(m_scrollState)
    {
    case VCPFRM_STATE_TOP_STRETCHING:        
        maxItemGap  = newPosY - m_stretchStartPosY;
        break;
    case VCPFRM_STATE_BOTTOM_STRETCHING:
       maxItemGap  = m_stretchStartPosY - newPosY;        
        break;
   case VCPFRM_STATE_TOP_RECOILING:
     case VCPFRM_STATE_BOTTOM_RECOILING:
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);   
        VfxAutoAnimate::setDuration(m_recoilTime);

        m_parentForm->m_formHeight = updatePositions(VCPFRM_ITEMID_INVALID, m_indexer);
        m_parentForm->setContentSize(VfxSize(m_parentForm->m_formWidth, m_parentForm->m_formHeight));
        
        VfxAutoAnimate::commit();	

        return m_parentForm->m_formHeight;
    default:
        break;
 
    }
    if(maxItemGap <= 0) // when 
    {
        return m_parentForm->m_formHeight;
    }
        maxItemGap  = maxItemGap < 15 ? maxItemGap :15;
    VfxS32 currentStretchGap = 0;
    VfxObjListEntry *i = m_indexer.m_mappingList.getValidHead() ;
    VcpFormItemBase *curItem = ((VcpFormIndexer::VcpFormItemdata *)i->get())->item;
    VfxRect curViewBounds = m_parentForm->getViewBounds();
    formHeight = m_parentForm->m_formHeight;

    for ( ; i != NULL; i = i->getValidNext(), ctr++)
    {
        curItem = ((VcpFormIndexer::VcpFormItemdata *)i->get())->item;

        if(VCPFRM_STATE_TOP_STRETCHING == m_scrollState)
        {
            curItem->setPos(curItem->getPos().x, lastPos);
            if(ctr < 6)
            {
                lastPos +=  (maxItemGap  * 3 )/ (4 *(ctr+1));
            }
        }
        else if(VCPFRM_STATE_BOTTOM_STRETCHING == m_scrollState)
        {
            VfxS32 backCtr = m_indexer.getCount() - ctr;            
            if(backCtr < 6 && backCtr > 0)
            {
                currentStretchGap = (maxItemGap  *1 )/(2 * backCtr );
                lastPos += currentStretchGap;
                formHeight += currentStretchGap;
                curItem->setPos(curItem->getPos().x, lastPos);
            }
        }         
        lastPos +=  curItem->getSize().height;        
    }

    if(VCPFRM_STATE_BOTTOM_STRETCHING == m_scrollState)
    {
        m_parentForm->setContentOffset(VfxPoint(0, formHeight - curViewBounds.size.height));
        m_parentForm ->setContentSize(VfxSize(m_parentForm->getContentSize().width, formHeight ));
    }
    return lastPos;
}
#endif

VfxS32 VcpFormLayouter::updatePositions(VfxId itemId, VcpFormIndexer m_indexer)
{
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FuP", SA_start); 
#endif	
    VcpFormItemBase *prevItem = NULL;
    VcpFormItemBase *curItem = NULL;
    VfxObjListEntry *i = m_indexer.m_mappingList.getValidHead() ;
    if(i)
    {
        // Execute any special handling for the first (topmost) item.
        ((VcpFormIndexer::VcpFormItemdata *)(i->get()))->item->firstItemDependentChanges(m_parentForm); 
    }
    VfxS32 lastPos = m_parentForm->getContentTopGap();
    if(itemId != VCPFRM_ITEMID_INVALID)
    {
        for (  ; i != NULL ; i = i->getValidNext())
        {
            curItem = ((VcpFormIndexer::VcpFormItemdata *)i->get())->item;
            if( itemId == curItem->getId())
            {                    
                break;    
            }
            lastPos += ((VcpFormIndexer::VcpFormItemdata *)(i->get()))->item->getSize().height + m_itemHorzGap;
            prevItem = curItem;
        }
    }
    for ( ; i != NULL ; i = i->getValidNext())
    {
        curItem = ((VcpFormIndexer::VcpFormItemdata *)i->get())->item;
        curItem->setPos(curItem->getPos().x, lastPos);
        curItem->executePrevDependentBehavior(prevItem);
        lastPos +=  curItem->getSize().height + m_itemHorzGap;        
        prevItem = curItem;
    }
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("FuP", SA_stop); 
#endif		
    return lastPos;    
}

/***************************************************************************** 
* Class VcpFormItemBase
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemBase", VcpFormItemBase, VfxControl);

VcpFormItemBase::VcpFormItemBase():
m_id(VCPFRM_ITEMID_INVALID),
m_height(0),
m_pos(VfxPoint(0,0)),
m_isHidden(VFX_FALSE),
m_separator(NULL),
m_cover(NULL)
{
}
void VcpFormItemBase::onInit()
{
    VfxControl::onInit();
    setSize(getParentFrame()->getSize().width, m_height);
 
    setAutoAnimate(VFX_TRUE);
    setBgColor(VCP_FORM_ITEM_BG_COLOR);
    setIsZSortChild(VFX_TRUE);
}
void VcpFormItemBase::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    checkUpdate();
}

void VcpFormItemBase::setHeight(VfxS32 height)
{
	VFX_LOG(VFX_INFO2, VCP_FORM_ITEM_SET_HEIGHT, m_id, m_height, height);    

    m_height = height;
    onUpdate();
}

void VcpFormItemBase::setIsDisabled(VfxBool state)
{
    if(state == VFX_TRUE)
    {
        if(!m_cover)
        {
            VFX_OBJ_CREATE(m_cover, VcpFormDisableOverlayFrame, this);
            m_cover->setOpacity(0.5f);
            m_cover->setBgColor(VCP_FORM_DISABLED_OVERLAY_COLOR);
        }
        m_cover->setPos(0,0);
        m_cover->setSize(getSize());
        m_cover->bringToFront();
        m_cover->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        m_cover->setPosZ(-1);
    }
    else
    {
        if(m_cover)
        {
            VFX_OBJ_CLOSE(m_cover);
        }
        setBgColor(VCP_FORM_ITEM_BG_COLOR);
        setOpacity(1.0f);
    }
    VfxControl::setIsDisabled(state);
	VFX_LOG(VFX_INFO2, VCP_FORM_ITEM_DISABLED, m_id, state);    
}

void VcpFormItemBase::setIsHidden(VfxBool state)
{
    m_isHidden = state;
    checkUpdate();   
	VFX_LOG(VFX_INFO2, VCP_FORM_ITEM_HIDDEN, m_id, m_isHidden);    	
}


void VcpFormItemBase::setHasSeparator(VfxBool value)
{
    if(value == VFX_TRUE)
    {
        if(!m_separator)
        {
            VfxImageSrc sepImg = VfxImageSrc(VCP_IMG_FORM_SEP_LINE);
            VFX_OBJ_CREATE(m_separator, VfxFrame, this);
            m_separator->setAnchor(0,1.0f);
            m_separator->setPos(0, getSize().height);
            m_separator->setImgContent(sepImg);
            m_separator->setSize(getSize().width, sepImg.getSize().height);
            m_separator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

            m_separator->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_NONE, 
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
        }
    }
    else
    {
        if(m_separator)
        {
            VFX_OBJ_CLOSE(m_separator);
        }
    }
	VFX_LOG(VFX_INFO2, VCP_FORM_ITEM_HAS_SEPARATOR, m_id, value);    		
}

VfxBool VcpFormItemBase::getHasSeparator() const
{
    if(m_separator)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VcpFormItemBase::onUpdate()
{

#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FBU", SA_start); 
#endif	

	VfxS32 curr_height = getSize().height;
	
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);   
    VfxAutoAnimate::setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
	
    if(m_isHidden)
    {
        setSize(getParentFrame()->getSize().width, 0);       
    }
    else
    {
		setSize(getParentFrame()->getSize().width, getHeight());	   
    }
    
    VfxAutoAnimate::commit();    
    
	if(curr_height != getSize().height)
	{
		m_signalHeightChange.emit(m_id);
	}
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FBU", SA_stop); 
#endif
	
}

void VcpFormItemBase::firstItemDependentChanges(VcpForm *parent)
{
}

void VcpFormItemBase::executePrevDependentBehavior(VcpFormItemBase *prevItem)
{      
}

#if defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) 
VfxBool VcpFormItemBase::canHandleKeyEvent()
{
    return VFX_FALSE;
}
#endif /* defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) */

/***************************************************************************** 
* Class VcpFormItemCustomFrame
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemCustomFrame", VcpFormItemCustomFrame, VcpFormItemBase);

VcpFormItemCustomFrame::VcpFormItemCustomFrame():
m_customFrame(NULL)
{
}
void VcpFormItemCustomFrame::onInit()
{
    VcpFormItemBase::onInit();
}
void VcpFormItemCustomFrame::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);
}

void VcpFormItemCustomFrame::attachCustomFrame(VfxFrame *customframe)
{
    setSize(getSize().width, customframe->getSize().height);
    setHeight(customframe->getSize().height);
    customframe->removeFromParentFrame();
    addChildFrame(customframe);    
    m_customFrame = customframe;
}
/***************************************************************************** 
* Class VcpFormItemCaption
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemCaption", VcpFormItemCaption, VcpFormItemBase);

VcpFormItemCaption::VcpFormItemCaption():
m_textFrame(NULL),
m_style(VCPFORM_STYLE1)
{
}
void VcpFormItemCaption::onInit()
{
    VcpFormItemBase::onInit();

    setHeight(CAPTION_HEIGHT +  (VCPFRM_ITEM_HORZ_GAP_1<<1));

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setAnchor(0,0.5);

    VfxS32 offset_y = getSize().height & 0x1;
    m_textFrame->setPos(VCPFRM_INDENT_L1, (getSize().height + 1)/2 );
    
    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CAPTION_FONT_SIZE), VFX_FE1_9));
    m_textFrame->setBounds(0,0,getSize().width - (VCPFRM_INDENT_L1<<1), 0);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setString(VFX_WSTR_EMPTY);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);    
    m_textFrame->setColor(VCP_FORM_CAPTION_TEXT_COLOR);

    m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    setStyle(m_style);
}
void VcpFormItemCaption::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);
}


/* vaib mem reduction*/
void VcpFormItemCaption::setText(VfxResId text_id)
{
	m_textFrame->setString(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemCaption::setText(const VfxWChar* text_buf)
{
	m_textFrame->setString(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemCaption::setText(const VfxWString &text)
{
    m_textFrame->setString(text);
}
VfxWString VcpFormItemCaption::getText()
{
    return m_textFrame->getString();
}

void VcpFormItemCaption::onDraw(VfxDrawContext &dc)   
{
        dc.drawResizedImage( VfxRect(0, VCPFRM_ITEM_HORZ_GAP_1, getSize().width - 2*(0), CAPTION_HEIGHT), VfxImageSrc(VCP_IMG_FORM_CAPTION_BG));
}

void VcpFormItemCaption::setStyle(VcpFormStyleEnum style)
{
    m_style = style;
    //if(m_style == VCPFORM_STYLE1)
    {
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_textFrame->setIndent(VCPFRM_INDENT_L2);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    invalidate();
}
void VcpFormItemCaption::executePrevDependentBehavior(VcpFormItemBase *prevItem)
{
    VcpFormItemBase::executePrevDependentBehavior(prevItem);
    if(!prevItem)
    {
        return;
    }
    else
    {
        prevItem->setHasSeparator(VFX_FALSE);
    }
}

VcpFormStyleEnum VcpFormItemCaption::getStyle()
{
    return m_style;
}

/***************************************************************************** 
* Class VcpFormItemLabeledControl
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemLabeledControl", VcpFormItemLabeledControl, VcpFormItemBase);

VcpFormItemLabeledControl::VcpFormItemLabeledControl():    
m_label(NULL),
m_labelText(VFX_WSTR_EMPTY),
m_labelPos(VCPFORM_NO_LABEL)
{
}
void VcpFormItemLabeledControl::onInit()
{
    VcpFormItemBase::onInit();    
    setHeight(TOP_GAP + VCPFRM_STD_UI_CNTRL_HEIGHT + BOTTOM_GAP);    
}

void VcpFormItemLabeledControl::onUpdate()
{            
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FIL", SA_start); 
#endif
    if(m_labelText == VFX_WSTR_EMPTY || m_labelText == VFX_WSTR_NULL)
    {
        if(m_label)
        {
            VFX_OBJ_CLOSE(m_label);
        }
    }
    else
    {
        if(!m_label)
        {
            VFX_OBJ_CREATE(m_label, VfxTextFrame, this);
        }
        m_label->setString(m_labelText);
    }


    if(m_labelPos == VCPFORM_NO_LABEL)
    {
        m_height =  TOP_GAP + getControlRect().size.height + BOTTOM_GAP;
        if(m_label)
        {
            VFX_OBJ_CLOSE(m_label);
        }
    }
    else if(m_labelPos == VCPFORM_TOP_LEFT)
    {
        if(!m_label)
        {
        
#if defined(__MAUI_SOFTWARE_LA__)
				SLA_CustomLogging("FIL", SA_stop); 
#endif
            return;
        }
        m_label->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_label->setAnchor(0,0);
        m_label->setPos(LEFT_GAP, TOP_GAP);
        m_label->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
        m_label->setBounds(0,0,getSize().width - (LEFT_GAP<<1), 0);
        m_label->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_label->setColor(VCP_FORM_MAIN_FONT_COLOR);

        m_height = TOP_GAP + m_label->getSize().height + VCPFRM_ITEM_HORZ_GAP_1 + getControlRect().size.height + BOTTOM_GAP;        
    }
    else if(m_labelPos == VCPFORM_LEFT)
    {
        if(!m_label)
        {
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("FIL", SA_stop); 
#endif        
            return;
        }

        m_label->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);            
        m_label->setAnchor(0, 0.5);
        m_label->setPos(LEFT_GAP, TOP_GAP + (VCPFRM_STD_UI_CNTRL_HEIGHT>>1));
        m_label->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
        m_label->setBounds(0, 0, LABEL_MAX_WIDTH,  0);
        m_label->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_label->setColor(VCP_FORM_MAIN_FONT_COLOR);
        m_height = TOP_GAP + getControlRect().size.height + BOTTOM_GAP;    
    }
    VcpFormItemBase::onUpdate();
    if(m_label)
    {
        m_label->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_NONE);
    }
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FIL", SA_stop); 
#endif	
}

void VcpFormItemLabeledControl::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);
}

void VcpFormItemLabeledControl::setLabelPosition(VcpFormLabelPositionEnum pos)
{
    if(m_labelPos != pos)
    {
        m_labelPos = pos;
        onUpdate();
    }
}

VcpFormLabelPositionEnum VcpFormItemLabeledControl::getLabelPosition()
{
    return m_labelPos;
}

VfxRect VcpFormItemLabeledControl::getControlRect()
{
    // It'll return the position assuming the anchor is (0.0, 0.0)
    VfxS32 labelHeight = 0;
    if(m_label)
    {
        labelHeight = m_label->getSize().height;
    }
    if(m_labelPos == VCPFORM_NO_LABEL)
    {
        return VfxRect(LEFT_GAP, 
                                        TOP_GAP,
            getParentFrame()->getSize().width - (LEFT_GAP<<1), 
                                        VCPFRM_STD_UI_CNTRL_HEIGHT) ;
    }
    else if(m_labelPos == VCPFORM_TOP_LEFT)
    {
        return VfxRect(LEFT_GAP, 
                                     (TOP_GAP + labelHeight + TOP_GAP/2),
            getParentFrame()->getSize().width - (LEFT_GAP<<1), 
                                     VCPFRM_STD_UI_CNTRL_HEIGHT) ;
    }
    else if(m_labelPos == VCPFORM_LEFT)
    {
        return VfxRect(LEFT_GAP + LABEL_MAX_WIDTH +VCPFRM_SIDE_MARGIN_SMALL, 
                                     TOP_GAP,
            getParentFrame()->getSize().width - (LEFT_GAP + LABEL_MAX_WIDTH +VCPFRM_SIDE_MARGIN_SMALL + LEFT_GAP), 
                                     VCPFRM_STD_UI_CNTRL_HEIGHT) ;
    }
    VFX_ASSERT(0);
    return VfxRect(0,0,0,0);
}

void VcpFormItemLabeledControl::setLabelTextFromXML(const VfxWString &text)
{
        VfxWString t = text;
        setLabelText(text);
}

/* vaib mem reduction*/
void VcpFormItemLabeledControl::setLabelText(VfxResId text_id)
{
	setLabelText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemLabeledControl::setLabelText(const VfxWChar* text_buf)
{
	setLabelText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemLabeledControl::setLabelText(VfxWString text)
{
    m_labelText = text;
    if(m_labelText == VFX_WSTR_EMPTY || m_labelText == VFX_WSTR_NULL)
    {
       setLabelPosition(VCPFORM_NO_LABEL);
    }
    else if(m_labelPos == VCPFORM_NO_LABEL)
    {
        setLabelPosition(VCPFORM_TOP_LEFT);
    }
    onUpdate();
}

VfxWString VcpFormItemLabeledControl::getLabelText()
{
    return m_label->getString();
}

/***************************************************************************** 
* Class VcpFormItemBigArrowButton
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemBigArrowButton", VcpFormItemBigArrowButton, VcpFormItemLabeledControl);

VcpFormItemBigArrowButton::VcpFormItemBigArrowButton():    
m_button(NULL)
{
}
void VcpFormItemBigArrowButton::onInit()
{
    VcpFormItemLabeledControl::onInit();    

    VFX_OBJ_CREATE(m_button, VcpArrowButton, this);
    m_button->setText(VFX_WSTR_EMPTY);
    m_button->m_signalClicked.connect(this, &VcpFormItemBigArrowButton::onButtonClick);
    m_button->setStyle(VCP_BUTTON_STYLE_DEFAULT);

    checkUpdate();
}

void VcpFormItemBigArrowButton::onUpdate()
{
    VcpFormItemLabeledControl::onUpdate();
    if(m_button)
    {
        m_button->setInnerRect(getControlRect());
    }
}

void VcpFormItemBigArrowButton::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemLabeledControl::onFormBoundsChanged(frm, rect);
}

void VcpFormItemBigArrowButton::setLabelPosition(VcpFormLabelPositionEnum pos)
{
    VcpFormItemLabeledControl::setLabelPosition(pos);
}

/* vaib mem reduction*/
void VcpFormItemBigArrowButton::setButtonText(VfxResId text_id)
{
	m_button->setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemBigArrowButton::setButtonText(const VfxWChar* text_buf)
{
	m_button->setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemBigArrowButton::setButtonText(const VfxWString& text)
{
    m_button->setText(text);        
}
VfxWString VcpFormItemBigArrowButton::getButtonText()
{
    return m_button->getText();
}
VcpArrowButton *VcpFormItemBigArrowButton::getButton()
{
    return m_button;       
}

/* vaib mem reduction*/
void VcpFormItemBigArrowButton::setHintText(VfxResId text_id)
{
	m_button->setHintText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemBigArrowButton::setHintText(const VfxWChar* text_buf)
{
	m_button->setHintText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemBigArrowButton::setHintText(VfxWString text)
{
    m_button->setHintText(text);
}

VfxWString VcpFormItemBigArrowButton::getHintText()
{
    return m_button->getHintText();
}

void VcpFormItemBigArrowButton::onButtonClick(VfxObject *btn, VfxId id)
{
    m_signalButtonClick.emit(getId());
}


/***************************************************************************** 
* Class VcpFormItemBigAddButton
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemBigAddButton", VcpFormItemBigAddButton, VcpFormItemLabeledControl);

VcpFormItemBigAddButton::VcpFormItemBigAddButton():    
m_button(NULL)
{
}

void VcpFormItemBigAddButton::onInit()
{
    VcpFormItemLabeledControl::onInit();    

    VFX_OBJ_CREATE(m_button, VcpAddButton, this);
    m_button->setText(VFX_WSTR_EMPTY);

    setLabelPosition(VCPFORM_NO_LABEL); 
    m_button->setInnerRect(getControlRect());
    m_button->m_signalClicked.connect(this, &VcpFormItemBigAddButton::onButtonClick);
    if(m_button)
    {
        m_button->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
    }
}

void VcpFormItemBigAddButton::onUpdate()
{
    VcpFormItemLabeledControl::onUpdate();
    if(m_button)
    {
        m_button->setInnerRect(getControlRect());
    }
}
void VcpFormItemBigAddButton::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);
}

void VcpFormItemBigAddButton::setLabelPosition(VcpFormLabelPositionEnum pos)
{
    VcpFormItemLabeledControl::setLabelPosition(pos);
}

/* vaib mem reduction*/
void VcpFormItemBigAddButton::setButtonText(VfxResId text_id)
{
	m_button->setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemBigAddButton::setButtonText(const VfxWChar* text_buf)
{
	m_button->setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemBigAddButton::setButtonText(const VfxWString& text)
{
    m_button->setText(text);        
}
VfxWString VcpFormItemBigAddButton::getButtonText()
{
    return m_button->getText();
}
VcpAddButton *VcpFormItemBigAddButton::getButton()
{
    return m_button;       
}

void VcpFormItemBigAddButton::onButtonClick(VfxObject *btn, VfxId id)
{
    m_signalButtonClick.emit(getId());
}

/***************************************************************************** 
* Class VcpFormItemBigButton
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemBigButton", VcpFormItemBigButton, VcpFormItemLabeledControl);

VcpFormItemBigButton::VcpFormItemBigButton():    
    m_button(NULL)
{
}
void VcpFormItemBigButton::onInit()
{
    VcpFormItemLabeledControl::onInit();    

    VFX_OBJ_CREATE(m_button, VcpButton, this);
    m_button->setText(VFX_WSTR_EMPTY);
	m_button->m_signalClicked.connect(this, &VcpFormItemBigButton::onButtonClick);
    m_button->setStyle(VCP_BUTTON_STYLE_DEFAULT);
    m_button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);

	setLabelPosition(m_labelPos);

    VFX_OBJ_CREATE(m_hintText, VfxTextFrame, m_button);
    m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    m_hintText->setColor(VCP_FORM_HINT_TEXT_COLOR);
    m_hintText->setIsUnhittable(VFX_TRUE);
	
    checkUpdate();
}

void VcpFormItemBigButton::onUpdate()
{
    VcpFormItemLabeledControl::onUpdate();
    if(m_button)
    {
        m_button->setInnerRect(getControlRect());
        if(m_hintText)
        {
            m_hintText->setAnchor(1.0, 0.5);
            m_hintText->setPos(m_button->getInnerRect().size.width - VCPFRM_INDENT_L3, m_button->getInnerRect().size.height / 2 );

            VfxS32 left, top, right, bottom;
            m_button->getMargin(left, top, right, bottom);
            VfxS32 availableWidth = m_hintText->getPos().x - left;
            m_hintText->setBounds(0, 0, availableWidth/3, 0);
            m_hintText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));
            m_hintText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_hintText->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_NONE);
        } 
    }
}

void VcpFormItemBigButton::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemLabeledControl::onFormBoundsChanged(frm, rect);
}

void VcpFormItemBigButton::setLabelPosition(VcpFormLabelPositionEnum pos)
{
    VcpFormItemLabeledControl::setLabelPosition(pos);
}

/* vaib mem reduction*/
void VcpFormItemBigButton::setButtonText(VfxResId text_id)
{
	m_button->setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemBigButton::setButtonText(const VfxWChar* text_buf)
{
	m_button->setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemBigButton::setButtonText(VfxWString text)
{
    m_button->setText(text);        
}
VfxWString VcpFormItemBigButton::getButtonText()
{
    return m_button->getText();
}
VcpButton *VcpFormItemBigButton::getButton()
{
    return m_button;       
}

/* vaib mem reduction*/
void VcpFormItemBigButton::setHintText(VfxResId text_id)
{
	m_hintText->setString(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemBigButton::setHintText(const VfxWChar* text_buf)
{
	m_hintText->setString(VFX_WSTR_MEM(text_buf));
}


void VcpFormItemBigButton::setHintText(VfxWString text)
{
    m_hintText->setString(text);
}

VfxWString VcpFormItemBigButton::getHintText()
{
    return m_hintText->getString(); 
}

void VcpFormItemBigButton::onButtonClick(VfxObject *btn, VfxId id)
{
	m_signalButtonClick.emit(getId());
}

/***************************************************************************** 
* Class VcpFormItemTextInput
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemTextInput", VcpFormItemTextInput, VcpFormItemLabeledControl);

VcpFormItemTextInput::VcpFormItemTextInput():    
    m_textBox(NULL)
{
    memset(m_inputString, 0, sizeof(VfxWChar)*128);
}


#if defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING)
VfxBool VcpFormItemTextInput::canHandleKeyEvent()
{
    return VFX_TRUE;
} 
#endif /* defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) */

void VcpFormItemTextInput::onInit()
{
    VcpFormItemLabeledControl::onInit();    
    VFX_OBJ_CREATE(m_textBox, VcpFormTextEditor, this);

    setLabelPosition(VCPFORM_NO_LABEL); 
    m_textBox->setPos(getControlRect().origin);  
    m_textBox->setEditorSize(getControlRect().size.width, VCPFRM_STD_UI_CNTRL_HEIGHT);    

    m_textBox->getEditor()->setText(m_inputString, 128);   

    onUpdate();
}

VfxRect VcpFormItemTextInput::getControlRect()
{
    VfxRect rect = VcpFormItemLabeledControl::getControlRect();    
    if(m_textBox)
    {
        rect.size.height = m_textBox->getSize().height;
    }
    return rect;
}

void VcpFormItemTextInput::onUpdate()
{
    VcpFormItemLabeledControl::onUpdate();
    if(m_textBox)
    {
        m_textBox->setPos(getControlRect().origin);  
        m_textBox->setEditorSize(getControlRect().size.width, m_textBox->getEditorSize().height );    
    }
}

void VcpFormItemTextInput::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{  
    VcpFormItemLabeledControl::onFormBoundsChanged(frm, rect);
}

void VcpFormItemTextInput::setLabelPosition(VcpFormLabelPositionEnum pos)
{
    VcpFormItemLabeledControl::setLabelPosition(pos);
}

void VcpFormItemTextInput::setTextFromXML(const VfxWString &text)
{       
        VfxWString t = text;
        setText(t);
}

/* vaib mem reduction*/
void VcpFormItemTextInput::setText(VfxResId text_id)
{
	setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemTextInput::setText(const VfxWChar* text_buf)
{
	setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemTextInput::setText(VfxWString text)
{
    vfx_sys_wcscpy(m_inputString, text.getBuf());
    m_textBox->getEditor()->setText(m_inputString, 128);  
}

VfxWString VcpFormItemTextInput::getText()
{
    return VFX_WSTR_STATIC(m_textBox->getEditor()->getText());
}

VcpTextEditor *VcpFormItemTextInput::getTextBox()
{
    return m_textBox->getEditor();
}

void VcpFormItemTextInput::setFocused(VfxBool value)
{
    if(VFX_TRUE == value)
    {
        m_textBox->getEditor()->activate();
    }
    else 
    {
        m_textBox->getEditor()->deactivate();
    }
}

/* vaib mem reduction*/
void VcpFormItemTextInput::setWarningText(VfxResId text_id)
{
	m_textBox->setWarningText(VFX_WSTR_RES(text_id));
	onUpdate();
}

/* vaib mem reduction*/
void VcpFormItemTextInput::setWarningText(const VfxWChar* text_buf)
{
	m_textBox->setWarningText(VFX_WSTR_MEM(text_buf));
	onUpdate();
}

void VcpFormItemTextInput::setWarningText(const VfxWString &value)
{
    m_textBox->setWarningText(value);
    onUpdate();
}

/***************************************************************************** 
* Class VcpFormItemRemovableTextEntry
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemRemovableTextEntry", VcpFormItemRemovableTextEntry, VcpFormItemBase);

VcpFormItemRemovableTextEntry::VcpFormItemRemovableTextEntry():
m_leftButton(NULL),
m_textBox(NULL),
m_addButton(NULL),
m_removeButton(NULL),
m_mode(VFX_TRUE),
m_hasLeftButton(VFX_TRUE)
{
    memset(m_inputString, 0, sizeof(VfxWChar)*128);
}

VcpFormItemRemovableTextEntry::VcpFormItemRemovableTextEntry(VfxBool mode):
m_leftButton(NULL),
m_textBox(NULL),
m_addButton(NULL),
m_removeButton(NULL),
m_mode(mode),
m_hasLeftButton(VFX_TRUE)
{
    memset(m_inputString, 0, sizeof(VfxWChar)*128);
}

void VcpFormItemRemovableTextEntry::onInit()
{
    VcpFormItemBase::onInit(); 
    setHeight(VCPFRM_ITEM_HORZ_GAP_1 + VCPFRM_STD_UI_EDITOR_HEIGHT + VCPFRM_ITEM_HORZ_GAP_1);    
    updateChildren();
    updateLayout();
}

void VcpFormItemRemovableTextEntry::setHasLeftButton(VfxBool choice)
{
    m_hasLeftButton = choice;
    updateChildren();
    updateLayout();
}

VfxBool VcpFormItemRemovableTextEntry::getHasLeftButton() const
{
    return m_hasLeftButton;
}


/* vaib mem reduction*/
void VcpFormItemRemovableTextEntry::setText(VfxResId text_id)
{
	setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemRemovableTextEntry::setText(const VfxWChar* text_buf)
{
	setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemRemovableTextEntry::setText(VfxWString text)
{
    vfx_sys_wcscpy(m_inputString, text.getBuf());
    m_textBox->getEditor()->setText(m_inputString, 128);  
}

VfxWString VcpFormItemRemovableTextEntry::getText()
{
    return VFX_WSTR_STATIC(m_textBox->getEditor()->getText());
}

/* vaib mem reduction*/
void VcpFormItemRemovableTextEntry::setWarningText(VfxResId text_id)
{
	m_textBox->setWarningText(VFX_WSTR_RES(text_id));
	onUpdate();
}

/* vaib mem reduction*/
void VcpFormItemRemovableTextEntry::setWarningText(const VfxWChar* text_buf)
{
	m_textBox->setWarningText(VFX_WSTR_RES(text_buf));
	onUpdate();
}

void VcpFormItemRemovableTextEntry::setWarningText(const VfxWString &value)
{
    m_textBox->setWarningText(value);
    onUpdate();
}

VcpArrowButton *VcpFormItemRemovableTextEntry::getLeftButton() 
{
    return m_leftButton;
}
VcpTextEditor  *VcpFormItemRemovableTextEntry::getTextBox()     
{
    return m_textBox->getEditor();
}

VfxBool VcpFormItemRemovableTextEntry::getMode()
{
    return m_mode;
}

void VcpFormItemRemovableTextEntry::updateChildren()
{
    if(m_hasLeftButton)
    {
        if(!m_leftButton)
        {
            VFX_OBJ_CREATE(m_leftButton , VcpArrowButton, this);    
        }
    }
    else
    {
        if(m_leftButton)
        {
            VFX_OBJ_CLOSE(m_leftButton);
        }
    }

    if(!m_textBox)
    {
        VFX_OBJ_CREATE(m_textBox, VcpFormTextEditor, this);
    }
    if(m_addButton)
    {
        VFX_OBJ_CLOSE(m_addButton);
    }
    if(m_removeButton)
    {
        VFX_OBJ_CLOSE(m_removeButton);
    }
    if(VFX_TRUE == m_mode )
    {
        VFX_OBJ_CREATE(m_addButton, VcpAddButton, this);
    }
    else
    {
        VFX_OBJ_CREATE(m_removeButton, VcpCancelButton, this);
    }
}


void VcpFormItemRemovableTextEntry::updateLayout()
{
    VfxS32 x = VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2;
    if(m_leftButton)
    {
        m_leftButton->setInnerRect(VfxRect(VfxPoint(x, VCPFRM_ITEM_HORZ_GAP_1), VfxSize(LEFT_BUTTON_SIZE, VCPFRM_STD_UI_EDITOR_HEIGHT)));
        m_leftButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_NONE);

        x += m_leftButton->getSize().width + GAP;
    }
    if(m_textBox)
    {
        m_textBox->setEditorSize(getSize().width - (x + GAP + RIGHT_BUTTON_SIZE + VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2), 
            VCPFRM_STD_UI_EDITOR_HEIGHT);
        m_textBox->getEditor()->setText(m_inputString, 128);  
        m_textBox->setPos(x , VCPFRM_ITEM_HORZ_GAP_1);
        x += m_textBox->getSize().width + GAP;
    }
    if(m_addButton)
    {
        m_addButton->setInnerRect(VfxRect(      VfxPoint(getSize().width - (VCPFRM_INDENT_L1 + RIGHT_BUTTON_SIZE + VCPFRM_INDENT_L2), VCPFRM_ITEM_HORZ_GAP_1), VfxSize(RIGHT_BUTTON_SIZE, VCPFRM_STD_UI_EDITOR_HEIGHT)  ));
        m_addButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
        if(m_leftButton)
        {
            m_leftButton->setOpacity(0.3f);
            m_leftButton->setIsUnhittable(VFX_TRUE);
        }
        if(m_textBox)
        {
            m_textBox->setOpacity(0.3f);
            m_textBox->setIsUnhittable(VFX_TRUE);
        }
        m_addButton->m_signalClicked.connect(this, &VcpFormItemRemovableTextEntry::onAddRemoveClick);                
    }
    else if(m_removeButton)
    {
        m_removeButton->setInnerRect(VfxRect(      VfxPoint(getSize().width - (VCPFRM_INDENT_L1 + RIGHT_BUTTON_SIZE + VCPFRM_INDENT_L2), VCPFRM_ITEM_HORZ_GAP_1), VfxSize(RIGHT_BUTTON_SIZE, VCPFRM_STD_UI_EDITOR_HEIGHT)  ));
        m_removeButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);

        if(m_leftButton)
        {
            m_leftButton->setOpacity(1.0);
            m_leftButton->setIsUnhittable(VFX_FALSE);
        }
        if(m_textBox)
        {
            m_textBox->setOpacity(1.0);
            m_textBox->setIsUnhittable(VFX_FALSE);
        }

        m_removeButton->m_signalClicked.connect(this, &VcpFormItemRemovableTextEntry::onAddRemoveClick);                
    }

}

void VcpFormItemRemovableTextEntry::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);        
}

void VcpFormItemRemovableTextEntry::onAddRemoveClick(VfxObject*sender, VfxId btnId)
{
    if(VFX_TRUE == m_mode )
    {
        m_signalAddRemoveClick.emit(this, m_id, VFX_TRUE);
    }
    else
    {  
        m_signalAddRemoveClick.emit(this, m_id, VFX_FALSE);        
    }
}

void VcpFormItemRemovableTextEntry::setMode(VfxBool mode)
{  
    m_mode = mode;

    updateChildren();
    updateLayout();
}


#if defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING)
VfxBool VcpFormItemRemovableTextEntry::canHandleKeyEvent()
{
    return VFX_TRUE;
}
#endif /* defined(VCP_FRM_KEY_BASED_FOCUS_HANDLING) */

void VcpFormItemRemovableTextEntry::setFocused(VfxBool value)
{
    if(value == VFX_TRUE)
    {
        m_textBox->getEditor()->activate();
    }
    else
    {
        m_textBox->getEditor()->deactivate();
    }
}

void VcpFormItemRemovableTextEntry::onUpdate()
{
    if(m_textBox)
    {
        m_textBox->setEditorSize(getSize().width - (m_textBox->getPos().x + GAP + RIGHT_BUTTON_SIZE + VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2), 
            m_textBox->getEditorSize().height);
        m_height = VCPFRM_ITEM_HORZ_GAP_1 + m_textBox->getSize().height + VCPFRM_ITEM_HORZ_GAP_1;
    }
    VcpFormItemBase::onUpdate();
}


/***************************************************************************** 
* Class VcpFormItemCell
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemCell", VcpFormItemCell, VcpFormItemBase);

VcpFormItemCell::VcpFormItemCell():
m_mainText(NULL),
m_hintText(NULL),
m_isTappable(VFX_TRUE),
m_state(NORMAL)
{}

void VcpFormItemCell::onInit()
{
    VcpFormItemBase::onInit();
    setHeight(HEIGHT);    
       
    setMainText(VFX_WSTR_EMPTY);
    m_mainText->setPos(LEFT_MARGIN, TOP_MARGIN);

    ((VcpForm*)getParentFrame())->insertSeparator(this);
}
void VcpFormItemCell::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemBase::onFormBoundsChanged(frm, rect);    
}

VfxBool VcpFormItemCell::onPenInput(VfxPenEvent &event)
{    
    if(!m_isTappable)
    {
        return VFX_TRUE;
    }
    VfxPoint pos(event.getRelPos(this));    

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        if(m_state == NORMAL)
        {
            m_downPos = pos;        
            m_state = PRESSED;
            setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            setImgContent(VfxImageSrc(VCP_IMG_FORM_HIGHLIGHTED_CELL_BG));
            m_mainText->setColor(VCP_FORM_HIGHLIGHTED_FONT_COLOR);
            if(m_hintText)
            {
                m_hintText->setColor(VCP_FORM_HIGHLIGHTED_FONT_COLOR);
            }
        }
        return VFX_TRUE;
    case VFX_PEN_EVENT_TYPE_UP:
        if (m_state == PRESSED)
        {
            m_state = NORMAL;
            VfxTimer *timer;
            VFX_OBJ_CREATE(timer, VfxTimer, this);
            timer->setStartDelay(VCP_FORM_MUST_STAY_FOCUSSED_TIME);
            timer->m_signalTick.connect(this, &VcpFormItemCell::onFocusedTimeEnd);
            timer->start();
            onCellTap(event);        
        }
        m_downPos = VfxPoint(-1,-1);
        return VFX_TRUE;
    case VFX_PEN_EVENT_TYPE_LONG_TAP:
        if (m_state == PRESSED)
        {
            onCellTap(event);        
        }
        return VFX_TRUE;
    case VFX_PEN_EVENT_TYPE_MOVE:
        if((VFX_ABS(pos.y - m_downPos.y) < getHeight()) && m_isTappable)
        {
            return VFX_TRUE;
        } // Otherwise, behave as ABORT
    case VFX_PEN_EVENT_TYPE_ABORT:
        if (m_state == PRESSED)
        {
            m_state = NORMAL;
            VfxTimer *timer;
            VFX_OBJ_CREATE(timer, VfxTimer, this);
            timer->setStartDelay(VCP_FORM_MUST_STAY_FOCUSSED_TIME);
            timer->m_signalTick.connect(this, &VcpFormItemCell::onFocusedTimeEnd);
            timer->start();
        }
        break;
    default:
        break;
    }
    VfxControl::onPenInput(event);
    return VFX_FALSE;
}

void VcpFormItemCell::setIsDisabled(VfxBool state)	
{
	if (m_state == PRESSED)
	{
		m_state = NORMAL;
		setImgContent(VFX_IMAGE_SRC_NULL);
		setBgColor(getBgColor());
		m_mainText->setColor(VCP_FORM_MAIN_FONT_COLOR);
		if(m_hintText)
		{
			m_hintText->setColor(VCP_FORM_HINT_TEXT_COLOR);
		}
	}
	VcpFormItemBase::setIsDisabled(state);
}

void VcpFormItemCell::onFocusedTimeEnd(VfxTimer *timer)
{
    if(timer)
    {
        timer->stop();
        VFX_OBJ_CLOSE(timer);
    }
    setImgContent(VFX_IMAGE_SRC_NULL);
    setBgColor(getBgColor());
    m_mainText->setColor(VCP_FORM_MAIN_FONT_COLOR);
    if(m_hintText)
    {
        m_hintText->setColor(VCP_FORM_HINT_TEXT_COLOR);
    }
}

/* vaib mem reduction*/
void VcpFormItemCell::setMainText(VfxResId text_id)
{
	setMainText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemCell::setMainText(const VfxWChar* text_buf)
{
	setMainText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemCell::setMainText(const VfxWString &text)
{
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("FCM", SA_start); 
#endif
    if(!m_mainText)
    {
        VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
        m_mainText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE)));
        m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_mainText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_mainText->setColor(VCP_FORM_MAIN_FONT_COLOR);
        m_mainText->setFullLineHeightMode(VFX_FALSE);
    }
    m_mainText->setString(text);
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
				SLA_CustomLogging("FCM", SA_stop); 
#endif	
}

void VcpFormItemCell::firstItemDependentChanges(VcpForm *parent)
{
    VcpFormItemBase::firstItemDependentChanges(parent);
    parent->setContentTopGap(0);
}

VfxWString VcpFormItemCell::getMainText()
{
    return m_mainText->getString();
}

/* vaib mem reduction*/
void VcpFormItemCell::setHintText(VfxResId text_id)
{
	setHintText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemCell::setHintText(const VfxWChar* text_buf)
{
	setHintText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemCell::setHintText(const VfxWString &text)
{
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FCH", SA_start); 
#endif
    if(text == VFX_WSTR_NULL ||
        text == VFX_WSTR_EMPTY)
    {
        if(m_hintText)
        {
            VFX_OBJ_CLOSE(m_hintText);
            checkUpdate();
        }
        return;
    }
    if(!m_hintText)
    {

	    VFX_OBJ_CREATE(m_hintText, VfxTextFrame, this);
	    m_hintText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(HINT_FONT_SIZE)));
	    m_hintText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	    m_hintText->setColor(VCP_FORM_HINT_TEXT_COLOR);
	   // m_hintText->setFullLineHeightMode(VFX_FALSE);
	    m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    }
	m_hintText->setString(text);
	checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FCH", SA_stop); 
#endif	
}

VfxWString VcpFormItemCell::getHintText()
{
    if(m_hintText)
    {
        return m_hintText->getString();
    }
    else
    {
        return VFX_WSTR_EMPTY;
    }
}

void VcpFormItemCell::setIsTappable(VfxBool isTappable)
{
    m_isTappable = isTappable;
}

VfxBool VcpFormItemCell::getIsTappable()
{
    return m_isTappable;
}

void VcpFormItemCell::onCellTap(VfxPenEvent &event)
{
	VFX_UNUSED(event);
}

void VcpFormItemCell::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FCU", SA_start); 
#endif	
	VcpFormItemBase::onUpdate();
    if(!m_mainText)
    {
        return;
    }
	m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + RIGHT_MARGIN), 0);
	if(m_hintText)
	{
	   m_mainText->setAnchor(0,0);
	   m_mainText->setPos(m_mainText->getPos().x, TOP_MARGIN);
	   m_hintText->setAnchor(0,1.0);
	   m_hintText->setPos(m_mainText->getPos().x, getSize().height - BOTTOM_MARGIN );
	   m_hintText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + RIGHT_MARGIN), 0);
	}
	else
	{
	   m_mainText->setAnchor(0,0.5);
	   m_mainText->setPos(m_mainText->getPos().x, getSize().height/2);
	}
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FCU", SA_stop); 
#endif		

}


/***************************************************************************** 
* Class VcpFormItemLauncherCell
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemLauncherCell", VcpFormItemLauncherCell, VcpFormItemCell);

VcpFormItemLauncherCell::VcpFormItemLauncherCell():
m_accessory(NULL),
m_accType(VCPFORM_NONE),
m_hintPosition(HINT_POSITION_BOTTOM_LEFT)
{
}

void VcpFormItemLauncherCell::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FIC", SA_start); 
#endif
    VcpFormItemCell::onInit();

    VFX_OBJ_CREATE(m_accessory, VfxImageFrame, this);
    m_accessory->setAnchor(1.0, 0.5);
    m_accessory->setPos(getSize().width - RIGHT_MARGIN , getSize().height/2);
    m_accessory->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("FIC", SA_stop); 
#endif	
}
void VcpFormItemLauncherCell::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemCell::onFormBoundsChanged(frm, rect);
}

VfxBool VcpFormItemLauncherCell::onPenInput(VfxPenEvent &event)
{
    VfxBool result =  VcpFormItemCell::onPenInput(event);    
    if(m_state == PRESSED)    
    {
        if(m_accessory&&
            (m_accType == VCPFORM_NEXT_ITEM_ICON))
        {
            m_accessory->setImgContent(VfxImageSrc(VCP_IMG_NEXT_ITEM_ICON_P));
        }
    }
    return result;    
}

void VcpFormItemLauncherCell::onCellTap(VfxPenEvent &event)
{
    VcpFormItemCell::onCellTap(event);
    if(getIsDisabled())
    {
        return;
    }
    if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_signalTap.postEmit(this, m_id);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        m_signalLongTap.postEmit(this, m_id);
    }    
}

void VcpFormItemLauncherCell::onFocusedTimeEnd(VfxTimer *timer)
{
    VcpFormItemCell::onFocusedTimeEnd(timer);
    if(m_accessory &&
        (m_accType == VCPFORM_NEXT_ITEM_ICON))
    {
        m_accessory->setImgContent(VfxImageSrc(VCP_IMG_NEXT_ITEM_ICON_N));
    }
}

void VcpFormItemLauncherCell::setAccessory(VcpFormAccessoryType acc)
{
    m_accType = acc;
    if(m_accType == VCPFORM_NEXT_ITEM_ICON)
    {
        m_accessory->setImgContent(VfxImageSrc(VCP_IMG_NEXT_ITEM_ICON_N));
    }    
    checkUpdate();
}

VcpFormAccessoryType VcpFormItemLauncherCell::getAccessory()
{
    return m_accType;
}

void VcpFormItemLauncherCell::setHintPosition(HintPositionEnum hintPos)
{
	m_hintPosition = hintPos;
	checkUpdate();
}

VcpFormItemLauncherCell::HintPositionEnum VcpFormItemLauncherCell::getHintPosition()
{
    return m_hintPosition;
}

void VcpFormItemLauncherCell::onUpdate()
{	
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FLU", SA_start); 
#endif

    VcpFormItemCell::onUpdate();
    VfxS32 rightGap = RIGHT_MARGIN;
    if(m_accessory)
    {
        rightGap += m_accessory->getSize().width + VCPFRM_SIDE_MARGIN_SMALL;
    }	
    if(!m_hintText)
    {
        if(m_mainText)
        {
            m_mainText->setAnchor(0.0, 0.5);
            m_mainText->setVerticalToCenter(VFX_TRUE);
            m_mainText->setPos(LEFT_MARGIN, getSize().height/2);
            m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap), 0);
        }
        return;
    }
    switch(m_hintPosition)
    {
    case HINT_POSITION_BOTTOM_LEFT:
        if(m_hintText)
        {
            m_hintText->setAnchor(0.0, 1.0);
            m_hintText->setPos(m_mainText->getPos().x, getSize().height - (BOTTOM_MARGIN ) );
            m_hintText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap) , 0);
            m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        }
        if(m_mainText)
        {
            m_mainText->setAnchor(0.0, 0.0);
            m_mainText->setPos(LEFT_MARGIN, TOP_MARGIN);
            m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap), 0);
        }

        break;


    case HINT_POSITION_RIGHT_END:
        if(m_hintText)
        {
            m_hintText->setAnchor(1.0, 0.5);
            m_hintText->setVerticalToCenter(VFX_TRUE);
            m_hintText->setPos((getSize().width - (LEFT_MARGIN + rightGap))/3, getSize().height/2);
            m_hintText->setBounds(0, 0, getSize().width/2 , 0);
            m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        }
        if(m_mainText)
        {
            m_mainText->setAnchor(0.0, 0.5);
            m_mainText->setVerticalToCenter(VFX_TRUE);
            m_mainText->setPos(LEFT_MARGIN, getSize().height/2);
            m_mainText->setBounds(0, 0, 2*(getSize().width - (LEFT_MARGIN + rightGap))/3, 0);
        }
        break;
    default:
        if(m_mainText)
        {
            m_mainText->setAnchor(0.0, 0.5);
            m_mainText->setVerticalToCenter(VFX_TRUE);
            m_mainText->setPos(LEFT_MARGIN, getSize().height/2);
            m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap), 0);
        }
        break;
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FLU", SA_stop); 
#endif	

}

/***************************************************************************** 
* Class VcpFormItemSwitchCell
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemSwitchCell", VcpFormItemSwitchCell, VcpFormItemCell);

VcpFormItemSwitchCell::VcpFormItemSwitchCell():
m_switch(NULL),
m_activityInd(NULL)
{
}

void VcpFormItemSwitchCell::onInit()
{
    VcpFormItemCell::onInit();
    setIsTappable(VFX_FALSE);
    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    m_switch->setAnchor(1.0, 0.5);
    m_switch->setPos(getSize().width - RIGHT_MARGIN, getSize().height/2);
    m_switch->setChecked(VFX_FALSE, VFX_FALSE);
    m_switch->m_signalSwitchChanged.connect(this, &VcpFormItemSwitchCell::onUserSwitchChangeReq);
    m_switch->m_signalToggleAnimationDone.connect(this, &VcpFormItemSwitchCell::onSwitchAnimationCompleted);
    m_switch->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
}
void VcpFormItemSwitchCell::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemCell::onFormBoundsChanged(frm, rect);
}

void VcpFormItemSwitchCell::onUserSwitchChangeReq(VcpSwitch* sw, VfxBool status)
{
    m_switch->setChecked(!m_switch->getChecked(), VFX_FALSE); // Revert the change first. Toggle command should come only form App.
    m_signalSwitchChangeReq.emit(this, m_id, status);
}

void VcpFormItemSwitchCell::onSwitchAnimationCompleted(VcpSwitch *sw, VfxBool state)
{
    m_signalToggleAnimationDone.emit(this, m_id, state);
}

void VcpFormItemSwitchCell::setSwitchStatus(VfxBool state)
{
    if(m_activityInd)
    {
        VFX_OBJ_CLOSE(m_activityInd);
        m_switch->setIsHapticTouchEnabled(VFX_TRUE);
    }
    m_switch->setChecked(state);
}

VfxBool VcpFormItemSwitchCell::getSwitchStatus()
{
    return m_switch->getChecked();
}

void VcpFormItemSwitchCell::showProcessInd()
{
    if(!m_activityInd)
    {
        VFX_OBJ_CREATE(m_activityInd, VcpActivityIndicator, this);
        m_activityInd->setAnchor(1, 0.5);
        m_activityInd->setPos(m_switch->getPos().x - (m_switch->getSize().width + VCPFRM_ITEM_HORZ_GAP), getSize().height/2);
        m_activityInd->start();
        m_switch->setIsHapticTouchEnabled(VFX_FALSE);
    }
}

void VcpFormItemSwitchCell::hideProcessInd()
{
    if(m_activityInd)
    {
        VFX_OBJ_CLOSE(m_activityInd);
        m_switch->setIsHapticTouchEnabled(VFX_TRUE);
    }
}

void VcpFormItemSwitchCell::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FSU", SA_start); 
#endif
    VcpFormItemCell::onUpdate();
    VfxS32 rightGap = RIGHT_MARGIN + VCPFRM_SIDE_MARGIN_SMALL;
    if(m_switch)
    {
        rightGap += m_switch->getSize().width;
    }
    if(m_mainText)
    {
        m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap) , 0);
    }
    if(m_hintText)
    {
        m_hintText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap) , 0);
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FSU", SA_stop); 
#endif	
}

/***************************************************************************** 
* Class VcpFormItemAidButtonCell
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpFormItemAidButtonCell", VcpFormItemAidButtonCell, VcpFormItemCell);

VcpFormItemAidButtonCell::VcpFormItemAidButtonCell():
m_button(NULL)
{
}

void VcpFormItemAidButtonCell::onInit()
{
    VcpFormItemCell::onInit();
    setIsTappable(VFX_FALSE);
    VFX_OBJ_CREATE(m_button, VcpButton, this);
    m_button->setSize((VCPFRM_STD_UI_CNTRL_HEIGHT<<1), VCPFRM_STD_UI_CNTRL_HEIGHT);
    m_button->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));    
    m_button->setAnchor(1.0, 0.5);
    m_button->setPos(getSize().width - RIGHT_MARGIN, getSize().height/2);    
    m_button->m_signalClicked.connect(this, &VcpFormItemAidButtonCell::onButtonPress);
    m_button->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
}
void VcpFormItemAidButtonCell::onFormBoundsChanged(VfxFrame *frm, const VfxRect &rect)
{
    VcpFormItemCell::onFormBoundsChanged(frm, rect);
}

void VcpFormItemAidButtonCell::onButtonPress(VfxObject* btn, VfxId id)
{
    m_signalAidButtonPress.emit(this, m_id);    
}

/* vaib mem reduction*/
void VcpFormItemAidButtonCell::setButtonText(VfxResId text_id)
{
	m_button->setText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction*/
void VcpFormItemAidButtonCell::setButtonText(const VfxWChar* text_buf)
{
	m_button->setText(VFX_WSTR_MEM(text_buf));
}

void VcpFormItemAidButtonCell::setButtonText(const VfxWString &text)
{
    m_button->setText(text);        
}

void VcpFormItemAidButtonCell::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FAU", SA_start); 
#endif
    VcpFormItemCell::onUpdate();
    VfxS32 rightGap = RIGHT_MARGIN + VCPFRM_SIDE_MARGIN_SMALL;
    if(m_button)
    {
            rightGap += m_button->getSize().width;
    }
    if(m_mainText)
    {
        m_mainText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap) , 0);
    }
    if(m_hintText)
    {
        m_hintText->setBounds(0, 0, getSize().width - (LEFT_MARGIN + rightGap) , 0);
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("FAU", SA_stop); 
#endif	
}

/***************************************************************************** 
* Class VcpFormTextEditor
*****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpFormTextEditor", VcpFormTextEditor, VfxFrame);


VcpFormTextEditor::VcpFormTextEditor():
m_editor(NULL),
m_warningTextFrm(NULL)
{}

void VcpFormTextEditor::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_editor, VcpTextEditor, this);
    m_editor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);    
    m_editor->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_3)));
}

/* vaib mem reduction */
void VcpFormTextEditor::setWarningText(VfxResId text_id)
{
	setWarningText(VFX_WSTR_RES(text_id));
}

/* vaib mem reduction */
void VcpFormTextEditor::setWarningText(const VfxWChar* text_buf)
{
	setWarningText(VFX_WSTR_MEM(text_buf));
}

void VcpFormTextEditor::setWarningText(const VfxWString &text)
{
    if(text == VFX_WSTR_NULL || text == VFX_WSTR_EMPTY)
    {
        if(m_warningTextFrm)
        {
            setSize(getSize().width, m_editor->getSize().height);
            VFX_OBJ_CLOSE(m_warningTextFrm);
        }
    }
    else
    {
        if(!m_warningTextFrm)
        {
            VFX_OBJ_CREATE(m_warningTextFrm, VfxTextFrame, this);
            m_warningTextFrm->setColor(VCP_FORM_WARNING_TEXT_COLOR);
            m_warningTextFrm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));
            m_warningTextFrm->setBounds(0, 0, m_editor->getSize().width, 0);
            m_warningTextFrm->setAnchor(0, 1.0f);
            setEditorSize(m_editor->getSize());
            m_warningTextFrm->setPos(m_editor->getPos().x, getSize().height);
            m_warningTextFrm->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_warningTextFrm->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_warningTextFrm->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_NONE, 
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
        }
        m_warningTextFrm->setString(text);
    }
}

VfxWString VcpFormTextEditor::getWarningText() const
{
    if(m_warningTextFrm)
    {
        return m_warningTextFrm->getString();
    }
    else
    {
        return VFX_WSTR_EMPTY;
    }
}

VcpTextEditor *VcpFormTextEditor::getEditor() const
{
    return m_editor;
}

void VcpFormTextEditor::setEditorSize(const VfxSize &size)
{    
    setEditorSize(size.width, size.height);
}

void VcpFormTextEditor::setEditorSize(VfxS32 w, VfxS32 h)
{
    m_editor->setSize(w,h);    
    if(m_warningTextFrm)
    {        
       m_warningTextFrm->setBounds(0, 0, m_editor->getSize().width, 0);

       m_warningTextFrm->setPos(m_editor->getPos().x, getSize().height);
       h += VCPFRM_ITEM_HORZ_GAP_1+ m_warningTextFrm->getSize().height;
    }    
    setSize(w,h);    
}

VfxSize VcpFormTextEditor::getEditorSize() const
{
    return m_editor->getSize();
}

