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
 *  vapp_screen_lock_liberate.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the liberate screen lock class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_COSMOS_H__
#define __VAPP_SCREEN_LOCK_COSMOS_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)



/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_cosmos_unlock_item_factory.h"
#include "vapp_screen_lock_cosmos_notification_cell.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappScreenLockFrame;
class VappScreenLockTime;
class VappWallpaper;
class VappScreenLockCard;
class VappWidgetMusicPlayerInfoPanel;
class VappWidgetFmRadioPanel;

#define VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME                8

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_OFFSET        (20)
#define VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET             (0)


#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_OFFSET        (16)
#define VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET             (0)


#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_OFFSET        (16)
#define VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET             (25)


#else /* defined(__MMI_MAINLCD_240X320__) */
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_OFFSET        (16)
#define VAPP_SCREEN_LOCK_MEDIA_PANEL_OFFSET             (25)


#endif /* defined(__MMI_MAINLCD_240X320__) */

/*****************************************************************************
 * Screen Lock Cosmos Class
 *****************************************************************************/

/*
 * Screen Lock Cosmos Class
 */
class VappScreenLockLiberate : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockLiberate);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockLiberate();

// Override
public:
    virtual VappScreenLockId getId() const;
    
    // Get string resource ID for the name of this screen lock
    // RETURNS: length of the screen lock name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    // Create screen lock icon.
    // RETURNS: frame
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );

    virtual VfxS32 getScreenshotNum() const;

    VfxFrame **createScreenshot(VfxObject *parentObj) const;

// Override
protected:
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onPageEnter();
    virtual void onPageExit();
    virtual void onSerializeView();
    virtual void onRestoreView();
    virtual VfxResId onGetStatusBarBg();
    virtual VfxBool onGetStatusBarTranslucent();
    virtual void onBacklightOff();
    virtual void onBacklightOn(); 

// Method
private:
    static mmi_ret eventHandler(mmi_event_struct *event); 

    VappScreenLockCard *createUnlockItem(
                VappScreenLockUnlockItemPos pos, VfxObject *parentObj);

    // This function initializes the wallpaper.
    void initWallpaper();

    void createWallpaper();
    void releaseWallpaper();

    // This function deinitializes the wallpaper.
    void deinitWallpaper();

    void wallpaperUpdatedHdlr();

    void onUnlockHandler(VappScreenLockFrame *frame);

    void switchMediaControlPanel();

    void showMediaPanel(VfxBool isShow);

    // Receive media panel close request
    void onMediaPanelClose(VappWidgetMusicPlayerInfoPanel* panel);
    
    // handler when receiving sleep in event
    mmi_ret backlightOffHandler(mmi_event_struct *event);

    // To handle the panel switch between notification panel & media panel
    // while there is a notification changed signal received.
    void onNotificationChanged();
    
    // To handle notofication panel while notifications decrease to zero.
    void onNotificatiEmpty();

    // The cache timeline stopped.
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop);

// Variable
private:

    // Background image frame
    VappWallpaper             *m_wallpaper;

    // operator and time area
    VappScreenLockTime        *m_timeArea;

    VappScreenLockFrame       *m_lockFrame;

    /* Create info panel for image, title, duration, ... */
    VappWidgetMusicPlayerInfoPanel *m_mediaPanel;

    VappWidgetFmRadioPanel *m_fmPanel;
    
    // Notification panel
    VappScreenLockLiberateNotiPanel  *m_notiPanel;
};

#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
#endif /*__VAPP_SCREEN_LOCK_COSMOS_H__ */
