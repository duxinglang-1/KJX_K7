/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_desktop_page.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the page.
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

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <limits.h>
#include <stdlib.h>

#include "MMI_include.h"

#include "vfx_uc_include.h"
#include "vapp_app_widget.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_page.h"

#include "mmi_rp_vapp_desktop_def.h"

//
// C headers
//
extern "C"
{
#if defined(VAPP_DESKTOP_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}


/*****************************************************************************
 * Page Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopPage", VappDesktopPage, VfxControl);


const VfxS32 VappDesktopPage::s_vertiTileNum = VAPP_DESKTOP_PAGE_VERTI_TILE_NUM;
const VfxS32 VappDesktopPage::s_horizTileNum = VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM;
const VfxS32 VappDesktopPage::s_outerBorderTopWidth = VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH;
const VfxS32 VappDesktopPage::s_outerBorderBottomWidth = VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH;
const VfxS32 VappDesktopPage::s_outerBorderLeftWidth = VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH;
const VfxS32 VappDesktopPage::s_outerBorderRightWidth = VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH;
const VfxS32 VappDesktopPage::s_autoSlideBorderLeftWidth = VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH;
const VfxS32 VappDesktopPage::s_autoSlideBorderRightWidth = VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_RIGHT_WIDTH;


VappDesktopPage::VappDesktopPage() :
    m_currentPageIndex(0),
    m_slideSpeed(0)
#if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
    ,
    m_debugPanel(NULL),
    m_debugText(NULL),
    m_isPenMoved(VFX_FALSE)
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE) */
#if defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE)
    ,
    m_autoSlideHint(NULL)
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE) */
{
    // Do nothing.
}


void VappDesktopPage::onInit()
{
    VfxControl::onInit();

    VfxSize screenSize = getScreenSize();

    //
    // This frame.
    //
    setAutoAnimate(VFX_TRUE);

    setPos(0, s_outerBorderTopWidth);

    setSize(
        screenSize.width,
        screenSize.height - s_outerBorderTopWidth - s_outerBorderBottomWidth);

    setCacheMode(VFX_CACHE_MODE_PREVENT);
}


void VappDesktopPage::onDeinit()
{
    VfxControl::onDeinit();
}


void VappDesktopPage::setBounds(const VfxRect &value)
{
    VfxRect bounds = value;

    //
    // Make sure the origin of the bounds doesn't exceed the value range.
    //
    if (bounds.origin.x < 0)
    {
        bounds.origin.x = 0;
    }

    VfxS32 maxX = bounds.getWidth() * (VAPP_DESKTOP_MAX_PAGE_NUM - 1);

    if (bounds.origin.x > maxX)
    {
        bounds.origin.x = maxX;
    }

    VfxControl::setBounds(bounds);
}


void VappDesktopPage::onDraw(VfxDrawContext &dc)
{
#if defined(VAPP_DESKTOP_UT_DESKTOP_TILE)
    VfxSize tileSize = getTileSize();

    for (VfxS32 pageIndex = 0; pageIndex < VAPP_DESKTOP_MAX_PAGE_NUM; pageIndex++)
    {
        VfxS32 firstIndex = getFirstRoomIndex(tileSize, pageIndex);
        VfxS32 lastIndex = getLastRoomIndex(tileSize, pageIndex);

        for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
        {
            VfxRect room = getRoom(tileSize, idx);
            VappAppWidget *occupiedWidget = getOccupiedWidget(room);

            if (occupiedWidget)
            {
                room = searchNearest(occupiedWidget, pageIndex);
                VFX_ASSERT(!room.isEmpty());
            }

            srand(pageIndex * VAPP_DESKTOP_MAX_PAGE_NUM + idx);

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
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_TILE) */
}


VfxBool VappDesktopPage::doPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_DO_PEN_INPUT,
                           'D', event.timeStamp,
                           event.downPos.x, event.downPos.y));

            VAPP_DESKTOP_SLA(("HDD", SA_label));

            initSlideSpeed();

        #if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_FALSE;
        #endif

            break;
        }
        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_DO_PEN_INPUT,
                           'M', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_DESKTOP_SLA(("HDM", SA_label));

            updateSlideSpeed(event);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(3);

            VfxS32 offset = event.pos.x - event.prevPos.x;
            VfxRect bounds = getBounds();

            bounds.origin.x -= offset;
            setBounds(bounds);

            VfxAutoAnimate::commit();

        #if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_TRUE;
        #endif

            break;
        }
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_DO_PEN_INPUT,
                           'L', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_DESKTOP_SLA(("HDL", SA_label));

            break;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_DO_PEN_INPUT,
                           'U', event.timeStamp,
                           event.predictPos.x, event.predictPos.y));

            VAPP_DESKTOP_SLA(("HDU", SA_label));

            VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
            VfxS32 xDiff = event.predictPos.x - event.downPos.x;

            if (tDiff >= SWIPE_CRITERIA || VFX_ABS(xDiff) <= SENSITIVITY)
            {
                VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_NORMAL_SWIPE,
                                  xDiff, tDiff));

                slideToNearest(getSlideDurationToNearest());
            }
            else
            {
                VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_QUICK_SWIPE,
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

        #if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
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
        #endif /* defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE) */

            break;
        }
        case VFX_PEN_EVENT_TYPE_ABORT:
        {
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_PAGE_DO_PEN_INPUT,
                           'A', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_DESKTOP_SLA(("HDA", SA_label));

            slideToNearest();
            break;
        }
        default:
            break;
    }

    return VFX_TRUE;
}


VfxS32 VappDesktopPage::getCurrentPageIndex() const
{
    return m_currentPageIndex;
}


VfxS32 VappDesktopPage::getPageIndex(const VfxPoint &pos) const
{
    VfxS32 width = getBounds().getWidth();
    VfxS32 pageIndex = pos.x / width;

    return clampIndex(pageIndex);
}


VfxRect VappDesktopPage::getPageRect(VfxS32 pageIndex) const
{
    if (pageIndex < 0 || pageIndex >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return VFX_RECT_ZERO;
    }

    VfxPoint origin;

    origin.x = pageIndex * getBounds().getWidth();
    origin.y = 0;

    return VfxRect(origin, getBounds().size);
}


VfxBool VappDesktopPage::getPageRectExt(
    VfxS32 pageIndex,
    VfxRect &insideRect,
    VfxRect &outsideRect) const
{
    VfxRect rect = getPageRect(pageIndex);

    if (rect == VFX_RECT_ZERO)
    {
        return VFX_FALSE;
    }

    insideRect = rect;
    insideRect.origin.y += s_outerBorderTopWidth;

    outsideRect = rect;
    outsideRect.size.height += s_outerBorderTopWidth + s_outerBorderBottomWidth;

    return VFX_TRUE;
}


VfxS32 VappDesktopPage::getAutoSlideDirection(const VfxPoint &pos) const
{
    VfxS32 pageIndex = getPageIndex(pos);
    VfxS32 width = getBounds().getWidth();
    VfxS32 leftEdge = width * pageIndex + s_autoSlideBorderLeftWidth;
    VfxS32 rightEdge = width * (pageIndex + 1) - s_autoSlideBorderRightWidth;

#if defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE)
    VfxS32 location = 0;

    if (pos.x < leftEdge)
    {
        location = -1;
    }
    else if (pos.x >= rightEdge)
    {
        location = 1;
    }

    ((VappDesktopPage *)this)->setAutoSlideHint(location);
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE) */

    //
    // Return value meanings:
    //
    //   0: cannot auto-slide the page
    //  -1: can auto-slide to the previous page
    //   1: can auto-slide to the next page
    //
    if (pos.x < leftEdge && pageIndex > 0)
    {
        return -1;
    }
    else if (pos.x >= rightEdge && pageIndex < VAPP_DESKTOP_MAX_PAGE_NUM - 1)
    {
        return 1;
    }

    return 0;
}


VfxS32 VappDesktopPage::getDistanceToNext()
{
    if (m_currentPageIndex >= VAPP_DESKTOP_MAX_PAGE_NUM - 1)
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


VfxS32 VappDesktopPage::getDistanceToPrevious()
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


VfxS32 VappDesktopPage::getDistanceToNearest()
{
    VfxS32 distToNext = getDistanceToNext();
    VfxS32 distToPrevious = getDistanceToPrevious();

    return vfxMin(distToNext, distToPrevious);
}


VfxMsec VappDesktopPage::getSlideDurationToNext()
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


VfxMsec VappDesktopPage::getSlideDurationToPrevious()
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


VfxMsec VappDesktopPage::getSlideDurationToNearest()
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


VfxBool VappDesktopPage::slideToNext(VfxMsec duration)
{
    if (m_currentPageIndex >= VAPP_DESKTOP_MAX_PAGE_NUM - 1)
    {
        return VFX_FALSE;
    }

    return slideTo(m_currentPageIndex + 1, duration);
}


VfxBool VappDesktopPage::slideToPrevious(VfxMsec duration)
{
    if (m_currentPageIndex <= 0)
    {
        return VFX_FALSE;
    }

    return slideTo(m_currentPageIndex - 1, duration);
}


VfxBool VappDesktopPage::slideToNearest(VfxMsec duration)
{
    VfxS32 x = getBounds().getMinX();
    VfxS32 width = getBounds().getWidth();

    VfxS32 idx = (VfxS32)vfx_sys_floor((VfxFloat)x / width + 0.5f);

    return slideTo(clampIndex(idx), duration);
}


VfxBool VappDesktopPage::slideToCentra(VfxMsec duration)
{
    VfxS32 idx;

    if (VAPP_DESKTOP_MAX_PAGE_NUM % 2 == 0)
    {
        idx = VAPP_DESKTOP_MAX_PAGE_NUM / 2 - 1;
    }
    else
    {
        idx = VAPP_DESKTOP_MAX_PAGE_NUM / 2;
    }

    return slideTo(idx, duration);
}


VfxBool VappDesktopPage::slideTo(VfxS32 pageIndex, VfxMsec duration)
{
    if (pageIndex < 0 || pageIndex >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return VFX_FALSE;
    }

    if (duration < 0)
    {
        duration = SLIDE_DEFAULT_DURATION; // Use default sliding duration.
    }

    //
    // Update page bounds.
    //
    VfxRect bounds = getBounds();
    VfxS32 newPos = bounds.getWidth() * pageIndex;

    if (bounds.origin.x != newPos)
    {
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
        }

        setBounds(bounds);

        VfxAutoAnimate::commit();
    }

    //
    // Emit signal if the page index is changed.
    //
    if (m_currentPageIndex != pageIndex)
    {
        m_currentPageIndex = pageIndex;
        m_signalPageChanged.emit(this);
    }

    return VFX_TRUE;
}


VfxBool VappDesktopPage::addToPage(VappAppWidget *widget, VfxS32 pageIndex)
{
    VfxRect room = searchRoom(widget, pageIndex);

    if (!room.isEmpty())
    {
        setWidgetOnRoom(widget, room);
        addChildFrame(widget);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappDesktopPage::addToPageIfAny(VappAppWidget *widget)
{
    VfxRect room = searchRoomIfAny(widget);

    if (!room.isEmpty())
    {
        setWidgetOnRoom(widget, room);
        addChildFrame(widget);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappDesktopPage::addToNearest(VappAppWidget *widget, VfxS32 pageIndex)
{
    VfxRect room = searchNearest(widget, pageIndex);

    if (!room.isEmpty())
    {
        setWidgetOnRoom(widget, room);
        addChildFrame(widget);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappDesktopPage::addToDesktop(VappAppWidget *widget)
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


void VappDesktopPage::removeFromPage(VappAppWidget *widget)
{
    widget->removeFromParentFrame();
}


void VappDesktopPage::getFromPage(VfxS32 idx, VfxObjList &objList)
{
    if (idx < 0 || idx >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return;
    }

    const VfxRect pageRect = getPageRect(idx);

    for (VfxFrame *frame = getFirstChildFrame();
         frame != NULL;
         frame = frame->getNextFrame())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(frame, VappAppWidget);

        if (widget)
        {
            //
            // If the position of the widget is located within this page, we
            // consider it belongs to this page.
            //
            VfxPoint pos = widget->getPos();

            if (pageRect.contains(pos))
            {
                objList.append(widget);
            }
        }
    }
}


void VappDesktopPage::getFromAllPage(VfxObjList &objList)
{
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        getFromPage(i, objList);
    }
}


VfxBool VappDesktopPage::canAddToPage(
    const VappAppWidget *widget,
    VfxS32 pageIndex) const
{
    return !searchRoom(widget, pageIndex).isEmpty();
}


VfxBool VappDesktopPage::canAddToPageIfAny(const VappAppWidget *widget) const
{
    return !searchRoomIfAny(widget).isEmpty();
}


VfxBool VappDesktopPage::canAddToNearest(
    const VappAppWidget *widget,
    VfxS32 pageIndex) const
{
    return !searchNearest(widget, pageIndex).isEmpty();
}


VfxBool VappDesktopPage::canAddToDesktop(const VappAppWidget *widget) const
{
    if (canAddToNearest(widget) || canAddToPageIfAny(widget))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxRect VappDesktopPage::searchRoom(
    const VappAppWidget *widget,
    VfxS32 pageIndex) const
{
    if (pageIndex < 0)
    {
        pageIndex = getPageIndex(widget->getPos());
    }

    VfxSize roomSize = getRoomSize(widget);
    VfxS32 firstIndex = getFirstRoomIndex(roomSize, pageIndex);
    VfxS32 lastIndex = getLastRoomIndex(roomSize, pageIndex);

    for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
    {
        VfxRect room = getRoom(roomSize, idx);
        VappAppWidget *occupiedWidget = getOccupiedWidget(room);

        if (!occupiedWidget || occupiedWidget == widget)
        {
            return room;
        }
    }

    return VFX_RECT_ZERO;
}


VfxRect VappDesktopPage::searchRoomIfAny(const VappAppWidget *widget) const
{
    for (VfxS32 pageIndex = 0; pageIndex < VAPP_DESKTOP_MAX_PAGE_NUM; pageIndex++)
    {
        VfxRect room = searchRoom(widget, pageIndex);
        if (!room.isEmpty())
        {
            return room;
        }
    }

    return VFX_RECT_ZERO;
}


VfxRect VappDesktopPage::searchNearest(
    const VappAppWidget *widget,
    VfxS32 pageIndex) const
{
    if (pageIndex < 0)
    {
        pageIndex = getPageIndex(widget->getPos());
    }

    VfxSize roomSize = getRoomSize(widget);
    VfxRect nearestRoom(VFX_RECT_ZERO);
    VfxS32 minDistance = INT_MAX;
    VfxS32 firstIndex = getFirstRoomIndex(roomSize, pageIndex);
    VfxS32 lastIndex = getLastRoomIndex(roomSize, pageIndex);

    for (VfxS32 idx = firstIndex; idx <= lastIndex; idx++)
    {
        VfxRect room = getRoom(roomSize, idx);
        VfxS32 distance = calcDistance(widget->getPos(), room.getMidPoint());
        VappAppWidget *occupiedWidget = getOccupiedWidget(room);

        if ((!occupiedWidget || occupiedWidget == widget) &&
            (distance < minDistance))
        {
            nearestRoom = room;
            minDistance = distance;
        }
    }

    return nearestRoom;
}


VfxS32 VappDesktopPage::calcDistance(
    const VfxPoint &p1,
    const VfxPoint &p2) const
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


void VappDesktopPage::initSlideSpeed()
{
    m_slideSpeed = 0;
}


void VappDesktopPage::updateSlideSpeed(VfxPenEvent &event)
{
    VfxMsec time = vfxAbs(event.timeStamp - event.prevTimeStamp);
    VfxS32 offset = vfxAbs(event.pos.x - event.prevPos.x);

    if (time != 0)
    {
        m_slideSpeed = (offset * 1000) / time;
    }
}


VfxMsec VappDesktopPage::clampSlideDuration(VfxMsec duration)
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


VfxS32 VappDesktopPage::clampIndex(VfxS32 pageIndex) const
{
    if (pageIndex < 0)
    {
        return 0;
    }

    if (pageIndex >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return VAPP_DESKTOP_MAX_PAGE_NUM - 1;
    }

    return pageIndex;
}


VfxSize VappDesktopPage::getTileSize()
{
    return VfxSize(VAPP_DESKTOP_PAGE_TILE_WIDTH, VAPP_DESKTOP_PAGE_TILE_HEIGHT);
}


VfxSize VappDesktopPage::getRoomSize(const VappAppWidget *widget)
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


VfxS32 VappDesktopPage::getTotalRoomNum(const VfxSize &roomSize)
{
    return getPageRoomNum(roomSize) * VAPP_DESKTOP_MAX_PAGE_NUM;
}


VfxS32 VappDesktopPage::getPageRoomNum(const VfxSize &roomSize)
{
    return getPageHorizRoomNum(roomSize) * getPageVertiRoomNum(roomSize);
}


VfxS32 VappDesktopPage::getPageHorizRoomNum(const VfxSize &roomSize)
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



VfxS32 VappDesktopPage::getPageVertiRoomNum(const VfxSize &roomSize)
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


VfxS32 VappDesktopPage::getFirstRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * pageIdx;
}


VfxS32 VappDesktopPage::getLastRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * (pageIdx + 1) - 1;
}


VfxRect VappDesktopPage::getRoom(
    const VfxSize &roomSize,
    VfxS32 pageIdx,
    VfxS32 x,
    VfxS32 y)
{
    VfxS32 horizRoomNum = getPageHorizRoomNum(roomSize);
    VfxS32 vertiRoomNum = getPageVertiRoomNum(roomSize);
    VfxSize tileSize = getTileSize();
    VfxPoint pos;

    if (pageIdx < 0 || pageIdx >= VAPP_DESKTOP_MAX_PAGE_NUM ||
        x < 0 || x >= horizRoomNum ||
        y < 0 || y >= vertiRoomNum)
    {
        return VFX_RECT_ZERO;
    }

    //
    // Get screen size.
    //
    VfxSize screenSize = getScreenSize();

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

    pos.y = offset.y + y * (tileSize.height);

    return VfxRect(pos, roomSize);
}


VfxRect VappDesktopPage::getRoom(const VfxSize &roomSize, VfxS32 idx)
{
    //
    // Page Index
    //
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum == 0)
    {
        return VFX_RECT_ZERO;
    }

    VfxS32 pageIdx = idx / pageRoomNum;
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

    return getRoom(roomSize, pageIdx, x, y);
}


VappAppWidget *VappDesktopPage::getOccupiedWidget(const VfxRect &room) const
{
    for (VfxFrame *frame = getFirstChildFrame();
         frame != NULL;
         frame = frame->getNextFrame())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(frame, VappAppWidget);

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


VfxBool VappDesktopPage::isOccupied(const VfxRect &room) const
{
    return getOccupiedWidget(room) ? VFX_TRUE : VFX_FALSE;
}


void VappDesktopPage::setWidgetOnRoom(
    VappAppWidget *widget,
    const VfxRect &room) const
{
    VfxPoint pos = room.getMidPoint();

    widget->setPos(pos);
}


VfxSize VappDesktopPage::getScreenSize()
{
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    return VfxSize(screenSize.width, screenSize.height);
}


#if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
void VappDesktopPage::setDebugText(
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
        m_debugPanel->setImgContent(VfxImageSrc(IMG_ID_VAPP_DESKTOP_SNAPSHOT_BG));
        m_debugPanel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_debugPanel->setAnchor(0.5f, 1.0f);

        VfxPoint pos;

        pos.x = parent->getBounds().getMidX();
        pos.y = DEBUG_TEXT_POS_Y;

        m_debugPanel->setPos(pos);

        VFX_OBJ_CREATE(m_debugText, VfxTextFrame, m_debugPanel);

        m_debugText->setAnchor(0.5f, 0.5f);
        m_debugText->setFont(VFX_FONT_DESC_SMALL);
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
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE) */


#if defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE)
void VappDesktopPage::setAutoSlideHint(VfxS32 location)
{
    VfxFrame *parent = getParentFrame();

    if (!m_autoSlideHint)
    {
        VFX_OBJ_CREATE(m_autoSlideHint, VfxFrame, this);
        parent->addChildFrame(m_autoSlideHint);

        m_autoSlideHint->setImgContent(VfxImageSrc(IMG_ID_VAPP_DESKTOP_SNAPSHOT_BG));
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

#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE) */
#endif /* defined(__MMI_VUI_LAUNCHER__) */

