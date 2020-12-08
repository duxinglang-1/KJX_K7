/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_robot_mainmenu.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Cosmos Vertical Mainmenu
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#include "vapp_launcher_robot_mainmenu.h"
#include "mmi_rp_vapp_launcher_robot_mainmenu_def.h"
#include "mmi_rp_srv_status_icons_def.h"

//get app name
extern "C" {
#include "AppMgrSrvGprot.h"
}


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Function
 *****************************************************************************/

//Use VfxFrame instead of VfxPage for specific reason of 'press icon from mainmenu to home screen' feature,
//Laucnher framework will receive pen abort if use VfxFrame to do it.
// Block pen event routing, change to VfxConrtol in order to block penInput routing,
// otherwise, swipe shortcut bar in mainmenu, it will swipe home screen page (linear transform) as well
// and therefore cause performance/FPS degraded.
VFX_IMPLEMENT_CLASS("VappLauncherRobotMainmenuPage", VappLauncherRobotMainmenuPage, VfxControl);

VappLauncherRobotMainmenuPage::VappLauncherRobotMainmenuPage():
    m_menu(NULL),
	m_iconBar(NULL),
    m_shortcutBar(NULL),
    m_ShadowBarTop(NULL),
    m_shadowBarBottom(NULL),
    m_shortcutHome(NULL)
{
    //do nothing.
}


void VappLauncherRobotMainmenuPage::onInit()
{
    VfxControl::onInit();
    initialUI();
}


void VappLauncherRobotMainmenuPage::onDeinit()
{
    releaseUI();
    VfxControl::onDeinit();
}


void VappLauncherRobotMainmenuPage::initialUI()
{
    //Create bg of status icon bar
    VFX_OBJ_CREATE(m_iconBar,VfxFrame,this);
    m_iconBar->setPos(0,0);
    m_iconBar->setBgColor(VFX_COLOR_BLACK);
    m_iconBar->setBounds(VfxRect(0, 0, STATUS_BAR_BOUNDS_X, STATUS_BAR_BOUNDS_Y));
    
    //Create top shadow bar
    VFX_OBJ_CREATE(m_ShadowBarTop, VfxImageFrame, this);
    m_ShadowBarTop->setPos(VfxPoint(0, TOP_SHADOW_POS_Y));
    m_ShadowBarTop->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_SHADOW_TOP);
    m_ShadowBarTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_ShadowBarTop->setBounds(VfxRect(0, 0, SHADOW_BOUND_X, SHADOW_BOUND_Y));
    m_ShadowBarTop->setIsUnhittable(VFX_TRUE);

    //create base menu
    VFX_OBJ_CREATE(m_menu, VappLauncherRobotMainmenuPageMenu, this);
    m_menu->setPos(VfxPoint(0, BASEMENU_POS_Y));
    m_menu->setBounds(VfxRect(0, 0, BASEMENU_BOUNDS_X, BASEMENU_BOUNDS_Y));
    m_menu->setBgColor(VFX_COLOR_BLACK);
    m_menu->sendToBack();
    m_menu->setCacheLen(1);
    m_menu->m_internalSignalSendIcon.connect(this, &VappLauncherRobotMainmenuPage::onSendIcon);

    //Create bottom shadow bar
    VFX_OBJ_CREATE(m_shadowBarBottom, VfxImageFrame, this);
    m_shadowBarBottom->setPos(VfxPoint(0, BOTTOM_SHADOW_POS_Y));
    m_shadowBarBottom->setResId(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_SHADOW_BOTTOM);
    m_shadowBarBottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shadowBarBottom->setBounds(VfxRect(0, 0, SHADOW_BOUND_X, SHADOW_BOUND_Y));
    m_shadowBarBottom->setIsUnhittable(VFX_TRUE);

    //Create shortcut bar    
    VFX_OBJ_CREATE(m_shortcutBar, VfxImageFrame, this);
    m_shortcutBar->setPos(VfxPoint(0, SHORTCUT_POS_Y));
    m_shortcutBar->setBounds(VfxRect(0, 0, SHORTCUT_BOUND_X, SHORTCUT_BOUND_Y));
    m_shortcutBar->setBgColor(VFX_COLOR_BLACK);

    //Create home button on the shortcut bar
    VFX_OBJ_CREATE(m_shortcutHome, VcpImageButton, m_shortcutBar);
    m_shortcutHome->setImage(VcpStateImage(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_HOME));
    m_shortcutHome->setAnchor(0.5f , 0.5f);
    m_shortcutHome->setPos(m_shortcutBar->getSize().width / 2, m_shortcutBar->getSize().height /2);
    m_shortcutHome->setBounds(VfxRect(0, 0, HOME_ICON_BOUNDS_X, HOME_ICON_BOUNDS_Y));
    m_shortcutHome->setIsEffect(VFX_TRUE);
    m_shortcutHome->setEffectSize(VfxSize(EFFECT_SIZE, EFFECT_SIZE));
    m_shortcutHome->m_signalClicked.connect(this, &VappLauncherRobotMainmenuPage::onHomeBtnClicked);

    //Connect signal if main menu is ready to show up and use this point to create cache.
    m_signalReadyToShow.connect(this, &VappLauncherRobotMainmenuPage::onReadyToCache);
}


void VappLauncherRobotMainmenuPage::releaseUI()
{
    // Not release resource if it has been released.
    if(m_menu)
    {
        m_menu->m_internalSignalSendIcon.disconnect(this, &VappLauncherRobotMainmenuPage::onSendIcon);
        m_signalReadyToShow.disconnect(this, &VappLauncherRobotMainmenuPage::onReadyToCache);
        
        VFX_OBJ_CLOSE(m_iconBar);
        VFX_OBJ_CLOSE(m_ShadowBarTop);
        VFX_OBJ_CLOSE(m_menu);
        VFX_OBJ_CLOSE(m_shadowBarBottom);
        VFX_OBJ_CLOSE(m_shortcutBar);
    }
}


void VappLauncherRobotMainmenuPage::create2ndPassLoader()
{
    //
    // Create timer to handle the 2nd pass of APP's activation. The timer will
    // expire immediately, i.e., 1 msec, because we only want to accelerate the
    // rendering time of the first frame.
    //
    VfxTimer *timer2ndPassLoader;
    VFX_OBJ_CREATE(timer2ndPassLoader, VfxTimer, this);
    timer2ndPassLoader->setStartDelay(1);
    timer2ndPassLoader->m_signalTick.connect(this, &VappLauncherRobotMainmenuPage::on2ndPassLoader);

    //
    // Start timer.
    //
    timer2ndPassLoader->start();
}


VfxBool VappLauncherRobotMainmenuPage::onPenInput(VfxPenEvent &event)
{
    return VFX_TRUE;
}


void VappLauncherRobotMainmenuPage::onSendIcon(
                                    VfxChar *package,
                                    VfxPoint offset)
{
    // The outer signal for sending icon to robot launcher
    m_signalSendIcon.emit(package,offset);
}


void VappLauncherRobotMainmenuPage::onReadyToCache()
{
    create2ndPassLoader();

    // The first child frame of base menu is scrollable,
    // in order to cache each cell, must set scrollable as preCacheChildren.
    m_menu->getFirstChildFrame()->preCacheChildren();
}


void VappLauncherRobotMainmenuPage::onSerializeView()
{
    releaseUI();
}


void VappLauncherRobotMainmenuPage::onRestoreView()
{
    initialUI();
}


void VappLauncherRobotMainmenuPage::setRectToVisible()
{
    // return to the current view if switching between launcher and mainmenu.
    const VfxS32 currentViewY = m_menu->getViewBounds().origin.y;
    m_menu->scrollRectToVisible(VfxRect(0, currentViewY, m_menu->getSize().width, m_menu->getSize().height),VFX_FALSE);
}


void VappLauncherRobotMainmenuPage::on2ndPassLoader(VfxTimer *timer)
{
    //set cache length in pixel
    if(m_menu)
    {
        m_menu->setCacheLen(CACHE_LEN);
    }
    
    VFX_OBJ_CLOSE(timer);
}


VfxResId VappLauncherRobotMainmenuPage::getStatusBarResId()
{
    VfxResId StatusBarId = IMG_ID_VAPP_LAUNCHER_ROBOT_MM_STATUS_BAR_BG;
    return StatusBarId;
}


void VappLauncherRobotMainmenuPage::onHomeBtnClicked(VfxObject * sender,VfxId id)
{
    m_homeClicked.emit();
}
