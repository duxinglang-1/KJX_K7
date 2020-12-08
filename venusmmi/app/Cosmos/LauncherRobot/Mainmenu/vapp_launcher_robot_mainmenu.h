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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_robot_mainmenu.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Launcher Robot Mainmenu
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_ROBOT_MAINMENU_H
#define VAPP_LAUNCHER_ROBOT_MAINMENU_H

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vapp_launcher_robot_mainmenu_page.h"
#include "vfx_control.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/

class VappLauncherRobotMainmenuPage : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherRobotMainmenuPage);

// Constructor / Destructor
public:
	VappLauncherRobotMainmenuPage();

//signal
public:

    // Since m_menu will be closed while onSerialized,
    // so, signal will be closed as well, hence, it needs two singals,
    // m_internalSignalSendIcon->m_signalSendIcon(outer_signal)->robotLauncher,
    // therefore, robotoLauncher can always connect the outer signal not the internal one.
    VfxSignal2 <char *, VfxPoint > m_signalSendIcon;

    // The use of notify if the main menu is ready to show
    VfxSignal0                     m_signalReadyToShow;
    
// Variables
public:
    VappLauncherRobotMainmenuPageMenu * m_menu;
    VfxSignal0 m_homeClicked;   

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        SCREEN_HEIGHT = 800,
        STATUS_BAR_BOUNDS_X = 480,
        STATUS_BAR_BOUNDS_Y = 38,
        BASEMENU_BOUNDS_X = 480,
        BASEMENU_BOUNDS_Y = 688, 
        SHADOW_BOUND_X = 480,
        SHADOW_BOUND_Y = 50,
        SHORTCUT_POS_Y = 719,
        HOME_ICON_BOUNDS_X = 58,
        HOME_ICON_BOUNDS_Y = 58,
        TOP_SHADOW_POS_Y = 37,
        BOTTOM_SHADOW_POS_Y = 669,        
        SHORTCUT_BOUND_X = 480,
        SHORTCUT_BOUND_Y = 81,
        BASEMENU_POS_Y = 35,
        EFFECT_SIZE = 84,
        
    #elif defined(__MMI_MAINLCD_320X480__)
        SCREEN_HEIGHT = 480,
        STATUS_BAR_BOUNDS_X = 320,
        STATUS_BAR_BOUNDS_Y = 24,
        BASEMENU_BOUNDS_X = 320,
        BASEMENU_BOUNDS_Y = 391,
        SHADOW_BOUND_X = 320,
        SHADOW_BOUND_Y = 37,
        SHORTCUT_BOUND_X = 320,
        SHORTCUT_BOUND_Y = 65,
        SHORTCUT_POS_Y = 415,
        HOME_ICON_BOUNDS_X = 46,
        HOME_ICON_BOUNDS_Y = 46,
        TOP_SHADOW_POS_Y = 24,
        BOTTOM_SHADOW_POS_Y = 380,
        BASEMENU_POS_Y = 25,
        EFFECT_SIZE = 70,
        
    #elif defined(__MMI_MAINLCD_240X400__)
        SCREEN_HEIGHT = 400,
        STATUS_BAR_BOUNDS_X = 240,
        STATUS_BAR_BOUNDS_Y = 24,
        BASEMENU_BOUNDS_X = 240,
        BASEMENU_BOUNDS_Y = 330,
        SHADOW_BOUND_X = 240,
        SHADOW_BOUND_Y = 30,
        SHORTCUT_BOUND_X = 240,
        SHORTCUT_BOUND_Y = 47,
        SHORTCUT_POS_Y = 354,
        HOME_ICON_BOUNDS_X = 37,
        HOME_ICON_BOUNDS_Y = 37,
        TOP_SHADOW_POS_Y = 24,
        BOTTOM_SHADOW_POS_Y = 325,
        BASEMENU_POS_Y = 24,
        EFFECT_SIZE = 60,
        
    #else /* defined(__MMI_MAINLCD_240X320__) */ //QVGA
        SCREEN_HEIGHT = 320,
        STATUS_BAR_BOUNDS_X = 240,
        STATUS_BAR_BOUNDS_Y = 24,
        BASEMENU_BOUNDS_X = 240,
        BASEMENU_BOUNDS_Y = 280,
        SHADOW_BOUND_X = 240,
        SHADOW_BOUND_Y = 30,
        SHORTCUT_BOUND_X = 240,
        SHORTCUT_BOUND_Y = 47,
        SHORTCUT_POS_Y = 273,
        HOME_ICON_BOUNDS_X = 37,
        HOME_ICON_BOUNDS_Y = 37,
        TOP_SHADOW_POS_Y = 24,
        BOTTOM_SHADOW_POS_Y = 243,
        BASEMENU_POS_Y = 18,
        EFFECT_SIZE = 60,
        
    #endif 
        
        CACHE_LEN = 2 * SCREEN_HEIGHT
    };

private:
    VfxFrame *m_iconBar;
    VfxImageFrame *m_shortcutBar;
    VfxImageFrame *m_ShadowBarTop;
    VfxImageFrame *m_shadowBarBottom;    
    VcpImageButton *m_shortcutHome;

// Public methods
public:
    VfxResId getStatusBarResId();
    void setRectToVisible();
    void onSerializeView();
    void onRestoreView();
    
// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);    

// Implementation
private:

    // This function is used to create UI componments.
    void initialUI();

    // This function is used to release related UI componments.
    void releaseUI();

    // This function is used to emit signal to home screen while home button clicked.
    void onHomeBtnClicked(VfxObject * sender,VfxId id);   
    
    // This function creates the objects for the 2nd pass loader.
    void create2ndPassLoader();

    // This function is the timeout function to load the 2nd pass components.
    void on2ndPassLoader(
        VfxTimer *timer         // [IN] Timer
    );

    // This function handles the signal which is emitted after long press from base menu's cell
    void onSendIcon(
            VfxChar *package, 
            VfxPoint offset);

    // This function handles the signal while the main menu is ready to show up.
    // By doing this, it can be used as a point to create cache lentgh.
    void onReadyToCache();
};

#endif /*VAPP_LAUNCHER_ROBOT_MAINMENU_H*/
