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
 *  vapp_screen_lock_pattern.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the pattern screen lock class
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "GlobalResDef.h"
#include "vfx_uc_include.h"
#include "vfx_page.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_native_factory.h"
#include "vapp_screen_lock_pattern.h"
#include "vapp_screen_lock_gprot.h"               // for launch screen lock
#include "mmi_rp_vapp_screen_lock_pattern_def.h"
#include "nvram_common_defs.h"
#include "vapp_screen_lock_setting_provider.h"    // get setting provider to launch screen lock

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GpioSrvGProt.h"

#include "vapp_wallpaper_kit.h"
// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

#ifdef __cplusplus
}
#endif

#if defined(__MMI_MAINLCD_480X800__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y  (VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT + 30)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y  VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT
#elif defined(__MMI_MAINLCD_240X400__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y  (VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT + 10)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y  (VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT - 11)
#else
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y  VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT
#endif

#if defined(__MMI_MAINLCD_480X800__)
    #define VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y  (150)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y  (80)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y  (70)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y  (40)
#else
    #define VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y  (80)
#endif


VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockPattern,
    VAPP_SCREEN_LOCK_TYPE_PATTERN,
    VappScreenLockPatternPublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockPattern, VappScreenLock);
VappScreenLockPattern::VappScreenLockPattern():
    m_wallpaper(NULL),
    m_time(NULL),
    m_frame(NULL),
    m_setting(NULL)
{
    // Do nothing.
}

VappScreenLockId VappScreenLockPattern::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE,
                            VAPP_SCREEN_LOCK_TYPE_PATTERN);
}


VfxS32 VappScreenLockPattern::getName(
    VfxWChar *string,
    VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_NAME);
    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappScreenLockPattern::createIcon(
    VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ICON);

    return icon;
}


VfxS32 VappScreenLockPattern::getScreenshotNum() const
{
    return 1;
}

VfxFrame **VappScreenLockPattern::createScreenshot(
    VfxObject *parentObj) const
{
    VfxFrame **screenshot;

    VFX_ALLOC_MEM(screenshot, getScreenshotNum(), parentObj);

    VFX_OBJ_CREATE(screenshot[0], VfxImageFrame, parentObj);
    ((VfxImageFrame*)(screenshot[0]))->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_SCREENSHOT);
    return screenshot;
}

void VappScreenLockPattern::onCreateView()
{

    // Create a timeline to force cache frame for performance consideration.
    // In this case, it will cache,
    // Time Area, Lock Frame(no card), Wallpaper,
    VfxFloatTimeline * m_cacheTL;
    VFX_OBJ_CREATE(m_cacheTL, VfxFloatTimeline, this);
    m_cacheTL->setTarget(this);
    m_cacheTL->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_cacheTL->setDurationTime(3);
    m_cacheTL->setFromValue(0.01f);
    m_cacheTL->setToValue(0.0f);
    m_cacheTL->m_signalStopped.connect(this, &VappScreenLockPattern::onTimelineStop);
    m_cacheTL->start();

    VfxS16 error;

    initWallpaper();

    VFX_OBJ_CREATE_EX(m_frame, VappScreenLockPatternFrame, this, (getSize().width, VAPP_SCREEN_LOCK_PATTERN_FRAME_START_Y));
    m_frame->setPos(0,  VAPP_SCREEN_LOCK_PATTERN_STATUS_BAR_HEIGHT);
    m_frame->setSize(getSize());
    m_frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_frame->m_signalPattern.connect(this, &VappScreenLockPattern::onPattern);

    ReadRecord(NVRAM_EF_VENUS_SLK_PATTERN_LID, 1, m_pattern, NVRAM_EF_VENUS_SLK_PATTERN_SIZE, &error);

    VFX_OBJ_CREATE(m_time, VappScreenLockPatternTime, this);

    mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappScreenLockPattern::eventHandler, this);
}

void VappScreenLockPattern::onReleaseView()
{
    deinitWallpaper();
    VFX_OBJ_CLOSE(m_time);
    VFX_OBJ_CLOSE(m_frame);

    mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappScreenLockPattern::eventHandler, this);
}

void VappScreenLockPattern::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP,
                    VAPP_SCREEN_LOCK_PATTERN_BACKLIGHT_OFF_TIME*0.7,
                    VAPP_SCREEN_LOCK_PATTERN_BACKLIGHT_OFF_TIME);

    if(!m_wallpaper)
    {
        createWallpaper();
    }
    else
    {
        m_wallpaper->resume();
    }
}

void VappScreenLockPattern::onPageExit()
{
    // restore app timer when lock is not active
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    m_wallpaper->suspend();
}

void VappScreenLockPattern::onSerializeView()
{
    if(m_wallpaper)
    {
        m_wallpaper->serializeView();
    }
}


void VappScreenLockPattern::onRestoreView()
{
    if(m_wallpaper)
    {
        m_wallpaper->restoreView();
    }
}


/* Setting Pages */
VfxBool VappScreenLockPattern::onGetConfigurationSupported() const
{
    return VFX_TRUE;
}

void VappScreenLockPattern::onCreateConfiguration()
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        VFX_OBJ_CREATE(m_setting, VappScreenLockPatternSettingPage, this);
        m_setting->m_signalExit.connect(this, &VappScreenLockPattern::onExitSetting);

        mainScr->pushPage(0, m_setting);
    }
}

VfxResId VappScreenLockPattern::onGetStatusBarBg()
{
	return IMG_ID_VAPP_SCREEN_LOCK_PATTERN_STATUSBAR_BG;
}


VfxBool VappScreenLockPattern::onGetStatusBarTranslucent()
{
	return VFX_TRUE;
}


void VappScreenLockPattern::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}


void VappScreenLockPattern::wallpaperUpdatedHdlr()
{
    releaseWallpaper();

    //
    // Because video wallpaper cannot be created in the background, we can only
    // re-create the wallpaper when this page is active.
    //
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if(isEntered() && !mainScr->getIsSnapshotDrawing() )
    {
        createWallpaper();
    }
}

void VappScreenLockPattern::initWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.connect(this, &VappScreenLockPattern::wallpaperUpdatedHdlr);

    createWallpaper();
}

void VappScreenLockPattern::createWallpaper()
{
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_LOCK);
}

void VappScreenLockPattern::releaseWallpaper()
{
    if(m_wallpaper)
    {
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}

void VappScreenLockPattern::deinitWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.disconnect(this, &VappScreenLockPattern::wallpaperUpdatedHdlr);

    releaseWallpaper();
}

void VappScreenLockPattern::onExitSetting(VappScreenLockPatternSettingPage* sender, VfxBool result)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 220);

    // MAUI_03197084: In order to enter pattern directly while clicking OK in pattern setting,
    //                so, in this case,setting won't help to launch instead of launch by ourself 
    //
    VappScreenLockSettingProvider* provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);
    provider->setDefaultScreenLock(getId());

    vapp_screen_lock_launch();

    m_signalConfigurationCompleted.postEmit(this, result);
}

void VappScreenLockPattern::onPattern(VfxU8 *pattern)
{
    VfxBool is_match = VFX_TRUE;

    for (VfxS32 i = 0; i < VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
    {
        if (m_pattern[i] != pattern[i])
        {
            is_match = VFX_FALSE;
            break;
        }
    }

    if (is_match == VFX_TRUE)
    {
        m_signalUnlock.postEmit(this);
    }
    else
    {
        m_frame->setCheckError();
    }
}

mmi_ret VappScreenLockPattern::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappScreenLockPattern* instance = (VappScreenLockPattern *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
            instance->m_frame->resetPattern();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


VFX_IMPLEMENT_CLASS("VappScreenLockPatternSettingPage", VappScreenLockPatternSettingPage, VfxPage);

VappScreenLockPatternSettingPage::VappScreenLockPatternSettingPage() :
    m_isExitApp(VFX_FALSE),
    m_frame(NULL),
    m_titleBar(NULL),
    m_buttomBar(NULL),
    m_state(SETTING_STATE_INITED),
    m_res(CLICK_RESULT_NONE)
{
    memset(m_currPattern, 0xFF, sizeof(m_currPattern));
}

void VappScreenLockPatternSettingPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle((STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_SET));
    m_titleBar->setBgColor(VFX_COLOR_BLACK);
    m_titleBar->setTranslucent(VFX_FALSE);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_buttomBar, VcpToolBar, this);
    m_buttomBar->m_signalButtonTap.connect(this, &VappScreenLockPatternSettingPage::onToolBarClick);
    m_buttomBar->addItem('CONT', VFX_WSTR_RES(STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_CONTINUE), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_buttomBar->addItem('BACK', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_buttomBar->setDisableItem('CONT', VFX_TRUE);
    m_buttomBar->setBgColor(VFX_COLOR_BLACK);
    m_buttomBar->setTranslucent(VFX_FALSE);
    setBottomBar(m_buttomBar);

    m_isExitApp = VFX_FALSE;

    setBgColor(VFX_COLOR_BLACK);
    setTranslucent(VFX_TRUE);
    setBarAutoHide(VFX_FALSE);

    this->m_signalTransitionStop.connect(this, &VappScreenLockPatternSettingPage::onExitSettingPage);
}

void VappScreenLockPatternSettingPage::onDeinit()
{
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_buttomBar);
    if (m_frame)
    {
        VFX_OBJ_CLOSE(m_frame);
    }

    VfxPage::onDeinit();
}

void VappScreenLockPatternSettingPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    if (!isBackward && m_frame == NULL)
    {
        VFX_OBJ_CREATE_EX(m_frame, VappScreenLockPatternFrame, this, (getSize().width, VAPP_SCREEN_LOCK_PATTERN_SETTING_FRAME_START_Y));
        m_frame->setSize(getSize());
        m_frame->setBgColor(VFX_COLOR_BLACK);
        m_frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_frame->m_signalPattern.connect(this, &VappScreenLockPatternSettingPage::onSetPattern);

        // Set prevent cache in order to cache the its child(dot frame)
        m_frame->setCacheMode(VFX_CACHE_MODE_PREVENT);
    }
}

void VappScreenLockPatternSettingPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    VfxMainScr* scr = getMainScr();

    if (m_state == SETTING_STATE_INITED)
    {
         m_res = CLICK_RESULT_CANCEL;
         scr->popPage();
    }
    else if (m_state == SETTING_STATE_PATTERN_SET_DONE)
    {
        if (id == 'CONT')
        {
            m_frame->resetPattern();
            m_frame->setLocked(VFX_FALSE);
            m_titleBar->setTitle((STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_CONFIRM));
            m_buttomBar->setDisableItem('CONT', VFX_TRUE);
            m_buttomBar->setDisableItem('BACK', VFX_TRUE);
            m_buttomBar->changeItem('CONT', VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
            m_buttomBar->changeItem('BACK', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        }
        else if (id == 'BACK')  // retry
        {
            // retry
            m_state = SETTING_STATE_INITED;
            m_frame->resetPattern();
            m_frame->setLocked(VFX_FALSE);
            m_buttomBar->setDisableItem('CONT', VFX_TRUE);
            m_buttomBar->changeItem('BACK', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
            //m_signalExit.postEmit(this, VFX_FALSE);
            //scr->popPage();
        }
    }
    else if (m_state == SETTING_STATE_CONFIRM)
    {
        if (id == 'CONT')
        {
            onSavePattern();
            m_res = CLICK_RESULT_OK;
            m_signalExit.emit(this, VFX_TRUE);
        }
        else if (id == 'BACK')
        {
            m_res = CLICK_RESULT_CANCEL;
        }
        scr->popPage();
    }
}

void VappScreenLockPatternSettingPage::onSetPattern(VfxU8 *pattern)
{
    if (m_state == SETTING_STATE_INITED)
    {
        // copy temp pattern
        for (VfxS32 i = 0; i < 9; i++)
        {
            m_currPattern[i] = pattern[i];
        }

        m_state = SETTING_STATE_PATTERN_SET_DONE;
        m_frame->setLocked(VFX_TRUE);
        m_buttomBar->setDisableItem('CONT', VFX_FALSE);
        m_buttomBar->changeItem('BACK', VFX_WSTR_RES(STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_RETRY), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    }
    else if (m_state == SETTING_STATE_PATTERN_SET_DONE || m_state == SETTING_STATE_CONFIRM)
    {
        // check pattern match here
        VfxBool b_match = VFX_TRUE;

        m_state = SETTING_STATE_CONFIRM;

        for (VfxS32 i = 0; i < 9; i++)
        {
            if (m_currPattern[i] != pattern[i])
            {
                b_match = VFX_FALSE;
                break;
            }
        }

        if (b_match == VFX_FALSE)
        {
            m_frame->setCheckError();
            m_frame->setLocked(VFX_FALSE);
            m_buttomBar->setDisableItem('CONT', VFX_TRUE);
            m_buttomBar->setDisableItem('BACK', VFX_FALSE);
            mmi_frm_nmgr_balloon(
    		      MMI_SCENARIO_ID_DEFAULT,
    		      MMI_EVENT_INFO_BALLOON,
    		      MMI_NMGR_BALLOON_TYPE_FAILURE,
    		      VFX_WSTR_RES(STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_BALLOON_CONFIRM_FAIL).getBuf());
        }
        else
        {
            m_frame->setLocked(VFX_TRUE);
            m_buttomBar->setDisableItem('CONT', VFX_FALSE);
            m_buttomBar->setDisableItem('BACK', VFX_FALSE);
            /*
            mmi_frm_nmgr_balloon(
    		      MMI_SCENARIO_ID_DEFAULT,
    		      MMI_EVENT_INFO_BALLOON,
    		      MMI_NMGR_BALLOON_TYPE_SUCCESS,
    		      VFX_WSTR_RES(STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_BALLOON_CONFIRM_OK).getBuf());
            */
        }
    }
}

void VappScreenLockPatternSettingPage::onSavePattern()
{
    VfxS16 error;

    WriteRecord(NVRAM_EF_VENUS_SLK_PATTERN_LID, 1, m_currPattern, NVRAM_EF_VENUS_SLK_PATTERN_SIZE, &error);
}

void VappScreenLockPatternSettingPage::onExitSettingPage(VfxObject* sender, VfxBool in, VfxS32 direction)
{
    /* fade out? */
    if (in == VFX_FALSE)
    {
        /* already send signal when OK clicked. */
        if (m_res == CLICK_RESULT_CANCEL || m_res == CLICK_RESULT_NONE)
        {
            m_signalExit.emit(this, VFX_FALSE);
        }
    }
}

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__
