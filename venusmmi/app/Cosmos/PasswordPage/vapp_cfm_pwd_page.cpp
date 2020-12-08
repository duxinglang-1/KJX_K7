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
 *  vapp_cfm_pwd_page.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Confirm password page
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_password_page_gprot.h"
#include "vapp_style_dyer_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"

VFX_IMPLEMENT_CLASS("VappConfirmPasswordPage", VappConfirmPasswordPage, VfxPage);


void VappConfirmPasswordPage::onInit()
{
    VfxPage::onInit();
    //VappStyleDyer *dyer = VappStyleDyer::getDefaultDyer();
    //dyer->dyePage(this);
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    VfxSize pageSize = getSize();
	VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(PROMPT_FONT_SIZE);

    VFX_OBJ_CREATE(m_inputPromptText, VfxTextFrame, this);
	

    m_inputPromptText->setFont(font);       
	m_inputPromptText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    //dyer->dyeTextOnPage(m_inputPromptText, PROMPT_FONT_SIZE);
    m_inputPromptText->setPos(MARGIN, INPUT_PROMPT_Y);
    m_inputPromptText->setString(VFX_WSTR_EMPTY);

    VFX_OBJ_CREATE(m_inputEditor, VcpTextEditor, this);
    m_inputEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_inputEditor->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);
    m_inputEditor->setPos(MARGIN, INPUT_EDITOR_Y);
    m_inputEditor->setSize(pageSize.width - 2 * MARGIN, EDITOR_HEIGHT);
    m_inputEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_inputEditor->setAutoActivated(VFX_TRUE);
    m_inputEditor->m_signalTextChanged.connect(this, &VappConfirmPasswordPage::onInputChanged);

    VFX_OBJ_CREATE(m_confirmPromptText, VfxTextFrame, this);
	//font.size = VFX_FONT_DESC_VF_SIZE(PROMPT_FONT_SIZE);
    m_confirmPromptText->setFont(font);       
	m_confirmPromptText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    //dyer->dyeTextOnPage(m_confirmPromptText, PROMPT_FONT_SIZE);
    m_confirmPromptText->setPos(MARGIN, CONFIRM_PROMPT_Y);
    m_confirmPromptText->setString(VFX_WSTR_EMPTY);

    VFX_OBJ_CREATE(m_confirmEditor, VcpTextEditor, this);
    m_confirmEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_confirmEditor->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);
    m_confirmEditor->setPos(MARGIN, CONFIRM_EDITOR_Y);
    m_confirmEditor->setSize(pageSize.width - 2 * MARGIN, EDITOR_HEIGHT);
    m_confirmEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_confirmEditor->m_signalTextChanged.connect(this, &VappConfirmPasswordPage::onInputChanged);

    VFX_OBJ_CREATE(m_okBtn, VcpButton, this);
    m_okBtn->setSize(pageSize.width - MARGIN * 2, BUTTON_HEIGHT);
    m_okBtn->setPos(MARGIN, BUTTON_Y);
    m_okBtn->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    m_okBtn->m_signalClicked.connect(this, &VappConfirmPasswordPage::onOkBtnClicked);
    m_okBtn->setIsDisabled(VFX_TRUE);
    m_okBtn->setText(STR_GLOBAL_OK);
}


mmi_ret VappConfirmPasswordPage::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_DONT_CARE;

    m_signalProc.emit(this, evt, ret);

    return ret;
}


void VappConfirmPasswordPage::setLengthRestriction(VfxS32 minPwdLen, VfxS32 maxPwdLen)
{
    VFX_ASSERT(0 < minPwdLen && minPwdLen <= maxPwdLen);

    m_minPwdLen = minPwdLen;
    m_maxPwdLen = maxPwdLen;
    m_inputEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_confirmEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_okBtn->setIsDisabled(VFX_TRUE);
}


void VappConfirmPasswordPage::setPrompt(const VfxWString &inputPrompt, const VfxWString &confirmPrompt)
{
    m_inputPromptText->setString(inputPrompt);
    m_inputPromptText->setSize(m_inputPromptText->getMeasureBounds().size);
    m_confirmPromptText->setString(confirmPrompt);
    m_confirmPromptText->setSize(m_confirmPromptText->getMeasureBounds().size);
}


void VappConfirmPasswordPage::setAuxButton(AuxButtonEnum id, const VfxWString& text, AuxTypeEnum type)
{
    if (m_auxBtn == NULL)
    {
        VfxSize pageSize = getSize();

        m_okBtn->setSize((pageSize.width - MARGIN * 3) / 2, m_okBtn->getSize().height);
        m_okBtn->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_NONE);

        VfxRect okBtnRect = m_okBtn->getRect();
        VFX_OBJ_CREATE(m_auxBtn, VcpButton, this);
        m_auxBtn->setText(text);
        m_auxBtn->setSize(pageSize.width - okBtnRect.size.width - MARGIN * 3, okBtnRect.size.height);
        m_auxBtn->setPos(pageSize.width - MARGIN - m_auxBtn->getSize().width, okBtnRect.origin.y);
        m_auxBtn->setId(static_cast<VfxId>(id));
        if (type == AUX_TYPE_CRITICAL)
        {
            m_auxBtn->setStyle(VCP_BUTTON_STYLE_RED);
        }
        else if (type == AUX_TYPE_NEGATIVE)
        {
            m_auxBtn->setStyle(VCP_BUTTON_STYLE_GREY);
        }
        m_auxBtn->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_NONE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_NONE);
        m_auxBtn->m_signalClicked.connect(this, &VappConfirmPasswordPage::onAuxBtnClicked);
    }
    else
    {
        m_auxBtn->setText(text);
        if (type == AUX_TYPE_CRITICAL)
        {
            m_auxBtn->setStyle(VCP_BUTTON_STYLE_RED);
        }
        else if (type == AUX_TYPE_NEGATIVE)
        {
            m_auxBtn->setStyle(VCP_BUTTON_STYLE_GREY);
        }
        else
        {
            m_auxBtn->setStyle(VCP_BUTTON_STYLE_DEFAULT);
        }
    }
}


void VappConfirmPasswordPage::onInputChanged(VcpTextEditor *editor)
{
    VfxU32 inputLen = vfx_sys_wcslen(m_inputEditor->getText());
    VfxU32 confirmLen = vfx_sys_wcslen(m_confirmEditor->getText());
    
    if (static_cast<VfxS32>(inputLen) >= m_minPwdLen &&
        static_cast<VfxS32>(confirmLen) >= m_minPwdLen)
    {
        m_okBtn->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_okBtn->setIsDisabled(VFX_TRUE);
    }
}


void VappConfirmPasswordPage::onOkBtnClicked(VfxObject *obj, VfxId id)
{
    if (vfx_sys_wcscmp(m_inputEditor->getText(), m_confirmEditor->getText()) == 0)
    {
        m_signalDone.emit(this);
    }
    else
    {
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        m_confirmPopup->setText(m_diffInputPrompt);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirmPopup->show(VFX_TRUE);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappConfirmPasswordPage::onDiffInputConfirmed);
    }
}


void VappConfirmPasswordPage::onDiffInputConfirmed(VfxObject *obj, VfxId id)
{
    if (m_confirmPopup.isValid())
    {
        m_confirmPopup->exit(VFX_TRUE);
        m_confirmPopup = NULL;
    }

    clearInput();
    activateEditor();
}


void VappConfirmPasswordPage::onAuxBtnClicked(VfxObject *obj, VfxId id)
{
    m_signalAuxSelected.emit(this, static_cast<AuxButtonEnum>(id));
}

