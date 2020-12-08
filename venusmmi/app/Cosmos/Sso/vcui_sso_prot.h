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
 *  vcui_sso_prot.h
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
 *  
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

#ifndef __VCUI_SSO_PROT_H__
#define __VCUI_SSO_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_page.h"
#include "vcp_text_editor.h"
#include "vcp_button.h"
#include "vcp_form.h"
#include "vcui_sso_gprot.h"
#include "vcp_indicator_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#include "SsoSrvGprot.h"
#ifdef __cplusplus
}
#endif


typedef struct _vcui_sso_login_args
{   
    VfxU8 accountId;
    VfxU32 provider;
} vcui_sso_login_args;

class VcuiSsoLogin : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSsoLogin);    

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
};

#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
class VcuiSsoItemCell : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VcuiSsoItemCell);
    
public:
    VcuiSsoItemCell();
    VcuiSsoItemCell(VfxPage *page, VfxBool addAcc, VfxBool need_signup);
public:
    void disableLogin(VfxBool disable);
protected:
    virtual void onInit();
private:
    enum VCUI_SSO_CELL_LAYOUT{
    #if defined(__MMI_MAINLCD_480X800__)
        PAGE_WIDTH = 480,
        BUTTON_WIDTH = 221,
        BUTTON_HEIGHT = 70,
        BUTTON_GAP = 10,
        BUTTON_L_GAP = (PAGE_WIDTH - BUTTON_WIDTH*2 - BUTTON_GAP)/2,
        BUTTON_R_GAP = BUTTON_L_GAP,
    #elif defined(__MMI_MAINLCD_320X480__)
        PAGE_WIDTH = 320,
        BUTTON_WIDTH = 150,
        BUTTON_HEIGHT = 47,
        BUTTON_GAP = 4,
        BUTTON_L_GAP = (PAGE_WIDTH - BUTTON_WIDTH*2 - BUTTON_GAP)/2,
        BUTTON_R_GAP = BUTTON_L_GAP,
    #else
        PAGE_WIDTH = 240,
        BUTTON_WIDTH = 113,
        BUTTON_HEIGHT = 42,
        BUTTON_GAP = 4,
        BUTTON_L_GAP = (PAGE_WIDTH - BUTTON_WIDTH*2 - BUTTON_GAP)/2,
        BUTTON_R_GAP = BUTTON_L_GAP,
    #endif
    };
private:
    VfxBool   m_need_signup;
    VfxBool   m_addAcc;
    VfxPage   *m_parent;
    VcpButton *m_login;
    VcpButton *m_signup;
};

class VcuiSsoLoginPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcuiSsoLoginPage);

public:
    VcuiSsoLoginPage();
    VcuiSsoLoginPage(VfxU32 provider, VfxU8 accountId, VfxBool isSso = VFX_FALSE, VfxBool isCui = VFX_FALSE);
    VcuiSsoLoginPage(VfxU32 provider, VfxWChar *user, VfxBool isSso = VFX_FALSE,VfxBool isCui = VFX_FALSE);

public:
    enum VAPP_SSO_BUTTON_ID
    {
        ID_BUTTON_LOGIN = 1,
        ID_BUTTON_SIGNUP,

        ID_BUTTON_TOTAL
    };

    void onClicked(VfxObject* obj, VfxId id);
    void queryLoginInfo(VfxU32 *providerId, VfxU8 *accountId, VfxBool *isSso);
public:
    /* If you use CUI vcui_sso_login, you don't need to connect the signal.
       It prepare for using the page directly, can connect the signal to receive login result */
    VfxSignal3 <VfxPage*, vcui_sso_login_result_enum, VfxS32>m_signalLoginCb;
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onExit(VfxBool isBackward);

private:
    void notifyCaller(vcui_sso_login_result_enum result, VfxS32 err);
    void onFunctionBarTap(VfxObject *sender, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);
    void onTextChanged(VcpTextEditor *sender);
    static mmi_ret onLoginCb(mmi_event_struct *param);
    static void onSsoLoginCb(S32 reg_id, srv_sso_result result, U32 provider, U8 account, void *userdata);
    static void onDelAccCb(S32 reg_id, srv_sso_result result, void *userdata);
    void handleLoginCb(mmi_event_struct *param);
    void handleSsoLoginCb(srv_sso_result result, U32 provider, U8 account);
    void handleDelAccCb(srv_sso_result result);
    void login();
    void doLogin(VfxWString account, VfxWString password);
    void showProcessingPop(VfxWString str);
    void onCancelProcessing(VfxObject *obj, VfxFloat processing);
    static mmi_ret Listener(mmi_event_struct* evt);
    void handleListener(mmi_event_struct* evt);
private:
    /* Layout */
    enum {
        PAGE_WIDTH = 480,
        PAGE_HEIGHT = 800,
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        LOGO_WIDTH = 0,
        LOGO_HEIGHT = 0,
        LOGO_L_GAP = 0,
        LOGO_T_GAP = 0,
        LOGO_X = 0,
        LOGO_Y = 0,
        LOGO_EDITOR_GAP = 10,
#endif
        ACC_WIDTH = 300,
        ACC_HEIGHT = 40,
        ACC_L_GAP = (PAGE_WIDTH-ACC_WIDTH)/2,
        ACC_X = ACC_L_GAP,
        ACC_Y = (LOGO_Y+LOGO_HEIGHT+LOGO_EDITOR_GAP),
        ACC_FONT_SIZE = 30,
        ACC_PW_GAP = 5,

        PW_WIDTH = 300,
        PW_HEIGHT = 40,
        PW_L_GAP = ACC_L_GAP,
        PW_X = PW_L_GAP,
        PW_Y = (ACC_Y+ACC_HEIGHT+ACC_PW_GAP),
        PW_FONT_SIZE = 30,
        PW_BUTTON_GAP = 45,

        FORM_WIDTH = PAGE_WIDTH,
        FORM_HEIGHT = VCPFRM_STD_UI_CNTRL_HEIGHT*2,

        BUTTON_WIDTH = 145,
        BUTTON_HEIGHT = 38,
        BUTTON_L_GAP = ACC_L_GAP,
        BUTTON_R_GAP = ACC_L_GAP,
        BUTTON_GAP = 10,
        LOGIN_X = BUTTON_L_GAP,
        SIGNUP_X = (LOGIN_X+BUTTON_WIDTH+BUTTON_GAP),
        BUTTON_Y = (PW_Y+PW_HEIGHT+PW_BUTTON_GAP),
    };
private:
    #define SSO_PW_MASK_STR VfxWString().format("********")
    
    enum VAPP_SSO_FUNC_BAR_ID
    {
        ID_FUNC_BAR_PREV = 1,
        ID_FUNC_BAR_NEXT,
        ID_FUNC_BAR_LOGIN,

        ID_FUNC_BAR_TOTAL
    };
    
    enum VAPP_SSO_EDITOR_ID
    {
        ID_ACCOUNT = 1,
        ID_PASSWORD,
        ID_CELL,

        ID_TOTAL
    };
private:
    VfxU8         m_accountId;
    VfxBool       m_ignoreCB;
    VfxBool       m_addAcc;
    VfxBool       m_isSso;
    VfxBool       m_isCui;
    VfxU32        m_provider;
    VfxS32        m_reqId;
    VcpForm       *m_form;
    VfxImageFrame *m_logo;
    VcpFormItemTextInput *m_account;
    VcpFormItemTextInput *m_password;
    VcuiSsoItemCell *m_cell;
    VcpButton     *m_login;
    VcpButton     *m_signup;
    VfxWeakPtr<VcpIndicatorPopup> m_processing;
    VfxChar       *m_oldAccName;
    VfxChar       *m_user;
};
#endif
#endif /* __VCUI_SSO_PROT_H__ */
