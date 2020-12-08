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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_text_editor.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  editor class header file
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

#ifndef __VCP_TEXT_EDITOR_H__
#define __VCP_TEXT_EDITOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

#include "ime\vsrv_input_manager.h"

#include "vcp_button.h"
#include "clipboard\vsrv_clipboard.h"
#include "vcp_text_view.h"
#include "vcp_image_button.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vcp_text_utils.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"
#include "vcp_text_storage.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_text_frame.h"

extern "C"
{
#include "ImeGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
// <group DOM_TextEditor_Macro&Enum_Macro>
#define VCP_EDITOR_CLASS_NAME             "TextEditor"
#define VCP_EDITOR_COUNTER_POS            VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN

#define VCP_EDITOR_COUNTER_DISP_PERCENTAGE   0.8

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_EDITOR_COUNTER_FONT_SIZE      12
#define VCP_EDITOR_COUNTER_LR_MARGIN       2
#define VCP_EDITOR_COUNTER_TD_MARGIN       1
#define VCP_EDITOR_DELETE_BTN_WIDTH       30
#define VCP_EDITOR_DELETE_BTN_HEIGHT      30
#define VCP_EDITOR_DELETE_BTN_GAP          2
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_EDITOR_COUNTER_FONT_SIZE      20
#define VCP_EDITOR_COUNTER_LR_MARGIN       4
#define VCP_EDITOR_COUNTER_TD_MARGIN       2
#define VCP_EDITOR_DELETE_BTN_WIDTH       60
#define VCP_EDITOR_DELETE_BTN_HEIGHT      60
#define VCP_EDITOR_DELETE_BTN_GAP          2
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_EDITOR_COUNTER_FONT_SIZE      12
#define VCP_EDITOR_COUNTER_LR_MARGIN       2
#define VCP_EDITOR_COUNTER_TD_MARGIN       1
#define VCP_EDITOR_DELETE_BTN_WIDTH       30
#define VCP_EDITOR_DELETE_BTN_HEIGHT      30
#define VCP_EDITOR_DELETE_BTN_GAP          2
#else
#define VCP_EDITOR_COUNTER_FONT_SIZE      12
#define VCP_EDITOR_COUNTER_LR_MARGIN       2
#define VCP_EDITOR_COUNTER_TD_MARGIN       1
#define VCP_EDITOR_DELETE_BTN_WIDTH       30
#define VCP_EDITOR_DELETE_BTN_HEIGHT      30
#define VCP_EDITOR_DELETE_BTN_GAP          2
#endif

/* DOM-NOT_FOR_SDK-BEGIN */

// <group DOM_TextEditor_Struct>
// Text editor history structure
typedef struct 
{
    VfxBool isActive;
    VfxBool isSaved;
    VfxS32 cursorIndex;
    mmi_imc_history imeHistory;
    VfxTextRange selection;
}VcpTextEditorHistoryStruct, *pVcpTextEditorHistoryStruct;

/* DOM-NOT_FOR_SDK-END */

class VcpEditing;
class VcpTextCounter;
class VcpTextCursor;

// <group DOM_TextEditor_VcpTextEditor_Enum>
// the editor buffer encoding type
// Text encoding type Enum
enum VcpTextEncodingEnum
{
    // UCS2 encoding type
    VCP_TEXT_ENCODING_UCS2,

    // GB encoding type
    VCP_TEXT_ENCODING_GB2312,

    // ascii encoding based length
    // if input ASCII char, can input N chars,
    // if input UCS2 char, can only input N/2 chars
    VCP_TEXT_ENCODING_ASCII,

    // gsm char based length
    // if input GSM char, can input N chars,
    // if input UCS2 char, can only input N/2 chars
    // if input GSM extension char, it will +2
    VCP_TEXT_ENCODING_GSM,

    // 0x81 encoding
    VCP_TEXT_ENCODING_0X81,

    /* DOM-NOT_FOR_SDK-BEGIN */
    // TODO: following encoding types is not support currently
    // UTF8 encoding type
    VCP_TEXT_ENCODING_UTF8,
    /* DOM-NOT_FOR_SDK-END */

    // End of enum
    VCP_TEXT_ENCODING_END_OF_ENUM
};


// <group DOM_TextEditor_VcpTextEditor_Enum>
// the editor text change enum
enum VcpTextChangeEnum
{
    // the text to be insert
    VCP_TEXT_CHANGE_INSERT_CHAR,
    // the text to be delete
    VCP_TEXT_CHANGE_DELETE_CHAR,
    // the text to be delete all
    VCP_TEXT_CHANGE_DELETE_ALL,
    // the string to be insert
    VCP_TEXT_CHANGE_INSERT_STR,
    // END of Enum
    VCP_TEXT_CHANGE_END_OF_ENUM
};


// <group DOM_TextEditor_VcpTextEditor_Enum>
// the editor counter display mode enum
enum VcpTextCounterDisplayModeEnum
{
    // auto show counter
    VCP_TEXT_COUNTER_DISP_AUTO,
    // show counter manually
    VCP_TEXT_COUNTER_DISP_MANUAL,
    // always show counter
    VCP_TEXT_COUNTER_DISP_SHOW,
    // always hide
    VCP_TEXT_COUNTER_DISP_HIDE,
    // END of Enum
    VCP_TEXT_COUNTER_DISP_END_OF_ENUM
};


/***************************************************************************** 
 * Class VcpTextEditor
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Text Editor is mainly applied for users to input the information field. 
 *  When users tap the Text Editor, system will enter the input mode or offer the Picker according to the information attribute
 *  VcpTextEditor is a TextView that configures itself as editable. This control will 
 *  connect IME to allow user input text.
 * EXAMPLE
 * <code>
 *  VcpTextEditor *m_textInput;
 *  VFX_OBJ_CREATE(m_textInput, VcpTextEditor , this);
 *  m_textInput->setPos(VfxPoint(INPUT_X, INPUT_Y));
 *  m_textInput->setBounds(VfxRect(0, 0, INPUT_WIDTH, INPUTY_HEIGHT));
 *  m_textInput->setText(text);
 *  m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
 *  m_textInput->setIME(IMM_INPUT_TYPE_PHONE_NUMBER);
 *  m_textInput->setHint(VFX_WSTR("Please tap to input:"));
 * </code>
 */
class VcpTextEditor : public VcpTextView                  
{
    VFX_DECLARE_CLASS(VcpTextEditor);

// Constructor / Destructor
public:
    // <group DOM_TextEditor_VcpTextEditor_Constructor/Destructor>
    VcpTextEditor();

// Signal
public:
    // <group DOM_TextEditor_VcpTextEditor_Event>
    // indicate the text content has been changed
    VfxSignal1 <
        VcpTextEditor *>            // [IN] text editor object
        m_signalTextChanged;
        
    // <group DOM_TextEditor_VcpTextEditor_Event>
    // indicate the text editor is acitvated to input text (VFX_TRUE) or deactivated (VFX_FALSE)
    VfxSignal2 <
        VcpTextEditor *,            // [IN] text editor object
        VfxBool>                    // [IN] text editor is activate or deactivate
        m_signalActivated;

    // <group DOM_TextEditor_VcpTextEditor_Event>
    // indicate that the text to be changed, send before the text change.
    // If App return VFX_FALSE, the char will not be inserted/deleted
    VfxSignal4 <
        VfxWChar *,                 // [IN] text to be input
        VfxS32,                     // [IN] cursor index
        VcpTextChangeEnum,          // [IN] text change type
        VfxBool *>                  // [OUT] can be changed or not
        m_signalBeforeChange;

    // <group DOM_TextEditor_VcpTextEditor_Event>
    // Cursor position change signal
    VfxSignal2 <
        VcpTextEditor *,            // [IN] text editor object
        VfxS32>                     // [IN] cursor index
        m_signalCursorIndexChanged;

    // <group DOM_TextEditor_VcpTextEditor_Event>
    // enter key on VK is clicked
    VfxSignal2 <
        VcpTextEditor *,            // [IN] text editor object
        IMEVKEnterKeyStyleEnum>     // [IN] VK enter key type
        m_signalEnterKeyClicked;

    // <group DOM_TextEditor_VcpTextEditor_Event>
    // send before editor handle key event
    // application can register this signal and return VFX_FALSE to let editor don't process the key
    VfxSignal3 <
        VcpTextEditor*,          // [IN] text editor object
        VfxKeyEvent&,            // [IN] key event
        VfxBool&>                // [IN] return value
        m_signalOnBeforeKeyInput;

// Method
public:
    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set a editable string with a specfic encoding type for counter
    // it will postEmit m_signalTextChanged when text changes
    VfxS32 setText(
        VfxWChar *text,                                       // [IN] text buffer
        VfxS32 maxLen,                                        // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,                      // [IN] need editor malloc buffer for edit
        VcpTextEncodingEnum type = VCP_TEXT_ENCODING_UCS2,    // [IN] the type of character counter
        VcpRichTextFormat *format = NULL                      // [IN] text format object list
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set a editable string with a specfic encoding type for counter
    // it will postEmit m_signalTextChanged when text changes
    VfxS32 setText(
        const VfxWString &text,                               // [IN] text
        VfxS32 maxLen,                                        // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,                      // [IN] need editor malloc buffer for edit
        VcpTextEncodingEnum type = VCP_TEXT_ENCODING_UCS2,    // [IN] the type of character counter
        VcpRichTextFormat *format = NULL                      // [IN] text format object list
        );

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // change text content. Internal used by Converter app
    // it will not postEmit m_signalTextChanged when text changes
    VfxS32 changeText(
        VfxWChar *text,                                       // [IN] text buffer
        VfxS32 maxLen,                                        // [IN] the max text length to be input
        VfxBool isStaticBuf = VFX_FALSE,                      // [IN] need editor malloc buffer for edit
        VcpTextEncodingEnum type = VCP_TEXT_ENCODING_UCS2,    // [IN] the type of character counter
        VcpRichTextFormat *format = NULL                      // [IN] text format object list
        );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set editor max edit length in character count
    void setMaxLength(
        VfxS32 maxLen               // [IN] max text length can be input
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get editor max edit length in character count
    VfxS32 getMaxLength(void) const { return m_storage->getMaxLength(); }

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set IME input type and IME 
    void setIME(
        VfxU64 inputType,                             // [IN] the input type: mmi_imm_input_type_enum
        VfxU32 inputSetting = IME_SETTING_FLAG_NONE   // [IN] ime setting
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set IME input binding
    void setIME(
        const VsrvInputBinding &inputBinding          // [IN] input binding
        );
    
    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Return the plain text content 
    VfxWChar *getText();
        
    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set line mode to Single or Multiline
    void setLineMode(
        VcpTextLineModeEnum mode                    // [IN] line mode
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // hide editor counter or not
    void hideCounter(
        VfxBool isHide                              // [IN] VFX_TRUE for hide, VFX_FALSE for show
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set counter display mode
    void setCounterDisplayMode(
        VcpTextCounterDisplayModeEnum mode          // [IN] counter display mode
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Process key input, used when the application use it own key it insert
    // for example, dialer pad
    VfxBool processKeyInput(
        VfxKeyEvent &event                          // [IN] key event
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set auto activate editor by key input
    void setAutoActivateByKey(VfxBool value);

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Set function bar which is above VK
    void setFunctionBar(
        VfxFrame *frame,                            // [IN] function bar frame
        VfxBool isAutoClose = VFX_TRUE              // [IN] need close by editor or not
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // Get function bar which is above VK
    VfxFrame * getFunctionBar();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // insert text
    VfxU32 insertText(
        VfxWChar *string                            // [IN] inserted string
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // insert text
    VfxU32 insertText(
        VfxWChar wChar                              // [IN] inserted char
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // delete chars with specific range
    VfxU32 deleteChars(
        VfxS32 start,                               // [IN] delete start position
        VfxS32 end                                  // [IN] delete end position
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // delete chars before cursor position
    VfxU32 deleteChars();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // delete all text in editor
    void deleteAll(void);

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get char before cursor position
    VfxWChar getCharBeforeCursor();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get the n char before cursor position
    VfxWChar getCharBeforeCursor(
        VfxS32 n                                    // [IN] the nTh character
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get char after cursor position
    VfxWChar getCharAfterCursor();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get the n char after cursor position
    VfxWChar getCharAfterCursor(
        VfxS32 n                                    // [IN] the nTh character
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // backward cursor for one position 
    VfxS32 previous();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // backward cursor for the steps position
    VfxS32 previous(
        VfxS32 steps                                // [IN] previous steps
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // forward cursor for one position
    VfxS32 next();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // forward cursor for the steps position
    VfxS32 next(
        VfxS32 steps                                // [IN] next steps
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // upward the cursor line
    VfxS32 previousLine();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // downward the cursor line
    VfxS32 nextLine();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // move cursor to specific index
    void setCursorIndex(
        VfxS32 index                                // [IN] new cursor index
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get cursor index
    VfxS32 getCursorIndex(void) const;

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // enable delete button, only for singleline
    void setDeleteButton(
        VfxBool value                               // [IN] enable delete button or not
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // enable Enter key on VK or not
    void setEnterKeyEnabled(
        VfxBool value                               // [IN] enable enter key on VK or not
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set Enter key style
    void setEnterKeyStyle(
        IMEVKEnterKeyStyleEnum style                // [IN] enter key stype
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set the editor is deactivated automatically when pen down in other controls
    void setAutoDeactivated(
        VfxBool isAutoDeactivated                   // [IN] auto deactivate or not
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set the editor is activated automatically when create the text editor
    // default the cursor will be at last position of text when activate, you can set cursor index by cursorIndex
    void setAutoActivated(
        VfxBool isAutoActivated,                    // [IN] auto activate or not
        VfxS32 cursorIndex = -1                     // [INI] cursor index
        );

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get history, only used for Baidu search widget
    // backward compatible for pluto design
    void getHistory(
        VcpTextEditorHistoryStruct *history         // [OUT] text editor history 
        );

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set history, only used for Baidu search widget
    // backward compatible for pluto design
    void setHistory(
        VcpTextEditorHistoryStruct *history         // [IN] text editor history
        );

    /* DOM-NOT_FOR_SDK-END */

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // show soft input (VK)
    void showSoftInput();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // hide soft input (VK)
    void hideSoftInput();

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set autocap to off temprarily
    void disableAutoCap();

    /* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set is hide cursor or not
    void setIsHideCursor(VfxBool value);

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set is deactivate editor (content must be empty) when hide VK
    void setIsDeactivateWhenHideVK(VfxBool value) { m_isDeactivateWhenHideVK = value; }

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // direct input string from test module
    static VfxU32 directInput(VfxU8 index, VfxWChar *p);

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // get current active editor instance
    static VcpTextEditor *getCurrentActivateEditor(){ return s_activateEditor; }

    // <group DOM_TextEditor_VcpTextEditor_Method>
    // set current active editor instance
    static void setCurrentActivateEditor(VcpTextEditor *editor) { s_activateEditor = editor; }

    /* DOM-NOT_FOR_SDK-END */

// Override
public:
    // <group DOM_TextEditor_VcpTextEditor_Override>
    // set bounds
    virtual void setBounds(
        const VfxRect &value            // [IN] bounds value
        );

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // Activate editor to input text
    virtual void activate(
        VfxBool isSetFocus = VFX_TRUE   // [IN] unused any more
        );

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // Exit text input state
    virtual void deactivate(
        VfxBool isSetFocus = VFX_TRUE   // [IN] unused any more
        );

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // Disable editor, if disable, the editor will be unhittable which is can't receive the pen event.
    // also, the text will be grey when disabled
    virtual void setIsDisabled(
        VfxBool isDisabled              // [IN] is disabled
    );

// Override
protected:
    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on init
    virtual void onInit();

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on deinit
    virtual void onDeinit();   

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on key input
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on key input
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on serialize
    virtual VfxBool onSerialize(VfxArchive &ar);

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on restore
    virtual void onRestore(VfxArchive &ar);

    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on object notify
    virtual void onObjectNotify(VfxId eventId, void *userData);

// Implementation
private:

    struct counterFPEData
    {
        VfxObjHandle viewObjHandle;
        VfxObjHandle editorObjHandle;
    };

// Implementation
private:
    // <group DOM_TextEditor_VcpTextEditor_Override>
    // on focus changed
    void onFocusChanged(VfxBool focused);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // get history
    void getHistory();

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // set history
    void setHistory();

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on text changed happened
    void onTextChanged(VcpTextView *view);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on text editor activated
    void onActived(VcpTextView *editor, VfxBool active);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on before text changes
    void onBeforeTextChange(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on cursor index changed
    void onCursorIndexChanged(VcpTextCursor *cursor);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on enter key clicked
    void onEnterKeyClicked(VcpTextView *editor, IMEVKEnterKeyStyleEnum style);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // check if it is editabled
    virtual VfxBool editable() const { 
        return VFX_TRUE;
    }

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on delete button clicked
    void onDeleteButtonClick(VfxObject *obj, VfxId id);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on pen event processed
    void onPenEventProcessed(VfxPenEvent &event, VfxControl *control);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on rotated
    void onRotated(VfxScreenRotateParam rotateParam);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on rotated to
    void onRotateTo(VfxScreenRotateParam rotateParam);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // activate internal function
    void activateInternal(VfxBool isSetFocus = VFX_TRUE);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // deactivate internal function
    void deactivateInternal(VfxBool isSetFocus = VFX_TRUE);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // FPE callback for interset mode
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // update counter display mode
    void updateCounter(VfxS32 maxLen);

#if VCP_TEXT_CLIPBOARD_SUPPORT
    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // on clipboard event
    void onClipboardEvent(VfxCcpEventType type, VfxWChar** string, VfxS32 len, VfxS32 *ret_len);
#endif

private:
    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VcpTextCounter *m_counter;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VcpImageButton *m_deleteButton;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VfxBool m_enableDeleteButton;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VfxBool m_autoDeactivated;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VfxBool m_autoActivated;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VfxBool m_autoCloseFunctionBar;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    VfxBool m_freezActiveState;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // used for when setText should not postEmit the signal m_signalTextChanged
    VfxBool m_isTextReady; 

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // save editor history when editor deactivated
    VcpTextEditorHistoryStruct *m_history;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // save IME history when editor deactivated
    void *m_imeHistory;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // editor counter display mode, default is auto display
    VcpTextCounterDisplayModeEnum m_counterDispMode;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    static VcpTextEditor *s_activateEditor;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // is hide cursor or not
    VfxBool m_isHideCursor;

    // <group DOM_TextEditor_VcpTextEditor_Implementation>
    // is deactivate empty editor when hide VK
    VfxBool m_isDeactivateWhenHideVK;

	// <group DOM_TextEditor_VcpTextEditor_Implementation>
    // is showing IME popup
	VfxBool m_isShowIMEPopup;

protected:
    friend class VcpEditing;
    friend class VcpTextCursor;
};


/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * Class VfxEditing
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpEditing is used to attached to a TextView to make it connected to IME, which make
 *  the view editable.
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpEditing : public VfxObject,
                   public InputConnection
{
// Constructor / Destructor
public:
    // <group DOM_TextEditor_VcpEditing_Constructor/Destructor>
    VcpEditing();

// Method
public:
    // <group DOM_TextEditor_VcpEditing_Method>
    // attach this Editing to a TextView
    void attachTo(
        VcpTextView *textView       // the instance of textview to be attached with this Editing
    );

    // <group DOM_TextEditor_VcpEditing_Method>
    // Set IME input type and IME 
    void setIME(
        VfxU64 inputType,             // [IN] the input type
        VfxU32 inputSetting = IME_SETTING_FLAG_NONE   // [IN] ime setting
        );

    // <group DOM_TextEditor_VcpEditing_Method>
    // Set IME input binding
    void setIME(
        const VsrvInputBinding &inputBinding // [IN] input binding
        );

    // <group DOM_TextEditor_VcpEditing_Method>
    // Make cursor visible
    void scrollViewForCursor();

    // <group DOM_TextEditor_VcpEditing_Method>
    // Locate the cursor the position point
    void locateCursorTo(const VfxPoint &point);
    
    // <group DOM_TextEditor_VcpEditing_Method>
    // Set function bar which is above VK
    void setFunctionBar(VfxFrame *frame);

    // <group DOM_TextEditor_VcpEditing_Method>
    // Get function bar which is above VK
    VfxFrame * getFunctionBar();

    // <group DOM_TextEditor_VcpEditing_Method>
    // test input, check if the string can be insert or not
    VfxU32 testInput(VfxWChar *text);

    // <group DOM_TextEditor_VcpEditing_Method>
    // test input, check if the string can be insert or not
    VfxU32 testInput(VfxWChar ch);
    
// Signal
public:
    // <group DOM_TextEditor_VcpEditing_Event>
    // indicate the text content has been changed
    VfxSignal1 <VcpTextView *> m_signalTextChanged;
        
    // <group DOM_TextEditor_VcpEditing_Event>
    // indicate the activate state
    VfxSignal2 <VcpTextView *, VfxBool> m_signalActivated;

    // <group DOM_TextEditor_VcpEditing_Event>
    // indicate that the text to be changed, send before the text change.
    // If App return VFX_FALSE, the char will not be inserted/deleted
    VfxSignal4 <VfxWChar *, VfxS32, VcpTextChangeEnum, VfxBool *> m_signalBeforeChange;

    // <group DOM_TextEditor_VcpEditing_Event>
    // enter key on VK is clicked
    VfxSignal2 <VcpTextView *, IMEVKEnterKeyStyleEnum> m_signalEnterKeyClicked;
    
// Override   
public:
    // <group DOM_TextEditor_VcpEditing_Override>
    //  begin batch edit mode
    virtual VfxBool beginBatchEdit();

    // <group DOM_TextEditor_VcpEditing_Override>
    // end batch edit mode
    virtual VfxBool endBatchEdit();

    // <group DOM_TextEditor_VcpEditing_Override>
    // insert text
    virtual VfxU32 insertText(VfxWChar *string, VfxS32 newCursorPos, VfxS32 index = -1);

    // <group DOM_TextEditor_VcpEditing_Override>
    // insert text
    virtual VfxU32 insertText(VfxWChar wChar, VfxS32 newCursorPos, VfxS32 index = -1);

    // <group DOM_TextEditor_VcpEditing_Override>
    // set marked text for IME
    virtual VfxU32 setMarkedText(
        VfxWChar *string, 
        VfxS32 selRangeStart, 
        VfxS32 selRangeEnd, 
        VfxS32 newCursorPos);

    // <group DOM_TextEditor_VcpEditing_Override>
    // finish marked text
    virtual void finishMarkedText();

    // <group DOM_TextEditor_VcpEditing_Override>
    // send key event
    virtual void sendKeyEvent(
        VfxKeyEventTypeEnum type,           // Key type
        VfxKeyCodeEnum      keyCode,        // Key code
        VfxWChar            ucs2,           // UCS2
        VfxU32              specialKeyFlag, // Key special flag, see VFX_SPECIAL_KEY_FLAG_XXXX.
        VfxMsec             timeStamp       // Time stemp of the key input event
        );

    // <group DOM_TextEditor_VcpEditing_Override>
    // clear editor content
    virtual void clear();

    // <group DOM_TextEditor_VcpEditing_Override>
    // delete chars
    virtual VfxU32 deleteChars(VfxS32 start, VfxS32 end);

    // <group DOM_TextEditor_VcpEditing_Override>
    // delete chars
    virtual VfxU32 deleteChars();

    // <group DOM_TextEditor_VcpEditing_Override>
    // delete char at cursor position
    virtual VfxU32 deleteAtCursor(VfxS32 leftLength, VfxS32 rightLength);

    // <group DOM_TextEditor_VcpEditing_Override>
    // get text length in editor
    virtual VfxS32 length() const;

    // <group DOM_TextEditor_VcpEditing_Override>
    // get max allowed length in editor
    virtual VfxS32 maxLength() const;

    // <group DOM_TextEditor_VcpEditing_Override>
    // get char before cursor position
    virtual VfxWChar getCharBeforeCursor(
        VfxS32 index, 
        VfxS32 moveType, 
        VfxS32 *charType);

    // <group DOM_TextEditor_VcpEditing_Override>
    // get char after cursor position
    virtual VfxWChar getCharAfterCursor(
        VfxS32 index, 
        VfxS32 moveType, 
        VfxS32 *charType);

    // <group DOM_TextEditor_VcpEditing_Override>
    // set selection range
    virtual VfxS32 setSelection(VfxS32 start, VfxS32 end); 

    // <group DOM_TextEditor_VcpEditing_Override>
    // get selection range
    virtual void getSelection(VfxS32 *start, VfxS32 *end);

    // <group DOM_TextEditor_VcpEditing_Override>
    // get text buffer
    virtual VfxWChar* getText();

    // <group DOM_TextEditor_VcpEditing_Override>
    // set IME UI layout
    virtual void setIMEUILayout(
        VfxS32 x,       // The x coordinate of IME UI rectangle
        VfxS32 y,       // The y coordinate of IME UI rectangle
        VfxS32 width,   // The width of IME UI rectangle
        VfxS32 height,  // The height of IME UI rectangle
        VfxS32 vkX,       // The x coordinate of VK rectangle
        VfxS32 vkY,       // The y coordinate of VK  rectangle
        VfxS32 vkWidth,   // The width of VK  rectangle
        VfxS32 vkHeight,   // The height of VK  rectangle
        VfxBool isAnim);

    // <group DOM_TextEditor_VcpEditing_Override>
    // get cursor instance
    virtual VcpTextCursor* getCursor();

    // <group DOM_TextEditor_VcpEditing_Override>
    // get cursor index
    virtual VfxS32 getCursorIndex(VfxBool isSkipIcon = VFX_FALSE);

    // <group DOM_TextEditor_VcpEditing_Override>
    // get cursor rect
    virtual VfxBool getCursorRect(
        VfxS32 *x,       // The x coordinate of cursor, should be related to the whole screen
        VfxS32 *y,       // The y coordinate of cursor, should be related to the whole screen
        VfxS32 *width,   // The width of cursor
        VfxS32 *height   // The height of cursor
        );

    // <group DOM_TextEditor_VcpEditing_Override>
    // send ime notification
    virtual VfxBool sendIMENotification(InputNotificationEnum notificationID, void *data);

    // <group DOM_TextEditor_VcpEditing_Override>
    // Active IME input
    virtual void activate();

    // <group DOM_TextEditor_VcpEditing_Override>
    // Make this view exit the input mode.
    virtual void deactivate();

    // <group DOM_TextEditor_VcpEditing_Override>
    // move cursor by line
    virtual VfxS32 moveCursorByLine(VfxS32 steps);

    // <group DOM_TextEditor_VcpEditing_Override>
    // move cursor by char
    virtual VfxS32 moveCursorByChar(VfxS32 steps);
    
// Implement
public:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // clear selection range
    VfxBool clearSelectionRange();

// Implement
private:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // when text changed happend
    void onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed);

    // <group DOM_TextEditor_VcpEditing_Implementation>
    void configFunctionBar(VfxBool isEditorActive = VFX_TRUE);

private:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // text view instance
    VcpTextView *m_view;

    // <group DOM_TextEditor_VcpEditing_Implementation>
    // Inputbinding instance
    VsrvInputBinding m_inputBinding;

    // <group DOM_TextEditor_VcpEditing_Implementation>
    // VsrvInputManager instance
    VsrvInputManager* m_inputManager;

    // <group DOM_TextEditor_VcpEditing_Implementation>
    // input type
    VcpTextCursor *m_cursor;

    // <group DOM_TextEditor_VcpEditing_Implementation>
    // if modified or not
    VfxBool m_isModify;

public:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // indicate batch edit start
    VfxS32 m_batchEdit;

private:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // weak pointer to function bar 
    VfxFrameWeakPtr m_functionBarPtr;

    // <group DOM_TextEditor_VcpEditing_Implementation>
    // Timeline for hiding function bar
    VfxPointTimeline *m_hideFunctionBarTimeline;
	
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // Timeline for hiding function bar
    VfxPointTimeline *m_showFunctionBarTimeline;

private:
    // <group DOM_TextEditor_VcpEditing_Implementation>
    // on hide function bar time line stopped
    void onHideFunctionBarTimelineStoppped(VfxBaseTimeline *timeline, VfxBool isCompleted);

// Implement
protected:
    friend class VcpTextEditor;
    friend class VcpTextView;
    friend class VcpTextScrollView;
    friend class VcpTextCursor;
};


/***************************************************************************** 
 * Class VcpTextCursor
 *****************************************************************************/

/*
 * DESCRIPTION
 *  TextView Cursor information 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpTextCursor : public VfxFrame
{
    VFX_DECLARE_CLASS(VcpTextCursor);
    
// Constructor / Destructor
public:
     // <group DOM_TextEditor_VcpTextCursor_Constructor/Destructor>
     VcpTextCursor();
     
// Enum
public:
    // <group DOM_TextEditor_VcpTextCursor_Enum>
    // Enum for cursor movement type
    enum CursorMoveType
    {
        LOGIC_MOVE,
        VISUAL_MOVE,
        MOVE_END_OF_ENUM
    };
    
// Signal    
public:
    // <group DOM_TextEditor_VcpTextCursor_Event>
    // Cursor position change signal
    VfxSignal1 <VcpTextCursor *> m_signalCursorIndexChanged;
    
// Method    
public:
    // <group DOM_TextEditor_VcpTextCursor_Method>
    // set visible or not
    void setVisible(VfxBool visible);

    // <group DOM_TextEditor_VcpTextCursor_Method>
    // get the current actived cursor
    static VcpTextCursor* getActiveInstance(){ return s_activeCursor; }

    // <group DOM_TextEditor_VcpTextCursor_Method>
    // set editing for this cursor
    void setEditing(VcpEditing *editing){ 
        m_editing = editing; 
    }

    // <group DOM_TextEditor_VcpTextCursor_Method>
    // set cursor move start x position
    void setMoveStartX(VfxS32 value){ 
        m_moveStartX = value; 
    }

    // <group DOM_TextEditor_VcpTextCursor_Method>
    // update view (Editor) position for cursor
    // it will scroll editor pos to make cursor appear if editor is put in another scrollable (List/Form)
    void updateViewForCursor();

    /* DOM-NOT_FOR_SDK-BEGIN */
    // <group DOM_TextEditor_VcpTextCursor_Override>
    // frame property effect callback
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
    /* DOM-NOT_FOR_SDK-END */
// Override    
public:
    // <group DOM_TextEditor_VcpTextCursor_Override>
    // on init
    virtual void onInit();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // on deinit
    virtual void onDeinit();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // set the cursor position
    virtual void setIndex(VfxS32 index, VfxPoint * newPos = NULL, VfxBool needSetPos = VFX_TRUE);

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // get the cursor position
    virtual VfxS32 getIndex() const { return m_logicIndex; }

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // set the cursor movement type
    virtual void setMoveType(VfxS32 type) { m_moveType = type; }

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // direct display or hide cursor 
    virtual void directDraw(VfxBool show);

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // backward cursor for one position 
    virtual VfxS32 previous();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // backward cursor for the steps position
    virtual VfxS32 previous(VfxS32 steps);

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // forward cursor for one position
    virtual VfxS32 next();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // forward cursor for the steps position
    virtual VfxS32 next(VfxS32 steps);

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // upward the cursor line
    virtual VfxS32 previousLine();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // downward the cursor line
    virtual VfxS32 nextLine();

// Override
protected:
    // <group DOM_TextEditor_VcpTextCursor_Override>
    // flash cursor or not
    virtual VfxBool flash(){ return VFX_TRUE; }

// Implementation    
private:
    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // handle blink effect
    void onBlink(VfxTimer *timer);
 
// Variable        
private:    
    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // blink timer
    VfxTimer *m_blinkTimer;
    
    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // the activated cursor instance
    static VcpTextCursor *s_activeCursor;

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // cursor movement type
    // VCP_TEXTVIEW_CURSOR_LOGIC_MOVE or VCP_TEXTVIEW_CURSOR_VISUAL_MOVE
    VfxS32 m_moveType;

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // cursor logic index
    VfxS32 m_logicIndex;

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    VfxS32 m_moveStartX;

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    VcpEditing * m_editing;

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    VfxBool m_isHidden;
};


/***************************************************************************** 
 * Class VcpTextCounter
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Display the remaining counter
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpTextCounter : public VfxTextFrame
{
    
// Constructor / Destructor
public:
    // <group DOM_TextEditor_VcpTextCounter_Constructor/Destructor>
    VcpTextCounter();
    
// Method    
public:
    // <group DOM_TextEditor_VcpTextCounter__Method>
    // set the counter owner
    void setOwner(VcpTextView *view);

    // <group DOM_TextEditor_VcpTextCounter__Method>
    // update counter
    void updateCounter();
    
// Override    
public:
    // <group DOM_TextEditor_VcpTextCursor_Override>
    // on init
    virtual void onInit();

    // <group DOM_TextEditor_VcpTextCursor_Override>
    // check if the point in the its rect
    virtual VfxBool onContainPoint(
        const VfxPoint &point       // [IN] the point in the coordinate of the frame
    ) const;

// Implementation
private:
    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // on text changed
    void onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed);   

    // <group DOM_TextEditor_VcpTextCursor_Implementation>
    // on parent bounds changed
    void onParentBoundsChanged(VfxFrame *frame, const VfxRect &rect);

};

/* DOM-NOT_FOR_SDK-END */

#endif /* __VCP_TEXT_EDITOR_H__ */
