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
 *  vapp_gallery_shooting.cpp
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
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_GALLERY_SLIM__

#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_slim.h"
#include "cp/vapp_media_grid_cp.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_gallery_slim_viewer.h"
#include "vapp_gallery_slim_player.h"
#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"
#include "trc/vadp_app_trc.h"
#include "vapp_gallery_slim_index.h"
#include "vcp_base_menu.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

extern "C"
{
#include "AppMgrSrvGprot.h"
#include "FileMgrResDef.h"
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/
#define __GALLERY_GRID_FADE_IN_ENABLED_

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMediaGridComponentCell", VappMediaGridComponentCell, VfxControl);
VFX_IMPLEMENT_CLASS("VappMediaGridComponent", VappMediaGridComponent, VcpBaseMenu);

VappMediaGridComponent::VappMediaGridComponent() :
    m_isViewCellReady(VFX_FALSE)
    ,m_isCellFadeOut(VFX_FALSE)
    ,m_mediaList(NULL)
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    ,m_isMultiSelecting(VFX_FALSE)
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__*/

    ,m_waitingIcon(NULL)
{		
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    m_selectedSet.clearAll();
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__*/
}

void VappMediaGridComponent::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_ON_INIT);
    VcpBaseMenu::onInit();

    const float freeRunFactor = 1.3f;
    const VfxS32 duration = 1;

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(duration);
    m_timer->setDuration(duration);
    m_timer->m_signalTick.connect(this, &VappMediaGridComponent::onTimerTick);

    m_state = Opening;

    setSlowFactor(1.0f, 1.0f, freeRunFactor);
    m_isScrolling = VFX_FALSE;
}


void VappMediaGridComponent::onDeinit()
{
    m_timer->stop();

    VcpBaseMenu::onDeinit();
}

void VappMediaGridComponent::pauseUpdate(const VfxBool pause, const U32 line)
{
    if(NULL == m_timer)
        return;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_PAUSE_UPDATE, pause, line);
    if(pause)
        m_timer->stop();
    else
        m_timer->start();
}

VfxBool VappMediaGridComponent::onKeyInput(VfxKeyEvent &event)
{
    if(!m_mediaList.isValid())
    {
        return VFX_TRUE;
    }

    if(VFX_KEY_CODE_ARROW_UP == event.keyCode|| VFX_KEY_CODE_ARROW_DOWN == event.keyCode)
    {
        if(VFX_KEY_EVENT_TYPE_DOWN == event.type || VFX_KEY_EVENT_TYPE_REPEAT == event.type)
        {
            // find the reference point for next view
            const VfxRect currentView = getViewBounds();
            VfxPoint p = VfxPoint(0, currentView.getY() + currentView.getHeight());
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                p.y = currentView.getY();
            }
            // calculate the top-left point of next view
            const VcpMenuPos pos = getLayout()->queryPosByPt(p);
            if(-1 == pos.group)
            {
                // do nothing to avoid loop menu
                return VFX_TRUE;
            }

            // call onViewScrollStart() while scrolling is centainly happened
            onViewScrollStart();

            const VfxRect cellRect = getLayout()->queryCellRect(pos);
            VfxS32 yTopLeft = cellRect.getY() - getLayout()->GRID_MARGIN_Y;
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                yTopLeft = cellRect.getY() + cellRect.getHeight() + getLayout()->GRID_MARGIN_Y - currentView.getHeight();
            }
            VfxRect nextView = VfxRect(currentView.getX(), yTopLeft, currentView.getWidth(), currentView.getHeight());
            makeVisible(nextView, VFX_TRUE);

            onViewScrollEnd();
            return VFX_TRUE;
        }
    }
    //return VcpBaseMenu::onKeyInput(event);
    return VFX_TRUE;
}

VcpBaseMenuLayout* VappMediaGridComponent::createLayout()
{
    VappMediaGridComponentLayout *layout;
    VFX_OBJ_CREATE_EX(layout, VappMediaGridComponentLayout, this, (this));
    return layout;
}

VfxFrame* VappMediaGridComponent::createCell(VfxS32 group, VfxS32 pos)
{
    // create cell
    VappMediaGridComponentCell *cell = NULL;
    VFX_OBJ_CREATE(cell, VappMediaGridComponentCell, this);
    cell->setPosIndex(group, pos);
    getLayout()->configCellSize(cell);

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    cell->setSelected(isMultiSelecting(), isSelected(pos));
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

    return cell;
}

void VappMediaGridComponent::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    if(m_mediaList.isValid())
    {
        VappMediaGridComponentCell *cell = (VappMediaGridComponentCell *)cellFrame;
        cell->closeImage(m_mediaList.get());
    }
    VFX_OBJ_CLOSE(cellFrame);
}

VfxFrame* VappMediaGridComponent::createGroupHeader(VfxS32 group)
{
    VappMediaGridComponentHeader* item;
    VFX_OBJ_CREATE(item, VappMediaGridComponentHeader, this);
    return item;
}

void VappMediaGridComponent::onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
{
    VFX_OBJ_CLOSE(groupFrame);
}

void VappMediaGridComponent::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cellFrame, VfxU32 flag)
{
    VappMediaGridComponentCell* item = (VappMediaGridComponentCell*) cellFrame;
    VappMediaGridComponentCell::CellDataType type = VappMediaGridComponentCell::DATA_TYPE_MEMORY;
    VFX_ASSERT(item != NULL);

    IVappGalleryMediaList *pMediaList = (m_mediaList.isValid()) ? m_mediaList.get() : NULL;
    if(pMediaList)
    {
        VfxBool isVideo = VFX_FALSE;
        VfxBool is3dImg = VFX_FALSE;

        VappGalleryMediaGroupType groupType = pMediaList->getMediaGroupType(VcpMenuPos(group, pos));
		if(groupType != MEDIA_GROUP_WAIT_DECODING)
		{
	        isVideo = (MEDIA_GROUP_VIDEO == groupType)? VFX_TRUE : VFX_FALSE;
	        if(MEDIA_GROUP_VIDEO != groupType)
	        {
	            // if cell content is not video, then check if it is 3D image (mav or 3D red-blue image)
	            is3dImg = is3dPhoto(VcpMenuPos(group, pos));
	        }

	        // update cell info
	        item->setVideoOverlay(isVideo);
	        item->set3dPhotoBadge(is3dImg);
		}
		else
		{
			type = VappMediaGridComponentCell::DATA_TYPE_DEFAULT;
		}
    }

    // TODO: checking source list limit here
    // e.g. File system sorting limit.
    VfxBool overLimit = VFX_FALSE;
    if (overLimit && m_isScrolling)
    {
        item->enter(rect, VFX_TRUE);
        item->updateImage(pMediaList, VappMediaGridComponentCell::DATA_TYPE_DEFAULT);
    }

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        VfxBool bAnim = (flag & VCP_CELL_FLAG_OPENING) ? VFX_TRUE : VFX_FALSE;
        item->enter(rect, bAnim);
        item->updateImage(pMediaList, type);
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(rect);
    }
    else
    {
        VfxBool bMoveAnim = (flag & VCP_CELL_FLAG_FORCESET) ? VFX_FALSE : VFX_TRUE;
        item->updateImage(pMediaList, type);
        item->updatePos(rect, bMoveAnim);
    }
}

void VappMediaGridComponent::onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag)
{
    VappMediaGridComponentHeader* item = (VappMediaGridComponentHeader*) header;

    if(m_mediaList.isValid())
    {
        VfxWString groupName;
        m_mediaList.get()->getGroupName(group, groupName);
        item->setString(groupName);
    }
    else
    {
        VfxWString groupName;
        groupName.setEmpty();
        item->setString(groupName);
    }

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(rect, VFX_TRUE);
        }
        else
        {
            item->enter(rect, VFX_FALSE);
        }
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(rect);
    }
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->updatePos(rect, VFX_FALSE);
    }
    else
    {
        item->updatePos(rect, VFX_TRUE);
    }
}

void VappMediaGridComponent::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame *cell)
{
    if(m_mediaList.isValid() && m_mediaList.get()->isReloading())
        return;

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    if(isMultiSelecting())
    {
        VappMediaGridComponentCell *item = VFX_OBJ_DYNAMIC_CAST(cell, VappMediaGridComponentCell);
        if(m_selectedSet.isSet(pos))
        {
            m_selectedSet.clear(pos);
            item->setSelected(VFX_TRUE, VFX_FALSE);
        }
        else
        {
            m_selectedSet.set(pos);
            item->setSelected(VFX_TRUE, VFX_TRUE);
        }
        item->invalidate();

        m_signalThumbTapped.emit(VcpMenuPos(group, pos), cell);
    }
    else
#endif

    {
        // in FTO, there is no "highlight" stage,
        // we invoke tapped event directly.
        m_signalThumbTapped.emit(VcpMenuPos(group, pos), cell);
    }
}

void VappMediaGridComponent::onTouchCell(
    VcpMenuPos          cellPos,     // [IN] The cell position
    CellTouchTypeEnum   touchType,   // [IN] The touch type
    VfxPoint            pt,          // [IN] The pen position
    VfxFrame            *cell        // [IN] The cell object
)
{
    do
    {
        if(!m_mediaList.isValid())
            return;

        // TODO: skip if media list is reloading...

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        // skip if now is multiselecting
        if(isMultiSelecting())
            return;
#endif
        // TODO: if fileOP exist

        // handle long press event only
        // for tap event, we process it in VappMediaGridComponent::onTapCel
        if(TouchLongTap != touchType)
            return;

        if(m_mediaList.get()->isReloading())
            return;
    }while(0);

    m_signalThumbLongPressed.emit(cellPos);
}

void VappMediaGridComponent::onCellFadeOut()
{
    VfxS32 denominator;
    VfxS32 index;
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;

    VcpMenuRegionIter itr(this, getRealContentRegion());

    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

    m_isCellFadeOut = VFX_TRUE;
    stopScrolling();

    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        S32 moveLength;

        VappMediaGridComponentCell* cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
#ifdef __GALLERY_GRID_FADE_IN_ENABLED__
        cell->setAutoAnimate(VFX_TRUE);
#else
        cell->setAutoAnimate(VFX_FALSE);
#endif
        if (cell)
        {
            denominator = getLayout()->getCellNumPerRow() / 2;
            index = p.pos % getLayout()->getCellNumPerRow();

            moveLength = mainScreenSize.width * (getLayout()->getCellNumPerRow()/2 + 1) /getLayout()->getCellNumPerRow();

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(VappMediaGridComponentLayout::CELL_FADEOUT_DURATION);

            if (index / denominator == 0)
            {
                cell->setPos(VfxPoint((-moveLength) + cell->getPos().x, cell->getPos().y));
            }
            else if (index / denominator == 1 && index % denominator == 0)
            {
                if ((p.pos / getLayout()->getCellNumPerRow()) % 2 == 0)
                {
                    cell->setPos(VfxPoint((-moveLength) + cell->getPos().x, cell->getPos().y));
                }
                else
                {
                    cell->setPos(VfxPoint(moveLength + cell->getPos().x, cell->getPos().y));
                }
            }
            else/* if (index / denominator > 1)*/
            {
                cell->setPos(VfxPoint(moveLength + cell->getPos().x, cell->getPos().y));
            }

            VfxAutoAnimate::commit();
        }
    }
}


void VappMediaGridComponent::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    // there is no focus concept in FTO W11.12
}

void VappMediaGridComponent::postSetBounds(VfxS32 l, VfxS32 t, VfxS32 w, VfxS32 h)
{
    setBounds(VfxRect(l,t,w,h));
    update();
}


void VappMediaGridComponent::postSetPos(VfxS32 x, VfxS32 y)
{
    setPos(x,y);
    update();
}

void VappMediaGridComponent::onViewScrollStart()
{
    VcpBaseMenu::onViewScrollStart();

    pauseUpdate(VFX_TRUE, __LINE__);

    m_isScrolling = VFX_TRUE;

    m_isViewCellReady = VFX_FALSE;

    if(m_mediaList.isValid())
    {
        m_mediaList.get()->enableBackgroundDecode(VFX_FALSE);
    }
}


void VappMediaGridComponent::onViewScrollEnd()
{
    VcpBaseMenu::onViewScrollEnd();

    m_isScrolling = VFX_FALSE;
    pauseUpdate(VFX_TRUE, __LINE__);
    m_liteUpdateLastPos = -1;

    if(m_mediaList.isValid())
    {
        m_mediaList.get()->enableBackgroundDecode(VFX_TRUE);
    }

#ifdef __MMI_VUI_MEDIAWALL_LITE_DISPLAY__
    liteUpdate();
#else
    heavyUpdate();
#endif
    if (m_isCellFadeOut)
        return;
    // no need to update focus item in FTO.
}

void VappMediaGridComponent::onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion)
{
    if(m_isScrolling)
    {
        return;
    }

    heavyUpdate();

    // there is no focus in FTO
}

VfxBool VappMediaGridComponent::getIsViewCellReady()
{
    VappMediaGridComponentCell* cell;
    VcpMenuPos p;
    VfxBool ret = VFX_TRUE;
    VcpMenuRegionIter itr(this, getRealContentRegion());

    ret = VFX_TRUE;
    while(!itr.isEnd())
    {
        p = itr.next();

        cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
        if (cell && (cell->getImageState() != VappMediaGridComponentCell::STATE_IMAGE) && getIsCellVisiable(p))
        {
           ret = VFX_FALSE;
           break;
        }
    }
    return ret;
}

void VappMediaGridComponent::setDummyCellCount(VfxS32 cellCount)
{
    if(getLayout())
    {
        getLayout()->setCellCountCache(cellCount);
    }
}

void VappMediaGridComponent::setMediaList(IVappGalleryMediaList *pThumbSource)
{
    if(m_mediaList.isValid() && m_mediaList.get() != pThumbSource)
    {
        m_mediaList->getListEvent()->disconnect(this, &VappMediaGridComponent::onListPrepared);
        m_mediaList.get()->getDecodeEvent()->disconnect(this, &VappMediaGridComponent::onDecodeResult);
        m_mediaList.get()->getListReloadStartEvent()->disconnect(this, &VappMediaGridComponent::onReloadListStart);
        m_mediaList.get()->getListReloadFinishedEvent()->disconnect(this, &VappMediaGridComponent::onReloadListFinished);
    }

    m_mediaList = pThumbSource;

    if(m_mediaList.isValid())
    {
        m_mediaList->getListEvent()->connect(this, &VappMediaGridComponent::onListPrepared);
        m_mediaList.get()->getDecodeEvent()->connect(this, &VappMediaGridComponent::onDecodeResult);
        m_mediaList.get()->getListReloadStartEvent()->connect(this, &VappMediaGridComponent::onReloadListStart);
        m_mediaList.get()->getListReloadFinishedEvent()->connect(this, &VappMediaGridComponent::onReloadListFinished);

        getLayout()->setMediaList(m_mediaList.get());

        if(!(m_mediaList.get()->isPrepared()))
        {
            m_mediaList.get()->prepareList();
        }
    }

    // update layout
    update();
}

void VappMediaGridComponent::releaseAllCachedImage()
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappMediaGridComponentCell* cell = NULL;
    VcpMenuPos p;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
        cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
        cell->closeImage(m_mediaList.get());
        cell->setLoadingIcon();
    }
}

void VappMediaGridComponent::heavyUpdate(void)
{
    GALLERY_MEASURE_TIME_START("GGH");

    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappMediaGridComponentCell* cell;
    VcpMenuPos p;
    VappGalleryDecodeResult decodeResult = OK;
    VfxBool isCellDecode = VFX_FALSE;

    pauseUpdate(VFX_TRUE, __LINE__);

    if (m_isScrolling || !m_mediaList.isValid())
        return;

    while(!itr.isEnd())
    {
        p = itr.next();

        if(p.isGroupHeader())
        {
            continue;
        }

        cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);

        isCellDecode = VFX_FALSE;
        if (!m_isViewCellReady && getIsCellVisiable(p))
        {
            isCellDecode = VFX_TRUE;
        }
        else if (m_isViewCellReady)
        {
            isCellDecode = VFX_TRUE;
        }

        if (cell && (cell->getImageState() != VappMediaGridComponentCell::STATE_IMAGE) && isCellDecode)
        {
            GALLERY_MEASURE_TIME("UNB");

            GALLERY_MEASURE_TIME_START("GGD");
            // otherwise we continue decode & cache the thumbnail
            VfxImageBuffer thumbBuf;
            decodeResult = m_mediaList.get()->startDecodeThumb(p, thumbBuf);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_HEAVY_UPDATE, p.group, p.pos, decodeResult);
            switch(decodeResult)
            {
            case OK:
                // already decoded, directly update
                cell->setImageBuffer(thumbBuf);
                pauseUpdate(VFX_FALSE, __LINE__);   // continue next
                break;
            case FORMAT_UNSUPPORTED:
                cell->setErrorIcon(__LINE__);
                pauseUpdate(VFX_FALSE, __LINE__);   // continue next
                break;
            case DRM_LOCKED:
                cell->setDRMIcon();
                pauseUpdate(VFX_FALSE, __LINE__);   // continue next
                break;
            default:
                // decoding, waiting for decodeCallBack
                break;
            }
            break;
        }
    }

    if (!m_isViewCellReady && getIsViewCellReady())
    {
        m_isViewCellReady = VFX_TRUE;
        pauseUpdate(VFX_FALSE, __LINE__);
    }
    GALLERY_MEASURE_TIME_STOP("GGH");
}

void VappMediaGridComponent::heavyUpdate(VfxS32 index, VappGalleryDecodeResult result)
{
    GALLERY_MEASURE_TIME_START("GGh");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_HEAVY_UPDATE_WITH_INDEX, 0, index, result);
    const int group = 0;
    VappMediaGridComponentCell *cell = (VappMediaGridComponentCell*)getCellIfPresent(group, index);

    if (cell && (cell->getImageState() != VappMediaGridComponentCell::STATE_IMAGE))
    {
        if (result == OK)
            cell->updateImage(m_mediaList.get(), VappMediaGridComponentCell::DATA_TYPE_MEMORY);
        else if (result == DRM_LOCKED)
            cell->setDRMIcon();
		else
            cell->setErrorIcon(__LINE__);
    }

    GALLERY_MEASURE_TIME_STOP("GGh");
    heavyUpdate();
}

void VappMediaGridComponent::liteUpdate(void)
{
    GALLERY_MEASURE_TIME_START("GGL");
    VcpMenuPos p;
    VcpMenuRegion currRegion = getRealContentRegion();
    VappMediaGridComponentCell* cell;
    VfxBool is_end = VFX_FALSE;

    if (currRegion.begin.pos >= 0 && currRegion.end.pos >= 0 && m_liteUpdateLastPos < 0)
    {
        m_liteUpdateLastPos = currRegion.begin.pos;
        is_end = VFX_FALSE;
    }
    else
    {
        m_liteUpdateLastPos++;
        if (m_liteUpdateLastPos > currRegion.end.pos)
        {
            is_end = VFX_TRUE;
        }
        else
        {
            is_end = VFX_FALSE;
        }
    }

    if (is_end)
    {
        m_liteUpdateLastPos = -1;
        heavyUpdate();
    }
    else
    {
        p.group = 0;
        p.pos = m_liteUpdateLastPos;
        cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
        if (cell && cell->getImageState() != VappMediaGridComponentCell::STATE_IMAGE)
        {
            cell->updateImage(m_mediaList.get(), VappMediaGridComponentCell::DATA_TYPE_MEMORY);
        }
        pauseUpdate(VFX_FALSE, __LINE__);
    }
    GALLERY_MEASURE_TIME_STOP("GGL");
}

void VappMediaGridComponent::update()
{
    if(getLayout())
    {
        getLayout()->setMediaList(m_mediaList.get());
    }
    VcpBaseMenu::updateLayout();
}

void VappMediaGridComponent::onReloadListStart(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_ON_RELOAD_LIST, mediaPos.group, mediaPos.pos, 0);
    pauseUpdate(VFX_TRUE, __LINE__);
    showWaitingIcon(VFX_TRUE);
}
void VappMediaGridComponent::onReloadListFinished(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_ON_RELOAD_LIST, mediaPos.group, mediaPos.pos, 1);
	VappMediaGridComponentCell* cell;
    VcpMenuPos p;
    VcpMenuRegionIter itr(this, getRealContentRegion());

	IVappGalleryMediaList *pMediaList = NULL;
	VfxBool isVideo = VFX_FALSE;
	VfxBool is3dImg = VFX_FALSE;
	pMediaList = (m_mediaList.isValid()) ? m_mediaList.get() : NULL;
	while(!itr.isEnd() && pMediaList)
    {
    	p = itr.next();
        cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
        if (cell && cell->getImageState() != VappMediaGridComponentCell::STATE_IMAGE)
        {
	        isVideo = (MEDIA_GROUP_VIDEO == pMediaList->getMediaGroupType(VcpMenuPos(p.group, p.pos)))? VFX_TRUE : VFX_FALSE;
	        // if cell content is not video, then check if it is 3D image (mav or 3D red-blue image)
	        is3dImg = !isVideo && is3dPhoto(VcpMenuPos(p.group, p.pos));
	        // update cell info
	        cell->setVideoOverlay(isVideo);
	        cell->set3dPhotoBadge(is3dImg);
        }
    }
	
    pauseUpdate(VFX_FALSE, __LINE__);
    showWaitingIcon(VFX_FALSE);
}

void VappMediaGridComponent::showWaitingIcon(const VfxBool show)
{
    if(NULL == m_waitingIcon)
    {
        VFX_OBJ_CREATE(m_waitingIcon, VcpActivityIndicator, this);
        m_waitingIcon->setAnchor(0.5f, 0.5f);
        m_waitingIcon->setPos(getSize().width / 2, getSize().height / 2);
        m_waitingIcon->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID);
        m_waitingIcon->setHiddenWhenStopped(VFX_TRUE);
    }

    if(show)
    {
        m_waitingIcon->start();
        m_waitingIcon->bringToFront();
    }
    else
    {
        m_waitingIcon->stop();
        m_waitingIcon->sendToBack();
    }
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
VfxBool VappMediaGridComponent::isSelected(VfxU32 index)
{
    if(isMultiSelecting())
    {
        return m_selectedSet.isSet(index);
    }
    return VFX_FALSE;
}

VfxBool VappMediaGridComponent::isMultiSelecting()const
{
    return m_isMultiSelecting;
}

void VappMediaGridComponent::beginMultiSelect()
{
    if(isMultiSelecting())
    {
        return;
    }

    m_isMultiSelecting = VFX_TRUE;
    m_selectedSet.clearAll();
    setAllSelected(VFX_FALSE);
}

VfxBool VappMediaGridComponent::isAllSelected()
{
    if(!getLayout())
    {
        return VFX_FALSE;
    }

    for(VfxS32 g = 0; g < getLayout()->getGroupCount(); ++g)
    {
        if(!m_selectedSet.isAllSet(g, 0, getLayout()->getCellCount(g)))
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

VfxBool VappMediaGridComponent::isAnySelected()
{
    if(!getLayout())
    {
        return VFX_FALSE;
    }

    for(VfxS32 g = 0; g < getLayout()->getGroupCount(); ++g)
    {
        if(m_selectedSet.isAnySet(g, 0, getLayout()->getCellCount(g)))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappMediaGridComponent::setAllSelected(VfxBool isSelected)
{
    // update selection state
    if(isSelected)
    {
        m_selectedSet.setAll();
    }
    else
    {
        m_selectedSet.clearAll();
    }

    // redraw visible cells.
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VcpMenuPos p;
    const VfxBool isSelecting = isMultiSelecting();
    // make sure all currently visible cells are updated.
    while(!itr.isEnd())
    {
        p = itr.next();
        VappMediaGridComponentCell* cell = (VappMediaGridComponentCell*)getCellIfPresent(p.group, p.pos);
        cell->setSelected(isSelecting, isSelected);
        cell->invalidate();
    }
}

void VappMediaGridComponent::endMultiSelect()
{
    if(!isMultiSelecting())
    {
        return;
    }

    m_isMultiSelecting = VFX_FALSE;
    m_selectedSet.clearAll();
    setAllSelected(VFX_FALSE);
}
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */


VfxS32 VappMediaGridComponent::getDisplayIdx()
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VcpMenuPos p = itr.next();
    return p.pos;
}


void VappMediaGridComponent::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    GALLERY_MEASURE_TIME_LABEL("Gpt");

    m_timer->stop();
    if (!m_isScrolling)
    {
        if (m_liteUpdateLastPos >= 0)
            liteUpdate();
        else
            heavyUpdate();
    }
}

void VappMediaGridComponent::onReset()
{
    reset();
}

void VappMediaGridComponent::onListPrepared(VappGalleryPrepareResult prepareResult)
{
    update();
}

void VappMediaGridComponent::onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result)
{
    GALLERY_MEASURE_TIME("DCB");
    heavyUpdate(index.pos, result);
}

VfxBool VappMediaGridComponent::getIsInViewRegion(VcpMenuPos Pos)
{
    VfxPoint viewPoint;
    VfxSize viewSize;
    VfxRect rect;
    VappMediaGridComponentCell* cell = (VappMediaGridComponentCell*)getCellIfPresent(Pos.group, Pos.pos);;

    if (!cell)
        return VFX_FALSE;

    VappMediaGridComponentLayout *vLayout = getLayout();
    viewPoint = vLayout->getViewPosition();
    viewSize = vLayout->getViewDimension();
    rect = vLayout->queryCellRect(Pos);

    if (rect.getMinX() >= viewPoint.x &&
        rect.getMinY() >= viewPoint.y &&
        rect.getMaxX() <= viewPoint.x + viewSize.width &&
        rect.getMaxY() <= viewPoint.y + viewSize.height)
    {
        return VFX_TRUE;
    }


    return VFX_FALSE;

}


VfxBool VappMediaGridComponent::getIsCellVisiable(VcpMenuPos Pos)
{
    VfxPoint viewPoint;
    VfxSize viewSize;
    VfxRect rect;
    VappMediaGridComponentCell* cell = (VappMediaGridComponentCell*)getCellIfPresent(Pos.group, Pos.pos);;

    if (!cell)
        return VFX_FALSE;

    VappMediaGridComponentLayout *vLayout = getLayout();
    viewPoint = vLayout->getViewPosition();
    viewSize = vLayout->getViewDimension();
    rect = vLayout->queryCellRect(Pos);

    if(0 == rect.getWidth() ||
       0 == rect.getHeight())
    {
        return VFX_FALSE;
    }
    else if (rect.getMinX() >= viewPoint.x &&
        rect.getMinY() >= viewPoint.y + viewSize.height &&
        rect.getMaxX() >= viewPoint.x &&
        rect.getMaxY() >= viewPoint.y + viewSize.height)
    {
        return VFX_FALSE;
    }
    else if (rect.getMinX() >= viewPoint.x &&
             rect.getMinY() <= viewPoint.y &&
             rect.getMaxX() >= viewPoint.x &&
             rect.getMaxY() <= viewPoint.y)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;

}

VfxBool VappMediaGridComponent::is3dPhoto(VcpMenuPos p) const
{
    if(!m_mediaList.isValid())
        return VFX_FALSE;

    VfxWString path = VFX_WSTR_EMPTY;
    if(OK != m_mediaList.get()->getMediaPath(p, path))
        return VFX_FALSE;

    // multi angle image
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    GALLERY_MEASURE_TIME_START("Gft");
    const filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)path.getBuf());
    GALLERY_MEASURE_TIME_STOP("Gft");
    if(FMGR_TYPE_MAV == fileType)
    {
        return VFX_TRUE;
    }
#endif

    // 3D red blue image
#if defined(__3D_IMAGE_SUPPORT__) && defined(EXIF_SUPPORT)
    const VfxBool is3DRedBlueImg = is3DRedBlueImage(path.getBuf());
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][GridCP] is3dPhoto, is3DRedBlue[%d]", is3DRedBlueImg); 
    return is3DRedBlueImg;
#endif

    return VFX_FALSE;
}

/*****************************************************************************
 * VappMediaGridComponentLayout
 *****************************************************************************/
VappMediaGridComponentLayout::VappMediaGridComponentLayout(VcpBaseMenu* menu) :
    VcpBaseMenuLayout(menu),
    m_mediaList(NULL),
    m_groupCount(1),
    m_cellCountCache(0)
{
}

VappMediaGridComponentLayout::~VappMediaGridComponentLayout()
{
    m_mediaList = NULL;
}

void VappMediaGridComponentLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
    m_mediaList = NULL;
    m_groupCount = 1;
    m_cellNumPerRow = CELL_NUM_PER_ROW;
    for(int i = 0; i < MAX_GROUP_CACHE_NUM; ++i)
    {
        m_groupStartPos[i] = -1;
    }
}

VfxS32 VappMediaGridComponentLayout::getGroupCount()
{
    if(NULL == m_mediaList)
    {
        // if there are 1st group cell count cache,
        // return 1 group
        return m_cellCountCache ? 1: 0;
    }
    return m_mediaList->getGroupCount();
}

VfxBool VappMediaGridComponentLayout::isMultiGroupMode()
{
    return getGroupCount() > 1;
}

VfxS32 VappMediaGridComponentLayout::getCellCount(VfxS32 group)
{
    if(NULL == m_mediaList)
    {
        if(0 == group)
        {
            return m_cellCountCache;
        }
        else
        {
            return 0;
        }
    }

    VfxS32 ret = m_mediaList->getMediaCountInGroup(group);
    if(0 == group)
    {
        m_cellCountCache = ret;
    }
    return ret;
}

VfxBool VappMediaGridComponentLayout::hasGroupHeader(VfxS32 group)
{
    return isMultiGroupMode();
}

VfxS32 VappMediaGridComponentLayout::getContentLengthInGroup(VfxS32 group)
{
    const VfxS32 extraGroupHeight = isMultiGroupMode() ? HEADER_HEIGHT + GRID_MARGIN_Y * 2 : GRID_MARGIN_Y * 2;
    VfxS32 row = (getCellCount(group) + m_cellNumPerRow - 1) / m_cellNumPerRow;
    return row * CELL_HEIGHT + extraGroupHeight;
}

VfxS32 VappMediaGridComponentLayout::getGroupStart(VfxS32 group, VfxBool forceRefresh)
{
    if(group >= MAX_GROUP_CACHE_NUM ||
       group < 0)
    {
        VFX_DEV_ASSERT(VFX_FALSE);
    }

    if(-1 != m_groupStartPos[group] && !forceRefresh)
    {
        return m_groupStartPos[group];
    }

    // otherwise we perform calculation and cache the result before return.
    VfxS32 offset = 0;
    for(int g = 0; g < getGroupCount(); ++g)
    {
        m_groupStartPos[g] = offset;
        offset += getContentLengthInGroup(g);
    }

    return m_groupStartPos[group];
}

VfxS32 VappMediaGridComponentLayout::getContentLength()
{
    if (m_cellNumPerRow == 0)
        return 0;

    if(!isMultiGroupMode())
    {
        return getContentLengthInGroup(0) + GRID_MARGIN_Y;
    }
    else
    {
        // multiple group requires group header, plus all content length
        // of the group.
        const VfxS32 lastGroup = getGroupCount() - 1;
        const VfxS32 lastGroupStart = getGroupStart(lastGroup);
        return lastGroupStart + getContentLengthInGroup(lastGroup) + GRID_MARGIN_Y * 2;
    }
}

VcpMenuRegion VappMediaGridComponentLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
                getCellByPos(r.origin),
                getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
            );
}

VfxS32 VappMediaGridComponentLayout::getGroupByPos(const VfxPoint &pt)
{
    // TODO: we only support vertical layout now.
    const VfxS32 y = pt.y;
    if (y < 0)
    {
        return 0;
    }

    const VfxS32 lastGroup = getGroupCount() - 1;

    // linear search through groups
    for (VfxS32 g = 0; g < getGroupCount(); ++g)
    {
        if (y >= getGroupStart(g) && (g + 1) <= lastGroup && y < getGroupStart(g + 1))
            return g;
    }

    return lastGroup;
}

VcpMenuPos VappMediaGridComponentLayout::getCellByPosInGroup(VfxS32 group, const VfxPoint &pt, VfxBool clampToValidRegion)
{
    VcpMenuPos p;
    p.group = group;

    if (m_cellNumPerRow == 0)
    {
        if(clampToValidRegion)
        {
            p.group = group;
            p.pos = 0;
            return p;
        }
        else
        {
            p.invalid();
            return p;
        }
    }

    VfxS32 row = (pt.y - GRID_MARGIN_Y) / CELL_HEIGHT;
    VfxS32 col = VFX_MAX(pt.x - 1, 0) / CELL_WIDTH;
    p.pos = row * m_cellNumPerRow + col;

    if (p.pos < 0)
    {
        if(clampToValidRegion)
        {
            p.pos = 0;
        }
        else
        {
            p.invalid();
        }

    }
    if (p.pos >= getCellCount(p.group))
    {
        if(clampToValidRegion)
        {
            p.pos = getCellCount(p.group) - 1;
        }
        else
        {
            p.invalid();
        }
    }

    return p;
}

VcpMenuPos VappMediaGridComponentLayout::getCellByPos(const VfxPoint &pt, VfxBool clampToValidRegion)
{
    if(!isMultiGroupMode())
    {
        return getCellByPosInGroup(0, pt, clampToValidRegion);
    }
    else
    {
        const VfxS32 group = getGroupByPos(pt);

        VfxS32 offset = pt.y - getGroupStart(group);

        if(offset < HEADER_HEIGHT)
        {
            // invalid pos means group header.
            VcpMenuPos p;
            p.invalid();
            p.group = group;
            return p;
        }

        offset -= (HEADER_HEIGHT + GRID_MARGIN_Y * 2);
        return getCellByPosInGroup(group, VfxPoint(pt.x, offset), clampToValidRegion);
    }
}

VcpMenuPos VappMediaGridComponentLayout::queryPosByPt(const VfxPoint& pt)
{
    // do not clamp, return invalid region if none hit
    return getCellByPos(pt, VFX_FALSE);
}

VfxRect VappMediaGridComponentLayout::queryGroupHeaderRect(VfxS32 group)
{
    if(!isMultiGroupMode())
    {
        return VfxRect(0, 0, 0, 0);
    }
    else
    {
        return VfxRect(
            0,
            getGroupStart(group) + GRID_MARGIN_Y * 2,
            getViewSize().width,
            HEADER_HEIGHT);
    }
}

VfxRect VappMediaGridComponentLayout::queryCellRect(VcpMenuPos pos)
{
    if(pos.group < 0 || m_cellNumPerRow == 0 || pos.pos < -1)
        return VfxRect(-1, -1, 0, 0);

    if(!isMultiGroupMode() && pos.pos <= -1)
    {
        // single group mode should not have
        // group cell
        return VfxRect(-1, -1, 0, 0);
    }

    if(pos.group >= getGroupCount() || pos.pos >= getCellCount(pos.group))
        return VfxRect(-1, -1, 0, 0);

    VfxS32 y = (pos.pos / m_cellNumPerRow) * CELL_HEIGHT + CELL_INNER_Y;
    VfxS32 x = (pos.pos % m_cellNumPerRow) * CELL_WIDTH + CELL_INNER_X;

    if(isMultiGroupMode())
    {
        y += getGroupStart(pos.group) + HEADER_HEIGHT + GRID_MARGIN_Y * 2;
    }

    y += GRID_MARGIN_Y;

    return VfxRect(x, y, CELL_WIDTH - CELL_INNER_X * 2, CELL_HEIGHT - CELL_INNER_Y * 2);
}

VfxBool VappMediaGridComponentLayout::navDir(NavDirEnum dir)
{
    // If there is no one is focused, we pick up one in the screen
    if (!getFocusItem().isValid())
    {
        VcpMenuPos p = getCellByPos(m_viewRect.origin);
        // we cannot focus on the header
        if (p.isGroupHeader())
        {
            p.pos = 0;
        }
        setFocusItem(p);
        return VFX_TRUE;
    }

    VcpMenuPos p;
    if (dir == NAV_DIR_UP)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_cellNumPerRow;
        VfxS32 r = p.pos / m_cellNumPerRow;
        VfxS32 group_row = (getCellCount(p.group)-1) / m_cellNumPerRow;

        if (r > 0)
        {
            r--;
            p.pos = r * m_cellNumPerRow + c;
        }
        else
        {
            if (p.group <= 0)
            {
                p.group = 0;
                if (group_row > 0)
                {
                    p.pos += group_row * m_cellNumPerRow;
                    if (p.pos > getCellCount(p.group)-1)
                    {
                        p.pos = getCellCount(p.group)-1;
                    }
                }
                else
                    p.pos = 0;
            }
            else
            {
                p.group--;

                VfxS32 n_group_row = getCellCount(p.group) / m_cellNumPerRow;

                p.pos = n_group_row * m_cellNumPerRow + c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
    }
    else if (dir == NAV_DIR_DOWN)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_cellNumPerRow;
        VfxS32 r = p.pos / m_cellNumPerRow;
        VfxS32 group_row = (getCellCount(p.group) - 1) / m_cellNumPerRow;

        if (r >= group_row)
        {
            p.group++;
            if (p.group >= getGroupCount())
            {
                p.group = getGroupCount() - 1;
                if (group_row > 0)
                    p.pos = c;
                else
                    p.pos = getCellCount(p.group) - 1;
            }
            else
            {
                p.pos = c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        else
        {
            p.pos = (r + 1) * m_cellNumPerRow + c;
            if (p.pos >= getCellCount(p.group))
            {
                p.pos = getCellCount(p.group) - 1;
            }
        }
    }
    else if (dir == NAV_DIR_LEFT)
    {
        p = getFocusItem();
        if (p.pos == 0)
            p.pos = getCellCount(p.group) - 1;
        else
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
    }
    else if (dir == NAV_DIR_RIGHT)
    {
        p = getFocusItem();
        if (p.pos == getCellCount(p.group) - 1)
            p.pos = 0;
        else
            p = getFocusItem().getNextPos(this, VFX_FALSE);
    }
    if (p)
    {
        setFocusItem(p);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappMediaGridComponentLayout::setFocusItem(VcpMenuPos focus,  VfxBool isMoveToVisible)
{
    VcpBaseMenuLayout:: setFocusItem(focus, isMoveToVisible);
}


void VappMediaGridComponentLayout::makeVisible(VcpMenuPos p, VfxBool isAnim)
{
    VcpBaseMenuLayout:: makeVisible(p, isAnim);
}


const VfxPoint VappMediaGridComponentLayout::getViewPosition() const
{
    VfxPoint pos = getViewPos();
    return pos;
}


const VfxSize VappMediaGridComponentLayout::getViewDimension() const
{
    VfxSize size = getViewSize();
    return size;
}

/*****************************************************************************
 * VappMediaGridComponentCell
 *****************************************************************************/
VappMediaGridComponentCell::VappMediaGridComponentCell() :
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
	m_isSelected(VFX_FALSE),
	m_isSelectMode(VFX_FALSE), 
#endif
	m_group(0),
	m_index(0), 
    m_state(STATE_EXIT),
    m_width(0),
    m_height(0),
    m_innerX(0),
    m_innerY(0),
    m_showVideoOverlay(VFX_FALSE),
    m_show3dPhotoBadge(VFX_FALSE),
    m_imageBuf(NULL),   
    m_selectBorderColor(255, 252, 178, 21)
{

}

VappMediaGridComponentCell::~VappMediaGridComponentCell()
{
    m_index = 0;
    m_group = 0;
    m_state = STATE_EXIT;
    m_imageBuf = NULL;
}

void VappMediaGridComponentCell::onInit()
{
    VfxControl::onInit();

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    setAnchor(VfxFPoint(0.5, 0.5));
    setOpacity(1);
    setBgColor(VfxColor(255, LOADING_BG_COLOR, LOADING_BG_COLOR, LOADING_BG_COLOR));
}

void VappMediaGridComponentCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappMediaGridComponentCell::onDraw(VfxDrawContext &dc)
{
    VfxSize s = getSize();
    if(0 == s.width || 0 == s.height)
    {
        return;
    }

    drawThumb(dc);
    drawVideoOverlay(dc);
    draw3dPhotoBadge(dc);
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    drawCheckBox(dc);
#endif
    drawDebugInfo(dc);
}

void VappMediaGridComponentCell::drawThumb(VfxDrawContext &dc)
{
    const VfxS32 x = 0;
    const VfxS32 y = 0;
    switch(m_image.getType())
    {
    case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        GALLERY_MEASURE_TIME_START("Gdb");
        dc.drawImage(x, y, m_image);
        GALLERY_MEASURE_TIME_STOP("Gdb");
        break;
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        GALLERY_MEASURE_TIME_START("Gdr");
        dc.drawImage(0, 0, m_image);
        GALLERY_MEASURE_TIME_STOP("Gdr");
        break;
    case VFX_IMAGE_SRC_TYPE_NULL:
    default:
        //dc.setFillColor(VfxColor(255, DEFAILT_THUMB_WHITENESS, DEFAILT_THUMB_WHITENESS, DEFAILT_THUMB_WHITENESS));
        //dc.fillRect(VfxRect(x, y, DEFAILT_THUMB_SIZE, DEFAILT_THUMB_SIZE));
        break;
    }
}

void VappMediaGridComponentCell::drawVideoOverlay(VfxDrawContext &dc)
{
    if(!m_showVideoOverlay)
    {
        return;
    }

    // draw overlay frame
    dc.drawImage(0, 0, VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_VIDEO_FRAME));
    // draw video icon
    VfxImageSrc img = VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_VIDEO_ICON);
    const VfxS32 x = getSize().width  - img.getSize().width - MARGIN_BADGE_X;
    const VfxS32 y = getSize().height - img. getSize().height - MARGIN_BADGE_Y;
    dc.drawImage(x, y, img);

}

void VappMediaGridComponentCell::draw3dPhotoBadge(VfxDrawContext &dc)
{
    if(!m_show3dPhotoBadge)
    {
        return;
    }

    // draw video icon
    VfxImageSrc img = VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_MAV_ICON);
    const VfxS32 x = getSize().width  - img.getSize().width - MARGIN_BADGE_X;
    const VfxS32 y = getSize().height - img. getSize().height - MARGIN_BADGE_Y;
    dc.drawImage(x, y, img);

}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
void VappMediaGridComponentCell::drawCheckBox(VfxDrawContext &dc)
{
    if(!m_isSelectMode)
    {
        return;
    }

    VfxImageSrc img = m_isSelected ?
                      VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_CHECK_CHECKED) :
                      VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_CHECK_EMPTY);
    VfxS32 x = 0;
    VfxS32 y = getSize().height - img.getSize().height - 1;
    dc.drawImage(x, y, VfxImageSrc(img));
}
#endif

void VappMediaGridComponentCell::drawDebugInfo(VfxDrawContext &dc)
{
#ifdef __VAPP_GALLERY_INTERNAL_DEBUG__
    GALLERY_MEASURE_TIME_START("Gdt");
    VfxWString str;
    str.format("%d, %d", m_group, m_index);
    dc.drawText(10, 10, str);
    GALLERY_MEASURE_TIME_STOP("Gdt");
#endif
}

void VappMediaGridComponentCell::set3dPhotoBadge(VfxBool show)
{
    m_show3dPhotoBadge= show;
    invalidate();
}

void VappMediaGridComponentCell::setVideoOverlay(VfxBool showVideoOverlay)
{
    m_showVideoOverlay = showVideoOverlay;
    invalidate();
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
void VappMediaGridComponentCell::setSelected(VfxBool bIsSelectMode, VfxBool bSelected)
{
    m_isSelectMode = bIsSelectMode;
    m_isSelected = bSelected;
    invalidate();
}
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

VfxBool VappMediaGridComponentCell::updateImage(IVappGalleryMediaList *pSource, CellDataType type)
{
    // Final Image already loaded
    if(m_state == STATE_IMAGE)
    {
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        setSelected(m_isSelectMode, m_isSelected); // properly draw highlight
#endif
        return VFX_TRUE;
    }

    const VcpMenuPos p(m_group, m_index);
    VfxWString path;

    if(type == DATA_TYPE_DEFAULT || pSource == NULL)
    {
        // Forced to be empty thumb, skip it
        setLoadingIcon();
    }
    else if(pSource && OK != pSource->getMediaPath(p, path))
    {
        // resource IDs are special case, they don't need media cache.
        // we check if it is path first, since getMediaSource can be slow.
        VfxImageSrc src;
        pSource->getMediaSource(p, src);
        if(VFX_IMAGE_SRC_TYPE_RES_ID == src.getType())
        {
            setImageResId(src.getResId());
        }
    }
    else
    {
        // Other cases, check decode status
        VappGalleryDecodeResult result;
        VfxImageBuffer thumbBuf;
        {
            GALLERY_MEASURE_TIME(type == DATA_TYPE_MEMORY ? "UBC" : "UBD");
            result = pSource->lockThumb(p, thumbBuf);
        }

        switch(result)
        {
        case OK:
            setImageBuffer(thumbBuf);
            break;
        case FORMAT_UNSUPPORTED:
            setErrorIcon(__LINE__);
            break;
        case DRM_LOCKED:
            setDRMIcon();
            break;
        default:
            // maybe still decoding
            setLoadingIcon();
            break;
        }
    }
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    setSelected(m_isSelectMode, m_isSelected); // properly draw highlight
#endif
    return VFX_TRUE;
}

void VappMediaGridComponentCell::closeImage(IVappGalleryMediaList *pThumbSource)
{
    if(m_state == STATE_IMAGE && m_image.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
    {
        // vadp_mediawall_srv_free_image_buffer
        VcpMenuPos index;
        index.group = m_group;
        index.pos = m_index;
        pThumbSource->unlockThumb(index, m_image.getImageBuffer());
    }
}

void VappMediaGridComponentCell::setErrorIcon(const VfxU32 line)
{
	// remove build warning 2012-11-21
    // MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_SET_ERROR_ICON, m_group, m_pos, line);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_GRID_SET_ERROR_ICON, m_group, m_index, line);
    m_image.setResId(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON);
    m_state = STATE_IMAGE;
    invalidate();
}

void VappMediaGridComponentCell::setDRMIcon()
{
    m_image.setResId(IMG_ID_VAPP_GALLERY_SHT_DRM_ICON);
    m_state = STATE_IMAGE;
    invalidate();
}

void VappMediaGridComponentCell::setLoadingIcon()
{
    m_image.setNull();
    m_state = STATE_DEFAULT;
    invalidate();
}

void VappMediaGridComponentCell::setImageResId(const MMI_IMG_ID imgId)
{
    m_image.setResId(imgId);
    m_state = STATE_IMAGE;
    invalidate();
}

void VappMediaGridComponentCell::setImageBuffer(const VfxImageBuffer &imageBuf)
{
#ifdef __GALLERY_GRID_FADE_IN_ENABLED_
    setAutoAnimate(VFX_TRUE);
#else
    setAutoAnimate(VFX_FALSE);
#endif
    m_imageBuf = imageBuf.ptr;
    m_image.setImageBuffer(imageBuf);
    // flash effect
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setOpacity(0.3f);
    VfxAutoAnimate::commit();
    setOpacity(1.0f);
    m_state = STATE_IMAGE;
    invalidate();
}

void VappMediaGridComponentCell::updatePos(const VfxRect& r, VfxBool animation)
{
#ifdef __GALLERY_GRID_FADE_IN_ENABLED_
    setAutoAnimate(animation);
#else
    setAutoAnimate(VFX_FALSE);
#endif
    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    m_width = r.getWidth();
    m_height = r.getHeight();
    setBounds(VfxRect(0, 0, m_width, m_height));
}


void VappMediaGridComponentCell::enter(const VfxRect& r, VfxBool animation)
{
    if (animation)
    {
        setPos(VfxPoint(r.getMidX(), r.getMidY()));
        updatePos(r, VFX_TRUE);
        setOpacity(1.0f);
    }
    else
    {
        updatePos(r, VFX_FALSE);
        setOpacity(1.0f);
    }
}

void VappMediaGridComponentCell::leave(const VfxRect& r)
{
#ifdef __GALLERY_GRID_FADE_IN_ENABLED_
    setAutoAnimate(VFX_TRUE);
#else
    setAutoAnimate(VFX_FALSE);
#endif
    updatePos(r, VFX_FALSE);
    setOpacity(0);
}

vcui_gallery_media_state_enum VappMediaGridComponentCell::getContentDecodeState() const
{
    if(m_state != STATE_IMAGE)
    {
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    switch(m_image.getType())
    {
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        switch(m_image.getResId())
        {
        case IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON:
        case IMG_ID_VAPP_GALLERY_SHT_DRM_ICON:
            return VCUI_GALLERY_MEDIA_STATE_FORMAT_UNSUPPORTED;
        }
        break;
    case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        return VCUI_GALLERY_MEDIA_STATE_OK;
    default:
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
}

VappMediaGridComponentHeader::VappMediaGridComponentHeader():
    m_caption(NULL)
{
}

void VappMediaGridComponentHeader::onInit()
{
    VappMediaGridComponentCell::onInit();
    VfxImageSrc headerImg(VCP_IMG_LIST_MENU_GROUP_HEADER_BG);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setImgContent(headerImg);

    VFX_OBJ_CREATE(m_caption, VfxTextFrame, this);
    m_caption->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL, VFX_FE1_9));
    m_caption->setAutoResized(VFX_TRUE);
    m_caption->setAutoFontSize(VFX_FALSE);
    m_caption->setColor(VFX_COLOR_RES(VCP_COL_LIST_MENU_HEADER_TEXT));
    m_caption->setAnchor(0.0f, 0.5f);
    m_caption->setPos(MARGIN_LEFT, getSize().height / 2);
    m_caption->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_NONE,
                              VFX_FRAME_ALIGNER_MODE_MID);
}

void VappMediaGridComponentHeader::setString(const VfxWString &text)
{
    if(NULL == m_caption)
    {
        return;
    }
    m_caption->setString(text);
}

#endif
