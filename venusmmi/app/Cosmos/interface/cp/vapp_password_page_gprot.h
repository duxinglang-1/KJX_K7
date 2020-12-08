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
 *  vapp_password_page_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Password page interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_PASSWORD_PAGE_H__
#define __VAPP_PASSWORD_PAGE_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"


#define VAPP_PWD_PAGE_EMPTY_STRING_PTR ((VfxWChar*)L"")


// Page of password
class VappPasswordPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappPasswordPage);

private:
    enum LayoutConfig
    {
#if defined(__MMI_MAINLCD_480X800__)
        MARGIN = 14,
        PROMPT_FONT_SIZE = 32,
        PROMPT_Y = 40,
        EDITOR_Y = 88,
        EDITOR_HEIGHT = 66,
        EXTRA_MSG_Y = 170,
        BUTTON_HEIGHT = 80,
        BUTTON_Y = 224,
#elif defined(__MMI_MAINLCD_240X320__)
        MARGIN = 6,
        PROMPT_FONT_SIZE = 16,
        PROMPT_Y = 14,
        EDITOR_Y = 40,
        EDITOR_HEIGHT = 34,
        EXTRA_MSG_Y = 82,
        BUTTON_HEIGHT = 42,
        BUTTON_Y = 106,
#elif defined(__MMI_MAINLCD_240X400__)
        MARGIN = 6,
        PROMPT_FONT_SIZE = 16,
        PROMPT_Y = 20,
        EDITOR_Y = 46,
        EDITOR_HEIGHT = 34,
        EXTRA_MSG_Y = 87,
        BUTTON_HEIGHT = 42,
        BUTTON_Y = 112,
#else /* __MMI_MAINLCD_320X480__ */
        MARGIN = 10,
        PROMPT_FONT_SIZE = 20,
        PROMPT_Y = 20,
        EDITOR_Y = 50,
        EDITOR_HEIGHT = 40,
        EXTRA_MSG_Y = 100,
        BUTTON_HEIGHT = 40,
        BUTTON_Y = 200,
#endif
        LAYOUT_END_OF_ENUM
    };

    // Password prompt
    VfxTextFrame *m_promptText;
    // More description or trial hint about the password
    VfxTextFrame *m_extraMsgText;
    // Password input box
    VcpTextEditor *m_pwdEditor;
    // Done button to confirm the password
    VcpButton *m_okBtn;
    // Auxiliary button for additional function
    VcpButton *m_auxBtn;
    // Minimum password length
    VfxS32 m_minPwdLen;
    // Maximum password length
    VfxS32 m_maxPwdLen;
    // Count-down timer to enable OK button, see disableDoneButtonForMsec(VfxMsec)
    VfxWeakPtr<VfxTimer> m_countDownTimer;
    // Timeout value to enabled OK button, see disableDoneButtonForMsec(VfxMsec)
    VfxMsec m_timeoutMsec;

    void onOkBtnClicked(VfxObject *obj, VfxId id);
    void onAuxBtnClicked(VfxObject *obj, VfxId id);
    void onInputChanged(VcpTextEditor *editor);
    void onCountDownTick(VfxTimer *timer);
    void setOkBtnEnabledByCond();

protected:
    virtual void onInit();
    virtual void onBack();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    
public:

    // Auxiliary button ID
    enum AuxButtonEnum
    {
        // Default auxiliary button
        AUX_BUTTON_DEFAULT,

        AUX_BUTTON_END_OF_ENUM
    };

    // Type of auxiliary button
    enum AuxTypeEnum
    {
        // Normal button
        AUX_TYPE_NORMAL,
        // Critical button
        AUX_TYPE_CRITICAL,
        // Negative, will show grey button
        AUX_TYPE_NEGATIVE,

        AUX_TYPE_END_OF_ENUM
    };

    // Back events
    enum BackEventEnum
    {
        // Go back event
        GO_BACK,

        BACK_EVENT_END_OF_ENUM
    };

    // Done signal. Emit when user presses the Done button
    VfxSignal1<VappPasswordPage*> m_signalDone;
    // Back signal. Emit after user goes back from the page
    VfxSignal2<VappPasswordPage*, BackEventEnum> m_signalBack;
    // Auxiliary button is pressed
    VfxSignal2<VappPasswordPage*, AuxButtonEnum> m_signalAuxSelected;
    // Events to the proc of this page
    VfxSignal3<VappPasswordPage*, mmi_event_struct*, mmi_ret&> m_signalProc;

    // Constructor
    VappPasswordPage() :
        m_promptText(NULL),
        m_extraMsgText(NULL),
        m_pwdEditor(NULL),
        m_okBtn(NULL),
        m_auxBtn(NULL),
        m_minPwdLen(4),
        m_maxPwdLen(4),
        m_countDownTimer(NULL),
        m_timeoutMsec(0)
    {
    }

    // Set the length restriction of input
    void setLengthRestriction(VfxS32 minPwdLen, VfxS32 maxPwdLen);
    // Prompt text of the password
    void setPrompt(const VfxWString &text);
    // Set sxtra message to hint the password. For example, the number of trials remaining
    void setExtraMessage(const VfxWString &text);
    // Set auxiliary button on the page
    void setAuxButton(AuxButtonEnum id, const VfxWString& text, AuxTypeEnum type = AUX_TYPE_NORMAL);

    // Activate editor, to show virutal keyboard
    void activateEditor()
    {
        m_pwdEditor->activate();
    }

    // Get current input
    const VfxWChar *getInput() const
    {
        return m_pwdEditor->getText();
    }

    // Clear input
    void clearInput()
    {
        m_pwdEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
        m_okBtn->setIsDisabled(VFX_TRUE);
    }

    // Disable the Done button for a while. After mSec milli-seconds, the done
    // button will be re-enabled.
    void disableDoneButtonForMsec(VfxMsec mSec);
};



// Password page owns 2 input box.
// One for the first time input, the other to confirm the input.
class VappConfirmPasswordPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappConfirmPasswordPage);

private:

    enum LayoutConfig
    {
#if defined(__MMI_MAINLCD_480X800__)
        MARGIN = 14,
        PROMPT_FONT_SIZE = 32,
        EDITOR_HEIGHT = 66,
        INPUT_PROMPT_Y = 40,
        INPUT_EDITOR_Y = 88,
        CONFIRM_PROMPT_Y = 170,
        CONFIRM_EDITOR_Y = 220,
        BUTTON_HEIGHT = 80,
        BUTTON_Y = 306,
#elif defined(__MMI_MAINLCD_240X320__)
        MARGIN = 6,
        PROMPT_FONT_SIZE = 16,
        EDITOR_HEIGHT = 34,
        INPUT_PROMPT_Y = 14,
        INPUT_EDITOR_Y = 40,
        CONFIRM_PROMPT_Y = 82,
        CONFIRM_EDITOR_Y = 106,
        BUTTON_HEIGHT = 40,
        BUTTON_Y = 148,
#elif defined(__MMI_MAINLCD_240X400__)
        MARGIN = 6,
        PROMPT_FONT_SIZE = 16,
        EDITOR_HEIGHT = 34,
        INPUT_PROMPT_Y = 14,
        INPUT_EDITOR_Y = 40,
        CONFIRM_PROMPT_Y = 82,
        CONFIRM_EDITOR_Y = 106,
        BUTTON_HEIGHT = 40,
        BUTTON_Y = 148,
#else /* __MMI_MAINLCD_320X480__ */
        MARGIN = 10,
        PROMPT_FONT_SIZE = 20,
        EDITOR_HEIGHT = 40,
        INPUT_PROMPT_Y = 15,
        INPUT_EDITOR_Y = 45,
        CONFIRM_PROMPT_Y = 95,
        CONFIRM_EDITOR_Y = 125,
        BUTTON_HEIGHT = 40,
        BUTTON_Y = 200,
#endif

        LAYOUT_END_OF_ENUM
    };

    // Prompt of the password
    VfxTextFrame *m_inputPromptText;
    // Password input box
    VcpTextEditor *m_inputEditor;
    // Prompt of password confirmation
    VfxTextFrame *m_confirmPromptText;
    // Input box for password confirmation
    VcpTextEditor *m_confirmEditor;
    // Done button to confirm password
    VcpButton *m_okBtn;
    // Auxiliary button for additional function
    VcpButton *m_auxBtn;
    // Message for different password inputs
    VfxWString m_diffInputPrompt;
    // Minimum password length
    VfxS32 m_minPwdLen;
    // Maximum password length
    VfxS32 m_maxPwdLen;
    // Instance of a confirm popup
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopup;

    void onInputChanged(VcpTextEditor *editor);
    void onOkBtnClicked(VfxObject *obj, VfxId id);
    void onAuxBtnClicked(VfxObject *obj, VfxId id);
    void onDiffInputConfirmed(VfxObject *obj, VfxId id);
    
protected:
    virtual void onInit();
    virtual mmi_ret onProc(mmi_event_struct *evt);

public:
    // Auxiliary button ID
    enum AuxButtonEnum
    {
        // Default auxiliary button
        AUX_BUTTON_DEFAULT,

        AUX_BUTTON_END_OF_ENUM
    };

    // Type of auxiliary button
    enum AuxTypeEnum
    {
        // Normal
        AUX_TYPE_NORMAL,
        // Critical
        AUX_TYPE_CRITICAL,
        // Negative, will show grey button
        AUX_TYPE_NEGATIVE,

        AUX_TYPE_END_OF_ENUM
    };

    // Done signal. Emit when user presses the Done button
    VfxSignal1<VappConfirmPasswordPage*> m_signalDone;
    // Auxiliary button is pressed
    VfxSignal2<VappConfirmPasswordPage*, AuxButtonEnum> m_signalAuxSelected;
    // Events to the proc of this page
    VfxSignal3<VappConfirmPasswordPage*, mmi_event_struct*, mmi_ret&> m_signalProc;

    VappConfirmPasswordPage() :
        m_inputPromptText(NULL),
        m_inputEditor(NULL),
        m_confirmPromptText(NULL),
        m_confirmEditor(NULL),
        m_okBtn(NULL),
        m_auxBtn(NULL),
        m_minPwdLen(4),
        m_maxPwdLen(4),
        m_confirmPopup(NULL)
    {
    }

    // Set the length restriction of input
    void setLengthRestriction(VfxS32 minPwdLen, VfxS32 maxPwdLen);
    // Prompt text of the password
    void setPrompt(const VfxWString &inputPrompt, const VfxWString &confirmPrompt);
    // Set auxiliary button on the page
    void setAuxButton(AuxButtonEnum id, const VfxWString& text, AuxTypeEnum type = AUX_TYPE_NORMAL);

    // Set the prompt text on different inputs
    void setDiffInputPrompt(const VfxWString &promptText)
    {
        m_diffInputPrompt = promptText;
    }

    // Activate editor, to show virutal keyboard
    void activateEditor()
    {
        m_inputEditor->activate();
    }

    // Get current input
    const VfxWChar *getInput() const
    {
        return m_inputEditor->getText();
    }

    // Clear input
    void clearInput()
    {
        m_inputEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
        m_confirmEditor->setText(VAPP_PWD_PAGE_EMPTY_STRING_PTR, m_maxPwdLen);
        m_okBtn->setIsDisabled(VFX_TRUE);
    }
};


#endif /* __VAPP_PASSWORD_PAGE_H__ */

