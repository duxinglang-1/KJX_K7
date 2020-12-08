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
 *  vcp_var_height_menu.cpp
 *
 * Project:
 * --------
 *  Venus 
 *
 * Description:
 * ------------
 *  Variable Height Menu
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
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MTK_TARGET__
#ifdef __VENUS_SWLA_DBG_ON__
#define __MAUI_SOFTWARE_LA__
#else
//#define __MAUI_SOFTWARE_LA__
#endif
#endif

extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

}
#include "vcp_var_height_menu.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h" // FNT_COSMOS_TEXT_EMPTY
#endif /* defined(__MMI_VUI_COSMOS_CP__) */

/***************************************************************************** 
 * Class VcpVarHeightMenuCurCellsIter
 *****************************************************************************/

VcpVarHeightMenuCurCellsIter::VcpVarHeightMenuCurCellsIter(VcpVarHeightMenu *menu) : 
    m_itr(VcpMenuRegionIter(menu, menu->getRealContentRegion())), 
    m_menu(menu), 
    m_curr(NULL)
{
}

VfxBool VcpVarHeightMenuCurCellsIter::isEnd()
{
    /* loop through current list of created cells
       if some valid cell is found, keep it at m_curr and return false (not finished yet)
       try the next one if the cell is invalid, return true when all cells are examined   */       
    while ( m_menu->getCellCount() > 0 && ! m_itr.isEnd() )
    {
        VcpMenuPos menu_pos = m_itr.next();
        m_curr = (VcpVarHeightMenuCell *)m_menu->getCellIfPresent(menu_pos.group, menu_pos.pos);
        if ( m_curr ) 
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

VcpVarHeightMenuCell *VcpVarHeightMenuCurCellsIter::next() 
{
    return m_curr;
}

/***************************************************************************** 
 * Class VcpVarHeightMenuCell
 *****************************************************************************/



VcpVarHeightMenuCell::VcpVarHeightMenuCell(VcpMenuPos menupos) : m_menupos(menupos)
{
}

void VcpVarHeightMenuCell::onInit()
{
    VfxControl::onInit();
    
    m_signalBoundsChanged.connect(this, &VcpVarHeightMenuCell::onBoundsChanged);
}

VfxRect VcpVarHeightMenuCell::getHitRect()
{
    return getBounds();
}

void VcpVarHeightMenuCell::setHighlight(VfxBool isHighlight)
{
    // empty
}

void VcpVarHeightMenuCell::onBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    // empty    
}

VcpVarHeightMenu *VcpVarHeightMenuCell::getMenu()
{
    // cell --parent--> view --parent--> menu 
    // Ref: VcpScrollable::onAddChild
    if (getParentFrame() && getParentFrame()->getParentFrame())
    {
        return VFX_STATIC_CAST(getParentFrame()->getParentFrame(), VcpVarHeightMenu*);
    }
    
    return NULL;
}

VfxBool VcpVarHeightMenuCell::isTop()
{
    return  getMenu()->isReverse() && m_menupos.pos == getMenu()->getCellCount() - 1 ||
           !getMenu()->isReverse() && m_menupos.pos == 0;
}

VfxBool VcpVarHeightMenuCell::isBottom()
{
    return  getMenu()->isReverse() && m_menupos.pos == 0 ||
           !getMenu()->isReverse() && m_menupos.pos == getMenu()->getCellCount() - 1;
}

/***************************************************************************** 
 * Class VcpVarHeightMenu
 *****************************************************************************/


VcpVarHeightMenu::VcpVarHeightMenu(VcpVarHeightMenuLayoutType type) : 
    m_bkgd(NULL),
    m_defaultHeight(30),
    m_cellCount(0),
    m_type(type), 
    m_hasHighlight(VFX_TRUE),
    m_hasAnimation(VFX_FALSE),
    m_animationReadyInternal(VFX_FALSE),
    m_animationReadyExternal(VFX_FALSE),
    m_animationPlayed(VFX_FALSE),
    m_emptyText(NULL)    
{
}


void VcpVarHeightMenu::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HIN", SA_start);
#endif        
    VcpBaseMenu::onInit();

    VFX_OBJ_CREATE(m_bkgd, VfxImageFrame, this);
    addChildFrame(m_bkgd);
    m_bkgd->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bkgd->setSize(getSize());
    m_bkgd->sendToBack();
    m_bkgd->setAutoAnimate(VFX_TRUE);

    setAutoAnimate(VFX_TRUE);
    m_items.init(this);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HIN", SA_stop);
#endif            
}

void VcpVarHeightMenu::onDeinit()
{
    for (VfxU32 i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_userData)
        {
            VFX_FREE_MEM(m_items[i].m_userData);
            m_items[i].m_userData = NULL;
            m_items[i].m_userDataSize = 0;
            
        }
    }    
    VcpBaseMenu::onDeinit();
}

void VcpVarHeightMenu::onAfterCreateLayout()
{
    if (isReverse())
    {
        VfxPoint p(0, 0);
        p.y = -m_view->getBounds().getHeight();
        makeVisible(VfxRect(p, m_view->getBounds().size), VFX_FALSE);
    }
}

void VcpVarHeightMenu::addMarginItem(VcpBaseMenuMarginAreaEnum area, VcpBaseMenuMarginAreaFramePlacementEnum placement, VfxFrame *frame)
{
    VcpBaseMenu::addMarginItem(area, placement, frame);
    updateOrigin();    
}

void VcpVarHeightMenu::removeMarginItem(VfxFrame *frame)
{
    VcpBaseMenu::removeMarginItem(frame);
    updateOrigin();
}

void VcpVarHeightMenu::removeMarginItem(VcpMenuPos pos)
{
    VcpBaseMenu::removeMarginItem(pos);
    updateOrigin();
}


VcpVarHeightMenuCurCellsIter VcpVarHeightMenu::getCurrentCellsIter()
{
    return VcpVarHeightMenuCurCellsIter(this);
}


VfxBool VcpVarHeightMenu::isReverse()
{
    return LAYOUT_REVERSE == m_type;
}

void VcpVarHeightMenu::setHasHighlight(VfxBool has_highlight)
{
    m_hasHighlight = has_highlight;
}

VfxBool VcpVarHeightMenu::hasHighlight()
{
    return m_hasHighlight;
}

void VcpVarHeightMenu::setHasAnimation(VfxBool has_animation)
{
    m_hasAnimation = has_animation;
}

VfxBool VcpVarHeightMenu::hasAnimation()
{
    return m_hasAnimation;
}

void VcpVarHeightMenu::setReadyForAnimation()
{
    if ( !m_animationReadyExternal ) 
    {
        m_animationReadyExternal = VFX_TRUE;
        checkUpdate();
    }
}

void VcpVarHeightMenu::checkReadyForAnimation(VfxObject* content, VfxBool isReady)
{
    if ( !hasAnimation() )
    {
        return;
    }
    
    if ( !m_animationReadyInternal )
    {
        VcpVarHeightMenuCurCellsIter cellList = getCurrentCellsIter();
        while ( !cellList.isEnd() )
        {
            VcpVarHeightMenuCell *cell = cellList.next();
            if ( cell )
            {
                VfxRect rect = m_layout->queryCellRect(cell->m_menupos);
                // done checking cells within view bounds
                if (( isReverse() && rect.getMaxY() < m_view->getBounds().getMinY()) ||
                    (!isReverse() && rect.getMinY() > m_view->getBounds().getMaxY()) )
                {
                    break;
                }
                // if the cell exists and lies within the view bounds but not ready to animate yet => skip and check next time
                if ( !cell->isReadyForAnimation() )
                {
                    return; // m_animationReadyInternal is still VFX_FALSE
                }
            }
        }
        m_animationReadyInternal = VFX_TRUE;
        checkUpdate();
    }
}

void VcpVarHeightMenu::playAnimation()
{
    if ( !hasAnimation() )
    {
        return;
    }
    
    VfxS32 i = 0;
    VcpVarHeightMenuCurCellsIter cellList = getCurrentCellsIter();
    while (!cellList.isEnd())
    {
        VcpVarHeightMenuCell *cell = cellList.next();
        if ( cell )
        {
            cell->playAnimation(i++);
        }
    }
}

VfxBool VcpVarHeightMenu::isAnimationPlayed()
{
    return m_animationPlayed;
}

void VcpVarHeightMenu::forceUpdateCell(VcpMenuPos pos)
{
    updateCell(getLayout()->queryCellRect(pos), pos, 0);
}

void VcpVarHeightMenu::setBounds(const VfxRect &value)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HSB", SA_start);
#endif
    

    // will call setViewRect() and checkUpdate() 
    VcpBaseMenu::setBounds(value);
    
    m_bkgd->setSize(getSize());

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HSB", SA_stop);
#endif    
}

void VcpVarHeightMenu::setImgContent(const VfxImageSrc &value)
{
    setBgColor(VFX_COLOR_TRANSPARENT);
    m_bkgd->setImgContent(value);
}

VcpBaseMenuLayout* VcpVarHeightMenu::createLayout()
{
    VcpVarHeightMenuLayout *var_height_menu_layout;    
    VFX_OBJ_CREATE_EX(var_height_menu_layout, VcpVarHeightMenuLayout, this, (this));
    return var_height_menu_layout;
}

void VcpVarHeightMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HOC", SA_start);
#endif  
    VFX_OBJ_CLOSE(cellFrame);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HOC", SA_stop);
#endif  
}

void VcpVarHeightMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{   
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HUC", SA_start);
#endif     
     cell->setPos(rect.origin);   
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HUC", SA_stop);
#endif     
}

void VcpVarHeightMenu::onTouchCell(VcpMenuPos cellPos, VcpBaseMenu::CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    VcpVarHeightMenuCell *var_height_menu_cell = (VcpVarHeightMenuCell *)cell;

    if ( touchType == VcpBaseMenu::TouchDown && !var_height_menu_cell->getHitRect().contains(pt) )
    {
        m_clickedCell = NULL;
        return;
    }
    
    switch (touchType)
    {
        case VcpBaseMenu::TouchDown:
        {
            getLayout()->setFocusItem(cellPos, VFX_FALSE);
            var_height_menu_cell->m_signalTouchDown.postEmit(var_height_menu_cell);
            break;
        }
        case VcpBaseMenu::TouchUp:
        {
            getLayout()->clearFocusItem();
            var_height_menu_cell->m_signalTouchUp.postEmit(var_height_menu_cell);
            break;
        }
        case VcpBaseMenu::TouchTap:
        {
            var_height_menu_cell->m_signalTapped.postEmit(var_height_menu_cell);
            break;
        }
        case VcpBaseMenu::TouchLongTap:
        {
            if ( var_height_menu_cell->m_signalLongPressed.getSlotCount() > 0 ) 
            {
                var_height_menu_cell->m_signalLongPressed.postEmit(var_height_menu_cell);
            }
            break;
        }
    }
}

void VcpVarHeightMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    getLayout()->clearFocusItem();
}

void VcpVarHeightMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HFC", SA_start);
#endif  
    if (!hasHighlight())
    {
        return;
    }
    
    if (previousFocusItem.isValid())
    {
        VcpVarHeightMenuCell* item = (VcpVarHeightMenuCell *) getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);      
        if (item)
        {
            item->setHighlight(VFX_FALSE);
        }
    }
    
    if (focusItem.isValid())
    {
        VcpVarHeightMenuCell* item = (VcpVarHeightMenuCell *) getCellIfPresent(focusItem.group, focusItem.pos);        
        if (item)
        {
            item->setHighlight(VFX_TRUE);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HFC", SA_stop);
#endif      
}

void VcpVarHeightMenu::onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HBC", SA_start);
#endif      
    VcpBaseMenu::onViewBoundsValueChange(source, oldBounds);

    // no need to adjust the size of cells if only the pos is changed (dragging) 
    if ( oldBounds.size != m_view->getBounds().size )
    {
        updateOrigin();
    }  
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HBC", SA_stop);
#endif          
}

void VcpVarHeightMenu::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HUP", SA_start);
#endif  


    VcpBaseMenu::onUpdate();

    if ( isReadyForAnimation() )
    {
        m_animationPlayed = VFX_TRUE;

        playAnimation();
    }

    if (m_cellCount == 0 )
    {
        VfxWString text;
        VcpListMenuTextColorEnum textColor;
        
        if ( getMenuEmptyText(text, textColor) )
        {
            if ( !m_emptyText )
            {
                VFX_OBJ_CREATE(m_emptyText, VfxTextFrame, this);
                VFX_OBJ_ASSERT_VALID(m_emptyText);

                //addChildFrame(m_emptyText);
            }

            m_emptyText->setString(text);
            m_emptyText->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
            m_emptyText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_emptyText->setAutoResized(VFX_TRUE);
            m_emptyText->setSize((VfxS32)(getSize().width * VCP_LIST_MENU_EMPTY_TEXT_WITH_RATIO), 0);
#if defined(__MMI_VUI_COSMOS_CP__)
            m_emptyText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
            m_emptyText->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));
#else /* defined(__MMI_VUI_COSMOS_CP__) */
            m_emptyText->setColor(VFX_COLOR_GREY);
#endif /* defined(__MMI_VUI_COSMOS_CP__) */
            m_emptyText->setAnchor(0.5, 0.5);
            VfxPoint p = m_view->getBounds().getMidPoint();
            p.y = (m_layout->getTotalLength() + m_layout->getMarginLength(VCP_BASE_MENU_MARGIN_AREA_TOP)) / 2;
            m_emptyText->setPos(p);
        }
    }
    else if ( m_emptyText )
    {
        VFX_OBJ_CLOSE(m_emptyText);
        m_emptyText = NULL;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("HUP", SA_stop);
#endif      
}


VfxBool VcpVarHeightMenu::IsSupportTransition() {
    return VFX_FALSE;
}

VfxBool VcpVarHeightMenu::isReadyForAnimation()
{
    return !m_animationPlayed && m_animationReadyInternal && m_animationReadyExternal;
}




void VcpVarHeightMenu::setCount(VfxS32 count)
{
    if (m_cellCount != count)
    {
        m_cellCount = count;
        updateCountAndDefaultHeight();
        checkUpdate();
    }    
}
void VcpVarHeightMenu::setDefaultHeight(VfxS32 height)
{
    if (m_defaultHeight != height)
    {
        m_defaultHeight = height;
        updateCountAndDefaultHeight();
        checkUpdate();
    }
}


void VcpVarHeightMenu::updateCountAndDefaultHeight()
{
    // when menu is reset, getCount might return 0 temporarily
    if (m_cellCount == 0)
    {     
       m_items.clear();     
       return;
    }

    if (m_cellCount > (VfxS32)m_items.size())
    {
        for (VfxS32 i = m_items.size(); i < m_cellCount; ++i)
        {            
            
            VcpVarHeightMenuItem item(VCP_VAR_HEIGHT_MENU_INVALID_ID, 0);
            if(i == 0)
            {
                item.m_accumulatedLength = m_defaultHeight;
            }
            else
            {
                item.m_accumulatedLength = m_items[i - 1].m_accumulatedLength + m_defaultHeight;
            }            
            m_items.pushBack(item);
        }                
    }
    else if(m_cellCount < (VfxS32) m_items.size())
    {
        for (VfxS32 i = m_items.size(); i > m_cellCount; --i)
        {            
            m_items.popBack();
        }         
    }    
    else // m_items.size() == m_cellCount 
    {
        for (VfxS32 i = 0; i < m_cellCount; ++i)
        {                                    
            if(i == 0)
            {
                m_items[i].m_accumulatedLength = m_defaultHeight;
            }
            else
            {
                m_items[i].m_accumulatedLength = m_items[i - 1].m_accumulatedLength + m_defaultHeight;
            }            

        }                

    }


    updateOrigin();

}


VfxBool VcpVarHeightMenu::addItem(VfxId id, VfxS32 h, void* userData, VfxS32 size)
{
    return insertItem(id, h, m_items.size(), userData, size);
}
VfxBool VcpVarHeightMenu::insertItem(VfxId id, VfxS32 h, VfxId refId, VfxBool addBeforeRef, void* userData, VfxS32 size)
{
    VfxU32 i;
    for (i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_id == refId)
        {
            break;
        }
    }    
    return insertItem(id, h, addBeforeRef ? i : i + 1, userData, size);    
}
VfxBool VcpVarHeightMenu::insertItem(VfxId id, VfxS32 h, VfxS32 index, void* userData, VfxS32 size)
{   
    if (!(index >= 0 && index <= (VfxS32)m_items.size()) || !((userData == NULL && size == 0) || (userData != NULL && size !=0)))
    {
        return VFX_FALSE;
    }

    
    VcpVarHeightMenuItem item(id, 0);
    item.m_accumulatedLength = index != 0 ? m_items[index - 1].m_accumulatedLength + h : h;      

    if (userData != NULL)
    {        
        item.m_userDataSize = size;
        VFX_ALLOC_MEM(item.m_userData, item.m_userDataSize, this);            
        memcpy(item.m_userData, userData, item.m_userDataSize);
    }

    //increase pos
    VcpMenuRegionIter   itr(getLayout(), getRealContentRegion());
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VcpVarHeightMenuCell* cell = (VcpVarHeightMenuCell*) getCellIfPresent(p.group, p.pos);

        if (cell && p.pos >= index)
        {
            cell->m_menupos.pos++;
        }
    }

    if (m_focusItem.pos >= index)
    {
        m_focusItem.pos++;
    }

    m_items.insert(index, item);  

    for (VfxU32 j = index + 1; j < m_items.size(); ++j)
    {
        m_items[j].m_accumulatedLength += h;
    }    
    m_cellCount = m_items.size();

    putinCell(0, index);

    return VFX_TRUE;
}
VfxBool VcpVarHeightMenu::removeItem(VfxId id)
{
    VfxU32 i;
    for (i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_id == id)
        {
            break;
        }
    }    
    return removeItem((VfxS32)i);    
}
VfxBool VcpVarHeightMenu::removeItem(VfxS32 index)
{
    if (!(index >= 0 && index < (VfxS32)m_items.size()))
    {
        return VFX_FALSE;
    }


    VfxS32 h = index > 0 ? m_items[index].m_accumulatedLength - m_items[index - 1].m_accumulatedLength : m_items[0].m_accumulatedLength;
    for (VfxU32 i = index + 1; i < m_items.size(); ++i)
    {
        m_items[i].m_accumulatedLength -= h;
    }
    
    if (m_items[index].m_userData)
    {
        VFX_FREE_MEM(m_items[index].m_userData);
        m_items[index].m_userData = NULL;
        m_items[index].m_userDataSize = 0;
    }
        

    //decrease pos
    VcpMenuRegionIter   itr(getLayout(), getRealContentRegion());
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VcpVarHeightMenuCell* cell = (VcpVarHeightMenuCell*) getCellIfPresent(p.group, p.pos);

        if (cell && p.pos >= index)
        {
            cell->m_menupos.pos --;           
        }
    }      

    if (m_focusItem.pos >= index)
    {
        m_focusItem.pos--;
    }


    m_items.erase(index);    
    m_cellCount = m_items.size();

    withdrawCell(0, index);

    return VFX_TRUE;
}


VfxBool VcpVarHeightMenu::updateItem(VfxId id)
{
    VfxU32 i;
    for (i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_id == id)
        {
            break;
        }
    }    
    return updateItem((VfxS32)i);    
    
}
VfxBool VcpVarHeightMenu::updateItem(VfxS32 index)
{
    if (!(index >= 0 && index < (VfxS32)m_items.size()))
    {
        return VFX_FALSE;
    }

    VcpVarHeightMenuCell* cell = (VcpVarHeightMenuCell*) getCellIfPresent(0, index);
    if (cell)
    {
        cell->checkUpdate();
        updateLayout();
    }

    return VFX_TRUE;
}

void* VcpVarHeightMenu::getItemData(VfxId id)
{
    VfxU32 i;
    for (i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_id == id)
        {
            break;
        }
    }    
    return getItemData((VfxS32)i);    
}

void* VcpVarHeightMenu::getItemData(VfxS32 index)
{
    if (!(index >= 0 && index < (VfxS32)m_items.size()))
    {
        return NULL;
    }
    return m_items[index].m_userData;
}


VfxId VcpVarHeightMenu::getItemId(VfxS32 index)
{
    if (!(index >= 0 && index < (VfxS32)m_items.size()))
    {
        return VCP_VAR_HEIGHT_MENU_INVALID_ID;
    }

    return m_items[index].m_id;    
}
VfxS32 VcpVarHeightMenu::getItemIndex(VfxId id)
{
    for (VfxU32 i = 0; i < m_items.size(); ++i)
    {
        if(m_items[i].m_id == id)
        {
            return i;
        }
    }    
    return -1;
}

void VcpVarHeightMenu::setItemHeight(VfxS32 index, VfxS32 height)
{   
    if (index < 0 || index >= m_cellCount)
        return;

    
    VfxS32 orig_height, height_diff, i;
    orig_height = index == 0 ? m_items[0].m_accumulatedLength : m_items[index].m_accumulatedLength - m_items[index - 1].m_accumulatedLength;
    height_diff = height - orig_height;

    if (height_diff == 0)
        return;

    for ( i = index ; i < m_cellCount ; ++ i )
    {
        m_items[i].m_accumulatedLength = m_items[i].m_accumulatedLength + height_diff;
    }

    updateOrigin();
}


VfxS32 VcpVarHeightMenu::getItemHeight(VfxS32 index)
{
    if (index >= 0 && index < m_cellCount )
    {
        return index == 0 ? m_items[0].m_accumulatedLength : m_items[index].m_accumulatedLength - m_items[index - 1].m_accumulatedLength;
    }
    else
    {
        return 0;
    }    
}

VfxS32 VcpVarHeightMenu::getAccumulatedItemHeight(VfxS32 index)
{
    if (index >= 0 && index < m_cellCount )
    {
        return m_items[index].m_accumulatedLength;
    }
    else
    {
        return 0;
    }    
}





void VcpVarHeightMenu::updateOrigin()
{
    if(m_layout && isReverse())
    {                        
        VfxS32 h = m_view->getBounds().size.height;        
        setContentOrigin(VfxPoint(0, VFX_MIN(-h, -m_layout->getTotalLength())));       
    }    
  
    updateLayout();        
}



/***************************************************************************** 
 * Class VcpVarHeightMenuLayout
 *****************************************************************************/


VcpVarHeightMenuLayout::VcpVarHeightMenuLayout(VcpVarHeightMenu *menu) :
    VcpBaseMenuLayout(menu)    
{
}

VfxS32 VcpVarHeightMenuLayout::getCellCount(VfxS32 group)
{
    return getVarHeightMenu()->getCellCount();
}


VfxS32 VcpVarHeightMenuLayout::getContentLength()
{   
    VfxS32 cell_count = getVarHeightMenu()->getCellCount();
    if (cell_count == 0)
    {
        VfxWString text;
        VcpListMenuTextColorEnum textColor;        

        
        if (getVarHeightMenu()->getMenuEmptyText(text, textColor))
        {
            VfxS32 gap = getVarHeightMenu()->getDefaultHeight();
            VfxS32 baseheight = getMarginLength(VCP_BASE_MENU_MARGIN_AREA_TOP) + getMarginLength(VCP_BASE_MENU_MARGIN_AREA_BOTTOM);
            return VFX_MAX(gap, m_viewRect.getHeight() - baseheight);            
        }
        else 
        {
            return 0;
        }        
    }

    return getVarHeightMenu()->getAccumulatedItemHeight(cell_count - 1);
        
}

VfxRect VcpVarHeightMenuLayout::queryMarginItemRect(VcpMenuPos pos)
{
    return queryMarginItemRectHelper(m_pMenu, this, m_viewRect, pos, getVarHeightMenu()->isReverse() );
}

VcpMenuRegion VcpVarHeightMenuLayout::queryRegion(const VfxRect& r)
{
    VfxS32 cell_count = getVarHeightMenu()->getCellCount();
    if ( cell_count == 0 )
    {
        return VcpMenuRegion(VcpMenuPos(),VcpMenuPos());
    }

    VcpMenuRegion region;

     
    if(getVarHeightMenu()->isReverse())
    {
        return VcpMenuRegion(queryPosByPt(r.getMaxY()), queryPosByPt(r.getMinY()));
    }
    else
    {
        return VcpMenuRegion(queryPosByPt(r.getMinY()), queryPosByPt(r.getMaxY()));
    }

    
}



VfxRect VcpVarHeightMenuLayout::queryCellRect(VcpMenuPos pos)
{
    VfxS32 cell_count = getVarHeightMenu()->getCellCount();
    if ( cell_count == 0 )
    {
        return VfxRect();
    }    

    VfxS32 y = 0;
    VfxS32 height = getVarHeightMenu()->getItemHeight(pos.pos);
    VfxS32 width = getVarHeightMenu()->getSize().width;

     
    if(getVarHeightMenu()->isReverse())
    {             
         VfxS32 offset = VFX_MAX(0, m_viewRect.getHeight() - getTotalLength());
         y = - getVarHeightMenu()->getAccumulatedItemHeight(pos.pos) - getMarginLength(VCP_BASE_MENU_MARGIN_AREA_BOTTOM) - offset;          
    }
    else
    {             
        if (pos.pos != 0)
        {            
            y = getVarHeightMenu()->getAccumulatedItemHeight(pos.pos - 1);
        }
        y += getMarginLength(VCP_BASE_MENU_MARGIN_AREA_TOP);
    }

    return VfxRect(0, y, width, height);
}




VcpMenuPos VcpVarHeightMenuLayout::queryPosByPt(VfxS32 y)
{
    VfxS32 cell_count = getVarHeightMenu()->getCellCount();
    VcpMenuPos p(0, cell_count - 1);
    
    if(getVarHeightMenu()->isReverse())
    {
        for (VfxS32 i = 0; i < cell_count; ++i)
        {
            if(-getVarHeightMenu()->getAccumulatedItemHeight(i) - getMarginLength(VCP_BASE_MENU_MARGIN_AREA_BOTTOM) <= y)
            {
                p.pos = i;
                break;
            }
        }        
    }
    else
    {     
        for (VfxS32 i = 0; i < cell_count; ++i)
        {
            if(getVarHeightMenu()->getAccumulatedItemHeight(i) + getMarginLength(VCP_BASE_MENU_MARGIN_AREA_TOP) >= y)
            {
                p.pos = i;
                break;
            }
        }                
        
    }

    return p;
}


VcpBaseMenuLayout::ScrollDirEnum VcpVarHeightMenuLayout::getScrollDir()
{
    return VcpBaseMenuLayout::SCROLLDIR_VERT;
}

VfxBool VcpVarHeightMenuLayout::navDir(NavDirEnum dir)
{
    if (dir != NAV_DIR_UP && dir != NAV_DIR_DOWN)
    {
        return VFX_FALSE;
    }

    VcpMenuRegion visibleRegion = queryRegion(m_viewRect);

#if defined(__MMI_VUI_COSMOS_CP__)

    VcpMenuPos pos; 
    VcpMenuPos newPos;

    if( (dir == NAV_DIR_UP) ^ (getVarHeightMenu()->isReverse() ) )
    {
        pos = visibleRegion.begin;
        newPos = pos.getPrevPos(this, VFX_TRUE);                
    }
    else
    {
        pos = visibleRegion.end;
        newPos = pos.getNextPos(this, VFX_TRUE);
    }

    VfxRect targetRect = m_viewRect;

    vcpBaseMenuNavDirHelper(this->m_pMenu, this, dir, pos, newPos, targetRect);

    m_pMenu->makeVisible(targetRect, VFX_TRUE);

    return VFX_TRUE;


#else

    VcpMenuPos focusItem = m_pMenu->getFocusItem();
    VcpMenuPos focusMarginItem = m_pMenu->getFocusMarginItem();


    if (!focusItem.isValid())
    {
        VcpMenuPos oldfocus;
        if (focusMarginItem.isValid())                
        {
            oldfocus = focusMarginItem;
            if (dir == NAV_DIR_UP)
            {
                if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_TOP && 
                   focusMarginItem.pos == m_pMenu->m_marginItemArray[focusMarginItem.group].size() - 1)
                {
                    return VFX_TRUE;                    
                }
                if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_TOP)
                {
                    focusMarginItem.pos++;                    
                }
                else if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM)
                {
                    focusMarginItem.pos--;
                }
            }
            else if (dir == NAV_DIR_DOWN)
            {
                if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM && 
                   focusMarginItem.pos == m_pMenu->m_marginItemArray[focusMarginItem.group].size() - 1)
                {
                    return VFX_TRUE;                    
                }
                if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_TOP)
                {
                    focusMarginItem.pos--;                    
                }
                else if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM)
                {
                    focusMarginItem.pos++;
                }                
            }
            if(focusMarginItem.pos < 0)
            {
                focusMarginItem.invalid();                
            }            
        }
        else
        {
            if(getVarHeightMenu()->isReverse())
            {
                focusMarginItem = vcpBaseMenuLayoutQueryMarginItemByPt(m_pMenu, this, VfxPoint(m_viewRect.getMaxX(), m_viewRect.getMaxY()));            
            }
            else
            {
                focusMarginItem = vcpBaseMenuLayoutQueryMarginItemByPt(m_pMenu, this, m_viewRect.origin);     

            }
            
        }

        if (focusMarginItem.isValid())
        {
            m_pMenu->setFocusMarginItem(focusMarginItem, VFX_TRUE);                    
            return VFX_TRUE;
        }
        

        VcpMenuPos p;
        
        if(oldfocus.isValid())
        {
            VfxRect fr = queryMarginItemRect(oldfocus);
            if (dir == NAV_DIR_UP)
            {
                p = queryPosByPt(fr.getMinY() - 5); 
              
            }
            else if (dir == NAV_DIR_DOWN)
            {
                p = queryPosByPt(fr.getMaxY() + 5); 
            }
        }
        else
        {
            if (getVarHeightMenu()->isReverse())
            {
                p = queryPosByPt(m_viewRect.getMaxY());  
            }
            else
            {
               p = queryPosByPt(m_viewRect.getMinY());                 
            }
        }

   

        // we cannot focus on the header
        if (p.isGroupHeader()) 
        {
            p.pos = 0;
        }

        setFocusItem(p);
        return VFX_TRUE;         
    }
    else if (focusItem.isValid() && !visibleRegion.isWithin(focusItem))
    {     
        VcpMenuPos highlightPos;

        if (visibleRegion.begin.group > getFocusItem().group ||
           (visibleRegion.begin.group == getFocusItem().group &&
            visibleRegion.begin.pos >= getFocusItem().pos))
        {
            if (getVarHeightMenu()->isReverse())
            {
                highlightPos = visibleRegion.end;
            }
            else
            {
                highlightPos = visibleRegion.begin;   
            }
        }
        else
        {
            if (getVarHeightMenu()->isReverse())
            {
                highlightPos = visibleRegion.begin;    
            }
            else
            {
                highlightPos = visibleRegion.end;
            }
        }

        if (!highlightPos.isGroupHeader())
        {
            setFocusItem(highlightPos);
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }        
    }
    else
    {
        VcpMenuPos f = focusItem;
        VfxRect fr = queryCellRect(focusItem);

        if (dir == NAV_DIR_UP)
        {
            if(getVarHeightMenu()->isReverse())
            {
                f = f.getNextPos(this, VFX_FALSE);                              
            }
            else
            {
                f = f.getPrevPos(this, VFX_FALSE);                              
            }

            if(!f.isValid())
            {
                VcpMenuPos p = vcpBaseMenuLayoutQueryMarginItemByPt(m_pMenu, this, VfxPoint(fr.getMinX(), fr.getMinY() - 5));           
                if(p.isValid())
                {
                   m_pMenu->setFocusMarginItem(p, VFX_TRUE);                    
                   return VFX_TRUE;
                }               
                return VFX_FALSE;
            }                       
        }
        if (dir == NAV_DIR_DOWN)
        {
            if(getVarHeightMenu()->isReverse())
            {
                f = f.getPrevPos(this, VFX_FALSE);                              
            }
            else         
            {
                f = f.getNextPos(this, VFX_FALSE);     
            }
            if(!f.isValid())
            {
                VcpMenuPos p = vcpBaseMenuLayoutQueryMarginItemByPt(m_pMenu, this, VfxPoint(fr.getMaxX(), fr.getMaxY() + 5));               
                if(p.isValid())
                {
                  m_pMenu->setFocusMarginItem(p, VFX_TRUE);                    
                  return VFX_TRUE;
                }               
                return VFX_FALSE;
            }
        }

        if (f.isValid())
        {
          m_pMenu->setFocusItem(f);
          return VFX_TRUE;
        }
    }
     

 
     return VFX_FALSE;

#endif 
}





