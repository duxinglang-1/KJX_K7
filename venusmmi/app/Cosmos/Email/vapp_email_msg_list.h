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
 * Vapp_email_msg_list.h
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


#ifndef __VAPP_EMAIL_MSG_LIST_H__
#define __VAPP_EMAIL_MSG_LIST_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
//#include "vapp_email_composer.h"
#include "Vapp_Email_mgr.h"
#include "vcp_menu_popup.h"

extern "C"
{
#include "emailsrvgprot.h"
} /* extern "C" */


enum MsgListPageTBItemId
{
    MSG_LIST_PAGE_TB_NEW_MAIL,
    MSG_LIST_PAGE_TB_REFRESH,
    MSG_LIST_PAGE_TB_MORE_FOLDERS,
    MSG_LIST_PAGE_TB_SORT,
    MSG_LIST_PAGE_TB_RESEND,
    MSG_LIST_PAGE_TB_DELETE,
    MSG_LIST_PAGE_TB_SELECT_ALL,
    MSG_LIST_PAGE_TB_SELECT_MARK_AS_UNREAD,
    MSG_LIST_PAGE_TB_SELECT_DELETE,
    MSG_LIST_PAGE_TB_CANCEL,
    MSG_LIST_PAGE_TB_TOTAL
};


enum MsgListPageSortTypeEnum
{
    MSG_LIST_PAGE_SORT_TYPE_SIZE,
    MSG_LIST_PAGE_SORT_TYPE_RECIPIENT,
    MSG_LIST_PAGE_SORT_TYPE_SUBJECT,
    MSG_LIST_PAGE_SORT_TYPE_READ_STATUS,
    MSG_LIST_PAGE_SORT_TYPE_TIME,
    MSG_LIST_PAGE_SORT_TYPE_CANCEL,
    MSG_LIST_PAGE_SORT_TYPE_TOTAL
};


enum MsgListPageLongTapMenuEnum
{
    MSG_LIST_PAGE_LONG_TAP_REPLY,
    MSG_LIST_PAGE_LONG_TAP_FORWARD,
    MSG_LIST_PAGE_LONG_TAP_DELETE,
    MSG_LIST_PAGE_LONG_TAP_MARK_AS_UNREAD,
    MSG_LIST_PAGE_LONG_TAP_MOVE_TO_DRAFT,
    MSG_LIST_PAGE_LONG_TAP_SEND,
    MSG_LIST_PAGE_LONG_TAP_TOTAL
};


enum MsgListPageMoreBoxesTypeEnum
{
    MSG_LIST_PAGE_MORE_BOXES_TYPE_INBOX,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_DRAFTS,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_OUTBOX,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_SENT,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_REMOTE_FOLDER,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_CANCEL,
    MSG_LIST_PAGE_MORE_BOXES_TYPE_TOTAL
};

void vapp_email_reset_curr_fldr_info(void);

void vapp_email_reset_fldr_info(EMAIL_ACCT_ID acctId);

class VappEmailMsgListMenuCell : public VcpListMenuCellTripleTextFrameEx
{
public:
    VappEmailMsgListMenuCell(VfxU32 index)
        :m_iconImage(NULL),
         m_index(index)
    {
    };
    virtual void onCreateElements();
    //void onCloseElements();
    //void onLayoutElements();
    virtual void onUpdateElements();

private:
    VfxImageFrame *m_iconImage;
    VfxU32 m_index;
};


class VappEmailMsgListProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappEmailMsgListProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID);
    virtual void onInit();
    virtual void onDeinit();
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
    VcpListMenu *getListMenu();
    virtual VfxBool getItemTextFrameFormat(VfxU32, VcpListMenuFieldEnum, VfxTextFrame *);    

    /* functions */
    void sortMsg(MsgListPageSortTypeEnum sortType);
    EMAIL_MSG_ID getNextMsgID(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    EMAIL_MSG_ID getPrevMsgID(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    void getMsgIndex(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    EMAIL_FLDR_HANDLE getFldrHandle();
    void resetProvider(EMAIL_ACCT_ID, EMAIL_FLDR_ID);
    void initProvider(EMAIL_ACCT_ID, EMAIL_FLDR_ID);
    void getMsgNum(VfxU32 &unreadMsgNum, VfxU32 &msgNum);
    static void onMsgListUpdate(srv_email_om_notify_struct *, void *);
    srv_email_result_enum markMsg(VfxBool);
    srv_email_result_enum markAsUnread(EMAIL_MSG_ID msgID);
    srv_email_result_enum moveMsgToFolder(EMAIL_FLDR_ID, EMAIL_MSG_ID);
    srv_email_result_enum deleteMsg(EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID);
    void getCheckBoxList();
    void checkBoxClick(VfxU32 index)
    {
        if (m_checkBoxList != NULL)
        {
            if (m_checkBoxList[index])
            {
                m_checkBoxList[index] = 0;
                m_checkedMsg--;
            }
            else
            {
                m_checkBoxList[index] = 1;
                m_checkedMsg++;
            }
        }
    };
    void freeCheckBoxList()
    {
        if (m_checkBoxList != NULL)
        {
            free_ctrl_buffer(m_checkBoxList);
            m_checkBoxList = NULL;
        }
        m_checkedMsg = 0;
        m_currMsgNum = 0;
    };
    VfxU32 getCheckedItemNum()
    {
        return m_checkedMsg;
    };
    void selectAllCheckBox(VfxU8);
    EMAIL_MSG_ID getMsgIDByIndex(VfxU32);
    void increaseSendFailNum()
    {
        m_sendFailMsgNum++;
    };
    void resetSendFailNum()
    {
        m_sendFailMsgNum = 0;
    };
    VfxU32 getIndexMap(VfxU32);

private:
    EMAIL_FLDR_HANDLE m_fldrHandle;
    EMAIL_REQ_ID m_listReqID;
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    VcpListMenu *m_listMenu;
    VfxU8 *m_checkBoxList;
    VfxU32 m_sendFailMsgNum;
    VfxU32 m_checkedMsg;
    VfxU32 m_currMsgNum;    // multi selection in sent box to avoid new message add to multi selection list.
    VfxBool m_isReady;      // List provider is ready for show list data.

private:
    static void generalAsyncCallback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data);
    VfxU16 getMsgStatusIcon(VcpListMenuFieldEnum, VfxU32);
    void setProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID);
};


class VappEmailMsgListTitleBar : public VfxPageBar
{
public:
    VappEmailMsgListTitleBar()
        :m_leftButton(NULL),
         m_rightButton(NULL),
         m_fldrNameText(NULL),
         m_acctNameText(NULL),
         m_bgImageFrame(NULL),
         m_rotation(VFX_SCR_ROTATE_TYPE_NORMAL)
    {
    };
    VappEmailMsgListTitleBar(VfxBool showBtn)
        :m_leftButton(NULL),
         m_rightButton(NULL),
         m_fldrNameText(NULL),
         m_acctNameText(NULL),
         m_bgImageFrame(NULL),
         m_rotation(VFX_SCR_ROTATE_TYPE_NORMAL)
    {
    };
    virtual void onInit();
    virtual void onSetRotate(VfxScrRotateTypeEnum rotation);    
    VcpImageButton *getLeftButton()
    {
        return m_leftButton;
    };
    VcpImageButton *getRightButton()
    {
        return m_rightButton;
    };
    void updateButtons(VfxBool);
    void updateTitleText(VfxWString &, VfxWString &);
    void updateTitleTextLayout();
    void updateTitleBtnLayout();

private:
    //VcpImageButton *m_bgBtn;
    VcpImageButton *m_leftButton;
    VcpImageButton *m_rightButton;
    VfxTextFrame *m_fldrNameText;
    VfxTextFrame *m_acctNameText;
    VfxImageFrame *m_bgImageFrame;
    VfxScrRotateTypeEnum m_rotation;    
};


class VappEmailMsgListPage : public VfxPage
{
public:
    VappEmailMsgListPage(EMAIL_ACCT_ID, EMAIL_FLDR_ID, srv_email_fldr_type_enum, VfxBool);
    VappEmailMsgListPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &);
    virtual void onEnter(VfxBool);
    virtual void onEntered();
    virtual void onBack();
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    void onTBClick(VfxObject *, VfxId);
    void onItemClick(VcpListMenu *, VfxU32);
    void onItemLongTapped(VcpListMenu *, VfxU32);
    void onLongTapMenuItemClick(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);
    void onSortTypeClick(VfxObject *, VfxId);
    void onMoreFolderClick(VfxObject *, VfxId);
    void onTitleBarLBtnClick(VfxObject *, VfxId);
    void onTitleBarRBtnClick(VfxObject *, VfxId);
    void onDeleteConfirmBtnClick(VfxObject *, VfxId);

    EMAIL_MSG_ID getNextMsgID(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    EMAIL_MSG_ID getPrevMsgID(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    void getMsgIndex(EMAIL_MSG_ID, VfxU32 &, VfxU32 &);
    void onMsgListUpdate();
    void generalAsyncCallback(srv_email_result_struct *, EMAIL_REQ_ID, void *);
    void providerUpdated(srv_email_result_enum result, VfxBool isDeleteMsg = VFX_FALSE);
    void showLoadingPopup(const VfxWChar *textPtr = NULL);
    void closeLoading()
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_CLOSE_LOADING, __LINE__);
        if (m_loadingPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_loadingPopup);
            m_loadingPopup = NULL;
        }
    };
    srv_email_result_enum setSingleMsgFlag();
    void onFldrMsgNumChange(EMAIL_ACCT_ID, EMAIL_FLDR_ID, VappEmailFldrMsgNumStruct);
    void onMsgChange(EMAIL_MSG_ID, srv_email_om_notify_msg_struct);
    void onAcctNwkDone(EMAIL_ACCT_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void onMsgStateChange(EMAIL_MSG_ID, VappEmailMsgStateEnum);
    void onMsgDelete(EMAIL_MSG_ID);
    void onAcctStateChange(EMAIL_ACCT_ID, VappEmailAcctStateEnum);
    void resetPage(EMAIL_ACCT_ID, EMAIL_FLDR_ID, srv_email_fldr_type_enum);
    void updateTitleBar();
    void onErrorPopupClicked(VfxObject*, VfxId);

private:
    enum VappEmailMsgListPageTBEnum
    {
        MSG_LIST_PAGE_TOOLBAR_NEW_MAIL,
        MSG_LIST_PAGE_TOOLBAR_REFRESH,
        MSG_LIST_PAGE_TOOLBAR_MAIL_BOXES,
        MSG_LIST_PAGE_TOOLBAR_SORT,
        MSG_LIST_PAGE_TOOLBAR_MARK_AS_UNREAD,
        MSG_LIST_PAGE_TOOLBAR_DELETE,
        MSG_LIST_PAGE_TOOLBAR_TOTAL
    };
    VappEmailMsgListProvider *m_listProvider;
    VcpToolBar *mToolbar;
    VcpListMenu *m_listMenu;
    VappEmailMsgListTitleBar *m_titleBar;
    VcpIndicatorPopup *m_loadingPopup;
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    srv_email_fldr_type_enum m_fldrType;
    VfxU32 m_index;
    VfxBool m_multiSelection;
    VfxBool m_allSelected;
    EMAIL_REQ_ID m_reqID;
    enum VappEmailMsgListPageTBType
    {
        MSG_LIST_PAGE_TB_TYPE_NONE,
        MSG_LIST_PAGE_TB_TYPE_INBOX,
        MSG_LIST_PAGE_TB_TYPE_OUTBOX,
        MSG_LIST_PAGE_TB_TYPE_SENT,
        MSG_LIST_PAGE_TB_TYPE_DRAFT,
        MSG_LIST_PAGE_TB_TYPE_TOTAL
    };
    VappEmailMsgListPageTBType m_TBType;
    VfxBool m_showTitleBarBtn;
    VcpTitleBar *m_bgTitleBar;
    EMAIL_MSG_ID m_longTappedMsgID;
    VcpMenuPopup *m_selectPopup;
    VcpConfirmPopup *m_deleteConfirmPopup;
    VfxBool m_isDeleteOutboxMsg;
    VappEmailErrorPopup *m_errorPopup;
    VfxBool m_needUpdate;
 
private:
    void updatePage();
    void updateMsgList();
    void updateToolbar();
    void updateTitleBarText();
    void updateToolbarItems();
    void setInboxToolbar();
    void setOutboxToolbar();
    void setSentToolbar();
    void setDraftToolbar();
    srv_email_result_enum getFldrIDandTypeByBtn(MsgListPageMoreBoxesTypeEnum);
    void updateMultiSelectToolbar();
};


class VappEmailMsgListRemoteFolderListProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappEmailMsgListRemoteFolderListProvider(EMAIL_ACCT_ID acctID);
    virtual void setMenu(VcpListMenu *listMenu)
    {
        m_listMenu = listMenu;
    };
    virtual VfxBool getItemText(VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getItemTextFrameFormat(VfxU32, VcpListMenuFieldEnum, VfxTextFrame *);
    virtual VfxBool getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &);
    virtual void closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32) const;
    virtual VfxBool swapItem(VfxU32, VfxU32);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32, VfxFrame *);
    virtual void closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *);
    void updateFldrMsgNum(EMAIL_FLDR_ID fldrID, VfxU32 unreadMsgNum, VfxU32 msgNum);

private:
    VcpListMenu *m_listMenu;
    EMAIL_ACCT_ID m_acctID;
    struct FldrIDMsgNumMap
    {
        EMAIL_FLDR_ID fldrID;
        VfxU32 msgNum;
        VfxU32 unreadMsgNum;
    };
    /* SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER */
    FldrIDMsgNumMap m_fldrIDMsgNumMap[20];
};


class VappEmailMsgListRemoteFolderPage : public VfxPage
{
public:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    VappEmailMsgListRemoteFolderPage(EMAIL_ACCT_ID acctID)
        :m_acctID(acctID),
        m_listProvider(NULL),
        m_listMenu(NULL),
        m_titleBar(NULL)
    {
    };
    virtual void onRotate(const VfxScreenRotateParam &param);
    VappEmailMsgListRemoteFolderPage();
    void onItemClick(VcpListMenu *, VfxU32);
    void onAcctMsgNumChange(EMAIL_ACCT_ID, EMAIL_FLDR_ID, VappEmailFldrMsgNumStruct);

private:
    EMAIL_ACCT_ID m_acctID;
    VappEmailMsgListRemoteFolderListProvider *m_listProvider;
    VcpListMenu *m_listMenu;
    VcpTitleBar *m_titleBar;
};


#endif /* __VAPP_EMAIL_MSG_LIST_H__ */
