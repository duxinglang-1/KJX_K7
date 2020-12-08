/*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  vapp_fnt_mgr.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vfx_app_launcher.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "vcp_confirm_popup.h"
#include "vcp_popup_data_type.h"
#include "FileMgrSrvGProt.h"
#include "vapp_fmgr_cui_gprot.h"
#include "Vapp_usb_gprot.h"
#include "mmi_rp_srv_venus_component_menu_popup_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_fnt_mgr.h"
#include "vapp_launcher_gprot.h"
#include "vcp_global_popup.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "FileMgrCuiGProt.h"
#include "FontManagerGProt.h"
#include "font_engine_interface.h"
#include "mmi_rp_app_font_manager_def.h"
#include "mmi_rp_vapp_fontmgr_def.h"
#include "UcmSrvGprot.h"
#ifdef __cplusplus
}
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
void *g_curr_app = NULL;
VfxBool launchFromFM = VFX_FALSE;

/***************************************************************************** 
 * Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  vapp_font_settings_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vapp_font_settings_launch(VfxMainScr* scr)
{
#ifdef __MMI_USB_SUPPORT__
    if(srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return;
    }
#endif

    launchFromFM = VFX_FALSE;
    VfxAppLauncher::launch( 
        VAPP_FONTMGR, 
        VFX_OBJ_CLASS_INFO(VappFontSettings),
        GRP_ID_ROOT);

}

VFX_IMPLEMENT_CLASS("VappFontSettings", VappFontSettings, VfxApp);


/*****************************************************************************
 * FUNCTION
 *  VappFontSettings::VappFontSettings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontSettings::VappFontSettings()
{

}



/*****************************************************************************
 * FUNCTION
 *  VappFontSettings::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettings::onInit(void)
{
    VfxApp::onInit();
    g_curr_app = (void*)this;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettings::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettings::onDeinit(void)
{
    g_curr_app = NULL;
    VfxApp::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettings::onRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettings::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappFontSettingsScreen *scr;
    VFX_OBJ_CREATE(scr, VappFontSettingsScreen, this);
    scr->show();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettings::onProc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret VappFontSettings::onProc(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VappFontSettingsScreen", VappFontSettingsScreen, VfxMainScr);


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::VappFontSettingsScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontSettingsScreen::VappFontSettingsScreen()
{
    main_page = NULL;
    options_page = NULL;
    confirm = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::on1stReady
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(main_page, VappFontSettingsMainPage, this);
    pushPage(0,main_page);

    VappFontSettings *app;
    app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFontSettings);
    
    app->m_mainPage = main_page;

}

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappFontSettingsMainPage", VappFontSettingsMainPage, VfxPage);


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::VappFontSettingsMainPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontSettingsMainPage::VappFontSettingsMainPage()
{
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::onInit(void)
{
    VfxPage::onInit();

    m_app = (VappFontSettings*)getApp();

    //Draw Main Page
    drawMainPage();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::onExit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::onExit(VfxBool isBackward)
{
    VfxPage::onExit(isBackward);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::drawMainPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::drawMainPage(void)
{
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(VFX_WSTR_RES(STR_ID_FONT_MGR_LIST_FONT));
    setTopBar(title);
    VFX_OBJ_CREATE(m_List, VcpListMenu, this);
    m_List->setContentProvider(this);
    m_List->setPos(0,0);
	m_List->setSize(getSize());
    m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
    m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
    m_List->m_signalItemTapped.connect(this, &VappFontSettingsMainPage::onItemTap);
	m_List->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_List->updateAllItems();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::updateList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::updateList(void)
{
    m_List->setContentProvider(this);
    m_List->updateAllItems();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::onItemTap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::onItemTap(VcpListMenu *sender, VfxU32 index)
{
    VappFontSettingsScreen* scr = (VappFontSettingsScreen*)getMainScr();
    mmi_font_set_selected_font(index);
    VFX_OBJ_CREATE(scr->options_page, VappFontSettingsOptionsPage, scr);
    scr->pushPage(0,scr->options_page);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::getItemText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxBool VappFontSettingsMainPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    VfxU8 *fontNamePtrs = NULL;
    mmi_font_mgr_get_font_list(index, &fontNamePtrs);
    text = VFX_WSTR_MEM((const VfxWChar *)fontNamePtrs);
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::getItemImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxBool VappFontSettingsMainPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::getCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 VappFontSettingsMainPage::getCount() const
{
    return mmi_font_mgr_get_font_num();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::setMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::setMenu(VcpListMenu *menu)
{
	m_list = menu;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsMainPage::handleCardPlugOut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsMainPage::handleCardPlugOut(void)
{
    VappFontSettingsScreen* scr = (VappFontSettingsScreen*)getMainScr();
    updateList();
    scr->destroyConfirm();
    scr->closeOptionsPage();
    scr->closeFMGRCui();
}


VFX_IMPLEMENT_CLASS("VappFontSettingsOptionsPage", VappFontSettingsOptionsPage, VfxPage);


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::VappFontSettingsOptionsPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontSettingsOptionsPage::VappFontSettingsOptionsPage()
{
    priPopup = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::onInit(void)
{
    VfxPage::onInit();

    m_app = (VappFontSettings*)getApp();

    //Draw Main Page
    drawMainPage();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::onDeinit(void)
{
    VappFontSettingsScreen* scr = (VappFontSettingsScreen*)getMainScr();
    scr->options_page = NULL;
    VfxPage::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::drawMainPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::drawMainPage(void)
{
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(VFX_WSTR_RES(STR_ID_FONT_MGR_LIST_FONT));
    setTopBar(title);
    VFX_OBJ_CREATE(m_List, VcpListMenu, this);
    m_List->setContentProvider(this);
    m_List->setPos(0,0);
	m_List->setSize(getSize());
    m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
    m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
    m_List->m_signalItemTapped.connect(this, &VappFontSettingsOptionsPage::onItemTap);
	m_List->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_List->updateAllItems();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::onItemTap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::onItemTap(VcpListMenu *sender, VfxU32 index)
{
    VappFontSettingsScreen* scr = (VappFontSettingsScreen*)getMainScr();
    if(mmi_font_mgr_is_system_font())
    {
        if(mmi_font_mgr_get_font_num() == 1)
        {
            if(index == 0)
            {
                scr->addNewFont();
            }
            else
            {
                ASSERT(0);
            }
        }
        else
        {
            if(index == 0)
            {
                changeFontPriority();
            }
            else if(index == 1)
            {
                scr->addNewFont();
            }
            else
            {
                ASSERT(0);
            }
        }
    }
    else
    {
        switch(index)
        {
            case 0:
                changeFontPriority();
                break;
            case 1:
                scr->uninstallFont();
                break;
            case 2:
                scr->addNewFont();
                break;
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::changeFontPriority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::changeFontPriority(void)
{
    VFX_OBJ_CREATE(priPopup, VappSetPriorityPopup, this);
    priPopup->setInitPri(mmi_font_get_selected_font_priority());
    priPopup->setTitle(STR_ID_FONT_MGR_CHANGE_PRIORITY);
    priPopup->m_signalBtnClicked.connect(this,&VappFontSettingsOptionsPage::onPriButtonClicked);
    priPopup->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::closePriPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::closePriPopup(void)
{
    if(priPopup)
    {
        VFX_OBJ_CLOSE(priPopup);
        priPopup = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::closeOptionsPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::closeOptionsPage(void)
{
    if(options_page)
    {
        options_page->closePriPopup();
        closePage(getPageId((const VfxPage *) options_page));
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::closeFMGRCui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::closeFMGRCui(void)
{
    if(cui_gid != GRP_ID_INVALID)
    {
        vcui_file_selector_close(cui_gid);
        cui_gid = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::destroyConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::destroyConfirm(void)
{
    if(confirm)
    {
        VFX_OBJ_CLOSE(confirm);
        confirm = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::uninstallFont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::uninstallFont(void)
{
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString txt(STR_ID_FONT_MGR_UNINSTALL_GOTO_HOME_QUERY);
    confirm->setText(txt);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_GLOBAL_OK), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappFontSettingsScreen::uninstallFontConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::uninstallFontConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::uninstallFontConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;
    if(input)
    {
        showUninstallingIndicatorPopup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::addNewFont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::addNewFont(void)
{
    FMGR_FILTER filter;
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_TTF);
    cui_gid = vcui_file_selector_create(getApp()->getGroupId(), (WCHAR*)L"root", &filter, 
                        VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
	if (cui_gid)
	{
		vfxSetCuiCallerScr(cui_gid, this);
        vcui_file_selector_run(cui_gid);
	}
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::onProc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret VappFontSettingsScreen::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
		case EVT_ID_VCUI_FILE_SELECTOR_RESULT: /*evnt from file manager*/
			vcui_file_selector_result_event_struct *fmgrEvt = (vcui_file_selector_result_event_struct*)evt;

			if (fmgrEvt->result > 0)
			{
                VfxBool ret = VFX_FALSE;
				srv_fmgr_fileinfo_struct info = {0,};
				WCHAR* path_buffer  = NULL;
				U32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR);
				VFX_SYS_ALLOC_MEM(path_buffer, (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR));
				vcui_file_selector_get_selected_filepath(cui_gid, &info, path_buffer, buff_size);
                ret = mmi_font_mgr_install_new_font((char*)path_buffer);
				VFX_SYS_FREE_MEM(path_buffer);
                vcui_file_selector_close(cui_gid);
                cui_gid = GRP_ID_INVALID;
                if(ret)
                {
                    popPage();

                    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
                    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
                    VfxWString txt(STR_ID_FONT_MGR_ACTIVATE_GOTO_HOME_QUERY);
                    confirm->setText(txt);
                    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
                    confirm->setCustomButton(
                                VfxWString(STR_GLOBAL_OK), 
                                VfxWString(STR_GLOBAL_CANCEL), 
                                VCP_POPUP_BUTTON_TYPE_WARNING, 
                                VCP_POPUP_BUTTON_TYPE_CANCEL);
                    confirm->m_signalButtonClicked.connect(this, &VappFontSettingsScreen::activateFontConfirm);
                    confirm->setAutoDestory(VFX_TRUE);
                    confirm->show(VFX_TRUE);
                }
			}
            else
			{
				vcui_file_selector_close(cui_gid);
                cui_gid = GRP_ID_INVALID;
			}
			break;
    }

    return VfxMainScr::onProc(evt);
}

/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::showInstallingIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::showInstallingIndicatorPopup(void)
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, this);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_indPopup->setText(VFX_WSTR_RES(STR_GLOBAL_INSTALLING));
    m_indPopup->setAutoDestory(VFX_TRUE);
    m_indPopup->setIsAnimate(VFX_FALSE);
    m_indPopup->m_signalPopupState.connect(this, &VappFontSettingsScreen::onInstallPopState);
    m_indPopup->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::showUninstallingIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::showUninstallingIndicatorPopup(void)
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, this);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_indPopup->setText(VFX_WSTR_RES(STR_ID_FONT_MGR_UNINSTALLING_FONT));
    m_indPopup->setAutoDestory(VFX_TRUE);
    m_indPopup->setIsAnimate(VFX_FALSE);
    m_indPopup->m_signalPopupState.connect(this, &VappFontSettingsScreen::onUninstallPopState);
    m_indPopup->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::showPriorityIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::showPriorityIndicatorPopup(void)
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, this);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_indPopup->setText(VFX_WSTR_RES(STR_ID_FONT_MGR_CHANGING_FONT_PRIORITY));
    m_indPopup->setAutoDestory(VFX_TRUE);
    m_indPopup->setIsAnimate(VFX_FALSE);
    m_indPopup->m_signalPopupState.connect(this, &VappFontSettingsScreen::onPriorityPopState);
    m_indPopup->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::closeIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::closeIndicatorPopup(void)
{
    VFX_OBJ_CLOSE(m_indPopup);
    m_indPopup = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::onInstallPopState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::onInstallPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        if(confirm)
        {
            mmi_font_mgr_activate_font();
		    mmi_event_struct evt;
		    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            if(srv_ucm_is_incoming_call())
            {
                closeIndicatorPopup();
                VappFontSettings *app;
                app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFontSettings);
                VappFontSettingsMainPage *page = app->m_mainPage;
                page->updateList();
            }
            else
            {
                vapp_launcher_restart();
            }
        }
        else
        {
            mmi_font_mgr_activate_cancel();
            closeIndicatorPopup();
            VappFontSettings *app;
            app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFontSettings);
            VappFontSettingsMainPage *page = app->m_mainPage;
            page->updateList();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::onUninstallPopState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::onUninstallPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        if(confirm)
        {
            mmi_font_mgr_uninstall_font();
		    mmi_event_struct evt;
		    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            if(srv_ucm_is_incoming_call())
            {
                closeIndicatorPopup();
                VappFontSettings *app;
                app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFontSettings);
                VappFontSettingsMainPage *page = app->m_mainPage;
                page->updateList();
                popPage();
            }
            else
            {
                vapp_launcher_restart();
            }
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_SUCCESS, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_DONE)).getBuf());
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::onPriorityPopState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::onPriorityPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        if(confirm)
        {
            mmi_font_mgr_font_list_option_priority_change_handler();
		    mmi_event_struct evt;
		    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            if(srv_ucm_is_incoming_call())
            {
                closeIndicatorPopup();
                VappFontSettings *app;
                app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFontSettings);
                VappFontSettingsMainPage *page = app->m_mainPage;
                page->updateList();
                popPage();
            }
            else
            {
                vapp_launcher_restart();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::activateFontConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::activateFontConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;
    if(input)
    {
        showInstallingIndicatorPopup();
    }
    else
    {
        if(confirm)
        {
            showInstallingIndicatorPopup();
            confirm = NULL;
        }
        else
        {
            mmi_font_mgr_activate_exit();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::getItemText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxBool VappFontSettingsOptionsPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    VfxU8 *fontOptionsPtrs = NULL;
    /*
    if (fieldType != VCP_LIST_MENU_FIELD_TEXT || index >= 15)
	{
		return VFX_FALSE;
	}
    */
    mmi_font_mgr_get_font_options_list(index, &fontOptionsPtrs);
    text = VFX_WSTR_MEM((const VfxWChar *)fontOptionsPtrs);
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::getItemImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxBool VappFontSettingsOptionsPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::getCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 VappFontSettingsOptionsPage::getCount() const
{
    return mmi_font_mgr_get_font_options_count();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::setMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::setMenu(VcpListMenu *menu)
{
	m_list = menu;
}


VFX_IMPLEMENT_CLASS("VappSetPriorityPopup", VappSetPriorityPopup, VfxBasePopup);


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::VappSetPriorityPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappSetPriorityPopup::VappSetPriorityPopup(void):
    m_priText(NULL),
    m_slider(NULL),
    pri_icon(NULL),
    m_min(1)
{
    m_pri = mmi_font_get_selected_font_priority();
    m_max = mmi_font_mgr_get_font_num();
}

    
/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onInit(void)
{
    VfxBasePopup::onInit();

//	m_self = this;

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, POPUP_WIDTH, POPUP_HEIGHT);

    VfxFrame* background_top;
    VFX_OBJ_CREATE(background_top, VfxFrame, this);
    background_top->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_TITLE_BG));
    background_top->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_top->setPos(0, 0);
    background_top->setSize(POPUP_WIDTH, UP_HEIGHT);

    VfxFrame* background_bot;
    VFX_OBJ_CREATE(background_bot, VfxFrame, this);
    background_bot->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_BG));
    background_bot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_bot->setPos(0, UP_HEIGHT);
    background_bot->setSize(POPUP_WIDTH, POPUP_HEIGHT - UP_HEIGHT);

    //priority text
    VFX_OBJ_CREATE(m_priText, VfxTextFrame, background_top);
    m_priText->setAutoResized(VFX_FALSE);
    m_priText->setSize(POPUP_WIDTH, UP_HEIGHT);
    m_priText->setPos(0,0);
    m_priText->setString(VFX_WSTR_RES(STR_ID_FONT_MGR_CHANGE_PRIORITY));
    m_priText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FNT_SIZE)));
    m_priText->setVerticalToCenter(VFX_TRUE);
    m_priText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    //icon
    VfxWChar pri_str_ucs2[3];
    VfxU8 pri_str[3];
    memset(pri_str_ucs2, 0, 6);
    memset(pri_str, 0, 3);
    sprintf((char*)pri_str, "%2d", m_pri);
    mmi_asc_to_ucs2((char*) pri_str_ucs2, (char*) pri_str);
    VFX_OBJ_CREATE(pri_icon,VfxTextFrame,this);
	pri_icon->setAutoResized(VFX_TRUE);
	pri_icon->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    pri_icon->setString(VFX_WSTR_MEM((const VfxWChar*)pri_str_ucs2));
    pri_icon->setPos(ICON_X,ICON_Y);

    //Slider
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);
    m_slider->setPos(BAR_X, BAR_Y);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(BAR_LENGTH);
    m_slider->setMaxValue(m_max);
    m_slider->setMinValue(m_min);
    m_slider->setTotalDiscreteStepsForPen(m_max - m_min);
    m_slider->setCurrentValue(m_pri);

    m_slider->m_signalUserChangedValue.connect(this, &VappSetPriorityPopup::onSliderMoved);

    VcpButton* btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    btn->setPos(BTN_X,BTN_Y);
    btn->setSize(BTN_WIDTH,BTN_HEIGHT);
    btn->m_signalClicked.connect(this,&VappSetPriorityPopup::onButtonClicked);
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onDeinit(void)
{
	VfxBasePopup::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::setInitPri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::setInitPri(VfxU8 pri)
{
    if(pri > m_max)
    {
        pri = m_max;
    }

    if(pri < m_min)
    {
        pri = m_min;
    }    

    m_pri = pri;

    m_slider->setCurrentValue(m_pri);

}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::getPri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU8 VappSetPriorityPopup::getPri(void)
{
    return m_pri;
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::setTitle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::setTitle(VfxResId id)
{
    m_priText->setString(VFX_WSTR_RES(id));
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onDecreasePri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onDecreasePri(void)
{

    if(m_pri <= m_min)
    {
        return;
    }

    m_pri --;

    m_slider->setCurrentValue(m_pri);
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onIncreasePri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onIncreasePri(void)
{

    if(m_pri >= m_max)
    {
        return;
    }

    m_pri ++;

    m_slider->setCurrentValue(m_pri);
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onKeyInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxBool VappSetPriorityPopup::onKeyInput(VfxKeyEvent &event)
{
    switch(event.keyCode)
    {
        case VFX_KEY_CODE_BACK:
        {
            return VFX_TRUE;
        }
/*
        case VFX_KEY_CODE_VOL_DOWN:
        {
            switch(event.type)
            {
                case KEY_LONG_PRESS:
                case KEY_REPEAT:
                case KEY_EVENT_DOWN:
                {
                    onDecreasePri();
                    return VFX_TRUE;
                    break;
                }

                default:
                    return VFX_TRUE;
            }
            break;
        }

        case VFX_KEY_CODE_VOL_UP:
        {
            switch(event.type)
            {
                case KEY_LONG_PRESS:
                case KEY_REPEAT:
                case KEY_EVENT_DOWN:
                {
                    onIncreasePri();
                    return VFX_TRUE;
                    break;
                }

                default:
                    return VFX_TRUE;
            }

            break;
        }
*/
    }

    return VfxBasePopup::onKeyInput(event);

}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onSliderMoved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval)
{
    if(m_pri == (VfxU8)newval)
    {
        return ;
    }

    m_pri = (VfxU8)newval;

    VfxWChar pri_str_ucs2[3];
    VfxU8 pri_str[3];
    memset(pri_str_ucs2, 0, 6);
    memset(pri_str, 0, 3);
    sprintf((char*)pri_str, "%2d", m_pri);
    mmi_asc_to_ucs2((char*) pri_str_ucs2, (char*) pri_str);
    pri_icon->setString(VFX_WSTR_MEM((const VfxWChar*)pri_str_ucs2));
}


/*****************************************************************************
 * FUNCTION
 *  VappSetPriorityPopup::onButtonClicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappSetPriorityPopup::onButtonClicked(VfxObject *sender, VfxId id)
{
    m_signalBtnClicked.postEmit(m_pri);

    leave(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::changePriorityConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::changePriorityConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;
    if(input)
    {
        showPriorityIndicatorPopup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsScreen::changePriorityPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsScreen::changePriorityPopup(void)
{
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString txt(STR_ID_FONT_MGR_GOTO_HOME_QUERY);
    confirm->setText(txt);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_GLOBAL_CONTINUE), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappFontSettingsScreen::changePriorityConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontSettingsOptionsPage::onPriButtonClicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontSettingsOptionsPage::onPriButtonClicked(VfxU8 pri)
{
    VappFontSettingsScreen* scr = (VappFontSettingsScreen*)getMainScr();
    VappFontSettings *app;
    app = VFX_OBJ_DYNAMIC_CAST(scr->getApp(),VappFontSettings);
    VappFontSettingsMainPage *page = app->m_mainPage;

    if(mmi_font_set_selected_font_priority(pri))
    {
        scr->changePriorityPopup();
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_SUCCESS, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_DONE)).getBuf());
        page->updateList();
        scr->popPage();
        priPopup = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_font_mgr_install_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern "C" void vapp_font_mgr_install_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    switch(item_id)
    {
        case MENU_FMGR_VECTOR_FONT_OPTION_INSTALL:
            if(mmi_font_mgr_install_new_font((char*)filepath))
            {
                vapp_fnt_mgr_launch();
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_fnt_mgr_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern "C" void vapp_fnt_mgr_launch(void)
{
	launchFromFM = VFX_TRUE;
    VfxAppLauncher::launch( 
        VAPP_FONTMGR, 
        VFX_OBJ_CLASS_INFO(VappFontActivate),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappFontActivate", VappFontActivate, VfxApp);


/*****************************************************************************
 * FUNCTION
 *  VappFontActivate::VappFontActivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontActivate::VappFontActivate()
{

}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivate::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivate::onInit(void)
{
    VfxApp::onInit();
    g_curr_app = (void*)this;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivate::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivate::onDeinit(void)
{
    g_curr_app = NULL;
    VfxApp::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivate::onRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivate::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE(m_mainScr, VappFontActivateScreen, this);
    m_mainScr->show();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivate::onProc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret VappFontActivate::onProc(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VappFontActivateScreen", VappFontActivateScreen, VfxMainScr);


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::VappFontActivateScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontActivateScreen::VappFontActivateScreen()
{
    setIsSmallScreen();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::onInit()
{
    VfxMainScr::onInit();
    setDisplayStyle();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::onDeinit(void)
{
    VfxMainScr::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::on1stReady
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setBgColor(VFX_COLOR_TRANSPARENT);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString txt(STR_ID_FONT_MGR_ACTIVATE_GOTO_HOME_QUERY);
    confirm->setText(txt);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_GLOBAL_OK), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappFontActivateScreen::activateFontConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::showIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::showIndicatorPopup(void)
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, this);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_indPopup->setText(VFX_WSTR_RES(STR_GLOBAL_INSTALLING));
    m_indPopup->setAutoDestory(VFX_TRUE);
    m_indPopup->setIsAnimate(VFX_FALSE);
    m_indPopup->m_signalPopupState.connect(this, &VappFontActivateScreen::onPopState);
    m_indPopup->show(VFX_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::closeIndicatorPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::closeIndicatorPopup(void)
{
    VFX_OBJ_CLOSE(m_indPopup);
    m_indPopup = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::onPopState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        if(confirm)
        {
            mmi_font_mgr_activate_font();
		    mmi_event_struct evt;
		    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            if(srv_ucm_is_incoming_call())
            {
                closeIndicatorPopup();
                exit();
            }
            else
            {
                vapp_launcher_restart();
            }
        }
        else
        {
            mmi_font_mgr_activate_cancel();
            closeIndicatorPopup();
            exit();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::activateFontConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::activateFontConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;
    if(input)
    {
        showIndicatorPopup();
    }
    else
    {
        if(confirm)
        {
            showIndicatorPopup();
            confirm = NULL;
        }
        else
        {
            mmi_font_mgr_activate_exit();
            exit();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::setDisplayStyle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::setDisplayStyle()
{
    setBgColor(VFX_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontActivateScreen::handleCardPlugOut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontActivateScreen::handleCardPlugOut(void)
{
    if(confirm)
    {
        VFX_OBJ_CLOSE(confirm);
        confirm = NULL;
    }
    exit();
}


/*****************************************************************************
 * FUNCTION
 *  vapp_fnt_mgr_launch_dummy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern "C" void vapp_fnt_mgr_launch_dummy(void)
{
    VfxAppLauncher::launch( 
        VAPP_FONTMGR, 
        VFX_OBJ_CLASS_INFO(VappFontDummy),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappFontDummy", VappFontDummy, VfxApp);


/*****************************************************************************
 * FUNCTION
 *  VappFontDummy::VappFontDummy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontDummy::VappFontDummy()
{

}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummy::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummy::onInit(void)
{
    VfxApp::onInit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummy::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummy::onDeinit(void)
{
    VfxApp::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummy::onRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummy::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappFontDummyScreen* mainScr;
    VFX_OBJ_CREATE(mainScr, VappFontDummyScreen, this);
    mainScr->show();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummy::onProc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret VappFontDummy::onProc(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VappFontDummyScreen", VappFontDummyScreen, VfxMainScr);


/*****************************************************************************
 * FUNCTION
 *  VappFontDummyScreen::VappFontDummyScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VappFontDummyScreen::VappFontDummyScreen()
{
    setIsSmallScreen();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummyScreen::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummyScreen::onInit()
{
    VfxMainScr::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummyScreen::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummyScreen::onDeinit(void)
{
    VfxMainScr::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VappFontDummyScreen::on1stReady
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void VappFontDummyScreen::on1stReady()
{
    VfxMainScr::on1stReady();
    exit();
}


/*****************************************************************************
 * FUNCTION
 *  vapp_font_mgr_usb_ms_plug_in_hdlr
 * DESCRIPTION
 *  font mangager notify handler
 * PARAMETERS
 *  evt       : [IN]       event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern "C" mmi_ret vapp_font_mgr_usb_ms_plug_in_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_font_mgr_uninstall_font_ms_mode())
    {
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
	    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
        vapp_launcher_restart();
    }
    /*
    if(g_curr_app)
    {
        if(launchFromFM)
        {
            VappFontActivate* app = (VappFontActivate*)g_curr_app;
            VfxAppLauncher::terminate(app->getGroupId());
        }
        else
        {
            VappFontSettings* app = (VappFontSettings*)g_curr_app;
            VfxAppLauncher::terminate(app->getGroupId());
        }
    }
    */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_font_mgr_fmgr_notify_hdlr
 * DESCRIPTION
 *  font mangager notify handler
 * PARAMETERS
 *  evt       : [IN]       event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern "C" mmi_ret vapp_font_mgr_fmgr_notify_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct *plug_evt;
    srv_fmgr_notification_format_event_struct *format_evt;
    VfxU32 i;
    VfxBool is_changed = VFX_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT ||
        evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT)
    {
        format_evt = (srv_fmgr_notification_format_event_struct*)evt;
        if (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
        {
            is_changed = mmi_font_mgr_drv_remove_hdlr((char*)&format_evt->drv_letter);
        }
    }
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        plug_evt = (srv_fmgr_notification_dev_plug_event_struct*)evt;
        for (i = 0; i < plug_evt->count; i++)
        {
            is_changed = mmi_font_mgr_drv_remove_hdlr((char*)&plug_evt->drv_letters[i]);
        }
    }

    if(is_changed)
    {
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FONT_CHANGED);
	    MMI_FRM_CB_EMIT_EVENT(&evt);
        //vapp_launcher_restart();
        
        if(g_curr_app)
        {
            if(launchFromFM)
            {
                VappFontActivate* app = (VappFontActivate*)g_curr_app;
                VappFontActivateScreen *scr = app->m_mainScr;
                scr->handleCardPlugOut();
            }
            else
            {
                VappFontSettings* app = (VappFontSettings*)g_curr_app;
                VappFontSettingsMainPage *page = app->m_mainPage;
                page->handleCardPlugOut();
            }
        }
        else
        {
            vapp_fnt_mgr_launch_dummy();
        }
        
    }
    return MMI_RET_OK;
}


#endif

extern "C" void vcp_font_memory_card_notify_popup(WCHAR *str)
{
    vcp_global_popup_show_confirm_one_button_str(GRP_ID_ROOT, VCP_POPUP_TYPE_WARNING, VfxWString().loadFromMem(str), VFX_WSTR("Please wait!"), VCP_POPUP_BUTTON_TYPE_WARNING, NULL, NULL);
}

