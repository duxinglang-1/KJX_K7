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
 *  vapp_password_page.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Password page
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_password_page_gprot.h"
#include "vapp_style_dyer_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"

VFX_IMPLEMENT_CLASS("VappPasswordPage", VappPasswordPage, VfxPage);


void VappPasswordPage::onInit()
{
    VfxPage::onInit();
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    //VappStyleDyer *dyer = VappStyleDyer::getDefaultDyer();
    //dyer->dyePage(this);
	VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(PROMPT_FONT_SIZE);
    VfxSize pageSize = getSize();

    VFX_OBJ_CREATE(m_promptText, VfxTextFrame, this);
    //dyer->dyeTextOnPage(m_promptText, PROMPT_FONT_SIZE);
    m_promptText->setFont(font);       
	m_promptText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_promptText->setPos(MARGIN, PROMPT_Y);
    m_promptText->setString(VFX_WSTR_EMPTY);

    VFX_OBJ_CREATE(m_pwdEditor, VcpTextEditor, this);
    m_pwdEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_pwdEditor->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);
    m_pwdEditor->setPos(MARGIN, EDITOR_Y);
    m_pwdEditor->setSize(pageSize.width - 2 * MARGIN, EDITOR_HEIGHT);
    m_pwdEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_pwdEditor->setAutoActivated(VFX_TRUE);
    m_pwdEditor->m_signalTextChanged.connect(this, &VappPasswordPage::onInputChanged);

    VFX_OBJ_CREATE(m_extraMsgText, VfxTextFrame, this);
    m_extraMsgText->setFont(font);       
	m_extraMsgText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    //dyer->dyeTextOnPage(m_extraMsgText, PROMPT_FONT_SIZE);
    m_extraMsgText->setPos(MARGIN, EXTRA_MSG_Y);
    m_extraMsgText->setString(VFX_WSTR_EMPTY);

    VFX_OBJ_CREATE(m_okBtn, VcpButton, this);
    m_okBtn->setSize(pageSize.width - MARGIN * 2, BUTTON_HEIGHT);
    m_okBtn->setPos(MARGIN, BUTTON_Y);
    m_okBtn->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
    m_okBtn->m_signalClicked.connect(this, &VappPasswordPage::onOkBtnClicked);
    m_okBtn->setIsDisabled(VFX_TRUE);
    m_okBtn->setText(STR_GLOBAL_OK);
}


// will be called only on external operations, such as by other app or by framework
void VappPasswordPage::onBack()
{
    if (m_signalBack.getSlotCount() == 0)
    {
        // VfxPage::onBack() will close the page
        VfxPage::onBack();
    }
    else
    {
        m_signalBack.postEmit(this, GO_BACK);
    }
}


mmi_ret VappPasswordPage::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_DONT_CARE;

    m_signalProc.emit(this, evt, ret);

    return ret;
}


void VappPasswordPage::setLengthRestriction(VfxS32 minPwdLen, VfxS32 maxPwdLen)
{
    VFX_ASSERT(0 < minPwdLen && minPwdLen <= maxPwdLen);

    m_minPwdLen = minPwdLen;
    m_maxPwdLen = maxPwdLen;
    m_pwdEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
    m_okBtn->setIsDisabled(VFX_TRUE);
}


void VappPasswordPage::setPrompt(const VfxWString &text)
{
    m_promptText->setString(text);
    m_promptText->setSize(m_promptText->getMeasureBounds().size);
}


void VappPasswordPage::setExtraMessage(const VfxWString &text)
{
    m_extraMsgText->setString(text);
    m_extraMsgText->setSize(m_promptText->getMeasureBounds().size);
}


void VappPasswordPage::setAuxButton(AuxButtonEnum id, const VfxWString& text, AuxTypeEnum type)
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
        m_auxBtn->m_signalClicked.connect(this, &VappPasswordPage::onAuxBtnClicked);
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


void VappPasswordPage::onInputChanged(VcpTextEditor *editor)
{
    setOkBtnEnabledByCond();
}


void VappPasswordPage::setOkBtnEnabledByCond()
{
    VfxU32 inputLen = vfx_sys_wcslen(m_pwdEditor->getText());
    
    if (static_cast<VfxS32>(inputLen) >= m_minPwdLen &&
        !m_countDownTimer.isValid())
    {
        // enable
        m_okBtn->setIsDisabled(VFX_FALSE);
    }
    else
    {
        // disable
        m_okBtn->setIsDisabled(VFX_TRUE);
    }
}


void VappPasswordPage::onOkBtnClicked(VfxObject *obj, VfxId id)
{
    m_signalDone.emit(this);
}


void VappPasswordPage::onAuxBtnClicked(VfxObject *obj, VfxId id)
{
    m_signalAuxSelected.emit(this, static_cast<AuxButtonEnum>(id));
}


void VappPasswordPage::disableDoneButtonForMsec(VfxMsec mSec)
{
    VFX_ASSERT(mSec > 0);

    m_timeoutMsec = (VfxTimer::getCurrentTime() + mSec);
    m_okBtn->setIsDisabled(VFX_TRUE);

    if (!m_countDownTimer.isValid())
    {
        VFX_OBJ_CREATE(m_countDownTimer, VfxTimer, this);
        m_countDownTimer->m_signalTick.connect(this, &VappPasswordPage::onCountDownTick);
    }
    else
    {
        m_countDownTimer->stop();
    }

    m_countDownTimer->setStartDelay(0);
    m_countDownTimer->setDuration(1000);
    m_countDownTimer->start();
    
}


void VappPasswordPage::onCountDownTick(VfxTimer *timer)
{
    VfxMsec currentTime = VfxTimer::getCurrentTime();
    VfxMsec diffMsec = vfxMsecDiff(m_timeoutMsec, currentTime);
    
    if (diffMsec > 0)
    {
        VfxWString remainingSecStr;
        remainingSecStr.format("%d", ((diffMsec - 1) / 1000) + 1);
        m_okBtn->setText(remainingSecStr);
    }
    else
    {
        m_countDownTimer->stop();
        VFX_OBJ_CLOSE(m_countDownTimer);
        
        setOkBtnEnabledByCond();
        m_okBtn->setText(STR_GLOBAL_OK);
    }
}
