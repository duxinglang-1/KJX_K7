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
 *  vapp_cube_vip_contact_list_ctrl.cpp
 *
 * Project:
 * --------
 *  list ctrl class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_cube_vip_contact_list_ctrl.h"

    #include "vcp_scrollable.h"
    #include "vfx_frame.h"
    #include "vfx_cpp_base.h"
    #include "vfx_object.h"
    #include "vfx_sys_memory.h"
    #include "vfx_class_info.h"
    #include "vfx_control.h"
    #include "vfx_datatype.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_basic_type.h"
    #include "vfx_text_frame.h"
    #include "vrt_datatype.h"
    #include "vfx_input_event.h"
    #include "vfx_signal.h"
    #include "vfx_string.h"
    #include "vfx_font_desc.h"
    #include "vfx_animation.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
    

/***************************************************************************** 
 * Global function
 *****************************************************************************/

/***************************************************************************** 
 * UI componet: List control
 *****************************************************************************/
VappScrollCtrl::VappScrollCtrl() : VcpScrollable()
{

};

VfxFrame *VappScrollCtrl::getFirstItem()
{
	return m_view->getFirstChildFrame();
}

VfxFrame *VappScrollCtrl::getLastItem()
{
	return m_view->getLastChildFrame();
}


/***************************************************************************** 
 * UI componet: List control
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("ListCtrlItem", VappListCtrlItem, VfxControl);

VappListCtrlItem::VappListCtrlItem() :
	m_frmImage(NULL),
	m_frmText(NULL),
	m_pUserData(NULL),
	m_nTxtStart(0XFFFF)
{
    
}

void VappListCtrlItem::onInit()
{	
	VfxControl::onInit();

	VFX_OBJ_CREATE(m_frmImage, VfxImageFrame, this);
	m_frmImage->setAnchor(VfxFPoint(0.5, 0.5));
	
	VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);
	m_frmText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_frmText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_frmText->setColor(VFX_COLOR_WHITE);
}

VfxBool VappListCtrlItem::onPenInput(VfxPenEvent & event)
{

	switch(event.type)
	{
	case VFX_PEN_EVENT_TYPE_DOWN:
		break;

	case VFX_PEN_EVENT_TYPE_MOVE:
		{
			VfxPoint ptDown = event.getRelDownPos(this);
			VfxPoint ptMove = event.getRelPos(this);
			if (VFX_ABS(ptMove.y - ptDown.y) > 5) // VscrollableView::FREE_RUN_START_MOVE_THRESHOLD
			{
				// handle out capture
				getParentControl()->capture();
			}
		}
		break;
		
	case VFX_PEN_EVENT_TYPE_UP:
		
		m_signalSel.emit(m_pUserData);
		break;
		
	default:
		break;
	}

	return VFX_FALSE;
}

void VappListCtrlItem::update(VfxS32 margin)
{
	// make image at the center.
	m_frmImage->setPos(VfxPoint(margin / 2, getBounds().getHeight() / 2));

	VfxSize size = m_frmText->getMeasureBounds().size;
	VfxS32 h = (getBounds().getHeight() - size.height) / 2;

	// no Image.
	if (m_frmImage->getResId() == 0)
	{
		m_frmText->setPos(VfxPoint(TEXT_POS_X, h));
	}
	else
	{
		m_frmText->setPos(VfxPoint(margin, h));
	}	

	VfxRect bounds ;
	bounds.size.width = getBounds().getWidth() - margin;
	bounds.size.height = getBounds().getHeight();
	m_frmText->setBounds(bounds);
}

void VappListCtrlItem::setTextStartPos(const VfxS32 &x)
{
	m_nTxtStart = x;
}

void VappListCtrlItem::setContent(const VfxS32 &imgId, const VfxWString &text)
{	
	m_frmImage->setResId(imgId);
	m_frmText->setString(text);
	
	update(m_nTxtStart);
}


void VappListCtrlItem::getText(VfxWString &text) const
{
	text = m_frmImage->getSrc();
}

void VappListCtrlItem::setData(void* data)
{
	m_pUserData = data;
}
void* VappListCtrlItem::getData(void) const
{
	return m_pUserData;
}

void VappListCtrlItem::setFont(const VfxFontDesc &font)
{
	m_frmText->setFont(font);
}

/***************************************************************************** 
 * UI componet: List control
 *****************************************************************************/
VappListCtrl::VappListCtrl(const VfxBool &scroll) :
	m_cpScroll(NULL),
	m_tlPoint(NULL),
	m_frmCurr(NULL),
	m_frmHilite(NULL),
	m_imgBg(NULL),
	m_uCount(0),
	m_bShifting(VFX_FALSE),
	m_itemFont(VFX_FONT_DESC_SMALL),
	m_clrTxt(VFX_COLOR_BLACK),
	m_bScroll(scroll)
{

}

void VappListCtrl::onInit()
{
	VfxControl::onInit();

	VFX_OBJ_CREATE(m_tlPoint, VfxPointTimeline, this);
	m_tlPoint->m_signalStopped.connect(this, &VappListCtrl::onTimelineStop);
	
	if (m_bScroll)
	{
		VFX_OBJ_CREATE(m_cpScroll, VappScrollCtrl, this);
		m_cpScroll->setBgColor(VRT_COLOR_TRANSPARENT);
	}
	else
	{
		VFX_OBJ_CREATE(m_frmHilite, VfxFrame, this);
		m_frmHilite->setAutoAnimate(VFX_TRUE);
	}
	
    m_signalBoundsChanged.connect(this, &VappListCtrl::onBoundsValueChange);
}

void VappListCtrl::onAddChild(VfxObject * objChild)
{
	if (m_cpScroll != NULL && objChild != m_cpScroll)
	{
	    m_cpScroll->addChild(objChild);
		return;
	}
	
	VfxControl::onAddChild(objChild);
}
void VappListCtrl::onDeinit()
{
	m_tlPoint->m_signalStopped.disconnect(this, &VappListCtrl::onTimelineStop);
	m_signalBoundsChanged.disconnect(this, &VappListCtrl::onBoundsValueChange);

	VfxControl::onDeinit();
}

VfxU16 VappListCtrl::insertItem(const LC_ITEM &item)
{	
	m_uCount++;
	
	VappListCtrlItem *prevItem;
	if (m_cpScroll != NULL)
	{
		prevItem = VFX_OBJ_DYNAMIC_CAST(m_cpScroll->getLastItem(), VappListCtrlItem);
	}
	else
	{
		prevItem = VFX_OBJ_DYNAMIC_CAST(getLastChildFrame(), VappListCtrlItem);
	}
	
	VappListCtrlItem *newFrame;
	VFX_OBJ_CREATE(newFrame, VappListCtrlItem, this);
	newFrame->setFont(m_itemFont);
	
	VfxRect bounds;
	bounds = VfxRect(VFX_POINT_ZERO, VfxSize(getBounds().getWidth(), item.iItemHeight));
	newFrame->setBounds(bounds);
	VfxPoint point;
	// Insert to the next position.
	if (prevItem != NULL)
	{
		point = VfxPoint(0, prevItem->getPos().y + bounds.getMaxY());
	}

	newFrame->setPos(point);
	newFrame->setTextStartPos(item.iImageWidth);
	newFrame->setContent(item.imgId, item.string);
	newFrame->setData(item.userData);
	
	newFrame->m_signalSel.connect(this, &VappListCtrl::onItemSel);
	if (m_cpScroll != NULL)
	{
		// reset scroll bar's content size
		VfxU8 y = point.y + bounds.getMaxY() + MARGIN;
		m_cpScroll->setContentSize(VfxSize(bounds.getWidth(), y));
	}

	return m_uCount;
}

VfxS8 VappListCtrl::getCurrSel(void) const
{
	if (m_frmHilite == NULL)
	{
		return -1;
	}
	
	VfxS8 pos = -1;
	VfxBool bFound = VFX_FALSE;
	VfxFrame *frame = m_frmHilite->getNextFrame();
	VfxPoint point;
	
	// if highlight frame is moving, get the ToValue as the position of Hilite frame
	if (m_bShifting)
	{
		point = m_tlPoint->getToValue();
	}
	else
	{
		point = m_frmHilite->getPos();
	}
	
	while(frame != NULL)
	{
		pos++;
		if (frame->getPos() == point)
		{
			bFound = VFX_TRUE;
			break;
		}
		frame = frame->getNextFrame();
	}
	
	return (bFound ? pos : -1);
}

void VappListCtrl::setCurrSel(const VfxU8 & pos)
{
	if (m_frmHilite == NULL)
	{
		return;
	}
	
	VfxFrame *frame, *prevFrame;
	VfxU8 posFrame = pos;

	prevFrame = NULL;
	// highlight frame is under all list items
	frame = m_frmHilite->getNextFrame();
	while((frame != NULL) && posFrame > 0)
	{
		prevFrame = frame;
		frame = frame->getNextFrame();
		posFrame--;
	}

	if (frame == NULL)
	{
		frame = prevFrame;
	}

	m_frmHilite->setPos(frame->getPos());
	
	shiftItem(m_frmHilite, 0, frame->getPos().y - m_frmHilite->getPos().y);
	m_frmHilite->setHidden(VFX_FALSE);
}

void VappListCtrl::shiftItem(VfxFrame *target, const VfxS32 &xOffset, const VfxS32 &yOffset)
{
	if (xOffset == 0 && yOffset == 0)
	{
		return;
	}
	
	m_tlPoint->setTarget(target);
	
	VfxPoint point = target->getPos();
	m_tlPoint->setFromValue(point);
	point.x += xOffset;
	point.y += yOffset;
	
	m_tlPoint->setToValue(point);
	m_tlPoint->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
	m_tlPoint->setDurationTime(250);
	m_tlPoint->setRepeatCount(1);
	
	m_tlPoint->start();
}

VfxBool VappListCtrl::onPenInput(VfxPenEvent & event)
{
	VfxFrame *frame;
	
	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
			frame = hitTestChild(event.getRelPos(this));
			if (frame != NULL && m_frmHilite != NULL)
			{
				m_frmCurr = frame;
				// maybe change bounds has better fancy than shift item.
				shiftItem(m_frmHilite, 0, frame->getPos().y - m_frmHilite->getPos().y);
				m_frmHilite->setPos(0, frame->getPos().y);
				m_bShifting = VFX_TRUE;
				
				return VFX_TRUE;
			}	
			break;
			
		case VFX_PEN_EVENT_TYPE_UP:
			frame = hitTestChild(event.getRelPos(this));
			if (frame != NULL)
			{
				VappListCtrlItem *itemFrame = VFX_OBJ_DYNAMIC_CAST(frame, VappListCtrlItem);
				if (itemFrame != NULL)
				{
					m_signalSelChange.emit(itemFrame->getData());
				}
			}
			if (m_frmCurr != NULL)
			{
				m_frmCurr = NULL;	
				return VFX_TRUE;
			}
			break;
			
		default:
			break;
	}

	return VfxControl::onPenInput(event);
}


void VappListCtrl::setTextColor(const VfxColor & color)
{
	m_clrTxt = color;
}

void VappListCtrl::setHighlightRes(const VfxS32 & resId)
{
	if (!m_bScroll && m_frmHilite != NULL)
	{
		VfxImage *image;
		VFX_OBJ_CREATE(image, VfxImage, m_frmHilite);
		m_frmHilite->setHidden(VFX_FALSE);
		image->setResId(resId);
		m_frmHilite->setContent(image);
		m_frmHilite->setIsCached(VFX_TRUE);
		m_frmHilite->setBounds(VfxRect(VFX_POINT_ZERO, image->getSize()));
	}
}
void VappListCtrl::setFont(const VfxFontDesc &font)
{
	m_itemFont = font;
}
void VappListCtrl::clearAll(void)
{
	VfxFrame *frame, lastFrame;

	if (m_cpScroll != NULL)
	{
		while(frame = m_cpScroll->getFirstItem())
		{
			frame->close();
		}
	}
	else
	{
		while((frame = getLastChildFrame()) && frame != m_frmHilite)
		{
			frame->close();
		}
	}

	m_uCount = 0;
}

void VappListCtrl::onItemSel(void * usrData)
{
	m_signalSelChange.emit(usrData);
}

VfxFrame *VappListCtrl::hitTestChild(const VfxPoint & point) const
{
    if (!containPoint(point))
    {
        return NULL;
    }
    
    // TODO: tail recursion can change to while loop
    // Reversed check whatever a child frame contains the point
    VfxFrame *itr;
	if (m_cpScroll != NULL)
	{
		return NULL; // Scrollable can't accept Pen Event
	}
	else
	{
		itr = getLastChildFrame();
	}
    for (; itr != NULL; itr = itr->getPrevFrame())
    {
        // Ignore hidden frames
        if (!itr->getHidden())
        {
        	VfxPoint child_pos = convertPointTo(point, itr);
            if (itr->containPoint(child_pos))
            {
                return itr;
            }
        }
    }

    // No child frame contains the point, return this frame
    return NULL;
}

void VappListCtrl::onTimelineStop(VfxBaseTimeline *source, VfxBool stop)
{
	m_bShifting = VFX_FALSE;
}

void VappListCtrl::onBoundsValueChange(VfxFrame * source, const VfxRect & oldBounds)
{
	VFX_ASSERT(source == this);

	if (m_cpScroll != NULL)
	{
		VfxRect rect = getBounds();
	
		m_cpScroll->setPos(VfxPoint(0, 0));
	    m_cpScroll->setBounds(rect);
	    m_cpScroll->setContentSize(VfxSize(rect.getWidth(), rect.getHeight()));
	    m_cpScroll->setViewRect(rect);
	}
}
