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
 *  vapp_launcher_robot_mainmenu_builder.h
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

#ifndef VAPP_LAUNCHER_ROBOT_MAINMENU_BUILDER_H
#define VAPP_LAUNCHER_ROBOT_MAINMENU_BUILDER_H

#include "MMI_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDatatype.h"
#include "vfx_container.h"
#include "vcp_page_menu_util.h"
#include "vfx_text_frame.h"
#include "vfx_timer.h"

extern "C"
{
#include "AppMgrSrvGprot.h"
}

/*****************************************************************************
  * Class VappLauncherRobotMainmenuCell
  *****************************************************************************/

class VappLauncherRobotMainmenuCell : public VcpPageMenuCell
{
    VFX_DECLARE_CLASS(VappLauncherRobotMainmenuCell);

// Constructor / Destructor
public:
    VappLauncherRobotMainmenuCell(){}
    VappLauncherRobotMainmenuCell(const VfxImageSrc & image, const VfxWString & title);

public:
    void setCellAppName(mmi_app_package_name_struct appName);
    void getCellAppName(mmi_app_package_name_struct & result);

    void setIsPreinstall(VfxBool isPreinstall);
    void setEditMode(VfxBool editMode);
    void updateCacheMode();
    void setBadge(VfxWChar *badge);
    void setBadgeHidden(VfxBool isHidden);
    
    static mmi_ret eventHandler(mmi_event_struct *event);
    virtual void onCellDisplay();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void updateIconImage(const VfxImageSrc & image);
    void updateTitle(const VfxWString & title);
    void updateIsPreinstall(VfxBool isPreinstall);
    VfxBool isEditModeTransitioning();
    void updateBadge();

    VfxImageSrc                 m_cellImage;
    VfxWString                  m_cellTitle;
    VfxWChar                    m_cellBadge[SRV_APPMGR_BADGE_MAX_LEN + 1];

    mmi_app_package_name_struct m_appName;
    VfxBool                     m_firstDisplay;
    VfxBool                     m_onBottomBar;
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isBadgeHidden;
    VfxFrame *                  m_iconBgFrame;
    VfxFrame *                  m_iconBgFrameEdit;
    VfxFrame *                  m_iconFrame;
    VfxTextFrame *              m_textFrame;
    VfxFrame *                  m_textBgFrame;
    VfxFrame *                  m_preinstallFrame;
    VfxFrame *                  m_stableFrameContainer;
    VfxFrame                    *m_badgeBgFrame;
    VfxTextFrame                *m_badgeTextFrame;
    
    static VfxList <VappLauncherRobotMainmenuCell *> s_cellList;

};

VappLauncherRobotMainmenuCell *createMainmenuRobotCell(mmi_app_package_name_struct &appName, VfxObject *parent, VfxBool preinstall);

VappLauncherRobotMainmenuCell *createMainmenuRobotCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame *parent);

#endif /*VAPP_LAUNCHER_ROBOT_MAINMENU_BUILDER_H*/
