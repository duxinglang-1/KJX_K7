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
 *  vapp_launcher_robot_director.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the director page.
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

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vfx_adp_device.h"
#include "vapp_archive_nvram.h"
#include "vapp_launcher_def.h"
#include "vapp_launcher.h"
#include "vapp_launcher_native_factory.h"
#include "vapp_widget.h"
#include "vapp_widget_kit.h"
#include "vapp_launcher_mem_cfg.h"
#include "vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_page_selector.h"
#include "vapp_launcher_robot_shortcut_selector.h"
#include "vapp_launcher_robot_widget_selector.h"
#include "vapp_launcher_robot_director.h"
#include "vapp_launcher_robot_preinstaller.h"
#include "mmi_rp_vapp_launcher_robot_def.h"
#include "vapp_clog_gprot.h"
#include "vapp_setting_framework_gprot.h"
#include "vapp_setting_wallpaper_setting_gprot.h"
#include "vapp_dialer_gprot.h"
#include "vapp_platform_context.h"

//
// Wallpaper:
//
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_setting_method_gprot.h"

//
// C headers
//
extern "C"
{
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#include "ImeQwertyProt.h"
#endif

#if defined(VAPP_LAUNCHER_ROBOT_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif

// browser
#include "browser_api.h"
}

#if defined(__MMI_VUI_PLATFORM_CONTEXT_SLIM__)
#define VAPP_LAUNCHER_ROBOT_WIDGET_SETTING_DATA_SIZE (15 * (VAPP_LAUNCHER_ROBOT_MAX_SHORTCUT_WIDGET_NUM + 10))
#endif
/*****************************************************************************
 * Home Director
 *****************************************************************************/

VAPP_LAUNCHER_SYS_PUBLISH_NATIVE(
    VappLauncherRobotDirector,
    VAPP_LAUNCHER_TYPE_ROBOT,
    VappLauncherRobotDirectorPublisher);

VAPP_LAUNCHER_IMPLEMENT_CLASS(VappLauncherRobotDirector, VappLauncher);

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
VfxBool VappLauncherRobotDirector::s_isShowMainmenu = VFX_FALSE;
VfxS32 VappLauncherRobotDirector::s_curHSPageIndex = VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM/2;
#endif
VfxU8 *VappLauncherRobotDirector::m_widgetSettingDataPtr = NULL;
VfxU32 VappLauncherRobotDirector::m_widgetSettingDataSize = 0;

const VfxFloat VappLauncherRobotDirector::s_dndScaleRatio = 0.7f;
const VfxFloat VappLauncherRobotDirector::s_dndOpacity = 0.6f;
const VfxFloat VappLauncherRobotDirector::s_landingOpacity = 0.4f;
const VfxColor VappLauncherRobotDirector::s_alertFilterMin(0, 128, 0, 0);    // ARGB
const VfxColor VappLauncherRobotDirector::s_alertFilterMax(255, 255, 0, 0);  // ARGB


VappLauncherRobotDirector::VappLauncherRobotDirector() :
    m_widgetArchiveSource(NULL),
    m_dummyRootHS(NULL),
    m_timer2ndPassLoader(NULL),
    m_wallpaper(NULL),
    m_timerResumeWallpaper(NULL),
    m_isWallpaperSuspendForMM(VFX_FALSE),
    m_isWallpaperSuspendForAppExit(VFX_FALSE),
    m_isWallpaperSuspendForNcenter(VFX_FALSE),
#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    m_isSuspendWallpaperForSwipe(VFX_FALSE),
    m_isSuspendWallpaperForPenDown(VFX_FALSE),
#endif /* defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE) */
    m_desktop(NULL),
    m_timerAutoSlideDesktop(NULL),
    m_isCaptured(VFX_FALSE),
    m_isCapturedFromOthers(VFX_FALSE),
    m_cannotSwipeRequest(),
    m_cannotSwipeList(),
    m_shortcutBar(NULL),
    m_mainmenu(NULL),
    m_tlMMSSE(NULL),
    m_tlHSSSE(NULL),
    m_toolbar(NULL),
    m_isCreatWidgetFromMM(VFX_FALSE),
    m_trashCanBar(NULL),
    m_isInEditMode(VFX_FALSE),
    m_pageSelector(NULL),
    m_pageSelectorOos(NULL),
    m_pageSelectorDnd(NULL),
    m_timerLaunchPageSelectorDnd(NULL),
    m_numShortcut(0),
    m_shortcutSelector(NULL),
    m_widgetSelector(NULL),
    m_selectedWidget(NULL),
    m_deleteWidgetList(),
    m_dndWidget(NULL),
#if defined(__COSMOS_3D_V10__)
    m_alertMaterial(NULL),
#else
    m_alertFilter(NULL),
#endif
    m_penOffset(VFX_POINT_ZERO),
    m_widgetList()
{
    // Do nothing.
}


VfxBool VappLauncherRobotDirector::onKeyInput(VfxKeyEvent &event)
{
    if (isPageSelectorPresent())
    {
        return VappLauncher::onKeyInput(event);
    }

    //
    // Go Back.
    //
    if (event.keyCode == VFX_KEY_CODE_BACK)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_mainmenu && m_mainmenu->getOpacity() == 1)
            {
                // go back to HS from MM after press Home key if MM is active
                showMainMenu(VFX_FALSE);
            }
            else if (m_isInEditMode) // if HS is active
            {
                // if press back key on hs page,
                // then leave edit mode
                toggleEditMode(VFX_FALSE);
            }
        }
        return VFX_TRUE;
    }

    //
    // Standby.
    //
    else if (event.keyCode == VFX_KEY_CODE_HOME)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            // if MM is active, go back to Home when press Home key
            if (m_mainmenu && m_mainmenu->getOpacity() == 1)
            {
                showMainMenu(VFX_FALSE);
            }
            else // if HS is active
            {
                if (m_isInEditMode)
                {
                    toggleEditMode(VFX_FALSE);
                    return VFX_TRUE;
                }
                m_desktop->slideToCentra();
            }
        }

        return VFX_TRUE;
    }

    //
    // Call log.
    //
    else if (event.keyCode == VFX_KEY_CODE_SEND)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            vfxPostInvoke(this, &VappLauncherRobotDirector::launchCallLog);
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
            #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
                suspendWallpaperForSwipe();
            #endif
            
                m_desktop->slideToNext();
            
            #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
                resumeWallpaperForSwipe();
            #endif

            return VFX_TRUE;
        }
    }

    //
    // Dialer
    //
    else if (event.keyCode == VFX_KEY_CODE_0 ||
             event.keyCode == VFX_KEY_CODE_1 ||
             event.keyCode == VFX_KEY_CODE_2 ||
             event.keyCode == VFX_KEY_CODE_3 ||
             event.keyCode == VFX_KEY_CODE_4 ||
             event.keyCode == VFX_KEY_CODE_5 ||
             event.keyCode == VFX_KEY_CODE_6 ||
             event.keyCode == VFX_KEY_CODE_7 ||
             event.keyCode == VFX_KEY_CODE_8 ||
             event.keyCode == VFX_KEY_CODE_9 ||
             event.keyCode == VFX_KEY_CODE_STAR ||
             event.keyCode == VFX_KEY_CODE_POUND ||
             event.keyCode == VFX_KEY_CODE_P ||
             event.keyCode == VFX_KEY_CODE_W ||
         #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
             mmi_imm_qwerty_is_valid_character_by_mmi_key(event.keyCode, L'+') ||
         #endif
             VFX_FALSE)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            VfxKeyCodeEnum *keyCode;

            VFX_ALLOC_MEM(keyCode, sizeof(VfxKeyCodeEnum), this);
            *keyCode = event.keyCode;

            vfxPostInvoke(this, &VappLauncherRobotDirector::launchDialerWithKey, keyCode);

            return VFX_TRUE;
        }
    }

    return VappLauncher::onKeyInput(event);
}


void VappLauncherRobotDirector::onPenDownTimerTick(VfxTimer *source)
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_DOWN_TIMER_TICK, 200));

    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    penSrv->resumeDelayedEvent();
}


VfxBool VappLauncherRobotDirector::isPenEventCaptureByComp()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget->isProcessPenCapture())
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxBool VappLauncherRobotDirector::onPreviewPenInput(VfxPenEvent &event)
{
    if (isPageSelectorPresent())
    {
        return VappLauncher::onPreviewPenInput(event);
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:

            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

        #if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
            suspendWallpaperForPenDown();
        #endif

            //
            // Update the widget's focus.
            //
            if (!m_isCaptured)
            {
                updateWidgetFocus(event);

                // there is no need to delay pen event 
                // if this pen down is sent because comp call captured
                // 
                if(!m_desktop->isSliding() && !isPenEventCaptureByComp())
                {
                    // delay event when first pen down
                    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
                    if (penSrv->delayEvent(this, event))
                    {
                        m_penDownTimer->start();
                        onPenInput(event);
                    }
                }
            }

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:

            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));

            //
            // If the horizontal pen-move is large enough, capture the pen
            // event.
            //
            if (//!m_isCaptured &&
                !isSwipeForbidden() &&
                !isFrameCannotSwipe(event.relObjList) &&
                calcDistance(event.downPos, event.pos) > SLIDE_START_OFFSET &&
                isHorizontalPenMove(event))
            {
                VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_CAPTURE));

                if (m_penDownTimer->getIsEnabled())
                {                 
                    m_penDownTimer->stop();
                }
                else
                {
                    if (capturePenEvent(event.target))
                    {
                        return VFX_TRUE;
                    }
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:

            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'L', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                               'U', event.pos.x, event.pos.y));

                if (m_penDownTimer->getIsEnabled())
                {   // pen click
                    m_penDownTimer->stop();
                    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
                    penSrv->resumeDelayedEvent();
                }
            }
            else
            {
                VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                               'A', event.pos.x, event.pos.y));
                m_penDownTimer->stop();
            }

        #if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
            resumeWallpaperForPenDown();
        #endif

            break;

        default:
            break;
    }

    return VappLauncher::onPreviewPenInput(event);
}


VfxBool VappLauncherRobotDirector::onPenInput(VfxPenEvent &event)
{
    if (!m_isCaptured && event.type != VFX_PEN_EVENT_TYPE_DOWN)
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                       '-', event.pos.x, event.pos.y));

        return VappLauncher::onPenInput(event);
    }

    //
    // Notify the desktop that a pen event comes.
    //
    if (!m_penDownTimer->getIsEnabled())
    {                 
        m_desktop->doPenInput(event);
    }

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
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

            m_isCaptured = VFX_TRUE;

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                           'L', event.pos.x, event.pos.y));

            if (!m_isInEditMode &&
                calcDistance(event.downPos, event.pos) <= SLIDE_START_OFFSET)
            {
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
                toggleEditMode(VFX_TRUE);
            }

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                               'U', event.pos.x, event.pos.y));
            }
            else
            {
                VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_PEN_INPUT,
                               'A', event.pos.x, event.pos.y));
            }
            
            m_isCaptured = VFX_FALSE;
            m_isCapturedFromOthers = VFX_FALSE;

            break;

        default:
            break;
    }

    return VFX_TRUE;
}


VfxBool VappLauncherRobotDirector::capturePenEvent(const VfxObject *target)
{
    if(m_isCaptured == VFX_FALSE)
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
    else
    {
        return VFX_FALSE;
    }
}


void VappLauncherRobotDirector::onDraw(VfxDrawContext &dc)
{
    VappLauncher::onDraw(dc);

    //
    // Update widgets' visible.
    //
    updateWidgetVisible();
}


VappLauncherId VappLauncherRobotDirector::getId() const
{
    return VappLauncherId(
            VAPP_LAUNCHER_SRC_NATIVE,
            VAPP_LAUNCHER_TYPE_ROBOT);
}


VfxS32 VappLauncherRobotDirector::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_LAUNCHER_ROBOT_SETTING_NAME);
    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);

}


VfxFrame *VappLauncherRobotDirector::createIcon(VfxObject *parentObj)
{
    return NULL;
}


VfxS32 VappLauncherRobotDirector::getScreenshotNum() const
{
    return 1;
}


VfxFrame **VappLauncherRobotDirector::createScreenshot(VfxObject *parentObj) const
{
    VfxFrame **screenshot;

    VFX_ALLOC_MEM(screenshot, getScreenshotNum(), parentObj);

    VFX_OBJ_CREATE(screenshot[0], VfxImageFrame, parentObj);

    ((VfxImageFrame*)screenshot[0])->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_SETTING_SNAPSHOT);
    return screenshot;
}


void VappLauncherRobotDirector::onCreateView()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_INIT, 100));

    VappLauncher::onCreateView();

    //
    // Launcher Size.
    //
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    setSize(screenSize.width, screenSize.height);

    VFX_OBJ_CREATE(m_dummyRootHS, VfxFrame, this);
    m_dummyRootHS->setSize(getSize());

    //
    // 2nd pass activation.
    //
    create2ndPassLoader();

    //
    // Other UI components
    //
    if(isFirstInit())
    {
        createWallpaper(WALLPAPER_BOOTUP_DELAY_TIME);
    }
    else
    {
        createWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    }

    createDesktop();

    createShortcutBar();

    createToolbar();

    createTrashCanBar();

    createWidget();

    createMainMenu();

    VFX_OBJ_CREATE(m_penDownTimer, VfxTimer, this);
    m_penDownTimer->setStartDelay(PEN_DOWN_DELAY);
    m_penDownTimer->m_signalTick.connect(this, &VappLauncherRobotDirector::onPenDownTimerTick);   

    //
    // Connect wallpaper changed signal.
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.connect(this, &VappLauncherRobotDirector::onWallpaperChanged);

    //
    // For performance, try to reduce the time to render the first frame of the
    // SSE using 2nd pass loader.
    //
    start2ndPassLoader();

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_INIT, 200));
}


void VappLauncherRobotDirector::onReleaseView()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_DEINIT, 100));

    //
    // Disconnect wallpaper changed signal.
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.disconnect(this, &VappLauncherRobotDirector::onWallpaperChanged);

    //
    // Release other UI components
    //
    releaseWidget();

    releaseToolbar();

    releaseTrashCanBar();

    releaseShortcutBar();

    releaseDesktop();

    releaseWallpaper();

    //
    // Release 2nd pass activation.
    //
    release2ndPassLoader();

    releaseMainmenu();
    
    if(m_pageSlideTransitionWeakPtr.isValid())
    {
        VFX_OBJ_CLOSE(m_pageSlideTransitionWeakPtr);
    }

    VFX_OBJ_CLOSE(m_penDownTimer);
    
    VFX_OBJ_CLOSE(m_dummyRootHS);
    VappLauncher::onReleaseView();

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_DEINIT, 200));
}


void VappLauncherRobotDirector::onSerializeView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    VappLauncher::onSerializeView(ar);

    // Serialize widgets to save memory.
    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_start));
    serializeWidget();
    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_stop));

    // Move wallpaper create/restore from page onEnter/onExit to onAppActive/onAppInactive
    // because wallpaper will be MM's background

    // Serialize wallpaper
    // wallpaper may be deleted on MM when plug-in/plug-out Memory,
    // in this case, wallpaper will be null pointer when leaving HS/MM app,
    // but wallpaper will be created onRestoreView when HS/MM app active
    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_start));
    if(m_wallpaper)
    {
        m_wallpaper->serializeView();
    }
    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_stop));

    // Stop the 2nd pass App active if it isn't completed.
    stop2ndPassLoader();

    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_start));
    m_mainmenu->onSerializeView();
    VAPP_LAUNCHER_ROBOT_SLA(("HD2", SA_stop));
}


void VappLauncherRobotDirector::onRestoreView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    VappLauncher::onRestoreView(ar);

    //
    // Restore the wallpaper. Note that wallpaper cannot be changed when the
    // setting sends a 'wallpaper-changed' signal.
    //
    // SEE ALSO: onWallpaperChanged
    //

    // Move wallpaper create/restore from page onEnter/onExit to onAppActive/onAppInactive
    // because wallpaper will be MM's background
    VAPP_LAUNCHER_ROBOT_SLA(("HR0", SA_start));
    if (!m_wallpaper)
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_ENTER, 300));
        createWallpaperExt(-1);
    }
    else
    {
        VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_ENTER, 301));
        m_wallpaper->restoreView();
    }
    VAPP_LAUNCHER_ROBOT_SLA(("HR0", SA_stop));
    //
    // For performance, try to reduce the time to render the first frame of the
    // SSE using 2nd pass loader.
    //
    start2ndPassLoader();

    VAPP_LAUNCHER_ROBOT_SLA(("HR0", SA_start));
    m_mainmenu->onRestoreView();
    VAPP_LAUNCHER_ROBOT_SLA(("HR0", SA_stop));
}


void VappLauncherRobotDirector::onEnter()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_ENTER, 100));
    VAPP_LAUNCHER_ROBOT_SLA(("HI1", SA_start));

    VappLauncher::onEnter();

    restoreWidgetForPageSwitch();

    // For performance, resume the wallpaper after the page transition animation
    // completes. To avoid from the complication, we only resume wallpaper when
    // it had suspended because the page exited.
    if (m_wallpaper && m_isWallpaperSuspendForAppExit)
    {
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
        m_isWallpaperSuspendForAppExit = VFX_FALSE;
    }
    
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    if(isRestoreStatus() && s_isShowMainmenu && !isProcessHomeKey())
    {
        showMainMenu(VFX_TRUE, VFX_FALSE);
    }
    else
    {
        showMainMenu(VFX_FALSE, VFX_FALSE);
    }
#else
    if(m_mainmenu->getOpacity() == 1.0 && !isProcessHomeKey())
    {
        // notify main menu's pagen enter, it needs to cache icon
        showMainMenu(VFX_TRUE, VFX_FALSE);
    }
    else
    {
        showMainMenu(VFX_FALSE, VFX_FALSE);
    }
#endif

    m_desktop->enterDesktop();
    
    //
    // For performance, we will suspend the wallpaper when the notification
    // center is active.
    //
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    ncenter->m_signalEvent.connect(this, &VappLauncherRobotDirector::onNotificationCenterChanged);

    VAPP_LAUNCHER_ROBOT_SLA(("HI1", SA_stop));
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_ENTER, 200));
}


void VappLauncherRobotDirector::onExit()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_EXIT, 100));
    VAPP_LAUNCHER_ROBOT_SLA(("HD0", SA_start));

    m_desktop->exitDesktop();

    // For performance, suspend the wallpaper before the page transition
    // animation starts.
    if (m_wallpaper && !m_isWallpaperSuspendForAppExit)
    {
        if (m_timerResumeWallpaper->getIsEnabled())
        {
            // If timer is already ongoing, expire it immediately
            m_timerResumeWallpaper->stop();
            m_wallpaper->resume();
        }
        m_wallpaper->suspend();
        m_isWallpaperSuspendForAppExit = VFX_TRUE;
    }

    serializeWidgetForPageSwitch();

    //
    // Disconnect the notification center changed signal.
    //
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    ncenter->m_signalEvent.disconnect(this, &VappLauncherRobotDirector::onNotificationCenterChanged);

    VappLauncher::onExit();

    VAPP_LAUNCHER_ROBOT_SLA(("HD0", SA_stop));
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_EXIT, 200));
}


VfxResId VappLauncherRobotDirector::onGetStatusBarBg()
{
    return IMG_ID_VAPP_LAUNCHER_ROBOT_STATUS_BAR_BG;
}


VfxBool VappLauncherRobotDirector::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


void VappLauncherRobotDirector::save()
{
    m_widgetList.removeAllInvalidate();

    //
    // Create list array for widgets on each page.
    //
    VfxObjList list[CUSTOM_LAUNCHER_ROBOT_PAGE_NUM];

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);
        VFX_ASSERT(widget);

        VfxS32 pageIdx = m_desktop->getPageIndex(widget);
        if (pageIdx >= 0 && pageIdx < CUSTOM_LAUNCHER_ROBOT_PAGE_NUM)
        {
            list[pageIdx].append(widget);
        }
    }

    //
    // Write settings of each page.
    //
    VfxArchive *ar = createArchive(0, 'w');
    if (!ar)
    {
        return;
    }

    // save widget setting into NVRAM and buffer
    VfxArchive *archiveToRAM;
    VFX_OBJ_CREATE(archiveToRAM, VfxArchive, this);

    //
    //Clear old widget setting data
    //
    VFX_FREE_MEM(m_widgetSettingDataPtr);
    m_widgetSettingDataSize = 0;
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
    VFX_OBJ_CREATE_EX(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext), (VAPP_LAUNCHER_ROBOT_WIDGET_SETTING_DATA_SIZE));
#else
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif
    archiveToRAM->setSource(m_widgetArchiveSource);

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_ROBOT_PAGE_NUM; i++)
    {
        ar->writeU8(list[i].getEntryCount());
        archiveToRAM->writeU8(list[i].getEntryCount());

        for (VfxObjListEntry *entry = list[i].getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

            VFX_ASSERT(widget);

            // Widget ID.
            widget->getId().encodeToArchive(ar);
            widget->getId().encodeToArchive(archiveToRAM);

            // Page index of Widget.
            ar->writeU8(m_desktop->getPageIndex(widget));
            archiveToRAM->writeU8(m_desktop->getPageIndex(widget));

            // Widget position.
            ar->writePoint(widget->getPos());
            archiveToRAM->writePoint(widget->getPos());
        }
    }

    m_widgetArchiveSource->detachBuffer(&m_widgetSettingDataPtr, &m_widgetSettingDataSize);
    
    VFX_OBJ_CLOSE(ar);
    VFX_OBJ_CLOSE(m_widgetArchiveSource);
    VFX_OBJ_CLOSE(archiveToRAM);
}


void VappLauncherRobotDirector::create2ndPassLoader()
{
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappLauncherRobotDirector::on2ndPassLoader);
}


void VappLauncherRobotDirector::release2ndPassLoader()
{
    VFX_OBJ_CLOSE(m_timer2ndPassLoader);
}


void VappLauncherRobotDirector::start2ndPassLoader()
{
    m_desktop->setHidden(VFX_TRUE);

    m_timer2ndPassLoader->start();
}


void VappLauncherRobotDirector::stop2ndPassLoader()
{
    if (m_timer2ndPassLoader->getIsEnabled())
    {
        m_timer2ndPassLoader->stop();
    }
}


void VappLauncherRobotDirector::on2ndPassLoader(VfxTimer *timer)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HI3", SA_label));

    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_2ND_PASS_LOADER, 200));
    restoreWidget();

    m_desktop->setHidden(VFX_FALSE);

    //
    // Animate the widgets with landing effect.
    //
    setWidgetLandingEffect();

    VAPP_LAUNCHER_ROBOT_SLA(("HI3", SA_label));
}


void VappLauncherRobotDirector::createWallpaper(VfxMsec delayTime)
{
    VFX_ASSERT(!m_wallpaper && !m_timerResumeWallpaper);

    // Create wallpaper
    m_wallpaper = VappWallpaperKit::createWallpaper(m_dummyRootHS, VAPP_WALLPAPER_SRC_HOMESCREEN, VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

    //
    // Sync wallpaper to the desktop's current bounds.
    //
    if (m_desktop)
    {
        m_wallpaper->setDesktopBoundsChanged(
                        VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM,
                        m_desktop,
                        m_desktop->getBounds());
    }

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


void VappLauncherRobotDirector::createWallpaperExt(VfxMsec delayTime)
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_CREATE_WALLPAPER_EXT, delayTime, 200));

    // Re-create the wallpaper. For performance, if the page selector is
    // present, we specify a negative delay time such that wallpaper is
    // suspended after it is created.
    if (isPageSelectorPresent())
    {
        createWallpaper(-1);    // -1 means do not resume it now.
    }
    else
    {
        createWallpaper(delayTime);
    }

    // For performance, if the notification center is present, suspend it.
    if (m_isWallpaperSuspendForNcenter)
    {
        m_wallpaper->suspend();
    }
}


void VappLauncherRobotDirector::releaseWallpaper()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_RELEASE_WALLPAPER, 200));

    // Release objects.
    VFX_OBJ_CLOSE(m_wallpaper);
    VFX_OBJ_CLOSE(m_timerResumeWallpaper);
}


void VappLauncherRobotDirector::onWallpaperChanged()
{
    VAPP_LAUNCHER_ROBOT_LOG((TRC_VAPP_LAUNCHER_ROBOT_DIRECTOR_ON_WALLPAPER_CHANGED, 200));
    releaseWallpaper();

    //
    // Because video wallpaper cannot be created in the background, we can only
    // re-create the wallpaper when this director page is active.
    //
    if (!isSerialized())
    {
        createWallpaperExt(-1);
    }

    if (isEntered())
    {
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    }

    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);

    // [MAUI_03154209] [Launcher] Workaround VRT mem factor and video memory concurrency issue.
    // vrt factor is used to reserve memory for vrt to do cache or provide resource to GPU,
    // so if wallpaper no needs to set vrt cache size for gpu resource (EX. 3D wallpaper)
    // set the default vrt factor to VRT to do the cache
    // set vrt cache size of HS screen variable when wallpaper changed
    // so that screen will set vrt factor before vrt init
    if(!m_wallpaper)
    {
        VappWallpaper *wallpaper = VappWallpaperKit::createWallpaperWithoutSetup(m_dummyRootHS, VAPP_WALLPAPER_SRC_HOMESCREEN);
        if(wallpaper->getVrtMemFactor() == 0)
        {
            mainScr->setVrtCacheSize(VAPP_LAUNCHER_VRT_CACHE_LIMIT);
        }
        else
        {
            mainScr->setVrtCacheSize(wallpaper->getVrtMemFactor());
        }
        VFX_OBJ_CLOSE(wallpaper);
    }
    else
    {
        // set Vrt Mem Factor for wallpaper changed
        if(m_wallpaper->getVrtMemFactor() == 0)
        {
            mainScr->setVrtCacheSize(VAPP_LAUNCHER_VRT_CACHE_LIMIT);
        }
        else
        {
            mainScr->setVrtCacheSize(m_wallpaper->getVrtMemFactor());
        }
    }
}


void VappLauncherRobotDirector::delayResumeWallpaper(VfxMsec delayTime)
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
        m_timerResumeWallpaper->m_signalTick.connect(this, &VappLauncherRobotDirector::onResumeWallpaper);
        m_timerResumeWallpaper->start();
    }
}


void VappLauncherRobotDirector::onResumeWallpaper(VfxTimer *timer)
{
    if (m_wallpaper)
    {
        m_wallpaper->resume();
    }
}


#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
void VappLauncherRobotDirector::suspendWallpaperForSwipe()
{
    // If timer is already ongoing, fire it immediately.
    if (m_timerResumeWallpaper->getIsEnabled())
    {
        m_wallpaper->resume();
        m_timerResumeWallpaper->stop();
    }

    if (!m_isSuspendWallpaperForSwipe
        && m_wallpaper->isAllowSuspendOnSwipe())
    {
        m_isSuspendWallpaperForSwipe = VFX_TRUE;
        m_wallpaper->suspend();
    }
}


void VappLauncherRobotDirector::resumeWallpaperForSwipe()
{
    if (m_isSuspendWallpaperForSwipe)
    {
        m_isSuspendWallpaperForSwipe = VFX_FALSE;
        delayResumeWallpaper(WALLPAPER_SWIPE_DELAY_TIME);
    }
}


void VappLauncherRobotDirector::suspendWallpaperForPenDown()
{
    // If timer is already ongoing, fire it immediately.
    if (m_timerResumeWallpaper->getIsEnabled())
    {
        m_wallpaper->resume();
        m_timerResumeWallpaper->stop();
    }

    if (!m_isSuspendWallpaperForPenDown &&
        m_wallpaper->isAllowSuspendOnPenDown())
    {
        m_isSuspendWallpaperForPenDown = VFX_TRUE;
        m_wallpaper->suspend();
    }
}


void VappLauncherRobotDirector::resumeWallpaperForPenDown()
{
    if (m_isSuspendWallpaperForPenDown)
    {
        m_isSuspendWallpaperForPenDown = VFX_FALSE;
        delayResumeWallpaper(WALLPAPER_SWIPE_DELAY_TIME);
    }
}
#endif /* defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE) */


void VappLauncherRobotDirector::onNotificationCenterChanged(VappNCenterEventEnum event)
{
    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
            // For performance, suspend the wallpaper if the notification center
            // is active.
            if (!m_isWallpaperSuspendForNcenter)
            {
                if (m_wallpaper)
                {
                    m_wallpaper->suspend();
                }

                m_isWallpaperSuspendForNcenter = VFX_TRUE;
            }
            break;

        case VAPP_NCENTER_EVENT_EXITED:
            // For performance, resume the wallpaper after the notification
            // center is inactive. To avoid from the complication, we only
            // resume wallpaper when it had suspended because the notification
            // center entered.
            if (m_isWallpaperSuspendForNcenter)
            {
                if (m_wallpaper)
                {
                    delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
                }

                m_isWallpaperSuspendForNcenter = VFX_FALSE;
            }
            break;

        default:
            break;
    }
}


void VappLauncherRobotDirector::createDesktop()
{
    VFX_ASSERT(!m_desktop && !m_timerAutoSlideDesktop);

    VFX_OBJ_CREATE(m_desktop, VappLauncherRobotDesktop, m_dummyRootHS);
    m_desktop->m_signalPageChanged.connect(this, &VappLauncherRobotDirector::onDesktopPageChanged);
    m_desktop->m_signalPageSlide.connect(this, &VappLauncherRobotDirector::onDesktopPageSlide);
    m_desktop->m_signalPageSlideEnd.connect(this, &VappLauncherRobotDirector::onDesktopPageSlideEnd);

    // Timer to do auto. sliding when the widget is dragged to the left or right
    // side of the desktop.
    VFX_OBJ_CREATE(m_timerAutoSlideDesktop, VfxTimer, this);
    m_timerAutoSlideDesktop->setStartDelay(DND_PAGE_SWITCH_START_DELAY);
    m_timerAutoSlideDesktop->setDuration(DND_PAGE_SWITCH_NEXT_DELAY);
    m_timerAutoSlideDesktop->m_signalTick.connect(this, &VappLauncherRobotDirector::onAutoSlideDesktop);

    VFX_OBJ_CREATE(m_dummyDesktop, VfxFrame, this);
    m_dummyDesktop->setSize(getSize());
    m_dummyDesktop->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_tlSlideDummyDesktop, VfxS32Timeline, this);
    m_tlSlideDummyDesktop->setTarget(m_dummyDesktop);
    m_tlSlideDummyDesktop->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_X);
    m_tlSlideDummyDesktop->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    m_dummyDesktop->m_signalBoundsChanged.connect(this, &VappLauncherRobotDirector::onDesktopBoundsChanged);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    if(isRestoreStatus())
    {
        m_desktop->slideTo(s_curHSPageIndex, VFX_FALSE, 0);
    }
    else
#endif
    {
        // Centralize the desktop.
        m_desktop->slideToCentra(VFX_FALSE, 0);
    }

    VfxAutoAnimate::commit();
}


void VappLauncherRobotDirector::releaseDesktop()
{
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    s_curHSPageIndex = m_desktop->getCurrentPageIndex();
#endif
    VFX_OBJ_CLOSE(m_desktop);
    VFX_OBJ_CLOSE(m_timerAutoSlideDesktop);
    VFX_OBJ_CLOSE(m_dummyDesktop);
    VFX_OBJ_CLOSE(m_tlSlideDummyDesktop);
}


void VappLauncherRobotDirector::forbidSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.append(requester);
    }
}


void VappLauncherRobotDirector::permitSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.removeOne(requester);
    }
}


VfxBool VappLauncherRobotDirector::isSwipeForbidden()
{
    // Requester might be closed. Remove invalid requesters first.
    m_cannotSwipeRequest.removeAllInvalidate();

    return m_cannotSwipeRequest.isEmpty() ? VFX_FALSE : VFX_TRUE;
}


void VappLauncherRobotDirector::addFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.append(frame);
    }
}


void VappLauncherRobotDirector::removeFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.removeOne(frame);
    }
}


VfxBool VappLauncherRobotDirector::isFrameCannotSwipe(VfxFrame *frame)
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

            if (parent && isChildFrame(parent, frame) ||
                parent == frame)
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}


VfxBool VappLauncherRobotDirector::isFrameCannotSwipe(VfxObjList &frameList)
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


VfxBool VappLauncherRobotDirector::isChildFrame(
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


void VappLauncherRobotDirector::onDesktopPageChanged(VappLauncherRobotDesktop *desktop)
{
    VFX_ASSERT(m_desktop && m_desktop == desktop);

    // Notify menu bar that the current page index is changed.
    if(m_shortcutBar)
    {
        m_shortcutBar->setIndex(m_desktop->getCurrentPageIndex());
    }
}


void VappLauncherRobotDirector::onDesktopPageSlide(
    VappLauncherRobotDesktop *desktop,
    VfxS32 newDesktopBoundsOriginX,
    VfxS32 oldDesktopBoundsOriginX,
    VfxS32 duration)
{
    VFX_ASSERT(m_desktop && m_desktop == desktop);

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
    VfxRect bounds = m_dummyDesktop->getBounds();
    bounds.origin.x = newDesktopBoundsOriginX;
    m_dummyDesktop->setBounds(bounds);

    VfxAutoAnimate::commit();

    // suspend wallpaper when desktop swipe
#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    suspendWallpaperForSwipe();
#endif
}


void VappLauncherRobotDirector::onDesktopPageSlideEnd()
{
    // suspend wallpaper when desktop swipe
#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    resumeWallpaperForSwipe();
#endif
}


void VappLauncherRobotDirector::onDesktopBoundsChanged(
    VfxFrame *frame,
    const VfxRect &oldBounds)
{
    VFX_ASSERT(m_dummyDesktop && m_dummyDesktop == frame);

    VfxRect bounds = frame->getBounds();

#if defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    //
    // when desktop bounds exceeds max bounds x,
    // then the wallpaper will move (max_page-1)*x back to first page
    //
    VfxS32 maxX = bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1);
    if (bounds.origin.x < 0)
    {
        VfxS32 x = -bounds.origin.x;
        bounds.origin.x = (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1)*x;
    }
    else if (bounds.origin.x > maxX)
    {
        VfxS32 x = bounds.origin.x - maxX;
        bounds.origin.x = (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1) * (bounds.getWidth() - x);
    }
#else
    //
    // home desktop may exceeds max bounds for page transition effect,
    // but wallpaper does not expect to receive the bounds overflow,
    // so make sure the origin of the bounds doesn't exceed the value range to wallpaper.
    //
    if (bounds.origin.x < 0)
    {
        bounds.origin.x = 0;
    }
    else if (bounds.origin.x > bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1))
    {
        bounds.origin.x = bounds.getWidth() * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1);
    }
#endif

    VfxFrame *dummyFrame;
    VFX_OBJ_CREATE(dummyFrame, VfxFrame, this);
    dummyFrame->setBounds(bounds);

    // Notify wallpaper that desktop is moved.
    if (m_wallpaper)
    {
        m_wallpaper->setDesktopBoundsChanged(VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM, dummyFrame, oldBounds);
    }

    VFX_OBJ_CLOSE(dummyFrame);
}


void VappLauncherRobotDirector::onAutoSlideDesktop(VfxTimer *timer)
{
    if (!m_dndWidget)
    {
        return;
    }

    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr && m_desktop);

    // Get the pen point on the screen.
    VfxPoint pos = m_dndWidget->getPos();

    pos.x += m_penOffset.x;
    pos.y += m_penOffset.y;

    // Convert the point to the desktop.
    pos = mainScr->convertPointTo(pos, m_desktop);

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

#if !defined(VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT)
    if (idx <= 0 || idx >= VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM - 1)
    {
        timer->stop();
    }
#endif
}


void VappLauncherRobotDirector::createShortcutBar()
{
    VFX_ASSERT(!m_shortcutBar);

    // android type
    VFX_OBJ_CREATE(m_shortcutBar, VappLauncherRobotShortcutBar, m_dummyRootHS);

    m_shortcutBar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_shortcutBar->m_signalExecute.connect(this, &VappLauncherRobotDirector::onShortcutExecute);
    m_shortcutBar->setIndex(m_desktop->getCurrentPageIndex());
    m_shortcutBar->m_signalIndicatorClicked.connect(this, &VappLauncherRobotDirector::onIndicatorClicked);
    m_shortcutBar->m_signalIndicatorLongPressed.connect(this, &VappLauncherRobotDirector::onIndicatorLongPressed);

    // Forbid the desktop swipping if the pen event is on the shortcut bar.
    addFrameCannotSwipe(m_shortcutBar);
}


void VappLauncherRobotDirector::releaseShortcutBar()
{
    VFX_OBJ_CLOSE(m_shortcutBar);
}


void VappLauncherRobotDirector::createMainMenu()
{
    if(!m_mainmenu)
    {
        VFX_OBJ_CREATE(m_mainmenu, VappLauncherRobotMainmenuPage, this);
        m_mainmenu->setSize(getSize());
        m_mainmenu->m_signalSendIcon.connect(this, &VappLauncherRobotDirector::onLongPressedMMCell);
        m_mainmenu->setBgColor(VFX_COLOR_BLUE);
        m_mainmenu->m_homeClicked.connect(this, &VappLauncherRobotDirector::onClickedHomeOnMainMenu);
        m_mainmenu->setOpacity(0);
        m_mainmenu->setIsUnhittable(VFX_TRUE);
        m_mainmenu->m_menu->setFocused(VFX_FALSE);

        addFrameCannotSwipe(m_mainmenu);
    }

    if(!m_tlMMSSE)
    {
        VFX_OBJ_CREATE(m_tlMMSSE, VfxFloatTimeline, this);
        m_tlMMSSE->setTarget(m_mainmenu);
        m_tlMMSSE->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_tlMMSSE->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlMMSSE->setDuration(200);
        m_tlMMSSE->m_signalStopped.connect(this, &VappLauncherRobotDirector::onMMSSEFinished);

    }
    
    if(!m_tlHSSSE)
    {
        VFX_OBJ_CREATE(m_tlHSSSE, VfxFloatTimeline, this);
        m_tlHSSSE->setTarget(m_dummyRootHS);
        m_tlHSSSE->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_tlHSSSE->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlHSSSE->setDuration(200);
        m_tlHSSSE->m_signalStopped.connect(this, &VappLauncherRobotDirector::onHSSSEFinished);
    }

}


void VappLauncherRobotDirector::releaseMainmenu()
{
    m_mainmenu->m_signalSendIcon.disconnect(this, &VappLauncherRobotDirector::onLongPressedMMCell);
    m_mainmenu->m_homeClicked.disconnect(this, &VappLauncherRobotDirector::onClickedHomeOnMainMenu);
    VFX_OBJ_CLOSE(m_mainmenu);

    VFX_OBJ_CLOSE(m_tlMMSSE);
    VFX_OBJ_CLOSE(m_tlHSSSE);
}


void VappLauncherRobotDirector::onHSSSEFinished(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    VfxFloatTimeline *tl = (VfxFloatTimeline *)timeline;
    VfxFloat toValue = tl->getToValue();

    m_dummyRootHS->setCacheMode(VFX_CACHE_MODE_AUTO);
    m_dummyRootHS->setOpacity(toValue);
}


void VappLauncherRobotDirector::onMMSSEFinished(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    VfxFloatTimeline *tl = (VfxFloatTimeline *)timeline;
    VfxFloat toValue = tl->getToValue();

    if (toValue == 1.0f)
    {
        m_mainmenu->m_signalReadyToShow.emit();
    }
    
    m_mainmenu->setCacheMode(VFX_CACHE_MODE_AUTO);
    m_mainmenu->setOpacity(toValue);
}


void VappLauncherRobotDirector::showMainMenu(VfxBool isShow, VfxBool isAutoAnimate)
{
    VFX_ASSERT(m_mainmenu);
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    s_isShowMainmenu = isShow;
#endif

    // handle page transition part
    if(!isAutoAnimate)
    {
        if(isShow)
        {
            m_desktop->exitDesktop();
            m_mainmenu->m_signalReadyToShow.emit();
            m_mainmenu->setOpacity(1.0);
            m_dummyRootHS->setOpacity(0.0);
        }
        else
        {
            m_desktop->enterDesktop();
            m_mainmenu->setOpacity(0.0);
            m_dummyRootHS->setOpacity(1.0);  
        }
    }
    else
    {
        m_mainmenu->setCacheMode(VFX_CACHE_MODE_FREEZE);
        m_dummyRootHS->setCacheMode(VFX_CACHE_MODE_FREEZE);

        if(isShow)
        {
            m_desktop->exitDesktop();
            m_tlHSSSE->setFromValue(m_dummyRootHS->getOpacity());
            m_tlHSSSE->setToValue(0.0);
            m_tlHSSSE->start();
            
            m_tlMMSSE->setFromValue(m_mainmenu->getOpacity());
            m_tlMMSSE->setToValue(1.0);
            m_tlMMSSE->start();
        }
        else
        {
            m_desktop->enterDesktop();
            m_tlHSSSE->setFromValue(m_dummyRootHS->getOpacity());
            m_tlHSSSE->setToValue(1.0);
            m_tlHSSSE->start();
            
            m_tlMMSSE->setFromValue(m_mainmenu->getOpacity());
            m_tlMMSSE->setToValue(0.0);
            m_tlMMSSE->start();
        }
    }

    // handle behavior part
    if(isShow)
    {
        m_mainmenu->m_menu->setFocused(VFX_TRUE);
        m_mainmenu->setIsUnhittable(VFX_FALSE);
        m_mainmenu->setRectToVisible();

        if(!m_isWallpaperSuspendForMM)
        {
            if(m_wallpaper)
            {
                m_wallpaper->suspend();
            }
            suspendWidget();
            m_isWallpaperSuspendForMM = VFX_TRUE;
        }
    }
    else
    {
        m_mainmenu->setIsUnhittable(VFX_TRUE);
        m_mainmenu->m_menu->setFocused(VFX_FALSE);
        if (m_isWallpaperSuspendForMM)
        {
            if(m_wallpaper)
            {
                m_wallpaper->resume();
            }
            resumeWidget();
            m_isWallpaperSuspendForMM = VFX_FALSE;
        }
    }
}


void VappLauncherRobotDirector::onShortcutExecute(
        VappLauncherRobotShortcutBar::ButtonEnum buttonId)
{
    switch (buttonId)
    {
        case VappLauncherRobotShortcutBar::BUTTON_DIALER:
            vfxPostInvoke(this, &VappLauncherRobotDirector::launchDialer);
            break;

        case VappLauncherRobotShortcutBar::BUTTON_MAINMENU:
            showMainMenu(VFX_TRUE);
            break;

#ifdef __MMI_GB_WINGUO__
        case VappLauncherRobotShortcutBar::BUTTON_WINGUO:
            vfxPostInvoke(this, &VappLauncherRobotDirector::launchWinguo);
            break;
#else
        case VappLauncherRobotShortcutBar::BUTTON_BROWSER:
            vfxPostInvoke(this, &VappLauncherRobotDirector::launchBrowser);
            break;
#endif
        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappLauncherRobotDirector::onClickedHomeOnMainMenu()
{
    showMainMenu(VFX_FALSE);
}


void VappLauncherRobotDirector::onLongPressedMMCell(
                                    VfxChar *package,
                                    VfxPoint offset)
{
    VappWidgetId widgetId = VappWidgetId(VAPP_WIDGET_SRC_SHORTCUT, srv_appmgr_get_id_by_app_package_name(package));
    if(isShortcutCreated(widgetId))
    {
        // TODO: modify string, should be the same shortcut already be created
        displayErrorPopup(
            VCP_POPUP_TYPE_INFO,
            VCP_CONFIRM_BUTTON_SET_OK,
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_ALREADY_EXIT));

        return;
    }

    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);

    //
    // Create widget.
    //
    VappWidgetKit *kit;

    kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    VappWidget *widget;
    widget = kit->createWidget(
                            VappWidgetId(VAPP_WIDGET_SRC_SHORTCUT, srv_appmgr_get_id_by_app_package_name(package)),
                            m_dummyRootHS);
    m_penOffset.x = offset.x - widget->getSize().width/2;
    m_penOffset.y = offset.y - widget->getSize().height/2;

    //
    // If all pages cannot add this widget, display a error popup.
    //
    if (!m_desktop->canAddToPageIfAny(widget))
    {
        VFX_OBJ_CLOSE(widget);
        widget = NULL;

        displayErrorPopup(
            VCP_POPUP_TYPE_INFO,
            VCP_CONFIRM_BUTTON_SET_OK,
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_ALL_PAGE_FULL));

        return;
    }

    VFX_ASSERT(!m_isCreatWidgetFromMM);
    m_isCreatWidgetFromMM = VFX_TRUE;
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_desktop->addChildFrame(widget);
    widget->createView();
    activateWidget(widget);

    VfxAutoAnimate::commit();

    // widget enter dragged mode directly if it is created
    // by put app icon from MM
    widget->setWidgetDragged(VFX_TRUE);

    // after widget created, it will capture pen from HS, then
    // widget will follow the same flow with the scenario
    // of drag widget from HS
    widget->processPenCapture();
    
    // after put app icon to HS,
    // MM will disappear with fade out animation
    showMainMenu(VFX_FALSE);
}


void VappLauncherRobotDirector::onIndicatorLongPressed()
{
    launchPageSelector();
}


void VappLauncherRobotDirector::onIndicatorClicked(VfxS32 direction)
{
    if (direction > 0)
    {
        m_desktop->slideToNext();
    }
    else if (direction < 0)
    {
        m_desktop->slideToPrevious();
    }
}


VfxBool VappLauncherRobotDirector::isShortcutCreated(VappWidgetId widgetId)
{
    //
    // For shortcuts that are already present on the desktop, we do not allow
    // the users to create them again.
    //
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);
        if (!widget)
        {
            continue;
        }

        VappWidgetId id = widget->getId();

        if (id == widgetId)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void VappLauncherRobotDirector::createToolbar()
{
    VFX_ASSERT(!m_toolbar);

    VFX_OBJ_CREATE(m_toolbar, VappLauncherRobotToolbar, m_dummyRootHS);
    m_toolbar->fold();
    m_toolbar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_toolbar->m_signalExecute.connect(this, &VappLauncherRobotDirector::onToolbarExecute);

    // Forbid the desktop swipping if the pen event is on the toolbar.
    addFrameCannotSwipe(m_toolbar);
}


void VappLauncherRobotDirector::releaseToolbar()
{
    VFX_OBJ_CLOSE(m_toolbar);
}


void VappLauncherRobotDirector::onToolbarExecute(
    VappLauncherRobotToolbar *toolbar,
    VappLauncherRobotToolbar::ButtonEnum button)
{
    VFX_ASSERT(toolbar && toolbar == m_toolbar);

    switch (button)
    {
        case VappLauncherRobotToolbar::BUTTON_ADD_WIDGET:
            launchWidgetSelector();
            break;

        case VappLauncherRobotToolbar::BUTTON_ADD_SHORTCUT:
            launchShortcutSelector();
            break;

        case VappLauncherRobotToolbar::BUTTON_SET_WALLPAPER:
            vapp_setting_launch_by_hdlr(onPushWallpaperSettingPage);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappLauncherRobotDirector::onPushWallpaperSettingPage(VfxMainScr *mainScr)
{
    mainScr->setTransitType(VFX_SCR_TRANSIT_TYPE_SCR);
    vapp_setting_home_screen_wallpaper_setting_launch(mainScr);
}


void VappLauncherRobotDirector::createTrashCanBar()
{
    VFX_ASSERT(!m_trashCanBar);

    VFX_OBJ_CREATE(m_trashCanBar, VappLauncherRobotTrashCanBar, m_dummyRootHS);
    m_trashCanBar->fold();
    m_trashCanBar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);

    // Forbid the desktop swipping if the pen event is on the toolbar.
    addFrameCannotSwipe(m_trashCanBar);
}


void VappLauncherRobotDirector::releaseTrashCanBar()
{
    VFX_OBJ_CLOSE(m_trashCanBar);
}


void VappLauncherRobotDirector::toggleWidgetLayoutMode(VfxBool isOn, VfxBool isAnimatable)
{
    if (isOn)
    {
        m_shortcutBar->fold(isAnimatable);
        m_toolbar->fold(isAnimatable);
        m_trashCanBar->unfold(isAnimatable);
    }
    else if (!isOn && m_isInEditMode)
    {
        m_shortcutBar->fold(isAnimatable);
        m_toolbar->unfold(isAnimatable);
        m_trashCanBar->fold(isAnimatable);
    }
    else if (!isOn && !m_isInEditMode)
    {
        m_shortcutBar->unfold(isAnimatable);
        m_toolbar->fold(isAnimatable);
        m_trashCanBar->fold(isAnimatable);
    }
}


void VappLauncherRobotDirector::toggleEditMode(VfxBool isOn, VfxBool isAnimatable)
{
    if (isOn && !m_isInEditMode)
    {
        m_shortcutBar->fold(isAnimatable);
        m_toolbar->unfold(isAnimatable);

        m_isInEditMode = VFX_TRUE;
    }
    else if (!isOn && m_isInEditMode)
    {
        m_shortcutBar->unfold(isAnimatable);
        m_toolbar->fold(isAnimatable);

        m_isInEditMode = VFX_FALSE;
    }
}


void VappLauncherRobotDirector::closePageSelector(VappLauncherRobotPageSelector::AbortCauseEnum causeEnum)
{
    //
    // Close all page selectors.
    //
    if (m_pageSelector)
    {
        m_pageSelector->m_signalAborted.emit(
            m_pageSelector,
            causeEnum);
    }

    if (m_pageSelectorDnd)
    {
        m_pageSelectorDnd->m_signalAborted.emit(
            m_pageSelectorDnd,
            causeEnum);
    }

    if (m_pageSelectorOos)
    {
        m_pageSelectorOos->m_signalAborted.emit(
            m_pageSelectorOos,
            causeEnum);
    }
}


void VappLauncherRobotDirector::launchPageSelector()
{
    VAPP_LAUNCHER_ROBOT_SLA(("HP0", SA_start));

    //
    // Fold or suspend other UI component to speed-up the animation.
    //
    m_wallpaper->suspend();
    setBarFolding(VFX_TRUE);
    setWidgetSlim(VFX_TRUE);
    m_shortcutBar->hideIndicator(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelector == NULL);
    m_pageSelector = createPageSelector();

    m_pageSelector->m_signalAssembled.connect(this, &VappLauncherRobotDirector::onPageSelectorAssembled);
    m_pageSelector->m_signalSelected.connect(this, &VappLauncherRobotDirector::onPageSelectorSelected);
    m_pageSelector->m_signalAborted.connect(this, &VappLauncherRobotDirector::onPageSelectorAborted);
    m_pageSelector->m_signalDismissed.connect(this, &VappLauncherRobotDirector::onPageSelectorDismissed);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelector->assemble();
    VfxAutoAnimate::initAnimateEnd();

    VAPP_LAUNCHER_ROBOT_SLA(("HP0", SA_stop));
}


void VappLauncherRobotDirector::onPageSelectorAssembled(
    VappLauncherRobotPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Assembling completes. Resume the heavy UI components.
    //

    // At present, keep heavy UI component, e.g. wallpaper, stopped because the
    // performance is still not good enough.
}


void VappLauncherRobotDirector::onPageSelectorSelected(
    VappLauncherRobotPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

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


void VappLauncherRobotDirector::onPageSelectorAborted(
    VappLauncherRobotPageSelector *pageSelector,
    VappLauncherRobotPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappLauncherRobotPageSelector::ABORT_CAUSE_HOME_KEY &&
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


void VappLauncherRobotDirector::onPageSelectorDismissed(
    VappLauncherRobotPageSelector *pageSelector)
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
    m_shortcutBar->hideIndicator(VFX_FALSE);
}


void VappLauncherRobotDirector::launchPageSelectorOos(VappWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
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
    m_shortcutBar->hideIndicator(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelectorOos == NULL);
    m_pageSelectorOos = createPageSelector();

    m_pageSelectorOos->m_signalAssembled.connect(this, &VappLauncherRobotDirector::onPageSelectorOosAssembled);
    m_pageSelectorOos->m_signalSelected.connect(this, &VappLauncherRobotDirector::onPageSelectorOosSelected);
    m_pageSelectorOos->m_signalAborted.connect(this, &VappLauncherRobotDirector::onPageSelectorOosAborted);
    m_pageSelectorOos->m_signalDismissed.connect(this, &VappLauncherRobotDirector::onPageSelectorOosDismissed);

    m_pageSelectorOos->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorOos->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappLauncherRobotDirector::onPageSelectorOosAssembled(
    VappLauncherRobotPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
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


void VappLauncherRobotDirector::onPageSelectorOosSelected(
    VappLauncherRobotPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

    //
    // If the user taps a page without available spaces for this widget, display
    // an error popup.
    //
    if (m_isPageFull[idx])
    {
        displayErrorPopup(
            VCP_POPUP_TYPE_INFO,
            VCP_CONFIRM_BUTTON_SET_OK,
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_UNAVAILABLE));

        pageSelector->revive();

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


void VappLauncherRobotDirector::onPageSelectorOosAborted(
    VappLauncherRobotPageSelector *pageSelector,
    VappLauncherRobotPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    //
    // Operation aborted. Close the widget.
    //
    VappWidget *widget = (VappWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    widget->releaseView();
    VFX_OBJ_CLOSE(widget);

    pageSelector->setId(VFX_ID_NULL);

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappLauncherRobotPageSelector::ABORT_CAUSE_HOME_KEY &&
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


void VappLauncherRobotDirector::onPageSelectorOosDismissed(
    VappLauncherRobotPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    VappWidget *widget = (VappWidget *)pageSelector->getId();
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
    m_shortcutBar->hideIndicator(VFX_FALSE);

    //
    // Activate the widget on the desktop if the operation is not aborted, e.g.,
    // the 'widget' pointer is valid. If this dismissing operation is because
    // the user abort the page selector, 'selectedIndex' will be -1 and 'widget'
    // will be NULL because it is closed already in onPageSelectorOosAborted.
    //
    if (widget &&
        selectedIndex >= 0 &&
        selectedIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM)
    {
        VFX_OBJ_ASSERT_VALID(widget);
        VFX_ASSERT(m_desktop->canAddToPage(widget, selectedIndex));
        activateWidgetOnDesktop(widget, selectedIndex);
    }
}


void VappLauncherRobotDirector::launchPageSelectorDnd(VappWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
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
    m_shortcutBar->hideIndicator(VFX_TRUE);

    //
    // Create the page selector.
    //
    VFX_ASSERT(m_pageSelectorDnd == NULL);
    m_pageSelectorDnd = createPageSelector();

    m_pageSelectorDnd->m_signalAssembled.connect(this, &VappLauncherRobotDirector::onPageSelectorDndAssembled);
    m_pageSelectorDnd->m_signalSelected.connect(this, &VappLauncherRobotDirector::onPageSelectorDndSelected);
    m_pageSelectorDnd->m_signalAborted.connect(this, &VappLauncherRobotDirector::onPageSelectorDndAborted);
    m_pageSelectorDnd->m_signalDismissed.connect(this, &VappLauncherRobotDirector::onPageSelectorDndDismissed);

    m_pageSelectorDnd->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorDnd->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappLauncherRobotDirector::onPageSelectorDndAssembled(
    VappLauncherRobotPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
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


void VappLauncherRobotDirector::onPageSelectorDndSelected(
    VappLauncherRobotPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM);

    //
    // If the user drop the widget to a page without available spaces, abort
    // the operation.
    //
    if (m_isPageFull[idx])
    {
        onPageSelectorDndAborted(
            pageSelector,
            VappLauncherRobotPageSelector::ABORT_CAUSE_DROP_OUTSIDE);

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
    VappWidget *widget = (VappWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    widget->setIsUnhittable(VFX_TRUE);
}


void VappLauncherRobotDirector::onPageSelectorDndAborted(
    VappLauncherRobotPageSelector *pageSelector,
    VappLauncherRobotPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappLauncherRobotPageSelector::ABORT_CAUSE_HOME_KEY &&
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
    VappWidget *widget = (VappWidget *)pageSelector->getId();
    VFX_OBJ_ASSERT_VALID(widget);

    widget->setIsUnhittable(VFX_TRUE);
}


void VappLauncherRobotDirector::onPageSelectorDndDismissed(
    VappLauncherRobotPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    VappWidget *widget = (VappWidget *)pageSelector->getId();
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
    m_shortcutBar->hideIndicator(VFX_FALSE);

    //
    // Animate the widget to its final position. If the user doesn't correctly
    // drop the widget to a page with enough space, 'selectedIndex' will be -1.
    //
    if (selectedIndex >= 0 && selectedIndex < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM &&
        m_desktop->canAddToPage(widget, selectedIndex))
    {
        m_desktop->addToPage(widget, selectedIndex);
    }
    else
    {
        if(m_isCreatWidgetFromMM)
        {
            onDeselectWidget(widget);
            m_isCreatWidgetFromMM = VFX_FALSE;

            if(selectedIndex!=-1)
            {
                displayErrorPopup(
                    VCP_POPUP_TYPE_INFO,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_UNAVAILABLE));
            }
            return;
        }

        widget->restorePosition();
        m_desktop->addToNearest(widget, m_widgetPageIndex);
    }

    // Dismiss animation is done. Recovery the widget to hittable.
    widget->setIsUnhittable(VFX_FALSE);

    // Update widget's position.
    save();

    m_isCreatWidgetFromMM = VFX_FALSE;
}


VappLauncherRobotPageSelector *VappLauncherRobotDirector::createPageSelector()
{
    VappLauncherRobotPageSelector *pageSelector;

    VFX_OBJ_CREATE(pageSelector, VappLauncherRobotPageSelector, m_dummyRootHS);
    pageSelector->setFocused(VFX_TRUE);

    //
    // Add widgets to the page selector.
    //
    packWidgetToPageSelector(pageSelector);

    return pageSelector;
}


void VappLauncherRobotDirector::closePageSelector(VappLauncherRobotPageSelector *pageSelector)
{
    //
    // Restore all frame to each page.
    //
    unpackWidgetFromPageSelector(pageSelector);

    VFX_OBJ_CLOSE(pageSelector);
}


void VappLauncherRobotDirector::packWidgetToPageSelector(
    VappLauncherRobotPageSelector *pageSelector)
{
    VfxS32 currentPageIndex = m_desktop->getCurrentPageIndex();
    VfxObjList objList;

    pageSelector->setFocusSnapshot(currentPageIndex);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        VfxRect sourceRect = m_desktop->getPageRect(i);

        pageSelector->setSnapshotLayout(i, sourceRect);

        objList.clear();
        m_desktop->getFromPage(i, objList);

        for (VfxObjListEntry *entry = objList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

            if (widget)
            {
                pageSelector->addToSnapshot(i, widget);
            }
        }
    }
}


void VappLauncherRobotDirector::unpackWidgetFromPageSelector(
    VappLauncherRobotPageSelector *pageSelector)
{
    VfxObjList objList;

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM; i++)
    {
        objList.clear();
        pageSelector->removeFromSnapshot(i, objList);

        for (VfxObjListEntry *entry = objList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

            if (widget)
            {
                m_desktop->addToNearest(widget, i);
            }
        }
    }
}


VfxBool VappLauncherRobotDirector::isPageSelectorPresent()
{
    if (m_pageSelector || m_pageSelectorOos || m_pageSelectorDnd)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappLauncherRobotDirector::launchShortcutSelector()
{
    VAPP_LAUNCHER_ROBOT_SLA(("HS0", SA_start));

    //
    // Create the shortcut selector page.
    //
    // For performance, we delay the display of the page's content until the
    // page transition is completed. Otherwise, because VRT might be quitely
    // busy now, e.g. live wallpaper, sorting the shortcuts will take a long
    // time.
    //
    VFX_OBJ_CREATE(m_shortcutSelector, VappLauncherRobotShortcutSelector, this);
    m_shortcutSelector->m_signalSelected.connect(this, &VappLauncherRobotDirector::onWidgetSelected);
    m_shortcutSelector->m_signalTransitionStop.connect(this, &VappLauncherRobotDirector::onShowShortcutSelector);

    // Push page into the screen.
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);
    VfxPage *topPage = mainScr->getPage(mainScr->getTopPageId() );

    //
    // use specific page transition to avoid clear HS cache,
    // or it will spend a lot of time to decode image when back from shortcut selector/ widget selector page
    //
    VfxLauncherRobotPageSlideTransition *transition;
    VFX_OBJ_CREATE(transition, VfxLauncherRobotPageSlideTransition, this);
    transition->m_signalStopped.connect(this, &VappLauncherRobotDirector::onLeaveLauncherPageTransition);
    topPage->setTransition(transition);
    m_pageSlideTransitionWeakPtr = transition;

    mainScr->pushPage(0, m_shortcutSelector);

    VAPP_LAUNCHER_ROBOT_SLA(("HS0", SA_stop));
}


void VappLauncherRobotDirector::onLeaveLauncherPageTransition(VfxBool in, VfxS32 direction)
{
    if (in)
    {
        VfxMainScr *mainScr;
        mainScr = VfxMainScr::findMainScr(getParentFrame());
        VFX_ASSERT(mainScr);
        VfxPage * topPage = mainScr->getPage(mainScr->getTopPageId() );
        topPage->setTransition(NULL);
    }
}


void VappLauncherRobotDirector::onShowShortcutSelector(
    VfxObject *sender,
    VfxBool in,
    VfxS32 direction)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HS1", SA_start));

    VFX_ASSERT(sender && sender == m_shortcutSelector);

    // This handler should be called when the page is going to show and the
    // history direction is positive.
    if (in != VFX_TRUE || direction <= 0)
    {
        return;
    }

    m_shortcutSelector->m_signalTransitionStop.disconnect(this, &VappLauncherRobotDirector::onShowShortcutSelector);

    m_widgetList.removeAllInvalidate();
    VfxS32 entryCount = m_widgetList.getEntryCount();
    VappWidgetId **widgetId = VappWidgetId::newArray(entryCount, this);
    VfxS32 totalNum = 0;

    //
    // For shortcuts that are already present on the desktop, we do not allow
    // the users to select them again.
    //
    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);
        if (!widget)
        {
            continue;
        }

        VappWidgetId id = widget->getId();

        if (id.getSource() == VAPP_WIDGET_SRC_SHORTCUT)
        {
            VFX_ASSERT(totalNum < entryCount);
            widgetId[totalNum++]->assignWith(id);
        }
    }

    m_shortcutSelector->setBlockedList(widgetId, totalNum);

    VappWidgetId::deleteArray(widgetId, entryCount);

    //
    // Show the page.
    //
    m_shortcutSelector->show();

    VAPP_LAUNCHER_ROBOT_SLA(("HS1", SA_stop));
}


void VappLauncherRobotDirector::launchWidgetSelector()
{
    VAPP_LAUNCHER_ROBOT_SLA(("HW0", SA_start));

    //
    // Create the widget selector page.
    //
    // For performance, we delay the display of this page's content until the
    // page transition is completed. Otherwise, because VRT might be quitely
    // busy now, e.g. live wallpaper, sorting the shortcuts will take a long
    // time.
    //
    VFX_OBJ_CREATE(m_widgetSelector, VappLauncherRobotWidgetSelector, this);
    m_widgetSelector->m_signalSelected.connect(this, &VappLauncherRobotDirector::onWidgetSelected);
    m_widgetSelector->m_signalTransitionStop.connect(this, &VappLauncherRobotDirector::onShowWidgetSelector);

    // Push page into the screen.
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);
    VfxPage *topPage = mainScr->getPage(mainScr->getTopPageId() );

    //
    // use specific page transition to avoid clear HS cache,
    // or it will spend a lot of time to decode image when back from shortcut selector/ widget selector page
    //
    VfxLauncherRobotPageSlideTransition *transition;
    VFX_OBJ_CREATE(transition, VfxLauncherRobotPageSlideTransition, this);
    transition->m_signalStopped.connect(this, &VappLauncherRobotDirector::onLeaveLauncherPageTransition);
    topPage->setTransition(transition);
    m_pageSlideTransitionWeakPtr = transition;

    mainScr->pushPage(0, m_widgetSelector);

    VAPP_LAUNCHER_ROBOT_SLA(("HW0", SA_stop));
}


void VappLauncherRobotDirector::onShowWidgetSelector(
    VfxObject *sender,
    VfxBool in,
    VfxS32 direction)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HW1", SA_start));

    VFX_ASSERT(sender && sender == m_widgetSelector);

    // This handler should be called when the page is going to show and the
    // history direction is positive.
    if (in != VFX_TRUE || direction <= 0)
    {
        return;
    }

    m_widgetSelector->m_signalTransitionStop.disconnect(this, &VappLauncherRobotDirector::onShowWidgetSelector);

    //
    // For widgets that are already present, we do not allow the user to select
    // them again.
    //
    m_widgetList.removeAllInvalidate();

    VfxS32 entryCount = m_widgetList.getEntryCount();

    if (entryCount > 0)
    {
        VappWidgetId **widgetId = VappWidgetId::newArray(entryCount, this);
        VfxS32 totalNum = 0;

        for (VfxObjListEntry *entry = m_widgetList.getHead();
             entry != NULL;
             entry = entry->getNext())
        {
            VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);
            if (!widget)
            {
                continue;
            }

            VappWidgetId id = widget->getId();

            if (id.getSource() != VAPP_WIDGET_SRC_SHORTCUT)
            {
                VFX_ASSERT(totalNum < entryCount);
                widgetId[totalNum++]->assignWith(id);
            }
        }

        m_widgetSelector->setBlockedList(widgetId, totalNum);

        VappWidgetId::deleteArray(widgetId, entryCount);
    }

    //
    // Show the page.
    //
    m_widgetSelector->show();

    VAPP_LAUNCHER_ROBOT_SLA(("HW1", SA_stop));
}


void VappLauncherRobotDirector::onWidgetSelected(
    VfxPage *page,
    const VappWidgetId &widgetId)
{
    //
    // Create widget.
    //
    VappWidgetKit *kit;

    kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    VFX_ASSERT(!m_selectedWidget); // to detect memory leak.
    m_selectedWidget = kit->createWidget(widgetId, m_dummyRootHS);

    if (m_selectedWidget)
    {
        if( widgetId.getSource() == VAPP_WIDGET_SRC_SHORTCUT &&
            m_numShortcut == VAPP_LAUNCHER_ROBOT_MAX_SHORTCUT_WIDGET_NUM)
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_CANNOT_ADD_MORE_SHORTCUT));
            VFX_OBJ_CLOSE(m_selectedWidget);
        }
        else
        {
            // Widget's final parent frame will be determined later.
            m_selectedWidget->removeFromParentFrame();

            // For performance, we install the widget on the desktop until the page
            // transition animation stops.
            page->m_signalTransitionStop.connect(this, &VappLauncherRobotDirector::onInstallWidget);

            if(widgetId.getSource() == VAPP_WIDGET_SRC_SHORTCUT)
            {
                m_numShortcut++;
            }
        }
    }

    //
    // Close the selector.
    //
    page->exit();
}


void VappLauncherRobotDirector::onInstallWidget(
    VfxObject* sender,
    VfxBool in,
    VfxS32 direction)
{
    VFX_UNUSED(sender);
    VFX_UNUSED(in);
    VFX_UNUSED(direction);

    VFX_OBJ_ASSERT_VALID(m_selectedWidget);

    VappWidget *widget = m_selectedWidget;
    m_selectedWidget = NULL;

    //
    // Create View. If failed, display a error popup.
    //
    VfxWString errorString;

    widget->createView();

    if (widget->getCreateViewFailure(errorString))
    {
        VFX_OBJ_CLOSE(widget);

        displayErrorPopup(
            VCP_POPUP_TYPE_FAILURE,
            VCP_CONFIRM_BUTTON_SET_OK,
            errorString.getBuf());

        return;
    }

    //
    // If all pages cannot add this widget, display a error popup.
    //
    if (!m_desktop->canAddToPageIfAny(widget))
    {
        widget->releaseView();
        VFX_OBJ_CLOSE(widget);

        displayErrorPopup(
            VCP_POPUP_TYPE_INFO,
            VCP_CONFIRM_BUTTON_SET_OK,
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_ALL_PAGE_FULL));

        return;
    }

    //
    // If the current page can contain this widget, add it.
    //
    if (m_desktop->canAddToPage(widget, m_desktop->getCurrentPageIndex()))
    {
        activateWidgetOnDesktop(widget, m_desktop->getCurrentPageIndex());
        return;
    }

    //
    // At least one page can contain this widget. Display the page selector for
    // the user to select a feasible page.
    //
    launchPageSelectorOos(widget);
}


void VappLauncherRobotDirector::createWidget()
{
    if (isNewSetting())
    {
        //
        // Create the pre-installed widgets.
        //
        createPreInstalledWidget();

        setIsNewSetting(VFX_FALSE);
    }
    else
    {
        //
        // Create all widgets which are present in the archive.
        //
        if(m_widgetSettingDataPtr)
        {
            createArchivedWidgetFromRAM();
        }
        else
        {
            createArchivedWidget();
        }
    }

#if defined(__COSMOS_3D_V10__)
    //
    // Color Material
    //
    VFX_OBJ_CREATE(m_alertMaterial, VappLauncherRobotColorMaterial, this);
#else
    //
    // Color Filter
    //
    VFX_OBJ_CREATE(m_alertFilter, VappLauncherRobotColorFilter, this);
    m_alertFilter->setColorFilter(s_alertFilterMin, s_alertFilterMax);
#endif /* !defined(__COSMOS_3D_V10__) */

    //
    // Timer to launch page selector if the user drags the widget to stay on
    // some pre-defined UI component.
    //
    VFX_OBJ_CREATE(m_timerLaunchPageSelectorDnd, VfxTimer, this);
    m_timerLaunchPageSelectorDnd->setStartDelay(DND_PAGE_SELECTOR_START_DELAY);
    m_timerLaunchPageSelectorDnd->m_signalTick.connect(this, &VappLauncherRobotDirector::onLaunchPageSelectorDnd);
}


void VappLauncherRobotDirector::createPreInstalledWidget()
{
    VappLauncherRobotPreinstaller *preinstaller;

    VFX_OBJ_CREATE(preinstaller, VappLauncherRobotPreinstaller, this);

    VfxS32 num = preinstaller->getPreInstalledNum();

    if (num <= 0) // no pre-installed widgets.
    {
        VFX_OBJ_CLOSE(preinstaller);
        return;
    }

    //
    // Get the pre-installed widgets information.
    //
    VappWidgetPreInstalled **preInstalled;

    VFX_ALLOC_MEM(preInstalled, num * sizeof(VappWidgetPreInstalled *), this);

    for (VfxS32 i = 0; i < num; i++)
    {
        VFX_ALLOC_NEW(preInstalled[i], VappWidgetPreInstalled, this);
    }

    VfxS32 realNum = preinstaller->getPreInstalledWidget(preInstalled, num);
    VFX_ASSERT(num == realNum);

    VFX_OBJ_CLOSE(preinstaller);

    //
    // Create the pre-installed widgets.
    //
    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    for (VfxS32 i = 0; i < num; i++)
    {
        //
        // Create the pre-installed widget.
        //
        VappWidget *widget = kit->createWidget(preInstalled[i]->m_id, m_dummyRootHS);
        if (!widget)
        {
            continue;
        }
        
        if(preInstalled[i]->m_id.getSource() == VAPP_WIDGET_SRC_SHORTCUT)
        {
            m_numShortcut++;
        }

        //
        // Create View. If failed, close it and process the next one.
        //
        VfxWString errorString;

        widget->createView();

        if (widget->getCreateViewFailure(errorString))
        {
            VFX_OBJ_CLOSE(widget);
            continue;
        }

        //
        // Set the pre-installed widget's position.
        //
        VfxPoint pos;

        pos.x = preInstalled[i]->m_pos.x;
        pos.y = preInstalled[i]->m_pos.y;
        widget->setPos(pos);

        //
        // Activate the widget and put it on the desktop.
        //
        if (!m_desktop->canAddToPageIfAny(widget))
        {
            widget->releaseView();
            VFX_OBJ_CLOSE(widget);
        }
        else
        {
            activateWidget(widget);
            m_desktop->addToDesktop(widget, preInstalled[i]->m_pageIdx);
        }
    }

    save();

    for (VfxS32 i = 0; i < num; i++)
    {
        VFX_DELETE(preInstalled[i]);
    }

    VFX_FREE_MEM(preInstalled);
}


void VappLauncherRobotDirector::createArchivedWidgetFromRAM()
{
    //
    // Create archive.
    //
    VfxArchive *ar;
    VFX_OBJ_CREATE(ar, VfxArchive, this);
    if (!ar)
    {
        return;
    }

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    VappWidgetId id;

    // read widget setting from buffer
    VFX_ASSERT(m_widgetSettingDataPtr);
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
    m_widgetArchiveSource->attachBuffer(m_widgetSettingDataPtr, m_widgetSettingDataSize);
    ar->setSource(m_widgetArchiveSource);

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_ROBOT_PAGE_NUM; i++)
    {
        VfxS32 totalNum = ar->readU8();

        for (VfxS32 i = 0; i < totalNum; i++)
        {
            //
            // Parse the archive.
            //
            VappWidgetId id;
            VfxS32 pageIndex;
            VfxPoint pos;

            // Widget ID.
            id.decodeFromArchive(ar);

            // page index of Widget
            pageIndex = ar->readU8();

            // Widget Position.
            ar->readPoint(pos);

            //
            // Create the widget.
            //
            VappWidget *widget = kit->createWidget(id, m_dummyRootHS);
            if (!widget)
            {
                continue;
            }

            if(id.getSource() == VAPP_WIDGET_SRC_SHORTCUT)
            {
                m_numShortcut++;
            }
            
            //
            // Create View. If failed, close it and process the next one.
            //
            VfxWString errorString;

            widget->createView();

            if (widget->getCreateViewFailure(errorString))
            {
                VFX_OBJ_CLOSE(widget);
                continue;
            }

            //
            // Activate the widget and put it on the desktop.
            //
            if (!m_desktop->canAddToPageIfAny(widget))
            {
                widget->releaseView();
                VFX_OBJ_CLOSE(widget);
            }
            else
            {
                activateWidget(widget);
                widget->setPos(pos);
                m_desktop->addToDesktop(widget, pageIndex);
            }
        }
    }
    m_widgetArchiveSource->detachBuffer(&m_widgetSettingDataPtr, &m_widgetSettingDataSize);
    
    VFX_OBJ_CLOSE(m_widgetArchiveSource);
    VFX_OBJ_CLOSE(ar);
}


void VappLauncherRobotDirector::createArchivedWidget()
{
    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    VappWidgetId id;

    VfxArchive *ar = createArchive(0, 'r');
    if (!ar)
    {
        return;
    }

    // read NVRAM info and write widget setting into memory to 
    // reduce launcher response time by reduce NVRAM access number
    
    //
    //Clear old widget setting data.
    //
    VFX_FREE_MEM(m_widgetSettingDataPtr);
    m_widgetSettingDataSize = 0;
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
    VFX_OBJ_CREATE_EX(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext), (VAPP_LAUNCHER_ROBOT_WIDGET_SETTING_DATA_SIZE));
#else
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif
    VfxArchive *archiveToRAM;
    VFX_OBJ_CREATE(archiveToRAM, VfxArchive, this);
    archiveToRAM->setSource(m_widgetArchiveSource);

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_ROBOT_PAGE_NUM; i++)
    {
        VfxS32 totalNum = ar->readU8();
        archiveToRAM->writeU8(totalNum);

        for (VfxS32 i = 0; i < totalNum; i++)
        {
            //
            // Parse the archive.
            //
            VappWidgetId id;
            VfxS32 pageIndex;
            VfxPoint pos;

            // Widget ID.
            id.decodeFromArchive(ar);
            id.encodeToArchive(archiveToRAM);

            // page index of Widget
            pageIndex = ar->readU8();
            archiveToRAM->writeU8(pageIndex);

            // Widget Position.
            ar->readPoint(pos);
            archiveToRAM->writePoint(pos);

            //
            // Create the widget.
            //
            VappWidget *widget = kit->createWidget(id, m_dummyRootHS);
            if (!widget)
            {
                continue;
            }

            if(id.getSource() == VAPP_WIDGET_SRC_SHORTCUT)
            {
                m_numShortcut++;
            }
            
            //
            // Create View. If failed, close it and process the next one.
            //
            VfxWString errorString;

            widget->createView();

            if (widget->getCreateViewFailure(errorString))
            {
                VFX_OBJ_CLOSE(widget);
                continue;
            }

            //
            // Activate the widget and put it on the desktop.
            //
            if (!m_desktop->canAddToPageIfAny(widget))
            {
                widget->releaseView();
                VFX_OBJ_CLOSE(widget);
            }
            else
            {
                activateWidget(widget);
                widget->setPos(pos);
                m_desktop->addToDesktop(widget, pageIndex);
            }
        }
    }
    m_widgetArchiveSource->detachBuffer(&m_widgetSettingDataPtr, &m_widgetSettingDataSize);
    
    VFX_OBJ_CLOSE(ar);
    VFX_OBJ_CLOSE(m_widgetArchiveSource);
    VFX_OBJ_CLOSE(archiveToRAM);
}


void VappLauncherRobotDirector::releaseWidget()
{
    //
    // Misc.
    //
#if defined(__COSMOS_3D_V10__)
    VFX_OBJ_CLOSE(m_alertMaterial);
#else
    VFX_OBJ_CLOSE(m_alertFilter);
#endif

    VFX_OBJ_CLOSE(m_timerLaunchPageSelectorDnd);

    //
    // Widgets.
    //
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->releaseView();
            VFX_OBJ_CLOSE(widget);
        }
    }

    m_widgetList.removeAllInvalidate();
}


void VappLauncherRobotDirector::onDragWidget(VappWidget *widget, VfxPenEvent &event)
{
    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);

    VFX_ASSERT(mainScr && widget && m_desktop);

    // suspend widget for performance improment
    suspendWidget();

    //
    // Touch feedback
    //
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

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

    // m_penOffset will be transmitted by MM if app icon is from MM
    if(!m_isCreatWidgetFromMM)
    {
        m_penOffset = calcOffset(widget, event);
        m_widgetPageIndex = m_desktop->getPageIndex(widget);
    }

    widget->backupPosition();
    m_desktop->removeFromDesktop(widget);


    //
    // If the desktop cannot add widget, alert the widget.
    // It is may happens when the widget is dragged from MM,
    // the current page may be full of widget
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
    // Initialization (disable auto. animation during initialization)
    //
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    widget->setPos(calcPosition(mainScr, event, m_penOffset));

    VfxAutoAnimate::commit();

    //
    // Use auto animation for the opacity and transformation of the widget.
    //
    setWidgetDndEffect(widget, VFX_TRUE);

    //
    // Put the widget on the main screen such that it displays on the top-level.
    //
    mainScr->addChildFrame(widget);

#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    // Since we change the parent of the widget from this page to the screen,
    // the onPreviewPenInput of this page will no longer receive the pen event.
    // Resume the wallpaper here.
    //
    // TODO: Should UI engine send an "pen-abort" to the page at this case?
    resumeWallpaperForPenDown();
#endif /* defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE) */

    // Save the Drag-and-Drop (DnD) widget pointer.
    m_dndWidget = widget;

    // if drag widget from MM, no need to enter edit mode
    if(!m_isCreatWidgetFromMM)
    {
        //
        // Enter widget layout mode,
        // Can drag widget around the HS page,
        // also can delete it by drag it to trash can
        //
        toggleWidgetLayoutMode(VFX_TRUE, VFX_TRUE);
    }
}


void VappLauncherRobotDirector::onMoveWidget(VappWidget *widget, VfxPenEvent &event)
{
    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);

    VFX_ASSERT(mainScr && widget && m_desktop);

    //
    // Notify other UI component.
    //
    m_wallpaper->setWidgetMoved(event.pos, widget);

    //
    // Change widget's property.
    //
    widget->forcePos(calcPosition(mainScr, event, m_penOffset));

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
    // If widget move to trash can, alert the trash can
    //
    if(m_trashCanBar->containPoint( convertPointTo(event.pos,m_trashCanBar), VFX_TRUE))
    {
        m_trashCanBar->setAlertDeleteWidget(VFX_TRUE);
    }
    else
    {
        m_trashCanBar->setAlertDeleteWidget(VFX_FALSE);
    }

    //
    // Long-Tap Operation.
    //
    //  Priority 1: open the page selection
    //  Priority 2: auto-slide the page.
    //
    VFX_ASSERT(m_shortcutBar);

    VfxS32 indicatorDirection = 0;
    if (m_shortcutBar->isIndicatorHitted(event, indicatorDirection))
    {
        m_timerAutoSlideDesktop->stop();

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
            m_timerAutoSlideDesktop->stop();
        }
        else
        {
            if (!m_timerAutoSlideDesktop->getIsEnabled())
            {
                m_timerAutoSlideDesktop->start();
            }
        }
    }
}


void VappLauncherRobotDirector::onDropWidget(VappWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && widget == m_dndWidget && m_desktop);

    // if widget is dragged from MM, m_trashCanBar will be fold state,
    // so it can not be deleted

    // delete widget if drag widget into trash can
    if(m_trashCanBar->containPoint( convertPointTo(event.pos,m_trashCanBar), VFX_TRUE))
    {
        onDeselectWidget(widget);

        // reset state
        m_dndWidget = NULL;
        resumeWidget();
        m_timerLaunchPageSelectorDnd->stop();
        m_timerAutoSlideDesktop->stop();
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
        setWidgetSlim(VFX_FALSE);
        toggleWidgetLayoutMode(VFX_FALSE, VFX_TRUE);
        m_trashCanBar->setAlertDeleteWidget(VFX_FALSE);
        return;
    }

    // resume widget
    resumeWidget();

    // Clear the Drag-and-Drop (DnD) widget pointer.
    m_dndWidget = NULL;

    m_timerLaunchPageSelectorDnd->stop();
    m_timerAutoSlideDesktop->stop();

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
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    VfxS32 pageIndex;
    VfxPoint pagePos;
    VfxPoint tmpPos = calcPosition(m_desktop, event, VfxPoint(0,0));
    pageIndex = m_desktop->getPageIndexAndPos(tmpPos, pagePos);
    pagePos.x -= m_penOffset.x;
    pagePos.y -= m_penOffset.y;
    widget->setPos(pagePos);

    VfxAutoAnimate::commit();

    if (m_desktop->canAddToPage(widget, pageIndex))
    {
        m_desktop->addToNearest(widget, pageIndex);
    }
    else
    {
        if(m_isCreatWidgetFromMM)
        {
            onDeselectWidget(widget);
            m_isCreatWidgetFromMM = VFX_FALSE;

            displayErrorPopup(
                VCP_POPUP_TYPE_INFO,
                VCP_CONFIRM_BUTTON_SET_OK,
                VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_UNAVAILABLE));

            return;
        }

        widget->restorePosition();
        m_desktop->addToNearest(widget, m_widgetPageIndex);
    }

    save();

    m_isCreatWidgetFromMM = VFX_FALSE;
    toggleWidgetLayoutMode(VFX_FALSE, VFX_TRUE);
}


void VappLauncherRobotDirector::onAbortWidget(VappWidget *widget, VfxPenEvent &event)
{
    VFX_ASSERT(widget && widget == m_dndWidget && m_desktop);

    // resume widget
    resumeWidget();

    // Clear the Drag-and-Drop (DnD) widget pointer.
    m_dndWidget = NULL;

    m_timerLaunchPageSelectorDnd->stop();
    m_timerAutoSlideDesktop->stop();

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
    // If the page selector is present, handle it specially.
    //
    if (m_pageSelectorDnd)
    {
        m_pageSelectorDnd->doPenInput(event);
        return;
    }

    if(m_isCreatWidgetFromMM)
    {
        onDeselectWidget(widget);
    }
    else
    {
        widget->restorePosition();
        m_desktop->addToNearest(widget, m_widgetPageIndex);
    }

    m_isCreatWidgetFromMM = VFX_FALSE;
    toggleWidgetLayoutMode(VFX_FALSE, VFX_TRUE);
}


void VappLauncherRobotDirector::onDeselectWidget(VappWidget *widget)
{
    VAPP_LAUNCHER_ROBOT_SLA(("HUI", SA_start));

    VFX_ASSERT(widget);

    m_deleteWidgetList.append(widget);
    widget->setHidden(VFX_TRUE);

    // it will only callback once if register same callback at a single primitive,
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->blockAfterNextCommit(1, VfxCallback0(this, &VappLauncherRobotDirector::onDeleteWidget));

    VAPP_LAUNCHER_ROBOT_SLA(("HUI", SA_stop));
}


void VappLauncherRobotDirector::onDeleteWidget()
{
    m_deleteWidgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_deleteWidgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->releaseView();

            if(widget->getId().getSource() == VAPP_WIDGET_SRC_SHORTCUT)
            {
                m_numShortcut--;
            }
            
            widget->setVisible(VFX_FALSE);

            m_widgetList.removeOne(widget);

            VFX_OBJ_CLOSE(widget);
        }
    }

    m_deleteWidgetList.removeAllInvalidate();

    save();
}


void VappLauncherRobotDirector::onForbidDesktopSwipe(VappWidget *widget)
{
    forbidSwipe(widget);
}


void VappLauncherRobotDirector::onPermitDesktopSwipe(VappWidget *widget)
{
    permitSwipe(widget);
}


void VappLauncherRobotDirector::onLaunchPageSelectorDnd(VfxTimer *timer)
{
    VappWidget *widget;

    if (m_dndWidget)
    {
        widget = m_dndWidget;
    }
    else
    {
        return;
    }

    setWidgetAlertEffect(widget, VFX_FALSE);
    toggleWidgetLayoutMode( VFX_FALSE, VFX_TRUE);
    launchPageSelectorDnd(widget);
}


void VappLauncherRobotDirector::activateWidget(VappWidget *widget)
{
    //
    // Connect signals and create the view.
    //
    widget->m_signalDrag.connect(this, &VappLauncherRobotDirector::onDragWidget);
    widget->m_signalMove.connect(this, &VappLauncherRobotDirector::onMoveWidget);
    widget->m_signalDrop.connect(this, &VappLauncherRobotDirector::onDropWidget);
    widget->m_signalAbort.connect(this, &VappLauncherRobotDirector::onAbortWidget);
    widget->m_signalDeselect.connect(this, &VappLauncherRobotDirector::onDeselectWidget);
    widget->m_signalForbidDesktopSwipe.connect(this, &VappLauncherRobotDirector::onForbidDesktopSwipe);
    widget->m_signalPermitDesktopSwipe.connect(this, &VappLauncherRobotDirector::onPermitDesktopSwipe);

    m_widgetList.append(widget);
}


void VappLauncherRobotDirector::activateWidgetOnDesktop(VappWidget *widget, VfxS32 idx)
{
    activateWidget(widget);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_desktop->addToPage(widget, idx);

    VfxAutoAnimate::commit();

    save();
}


void VappLauncherRobotDirector::serializeWidget()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->serializeView();
            widget->setVisible(VFX_FALSE);
        }
    }
}


void VappLauncherRobotDirector::restoreWidget()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->restoreView();
        }
    }
}


void VappLauncherRobotDirector::serializeWidgetForPageSwitch()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->serializeViewForPageSwitch();
            widget->setVisible(VFX_FALSE);
        }
    }
}


void VappLauncherRobotDirector::restoreWidgetForPageSwitch()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->restoreViewForPageSwitch();
        }
    }
}


void VappLauncherRobotDirector::suspendWidget()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->suspend();
        }
    }
}


void VappLauncherRobotDirector::resumeWidget()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            widget->resume();
        }
    }
}


void VappLauncherRobotDirector::updateWidgetFocus(VfxPenEvent &event)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            if (widget->containPoint(event.getRelPos(widget)))
            {
                widget->focusView();
            }
            else
            {
                widget->defocusView();
            }
        }
    }
}


void VappLauncherRobotDirector::updateWidgetVisible()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            VfxBool isVisible = isWidgetVisible(widget);

            widget->setVisible(isVisible);
        }
    }
}


void VappLauncherRobotDirector::setWidgetSlim(VfxBool isSlim)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

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


void VappLauncherRobotDirector::setWidgetAlertEffect(VappWidget *widget, VfxBool isOn)
{
    VFX_OBJ_ASSERT_VALID(widget);

#if defined(__COSMOS_3D_V10__)
    if (isOn)
    {
        widget->setMaterial(m_alertMaterial->get());
        widget->setEditButtonMaterial(m_alertMaterial->get());
    }
    else
    {
        widget->setMaterial(NULL);
        widget->setEditButtonMaterial(NULL);
    }
#else
    if (isOn)
    {
        widget->setFilter(m_alertFilter);
    }
    else
    {
        widget->setFilter(NULL);
    }
#endif /* defined(__COSMOS_3D_V10__) */
}


void VappLauncherRobotDirector::setWidgetDndEffect(VappWidget *widget, VfxBool isOn)
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


void VappLauncherRobotDirector::setWidgetLandingEffect()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget && isWidgetVisible(widget))
        {
            //
            // Init animation
            //
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

            widget->setOpacity(s_landingOpacity);

            VfxAutoAnimate::commit();

            //
            // Animate it.
            //
            widget->setOpacity(1.0f);
        }
    }
}


VfxBool VappLauncherRobotDirector::isWidgetVisible(const VappWidget *widget) const
{
    VfxMainScr *mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);

    VfxRect screenBounds = mainScr->getBounds();
    VfxRect rect = widget->getBounds();

    rect = widget->convertRectTo(rect, mainScr);
    rect.intersectWith(screenBounds);

    if (rect.getWidth() > 0 && rect.getHeight() > 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxPoint VappLauncherRobotDirector::calcOffset(
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


VfxPoint VappLauncherRobotDirector::calcPosition(
    const VfxFrame *frame,
    VfxPenEvent &event,
    const VfxPoint &offset) const
{
    // error handling, pen may transimit pos overflow screen size
    if (event.pos.x >= getSize().width)
    {
        event.pos.x = getSize().width-1;
    }
    else if (event.pos.x < 0)
    {
        event.pos.x = 0;
    }

    VfxPoint pos = event.getRelPos(frame);

    pos.x -= offset.x;
    pos.y -= offset.y;

    return pos;
}


void VappLauncherRobotDirector::launchCallLog(void *userData)
{
    VFX_UNUSED(userData);

    vapp_clog_aclt_launch();
}


void VappLauncherRobotDirector::launchBrowser(void *userData)
{
#ifdef BROWSER_SUPPORT
    goto_mobile_suite_screen();
#endif
}


#ifdef __MMI_GB_WINGUO__
extern "C" MMI_ID GB_WG_Search_Net_Launch(void* args, U32 argSize);
void VappLauncherRobotDirector::launchWinguo(void *userData)
{
    GB_WG_Search_Net_Launch(NULL,NULL);
}
#endif


void VappLauncherRobotDirector::launchDialer(void *userData)
{
    vapp_dialer_launch_from_phb(NULL, 0);
}


void VappLauncherRobotDirector::launchDialerWithKey(void *userData)
{
    VFX_ASSERT(userData);

    // After we launch the dialer for key down event, dialer would need the
    // following key long-press event, too, e.g., to do speed dial. Set-up
    // this flag such that UI engine will route the consequent key events to the
    // dialer
    VfxKeypad::sendIncompleteKeyToNewScreen(VFX_TRUE);

    // Copy the data to the stack memory and free the user data.
    VfxKeyCodeEnum keyCode = (*(VfxKeyCodeEnum *)userData);
    VFX_FREE_MEM(userData);

    vapp_dialer_launch_by_key(keyCode);
}


VfxBool VappLauncherRobotDirector::isNewSetting() const
{
    U8 flag;
    S16 err;

    ReadValue(NVRAM_VAPP_LAUNCHER_ROBOT_NEW_SETTING, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_READ_SUCCESS);

    return flag == 0x00 ? VFX_FALSE : VFX_TRUE;
}


void VappLauncherRobotDirector::setIsNewSetting(VfxBool value)
{
    U8 flag;
    S16 err;

    flag = (value ? 0x01 : 0x00);

    WriteValue(NVRAM_VAPP_LAUNCHER_ROBOT_NEW_SETTING, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


VfxArchive *VappLauncherRobotDirector::createArchive(
    VfxU16 index,
    VfxChar mode)
{
    //
    // Determine the archive sourcd mode.
    //
    VappArchiveNvramSource::SourceModeEnum sourceMode;

    switch (mode)
    {
        case 'r':
            sourceMode = VappArchiveNvramSource::SOURCE_MODE_READ;
            break;

        case 'w':
            sourceMode = VappArchiveNvramSource::SOURCE_MODE_WRITE;
            break;

        default:
            sourceMode = VappArchiveNvramSource::SOURCE_MODE_UNKNOWN;
            VFX_ASSERT(0);
            break;
    }

    //
    // Create archive.
    //
    VfxArchive *ar;
    VappArchiveNvramSource *arSource;

    VFX_OBJ_CREATE(ar, VfxArchive, this);
    VFX_OBJ_CREATE(arSource, VappArchiveNvramSource, ar);

    VFX_ASSERT(index < CUSTOM_LAUNCHER_ROBOT_PAGE_NUM);

    VfxBool ret = arSource->open(
                    NVRAM_EF_VAPP_LAUNCHER_ROBOT_SETTING_LID,
                    index + 1,
                    NVRAM_EF_VAPP_LAUNCHER_ROBOT_SETTING_SIZE,
                    sourceMode);
    if (!ret)
    {
        VFX_OBJ_CLOSE(ar);
        return NULL;
    }

    ar->setSource(arSource);

    return ar;
}


void VappLauncherRobotDirector::displayErrorPopup(
    VcpPopupTypeEnum type,
    VcpConfirmPopupButtonSetEnum buttonType,
    const VfxWChar *string)
{
    VcpConfirmPopup *popup;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(type);
    popup->setButtonSet(buttonType);
    popup->setText((string));
    popup->setAutoDestory(VFX_TRUE);
    popup->setStaticShelter(VFX_TRUE);
    popup->show(VFX_TRUE);
}


VfxS32 VappLauncherRobotDirector::calcDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


VfxBool VappLauncherRobotDirector::isHorizontalPenMove(const VfxPenEvent &event)
{
    VfxS32 xDiff = vfxAbs(event.pos.x - event.downPos.x);
    VfxS32 yDiff = vfxAbs(event.pos.y - event.downPos.y);

    return xDiff > yDiff ? VFX_TRUE : VFX_FALSE;
}


void VappLauncherRobotDirector::setBarFolding(VfxBool isFolded, VfxBool isAnimatable)
{
    if (isFolded)
    {
        m_shortcutBar->fold(isAnimatable);
        m_toolbar->fold(isAnimatable);
    }
    else
    {
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


/*****************************************************************************
 * Class VfxLauncherRobotPageSlideTransition
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxLauncherRobotPageSlideTransition", VfxLauncherRobotPageSlideTransition, VfxPageSlideTransition);

VfxBool VfxLauncherRobotPageSlideTransition::customOuted()
{
    return VFX_FALSE;
}

