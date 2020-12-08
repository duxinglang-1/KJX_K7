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
 *  vadp_p2v_input_server_interface.cpp
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input server p2v interfaces
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
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

extern "C"
{
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "Word_engine.h"
#include "Imc_symbol.h"
#include "Imc_key.h"
#include "Imc_pen.h"
#include "Imc.h"
}



#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vcp_pluto_control.h"
#include "vcp_textview.h"
#include "vcp_popup.h"
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
#include "vcp_confirm_popup.h"
#endif

#include "vsrv_input_manager.h"
#include "vadp_v2p_input_server.h"
#include "vadp_p2v_input_server_interface.h"
#include "vsrv_input_method_popup.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_uiframework_def.h"


/**********************************************************************
 * External Interfaces:
 **********************************************************************/

void vadp_p2v_redraw_imui_controls(U32 imuiSet)
{
}


void vadp_p2v_get_pos_from_fixed_control(S16* x, S16* y)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);

    VfxRect fixed_control_rect = this_ptr->getFixedUIRect();
    *x  += fixed_control_rect.getX();
    *y  += fixed_control_rect.getY();
    
}

extern "C" 
void vadp_p2v_set_softkey_function(void (*f) (void), MMI_key_event_type keyType, WGUI_SOFTKEY_ENUM keyCode)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);
    U16 mmiKeyCode;

    switch(keyCode)
    {
    case MMI_LEFT_SOFTKEY:
        mmiKeyCode = KEY_LSK;
        break;
    case MMI_RIGHT_SOFTKEY:
        mmiKeyCode = KEY_RSK;
        break;
    case MMI_CENTER_SOFTKEY:
        mmiKeyCode = KEY_CSK;
        break;
    default:
        return;

    }

    this_ptr->setKeyHandler((FuncPtr)f, mmiKeyCode, keyType);
}


void vadp_p2v_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    this_ptr->setKeyHandler(funcPtr, (VfxU16)keyCode, (VfxU16)keyType);
}


FuncPtr vadp_p2v_get_key_handler(U16 keyCode, U16 keyType)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    return (FuncPtr)this_ptr->getKeyHandler((VfxU16)keyCode, (VfxU16)keyType);
}


void vadp_p2v_clear_key_handler(U16 keyCode, U16 keyType)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    this_ptr->clearKeyHandler((VfxU16)keyCode, (VfxU16)keyType);
}

void vadp_p2v_get_current_key_info(U16 *keyCode, U16 *keyType)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    this_ptr->getCurrentKeyInfo((VfxU16 *)keyCode, (VfxU16 *)keyType);
}


MMI_BOOL vadp_p2v_send_imui_message(mmi_imui_message_struct_p msg_ptr, U32 *ret)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);

    return (this_ptr->sendMessage(msg_ptr, ret) == VFX_TRUE) ? MMI_TRUE : MMI_FALSE;
}


MMI_BOOL vadp_p2v_is_venus_ime_connected(void)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    return (this_ptr->getBinding() == NULL) ? MMI_FALSE : MMI_TRUE;
}


void vadp_p2v_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VFX_ASSERT(this_ptr);

    this_ptr->setGroupKeyHandler(funcPtr, (VfxU16 *)keyCodes, (VfxU8)len, (VfxU16) keyType);
}


void vadp_p2v_set_default_imui_parameters(mmi_imui_param_struct *param)
{
}


#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
void vadp_p2v_start_capture_stroke(
        U32 max_points,
        mmi_pen_point_struct *point_array,
        U32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    
    this_ptr->setStrokeAreaAndStart(
                    (VfxU32)max_points, 
                    (VfxPenStrokePoint*)point_array, 
                    (VfxU32)num_regions, 
                    (VfxPenStrokeHandWritingRegion*)region_array, 
                    (VfxPenStrokeHandWritingRegion*)ext_region);
    
}


void vadp_p2v_stop_capture_stroke(void)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    this_ptr->stopStroke();

}

void vadp_p2v_begin_strokes_of_character(void)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    this_ptr->beginStrokesOfCharacter();

}

void vadp_p2v_end_strokes_of_character(void)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    this_ptr->endStrokesOfCharacter();

}

void vadp_p2v_change_handwriting_area(
        U32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    this_ptr->changeHWArea((VfxPenStrokeHandWritingRegion*)region_array, (VfxU32)num_regions, (VfxPenStrokeHandWritingRegion*)ext_region);
}

void vadp_p2v_change_handwriting_area_ex(
        U32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    VadpInputServerUI *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VFX_ASSERT(this_ptr);
    this_ptr->changeHWAreaEx((VfxPenStrokeHandWritingRegion*)region_array, (VfxU32)num_regions, (VfxPenStrokeHandWritingRegion*)ext_region);

}

#endif /* #if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) */


#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) || defined(__MMI_IME_V3__)
extern "C"
void vadp_p2v_show_popup_list(
                    S32 x, 
                    S32 y, 
                    S32 number_of_items,
                    U16 *list_of_items,
                    S32 highlighted_item,
                    FuncPtr confirm_callback, 
                    FuncPtr cancel_callback)
{
    
    
}
extern "C"
void vadp_p2v_close_ime_popup(void)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    this_ptr->closepopup();
}

#define VADP_P2V_INPUT_METHOD_POPUP_MAX_COUNT           100

extern "C"
void vadp_p2v_show_ime_popup(
        U16 title_str_id,
        U16 *item_str_id_array,
        S32 item_count,
        S32 hilite_item,
        Vadp_p2v_input_method_popup_cb cb_func1,
		Vadp_p2v_input_method_popup_cbExt cb_func2,
		MMI_BOOL show_button)
{
	#ifdef __COSMOS_MMI_PACKAGE__
    if (title_str_id == 0)
    {
        VFX_ASSERT(0);
    }
    VfxWString title = VFX_WSTR_RES(title_str_id);

    VfxWString items[VADP_P2V_INPUT_METHOD_POPUP_MAX_COUNT];
    VsrvInputMethodPopup *popup;    // can destroy itself
    for (int i = 0; i < item_count; i++)
    {
        if (item_str_id_array[i] == 0)
        {
            VFX_ASSERT(0);
        }
        items[i] = VFX_WSTR_RES(item_str_id_array[i]);
    }

    // reset the state of ime
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
  //  mmi_imc_pen_stop_singleblock_handwriting(); /* supposedly hack reset to fix issue ; no side effect seen */
    #endif
    mmi_imc_reset_ime_state();


    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding * inputBinding = this_ptr->getBinding();
	
    if(inputBinding && inputBinding ->getConnection() && inputBinding->getOwner())
    {
    	VfxBool showSettingButton = !(inputBinding->m_inputSettingFlags & IME_DISABLE_SETTING_ENTRY_BUTTON);
        VFX_OBJ_CREATE_EX(
		popup,
		VsrvInputMethodPopup,
		inputBinding->getOwner(),
		(title, items, (VfxS32)item_count, (VfxS32)hilite_item, (VsrvInputMethodPopupCb)cb_func1,  (VsrvInputMethodPopupCbExt)cb_func2, showSettingButton, (VfxBool)show_button));
    }
    else
    {
        VFX_OBJ_CREATE_EX(
                popup,
                VsrvInputMethodPopup,
                // TODO: revise VFX_OBJ_GET_INSTANCE(VadpInputServerUI),
                VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr(),
                (title, items, (VfxS32)item_count, (VfxS32)hilite_item, (VsrvInputMethodPopupCb)cb_func1,  (VsrvInputMethodPopupCbExt)cb_func2, VFX_TRUE, (VfxBool)show_button));
                }
    
    popup->setStaticShelter(VFX_TRUE);
    popup->show(VFX_TRUE);
#ifdef __MMI_TOUCH_SCREEN__

    ::mmi_pen_reset();
#endif
#endif
}


extern "C"
void vadp_p2v_show_ime_popup_by_mem(
        U16 title_str_id,
        VfxWChar *item_str_array[],
        S32 item_count,
        S32 hilite_item,
        Vadp_p2v_input_method_popup_cb cb_func1,
		Vadp_p2v_input_method_popup_cbExt cb_func2,
		MMI_BOOL show_button)
{
	#ifdef __COSMOS_MMI_PACKAGE__
    if (title_str_id == 0)
    {
        VFX_ASSERT(0);
    }
    VfxWString title = VFX_WSTR_RES(title_str_id);
    
    VfxWString items[VADP_P2V_INPUT_METHOD_POPUP_MAX_COUNT];
    VsrvInputMethodPopup *popup;    // can destroy itself
    for (int i = 0; i < item_count; i++)
    {
        items[i] = VFX_WSTR_MEM(item_str_array[i]);
    }

    // reset the state of ime
    mmi_imc_reset_ime_state();

	VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
	VsrvInputBinding * inputBinding = this_ptr->getBinding();
	
	if(inputBinding && inputBinding ->getConnection() && inputBinding->getOwner())
	{
		VfxBool showSettingButton = inputBinding->m_inputSettingFlags & IME_DISABLE_SETTING_ENTRY_BUTTON;
		VFX_OBJ_CREATE_EX(
			popup,
			VsrvInputMethodPopup,
			inputBinding->getOwner(),
			(title, items, (VfxS32)item_count, (VfxS32)hilite_item, (VsrvInputMethodPopupCb)cb_func1,  (VsrvInputMethodPopupCbExt)cb_func2, showSettingButton, (VfxBool)show_button));
	}
	else
	{
		
		VFX_OBJ_CREATE_EX(
			popup,
			VsrvInputMethodPopup,
			// TODO: revise VFX_OBJ_GET_INSTANCE(VadpInputServerUI),
			VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr(),
			(title, items, (VfxS32)item_count, (VfxS32)hilite_item, (VsrvInputMethodPopupCb)cb_func1,  (VsrvInputMethodPopupCbExt)cb_func2, VFX_TRUE, (VfxBool)show_button));
	}
    
    popup->setStaticShelter(VFX_TRUE);
    popup->show(VFX_TRUE);
#ifdef __MMI_TOUCH_SCREEN__

    ::mmi_pen_reset();
#endif
#endif
}

#endif /* #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */


#if defined(__MMI_IME_USER_DATABASE__)

/***************************************************************************** 
 * Class VadpEditNewWordPopup
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VadpEditNewWordPopup is used to show the popup when the user wants to change input mode or
 *  writing language
 */
class VadpEditNewWordPopup : public VcpInputPopup
{
// Constructor / Destructor
public:

    VadpEditNewWordPopup() : m_backupInputBinding(NULL), m_backupInputMethodHistory(NULL) 
	{
		memset(&new_word_editor_buffer[0], 0, sizeof(UI_character_type) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1);
	}
    
// Override
protected:

    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Implementation
private:

    void onButtonClicked(VfxObject *sender, VcpInputPopupButtonEnum buttonId);

// Variable
private:

    VsrvInputBinding *m_backupInputBinding;

    void *m_backupInputMethodHistory;
	UI_character_type new_word_editor_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
};

extern "C"
{
//extern UI_character_type g_imc_new_word_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
extern mmi_imm_input_mode_enum g_imc_edit_new_word_input_mode_list[MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG];
extern mmi_imm_input_mode_enum g_imc_new_word_input_mode;
}

/***************************************************************************** 
 * Class VadpEditNewWordPopup
 *****************************************************************************/

void VadpEditNewWordPopup::onInit()
{
    VsrvInputManager *inputManager = VFX_OBJ_GET_INSTANCE(VsrvInputManager);
        
    m_backupInputBinding = inputManager->getBinding();

    VFX_ALLOC_MEM(m_backupInputMethodHistory, inputManager->getInputMethodHistorySize(), this);

    inputManager->getInputMethodHistory(m_backupInputMethodHistory);
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    (topLevel->getActiveScr())->addChildFrame(this);   
        
    VcpInputPopup::onInit();


    setAutoDestory(VFX_FALSE);

    setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_SPELL_WORD));

    setText(VFX_WSTR_STATIC(new_word_editor_buffer), MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE / 2, VFX_TRUE);

    VsrvInputBinding inputBinding(IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ADD_NEW_WORD, IME_DISABLE_NEW_LINE_SYMBOL, 0, m_inputbox[0]->m_editing);

    inputBinding.setUserSpecialInputModeList(::g_imc_edit_new_word_input_mode_list);

    m_inputbox[0]->setIME(inputBinding);

    m_signalButtonClicked.connect(this, &VadpEditNewWordPopup::onButtonClicked);

    m_inputbox[0]->setAutoActivated(VFX_TRUE);

    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

    inputServerUI->registerExtraControl(this);
	//IsNewordPopupEnable = VFX_TRUE ;
}


void VadpEditNewWordPopup::onDeinit()
{
    VFX_FREE_MEM(m_backupInputMethodHistory);
	//IsNewordPopupEnable = VFX_FALSE ;
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    inputServerUI->leaveIMEPopupMenu(this);

    VcpInputPopup::onDeinit();
}


VfxBool VadpEditNewWordPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        exit(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}


void VadpEditNewWordPopup::onButtonClicked(VfxObject *sender, VcpInputPopupButtonEnum buttonId)
{
    mmi_imc_message_struct imc_msg;
    VfxBool has_forbidden_char = VFX_FALSE;
    VfxS32 str_len = 0;
    VfxS32 i, j;
    mmi_ime_word_add_new_word_ret_value_enum ret = MMI_IME_WORD_ADD_NEW_WORD_FAILED;
    UI_character_type temp_new_word_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    mmi_ime_word_capital_state_enum old_case;
#endif
    

    if (buttonId == VCP_INPUT_POPUP_BTN_OK)
    {
        VFX_ASSERT(g_imc_new_word_input_mode != IMM_INPUT_MODE_NONE);

        str_len = mmi_ucs2strlen((const CHAR * )&new_word_editor_buffer[0]);

        if (mmi_ucs2chr((const CHAR * )&new_word_editor_buffer[0], 0x20) != NULL 
            || mmi_ucs2chr((const CHAR * )&new_word_editor_buffer[0], 0x30) != NULL) /* Space and zero are forbidden in new word */
        {
            has_forbidden_char = VFX_TRUE;
        }

        if (new_word_editor_buffer[0] != 0 && str_len > 1 && !has_forbidden_char)
        { 
            ret = mmi_ime_word_add_new_word(g_imc_new_word_input_mode, new_word_editor_buffer);
        }
    }
    else if (buttonId == VCP_INPUT_POPUP_BTN_CANCEL)
    {
        
    }

    if (m_backupInputBinding && m_backupInputBinding->getConnection())
    {
        VsrvInputManager *inputManager = VFX_OBJ_GET_INSTANCE(VsrvInputManager);

        if (inputManager && m_backupInputMethodHistory)
        {
            inputManager->setInputMethodHistory(m_backupInputMethodHistory);
        }
        
        m_backupInputBinding->getConnection()->sendIMENotification(IME_NOTIFICATION_ACTIVATE_EDITOR, NULL);
    }

    if (buttonId == VCP_INPUT_POPUP_BTN_OK && new_word_editor_buffer[0] != 0 )//&& mmi_imc_is_connected())
    {
        mmi_imc_global_data_struct_p imeData = mmi_imc_get_global_data();
        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
        old_case = imeData->capital_state;
    
        mmi_imc_key_change_candidate_case_by_previous_string();

        const sIMEModeDetails * modeDetailsPtr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());

        VFX_ASSERT(modeDetailsPtr);
    
        if ((modeDetailsPtr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            && imeData->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
        {
            new_word_editor_buffer[0] = mmi_towupper(new_word_editor_buffer[0]);
        }

        imeData->capital_state = old_case;
    #endif /* #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) */
    
	    for (i = 0, j = 0; new_word_editor_buffer[i]; i++)
	    {
		    if (mmi_imm_test_input(&new_word_editor_buffer[i], 1))
		    {
			    temp_new_word_buffer[j++] = new_word_editor_buffer[i];
		    }
	    }

	    temp_new_word_buffer[j] = 0;
    
  
    }

    exit(VFX_FALSE);
    if (buttonId == VCP_INPUT_POPUP_BTN_OK && new_word_editor_buffer[0] != 0)// && mmi_imc_is_connected())
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_START_SMART_ALPHABETIC;
	    mmi_imc_send_message(&imc_msg);

        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)&temp_new_word_buffer[0];
        imc_msg.param_1 = 0;

        mmi_imc_send_message(&imc_msg);
    
	    imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
        mmi_imc_send_message(&imc_msg);
    
    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        mmi_imc_editor_cursor_movement_handler(NULL);
    #endif    
    }
    if (buttonId == VCP_INPUT_POPUP_BTN_OK)
    {

        /*
        VcpAlertPopup *alertPopup;
        
        VFX_OBJ_CREATE(alertPopup, VcpAlertPopup, VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr());*/

        if (ret == MMI_IME_WORD_ADD_NEW_WORD_SUCCESS)
        {

            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS,
                (WCHAR *)GetString(STR_GLOBAL_SAVED));



            //  alertPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
            // alertPopup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVED));
        }
        else if (ret == MMI_IME_WORD_ADD_NEW_WORD_DUPLICAT)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)GetString(STR_INPUT_METHOD_WORD_ALREADY_EXISTS));
            //   alertPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            //   alertPopup->setText(VFX_WSTR_RES(STR_INPUT_METHOD_WORD_ALREADY_EXISTS));
        }
        else
        {

            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)GetString(STR_GLOBAL_FAILED_TO_SAVE));
            //   alertPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            // alertPopup->setText(VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE));
        }
        //alertPopup->setStaticShelter(VFX_TRUE);

        // alertPopup->show(VFX_TRUE);
    }
}

void vadp_p2v_show_new_word_editor(void)
{
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
	VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    VadpEditNewWordPopup *inputPopup = NULL;

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
    mmi_imc_pen_stop_singleblock_handwriting();
#endif
    mmi_imc_reset_ime_state();


    if(this_ptr->getBinding() && this_ptr->getBinding()->getConnection() && this_ptr->getBinding()->getOwner())
    {

        VFX_OBJ_CREATE(inputPopup, 
            VadpEditNewWordPopup,
            this_ptr->getBinding()->getOwner());
    }

    else
    {
    VFX_OBJ_CREATE(inputPopup, 
        VadpEditNewWordPopup,
        VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr());

    }

    VFX_ASSERT(inputPopup);

    inputPopup->setStaticShelter(VFX_TRUE);
	inputServerUI->enterIMEPopupMenu(inputPopup);
    inputPopup->show(VFX_TRUE);

#ifdef __MMI_TOUCH_SCREEN__
    ::mmi_pen_reset();
#endif
}
#endif /* #if defined(__MMI_IME_USER_DATABASE__) */


#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
extern "C" void vadp_p2v_show_no_hw_data_popup(void)
{
    VcpConfirmPopup* m_confirmPopup;
	
	mmi_imc_reset_ime_state();

	VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 

        if(this_ptr->getBinding() && this_ptr->getBinding()->getConnection() && this_ptr->getBinding()->getOwner())
	{
		VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this_ptr->getBinding()->getOwner());
	}
	else
	{
		VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr());
	}

	VfxWString strText(VFX_WSTR_RES(STR_INPUT_METHOD_NO_HW_DATA));  
	m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
	m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
	m_confirmPopup->setText(strText);
	m_confirmPopup->setAutoDestory(VFX_FALSE);
	m_confirmPopup->setCatchFocus(VFX_FALSE);
	m_confirmPopup->show(VFX_TRUE);  			

#ifdef __MMI_TOUCH_SCREEN__
    ::mmi_pen_reset();
#endif

}
#endif /*#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)*/


