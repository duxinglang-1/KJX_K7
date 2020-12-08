/*****************************************************************************
*  Copyright Statement:
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
 *  vapp_atv_page.cpp
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_ATV_SUPPORT__

#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_mtv.h"
#include "USBSrvGprot.h"
#include "GpioSrvGprot.h"
#ifdef __cplusplus
}
#endif
#include "mmi_rp_vapp_atv_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#include "vcp_global_popup.h"
#include "vapp_atv.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Screen Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvScreen", VappAtvScreen, VfxMainScr);

VappAtvScreen::VappAtvScreen():
    m_app(NULL),
    m_scanLocPage(NULL),
    m_mainPage(NULL)
#ifdef __MMI_ATV_STORAGE_SELECT__
    , m_storagePage(NULL)
#endif
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    , m_settingPage(NULL)
#endif
#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
    , m_recSizePage(NULL)
#endif
{
}

void VappAtvScreen::on1stReady()
{
    VfxMainScr::on1stReady();
    setBgColor(VFX_COLOR_BLACK);// Herman advise.

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappAtvApp);

    entryScanLocPage();
}

void VappAtvScreen::on2ndReady()
{
    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappAtvApp);

	if(m_app->m_tempBuffer!=NULL)
	{
        applib_asm_free_r(VAPP_ATV, m_app->m_tempBuffer);
        m_app->m_tempBuffer = NULL;
	}

    MDI_RESULT ret;
    ret = m_app->openEngine();
    if (ret == MDI_RES_MTV_SUCCEED)
    {
        m_app->allocStructure();
    }

    if (m_app->getKernelState() == ATV_KERNEL_CLOSED)
    {
        displayPowerOnFailCfm();
        return;
    }
    
    if(!m_app->m_setting.is_inited)
    {
        m_scanLocPage->createCountryList();  //move the list menu in this function.
    }
    
    if( m_scanLocPage->m_actInd!=NULL)
    {
        m_scanLocPage->m_actInd->stop();
        VFX_OBJ_CLOSE(m_scanLocPage->m_actInd);
        m_scanLocPage->m_actInd = NULL;
    }
        
    if(m_scanLocPage->m_loadingPopup!=NULL)
    {
        m_scanLocPage->m_loadingPopup->exit(VFX_TRUE);
        VFX_OBJ_CLOSE(m_scanLocPage->m_loadingPopup);
        m_scanLocPage->m_loadingPopup = NULL;
    }
    
    m_app->m_1stEnter = VFX_TRUE;
    if (m_scanLocPage->m_displayScanProg)
    {
        if(!m_app->m_proc_close)  // when closing(ex: press home key in MT call). don't scan.
    {
            // Scan progress
            m_scanLocPage->displayScanProg();
        }
        m_scanLocPage->m_displayScanProg = VFX_FALSE;
    }
}

void VappAtvScreen::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappAtvScreen::displayPowerOnFailCfm(void)
{
    VcpConfirmPopup *cfm;
    VFX_OBJ_CREATE(cfm, VcpConfirmPopup, this);

    cfm->setInfoType(VCP_POPUP_TYPE_WARNING);
    cfm->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_NOTIFY_HW_NOT_READY));
    cfm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    cfm->m_signalButtonClicked.connect(
        this, &VappAtvScreen::onPowerOnFailCfmClicked);
    cfm->show(VFX_TRUE);
}

void VappAtvScreen::onPowerOnFailCfmClicked(VfxObject* sender, VfxU32 id)
{
    // Destroy APP
    m_app->exit();
}


void VappAtvScreen::entryScanLocPage()
{
    if (m_scanLocPage == NULL)
    {
        if (m_app->m_numServices == 0)
        {
		#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
            if (m_settingPage)
            {
                m_settingPage->exit();
                m_settingPage = NULL;
            }
		#endif
            if (m_mainPage)
            {
                m_mainPage->exit();
                m_mainPage = NULL;
            }
        }

        VFX_OBJ_CREATE(m_scanLocPage, VappAtvScanLocPage, this);
        m_scanLocPage->m_signalScanFinished.connect(
            this, &VappAtvScreen::entryMainPage);
    }
    pushPage(0, m_scanLocPage);
}

void VappAtvScreen::entryMainPage()
{
    // Exit scan location page
    if (m_scanLocPage)
    {
        m_scanLocPage->exit();
        m_scanLocPage = NULL;
    }

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    //exit the settingpage
    if (m_settingPage)
    {
        m_settingPage->exit();
        m_settingPage = NULL;
    }
#endif

    // Entry main screen
    if (m_mainPage)
    {

        m_mainPage->resetAnchor();
    }
    else
    {
        VFX_OBJ_CREATE(m_mainPage, VappAtvMainPage, this);
        m_mainPage->m_signalChangePage.connect(
            this, &VappAtvScreen::onPageChange);
        pushPage(0, m_mainPage);
    }
}

#ifdef __MMI_ATV_STORAGE_SELECT__
void VappAtvScreen::entryStoragePage()
{
    if (m_storagePage == NULL)
    {
        VFX_OBJ_CREATE(m_storagePage, VappAtvStoragePage, this);
        m_storagePage->m_signalStorageClicked.connect(
            this, &VappAtvScreen::onStroageClicked);
    }
    pushPage(0, m_storagePage);
}
#endif

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
void VappAtvScreen::entryRecSizePage()
{
    if (m_recSizePage == NULL)
    {
        VFX_OBJ_CREATE(m_recSizePage, VappAtvRecSizePage, this);
        m_recSizePage->m_signalRecSizeClicked.connect(
            this, &VappAtvScreen::onRecSizeClicked);
    }
    pushPage(0, m_recSizePage);
}
#endif

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
void VappAtvScreen::entrySettingPage()
{
    m_settingPage = NULL;

    VFX_OBJ_CREATE(m_settingPage, VappAtvSettingPage, this);
    m_settingPage->m_signalListCellClicked.connect(
            this, &VappAtvScreen::onSettingCellClicked);

    pushPage(0, m_settingPage);
}
#endif

#ifdef __MMI_ATV_STORAGE_SELECT__
void VappAtvScreen::onStroageClicked()
{
    //go back to main screen
    m_storagePage->exit();
    m_storagePage = NULL;
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    m_settingPage->exit();
    m_settingPage = NULL;
#endif
}
#endif

#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
void VappAtvScreen::onRecSizeClicked()
{
    //go back to main screen
    m_recSizePage->exit();
    m_recSizePage = NULL;
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    m_settingPage->exit();
    m_settingPage = NULL;
#endif
}
#endif

#ifdef __MMI_ATV_PLAYER_SETTING__
void VappAtvScreen::displayPlayerSetting()
{
    m_mainPage->m_dispType = ATV_DISP_PLAYER_SETTING;
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    // Exit setting page
    m_settingPage->exit();
    m_settingPage = NULL;
#endif
}
#endif

void VappAtvScreen::onPageChange(VappAtvMainPage::PAGE_TYPE_ENUM type)
{
    switch (type)
    {
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        case VappAtvMainPage::PAGE_SETTING:
            entrySettingPage();
            break;
	#endif
        case VappAtvMainPage::PAGE_SCAN_LOC:
            entryScanLocPage();
            break;
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		case VappAtvMainPage::PAGE_STORAGE_SELECT:
			entryStoragePage();
			break;
	#endif
        default:
            ASSERT(0);
    }
}


void VappAtvScreen::onSettingCellClicked(VappAtvSettingPage::CELL_TYPE_ENUM type)
{
    switch (type)
    {
        case VappAtvSettingPage::CELL_SCAN_LOCATION:
            entryScanLocPage();
            break;
#ifdef __MMI_ATV_PLAYER_SETTING__
        case VappAtvSettingPage::CELL_PLAYER_SETTING:
            displayPlayerSetting();
            break;
#endif
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
        case VappAtvSettingPage::CELL_RECORD_SIZE:
            entryRecSizePage();
            break;
#endif
#ifdef __MMI_ATV_STORAGE_SELECT__
        case VappAtvSettingPage::CELL_STORAGE:
            entryStoragePage();
            break;
#endif
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * Scan Location Page Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvScanLocPage", VappAtvScanLocPage, VfxPage);

VappAtvScanLocPage::VappAtvScanLocPage():
    m_locListCreated(VFX_FALSE),
    m_displayScanProg(VFX_FALSE),
    m_scanProg(NULL),
    m_toolBar(NULL),
    m_loadingPopup(NULL),
    m_actInd(NULL)
{
}


void VappAtvScanLocPage::onInit()
{
    VfxPage::onInit();

    /* Get App */
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);


    if (!m_app->m_setting.is_inited || m_app->m_scrn->m_mainPage)
    {
        setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        displayScanLocList();
    }
    else
    {
        setStatusBar(VFX_FALSE);
        setBgColor(VRT_COLOR_BLACK);

        m_displayScanProg = VFX_TRUE;
    }
}

void VappAtvScanLocPage::onDeinit()
{
    m_app->m_scrn->m_scanLocPage = NULL;
    VfxPage::onDeinit();
}

void VappAtvScanLocPage::onEnter(VfxBool isBackward)
{
    if (m_displayScanProg & m_app->m_1stEnter)
    {
        if(!m_app->m_proc_close)  // when closing(ex: press home key in MT call). don't scan.
        {
            // Scan progress
            displayScanProg();
        }
        m_displayScanProg = VFX_FALSE;
    }

    if(!m_app->m_1stEnter && m_app->m_setting.is_inited)    
    {
        VFX_OBJ_CREATE(m_loadingPopup,VcpLoadingPopup,this);
        m_loadingPopup->setIcon(VfxImageSrc(MAIN_MENU_ATV_ICON));
        m_loadingPopup->show(VFX_TRUE);
        m_loadingPopup->setAutoDestory(VFX_TRUE);
    }
}

void VappAtvScanLocPage::onExit(VfxBool isBackward)
{
    if (m_app->getKernelState() == ATV_KERNEL_SCANNING)
    {
        m_app->clearPageHighPriority();
        m_app->abortScanService();
        VFX_OBJ_CLOSE(m_scanProg);
        m_displayScanProg = VFX_TRUE;
    }
}

void VappAtvScanLocPage::onBack()
{
    if(m_app->getKernelState() == ATV_KERNEL_CLOSED)
    {   
        VfxPage::onBack();
        return;
    }
    
    if (!m_app->m_scrn->m_mainPage || m_app->m_numServices == 0)
    {
        if(m_app->m_setting.is_inited && !m_app->m_scrn->m_mainPage)
        {
            // Stop scan
            m_app->abortScanService();

            // get service list
            m_app->getServiceList();
        }

        m_app->closeEngine();
        displayPleaseWait();
    }
    else
    {
        VfxPage::onBack();
    }
}

void VappAtvScanLocPage::displayScanProg()
{
    if(m_scanProg!=NULL)
    {
        VFX_OBJ_CLOSE(m_scanProg);
        m_scanProg=NULL;
    }
    ASSERT(m_scanProg == NULL);
    VFX_OBJ_CREATE(m_scanProg, VappAtvScanProg, this);
    m_scanProg->m_signal.connect(this, &VappAtvScanLocPage::scanEvthandler);
}


void VappAtvScanLocPage::displayScanLocList()
{
    ASSERT(m_locListCreated == VFX_FALSE);

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ATV_SCAN_LOCATION));

    setTopBar(titleBar);

    // Tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(
        BUTTON_SCAN, VFX_WSTR_RES(STR_ID_VAPP_ATV_SCAN), VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);

    VfxResId strId;
    VfxResId imgId;
    if (m_app->m_numServices == 0)
    {
        strId = STR_GLOBAL_EXIT;
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT;
    }
    else
    {
        strId = STR_GLOBAL_CANCEL;
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
    }

    m_toolBar->addItem(BUTTON_CANCEL_EXIT, VFX_WSTR_RES(strId), imgId);

    m_toolBar->m_signalButtonTap.connect(
        this, &VappAtvScanLocPage::countrySelHandler);

    setBottomBar(m_toolBar);

    
    if(m_app->m_1stEnter)
    {
        createCountryList();
    }
    else
    {
        VFX_OBJ_CREATE(m_actInd,VcpActivityIndicator,this);
        m_actInd->setPos(getSize().width / 2, getSize().height / 2);
        m_actInd->setAnchor(0.5,0.5);
        m_actInd->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_MID,
            VFX_FRAME_ALIGNER_MODE_MID,
            VFX_FRAME_ALIGNER_MODE_MID,
            VFX_FRAME_ALIGNER_MODE_MID);
        m_actInd->start();
    }
}

void VappAtvScanLocPage::createCountryList()
{
    // Country list
    VcpListMenu * counList;
    VFX_OBJ_CREATE(counList, VcpListMenu, this);
    counList->setSize(getSize());
    counList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    counList->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_FALSE);
    counList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    counList->m_signalItemSelectionStateChanged.connect(
        this,&VappAtvScanLocPage::countryHilightHandler);
    counList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);
    counList->setContentProvider(this);

    hilight_country = m_app->m_setting.selected_country;
    counList->setVisibleMenuItem(hilight_country);

    m_locListCreated = MMI_TRUE;
}

void VappAtvScanLocPage::scanEvthandler(VappAtvScanProg::EVT_TYPE_ENUM evt)
{
    VFX_OBJ_CLOSE(m_scanProg);

    switch (evt)
    {
        case VappAtvScanProg::EVT_CHANGE_SCAN_LOC:

            if (!m_locListCreated)
            {
                displayScanLocList();
            }
            else
            {
                m_toolBar->changeItem(
                    BUTTON_CANCEL_EXIT, VFX_WSTR_RES(STR_GLOBAL_EXIT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);
            }
            break;

        case VappAtvScanProg::EVT_EXIT:

            m_app->closeEngine();
            displayPleaseWait();

            break;

        case VappAtvScanProg::EVT_SCAN_FINISHED:

            m_signalScanFinished.emit();

            break;
        case VappAtvScanProg::EVT_SCAN_FAIL:
            showMdiFailConfirm(MDI_RES_MTV_FAILED);
            break;
    }
}

void VappAtvScanLocPage::showMdiFailConfirm(MDI_RESULT ret)
{
    VcpConfirmPopup *cfm;
    VFX_OBJ_CREATE(cfm, VcpConfirmPopup, this);

    cfm->setInfoType(VCP_POPUP_TYPE_WARNING);

    mmi_event_notify_enum popup_type;
    MMI_ID_TYPE string_id;
    string_id = mdi_util_get_mdi_error_info(ret, &popup_type);

    cfm->setText(VFX_WSTR_RES(string_id));
    cfm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    cfm->show(VFX_TRUE);
}

void VappAtvScanLocPage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

VfxU32 VappAtvScanLocPage::getCount(void) const
{
    return STR_ID_VAPP_ATV_COUNTRY_END - STR_ID_VAPP_ATV_COUNTRY_START - 1;
}


VfxBool VappAtvScanLocPage::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color)
{
    if(fieldType != VCP_LIST_MENU_FIELD_TEXT)
    {
        return VFX_FALSE;
    }

    text = VFX_WSTR_RES(STR_ID_VAPP_ATV_COUNTRY_START + 1 + index);
    return VFX_TRUE;
}



VcpListMenuItemStateEnum VappAtvScanLocPage::getItemState(VfxU32 index) const
{
    //if (index == m_app->m_setting.selected_country)
    if (index == hilight_country)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


void VappAtvScanLocPage::countryHilightHandler(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        hilight_country = index;
    }
}


void VappAtvScanLocPage::countrySelHandler(VfxObject* obj, VfxId id)
{

    switch(id)
    {
        case BUTTON_SCAN:
        {
            //stop service first
            m_app->deInitDisplay(MMI_TRUE);

            m_app->m_setting.selected_country = hilight_country;

            displayScanProg();

            break;
        }

        case BUTTON_CANCEL_EXIT:
        {
            if (!m_app->m_scrn->m_mainPage || m_app->m_numServices == 0)
            {
                m_app->closeEngine();
                displayPleaseWait();
            }
            else
            {
                //pop scanLoc page
                m_app->m_scrn->popPage();
               /*if (m_app->m_scrn->m_settingPage)
                {
                    m_app->m_scrn->m_settingPage->exit();
                    m_app->m_scrn->m_settingPage = NULL;
                }*/
            }

            break;
        }

        default:
            break;
    }

}

void VappAtvScanLocPage::displayPleaseWait()
{
    VcpIndicatorPopup *indPopup;

    VFX_OBJ_CREATE(indPopup, VcpIndicatorPopup, this);
    indPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    indPopup->show(VFX_TRUE);
}

/*****************************************************************************
 * Scan Progress Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvScanProg", VappAtvScanProg, VfxControl);

VappAtvScanProg::VappAtvScanProg():
    m_cfm(NULL),
    m_progPopup(NULL)
{
}


void VappAtvScanProg::onInit()
{
    VfxControl::onInit();

    /* Get App */
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    VFX_OBJ_CREATE(m_progPopup, VcpIndicatorPopup, this);

    m_progPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);


    m_progPopup->setAutoDestory(VFX_FALSE);

    if (m_app->m_setting.is_inited && !m_app->m_scrn->m_mainPage)
    {
        m_progPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_INITIALIZING));
    }
    else
    {
        m_progPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_SCANNING));
        m_progPopup->m_signalCanceled.connect(
            this, &VappAtvScanProg::cancelScanHandler);
        m_progPopup->show(VFX_TRUE);
    }


    // start scan
    startScan();
}

void VappAtvScanProg::startScan()
{
    MDI_RESULT ret;

    m_app->setPageHighPriority();
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    
    m_progPopup->setProgress(0.0);
    ret = m_app->scanService();

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        m_app->clearPageHighPriority();
        srv_backlight_turn_off();
        
        m_signal.emit(EVT_SCAN_FAIL);
    }
}

void VappAtvScanProg::setScanProgress(VfxFloat value)
{
    m_progPopup->setProgress(value);
}

void VappAtvScanProg::cancelScanHandler(VfxObject* obj, VfxFloat progress)
{
    m_app->clearPageHighPriority();
    srv_backlight_turn_off();

    // Stop scan
    m_app->abortScanService();

    // get service list
    m_app->getServiceList();

    scanFinishHandler();
}

void VappAtvScanProg::scanFinishHandler(void)
{
    VFX_OBJ_CLOSE(m_progPopup);
    m_app->clearPageHighPriority();
    srv_backlight_turn_off();

    if (m_app->m_numServices > 0)
    {
        m_app->m_setting.is_inited = MMI_TRUE;
        m_app->writeSetting();
#ifdef __MMI_ATV_RECORD__
        m_app->initRecSizeList();
#endif
        // reset cell
        if (m_app->m_scrn->m_mainPage)
        {
        	#ifndef __MMI_ATV_SLIM__
            VappAtvWheelPanel *wheel = m_app->m_scrn->m_mainPage->m_wheelPanel;
			#else
			VappAtvWheelPanelSlim *wheel = m_app->m_scrn->m_mainPage->m_wheelPanel;
			#endif

            VfxS32 idx;
            for(idx = 0; idx < m_app->m_numPrevServices; idx ++)
            {
                wheel->resetCell(idx);
            }
            wheel->initWheelFocus();
        }
        m_app->m_numPrevServices = m_app->m_numServices;

        // Notify scan finish
        m_signal.emit(EVT_SCAN_FINISHED);
    }
    else
    {
        m_app->m_setting.is_inited = MMI_FALSE;
        m_app->writeSetting();

        displayScanAgainConfirm();
    }
}

void VappAtvScanProg::displayScanAgainConfirm(void)
{
    ASSERT(m_cfm == NULL);
    VFX_OBJ_CREATE(m_cfm, VcpConfirmPopup, this);

    m_cfm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_cfm->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_NO_SERVICE_ASK));
    m_cfm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_cfm->setCustomButton(
        VFX_WSTR_RES(STR_ID_VAPP_ATV_CHANGE_SCAN_LOCATION),
        VFX_WSTR_RES(STR_GLOBAL_EXIT),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_cfm->m_signalButtonClicked.connect(
        this, &VappAtvScanProg::onScanConfirmClicked);
    m_cfm->show(VFX_TRUE);
}


void VappAtvScanProg::onScanConfirmClicked(VfxObject* sender, VfxU32 id)
{
    //VFX_OBJ_CLOSE(m_cfm);

    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            m_signal.emit(EVT_CHANGE_SCAN_LOC);

            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            m_signal.emit(EVT_EXIT);

            break;
    }
}



/*****************************************************************************
 * Settings Page Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvSettingPage", VappAtvSettingPage, VfxPage);

void VappAtvSettingPage::onInit()
{
    VfxPage::onInit();

    

    /* Get App */
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_SETTINGS));

    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    // Scan location
    S32 idx = 0;
    VFX_OBJ_CREATE(m_cell[idx], VcpFormItemLauncherCell, m_form);
	m_cell[idx]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_ATV_SCAN_LOCATION));
	m_cell[idx]->setHintText(
        VFX_WSTR_RES(STR_ID_VAPP_ATV_COUNTRY_START + 1 + m_app->m_setting.selected_country));
	m_cell[idx]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_cell[idx]->m_signalTap.connect(this, &VappAtvSettingPage::settingSelHandler);
    m_form->addItem(m_cell[idx], CELL_SCAN_LOCATION);
    idx ++;

#ifdef __MMI_ATV_PLAYER_SETTING__
    // Player setting
    VFX_OBJ_CREATE(m_cell[idx], VcpFormItemLauncherCell, m_form);
	m_cell[idx]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_ATV_PLAYER_SETTINGS));
	m_cell[idx]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_ATV_SET_PLAYER_SETTING));
	m_cell[idx]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_cell[idx]->m_signalTap.connect(this, &VappAtvSettingPage::settingSelHandler);
    m_form->addItem(m_cell[idx], CELL_PLAYER_SETTING);
    idx ++;
#endif

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
    // Record size
    mdi_mtv_recorder_size_enum size;
    VFX_OBJ_CREATE(m_cell[idx], VcpFormItemLauncherCell, m_form);
	m_cell[idx]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_ATV_RECORD_SIZE));
    size = (mdi_mtv_recorder_size_enum)m_app->m_setting.record_size;
	m_cell[idx]->setHintText(m_app->getRecSizeString(size));
	m_cell[idx]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_cell[idx]->m_signalTap.connect(this, &VappAtvSettingPage::settingSelHandler);
    m_form->addItem(m_cell[idx], CELL_RECORD_SIZE);
    idx ++;
#endif

#ifdef __MMI_ATV_STORAGE_SELECT__
    // Storage
    VFX_OBJ_CREATE(m_cell[idx], VcpFormItemLauncherCell, m_form);
	m_cell[idx]->setMainText(VFX_WSTR_RES(STR_GLOBAL_STORAGE));
	m_cell[idx]->setHintText(m_app->getDrvString((srv_fmgr_drv_type_enum)m_app->m_setting.storage));
	m_cell[idx]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_cell[idx]->m_signalTap.connect(this, &VappAtvSettingPage::settingSelHandler);
    m_form->addItem(m_cell[idx], CELL_STORAGE);
    idx ++;
    // set cell status
    setIsCellEnabled();
#endif
}

#ifdef __MMI_ATV_STORAGE_SELECT__
void VappAtvSettingPage::setIsCellEnabled()
{
    // set storage cell status
#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    //if (srv_usb_is_in_mass_storage_mode())
    if(m_app->m_massStorageMode)
    {
        m_cell[CELL_STORAGE]->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_cell[CELL_STORAGE]->setIsDisabled(VFX_FALSE);
    }
#endif /* __MMI_USB_SUPPORT__ */
}
#endif


void VappAtvSettingPage::onDeinit()
{
   //m_app->m_scrn->m_settingPage = NULL;
    VfxPage::onDeinit();
}

void VappAtvSettingPage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappAtvSettingPage::settingSelHandler(VcpFormItemCell* sender, VfxId Id)
{
    m_signalListCellClicked.emit((CELL_TYPE_ENUM)Id);
}

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_RECORD_SIZE_SELECT__)
/*****************************************************************************
 * Record Size Page Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvRecSizePage", VappAtvRecSizePage, VfxPage);

void VappAtvRecSizePage::onInit()
{
    VfxPage::onInit();

    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ATV_RECORD_SIZE));

    setTopBar(titleBar);

    // RecSize list
    VcpListMenu * sizeList;
    VFX_OBJ_CREATE(sizeList, VcpListMenu, this);
    sizeList->setSize(getSize());
    sizeList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    sizeList->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    sizeList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    sizeList->m_signalItemTapped.connect(
        this,&VappAtvRecSizePage::SizeSelHandler);
    sizeList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);
    sizeList->setContentProvider(this);

}

void VappAtvRecSizePage::onDeinit()
{
    m_app->m_scrn->m_recSizePage = NULL;
    VfxPage::onDeinit();
}

void VappAtvRecSizePage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}


VfxU32 VappAtvRecSizePage::getCount(void) const
{
    return m_app->recSizeNum;
}


VfxBool VappAtvRecSizePage::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color)
{
    if(fieldType != VCP_LIST_MENU_FIELD_TEXT)
    {
        return VFX_FALSE;
    }

    text = m_app->getRecSizeString(m_app->recSizeList[(m_app->recSizeNum)-index-1]);

    return VFX_TRUE;
}



VcpListMenuItemStateEnum VappAtvRecSizePage::getItemState(VfxU32 index) const
{
    if (m_app->recSizeList[(m_app->recSizeNum)-index-1] == m_app->m_setting.record_size)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappAtvRecSizePage::SizeSelHandler(VcpListMenu *menu, VfxU32 index)
{
    if (m_app->recSizeList[(m_app->recSizeNum)-index-1] != m_app->m_setting.record_size)
    {
        m_app->setRecSize(m_app->recSizeList[(m_app->recSizeNum)-index-1]);

        //update video frame size
        m_app->m_scrn->m_mainPage->setVideoFramePosSize();
    }

    m_signalRecSizeClicked.emit();
}
#endif

#ifdef __MMI_ATV_STORAGE_SELECT__
/*****************************************************************************
 * Record Size Page Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvStoragePage", VappAtvStoragePage, VfxPage);
VappAtvStoragePage::VappAtvStoragePage()
{
}


void VappAtvStoragePage::onInit()
{
    VfxPage::onInit();

    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_STORAGE));
    setTopBar(titleBar);

    // Storage
    VFX_OBJ_CREATE(m_storageList, VcpListMenu, this);
    m_storageList->setSize(getSize());
    m_storageList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_storageList->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_storageList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_storageList->m_signalItemTapped.connect(
        this,&VappAtvStoragePage::StorageSelHandler);
    m_storageList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_storageList->setContentProvider(this);

    //init status
    initStorageStatus();
}

void VappAtvStoragePage::onEntered()
{
    VfxPage::onEntered();
    m_storageList->updateAllItems();

}

void VappAtvStoragePage::onDeinit()
{
    VFX_OBJ_CLOSE(m_storageList);
    m_app->m_scrn->m_storagePage = NULL;
    VfxPage::onDeinit();
}

void VappAtvStoragePage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}


VfxU32 VappAtvStoragePage::getCount(void) const
{
    return storageNum;
}


VfxBool VappAtvStoragePage::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color)
{
    if(fieldType != VCP_LIST_MENU_FIELD_TEXT)
    {
        return VFX_FALSE;
    }

    ASSERT(index < 2);

    text = m_app->getDrvString(drvType[index]);

    return VFX_TRUE;
}



VcpListMenuItemStateEnum VappAtvStoragePage::getItemState(VfxU32 index) const
{
    if (drvType[index] == m_app->m_setting.storage)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

VfxBool VappAtvStoragePage::getItemIsDisabled(VfxU32 index) const
{
    if (index == 0)
    {
        return VFX_FALSE;
    }
    else
    {
        if (srv_fmgr_drv_is_accessible(
           srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
        {
           return VFX_FALSE;
        }
        else
        {
           return VFX_TRUE;
        }
    }
}

void VappAtvStoragePage::StorageSelHandler(VcpListMenu *menu, VfxU32 index)
{
    if (drvType[index] != m_app->m_setting.storage)
    {
        m_app->setStorage(drvType[index]);
    }

    m_signalStorageClicked.emit();

}

void VappAtvStoragePage::initStorageStatus()
{
    storageNum = 0;
    drvType[storageNum ++] = SRV_FMGR_DRV_PHONE_TYPE;
    drvType[storageNum ++] = SRV_FMGR_DRV_CARD_TYPE;

   /* if (srv_fmgr_drv_is_accessible(
            srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE)))
    {
        drvType[storageNum ++] = SRV_FMGR_DRV_PHONE_TYPE;
    }

    if (srv_fmgr_drv_is_accessible(
            srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        drvType[storageNum ++] = SRV_FMGR_DRV_CARD_TYPE;
    }
     */
    
    
}

void VappAtvStoragePage::setItemDisable(VfxU32 index,VfxBool isDisabled)
{
    /*m_storageList->getCell(index)->setIsDisabled(isDisabled);
    if(isDisabled)
    {
        if(m_coverFrame!=NULL)
        {
            VFX_OBJ_CLOSE(m_coverFrame);
            m_coverFrame = NULL;
        }
        
        VFX_OBJ_CREATE(m_coverFrame,VfxFrame,this);
        m_coverFrame->setPos(0,index*(m_storageList->getItemHeight(0)));
        m_coverFrame->setSize(getSize().width,m_storageList->getItemHeight(0));
        m_coverFrame->bringToFront();
        m_coverFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        m_coverFrame->setBgColor(VRT_COLOR_MAKE(178, 220, 220, 220));

    }
    else
    {
        VFX_OBJ_CLOSE(m_coverFrame);
        m_coverFrame = NULL;
        
    }*/
    
    m_storageList->updateAllItems();
}
#endif// __MMI_ATV_STORAGE_SELECT__

#endif //__MMI_ATV_SUPPORT__
