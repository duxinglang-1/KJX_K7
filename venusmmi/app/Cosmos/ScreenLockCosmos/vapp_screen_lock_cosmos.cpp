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
 *  vapp_screen_lock_liberate.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the liberate screen lock class
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"

#include "vapp_screen_lock_native_factory.h"
#include "vapp_screen_lock_cosmos.h"

#include "vapp_screen_lock_cosmos_unlock_item_kit.h"
#include "vapp_screen_lock_cosmos_unlock_card.h"

#include "vapp_screen_lock_cosmos_frame.h"
#include "vapp_screen_lock_cosmos_time.h"
#include "vapp_wallpaper_kit.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"

// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

//for music player
#include "vapp_widget_music_player.h"

// for fm radio panel
#include "vapp_widget_fm_radio.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_frm_scenario_gprot.h"
#include "GpioSrvGProt.h"
#include "GlobalResDef.h"
#include "AppMgrSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Screen Lock Liberate Class
 *****************************************************************************/

VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockLiberate,
    VAPP_SCREEN_LOCK_TYPE_LIBERATE,
    VappScreenLockLiberatePublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockLiberate, VappScreenLock);


VappScreenLockLiberate::VappScreenLockLiberate():
    m_wallpaper(NULL),
    m_timeArea(NULL),
    m_lockFrame(NULL),
    m_notiPanel(NULL)
#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    ,m_fmPanel(NULL)
#endif
#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    ,m_mediaPanel(NULL)
#endif
{
    // Do nothing.
}


VappScreenLockId VappScreenLockLiberate::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE, 
                            VAPP_SCREEN_LOCK_TYPE_LIBERATE);
}


VfxS32 VappScreenLockLiberate::getName(
    VfxWChar *string,
    VfxS32 size) const
{
    VFX_ASSERT(string && size > 0);
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_NAME);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);
}


VfxFrame *VappScreenLockLiberate::createIcon(
    VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_ICON);

    return icon;
}


VfxS32 VappScreenLockLiberate::getScreenshotNum() const
{
    return 1;
}


VfxFrame **VappScreenLockLiberate::createScreenshot(VfxObject *parentObj) const
{
    VfxFrame **screenshot;
    
    VFX_ALLOC_MEM(screenshot, getScreenshotNum(), parentObj);
    
    VFX_OBJ_CREATE(screenshot[0], VfxImageFrame, parentObj);
    ((VfxImageFrame*)(screenshot[0]))->setResId(IMG_ID_VAPP_SCREEN_LOCK_COSMOS_SETTING_SNAPSHOT);
    return screenshot;
}


void VappScreenLockLiberate::onCreateView()
{ 

    // Create a timeline to force cache frame for performance consideration.
    // In this case, it will cache,
    // Time Area, Lock Frame(no card), Wallpaper,
    VfxFloatTimeline *m_cacheTL;
    VFX_OBJ_CREATE(m_cacheTL, VfxFloatTimeline, this);
    m_cacheTL->setTarget(this);
    m_cacheTL->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_cacheTL->setDurationTime(3);
    m_cacheTL->setFromValue(0.01f);
    m_cacheTL->setToValue(0.0f);
    m_cacheTL->m_signalStopped.connect(this, &VappScreenLockLiberate::onTimelineStop);    
    m_cacheTL->start();

    // Initial unlock screen background wallpaper.
    initWallpaper();

    // Time and Operator area
    VFX_OBJ_CREATE(m_timeArea, VappScreenLockTime, this);
    
    // Create notification panel
    VFX_OBJ_CREATE(m_notiPanel, VappScreenLockLiberateNotiPanel, this);
    m_notiPanel->setAnchor(0.5f, 0.0f);
    m_notiPanel->setPos(getSize().width/2, m_timeArea->getSize().height - VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_SHADOW);
    m_notiPanel->setBounds(VfxRect(0,0, this->getSize().width, this->getSize().height - (LCD_HEIGHT/1.6)));
    m_notiPanel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);    
    m_notiPanel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_notiPanel->setImgContent(VfxImageSrc(IMG_ID_VAPP_SCREEN_LOCK_NOTIFICATION_BG));
    m_notiPanel->setAutoAnimate(VFX_TRUE);
    m_notiPanel->m_signalNotiChanged.connect(this,&VappScreenLockLiberate::onNotificationChanged);
    m_notiPanel->m_signalNotiEmpty.connect(this,&VappScreenLockLiberate::onNotificatiEmpty);

    // Show notification panel if there's notifications in the list at begining.
    // Senario: In scr lock, UCM comes, scr lock exits, missed call, UCM exists, Lock goes back again.
    if(m_notiPanel->m_isNotiEmpty)
    {
        m_notiPanel->setOpacity(0.0f);
    }
    else
    {
        m_notiPanel->setOpacity(1.0f);
        m_notiPanel->m_isNotiShowed = VFX_TRUE;
        m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG_NO_SHADOW, VFX_FALSE);
    }
    
    //
    // Create FM Radio Panel
    //
#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(vadp_fm_radio_is_playing())
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_INIT, 301);
        
        /* Width = 318, Height = 154 */
        VFX_OBJ_CREATE_EX(m_fmPanel, VappWidgetFmRadioPanel, this, (VappWidgetFmRadioPanel::MODE_LOCK));
        m_fmPanel->setAnchor(0.5, 0);
        m_fmPanel->setPos(getSize().width/2, VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT + 
                                             VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH * 2 - 
                                             VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET);
        m_fmPanel->setAutoAnimate(VFX_TRUE);

        // Switch effect between two Panels.
        if(m_notiPanel->getOpacity() == 0)
        {
            m_fmPanel->setOpacity(1.0f);
        }
        else
        {
            m_fmPanel->setOpacity(0.0f);
        }
    }
    else
#endif

    //
    // Create Music Player Panel
    //
#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    {
       VappMusicPlayerService *srv = VFX_OBJ_GET_INSTANCE(VappMusicPlayerService);

       if(srv && srv->getActiveCount() > 0)
        {
            // music player has active list
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_INIT, 300);
            
            /* Width = 318, Height = 154 */
            VFX_OBJ_CREATE_EX(m_mediaPanel, VappWidgetMusicPlayerInfoPanel, this, (VappWidgetMusicPlayerInfoPanel::MODE_LOCK));
            m_mediaPanel->setAnchor(0.5, 0);
            m_mediaPanel->setPos(getSize().width/2, VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT + 
                                                    VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH * 2 - 
                                                     VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET);
            
            m_mediaPanel->m_signalPanelClose.connect(this,&VappScreenLockLiberate::onMediaPanelClose);
            m_mediaPanel->setAutoAnimate(VFX_TRUE);
                
            // Switch effect between two Panels.
            if(m_notiPanel->getOpacity() == 0)
            {
                m_mediaPanel->setOpacity(1.0f);
                m_mediaPanel->setFocused(VFX_TRUE); // for received Key event
            }
            else
            {
                m_mediaPanel->setOpacity(0.0f);
                m_mediaPanel->setFocused(VFX_FALSE);
                m_mediaPanel->setPanelActive(VFX_FALSE);
            }
        }
    }
#endif

    VFX_OBJ_CREATE(m_lockFrame, VappScreenLockFrame, this);
    m_lockFrame->setSize(getSize());
    m_lockFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_lockFrame->setHideUnlockHint(VFX_TRUE);
    m_lockFrame->m_signalUnlocked.connect(this,&VappScreenLockLiberate::onUnlockHandler);
    m_lockFrame->setPos(0, VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH);

    // In order to cache three cards at first launch, we set lockframe as prevent cache,
    // and set force cache while init cards.
    m_lockFrame->setCacheMode(VFX_CACHE_MODE_PREVENT);
    
    // Create and insert cards into unlock page
    VappScreenLockCard *card1;
    card1 = createUnlockItem(VAPP_SCREEN_LOCK_UNLOCK_ITEM_LEFT, m_lockFrame);
    m_lockFrame->addCard(card1);
    
    VappScreenLockCard *card2;
    card2 = createUnlockItem(VAPP_SCREEN_LOCK_UNLOCK_ITEM_MIDDLE, m_lockFrame);
    m_lockFrame->addCard(card2);

    VappScreenLockCard *card3;
    card3 = createUnlockItem(VAPP_SCREEN_LOCK_UNLOCK_ITEM_RIGHT, m_lockFrame);
    m_lockFrame->addCard(card3);

    m_lockFrame->layoutCards();

    mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappScreenLockLiberate::eventHandler, this);
}


void VappScreenLockLiberate::onReleaseView()
{
    m_lockFrame->m_signalUnlocked.disconnect(this,&VappScreenLockLiberate::onUnlockHandler);
    m_notiPanel->m_signalNotiChanged.disconnect(this,&VappScreenLockLiberate::onNotificationChanged);
    m_notiPanel->m_signalNotiEmpty.disconnect(this,&VappScreenLockLiberate::onNotificatiEmpty);
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN,&VappScreenLockLiberate::eventHandler, this);

    deinitWallpaper();
    VFX_OBJ_CLOSE(m_timeArea);
    VFX_OBJ_CLOSE(m_lockFrame);
    VFX_OBJ_CLOSE(m_notiPanel);

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(m_fmPanel)
    {
        VFX_OBJ_CLOSE(m_fmPanel);
    }
#endif

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    if(m_mediaPanel)
    {
        VFX_OBJ_CLOSE(m_mediaPanel);
    }
#endif    
}


VfxResId VappScreenLockLiberate::onGetStatusBarBg()
{
	return IMG_ID_VAPP_SCREEN_LOCK_STATUS_ICON_BAR;
}


VfxBool VappScreenLockLiberate::onGetStatusBarTranslucent()
{
	return VFX_TRUE;
}


void VappScreenLockLiberate::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME*0.7,VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME);

    if(!m_wallpaper)
    {
        createWallpaper();
    }
    else
    {
        m_wallpaper->resume();
    }
}


void VappScreenLockLiberate::onPageExit()
{
    // restore app timer when lock is not active
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    m_wallpaper->suspend();
}
    

void VappScreenLockLiberate::onSerializeView()
{
    if(m_wallpaper)
    {
        m_wallpaper->serializeView();
    }
    
    // reset the state of media/FM panel while page serialized.
    // since there's no key abort mech. in framework.    
    // MAUI_03159225
#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)    
    if(m_mediaPanel)
    {
        m_mediaPanel->setPanelActive(VFX_FALSE);
    }
#endif

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(m_fmPanel)
    {
        m_fmPanel->setPanelActive(VFX_FALSE);
    }
#endif 
}


void VappScreenLockLiberate::onRestoreView()
{
    if(m_wallpaper)
    {
        m_wallpaper->restoreView();
    }
}


void VappScreenLockLiberate::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}


void VappScreenLockLiberate::initWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.connect(this, &VappScreenLockLiberate::wallpaperUpdatedHdlr);

    createWallpaper();
}

    
void VappScreenLockLiberate::createWallpaper()
{
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_LOCK);
}


void VappScreenLockLiberate::releaseWallpaper()
{
    if(m_wallpaper)
    {
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}


void VappScreenLockLiberate::wallpaperUpdatedHdlr()
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


void VappScreenLockLiberate::deinitWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.disconnect(this, &VappScreenLockLiberate::wallpaperUpdatedHdlr);

    releaseWallpaper();
}


void VappScreenLockLiberate::onUnlockHandler(VappScreenLockFrame *frame)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200);
    m_signalUnlock.postEmit(this);
}


VappScreenLockCard *VappScreenLockLiberate::createUnlockItem(
            VappScreenLockUnlockItemPos pos, VfxObject *parentObj)
{
    //
    // Create unlock item.
    //
    VappScreenLockUnlockItemKit *kit;

    VFX_OBJ_CREATE(kit,VappScreenLockUnlockItemKit,parentObj);

    return (VappScreenLockCard *)kit->createUnlockItem(
                                                kit->getUnlockItemId(pos), 
                                                parentObj);
}


void VappScreenLockLiberate::switchMediaControlPanel()
{
#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if (m_fmPanel && m_fmPanel->getOpacity() == 0)
    {
        showMediaPanel(VFX_TRUE);
        return;
    }
    else if (m_fmPanel && m_fmPanel->getOpacity() ==1 &&
             m_notiPanel->m_isNotiShowed && !m_notiPanel->m_isNotiEmpty)
    {
        showMediaPanel(VFX_FALSE);
        return;
    }
#endif

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

    if (m_mediaPanel && m_mediaPanel->getOpacity() == 0)
    {
        showMediaPanel(VFX_TRUE);
        return;
    }
    else if(m_mediaPanel && m_mediaPanel->getOpacity() == 1 &&
            m_notiPanel->m_isNotiShowed && !m_notiPanel->m_isNotiEmpty)
    {
        showMediaPanel(VFX_FALSE);
        return;
    }
#endif
}


void VappScreenLockLiberate::showMediaPanel(VfxBool isShow)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    VfxAutoAnimate::setDuration(250);

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(m_fmPanel)
    {
        if(isShow)
        {
            m_fmPanel->setOpacity(1.0f);
            m_notiPanel->setOpacity(0.0f);
            m_fmPanel->setIsUnhittable(VFX_FALSE);
            m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG, VFX_TRUE);
        }
        else
        {
            m_fmPanel->setOpacity(0.0f); 
            m_notiPanel->setOpacity(1.0f);
            m_fmPanel->setIsUnhittable(VFX_TRUE);

            // Change the background image of time area without shadow
            m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG_NO_SHADOW, VFX_FALSE);
        }
        
    VfxAutoAnimate::commit(); 

        return;
    }
#endif

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    if(m_mediaPanel)
    {
        if(isShow)
        {
            m_mediaPanel->setOpacity(1.0f);
            m_mediaPanel->setFocused(VFX_TRUE);
            m_notiPanel->setOpacity(0.0f);
            m_mediaPanel->setIsUnhittable(VFX_FALSE);
            m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG, VFX_TRUE);             
        }
        else
        {
            m_mediaPanel->setOpacity(0.0f); 
            m_mediaPanel->setFocused(VFX_FALSE);
            m_mediaPanel->setPanelActive(VFX_FALSE);
            m_notiPanel->setOpacity(1.0f);
            m_mediaPanel->setIsUnhittable(VFX_TRUE);
            m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG_NO_SHADOW, VFX_FALSE);
        }

    VfxAutoAnimate::commit(); 

        return;
    }
#endif

    //
    // The case of NO FM radio and Music player widget on screen lock
    //
    if(isShow)
    {
        m_notiPanel->setOpacity(1.0f);
        
        // Change the background image of time area without shadow
        m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG_NO_SHADOW, VFX_FALSE);

    }
    
    VfxAutoAnimate::commit();
}


VfxBool VappScreenLockLiberate::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_HOME &&
        event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        switchMediaControlPanel();
    }

    // key routing handles on screen lock base.
    return VappScreenLock::onKeyInput(event);
}


void VappScreenLockLiberate::onMediaPanelClose(VappWidgetMusicPlayerInfoPanel* panel)
{
#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    if(m_mediaPanel)
    {
        VFX_OBJ_CLOSE(m_mediaPanel);
    }
#endif    
}


void VappScreenLockLiberate::onBacklightOn()
{
    m_lockFrame->isBacklightOff(VFX_FALSE);
}


void VappScreenLockLiberate::onBacklightOff()
{
    m_lockFrame->isBacklightOff(VFX_TRUE);
}


mmi_ret VappScreenLockLiberate::backlightOffHandler(mmi_event_struct *event)
{
#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(m_fmPanel)
    {
        //m_fmPanel->setControlHidden(VFX_TRUE);
    }
#endif

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    if(m_mediaPanel)
    {
        //m_mediaPanel->setControlHidden(VFX_TRUE);
    }
#endif

    return MMI_RET_OK;
}


mmi_ret VappScreenLockLiberate::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappScreenLockLiberate* instance = (VappScreenLockLiberate *)event->user_data;
    
    switch (event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
            instance->backlightOffHandler(event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

void VappScreenLockLiberate::onNotificatiEmpty()
{
    m_notiPanel->setOpacity(0.0f);
    m_timeArea->setTimeAreaBG(IMG_ID_VAPP_SCREEN_LOCK_TIME_BG, VFX_TRUE);
}


void VappScreenLockLiberate::onNotificationChanged()
{

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    if(m_fmPanel)
    {
        if(m_fmPanel->getOpacity() == 1.0f)
        {
        showMediaPanel(VFX_FALSE);
        }
        return;
    }
#endif

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)
    if(m_mediaPanel)
    {
        if(m_mediaPanel->getOpacity() == 1.0f)
        {
        showMediaPanel(VFX_FALSE);
        }
		return;
    }

    //
    // The case of NO FM radio and Music player widget on screen lock
    //

     showMediaPanel(VFX_TRUE);

#endif
}

#endif // __MMI_VUI_SCREEN_LOCK_COSMOS__
