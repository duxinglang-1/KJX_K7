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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * Vapp_email_main.h
 *
 * Project:
 * --------
 * 
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
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __VAPP_EMAIL_MAIN_H__
#define __VAPP_EMAIL_MAIN_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"


#include "vapp_email_prot.h"
#include "vapp_email_composer.h"
#include "Vapp_Email_mgr.h"


extern "C"
{
#include "emailsrvgprot.h"
} /* extern "C" */


enum EmailAcctListPageTBEnum
{
    EMAIL_ACCT_LIST_PAGE_TB_NEW_MSG,
    EMAIL_ACCT_LIST_PAGE_TB_REFRESH,
    EMAIL_ACCT_LIST_PAGE_TB_SETTING,
    EMAIL_ACCT_LIST_PAGE_TB_TOTAL
};


enum EmailPageTypeEnum
{
    EMAIL_PAGE_TYPE_BASE,
    EMAIL_PAGE_TYPE_ACCT_LISG,
    EMAIL_PAGE_TYPE_MSG_LIST,
    EMAIL_PAGE_TYPE_MSG_VIEW,
    EMAIL_PAGE_TYPE_REMOTE_FOLDER_LIST,
    EMAIL_PAGE_TYPE_USE_DETAILS,
    EMAIL_PAGE_TYPE_ATTACH_LIST,
    EMAIL_PAGE_TYPE_RECIPIENT_LIST,
    EMAIL_PAGE_TYPE_TOTAL
};


enum EmailMainFirstPageEnum
{
    EMAIL_MAIN_FIRST_PAGE_ACCT_LIST,
    EMAIL_MAIN_FIRST_PAGE_MSG_LIST,
    EMAIL_MAIN_FIRST_PAGE_MSG_VIEW,
    EMAIL_MAIN_FIRST_PAGE_TOTAL
};

typedef struct
{
    VfxBool needLaunch;
    WCHAR *subj;
    WCHAR *cont;
    WCHAR toAddr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    WCHAR toName[SRV_EMAIL_MAX_DISP_NAME_LEN + 1];
    WCHAR attchPath[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    VfxBool deleleAttch;
    VfxBool usePopToShowErr;
} vapp_email_composer_launch;


enum EmailEntryPointEnum
{
    EMAIL_ENTRY_FROM_MAIN_MENU,
    EMAIL_ENTRY_FROM_NCENTER,
    EMAIL_ENTRY_FROM_COMPOSER,
    EMAIL_ENTRY_FROM_OTHER_APP,
    EMAIL_ENTRY_TOTAL
};

typedef struct
{
    EmailMainFirstPageEnum first_page_type;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_MSG_ID msg_id;
    srv_email_fldr_type_enum fldr_type;
    VfxBool show_switch_btn;
    EmailEntryPointEnum entry_point;

    vapp_email_composer_launch lauch_comp;
} email_app_set_first_struct;


typedef struct
{
    S32 err_no;
    U16 str_id;
} email_app_err_struct;

extern const email_app_err_struct email_err_tbl[22];

class VappEmailApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappEmailApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    void deinitMem();
    static void *memAlloc(U32 size);
    static void memFree(void *ptr);
	
protected:
	using VfxApp::onProcessClose;

private:
    void *m_memPoolPtr;
    static KAL_ADM_ID m_admMemPtr;
};


class VappEmailAcctListMenuProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    virtual void setMenu(VcpListMenu*);
    virtual VfxBool getItemText(VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);    
    virtual VfxBool getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &);
    virtual void closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32) const;
    virtual VfxBool swapItem(VfxU32, VfxU32);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32, VfxFrame *);
    virtual void closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *);
    virtual VfxBool getItemTextFrameFormat(VfxU32, VcpListMenuFieldEnum, VfxTextFrame *);

private:
    VcpListMenu *m_listMenu;

private:
    VfxBool getAcctDisplayInfo(VfxU32, VfxWString &);
};


class VappEmailAcctListPage : public VfxPage
{
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    void onTBClick(VfxObject *, VfxId);
    void onItemClick(VcpListMenu *, VfxU32);
    void onCreateAcctConfirmBtnClick(VfxObject *, VfxId);
    void onMsgNumberChange(EMAIL_ACCT_ID, VfxU32, VfxU32);
    void onAcctNwkDone(EMAIL_ACCT_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void onAcctStateChange(EMAIL_ACCT_ID, VappEmailAcctStateEnum);
    void on2ndEnter();  //Enter page after SSE

    EMAIL_ACCT_ID getAcctID(VfxU32 index)
    {
        return m_acctIDList[index];
    };
    EMAIL_ACCT_ID getFldrID(VfxU32 index)
    {
        return m_folderIDList[index];
    };
    void getNextAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID);
    void getPrevAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID);
    void setCurrFldr(EMAIL_FLDR_ID fldrID)
    {
        m_folderIDList[m_currItemIndex] = fldrID;
    };
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
    void switchStorage(VfxObject *, VfxId);
    void onPreSwitchStorage();
    void onPostSwitchStorage(VappEmailResEnum);
    void storageSwitchDone(VappEmailResEnum);
#endif    
    void showLoading()
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_LOADING, __LINE__);
        if (m_loadingPopup == NULL)
        {
            VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, this);
            m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            VfxWString text;
            text.loadFromRes(STR_GLOBAL_LOADING);
            m_loadingPopup->setText(text);
            m_loadingPopup->setAutoDestory(VFX_FALSE);
            m_loadingPopup->show(VFX_TRUE);
        }
    };
    void closeLoading()
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_CLOSE_LOADING, __LINE__);
        if (m_loadingPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_loadingPopup);
            m_loadingPopup = NULL;
        }
    };
    void enterPage(VfxBool);
    void initIDs(VfxBool resetAll);    // get all inbox id or not

private:
    enum VappEmailAcctListPageTBEnum
    {
        ACCT_LIST_PAGE_TOOLBAR_NEW_MAIL,
        ACCT_LIST_PAGE_TOOLBAR_REFRESH,
        ACCT_LIST_PAGE_TOOLBAR_EMAIL_SETTING,
        ACCT_LIST_PAGE_TOOLBAR_TOTAL
    };
    EMAIL_ACCT_ID m_acctIDList[MMI_EMAIL_MAX_ACCTS];
    EMAIL_FLDR_ID m_folderIDList[MMI_EMAIL_MAX_ACCTS];
    VfxU32 m_currItemIndex;
    VappEmailAcctListMenuProvider *m_listProvider;
    VcpListMenu *m_listMenu;
    VcpToolBar *m_toolbar;
    VcpIndicatorPopup *m_loadingPopup;
    VcpConfirmPopup *m_confirmPopup;
    VfxBool m_switchingStorage;

private:
    void showCreateAcctConfirm();
#ifdef __MMI_SSO__
    //Email SSO account
    void showCreateSsoAcctConfirm();
    void onCreateSsoAcctConfirmBtnClick(VfxObject *btn, VfxId id);
    void onReplaceForSsoAcctConfirmBtnClick(VfxObject *btn, VfxId id);    
    void addSsoAcct();
    void replaceAcctForSso();    
#endif /* #ifdef __MMI_SSO__ */
};

#ifdef __MMI_SSO__

class VappEmailSsoReplaceAcctPage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

private:
    void initData();
    void onItemStateChanged(
        VcpListMenu *sender,
        VfxU32 index,
        VcpListMenuItemStateEnum newState);
    void onToolBarClick(VfxObject *obj, VfxId id);

private:
    VcpListMenu *m_menu;
    VcpToolBar *m_toolBar;
    VfxU32 m_selectedIndex;
    VfxU32 m_acctCount;
    EMAIL_ACCT_ID m_acctId[MMI_EMAIL_MAX_ACCTS];
};
#endif /* #ifdef __MMI_SSO__ */


class VappEmailMainScrn : public VfxMainScr
{
public:
    VappEmailMainScrn(email_app_set_first_struct firstPageInfo)
        :m_firstPage(NULL),
         m_acctListPage(NULL),
         m_firstPageType(firstPageInfo.first_page_type),
         m_compInst(NULL),
         m_acctID(firstPageInfo.acct_id),
         m_fldrID(firstPageInfo.fldr_id),
         m_msgID(firstPageInfo.msg_id),
         m_fldrType(firstPageInfo.fldr_type),
         m_showTitleSwitchBtn(firstPageInfo.show_switch_btn),
         sendToAddr(NULL),
         sendToDisplayName(NULL)
    {
        #ifdef __VENUS_3D_UI_ENGINE__
        // default is 0, which causes VRT to use ALL vrt_mem_factor as cache mem.
        // so we set 1, to preserve space for OpenGL.
        setVrtCacheLimitSize(1);
        #endif    
    };
    virtual ~VappEmailMainScrn();
    virtual void on1stReady();
    virtual void on2ndReady();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    void getNextAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID);
    void getPrevAcctnFldr(EMAIL_ACCT_ID &acctID, EMAIL_FLDR_ID &fldrID);
    void setCurrFldr(EMAIL_FLDR_ID fldrID);
    EMAIL_MSG_ID getNextMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total);
    EMAIL_MSG_ID getPrevMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total);
    void getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total);
    void launchComposer(EMAIL_ACCT_ID, EMAIL_MSG_ID, VappEmailComp::VappEmailEditModeEnum);
    void setSendToAddr(WCHAR *addr, WCHAR *dispName)
    {
        sendToAddr = addr;
        sendToDisplayName = dispName;
    };
    void closeCompInstanse()
    {
        if (m_compInst != NULL)
        {
            VFX_OBJ_CLOSE(m_compInst);
            m_compInst = NULL;
        }
    };

    EmailMainFirstPageEnum getFirstPageType()
    {
        return m_firstPageType;
    };

private:
    VfxPage *m_firstPage;
    VfxWeakPtr<VappEmailAcctListPage> m_acctListPage;    
    EmailMainFirstPageEnum m_firstPageType;
    VappEmailComp *m_compInst;    
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    srv_email_fldr_type_enum m_fldrType;
    VfxBool m_showTitleSwitchBtn;
    WCHAR *sendToAddr;
    WCHAR *sendToDisplayName;
};


class VappEmailErrorPopup : public VcpConfirmPopup
{
public:
    VappEmailErrorPopup()
        :m_popupType(VCP_POPUP_TYPE_FAILURE)
    {
        m_postFix.setEmpty();
    };
    void showErrorPopup(
        srv_email_result_enum result,
        VfxMainScr *mainScr = NULL,
        EmailPageTypeEnum popPage1 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage2 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage3 = EMAIL_PAGE_TYPE_BASE);
    void showErrorPopup(
        VappEmailResStruct result,
        VfxMainScr *mainScr = NULL,
        EmailPageTypeEnum popPage1 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage2 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage3 = EMAIL_PAGE_TYPE_BASE);
    void showErrorPopup(
        VfxResId strID,
        VfxMainScr *mainScr = NULL,
        EmailPageTypeEnum popPage1 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage2 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage3 = EMAIL_PAGE_TYPE_BASE);
    void showErrorPopup(
        VfxWString &stirng,
        VfxMainScr *mainScr = NULL,
        EmailPageTypeEnum popPage1 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage2 = EMAIL_PAGE_TYPE_BASE,
        EmailPageTypeEnum popPage3 = EMAIL_PAGE_TYPE_BASE);
    void setPopupType(VcpPopupTypeEnum popupType)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SET_POPUP_TYPE, popupType);
        m_popupType = popupType;
    };
    void setPostFix(VfxWString &postFix)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SET_POSTFIX);
        m_postFix = postFix;
    };
    virtual void onDeinit();

private:
    VfxMainScr *m_mainScr;
    EmailPageTypeEnum m_popPage1;
    EmailPageTypeEnum m_popPage2;
    EmailPageTypeEnum m_popPage3;
    VcpPopupTypeEnum m_popupType;
    VfxWString m_postFix;
};


#endif /* __VAPP_EMAIL_MAIN_H__ */
