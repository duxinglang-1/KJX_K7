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
 *  vapp_desktop_director.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the desktop director.
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

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"
#include "vapp_app_widget.h"
#include "vapp_app_widget_kit.h"
#include "vapp_app_widget_archive.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_page_selector.h"
#include "vapp_desktop_shortcut_selector.h"
#include "vapp_desktop_widget_selector.h"
#include "vapp_desktop_director.h"
#include "vapp_desktop_gprot.h"
#include "mmi_rp_vapp_desktop_def.h"

//
// Wallpaper:
//
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_cfg.h"

//
// C headers
//
extern "C"
{
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "IdleGprot.h"
#include "PhoneSetupGprots.h"
#include "SimSpaceGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "app_mem.h"
#include "AppMgrSrvGprot.h"

#if defined(VAPP_DESKTOP_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}


static mmi_ret vapp_desktop_handle_appmgr_uninstall_package(mmi_event_struct *event)
{
    MMI_ASSERT(event);

    //
    // FTE launcher and key launcher will be switchable dynamically from w12.09
    // so FTE launcher may not be initialized so that the NVRAM record is not initialized
    // so if FTE launcher is not initialed, skip this handling.
    //
    if (VappAppWidgetArchiveUtil::isNewVersion())
    {
        return MMI_RET_OK;
    }

    srv_appmgr_update_event_struct *evt = (srv_appmgr_update_event_struct *)event;

    //
    //  Read widget NVRAM info and find the uninstall widget, then
    //  set id to invalid. Accordingly, the shorcut will not be 
    //  created when back to HS
    //
    VappAppWidgetArchiveIterator *iterR;
    VFX_OBJ_CREATE(iterR,VappAppWidgetArchiveIterator, VFX_SYS_GLOBAL_CONTEXT);

    // read arichive file fail or there is no widget installed in HS
    VfxS32 totalNumWidget;
    if (!iterR->readFirst(totalNumWidget) || totalNumWidget == 0)
    {
        VFX_OBJ_CLOSE(iterR);
        return MMI_RET_OK;
        
    }

    VappAppWidgetArchiveIterator *iterW;
    VFX_OBJ_CREATE(iterW,VappAppWidgetArchiveIterator, VFX_SYS_GLOBAL_CONTEXT);
    
    // check if archive file is created successfully
    if (!iterW->writeFirst(totalNumWidget))
    {
        VFX_OBJ_CLOSE(iterW);
        return MMI_RET_OK;
    }

    //
    // start to read/write widget info after check if archive file is created successfully
    //
    
    // read archived widget infomation
    VappAppWidgetId **idArray;
    VfxPoint **posArray;
    VFX_SYS_ALLOC_MEM(idArray, totalNumWidget * sizeof(VappAppWidgetId *));
    VFX_SYS_ALLOC_MEM(posArray, totalNumWidget * sizeof(VfxPoint *));

    for (VfxS32 i = 0; i < totalNumWidget; i++)
    {
        VFX_SYS_NEW(idArray[i], VappAppWidgetId);
        VFX_SYS_NEW(posArray[i], VfxPoint);
    }

    VfxS32 index = 0;
    for (VfxBool isSuccess = iterR->readNext(*(idArray[index]), *(posArray[index]));
         isSuccess == VFX_TRUE;
         isSuccess = iterR->readNext(*(idArray[index]), *(posArray[index])))
    {
        // check if created widget is uninstalled then set it invalid
        if(idArray[index]->getSource() == VAPP_APP_WIDGET_SRC_SHORTCUT &&
           strcmp(idArray[index]->getStringType(), evt->app_name) == 0)
        {
            idArray[index]->assignWith(VAPP_APP_WIDGET_SRC_INVALID,0);
        }
        index++;
    }
    VFX_OBJ_CLOSE(iterR);

    //
    //  write widget NVRAM info back
    //
    for(VfxS32 i=0; i<totalNumWidget; i++)
    {
        iterW->writeNext(*(idArray[i]), *(posArray[i]));
    }

    VFX_OBJ_CLOSE(iterW);

    for (VfxS32 i = 0; i < totalNumWidget; i++)
    {
        VFX_SYS_DELETE(idArray[i]);
        VFX_SYS_DELETE(posArray[i]);
    }

    VFX_SYS_FREE_MEM(idArray);
    VFX_SYS_FREE_MEM(posArray);

    return MMI_RET_OK;
}


extern "C" mmi_ret vapp_desktop_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
            ret = vapp_desktop_handle_appmgr_uninstall_package(event);
            break;
            
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * Desktop Director
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopDirector", VappDesktopDirector, VfxAppCatScr);

VfxBool VappDesktopDirector::s_isHistoryValid = VFX_FALSE;
VfxBool VappDesktopDirector::s_isInEditMode = VFX_FALSE;
VfxS32 VappDesktopDirector::s_pageIndex = 0;

VappAppWidgetId VappDesktopDirector::s_selectedWidgetId;

const VfxFloat VappDesktopDirector::s_dndScaleRatio = 0.8f;
const VfxFloat VappDesktopDirector::s_dndOpacity = 0.7f;
const VfxColor VappDesktopDirector::s_alertFilterMin(0, 128, 0, 0);    // ARGB
const VfxColor VappDesktopDirector::s_alertFilterMax(255, 255, 0, 0);  // ARGB


VappDesktopDirector::VappDesktopDirector() :
    m_wallpaper(NULL),
    m_timer2ndPassLoader(NULL),
    m_timerResumeWallpaper(NULL),
    m_desktop(NULL),
    m_timerAutoSlidePage(NULL),
    m_isCaptured(VFX_FALSE),
    m_isCapturedFromOthers(VFX_FALSE),
    m_isSuspendWallpaperForSwipe(VFX_FALSE),
    m_cannotSwipeRequest(),
    m_cannotSwipeList(),
    m_indicator(NULL),
    m_shortcutBar(NULL),
    m_toolbar(NULL),
    m_statusIconBar(NULL),
    m_isInEditMode(VFX_FALSE),
    m_pageSelector(NULL),
    m_pageSelectorOos(NULL),
    m_pageSelectorDnd(NULL),
    m_timerLaunchPageSelectorDnd(NULL),
    m_shortcutSelector(NULL),
    m_widgetSelector(NULL),
    m_selectedWidget(NULL),
    m_dndWidget(NULL),
    m_alertFilter(NULL),
    m_penOffset(VFX_POINT_ZERO),
    m_timerWidgetFly(NULL),
    m_widgetList()
{
    setVrtCacheLimitSize(1800000);
}


void VappDesktopDirector::onInit()
{
    VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_INIT, 100));

    VAPP_DESKTOP_SLA(("HI0", SA_start));

    VfxAppCatScr::onInit();

    //
    // UI components
    //
    createWallpaper(WALLPAPER_CREATE_DELAY_TIME);

    createPage();

    createStatusIconBar();

    createPageIndicator();

    createShortcutBar();

    createToolbar();

    createWidget();

    //
    // 2nd pass creation.
    //
    if (getIsSnapshotDrawing())
    {
        on2ndPassLoader(NULL);
    }
    else
    {
        create2ndPassLoader();
    }

    //
    // Restore the history settings. No animation is needed here.
    //
    if (s_isHistoryValid)
    {
        toggleEditMode(s_isInEditMode);
        m_desktop->slideTo(s_pageIndex);
    }

    VAPP_DESKTOP_SLA(("HI0", SA_stop));

    VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_INIT, 200));
}


void VappDesktopDirector::onAfterInit()
{
    VAPP_DESKTOP_SLA(("HI1", SA_start));

    VfxAppCatScr::onAfterInit();


    VAPP_DESKTOP_SLA(("HI1", SA_stop));
}


void VappDesktopDirector::onBeforeDeinit()
{
    VAPP_DESKTOP_SLA(("HD0", SA_start));

    //
    // Serialize the history settings.
    //
    s_isHistoryValid = VFX_TRUE;
    s_isInEditMode = m_isInEditMode;
    s_pageIndex = m_desktop->getCurrentPageIndex();

    VfxAppCatScr::onBeforeDeinit();

    VAPP_DESKTOP_SLA(("HD0", SA_stop));
}


void VappDesktopDirector::onDeinit()
{
    VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_DEINIT, 100));

    VAPP_DESKTOP_SLA(("HD1", SA_start));

    //
    // 2nd Pass creation.
    //
    release2ndPassLoader();

    //
    // UI components
    //
    releaseWidget();

    releaseToolbar();

    releaseShortcutBar();

    releasePageIndicator();

    releaseStatusIconBar();

    releasePage();

    releaseWallpaper();

    VfxAppCatScr::onDeinit();

    VAPP_DESKTOP_SLA(("HD1", SA_stop));

    VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_DEINIT, 200));
}


void VappDesktopDirector::onAfterDeinit()
{
    VAPP_DESKTOP_SLA(("HD2", SA_start));

    VfxAppCatScr::onAfterDeinit();

    VAPP_DESKTOP_SLA(("HD2", SA_stop));
}


void VappDesktopDirector::onExit(VfxBool isBackward)
{
    // it is for video wallpaper
    // video wallpaper is allow to snapshot when it is suspended
    m_wallpaper->suspend();
}


VfxBool VappDesktopDirector::onKeyInput(VfxKeyEvent &event)
{
    //
    // Go Back.
    //
    if (event.keyCode == VFX_KEY_CODE_RSK)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_isInEditMode)
            {
                toggleEditMode(VFX_FALSE);
            }

            return VFX_TRUE;
        }
    }

    //
    // Standby.
    //
    else if (event.keyCode == VFX_KEY_CODE_END)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_isInEditMode)
            {
                toggleEditMode(VFX_FALSE);
                return VFX_TRUE;
            }

            m_desktop->slideToCentra();

            return VFX_TRUE;
        }
    }

    //
    // Previous Page.
    //
    else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
            event.type == VFX_KEY_EVENT_TYPE_REPEAT)
        {
            m_desktop->slideToPrevious();
            return VFX_TRUE;
        }
    }

    //
    // Next Page.
    //
    else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
            event.type == VFX_KEY_EVENT_TYPE_REPEAT)
        {
            m_desktop->slideToNext();
            return VFX_TRUE;
        }
    }

#if (MMI_MAX_SIM_NUM >= 3)
    //
    // SIM space.
    //
    else if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            mmi_sim_space_launch();
            return VFX_TRUE;
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    return VfxAppCatScr::onKeyInput(event);
}


VfxBool VappDesktopDirector::onPreviewPenInput(VfxPenEvent &event)
{
    //
    // If some widget is during the dropping animation, drop it immediately such
    // that the state of the widget DnD mechanism can be reset.
    //
    if (m_timerWidgetFly && m_timerWidgetFly->getIsEnabled())
    {
        m_timerWidgetFly->m_signalTick.emit(m_timerWidgetFly);
        m_timerWidgetFly->stop();
    }

    //
    // Preview pen event to capture the pen control if we should swipe the
    // desktop.
    //
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:

            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:

            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));

            //
            // If the horizontal pen-move is large enough, capture the pen
            // event.
            //
            if (!m_isCaptured &&
                !isSwipeForbidden() &&
                !isFrameCannotSwipe(event.relObjList) &&
                calcDistance(event.downPos, event.pos) > SLIDE_START_OFFSET &&
                isHorizontalPenMove(event))
            {
                VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_CAPTURE));

                if (capturePenEvent(event.target))
                {
                    return VFX_TRUE;
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:

            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'L', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_UP:

            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'U', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_ABORT:

            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'A', event.pos.x, event.pos.y));

            break;

        default:
            break;
    }

    return VfxAppCatScr::onPreviewPenInput(event);
}


VfxBool VappDesktopDirector::onPenInput(VfxPenEvent &event)
{
    if (!m_isCaptured && event.type != VFX_PEN_EVENT_TYPE_DOWN)
    {
        VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                       '-', event.pos.x, event.pos.y));

        return VfxAppCatScr::onPenInput(event);
    }

    //
    // Notify the desktop that a pen event comes.
    //
    m_desktop->doPenInput(event);

    //
    // Notify the wallpaper that a pen event comes. Wallpaper might show heavy
    // animation for this pen input. For performance, we only notify the
    // wallpaper when this pen event is directly comes from this page director,
    // rather than captured other UI component, e.g., widgets.
    //
    if (!m_isCapturedFromOthers)
    {
        m_wallpaper->doPenInput(event);
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

            m_isCaptured = VFX_TRUE;

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));

            if (!m_isSuspendWallpaperForSwipe 
                && m_wallpaper->isAllowSuspendOnSwipe())
            {
                m_isSuspendWallpaperForSwipe = VFX_TRUE;

                m_wallpaper->suspend();
            }

            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                           'L', event.pos.x, event.pos.y));

            if (calcDistance(event.downPos, event.pos) <= SLIDE_START_OFFSET)
            {
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

                if (!m_isInEditMode)
                {
                    toggleEditMode(VFX_TRUE);
                }
                else
                {
                    toggleEditMode(VFX_FALSE);
                }
            }

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:

            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                                  'U', event.pos.x, event.pos.y));
            }
            else
            {
                VAPP_DESKTOP_LOG((TRC_VAPP_DESKTOP_DIRECTOR_ON_PEN_INPUT,
                                  'A', event.pos.x, event.pos.y));
            }

            if (m_isSuspendWallpaperForSwipe)
            {
                m_isSuspendWallpaperForSwipe = VFX_FALSE;

                delayResumeWallpaper(WALLPAPER_SWIPE_DELAY_TIME);
            }

            m_isCaptured = VFX_FALSE;
            m_isCapturedFromOthers = VFX_FALSE;

            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappDesktopDirector::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_INIT:
        {
            onAfterInit();
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT:
        {
            onAfterDeinit();
            return;
        }
        default:
        {
            VfxAppCatScr::onObjectNotify(id, userData);
            return;
        }
    }
}


VfxBool VappDesktopDirector::capturePenEvent(const VfxObject *target)
{
    m_isCaptured = VFX_TRUE;
    m_isCapturedFromOthers = VFX_TRUE;

    if (target != m_desktop && capture())
    {
        return VFX_TRUE;
    }
    else
    {
        m_isCaptured = VFX_FALSE;
        m_isCapturedFromOthers = VFX_FALSE;

        return VFX_FALSE;
    }
}


void VappDesktopDirector::create2ndPassLoader()
{
    //
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    //
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappDesktopDirector::on2ndPassLoader);

    //
    // Start timer.
    //
    m_timer2ndPassLoader->start();
}


void VappDesktopDirector::release2ndPassLoader()
{
    if (m_timer2ndPassLoader && m_timer2ndPassLoader->getIsEnabled())
    {
        m_timer2ndPassLoader->stop();

        //
        // Foribly load all UI components if the 2nd pass loader has not run
        // until the home exits.
        //
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        on2ndPassLoader(m_timer2ndPassLoader);

        VfxAutoAnimate::commit();
    }

    VFX_OBJ_CLOSE(m_timer2ndPassLoader);
}


void VappDesktopDirector::on2ndPassLoader(VfxTimer *timer)
{
    VAPP_DESKTOP_SLA(("HI2", SA_start));

    m_widgetList.removeAllInvalidate();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

        if (widget)
        {
            activateWidget(widget);
        }
    }

    VfxAutoAnimate::commit();

    //
    // Create the selected widget if it is present.
    //
    if (!getIsSnapshotDrawing() &&
        s_selectedWidgetId.getSource() != VAPP_APP_WIDGET_SRC_INVALID)
    {
        vfxPostInvoke0(this, &VappDesktopDirector::layoutWidget);
    }

    VAPP_DESKTOP_SLA(("HI2", SA_stop));
}


void VappDesktopDirector::createWallpaper(VfxMsec delayTime)
{
    VFX_ASSERT(!m_wallpaper && !m_timerResumeWallpaper);

    //
    // Create the wallpaper.
    //
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_HOMESCREEN, VAPP_DESKTOP_MAX_PAGE_NUM);

    //
    // For performance, suspend it first. Resume the wallpaper according to the
    // 'delayTime'.
    //
    //   = 0: resume it immediately
    //   > 0: resume it after the specified msec.
    //   < 0: do not resume it now.
    //
    m_wallpaper->suspend();

    if (delayTime >= 0)
    {
        delayResumeWallpaper(delayTime);
    }
}


void VappDesktopDirector::releaseWallpaper()
{
    // Release objects.
    VFX_OBJ_CLOSE(m_wallpaper);
    VFX_OBJ_CLOSE(m_timerResumeWallpaper);
}


void VappDesktopDirector::delayResumeWallpaper(VfxMsec delayTime)
{
    // If wallpaper is not present, this function does nothing.
    if (!m_wallpaper)
    {
        return;
    }

    // Lazy creation the timer when it is needed.
    if (!m_timerResumeWallpaper)
    {
        VFX_OBJ_CREATE(m_timerResumeWallpaper, VfxTimer, this);
    }

    // If timer is already ongoing, fire it immediately.
    if (m_timerResumeWallpaper->getIsEnabled())
    {
        m_wallpaper->resume();
        m_timerResumeWallpaper->stop();
    }

    // Prepare for the next run. If delayTime is 0, resume it right now.
    if (delayTime == 0)
    {
        m_wallpaper->resume();
    }
    else if (delayTime > 0)
    {
        m_timerResumeWallpaper->setStartDelay(delayTime);
        m_timerResumeWallpaper->m_signalTick.connect(this, &VappDesktopDirector::onResumeWallpaper);
        m_timerResumeWallpaper->start();
    }
}


void VappDesktopDirector::onResumeWallpaper(VfxTimer *timer)
{
    if (m_wallpaper)
    {
        m_wallpaper->resume();
    }
}


void VappDesktopDirector::createPage()
{
    VFX_ASSERT(!m_desktop && !m_timerAutoSlidePage);

    VFX_OBJ_CREATE(m_desktop, VappDesktopPage, this);
    m_desktop->m_signalPageChanged.connect(this, &VappDesktopDirector::onDesktopPageChanged);
    m_desktop->m_signalBoundsChanged.connect(this, &VappDesktopDirector::onDesktopBoundsChanged);

    // Centralize the desktop.
    m_desktop->slideToCentra();

    // Timer to do auto. sliding when the widget is dragged to the left or right
    // side of the desktop.
    VFX_OBJ_CREATE(m_timerAutoSlidePage, VfxTimer, this);
    m_timerAutoSlidePage->setStartDelay(DND_PAGE_SWITCH_START_DELAY);
    m_timerAutoSlidePage->setDuration(DND_PAGE_SWITCH_NEXT_DELAY);
    m_timerAutoSlidePage->m_signalTick.connect(this, &VappDesktopDirector::onAutoSlidePage);
}


void VappDesktopDirector::releasePage()
{
    VFX_OBJ_CLOSE(m_desktop);
    VFX_OBJ_CLOSE(m_timerAutoSlidePage);
}


void VappDesktopDirector::forbidSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.append(requester);
    }
}


void VappDesktopDirector::permitSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.removeOne(requester);
    }
}


VfxBool VappDesktopDirector::isSwipeForbidden()
{
    // Requester might be closed. Remove invalid requesters first.
    m_cannotSwipeRequest.removeAllInvalidate();

    return m_cannotSwipeRequest.isEmpty() ? VFX_FALSE : VFX_TRUE;
}


void VappDesktopDirector::addFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.append(frame);
    }
}


void VappDesktopDirector::removeFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.removeOne(frame);
    }
}


VfxBool VappDesktopDirector::isFrameCannotSwipe(VfxFrame *frame)
{
    // Forbidden frame might be closed. Remove invalid frames first.
    m_cannotSwipeList.removeAllInvalidate();

    if (frame)
    {
        for (VfxObjListEntry *entry = m_cannotSwipeList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VfxFrame *parent = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

            if (parent && isChildFrame(parent, frame))
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}


VfxBool VappDesktopDirector::isFrameCannotSwipe(VfxObjList &frameList)
{
    for (VfxObjListEntry *entry = frameList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(entry->get(), VfxFrame);

        if (frame && isFrameCannotSwipe(frame))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxBool VappDesktopDirector::isChildFrame(
    const VfxFrame *parent,
    const VfxFrame *child) const
{
    for (VfxFrame *frame = child->getParentFrame();
         frame != NULL;
         frame = frame->getParentFrame())
    {
        if (frame == parent)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


void VappDesktopDirector::onDesktopPageChanged(VappDesktopPage *desktop)
{
    VFX_ASSERT(m_desktop && m_desktop == desktop);

    // Notify menu bar that the current page index is changed.
    if (m_indicator)
    {
        m_indicator->setIndex(m_desktop->getCurrentPageIndex());
    }
}


void VappDesktopDirector::onDesktopBoundsChanged(
    VfxFrame *frame,
    const VfxRect &oldBounds)
{
    VFX_ASSERT(m_desktop && m_desktop == frame);

    // Notify wallpaper that desktop is moved.
    if (m_wallpaper)
    {
        m_wallpaper->setDesktopBoundsChanged(VAPP_DESKTOP_MAX_PAGE_NUM, frame, oldBounds);
    }
}


void VappDesktopDirector::onAutoSlidePage(VfxTimer *timer)
{
    if (!m_dndWidget)
    {
        return;
    }

    VFX_ASSERT(m_desktop);

    // Get the pen point on the screen.
    VfxPoint pos = m_dndWidget->getPos();

    pos.x += m_penOffset.x;
    pos.y += m_penOffset.y;

    // Convert the point to the desktop.
    pos = convertPointTo(pos, m_desktop);

    //
    // Calculate if the point is located in the area to auto. slide desktop.
    //
    VfxS32 direction = m_desktop->getAutoSlideDirection(pos);

    if (direction > 0)
    {
        m_desktop->slideToNext();
    }
    else if (direction < 0)
    {
        m_desktop->slideToPrevious();
    }

    //
    // If the page cannot contain this widget, alert the widget.
    //
    if (!m_desktop->canAddToPage(m_dndWidget, m_desktop->getCurrentPageIndex()))
    {
        setWidgetAlertEffect(m_dndWidget, VFX_TRUE);
    }
    else
    {
        setWidgetAlertEffect(m_dndWidget, VFX_FALSE);
    }

    //
    // Stop timer when the desktop has slided to the left-most or right-most
    // pages.
    //
    VfxS32 idx = m_desktop->getCurrentPageIndex();

    if (idx <= 0 || idx >= VAPP_DESKTOP_MAX_PAGE_NUM - 1)
    {
        timer->stop();
    }
}


void VappDesktopDirector::createPageIndicator()
{
    VFX_ASSERT(!m_indicator);

    VFX_OBJ_CREATE(m_indicator, VappDesktopPageIndicator, this);
    m_indicator->m_signalClicked.connect(this, &VappDesktopDirector::onIndicatorClicked);

    //
    // Put page indicator below the status icon bar.
    //
    VFX_ASSERT(m_statusIconBar);

    VfxPoint pos = m_indicator->getPos();

    pos.y += m_statusIconBar->getBounds().getHeight();

    m_indicator->setPos(pos);

    //
    // Set the current page index on the deskop.
    //
    VFX_ASSERT(m_desktop);
    m_indicator->setIndex(m_desktop->getCurrentPageIndex());
}


void VappDesktopDirector::releasePageIndicator()
{
    VFX_OBJ_CLOSE(m_indicator);
}


void VappDesktopDirector::onIndicatorClicked(VappDesktopPageIndicator *indicator)
{
    VFX_ASSERT(indicator && m_indicator == indicator);

    launchPageSelector();
}


void VappDesktopDirector::createShortcutBar()
{
    VFX_ASSERT(!m_shortcutBar);

    VFX_OBJ_CREATE(m_shortcutBar, VappDesktopShortcutBar, this);

    // Forbid the desktop swipping if the pen event is on the shortcut bar.
    addFrameCannotSwipe(m_shortcutBar);
}


void VappDesktopDirector::releaseShortcutBar()
{
    VFX_OBJ_CLOSE(m_shortcutBar);
}


void VappDesktopDirector::createToolbar()
{
    VFX_ASSERT(!m_toolbar);

    VFX_OBJ_CREATE(m_toolbar, VappDesktopToolbar, this);
    m_toolbar->fold();
    m_toolbar->m_signalExecute.connect(this, &VappDesktopDirector::onToolbarExecute);

    // Forbid the desktop swipping if the pen event is on the toolbar.
    addFrameCannotSwipe(m_toolbar);
}


void VappDesktopDirector::releaseToolbar()
{
    VFX_OBJ_CLOSE(m_toolbar);
}


void VappDesktopDirector::onToolbarExecute(
    VappDesktopToolbar *toolbar,
    VappDesktopToolbar::ButtonEnum button)
{
    VFX_ASSERT(toolbar && toolbar == m_toolbar);

    switch (button)
    {
        case VappDesktopToolbar::BUTTON_ADD_WIDGET:
            vapp_desktop_launch_widget_selector(onWidgetSelected);
            break;

        case VappDesktopToolbar::BUTTON_ADD_SHORTCUT:
            vapp_desktop_launch_shortcut_selector(onWidgetSelected);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappDesktopDirector::createStatusIconBar()
{
    VFX_ASSERT(!m_statusIconBar);

    VFX_OBJ_CREATE(m_statusIconBar, VcpStatusIconBar, this);
    m_statusIconBar->enableBackground(VFX_FALSE);
    m_statusIconBar->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
}


void VappDesktopDirector::releaseStatusIconBar()
{
    VFX_OBJ_CLOSE(m_statusIconBar);
}


void VappDesktopDirector::toggleEditMode(VfxBool isOn, VfxBool isAnimatable)
{
    if (isOn && !m_isInEditMode)
    {
        setWidgetEditMode(VFX_TRUE);

        m_shortcutBar->fold(VFX_FALSE);
        m_toolbar->unfold(isAnimatable);
        m_wallpaper->suspend();

        m_isInEditMode = VFX_TRUE;
    }
    else if (!isOn && m_isInEditMode)
    {
        setWidgetEditMode(VFX_FALSE);

        m_shortcutBar->unfold(isAnimatable);
        m_toolbar->fold(VFX_FALSE);
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);

        m_isInEditMode = VFX_FALSE;
    }
}


void VappDesktopDirector::launchPageSelector()
{
    VAPP_DESKTOP_SLA(("HP0", SA_start));

    //
    // Fold or suspend other UI component to speed-up the animation.
    //
    m_wallpaper->suspend();
    setBarFolding(VFX_TRUE);
    setWidgetSlim(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelector == NULL);
    m_pageSelector = createPageSelector();

    m_pageSelector->m_signalAssembled.connect(this, &VappDesktopDirector::onPageSelectorAssembled);
    m_pageSelector->m_signalSelected.connect(this, &VappDesktopDirector::onPageSelectorSelected);
    m_pageSelector->m_signalAborted.connect(this, &VappDesktopDirector::onPageSelectorAborted);
    m_pageSelector->m_signalDismissed.connect(this, &VappDesktopDirector::onPageSelectorDismissed);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelector->assemble();
    VfxAutoAnimate::initAnimateEnd();

    VAPP_DESKTOP_SLA(("HP0", SA_stop));
}


void VappDesktopDirector::onPageSelectorAssembled(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Assembling completes. Resume the heavy UI components.
    //

    // At present, keep heavy UI component, e.g. wallpaper, stopped because the
    // performance is still not good enough.
}


void VappDesktopDirector::onPageSelectorSelected(
    VappDesktopPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);
    VFX_ASSERT(idx >= 0 && idx < VAPP_DESKTOP_MAX_PAGE_NUM);

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Selection is done.
    //
    setBarFolding(VFX_FALSE);
    m_desktop->slideTo(idx, 0);

    pageSelector->setFocusSnapshot(idx);
    pageSelector->dismiss();
}


void VappDesktopDirector::onPageSelectorAborted(
    VappDesktopPageSelector *pageSelector,
    VappDesktopPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappDesktopPageSelector::ABORT_CAUSE_HOME_KEY &&
        m_isInEditMode)
    {
        toggleEditMode(VFX_FALSE, VFX_FALSE);
    }

    //
    // Go back to previous focused page.
    //
    VfxS32 idx = pageSelector->getFocusSnapshot();

    onPageSelectorSelected(pageSelector, idx);
}


void VappDesktopDirector::onPageSelectorDismissed(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Close the page selector.
    //
    closePageSelector(pageSelector);
    m_pageSelector = NULL;

    //
    // Dismissing completes. Resume the heavy UI components.
    //
    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    setWidgetSlim(VFX_FALSE);
}


void VappDesktopDirector::launchPageSelectorOos(VappAppWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        if (m_desktop->canAddToPage(widget, i))
        {
            m_isPageFull[i] = VFX_FALSE;
        }
        else
        {
            m_isPageFull[i] = VFX_TRUE;
        }
    }

    //
    // Fold or suspend other UI component to speed-up the animation.
    //
    m_wallpaper->suspend();
    setBarFolding(VFX_TRUE);
    setWidgetSlim(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelectorOos == NULL);
    m_pageSelectorOos = createPageSelector();

    m_pageSelectorOos->m_signalAssembled.connect(this, &VappDesktopDirector::onPageSelectorOosAssembled);
    m_pageSelectorOos->m_signalSelected.connect(this, &VappDesktopDirector::onPageSelectorOosSelected);
    m_pageSelectorOos->m_signalAborted.connect(this, &VappDesktopDirector::onPageSelectorOosAborted);
    m_pageSelectorOos->m_signalDismissed.connect(this, &VappDesktopDirector::onPageSelectorOosDismissed);

    m_pageSelectorOos->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorOos->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappDesktopDirector::onPageSelectorOosAssembled(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        if (m_isPageFull[i])
        {
            m_pageSelectorOos->setSnapshotAlert(i, VFX_TRUE);
        }
    }

    //
    // Assembling completes. Resume the heavy UI components.
    //

    // At present, keep heavy UI component, e.g. wallpaper, stopped because the
    // performance is still not good enough.
}


void VappDesktopDirector::onPageSelectorOosSelected(
    VappDesktopPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);
    VFX_ASSERT(idx >= 0 && idx < VAPP_DESKTOP_MAX_PAGE_NUM);

    //
    // If the user taps a page without available spaces for this widget, display
    // an error popup.
    //
    if (m_isPageFull[idx])
    {
        PopupContext *context;

        VFX_ALLOC_MEM(context, sizeof(PopupContext), this);
        context->stringId = STR_ID_VAPP_DESKTOP_PAGE_UNAVAILABLE;
        context->type = MMI_EVENT_INFO;

        vfxPostInvoke1(this, &VappDesktopDirector::displayErrorPopup, context);

        return;
    }

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Selection is done.
    //
    setBarFolding(VFX_FALSE);
    m_desktop->slideTo(idx, 0);

    pageSelector->disableSnapshotAlert();
    pageSelector->setFocusSnapshot(idx);
    pageSelector->dismiss();
}


void VappDesktopDirector::onPageSelectorOosAborted(
    VappDesktopPageSelector *pageSelector,
    VappDesktopPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    //
    // Operation aborted. Close the widget.
    //
    VappAppWidget *widget = (VappAppWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    VFX_OBJ_CLOSE(widget);

    pageSelector->setId(VFX_ID_NULL);

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappDesktopPageSelector::ABORT_CAUSE_HOME_KEY &&
        m_isInEditMode)
    {
        toggleEditMode(VFX_FALSE, VFX_FALSE);
    }

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Abort the selection. Go back to the previous focused page.
    //
    VfxS32 idx = pageSelector->getFocusSnapshot();

    setBarFolding(VFX_FALSE);
    m_desktop->slideTo(idx, 0);

    pageSelector->disableSnapshotAlert();
    pageSelector->setFocusSnapshot(idx);
    pageSelector->dismiss();
}


void VappDesktopDirector::onPageSelectorOosDismissed(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    VappAppWidget *widget = (VappAppWidget *)pageSelector->getId();
    VfxS32 selectedIndex = pageSelector->getLastSelectedIndex();

    //
    // Close the page selector.
    //
    closePageSelector(pageSelector);
    m_pageSelectorOos = NULL;

    //
    // Dismissing completes. Resume the heavy UI components.
    //
    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    setWidgetSlim(VFX_FALSE);

    //
    // Activate the widget on the desktop if the operation is not aborted, e.g.,
    // the 'widget' pointer is valid. If this dismissing operation is because
    // the user abort the page selector, 'selectedIndex' will be -1 and 'widget'
    // will be NULL because it is closed already in onPageSelectorOosAborted.
    //
    if (widget && selectedIndex >= 0 && selectedIndex < VAPP_DESKTOP_MAX_PAGE_NUM)
    {
        VFX_OBJ_ASSERT_VALID(widget);
        VFX_ASSERT(m_desktop->canAddToPage(widget, selectedIndex));
        installWidgetOnPage(VFX_TRUE, widget, selectedIndex);
    }
}


void VappDesktopDirector::launchPageSelectorDnd(VappAppWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        if (m_desktop->canAddToPage(widget, i))
        {
            m_isPageFull[i] = VFX_FALSE;
        }
        else
        {
            m_isPageFull[i] = VFX_TRUE;
        }
    }

    //
    // Fold or suspend other UI component to speed-up the animation.
    //
    m_wallpaper->suspend();
    setBarFolding(VFX_TRUE);
    setWidgetSlim(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelectorDnd == NULL);
    m_pageSelectorDnd = createPageSelector();

    m_pageSelectorDnd->m_signalAssembled.connect(this, &VappDesktopDirector::onPageSelectorDndAssembled);
    m_pageSelectorDnd->m_signalSelected.connect(this, &VappDesktopDirector::onPageSelectorDndSelected);
    m_pageSelectorDnd->m_signalAborted.connect(this, &VappDesktopDirector::onPageSelectorDndAborted);
    m_pageSelectorDnd->m_signalDismissed.connect(this, &VappDesktopDirector::onPageSelectorDndDismissed);

    m_pageSelectorDnd->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorDnd->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappDesktopDirector::onPageSelectorDndAssembled(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        if (m_isPageFull[i])
        {
            m_pageSelectorDnd->setSnapshotAlert(i, VFX_TRUE);
        }
    }

    //
    // Assembling completes. Resume the heavy UI components.
    //

    // At present, keep heavy UI component, e.g. wallpaper, stopped because the
    // performance is still not good enough.
}


void VappDesktopDirector::onPageSelectorDndSelected(
    VappDesktopPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);
    VFX_ASSERT(idx >= 0 && idx < VAPP_DESKTOP_MAX_PAGE_NUM);

    //
    // If the user drop the widget to a page without available spaces, abort
    // the operation.
    //
    if (m_isPageFull[idx])
    {
        onPageSelectorDndAborted(
            pageSelector,
            VappDesktopPageSelector::ABORT_CAUSE_DROP_OUTSIDE);

        return;
    }

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Selection is done.
    //
    setBarFolding(VFX_FALSE);
    m_desktop->slideTo(idx, 0);

    pageSelector->disableSnapshotAlert();
    pageSelector->setFocusSnapshot(idx);
    pageSelector->dismiss();

    //
    // Temporarily set the widget to unhittable during the dismissing animation.
    //
    VappAppWidget *widget = (VappAppWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    widget->setIsUnhittable(VFX_TRUE);
}


void VappDesktopDirector::onPageSelectorDndAborted(
    VappDesktopPageSelector *pageSelector,
    VappDesktopPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappDesktopPageSelector::ABORT_CAUSE_HOME_KEY &&
        m_isInEditMode)
    {
        toggleEditMode(VFX_FALSE, VFX_FALSE);
    }

    //
    // Abort the selection.
    //
    setBarFolding(VFX_FALSE);

    pageSelector->disableSnapshotAlert();
    pageSelector->dismiss();

    //
    // Temporarily set the widget to unhittable during the dismissing animation.
    //
    VappAppWidget *widget = (VappAppWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    widget->setIsUnhittable(VFX_TRUE);
}


void VappDesktopDirector::onPageSelectorDndDismissed(
    VappDesktopPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    VappAppWidget *widget = (VappAppWidget *)pageSelector->getId();
    VfxS32 selectedIndex = pageSelector->getLastSelectedIndex();

    //
    // Close the page selector.
    //
    closePageSelector(pageSelector);
    m_pageSelectorDnd = NULL;

    //
    // Dismissing completes. Resume the heavy UI components.
    //
    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    setWidgetSlim(VFX_FALSE);

    //
    // Put widget on the desktop.
    //
    VfxPoint flyingSrcPos = widget->getPos();

    VfxPoint pos = convertPointTo(widget->getPos(), m_desktop);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(pos);

    VfxAutoAnimate::commit();

    //
    // Animate the widget to its final position. If the user doesn't correctly
    // drop the widget to a page with enough space, 'selectedIndex' will be -1.
    //
    if (selectedIndex >= 0 && selectedIndex < VAPP_DESKTOP_MAX_PAGE_NUM &&
        m_desktop->canAddToPage(widget, selectedIndex))
    {
        m_desktop->addToPage(widget, selectedIndex);
    }
    else
    {
        widget->restorePosition();
        m_desktop->addToNearest(widget);
    }

    saveArchivedWidget();

    //
    // Fly the widget on this director screen such that widget will not be
    // cutted by the desktop frame's bounds.
    //
    widget->backupPosition();

    VfxPoint flyingDstPos = convertPointFrom(widget->getPos(), m_desktop);

    addChildFrame(widget);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(flyingSrcPos);

    VfxAutoAnimate::commit();

    widget->setPos(flyingDstPos);

    m_timerWidgetFly->start();

    // Dismiss animation is done. Recovery the widget to hittable.
    widget->setIsUnhittable(VFX_FALSE);
}


VappDesktopPageSelector *VappDesktopDirector::createPageSelector()
{
    VappDesktopPageSelector *pageSelector;

    VFX_OBJ_CREATE(pageSelector, VappDesktopPageSelector, this);
    pageSelector->setFocused(VFX_TRUE);

    forbidSwipe(pageSelector);

    //
    // Add widgets to the page selector.
    //
    packWidgetToPageSelector(pageSelector);

    return pageSelector;
}


void VappDesktopDirector::closePageSelector(VappDesktopPageSelector *pageSelector)
{
    //
    // Restore all frame to each page.
    //
    unpackWidgetFromPageSelector(pageSelector);

    permitSwipe(pageSelector);

    VFX_OBJ_CLOSE(pageSelector);
}


void VappDesktopDirector::packWidgetToPageSelector(
    VappDesktopPageSelector *pageSelector)
{
    VfxS32 currentPageIndex = m_desktop->getCurrentPageIndex();
    VfxObjList objList;

    pageSelector->setFocusSnapshot(currentPageIndex);

    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        VfxRect insideRect, outsideRect;

        m_desktop->getPageRectExt(i, insideRect, outsideRect);

        pageSelector->setSnapshotLayout(i, insideRect, outsideRect);

        objList.clear();
        m_desktop->getFromPage(i, objList);

        for (VfxObjListEntry *entry = objList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

            if (widget)
            {
                pageSelector->addToSnapshot(i, widget);
            }
        }
    }
}


void VappDesktopDirector::unpackWidgetFromPageSelector(
    VappDesktopPageSelector *pageSelector)
{
    VfxObjList objList;

    for (VfxS32 i = 0; i < VAPP_DESKTOP_MAX_PAGE_NUM; i++)
    {
        objList.clear();
        pageSelector->removeFromSnapshot(i, objList);

        for (VfxObjListEntry *entry = objList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

            if (widget)
            {
                m_desktop->addToNearest(widget);
            }
        }
    }
}


void VappDesktopDirector::onWidgetSelected(const VappAppWidgetId &id)
{
    s_selectedWidgetId = id;
}


void VappDesktopDirector::layoutWidget()
{
    //
    // Create widget.
    //
    VappAppWidgetKit *kit;

    kit = VFX_OBJ_GET_INSTANCE(VappAppWidgetKit);

    VFX_ASSERT(s_selectedWidgetId.getSource() != VAPP_APP_WIDGET_SRC_INVALID);

    m_selectedWidget = kit->createWidget(s_selectedWidgetId, this);

    if (m_selectedWidget)
    {
        // Widget's final parent frame will be determined later.
        m_selectedWidget->removeFromParentFrame();

        // For performance, we install the widget on the desktop until the page
        // transition animation stops.
        vfxPostInvoke0(this, &VappDesktopDirector::onPostLayoutWidget);
    }

    s_selectedWidgetId.assignWith(
        VAPP_APP_WIDGET_SRC_INVALID,
        VappAppWidgetId::TYPE_KIND_UNKNOWN);
}


void VappDesktopDirector::onPostLayoutWidget()
{
    VFX_OBJ_ASSERT_VALID(m_selectedWidget);

    VappAppWidget *widget = m_selectedWidget;
    m_selectedWidget = NULL;

    //
    // If all pages cannot add this widget, display a error popup.
    //
    if (!m_desktop->canAddToPageIfAny(widget))
    {
        VFX_OBJ_CLOSE(widget);

        PopupContext *context;

        VFX_ALLOC_MEM(context, sizeof(PopupContext), this);
        context->stringId = STR_ID_VAPP_DESKTOP_ALL_PAGE_FULL;
        context->type = MMI_EVENT_INFO;

        vfxPostInvoke1(this, &VappDesktopDirector::displayErrorPopup, context);

        return;
    }

    //
    // If the current page can contain this widget, add it. We will create
    // widget's view during the 2nd pass creation phase.
    //
    if (m_desktop->canAddToPage(widget, m_desktop->getCurrentPageIndex()))
    {
        installWidgetOnPage(
            VFX_TRUE,
            widget,
            m_desktop->getCurrentPageIndex());

        return;
    }

    //
    // At least one page can contain this widget. Display the page selector for
    // the user to select a feasible page.
    //
    launchPageSelectorOos(widget);
}


void VappDesktopDirector::createWidget()
{
    if (VappAppWidgetArchiveUtil::isNewVersion())
    {
        //
        // Create the pre-installed widgets.
        //
        createPreInstalledWidget();

        //
        // This load is resets to its default widget configuration.
        //
        saveArchivedWidget();
        VappAppWidgetArchiveUtil::setVersionChecked();
    }
    else
    {
        //
        // Create all widgets which are present in the archive.
        //
        createArchivedWidget();
    }

    //
    // Color Filter
    //
    VFX_OBJ_CREATE(m_alertFilter, VappDesktopColorFilter, this);
    m_alertFilter->setColorFilter(s_alertFilterMin, s_alertFilterMax);

    //
    // Timer to fly the widget to its final position.
    //
    VFX_OBJ_CREATE(m_timerWidgetFly, VfxTimer, this);
    m_timerWidgetFly->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timerWidgetFly->m_signalTick.connect(this, &VappDesktopDirector::onFlyingFinished);

    //
    // Timer to launch page selector if the user drags the widget to stay on
    // some pre-defined UI component.
    //
    VFX_OBJ_CREATE(m_timerLaunchPageSelectorDnd, VfxTimer, this);
    m_timerLaunchPageSelectorDnd->setStartDelay(DND_PAGE_SELECTOR_START_DELAY);
    m_timerLaunchPageSelectorDnd->m_signalTick.connect(this, &VappDesktopDirector::onLaunchPageSelectorDnd);
}


void VappDesktopDirector::createPreInstalledWidget()
{
    VappAppWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappAppWidgetKit);
    VfxS32 num = kit->getPreInstalledNum();

    if (num <= 0)
    {
        return; // no pre-installed widgets.
    }

    VappAppWidgetPreInstalled **preInstalled;

    VFX_ALLOC_MEM(preInstalled, num * sizeof(VappAppWidgetPreInstalled *), this);

    for (VfxS32 i = 0; i < num; i++)
    {
        VFX_ALLOC_NEW(preInstalled[i], VappAppWidgetPreInstalled, this);
    }

    VfxS32 realNum = kit->getPreInstalledWidget(preInstalled, num);
    VFX_ASSERT(num == realNum);

    for (VfxS32 i = 0; i < num; i++)
    {
        // Create the pre-installed widget.
        VappAppWidget *widget = kit->createWidget(preInstalled[i]->m_id, this);
        VFX_ASSERT(widget);

        // Set the pre-installed widget's position.
        VfxRect pageRect = m_desktop->getPageRect(preInstalled[i]->m_pageIdx);
        VfxPoint pos = pageRect.origin;

        pos.x += preInstalled[i]->m_pos.x;
        pos.y += preInstalled[i]->m_pos.y;
        widget->setPos(pos);

        //
        // Activate the widget and put it on the desktop.
        //
        if (!m_desktop->canAddToDesktop(widget))
        {
            VFX_OBJ_CLOSE(widget);
        }
        else
        {
            m_desktop->addToDesktop(widget);
            m_widgetList.append(widget);
        }
    }

    for (VfxS32 i = 0; i < num; i++)
    {
        VFX_DELETE(preInstalled[i]);
    }

    VFX_FREE_MEM(preInstalled);
}


void VappDesktopDirector::createArchivedWidget()
{
    VappAppWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappAppWidgetKit);
    VappAppWidgetArchiveIterator *iter;
    VfxS32 totalNum;
    VappAppWidgetId id;
    VfxPoint pos;

    VFX_OBJ_CREATE(iter, VappAppWidgetArchiveIterator, this);

    if (!iter->readFirst(totalNum))
    {
        VFX_OBJ_CLOSE(iter);
    }

    for (VfxBool isSuccess = iter->readNext(id, pos);
         isSuccess == VFX_TRUE;
         isSuccess = iter->readNext(id, pos))
    {
        VappAppWidget *widget = kit->createWidget(id, this);
        if (!widget)
        {
            continue; // not found
        }

        widget->setPos(pos);

        if (!m_desktop->canAddToDesktop(widget))
        {
            VFX_OBJ_CLOSE(widget);
        }
        else
        {
            m_desktop->addToDesktop(widget);
            m_widgetList.append(widget);
        }
    }

    VFX_OBJ_CLOSE(iter);
}


void VappDesktopDirector::releaseWidget()
{
    // In case that the widget is on the dropping animation when this screen
    // is deleted, immediately emit the timeout signal such that the widget is
    // put into the desktop.
    if (m_timerWidgetFly && m_timerWidgetFly->getIsEnabled())
    {
        onFlyingFinished(m_timerWidgetFly);
    }

    //
    // Release all widgets' view.
    //
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

        if (widget)
        {
            widget->releaseView();
            VFX_OBJ_CLOSE(widget);
        }
    }
}


void VappDesktopDirector::saveArchivedWidget()
{
    m_widgetList.removeAllInvalidate();

    VappAppWidgetArchiveIterator *iter;

    VFX_OBJ_CREATE(iter, VappAppWidgetArchiveIterator, this);

    if (!iter->writeFirst(m_widgetList.getValidCount()))
    {
        return;
    }

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

        if (widget)
        {
            iter->writeNext(widget->getId(), widget->getPos());
        }
    }

    VFX_OBJ_CLOSE(iter);
}


void VappDesktopDirector::onFlyingFinished(VfxTimer *timer)
{
    if (m_dndWidget)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        m_dndWidget->restorePosition();

        VfxAutoAnimate::commit();

        m_desktop->addChildFrame(m_dndWidget);

        m_dndWidget = NULL;
    }
}


void VappDesktopDirector::onDragWidget(VappAppWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && m_desktop);

    //
    // Touch feedback
    //
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    //
    // Enter edit mode.
    //
    toggleEditMode(VFX_TRUE);

    //
    // Notify other UI component
    //
    m_wallpaper->setWidgetDragged(event.pos, widget);

    //
    // Suspend the heavy UI components.
    //
    m_wallpaper->suspend();
    setWidgetSlim(VFX_TRUE);

    //
    // Preliminary
    //
    m_penOffset = calcOffset(widget, event);

    widget->backupPosition();
    m_desktop->removeFromPage(widget);

    //
    // Initialization (disable auto. animation during initialization)
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(calcPosition(this, event, m_penOffset));

    VfxAutoAnimate::commit();

    //
    // Use auto animation for the opacity and transformation of the widget.
    //
    setWidgetDndEffect(widget, VFX_TRUE);

    //
    // Put the widget on the main screen such that it displays on the top-level.
    //
    addChildFrame(widget);

    //
    // When users are dragging the widget, do not allow the director to capture
    // the pen event to swipe the page.
    //
    forbidSwipe(widget);

    // Save the Drag-and-Drop (DnD) widget pointer.
    m_dndWidget = widget;
}


void VappDesktopDirector::onMoveWidget(VappAppWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && m_desktop);

    //
    // Notify other UI component.
    //
    m_wallpaper->setWidgetMoved(event.pos, widget);

    //
    // Change widget's property.
    //
    widget->forcePos(calcPosition(this, event, m_penOffset));

    //
    // If the page selector is present, handle it specially.
    //
    if (m_pageSelectorDnd)
    {
        m_pageSelectorDnd->doPenInput(event);
        return;
    }

    //
    // If the desktop cannot add widget, alert the widget.
    //
    if (!m_desktop->canAddToPage(widget, m_desktop->getCurrentPageIndex()))
    {
        setWidgetAlertEffect(widget, VFX_TRUE);
    }
    else
    {
        setWidgetAlertEffect(widget, VFX_FALSE);
    }

    //
    // Long-Tap Operation.
    //
    //  Priority 1: open the page selection
    //  Priority 2: auto-slide the page.
    //
    VFX_ASSERT(m_indicator);

    if (m_indicator->isHitted(event))
    {
        m_timerAutoSlidePage->stop();

        if (!m_timerLaunchPageSelectorDnd->getIsEnabled())
        {
            m_timerLaunchPageSelectorDnd->start();
        }
    }
    else
    {
        m_timerLaunchPageSelectorDnd->stop();

        VfxS32 ret;

        ret = m_desktop->getAutoSlideDirection(event.getRelPos(m_desktop));

        if (ret == 0)
        {
            m_timerAutoSlidePage->stop();
        }
        else
        {
            if (!m_timerAutoSlidePage->getIsEnabled())
            {
                m_timerAutoSlidePage->start();
            }
        }
    }
}


void VappDesktopDirector::onDropWidget(VappAppWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && widget == m_dndWidget && m_desktop);

    m_timerLaunchPageSelectorDnd->stop();
    m_timerAutoSlidePage->stop();

    //
    // Stop the dragging effect. Stop the alert effect.
    //
    setWidgetDndEffect(widget, VFX_FALSE);
    setWidgetAlertEffect(widget, VFX_FALSE);

    //
    // Notify other UI component.
    //
    m_wallpaper->setWidgetDropped(event.pos, widget);

    //
    // Resume the heavy UI components.
    //
    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    setWidgetSlim(VFX_FALSE);

    //
    // Widget is put on the desktop. Now we allow users to swipe the desktop.
    //
    permitSwipe(widget);

    //
    // If the page selector is present, handle it specially.
    //
    if (m_pageSelectorDnd)
    {
        m_pageSelectorDnd->doPenInput(event);
        return;
    }

    //
    // Finalization
    //
    VfxPoint flyingSrcPos = calcPosition(this, event, m_penOffset);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(calcPosition(m_desktop, event, m_penOffset));

    VfxAutoAnimate::commit();

    if (m_desktop->canAddToPage(widget, m_desktop->getCurrentPageIndex()))
    {
        m_desktop->addToNearest(widget, m_desktop->getCurrentPageIndex());
    }
    else
    {
        widget->restorePosition();
        m_desktop->addToNearest(widget);
    }

    saveArchivedWidget();

    //
    // Fly the widget on this director screen such that widget will not be
    // cutted by the desktop frame's bounds.
    //
    widget->backupPosition();

    VfxPoint flyingDstPos = convertPointFrom(widget->getPos(), m_desktop);

    addChildFrame(widget);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(flyingSrcPos);

    VfxAutoAnimate::commit();

    widget->setPos(flyingDstPos);

    m_timerWidgetFly->start();
}


void VappDesktopDirector::onAbortWidget(VappAppWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && widget == m_dndWidget && m_desktop);

    m_timerLaunchPageSelectorDnd->stop();
    m_timerAutoSlidePage->stop();

    //
    // Stop the dragging effect. Stop the alert effect.
    //
    setWidgetDndEffect(widget, VFX_FALSE);
    setWidgetAlertEffect(widget, VFX_FALSE);

    //
    // Notify other UI component.
    //
    m_wallpaper->setWidgetDropped(event.pos, widget);

    //
    // Resume the heavy UI components.
    //
    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    setWidgetSlim(VFX_FALSE);

    //
    // Widget is put on the desktop. Now we allow users to swipe the desktop.
    //
    permitSwipe(widget);

    //
    // If the page selector is present, handle it specially.
    //
    if (m_pageSelectorDnd)
    {
        m_pageSelectorDnd->doPenInput(event);
        return;
    }

    //
    // Finalization
    //
    // Fly the widget on this director screen such that widget will not be
    // cutted by the desktop frame's bounds.
    //
    VfxPoint flyingSrcPos = calcPosition(this, event, m_penOffset);

    widget->restorePosition();

    VfxPoint flyingDstPos = convertPointFrom(widget->getPos(), m_desktop);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(flyingSrcPos);

    VfxAutoAnimate::commit();

    widget->setPos(flyingDstPos);

    m_timerWidgetFly->start();
}


void VappDesktopDirector::onDeselectWidget(VappAppWidget *widget)
{
    VFX_ASSERT(widget);
    VAPP_DESKTOP_SLA(("HDH", SA_start));

    m_deleteWidget = widget;
    widget->setHidden(VFX_TRUE);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->blockAfterNextCommit(1, VfxCallback0(this, &VappDesktopDirector::onDeleteWidget));
  
    VAPP_DESKTOP_SLA(("HDH", SA_stop));
}


void VappDesktopDirector::onDeleteWidget()
{
    VFX_ASSERT(m_deleteWidget);
    VAPP_DESKTOP_SLA(("HDW", SA_start));

    m_deleteWidget->releaseView();

    m_widgetList.removeOne(m_deleteWidget);

    VFX_OBJ_CLOSE(m_deleteWidget);
    m_deleteWidget = NULL;

    saveArchivedWidget();
    VAPP_DESKTOP_SLA(("HDW", SA_stop));
}


void VappDesktopDirector::onLaunchPageSelectorDnd(VfxTimer *timer)
{
    if (!m_dndWidget)
    {
        return;
    }

    launchPageSelectorDnd(m_dndWidget);

    //
    // Disable the alert effect and make sure the widget is on the top of the
    // page selector.
    //
    setWidgetAlertEffect(m_dndWidget, VFX_FALSE);

    //
    // Re-add this frame such that it will be bringed to the front. Don't use
    // bringToFront API directly. It will not trigger widget's
    // onParentFrameChanged virtual function.
    //
    m_dndWidget->removeFromParentFrame();
    addChildFrame(m_dndWidget);
}


void VappDesktopDirector::activateWidget(VappAppWidget *widget)
{
    //
    // Connect signals and create the view.
    //
    widget->m_signalDrag.connect(this, &VappDesktopDirector::onDragWidget);
    widget->m_signalMove.connect(this, &VappDesktopDirector::onMoveWidget);
    widget->m_signalDrop.connect(this, &VappDesktopDirector::onDropWidget);
    widget->m_signalAbort.connect(this, &VappDesktopDirector::onAbortWidget);
    widget->m_signalDeselect.connect(this, &VappDesktopDirector::onDeselectWidget);

    widget->createView();

    //
    // Misc.
    //
    if (m_isInEditMode)
    {
        widget->enterEditMode();
    }
}


void VappDesktopDirector::installWidgetOnPage(
    VfxBool activate,
    VappAppWidget *widget,
    VfxS32 idx)
{
    if (activate)
    {
        activateWidget(widget);
    }

    m_widgetList.append(widget);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_desktop->addToPage(widget, idx);

    VfxAutoAnimate::commit();

    saveArchivedWidget();
}


void VappDesktopDirector::setWidgetSlim(VfxBool isSlim)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

        if (widget)
        {
            if (isSlim)
            {
                widget->enterSlimView();
            }
            else
            {
                widget->exitSlimView();
            }
        }
    }
}


void VappDesktopDirector::setWidgetEditMode(VfxBool isOn)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappAppWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappAppWidget);

        if (widget)
        {
            if (isOn)
            {
                widget->enterEditMode();
            }
            else
            {
                widget->exitEditMode();
            }
        }
    }
}


void VappDesktopDirector::setWidgetAlertEffect(VappAppWidget *widget, VfxBool isOn)
{
    VFX_OBJ_ASSERT_VALID(widget);

    if (isOn)
    {
        widget->setFilter(m_alertFilter);
    }
    else
    {
        widget->setFilter(NULL);
    }
}


void VappDesktopDirector::setWidgetDndEffect(
    VappAppWidget *widget,
    VfxBool isOn)
{
    if (isOn)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        widget->setOpacity(s_dndOpacity);

        VfxTransform trans;

        trans.init(VRT_TRANSFORM_TYPE_AFFINE);
        trans.data.affine.sx = s_dndScaleRatio;
        trans.data.affine.sy = s_dndScaleRatio;

        widget->setTransform(trans);

        VfxAutoAnimate::commit();

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_DAMPING_OUT);

        widget->setTransform(VFX_TRANSFORM_IDENTITY);

        VfxAutoAnimate::commit();
    }
    else
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        widget->setOpacity(1.0f);

        VfxAutoAnimate::commit();
    }
}


VfxPoint VappDesktopDirector::calcOffset(
    const VfxFrame *frame,
    const VfxPenEvent &event) const
{
    VfxRect bounds = frame->getBounds();
    VfxPoint penPos = event.getRelPos(frame);

    VfxPoint offset;
    offset.x = penPos.x - bounds.getMidX();
    offset.y = penPos.y - bounds.getMidY();

    return offset;
}


VfxPoint VappDesktopDirector::calcPosition(
    const VfxFrame *frame,
    const VfxPenEvent &event,
    const VfxPoint &offset) const
{
    VfxPoint pos = event.getRelPos(frame);

    pos.x -= offset.x;
    pos.y -= offset.y;

    return pos;
}


void VappDesktopDirector::displayErrorPopup(PopupContext *context)
{
    VFX_ASSERT(context);

    const VfxResId stringId = context->stringId;
    mmi_event_notify_enum type = context->type;

    VFX_FREE_MEM(context);

    mmi_popup_display_simple(
        (WCHAR *)vfxSysResGetStr(stringId),
        type,
        mmi_idle_get_group_id(),
        NULL);
}


VfxS32 VappDesktopDirector::calcDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


VfxBool VappDesktopDirector::isHorizontalPenMove(const VfxPenEvent &event)
{
    VfxS32 xDiff = vfxAbs(event.pos.x - event.downPos.x);
    VfxS32 yDiff = vfxAbs(event.pos.y - event.downPos.y);

    return xDiff > yDiff ? VFX_TRUE : VFX_FALSE;
}


void VappDesktopDirector::setBarFolding(VfxBool isFolded, VfxBool isAnimatable)
{
    if (isFolded)
    {
        m_indicator->fold(isAnimatable);
        m_shortcutBar->fold(isAnimatable);
        m_toolbar->fold(isAnimatable);
    }
    else
    {
        m_indicator->unfold(isAnimatable);

        if (m_isInEditMode)
        {
            m_shortcutBar->fold(isAnimatable);
            m_toolbar->unfold(isAnimatable);
        }
        else
        {
            m_shortcutBar->unfold(isAnimatable);
            m_toolbar->fold(isAnimatable);
        }
    }
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

