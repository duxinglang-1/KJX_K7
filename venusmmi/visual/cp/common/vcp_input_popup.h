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
 *  vcp_input_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Input popup Component
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_INPUT_POPUP_H__
#define __VCP_INPUT_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_button.h"
#include "vcp_text_editor.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
// <group DOM_InputPopup_Macro&Enum_Macro>
#if defined(__MMI_MAINLCD_320X480__)
#define VCP_INPUT_POPUP_MAX_GROUP_NUM            2
#define VCP_INPUT_POPUP_WIDTH                    290
#define VCP_INPUT_POPUP_LANDSCAPE_WIDTH          340
#define VCP_INPUT_POPUP_INPUTBOX_WIDTH           (VCP_INPUT_POPUP_WIDTH - 2 * VCP_INPUT_POPUP_LR_GAP)
#define VCP_INPUT_POPUP_INPUTBOX_HEIGHT          39
#define VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS      100
#define VCP_INPUT_POPUP_TD_GAP                   5
#define VCP_INPUT_POPUP_LR_GAP                   15
#define VCP_INPUT_POPUP_BOTTOM_GAP               16
#define VCP_INPUT_POPUP_TITLE_X                  VCP_INPUT_POPUP_LR_GAP
#define VCP_INPUT_POPUP_TITLE_Y                   0
#define VCP_INPUT_POPUP_TITLE_HEIGHT             25
#define VCP_INPUT_POPUP_TEXT_WIDTH               VCP_INPUT_POPUP_INPUTBOX_WIDTH
#define VCP_INPUT_POPUP_TEXT_HEIGHT               0
#define VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE        3
#define VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE       2
#define VCP_INPUT_POPUP_BUTTON_WIDTH              ((VCP_INPUT_POPUP_INPUTBOX_WIDTH - VCP_INPUT_POPUP_BUTTON_GAP) / 2)
#define VCP_INPUT_POPUP_BUTTON_HEIGHT             45
#define VCP_INPUT_POPUP_BUTTON_GAP                4
#define VCP_INPUT_POPUP_BUTTON_TEXT_LEFT_MARGIN   10
#define VCP_INPUT_POPUP_TITLE_FONT_SIZE           15
#define VCP_INPUT_POPUP_HINT_FONT_SIZE            18
#define VCP_INPUT_POPUP_ERROR_FONT_SIZE           14
#define VCP_INPUT_POPUP_BTN_FONT_SIZE             18
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_INPUT_POPUP_MAX_GROUP_NUM            2
#define VCP_INPUT_POPUP_WIDTH                    446
#define VCP_INPUT_POPUP_LANDSCAPE_WIDTH          546
#define VCP_INPUT_POPUP_INPUTBOX_WIDTH           (VCP_INPUT_POPUP_WIDTH - 2 * VCP_INPUT_POPUP_LR_GAP)
#define VCP_INPUT_POPUP_INPUTBOX_HEIGHT          67
#define VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS      100
#define VCP_INPUT_POPUP_TD_GAP                   14
#define VCP_INPUT_POPUP_LR_GAP                   21
#define VCP_INPUT_POPUP_BOTTOM_GAP               30
#define VCP_INPUT_POPUP_TITLE_X                  VCP_INPUT_POPUP_LR_GAP
#define VCP_INPUT_POPUP_TITLE_Y                   0
#define VCP_INPUT_POPUP_TITLE_HEIGHT             45
#define VCP_INPUT_POPUP_TEXT_WIDTH               VCP_INPUT_POPUP_INPUTBOX_WIDTH
#define VCP_INPUT_POPUP_TEXT_HEIGHT               0
#define VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE        3
#define VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE       2
#define VCP_INPUT_POPUP_BUTTON_WIDTH              ((VCP_INPUT_POPUP_INPUTBOX_WIDTH - VCP_INPUT_POPUP_BUTTON_GAP) / 2)
#define VCP_INPUT_POPUP_BUTTON_HEIGHT             70
#define VCP_INPUT_POPUP_BUTTON_GAP                10
#define VCP_INPUT_POPUP_BUTTON_TEXT_LEFT_MARGIN   18 /* Unused after button text center aligned */
#define VCP_INPUT_POPUP_TITLE_FONT_SIZE           24
#define VCP_INPUT_POPUP_HINT_FONT_SIZE            30
#define VCP_INPUT_POPUP_ERROR_FONT_SIZE           24
#define VCP_INPUT_POPUP_BTN_FONT_SIZE             30
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_INPUT_POPUP_MAX_GROUP_NUM            2
#define VCP_INPUT_POPUP_WIDTH                    222
#define VCP_INPUT_POPUP_LANDSCAPE_WIDTH          242
#define VCP_INPUT_POPUP_INPUTBOX_WIDTH           (VCP_INPUT_POPUP_WIDTH - 2 * VCP_INPUT_POPUP_LR_GAP)
#define VCP_INPUT_POPUP_INPUTBOX_HEIGHT          37
#define VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS      100
#define VCP_INPUT_POPUP_TD_GAP                   5
#define VCP_INPUT_POPUP_LR_GAP                   8
#define VCP_INPUT_POPUP_BOTTOM_GAP               13
#define VCP_INPUT_POPUP_TITLE_X                  VCP_INPUT_POPUP_LR_GAP
#define VCP_INPUT_POPUP_TITLE_Y                   0
#define VCP_INPUT_POPUP_TITLE_HEIGHT             20
#define VCP_INPUT_POPUP_TEXT_WIDTH               VCP_INPUT_POPUP_INPUTBOX_WIDTH
#define VCP_INPUT_POPUP_TEXT_HEIGHT               0
#define VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE        3
#define VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE       2
#define VCP_INPUT_POPUP_BUTTON_WIDTH              ((VCP_INPUT_POPUP_INPUTBOX_WIDTH - VCP_INPUT_POPUP_BUTTON_GAP) / 2)
#define VCP_INPUT_POPUP_BUTTON_HEIGHT             40
#define VCP_INPUT_POPUP_BUTTON_GAP                5
#define VCP_INPUT_POPUP_BUTTON_TEXT_LEFT_MARGIN   18
#define VCP_INPUT_POPUP_TITLE_FONT_SIZE           13
#define VCP_INPUT_POPUP_HINT_FONT_SIZE            14
#define VCP_INPUT_POPUP_ERROR_FONT_SIZE           14
#define VCP_INPUT_POPUP_BTN_FONT_SIZE             16
#else
#define VCP_INPUT_POPUP_MAX_GROUP_NUM            2
#define VCP_INPUT_POPUP_WIDTH                    290
#define VCP_INPUT_POPUP_LANDSCAPE_WIDTH          340
#define VCP_INPUT_POPUP_INPUTBOX_WIDTH           (VCP_INPUT_POPUP_WIDTH - 2 * VCP_INPUT_POPUP_LR_GAP)
#define VCP_INPUT_POPUP_INPUTBOX_HEIGHT          39
#define VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS      100
#define VCP_INPUT_POPUP_TD_GAP                   5
#define VCP_INPUT_POPUP_LR_GAP                   16
#define VCP_INPUT_POPUP_BOTTOM_GAP               19
#define VCP_INPUT_POPUP_TITLE_X                  VCP_INPUT_POPUP_LR_GAP
#define VCP_INPUT_POPUP_TITLE_Y                   0
#define VCP_INPUT_POPUP_TITLE_HEIGHT             25
#define VCP_INPUT_POPUP_TEXT_WIDTH               VCP_INPUT_POPUP_INPUTBOX_WIDTH
#define VCP_INPUT_POPUP_TEXT_HEIGHT               0
#define VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE        3
#define VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE       2
#define VCP_INPUT_POPUP_BUTTON_WIDTH              ((VCP_INPUT_POPUP_INPUTBOX_WIDTH - VCP_INPUT_POPUP_BUTTON_GAP) / 2)
#define VCP_INPUT_POPUP_BUTTON_HEIGHT             45
#define VCP_INPUT_POPUP_BUTTON_GAP                5
#define VCP_INPUT_POPUP_BUTTON_TEXT_LEFT_MARGIN   10
#define VCP_INPUT_POPUP_TITLE_FONT_SIZE           15
#define VCP_INPUT_POPUP_HINT_FONT_SIZE            18
#define VCP_INPUT_POPUP_ERROR_FONT_SIZE           14
#define VCP_INPUT_POPUP_BTN_FONT_SIZE             18
#endif

#define     VFX_TOP_LEVEL_Z_INPUT_POPUP    7500 // Should be bigger than VFX_TOP_LEVEL_Z_IME_UI

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// <group DOM_InputPopup_VcpInputPopup_Enum>
enum VcpInputPopupButtonEnum
{
    // ok button id
    VCP_INPUT_POPUP_BTN_OK,
    // cancel button id
    VCP_INPUT_POPUP_BTN_CANCEL,
    VCP_INPUT_POPUP_BTN_TOTAL
};


/*****************************************************************************
 * Class VcpInputPopup
 *****************************************************************************/

/*
 *  VcpInputPopup show input popup. 
 *  Applications can show an Inputbox inside a popup.
 *  This is usually used for quick input password.
 *  If you want to change the input type of editor, please use setIME to set the input type.
 *  When finish input, press Ok/Cancel button, signal will be emit to App to handle the button event.
 *  Currently we support max two groups editor due to screen size limitation.
 *
 * EXAMPLE
 * <code>
 *  VcpInputPopup *m_inputPopup;
 *  VFX_OBJ_CREATE(m_inputPopup, VcpInputPopup, this);
 *  m_inputPopup->setHintText(VFX_WSTR("This is a input popup test, you can set any input type. Please input password:")); 
 *  m_inputPopup->m_signalButtonClicked.connect(this, &VtstRtInputPopup::ipOnButtonClicked);
 *  m_inputPopup->setText(VFX_WSTR("Hello World!"), 20);
 *  m_inputPopup->setTitle(VFX_WSTR("This is title"));
 *  m_inputPopup->show(VFX_TRUE);
 * </code>
 */
class VcpInputPopup : public VfxBasePopup
{
    VFX_DECLARE_CLASS(VcpInputPopup);
// Constructor / Destructor
public:
    // <group DOM_InputPopup_VcpInputPopup_Constructor/Destructor>
    VcpInputPopup(); 

// Override
public:
    // <group DOM_InputPopup_VcpInputPopup_Override>
    // get ime mode
   // virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}
	virtual void onObjectNotify(VfxId id, void *userData);

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // While IME becomes active, it notifies top level to adjust layout to fit input area
    virtual void setIMElayout(
        VfxRect &imeRect,       // [IN] IME area
        VfxFrame *imeOwner      // [IN] The owner who creates IME
    );

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // While IME becomes inactive, it notifies to reset the layout
    virtual void resetIMElayout();

// Method
public:

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // Show the popup
    void show(
        VfxBool isAnim      // [IN] show animation or not
    );

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // set Group number
    void setGroupNum(
        VfxU8 num           // [IN] group number
        );
    
    // <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text
    void setTitle(
        const VfxWString &title                  // [IN] title text
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text
    void setTitle(
        VfxResId title_id                  // [IN] title text
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text
    void setTitle(
        const VfxWChar* title_buf                  // [IN] title text
        );
	 
    // <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text, only show hint text when group number more than one
    void setHintText(
        const VfxWString &text,                  // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text, only show hint text when group number more than one
    void setHintText(
        VfxResId text_id,                  // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set hint text, only show hint text when group number more than one
    void setHintText(
        const VfxWChar* text_buf,                  // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // set error text
    void setErrorText(
        const VfxWString &text,                  // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set error text
    void setErrorText(
        VfxResId text_id,                  // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // set error text
    void setErrorText(
        const VfxWChar* text_buf,                // [IN] text
        VfxU8 index = 0                          // [IN] group ID
        );
	
    // <group DOM_InputPopup_VcpInputPopup_Method>
    // Set a editable string with a specfic encoding type for counter
    void setText(
        const VfxWString &text,                 // [IN] text
        VfxS32 maxLen,                          // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,        // [IN] need editor malloc buffer for edit
        VfxU8 index = 0                         // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // Set a editable string with a specfic encoding type for counter
    void setText(
        VfxResId text_id,                 // [IN] text
        VfxS32 maxLen,                          // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,        // [IN] need editor malloc buffer for edit
        VfxU8 index = 0                         // [IN] group ID
        );

	/* vaib mem reduction*/
	// <group DOM_InputPopup_VcpInputPopup_Method>
    // Set a editable string with a specfic encoding type for counter
    void setText(
        const VfxWChar* text_buf,               // [IN] text
        VfxS32 maxLen,                          // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,        // [IN] need editor malloc buffer for edit
        VfxU8 index = 0                         // [IN] group ID
        );
	
    // <group DOM_InputPopup_VcpInputPopup_Method>
    // get input text
    const VfxWString getText(
        VfxU8 index = 0                          // [IN] group ID
    ) const
    {
        return VFX_WSTR_MEM(m_inputbox[index]->getText());
    }

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // Set IME input type and IME 
    void setIME(
        VfxU64 inputType,             // [IN] the input type: mmi_imm_input_type_enum
        InputSettingEnum inputSetting = IME_SETTING_FLAG_NONE,   // [IN] ime setting
        VfxU8 index = 0               // [IN] group ID
        );

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // get editor
    VcpTextEditor *getInputbox(
        VfxU8 index = 0                          // [IN] group ID
    )
    {
        return m_inputbox[index];
    }

    // <group DOM_InputPopup_VcpInputPopup_Method>
    // set is allowed empty content in editor
    // If true, then the Ok button will not be disalbed if editor is empty
    void setIsAllowedEmptyContent(
        VfxBool value                           // [IN] allowed empty or not
        )
    {
        m_isAllowdEmptyContent = value;
    }

// Signal
public:
    // <group DOM_InputPopup_VcpInputPopup_Event>
    // when the input popup is closed
    VfxSignal1 <
        VcpInputPopup*                    // popup
    > m_signalPopupClosed;

    // <group DOM_InputPopup_VcpInputPopup_Event>
    // This singal is invoked when Ok/Cancel button on VK is clicked
    VfxSignal2 <
        VfxObject*,     // sender 
        VcpInputPopupButtonEnum           // id
    > m_signalButtonClicked;

// override
protected:
    // <group DOM_InputPopup_VcpInputPopup_Override>
    // On init
    virtual void onInit();

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // On rotate
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // On update
    virtual void onUpdate();

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // On key input
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    // <group DOM_InputPopup_VcpInputPopup_Override>
    // While entering the popup to be active
    virtual void onEnter();

// implenmention
private:
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    // on button clicked
    void onButtonClick(VfxObject* sender, VfxId id);

    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    // on text changed in inputbox
    void onTextChanged(VcpTextEditor *inputbox);

    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    // activate inputbox when enter
    void activateInputbox();
	// <group DOM_InputPopup_VcpInputPopup_Implementation>
	// Sets OK button state. 
	void setOkBtnState();
	// <group DOM_InputPopup_VcpInputPopup_Implementation>
	// Resets the position of popup.
	void resetPosition(VfxS32 popupHeight);

// Variable
protected:
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxU8                           m_groupNum;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxBool                         m_isAllowdEmptyContent;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxFrame                        *m_background;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxFrame                        *m_titleBg;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxWString                      m_title;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxWString                      m_hintText[VCP_INPUT_POPUP_MAX_GROUP_NUM];
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxWString                      m_errorText[VCP_INPUT_POPUP_MAX_GROUP_NUM];
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxTextFrame                    *m_titleFrame;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxTextFrame                    *m_hintTextFrame[VCP_INPUT_POPUP_MAX_GROUP_NUM];
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxTextFrame                    *m_errorTextFrame[VCP_INPUT_POPUP_MAX_GROUP_NUM];
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VcpTextEditor                   *m_inputbox[VCP_INPUT_POPUP_MAX_GROUP_NUM];
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VcpButton                       *m_okButton;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VcpButton                       *m_cancelButton;
    // <group DOM_InputPopup_VcpInputPopup_Implementation>
    VfxPoint                         m_orgImePoint;
	// <group DOM_InputPopup_VcpInputPopup_Implementation>
	VfxS32							m_contentHeight;
};


#endif /* __VCP_INPUT_POPUP_H__ */

