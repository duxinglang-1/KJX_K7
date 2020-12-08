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
 *  vapp_widget_installer.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __GADGET_SUPPORT__
#include "MMIDataType.h"
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"  
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_widget_installer.h"
#include "mmi_rp_vapp_wgtinst_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"
extern "C" 
{
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "FileMgrCUIGProt.h"
#include "FileMgrSrvGProt.h"
#include "ProcedureGprot.h"
#include "custom_gadget_config.h"
}

#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif

#include "vapp_bootup_app.h"
#include "vapp_widget_adp.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_WIDGET_INSTALLER_TEXT_VIEW_HEIGHT (230)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_WIDTH (35)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_HEIGHT (35)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_WIDGET_INSTALLER_TEXT_VIEW_HEIGHT (300)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_WIDTH (35)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_HEIGHT (35)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_WIDGET_INSTALLER_TEXT_VIEW_HEIGHT (380)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_WIDTH (40)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_HEIGHT (40)
#else
#define VAPP_WIDGET_INSTALLER_TEXT_VIEW_HEIGHT (630)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_WIDTH (50)
#define VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_HEIGHT (50)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static VappWidgetInstallerApp *g_app = NULL;
static mmi_frm_proc_id_info_struct g_id_info;
static VfxBool g_widget_installer_notify_free = VFX_FALSE;
static VfxBool g_widget_installer_launch = VFX_FALSE;

/***************************************************************************** 
 * Local Functions
 *****************************************************************************/
static VfxResId vapp_wgtmgr_installer_translate_error_to_string(srv_wgtmgr_result_enum error)
{
    VfxResId error_string;

    switch (error)
    {
        case SRV_WGTMGR_RET_MEM_NOT_ENOUGH:
            error_string = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;

		case SRV_WGTMGR_RET_WGT_CORRUPTED:
            error_string = STR_ID_VAPP_WGTINST_WIDGET_IS_CORRUPTED;
            break;

        case SRV_WGTMGR_RET_EXCEED_MAX_INSTALLED_NUM:
            error_string = STR_ID_VAPP_WGTINST_OVER_MAX_INSTALL;
            break;

        case SRV_WGTMGR_RET_WGT_NOT_VALID:
            error_string = STR_ID_VAPP_WGTINST_WIDGET_IS_NOT_VALID;
            break;

        case SRV_WGTMGR_RET_DISK_SPACE_NOT_ENOUGH:
            error_string = STR_ID_VAPP_WGTINST_DISK_SPACE_IS_NOT_ENOUGH;
            break;

        default:
            error_string = STR_GLOBAL_ERROR;
            break;
   	}
    return error_string;

}



/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_widget_installer_launch(const WCHAR* filepath)
{
    g_widget_installer_launch = VFX_TRUE;

    VfxAppLauncher::launch( 
        VAPP_WGTINST,
        VFX_OBJ_CLASS_INFO(VappWidgetInstallerApp),
        GRP_ID_ROOT, 
        (void*)filepath,
        (kal_wstrlen(filepath) + 1) * sizeof(WCHAR));
}

VfxBool vapp_widget_installer_is_launched()
{
    return (g_app != NULL || g_widget_installer_launch == VFX_TRUE) ? VFX_TRUE : VFX_FALSE;
}

VfxBool vapp_widget_installer_is_wait_to_free_handler()
{
    if (g_widget_installer_notify_free)
    {
        g_widget_installer_notify_free = VFX_FALSE;

        VappWidgetInstallerApp *instApp = 
            (VappWidgetInstallerApp *) VfxAppLauncher::findApp(VAPP_WGTINST, VFX_OBJ_CLASS_INFO(VappWidgetInstallerApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
        
        if (instApp)
        {
            instApp->continueClose(VFX_APP_CLOSE_ANSWER_YES);
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

static mmi_ret vapp_widget_preinstaller_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    { 
        case EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND:
        {
            mmi_frm_proc_notify_completed(g_id_info);

            break;
        }
    }

    return MMI_RET_OK;
}


mmi_frm_proc_result_enum vapp_widget_preinstall_widget(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_wgtmgr_preinstall_widget() == MMI_FALSE)
    {
        g_widget_installer_launch = VFX_TRUE;

       	g_id_info = id_info;

        VappBootupApp *bootup_app = VappBootupApp::getApp();

        VfxMainScr *top_scrn = VFX_OBJ_DYNAMIC_CAST(bootup_app->getTopScreen(), VfxMainScr);

        ASSERT(top_scrn);

        VappWidgetPreInstallerPage *page;

        VFX_OBJ_CREATE(page, VappWidgetPreInstallerPage, top_scrn);

        top_scrn->pushPage(VappBootupApp::PAGE_PREINSTALL_WIDGETS, page);

        mmi_frm_cb_reg_event(EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND, vapp_widget_preinstaller_proc, NULL);

        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


extern "C" void vapp_widget_installer_install_wgt(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    vapp_widget_installer_launch(filepath);
}


extern "C" void vapp_widget_installer_install_wgt_callback(S16 wgt_id, srv_wgtmgr_install_wgt_result_struct *info, void * user_data)
{
    if (g_app != NULL)
   	{
        g_app->installWidgetCont(wgt_id, info);
    }
    else
    {
        // Cancel the installation if app does not exists
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
    }
}


extern "C" void vapp_widget_installer_install_wgt_finish_callback(srv_wgtmgr_result_enum ret, void * user_data)
{
    if (g_app != NULL)
    {
        g_app->installWidgetFinish(ret);
    }
}


/***************************************************************************** 
 * VappWidgetInstallerApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetInstallerApp", VappWidgetInstallerApp, VfxApp);

void VappWidgetInstallerApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // Set g_app pointer, it wll be used when callback is invoked by WgtMgrSrv
    g_app = this;

    // Set installed widget id to -1
    m_id = -1;

    // Create and display main screen
    VFX_OBJ_CREATE(m_scrn, VappWidgetInstallerScreen, this);

    // Chage state, it means the app starts the installation
    m_state = VAPP_WGTINST_STATE_START;

    // Invoke widget manager service api to install widget
    srv_wgtmgr_install_wgt((WCHAR*)args, vapp_widget_installer_install_wgt_callback, NULL);

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, eventHandler, this);
#endif

    m_scrn->show();

    VappWidgetInstallerPage *page = getPage();

}


void VappWidgetInstallerApp::onDeinit()
{
    // If it is waiting for user's decision, it needs to send cancellation to WgtMgrSrv
    if (m_state == VAPP_WGTINST_STATE_QUERY)
    {
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
    }
    m_state = VAPP_WGTINST_STATE_NULL;

    // Set g_app to NULL since the application is closing
    g_app = NULL;

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, eventHandler, this);
#endif

    g_widget_installer_launch = VFX_FALSE;

    VfxApp::onDeinit();
}

VfxAppCloseAnswerEnum VappWidgetInstallerApp::onProcessClose(VfxAppCloseOption options)
{
    if (options & VFX_APP_CLOSE_OPTION_NO_FLAG) /* press home key */
    {
        return VFX_APP_CLOSE_ANSWER_YES;
    }
    else
    {
        if (custom_gadget_using_asm() == KAL_TRUE)
        {
            if (vapp_widget_is_wait_asm_rsp() == VFX_TRUE)
            {
                return VFX_APP_CLOSE_ANSWER_YES;
            }

            g_widget_installer_notify_free = VFX_TRUE;

            vapp_widget_send_message(NULL, NULL, MSG_ID_WIDGET_FREE_ASM_REQ, MOD_GADGET);

            return VFX_APP_CLOSE_ANSWER_LATER;
        }
        else
        {
            return VFX_APP_CLOSE_ANSWER_YES;
        }
    }

    return VfxApp::onProcessClose(options);
}

void VappWidgetInstallerApp::continueClose(VfxAppCloseAnswerEnum answer)
{
    VfxApp::continueClose(answer);
}

void VappWidgetInstallerApp::installWidgetCont(VfxS16 wgt_id, void* result)
{
    srv_wgtmgr_install_wgt_result_struct *info = (srv_wgtmgr_install_wgt_result_struct*)result;

    VappWidgetInstallerPage *page = getPage();

    m_id = wgt_id;

    if (page != NULL && m_state == VAPP_WGTINST_STATE_START)
    {
        srv_wgtmgr_result_enum ret = info->result;

        // Stop the installing indicator first
        page->stopIndicatorPopup();

        // Connect signal handler to receive action
        page->m_signalAction.connect(this, &VappWidgetInstallerApp::onActionHandler);

        if (ret == SRV_WGTMGR_RET_OK || ret == SRV_WGTMGR_RET_OLD_VERSION ||
            ret == SRV_WGTMGR_RET_NEW_VERSION || ret == SRV_WGTMGR_RET_ALREADY_INSTALLED)
        {
            m_state = VAPP_WGTINST_STATE_QUERY;
            page->displayWidgetInfo((void*)info);
        }
        else
        {
            // it encounters a problem when installing a widget, display an error popup
            page->displayPopup(VCP_POPUP_TYPE_FAILURE, vapp_wgtmgr_installer_translate_error_to_string(ret));
        }
    }
    else
    {
        // Cancel the installation if page does not exists
        srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
    }
}


void VappWidgetInstallerApp::installWidgetFinish(VfxS32 ret)
{
    VappWidgetInstallerPage *page = getPage();

    if (page != NULL && m_state == VAPP_WGTINST_STATE_CONT)
    {
        // Close widget details view if re-installed the opened widget
        vapp_widget_terminate_widget(m_id);

        // Stop displaying indicator first
        page->stopIndicatorPopup();

        if (ret == SRV_WGTMGR_RET_OK)
        {
            page->displayPopup(VCP_POPUP_TYPE_SUCCESS, STR_ID_VAPP_WGTINST_INSTALLED);
        }
        else
        {
            // Delete the widget
            if (m_id != -1)
            {
                srv_wgtmgr_delete_wgt(m_id, NULL, NULL);
            }

            page->displayPopup(VCP_POPUP_TYPE_FAILURE, vapp_wgtmgr_installer_translate_error_to_string((srv_wgtmgr_result_enum)ret));
        }
    }
    m_state = VAPP_WGTINST_STATE_NULL;
}


VappWidgetInstallerPage* VappWidgetInstallerApp::getPage()
{
    VappWidgetInstallerPage *page = NULL;
    if (m_scrn != NULL)
    {
        page = m_scrn->m_page;
    }
    return page;
}


void VappWidgetInstallerApp::onActionHandler(VappWidgetInstallerAction act)
{
    VappWidgetInstallerPage *page = getPage();

    if (page != NULL)
    {
        if (act == VAPP_WGTINST_ACT_INSTALL_CONT)
        {
            page->selectStorage();
        }
        else if(act == VAPP_WGTINST_ACT_INSTALL_CANCEL)
        {
            page->displayPopup(VCP_POPUP_TYPE_FAILURE, STR_ID_VAPP_WGTINST_CANCELED);
            srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CANCEL, (srv_wgtmgr_wgt_drive_enum)0, NULL, NULL);
            m_state = VAPP_WGTINST_STATE_NULL;
        }
        else if (act == VAPP_WGTINST_ACT_POPUP_END)
        {
            m_scrn->popPage();
        }
        else if (act == VAPP_WGTINST_ACT_SELECT_PHONE || act == VAPP_WGTINST_ACT_SELECT_MEMCARD)
        {
            page->displayIndicatorPopup();

            srv_wgtmgr_wgt_drive_enum drive = SRV_WGTMGR_DRIVE_PUBLIC;

            if(act == VAPP_WGTINST_ACT_SELECT_MEMCARD)
            {
                drive = SRV_WGTMGR_DRIVE_MEMORY_CARD;
            }
            // Continue the installation
            srv_wgtmgr_install_wgt_cont(SRV_WGTMGR_INSTALL_CONT, drive, vapp_widget_installer_install_wgt_finish_callback, NULL);
            m_state = VAPP_WGTINST_STATE_CONT;
        }
    }
}


mmi_ret VappWidgetInstallerApp::eventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    if (evt->evt_id == EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND)
    {
        VappWidgetInstallerApp* app = (VappWidgetInstallerApp*) evt->user_data;
        app->exit();
        mmi_frm_proc_notify_completed(g_id_info);
    }

#ifdef __MMI_USB_SUPPORT__
    if (evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        VappWidgetInstallerApp* app = (VappWidgetInstallerApp*) evt->user_data;
        app->exit();
    }
#endif
    return MMI_RET_OK;
}

/***************************************************************************** 
 * VappWidgetInstallerScreen
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetInstallerScreen", VappWidgetInstallerScreen, VfxMainScr);

void VappWidgetInstallerScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VFX_OBJ_CREATE(m_page, VappWidgetInstallerPage, this);
    pushPage(0, m_page);
}


/***************************************************************************** 
 * VappWidgetInstallerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetInstallerPage", VappWidgetInstallerPage, VfxPage);

void VappWidgetInstallerPage::onInit()
{
    VfxPage::onInit();

    // Set title bar
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_INSTALL));
    setTopBar(bar);

    // Set backgroud color
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    displayIndicatorPopup();
}


void VappWidgetInstallerPage::displayIndicatorPopup()
{
    if (m_indicatorPopup == NULL)
    {
        VFX_OBJ_CREATE(m_indicatorPopup, VcpIndicatorPopup, this);
        m_indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_indicatorPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WGTINST_INSTALLING));
        m_indicatorPopup->show(VFX_TRUE);
    }
}


void VappWidgetInstallerPage::stopIndicatorPopup()
{
    if (m_indicatorPopup != NULL)
    {
        m_indicatorPopup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_indicatorPopup);
        m_indicatorPopup = NULL;
    }	
}


void VappWidgetInstallerPage::displayPopup(VcpPopupTypeEnum type, VfxResId id)
{

    VcpConfirmPopup *confirmPopup;
    VfxWString text = VFX_WSTR_RES(id);	
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
    confirmPopup->setInfoType(type);
    confirmPopup->setText(text);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappWidgetInstallerPage::onPopupEnd);
}
 

void VappWidgetInstallerPage::onPopupEnd(VfxObject* obj, VfxId id)
{
    VFX_UNUSED(obj);

    m_signalAction.postEmit(VAPP_WGTINST_ACT_POPUP_END);
}


void VappWidgetInstallerPage::eventHandler(VfxObject* obj, VfxId id)
{
    VFX_UNUSED(obj);
    VappWidgetInstallerAction act = VAPP_WGTINST_ACT_INSTALL_NONE;

    switch (id)
    {
        case ID_TOOLBAR_OK:
            act = VAPP_WGTINST_ACT_INSTALL_CONT;
            break;

        case ID_TOOLBAR_CANCEL:
        case ID_DRIVE_CANCEL:			
            act = VAPP_WGTINST_ACT_INSTALL_CANCEL;
            break;

        case ID_DRIVE_PHONE:
            act = VAPP_WGTINST_ACT_SELECT_PHONE;
            break;

        case ID_DRIVE_MEMCARD:
            act = VAPP_WGTINST_ACT_SELECT_MEMCARD;
            break;

        default:
            break;			
    }

    m_signalAction.postEmit(act);
}


void VappWidgetInstallerPage::selectStorage()
{
    VcpCommandPopup *commandPopup;
    VFX_OBJ_CREATE(commandPopup, VcpCommandPopup, this);
    commandPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    commandPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CHOOSE_STORAGE));
    commandPopup->addItem(ID_DRIVE_PHONE,   VFX_WSTR_RES(STR_GLOBAL_PHONE), VCP_POPUP_BUTTON_TYPE_NORMAL);
	
    if (srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV) == MMI_TRUE)
    {
        commandPopup->addItem(ID_DRIVE_MEMCARD, VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    commandPopup->addItem(ID_DRIVE_CANCEL,  VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    commandPopup->m_signalButtonClicked.connect(this, &VappWidgetInstallerPage::eventHandler);
    commandPopup->show(VFX_TRUE);
}


void VappWidgetInstallerPage::displayWidgetInfo(void *result)
{
    srv_wgtmgr_install_wgt_result_struct *info = (srv_wgtmgr_install_wgt_result_struct *)result;
    srv_wgtmgr_result_enum ret = info->result;

    // Prepare the widget infomation
    if (ret == SRV_WGTMGR_RET_OK)
    {
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_QUERY_FOR_INSTALL);
        m_text += VFX_WSTR("\n\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_NAME);
        m_text += VFX_WSTR_MEM(info->wgt_name);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_VERSION);
        m_text += VFX_WSTR_MEM(info->wgt_version_install);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_AUTHOR);
        m_text += VFX_WSTR_MEM(info->wgt_author);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_COPYRIGHT);
        m_text += VFX_WSTR_MEM(info->wgt_copyright);
        m_text += VFX_WSTR("\n");
    }
    else
    {
        VfxResId version_info;
        if (ret == SRV_WGTMGR_RET_NEW_VERSION)
        {
            version_info = STR_ID_VAPP_WGTINST_NEW_VERSION;			
        }
        else if (ret == SRV_WGTMGR_RET_OLD_VERSION)
        {
            version_info = STR_ID_VAPP_WGTINST_OLD_VERSION;
        }
        else
        {
            version_info = STR_ID_VAPP_WGTINST_ALREADY_INSTALLED;
        }
        m_text += VFX_WSTR_RES(version_info);
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_REPLACE_WIDGET);
        m_text += VFX_WSTR("\n\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_NAME);
        m_text += VFX_WSTR_MEM(info->wgt_name);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_CURRENT_VERSION);
        m_text += VFX_WSTR_MEM(info->wgt_version_original);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_VERSION_FOUND);
        m_text += VFX_WSTR_MEM(info->wgt_version_install);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_AUTHOR);
        m_text += VFX_WSTR_MEM(info->wgt_author);
        m_text += VFX_WSTR("\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_WGT_COPYRIGHT);
        m_text += VFX_WSTR_MEM(info->wgt_copyright);
        m_text += VFX_WSTR("\n\n");
        m_text += VFX_WSTR_RES(STR_ID_VAPP_WGTINST_CONTINUE_INSTALL);
    }

    // Creat text view to display widget information
    VcpTextView *text_view;
    VFX_OBJ_CREATE(text_view, VcpTextView, this);

    // Get main screen size
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

    text_view->setPos(VfxPoint(0, 6));
    text_view->setBounds(VfxRect(0, 0, mainScreenSize.width, VAPP_WIDGET_INSTALLER_TEXT_VIEW_HEIGHT));
    text_view->setMargins(10);
    text_view->setText(m_text);
    text_view->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    text_view->setAlignMode(VCP_TEXT_ALIGN_MODE_NATURAL);
    text_view->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

    // Create tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);

    // Add buttons on tool bar
    toolbar->addItem(ID_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolbar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    toolbar->m_signalButtonTap.connect(this, &VappWidgetInstallerPage::eventHandler);
    setBottomBar(toolbar);
}


/***************************************************************************** 
 * VappWidgetPreInstallerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetPreInstallerPage", VappWidgetPreInstallerPage, VfxPage);

void VappWidgetPreInstallerPage::onInit()
{
    VfxPage::onInit();

    // Set backgroud color
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    setStatusBar(VFX_FALSE);

    VcpActivityIndicator *loadingIcon;
    VFX_OBJ_CREATE(loadingIcon, VcpActivityIndicator, this);
    VfxU32 x, y;
    loadingIcon->setSize(VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_WIDTH, VAPP_WIDGET_INSTALLER_LOADING_ICON_SIZE_HEIGHT);
    x = getPageRect().getWidth()/2 - loadingIcon->getSize().width/2;
    y = getPageRect().getHeight()/2 - loadingIcon->getSize().height/2;
    loadingIcon->setPos(x, y);
    loadingIcon->start();

    VfxTextFrame *text_frame;
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(getPageRect().getWidth()/2, y - 40));
    text_frame->setString(VFX_WSTR_RES(STR_ID_VAPP_WGTINST_INSTALLING_WIDGET));
    text_frame->setAnchor(0.5f, 0.5f);
    text_frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    text_frame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

}


void VappWidgetPreInstallerPage::onDeinit()
{
    g_widget_installer_launch = VFX_FALSE;

    mmi_frm_cb_dereg_event(EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND, vapp_widget_preinstaller_proc, NULL);
    VfxPage::onDeinit();
}


VfxBool VappWidgetPreInstallerPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_POWER ||
        event.keyCode == VFX_KEY_CODE_END)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
        {
            if (event.keyCode != VFX_KEY_CODE_POWER)
            {
                return VFX_TRUE;
            }
        }
        else
        {
            if (event.keyCode != VFX_KEY_CODE_END)
            {
                return VFX_TRUE;
            }
        }
        
        if (event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
        {
            return VfxPage::onKeyInput(event);
        }
        else
        {
            return VFX_TRUE;
        }
    }

    return VFX_TRUE;
}

#endif
