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
 *  vsrv_input_method_interface.h
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input method interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VSRV_INPUT_METHOD_INTERFACE_H__
#define __VSRV_INPUT_METHOD_INTERFACE_H__

extern "C"
{
	#include "ImeGprotEnums.h"
}   

#include "Vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vfx_control.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
#define    VSRV_INPUT_MANAGER_MAX_DISABLED_EVENT_NUM    (10)
#define    VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM     (10)
#define    VSRV_INPUT_MANAGER_MAX_USER_SPECIAL_MODE_NUM    (20)

#define    VFX_TOP_LEVEL_Z_IME_UI   6000 // Should be bigger than VFX_TOP_LEVEL_Z_POPUP and smaller than VFX_TOP_LEVEL_Z_INPUT_POPUP

// NOTE: Must add the new enum IDs to the end, can't change the values
//       of original enum IDs
typedef enum
{
    IME_INPUT_EVENT_NONE,
    IME_INPUT_EVENT_HIDE,
    IME_INPUT_EVENT_SHOW,
    IME_INPUT_EVENT_CAPSLOCK,
    IME_INPUT_EVENT_SPACE,
    IME_INPUT_EVENT_BAKSPACE,
    IME_INPUT_EVENT_SYMBPICKER,
    IME_INPUT_EVENT_BRACKET,
    IME_INPUT_EVENT_NEWLINE,
    IME_INPUT_EVENT_EUROSYMB,
    IME_INPUT_EVENT_DISPLAY_CALLBACK,
    IME_INPUT_EVENT_MAX
}IMEInputEventEnum;


// NOTE: Must add the new enum IDs to the end, can't change the values
//       of original enum IDs
typedef enum
{
    IME_SETTING_FLAG_NONE = 0,
    IME_DISABLE_KEY_INPUT = 0x0001,
    IME_DISABLE_HANDWRITING = 0x0002,
    IME_ALLOWED_CHARACTER_LIST = 0x0004,
    IME_DISABLED_CHARACTER_LIST = 0x0008,
    IME_ALLOWED_EVENT_LIST = 0x0010,
    IME_DISABLED_EVENT_LIST = 0x0020,
    IME_DISABLE_NEW_LINE_SYMBOL = 0x0040,
    IME_VK_DEFAULT_ENLARGED = 0x0080,
    IME_DISABLE_VK = 0x0100,
    IME_PLUS_CHAR_HANDLING =  0x0200,
    IME_JAVA_SPECIAL_SYMBOL =  0x0400,
    IME_SKIP_DECIMAL_CHECK = 0x0800,
    IME_DISABLE_CANDIDATE_BOX = 0X1000,
    IME_DISABLE_SETTING_ENTRY_BUTTON = 0x2000,
    IME_SETTING_FLAG_MAX
}InputSettingEnum;


// NOTE: Must add the new enum IDs to the end, can't change the values
//       of original enum IDs
typedef enum
{
    IME_INPUT_STYLE_NONE = 0,
    IME_INPUT_STYLE_WCSS = 0x0001,
    IME_INPUT_STYLE_NO_SOFTKEYS = 0x0002,
    IME_INPUT_STYLE_MAX
}InputStyleEnum;


// NOTE: Must add the new enum IDs to the end, can't change the values
//       of original enum IDs
typedef enum
{
    IME_NOTIFICATION_NONE = 0,
    IME_NOTIFICATION_INPUT_MODE_CHANGED,
    IME_NOTIFICATION_BACK_TO_INITIAL_STATE,
    IME_NOTIFICATION_IF_DEACTIVATE_BY_PEN_INTERRUPT,
    IME_NOTIFICATION_DEACTIVATED_BY_INTERRUPT,
    IME_NOTIFICATION_PEN_DOWN_IN_IMUI_CONTROL,
    IME_NOTIFICATION_QUERY_CLIENT_SSP_STATE,
    IME_NOTIFICATION_ACTIVATE_EDITOR,
    IME_NOTIFICATION_DEACTIVATE_EDITOR,
    IME_NOTIFICATION_SPECIAL_VK_ENTER_KEY_CLICKED,
    IME_NOTIFICATION_FREEZ_ACTIVE_STATE,
    IME_NOTIFICATION_SHOW_IME_POPUP,
    IME_NOTIFICATION_IS_CLIPBOARD_STATE,
    IME_NOTIFICATION_CLOSE_IME_POPUP,
    IME_NOTIFICATION_MAX
}InputNotificationEnum;


// NOTE: Must add the new enum IDs to the end, can't change the values
//       of original enum IDs
typedef enum
{
    IME_VK_ENTER_KEY_STYLE_ENTER = 0,
    IME_VK_ENTER_KEY_STYLE_SEARCH,
    IME_VK_ENTER_KEY_STYLE_DONE,
    IME_VK_ENTER_KEY_STYLE_MAX
}IMEVKEnterKeyStyleEnum;


//#ifdef __MRE_SDK__

typedef enum _ImeServiceInputConnectionProxyMsgIDEnum
{
    IME_SRV_INPUT_CON_MSG_NONE,
    IME_SRV_INPUT_CON_MSG_BEGIN_BATCH_EDIT,
    IME_SRV_INPUT_CON_MSG_END_BATCH_EDIT,
    IME_SRV_INPUT_CON_MSG_INSERT_STRING,
    IME_SRV_INPUT_CON_MSG_INSERT_CHAR,
    IME_SRV_INPUT_CON_MSG_SET_MARKED_TEXT,
    IME_SRV_INPUT_CON_MSG_FINISH_MARKED_TEXT,
    IME_SRV_INPUT_CON_MSG_SEND_KEY_EVENT,
    IME_SRV_INPUT_CON_MSG_CLEAR,
    IME_SRV_INPUT_CON_MSG_DELETE_CHARS,
    IME_SRV_INPUT_CON_MSG_DELETE,
    IME_SRV_INPUT_CON_MSG_DELETE_AT_CURSOR,
    IME_SRV_INPUT_CON_MSG_GET_LENGTH,
    IME_SRV_INPUT_CON_MSG_GET_MAX_LENGTH,
    IME_SRV_INPUT_CON_MSG_GET_CHAR_BEFORE_CURSOR,
    IME_SRV_INPUT_CON_MSG_GET_CHAR_AFTER_CURSOR,
    IME_SRV_INPUT_CON_MSG_SET_SELECTION,
    IME_SRV_INPUT_CON_MSG_GET_SELECTION,
    IME_SRV_INPUT_CON_MSG_GET_TEXT,
    IME_SRV_INPUT_CON_MSG_SET_IME_LAYOUT,
    IME_SRV_INPUT_CON_MSG_GET_CURSOR_INDEX,
    IME_SRV_INPUT_CON_MSG_GET_CURSOR_RECT,
    IME_SRV_INPUT_CON_MSG_SEND_IME_NOTIFICATION,
    IME_SRV_INPUT_CON_MSG_MOVE_CURSOR_BY_LINE,
    IME_SRV_INPUT_CON_MSG_MOVE_CURSOR_BY_CHAR,
    IME_SRV_INPUT_CON_MSG_MAX
}ImeServiceInputConnectionProxyMsgIDEnum;

typedef VfxU32 (*InputConnectionProxyMsgProc)(ImeServiceInputConnectionProxyMsgIDEnum msgID, VfxU32 *args, VfxU32 argSize);

//#endif /* #ifdef __MRE_SDK__ */

/***************************************************************************** 
 * Classes
 *****************************************************************************/

//class VfxControl;
//class VadpInputServer;
//class VfxTextRange;
//class VcpTextCursor;

/*
 * DESCRIPTION
 *  Interface for communication channel from an InputMethod back to the textview that is 
 *  receiving its input 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class InputConnection
{
public:
    /*
     * Virtual functions
     */

    // Tell the editor that you are starting a batch of editor operations
    virtual VfxBool beginBatchEdit() = 0;
    // Tell the editor that you are done with a batch edit previously initiated with 
    // beginBatchEdit() 
    virtual VfxBool endBatchEdit() = 0;

    // Insert the given string at the current cursor position
    // If newCursorPos>=0, set the cursor to this new position
    // index is the insert position, in default, the insert position is cursor position
    virtual VfxU32 insertText(VfxWChar *string, VfxS32 newCursorPos, VfxS32 index = -1) = 0;
    virtual VfxU32 insertText(VfxWChar wChar, VfxS32 newCursorPos, VfxS32 index = -1) = 0;

    // Replace the current marked text with string and set selection range, computed 
    // from the beginning of the marked text. If there is no marked text, the current
    // selection text is replaced. If there is no selection text, insert marked
    // string at the current cursor position.
    virtual VfxU32 setMarkedText(
        VfxWChar *string, 
        VfxS32 selRangeStart, 
        VfxS32 selRangeEnd, 
        VfxS32 newCursorPos) = 0;

    // Have the current marked text finish
    virtual void finishMarkedText() = 0;

    // sendKeyEvent
    virtual void sendKeyEvent(
        VfxKeyEventTypeEnum type,           // Key type
        VfxKeyCodeEnum      keyCode,        // Key code
        VfxWChar            ucs2,           // UCS2
        VfxU32              specialKeyFlag, // Key special flag, see VFX_SPECIAL_KEY_FLAG_XXXX.
        VfxMsec             timeStamp       // Time stemp of the key input event
        ) = 0;

    // Clear all the content
    virtual void clear() = 0;

    // delete text from start offset to end offset.
    virtual VfxU32 deleteChars(VfxS32 start, VfxS32 end) = 0;

    // If there is selection text, delete all the selection. Otherwise, delete 
    // a character(or cluster).
    virtual VfxU32 deleteChars() = 0;

    // Delete leftLength characters of text before the current cursor position, and 
    // delete rightLength characters of text after the current cursor position
    virtual VfxU32 deleteAtCursor(VfxS32 leftLength, VfxS32 rightLength) = 0;

    // Returns the length, in characters, of the text managed by this Textview, 
    // not include the '/0' terminal character.
    virtual VfxS32 length() const = 0;

    // Returns the max length of the editor.
    virtual VfxS32 maxLength() const = 0;

    // Returns the character before the index count of cursor.
    virtual VfxWChar getCharBeforeCursor(
        VfxS32 index, 
        VfxS32 moveType, 
        VfxS32 *charType) = 0;

    // Returns the character after the index count of cursor.
    virtual VfxWChar getCharAfterCursor(
        VfxS32 index, 
        VfxS32 moveType, 
        VfxS32 *charType) = 0;

    virtual VfxS32 setSelection(VfxS32 start, VfxS32 end) = 0;

    // Get the selection 
    virtual void getSelection(VfxS32 *start, VfxS32 *end) = 0;
    
    virtual VfxWChar* getText() = 0;

    virtual void setIMEUILayout(
        VfxS32 x,       // The x coordinate of IME UI rectangle
        VfxS32 y,       // The y coordinate of IME UI rectangle
        VfxS32 width,   // The width of IME UI rectangle
        VfxS32 height,   // The height of IME UI rectangle
        VfxS32 vkX,       // The x coordinate of VK rectangle
        VfxS32 vkY,       // The y coordinate of VK  rectangle
        VfxS32 vkWidth,   // The width of VK  rectangle
        VfxS32 vkHeight,   // The height of VK  rectangle
        VfxBool isAnim) = 0;

    virtual VfxS32 getCursorIndex(VfxBool isSkipIcon = VFX_FALSE) = 0;

    virtual VfxBool getCursorRect(
        VfxS32 *x,       // The x coordinate of cursor, should be related to the whole screen
        VfxS32 *y,       // The y coordinate of cursor, should be related to the whole screen
        VfxS32 *width,   // The width of cursor
        VfxS32 *height   // The height of cursor
        ) = 0;

    virtual VfxS32 moveCursorByLine(VfxS32 steps) = 0;

    virtual VfxS32 moveCursorByChar(VfxS32 steps) = 0;
    
    virtual VfxBool sendIMENotification(InputNotificationEnum notificationID, void *data) = 0;
};


/*
 * Input binding Class
 */

class VsrvInputBinding : public VfxBase
{
    
//Constructor / Destructor
public:
    
    VsrvInputBinding();

    VsrvInputBinding(VfxU64 inputType, 
                     VfxU32 settingFlags, 
                     VfxU32 styleFlags, 
                     InputConnection *conn
                    ); // Constructor from a input connection
    
    // Copy constructor
    VsrvInputBinding(const VsrvInputBinding &other) {initWith(other);}
    
//Method
public:

    VsrvInputBinding &operator =(const VsrvInputBinding &other);

    InputConnection *getConnection() { return m_inputConnectionPtr; }

    void setAllowedChars(VfxWString string) 
    {
        m_allowedChars = string;

        if (!m_allowedChars.isNull() && !m_allowedChars.isEmpty())
        {
            m_inputSettingFlags |= IME_ALLOWED_CHARACTER_LIST;
        }
    }
    
    void setDisabledChars(VfxWString string) 
    {
        m_disabledChars = string;
        
        if (!m_disabledChars.isNull() && !m_disabledChars.isEmpty())
        {
            m_inputSettingFlags |= IME_DISABLED_CHARACTER_LIST;
        }
    }
    
    void setAllowedEvents(IMEInputEventEnum *events);
    
    void setDisabledEvents(IMEInputEventEnum *events);
    
    void setUserSpecialInputModeList(mmi_imm_input_mode_enum *list);

    void setVKEnterKeyStyle(IMEVKEnterKeyStyleEnum style)
    {
        m_vkEnterKeyStyle = style;
    }

    void setVKEnterKeyEnabled(VfxBool isEnabled)
    {
        m_isVKEnterKeyEnabled = isEnabled;
    }

    VfxWString &getAllowedChars() {return m_allowedChars;}

    VfxWString &getDisabledChars() {return m_disabledChars;}

    IMEInputEventEnum *getAllowedEvents() {return &m_allowedEvents[0];}

    IMEInputEventEnum *getDisabledEvents() {return &m_disabledEvents[0];}

    mmi_imm_input_mode_enum *getUserSpecialInputModeList() {return &m_userSpecialInputModeList[0];}

    IMEVKEnterKeyStyleEnum getVKEnterKeyStyle() {return m_vkEnterKeyStyle;}

    
    void setOwner(VfxObject* owner)
    {
        m_owner = owner;
    }

    VfxObject* getOwner()
    {
        return m_owner;
    }


    
public:

    VfxU64 m_inputType;

    VfxU32 m_inputSettingFlags;

    VfxU32 m_inputStyleFlags;

    InputConnection *m_inputConnectionPtr;

    IMEVKEnterKeyStyleEnum m_vkEnterKeyStyle;

    VfxBool m_isVKEnterKeyEnabled;

	mmi_imm_input_mode_enum m_appDesiredFirstInputMode;

private:
   VfxObject* m_owner;
    VfxWString m_allowedChars;
    
    VfxWString m_disabledChars;

    IMEInputEventEnum m_allowedEvents[VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM];

    IMEInputEventEnum m_disabledEvents[VSRV_INPUT_MANAGER_MAX_DISABLED_EVENT_NUM];

    mmi_imm_input_mode_enum m_userSpecialInputModeList[VSRV_INPUT_MANAGER_MAX_USER_SPECIAL_MODE_NUM];

private:

    void initWith(const VsrvInputBinding &other);
};

inline
VsrvInputBinding &VsrvInputBinding::operator =(const VsrvInputBinding &other)
{
    initWith(other);
    return *this;
}

/*
 * Input method class, pure interface
 */

class VsrvInputMethodInterface
{

//Method
public:
    
    virtual VfxBool bindInput(VsrvInputBinding *binding) = 0; //Bind a input binding to input manager

    virtual VfxBool unbindInput(VsrvInputBinding *binding) = 0; //Unbind a text view from input manager

    virtual VsrvInputBinding *getBinding() = 0; //Get input binding pointer 
    
    virtual VfxBool activateInput() = 0; // This method is called when the text view starts to receive text and it is 
                                         // ready for this input method to process received events and send result text 
                                         // back to the text view

    virtual VfxBool deactivateInput() = 0; // Deactivate input method, but the text view is 
                                           // still binded to input manager

    virtual VfxBool dispatchKeyEvent(VfxKeyEvent &event) = 0; // If the input method wants to handle this key event, return true, 
                                                              // otherwise return false and the caller will handle the event 

    virtual VfxBool dispatchPenEvent(VfxPenEvent &event) = 0; // If the input method wants to handle this pen event, return true, 
                                                              // otherwise return false and the caller will handle the event   

    virtual void disableSymbolPicker() = 0; // Disable symbol picker function

    virtual void enableSymbolPicker() = 0; // Enalbe symbol picker function

    
    virtual void override_autocap() = 0; // set autocap to off temprarily.
    
    virtual VfxBool getCharInfor(VfxWChar code, 
        VfxWChar *inforBuf, 
        VfxU32 bufSize, 
        mmi_imm_input_mode_enum mode) const = 0; // Gets information related to a phonectic character .Typical usage include pinyin search 

    virtual VfxBool isIMEState() const = 0; // Check if it's IME state currently

    virtual void addNewWordsFromText(VfxWChar *text) = 0; // Add the new words of the text into IME user database

    virtual mmi_imm_input_mode_enum getCurrInputMode() const = 0; // Get current input mode 

    virtual mmi_imm_input_type_enum getCurrInputType() const = 0; // Get current input type 

    virtual mmi_imm_input_mode_enum *getCurrrUserSpecificInputModeList() = 0; // Get current user specific input mode list

    virtual void setInputModeSwitchable(VfxBool isSwitchable) = 0; // Set if input mode is switchable

    virtual VfxU32 getInputMethodHistorySize() const = 0; // Get input method history size

    virtual void getInputMethodHistory(void *historyAddress) = 0; // Get input method history data, should be called 
                                                                  // when the current screen in entering history

    virtual void setInputMethodHistory(void *historyAddress) = 0; // Set input method history data, should be called 
                                                                  // when back from history

    virtual void enableAutoCapInHistory(void *historyAddress) = 0; // enable the auto capitalization in history

    virtual void showSoftInput() = 0; // Request that the current input method's soft input area be shown to the user

    virtual void hideSoftInput() = 0; // Request to hide the current input method's soft input area 

    virtual VfxBool isSoftInputVisible() = 0; // Check if the soft input area is visible

    virtual VfxS32 isValidInputString(VfxWChar *string, VfxS32 len) = 0; // To check if the string can be input by input method

    virtual VfxBool isValidInputStringForPaste(VfxWChar *string, VfxS32 len) = 0; // To check if the string can be input by input method

    virtual void cursorPosChanged(VfxRect &cursorRect) = 0; // To indicate the cursor position is changed, the posistion is full screen relative

    virtual VfxBool isInputMethodUIControl(VfxControl *control) = 0; // To check if it's input method UI control

    virtual void rotate() = 0; // To rotate the input method

    virtual void beforeRotate() = 0; // Before rotating the input method

    virtual void setSpecialEnterKey(VfxBool isEnabled) = 0; // Configure the special enter key status

    virtual void resetIMEState() = 0; // Reset IME state to the initial state
};

#endif /* __VSRV_INPUT_METHOD_INTERFACE_H__ */

