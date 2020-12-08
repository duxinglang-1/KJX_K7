/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_cosmos_desktop.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the desktop.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include <limits.h>
#include <stdlib.h>

#include "MMI_include.h"

#include "vfx_uc_include.h"
#include "vapp_widget.h"
#include "vapp_launcher_cosmos_def.h"
#include "vapp_launcher_cosmos_desktop.h"

#include "mmi_rp_vapp_launcher_cosmos_def.h"

#include "vapp_launcher_cosmos_page_transition_factory.h"

//
// C headers
//
extern "C"
{
#if defined(VAPP_LAUNCHER_COSMOS_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}


/*****************************************************************************
 * Home Desktop Page Class
 *****************************************************************************/

VappLauncherCosmosDesktopPage::VappLauncherCosmosDesktopPage() :
    m_id(0),
    m_sourceRect(VFX_RECT_ZERO),
    m_objList(),
    m_bg(NULL)
{
    // Do nothing.
}


void VappLauncherCosmosDesktopPage::onInit()
{
    VfxFrame::onInit();

    setSize(getParentFrame()->getSize());
    VFX_OBJ_CREATE(m_bg, VfxFrame, this);
    m_bg->setOpacity(0);
    m_bg->setBgColor(VFX_COLOR_BLACK);
    m_bg->setAnchor(0.5, 0.5);
    m_bg->setPos(getParentFrame()->getSize().width/2, getParentFrame()->getSize().height/2);
    m_bg->setSize(getParentFrame()->getSize());
    m_bg->setAutoAnimate(VFX_TRUE);
    m_bg->setHidden(VFX_TRUE);

}


void VappLauncherCosmosDesktopPage::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappLauncherCosmosDesktopPage::setId(VfxId id)
{
    m_id = id;
}


VfxId VappLauncherCosmosDesktopPage::getId() const
{
    return m_id;
}


void VappLauncherCosmosDesktopPage::setLayout(
    const VfxRect &sourceRect)
{
    m_sourceRect = sourceRect;
    setSize(m_sourceRect.size);
}


void VappLauncherCosmosDesktopPage::getLayout(
    VfxRect &sourceRect) const
{
    sourceRect = m_sourceRect;
}
    

void VappLauncherCosmosDesktopPage::addToContainer(
    VfxFrame *frame)
{
    if (frame)
    {
        //frame->setIsUnhittable(VFX_TRUE);

        VfxPoint pos = frame->getPos();

        pos.x -= m_sourceRect.origin.x;
        pos.y -= m_sourceRect.origin.y;

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        frame->setPos(pos);

        VfxAutoAnimate::commit();

        addChildFrame(frame);
        m_objList.append(frame);
    }
}
    

void VappLauncherCosmosDesktopPage::removeFromContainer(
    VfxObjList &objList)
{
    for (VfxObjListEntry *entry = m_objList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

        if (frame)
        {
            frame->setIsUnhittable(VFX_FALSE);

            VfxPoint pos = frame->getPos();

            pos.x += m_sourceRect.origin.x;
            pos.y += m_sourceRect.origin.y;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

            frame->setPos(pos);
            frame->setTransform(VFX_TRANSFORM_IDENTITY);

            VfxAutoAnimate::commit();

            frame->removeFromParentFrame();
            objList.append(frame);
        }
    }

    m_objList.clear();
}


VfxBool VappLauncherCosmosDesktopPage::isEmpty()
{
    return m_objList.isEmpty();
}


VfxFPoint VappLauncherCosmosDesktopPage::getResizeRatio(
    const VfxRect &dst,
    const VfxRect &src) const
{
    VFX_ASSERT(src.size.width > 0 && src.size.height > 0);

    VfxFloat sx = (VfxFloat)dst.size.width / src.size.width;
    VfxFloat sy = (VfxFloat)dst.size.height / src.size.height;

    return VfxFPoint(sx, sy);
}
    

void VappLauncherCosmosDesktopPage::showBg(VfxBool isShow)
{
    if(isShow)
    {
        m_bg->setOpacity(VAPP_LAUNCHER_COSMOS_DESKTOP_PAGE_BG_OPACITY);
    }
    else
    {
        m_bg->setOpacity(0);
    }
}


/*****************************************************************************
 * Desktop Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosDesktop", VappLauncherCosmosDesktop, VfxControl);


const VfxS32 VappLauncherCosmosDesktop::s_vertiTileNum = VAPP_LAUNCHER_COSMOS_DESKTOP_VERTI_TILE_NUM;
const VfxS32 VappLauncherCosmosDesktop::s_horizTileNum = VAPP_LAUNCHER_COSMOS_DESKTOP_HORIZ_TILE_NUM;
const VfxS32 VappLauncherCosmosDesktop::s_outerBorderTopWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_TOP_WIDTH;
const VfxS32 VappLauncherCosmosDesktop::s_outerBorderBottomWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH;
const VfxS32 VappLauncherCosmosDesktop::s_outerBorderLeftWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_LEFT_WIDTH;
const VfxS32 VappLauncherCosmosDesktop::s_outerBorderRightWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_RIGHT_WIDTH;
const VfxS32 VappLauncherCosmosDesktop::s_autoSlideBorderLeftWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH;
const VfxS32 VappLauncherCosmosDesktop::s_autoSlideBorderRightWidth = VAPP_LAUNCHER_COSMOS_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH;


VappLauncherCosmosDesktop::VappLauncherCosmosDesktop() :
    m_currentPageIndex(0),
    m_slideSpeed(0),
    m_tlTranslateDummyNodeX(NULL),
    m_animDummyFrame(NULL),
    m_transition(NULL)
#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE)
    ,
    m_debugPanel(NULL),
    m_debugText(NULL),
    m_isPenMoved(VFX_FALSE)
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE) */
#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE)
    ,
    m_autoSlideHint(NULL)
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE) */
{
    for(VfxS32 i=0; i<VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        m_page[i] = NULL;
    }
}


void VappLauncherCosmosDesktop::onInit()
{
    VfxControl::onInit();

    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    //
    // This frame.
    //
    setAutoAnimate(VFX_TRUE);
    setSize(VfxSize(screenSize.width, screenSize.height));
    setCacheMode(VFX_CACHE_MODE_PREVENT);

    VFX_OBJ_CREATE(m_tlTranslateDummyNodeX, VfxS32Timeline, this);
    m_tlTranslateDummyNodeX->m_signalStopped.connect(this, &VappLauncherCosmosDesktop::updateDummyNodePosX);

    VFX_OBJ_CREATE(m_animDummyFrame, VfxFrame, this);
    getAnimDummyFrame()->setSize(1, 1);
    getAnimDummyFrame()->setBgColor(VFX_COLOR_RED);
    getAnimDummyFrame()->setOpacity(0);

    VappLauncherCosmosPageTransitionFactory *factory = VFX_OBJ_GET_INSTANCE(VappLauncherCosmosPageTransitionFactory);
    m_transition = factory->createPageTransition(VAPP_PAGE_TRANSITION_TYPE_NORMAL,this);

	for(VfxS32 i=0; i<VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_page[i], VappLauncherCosmosDesktopPage, this);
        m_page[i]->setPos(getPageRect(i).getMinX(), getPageRect(i).getMinY());
        m_page[i]->setFilterTiming(m_page[i]->getPos().x);
        m_page[i]->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        m_page[i]->setQuality(VFX_RENDER_QUALITY_HIGH);
        initPageAnim(m_page[i]);
    }
}


void VappLauncherCosmosDesktop::updateDummyNodePosX(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    VfxRect bounds = getBounds();

#if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if(bounds.getMinX() > bounds.getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1+0.5))
    {
        bounds.origin.x = 0;
    }
    else if(bounds.getMinX() < bounds.getWidth() * (-1+0.5))
    {
        bounds.origin.x = bounds.getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1);
    }
#endif

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));
    setBounds(bounds);

    VfxAutoAnimate::commit();
}


VfxFrame *VappLauncherCosmosDesktop::getAnimDummyFrame() const
{
    return m_animDummyFrame;
}


void VappLauncherCosmosDesktop::onDeinit()
{
    m_tlTranslateDummyNodeX->m_signalStopped.disconnect(this, &VappLauncherCosmosDesktop::updateDummyNodePosX);
    VfxControl::onDeinit();
}


void VappLauncherCosmosDesktop::setBounds(const VfxRect &value)
{
    VfxRect bounds = value;

    // allow desktop bounds overflow the max    desktop bounds(page x page width), 
    // it will slide to nearest page after pen up
    VfxControl::setBounds(bounds);
}


void VappLauncherCosmosDesktop::onDraw(VfxDrawContext &dc)
{
#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_TILE)
    VfxSize tileSize = getTileSize();

    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; pageIndex++)
    {
        VfxS32 firstIndex = getFirstRoomIndex(tileSize, pageIndex);
        VfxS32 lastIndex = getLastRoomIndex(tileSize, pageIndex);

        for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
        {
            VfxRect room = getRoom(tileSize, idx);
            VappWidget *occupiedWidget = getOccupiedWidget(pageIndex, room);

            if (occupiedWidget)
            {
                room = searchNearest(occupiedWidget, pageIndex);
                VFX_ASSERT(!room.isEmpty());
            }

            srand(pageIndex * VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM + idx);

            VfxColor color;

            color.setA(255);
            color.setR(rand() % 255);
            color.setG(rand() % 255);
            color.setB(rand() % 255);

            dc.setStrokeColor(color);

            dc.drawLine(room.getMinX(), room.getMinY(),
                        room.getMaxX(), room.getMinY());

            dc.drawLine(room.getMinX(), room.getMaxY(),
                        room.getMaxX(), room.getMaxY());

            dc.drawLine(room.getMinX(), room.getMinY(),
                        room.getMinX(), room.getMaxY());

            dc.drawLine(room.getMaxX(), room.getMinY(),
                        room.getMaxX(), room.getMaxY());
        }
    }
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_TILE) */
}


VfxBool VappLauncherCosmosDesktop::doPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_DO_PEN_INPUT,
                           'D', event.timeStamp,
                           event.downPos.x, event.downPos.y));

            VAPP_LAUNCHER_COSMOS_SLA(("HDD", SA_label));

            initSlideSpeed();

        #if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_FALSE;
        #endif

            break;
        }
        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_DO_PEN_INPUT,
                           'M', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_COSMOS_SLA(("HDM", SA_label));

            // not allow to move desktop page when desktop page is swiping
            if(m_tlTranslateDummyNodeX->getIsEnabled())
            {
                break;
            }
            
            updateSlideSpeed(event);

            //
            // Wallpaper used ownerDraw mechanism will block MMI running when onDraw callback,
            // after onDraw, then VRT change to MMI task then start to set desktop bounds,
            // but onDraw needs much time, it will casue widget swipe not smooth, 
            //
            // [Solution] suspend vrt until MMI set desktop bounds timeline
            // suspend vrt will cost a little time more less than onDraw,
            // so it will feel more smooth by using this method
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(3);

            VfxS32 offset = event.pos.x - event.prevPos.x;
            VfxRect bounds = getBounds();

        #if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
            //
            // overflow desktop bounds will translate to first desktop page bounds 
            // in page framePropertyEffectCallback
            //
            VfxFloat overflowRatio = 1;
        #else
            // damping effect
            VfxFloat overflowRatio = 1;

            if((bounds.origin.x > 
                getBounds().getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1) &&
               bounds.origin.x < 
                getBounds().getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)) ||
               (bounds.origin.x > 
                -getBounds().getWidth() &&
               bounds.origin.x < 0))
            {
                // reference iphone effect, move 0.5 times offset on the first/last page
                offset = 0.5 * offset;
            }
        #endif

            bounds.origin.x -= offset;
        
            if(bounds.origin.x > 
                getBounds().getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1) + overflowRatio * getBounds().getWidth())
            {
                bounds.origin.x = getBounds().getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1) + overflowRatio * getBounds().getWidth();
            }
            else if(bounds.origin.x < -overflowRatio * getBounds().getWidth())
            {
                bounds.origin.x = -overflowRatio * getBounds().getWidth();
            }

            showDesktopPageBg(VFX_TRUE);
            getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));
            setBounds(bounds);

            VfxAutoAnimate::commit();

        #if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_TRUE;
        #endif

            break;
        }
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_DO_PEN_INPUT,
                           'L', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_COSMOS_SLA(("HDL", SA_label));

            break;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_DO_PEN_INPUT,
                           'U', event.timeStamp,
                           event.predictPos.x, event.predictPos.y));

            VAPP_LAUNCHER_COSMOS_SLA(("HDU", SA_label));

            VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
            VfxS32 xDiff = event.predictPos.x - event.downPos.x;

            if (tDiff >= SWIPE_CRITERIA || VFX_ABS(xDiff) <= SENSITIVITY)
            {
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_NORMAL_SWIPE,
                               xDiff, tDiff));

                slideToNearest(getSlideDurationToNearest());
            }
            else
            {
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_QUICK_SWIPE,
                               xDiff, tDiff));

                VfxBool ret;

                if (xDiff > 0)
                {
                    ret = slideToPrevious(getSlideDurationToPrevious());
                }
                else
                {
                    ret = slideToNext(getSlideDurationToNext());
                }

                if (!ret)
                {
                    slideToNearest();
                }
            }
            showDesktopPageBg(VFX_FALSE);

        #if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE)
            WCHAR buf[128];

            kal_wsprintf(buf, "td: %d, xd: %d", tDiff, xDiff);

            if (m_isPenMoved)
            {
                setDebugText(VFX_WSTR_MEM(buf));
            }
            else
            {
                setDebugText(VFX_WSTR_MEM(buf), VFX_COLOR_RED);
            }
        #endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE) */

            break;
        }
        case VFX_PEN_EVENT_TYPE_ABORT:
        {
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DESKTOP_DO_PEN_INPUT,
                           'A', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_COSMOS_SLA(("HDA", SA_label));

            slideToNearest();
            showDesktopPageBg(VFX_FALSE);
            break;
        }
        default:
            break;
    }

    return VFX_TRUE;
}


VfxS32 VappLauncherCosmosDesktop::getCurrentPageIndex() const
{
    return m_currentPageIndex;
}


VfxS32 VappLauncherCosmosDesktop::getPageIndex(const VfxPoint &pos) const
{
    VfxS32 width = getBounds().getWidth();
    VfxS32 pageIndex = pos.x / width;

    return clampIndex(pageIndex);
}


VfxS32 VappLauncherCosmosDesktop::getPageIndex(const VappWidget *widget) const
{

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        for (VfxFrame *frame = m_page[i]->getFirstChildFrame();
             frame != NULL;
             frame = frame->getNextFrame())
        {
            if(widget == VFX_OBJ_DYNAMIC_CAST(frame, VappWidget))
            {
                return i;
            }
            
        }

    }
    return -1;
}


VfxS32 VappLauncherCosmosDesktop::getPageIndexAndPos(
    const VfxPoint &pos,          
    VfxPoint &pagePos        
) const
{
    VfxS32 pageIndex = getPageIndex(pos);
    pagePos = VfxPoint(pos.x - pageIndex*getBounds().getWidth(), pos.y);
    return pageIndex;

}


VfxRect VappLauncherCosmosDesktop::getPageRect(VfxS32 pageIndex) const
{
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return VFX_RECT_ZERO;
    }

    VfxPoint origin;

    origin.x = pageIndex * getBounds().getWidth();
    origin.y = 0;

    return VfxRect(origin, getBounds().size);
}


VfxRect VappLauncherCosmosDesktop::getPageValidRect(VfxS32 pageIndex) const
{
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return VFX_RECT_ZERO;
    }

    VfxSize tileSize = getTileSize();
    VfxS32 firstIndex = getFirstRoomIndex(tileSize, pageIndex);
    VfxS32 lastIndex = getLastRoomIndex(tileSize, pageIndex);
    VfxRect firstRoom = getRoom(tileSize, firstIndex);
    VfxRect lastRoom = getRoom(tileSize, lastIndex);

    VfxSize size;

    size.width = lastRoom.getMaxX() - firstRoom.getMinX();
    size.height = lastRoom.getMaxY() - firstRoom.getMinY();

    return VfxRect(firstRoom.origin, size);
}


VfxS32 VappLauncherCosmosDesktop::getAutoSlideDirection(const VfxPoint &pos) const
{
    VfxS32 pageIndex = getPageIndex(pos);
    VfxS32 width = getBounds().getWidth();
    VfxS32 leftEdge = width * pageIndex + s_autoSlideBorderLeftWidth;
    VfxS32 rightEdge = width * (pageIndex + 1) - s_autoSlideBorderRightWidth;

#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE)
    VfxS32 location = 0;

    if (pos.x < leftEdge)
    {
        location = -1;
    }
    else if (pos.x >= rightEdge)
    {
        location = 1;
    }

    ((VappLauncherCosmosDesktop *)this)->setAutoSlideHint(location);
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE) */

    //
    // Return value meanings:
    //
    //   0: cannot auto-slide the page
    //  -1: can auto-slide to the previous page
    //   1: can auto-slide to the next page
    //
#if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if (pos.x < leftEdge)
    {
        return -1;
    }
    else if (pos.x >= rightEdge)
    {
        return 1;
    }
#else
    if (pos.x < leftEdge && pageIndex > 0)
    {
        return -1;
    }
    else if (pos.x >= rightEdge && pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1 )
    {
        return 1;
    }
#endif

    return 0;
}


VfxS32 VappLauncherCosmosDesktop::getDistanceToNext()
{
    if (m_currentPageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1)
    {
        return 0;
    }
    else
    {
        VfxS32 srcPos = getBounds().getMinX();
        VfxS32 dstPos = getBounds().getWidth() * (m_currentPageIndex + 1);

        return vfxAbs(dstPos - srcPos);
    }
}


VfxS32 VappLauncherCosmosDesktop::getDistanceToPrevious()
{
    if (m_currentPageIndex <= 0)
    {
        return 0;
    }
    else
    {
        VfxS32 srcPos = getBounds().getMinX();
        VfxS32 dstPos = getBounds().getWidth() * (m_currentPageIndex - 1);

        return vfxAbs(dstPos - srcPos);
    }
}


VfxS32 VappLauncherCosmosDesktop::getDistanceToNearest()
{
    VfxS32 distToNext = getDistanceToNext();
    VfxS32 distToPrevious = getDistanceToPrevious();

    return vfxMin(distToNext, distToPrevious);
}


VfxMsec VappLauncherCosmosDesktop::getSlideDurationToNext()
{
    if (m_slideSpeed == 0)
    {
        return SLIDE_DEFAULT_DURATION;
    }
    else
    {
        VfxS32 distance = getDistanceToNext();

        return clampSlideDuration(distance * 1000 / m_slideSpeed);
    }
}


VfxMsec VappLauncherCosmosDesktop::getSlideDurationToPrevious()
{
    if (m_slideSpeed == 0)
    {
        return SLIDE_DEFAULT_DURATION;
    }
    else
    {
        VfxS32 distance = getDistanceToPrevious();

        return clampSlideDuration(distance * 1000 / m_slideSpeed);
    }
}


VfxMsec VappLauncherCosmosDesktop::getSlideDurationToNearest()
{
    if (m_slideSpeed == 0)
    {
        return SLIDE_DEFAULT_DURATION;
    }
    else
    {
        VfxS32 distance = getDistanceToNearest();

        return clampSlideDuration(distance * 1000 / m_slideSpeed);
    }
}


VfxBool VappLauncherCosmosDesktop::slideToNext(VfxMsec duration)
{
#if !defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if (m_currentPageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1)
    {
        return VFX_FALSE;
    }
#else
    // not allow to move desktop page when desktop page is swiping
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_FALSE;
    }
#endif

    return slideTo(m_currentPageIndex + 1, duration);
}


VfxBool VappLauncherCosmosDesktop::slideToPrevious(VfxMsec duration)
{
#if !defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if (m_currentPageIndex <= 0)
    {
        return VFX_FALSE;
    }
#else
    // not allow to move desktop page when desktop page is swiping
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_FALSE;
    }
#endif

    return slideTo(m_currentPageIndex - 1, duration);
}


VfxBool VappLauncherCosmosDesktop::slideToNearest(VfxMsec duration)
{
    VfxS32 x = getBounds().getMinX();
    VfxS32 width = getBounds().getWidth();

    VfxS32 idx = (VfxS32)vfx_sys_floor((VfxFloat)x / width + 0.5f);

#if !defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    idx = clampIndex(idx);
#endif

    return slideTo(idx, duration);
}


VfxBool VappLauncherCosmosDesktop::slideToCentra(VfxMsec duration)
{
    return slideTo(getCentraPageIndex(), duration);
}


VfxBool VappLauncherCosmosDesktop::slideTo(VfxS32 pageIndex, VfxMsec duration)
{
#if !defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return VFX_FALSE;
    }
#endif

    // slideTo use timeline to trigger FTP transition effect, it can not update in first SSE frame
    // So if duration == 0, change the dummy frame position directly,
    // it is used on first frame when launcher active, slide to the previous page
    if(duration == 0)
    {
        VfxRect bounds = getBounds();
        VfxS32 newPos = bounds.getWidth() * pageIndex;
        bounds.origin.x = newPos;
        
        getAnimDummyFrame()->setPos(bounds.origin.x,0);
        setBounds(bounds);
        
        // update current desktop bounds because page FPE transform needs to adjust translate transform by this value
        getAnimDummyFrame()->setFpeUser0(bounds.getMinX());
        getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));

        if (m_currentPageIndex != pageIndex)
        {
            m_currentPageIndex = pageIndex;
            m_signalPageChanged.emit(this);
        }
        return VFX_TRUE;
    }

    if (duration < 0)
    {
        duration = SLIDE_DEFAULT_DURATION;  // Use default sliding duration.
    }

    //
    // Update page bounds.
    //
    VfxRect bounds = getBounds();
    VfxS32 newPos = bounds.getWidth() * pageIndex;

    if (bounds.origin.x != newPos)
    {
        // use fpe user 0 to store the translation data
        m_tlTranslateDummyNodeX->setTarget(getAnimDummyFrame());
        m_tlTranslateDummyNodeX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_tlTranslateDummyNodeX->setDurationTime(duration);
        m_tlTranslateDummyNodeX->setRepeatCount(1);
        m_tlTranslateDummyNodeX->setIsFromCurrent(VFX_TRUE);
        //m_tlTranslateDummyNodeX->setFromValue(bounds.getMinX());
        m_tlTranslateDummyNodeX->setFromValue(getAnimDummyFrame()->getPos().x);
        m_tlTranslateDummyNodeX->setToValue(newPos);
        m_tlTranslateDummyNodeX->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlTranslateDummyNodeX->start();

        bounds.origin.x = newPos;

        VfxAutoAnimate::begin();

        if (duration == 0)
        {
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }
        else
        {
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            VfxAutoAnimate::setDuration(duration);

            //
            // Wallpaper used ownerDraw mechanism will block MMI running when onDraw callback,
            // after onDraw, then VRT change to MMI task then start to set desktop bounds,
            // but onDraw needs much time, it will casue widget swipe not smooth, 
            //
            // [Solution] suspend vrt until MMI set desktop bounds timeline
            // suspend vrt will cost a little time more less than onDraw,
            // so it will feel more smooth by using this method
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        }

        setBounds(bounds);

        VfxAutoAnimate::commit();
    }

    //
    // Emit signal if the page index is changed.
    //
#if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if(pageIndex < 0)
    {
        pageIndex = VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1;
    }
    else if(pageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        pageIndex = 0;
    }
#endif

    if (m_currentPageIndex != pageIndex)
    {
        m_currentPageIndex = pageIndex;
        m_signalPageChanged.emit(this);
    }

    return VFX_TRUE;
}


VfxBool VappLauncherCosmosDesktop::addToPage(VappWidget *widget, VfxS32 pageIndex)
{
    VfxRect room = searchRoom(widget, pageIndex);

    if (!room.isEmpty())
    {
        m_page[pageIndex]->addToContainer(widget);
        widget->setPos(room.getMidPoint());

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappLauncherCosmosDesktop::addToPageIfAny(VappWidget *widget)
{
    VfxS32 pageIndex = -1;
    VfxRect room = searchRoomIfAny(widget, pageIndex);

    if (!room.isEmpty())
    {
        m_page[pageIndex]->addToContainer(widget);
        widget->setPos(room.getMidPoint());

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappLauncherCosmosDesktop::addToNearest(VappWidget *widget, VfxS32 pageIndex)
{
    VfxRect room = searchNearest(widget, pageIndex);

    if (!room.isEmpty())
    {
        m_page[pageIndex]->addToContainer(widget);
        widget->setPos(room.getMidPoint());

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappLauncherCosmosDesktop::addToDesktop(VappWidget *widget)
{
    if (addToNearest(widget))
    {
        return VFX_TRUE;
    }

    if (addToPageIfAny(widget))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappLauncherCosmosDesktop::addToDesktop(VappWidget *widget, VfxS32 pageIndex)
{
    if (addToNearest(widget,pageIndex))
    {
        return VFX_TRUE;
    }

    if (addToPageIfAny(widget))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappLauncherCosmosDesktop::removeFromDesktop(VappWidget *widget)
{
    widget->removeFromParentFrame();
}


void VappLauncherCosmosDesktop::getFromPage(VfxS32 idx, VfxObjList &objList)
{
    if (idx < 0 || idx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return;
    }


    for (VfxFrame *frame = m_page[idx]->getFirstChildFrame();
         frame != NULL;
         frame = frame->getNextFrame())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(frame, VappWidget);

        if (widget)
        {
            objList.append(widget);
        }
    }
}


void VappLauncherCosmosDesktop::getFromAllPage(VfxObjList &objList)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        getFromPage(i, objList);
    }
}


VfxBool VappLauncherCosmosDesktop::canAddToPage(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    return !searchRoom(widget, pageIndex).isEmpty();
}


VfxBool VappLauncherCosmosDesktop::canAddToPageIfAny(const VappWidget *widget) const
{
    return !searchRoomIfAny(widget).isEmpty();
}


VfxRect VappLauncherCosmosDesktop::searchRoom(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    VFX_ASSERT(pageIndex >= 0 && pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    VfxSize roomSize = getRoomSize(widget);
    VfxS32 firstIndex = 0;
    VfxS32 lastIndex = getPageRoomNum(roomSize);

    for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
    {
        VfxRect room = getRoom(roomSize, idx);
        VappWidget *occupiedWidget = getOccupiedWidget(pageIndex, room);

        if (!occupiedWidget || occupiedWidget == widget)
        {
            return room;
        }
    }

    return VFX_RECT_ZERO;
}


VfxRect VappLauncherCosmosDesktop::searchRoomIfAny(const VappWidget *widget) const
{
    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; pageIndex++)
    {
        VfxRect room = searchRoom(widget, pageIndex);
        if (!room.isEmpty())
        {
            return room;
        }
    }

    return VFX_RECT_ZERO;
}


VfxRect VappLauncherCosmosDesktop::searchRoomIfAny(const VappWidget *widget, VfxS32 &pageId) const
{
    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; pageIndex++)
    {
        VfxRect room = searchRoom(widget, pageIndex);
        if (!room.isEmpty())
        {
            pageId = pageIndex;
            return room;
        }
    }

    pageId = -1;
    return VFX_RECT_ZERO;
}


VfxRect VappLauncherCosmosDesktop::searchNearest(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    VFX_ASSERT(pageIndex >= 0 && pageIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    VfxSize roomSize = getRoomSize(widget);
    VfxRect nearestRoom(VFX_RECT_ZERO);
    VfxS32 minDistance = INT_MAX;
    VfxS32 firstIndex = 0;
    VfxS32 lastIndex = getPageRoomNum(roomSize);

    for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
    {
        VfxRect room = getRoom(roomSize, idx);
        VfxS32 distance = calcDistance(widget->getPos(), room.getMidPoint());
        VappWidget *occupiedWidget = getOccupiedWidget(pageIndex, room);

        if ((!occupiedWidget || occupiedWidget == widget) &&
            (distance < minDistance))
        {
            nearestRoom = room;
            minDistance = distance;
        }
    }

    return nearestRoom;
}


VfxS32 VappLauncherCosmosDesktop::calcDistance(
    const VfxPoint &p1,
    const VfxPoint &p2) const
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


void VappLauncherCosmosDesktop::initSlideSpeed()
{
    m_slideSpeed = 0;
}


void VappLauncherCosmosDesktop::updateSlideSpeed(VfxPenEvent &event)
{
    VfxMsec time = vfxAbs(event.timeStamp - event.prevTimeStamp);
    VfxS32 offset = vfxAbs(event.pos.x - event.prevPos.x);

    if (time != 0)
    {
        m_slideSpeed = (offset * 1000) / time;
    }
}


VfxMsec VappLauncherCosmosDesktop::clampSlideDuration(VfxMsec duration)
{
    if (duration < SLIDE_MIN_DURATION)
    {
        return SLIDE_MIN_DURATION;
    }

    if (duration > SLIDE_MAX_DURATION)
    {
        return SLIDE_MAX_DURATION;
    }

    return duration;
}


VfxS32 VappLauncherCosmosDesktop::clampIndex(VfxS32 pageIndex) const
{
    if (pageIndex < 0)
    {
        return 0;
    }

    if (pageIndex >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1;
    }

    return pageIndex;
}


VfxS32 VappLauncherCosmosDesktop::getCentraPageIndex()
{
    if (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM % 2 == 0)
    {
        return VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM / 2 - 1;
    }
    else
    {
        return VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM / 2;
    }
}


VfxSize VappLauncherCosmosDesktop::getTileSize()
{
    return VfxSize(VAPP_LAUNCHER_COSMOS_DESKTOP_TILE_WIDTH, VAPP_LAUNCHER_COSMOS_DESKTOP_TILE_HEIGHT);
}


VfxSize VappLauncherCosmosDesktop::getRoomSize(const VappWidget *widget)
{
    const VfxSize tileSize = getTileSize();
    VfxSize roomSize = tileSize;
    VfxS32 idx;

    for (idx = s_horizTileNum - 1; idx >= 0; idx--)
    {
        if (roomSize.width >= widget->getMaxSize().width)
        {
            break;
        }
        else
        {
            roomSize.width += tileSize.width;
        }
    }

    if (idx < 0)
    {
        return VFX_SIZE_ZERO;
    }

    for (idx = s_vertiTileNum - 1; idx >= 0; idx--)
    {
        if (roomSize.height >= widget->getMaxSize().height)
        {
            break;
        }
        else
        {
            roomSize.height += tileSize.height;
        }
    }

    if (idx < 0)
    {
        return VFX_SIZE_ZERO;
    }

    return roomSize;
}


VfxS32 VappLauncherCosmosDesktop::getTotalRoomNum(const VfxSize &roomSize)
{
    return getPageRoomNum(roomSize) * VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM;
}


VfxS32 VappLauncherCosmosDesktop::getPageRoomNum(const VfxSize &roomSize)
{
    return getPageHorizRoomNum(roomSize) * getPageVertiRoomNum(roomSize);
}


VfxS32 VappLauncherCosmosDesktop::getPageHorizRoomNum(const VfxSize &roomSize)
{
    VfxS32 roomWidth = roomSize.width;
    VfxS32 tileWidth = getTileSize().width;
    VfxS32 tileNum = 1;

    roomWidth -= tileWidth;

    while (roomWidth > 0 && tileNum < s_horizTileNum)
    {
        roomWidth -= tileWidth;
        ++tileNum;
    }

    return s_horizTileNum - tileNum + 1;
}



VfxS32 VappLauncherCosmosDesktop::getPageVertiRoomNum(const VfxSize &roomSize)
{
    VfxS32 roomHeight = roomSize.height;
    VfxS32 tileHeight = getTileSize().height;
    VfxS32 tileNum = 1;

    roomHeight -= tileHeight;

    while (roomHeight > 0 && tileNum < s_vertiTileNum)
    {
        roomHeight -= tileHeight;
        ++tileNum;
    }

    return s_vertiTileNum - tileNum + 1;
}


VfxS32 VappLauncherCosmosDesktop::getFirstRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * pageIdx;
}


VfxS32 VappLauncherCosmosDesktop::getLastRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * (pageIdx + 1) - 1;
}


VfxRect VappLauncherCosmosDesktop::getRoom(
    const VfxSize &roomSize,
    VfxS32 x,
    VfxS32 y)
{
    VfxS32 horizRoomNum = getPageHorizRoomNum(roomSize);
    VfxS32 vertiRoomNum = getPageVertiRoomNum(roomSize);
    VfxSize tileSize = getTileSize();
    VfxPoint pos;

    if (x < 0 || x >= horizRoomNum ||
        y < 0 || y >= vertiRoomNum)
    {
        return VFX_RECT_ZERO;
    }

    //
    // Get screen size.
    //
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    //
    // Calculate the offset to centralize the entire valid page rectangle.
    //
    VfxS32 remainedWidth, remainedHeight;

    remainedWidth = screenSize.width -
                    s_outerBorderLeftWidth - s_outerBorderRightWidth -
                    s_horizTileNum * tileSize.width;

    remainedHeight = screenSize.height -
                     s_outerBorderTopWidth - s_outerBorderBottomWidth -
                     s_vertiTileNum * tileSize.height;

    VFX_ASSERT(remainedWidth >= 0 && remainedHeight >= 0);

    VfxPoint offset;

    offset.x = remainedWidth >> 1;
    offset.y = remainedHeight >> 1;

    //
    // Calculate the position of this room.
    //
    pos.x = offset.x +
            s_outerBorderLeftWidth +
            x * (tileSize.width);

    pos.y = offset.y +
            s_outerBorderTopWidth +
            y * (tileSize.height);

    return VfxRect(pos, roomSize);
}


VfxRect VappLauncherCosmosDesktop::getRoom(
    const VfxSize &roomSize,
    VfxS32 pageIdx,
    VfxS32 x,
    VfxS32 y)
{
    VfxS32 horizRoomNum = getPageHorizRoomNum(roomSize);
    VfxS32 vertiRoomNum = getPageVertiRoomNum(roomSize);
    VfxSize tileSize = getTileSize();
    VfxPoint pos;

    if (pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM ||
        x < 0 || x >= horizRoomNum ||
        y < 0 || y >= vertiRoomNum)
    {
        return VFX_RECT_ZERO;
    }

    //
    // Get screen size.
    //
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    //
    // Calculate the offset to centralize the entire valid page rectangle.
    //
    VfxS32 remainedWidth, remainedHeight;

    remainedWidth = screenSize.width -
                    s_outerBorderLeftWidth - s_outerBorderRightWidth -
                    s_horizTileNum * tileSize.width;

    remainedHeight = screenSize.height -
                     s_outerBorderTopWidth - s_outerBorderBottomWidth -
                     s_vertiTileNum * tileSize.height;

    VFX_ASSERT(remainedWidth >= 0 && remainedHeight >= 0);

    VfxPoint offset;

    offset.x = remainedWidth >> 1;
    offset.y = remainedHeight >> 1;

    //
    // Calculate the position of this room.
    //
    pos.x = offset.x +
            pageIdx * screenSize.width +
            s_outerBorderLeftWidth +
            x * (tileSize.width);

    pos.y = offset.y +
            s_outerBorderTopWidth +
            y * (tileSize.height);

    return VfxRect(pos, roomSize);
}


VfxRect VappLauncherCosmosDesktop::getRoom(const VfxSize &roomSize, VfxS32 idx)
{
    //
    // Page Index
    //
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum == 0)
    {
        return VFX_RECT_ZERO;
    }

    VfxS32 remained = idx % pageRoomNum;

    //
    // X & Y Index
    //
    VfxS32 pageHorizRoomNum = getPageHorizRoomNum(roomSize);

    if (pageHorizRoomNum == 0)
    {
        return VFX_RECT_ZERO;
    }

    VfxS32 y = remained / pageHorizRoomNum;
    VfxS32 x = remained % pageHorizRoomNum;

    return getRoom(roomSize, x, y);
}


VappWidget *VappLauncherCosmosDesktop::getOccupiedWidget(VfxS32 pageIndex, const VfxRect &room) const
{
    for (VfxFrame *frame = m_page[pageIndex]->getFirstChildFrame();
         frame != NULL;
         frame = frame->getNextFrame())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(frame, VappWidget);

        if (widget)
        {
            //
            // Calculate the rectangle that this widget occupies. Note that we
            // shall use the size that this widget declares by 'getMaxSize'.
            //
            VfxRect rect;

            rect.size = widget->getMaxSize();
            rect.origin = widget->getPos();

            rect.origin.x -= rect.size.width >> 1;
            rect.origin.y -= rect.size.height >> 1;

            //
            // Intersect with the 'room' to check if they are overlapped.
            //
            rect.intersectWith(room);

            if (rect.getWidth() > 0 && rect.getHeight() > 0)
            {
                return widget;
            }
        }
    }

    return NULL;
}


VappWidget *VappLauncherCosmosDesktop::getOccupiedWidget(const VfxRect &room) const
{
    for (VfxFrame *frame = getFirstChildFrame();
         frame != NULL;
         frame = frame->getNextFrame())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(frame, VappWidget);

        if (widget)
        {
            //
            // Calculate the rectangle that this widget occupies. Note that we
            // shall use the size that this widget declares by 'getMaxSize'.
            //
            VfxRect rect;

            rect.size = widget->getMaxSize();
            rect.origin = widget->getPos();

            rect.origin.x -= rect.size.width >> 1;
            rect.origin.y -= rect.size.height >> 1;

            //
            // Intersect with the 'room' to check if they are overlapped.
            //
            rect.intersectWith(room);

            if (rect.getWidth() > 0 && rect.getHeight() > 0)
            {
                return widget;
            }
        }
    }

    return NULL;
}


VfxBool VappLauncherCosmosDesktop::isOccupied(const VfxRect &room) const
{
    return getOccupiedWidget(room) ? VFX_TRUE : VFX_FALSE;
}


void VappLauncherCosmosDesktop::setWidgetOnRoom(
    VappWidget *widget,
    const VfxRect &room) const
{
    VfxPoint pos = room.getMidPoint();

    widget->setPos(pos);
}


void VappLauncherCosmosDesktop::initPageAnim(VappLauncherCosmosDesktopPage *page)
{
    // set fpe for desktop page
    VappLauncherCosmosPageTransPara para;
    para.totalPage = VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM;
    para.desktopBoundsOrigin = getBounds().origin;
    para.pageWidth = getBounds().getWidth();
    para.pageHeight = getBounds().getHeight();
    para.pagePosX = page->getPos().x;
    para.pagePosY = page->getPos().y;
    para.desktop = this;
    para.page = page;
    para.transitionEffect = m_transition; 

    page->setPropertyEffectCallback(
        getAnimDummyFrame(),
        VappLauncherCosmosDesktop::framePropertyEffectCallback,
        &para,
        sizeof(para) );
}


vrt_render_dirty_type_enum VappLauncherCosmosDesktop::framePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{

    const VappLauncherCosmosPageTransPara *transPara = (const VappLauncherCosmosPageTransPara *)user_data;

    const VfxS32 desktopWidth = transPara->desktop->getBounds().getWidth();
    const VfxS32 desktopHeight = transPara->desktop->getBounds().getHeight();
    VappLauncherCosmosPageTransition *transition = transPara->transitionEffect;

    const vrt_s32 translate = watch_frame->pos.x;
    const vrt_s32 rawPosX = static_cast<vrt_s32>(target_frame->filter_timing);
    vrt_float t = vrt_float(rawPosX - translate) / desktopWidth;

#if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if(t > (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1))
    {
        // 
        //   t:    1    -3   -2   -1    0 
        // page: |----|----|----|----|----|
        //
        t = -1 + (t - (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1));
    }
    else if(t < -(VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1))
    {
        // 
        //   t:    0     1    2    3   -1 
        // page: |----|----|----|----|----|
        //
        t = (t + (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM-1)) + 1;
    }
#endif

    if (t < -1.0f || t > 1.0f)
    {
        target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        target_frame->pos.x = -10000;
        target_frame->pos.y = -10000;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    return transition->onTransition(
                            t, 
                            desktopWidth, 
                            desktopHeight, 
                            target_frame->pos.x, 
                            target_frame->pos.y, 
                            translate,
                            target_frame);
}


void VappLauncherCosmosDesktop::showDesktopPageBg(VfxBool isShow)
{
    for(VfxS32 i=0; i<VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
    {
        m_page[i]->showBg(isShow);
    }
}


#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE)
void VappLauncherCosmosDesktop::setDebugText(
    const VfxWString &string,
    const VfxColor &color)
{
    VfxFrame *parent = getParentFrame();

    if (!m_debugText)
    {
        VFX_OBJ_CREATE(m_debugPanel, VfxFrame, this);
        parent->addChildFrame(m_debugPanel);

        m_debugPanel->setAutoAnimate(VFX_TRUE);
        m_debugPanel->setIsUnhittable(VFX_TRUE);
        m_debugPanel->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_SNAPSHOT_BG));
        m_debugPanel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_debugPanel->setAnchor(0.5f, 1.0f);

        VfxPoint pos;

        pos.x = parent->getBounds().getMidX();
        pos.y = DEBUG_TEXT_POS_Y;

        m_debugPanel->setPos(pos);

        VFX_OBJ_CREATE(m_debugText, VfxTextFrame, m_debugPanel);

        m_debugText->setAnchor(0.5f, 0.5f);
        m_debugText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(DEBUG_TEXT_FONT_SIZE)));
        m_debugText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }

    VFX_ASSERT(m_debugText && m_debugPanel);

    //
    // Update
    //
    m_debugText->setColor(color);

    m_debugText->setString(string);

    VfxRect textBounds = m_debugText->getMeasureBounds();
    textBounds.size.width += 20;
    m_debugPanel->setBounds(textBounds);

    m_debugText->setPos(m_debugPanel->getBounds().getMidPoint());

    //
    // Init & Animate
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_debugPanel->setOpacity(1.0f);

    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(2000);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);

    m_debugPanel->setOpacity(0.0f);

    VfxAutoAnimate::commit();
}
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_SLIDE) */


#if defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE)
void VappLauncherCosmosDesktop::setAutoSlideHint(VfxS32 location)
{
    VfxFrame *parent = getParentFrame();

    if (!m_autoSlideHint)
    {
        VFX_OBJ_CREATE(m_autoSlideHint, VfxFrame, this);
        parent->addChildFrame(m_autoSlideHint);

        m_autoSlideHint->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_SNAPSHOT_BG));
        m_autoSlideHint->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        //
        // Time line
        //
        VfxFloatTimeline *timeline;

        VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
        timeline->setTarget(m_autoSlideHint);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        timeline->setFromValue(0.4f);
        timeline->setToValue(0.8f);
        timeline->setDuration(800);
        timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->start();
    }

    if (location == 0)
    {
        m_autoSlideHint->setHidden(VFX_TRUE);
    }
    else if (location < 0)
    {
        m_autoSlideHint->setHidden(VFX_FALSE);
        m_autoSlideHint->setAnchor(VfxFPoint(0.0f, 0.0f));

        m_autoSlideHint->setPos(VFX_POINT_ZERO);

        VfxSize size = parent->getSize();
        size.width = s_autoSlideBorderLeftWidth;
        m_autoSlideHint->setSize(size);
    }
    else if (location > 0)
    {
        m_autoSlideHint->setHidden(VFX_FALSE);
        m_autoSlideHint->setAnchor(VfxFPoint(1.0f, 0.0f));

        VfxPoint pos;
        pos.x = parent->getBounds().getWidth();
        pos.y = 0;
        m_autoSlideHint->setPos(pos);

        VfxSize size = parent->getSize();
        size.width = s_autoSlideBorderRightWidth;
        m_autoSlideHint->setSize(size);
    }
}
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_DESKTOP_AUTO_SLIDE) */

