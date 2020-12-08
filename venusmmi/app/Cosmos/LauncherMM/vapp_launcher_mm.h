/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_mm.h
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher MM
 *
 * Description:
 * ------------
 *  Launcher MM
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __VAPP_LAUNCHER_MM_H__
#define __VAPP_LAUNCHER_MM_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_MM__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDatatype.h"

#include "vfx_mc_include.h"

#include "vcp_menu_popup.h"
#include "vcp_page_menu_transition.h"
#include "vcp_status_icon_bar.h"

#include "vapp_launcher_mm_builder.h"
#include "vapp_launcher_mm_gprot.h"
#include "vapp_launcher_mm_page_menu.h"

#include "vapp_launcher.h"
#include "vapp_launcher_primitive.h"

#include "vapp_ncenter.h"

#include "vapp_wallpaper.h"

extern "C"
{
#include "SensorSrvGport.h"
}


/*****************************************************************************
 * Define
 *****************************************************************************/

/* If defined, we will suspend the live wallpaper when the user swipes the
   desktop. This will improve the animation performance. */
#define VAPP_LAUNCHER_MM_SUSPEND_LWP_DURING_SWIPE

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif


/*****************************************************************************
 * Static Constant
 *****************************************************************************/

#ifdef __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT = 96;
#else
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT = 128;
#endif
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_COUNT = 8;

#else // __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT = 120;
#else
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT = 160;
#endif
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_COUNT = 10;

#endif // __LOW_COST_SUPPORT_COMMON__

static const VfxS32 VAPP_LAUNCHER_MM_MAX_APP_DATA_PER_FOLDER = 8;

static const VfxS32 VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER_DATA = 4;
static const VfxS32 VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_APP_DATA = VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER_DATA * VAPP_LAUNCHER_MM_MAX_APP_DATA_PER_FOLDER;

static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA = 16;
static const VfxS32 VAPP_LAUNCHER_MM_MAX_PAGE_APP_DATA = VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA * VAPP_LAUNCHER_MM_MAX_APP_DATA_PER_FOLDER +
                                                         VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT - VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA +
                                                         VAPP_LAUNCHER_MM_MAX_PAGE_COUNT;

static const VfxU32 VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH = 15;

static const VfxS32 VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX = -1;
static const VfxU32 VAPP_LAUNCHER_MM_APP_ORDER_DATA_EMPTY = 0xE0E0E0E0;
static const VfxU32 VAPP_LAUNCHER_MM_APP_ORDER_DATA_DISABLED = 0xD0D0D0D0;
static const VfxU32 VAPP_LAUNCHER_MM_APP_ORDER_DATA_DELETED = 0xD1D1D1D1;


/***************************************************************************** 
 * Structure
 *****************************************************************************/

struct VappLauncherMmAppOrderDataStruct
{
    VfxS32 index;
    VfxS32 subindex;
    VfxU32 appId;
};

struct VappLauncherMmAppFolderDataStruct
{
    VfxS32      index;
    VfxWChar    name[VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH + 1];
};


/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

class VappLauncherMm;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

// Cache data utilities
extern VfxU8 vappLauncherMmGetStringFontEffectId();
extern VfxS32 vappLauncherMmGetStringWidth(mmi_app_package_name_struct &appName);
extern void vappLauncherMmSetStringWidth(mmi_app_package_name_struct &appName, VfxS16 stringWidth);
extern void vappLauncherMmClearStringWidth();

extern VappLauncherMm *vappLauncherMmGetInstance();

// For uninstall icon
void vappLauncherMmUninstallApp(VappLauncherMmCell *cell);

void vappLauncherMmClearOrderData(VappLauncherMmAppOrderDataStruct *orderData);

/***************************************************************************** 
 * Class VappLauncherMm
 *****************************************************************************/

class VappLauncherMm : public VappLauncher
{
    VAPP_LAUNCHER_DECLARE_CLASS(VappLauncherMm);

// Constructor / Destructor
public:
    VappLauncherMm();

// Method
public:
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    void setTransitionEffect(VcpPageMenuTransitionType transitionType);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#ifdef VAPP_LAUNCHER_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    void startListenMotionSensor();
    void stopListenMotionSensor();
#endif

// Override
public:
    // Get Id for this launcher.
    // RETURNS: string ID
    virtual VappLauncherId getId() const;

    // Get string resource ID for the name of this launcher.
    // RETURNS: length of the launcher name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    // Create launcher icon.
    // RETURNS: Launcher icon.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );
    
    // This function gets the number of the screenshots.
    // RETURNS: Number of screenshots.
    virtual VfxS32 getScreenshotNum() const;

    // This function creates the screenshots.
    // RETURNS: Array of the screenshots.
    virtual VfxFrame **createScreenshot(
        VfxObject *parentObj        // [IN] Parent of the screenshots
    ) const;
    
protected:
    // Override this virtual to create the launcher's view.
    virtual void onCreateView();

    // Override this virtual to release the launcher's view.
    virtual void onReleaseView();

    // Override this virtual to handle the scenario when the mobile enters the
    // launcher page.
    virtual void onEnter();

    // Override this virtual to handle the scenario when the mobile exits the
    // launcher page.
    virtual void onExit();
    
    // Override this virtual to serialize your view. This virtual is mainly used
    // to save more memory. Generally, it is called when the home screen becomes
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView(
        VfxArchive *ar      // [OUT] Archive to save your history
    );
    
    virtual VfxResId onGetStatusBarBg();
    
    virtual VfxBool onGetStatusBarTranslucent();
    
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

    // This function handles the wallpaper changed signal.
    virtual void onWallpaperChanged();

// Implementation    
public:

    void onDelBtnClicked(VappLauncherMmCell *cell);
    void onBgRunningPopupClicked(
        VfxObject* obj, 
        VfxId id
    );
    void onPopupButtonClicked(
        VfxObject* obj, 
        VfxId id
    );
	
    void closeDeletingPopup();

    static void onUninstallAppCallback(srv_appmgr_cb_event_enum result, void *user_data);

    void setIsUninstallingMode(VfxBool isUninstalling);

// Variable
private:
    VfxFrame *m_bottomBarBgFrame;
    
    VappLauncherMmPageMenu    *m_menu;
    VappLauncherMmBuilder     *m_builder;
    
    VappWallpaper   *m_wallpaper;
    VfxFrame        *m_wallpaperMask;
    VfxTimer        *m_timerResumeWallpaper;
    
#ifdef VAPP_LAUNCHER_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    SRV_SENSOR_HANDLE   m_doubleTapSensorHandle;
    VfxS32              m_doubleTapSwitchDirection;
    VfxTimer            *m_doubleTapTimer;
#endif
            
    VfxS32  m_dataSyncVersion;
    VfxBool m_isDataDirty;
    VfxBool m_isOrganizeMode;
    VfxBool m_isFolderMode;
    VfxBool m_isEnter;

    VcpIndicatorPopup *m_deletingPopup;
    VfxBool m_isPopupAutoDestory;
	
#if defined(VAPP_LAUNCHER_MM_SUSPEND_LWP_DURING_SWIPE)
    // If wallpaper is suspended when the page is swipping.
    VfxBool m_isSuspendWallpaperForSwipe;
    // If wallpaper is suspended when the user touches the desktop.
    VfxBool m_isSuspendWallpaperForPenDown;
#endif /* defined(VAPP_LAUNCHER_MM_SUSPEND_LWP_DURING_SWIPE) */

    // If wallpaper is suspended because the page exits.
    VfxBool m_isWallpaperSuspendForPageExit;
    // If wallpaper is suspended because notification center is shown.
    VfxBool m_isWallpaperSuspendForNcenter;
    // If wallpaper is suspended because entering edit mode.
    VfxBool m_isWallpaperSuspendForEditMode;
    // If wallpaper is suspended because entering folder mode.
    VfxBool m_isWallpaperSuspendForFolderMode;
    
    static VfxS32   s_currentPage;
    
// Implementation
private:
    void reloadMainmenu();

    void initUI();
    void deinitUI();
    void initMenu();

    // This function creates the wallpaper. The 'delayTime' controls the delay
    // time, in msec., that we will start to animate this wallpaper. If its
    // value is negative, we do not animate it. If its value is 0, we animate
    // it immediately.
    void createWallpaper(
        VfxMsec delayTime = 0   // [IN] Delay time to animate this wallpaper
    );
    // This function creates the wallpaper. This function will consider if we
    // should resume the wallpaper according to the current state of the home
    // screen.
    //
    // SEE ALSO: createWallpaper
    void createWallpaperExt(
        VfxMsec delayTime = 0   // [IN] Delay time to animate the wallpaper
    );
    // This function releases the wallpaper.
    void releaseWallpaper();
    // This function handles the wallpaper mask bounds changed signal.
    void onWallpaperMaskBoundsChanged(VfxFrame *frame, const VfxRect &oldBounds);
    // This function is the signal handler when the notification center changes
    // its state.
    void onNotificationCenterChanged(
        VappNCenterEventEnum event  // [IN] State event
    );
    // This function resumes the wallpaper after the specified time.
    void delayResumeWallpaper(
        VfxMsec delayTime           // [IN] Delay time to resume the wallpaper
    );
    // This function is the time-out handler to resume and animate the wallpaper
    // after we create it.
    void onResumeWallpaper(
        VfxTimer *timer         // [IN] Timer
    );

#if defined(VAPP_LAUNCHER_MM_SUSPEND_LWP_DURING_SWIPE)
    // This function suspends the wallpaper when the user starts to swipe the
    // desktop.
    void suspendWallpaperForSwipe();
    // This function resumes the wallpaper when the user stops swipping the
    // desktop.
    void resumeWallpaperForSwipe();
    // This function suspends the wallpaper when the user touches the desktop.
    void suspendWallpaperForPenDown();
    // This function resumes the wallpaper when the user stops touching the
    // desktop.
    void resumeWallpaperForPenDown();
#endif /* defined(VAPP_LAUNCHER_MM_SUSPEND_LWP_DURING_SWIPE) */

    void onScreenEntered(VfxBool isBackward);
    void onAppClicked(VcpPageMenuCell * cell);
    void onOrganizeChanged(VfxBool organizeMode);
    void onFolderModeChanged(VfxBool isFolderMode);
    void onPageChanged(VfxS32 pageIndex);
    void onPageMoved(VfxS32 translateX, VfxS32 translateDuration);

    void saveAllData();
    
    static mmi_ret eventHandler(mmi_event_struct *event);
    
    // The callback function of the delete icon has been scaled.
    void onDeleteIconScaled(VfxBool isScaled);    
    
#ifdef VAPP_LAUNCHER_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    void onDoubleTapTimerTick(VfxTimer *source);
    static void sensorHandler(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);
#endif
};


#endif // __MMI_VUI_LAUNCHER_MM__


#endif // __VAPP_LAUNCHER_MM_H__

