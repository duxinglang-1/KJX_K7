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
 *  vapp_setting_dlui_menu.cpp
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_THEMES_APPLICATION__) || defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) \
    || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__) || defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_setting_def.h"

#include "vcp_global_popup.h"
#include "vapp_fmgr.h"

#include "vapp_setting_launcher_scr_lock_gprot.h"
#include "vapp_setting_dlui_content_provider.h"
#include "vapp_setting_dlui_menu.h"

#include "vapp_setting_framework.h"
#include "vapp_setting_framework_gprot.h"

#include "Vapp_usb_gprot.h"
#include "vapp_theme_gprot.h"

extern "C"
{
#include "PhoneSetupResList.h"
#include "mmi_rp_file_type_def.h"

#include "MMIDataType.h"
#include "ps_public_enum.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/    

//**********************************************************************************
// VappVarUILayout
//**********************************************************************************

void VappVarUILayout::onInit()
{
    VcpBaseMenuLayout::onInit();
    
    m_cellWidth = PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP;
}

VappVarUILayout::ScrollDirEnum VappVarUILayout::getScrollDir()
{
    return SCROLLDIR_HORZ;
}

VfxS32 VappVarUILayout::getGroupCount()
{
    return m_groupCount;
}

void VappVarUILayout::setGroupCount(VfxS32 gNum)
{
    m_groupCount = gNum;
}

VfxS32 VappVarUILayout::getCellCount(VfxS32 group)
{
    VappVarUIMenu* menu = (VappVarUIMenu*)m_pMenu;
    return menu->getItemCount(group);
}

void VappVarUILayout::setTotalItem(VfxS32 totalCount)
{
   m_totalCount = totalCount;
}

VfxS32 VappVarUILayout::menuPosToIndex(VcpMenuPos pos)
{
    VappVarUIMenu* menu = (VappVarUIMenu*)m_pMenu;
    return menu->menuPosToIndex(pos);
}

VfxS32 VappVarUILayout::getContentLength()
{
    return m_totalCount*m_cellWidth + PREVIEW_BLANCK_GAP*2;
}

VfxBool VappVarUILayout::hasGroupHeader(VfxS32 group)
{
    return VFX_FALSE;
}

VcpMenuRegion VappVarUILayout::queryRegion(const VfxRect & r)
{
    return VcpMenuRegion(getCellByPos(r.origin),
                        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY())));
}

VcpMenuPos VappVarUILayout::getCellByPos(VfxPoint pt)
{
	VfxS32 groupNum = 0;
    VfxS32 cellCount = (pt.x-PREVIEW_BLANCK_GAP)/m_cellWidth;

    if (cellCount < 0)
    {
        cellCount = 0;
    }
    if (cellCount >=m_totalCount)
    {
        cellCount = m_totalCount - 1;
    }

    while(cellCount>=0&&groupNum<m_groupCount)
    {
        VfxS32 count = getCellCount(groupNum);
        if (cellCount<count)
            break;
        ++groupNum;
        cellCount -= count;        
    }

    VcpMenuPos p(groupNum, cellCount);
    if (p.pos < 0)
    {
        p.pos = 0;
    }
    else if(p.pos >= getCellCount(p.group))
    {
        p.pos = getCellCount(p.group) - 1;
    }

    return p;
}

VfxRect VappVarUILayout::queryCellRect(VcpMenuPos pos)
{
    VFX_DEV_ASSERT(pos.isValid());
    VFX_DEV_ASSERT(!pos.isGroupHeader());
    VfxS32 index = menuPosToIndex(pos);
    return VfxRect(index*m_cellWidth+PREVIEW_BLANCK_GAP, 0, m_cellWidth, getViewSize().height);
}

void VappVarUILayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = margin[2] = m_cellWidth;
    margin[1] = margin[3] = 0;
}

VfxBool VappVarUILayout::navDir(NavDirEnum dir)
{
    // Igore left and right
    if (NAV_DIR_UP == dir || NAV_DIR_DOWN == dir)
    {
        return VFX_FALSE;
    }

    // If there is no one is focused, we pick up one in the screen
    if (!(getFocusItem().isValid()))
    {
        VcpMenuPos p = getCellByPos(VfxPoint(m_viewRect.getMidX(), m_viewRect.getMidY()));
        setFocusItem(p);

        return VFX_TRUE;
    }

    VcpMenuPos p;
    if (dir == NAV_DIR_LEFT)
    {
        p = getFocusItem().getPrevPos(this, VFX_FALSE);
    }
    if (NAV_DIR_RIGHT == dir)
    {
        p = getFocusItem().getNextPos(this, VFX_FALSE);
    }
    if (p)
    {
        setFocusItem(p);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
//**********************************************************************************
// VappVarUICell
//**********************************************************************************
void VappVarUICell::onInit()
{
    VfxControl::onInit();
    setAnchor(0.5f, 0.5f);
    setIsOpaque(VFX_TRUE);

    VfxImageFrame* bgFrame;
    VFX_OBJ_CREATE(bgFrame, VfxImageFrame, this);
    bgFrame->setAnchor(0.5f, 0.0f);
    bgFrame->setPos((PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP)/2, 0);
    bgFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_SETTING_LAUNCHER_BG_L));
    bgFrame->setSize(PREVIEW_BG_WIDTH, PREVIEW_BG_HEIGHT);
    bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    VFX_OBJ_CREATE(m_timeline1, VfxFloatTimeline, this);
    m_timeline1->setTarget(this);
    m_timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_timeline1->setDurationTime(150);

    setAutoAnimate(VFX_TRUE);

	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
}

void VappVarUICell::onDeinit()
{
    m_timeline1->stop();
    m_singalFreeImgMem.emit(m_curPos, m_imageFrame);
    VfxControl::onDeinit();
}

void VappVarUICell::setHighlight(VfxBool isHighLight)
{
    m_highlight = isHighLight;
    if (!isHighLight)
        return ;
    
    if (NULL == m_hiPic)
    {
        VFX_OBJ_CREATE(m_hiPic, VfxImageFrame, this);
        m_hiPic->setAnchor(1.0f, 1.0f);
        m_hiPic->setPos(PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP/2, PREVIEW_BG_HEIGHT);
        m_hiPic->setImgContent(VfxImageSrc(IMG_ID_VAPP_SETTING_LAUNCHER_SELECT));
    }

    m_hiPic->bringToFront();
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    VfxAutoAnimate::commit();
}

VfxBool VappVarUICell::getHighlight() const
{
    return m_highlight; 
}

void VappVarUICell::enter(const VfxRect & r,VfxBool animation)
{
    updatePos(r, VFX_FALSE);

    if (animation)
    {
        m_timeline1->setStartTime(0);
        m_timeline1->setFromValue(0.0f);
        m_timeline1->setToValue(1.0f);
        m_timeline1->start();
    }
    else
    {
        setOpacity(1.0f);
    }
}

void VappVarUICell::leave(const VfxRect& r)
{
    m_timeline1->stop();
    m_timeline1->setStartTime(0);
    m_timeline1->setFromValue(1.0f);
    m_timeline1->setToValue(0.0f);
    m_timeline1->start();
}

void VappVarUICell::updatePos(const VfxRect & r,VfxBool isAnim)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);

    setPos(r.getMidX(), r.getMidY());
    setBounds(VfxRect(VfxPoint(0, 0), r.size));

    VfxAutoAnimate::commit();
}

void VappVarUICell::setImage(VfxFrame* imgFrame)
{
    m_imageFrame = imgFrame;

	if (NULL != imgFrame)
{
        addChildFrame(imgFrame);
	    m_imageFrame->setAnchor(0.5f, 0.0f);
	    m_imageFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_imageFrame->setPos(getSize().width/2, (PREVIEW_BG_HEIGHT-PREVIEW_IMG_HEIGHT+PREVIEW_SHADOW_T-PREVIEW_SHADOW_B)/2);
}

}

VfxFrame* VappVarUICell::getImage(void)
{
    return m_imageFrame;
}

//**********************************************************************************
// VappVarUIMenu
//**********************************************************************************
VappVarUIMenu::VappVarUIMenu(IVappDLUISettingProvider* dluiProvider)
    : m_dluiProvider(dluiProvider)
{
    m_itemCount = _getTotalItem();
    m_dluiProvider->m_signalReleaseAllScrnshot.connect(this, &VappVarUIMenu::releaseCachedImage);
    m_dluiProvider->m_signalUpdateScrnshot.connect(this, &VappVarUIMenu::updateCachedImage);
}

VappVarUIMenu::~VappVarUIMenu()
{
}

VcpBaseMenuLayout* VappVarUIMenu::createLayout()
{
    VappVarUILayout* layout;
    VFX_OBJ_CREATE_EX(layout, VappVarUILayout, this, (this));
    VfxS32 groupNum = getGroupCount();
    layout->setGroupCount(groupNum);
    layout->setTotalItem(m_itemCount);
    
    return layout;
}

VfxS32 VappVarUIMenu::menuPosToIndex(const VcpMenuPos& pos)
{
    VfxS32 index = pos.pos;
    VfxS32 group = pos.group;
    while (!(--group<0))
    {
        index += getItemCount(group);
    }

    return index;
}

VfxS32 VappVarUIMenu::getTotalItem() const
{
    return m_itemCount;
}

VfxS32 VappVarUIMenu::_getTotalItem()
{
    VfxS32 cellCount = 0;
    VfxS32 group = getGroupCount();
    for (VfxS32 i = 0; i<group; ++i)
    {
        cellCount += getItemCount(i);
    }

    return cellCount;
}

void VappVarUIMenu::freeImgScreenMem(const VcpMenuPos& curPos, VfxFrame* imgFrame)
{
    m_dluiProvider->freeDLUIScreenShot(curPos.group, curPos.pos, imgFrame);
}

void VappVarUIMenu::updateCachedImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappVarUICell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappVarUICell *)getCellIfPresent(p.group, p.pos);
		if (NULL != cell)
		{
            VfxFrame* imgFrame = m_dluiProvider->getDLUIScreenShot(p.group, p.pos);
            cell->setImage(imgFrame);
            cell->setHighlight(cell->getHighlight());
		}
    }
}


void VappVarUIMenu::releaseCachedImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappVarUICell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappVarUICell *)getCellIfPresent(p.group, p.pos);
		if (NULL != cell)
		{
            VfxFrame* imgFrame = cell->getImage();
            if (NULL != imgFrame)
            {
                cell->setImage(NULL);
                freeImgScreenMem(p, imgFrame);
            }
		}
    }
}


void VappVarUIMenu::forceCache(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappVarUICell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappVarUICell *)getCellIfPresent(p.group, p.pos);
		if (cell != NULL)
		{
            cell->preCache();
		}
    }
}


VfxFrame* VappVarUIMenu::createCell(VfxS32 group,VfxS32 pos)
{
    // get cell icon
    VfxFrame* imgFrame = m_dluiProvider->getDLUIScreenShot(group, pos);
    
    VappVarUICell* item;
    VFX_OBJ_CREATE_EX(item, VappVarUICell, this, (VcpMenuPos(group,pos)));
    item->setSize(VfxSize(PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP, PREVIEW_BG_HEIGHT));
    item->setImage(imgFrame);
    item->setHighlight(VFX_FALSE);
    item->m_singalFreeImgMem.connect(this, &VappVarUIMenu::freeImgScreenMem);

    if (m_dluiProvider->isCurUIDefault(group, pos))
    {
        item->setHighlight(VFX_TRUE);
    }

    return item;
}

VfxS32 VappVarUIMenu::getGroupCount() const
{
    return m_dluiProvider->getDLUIGroupCount();
}

VfxS32 VappVarUIMenu::getItemCount(VfxS32 group) const
{
    return m_dluiProvider->getDLUIItemCount(group);
}

void VappVarUIMenu::onUpdateCell(const VfxRect & rect,VfxS32 group,VfxS32 pos,VfxFrame * cell,VfxU32 flag)
{
    VappVarUICell* item = (VappVarUICell*)cell;

    VfxRect r = rect;
    ++r.origin.x;
    ++r.origin.y;
    r.size.width -= 2;
    r.size.height -= 2;

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(r, VFX_TRUE);
        }
        else
        {
            item->enter(r, VFX_FALSE);
        }
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(r);
    }
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->updatePos(r, VFX_FALSE);
    }
    else
    {
        item->updatePos(r, VFX_TRUE);
    }
}

void VappVarUIMenu::onTouchCell(VcpMenuPos cellPos, VcpBaseMenu::CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell)
{
    if (touchType == VcpBaseMenu::TouchTap)
    {
        //VappVarUICell* item = (VappVarUICell*)cell;
        //item->click();
        getLayout()->setFocusItem(cellPos);
    }
}

void VappVarUIMenu::onViewScrollEnd()
{
    VcpBaseMenu::onViewScrollEnd();

    m_isScrolling = VFX_FALSE;
    m_timer->stop();
    updateFocus();
    return;
}

void VappVarUIMenu::updateFocus()
{
    VappVarUILayout *layout = (VappVarUILayout *)getLayout();

    VfxRect rect = m_view->getBounds();
    VcpMenuRegion visibleRegion = layout->queryRegion(rect);

    VcpMenuRegionIter itr(layout, visibleRegion);
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        VfxRect r = layout->queryCellRect(p);
        
        VfxS32 sizeDiff = rect.size.width - r.size.width;
        VfxS32 originDiff = rect.origin.x - r.origin.x;
        
        //if (rect.intersectWith(r) == r)
	if (VFX_ABS(originDiff+sizeDiff)<r.size.width)
        {
            layout->setFocusItem(p, VFX_FALSE);
            break;
        }
    }
}

void VappVarUIMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    m_signalFocusItemChange.emit(focusItem.group, focusItem.pos);
}
#endif

