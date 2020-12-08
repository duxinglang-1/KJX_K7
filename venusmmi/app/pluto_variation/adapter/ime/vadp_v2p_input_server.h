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
 *  vadp_v2p_input_server.h
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input server
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_V2P_INPUT_SERVER_H__
#define __VADP_V2P_INPUT_SERVER_H__

extern "C"
{
    #include "MMI_features.h"
    #include "ImeGprot.h"
    #include "MMIDataType.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "imui.h"
} 

    #include "vfx_datatype.h"
    #include "vfx_object.h"
    #include "vsrv_input_manager.h"
    #include "vfx_class_info.h"
    #include "vfx_cpp_base.h"
    #include "vfx_input_event.h"
    #include "vfx_basic_type.h"
    #include "vcp_text_editor.h"
    #include "vfx_animation.h"
    #include "vfx_signal.h"
    #include "vfx_frame.h"
    #include "vfx_control.h"
    #include "vcp_vk.h"
    #include "vcp_sel_box.h"
    #include "vfx_layer_control.h"


class VadpInputServerUI;
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
class VcpVKMain;
class VcpVKMini;
#else
class VcpVK;
#endif

#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__)
class VadpInputServerSingleBlockHWPanel;
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * Input server Class
 */
class VadpInputServer : public VfxObject, public VsrvInputMethodInterface
{
    VFX_DECLARE_CLASS(VadpInputServer);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VadpInputServer);
    
// Constructor / Destructor
// Override
protected:
    virtual vrt_allocator_handle getAllocator();

public:

    VadpInputServer();

    virtual ~VadpInputServer();

    virtual VfxBool bindInput(VsrvInputBinding *binding);

    virtual VsrvInputBinding *getBinding(); 

    virtual VfxBool unbindInput(VsrvInputBinding* binding); 
    
    virtual VfxBool activateInput(); 

    virtual VfxBool deactivateInput(); 

    virtual VfxBool dispatchKeyEvent(VfxKeyEvent &event); 

    virtual VfxBool dispatchPenEvent(VfxPenEvent &event);  

    virtual void closepopup();
    virtual void override_autocap();

    virtual void disableSymbolPicker(); 

    virtual void enableSymbolPicker(); 

    virtual VfxBool getCharInfor(VfxWChar code, VfxWChar *inforBuf, VfxU32 bufSize, mmi_imm_input_mode_enum mode) const;

    virtual VfxBool isIMEState() const; 

    virtual void addNewWordsFromText(VfxWChar *text); 

    virtual mmi_imm_input_mode_enum getCurrInputMode() const; 

    virtual mmi_imm_input_type_enum getCurrInputType() const; 

    virtual mmi_imm_input_mode_enum *getCurrrUserSpecificInputModeList(); 

    virtual void setInputModeSwitchable(VfxBool isSwitchable); 

    virtual VfxU32 getInputMethodHistorySize() const;

    virtual void getInputMethodHistory(void *historyAddress);

    virtual void setInputMethodHistory(void *historyAddress);

    virtual void enableAutoCapInHistory(void *historyAddress);

    virtual void showSoftInput();

    virtual void hideSoftInput();

    virtual VfxBool isSoftInputVisible();

    virtual VfxS32 isValidInputString(VfxWChar *string, VfxS32 len);
    virtual VfxBool isValidInputStringForPaste(VfxWChar *string, VfxS32 len);
    
    virtual void cursorPosChanged(VfxRect &cursorRect);

    virtual VfxBool isInputMethodUIControl(VfxControl *control);

    virtual void rotate();

    virtual void beforeRotate();

    virtual void setSpecialEnterKey(VfxBool isEnabled);

    virtual void resetIMEState();
    //#if defined(__MMI_COSMOS_KEYPAD_BAR__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
    void insert_sym_by_sympicker(VfxObject *, VfxWChar);
   // #endif
// Method
public:
    void onbacklightChange(VfxBool lit);

    void setKeyHandler(FuncPtr funcPtr, VfxU16 keyCode, VfxU16 keyType);
    FuncPtr getKeyHandler(VfxU16 keyCode, VfxU16 keyType);
    void clearKeyHandler(VfxU16 keyCode, VfxU16 keyType);
    void setGroupKeyHandler(FuncPtr funcPtr, VfxU16 *keyCodes, VfxU8 len, VfxU16 keyType);
    void getCurrentKeyInfo(VfxU16 *keyCode, VfxU16 *keyType);

// Implementation
private:

    VsrvInputBinding *m_currInputBinding;

    FuncPtr *m_currentKeyFuncPtrs;

    VfxBool m_isMultitapState;

    VfxKeyCodeEnum m_currentKeyCode;

    VfxKeyEventTypeEnum m_currentKeyType;

    VfxSignal0 m_signalCursorPosChanged;

    VfxBool m_decimalFlag;


// Implementation
private:

    void applyInputSettings();

    static U32 plutoImeMsgCallBcak(void * inputHandle, mmi_imc_message_struct_p msgPtr);

#if defined (__MMI_TOUCH_SCREEN__)
    void convertInputEventsToVKEvents(const IMEInputEventEnum *inputEventsList, gui_virtual_keyboard_pen_enum *vkEventList);
    gui_virtual_keyboard_pen_enum mapInputEventToVKEvent(IMEInputEventEnum inputEvent);
#endif

    void onPenEventProcessed(VfxPenEvent &event, VfxControl *control);

    void onCursorPosChanged();

    void checkDecimal();

    VfxU32 insertCharWrapper(VfxWChar wChar, VfxS32 newCursorPos, VfxS32 index = -1);

    friend class VadpInputServerUI; 
	friend class VIME_SymbolPicker_Page;
};

#endif /* __VADP_V2P_INPUT_SERVER_H__ */


/*
 * Input server UI Class
 */
class VadpInputServerUI : public VfxObject
{
    VFX_DECLARE_CLASS(VadpInputServerUI);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VadpInputServerUI);

// Override
protected:
    virtual vrt_allocator_handle getAllocator();

// Constructor / Destructor
public:

    VadpInputServerUI();
#if defined __MMI_IME_CANDIDATE_GRID__
    VfxS32 updateCandGrid(VcpCandGrid *selBox, mmi_imui_update_selection_area_struct_p updatePtr);
#endif
    virtual ~VadpInputServerUI(){}

// Method
public:
    void halt_vk_animation()
    {
        m_haltVkAnimation = VFX_TRUE;
    }
    VfxBool sendMessage(mmi_imui_message_struct_p msg_ptr, VfxU32 *ret);

    void setFrameAboveVK(VfxFrame *aboveFrame);

    VfxRect getFixedUIRect();

    VfxBool isIMUIControl(VfxControl *control);
    
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
    void setStrokeAreaAndStart(VfxU32 maxPoint, VfxPenStrokePoint *points, VfxU32 areaCount, VfxPenStrokeHandWritingRegion *areas, VfxPenStrokeHandWritingRegion * extArea);
    void stopStroke();
    void beginStrokesOfCharacter();
    void endStrokesOfCharacter();
    void changeHWArea(const VfxPenStrokeHandWritingRegion * areas, VfxU32 areaCount, const VfxPenStrokeHandWritingRegion * extArea);
    void changeHWAreaEx(const VfxPenStrokeHandWritingRegion * areas, VfxU32 areaCount, const VfxPenStrokeHandWritingRegion * extArea);
#endif

    void registerExtraControl(VfxControl *extraControl);

    void unRegisterExtraControl(VfxControl *extraControl);

    void registerIMEPopupMenu(VfxBasePopup *popup);

    void unRegisterIMEPopupMenu(VfxBasePopup *popup);

    void enterIMEPopupMenu(VfxBasePopup *popup);

	void leaveIMEPopupMenu(VfxBasePopup *popup);

    void beforeRotate();

    void rotate();

    void setSpecialEnterKey(VfxBool isEnabled);
    
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    void updateVKButtonValidation();
#endif

// Override
protected:

    virtual void onInit();

    virtual void onDeinit();

// Member
private:
    VfxBool m_haltVkAnimation;
    VfxBool m_isActive;
    VfxBasePopupStateEnum m_popupstate;

    VfxS32 m_uiBottomY;
    VfxS32 m_uiWidth;
    VfxS32 m_uiX;

#if defined(__MMI_IME_FLOATING_CAND_BOX__)  
    VfxS32 m_uiFloatingWidth;
    VfxS32 m_uiFloatingX;
    VfxS32 m_uiFloatingBottomY;
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    VcpVKMain *m_vk;
    VcpVKMini * m_vkMini;
#else
    VcpVK *m_vk;
#endif
    VfxBool m_isVKHidden;
    static VfxBool s_enableVKTransitionEffect;
    VfxTimer *m_vkEffectValidationTimer;
#endif

#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
    VadpInputServerSingleBlockHWPanel *m_singleBlockHWPanel;
#endif

    VcpSelBox *m_compBox;

    VcpSelBox *m_candBox;
#if defined __MMI_IME_CANDIDATE_GRID__
    VcpCandGrid * m_candGrid;
#endif
#if defined __MMI_IME_SCROLLING_COMPOSITION__
    VcpScrollableSelBox *m_sCompBox;
#endif
#ifdef __MMI_CSTAR_PHRASE_INPUT__
    VcpResizableCompositionBox *m_inputArea;
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
    VcpResizableCompositionBox *m_rCompBox;
#endif

    VfxS32 m_candBoxFlag;

    VfxS32 m_compBoxFlag;

    VfxFrameWeakPtr m_frameAboveVKWeekPtr;

#if defined(__MMI_IME_USER_DATABASE__)
    VfxWString newWordPrompt;
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__) 
    VfxRect m_floatingUIRect;
#endif

#if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
    VfxBool m_isIMEIndicatorEnabled;
#endif

    
    VfxRect m_fixedUIRect;

    VfxObjList m_extraControlList;
    
    VfxWeakPtr <VfxBasePopup> m_popupMenu;

// Implementation
private:

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    void createVirtualKeyboard();
#if defined   __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    void createMiniVirtualKeyboard();
    void setupMiniVirtualKeyboard();
    void onVKButtonLongTapEvent(VfxObject *sender, VcpVKLongtapHintEvt& event);
    void onVKButtonLongTapTimeUp(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
#endif
#if defined   __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__
    void vkDisplayCallback(VcpVKDisplayCbPara &vkDisplayCbfo);
    VfxBool vkMultiPopupCallback(VfxU32 content, VfxU32* index);
#endif
    void setupVirtualKeyboard(mmi_imui_message_struct_p msg_ptr);
    void onVKButtonDown(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void onVKButtonRepeat(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void onVKButtonMove(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void onVKButtonLongTap(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void onVKButtonUp(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void onVKButtonAbort(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value);
    void translateVKEvent(VcpVKBtnTypeEnum btnType, VfxU32 value, gui_virtual_keyboard_pen_enum *vk_event, gui_pen_event_param_struct *vk_para);
    void dispatchVKEvent(VfxU8 penEvent, gui_virtual_keyboard_pen_enum vkEvent, gui_pen_event_param_struct *vkParaPtr);
    void insertChar(UI_string_type str, UI_character_type character);
    void deleteChar(UI_string_type str, UI_character_type character);
    void insertVKEvent(gui_virtual_keyboard_pen_enum *eventList, gui_virtual_keyboard_pen_enum event);
    void deleteVKEvent(gui_virtual_keyboard_pen_enum *eventList, gui_virtual_keyboard_pen_enum event);
    void onVKEffectValidationCheckTimer(VfxTimer *timer);
    static void vkEffectValidationCheckTimer();
    void updateVKSpecialEnterKey();
#endif
    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void initUIProperties();

    void updateUIParams();

    void reorderCandidatesToCenterFirst(VfxWChar *str, VfxS32 count);

    VfxWChar *getStringByIndex(VfxWChar * str, VfxS32 index, VfxS32 count);

    void layoutUIComponents();

    void layoutAllFixedUIComponents();

#if defined(__MMI_IME_FLOATING_CAND_BOX__) 
    void layoutAllFloatingUIComponents();
    VfxS32 getFloatingUIHeight();
#endif

#if defined(__MMI_TOUCH_SCREEN__)
    void drawHandWritingStroke(mmi_pen_point_struct *previous_point, mmi_pen_point_struct *point);

    void clearHandWritingStroke();
#endif

    VfxS32 updateSelBox(VcpSelBox *selBox, mmi_imui_update_selection_area_struct_p updatePtr);

    void updateSelBoxTheme(VcpSelBox *selBox);
#if defined __MMI_IME_SCROLLING_COMPOSITION__
    VcpScrollableSelBox*  createScrollableSelBox();
    void  updateSelBoxTheme(VcpScrollableSelBox *selBox);
    VfxS32 updateScrollableSelBox(VcpScrollableSelBox *selBox, mmi_imui_update_selection_area_struct_p updatePtr);
#endif
#if defined __MMI_IME_CANDIDATE_GRID__
    VcpCandGrid * createCandGrid();
    void  updateSelBoxTheme(VcpCandGrid *selBox);
    void onCandGridClick(VfxObject *selBox, VfxS32 index);
#endif
    VcpSelBox * createSelBox(VfxU32 style);

#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
    VcpResizableCompositionBox * createResizableCompositionBox();
#if defined(__MMI_TOUCH_SCREEN__)
    void onResizeableCompBoxClicked(VfxObject* rCompBox);
#endif
#endif

    VfxFontDesc mapFontDesc(UI_font_type fontStyle);

    VfxU32 mapColorValue(color colorStruct);

#if defined(__MMI_TOUCH_SCREEN__)
    void onSelBoxCandDown(VfxObject *selBox, VfxS32 index);
    void onSelBoxCandUp(VfxObject *selBox, VfxS32 index);
    void onSelBoxCandMove(VfxObject *selBox, VfxS32 index);

    void onSelBoxPreArrowClicked(VfxObject *selBox);
    void onSelBoxNextArrowClicked(VfxObject *selBox);
#endif

    friend class VadpInputServer; 
    friend class VIME_SymbolPicker_Page;
};


#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__)
/*
 * VadpInputServerSingleBlockHWPanel Class
 */
class VadpInputServerSingleBlockHWPanel : public VfxControl
{
// Constructor / Destructor
public:

    VadpInputServerSingleBlockHWPanel();

    virtual ~VadpInputServerSingleBlockHWPanel(){}

// Method
public:

    void setExtraBlockImg(VfxId imgId);

    void drawStroke(VfxPoint prevPoint, VfxPoint point);

    void clearStroke();

    void setStrokColor(VfxColor strokeColor);

	void rotate();

	void updateSize();

// Override
protected:

    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

public:
#if	defined( __MMI_IME_V3__) && defined(__MMI_IME_VK_TYPE_HANDWRITING__)
	VfxPoint	m_hw_start_pos;
	
	void setHWPos(VfxU32 x, VfxU32 y);
	const VfxPoint & getHWPos();
#endif
// Implementation    
private:

    VfxImageFrame *m_extraBlock;

    VfxLayerControl *m_strokeLayerControl;

    gdi_handle m_strokeLayer;

    VfxColor m_strokeColor;

    void *m_strokeLayerBuffer;
};
#endif
