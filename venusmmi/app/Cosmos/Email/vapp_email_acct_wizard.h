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
 *  Vapp_email_acct_wizard.h
 *
 * Project:
 * --------
 *  COSMOS Email Account Creation Wizard
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

#ifndef _VAPP_EMAIL_ACCT_WIZARD_H_
#define _VAPP_EMAIL_ACCT_WIZARD_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

extern "C" {
#include "EmailAppGprot.h"
#include "Vapp_email_core.h"
#include "EmailSrvGprot.h"
}

#include "vapp_email_mgr.h"
#include "vapp_email_prot.h"
#include "vapp_email_util.h"

class VappEmailAcctWizardPop: public VcpIndicatorPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};

class VappEmailAcctWizardScreen: public VfxMainScr
{
public:
    VappEmailAcctWizardScreen();
    virtual ~VappEmailAcctWizardScreen();
    virtual void on1stReady();    

    VfxU32 getAcctTemplateIndex(void) const;
    void setAcctTemplateIndex(VfxU32 index);

    EMAIL_ACCT_HANDLE getAcctHandle(void) const;
    void setAcctHandle(EMAIL_ACCT_HANDLE hd);

    VfxBool getNeedTestNetwork(void) const;
    void setNeedTestNetwork(VfxBool needTest);

public:
    mmi_email_acct_temp_struct *acctTemplate;
    srv_email_acct_info_struct currAcctInfo;

private:
    VfxU32 acctTemplateIndex;
};

class VappEmailAcctWizardTemplatePage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    VappEmailAcctWizardTemplatePage();
    virtual void onInit();    
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    void onTapped(VcpListMenu *menu, VfxU32 index);

    virtual VfxBool getItemText(
        VfxU32, VcpListMenuFieldEnum, VfxWString&, VcpListMenuTextColorEnum&);
    virtual VfxBool getItemImage(VfxU32, VcpListMenuFieldEnum, VfxImageSrc&);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
private:
    VcpListMenu *m_menu;
    VfxU32 selectedIndex;
    VfxU32 acctTemplateNum;
};

class VappEmailAcctWizardOthersBasicPage: public VfxPage
{
public:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onSubPageToolBarClick(VfxObject*, VfxId id, VfxS32);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);

private:
    VcpForm *form;
    VcpFormItemTextInput *addrTextInput;
    VcpFormItemTextInput *userTextInput;
    VcpFormItemTextInput *pswdTextInput;
    
    VcpFunctionBar *funcBar;
    VcpTextEditor *prevEditor;
    VcpTextEditor *nextEditor;
    VcpTextEditor *currEditor;

    VappEmailListSingleSelectTmplPage *protocolPage;
    
    enum formItemEnum
    {
        ADDR_USER_INFO_ENUM,
        ADDR_TEXTINPUT_ENUM,
        USER_NAME_TEXTINPUT_ENUM,
        PSWD_TEXTINPUT_ENUM,
        TOTAL_ITEMS
    };
};

class VappEmailStillSaveCfmPop: public VcpConfirmPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


class VappEmailAcctWizardFinishPage: public VfxPage
{
public:
    VappEmailAcctWizardFinishPage(){VFX_ASSERT(0);}
    explicit VappEmailAcctWizardFinishPage(VfxBool byTmpl);
    virtual ~VappEmailAcctWizardFinishPage();

    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void tmplOnInit();
    void othersOnInit();
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onFuncBarClick(VfxObject*, VfxId id);
    void onTextActivated(VcpTextEditor *sender, VfxBool activated);
    void onCfmChooseContinue(VfxObject *obj, VfxId id);

    VfxBool isNetworkValid();
    VfxBool isEditorDataValid();
    void saveEditorData();
    void fillAcctInfo();
    void setNeedTestNetWork(VfxBool need);
    void saveAndTest();
    void saveOnly();
    void saveAcct();
    void delCurrAcct();

    VfxBool matchTemplate();

    void saveAcctCancelProc(VfxObject*, VfxFloat);
    void testNetworkCancelProc(VfxObject*, VfxFloat);
    void testNetworkProc(
        EMAIL_ACCT_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void confirmChooseProc(VfxObject *obj, VfxId id);
    
    void closePrevMainScr();
    
    static void saveAcctProc(srv_email_result_enum res, void *userData);
    
private:
    VcpForm *form;
    VcpFormItemTextInput *incomingEditor;
    VcpFormItemTextInput *outgoingEditor;
    
    VcpFormItemTextInput *addrTextInput;
    VcpFormItemTextInput *pswdTextInput;
    
    VappEmailAcctWizardPop *indicatorPop;

    VcpFunctionBar *funcBar;
    VcpTextEditor *prevEditor;
    VcpTextEditor *nextEditor;
    VcpTextEditor *currEditor;
    
    VfxBool createByTemplate;
    EMAIL_ACCT_HANDLE acctHandle;
    VfxBool needTestNetwork;

    enum tmplFormItemEnum
    {
        ADDR_USER_INFO_ENUM,
        ADDR_TEXTINPUT_ENUM,
        PSWD_TEXTINPUT_ENUM,
        TMPL_TOTAL_ITEMS
    };
    
    enum othersFormItemEnum
    {
        INCOMING_EDITOR_ENUM,
        OUTGOING_EDITOR_ENUM,
        OTHER_TOTAL_ITEMS
    };    
};
#endif  // _VAPP_EMAIL_ACCT_WIZARD_H_

