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
 *  vapp_launcher_robot_mainmenu_page.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Vertical Mainmenu
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_LAUNCHER_ROBOT_MAINMENU_PAGE_H
#define VAPP_LAUNCHER_ROBOT_MAINMENU_PAGE_H

#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_robot_mainmenu_builder.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)

    const mmi_app_package_name_struct extractAdd[]= 
    {
        "native.mtk.launcher_robot_page_transition_setting"
    };
#endif

class VappLauncherRobotMainmenuPage;

/***************************************************************************** 
 * VappLauncherRobotMainmenuPage-menu
 *****************************************************************************/

class VappLauncherRobotMainmenuPageMenu : public VcpBaseMenu
{
    VFX_DECLARE_CLASS(VappLauncherRobotMainmenuPageMenu);

// Constructor / Destructor
public:
    VappLauncherRobotMainmenuPageMenu();

//signal
public:
    // Since m_menu will be closed while onSerialized,
    // so, signal will be closed as well and therefore, it needs two singals,
    // m_internalSignalSendIcon->m_signalSendIcon(outer_signal)->robotLauncher,
    // by doing this, robotoLauncher always connect the outer signal not the internal one.
    VfxSignal2 <char *, VfxPoint > m_internalSignalSendIcon;

// Variables
private:
    VfxS32 m_focusCellIdx;
    VappLauncherRobotMainmenuPage * m_page;
    VfxS32 m_preCreatedCell;
    mmi_app_package_name_struct * m_newAppList;
    mmi_app_package_name_struct *m_preAppList;
    mmi_app_package_name_struct m_launchApp;


    //#if 0 //try to move to menuCell section
    VappLauncherRobotMainmenuCell *m_cell;
    //#endif

protected:
    VfxS32  m_firstPos;
    VfxS32  m_testStyle;
    VfxBool m_cellTextVisible;
    VfxBool m_dragMode;
    VfxS32  m_delayTicks; // this is for simulate if create cell is very slow
    VfxBool m_isSupportTransition;
    

// Public methods
public:
    void nextStyle();
    void launchApp(VfxU32 pos);
    void reloadMainmenu();  
    
// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VcpBaseMenuLayout* createLayout();
    virtual VfxFrame* createGroupHeader(VfxS32 group);
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);
    virtual void onBeforeUpdate(const VcpMenuRegion& currentRegion,const VcpMenuRegion& targetRegion);
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag);
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell);
    virtual void onTouchCell(
        VcpMenuPos          cellPos,
        CellTouchTypeEnum   touchType,
        VfxPoint            pt,
        VfxFrame            *cell
    );   
    virtual void onDragStart();
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onDragEnd();
    virtual VfxBool IsSupportTransition();

// Implementation
private:

    void queryAppInfo();
    void queryPreAppInfo();
    VfxBool isPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount);
    void sortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount);
    VfxU32 getAppTypeOrder(mmi_app_package_name_struct appName);
    static mmi_ret eventHandler(mmi_event_struct *event);    

    // This function post launches applications.
    void postLaunch(
        VfxU32 pos
    );
};


/***************************************************************************** 
 * VappLauncherRobotMainmenuPage-MenuLayout 
 *****************************************************************************/

class VappLauncherRobotMainmenulPageMenuLayout : public VcpBaseMenuLayout
{
    VFX_DECLARE_CLASS(VappLauncherRobotMainmenulPageMenuLayout );

// Constructor / Destructor
public:
    VappLauncherRobotMainmenulPageMenuLayout();

    VappLauncherRobotMainmenulPageMenuLayout(VcpBaseMenu* menu);
    
// Variables
private:
  
  VfxS32 m_totalAppNum;

public:
    VfxU32 m_itemCount;

// Public methods
public:
    VcpMenuPos getCellByPos(VfxPoint pt);
    void setColumnCount(VfxS32 cnt);
    VfxS32 getColumnCount();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual ScrollDirEnum getScrollDir();
    virtual VfxS32 getGroupCount();    
    virtual VfxS32 getCellCount(VfxS32 group);
    virtual VfxS32 getContentLength();
    virtual VfxBool hasGroupHeader(VfxS32 group);
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    virtual VfxRect queryGroupHeaderRect(VfxS32 group);
    virtual VfxRect queryCellRect(VcpMenuPos pos);
    virtual void getPreferFocusMargin(VfxS32 margin[4]);
    virtual void onViewChanged();   
    virtual VfxBool navDir(NavDirEnum dir);
    
private:
    VfxS32 getGroupByY(VfxS32 y);
    VfxS32 getWholeGroupHeight(VfxS32 group);
    void resetCache();

// Implementation
private:

protected:
    VfxS32 m_cellHeight;
    VfxS32 m_cellWidth;
    VfxS32 m_headerHeight;
    VfxS32 m_columnCount;
    VfxS32 m_groupGap;
    VfxS32 m_groupStartPt[4]; 
};


/***************************************************************************** 
 * VappLauncherRobotMainmenuPage MenuCell 
 *****************************************************************************/

class VappLauncherRobotMainmenuPageMenuCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherRobotMainmenuPageMenuCell);
    
// Constructor / Destructor
public:
    VappLauncherRobotMainmenuPageMenuCell();

// Variables
private:

        VfxBool          m_highlight;
        VfxS32           m_group, m_pos;
        VfxBool          m_dragging;
        VfxPoint         m_dragPt;
        
// Public methods
public:
    void setHighlight(VfxBool isHighLight, VfxBool isAnim);
    void enter(const VfxRect& r, VfxBool animation, VfxS32 delay);
    void withdraw();
    void leave(const VfxRect& r);
    void updatePos(const VfxRect& r, VfxBool isAnim);
    void click(VfxS32 pos);
    void setAppOrderData(mmi_app_package_name_struct orderData[], VfxS32 count);

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void setBounds(const VfxRect &value);
    virtual void onUpdate();
    
// Implementation
private:
    void getCellAppName(mmi_app_package_name_struct & result);
};
#endif /*VAPP_LAUNCHER_ROBOT_MAINMENU_PAGE_H*/
