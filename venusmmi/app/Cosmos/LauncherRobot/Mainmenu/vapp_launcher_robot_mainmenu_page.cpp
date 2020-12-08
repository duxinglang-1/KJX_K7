/*******************************************************************************
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*******************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_robot_mainmenu_page.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 * removed!
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#include "vapp_launcher_robot_mainmenu_page.h"
#include "vfx_async_signal.h"

extern "C" 
{
    #include "AppMgrSrvGprot.h" //get app info
}


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static VfxU32 getTotalAppNum()
{
    U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);

    U32 preCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    U32 totalCount = count + preCount;

    #if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)
        return (VfxS32)totalCount + 2;
    #else
        return (VfxS32)totalCount + 1;
    #endif
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)   //WVGA
static const VfxS32 ROBOT_MAINMENU_HEADER_HEIGHT = 16;
static const VfxS32 ROBOT_MAINMENU_ROW_COUNT = 5;
static const VfxS32 ROBOT_MAINMENU_CELL_HEIGHT_OFFSET = (-23);
static const VfxS32 ROBOT_MAINMENU_LENGTH_OFFSET = 7;

#elif defined(__MMI_MAINLCD_240X320__) //QVGA
static const VfxS32 ROBOT_MAINMENU_HEADER_HEIGHT = 12;
static const VfxS32 ROBOT_MAINMENU_ROW_COUNT = 3;
static const VfxS32 ROBOT_MAINMENU_CELL_HEIGHT_OFFSET = 14;
static const VfxS32 ROBOT_MAINMENU_LENGTH_OFFSET = 35;

#elif defined(__MMI_MAINLCD_240X400__) //WQVGA
static const VfxS32 ROBOT_MAINMENU_HEADER_HEIGHT = 10;
static const VfxS32 ROBOT_MAINMENU_ROW_COUNT = 4;
static const VfxS32 ROBOT_MAINMENU_CELL_HEIGHT_OFFSET = -2;
static const VfxS32 ROBOT_MAINMENU_LENGTH_OFFSET = 0;

#else                                  //HVGA 320X480
static const VfxS32 ROBOT_MAINMENU_HEADER_HEIGHT = 10;
static const VfxS32 ROBOT_MAINMENU_ROW_COUNT = 4;
static const VfxS32 ROBOT_MAINMENU_CELL_HEIGHT_OFFSET = (-3);
static const VfxS32 ROBOT_MAINMENU_LENGTH_OFFSET = 15;

#endif


/*****************************************************************************
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * VappLauncherRobotMainmenuPage Page Implementation
 *****************************************************************************/
class MyHeader : public VappLauncherRobotMainmenuPageMenuCell
{
    public:
        virtual void onInit()
        {
            VappLauncherRobotMainmenuPageMenuCell::onInit();
        }
};

/***************************************************************************** 
 * VappLauncherRobotMainmenuPage Menu Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotMainmenuPageMenu", VappLauncherRobotMainmenuPageMenu, VcpBaseMenu);

VappLauncherRobotMainmenuPageMenu::VappLauncherRobotMainmenuPageMenu():
    m_focusCellIdx(-1), 
    m_page(NULL), 
    m_preCreatedCell(-1),
    m_newAppList(NULL),
    m_preAppList(NULL)
{
    //do nothing
}


void VappLauncherRobotMainmenuPageMenu::onInit()
{
    m_isSupportTransition = VFX_TRUE;
    m_cellTextVisible = VFX_FALSE;
    m_testStyle = 0;
    m_firstPos = 0;
    m_dragMode = VFX_FALSE;
    m_delayTicks = 0;
    
    VcpBaseMenu::onInit();
    
    //get app name
    queryAppInfo();

    //get pre-app name
    queryPreAppInfo();

    //register events
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);    

    //sort app list
    // -1 for mainmenu icon
    sortAppListByDisplayName(m_newAppList,getTotalAppNum()-1);
}


void VappLauncherRobotMainmenuPageMenu::launchApp(VfxU32 pos)
{
    //srv_appmgr_launch(m_newAppList[pos]);
    strncpy(m_launchApp,m_newAppList[pos], MMI_APP_NAME_MAX_LEN -1);
    vfxPostInvoke1(this,&VappLauncherRobotMainmenuPageMenu::postLaunch, pos);
}

void VappLauncherRobotMainmenuPageMenu::postLaunch(VfxU32 pos)
{
    // Use m_launchApp(char) instead of m_newApplist(whole app array),
    // to avoid the array becomes invalid.
    // Scenario: Post launch the app, launcher will become inactive and de-init mainmenu,
    //           in this case, m_newApplist will be freed and resulting the array becomes invalid.
    if(m_launchApp)
    {
        // launch the clicking app.
        srv_appmgr_launch(m_launchApp);
    }
    else
    {
        // the app package name is invalid.
        VFX_ASSERT(0);
    }
}

VfxBool VappLauncherRobotMainmenuPageMenu::isPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount)
{
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(appName);
    if (type != SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
    {
        return VFX_FALSE;
    }
    for (VfxU32 i = 0; i < preInstalledAppCount; ++i)
    {
        if (strncmp(appName, preInstalledApp[i], MMI_APP_NAME_MAX_LEN) == 0)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappLauncherRobotMainmenuPageMenu::queryPreAppInfo()
{
    
    U32 preInstalledAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (preInstalledAppCount)
    {
        // release it to avoid leak, since it's global variable.
        VFX_FREE_MEM(m_preAppList);
        VFX_ALLOC_MEM(m_preAppList,
                      sizeof(mmi_app_package_name_struct) * preInstalledAppCount,
                      this );
        
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, m_preAppList, preInstalledAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
}

void VappLauncherRobotMainmenuPageMenu::queryAppInfo()
{
    U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
    U32 preCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    VfxS32 totalCount = getTotalAppNum();

    mmi_ret ret;
    mmi_app_package_name_struct * package;    
    VFX_ALLOC_MEM(package, sizeof(mmi_app_package_name_struct) * totalCount,this);
    memset(package, 0, sizeof(mmi_app_package_name_struct) *  totalCount);

    //query native/java app name from app manager.
    ret = srv_appmgr_get_app_package_list(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE,
            package, count);
            
    VFX_ASSERT(ret != MMI_RET_ERR);

    //query preinstall app (MRE downloadalbe shortcut) name from app manager.
    ret = srv_appmgr_get_app_package_list(
            SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE,
            package + count, preCount);
    
    VFX_ASSERT(ret != MMI_RET_ERR);

    //Check if home icon exist in the orginal app list,
    //mainmenu icon has been hidden as default.
    VfxS32 unUseApp = 0;
    for (VfxU32 i = 0; i < totalCount; ++i)
    {
        if (strncmp(package[i], "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
        {
            ++unUseApp;
	    continue;
        }
    }

    // release it to avoid leak, since it's global variable.
    VFX_FREE_MEM(m_newAppList);

    //append to new list if mainmenu or home icon be found.
    VFX_ALLOC_MEM(m_newAppList, sizeof(mmi_app_package_name_struct) * totalCount - unUseApp,this);
    VfxS32 hit = 0;
    for (VfxU32 i = 0; i < totalCount; ++i)
    {
        if (strncmp(package[i], "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
        {
            ++hit;
			continue;
            
        }
        strncpy(m_newAppList[i - hit], package[i], MMI_APP_NAME_MAX_LEN - 1);

        #if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)
            // Append home swtich effect to the list
            if(i == (totalCount - 1))
            {
                // -2, 1 for mainmenu icon while other for home screen switch effect.
                strncpy(m_newAppList[totalCount - 2],extractAdd[0], MMI_APP_NAME_MAX_LEN - 1);
                continue;
            }
        #endif
    }
        
    VFX_FREE_MEM(package);
}

VfxU32 VappLauncherRobotMainmenuPageMenu::getAppTypeOrder(mmi_app_package_name_struct appName)
{
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(appName);
    if (type == SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE)
    {
        return 0;
    }
    else if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
    {
        return 1;
    }
    else if (type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        return 2;
    }
    return 100;
}


void VappLauncherRobotMainmenuPageMenu::sortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount)
{
    // construct the display name mapping
    mmi_ret result;
    WCHAR **names;

    // allocate memory from launcher heap (ASM).
    VFX_ALLOC_MEM(names, 
                  sizeof(WCHAR*) * appCount + sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount,
                  this);
    
    memset(names, 0, sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount);
    names[0] = (WCHAR*)(names + appCount );
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        names[iPos] = names[0] + iPos * MMI_APP_NAME_MAX_LEN;
        result = srv_appmgr_get_app_package_name(appList[iPos], names[iPos]);
        VFX_ASSERT(result != MMI_RET_ERR);
    }

    // selection sort
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        VfxS32 iMin = iPos;
        VfxU32 iMinTypeOrder = getAppTypeOrder(appList[iPos]);
        for (VfxS32 i = iPos + 1; i < appCount; ++i)
        {
            // first compare app type, then compare app display name
            VfxU32 typeOrder = getAppTypeOrder(appList[i]);
            if (typeOrder < iMinTypeOrder)
            {
                iMin = i;
                iMinTypeOrder = typeOrder;
            }
            else if (typeOrder == iMinTypeOrder)
            {
                if (wcsncmp((const wchar_t*)names[iMin], (const wchar_t*)names[i], MMI_APP_NAME_MAX_LEN) > 0)
                {
                    iMin = i;
                }
            }
        }
        // swap(iPos, iMin)
        mmi_app_package_name_struct packageTemp;
        strncpy(packageTemp, appList[iMin], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iMin], appList[iPos], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iPos], packageTemp, MMI_APP_NAME_MAX_LEN - 1);

        WCHAR* nameTemp;
        nameTemp = names[iMin];
        names[iMin] = names[iPos];
        names[iPos] = nameTemp;
    }

    VFX_SYS_FREE_MEM(names);

}


void VappLauncherRobotMainmenuPageMenu::reloadMainmenu()
{
    // Re-inquire App list
    VFX_FREE_MEM(m_newAppList);
    queryAppInfo();

    // Re-inquire Pre-App list
    VFX_FREE_MEM(m_preAppList);
    queryPreAppInfo();

    // app list sorting
    sortAppListByDisplayName(m_newAppList,getTotalAppNum()-1);

    //reset base menu layout
    reset();
}


mmi_ret VappLauncherRobotMainmenuPageMenu::eventHandler(mmi_event_struct *event)
{
    VappLauncherRobotMainmenuPageMenu *pageMenu = (VappLauncherRobotMainmenuPageMenu *)event->
user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
				
                pageMenu->reloadMainmenu();

            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappLauncherRobotMainmenuPageMenu::onDeinit()
{

    //deregister events
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappLauncherRobotMainmenuPageMenu::eventHandler, this);    

    VFX_FREE_MEM(m_newAppList);
    VFX_FREE_MEM(m_preAppList);

    VcpBaseMenu::onDeinit();
}


void VappLauncherRobotMainmenuPageMenu::nextStyle()
{
    m_testStyle++;
    m_dragMode = VFX_FALSE;
    reset();
}


VcpBaseMenuLayout* VappLauncherRobotMainmenuPageMenu::createLayout()
{
    VappLauncherRobotMainmenulPageMenuLayout* layout;

    VFX_OBJ_CREATE_EX(layout, VappLauncherRobotMainmenulPageMenuLayout, this, (this));

    return layout;
}


VfxFrame* VappLauncherRobotMainmenuPageMenu::createGroupHeader(VfxS32 group)
{
    MyHeader* item;
    VFX_OBJ_CREATE(item, MyHeader, this);
    
    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "(Group %d)", group);
    //item->setBgColor(VFX_COLOR_GREEN);
    item->setHighlight(VFX_FALSE, VFX_FALSE);
    
    return item;
}


VfxFrame* VappLauncherRobotMainmenuPageMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VappLauncherRobotMainmenuPageMenuCell* item;
    VFX_OBJ_CREATE(item, VappLauncherRobotMainmenuPageMenuCell, this);

    VfxWChar caption[40] = {0};
    kal_wsprintf(caption, "(%d, %d)", group, pos);
    item->setHighlight(VFX_FALSE, VFX_FALSE);

	//Use mainmenu builder to create icon & text cell into cells of base menu
    VfxChar temp[MMI_APP_NAME_MAX_LEN];

    //strncpy(temp, m_package[pos], MMI_APP_NAME_MAX_LEN);
    //strncpy(temp, "native.mtk.alarm", MMI_APP_NAME_MAX_LEN);
    strncpy(temp, m_newAppList[pos], MMI_APP_NAME_MAX_LEN); 

    VfxBool isPreInstalled = VFX_FALSE;
    U32 preInstalledAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    isPreInstalled = isPreInstalledApp(m_newAppList[pos], m_preAppList, preInstalledAppCount);
    
    m_cell = createMainmenuRobotCell(temp, item, isPreInstalled);

    //m_cell->setBgColor(VFX_COLOR_WHITE);
    
    VFX_ASSERT(m_cell);
    
    m_cell->onCellDisplay();

    return item;
}


void VappLauncherRobotMainmenuPageMenu::onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
{
    VFX_OBJ_CLOSE(groupFrame);
}


void VappLauncherRobotMainmenuPageMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}


void VappLauncherRobotMainmenuPageMenu::onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag)
{
        MyHeader* item = (MyHeader*) header;

        if (flag & VCP_CELL_FLAG_FIRSTINIT)
        {
            if (flag & VCP_CELL_FLAG_OPENING)
            {
                item->enter(rect, VFX_TRUE, 0);
            }
            else
            {
                item->enter(rect, VFX_FALSE, 0);
            }
        }
        else if (flag & VCP_CELL_FLAG_CLOSING)
        {
            item->leave(rect);
        }
        else if (flag & VCP_CELL_FLAG_FORCESET)
        {
            item->updatePos(rect, VFX_FALSE);
        }
        else
        {
            item->updatePos(rect, VFX_TRUE);
        }
}


void VappLauncherRobotMainmenuPageMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    if (previousFocusItem.isValid() && !previousFocusItem.isGroupHeader())
    {
        VappLauncherRobotMainmenuPageMenuCell* item = (VappLauncherRobotMainmenuPageMenuCell*) getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);
        if (item)
        {
            item->setHighlight(VFX_FALSE, VFX_TRUE);
        }
    }
    if (focusItem.isValid() && !focusItem.isGroupHeader())
    {
        VappLauncherRobotMainmenuPageMenuCell* item = (VappLauncherRobotMainmenuPageMenuCell*) getCellIfPresent(focusItem.group, focusItem.pos);
        if (item)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }
    }
}


void VappLauncherRobotMainmenuPageMenu::onBeforeUpdate(
    const VcpMenuRegion& currentRegion,
    const VcpMenuRegion& targetRegion
)
{
    m_firstPos = currentRegion.begin.pos;
}


void VappLauncherRobotMainmenuPageMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VappLauncherRobotMainmenuPageMenuCell* item = (VappLauncherRobotMainmenuPageMenuCell*) cell;

    VfxRect r = rect;
    r.origin.x += 1;
    r.origin.y += 1;
    r.size.width -= 2;
    r.size.height -= 2;
    
    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(r, VFX_TRUE, (pos - m_firstPos) * 50);
        }
        else
        {
            item->enter(r, VFX_FALSE, 0);
        }
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(r);
    }
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->updatePos(r, VFX_FALSE);
    }
    else
    {
        item->updatePos(r, VFX_TRUE);
    }
}


void VappLauncherRobotMainmenuPageMenu::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    VappLauncherRobotMainmenuPageMenuCell* item = (VappLauncherRobotMainmenuPageMenuCell*) cell;
    item->click(pos);
    getLayout()->setFocusItem(VcpMenuPos(group, pos));

    VcpMenuPos focus = getLayout()->getFocusItem();
    // TODO: consisely,the home switch effect as pos 18
    if (cell && focus.pos == 18)
    {
        cell->setOpacity(1.0f);
    }
}


void VappLauncherRobotMainmenuPageMenu::onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    VappLauncherRobotMainmenuPageMenuCell* item = (VappLauncherRobotMainmenuPageMenuCell*) cell;

    switch (touchType)
    {
        case TouchLongTap:

            //Emit app name,position and anchor of cell to homescreen.
            m_internalSignalSendIcon.emit(m_newAppList[cellPos.pos],pt); 
            item->setOpacity(1.0f);
            break;
   
        case TouchDown:
            getLayout()->setFocusItem(cellPos);
            item->setOpacity(0.3f);
            break;
            
        default:
            break;
    }
}


void VappLauncherRobotMainmenuPageMenu::onDragStart()
{
    VFX_TRACE(("onDragStart\n"));;
    VcpBaseMenu::onDragStart();
}


void VappLauncherRobotMainmenuPageMenu::onDragEnd()
{
    VFX_TRACE(("onDragEnd\n"));;
    VcpBaseMenu::onDragEnd();
    VFX_TRACE(("Real: (%d, %d), Bounds:(%d, %d)\n", 
        m_view->forceGetBounds().origin.x, 
        m_view->forceGetBounds().origin.y, 
        m_view->getBounds().origin.x, 
        m_view->getBounds().origin.y
    ));
}


void VappLauncherRobotMainmenuPageMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_TRACE(("onDrag: %d %d\n", xoffset, yoffset));;

    if (xoffset != 0 || yoffset != 0)
    {
        VcpMenuPos focus = getLayout()->getFocusItem();
        if (focus.isValid())
        {
            VappLauncherRobotMainmenuPageMenuCell* cell = 
                (VappLauncherRobotMainmenuPageMenuCell*) getCellIfPresent(focus.group, focus.pos);

            if (cell)
            {
                cell->setOpacity(1.0f);
            }
        }
    }  
}


VfxBool VappLauncherRobotMainmenuPageMenu::IsSupportTransition()
{
    return VFX_FALSE;
}


/***************************************************************************** 
 * VappLauncherRobotMainmenuPage MenuLayout Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotMainmenulPageMenuLayout", VappLauncherRobotMainmenulPageMenuLayout, VcpBaseMenuLayout);

VappLauncherRobotMainmenulPageMenuLayout::VappLauncherRobotMainmenulPageMenuLayout():
    VcpBaseMenuLayout(NULL),
    m_totalAppNum(0),
    m_itemCount(0)
{
    //do nothing
}

    
VappLauncherRobotMainmenulPageMenuLayout::VappLauncherRobotMainmenulPageMenuLayout(VcpBaseMenu* menu):
    VcpBaseMenuLayout(menu),
    m_itemCount(0)
{
    //do nothing
}

    
void VappLauncherRobotMainmenulPageMenuLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_headerHeight = ROBOT_MAINMENU_HEADER_HEIGHT;
    m_columnCount = 4;
    m_groupGap = 1;
    resetCache();  
    m_totalAppNum = getTotalAppNum()-1;//home icon
}


void VappLauncherRobotMainmenulPageMenuLayout::onDeinit()
{
    VcpBaseMenuLayout::onDeinit();
}


VcpBaseMenuLayout::ScrollDirEnum VappLauncherRobotMainmenulPageMenuLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}


VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getGroupCount()
{
    return 1;
}

VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getCellCount(VfxS32 group)
{
    // we cache the item number while initializing
    return m_totalAppNum + group*3;
}


VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getContentLength()
{
	return m_groupStartPt[1] - m_groupGap + ROBOT_MAINMENU_LENGTH_OFFSET;
}


VfxBool VappLauncherRobotMainmenulPageMenuLayout::hasGroupHeader(VfxS32 group)
{
    return VFX_TRUE;
}

VcpMenuRegion VappLauncherRobotMainmenulPageMenuLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
        getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
}


VcpMenuPos VappLauncherRobotMainmenulPageMenuLayout::getCellByPos(VfxPoint pt)
{
        VcpMenuPos p;
        p.group = getGroupByY(pt.y);
        VfxS32 offy = pt.y - m_groupStartPt[p.group];

        if (offy < m_headerHeight)
        {
            p.pos = -1;
            return p;
        }

        VfxS32 row = (offy - m_headerHeight) / m_cellHeight;
        VfxS32 col = VFX_MAX(pt.x - 1, 0) / m_cellHeight;
        p.pos = row * m_columnCount + col;

        if (p.pos >= getCellCount(p.group))
        {
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
 }    


VfxRect VappLauncherRobotMainmenulPageMenuLayout::queryGroupHeaderRect(VfxS32 group)
{
    return VfxRect(
        0, 
        m_groupStartPt[group], 
        getViewSize().width, 
        m_headerHeight);
}


VfxRect VappLauncherRobotMainmenulPageMenuLayout::queryCellRect(VcpMenuPos pos)
{
    //return a cell rect    
    if (pos.group < 0 || pos.pos < -1)
        return VfxRect(-1, -1, 0, 0);

    if (pos.group >= 3 || pos.pos >= getCellCount(pos.group))
        return VfxRect(-1, -1, 0, 0);

    VfxS32 y = m_groupStartPt[pos.group] + m_headerHeight;
    //VfxS32 w = m_cellHeight;//orginal
	VfxS32 w = m_cellWidth;

    VfxS32 row = (pos.pos / m_columnCount) * m_cellHeight;
    VfxS32 col = (pos.pos % m_columnCount) * w;
            
    return VfxRect(col, y + row, w, m_cellHeight);
}


void VappLauncherRobotMainmenulPageMenuLayout::getPreferFocusMargin(VfxS32 margin[4])
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void VappLauncherRobotMainmenulPageMenuLayout::onViewChanged()
{
    resetCache();
}


VfxBool VappLauncherRobotMainmenulPageMenuLayout::navDir(NavDirEnum dir)
{
    // If there is no one is focused, we pick up one in the screen
    if (!getFocusItem().isValid())
    {
        VcpMenuPos p = getCellByPos(m_viewRect.origin);
        // we cannot focus on the header
        if (p.isGroupHeader()) 
        {
            p.pos = 0;
        }
        setFocusItem(p);
        return VFX_TRUE;
    }

    VcpMenuPos p;
    if (dir == NAV_DIR_UP)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_columnCount, r = p.pos / m_columnCount;
        VfxS32 group_row = (getCellCount(p.group)-1) / m_columnCount;

        if (r > 0)
        {
            r --;
            p.pos = r * m_columnCount + c;
        }
        else
        {
            if (p.group <= 0)
            {
                p.group = 0;
                p.pos = 0;
            }
            else
            {
                p.group--;

                VfxS32 n_group_row = getCellCount(p.group) / m_columnCount;

                p.pos = n_group_row * m_columnCount + c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }

        }
    }
    if (dir == NAV_DIR_DOWN)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_columnCount, r = p.pos / m_columnCount;
        VfxS32 group_row = (getCellCount(p.group) - 1) / m_columnCount;

        if (r >= group_row)
        {
            p.group ++;
            if (p.group >= getGroupCount())
            {
                if (group_row > 0)
                    p.pos = c;
                else
                p.pos = getCellCount(p.group) - 1;
            }
            else
            {
                p.pos = c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        else
        {
            p.pos = (r + 1) * m_columnCount + c;
            if (p.pos >= getCellCount(p.group))
            {
                p.pos = getCellCount(p.group) - 1;
            }
        }
    }
    if (dir == NAV_DIR_LEFT)
    {
        p = getFocusItem().getPrevPos(this, VFX_FALSE);
    }
    if (dir == NAV_DIR_RIGHT)
    {
        p = getFocusItem().getNextPos(this, VFX_FALSE);
    }
    if (p)
    {
        setFocusItem(p);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappLauncherRobotMainmenulPageMenuLayout::setColumnCount(VfxS32 cnt)
{
    m_columnCount = cnt;
    resetCache();
    update();
}


VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getColumnCount()
{
    return m_columnCount;
}


VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getWholeGroupHeight(VfxS32 group)
{
    VfxS32 row = (getCellCount(group) + m_columnCount - 1) / m_columnCount;
    return m_headerHeight + row * m_cellHeight;
}


VfxS32 VappLauncherRobotMainmenulPageMenuLayout::getGroupByY(VfxS32 y)
{
    if (y < 0) 
    {
        return 0;
    }
    for (VfxS32 i = 0; i < 3; i++)
    {
        if (y >= m_groupStartPt[i] && y < m_groupStartPt[i + 1])
            return i;
    }
    return 2;
}


void VappLauncherRobotMainmenulPageMenuLayout::resetCache()
{
    m_cellWidth = getViewSize().width / m_columnCount;
    //m_cellHeight = getViewSize().width / m_columnCount;//orgin
    m_cellHeight = getViewSize().height / ROBOT_MAINMENU_ROW_COUNT - ROBOT_MAINMENU_CELL_HEIGHT_OFFSET;

    m_groupStartPt[0] = 0;
    for (VfxS32 i = 1; i < 4; i++)
    {
        m_groupStartPt[i] = m_groupStartPt[i - 1] + getWholeGroupHeight(i - 1) + m_groupGap;
    }    
}


/***************************************************************************** 
 * VappLauncherRobotMainmenuPage Menu Cell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotMainmenuPageMenuCell", VappLauncherRobotMainmenuPageMenuCell, VfxControl);

VappLauncherRobotMainmenuPageMenuCell::VappLauncherRobotMainmenuPageMenuCell():
    m_highlight(VFX_FALSE)
{
    // do nothing
}


void VappLauncherRobotMainmenuPageMenuCell::onInit()
{
    VfxControl::onInit();
    
    sendToBack();
    setOpacity(1);
    setAnchor(VfxFPoint(0.5, 0.5));
    setIsCached(VFX_TRUE);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    // set bg as black,for the opacity
    setBgColor(VFX_COLOR_BLACK);
    m_highlight = VFX_FALSE;
    m_dragging = VFX_FALSE;
}


void VappLauncherRobotMainmenuPageMenuCell::onDeinit()
{
    VfxControl::onDeinit();
}


void VappLauncherRobotMainmenuPageMenuCell::setHighlight(VfxBool isHighLight, VfxBool isAnim)
{
    m_highlight = isHighLight;
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    
    if (m_highlight)
    {
        //
        //MAUI_03143751,no cell bordrs in robot mainmenu in navDir
        //
        //setBorderWidth(0);
    }
    else
    {
        //setBorderWidth(0);
    }            
    VfxAutoAnimate::commit();
    
    checkUpdate();

}


void VappLauncherRobotMainmenuPageMenuCell::onUpdate()
{

}


void VappLauncherRobotMainmenuPageMenuCell::enter(const VfxRect& r, VfxBool animation, VfxS32 delay)
{
    if (animation)
    {
        setPos(VfxPoint(r.getMidX(), r.getMidY()));
        updatePos(r, VFX_TRUE);
        setOpacity(1.0f);
    }
    else
    {
        updatePos(r, VFX_FALSE);
        setOpacity(1.0f);
    }

}


void VappLauncherRobotMainmenuPageMenuCell::leave(const VfxRect& r)
{

}


void VappLauncherRobotMainmenuPageMenuCell::updatePos(const VfxRect& r, VfxBool isAnim)
{
    if (m_dragging)
        return;
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    
    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    setBounds(VfxRect(VfxPoint(0, 0), r.size));
    
    VfxAutoAnimate::commit();

}


void VappLauncherRobotMainmenuPageMenuCell::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);
}


void VappLauncherRobotMainmenuPageMenuCell::click(VfxS32 pos)
{

    VappLauncherRobotMainmenuPageMenu* menu = (VappLauncherRobotMainmenuPageMenu*) getParentControl()->getParentControl();    
    menu->launchApp(pos);
}
