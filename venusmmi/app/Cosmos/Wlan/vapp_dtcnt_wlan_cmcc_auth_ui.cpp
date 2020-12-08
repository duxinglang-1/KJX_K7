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
 *  vapp_dtcnt_wlan_cmcc_auth_ui.cpp
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
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_OP01_WIFI__
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_dtcnt_wlan_cmcc_auth_ui.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

extern "C"
{
#include "FileMgrType.h"
#include "SimCtrlSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "mmi_rp_vapp_wlan_auth_def.h"
}

static const char* VAPP_CMCC_WLAN_SETTING_FILENAME =  "cmccwlan.dat";
static const vappCmccWlanFileData initFileData = {VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, "", "",
                                                  {"10086", "10086", "10086", "KTWLAN", "XGWLANMM", "CZWLANMM"}};
vappCmccWlanSetting VappCmccWlanAutoAuth::s_cmccSettingData = {0};

/*******************************************************************************
* Export API 
*******************************************************************************/
extern "C" mmi_id vapp_dtcnt_wlan_auth_login(vapp_dtcnt_wlan_auth_callback cb)
{
    mmi_id launch_id;
    //save para
    VappCmccWlanAutoAuth::s_cmccSettingData.cb = cb;
    VappCmccWlanAutoAuth::s_cmccSettingData.login_state = VFX_TRUE;
    //find app, avoid app re_enter
    VappCmccWlanAutoAuthApp *app = (VappCmccWlanAutoAuthApp *)VfxAppLauncher::findApp(
    	                VAPP_WLAN_AUTH,
    	                VFX_OBJ_CLASS_INFO(VappCmccWlanAutoAuthApp), 
    	                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (app)
    {
        VappCmccWlanAutoAuthScr *scr = app->getScreen();
        if(scr)
        {
            scr->setLoginFlag(VFX_FALSE);
        }
        VfxAppLauncher::terminate(app->getGroupId());
    }
    //launch app
    launch_id = VfxAppLauncher::launch( 
        VAPP_WLAN_AUTH,
        VFX_OBJ_CLASS_INFO(VappCmccWlanAutoAuthApp),
        GRP_ID_ROOT,
        NULL, 
        0);
    return launch_id;
}

extern "C" mmi_id vapp_dtcnt_wlan_auth_logout(vapp_dtcnt_wlan_auth_callback cb)
{
    mmi_id launch_id = 0;
    //save para
    VappCmccWlanAutoAuth::s_cmccSettingData.cb = cb;
    VappCmccWlanAutoAuth::s_cmccSettingData.login_state = VFX_FALSE;
    vapp_cmcc_wlan_auth_ret_enum ret = VappCmccWlanAutoAuth::authLogout();
    //launch app
    if(VAPP_CMCC_WLAN_AUTH_WBLOCK == ret)
    {
        launch_id = VfxAppLauncher::launch( 
        		VAPP_WLAN_AUTH,
        		VFX_OBJ_CLASS_INFO(VappCmccWlanAutoAuthApp),
        		GRP_ID_ROOT,
        		NULL, 
        		0);
    }
    return launch_id;
}

extern "C" void vapp_dtcnt_wlan_auth_abort()
{
    VappCmccWlanAutoAuth::authAbort();
}

extern "C" mmi_ret vapp_dtcnt_wlan_auth_launch(mmi_event_struct *param)
{
    vapp_dtcnt_wlan_auth_login(VappCmccWlanAutoAuth::s_cmccSettingData.cb);
    return MMI_RET_OK;
}

extern "C" MMI_BOOL vapp_dtcnt_wlan_is_auto_auth()
{
    vappCmccWlanFileData cmccWlanFileData;
    VappCmccWlanAutoAuth::getDataFromFile(&cmccWlanFileData);
    return (MMI_BOOL)cmccWlanFileData.isAutoAuth;
}

/***************************************************************************** 
 * Class VcpCMCCConfirmPopup
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpCMCCConfirmPopup", VcpCMCCConfirmPopup, VcpConfirmPopup);
	
void VcpCMCCConfirmPopup::onInit()
{
    VcpConfirmPopup::onInit();
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_COMMAND_POPUP_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    //user add
    //checkbox
    VFX_OBJ_CREATE(m_imgButton, VcpImageButton, m_backgroundBottom);
    VcpStateImage imglist;
    if(m_imgState)
        imglist.setImage(VCP_IMG_LIST_MENU_CHECK_BOX_OFF,NULL,NULL,NULL);
    else
        imglist.setImage(VCP_IMG_LIST_MENU_CHECK_BOX_ON,NULL,NULL,NULL);
    m_imgButton->setImage(imglist);
    m_imgButton->setAnchor(0.5, 0.5);
    m_imgButton->setRect(VCP_CONFIRM_POPUP_BUTTON_X, VCP_CONFIRM_POPUP_BUTTON_Y, VCP_CONFIRM_POPUP_ICON_WIDTH, VCP_CONFIRM_POPUP_ICON_HEIGHT);
    m_imgButton->m_signalClicked.connect(this, &VcpCMCCConfirmPopup::onImgButtonClick);
    
    //text after checkbox
    VFX_OBJ_CREATE(m_text, VfxTextFrame, m_backgroundBottom);
    m_text->setRect(VCP_CONFIRM_POPUP_TEXT_X, VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_ICON_HEIGHT/2, VCP_CONFIRM_POPUP_TEXT_WIDTH, 20);
    m_text->setAnchor(0, 0.5);
    m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_REMIND));
    m_text->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
    m_text->setFont(fontDesc);
    m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);	
}

void VcpCMCCConfirmPopup::setCheckBoxPos()
{
	if(m_bottomRegionHeight != NULL && m_button[0] != NULL && m_button[1] != NULL)
	{
		m_button[0]->setInnerRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_ICON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP * 3, 
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                             ));
		m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_ICON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP * 3;
		m_button[1]->setInnerRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_ICON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP * 4, 
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                            ));
		m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT * 2 + VCP_CONFIRM_POPUP_BUTTON_GAP * 4+ VCP_CONFIRM_POPUP_ICON_HEIGHT + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;
	}
}

void VcpCMCCConfirmPopup::onImgButtonClick(VfxObject* sender, VfxId id)
{
    VcpStateImage imglist;
    m_imgState = !m_imgState;
    if(m_imgState)
    {
        imglist.setImage(VCP_IMG_LIST_MENU_CHECK_BOX_OFF,NULL,NULL,NULL);
    }
    else
    {
        imglist.setImage(VCP_IMG_LIST_MENU_CHECK_BOX_ON,NULL,NULL,NULL);
    }
    m_imgButton->setImage(imglist);
    if(sender == m_imgButton)
    {
        m_signalButtonClicked.postEmit(this,VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_0);
    }
}

void VcpCMCCConfirmPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    VFX_UNUSED(id);	
    if (m_buttonPressed)
    {
        return;
    }
    m_buttonPressed = VFX_TRUE;
    if (sender == m_button[0])
    {
        m_signalButtonClicked.postEmit(this,VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_1);
    }
    else if(sender == m_button[1])
    {
        m_signalButtonClicked.postEmit(this,VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_2);
    }
    leave(VFX_TRUE);
}


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWlanAuthListener);

/***************************************************************************** 
 * Class VappCmccWlanAutoAuth
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappCmccWlanAutoAuth", VappCmccWlanAutoAuth, VfxObject);

void VappCmccWlanAutoAuth::onInit()
{
    VfxObject::onInit();
    getDataFromFile(&m_cmccFileData);
}

void VappCmccWlanAutoAuth::onDeinit()
{
    VfxObject::onDeinit();
}

void VappCmccWlanAutoAuth::authLoginCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGIN_CALLBACK, ret, 500);
    
    if (s_cmccSettingData.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGIN)
    {		
        sendCallback(ret);
        VFX_OBJ_GET_INSTANCE(VappWlanAuthListener)->m_appStateChange.postEmit(ret);
        if (ret == VAPP_CMCC_WLAN_AUTH_OK || ret == VAPP_CMCC_WLAN_AUTH_NO_NEED_LOGIN)
        {
            s_cmccSettingData.need_logout = VFX_TRUE;
        }
        s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        srv_dtcnt_wlan_send_portal_login_stop_req((MMI_BOOL)(ret == VAPP_CMCC_WLAN_AUTH_OK || ret == VAPP_CMCC_WLAN_AUTH_NO_NEED_LOGIN));
    }
}

vapp_cmcc_wlan_auth_ret_enum VappCmccWlanAutoAuth::authLogin()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s_cmccSettingData.ui_activity != CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGIN, -1);
        sendCallback(VAPP_CMCC_WLAN_AUTH_BUSY);
        return VAPP_CMCC_WLAN_AUTH_BUSY;
    }
    s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_LOGIN;
    srv_dtcnt_wlan_send_portal_login_start_req(VappCmccWlanAuthHttp::getAbmId());
    ret = VappCmccWlanAuthHttp::httpLogin(authLoginCallback, getObjHandle());
    if(ret != VAPP_CMCC_WLAN_AUTH_WBLOCK)
    {
        sendCallback(ret);
        s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
    }
    return ret;
}

void VappCmccWlanAutoAuth::sendCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
    vapp_auth_ret_struct authRet;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGIN_CALLBACK, ret, 501);
    //callback
    if(s_cmccSettingData.cb != NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGIN_CALLBACK, ret, 502);
        s_cmccSettingData.cb(ret);
        s_cmccSettingData.cb = NULL; 
    }
    //send evt
    MMI_FRM_INIT_EVENT(&authRet, EVT_ID_VAPP_WLAN_CMCC_AUTH);
    authRet.ret = ret;
    MMI_FRM_CB_EMIT_EVENT(&authRet);
}

void VappCmccWlanAutoAuth::authLogoutCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGOUT_CALLBACK, ret, 500);
    if (s_cmccSettingData.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGOUT)
    {
        sendCallback(ret);
        VFX_OBJ_GET_INSTANCE(VappWlanAuthListener)->m_appStateChange.postEmit(ret);
        if (s_cmccSettingData.cb != NULL)
        {
            s_cmccSettingData.cb(ret);
            s_cmccSettingData.cb = NULL;
        }
        s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        srv_dtcnt_wlan_send_portal_logout_req();
    }
}

vapp_cmcc_wlan_auth_ret_enum VappCmccWlanAutoAuth::authLogout()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, 500);
    if (s_cmccSettingData.ui_activity != CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, -1);
        sendCallback(VAPP_CMCC_WLAN_AUTH_BUSY);
        return VAPP_CMCC_WLAN_AUTH_BUSY;
    }
    if (!s_cmccSettingData.need_logout)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, -2);
        sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
        return VAPP_CMCC_WLAN_AUTH_OK;
    }
    s_cmccSettingData.need_logout = VFX_FALSE;
    ret = VappCmccWlanAuthHttp::httpLogout(authLogoutCallback, NULL);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, ret);
    if (ret != VAPP_CMCC_WLAN_AUTH_WBLOCK)
    {	
        VFX_OBJ_GET_INSTANCE(VappWlanAuthListener)->m_appStateChange.postEmit(ret);
        sendCallback(ret);
        srv_dtcnt_wlan_send_portal_logout_req();
        return ret;
    }
    s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_LOGOUT;
    return ret;
}

void VappCmccWlanAutoAuth::authAbort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, s_cmccSettingData.ui_activity);
    if (s_cmccSettingData.ui_activity == CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, -1);
        return;
    }
    if (s_cmccSettingData.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, 1);
        s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        VappCmccWlanAuthHttp::httpAbort();
        srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
    }
    else //if (m_cmccSettingData.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGOUT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, 2);
        s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        VappCmccWlanAuthHttp::httpAbort();
        srv_dtcnt_wlan_send_portal_logout_req();
    }
    sendCallback(VAPP_CMCC_WLAN_AUTH_ABORTED);
    VFX_OBJ_GET_INSTANCE(VappWlanAuthListener)->m_appStateChange.postEmit(VAPP_CMCC_WLAN_AUTH_ABORTED);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, -100);
}

void VappCmccWlanAutoAuth::getDataFromFile(vappCmccWlanFileData *wlanCmccFileData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h = 0;
    WCHAR str[64];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    VAPP_CMCC_WLAN_MAKE_FILENAME(str);
    h = FS_Open(str, FS_READ_ONLY);
    if (h < 0)
    {
        memcpy(wlanCmccFileData, &initFileData, sizeof(vappCmccWlanFileData));
        return;
    }
    FS_Read(h, wlanCmccFileData, sizeof(vappCmccWlanFileData), NULL);
    FS_Close(h);
}

void VappCmccWlanAutoAuth::saveDataToFile(vappCmccWlanFileData *wlanCmccFileData)
{
    WCHAR str[64];
    FS_HANDLE h = 0;

    VAPP_CMCC_WLAN_MAKE_FILENAME(str);
    h = FS_Open(str, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (h < 0)
    {
        return;
    }
    FS_Write(h, wlanCmccFileData, sizeof(vappCmccWlanFileData), NULL);
    FS_Close(h);
}

/***************************************************************************** 
 * Class VappCmccWlanAutoAuthApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCmccWlanAutoAuthApp", VappCmccWlanAutoAuthApp, VfxApp);

void VappCmccWlanAutoAuthApp::onRun(void * args,VfxU32 argSize)
{	
    vapp_auth_close_page_struct closepageEvt;
    VFX_OBJ_CREATE(m_autoAuthObj, VappCmccWlanAutoAuth, this);
    vappCmccWlanFileData *m_fileData = m_autoAuthObj->getFileData();
    if(m_fileData->isDataSaved)
    {
        VFX_OBJ_CREATE_EX(m_scr, VappCmccWlanAutoAuthScr, this, (VFX_TRUE));
    }
    else
    {
        MMI_FRM_INIT_EVENT(&closepageEvt, EVT_ID_VAPP_WLAN_CMCC_CLOSE_PAGE);
        MMI_FRM_CB_EMIT_EVENT(&closepageEvt);
        VFX_OBJ_CREATE_EX(m_scr, VappCmccWlanAutoAuthScr, this, (VFX_FALSE));
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGIN, 100);
    }
    m_scr->show();
}

/***************************************************************************** 
 * Class VappCmccWlanAutoAuthScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCmccWlanAutoAuthScr", VappCmccWlanAutoAuthScr, VfxMainScr);

VappCmccWlanAutoAuthScr::VappCmccWlanAutoAuthScr(VfxBool flag) :
    m_isSmallScr(flag),
    m_login(VFX_TRUE),
    m_authflag(VFX_FALSE),
    m_autoAuthObj(NULL),
    m_confirmPopup(NULL),
    m_popup(NULL),
    m_dir(VFX_SCR_ROTATE_TYPE_NORMAL)
{
    memset(&m_fileData, 0, sizeof(vappCmccWlanFileData));
    if (m_isSmallScr || !VappCmccWlanAutoAuth::s_cmccSettingData.login_state)
    {
        setIsSmallScreen();
    }
}
	
void VappCmccWlanAutoAuthScr::onInit()
{
    VfxMainScr::onInit();
}

void VappCmccWlanAutoAuthScr::onDeinit()
{
    //tap home key in the authenticating 
    if(m_authflag)
    {
        VappCmccWlanAutoAuth::authAbort();
    }
    //avoid app re_enter
    if(m_login)
    {
        VappCmccWlanAutoAuth::sendCallback(VAPP_CMCC_WLAN_AUTH_ABORTED);
    }
    VfxMainScr::onDeinit();
}

void VappCmccWlanAutoAuthScr::onEnter(VfxBool isBackward)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_dir = renderer->getPreScreenRotateType();
}

void VappCmccWlanAutoAuthScr::onQueryRotateEx(VfxScreenRotateParam & param)
{
    param.rotateTo = m_dir;
}

void VappCmccWlanAutoAuthScr::on1stReady()
{
    VfxMainScr::on1stReady();
    VFX_OBJ_GET_INSTANCE(VappWlanAuthListener)->m_appStateChange.connect(this, &VappCmccWlanAutoAuthScr::closePopup);
    if(VappCmccWlanAutoAuth::s_cmccSettingData.login_state)
    {
        login();
    }
    else
    {
        logout();
    }
}

void VappCmccWlanAutoAuthScr::login()
{
    VappCmccWlanAutoAuthApp *app = (VappCmccWlanAutoAuthApp*)getParent();
    m_autoAuthObj = app->getAutoAuthObj();
    vappCmccWlanFileData *m_fileData = m_autoAuthObj->getFileData();
    if(m_fileData->isDataSaved)
    {
        setBgColor(VFX_COLOR_TRANSPARENT);
        if(m_fileData->isAutoNotify)
        {
            VFX_OBJ_CREATE_EX(m_confirmPopup, VcpCMCCConfirmPopup, this, (m_fileData->isAutoNotify));
	    m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_CONFIRM_AUTH));
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
	    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	    m_confirmPopup->setCustomButton(
			    VFX_WSTR_RES(STR_GLOBAL_CONNECT),
			    VFX_WSTR_RES(STR_GLOBAL_CANCEL),
			    VCP_POPUP_BUTTON_TYPE_WARNING,
			    VCP_POPUP_BUTTON_TYPE_CANCEL);
	    m_confirmPopup->setCheckBoxPos();
            m_confirmPopup->show(VFX_TRUE);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappCmccWlanAutoAuthScr::onConnectClick);
        }
        else
        {
            vapp_cmcc_wlan_auth_ret_enum ret = m_autoAuthObj->authLogin();
            m_login = VFX_FALSE;
            m_authflag = VFX_TRUE;
            if (VAPP_CMCC_WLAN_AUTH_WBLOCK == ret)
            {
                VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, this);
                m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
                m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_HTTP_LOGIN_LOADING));
                m_popup->setAutoDestory(VFX_FALSE);
                m_popup->m_signalButtonClicked.connect(this, &VappCmccWlanAutoAuthScr::onCancelClicked);
                m_popup->show(VFX_TRUE);
            }
            else
            {
                VappCmccWlanAutoAuth::s_cmccSettingData.cb = NULL;
                VappCmccWlanAutoAuth::s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
                srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
            }
        }
    }
    else
    {
        VappCmccWlanSettingPage *cmccWlanSettingPage;
        VFX_OBJ_CREATE_EX(cmccWlanSettingPage, VappCmccWlanSettingPage, this, (m_login));
        pushPage(0, cmccWlanSettingPage);
    }
}

void VappCmccWlanAutoAuthScr::logout()
{
    setBgColor(VFX_COLOR_TRANSPARENT);
    VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_DISCONNECTING));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->show(VFX_TRUE);
}

void VappCmccWlanAutoAuthScr::onCancelClicked(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if(id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        if(m_popup)
        {
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
        }
        VappCmccWlanAutoAuth::authAbort();
    }
    exit();
}

void VappCmccWlanAutoAuthScr::onConnectClick(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if(id == VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_0)
    {
        vappCmccWlanFileData *m_fileData = m_autoAuthObj->getFileData();
        if(m_fileData->isAutoNotify)
        {
            m_fileData->isAutoNotify = VFX_FALSE;
        }
        else
        {
            m_fileData->isAutoNotify = VFX_TRUE;
        }
        VappCmccWlanAutoAuth::saveDataToFile(m_fileData);
    }
    else if(id == VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_1)
    {
        vapp_cmcc_wlan_auth_ret_enum ret = m_autoAuthObj->authLogin();
        m_login = VFX_FALSE;
        m_authflag = VFX_TRUE;
        if (VAPP_CMCC_WLAN_AUTH_WBLOCK == ret)
        {
            VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, this);
            m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
            m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_HTTP_LOGIN_LOADING));
            m_popup->setAutoDestory(VFX_FALSE);
            m_popup->m_signalButtonClicked.connect(this, &VappCmccWlanAutoAuthScr::onCancelClicked);
            m_popup->show(VFX_TRUE);			
        }
        else
        {
            VappCmccWlanAutoAuth::s_cmccSettingData.cb = NULL;
            VappCmccWlanAutoAuth::s_cmccSettingData.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
            srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
        }
    }
    else
    {
        exit();
    }
}

void VappCmccWlanAutoAuthScr::closePopup(vapp_cmcc_wlan_auth_ret_enum ret) 
{
    m_authflag = VFX_FALSE;
    if(m_popup)
    {
        m_popup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_popup);
    }
    exit();
}

/***************************************************************************** 
 * Class VappCmccWlanSettingPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappCmccWlanSettingPage", VappCmccWlanSettingPage, VfxPage);

void VappCmccWlanSettingPage::onInit()
{
    VfxPage::onInit();
    
    VappCmccWlanAutoAuth::getDataFromFile(&m_wlanCmccData);
    
    VcpTitleBar *titleBar;
    VfxWString str;
    WCHAR wStr[VAPP_CMCC_WLAN_MAX_INPUT_LEN + 1];
    
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_AUTH_MAIN);
    titleBar->setTitle(str);
    setTopBar(titleBar);
    
    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    
    str.loadFromRes(STR_GLOBAL_SAVE);
    toolBar->addItem(CMCC_AUTH_SETTING_TOOLBAR_ID_SAVE, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    str.loadFromRes(STR_GLOBAL_CANCEL);
    toolBar->addItem(CMCC_AUTH_SETTING_TOOLBAR_ID_CANCEL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappCmccWlanSettingPage::onToolBarTapped);
    setBottomBar(toolBar);
    
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
	
    VcpFormItemBigButton *btn;
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_APPLY_PASSWORD);
    btn->setButtonText(str);
    btn->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnSubscribe);
    m_form->addItem(btn, CMCC_AUTH_ID_APLLY);
    
    VcpFormItemCaption *caption;
    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_ACCT_SETTING);
    caption->setText(str);
    caption->setStyle(VCPFORM_STYLE2);
    m_form->addItem(caption, CMCC_AUTH_ID_SETTING_CAPTION);
    
    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    str.loadFromRes(STR_GLOBAL_PREV);
    functionBar->addItem(ID_CMCC_FUNCTIONBAR_PREV, str);
    str.loadFromRes(STR_GLOBAL_NEXT);
    functionBar->addItem(ID_CMCC_FUNCTIONBAR_NEXT, str);
    str.loadFromRes(STR_GLOBAL_SAVE);
    functionBar->addItem(ID_CMCC_FUNCTIONBAR_SAVE, str);
    functionBar->setItemSpecial(ID_CMCC_FUNCTIONBAR_SAVE);
    functionBar->m_signalButtonTap.connect(this, &VappCmccWlanSettingPage::onFunctionBarTap);
    
    VcpFormItemTextInput *textInput;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    str.loadFromRes(STR_GLOBAL_USERNAME);
    textInput->setLabelText(str);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
    mmi_asc_to_wcs((WCHAR *)&wStr, (char *)m_wlanCmccData.username);
    textInput->getTextBox()->setText((VfxWChar *)&wStr, VAPP_CMCC_WLAN_MAX_INPUT_LEN);
    textInput->getTextBox()->setId(CMCC_AUTH_ID_USERNAME);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappCmccWlanSettingPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(textInput, CMCC_AUTH_ID_USERNAME);
    
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    str.loadFromRes(STR_GLOBAL_PASSWORD);
    textInput->setLabelText(str);
    mmi_asc_to_wcs((WCHAR *)&wStr, (char *)m_wlanCmccData.password);
    textInput->getTextBox()->setText((VfxWChar *)&wStr, VAPP_CMCC_WLAN_MAX_INPUT_LEN);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    textInput->getTextBox()->setId(CMCC_AUTH_ID_PASSWORD);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappCmccWlanSettingPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(textInput, CMCC_AUTH_ID_PASSWORD);

    if(m_wlanCmccData.isDataSaved)
    {
        VcpFormItemBigArrowButton *btnArrow;
        VFX_OBJ_CREATE(btnArrow, VcpFormItemBigArrowButton, m_form);
        str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_MODIFY_PASSWORD);
        btnArrow->setButtonText(str);
        btnArrow->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnModifyPasswd);
        m_form->addItem(btnArrow, CMCC_AUTH_ID_CHANGE);
        
        VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
        str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_RESET_PASSWORD);
        btn->setButtonText(str);
        btn->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnResetPasswd);
        m_form->addItem(btn, CMCC_AUTH_ID_RESET);
    }
    //other
    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_OTHERS);
    caption->setText(str);
    caption->setStyle(VCPFORM_STYLE2);
    m_form->addItem(caption, CMCC_AUTH_ID_OTHERS_CAPTION);
    
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_AUTO_AUTH);
    btn->setButtonText(str);
    
    str.loadFromRes(m_wlanCmccData.isAutoAuth ? STR_GLOBAL_ON : STR_GLOBAL_OFF);
    btn->setHintText(str);
    btn->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnAutoAuth);
    m_form->addItem(btn, CMCC_AUTH_ID_AUTO_AUTH);
    
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_NOTI_AUTH);
    btn->setButtonText(str);
    str.loadFromRes(m_wlanCmccData.isAutoNotify ? STR_GLOBAL_ON : STR_GLOBAL_OFF);
    btn->setHintText(str);
    btn->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnAutoNotify);
    m_form->addItem(btn, CMCC_AUTH_ID_PROMPT);
    
    VFX_OBJ_CREATE(btn, VcpFormItemBigButton, m_form);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_INSTALL_UPDATE);
    btn->setButtonText(str);
    btn->getButton()->m_signalClicked.connect(this, &VappCmccWlanSettingPage::onBtnUpdateInstall);
    m_form->addItem(btn, CMCC_AUTH_ID_UPDATE);
	
}

void VappCmccWlanSettingPage::onDeinit()
{
    if(fsCuiId > 0)
    {
	vcui_file_selector_close(fsCuiId);
    }
    VfxPage::onDeinit();
}


void VappCmccWlanSettingPage::onToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    )
{
    switch (id)
    {
        case CMCC_AUTH_SETTING_TOOLBAR_ID_SAVE:
            saveToFile();
            break;
        case CMCC_AUTH_SETTING_TOOLBAR_ID_CANCEL:
            getMainScr()->popPage();
            break;
        default:
            break;
    }
}

VfxBool VappCmccWlanSettingPage::checkInput()
{
    VfxWChar *str_wchr;
    VcpFormItemTextInput *textInput;
    VfxWString string;
    VfxBool errorFlag = VFX_FALSE;
    VfxBool focus = VFX_FALSE; // use to get the first error item
    VfxId focusItemId = CMCC_AUTH_ID_USERNAME;
    VfxBool emptyErrorUsername = VFX_FALSE;
    VfxBool emptyErrorPassword = VFX_FALSE;
    
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_USERNAME);
    str_wchr = textInput->getTextBox()->getText();
    //use vfx_wcslen
    if(mmi_wcslen((WCHAR*)str_wchr) == 0)
    {
        errorFlag = VFX_TRUE;
        emptyErrorUsername = VFX_TRUE;
        if(!focus)
        {
            focus = VFX_TRUE;
            focusItemId = CMCC_AUTH_ID_USERNAME;
        }
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    if(mmi_wcslen((WCHAR*)str_wchr) == 0)
    {
        errorFlag = VFX_TRUE;
        emptyErrorPassword = VFX_TRUE;
        if(!focus)
        {
            focus = VFX_TRUE;
            focusItemId = CMCC_AUTH_ID_PASSWORD;
        }
    }
    if (errorFlag)
    {
        if(emptyErrorPassword)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_PASSWORD);
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_EMPTY_PASSWORD);
            textInput->setWarningText(string);
        }
        if(emptyErrorUsername)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_USERNAME);
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_EMPTY_USERNAME);
            textInput->setWarningText(string);
        }
    }
    m_form->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);
    if(errorFlag)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappCmccWlanSettingPage::saveToFile()
{
    VfxWChar *str_wchr;
    VcpFormItemTextInput *textInput;
    VfxWString string;
	
    if(checkInput())
    {
        return;
    }
    srv_dtcnt_wlan_prefer_struct wlanSetting;
    srv_dtcnt_get_wlan_prefer_setting(&wlanSetting);
    wlanSetting.auto_portal_switch = 
        (m_wlanCmccData.isAutoAuth) ? 0 : 1;
    srv_dtcnt_set_wlan_prefer_setting(&wlanSetting);
    
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_USERNAME);
    str_wchr = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((char *)m_wlanCmccData.username, str_wchr);
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_AUTH_ID_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    mmi_wcs_to_asc((char *)m_wlanCmccData.password, str_wchr);
    m_wlanCmccData.isDataSaved = VFX_TRUE;
    VappCmccWlanAutoAuth::saveDataToFile(&m_wlanCmccData);
	
    if(m_login)
    {
        //exit();
        VappCmccWlanAutoAuthScr *scr = (VappCmccWlanAutoAuthScr *)getMainScr();
        scr->setLoginFlag(VFX_FALSE);
        VfxAppLauncher::terminate(getApp()->getGroupId());
        //vapp_dtcnt_wlan_auth_login(VappCmccWlanAutoAuth::s_cmccSettingData.cb);
        
        mmi_event_struct evt;
        
        MMI_FRM_INIT_EVENT(&evt, 0);
        mmi_frm_post_event(&evt, vapp_dtcnt_wlan_auth_launch, NULL);
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappCmccWlanSettingPage::onTextActivated(
    VcpTextEditor *sender,  // [IN] send object
    VfxBool  activated      // [IN] activate flag
)
{
    if (activated)
    {
        m_currActiveId = sender->getId();
        VcpFunctionBar *functionBar;
        functionBar = (VcpFunctionBar *)sender->getFunctionBar();
        if (m_currActiveId == CMCC_AUTH_ID_USERNAME)
        {
            functionBar->setDisableItem(ID_CMCC_FUNCTIONBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_CMCC_FUNCTIONBAR_NEXT, VFX_FALSE);
        } 
        else
        {
            functionBar->setDisableItem(ID_CMCC_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_CMCC_FUNCTIONBAR_NEXT, VFX_TRUE);
        }        
    }
}



void VappCmccWlanSettingPage::onFunctionBarTap(
    VfxObject *sender,  // [IN] sender object
    VfxId id            // [IN] Toolbar id
)
{
    VcpTextEditor *textEdit;
    VcpFormItemTextInput *textInput;
    switch (id)
    {
        case ID_CMCC_FUNCTIONBAR_PREV:
        {
            VfxId prevId = CMCC_AUTH_ID_USERNAME;
            switch (m_currActiveId)
            {
                case CMCC_AUTH_ID_USERNAME:
                    break;
                case CMCC_AUTH_ID_PASSWORD:
                    prevId = CMCC_AUTH_ID_USERNAME;
                    break;
            }  
            textInput = (VcpFormItemTextInput *)m_form->getItem(prevId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(prevId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
        
        case ID_CMCC_FUNCTIONBAR_NEXT:
        {
            VfxId nextId = CMCC_AUTH_ID_PASSWORD;
            switch (m_currActiveId)
            {
                case CMCC_AUTH_ID_USERNAME:
                    nextId = CMCC_AUTH_ID_PASSWORD;
                    break;
                case CMCC_AUTH_ID_PASSWORD:
                    break;
            } 
            textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(nextId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
		
        case ID_CMCC_FUNCTIONBAR_SAVE:
        {
            textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
            textInput->getTextBox()->deactivate();
            saveToFile();
            break;
        }
    }
}

void VappCmccWlanSettingPage::onBtnSubscribe(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VFX_OBJ_CREATE(m_applyConfirmPopup, VcpConfirmPopup, this);
    m_applyConfirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_applyConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_CONFIRM_SMS));
    m_applyConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    //applyConfirmPopup->setAutoDestory(VFX_TRUE);
    m_applyConfirmPopup->show(VFX_TRUE);
    m_applyConfirmPopup->m_signalButtonClicked.connect(this, &VappCmccWlanSettingPage::onSubscribeConfirm);
}

void VappCmccWlanSettingPage::onSubscribeConfirm(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        settingSendMsg(ID_CMCC_AUTH_MSG_TYPE_APPLY);
    }
    m_applyConfirmPopup = NULL;
}

void VappCmccWlanSettingPage::onBtnModifyPasswd(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VappCmccModifyPage *cmccModifyPage;
    VFX_OBJ_CREATE_EX(cmccModifyPage, VappCmccModifyPage, this, (&m_wlanCmccData));
    getMainScr()->pushPage(0, cmccModifyPage);
}

void VappCmccWlanSettingPage::onBtnResetPasswd(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VFX_OBJ_CREATE(m_resetConfirmPopup, VcpConfirmPopup, this);
    m_resetConfirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_resetConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_CONFIRM_SMS));
    m_resetConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    m_resetConfirmPopup->show(VFX_TRUE);
    m_resetConfirmPopup->m_signalButtonClicked.connect(this, &VappCmccWlanSettingPage::onResetConfirm);
}

void VappCmccWlanSettingPage::onResetConfirm(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        settingSendMsg(ID_CMCC_AUTH_MSG_TYPE_RESET);
    }
    m_resetConfirmPopup = NULL;
}


void VappCmccWlanSettingPage::onBtnAutoAuth(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_AUTO_AUTH);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    if(m_wlanCmccData.isAutoAuth)
    {
        str.loadFromRes(STR_GLOBAL_ON);
        selectPopup->addItem(1, str, VFX_TRUE);
        str.loadFromRes(STR_GLOBAL_OFF);
        selectPopup->addItem(0, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_GLOBAL_ON);
        selectPopup->addItem(1, str, VFX_FALSE);
        str.loadFromRes(STR_GLOBAL_OFF);
        selectPopup->addItem(0, str, VFX_TRUE);
    }
    selectPopup->m_signalPopupState.connect(this, &VappCmccWlanSettingPage::onSelectAutoAuth);
    selectPopup->show(VFX_FALSE);
}

void VappCmccWlanSettingPage::onSelectAutoAuth(
	VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
    )
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        if((i ? VFX_TRUE : VFX_FALSE) == m_wlanCmccData.isAutoAuth)
        {
            return;
        }
		
        VcpFormItemBigButton *btn;
        VfxWString str;
        btn =(VcpFormItemBigButton *)(m_form->getItem(CMCC_AUTH_ID_AUTO_AUTH));
		    if (i == 1)
        {
            m_wlanCmccData.isAutoAuth = VFX_TRUE;
            str.loadFromRes(STR_GLOBAL_ON);
            btn->setHintText(str);
        }
        else
        {
            m_wlanCmccData.isAutoAuth = VFX_FALSE;
            str.loadFromRes(STR_GLOBAL_OFF);
            btn->setHintText(str);
        }
        return;
    }
}

void VappCmccWlanSettingPage::onBtnAutoNotify(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    VcpSelectPopup *selectPopup;
    VFX_OBJ_CREATE(selectPopup, VcpSelectPopup, this);
    selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_NOTI_AUTH);
    selectPopup->setText(str);
    selectPopup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    if(m_wlanCmccData.isAutoNotify)
    {
        str.loadFromRes(STR_GLOBAL_ON);
        selectPopup->addItem(1, str, VFX_TRUE);
        str.loadFromRes(STR_GLOBAL_OFF);
        selectPopup->addItem(0, str, VFX_FALSE);
    }
    else
    {
        str.loadFromRes(STR_GLOBAL_ON);
        selectPopup->addItem(1, str, VFX_FALSE);
        str.loadFromRes(STR_GLOBAL_OFF);
        selectPopup->addItem(0, str, VFX_TRUE);
    }
    selectPopup->m_signalPopupState.connect(this, &VappCmccWlanSettingPage::onSelectAutoNotify);
    selectPopup->show(VFX_FALSE);
}

void VappCmccWlanSettingPage::onSelectAutoNotify(
    VfxBasePopup *sender,        // popup
    VfxBasePopupStateEnum state  // state
    )
{
    if(state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {        
        VcpSelectPopup *senderPopup;
        senderPopup = (VcpSelectPopup*)sender;
        VfxId i;
        i = senderPopup->getFirstSeletedId();
        if((i ? VFX_TRUE : VFX_FALSE) == m_wlanCmccData.isAutoNotify)
        {
            return;
        }
		
        VcpFormItemBigButton *btn;
        VfxWString str;
        btn =(VcpFormItemBigButton *)(m_form->getItem(CMCC_AUTH_ID_PROMPT));
        if (i == 1)
        {
            m_wlanCmccData.isAutoNotify = VFX_TRUE;
            str.loadFromRes(STR_GLOBAL_ON);
            btn->setHintText(str);
        }
        else
        {
            m_wlanCmccData.isAutoNotify = VFX_FALSE;
            str.loadFromRes(STR_GLOBAL_OFF);
            btn->setHintText(str);
            VcpConfirmPopup *confirmPopup = NULL;
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_AUTH_NOTIFY));
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
            /*VFX_OBJ_CREATE(m_warnningConfirmPopup, VcpConfirmPopup, this);
            m_warnningConfirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_warnningConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_AUTH_NOTIFY));
            m_warnningConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            m_warnningConfirmPopup->show(VFX_TRUE);
            m_warnningConfirmPopup->m_signalButtonClicked.connect(this, &VappCmccWlanSettingPage::onOkWarningConfirm);*/
        }
        return;
    }
}

void VappCmccWlanSettingPage::onOkWarningConfirm(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_OK)
    {
        m_warnningConfirmPopup->exit(VFX_TRUE);
    }
}

void VappCmccWlanSettingPage::settingMsgCallback(srv_sms_callback_struct* sms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcpConfirmPopup *confirmPopup;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!VappCmccWlanAutoAuth::s_cmccSettingData.sms_state)
    {
        return;
    }
    VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_FALSE;
    VappCmccWlanSettingPage *settingPage = (VappCmccWlanSettingPage *)VfxObject::handleToObject((VfxObjHandle)sms->user_data);
    if(settingPage)
    {		
        settingPage->m_popup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(settingPage->m_popup);
        if (sms->result)
        {
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, settingPage);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SEND_SMS_SUCC));
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, settingPage);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SEND_SMS_FAIL));
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
        }
    }
}

void VappCmccWlanSettingPage::settingSendMsg(msgType type)
{
    WCHAR sms_content[VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN + 1] = {0};
    WCHAR sms_num[VAPP_CMCC_WLAN_MAX_SMS_NUM_LEN + 1] = {0};
    VfxWString causeStr;
    
    if(ID_CMCC_AUTH_MSG_TYPE_APPLY == type)
    {
        mmi_asc_to_wcs((WCHAR*)sms_num, (char*)m_wlanCmccData.sms.num[0]);
        mmi_asc_to_wcs((WCHAR*)sms_content, (char*)m_wlanCmccData.sms.txt[0]);
    }
    else if(ID_CMCC_AUTH_MSG_TYPE_RESET == type)
    {
        mmi_asc_to_wcs((WCHAR*)sms_num, (char*)m_wlanCmccData.sms.num[2]);
        mmi_asc_to_wcs((WCHAR*)sms_content, (char*)m_wlanCmccData.sms.txt[2]);
    }
	
    if (VappCmccWlanAutoAuth::s_cmccSettingData.sms_state||
        !srv_sms_is_sms_ready() ||
        srv_sms_is_sms_busy() ||
        srv_sms_is_bg_send_action_busy())
    {
        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SMS_BUSY));
        confirmPopup->setAutoDestory(VFX_TRUE);
        confirmPopup->show(VFX_TRUE);
        return;
    }
	
    sms_handle = srv_sms_get_send_handle();
    if (NULL == sms_handle)
    {
        return;
    }
    srv_sms_set_address(sms_handle, (char *)sms_num);
    srv_sms_set_content(sms_handle, 
        (char *)sms_content, 
        kal_wstrlen(sms_content) * 2);
    VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_TRUE;
    VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SMS_SEND_LOADING));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->m_signalButtonClicked.connect(this, &VappCmccWlanSettingPage::onCancelClicked);
    m_popup->show(VFX_TRUE);
    srv_sms_send_msg(sms_handle, settingMsgCallback, getObjHandle());
}

void VappCmccWlanSettingPage::onCancelClicked(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if(id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        if(m_popup)
        {
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
        }
        srv_sms_abort_send(sms_handle);
        VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_FALSE;
    }
}

void VappCmccWlanSettingPage::onBtnUpdateInstall(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    FMGR_FILTER filter;
    U32 option_flag = VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |
                      VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN |
                      VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    fsCuiId = vcui_file_selector_create(
    		    getMainScr()->getGroupId(),
    		    VFX_WSTR("root"),
    		    &filter,
    		    VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
    		    option_flag);
    if(fsCuiId != GRP_ID_INVALID)
    {
        vfxSetCuiCallerScr(fsCuiId, getMainScr());
        vcui_file_selector_run(fsCuiId);
    }
}


mmi_ret VappCmccWlanSettingPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:  // evrnt from file manager
        {
            vcui_file_selector_result_event_struct *fmgrEvt;
            fmgrEvt = (vcui_file_selector_result_event_struct*)evt;
            VfxBool errorFlag = VFX_FALSE;
            VcpConfirmPopup *confirmPopup;
			
            if (fmgrEvt->result > 0)
            {
                srv_fmgr_fileinfo_struct info;
                memset(&info, 0, sizeof(info));
                VfxU32 buffSize = (SRV_FMGR_PATH_MAX_LEN+1) * sizeof(VfxWChar);
                WCHAR selectedFilePath[SRV_FMGR_PATH_MAX_LEN + 1];
                vcui_file_selector_get_selected_filepath(
                fsCuiId, &info, selectedFilePath, buffSize);
                if (info.size == 0)
                {
                    errorFlag = VFX_TRUE;
                }
                else
                {
                    if(!parseUpdateFile(selectedFilePath))
                    {
                        errorFlag = VFX_TRUE;
                    }
                } 
            }
            else
            {
                errorFlag = VFX_TRUE;
            }
            vcui_file_selector_close(fsCuiId);
            //show popup
            if(!errorFlag)
            {
                VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
                confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
                confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_HTTP_UPDATE_SUCC));
                confirmPopup->setAutoDestory(VFX_TRUE);
                confirmPopup->show(VFX_TRUE);
            }
            else
            {
                VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
                confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
                confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_HTTP_UPDATE_FAIL));
                confirmPopup->setAutoDestory(VFX_TRUE);
                confirmPopup->show(VFX_TRUE);
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

VfxBool VappCmccWlanSettingPage::parseUpdateFile(WCHAR *filename)
{
    FS_HANDLE h = 0;
    char buf[128];
    char line[VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN + 1];
    int i, j, ret, seq;
    U32 len;
    char c;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h = FS_Open(filename, FS_READ_ONLY);
    if (h < 0)
    {
        return VFX_FALSE;
    }

    seq = 0;
    i = j = 0;
    len = 0;
    ret = FS_Read(h, buf, 128, &len);
    while(ret >= 0 && len > 0 && seq < 6)
    {
        ASSERT(i < len);
        c = buf[i++];
        if (c == '\r')
        {
        }
        else if (c == '\n')
        {
            ASSERT(j <= VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN);
            line[j] = 0;
            saveUpdateItem(line, seq++);
			
            //save
            j = 0;
        }
        else
        {
            if (j < VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN)
            {
                line[j++] = c;
            }
        }

        if (i == len)
        {
            i = 0;
            len = 0;
            ret = FS_Read(h, buf, 128, &len);
        }
    }

    if (seq < 6)
    {
        ASSERT(j <= VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN);
        line[j] = 0;
        saveUpdateItem(line, seq++);
    }
    FS_Close(h);
    VappCmccWlanAutoAuth::saveDataToFile(&m_wlanCmccData);
    return VFX_TRUE;
}

void VappCmccWlanSettingPage::saveUpdateItem(char *str, int seq)
{
	
    if (seq> 6 || str[0] == 0)
    {
        return;
    }

    if (seq % 2 == 0)
    {
        if (!applib_is_valid_number((U8*) str))
        {
            return;
        }
        str[VAPP_CMCC_WLAN_MAX_SMS_NUM_LEN] = 0;
        strcpy(m_wlanCmccData.sms.num[seq / 2], str);
    }
    else
    {
        strcpy(m_wlanCmccData.sms.txt[seq / 2], str);
    }
    m_wlanCmccData.isDataUpdated = VFX_TRUE;
}


/***************************************************************************** 
 * Class VappCmccModifyPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappCmccModifyPage", VappCmccModifyPage, VfxPage);

void VappCmccModifyPage::onInit()
{
    VfxPage::onInit();
    
    VcpTitleBar *titleBar;
    VfxWString str;
    
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_AUTH_MAIN);
    titleBar->setTitle(str);
    setTopBar(titleBar);
    
    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    str.loadFromRes(STR_GLOBAL_OK);
    toolBar->addItem(CMCC_MODIFY_PASSWORD_TOOLBAR_ID_OK, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    str.loadFromRes(STR_GLOBAL_CANCEL);
    toolBar->addItem(CMCC_MODIFY_PASSWORD_TOOLBAR_ID_CANCEL, str, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappCmccModifyPage::onToolBarTapped);
    setBottomBar(toolBar);
	
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    str.loadFromRes(STR_GLOBAL_PREV);
    functionBar->addItem(ID_CMCC_MODIFY_FUNCTIONBAR_PREV, str);
    str.loadFromRes(STR_GLOBAL_NEXT);
    functionBar->addItem(ID_CMCC_MODIFY_FUNCTIONBAR_NEXT, str);
    str.loadFromRes(STR_GLOBAL_OK);
    functionBar->addItem(ID_CMCC_MODIFY_FUNCTIONBAR_OK, str);
    functionBar->setItemSpecial(ID_CMCC_MODIFY_FUNCTIONBAR_OK);
    functionBar->m_signalButtonTap.connect(this, &VappCmccModifyPage::onFunctionBarTap);
    
    VcpFormItemTextInput *textInput;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_OLD_PASSWORD);
    textInput->setLabelText(str);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    textInput->getTextBox()->setText(VFX_WSTR(""), VAPP_CMCC_WLAN_MAX_INPUT_LEN);
    textInput->getTextBox()->setId(CMCC_MODIFY_ID_OLD_PASSWORD);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappCmccModifyPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(textInput, CMCC_MODIFY_ID_OLD_PASSWORD);

    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_NEW_PASSWORD);
    textInput->setLabelText(str);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    textInput->getTextBox()->setText(VFX_WSTR(""), VAPP_CMCC_WLAN_MAX_INPUT_LEN);
    textInput->getTextBox()->setId(CMCC_MODIFY_ID_NEW_PASSWORD);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappCmccModifyPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(textInput, CMCC_MODIFY_ID_NEW_PASSWORD);

    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    str.loadFromRes(STR_ID_VAPP_WLAN_CMCC_NEW_PASSWORD2);
    textInput->setLabelText(str);
    textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    textInput->getTextBox()->setText(VFX_WSTR(""), VAPP_CMCC_WLAN_MAX_INPUT_LEN);
    textInput->getTextBox()->setId(CMCC_MODIFY_ID_NEW_PASSWORD2);
    textInput->getTextBox()->m_signalActivated.connect(this, &VappCmccModifyPage::onTextActivated);
    textInput->getTextBox()->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(textInput, CMCC_MODIFY_ID_NEW_PASSWORD2);
}

void VappCmccModifyPage::onDeinit()
{
    VfxPage::onDeinit();
}

void VappCmccModifyPage::onToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    )
{
    switch (id)
    {
        case CMCC_MODIFY_PASSWORD_TOOLBAR_ID_OK:
            onOKClicked();
            break;
        case CMCC_MODIFY_PASSWORD_TOOLBAR_ID_CANCEL:
            getMainScr()->popPage();
            break;
        default:
            break;
    }
}

void VappCmccModifyPage::onFunctionBarTap(
    VfxObject *sender,  // [IN] sender object
    VfxId id            // [IN] Toolbar id
)
{
    switch (id)
    {
        case ID_CMCC_MODIFY_FUNCTIONBAR_PREV:
        {
            VfxId prevId = CMCC_MODIFY_ID_OLD_PASSWORD;
            switch (m_currActiveId)
            {
                case CMCC_MODIFY_ID_NEW_PASSWORD:
                    prevId = CMCC_MODIFY_ID_OLD_PASSWORD;
                    break;
                case CMCC_MODIFY_ID_NEW_PASSWORD2:
                    prevId = CMCC_MODIFY_ID_NEW_PASSWORD;
                    break;
            }
            VcpTextEditor *textEdit;
            VcpFormItemTextInput *textInput;
            textInput = (VcpFormItemTextInput *)m_form->getItem(prevId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(prevId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
        
        case ID_CMCC_MODIFY_FUNCTIONBAR_NEXT:
        {
            VfxId nextId = CMCC_MODIFY_ID_NEW_PASSWORD2;
            switch (m_currActiveId)
            {
                case CMCC_MODIFY_ID_OLD_PASSWORD:
                    nextId = CMCC_MODIFY_ID_NEW_PASSWORD;
                    break;
                case CMCC_MODIFY_ID_NEW_PASSWORD:
                    nextId = CMCC_MODIFY_ID_NEW_PASSWORD2;
                    break;
            }
            VcpTextEditor *textEdit;
            VcpFormItemTextInput *textInput;
            textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
            textEdit = textInput->getTextBox();
            textEdit->activate();
            m_form->scrollItemToView(nextId, VCPFORM_SCROLL_BOTTOM, VFX_TRUE);
            break;
        }
		
        case ID_CMCC_MODIFY_FUNCTIONBAR_OK:
        {
           	onOKClicked();
            break;
        }
        default:
            break;
    }
}

void VappCmccModifyPage::onTextActivated(
    VcpTextEditor *sender,  // [IN] send object
    VfxBool  activated      // [IN] activate flag
)
{
    if (activated)
    {
        m_currActiveId = sender->getId();
        VcpFunctionBar *functionBar;
        functionBar = (VcpFunctionBar *)sender->getFunctionBar();
        if (m_currActiveId == CMCC_MODIFY_ID_OLD_PASSWORD)
        {
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_NEXT, VFX_FALSE);
        } 
        else if(m_currActiveId == CMCC_MODIFY_ID_NEW_PASSWORD)
        {
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_NEXT, VFX_FALSE);
        }
        else
        {
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_CMCC_MODIFY_FUNCTIONBAR_NEXT, VFX_TRUE);
        }
    }
}

VfxBool VappCmccModifyPage::checkPassword()
{
    VfxWChar *str_wchr;
    VfxWChar *str_wchr2;
    VcpFormItemTextInput *textInput;
    VfxWString string;
    U8 password[VAPP_CMCC_WLAN_MAX_INPUT_LEN + 1];;
    VfxBool errorFlag = VFX_FALSE;
    VfxBool focus = VFX_FALSE; // use to get the first error item
    VfxId focusItemId = CMCC_MODIFY_ID_OLD_PASSWORD;
    VfxBool emptyErrorOldPassword = VFX_FALSE;
    VfxBool emptyErrorNewPassword = VFX_FALSE;
    VfxBool emptyErrorNewPassword2 = VFX_FALSE;
	
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_OLD_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    if(mmi_wcslen((WCHAR*)str_wchr) == 0)
    {
        errorFlag = VFX_TRUE;
        emptyErrorOldPassword = VFX_TRUE;
        if(!focus)
        {
            focus = VFX_TRUE;
            focusItemId = CMCC_MODIFY_ID_OLD_PASSWORD;
        }
    }
    else
    {
        mmi_wcs_to_asc((char *)password, str_wchr);
        if(vfx_sys_strcmp((VfxChar*)password, (VfxChar*)m_wlanCmccDataPtr->password) != 0)
        {
            textInput->getTextBox()->setText(VFX_WSTR(""), VAPP_CMCC_WLAN_MAX_INPUT_LEN);
            errorFlag = VFX_TRUE;
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_CORRECT_OLD_PASSWORD);
            textInput->setWarningText(string);
            if(!focus)
            {
                focus = VFX_TRUE;
                focusItemId = CMCC_MODIFY_ID_OLD_PASSWORD;
            }
        }
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_NEW_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    if(mmi_wcslen((WCHAR*)str_wchr) == 0)
    {
        errorFlag = VFX_TRUE;
        emptyErrorNewPassword = VFX_TRUE;
        if(!focus)
        {
            focus = VFX_TRUE;
            focusItemId = CMCC_MODIFY_ID_NEW_PASSWORD;
        }
    }

    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_NEW_PASSWORD2);
    str_wchr2 = textInput->getTextBox()->getText();
    if(mmi_wcslen((WCHAR*)str_wchr2) == 0)
    {
        errorFlag = VFX_TRUE;
        emptyErrorNewPassword2 = VFX_TRUE;
        if(!focus)
        {
            focus = VFX_TRUE;
            focusItemId = CMCC_MODIFY_ID_NEW_PASSWORD2;
        }
    }
    else
    {
        if(mmi_wcscmp((WCHAR*)str_wchr, (WCHAR*)str_wchr) != 0)
        {
            textInput->getTextBox()->setText(VFX_WSTR(""), VAPP_CMCC_WLAN_MAX_INPUT_LEN);
            errorFlag = VFX_TRUE;
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_DIFFERENT_NEW_PASSWORD);
            textInput->setWarningText(string);
            if(!focus)
            {
                focus = VFX_TRUE;
                focusItemId = CMCC_MODIFY_ID_NEW_PASSWORD2;
            }
        }
    }
    if (errorFlag)
    {
        if(emptyErrorNewPassword2)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_NEW_PASSWORD2);
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_EMPTY_NEW2_PASSWORD);
            textInput->setWarningText(string);
        }
        if(emptyErrorNewPassword)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_NEW_PASSWORD);
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_EMPTY_NEW1_PASSWORD);
            textInput->setWarningText(string);
        }
        if(emptyErrorOldPassword)
        {
            textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_OLD_PASSWORD);
            string.loadFromRes(STR_ID_VAPP_WLAN_CMCC_EMPTY_OLD_PASSWORD);
            textInput->setWarningText(string);
        }
    }
    m_form->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);
    if(errorFlag)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappCmccModifyPage::modifyMsgCallback(srv_sms_callback_struct* sms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcpConfirmPopup *confirmPopup;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!VappCmccWlanAutoAuth::s_cmccSettingData.sms_state)
    {
        return;
    }
    VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_FALSE;
    VappCmccModifyPage *modifyPage = (VappCmccModifyPage *)VfxObject::handleToObject((VfxObjHandle)sms->user_data);
    if(modifyPage)
    {
        modifyPage->m_popup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(modifyPage->m_popup);
        if (sms->result)
        {
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, modifyPage);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SEND_SMS_SUCC));
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, modifyPage);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SEND_SMS_FAIL));
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
        }
    }
}

void VappCmccModifyPage::modifySendMsg()
{
    WCHAR sms_content[VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN + 1] = {0};
    WCHAR sms_num[VAPP_CMCC_WLAN_MAX_SMS_NUM_LEN + 1] = {0};
    VfxWString causeStr;
    VcpFormItemTextInput *textInput;
    VfxWChar *str_wchr;
    
    mmi_asc_to_wcs((WCHAR*)sms_num, (char*)m_wlanCmccDataPtr->sms.num[1]);
    mmi_asc_to_wcs((WCHAR*)sms_content, (char*)m_wlanCmccDataPtr->sms.txt[1]);
    mmi_wcscat((WCHAR*)sms_content, (WCHAR*)L" ");
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_OLD_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    mmi_wcscat((WCHAR*)sms_content, (WCHAR*)str_wchr);
    
    mmi_wcscat((WCHAR*)sms_content, (WCHAR*)L" ");
    
    textInput = (VcpFormItemTextInput *)m_form->getItem(CMCC_MODIFY_ID_NEW_PASSWORD);
    str_wchr = textInput->getTextBox()->getText();
    mmi_wcscat((WCHAR*)sms_content, (WCHAR*)str_wchr);
	
    if (VappCmccWlanAutoAuth::s_cmccSettingData.sms_state||
        !srv_sms_is_sms_ready() ||
        srv_sms_is_sms_busy() ||
        srv_sms_is_bg_send_action_busy())
    {
        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SMS_BUSY));
        confirmPopup->setAutoDestory(VFX_TRUE);
        confirmPopup->show(VFX_TRUE);
        return;
    }
	
    sms_handle = srv_sms_get_send_handle();
    if (sms_handle == NULL)
    {
        return;
    }
    srv_sms_set_address(sms_handle, (char*)sms_num);
    srv_sms_set_content(sms_handle, 
        (char *)sms_content, 
        kal_wstrlen(sms_content) * 2);
    VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_TRUE;
    VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_SMS_SEND_LOADING));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->m_signalButtonClicked.connect(this, &VappCmccModifyPage::onCancelClicked);
    m_popup->show(VFX_TRUE);
    srv_sms_send_msg(sms_handle, modifyMsgCallback, getObjHandle());
}

void VappCmccModifyPage::onCancelClicked(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if(id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        if(m_popup)
        {
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
        }
        srv_sms_abort_send(sms_handle);
        VappCmccWlanAutoAuth::s_cmccSettingData.sms_state = VFX_FALSE;
    }
}

void VappCmccModifyPage::onOKClicked()
{
    if(!checkPassword())
    {
        VFX_OBJ_CREATE(m_modifyConfirmPopup, VcpConfirmPopup, this);
        m_modifyConfirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_modifyConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CMCC_CONFIRM_SMS));
        m_modifyConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
        //modifyConfirmPopup->setAutoDestory(VFX_TRUE);
        m_modifyConfirmPopup->show(VFX_TRUE);
        m_modifyConfirmPopup->m_signalButtonClicked.connect(this, &VappCmccModifyPage::onModifyConfirm);
    }
}

void VappCmccModifyPage::onModifyConfirm(
    VfxObject* sender, //sender 
    VfxId id //
    )
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        modifySendMsg();
    }
    m_modifyConfirmPopup = NULL;
}

#endif
