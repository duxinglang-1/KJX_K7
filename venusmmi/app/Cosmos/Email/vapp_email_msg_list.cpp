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
 * Vapp_email_msg_list.cpp
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


#include "MMI_features.h" 
#include "Vapp_Email_Main.h"
#include "Vapp_Email_Msg_List.h"
#include "Vapp_Email_Msg_View.h"
#include "vapp_email_util.h"


extern "C"
{
#include "emailsrvgprot.h"
#include "emailappmem.h"

/* long tapped feedback */
#include "vfx_adp_device.h"

#include "mmi_rp_app_cosmos_global_def.h"
} /* exter "C" */


extern EMAIL_SRV_HANDLE gEmailSrvHandle;
extern VfxU32 gScrnWidth;
extern VfxU32 gScrnHeight;

 
typedef struct
{
    srv_email_fldr_create_info_struct info;
    EMAIL_FLDR_HANDLE handle;
} email_app_curr_fldr_info_struct;

static email_app_curr_fldr_info_struct gCurrFldrInfo;


void vapp_email_reset_curr_fldr_info(void)
{
    if (gCurrFldrInfo.handle != EMAIL_FLDR_INVALID_ID)
    {
        srv_email_fldr_destroy(gCurrFldrInfo.handle);
    }
    
    memset(&gCurrFldrInfo, 0, sizeof(email_app_curr_fldr_info_struct));
}


void vapp_email_reset_fldr_info(EMAIL_ACCT_ID acctId)
{
    if (gCurrFldrInfo.info.acct_id == acctId)
    {
        vapp_email_reset_curr_fldr_info();
    }
}


void VappEmailMsgListMenuCell::onCreateElements()
{
    VcpListMenuCellTripleTextFrameEx::onCreateElements();

    VfxBool isUnread = VFX_FALSE;
    VappEmailMsgListProvider *contentProvider = (VappEmailMsgListProvider*)(((VcpListMenu*)getMenu())->getContentProvider());
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
    U32 msgCount = 1;
    srv_email_fldr_get_msg_list(contentProvider->getFldrHandle(), (U32)m_index, &msgCount, msgInfo);
    if (!(msgInfo->flag & EMAIL_MSG_FLAG_SEEN))
    {
        isUnread = VFX_TRUE;
    }
    free_ctrl_buffer(msgInfo);

    if (isUnread == VFX_TRUE)
    {
        VFX_OBJ_CREATE(m_iconImage, VfxImageFrame, this);
        m_iconImage->setResId(IMG_EMAIL_FTO_UNREAD_ID);
        m_iconImage->setPos(0, 0);
        m_iconImage->setSize(EMAIL_MSG_LIST_UNREAD_ICON_SIZE, EMAIL_MSG_LIST_UNREAD_ICON_SIZE);
    }
}


//void VappEmailMsgListMenuCell::onCloseElements()
//{
//    VcpListMenuCellTripleTextFrameEx::onCloseElements();
//}
//
//
//void VappEmailMsgListMenuCell::onLayoutElements()
//{
//    VcpListMenuCellTripleTextFrameEx::onLayoutElements();
//}
//
//
void VappEmailMsgListMenuCell::onUpdateElements()
{
    VcpListMenuCellTripleTextFrameEx::onUpdateElements();

    VfxBool isUnread = VFX_FALSE;
    VappEmailMsgListProvider *contentProvider = (VappEmailMsgListProvider*)(((VcpListMenu*)getMenu())->getContentProvider());
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
    U32 msgCount = 1;
    srv_email_fldr_get_msg_list(contentProvider->getFldrHandle(), (U32)m_index, &msgCount, msgInfo);
    if (!(msgInfo->flag & EMAIL_MSG_FLAG_SEEN))
    {
        isUnread = VFX_TRUE;
    }
    free_ctrl_buffer(msgInfo);

    if (isUnread == VFX_TRUE)
    {
        if (m_iconImage == NULL)
        {
            VFX_OBJ_CREATE(m_iconImage, VfxImageFrame, this);
            m_iconImage->setPos(0, 0);
            m_iconImage->setSize(EMAIL_MSG_LIST_UNREAD_ICON_SIZE, EMAIL_MSG_LIST_UNREAD_ICON_SIZE);
        }
        m_iconImage->setResId(IMG_EMAIL_FTO_UNREAD_ID);
    }
    else
    {
        if (m_iconImage != NULL)
        {
            VFX_OBJ_CLOSE(m_iconImage);
            m_iconImage = NULL;
        }
    }
}


VappEmailMsgListPage::VappEmailMsgListPage(
    EMAIL_ACCT_ID acctID,
    EMAIL_FLDR_ID fldrID,
    srv_email_fldr_type_enum fldrType,
    VfxBool showTitleBarBtn)
    :m_listProvider(NULL),
     mToolbar(NULL),
     m_listMenu(NULL),
     m_titleBar(NULL),
     m_loadingPopup(NULL),
     m_acctID(acctID),
     m_fldrID(fldrID),
     m_fldrType(fldrType),
     m_index(0),
     m_multiSelection(VFX_FALSE),
     m_allSelected(VFX_FALSE),
     m_reqID(0),
     m_TBType(MSG_LIST_PAGE_TB_TYPE_NONE),
     m_showTitleBarBtn(showTitleBarBtn),
     m_bgTitleBar(NULL),
     m_longTappedMsgID(EMAIL_MSG_INVALID_ID),
     m_selectPopup(NULL),
     m_deleteConfirmPopup(NULL),
     m_isDeleteOutboxMsg(VFX_FALSE),
     m_errorPopup(NULL),
     m_needUpdate(VFX_FALSE)
{

}


VappEmailMsgListPage::VappEmailMsgListPage()
    :m_listProvider(NULL),
     mToolbar(NULL),
     m_listMenu(NULL),
     m_titleBar(NULL),
     m_loadingPopup(NULL),
     m_acctID(EMAIL_ACCT_INVALID_ID),
     m_fldrID(EMAIL_FLDR_INVALID_ID),
     m_fldrType(SRV_EMAIL_FLDR_TYPE_INVALID),
     m_index(0),
     m_multiSelection(VFX_FALSE),
     m_allSelected(VFX_FALSE),
     m_reqID(0),
     m_TBType(MSG_LIST_PAGE_TB_TYPE_NONE),
     m_showTitleBarBtn(VFX_FALSE),
     m_bgTitleBar(NULL),
     m_longTappedMsgID(EMAIL_MSG_INVALID_ID),
     m_selectPopup(NULL),
     m_deleteConfirmPopup(NULL),
     m_isDeleteOutboxMsg(VFX_FALSE),
     m_errorPopup(NULL),
     m_needUpdate(VFX_FALSE)
{

}


void VappEmailMsgListPage::onInit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_PAGE_INIT);

    VfxPage::onInit();
    VappEmailMgr *emailMgrInst = VappEmailMgr::getInstance();
    emailMgrInst->enterAcct(m_acctID);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX(m_listProvider, VappEmailMsgListProvider, this, (m_acctID, m_fldrID));
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT_EX);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgListPage::onItemClick);
    m_listMenu->m_signalItemLongTapped.connect(this, &VappEmailMsgListPage::onItemLongTapped);
    m_listProvider->setMenu(m_listMenu);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    updateTitleBar();
    updateToolbar();

    emailMgrInst->m_signalFldrMsgNumChange.connect(this, &VappEmailMsgListPage::onFldrMsgNumChange);
    emailMgrInst->m_signalMsgChange.connect(this, &VappEmailMsgListPage::onMsgChange);
    emailMgrInst->m_signalAcctNwkDone.connect(this, &VappEmailMsgListPage::onAcctNwkDone);
    emailMgrInst->m_signalMsgDelete.connect(this, &VappEmailMsgListPage::onMsgDelete);
    emailMgrInst->m_signalAcctStateChange.connect(this, &VappEmailMsgListPage::onAcctStateChange);

    /* only for outbox */
    emailMgrInst->m_signalMsgStateChange.connect(this, &VappEmailMsgListPage::onMsgStateChange);

    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
}


void VappEmailMsgListPage::onDeinit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_PAGE_DEINIT);

    VfxPage::onDeinit();

    VappEmailMgr::getInstance()->editFldrStop(m_acctID, m_fldrID);
    VappEmailMgr::getInstance()->exitAcct(m_acctID);
}


void VappEmailMsgListPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (m_needUpdate)
    {
        updatePage();
        m_needUpdate = VFX_FALSE;
    }

    if (isBackward)
    {
        if (m_showTitleBarBtn)
        {
            m_titleBar->getLeftButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
            m_titleBar->getRightButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        }
    }
}


void VappEmailMsgListPage::onEntered()
{
    m_listMenu->setContentProvider(m_listProvider);
}


VfxBool VappEmailMsgListPage::onKeyInput(VfxKeyEvent &event)
{
    if (m_showTitleBarBtn)
    {
        /* follow BD's rule, handle key event down and long press */
        if (event.specialKeyFlag == 0 &&
            (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
             event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS ||
             event.type == VFX_KEY_EVENT_TYPE_REPEAT))
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
            {
                onTitleBarLBtnClick(NULL, 0);
            }
            else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
            {
                onTitleBarRBtnClick(NULL, 0);
            }
        }

        if (event.specialKeyFlag == 0)
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                {
                    m_titleBar->getLeftButton()->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
                }
                else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
                {
                    m_titleBar->getRightButton()->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
                }
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                {
                    m_titleBar->getLeftButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
                }
                else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
                {
                    m_titleBar->getRightButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
                }
            }
        }
    }

    /* do not stop route key event to let other CP have opportunity to handle key event */
    return VfxPage::onKeyInput(event);
}


void VappEmailMsgListPage::onBack()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_PAGE_ON_BACK, m_fldrType);

    if (m_multiSelection == VFX_TRUE)
    {
        onTBClick(NULL, MSG_LIST_PAGE_TB_CANCEL);
        return;
    }

    if (m_fldrType == SRV_EMAIL_FLDR_TYPE_INBOX)
    {
        VappEmailMgr::getInstance()->exitAcct(m_acctID);
        VfxPage::onBack();
    }
    else
    {
        onMoreFolderClick(NULL, MSG_LIST_PAGE_MORE_BOXES_TYPE_INBOX);
    }
}


void VappEmailMsgListPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_270 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_LANDSCAPE)
    {
        gScrnWidth = LCD_HEIGHT;
        gScrnHeight = LCD_WIDTH;
    }
    else
    {
        gScrnWidth = LCD_WIDTH;
        gScrnHeight = LCD_HEIGHT;
    }

    //updateTitleBarText();
}


void VappEmailMsgListPage::updatePage()
{
    updateMsgList();
    updateTitleBar();
    updateToolbar();
}


void VappEmailMsgListPage::resetPage(
        EMAIL_ACCT_ID acctID,
        EMAIL_FLDR_ID fldrID,
        srv_email_fldr_type_enum fldrType)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_PAGE_RESET_PAGE, acctID, fldrID, fldrType);

    if (m_acctID != acctID)
    {
        VappEmailMgr::getInstance()->exitAcct(m_acctID);
        VappEmailMgr::getInstance()->enterAcct(acctID);
        m_acctID = acctID;
    }
    m_fldrID = fldrID;
    m_fldrType = fldrType;
    m_isDeleteOutboxMsg = VFX_FALSE;
    m_listProvider->resetProvider(m_acctID, m_fldrID);

    m_needUpdate = VFX_FALSE;
}


void VappEmailMsgListPage::updateTitleBar()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_UPDATE_TITLEBAR);
    if (m_titleBar == NULL)
    {
        VFX_OBJ_CREATE_EX(m_titleBar, VappEmailMsgListTitleBar, this, (m_showTitleBarBtn));
        setTopBar(m_titleBar);
    }

    updateTitleBarText();
    VcpImageButton *btn = NULL;
    btn = m_titleBar->getLeftButton();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgListPage::onTitleBarLBtnClick);
    }
    btn = m_titleBar->getRightButton();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgListPage::onTitleBarRBtnClick);
    }
}


void VappEmailMsgListPage::onErrorPopupClicked(VfxObject*, VfxId)
{
    m_errorPopup = NULL;
}


void VappEmailMsgListPage::updateTitleBarText()
{
    if (m_titleBar == NULL)
    {
        return;
    }

    VfxWString tbText;
    VfxWString numString;
    VfxWString numtext;
    VfxU32 unreadMsgNum;
    VfxU32 msgNum;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    m_listProvider->getMsgNum(unreadMsgNum, msgNum);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_UPDATE_TITLEBAR_TEXT, m_acctID, unreadMsgNum, msgNum);

    numString += VFX_WSTR(" ");
    numString += VFX_WSTR_RES(STR_EMAIL_FTO_LEFT_PARENTHESES);

    switch (m_fldrType)
    {
        case SRV_EMAIL_FLDR_TYPE_INBOX:
        {
            tbText.loadFromRes(STR_GLOBAL_INBOX);
            if (unreadMsgNum == 0)
            {
                numtext.format("%d", msgNum);
            }
            else
            {
                numtext.format("%d/%d", unreadMsgNum, msgNum);
            }
            break;
        }
    
        case SRV_EMAIL_FLDR_TYPE_OUTBOX:
        {
            tbText.loadFromRes(STR_GLOBAL_OUTBOX);
            numtext.format("%d", msgNum);
            break;
        }
        
        case SRV_EMAIL_FLDR_TYPE_SENT:
        {
            tbText.loadFromRes(STR_EMAIL_SENT_ID);
            numtext.format("%d", msgNum);
            break;
        }

        case SRV_EMAIL_FLDR_TYPE_DRAFT:
        {
            tbText.loadFromRes(STR_GLOBAL_DRAFTS);
            numtext.format("%d", msgNum);
            break;
        }

        case SRV_EMAIL_FLDR_TYPE_REMOTE:
        {
            EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
            srv_email_acct_folder_struct *fldrInfo = NULL;

            do
            {
                result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_acct_open(acctHandle, m_acctID);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                fldrInfo = (srv_email_acct_folder_struct*)get_ctrl_buffer(sizeof(srv_email_acct_folder_struct));
                result = srv_email_acct_get_fldr_info(
                            acctHandle,
                            m_fldrID,
                            fldrInfo);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                tbText.loadFromMem((VfxWChar*)(fldrInfo->folder_name));
            } while(0);

            if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
            {
                srv_email_acct_destroy(acctHandle);
            }
            if (fldrInfo != NULL)
            {
                free_ctrl_buffer(fldrInfo);
            }
            if (unreadMsgNum == 0)
            {
                numtext.format("%d", msgNum);
            }
            else
            {
                numtext.format("%d/%d", unreadMsgNum, msgNum);
            }
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
                errorPopup->showErrorPopup(result);
            }
            break;
        }
        
        default:
            return;
    }
    
    numString += numtext;
    numString += VFX_WSTR_RES(STR_EMAIL_FTO_RIGHT_PARENTHESES); 
    
    tbText += numString;

    VfxWString acctName;
    S32 acctNameLength = SRV_EMAIL_MAX_ACCT_NAME_LEN + 1;
    WCHAR *textCont = (WCHAR*)get_ctrl_buffer(acctNameLength * 2);
    result = srv_email_acct_get_name(m_acctID, textCont, acctNameLength);
    acctName.loadFromMem(textCont);
    free_ctrl_buffer(textCont);
    m_titleBar->updateTitleText(tbText, acctName);
    m_titleBar->updateButtons(m_showTitleBarBtn);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result);
    }
}


void VappEmailMsgListPage::updateToolbar()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_UPDATE_TOOLBAR, mToolbar, m_fldrType);

    if (mToolbar == NULL)
    {
        VFX_OBJ_CREATE(mToolbar, VcpToolBar, this);
        mToolbar->m_signalButtonTap.connect(this, &VappEmailMsgListPage::onTBClick);
        setBottomBar(mToolbar);
    }

    if (m_multiSelection == VFX_FALSE)
    {
        updateToolbarItems();
    }
}


void VappEmailMsgListPage::updateToolbarItems()
{
    switch (m_fldrType)
    {
    case SRV_EMAIL_FLDR_TYPE_INBOX:
    case SRV_EMAIL_FLDR_TYPE_REMOTE:
        {
            setInboxToolbar();
        }
        break;
    case SRV_EMAIL_FLDR_TYPE_OUTBOX:
        {
            setOutboxToolbar();
        }
        break;
    case SRV_EMAIL_FLDR_TYPE_SENT:
        {
            setSentToolbar();
        }
        break;
    case SRV_EMAIL_FLDR_TYPE_DRAFT:
        {
            setDraftToolbar();
        }
        break;
    default:
        return;
    }
}


EMAIL_MSG_ID VappEmailMsgListPage::getNextMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    return m_listProvider->getNextMsgID(currMsgID, index, total);
}


EMAIL_MSG_ID VappEmailMsgListPage::getPrevMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    return m_listProvider->getPrevMsgID(currMsgID, index, total);
}


void VappEmailMsgListPage::getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    m_listProvider->getMsgIndex(currMsgID, index, total);
}


void VappEmailMsgListPage::onMsgListUpdate()
{
    updatePage();
}


void VappEmailMsgListPage::generalAsyncCallback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ASYNC_CALLBACK, result->result, result->major, result->minor);

    if (m_showTitleBarBtn)
    {
        m_titleBar->getLeftButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        m_titleBar->getRightButton()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    }
    closeLoading();

    if (m_multiSelection)
    {
        m_multiSelection = VFX_FALSE;
        VappEmailMgr::getInstance()->editFldrStop(m_acctID, m_fldrID);
    }

    if (!result->result)
    {
        if (result->major == SRV_EMAIL_MAIL_ERROR)
        {
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getParent());
            /* should also handle srv_email_result_struct */
            errorPopup->showErrorPopup((srv_email_result_enum)result->minor);
        }
        return;
    }

    onMsgListUpdate();
}


void VappEmailMsgListPage::providerUpdated(srv_email_result_enum result, VfxBool isDeleteMsg)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_PROVIDER_UPDATED, result, isDeleteMsg);

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        onMsgListUpdate();
    }
    else if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (isDeleteMsg)
        {
            VfxWString text;
            text.loadFromRes(STR_GLOBAL_DELETING);
            showLoadingPopup(text.getBuf());
        }

        m_listMenu->resetAllItems(VFX_TRUE);
    }
    else
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result);
    }
}


void VappEmailMsgListPage::showLoadingPopup(const VfxWChar *textPtr)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_LOADING);

    if (m_loadingPopup == NULL)
    {
        VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, this);
        m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        VfxWString text;
        if (textPtr == NULL)
        {
            text.loadFromRes(STR_GLOBAL_LOADING);
        }
        else
        {
            text.loadFromMem(textPtr);
        }
        m_loadingPopup->setText(text);
        m_loadingPopup->setAutoDestory(VFX_FALSE);
        m_loadingPopup->show(VFX_TRUE);
    }
}


srv_email_result_enum VappEmailMsgListPage::setSingleMsgFlag()
{
    return SRV_EMAIL_RESULT_SUCC;
}


void VappEmailMsgListPage::onFldrMsgNumChange(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID, VappEmailFldrMsgNumStruct numChange)
{
    if (acctID != m_acctID || fldrID != m_fldrID)
    {
        return;
    }

    if (m_multiSelection == VFX_TRUE)
    {
        return;
    }

    if (getMainScr()->getTopPageId() != EMAIL_PAGE_TYPE_MSG_LIST)
    {
        m_needUpdate = VFX_TRUE;
        return;
    }

    updateTitleBar();
    updateToolbar();
    if (m_listMenu != NULL)
    {
        m_listMenu->resetAllItems(VFX_TRUE);
        if (m_isDeleteOutboxMsg && m_listProvider->getCount() == 0)
        {
            m_isDeleteOutboxMsg = VFX_FALSE;
            //onTBClick(NULL, MSG_LIST_PAGE_TB_RESEND);
            VfxWString tbText;
            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
            {
                VappEmailMgr::getInstance()->cancelSendOutbox(m_acctID);
                tbText.loadFromRes(STR_EMAIL_FTO_RESEND_MAIL_ID);
                mToolbar->changeItem(
                    MSG_LIST_PAGE_TB_RESEND,
                    tbText,
                    VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND));
            }
        }
    }
}


void VappEmailMsgListPage::onMsgChange(EMAIL_MSG_ID msgID, srv_email_om_notify_msg_struct)
{
    if (srv_email_msg_id_to_acct_id(msgID) != m_acctID || srv_email_msg_id_to_fldr_id(msgID) != m_fldrID)
    {
        return;
    }

    /* it can be NULL entry Inbox when refreshing background if some message's state change */
    if (m_listMenu != NULL)
    {
        /* list menu item count not change updateAllItems will be ok */
        m_listMenu->resetAllItems(VFX_TRUE);
    }
}


void VappEmailMsgListPage::onAcctNwkDone(EMAIL_ACCT_ID acctID, VappEmailNwkDoneEnum operation, VappEmailResStruct result)
{
    if (acctID != m_acctID)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ACCT_NWK_DONE, acctID, operation, result.result);

    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX)
    {
        m_listProvider->resetSendFailNum();
        m_listMenu->resetAllItems(VFX_TRUE);
    }

    srv_email_fldr_type_enum fldrType = srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID);
    if (fldrType == SRV_EMAIL_FLDR_TYPE_SENT && m_multiSelection == VFX_TRUE)
    {
        return;
    }

    /* no need to update draft when account network done */
    if (fldrType != SRV_EMAIL_FLDR_TYPE_DRAFT)
    {
        updateToolbar();
    }
}


void VappEmailMsgListPage::onMsgStateChange(EMAIL_MSG_ID msgID, VappEmailMsgStateEnum msgState)
{
    if (srv_email_msg_id_to_acct_id(msgID) != m_acctID || srv_email_msg_id_to_fldr_id(msgID) != m_fldrID)
    {
        return;
    }

    if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
    {
        /* close option menu or delete confirm popup when message's status changes to sending */
        if (msgID == m_longTappedMsgID)
        {
            if (m_selectPopup != NULL)
            {
                VFX_OBJ_CLOSE(m_selectPopup);
                m_selectPopup = NULL;
            }
            if (m_deleteConfirmPopup != NULL)
            {
                VFX_OBJ_CLOSE(m_deleteConfirmPopup);
                m_deleteConfirmPopup = NULL;
            }
            m_longTappedMsgID = EMAIL_MSG_INVALID_ID;
        }
    }

    if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL)
    {
        if (m_listProvider != NULL)
        {
            m_listProvider->increaseSendFailNum();
        }
    }

    if (m_listMenu != NULL)
    {
        m_listMenu->resetAllItems(VFX_TRUE);
    }
}


void VappEmailMsgListPage::onMsgDelete(EMAIL_MSG_ID msgID)
{
    if (msgID == m_longTappedMsgID)
    {
        /* close option menu or delete confirm popup when message is delete by updating */
        if (m_selectPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_selectPopup);
            m_selectPopup = NULL;
        }
        if (m_deleteConfirmPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_deleteConfirmPopup);
            m_deleteConfirmPopup = NULL;
        }
        m_longTappedMsgID = EMAIL_MSG_INVALID_ID;
    }

    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX &&
        m_errorPopup != NULL)
    {
        VFX_OBJ_CLOSE(m_errorPopup);
        m_errorPopup = NULL;
    }
}


void VappEmailMsgListPage::onAcctStateChange(EMAIL_ACCT_ID acctID, VappEmailAcctStateEnum state)
{
    if (acctID != m_acctID)
    {
        return;
    }

    updateToolbar();
    
    if (state == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING && m_listMenu != NULL)
    {
        m_listMenu->resetAllItems(VFX_TRUE);
    }
}


void VappEmailMsgListPage::setInboxToolbar()
{
    if (m_TBType != MSG_LIST_PAGE_TB_TYPE_INBOX)
    {
        m_TBType = MSG_LIST_PAGE_TB_TYPE_INBOX;
        for (VfxU32 i = 0; i < MSG_LIST_PAGE_TB_TOTAL; i++)
        {
            mToolbar->removeItem(i);
        }

        VfxWString tbText;
        tbText.loadFromRes(STR_EMAIL_FTO_NEW_EMAIL_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_NEW_MAIL, tbText, VfxResId(IMG_EMAIL_FTO_TB_NEW_MAIL));
        tbText.loadFromRes(STR_GLOBAL_REFRESH);
        mToolbar->addItem(MSG_LIST_PAGE_TB_REFRESH, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
        tbText.loadFromRes(STR_EMAIL_FTO_MAIL_BOXES_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_MORE_FOLDERS, tbText, VfxResId(IMG_EMAIL_FTO_TB_MAILBOXES));
        tbText.loadFromRes(STR_GLOBAL_DELETE);
        mToolbar->addItem(MSG_LIST_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
        tbText.loadFromRes(STR_GLOBAL_SORT);
        mToolbar->addItem(MSG_LIST_PAGE_TB_SORT, tbText, VfxResId(IMG_EMAIL_FTO_TB_SORT));
    }

    mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_FALSE);
    mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_FALSE);
    VfxWString tbText;
    if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
        VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
    {
        tbText.loadFromRes(STR_EMAIL_FTO_STOP_REFRESH_ID);
        mToolbar->changeItem(
            MSG_LIST_PAGE_TB_REFRESH,
            tbText,
            VfxResId(IMG_EMAIL_FTO_TB_STOP));
    }
    else
    {
        tbText.loadFromRes(STR_GLOBAL_REFRESH);
        mToolbar->changeItem(
            MSG_LIST_PAGE_TB_REFRESH,
            tbText,
            VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
    }
    if(m_listProvider->getCount() == 0)
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_TRUE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_TRUE);
    }
    VappEmailStateEnum emailState;
    if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_REFRESH, VFX_FALSE);
    }
    else
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_REFRESH, VFX_TRUE);
    }
}


void VappEmailMsgListPage::setOutboxToolbar()
{
    if (m_TBType != MSG_LIST_PAGE_TB_TYPE_OUTBOX)
    {
        m_TBType = MSG_LIST_PAGE_TB_TYPE_OUTBOX;
        for (VfxU32 i = 0; i < MSG_LIST_PAGE_TB_TOTAL; i++)
        {
            mToolbar->removeItem(i);
        }

        VfxWString tbText;
        tbText.loadFromRes(STR_EMAIL_FTO_NEW_EMAIL_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_NEW_MAIL, tbText, VfxResId(IMG_EMAIL_FTO_TB_NEW_MAIL));
        tbText.loadFromRes(STR_EMAIL_FTO_RESEND_MAIL_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_RESEND, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND));
        tbText.loadFromRes(STR_EMAIL_FTO_MAIL_BOXES_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_MORE_FOLDERS, tbText, VfxResId(IMG_EMAIL_FTO_TB_MAILBOXES));
        tbText.loadFromRes(STR_GLOBAL_DELETE);
        mToolbar->addItem(MSG_LIST_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
    }

    if(m_listProvider->getCount() == 0)
    {
        VfxWString tbText;
        tbText.loadFromRes(STR_EMAIL_FTO_RESEND_MAIL_ID);
        mToolbar->changeItem(
            MSG_LIST_PAGE_TB_RESEND,
            tbText,
            VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND));
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_RESEND, VFX_TRUE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_TRUE);
    }
    else
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_FALSE);
        VappEmailStateEnum emailState;
        if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
        {
            mToolbar->setDisableItem(MSG_LIST_PAGE_TB_RESEND, VFX_FALSE);
        }
        else
        {
            mToolbar->setDisableItem(MSG_LIST_PAGE_TB_RESEND, VFX_TRUE);
        }
        VfxWString tbText;
        if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
            VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
        {
#ifdef __MMI_EMAIL_IMAP_PUSH__
            if (!VappEmailMgr::getInstance()->isPushRefreshing(m_acctID)) /* not disable resent when push refreshing */
#endif
            {
                mToolbar->setDisableItem(MSG_LIST_PAGE_TB_RESEND, VFX_TRUE);
            }
        }
        else
        {
            mToolbar->setDisableItem(MSG_LIST_PAGE_TB_RESEND, VFX_FALSE);
            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
            {
                tbText.loadFromRes(STR_EMAIL_FTO_STOP_SEND_ID);
                mToolbar->changeItem(
                    MSG_LIST_PAGE_TB_RESEND,
                    tbText,
                    VfxResId(IMG_EMAIL_FTO_TB_STOP));
            }
            else
            {
                tbText.loadFromRes(STR_EMAIL_FTO_RESEND_MAIL_ID);
                mToolbar->changeItem(
                    MSG_LIST_PAGE_TB_RESEND,
                    tbText,
                    VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND));
            }
        }
    }
}


void VappEmailMsgListPage::setSentToolbar()
{
    if (m_TBType != MSG_LIST_PAGE_TB_TYPE_SENT)
    {
        m_TBType = MSG_LIST_PAGE_TB_TYPE_SENT;
        for (VfxU32 i = 0; i < MSG_LIST_PAGE_TB_TOTAL; i++)
        {
            mToolbar->removeItem(i);
        }
        
        VfxWString tbText;
        tbText.loadFromRes(STR_EMAIL_FTO_NEW_EMAIL_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_NEW_MAIL, tbText, VfxResId(IMG_EMAIL_FTO_TB_NEW_MAIL));
        tbText.loadFromRes(STR_GLOBAL_DELETE);
        mToolbar->addItem(MSG_LIST_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
        tbText.loadFromRes(STR_EMAIL_FTO_MAIL_BOXES_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_MORE_FOLDERS, tbText, VfxResId(IMG_EMAIL_FTO_TB_MAILBOXES));
        tbText.loadFromRes(STR_GLOBAL_SORT);
        mToolbar->addItem(MSG_LIST_PAGE_TB_SORT, tbText, VfxResId(IMG_EMAIL_FTO_TB_SORT));
    }

    if(m_listProvider->getCount() == 0)
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_TRUE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_TRUE);
    }
    else
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_FALSE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_FALSE);
    }
}


void VappEmailMsgListPage::setDraftToolbar()
{
    if (m_TBType != MSG_LIST_PAGE_TB_TYPE_DRAFT)
    {
        m_TBType = MSG_LIST_PAGE_TB_TYPE_DRAFT;
        for (VfxU32 i = 0; i < MSG_LIST_PAGE_TB_TOTAL; i++)
        {
            mToolbar->removeItem(i);
        }
        
        VfxWString tbText;
        tbText.loadFromRes(STR_EMAIL_FTO_NEW_EMAIL_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_NEW_MAIL, tbText, VfxResId(IMG_EMAIL_FTO_TB_NEW_MAIL));
        tbText.loadFromRes(STR_GLOBAL_DELETE);
        mToolbar->addItem(MSG_LIST_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
        tbText.loadFromRes(STR_EMAIL_FTO_MAIL_BOXES_ID);
        mToolbar->addItem(MSG_LIST_PAGE_TB_MORE_FOLDERS, tbText, VfxResId(IMG_EMAIL_FTO_TB_MAILBOXES));
        tbText.loadFromRes(STR_GLOBAL_SORT);
        mToolbar->addItem(MSG_LIST_PAGE_TB_SORT, tbText, VfxResId(IMG_EMAIL_FTO_TB_SORT));
    }

    if(m_listProvider->getCount() == 0)
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_TRUE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_TRUE);
    }
    else
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SORT, VFX_FALSE);
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_DELETE, VFX_FALSE);
    }
}


srv_email_result_enum VappEmailMsgListPage::getFldrIDandTypeByBtn(MsgListPageMoreBoxesTypeEnum btnType)
{
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_result_enum result;
    EMAIL_FLDR_ID fldrIDArray[4];
    S32 fldrCount = 4;

    do
    {
        result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_open(acctHandle, m_acctID);
        result = srv_email_acct_get_fldr_id(
                    acctHandle,
                    SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
                    0,
                    &fldrCount,
                    fldrIDArray);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        switch (btnType)
        {
        case MSG_LIST_PAGE_MORE_BOXES_TYPE_INBOX:
            m_fldrType = SRV_EMAIL_FLDR_TYPE_INBOX;
            m_fldrID = fldrIDArray[0];
            break;
        case MSG_LIST_PAGE_MORE_BOXES_TYPE_DRAFTS:
            m_fldrType = SRV_EMAIL_FLDR_TYPE_DRAFT;
            m_fldrID = fldrIDArray[3];
            break;
        case MSG_LIST_PAGE_MORE_BOXES_TYPE_OUTBOX:
            m_fldrType = SRV_EMAIL_FLDR_TYPE_OUTBOX;
            m_fldrID = fldrIDArray[1];
            break;
        case MSG_LIST_PAGE_MORE_BOXES_TYPE_SENT:
            m_fldrType = SRV_EMAIL_FLDR_TYPE_SENT;
            m_fldrID = fldrIDArray[2];
            break;
        default:
            break;
        }
    } while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }

    return result;
}


void VappEmailMsgListPage::updateMultiSelectToolbar()
{
    VfxU32 checkedNum = m_listProvider->getCheckedItemNum();

    if (checkedNum == 0)
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SELECT_DELETE, VFX_TRUE);
    }
    else
    {
        mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SELECT_DELETE, VFX_FALSE);
    }

    if (checkedNum == m_listProvider->getCount())
    {
        m_allSelected = VFX_TRUE;
        mToolbar->changeItem(
            MSG_LIST_PAGE_TB_SELECT_ALL,
            VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL),
            VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_allSelected = VFX_FALSE;
        mToolbar->changeItem(
            MSG_LIST_PAGE_TB_SELECT_ALL,
            VFX_WSTR_RES(STR_GLOBAL_MARK_ALL),
            VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
}


void VappEmailMsgListPage::onTBClick(VfxObject *object, VfxId tbIndex)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_TOOLBAR_CLICK, tbIndex, m_fldrType);

    m_listMenu->stopScrolling();

    VfxRect bounds = getBounds();

    switch (tbIndex)
    {
    case MSG_LIST_PAGE_TB_NEW_MAIL:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(m_acctID, EMAIL_MSG_INVALID_ID, VappEmailComp::EMAIL_MODE_NEW);
        }
        break;
    case MSG_LIST_PAGE_TB_REFRESH:
        {
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_INBOX && m_fldrType != SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                return;
            }

            if (VappEmailMgr::getInstance()->getEmailAppState() == VAPP_EMAIL_STATE_FLIGHT_MODE)
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
                return;
            }

            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_EMAIL_FTO_SENDING_CANNOT_REFRESH));
                return;
            }

            VfxWString tbText;
            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
            {
                VappEmailMgr::getInstance()->cancelAcctRefresh(m_acctID);
                tbText.loadFromRes(STR_GLOBAL_REFRESH);
                mToolbar->changeItem(
                    MSG_LIST_PAGE_TB_REFRESH,
                    tbText,
                    VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH));
            }
            else
            {
                if (VappEmailMgr::getInstance()->refreshAcct(m_acctID) == VAPP_EMAIL_RES_WOULDBLOCK)
                {
                    tbText.loadFromRes(STR_EMAIL_FTO_STOP_REFRESH_ID);
                    mToolbar->changeItem(
                        MSG_LIST_PAGE_TB_REFRESH,
                        tbText,
                        VfxResId(IMG_EMAIL_FTO_TB_STOP));
                }
                else
                {
                    /* popup */
                }
            }
        }
        break;
    case MSG_LIST_PAGE_TB_MORE_FOLDERS:
        {
            srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
            VcpCommandPopup *moreFolderPopup;
            VFX_OBJ_CREATE(moreFolderPopup, VcpCommandPopup, this);
            VfxWString text;
            text.loadFromRes(STR_EMAIL_FTO_MAIL_BOXES_ID);
            moreFolderPopup->setText(text);
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_INBOX)
            {
                text.loadFromRes(STR_GLOBAL_INBOX);
                moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_INBOX, text);
            }
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_DRAFT)
            {
                text.loadFromRes(STR_GLOBAL_DRAFTS);
                moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_DRAFTS, text);
            }
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_OUTBOX)
            {
                text.loadFromRes(STR_GLOBAL_OUTBOX);
                moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_OUTBOX, text);
            }
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_SENT)
            {
                text.loadFromRes(STR_EMAIL_SENT_ID);
                moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_SENT, text);
            }

        #ifdef __MMI_EMAIL_REMOTE_FOLDER__
            S32 remoteNum = 0;
            EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
            do
            {
                result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_acct_open(acctHandle, m_acctID);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_acct_get_fldr_num(
                            acctHandle,
                            SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                            &remoteNum);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
            } while(0);
            if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
            {
                srv_email_acct_destroy(acctHandle);
            }
            if (result == SRV_EMAIL_RESULT_SUCC && remoteNum != 0)
            {
                text.loadFromRes(STR_EMAIL_FTO_REMOTE_FOLDER);
                moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_REMOTE_FOLDER, text);
            }
        #endif /* __MMI_EMAIL_REMOTE_FOLDER__ */
            text.loadFromRes(STR_GLOBAL_CANCEL);
            moreFolderPopup->addItem(MSG_LIST_PAGE_MORE_BOXES_TYPE_CANCEL, text, VCP_POPUP_BUTTON_TYPE_CANCEL);
            moreFolderPopup->m_signalButtonClicked.connect(this, &VappEmailMsgListPage::onMoreFolderClick);
            moreFolderPopup->show(VFX_TRUE);
        } while(0);
        break;
    case MSG_LIST_PAGE_TB_SORT:
        {
            // no sort toolbar item in outbox
            if ((m_fldrType == SRV_EMAIL_FLDR_TYPE_INBOX || m_fldrType == SRV_EMAIL_FLDR_TYPE_REMOTE) &&
               (VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING ||
                VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVE_WAITING))
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_EMAIL_REFRESHING_CANNOT_SORT));
                return;
            }
            /* when refresh or send this account, could not sort
             * in case of message number chanegs of this folder
             */
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_SENT)
            {
                VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(m_acctID);
                if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
                    acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_REFRESHING_CANNOT_SORT));
                    return;
                }
                else if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                         acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_SENDING_CANNOT_SORT));
                    return;
                }
            }

            VcpCommandPopup *sortPopup;
            VFX_OBJ_CREATE(sortPopup, VcpCommandPopup, this);
            VfxWString text;
            text.loadFromRes(STR_GLOBAL_SORT);
            sortPopup->setText(text);
            text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_SIZE_ID);
            sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_SIZE, text);
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_INBOX || m_fldrType == SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_SENDER_ID);
            }
            else
            {
                text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_RECIPIENT_ID);
            }
            sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_RECIPIENT, text);
            text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_SUBJECT_ID);
            sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_SUBJECT, text);
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_INBOX || m_fldrType == SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_READ_STAUTS_ID);
                sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_READ_STATUS, text);
            }
            text.loadFromRes(STR_EMAIL_FTO_FOLDER_SORT_TIME_ID);
            sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_TIME, text);
            text.loadFromRes(STR_GLOBAL_CANCEL);
            sortPopup->addItem(MSG_LIST_PAGE_SORT_TYPE_CANCEL, text, VCP_POPUP_BUTTON_TYPE_CANCEL);
            sortPopup->m_signalButtonClicked.connect(this, &VappEmailMsgListPage::onSortTypeClick);
            sortPopup->show(VFX_TRUE);
        }
        break;
    case MSG_LIST_PAGE_TB_RESEND:
        {
            if (m_fldrType != SRV_EMAIL_FLDR_TYPE_OUTBOX)
            {
                return;
            }

            if (VappEmailMgr::getInstance()->getEmailAppState() == VAPP_EMAIL_STATE_FLIGHT_MODE)
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
                return;
            }

            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
            {
#ifdef __MMI_EMAIL_IMAP_PUSH__
                if (!VappEmailMgr::getInstance()->isPushRefreshing(m_acctID)) /* not disable resent when push refreshing */
#endif
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_REFRESHING_CANNOT_SEND));
                        return;
                }
            }

            VfxWString tbText;
            if (VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                VappEmailMgr::getInstance()->getAcctState(m_acctID) == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
            {
                VappEmailMgr::getInstance()->cancelSendOutbox(m_acctID);
                tbText.loadFromRes(STR_EMAIL_FTO_RESEND_MAIL_ID);
                mToolbar->changeItem(
                    MSG_LIST_PAGE_TB_RESEND,
                    tbText,
                    VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND));
            }
            else
            {
                if (VappEmailMgr::getInstance()->sendOutbox(m_acctID) == VAPP_EMAIL_RES_WOULDBLOCK)
                {
                    tbText.loadFromRes(STR_EMAIL_FTO_STOP_SEND_ID);
                    mToolbar->changeItem(
                        MSG_LIST_PAGE_TB_RESEND,
                        tbText,
                        VfxResId(IMG_EMAIL_FTO_TB_STOP));
                }
                else
                {
                    /* popup */
                }
            }
            m_listMenu->resetAllItems(VFX_TRUE);
        }
        break;
    case MSG_LIST_PAGE_TB_DELETE:
        {
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_OUTBOX &&
               (VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING ||
                VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING))
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_EMAIL_SENDING_CANNOT_DELETE));
                return;
            }
            if ((m_fldrType == SRV_EMAIL_FLDR_TYPE_INBOX || m_fldrType == SRV_EMAIL_FLDR_TYPE_REMOTE) &&
               (VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING ||
                VappEmailMgr::getInstance()->getFldrState(m_acctID, m_fldrID) == VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVE_WAITING))
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(STR_EMAIL_REFRESHING_CANNOT_DELETE));
                return;
            }
            /* when refresh or send this account, could not multi selection delete
             * in case of message number chanegs of this folder
             */
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_SENT)
            {
                VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(m_acctID);
                if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING ||
                    acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING)
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_REFRESHING_CANNOT_DELETE));
                    return;
                }
                else if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
                         acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_SENDING_CANNOT_DELETE));
                    return;
                }
            }

            VappEmailResEnum mgrResult = VappEmailMgr::getInstance()->editFldrStart(m_acctID, m_fldrID);
            if (mgrResult != VAPP_EMAIL_RES_SUCC)
            {
                /* popup */
                break;
            }
            m_TBType = MSG_LIST_PAGE_TB_TYPE_NONE;
            m_allSelected = VFX_FALSE;
            m_multiSelection = VFX_TRUE;
            m_listProvider->getCheckBoxList();
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
            m_listMenu->resetAllItems(VFX_TRUE);

            for (VfxU32 i = 0; i < MSG_LIST_PAGE_TB_TOTAL; i++)
            {
                mToolbar->removeItem(i);
            }
            VfxWString tbText;
            tbText.loadFromRes(STR_GLOBAL_MARK_ALL);
            mToolbar->addItem(MSG_LIST_PAGE_TB_SELECT_ALL, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL));
            tbText.loadFromRes(STR_GLOBAL_DELETE);
            mToolbar->addItem(MSG_LIST_PAGE_TB_SELECT_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
            mToolbar->setDisableItem(MSG_LIST_PAGE_TB_SELECT_DELETE, VFX_TRUE);
            tbText.loadFromRes(STR_GLOBAL_CANCEL);
            mToolbar->addItem(MSG_LIST_PAGE_TB_CANCEL, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL));
        }
        break;
    case MSG_LIST_PAGE_TB_SELECT_ALL:
        {
            VfxWString text;
            VfxU8 check = 0;
            VfxResId imageID = VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL;
            if (m_allSelected)
            {
                imageID = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
                text.loadFromRes(STR_GLOBAL_MARK_ALL);
                m_allSelected = VFX_FALSE;
                check = 0;
            }
            else
            {
                text.loadFromRes(STR_GLOBAL_UNMARK_ALL);
                m_allSelected = VFX_TRUE;
                check = 1;
            }
            m_listProvider->selectAllCheckBox(check);
            mToolbar->changeItem(MSG_LIST_PAGE_TB_SELECT_ALL, text, imageID);
            m_listMenu->resetAllItems(VFX_TRUE);
            updateMultiSelectToolbar();
        }
        break;
    case MSG_LIST_PAGE_TB_SELECT_DELETE:
        {
            VFX_OBJ_CREATE(m_deleteConfirmPopup, VcpConfirmPopup, this);
            m_deleteConfirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_deleteConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            VfxU32 checkedNum = m_listProvider->getCheckedItemNum();
            VfxWString text;
            VfxWString countText;
            VfxWString questionMarkText;
            if (checkedNum == 1)
            {
                text.loadFromRes(STR_EMAIL_FTO_DEL_SELECTED_MAIL_ID);
            }
            else
            {
                text.loadFromRes(STR_EMAIL_FTO_DEL_SELECTED_MAILS_ID);
            }
            countText.format("%d", checkedNum);
            questionMarkText.loadFromRes(STR_EMAIL_FTO_QUESTION_MARK_ID);
            text += countText;
            text += questionMarkText;
            m_deleteConfirmPopup->setText(text);
            VfxWString btnText1;
            btnText1.loadFromRes(STR_GLOBAL_DELETE);
            VfxWString btnText2;
            btnText2.loadFromRes((VfxResId)STR_GLOBAL_CANCEL);
            m_deleteConfirmPopup->setCustomButton(
                btnText1,
                btnText2,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_deleteConfirmPopup->m_signalButtonClicked.connect(
                this,
                &VappEmailMsgListPage::onDeleteConfirmBtnClick);
            m_deleteConfirmPopup->setAutoDestory(VFX_FALSE);
            m_deleteConfirmPopup->show(VFX_TRUE);
        }
        break;
    case MSG_LIST_PAGE_TB_CANCEL:
        {
            VappEmailMgr::getInstance()->editFldrStop(m_acctID, m_fldrID);
            m_allSelected = VFX_FALSE;
            m_multiSelection = VFX_FALSE;
            m_listProvider->freeCheckBoxList();
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
            m_listMenu->resetAllItems(VFX_TRUE);
            updateToolbar();
        }
        break;
    default:
        return;
    }
}


void VappEmailMsgListPage::onItemClick(VcpListMenu *menu, VfxU32 index)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ITEM_CLICK, index, m_multiSelection);

    if (m_multiSelection)
    {
        m_listProvider->checkBoxClick(index);
        updateMultiSelectToolbar();
        return;
    }

    m_index = m_listProvider->getIndexMap(index);

    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    kal_bool isValid;
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
    srv_email_result_enum result;
    U32 msgCount = 1;

    do
    {
        result = srv_email_fldr_get_msg_list(m_listProvider->getFldrHandle(), (U32)m_index, &msgCount, msgInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        msgID = msgInfo->msg_id;
        result = srv_email_msg_check_valid(msgID, &isValid);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
    } while(0);

    free_ctrl_buffer(msgInfo);

    if (result == SRV_EMAIL_RESULT_SUCC && isValid)
    {
        if (m_fldrType == SRV_EMAIL_FLDR_TYPE_DRAFT)
        {
            msgID = m_listProvider->getMsgIDByIndex(m_index);
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, msgID, VappEmailComp::EMAIL_MODE_EDIT);
        }
        else
        {
            if (m_fldrType == SRV_EMAIL_FLDR_TYPE_OUTBOX)
            {
                VappEmailMsgStateEnum  msgState = VappEmailMgr::getInstance()->getMsgState(msgID);
                if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING ||
                    msgState == VAPP_EMAIL_MSG_STATE_NETWORK_WAITING)
                {
                    VFX_OBJ_CREATE(m_errorPopup, VappEmailErrorPopup, this);
                    m_errorPopup->m_signalButtonClicked.connect(
                        this,
                        &VappEmailMsgListPage::onErrorPopupClicked);
                    m_errorPopup->showErrorPopup(STR_EMAIL_FTO_SENDING_CANNOT_OPEN_ID);
                    return;
                }
            }
            VfxMainScr *mainScr = getMainScr();
            VappEmailMsgViewPage *msgViewPage;
            VFX_OBJ_CREATE_EX(msgViewPage, VappEmailMsgViewPage, mainScr, (m_acctID, m_fldrID, msgID));
            VfxU32 unreadMsgNum;
            VfxU32 msgNum;
            m_listProvider->getMsgNum(unreadMsgNum, msgNum);
            mainScr->pushPage(EMAIL_PAGE_TYPE_MSG_VIEW, msgViewPage);
        }
    }
    else
    {
        if (isValid == KAL_FALSE)
        {
            /* to delete right msg */
            m_longTappedMsgID = msgID;
            VFX_OBJ_CREATE(m_deleteConfirmPopup, VcpConfirmPopup, this);
            m_deleteConfirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_deleteConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_deleteConfirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_BROKEN_EMAIL_DELETE_ID));
            VfxWString btnText1;
            btnText1.loadFromRes((VfxResId)STR_GLOBAL_DELETE);
            VfxWString btnText2;
            btnText2.loadFromRes((VfxResId)STR_GLOBAL_CANCEL);
            m_deleteConfirmPopup->setCustomButton(
                btnText1,
                btnText2,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_deleteConfirmPopup->m_signalButtonClicked.connect(
                this,
                &VappEmailMsgListPage::onDeleteConfirmBtnClick);
            m_deleteConfirmPopup->setAutoDestory(VFX_FALSE);
            m_deleteConfirmPopup->show(VFX_TRUE);
            return;
        }
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
            errorPopup->showErrorPopup(result);
        }
    }
}


void VappEmailMsgListPage::onItemLongTapped(VcpListMenu *listMenu, VfxU32 index)
{
    if (m_multiSelection == VFX_TRUE)
    {
        return;
    }

    EMAIL_MSG_ID currSendingMsgID = EMAIL_MSG_INVALID_ID;
    VfxBool isSendingMsg = VappEmailMgr::getInstance()->getCurrSendingMsg(currSendingMsgID);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_ITEM_LONG_TAP,
        index,
        m_fldrType,
        isSendingMsg,
        currSendingMsgID);

    if (m_fldrType == SRV_EMAIL_FLDR_TYPE_OUTBOX && index == 0 && isSendingMsg == VFX_TRUE)
    {
        /* The first mail in outbox is sending, can't delete */
        return;
    }

    m_index = m_listProvider->getIndexMap(index);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ITEM_LONG_TAP, m_index);

    VFX_OBJ_CREATE(m_selectPopup, VcpMenuPopup, this);
    m_selectPopup->setTitle(VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_OPTIONS_ID));
    m_selectPopup->setIsAutoClose(VFX_TRUE);
    VappEmailStateEnum emailState;

    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U32 msgCount = 1;
    result = srv_email_fldr_get_msg_list(m_listProvider->getFldrHandle(), (U32)index, &msgCount, msgInfo);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(msgInfo);
        return;
    }
    m_longTappedMsgID = msgInfo->msg_id;

    VfxWString text;
    switch (m_fldrType)
    {
    case SRV_EMAIL_FLDR_TYPE_INBOX:
    case SRV_EMAIL_FLDR_TYPE_REMOTE:
        {
            VfxBool hasSender = VFX_FALSE;
            if (msgInfo->addr.disp_name != 0 || msgInfo->addr.email_addr[0] != 0)
            {
                hasSender = VFX_TRUE;
            }
            if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
            {
                if (hasSender)
                {
                    text.loadFromRes(STR_GLOBAL_REPLY);
                    m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_REPLY, text);
                }
                text.loadFromRes(STR_GLOBAL_FORWARD);
                m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_FORWARD, text);
            }
            text.loadFromRes(STR_GLOBAL_DELETE);
            m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_DELETE, text);
            if (msgInfo->flag & EMAIL_MSG_FLAG_SEEN)
            {
                text.loadFromRes(STR_EMAIL_FTO_MARK_UNREAD_ID);
                m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_MARK_AS_UNREAD, text);
            }
        }
        break;
    case SRV_EMAIL_FLDR_TYPE_OUTBOX:
        text.loadFromRes((VfxResId)STR_GLOBAL_DELETE);
        m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_DELETE, text);
        break;
    case SRV_EMAIL_FLDR_TYPE_SENT:
        text.loadFromRes((VfxResId)STR_GLOBAL_FORWARD);
        m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_FORWARD, text);
        text.loadFromRes((VfxResId)STR_GLOBAL_DELETE);
        m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_DELETE, text);
        break;
    case SRV_EMAIL_FLDR_TYPE_DRAFT:
        {
            srv_email_msg_get_basic_info_struct *basicInfo = NULL;
            VfxBool hasRecipient = VFX_FALSE;

            do
            {
                EMAIL_MSG_HANDLE msgHandle = EMAIL_MSG_INVALID_HANDLE;
                result = srv_email_msg_create(gEmailSrvHandle, &msgHandle);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = srv_email_msg_open(msgHandle, m_acctID, m_fldrID, msgInfo->msg_id);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                basicInfo =
                    (srv_email_msg_get_basic_info_struct*)get_ctrl_buffer(sizeof(srv_email_msg_get_basic_info_struct));
                result = srv_email_msg_get_basic_info(msgHandle, basicInfo);
                srv_email_msg_destroy(msgHandle);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                if (basicInfo->to_addr_num != 0 || basicInfo->cc_addr_num != 0 || basicInfo->bcc_addr_num != 0)
                {
                    hasRecipient = VFX_TRUE;
                }
            } while (0);

            if (msgInfo != NULL)
            {
                /* there is "return" after */
                free_ctrl_buffer(msgInfo);
                msgInfo = NULL;
            }
            if (basicInfo != NULL)
            {
                free_ctrl_buffer(basicInfo);
            }
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                return;
            }

            if (VappEmailMgr::getInstance()->isNetworkReady(emailState) &&
                VappEmailMgr::getInstance()->getEmailAppState() != VAPP_EMAIL_STATE_FLIGHT_MODE &&
                hasRecipient == VFX_TRUE)
            {
                text.loadFromRes((VfxResId)STR_GLOBAL_SEND);
                m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_SEND, text);
            }
            text.loadFromRes((VfxResId)STR_GLOBAL_DELETE);
            m_selectPopup->addItem(MSG_LIST_PAGE_LONG_TAP_DELETE, text);
        }
        break;
    default:
        return;
    }

    if (msgInfo != NULL)
    {
        free_ctrl_buffer(msgInfo);
        msgInfo = NULL;
    }

    m_selectPopup->m_signalMenuCallback.connect(this, &VappEmailMsgListPage::onLongTapMenuItemClick);
    m_selectPopup->showMenu();

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);    
}


void VappEmailMsgListPage::onLongTapMenuItemClick(
        VcpMenuPopup *menu,
        VcpMenuPopupEventEnum eventType,
        VcpMenuPopupItem *item)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ITEM_LONG_TAP_MENU_CLICK, eventType);

    if (eventType == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        VfxId id = item->getId();
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ITEM_LONG_TAP_MENU_CLICK_2, id);
        switch (id)
        {
        case MSG_LIST_PAGE_LONG_TAP_REPLY:
            {
                //EMAIL_MSG_ID msgID = m_listProvider->getMsgIDByIndex(m_index);
                VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
                mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, m_longTappedMsgID, VappEmailComp::EMAIL_MODE_REPLY);
            }
            break;
        case MSG_LIST_PAGE_LONG_TAP_FORWARD:
            {
                //EMAIL_MSG_ID msgID = m_listProvider->getMsgIDByIndex(m_index);
                VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
                mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, m_longTappedMsgID, VappEmailComp::EMAIL_MODE_FWD);
            }
            break;
        case MSG_LIST_PAGE_LONG_TAP_DELETE:
            {
                VFX_OBJ_CREATE(m_deleteConfirmPopup, VcpConfirmPopup, this);
                m_deleteConfirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
                m_deleteConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
                m_deleteConfirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_DEL_SEL_MAIL_ID));
                VfxWString btnText1;
                btnText1.loadFromRes((VfxResId)STR_GLOBAL_DELETE);
                VfxWString btnText2;
                btnText2.loadFromRes((VfxResId)STR_GLOBAL_CANCEL);
                m_deleteConfirmPopup->setCustomButton(
                    btnText1,
                    btnText2,
                    VCP_POPUP_BUTTON_TYPE_WARNING,
                    VCP_POPUP_BUTTON_TYPE_CANCEL);
                m_deleteConfirmPopup->m_signalButtonClicked.connect(
                    this,
                    &VappEmailMsgListPage::onDeleteConfirmBtnClick);
                m_deleteConfirmPopup->setAutoDestory(VFX_FALSE);
                m_deleteConfirmPopup->show(VFX_TRUE);
            }
            break;
        case MSG_LIST_PAGE_LONG_TAP_MARK_AS_UNREAD:
            {
                /* should handle return value */
                m_listProvider->markAsUnread(m_longTappedMsgID);
            }
            break;
        case MSG_LIST_PAGE_LONG_TAP_MOVE_TO_DRAFT:
            {
                srv_email_result_enum result;
                EMAIL_FLDR_ID fldrID = EMAIL_FLDR_INVALID_ID;
                fldrID = srv_email_fldr_type_to_fldr_id(m_acctID, SRV_EMAIL_FLDR_TYPE_DRAFT);
                result = m_listProvider->moveMsgToFolder(fldrID, m_longTappedMsgID);

                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    vapp_email_alert_cfm(vapp_email_util_get_err_code(SRV_EMAIL_MAIL_ERROR, result));
                    return;
                }

                m_listMenu->resetAllItems(VFX_TRUE);
            }
            break;
        case MSG_LIST_PAGE_LONG_TAP_SEND:
            {
                /* in drafts, first move message to outbox then send outbox */
                srv_email_result_enum result;
                EMAIL_FLDR_ID fldrID = EMAIL_FLDR_INVALID_ID;
                fldrID = srv_email_fldr_type_to_fldr_id(m_acctID, SRV_EMAIL_FLDR_TYPE_OUTBOX);
                result = m_listProvider->moveMsgToFolder(fldrID, m_longTappedMsgID);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    vapp_email_alert_cfm(vapp_email_util_get_err_code(SRV_EMAIL_MAIL_ERROR, result));
                    return;
                }
                m_listMenu->resetAllItems(VFX_TRUE);
                VappEmailMgr::getInstance()->sendOutbox(m_acctID);
            }
            break;
        default:
            return;
        }
        if (id != MSG_LIST_PAGE_LONG_TAP_DELETE)
        {
            m_longTappedMsgID = EMAIL_MSG_INVALID_ID;
        }
    }
    else if (eventType == VCP_MENU_POPUP_EVENT_MENU_CANCEL)
    {
        m_longTappedMsgID = EMAIL_MSG_INVALID_ID;
    }
    //VFX_OBJ_CLOSE(m_selectPopup);
    m_selectPopup = NULL;
}


void VappEmailMsgListPage::onSortTypeClick(VfxObject *, VfxId id)
{
    m_listProvider->sortMsg((MsgListPageSortTypeEnum)id);
}


void VappEmailMsgListPage::onMoreFolderClick(VfxObject *, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_MORE_FOLDER_CLICK, m_fldrType, id);

    if (id >= MSG_LIST_PAGE_MORE_BOXES_TYPE_CANCEL)
    {
        return;
    }

    if (id == MSG_LIST_PAGE_MORE_BOXES_TYPE_REMOTE_FOLDER)
    {
        VappEmailMsgListRemoteFolderPage *remoteFolderListPage;
        VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
        VFX_OBJ_CREATE_EX(remoteFolderListPage, VappEmailMsgListRemoteFolderPage, mainScr, (m_acctID));
        mainScr->pushPage(EMAIL_PAGE_TYPE_REMOTE_FOLDER_LIST, remoteFolderListPage);
        return;
    }

    srv_email_result_enum result = getFldrIDandTypeByBtn((MsgListPageMoreBoxesTypeEnum)id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        /* should not failed */
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_REMOTE_FOLDER_LIST);
    }

    ((VappEmailMainScrn*)getMainScr())->setCurrFldr(m_fldrID);
    m_isDeleteOutboxMsg = VFX_FALSE;
    m_listProvider->resetProvider(m_acctID, m_fldrID);
    if (m_listMenu != NULL)
    {
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    }

    updateTitleBarText();
}


void VappEmailMsgListPage::updateMsgList()
{
    if (m_listMenu == NULL)
    {
        VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
        VfxSize pageSize = getSize();
        m_listMenu->setContentProvider(m_listProvider);
        m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT_EX);
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgListPage::onItemClick);
        m_listMenu->m_signalItemLongTapped.connect(this, &VappEmailMsgListPage::onItemLongTapped);
        m_listProvider->setMenu(m_listMenu);
        m_listMenu->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    else
    {
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->resetAllItems(VFX_TRUE);
    }
}


void VappEmailMsgListPage::onTitleBarLBtnClick(VfxObject *, VfxId)
{
    EMAIL_ACCT_ID acctID;
    EMAIL_FLDR_ID fldrID;
    VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
    mainScrn->getPrevAcctnFldr(acctID, fldrID);
    /* clear multi selection check box */
    onTBClick(NULL, MSG_LIST_PAGE_TB_CANCEL);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_TITLE_LBTN_CLICK,
        acctID,
        fldrID,
        srv_email_fldr_id_to_fldr_type(acctID, fldrID));
    resetPage(acctID, fldrID, srv_email_fldr_id_to_fldr_type(acctID, fldrID));
}


void VappEmailMsgListPage::onTitleBarRBtnClick(VfxObject *, VfxId)
{
    EMAIL_ACCT_ID acctID;
    EMAIL_FLDR_ID fldrID;
    VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
    mainScrn->getNextAcctnFldr(acctID, fldrID);
    /* clear multi selection check box */
    onTBClick(NULL, MSG_LIST_PAGE_TB_CANCEL);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_TITLE_RBTN_CLICK,
        acctID,
        fldrID,
        srv_email_fldr_id_to_fldr_type(acctID, fldrID));
    resetPage(acctID, fldrID, srv_email_fldr_id_to_fldr_type(acctID, fldrID));
}


void VappEmailMsgListPage::onDeleteConfirmBtnClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_DELETE_CONFIRM_CLICK, id);

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1 || id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        VappEmailMgr::getInstance()->editFldrStop(m_acctID, m_fldrID);
        if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
        {
            return;
        }

        if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX)
        {
            m_isDeleteOutboxMsg = VFX_TRUE;
        }
        srv_email_result_enum result;
        if (m_multiSelection)
        {
            m_allSelected = VFX_FALSE;
            m_multiSelection = VFX_FALSE;
            result = m_listProvider->markMsg(VFX_TRUE);
            m_listProvider->freeCheckBoxList();
            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                result = m_listProvider->deleteMsg();
            }
        }
        else
        {
            result = m_listProvider->deleteMsg(m_longTappedMsgID);
        }
        providerUpdated(result, VFX_TRUE);
    }

    m_longTappedMsgID = EMAIL_MSG_INVALID_ID;
    VFX_OBJ_CLOSE(m_deleteConfirmPopup);
    m_deleteConfirmPopup = NULL;
}


void VappEmailMsgListProvider::generalAsyncCallback(
    srv_email_result_struct *result,
    EMAIL_REQ_ID req_id,
    void *user_data)
{
    VappEmailMsgListProvider *currObj = (VappEmailMsgListProvider*)user_data;
    currObj->m_isReady = VFX_TRUE;
    
    VappEmailMsgListPage *msgListPage = (VappEmailMsgListPage*)(currObj->getParent());
    msgListPage->generalAsyncCallback(result, req_id, user_data);
}


VappEmailMsgListProvider::VappEmailMsgListProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID)
    :m_fldrHandle(EMAIL_FLDR_INVALID_HANDLE),
     m_acctID(acctID),
     m_fldrID(fldrID),
     m_checkBoxList(NULL),
     m_sendFailMsgNum(0),
     m_currMsgNum(0),
     m_isReady(VFX_FALSE)
{
}


void VappEmailMsgListProvider::onInit()
{
    initProvider(m_acctID, m_fldrID);
}


void VappEmailMsgListProvider::onDeinit()
{    
    if (m_checkBoxList != NULL)
    {
        free_ctrl_buffer(m_checkBoxList);
        m_checkBoxList = NULL;
    }

    if (m_fldrHandle)
    {
        srv_email_fldr_clear_callback(m_fldrHandle);
    }
}


void VappEmailMsgListProvider::setMenu(VcpListMenu* listMenu)
{
    m_listMenu = listMenu;
}


VfxBool VappEmailMsgListProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &textColor)
{
    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            srv_email_fldr_msg_info_struct *msgInfo =
                (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
            srv_email_result_enum result;
            U32 msgCount = 1;

            do
            {
                result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)getIndexMap(index), &msgCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                if (msgInfo->addr.disp_name_len != 0)
                {
                    textString.loadFromMem((VfxWChar*)msgInfo->addr.disp_name);
                }
                else if (msgInfo->addr.email_addr[0] != 0)
                {
                    textString.loadFromMem((VfxWChar*)msgInfo->addr.email_addr);
                }
                else
                {
                    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) != SRV_EMAIL_FLDR_TYPE_INBOX)
                    {
                        textString.loadFromRes(STR_EMAIL_FTO_NO_RECIPIENT);
                    }
                }
            }while(0);

            free_ctrl_buffer(msgInfo);
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        {
            srv_email_fldr_msg_info_struct *msgInfo =
                (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
            srv_email_result_enum result;
            U32 msgCount = 1;

            do
            {
                result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)getIndexMap(index), &msgCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                if (msgInfo->buff[0] == 0)
                {
                    textString.loadFromRes(STR_EMAIL_FTO_COMMON_NO_SUBJECT_ID);
                }
                else
                {
                    textString.loadFromMem((VfxWChar*)msgInfo->buff);
                }
            } while(0);

            free_ctrl_buffer(msgInfo);
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        {
            srv_email_fldr_msg_info_struct *msgInfo =
                (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
            srv_email_result_enum result;
            U32 msgCount = 1;
            U32 currTime;
            U32 localTime;
            applib_time_struct timeInfo = {0};
            applib_time_struct currTimeInfo = {0};

            result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)getIndexMap(index), &msgCount, msgInfo);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                free_ctrl_buffer(msgInfo);
                return VFX_FALSE;
            }
            localTime = applib_dt_sec_utc_to_local(msgInfo->time);
            free_ctrl_buffer(msgInfo);
            applib_dt_utc_sec_2_mytime(localTime, &timeInfo, MMI_FALSE);
            currTime = app_getcurrtime();
            applib_dt_utc_sec_2_mytime(currTime, &currTimeInfo, MMI_FALSE);
            VfxDateTime dateTime;
            dateTime.setDateTime(&timeInfo);
            if (currTimeInfo.nYear == timeInfo.nYear &&
                currTimeInfo.nMonth == timeInfo.nMonth &&
                currTimeInfo.nDay == timeInfo.nDay)
            {
                textString = dateTime.getDateTimeString(
                                VFX_DATE_TIME_TIME_HOUR |
                                VFX_DATE_TIME_TIME_MINUTE);
            }
            else
            {
                textString = dateTime.getDateTimeString(
                                VFX_DATE_TIME_DATE_MONTH |
                                VFX_DATE_TIME_DATE_DAY);
            }
        }
        break;
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


VfxBool VappEmailMsgListProvider::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (m_isReady)
    {
        text.loadFromRes(STR_EMAIL_FTO_NO_EMAILS_ID);
    }
    else
    {
        text.loadFromRes(STR_GLOBAL_LOADING);
    }
    return VFX_TRUE;
}


VfxBool VappEmailMsgListProvider::getItemImage(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxImageSrc &imageSrc)
{
    U16 iconID = getMsgStatusIcon(fieldType, index);
    imageSrc.setResId(iconID);
    if (iconID == 0)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


void VappEmailMsgListProvider::closeItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldEnum,
        VfxImageSrc imageSrc)
{

}


VfxU32 VappEmailMsgListProvider::getCount(void) const
{
    if (m_checkBoxList != NULL)
    {
        return m_currMsgNum;
    }
    else
    {
        if (!m_isReady)
        {
            return 0;
        }
        
        VfxU32 msgNun = 0;
        srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, (S32*)(&msgNun));
        return msgNun;
    }
}


VcpListMenuItemStateEnum VappEmailMsgListProvider::getItemState(VfxU32 index) const
{
    if (m_checkBoxList != NULL)
    {
        if (m_checkBoxList[index])
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappEmailMsgListProvider::swapItem(VfxU32 first, VfxU32 second)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappEmailMsgListProvider::getItemCustomContentFrame(
                                    VfxU32 index,
                                    VfxFrame *frame)
{
    VappEmailMsgListMenuCell *msgListItem = NULL;
    VFX_OBJ_CREATE_EX(msgListItem, VappEmailMsgListMenuCell, frame, (index));
    return msgListItem;
}


void VappEmailMsgListProvider::closeItemCustomContentFrame(
        VfxU32 index,
        VcpListMenuCellClientBaseFrame *baseFrame)
{
}


VcpListMenu *VappEmailMsgListProvider::getListMenu()
{
    return m_listMenu;
}


VfxBool VappEmailMsgListProvider::getItemTextFrameFormat(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxTextFrame *frame)
{
    return VFX_FALSE;
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}


U16 VappEmailMsgListProvider::getMsgStatusIcon(VcpListMenuFieldEnum fieldType, VfxU32 index)
{
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U32 msgCount = 1;
    U16 iconID = 0;
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
    result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(index), &msgCount, msgInfo);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(msgInfo);
        return iconID;
    }

    if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA2)
    {
        if (msgInfo->has_attach)
        {
            if (msgInfo->priority == EMAIL_MSG_PRIO_MED)
            {
                iconID = IMG_EMAIL_FTO_LIST_ATTCH;
            }
            else if (msgInfo->priority == EMAIL_MSG_PRIO_LOW)
            {
                iconID = IMG_EMAIL_FTO_LIST_PRIO_LOW_ATT;
            }
            else /* EMAIL_MSG_PRIO_HIGH */
            {
                iconID = IMG_EMAIL_FTO_LIST_PRIO_HIGH_ATT;
            }
        }
        else
        {
            if (msgInfo->priority == EMAIL_MSG_PRIO_MED)
            {
                iconID = 0;
            }
            else if (msgInfo->priority == EMAIL_MSG_PRIO_LOW)
            {
                iconID = IMG_EMAIL_FTO_LIST_PRIO_LOW;
            }
            else /* EMAIL_MSG_PRIO_HIGH */
            {
                iconID = IMG_EMAIL_FTO_LIST_PRIO_HIGH;
            }
        }
    }
    else
    {
        if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_INBOX)
        {
            if (msgInfo->state & SRV_EMAIL_MSG_STATE_HEADER_ONLY)
            {
                iconID = IMG_EMAIL_FTO_LIST_HEADER_ONLY;
            }
            else if (msgInfo->state & SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH)
            {
                iconID = IMG_EMAIL_FTO_LIST_UNFINISH;
            }
        }
        else if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX)
        {
            VappEmailMsgStateEnum msgState = VappEmailMgr::getInstance()->getMsgState(msgInfo->msg_id);
            if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
            {
                iconID = IMG_EMAIL_FTO_LIST_MSG_SENDING;
            }
            else if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_WAITING)
            {
                iconID = IMG_EMAIL_FTO_LIST_MSG_WAITING;
            }
            else if (msgState == VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL)
            {
                iconID = IMG_EMAIL_FTO_LIST_MSG_SEND_FAIL;
            }
        }
    }

    free_ctrl_buffer(msgInfo);
    return iconID;
}


void VappEmailMsgListProvider::setProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID)
{
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_SET_PROVIDER,
        acctID,
        fldrID,
        srv_email_fldr_id_to_fldr_type(acctID, fldrID));

    m_acctID = acctID;
    m_fldrID = fldrID;
    srv_email_result_enum result;
    srv_email_fldr_create_info_struct fldrCreateInfo;
    fldrCreateInfo.acct_id = acctID;
    fldrCreateInfo.fldr_id = fldrID;
    fldrCreateInfo.list_field = 0;
    fldrCreateInfo.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE;
    /* cause of SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE sort_order has no effect */
    if (srv_email_fldr_id_to_fldr_type(acctID, fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX)
    {
        fldrCreateInfo.sort_order = MMI_TRUE;
    }
    else
    {
        fldrCreateInfo.sort_order = MMI_FALSE;
    }

    if (fldrCreateInfo.acct_id != gCurrFldrInfo.info.acct_id ||
        fldrCreateInfo.fldr_id != gCurrFldrInfo.info.fldr_id ||
        fldrCreateInfo.sort_mode != gCurrFldrInfo.info.sort_mode ||
        fldrCreateInfo.sort_order != gCurrFldrInfo.info.sort_order ||
        fldrCreateInfo.list_field != gCurrFldrInfo.info.list_field )
    {
        /* enter a new folder */
        if (gCurrFldrInfo.handle != EMAIL_FLDR_INVALID_HANDLE)
        {
            srv_email_fldr_destroy(gCurrFldrInfo.handle);
            gCurrFldrInfo.handle = EMAIL_FLDR_INVALID_HANDLE;
        }
        memcpy(&gCurrFldrInfo.info, &fldrCreateInfo, sizeof(srv_email_fldr_create_info_struct));
        do
        {
            result = srv_email_fldr_create(gEmailSrvHandle, &fldrCreateInfo, &m_fldrHandle);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            gCurrFldrInfo.handle = m_fldrHandle;

            result = srv_email_fldr_regist_callback(m_fldrHandle, &VappEmailMsgListProvider::generalAsyncCallback, this);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            result = srv_email_fldr_list_msg_ext(
                        m_fldrHandle,
                        SRV_EMAIL_MSG_TEXT_SUBJ,
                        SRV_EMAIL_MSG_CREATED_DATE,
                        &m_listReqID);
    
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                m_isReady = VFX_TRUE;
            }
            else
            {
                m_isReady = VFX_FALSE;
            }

            ((VappEmailMsgListPage*)getParent())->providerUpdated(result);
        } while(0);
    }
    else
    {
        m_fldrHandle = gCurrFldrInfo.handle;

        srv_email_fldr_regist_callback(m_fldrHandle, &VappEmailMsgListProvider::generalAsyncCallback, this);
        m_isReady = VFX_TRUE;
    }
}


VfxU32 VappEmailMsgListProvider::getIndexMap(VfxU32 orgIndex)
{
    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) != SRV_EMAIL_FLDR_TYPE_OUTBOX)
    {
        return orgIndex;
    }

    srv_email_result_enum result;
    VfxU32 dstIndex = orgIndex;
    VfxU32 totalMsg = 0;
    result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, (S32*)&totalMsg);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return dstIndex;
    }

    VfxU32 getCount = 1;
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));

    EMAIL_MSG_ID currSendingMsg;
    if (VappEmailMgr::getInstance()->getCurrSendingMsg(currSendingMsg) == VFX_TRUE)
    {
        if (orgIndex == 0)
        {
            for (VfxU16 i = 0; i < totalMsg; i++)
            {
                result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)i, (U32*)&getCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC || getCount != 1)
                {
                    return dstIndex;
                }
                if (VappEmailMgr::getInstance()->getMsgState(msgInfo->msg_id) == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
                {
                    dstIndex = i;
                    break;
                }
            }
        }
        else
        {
            VfxU32 counter = 1;
            VappEmailMsgStateEnum findState = VAPP_EMAIL_MSG_STATE_NETWORK_WAITING;
            if (orgIndex >= totalMsg - m_sendFailMsgNum)
            {
                findState = VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL;
                counter = m_sendFailMsgNum - (totalMsg - orgIndex) + 1;
            }
            else
            {
                counter = orgIndex;
            }
            for (VfxU16 i = 0; i < totalMsg; i++)
            {
                result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)i, (U32*)&getCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC || getCount != 1)
                {
                    return dstIndex;
                }
                if (VappEmailMgr::getInstance()->getMsgState(msgInfo->msg_id) == findState)
                {
                    counter--;
                    if (counter == 0)
                    {
                        dstIndex = i;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        VfxU32 counter = 1;
        VappEmailMsgStateEnum findState = VAPP_EMAIL_MSG_STATE_NETWORK_WAITING;
        if (orgIndex >= totalMsg - m_sendFailMsgNum)
        {
            findState = VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL;
            counter = m_sendFailMsgNum - (totalMsg - orgIndex) + 1;
        }
        else
        {
            counter = orgIndex + 1;
        }
        for (VfxU16 i = 0; i < totalMsg; i++)
        {
            result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)i, (U32*)&getCount, msgInfo);
            if (result != SRV_EMAIL_RESULT_SUCC || getCount != 1)
            {
                return dstIndex;
            }
            if (VappEmailMgr::getInstance()->getMsgState(msgInfo->msg_id) == findState)
            {
                counter--;
                if (counter == 0)
                {
                    dstIndex = i;
                    break;
                }
            }
        }
    }

    free_ctrl_buffer(msgInfo);

    return dstIndex;
}


void VappEmailMsgListProvider::sortMsg(MsgListPageSortTypeEnum sortType)
{
    /* when long time no operation page will be locked and this api will be called by sortType == -1 */
    if ((signed int)sortType < MSG_LIST_PAGE_SORT_TYPE_SIZE || sortType >= MSG_LIST_PAGE_SORT_TYPE_CANCEL)
    {
        return;
    }

    srv_email_fldr_sort_msg_struct *sortInfo =
        (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
    sortInfo->sort_order = MMI_FALSE;
    sortInfo->msg_index = 0;
    sortInfo->msg_id = 0;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_fldr_basic_info_struct basicInfo;
    result = srv_email_fldr_get_basic_info(m_fldrHandle, &basicInfo);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup(result);
        return;
    }

    switch (sortType)
    {
    case MSG_LIST_PAGE_SORT_TYPE_SIZE:
        sortInfo->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_SERVER_SIZE;
        break;
    case MSG_LIST_PAGE_SORT_TYPE_RECIPIENT:
        sortInfo->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_ADDR;
        break;
    case MSG_LIST_PAGE_SORT_TYPE_SUBJECT:
        sortInfo->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_BUFFER;
        break;
    case MSG_LIST_PAGE_SORT_TYPE_READ_STATUS:
        sortInfo->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG;
        break;
    case MSG_LIST_PAGE_SORT_TYPE_TIME:
        sortInfo->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
        break;
    default:
        break;
    }
    if (sortInfo->sort_mode == basicInfo.sort_mode)
    {
        sortInfo->sort_order = (MMI_BOOL)!basicInfo.sort_order;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_SORT,
        basicInfo.sort_mode,
        basicInfo.sort_order,
        sortInfo->sort_mode,
        sortInfo->sort_order);

    srv_email_fldr_sort_msg(m_fldrHandle, sortInfo);
    free_ctrl_buffer(sortInfo);

    m_listMenu->resetAllItems(VFX_TRUE);
}


EMAIL_MSG_ID VappEmailMsgListProvider::getNextMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    srv_email_result_enum result;
    S32 msgNumber = 0;
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    srv_email_fldr_msg_info_struct *msgInfo = NULL;
    U32 msgCount = 1;

    total = 0;
    index = 0;

    do
    {
        result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, &msgNumber);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        total = msgNumber;
        if (msgNumber == 0)
        {
            break;
        }
        msgInfo = (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
        for (S32 i = 0; i < msgNumber; i++)
        {
            result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(i), &msgCount, msgInfo);
            if (result != SRV_EMAIL_RESULT_SUCC || msgCount != 1)
            {
                break;
            }
            if (msgInfo->msg_id == currMsgID)
            {
                i = (i + 1) % msgNumber;
                index = i;
                result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(i), &msgCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC || msgCount != 1)
                {
                    break;
                }
                msgID = msgInfo->msg_id;
                break;
            }
        }
    } while(0);

    if (msgInfo != NULL)
    {
        free_ctrl_buffer(msgInfo);
    }

    return msgID;
}


EMAIL_MSG_ID VappEmailMsgListProvider::getPrevMsgID(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    srv_email_result_enum result;
    S32 msgNumber = 0;
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    srv_email_fldr_msg_info_struct *msgInfo = NULL;
    U32 msgCount = 1;

    total = 0;
    index = 0;

    do
    {
        result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, &msgNumber);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        total = msgNumber;
        if (msgNumber == 0)
        {
            break;
        }
        msgInfo = (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
        for (S32 i = 0; i < msgNumber; i++)
        {
            result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(i), &msgCount, msgInfo);
            if (result != SRV_EMAIL_RESULT_SUCC || msgCount != 1)
            {
                break;
            }
            if (msgInfo->msg_id == currMsgID)
            {
                i = (i + msgNumber - 1) % msgNumber;
                index = i;
                result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(i), &msgCount, msgInfo);
                if (result != SRV_EMAIL_RESULT_SUCC || msgCount != 1)
                {
                    break;
                }
                msgID = msgInfo->msg_id;
                break;
            }
        }
    } while(0);

    if (msgInfo != NULL)
    {
        free_ctrl_buffer(msgInfo);
    }

    return msgID;
}


void VappEmailMsgListProvider::getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    srv_email_result_enum result;
    S32 msgNumber = 0;
    srv_email_fldr_msg_info_struct *msgInfo = NULL;
    U32 msgCount = 1;

    total = 0;
    index = 0;

    do
    {
        result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, &msgNumber);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        total = msgNumber;
        if (msgNumber == 0)
        {
            break;
        }
        msgInfo = (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
        for (S32 i = 0; i < msgNumber; i++)
        {
            result = srv_email_fldr_get_msg_list(m_fldrHandle, getIndexMap(i), &msgCount, msgInfo);
            if (result != SRV_EMAIL_RESULT_SUCC || msgCount != 1)
            {
                break;
            }
            if (msgInfo->msg_id == currMsgID)
            {
                index = i;
                break;
            }
        }
    } while(0);

    if (msgInfo != NULL)
    {
        free_ctrl_buffer(msgInfo);
    }
}


EMAIL_FLDR_HANDLE VappEmailMsgListProvider::getFldrHandle()
{
    return m_fldrHandle;
}


void VappEmailMsgListProvider::resetProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID)
{
    freeCheckBoxList();
    setProvider(acctID, fldrID);
}


void VappEmailMsgListProvider::initProvider(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID)
{
    setProvider(acctID, fldrID);
}


void VappEmailMsgListProvider::getMsgNum(VfxU32 &unreadMsgNum, VfxU32 &msgNum)
{
    unreadMsgNum = 0;
    msgNum = 0;
    srv_email_result_enum result;
    result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, (S32*)(&msgNum));
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return;
    }
    result = srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG_UNREAD, (S32*)(&unreadMsgNum));
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        unreadMsgNum = 0;
        msgNum = 0;
    }
}


void VappEmailMsgListProvider::onMsgListUpdate(srv_email_om_notify_struct *notify_data, void *user_data)
{
    VappEmailMsgListProvider* provider = (VappEmailMsgListProvider*)user_data;
    ((VappEmailMsgListPage*)(provider->getParent()))->onMsgListUpdate();
}


srv_email_result_enum VappEmailMsgListProvider::markMsg(VfxBool markMsg)
{
    U32 msgCount = 1;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    VfxU32 totalMsgNum = getCount();

    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));

    for (U32 i = 0; i < totalMsgNum; i++)
    {
        if (!m_checkBoxList[i])
        {
            continue;
        }
        result = srv_email_fldr_get_msg_list(m_fldrHandle , getIndexMap(i), &msgCount, msgInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            /* memory operation, should not be failed */
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getParent());
            errorPopup->showErrorPopup(result);
            break;
        }
        msgID = msgInfo->msg_id;
        result = srv_email_fldr_mark_msg(m_fldrHandle, MMI_FALSE, msgID, (MMI_BOOL)markMsg);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            /* memory operation, should not be failed */
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getParent());
            errorPopup->showErrorPopup(result);
            break;
        }
    }

    free_ctrl_buffer(msgInfo);
    return result;
}


srv_email_result_enum VappEmailMsgListProvider::markAsUnread(EMAIL_MSG_ID msgID)
{
    srv_email_fldr_set_msg_flag_struct setFlagInfo;
    memset(&setFlagInfo, 0, sizeof(srv_email_fldr_set_msg_flag_struct));
    setFlagInfo.msg_id = msgID;
    setFlagInfo.set_all = MMI_FALSE;
    setFlagInfo.set_all_marked = MMI_FALSE;
    setFlagInfo.msg_flag = !EMAIL_MSG_FLAG_SEEN;
    setFlagInfo.flag_mask = EMAIL_MSG_FLAG_SEEN;

    return srv_email_fldr_set_msg_flag(m_fldrHandle, &setFlagInfo, NULL);
}


srv_email_result_enum VappEmailMsgListProvider::moveMsgToFolder(EMAIL_FLDR_ID fldrID, EMAIL_MSG_ID msgID)
{
    EMAIL_MSG_HANDLE msgHandle = EMAIL_MSG_INVALID_HANDLE;
    srv_email_result_enum result;
    EMAIL_MSG_ID msgIDTemp = msgID;

    do
    {
        result = srv_email_msg_create(gEmailSrvHandle, &msgHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_open(msgHandle, m_acctID, m_fldrID, msgIDTemp);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_move(msgHandle, m_acctID, fldrID, &msgIDTemp);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        srv_email_msg_destroy(msgHandle);
    } while(0);

    if (msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_MOVE_MSG_TO_FOLDER,
        0,
        msgIDTemp,
        fldrID,
        result);

    return result;
}


srv_email_result_enum VappEmailMsgListProvider::deleteMsg(EMAIL_MSG_ID msgID)
{
    srv_email_fldr_delete_msg_struct deleteMsgInfo;
    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_INBOX ||
        srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_REMOTE)
    {
        deleteMsgInfo.delete_header = MMI_FALSE;
    }
    else
    {
        deleteMsgInfo.delete_header = MMI_TRUE;
    }
    deleteMsgInfo.delete_server = MMI_TRUE;
    deleteMsgInfo.delete_all = MMI_FALSE;
    if (msgID == EMAIL_MSG_INVALID_ID)
    {
        deleteMsgInfo.delete_all_marked = MMI_TRUE;
    }
    else
    {
        deleteMsgInfo.delete_all_marked = MMI_FALSE;
        deleteMsgInfo.msg_id = msgID;
    }
    return srv_email_fldr_delete_msg(m_fldrHandle, &deleteMsgInfo, NULL);
}


void VappEmailMsgListProvider::getCheckBoxList()
{
    S32 msgNumber = 0;
    srv_email_fldr_get_msg_num(m_fldrHandle, SRV_EMAIL_FLDR_MSG, &msgNumber);
    m_checkBoxList = (VfxU8*)get_ctrl_buffer(sizeof(VfxU8) * msgNumber);
    memset(m_checkBoxList, 0, sizeof(VfxU8) * msgNumber);
    m_checkedMsg = 0;
    m_currMsgNum = msgNumber;
}


void VappEmailMsgListProvider::selectAllCheckBox(VfxU8 select)
{
    VfxU32 msgNumber = getCount();
    for (VfxU32 i = 0; i < msgNumber; i++)
    {
        m_checkBoxList[i] = select;
    }
    if (select == 1)
    {
        m_checkedMsg = msgNumber;
    }
    else
    {
        m_checkedMsg = 0;
    }
}


EMAIL_MSG_ID VappEmailMsgListProvider::getMsgIDByIndex(VfxU32 index)
{
    EMAIL_MSG_ID msgID = EMAIL_MSG_INVALID_ID;
    srv_email_fldr_msg_info_struct *msgInfo =
        (srv_email_fldr_msg_info_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_struct));
    srv_email_result_enum result;
    U32 msgCount = 1;

    do
    {
        result = srv_email_fldr_get_msg_list(m_fldrHandle, (U32)index, &msgCount, msgInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        msgID = msgInfo->msg_id;
    } while(0);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_GET_ID_BY_INDEX,
        index,
        msgID);

    free_ctrl_buffer(msgInfo);
    return msgID;
}


void VappEmailMsgListTitleBar::onInit()
{
    VfxPageBar::onInit();

    if (m_bgImageFrame == NULL)
    {
        VFX_OBJ_CREATE(m_bgImageFrame, VfxImageFrame, this);
        m_bgImageFrame->setResId(IMG_EMAIL_FTO_TITLEBAR_BG_ID);
        m_bgImageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_bgImageFrame->setRect(0, 0, gScrnWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    }
}


void VappEmailMsgListTitleBar::onSetRotate(VfxScrRotateTypeEnum rotation)
{
    if(m_rotation == rotation)
    {
        return;
    }

    m_rotation = rotation;
    
    updateTitleTextLayout();
    updateTitleBtnLayout();    
}


void VappEmailMsgListTitleBar::updateButtons(VfxBool showSwitchBtn)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_TITLEBAR_UPDATE_BTN, showSwitchBtn);

    VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
    if (showSwitchBtn)
    {
        if (m_leftButton == NULL)
        {
            VFX_OBJ_CREATE(m_leftButton, VcpImageButton, this);
            m_leftButton->setImage(
                VcpStateImage(
                    IMG_EMAIL_FTO_LEFT_ID,
                    IMG_EMAIL_FTO_LEFT_ID,
                    IMG_EMAIL_FTO_LEFT_ID,
                    IMG_EMAIL_FTO_LEFT_ID));
            m_leftButton->setIsEffect(VFX_TRUE);
            m_leftButton->setEffectRatio(1.2f);
            m_leftButton->setEffectOffset(
                VfxPoint(
                EMAIL_MSG_VIEW_HEADER_LEFT_GAP  - 1,
                btnTopGap - 1));
        }
        if (m_rightButton == NULL)
        {
            VFX_OBJ_CREATE(m_rightButton, VcpImageButton, this);
            m_rightButton->setImage(
                VcpStateImage(
                    IMG_EMAIL_FTO_RIGHT_ID,
                    IMG_EMAIL_FTO_RIGHT_ID,
                    IMG_EMAIL_FTO_RIGHT_ID,
                    IMG_EMAIL_FTO_RIGHT_ID));
            m_rightButton->setIsEffect(VFX_TRUE);
            m_rightButton->setEffectRatio(1.2f);
            m_rightButton->setEffectOffset(
                VfxPoint(
                gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - 2,
                btnTopGap - 1));
        }

        VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
        m_leftButton->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, btnTopGap);
        m_leftButton->setBounds(
            VfxRect(
                EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
        m_rightButton->setPos(
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
            btnTopGap);
        m_rightButton->setBounds(
            VfxRect(
                gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
    }
    else
    {
        if (m_leftButton != NULL)
        {
            VFX_OBJ_CLOSE(m_leftButton);
            m_leftButton = NULL;
        }
        if (m_rightButton != NULL)
        {
            VFX_OBJ_CLOSE(m_rightButton);
            m_rightButton = NULL;
        }
    }
}


void VappEmailMsgListTitleBar::updateTitleText(VfxWString &fldrNameText, VfxWString &acctNameText)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_TITLEBAR_UPDATE_TEXT);

    if (m_fldrNameText == NULL)
    {
        VFX_OBJ_CREATE(m_fldrNameText, VfxTextFrame, this);
    }
    if (m_acctNameText == NULL)
    {
        VFX_OBJ_CREATE(m_acctNameText, VfxTextFrame, this);
    }
    VfxWString emptyText;
    emptyText.setEmpty();
    setSize(gScrnWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);

    // adjust postion of two line
    m_acctNameText->setString(acctNameText);
    //m_acctNameText->setString(acctNameText);
    m_acctNameText->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
    m_acctNameText->setColor(VFX_COLOR_WHITE);
    m_acctNameText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_acctNameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    //m_acctNameText->forceUpdate();
    m_acctNameText->setPos(
        VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
        EMAIL_MSG_VIEW_HEADER_TOP_GAP);
    m_acctNameText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_TOP_GAP,
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_acctNameText->getBounds().getHeight()));

    // adjust postion of two line
    m_fldrNameText->setString(fldrNameText);
    //m_fldrNameText->setString(fldrNameText);
    m_fldrNameText->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_SMALL));
    m_fldrNameText->setColor(VFX_COLOR_WHITE);
    m_fldrNameText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_fldrNameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    //m_fldrNameText->forceUpdate();
    m_fldrNameText->setPos(
        VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
        EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - EMAIL_MSG_VIEW_HEADER_TOP_GAP - m_fldrNameText->getBounds().getHeight());
    m_fldrNameText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - EMAIL_MSG_VIEW_HEADER_TOP_GAP - m_fldrNameText->getBounds().getHeight(),
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_fldrNameText->getBounds().getHeight()));
}


void VappEmailMsgListTitleBar::updateTitleTextLayout()
{
    VfxU32 screennWidth;
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_TITLEBAR_UPDATE_TEXT_LAYOUT);

    if (m_rotation == VFX_SCR_ROTATE_TYPE_90 || m_rotation == VFX_SCR_ROTATE_TYPE_270)
    {
        screennWidth = LCD_HEIGHT;
    }
    else
    {
        screennWidth = LCD_WIDTH;
    }    

    setSize(screennWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);

    m_bgImageFrame->setBounds(VfxRect(0, 0, screennWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT));

    m_acctNameText->setPos(
        VfxPoint(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_TOP_GAP));
    m_acctNameText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_TOP_GAP,
            screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_acctNameText->getBounds().getHeight()));
    //m_acctNameText->forceUpdate();

    m_fldrNameText->setPos(
        VfxPoint(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_fldrNameText->getBounds().getHeight() - EMAIL_MSG_VIEW_HEADER_TOP_GAP));
    m_fldrNameText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_fldrNameText->getBounds().getHeight() - EMAIL_MSG_VIEW_HEADER_TOP_GAP,
            screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_fldrNameText->getBounds().getHeight()));
    //m_fldrNameText->forceUpdate();
}


void VappEmailMsgListTitleBar::updateTitleBtnLayout()
{
    VfxU32 screennWidth;
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_TITLEBAR_UPDATE_BTN_LAYOUT);
    
    if (m_rotation == VFX_SCR_ROTATE_TYPE_90 || m_rotation == VFX_SCR_ROTATE_TYPE_270)
    {
        screennWidth = LCD_HEIGHT;
    }
    else
    {
        screennWidth = LCD_WIDTH;
    }

    setSize(screennWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;

    if (m_leftButton != NULL)
    {
        m_leftButton->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, btnTopGap);
        m_leftButton->setBounds(
            VfxRect(
                EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
        m_leftButton->setEffectOffset(
            VfxPoint(
                EMAIL_MSG_VIEW_HEADER_LEFT_GAP - 1,
                btnTopGap - 1));
    }
    if (m_rightButton != NULL)
    {
        m_rightButton->setPos(
            screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
            btnTopGap);
        m_rightButton->setBounds(
            VfxRect(
                screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
        m_rightButton->setEffectOffset(
            VfxPoint(
                screennWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - 2,
                btnTopGap - 1));
    }
}


VappEmailMsgListRemoteFolderListProvider::VappEmailMsgListRemoteFolderListProvider(EMAIL_ACCT_ID acctID)
    :m_acctID(acctID)
{
    memset(m_fldrIDMsgNumMap, 0, sizeof(FldrIDMsgNumMap) * 20);
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    S32 getFldrIDCount = 1;
    EMAIL_FLDR_ID fldrID = EMAIL_FLDR_INVALID_ID;
    srv_email_acct_folder_struct *fldrInfo = NULL;
    S32 remoteNum = 0;

    do
    {
        result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_open(acctHandle, m_acctID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_get_fldr_num(
                    acctHandle,
                    SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                    &remoteNum);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        fldrInfo = (srv_email_acct_folder_struct*)get_ctrl_buffer(sizeof(srv_email_acct_folder_struct));
        for (VfxS32 index = 0; index < remoteNum; index++)
        {
            result = srv_email_acct_get_fldr_id(
                        acctHandle,
                        SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                        (S32)index,
                        &getFldrIDCount,
                        &fldrID);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            result = srv_email_acct_get_fldr_info(
                        acctHandle,
                        fldrID,
                        fldrInfo);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            m_fldrIDMsgNumMap[index].fldrID = fldrID;
            m_fldrIDMsgNumMap[index].msgNum = fldrInfo->msg_count;
            m_fldrIDMsgNumMap[index].unreadMsgNum = fldrInfo->unread_count;
        }
    } while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    if (fldrInfo != NULL)
    {
        free_ctrl_buffer(fldrInfo);
    }
}


VfxBool VappEmailMsgListRemoteFolderListProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &color)
{
    if (fieldType != VCP_LIST_MENU_FIELD_TEXT)
    {
        return VFX_FALSE;
    }

    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    S32 getFldrIDCount = 1;
    EMAIL_FLDR_ID fldrID = EMAIL_FLDR_INVALID_ID;
    srv_email_acct_folder_struct *fldrInfo = NULL;

    do
    {
        result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_open(acctHandle, m_acctID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_get_fldr_id(
                    acctHandle,
                    SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                    (S32)index,
                    &getFldrIDCount,
                    &fldrID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        fldrInfo = (srv_email_acct_folder_struct*)get_ctrl_buffer(sizeof(srv_email_acct_folder_struct));
        result = srv_email_acct_get_fldr_info(
                    acctHandle,
                    fldrID,
                    fldrInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        textString.loadFromMem((VfxWChar*)(fldrInfo->folder_name));
        VfxWString numString;
        VfxWString temp;
        numString += VFX_WSTR(" ");
        numString += VFX_WSTR_RES(STR_EMAIL_FTO_LEFT_PARENTHESES);
        
        if (fldrInfo->unread_count != 0)
        {
            temp.format("%d/%d", m_fldrIDMsgNumMap[index].unreadMsgNum, m_fldrIDMsgNumMap[index].msgNum);
            color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
        }
        else
        {
            temp.format("%d", m_fldrIDMsgNumMap[index].msgNum);
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }

        numString += temp;
        numString += VFX_WSTR_RES(STR_EMAIL_FTO_RIGHT_PARENTHESES); 
        textString += numString;
    } while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    if (fldrInfo != NULL)
    {
        free_ctrl_buffer(fldrInfo);
    }
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappEmailMsgListRemoteFolderListProvider::getItemTextFrameFormat(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxTextFrame *frame)
{
    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            if (m_fldrIDMsgNumMap[index].unreadMsgNum != NULL)
            {
                VfxFontDesc font = frame->getFont();
                font.setAttr(VFX_FONT_DESC_ATTR_BOLD);
                frame->setFont(font);
            }
        }
        break;
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


VfxBool VappEmailMsgListRemoteFolderListProvider::getItemImage(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxImageSrc &imageSrc)
{
    return VFX_FALSE;
}


void VappEmailMsgListRemoteFolderListProvider::closeItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc imageSrc)
{
}


VfxU32 VappEmailMsgListRemoteFolderListProvider::getCount(void) const
{
    S32 remoteNum = 0;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;

    do
    {
        srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
        result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_open(acctHandle, m_acctID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_get_fldr_num(
                    acctHandle,
                    SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                    &remoteNum);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
    } while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    return remoteNum;
}


VcpListMenuItemStateEnum VappEmailMsgListRemoteFolderListProvider::getItemState(VfxU32) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappEmailMsgListRemoteFolderListProvider::swapItem(VfxU32 first, VfxU32 second)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappEmailMsgListRemoteFolderListProvider::getItemCustomContentFrame(
                                    VfxU32 index,
                                    VfxFrame *frame)
{
    return NULL;
}


void VappEmailMsgListRemoteFolderListProvider::closeItemCustomContentFrame(
        VfxU32 index,
        VcpListMenuCellClientBaseFrame *baseFrame)
{
}


void VappEmailMsgListRemoteFolderListProvider::updateFldrMsgNum(
        EMAIL_FLDR_ID fldrID,
        VfxU32 unreadMsgNum,
        VfxU32 msgNum)
{
    for (VfxU32 index = 0; index < 20; index++)
    {
        if (fldrID == m_fldrIDMsgNumMap[index].fldrID)
        {
            m_fldrIDMsgNumMap[index].msgNum = msgNum;
            m_fldrIDMsgNumMap[index].unreadMsgNum = unreadMsgNum;
        }
    }
}


void VappEmailMsgListRemoteFolderPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    setTopBar(m_titleBar);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_EMAIL_FTO_REMOTE_FOLDER));

    VFX_OBJ_CREATE_EX(m_listProvider, VappEmailMsgListRemoteFolderListProvider, this, (m_acctID));
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listProvider->setMenu(m_listMenu);
    VfxSize pageSize = getSize();
    m_listMenu->setContentProvider(m_listProvider);
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgListRemoteFolderPage::onItemClick);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VappEmailMgr::getInstance()->m_signalFldrMsgNumChange.connect(this, &VappEmailMsgListRemoteFolderPage::onAcctMsgNumChange);
}


void VappEmailMsgListRemoteFolderPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_270 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_LANDSCAPE)
    {
        gScrnWidth = LCD_HEIGHT;
        gScrnHeight = LCD_WIDTH;
    }
    else
    {
        gScrnWidth = LCD_WIDTH;
        gScrnHeight = LCD_HEIGHT;
    }
}


VappEmailMsgListRemoteFolderPage::VappEmailMsgListRemoteFolderPage()
{
}


void VappEmailMsgListRemoteFolderPage::onItemClick(VcpListMenu *, VfxU32 index)
{
    S32 getRemoteNum = 1;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldrID = EMAIL_FLDR_INVALID_ID;

    do
    {
        result = srv_email_acct_create(gEmailSrvHandle, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_open(acctHandle, m_acctID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_acct_get_fldr_id(
                    acctHandle,
                    SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
                    (S32)index,
                    &getRemoteNum,
                    &fldrID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
    } while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }

    VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
    mainScrn->popPage();
    mainScrn->setCurrFldr(fldrID);
    VfxId msgListPageID = mainScrn->getTopPageId();
    VappEmailMsgListPage *msgListPage = (VappEmailMsgListPage*)(mainScrn->getPage(msgListPageID));

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_LIST_REMOTE_FOLDER_ITEM_CLICK,
        index,
        fldrID);

    msgListPage->resetPage(m_acctID, fldrID, SRV_EMAIL_FLDR_TYPE_REMOTE);
    msgListPage->updateTitleBar();
}


void VappEmailMsgListRemoteFolderPage::onAcctMsgNumChange(
        EMAIL_ACCT_ID acctID,
        EMAIL_FLDR_ID fldrID,
        VappEmailFldrMsgNumStruct msgNumInfo)
{
    if (acctID != m_acctID)
    {
        return;
    }

    m_listProvider->updateFldrMsgNum(fldrID, msgNumInfo.unreadNum, msgNumInfo.totalNum);
    m_listMenu->resetAllItems(VFX_TRUE);
}



