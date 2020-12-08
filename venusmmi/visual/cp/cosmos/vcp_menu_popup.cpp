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
*  vcp_menu_popup.cpp
*
* Project:
* --------
*  VenusMMI
*
* Description:
* ------------
*  Menu Popup
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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
#include "vcp_menu_popup.h"
#include "mmi_rp_srv_venus_component_menu_popup_def.h"

#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_base_popup.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_frame_aligner.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_screen.h"
#include "vcp_base_menu.h"
#include "vadp_sys_trc.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/* text frame right gap due to highlight size */
#define TEXT_RIGHT_GAP 5 
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
* Define
*****************************************************************************/

/***************************************************************************** 
 * class VcpMenuPopupBaseMenuLayout
 *****************************************************************************/
VcpMenuPopupBaseMenuLayout::VcpMenuPopupBaseMenuLayout(VcpBaseMenu* menu) : 
VcpBaseMenuLayout(menu) 
{}

void VcpMenuPopupBaseMenuLayout::onInit()        
{
    VcpBaseMenuLayout::onInit();

    m_cellWidth = 0;
    m_cellHeight = VCP_MENU_POPUP_CELL_HEIGHT;        
    m_cellCount = 0;
}

VcpMenuPopupBaseMenuLayout::ScrollDirEnum VcpMenuPopupBaseMenuLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}

VfxS32 VcpMenuPopupBaseMenuLayout::getGroupCount()
{
    return 1;
}

VfxS32 VcpMenuPopupBaseMenuLayout::getCellCount(VfxS32 group)
{
    VFX_UNUSED(group);
    return m_cellCount;
}

VfxS32 VcpMenuPopupBaseMenuLayout::getContentLength()
{
    return m_cellCount * m_cellHeight;
}

VcpMenuRegion VcpMenuPopupBaseMenuLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
        getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
}

VcpMenuPos VcpMenuPopupBaseMenuLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    p.group = 0;
    p.pos = pt.y / m_cellHeight;        
    return p;
}    

// Return a cell rect
VfxRect VcpMenuPopupBaseMenuLayout::queryCellRect(VcpMenuPos pos)
{            
    return VfxRect(0, pos.pos * m_cellHeight, m_cellWidth, m_cellHeight);
}

void VcpMenuPopupBaseMenuLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = 0;
    margin[1] = m_cellHeight;
    margin[2] = 0;
    margin[3] = m_cellHeight;
}

VfxBool VcpMenuPopupBaseMenuLayout::navDir(NavDirEnum dir)
{
    // Igore left and right
    if (!((dir == NAV_DIR_UP) || (dir == NAV_DIR_DOWN)))
    {
        return VFX_FALSE;
    }

    VcpMenuRegion visibleRegion = queryRegion(m_viewRect);

    VcpMenuPos pos = (dir == NAV_DIR_UP) ? (visibleRegion.begin) : (visibleRegion.end);
    VcpMenuPos newPos = pos.getPrevPos(this, VFX_TRUE);
    if (dir == NAV_DIR_UP)
    {
        newPos = pos.getPrevPos(this, VFX_TRUE);                
    }
    else
    {
        newPos = pos.getNextPos(this, VFX_TRUE);
    }
    VfxRect targetRect = m_viewRect;
    vcpBaseMenuNavDirHelper(this->m_pMenu, this, dir, pos, newPos, targetRect);
    m_pMenu->makeVisible(targetRect, VFX_TRUE);
    return VFX_TRUE;
}

VfxS32 VcpMenuPopupBaseMenuLayout::getCellNum() const
{
    return m_cellCount;
}

void VcpMenuPopupBaseMenuLayout::setCellNum(VfxS32 num)
{
    if (num < 0)
    {
        num = 0;
    }
    m_cellCount = num;
}

const VfxSize VcpMenuPopupBaseMenuLayout::getCellSize() const
{
    return VfxSize(m_cellWidth, m_cellHeight);
}

void VcpMenuPopupBaseMenuLayout::setCellSize(const VfxSize &cellSize)
{
    m_cellWidth = cellSize.width;
    m_cellHeight = cellSize.height;
}



/***************************************************************************** 
 * class VcpMenuPopupItem
 *****************************************************************************/
VcpMenuPopupItem::VcpMenuPopupItem():
m_id(0),
m_textFrame(NULL),
m_icon(NULL)
{ }

void VcpMenuPopupItem::onInit()
{
    VfxControl::onInit();
    setSize(100,0);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE)));

    m_textFrame->setColor(VCP_MENU_POPUP_CELL_N_TEXT_COLOR);
    m_textFrame->setAnchor(0, 0.5f);

    VFX_OBJ_CREATE(m_separator, VfxFrame, this);
    m_separator->setSize(getSize().width, VCP_MENU_POPUP_SEP_LINE_HEIGHT);       
    m_separator->setPos(0, getSize().height - m_separator->getSize().height);

    m_separator->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_SEP_LINE));
    m_separator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_separator->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

    checkUpdate();
}

void VcpMenuPopupItem::setText(VfxResId resId)
{
    setText(VFX_WSTR_RES(resId));
}

void VcpMenuPopupItem::setText(const VfxWChar *mem)
{
    setText(VFX_WSTR_MEM(mem));
}

void VcpMenuPopupItem::setText(const VfxWString &str)
{
    m_text = str; 
    m_textFrame->setString(m_text);
    checkUpdate();
}

VfxWString VcpMenuPopupItem::getText() const
{
    return m_text;
}    

void VcpMenuPopupItem::setBounds(const VfxRect &value)
{
    checkUpdate();
    VfxControl::setBounds(value);
}

void VcpMenuPopupItem::setIcon(const VfxImageSrc &img)
{
    if(img.isEmpty() || img.isNull())
    {
        if(m_icon)
        {
            VFX_OBJ_CLOSE(m_icon);
        }
        checkUpdate();
        return;
    }
    if(!m_icon)
    {
        VFX_OBJ_CREATE(m_icon, VfxFrame, this);
    }
    m_icon->setSize(img.getSize());
    m_icon->setImgContent(img);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    checkUpdate();
}

const VfxImageSrc &VcpMenuPopupItem::getIcon() const
{
    return m_icon->getImgContent();
}

void VcpMenuPopupItem::onUpdate()
{
    m_textFrame->setPos(0, getSize().height/2);
    m_textFrame->setMargins(VCP_MENU_POPUP_LEFT_CONTENT_MARGIN , 0, VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN , 0);
    if(m_icon)
    {        
        m_icon->setAnchor(1.0f, 0.5f);
        m_icon->setPos(getSize().width - VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN, getSize().height/2);        
        m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);

        m_textFrame->setSize(m_icon->getPos().x - m_icon->getSize().width , m_textFrame->getSize().height);     
    }
    else
    {
        m_textFrame->setSize(getSize().width, m_textFrame->getSize().height);
    }
    if(getIsDisabled())
    {
        setOpacity(0.3f);
    }
    else
    {
        setOpacity(1.0f);
    }
}


/***************************************************************************** 
 * class VcpMenuPopupItemType2
 *****************************************************************************/
VcpMenuPopupItemType2::VcpMenuPopupItemType2():
m_hintTextFrame(NULL),
m_hintPlacement(VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_RIGHT),
m_hintText(VFX_WSTR_EMPTY)
{ }

void VcpMenuPopupItemType2::onInit()
{
	VcpMenuPopupItem::onInit();
}

void VcpMenuPopupItemType2::setHintText(VfxResId resId)
{   
    setHintText(VFX_WSTR_RES(resId));
}

void VcpMenuPopupItemType2::setHintText(const VfxWChar *mem)
{
    setHintText(VFX_WSTR_MEM(mem));
}

void VcpMenuPopupItemType2::setHintText(const VfxWString &hint)
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
		m_hintTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_hintTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		m_hintTextFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE-4)));
		
		m_hintTextFrame->setColor(VCP_MENU_POPUP_CELL_HINT_TEXT_COLOR);
		m_hintTextFrame->setAnchor(0, 0.5f);		
	}
    m_hintText = hint;  
}

const VfxWString &VcpMenuPopupItemType2::getHintText()
{
	if(!m_hintTextFrame)
	{
		return m_hintText;
	}
	return m_hintTextFrame->getString();		
}

void VcpMenuPopupItemType2::setHintTextPlacement(VcpMenuPopupItemType2HintPlacement placement)
{
    m_hintPlacement = placement;
    
    checkUpdate();
}


VcpMenuPopupItemType2HintPlacement VcpMenuPopupItemType2::getHintTextPlacement() const
{
    return m_hintPlacement;
}


void VcpMenuPopupItemType2::setBounds(const VfxRect &value)
{
	// Overriding parent
    VcpMenuPopupItem::setBounds(value);
}

void VcpMenuPopupItemType2::onUpdate()
{
    // Overriding (not extending) parent
    
    VfxS32 available_width = getSize().width - VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN;
    VfxS32 x = VCP_MENU_POPUP_LEFT_CONTENT_MARGIN;

    if(m_icon)
    {        
        m_icon->setAnchor(0.0f, 0.5f);
        m_icon->setPos(x, getSize().height/2);        
        m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_NONE);
       
        x += m_icon->getSize().width + VCP_MENU_POPUP_ICON_TEXT_GAP;
        available_width = getSize().width - x;        
    }

    m_textFrame->setPos(x, getSize().height/2);

    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
    VfxRect textBounds= m_textFrame->getMeasureBounds();
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    m_textFrame->setSize(VFX_MIN(textBounds.size.width, available_width), m_textFrame->getSize().height);     

    if(m_hintTextFrame)
    {
        if(m_hintPlacement == VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_RIGHT)
        {
            VfxWString hintText = VFX_WSTR("(");
            hintText += m_hintText;
            hintText += VFX_WSTR(")");
            m_hintTextFrame->setString(hintText);  
            x += m_textFrame->getSize().width + VCP_MENU_POPUP_ICON_TEXT_GAP;
            available_width = getSize().width - x;
            m_hintTextFrame->setMargins(VCP_MENU_POPUP_ICON_TEXT_GAP , 0, VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN , 0);
        m_hintTextFrame->setPos(x, getSize().height/2);
        m_hintTextFrame->setSize(available_width, m_hintTextFrame->getSize().height);
    }
        else
        {      
            VfxWString hintText = m_hintText;
            m_hintTextFrame->setString(hintText);  
            m_textFrame->setPos(x, getSize().height/4);
            m_hintTextFrame->setMargins(0 , 0, 0 , 0);           
            m_hintTextFrame->setPos(x, (getSize().height*3)/4);
            
            m_hintTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
            VfxRect textBounds= m_hintTextFrame->getMeasureBounds();
            m_hintTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            
            m_hintTextFrame->setSize(VFX_MIN(textBounds.size.width, available_width), m_textFrame->getSize().height);
        }        
    }
    if(getIsDisabled())
    {
        setOpacity(0.3f);
    }
    else
    {
        setOpacity(1.0f);
    }
}

/***************************************************************************** 
* class VcpMenuPopup
*****************************************************************************/

VcpMenuPopup::VcpMenuPopup() : 
m_titleBg(NULL),
m_titleFrame(NULL),
m_titleText(VFX_WSTR_NULL),
m_layout(NULL),
m_menu(NULL),
m_background(NULL),
m_width(VCP_MENU_POPUP_WIDTH_POTRAIT),
m_maxVisibleCells(MAX_VISIBLE_CELLS_POTRAIT),
m_isAutoClose(VFX_TRUE),
m_isAutoCancel(VFX_TRUE),
m_closeButton(NULL)
{
}


void VcpMenuPopup::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpI", SA_start); 
#endif
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_BG));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsUnhittable(VFX_TRUE);
    m_background->setIsCached(VFX_TRUE);

    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_TITLE_BG));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_menu, VcpMenuPopupBaseMenu, this);
    m_layout = (VcpMenuPopupBaseMenuLayout*)m_menu->getLayout();

    m_menu->m_signalMenu.connect(this, &VcpMenuPopup::onMenuItemEvent);

    VfxScrRotateTypeEnum rotation = getTargetScreen()->getRotateType();	
    if (rotation == VFX_SCR_ROTATE_TYPE_0 || rotation == VFX_SCR_ROTATE_TYPE_180)
    {
        m_width = VCP_MENU_POPUP_WIDTH_POTRAIT;
        m_maxVisibleCells = MAX_VISIBLE_CELLS_POTRAIT;        
    }
    else
    {
        m_width = VCP_MENU_POPUP_WIDTH_LANDSCAPE;
        m_maxVisibleCells = MAX_VISIBLE_CELLS_LANDSCAPE;        
    }

    setRect(0,0, m_width, 0); 
    setAnchor(0.5f, 0.5f);    

    setIsAutoClose(VFX_TRUE);
    setIsAutoCancel(VFX_TRUE);        
    m_layout->setCellSize(VfxSize(m_menu->getSize().width, VCP_MENU_POPUP_CELL_HEIGHT));
    onUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpI", SA_stop); 
#endif
}
VfxBool VcpMenuPopup::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VFX_TRUE;
    }

    return VfxBasePopup::onPenInput(event);
}

void VcpMenuPopup::onPenInputOnOutside(VfxPenEvent &event)
{
    if (m_isAutoCancel)
    {   // auto close the menu if pen down outside

        // emit menu cancel signal

        VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_EMIT_CANCEL);
        m_signalMenuCallback.postEmit(this, VCP_MENU_POPUP_EVENT_MENU_CANCEL, NULL);

        //vfxPostInvoke1(this, &VcpMenuPopup::exit, VFX_TRUE);
        exit(VFX_TRUE);

        return;
    }

    VfxBasePopup::onPenInputOnOutside(event);
}

void VcpMenuPopup::onLeaveStack()
{
    // emit menu close signal
    VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_EMIT_CLOSE);
    m_signalMenuCallback.postEmit(this, VCP_MENU_POPUP_EVENT_MENU_CLOSE, NULL);         
}

void VcpMenuPopup::onExit()
{
    VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_EXIT);
    VfxBasePopup::onExit();
}


void VcpMenuPopup::onEnter()
{
    VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_ENTER);
    processUpdate();
    VfxBasePopup::onEnter();
}

VfxBool VcpMenuPopup::onKeyInput(VfxKeyEvent &event)
{
    switch (event.keyCode)
    {
    case VFX_KEY_CODE_BACK:

        // emit menu cancel signal
        VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_EMIT_CANCEL_FROM_BACKKEY);
        m_signalMenuCallback.postEmit(this, VCP_MENU_POPUP_EVENT_MENU_CANCEL, NULL);

        leave(VFX_TRUE);
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
    return VfxBasePopup::onKeyInput(event);
}


void VcpMenuPopup::onMenuItemEvent(VcpMenuPopupBaseMenu *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item)
{
    VFX_UNUSED(menu);

    if (event == VCP_MENU_POPUP_BASE_MENU_EVENT_ITEM_SELECTED)
    {
        VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_EMIT_ITEM_SELECTED, item->getId());
        m_signalMenuCallback.postEmit(this, VCP_MENU_POPUP_EVENT_ITEM_SELECTED, item);
        m_menu->m_signalMenu.disconnect(this, &VcpMenuPopup::onMenuItemEvent);

        // auto close the menu, must use post invoke
        if (getIsAutoClose())
        {
            //vfxPostInvoke1(this, &VcpMenuPopup::exit, VFX_TRUE);
            exit(VFX_TRUE);
        }
    }        
}

VcpMenuPopupItem *VcpMenuPopup::getItemById(VfxId id)
{
    VcpMenuPopupItem *item;
    VfxS32 i = 0;
    do
    {
        item = (VcpMenuPopupItem*)(m_menu->getCellByPos(i++));
        if(item->getId() == id)
        {              
            break;            
        }
    }
    while(item);
    return item;
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, VfxResId resId, VcpMenuPopupItemType itemType)
{
    return addItem(id, VFX_WSTR_RES(resId), itemType);
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, const VfxWChar *mem, VcpMenuPopupItemType itemType)
{
    return addItem(id, VFX_WSTR_MEM(mem), itemType);
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, VfxWString itemText, VcpMenuPopupItemType itemType)
{
    return addItem(id, itemText, VFX_IMAGE_SRC_NULL, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, VfxResId resId, VcpMenuPopupItemType itemType)
{
    return insertItem(id, afterId, VFX_WSTR_RES(resId), itemType);
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, const VfxWChar *mem, VcpMenuPopupItemType itemType)
{
    return insertItem(id, afterId, VFX_WSTR_MEM(mem), itemType);
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, VfxWString itemText, VcpMenuPopupItemType itemType)
{
    return insertItem(id, afterId, itemText, VFX_IMAGE_SRC_NULL, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, VfxResId resId, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    return addItem(id, VFX_WSTR_RES(resId), img, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, const VfxWChar *mem, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    return addItem(id, VFX_WSTR_MEM(mem), img, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::addItem(VfxId id, VfxWString itemText, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    VcpMenuPopupItem* newItem =  createMenuItem(id, itemText, itemType);
    VFX_DEV_ASSERT(newItem);
    insertItem(NULL, NULL, newItem);
    newItem->setIcon(img);
    return newItem;
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, VfxResId resId, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    return insertItem(id, afterId, VFX_WSTR_RES(resId), img, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, const VfxWChar *mem, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    return insertItem(id, afterId, VFX_WSTR_MEM(mem), img, itemType);
}

VcpMenuPopupItem *VcpMenuPopup::insertItem(VfxId id, VfxId afterId, VfxWString itemText, const VfxImageSrc &img, VcpMenuPopupItemType itemType)
{
    VcpMenuPopupItem* newItem =  createMenuItem(id, itemText, itemType);
    VFX_DEV_ASSERT(newItem);
    VcpMenuPopupItem *itemFrame = getItemById(afterId);
    insertItem(NULL, itemFrame, newItem);    
    newItem->setIcon(img);
    VFX_LOG(VFX_INFO2, VCP_MENUPOPUP_NEW_TEM_INSERTED, newItem->getId());	
    return newItem;        
}

void VcpMenuPopup::insertItem(
                              VcpMenuPopupItem* parent, 
                              VcpMenuPopupItem* insertAfterItem,
                              VcpMenuPopupItem* item)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpA", SA_start); 
#endif

    // force the item to be unhidden
    item->setHidden(VFX_FALSE);
    m_signalBoundsChanged.connect(item, &VcpMenuPopupItem::onMenuBoundsChange);
    //m_menu->addChild(item);

    // add into the menu view
    if (insertAfterItem == NULL)
    {
        m_menu->insertItemAsChildFrame((VfxFrame*)item);
    }
    else
    {
        insertAfterItem->getParentFrame()->insertChildFrameAfter(insertAfterItem, item);        
    }            

    // set size and hide it by the minus y pos (the correct pos will be set in update cell)
    item->setRect(0, m_layout->getCellCount(0)*m_layout->getCellSize().height, m_layout->getCellSize().width, m_layout->getCellSize().height);
    m_layout->setCellNum(m_layout->getCellNum() + 1);
    m_menu->update();
    item->setText(item->getText());
    item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);

    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpA", SA_stop); 
#endif	
	
}


void VcpMenuPopup::removeItem(VcpMenuPopupItem* item)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpR", SA_start); 
#endif	
    // move item frame to VcpMenuPopupBaseMenu to remove it from the view tree
    item->getParentFrame()->getParentFrame()->addChildFrame(item);

    if (!item->getHidden())
    {
        item->setHidden(VFX_TRUE);
        // decrease 1 item
        m_layout->setCellNum(m_layout->getCellNum() - 1);

        m_menu->update();
    }            
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpR", SA_stop); 
#endif	
	
}


void VcpMenuPopup::closeItem(VcpMenuPopupItem* item)
{
    if (!item->getHidden())
    {
        // decrease 1 item
        m_layout->setCellNum(m_layout->getCellNum() - 1);
        m_menu->update();
    }

    VFX_OBJ_CLOSE(item);
}

void VcpMenuPopup::setTitle(VfxResId resId)
{
    setTitle(VFX_WSTR_RES(resId));
}

void VcpMenuPopup::setTitle(const VfxWChar *mem)
{
    setTitle(VFX_WSTR_MEM(mem));
}

void VcpMenuPopup::setTitle(const VfxWString &title)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpT", SA_start); 
#endif	
    m_titleText = title;

    // lazy create title and close button
    if (!m_titleText.isNull() && !m_titleText.isEmpty())
    {
        if (m_titleFrame == NULL)
        {
            VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, m_titleBg);
            m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_titleFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_titleFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE), VFX_FE1_9));
            m_titleFrame->setColor(VCP_MENU_POPUP_TITLE_TEXT_COLOR);		

            m_titleFrame->setAnchor(0, 0.5);
            m_titleFrame->setMargins(TITLE_MARGIN_LEFT,0, TITLE_MARGIN_RIGHT,0);
            m_titleFrame->setPos(0, (m_titleBg->getSize().height + 1)/2);
            m_titleFrame->setSize(m_titleBg->getSize().width, m_titleFrame->getSize().height);        
            //m_titleFrame->setAutoResized(VFX_FALSE);
            m_titleFrame->setFullLineHeightMode(VFX_FALSE);
            m_titleFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_MID, 
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_MID);
        }
        m_titleFrame->setString(m_titleText);
    }
    else
    {   // set NULL or EMPY
        if (m_titleFrame)
        {
            VFX_OBJ_CLOSE(m_titleFrame);
        }            
        m_titleFrame = NULL;
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpT", SA_stop); 
#endif		
}

VcpMenuPopupItem* VcpMenuPopup::createMenuItem(
    VfxId itemId, 
    VfxResId resId,
    VcpMenuPopupItemType itemType)
{
    return createMenuItem(
        itemId, 
        VFX_WSTR_RES(resId),
        itemType);
}

VcpMenuPopupItem* VcpMenuPopup::createMenuItem(
    VfxId itemId, 
    const VfxWChar *mem,
    VcpMenuPopupItemType itemType)
{
    return createMenuItem(
        itemId, 
        VFX_WSTR_MEM(mem),
        itemType);
}

VcpMenuPopupItem* VcpMenuPopup::createMenuItem(
    VfxId itemId, 
    VfxWString itemText,
    VcpMenuPopupItemType itemType)
{
    VcpMenuPopupItem *item;

    if(itemType == VCP_MENU_POPUP_ITEM_TYPE_2)
    {
        VFX_OBJ_CREATE(item, VcpMenuPopupItemType2, this);
    }
    else
    {
    VFX_OBJ_CREATE(item, VcpMenuPopupItem, this);
    }

    item->setId(itemId);
    item->setText(itemText);    
    item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    return item;
}

void VcpMenuPopup::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_180)
    {
        m_width = VCP_MENU_POPUP_WIDTH_POTRAIT;
        m_maxVisibleCells = MAX_VISIBLE_CELLS_POTRAIT;        
    }
    else
    {
        m_width = VCP_MENU_POPUP_WIDTH_LANDSCAPE;
        m_maxVisibleCells = MAX_VISIBLE_CELLS_LANDSCAPE;        
    }

    onUpdate();
    VfxBasePopup::onRotate(param);
}

void VcpMenuPopup::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpU", SA_start); 
#endif	
    VfxS32 margin = MENU_MARGIN_TOP + MENU_MARGIN_BOTTOM;
    VfxS32 newPopupHeight;
    if (m_titleBg)
    {
        margin += MENU_TITLE_HEIGHT;
    }

    VfxS32 cellheight = m_layout->getCellSize().height;
    VfxS32 maxPopupHeight = margin + (m_maxVisibleCells*cellheight);// + (cellheight>>1);

    newPopupHeight = m_layout->getContentLength() + margin;

    newPopupHeight  = newPopupHeight < maxPopupHeight ? newPopupHeight  : maxPopupHeight;

    setSize(m_width, newPopupHeight);

    onSize();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpU", SA_stop); 
#endif		
}        

void VcpMenuPopup::onSize()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpS", SA_start); 
#endif	
    VfxS32 totalWidth, totalHeight;

    // center align to parent
    setPos(getTargetScreen()->getBounds().getMidPoint());
    totalWidth = getSize().width;
    totalHeight = getSize().height;

    if (m_titleBg)
    {     
        m_titleBg->setRect( 0, 0, totalWidth, MENU_TITLE_HEIGHT);        
    }

    // resize menu
    if (m_menu)
    {
        if (m_titleBg)
        {
            m_menu->setPos(MENU_MARGIN_LEFT, MENU_MARGIN_TOP + m_titleBg->getSize().height);        
        }
        else
        {
            m_menu->setPos(MENU_MARGIN_LEFT, MENU_MARGIN_TOP);
        }

        m_menu->setSize(totalWidth - (m_menu->getPos().x + MENU_MARGIN_RIGHT), totalHeight - (m_menu->getPos().y + MENU_MARGIN_BOTTOM));
        m_layout->setCellSize(VfxSize(m_menu->getSize().width, VCP_MENU_POPUP_CELL_HEIGHT));       
        m_menu->update();
    }
    if(m_background)
    {
        m_background->setSize(totalWidth, totalHeight - MENU_TITLE_HEIGHT);
        m_background->setPos(0, MENU_TITLE_HEIGHT);            
    }       
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("MpS", SA_stop); 
#endif		
}
/*****************************************************************************
* Class VcpMenuPopupBaseMenu
*****************************************************************************/

VfxFrame *VcpMenuPopupBaseMenu::getCellByPos(VfxS32 pos)
{
    VfxFrame *f;
    VfxS32 i = 0;

    if (pos < 0)
    {
        return NULL;
    }

    // get menu view frame
    f = getFirstChildFrame();
    if (!f)
    {
        return NULL;
    }

    for (f = f->getFirstChildFrame(); f; f = f->getNextFrame())
    {
        if (f->getHidden())
        {
            continue;
        }

        if (pos == i)
        {
            return f;
        }

        i++;
    }        

    /*
    * cannot find a cell by pos, this must be due to item deleting?
    * to prevent return a NULL item to make menu cache data abort, 
    * we return a valid frame here (not so sure, maybe no cell at all...)
    */
    return getFirstChildFrame();
    // return NULL;
}


void VcpMenuPopupBaseMenu::onInit()
{
    VcpBaseMenu::onInit();
    enableBoundaryLight(VFX_FALSE);
    createLayout();
}


void VcpMenuPopupBaseMenu::tapCell(
                                   VfxS32 group,
                                   VfxS32 pos,
                                   VfxFrame* cell
                                   )
{
    VfxU32 ret = 0;    

    VFX_UNUSED(group);
    VFX_UNUSED(pos);    

    // set the tapped cell focused
    // getLayout()->setFocusItem(VcpMenuPos(group, pos), VFX_FALSE);

    VcpMenuPopupItem *item = (VcpMenuPopupItem*)cell;


    // send tap event
    item->onEvent(VCP_MENU_POPUP_ITEM_EVENT_TAP, 0, &ret);

    m_signalMenu.postEmit(this, VCP_MENU_POPUP_EVENT_ITEM_SELECTED, (VcpMenuPopupItem*)cell);
}

void VcpMenuPopupBaseMenu::onUpdateCell(
                                        const VfxRect &rect,    // [IN] The position that layouter report
                                        VfxS32 group,           // [IN] The group index
                                        VfxS32 pos,             // [IN] The cell index in the group
                                        VfxFrame* cell,         // [IN] The cell object
                                        VfxU32 flag             // [IN] The state about this cell
                                        )
{
    VFX_UNUSED(rect);
    VFX_UNUSED(group);
    VFX_UNUSED(flag);
    // cell->setAutoAnimate(VFX_TRUE);
    // do not update cells inside the clip
    if ((cell != m_subGroupClip) && (cell->getParentFrame() != m_subGroupClip))
    {
        cell->setPos(0, pos * m_layout->getCellSize().height);
    }
}


void VcpMenuPopupBaseMenu::onFocusIndexChange(
    VcpMenuPos focusItem,
    VcpMenuPos previousFocusItem
    )
{
    VfxFrame *cell;

    // set focus item
    cell = getCellByPos(focusItem.pos);
    if (cell)
    {
        ((VcpMenuPopupItem*)cell)->onEvent(VCP_MENU_POPUP_ITEM_EVENT_SET_FOCUS, (VfxU32)VFX_TRUE, NULL);
    }            

    // unfocus previous focus item
    cell = getCellByPos(previousFocusItem.pos);
    if (cell)
    {
        ((VcpMenuPopupItem*)cell)->onEvent(VCP_MENU_POPUP_ITEM_EVENT_SET_FOCUS, (VfxU32)VFX_FALSE, NULL);
    }            
}


void VcpMenuPopupBaseMenu::onTouchCell(
                                       VcpMenuPos          cellPos,
                                       CellTouchTypeEnum   touchType,
                                       VfxPoint            pt,
                                       VfxFrame            *cell
                                       )
{
    VFX_UNUSED(pt);

    switch(touchType)
    {
    case TouchDown:
        getLayout()->setFocusItem(cellPos, VFX_FALSE);
        break;

    case TouchUp:
        getLayout()->clearFocusItem();
        break;

    case TouchTap:            
        // TouchTap will be invoked before TouchUp and tap might change the menu content.
        vfxPostInvoke3(this, &VcpMenuPopupBaseMenu::tapCell, cellPos.group, cellPos.pos, cell);
        break;

    default:
        break;
    }    
}


void VcpMenuPopupBaseMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpBaseMenu::onDrag(xoffset, yoffset);
    getLayout()->clearFocusItem();
}

void VcpMenuPopupBaseMenu::insertItemAsChildFrame(VfxFrame *itemFrm)
{
    m_view->addChildFrame(itemFrm);
}

/*****************************************************************************
* Class VcpMenuPopupItem
*****************************************************************************/

VfxBool VcpMenuPopupItem::onEvent(VcpMenuPopupItemEventEnum event, VfxU32 param, VfxU32 *ret)
{
    VfxBool isFocused;

    VFX_UNUSED(ret);

    if (param)
    {
        isFocused = VFX_TRUE;
    }
    else
    {
        isFocused = VFX_FALSE;
    }

    // handle set focus
    if (event == VCP_MENU_POPUP_ITEM_EVENT_SET_FOCUS)
    {        
        if (isFocused)
        {
            setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_HIGHLIGHT_ITEM_BACKGROUND));
            setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_textFrame->setColor(VCP_MENU_POPUP_CELL_H_TEXT_COLOR);
        }
        else
        {
            setImgContent(VfxImageSrc(VFX_IMAGE_SRC_TYPE_NULL));
            setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_textFrame->setColor(VCP_MENU_POPUP_CELL_N_TEXT_COLOR);
        }

        return VFX_TRUE;
    }            

    return VFX_FALSE;
}

void VcpMenuPopupItem::onMenuBoundsChange(VfxFrame *frm, const VfxRect &rect)
{
    setSize(frm->getSize().width, VCP_MENU_POPUP_CELL_HEIGHT);
    m_separator->setSize(frm->getSize().width, 2);
}


