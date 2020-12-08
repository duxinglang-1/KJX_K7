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
 *  vcp_option_menu.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Option menu
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
#include "vcp_option_menu.h"

extern "C"
{
// for menu resource APIs
#include "MMI_include.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "CustMenuRes.h"
}

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_base_popup.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vfx_image_src.h"
#include "vfx_signal.h"
#include "vcp_button.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_text_frame.h"
#include "vcp_base_menu.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"

#if defined(__MMI_MAINLCD_320X480__)
    // 320x480
    #define VCP_OPTION_MENU_DEFAULT_RECT 30, 83, 259, 360
#elif defined(__MMI_MAINLCD_240X400__)
    // 240x400
    #define VCP_OPTION_MENU_DEFAULT_RECT 18 - 10, 60 - 10, 204 + 20, 280 + 20
#else
    // 240x320
    #define VCP_OPTION_MENU_DEFAULT_RECT 18 - 10, 60 - 10, 204 + 20, 220 + 20
#endif

/* text frame right gap due to highlight size */
#define TEXT_RIGHT_GAP 5

/***************************************************************************** 
 * Define
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpOptionMenuRadioItem", VcpOptionMenuRadioItem, VcpOptionMenuCheckItem);
VFX_IMPLEMENT_CLASS("VcpOptionMenuTextItem", VcpOptionMenuTextItem, VcpOptionMenuItem);

/***************************************************************************** 
 * class VcpOptionMenu
 *****************************************************************************/
 
VcpOptionMenu::VcpOptionMenu() :
    m_titleBg(NULL),
    m_titleFrame(NULL),
    m_showCancelButton(VFX_TRUE),
    m_titleText(VFX_WSTR_NULL),
    m_layout(NULL),
    m_menu(NULL),
    m_background(NULL),
    m_closeButton(NULL),
    m_isAutoClose(VFX_TRUE),
    m_isAutoCancel(VFX_TRUE),
    m_cancelButton(NULL)
{
}


void VcpOptionMenu::onInit()
{
    VfxBasePopup::onInit();

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsUnhittable(VFX_TRUE);
    m_background->setIsCached(VFX_TRUE);

    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_TOP));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_menu, VcpOptionBaseMenu, this);
    m_layout = (VcpOptionBaseMenuLayout*)m_menu->getLayout();

    m_menu->m_signalMenu.connect(this, &VcpOptionMenu::onMenuItemEvent);

    // create and init cancel button
    VFX_OBJ_CREATE(m_cancelButton, VcpButton, this);
    m_cancelButton->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_cancelButton->setTextColor(VFX_COLOR_WHITE);
    m_cancelButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_cancelButton->m_signalClicked.connect(this, &VcpOptionMenu::onCloseButtonClick);
    #ifdef __MMI_VUI_COSMOS_CP__
        VcpStateImage SI = VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                                 );
    #else
         VcpStateImage SI = VcpStateImage(
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL,
                                                VCP_IMG_POPUP_BUTTON_PRESSED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_DISABLED,
                                                VCP_IMG_POPUP_BUTTON_CANCEL_NORMAL
                                                 );
    #endif
    m_cancelButton->setImage(SI);
	m_cancelButton->setMargin(6, 5, 7, 7);
    if (!m_showCancelButton)
    {
        m_cancelButton->setHidden(VFX_TRUE);
    }

    setRect(VCP_OPTION_MENU_DEFAULT_RECT); 
    setAnchor(0.5f, 0.5f);    
}


void VcpOptionMenu::onMenuItemEvent(VcpOptionBaseMenu *menu, VcpOptionBaseMenu::VcpOptionBaseMenuEventEnum event, VcpOptionMenuItem *item)
{
    VFX_UNUSED(menu);

    if (event == VcpOptionBaseMenu::MENU_EVENT_ITEM_SELECTED)
    {
        m_signalMenuCallback.postEmit(this, VCP_OPTION_MENU_EVENT_ITEM_SELECTED, item);

        // auto close the menu, must use post invoke
        if (getIsAutoClose())
        {
            vfxPostInvoke1(this, &VcpOptionMenu::closeMenu, VFX_TRUE);
        }
    }        
}


VfxBool VcpOptionMenu::loadFromRes(VfxResId menuId)
{
    VfxS32 i;
    VfxS32 itemCount;    
    U16 menu = (U16)menuId;

    // TODO: support loadFromRes anytime?    
    itemCount = (VfxS32)GetNumOfChild_Ext(menu);

    if (!itemCount)
    {
        return VFX_FALSE;
    }

    for (i = 0; i < itemCount; i++)
    {
        U16 id, subId = 0;
        VcpOptionMenuItem *optionItem;
        VfxS32 subGroupChildNum;

        // add first level items
        id = GetSeqItemId_Ext(menu, (U16)i);                    
        optionItem = createMenuItem((VfxId)id, VFX_WSTR_RES(GetStringIdOfItem(id)));  
        appendItem(NULL, optionItem);

        // add subgroup items
        subGroupChildNum = (VfxS32)GetNumOfChild_Ext(id);
        if (subGroupChildNum)
        {
            for (VfxS32 j = 0; j < subGroupChildNum; j++)
            {
                VcpOptionMenuItem *subItem;
            
                subId = GetSeqItemId_Ext(id, (U16)j);
                subItem = createMenuItem((VfxId)subId, VFX_WSTR_RES(GetStringIdOfItem(subId)));
                appendItem(optionItem, subItem);
            }
        }        
    }

    m_menu->update();
    
    return VFX_TRUE;
}


void VcpOptionMenu::appendItem(
    VcpOptionMenuItem* parent,  
    VcpOptionMenuItem* item)
{
    // force the item to be unhidden
    item->setHidden(VFX_FALSE);

    if (parent == NULL)
    {
      //  m_menu->addChild(item);
		m_menu->getFirstChildFrame()->addChildFrame(item); 
    }
    else
    {
        VfxFrame* f = NULL;
        
        parent->addChild(item);

        if (parent->getNextFrame())
        {
            if (((VcpOptionMenuItem*)parent->getNextFrame())->getParentMenuItem() == parent)
            {   // the parent item already has childs, find the last child to insert
                for (f = parent->getNextFrame(); f && (((VcpOptionMenuItem*)f)->getParentMenuItem() == parent); f = f->getNextFrame());
                if (f)
                {
                    f = f->getPrevFrame();
                }                    
            }
            else
            {   // the item is the first child of parent
                f = parent;
            }
        }
        
        if (f)
        {
            parent->getParentFrame()->insertChildFrameAfter(f, item);
        }
        else
        {   // add to the last
            parent->getParentFrame()->addChildFrame(item); 
        }
    }

    // set size and hide it by the minus y pos (the correct pos will be set in update cell)
    item->setRect(0, -m_layout->getCellSize().height, m_layout->getCellSize().width, m_layout->getCellSize().height);

    if (parent)
    {
        item->setHidden(VFX_TRUE);    
        item->setLevel(1);

        // display group indicator if the parent is a text item
        if (item->getParentItem()->isKindOf(VFX_OBJ_CLASS_INFO(VcpOptionMenuTextItem)))
        {
            ((VcpOptionMenuTextItem*)item->getParentItem())->enableSubGroupIndicator(VFX_TRUE);
        }
    }

    if (!item->getHidden())
    {
        m_layout->setCellNum(m_layout->getCellNum() + 1);
    }        

    m_menu->update();
}


void VcpOptionMenu::insertItem(
    VcpOptionMenuItem* parent, 
	VcpOptionMenuItem* insertAfterItem,
	VcpOptionMenuItem* item)
{
    // force the item to be unhidden
    item->setHidden(VFX_FALSE);

    if (parent == NULL)
    {
     //   m_menu->addChild(item);

        // add into the menu view
        if (insertAfterItem == NULL)
        {
            // insert item to the beginning
            item->getParentFrame()->getFirstChildFrame()->addChildFrame(item);
            item->sendToBack();            
        }
        else
        {
            item->getParentFrame()->getFirstChildFrame()->insertChildFrameAfter(insertAfterItem, item);        
        }            
    }
    else
    {
        // object tree to parent
        parent->addChild(item);

        parent->getParentFrame()->getFirstChildFrame()->insertChildFrameAfter(insertAfterItem, item);
    }

    // set size and hide it by the minus y pos (the correct pos will be set in update cell)
    item->setRect(0, -m_layout->getCellSize().height, m_layout->getCellSize().width, m_layout->getCellSize().height);

    if (parent)
    {
        item->setHidden(VFX_TRUE);    
        item->setLevel(1);

        // display group indicator if the parent is a text item
        if (item->getParentItem()->isKindOf(VFX_OBJ_CLASS_INFO(VcpOptionMenuTextItem)))
        {
            ((VcpOptionMenuTextItem*)item->getParentItem())->enableSubGroupIndicator(VFX_TRUE);
        }
    }

    if (!item->getHidden())
    {
        m_layout->setCellNum(m_layout->getCellNum() + 1);
    }

    m_menu->update();
}


void VcpOptionMenu::removeItem(VcpOptionMenuItem* item)
{
    // move item frame to VcpOptionBaseMenu to remove it from the view tree
    item->getParentFrame()->getParentFrame()->addChildFrame(item);

    if (!item->getHidden())
    {
        item->setHidden(VFX_TRUE);
        // decrease 1 item
        m_layout->setCellNum(m_layout->getCellNum() - 1);
        
        m_menu->update();
    }            
}


void VcpOptionMenu::closeItem(VcpOptionMenuItem* item)
{
    if (!item->getHidden())
    {
        // decrease 1 item
        m_layout->setCellNum(m_layout->getCellNum() - 1);
        m_menu->update();
    }

    VFX_OBJ_CLOSE(item);
}


void VcpOptionMenu::setTitle(const VfxWString &title)
{
    m_titleText = title;

    // lazy create title and close button
    if (!m_titleText.isNull() && !m_titleText.isEmpty())
    {
        if (m_titleFrame == NULL)
        {
            VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, this);
            m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

            // create close button
            VFX_OBJ_CREATE(m_closeButton, VcpButton, this);
        }

        // init title frame
        m_titleFrame->setAutoResized(VFX_TRUE);
        m_titleFrame->setString(m_titleText);
        m_titleFrame->setRect(0, TITLE_VERTICAL_GAP, m_menu->getSize().width - TITLE_CLOSE_BUTTON_WIDTH, TITLE_VERTICAL_GAP + m_titleFrame->getSize().height);
        m_titleFrame->setAutoResized(VFX_FALSE);
        // TODO: use theme
        m_titleFrame->setColor(VFX_COLOR_BLACK);

        // init close button
        m_closeButton->setRect(m_menu->getSize().width - TITLE_CLOSE_BUTTON_WIDTH, TITLE_VERTICAL_GAP, TITLE_CLOSE_BUTTON_WIDTH, m_titleFrame->getSize().height - TITLE_VERTICAL_GAP);
        m_closeButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
        // TODO: REMOVE ME
        // m_closeButton->setBgColor(VFX_COLOR_PURPLE);
        m_closeButton->m_signalClicked.connect(this, &VcpOptionMenu::onCloseButtonClick);

        VcpStateImage SI = VcpStateImage(VCP_IMG_OPTION_MENU_BUTTON_CLOSE_N, VCP_IMG_OPTION_MENU_BUTTON_CLOSE_P, 0, 0);

		m_closeButton->setImage(SI);
        m_closeButton->setIsAutoResized(VFX_TRUE);

        // TODO: enable close button?
        m_closeButton->setHidden(VFX_TRUE);
    }
    else
    {   // set NULL or EMPY
        if (m_titleFrame)
        {
            VFX_OBJ_CLOSE(m_titleFrame);
        }            
        m_titleFrame = NULL;
    }

    onSize();
}


void VcpOptionMenu::onCloseButtonClick(VfxObject* sender, VfxId id)
{
    VFX_UNUSED(sender);
    VFX_UNUSED(id);

    // close menu
    closeMenu();
}


VcpOptionMenuItem* VcpOptionMenu::createMenuItem(
    VfxId itemId, 
    VfxWString itemText,
    VfxImageSrc itemIcon)
{
    VcpOptionMenuTextItem *item;

    VFX_OBJ_CREATE(item, VcpOptionMenuTextItem, this);
    item->setId(itemId);
    item->setText(itemText);
    
    if (itemIcon != VFX_IMAGE_SRC_NULL)
    {
        item->setIcon(itemIcon);
    }        

    return (VcpOptionMenuItem*)item;
}


VcpOptionMenuItem* VcpOptionMenu::createRadioMenuItem(
    VfxId itemId, 
    VfxWString itemText,
    VfxBool checkedState,
    VfxImageSrc itemIcon,
    VfxImageSrc onImage,
    VfxImageSrc offImage,
    VcpOptionMenuRadioItem::VcpOptionMenuRadioItemStyleEnum style)
{
    VcpOptionMenuRadioItem *item;

    VFX_OBJ_CREATE(item, VcpOptionMenuRadioItem, this);

    item->setId(itemId);
    item->setText(itemText);
    
    if (itemIcon != VFX_IMAGE_SRC_NULL)
    {
        item->setIcon(itemIcon);
    }     

    item->setRadioImage(onImage, offImage);
    item->setStyle(style);
    item->setCheck(checkedState);

    return (VcpOptionMenuItem*)item;
}


VcpOptionMenuItem* VcpOptionMenu::createCheckMenuItem(
    VfxId itemId, 
    VfxWString itemText, 
    VfxBool checkedState,
    VfxImageSrc itemIcon)
{
    VcpOptionMenuCheckItem *item;

    VFX_OBJ_CREATE(item, VcpOptionMenuCheckItem, this);
    item->setId(itemId);
    item->setText(itemText);
    item->setCheck(checkedState);

    if (itemIcon != VFX_IMAGE_SRC_NULL)
    {
        item->setIcon(itemIcon);
    }

    return (VcpOptionMenuItem*)item;   
}


void VcpOptionMenu::autoResize()
{
    VfxS32 gap = BG_IMG_GAP_TOP + BG_IMG_GAP_BOTTOM;
    VfxS32 newMenuHeight;

    if (m_titleFrame)
    {
        gap += m_titleFrame->getSize().height;
    }

    if (m_showCancelButton)
    {
        gap += m_layout->getCellSize().height;
    }

    newMenuHeight = m_layout->getContentLength() + gap;
    
    if (newMenuHeight < getSize().height)
    {
        setSize(getSize().width, newMenuHeight);
    }
}        


/*****************************************************************************
 * Class VcpOptionBaseMenu
 *****************************************************************************/
 
VfxFrame *VcpOptionBaseMenu::getCellByPos(VfxS32 pos)
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
    	VcpOptionMenuItem *item = VFX_OBJ_DYNAMIC_CAST(f, VcpOptionMenuItem);
        if (f->getHidden() ) //|| item == NULL)
        {
            continue;
        }

        // check subgroup clip frame
        if (f == m_subGroupClip)
        {
            // folding, bypass all cells inside the clip
            if (m_subGroupClip->getBounds().getY() != 0)
            {
                continue;
            }

            // expanding, must consider cells inside the clip
            for (VfxFrame *s = m_subGroupClip->getFirstChildFrame(); s; s = s->getNextFrame())
            {
                if (pos == i)
                {
                    return s;
                }
                i++;
            }       

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
VfxS32 VcpOptionBaseMenu::getPosByCell(VfxFrame *cellFrame)
{
	VfxFrame *f;
	VfxS32 pos = 0;
	
	if(cellFrame == NULL)
		return 0;
    f = getFirstChildFrame();
	for (f = f->getFirstChildFrame(); f; f = f->getNextFrame())
	{
		if(f == cellFrame)
			break;
        if (f->getHidden())
        {
            continue;
        }
        if (f == m_subGroupClip)
        {
            // folding, bypass all cells inside the clip
            if (m_subGroupClip->getBounds().getY() != 0)
            {
                continue;
            }

            // expanding, must consider cells inside the clip
            for (VfxFrame *s = m_subGroupClip->getFirstChildFrame(); s; s = s->getNextFrame())
            {
                if(f == s)
                    break;
                pos++;
            }       
        }
		pos++;
	}
	return pos;
}


void VcpOptionBaseMenu::onInit()
{
    VcpBaseMenu::onInit();

    // create subgroup clip frame for subgroup exapanding/folding animation
    VFX_OBJ_CREATE(m_subGroupClip, VfxFrame, this);
    VFX_OBJ_CREATE(m_subGroupClipTl, VfxS32Timeline, m_subGroupClip);
    m_subGroupClip->setHidden(VFX_TRUE);
    m_subGroupClipTl->setTarget(m_subGroupClip);
    m_subGroupClipTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_Y);
    m_subGroupClipTl->setDurationTime(VfxAutoAnimate::getDuration());
    m_subGroupClipTl->setRepeatDuration(VfxAutoAnimate::getDuration());    
}


void VcpOptionBaseMenu::expandGroup(VfxFrame *groupParent)
{
    VfxS32 pos_y_start;
    VfxS32 count = 0;
    VfxFrame *f = NULL;

    stopSubGroupAnim();

    pos_y_start = groupParent->getPos().y + m_layout->getCellSize().height;

    for (f = groupParent->getNextFrame(); f; pos_y_start += m_layout->getCellSize().height)
    {
        if (((VcpOptionMenuItem*)f)->getParentMenuItem() == groupParent)
        {
            VfxFrame *frame;
            frame = f;
            f = f->getNextFrame();
            // add child frames to be expanded to the clip frame
            m_subGroupClip->addChildFrame(frame);
            frame->setPos(frame->getPos().x, count * m_layout->getCellSize().height);
            frame->setHidden(VFX_FALSE);
            count++;
        }
        else
        {
            break;
        }
    }

    // move all following items down
    // TODO: tricky to see if a cell is created by (f->getPos().y >= 0)?
    for (; f; f = f->getNextFrame())
    {
        if (!f->getHidden())
        {
            if (f->getPos().y < 0)
            {
                break;
            }            
        
            f->setAutoAnimate(VFX_TRUE);
            f->setPos(f->getPos().x, pos_y_start);
            f->setAutoAnimate(VFX_FALSE);
            pos_y_start += m_layout->getCellSize().height;
        }
    }

    // start subgroup expanding animation (clip bounds y from clip height to 0)
    m_subGroupClip->setHidden(VFX_FALSE);
    m_subGroupClip->setRect(groupParent->getPos().x, groupParent->getPos().y + m_layout->getCellSize().height, groupParent->getSize().width, count * m_layout->getCellSize().height);
    m_subGroupClip->setBounds(0, 0, groupParent->getSize().width, count * m_layout->getCellSize().height);
    // insert the clip right after the parent item
    groupParent->getParentFrame()->insertChildFrameAfter(groupParent, m_subGroupClip);        
    m_subGroupClipTl->setFromValue(count * m_layout->getCellSize().height);
    m_subGroupClipTl->setToValue(0);
    m_subGroupClipTl->m_signalStopped.connect(this, &VcpOptionBaseMenu::onSubGroupAnimStop);
    m_subGroupClipTl->start();    

    m_layout->setCellNum(m_layout->getCellNum() + count);        

    update();
}


void VcpOptionBaseMenu::onSubGroupAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VfxFrame *f, *nextFrame, *parent, *prevFrame;
    VfxS32 pos_y_start;

    VFX_UNUSED(timeline);
    VFX_UNUSED(isCompleted);

    parent = m_subGroupClip->getPrevFrame();
    pos_y_start = parent->getPos().y + m_layout->getCellSize().height;
    prevFrame = parent;

    // move all child frames from the clip frame to real parent
    for (f = m_subGroupClip->getFirstChildFrame(); f; pos_y_start += m_layout->getCellSize().height)
    {
        nextFrame = f->getNextFrame();
        parent->getParentFrame()->insertChildFrameAfter(prevFrame, f);
        f->setPos(parent->getPos().x, pos_y_start);

        if (m_subGroupClip->getBounds().getY() != 0)
        {
            f->setHidden(VFX_TRUE);
        }

        prevFrame = f;
        f = nextFrame;
    }

    // hide the clip
    m_subGroupClip->setHidden(VFX_TRUE);

    update();
}


void VcpOptionBaseMenu::foldGroup(VfxFrame *groupParent)
{
    VfxS32 pos_y_start;
    VfxS32 count = 0;
    VfxFrame *f = NULL;
    
    stopSubGroupAnim();
  
    pos_y_start = groupParent->getPos().y + m_layout->getCellSize().height;

    for (f = groupParent->getNextFrame(); f; pos_y_start += m_layout->getCellSize().height)
    {
        if (((VcpOptionMenuItem*)f)->getParentMenuItem() == groupParent)
        {
            VfxFrame *frame;
            frame = f;
            f = f->getNextFrame();
            m_subGroupClip->addChildFrame(frame);
            frame->setPos(frame->getPos().x, count * m_layout->getCellSize().height);
            count++;
        }
        else
        {
            break;
        }
    }

    // hide clip to exclude it from the following moving down
    m_subGroupClip->setHidden(VFX_TRUE);

    pos_y_start = groupParent->getPos().y + m_layout->getCellSize().height;
    // move all following items up
    for (; f; f = f->getNextFrame())
    {
        if (!f->getHidden())
        {
            if (f->getPos().y < 0)
            {
                break;
            }            
        
            f->setAutoAnimate(VFX_TRUE);
            f->setPos(f->getPos().x, pos_y_start);
            f->setAutoAnimate(VFX_FALSE);
            pos_y_start += m_layout->getCellSize().height;
        }
    }

    // start subgroup folding animation (clip bounds y from 0 to clip height)
    m_subGroupClip->setHidden(VFX_FALSE);
    m_subGroupClip->setRect(groupParent->getPos().x, groupParent->getPos().y + m_layout->getCellSize().height, groupParent->getSize().width, count * m_layout->getCellSize().height);
    m_subGroupClip->setBounds(0, count * m_layout->getCellSize().height, groupParent->getSize().width, count * m_layout->getCellSize().height);
    groupParent->getParentFrame()->insertChildFrameAfter(groupParent, m_subGroupClip);
    m_subGroupClipTl->setFromValue(0);
    m_subGroupClipTl->setToValue(count * m_layout->getCellSize().height);
    m_subGroupClipTl->m_signalStopped.connect(this, &VcpOptionBaseMenu::onSubGroupAnimStop);
    m_subGroupClipTl->start();    
    
    m_layout->setCellNum(m_layout->getCellNum() - count);

    update(); 
}


void VcpOptionBaseMenu::setRadioGroupExclusive(VfxFrame *checkedGroupItem)
{
    VfxFrame *f;

    // clear all radio items before in the same group
    for (f = checkedGroupItem->getPrevFrame(); f; f = f->getPrevFrame())
    {
        if (f->getHidden() || (f == m_subGroupClip))
        {
            continue;
        }
    
        if (f->isKindOf(VFX_OBJ_CLASS_INFO(VcpOptionMenuRadioItem)) && (f->getParent() == checkedGroupItem->getParent()))
        {
            ((VcpOptionMenuRadioItem*)f)->setCheck(VFX_FALSE);
        }
        else
        {
            break;
        }
    }

    // clear all radio items after in the same group
    for (f = checkedGroupItem->getNextFrame(); f; f = f->getNextFrame())
    {
        if (f->getHidden() || (f == m_subGroupClip))
        {
            continue;
        }

        if (f->isKindOf(VFX_OBJ_CLASS_INFO(VcpOptionMenuRadioItem)) && 
            (f->getParent() == checkedGroupItem->getParent()))
        {
            ((VcpOptionMenuRadioItem*)f)->setCheck(VFX_FALSE);
        }
        else
        {
            break;
        }
    }

    // check the selected radio
    ((VcpOptionMenuRadioItem*)checkedGroupItem)->setCheck(VFX_TRUE);
}


void VcpOptionBaseMenu::stopSubGroupAnim()
{
    if (m_subGroupClipTl->getIsEnabled())
    {   
        // to make sure the previous animation stop signal emit before the later start signal
        // because stop callback is post emit
        m_subGroupClipTl->m_signalStopped.disconnect(this, &VcpOptionBaseMenu::onSubGroupAnimStop);
        m_subGroupClipTl->stop();       
        onSubGroupAnimStop(m_subGroupClipTl, VFX_TRUE);
    }
}


void VcpOptionBaseMenu::tapCell(
    VfxS32 group,
    VfxS32 pos,
    VfxFrame* cell
)
{
    VfxBool isGroup = VFX_FALSE;
    VfxU32 ret = 0;    

    VFX_UNUSED(group);
    VFX_UNUSED(pos);    

    // set the tapped cell focused
    // getLayout()->setFocusItem(VcpMenuPos(group, pos), VFX_FALSE);

    VcpOptionMenuItem *item = (VcpOptionMenuItem*)cell;

    if (item->getFlag(VcpOptionMenuItem::IS_HAS_CHILD))
    {
        if (item->getFlag(VcpOptionMenuItem::IS_CHILD_EXPAND))
        {   // fold sub group
            foldGroup(item);
            m_expandedSubGroup = NULL;
        }
        else
        {   // expand sub group
            if (m_expandedSubGroup)
            {
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                foldGroup(m_expandedSubGroup);
                VfxAutoAnimate::commit();

                ((VcpOptionMenuItem*)m_expandedSubGroup)->onEvent(VcpOptionMenuItem::MENU_ITEM_EVENT_TAP, 0, &ret);                
            }

            expandGroup(item);
            m_expandedSubGroup = item;

            makeVisible(VcpMenuPos(group, pos), VFX_TRUE);            
        }

        isGroup = VFX_TRUE;
    }

	// set focus item
	{
		VcpMenuPos cell_pos;
        cell_pos.group = 0;
		cell_pos.pos = getPosByCell(cell);
		getLayout()->setFocusItem(cell_pos, VFX_FALSE);
	}
    // send tap event
    item->onEvent(VcpOptionMenuItem::MENU_ITEM_EVENT_TAP, 0, &ret);

    // do radio group exclusive set
    if (item->isKindOf(VFX_OBJ_CLASS_INFO(VcpOptionMenuRadioItem)))
    {
        setRadioGroupExclusive(cell);
    }

    // emit select signal if a non-group item is selected
    if (!isGroup)
    {
        m_signalMenu.postEmit(this, MENU_EVENT_ITEM_SELECTED, (VcpOptionMenuItem*)cell);
    }
}


void VcpOptionBaseMenu::onFocusIndexChange(
    VcpMenuPos focusItem,
    VcpMenuPos previousFocusItem
)
{
    VfxFrame *cell;

    // set focus item
    cell = getCellByPos(focusItem.pos);
    if (cell)
    {
        ((VcpOptionMenuItem*)cell)->onEvent(VcpOptionMenuItem::MENU_ITEM_EVENT_SET_FOCUS, (VfxU32)VFX_TRUE, NULL);
    }            

    // unfocus previous focus item
    cell = getCellByPos(previousFocusItem.pos);
    if (cell)
    {
        ((VcpOptionMenuItem*)cell)->onEvent(VcpOptionMenuItem::MENU_ITEM_EVENT_SET_FOCUS, (VfxU32)VFX_FALSE, NULL);
    }            
}


void VcpOptionBaseMenu::onTouchCell(
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
			{
				VcpOptionMenuItem *item = (VcpOptionMenuItem*)cell;

				if (!item->getFlag(VcpOptionMenuItem::IS_HAS_CHILD))
                    getLayout()->clearFocusItem();
                break;
			}
        case TouchTap:            
            // TouchTap will be invoked before TouchUp and tap might change the menu content.
            vfxPostInvoke3(this, &VcpOptionBaseMenu::tapCell, cellPos.group, cellPos.pos, cell);
            break;

        default:
            break;
    }    
}


void VcpOptionBaseMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpBaseMenu::onDrag(xoffset, yoffset);
    getLayout()->clearFocusItem();
}


/*****************************************************************************
 * Class VcpOptionMenu
 *****************************************************************************/

void VcpOptionMenu::onSize()
{
    VfxS32 menuWidth, menuHeight;

    menuWidth = getSize().width;
    menuHeight = getSize().height;

    if (m_titleFrame)
    {
        // resize title frame
        m_titleFrame->setAutoResized(VFX_TRUE);
        m_titleFrame->setString(m_titleText);

        // TODO: enable close button?
        m_titleFrame->setRect(
            BG_IMG_GAP_LEFT, 
            BG_IMG_GAP_TOP + TITLE_VERTICAL_GAP,
            menuWidth /* - TITLE_CLOSE_BUTTON_WIDTH */ - BG_IMG_GAP_LEFT - BG_IMG_GAP_RIGHT,
            2 * TITLE_VERTICAL_GAP + m_titleFrame->getMeasureBounds().size.height);
        m_titleFrame->setAutoResized(VFX_FALSE);
        
        // resize title bg frame
        m_titleBg->setRect(0, 0, getSize().width, m_titleFrame->getSize().height + BG_IMG_GAP_TOP);

        // resize close button
        m_closeButton->setRect(
            menuWidth - TITLE_CLOSE_BUTTON_WIDTH - BG_IMG_GAP_RIGHT, 
            BG_IMG_GAP_TOP, 
            TITLE_CLOSE_BUTTON_WIDTH, 
            m_titleFrame->getSize().height - TITLE_VERTICAL_GAP);
    }       

    // adjust menu size by BG IMAGE gaps
    menuWidth -= BG_IMG_GAP_LEFT + BG_IMG_GAP_RIGHT;
    // menuHeight -= BG_IMG_GAP_TOP + BG_IMG_GAP_BOTTOM;

    // resize menu
    if (m_menu)
    {
        if (m_titleFrame)
        {
            m_menu->setPos(BG_IMG_GAP_LEFT, BG_IMG_GAP_TOP + m_titleFrame->getSize().height);        
        }
        else
        {
            m_menu->setPos(BG_IMG_GAP_LEFT, BG_IMG_GAP_TOP);
        }

        if (m_showCancelButton)
        {
            m_cancelButton->setPos(BG_IMG_GAP_LEFT, CANCEL_BUTTON_VERTICAL_GAP + menuHeight - m_layout->getCellSize().height - BG_IMG_GAP_BOTTOM);
            m_cancelButton->setSize(menuWidth, m_layout->getCellSize().height - CANCEL_BUTTON_VERTICAL_GAP);
            menuHeight -= m_layout->getCellSize().height;                    
        }

        m_menu->setSize(menuWidth, menuHeight - m_menu->getPos().y - BG_IMG_GAP_BOTTOM);
        m_layout->setCellSize(VfxSize(menuWidth - MENU_RIGHT_GAP, m_layout->getCellSize().height));
        m_menu->update();
    }

    // resize background
    if (m_background)
    {
        m_background->setSize(getSize());
    }    

    // center align to parent
    VfxSize parentSize = getParentFrame()->getSize();
    setPos(parentSize.width / 2, parentSize.height / 2);
}


/*****************************************************************************
 * Class VcpOptionMenuItem
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VcpOptionMenuItem", VcpOptionMenuItem, VfxControl);
VfxBool VcpOptionMenuItem::onEvent(VcpOptionMenuItemEventEnum event, VfxU32 param, VfxU32 *ret)
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
    if (event == MENU_ITEM_EVENT_SET_FOCUS)
    {        
        if (isFocused)
        {
            setImgContent(m_first_level_bg.getImageHighlight());
        }
        else
        {
            if (getLevel() && ((VcpOptionMenuItem*)getPrevFrame() == getParent()))
            {   // first item in the second level
               setImgContent(m_first_level_bg.getImagePressed());
            }
            else
            {   // other items
                setImgContent(m_first_level_bg.getImageNormal());
            }                 
        }

        return VFX_TRUE;
    }            

    return VFX_FALSE;
}


/*****************************************************************************
 * Class VcpOptionMenuCheckItem
 *****************************************************************************/
 
VfxBool VcpOptionMenuCheckItem::onEvent(VcpOptionMenuItemEventEnum event, VfxU32 param, VfxU32 *ret)
{
    switch (event)
    {
        case MENU_ITEM_EVENT_TAP:
            onCheck();
            return VFX_TRUE;

        case MENU_ITEM_EVENT_GET_CHECKED:
            if (ret)
            {
                *ret = getCheck();
                
                return VFX_TRUE;
            }
            break;
            
        case MENU_ITEM_EVENT_SET_CHECKED:
            setCheck((VfxBool)(param > 0));
            return VFX_TRUE;

        default:
            break;
    }

    return VcpOptionMenuItem::onEvent(event, param, ret);
}


void VcpOptionMenuCheckItem::update()
{    
    VfxS32 x;

    if (m_level)
    {
        x = SECOND_LEVEL_TEXT_GAP;
    }
    else
    {
        x = FIRST_LEVEL_TEXT_GAP;
    }

    if (m_iconFrame)
    {
        m_iconFrame->setPos(x, getSize().height / 2);
        x += m_iconFrame->getSize().width + ICON_TEXT_GAP;            
    }

    if (m_textFrame)
    {
        // move text frame position according to the level
        m_textFrame->setPos(x, getSize().height / 2);
        m_textFrame->setSize(getSize().width - x, m_textFrame->getSize().height);
    }

    // check box before the text
    if (m_checkFrame)
    {
        if (getCheck())
        {
		    m_checkFrame->setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_CHECK_BOX_P));
        }
        else
        {
           m_checkFrame->setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_CHECK_BOX_N));
        }

        if (m_textFrame)
        {
            m_checkFrame->setPos(m_textFrame->getPos().x - m_checkFrame->getSize().width - CHECK_BOX_TO_TEXT_GAP, (getSize().height - m_checkFrame->getSize().height) / 2);
        }
    }
}


/*****************************************************************************
 * Class VcpOptionMenuRadioItem
 *****************************************************************************/

void VcpOptionMenuRadioItem::update()
{
    VcpOptionMenuCheckItem::update();

    if (m_onImg.isEmpty() || m_offImg.isEmpty())
    {            
        return;
    }

    if (m_checkFrame)
    {
        VfxImageSrc activeImg;
    
        if (getCheck())
        {
            activeImg = m_onImg;
            m_checkFrame->setImgContent(m_onImg);
        }
        else
        {
            activeImg = m_offImg;
            m_checkFrame->setImgContent(m_offImg);
        }

        if (m_textFrame)
        {
            if (m_style == VCP_OPTION_MENU_RADIO_ITEM_STYLE_ICON_RIGHT_ALIGN)
            {
                m_checkFrame->setPos(getSize().width - activeImg.getSize().width - RADIO_BOX_TO_RIGHT_GAP, (getSize().height - activeImg.getSize().height) / 2);
                // must resize text frame
                m_textFrame->setSize(m_checkFrame->getPos().x - m_textFrame->getPos().x - RADIO_TEXT_TO_BUTTON_GAP, m_textFrame->getSize().height);            
            }
            else
            {
                if (m_iconFrame)
                {
                    m_checkFrame->setPos(m_iconFrame->getPos().x - m_checkFrame->getSize().width - CHECK_BOX_TO_TEXT_GAP, (getSize().height - m_checkFrame->getSize().height) / 2);
                }
            }
        }
    }
}


/*****************************************************************************
 * Class VcpOptionMenuTextItem
 *****************************************************************************/
void VcpOptionMenuTextItem::update()
{
    VfxS32 x;

    // move text frame position according to the level
    if (m_level)
    {
        x = SECOND_LEVEL_TEXT_GAP;
    }
    else
    {
        x = FIRST_LEVEL_TEXT_GAP;
    }

    if (m_iconFrame)
    {
        m_iconFrame->setPos(x, getSize().height / 2);
        x += m_iconFrame->getSize().width + ICON_TEXT_GAP;
    }

    m_textFrame->setPos(x, getSize().height / 2);    
    m_textFrame->setSize(getSize().width - x - TEXT_RIGHT_GAP, m_textFrame->getSize().height);        
}

