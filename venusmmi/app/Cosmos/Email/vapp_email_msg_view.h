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
 * Vapp_email_msg_view.h
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


#ifndef __VAPP_EMAIL_MSG_VIEW_H__
#define __VAPP_EMAIL_MSG_VIEW_H__


#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "Vapp_Email_Main.h"
#include "Vapp_Email_mgr.h"

extern "C"
{
#include "emailsrvgprot.h"
#include "FileMgrSrvGProt.h"
#include "app_html.h"
} /* extern "C" */


#define VAPP_EMAIL_HTML_PAESE_BUFF_LEN          (1024)
#define VAPP_EMAIL_MAX_CONTENT_LEN              (2 * 1024)


#if defined(__MMI_MAINLCD_320X480__)

#define EMAIL_MSG_VIEW_FONT_SMALL       VFX_FONT_DESC_VF_SIZE(14)
#define EMAIL_MSG_VIEW_FONT_MEDIUM      VFX_FONT_DESC_VF_SIZE(20)
#define VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH                   30
#define EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT                   51
#define EMAIL_MSG_VIEW_HEADER_TOP_GAP                       6
#define EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP                    6
#define EMAIL_MSG_VIEW_HEADER_LEFT_GAP                      8
#define EMAIL_MSG_VIEW_HEADER_RIGHT_GAP                     8
#define EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT                   47
#define EMAIL_MSG_VIEW_CONT_ITEMS_GAP                       8
#define EMAIL_MSG_VIEW_CONT_LINE_HEIGHT                     36
#define EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH             55
#define EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH              55
#define EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT         ((EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT + 1) / 2)
#define EMAIL_MSG_LIST_UNREAD_ICON_SIZE                     8

#elif defined(__MMI_MAINLCD_480X800__)

#define EMAIL_MSG_VIEW_FONT_SMALL       VFX_FONT_DESC_VF_SIZE(26)
#define EMAIL_MSG_VIEW_FONT_MEDIUM      VFX_FONT_DESC_VF_SIZE(35)
#define VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH                   51
#define EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT                   86
#define EMAIL_MSG_VIEW_HEADER_TOP_GAP                       9
#define EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP                    10
#define EMAIL_MSG_VIEW_HEADER_LEFT_GAP                      14
#define EMAIL_MSG_VIEW_HEADER_RIGHT_GAP                     14
#define EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT                   84
#define EMAIL_MSG_VIEW_CONT_ITEMS_GAP                       14
#define EMAIL_MSG_VIEW_CONT_LINE_HEIGHT                     48
#define EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH             93
#define EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH              93
#define EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT         ((EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT + 1) / 2)
#define EMAIL_MSG_LIST_UNREAD_ICON_SIZE                     14

#else

#define EMAIL_MSG_VIEW_FONT_SMALL       VFX_FONT_DESC_VF_SIZE(13)
#define EMAIL_MSG_VIEW_FONT_MEDIUM      VFX_FONT_DESC_VF_SIZE(18)
#define VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH                   27
#define EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT                   45
#define EMAIL_MSG_VIEW_HEADER_TOP_GAP                       5
#define EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP                    5
#define EMAIL_MSG_VIEW_HEADER_LEFT_GAP                      8
#define EMAIL_MSG_VIEW_HEADER_RIGHT_GAP                     8
#define EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT                   42
#define EMAIL_MSG_VIEW_CONT_ITEMS_GAP                       8
#define EMAIL_MSG_VIEW_CONT_LINE_HEIGHT                     32
#define EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH             49
#define EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH              49
#define EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT         ((EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT + 1) / 2)
#define EMAIL_MSG_LIST_UNREAD_ICON_SIZE                     5

#endif


typedef struct
{
    EMAIL_ATTCH_ID attach_id;                       /* The attachment id */
    S32 charset;                                    /* The charset of the attachment */
    S32 name_len;                                   /* Length of attachment display name buffer */
    WCHAR name[EMAIL_ATTCH_FILE_NAME_LEN + 1];      /* Buffer to store the attachment display name */
    WCHAR path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];    /* The filepath of the attachment */
    S32 size;                                       /* The size of the attachment */
    S32 mime_type;                                  /* The mime type of the content */
    S32 mime_subtype;                               /* The mime subtype of the content */
    MMI_BOOL drm_object;                            /* The attachment is the DRM object or not */
    S32 drm_type;                                   /* The mime type of the DRM object */
    S32 drm_subtype;                                /* The mime subtype of the DRM object */
    CHAR cid[SRV_EMAIL_CID_MAX_LEN + 1];            /* The Content ID digest of the attachment */
    MMI_BOOL downloaded;                            /* The attachment has been downloaded or not */
} srv_email_attach_structa;


typedef struct
{
    S32 in_content_len;
    FS_HANDLE file_h;
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif
    U8 *convert_buffer;
    U32 read_len;
    U32 buff_len;
    U32 read_buff_len;
    BOOL is_last_read;
    U8 *data_temp_ptr;
    U8 *read_temp_ptr;
    U8 *html_data_buff_ptr;
    U32 html_data_buff_len;
    applib_html_plaintext_context_struct plaintext;
} VappEmailContentParser;


typedef enum
{
    EMAIL_CONT_PARSE_NONE = 0,
    EMAIL_CONT_PARSE_START,
    EMAIL_CONT_PARSE_PARSING,
    EMAIL_CONT_PARSE_FINISH,
    EMAIL_CONT_PARSE_END
} VappEmailContentParserState;


enum MsgViewFormBaseItemType
{
    MSG_VIEW_FORM_BASE_ITEM_FROM,
    MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO,
    MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC,
    MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_BCC,
    MSG_VIEW_FORM_BASE_ITEM_SUBJ,
    MSG_VIEW_FORM_BASE_ITEM_HTML,
    MSG_VIEW_FORM_BASE_ITEM_CONT,
    MSG_VIEW_FORM_BASE_ITEM_TOTAL
};


enum MsgViewPageTBItemId
{
    MSG_VIEW_PAGE_TB_REPLY,
    MSG_VIEW_PAGE_TB_REPLY_ALL,
    MSG_VIEW_PAGE_TB_FORWARD,
    MSG_VIEW_PAGE_TB_SEND,
    MSG_VIEW_PAGE_TB_USE_DETAILS,
    MSG_VIEW_PAGE_TB_MOVE_TO_DRAFTS,
    MSG_VIEW_PAGE_TB_DELETE,
    MSG_VIEW_PAGE_TB_MARK_AS_UNREAD,
    MSG_VIEW_PAGE_TB_TOTAL
};


enum MsgViewPageKeywordOperation
{
    MSG_VIEW_PAGE_KEYWORD_OPERATION_EDIT_BEFORE_CALL,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_MESSAGE,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_GO_TO_URL,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_SAVE_TO_BOOKMARKS,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL,
    MSG_VIEW_PAGE_KEYWORD_OPERATION_TOTAL
};


enum EmailMsgViewRecipientTypeEnum
{
    EMAIL_MSG_VIEW_RECIPIENT_BASE,
    EMAIL_MSG_VIEW_RECIPIENT_TO,
    EMAIL_MSG_VIEW_RECIPIENT_CC,
    EMAIL_MSG_VIEW_RECIPIENT_BCC,
    EMAIL_MSG_VIEW_RECIPIENT_TOTAL
};


class VappEmailMsgViewRecipientListProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappEmailMsgViewRecipientListProvider(
        EMAIL_ACCT_ID acctID,
        EMAIL_FLDR_ID fldrID,
        EMAIL_MSG_ID msgID,
        EmailMsgViewRecipientTypeEnum recipientType)
        :m_acctID(acctID),
         m_fldrID(fldrID),
         m_msgID(msgID),
         m_recipientType(recipientType),
         m_recipientAddrNum(0)
    {
    };
    VappEmailMsgViewRecipientListProvider()
    {
    };
    void releaseAllRecipientAddr()
    {
        if (m_recipientAddrList != NULL)
        {
            VappEmailApp::memFree(m_recipientAddrList);
            m_recipientAddrList = NULL;
        }
    };
    virtual void onInit();
    virtual void setMenu(VcpListMenu *liseMenu)
    {
        m_listMenu = liseMenu;
    };
    virtual VfxBool getItemText(VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &);
    virtual void closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32) const;
    virtual VfxBool swapItem(VfxU32, VfxU32);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32, VfxFrame *);
    virtual void closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *);

private:
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    EmailMsgViewRecipientTypeEnum m_recipientType;
    VcpListMenu *m_listMenu;
    VfxU32 m_recipientAddrNum;
    srv_email_addr_struct *m_recipientAddrList;
};


class VappEmailMsgViewRecipientPage : public VfxPage
{
public:
    VappEmailMsgViewRecipientPage(
        EMAIL_ACCT_ID,
        EMAIL_FLDR_ID,
        EMAIL_MSG_ID,
        EmailMsgViewRecipientTypeEnum);
    VappEmailMsgViewRecipientPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRotate(const VfxScreenRotateParam &param);
    void onItemClick(VcpListMenu *, VfxU32);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

private:
    VcpListMenu *m_listMenu;
    VappEmailMsgViewRecipientListProvider *m_listProvider;
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    EmailMsgViewRecipientTypeEnum m_recipientType;

private:
    void onKeywordOperationClick(VfxObject *, VfxId);
};


class VappEmailMsgViewUseDetailsMenuProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappEmailMsgViewUseDetailsMenuProvider(VcpTextView *);
    VappEmailMsgViewUseDetailsMenuProvider();
    virtual void setMenu(VcpListMenu *liseMenu)
    {
        m_listMenu = liseMenu;
    };
    virtual VfxBool getItemText(VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &);
    virtual void closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32) const;
    virtual VcpListMenuCmdStateEnum getItemCmdState(VfxU32 index) const;    
    virtual VfxBool swapItem(VfxU32, VfxU32);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32, VfxFrame *);
    virtual void closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *);
    virtual void onInit();

private:
    VcpListMenu *m_listMenu;
    VcpTextView *m_textView;
};


class VappEmailMsgViewUseDetailsPage : public VfxPage
{
public:
    VappEmailMsgViewUseDetailsPage(VcpTextView *);
    VappEmailMsgViewUseDetailsPage();
    virtual void onInit();
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    void onItemClick(VcpListMenu *, VfxU32);
    void onCMDBtnClick(VcpListMenu *, VfxU32);

private:
    VcpListMenu *m_listMenu;
    VappEmailMsgViewUseDetailsMenuProvider *m_listProvider;
    VcpTextView *m_contTextView;

private:
    void onKeywordOperationClick(VfxObject *obj, VfxId id);
    void onSimAvailableChanged(VfxBool simAvailable);
};


class VappEmailMsgViewHtmlItem : public VcpFormItemBase
{
public:
    virtual void onInit();
    VcpButton *getHtmlBtn()
    {
        return m_htmlBtn;
    };
    void updateLayout();
    void disableBtn()
    {
        if (m_htmlBtn != NULL)
        {
            m_htmlBtn->setIsDisabled(VFX_TRUE);
        }
    };

private:
    VcpButton *m_htmlBtn;
};


class VappEmailMsgViewRecipientItem : public VcpFormItemBase
{
public:
    virtual void onInit();
    srv_email_result_enum initTextFrame(
        EMAIL_MSG_HANDLE msgHandle,
        EmailMsgViewRecipientTypeEnum,
        VfxU32 bccIndex = 0);
    VcpButton *getRecipientListBtn()
    {
        return m_button;
    };
    void onSingleRecipientClick(VfxObject *, VfxId);
    void disableAllBtn()
    {
        if (m_button != NULL)
        {
            m_button->setIsDisabled(VFX_TRUE);
        }
        for (VfxU16 i = 0; i < 30; i++)
        {
            if (m_btnList[i] == NULL)
            {
                return;
            }
            else
            {
                m_btnList[i]->setIsDisabled(VFX_TRUE);
            }
        }
    };
    void updateLayout();

private:
    VcpButton *m_button;
    EmailMsgViewRecipientTypeEnum m_recipientType;
    EMAIL_MSG_HANDLE m_msgHandle;
    /* MMI_EMAIL_MAX_ADDR_NUM */
    VcpButton *m_btnList[30];
    VfxTextFrame *m_threeDotText;
    VfxTextFrame *m_recipientTypeText;
    VfxU32 m_recipientNum;

private:
    void onKeywordOperationClick(VfxObject *, VfxId);
};


class VappEmailMsgViewFromItem : public VcpFormItemBase
{
public:
    virtual void onInit();
    void updateFromItem(const VfxWString &, VfxBool);
    VcpButton *getFromBtn()
    {
        return m_fromButton;
    };
    VcpImageButton *getRecipientBtn()
    {
        return m_recipientButton;
    };
    void updateLayout();
    void disableAllBtn()
    {
        if (m_fromButton != NULL)
        {
            m_fromButton->setIsDisabled(VFX_TRUE);
        }
        if (m_recipientButton != NULL)
        {
            m_recipientButton->setIsDisabled(VFX_TRUE);
        }
    };
    void updateBtnIcon(VfxBool);

private:
    VfxTextFrame *m_fromItemText;
    VcpButton *m_fromButton;
    VcpImageButton *m_recipientButton;
};


class VappEmailMsgViewSubjItem : public VcpFormItemBase
{
public:
    virtual void onInit();
    void updateSubjItem(const VfxWString &, const VfxWString &);
    VcpImageButton *getBtn()
    {
        return m_btn;
    };
    void foldItem(VfxBool);
    void updateLayout();
    void expendItem(VfxBool);

private:
    VfxTextFrame *m_subjView;
    VfxTextFrame *m_dateView;
    VcpImageButton *m_btn;
    VfxBool m_needBtn;

private:
    void updateBtn();
    void setSubj(const VfxWString &);
    void setDate(const VfxWString &);
    VfxU32 getGapBetweenLines()
    {
        VfxTextFrame *textFrame1;
        VFX_OBJ_CREATE(textFrame1, VfxTextFrame, this);
        textFrame1->setString(VFX_WSTR("bp"));
        textFrame1->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
        textFrame1->setMargins(0, 0, 0, 0);
        textFrame1->forceUpdate();
        VfxTextFrame *textFrame2;
        VFX_OBJ_CREATE(textFrame2, VfxTextFrame, this);
        textFrame2->setString(VFX_WSTR("bp"));
        textFrame2->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_SMALL));
        textFrame2->setMargins(0, 0, 0, 0);
        textFrame2->forceUpdate();

        VfxU32 gap = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT -
                     textFrame1->getBounds().getHeight() -
                     textFrame2->getBounds().getHeight() -
                     EMAIL_MSG_VIEW_HEADER_TOP_GAP -
                     EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP;
        VFX_OBJ_CLOSE(textFrame1);
        VFX_OBJ_CLOSE(textFrame2);
        return gap;
    };
};


class VappEmailMsgViewTitleBar : public VfxPageBar
{
public:
    VappEmailMsgViewTitleBar()
        :m_leftButton(NULL),
         m_rightButton(NULL),
         m_indexText(NULL),
         m_fldrNameText(NULL),
         m_bgImageFrame(NULL),
         m_rotation(VFX_SCR_ROTATE_TYPE_NORMAL)
    {
    };
    virtual void onInit();
    virtual void onSetRotate(VfxScrRotateTypeEnum rotation);
    
    VcpImageButton *getLeftBtn()
    {
        return m_leftButton;
    };
    VcpImageButton *getRightBtn()
    {
        return m_rightButton;
    };
    void updateTitleText(VfxWString &, VfxWString &);
    void updateButtons(VfxBool);
    void updateTitleLayout();
    void disableAllBtn()
    {
        if (m_leftButton != NULL)
        {
            m_leftButton->setIsDisabled(VFX_TRUE);
        }
        if (m_rightButton != NULL)
        {
            m_rightButton->setIsDisabled(VFX_TRUE);
        }
    };
    void getTitleBarText(VfxWString &indexText, VfxWString &fldrNameText)
    {
        indexText = m_indexText->getString();
        fldrNameText = m_fldrNameText->getString();
    };

private:
    VcpImageButton *m_leftButton;
    VcpImageButton *m_rightButton;
    VfxTextFrame *m_indexText;
    VfxTextFrame *m_fldrNameText;
    VfxImageFrame *m_bgImageFrame;
    VfxScrRotateTypeEnum m_rotation;
};


class VappEmailMsgViewPage : public VfxPage
{
public:
    VappEmailMsgViewPage(EMAIL_ACCT_ID, EMAIL_FLDR_ID, EMAIL_MSG_ID);
    VappEmailMsgViewPage();

    virtual void onInit();
    virtual void onDeinit();

    VfxBool updateMsgInfo();
    
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual VfxBool onKeyInput(VfxKeyEvent &);
    virtual void onRotate(const VfxScreenRotateParam &);
    void onTBClick(VfxObject *, VfxId);
    void onFromBtnClick(VfxObject *, VfxId);
    void onContentKeywordClick(VcpTextKeyWordEnum, VfxWChar *, VfxS32);
    void onRecipientBtnClick(VfxObject *, VfxId);
    void onRecipientListToBtnClick(VfxObject *, VfxId);
    void onRecipientListCcBtnClick(VfxObject *, VfxId);
#if 0    
/* under construction !*/
#endif
    void onDeleteConfirmBtnClick(VfxObject *, VfxId);
    void onReadMoreConfirmBtnClick(VfxObject *, VfxId);
    void onAttachBtnClick(VfxObject*, VfxId);
    void onHtmlBtnClick(VfxObject*, VfxId);
    static void getHtmlFileCallback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data);
    void cancelGetHtmlFile();
    void onReadMoreBtnClick(VcpTextView*, VfxWString);
    void onTitleLBtnClick(VfxObject *, VfxId);
    void onTitleRBtnClick(VfxObject *, VfxId);
    void onSubjBtnClick(VfxObject *, VfxId);
    void onKeywordOperationClick(VfxObject *, VfxId);
    void onRetrieveDone(EMAIL_MSG_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void onMsgNumChange(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID, VappEmailFldrMsgNumStruct numChange);
    void onMsgChange(EMAIL_MSG_ID, srv_email_om_notify_msg_struct);
    void onAcctNwkProc(VappEmailNwkStateEnum, VfxU32, VappEmailNwkProcEnum);
    void onMsgStateChange(EMAIL_MSG_ID, VappEmailMsgStateEnum);
    void onFldrStateChange(EMAIL_FLDR_ID fldrId, VappEmailFldrStateEnum state)    ;
    void onAcctNwkDone(EMAIL_ACCT_ID acctID, VappEmailNwkDoneEnum operation, VappEmailResStruct result);    
    void onMsgDelete(EMAIL_MSG_ID);

    void getIndex(VfxU32 &index, VfxU32 &total);
    void getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total);
    void closeLoading()
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_CLOSE_LOADING, __LINE__);
        if (m_loadingPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_loadingPopup);
            m_loadingPopup = NULL;
        }
    };
    static void mmi_email_read_extract_html(void *userData);
    static void mmi_email_read_cont_parser_ind(void *userData);
    static void mmi_email_read_cont_parser();
    static U8 *mmi_email_parse_content_to_ucs2(VappEmailContentParser *parser, S32 chset, U16 *outLen, U32 *pos);
    void msgHeaderUpdated();
    void msgContentUpdated();

protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    /* title bar */
    VappEmailMsgViewTitleBar *m_titleBar;

    /* header part */
    VcpRichTextCustomFrame m_msgHeaderFrame;
    //VappEmailMsgViewHeaderContainerFrame m_msgHeaderContainerFrame;
    VcpForm *m_msgForm;
    VappEmailMsgViewFromItem *m_fromItem;
    VappEmailMsgViewRecipientItem *m_recipientItemTo;
    VappEmailMsgViewRecipientItem *m_recipientItemCc;
    VappEmailMsgViewRecipientItem *m_recipientItemBcc;
    VappEmailMsgViewSubjItem *m_subjItem;
    VappEmailMsgViewHtmlItem *m_htmlItem;

    /* content part */
    VcpTextView *m_msgCont;
    VcpButton *m_attachBtn;
    VcpRichTextCustomFrame m_msgAttachBtnFrame;

    /* toolbar */
    VcpToolBar *m_toolbar;

    /* page and popup */
    VcpConfirmPopup *m_deleteConfirmPage;
    VappEmailMsgViewUseDetailsPage *m_useDetailsPage;
    VcpIndicatorPopup *m_loadingPopup;

    /* IDs */
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    mmi_id m_dialerID;
    mmi_id m_phbID;
    mmi_id m_bkmID;

    /* html */
    EMAIL_MSG_HANDLE m_msgHandle;
    VfxBool m_isGetHtmlFile;    
    mmi_id m_getHtmlFileReqID;

    /* status */
    VfxBool m_isAddrFold;
    VfxBool m_isSubjFold;
    VfxBool m_deleteMsg;
    VfxBool m_isPageDisabled;
    static VfxBool m_asyncParse;
    VfxBool m_popupShowed;    // need show too many attachment & recipient popup or not

    /* message info*/
    srv_email_msg_get_basic_info_struct *m_msgBasicInfo;

private:
    void updateMsgViewer();
    void updateMsgHeader();
    void updateMsgContent();
    void addHtmlFrame();
    void removeHtmlFrame();
    void updateMsgHeaderLayout();
    void updateAttachInfo();
    void updateTitleBar();
    void updateTitleBarText();
    void updateToolbar();
    srv_email_result_enum updateFromItem();
    srv_email_result_enum updateSubjItem();
    static void updateContItemCallback(void *userData, int result);
    void showLoading(VfxBool canCancel = VFX_FALSE, VfxBool isDownload = VFX_FALSE, VfxBool isGetHtmlFile = VFX_FALSE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_LOADING, __LINE__);
        if (m_loadingPopup == NULL)
        {
            VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, getParent());
            if (canCancel)
            {
                m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
                m_loadingPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onLoadingBtnClick);
            }
            else
            {
                m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            }
            if (isDownload == VFX_TRUE)
            {
                m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_DOWNLOADING));
            }
            else
            {
                m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_LOADING));
            }
            m_loadingPopup->setAutoDestory(VFX_FALSE);
            m_loadingPopup->show(VFX_TRUE);
            m_isGetHtmlFile = isGetHtmlFile;
        }
    };
    void addRecipientItem();
    void onRecipientListBtnClick(EmailMsgViewRecipientTypeEnum);
    void onLoadingBtnClick(VfxObject *, VfxId);
    void retrieveContent();
    void disablePage();
    void showNotDownloadAllPopup();
    void onNotDownloadAllBtnClick(VfxObject *, VfxId);
    void onPopupBtnClick(VfxObject *, VfxId);
#if 0    
/* under construction !*/
#endif
    void getMsgBasicInfo(
        VfxBool *showHtmlBtn = NULL,
        VfxBool *showReadMoreBtn = NULL,
        VfxBool *showAttachBtn = NULL,
        VfxBool *hasTextCont = NULL,
        S8* htmlStatus = NULL);
    void resetSwitchBtnState()
    {
        if (m_titleBar != NULL &&
            m_titleBar->getLeftBtn() != NULL && 
            m_titleBar->getRightBtn() != NULL &&
            m_titleBar->getLeftBtn()->getState() != VCP_IMAGE_BUTTON_STATE_DISABLED &&
            m_titleBar->getRightBtn()->getState() != VCP_IMAGE_BUTTON_STATE_DISABLED)
        {
            m_titleBar->getLeftBtn()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
            m_titleBar->getRightBtn()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        }
    };
    
    void setMsgAsRead(); // set message flag as seen
};


class VappEmailMsgViewAttachListMenuProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappEmailMsgViewAttachListMenuProvider(EMAIL_ACCT_ID, EMAIL_FLDR_ID, EMAIL_MSG_ID);
    VappEmailMsgViewAttachListMenuProvider();
    virtual void setMenu(VcpListMenu *liseMenu)
    {
        m_listMenu = liseMenu;
    };
    virtual VfxBool getItemText(VfxU32, VcpListMenuFieldEnum, VfxWString &, VcpListMenuTextColorEnum &);
    virtual VfxBool getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &);
    virtual void closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc);
    virtual VfxU32 getCount(void) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32) const;
    virtual VfxBool swapItem(VfxU32, VfxU32);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32, VfxFrame *);
    virtual void closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *);
    virtual void onInit();

private:
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    S32 m_attachNum;
    VcpListMenu *m_listMenu;
};


class VappEmailMsgViewAttachPage : public VfxPage
{
public:
    VappEmailMsgViewAttachPage(EMAIL_ACCT_ID, EMAIL_FLDR_ID, EMAIL_MSG_ID);
    VappEmailMsgViewAttachPage();

    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual void onRotate(const VfxScreenRotateParam &param);
    void onItemClick(VcpListMenu *, VfxU32);
    void onCMDBtnClick(VcpListMenu *, VfxU32);
    void onTBClick(VfxObject *, VfxId);
    void onDownloadAllConfirmBtnClick(VfxObject *, VfxId);
    void onDownloadsingleConfirmBtnClick(VfxObject *, VfxId);
    void onSaveAttachBtnClick(VfxObject *, VcpInputPopupButtonEnum);
    void saveContact(VfxBool);
    void onErrorPopupBtnClick(VfxObject *, VfxId);
    void onRetrieveDone(EMAIL_MSG_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void onAcctNwkProc(VappEmailNwkStateEnum, VfxU32, VappEmailNwkProcEnum);
    EMAIL_ACCT_ID m_acctID;
    EMAIL_FLDR_ID m_fldrID;
    EMAIL_MSG_ID m_msgID;
    void showLoading(VfxBool canCancel = VFX_FALSE, VfxBool isDownload = VFX_FALSE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_SHOW_LOADING, __LINE__);
        if (m_loadingPopup == NULL)
        {
            VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, getParent());
            if (canCancel)
            {
                m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
                m_loadingPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewAttachPage::onLoadingBtnClick);
            }
            else
            {
                m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            }
            if (isDownload == VFX_TRUE)
            {
                m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_DOWNLOADING));
            }
            else
            {
                m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_LOADING));
            }
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
    }
    void onMsgDelete(EMAIL_MSG_ID);

private:
    VappEmailMsgViewAttachListMenuProvider *m_listProvider;
    VcpListMenu *m_listMenu;
    VcpIndicatorPopup *m_loadingPopup;
    VcpToolBar *m_toolbar;
    WCHAR *m_copyFileDstPathPtr;
    static VfxU32 m_attachIndex;
    MMI_ID m_imageViewer;
    MMI_ID m_audioPlayer;
    MMI_ID m_videoPlayer;
    MMI_ID m_vcardViewer;
    VfxBool m_attachViewSave;    // VFX_TRUE for view and VFX_FALSE for save

private:
    static mmi_ret copyAttachCallback(mmi_event_struct *param);
    static mmi_ret saveAttachmentCallback(mmi_event_struct *param);
    void saveAttachment();
    void updateToolbar();
    void onLoadingBtnClick(VfxObject *, VfxId);
    void openAttachFile();
};


#endif /* __VAPP_EMAIL_MSG_VIEW_H__ */

