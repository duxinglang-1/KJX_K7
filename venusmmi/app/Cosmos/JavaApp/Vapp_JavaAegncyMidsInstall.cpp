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
 *  vapp_javaagencysrc.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Java install
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
#ifdef __J2ME__
#include "MMI_features.h" 
#include "vapp_JavaAgencySrc.h"
#include "mmi_rp_vapp_java_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "MMI_include.h"
#include "vapp_java_adp.h"
#include "vapp_java_srv.h"
#include "Vapp_JavaAgencyMidsInstall.h"

 extern "C"
{
#include "AppMgrSrvprot.h"
#include "JavaAppFactorySrvGprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern VappJavaHelper vappjavaHelper;
/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappJavaMidInstallconfirm",VappJavaMidInstallconfirm,VcpCommandPopup);
VfxBool VappJavaMidInstallconfirm::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK ||
            event.keyCode == VFX_KEY_CODE_HOME ||
            event.keyCode == VFX_KEY_CODE_POWER)
        {
                m_signalButtonClicked.postEmit(this, m_button[1]->getId());
                m_buttonPressed = VFX_TRUE;
        }
    }
    return VfxBasePopup::onKeyInput(event);
}

VFX_IMPLEMENT_CLASS("VappJavaMidInstallAuthInputPopup",VappJavaMidInstallAuthInputPopup,VcpInputPopup);
VfxBool VappJavaMidInstallAuthInputPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK ||
            event.keyCode == VFX_KEY_CODE_HOME ||
            event.keyCode == VFX_KEY_CODE_POWER)
        {
            m_signalButtonClicked.postEmit(this, VCP_INPUT_POPUP_BTN_CANCEL);
        }
    }
    return VfxBasePopup::onKeyInput(event);
}
VFX_IMPLEMENT_CLASS("VappJavaMidInstallProgress",VappJavaMidInstallProgress,VcpIndicatorPopup);
VfxBool VappJavaMidInstallProgress::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK ||
            event.keyCode == VFX_KEY_CODE_HOME ||
            event.keyCode == VFX_KEY_CODE_POWER )
        {
                if((m_popupType == VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON) ||
                    (m_popupType == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
                {
                    leave(VFX_TRUE);
                }
                mmi_java_mids_install_abort();
                vfxPostInvoke0(&vappjavaHelper,&VappJavaHelper::closeJavaApp);
        }
    }
    return VfxBasePopup::onKeyInput(event);
}
#ifndef J2ME_SLIM_MEMORY_SUPPORT
VFX_IMPLEMENT_CLASS("VappJavaMidStopScreen", VappJavaMidStopScreen, VfxAppScr);

void VappJavaMidStopScreen::showTerminating()
{
    VcpIndicatorPopup *indacatorppPopup;
    VFX_OBJ_CREATE(indacatorppPopup,VcpIndicatorPopup,this);
    indacatorppPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    indacatorppPopup->setText(STR_ID_VAPP_JAVA_VM_TERMINATING);
    indacatorppPopup->setAutoDestory(VFX_FALSE);
    indacatorppPopup->show(VFX_TRUE);
}
void VappJavaMidStopScreen::showStopConfirmDialog()
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_TERMINATE_CONFRIM_DIALOG);
    VFX_OBJ_CREATE(confirmPopup, VappJavaMidInstallconfirm, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setText(STR_JAVA_NCENTER_TERMINATE_JAVA_GAME);
    confirmPopup->setCustomButton(STR_GLOBAL_YES, 
                                         STR_GLOBAL_CANCEL,
                                         VCP_POPUP_BUTTON_TYPE_WARNING,
                                         VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappJavaMidStopScreen::stopConfirm); 
}
void VappJavaMidStopScreen::stopConfirm(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        if(jam_mvm_get_vm_state(g_mmi_java_install_terminate_vm_id) == JVM_TERMINATING_STATE||    
        jam_mvm_get_vm_state(g_mmi_java_install_terminate_vm_id) == JVM_TERMINATE_STATE)
        {
            kal_trace(TRACE_STATE, FUNC_JVM_ENTER_TERMINATE_MODE_TERMINATING);
            return;
        } 
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_TERMINATE_CONFRIM_HANDLER,0);
        mmi_java_mids_install_ask_terminate_cb(MMI_TRUE);
        vfxPostInvoke0(this,&VappJavaMidStopScreen::showTerminating);
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_TERMINATE_CONFRIM_HANDLER,1);
        mmi_java_mids_install_ask_terminate_cb(MMI_FALSE);
    }
}

void VappJavaMidStopScreen::onInit()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
    VfxAppScr::onInit();
    this->setBgColor(VFX_COLOR_TRANSPARENT);
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);
    statusBar->setPos(0, 0);
    show();
}
void VappJavaMidStopScreen::onEnter(VfxBool isBackward)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
}
void VappJavaMidStopScreen::onSnapshotEnter()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
}


void VappJavaMidStopScreen::onBack()
{
    mmi_java_mids_install_ask_terminate_cb(MMI_FALSE);
}
void VappJavaMidStopScreen::onRotate(const VfxScreenRotateParam &param)
{
    VfxAppScr::onRotate(param);
    statusBar->setSize(getSize().width,statusBar->getSize().height);
}
void VappJavaMidStopScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = rotateType;
}
#endif


VFX_IMPLEMENT_CLASS("VappJavaMidInstallScreen", VappJavaMidInstallScreen, VfxAppScr);
void VappJavaMidInstallScreen::onRotate(const VfxScreenRotateParam &param)
{
    VfxAppScr::onRotate(param);
    statusBar->setSize(getSize().width,statusBar->getSize().height);
}
void VappJavaMidInstallScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = rotateType;
}

void VappJavaMidInstallScreen::JavaInstallStart()
{
    VFX_OBJ_CREATE(progressBar,VappJavaMidInstallProgress,this);
    progressBar->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON );
    progressBar->setText(STR_JAVA_START_INSTALLING);
    progressBar->setMaxProgress(1.0);
    progressBar->setAutoDestory(VFX_FALSE);
    progressBar->setProgress((VfxFloat)(g_mmi_java_install_progress /100.0));
    progressBar->show(VFX_TRUE);
    progressBar->m_signalCanceled.connect(this, &VappJavaMidInstallScreen::onCanceled);
    mmi_java_mids_install_request_start();
}

void VappJavaMidInstallScreen::setDisplayStyle()
{
    this->setBgColor(VFX_COLOR_TRANSPARENT);
}

void VappJavaMidInstallScreen::onCanceled(VfxObject* obj, VfxFloat id)
{
    mmi_java_mids_install_abort();
    vfxPostInvoke0(&vappjavaHelper,&VappJavaHelper::closeJavaApp);
}


void VappJavaMidInstallScreen::updateProgress(VfxFloat progress_value)
{
    if(progressBar!= NULL && progressBar->isValid())   
        progressBar->show(VFX_TRUE);
    else
        return;
    progressBar->setProgress(progress_value);
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_UPDATE_PROJESS,progress_value);
}


void VappJavaMidInstallScreen::showAuthDialog()
{
    VFX_OBJ_CREATE(authInputPopup, VappJavaMidInstallAuthInputPopup, this);
    authInputPopup->setGroupNum(2);
    authInputPopup->setTitle(STR_GLOBAL_AUTHENTICATION);
    authInputPopup->setHintText(STR_GLOBAL_USERNAME, 0);
    authInputPopup->setHintText(STR_GLOBAL_PASSWORD, 1);
    VcpTextEditor *passwordEditor = authInputPopup->getInputbox(1);
    passwordEditor->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, IME_DISABLE_NEW_LINE_SYMBOL);
    authInputPopup->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::onAuthInputBtnClicked);
    authInputPopup->setAutoDestory(VFX_FALSE);
    authInputPopup->show(VFX_TRUE);
}
void VappJavaMidInstallScreen::onAuthInputBtnClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    switch(id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
            kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_AUTH_TOOLBAR_HANDLER,0);            
            #ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__  
            mmi_java_send_get_auth_res((U8*)authInputPopup->getText(0).getBuf(), (U8 * )authInputPopup->getText(1).getBuf());
            #endif 
            if(authInputPopup)
            {
                VFX_OBJ_CLOSE(authInputPopup);
                authInputPopup = NULL;
            }
            break;
        case VCP_INPUT_POPUP_BTN_CANCEL:
           kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_AUTH_TOOLBAR_HANDLER,1);
           mmi_java_mids_install_abort();
           if(authInputPopup)
           {
                VFX_OBJ_CLOSE(authInputPopup);
                authInputPopup = NULL;
           }
           break;
        default:
            kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_AUTH_TOOLBAR_HANDLER,2);
            break;
        }
}

void VappJavaMidInstallScreen::rmsConfirm(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_RMS_CONFIRM_HANDLER,0);
        mmi_java_send_reset_rms_res(KAL_TRUE);
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_RMS_CONFIRM_HANDLER,1);
        mmi_java_send_reset_rms_res(KAL_FALSE);
    }

}

void VappJavaMidInstallScreen::rmsConfirmDialog()
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_RMS_CONFIRM_DIALOG);
    VFX_OBJ_CREATE(confirmPopup, VappJavaMidInstallconfirm, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setText(STR_ID_VAPP_JAVA_RESET_RMS_ASK);
    confirmPopup->setCustomButton(STR_GLOBAL_YES, 
                                         STR_GLOBAL_NO,
                                         VCP_POPUP_BUTTON_TYPE_NORMAL,
                                         VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::rmsConfirm); 
}

void VappJavaMidInstallScreen::installConfirm(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_INSTALL_CONFRIM_HANDLER,0);
        mmi_java_send_mids_install_confirm_res(MMI_TRUE);
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_INSTALL_CONFRIM_HANDLER,1);
        mmi_java_send_mids_install_confirm_res(MMI_FALSE);                                    
    }
}

void VappJavaMidInstallScreen::showConfirmDialog(VfxU16 * str)
{
    VFX_OBJ_CREATE(confirmPopup, VappJavaMidInstallconfirm, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirmPopup->setText(VFX_WSTR_DYNAMIC(str));
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setCustomButton(STR_GLOBAL_INSTALL, 
                                         STR_GLOBAL_CANCEL,
                                         VCP_POPUP_BUTTON_TYPE_NORMAL,
                                         VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::installConfirm); 
}
void VappJavaMidInstallScreen::showPushInstallDialog()
{
    #ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
    U16* str = mmi_java_get_push_install_confirm_string();
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_PUSH_INSTALL_DIALOG);
    VFX_OBJ_CREATE(confirmPopup, VappJavaMidInstallconfirm, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setText(str);
    confirmPopup->setCustomButton(STR_GLOBAL_YES, 
                                         STR_GLOBAL_CANCEL,
                                         VCP_POPUP_BUTTON_TYPE_NORMAL,
                                         VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    is_pushinstall_confirm = VFX_TRUE;
    confirmPopup->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::pushInstallConfirm);
    free_ctrl_buffer(str);
    #endif
}
void VappJavaMidInstallScreen::pushInstallConfirm(VfxObject *obj, VfxId id)
{
#ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_PUSH_INSTALL_HANDLER,0);
        mmi_java_set_push_install_info();
        vfxPostInvoke0(&vappjavaHelper,&VappJavaHelper::reEntryInstall);
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_PUSH_INSTALL_HANDLER,1);
        mmi_java_discard_current_push_install_req();
        vapp_java_close_venus_screen();
    }
    is_pushinstall_confirm = VFX_FALSE;
#endif	
}

void VappJavaMidInstallScreen::showDMInstallDialog()
{
    #ifdef __DM_SCOMO_SUPPORT__
    U16 title = 0; 
    U16 confirm_str = 0;    
    mmi_java_dmui_scomo_get_title_and_confirm_str(&title, &confirm_str);
    VFX_OBJ_CREATE(confirmPopup, VappJavaMidInstallconfirm, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setText(confirm_str);
    confirmPopup->setCustomButton(STR_GLOBAL_YES, 
                                         STR_GLOBAL_CANCEL,
                                         VCP_POPUP_BUTTON_TYPE_WARNING,
                                         VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::dmInstallConfirm); 
    #endif /*_DM_SCOMO_SUPPORT__*/
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_DM_INSTALL_DIALOG);
}

void VappJavaMidInstallScreen::dmInstallConfirm(VfxObject *obj, VfxId id)
{
#ifdef __DM_SCOMO_SUPPORT__
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_DM_INSTALL_HANDLER,0);
        vfxPostInvoke0(this,&VappJavaMidInstallScreen::JavaInstallStart);
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_DM_INSTALL_HANDLER,1);
        vapp_java_close_venus_screen();
    }
#endif /*_DM_SCOMO_SUPPORT__*/
}

void VappJavaMidInstallScreen::onInit()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
    VfxAppScr::onInit();
    setDisplayStyle();
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);
    statusBar->setPos(0, 0);
    show();
}
void VappJavaMidInstallScreen::onEnter(VfxBool isBackward)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
}
void VappJavaMidInstallScreen::onSnapshotEnter()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    rotateType = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(rotateType);
}

void VappJavaMidInstallScreen::onDeinit()
{
    if(is_need_abort)
    {
        mmi_java_mids_install_abort();
    }
}

void VappJavaMidInstallScreen::onBack()
{
    mmi_java_mids_install_abort();
}

void VappJavaMidInstallScreen:: setNeedAbortInstall(VfxBool abort)
{
    is_need_abort = abort;
}

void VappJavaMidInstallScreen::selectInstallDrv()
{
    setBgColor(VFX_COLOR_TRANSPARENT);
    VFX_OBJ_CREATE(option, VappJavaMidInstallconfirm, this);
    option->setInfoType(VCP_POPUP_TYPE_QUESTION);
    option->setText(STR_GLOBAL_SELECT);
    option->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    option->setCustomButton(STR_GLOBAL_PHONE, 
                                         STR_GLOBAL_MEMORY_CARD,
                                         VCP_POPUP_BUTTON_TYPE_NORMAL,
                                         VCP_POPUP_BUTTON_TYPE_NORMAL);
    option->setAutoDestory(VFX_FALSE);
    option->show(VFX_TRUE);
    option->m_signalButtonClicked.connect(this, &VappJavaMidInstallScreen::onInstallSelectDrvClick);
}


void VappJavaMidInstallScreen::onInstallSelectDrvClick(VfxObject *obj, VfxId id)
{
    S8 drv;
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        drv =(S8)SRV_FMGR_PHONE_DRV;
        mmi_java_send_get_install_drv_res(drv);
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        drv =(S8)SRV_FMGR_CARD_DRV;
        mmi_java_send_get_install_drv_res(drv);
    }
    else
    {
        mmi_java_mids_install_abort();
    }
}
void VappJavaMidInstallScreen::onProcessClose(void)
{
#ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
    if(is_pushinstall_confirm)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_INSTALL_ON_PROCESS_CLOSE,0); 
        mmi_java_discard_current_push_install_req();
    }
#endif
}

#endif
