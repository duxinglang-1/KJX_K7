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
 * Vapp_mre_app_operator.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MRE_APP_OPERATOR_H_
#define _MRE_APP_OPERATOR_H_
#ifdef __COSMOS_MMI_PACKAGE__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_app_manager.h"
#include "vcp_question_popup.h"
extern "C"
{
#include "vmappcomm.h"
#include "vmsys.h"
}
#ifdef _MRE_LOADING_POPUP_
#include "vcp_loading_popup.h"
#endif
/***************************************************************************** 
 * Defines
 *****************************************************************************/
#ifdef _AM_PRINT_TRACE_
#define VAPP_MRE_ENTER_INSTALL "[MRE][FTO AM]enter install app<app id = %d>"
#define VAPP_MRE_ENTER_LAUNCH "[MRE][FTO AM]enter launch app<app id = %d>"

#define VAPP_MRE_SET_APP_BEGIN "[MRE][FTO AM]VappMREOperator::setApp<begin><app Name = %s>"
#define VAPP_MRE_SET_APP_END "[MRE][FTO AM]VappMREOperator::setApp<end><app Path = %s>"
#define VAPP_MRE_SET_PATH_BEGIN "[MRE][FTO AM]VappMREOperator::setAppPath<begin><app Path = %s>"
#define VAPP_MRE_SET_PATH_END "[MRE][FTO AM]VappMREOperator::setAppPath<end><app Name = %s>"

#define VAPP_MRE_CHECK_UPDATE "[MRE][FTO AM]VappMREOperator::checkUpdateMRE<current time,year = %d,month = %d,day = %d>"
#define VAPP_MRE_LAST_UPDATE_TIME "[MRE][FTO AM]VappMREOperator::checkUpdateMRE<last update time,year = %d,month = %d,day = %d>"
#define VAPP_MRE_LAST_CANCEL_TIME "[MRE][FTO AM]VappMREOperator::checkUpdateMRE<last cancel time,year = %d,month = %d,day = %d>"

#define VAPP_MRE_LAUNCH_APP "[MRE][FTO AM]VappMREOperator::launchApp<app Path = %s>"
#define VAPP_MRE_ACTIVE_APP "[MRE][FTO AM]VappMREOperator::activeApp<app Path = %s>"
#define VAPP_MRE_INSTALL_APP "[MRE][FTO AM]VappMREOperator::installApp<app Path = %s>"
#define VAPP_MRE_INSTALL_SUCCESS "[MRE][FTO AM]VappMREOperator::installApp<app Name = %s>"

#define VAPP_MRE_UPDATE_MRE_CB "[MRE][FTO AM]VappMREOperator::updateMRECB<>"
#define VAPP_MRE_LAUNCH_APP_CB "[MRE][FTO AM]VappMREOperator::launchAppCB<result = %d>"

#define VAPP_MRE_MAINSCR_READY "[MRE][FTO AM]VappMREOperatorMainScr::on1stReady<operate type = %d>"
#define VAPP_MRE_MAINSCR_ONLAUNCHAPP "[MRE][FTO AM]VappMREOperatorMainScr::onLaunchApp<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONLAUNCHED "[MRE][FTO AM]VappMREOperatorMainScr::onLaunched<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONREPAIR "[MRE][FTO AM]VappMREOperatorMainScr::onRepair<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONDELETED "[MRE][FTO AM]VappMREOperatorMainScr::onDeletedApp<isvalid = %d>" 
#define VAPP_MRE_MAINSCR_ONUPDATEMRE "[MRE][FTO AM]VappMREOperatorMainScr::onUpdateMRE<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONUPDATED "[MRE][FTO AM]VappMREOperatorMainScr::onUpdated<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONINSTALL "[MRE][FTO AM]VappMREOperatorMainScr::onInstall<isvalid = %d>"
#define VAPP_MRE_MAINSCR_ONEXIT "[MRE][FTO AM]VappMREOperatorMainScr::onExit<isvalid = %d>"
#endif

/***************************************************************************** 
 * Classes
 *****************************************************************************/
class VappMREOperator :public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappMREOperator);
public:
    class VappTime
    {
    public:
        VfxU8   m_month;
        VfxU8   m_day;
    };
    enum
    {
        VAPP_MRE_LAUNCH_ERR,
        VAPP_MRE_LAUNCH_CB_ERR
    };
    VappMREOperator();
    
    void setApp(VfxChar* pAppName);
    void setAppPath(VfxWChar* pAppPath);

    VfxBool isInstalled();
    VfxBool isExist();
    VfxBool isUpdating();
    VfxBool isRunning();
    VfxBool checkUpdateMRE();
    VfxS32 updateMRE();
    void cancelUpdateMRE();
    void cancelNotify();

    VfxBool checkAppValid();
    VfxBool isOnCard();
    VfxS32 launchApp();  
    VfxS32 activeApp();
    VfxS32 installApp();
    VfxS32 installVso();
    void updateAppFile(void* data);
    
#ifdef _MRE_LOADING_POPUP_
    void getAppIcon(VfxImageSrc &img, VfxObject* alloc);
#endif    
    void release();
//    static VappMREOperator* getInstance();
    static void updateAppFileCB(VfxS32 result, VfxWChar* path, void* user_data);
public:
    VappInfo                m_appInfo;
    VfxWString              m_wstrAppPath;
    VfxSignal1<VfxS32>      m_launchedSignal;
    VfxSignal1<VfxS32>      m_updateMRESignal;
    VfxSignal1<VfxS32>      m_updateFileSignal;
           
private:
//    static void checkMREUpdateCB();
    static void updateMRECB(VfxS32 result);
    static void launchAppCB(VfxWChar* app_path, VfxS32 evt);
    
    static VfxS32  transErrorCode(VfxS32 err, VfxS32 errType = VAPP_MRE_LAUNCH_ERR);
#ifdef _AM_TEST_    
    void onTime(VfxTimer* pTimer);
    void onTime1(VfxTimer* pTimer);
#endif
private:
    VfxU8*        m_pImg;
    VfxBool       m_bLaunching;
    VappTime      m_lastUpdateTime;
    VappTime      m_lastCancelTime;//last cancel update time if today no cancel ,it will be set to 0   
    mmi_ret       m_result;
    mmi_app_package_name_struct m_appName;
    VfxBool       m_bRegister;
    
};


//************************************************************************************
// special popup, process back key
//************************************************************************************
class VappConfirmPopup : public VcpConfirmPopup
{
public:
    VappConfirmPopup();
    
    VfxS32  m_clickType;
    
protected:    
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onClicked(VfxObject* obj,  VfxId id);
    
    
};

class VappQuestionPopup : public VcpQuestionPopup
{
public:
    VappQuestionPopup();
    
    VfxS32  m_clickType;
    
protected:    
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onClicked(VfxObject* obj,  VfxId id);
    
    
};
//************************************************************************************
// Main Screen
//************************************************************************************
class VappMREOperatorMainScr : public VfxAppScr
{

public:    
    enum OPERATE_TYPE_ENUM
    {
        OPERATE_TYPE_INSTALL,
        OPERATE_TYPE_LAUNCH
    };
    VappInfo    m_appInfo;

    VappMREOperatorMainScr(VfxS32 type);
    void setOperateType(VfxS32 type);
    void on1stReady();
protected:
    virtual void onEnter(VfxBool isBackward);
    static mmi_ret cardPlugOutCB(mmi_event_struct *param);
       
    void install();
    void launch();
    void onLaunchApp();
    void onClickLaunchApp(VfxObject* pObj, VfxId id);
    void onClickInstallApp(VfxObject* pObj, VfxId id);
    void launchApp();
    void onLaunched(VfxS32 result);
    void onRepair(VfxObject* pObj, VfxId id);
    void onDeletedApp(VfxS32 bResult);
    void onUpdateMRE(VfxObject* pObj, VfxId id);
    void onCancelUpdateMRE(VfxObject* obj, VfxFloat f);
    void onUpdated(VfxS32 result);
    void onInstallLaunch();
    void onExit(VfxObject* pObj, VfxId id);
    void onCanceled(VfxObject* pObj, VfxFloat flt);

    void onInstallPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state);
    void onInstallFailPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state);
    void onUpdateFailPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state);
private:
    VfxBool                 m_bFirstIn;
    VfxBool                 m_bLaunched;
    VfxBool                 m_bValid;
    VfxS32                  m_operateType;//OPERATE_TYPE_ENUM
    VappQuestionPopup*      m_installPopup;
    VcpIndicatorPopup*      m_updateMREPopup;
#ifdef _MRE_LOADING_POPUP_    
    VcpLoadingPopup*        m_launchAppPopup;
#endif    
};

//************************************************************************************
// Launch App
//************************************************************************************
class VappMRELauncher : public VfxApp
{
    VFX_DECLARE_CLASS(VappMRELauncher);
public:
    virtual void onRun(void* args, VfxU32 argSize); 
   
private:
    virtual void onDeinit();
    VfxChar*    m_appName;
};

class VappMRELauncherEx : public VfxApp
{
    VFX_DECLARE_CLASS(VappMRELauncherEx);
public:
    virtual void onRun(void* args, VfxU32 argSize); 
   
private:
    virtual void onDeinit();
    VfxChar*    m_appName;
};
//************************************************************************************
// Install App
//************************************************************************************
class VappMREInstaller : public VfxApp
{
    VFX_DECLARE_CLASS(VappMREInstaller);
public:
    VappMREInstaller();
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
protected:
    
    friend class VappMREOperatorMainScr;
};

//************************************************************************************
// Update App
//************************************************************************************
class VappMREUpdater : public VfxApp
{
    VFX_DECLARE_CLASS(VappMREUpdater);
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();   
public:    
    void* m_update_data;
};

class VappMREUpdateMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappMREUpdateMainScr);
public:    
    VappMREUpdateMainScr();
protected:
    void onEnter(VfxBool isBackward);
    void on1stReady(); 
    void onQueried(VfxObject* obj, VfxId id);
    void onResult(VfxS32 result);
    void onExit(VfxObject* obj, VfxId id);
private:
    VfxBool m_bFirstIn;
    VcpIndicatorPopup* m_pWaitingPopup;
};

//************************************************************************************
// Install vso
//************************************************************************************
class VappMREVSOInstaller : public VfxApp
{
    VFX_DECLARE_CLASS(VappMREVSOInstaller);
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();   
public:    
    void* m_update_data;
};

class VappMREVSOInstallMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappMREVSOInstallMainScr);
public:    
    VappMREVSOInstallMainScr();
protected:
    void onEnter(VfxBool isBackward);
    static mmi_ret cardPlugOutCB(mmi_event_struct *param);
    
    void on1stReady(); 
    void onInstallPopupStateChanged(VfxBasePopup* pPopup, VfxBasePopupStateEnum state);
    void OnInstallFailed(VfxS32 result);
    void OnInstallSuccess();
    void onExit(VfxObject* obj, VfxId id);
private:
    VfxBool m_bFirstIn;
    VcpIndicatorPopup* m_pWaitingPopup;
};

#endif //__COSMOS_MMI_PACKAGE__
class VappMREShortcutInstall : public VfxApp
{
    VFX_DECLARE_CLASS(VappMREShortcutInstall);
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();   
public:    
    VfxChar* m_name;
};

class VappMREShortcutInstallMainScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappMREShortcutInstallMainScr);
public:    
    VappMREShortcutInstallMainScr();
    void ExitWaitingPopup();
    void ShowPopup();
protected:
    void onEnter(VfxBool isBackward);
    void on1stReady(); 
    void onQueried(VfxObject* obj, VfxId id);    
private:
    VfxBool m_bFirstIn;
    VcpIndicatorPopup* m_pWaitingPopup;
};
#endif //_MRE_APP_OPERATOR_H_
