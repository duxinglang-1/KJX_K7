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
 *  vapp_launcher_key_mainmenu.h
 *
 * Project:
 * --------
 *  Launcher key
 *
 * Description:
 * ------------
 *  Launcher key mainmenu
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VAPP_LAUNCHER_KEY_MAINMENU_H__
#define __VAPP_LAUNCHER_KEY_MAINMENU_H__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_KEY__

#include "MMIDataType.h"
#include "vfx_datatype.h"
#include "vcp_status_icon_bar.h"
#include "vapp_launcher_key_mainmenu_builder.h"
#include "vapp_wallpaper.h"
#include "vfx_app_cat_scr.h"
extern "C" {
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "AppMgrSrvGprot.h"
}
#include "vcp_softkey.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
enum VappLauncherKmmEntryAnimType
{
    VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE = 0,
    VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_IDLE,
	VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_WIDGET,

    VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_MAX
};

// sync with home screen
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define  VAPP_KMM_SOFTKEY_BAR_HEIGHT  (23)
#define  VAPP_KMM_SOFTKEY_BAR_GAP (12)
#define  VAPP_KMM_SOFTKEY_WIDTH (80)
#define VAPP_LAUNCHER_KEY_MM_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(18)
#define  VAPP_KMM_MENU_MARGERN_X  (2)
#elif defined(__MMI_MAINLCD_320X240__)
#define  VAPP_KMM_SOFTKEY_BAR_HEIGHT  (20)
#define  VAPP_KMM_SOFTKEY_BAR_GAP (30)
#define  VAPP_KMM_SOFTKEY_WIDTH (80)
#define VAPP_LAUNCHER_KEY_MM_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(18)
#define  VAPP_KMM_MENU_MARGERN_X  (11)
#else
#define  VAPP_KMM_SOFTKEY_BAR_HEIGHT  (30)
#define  VAPP_KMM_SOFTKEY_BAR_GAP (20)
#define  VAPP_KMM_SOFTKEY_WIDTH (LCD_WIDTH/2)
#define VAPP_LAUNCHER_KEY_MM_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(22)
#define  VAPP_KMM_MENU_MARGERN_X  (2)
#endif

#if !defined(__MMI_FTE_SUPPORT_SLIM__)
	#define __VAPP_KMM_SHOW_MENU_BG__
#endif
// config max app count
// need sync with nvram_common_def.h
#if defined(__MMI_MAINLCD_240X320__)
	#define VAPP_KEY_MAINMENU_SAVED_DATA_COUNT  (34 * 3)
#elif defined(__MMI_MAINLCD_240X400__)
	#define VAPP_KEY_MAINMENU_SAVED_DATA_COUNT  (21*5)
#elif defined(__MMI_MAINLCD_320X240__)
    #define VAPP_KEY_MAINMENU_SAVED_DATA_COUNT  (32*3)
#else
	#define VAPP_KEY_MAINMENU_SAVED_DATA_COUNT  (34 * 3)
#endif

/***************************************************************************** 
 * Structure
 *****************************************************************************/

struct VappKeyMainmenuConfirmCtx
{
    MMI_STR_ID              string_id;
    mmi_event_notify_enum   event;
    mmi_confirm_type_enum   ctype;
    mmi_proc_func           proc;
};

struct VappKeyMainmenuPopupCtx
{
    MMI_STR_ID              string_id;
    mmi_event_notify_enum   event;
    MMI_ID                  parent_id;
};

/*****************************************************************************
 * Global Function
 *****************************************************************************/

void vapp_key_mainmenu_uninstall_app(VappKeyMainmenuCell *cell);

/***************************************************************************** 
 * Class VappKeyMainmenu
 *****************************************************************************/
class VappKeyMainmenu : public VfxControl
{

// Constructor / Destructor
public:
    VappKeyMainmenu();
//Enum
public:
    enum{
        #ifdef __MMI_FTE_SUPPORT_SLIM__
        ENTRY_ANIM_TIME = 400,
        RESTORE_EFFECT_DURATION = 400,
        #else
        ENTRY_ANIM_TIME = 200,
		RESTORE_EFFECT_DURATION = 170,
        #endif
        ENTRY_ANIM_DURATION = 200,
		RESTORE_WALLPAPER_DURATION = 2000,
		SHOW_POPUP_DELAY = 300
    };
// Methods
public:
    void show(VappLauncherKmmEntryAnimType type);
    void reloadMainmenu();
// Events
public:
    VfxSignal0 m_backFromMainmenu;

// static variable  
public:
    static VfxBool  m_isOrganizeMode;
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	static VcpPageMenuTransitionType m_animType;
	static VfxBool m_isRandom;
#endif
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    
public:	
    virtual void setHidden(VfxBool value);
    VfxBool getIsHidden();    
    static mmi_ret EventHandler(mmi_event_struct *event);
// Variable
private:
    VappKeyMainmenuPageMenu      *m_menu;
    VappKeyMainmenuBuilder       *m_builder;
    VcpSoftkey              *m_softkeybar;
    VcpPageMenuCell         *m_highlightCell;   
    static VfxS32   m_currentPage;
    static VfxS32   m_highlightIndex;
	VfxBool m_isAnmiation;
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	VfxFrame *m_menu_bg;
#endif
	VfxBool m_isHidden;
	VfxBool m_isCskDown;
// Implementation
private:
    void showAnimation();
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	void initPageMenuSwitchAnimType();
#endif
    void initMenu();
// wallpaper 
	void suspendWallpaper();
	void resumeWallpaper();
    
    void onAppClicked(VcpPageMenuCell *cell);
    void onOrganizeChanged(VfxBool organizeMode);
    void onHighlightChanged(VcpPageMenuCell *cell);
	void onSuspendWallpaper(VfxBool is_suspend);
    
  //  void handleRsk(void *data);
    void handleClearKey(void *data);
    void onEventLsk(VcpSoftkeyEventEnum event_type);
    void onEventRsk(VcpSoftkeyEventEnum event_type);
	void CreateOptionList();
	void onEntryAnimTimer(VfxTimer *source);
	void onRestoreTimer(VfxTimer *source);
	void onRestoreWallpaperTimer(VfxTimer *source);
	void onShowPopup(VfxTimer *source);
};

/***************************************************************************** 
 * Class VappLauncherMmScr  for backround call.
 *****************************************************************************/
class VappLauncherMmWallpaper : public VfxFrame
{
	VFX_DECLARE_CLASS(VappLauncherMmWallpaper);
public:
	void resume(){};
	void suspend(){};
};
class VappLauncherMmScr : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VappLauncherMmScr);
// Declaration
private:

// Constructor / Destructor
public:
    VappLauncherMmScr();
public:
	static VfxBool m_isActive;
private:
	void onMainMenuBack();
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
// Variable
public:
    VcpStatusIconBar        *m_statusBar;
	VappLauncherMmWallpaper *m_wallpaper;
	VappKeyMainmenu *m_menu;
};

// utils
VfxS32 vappKeyMainmenuGetCellCountInPage();

#endif // __MMI_VUI_LAUNCHER_KEY__

#endif // __VAPP_LAUNCHER_KEY_MAINMENU_H__

