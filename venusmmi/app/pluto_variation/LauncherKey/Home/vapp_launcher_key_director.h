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
 *  vapp_launcher_key_director.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the keylauncher director.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_KEYLAUNCHER_DIRECTOR_H
#define VAPP_KEYLAUNCHER_DIRECTOR_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vrt_datatype.h"
#include "vfx_uc_include.h"
#include "vfx_app_cat_scr.h"
#include "vcp_status_icon_bar.h"
#include "vapp_wallpaper.h"
#include "vapp_launcher_key.h"
#include "vapp_launcher_key_def.h"
#include "vapp_launcher_key_primitive.h"
#include "vapp_launcher_key_widget_menu.h"
#include "vapp_op_launcher_key_hs.h"

#include "vapp_launcher_key_mainmenu.h"


//
// C headers
//
extern "C"
{
#include "MMIDataType.h"	
}


/*****************************************************************************
 * KeyLauncher Define
 *****************************************************************************/


/*****************************************************************************
 * KeyLauncher Director Object
 *****************************************************************************/

class VappKeyLauncherDirector : public VfxAppCatScr
{
//    VFX_DECLARE_CLASS(VappKeyLauncherDirector);

// Constructor / Destructor
public:
    // Default constructor
    VappKeyLauncherDirector();
    VappKeyLauncherDirector(MMI_ID app_id);
// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // While leaving the screen to be inactive
    virtual void onExit(VfxBool isBackward);

//
// This block implements the handler for the pen input and key input
//

// Override
protected:
	// Please refer to VfxControl.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );
	
    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//
// This block implements the create/release/switch of three page.
//

// Enum
public:
	// Key launcher include 3 page screen: 
	// Idle page, which include Operator name, Date time...
	// Widget page, which include Widget icons menu and one widget full view
	// Mainmenu page, which is mainmenu, we take it in one part of key laucher, 
	// as to improve performe the switch between Homescreen and Mainmenu
    enum KeyLauncherPage
    {
		IDLE_PAGE,
		WIDGET_PAGE,
		MAINMENU_PAGE,
		NULL_PAGE,
	};

// Variable
public:
	// Screen group Id, for relase asm2.0 memory
    MMI_ID m_groupId;

// Variable
public:
	// Current page, which is used to show when enter (back to) Key launcher app
	static KeyLauncherPage s_currentPage;

	// Pervious page, idle or widget page, which is used to show when back from Mainmenu page
	static KeyLauncherPage s_perviousPage;

// Variable
private:
	// When switch page, some are async swich, we need wait last page close finished
	KeyLauncherPage m_switchToPage;

// Implementation
private:
	// This function create or unhidden all object of this page.
	// will be called in onInit or when switch in three page.
	void createObjofPage(
		KeyLauncherPage   page       // [IN] which page enum
	);

	// This function release or hidden object of this page.
	// Will be called when switch in three page, release as to save RAM, hidden as to speed up next loading
	void releaseObjofPage(
		KeyLauncherPage   page     // [IN] which page enum
	);

	// This function close all object of those three page.
	// Will be called in onDeinit
	void releaseAllObjofPage();

	// This function will release or hidden object of from_page, and create or unhidden object of to_page;
	// If from_page is equal to to_page, we only create or unhidden object of to_page. such as in onInit.
	void switchPage(
		KeyLauncherPage   to_page,       // [IN] which page switch to
		KeyLauncherPage   from_page,     // [IN] which page switch from
		VfxBool needWidgetMenuFlyIn = VFX_FALSE // [IN] only usabe when to_page is WIDGET_PAGE
	);

//
// This block implements the widget menu.
//

// Variable
private:
#ifndef __OP01_3G__
	VappKeyLauncherIdlePage *m_idlePage;
#else
    VappOpKeyLauncherIdlePage *m_idlePage;
#endif

//
// This block implements the widget menu.
//

// Variable
private:
	// widget menu
	VappKeyLauncherWidgetMenu * m_widgetMenu;

	// If need widget menu show fiy in animation.
	// Only fly in when switch from Idle->Widget, or from Main Menu -> Widget; by RSK
	VfxBool m_needWidgetMenuFlyIn;

// Implementation
private:
	// This function creates the widget menu, connect its signal, then show it
	void createWidgetMenu();

	// This function releases the widget menu
	void releaseWidgetMenu(
		VfxBool need_close                //[IN] VFX_TRUE is to close, FALSE is to hidden
	);

	// This function is called when widget menu start/finished fly in or fly out,
	void onWidgetMenuFly(
		VappKeyLauncherWidgetMenu::FlyType ft,  //[IN] fly in or fly out
		VappKeyLauncherWidgetMenu::FlyState fs  //[IN] fly start or fly finish
	);

//
// This block implements the mainmenu.
//
private:
	VappKeyMainmenu *m_mainmenu; //temp

	// If need main menu show fiy in animation.
	// Only fly in when switch from Idle->Main Menu, or from  -> Widget->Main Menu; by RSK
	VappLauncherKmmEntryAnimType m_needMainMenuFlyIn;

// Implementation
private:
	// This function creates the main menu, connect its signal, then show it
	void createMainMenu();

	// This function releases the main menu
	void releaseMainMenu(
		VfxBool need_close                //[IN] VFX_TRUE is to close, FALSE is to hidden
	);

	// This function is called when back from MM, press back key/pen
	void onMainMenuBack();
	

//
// This block implements the wallpaper.
//

// Enum
private:
    enum WallpaperSupendTime
    {
        // Delayed time, in msec., to load the wallpaper. Because loading the
        // wallpaper takes time, if the handset will hang for a while when it
        // just enters the home screen, please tune this parameter.
        WALLPAPER_CREATE_DELAY_TIME = 600,
        WALLPAPER_NORMAL_DELAY_TIME = 300,
        WALLPAPER_SWITCH_DELAY_TIME = 500,   // Widget menu switch animation
        WALLPAPER_PERMANENT_SUSPEND = -1,   // Permanent supend wallpaper until resume
        WALLPAPER_FLY_DELAY_TIME = 3500,    // Widget menu fly in / fly out animation
    };

// Variable
public:
	// container frame
	VfxFrame *m_container;

    // Wallpaper. Mainmenu will use this variable, so need set it as public
    VappWallpaper *m_wallpaper;

    // Time to resume wallpaper after it is created.
    VfxTimer *m_timerResumeWallpaper;

// Implementation
private:
    // This function creates the wallpaper. The 'delayTime' controls the delay
    // time, in msec., that we will start to animate this wallpaper. If its
    // value is negative, we do not animate it. If its value is 0, we animate
    // it immediately.
    void createWallpaper(
        VfxMsec delayTime = 0   // [IN] Delay time to animate this wallpaper
    );

    // This function releases the wallpaper.
    void releaseWallpaper();

public:
    // This function resumes the wallpaper after the specified time.
    void delayWallpaper(
        VfxMsec delayTime       // [IN] Delay time to resume the wallpaper
    );

	//This function get wallpaper handle
	VappWallpaper *getWallpaper(void)
	{
		return m_wallpaper;
	}
	//This function get container handle, for cache wallpaper + mainemnu bg
	VfxFrame *getContainer(void)
	{
		return m_container;
	}
private:
    // This function is the time-out handler to resume and animate the wallpaper
    // after we create it.
    void onResumeWallpaper(
        VfxTimer *timer         // [IN] Timer
    );

//
// This block implements the toolbar.
//

// Variable
private:
    // Toolbar, include "Mainmenu" "Widgets"  in Idle page; "Mainmenu" "Idle" in Widget page.
    VappKeyLauncherToolbar *m_toolbar;

// Implementation
private:
    // This function creates the toolbar.
    void createToolbar();

    // This function releases the toolbar.
    void releaseToolbar();

    // This function is the callback function when a button on the toolbar is
    // clicked.
    void onToolbarExecute(
        VfxObject *toolbar,           // [IN] Toolbar
        VfxId buttonId,               // [IN] The clicked button
        VcpSoftkeyEventEnum event
    );

//
// This block implements the status icon bar.
//

// Implementation
private:
    // Status icon bar.
    VcpStatusIconBar *m_statusIconBar;

// Implementation
private:
    // This function creates the status icon bar.
    void createStatusIconBar();

    // This function releases the status icon bar.
    void releaseStatusIconBar();

//
// This block implements the rest.
//

// Implementation
private:
	// When capture key_down, need handle key_up also.
	VfxBool m_captureKey;

	// If we capture the pen event.
    VfxBool m_isCapturedPen;

};

#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_KEYLAUNCHER_DIRECTOR_H */


