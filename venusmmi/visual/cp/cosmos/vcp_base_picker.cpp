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
 *  vcp_base_picker.cpp
 *
 * Project:
 * --------
 *  A basic picker for FTO picker
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vcp_base_picker.h"
#include "vfx_cpp_base.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vcp_wheel_menu.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
#include "vfx_primitive_frame.h"
#include "mmi_rp_srv_venus_component_base_picker_def.h"

/***************************************************************************** 
 * Class VcpBasePickerField
 *****************************************************************************/

VcpBasePickerField::VcpBasePickerField() :
    m_fieldIndex(-1),
    m_dataType(VCP_PICKER_DATA_TYPE_STRING),
    m_cellHeight(1),
    m_isLoop(VFX_FALSE),
    m_realCellCount(0),
    m_realFocus(-1),
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
    m_stringAlignMode(VCP_PICKER_STRING_ALIGN_MODE_LEFT),
#endif
    m_textFont(VFX_FONT_DESC_MEDIUM),
#ifdef	__MMI_VUI_COSMOS_CP__
	m_textColor(VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_TXT)),
#else
    m_textColor(VfxColor(255, 123, 123 , 123)),
#endif
    m_resetTimer(NULL)
{}

void VcpBasePickerField::onInit()
{
    VcpWheelMenu::onInit();
}

void VcpBasePickerField::resetCells()
{
	VfxS32 i;
	
	m_defaultAnimationBackup = getDefaultAnimTime();
	setDefaultAnimTime(0);
	
	for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
	{
		VcpWheelMenu::resetCell(i);
	}
	m_realFocus = -1;
	this->update();
	
}

VfxFrame* VcpBasePickerField::createCell(VfxS32 cell, VfxS32 subcell)
{
    //if (m_dataType == VCP_PICKER_DATA_TYPE_STRING)
    IVcpBasePickerContentProvider *contentProvider = ((VcpBasePicker *) getParent())->m_contentProvider;
    if (contentProvider->getFieldDatatype(m_fieldIndex) == VCP_PICKER_DATA_TYPE_STRING)
    {
        VfxFrame *cellBlock;
        VFX_OBJ_CREATE(cellBlock, VfxFrame, this);
        cellBlock->setBounds(0, 0, getSize().width, m_cellHeight);
        cellBlock->setAnchor(0.5f, 0.5f);

        VfxTextFrame* item;
        VFX_OBJ_CREATE(item, VfxTextFrame, cellBlock);
        
        item->setBounds(0, 0, getSize().width, m_cellHeight);
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        if (m_stringAlignMode == VCP_PICKER_STRING_ALIGN_MODE_LEFT)
        {
            item->setAnchor(0, 0.5f);
            item->setPos(0, m_cellHeight/2);
        }
        else if (m_stringAlignMode == VCP_PICKER_STRING_ALIGN_MODE_CENTER)
        {
            item->setAnchor(0.5f, 0.5f);
            item->setPos(getSize().width/2, m_cellHeight/2);
        }
        else if (m_stringAlignMode == VCP_PICKER_STRING_ALIGN_MODE_RIGHT)
        {
            item->setAnchor(1.0f, 0.5f);
            item->setPos(getSize().width, m_cellHeight/2);
        }
#else
			item->setAnchor(0.5f, 0.5f);
            item->setPos(getSize().width/2, m_cellHeight/2);
#endif
       
        item->setFont(m_textFont);
        item->setColor(m_textColor);
        item->setFullLineHeightMode(VFX_TRUE);

        if (m_isLoop)
        {
            item->setString(contentProvider->onGetFieldString(m_fieldIndex, cell % m_realCellCount));
        }
        else
        {
            item->setString(contentProvider->onGetFieldString(m_fieldIndex, cell));
        }
        
		return cellBlock;
    }
    else
    {
        VfxFrame *item = contentProvider->onGetFieldFrame(m_fieldIndex, cell);
		return item;
    }    
}
    


void VcpBasePickerField::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    //if (m_dataType == VCP_PICKER_DATA_TYPE_STRING)
    IVcpBasePickerContentProvider *contentProvider = ((VcpBasePicker *) getParent())->m_contentProvider;
    if (contentProvider->getFieldDatatype(m_fieldIndex) == VCP_PICKER_DATA_TYPE_STRING)
    {
        VFX_UNUSED(cell);
        VFX_UNUSED(subcell);
        VFX_OBJ_CLOSE(cellFrame);
    }
    else
    {
        if (m_isLoop)
        {
            contentProvider->onFieldCloseCell(m_fieldIndex, cell % m_realCellCount, cellFrame);
        }
        else
        {
            contentProvider->onFieldCloseCell(m_fieldIndex, cell, cellFrame);
        }
    }
}


void VcpBasePickerField::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    if (m_isLoop)
    {
        ((VcpBasePicker *) getParent())->m_contentProvider->onFieldFocusIndexChange(m_fieldIndex, focusItem % m_realCellCount, previousFocusItem % m_realCellCount);
    }
    else
    {
        ((VcpBasePicker *) getParent())->m_contentProvider->onFieldFocusIndexChange(m_fieldIndex, focusItem, previousFocusItem);
    }
}


void VcpBasePickerField::setFocusIndex(VfxS32 index, VfxMsec animTime)
{
    VfxS32 preFocus = m_focus;
    
    if (m_isLoop)
    {
        // fisrt time to set focus
        if (m_realFocus == -1)
        {
            m_realCellCount =  ((VcpBasePicker *) getParent())->m_contentProvider->getFieldCellCount(m_fieldIndex);
            setFocus(((1 << 20) / m_realCellCount) * m_realCellCount + index, animTime);
            m_realFocus = index;
        }
        else
        {
            // find nearest path
            VfxS32 newFocus;
            newFocus = (index - m_realFocus + m_realCellCount) % m_realCellCount;
            if (newFocus > m_realCellCount/2)
            {
                newFocus -= m_realCellCount;
            }

            //setFocus(getFocus() + newFocus - m_realFocus, animTime);
            //m_realFocus = newFocus;

			setFocus(getFocus() + newFocus, animTime);
            m_realFocus = getFocus() % m_realCellCount;
        }    
    }
    else
    {
        setFocus(index, animTime);
    }

    if (preFocus != m_focus)
    {
        for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
        {
            VfxFrame* cellBlock = getCellIfPresent(i);
            if (cellBlock)
        	{
                // because cellBlock only one child
        		VfxTextFrame* item = (VfxTextFrame*)cellBlock->getFirstChildFrame();

        		item->setFont(m_textFont);
        		item->setColor(m_textColor);
        	}
        }

        if (animTime == -1)
        {
            animTime = 250;
        }
        else if (animTime < 0)
        {
           animTime = 0;
        }
        
        VFX_OBJ_CLOSE(m_resetTimer);

		if (animTime == 0)
		{
			resetCell();
		}
		else
		{   	
			VFX_OBJ_CREATE(m_resetTimer, VfxTimer, this); 
			m_resetTimer->m_signalTick.connect(this, &VcpBasePickerField::onResetTimerStop);
			m_resetTimer->setStartDelay(animTime);
			m_resetTimer->start();
		}
	}
}


VfxS32 VcpBasePickerField::getFocusIndex()
{
    if (m_isLoop)
    {
        return getFocus() % m_realCellCount;
    }
    else
    {
        return getFocus();
    }
}


void VcpBasePickerField::onResetTimerStop(VfxTimer *source)
{
    VFX_OBJ_CLOSE(m_resetTimer);

    resetCell();
}


void VcpBasePickerField::resetCell()
{
    VfxFrame* cellBlock = getCellIfPresent(getFocus());
    
    if (cellBlock)
	{
        // because cellBlock only one child
		VfxTextFrame* item = (VfxTextFrame*)cellBlock->getFirstChildFrame();

		item->setFont(m_focusTextFont);
		item->setColor(m_focusTextColor);
	}
}

void VcpBasePickerField::onDragStart()
{
	if (getDefaultAnimTime() == 0 && m_defaultAnimationBackup != 0)
	{
		setDefaultAnimTime(m_defaultAnimationBackup);
		m_defaultAnimationBackup = 0;
	}

    for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
    {
        VfxFrame* cellBlock = getCellIfPresent(i);
        if (cellBlock)
    	{
            // because cellBlock only one child
    		VfxTextFrame* item = (VfxTextFrame*)cellBlock->getFirstChildFrame();

    		item->setFont(m_textFont);
    		item->setColor(m_textColor);
    	}
    }
	VFX_OBJ_CLOSE(m_resetTimer);	
}

void VcpBasePickerField::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);
    
    if (yspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
        if (m_isLoop)
        {
            m_realFocus = getFocus() % m_realCellCount;
        }
        resetCell();
    }
    else
    {
        VfxS32   s      = yspeed > 0 ? 1 : -1;
        VfxFloat m      = VFX_ABS(yspeed) / 333.3f;
        
        if (m > 10) m = 10;
        
        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 100 * m);
        if (m_isLoop)
        {
            m_realFocus = getFocus() % m_realCellCount;
        }

        VFX_OBJ_CLOSE(m_resetTimer);
        VFX_OBJ_CREATE(m_resetTimer, VfxTimer, this); 
        m_resetTimer->m_signalTick.connect(this, &VcpBasePickerField::onResetTimerStop);
        m_resetTimer->setStartDelay(100 * m);
        m_resetTimer->start();
    }
}

void VcpBasePickerField::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(xoffset);
    setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / m_cellHeight, 0);
}


VfxS32 VcpBasePickerField::getCount()
{
    if (m_isLoop)
    {
        m_realCellCount =  ((VcpBasePicker *) getParent())->m_contentProvider->getFieldCellCount(m_fieldIndex);
        return (1 << 21);
    }
    else
    {
        return ((VcpBasePicker *) getParent())->m_contentProvider->getFieldCellCount(m_fieldIndex);
    }
}


VfxS32 VcpBasePickerField::getBehindCount()
{
    return (getSize().height - m_cellHeight)/m_cellHeight + 1;
}


VfxS32 VcpBasePickerField::getAheadCount()
{
    return (getSize().height - m_cellHeight)/m_cellHeight + 1;
}

vrt_render_dirty_type_enum VcpBasePickerField::myFrameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,   // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);

    VFX_DEV_ASSERT(target_frame != NULL);

    VfxS32 w = viewBounds.size.width / 2;
    VfxS32 h = viewBounds.size.height / 2;
    VfxPoint org = target_frame->pos;

    target_frame->pos.x = w;

    if (cellRelPos < -1)
    {
        target_frame->pos.y = h + (VfxS32) (((cellRelPos - (-1.0f)) * 0.7f + (-1.0f)) * target_frame->bounds.size.height);
    }
    else if (cellRelPos > 1)
    {
        target_frame->pos.y = h + (VfxS32) (((cellRelPos - (1.0f)) * 0.7f + 1.0f) * target_frame->bounds.size.height);
    }
    else
    {
        target_frame->pos.y = h + (VfxS32) (cellRelPos * target_frame->bounds.size.height);
    }

    target_frame->transform.data.affine.sy = 1.0f;

    VfxS32 baseY = target_frame->bounds.size.height/2;

    if (target_frame->pos.y < baseY)
    {
        target_frame->transform.data.affine.sy = -0.7f / (target_frame->bounds.size.height/2) * (baseY - target_frame->pos.y) + 1.0f;
    }

    baseY = viewBounds.size.height - target_frame->bounds.size.height/2;

    if (target_frame->pos.y > baseY)
    {
        target_frame->transform.data.affine.sy = -0.7f / (target_frame->bounds.size.height/2) * (target_frame->pos.y - baseY) + 1.0f;
    }
        
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

/***************************************************************************** 
 * Class VcpBasePicker
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VcpBasePicker", VcpBasePicker, VfxControl);

VcpBasePicker::VcpBasePicker() : 
    m_contentProvider(NULL),
    m_background(NULL), 
    m_fieldCount(0),
    m_fieldCellHeight(0)
{
    VfxS32 i;
    for (i = 0; i < 3; i++)
    {
        m_field[i] = NULL;
        m_fieldCellWidth[i] = 0;
        m_isDataLoop[i] = VFX_FALSE;
        m_fieldCellDataType[i] = VCP_PICKER_DATA_TYPE_STRING;
        m_fieldFocus[i] = 0;
        m_unitTextFrame[i] = NULL;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        m_fieldStringAlignMode[i] = VCP_PICKER_STRING_ALIGN_MODE_CENTER;
#ifdef __MMI_VUI_COSMOS_CP__
        m_fieldTextColor[i] = VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_TXT);
		m_fieldFocusTextColor[i] =  VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_FOCUS_TXT);
#else
		m_fieldTextColor[i] = VfxColor(255, 123, 123 , 123);
		m_fieldFocusTextColor[i] = VfxColor(255, 15, 15 , 15);
#endif
#endif
		m_fieldTextFont[i] = VFX_FONT_DESC_MEDIUM;
        m_fieldFocusTextFont[i] = VFX_FONT_DESC_MEDIUM;
    }
}


void VcpBasePicker::onInit()
{
    VfxControl::onInit();

    // background 
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_BASE_PICKER_BG));

    //m_fieldBackground

    VfxS32 i;
    for (i = 0; i < 3; i++)
    {
        VFX_OBJ_CREATE(m_fieldBackground[i], VfxFrame, this);
        m_fieldBackground[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_fieldBackground[i]->setImgContent(VfxImageSrc(VCP_IMG_BASE_PICKER_FIELD_BG));
    }
    // uintTextFrames
    for (i = 0; i < 3; i++)
    {
        if (m_unitTextFrame[i] == NULL)
        {
            VFX_OBJ_CREATE(m_unitTextFrame[i], VfxTextFrame, this);
            m_unitTextFrame[i]->setFont(VFX_FONT_DESC_MEDIUM);
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
#ifdef __MMI_VUI_COSMOS_CP__
			m_unitTextFrame[i]->setColor(VFX_COLOR_RES(CLR_COSMOS_BASE_PICKER_UNIT_TXT));
#else
			m_unitTextFrame[i]->setColor(VfxColor(255, 255, 255 , 255));
#endif
#endif
			
            m_unitTextFrame[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        }
    }

    // left arrow, right arrow, shadow;
    VFX_OBJ_CREATE(m_leftArrow, VfxImageFrame, this);
    m_leftArrow->setResId(VCP_IMG_BASE_PICKER_RIGHT_ARROW);
    m_leftArrow->setAnchor(0, 0.5);

    VFX_OBJ_CREATE(m_rightArrow, VfxImageFrame, this);
    m_rightArrow->setResId(VCP_IMG_BASE_PICKER_LEFT_ARROW);
    m_rightArrow->setAnchor(1, 0.5);

    VFX_OBJ_CREATE(m_shadowUp, VfxImageFrame, this);
    m_shadowUp->setResId(VCP_IMG_BASE_PICKER_SHADOW_UP);
    m_shadowUp->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shadowUp->setAnchor(0.5, 0);

    VFX_OBJ_CREATE(m_shadowDown, VfxImageFrame, this);
    m_shadowDown->setResId(VCP_IMG_BASE_PICKER_SHADOW_DOWN);
    m_shadowDown->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shadowDown->setAnchor(0.5, 1);
    
}


void VcpBasePicker::onUpdate()
{
    VfxS32 i;
    for (i = 0; i < 3; i++)
    {
        VFX_OBJ_CLOSE(m_field[i]);
        m_fieldBackground[i]->setHidden(VFX_TRUE);
        m_unitTextFrame[i]->setHidden(VFX_TRUE);
    }
    // please set contentProvider
    VFX_ASSERT(m_contentProvider);

    for (i = 0; i < m_fieldCount; i++)
    {
        VFX_OBJ_CREATE(m_field[i], VcpBasePickerField, this);
        m_field[i]->setFieldIndex(i);
        m_field[i]->setIsLoop(m_isDataLoop[i]);
        //m_field[i]->setRect(m_fieldRect[i]);
        m_field[i]->setRect(m_fieldRect[i].getX(), m_fieldRect[i].getY() + VCP_BASE_PICKER_FIELD_SHADOW, m_fieldRect[i].getWidth(), m_fieldRect[i].getHeight() - 2 * VCP_BASE_PICKER_FIELD_SHADOW);
        m_field[i]->setDataType(m_fieldCellDataType[i]);
        m_field[i]->setCellHeight(m_fieldCellHeight);
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        m_field[i]->setTextColor(m_fieldTextColor[i]);
        m_field[i]->setFocusTextColor(m_fieldFocusTextColor[i]);
 		m_field[i]->setStringAlignMode(m_fieldStringAlignMode[i]);
#endif
		m_field[i]->setFocusTextFont(m_fieldFocusTextFont[i]);
		m_field[i]->setTextFont(m_fieldTextFont[i]);
 

        m_fieldBackground[i]->setRect(m_fieldRect[i]);
        m_fieldBackground[i]->setHidden(VFX_FALSE);
    
        m_field[i]->setFocusIndex(m_fieldFocus[i], 0);
        m_field[i]->update();
    }
    
    // unit frame
    for (i = 0; i < m_fieldCount; i++)
    {
        m_unitTextFrame[i]->setAnchor(0.5, 0);
        m_unitTextFrame[i]->setPos(m_unitTextRect[i].origin.x + m_unitTextRect[i].size.width/2, m_unitTextRect[i].origin.y);
        m_unitTextFrame[i]->setBounds(0, 0, m_unitTextRect[i].size.width, m_unitTextRect[i].size.height);
        m_unitTextFrame[i]->bringToFront();        
        m_unitTextFrame[i]->setHidden(VFX_FALSE);
    }

    // left right arrow, up down shadow
	VfxS32 width = getSize().width;
    m_leftArrow->setPos(VCP_BASE_PICKER_MARGIN_WIDTH, m_fieldRect[0].origin.y + m_fieldRect[0].size.height/2);
    m_rightArrow->setPos(width - VCP_BASE_PICKER_MARGIN_WIDTH, m_fieldRect[0].origin.y + m_fieldRect[0].size.height/2);
    m_shadowUp->setPos(width/2, m_fieldRect[0].origin.y);
    m_shadowUp->setSize(width - 2 * VCP_BASE_PICKER_MARGIN_WIDTH, m_shadowUp->getSize().height);
    
    m_shadowDown->setPos(width/2, m_fieldRect[0].origin.y + m_fieldRect[0].size.height);
    m_shadowDown->setSize(width - 2 * VCP_BASE_PICKER_MARGIN_WIDTH, m_shadowUp->getSize().height);
}


VfxBool VcpBasePicker::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    VFX_UNUSED(aborter);
    VFX_UNUSED(reason);

    return VFX_FALSE;
}


void VcpBasePicker::setFieldCount(VfxS32 count)
{
    m_fieldCount = count;
    checkUpdate();
}


void VcpBasePicker::setBackground(VfxImageSrc img)
{
    m_background->setImgContent(img);
}

void VcpBasePicker::setFieldIsDataLoop(VfxS32 field, VfxBool value)
{
    if (field < m_fieldCount)
    {
        m_isDataLoop[field] = value;
        checkUpdate();
    }
}


VfxBool VcpBasePicker::getFieldIsDataLoop(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VFX_FALSE;
    }
    
    return m_isDataLoop[field];
}


void VcpBasePicker::setFieldDataType(VfxS32 field, VcpPickerDataType value)
{
    if (field < m_fieldCount)
    {
        m_fieldCellDataType[field] = value;
        checkUpdate();
    }
}


VcpPickerDataType VcpBasePicker::getFieldDataType(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VCP_PICKER_DATA_TYPE_STRING;
    }
    
    return m_fieldCellDataType[field];
}


void VcpBasePicker::setFieldFocus(VfxS32 field, VfxS32 focus, VfxMsec animTime)
{
    if (field < m_fieldCount)
    {
        if (m_field[field])
        {
            m_field[field]->setFocusIndex(focus, animTime);
            m_fieldFocus[field] = focus;
        }
        else
        {
            // The field not ready yet, store index and set it onUpdate()
            // This must be the first time set focus so we discard animTime 
            m_fieldFocus[field] = focus;
            checkUpdate();
        }
    }
}


VfxS32 VcpBasePicker::getFieldFocus(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return -1;
    }
    
    if (m_field[field])
    {
        return m_field[field]->getFocusIndex();
    }
    else
    {
        return m_fieldFocus[field];
    }
}
#ifndef __MMI_VUI_COSMOS_CP_SLIM__

void VcpBasePicker::setFieldTextFont(VfxS32 field, const VfxFontDesc &font)
{
    if (field < m_fieldCount)
    {
        m_fieldTextFont[field] = font;
        checkUpdate();
    }
}


VfxFontDesc VcpBasePicker::getFieldTextFont(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VFX_FONT_DESC_MEDIUM;
    }
    
    return m_fieldTextFont[field];
}


void VcpBasePicker::setFieldTextColor(VfxS32 field, VfxColor color)
{
    if (field < m_fieldCount)
    {
        m_fieldTextColor[field] = color;
        checkUpdate();
    }
}


VfxColor VcpBasePicker::getFieldTextColor(VfxS32 field)
{
    if (field >= m_fieldCount)
    {
        return VfxColor(VFX_COLOR_WHITE);
    }

    return m_fieldTextColor[field];
}


void VcpBasePicker::setFieldFocusTextFont(VfxS32 field, const VfxFontDesc &font)
{
    if (field < m_fieldCount)
    {
        m_fieldFocusTextFont[field] = font;
        checkUpdate();
    }
}


VfxFontDesc VcpBasePicker::getFieldFocusTextFont(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VFX_FONT_DESC_MEDIUM;
    }
    
    return m_fieldFocusTextFont[field];
}


void VcpBasePicker::setFieldFocusTextColor(VfxS32 field, VfxColor color)
{
    if (field < m_fieldCount)
    {
        m_fieldFocusTextColor[field] = color;
        checkUpdate();
    }
}


VfxColor VcpBasePicker::getFieldFocusTextColor(VfxS32 field)
{
    if (field >= m_fieldCount)
    {
        return VfxColor(VFX_COLOR_WHITE);
    }

    return m_fieldFocusTextColor[field];
}


void VcpBasePicker::setFieldStringAlignMode(VfxS32 field, VcpPickerStringAlignMode mode)
{
    if (field < m_fieldCount)
    {
        m_fieldStringAlignMode[field] = mode;
        checkUpdate();
    }
}


VcpPickerStringAlignMode VcpBasePicker::getFieldStringAlignMode(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VCP_PICKER_STRING_ALIGN_MODE_LEFT;
    }
    
    return m_fieldStringAlignMode[field];
}

void VcpBasePicker::setUnitTextVisible(VfxS32 field, VfxBool value)
{
    if (field < m_fieldCount)
    {
        m_unitTextFrame[field]->setHidden(!value);
    }
}


VfxBool VcpBasePicker::getUnitTextVisible(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VFX_FALSE;
    }
    return !m_unitTextFrame[field]->getHidden();
}


void VcpBasePicker::setUnitTextString(VfxS32 field, const VfxWString &str)
{
    if (field < m_fieldCount)
    {
        m_unitTextFrame[field]->setString(str);
    }
}


VfxWString VcpBasePicker::getUnitTextString(VfxS32 field) const
{
    if (field > m_fieldCount)
    {
        return VFX_WSTR_NULL;
    }
    
    return m_unitTextFrame[field]->getString();
}


void VcpBasePicker::setUintTextFont(VfxS32 field, const VfxFontDesc &font)
{
    if (field < m_fieldCount)
    {
        m_unitTextFrame[field]->setFont(font);
    }
}

    
VfxFontDesc VcpBasePicker::getUintTextFont(VfxS32 field) const
{
    if (field > m_fieldCount)
    {
        return VFX_FONT_DESC_MEDIUM;
    }
    return m_unitTextFrame[field]->getFont();
}

    
void VcpBasePicker::setUintTextColor(VfxS32 field, VfxColor color)
{
    if (field < m_fieldCount)
    {
        m_unitTextFrame[field]->setColor(color);
    }
}


VfxColor VcpBasePicker::getUnitTextColor(VfxS32 field)
{
    if (field > m_fieldCount)
    {
        return VfxColor(VFX_COLOR_WHITE);
    }
    return m_unitTextFrame[field]->getColor();
}

#endif
void VcpBasePicker::setFieldInfo(const VcpBasePickerFieldInfo &info)
{
    VfxS32 index = info.index;
    if (index < m_fieldCount)
    {
        m_isDataLoop[index] = info.isDataLoop;
        //focus index
        setFieldFocus(index, info.focusIndex, 0);
#ifndef __MMI_VUI_COSMOS_CP_SLIM__        
		m_fieldFocusTextColor[index] = info.focusTextColor;
        m_fieldTextColor[index] = info.textColor;
		m_unitTextFrame[index]->setColor(info.unitTextColor);
#endif
		m_fieldTextFont[index] = info.textFont;
        m_fieldFocusTextFont[index] = info.focusTextFont;
		m_unitTextFrame[index]->setFont(info.unitTextFont);

        m_unitTextFrame[index]->setHidden(!info.unitTextVisible);
        m_unitTextFrame[index]->setString(info.unitTextString);

        checkUpdate();
    }
}


void VcpBasePicker::resetFieldCells(VfxS32 field)
{
	if (field < m_fieldCount && m_field[field] != NULL)
	{
		m_field[field]->resetCells();
	}
}
