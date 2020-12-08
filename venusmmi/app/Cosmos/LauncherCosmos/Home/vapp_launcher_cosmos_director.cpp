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
 *  vapp_launcher_cosmos_director.cpp
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vapp_launcher_cosmos_def.h"
#include "vapp_launcher_cosmos_page_selector.h"
#include "vapp_launcher_cosmos_shortcut_selector.h"
#include "vapp_launcher_cosmos_widget_selector.h"
#include "vapp_launcher_cosmos_director.h"
#include "vapp_launcher_cosmos_preinstaller.h"
#include "mmi_rp_vapp_launcher_cosmos_def.h"
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

#if defined(VAPP_LAUNCHER_COSMOS_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}

#if defined(__MMI_VUI_PLATFORM_CONTEXT_SLIM__)
#define VAPP_LAUNCHER_COSMOS_WIDGET_SETTING_DATA_SIZE (15 * (VAPP_LAUNCHER_COSMOS_MAX_SHORTCUT_WIDGET_NUM + 10))
#endif
/*****************************************************************************
 * Home Director
 *****************************************************************************/

VAPP_LAUNCHER_SYS_PUBLISH_NATIVE(
    VappLauncherCosmosDirector,
    VAPP_LAUNCHER_TYPE_COSMOS,
    VappLauncherCosmosDirectorPublisher);

VAPP_LAUNCHER_IMPLEMENT_CLASS(VappLauncherCosmosDirector, VappLauncher);

VfxU8 *VappLauncherCosmosDirector::m_widgetSettingDataPtr = NULL;
VfxU32 VappLauncherCosmosDirector::m_widgetSettingDataSize = 0;

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
VfxS32 VappLauncherCosmosDirector::s_curHSPageIndex = VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM/2;
#endif

const VfxFloat VappLauncherCosmosDirector::s_dndScaleRatio = 0.7f;
const VfxFloat VappLauncherCosmosDirector::s_dndOpacity = 0.6f;
const VfxFloat VappLauncherCosmosDirector::s_landingOpacity = 0.4f;
const VfxColor VappLauncherCosmosDirector::s_alertFilterMin(0, 128, 0, 0);    // ARGB
const VfxColor VappLauncherCosmosDirector::s_alertFilterMax(255, 255, 0, 0);  // ARGB


VappLauncherCosmosDirector::VappLauncherCosmosDirector() :
    m_widgetArchiveSource(NULL),
    m_timer2ndPassLoader(NULL),
    m_wallpaper(NULL),
    m_timerResumeWallpaper(NULL),
    m_isWallpaperSuspendForAppExit(VFX_FALSE),
    m_isWallpaperSuspendForNcenter(VFX_FALSE),
#if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
    m_isSuspendWallpaperForSwipe(VFX_FALSE),
    m_isSuspendWallpaperForPenDown(VFX_FALSE),
#endif /* defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE) */
    m_desktop(NULL),
    m_timerAutoSlideDesktop(NULL),
    m_isCaptured(VFX_FALSE),
    m_isCapturedFromOthers(VFX_FALSE),
    m_cannotSwipeRequest(),
    m_cannotSwipeList(),
    m_indicator(NULL),
    m_shortcutBar(NULL),
    m_isMMLaunchedByShortcutBar(VFX_FALSE),
    m_toolbar(NULL),
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


VfxBool VappLauncherCosmosDirector::onKeyInput(VfxKeyEvent &event)
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
            if (m_isInEditMode)
            {
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
            if (m_isInEditMode)
            {
                toggleEditMode(VFX_FALSE);
                return VFX_TRUE;
            }

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            suspendWallpaperForSwipe();
        #endif
        
            m_desktop->slideToCentra();
        
        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            resumeWallpaperForSwipe();
        #endif
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
            vfxPostInvoke(this, &VappLauncherCosmosDirector::launchCallLog);
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
        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            suspendWallpaperForSwipe();
        #endif
        
            m_desktop->slideToPrevious();
        
        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            resumeWallpaperForSwipe();
        #endif
        
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

            vfxPostInvoke(this, &VappLauncherCosmosDirector::launchDialer, keyCode);

            return VFX_TRUE;
        }
    }

    return VappLauncher::onKeyInput(event);
}


VfxBool VappLauncherCosmosDirector::onPreviewPenInput(VfxPenEvent &event)
{
    if (isPageSelectorPresent())
    {
        return VappLauncher::onPreviewPenInput(event);
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:

            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            suspendWallpaperForPenDown();
        #endif

            //
            // Update the widget's focus.
            //
            if (!m_isCaptured)
            {
                updateWidgetFocus(event);
            }

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:

            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PREVIEW_PEN_INPUT,
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
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_CAPTURE));

                if (capturePenEvent(event.target))
                {
                    return VFX_TRUE;
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:

            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                           'L', event.pos.x, event.pos.y));

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                               'U', event.pos.x, event.pos.y));
            }
            else
            {
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PREVIEW_PEN_INPUT,
                               'A', event.pos.x, event.pos.y));
            }

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            resumeWallpaperForPenDown();
        #endif

            break;

        default:
            break;
    }

    return VappLauncher::onPreviewPenInput(event);
}


VfxBool VappLauncherCosmosDirector::onPenInput(VfxPenEvent &event)
{
    if (!m_isCaptured && event.type != VFX_PEN_EVENT_TYPE_DOWN)
    {
        VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
                       '-', event.pos.x, event.pos.y));

        return VappLauncher::onPenInput(event);
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
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
                           'D', event.pos.x, event.pos.y));

            m_isCaptured = VFX_TRUE;

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            if (m_isCapturedFromOthers)
            {
                suspendWallpaperForSwipe();
            }
        #endif /* defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE) */

            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            suspendWallpaperForSwipe();
        #endif

            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
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
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
                               'U', event.pos.x, event.pos.y));
            }
            else
            {
                VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_PEN_INPUT,
                               'A', event.pos.x, event.pos.y));
            }

        #if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
            resumeWallpaperForSwipe();
        #endif

            m_isCaptured = VFX_FALSE;
            m_isCapturedFromOthers = VFX_FALSE;

            break;

        default:
            break;
    }

    return VFX_TRUE;
}


VfxBool VappLauncherCosmosDirector::capturePenEvent(const VfxObject *target)
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


void VappLauncherCosmosDirector::onDraw(VfxDrawContext &dc)
{
    VappLauncher::onDraw(dc);

    //
    // Update widgets' visible.
    //
    updateWidgetVisible();
}


VappLauncherId VappLauncherCosmosDirector::getId() const
{
    return VappLauncherId(
            VAPP_LAUNCHER_SRC_NATIVE,
            VAPP_LAUNCHER_TYPE_COSMOS);
}


VfxS32 VappLauncherCosmosDirector::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_LAUNCHER_COSMOS_SETTING_NAME);
    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);

}


VfxFrame *VappLauncherCosmosDirector::createIcon(VfxObject *parentObj)
{
    return NULL;
}


VfxS32 VappLauncherCosmosDirector::getScreenshotNum() const
{
    return 1;
}


VfxFrame **VappLauncherCosmosDirector::createScreenshot(VfxObject *parentObj) const
{
    VfxFrame **screenshot;
    
    VFX_ALLOC_MEM(screenshot, getScreenshotNum(), parentObj);
    
    VFX_OBJ_CREATE(screenshot[0], VfxImageFrame, parentObj);
    ((VfxImageFrame*)(screenshot[0]))->setResId(IMG_ID_VAPP_LAUNCHER_COSMOS_SETTING_SNAPSHOT);
    return screenshot;
}


void VappLauncherCosmosDirector::onCreateView()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_INIT, 100));

    VappLauncher::onCreateView();

    //
    // Launcher Size.
    //
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    setSize(screenSize.width, screenSize.height);

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

    createPageIndicator();

    createToolbar();

    createWidget();

    //
    // Connect wallpaper changed signal.
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.connect(this, &VappLauncherCosmosDirector::onWallpaperChanged);

    //
    // For performance, try to reduce the time to render the first frame of the
    // SSE using 2nd pass loader.
    //
    start2ndPassLoader();

    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_INIT, 200));
}


void VappLauncherCosmosDirector::onReleaseView()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_DEINIT, 100));

    //
    // Disconnect wallpaper changed signal.
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.disconnect(this, &VappLauncherCosmosDirector::onWallpaperChanged);

    //
    // Release other UI components
    //
    releaseWidget();

    releaseToolbar();

    releaseShortcutBar();

    releasePageIndicator();

    releaseDesktop();

    releaseWallpaper();

    //
    // Release 2nd pass activation.
    //
    release2ndPassLoader();

    if(m_pageSlideTransitionWeakPtr.isValid())
    {
        VFX_OBJ_CLOSE(m_pageSlideTransitionWeakPtr);
    }

    VappLauncher::onReleaseView();

    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_DEINIT, 200));
}


void VappLauncherCosmosDirector::onSerializeView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    VappLauncher::onSerializeView(ar);

    // Serialize widgets to save memory.
    VAPP_LAUNCHER_COSMOS_SLA(("HD2", SA_start));
    serializeWidget();
    VAPP_LAUNCHER_COSMOS_SLA(("HD2", SA_stop));

    // Serialize wallpaper
    // wallpaper may be deleted on MM when plug-in/plug-out Memory,
    // in this case, wallpaper will be null pointer when leaving HS/MM app,
    // but wallpaper will be created onRestoreView when HS/MM app active
    VAPP_LAUNCHER_COSMOS_SLA(("HD2", SA_start));
    if(m_wallpaper)
    {
        m_wallpaper->serializeView();
    }

    // Stop the 2nd pass App active if it isn't completed.
    stop2ndPassLoader();
    
    VAPP_LAUNCHER_COSMOS_SLA(("HD2", SA_stop));
}


void VappLauncherCosmosDirector::onRestoreView(VfxArchive *ar)
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
    if (!m_wallpaper)
    {
        VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_ENTER, 300));
        createWallpaperExt(-1);
    }
    else
    {
        VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_ENTER, 301));
        m_wallpaper->restoreView();
    }

    //
    // For performance, try to reduce the time to render the first frame of the
    // SSE using 2nd pass loader.
    //
    start2ndPassLoader();
}


void VappLauncherCosmosDirector::onEnter()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_ENTER, 100));
    VAPP_LAUNCHER_COSMOS_SLA(("HI1", SA_start));

    VappLauncher::onEnter();

    m_shortcutBar->restore();

    restoreWidgetForPageSwitch();

    resumeWidget();

    // For performance, resume the wallpaper after the page transition animation
    // completes. To avoid from the complication, we only resume wallpaper when
    // it had suspended because the page exited.
    if (m_wallpaper && m_isWallpaperSuspendForAppExit)
    {
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
        m_isWallpaperSuspendForAppExit = VFX_FALSE;
    }

    //
    // For performance, we will suspend the wallpaper when the notification
    // center is active.
    //
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    ncenter->m_signalEvent.connect(this, &VappLauncherCosmosDirector::onNotificationCenterChanged);

    VAPP_LAUNCHER_COSMOS_SLA(("HI1", SA_stop));
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_ENTER, 200));
}


void VappLauncherCosmosDirector::onEntered()
{
    if(m_isMMLaunchedByShortcutBar)
    {
        VfxAutoAnimate::begin();
        m_desktop->setOpacity(1.0f);
        m_shortcutBar->setOpacity(1.0f);
        m_indicator->setOpacity(1.0f);
        VfxAutoAnimate::commit();

        m_isMMLaunchedByShortcutBar = VFX_FALSE;
    }
}


void VappLauncherCosmosDirector::onExit()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_EXIT, 100));
    VAPP_LAUNCHER_COSMOS_SLA(("HD0", SA_start));

    // Move wallpaper create/restore from onAppActive/onAppInactive to page onEnter/onExit
    // because wallpaper will be MM's background
    // suspend wallpaper on MM too.

    suspendWidget();
    
    // For performance, suspend the wallpaper before the page transition
    // animation starts.
    if (m_wallpaper && !m_isWallpaperSuspendForAppExit)
    {
        if (m_timerResumeWallpaper && m_timerResumeWallpaper->getIsEnabled())
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
    ncenter->m_signalEvent.disconnect(this, &VappLauncherCosmosDirector::onNotificationCenterChanged);

    VappLauncher::onExit();

    VAPP_LAUNCHER_COSMOS_SLA(("HD0", SA_stop));
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_EXIT, 200));
}


VfxResId VappLauncherCosmosDirector::onGetStatusBarBg()
{
    return IMG_ID_VAPP_LAUNCHER_COSMOS_STATUS_BAR_BG;
}


VfxBool VappLauncherCosmosDirector::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


void VappLauncherCosmosDirector::save()
{
    m_widgetList.removeAllInvalidate();

    //
    // Create list array for widgets on each page.
    //
    VfxObjList list[CUSTOM_LAUNCHER_COSMOS_PAGE_NUM];

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);
        VFX_ASSERT(widget);

        VfxS32 pageIdx = m_desktop->getPageIndex(widget);
        if (pageIdx >= 0 && pageIdx < CUSTOM_LAUNCHER_COSMOS_PAGE_NUM)
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
    //Clear old widget setting data.
    //
    VFX_FREE_MEM(m_widgetSettingDataPtr);
    m_widgetSettingDataSize = 0;
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
    VFX_OBJ_CREATE_EX(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext), (VAPP_LAUNCHER_COSMOS_WIDGET_SETTING_DATA_SIZE));
#else
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif
    archiveToRAM->setSource(m_widgetArchiveSource);

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_COSMOS_PAGE_NUM; i++)
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


void VappLauncherCosmosDirector::create2ndPassLoader()
{
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame used in SSE.
    VFX_OBJ_CREATE(m_timer2ndPassLoader, VfxTimer, this);
    m_timer2ndPassLoader->setStartDelay(1);
    m_timer2ndPassLoader->m_signalTick.connect(this, &VappLauncherCosmosDirector::on2ndPassLoader);
}


void VappLauncherCosmosDirector::release2ndPassLoader()
{
    VFX_OBJ_CLOSE(m_timer2ndPassLoader);
}


void VappLauncherCosmosDirector::start2ndPassLoader()
{
    m_desktop->setHidden(VFX_TRUE);

    m_timer2ndPassLoader->start();
}


void VappLauncherCosmosDirector::stop2ndPassLoader()
{
    if (m_timer2ndPassLoader->getIsEnabled())
    {
        m_timer2ndPassLoader->stop();
    }
}


void VappLauncherCosmosDirector::on2ndPassLoader(VfxTimer *timer)
{
    VAPP_LAUNCHER_COSMOS_SLA(("HI3", SA_label));

    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_2ND_PASS_LOADER, 200));
    restoreWidget();

    m_desktop->setHidden(VFX_FALSE);

    //
    // Animate the widgets with landing effect.
    //
    setWidgetLandingEffect();

    VAPP_LAUNCHER_COSMOS_SLA(("HI3", SA_label));
}


void VappLauncherCosmosDirector::createWallpaper(VfxMsec delayTime)
{
    VFX_ASSERT(!m_wallpaper && !m_timerResumeWallpaper);

    //
    // Create the wallpaper.
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_HOMESCREEN, VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    //
    // Sync wallpaper to the desktop's current bounds.
    //
    if (m_desktop)
    {
        m_wallpaper->setDesktopBoundsChanged(
                        VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM,
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


void VappLauncherCosmosDirector::createWallpaperExt(VfxMsec delayTime)
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_CREATE_WALLPAPER_EXT, delayTime, 200));

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


void VappLauncherCosmosDirector::releaseWallpaper()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_RELEASE_WALLPAPER, 200));

    // Release objects.
    VFX_OBJ_CLOSE(m_wallpaper);
    VFX_OBJ_CLOSE(m_timerResumeWallpaper);
}


void VappLauncherCosmosDirector::onWallpaperChanged()
{
    VAPP_LAUNCHER_COSMOS_LOG((TRC_VAPP_LAUNCHER_COSMOS_DIRECTOR_ON_WALLPAPER_CHANGED, 200));
    releaseWallpaper();

    //
    // Because video wallpaper cannot be created in the background, we can only
    // re-create the wallpaper when this director page is active.
    //
    if (!isSerialized())
    {
        createWallpaperExt(-1);
    }

    if(isEntered())
    {
        delayResumeWallpaper(WALLPAPER_NORMAL_DELAY_TIME);
    }
}


void VappLauncherCosmosDirector::delayResumeWallpaper(VfxMsec delayTime)
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
        m_timerResumeWallpaper->m_signalTick.connect(this, &VappLauncherCosmosDirector::onResumeWallpaper);
        m_timerResumeWallpaper->start();
    }
}


void VappLauncherCosmosDirector::onResumeWallpaper(VfxTimer *timer)
{
    if (m_wallpaper)
    {
        m_wallpaper->resume();
    }
}


#if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
void VappLauncherCosmosDirector::suspendWallpaperForSwipe()
{
    // If timer is already ongoing, fire it immediately.
    if (m_timerResumeWallpaper && m_timerResumeWallpaper->getIsEnabled())
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


void VappLauncherCosmosDirector::resumeWallpaperForSwipe()
{
    if (m_isSuspendWallpaperForSwipe)
    {
        m_isSuspendWallpaperForSwipe = VFX_FALSE;
        delayResumeWallpaper(WALLPAPER_SWIPE_DELAY_TIME);
    }
}


void VappLauncherCosmosDirector::suspendWallpaperForPenDown()
{
    // If timer is already ongoing, fire it immediately.
    if (m_timerResumeWallpaper && m_timerResumeWallpaper->getIsEnabled())
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


void VappLauncherCosmosDirector::resumeWallpaperForPenDown()
{
    if (m_isSuspendWallpaperForPenDown)
    {
        m_isSuspendWallpaperForPenDown = VFX_FALSE;
        delayResumeWallpaper(WALLPAPER_SWIPE_DELAY_TIME);
    }
}
#endif /* defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE) */


void VappLauncherCosmosDirector::onNotificationCenterChanged(VappNCenterEventEnum event)
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


void VappLauncherCosmosDirector::createDesktop()
{
    VFX_ASSERT(!m_desktop && !m_timerAutoSlideDesktop);

    VFX_OBJ_CREATE(m_desktop, VappLauncherCosmosDesktop, this);
    m_desktop->m_signalPageChanged.connect(this, &VappLauncherCosmosDirector::onDesktopPageChanged);
    m_desktop->m_signalBoundsChanged.connect(this, &VappLauncherCosmosDirector::onDesktopBoundsChanged);

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    if(isRestoreStatus())
    {
        m_desktop->slideTo(s_curHSPageIndex, 0);
    }
    else
#endif
    {
        // Centralize the desktop.
        m_desktop->slideToCentra();
    }

    // Timer to do auto. sliding when the widget is dragged to the left or right
    // side of the desktop.
    VFX_OBJ_CREATE(m_timerAutoSlideDesktop, VfxTimer, this);
    m_timerAutoSlideDesktop->setStartDelay(DND_PAGE_SWITCH_START_DELAY);
    m_timerAutoSlideDesktop->setDuration(DND_PAGE_SWITCH_NEXT_DELAY);
    m_timerAutoSlideDesktop->m_signalTick.connect(this, &VappLauncherCosmosDirector::onAutoSlideDesktop);
}


void VappLauncherCosmosDirector::releaseDesktop()
{
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    s_curHSPageIndex = m_desktop->getCurrentPageIndex();
#endif

    VFX_OBJ_CLOSE(m_desktop);
    VFX_OBJ_CLOSE(m_timerAutoSlideDesktop);
}


void VappLauncherCosmosDirector::forbidSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.append(requester);
    }
}


void VappLauncherCosmosDirector::permitSwipe(VfxObject *requester)
{
    if (requester)
    {
        m_cannotSwipeRequest.removeOne(requester);
    }
}


VfxBool VappLauncherCosmosDirector::isSwipeForbidden()
{
    // Requester might be closed. Remove invalid requesters first.
    m_cannotSwipeRequest.removeAllInvalidate();

    return m_cannotSwipeRequest.isEmpty() ? VFX_FALSE : VFX_TRUE;
}


void VappLauncherCosmosDirector::addFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.append(frame);
    }
}


void VappLauncherCosmosDirector::removeFrameCannotSwipe(VfxFrame *frame)
{
    if (frame)
    {
        m_cannotSwipeList.removeOne(frame);
    }
}


VfxBool VappLauncherCosmosDirector::isFrameCannotSwipe(VfxFrame *frame)
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


VfxBool VappLauncherCosmosDirector::isFrameCannotSwipe(VfxObjList &frameList)
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


VfxBool VappLauncherCosmosDirector::isChildFrame(
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


void VappLauncherCosmosDirector::onDesktopPageChanged(VappLauncherCosmosDesktop *desktop)
{
    VFX_ASSERT(m_desktop && m_desktop == desktop);

    // Notify menu bar that the current page index is changed.
    if (m_indicator)
    {
        m_indicator->setIndex(m_desktop->getCurrentPageIndex());
    }
}


void VappLauncherCosmosDirector::onDesktopBoundsChanged(
    VfxFrame *frame,
    const VfxRect &oldBounds)
{
    VFX_ASSERT(m_desktop && m_desktop == frame);

    VfxRect bounds = frame->getBounds();

#if defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    // 
    // when desktop bounds exceeds max bounds x,
    // then the wallpaper will move (max_page-1)*x back to first page
    //
    VfxS32 maxX = bounds.getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1);
    if (bounds.origin.x < 0)
    {
        VfxS32 x = -bounds.origin.x;
        bounds.origin.x = (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1)*x;
    }
    else if (bounds.origin.x > maxX)
    {
        VfxS32 x = bounds.origin.x - maxX;
        bounds.origin.x = (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1) * (bounds.getWidth() - x);
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
    else if (bounds.origin.x > bounds.getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1))
    {
        bounds.origin.x = bounds.getWidth() * (VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1);
    }
#endif

    VfxFrame *dummyFrame;
    VFX_OBJ_CREATE(dummyFrame, VfxFrame, this);
    dummyFrame->setBounds(bounds);
    
    // Notify wallpaper that desktop is moved.
    if (m_wallpaper)
    {
        m_wallpaper->setDesktopBoundsChanged(VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM, dummyFrame, oldBounds);
    }

    VFX_OBJ_CLOSE(dummyFrame);
}


void VappLauncherCosmosDirector::onAutoSlideDesktop(VfxTimer *timer)
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

#if !defined(VAPP_LAUNCHER_COSMOS_SWIPE_LOOP_BACK_SUPPORT)
    if (idx <= 0 || idx >= VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM - 1)
    {
        timer->stop();
    }
#endif
}


void VappLauncherCosmosDirector::createPageIndicator()
{
    VFX_ASSERT(!m_indicator);

    VFX_OBJ_CREATE(m_indicator, VappLauncherCosmosPageIndicator, this);
    m_indicator->setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_indicator->m_signalClicked.connect(this, &VappLauncherCosmosDirector::onIndicatorClicked);
    m_indicator->setAnchor(0.5, 1.0);
    m_indicator->setPos(m_shortcutBar->getSize().width/2, getSize().height-m_shortcutBar->getSize().height);

    //
    // Set the current page index on the deskop.
    //
    VFX_ASSERT(m_desktop);
    m_indicator->setIndex(m_desktop->getCurrentPageIndex());
}


void VappLauncherCosmosDirector::releasePageIndicator()
{
    VFX_OBJ_CLOSE(m_indicator);
}


void VappLauncherCosmosDirector::onIndicatorClicked(VappLauncherCosmosPageIndicator *indicator)
{
    VFX_ASSERT(indicator && m_indicator == indicator);

    launchPageSelector();
}


void VappLauncherCosmosDirector::createShortcutBar()
{
    VFX_ASSERT(!m_shortcutBar);

    VFX_OBJ_CREATE(m_shortcutBar, VappLauncherCosmosShortcutBar, this);
    m_shortcutBar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_shortcutBar->m_signalMMLaunched.connect(this, &VappLauncherCosmosDirector::onMainMenuLaunched);

    // Forbid the desktop swipping if the pen event is on the shortcut bar.
    addFrameCannotSwipe(m_shortcutBar);
}


void VappLauncherCosmosDirector::releaseShortcutBar()
{
    VFX_OBJ_CLOSE(m_shortcutBar);
}


void VappLauncherCosmosDirector::onMainMenuLaunched()
{
    m_isMMLaunchedByShortcutBar = VFX_TRUE;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_desktop->setOpacity(0.0f);
    m_shortcutBar->setOpacity(0.0f);
    m_indicator->setOpacity(0.0f);
    VfxAutoAnimate::commit();
}


void VappLauncherCosmosDirector::createToolbar()
{
    VFX_ASSERT(!m_toolbar);

    VFX_OBJ_CREATE(m_toolbar, VappLauncherCosmosToolbar, this);
    m_toolbar->fold();
    m_toolbar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_toolbar->m_signalExecute.connect(this, &VappLauncherCosmosDirector::onToolbarExecute);

    // Forbid the desktop swipping if the pen event is on the toolbar.
    addFrameCannotSwipe(m_toolbar);
}


void VappLauncherCosmosDirector::releaseToolbar()
{
    VFX_OBJ_CLOSE(m_toolbar);
}


void VappLauncherCosmosDirector::onToolbarExecute(
    VappLauncherCosmosToolbar *toolbar,
    VappLauncherCosmosToolbar::ButtonEnum button)
{
    VFX_ASSERT(toolbar && toolbar == m_toolbar);

    switch (button)
    {
        case VappLauncherCosmosToolbar::BUTTON_ADD_WIDGET:
            launchWidgetSelector();
            break;

        case VappLauncherCosmosToolbar::BUTTON_ADD_SHORTCUT:
            launchShortcutSelector();
            break;

        case VappLauncherCosmosToolbar::BUTTON_SET_WALLPAPER:
            vapp_setting_launch_by_hdlr(onPushWallpaperSettingPage);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappLauncherCosmosDirector::onPushWallpaperSettingPage(VfxMainScr *mainScr)
{
    mainScr->setTransitType(VFX_SCR_TRANSIT_TYPE_SCR);
    vapp_setting_home_screen_wallpaper_setting_launch(mainScr);
}


void VappLauncherCosmosDirector::toggleEditMode(VfxBool isOn, VfxBool isAnimatable)
{
    if (isOn && !m_isInEditMode)
    {
        setWidgetEditMode(VFX_TRUE);

        m_shortcutBar->fold(isAnimatable);
        m_toolbar->unfold(isAnimatable);

        m_isInEditMode = VFX_TRUE;
    }
    else if (!isOn && m_isInEditMode)
    {
        setWidgetEditMode(VFX_FALSE);

        m_shortcutBar->unfold(isAnimatable);
        m_toolbar->fold(isAnimatable);

        m_isInEditMode = VFX_FALSE;
    }
}


void VappLauncherCosmosDirector::launchPageSelector()
{
    VAPP_LAUNCHER_COSMOS_SLA(("HP0", SA_start));

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

    m_pageSelector->m_signalAssembled.connect(this, &VappLauncherCosmosDirector::onPageSelectorAssembled);
    m_pageSelector->m_signalSelected.connect(this, &VappLauncherCosmosDirector::onPageSelectorSelected);
    m_pageSelector->m_signalAborted.connect(this, &VappLauncherCosmosDirector::onPageSelectorAborted);
    m_pageSelector->m_signalDismissed.connect(this, &VappLauncherCosmosDirector::onPageSelectorDismissed);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelector->assemble();
    VfxAutoAnimate::initAnimateEnd();

    VAPP_LAUNCHER_COSMOS_SLA(("HP0", SA_stop));
}


void VappLauncherCosmosDirector::onPageSelectorAssembled(
    VappLauncherCosmosPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Assembling completes. Resume the heavy UI components.
    //

    // At present, keep heavy UI component, e.g. wallpaper, stopped because the
    // performance is still not good enough.
}


void VappLauncherCosmosDirector::onPageSelectorSelected(
    VappLauncherCosmosPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

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


void VappLauncherCosmosDirector::onPageSelectorAborted(
    VappLauncherCosmosPageSelector *pageSelector,
    VappLauncherCosmosPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelector);

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappLauncherCosmosPageSelector::ABORT_CAUSE_HOME_KEY &&
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


void VappLauncherCosmosDirector::onPageSelectorDismissed(
    VappLauncherCosmosPageSelector *pageSelector)
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


void VappLauncherCosmosDirector::launchPageSelectorOos(VappWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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

    m_pageSelectorOos->m_signalAssembled.connect(this, &VappLauncherCosmosDirector::onPageSelectorOosAssembled);
    m_pageSelectorOos->m_signalSelected.connect(this, &VappLauncherCosmosDirector::onPageSelectorOosSelected);
    m_pageSelectorOos->m_signalAborted.connect(this, &VappLauncherCosmosDirector::onPageSelectorOosAborted);
    m_pageSelectorOos->m_signalDismissed.connect(this, &VappLauncherCosmosDirector::onPageSelectorOosDismissed);

    m_pageSelectorOos->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorOos->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappLauncherCosmosDirector::onPageSelectorOosAssembled(
    VappLauncherCosmosPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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


void VappLauncherCosmosDirector::onPageSelectorOosSelected(
    VappLauncherCosmosPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorOos);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    //
    // If the user taps a page without available spaces for this widget, display
    // an error popup.
    //
    if (m_isPageFull[idx])
    {
        displayErrorPopup(
            VCP_POPUP_TYPE_INFO,
            VCP_CONFIRM_BUTTON_SET_OK,
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_PAGE_UNAVAILABLE));

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


void VappLauncherCosmosDirector::onPageSelectorOosAborted(
    VappLauncherCosmosPageSelector *pageSelector,
    VappLauncherCosmosPageSelector::AbortCauseEnum cause)
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
    if (cause == VappLauncherCosmosPageSelector::ABORT_CAUSE_HOME_KEY &&
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


void VappLauncherCosmosDirector::onPageSelectorOosDismissed(
    VappLauncherCosmosPageSelector *pageSelector)
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

    //
    // Activate the widget on the desktop if the operation is not aborted, e.g.,
    // the 'widget' pointer is valid. If this dismissing operation is because
    // the user abort the page selector, 'selectedIndex' will be -1 and 'widget'
    // will be NULL because it is closed already in onPageSelectorOosAborted.
    //
    if (widget &&
        selectedIndex >= 0 &&
        selectedIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM)
    {
        VFX_OBJ_ASSERT_VALID(widget);
        VFX_ASSERT(m_desktop->canAddToPage(widget, selectedIndex));
        activateWidgetOnDesktop(widget, selectedIndex);
    }
}


void VappLauncherCosmosDirector::launchPageSelectorDnd(VappWidget *widget)
{
    //
    // Remember if each page can contain this widget before we pack the frames
    // to the page selector.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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

    m_pageSelectorDnd->m_signalAssembled.connect(this, &VappLauncherCosmosDirector::onPageSelectorDndAssembled);
    m_pageSelectorDnd->m_signalSelected.connect(this, &VappLauncherCosmosDirector::onPageSelectorDndSelected);
    m_pageSelectorDnd->m_signalAborted.connect(this, &VappLauncherCosmosDirector::onPageSelectorDndAborted);
    m_pageSelectorDnd->m_signalDismissed.connect(this, &VappLauncherCosmosDirector::onPageSelectorDndDismissed);

    m_pageSelectorDnd->setId((VfxId)widget);

    //
    // Do a initial auto. animation.
    //
    VfxAutoAnimate::initAnimateBegin();
    m_pageSelectorDnd->assemble();
    VfxAutoAnimate::initAnimateEnd();
}


void VappLauncherCosmosDirector::onPageSelectorDndAssembled(
    VappLauncherCosmosPageSelector *pageSelector)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Alert the snapshot if it cannot contain this widget.
    //
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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


void VappLauncherCosmosDirector::onPageSelectorDndSelected(
    VappLauncherCosmosPageSelector *pageSelector,
    VfxS32 idx)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);
    VFX_ASSERT(idx >= 0 && idx < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM);

    //
    // If the user drop the widget to a page without available spaces, abort
    // the operation.
    //
    if (m_isPageFull[idx])
    {
        onPageSelectorDndAborted(
            pageSelector,
            VappLauncherCosmosPageSelector::ABORT_CAUSE_DROP_OUTSIDE);

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


void VappLauncherCosmosDirector::onPageSelectorDndAborted(
    VappLauncherCosmosPageSelector *pageSelector,
    VappLauncherCosmosPageSelector::AbortCauseEnum cause)
{
    VFX_ASSERT(pageSelector && pageSelector == m_pageSelectorDnd);

    //
    // Dismissing will start. Suspend the heavy UI components.
    //

    // All other UI components are hidden or stopped.

    //
    // Exit edit mode for Home key.
    //
    if (cause == VappLauncherCosmosPageSelector::ABORT_CAUSE_HOME_KEY &&
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


void VappLauncherCosmosDirector::onPageSelectorDndDismissed(
    VappLauncherCosmosPageSelector *pageSelector)
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

    //
    // Animate the widget to its final position. If the user doesn't correctly
    // drop the widget to a page with enough space, 'selectedIndex' will be -1.
    //
    if (selectedIndex >= 0 && selectedIndex < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM &&
        m_desktop->canAddToPage(widget, selectedIndex))
    {
        m_desktop->addToPage(widget, selectedIndex);
    }
    else
    {
        widget->restorePosition();
        m_desktop->addToNearest(widget, m_widgetPageIndex);
    }

    // Dismiss animation is done. Recovery the widget to hittable.
    widget->setIsUnhittable(VFX_FALSE);

    // Update widget's position.
    save();
}


VappLauncherCosmosPageSelector *VappLauncherCosmosDirector::createPageSelector()
{
    VappLauncherCosmosPageSelector *pageSelector;

    VFX_OBJ_CREATE(pageSelector, VappLauncherCosmosPageSelector, this);
    pageSelector->setFocused(VFX_TRUE);

    //
    // Add widgets to the page selector.
    //
    packWidgetToPageSelector(pageSelector);

    return pageSelector;
}


void VappLauncherCosmosDirector::closePageSelector(VappLauncherCosmosPageSelector *pageSelector)
{
    //
    // Restore all frame to each page.
    //
    unpackWidgetFromPageSelector(pageSelector);

    VFX_OBJ_CLOSE(pageSelector);
}


void VappLauncherCosmosDirector::packWidgetToPageSelector(
    VappLauncherCosmosPageSelector *pageSelector)
{
    VfxS32 currentPageIndex = m_desktop->getCurrentPageIndex();
    VfxObjList objList;

    pageSelector->setFocusSnapshot(currentPageIndex);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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


void VappLauncherCosmosDirector::unpackWidgetFromPageSelector(
    VappLauncherCosmosPageSelector *pageSelector)
{
    VfxObjList objList;

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM; i++)
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


VfxBool VappLauncherCosmosDirector::isPageSelectorPresent()
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


void VappLauncherCosmosDirector::launchShortcutSelector()
{
    VAPP_LAUNCHER_COSMOS_SLA(("HS0", SA_start));

    //
    // Create the shortcut selector page.
    //
    // For performance, we delay the display of the page's content until the
    // page transition is completed. Otherwise, because VRT might be quitely
    // busy now, e.g. live wallpaper, sorting the shortcuts will take a long
    // time.
    //
    VFX_OBJ_CREATE(m_shortcutSelector, VappLauncherCosmosShortcutSelector, this);
    m_shortcutSelector->m_signalSelected.connect(this, &VappLauncherCosmosDirector::onWidgetSelected);
    m_shortcutSelector->m_signalTransitionStop.connect(this, &VappLauncherCosmosDirector::onShowShortcutSelector);

    // Push page into the screen.
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);
    VfxPage *topPage = mainScr->getPage(mainScr->getTopPageId() );

    //
    // use specific page transition to avoid clear HS cache,
    // or it will spend a lot of time to decode image when back from shortcut selector/ widget selector page
    //
    VfxLauncherCosmosPageSlideTransition *transition;
    VFX_OBJ_CREATE(transition, VfxLauncherCosmosPageSlideTransition, this);
    transition->m_signalStopped.connect(this, &VappLauncherCosmosDirector::onLeaveLauncherPageTransition);
    topPage->setTransition(transition);
    m_pageSlideTransitionWeakPtr = transition;

    mainScr->pushPage(0, m_shortcutSelector);

    VAPP_LAUNCHER_COSMOS_SLA(("HS0", SA_stop));
}


void VappLauncherCosmosDirector::onLeaveLauncherPageTransition(VfxBool in, VfxS32 direction)
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


void VappLauncherCosmosDirector::onShowShortcutSelector(
    VfxObject *sender,
    VfxBool in,
    VfxS32 direction)
{
    VAPP_LAUNCHER_COSMOS_SLA(("HS1", SA_start));

    VFX_ASSERT(sender && sender == m_shortcutSelector);

    // This handler should be called when the page is going to show and the
    // history direction is positive.
    if (in != VFX_TRUE || direction <= 0)
    {
        return;
    }

    m_shortcutSelector->m_signalTransitionStop.disconnect(this, &VappLauncherCosmosDirector::onShowShortcutSelector);

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

    VAPP_LAUNCHER_COSMOS_SLA(("HS1", SA_stop));
}


void VappLauncherCosmosDirector::launchWidgetSelector()
{
    VAPP_LAUNCHER_COSMOS_SLA(("HW0", SA_start));

    //
    // Create the widget selector page.
    //
    // For performance, we delay the display of this page's content until the
    // page transition is completed. Otherwise, because VRT might be quitely
    // busy now, e.g. live wallpaper, sorting the shortcuts will take a long
    // time.
    //
    VFX_OBJ_CREATE(m_widgetSelector, VappLauncherCosmosWidgetSelector, this);
    m_widgetSelector->m_signalSelected.connect(this, &VappLauncherCosmosDirector::onWidgetSelected);
    m_widgetSelector->m_signalTransitionStop.connect(this, &VappLauncherCosmosDirector::onShowWidgetSelector);

    // Push page into the screen.
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(getParentFrame());
    VFX_ASSERT(mainScr);
    VfxPage *topPage = mainScr->getPage(mainScr->getTopPageId() );

    VfxLauncherCosmosPageSlideTransition *transition;
    VFX_OBJ_CREATE(transition, VfxLauncherCosmosPageSlideTransition, this);
    transition->m_signalStopped.connect(this, &VappLauncherCosmosDirector::onLeaveLauncherPageTransition);
    topPage->setTransition(transition);
    m_pageSlideTransitionWeakPtr = transition;

    mainScr->pushPage(0, m_widgetSelector);

    VAPP_LAUNCHER_COSMOS_SLA(("HW0", SA_stop));
}


void VappLauncherCosmosDirector::onShowWidgetSelector(
    VfxObject *sender,
    VfxBool in,
    VfxS32 direction)
{
    VAPP_LAUNCHER_COSMOS_SLA(("HW1", SA_start));

    VFX_ASSERT(sender && sender == m_widgetSelector);

    // This handler should be called when the page is going to show and the
    // history direction is positive.
    if (in != VFX_TRUE || direction <= 0)
    {
        return;
    }

    m_widgetSelector->m_signalTransitionStop.disconnect(this, &VappLauncherCosmosDirector::onShowWidgetSelector);

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

    VAPP_LAUNCHER_COSMOS_SLA(("HW1", SA_stop));
}


void VappLauncherCosmosDirector::onWidgetSelected(
    VfxPage *page,
    const VappWidgetId &widgetId)
{
    //
    // Create widget.
    //
    VappWidgetKit *kit;

    kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    VFX_ASSERT(!m_selectedWidget); // to detect memory leak.
    m_selectedWidget = kit->createWidget(widgetId, this);

    if (m_selectedWidget)
    {
        if( widgetId.getSource() == VAPP_WIDGET_SRC_SHORTCUT &&
            m_numShortcut == VAPP_LAUNCHER_COSMOS_MAX_SHORTCUT_WIDGET_NUM)
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_CANNOT_ADD_MORE_SHORTCUT));
            VFX_OBJ_CLOSE(m_selectedWidget);
        }
        else
        {
            // Widget's final parent frame will be determined later.
            m_selectedWidget->removeFromParentFrame();

            // For performance, we install the widget on the desktop until the page
            // transition animation stops.
            page->m_signalTransitionStop.connect(this, &VappLauncherCosmosDirector::onInstallWidget);

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


void VappLauncherCosmosDirector::onInstallWidget(
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
            VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_ALL_PAGE_FULL));

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


void VappLauncherCosmosDirector::createWidget()
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
        if (m_widgetSettingDataPtr)
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
    VFX_OBJ_CREATE(m_alertMaterial, VappLauncherCosmosColorMaterial, this);
#else
    //
    // Color Filter
    //
    VFX_OBJ_CREATE(m_alertFilter, VappLauncherCosmosColorFilter, this);
    m_alertFilter->setColorFilter(s_alertFilterMin, s_alertFilterMax);
#endif /* !defined(__COSMOS_3D_V10__) */

    //
    // Timer to launch page selector if the user drags the widget to stay on
    // some pre-defined UI component.
    //
    VFX_OBJ_CREATE(m_timerLaunchPageSelectorDnd, VfxTimer, this);
    m_timerLaunchPageSelectorDnd->setStartDelay(DND_PAGE_SELECTOR_START_DELAY);
    m_timerLaunchPageSelectorDnd->m_signalTick.connect(this, &VappLauncherCosmosDirector::onLaunchPageSelectorDnd);
}


void VappLauncherCosmosDirector::createPreInstalledWidget()
{
    VappLauncherCosmosPreinstaller *preinstaller;

    VFX_OBJ_CREATE(preinstaller, VappLauncherCosmosPreinstaller, this);

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
        VappWidget *widget = kit->createWidget(preInstalled[i]->m_id, this);
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


void VappLauncherCosmosDirector::createArchivedWidgetFromRAM()
{
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
    
    //
    // Create archive.
    //
    VfxArchive *ar;
    VFX_OBJ_CREATE(ar, VfxArchive, this);
    if (!ar)
    {
        return;
    }

    // TODO:
    //
    // Archive source shall support to switch from write mode to read mode
    // directly.
    VFX_ASSERT(m_widgetSettingDataPtr);
    m_widgetArchiveSource->attachBuffer(m_widgetSettingDataPtr, m_widgetSettingDataSize);
    ar->setSource(m_widgetArchiveSource);

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    VappWidgetId id;

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_COSMOS_PAGE_NUM; i++)
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
            VappWidget *widget = kit->createWidget(id, this);
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


void VappLauncherCosmosDirector::createArchivedWidget()
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
    //Clear old setting data.
    //
    VFX_FREE_MEM(m_widgetSettingDataPtr);
    m_widgetSettingDataSize = 0;
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
    VFX_OBJ_CREATE_EX(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext), (VAPP_LAUNCHER_COSMOS_WIDGET_SETTING_DATA_SIZE));
#else
    VFX_OBJ_CREATE(m_widgetArchiveSource, VfxMemArchiveSource, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif

    VfxArchive *archiveToRAM;
    VFX_OBJ_CREATE(archiveToRAM, VfxArchive, this);
    archiveToRAM->setSource(m_widgetArchiveSource);

    for (VfxS32 i = 0; i < CUSTOM_LAUNCHER_COSMOS_PAGE_NUM; i++)
    {
        VfxS32 totalNum = ar->readU8();
        archiveToRAM->writeU8(totalNum);

        for (VfxS32 j = 0; j < totalNum; j++)
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
            VappWidget *widget = kit->createWidget(id, this);
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


void VappLauncherCosmosDirector::releaseWidget()
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


void VappLauncherCosmosDirector::onDragWidget(VappWidget *widget, VfxPenEvent &event)
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
    setWidgetSuspended(VFX_TRUE);

    //
    // Preliminary
    //
    m_penOffset = calcOffset(widget, event);
    m_widgetPageIndex = m_desktop->getPageIndex(widget);
    widget->backupPosition();
    m_desktop->removeFromDesktop(widget);

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

#if defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE)
    // Since we change the parent of the widget from this page to the screen,
    // the onPreviewPenInput of this page will no longer receive the pen event.
    // Resume the wallpaper here.
    //
    // TODO: Should UI engine send an "pen-abort" to the page at this case?
    resumeWallpaperForPenDown();
#endif /* defined(VAPP_LAUNCHER_COSMOS_SUSPEND_LWP_DURING_SWIPE) */

    // Save the Drag-and-Drop (DnD) widget pointer.
    m_dndWidget = widget;
}


void VappLauncherCosmosDirector::onMoveWidget(VappWidget *widget, VfxPenEvent &event)
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
    // Long-Tap Operation.
    //
    //  Priority 1: open the page selection
    //  Priority 2: auto-slide the page.
    //
    VFX_ASSERT(m_indicator);

    if (m_indicator->isHitted(event))
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


void VappLauncherCosmosDirector::onDropWidget(VappWidget *widget, VfxPenEvent &event)
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
    setWidgetSuspended(VFX_FALSE);

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
        widget->restorePosition();
        m_desktop->addToNearest(widget, m_widgetPageIndex);
    }

    save();
}


void VappLauncherCosmosDirector::onAbortWidget(VappWidget *widget, VfxPenEvent &event)
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
    setWidgetSuspended(VFX_FALSE);

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

    widget->restorePosition();
    m_desktop->addToNearest(widget, m_widgetPageIndex);
}


void VappLauncherCosmosDirector::onDeselectWidget(VappWidget *widget)
{
    VAPP_LAUNCHER_COSMOS_SLA(("HUI", SA_start));

    VFX_ASSERT(widget);

    m_deleteWidgetList.append(widget);
    widget->setHidden(VFX_TRUE);

    // it will only callback once if register same callback at a single primitive,
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->blockAfterNextCommit(1, VfxCallback0(this, &VappLauncherCosmosDirector::onDeleteWidget));

    VAPP_LAUNCHER_COSMOS_SLA(("HUI", SA_stop));
}


void VappLauncherCosmosDirector::onDeleteWidget()
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


void VappLauncherCosmosDirector::onForbidDesktopSwipe(VappWidget *widget)
{
    forbidSwipe(widget);
}


void VappLauncherCosmosDirector::onPermitDesktopSwipe(VappWidget *widget)
{
    permitSwipe(widget);
}


void VappLauncherCosmosDirector::onLaunchPageSelectorDnd(VfxTimer *timer)
{
    if (!m_dndWidget)
    {
        return;
    }

    setWidgetAlertEffect(m_dndWidget, VFX_FALSE);

    launchPageSelectorDnd(m_dndWidget);
}


void VappLauncherCosmosDirector::activateWidget(VappWidget *widget)
{
    //
    // Connect signals and create the view.
    //
    widget->m_signalDrag.connect(this, &VappLauncherCosmosDirector::onDragWidget);
    widget->m_signalMove.connect(this, &VappLauncherCosmosDirector::onMoveWidget);
    widget->m_signalDrop.connect(this, &VappLauncherCosmosDirector::onDropWidget);
    widget->m_signalAbort.connect(this, &VappLauncherCosmosDirector::onAbortWidget);
    widget->m_signalDeselect.connect(this, &VappLauncherCosmosDirector::onDeselectWidget);
    widget->m_signalForbidDesktopSwipe.connect(this, &VappLauncherCosmosDirector::onForbidDesktopSwipe);
    widget->m_signalPermitDesktopSwipe.connect(this, &VappLauncherCosmosDirector::onPermitDesktopSwipe);

    //
    // Misc.
    //
    if (m_isInEditMode)
    {
        widget->enterEditMode();
    }

    m_widgetList.append(widget);
}


void VappLauncherCosmosDirector::activateWidgetOnDesktop(VappWidget *widget, VfxS32 idx)
{
    activateWidget(widget);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_desktop->addToPage(widget, idx);

    VfxAutoAnimate::commit();

    save();
}


void VappLauncherCosmosDirector::serializeWidget()
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


void VappLauncherCosmosDirector::restoreWidget()
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


void VappLauncherCosmosDirector::serializeWidgetForPageSwitch()
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


void VappLauncherCosmosDirector::restoreWidgetForPageSwitch()
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

void VappLauncherCosmosDirector::suspendWidget()
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


void VappLauncherCosmosDirector::resumeWidget()
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


void VappLauncherCosmosDirector::updateWidgetFocus(VfxPenEvent &event)
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


void VappLauncherCosmosDirector::updateWidgetVisible()
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


void VappLauncherCosmosDirector::setWidgetSuspended(VfxBool isSuspended)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
        {
            if (isSuspended)
            {
                widget->suspend();
            }
            else
            {
                widget->resume();
            }
        }
    }
}


void VappLauncherCosmosDirector::setWidgetSlim(VfxBool isSlim)
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


void VappLauncherCosmosDirector::setWidgetEditMode(VfxBool isOn)
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

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

    m_widgetList.removeAllInvalidate();
}


void VappLauncherCosmosDirector::setWidgetAlertEffect(VappWidget *widget, VfxBool isOn)
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


void VappLauncherCosmosDirector::setWidgetDndEffect(VappWidget *widget, VfxBool isOn)
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


void VappLauncherCosmosDirector::setWidgetLandingEffect()
{
    m_widgetList.removeAllInvalidate();

    for (VfxObjListEntry *entry = m_widgetList.getHead();
         entry != NULL;
         entry = entry->getNext())
    {
        VappWidget *widget = VFX_OBJ_DYNAMIC_CAST(entry->get(), VappWidget);

        if (widget)
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


VfxBool VappLauncherCosmosDirector::isWidgetVisible(const VappWidget *widget) const
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


VfxPoint VappLauncherCosmosDirector::calcOffset(
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


VfxPoint VappLauncherCosmosDirector::calcPosition(
    const VfxFrame *frame,
    VfxPenEvent &event,
    const VfxPoint &offset) const
{
    // error handling, pen may transimit pos overflow screen size
    if (event.pos.x >= getSize().width)
    {
        event.pos.x = getSize().width - 1;
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


void VappLauncherCosmosDirector::launchCallLog(void *userData)
{
    VFX_UNUSED(userData);

    vapp_clog_aclt_launch();
}


void VappLauncherCosmosDirector::launchDialer(void *userData)
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


VfxBool VappLauncherCosmosDirector::isNewSetting() const
{
    U8 flag;
    S16 err;

    ReadValue(NVRAM_VAPP_LAUNCHER_COSMOS_NEW_SETTING, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_READ_SUCCESS);

    return flag == 0x00 ? VFX_FALSE : VFX_TRUE;
}


void VappLauncherCosmosDirector::setIsNewSetting(VfxBool value)
{
    U8 flag;
    S16 err;

    flag = (value ? 0x01 : 0x00);

    WriteValue(NVRAM_VAPP_LAUNCHER_COSMOS_NEW_SETTING, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


VfxArchive *VappLauncherCosmosDirector::createArchive(
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

    VFX_ASSERT(index < CUSTOM_LAUNCHER_COSMOS_PAGE_NUM);

    VfxBool ret = arSource->open(
                    NVRAM_EF_VAPP_LAUNCHER_COSMOS_SETTING_LID,
                    index + 1,
                    NVRAM_EF_VAPP_LAUNCHER_COSMOS_SETTING_SIZE,
                    sourceMode);
    if (!ret)
    {
        VFX_OBJ_CLOSE(ar);
        return NULL;
    }

    ar->setSource(arSource);

    return ar;
}


void VappLauncherCosmosDirector::displayErrorPopup(
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


VfxS32 VappLauncherCosmosDirector::calcDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


VfxBool VappLauncherCosmosDirector::isHorizontalPenMove(const VfxPenEvent &event)
{
    VfxS32 xDiff = vfxAbs(event.pos.x - event.downPos.x);
    VfxS32 yDiff = vfxAbs(event.pos.y - event.downPos.y);

    return xDiff > yDiff ? VFX_TRUE : VFX_FALSE;
}


void VappLauncherCosmosDirector::setBarFolding(VfxBool isFolded, VfxBool isAnimatable)
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


/*****************************************************************************
 * Class VfxLauncherCosmosPageSlideTransition
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxLauncherCosmosPageSlideTransition", VfxLauncherCosmosPageSlideTransition, VfxPageSlideTransition);

VfxBool VfxLauncherCosmosPageSlideTransition::customOuted()
{
    return VFX_FALSE;
}

