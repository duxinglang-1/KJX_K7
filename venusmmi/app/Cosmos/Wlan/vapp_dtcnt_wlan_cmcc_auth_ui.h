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
 *  vapp_dtcnt_wlan_cmcc_auth_ui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_CMCC_AUTH_UI_H__
#define __VAPP_DTCNT_WLAN_CMCC_AUTH_UI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_OP01_WIFI__
#include "mmi_res_range_def.h"
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
extern "C"
{
#include "smssrvgprot.h"
}
#include "vapp_dtcnt_wlan_cmcc_auth_http.h"
#include "vapp_dtcnt_wlan_cmcc_auth_gprot.h"

///////////////////////////////////////////////////////////////////////////////

#define     VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_0     ('USR0')
#define     VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_1     ('USR1')
#define     VCP_CMCC_CONFIRM_POPUP_BUTTON_USER_2     ('USR2')

#define VAPP_CMCC_WLAN_MAX_INPUT_LEN    60
#define VAPP_CMCC_WLAN_MAX_SMS_NUM_LEN  21
#define VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN  60

#define VAPP_CMCC_WLAN_LOADING_TYPE_SMS    1
#define VAPP_CMCC_WLAN_LOADING_TYPE_LOGIN  2

extern const char* VAPP_CMCC_WLAN_SETTING_FILENAME;

#define VAPP_CMCC_WLAN_MAKE_FILENAME(str) \
    do{\
        kal_wsprintf(str,\
            "%c:\\%s",\
            (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM),\
            VAPP_CMCC_WLAN_SETTING_FILENAME);\
    }while(0)


enum
{
    CMCC_WLAN_UI_ACTIVITY_NULL = 0,
    CMCC_WLAN_UI_ACTIVITY_LOGIN,
    CMCC_WLAN_UI_ACTIVITY_LOGOUT,
};

enum msgType
{
    ID_CMCC_AUTH_MSG_TYPE_APPLY = 0,
    ID_CMCC_AUTH_MSG_TYPE_MODIFY,
    ID_CMCC_AUTH_MSG_TYPE_RESET,
    ID_CMCC_AUTH_MSG_TYPE_TOTAL
};

typedef struct
{
    char num[ID_CMCC_AUTH_MSG_TYPE_TOTAL][VAPP_CMCC_WLAN_MAX_SMS_NUM_LEN + 1];
    char txt[ID_CMCC_AUTH_MSG_TYPE_TOTAL][VAPP_CMCC_WLAN_MAX_SMS_TXT_LEN + 1];
}vappCmccWlanSms;

typedef struct
{
    VfxBool isAutoAuth;
    VfxBool isAutoNotify;
    VfxBool isDataSaved;
    VfxBool isDataUpdated;
    char username[VAPP_CMCC_WLAN_MAX_INPUT_LEN + 1];
    char password[VAPP_CMCC_WLAN_MAX_INPUT_LEN + 1];
    vappCmccWlanSms sms;
}vappCmccWlanFileData;

typedef struct
{
    VfxBool need_login;
    VfxBool need_logout;
    VfxBool sms_state; // false = NULL, true = SENDING
    VfxBool login_state;
    U32 ui_activity;
    vapp_dtcnt_wlan_auth_callback cb;
}vappCmccWlanSetting;

/*******************************************************************************
* Export API 
*******************************************************************************/

/***************************************************************************** 
 * Class VcpCMCCConfirmPopup
 *****************************************************************************/
/*
 * DESCRIPTION
 * 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VcpCMCCConfirmPopup : public VcpConfirmPopup
{
VFX_DECLARE_CLASS(VcpCMCCConfirmPopup);
    // Constructor / Destructor
public:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Constructor/Destructor>
    // Constructor block.
    VcpCMCCConfirmPopup() : m_imgState(VFX_TRUE),m_imgButton(NULL),m_text(NULL){}; 
    VcpCMCCConfirmPopup(VfxBool flag) : m_imgState(flag),m_imgButton(NULL),m_text(NULL){}; 
    // override
protected:
    virtual void onInit();
    // Implenmention
private:
    // <group DOM_ConfirmPopup_VcpConfirmPopup_Implementation>
    void onButtonClick(VfxObject* sender, VfxId id);
    void onImgButtonClick(VfxObject* sender, VfxId id);
public:
	void setCheckBoxPos();
protected:
    VfxBool m_imgState;
    VcpImageButton *m_imgButton;
    VfxTextFrame *m_text;
};


/***************************************************************************** 
 * Class VappWlanAuthListener
 *****************************************************************************/

class VappWlanAuthListener : public VfxObject
{
VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWlanAuthListener);
// Constructor / Destructor
public:
    VappWlanAuthListener() {}
    virtual ~VappWlanAuthListener() {}

public:
	VfxSignal1<vapp_cmcc_wlan_auth_ret_enum>  m_appStateChange;
};

/***************************************************************************** 
 * Class VappCmccWlanAutoAuth
 *****************************************************************************/
/*
 * DESCRIPTION
 * 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappCmccWlanAutoAuth : public VfxObject
{
VFX_DECLARE_CLASS(VappCmccWlanAutoAuth);
    // constructor / destructor
public:
    VappCmccWlanAutoAuth() : m_authHttp(NULL){}
    virtual ~VappCmccWlanAutoAuth() {}

    // override
public:
    virtual void onInit();
    virtual void onDeinit(); 
public:
    static void authLoginCallback(vapp_cmcc_wlan_auth_ret_enum ret);
    static void authLogoutCallback(vapp_cmcc_wlan_auth_ret_enum ret);
    static void sendCallback(vapp_cmcc_wlan_auth_ret_enum ret);
    static vapp_cmcc_wlan_auth_ret_enum authLogout();
    static void authAbort();
    static void getDataFromFile(vappCmccWlanFileData *wlanCmccFileData);
    static void saveDataToFile(vappCmccWlanFileData *wlanCmccFileData);
    vapp_cmcc_wlan_auth_ret_enum authLogin();
    vappCmccWlanFileData *getFileData(){return &m_cmccFileData;}
private:
    VappCmccWlanAuthHttp *m_authHttp;
    vappCmccWlanFileData m_cmccFileData;	
public: 
    static vappCmccWlanSetting s_cmccSettingData;
};

/***************************************************************************** 
 * Class VappCmccWlanAutoAuthScr
 *****************************************************************************/
/*
 * DESCRIPTION
 * 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappCmccWlanAutoAuthScr : public VfxMainScr
{
VFX_DECLARE_CLASS(VappCmccWlanAutoAuthScr);
// Override
public:
    VappCmccWlanAutoAuthScr(){};
    VappCmccWlanAutoAuthScr(VfxBool flag);
    virtual void on1stReady();
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
public:
    void setLoginFlag(VfxBool flag){ m_login = flag; }
protected:
    void onConnectClick(VfxObject* sender, VfxId id);
    void onCancelClicked(VfxObject* sender, VfxId id);
    void login();
    void logout();
    void closePopup(vapp_cmcc_wlan_auth_ret_enum ret);
private:
    VfxBool m_isSmallScr;
    VfxBool m_login; //avoid app re_enter
    VfxBool m_authflag; //tap home key in the authenticating 
    VappCmccWlanAutoAuth *m_autoAuthObj;
    VcpCMCCConfirmPopup *m_confirmPopup;
    VcpIndicatorPopup *m_popup;
    VfxScrRotateTypeEnum m_dir;
    vappCmccWlanFileData m_fileData;
};

/***************************************************************************** 
 * Class VappCmccWlanAutoAuthApp
 *****************************************************************************/
/*
 * DESCRIPTION
 * 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappCmccWlanAutoAuthApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCmccWlanAutoAuthApp);
public:
    VappCmccWlanAutoAuthApp() : 
    m_scr(NULL),
    m_autoAuthObj(NULL)
    {};
public:
    virtual void onRun(void* args, VfxU32 argSize);
    VappCmccWlanAutoAuth *getAutoAuthObj(){return m_autoAuthObj;}
    VappCmccWlanAutoAuthScr *getScreen(){return m_scr;}
private:
    VappCmccWlanAutoAuthScr *m_scr;
    VappCmccWlanAutoAuth *m_autoAuthObj;
};

/***************************************************************************** 
 * Class VappCmccWlanSettingPage
 *****************************************************************************/
/*
 * DESCRIPTION
 *  page for add/edit/view data account.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappCmccWlanSettingPage : public VfxPage
{
VFX_DECLARE_CLASS(VappCmccWlanSettingPage);
    
public:
    VappCmccWlanSettingPage() :
    m_login(VFX_FALSE),
    m_form(NULL),
    m_currActiveId(0),
    m_warnningConfirmPopup(NULL),
    m_resetConfirmPopup(NULL),
    m_applyConfirmPopup(NULL),
    m_popup(NULL),
    sms_handle(NULL),
    fsCuiId(0)
    {
        memset(&m_wlanCmccData, 0, sizeof(vappCmccWlanFileData));
    };
    VappCmccWlanSettingPage(VfxBool flag) :
    m_login(flag),
    m_form(NULL),
    m_currActiveId(0),
    m_warnningConfirmPopup(NULL),
    m_resetConfirmPopup(NULL),
    m_applyConfirmPopup(NULL),
    m_popup(NULL),
    sms_handle(NULL),
    fsCuiId(0)
    {
        memset(&m_wlanCmccData, 0, sizeof(vappCmccWlanFileData));
    };
    virtual ~VappCmccWlanSettingPage(){};
public:
    enum
    {
        CMCC_AUTH_SETTING_TOOLBAR_ID_SAVE,
        CMCC_AUTH_SETTING_TOOLBAR_ID_CANCEL
    } ;
    
    enum
    {
        CMCC_AUTH_ID_APLLY = 0,
        CMCC_AUTH_ID_SETTING_CAPTION,
        CMCC_AUTH_ID_USERNAME,
        CMCC_AUTH_ID_PASSWORD,
        CMCC_AUTH_ID_CHANGE,
        CMCC_AUTH_ID_RESET,
        CMCC_AUTH_ID_OTHERS_CAPTION,
        CMCC_AUTH_ID_AUTO_AUTH,
        CMCC_AUTH_ID_PROMPT,
        CMCC_AUTH_ID_UPDATE
    } ;
    
    enum
    {
        ID_CMCC_FUNCTIONBAR_PREV = 1,
        ID_CMCC_FUNCTIONBAR_NEXT,
        ID_CMCC_FUNCTIONBAR_SAVE
    } ;
    
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};
    
protected:
    void onToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    );
    VfxBool checkInput();
    void saveToFile();
    void onBtnSubscribe(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onSubscribeConfirm(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );
    void onBtnModifyPasswd(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onBtnResetPasswd(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onResetConfirm(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onBtnAutoAuth(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onSelectAutoAuth(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    );
    void onBtnAutoNotify(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onSelectAutoNotify(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    );
    void onOkWarningConfirm(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onCancelClicked(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    );
    void onBtnUpdateInstall(
        VfxObject* sender, //sender 
        VfxId id //
    );
    static void settingMsgCallback(srv_sms_callback_struct* sms);
    void settingSendMsg(msgType type);
    VfxBool parseUpdateFile(WCHAR *filename);
    void saveUpdateItem(char *str, int seq);
    
private:
    VfxBool m_login;
    VappCmccWlanAutoAuth *m_autoAuthObj;
    VcpForm *m_form;
    VfxId  m_currActiveId;
    vappCmccWlanFileData m_wlanCmccData;
    VcpConfirmPopup *m_warnningConfirmPopup;
    VcpConfirmPopup *m_resetConfirmPopup;
    VcpConfirmPopup *m_applyConfirmPopup;
    VcpIndicatorPopup *m_popup;
    SMS_HANDLE sms_handle;
    mmi_id fsCuiId;
};

/***************************************************************************** 
 * Class VappCmccModifyPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for add/edit/view data account.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappCmccModifyPage : public VfxPage
{
VFX_DECLARE_CLASS(VappCmccModifyPage);

public:
    VappCmccModifyPage(){};
    VappCmccModifyPage(vappCmccWlanFileData *wlanCmccData) :
    m_form(NULL),
    m_currActiveId(0),
    m_popup(NULL),
    m_modifyConfirmPopup(NULL),
    m_wlanCmccDataPtr(wlanCmccData),
    sms_handle(NULL)
    {};
    virtual ~VappCmccModifyPage(){};
    
public:
    enum
    {
        CMCC_MODIFY_PASSWORD_TOOLBAR_ID_OK,
        CMCC_MODIFY_PASSWORD_TOOLBAR_ID_CANCEL
    } ;

    enum
    {
        CMCC_MODIFY_ID_OLD_PASSWORD = 0,
        CMCC_MODIFY_ID_NEW_PASSWORD,
        CMCC_MODIFY_ID_NEW_PASSWORD2
    };
    enum
    {
        ID_CMCC_MODIFY_FUNCTIONBAR_PREV = 1,
        ID_CMCC_MODIFY_FUNCTIONBAR_NEXT,
        ID_CMCC_MODIFY_FUNCTIONBAR_OK
    } ;
	
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};
    
protected:
    void onToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    );
    void onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    );
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );
    void onModifyConfirm(
        VfxObject* sender, //sender 
        VfxId id //
    );
    void onCancelClicked(
        VfxObject* sender, //sender 
        VfxId id //
    );
    VfxBool checkPassword();
    static void modifyMsgCallback(srv_sms_callback_struct* sms);
    void modifySendMsg();    
    void onOKClicked();
private:
    VcpForm *m_form;
    VfxId m_currActiveId;
    VcpIndicatorPopup *m_popup;
    VcpConfirmPopup *m_modifyConfirmPopup;
    vappCmccWlanFileData *m_wlanCmccDataPtr;
    SMS_HANDLE sms_handle;
};
#endif
#endif /* __VAPP_DTCNT_WLAN_CMCC_AUTH_UI_H__ */
