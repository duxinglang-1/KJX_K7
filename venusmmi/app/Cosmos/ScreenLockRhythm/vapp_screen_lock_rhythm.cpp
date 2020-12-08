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
 *  vapp_screen_lock_rhythm.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the simple screen lock class
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_rhythm.h"
#include "vapp_screen_lock_native_factory.h"
#include "mmi_rp_vapp_screen_lock_rhythm_def.h"

#include "vdat_systime.h"
#include "vfx_date_time.h"
#include "Vfx_page.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_msg_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GpioSrvGProt.h"

#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "WAPPushSrvGprots.h"
#include "ProvBoxSrvGProt.h" /* mmi_provboxui_get_total_unread_msg_num */

#ifdef  __MMI_NSS_SUPPORT__
// for NSS support
#include "NotificationSettingSrvGprot.h" 
#endif
#include "AppMgrSrvGprot.h"                            // for query app info

#ifdef __cplusplus
}
#endif

#if defined (__MMI_MAINLCD_240X320__)
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT = 110;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_POS_Y = 21;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_FONT_SIZE = 48;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_POS_Y = 63;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_FONT_SIZE = 12;
static const VfxS32 SCREEN_LOCK_RHYTHM_ARROW_P0S_Y = 91;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT = 17;
static const VfxS32 SCREEN_LOCK_RHYTHM_DRAG_THRESHOLD = 35;
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP = 60;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_PANEL_RISE_UP = 30;
static const VfxFloat SCREEN_LOCK_RHYTHM_RISE_UP_STOP_RANGE = 4.0f;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_FONT_SIZE = 13;
static const VfxS32 VAPP_SCREEN_LOCK_RHYTHM_TIME_AMPM_GAP = 1;
#elif defined (__MMI_MAINLCD_240X400__)
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT = 110;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_POS_Y = 21;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_FONT_SIZE = 48;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_POS_Y = 68;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_FONT_SIZE = 12;
static const VfxS32 SCREEN_LOCK_RHYTHM_ARROW_P0S_Y = 88;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT = 17;
static const VfxS32 SCREEN_LOCK_RHYTHM_DRAG_THRESHOLD = 35;
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP = 70;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_PANEL_RISE_UP = 35;
static const VfxFloat SCREEN_LOCK_RHYTHM_RISE_UP_STOP_RANGE = 5.0f;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_FONT_SIZE = 13;
static const VfxS32 VAPP_SCREEN_LOCK_RHYTHM_TIME_AMPM_GAP = 1;
#else /* defined (__MMI_MAINLCD_320X480__) */
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT = 127;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_POS_Y = 20;
static const VfxS32 SCREEN_LOCK_RHYTHM_TIME_FONT_SIZE = 55;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_POS_Y = 74;//63;
static const VfxS32 SCREEN_LOCK_RHYTHM_DATE_FONT_SIZE = 14;
static const VfxS32 SCREEN_LOCK_RHYTHM_ARROW_P0S_Y = 97;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT = 20;
static const VfxS32 SCREEN_LOCK_RHYTHM_DRAG_THRESHOLD = 40;
static const VfxS32 SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP = 90;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_PANEL_RISE_UP = 45;
static const VfxFloat SCREEN_LOCK_RHYTHM_RISE_UP_STOP_RANGE = 6.0f;
static const VfxS32 SCREEN_LOCK_RHYTHM_INDICATOR_FONT_SIZE = 14;
static const VfxS32 VAPP_SCREEN_LOCK_RHYTHM_TIME_AMPM_GAP = 2;
#endif


#define MAX_REPEAT_NUM (4)
#define SCREEN_LOCK_RHYTHM_WP_DIVISION_POS_Y (LCD_HEIGHT - SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT - SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP - (VappScreenLockRhythmIndicatorPanel::CELL_TYPE_TOTAL)*SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT)
static const VfxS32 MIX_GAP = 3;  //there are 3px to mix between indicator & unlock panel
/*****************************************************************************
 * Screen Lock Rhythm Class
 *****************************************************************************/
VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockRhythm,
    VAPP_SCREEN_LOCK_TYPE_RHYTHM,
    VappScreenLockRhythmPublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockRhythm, VappScreenLock);

const VfxFloat VappScreenLockRhythm::s_degrade[] = {1.0f, 0.5f, 0.20f, 0.06f};
VfxFloat VappScreenLockRhythm::s_oldTiming = 0;
VfxS32 VappScreenLockRhythm::s_currentBounceCount = 0;

VappScreenLockRhythm::VappScreenLockRhythm():
    m_wallpaperTop(NULL),
    m_wallpaperBottom(NULL),
    m_unlockPanel(NULL),
    m_tlBounceEffect(NULL),
    m_tlRiseUp(NULL),
    m_timerTriggerBounce(NULL),
    m_isNeedUpdate(VFX_FALSE)
{
    // Do nothing.
}


VappScreenLockId VappScreenLockRhythm::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE, 
                            VAPP_SCREEN_LOCK_TYPE_RHYTHM);
}


VfxS32 VappScreenLockRhythm::getName(
    VfxWChar *string,
    VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_RHYTHM_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);

}


VfxFrame *VappScreenLockRhythm::createIcon(
    VfxObject *parentObj)
{
    return NULL;
}


VfxS32 VappScreenLockRhythm::getScreenshotNum() const
{
    return 1;
}


VfxFrame** VappScreenLockRhythm::createScreenshot(
        VfxObject *parent           // [IN] Parent of the screenshots
    ) const
{
    VfxImageFrame **screenshot = NULL;
    VfxS32 num = getScreenshotNum();
    VFX_ALLOC_MEM(screenshot, sizeof(VfxImageFrame*) * num, parent);
    
    for(VfxS32 i = 0; i < num; i++)
    {
        VFX_OBJ_CREATE(screenshot[i], VfxImageFrame, parent);
        screenshot[i]->setResId(IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_SCREENSHOT + i);  //only 1 screenshot
    }
    
    return (VfxFrame**)screenshot;
}


void VappScreenLockRhythm::onCreateView()
{
    //wallpaper
    initWallpaper();

    //unlock panel
    VFX_OBJ_CREATE(m_unlockPanel, VappScreenLockRhythmUnlockPanel, this);
    m_unlockPanel->setAnchor(0.0f, 1.0f);
    m_unlockPanel->setPos(0, getSize().height);
    m_unlockPanel->m_signalUnlock.connect(this, &VappScreenLockRhythm::onUnlockHandler);
    m_unlockPanel->m_signalStopAnim.connect(this, &VappScreenLockRhythm::onStopAnimHandler);
    m_unlockPanel->m_signalCheckTimer.connect(this, &VappScreenLockRhythm::checkBounceTimer);
    m_unlockPanel->setAutoAnimate(VFX_TRUE);
    m_unlockPanel->setCacheMode(VFX_CACHE_MODE_PREVENT);

    //indicator panel
    VFX_OBJ_CREATE(m_indicatorPanel, VappScreenLockRhythmIndicatorPanel, this);
    bindToPanel();

    VFX_OBJ_CREATE(m_tlBounceEffect, VfxFloatTimeline, this);
    m_tlBounceEffect->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_tlBounceEffect->setIsFromCurrent(VFX_FALSE);
    m_tlBounceEffect->setFromValue(0.0f);
    m_tlBounceEffect->setToValue(1.0f);
    m_tlBounceEffect->setDuration(300);
    m_tlBounceEffect->setRepeatCount(MAX_REPEAT_NUM);

    VFX_OBJ_CREATE(m_timerTriggerBounce, VfxTimer, this);
    m_timerTriggerBounce->setDuration(4000);
    m_timerTriggerBounce->setStartDelay(3000);
    m_timerTriggerBounce->m_signalTick.connect(this, &VappScreenLockRhythm::onTimerTriggerBounce);
    
    updateUnreadMsg();
    updateMissedCall();

    if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD))
    {
        checkBounceTimer();
    }
    initEvent();
}


void VappScreenLockRhythm::onReleaseView()
{
    deinitEvent();
    deinitWallpaper();
    VFX_OBJ_CLOSE(m_unlockPanel);
    VFX_OBJ_CLOSE(m_indicatorPanel);
    VFX_OBJ_CLOSE(m_tlBounceEffect);
    VFX_OBJ_CLOSE(m_timerTriggerBounce);
    VFX_OBJ_CLOSE(m_tlRiseUp);
}


void VappScreenLockRhythm::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, 
                    VAPP_SCREEN_LOCK_RHYTHM_BACKLIGHT_OFF_TIME*0.7,
                    VAPP_SCREEN_LOCK_RHYTHM_BACKLIGHT_OFF_TIME);
}


void VappScreenLockRhythm::onPageExit()
{
    // restore app timer when lock is not active
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}


VfxResId VappScreenLockRhythm::onGetStatusBarBg()
{
    return IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_STATUSBAR_BG;
}


VfxBool VappScreenLockRhythm::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


VfxBool VappScreenLockRhythm::onPenInput(VfxPenEvent &event)
{
    if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE && m_unlockPanel->containPoint(event.getRelPos(m_unlockPanel)))
    {
        // change anchor to down pos, convenient to deal with pen move.
        VfxPoint pt = event.getRelPos(m_unlockPanel);
        VfxFloat anchor_y = (VfxFloat)pt.y / m_unlockPanel->getSize().height;
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_unlockPanel->setAnchor(0.0f, anchor_y);
        m_unlockPanel->setPos(0, event.pos.y);
        VfxAutoAnimate::commit();
        m_unlockPanel->setOpacity(0.7f);

        m_unlockPanel->capture();
        return VFX_TRUE;
    }

    return VfxControl::onPenInput(event);
}


void VappScreenLockRhythm::onBacklightOn()
{
    if (m_indicatorPanel->isEmpty())
    {
        riseUp();  //rise up from bottom, and then do bounce animation.
    }
    else
    {
        bindToPanel();
        riseUp();
    }

    m_unlockPanel->playArrow();
}


void VappScreenLockRhythm::onBacklightOff()
{
    if (m_tlBounceEffect && m_tlBounceEffect->getIsEnabled())
    {
        m_tlBounceEffect->stop();
    }

    if (m_tlRiseUp && m_tlRiseUp->getIsEnabled())
    {
        m_tlRiseUp->stop();
    }

    if (m_timerTriggerBounce->getIsEnabled())
    {
        m_timerTriggerBounce->stop();
    }
    m_unlockPanel->restoreOriginPosition(VFX_TRUE);
    m_indicatorPanel->restoreOriginPosition();

    m_unlockPanel->stopArrow();
}


void VappScreenLockRhythm::onUnlockHandler(VfxObject* sender)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200);
    m_signalUnlock.postEmit(this);
}


void VappScreenLockRhythm::onStopAnimHandler()
{
    if (m_tlBounceEffect && m_tlBounceEffect->getIsEnabled())
    {
        m_tlBounceEffect->stop();
    }

    m_timerTriggerBounce->stop();
    bindToPanel();
}


void VappScreenLockRhythm::initWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.connect(this, &VappScreenLockRhythm::wallpaperUpdatedHdlr);

    createWallpaper();
}


void VappScreenLockRhythm::createWallpaper()
{
    //
    //Divide wallpaper to two part, only cache bottom part to save cache size.
    //
    VFX_OBJ_CREATE(m_wpContainerTop, VfxFrame, this);
    VFX_OBJ_CREATE(m_wpContainerBottom, VfxFrame, this);
    m_wpContainerTop->setRect(0, 0, LCD_WIDTH, SCREEN_LOCK_RHYTHM_WP_DIVISION_POS_Y);
    m_wpContainerBottom->setPos(0, SCREEN_LOCK_RHYTHM_WP_DIVISION_POS_Y);
    m_wpContainerBottom->setBounds(0, SCREEN_LOCK_RHYTHM_WP_DIVISION_POS_Y, LCD_WIDTH, LCD_HEIGHT - SCREEN_LOCK_RHYTHM_WP_DIVISION_POS_Y);
    //
    //MAUI_03309322:
    //send the wallpaper to back as background
    //
    m_wpContainerTop->sendToBack();
    m_wpContainerBottom->sendToBack();
    
    m_wallpaperTop = VappWallpaperKit::createWallpaper(m_wpContainerTop, VAPP_WALLPAPER_SRC_LOCK);
    m_wallpaperBottom = VappWallpaperKit::createWallpaper(m_wpContainerBottom, VAPP_WALLPAPER_SRC_LOCK);

    //
    //Only permit wallpaper bottom part can be cached by vrt.
    //
    preventAllChildCache(m_wpContainerTop);
    m_wpContainerBottom->setCacheMode(VFX_CACHE_MODE_FREEZE);
    m_wallpaperBottom->setCacheMode(VFX_CACHE_MODE_PREVENT);
    
    //Only static wallpaper, cannot touch
    m_wallpaperTop->setIsUnhittable(VFX_TRUE);
    m_wallpaperBottom->setIsUnhittable(VFX_TRUE);
}


void VappScreenLockRhythm::releaseWallpaper()
{
    if(m_wallpaperTop)
    {
        VFX_OBJ_CLOSE(m_wallpaperTop);
    }

    if(m_wallpaperBottom)
    {
        VFX_OBJ_CLOSE(m_wallpaperBottom);
    }
    VFX_OBJ_CLOSE(m_wpContainerTop);
    VFX_OBJ_CLOSE(m_wpContainerBottom);
}


void VappScreenLockRhythm::deinitWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.disconnect(this, &VappScreenLockRhythm::wallpaperUpdatedHdlr);

    releaseWallpaper();
}


void VappScreenLockRhythm::wallpaperUpdatedHdlr()
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


void VappScreenLockRhythm::initEvent()
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,  &VappScreenLockRhythm::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY,  &VappScreenLockRhythm::eventHandler, this);

    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG,  &VappScreenLockRhythm::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG,  &VappScreenLockRhythm::eventHandler, this);
}


void VappScreenLockRhythm::deinitEvent()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,  &VappScreenLockRhythm::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY,  &VappScreenLockRhythm::eventHandler, this);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG,  &VappScreenLockRhythm::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG,  &VappScreenLockRhythm::eventHandler, this);  
}


mmi_ret VappScreenLockRhythm::eventHandler(mmi_event_struct * event)
{
    VappScreenLockRhythm* pThis = (VappScreenLockRhythm *)event->user_data;
    
    switch (event->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_REFRESH:
            pThis->updateUnreadMsg();
            break;

        case EVT_ID_SRV_UM_NOTIFY_READY:
            pThis->updateUnreadMsg();
            break;

        case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct*) event;
            if (add_evt->new_idf.cate == SRV_CLOG_CATE_CALL && add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                pThis->updateMissedCall();
            }
            break;
        }   

        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *del_evt = (srv_clog_evt_del_log_struct*) event;
            if (del_evt->idf.cate == SRV_CLOG_CATE_CALL && del_evt->idf.log_type == SRV_CLOG_CLT_MISSED)
            {               
                pThis->updateMissedCall();
            }
            break;
        }

        default:
            break;
        
    }
    pThis->checkBounceTimer();
    return MMI_RET_OK;
}


VfxBool VappScreenLockRhythm::updateUnreadMsg()
{
    U16 settingValue = 1;
 
#ifdef  __MMI_NSS_SUPPORT__
    //check MSG_APP's NSS setting
    mmi_srv_nss_get_setting(VAPP_MSG, NSS_SETTING_LOCK_SCRN, &settingValue);
#endif

	if(!(settingValue))
    {
        return VFX_TRUE;
	}
   
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_UPDATE_MSG_NUMBER, srv_um_check_ready(), getUnreadMsgNum(), 200);
    if(MMI_FALSE == srv_um_check_ready())
    {
        return VFX_FALSE;
    }

    //During unlock panel in animation, delay to update msg num until animation finished.
    if (m_indicatorPanel->isEmpty() && 
        ((m_tlBounceEffect && m_tlBounceEffect->getIsEnabled()) || (m_tlRiseUp && m_tlRiseUp->getIsEnabled())))
    {
        m_isNeedUpdate = VFX_TRUE;
        return VFX_FALSE;
    }

    VfxU32 unread = getUnreadMsgNum();
    m_indicatorPanel->updateCell(VappScreenLockRhythmIndicatorPanel::CELL_TYPE_UNREAD_MESSAGE, unread);
    return VFX_TRUE;
}


VfxBool VappScreenLockRhythm::updateMissedCall()
{
    U16 settingValue = 1;
 
#ifdef  __MMI_NSS_SUPPORT__
    //check CALLLOG_APP's NSS setting
    mmi_srv_nss_get_setting(VAPP_CALLLOG, NSS_SETTING_LOCK_SCRN, &settingValue);
#endif

	if(!(settingValue))
    {
        return VFX_TRUE;
	}
    
    VfxU32 miss = srv_clog_get_unread_missed_call_num();

    m_indicatorPanel->updateCell(VappScreenLockRhythmIndicatorPanel::CELL_TYPE_MISSED_CALL, miss);
    return VFX_TRUE;
}


VfxU32 VappScreenLockRhythm::getUnreadMsgNum()
{
    VfxU32 count = 0;

    /* Get SMS unread count */
    count += srv_sms_get_unread_sms_num();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, count, 200);

#ifdef __MMI_MMS_2__
    /* Get MMS unread count */
    VfxS32 result;
    srv_mms_get_msg_count_struct msg_count_req;

    vfx_sys_mem_zero(&msg_count_req, sizeof(srv_mms_get_msg_count_struct));

    msg_count_req.count = 1;
    msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;

    result = srv_mms_get_msg_count(&msg_count_req);

    if (SRV_MMS_RESULT_OK == result)
    {
        count += msg_count_req.rsp_tb[0];
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, msg_count_req.rsp_tb[0], 201);
    }
#endif

#ifdef WAP_SUPPORT
    /* Get Push unread count */
    count += srv_get_push_unread_count();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_get_push_unread_count(), 202);
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /* Get Prov unread count */
    count += srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL), 203);
#endif

    return count;
}


void VappScreenLockRhythm::bounceAnimation(VfxFrame *frame, VfxU32 max_range)
{
    s_oldTiming = 0;
    s_currentBounceCount = 0;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setFpeUser0((VfxFloat)frame->getPos().y);  // remember the last position in y axis
    VfxAutoAnimate::commit();

    frame->setPropertyEffectCallback(
        frame,
        &VappScreenLockRhythm::fpeBounce,
        &max_range,
        sizeof(VfxS32)
        );
        
    m_tlBounceEffect->setTarget(frame);
    m_tlBounceEffect->m_signalStopped.connect(this, &VappScreenLockRhythm::onTimelineBounceStopped);
    m_tlBounceEffect->start();
}


void VappScreenLockRhythm::checkBounceTimer()
{
    if (m_indicatorPanel->isEmpty())
    {
        m_timerTriggerBounce->stop();
    }
    else if (!m_timerTriggerBounce->getIsEnabled())
    {
        m_timerTriggerBounce->start();
    }
}


void VappScreenLockRhythm::bindToPanel()
{
    m_indicatorPanel->setPropertyEffectCallback(
        m_unlockPanel,
        &VappScreenLockRhythm::fpeUnlock,
        NULL,
        0);
}


void VappScreenLockRhythm::riseUp()
{
    m_unlockPanel->setIsUnhittable(VFX_TRUE);
    
    //from
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_unlockPanel->forcePos(VfxPoint(0, LCD_HEIGHT + SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT));
    m_unlockPanel->setAnchor(0.0f, 1.0f);
    VfxAutoAnimate::commit();

    //to
    VFX_OBJ_CREATE(m_tlRiseUp, VfxS32Timeline, this);
    m_tlRiseUp->setTarget(m_unlockPanel);
    m_tlRiseUp->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_tlRiseUp->setFromValue(LCD_HEIGHT + SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT);
    m_tlRiseUp->setToValue(LCD_HEIGHT);
    m_tlRiseUp->setDuration(200);
    m_tlRiseUp->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_tlRiseUp->m_signalStopped.connect(this, &VappScreenLockRhythm::onTimelineRiseUpStopped);
    m_tlRiseUp->start();
}


void VappScreenLockRhythm::onTimelineBounceStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        m_unlockPanel->restoreOriginPosition(VFX_TRUE);
        m_indicatorPanel->restoreOriginPosition();
    }
    
    m_unlockPanel->setPropertyEffectCallback(NULL , NULL, NULL, 0);
    m_indicatorPanel->setPropertyEffectCallback(NULL, NULL, NULL, 0);

    //delay to update msg num
    if (m_isNeedUpdate)
    {
        updateUnreadMsg();
        m_isNeedUpdate = VFX_FALSE;
    }

    if (!m_indicatorPanel->isEmpty() && !m_timerTriggerBounce->getIsEnabled())
    {
        m_timerTriggerBounce->start();
    }
    
    bindToPanel();
}


void VappScreenLockRhythm::onTimelineRiseUpStopped(VfxBaseTimeline * timeline,VfxBool isCompleted)
{
    m_unlockPanel->restoreOriginPosition(VFX_TRUE);
    m_unlockPanel->setIsUnhittable(VFX_FALSE);

    if (m_indicatorPanel->isEmpty())
    {
        bounceAnimation(m_unlockPanel, SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP);
    }
    else
    {
        bounceAnimation(m_indicatorPanel, SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_RISE_UP);
    }

    VFX_ASSERT(m_tlRiseUp == timeline);
    VFX_OBJ_CLOSE(m_tlRiseUp);
}


void VappScreenLockRhythm::onTimerTriggerBounce(VfxTimer *timer)
{
    if (m_indicatorPanel->isEmpty())
    {
        timer->stop();
    }
    else
    {
        bounceAnimation(m_indicatorPanel, SCREEN_LOCK_RHYTHM_INDICATOR_PANEL_RISE_UP);
    }
}


vrt_render_dirty_type_enum VappScreenLockRhythm::fpeUnlock(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VfxFloat anchor_y = watch_frame->anchor_point.y;
    VfxS32 h = VfxS32(watch_frame->bounds.size.height * anchor_y + 0.5f);
    
    target_frame->pos.y = watch_frame->pos.y - h + MIX_GAP;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum VappScreenLockRhythm::fpeBounce(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VfxFloat currentTiming = target_frame->pos_z;
    VfxS32 max_range = *(VfxS32*)user_data;
    if (vfxAbs(currentTiming - s_oldTiming) > 0.7f)  //identify if it is a new timing.
    {
        s_currentBounceCount++;
    }

    if (s_currentBounceCount > MAX_REPEAT_NUM - 1)
    {
        s_currentBounceCount = MAX_REPEAT_NUM - 1;
    }
    VfxFloat range = max_range * s_degrade[s_currentBounceCount];

    if (range < SCREEN_LOCK_RHYTHM_RISE_UP_STOP_RANGE)
    {
        range = 0;
    }
    
    VfxS32 offset_y = range * vfxAbs(vfxSin(VFX_DEG_TO_RAD(currentTiming * 180)));
    target_frame->pos.y = target_frame->fpe_user_0 - offset_y;

    s_oldTiming = target_frame->pos_z;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VappScreenLockRhythm::preventAllChildCache(VfxFrame *parent)
{
    parent->setCacheMode(VFX_CACHE_MODE_PREVENT);
    VfxFrame *frame = parent->getFirstChildFrame();
    while (frame != NULL)
    {
        preventAllChildCache(frame);
        frame = frame->getNextFrame();
    }
}

/*****************************************************************************
 * Screen Lock Rhythm Unlock Panel Class
 *****************************************************************************/
const VfxFloat VappScreenLockRhythmUnlockPanel::s_arrow_opacity[3] = {0.4f, 0.7f, 1.0f};

VappScreenLockRhythmUnlockPanel::VappScreenLockRhythmUnlockPanel():
    m_state(STATE_NORMAL),
    m_counter(0),
    m_isAnim(VFX_FALSE)
{
}


void VappScreenLockRhythmUnlockPanel::onInit()
{
    VfxControl::onInit();
    
    setBgColor(VFX_COLOR_TRANSPARENT);
    setSize(LCD_WIDTH, SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT);

    //
    //dummy frame, 
    //except arrow, other UI components will be created on it. VRT can cache them together to save cache size.
    //
    VFX_OBJ_CREATE(m_dummyFrame, VfxFrame, this);
    m_dummyFrame->setSize(getSize());
    
    //bg
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, m_dummyFrame);
    m_bg->setResId(IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_SCREENLOCK_BG);
    m_bg->setSize(getSize());
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bg->setCacheMode(VFX_CACHE_MODE_PREVENT);

    //arrow 
    VfxS32 y = SCREEN_LOCK_RHYTHM_ARROW_P0S_Y;
    VfxImageSrc img_arrow(IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_ARROW);
    VfxSize size_arrow = img_arrow.getSize();
    for(VfxS32 i = 0; i < 3; i++)
    {
        VFX_OBJ_CREATE(m_arrow[i], VfxImageFrame, this);
        m_arrow[i]->setAnchor(0.5f, 0.0f);
        m_arrow[i]->setImgContent(img_arrow);
        m_arrow[i]->setPos(LCD_WIDTH/2, y);

        y += size_arrow.height;                
    }

    //arrow animation
    VFX_OBJ_CREATE(m_timerArrowAnimation, VfxTimer, this);
    m_timerArrowAnimation->setStartDelay(250);
    m_timerArrowAnimation->setDuration(250);
    m_timerArrowAnimation->m_signalTick.connect(this, &VappScreenLockRhythmUnlockPanel::onTimerArrowAnimation);
    m_timerArrowAnimation->start();

    //time
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(SCREEN_LOCK_RHYTHM_TIME_FONT_SIZE);
    VFX_OBJ_CREATE(m_time, VfxTextFrame, m_dummyFrame);
    m_time->setAnchor(0.5f, 0.0f);
    m_time->setPos(LCD_WIDTH/2, SCREEN_LOCK_RHYTHM_TIME_POS_Y);
    m_time->setFont(font);
    //ampm
    VFX_OBJ_CREATE(m_AmPm, VfxTextFrame, m_dummyFrame);
    //date
    font.size = VFX_FONT_DESC_VF_SIZE(SCREEN_LOCK_RHYTHM_DATE_FONT_SIZE);
    VFX_OBJ_CREATE(m_date, VfxTextFrame, m_dummyFrame);
    m_date->setAnchor(0.5f, 0.0f);
    m_date->setPos(LCD_WIDTH/2, SCREEN_LOCK_RHYTHM_DATE_POS_Y);
    m_date->setFont(font);
 
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappScreenLockRhythmUnlockPanel::timeUpdate);

    timeUpdate(VDAT_SYSTIME_CHANGED_MIN);
}


VfxBool VappScreenLockRhythmUnlockPanel::onPenInput(VfxPenEvent &event)
{
    VfxPoint pt = event.getRelPos(this);
    if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_state = STATE_PRESSED;
        m_signalStopAnim.emit();
        
        VfxFloat anchor_y = (VfxFloat)pt.y / getSize().height;
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setAnchor(0.0f, anchor_y);
        setPos(0, event.pos.y);
        VfxAutoAnimate::commit();
        setOpacity(0.7f);

        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if(m_state == STATE_PRESSED)
        {
            pt = event.getRelPos(this);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            forcePos(VfxPoint(0, event.pos.y > event.downPos.y ? event.pos.y : event.downPos.y));
            VfxAutoAnimate::commit();
        }
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if(m_state == STATE_PRESSED)
        {
            m_state = STATE_NORMAL;
            m_signalCheckTimer.emit();
            
            if(getPos().y > event.downPos.y + SCREEN_LOCK_RHYTHM_DRAG_THRESHOLD)
            {
                dismiss();
            }
            else if(getPos().y <= event.downPos.y)
            {
                restoreOriginPosition(VFX_TRUE);
            }
            else
            {
                restoreOriginPosition(VFX_FALSE);
            }
        }
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_signalCheckTimer.emit();
        restoreOriginPosition(VFX_FALSE);
        return VFX_TRUE;
    }

    return VfxControl::onPenInput(event);
}


void VappScreenLockRhythmUnlockPanel::timeUpdate(VfxU32 flag)
{
    if(flag & VDAT_SYSTIME_CHANGED_MIN || flag & VDAT_SYSTIME_CHANGED_HOUR)
    {
        VfxDateTime time;
        time.setCurrentTime();

        VfxWChar string_buf[10], ampm_buf[3];
        VfxU8 str_len;
        VfxBool ampm_exist = VFX_FALSE;
        time.getDateTimeString(VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR, (VfxWChar*)string_buf, 10);
        str_len = vfx_sys_wcslen((VfxWChar*)string_buf);
        if(str_len > 6)//with AMPM ,the len will no less than 7
        {
           ampm_exist = VFX_TRUE;
           vfx_sys_wcscpy((VfxWChar*) ampm_buf, (VfxWChar*) &string_buf[str_len-2]);
           string_buf[str_len-3] = 0; /* \space */
           string_buf[str_len-2] = 0; 
           string_buf[str_len-1] = 0;
           m_AmPm->setFullLineHeightMode(VFX_FALSE);
           m_AmPm->setString((ampm_buf));
           m_AmPm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SCREEN_LOCK_RHYTHM_DATE_FONT_SIZE), VFX_FONT_DESC_ATTR_BOLD, VFX_FE1_1));
           m_AmPm->setAutoResized(VFX_TRUE);
        }

       // Time
        m_time->setFullLineHeightMode(VFX_FALSE);
        m_time->setString((string_buf));
        m_time->setAutoResized(VFX_TRUE);

        if(ampm_exist == VFX_TRUE)
        {
            
          m_AmPm->setAnchor(0.0f, 1.0f);
          m_AmPm->setPos(((LCD_WIDTH - m_time->getSize().width)>>1) + m_time->getSize().width + VAPP_SCREEN_LOCK_RHYTHM_TIME_AMPM_GAP, 
                        m_time->getPos().y + (m_time->getSize().height));
        }

        //date
        VfxU32 flags = VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;
        VfxWString str = time.getDateTimeString(flags);
        flags = VFX_DATE_TIME_DAY_MASK | VFX_DATE_TIME_DAY_NORMAL_NAME;
        str += VFX_WSTR(" ");  //add space
        str += time.getDateTimeString(flags);
        m_date->setString(str);
    }
}


void VappScreenLockRhythmUnlockPanel::restoreOriginPosition(VfxBool isNoAnimation)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(isNoAnimation);
    setPos(0, LCD_HEIGHT);
    setOpacity(1.0f);
    setAnchor(0.0, 1.0f);
    VfxAutoAnimate::commit();
    m_state = STATE_NORMAL;
}


void VappScreenLockRhythmUnlockPanel::playArrow()
{
    if (m_timerArrowAnimation && !m_timerArrowAnimation->getIsEnabled())
    {
        m_timerArrowAnimation->start();
    }
}


void VappScreenLockRhythmUnlockPanel::stopArrow()
{
    if (m_timerArrowAnimation && m_timerArrowAnimation->getIsEnabled())
    {
        m_timerArrowAnimation->stop();
    }
}


void VappScreenLockRhythmUnlockPanel::dismiss()
{
    VfxS32Timeline *tl;
    VFX_OBJ_CREATE(tl, VfxS32Timeline, this);
    tl->setTarget(this);
    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    tl->setIsFromCurrent(VFX_TRUE);
    tl->setToValue(LCD_HEIGHT + getSize().height);
    tl->setDuration(250);
    tl->m_signalStopped.connect(this, &VappScreenLockRhythmUnlockPanel::onTimelineStopped);
    tl->start();
}


void VappScreenLockRhythmUnlockPanel::onTimelineStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_signalUnlock.postEmit(this);
}


void VappScreenLockRhythmUnlockPanel::onTimerArrowAnimation(VfxTimer *timer)
{
    m_counter %= 3;
    VfxS32 j = 0;
    for (VfxS32 i = 0; i < 3; i++)
    {
        j = (m_counter - i + 3) % 3;
        m_arrow[i]->setOpacity(s_arrow_opacity[j]);
    }
    m_counter++;
}
/*****************************************************************************
 * Screen Lock Rhythm Indicator Panel Class
 *****************************************************************************/
const VappScreenLockRhythmIndicatorPanel::CellEntry VappScreenLockRhythmIndicatorPanel::s_cellTbl[] = 
{
    VappScreenLockRhythmIndicatorPanel::CellEntry(
        IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_MESSAGE, 
        STR_ID_VAPP_SCREEN_LOCK_RHYTHM_UNREAD_MESSAGE),

    VappScreenLockRhythmIndicatorPanel::CellEntry(
        IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_CALL, 
        STR_ID_VAPP_SCREEN_LOCK_RHYTHM_MISSED_CALL)
};


VappScreenLockRhythmIndicatorPanel::VappScreenLockRhythmIndicatorPanel():
    m_cellCount(0)
{
    for (VfxS32 i = 0; i < CELL_TYPE_TOTAL; i++)
    {
        m_cell[i] = NULL;
    }
}


void VappScreenLockRhythmIndicatorPanel::updateCell(CellTypeEnum type, VfxU32 num)
{
    VFX_ASSERT(type < CELL_TYPE_TOTAL);

    if (0 == num)
    {
        if (m_cell[type] != NULL)
        {
            VFX_OBJ_CLOSE(m_cell[type]);
            m_cell[type] = NULL;
            m_cellCount--;
        }
    }
    else
    {
        if (m_cell[type] == NULL)
        {
            VFX_OBJ_CREATE_EX(m_cell[type], VappScreenLockRhythmIndicatorCell, this, (s_cellTbl[type].m_imgId, s_cellTbl[type].m_strId));
            m_cellCount++;
        }
        m_cell[type]->updateNum(num);
    }

    updateLayout();
}


VfxBool VappScreenLockRhythmIndicatorPanel::isEmpty()
{
    return m_cellCount ? VFX_FALSE : VFX_TRUE;
}


void VappScreenLockRhythmIndicatorPanel::updateLayout()
{
    if (m_cellCount == 0)
    {
        setHidden(VFX_TRUE);
        return;
    }
    
    VfxS32 total_height = m_cellCount * SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT;

    restoreOriginPosition();
    setHidden(VFX_FALSE);
    setSize(LCD_WIDTH, total_height);

    VfxS32 h = 0;
    for (VfxS32 i = 0; i < CELL_TYPE_TOTAL; i++)
    {
        if (m_cell[i] == NULL)
        {
            continue;
        }
        m_cell[i]->setPos(0, h);
        h += SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT;
    }
}


void VappScreenLockRhythmIndicatorPanel::restoreOriginPosition()
{
    setAnchor(0.0f, 1.0f);
    setPos(0, LCD_HEIGHT - SCREEN_LOCK_RHYTHM_UNLOCK_PANEL_HEIGHT + MIX_GAP);
}
/*****************************************************************************
 * Screen Lock Rhythm Indicator Cell Class
 *****************************************************************************/
VappScreenLockRhythmIndicatorCell::VappScreenLockRhythmIndicatorCell(VfxResId image_id, VfxResId string_id):
    m_imgId(image_id),
    m_stringId(string_id)
{
}


void VappScreenLockRhythmIndicatorCell::onInit()
{
    VfxFrame::onInit();

    setSize(LCD_WIDTH, SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT);

    VfxFrame *bg;
    VFX_OBJ_CREATE(bg, VfxFrame, this);
    bg->setSize(LCD_WIDTH, SCREEN_LOCK_RHYTHM_INDICATOR_CELL_HEIGHT);
    bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_INDICATOR_BG));
    bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);      
        
    VFX_OBJ_CREATE(m_img, VfxImageFrame, this);
    m_img->setResId(m_imgId);
    
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
}


void VappScreenLockRhythmIndicatorCell::updateNum(VfxU32 num)
{
    VFX_ASSERT(num > 0);
    num = num > 99 ? 99 : num;

    VfxWString str;
    str.format("%d%d", num/10, num%10);
    str += VFX_WSTR(" ");  //space
    if (num > 1)
    {
        if (m_stringId == STR_ID_VAPP_SCREEN_LOCK_RHYTHM_MISSED_CALL)
        {
            m_stringId = STR_ID_VAPP_SCREEN_LOCK_RHYTHM_MISSED_CALL_MULTIPLE;
        }
        else
        {
           m_stringId = STR_ID_VAPP_SCREEN_LOCK_RHYTHM_UNREAD_MESSAGE_MULTIPLE; 
        }
        
    }
    str += VFX_WSTR_RES(m_stringId);
    m_text->setString(str);

    layout();
}


void VappScreenLockRhythmIndicatorCell::layout()
{
    VfxS32 w_img, w_txt, x_img, x_txt;
    w_img = m_img->getSize().width;

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(SCREEN_LOCK_RHYTHM_INDICATOR_FONT_SIZE);
    font.effect = VFX_FE1_9;
    VfxSize size = font.measureStr(m_text->getString());
    w_txt = size.width;

    x_img = (LCD_WIDTH - w_img - w_txt - 3)/2;
    x_txt = x_img + w_img + 3;
    m_img->setPos(x_img, 0);
    m_text->setPos(x_txt, 0);
    m_text->setFont(font);
}
#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__) */
