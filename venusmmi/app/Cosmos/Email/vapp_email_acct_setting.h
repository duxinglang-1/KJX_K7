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
 *  Vapp_email_acct.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Single Account Setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_EMAIL_ACCT_SETTING_H_
#define _VAPP_EMAIL_ACCT_SETTING_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

extern "C" {
#include "EmailSrvGprot.h"
#include "EmailAppGprot.h"
#include "Vapp_email_core.h"
#include "cbmsrvgprot.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "FileMgrSrvGprot.h"
}

#include "vapp_email_prot.h"
#include "vapp_email_util.h"
#include "vapp_email_acct.h"
#include "vapp_email_mgr.h"

class VappEmailAcctSettingScreen: public VfxMainScr
{
// Override
public:
    VappEmailAcctSettingScreen(){VFX_ASSERT(0);}
    explicit VappEmailAcctSettingScreen(EMAIL_ACCT_ID acct_id);
    virtual ~VappEmailAcctSettingScreen();

    virtual void on1stReady();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    
public:
    srv_email_result_enum show(void);
    VappEmailAcct *getCurrAcct(void) const;

private:
    EMAIL_ACCT_ID acctId;
    VappEmailAcct *acctInfo;
};

class VappEmailTmplAcctSettingPage: public VfxPage
{   
public:
    VcpFunctionBar *funcBar;

    VappEmailTmplAcctSettingPage():funcBar(NULL){}
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    VappEmailAcctSettingScreen *getMainScr() const;
};

class VappEmailAcctNormalSettingPage: public VappEmailTmplAcctSettingPage
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct * evt);

private:
    void onConfirmClick(VfxObject*, VfxId);
    void onToolBarClick(VfxObject*, VfxId);
    void onFuncBarClick(VfxObject*, VfxId);
    void onFormCellClick(VcpFormItemCell*, VfxId);
    void onSwitchClick(VcpFormItemSwitchCell*, VfxId, VfxBool);
    void onSingleSelectSave(VfxObject*, VfxS32);
    void onSimpleInputSave(VfxObject*, const VfxWString&);
    void onTextActivated(VcpTextEditor*, VfxBool);
    void onSimAvailableChanged(VfxBool simAvailable);
    
private:
    VfxU8 appId;    
    mmi_id cuiId;
    VcpForm *form;
    VcpFormItemTextInput *addr;
    VcpFormItemTextInput *acctName;
    VcpFormItemTextInput *dispName;
    VcpFormItemTextInput *userName;
    VcpFormItemTextInput *pswd;
    VcpFormItemLauncherCell *downloadOption;
    VcpFormItemLauncherCell *checkInterval;
    VcpFormItemSwitchCell *saveSentEmail;
    VcpFormItemLauncherCell *defaultDataAcct;

    VcpTextEditor *prevEditor;
    VcpTextEditor *nextEditor;
    VcpTextEditor *currEditor;

    VappEmailListSingleSelectTmplPage *downloadOpt;
    VappEmailListSingleSelectTmplPage *chkInterval;
    VappEmailSimpleInputTmplPage *dlSizePage;
    
    enum VappEmailAcctNormalSettingFormItemEnum
    {
        FORM_ITEM_USER_INFO = 0,
        FORM_ITEM_ADDR,
        FORM_ITEM_ACCT_NAME,
        FORM_ITEM_DISP_NAME,
        FORM_ITEM_LOG_IN_INFO,
        FORM_ITEM_USER_NAME,
        FORM_ITEM_PSWD,
        FORM_ITEM_ACCT_INFO,
        FORM_ITEM_DATA_ACCT,
        FORM_ITEM_DOWNLOAD_OPT,
        FORM_ITEM_CHECK_INTERVAL,
        FORM_ITEM_SAVE_SENT_EMAIL,
    };
};

class VappEmailAcctAdvSettingMainPage: public VappEmailTmplAcctSettingPage
{
public:
    virtual void onInit();

private:
    void onFormCellClick(VcpFormItemCell *obj, VfxId id);

private:
    enum VappEmailAcctAdvSettingMainPageFormItem
    {
        FORM_ITEM_ACCT_SETTING = 0,
        FORM_ITEM_OUTGOING,
        FORM_ITEM_INCOMING,
        FORM_ITEM_SIGNATURE,
    };
};

class VappEmailAcctAdvSettingAcctPage: public VappEmailTmplAcctSettingPage
{
public:
    VappEmailAcctAdvSettingAcctPage(){}
    virtual void onInit();

private:
    void onSwitchClick(VcpFormItemSwitchCell*, VfxId id, VfxBool switch_on);
    void onSimpleInputSave(VfxObject* obj, const VfxWString& text);
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);

private:
    VcpFormItemTextInput *retriveAmount;
    VcpFormItemTextInput *replyTo;
    
    VappEmailSimpleInputTmplPage *retriveAmountPage;
    VappEmailSimpleInputTmplPage *replyToPage;
    VcpFormItemTextInput *downloadSize;

    VcpTextEditor *prevEditor;
    VcpTextEditor *nextEditor;
    VcpTextEditor *currEditor;
    
    enum VappEmailAcctAdvSettingAcctPageFormItem
    {
        FORM_ITEM_NOTIFICATION = 0,
        FORM_ITEM_PROTOCOL,
        FORM_ITEM_RETRIVE_AMOUNT,
        FORM_ITEM_DOWNLOAD_SIZE,
        FORM_ITEM_REPLY_TO
    };
};

class VappEmailAcctAdvSettingServerPage: public VappEmailTmplAcctSettingPage
{
public:
    enum VappEmailServerTypeEnum
    {
        EMAIL_OUTGOING_SERVER = 0,
        EMAIL_INCOMING_SERVER
    };

    VappEmailAcctAdvSettingServerPage(VappEmailServerTypeEnum serverType)
        : m_serverType(serverType)
    {
    };

    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

private:
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onFormCellClick(VcpFormItemCell *obj, VfxId id);
    void onSingleSelectSave(VfxObject *obj, VfxS32 select_index);
    void onSwitchClick(VcpFormItemSwitchCell*, VfxId, VfxBool);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);

private:    
    VcpFormItemTextInput *m_server;
    VcpFormItemTextInput *m_port;
    VcpFormItemLauncherCell *m_security;
    VappEmailListSingleSelectTmplPage *m_secModePage;
    VappEmailServerTypeEnum m_serverType;    

    VcpTextEditor *m_prevEditor;
    VcpTextEditor *m_nextEditor;
    VcpTextEditor *m_currEditor;
    
    enum VappEmailAcctAdvSettingServerPageFormItem
    {
        FORM_ITEM_SERVER = 0,
        FORM_ITEM_PORT,
        FORM_ITEM_SERCURITY,
        FORM_ITEM_AUTHENTICATION, //For outgoing server
        FORM_ITEM_APOP_SEC,       //For incoming server
        FORM_ITEM_REMOTE_FLDR     //For incoming server
    };
};

class VappEmailAcctAdvSettingOutAuthPage: public VappEmailTmplAcctSettingPage
{
public:
    virtual void onInit();

private:
    void onSwitchClick(VcpFormItemSwitchCell*, VfxId, VfxBool);
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);

private:
    enum VappEmailAcctAdvSettingOutAuthPageFormItem
    {
        FORM_ITEM_OUTGOING_AUTH_SWITCH = 0,
        FORM_ITEM_OUTGOING_AUTH_CAP,
        FORM_ITEM_OUTGOING_USERNAME,
        FORM_ITEM_OUTGOING_PSWD,
    };
    
    VcpTextEditor *prevEditor;
    VcpTextEditor *nextEditor;
    VcpTextEditor *currEditor;

    VcpFormItemSwitchCell *auth_switch;
    VcpFormItemTextInput *username;
    VcpFormItemTextInput *pswd;
};

class VappEmailAcctAdvSettingSignaturePage: public VappEmailTmplAcctSettingPage
{
public:
    VappEmailAcctAdvSettingSignaturePage();
    virtual void onInit();
    virtual mmi_ret onProc(mmi_event_struct * evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void addSigImgBtn(void);
    void onBtnClick(VfxObject *obj, VfxId id);
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onSwitchCellClick(VcpFormItemSwitchCell*, VfxId id, VfxBool switch_on);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);
    void onTcardPlug(VfxBool in);

private:
    static void signatureEditDone(VfxS32 editRes, void *userData);

private:
    VcpForm *form;
    VcpButton *sigImgBtn;
    VcpToolBar *m_toolBar;
    VcpCancelButton *removeBtn;
    VcpFormItemSwitchCell *autoSig;
    VcpTextEditor *sigTextTextEditor;
    mmi_email_sig_struct m_signature;
    VcpIndicatorPopup *indicator_pop;
    VcpFormItemCustomFrame *sig_img;
    
    VfxBool insertEnable;

    mmi_id fsCuiId;
    mmi_id imgViewCuiId;
    
    WCHAR sigFilePath[SRV_FMGR_PATH_MAX_LEN + 1];
    VfxBool pathChanged;
    enum VappEmailAcctAdvSettingSignaturePageFormItem
    {
        FORM_ITEM_SIGNATURE_SWITCH = 0,
        FORM_ITEM_SIGNATURE_CAP,
        FORM_ITEM_SIGNATURE_TEXT,
        FORM_ITEM_SIGNATURE_IMG,
    };
};

class VappEmailAcctAdvSettingRmtFldrPage
    : public VappEmailTmplAcctSettingPage, public IVcpListMenuContentProvider
{
public:        
    VappEmailAcctAdvSettingRmtFldrPage();
    virtual ~VappEmailAcctAdvSettingRmtFldrPage();

    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getItemImage(
        VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    virtual VfxBool getItemIsHighlightable(VfxU32 index) const;

private:
    void onPopPressBack(VfxObject* o, VfxId id);
    void onPopCanceled(VfxObject*, VfxFloat);
    void onPopErrorClick(VfxObject*, VfxId);
    void onCmdBtnClicked(VcpListMenu *sender, VfxU32 index);
    void onRmtFldrReady(EMAIL_ACCT_ID acctId, 
                               VappEmailNwkDoneEnum nwkDoneType,
                               VappEmailResStruct res);
    void onRmtFldrEvt(VappEmailNwkStateEnum,
                             VfxU32,
                             VappEmailNwkProcEnum status);

public:    
    static const VfxU32 SUPPORTED_RMT_FLDR_MAX_NUM = 20;

private:
    EMAIL_REQ_ID reqId;
    EMAIL_ACCT_ID acctId;
    EMAIL_ACCT_HANDLE acctHandle;
    VfxU32 remoteFldrTotal;
    VfxBool dataReady;
    VfxBool isSubscribed[SUPPORTED_RMT_FLDR_MAX_NUM];

    VcpListMenu *m_menu;
    VcpIndicatorPopup *indicator_pop;
};

#endif  // _VAPP_EMAIL_ACCT_SETTING_H_
