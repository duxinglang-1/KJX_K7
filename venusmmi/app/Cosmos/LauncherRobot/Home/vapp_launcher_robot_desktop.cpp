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
 *  vapp_launcher_robot_desktop.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_desktop.h"
#include "mmi_rp_vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_page_transition_setting.h"
#include "vapp_launcher_robot_page_transition_factory.h"

//
// C headers
//
extern "C"
{
#if defined(VAPP_LAUNCHER_ROBOT_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}

#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH (VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_WIDTH)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT (VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT + VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH)

#if defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH (0.55*VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT (0.55*VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT)
#else
#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH (VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT (VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT)
#endif


/*****************************************************************************
 * Home Desktop Page Class
 *****************************************************************************/

VappLauncherRobotDesktopPage::VappLauncherRobotDesktopPage() :
    m_id(0),
    m_sourceRect(VFX_RECT_ZERO),
    m_oriRect(VFX_RECT_ZERO),
    m_resizeRect(VFX_RECT_ZERO),
    m_objList(),
    m_bg(NULL)
{
    // Do nothing.
}


void VappLauncherRobotDesktopPage::onInit()
{
    VfxFrame::onInit();
    
    VfxS32 width = getParentFrame()->getSize().width;
    VfxS32 height = VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT + VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH;

    setSize(width, height);
    
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_BG);
    m_bg->setAnchor(0.5, 0.5);
    m_bg->setPos(getSize().width/2, VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH + VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT/2);
    m_bg->setSize(getSize().width, VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT);
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bg->setOpacity(0);
    m_bg->setAutoAnimate(VFX_TRUE);
}


void VappLauncherRobotDesktopPage::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappLauncherRobotDesktopPage::setBounds(const VfxRect &value)
{
    VfxFrame::setBounds(value);
    m_sourceRect = value;
}


void VappLauncherRobotDesktopPage::setId(VfxId id)
{
    m_id = id;
}


VfxId VappLauncherRobotDesktopPage::getId() const
{
    return m_id;
}


void VappLauncherRobotDesktopPage::setLayout(
    const VfxRect &oriRect,
    const VfxRect &resizeRect)
{
    m_oriRect = oriRect;
    m_resizeRect = resizeRect;
}


void VappLauncherRobotDesktopPage::getLayout(
    VfxRect &oriRect,
    VfxRect &resizeRect) const

{
    oriRect = m_oriRect;
    resizeRect = m_resizeRect;
}
    

void VappLauncherRobotDesktopPage::addToContainer(
    VfxFrame *frame)
{
    if (frame)
    {
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
    

void VappLauncherRobotDesktopPage::removeFromContainer(
    VfxObjList &objList)
{
    for (VfxObjListEntry *entry = m_objList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

        if (frame)
        {
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


void VappLauncherRobotDesktopPage::setContentRect(
    const VfxRect &rect)
{
    VfxFPoint ratio = getResizeRatio(rect, m_oriRect);

    for (VfxObjListEntry *entry = m_objList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

        if (frame)
        {
            // Calculate the new position.
            VfxPoint srcPos = frame->getPos();
            VfxPoint dstPos, offset;

            dstPos.x = (VfxS32)(srcPos.x * ratio.x + 0.5f);
            dstPos.y = (VfxS32)(srcPos.y * ratio.y + 0.5f);

            offset.x = dstPos.x - srcPos.x;
            offset.y = dstPos.y - srcPos.y;

            // Transform this frame.
            VfxTransform trans;

            trans.init(VRT_TRANSFORM_TYPE_AFFINE);
            trans.data.affine.sx = ratio.x;
            trans.data.affine.sy = ratio.y;
            trans.data.affine.tx = (VfxFloat)(rect.origin.x + offset.x);
            trans.data.affine.ty = (VfxFloat)(rect.origin.y + offset.y);

            frame->setTransform(trans);
        }
    }
    if (m_bg)
    {
        // Calculate the new position.
        VfxPoint srcPos = m_bg->getPos();
        VfxPoint dstPos, offset;

        dstPos.x = (VfxS32)(srcPos.x * ratio.x + 0.5f);
        dstPos.y = (VfxS32)(srcPos.y * ratio.y + 0.5f);

        offset.x = dstPos.x - srcPos.x;
        offset.y = dstPos.y - srcPos.y;

        // Transform this frame.
        VfxTransform trans;

        trans.init(VRT_TRANSFORM_TYPE_AFFINE);
        trans.data.affine.sx = ratio.x;
        trans.data.affine.sy = ratio.y;
        trans.data.affine.tx = (VfxFloat)(rect.origin.x + offset.x);
        trans.data.affine.ty = (VfxFloat)(rect.origin.y + offset.y);

        m_bg->setTransform(trans);
    }
}


VfxBool VappLauncherRobotDesktopPage::isEmpty()
{
    return m_objList.isEmpty();
}


VfxFPoint VappLauncherRobotDesktopPage::getResizeRatio(
    const VfxRect &dst,
    const VfxRect &src) const
{
    VFX_ASSERT(src.size.width > 0 && src.size.height > 0);

    VfxFloat sx = (VfxFloat)dst.size.width / src.size.width;
    VfxFloat sy = (VfxFloat)dst.size.height / src.size.height;

    return VfxFPoint(sx, sy);
}
    

void VappLauncherRobotDesktopPage::showBg(VfxBool isShow, VfxFloat bgOpacity, VfxBool isAnimatable)
{
    VfxAutoAnimate::begin();
    
    if (isAnimatable)
    {
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        VfxAutoAnimate::setDuration(50);
    }
    else
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
    }

    if(isShow)
    {
        m_bg->setOpacity(bgOpacity);
    }
    else
    {
        m_bg->setOpacity(0);
    }

    VfxAutoAnimate::commit();

}


void VappLauncherRobotDesktopPage::forceSetContentOpacity(VfxFloat opacity)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    for (VfxObjListEntry *entry = m_objList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

        if (frame)
        {
            // if the opacity is the same, it can not set it again,
            // needs to set other value before
            if(opacity == 0)
            {
                frame->setOpacity(1);
                frame->setOpacity(0);
            }
            else
            {
                frame->setOpacity(opacity/2);
                frame->setOpacity(opacity);
            }
        }
    }
         
    VfxAutoAnimate::commit();
}


/*****************************************************************************
 * Desktop Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotDesktop", VappLauncherRobotDesktop, VfxControl);


const VfxS32 VappLauncherRobotDesktop::s_vertiTileNum = VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM;
const VfxS32 VappLauncherRobotDesktop::s_horizTileNum = VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM;
const VfxS32 VappLauncherRobotDesktop::s_outerBorderTopWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH;
const VfxS32 VappLauncherRobotDesktop::s_outerBorderBottomWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH;
const VfxS32 VappLauncherRobotDesktop::s_outerBorderLeftWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH;
const VfxS32 VappLauncherRobotDesktop::s_outerBorderRightWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH;
const VfxS32 VappLauncherRobotDesktop::s_autoSlideBorderLeftWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH;
const VfxS32 VappLauncherRobotDesktop::s_autoSlideBorderRightWidth = VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH;


VappLauncherRobotDesktop::VappLauncherRobotDesktop() :
    m_currentPageIndex(0),
    m_slideSpeed(0),
    m_tlTranslateDummyNodeX(NULL),
    m_timerSlideFantasyEffect(NULL),
    m_animDummyFrame(NULL),
    m_transition(NULL),
    m_slideDirection(0),
    m_timerPrecachePageChildren(NULL),
    m_isFreezePage(VFX_FALSE),
    m_quickSwipeTicket(0),
    m_transitionZoomInType(VAPP_PAGE_TRANSITION_INVALID),
    m_transitionZoomOutType(VAPP_PAGE_TRANSITION_INVALID),
    m_transitionType(VAPP_PAGE_TRANSITION_INVALID)
#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE)
    ,
    m_debugPanel(NULL),
    m_debugText(NULL),
    m_isPenMoved(VFX_FALSE)
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE) */
#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE)
    ,
    m_autoSlideHint(NULL)
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE) */
{
    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_page[i] = NULL;
    }
}


void VappLauncherRobotDesktop::onInit()
{
    VfxControl::onInit();

    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    //
    // This frame.
    //
    setAutoAnimate(VFX_TRUE);

#if defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
    VfxS32 height = VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT + VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH;
#else
    VfxS32 height = screenSize.height;
#endif

    setSize(VfxSize(screenSize.width, height));

    VFX_OBJ_CREATE(m_tlTranslateDummyNodeX, VfxS32Timeline, this);
    m_tlTranslateDummyNodeX->m_signalStopped.connect(this, &VappLauncherRobotDesktop::updateDummyNodePosX);

    VFX_OBJ_CREATE(m_animDummyFrame, VfxFrame, this);
    getAnimDummyFrame()->setSize(1, 1);
    getAnimDummyFrame()->setBgColor(VFX_COLOR_RED);
    getAnimDummyFrame()->setOpacity(0);
    getAnimDummyFrame()->setFpeUser0(getBounds().getMinX());
    getAnimDummyFrame()->setCacheMode(VFX_CACHE_MODE_PREVENT);

    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_page[i], VappLauncherRobotDesktopPage, this);
        m_page[i]->setPos(getPageRect(i).getMinX(), getPageRect(i).getMinY());
        m_page[i]->setFpeUser0(m_page[i]->getPos().x);
        m_page[i]->setLayout(VfxRect(0,0,VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT),
                             VfxRect(0,0,VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT));
    }
    
    VFX_OBJ_CREATE(m_timerPrecachePageChildren, VfxTimer, this);
    m_timerPrecachePageChildren->setStartDelay(350);
    m_timerPrecachePageChildren->m_signalTick.connect(this, &VappLauncherRobotDesktop::onPrecachePageChildrenCallback);

    VFX_OBJ_CREATE(m_timerSlideFantasyEffect, VfxTimer, this);
    m_timerSlideFantasyEffect->setStartDelay(1);
    m_timerSlideFantasyEffect->m_signalTick.connect(this, &VappLauncherRobotDesktop::onSlideFantasyEffectCallback);
}


void VappLauncherRobotDesktop::updateDummyNodePosX(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    // this callback may be arrived during pen move event

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_UPDATE_DUMMY_NODE_POS_X, 200));

    VAPP_LAUNCHER_ROBOT_SLA(("HTC", SA_label));

    // to value has problem
    if(!isCompleted)
    {
        return;
    }

    VfxS32Timeline *tl = (VfxS32Timeline *)timeline;
    
    VfxRect bounds = getBounds();
    bounds.origin.x = tl->getToValue();
    
#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    // set the bounds to the normal range when swipe animation stopped
    if(bounds.getMinX() > bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        bounds.origin.x = bounds.origin.x % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
    }
    else if(bounds.getMinX() < 0)
    {
        bounds.origin.x = bounds.origin.x % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
        if(bounds.origin.x  != 0)
        {
            bounds.origin.x = bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM) + bounds.origin.x;
        }
    }
#endif

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    // page FPE transform will influenced by desktop bounds,
    // so only update desktop bounds after end of sliding animation
    setBounds(bounds);

    // update current desktop bounds because page FPE transform needs to adjust translate transform by this value
    getAnimDummyFrame()->setFpeUser0(getBounds().getMinX());
    getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));

    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(m_page[i]->getSize() == VfxSize(VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH,VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT))
        {
            m_page[i]->setSize(VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT);
            m_page[i]->setContentRect(VfxRect(0, 0, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT));
            showDesktopPageBg(VFX_FALSE);
            unfreezeDesktopPage();
        }
    }

    VfxAutoAnimate::commit();

    // reset page transition effect
    setupTransitionEffect(m_transitionZoomInType);
    setDesktopPageUnhittable(VFX_FALSE);
    unHideDesktopPage();
    unfreezeCurrentDesktopPage();
    m_timerPrecachePageChildren->start();

    emitPageSlideEndSignal();
}


VfxFrame *VappLauncherRobotDesktop::getAnimDummyFrame() const
{
    return m_animDummyFrame;
}


void VappLauncherRobotDesktop::onDeinit()
{
    m_tlTranslateDummyNodeX->m_signalStopped.disconnect(this, &VappLauncherRobotDesktop::updateDummyNodePosX);

    releaseTransitionEffect();
    VfxControl::onDeinit();
}


void VappLauncherRobotDesktop::setBounds(const VfxRect &value)
{
    VfxRect bounds = value;

    // allow desktop bounds overflow the max    desktop bounds(page x page width), 
    // it will slide to nearest page after pen up
    VfxControl::setBounds(bounds);
}


void VappLauncherRobotDesktop::onDraw(VfxDrawContext &dc)
{
#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_TILE)
    VfxSize tileSize = getTileSize();

    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; pageIndex++)
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

            srand(pageIndex * VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM + idx);

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
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_TILE) */
}


VfxBool VappLauncherRobotDesktop::doPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_DO_PEN_INPUT,
                           'D', event.timeStamp,
                           event.downPos.x, event.downPos.y));

            VAPP_LAUNCHER_ROBOT_SLA(("HDD", SA_label));

            initSlideSpeed();

        #if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_FALSE;
        #endif
            m_timerPrecachePageChildren->stop();

            // not allow to normal swipe when desktop page is swiping
            if(m_tlTranslateDummyNodeX->getIsEnabled())
            {
                break;
            }
            else
            {
                // reset m_quickSwipeTicket if the swipe is not during animation
                // this is not related to the previous one
                m_quickSwipeTicket = 0;
            }
            
            updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);
            break;
        }
        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_DO_PEN_INPUT,
                           'M', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_ROBOT_SLA(("HDM", SA_label));

            updateSlideSpeed(event);

            if(m_tlTranslateDummyNodeX->getIsEnabled())
            {
                break;
            }
            
            updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);

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

            slidePageForPenMove(event);
            
            VfxAutoAnimate::commit();
            
            // advance freeze next page 
            freezeDesktopPage(FREEZE_FOR_SLIDE);

        #if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE)
            m_isPenMoved = VFX_TRUE;
        #endif

            break;
        }
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_DO_PEN_INPUT,
                           'L', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_ROBOT_SLA(("HDL", SA_label));

            break;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_DO_PEN_INPUT,
                           'U', event.timeStamp,
                           event.predictPos.x, event.predictPos.y));

            VAPP_LAUNCHER_ROBOT_SLA(("HDU", SA_label));

            VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
            VfxS32 xDiff = event.predictPos.x - event.downPos.x;

            if(m_transitionType == m_transitionZoomInType)
            {
                VfxS32 tmpDir = (xDiff >= 0) ? -1: 1;

                if( m_quickSwipeTicket == 0 &&
                    tDiff <= 200)
                {
                    m_quickSwipeTicket++;
                    m_quickSwipeDirection = tmpDir;
                }
                else if ( m_quickSwipeTicket == 1 && 
                          m_transition->isSupportQuickSwipe() &&
                          tDiff <= 200 &&
                          m_tlTranslateDummyNodeX->getIsEnabled() &&
                          m_quickSwipeDirection == tmpDir )
                {
                    m_tlTranslateDummyNodeX->stop();
                    
                    m_quickSwipeDirection = tmpDir;

                    m_timerSlideFantasyEffect->start();
                    m_quickSwipeTicket = 0;
                    break;
                }
                else
                {
                    m_quickSwipeTicket = 0;
                }
            }

            if(m_tlTranslateDummyNodeX->getIsEnabled())
            {
                break;
            }

            slidePageForPenUp(event);
            m_slideDirection = 0;
        #if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE)
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
        #endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE) */

            break;
        }
        case VFX_PEN_EVENT_TYPE_ABORT:
        {
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_DO_PEN_INPUT,
                           'A', event.timeStamp,
                           event.pos.x, event.pos.y));

            VAPP_LAUNCHER_ROBOT_SLA(("HDA", SA_label)); 
            m_tlTranslateDummyNodeX->stop();
            m_timerSlideFantasyEffect->stop();
            m_slideDirection = 0;
            slideToNearest();
            unfreezeDesktopPage();
            break;
        }
        default:
            break;
    }

    return VFX_TRUE;
}


void VappLauncherRobotDesktop::enterDesktop()
{
    unHideDesktopPage();
    m_timerPrecachePageChildren->start();
}


void VappLauncherRobotDesktop::exitDesktop()
{
    unfreezeDesktopPage();
}


VfxS32 VappLauncherRobotDesktop::getCurrentPageIndex() const
{
    return m_currentPageIndex;
}


VfxS32 VappLauncherRobotDesktop::getPageIndex(const VfxPoint &pos) const
{
    VfxS32 width = getBounds().getWidth();
    VfxS32 pageIndex = pos.x / width;

    return clampIndex(pageIndex);
}


VfxS32 VappLauncherRobotDesktop::getPageIndex(const VappWidget *widget) const
{

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
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


VfxS32 VappLauncherRobotDesktop::getPageIndexAndPos(
    const VfxPoint &pos,          
    VfxPoint &pagePos        
) const
{
    VfxS32 pageIndex = getPageIndex(pos);
    pagePos = VfxPoint(pos.x - pageIndex*getBounds().getWidth(), pos.y);
    return pageIndex;

}


VfxRect VappLauncherRobotDesktop::getPageRect(VfxS32 pageIndex) const
{
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        return VFX_RECT_ZERO;
    }

    VfxPoint origin;

    origin.x = pageIndex * getBounds().getWidth();
    origin.y = 0;

    return VfxRect(origin, getBounds().size);
}


VfxRect VappLauncherRobotDesktop::getPageValidRect(VfxS32 pageIndex) const
{
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
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


VfxS32 VappLauncherRobotDesktop::getAutoSlideDirection(const VfxPoint &pos) const
{
    VfxS32 pageIndex = getPageIndex(pos);
    VfxS32 width = getBounds().getWidth();
    VfxS32 leftEdge = width * pageIndex + s_autoSlideBorderLeftWidth;
    VfxS32 rightEdge = width * (pageIndex + 1) - s_autoSlideBorderRightWidth;

#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE)
    VfxS32 location = 0;

    if (pos.x < leftEdge)
    {
        location = -1;
    }
    else if (pos.x >= rightEdge)
    {
        location = 1;
    }

    ((VappLauncherRobotDesktop *)this)->setAutoSlideHint(location);
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE) */

    //
    // Return value meanings:
    //
    //   0: cannot auto-slide the page
    //  -1: can auto-slide to the previous page
    //   1: can auto-slide to the next page
    //
#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
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
    else if (pos.x >= rightEdge && pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1 )
    {
        return 1;
    }
#endif

    return 0;
}


VfxS32 VappLauncherRobotDesktop::getDistanceToNext()
{
    if (m_currentPageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1)
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


VfxS32 VappLauncherRobotDesktop::getDistanceToPrevious()
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


VfxS32 VappLauncherRobotDesktop::getDistanceToNearest()
{
    VfxS32 distToNext = getDistanceToNext();
    VfxS32 distToPrevious = getDistanceToPrevious();

    return vfxMin(distToNext, distToPrevious);
}


VfxMsec VappLauncherRobotDesktop::getSlideDurationToNext()
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


VfxMsec VappLauncherRobotDesktop::getSlideDurationToPrevious()
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


VfxMsec VappLauncherRobotDesktop::getSlideDurationToNearest()
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


void VappLauncherRobotDesktop::emitPageSlideSignal(
    VfxS32 newDesktopBoundsOriginX,
    VfxS32 oldDesktopBoundsOriginX,
    VfxS32 duration)
{
    VfxRect bounds = getBounds();
    
#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    // set the bounds to the normal range when swipe animation stopped
    if(newDesktopBoundsOriginX > bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        //bounds.origin.x = 0;
        newDesktopBoundsOriginX = newDesktopBoundsOriginX % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
    }
    else if(newDesktopBoundsOriginX < -bounds.getWidth())
    {
        newDesktopBoundsOriginX = newDesktopBoundsOriginX % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
        newDesktopBoundsOriginX = bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM) + newDesktopBoundsOriginX;
    }
#endif

    m_signalPageSlide.emit(this, newDesktopBoundsOriginX, getAnimDummyFrame()->getPos().x, duration);
}


void VappLauncherRobotDesktop::emitPageSlideEndSignal()
{
    m_signalPageSlideEnd.emit();
}


VfxBool VappLauncherRobotDesktop::isSliding()
{
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappLauncherRobotDesktop::slidePageForPenMove(VfxPenEvent &event)
{
    VfxS32 offset = event.pos.x - event.prevPos.x;
    VfxRect bounds = getBounds();
    bounds.origin.x = getAnimDummyFrame()->getPos().x;

#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    //
    // overflow desktop bounds will translate to first desktop page bounds 
    // in page framePropertyEffectCallback
    //
    //VfxFloat overflowRatio = 1;
#else
    // damping effect
    //VfxFloat overflowRatio = 1;

    if((bounds.origin.x > 
        getBounds().getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1) &&
       bounds.origin.x < 
        getBounds().getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)) ||
       (bounds.origin.x > 
        -getBounds().getWidth() &&
       bounds.origin.x < 0))
    {
        // reference iphone effect, move 0.5 times offset on the first/last page
        offset = 0.5 * offset;
    }
#endif

#if defined(VAPP_LAUNCHER_ROBOT_SLIDE_ONLY_TWO_PAGE_AT_A_TIME)
    if(m_slideDirection == 0)
    {
        m_slideDirection = ( (event.pos.x - event.prevPos.x)>=0 )? -1 : 1 ;
    }

    if( m_slideDirection >= 0 && 
        (bounds.origin.x-offset < getAnimDummyFrame()->getFpeUser0()))
    {
        bounds.origin.x = getAnimDummyFrame()->getFpeUser0();
    }
    else if( m_slideDirection < 0 && 
        (bounds.origin.x-offset > getAnimDummyFrame()->getFpeUser0()))
    {
        bounds.origin.x = getAnimDummyFrame()->getFpeUser0();
    }
    else
#endif
    {
        bounds.origin.x -= offset;
    }

    emitPageSlideSignal(getAnimDummyFrame()->getPos().x, bounds.getMinX(), 3);
    getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));
}


void VappLauncherRobotDesktop::slidePageForPenUp(VfxPenEvent &event)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HPU", SA_start));
    
    VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
    VfxS32 xDiff = event.predictPos.x - event.downPos.x;

    if (tDiff >= SWIPE_CRITERIA || VFX_ABS(xDiff) <= SENSITIVITY)
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_NORMAL_SWIPE,
                       xDiff, tDiff));

        slideToNearest(getSlideDurationToNearest());
    }
    else
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_QUICK_SWIPE,
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
    VAPP_LAUNCHER_ROBOT_SLA(("HPU", SA_stop));
}


VfxBool VappLauncherRobotDesktop::slideWithFantasticEffect(VfxS32 direction)
{
#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if (m_currentPageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1)
    {
        return VFX_FALSE;
    }
#endif

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_SLIDE_WITH_FANTASTIC_EFFECT, 200));
    unfreezeDesktopPage();
    showDesktopPageBg(VFX_TRUE);
    if(direction < 0)
    {
        return slideByValue(-1-VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM, getSlideDurationToPrevious()*m_transition->getExtendAnimationTime());
    }
    else
    {
        return slideByValue(1 + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM, getSlideDurationToPrevious()*m_transition->getExtendAnimationTime());
    }
}


VfxBool VappLauncherRobotDesktop::slideToNext(VfxMsec duration)
{
#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if (m_currentPageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1)
    {
        return VFX_FALSE;
    }
#else
    // not allow to move desktop when desktop page is swiping
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_FALSE;
    }
#endif

    m_timerPrecachePageChildren->stop();
    updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);
    m_slideDirection = 1;
    freezeDesktopPage(FREEZE_FOR_SLIDE);
    return slideTo(m_currentPageIndex + 1, duration);
}


VfxBool VappLauncherRobotDesktop::slideToPrevious(VfxMsec duration)
{
#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if (m_currentPageIndex <= 0)
    {
        return VFX_FALSE;
    }
#else
    // not allow to move desktop when desktop page is swiping
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_FALSE;
    }
#endif

    m_timerPrecachePageChildren->stop();
    updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);
    m_slideDirection = -1;
    freezeDesktopPage(FREEZE_FOR_SLIDE);
    return slideTo(m_currentPageIndex - 1, duration);
}


VfxBool VappLauncherRobotDesktop::slideToNearest(VfxMsec duration)
{
    VfxS32 x = getAnimDummyFrame()->getPos().x;
    VfxS32 width = getBounds().getWidth();

    VfxS32 idx = (VfxS32)vfx_sys_floor((VfxFloat)x / width + 0.5f);

#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    idx = clampIndex(idx);
#endif

    updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);
    return slideTo(idx, duration);
}


VfxBool VappLauncherRobotDesktop::slideToCentra(VfxBool isShowPageBg, VfxMsec duration)
{
    // not allow to move desktop when desktop page is swiping
    if(m_tlTranslateDummyNodeX->getIsEnabled())
    {
        return VFX_FALSE;
    }

    updateTransitionEffect(m_transitionZoomInType, m_transitionZoomOutType);

    // slideTo use timeline to trigger FTP transition effect, it can not update in first SSE frame
    // So if duration == 0, change the dummy frame position directly,
    // it is used on launcher initial, show the centra page at first
    if(duration == 0)
    {
        VfxRect bounds = getBounds();
        VfxS32 newPos = bounds.getWidth() * getCentraPageIndex();
        bounds.origin.x = newPos;
        
        getAnimDummyFrame()->setPos(bounds.origin.x,0);
        setBounds(bounds);
        
        // update current desktop bounds because page FPE transform needs to adjust translate transform by this value
        getAnimDummyFrame()->setFpeUser0(bounds.getMinX());
        getAnimDummyFrame()->setPos(VfxPoint(bounds.getMinX(), bounds.getMinY()));

        if (m_currentPageIndex != getCentraPageIndex())
        {
            m_currentPageIndex = getCentraPageIndex();
            m_signalPageChanged.emit(this);
        }
        return VFX_TRUE;
    }
    
    return slideTo(getCentraPageIndex(), isShowPageBg, duration);
}


VfxBool VappLauncherRobotDesktop::slideTo(VfxS32 pageIndex, VfxBool isShowPageBg, VfxMsec duration)
{   
#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if (pageIndex < 0 || pageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
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

    if (getAnimDummyFrame()->getPos().x != newPos)
    {
        emitPageSlideSignal(newPos, getAnimDummyFrame()->getPos().x, duration);
        
        setDesktopPageUnhittable(VFX_TRUE);
        
        // use fpe user 0 to store the translation data
        m_tlTranslateDummyNodeX->setTarget(getAnimDummyFrame());
        m_tlTranslateDummyNodeX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_tlTranslateDummyNodeX->setDurationTime(duration);
        m_tlTranslateDummyNodeX->setRepeatCount(1);
        m_tlTranslateDummyNodeX->setIsFromCurrent(VFX_TRUE);
        m_tlTranslateDummyNodeX->setFromValue(getAnimDummyFrame()->getPos().x);
        m_tlTranslateDummyNodeX->setToValue(newPos);
        m_tlTranslateDummyNodeX->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlTranslateDummyNodeX->start();

        // set total length of movement
        getAnimDummyFrame()->setFilterTiming(getAnimDummyFrame()->getPos().x);
        getAnimDummyFrame()->setPosZ(newPos);
    }
    else
    {
        // move has limited range , it may stop at the boundary,
        // so it will no let timeline go, then callback will not happen
        // needs to unHideDesktop in this case
        unHideDesktopPage();
    }

    //
    // Emit signal if the page index is changed.
    //
#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    pageIndex = pageIndex % VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    if(pageIndex < 0)
    {
        pageIndex = pageIndex + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
#endif

    if (m_currentPageIndex != pageIndex)
    {
        m_currentPageIndex = pageIndex;
        m_signalPageChanged.emit(this);
    }

    return VFX_TRUE;
}


VfxBool VappLauncherRobotDesktop::slideByValue(VfxS32 pageOffset, VfxMsec duration)
{
    if (duration < 0)
    {
        duration = SLIDE_DEFAULT_DURATION;  // Use default sliding duration.
    }

    //
    // Update page bounds.
    //
    VfxRect bounds = getBounds();
    VfxS32 newPos = getAnimDummyFrame()->getFpeUser0() + bounds.getWidth() * pageOffset;

    if (getAnimDummyFrame()->getPos().x != newPos)
    {
        emitPageSlideSignal(newPos, getAnimDummyFrame()->getPos().x, duration);
        
        setDesktopPageUnhittable(VFX_TRUE);

        // use fpe user 0 to store the translation data
        m_tlTranslateDummyNodeX->setTarget(getAnimDummyFrame());
        m_tlTranslateDummyNodeX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_tlTranslateDummyNodeX->setDurationTime(duration);
        m_tlTranslateDummyNodeX->setRepeatCount(1);
        m_tlTranslateDummyNodeX->setIsFromCurrent(VFX_TRUE);
        m_tlTranslateDummyNodeX->setFromValue(getAnimDummyFrame()->getPos().x);
        m_tlTranslateDummyNodeX->setToValue(newPos);
        m_tlTranslateDummyNodeX->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlTranslateDummyNodeX->start();

        // set total length of movement
        getAnimDummyFrame()->setFilterTiming(getAnimDummyFrame()->getPos().x);
        getAnimDummyFrame()->setPosZ(newPos);

        // prepare to freeze total page to do quick slide animation
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        
        for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
        {
            if(m_transition->isResizePageForSlim())
            {
                m_page[i]->setSize(VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT);
                m_page[i]->setContentRect(VfxRect(0, 0, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT));
            }
            m_page[i]->setHidden(VFX_FALSE);
            freezeDesktopPage(FREEZE_ALL);
        }
        
        VfxAutoAnimate::commit();
    }
    else
    {
        // move has limited range , it may stop at the boundary,
        // so it will no let timeline go, then callback will not happen
        // needs to unHideDesktop in this case
        unHideDesktopPage();
    }


    // set the bounds to the normal range when swipe animation stopped
    if(newPos > bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        newPos = newPos % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
    }
    else if(newPos < 0)
    {
        newPos = newPos % (bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
        if(newPos != 0)
        {
            newPos = bounds.getWidth()*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM) + newPos;
        }
    }

    VfxS32 pageIndex = newPos/bounds.getWidth();
    pageIndex = pageIndex % VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    if(pageIndex < 0)
    {
        pageIndex = pageIndex + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
    
    if (m_currentPageIndex != pageIndex)
    {
        m_currentPageIndex = pageIndex;
        m_signalPageChanged.emit(this);
    }
    return VFX_TRUE;
}


VfxBool VappLauncherRobotDesktop::addToPage(VappWidget *widget, VfxS32 pageIndex)
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


VfxBool VappLauncherRobotDesktop::addToPageIfAny(VappWidget *widget)
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


VfxBool VappLauncherRobotDesktop::addToNearest(VappWidget *widget, VfxS32 pageIndex)
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


VfxBool VappLauncherRobotDesktop::addToDesktop(VappWidget *widget)
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


VfxBool VappLauncherRobotDesktop::addToDesktop(VappWidget *widget, VfxS32 pageIndex)
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


void VappLauncherRobotDesktop::removeFromDesktop(VappWidget *widget)
{
    widget->removeFromParentFrame();
}


void VappLauncherRobotDesktop::getFromPage(VfxS32 idx, VfxObjList &objList)
{
    if (idx < 0 || idx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
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
            //
            // If the position of the widget is located within this page, we
            // consider it belongs to this page.
            //
            objList.append(widget);
        }
    }
}


void VappLauncherRobotDesktop::getFromAllPage(VfxObjList &objList)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        getFromPage(i, objList);
    }
}


VfxBool VappLauncherRobotDesktop::canAddToPage(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    return !searchRoom(widget, pageIndex).isEmpty();
}


VfxBool VappLauncherRobotDesktop::canAddToPageIfAny(const VappWidget *widget) const
{
    return !searchRoomIfAny(widget).isEmpty();
}


VfxRect VappLauncherRobotDesktop::searchRoom(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    VFX_ASSERT(pageIndex >= 0 && pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

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


VfxRect VappLauncherRobotDesktop::searchRoomIfAny(const VappWidget *widget) const
{
    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; pageIndex++)
    {
        VfxRect room = searchRoom(widget, pageIndex);
        if (!room.isEmpty())
        {
            return room;
        }
    }

    return VFX_RECT_ZERO;
}


VfxRect VappLauncherRobotDesktop::searchRoomIfAny(const VappWidget *widget, VfxS32 &pageId) const
{
    for (VfxS32 pageIndex = 0; pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; pageIndex++)
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


VfxRect VappLauncherRobotDesktop::searchNearest(
    const VappWidget *widget,
    VfxS32 pageIndex) const
{
    VFX_ASSERT(pageIndex >= 0 && pageIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

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


VfxS32 VappLauncherRobotDesktop::calcDistance(
    const VfxPoint &p1,
    const VfxPoint &p2) const
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


void VappLauncherRobotDesktop::initSlideSpeed()
{
    m_slideSpeed = 0;
}


void VappLauncherRobotDesktop::updateSlideSpeed(VfxPenEvent &event)
{
    VfxMsec time = vfxAbs(event.timeStamp - event.prevTimeStamp);
    VfxS32 offset = vfxAbs(event.pos.x - event.prevPos.x);

    if (time != 0)
    {
        m_slideSpeed = (offset * 1000) / time;
    }
}


VfxMsec VappLauncherRobotDesktop::clampSlideDuration(VfxMsec duration)
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


VfxS32 VappLauncherRobotDesktop::clampIndex(VfxS32 pageIndex) const
{
    if (pageIndex < 0)
    {
        return 0;
    }

    if (pageIndex >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        return VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1;
    }
    return pageIndex;
}


VfxS32 VappLauncherRobotDesktop::getCentraPageIndex()
{
    if (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM % 2 == 0)
    {
        return VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM / 2 - 1;
    }
    else
    {
        return VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM / 2;
    }
}


VfxSize VappLauncherRobotDesktop::getTileSize()
{
    return VfxSize(VAPP_LAUNCHER_ROBOT_DESKTOP_TILE_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_TILE_HEIGHT);
}


VfxSize VappLauncherRobotDesktop::getRoomSize(const VappWidget *widget)
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


VfxS32 VappLauncherRobotDesktop::getTotalRoomNum(const VfxSize &roomSize)
{
    return getPageRoomNum(roomSize) * VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
}


VfxS32 VappLauncherRobotDesktop::getPageRoomNum(const VfxSize &roomSize)
{
    return getPageHorizRoomNum(roomSize) * getPageVertiRoomNum(roomSize);
}


VfxS32 VappLauncherRobotDesktop::getPageHorizRoomNum(const VfxSize &roomSize)
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



VfxS32 VappLauncherRobotDesktop::getPageVertiRoomNum(const VfxSize &roomSize)
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


VfxS32 VappLauncherRobotDesktop::getFirstRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * pageIdx;
}


VfxS32 VappLauncherRobotDesktop::getLastRoomIndex(
    const VfxSize &roomSize,
    VfxS32 pageIdx)
{
    VfxS32 pageRoomNum = getPageRoomNum(roomSize);

    if (pageRoomNum <= 0 ||
        pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        return -1;
    }

    return pageRoomNum * (pageIdx + 1) - 1;
}


VfxRect VappLauncherRobotDesktop::getRoom(
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


VfxRect VappLauncherRobotDesktop::getRoom(
    const VfxSize &roomSize,
    VfxS32 pageIdx,
    VfxS32 x,
    VfxS32 y)
{
    VfxS32 horizRoomNum = getPageHorizRoomNum(roomSize);
    VfxS32 vertiRoomNum = getPageVertiRoomNum(roomSize);
    VfxSize tileSize = getTileSize();
    VfxPoint pos;

    if (pageIdx < 0 || pageIdx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM ||
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


VfxRect VappLauncherRobotDesktop::getRoom(const VfxSize &roomSize, VfxS32 idx)
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


VappWidget *VappLauncherRobotDesktop::getOccupiedWidget(VfxS32 pageIndex, const VfxRect &room) const
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


VappWidget *VappLauncherRobotDesktop::getOccupiedWidget(const VfxRect &room) const
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


VfxBool VappLauncherRobotDesktop::isOccupied(const VfxRect &room) const
{
    return getOccupiedWidget(room) ? VFX_TRUE : VFX_FALSE;
}


void VappLauncherRobotDesktop::setWidgetOnRoom(
    VappWidget *widget,
    const VfxRect &room) const
{
    VfxPoint pos = room.getMidPoint();

    widget->setPos(pos);
}


void VappLauncherRobotDesktop::initPageAnim(VappLauncherRobotDesktopPage *page)
{
    VFX_OBJ_ASSERT_VALID(m_transition);
    
    page->setPropertyEffectCallback(page, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
    
    // set fpe for desktop page
    VappLauncherRobotPageTransPara para;
    para.totalPage = VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    para.pageWidth = getBounds().getWidth();
    para.pageHeight = getBounds().getHeight();
    para.transitionEffect = m_transition; 

    page->setPropertyEffectCallback(
        getAnimDummyFrame(),
        VappLauncherRobotDesktop::framePropertyEffectCallback,
        &para,
        sizeof(para) );
}


vrt_render_dirty_type_enum VappLauncherRobotDesktop::framePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    const VappLauncherRobotPageTransPara *transPara = (const VappLauncherRobotPageTransPara *)user_data;

    const VfxS32 desktopWidth = transPara->pageWidth;
    //const VfxS32 desktopHeight = transPara->pageHeight;
    VappLauncherRobotPageTransition *transition = (VappLauncherRobotPageTransition *)transPara->transitionEffect;

    const vrt_s32 translate = watch_frame->pos.x;
    const vrt_s32 rawPosX = static_cast<vrt_s32>(target_frame->fpe_user_0);
    vrt_float t = vrt_float(rawPosX - translate) / desktopWidth;
    const vrt_s32 targetPosX = static_cast<vrt_s32>(target_frame->pos_z);

    if(!transition->isValid() || !transition->isKindOf(VFX_OBJ_CLASS_INFO(VappLauncherRobotPageTransition)))
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_FPE_CALLBACK, &transition, rawPosX, translate, targetPosX, 500));
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    if(t > (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        while(t > (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
        {
            t -= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
        }
    }
    else if(t < -(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        while(t < -(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
        {
            t += VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
        }
    }

    // watching frame
    // fpe_user0: current desktop bounds
    // translate: current dummy frame position
    // filter_timing: original dummy frame position
    // position z: target pos 
    vrt_float ratio;

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_FPE_CALLBACK, &transition, rawPosX, translate, targetPosX, 200));
    if( watch_frame->pos_z == watch_frame->fpe_user_0)
    {
        ratio = 0;
    }
    else
    {
        ratio = VFX_ABS(vrt_float(translate-watch_frame->fpe_user_0) / vrt_float(watch_frame->pos_z-watch_frame->fpe_user_0));
    }

#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if(t > (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        // 
        //   t:    0     1    2    3   -1 
        // page: |----|----|----|----|----|
        //
        t = t - VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
    else if(t < -(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1))
    {
        // 
        //   t:    1    -3   -2   -1    0 
        // page: |----|----|----|----|----|
        //
        t = t + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
#endif

    if (!transition->isShowAllPage() && (t <= -1.0f || t >= 1.0f))
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_FPE_CALLBACK, &transition, rawPosX, translate, targetPosX, 400));
        target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        target_frame->pos.x = -10000;
        target_frame->pos.y = -10000;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_FPE_CALLBACK, &transition, rawPosX, translate, targetPosX, 201));
    VfxS32 nexDesktopBoundsX = (VfxS32)watch_frame->pos_z % (desktopWidth*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM));
    if(nexDesktopBoundsX < 0)
    {
        nexDesktopBoundsX += desktopWidth*(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);
    }
    return transition->onTransition(
                            ratio,
                            t, 
                            target_frame->bounds.size.width, 
                            target_frame->bounds.size.height, 
                            watch_frame->fpe_user_0,
                            nexDesktopBoundsX,
                            watch_frame->pos_z-watch_frame->filter_timing,
                            target_frame);
}


void VappLauncherRobotDesktop::showDesktopPageBg(VfxBool isShow, VfxFloat bgOpacity)
{
    if(m_transition->isShowPageBgDuringSlide())
    {
        // only do fade out animation when hide bg
        VfxBool isAnimatable = !isShow;
        for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
        {
            if(i != m_currentPageIndex)
            {
                m_page[i]->showBg(isShow, bgOpacity, VFX_FALSE);
            }
            else
            {
                m_page[i]->showBg(isShow, bgOpacity, isAnimatable);
            }
        }
    }
}


void VappLauncherRobotDesktop::precachePageChildren()
{
    VfxS32 curIndex = getAnimDummyFrame()->getFpeUser0() / getBounds().size.width;
    VfxS32 nextIndex = 0;
    VfxS32 prevIndex = 0;

    if(curIndex < 0)
    {
        curIndex = curIndex % VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
        curIndex = curIndex + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
    nextIndex = (curIndex+1)%VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;

    prevIndex = curIndex-1;
    if(prevIndex<0)
    {
        prevIndex = VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(i == curIndex || i == nextIndex || i == prevIndex)
        {
            m_page[i]->preCacheChildren();
        }
    }
}


void VappLauncherRobotDesktop::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}


void VappLauncherRobotDesktop::unHideDesktopPage()
{
    VAPP_LAUNCHER_ROBOT_SLA(("HUP", SA_label));;

    m_isFreezePage = VFX_TRUE;
    VfxS32 curIndex = getAnimDummyFrame()->getFpeUser0() / getBounds().size.width;
    VfxS32 nextIndex = 0;
    VfxS32 prevIndex = 0;

    if(curIndex < 0)
    {
        curIndex = curIndex % VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
        curIndex = curIndex + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
    nextIndex = (curIndex+1)%VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;

    prevIndex = curIndex-1;
    if(prevIndex<0)
    {
        prevIndex = VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(i == curIndex || i == nextIndex || i == prevIndex)
        {
            m_page[i]->setHidden(VFX_FALSE);
        }
        else
        {
            m_page[i]->setHidden(VFX_TRUE);
        }
    }
}


void VappLauncherRobotDesktop::freezeDesktopPage(VappLauncherRobotDesktopFreezeMode mode)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HFP", SA_label));;

    m_isFreezePage = VFX_TRUE;
    VfxS32 curIndex = getAnimDummyFrame()->getFpeUser0() / getBounds().size.width;
    VfxS32 nextIndex = 0;
    VfxS32 prevIndex = 0;

    if(curIndex < 0)
    {
        curIndex = curIndex % VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
        curIndex = curIndex + VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;
    }
    nextIndex = (curIndex+1)%VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM;

    prevIndex = curIndex-1;
    if(prevIndex<0)
    {
        prevIndex = VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM-1;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        // freeze may happen during fade out/in animation,
        // then it will freeze the wrong snapshot,
        // so set the opacity directly before freeze
        m_page[i]->forceSetContentOpacity(1.0);
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        if(mode == FREEZE_FOR_SLIDE)
        {
        #if !defined(VAPP_LAUNCHER_ROBOT_SLIDE_ONLY_TWO_PAGE_AT_A_TIME)
            // cache the current/next/prev page to improve the fps of current slide
            if(i == curIndex || i == nextIndex || i == prevIndex)
            {
                m_page[i]->setCacheMode(VFX_CACHE_MODE_FREEZE);
            }
            else
            {
                m_page[i]->setCacheMode(VFX_CACHE_MODE_AUTO);
                m_page[i]->setHidden(VFX_TRUE);
            }
        #else
            VfxS32 cacheIndex;
            if(m_slideDirection >= 0)
            {
                cacheIndex = nextIndex;
            }
            else
            {
                cacheIndex = prevIndex;
            }
            // cache the current/next/prev page to improve the fps of current slide
            if(i == curIndex || i == cacheIndex)
            {
                m_page[i]->setCacheMode(VFX_CACHE_MODE_FREEZE);
            }
            else
            {
                m_page[i]->setCacheMode(VFX_CACHE_MODE_AUTO);
                m_page[i]->setHidden(VFX_TRUE);
            }
        #endif
        }
        else if(mode == FREEZE_ALL)
        {
            // cache all page for multiple page transition
            m_page[i]->setCacheMode(VFX_CACHE_MODE_FREEZE);
            m_page[i]->setHidden(VFX_FALSE);
        }
        else
        {
            // no use
        }
    }
}


void VappLauncherRobotDesktop::unfreezeDesktopPage()
{
    if(m_isFreezePage)
    {
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
        {
            m_page[i]->setCacheMode(VFX_CACHE_MODE_AUTO);
        }
        m_isFreezePage = VFX_FALSE;
    }
}


void VappLauncherRobotDesktop::unfreezeCurrentDesktopPage()
{
    VfxS32 curIndex = getAnimDummyFrame()->getFpeUser0() / getBounds().size.width;
    m_page[curIndex]->setCacheMode(VFX_CACHE_MODE_AUTO);
    m_page[curIndex]->setHidden(VFX_FALSE);
}


void VappLauncherRobotDesktop::onSlideFantasyEffectCallback(VfxTimer *timer)
{
    m_timerPrecachePageChildren->stop();

    setupTransitionEffect(m_transitionZoomOutType);
    slideWithFantasticEffect(m_quickSwipeDirection);
}
    

void VappLauncherRobotDesktop::onPrecachePageChildrenCallback(VfxTimer *timer)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HPC", SA_label));;
    unfreezeDesktopPage();
    precachePageChildren();
}


void VappLauncherRobotDesktop::onUnFreezeTimerCallback(VfxTimer *timer)
{
    unfreezeDesktopPage();
}


void VappLauncherRobotDesktop::updateTransitionEffect(VappRobotPageTransitionTypeEnum &zoomInType, VappRobotPageTransitionTypeEnum &zoomOutType)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HUT", SA_start));
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_UPDATE_TRANSITION_EFFECT,200));
    
#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)
    VappRobotPageTransitionTypeEnum realZoomInValue;
    VappRobotPageTransitionTypeEnum realZoomOutValue;

    VappLauncherRobotPageTransitionSettingPopup::getPageTransitionEffectType(realZoomInValue,realZoomOutValue);
    VFX_ASSERT(realZoomInValue != VAPP_PAGE_TRANSITION_INVALID);
    
    if(zoomInType != realZoomInValue)
    {
        zoomInType = realZoomInValue;
        zoomOutType = realZoomOutValue;
        setupTransitionEffect(zoomInType);
    }
#else
    zoomInType = VAPP_PAGE_TRANSITION_TYPE_NORMAL;
    zoomOutType = VAPP_PAGE_TRANSITION_TYPE_NORMAL;
    setupTransitionEffect(zoomInType);
#endif
    VAPP_LAUNCHER_ROBOT_SLA(("HUT", SA_stop));
}


void VappLauncherRobotDesktop::setupTransitionEffect(VappRobotPageTransitionTypeEnum transitionType)
{
    if(m_transitionType == transitionType)
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_SETUP_TRANSITION_EFFECT,500));
        return;
    }
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_SETUP_TRANSITION_EFFECT,200));
    m_transitionType = transitionType;
    createTransitionEffect(transitionType);
    
    setIsZSortChild(VFX_TRUE);
    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_page[i]->setQuality(VFX_RENDER_QUALITY_HIGH);
        initPageAnim(m_page[i]);
        m_page[i]->setCullingType(m_transition->getCullingType());
    }   
}


void VappLauncherRobotDesktop::createTransitionEffect(VappRobotPageTransitionTypeEnum transitionType)
{
    VFX_OBJ_CLOSE(m_transition);
    
    VappLauncherRobotPageTransitionFactory *factory = VFX_OBJ_GET_INSTANCE(VappLauncherRobotPageTransitionFactory);
    m_transition = factory->createPageTransition(transitionType,this); 
    m_transition->onInitTransition(getSize().width, getSize().height, VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

#if defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
    VfxRect oriRect = VfxRect(0,0,VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_ORI_HEIGHT);
    VfxRect resizeRect = VfxRect(0,0,VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_WIDTH, VAPP_LAUNCHER_ROBOT_DESKTOP_PAGE_RESIZE_HEIGHT);
    m_transition->onInitTransitionForSlim(oriRect, resizeRect);
#endif

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DESKTOP_CREATE_TRANSITION_EFFECT, &m_transition, 200));
}


void VappLauncherRobotDesktop::releaseTransitionEffect()
{
    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_page[i]->setPropertyEffectCallback(m_page[i], NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
        
    }   

    VFX_OBJ_CLOSE(m_transition);
}


void VappLauncherRobotDesktop::setDesktopPageUnhittable(VfxBool isUnhittable)
{
    for(VfxS32 i=0; i<VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        m_page[i]->setIsUnhittable(isUnhittable);
    }
}


#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE)
void VappLauncherRobotDesktop::setDebugText(
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
        m_debugPanel->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_ROBOT_SNAPSHOT_BG));
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
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE) */


#if defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE)
void VappLauncherRobotDesktop::setAutoSlideHint(VfxS32 location)
{
    VfxFrame *parent = getParentFrame();

    if (!m_autoSlideHint)
    {
        VFX_OBJ_CREATE(m_autoSlideHint, VfxFrame, this);
        parent->addChildFrame(m_autoSlideHint);

        m_autoSlideHint->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_ROBOT_SNAPSHOT_BG));
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
#endif /* defined(VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE) */

