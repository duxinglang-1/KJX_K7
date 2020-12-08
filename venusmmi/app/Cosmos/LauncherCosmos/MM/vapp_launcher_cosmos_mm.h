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
 *  vapp_launcher_cosmos_mm.h
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher Cosmos
 *
 * Description:
 * ------------
 *  Launcher Cosmos Main Menu
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#ifndef __VAPP_LAUNCHER_COSMOS_MM_H__
#define __VAPP_LAUNCHER_COSMOS_MM_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDatatype.h"

#include "vfx_mc_include.h"

#include "vcp_menu_popup.h"
#include "vcp_page_menu_transition.h"
#include "vcp_status_icon_bar.h"

#include "vapp_launcher.h"

#include "vapp_launcher_cosmos_mm_builder.h"
#include "vapp_launcher_cosmos_mm_gprot.h"
#include "vapp_launcher_cosmos_mm_page_menu.h"

#include "vapp_ncenter.h"

#include "vapp_wallpaper.h"

extern "C"
{
#include "SensorSrvGport.h"
}


/*****************************************************************************
 * Define
 *****************************************************************************/

#define VAPP_LAUNCHER_COSMOS_MM_IN_PAGE

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif

// Disable translucent background in WVGA project
#if !defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND
#endif


/*****************************************************************************
 * Static Constant
 *****************************************************************************/

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA = 4;

#ifdef __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA = 96;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA = 128;
#endif

#else // __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA = 120;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA = 160;
#endif

#endif // __LOW_COST_SUPPORT_COMMON__


/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

class VappLauncherCosmosMmContent;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

extern VfxS32 vappLauncherCosmosMmGetCellCountInPage();
extern VappLauncherCosmosMmContent *vappLauncherCosmosMmGetInstance();

// For uninstall icon
void vappLauncherCosmosMmUninstallApp(VappLauncherCosmosMmCell *cell);

/*****************************************************************************
 * Pre-declaration
 *****************************************************************************/
#if defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE)
class VappLauncherCosmosMmScr;
#endif

class VappLauncherCosmosMmContent;

#if defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE)

/*****************************************************************************
 * Class VappLauncherCosmosMmApp
 *****************************************************************************/

class VappLauncherCosmosMmApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmApp);

// Override
protected:
    virtual void onRun(void *args, VfxU32 argSize);

// Variable
private:
    VappLauncherCosmosMmScr *m_scr;
};


/*****************************************************************************
 * Class VappLauncherCosmosMmScr
 *****************************************************************************/

class VappLauncherCosmosMmScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmScr);

// Constructor / Destructor
public:
    VappLauncherCosmosMmScr();

// Method
public:
    void reloadMainmenu();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited(VfxBool isBackward);

    virtual void onSnapshotEnter();
    virtual void onSnapshotExit();

// Variable
private:
    VappLauncherCosmosMmContent *m_content;
};

#endif /* defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE) */

#ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
/*****************************************************************************
 * Class VappLauncherCosmosMmPage
 *****************************************************************************/

class VappLauncherCosmosMmPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmPage);

// Constructor / Destructor
public:
    VappLauncherCosmosMmPage(){}
    VappLauncherCosmosMmPage(VappLauncherCosmosMmContent * content);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExited2();

// Variable
private:
    VappLauncherCosmosMmContent * m_content;

// Implementation
private:
    void onAppInactive(VfxBool isSnapshot);
};
#endif // VAPP_LAUNCHER_COSMOS_MM_IN_PAGE


/*****************************************************************************
 * Class VappLauncherCosmosMmContent
 *****************************************************************************/

class VappLauncherCosmosMmContent : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmContent);

// Constructor / Destructor
public:
    VappLauncherCosmosMmContent();

// Method
public:
    void onMainmenuEnter(VfxBool isBackward);
    void onMainmenuEntered();
    void onMainmenuExit();
    void onMainmenuExited();
    
    void reloadMainmenu();
    
    void onDelBtnClicked(VappLauncherCosmosMmCell *cell);
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
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    void setTransitionEffect(VcpPageMenuTransitionType transitionType);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    void startListenMotionSensor();
    void stopListenMotionSensor();
#endif
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Variable
private:
    VcpStatusIconBar    *m_statusBar;
    
    VappLauncherCosmosMmPageMenu    *m_menu;
    VappLauncherCosmosMmBuilder     *m_builder;
    VfxTransformTimeline *m_iconScaleTimeline;
    
#if defined(VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND)
    VfxFrame    *m_wallpaperMask;
#endif
    
#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    SRV_SENSOR_HANDLE   m_doubleTapSensorHandle;
    VfxS32              m_doubleTapSwitchDirection;
    VfxTimer            *m_doubleTapTimer;
#endif
        
    VfxS32  m_dataSyncVersion;
    VfxBool m_isDataDirty;
    VfxBool m_isOrganizeMode;
    
    VcpIndicatorPopup *m_deletingPopup;
    VfxBool m_isPopupAutoDestory;

    static VfxS32   s_currentPage;
    
public:
    VfxBool m_isEnter;
    VfxBool m_isEnterBackward;

// Implementation
private:
    void initUI();
    void deinitUI();
    void initMenu();
    
    void onScreenEntered(VfxBool isBackward);
    void onAppClicked(VcpPageMenuCell * cell);
    void onOrganizeChanged(VfxBool organizeMode);
    void onPageChanged(VfxS32 pageIndex);

    VappLauncher *findLauncher();
    
    static mmi_ret eventHandler(mmi_event_struct *event);

    // The callback function of the delete icon has been scaled.
    void onDeleteIconScaled(VfxBool isScaled);
    
    // This function is the signal handler when the notification center changes
    // its state.
    void onNotificationCenterChanged(
        VappNCenterEventEnum event  // [IN] State event
    );
#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    void onDoubleTapTimerTick(VfxTimer *source);
    static void sensorHandler(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);
#endif
};


#endif // __MMI_VUI_LAUNCHER_COSMOS__


#endif // __VAPP_LAUNCHER_COSMOS_MM_H__

