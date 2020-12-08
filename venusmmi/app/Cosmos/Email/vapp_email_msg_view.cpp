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
 * Vapp_email_msg_view.cpp
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

//#include "mmi_rp_app_email_venus_def.h"
#include "Vapp_Email_Main.h"
#include "Vapp_Email_Msg_List.h"
#include "Vapp_Email_Msg_View.h"
#include "vapp_email_util.h"

extern "C"
{
#include "app_mine.h"
#include "GlobalResDef.h"
#include "SimCtrlSrvGprot.h"
#include "FileMgrType.h"
#include "emailsrvgprot.h"
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
#include "opera_api.h"
#endif
#include "App_usedetails.h"
#include "Conversions.h"
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "RightsMgrResDef.h"
#include "RightsMgrGProt.h"
#endif /* __DRM_SUPPORT__ */
#include "MenuCuiGprot.h"

#include "Vcui_phb_gprot.h"

/* call */
#include "UCMGprot.h"

/* send SMS */
#include "vapp_uc_gprot.h"

/* view attachment */
#include "vcui_gallery_gprot.h"
#include "vcui_music_player_gprot.h"
/* edit before call */
//#include "Vcui_dialer_gprot.h"
#include "Vapp_dialer_cui.h"
#include "DialerCuigprot.h"

/* go to URL and add to bookmark */
#include "Browser_api.h"
#include "vcui_bookmark_gprot.h"

#include "FileMgrSrvGProt.h"
#include "Vapp_fmgr_cui_gprot.h"
#include "Vapp_fmgr_cp.h"

#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "mmi_frm_timer_gprot.h"

/* save attachment */
#include "DLAgentSrvGProt.h"
#include "DLAgentSrvDef.h"

/* open vcalender */
#include "vapp_cal_view_detail_ext_gprot.h"

#include "mmi_rp_app_cosmos_global_def.h"
} /* extern "C" */


extern EMAIL_SRV_HANDLE gEmailSrvHandle;
extern VfxU32 gScrnWidth;
extern VfxU32 gScrnHeight;

#define EMAIL_CONTENT_LENGTH    (MMI_EMAIL_MAX_CONT_LEN_BY_K * 1024)

#if defined(__MMI_EMAIL_HTML__)
WCHAR *gHtmlFilePath = NULL;
    #if defined(OPERA_V10_BROWSER)
    static OperaApi_MimeInfo *gHtmlAttInfo = NULL;
    #else /* OPERA_V10_BROWSER */
    const WCHAR gEmail2dots[] = { '.', '.', '\0' };
    static S32 gHtmlCharset = 0;
    static S32 gContLen = 0;
    static char *gNotConvertedStringData = NULL;
    static VappEmailContentParser *gHtmlParserContent = NULL;
    static VappEmailContentParserState gParserStatus;
    #endif /* OPERA_V10_BROWSER */
#endif /* __MMI_EMAIL_HTML__ */

static srv_email_attach_struct *gAttachInfoArray = NULL;
#ifdef __DRM_SUPPORT__
char *gRightsIssuer = NULL;
#endif
mmi_id gFolderSelectorID = 0;
static WCHAR *gSaveAttachPath = NULL;
static S32 gSaveJobID = 0;
static VfxWString gKeywordContent;
static VfxWString gKeywordContentBackUp;
static VfxBool gIsKeywordContentAddr = VFX_FALSE;
static VfxBool gIsSavePhoneNumber = VFX_FALSE;
WCHAR *gContent = NULL;


void VappEmailMsgViewRecipientItem::onInit()
{
    VcpFormItemBase::onInit();

    m_button = NULL;
    m_recipientType = EMAIL_MSG_VIEW_RECIPIENT_BASE;
    m_msgHandle = EMAIL_MSG_INVALID_HANDLE;
    m_recipientNum = 0;
    memset(m_btnList, 0, sizeof(VcpButton*) * 30);
    m_threeDotText = NULL;
    m_recipientTypeText = NULL;
}


srv_email_result_enum VappEmailMsgViewRecipientItem::initTextFrame(
                        EMAIL_MSG_HANDLE msgHandle,
                        EmailMsgViewRecipientTypeEnum recipientType,
                        VfxU32 index)
{
    m_recipientType = recipientType;
    srv_email_result_enum result;
    srv_email_msg_get_basic_info_struct basicInfo;
    srv_email_msg_get_recipient_struct getRecipientInfo;
    srv_email_addr_struct *addr = NULL;
    VfxU32 recipientNum = 0;
    VfxU32 i = 0;
    VfxU32 xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
    VfxU32 yPos = 1;
    VcpButton *btn;
    VfxU8 lineNum = 0;
    VfxWString text;
    VfxU32 rightBorder = 0;
    VfxU32 width;
    VfxU32 itemHeight = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2 - 3;
    VfxU32 listBtnWidth = EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH;
    VfxU32 lineHeight = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2 - 1;
    VfxU32 threeDotWidth = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2;

    do
    {
        m_msgHandle = msgHandle;
        result = srv_email_msg_get_basic_info(m_msgHandle, &basicInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        VfxWString recipientText;
        VFX_OBJ_CREATE(m_recipientTypeText, VfxTextFrame, this);
        if (recipientType == EMAIL_MSG_VIEW_RECIPIENT_TO)
        {
            recipientText.loadFromRes(STR_EMAIL_FTO_TO_ID);
            recipientNum = basicInfo.to_addr_num;
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_TO;
        }
        else if ((recipientType == EMAIL_MSG_VIEW_RECIPIENT_CC))
        {
            recipientText.loadFromRes(STR_EMAIL_FTO_CC_ID);
            recipientNum = basicInfo.cc_addr_num;
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_CC;
        }
      
        m_recipientTypeText->setString(recipientText);
        m_recipientTypeText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_recipientTypeText->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
        m_recipientTypeText->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 3);
        m_recipientTypeText->setBounds(VfxRect(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 3, 0, lineHeight));
        xPos = m_recipientTypeText->getBounds().getWidth() + EMAIL_MSG_VIEW_HEADER_LEFT_GAP + EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
        addr = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));
        getRecipientInfo.addr_list = addr;
        getRecipientInfo.number = 1;
        while (i < recipientNum && (lineNum < 2))
        {
            if (recipientType == EMAIL_MSG_VIEW_RECIPIENT_BCC)
            {
                i = index;
            }
            /* get address */
            getRecipientInfo.start_index = i;
            result = srv_email_msg_get_recipient(m_msgHandle, &getRecipientInfo);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            if (addr->disp_name_len)
            {
                text.loadFromMem((VfxWChar*)addr->disp_name);
            }
            else
            {
                text.loadFromMem((VfxWChar*)addr->email_addr);
            }
            /* create button */
            VFX_OBJ_CREATE(btn, VcpButton, this);
            m_btnList[i] = btn;
            btn->m_signalClicked.connect(this, &VappEmailMsgViewRecipientItem::onSingleRecipientClick);
            btn->setId(i);
            btn->setText(text);
            btn->setTextColor(VRT_COLOR_BLACK);
            btn->setTextFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
            btn->setMargin(3, 3, 3, 3);
            btn->setBgImageList(
                VcpStateImage(
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID));
            //btn->setBgImageList(NULL);
            btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth);
            btn->forceUpdate();
            width = btn->getBounds().getWidth();
            rightBorder = xPos + width + EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
            if (lineNum == 0)
            {
                if (rightBorder < gScrnWidth)
                {
                    btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                    xPos = rightBorder;
                }
                else
                {
                    if (xPos < gScrnWidth / 2)
                    {
                        btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                        btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth - xPos - EMAIL_MSG_VIEW_HEADER_LEFT_GAP);
                        xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                        yPos += lineHeight;
                        lineNum++;
                    }
                    else
                    {
                        lineNum++;
                        xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                        yPos += lineHeight;
                        btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                        xPos += width + EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                        if (xPos > gScrnWidth - threeDotWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP * 2 - EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH)
                        {
                            btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth - threeDotWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP * 3 - EMAIL_MSG_VIEW_RECIPIENT_LIST_BTN_WIDTH);
                            xPos -= (width + EMAIL_MSG_VIEW_HEADER_LEFT_GAP);
                            btn->forceUpdate();
                            xPos += btn->getBounds().getWidth() + EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                            //lineNum++;
                        }
                    }
                }
            }
            else
            {
                if (rightBorder < gScrnWidth - threeDotWidth - listBtnWidth - 3 * EMAIL_MSG_VIEW_HEADER_LEFT_GAP)
                {
                    btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                    xPos = rightBorder;
                }
                else
                {
                    btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                    if (i == recipientNum - 1)
                    {
                        btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth - xPos - EMAIL_MSG_VIEW_HEADER_LEFT_GAP);
                        xPos += width;
                    }
                    else
                    {
                        if ((S32)(gScrnWidth - xPos - threeDotWidth - listBtnWidth - 3 * EMAIL_MSG_VIEW_HEADER_RIGHT_GAP) >= (S32)EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH)
                        {
                            btn->setIsAutoResized(
                                VFX_TRUE,
                                0,
                                gScrnWidth - xPos - threeDotWidth - listBtnWidth - 3 * EMAIL_MSG_VIEW_HEADER_LEFT_GAP);
                            btn->forceUpdate();
                            width = btn->getBounds().getWidth();
                            xPos += width;
                            xPos += EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                        }
                        else
                        {
                            VFX_OBJ_CLOSE(btn);
                            m_btnList[i] = NULL;
                        }
                        VFX_OBJ_CREATE(m_threeDotText, VfxTextFrame, this);
                        VfxWString dotText;
                        dotText.format("...");
                        m_threeDotText->setString(dotText);
                        m_threeDotText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
                        m_threeDotText->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
                        m_threeDotText->setPos(xPos, yPos);
                        m_threeDotText->setBounds(VfxRect(xPos, yPos, threeDotWidth, lineHeight));
                    }
                    lineNum++;
                }
            }
            i++;
            if (recipientType == EMAIL_MSG_VIEW_RECIPIENT_BCC)
            {
                i = recipientNum;
            }
        }
        if (lineNum >= 2 && i < recipientNum)
        {
            VFX_OBJ_CREATE(m_button, VcpButton, this);
            m_button->setRect(VfxRect(gScrnWidth - listBtnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP, yPos, listBtnWidth, lineHeight));
            VfxWString tepText;
            tepText += VFX_WSTR_RES(STR_EMAIL_FTO_LEFT_PARENTHESES);
            text.format("%d", recipientNum);
            tepText += text;
            tepText += VFX_WSTR_RES(STR_EMAIL_FTO_RIGHT_PARENTHESES);             
            m_button->setMargin(0, 0, 0, 0);
            m_button->setTextFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
            m_button->setText(tepText);
        }
    } while(0);

    for (i = 0; i < 30; i++)
    {
        if (m_btnList[i] != NULL)
        {
            m_recipientNum++;
        }
        else
        {
            break;
        }
    }

    if (addr != NULL)
    {
        free_ctrl_buffer(addr);
    }
    if (yPos >= lineHeight && xPos != EMAIL_MSG_VIEW_HEADER_LEFT_GAP)
    {
        VcpFormItemBase::setHeight(EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    }
    else
    {
        VcpFormItemBase::setHeight(EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT + 1);
    }
    return result;
}


void VappEmailMsgViewRecipientItem::updateLayout()
{
    VcpFormItemBase::setHeight(EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT + 1);

    VfxU32 threeDotWidth = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2;
    VfxU32 listTailWidth = EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH + 3 * EMAIL_MSG_VIEW_HEADER_LEFT_GAP + threeDotWidth;
    VfxU32 i = 0;
    VfxU32 xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
    VfxU32 yPos = 1;
    VcpButton *btn;
    VfxU8 lineNum = 0;
    VfxU32 rightBorder = 0;
    VfxU32 width;
    VfxU32 itemHeight = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2 - 3;
    VfxU32 lineHeight = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT / 2 - 1;
    VfxU32 lastVisableBtnIndex = m_recipientNum - 1;

    m_recipientTypeText->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 3);
    m_recipientTypeText->setBounds(VfxRect(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 3, 0, lineHeight));
    xPos = m_recipientTypeText->getBounds().getWidth() + EMAIL_MSG_VIEW_HEADER_LEFT_GAP + EMAIL_MSG_VIEW_HEADER_LEFT_GAP;

    while (i < m_recipientNum && (lineNum < 2))
    {
        btn = m_btnList[i];
        btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth);
        btn->forceUpdate();
        width = btn->getBounds().getWidth();
        rightBorder = xPos + width;
        if (lineNum == 0)
        {
            if (rightBorder < gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP)
            {
                btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                xPos = rightBorder + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP;
            }
            else
            {
                lineNum++;
                if (xPos < (gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP) / 2)
                {
                    btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                    btn->setIsAutoResized(VFX_TRUE, 0, gScrnWidth - xPos - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP);
                    xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                    yPos += lineHeight;
                }
                else
                {
                    xPos = EMAIL_MSG_VIEW_HEADER_LEFT_GAP;
                    yPos += lineHeight;
                    btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                    rightBorder = xPos + width;
                    if (rightBorder > gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP)
                    {
                        /* no space for the following btns */
                        lastVisableBtnIndex = i;
                        btn->setIsAutoResized(
                            VFX_TRUE,
                            0,
                            gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP  - xPos);
                        for (VfxU32 j = i; j < m_recipientNum; j++)
                        {
                            btn = m_btnList[j];
                            btn->setPos(0, 0);
                            btn->setBounds(0, 0, 0, 0);
                        }
                        break;
                    }
                    xPos = rightBorder + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP;
                }
            }
        }
        else
        {
            if (rightBorder < gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP)
            {
                btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                xPos = rightBorder + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP;
            }
            else if (xPos < gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP)
            {
                btn->setRect(VfxRect(xPos, yPos, width, itemHeight));
                btn->setIsAutoResized(
                    VFX_TRUE,
                    0,
                    gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - xPos);
                btn->forceUpdate();
                rightBorder = gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP;
            }
            else
            {
                /* no space for the following btns */
                lastVisableBtnIndex = i;
                lineNum++;
                btn->setIsAutoResized(
                    VFX_TRUE,
                    0,
                    gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP  - xPos);
                for (VfxU32 j = i; j < m_recipientNum; j++)
                {
                    btn = m_btnList[j];
                    btn->setPos(0, 0);
                    btn->setBounds(0, 0, 0, 0);
                }
                break;
            }
        }
        i++;
    }

    if (m_button != NULL)
    {
        /* get space for "..." and recipient button */
        while (lastVisableBtnIndex != 0)
        {
            btn = m_btnList[lastVisableBtnIndex--];
            VfxPoint pos = btn->getPos();
            VfxRect bounds = btn->getBounds();
            rightBorder = pos.x + bounds.getWidth();
            if (pos.x >= (VfxS32)gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - (VfxS32)listTailWidth)
            {
                btn->setPos(0, 0);
                btn->setBounds(0, 0, 0, 0);
            }
            else
            {
                if (rightBorder > gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - listTailWidth)
                {
                    btn->setIsAutoResized(
                        VFX_TRUE,
                        0,
                        gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - listTailWidth - pos.x);
                    btn->forceUpdate();
                    rightBorder = gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - listTailWidth;
                }
                m_threeDotText->setPos(rightBorder + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP, pos.y);
                m_threeDotText->setBounds(
                    rightBorder + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
                    pos.y,
                    threeDotWidth,
                    itemHeight);
                m_button->setPos(
                    gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH,
                    pos.y);
                m_button->setBounds(
                    gScrnWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH,
                    pos.y,
                    EMAIL_MSG_VIEW_RECIPIENT_BTN_MIN_WIDTH,
                    itemHeight);
                break;
            }
        }
    }

    if (yPos >= lineHeight && xPos != EMAIL_MSG_VIEW_HEADER_LEFT_GAP)
    {
        VcpFormItemBase::setHeight(EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    }
    else
    {
        VcpFormItemBase::setHeight(EMAIL_MSG_VIEW_RECIPIENT_SINGLE_LINE_HEIGHT + 1);
    }
}


void VappEmailMsgViewRecipientItem::onSingleRecipientClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_RECIPIENT_CLICK, m_recipientType, id);

    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_msg_get_recipient_struct getRecipientInfo;
    srv_email_addr_struct *addr = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));

    do
    {
        getRecipientInfo.addr_list = addr;
        getRecipientInfo.number = 1;
        getRecipientInfo.start_index = id;
        if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_TO)
        {
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_TO;
        }
        else if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_CC)
        {
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_CC;
        }
        else
        {
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_BCC;
        }
        result = srv_email_msg_get_recipient(m_msgHandle, &getRecipientInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (addr->disp_name_len != 0)
        {
            gIsKeywordContentAddr = VFX_FALSE;
            gKeywordContent.loadFromMem((VfxWChar*)addr->disp_name);
            gKeywordContentBackUp.loadFromMem((VfxWChar*)addr->email_addr);
        }
        else
        {
            gIsKeywordContentAddr = VFX_TRUE;
            gKeywordContent.loadFromMem((VfxWChar*)addr->email_addr);
        }
    } while(0);

    free_ctrl_buffer(addr);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup(result);
        return;
    }

    gIsSavePhoneNumber = VFX_FALSE;

    VcpButton *btn = (VcpButton*)obj;
    gKeywordContent = btn->getText();
    VcpCommandPopup *addrOperationPopup;
    VFX_OBJ_CREATE(addrOperationPopup, VcpCommandPopup, getParent());
    addrOperationPopup->setText(gKeywordContent);
    VfxWString text;
    text.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_CANCEL);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL, text, VCP_POPUP_BUTTON_TYPE_CANCEL);
    addrOperationPopup->m_signalButtonClicked.connect((VappEmailMsgViewPage*)(getParent()->getParent()), &VappEmailMsgViewPage::onKeywordOperationClick);
    addrOperationPopup->show(VFX_TRUE);
}


void VappEmailMsgViewRecipientItem::onKeywordOperationClick(VfxObject *obj, VfxId id)
{
    ((VappEmailMsgViewPage*)getParent())->onKeywordOperationClick(obj, id);
}


void VappEmailMsgViewFromItem::onInit()
{
    VcpFormItemBase::onInit();

    m_fromItemText = NULL;
    m_fromButton = NULL;
    m_recipientButton = NULL;
}


void VappEmailMsgViewFromItem::updateFromItem(const VfxWString &fromText, VfxBool showRecipientBtn)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_FROM);

    setHeight(EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);

    if (m_fromItemText == NULL)
    {
        VFX_OBJ_CREATE(m_fromItemText, VfxTextFrame, this);
        m_fromItemText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_fromItemText->setAutoResized(VFX_TRUE);
        m_fromItemText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_fromItemText->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
        m_fromItemText->setString(VFX_WSTR_RES(STR_EMAIL_FTO_FROM_ID));
        m_fromItemText->forceUpdate();
        VfxU32 textTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_fromItemText->getBounds().getHeight()) / 2 + 1;
        m_fromItemText->setPos(VfxPoint(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, textTopGap));
        m_fromItemText->setBounds(
            VfxRect(
                EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                textTopGap,
                getBounds().getWidth(),
                getBounds().getHeight()));
    }
    if (!fromText.isEmpty())
    {
        VfxU32 xPos = m_fromItemText->getBounds().getWidth() + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2;
        if (m_fromButton == NULL)
        {
            VFX_OBJ_CREATE(m_fromButton, VcpButton, this);
            m_fromButton->setTextColor(VRT_COLOR_BLACK);
            m_fromButton->setMargin(3, 3, 3, 3);
            m_fromButton->setTextFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
            m_fromButton->setBgImageList(
                VcpStateImage(
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID,
                    IMG_EMAIL_FTO_ADDRESS_BG_ID));
            m_fromButton->setIsAutoResized(
                VFX_TRUE,
                0,
                gScrnWidth - xPos - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2);
        }
        m_fromButton->setText(fromText);
        m_fromButton->forceUpdate();
        VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_fromItemText->getBounds().getHeight()) / 2;
        m_fromButton->setPos(xPos, btnTopGap);
        m_fromButton->setBounds(
            VfxRect(
                xPos,
                btnTopGap,
                m_fromButton->getBounds().getWidth(),
                m_fromItemText->getBounds().getHeight() + 2));
    }
    else
    {
        if (m_fromButton)
        {
            VFX_OBJ_CLOSE(m_fromButton);
        }
    }
    if (showRecipientBtn == VFX_TRUE)
    {
        if (m_recipientButton == NULL)
        {
            VFX_OBJ_CREATE(m_recipientButton, VcpImageButton, this);

            m_recipientButton->setImage(
                VcpStateImage(
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID));
            VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
            m_recipientButton->setPos(
                gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap);
            m_recipientButton->setBounds(
                VfxRect(
                    gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                    btnTopGap,
                    VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                    VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
        }
    }
    else
    {
        if (m_recipientButton != NULL)
        {
            VFX_OBJ_CLOSE(m_recipientButton);
            m_recipientButton = NULL;
        }
    }
}


void VappEmailMsgViewFromItem::updateLayout()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_LAYOUT);

    setHeight(EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    if (m_fromButton != NULL)
    {
        VfxU32 xPos = m_fromItemText->getBounds().getWidth() + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2;
        VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_fromButton->getBounds().getHeight()) / 2;
        m_fromButton->setIsAutoResized(
            VFX_TRUE,
            0,
            gScrnWidth - xPos - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2);
        m_fromButton->forceUpdate();
        m_fromButton->setPos(xPos, btnTopGap);
        m_fromButton->setBounds(
            VfxRect(
                xPos,
                btnTopGap,
                m_fromButton->getBounds().getWidth(),
                m_fromButton->getBounds().getHeight()));

    }
    if (m_recipientButton != NULL)
    {
        VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
        m_recipientButton->setPos(
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
            btnTopGap);
        m_recipientButton->setBounds(
            VfxRect(
                gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
                btnTopGap,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
                VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
    }
}


void VappEmailMsgViewFromItem::updateBtnIcon(VfxBool isFold)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_FROM_BTN_ICON, m_recipientButton, isFold);

    if (m_recipientButton != NULL)
    {
        if (isFold == VFX_TRUE)
        {
            m_recipientButton->setImage(
                VcpStateImage(
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID,
                    IMG_EMAIL_FTO_UNFOLD_ID));
        }
        else
        {
            m_recipientButton->setImage(
                VcpStateImage(
                    IMG_EMAIL_FTO_FOLD_ID,
                    IMG_EMAIL_FTO_FOLD_ID,
                    IMG_EMAIL_FTO_FOLD_ID,
                    IMG_EMAIL_FTO_FOLD_ID));
        }
    }
}


void VappEmailMsgViewSubjItem::onInit()
{
    VcpFormItemBase::onInit();

    m_subjView = NULL;
    m_dateView = NULL;
    m_needBtn = VFX_FALSE;
    m_btn = NULL;
}


void VappEmailMsgViewSubjItem::updateSubjItem(const VfxWString &subj, const VfxWString &date)
{
    m_needBtn = VFX_FALSE;
    if (m_subjView == NULL)
    {
        VFX_OBJ_CREATE(m_subjView, VfxTextFrame, this);
    }
    if (m_dateView == NULL)
    {
        VFX_OBJ_CREATE(m_dateView, VfxTextFrame, this);
    }

    setHeight(0);
    setSubj(subj);
    setDate(date);
    updateBtn();
    setHeight(EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_SUBJ, m_needBtn);
}


void VappEmailMsgViewSubjItem::updateBtn()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_SUBJ_BTN, m_needBtn, m_btn);

    if (m_needBtn == VFX_FALSE)
    {
        if (m_btn != NULL)
        {
            VFX_OBJ_CLOSE(m_btn);
            m_btn = NULL;
        }
        return;
    }

    if (m_btn == NULL)
    {
        VFX_OBJ_CREATE(m_btn, VcpImageButton, this);
    }

    VfxU32 middle = getBounds().size.height / 2;
    m_btn->setPos(
        gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
        middle - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH / 2);
    m_btn->setSize(VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH, VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH);
    m_btn->setImage(
        VcpStateImage(
            IMG_EMAIL_FTO_UNFOLD_ID,
            IMG_EMAIL_FTO_UNFOLD_ID,
            IMG_EMAIL_FTO_UNFOLD_ID,
            IMG_EMAIL_FTO_UNFOLD_ID));
}


void VappEmailMsgViewSubjItem::foldItem(VfxBool fold)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SUBJ_BTN_FOLD_ITEM, fold);

    /* gap between first line and top */
    VfxU32 height = EMAIL_MSG_VIEW_HEADER_TOP_GAP;
    VfxRect bounds = m_subjView->getBounds();

    if (fold)
    {
        bounds = m_subjView->getBounds();
        //bounds.size.width -= 33;
        //bounds.size.height = 22;
        {
            VfxTextFrame *textFrame;
            VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
            textFrame->setString(VFX_WSTR("bp"));
            textFrame->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
            textFrame->forceUpdate();
            bounds.size.height = textFrame->getBounds().getHeight();
            VFX_OBJ_CLOSE(textFrame);
        }
        /* gap between two lines */
        bounds.size.height += 3;

        m_subjView->setAutoResized(VFX_FALSE);
        m_subjView->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_subjView->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        m_subjView->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height);
        m_subjView->setBounds(bounds);
        m_subjView->forceUpdate();
        height += m_subjView->getBounds().getHeight();
    }
    else
    {
        /* set text view */
        m_subjView->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
        m_subjView->setAutoResized(VFX_TRUE);
        m_subjView->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_subjView->setPos(VfxPoint(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height));
        bounds.size.height = 0;
        m_subjView->setBounds(bounds);
        m_subjView->forceUpdate();
        height += 3;
        height += m_subjView->getBounds().getHeight();
    }

    /* set date view */
    m_dateView->setPos(VfxPoint(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height));
    height += m_dateView->getBounds().getHeight();
    /* gap between second line and bottom */
    height += EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP;
    if (fold)
    {
        height = EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT;
    }

    setHeight(height);

    VfxU32 middle = getBounds().getHeight() / 2;
    if (m_needBtn == VFX_TRUE)
    {
        if (m_btn == NULL)
        {
            VFX_OBJ_CREATE(m_btn, VcpImageButton, this);
        }
        m_btn->setPos(
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
            middle - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH / 2);
        m_btn->setSize(VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH, VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH);
        if (fold)
        {
            m_btn->setImage(
                VcpStateImage(
                IMG_EMAIL_FTO_UNFOLD_ID,
                IMG_EMAIL_FTO_UNFOLD_ID,
                IMG_EMAIL_FTO_UNFOLD_ID,
                IMG_EMAIL_FTO_UNFOLD_ID));
        }
        else
        {
            m_btn->setImage(
                VcpStateImage(
                IMG_EMAIL_FTO_FOLD_ID,
                IMG_EMAIL_FTO_FOLD_ID,
                IMG_EMAIL_FTO_FOLD_ID,
                IMG_EMAIL_FTO_FOLD_ID));
        }
    }
    else
    {
        if (m_btn != NULL)
        {
            VFX_OBJ_CLOSE(m_btn);
            m_btn = NULL;
        }
    }
}


void VappEmailMsgViewSubjItem::updateLayout()
{
    m_needBtn = VFX_FALSE;
    setSubj(m_subjView->getString());
    setDate(m_dateView->getString());
    updateBtn();
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_SUBJ_LAYOUT, m_needBtn);
}


void VappEmailMsgViewSubjItem::expendItem(VfxBool isFold)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SUBJ_EXPEND_ITEM, isFold, m_needBtn);
    if (m_needBtn)
    {
        foldItem(isFold);
    }
}


void VappEmailMsgViewSubjItem::setSubj(const VfxWString &subj)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SET_SUBJ);

    /* gap between first line and top */
    VfxU32 height = EMAIL_MSG_VIEW_HEADER_TOP_GAP;
    VfxRect bounds;

    m_subjView->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
    m_subjView->setMargins(0, 0, 0, 0);
    m_subjView->setAutoResized(VFX_TRUE);
    m_subjView->setPos(VfxPoint(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height));
    /* set bounds to let text view know the length of one line */
    m_subjView->setBounds(
        VfxRect(
            EMAIL_MSG_VIEW_HEADER_LEFT_GAP,
            height,
            gScrnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
            0));
    if (subj.isEmpty())
    {
        m_subjView->setString(VFX_WSTR_RES(STR_EMAIL_FTO_COMMON_NO_SUBJECT_ID));
    }
    else
    {
        m_subjView->setString(subj);
    }
    m_subjView->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
    m_subjView->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_subjView->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_subjView->forceUpdate();
    /* more than one line */
    if (m_subjView->getLineCount() > 1)
    {
        m_needBtn = VFX_TRUE;
        bounds = m_subjView->getBounds();
        bounds.size.width -= (VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_RIGHT_GAP);
        {
            VfxTextFrame *textFrame;
            VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
            textFrame->setString(VFX_WSTR("bp"));
            textFrame->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_MEDIUM));
            textFrame->forceUpdate();
            bounds.size.height = textFrame->getBounds().getHeight();
            VFX_OBJ_CLOSE(textFrame);
        }
        bounds.size.height += 3;
        //bounds.size.height = 0;
        /* gap between two lines */
        //bounds.size.height += getGapBetweenLines();
        m_subjView->setAutoResized(VFX_FALSE);
        m_subjView->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_subjView->setBounds(bounds);
        m_subjView->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        m_subjView->setBounds(bounds);
        m_subjView->forceUpdate();
    }

    height += getGapBetweenLines();
    height += m_subjView->getBounds().getHeight();

    setHeight(height);
}


void VappEmailMsgViewSubjItem::setDate(const VfxWString &date)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SET_DATE);

    VfxU32 height = getSize().height;

    m_dateView->setPos(VfxPoint(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height));
    m_dateView->setBounds(VfxRect(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, height, gScrnWidth, 0));
    m_dateView->setString(date);
    m_dateView->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_dateView->setFont(VfxFontDesc(EMAIL_MSG_VIEW_FONT_SMALL));
    height += m_dateView->getBounds().getHeight();
    /* gap between first line and top */
    height += EMAIL_MSG_VIEW_HEADER_BOTTOM_GAP;
    setHeight(height);
}


void VappEmailMsgViewTitleBar::onInit()
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


void VappEmailMsgViewTitleBar::onSetRotate(VfxScrRotateTypeEnum rotation)
{
    if(m_rotation == rotation)
    {
        return;
    }

    m_rotation = rotation;
    updateTitleLayout();    
}


void VappEmailMsgViewTitleBar::updateTitleText(VfxWString &indexText, VfxWString &fldrNameText)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_TITLEBAR);

    if (m_indexText == NULL)
    {
        VFX_OBJ_CREATE(m_indexText, VfxTextFrame, this);
    }
    VfxWString emptyText;
    emptyText.setEmpty();
    //setTitle(emptyText);
    setSize(gScrnWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT);

    VfxFontDesc font(EMAIL_MSG_VIEW_FONT_MEDIUM, VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_DROP_SHADOW);
    if (indexText.isEmpty() != VFX_TRUE)
    {
        m_indexText->setString(indexText);
    }
    m_indexText->setFont(font);
    m_indexText->setColor(VFX_COLOR_WHITE);
    m_indexText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_indexText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_indexText->forceUpdate();
    VfxU32 textTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_indexText->getBounds().getHeight()) / 2;
    m_indexText->setPos(
        VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
        textTopGap);
    m_indexText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            textTopGap,
            gScrnWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_indexText->getBounds().getHeight()));
}


void VappEmailMsgViewTitleBar::updateTitleLayout()
{
    VfxU32 screennWidth;
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
    /* update switch buttons */
    VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
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
    m_rightButton->setPos(screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP, btnTopGap);
    m_rightButton->setBounds(
        VfxRect(
            screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
            btnTopGap,
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH,
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH));
    m_rightButton->setEffectOffset(
        VfxPoint(
            screennWidth - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH - 2,
            btnTopGap - 1));

    /* update text */
    VfxU32 textTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - m_indexText->getBounds().getHeight()) / 2;
    m_indexText->setPos(
        VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
        textTopGap);
    m_indexText->setBounds(
        VfxRect(
            VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH + EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 2,
            textTopGap,
            screennWidth - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH * 2 - EMAIL_MSG_VIEW_HEADER_LEFT_GAP * 4,
            m_indexText->getBounds().getHeight()));
    m_indexText->forceUpdate();
}


void VappEmailMsgViewTitleBar::updateButtons(VfxBool showSwitchBtn)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_TITLEBAR_BTN, showSwitchBtn);

    VfxU32 btnTopGap = (EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT - VAPP_EMAIL_TITLE_BAR_BUTTON_WIDTH) / 2;
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

    if (showSwitchBtn)
    {
        m_leftButton->setIsDisabled(VFX_FALSE);
        m_rightButton->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_leftButton->setIsDisabled(VFX_TRUE);
        m_rightButton->setIsDisabled(VFX_TRUE);
    }
    updateTitleLayout();
}


VfxBool VappEmailMsgViewPage::m_asyncParse = VFX_FALSE;


VappEmailMsgViewPage::VappEmailMsgViewPage(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID, EMAIL_MSG_ID msgID)
    :m_titleBar(NULL),
     m_msgForm(NULL),
     m_fromItem(NULL),
     m_recipientItemTo(NULL),
     m_recipientItemCc(NULL),
     m_recipientItemBcc(NULL),
     m_subjItem(NULL),
     m_htmlItem(NULL),
     m_msgCont(NULL),
     m_attachBtn(NULL),
     m_toolbar(NULL),
     m_deleteConfirmPage(NULL),
     m_useDetailsPage(NULL),
     m_loadingPopup(NULL),
     m_acctID(acctID),
     m_fldrID(fldrID),
     m_msgID(msgID),
     m_dialerID(0),
     m_phbID(0),
     m_bkmID(0),
     m_msgHandle(EMAIL_MSG_INVALID_HANDLE),
     m_isGetHtmlFile(VFX_FALSE),
     m_getHtmlFileReqID(EMAIL_REQ_INVALID_ID),
     m_isAddrFold(VFX_TRUE),
     m_isSubjFold(VFX_TRUE),     
     m_deleteMsg(VFX_FALSE),
     m_isPageDisabled(VFX_FALSE),
     m_popupShowed(VFX_FALSE),
     m_msgBasicInfo(NULL)
{
    
}


VappEmailMsgViewPage::VappEmailMsgViewPage()
{
}


void VappEmailMsgViewPage::onInit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_PAGE_INIT, m_msgID);

    VFX_ALLOC_MEM(gContent, (EMAIL_CONTENT_LENGTH + 128 + 128 + 1) * 2, getMainScr());
    VFX_ALLOC_MEM(gAttachInfoArray, sizeof(srv_email_attach_struct) * MMI_EMAIL_MAX_ATTACH_NUMBER, getMainScr());
    VFX_ALLOC_MEM(gSaveAttachPath, sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1), getMainScr());

#if defined(__MMI_EMAIL_HTML__)
    VFX_ALLOC_MEM(gHtmlFilePath, sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1), getMainScr());
    #if defined(OPERA_V10_BROWSER)
    VFX_ALLOC_MEM(gHtmlAttInfo, sizeof(OperaApi_MimeInfo) * MMI_EMAIL_MAX_ATTACH_NUMBER, getMainScr());
    #else /* OPERA_V10_BROWSER */
    VFX_ALLOC_MEM(gHtmlParserContent, sizeof(VappEmailContentParser), getMainScr());
    memset(gHtmlParserContent, 0, sizeof(VappEmailContentParser));
    VFX_ALLOC_MEM(gNotConvertedStringData, 20, getMainScr());
    #endif /* OPERA_V10_BROWSER */
#endif /* __MMI_EMAIL_HTML__ */

#ifdef __DRM_SUPPORT__
    VFX_ALLOC_MEM(gRightsIssuer, DRM_MAX_URL_LENGTH, getMainScr());
#endif

    VfxPage::onInit();

    if (getMainScr()->getPageCount() <= 1)
    {
        VappEmailMgr::getInstance()->enterAcct(m_acctID);
    }
    VappEmailMgr::getInstance()->m_signalMsgNwkDone.connect(this, &VappEmailMsgViewPage::onRetrieveDone);
    VappEmailMgr::getInstance()->m_signalMsgDelete.connect(this, &VappEmailMsgViewPage::onMsgDelete);
    VappEmailMgr::getInstance()->m_signalFldrMsgNumChange.connect(this, &VappEmailMsgViewPage::onMsgNumChange);
    VappEmailMgr::getInstance()->m_signalFldrStateChange.connect(this, &VappEmailMsgViewPage::onFldrStateChange);    
    VappEmailMgr::getInstance()->m_signalMsgChange.connect(this, &VappEmailMsgViewPage::onMsgChange);
    VappEmailMgr::getInstance()->m_signalMsgStateChange.connect(this, &VappEmailMsgViewPage::onMsgStateChange);
    VappEmailMgr::getInstance()->m_signalAcctNwkDone.connect(this, &VappEmailMsgViewPage::onAcctNwkDone);
    
    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);

    if (updateMsgInfo() == VFX_FALSE)
    {
        return;
    }

    updateAttachInfo();
    updateTitleBar();
    updateMsgHeader();
    updateMsgContent();
    updateToolbar();    /* use content information to enable or disable use details button at toolbar */

    gKeywordContent.setEmpty();
}


void VappEmailMsgViewPage::onDeinit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_PAGE_DEINIT, m_msgID, m_bkmID, m_dialerID, m_phbID);

    VfxPage::onDeinit();

    VFX_FREE_MEM(gContent);
    gContent = NULL;
    VFX_FREE_MEM(gAttachInfoArray);
    gAttachInfoArray = NULL;
    VFX_FREE_MEM(gSaveAttachPath);
    gSaveAttachPath = NULL;

#if defined(__MMI_EMAIL_HTML__)
    VFX_FREE_MEM(gHtmlFilePath);
    gHtmlFilePath = NULL;
    #if defined(OPERA_V10_BROWSER)
        VFX_FREE_MEM(gHtmlAttInfo);
        gHtmlAttInfo = NULL;
    #else /* OPERA_V10_BROWSER */       
        if (gHtmlParserContent->convert_buffer != NULL)
        {
            free_ctrl_buffer(gHtmlParserContent->convert_buffer);
            gHtmlParserContent->convert_buffer = NULL;
        }
        FS_Close(gHtmlParserContent->file_h);
        if (gHtmlParserContent->html_data_buff_ptr != NULL)
        {
            free_ctrl_buffer(gHtmlParserContent->html_data_buff_ptr);
            gHtmlParserContent->html_data_buff_ptr = NULL;
        }
        VFX_FREE_MEM(gHtmlParserContent);
        gHtmlParserContent = NULL;
        VFX_FREE_MEM(gNotConvertedStringData);
        gNotConvertedStringData = NULL;
    #endif /* OPERA_V10_BROWSER */
#endif /* __MMI_EMAIL_HTML__ */

#ifdef __DRM_SUPPORT__
    VFX_FREE_MEM(gRightsIssuer);
    gRightsIssuer = NULL;
#endif

    if (m_bkmID != 0)
    {
        vcui_bkm_add_bkm_close(m_bkmID);
        m_bkmID = 0;
    }
    if (m_dialerID != 0)
    {
        vcui_dialer_close(m_dialerID);
        m_dialerID = 0;
    }
    if (m_phbID != 0)
    {
        vcui_phb_contact_saver_close(m_phbID);
        m_phbID = 0;
    }

    if (m_msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        if (m_getHtmlFileReqID != EMAIL_REQ_INVALID_ID)
        {
            srv_email_msg_abort(m_msgHandle, m_getHtmlFileReqID);
            m_getHtmlFileReqID = EMAIL_REQ_INVALID_ID;
        }

        srv_email_msg_destroy(m_msgHandle);
        m_msgHandle = EMAIL_MSG_INVALID_HANDLE;
    }

    VFX_FREE_MEM(m_msgBasicInfo);


    if (getMainScr()->getPageCount() <= 1)
    {
        VappEmailMgr::getInstance()->exitAcct(m_acctID);
    }

    VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);
}


VfxBool VappEmailMsgViewPage::updateMsgInfo()
{
    srv_email_result_enum result;

    if (m_msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(m_msgHandle);
        m_msgHandle = EMAIL_MSG_INVALID_HANDLE;
    }

    if (m_msgBasicInfo != NULL)
    {
        VFX_FREE_MEM(m_msgBasicInfo);
    }

    result = srv_email_msg_create(gEmailSrvHandle, &m_msgHandle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_FALSE;
    }
    result = srv_email_msg_open(m_msgHandle, m_acctID, m_fldrID, m_msgID);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_FALSE;
    }

    if (m_msgBasicInfo == NULL)
    {
        VFX_ALLOC_MEM(m_msgBasicInfo, sizeof(srv_email_msg_get_basic_info_struct), getMainScr());
    }

    result = srv_email_msg_get_basic_info(m_msgHandle, m_msgBasicInfo);
    
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappEmailMsgViewPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (!isBackward)
    {
        setMsgAsRead();
    }

    if (isBackward)
    {
        resetSwitchBtnState();        
    }
}


VfxBool VappEmailMsgViewPage::onKeyInput(VfxKeyEvent &event)
{
    if (m_titleBar != NULL &&
        m_titleBar->getLeftBtn() != NULL &&
        m_titleBar->getRightBtn() != NULL &&
        m_titleBar->getLeftBtn()->getState() != VCP_IMAGE_BUTTON_STATE_DISABLED &&
        m_titleBar->getRightBtn()->getState() != VCP_IMAGE_BUTTON_STATE_DISABLED)
    {
        /* follow BD's rule, handle key event down and long press */
        if (event.specialKeyFlag == 0 &&
            (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
             event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS ||
             event.type == VFX_KEY_EVENT_TYPE_REPEAT))
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
            {
                onTitleLBtnClick(NULL, 0);
            }
            else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
            {
                onTitleRBtnClick(NULL, 0);
            }
        }

        if (event.specialKeyFlag == 0)
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                {
                    m_titleBar->getLeftBtn()->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
                }
                else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
                {
                    m_titleBar->getRightBtn()->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
                }
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                {
                    m_titleBar->getLeftBtn()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
                }
                else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
                {
                    m_titleBar->getRightBtn()->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
                }
            }
        }
    }

    /* do not stop route key event to let other CP have opportunity to handle key event */
    return VfxPage::onKeyInput(event);
}


void VappEmailMsgViewPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == param.rotateFrom)
    {
        return;
    }

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

    if (m_attachBtn != NULL)
    {
        m_attachBtn->setSize(
            gScrnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
            EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT);
        m_attachBtn->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
        m_attachBtn->forceUpdate();
    }
    updateMsgHeaderLayout();
}


void VappEmailMsgViewPage::onTBClick(VfxObject *, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_PAGE_TB_CLICK, id);

    switch (id)
    {
    case MSG_VIEW_PAGE_TB_REPLY:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, m_msgID, VappEmailComp::EMAIL_MODE_REPLY);
        }
        break;
    case MSG_VIEW_PAGE_TB_REPLY_ALL:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, m_msgID, VappEmailComp::EMAIL_MODE_REPLY_ALL);
        }
        break;
    case MSG_VIEW_PAGE_TB_FORWARD:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            mainScr->launchComposer(EMAIL_ACCT_INVALID_ID, m_msgID, VappEmailComp::EMAIL_MODE_FWD);
        }
        break;
    case MSG_VIEW_PAGE_TB_USE_DETAILS:
        {
            VfxMainScr* viewScrn = getMainScr();
            VFX_OBJ_CREATE_EX(
                m_useDetailsPage,
                VappEmailMsgViewUseDetailsPage,
                viewScrn,
                (m_msgCont));
            viewScrn->pushPage(EMAIL_PAGE_TYPE_USE_DETAILS, m_useDetailsPage);
        }
        break;
    case MSG_VIEW_PAGE_TB_MOVE_TO_DRAFTS:
        {
            VfxU32 index;
            VfxU32 total;
            VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
            EMAIL_MSG_ID msgID = mainScrn->getNextMsgID(m_msgID, index, total);

            srv_email_result_enum result;
            do
            {
                EMAIL_MSG_ID msgID;
                EMAIL_FLDR_ID fldrID = srv_email_fldr_type_to_fldr_id(m_acctID, SRV_EMAIL_FLDR_TYPE_DRAFT);
                /* the message delete signal is right after msg_move, so this member should be set before msg_move */
                m_deleteMsg = VFX_TRUE;
                result = srv_email_msg_move(m_msgHandle, m_acctID, fldrID, &msgID);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    m_deleteMsg = VFX_FALSE;
                }
            } while(0);
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
                mainScrn->closePage(EMAIL_PAGE_TYPE_MSG_VIEW);
            }
            else
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
                errorPopup->showErrorPopup(result);
            }
        }
        break;
    case MSG_VIEW_PAGE_TB_DELETE:
        {
            VFX_OBJ_CREATE(m_deleteConfirmPage, VcpConfirmPopup, this);
            m_deleteConfirmPage->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_deleteConfirmPage->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_deleteConfirmPage->setText(VFX_WSTR_RES(STR_EMAIL_FTO_DEL_MSG_CONFIRM_ID));
            VfxWString btnText1;
            btnText1.loadFromRes(STR_GLOBAL_DELETE);
            VfxWString btnText2;
            btnText2.loadFromRes(STR_GLOBAL_CANCEL);
            m_deleteConfirmPage->setCustomButton(
                btnText1,
                btnText2,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_deleteConfirmPage->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onDeleteConfirmBtnClick);
            m_deleteConfirmPage->setAutoDestory(VFX_TRUE);
            m_deleteConfirmPage->show(VFX_TRUE);
        }
        break;
    case MSG_VIEW_PAGE_TB_MARK_AS_UNREAD:
        {
            srv_email_result_enum result;
            do
            {
                result = srv_email_msg_set_flag(m_msgHandle, EMAIL_MSG_FLAG_SEEN, !EMAIL_MSG_FLAG_SEEN);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
            } while(0);

            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_TRUE);
            }
            else
            {
                /* popup error */
            }
        }
        break;
    default:
        return;
    }
}


void VappEmailMsgViewPage::onFromBtnClick(VfxObject *, VfxId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_FROM_BTN_CLICK);

    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_addr_struct *sender = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));

    do
    {
        result = srv_email_msg_get_sender(m_msgHandle, sender);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (sender->disp_name_len != 0)
        {
            gIsKeywordContentAddr = VFX_FALSE;
            gKeywordContent.loadFromMem(sender->disp_name);
            gKeywordContentBackUp.loadFromMem(sender->email_addr);
        }
        else
        {
            gIsKeywordContentAddr = VFX_TRUE;
            gKeywordContent.loadFromMem(sender->email_addr);
        }
    } while(0);

    free_ctrl_buffer(sender);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        errorPopup->showErrorPopup(result);
        return;
    }

    gIsSavePhoneNumber = VFX_FALSE;

    VcpCommandPopup *addrOperationPopup;
    VFX_OBJ_CREATE(addrOperationPopup, VcpCommandPopup, this);
    addrOperationPopup->setText(gKeywordContent);
    VfxWString text;
    text.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_CANCEL);
    addrOperationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL, text, VCP_POPUP_BUTTON_TYPE_CANCEL);
    addrOperationPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onKeywordOperationClick);
    addrOperationPopup->show(VFX_TRUE);
}


void VappEmailMsgViewPage::onContentKeywordClick(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len)
{
    VfxWChar tempChar = text[len];
    text[len] = 0;
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    VcpCommandPopup *keywordPopup;
    VFX_OBJ_CREATE(keywordPopup, VcpCommandPopup, this);
    keywordPopup->setAutoDestory(VFX_TRUE);
    gKeywordContent.loadFromMem(text);
    text[len] = tempChar;
    keywordPopup->setText(gKeywordContent);
    VfxWString commandText;

    /* reset */
    gIsSavePhoneNumber = VFX_FALSE;

    switch (mode)
    {
    case VCP_TEXT_KEYWORD_EMAIL:
        {
            gIsKeywordContentAddr = VFX_TRUE;
            commandText.loadFromRes(STR_EMAIL_FTO_SEND_MAIL_ID);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL, commandText);
            commandText.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, commandText);
            commandText.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, commandText);
        }
        break;
    case VCP_TEXT_KEYWORD_URL:
        {
            commandText.loadFromRes(STR_GLOBAL_GO_TO_URL);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_GO_TO_URL, commandText);
        #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
            commandText.loadFromRes(STR_EMAIL_FTO_URL_SAVE_FTO_BOOKMARK_ID);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SAVE_TO_BOOKMARKS, commandText);
        #endif /* #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__) */
        }
        break;
    case VCP_TEXT_KEYWORD_PHONENUMBER:
        {
            gIsSavePhoneNumber = VFX_TRUE;
            commandText.loadFromRes(STR_GLOBAL_EDIT_BEFORE_CALL);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_EDIT_BEFORE_CALL, commandText);
            commandText.loadFromRes(STR_GLOBAL_SEND_MESSAGE);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_MESSAGE, commandText);
            commandText.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, commandText);
            commandText.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, commandText);
        }
        break;
    default:
        VFX_OBJ_CLOSE(keywordPopup);
        return;
    }
    commandText.loadFromRes(STR_GLOBAL_CANCEL);
    keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL, commandText, VCP_POPUP_BUTTON_TYPE_CANCEL);
    keywordPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onKeywordOperationClick);
    keywordPopup->show(VFX_TRUE);
}


void VappEmailMsgViewPage::onRecipientBtnClick(VfxObject* sender, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_RECIPIENT_BTN_CLICK);

    if (m_isAddrFold)
    {
        /* addr item */
        addRecipientItem();
        m_fromItem->updateBtnIcon(VFX_FALSE);
    }
    else
    {
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO);
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC);
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_BCC);
        m_recipientItemTo = NULL;
        m_recipientItemCc = NULL;
        m_recipientItemBcc = NULL;
        m_isAddrFold = VFX_TRUE;
        m_fromItem->updateBtnIcon(VFX_TRUE);
    }
    msgHeaderUpdated();
}


void VappEmailMsgViewPage::onRecipientListToBtnClick(VfxObject *obj, VfxId id)
{
    onRecipientListBtnClick(EMAIL_MSG_VIEW_RECIPIENT_TO);
}


void VappEmailMsgViewPage::onRecipientListCcBtnClick(VfxObject *, VfxId)
{
    onRecipientListBtnClick(EMAIL_MSG_VIEW_RECIPIENT_CC);
}


void VappEmailMsgViewPage::onRecipientListBtnClick(EmailMsgViewRecipientTypeEnum type)
{    
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    VappEmailMsgViewRecipientPage *recipientPage;
    VFX_OBJ_CREATE_EX(
        recipientPage,
        VappEmailMsgViewRecipientPage,
        mainScr,
        (m_acctID, m_fldrID, m_msgID, type));
    mainScr->pushPage(EMAIL_PAGE_TYPE_RECIPIENT_LIST, recipientPage);
}


void VappEmailMsgViewPage::onLoadingBtnClick(VfxObject *, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_LOADING_CANCEL);
        if (m_isGetHtmlFile)
        {
            cancelGetHtmlFile();
        }
        else
        {
            VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);
        }
            
        closeLoading();
    }
    else if (VCP_POPUP_BUTTON_NO_PRESSED)
    {

        //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_LOADING_CANCEL);
        //VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);
        //closeLoading();
    }

}


void VappEmailMsgViewPage::updateMsgHeaderLayout()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_FORM_LAYOUT);

    /* no from item in Outbox */
    if (m_fromItem != NULL)
    {
        m_fromItem->updateLayout();
    }

    if (m_isPageDisabled == VFX_TRUE)
    {
        if (m_recipientItemTo != NULL)
        {
            m_recipientItemTo->updateLayout();
        }
        if (m_recipientItemCc != NULL)
        {
            m_recipientItemCc->updateLayout();
        }
        if (m_recipientItemBcc != NULL)
        {
            m_recipientItemBcc->updateLayout();
        }
    }
    else
    {
        if (m_recipientItemTo != NULL || m_recipientItemCc != NULL || m_recipientItemBcc != NULL)
        {
            m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO);
            m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC);
            m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_BCC);
            m_recipientItemTo = NULL;
            m_recipientItemCc = NULL;
            m_recipientItemBcc = NULL;
            addRecipientItem();
        }
    }

    m_subjItem->updateLayout();
    /* rotate form 90 to 0 and unfold button is showed again */
    m_subjItem->expendItem(m_isSubjFold);
    msgHeaderUpdated();
    VcpImageButton *btn = m_subjItem->getBtn();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onSubjBtnClick);
    }
    if (m_htmlItem != NULL)
    {
        m_htmlItem->updateLayout();
    }
}


void VappEmailMsgViewPage::retrieveContent()
{
    srv_email_prot_type_enum protocol;
    srv_email_acct_info_cache_struct *cacheData =
        (srv_email_acct_info_cache_struct*)get_ctrl_buffer(sizeof(srv_email_acct_info_cache_struct));
    srv_email_acct_cache_get(m_acctID, cacheData);
    protocol = cacheData->protocol;
    free_ctrl_buffer(cacheData);
    if (protocol == SRV_EMAIL_PROT_POP3)
    {
        VappEmailMgr::getInstance()->retrieveMsg(m_msgID, SRV_EMAIL_RETRIEVE_ALL_PARTS);
    }
    else
    {
        VappEmailMgr::getInstance()->retrieveMsg(m_msgID, SRV_EMAIL_RETRIEVE_ALL_CONTENT);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_RETRIEVE_CONT, protocol);

    showLoading(VFX_TRUE, VFX_TRUE);
}


void VappEmailMsgViewPage::disablePage()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_DISABLE_PAGE);
    
    m_isPageDisabled = VFX_TRUE;
    //VfxPage *attachListPage = getMainScr()->getPage(EMAIL_PAGE_TYPE_ATTACH_LIST);
    //VFX_OBJ_CLOSE(attachListPage);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY_ALL, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_FORWARD, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_SEND, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_USE_DETAILS, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_DELETE, VFX_TRUE);
    m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_TRUE);
    if (m_fromItem != NULL)
    {
        m_fromItem->disableAllBtn();
    }
    if (m_recipientItemTo != NULL)
    {
        m_recipientItemTo->disableAllBtn();
    }
    if (m_recipientItemCc != NULL)
    {
        m_recipientItemCc->disableAllBtn();
    }
    if (m_recipientItemBcc != NULL)
    {
        m_recipientItemBcc->disableAllBtn();
    }
    if (m_htmlItem != NULL)
    {
        m_htmlItem->disableBtn();
    }
    if (m_attachBtn != NULL)
    {
        m_attachBtn->setIsDisabled(VFX_TRUE);
    }

    if (m_titleBar != NULL)
    {
        m_titleBar->disableAllBtn();
    }
}


void VappEmailMsgViewPage::showNotDownloadAllPopup()
{
    if (m_popupShowed == VFX_TRUE)
    {
        return;
    }

    VfxBool recipientTooMany = VFX_FALSE;
    VfxBool attachTooMany = VFX_FALSE;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    if (m_msgBasicInfo->remain_to_addr_num != 0 ||
        m_msgBasicInfo->remain_cc_addr_num != 0)
    {
        recipientTooMany = VFX_TRUE;
    }
    if (m_msgBasicInfo->remain_attach_num != 0)
    {
        attachTooMany = VFX_TRUE;
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return;
    }

    if (recipientTooMany == VFX_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SHOW_RECIPIENT_TOO_MANY);
        VcpConfirmPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VcpConfirmPopup, this);
        errorPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        errorPopup->setAutoDestory(VFX_TRUE);
        errorPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_RECIPIENT_TOO_MANY_ID));
        errorPopup->show(VFX_TRUE);
        if (attachTooMany == VFX_TRUE)
        {
            errorPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onNotDownloadAllBtnClick);
        }
        else
        {
            errorPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onPopupBtnClick);
        }

        m_popupShowed = VFX_TRUE;
    }
    else if (attachTooMany == VFX_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SHOW_ATTACHMENT_TOO_MANY);
        VcpConfirmPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VcpConfirmPopup, this);
        errorPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        errorPopup->setAutoDestory(VFX_TRUE);
        errorPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_ATTACH_NOT_COMPLETE_ID));
        errorPopup->show(VFX_TRUE);
        errorPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onPopupBtnClick);

        m_popupShowed = VFX_TRUE;
    }
}


void VappEmailMsgViewPage::onNotDownloadAllBtnClick(VfxObject *, VfxId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SHOW_ATTACHMENT_TOO_MANY);
    VcpConfirmPopup *errorPopup;
    VFX_OBJ_CREATE(errorPopup, VcpConfirmPopup, this);
    errorPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    errorPopup->setAutoDestory(VFX_TRUE);
    errorPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_ATTACH_NOT_COMPLETE_ID));
    errorPopup->show(VFX_TRUE);
    errorPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onPopupBtnClick);
}


void VappEmailMsgViewPage::onPopupBtnClick(VfxObject *, VfxId)
{
    resetSwitchBtnState();
}

void VappEmailMsgViewPage:: setMsgAsRead()
{
    /* set email flag as seen */
    do
    {
        if (m_msgBasicInfo->flag != EMAIL_MSG_FLAG_SEEN)
        {
             srv_email_msg_set_flag(m_msgHandle, EMAIL_MSG_FLAG_SEEN, EMAIL_MSG_FLAG_SEEN);
        }
    }while(0);
};


void VappEmailMsgViewPage::getMsgBasicInfo(
        VfxBool *showHtmlBtn,
        VfxBool *showReadMoreBtn,
        VfxBool *showAttachBtn,
        VfxBool *hasTextCont,
        S8* htmlStatus)
{
    if (showHtmlBtn != NULL)
    {
        *showHtmlBtn = VFX_FALSE;
    }
    if (showReadMoreBtn != NULL)
    {
        *showReadMoreBtn = VFX_FALSE;
    }
    if (showAttachBtn != NULL)
    {
        *showAttachBtn = VFX_FALSE;
    }
    if (hasTextCont != NULL)
    {
        *hasTextCont = VFX_FALSE;
    }
    if (htmlStatus != NULL)
    {
        *htmlStatus = VFX_FALSE;
    }

    S8 tHtmlStatus = 0;
    S8 textStatus = 0;

    do
    {
        srv_email_result_enum result;
        if (m_msgBasicInfo->attach_num != 0)
        {
            if (showAttachBtn != NULL)
            {
                *showAttachBtn = VFX_TRUE;
            }
        }
        if (m_msgBasicInfo->state & SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH)
        {
            if (showReadMoreBtn != NULL)
            {
                *showReadMoreBtn = VFX_TRUE;
            }
        }
        result = srv_email_msg_cont_status(m_msgHandle, &textStatus, &tHtmlStatus);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (htmlStatus != NULL)
        {
            *htmlStatus = tHtmlStatus;
        }
        if (tHtmlStatus & SRV_EMAIL_MSG_CONT_PART_EXIST &&
            ((tHtmlStatus & SRV_EMAIL_MSG_CONT_DOWNLOADED) != SRV_EMAIL_MSG_CONT_DOWNLOADED))
        {
            if (showReadMoreBtn != NULL)
            {
                *showReadMoreBtn = VFX_TRUE;
            }
        }
        if (textStatus & SRV_EMAIL_MSG_CONT_PART_EXIST &&
            textStatus & SRV_EMAIL_MSG_CONT_DOWNLOADED)
        {
            if (hasTextCont != NULL)
            {
                *hasTextCont = VFX_TRUE;
            }
        }
        if (tHtmlStatus & SRV_EMAIL_MSG_CONT_PART_EXIST &&
            tHtmlStatus & SRV_EMAIL_MSG_CONT_DOWNLOADED)
        {
            if (showHtmlBtn != NULL)
            {
            #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
                *showHtmlBtn = VFX_TRUE;
            #endif
            }
        }
    } while (0);
}


void VappEmailMsgViewPage::onAttachBtnClick(VfxObject*, VfxId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_ATTACH_BTN_CLICK);
    VfxMainScr* viewScrn = getMainScr();
    VappEmailMsgViewAttachPage *attachPage;
    VFX_OBJ_CREATE_EX(
        attachPage,
        VappEmailMsgViewAttachPage,
        viewScrn,
        (m_acctID, m_fldrID, m_msgID));
    viewScrn->pushPage(EMAIL_PAGE_TYPE_ATTACH_LIST, attachPage);
}


void VappEmailMsgViewPage::onHtmlBtnClick(VfxObject*, VfxId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_HTML_BTN_CLICK);

#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    srv_email_result_enum result;
    U32 pathLen = SRV_FMGR_PATH_MAX_LEN + 1;
    EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;

    do
    {
        result = srv_email_msg_regist_callback(
                    m_msgHandle, 
                    getHtmlFileCallback,
                    getObjHandle());

        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        
        result = srv_email_msg_get_html_path_async(
                    m_msgHandle,
                    gHtmlFilePath,
                    pathLen,
                    &reqId);
        
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            break;
        }

        m_getHtmlFileReqID = reqId;
    } while(0);

    if (result != SRV_EMAIL_RESULT_SUCC &&
        result != SRV_EMAIL_RESULT_WOULDBLOCK )
    {
        /* handle error */
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup(result);
        return;
    }

    showLoading(VFX_TRUE, VFX_FALSE, VFX_TRUE);
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */
}


void VappEmailMsgViewPage::getHtmlFileCallback(
                                srv_email_result_struct *result,
                                EMAIL_REQ_ID req_id,
                                void *user_data)
{
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    U32 i = 0, total = 0;
    applib_mime_type_struct *mimeInfo = NULL;
    char operaTitle[20] = {0};
    char *charset;

    VappEmailMsgViewPage *inst = (VappEmailMsgViewPage *)handleToObject((VfxObjHandle)user_data);

    if (inst == NULL)
    {
      return;
    }

    inst->closeLoading();
    
    if (result->result != MMI_TRUE)
    {
        inst->m_isGetHtmlFile = EMAIL_REQ_INVALID_ID;
        
        /* handle error */
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, inst);
        errorPopup->showErrorPopup(vapp_email_util_get_err_code(result->major, result->minor));
        return;
    }

    /* prepare HTML attachments  */
    memset(gHtmlAttInfo, 0, sizeof(OperaApi_MimeInfo) * MMI_EMAIL_MAX_ATTACH_NUMBER);
    for (; i < MMI_EMAIL_MAX_ATTACH_NUMBER; i++)
    {
        if (gAttachInfoArray[i].attach_id == EMAIL_ATTCH_INVALID_ID)
        {
            break;
        }
        if (!gAttachInfoArray[i].downloaded ||
#ifdef __DRM_SUPPORT__
            gAttachInfoArray[i].drm_object ||
#endif
            (strlen(gAttachInfoArray[i].cid) == 0))
        {
            continue;
        }
        gHtmlAttInfo[total].cid = gAttachInfoArray[i].cid;
        gHtmlAttInfo[total].path = (CHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            (mmi_chset_enum)MMI_CHSET_UTF8,
            (char*)gAttachInfoArray[i].path,
            (char*)gHtmlAttInfo[total].path,
            (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
        gHtmlAttInfo[total].name = (CHAR*)get_ctrl_buffer((EMAIL_ATTCH_FILE_NAME_LEN + 1) * sizeof(CHAR));
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            (mmi_chset_enum)MMI_CHSET_UTF8,
            (char*)gAttachInfoArray[i].name,
            (char*)gHtmlAttInfo[total].name,
            (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
        mimeInfo = applib_mime_get_file_type((WCHAR*)gAttachInfoArray[i].name);
        if (mimeInfo == NULL)
        {
            gHtmlAttInfo[total].mime = NULL;
        }
        else
        {
            gHtmlAttInfo[total].mime = mimeInfo->mime_string;
        }
        total++;
    }

    CHAR *filepathTemp = (CHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
    CHAR *filepathData = (CHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
    mmi_wcs_to_asc((CHAR*)filepathTemp, gHtmlFilePath);
    memcpy(filepathData, filepathTemp, (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(CHAR));
    free_ctrl_buffer(filepathTemp);
    mmi_chset_convert(
        (mmi_chset_enum)MMI_CHSET_UCS2,
        MMI_CHSET_UTF8,
        (char*)GetString(STR_GLOBAL_EMAIL),
        (char*)operaTitle,
        20);
    charset = (char*)chset_get_preferred_mime_name(CHSET_UTF8);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_CALL_OPERA_API, __LINE__);
    OperaApi_ShowEmail(
        (char*)filepathData,
        (char*)operaTitle,
        charset,
        total,
        (OperaApi_MimeInfo*)gHtmlAttInfo,
        NULL);
    free_ctrl_buffer(filepathData);
    for (i = 0; i < total; i++)
    {
        free_ctrl_buffer(gHtmlAttInfo[i].path);
        free_ctrl_buffer(gHtmlAttInfo[i].name);
    }
    inst->m_isGetHtmlFile = EMAIL_REQ_INVALID_ID;
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */
}


void VappEmailMsgViewPage::cancelGetHtmlFile()
{
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    if (m_msgHandle == EMAIL_MSG_INVALID_HANDLE ||
        m_getHtmlFileReqID == EMAIL_REQ_INVALID_ID)
    {
        return;
    }

    srv_email_msg_abort(m_msgHandle, m_getHtmlFileReqID);
    m_getHtmlFileReqID = EMAIL_REQ_INVALID_ID;
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */  
}


void VappEmailMsgViewPage::onReadMoreBtnClick(VcpTextView*, VfxWString)
{
    if (m_isPageDisabled == VFX_TRUE)
    {
        return;
    }

    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(m_acctID);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_READ_MORE_BTN_CLICK, emailState, acctState);

    if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
    }

    if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
    {
        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_STOP_NETWORK_CONFIRM));
        VfxWString btnText1;
        btnText1.loadFromRes(STR_GLOBAL_CONTINUE);
        VfxWString btnText2;
        btnText2.loadFromRes(STR_GLOBAL_CANCEL);
        confirmPopup->setCustomButton(
            btnText1,
            btnText2,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        confirmPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewPage::onReadMoreConfirmBtnClick);
        confirmPopup->setAutoDestory(VFX_TRUE);
        confirmPopup->show(VFX_TRUE);
        return;
    }

    retrieveContent();
}


void VappEmailMsgViewPage::updateMsgViewer()
{
    updateAttachInfo();
    updateMsgHeader();
    updateMsgContent();
}


void VappEmailMsgViewPage::updateMsgHeader()
{
    if (m_recipientItemTo != NULL)
    {
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO);
        m_recipientItemTo = NULL;
    }
    if (m_recipientItemCc != NULL)
    {
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC);
        m_recipientItemCc = NULL;
    }
    if (m_recipientItemBcc != NULL)
    {
        m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_BCC);
        m_recipientItemBcc = NULL;
    }
    if (m_msgForm == NULL)
    {
        VFX_OBJ_CREATE(m_msgForm, VcpForm, this);
        m_msgForm->setBgColor(VFX_COLOR_TRANSPARENT);
        m_msgForm->setContentTopGap(0);
        m_msgForm->setPos(0, 0);
        m_msgForm->setSize(gScrnWidth, EMAIL_MSG_VIEW_HEADER_ITEM_HEIGHT * 2);
        m_msgForm->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
        m_msgHeaderFrame.setFrame(m_msgForm);
        m_msgHeaderFrame.setRange(0, 0);
        m_msgHeaderFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);
    }
    m_isPageDisabled = VFX_FALSE;
    //updateAttachInfo();

    srv_email_result_enum result;

    do
    {
        /* update three items of form */
        result = updateFromItem();
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = updateSubjItem();
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX ||
            srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_SENT)
        {
            addRecipientItem();
            m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_FROM);
            m_fromItem = NULL;
        }
        else
        {
            if (m_isAddrFold != VFX_TRUE)
            {
                addRecipientItem();
                m_fromItem->updateBtnIcon(VFX_FALSE);
            }
        }
    } while(0);

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        showNotDownloadAllPopup();
    }
    else
    {
        return;
    }

    m_subjItem->expendItem(m_isSubjFold);

    /* update form's bounds */
    m_msgForm->setSize(m_msgForm->getBounds().getWidth(), m_msgForm->getContentSize().height);
}


void VappEmailMsgViewPage::updateMsgContent()
{
    VfxBool hasTextCont = VFX_TRUE;
    S8 htmlStatus;
    getMsgBasicInfo(NULL, NULL, NULL, &hasTextCont, &htmlStatus);
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    do
    {
        /* init content buffer to avoid calculate wrong string length; 'ABABABAB' for ASM buffer */
        memset(gContent, 0, (EMAIL_CONTENT_LENGTH + 128 + 128 + 1) * 2);
        if (hasTextCont == VFX_TRUE)
        {
            U32 contentLen = EMAIL_CONTENT_LENGTH + 128 + 128 + 1 - 10; // reserve enough space for "...More"
            result = srv_email_msg_get_content(m_msgHandle, MMI_TRUE, gContent, &contentLen);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
        }
        else
        {
            if (htmlStatus & SRV_EMAIL_MSG_CONT_PART_EXIST &&
                htmlStatus & SRV_EMAIL_MSG_CONT_DOWNLOADED)
            {
            #if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER))
                gContLen = 0;
                /* get plain text content from html */
                CHAR *charsetString = (CHAR*)get_ctrl_buffer(50+1);
                U32 pathLen = SRV_FMGR_PATH_MAX_LEN + 1;
                result = srv_email_msg_get_html_file(
                            m_msgHandle,
                            gHtmlFilePath,
                            &pathLen,
                            charsetString,
                            MMI_FALSE);
                mmi_chset_get_charset_id((const kal_int8*)charsetString, (mmi_chset_enum*)&gHtmlCharset);
                VappEmailMsgViewPage::mmi_email_read_extract_html(this);
                free_ctrl_buffer(charsetString);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                result = SRV_EMAIL_RESULT_WOULDBLOCK;
                if (m_asyncParse == VFX_TRUE)
                {
                    showLoading();
                }
            #endif /* #if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER)) */
            }
        }
    } while (0);

    if (result != SRV_EMAIL_RESULT_SUCC && result != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        return;
    }

    msgContentUpdated();
}


void VappEmailMsgViewPage::addHtmlFrame()
{
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    if (m_htmlItem != NULL)
    {
        return;
    }

    VFX_OBJ_CREATE(m_htmlItem, VappEmailMsgViewHtmlItem, this);
    m_msgForm->addItem(m_htmlItem, MSG_VIEW_FORM_BASE_ITEM_HTML);
    m_htmlItem->getHtmlBtn()->m_signalClicked.connect(this, &VappEmailMsgViewPage::onHtmlBtnClick);

    /* update form's bounds */
    m_msgForm->setSize(m_msgForm->getBounds().getWidth(), m_msgForm->getContentSize().height);
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */
}


void VappEmailMsgViewPage::removeHtmlFrame()
{
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    if (m_htmlItem == NULL)
    {
        return;
    }

    m_msgForm->removeItem(MSG_VIEW_FORM_BASE_ITEM_HTML);
    m_htmlItem = NULL;

    /* update form's bounds */
    m_msgForm->setSize(m_msgForm->getBounds().getWidth(), m_msgForm->getContentSize().height);
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */
}


void VappEmailMsgViewPage::updateAttachInfo()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_ATTACH_INFO);

    S32 i = 0;
    srv_email_result_enum result;
    U32 pathLen = SRV_FMGR_PATH_MAX_LEN + 1;

    do
    {
        S32 getAttachNum = 1;
        for (; i < m_msgBasicInfo->attach_num; i++)
        {
            result = srv_email_msg_get_attachment_info(m_msgHandle, i, &getAttachNum, &gAttachInfoArray[i]);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            result = srv_email_msg_get_attachment_path(
                        m_msgHandle,
                        gAttachInfoArray[i].attach_id,
                        gAttachInfoArray[i].path,
                        pathLen);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
        }
        /* switch msg from more attachment to less attachment should clear the last position */
        if (m_msgBasicInfo->attach_num != MMI_EMAIL_MAX_ATTACH_NUMBER)
        {
            memset(&gAttachInfoArray[m_msgBasicInfo->attach_num], 0, sizeof(srv_email_attach_struct));
        }
    } while(0);
}


void VappEmailMsgViewPage::updateTitleBar()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_TITLEBAR);

    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    if (mainScr)
    {
        if (mainScr->getFirstPageType() == EMAIL_MAIN_FIRST_PAGE_MSG_VIEW)
        {
            /* 
             * Entry mail viewer from notification, no need to show title bar, 
             * because mail list is not ready, we can't switch to next mail.
             */
            return;
        }
    }
    
    if (m_titleBar == NULL)
    {
        VFX_OBJ_CREATE(m_titleBar, VappEmailMsgViewTitleBar, this);
        setTopBar(m_titleBar);
    }

    updateTitleBarText();
    VcpImageButton *btn = m_titleBar->getLeftBtn();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onTitleLBtnClick);
    }
    btn = m_titleBar->getRightBtn();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onTitleRBtnClick);
    }
}


void VappEmailMsgViewPage::updateTitleBarText()
{
    VfxWString acctName;
    S32 acctNameLength = SRV_EMAIL_MAX_ACCT_NAME_LEN + 1;
    WCHAR *textCont = (WCHAR*)get_ctrl_buffer(acctNameLength * 2);
    srv_email_acct_get_name(m_acctID, textCont, acctNameLength);
    acctName.loadFromMem(textCont);
    free_ctrl_buffer(textCont);

    VfxWString text;
    VfxU32 total;
    VfxU32 index;
    getIndex(index, total);
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_TITLEBAR_TEXT, index, total);

    if (m_isPageDisabled == VFX_TRUE)
    {
        text.setEmpty();
    }
    else
    {
        text.format("%d/%d", index + 1, total);
    }

    if (m_titleBar != NULL)
    {
        m_titleBar->updateTitleText(text, acctName);
        if (total == 1)
        {
            m_titleBar->updateButtons(VFX_FALSE);
        }
        else
        {
            m_titleBar->updateButtons(VFX_TRUE);
        }
    }
}


void VappEmailMsgViewPage::updateToolbar()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_TOOLBAR);

    srv_email_fldr_type_enum fldrType = srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID);
    if (m_toolbar == NULL)
    {
        VfxWString tbText;
        VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
        switch (fldrType)
        {
        case SRV_EMAIL_FLDR_TYPE_INBOX:
        case SRV_EMAIL_FLDR_TYPE_REMOTE:
            {
                tbText.loadFromRes(STR_GLOBAL_REPLY);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_REPLY, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_REPLY));
                tbText.loadFromRes(STR_EMAIL_FTO_REPLY_ALL_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_REPLY_ALL, tbText, VfxResId(IMG_EMAIL_FTO_TB_REPLY_ALL));
                tbText.loadFromRes(STR_GLOBAL_FORWARD);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_FORWARD, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD));
                tbText.loadFromRes(STR_EMAIL_FTO_USE_DETAILS_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_USE_DETAILS, tbText, VfxResId(IMG_EMAIL_FTO_TB_USE_DETAIL));
                tbText.loadFromRes(STR_GLOBAL_DELETE);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
                tbText.loadFromRes(STR_EMAIL_FTO_MARK_UNREAD_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, tbText, VfxResId(IMG_EMAIL_FTO_TB_MAKE_UNREAD));
            }
            break;
        case SRV_EMAIL_FLDR_TYPE_OUTBOX:
            {
                tbText.loadFromRes(STR_EMAIL_FTO_COMMON_MOVE_TO_DRAFT_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_MOVE_TO_DRAFTS, tbText, VfxResId(IMG_EMAIL_FTO_TB_MOVE_DRAFT));
                tbText.loadFromRes(STR_GLOBAL_DELETE);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
                tbText.loadFromRes(STR_EMAIL_FTO_USE_DETAILS_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_USE_DETAILS, tbText, VfxResId(IMG_EMAIL_FTO_TB_USE_DETAIL));
            }
            break;
        case SRV_EMAIL_FLDR_TYPE_SENT:
            {
                tbText.loadFromRes(STR_GLOBAL_FORWARD);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_FORWARD, tbText, VfxResId(VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD));
                tbText.loadFromRes(STR_GLOBAL_DELETE);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
                tbText.loadFromRes(STR_EMAIL_FTO_USE_DETAILS_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_USE_DETAILS, tbText, VfxResId(IMG_EMAIL_FTO_TB_USE_DETAIL));
            }
            break;
        case SRV_EMAIL_FLDR_TYPE_DRAFT:
            {
                tbText.loadFromRes(STR_GLOBAL_SEND);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_SEND, tbText, VfxResId(IMG_EMAIL_FTO_LIST_SEND_MAIL));
                tbText.loadFromRes(STR_GLOBAL_DELETE);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_DELETE, tbText, VfxResId(IMG_EMAIL_FTO_DELETE));
                tbText.loadFromRes(STR_EMAIL_FTO_USE_DETAILS_ID);
                m_toolbar->addItem(MSG_VIEW_PAGE_TB_USE_DETAILS, tbText, VfxResId(IMG_EMAIL_FTO_TB_USE_DETAIL));
            }
            break;
        default:
            return;
        }
        setBottomBar(m_toolbar);
        m_toolbar->m_signalButtonTap.connect(this, &VappEmailMsgViewPage::onTBClick);
    }
    if (m_msgCont != NULL)
    {
        VfxBool disableUseDetails = VFX_TRUE;
        VcpRichTextFormat *richTextFormat = m_msgCont->getFormatObject();
        while (richTextFormat)
        {
            if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
                ((VcpRichText*)richTextFormat)->isKeywordFormat())
            {
                disableUseDetails = VFX_FALSE;
                break;
            }
            richTextFormat = richTextFormat->getNext();
        }
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_USE_DETAILS, disableUseDetails);
    }
    if (VappEmailMgr::getInstance()->getMsgState(m_msgID) == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
    {
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MOVE_TO_DRAFTS, VFX_TRUE);
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_DELETE, VFX_TRUE);
        /* close delete confirm popup */
        if (m_deleteConfirmPage != NULL)
        {
            VFX_OBJ_CLOSE(m_deleteConfirmPage);
            m_deleteConfirmPage = NULL;
        }
    }
    else
    {
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MOVE_TO_DRAFTS, VFX_FALSE);
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_DELETE, VFX_FALSE);
    }
    VappEmailStateEnum emailState;
    if (!VappEmailMgr::getInstance()->isNetworkReady(emailState))
    {
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY, VFX_TRUE);
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY_ALL, VFX_TRUE);
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_FORWARD, VFX_TRUE);
    }
    else
    {
        srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
        srv_email_addr_struct *sender = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));
        VfxBool hasSender = VFX_FALSE;

        memset(sender, 0, sizeof(srv_email_addr_struct));
        do
        {
            result = srv_email_msg_get_sender(m_msgHandle, sender);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
        } while(0);

        if (sender->disp_name != 0 || sender->email_addr[0] != 0)
        {
            hasSender = VFX_TRUE;
        }
        free_ctrl_buffer(sender);

        if (hasSender == VFX_TRUE)
        {
            m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY, VFX_FALSE);
            m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY_ALL, VFX_FALSE);
        }
        else
        {
            m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY, VFX_TRUE);
            if (m_msgBasicInfo->to_addr_num == 0 && m_msgBasicInfo->cc_addr_num == 0 && m_msgBasicInfo->bcc_addr_num == 0)
            {
                m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY_ALL, VFX_TRUE);
            }
            else
            {
                m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_REPLY_ALL, VFX_FALSE);
            }
        }
        m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_FORWARD, VFX_FALSE);
        if (m_msgBasicInfo->flag & EMAIL_MSG_FLAG_SEEN)
        {
            m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_FALSE);
        }
        else
        {
            m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_TRUE);
        }
    }
}


void VappEmailMsgViewPage::getIndex(VfxU32 &index, VfxU32 &total)
{
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    mainScr->getMsgIndex(m_msgID, index, total);
}


void VappEmailMsgViewPage::getMsgIndex(EMAIL_MSG_ID currMsgID, VfxU32 &index, VfxU32 &total)
{
    srv_email_result_enum result;
    S32 msgNumber = 0;
    EMAIL_FLDR_HANDLE fldrHandle;
    total = 1;
    index = 0;

    
    srv_email_fldr_create_info_struct fldrCreateInfo;
    fldrCreateInfo.acct_id = srv_email_msg_id_to_acct_id(currMsgID);
    fldrCreateInfo.fldr_id = srv_email_msg_id_to_fldr_id(currMsgID);
    fldrCreateInfo.list_field = 0;
    fldrCreateInfo.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE;

    result = srv_email_fldr_create(gEmailSrvHandle, &fldrCreateInfo, &fldrHandle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return;
    }    
    result = srv_email_fldr_get_msg_num(fldrHandle, SRV_EMAIL_FLDR_MSG, &msgNumber);
    if (result != SRV_EMAIL_RESULT_SUCC || msgNumber == 0)
    {
        return;
    }
    total = msgNumber;
    
    if (fldrHandle != EMAIL_FLDR_INVALID_HANDLE)
    {
        srv_email_fldr_destroy(fldrHandle);
    }
}


mmi_ret VappEmailMsgViewPage::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_ONPROC, evt->evt_id, m_bkmID, m_dialerID, m_phbID);
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_DIALER_CLOSE_REQ: // request to close cui
    //case EVT_ID_CUI_DIALER_CLOSED_IND: // cui is closed
        if (m_dialerID != 0)
        {
            vcui_dialer_close(m_dialerID);
            m_dialerID = 0;
        }
        break;
    case EVT_ID_CUI_PHB_LIST_RESULT:
    case EVT_ID_CUI_PHB_SAVE_RESULT:
    case EVT_ID_CUI_PHB_VIEW_RESULT:
        if (m_phbID != 0)
        {
            vcui_phb_contact_saver_close(m_phbID);
            m_phbID = 0;
        }
        break;
    case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
        if (m_bkmID != 0)
        {
            vcui_bkm_add_bkm_close(m_bkmID);
            m_bkmID = 0;
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


void VappEmailMsgViewPage::onMsgDelete(EMAIL_MSG_ID msgID)
{
    if (msgID != m_msgID)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_MSG_DELETE, m_msgID, m_deleteMsg);
    /* do not handle when user select delete */
    if (m_deleteMsg)
    {
        return;
    }

    closeLoading();
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();

    /* close delete confirm popup */
    if (m_deleteConfirmPage != NULL)
    {
        VFX_OBJ_CLOSE(m_deleteConfirmPage);
        m_deleteConfirmPage = NULL;
    }
    /* do not close page, just disable all items */
    disablePage();
    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX)
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->setPopupType(VCP_POPUP_TYPE_INFO);
        errorPopup->showErrorPopup(
            STR_EMAIL_FTO_MSG_SENT_INFO_ID,
            getMainScr(),
            EMAIL_PAGE_TYPE_USE_DETAILS,
            EMAIL_PAGE_TYPE_ATTACH_LIST,
            EMAIL_PAGE_TYPE_RECIPIENT_LIST);
    }
    else
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup(
            STR_EMAIL_FTO_MSG_DELETE_ON_SERVER_ID,
            getMainScr(),
            EMAIL_PAGE_TYPE_USE_DETAILS,
            EMAIL_PAGE_TYPE_ATTACH_LIST,
            EMAIL_PAGE_TYPE_RECIPIENT_LIST);
    }
}


void VappEmailMsgViewPage::onTitleLBtnClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_TITLEBAR_LBTN_CLICK);

    kal_bool isValid = KAL_FALSE;
    VfxU32 index = 0, total = 0;
    VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
    EMAIL_MSG_ID msgID = mainScrn->getPrevMsgID(m_msgID, index, total);
    if (VappEmailMgr::getInstance()->getMsgState(msgID) == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
    {
        if (total == 2)
        {
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
            errorPopup->showErrorPopup(STR_EMAIL_FTO_SENDING_CANNOT_OPEN_ID);
            resetSwitchBtnState();
            return;
        }
        else
        {
            msgID = mainScrn->getPrevMsgID(msgID ,index, total);
        }
    }

    /* skip broken message */
    while (srv_email_msg_check_valid(msgID, &isValid) == SRV_EMAIL_RESULT_SUCC &&
           isValid == KAL_FALSE)
    {
        if (total == 2)
        {
            return;
        }
        else
        {
            msgID = mainScrn->getPrevMsgID(msgID ,index, total);
        }
        if (msgID == m_msgID)
        {
            /* check all msgs */
            return;
        }
    }

    if (isValid == VFX_FALSE)
    {
        return;
    }

    m_popupShowed = VFX_FALSE;
    m_msgID = msgID;
    updateMsgInfo();
    setMsgAsRead();    
    updateMsgViewer();
    updateTitleBarText();
    updateToolbar();

    if (m_msgCont != NULL)
    {
        m_msgCont->scrollToStart();
    }
}


void VappEmailMsgViewPage::onTitleRBtnClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_TITLEBAR_RBTN_CLICK);

    kal_bool isValid = KAL_FALSE;
    VfxU32 index = 0, total = 0;
    VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
    EMAIL_MSG_ID msgID = mainScrn->getNextMsgID(m_msgID, index, total);
    if (VappEmailMgr::getInstance()->getMsgState(msgID) == VAPP_EMAIL_MSG_STATE_NETWORK_SENDING)
    {
        if (total == 2)
        {
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
            errorPopup->showErrorPopup(STR_EMAIL_FTO_SENDING_CANNOT_OPEN_ID);
            resetSwitchBtnState();            
            return;
        }
        else
        {
            msgID = mainScrn->getNextMsgID(msgID ,index, total);
        }
    }

    /* skip broken message */
    while (srv_email_msg_check_valid(msgID, &isValid) == SRV_EMAIL_RESULT_SUCC &&
           isValid == KAL_FALSE)
    {
        if (total == 2)
        {
            return;
        }
        else
        {
            msgID = mainScrn->getNextMsgID(msgID ,index, total);
        }
        if (msgID == m_msgID)
        {
            /* check all msgs */
            return;
        }
    }

    if (isValid == VFX_FALSE)
    {
        return;
    }

    m_popupShowed = VFX_FALSE;
    m_msgID = msgID;
    updateMsgInfo();
    setMsgAsRead();    
    updateMsgViewer();
    updateTitleBarText();
    updateToolbar();
    
    if (m_msgCont != NULL)
    {
        m_msgCont->scrollToStart();
    }
}


void VappEmailMsgViewPage::onSubjBtnClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_SUBJ_BTN_CLICK, m_isSubjFold);

    m_subjItem->foldItem(!m_isSubjFold);
    if (m_isSubjFold)
    {
        m_isSubjFold = VFX_FALSE;
    }
    else
    {
        m_isSubjFold = VFX_TRUE;
    }
    msgHeaderUpdated();
}

void VappEmailMsgViewPage::onKeywordOperationClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_KEYWORD_OPERATION_CLICK, id);

    switch (id)
    {
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_EDIT_BEFORE_CALL:
        {
            // cui will handle flight mode
            m_dialerID = vcui_dialer_create(getApp()->getGroupId());
            if (m_dialerID != GRP_ID_INVALID)
            {
                srv_phb_remove_invalid_number((U16*)gKeywordContent.getBuf());
                vcui_dialer_set_dial_string(m_dialerID, gKeywordContent);
                vcui_dialer_run(m_dialerID);
                vfxSetCuiCallerScr(m_dialerID, getMainScr());
            }
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_MESSAGE:
        {
            // can enter composer in flight mode, UE revise.
            VappUcEntryStruct *ucEntryInfo = (VappUcEntryStruct*)get_ctrl_buffer(sizeof(VappUcEntryStruct));
            memset(ucEntryInfo, 0, sizeof(VappUcEntryStruct));
            srv_uc_addr_struct ucAddrInfo;
            memset(&ucAddrInfo, 0, sizeof(srv_uc_addr_struct));
            ucAddrInfo.addr = (U8*)gKeywordContent.getBuf();
            srv_phb_remove_invalid_number((U16*)ucAddrInfo.addr);
            ucAddrInfo.next = NULL;
            ucAddrInfo.previous = NULL;
            ucAddrInfo.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
            ucEntryInfo->addr_num = 1;
            ucEntryInfo->addr = &ucAddrInfo;
            ucEntryInfo->msg_type = SRV_UC_MSG_TYPE_DEFAULT;
            ucEntryInfo->type = SRV_UC_STATE_WRITE_NEW_MSG;

            mmi_id ucID = vcui_unifiedcomposer_create(getApp()->getGroupId(), ucEntryInfo);
            if (ucID != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(ucID, getMainScr());
                vcui_unifiedcomposer_run(ucID);
            }
            free_ctrl_buffer(ucEntryInfo);
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT:
        {
            m_phbID = vcui_phb_contact_saver_create(getApp()->getGroupId());
            if (m_phbID == GRP_ID_INVALID)
            {
                return;
            }
            vcui_phb_contact_saver_set_type(m_phbID, VAPP_PHB_SAVE_CONTACT_NEW);
            if (gIsSavePhoneNumber == VFX_TRUE)
            {
                vcui_phb_contact_saver_set_number(
                    m_phbID,
                    (WCHAR*)gKeywordContent.getBuf(),
                    mmi_ucs2strlen((CHAR*)gKeywordContent.getBuf()));
                gIsSavePhoneNumber = VFX_FALSE;
            }
            else
            {
                if (gIsKeywordContentAddr == VFX_TRUE)
                {
                    vcui_phb_contact_saver_set_email(
                        m_phbID,
                        (WCHAR*)gKeywordContent.getBuf(),
                        mmi_ucs2strlen((CHAR*)gKeywordContent.getBuf()));
                }
                else
                {
                    vcui_phb_contact_saver_set_name(
                        m_phbID,
                        (WCHAR*)gKeywordContent.getBuf(),
                        mmi_ucs2strlen((CHAR*)gKeywordContent.getBuf()));
                    vcui_phb_contact_saver_set_email(
                        m_phbID,
                        (WCHAR*)gKeywordContentBackUp.getBuf(), 
                        mmi_ucs2strlen((CHAR*)gKeywordContentBackUp.getBuf()));
                }
            }
            vfxSetCuiCallerScr(m_phbID, getMainScr());
            vcui_phb_contact_saver_run(m_phbID);
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT:
        {
            m_phbID = vcui_phb_contact_saver_create(getApp()->getGroupId());
            if (m_phbID == GRP_ID_INVALID)
            {
                return;
            }
            vcui_phb_contact_saver_set_type(m_phbID, VAPP_PHB_SAVE_CONTACT_REPLACE);
            if (gIsSavePhoneNumber == VFX_TRUE)
            {
                vcui_phb_contact_saver_set_number(
                    m_phbID,
                    (WCHAR*)gKeywordContent.getBuf(),
                    mmi_ucs2strlen((CHAR*)gKeywordContent.getBuf()));
                gIsSavePhoneNumber = VFX_FALSE;
            }
            else
            {
                if (gIsKeywordContentAddr == VFX_TRUE)
                {
                    vcui_phb_contact_saver_set_email(
                        m_phbID,
                        (WCHAR*)gKeywordContent.getBuf(),
                        mmi_ucs2strlen((CHAR*)gKeywordContent.getBuf()));
                }
                else
                {
                    vcui_phb_contact_saver_set_email(
                        m_phbID,
                        (WCHAR*)gKeywordContentBackUp.getBuf(), 
                        mmi_ucs2strlen((CHAR*)gKeywordContentBackUp.getBuf()));
                }
            }
            vcui_phb_contact_saver_run(m_phbID);

            vfxSetCuiCallerScr(m_phbID, getMainScr());
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL:
        {
            VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
            if (gIsKeywordContentAddr == VFX_TRUE)
            {
                mainScr->setSendToAddr((WCHAR*)gKeywordContent.getBuf(), NULL);
            }
            else
            {
                mainScr->setSendToAddr((WCHAR*)gKeywordContentBackUp.getBuf(), (WCHAR*)gKeywordContent.getBuf());
            }
            mainScr->launchComposer(m_acctID, EMAIL_MSG_INVALID_ID, VappEmailComp::EMAIL_MODE_NEW);
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_GO_TO_URL:
        {
        #ifdef BROWSER_SUPPORT
            wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)gKeywordContent.getBuf());
        #endif /*BROWSER_SUPPORT*/
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_SAVE_TO_BOOKMARKS:
        {            
        #ifdef BROWSER_SUPPORT
            char *convertedData = (char*)get_ctrl_buffer(2048);
            mmi_chset_convert(
                MMI_CHSET_UCS2,
                (mmi_chset_enum)MMI_CHSET_UTF8,
                (char*)gKeywordContent.getBuf(),
                (char*)convertedData,
                2048);
            /* should create group first */
            m_bkmID = vcui_bkm_add_bkm_create(getApp()->getGroupId());
			if(m_bkmID != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(m_bkmID, getMainScr());
                vcui_bkm_add_bkm_run(m_bkmID, (const U8*)convertedData);
            }
            free_ctrl_buffer(convertedData);
        #endif /*BROWSER_SUPPORT*/
        }
        break;
    case MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL:
        break;
    default:
        return;
    }
}


void VappEmailMsgViewPage::onRetrieveDone(EMAIL_MSG_ID msgID, VappEmailNwkDoneEnum operation, VappEmailResStruct result)
{
    if (msgID != m_msgID)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_VIEW_RETRIEVE_DONE,
        m_msgID,
        operation,
        result.result,
        result.major,
        result.minor);

    closeLoading();

    if (operation == VAPP_EMAIL_NWK_DONE_CANCEL)
    {
        return;
    }

    if (getMainScr()->getTopPageId() != EMAIL_PAGE_TYPE_MSG_VIEW)
    {
        return;
    }
    
    if (result.result != VAPP_EMAIL_RES_SUCC)
    {
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_MAIL_ERROR &&
            result.minor == SRV_EMAIL_RESULT_INVALID_MSG)
        {
            /* msg delete on server */
            return;
        }
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_MAIL_ERROR &&
            result.minor == SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE)
        {
            S32 downloadSize = 0;
            srv_email_acct_info_struct *account_info =
                (srv_email_acct_info_struct*)get_ctrl_buffer(sizeof(srv_email_acct_info_struct));
            srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
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
                result = srv_email_acct_read(acctHandle, account_info);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                downloadSize = account_info->download_size;
            } while(0);
            free_ctrl_buffer(account_info);
            if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
            {
                srv_email_acct_destroy(acctHandle);
            }
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
                errorPopup->showErrorPopup(result);
                return;
            }
    
            VfxWString text1;
            VfxWString text2;
            text1.loadFromRes(STR_EMAIL_FTO_TOO_LARGE_TO_DOWN_ID);
            text2.format("%dKB", (downloadSize + 1023) / 1024);
            text1 += text2;
            VcpConfirmPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VcpConfirmPopup, this);
            errorPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            errorPopup->setAutoDestory(VFX_TRUE);
            errorPopup->setText(text1);
            errorPopup->show(VFX_TRUE);
            return;
        }
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_MAIL_ERROR &&
            result.minor == SRV_EMAIL_RESULT_MSG_NOT_EXIST)
        {
            errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_MSG_VIEW);
        }
        else
        {
            errorPopup->showErrorPopup(result);
        }
        return;
    }

    updateMsgInfo();
    updateMsgHeader();
    updateMsgViewer();
    updateToolbar();
}


void VappEmailMsgViewPage::onMsgNumChange(EMAIL_ACCT_ID acctID, EMAIL_FLDR_ID fldrID, VappEmailFldrMsgNumStruct numChange)
{
    if (acctID != m_acctID || fldrID != m_fldrID)
    {
        return;
    }

    /* user delete msg, handle when popup exit */
    if (m_deleteMsg)
    {
        return;
    }

    if (m_isPageDisabled == VFX_TRUE)
    {
        return;
    }

    updateTitleBar();
}


void VappEmailMsgViewPage::onMsgChange(EMAIL_MSG_ID msgID, srv_email_om_notify_msg_struct notify)
{
    if (msgID != m_msgID)
    {
        return;
    }

    if (notify.chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_FLAG)
    {
        updateMsgInfo();
        if (m_toolbar != NULL)
        {
            if (notify.flag & EMAIL_MSG_FLAG_SEEN)
            {
                m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_FALSE);
            }
            else
            {
                m_toolbar->setDisableItem(MSG_VIEW_PAGE_TB_MARK_AS_UNREAD, VFX_TRUE);
            }
            updateToolbar();
        }
    }
}


void VappEmailMsgViewPage::onAcctNwkProc(VappEmailNwkStateEnum state, VfxU32 msgID, VappEmailNwkProcEnum proc)
{
    if ((EMAIL_MSG_ID)msgID != m_msgID)
    {
        return;
    }

    if (m_loadingPopup != NULL)
    {
        switch (proc)
        {
        case VAPP_EMAIL_NWK_PROC_CONNECTING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_CONNECTING_NETWORK));
            break;
        case VAPP_EMAIL_NWK_PROC_AUTHORIZING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_AUTHORIZING_ID));
            break;
        case VAPP_EMAIL_NWK_PROC_UPDATING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_UPDATING_INFO_ID));
            break;
        case VAPP_EMAIL_NWK_PROC_RETRIEVING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_RETRIEVING_ID));
            break;
        default:
            return;
        }
    }
}


void VappEmailMsgViewPage::onMsgStateChange(EMAIL_MSG_ID msgID, VappEmailMsgStateEnum state)
{
    if (m_msgID != msgID)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_MSG_STATE_CHANGE, m_msgID, state);

    updateMsgInfo();
    updateToolbar();
}


void VappEmailMsgViewPage::onFldrStateChange(EMAIL_FLDR_ID fldrId, VappEmailFldrStateEnum state)
{
    if (m_fldrID != fldrId)
    {
        return;
    }

    /* we close message view page when sending this message */
    if (state == VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING ||
        state == VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING)
    {
        VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
        mainScrn->closePage(EMAIL_PAGE_TYPE_MSG_VIEW);
        mainScrn->closePage(EMAIL_PAGE_TYPE_USE_DETAILS);
        mainScrn->closePage(EMAIL_PAGE_TYPE_ATTACH_LIST);
        mainScrn->closePage(EMAIL_PAGE_TYPE_RECIPIENT_LIST);        
        return;
    }
}


void VappEmailMsgViewPage::onAcctNwkDone(EMAIL_ACCT_ID acctID, VappEmailNwkDoneEnum operation, VappEmailResStruct result)
{
    if (acctID != m_acctID)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_LIST_ACCT_NWK_DONE, acctID, operation, result.result);

    /* cancle sending outbox */
    if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_OUTBOX ||
        operation == VAPP_EMAIL_NWK_DONE_CANCEL)
    {
        updateMsgInfo();
        updateToolbar();
    }
}


srv_email_result_enum VappEmailMsgViewPage::updateFromItem()
{
    srv_email_result_enum result;
    srv_email_addr_struct *sender = NULL;
    VfxWString text;
    VfxBool showRecipientBtn = VFX_FALSE;

    do
    {
        sender = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));
        result = srv_email_msg_get_sender(m_msgHandle, sender);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (sender->disp_name_len != 0)
        {
            text.loadFromMem((VfxWChar*)sender->disp_name);
        }
        else
        {
            text.loadFromMem((VfxWChar*)sender->email_addr);
        }
    } while(0);

    if (sender != NULL)
    {
        free_ctrl_buffer(sender);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

    if (m_fromItem == NULL)
    {
        VFX_OBJ_CREATE(m_fromItem, VappEmailMsgViewFromItem, m_msgForm);
        m_msgForm->addItem(m_fromItem, MSG_VIEW_FORM_BASE_ITEM_FROM);
        m_msgForm->insertSeparator(MSG_VIEW_FORM_BASE_ITEM_FROM);
    }

    if (m_msgBasicInfo->to_addr_num != 0 || m_msgBasicInfo->cc_addr_num != 0)
    {
        showRecipientBtn = VFX_TRUE;
    }
    m_fromItem->updateFromItem(text, showRecipientBtn);

    VcpButton *btn = m_fromItem->getFromBtn();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onFromBtnClick);
    }
    VcpImageButton *imgBtn = m_fromItem->getRecipientBtn();
    if (imgBtn != NULL)
    {
        imgBtn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onRecipientBtnClick);
    }
    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum VappEmailMsgViewPage::updateSubjItem()
{
    srv_email_result_enum result;
    U32 localTime;
    VfxWString dateText;
    VfxWString subjText;
    U32 subjLen = 0;
    S32 subjCharset = 0;
    WCHAR *subj = NULL;

    do
    {
        applib_time_struct timeInfo = {0};
        VfxDateTime dateTime;

        localTime = applib_dt_sec_utc_to_local(m_msgBasicInfo->mail_date);
        applib_dt_utc_sec_2_mytime(localTime, &timeInfo, MMI_FALSE);
        dateTime.setDateTime(&timeInfo);
        dateText = dateTime.getDateTimeString(
                        VFX_DATE_TIME_DATE_YEAR |
                        VFX_DATE_TIME_DATE_MONTH |
                        VFX_DATE_TIME_DATE_DAY |
                        VFX_DATE_TIME_TIME_HOUR |
                        VFX_DATE_TIME_TIME_MINUTE);

        result = srv_email_msg_get_subject_len(m_msgHandle, &subjLen, &subjCharset);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (subjLen != 0)
        {
            subjLen++;
            VFX_ALLOC_MEM(subj, subjLen * ENCODING_LENGTH, this);
            
            result = srv_email_msg_get_subject(m_msgHandle, subj, &subjLen);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            subjText.loadFromMem(subj);
            VFX_FREE_MEM(subj);
        }
        else
        {
            subjText.setEmpty();
        }
    } while(0);

    if (subj != NULL)
    {
        free_ctrl_buffer(subj);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

    /* add item to form */
    if (m_subjItem == NULL)
    {
        VFX_OBJ_CREATE(m_subjItem, VappEmailMsgViewSubjItem, m_msgForm);
        m_msgForm->addItem(m_subjItem, MSG_VIEW_FORM_BASE_ITEM_SUBJ);        
        m_msgForm->insertSeparator(MSG_VIEW_FORM_BASE_ITEM_SUBJ);
    }

    m_subjItem->updateSubjItem(subjText, dateText);

    VcpImageButton *btn = m_subjItem->getBtn();
    if (btn != NULL)
    {
        btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onSubjBtnClick);
    }
    return SRV_EMAIL_RESULT_SUCC;
}


void VappEmailMsgViewPage::updateContItemCallback(void *userData, int result)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_UPDATE_CONT_CALLBACK, result);

    VappEmailMsgViewPage *viewPage = (VappEmailMsgViewPage*)userData;
    viewPage->resetSwitchBtnState();
    viewPage->closeLoading();
    //viewPage->updateMsgHeader();
    viewPage->msgContentUpdated();
    viewPage->updateToolbar();
    viewPage->showNotDownloadAllPopup();
}


void VappEmailMsgViewPage::addRecipientItem()
{
    srv_email_result_enum result;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_VIEW_ADD_RECIPIENT_ITEM,
        m_msgBasicInfo->to_addr_num,
        m_msgBasicInfo->cc_addr_num,
        m_msgBasicInfo->bcc_addr_num);

    if (m_msgBasicInfo->to_addr_num != 0)
    {
        VFX_OBJ_CREATE(m_recipientItemTo, VappEmailMsgViewRecipientItem, m_msgForm);
        result = m_recipientItemTo->initTextFrame(m_msgHandle, EMAIL_MSG_VIEW_RECIPIENT_TO);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            VFX_OBJ_CLOSE(m_recipientItemTo);
            m_recipientItemTo = NULL;
            m_isAddrFold = VFX_TRUE;
        }
        else
        {
            m_msgForm->insertItem(m_recipientItemTo, MSG_VIEW_FORM_BASE_ITEM_SUBJ, MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO);
            m_msgForm->insertSeparator(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_TO);
            m_isAddrFold = VFX_FALSE;
            VcpButton *btn = m_recipientItemTo->getRecipientListBtn();
            if (btn != NULL)
            {
                btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onRecipientListToBtnClick);
            }
        }
    }
    if (m_msgBasicInfo->cc_addr_num != 0)
    {
        VFX_OBJ_CREATE(m_recipientItemCc, VappEmailMsgViewRecipientItem, m_msgForm);
        result = m_recipientItemCc->initTextFrame(m_msgHandle, EMAIL_MSG_VIEW_RECIPIENT_CC);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            VFX_OBJ_CLOSE(m_recipientItemCc);
            VFX_OBJ_CLOSE(m_recipientItemTo);
            m_recipientItemTo = NULL;
            m_recipientItemCc = NULL;
            m_isAddrFold = VFX_TRUE;
        }
        else
        {
            m_msgForm->insertItem(m_recipientItemCc, MSG_VIEW_FORM_BASE_ITEM_SUBJ, MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC);
            m_msgForm->insertSeparator(MSG_VIEW_FORM_BASE_ITEM_RECIPIENT_CC);
            m_isAddrFold = VFX_FALSE;
            VcpButton *btn = m_recipientItemCc->getRecipientListBtn();
            if (btn != NULL)
            {
                btn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onRecipientListCcBtnClick);
            }
        }
    }
}


void VappEmailMsgViewPage::onDeleteConfirmBtnClick(VfxObject *obj, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_DELETE_CONFIRM, id);

    m_deleteConfirmPage = NULL;

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VfxU32 index;
        VfxU32 total;
        VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
        EMAIL_MSG_ID msgID = mainScrn->getNextMsgID(m_msgID, index, total);

        srv_email_result_enum result;
        do
        {
            m_deleteMsg = VFX_TRUE;
            if (srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_INBOX ||
                srv_email_fldr_id_to_fldr_type(m_acctID, m_fldrID) == SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                result = srv_email_msg_delete(m_msgHandle, MMI_FALSE, MMI_TRUE);
            }
            else
            {
                /* for this delete, msg delete signal will be sent before this api return */
                result = srv_email_msg_delete(m_msgHandle, MMI_TRUE, MMI_TRUE);
            }
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                m_deleteMsg = VFX_FALSE;
            }
        } while(0);

        if (result == SRV_EMAIL_RESULT_SUCC)
        {
            VappEmailMainScrn *mainScrn = (VappEmailMainScrn*)getMainScr();
            mainScrn->closePage(EMAIL_PAGE_TYPE_MSG_VIEW);
        }
        else
        {
            VfxWString errorText;
            errorText.loadFromRes(STR_EMAIL_FTO_FAILED_TO_DELETE_ID);
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
            errorPopup->setPostFix(errorText);
            errorPopup->showErrorPopup(result);
        }
    }
}


void VappEmailMsgViewPage::onReadMoreConfirmBtnClick(VfxObject *, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_READ_MORE_CONFIRM, id);
    
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VappEmailMgr::getInstance()->cancelCurrNwkOperation();

        retrieveContent();
    }
}


void VappEmailMsgViewPage::mmi_email_read_extract_html(void *userData)
{
#if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER))

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_EXTRACT_HTML);
    
    U32 errorCode = 0;
    U16 parseBuffLen = VAPP_EMAIL_HTML_PAESE_BUFF_LEN / 2;

    memset(gHtmlParserContent, 0, sizeof(VappEmailContentParser));
    gHtmlParserContent->file_h = FS_Open((U16*)gHtmlFilePath, FS_READ_ONLY | FS_OPEN_SHARED);
    if (gHtmlParserContent->file_h > 0)
    {
        gParserStatus = EMAIL_CONT_PARSE_START;
        FS_GetFileSize(gHtmlParserContent->file_h, (UINT*)(&gHtmlParserContent->in_content_len));
        gHtmlParserContent->convert_buffer = (U8*)get_ctrl_buffer(parseBuffLen);
        if (gHtmlParserContent->in_content_len < (S32)(parseBuffLen - sizeof(WCHAR)))
        {
            gHtmlParserContent->read_len = gHtmlParserContent->in_content_len;
            gHtmlParserContent->is_last_read = TRUE;
        }
        else
        {
            gHtmlParserContent->read_len = parseBuffLen - sizeof(WCHAR);
            gHtmlParserContent->buff_len = 0;
        }
        gHtmlParserContent->data_temp_ptr = (U8*)gContent;
        gHtmlParserContent->read_temp_ptr = gHtmlParserContent->convert_buffer;
        FS_Read(gHtmlParserContent->file_h, gHtmlParserContent->read_temp_ptr, gHtmlParserContent->read_len, &errorCode);
        gHtmlParserContent->read_temp_ptr[errorCode] = 0;
        gHtmlParserContent->read_temp_ptr[errorCode + 1] = 0;
        gHtmlParserContent->read_buff_len = gHtmlParserContent->buff_len + errorCode;
        gHtmlParserContent->in_content_len -= errorCode;
        if (errorCode > 0)
        {
            m_asyncParse = VFX_FALSE;
            VappEmailMsgViewPage::mmi_email_read_cont_parser_ind(userData);
        }
        else
        {
            if (gHtmlParserContent->convert_buffer != NULL)
            {
                free_ctrl_buffer(gHtmlParserContent->convert_buffer);
                gHtmlParserContent->convert_buffer = NULL;
            }
            FS_Close(gHtmlParserContent->file_h);
            if (gHtmlParserContent->html_data_buff_ptr)
            {
                free_ctrl_buffer(gHtmlParserContent->html_data_buff_ptr);
                gHtmlParserContent->html_data_buff_ptr = NULL;
            }
            gParserStatus = EMAIL_CONT_PARSE_NONE;
            /* failed popup and close loading */
            VappEmailMsgViewPage::updateContItemCallback(userData, 0);
        }
    }
    else
    {
        gParserStatus = EMAIL_CONT_PARSE_NONE;
        /* failed popup and close loading */
        VappEmailMsgViewPage::updateContItemCallback(userData, 0);
    }

#endif
}


void VappEmailMsgViewPage::mmi_email_read_cont_parser_ind(void *userData)
{
#if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER))

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_CONT_PARSER_IND);
    if(gHtmlParserContent == NULL || gNotConvertedStringData == NULL)
    {
        return;
    }
    VappEmailMsgViewPage::mmi_email_read_cont_parser();
    if (gParserStatus == EMAIL_CONT_PARSE_FINISH)
    {
        if (gHtmlParserContent->convert_buffer != NULL)
        {
            free_ctrl_buffer(gHtmlParserContent->convert_buffer);
            gHtmlParserContent->convert_buffer = NULL;
        }
        FS_Close(gHtmlParserContent->file_h);
        if (gHtmlParserContent->html_data_buff_ptr != NULL)
        {
            free_ctrl_buffer(gHtmlParserContent->html_data_buff_ptr);
            gHtmlParserContent->html_data_buff_ptr = NULL;
        }
        /* successed close loading show message viewer */
        VappEmailMsgViewPage::updateContItemCallback(userData, 1);
    }
    else
    {
        m_asyncParse = VFX_TRUE;
        StartTimerEx(
            EMAIL_MMI_CONT_PARSER_TIMER,
            0,
            VappEmailMsgViewPage::mmi_email_read_cont_parser_ind,
            userData);
    }

#endif
}


void VappEmailMsgViewPage::mmi_email_read_cont_parser()
{
#if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER))

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_CONT_PARSER);

    U8 *retPtr = NULL;
    U16 convertLen = 0;
    U32 errorCode = 0;
    U32 pos = 0, i = 0, j = 0;
    U16 parseBuffLen = VAPP_EMAIL_HTML_PAESE_BUFF_LEN / 2;
    S32 dotsLen = mmi_wcslen(gEmail2dots);
    BOOL chsetSupport = FALSE;

    if (gHtmlCharset <= MMI_CHSET_BASE || gHtmlCharset >= MMI_CHSET_TOTAL)
    {
        convertLen = gHtmlParserContent->read_buff_len + ENCODING_LENGTH;
        pos = gHtmlParserContent->read_buff_len;
        retPtr = gHtmlParserContent->convert_buffer;
    }
    else
    {
        chsetSupport = TRUE;
        retPtr = VappEmailMsgViewPage::mmi_email_parse_content_to_ucs2(
                    gHtmlParserContent,
                    gHtmlCharset,
                    &convertLen,
                    &pos);
    }
    if (convertLen == 0)
    {
        if (retPtr && chsetSupport)
        {
            free_ctrl_buffer(retPtr);
        }
        gParserStatus = EMAIL_CONT_PARSE_FINISH;
        return;
    }
    else
    {
        if (gContLen * sizeof(WCHAR) + convertLen - sizeof(WCHAR) <= VAPP_EMAIL_MAX_CONTENT_LEN * sizeof(WCHAR))
        {
            memcpy(gHtmlParserContent->data_temp_ptr, retPtr, convertLen - sizeof(WCHAR));
            gHtmlParserContent->data_temp_ptr += convertLen - sizeof(WCHAR);
            gContLen += convertLen / sizeof(WCHAR) - 1;
            gHtmlParserContent->data_temp_ptr[0] = 0;
            gHtmlParserContent->data_temp_ptr[1] = 0;
            if (retPtr && chsetSupport)
            {
                free_ctrl_buffer(retPtr);
            }
        }
        else
        {
            if (VAPP_EMAIL_MAX_CONTENT_LEN - gContLen - dotsLen > 0)
            {
                memcpy(
                    gHtmlParserContent->data_temp_ptr,
                    retPtr,
                    (VAPP_EMAIL_MAX_CONTENT_LEN - gContLen - dotsLen) * sizeof(WCHAR));
                gHtmlParserContent->data_temp_ptr += (VAPP_EMAIL_MAX_CONTENT_LEN - gContLen - dotsLen) * sizeof(WCHAR);
            }
            gContLen = VAPP_EMAIL_MAX_CONTENT_LEN;
            gHtmlParserContent->data_temp_ptr[0] = 0;
            gHtmlParserContent->data_temp_ptr[1] = 0;
            if (retPtr && chsetSupport)
            {
                free_ctrl_buffer(retPtr);
            }
            gParserStatus = EMAIL_CONT_PARSE_FINISH;
            return;
        }
        if (pos != gHtmlParserContent->read_buff_len)
        {
            if (gHtmlParserContent->is_last_read && gHtmlParserContent->read_len == 0)
            {
                gParserStatus = EMAIL_CONT_PARSE_FINISH;
                return;
            }
            for (i = pos, j = 0; i < gHtmlParserContent->read_buff_len; i++, j++)
            {
                gHtmlParserContent->convert_buffer[j] = gHtmlParserContent->convert_buffer[i];
            }
            gHtmlParserContent->convert_buffer[j] = 0;
            gHtmlParserContent->convert_buffer[j + 1] = 0;
            gHtmlParserContent->buff_len = gHtmlParserContent->read_buff_len - pos;
            gHtmlParserContent->read_temp_ptr = gHtmlParserContent->convert_buffer + gHtmlParserContent->buff_len;
        }
        else
        {
            if (gHtmlParserContent->is_last_read)
            {
                gParserStatus = EMAIL_CONT_PARSE_FINISH;
                return;
            }
            gHtmlParserContent->read_temp_ptr = gHtmlParserContent->convert_buffer;
            gHtmlParserContent->buff_len = 0;
        }
        if (gHtmlParserContent->in_content_len <= (S32)(parseBuffLen - gHtmlParserContent->buff_len - sizeof(WCHAR)))
        {
            if (!gHtmlParserContent->is_last_read)
            {
                gHtmlParserContent->read_len = gHtmlParserContent->in_content_len;
                gHtmlParserContent->is_last_read = TRUE;
            }
            else
            {
                gHtmlParserContent->read_len = 0;
            }
        }
        else
        {
            gHtmlParserContent->read_len = parseBuffLen - gHtmlParserContent->buff_len - sizeof(WCHAR);
        }
        pos = 0;
    }
    if (gHtmlParserContent->read_len)
    {
        FS_Read(gHtmlParserContent->file_h, gHtmlParserContent->read_temp_ptr, gHtmlParserContent->read_len, &errorCode);
        gHtmlParserContent->read_temp_ptr[errorCode] = 0;
        gHtmlParserContent->read_temp_ptr[errorCode + 1] = 0;
        gHtmlParserContent->read_buff_len = gHtmlParserContent->buff_len + errorCode;
        gHtmlParserContent->in_content_len -= errorCode;
        if (errorCode > 0)
        {
            gParserStatus = EMAIL_CONT_PARSE_PARSING;
        }
        else
        {
            gParserStatus = EMAIL_CONT_PARSE_FINISH;
        }
    }
    else
    {
        gHtmlParserContent->read_buff_len = gHtmlParserContent->buff_len;
        gParserStatus = EMAIL_CONT_PARSE_PARSING;
    }

#endif
}


U8 *VappEmailMsgViewPage::mmi_email_parse_content_to_ucs2(VappEmailContentParser *parser, S32 chset, U16 *outLen, U32 *pos)
{
#if (defined(__MMI_EMAIL_HTML__) && !defined(OPERA_V10_BROWSER))

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_VIEW_CONT_TO_UCS2);

    U8 *convertedData = NULL, *temp_html_buff_ptr = NULL, *html_convert_ptr = NULL;
    U8 *temp_html_convert_ptr = NULL;
    U32 temp_pos = 0, html_convert_len = 0, html_out_len = 0, html_in_len = 0;
    U32 i = 0, j = 0;
    BOOL ret = FALSE;

    *outLen = 0;
    if (parser->html_data_buff_ptr == NULL)
    {
        parser->html_data_buff_ptr = (U8*)get_ctrl_buffer(VAPP_EMAIL_HTML_PAESE_BUFF_LEN);
        parser->html_data_buff_len = 0;
        applib_html_extract_plaintext_init(&parser->plaintext);
        memset(gNotConvertedStringData, 0, 20);
    }
    temp_html_buff_ptr = parser->html_data_buff_ptr + parser->html_data_buff_len;
    if (parser->read_buff_len + parser->html_data_buff_len >= VAPP_EMAIL_HTML_PAESE_BUFF_LEN - ENCODING_LENGTH)
    {
        html_in_len = VAPP_EMAIL_HTML_PAESE_BUFF_LEN - ENCODING_LENGTH;
        *pos = parser->read_buff_len - parser->html_data_buff_len;
        memcpy(
            temp_html_buff_ptr,
            parser->convert_buffer,
            VAPP_EMAIL_HTML_PAESE_BUFF_LEN - parser->html_data_buff_len);
        temp_html_buff_ptr[VAPP_EMAIL_HTML_PAESE_BUFF_LEN - parser->html_data_buff_len] = '\0';
    }
    else
    {
        html_in_len = parser->read_buff_len + parser->html_data_buff_len;
        *pos = parser->read_buff_len;
        memcpy(
            temp_html_buff_ptr,
            parser->convert_buffer,
            parser->read_buff_len);
        temp_html_buff_ptr[parser->read_buff_len] = '\0';
    }
    html_convert_ptr = (U8*)get_ctrl_buffer(VAPP_EMAIL_HTML_PAESE_BUFF_LEN);
    if (gNotConvertedStringData[0] != '\0')
    {
        strcpy((char*)html_convert_ptr, gNotConvertedStringData);
        i = strlen(gNotConvertedStringData);
        temp_html_convert_ptr = html_convert_ptr + i;
        html_out_len = VAPP_EMAIL_HTML_PAESE_BUFF_LEN - i;
        memset(gNotConvertedStringData, 0, 20);
    }
    else
    {
        temp_html_convert_ptr = html_convert_ptr;
        html_out_len = VAPP_EMAIL_HTML_PAESE_BUFF_LEN;
    }
    ret = applib_html_extract_plaintext_parse(
            &parser->plaintext,
            (kal_uint8)parser->is_last_read,
            parser->html_data_buff_ptr,
            html_in_len,
            temp_html_convert_ptr,
            &html_out_len,
            &html_convert_len);
    if (!ret)
    {
        *outLen = 0;
        free_ctrl_buffer(html_convert_ptr);
        return convertedData;
    }
    temp_html_convert_ptr[html_out_len] = '\0';
    for (i = html_convert_len, j = 0; i < html_in_len; i++, j++)
    {
        parser->html_data_buff_ptr[j] = parser->html_data_buff_ptr[i];
    }
    parser->html_data_buff_ptr[j] = '\0';
    parser->html_data_buff_len = html_in_len - html_convert_len;
    convertedData = (U8*)get_ctrl_buffer(2048);
    *outLen = (U16)mmi_chset_convert_ex(
        MMI_CHSET_UTF8,
        MMI_CHSET_UCS2,
        (char*)html_convert_ptr,
        (char*)convertedData,
        2048,
        &temp_pos);
    temp_pos = temp_pos - (U32)html_convert_ptr;
    i = strlen((char*)html_convert_ptr);
    /* the other case should not happen */
    if ((temp_pos <= i) && (i - temp_pos < 20))
    {
        strcpy(gNotConvertedStringData, (char*)(html_convert_ptr + temp_pos));
    }
    free_ctrl_buffer(html_convert_ptr);
    return convertedData;

#endif
    return NULL;
}


void VappEmailMsgViewPage::msgHeaderUpdated()
{
    m_msgForm->setSize(m_msgForm->getBounds().getWidth(), m_msgForm->getContentSize().height);
   // m_msgCont->forceUpdate();
    if (m_msgCont != NULL)
    {
        m_msgCont->UpdateViewForCustomFrame();
    }
}


void VappEmailMsgViewPage::msgContentUpdated()
{
    VfxBool showHtmlBtn = VFX_FALSE;
    VfxBool showReadMoreBtn = VFX_FALSE;
    VfxBool showAttachBtn = VFX_FALSE;

    getMsgBasicInfo(&showHtmlBtn, &showReadMoreBtn, &showAttachBtn, NULL, NULL);

    if (showHtmlBtn == VFX_TRUE)
    {
        addHtmlFrame();
    }
    else
    {
        removeHtmlFrame();
    }

    if (m_msgCont == NULL)
    {
        VFX_OBJ_CREATE(m_msgCont, VcpTextView, this);
        m_msgCont->setMargins(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 0, EMAIL_MSG_VIEW_HEADER_RIGHT_GAP, 0);
        m_msgCont->setUnderline(VFX_TRUE);
        m_msgCont->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_EMAIL_FTO_MAIL_CONTENT_TEXT));
        m_msgCont->setColor(VCP_TEXT_UNDERLINE_COLOR, VFX_COLOR_RES(CLR_EMAIL_FTO_MAIL_CONTENT_UNDERLINE));
        m_msgCont->setMinLineHeight(EMAIL_MSG_VIEW_CONT_LINE_HEIGHT);
        m_msgCont->setNormalBgImage(IMG_EMAIL_FTO_CONTENT_BG_ID);
        m_msgCont->setHiliteBgImage(IMG_EMAIL_FTO_CONTENT_BG_ID);
        m_msgCont->setPos(0, 0);
        m_msgCont->setBounds(VfxRect(0, 0, gScrnWidth, getSize().height));
        m_msgCont->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        m_msgCont->setKeyword(
            VCP_TEXT_KEYWORD_EMAIL |
        #ifdef BROWSER_SUPPORT
            VCP_TEXT_KEYWORD_URL |
        #endif /* BROWSER_SUPPORT */
            VCP_TEXT_KEYWORD_PHONENUMBER);
        m_msgCont->m_signalKeywordClick.connect(this, &VappEmailMsgViewPage::onContentKeywordClick);
    }

    VfxS32 start = mmi_ucs2strlen((CHAR*)gContent) + 1;    // skip the space
    if (showReadMoreBtn == VFX_TRUE)
    {
        WCHAR readMoreLink[20 + 1];
        kal_wsprintf(readMoreLink, " %w ", GetString(STR_EMAIL_FTO_LINK_MORE));
        mmi_ucs2cat((CHAR*)gContent, (CHAR*)readMoreLink);
    }
    if (mmi_ucs2strlen((CHAR*)gContent) == 0 && showAttachBtn == VFX_TRUE)
    {
        kal_wsprintf(gContent, " ");
    }
    m_msgCont->setText(VFX_WSTR_MEM(gContent));

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__    
    /* support emotion */
    VcpIconTable *iconTable = VappUcEmoticon::getEmotionTablePointer();
    VfxU32 sizeTable = VappUcEmoticon::getEmotionTableSize();
    m_msgCont->setIconMode(VFX_TRUE, iconTable, sizeTable);
#endif /* #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__ */

    m_msgCont->addTextFormat(m_msgHeaderFrame);
    if (showReadMoreBtn == VFX_TRUE)
    {
        VfxS32 end = mmi_ucs2strlen((CHAR*)gContent);    
        m_msgCont->setHyperLink(start, end - 1, VFX_WSTR_EMPTY);
        m_msgCont->m_signalHyperLinkClicked.connect(this, &VappEmailMsgViewPage::onReadMoreBtnClick);
    }
    /* remove attachment list button */
    if (m_attachBtn != NULL)
    {
        m_msgCont->removeTextFormat(m_msgAttachBtnFrame);
        VFX_OBJ_CLOSE(m_attachBtn);
        m_attachBtn = NULL;
    }

    if (showAttachBtn == VFX_TRUE)
    {
        if (m_attachBtn == NULL)
        {
            m_attachBtn = vcpCreateArrowButton(this);
            m_attachBtn->setSize(
                gScrnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
                EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT);
            m_attachBtn->m_signalClicked.connect(this, &VappEmailMsgViewPage::onAttachBtnClick);
            m_msgAttachBtnFrame.setFrame(m_attachBtn);
            m_msgAttachBtnFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);
        }

        /* update content of attachment list button */
        VfxWString string;
        VfxU16 i = 0;
        S32 totalSize = 0;
        for (; i < MMI_EMAIL_MAX_ATTACH_NUMBER; i++)
        {
            if (gAttachInfoArray[i].attach_id != EMAIL_ATTCH_INVALID_ID)
            {
                totalSize += gAttachInfoArray[i].size;
            }
            else
            {
                break;
            }
        }
        totalSize = (totalSize + 1023) / 1024;
        WCHAR btnText[30];
        if (i == 1)
        {
            kal_wsprintf(
                btnText, 
                "1 %w %w%dKB%w", 
                GetString(STR_EMAIL_FTO_ATTACHMENT_ID), 
                GetString(STR_EMAIL_FTO_LEFT_PARENTHESES),                
                totalSize,
                GetString(STR_EMAIL_FTO_RIGHT_PARENTHESES));
        }
        else
        {
            kal_wsprintf(
                btnText, 
                "%d %w %w%dKB%w", 
                i, 
                GetString(STR_EMAIL_FTO_ATTACHMENTS_ID), 
                GetString(STR_EMAIL_FTO_LEFT_PARENTHESES),
                totalSize,
                GetString(STR_EMAIL_FTO_RIGHT_PARENTHESES));
        }
        string.loadFromMem(btnText);
        m_attachBtn->setText(string);

        VfxS32 range = mmi_ucs2strlen((CHAR*)gContent);
        m_msgAttachBtnFrame.setRange(range, range);
        m_msgCont->addTextFormat(m_msgAttachBtnFrame);
    }

    m_msgCont->forceUpdate();
    if (m_attachBtn != NULL)
    {
        m_attachBtn->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
    }
}


VappEmailMsgViewAttachListMenuProvider::VappEmailMsgViewAttachListMenuProvider(
    EMAIL_ACCT_ID acctID,
    EMAIL_FLDR_ID fldrID,
    EMAIL_MSG_ID msgID)
    :m_acctID(acctID),
     m_fldrID(fldrID),
     m_msgID(msgID)
{
}


VappEmailMsgViewAttachListMenuProvider::VappEmailMsgViewAttachListMenuProvider()
{
}


VfxBool VappEmailMsgViewAttachListMenuProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &color)
{
    switch (fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            WCHAR attachNameNoExt[EMAIL_ATTCH_FILE_NAME_LEN + 1];
            memcpy(attachNameNoExt, gAttachInfoArray[index].name, sizeof(WCHAR) * (EMAIL_ATTCH_FILE_NAME_LEN + 1));
            WCHAR *extPtr = mmi_wcsrchr(attachNameNoExt, L'.');
            if (extPtr != NULL)
            {
                *extPtr = 0;
            }
            textString.loadFromMem(attachNameNoExt);
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        {
            textString.format("%dKB", (gAttachInfoArray[index].size + 1023) / 1024);
        }
        break;
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


VfxBool VappEmailMsgViewAttachListMenuProvider::getItemImage(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxImageSrc &imageSrc)
{
    switch (fieldType)
    {
    case VCP_LIST_MENU_FIELD_ICON:
        {
			#ifndef __MMI_EMAIL_VIDEO_PREVIEW__
		    applib_mime_type_struct *mime = applib_mime_get_file_type(gAttachInfoArray[index].name);
		    if (mime && mime->mime_type == MIME_TYPE_VIDEO)
		    {
		         imageSrc.setResId(srv_fmgr_types_get_icon(FMGR_TYPE_UNKNOWN, NULL, SRV_FMGR_TYPES_ICON_LARGE));
		         break;
		    }
			#endif
            mmi_fmgr_filetype_enum type;
            type = srv_fmgr_types_find_type_by_filename_str(gAttachInfoArray[index].name);
            imageSrc.setResId(srv_fmgr_types_get_icon(type, NULL, SRV_FMGR_TYPES_ICON_LARGE));
        }
        break;
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        {
            /* network not available, all should return VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED */
            if (gAttachInfoArray[index].downloaded)
            {
                imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_SAVE);
            }
            else
            {
                imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_DOWNLOAD);
            }
        }
        break;
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VappEmailMsgViewAttachListMenuProvider::closeItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc imageSrc)
{
}


VfxU32 VappEmailMsgViewAttachListMenuProvider::getCount(void) const
{
    return m_attachNum;
}


VcpListMenuItemStateEnum VappEmailMsgViewAttachListMenuProvider::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappEmailMsgViewAttachListMenuProvider::swapItem(VfxU32 first, VfxU32 second)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappEmailMsgViewAttachListMenuProvider::getItemCustomContentFrame(
                                    VfxU32 index, VfxFrame *frame)
{
    return NULL;
}


void VappEmailMsgViewAttachListMenuProvider::closeItemCustomContentFrame(
        VfxU32 index, VcpListMenuCellClientBaseFrame *baseFrame)
{
    
}


void VappEmailMsgViewAttachListMenuProvider::onInit()
{
    srv_email_result_enum result;
    EMAIL_MSG_HANDLE msgHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_msg_get_basic_info_struct *basicInfo =
        (srv_email_msg_get_basic_info_struct*)get_ctrl_buffer(sizeof(srv_email_msg_get_basic_info_struct));

    do
    {
        result = srv_email_msg_create(gEmailSrvHandle, &msgHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_open(msgHandle, m_acctID, m_fldrID, m_msgID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_get_basic_info(msgHandle, basicInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        S32 getAttachNum = 1;
        m_attachNum = basicInfo->attach_num;
        for (VfxU16 i = 0; i < m_attachNum; i++)
        {
            result = srv_email_msg_get_attachment_info(
                        msgHandle,
                        i,
                        &getAttachNum,
                        &gAttachInfoArray[i]);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
        }
    } while(0);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        /* should popup error */
    }

    free_ctrl_buffer(basicInfo);
    if (msgHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }
}


VfxU32 VappEmailMsgViewAttachPage::m_attachIndex = 0;


VappEmailMsgViewAttachPage::VappEmailMsgViewAttachPage(
    EMAIL_ACCT_ID acctID,
    EMAIL_FLDR_ID fldrID,
    EMAIL_MSG_ID msgID)
    :m_acctID(acctID),
     m_fldrID(fldrID),
     m_msgID(msgID),
     m_listProvider(NULL),
     m_listMenu(NULL),
     m_loadingPopup(NULL),
     m_toolbar(NULL),
     m_copyFileDstPathPtr(NULL),
     m_imageViewer(0),
     m_audioPlayer(0),
     m_videoPlayer(0),
     m_vcardViewer(0),
     m_attachViewSave(VFX_FALSE)
{
}


VappEmailMsgViewAttachPage::VappEmailMsgViewAttachPage()
{
}


void VappEmailMsgViewAttachPage::onInit()
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_PAGE_INIT);

    VfxPage::onInit();

    /* add title bar */
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    VfxWString text;
    text.loadFromRes(STR_GLOBAL_ATTACHMENT);
    titleBar->setTitle(text);
    setTopBar(titleBar);

    VFX_OBJ_CREATE_EX(
        m_listProvider,
        VappEmailMsgViewAttachListMenuProvider,
        this,
        (m_acctID, m_fldrID, m_msgID));
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setContentProvider(m_listProvider);
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    /* true means keep current position */
    //attachListMenu->resetAllItems(VFX_TRUE);
    m_listMenu->updateAllItems();
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgViewAttachPage::onItemClick);
    m_listMenu->m_signalCmdButtonClicked.connect(this, &VappEmailMsgViewAttachPage::onCMDBtnClick);
    m_listProvider->setMenu(m_listMenu);

    VappEmailMgr::getInstance()->m_signalMsgNwkDone.connect(this, &VappEmailMsgViewAttachPage::onRetrieveDone);

    updateToolbar();
}


void VappEmailMsgViewAttachPage::onDeinit()
{
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_ATTACH_PAGE_DEINIT,
        m_loadingPopup,
        m_copyFileDstPathPtr,
        0,
        gFolderSelectorID,
        m_imageViewer,
        m_audioPlayer,
        m_videoPlayer);

    if (m_copyFileDstPathPtr != NULL)
    {
        free_ctrl_buffer(m_copyFileDstPathPtr);
        m_copyFileDstPathPtr = NULL;
    }

    if (gFolderSelectorID != 0)
    {
        vcui_folder_selector_close(gFolderSelectorID);
        gFolderSelectorID = 0;
    }

    if (m_imageViewer != 0)
    {
        vcui_gallery_close(m_imageViewer);
        m_imageViewer = 0;
    }

    if (m_audioPlayer != 0)
    {
        vcui_music_player_close(m_audioPlayer);
        m_audioPlayer = 0;
    }

    if (m_videoPlayer != 0)
    {
        vcui_gallery_close(m_videoPlayer);
        m_videoPlayer = 0;
    }

    VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);

    VfxPage::onDeinit();
}


mmi_ret VappEmailMsgViewAttachPage::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_ATTACH_PAGE_ONPROC,
        evt->evt_id,
        gFolderSelectorID,
        m_imageViewer,
        m_audioPlayer,
        m_videoPlayer);

    switch (evt->evt_id)
    {
    case EVT_ID_VCUI_GALLERY_CLOSE_GID:
        {
            if (m_imageViewer != 0)
            {
                vcui_gallery_close(m_imageViewer);
                m_imageViewer = 0;
            }
            if (m_videoPlayer != 0)
            {
                vcui_gallery_close(m_videoPlayer);
                m_videoPlayer = 0;
            }
        }
        break;
    case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:
        {
            if (m_audioPlayer != 0)
            {
                vcui_music_player_close(m_audioPlayer);
                m_audioPlayer = 0;
            }
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}



void VappEmailMsgViewAttachPage::onRotate(const VfxScreenRotateParam &param)
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


void VappEmailMsgViewAttachPage::onItemClick(VcpListMenu *listMenu, VfxU32 index)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_PAGE_ITEM_CLICK, index);

    m_attachIndex = index;
    if (!gAttachInfoArray[index].downloaded)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_EMAIL_PLEASE_DOWNLOAD));
        return;
    }

    applib_mime_type_struct *mime = applib_mime_get_file_type(gAttachInfoArray[index].name);
    VfxBool supportType = VFX_FALSE;

    do
    {
        if (mime == NULL)
        {
            break;
        }
        if (mime->mime_type == MIME_TYPE_IMAGE ||
            mime->mime_type == MIME_TYPE_AUDIO)
        {
            supportType = VFX_TRUE;
            break;
        }
		
		#ifdef __MMI_EMAIL_VIDEO_PREVIEW__
		if (mime->mime_type == MIME_TYPE_VIDEO)
		{
			supportType = VFX_TRUE;
            break;
		}
		#endif
		
        if (mime->mime_type == MIME_TYPE_APPLICATION)
        {
            if (mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR ||
                mime->mime_subtype == MIME_SUBTYPE_HBSVCS ||
                mime->mime_subtype == MIME_SUBTYPE_CALENDAR)
            {
                supportType = VFX_TRUE;
                break;
            }
        #ifdef __MMI_VCARD__
            if (mime->mime_subtype == MIME_SUBTYPE_XVCARD ||
                mime->mime_subtype == MIME_SUBTYPE_VCARD)
            {
                supportType = VFX_TRUE;
                break;
            }
        #endif /* __MMI_VCARD__ */
        }
    } while(0);

    if (supportType == VFX_FALSE)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_EMAIL_FTO_FILE_TYEP_NOT_SUPPORTED_ID));
        return;
    }

    m_attachViewSave = VFX_TRUE;

#ifdef __DRM_SUPPORT__
    filetypes_group_type_enum fmgrType = srv_fmgr_types_find_group_by_filename_str(gAttachInfoArray[index].name);
    U8 permission = DRM_PERMISSION_NONE;
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE fileHandle;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_PAGE_IS_DRM_OBJ, gAttachInfoArray[index].drm_object);

    if (gAttachInfoArray[index].drm_object)
    {
        if (fmgrType == FMGR_TYPE_UNKNOWN)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_EMAIL_FTO_FILE_TYEP_NOT_SUPPORTED_ID));
            return;
        }
        if (fmgrType == FMGR_GROUP_IMAGE)
        {
            permission = DRM_PERMISSION_DISPLAY;
        }
        else if (fmgrType == FMGR_GROUP_AUDIO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        else if (fmgrType == FMGR_GROUP_VIDEO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        if ((fileHandle = DRM_open_file(
                            (UI_string_type)gAttachInfoArray[index].path, 
                            FS_READ_ONLY | FS_OPEN_SHARED, 
                            permission)) >= FS_NO_ERROR)
        {
            if ((method = DRM_get_object_method(fileHandle, NULL)) != DRM_METHOD_NONE)
            {
                if (DRM_validate_permission(fileHandle, NULL, permission) == MMI_FALSE)
                {
                    if (method & DRM_METHOD_SEPARATE_DELIVERY)
                    {
                        U32 size = sizeof(gRightsIssuer);
                        /* request rights from server */
                        memset(gRightsIssuer, 0, sizeof(gRightsIssuer));
                        if (FS_NO_ERROR <= DRM_get_rights_issuer(fileHandle, gRightsIssuer, &size))
                        {
                        #ifdef BROWSER_SUPPORT
                            WCHAR temp[DRM_MAX_URL_LENGTH] = {0};

                            mmi_asc_n_to_wcs(temp, (CHAR*)gRightsIssuer, strlen((const char *)gRightsIssuer));
                            wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)temp);
                        #else
                            VappEmailErrorPopup *errorPopup;
                            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
                            errorPopup->showErrorPopup(STR_GLOBAL_DRM_PROHIBITED);
                        #endif
                            DRM_close_file(fileHandle);
                            return;
                        }
                    }
                    VappEmailErrorPopup *errorPopup;
                    VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
                    errorPopup->showErrorPopup(STR_GLOBAL_DRM_PROHIBITED);
                    DRM_close_file(fileHandle);
                    return;
                }
            }
            //DRM_resume_consume();
            DRM_close_file(fileHandle);
        }
        else
        {
            /* open file fail */
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
            errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(fileHandle));
            return;
        }    
    }
#endif /* __DRM_SUPPORT__ */
    WCHAR *file_ext = mmi_wcsrchr(gAttachInfoArray[index].name, L'.');
    S32 attr = 0;
    WCHAR *copyFileDstPath = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    WCHAR *copyFileDstFolder = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    memset(copyFileDstPath, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    kal_wsprintf(copyFileDstPath, "%scopy_file\\attach%w", srv_email_get_root_path(), file_ext);
    kal_wsprintf(copyFileDstFolder, "%scopy_file\\", srv_email_get_root_path());
    if (!vapp_email_util_dir_exist(copyFileDstFolder))
    {
        S32 fsResult = FS_CreateDir(copyFileDstFolder);
        if (fsResult != FS_NO_ERROR)
        {
            free_ctrl_buffer(copyFileDstPath);
            free_ctrl_buffer(copyFileDstFolder);
            VappEmailErrorPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
            errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(fsResult));
            return;
        }
    }
    free_ctrl_buffer(copyFileDstFolder);
    attr = FS_GetAttributes((const WCHAR*)copyFileDstPath);
    if (attr & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes((const WCHAR*)copyFileDstPath, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
    }
    FS_Delete((U16*)copyFileDstPath);
    S32 copyFileJobID =
        srv_fmgr_async_copy(
            gAttachInfoArray[index].path,
            copyFileDstPath,
            0,
            &VappEmailMsgViewAttachPage::copyAttachCallback,
            getObjHandle());
    if (m_copyFileDstPathPtr != NULL)
    {
        free_ctrl_buffer(m_copyFileDstPathPtr);
        m_copyFileDstPathPtr = NULL;
    }
    m_copyFileDstPathPtr = copyFileDstPath;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_PAGE_COPY_FILE_JOB_ID, copyFileJobID);

    if (copyFileJobID > 0)
    {
        VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, (VappEmailMsgListPage*)getParent());
        m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_LOADING));
        m_loadingPopup->setAutoDestory(VFX_FALSE);
        m_loadingPopup->show(VFX_TRUE);
    }
    else
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(copyFileJobID));
        return;
    }
}


void VappEmailMsgViewAttachPage::onCMDBtnClick(VcpListMenu *, VfxU32 index)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_PAGE_CMD_CLICK, index, gAttachInfoArray[index].downloaded);

    m_attachIndex = index;
    if (gAttachInfoArray[index].downloaded)
    {
        saveAttachment();
        return;
    }
    else
    {
        if (VappEmailMgr::getInstance()->getEmailAppState() == VAPP_EMAIL_STATE_FLIGHT_MODE)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
            return;
        }

        VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(m_acctID);

        if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
            acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
            acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
            acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
        {
            VcpConfirmPopup *confirmPopup;
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_STOP_NETWORK_CONFIRM));
            VfxWString btnText1;
            btnText1.loadFromRes(STR_GLOBAL_CONTINUE);
            VfxWString btnText2;
            btnText2.loadFromRes(STR_GLOBAL_CANCEL);
            confirmPopup->setCustomButton(
                btnText1,
                btnText2,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirmPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewAttachPage::onDownloadsingleConfirmBtnClick);
            confirmPopup->setAutoDestory(VFX_TRUE);
            confirmPopup->show(VFX_TRUE);
            return;
        }

        VappEmailMgr::getInstance()->retrieveMsgAttach(gAttachInfoArray[index].attach_id);
        showLoading(VFX_TRUE, VFX_TRUE);
    }
}


void VappEmailMsgViewAttachPage::onTBClick(VfxObject *, VfxId)
{
    VappEmailStateEnum emailState = VappEmailMgr::getInstance()->getEmailAppState();
    VappEmailAcctStateEnum acctState = VappEmailMgr::getInstance()->getAcctState(m_acctID);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_TOOLBAR_CLICK, emailState, acctState);

    if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
    }

    if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
    {
        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirmPopup->setText(VFX_WSTR_RES(STR_EMAIL_STOP_NETWORK_CONFIRM));
        VfxWString btnText1;
        btnText1.loadFromRes(STR_GLOBAL_CONTINUE);
        VfxWString btnText2;
        btnText2.loadFromRes(STR_GLOBAL_CANCEL);
        confirmPopup->setCustomButton(
            btnText1,
            btnText2,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        confirmPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewAttachPage::onDownloadAllConfirmBtnClick);
        confirmPopup->setAutoDestory(VFX_TRUE);
        confirmPopup->show(VFX_TRUE);
        return;
    }

    VappEmailMgr::getInstance()->retrieveMsg(m_msgID, SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT);
    showLoading(VFX_TRUE, VFX_TRUE);
}


void VappEmailMsgViewAttachPage::onDownloadAllConfirmBtnClick(VfxObject *, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_DOWNLOAD_ALL_CONFIRM, id);
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VappEmailMgr::getInstance()->cancelCurrNwkOperation();

        VappEmailMgr::getInstance()->retrieveMsg(m_msgID, SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT);
        showLoading(VFX_TRUE, VFX_TRUE);
    }
}


void VappEmailMsgViewAttachPage::onDownloadsingleConfirmBtnClick(VfxObject *, VfxId id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_DOWNLOAD_SINGLE_CONFIRM, id);
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VappEmailMgr::getInstance()->cancelCurrNwkOperation();

        VappEmailMgr::getInstance()->retrieveMsgAttach(gAttachInfoArray[m_attachIndex].attach_id);
        showLoading(VFX_TRUE, VFX_TRUE);
    }
}


void VappEmailMsgViewAttachPage::onSaveAttachBtnClick(VfxObject *obj, VcpInputPopupButtonEnum id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_SAVE_ATTACH_BTN_CLICK, id);
    VappFileNameEditorPopup *fileNameEditor = (VappFileNameEditorPopup*)obj;
    VfxWString fileName = fileNameEditor->getText();
    VFX_OBJ_CLOSE(fileNameEditor);
    if (id == VCP_INPUT_POPUP_BTN_OK)
    {
        mmi_ucs2cat((CHAR*)gSaveAttachPath, (CHAR*)fileName.getBuf());
        gSaveJobID = srv_fmgr_async_copy(
                        gAttachInfoArray[m_attachIndex].path,
                        gSaveAttachPath,
                        0,
                        VappEmailMsgViewAttachPage::saveAttachmentCallback,
                        this);
        if (gSaveJobID > 0)
        {
            showLoading();
        }
        else
        {
            /* popup error for example file already exist */
        }
    }
}


mmi_ret VappEmailMsgViewAttachPage::copyAttachCallback(mmi_event_struct *param)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_COPY_TO_VIEW_CALLBACK);

    VappEmailMsgViewAttachPage *attachPage =
           (VappEmailMsgViewAttachPage *)handleToObject(param->user_data);

    if (attachPage == NULL)
    {
      //Page had been closed during copy file.
      return MMI_RET_OK;
    }

    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            srv_fmgr_async_done_event_struct *asyncEvt = (srv_fmgr_async_done_event_struct*)param;
            if (asyncEvt->result == 0)
            {
                if (attachPage->m_attachViewSave == VFX_TRUE)
                {
                    attachPage->openAttachFile();
                }
                else
                {
                #ifdef __MMI_DOWNLOAD_AGENT__
                    srv_da_ui_setting_struct uiSetting = {0, 0};

                    srv_da_save_file(
                        VAPP_EMAIL,
                        attachPage->m_copyFileDstPathPtr,
                        gAttachInfoArray[attachPage->m_attachIndex].name,
                        NULL,
                        0,
                        NULL,
                        &uiSetting);
                #endif /* __MMI_DOWNLOAD_AGENT__ */
                }
            }
            else
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, attachPage);
                errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(asyncEvt->result));
            }
            free_ctrl_buffer(attachPage->m_copyFileDstPathPtr);
            attachPage->m_copyFileDstPathPtr = NULL;
        }
        break;
    default:
        break;
    }
    attachPage->closeLoading();
    return MMI_RET_OK;
}


mmi_ret VappEmailMsgViewAttachPage::saveAttachmentCallback(mmi_event_struct *param)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_SAVE_CALLBACK);

    VappEmailMsgViewAttachPage *viewAttachPage = (VappEmailMsgViewAttachPage*)(param->user_data);
    srv_fmgr_async_done_event_struct *async_evt;

    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
            {
                viewAttachPage->closeLoading();
                async_evt = (srv_fmgr_async_done_event_struct*)param;
                if (async_evt->result != 0)
                {
                    VappEmailErrorPopup *errorPopup;
                    VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, viewAttachPage);
                    errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(async_evt->result));
                }
            }
            break;
    }
    return MMI_RET_OK;
}


void VappEmailMsgViewAttachPage::onRetrieveDone(
        EMAIL_MSG_ID msgID,
        VappEmailNwkDoneEnum operation,
        VappEmailResStruct result)
{
    if (m_msgID != msgID)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MSG_ATTACH_RETRIEVE_DONE,
        m_msgID,
        result.result,
        result.major,
        result.minor);

    closeLoading();

    if (operation == VAPP_EMAIL_NWK_DONE_CANCEL)
    {
        return;
    }

    if (result.result != VAPP_EMAIL_RES_SUCC)
    {
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_MAIL_ERROR &&
            result.minor == SRV_EMAIL_RESULT_INVALID_MSG)
        {
            /* msg delete on server */
            return;
        }
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_MAIL_ERROR &&
            result.minor == SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE)
        {
            S32 downloadSize = 0;
            srv_email_acct_info_struct *account_info =
                (srv_email_acct_info_struct*)get_ctrl_buffer(sizeof(srv_email_acct_info_struct));
            srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
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
                result = srv_email_acct_read(acctHandle, account_info);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    break;
                }
                downloadSize = account_info->download_size;
            } while(0);
            free_ctrl_buffer(account_info);
            if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
            {
                srv_email_acct_destroy(acctHandle);
            }
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                VappEmailErrorPopup *errorPopup;
                VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
                errorPopup->showErrorPopup(result);
                return;
            }

            VfxWString text1;
            VfxWString text2;
            text1.loadFromRes(STR_EMAIL_FTO_TOO_LARGE_TO_DOWN_ID);
            text2.format("%dKB", (downloadSize + 1023) / 1024);
            text1 += text2;
            VcpConfirmPopup *errorPopup;
            VFX_OBJ_CREATE(errorPopup, VcpConfirmPopup, this);
            errorPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            errorPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            errorPopup->setAutoDestory(VFX_TRUE);
            errorPopup->setText(text1);
            errorPopup->show(VFX_TRUE);
            return;
        }
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, getMainScr());
        if (result.result == VAPP_EMAIL_RES_SERVICE_ERROR &&
            result.major == SRV_EMAIL_RESULT_FS_ERROR &&
            result.minor == SRV_EMAIL_RESULT_MSG_NOT_EXIST)
        {
            errorPopup->showErrorPopup(result, getMainScr(), EMAIL_PAGE_TYPE_MSG_VIEW, EMAIL_PAGE_TYPE_ATTACH_LIST);
        }
        else
        {
            errorPopup->showErrorPopup(result);
        }
        return;
    }

    /* update gAttachInfoArray */
    m_listProvider->onInit();
    updateToolbar();
    /* handle result */
    m_listMenu->updateAllItems();
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappEmailMsgViewAttachPage::onAcctNwkProc(VappEmailNwkStateEnum state, VfxU32 msgID, VappEmailNwkProcEnum proc)
{
    if ((EMAIL_MSG_ID)msgID != m_msgID)
    {
        return;
    }

    if (m_loadingPopup != NULL)
    {
        switch (proc)
        {
        case VAPP_EMAIL_NWK_PROC_CONNECTING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_CONNECTING_NETWORK));
            break;
        case VAPP_EMAIL_NWK_PROC_AUTHORIZING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_AUTHORIZING_ID));
            break;
        case VAPP_EMAIL_NWK_PROC_UPDATING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_UPDATING_INFO_ID));
            break;
        case VAPP_EMAIL_NWK_PROC_RETRIEVING:
            m_loadingPopup->setText(VFX_WSTR_RES(STR_EMAIL_FTO_RETRIEVING_ID));
            break;
        default:
            return;
        }
    }
}


void VappEmailMsgViewAttachPage::saveAttachment()
{    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_SAVE);

    m_attachViewSave = VFX_FALSE;

    S32 attr = 0;
    WCHAR *copyFileDstPath = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    memset(copyFileDstPath, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    kal_wsprintf(copyFileDstPath, "%sattach", srv_email_get_root_path());
    attr = FS_GetAttributes((const WCHAR*)copyFileDstPath);
    if (attr & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes((const WCHAR*)copyFileDstPath, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
    }
    FS_Delete((U16*)copyFileDstPath);
    S32 copyFileJobID =
        srv_fmgr_async_copy(
            gAttachInfoArray[m_attachIndex].path,
            copyFileDstPath,
            0,
            &VappEmailMsgViewAttachPage::copyAttachCallback,
            getObjHandle());
    if (m_copyFileDstPathPtr != NULL)
    {
        free_ctrl_buffer(m_copyFileDstPathPtr);
        m_copyFileDstPathPtr = NULL;
    }
    m_copyFileDstPathPtr = copyFileDstPath;

    if (copyFileJobID > 0)
    {
        VFX_OBJ_CREATE(m_loadingPopup, VcpIndicatorPopup, (VappEmailMsgListPage*)getParent());
        m_loadingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_loadingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_LOADING));
        m_loadingPopup->setAutoDestory(VFX_FALSE);
        m_loadingPopup->show(VFX_TRUE);
    }
    else
    {
        VappEmailErrorPopup *errorPopup;
        VFX_OBJ_CREATE(errorPopup, VappEmailErrorPopup, this);
        errorPopup->showErrorPopup((VfxResId)srv_fmgr_fs_error_get_string(copyFileJobID));
    }
}


void VappEmailMsgViewAttachPage::updateToolbar()
{
    VfxU32 i = 0;
    VfxBool needToolbar = VFX_FALSE;
    VfxBool disableToolbar = VFX_TRUE;
    VfxU32 attachNum = m_listProvider->getCount();
    VappEmailStateEnum emailState;
    if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
    {
        disableToolbar = VFX_FALSE;
    }
    for (; i < attachNum; i++)
    {
        if (!gAttachInfoArray[i].downloaded)
        {
            needToolbar = VFX_TRUE;
        }
    }

    if (needToolbar == VFX_TRUE)
    {
        if (m_toolbar == NULL)
        {
            VfxWString text;
            VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
            text.loadFromRes(STR_EMAIL_DOWNLOAD_ALL);
            m_toolbar->addItem(0, text, VfxResId(IMG_EMAIL_FTO_TB_DOWNLOAD));
            m_toolbar->m_signalButtonTap.connect(this, &VappEmailMsgViewAttachPage::onTBClick);
            setBottomBar(m_toolbar);
        }

        m_toolbar->setDisableItem(0, disableToolbar);
        setBottomBar(m_toolbar);
    }
    else
    {
        if (m_toolbar != NULL)
        {
            VFX_OBJ_CLOSE(m_toolbar);
            m_toolbar = NULL;
        }

        toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        m_listMenu->resetAllItems();
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_UPDATE_TOOLBAR, needToolbar);
}


void VappEmailMsgViewAttachPage::onLoadingBtnClick(VfxObject *, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_LOADING_CANCEL);
        VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);
        closeLoading();
    }
    else if (VCP_POPUP_BUTTON_NO_PRESSED)
    {

        //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_LOADING_CANCEL);
        //VappEmailMgr::getInstance()->cancelMsgRetrieve(m_msgID);
        //closeLoading();
    }
}


void VappEmailMsgViewAttachPage::openAttachFile()
{
    applib_mime_type_struct *mime = applib_mime_get_file_type(m_copyFileDstPathPtr);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_OPEN, mime);
    if (mime != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_ATTACH_OPEN_TYPE, mime->mime_type);
        switch (mime->mime_type)
        {
        case MIME_TYPE_IMAGE:
            {
                m_imageViewer = vcui_gallery_image_viewer_create(getApp()->getGroupId(), m_copyFileDstPathPtr);
                if (m_imageViewer != GRP_ID_INVALID)
                {
                    WCHAR tempName[EMAIL_ATTCH_FILE_NAME_LEN + 1];
                    memcpy(tempName, gAttachInfoArray[m_attachIndex].name, sizeof(WCHAR) * EMAIL_ATTCH_FILE_NAME_LEN + 1);
                    WCHAR *ptr = mmi_wcsrchr(tempName, '.');
                    if (ptr != NULL)
                    {
                        *ptr = 0;
                    }
                    vfxSetCuiCallerScr(m_imageViewer, getMainScr());
                    vcui_gallery_set_title_str_ptr(m_imageViewer, tempName);
                    vcui_gallery_run(m_imageViewer);
                }
            }
            break;
        case MIME_TYPE_AUDIO:
            {
                m_audioPlayer = vcui_music_player_create(getApp()->getGroupId(), m_copyFileDstPathPtr);

                 if (m_audioPlayer != GRP_ID_INVALID)
                 {
                     WCHAR tempName[EMAIL_ATTCH_FILE_NAME_LEN + 1];
                     memcpy(tempName, gAttachInfoArray[m_attachIndex].name, sizeof(WCHAR) * EMAIL_ATTCH_FILE_NAME_LEN + 1);
                     WCHAR *ptr = mmi_wcsrchr(tempName, '.');
                     if (ptr != NULL)
                     {
                         *ptr = 0;
                     }
                     vfxSetCuiCallerScr(m_audioPlayer, getMainScr());
                     vcui_music_player_run(m_audioPlayer);
                     vcui_music_player_set_title(m_audioPlayer, tempName);
                 }
            }
            break;
        case MIME_TYPE_VIDEO:
            #ifndef __MMI_EMAIL_VIDEO_PREVIEW__
            {
                mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)GetString(STR_EMAIL_FTO_VIEW_IN_FMGR));
            }
            #else
            {
                m_videoPlayer = vcui_gallery_video_player_create(getApp()->getGroupId(), m_copyFileDstPathPtr);

                 if (m_videoPlayer != GRP_ID_INVALID)
                 {
                     WCHAR tempName[EMAIL_ATTCH_FILE_NAME_LEN + 1];
                     memcpy(tempName, gAttachInfoArray[m_attachIndex].name, sizeof(WCHAR) * EMAIL_ATTCH_FILE_NAME_LEN + 1);
                     WCHAR *ptr = mmi_wcsrchr(tempName, '.');
                     if (ptr != NULL)
                     {
                         *ptr = 0;
                     }
                     vfxSetCuiCallerScr(m_videoPlayer, getMainScr());
                     vcui_gallery_set_title_str_ptr(m_videoPlayer, tempName);
                     vcui_gallery_run(m_videoPlayer);
                 }
            }
            #endif
            break;
        case MIME_TYPE_APPLICATION:
            {
            #ifdef __MMI_VCARD__
                if (mime->mime_subtype == MIME_SUBTYPE_XVCARD ||
                    mime->mime_subtype == MIME_SUBTYPE_VCARD)
                {
                    m_vcardViewer = vcui_vcard_create(getApp()->getGroupId());

                    if (m_vcardViewer != GRP_ID_INVALID)
                    {
                        vfxSetCuiCallerScr(m_vcardViewer, getMainScr());
                        vcui_vcard_set_path(m_vcardViewer, m_copyFileDstPathPtr);
                        vcui_vcard_run(m_vcardViewer);
                    }
                }
            #endif /* __MMI_VCARD__ */
            
            #ifdef __MMI_VCALENDAR__
                if (mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR ||
                    mime->mime_subtype == MIME_SUBTYPE_HBSVCS ||
                    mime->mime_subtype == MIME_SUBTYPE_CALENDAR)
                {
                    FS_HANDLE fileHandle = 0;
                    fileHandle = FS_Open(m_copyFileDstPathPtr, FS_READ_ONLY);
                    if (fileHandle > 0)
                    {
                        S32 result = 0;
                        U32 fileSize = 0;
                        result = FS_GetFileSize(fileHandle, &fileSize);
                        if (result == FS_NO_ERROR && fileSize > 0)
                        {
                            char *buff = NULL;
                            UINT bytesRead = 0;
                            VFX_ALLOC_MEM(buff, (fileSize + 2), getMainScr());
                            memset(buff, 0, fileSize + 2);
                            result = FS_Read(fileHandle, buff, fileSize, &bytesRead);
                            if (result == FS_NO_ERROR)
                            {
                                vapp_cal_view_detail_from_message_launch((VfxChar*)buff, fileSize);
                            }
                            VFX_FREE_MEM(buff);
                        }
                        FS_Close(fileHandle);
                    }
                }
            #endif /* __MMI_VCALENDAR__ */                
            }
            break;
        default:
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)GetString(STR_EMAIL_FTO_FILE_TYEP_NOT_SUPPORTED_ID));
            break;
        }
    }

    return;
}


VappEmailMsgViewUseDetailsMenuProvider::VappEmailMsgViewUseDetailsMenuProvider(VcpTextView *textView)
    :m_listMenu(NULL),
     m_textView(textView)
{
}


VappEmailMsgViewUseDetailsMenuProvider::VappEmailMsgViewUseDetailsMenuProvider()
{
}


VfxBool VappEmailMsgViewUseDetailsMenuProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &color)
{
    switch (fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            VfxU32 count = 0;
            VcpRichTextFormat *richTextFormat = m_textView->getFormatObject();
            while (richTextFormat)
            {
                if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
                    ((VcpRichText*)richTextFormat)->isKeywordFormat())
                {
                    count++;
                }
                if (count >= index + 1)
                {
                    break;
                }
                richTextFormat = richTextFormat->getNext();
            }
            if (richTextFormat == NULL)
            {
                return VFX_FALSE;
            }
            VfxS32 start = richTextFormat->m_range.getStart();
            VfxS32 end = richTextFormat->m_range.getEnd();
            VfxWChar *text = m_textView->getText();
            VfxWChar tempChar = text[end];
            text[end] = 0;
            textString.loadFromMem(&text[start]);
            text[end] = tempChar;
        }
        break;
    }

    return VFX_TRUE;
}


VfxBool VappEmailMsgViewUseDetailsMenuProvider::getItemImage(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxImageSrc &imageSrc)
{
    switch (fieldType)
    {
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
    case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        {
            /* network not available, all should return VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED */
            VfxU32 count = 0;
            VcpRichTextFormat *richTextFormat = m_textView->getFormatObject();
            while (richTextFormat)
            {
                if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
                    ((VcpRichText*)richTextFormat)->isKeywordFormat())
                {
                    count++;
                }
                if (count >= index + 1)
                {
                    break;
                }
                richTextFormat = richTextFormat->getNext();
            }

            if (richTextFormat == NULL)
            {
                return VFX_FALSE;
            }
            
            VcpTextKeyWordEnum mode = ((VcpRichText*)richTextFormat)->m_mode;

            switch (mode)
            {
                case VCP_TEXT_KEYWORD_EMAIL:
                    imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_SEND_MAIL);
                    break;
                case VCP_TEXT_KEYWORD_URL:
                    imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_GET_URL);
                    break;
                case VCP_TEXT_KEYWORD_PHONENUMBER:
                    if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
                    {
                        imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_CALL_DISABLE);                    
                    }
                    else
                    {
                        imageSrc.setResId((VfxResId)IMG_EMAIL_FTO_LIST_CALL_ENABLE);
                    }
                    break;
                default:
                    return VFX_FALSE;
            }
        }
        break;
    default:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VappEmailMsgViewUseDetailsMenuProvider::closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc)
{
}


VfxU32 VappEmailMsgViewUseDetailsMenuProvider::getCount(void) const
{
    VfxU32 count = 0;
    VcpRichTextFormat *richTextFormat = m_textView->getFormatObject();
    while (richTextFormat)
    {
        if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
            ((VcpRichText*)richTextFormat)->isKeywordFormat())
        {
            count++;
        }
        richTextFormat = richTextFormat->getNext();
    }
    return count;
}


VcpListMenuItemStateEnum VappEmailMsgViewUseDetailsMenuProvider::getItemState(VfxU32) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VcpListMenuCmdStateEnum VappEmailMsgViewUseDetailsMenuProvider::getItemCmdState(VfxU32 index) const
{
    VfxU32 count = 0;
    VcpRichTextFormat *richTextFormat = m_textView->getFormatObject();
    while (richTextFormat)
    {
        if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
            ((VcpRichText*)richTextFormat)->isKeywordFormat())
        {
            count++;
        }
        if (count >= index + 1)
        {
            break;
        }
        richTextFormat = richTextFormat->getNext();
    }
    
    if (richTextFormat == NULL)
    {
        return VCP_LIST_MENU_CMD_STATE_NORMAL;
    }
    
    VcpTextKeyWordEnum mode = ((VcpRichText*)richTextFormat)->m_mode;

    if (mode == VCP_TEXT_KEYWORD_PHONENUMBER)
    {
        if (!srv_sim_ctrl_any_sim_is_available())
        {
            return VCP_LIST_MENU_CMD_STATE_DISABLED;
        }
    }

    return VCP_LIST_MENU_CMD_STATE_NORMAL;
}


VfxBool VappEmailMsgViewUseDetailsMenuProvider::swapItem(VfxU32, VfxU32)
{
    return VFX_TRUE;
}


VcpListMenuCellClientBaseFrame *VappEmailMsgViewUseDetailsMenuProvider::getItemCustomContentFrame(VfxU32, VfxFrame *)
{
    return NULL;
}


void VappEmailMsgViewUseDetailsMenuProvider::closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *)
{
}


void VappEmailMsgViewUseDetailsMenuProvider::onInit()
{
}


VappEmailMsgViewUseDetailsPage::VappEmailMsgViewUseDetailsPage(VcpTextView *textView)
    :m_contTextView(textView)
{
}


VappEmailMsgViewUseDetailsPage::VappEmailMsgViewUseDetailsPage()
{

}


void VappEmailMsgViewUseDetailsPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    VfxWString text;
    text.loadFromRes(STR_EMAIL_FTO_USE_DETAILS_ID);
    titleBar->setTitle(text);
    setTopBar(titleBar);

    VFX_OBJ_CREATE_EX(m_listProvider, VappEmailMsgViewUseDetailsMenuProvider, this, (m_contTextView));
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listProvider->setMenu(m_listMenu);
    m_listMenu->setContentProvider(m_listProvider);
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgViewUseDetailsPage::onItemClick);
    m_listMenu->m_signalCmdButtonClicked.connect(this, &VappEmailMsgViewUseDetailsPage::onCMDBtnClick);

    VappEmailMgr::getInstance()->m_signalSimAvailableChanged.connect(
        this, &VappEmailMsgViewUseDetailsPage::onSimAvailableChanged);    
}


void VappEmailMsgViewUseDetailsPage::onRotate(const VfxScreenRotateParam &param)
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


void VappEmailMsgViewUseDetailsPage::onItemClick(VcpListMenu *, VfxU32 index)
{
    VfxU32 count = 0;
    VcpRichTextFormat *richTextFormat = m_contTextView->getFormatObject();
    while (richTextFormat)
    {
        if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
            ((VcpRichText*)richTextFormat)->isKeywordFormat())
        {
            count++;
        }
        if (count >= index + 1)
        {
            break;
        }
        richTextFormat = richTextFormat->getNext();
    }
    if (richTextFormat == NULL)
    {
        return;
    }
    VcpTextKeyWordEnum mode = ((VcpRichText*)richTextFormat)->m_mode;

    VcpListMenuTextColorEnum color;
    VcpCommandPopup *keywordPopup;
    m_listProvider->getItemText(index, VCP_LIST_MENU_FIELD_TEXT, gKeywordContent, color);
    VFX_OBJ_CREATE(keywordPopup, VcpCommandPopup, this);
    keywordPopup->setAutoDestory(VFX_TRUE);
    keywordPopup->setText(gKeywordContent);
    VfxWString commandText;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_USE_DETAILS_ITEM_CLICK, index, mode);

    /* reset */
    gIsSavePhoneNumber = VFX_FALSE;

    switch (mode)
    {
    case VCP_TEXT_KEYWORD_EMAIL:
        {
            gIsKeywordContentAddr = VFX_TRUE;
            VappEmailStateEnum emailState;
            if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
            {
                commandText.loadFromRes(STR_EMAIL_FTO_SEND_MAIL_ID);
                keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL, commandText);
            }
            commandText.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, commandText);
            commandText.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, commandText);
        }
        break;
    case VCP_TEXT_KEYWORD_URL:
        {
            commandText.loadFromRes(STR_GLOBAL_GO_TO_URL);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_GO_TO_URL, commandText);
        #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__)
            commandText.loadFromRes(STR_EMAIL_FTO_URL_SAVE_FTO_BOOKMARK_ID);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SAVE_TO_BOOKMARKS, commandText);
        #endif /* #if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRM_BKM_INTERFACE_SUPPORT__) */
        }
        break;
    case VCP_TEXT_KEYWORD_PHONENUMBER:
        {
            gIsSavePhoneNumber = VFX_TRUE;
            VappEmailStateEnum emailState;
            if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
            {
                commandText.loadFromRes(STR_GLOBAL_EDIT_BEFORE_CALL);
                keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_EDIT_BEFORE_CALL, commandText);
                commandText.loadFromRes(STR_GLOBAL_SEND_MESSAGE);
                keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_MESSAGE, commandText);
            }
            commandText.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, commandText);
            commandText.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
            keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, commandText);
        }
        break;
    default:
        VFX_OBJ_CLOSE(keywordPopup);
        return;
    }
    commandText.loadFromRes(STR_GLOBAL_CANCEL);
    keywordPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL, commandText, VCP_POPUP_BUTTON_TYPE_CANCEL);
    keywordPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewUseDetailsPage::onKeywordOperationClick);
    keywordPopup->show(VFX_TRUE);
}


void VappEmailMsgViewUseDetailsPage::onKeywordOperationClick(VfxObject *obj, VfxId id)
{
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    VappEmailMsgViewPage * msgViewPage = (VappEmailMsgViewPage*)mainScr->getPage(EMAIL_PAGE_TYPE_MSG_VIEW);
    msgViewPage->onKeywordOperationClick(obj, id);
}


void VappEmailMsgViewUseDetailsPage::onSimAvailableChanged(VfxBool simAvailable)
{
    m_listMenu->updateAllItems();
}


void VappEmailMsgViewHtmlItem::onInit()
{
    VcpFormItemBase::onInit();

    VFX_OBJ_CREATE(m_htmlBtn, VcpButton, this);
    m_htmlBtn->setText(VFX_WSTR_RES(STR_EMAIL_FTO_LINK_HTML));
    m_htmlBtn->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 10);
    m_htmlBtn->setSize(
        gScrnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
        EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT);

    setHeight(EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT + 10);
    setBgColor(VFX_COLOR_TRANSPARENT);
}


void VappEmailMsgViewHtmlItem::updateLayout()
{
#if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER))
    if (m_htmlBtn == NULL)
    {
        return;
    }

    m_htmlBtn->setPos(EMAIL_MSG_VIEW_HEADER_LEFT_GAP, 10);
    m_htmlBtn->setSize(
        gScrnWidth - EMAIL_MSG_VIEW_HEADER_LEFT_GAP - EMAIL_MSG_VIEW_HEADER_RIGHT_GAP,
        EMAIL_MSG_VIEW_CONT_BUTTON_HEIGHT);
#endif /* #if (defined(__MMI_EMAIL_HTML__) && defined(OPERA_V10_BROWSER)) */
}


void VappEmailMsgViewUseDetailsPage::onCMDBtnClick(VcpListMenu *, VfxU32 index)
{
    VcpListMenuTextColorEnum color;
    m_listProvider->getItemText(index, VCP_LIST_MENU_FIELD_TEXT, gKeywordContent, color);

    VfxWString commandText;
    VfxU32 count = 0;
    VcpRichTextFormat *richTextFormat = m_contTextView->getFormatObject();
    while (richTextFormat)
    {
        if (richTextFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
            ((VcpRichText*)richTextFormat)->isKeywordFormat())
        {
            count++;
        }
        if (count >= index + 1)
        {
            break;
        }
        richTextFormat = richTextFormat->getNext();
    }
    if (richTextFormat == NULL)
    {
        return;
    }
    VcpTextKeyWordEnum mode = ((VcpRichText*)richTextFormat)->m_mode;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_USE_DETAILS_CMD_CLICK, index, mode);

    if (mode == VCP_TEXT_KEYWORD_PHONENUMBER)
    {
        srv_phb_remove_invalid_number((U16*)gKeywordContent.getBuf());
        
        mmi_id cuiId;
        cuiId = vcui_dialer_create(getApp()->getGroupId());
        vcui_dialer_set_dial_string(cuiId, (PU16)gKeywordContent.getBuf());
        vcui_dialer_run(cuiId);
    }
    else if (mode == VCP_TEXT_KEYWORD_EMAIL)
    {
        gIsKeywordContentAddr = VFX_TRUE;
        onKeywordOperationClick(NULL, MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL);
    }
    else
    {
        onKeywordOperationClick(NULL, MSG_VIEW_PAGE_KEYWORD_OPERATION_GO_TO_URL);
    }
}


void VappEmailMsgViewRecipientListProvider::onInit()
{
    m_recipientAddrList = NULL;

    srv_email_result_enum result;
    EMAIL_MSG_HANDLE msgHandle = EMAIL_MSG_INVALID_HANDLE;
    srv_email_msg_get_basic_info_struct basicInfo;
    srv_email_msg_get_recipient_struct getRecipientInfo;

    do
    {
        result = srv_email_msg_create(gEmailSrvHandle, &msgHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_open(msgHandle, m_acctID, m_fldrID, m_msgID);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        result = srv_email_msg_get_basic_info(msgHandle, &basicInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_TO)
        {
            m_recipientAddrNum = basicInfo.to_addr_num;
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_TO;
        }
        else if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_CC)
        {
            m_recipientAddrNum = basicInfo.cc_addr_num;
            getRecipientInfo.type = SRV_EMAIL_ADDR_TYPE_CC;
        }
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        getRecipientInfo.start_index = 0;
        getRecipientInfo.number = m_recipientAddrNum;
        getRecipientInfo.addr_list =
            (srv_email_addr_struct*)VappEmailApp::memAlloc(sizeof(srv_email_addr_struct) * m_recipientAddrNum);
        m_recipientAddrList = getRecipientInfo.addr_list;
        result = srv_email_msg_get_recipient(msgHandle, &getRecipientInfo);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
    } while(0);

    if (msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }
}


VfxBool VappEmailMsgViewRecipientListProvider::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &textString,
            VcpListMenuTextColorEnum &color)
{
    switch (fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        if (m_recipientAddrList[index].disp_name_len != 0)
        {
            textString.loadFromMem(m_recipientAddrList[index].disp_name);
        }
        else
        {
            textString.loadFromMem(m_recipientAddrList[index].email_addr);
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        textString.loadFromMem(m_recipientAddrList[index].email_addr);
        break;
    default:
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VappEmailMsgViewRecipientListProvider::getItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc &)
{
    return VFX_FALSE;
}


void VappEmailMsgViewRecipientListProvider::closeItemImage(VfxU32,VcpListMenuFieldEnum, VfxImageSrc)
{
}


VfxU32 VappEmailMsgViewRecipientListProvider::getCount(void) const
{
    return m_recipientAddrNum;
}


VcpListMenuItemStateEnum VappEmailMsgViewRecipientListProvider::getItemState(VfxU32) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappEmailMsgViewRecipientListProvider::swapItem(VfxU32, VfxU32)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappEmailMsgViewRecipientListProvider::getItemCustomContentFrame(VfxU32, VfxFrame *)
{
    return NULL;
}


void VappEmailMsgViewRecipientListProvider::closeItemCustomContentFrame(VfxU32, VcpListMenuCellClientBaseFrame *)
{
}


VappEmailMsgViewRecipientPage::VappEmailMsgViewRecipientPage(
    EMAIL_ACCT_ID acctID,
    EMAIL_FLDR_ID fldrID,
    EMAIL_MSG_ID msgID,
    EmailMsgViewRecipientTypeEnum recipientType)
    :m_acctID(acctID),
     m_fldrID(fldrID),
     m_msgID(msgID),
     m_recipientType(recipientType)
{
}


VappEmailMsgViewRecipientPage::VappEmailMsgViewRecipientPage()
    :m_acctID(EMAIL_ACCT_INVALID_ID),
     m_fldrID(EMAIL_FLDR_INVALID_ID),
     m_msgID(EMAIL_MSG_INVALID_ID),
     m_recipientType(EMAIL_MSG_VIEW_RECIPIENT_TO)
{
}


void VappEmailMsgViewRecipientPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE_EX(
        m_listProvider,
        VappEmailMsgViewRecipientListProvider,
        this,
        (m_acctID, m_fldrID, m_msgID, m_recipientType));
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listProvider->setMenu(m_listMenu);
    m_listMenu->setContentProvider(m_listProvider);
    VfxSize pageSize = getSize();
    m_listMenu->setRect(0, 0, pageSize.width, pageSize.height);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    //m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappEmailMsgViewRecipientPage::onItemClick);
    //m_listMenu->m_signalCmdButtonClicked.connect(this, &VappEmailMsgViewUseDetailsPage::onCMDBtnClick);

    VfxWString text;
    WCHAR recip[20];
    if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_TO)
    {
        kal_wsprintf(recip, "%w", (char*)GetString(STR_EMAIL_FTO_TO_ID));
    }
    else if (m_recipientType == EMAIL_MSG_VIEW_RECIPIENT_CC)
    {
        kal_wsprintf(recip, "%w", (char*)GetString(STR_EMAIL_FTO_CC_ID));
    }
    else
    {
        kal_wsprintf(recip, "%w", (char*)GetString(STR_EMAIL_FTO_BCC_ID));
    }
    recip[mmi_wcslen(recip) - 1] = 0;
    text.loadFromMem(recip);
    VfxWString numString;
    VfxWString tempText;
    numString += VFX_WSTR_RES(STR_EMAIL_FTO_LEFT_PARENTHESES);    
    tempText.format("%d", m_listProvider->getCount());
    numString += tempText;
    numString += VFX_WSTR_RES(STR_EMAIL_FTO_RIGHT_PARENTHESES);
    text += numString;
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    titleBar->setTitle(text);
    setTopBar(titleBar);
}


void VappEmailMsgViewRecipientPage::onDeinit()
{
    m_listProvider->releaseAllRecipientAddr();

    VfxPage::onDeinit();
}


void VappEmailMsgViewRecipientPage::onRotate(const VfxScreenRotateParam &param)
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


void VappEmailMsgViewRecipientPage::onItemClick(VcpListMenu *, VfxU32 index)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MSG_RECIPIENT_PAGE_ITEM, index);

    VcpCommandPopup *operationPopup;
    VFX_OBJ_CREATE(operationPopup, VcpCommandPopup, this);
    operationPopup->setAutoDestory(VFX_TRUE);
    VcpListMenuTextColorEnum color;
    m_listProvider->getItemText(index, VCP_LIST_MENU_FIELD_TEXT, gKeywordContent, color);
    m_listProvider->getItemText(index, VCP_LIST_MENU_FIELD_SUB_TEXT1, gKeywordContentBackUp, color);
    if (gKeywordContentBackUp == gKeywordContent)
    {
        gIsKeywordContentAddr = VFX_TRUE;
    }
    else
    {
        gIsKeywordContentAddr = VFX_FALSE;
    }
    gIsSavePhoneNumber = VFX_FALSE;
    operationPopup->setText(gKeywordContent);
    VappEmailStateEnum emailState;
    VfxWString text;
    if (VappEmailMgr::getInstance()->isNetworkReady(emailState))
    {
        text.loadFromRes(STR_EMAIL_FTO_SEND_MAIL_ID);
        operationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_SEND_EMAIL, text);
    }
    text.loadFromRes(STR_GLOBAL_CREATE_NEW_CONTACT);
    operationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CREATE_NEW_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_ADD_TO_EXISTING_CONTACT);
    operationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_ADD_TO_EXISTING_CONTACT, text);
    text.loadFromRes(STR_GLOBAL_CANCEL);
    operationPopup->addItem(MSG_VIEW_PAGE_KEYWORD_OPERATION_CANCEL, text, VCP_POPUP_BUTTON_TYPE_CANCEL);
    operationPopup->m_signalButtonClicked.connect(this, &VappEmailMsgViewRecipientPage::onKeywordOperationClick);
    operationPopup->show(VFX_TRUE);
}


void VappEmailMsgViewRecipientPage::onKeywordOperationClick(VfxObject *obj, VfxId id)
{
    VappEmailMainScrn *mainScr = (VappEmailMainScrn*)getMainScr();
    VappEmailMsgViewPage * msgViewPage = (VappEmailMsgViewPage*)mainScr->getPage(EMAIL_PAGE_TYPE_MSG_VIEW);
    msgViewPage->onKeywordOperationClick(obj, id);
}

