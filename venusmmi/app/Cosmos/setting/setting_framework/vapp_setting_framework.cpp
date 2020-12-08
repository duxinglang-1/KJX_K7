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
 *  Vapp_SettingFramework.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_framework.h"
#include "vtst_rt_main.h"
#include "vapp_setting_framework_cell_list.h"
extern "C"
{
#include "GlobalResDef.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__) 
#include "dcmgr.h" // DCM
#endif
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C"
{
MMI_ID vapp_setting_launch_by_menu_id(VappSettingPublicMenuItemEnum menu_id)
{
    VappSettingFWMgr *settingFWMgr = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
    return settingFWMgr->launchSetting(menu_id, NULL);
}

MMI_ID vapp_setting_launch_by_hdlr(VappSettingLaunchHdlr launchHdlr)
{
    VappSettingFWMgr *settingFWMgr = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
    return settingFWMgr->launchSetting(SETTING_MENU_NONE, launchHdlr);
}
MMI_ID vapp_setting_launch(void *param, U32 param_size)
{
    return vapp_setting_launch_by_menu_id(SETTING_MAIN_MENU);
}

}
#ifdef __AFX_RT_TEST__
VtstTestResultEnum vtst_sample_setting_framework(VfxU32 param)
{
    VFX_UNUSED(param);
    vapp_setting_launch(NULL, 0);
    return VTST_TR_OK;
}
#endif
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingFWMgr
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappSettingFWMgr);

MMI_ID VappSettingFWMgr::launchSetting(VfxU32 menuId, VappSettingLaunchHdlr launchHdlr)
{
    if (!isSettingMenuExist())
	{
	    VfxAppLauncher::terminate(m_appId);
	}
    vapp_setting_framework_launch_struct launchData = {0};
    launchData.menuId = menuId;
    launchData.launchHdlr =launchHdlr;
    
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_SETTING, 0, 0);
#endif
    m_appId = VfxAppLauncher::launch( 
        VAPP_SETTING,
        VFX_OBJ_CLASS_INFO(VappSettingApp),
        GRP_ID_ROOT,
        &launchData, 
        sizeof(vapp_setting_framework_launch_struct));
    return m_appId;
}
void VappSettingFWMgr::popMenu()
{
    if (m_topHistoryIdx == 0)
	{
	    ASSERT(0);
	}
    // Update history
    m_menuHistory[m_topHistoryIdx].menuId = 0;
    m_menuHistory[m_topHistoryIdx].page = NULL;    
    m_menuHistory[m_topHistoryIdx].menuCellList = NULL;        
    m_topHistoryIdx--;    
    
    if (m_topHistoryIdx == 0)
    {
	m_mainScr = NULL;
        m_cellListCreator = NULL;
    }

}
void VappSettingFWMgr::pushMenu(VfxId menuId)
{
    if (!m_cellListCreator)
    {
        VfxApp *parent = VfxAppLauncher::findApp(
                            VAPP_SETTING,
                            VFX_OBJ_CLASS_INFO(VappSettingApp),
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[setting_framework] setting has been launched, id(%d), address(%u)", parent->getGroupId(), parent);
        ASSERT(parent);
        VFX_OBJ_CREATE(m_cellListCreator, VappSettingFWCelllistCreator, parent);
    }
    if (m_topHistoryIdx >= SETTING_FRAMEWORK_MAX_DEPTH)
	{
	    ASSERT(0);
	}
    if (m_cellListCreator->checkIsSubItem(menuId) == VFX_FALSE)
	{
	    return;
	}
    VappSettingFWViewPage *viewPage;
    VFX_OBJ_CREATE(viewPage, VappSettingFWViewPage, m_mainScr.get());
    viewPage->m_signalEntryMenu.connect(this, &VappSettingFWMgr::pushMenu);
    viewPage->m_signalPopMenu.connect(this, &VappSettingFWMgr::popMenu);

    VappSettingFWCellList* cellList = m_cellListCreator->getMenuCellList(menuId, viewPage);

    // Update history
    m_menuHistory[m_topHistoryIdx].menuId = menuId;
    m_menuHistory[m_topHistoryIdx].page = viewPage;    
    m_menuHistory[m_topHistoryIdx].menuCellList = cellList;        
    m_topHistoryIdx++;
    
    viewPage->setTitle(m_cellListCreator->getPublicMenuTitle(menuId));
    viewPage->setCellList(cellList);
    m_mainScr->pushPage(0, viewPage);    
}

VfxMainScr* VappSettingFWMgr::getMainScr() 
{
    if (m_mainScr != NULL)
	{
        return m_mainScr.get();
	}
    return NULL;
}

/***************************************************************************** 
 * VappSettingFWViewPage
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 
VFX_IMPLEMENT_CLASS("VappSettingFWViewPage", VappSettingFWViewPage, VfxPage); 
VappSettingFWViewPage::~VappSettingFWViewPage()
{
    m_signalPopMenu.emit();
}

void VappSettingFWViewPage::onInit()
{
	VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
	//m_form->setBounds(this->getBounds());
	//m_form->setViewRect(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
	m_form->setSize(getSize());
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

}

void VappSettingFWViewPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
	{
        updatePage(NULL);	
	}
}

void VappSettingFWViewPage::updatePage(VcpFormItemBase *senderItem)
{
    VfxU16 id = 0;
    if (m_init == VFX_FALSE)
	{
         m_list->reset();
        do
        {
            // get setting cell from cell list
            VcpFormItemBase *settingCell = m_list->getCell();
            m_form->addItem(settingCell, id);
            VappSettingFWPublicCell *publicCell = VFX_OBJ_DYNAMIC_CAST(settingCell, VappSettingFWPublicCell);
            if (publicCell)
        	{
                publicCell->m_signalEntryMenu.connect(this, &VappSettingFWViewPage::onEnterMenu);
        	}
            id++;
        }
        while (m_list->getNext());
	}
	m_init = VFX_TRUE;
}

void VappSettingFWViewPage::onEnterMenu(VfxId menuId)
{
  m_signalEntryMenu.emit(menuId);
}

void VappSettingFWViewPage::setCellList(VappSettingFWCellList* cellList)
{
    m_list = cellList;
    updatePage(NULL);    
}
#pragma arm section code, rodata

/***************************************************************************** 
 * VappSettingMainScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSettingMainScr", VappSettingMainScr, VfxMainScr);
void VappSettingMainScr::on1stReady(void)
{
    VappSettingFWMgr *settingFWMgr = VappSettingFWMgr::getInstance();
    settingFWMgr->setMainScr(this);
    if (m_pageId != SETTING_MENU_NONE)
	{
        settingFWMgr->pushMenu(m_pageId);
	}
}

/***************************************************************************** 
 * VappSettingApp
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 
VFX_IMPLEMENT_CLASS("VappSettingApp", VappSettingApp, VfxApp);
void VappSettingApp::onDeinit()
{
    VfxApp::onDeinit();
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_SETTING);
#endif
}
 
void VappSettingApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
    
    VappSettingMainScr *settingMainScreen;
    VFX_OBJ_CREATE(settingMainScreen, VappSettingMainScr, this);    
    vapp_setting_framework_launch_struct *data = (vapp_setting_framework_launch_struct*)args;

    if (!args)
	{
        settingMainScreen->setStartPage(SETTING_MAIN_MENU);
	}
    else
    {
        if (data->menuId)
    	{
    	    settingMainScreen->setStartPage(data->menuId);
    	}
        else
        {
            data->launchHdlr(settingMainScreen);
        }
    }

    settingMainScreen->show();
}
#pragma arm section code, rodata

mmi_ret VappSettingApp::onProc(mmi_event_struct *evt)
{
    VappSettingFWMgr *settingFWMgr = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
    VfxMainScr *mainScr = settingFWMgr->getMainScr();
    if (mainScr)
    {
        VappSettingMainScr *settingFwMainScr = VFX_OBJ_DYNAMIC_CAST(mainScr, VappSettingMainScr);
        if (settingFwMainScr)
    	{
            return settingFwMainScr->processProc(evt);    	
    	}
    }
    return MMI_RET_DONT_CARE;
}
