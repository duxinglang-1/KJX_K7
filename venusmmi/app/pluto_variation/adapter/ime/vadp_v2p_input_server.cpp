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
 *  vadp_v2p_input_server.cpp
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input method manager
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "ImeGprot.h"
#include "string.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_inputs.h"
#include "gui_virtual_keyboard_language_type.h"
#include "DebugInitDef_Int.h"
#include "Imc.h"
#include "Imc_pen.h"
#include "Gdi_include.h"
#include "mmi_rp_srv_virtual_keyboard_misc_def.h"
#include "mmi_rp_srv_input_method_def.h"
#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif
}

#include "vfx_sys_mem_config.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_top_level.h"
#include "vfx_signal.h"
#include "vfx_pen.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vcp_text_utils.h"
#include "vfx_system.h"
#include "vfx_animation.h"
#include "vfx_frame.h"
#include "vcp_text_editor.h"
#include "vsrv_input_manager.h"
#include "vadp_v2p_input_server.h"
#include "vsrv_input_method_popup.h"
#include "vcp_symbol_picker.h"
#include "vcp_vk.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

extern "C"
{
    extern UI_ime_theme *current_ime_theme;
    extern S16 MMI_current_input_ext_type;
}
//#if defined(__MMI_COSMOS_KEYPAD_BAR__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
extern "C"
void vadp_p2v_show_symbol_picker(void)
{
    VIME_SymbolPicker_Page *symbol_picker_page;
    mmi_imc_reset_ime_state();
	 
    VadpInputServer *this_ptr = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
	 
    if (this_ptr->getBinding() && this_ptr->getBinding()->getConnection() && this_ptr->getBinding()->getOwner())
    {
        VFX_OBJ_CREATE(symbol_picker_page, VIME_SymbolPicker_Page, this_ptr->getBinding()->getOwner());
    }
    else
    {
        VFX_OBJ_CREATE(symbol_picker_page, VIME_SymbolPicker_Page, VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr());
    }
	 
	 //hack if no symbol then symbol picker object will not be created
     //VFX_ASSERT(symbol_picker_page);   
	 if(symbol_picker_page->m_no_of_symbols)
	 {
	 symbol_picker_page->enterIMEPopupMenu();
     symbol_picker_page->show(VFX_TRUE);
     symbol_picker_page->m_signalcallback.connect(VFX_OBJ_GET_INSTANCE(VadpInputServer), &VadpInputServer::insert_sym_by_sympicker);
	 }
	 else
	 {
		 VFX_OBJ_CLOSE(symbol_picker_page);	
	 }

}
//#endif


/***************************************************************************** 
 * Defines
 *****************************************************************************/

/***************************************************************************** 
 * Class VadpInputServer
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("InputServer", VadpInputServer, VfxObject);    
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VadpInputServer);
    

VadpInputServer::VadpInputServer():
    m_currInputBinding(NULL),
    m_currentKeyFuncPtrs(NULL),
    m_currentKeyCode(VFX_KEY_CODE_UNKNOWN),
    m_currentKeyType(VFX_KEY_EVENT_TYPE_UNKNOWN),
    m_decimalFlag(VFX_FALSE)

{
}


VadpInputServer::~VadpInputServer()
{
}

vrt_allocator_handle VadpInputServer::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}

VfxBool VadpInputServer::bindInput(VsrvInputBinding *binding)
{
    if (!binding)
    {
        return VFX_FALSE;
    }

    if (binding == m_currInputBinding)
    {
        return VFX_TRUE;
    }

    if (m_currInputBinding)
    {
        //unbindInput(m_currInputBinding);
        if (m_currInputBinding->getConnection())
        {
            m_currInputBinding->getConnection()->sendIMENotification(IME_NOTIFICATION_DEACTIVATE_EDITOR, NULL);
        }
    }

    VFX_ASSERT(!m_currInputBinding);

    m_currInputBinding = binding;

    VFX_ASSERT(m_currInputBinding);

	VFX_ASSERT(m_currInputBinding->getConnection());

    if (m_currInputBinding->m_inputType != IMM_INPUT_TYPE_NONE)
    {
        VFX_ASSERT(!m_currentKeyFuncPtrs);

        VFX_ALLOC_MEM(m_currentKeyFuncPtrs, MAX_KEYS * MAX_KEY_TYPE * sizeof(FuncPtr *), this);

        VFX_ASSERT(m_currentKeyFuncPtrs);
    }

    return VFX_TRUE;
}

VsrvInputBinding* VadpInputServer::getBinding()
{
    return m_currInputBinding;
}

VfxBool VadpInputServer::unbindInput(VsrvInputBinding* binding) 
{
    if (m_currInputBinding != binding)
    {
        return MMI_FALSE;
    }
    
    deactivateInput();

    m_currInputBinding = NULL;

    VFX_FREE_MEM(m_currentKeyFuncPtrs);

    m_currentKeyFuncPtrs = NULL;

    return VFX_TRUE;
}

void  VadpInputServer::onbacklightChange(VfxBool lit)
{

    if(!lit)
        //clear handwriting stroke for fixing the bug , workaround  aka Hack
    {
        VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
#if defined(__MMI_TOUCH_SCREEN__)
        inputServerUI->clearHandWritingStroke();
#endif
    }


}

VfxBool VadpInputServer::activateInput() 
{
    if (mmi_imc_is_connected())
    {
        mmi_imc_disconnect();
    }
	
    if (m_currInputBinding->m_inputType == IMM_INPUT_TYPE_NONE)
    {
        return VFX_TRUE;
    }
    VfxRenderer *vfxrender = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	
	vfxrender->m_signalBacklightSwitch2.connect(this, &VadpInputServer::onbacklightChange);
    memset(m_currentKeyFuncPtrs, 0, MAX_KEYS * MAX_KEY_TYPE * sizeof(FuncPtr *));
	
    m_isMultitapState = VFX_FALSE;
	
    applyInputSettings();

    const mmi_imm_input_mode_enum *input_mode_array = NULL;
    
    
    if (m_currInputBinding->m_inputType & IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        input_mode_array = m_currInputBinding->getUserSpecialInputModeList();
    }

	
	if (IMM_MESSAGE_ID_NONE == mmi_imm_set_required_mode_list((U32)m_currInputBinding->m_inputType, (mmi_imm_input_mode_enum *)input_mode_array, IMM_INPUT_MODE_NONE))
    {
		if(mmi_imc_connect((void *)this, (mmi_imc_message_funcptr)&VadpInputServer::plutoImeMsgCallBcak))
        {
            // TODO: need consider VRE case
            VfxPen *vfxPenPtr = VFX_OBJ_GET_INSTANCE(VfxPen);

            vfxPenPtr->m_signalEventProcessed.connect(this, &VadpInputServer::onPenEventProcessed);
                
            m_signalCursorPosChanged.connect(this, &VadpInputServer::onCursorPosChanged);

            mmi_imc_redraw_screen_by_state();
                
            return VFX_TRUE;   
        }
		else
		{
		    mmi_imc_disconnect();
			
		    return VFX_FALSE;
		}
    }
	else
	{
	    return VFX_FALSE;
	}
}

VfxBool VadpInputServer::deactivateInput() 
{
    if (!mmi_imc_is_connected())
    {
        return VFX_TRUE;
    }

    mmi_imc_disconnect();

    memset(m_currentKeyFuncPtrs, 0, MAX_KEYS * MAX_KEY_TYPE * sizeof(FuncPtr *));

    m_isMultitapState = VFX_FALSE;

#if defined(__MMI_FTE_SUPPORT__) || defined(__COSMOS_MMI__)
    mmi_imc_set_vk_present(MMI_IMC_VK_PRESENT_DEFAULT);
#endif

    m_signalCursorPosChanged.disconnect(this, &VadpInputServer::onCursorPosChanged);

    VfxPen *vfxPenPtr = VFX_OBJ_GET_INSTANCE(VfxPen);
    
    vfxPenPtr->m_signalEventProcessed.disconnect(this, &VadpInputServer::onPenEventProcessed);


    return VFX_TRUE;
}



void VadpInputServer::onPenEventProcessed(VfxPenEvent &event, VfxControl *control)
{
    if (!mmi_imc_is_connected() || !control || !m_currInputBinding || event.type != VFX_PEN_EVENT_TYPE_DOWN)
    {
        return;
    }

    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    
    if (inputServerUI->isIMUIControl(control))
    {
        return;
    }

    if (isIMEState())
    {
        mmi_imc_reset_ime_state();
    }
}


void VadpInputServer::onCursorPosChanged()
{
    if (!mmi_imc_is_connected())
    {
        return;
    }



     InputConnection *connPtr = m_currInputBinding->getConnection();
     if(connPtr->sendIMENotification( IME_NOTIFICATION_IS_CLIPBOARD_STATE, NULL))
        return;

    mmi_imc_editor_cursor_movement_handler(NULL);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)|| defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI);

    inputServerUI->updateVKButtonValidation();
#endif
}


void VadpInputServer::checkDecimal()
{
    m_decimalFlag = VFX_FALSE;
    
    if (m_currInputBinding && 
        ((m_currInputBinding->m_inputType & IMM_INPUT_TYPE_DECIMAL_NUMERIC) ||
         (m_currInputBinding->m_inputType & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)) &&
        !(m_currInputBinding->m_inputSettingFlags & IME_SKIP_DECIMAL_CHECK))
    {
        VfxWChar *textPtr = m_currInputBinding->m_inputConnectionPtr->getText();

        for (VfxS32 i = 0; textPtr[i]; i++)
        {
            if (textPtr[i] == L'.')
            {
                m_decimalFlag = VFX_TRUE;
                break;
            }
        }
    }
}


VfxU32 VadpInputServer::insertCharWrapper(VfxWChar wChar, VfxS32 newCursorPos, VfxS32 index)
{
    checkDecimal();

    if (m_currInputBinding && 
        ((m_currInputBinding->m_inputType & IMM_INPUT_TYPE_DECIMAL_NUMERIC) ||
         (m_currInputBinding->m_inputType & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)) &&
        !(m_currInputBinding->m_inputSettingFlags & IME_SKIP_DECIMAL_CHECK))
    {
        if (wChar == L'.' && m_decimalFlag)
        {
            UI_editor_play_tone_cannot_insert();
            return 0;
        }

        if (wChar == L'.' && m_currInputBinding->m_inputConnectionPtr->length() == 0)
        {
            m_currInputBinding->m_inputConnectionPtr->insertText(L'0', -1, -1);
        }

        VfxU32 ret = m_currInputBinding->m_inputConnectionPtr->insertText(wChar, newCursorPos, index);

        checkDecimal();

        return ret;
    }
    else
    {
        return m_currInputBinding->m_inputConnectionPtr->insertText(wChar, newCursorPos, index);
    }
    
}
extern "C"
{

    extern void mmi_imc_delete_all(void);
}
//#if defined __MMI_COSMOS_KEYPAD_BAR__ || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
void VadpInputServer::insert_sym_by_sympicker(VfxObject *object, VfxWChar sym)
{
       mmi_imc_insert_char_by_symbol_picker(sym);
}
//#endif
VfxBool VadpInputServer::dispatchKeyEvent(VfxKeyEvent &event) 
{

    if (!mmi_imc_is_connected())
    {
        return VFX_FALSE;
    }

    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

    if (inputServerUI->m_popupMenu != NULL)
    {
    if (inputServerUI->m_popupstate == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            #if !defined __MMI_COSMOS_KEYPAD_BAR__
			#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__) && defined(__COSMOS_MMI_PACKAGE__)
            if (mmi_imc_pen_get_curr_input_style() == MMI_IMC_PEN_INPUT_STYLE_HW && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
            {
                VfxBasePopup *popup = inputServerUI->m_popupMenu.get();
                ((VsrvInputMethodPopup*)popup)->confirmCurrentSelection();
            }
           #endif
           #endif
            inputServerUI->m_popupMenu->exit(VFX_TRUE);

            return VFX_TRUE;
        }
        else
        {
            return inputServerUI->m_popupMenu->processFocusKey(event); /* There is popup, IME doesn't process the key event */
        }
    }
        else
        {
            return VFX_TRUE;
        }
    }
    
    mmi_imc_state_enum preIMEState = mmi_imc_get_state();

    /* IME doesn't process special key, edtior will process */
    if ((event.keyCode == VFX_KEY_CODE_END) ||
        (event.keyCode == VFX_KEY_CODE_HOME) ||
        (event.keyCode == VFX_KEY_CODE_SEND) ||
        (event.keyCode == VFX_KEY_CODE_POWER)||
	    (event.keyCode == VFX_KEY_CODE_VOL_UP)||
        (event.keyCode == VFX_KEY_CODE_VOL_DOWN))
    {
        return VFX_FALSE;
    }

  if(event.keyCode == VFX_KEY_CODE_CLEAR)
    {
		if(!mmi_imc_is_ime_state())
        {
           return VFX_FALSE;
        }
    }
    
#if defined(__COSMOS_MMI__)
    if (event.keyCode == VFX_KEY_CODE_BACK || event.keyCode == VFX_KEY_CODE_FWD)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN && isIMEState())
        {
            mmi_imc_reset_ime_state();
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }
#endif

	m_currentKeyCode = event.keyCode;

	m_currentKeyType = event.type;
    
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)

    VFX_ASSERT(m_currentKeyFuncPtrs);

    if (event.keyCode == VFX_KEY_CODE_ENTER) /* Do the same remapping as keybrd.c */
    {
        if (*(m_currentKeyFuncPtrs + VFX_KEY_CODE_ENTER * MAX_KEY_TYPE + VFX_KEY_EVENT_TYPE_DOWN) == NULL && 
            *(m_currentKeyFuncPtrs + VFX_KEY_CODE_ENTER * MAX_KEY_TYPE + VFX_KEY_EVENT_TYPE_UP) == NULL && 
            *(m_currentKeyFuncPtrs + VFX_KEY_CODE_ENTER * MAX_KEY_TYPE + VFX_KEY_EVENT_TYPE_REPEAT) == NULL && 
            *(m_currentKeyFuncPtrs + VFX_KEY_CODE_ENTER * MAX_KEY_TYPE + VFX_KEY_EVENT_TYPE_LONG_PRESS) == NULL)
        {
            event.keyCode = VFX_KEY_CODE_LSK;
        }	 
    }
    
#if !defined(__COSMOS_MMI__)
    if (mmi_imc_key_routing_event_handler(event.keyCode, event.type, event.ucs2, event.specialKeyFlag))
    {
        return VFX_TRUE;
    }
#endif
#endif /* #if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
    
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	if(event.keyCode == VFX_KEY_CODE_ARROW_RIGHT
		|| event.keyCode == VFX_KEY_CODE_ARROW_LEFT
		|| event.keyCode == VFX_KEY_CODE_ARROW_UP
		|| event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
	{
		//editor will handle navigation keys if not ime state
		if(!mmi_imc_is_ime_state())
		{
		    return VFX_FALSE;
		}
	}
	if (event.keyCode != VFX_KEY_CODE_LSK
		&& event.keyCode != VFX_KEY_CODE_RSK
		&& event.keyCode != VFX_KEY_CODE_CSK
		&& event.keyCode != VFX_KEY_CODE_FWD
		&& event.keyCode != VFX_KEY_CODE_BACK)
	{
        VfxBool ret = VFX_FALSE;

        ret = (VfxBool)mmi_imc_key_qwerty_group_key_handler(event.keyCode, event.type, event.ucs2, event.specialKeyFlag);

        // if text highlight, should not append space
        VfxS32 h_start, h_end;
		if(m_currInputBinding)
		{
        m_currInputBinding->getConnection()->getSelection(&h_start, &h_end);
        VfxBool isTextHighlight = h_end - h_start > 0 ? VFX_TRUE : VFX_FALSE;
        if (!ret && !isIMEState() && !isTextHighlight &&
            event.keyCode == VFX_KEY_CODE_ARROW_RIGHT && 
            event.type == VFX_KEY_EVENT_TYPE_DOWN &&
            mmi_imc_is_append_one_more_space_input_mode(getCurrInputMode()))
        {
            InputConnection *connPtr = m_currInputBinding->getConnection();
            VfxWChar pre_c = 0, c = 0;
            
            VFX_ASSERT(connPtr);
            
            VfxWChar *textPtr = connPtr->getText();
            
            VfxWChar *cursorPtr = connPtr->getText() + connPtr->getCursorIndex();
            
            if (cursorPtr > textPtr)
            {
                pre_c = *(cursorPtr - 1);
            }
            
            c = *cursorPtr;
            
            if (c == 0 && pre_c != 0 && pre_c != L' ')
            {
#ifndef __MRE_SDK__
                UI_editor_disable_tones();
#endif
                VfxU32 retLen = m_currInputBinding->getConnection()->insertText((VfxWChar)L' ', -1);
#ifndef __MRE_SDK__        
                UI_editor_enable_tones();
#endif
                return (retLen > 0) ? VFX_TRUE : VFX_FALSE;
            }
        }
		}

        if (ret)
        {
            return MMI_TRUE;
        }
	}
	else
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
	{
        if (((event.keyCode >= VFX_KEY_CODE_LSK && event.keyCode <= VFX_KEY_CODE_CSK) ||
              event.keyCode == VFX_KEY_CODE_ENTER ||
              event.keyCode == VFX_KEY_CODE_FWD ||
              event.keyCode == VFX_KEY_CODE_BACK) && 
            !isIMEState())
        {
            return VFX_FALSE;
        }
    
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
            event.type == VFX_KEY_EVENT_TYPE_UP ||
            event.type == VFX_KEY_EVENT_TYPE_REPEAT ||
            event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
        {
            FuncPtr currentKeyHandler = *(m_currentKeyFuncPtrs + event.keyCode * MAX_KEY_TYPE + event.type); 
            
            if (currentKeyHandler)
            {
				#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
					if(mmi_imc_get_slider_status()== CLOSE)
					{
						mmi_imc_process_simulated_slider_event(OPEN);
					}
				#endif
                currentKeyHandler();
            }
        }
        else
        {
            return VFX_FALSE;
        }
	}

        // if text highlight, should not append space
        VfxS32 h_start, h_end;
	if(m_currInputBinding)
	{
        m_currInputBinding->getConnection()->getSelection(&h_start, &h_end);
        VfxBool isTextHighlight = h_end - h_start > 0 ? VFX_TRUE : VFX_FALSE;
        if ( !isIMEState() && !isTextHighlight &&
        event.keyCode == VFX_KEY_CODE_ARROW_RIGHT && 
        event.type == VFX_KEY_EVENT_TYPE_DOWN &&
        mmi_imc_is_append_one_more_space_input_mode(getCurrInputMode()))
    {
        InputConnection *connPtr = m_currInputBinding->getConnection();
        VfxWChar pre_c = 0, c = 0;

        VFX_ASSERT(connPtr);

        VfxWChar *textPtr = connPtr->getText();
        
        VfxWChar *cursorPtr = connPtr->getText() + connPtr->getCursorIndex();

        if (cursorPtr > textPtr)
        {
            pre_c = *(cursorPtr - 1);
        }

        c = *cursorPtr;

        if (c == 0 && pre_c != 0 && pre_c != L' ')
        {
#ifndef __MRE_SDK__
                UI_editor_disable_tones();
#endif
            VfxU32 retLen = m_currInputBinding->getConnection()->insertText((VfxWChar)L' ', -1);
#ifndef __MRE_SDK__        
                UI_editor_enable_tones();
#endif
            return (retLen > 0) ? VFX_TRUE : VFX_FALSE;
        }
    }
	}


	if (((event.keyCode >= VFX_KEY_CODE_LSK && event.keyCode <= VFX_KEY_CODE_CSK) || 
		  event.keyCode == VFX_KEY_CODE_FWD || event.keyCode == VFX_KEY_CODE_BACK ||
		 (event.keyCode >= VFX_KEY_CODE_ARROW_UP && event.keyCode <= VFX_KEY_CODE_ARROW_RIGHT)) && 
		!isIMEState() && preIMEState == mmi_imc_get_state())
	{
	    return VFX_FALSE;
	}
	else
	{
        return VFX_TRUE;
	}
}

VfxBool VadpInputServer::dispatchPenEvent(VfxPenEvent &event)	
{

#ifdef __MMI_COSMOS_KEYPAD_BAR__
		return VFX_FALSE;
#endif

#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
		if(mmi_imc_get_slider_status()== OPEN)
		{
			mmi_imc_process_simulated_slider_event(CLOSE);
		}
#endif

#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
if(mmi_imc_get_slider_status()==OPEN)
{
		return VFX_FALSE;
}
#endif

    if (!mmi_imc_is_connected())
    {
        return VFX_FALSE;
    }
    
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_point_struct pos = {event.pos.x, event.pos.y};
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            mmi_imc_pen_event_pen_down_in_editor(pos);
            break;
        case VFX_PEN_EVENT_TYPE_MOVE:
            mmi_imc_pen_event_pen_move_in_editor(pos);
            break;
        case VFX_PEN_EVENT_TYPE_UP:
            mmi_imc_pen_event_pen_up_in_editor(pos);
            break;
        case VFX_PEN_EVENT_TYPE_ABORT:
            mmi_imc_pen_event_pen_abort_in_editor(pos);
            break;
    }
#endif
    return VFX_FALSE;
}


void VadpInputServer::closepopup()
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

    if(inputServerUI->m_popupMenu != NULL)
    {
            inputServerUI->m_popupMenu->exit(VFX_TRUE);
    }

}

void VadpInputServer::override_autocap() 
{
    mmi_imc_config_auto_cap_flag(MMI_TRUE);
}

void VadpInputServer::disableSymbolPicker() 
{
    mmi_imc_disable_symbol_picker();
}

void VadpInputServer::enableSymbolPicker() 
{
    mmi_imc_enable_symbol_picker();
}

VfxBool VadpInputServer::getCharInfor(VfxWChar code, 
	VfxWChar *inforBuf, 
	VfxU32 bufSize, 
	mmi_imm_input_mode_enum mode) const
{
    if (mmi_imc_get_char_info((UI_character_type)code, 
		       (UI_string_type)inforBuf, 
		       (S32)bufSize,
		       mode))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }    
}

VfxBool VadpInputServer::isIMEState() const 
{
    if (mmi_imc_is_ime_state())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }    
}

void VadpInputServer::addNewWordsFromText(VfxWChar *text) 
{
    mmi_imc_scan_and_add_new_words((UI_string_type)text);
}

mmi_imm_input_mode_enum VadpInputServer::getCurrInputMode() const 
{
    return mmi_imm_get_curr_input_mode();
}

mmi_imm_input_type_enum VadpInputServer::getCurrInputType() const 
{
    return mmi_imm_get_curr_input_type();
}

mmi_imm_input_mode_enum* VadpInputServer::getCurrrUserSpecificInputModeList()
{
    return mmi_imm_get_curr_user_specific_input_mode_list();
}

void VadpInputServer::setInputModeSwitchable(VfxBool isSwitchable) 
{
    mmi_imm_config_change_input_mode((MMI_BOOL)isSwitchable);
}


VfxU32 VadpInputServer::getInputMethodHistorySize() const
{
    if (!mmi_imc_is_connected())
    {
        return 0;
    }

    return (VfxU32)sizeof(mmi_imc_history);
}


void VadpInputServer::getInputMethodHistory(void *historyAddress)
{
    if (!mmi_imc_is_connected())
    {
        return;
    }
    mmi_imc_get_input_method_history((mmi_imc_history_p)historyAddress);
}


void VadpInputServer::setInputMethodHistory(void *historyAddress)
{
	mmi_imc_set_input_method_history((mmi_imc_history_p)historyAddress);
}


void VadpInputServer::enableAutoCapInHistory(void *historyAddress)
{
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    ((mmi_imc_history_p)historyAddress)->skip_auto_cap_first_filter = MMI_TRUE;
#endif
}


void VadpInputServer::showSoftInput()
{

#ifdef __MMI_COSMOS_KEYPAD_BAR__
	return ;
#endif

#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
	return ;
#endif

#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
if(mmi_imc_get_slider_status()==OPEN)
{
		return ;
}
#endif

    if (!mmi_imc_is_connected())
    {
        return;
    }

#if defined(__MMI_TOUCH_SCREEN__)
    if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_VK)
    {
        return;
    }
#endif

    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
        return;
    }

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
    
#if !defined(__NO_HANDWRITING__)
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
    {
		mmi_imc_pen_vk_enable_single_block_hw();
    }
#endif

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_redraw_screen_by_state();
#endif
}

void VadpInputServer::hideSoftInput()
{
    if (!mmi_imc_is_connected())
    {
        return;
    }
    
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_pen_vk_hide();
    mmi_imc_redraw_screen_by_state();
#endif
}


VfxBool VadpInputServer::isSoftInputVisible()
{
    if (!mmi_imc_is_connected())
    {
        return VFX_FALSE;
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    if (mmi_imc_get_current_imui_height_skip_fixed_editor() > 0 &&
        mmi_imc_get_vk_area_height() > 0)
    {
        return VFX_TRUE;
    }
    else
#endif
    {
        return VFX_FALSE;
    }
}


VfxS32 VadpInputServer::isValidInputString(VfxWChar *string, VfxS32 len)
{
    if (!mmi_imc_is_connected())
    {
        return 0;
    }
    
    S32 valid_len = 0;
    MMI_BOOL is_valid = MMI_FALSE;

    mmi_imm_test_input_ext((UI_string_type)string, (S32)len, &is_valid, &valid_len);

    return (VfxS32)valid_len;
}

VfxBool VadpInputServer::isValidInputStringForPaste(VfxWChar *string, VfxS32 len)
{
    if (!mmi_imc_is_connected())
    {
        return 0;
    }

   return mmi_imm_test_paste((UI_string_type)string, (S32)len) ? VFX_TRUE : VFX_FALSE;
}



void VadpInputServer::cursorPosChanged(VfxRect &cursorRect)
{
    m_signalCursorPosChanged.postEmit();
}


VfxBool VadpInputServer::isInputMethodUIControl(VfxControl *control)
{
    if (!mmi_imc_is_connected())
    {
        return VFX_FALSE;
    }
    
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 
    
    return inputServerUI->isIMUIControl(control);
}


void VadpInputServer::beforeRotate()
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI);

    inputServerUI->beforeRotate();
}


void VadpInputServer::rotate()
{
    if (!mmi_imc_is_connected())
    {
        return;
    }

    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI);

    if (inputServerUI->m_popupMenu != NULL)
    {
        inputServerUI->m_popupMenu->exit(VFX_TRUE);
    }
    
    mmi_imc_check_rotation();

    inputServerUI->rotate();
    
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
    if ((mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING) || (mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING))
    {
        mmi_imc_cancel_timer();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
    }

    mmi_imc_pen_stop_singleblock_handwriting();
#endif

    mmi_imc_reset_ime_state();
  // special case for MAUI_02453421 + MAUI_02742622
    
#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_IME_FTE_ENHANCE__)   && defined(__MMI_VIRTUAL_KEYBOARD__)
    MMI_BOOL isVkOn = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
    mmi_imc_pen_set_history_is_vk_enlarge(isVkOn);
#endif
    /* set event handlers as per new keyboard */
    mmi_imc_pen_activate();
#endif

    mmi_imc_redraw_screen_by_state();
}


void VadpInputServer::setSpecialEnterKey(VfxBool isEnabled)
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI);

    inputServerUI->setSpecialEnterKey(isEnabled);
}

void VadpInputServer::resetIMEState()
{
    mmi_imc_reset_ime_state();
}


U32 VadpInputServer::plutoImeMsgCallBcak(void * inputHandle, mmi_imc_message_struct_p msgPtr)
{
    VadpInputServer *thisPtr = (VadpInputServer *)inputHandle;
	InputConnection *connPtr = NULL;
    VfxU32 lresult = 0;

	VFX_ASSERT(thisPtr->m_currInputBinding);

	connPtr = (InputConnection *)thisPtr->m_currInputBinding->getConnection();

	VFX_ASSERT(connPtr);

	switch (msgPtr->message_id)
	{
    case MMI_IMC_MESSAGE_INSERT_STRING:
	case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:
		lresult = connPtr->insertText((VfxWChar *)msgPtr->param_0, -1);
		break;
		
    case MMI_IMC_MESSAGE_INSERT_CHAR:
		
		lresult = (VfxU32)thisPtr->insertCharWrapper((VfxWChar)msgPtr->param_0, -1);
		break;
		
    case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
		
		connPtr->insertText(0x000A, -1);
		break;
		
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        {
		    VfxWChar string[2];
		    
		    string[0] = (VfxWChar)msgPtr->param_0;
		    string[1] = 0;

		    if (connPtr->setMarkedText(string, 0, 1, -1) > 0)
            {
                thisPtr->m_isMultitapState = VFX_TRUE;
		        lresult = VFX_TRUE;
		    }
        }
		break;
		
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:
        {
            VfxU32 strLen = vfx_sys_wcslen((const VfxWChar *)msgPtr->param_0);
            
            if (strLen > 0)
            {
                if (connPtr->setMarkedText((VfxWChar *)msgPtr->param_0, 0, strLen, -1))
                {
                    thisPtr->m_isMultitapState = VFX_TRUE;
                    lresult = VFX_TRUE;
                }
            }
        }
        
		break;
		
    case MMI_IMC_MESSAGE_DELETE_CHAR:
    case MMI_IMC_MESSAGE_DELETE_STRING:

		connPtr->deleteAtCursor((VfxS32)msgPtr->param_0, 0);
        thisPtr->checkDecimal();

		break;
		
    case MMI_IMC_MESSAGE_CLEAR_ALL:
		connPtr->clear();
        thisPtr->checkDecimal();
		break;
		
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
		connPtr->finishMarkedText();
		break;
		
    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msgPtr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                connPtr->moveCursorByLine(-((S32)msgPtr->param_1));
                break;
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                connPtr->moveCursorByLine((S32)msgPtr->param_1);
                break;
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                connPtr->moveCursorByChar(-((S32)msgPtr->param_1));
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                connPtr->moveCursorByChar((S32)msgPtr->param_1);
                break;
        }
        
		break;
		
    case MMI_IMC_MESSAGE_HILIGHT_BFCURSOR:
		VFX_ASSERT(0); // Not use in Venus
		break;
		
    case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
        ((mmi_imc_rect_p)msgPtr->param_0)->x = 0;
        ((mmi_imc_rect_p)msgPtr->param_0)->y = 0;
        ((mmi_imc_rect_p)msgPtr->param_0)->width = 0;
        ((mmi_imc_rect_p)msgPtr->param_0)->height = 0;
		break;
		
    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
		lresult = MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK; 
		break;
		
    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
		connPtr->finishMarkedText();
        thisPtr->m_isMultitapState = VFX_FALSE;
		break;
		
    case MMI_IMC_MESSAGE_GET_TEXT_LENGTH:
        lresult = connPtr->length();
        break;
		
    case MMI_IMC_MESSAGE_MODE_CHANGED: 
        connPtr->sendIMENotification(IME_NOTIFICATION_INPUT_MODE_CHANGED, NULL);
		break;
		
    case MMI_IMC_MESSAGE_CHANGE_TO_INITIAL:
        connPtr->sendIMENotification(IME_NOTIFICATION_BACK_TO_INITIAL_STATE, NULL);
		break;

    case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
        return connPtr->sendIMENotification(IME_NOTIFICATION_QUERY_CLIENT_SSP_STATE, NULL);


    case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
		if (connPtr->length() == 0)
		{
		    lresult = VFX_TRUE;
		}
		else
		{
		    lresult = VFX_FALSE;
		}
		break;
    case MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY: // Quick search editor need return true in this message
        if (thisPtr->m_currInputBinding->m_inputType & IMM_INPUT_TYPE_QUICK_SEARCH)
        {
            lresult = VFX_TRUE;
        }
        else
        {
            lresult = VFX_FALSE;
        }
		break;
    case MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR:
        {
            VfxS32 start = 0, end = 0, length = 0;

            connPtr->getSelection(&start, &end);

            length = end - start;
            
            if (connPtr->getCursorIndex() - length > 0)
            {
                *((VfxWChar *)msgPtr->param_0) = *(connPtr->getText() + connPtr->getCursorIndex() - length - 1);

                lresult = VFX_TRUE;
            }
            else if(connPtr->getCursorIndex() - length == 0)
            {
                *((VfxWChar *)msgPtr->param_0) = 0;
                lresult = VFX_TRUE;
            }
            else
            {
                lresult = VFX_FALSE;
            }
        }
		break;
    case MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE:
        {
            VfxS32 start = 0, end = 0, length = 0;

            connPtr->getSelection(&start, &end);
            
            if (end - start > 0)
            {
                lresult = VFX_TRUE;
            }
            else
            {
                lresult = VFX_FALSE;
            }
        }
        break;
    case MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE:
        {
            VfxS32 start = 0, end = 0, selectionLength = 0;

            connPtr->getSelection(&start, &end);

            selectionLength = end - start;

            UI_string_type buf = (UI_string_type)msgPtr->param_1;

            VfxS32 i;

            for (i = 0; i < (VfxS32)msgPtr->param_0; i++)
            {
                buf[i] = connPtr->getCharBeforeCursor(i + selectionLength+1, 0, NULL);

                if (buf[i] == 0)
                {
		            break;
                }
            }

            if (buf[i] != 0)
            {
                buf[i] = 0;
            }
        }
		break;
    
    case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
        thisPtr->insertCharWrapper((VfxWChar)msgPtr->param_1, -1, (VfxS32)msgPtr->param_0);
		break;
    case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
        connPtr->deleteChars((VfxS32)msgPtr->param_0, (VfxS32)msgPtr->param_0 + 1);
		break;
    case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
        lresult = (VfxU32)((VfxWChar)*(connPtr->getText() + (VfxS32)msgPtr->param_0));
		break;
    case MMI_IMC_MESSAGE_CHECK_FLOAT:
        
        thisPtr->checkDecimal();

        lresult = (thisPtr->m_decimalFlag == VFX_TRUE) ? 1 : 0;
        
		break;
    case MMI_IMC_MESSAGE_DECIAML_CHECK:
        thisPtr->checkDecimal();
		break;
    case MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL:
        thisPtr->insertCharWrapper(L'.', -1);
		break;
		
    case MMI_IMC_MESSAGE_INSERT_SPACE:
		connPtr->insertText(0x0020, -1);
		break;
		
    case MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE:
        if (thisPtr->m_currInputBinding->m_inputStyleFlags & IME_INPUT_STYLE_NO_SOFTKEYS)
        {
		    lresult = VFX_TRUE;
		}
		else
		{
		    lresult = VFX_FALSE;
		}
		break;
    
    case MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE:
        lresult = (VfxU32)thisPtr->m_isMultitapState;
		break;
    
    case MMI_IMC_MESSAGE_WCSS_CHECK:
        if (thisPtr->m_currInputBinding->m_inputStyleFlags & IME_INPUT_STYLE_WCSS)
        {
		    lresult = VFX_TRUE;
		}
		else
		{
		    lresult = VFX_FALSE;
		}
		break;
	case MMI_IMC_MESSAGE_IS_LAST_POSITION:
        lresult = VFX_FALSE;
		break;
    case MMI_IMC_MESSAGE_IS_OVERWRITE_MODE:
        lresult = VFX_FALSE;
		break;
        
    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE:
        {
            VfxS32 start = 0, end = 0;

            connPtr->getSelection(&start, &end);
            
            *((U8 **)(msgPtr->param_0)) = (U8 *)connPtr->getText();
            *((U8 **)(msgPtr->param_1)) = (U8 *)connPtr->getText() + ENCODING_LENGTH * (connPtr->getCursorIndex() - (end - start));
        }
        break;
        
    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR:
        *((U8 **)(msgPtr->param_0)) = (U8 *)connPtr->getText();
        *((U8 **)(msgPtr->param_1)) = (U8 *)connPtr->getText() + ENCODING_LENGTH * connPtr->getCursorIndex(VFX_TRUE);
        break;
        
	case MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED:
        lresult = VFX_FALSE;
		break;
    case MMI_IMC_MESSGAE_GET_EXT_INPUT_BOX_RECT:
        lresult = VFX_FALSE;
		break;
   
	case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:
        {
            VfxU32 strLen = vfx_sys_wcslen((const VfxWChar *)msgPtr->param_1);

            lresult = connPtr->setMarkedText((VfxWChar *)msgPtr->param_1, 0, strLen, -1);
        }
		break;
	
	case MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD:
        {
            VfxS32 start = 0, end = 0;

            connPtr->getSelection(&start, &end);

            if (end - start > 0)
            {
                *((UI_buffer_type *)(msgPtr->param_0)) = (UI_buffer_type)(connPtr->getText() + start);
                *((UI_buffer_type *)(msgPtr->param_1)) = (UI_buffer_type)(connPtr->getText() + end);
                
                lresult = end - start;
            }
            else
            {
                *((UI_buffer_type *)(msgPtr->param_0)) = 0;
                *((UI_buffer_type *)(msgPtr->param_1)) = 0;
                lresult = 0;
            }
            
        }
		break;
    case MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED:
		lresult = MMI_FALSE;
		break;
    case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
		
		if (connPtr->insertText((VfxWChar *)(L"()"), -1) == 2)
		{
		    // TODO: Move cursor to left
		    lresult = VFX_TRUE;
		}
		else
		{
		    lresult = VFX_FALSE;
		}
		break;
		
    case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
        lresult = VFX_FALSE;
		break;

    case MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE:
        {
            VfxS32 start = 0, end = 0;

            connPtr->getSelection(&start, &end);

            if (end - start > 0)
            {
                lresult = VFX_TRUE;
            }
            else
            {
                lresult = VFX_FALSE;
            }
        }
		break;

    case MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH:
        lresult = 0;
		break;

    case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:
    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
    case MMI_IMC_MESSAGE_KEY_EVENT:
    case MMI_IMC_MESSAGE_PEN_EVENT: 
    case MMI_IMC_MESSAGE_GET_TEXT:
    case MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START: // Don't need to handle in COSMOS
    case MMI_IMC_MESSAGE_GET_CURSOR_RECT: // Don't need to handle in Venus IMUI
        VFX_ASSERT(0); // Not use in Venus
		break;

    case MMI_IMC_MESSAGE_RESIZE:
    case MMI_IMC_MESSAGE_MOVE:
    case MMI_IMC_MESSAGE_REDRAW:
    case MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX:
    case MMI_IMC_MESSAGE_SET_KEY:
    case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
    case MMI_IMC_MESSAGE_SET_MASK:
    case MMI_IMC_MESSAGE_DECIMAL_INPUT:
    case MMI_IMC_MESSAGE_DRAW_INFORMATION_BAR:
    case MMI_IMC_MESSAGE_DRAW_IME_HINT:
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
    case MMI_IMC_MESSAGE_START_SMART_ALPHABETIC:
    case MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC:
    case MMI_IMC_MESSAGE_IS_THERE_CURSOR:
    case MMI_IMC_MESSAGE_VK_HIDE:
    case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
    case MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW:
    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
    case MMI_IMC_MESSAGE_GET_STOP_CURSOR_CALLBACK_FUNCPTR:
    case MMI_IMC_MESSAGE_GET_START_CURSOR_CALLBACK_FUNCPTR:
    case MMI_IMC_MESSAGE_IS_SKIP_GENERAL_PEN_UP_EVENT:
        // Don't need to handle in Venus
		break;

	default:
		break;
    }

	return (U32)lresult;
}


void VadpInputServer::applyInputSettings()
{
    if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_CANDIDATE_BOX)
    {
        mmi_imc_set_is_disable_candidate_box(MMI_TRUE);
    }
    else
    {
        mmi_imc_set_is_disable_candidate_box(MMI_FALSE);
    }

    if (m_currInputBinding->m_inputSettingFlags & IME_JAVA_SPECIAL_SYMBOL)
    {
        mmi_imc_set_is_java_special_symbol_enabled(MMI_TRUE);
    }
    else
    {
        mmi_imc_set_is_java_special_symbol_enabled(MMI_FALSE);
    }
    
	if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_KEY_INPUT)
	{
	    mmi_imc_disable_key_input();
	}

#if defined(__MMI_TOUCH_SCREEN__)
	if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_HANDWRITING)
	{
	    mmi_imc_disable_handwriting();
	}
	
	if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_VK)
	{
	    mmi_imc_disable_virtual_keyboard();
	}
#endif

    ::MMI_current_input_ext_type = 0;

    if (m_currInputBinding->m_inputSettingFlags & IME_DISABLE_NEW_LINE_SYMBOL)
    {
        ::MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }

    if (m_currInputBinding->m_inputSettingFlags & IME_ALLOWED_CHARACTER_LIST)
    {
        mmi_imm_set_characters(MMI_TRUE, (const UI_character_type *)m_currInputBinding->getAllowedChars());
    }
	else if (m_currInputBinding->m_inputSettingFlags & IME_DISABLED_CHARACTER_LIST)
	{
        mmi_imm_set_characters(MMI_FALSE, (const UI_character_type *)m_currInputBinding->getDisabledChars());
    }

    if (mmi_imm_get_default_input_mode() == IMM_INPUT_MODE_NONE &&
        m_currInputBinding->m_appDesiredFirstInputMode != IMM_INPUT_MODE_NONE &&
        m_currInputBinding->m_appDesiredFirstInputMode != IMM_INPUT_MODE_MAX_NUM)
    {
        mmi_imm_set_app_desired_input_mode(m_currInputBinding->m_appDesiredFirstInputMode);
    }

#if defined(__MMI_TOUCH_SCREEN__)
	if (m_currInputBinding->m_inputSettingFlags & IME_ALLOWED_EVENT_LIST)
	{
	    gui_virtual_keyboard_pen_enum vkEventList[VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM] = {GUI_VKBD_PEN_NONE};

		convertInputEventsToVKEvents(m_currInputBinding->getAllowedEvents(), &vkEventList[0]);

		if (vkEventList[0] != GUI_VKBD_PEN_NONE)
		{
	    	mmi_imm_set_events(MMI_TRUE, &vkEventList[0]);
		}
	}
	else if (m_currInputBinding->m_inputSettingFlags & IME_DISABLED_EVENT_LIST)
	{
	    gui_virtual_keyboard_pen_enum vkEventList[VSRV_INPUT_MANAGER_MAX_DISABLED_EVENT_NUM] = {GUI_VKBD_PEN_NONE};

		convertInputEventsToVKEvents(m_currInputBinding->getDisabledEvents(), &vkEventList[0]);

		if (vkEventList[0] != GUI_VKBD_PEN_NONE)
		{
	    	mmi_imm_set_events(MMI_FALSE, &vkEventList[0]);
		}
	}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */

#if defined(__MMI_FTE_SUPPORT__) || defined(__COSMOS_MMI__)
    mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif
}


void VadpInputServer::setKeyHandler(FuncPtr funcPtr, VfxU16 keyCode, VfxU16 keyType)
{
    VFX_ASSERT(m_currentKeyFuncPtrs);

    VFX_ASSERT(keyCode < MAX_KEYS && keyType < MAX_KEY_TYPE);
    
    *(m_currentKeyFuncPtrs + keyCode * MAX_KEY_TYPE + keyType) = funcPtr;
}


FuncPtr VadpInputServer::getKeyHandler(VfxU16 keyCode, VfxU16 keyType)
{
    VFX_ASSERT(m_currentKeyFuncPtrs);

    VFX_ASSERT(keyType < MAX_KEY_TYPE);
    
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    VFX_ASSERT(keyCode < MAX_KEYS);
#else
    VFX_ASSERT(keyCode < MAX_QWERTY_KEYS);
    if (keyCode >= MAX_KEYS)
    {
        /* There are no key handlers for qwerty keys, so NULL is returned */
        return NULL;
    }
    else
#endif    
    {
        return *(m_currentKeyFuncPtrs + keyCode * MAX_KEY_TYPE + keyType);
    }
}


void VadpInputServer::clearKeyHandler(VfxU16 keyCode, VfxU16 keyType)
{
    *(m_currentKeyFuncPtrs + keyCode * MAX_KEY_TYPE + keyType) = NULL;
}


void VadpInputServer::getCurrentKeyInfo(VfxU16 *keyCode, VfxU16 *keyType)
{
    *keyCode = m_currentKeyCode;
    *keyType = m_currentKeyType;
}


void VadpInputServer::setGroupKeyHandler(FuncPtr funcPtr, VfxU16 *keyCodes, VfxU8 len, VfxU16 keyType)
{
    VfxU8 count;
    MMI_ASSERT((len <= MAX_KEYS) && (keyType < MAX_KEY_TYPE));

    for (count = 0; count < len; count++)
    {
        setKeyHandler(funcPtr, keyCodes[count], keyType);
    }
}



#if defined(__MMI_TOUCH_SCREEN__)
void VadpInputServer::convertInputEventsToVKEvents(const IMEInputEventEnum *inputEventsList, gui_virtual_keyboard_pen_enum *vkEventList)
{
    VfxU32 i;

	for (i = 0; inputEventsList[i] != IME_INPUT_EVENT_NONE; i++)
	{
		VFX_ASSERT(i < VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM);
		
		vkEventList[i] = mapInputEventToVKEvent(inputEventsList[i]);

		if (vkEventList[i] == GUI_VKBD_PEN_NONE)
		{
		    break;
		}
	}

	vkEventList[i] = GUI_VKBD_PEN_NONE;
}

gui_virtual_keyboard_pen_enum VadpInputServer::mapInputEventToVKEvent(IMEInputEventEnum inputEvent)
{
    switch (inputEvent)
	{
	case IME_INPUT_EVENT_HIDE:
		return GUI_VKBD_PEN_HIDE;

		
	case IME_INPUT_EVENT_SHOW:
		return GUI_VKBD_PEN_SHOW;

		
	case IME_INPUT_EVENT_CAPSLOCK:
		return GUI_VKBD_PEN_CAPSLOCK;

		
	case IME_INPUT_EVENT_SPACE:
		return GUI_VKBD_PEN_SPACE;

		
	case IME_INPUT_EVENT_BAKSPACE:
		return GUI_VKBD_PEN_BAKSPACE;

		
	case IME_INPUT_EVENT_SYMBPICKER:
		return GUI_VKBD_PEN_SYMBPICKER;

		
	case IME_INPUT_EVENT_BRACKET:
		return GUI_VKBD_PEN_BRACKET;

		
	case IME_INPUT_EVENT_NEWLINE:
		return GUI_VKBD_PEN_NEWLINE;

		
	case IME_INPUT_EVENT_EUROSYMB:
		return GUI_VKBD_PEN_EUROSYMB;

		
	case IME_INPUT_EVENT_DISPLAY_CALLBACK:

		return GUI_VKBD_PEN_DISPLAY_CALLBACK;

		
	default:
		return GUI_VKBD_PEN_NONE;

	}


}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


/***************************************************************************** 
 * Class VadpInputServerUI
 *****************************************************************************/
#if defined(__MMI_IME_FTE_ENHANCE__)
#define SINGLE_BLOCK_BOTTOM_GAP          0
#define SINGLE_BLOCK_TOP_GAP             0

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#define SINGLE_BLOCK_AND_STROKE_AREA_GAP          2
#endif


#if defined(__MMI_MAINLCD_240X400__)
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #define SINGLE_BLOCK_HEIGHT 162
    #define SINGLE_BLOCK_WIDTH 203
    #define SINGLE_BLOCK_LEFT_GAP            1
    #define SINGLE_BLOCK_RIGHT_GAP           1
    #define SINGLE_BLOCK_X 0
    #define SINGLE_BLOCK_Y 0
    #define SINGLE_BLOCK_HEIGHT_ROTATED 116
    #define SINGLE_BLOCK_WIDTH_ROTATED 319
    #define SINGLE_BLOCK_X_ROTATED 0
    #define SINGLE_BLOCK_Y_ROTATED 0
#else
    #define SINGLE_BLOCK_HEIGHT  179
    #define SINGLE_BLOCK_WIDTH  160
    #define SINGLE_BLOCK_LEFT_GAP            0
    #define SINGLE_BLOCK_RIGHT_GAP           0
    #define SINGLE_BLOCK_X 40
    #define SINGLE_BLOCK_Y 221

    #define SINGLE_BLOCK_HEIGHT_ROTATED 122
    #define SINGLE_BLOCK_WIDTH_ROTATED 255
    #define SINGLE_BLOCK_X_ROTATED 72
    #define SINGLE_BLOCK_Y_ROTATED 118

#endif
    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH 85
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT 90
    #define SINGLE_BLOCK_EXTRA_BLOCK_X 120
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y 77
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X 108
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y 131

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED 85
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED 86
    #define SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED 234
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED 30
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED 222
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED 83

#elif defined(__MMI_MAINLCD_240X320__)
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #define SINGLE_BLOCK_HEIGHT 159
    #define SINGLE_BLOCK_WIDTH 203
    #define SINGLE_BLOCK_X 0
    #define SINGLE_BLOCK_Y 0
    #define SINGLE_BLOCK_LEFT_GAP            1
    #define SINGLE_BLOCK_RIGHT_GAP           1
    #define SINGLE_BLOCK_HEIGHT_ROTATED 116
    #define SINGLE_BLOCK_WIDTH_ROTATED 271
    #define SINGLE_BLOCK_X_ROTATED 0
    #define SINGLE_BLOCK_Y_ROTATED 0


#else
    #define SINGLE_BLOCK_HEIGHT 143
    #define SINGLE_BLOCK_WIDTH 160
    #define SINGLE_BLOCK_X   40
    #define SINGLE_BLOCK_Y    177
    #define SINGLE_BLOCK_LEFT_GAP            0
    #define SINGLE_BLOCK_RIGHT_GAP           0
    #define SINGLE_BLOCK_HEIGHT_ROTATED   122
    #define SINGLE_BLOCK_WIDTH_ROTATED  204
    #define SINGLE_BLOCK_X_ROTATED  58
    #define SINGLE_BLOCK_Y_ROTATED  118

#endif

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH 80
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT 80
    #define SINGLE_BLOCK_EXTRA_BLOCK_X 122
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y 76
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X 108
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y 128

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED 85
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED 86
    #define SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED 186
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED 30
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED 174
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED 83
#elif defined(__MMI_MAINLCD_320X240__)


#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #define SINGLE_BLOCK_HEIGHT 116
    #define SINGLE_BLOCK_WIDTH 319
    #define SINGLE_BLOCK_X 0
    #define SINGLE_BLOCK_Y 0
    #define SINGLE_BLOCK_LEFT_GAP            1
    #define SINGLE_BLOCK_RIGHT_GAP           1
    #define SINGLE_BLOCK_HEIGHT_ROTATED 162
    #define SINGLE_BLOCK_WIDTH_ROTATED 203
    #define SINGLE_BLOCK_X_ROTATED 0
    #define SINGLE_BLOCK_Y_ROTATED 0


#else
/* get from vk data */
    #define SINGLE_BLOCK_HEIGHT 160
    #define SINGLE_BLOCK_WIDTH 144
    #define SINGLE_BLOCK_X   48
    #define SINGLE_BLOCK_Y    161
    #define SINGLE_BLOCK_LEFT_GAP            0
    #define SINGLE_BLOCK_RIGHT_GAP           0
    #define SINGLE_BLOCK_HEIGHT_ROTATED   120
    #define SINGLE_BLOCK_WIDTH_ROTATED  192
    #define SINGLE_BLOCK_X_ROTATED  64
    #define SINGLE_BLOCK_Y_ROTATED  121

#endif


#define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH 85
#define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT 86
#define SINGLE_BLOCK_EXTRA_BLOCK_X 234
#define SINGLE_BLOCK_EXTRA_BLOCK_Y 30
#define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X 222
#define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y 83

#define SINGLE_BLOCK_HEIGHT_ROTATED 162
#define SINGLE_BLOCK_WIDTH_ROTATED 203
#define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED 85
#define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED 90
#define SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED 120
#define SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED 77
#define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED 108
#define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED 131

#elif defined(__MMI_MAINLCD_320X480__)   

#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #define SINGLE_BLOCK_HEIGHT 205
    #define SINGLE_BLOCK_WIDTH 271
    #define SINGLE_BLOCK_X 0
    #define SINGLE_BLOCK_Y 0
    #define SINGLE_BLOCK_LEFT_GAP            1
    #define SINGLE_BLOCK_RIGHT_GAP           1
    #define SINGLE_BLOCK_HEIGHT_ROTATED 150
    #define SINGLE_BLOCK_WIDTH_ROTATED 383
    #define SINGLE_BLOCK_X_ROTATED 0
    #define SINGLE_BLOCK_Y_ROTATED 0
#else
    #define SINGLE_BLOCK_HEIGHT 215
    #define SINGLE_BLOCK_WIDTH 214
    #define SINGLE_BLOCK_X   53
    #define SINGLE_BLOCK_Y   265
    #define SINGLE_BLOCK_LEFT_GAP            0
    #define SINGLE_BLOCK_RIGHT_GAP           0
    #define SINGLE_BLOCK_HEIGHT_ROTATED   163
    #define SINGLE_BLOCK_WIDTH_ROTATED   306
    #define SINGLE_BLOCK_X_ROTATED 87
    #define SINGLE_BLOCK_Y_ROTATED  157
#endif

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH 114
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT 114
    #define SINGLE_BLOCK_EXTRA_BLOCK_X 158
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y 92
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X 144
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y 169

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED 114
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED 114
    #define SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED 270
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED 37
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED 255
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED 114
    
#elif defined(__MMI_MAINLCD_480X800__)   

#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #define SINGLE_BLOCK_HEIGHT 347
    #define SINGLE_BLOCK_WIDTH 408
    #define SINGLE_BLOCK_X 0
    #define SINGLE_BLOCK_Y 0
    #define SINGLE_BLOCK_LEFT_GAP            1
    #define SINGLE_BLOCK_RIGHT_GAP           1
    #define SINGLE_BLOCK_HEIGHT_ROTATED 225
    #define SINGLE_BLOCK_WIDTH_ROTATED 640
    #define SINGLE_BLOCK_X_ROTATED 0
    #define SINGLE_BLOCK_Y_ROTATED 0
#else
    #define SINGLE_BLOCK_HEIGHT 358
    #define SINGLE_BLOCK_WIDTH  321
    #define SINGLE_BLOCK_X 80
    #define SINGLE_BLOCK_Y 442
    #define SINGLE_BLOCK_LEFT_GAP            0
    #define SINGLE_BLOCK_RIGHT_GAP           0
    #define SINGLE_BLOCK_HEIGHT_ROTATED 244
    #define SINGLE_BLOCK_WIDTH_ROTATED 510
    #define SINGLE_BLOCK_X_ROTATED 145
    #define SINGLE_BLOCK_Y_ROTATED 236
#endif
 

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH 168
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT 190
    #define SINGLE_BLOCK_EXTRA_BLOCK_X 235
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y 153
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X 218
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y 294

    #define SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED 187
    #define SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED 187
    #define SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED 450
    #define SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED 36
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED 445
    #define SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED 172

#else
    #error "This resolution doesn't support FTE" 
#endif

#endif /* defined(__MMI_IME_FTE_ENHANCE__) */


#ifdef __MMI_IME_FTE_ENHANCE__
#define VIRTUAL_KEYBOARD_BOTTOM_GAP    0
#define VIRTUAL_KEYBOARD_TOP_GAP       0
#else
#define VIRTUAL_KEYBOARD_BOTTOM_GAP    1
#define VIRTUAL_KEYBOARD_TOP_GAP       1
#endif

#define SELECTION_AREA_VER_GAP         3
#define INPUT_AREA_VER_GAP             3

#ifdef __MMI_IME_FTE_ENHANCE__
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        #define SELECTION_AREA_WIDTH   232 /* Including the frame */
    #elif defined(__MMI_MAINLCD_320X480__)
#if defined(__MMI_CSTAR_PHRASE_INPUT__)
        #define SELECTION_AREA_WIDTH   320 /* Including the frame */
#else
        #define SELECTION_AREA_WIDTH   300 /* Including the frame */
#endif
#elif defined(__MMI_MAINLCD_320X240__)
#define SELECTION_AREA_WIDTH   232 /* Including the frame */
    #elif defined(__MMI_MAINLCD_480X800__)
        #define SELECTION_AREA_WIDTH   440 /* Including the frame */
    #else
        #error "This resolution doesn't support FTE" 
    #endif
#endif



#ifdef __MMI_IME_FTE_ENHANCE__
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        #define CANDIDATE_BOX_LEFT_GAP     ((240 - SELECTION_AREA_WIDTH) / 2)
        #define CANDIDATE_BOX_RIGHT_GAP    ((240 - SELECTION_AREA_WIDTH) / 2)
#elif defined(__MMI_MAINLCD_320X240__)
#define CANDIDATE_BOX_LEFT_GAP     ((240 - SELECTION_AREA_WIDTH) / 2)
#define CANDIDATE_BOX_RIGHT_GAP    ((240 - SELECTION_AREA_WIDTH) / 2)
    #elif defined(__MMI_MAINLCD_320X480__)
        #define CANDIDATE_BOX_LEFT_GAP     ((320 - SELECTION_AREA_WIDTH) / 2)
        #define CANDIDATE_BOX_RIGHT_GAP    ((320 - SELECTION_AREA_WIDTH) / 2)
    #elif defined(__MMI_MAINLCD_480X800__)
        #define CANDIDATE_BOX_LEFT_GAP     ((480 - SELECTION_AREA_WIDTH) / 2)
        #define CANDIDATE_BOX_RIGHT_GAP    ((480 - SELECTION_AREA_WIDTH) / 2)
    #else
        #error "This resolution doesn't support FTE" 
    #endif

    #define CANDIDATE_BOX_TOP_GAP      0
    #define CANDIDATE_BOX_BOTTOM_GAP   4
#else
#define CANDIDATE_BOX_TOP_GAP          1
#define CANDIDATE_BOX_BOTTOM_GAP       1
#define CANDIDATE_BOX_LEFT_GAP         1
#define CANDIDATE_BOX_RIGHT_GAP        1
#endif

#ifdef __MMI_IME_FTE_ENHANCE__
#define CANDIDATE_BOX_INTER_BORDER_WIDTH    1  
#define CANDIDATE_BOX_EXTER_BORDER_WIDTH    3  /* The highlight frame */
#else
#define CANDIDATE_BOX_INTER_BORDER_WIDTH    1  
#define CANDIDATE_BOX_EXTER_BORDER_WIDTH    0  /* No exter highlight frame */
#endif

#define CANDIDATE_BOX_BORDER_WIDTH (CANDIDATE_BOX_INTER_BORDER_WIDTH + CANDIDATE_BOX_EXTER_BORDER_WIDTH)

#ifdef __MMI_IME_FTE_ENHANCE__
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        #define COMPOSITION_BOX_LEFT_GAP     ((240 - SELECTION_AREA_WIDTH) / 2)
        #define COMPOSITION_BOX_RIGHT_GAP    ((240 - SELECTION_AREA_WIDTH) / 2)
    #elif defined(__MMI_MAINLCD_320X480__)
        #define COMPOSITION_BOX_LEFT_GAP     ((320 - SELECTION_AREA_WIDTH) / 2)
        #define COMPOSITION_BOX_RIGHT_GAP    ((320 - SELECTION_AREA_WIDTH) / 2)
    #elif defined(__MMI_MAINLCD_480X800__)
        #define COMPOSITION_BOX_LEFT_GAP     ((480 - SELECTION_AREA_WIDTH) / 2)
        #define COMPOSITION_BOX_RIGHT_GAP    ((480 - SELECTION_AREA_WIDTH) / 2)
#elif defined(__MMI_MAINLCD_320X240__)
#define COMPOSITION_BOX_LEFT_GAP     ((240 - SELECTION_AREA_WIDTH) / 2)
#define COMPOSITION_BOX_RIGHT_GAP    ((240 - SELECTION_AREA_WIDTH) / 2)
    #else
        #error "This resolution doesn't support FTE" 
    #endif
    #define COMPOSITION_BOX_BOTTOM_GAP     0
    #define COMPOSITION_BOX_TOP_GAP        0
#else
#define COMPOSITION_BOX_BOTTOM_GAP     1
#define COMPOSITION_BOX_TOP_GAP        1
#define COMPOSITION_BOX_LEFT_GAP       1
#define COMPOSITION_BOX_RIGHT_GAP      1
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
        #define CANDIDATE_LEFT_SPACING         10
        #define CANDIDATE_RIGHT_SPACING        10
#elif defined(__MMI_MAINLCD_320X240__)
#define CANDIDATE_LEFT_SPACING         10
#define CANDIDATE_RIGHT_SPACING        10

    #elif defined(__MMI_MAINLCD_320X480__)   
        #define CANDIDATE_LEFT_SPACING         15
        #define CANDIDATE_RIGHT_SPACING        15
    #elif defined(__MMI_MAINLCD_480X800__)   
        #define CANDIDATE_LEFT_SPACING         20
        #define CANDIDATE_RIGHT_SPACING        20
    #else
        #error "This resolution doesn't support FTE" 
    #endif
#elif defined(__MMI_TOUCH_SCREEN__)
#define CANDIDATE_LEFT_SPACING         0
#define CANDIDATE_RIGHT_SPACING        0
#else
#define CANDIDATE_LEFT_SPACING         1
#define CANDIDATE_RIGHT_SPACING        1
#endif

#ifdef __MMI_IME_FTE_ENHANCE__
#define SLECTION_AREA_LEFT_SPACING     0
#define SLECTION_AREA_RIGHT_SPACING    0
#else
#define SLECTION_AREA_LEFT_SPACING     2
#define SLECTION_AREA_RIGHT_SPACING    2
#endif

#define INPUT_AREA_LEFT_SPACING     2
#define INPUT_AREA_RIGHT_SPACING    2

#ifdef __MMI_IME_FTE_ENHANCE__
#define ARROW_LEFT_SPACING             0
#define ARROW_RIGHT_SPACING            0
#else
#define ARROW_LEFT_SPACING             2
#define ARROW_RIGHT_SPACING            2
#endif

#define STAR_LEFT_SPACING              1
#define STAR_RIGHT_SPACING             1

#define LABEL_LEFT_SPACING             1
#define LABEL_RIGHT_SPACING            1

#define CANDIDATE_SPACE_WIDTH          3

#if defined(__MMI_MAINLCD_320X240__)
#define SELECTION_AREA_MAX_ITEM_NUM    60 /* May be configed by resolution? */
#else
#define SELECTION_AREA_MAX_ITEM_NUM    50
#endif

#define CURSOR_WIDTH                   1
#define CURSOR_HEIGHT                  7

#if defined(__MMI_TOUCH_SCREEN__)
#define ARROW_WIDTH                    8
#define ARROW_HEIGHT                   14
#else
#define ARROW_WIDTH                    3
#define ARROW_HEIGHT                   6
#endif

#define IME_HINT_LEFT_GAP              2
#define IME_HINT_RIGHT_GAP             2

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#define QWERTY_SWITCH_ICON_GAP         5
#endif


#if defined(__MMI_IME_FLOATING_CAND_BOX__)
#define FLOATING_CANDIDATE_BOX_GAP_FROM_CURSOR 2
#if defined(__MMI_IME_FTE_ENHANCE__)
#define FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE 0 /* Should be defined by LCD resolutions */
#else
#define FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE 26
#endif
#define FLOATING_VERTICAL_CANDIDATE_BOX_BORDER_WIDTH 1 /* Virtiacal list border is out of list component */
#define FLOATING_VERTICAL_CANDIDATE_BOX_ITEM_COUNT   3
#define FLOATING_VERTICAL_CANDIDATE_BOX_MIN_ITEM_COUNT 2

/* Should be defined by LCD resolutions */
#define FLOATING_VERTICAL_CANDIDATE_BOX_HEIGHT (MMI_IMUI_FLOATING_VERTICAL_CANDIDATE_BOX_ITEM_COUNT * MMI_MENUITEM_HEIGHT) 
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
#define RESIZEABLE_COMP_AREA_TEXT_LEFT_SPACEING     8
#define RESIZEABLE_COMP_AREA_TEXT_RIGHT_SPACEING    8
#define RESIZEABLE_COMP_AREA_COVERED_BOTTOM_HEIGHT  0
#define RESIZEABLE_COMP_AREA_TEXT_VER_GAP           1
#endif

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    #define INPUT_BOX_LEFT_GAP COMPOSITION_BOX_LEFT_GAP
    #define INPUT_BOX_RIGHT_GAP COMPOSITION_BOX_RIGHT_GAP
    #define RESIZEABLE_INPUT_AREA_COVERED_BOTTOM_HEIGHT RESIZEABLE_COMP_AREA_COVERED_BOTTOM_HEIGHT
#endif

#if 0
#ifdef __MMI_IME_FTE_ENHANCE__
    #if defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif defined(__MMI_MAINLCD_240X400__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif defined(__MMI_MAINLCD_480X800__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
#endif
#endif

#if defined __MMI_IME_V3__
#undef CANDIDATE_BOX_LEFT_GAP
#undef CANDIDATE_BOX_RIGHT_GAP
#define CANDIDATE_BOX_LEFT_GAP 0
#define CANDIDATE_BOX_RIGHT_GAP 0
#endif

VFX_IMPLEMENT_CLASS("InputServerUI", VadpInputServerUI, VfxObject);    
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VadpInputServerUI);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
VfxBool VadpInputServerUI::s_enableVKTransitionEffect = VFX_TRUE;
#endif

VadpInputServerUI::VadpInputServerUI() :
	m_isActive(VFX_FALSE),
    m_uiBottomY(0),
    m_uiWidth(0),
    m_uiX(0),
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    m_uiFloatingWidth(0),
    m_uiFloatingX(0),
    m_uiFloatingBottomY(0),
#endif
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    m_vk(NULL),
    m_isVKHidden(VFX_TRUE),
    m_vkEffectValidationTimer(NULL),
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
    m_singleBlockHWPanel(NULL),
#endif
    m_compBox(NULL),
    m_candBox(NULL),
#if defined __MMI_IME_CANDIDATE_GRID__
	m_candGrid(NULL),
#endif
#if defined __MMI_IME_SCROLLING_COMPOSITION__
    m_sCompBox(NULL),
#endif

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    m_inputArea(NULL),
#endif
#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
    m_rCompBox(NULL),
#endif
    m_candBoxFlag(0),
    m_compBoxFlag(0),
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    m_floatingUIRect(VFX_RECT_ZERO),
#endif
#if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
    m_isIMEIndicatorEnabled(VFX_FALSE),
#endif
    m_fixedUIRect(VFX_RECT_ZERO)

    
{
    
}


VfxBool VadpInputServerUI::sendMessage(mmi_imui_message_struct_p msg_ptr, VfxU32 *ret)
{
    VfxU32 lresult = MMI_IMUI_RESULT_FALSE;
    
    switch(msg_ptr->message_id)
    {
    case MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX:
        {
            VfxU32 style = (VfxU32)msg_ptr->param_0;
                
            if (current_ime_theme->separator_width > 0)
            {
                style |= MMI_IMUI_SELECTION_AREA_STYLE_SEPARATOR;
            }
        	else
        	{
                style &= ~MMI_IMUI_SELECTION_AREA_STYLE_SEPARATOR;
        	}
            
            m_candBox = createSelBox(style);

            m_candBoxFlag = 0;
            
            lresult = MMI_IMUI_RESULT_TRUE;
        } 
        break;
        

    case MMI_IMUI_MESSAGE_SET_ACTIVE_ROW_ID_VK:
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
        m_vk->setActiveRow((VfxU32)msg_ptr->param_0);
#endif
        break;

    #if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    case MMI_IMUI_MESSAGE_GET_QWERTY_VK_KEY_MAPPING:
        m_vk->setDataSource();
        wgui_virtual_keyboard_get_qwerty_keymapping((UI_character_type*) msg_ptr->param_0, msg_ptr->param_1);
        break;
    #endif

case MMI_IMUI_MESSAGE_SET_VK:
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
	wgui_setup_virtual_keyboard((gui_virtual_keyboard_language_enum) msg_ptr->param_0, msg_ptr->param_1);
#endif
	break;
        case MMI_IMUI_MESSAGE_GET_VK_AREA_RECT:
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
            wgui_virtual_keyboard_get_vk_rect((gui_virtual_keyboard_rect_struct_p)msg_ptr->param_0,(MMI_BOOL) msg_ptr->param_1);
#endif
        break;

case MMI_IMUI_MESSAGE_ADD_TOGGLE_STATE_ID_VK:
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
			wgui_virtual_keyboard_add_toggle_state_key((toggle_state_key_index_enum)msg_ptr->param_0,(toggle_state_id_mapping_enum) msg_ptr->param_1);
#endif
			break;

    case MMI_IMUI_MESSAGE_CREATE_COMPOSITION_BOX:
        {
            m_compBox = createSelBox((VfxU32)msg_ptr->param_0);

            m_compBoxFlag = 0;

        #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
            m_rCompBox = createResizableCompositionBox();
        #endif
#if defined __MMI_IME_SCROLLING_COMPOSITION__
            m_sCompBox = createScrollableSelBox();
#endif
            lresult = MMI_IMUI_RESULT_TRUE;
        }
    
        break;
        
    case MMI_IMUI_MESSAGE_CREATE_MULTI_BLOCK_AREA:
        VFX_ASSERT(0);
        break;
        
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_TOUCH_SCREEN__)       
    case MMI_IMUI_MESSAGE_CREATE_SINGLE_BLOCK_AREA:
        {
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 

            VsrvInputBinding* inputBinding = inputServer->getBinding();

            VFX_OBJ_CREATE(m_singleBlockHWPanel, VadpInputServerSingleBlockHWPanel, inputBinding->getOwner());

            m_singleBlockHWPanel->setHidden(VFX_TRUE);
        
            topLevel->addChildFrame(m_singleBlockHWPanel);
            
            m_singleBlockHWPanel->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);
            
            VFX_ASSERT(m_singleBlockHWPanel);
            
            lresult = MMI_IMUI_RESULT_TRUE;
        }
        break;
        
    case MMI_IMUI_MESSAGE_IS_STROKE_DOWN_IN_EXTRA_BLOCK:
        
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            VFX_ASSERT(m_singleBlockHWPanel);

            VfxPoint pos((VfxS32)msg_ptr->param_0, (VfxS32)msg_ptr->param_1);

            if (m_singleBlockHWPanel->containPoint(pos))
            {
                VfxRect extraBlockRect;

                if (mmi_imc_is_rotated())
                {
                    extraBlockRect.origin.x = SINGLE_BLOCK_EXTRA_BLOCK_X_ROTATED;
                    extraBlockRect.origin.y = SINGLE_BLOCK_EXTRA_BLOCK_Y_ROTATED;
                    extraBlockRect.size.width = SINGLE_BLOCK_EXTRA_BLOCK_WIDTH_ROTATED;
                    extraBlockRect.size.height= SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT_ROTATED;
                }
                else
                {
                    extraBlockRect.origin.x = SINGLE_BLOCK_EXTRA_BLOCK_X;
                    extraBlockRect.origin.y = SINGLE_BLOCK_EXTRA_BLOCK_Y;
                    extraBlockRect.size.width = SINGLE_BLOCK_EXTRA_BLOCK_WIDTH;
                    extraBlockRect.size.height= SINGLE_BLOCK_EXTRA_BLOCK_HEIGHT;
                }
                
                lresult = extraBlockRect.contains(pos);
            }
        }
        
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
        break;        

#endif /* #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) */

    case MMI_IMUI_MESSAGE_CREATE_INPUT_BOX:
#ifdef __MMI_CSTAR_PHRASE_INPUT__
        {	    
        #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
            m_inputArea = createResizableCompositionBox();
        #endif
        
            lresult = MMI_IMUI_RESULT_TRUE;	 
	 }
#endif
        break;
        
    case MMI_IMUI_MESSAGE_CREATE_TITLE_BOX:
        break;
        
    case MMI_IMUI_MESSAGE_CREATE_VITUAL_KEYBOARD:
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    #if defined (__MMI_IME_PLUG_IN__)
        if (!mmi_imui_is_in_control_set(MMI_IMUI_VIRTUAL_KEYBOARD))
        {
            createVirtualKeyboard();
     #if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
        createMiniVirtualKeyboard();
     #endif           
            mmi_imui_add_control(MMI_IMUI_VIRTUAL_KEYBOARD);
        } 
    #else
        createVirtualKeyboard();
        #if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
        createMiniVirtualKeyboard();
        #endif
  #endif
        lresult = MMI_IMUI_RESULT_TRUE;
#endif
        break;

    case MMI_IMUI_MESSAGE_CREATE_INFORMATION_BAR:
        
        VFX_ASSERT(0);
        break;
        
    case MMI_IMUI_MESSAGE_CREATE_CLIPBOARD_FLOATING_MENU:
                
        break;

    case MMI_IMUI_MESSAGE_UPDATE_CLIPBOARD_FLOATING_MENU:
            
        break;

    case MMI_IMUI_MESSAGE_CREATE_IME_INDICATOR:
    #if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
        if (mmi_imui_create_ime_indicator())
        {
            m_isIMEIndicatorEnabled = VFX_TRUE;
        }
    #else
        VFX_ASSERT(0);
    #endif
		break;
    
    case MMI_IMUI_MESSAGE_INIT_UI:

        initUIProperties();
        
        break;
        
    case MMI_IMUI_MESSAGE_SET_HAND_WRITING_STYLE:

        break;

    case MMI_IMUI_MESSAGE_SET_HAND_WRITING_AREAS:
        
        break;

    case MMI_IMUI_MESSAGE_SET_VIRTUAL_KEYBOARD:
        
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

        setupVirtualKeyboard(msg_ptr);
        
#endif /*defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)*/

        break;

    case MMI_IMUI_MESSAGE_SHOW_CANDIDATE_BOX:
        if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
        {
            m_candBox->setIsPenSelectionValid(VFX_FALSE);
        }
        else
        {
            m_candBox->setIsPenSelectionValid(VFX_TRUE);
        }
        m_candBox->setHidden(VFX_FALSE);
        lresult = MMI_IMUI_RESULT_TRUE;
        
        break;

    case MMI_IMUI_MESSAGE_HIDE_CANDIDATE_BOX:
        
        m_candBox->setHidden(VFX_TRUE);
        lresult = MMI_IMUI_RESULT_TRUE;
        
        break;
        
    case MMI_IMUI_MESSAGE_SHOW_CLIPBOARD_FLOATING_MENU:
        break;

    case MMI_IMUI_MESSAGE_HIDE_CLIPBOARD_FLOATING_MENU:
        break;

    case MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX:
        
        m_candBox->setHiliteCandidate((VfxS32)msg_ptr->param_0);
        
        break;

    case MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX:
        {
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            m_uiFloatingWidth = m_uiWidth - FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE * 2; 
            m_uiFloatingX = m_uiX + FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE;

            if (((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING)
            {
                m_candBox->setPos(m_uiFloatingX + CANDIDATE_BOX_LEFT_GAP, m_candBox->getPos().y);
                m_candBox->setSize(m_uiFloatingWidth - (CANDIDATE_BOX_LEFT_GAP + CANDIDATE_BOX_RIGHT_GAP),
                    m_candBox->getSize().height);
            }
            else
        #endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
            {
                m_candBox->setPos(m_uiX + CANDIDATE_BOX_LEFT_GAP, m_candBox->getPos().y);
                m_candBox->setSize(m_uiWidth - (CANDIDATE_BOX_LEFT_GAP + CANDIDATE_BOX_RIGHT_GAP),
                    m_candBox->getSize().height);
            }

            m_candBoxFlag = ((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags;

            lresult = updateSelBox(m_candBox, (mmi_imui_update_selection_area_struct_p)msg_ptr->param_0);

            if ((m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_CENTER_INDEX) && lresult > 0)
            {
                reorderCandidatesToCenterFirst(((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->str_ptr, (VfxS32)lresult);

                lresult = updateSelBox(m_candBox, (mmi_imui_update_selection_area_struct_p)msg_ptr->param_0); 
            }
        }
        break;

    case MMI_IMUI_MESSAGE_CANDIDATE_BOX_GET_INDEX:

        lresult = m_candBox->getHiliteCandidate();
        break;
#if defined __MMI_IME_CANDIDATE_GRID__

    case MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX_GRID:
        m_candGrid = createCandGrid();
        break;
    case MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX_GRID:
        m_candGrid->setSize(m_vk->getSize().width,m_vk->getSize().height-1); //set equal to vk size 
        lresult = updateCandGrid(m_candGrid, (mmi_imui_update_selection_area_struct_p)msg_ptr->param_0);
        break;
    case MMI_IMUI_MESSAGE_SHOW_CANDIDATE_GRID_BOX:
        m_candGrid->setHidden(VFX_FALSE);
        break;
	case MMI_IMUI_MESSAGE_CANDIDATE_GRID_BOX_GET_INDEX:
        lresult = m_candGrid->getHiliteCandidate();
        break;

#endif  

    case MMI_IMUI_MESSAGE_CANDIDATE_SET_FOCUS:

        m_candBox->setIsFocused(VFX_TRUE);
        
        break;
        
    case MMI_IMUI_MESSAGE_CANDIDATE_CANCEL_FOCUS:
 
        m_candBox->setIsFocused(VFX_FALSE);
        
        break;

    case MMI_IMUI_MESSAGE_RESERVE_CANDIDATE_AREA:
        
        break;
        
		#if defined(__MMI_IME_SCROLLING_COMPOSITION__)
	case MMI_IMUI_MESSAGE_REMOVE_VERTICAL_FLAG:
		m_compBoxFlag &= ~MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL;
		break;
	case MMI_IMUI_MESSAGE_ADD_VERTICAL_FLAG:
		m_compBoxFlag |= MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL;
		break;
		#endif

    case MMI_IMUI_MESSAGE_SHOW_COMPOSITION_BOX:
       
#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
        if (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE)
        {
            m_rCompBox->setHidden(VFX_FALSE);
        }
        else
#endif  
        {
#if defined __MMI_IME_SCROLLING_COMPOSITION__
            if (!(m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING) && (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL))
            {
                m_sCompBox->setHidden(VFX_FALSE);  
            }
            else
#endif
            {
                m_compBox->setHidden(VFX_FALSE);
            }  
        }
    
        lresult = MMI_IMUI_RESULT_TRUE;
      
        break;

    case MMI_IMUI_MESSAGE_HIDE_COMPOSITION_BOX:
    
    #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__) 
        m_rCompBox->setHidden(VFX_TRUE);
    #endif  
        m_compBox->setHidden(VFX_TRUE);
#if defined __MMI_IME_SCROLLING_COMPOSITION__
        m_sCompBox->setHidden(VFX_TRUE);
#endif
        lresult = MMI_IMUI_RESULT_TRUE;
      
        break;
    
      
    case MMI_IMUI_MESSAGE_SET_VK_SHIFT_STATE:
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
        wgui_virtual_keyboard_set_shift_state((toggle_state_id_mapping_enum)msg_ptr->param_0);
        #endif
        break;

    case MMI_IMUI_MESSAGE_UPDATE_COMPOSITION_BOX:
    
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        m_uiFloatingWidth = m_uiWidth - FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE * 2; 
        m_uiFloatingX = m_uiX + FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE;
        
        if ((((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING) && 
            !(((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
        {
        
            m_compBox->setPos(m_uiFloatingX + COMPOSITION_BOX_LEFT_GAP, m_compBox->getPos().y);
            m_compBox->setSize(m_uiFloatingWidth - (COMPOSITION_BOX_LEFT_GAP + COMPOSITION_BOX_RIGHT_GAP),
                m_compBox->getSize().height);
        }
        else
    #endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
        {
            m_compBox->setPos(m_uiX + COMPOSITION_BOX_LEFT_GAP, m_compBox->getPos().y);
            m_compBox->setSize(m_uiWidth - (COMPOSITION_BOX_LEFT_GAP + COMPOSITION_BOX_RIGHT_GAP),
            m_compBox->getSize().height);
#if defined __MMI_IME_SCROLLING_COMPOSITION__
            m_sCompBox->setSize(wgui_virtual_keyboard_return_floating_composition_box_width(),(m_vk->getSize().height*3)/4); //set equal to vk size 
#endif
        }
    
        ((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags |=  MMI_IMUI_SELECTION_AREA_FLAG_SPACE;

        m_compBoxFlag = ((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->flags;

    #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
        if (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE)
        {
            m_rCompBox->setText(VFX_WSTR_MEM(((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->str_ptr));
            //m_rCompBox->sendToBack();
            lresult = 1;
        }
        else
    #endif
#if defined __MMI_IME_SCROLLING_COMPOSITION__
        if (m_compBoxFlag &   MMI_IMUI_SELECTION_AREA_FLAG_SCROLLING_COMPOSITION_BOX && m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
        {
            lresult = updateScrollableSelBox(m_sCompBox, (mmi_imui_update_selection_area_struct_p)msg_ptr->param_0); 
        }
        else
#endif
        {
            lresult = updateSelBox(m_compBox, (mmi_imui_update_selection_area_struct_p)msg_ptr->param_0); 
        }
        
        break;

    case MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX:
#if defined __MMI_IME_SCROLLING_COMPOSITION__       
        if (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL)
        {
        m_sCompBox->setHiliteCandidate((VfxS32)msg_ptr->param_0);        
        }
        else
#endif
        {
            m_compBox->setHiliteCandidate((VfxS32)msg_ptr->param_0);
        }        
        break;
        
    case MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX:
#if defined __MMI_IME_SCROLLING_COMPOSITION__
        if (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL)
        {
        lresult = m_sCompBox->getHiliteCandidate();
        }
        else
#endif
        {
            lresult = m_compBox->getHiliteCandidate();
        }
        break;
        
    case MMI_IMUI_MESSAGE_COMPOSITION_SET_FOCUS:

        m_compBox->setIsFocused(VFX_TRUE);
        
        break;

    case MMI_IMUI_MESSAGE_COMPOSITION_CANCEL_FOCUS:
 
        m_compBox->setIsFocused(VFX_FALSE);
        
        break;
        
    case MMI_IMUI_MESSAGE_SHOW_VIRTUAL_KEYBOARD:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        //m_vk->setHidden(VFX_FALSE);
        m_isVKHidden = VFX_FALSE;
        lresult = MMI_IMUI_RESULT_TRUE;
    #endif    
        break;
        
    case MMI_IMUI_MESSAGE_SHOW_DISABLED_VIRTUAL_KEYBOARD:
        VFX_ASSERT(0);
        break;
        
    case MMI_IMUI_MESSAGE_HIDE_VIRTUAL_KEYBOARD:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        //m_vk->setHidden(VFX_TRUE);
        m_isVKHidden = VFX_TRUE;
        lresult = MMI_IMUI_RESULT_TRUE;
    #endif   
        break;

    case MMI_IMUI_MESSAGE_SHOW_MULTI_BLOCK:

        VFX_ASSERT(0);
        lresult = MMI_IMUI_RESULT_TRUE;
        
        break;
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)        
    case MMI_IMUI_MESSAGE_SHOW_SINGLE_BLOCK:    
        lresult = MMI_IMUI_RESULT_TRUE;        
        break;
    case MMI_IMUI_MESSAGE_HIDE_SINGLE_BLOCK:
        mmi_imc_pen_stop_singleblock_handwriting(); 
        lresult = MMI_IMUI_RESULT_TRUE;
        break;
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
        
    case MMI_IMUI_MESSAGE_UPDATE_INPUT_AREA:
        
#ifdef __MMI_CSTAR_PHRASE_INPUT__
{
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
       m_uiFloatingWidth = m_uiWidth - FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE * 2; 
       m_uiFloatingX = m_uiX + FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE;
               
       if ((((mmi_imui_update_input_area_struct_p)msg_ptr->param_0)->flags & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING)&& 
            !(((mmi_imui_update_input_area_struct_p)msg_ptr->param_0)->flags & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
       {
               
           m_inputArea->setPos(m_uiFloatingX + INPUT_BOX_LEFT_GAP, m_inputArea->getPos().y);
           m_inputArea->setSize(m_uiFloatingWidth - (INPUT_BOX_LEFT_GAP + INPUT_BOX_RIGHT_GAP),
           m_inputArea->getSize().height);
       }
       else
   #endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
       {
           m_inputArea->setPos(m_uiX + INPUT_BOX_LEFT_GAP, m_inputArea->getPos().y);
           m_inputArea->setSize(m_uiWidth - (INPUT_BOX_LEFT_GAP + INPUT_BOX_RIGHT_GAP),
           m_inputArea->getSize().height);
       }

       
       m_inputArea->setText(VFX_WSTR_MEM(((mmi_imui_update_selection_area_struct_p)msg_ptr->param_0)->str_ptr));      
}       
#else
        VFX_ASSERT(0);
#endif
            
        break;

    case MMI_IMUI_MESSAGE_SHOW_INPUT_BOX:
        
#ifdef __MMI_CSTAR_PHRASE_INPUT__
        {
            m_inputArea->setHidden(VFX_FALSE);
        }
#else
        VFX_ASSERT(0);
#endif
        lresult = MMI_IMUI_RESULT_TRUE;
        break;
        
    case MMI_IMUI_MESSAGE_HIDE_INPUT_BOX:
    
#ifdef __MMI_CSTAR_PHRASE_INPUT__
        {
            m_inputArea->setHidden(VFX_TRUE);
        }
#else
        VFX_ASSERT(0);
#endif
        lresult = MMI_IMUI_RESULT_TRUE;
        break;
        
    case MMI_IMUI_MESSAGE_INPUT_SET_FOCUS:
    
#ifdef __MMI_CSTAR_PHRASE_INPUT__
#else
        VFX_ASSERT(0);
#endif
        
        break;

    case MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL:
        
        break;

    case MMI_IMUI_MESSAGE_INPUT_CANCEL_FOCUS:        
    
#ifdef __MMI_CSTAR_PHRASE_INPUT__
#else
        VFX_ASSERT(0);
#endif
        break;
    
    case MMI_IMUI_MESSAGE_UPDATE_TITLE_AREA:
        
        VFX_ASSERT(0);

        break;
        
    case MMI_IMUI_MESSAGE_SHOW_TITLE_BOX:

        VFX_ASSERT(0);
        break;
        
    case MMI_IMUI_MESSAGE_HIDE_TITLE_BOX:

        VFX_ASSERT(0);
        break;
    
    case MMI_IMUI_MESSAGE_HIDE_MULTI_BLOCK:
        
        VFX_ASSERT(0);
        
        break;
        
    case MMI_IMUI_MESSAGE_REDRAW:
        layoutUIComponents();
    #if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
        if (m_isIMEIndicatorEnabled)
        {
            mmi_imui_update_ime_indicator();
        }
    #endif
        break;
        
    case MMI_IMUI_MESSAGE_REDRAW_FLOATING_CONTROLS:
        
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        layoutAllFloatingUIComponents();
    #endif
        
        break;
        
    case MMI_IMUI_MESSAGE_HIDE_ALL:

    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if (m_vk)
        {
           //m_vk->setHidden(VFX_TRUE);
           m_isVKHidden = VFX_TRUE;
        }
    #endif

    
        if (m_compBox)
        {
            m_compBox->setHidden(VFX_TRUE);
        }
#if defined __MMI_IME_SCROLLING_COMPOSITION__
        if (m_sCompBox)
        {
            m_sCompBox->setHidden(VFX_TRUE);
        }
#endif
        if (m_candBox)
        {
            m_candBox->setHidden(VFX_TRUE);
        }
#if defined __MMI_IME_CANDIDATE_GRID__
        if (m_candGrid)
        {
            m_candGrid->setHidden(VFX_TRUE);
        }
#endif

    #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
        if (m_rCompBox)
        {
            m_rCompBox->setHidden(VFX_TRUE);
        }
    #endif
    
    #ifdef __MMI_CSTAR_PHRASE_INPUT__
        if (m_inputArea)
        {
            m_inputArea->setHidden(VFX_TRUE);
        }
    #endif
    
        break;
        
    case MMI_IMUI_MESSAGE_SET_BACK_GROUND_REDRAW_FUNC:

        VFX_ASSERT(0);
        
        break;
        
    case MMI_IMUI_MESSAGE_EXIT:
        {
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if (m_vk) 
            {
                VFX_OBJ_CLOSE(m_vk);
            }
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
            if (m_vkMini) 
            {
                VFX_OBJ_CLOSE(m_vkMini);
            }
#endif
            s_enableVKTransitionEffect = VFX_FALSE;
            gui_start_timer(250, VadpInputServerUI::vkEffectValidationCheckTimer);
        
        #endif

        #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
            if (m_singleBlockHWPanel) 
            {
                VFX_OBJ_CLOSE(m_singleBlockHWPanel);
            }
        #endif

        
            if (m_compBox) 
            {
                VFX_OBJ_CLOSE(m_compBox);
            }
#if defined __MMI_IME_SCROLLING_COMPOSITION__
            if (m_sCompBox) 
            {
                VFX_OBJ_CLOSE(m_sCompBox);
            }
#endif
#if defined __MMI_IME_CANDIDATE_GRID__
            if (m_candGrid) 
            {
                VFX_OBJ_CLOSE(m_candGrid);
            }
#endif
            if (m_candBox) 
            {
                VFX_OBJ_CLOSE(m_candBox);
            }


        #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
            if (m_rCompBox) 
            {
                VFX_OBJ_CLOSE(m_rCompBox);
            }
        #endif
        
        #ifdef __MMI_CSTAR_PHRASE_INPUT__
            if (m_inputArea)
            {
                VFX_OBJ_CLOSE(m_inputArea);
            }
        #endif

        #if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
            if (m_isIMEIndicatorEnabled)
            {
                mmi_imui_close_ime_indicator();
                m_isIMEIndicatorEnabled = VFX_FALSE;
            }
        #endif
        
            if (m_popupMenu != NULL)
            {
                VfxBasePopup *popup = m_popupMenu.get();
                
                VFX_OBJ_CLOSE(popup);
            }
        
            m_extraControlList.removeAllInvalidate();
        
            VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

            inputServer->m_currInputBinding->getConnection()->setIMEUILayout(0, 0, 0, 0, 0, 0, 0, 0, VFX_FALSE);

            m_fixedUIRect = VfxRect(m_uiX, m_uiBottomY + 1, 0, 0);

            VfxAutoAnimate::commit();
        
			m_isActive = VFX_FALSE;
        }
        break;
        
    case MMI_IMUI_MESSAGE_DRAW_STROKE:
        
    #if defined(__MMI_TOUCH_SCREEN__)

        drawHandWritingStroke((mmi_pen_point_struct *)msg_ptr->param_0, (mmi_pen_point_struct *)msg_ptr->param_1);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;

    case MMI_IMUI_MESSAGE_SET_STROKE_COLOR:
        
    #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_TOUCH_SCREEN__)
        if (m_singleBlockHWPanel)
        {
            m_singleBlockHWPanel->setStrokColor(VfxColor(255, ((color *)msg_ptr->param_0)->r,
                                                         ((color *)msg_ptr->param_0)->g,
                                                         ((color *)msg_ptr->param_0)->b));
        }
    #endif /* #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) */

        break;

    case MMI_IMUI_MESSAGE_CLEAR_STROKE:
        
    #if defined(__MMI_TOUCH_SCREEN__)

        clearHandWritingStroke();
        
    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;

    case MMI_IMUI_MESSAGE_PEN_DOWN_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)
        VFX_ASSERT(0);
    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;

    case MMI_IMUI_MESSAGE_FLOATING_UI_PEN_DOWN_EVENT: /* Only for Venus input server floating control */
    
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VUI_ENGINE__) && defined(__MMI_IME_FLOATING_CAND_BOX__)
    
        VFX_ASSERT(0);
        
    #endif /*defined(__MMI_TOUCH_SCREEN__)*/
    
        break;

    case MMI_IMUI_MESSAGE_PEN_UP_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)

        VFX_ASSERT(0);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;

    case MMI_IMUI_MESSAGE_PEN_MOVE_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)

        VFX_ASSERT(0);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;
    case MMI_IMUI_MESSAGE_PEN_REPEAT_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)

        VFX_ASSERT(0);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;
    case MMI_IMUI_MESSAGE_PEN_LONG_TAP_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)

        VFX_ASSERT(0);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/

        break;

    case MMI_IMUI_MESSAGE_PEN_ABORT_EVENT:

    #if defined(__MMI_TOUCH_SCREEN__)

        VFX_ASSERT(0);

    #endif /*defined(__MMI_TOUCH_SCREEN__)*/
        break;

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_HANDWRITING_MULTI_BLOCK__)    
    case MMI_IMUI_MESSAGE_GET_MULTI_BLOCK_AREA:
        
        VFX_ASSERT(0);
        
        break;
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)  


    case MMI_IMUI_MESSAGE_GET_SINGLE_BLOCK_AREA:

#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            vrt_size_struct mainScreenSize;
            vrt_color_type_enum mainScreenColorFormat;
            vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

            if (mmi_imc_is_rotated())
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = m_uiX + SINGLE_BLOCK_LEFT_GAP;
                /* when virtaul keyboard is on, the buttom line is over softkey area. */
                ((mmi_imc_rect_p)msg_ptr->param_0)->y = mainScreenSize.height - 1 - (SINGLE_BLOCK_BOTTOM_GAP + SINGLE_BLOCK_HEIGHT_ROTATED) + 3;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = SINGLE_BLOCK_WIDTH_ROTATED- 1;
                ((mmi_imc_rect_p)msg_ptr->param_0)->height = SINGLE_BLOCK_HEIGHT_ROTATED- 3;  
            }
            else
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = m_uiX + SINGLE_BLOCK_LEFT_GAP;
                /* when virtaul keyboard is on, the buttom line is over softkey area. */
                ((mmi_imc_rect_p)msg_ptr->param_0)->y = mainScreenSize.height - 1 - (SINGLE_BLOCK_BOTTOM_GAP + SINGLE_BLOCK_HEIGHT) + 3;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = SINGLE_BLOCK_WIDTH - 1;
                ((mmi_imc_rect_p)msg_ptr->param_0)->height = SINGLE_BLOCK_HEIGHT - 3;  
            }
        }
#else
        {
            U8 uWidth = mmi_imm_handwriting_get_stroke_width();
            if (mmi_imc_is_rotated())
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = SINGLE_BLOCK_X_ROTATED + SINGLE_BLOCK_AND_STROKE_AREA_GAP + uWidth/2;
                ((mmi_imc_rect_p)msg_ptr->param_0)->y = SINGLE_BLOCK_Y_ROTATED + SINGLE_BLOCK_AND_STROKE_AREA_GAP + uWidth/2;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = SINGLE_BLOCK_WIDTH_ROTATED - SINGLE_BLOCK_AND_STROKE_AREA_GAP * 2 - uWidth;
                ((mmi_imc_rect_p)msg_ptr->param_0)->height = SINGLE_BLOCK_HEIGHT_ROTATED - SINGLE_BLOCK_AND_STROKE_AREA_GAP * 2 - uWidth;  
            }
            else
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = SINGLE_BLOCK_X + SINGLE_BLOCK_AND_STROKE_AREA_GAP + uWidth/2;
                ((mmi_imc_rect_p)msg_ptr->param_0)->y = SINGLE_BLOCK_Y + SINGLE_BLOCK_AND_STROKE_AREA_GAP + uWidth/2;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = SINGLE_BLOCK_WIDTH - SINGLE_BLOCK_AND_STROKE_AREA_GAP * 2 - uWidth;
                ((mmi_imc_rect_p)msg_ptr->param_0)->height = SINGLE_BLOCK_HEIGHT - SINGLE_BLOCK_AND_STROKE_AREA_GAP * 2 - uWidth;  
            }
        }

#endif
        break;
#endif
    case MMI_IMUI_MESSAGE_DRAW_INFORMATION_BAR:

        VFX_ASSERT(0);
        
        break;
        
    case MMI_IMUI_MESSAGE_GET_IME_INFOR_WIDTH:
        VFX_ASSERT(0);
        break;
        
    case MMI_IMUI_MESSAGE_GET_VK_AREA_HEIGHT:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        lresult = (U32)(VIRTUAL_KEYBOARD_BOTTOM_GAP + VIRTUAL_KEYBOARD_TOP_GAP + m_vk->getSize().height);
    #else
        lresult = 0;
    #endif
        break;

	case MMI_IMUI_MESSAGE_IS_SYMBOL_VK_TYPE:
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
        lresult = wgui_virtual_keyboard_is_symbol_vk((gui_virtual_keyboard_language_enum) msg_ptr->param_0);
        #endif
        break;

    case MMI_IMUI_MESSAGE_GET_VK_TYPE:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        lresult = (U32)m_vk->getType(); 
    #else
        lresult = 0;
    #endif
        break;

    case MMI_IMUI_MESSAGE_INVALIDATE_VK:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        m_vk->invalidate(); 
    #endif
        break;
       case MMI_IMUI_MESSAGE_UPDATE_VK:
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
		m_vk->checkUpdate();
    #endif
	 break;
    case MMI_IMUI_GET_VK_KEY_POSITION:
        //VFX_ASSERT(0);
        break;
#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    case MMI_IMUI_SET_HW_EXTRA_BLOCK_INDICATOR:
    #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        m_singleBlockHWPanel->setExtraBlockImg((VfxId)msg_ptr->param_0);
    #endif
        break;
#endif
        
    case MMI_IMUI_MESSAGE_SET_NEW_WORD_PROMPT:
    #if defined(__MMI_IME_USER_DATABASE__)
        newWordPrompt = VFX_WSTR_MEM((VfxWChar *)msg_ptr->param_0);

        if (m_candBox)
        {
            m_candBox->setNewWordString(newWordPrompt);
        }

#if defined __MMI_IME_CANDIDATE_GRID__
        if (m_candGrid)
        {
            m_candGrid->setNewWordString(newWordPrompt);
        }
#endif

            #endif

        break;
        
    case MMI_IMUI_MESSAGE_GET_MAX_CANDIDATE_WIDTH:
        VFX_ASSERT(0);
        break;
        
    case MMI_IMUI_MESSAGE_GET_IME_HINT_WIDTH:
        VFX_ASSERT(0);
        break;

    case MMI_IMUI_MESSAGE_DRAW_IME_HINT:
        VFX_ASSERT(0);
        break;
    
    case MMI_IMUI_MESSAGE_FIXED_IMUI_HEIGHT:
        lresult = (VfxU32)m_fixedUIRect.getHeight();
        break;
        
    case MMI_IMUI_MESSAGE_FLOATING_IMUI_HEIGHT:
        VFX_ASSERT(0);
        break;

    case MMI_IMUI_MESSAGE_GET_FLOATING_IMUI_SET:
        VFX_ASSERT(0);
        break;

    case MMI_IMUI_MESSAGE_SET_IMUI_PARAMETERS:
        //VFX_ASSERT(0);
        return 0;

        
	case MMI_IMUI_MESSAGE_GET_IMUI_PARAMETERS:
        #ifdef __MMI_IME_PLUG_IN__    
        {
            mmi_imui_param_struct* param = (mmi_imui_param_struct*) msg_ptr->param_0;
            param->imui_bottom = m_uiBottomY;
            param->imui_x = m_uiX;
            param->imui_width = m_uiWidth;
	        param->imui_bottom_border = 0;
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            param->imui_floating_bottom = m_uiFloatingBottomY;
            param->imui_floating_width = m_uiFloatingWidth;
            param->imui_floating_x = m_uiFloatingX;
        #endif
            lresult = MMI_IMUI_RESULT_TRUE;
            break;
        }
        #endif

        return 0;


    case MMI_IMUI_MESSAGE_GET_LAST_SHOWED_IMUI_SET:
        VFX_ASSERT(0);
        break;

#if defined(__MMI_VIRTUAL_KEYBOARD__)
    case MMI_IMUI_MESSAGE_CONFIG_REDRAW_VK:
        break;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)        
    case MMI_IMUI_MESSAGE_SET_VK_STYLE:
        if (m_vk->getAttr() != (VcpVKAttr )msg_ptr->param_0)
        {
            m_vk->setAttr((VcpVKAttr )msg_ptr->param_0);
            updateVKSpecialEnterKey();
        }
        break;
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    case MMI_IMUI_MESSAGE_CHECK_FLOATING_UI_CONTAIN_POINT:
        VFX_ASSERT(0);
        break;
#endif        

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    case MMI_IMUI_DOES_FLOATING_UI_COVER_IME_INDICATOR:

        lresult = 0;
        break;

    case MMI_IMUI_SET_FLOATING_CANDIDATE_BOX:
        m_candBoxFlag |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
        m_compBoxFlag |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
        break;
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__) 
    case MMI_IMUI_CHECK_OVERLAP_WITH_CURRENT_FLOATING_UI:
        VFX_ASSERT(0);
        break;

    case MMI_IMUI_GET_FLOATING_UI_RECT:
        VFX_ASSERT(0);
        break;
#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__)  */

#if defined(__MMI_TOUCH_SCREEN__) && !defined(MMI_IMUI_HANDWRITING_STROKE_ON_2_LAYER)    
    case MMI_IMUI_MESSAGE_GET_EXTRA_IMUI_LAYER_HANDLER:
        VFX_ASSERT(0);
        break;
#endif
	
	case MMI_IMUI_MESSAGE_EXIT_HANDWRITING_ON_DISCONNECT:
		
		break;

    /* for VENUS PLUG IN */
#ifdef __MMI_IME_PLUG_IN__
    case MMI_IMUI_MESSAGE_SET_HIDDEN_CONTROL: 
    {
        mmi_imui_control_type_enum imui_control = (mmi_imui_control_type_enum)msg_ptr->param_0;
        
        if(MMI_IMUI_VIRTUAL_KEYBOARD == imui_control) 
        {
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            if (m_vk)
            {
                m_isVKHidden = VFX_TRUE;
            }
            else
            {
                MMI_ASSERT(0); /* It is invalid to set vk when VK is not being created*/
            }
    #endif
        }
        else if (imui_control >= MMI_IMUI_CUSTOM_CONTROL_BEGIN && imui_control <= MMI_IMUI_CUSTOM_CONTROL_END)
        {
            mmi_imui_set_control_showed_flag(imui_control, MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(0); /* the imui control is invalid */
        }
        
        lresult = MMI_IMUI_RESULT_TRUE;
        break;
    }
   case MMI_IMUI_MESSAGE_SET_VISIBLE_CONTROL:
   {
        mmi_imui_control_type_enum imui_control = (mmi_imui_control_type_enum)msg_ptr->param_0;
        
        if(MMI_IMUI_VIRTUAL_KEYBOARD == imui_control) 
        {
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            if (m_vk)
            {                
                m_isVKHidden = VFX_FALSE;   
            }
            else
            {
                MMI_ASSERT(0); /* It is invalid to set vk when VK is not being created*/
            }
    #endif
        }
        else if (imui_control >= MMI_IMUI_CUSTOM_CONTROL_BEGIN && imui_control <= MMI_IMUI_CUSTOM_CONTROL_END)
        {
            mmi_imui_set_control_showed_flag(imui_control, MMI_TRUE);
        }
        else
        {
            MMI_ASSERT(0); /* the imui control is invalid */
        }

        lresult = MMI_IMUI_RESULT_TRUE;
        break;
    }
   case MMI_IMUI_MESSAGE_IS_VISIBLE_CONTROL:
   {
        mmi_imui_control_type_enum imui_control = (mmi_imui_control_type_enum)msg_ptr->param_0;
        
        if(MMI_IMUI_VIRTUAL_KEYBOARD == imui_control) 
        {
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            if (m_vk)
            {
                if(VFX_FALSE == m_isVKHidden)
                {
                    lresult = MMI_IMUI_RESULT_TRUE;
                }
                else
                {
                    lresult = MMI_IMUI_RESULT_FALSE;
                }
            }
    #endif
        }
        else if (imui_control >= MMI_IMUI_CUSTOM_CONTROL_BEGIN && imui_control <= MMI_IMUI_CUSTOM_CONTROL_END)
        {
            lresult = mmi_imui_is_visible_control(imui_control);
        }
        else
        {
            MMI_ASSERT(0); /* the imui control is invalid */
        }
        
        break;
    }

   case MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_CONTROL:

        lresult = MMI_IMUI_RESULT_FALSE;   /*VRT will help to check this, so return false defaultly*/   
        break;

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    case MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_FLOATING_CONTROL:

        lresult = MMI_IMUI_RESULT_FALSE;   /*VRT will help to check this, so return false defaultly*/
        break;
#endif

    case MMI_IMUI_MESSAGE_IS_VIRTUAL_KEYBOARD_HIDDEN: /*Only to check MTK virtual keyboard*/
        
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            if (m_vk)
            {
                if(VFX_FALSE == m_isVKHidden)
                {
                    lresult = MMI_IMUI_RESULT_TRUE;
                }
                else
                {
                    lresult = MMI_IMUI_RESULT_FALSE;
                }
            }
    #endif
        break;

    case MMI_IMUI_MESSAGE_IS_IN_CONTROL_SET:
        lresult = mmi_imui_is_in_control_set((mmi_imui_control_type_enum)msg_ptr->param_0);

        break;

    case MMI_IMUI_MESSAGE_ADD_CONTROL:
        mmi_imui_add_control((mmi_imui_control_type_enum)msg_ptr->param_0);

        break;
#endif
        
    default:
        break;
        
    }

    *ret = lresult;
        
    return VFX_TRUE;
}


void VadpInputServerUI::setFrameAboveVK(VfxFrame *aboveFrame)
{
    m_frameAboveVKWeekPtr = aboveFrame;
}


VfxRect VadpInputServerUI::getFixedUIRect()
{
    return m_fixedUIRect;
}


VfxBool VadpInputServerUI::isIMUIControl(VfxControl *control)
{
    VfxFrame *i;
    
    #if defined(__MMI_IME_PLUG_IN__)
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_IS_IMUI_CONTROL, (U32)control, 0))
        return VFX_TRUE;
    #endif
    
    for (i = control; i != NULL; i = i->getParentFrame())
    {
        VfxControl *control = VFX_OBJ_DYNAMIC_CAST(i, VfxControl);
        
        if (control != NULL)
        {
        #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if (m_vk == control)
            {
                return VFX_TRUE;
            }
        #endif

            if (m_compBox == control)
            {
                return VFX_TRUE;
            }

            if (m_candBox == control)
            {
                return VFX_TRUE;
            }

#if defined __MMI_IME_CANDIDATE_GRID__
            if (m_candGrid == control)
            {
                return VFX_TRUE;
            }
#endif
#if defined __MMI_IME_SCROLLING_COMPOSITION__
            if (m_sCompBox == control)
            {
                return VFX_TRUE;
            }
#endif
        #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
            if (m_rCompBox == control)
            {
                return VFX_TRUE;
            }
        #endif
        
        #ifdef __MMI_CSTAR_PHRASE_INPUT__
            if (m_inputArea == control)
            {
                return VFX_TRUE;
            }
        #endif

        #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
            if (m_singleBlockHWPanel == control)
            {
                return VFX_TRUE;
            }
        #endif
        
            VfxObjListEntry *listEntry = NULL;
            VfxControl *extraControlPtr = NULL;
            VfxFrame *i;

            for (listEntry = m_extraControlList.getHead(); listEntry != NULL; listEntry = listEntry->getNext())
            {
                extraControlPtr = VFX_OBJ_DYNAMIC_CAST(listEntry->get(), VfxControl);

                if (!extraControlPtr)
                {
                    continue;
                }
                
                if (extraControlPtr)
                {
                    for (i = extraControlPtr; i != NULL; i = i->getParentFrame())
                    {
                        VfxControl *controlPtr = VFX_OBJ_DYNAMIC_CAST(i, VfxControl);
                        
                        if (controlPtr != NULL)
                        {
                            if (controlPtr == control)
                            {
                                return VFX_TRUE;
                            }
                        }
                    }
                }
            }
        }
    }

    return VFX_FALSE;
}


void VadpInputServerUI::registerExtraControl(VfxControl *extraControl)
{
    m_extraControlList.removeAllInvalidate();

    m_extraControlList.append(extraControl);
}


void VadpInputServerUI::unRegisterExtraControl(VfxControl *extraControl)
{
    m_extraControlList.removeAllInvalidate();

    m_extraControlList.removeOne(extraControl);
}


void VadpInputServerUI:: onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{

    m_popupstate =  state;
}

void VadpInputServerUI::registerIMEPopupMenu(VfxBasePopup *popup)
{
    if (m_popupMenu != NULL)
    {
        m_popupMenu->exit(VFX_FALSE);
    }
    
    m_popupMenu = popup;
    m_popupMenu->m_signalPopupState.connect(this, &VadpInputServerUI::onPopupStateChanged);
    registerExtraControl(popup);
}


void VadpInputServerUI::unRegisterIMEPopupMenu(VfxBasePopup *popup)
{
    if (m_popupMenu == popup)
    {
        m_popupMenu = NULL;
    }
    
    unRegisterExtraControl(popup);
}


void VadpInputServerUI::enterIMEPopupMenu(VfxBasePopup *popup)
{
    VsrvInputBinding *inputBinding = VFX_OBJ_GET_INSTANCE(VadpInputServer)->m_currInputBinding;

    if (inputBinding)
    {
        InputConnection *connPtr = inputBinding->getConnection();

        if (connPtr)
        {
            connPtr->sendIMENotification(IME_NOTIFICATION_SHOW_IME_POPUP, NULL);
        }
    }
}

void VadpInputServerUI::leaveIMEPopupMenu(VfxBasePopup *popup)
{
    VsrvInputBinding *inputBinding = VFX_OBJ_GET_INSTANCE(VadpInputServer)->m_currInputBinding;

    if (inputBinding)
    {
        InputConnection *connPtr = inputBinding->getConnection();

        if (connPtr)
        {
            connPtr->sendIMENotification(IME_NOTIFICATION_CLOSE_IME_POPUP, NULL);
        }
    }
}


void VadpInputServerUI::initUIProperties()
{
    updateUIParams();

    m_isActive = VFX_TRUE;
}


void VadpInputServerUI::updateUIParams()
{
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

    m_uiBottomY = mainScreenSize.height - 1;
    m_uiX = 0;
    m_uiWidth = mainScreenSize.width;

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    m_uiFloatingWidth = m_uiWidth - FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE * 2;
    m_uiFloatingX = m_uiX + FLOATING_CANDIDATE_BOX_OFFSET_FROM_EDITOR_LEFT_EDGE;
#endif
}


void VadpInputServerUI::setSpecialEnterKey(VfxBool isEnabled)
{
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (m_vk)
    {
        VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
        VsrvInputBinding* inputBinding = inputServer->getBinding();

        if (inputBinding)
        {
            if (inputBinding->m_isVKEnterKeyEnabled != isEnabled)
            {
                inputBinding->m_isVKEnterKeyEnabled = isEnabled;
                updateVKButtonValidation();
            }
        }
    }
#endif
}


void VadpInputServerUI::beforeRotate()
{
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
	if(m_vkMini)
	{
		m_vkMini->setHidden(VFX_TRUE);
	}
#endif
    m_fixedUIRect = VfxRect(m_uiX, m_uiBottomY + 1, 0, 0);
}


void VadpInputServerUI::rotate()
{
    if (!m_isActive)
    {
        return;
    }

    updateUIParams();
    
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (m_vk)
    {
#if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        /* because rotating vk needs to set remove when wgui hack is removed */
        mmi_imc_pen_set_vk_active_row(mmi_imm_get_curr_input_type());
#endif
        m_vk->rotate();
        // to disable the input style button if there is only one vk type which is valid
        updateVKButtonValidation();
        updateVKSpecialEnterKey();
    }
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_TOUCH_SCREEN__)
    if (m_singleBlockHWPanel)
    {
        m_singleBlockHWPanel->rotate();
    }
#endif

}


void VadpInputServerUI::reorderCandidatesToCenterFirst(VfxWChar *str, VfxS32 count)
{
    VfxS32 new_index[(MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE > MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN ? MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE : MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN)] = {0};
    VfxWChar *temp_str;
    VfxS32 index = 0;    
    VfxS32 index_0 = (count - 1)/2;
    VfxS32 i = 1;
    VfxS32 mux = 1;    
    VfxS32 len = 0;
    VfxS32 j = 0;
    VfxWChar temp_candidates[MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE * 2];
    
    memcpy(temp_candidates, str, 2 * MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE * sizeof(VfxWChar));

    /* reorder the sequence */
    for (i = 1; i < count; i ++)
    {
        if ((i & 1) == 0)
        {
            mux = -1;
        }
        else
        {
            mux = 1;
        }
        
        index = (index_0) + (mux * ((i + 1)/2));
        new_index[index] = i;
    }

    for (i = 0; i < count; i ++)
    {
        temp_str = getStringByIndex(temp_candidates, new_index[i], count);
        
        if (temp_str)
        {
            len = vfx_sys_wcslen((const VfxWChar *)temp_str);
            
            memcpy(&str[j], temp_str, sizeof(VfxWChar) * (len + 1));
            j += (len + 1);
        }
        else
        {
            str[j] = 0;
            j++;
        }
    }

}


vrt_allocator_handle VadpInputServerUI::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}

VfxWChar * VadpInputServerUI::getStringByIndex(VfxWChar * str, VfxS32 index, VfxS32 count)
{
    VfxWChar *temp_str;
    VfxS32 len, i = 0;
    
    if (!str[0] || index >= count)
    {
        return NULL;
    }

    temp_str = str;
    
    while(i < index)
    {
        len = vfx_sys_wcslen((const VfxWChar *)temp_str);

        temp_str += (len + 1);
        i++;
    }

    return temp_str;
}


void VadpInputServerUI::layoutUIComponents()
{
    vfxPostInvoke0(this, &VadpInputServerUI::layoutAllFixedUIComponents);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    vfxPostInvoke0(this, &VadpInputServerUI::layoutAllFloatingUIComponents);
#endif
}
//fix this asap //manik
extern "C"
{
extern void mmi_imc_pen_get_vk_area_rect(S32* x,S32* y,S32* width,S32* height,MMI_BOOL is_large);
}

void VadpInputServerUI::layoutAllFixedUIComponents()
{
    if (!m_isActive)
    {
        return;
    }
	
    VfxS32 bottomY = m_uiBottomY;
    VfxRect vkRect = VFX_RECT_ZERO;
    VfxBool isVKAnim = VFX_FALSE;

/* its a special fix , actually a hack */
    vrt_size_struct screenSize;
    vrt_color_type_enum noUse;
    vrt_sys_get_main_screen_info(&screenSize, &noUse);



#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (!m_isVKHidden)
    {
        updateVKButtonValidation();

        if (m_vk->getHidden())
        {
            if (s_enableVKTransitionEffect)
            {
                VfxAutoAnimate::initAnimateBegin();
            }
            
            m_vk->setPos(m_uiX, bottomY - (VIRTUAL_KEYBOARD_BOTTOM_GAP + m_vk->getSize().height) + 1);

            if (s_enableVKTransitionEffect)
            {
                VfxAutoAnimate::initAnimateEnd();
            }

            isVKAnim = s_enableVKTransitionEffect;
        }
        else
        {
            isVKAnim = VFX_FALSE;

            if (m_vk->getPos().y == bottomY + 1 && !m_haltVkAnimation)   //its completely out of screen
            {
                isVKAnim = VFX_TRUE;
            }
            if(m_haltVkAnimation)
            {
                m_haltVkAnimation = VFX_FALSE;
            }
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(!isVKAnim);

            m_vk->setPos(m_uiX, bottomY - (VIRTUAL_KEYBOARD_BOTTOM_GAP + m_vk->getSize().height) + 1);
            
            VfxAutoAnimate::commit();
        }
        
/* both these components are supposed to have Vk top point as anchor */
#if defined __MMI_IME_SCROLLING_COMPOSITION__
        m_sCompBox->setPos(m_uiX, bottomY - (VIRTUAL_KEYBOARD_BOTTOM_GAP + m_vk->getSize().height) + 2);
#endif

#if defined __MMI_IME_CANDIDATE_GRID__
        m_candGrid->setPos(m_uiX, bottomY - (VIRTUAL_KEYBOARD_BOTTOM_GAP + m_vk->getSize().height) + 2);
#endif
        s_enableVKTransitionEffect = VFX_FALSE;
        
        m_vk->setHidden(VFX_FALSE);
    #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
        if (mmi_imc_pen_get_handwriting_style() == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK

			&& m_vk->getType() == GUI_VIRTUAL_KEYBOARD_TRAY
	
           )
        {
            m_singleBlockHWPanel->setHidden(VFX_FALSE);

#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__  )

			m_singleBlockHWPanel->setPos(m_vk->getPos());
#else
            if (mmi_imc_is_rotated())
            {
			m_singleBlockHWPanel->setPos(SINGLE_BLOCK_X_ROTATED,SINGLE_BLOCK_Y_ROTATED);
            }
            else
            {
			m_singleBlockHWPanel->setPos(SINGLE_BLOCK_X,SINGLE_BLOCK_Y);
            }
            
#endif
            if (mmi_imc_is_rotated())
            {
                m_singleBlockHWPanel->setSize(SINGLE_BLOCK_WIDTH_ROTATED, SINGLE_BLOCK_HEIGHT_ROTATED);
            }
            else
            {
                m_singleBlockHWPanel->setSize(SINGLE_BLOCK_WIDTH, SINGLE_BLOCK_HEIGHT);
            }
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            
            topLevel->insertChildFrameAfter(m_vk, m_singleBlockHWPanel);
        }
        else
        {
            m_singleBlockHWPanel->setHidden(VFX_TRUE);
        }
    #endif
        
        bottomY -= (VIRTUAL_KEYBOARD_BOTTOM_GAP + VIRTUAL_KEYBOARD_TOP_GAP + m_vk->getSize().height);

        vkRect = VfxRect(m_vk->getPos().x,
                         m_vk->getPos().y - VIRTUAL_KEYBOARD_TOP_GAP,
                         m_vk->getSize().width,
                         m_vk->getSize().height + VIRTUAL_KEYBOARD_BOTTOM_GAP + VIRTUAL_KEYBOARD_TOP_GAP);
    }
    else
    {
        if ( (m_vk->getPos().y != bottomY + 1) && (m_vk->getPos().y != screenSize.width ))
        {
            isVKAnim = VFX_TRUE;
        }

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(!isVKAnim);

        m_vk->setPos(m_uiX, bottomY + 1);

        VfxAutoAnimate::commit();

    #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
        m_singleBlockHWPanel->setHidden(VFX_TRUE);
    #endif
    }
#endif

#ifdef __MMI_IME_PLUG_IN__
    U32 custom_control;

    custom_control = mmi_imui_get_control_showed_flag();
    custom_control = custom_control & mmi_ime_sdk_get_custom_control_mask();
    if (custom_control != 0)
    {
        bottomY = mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_DRAW_CURRENT_FIXED_UI_CONTROLS, custom_control, bottomY);
    }
    else
#endif
    {
        if (!m_candBox->getHidden() && !(m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))
        {
            m_candBox->setPos(m_candBox->getPos().x, bottomY - (CANDIDATE_BOX_BOTTOM_GAP + m_candBox->getSize().height) + 1);
       
            bottomY -= (CANDIDATE_BOX_BOTTOM_GAP + CANDIDATE_BOX_TOP_GAP + m_candBox->getSize().height);
        }
#if defined __MMI_IME_CANDIDATE_GRID__

        if (!m_candGrid->getHidden() )
        {
                bottomY -= m_candGrid->getSize().height ;
        }
#endif



        if (!m_compBox->getHidden() && 
            !(m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING) &&
            !(m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING) &&
            !(m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
        {
            m_compBox->setPos(m_compBox->getPos().x, bottomY - (COMPOSITION_BOX_BOTTOM_GAP + m_compBox->getSize().height) + 1);
       
            bottomY -= (COMPOSITION_BOX_BOTTOM_GAP + COMPOSITION_BOX_TOP_GAP + m_compBox->getSize().height);
        }

#ifdef __MMI_CSTAR_PHRASE_INPUT__
        if (m_inputArea)
        {
            if (!m_inputArea->getHidden() &&
                !(m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))              
            {            
                m_inputArea->setPos(m_inputArea->getPos().x, 
                    bottomY - m_inputArea->getSize().height + RESIZEABLE_INPUT_AREA_COVERED_BOTTOM_HEIGHT + 1);
            
                bottomY -= (m_inputArea->getSize().height - RESIZEABLE_INPUT_AREA_COVERED_BOTTOM_HEIGHT);
            }
        }
#endif

    }  


    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer);

    if (m_uiBottomY == bottomY)
    {
        if (m_fixedUIRect != VfxRect(m_uiX, m_uiBottomY + 1, 0, 0))
        {
            inputServer->m_currInputBinding->getConnection()->setIMEUILayout(0, 0, 0, 0, 0, 0, 0, 0, isVKAnim);

            m_fixedUIRect = VfxRect(m_uiX, m_uiBottomY + 1, 0, 0);
        }
    }
    else
    {
        VfxRect newRect(m_uiX, bottomY + 1, m_uiWidth, m_uiBottomY - bottomY);

        if (m_fixedUIRect != newRect)
        {
            inputServer->m_currInputBinding->getConnection()->setIMEUILayout(
                m_uiX,
                bottomY + 1,
                m_uiWidth,
                m_uiBottomY - bottomY,
                vkRect.origin.x,
                vkRect.origin.y,
                vkRect.size.width,
                vkRect.size.height,
                isVKAnim);

            m_fixedUIRect = newRect;
        }
    }
}


#if defined(__MMI_IME_FLOATING_CAND_BOX__)
void VadpInputServerUI::layoutAllFloatingUIComponents()
{
    if (!m_isActive)
    {
        return;
    }

#ifdef __MMI_IME_PLUG_IN__
    U32 custom_control;
    
    custom_control = mmi_imui_get_control_showed_flag();
    custom_control = custom_control & mmi_ime_sdk_get_custom_control_mask();
    if (custom_control != 0)
    {
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_DRAW_CURRENT_FLOATING_UI_CONTROLS, custom_control, 0) == 0)
        {
            return;
        }  
    }
    else
#endif
    {
        VfxS32 floatingUIHeight = getFloatingUIHeight();
    
        if (floatingUIHeight == 0)
        {
            m_floatingUIRect = VFX_RECT_ZERO;
            return;
        }

        VfxS32 cursorX, cursorY, cursorWidth, cursorHeight;

        VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer);

        if (!inputServer->m_currInputBinding->getConnection()->getCursorRect(&cursorX, &cursorY, &cursorWidth, &cursorHeight))
        {
            return;
        }

        VfxS32 bottomY;

        if (cursorY + cursorHeight + FLOATING_CANDIDATE_BOX_GAP_FROM_CURSOR + floatingUIHeight - 1 < m_uiBottomY - m_fixedUIRect.getHeight() + 1)
        {
            bottomY = cursorY + cursorHeight + FLOATING_CANDIDATE_BOX_GAP_FROM_CURSOR + floatingUIHeight - 1;
        }
        else
        {
            bottomY = cursorY - FLOATING_CANDIDATE_BOX_GAP_FROM_CURSOR;
        }


        if (!m_candBox->getHidden() && (m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))
        {
            m_candBox->setPos(m_uiFloatingX + CANDIDATE_BOX_LEFT_GAP, bottomY - m_candBox->getSize().height + 1);
       
            bottomY -= m_candBox->getSize().height;
        }
    

#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
        if (!m_rCompBox->getHidden() &&
            (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
        {
            VfxS32 rCompBoxBottomY;

            if (m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING)
            {
                rCompBoxBottomY = bottomY;
            }
            else
            {
                rCompBoxBottomY = m_fixedUIRect.getY() - 1;
            }
        
            m_rCompBox->setPos(m_uiFloatingX + COMPOSITION_BOX_LEFT_GAP, 
                rCompBoxBottomY - m_rCompBox->getSize().height + RESIZEABLE_COMP_AREA_COVERED_BOTTOM_HEIGHT + 1);

            bottomY -= (m_rCompBox->getSize().height - RESIZEABLE_COMP_AREA_COVERED_BOTTOM_HEIGHT);
        }
        else
#endif
        {
            if (!m_compBox->getHidden() && 
                (m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING) &&
                !(m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
            {
                m_compBox->setPos(m_uiFloatingX + COMPOSITION_BOX_LEFT_GAP, bottomY - m_compBox->getSize().height + 1);
           
                bottomY -= m_compBox->getSize().height;
            }
        }

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    if (m_inputArea)
    {
        if (!m_inputArea->getHidden() && 
            (m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))
        {
            m_inputArea->setPos(m_uiFloatingX + INPUT_BOX_LEFT_GAP,
                bottomY - m_inputArea->getSize().height + RESIZEABLE_INPUT_AREA_COVERED_BOTTOM_HEIGHT + 1);

            bottomY -= (m_inputArea->getSize().height - RESIZEABLE_INPUT_AREA_COVERED_BOTTOM_HEIGHT);
        }
    }
#endif

    m_floatingUIRect = VfxRect(m_uiFloatingX, bottomY + 1, m_uiFloatingWidth, floatingUIHeight);
    }
    
}


VfxS32 VadpInputServerUI::getFloatingUIHeight()
{
    VfxS32 height = 0;
   
    if (!m_candBox->getHidden() && (m_candBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))
    {
        height += m_candBox->getSize().height;
    }
    

#if defined(__MMI_IME_FTE_ENHANCE__)
    if (!m_rCompBox->getHidden() && (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE))
    {
        height += m_rCompBox->getSize().height;
    }
    else
#endif
    {
        if (!m_compBox->getHidden() && (m_compBoxFlag & MMI_IMUI_SELECTION_AREA_FLAG_FLOATING))
        {
            height += m_compBox->getSize().height;
        }
    }

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    if (m_inputArea && !m_inputArea->getHidden())
    {
        height += m_inputArea->getSize().height;
    }
#endif

    return height;
}
#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */


#if defined(__MMI_TOUCH_SCREEN__)
void VadpInputServerUI::drawHandWritingStroke(mmi_pen_point_struct *previous_point, mmi_pen_point_struct *point)
{
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
    if (m_singleBlockHWPanel)
    {
        VfxPoint prePoint(previous_point->x, previous_point->y);
        VfxPoint curPoint(point->x, point->y);

        m_singleBlockHWPanel->drawStroke(prePoint, curPoint);
    }
#endif
}


void VadpInputServerUI::clearHandWritingStroke()
{
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) 
    if (m_singleBlockHWPanel)
    {
        m_singleBlockHWPanel->clearStroke();
    }
#endif

}

#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) ||  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void VadpInputServerUI::createVirtualKeyboard()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();
            
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    VFX_OBJ_CREATE(m_vk, VcpVKMain,  inputBinding->getOwner());
#else
    VFX_OBJ_CREATE_EX(m_vk, VcpVK,  inputBinding->getOwner() ,(inputBinding->getOwner()));
#endif 
    m_vk->setHidden(VFX_TRUE);
    
    m_isVKHidden = VFX_TRUE;
    
    topLevel->addChildFrame(m_vk);
    
    VFX_ASSERT(m_vk);
    
    m_vk->setPos(m_uiX, m_uiBottomY + 1);
    
    m_vk->setAutoAnimate(VFX_TRUE);

    m_vk->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);

    m_vk->m_signalButtonDown.connect(this, &VadpInputServerUI::onVKButtonDown);
    m_vk->m_signalButtonMove.connect(this, &VadpInputServerUI::onVKButtonMove);
    m_vk->m_signalButtonLongtap.connect(this, &VadpInputServerUI::onVKButtonLongTap);
    m_vk->m_signalButtonUp.connect(this, &VadpInputServerUI::onVKButtonUp);
    m_vk->m_signalButtonAbort.connect(this, &VadpInputServerUI::onVKButtonAbort);
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    m_vk->m_signalEventLongtap.connect(this, &VadpInputServerUI::onVKButtonLongTapEvent);
    m_vk->m_signalButtonLongtapTimeUp.connect(this, &VadpInputServerUI::onVKButtonLongTapTimeUp);
	m_vk->m_signalButtonRepeat.connect(this, &VadpInputServerUI::onVKButtonRepeat);
#endif
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__

    m_vk->registerDisplayCallback(this, (const VcpVKDisplayCB)&VadpInputServerUI::vkDisplayCallback);
    m_vk->registerMultiPopupCallback(this, (const VcpVKMultiPopupCB)&VadpInputServerUI::vkMultiPopupCallback);
#endif
    if (m_vkEffectValidationTimer)
    {
        m_vkEffectValidationTimer->stop();
    
        VFX_OBJ_CLOSE(m_vkEffectValidationTimer);
    }

    // gui_cancel_timer(VadpInputServerUI::vkEffectValidationCheckTimer);
}


void VadpInputServerUI::translateVKEvent(VcpVKBtnTypeEnum btnType, VfxU32 value, gui_virtual_keyboard_pen_enum *vk_event, gui_pen_event_param_struct *vk_para)
{
    *vk_event = GUI_VKBD_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(vk_para);

    if (btnType == VCP_VK_BUTTON_TYPE_CHAR)
    {
        *vk_event = GUI_VKBD_PEN_CHAR_I;
        vk_para->_u.i = (VfxWChar)value;
    }
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

	else if (btnType == VCP_VK_BUTTON_TYPE_STRING)
    {
        *vk_event = GUI_VKBD_PEN_V3_CHAR_I_STRING;
         vk_para->_u.p = (VfxWChar*)value;
    }
#endif
    else if (btnType == VCP_VK_BUTTON_TYPE_FUNC)
    {
        *vk_event = (gui_virtual_keyboard_pen_enum)value;
    }
    else
    {
        VFX_ASSERT(0);
    }
}

#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

void VadpInputServerUI::createMiniVirtualKeyboard()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            
    VFX_OBJ_CREATE(m_vkMini, VcpVKMini, this);
    
    m_vkMini->setHidden(VFX_TRUE);
    
    
    topLevel->addChildFrame(m_vkMini);

    VFX_ASSERT(m_vkMini);
    


    m_vkMini->setPosZ(VFX_TOP_LEVEL_Z_IME_UI -1);

    m_vkMini->m_signalButtonMove.connect(this, &VadpInputServerUI::onVKButtonMove);
    m_vkMini->m_signalButtonUp.connect(this, &VadpInputServerUI::onVKButtonUp);
    m_vkMini->m_signalButtonAbort.connect(this, &VadpInputServerUI::onVKButtonAbort);

    gui_cancel_timer(VadpInputServerUI::vkEffectValidationCheckTimer);
}

#endif


#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__
void VadpInputServerUI::vkDisplayCallback(VcpVKDisplayCbPara &vkDisplayCbfo)
{
    gui_virtual_keyboard_display_callback_type_enum flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_END;
    PU8 text;
    PU8 image;
    gui_virtual_keyboard_key_state_enum key_state;

    if (vkDisplayCbfo.buttonInfo.pos == VCP_VK_BUTTON_IMG_POS_BG)
    {
        // because the display callback in pluto do not support getting background of image
        vkDisplayCbfo.image.setNull();
        return;
    }
    
    switch (vkDisplayCbfo.buttonInfo.state)
    {
    case VCP_VK_BUTTON_STATE_HILITE:
        key_state = GUI_VK_KEY_STATE_HIGHLIGHT;
        break;
         
    case VCP_VK_BUTTON_STATE_DISABLED:
        key_state = GUI_VK_KEY_STATE_DISABLE;
        break;
         
    case VCP_VK_BUTTON_STATE_NORMAL:
        key_state = GUI_VK_KEY_STATE_NORMAL;
        break;

    case VCP_VK_BUTTON_STATE_POPUP:
        key_state = GUI_VK_KEY_STATE_POPUP;
        break;
        
    default:
        key_state = GUI_VK_KEY_STATE_NONE;
        VFX_ASSERT(0);
        break;
    }
    
    mmi_imc_pen_vk_icon_display_callback((U32)vkDisplayCbfo.buttonInfo.buttonContent,
                         &flag, &text, &image, key_state);

    if (flag == GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG ||
        flag == GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG_TEXT)
    {
        vkDisplayCbfo.image.setMem((const VfxU8 *)image);
    }
    else
    {
        vkDisplayCbfo.image.setNull();
    }
}


VfxBool VadpInputServerUI::vkMultiPopupCallback(VfxU32 content, VfxU32* index)
{
    VfxS32 noUse = 0;
    if (::mmi_imc_pen_vk_event_callback((gui_virtual_keyboard_pen_enum)content, (S32)noUse, (U32)index) == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

#endif
void VadpInputServerUI::onVKButtonDown(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);

    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_DOWN_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);
}


void VadpInputServerUI::onVKButtonRepeat(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);

    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_REPEAT_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);
}




void VadpInputServerUI::onVKButtonMove(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);

    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_MOVE_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);
}
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
void VadpInputServerUI::onVKButtonLongTapEvent(VfxObject *sender, VcpVKLongtapHintEvt& event)// , VfxPenEvent& forMini)
{
    VfxPenEvent temp;
    temp.pos = event.pos;
    event.pos = m_vk->convertPointTo(temp.getRelPos(m_vk), m_vkMini);
       m_vkMini->onPenInput(event);
}

void VadpInputServerUI::onVKButtonLongTapTimeUp(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    VfxU32 index = m_vk->getCurrButtonIndex();
	VfxRect rect ;
	VfxPoint Relpoint ;

      m_vkMini->setCurrButtonIndex( index);  // to get layouto

    /* if nothing is on it it will show nothing */
	VfxPoint point = m_vkMini->getCurrButtonRectMini(index);
	Relpoint = m_vk->convertPointTo(point, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
    m_vkMini->setPos( Relpoint); 
    m_vkMini->onUpdate();
    m_vkMini->setHidden(VFX_FALSE);
    
    rect = m_vk->getCurrButtonRectMain();
    /* to hilight the nearest button */
    {
        VfxPoint point(rect.origin.x,rect.origin.y);
        VcpVKLongtapHintEvt event;
        VfxPenEvent temp;
        event.pos = point;
        temp.pos = event.pos ;
        event.type = VFX_PEN_EVENT_TYPE_MOVE;
        event.pos = m_vk->convertPointTo(temp.getRelPos(m_vk), m_vkMini);
        m_vkMini->onPenInput(event);
        m_vk->invalidate();
    }

}

#endif

void VadpInputServerUI::onVKButtonLongTap(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);

    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_LONGTAP_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);
}


void VadpInputServerUI::onVKButtonUp(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);

    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_UP_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    m_vkMini->setHidden(VFX_TRUE);
#endif
    updateVKButtonValidation();
}


void VadpInputServerUI::onVKButtonAbort(VfxObject *sender, VcpVKBtnTypeEnum btnType, VfxU32 value)
{
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    translateVKEvent(btnType, value, &vk_event, &vk_para);
    
    dispatchVKEvent(MMI_IMUI_MESSAGE_PEN_ABORT_IN_VIRTUAL_KEYBOARD, vk_event, &vk_para);

    updateVKButtonValidation();
}


void VadpInputServerUI::dispatchVKEvent(VfxU8 penEvent, gui_virtual_keyboard_pen_enum vkEvent, gui_pen_event_param_struct *vkParaPtr)
{
    if (vkEvent == GUI_VKBD_PEN_NEWLINE ||
        vkEvent == GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE)
    {
        VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
        VsrvInputBinding* inputBinding = inputServer->getBinding();

        if (inputBinding)
        {
            if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH ||
                inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
            {
                if (penEvent == MMI_IMUI_MESSAGE_PEN_UP_IN_VIRTUAL_KEYBOARD)
                {
                    inputBinding->m_inputConnectionPtr->sendIMENotification(IME_NOTIFICATION_SPECIAL_VK_ENTER_KEY_CLICKED, NULL);
                }
                
                return;
            }
        }
    }
	
#if VCP_TEXT_CLIPBOARD_SUPPORT
	if(penEvent == MMI_IMUI_MESSAGE_PEN_DOWN_IN_VIRTUAL_KEYBOARD)
	{	
		VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
		VsrvInputBinding* inputBinding = inputServer->getBinding();

		if (inputBinding && (vkEvent == GUI_VKBD_PEN_CAPSLOCK || vkEvent == GUI_VKBD_PEN_CHANGE_MODE || vkEvent == GUI_VKBD_PEN_SYMBPICKER))
		{
			inputBinding->m_inputConnectionPtr->sendIMENotification(IME_NOTIFICATION_PEN_DOWN_IN_IMUI_CONTROL, NULL); //to hide clipbord when tap vk key
		}
	}
#endif
	
    mmi_imui_message_struct mes_str;

    mes_str.message_id = penEvent;
    mes_str.param_0 = (U32)vkEvent;
    mes_str.param_1 = (U32)vkParaPtr;

    mmi_imc_pen_event_command_handler(&mes_str);
}


void VadpInputServerUI::setupVirtualKeyboard(mmi_imui_message_struct_p msg_ptr)
{
    mmi_imui_virtual_keyboard_parameter_p vk_parameter = (mmi_imui_virtual_keyboard_parameter_p)msg_ptr->param_0;

    if (!vk_parameter)
    {
        return;
    }

    VfxBool vkChanged = VFX_FALSE;
    
    if (m_vk->getAttr() != (VcpVKAttr )vk_parameter->vk_style)
    {
        m_vk->setAttr((VcpVKAttr)vk_parameter->vk_style);
        vkChanged = VFX_TRUE;
    }

    if (m_vk->getType() != (VcpVKAttr )vk_parameter->vk_type)
    {
        m_vk->setType((VcpVKTypeEnum)vk_parameter->vk_type);
        vkChanged = VFX_TRUE;
    }
    
    if (vkChanged)
    {
        updateVKSpecialEnterKey();
    }
}


void VadpInputServerUI::updateVKSpecialEnterKey()
{
/* For toggle state handling */
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 

    VsrvInputBinding *inputBinding = inputServer->getBinding();
if(inputBinding)
{
   
    if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
    {
        wgui_virtual_keyboard_add_toggle_state_key((toggle_state_key_index_enum)GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_ENTER,(toggle_state_id_mapping_enum) GUI_VIRTUAL_KEYBOARD_ENTER_KEY_GO);
    }
    else if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH )
    {
        wgui_virtual_keyboard_add_toggle_state_key((toggle_state_key_index_enum)GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_ENTER,(toggle_state_id_mapping_enum) GUI_VIRTUAL_KEYBOARD_ENTER_KEY_SEARCH);
    }
    else
    {
        wgui_virtual_keyboard_add_toggle_state_key((toggle_state_key_index_enum)GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_ENTER,(toggle_state_id_mapping_enum) GUI_VIRTUAL_KEYBOARD_ENTER_KEY_ENTER);
    }
}

#elif defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__

    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 

    VsrvInputBinding *inputBinding = inputServer->getBinding();

    m_vk->clearAllButtonImage();

#if defined(__MMI_IME_FTE_ENHANCE__)
    if (inputBinding &&
        (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH ||
         inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE))
    {
        VcpVKBtnImg enterBtn;
        
        switch (mmi_imc_pen_get_curr_input_style())
        {
        case MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY:

            enterBtn.content = GUI_VKBD_PEN_NEWLINE;
            
            if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }
            else if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }

            if (mmi_imc_is_rotated())
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_D);
            }
            else
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_D);
            }
                
            m_vk->setButtonImage(enterBtn);
            break;

        case MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC:

            enterBtn.content = GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE;
            
            if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }
            else if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }
            
            if (mmi_imc_is_rotated())
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_D);
            }
            else
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_D);
            }
            
            m_vk->setButtonImage(enterBtn);
            break;

        case MMI_IMC_PEN_INPUT_STYLE_HW:
            
            enterBtn.content = GUI_VKBD_PEN_NEWLINE;

            if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }
            else if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
            {
                enterBtn.fgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_N);
                enterBtn.fgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_H);
                enterBtn.fgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_D);
                enterBtn.fgPopupImg = VFX_IMAGE_SRC_NULL;
            }

            if (mmi_imc_is_rotated())
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_D);
            }
            else
            {
                enterBtn.bgImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_N);
                enterBtn.bgPopupImg = VFX_IMAGE_SRC_NULL;
                enterBtn.bgHighlightImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_H);
                enterBtn.bgDisabledImg.setResId(IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_D);
            }
                
            m_vk->setButtonImage(enterBtn);
            break;

        default:
            return;
            break;
        }
    }
#endif /* #if defined(__MMI_IME_FTE_ENHANCE__) */
#endif
}
#define VK_MAX_DISABLE_EVENTS  20

#define VK_MAX_SET_CHAR  100

void VadpInputServerUI::updateVKButtonValidation()
{
    if (!m_vk)
    {
        return;
    }
    
    MMI_BOOL is_allowed_char, is_set_char;
    MMI_BOOL is_allowed_event, is_set_event;
    UI_character_type vkCharactersList[VK_MAX_SET_CHAR + 1];
    gui_virtual_keyboard_pen_enum vkEventList[VK_MAX_DISABLE_EVENTS + 1];

    vkCharactersList[VK_MAX_SET_CHAR] = 0;
    vkEventList[VK_MAX_DISABLE_EVENTS] = GUI_VKBD_PEN_NONE;
    
    is_set_char = mmi_imm_get_allowed_or_disabled_characters(&is_allowed_char, vkCharactersList);
   
    is_set_event = mmi_imm_get_allowed_or_disabled_events(&is_allowed_event, vkEventList);

    if (vkCharactersList[VK_MAX_SET_CHAR] != 0 || vkEventList[VK_MAX_DISABLE_EVENTS] != GUI_VKBD_PEN_NONE)
    {
        VFX_ASSERT(0);
    }
    
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();

    if (inputBinding)
    {
        if (inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_SEARCH ||
            inputBinding->m_vkEnterKeyStyle == IME_VK_ENTER_KEY_STYLE_DONE)
        {
            if (inputBinding->m_isVKEnterKeyEnabled)
            {
                if (is_set_char && is_allowed_char)
                {
                    insertChar(vkCharactersList, L'\n');
                    
                    if (is_set_event)
                    {
                        deleteVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                        deleteVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                    }
                }
                else if (is_set_char && is_set_event && !is_allowed_char && !is_allowed_event)
                {
                    deleteChar(vkCharactersList, L'\n');
                    deleteVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                    deleteVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                }
                else if (!is_set_char && is_set_event && !is_allowed_event)
                {
                    deleteVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                    deleteVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                }
                else if (is_set_char && !is_set_event && !is_allowed_char)
                {
                    deleteChar(vkCharactersList, L'\n');
                }
            }
            else
            {
                if (!is_set_char && !is_set_event)
                {
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                    is_allowed_event = MMI_FALSE;
                    is_set_event = MMI_TRUE;
                }
                else if (is_set_char && is_allowed_char)
                {
                    deleteChar(vkCharactersList, L'\n');
                    
                    if (is_set_event)
                    {
                        insertVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                        insertVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                    }
                }
                else if (is_set_char && is_set_event && !is_allowed_char && !is_allowed_event)
                {
                    insertChar(vkCharactersList, L'\n');
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                }
                else if (!is_set_char && is_set_event && !is_allowed_event)
                {
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_NEWLINE);
                    insertVKEvent(vkEventList, GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE);
                }
                else if (is_set_char && !is_set_event && !is_allowed_char)
                {
                    insertChar(vkCharactersList, L'\n');
                }
            }
        }
    }
    
    if (!is_set_char && !is_set_event)
    {
        m_vk->resetCharButtons();
        
        m_vk->resetFuncButtons();
        
        return;
    }
    else if (is_set_char && is_allowed_char)
    {
        if (is_set_event)
        {
            //m_vk->resetCharButtons();
            m_vk->setDisabledFuncButtons(vkEventList);
        }
        else
        {
            m_vk->resetFuncButtons();
        }

        m_vk->setAllowedCharButtons(VFX_WSTR_MEM(vkCharactersList));
    }
    else if (is_set_char && is_set_event && !is_allowed_char && !is_allowed_event)
    {
        m_vk->setDisabledCharButtons(VFX_WSTR_MEM(vkCharactersList));
        m_vk->setDisabledFuncButtons(vkEventList);
    }
    else if (!is_set_char && is_set_event && !is_allowed_event)
    {
        m_vk->resetCharButtons();
        m_vk->setDisabledFuncButtons(vkEventList);
    }
    else if (is_set_char && !is_set_event && !is_allowed_char)
    {
        m_vk->resetFuncButtons();
        m_vk->setDisabledCharButtons(VFX_WSTR_MEM(vkCharactersList));
    }
    else
    {
        m_vk->resetCharButtons();
        
        m_vk->resetFuncButtons();
    }
}


void VadpInputServerUI::insertChar(UI_string_type str, UI_character_type character)
{
    if (mmi_ucs2chr((const CHAR *)str, character))
    {
        mmi_ucs2ncat((CHAR *)str,(const CHAR *)&character, 1);
    }
}


void VadpInputServerUI::deleteChar(UI_string_type str, UI_character_type character)
{
    VfxS32 i = 0, j = 0;
    
    UI_character_type tempStr[VK_MAX_SET_CHAR + 1];

    for (;str[i];i++)
    {
        if (str[i] != character)
        {
            tempStr[j++] = str[i];
            tempStr[j] = 0;
        }
    }

    memcpy(str, tempStr, (VK_MAX_SET_CHAR + 1) * sizeof(UI_character_type));
}

        
void VadpInputServerUI::insertVKEvent(gui_virtual_keyboard_pen_enum *eventList, gui_virtual_keyboard_pen_enum event)
{
    VfxS32 i = 0;

    for(;eventList[i] != GUI_VKBD_PEN_NONE;i++)
    {
        if (eventList[i] == event)
        {
            break;
        }
    }

    if (eventList[i] == GUI_VKBD_PEN_NONE)
    {
        eventList[i] = event;
        eventList[i+1] = GUI_VKBD_PEN_NONE;
    }
}


void VadpInputServerUI::deleteVKEvent(gui_virtual_keyboard_pen_enum *eventList, gui_virtual_keyboard_pen_enum event)
{
    VfxS32 i = 0, j = 0;

    gui_virtual_keyboard_pen_enum tempEventList[VK_MAX_DISABLE_EVENTS + 1] = {GUI_VKBD_PEN_NONE};

    for(;eventList[i] != GUI_VKBD_PEN_NONE;i++)
    {
        if (eventList[i] != event)
        {
            tempEventList[j++] = eventList[i];
            tempEventList[j] = GUI_VKBD_PEN_NONE;
        }
    }

    memcpy(eventList, tempEventList, (VK_MAX_DISABLE_EVENTS + 1) * sizeof(gui_virtual_keyboard_pen_enum));
    }


void VadpInputServerUI::onVKEffectValidationCheckTimer(VfxTimer *timer)
{
    s_enableVKTransitionEffect = VFX_TRUE;

    VFX_OBJ_CLOSE(m_vkEffectValidationTimer);
}

void VadpInputServerUI::vkEffectValidationCheckTimer()
{
    s_enableVKTransitionEffect = VFX_TRUE;

    gui_cancel_timer(VadpInputServerUI::vkEffectValidationCheckTimer);
}

#endif /* #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */



void VadpInputServerUI::onInit()
{
    VfxObject::onInit();
}


void VadpInputServerUI::onDeinit()
{
    VfxObject::onDeinit();
}


#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
void VadpInputServerUI::setStrokeAreaAndStart(VfxU32 maxPoint, VfxPenStrokePoint *points, VfxU32 areaCount, VfxPenStrokeHandWritingRegion *areas, VfxPenStrokeHandWritingRegion *extArea)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->startCaptureStrokes(m_singleBlockHWPanel, points, maxPoint, areas, areaCount, extArea);
#endif
}


void VadpInputServerUI::stopStroke()
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->stopCaptureStrokes(m_singleBlockHWPanel);
#endif
}


void VadpInputServerUI::beginStrokesOfCharacter()
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->beginStrokesOfCharacter(m_singleBlockHWPanel);
#endif
}


void VadpInputServerUI::endStrokesOfCharacter()
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->endStrokesOfCharacter(m_singleBlockHWPanel);
#endif
}


void VadpInputServerUI::changeHWArea(const VfxPenStrokeHandWritingRegion * areas, VfxU32 areaCount, const VfxPenStrokeHandWritingRegion * extArea)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->changeHandWritingArea(m_singleBlockHWPanel, areas, areaCount, extArea);
#endif
}


void VadpInputServerUI::changeHWAreaEx(const VfxPenStrokeHandWritingRegion * areas, VfxU32 areaCount, const VfxPenStrokeHandWritingRegion * extArea)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    
    penService->changeHandWritingAreaEx(m_singleBlockHWPanel, areas, areaCount, extArea);
#endif
}

#endif /* #if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) */

#if defined __MMI_IME_CANDIDATE_GRID__
void VadpInputServerUI::updateSelBoxTheme(VcpCandGrid*selBox)
{
    VcpSelBoxThemeStruct selBoxTheme;  //make new struct

    // candidate
    selBoxTheme.candFont = mapFontDesc(current_ime_theme->text_font);
    selBoxTheme.candNormalColor = VfxColor(mapColorValue(current_ime_theme->cand_text_color));
    selBoxTheme.candHiliteColor = VfxColor(mapColorValue(current_ime_theme->cand_highlighted_text_color));
    selBoxTheme.candRadicalNormalColor = VfxColor(mapColorValue(current_ime_theme->stroke_color));
    selBoxTheme.candRadicalHiliteColor = VfxColor(mapColorValue(current_ime_theme->highlighted_stroke_color));
    selBoxTheme.candGap = current_ime_theme->text_space;


#if defined(__COSMOS_MMI__) 
    selBoxTheme.gridCandBg.setResId(VADP_IMG_IME_CG_CAND_BG);
    selBoxTheme.gridCandBgHl.setResId(VADP_IMG_IME_CG_CAND_BG_HL);
    selBoxTheme.gridFixedButtonBg.setResId(IMG_ID_FUNCTION_BKG_9SLICE);;
    selBoxTheme.gridFixedButtonBgHl.setResId(VADP_IMG_IME_CG_CAND_BG_HL);;
    selBoxTheme.gridBg.setResId(VADP_IMG_IME_CG_BG);
    selBoxTheme.deleteImg.setResId(VADP_IMG_IME_CG_BACKSPACE);
    selBoxTheme.backImg.setResId(VADP_IMG_IME_CG_BACK);
    selBoxTheme.arrowDownImg.setResId(VADP_IMG_IME_CG_ARROWDOWN);
    selBoxTheme.arrowDownDisableImg.setResId(VADP_IMG_IME_CG_ARROWDOWNDIS);
    selBoxTheme.arrowUpImg.setResId(VADP_IMG_IME_CG_ARROWUP);
    selBoxTheme.arrowUpDisableImg.setResId(VADP_IMG_IME_CG_ARROWUPDIS);
#elif defined(__MMI_IME_FTE_ENHANCE__)


#else


#endif



#if defined(__COSMOS_MMI__) 
    selBoxTheme.candHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_SMALL);
    selBoxTheme.candDullHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_SMALL);
    selBoxTheme.candRadicalHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_SMALL);
    selBoxTheme.candRadicalDullHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_SMALL);
    selBoxTheme.candHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_MEDIUM);
    selBoxTheme.candDullHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_MEDIUM);
    selBoxTheme.candRadicalHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_MEDIUM);
    selBoxTheme.candRadicalDullHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_MEDIUM);
    selBoxTheme.candHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_LARGE);
    selBoxTheme.candDullHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_LARGE);
    selBoxTheme.candRadicalHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_LARGE);
    selBoxTheme.candRadicalDullHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.candHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_highlight_small);
    selBoxTheme.candDullHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_small);
    selBoxTheme.candRadicalHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_highlight_small);
    selBoxTheme.candRadicalDullHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_small);
    selBoxTheme.candHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_highlight_medium);
    selBoxTheme.candDullHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_medium);
    selBoxTheme.candRadicalHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_highlight_medium);
    selBoxTheme.candRadicalDullHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_medium);
    selBoxTheme.candHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_highlight_large);
    selBoxTheme.candDullHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_large);
    selBoxTheme.candRadicalHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_highlight_large);
    selBoxTheme.candRadicalDullHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_large);
#else
    selBoxTheme.candHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->cand_highlight_color));
    selBoxTheme.candDullHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->cand_highlight_color));
    selBoxTheme.candRadicalHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->stroke_highlight_color));
    selBoxTheme.candRadicalDullHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->stroke_highlight_color));
#endif



    // the background of selection box
#if defined(__COSMOS_MMI__)
    selBoxTheme.bgImageLarge.setResId(VADP_IMG_IME_CAND_BG_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.bgImageSmall.setMem((const VfxU8 *)current_ime_theme->cand_background_small);
    selBoxTheme.focusedBgImageSmall.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_small);
    selBoxTheme.bgImageMedium.setMem((const VfxU8 *)current_ime_theme->cand_background_medium);
    selBoxTheme.focusedBgImageMedium.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_medium);
    selBoxTheme.bgImageLarge.setMem((const VfxU8 *)current_ime_theme->cand_background_large);
    selBoxTheme.focusedBgImageLarge.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_large);
#else
    selBoxTheme.borderColor = VfxColor(mapColorValue(current_ime_theme->border_color));
    selBoxTheme.focusedBorderColor = VfxColor(mapColorValue(current_ime_theme->focused_border_color));

    if (current_ime_theme->background_filler->b)
    {
        selBoxTheme.bgImage.setMem((const VfxU8 *)current_ime_theme->background_filler->b);
        selBoxTheme.bgColor = VfxColor();
    }
    else
    {
        selBoxTheme.bgImage = VfxImageSrc();
        selBoxTheme.bgColor = VfxColor(mapColorValue(current_ime_theme->background_filler->c));
    }

    if (current_ime_theme->focused_background_filler->b)
    {
        selBoxTheme.focusedBgImage.setMem((const VfxU8 *)current_ime_theme->focused_background_filler->b);
        selBoxTheme.focusedBgColor = VfxColor();
    }
    else
    {
        selBoxTheme.focusedBgImage = VfxImageSrc();
        selBoxTheme.focusedBgColor = VfxColor(mapColorValue(current_ime_theme->focused_background_filler->c));
    }
#endif

    selBox->setTheme(selBoxTheme);

}
VcpCandGrid * VadpInputServerUI::createCandGrid()
{
    VcpCandGrid* selBox;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();



    VFX_OBJ_CREATE(selBox, VcpCandGrid, inputBinding->getOwner());

    selBox->setHidden(VFX_FALSE);//test


    topLevel->addChildFrame(selBox);

    VFX_ASSERT(selBox);

    //m_sCompBox->setPos(m_uiX, m_uiBottomY + 1);


    selBox->setPosZ(VFX_TOP_LEVEL_Z_IME_UI -1);

    /* add signals */
    selBox->m_signalGridClick.connect(this, &VadpInputServerUI::onCandGridClick);

    updateSelBoxTheme(selBox);
     selBox->layoutButtons();
    return selBox;


}

void VadpInputServerUI::onCandGridClick(VfxObject *selBox, VfxS32 index)
{
    mmi_imui_message_struct mes_str;

    if (index <VCP_CAND_GRID_CANDIDATE)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_GRID_BOX;
        mes_str.param_0 =     MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT; 
        mes_str.param_1 = index;

        mmi_imc_pen_event_command_handler(&mes_str);

        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX ;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT;
        mes_str.param_1 = index;
    }

    else if (index ==VCP_CAND_GRID_BACKSPACE)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_GRID_PEN_DELETE ;
    }
    else if (index ==VCP_CAND_GRID_PREPAGE)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_UP;
    }
    else if (index ==VCP_CAND_GRID_NEXTPAGE)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_DOWN ;
    }
    else if (index ==VCP_CAND_GRID_BACK)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_GRID_PEN_BACK;
    }

    //hack <001> to override animation process of vk , as vk is hidden by service when we came here
    //so it will animate it , visually not very appealing , in this case , so have to stop animation
    halt_vk_animation();

    mmi_imc_pen_event_command_handler(&mes_str);
}

VfxS32 VadpInputServerUI::updateCandGrid(VcpCandGrid *selBox, mmi_imui_update_selection_area_struct_p updatePtr)
{ 

    VfxU32 flag = 0;

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_PRE_PAGE;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_NEXT_PAGE;
    }


    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_R2L)
    {
        flag |= VCP_SEL_BOX_FLAG_R2L;
    }


    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_LAST_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_LAST_PAGE;
    }




    return    selBox->update((const VfxWChar *)updatePtr->str_ptr, 
        updatePtr->count,
        updatePtr->highlight_index,
        flag);

}
#endif




#if defined __MMI_IME_SCROLLING_COMPOSITION__

void VadpInputServerUI::updateSelBoxTheme(VcpScrollableSelBox *selBox)
{
    VcpSelBoxThemeStruct selBoxTheme;  //make new struct

    
#if defined(__COSMOS_MMI__) 
    
      
selBoxTheme.scrollableboxBg.setResId(VADP_IMG_IME_SC_BG);
selBoxTheme.scrollableboxCandBg.setResId(VADP_IMG_IME_SC_CAND_BG);
selBoxTheme.scrollableboxCandBgHl.setResId(VADP_IMG_IME_SC_CAND_BG_HL);
   
#elif defined(__MMI_IME_FTE_ENHANCE__)
    
    //gaurav
    
#endif
    

    // candidate
    selBoxTheme.candFont = mapFontDesc(current_ime_theme->text_font);
    selBoxTheme.candNormalColor = VfxColor(mapColorValue(current_ime_theme->cand_text_color));
    selBoxTheme.candHiliteColor = VfxColor(mapColorValue(current_ime_theme->cand_highlighted_text_color));


    selBox->setTheme(selBoxTheme);

}



VcpScrollableSelBox* VadpInputServerUI::createScrollableSelBox()
{
    VcpScrollableSelBox* selBox;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();

    VFX_OBJ_CREATE(selBox, VcpScrollableSelBox, inputBinding->getOwner());

    selBox->setHidden(VFX_FALSE);//test


    topLevel->addChildFrame(selBox);

    VFX_ASSERT(selBox);

    //m_sCompBox->setPos(m_uiX, m_uiBottomY + 1);


    selBox->setPosZ(VFX_TOP_LEVEL_Z_IME_UI -1);

    /* add signals */
    selBox->m_signalCandUp.connect(this, &VadpInputServerUI::onSelBoxCandUp);
    selBox->m_signalCandDown.connect(this, &VadpInputServerUI::onSelBoxCandDown);
    selBox->enableHorizontalScrollIndicator(VFX_FALSE);
    selBox->enableVerticalScrollIndicator(VFX_FALSE);
    selBox->enableBoundaryLight(VFX_FALSE);


    updateSelBoxTheme(selBox);

    return selBox;


}


VfxS32 VadpInputServerUI::updateScrollableSelBox(VcpScrollableSelBox *selBox, mmi_imui_update_selection_area_struct_p updatePtr)
{ 

    return    selBox->update((const VfxWChar *)updatePtr->str_ptr, 
        updatePtr->count,
        updatePtr->highlight_index,
        0);

}
#endif


VfxS32 VadpInputServerUI::updateSelBox(VcpSelBox *selBox, mmi_imui_update_selection_area_struct_p updatePtr)
{

    VfxU32 flag = 0;

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_FOCUS)
    {
        flag |= VCP_SEL_BOX_FLAG_FOCUS;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_PRE_PAGE;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_NEXT_PAGE;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW)
    {
        flag |= VCP_SEL_BOX_FLAG_SHOW_ARROW;
    }

    if(updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_SHOW_EXPAND_BUTTON)
    {
        flag |= VCP_SEL_BOX_FLAG_SHOW_EXPAND_BUTTON;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID)
    {
        flag |= VCP_SEL_BOX_FLAG_FIX_GRID;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_R2L)
    {
        flag |= VCP_SEL_BOX_FLAG_R2L;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_SPACE)
    {
        flag |= VCP_SEL_BOX_FLAG_SPACE;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_CENTER_INDEX)
    {
        flag |= VCP_SEL_BOX_FLAG_CENTER_INDEX;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_LAST_PAGE)
    {
        flag |= VCP_SEL_BOX_FLAG_LAST_PAGE;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_SHOW_STAR)
    {
        flag |= VCP_SEL_BOX_FLAG_SHOW_STAR;
    }

    if (updatePtr->flags & MMI_IMUI_SELECTION_AREA_FLAG_DISABLE_LABEL)
    {
        flag |= VCP_SEL_BOX_FLAG_DISABLE_LABEL;
    }

#if defined(__MMI_IME_USER_DATABASE__)
    selBox->setNewWordString(newWordPrompt);
#endif

    return selBox->update((const VfxWChar *)updatePtr->str_ptr, 
                          updatePtr->count,
                          updatePtr->highlight_index,
                          flag);
}


void VadpInputServerUI::updateSelBoxTheme(VcpSelBox *selBox)
{
    VcpSelBoxThemeStruct selBoxTheme;

//expand button 
//since images have not come using arrow's images for now 
#if defined __MMI_IME_CANDIDATE_GRID__ &&  defined(__COSMOS_MMI__)  
    selBoxTheme.expandImg.setResId(VADP_IMG_IME_CG_EXPAND);
    selBoxTheme.gridCandBg.setResId(VADP_IMG_IME_CG_CAND_BG);
    selBoxTheme.gridCandBgHl.setResId(VADP_IMG_IME_CG_CAND_BG_HL);

#endif

    // star
    selBoxTheme.starFont = mapFontDesc(current_ime_theme->label_font);
    selBoxTheme.starColor = VfxColor(mapColorValue(current_ime_theme->indicator_color));
    
    // label
    selBoxTheme.labelFont = mapFontDesc(current_ime_theme->label_font);
    selBoxTheme.labelColor = VfxColor(mapColorValue(current_ime_theme->label_color));
    
    // candidate
    selBoxTheme.candFont = mapFontDesc(current_ime_theme->text_font);
    selBoxTheme.candNormalColor = VfxColor(mapColorValue(current_ime_theme->cand_text_color));
    selBoxTheme.candHiliteColor = VfxColor(mapColorValue(current_ime_theme->cand_highlighted_text_color));
    selBoxTheme.candRadicalNormalColor = VfxColor(mapColorValue(current_ime_theme->stroke_color));
    selBoxTheme.candRadicalHiliteColor = VfxColor(mapColorValue(current_ime_theme->highlighted_stroke_color));
    selBoxTheme.candGap = current_ime_theme->text_space;
    
#if defined(__COSMOS_MMI__) 
    selBoxTheme.candHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_SMALL);
    selBoxTheme.candDullHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_SMALL);
    selBoxTheme.candRadicalHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_SMALL);
    selBoxTheme.candRadicalDullHiliteBgImgSmall.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_SMALL);
    selBoxTheme.candHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_MEDIUM);
    selBoxTheme.candDullHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_MEDIUM);
    selBoxTheme.candRadicalHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_MEDIUM);
    selBoxTheme.candRadicalDullHiliteBgImgMedium.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_MEDIUM);
    selBoxTheme.candHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_LARGE);
    selBoxTheme.candDullHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_LARGE);
    selBoxTheme.candRadicalHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_HIGHLIGHT_LARGE);
    selBoxTheme.candRadicalDullHiliteBgImgLarge.setResId(VADP_IMG_IME_CAND_DULL_HIGHLIGHT_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.candHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_highlight_small);
    selBoxTheme.candDullHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_small);
    selBoxTheme.candRadicalHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_highlight_small);
    selBoxTheme.candRadicalDullHiliteBgImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_small);
    selBoxTheme.candHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_highlight_medium);
    selBoxTheme.candDullHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_medium);
    selBoxTheme.candRadicalHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_highlight_medium);
    selBoxTheme.candRadicalDullHiliteBgImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_medium);
    selBoxTheme.candHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_highlight_large);
    selBoxTheme.candDullHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_large);
    selBoxTheme.candRadicalHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_highlight_large);
    selBoxTheme.candRadicalDullHiliteBgImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_dull_highlight_large);
#else
    selBoxTheme.candHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->cand_highlight_color));
    selBoxTheme.candDullHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->cand_highlight_color));
    selBoxTheme.candRadicalHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->stroke_highlight_color));
    selBoxTheme.candRadicalDullHiliteBgColor = VfxColor(mapColorValue(current_ime_theme->stroke_highlight_color));
#endif

    // arrow
#if defined(__COSMOS_MMI__)  
    selBoxTheme.leftArrowNormalImgSmall.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_NORMAL_SMALL);
    selBoxTheme.leftArrowHiliteImgSmall.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DOWN_SMALL);
    selBoxTheme.leftArrowDisabledImgSmall.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DISABLE_SMALL);
    selBoxTheme.leftArrowNormalImgMedium.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_NORMAL_MEDIUM);
    selBoxTheme.leftArrowHiliteImgMedium.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DOWN_MEDIUM);
    selBoxTheme.leftArrowDisabledImgMedium.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DISABLE_MEDIUM);
    selBoxTheme.leftArrowNormalImgLarge.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_NORMAL_LARGE);
    selBoxTheme.leftArrowHiliteImgLarge.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DOWN_LARGE);
    selBoxTheme.leftArrowDisabledImgLarge.setResId(VADP_IMG_IME_CAND_LEFT_ARROW_DISABLE_LARGE);
    selBoxTheme.rightArrowNormalImgSmall.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_NORMAL_SMALL);
    selBoxTheme.rightArrowHiliteImgSmall.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DOWN_SMALL);
    selBoxTheme.rightArrowDisabledImgSmall.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DISABLE_SMALL);
    selBoxTheme.rightArrowNormalImgMedium.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_NORMAL_MEDIUM);
    selBoxTheme.rightArrowHiliteImgMedium.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DOWN_MEDIUM);
    selBoxTheme.rightArrowDisabledImgMedium.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DISABLE_MEDIUM);
    selBoxTheme.rightArrowNormalImgLarge.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_NORMAL_LARGE);
    selBoxTheme.rightArrowHiliteImgLarge.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DOWN_LARGE);
    selBoxTheme.rightArrowDisabledImgLarge.setResId(VADP_IMG_IME_CAND_RIGHT_ARROW_DISABLE_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.leftArrowNormalImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_up_small);
    selBoxTheme.leftArrowHiliteImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_down_small);
    selBoxTheme.leftArrowDisabledImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_disable_small);
    selBoxTheme.leftArrowNormalImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_up_medium);
    selBoxTheme.leftArrowHiliteImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_down_medium);
    selBoxTheme.leftArrowDisabledImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_disable_medium);
    selBoxTheme.leftArrowNormalImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_up_large);
    selBoxTheme.leftArrowHiliteImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_down_large);
    selBoxTheme.leftArrowDisabledImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_left_arrow_disable_large);
    selBoxTheme.rightArrowNormalImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_up_small);
    selBoxTheme.rightArrowHiliteImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_down_small);
    selBoxTheme.rightArrowDisabledImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_disable_small);
    selBoxTheme.rightArrowNormalImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_up_medium);
    selBoxTheme.rightArrowHiliteImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_down_medium);
    selBoxTheme.rightArrowDisabledImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_disable_medium);
    selBoxTheme.rightArrowNormalImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_up_large);
    selBoxTheme.rightArrowHiliteImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_down_large);
    selBoxTheme.rightArrowDisabledImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_right_arrow_disable_large);
#else
    selBoxTheme.arrowNormalColor = VfxColor(mapColorValue(current_ime_theme->arrow_up_color));
    selBoxTheme.arrowHiliteColor = VfxColor(mapColorValue(current_ime_theme->arrow_down_color));
    selBoxTheme.arrowDisabledColor = VfxColor(mapColorValue(current_ime_theme->arrow_disable_color));
#endif

    // seperator
#if defined(__COSMOS_MMI__) 
    selBoxTheme.seperatorNormalImgSmall.setResId(VADP_IMG_IME_CAND_SEP_SMALL);
    selBoxTheme.seperatorFocusedImgSmall.setResId(VADP_IMG_IME_CAND_SEP_SMALL);
    selBoxTheme.seperatorNormalImgMedium.setResId(VADP_IMG_IME_CAND_SEP_MEDIUM);
    selBoxTheme.seperatorFocusedImgMedium.setResId(VADP_IMG_IME_CAND_SEP_MEDIUM);
    selBoxTheme.seperatorNormalImgLarge.setResId(VADP_IMG_IME_CAND_SEP_LARGE);
    selBoxTheme.seperatorFocusedImgLarge.setResId(VADP_IMG_IME_CAND_SEP_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.seperatorNormalImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_separator_small);
    selBoxTheme.seperatorFocusedImgSmall.setMem((const VfxU8 *)current_ime_theme->cand_separator_small);
    selBoxTheme.seperatorNormalImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_separator_medium);
    selBoxTheme.seperatorFocusedImgMedium.setMem((const VfxU8 *)current_ime_theme->cand_separator_medium);
    selBoxTheme.seperatorNormalImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_separator_large);
    selBoxTheme.seperatorFocusedImgLarge.setMem((const VfxU8 *)current_ime_theme->cand_separator_large);
#else
    selBoxTheme.seperatorNormalColor = VfxColor(mapColorValue(current_ime_theme->separator_normal_color));
    selBoxTheme.seperatorFocusedColor = VfxColor(mapColorValue(current_ime_theme->separator_focused_color));
    selBoxTheme.seperatorWidth = (VfxS32)current_ime_theme->separator_width;
#endif

    // the background of selection box
#if defined(__COSMOS_MMI__)
    selBoxTheme.bgImageSmall.setResId(VADP_IMG_IME_CAND_BG_SMALL);
    selBoxTheme.focusedBgImageSmall.setResId(VADP_IMG_IME_CAND_FOCUS_FRAME_SMALL);
    selBoxTheme.bgImageMedium.setResId(VADP_IMG_IME_CAND_BG_MEDIUM);
    selBoxTheme.focusedBgImageMedium.setResId(VADP_IMG_IME_CAND_FOCUS_FRAME_MEDIUM);
    selBoxTheme.bgImageLarge.setResId(VADP_IMG_IME_CAND_BG_LARGE);
    selBoxTheme.focusedBgImageLarge.setResId(VADP_IMG_IME_CAND_FOCUS_FRAME_LARGE);
#elif defined(__MMI_IME_FTE_ENHANCE__)
    selBoxTheme.bgImageSmall.setMem((const VfxU8 *)current_ime_theme->cand_background_small);
    selBoxTheme.focusedBgImageSmall.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_small);
    selBoxTheme.bgImageMedium.setMem((const VfxU8 *)current_ime_theme->cand_background_medium);
    selBoxTheme.focusedBgImageMedium.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_medium);
    selBoxTheme.bgImageLarge.setMem((const VfxU8 *)current_ime_theme->cand_background_large);
    selBoxTheme.focusedBgImageLarge.setMem((const VfxU8 *)current_ime_theme->cand_focus_frame_large);
#else
    selBoxTheme.borderColor = VfxColor(mapColorValue(current_ime_theme->border_color));
    selBoxTheme.focusedBorderColor = VfxColor(mapColorValue(current_ime_theme->focused_border_color));

    if (current_ime_theme->background_filler->b)
    {
        selBoxTheme.bgImage.setMem((const VfxU8 *)current_ime_theme->background_filler->b);
        selBoxTheme.bgColor = VfxColor();
    }
    else
    {
        selBoxTheme.bgImage = VfxImageSrc();
        selBoxTheme.bgColor = VfxColor(mapColorValue(current_ime_theme->background_filler->c));
    }

    if (current_ime_theme->focused_background_filler->b)
    {
        selBoxTheme.focusedBgImage.setMem((const VfxU8 *)current_ime_theme->focused_background_filler->b);
        selBoxTheme.focusedBgColor = VfxColor();
    }
    else
    {
        selBoxTheme.focusedBgImage = VfxImageSrc();
        selBoxTheme.focusedBgColor = VfxColor(mapColorValue(current_ime_theme->focused_background_filler->c));
    }
#endif

    selBox->setTheme(selBoxTheme);
}


VcpSelBox * VadpInputServerUI::createSelBox(VfxU32 style)
{
    VfxU32 selBoxStyle = 0;
    VcpSelBox *selBox = NULL;
    
    if (style & MMI_IMUI_SELECTION_AREA_STYLE_ARROW)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_ARROW;
    }
#if defined __MMI_IME_CANDIDATE_GRID__
    if(style &  MMI_IMUI_SELECTION_AREA_STYLE_EXPAND_BUTTON )
    {
        selBoxStyle |=  VCP_SEL_BOX_STYLE_EXPAND_BUTTON ;
    }
#endif

    if (style & MMI_IMUI_SELECTION_AREA_STYLE_LABEL)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_LABEL;
    }

    if (style & MMI_IMUI_SELECTION_AREA_STYLE_STAR)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_STAR;
    }

    if (style & MMI_IMUI_SELECTION_AREA_STYLE_BORDER)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_BORDER;
    }

    if (style & MMI_IMUI_SELECTION_AREA_STYLE_SEPARATOR)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_SEPERATOR;
    }

    if (style & MMI_IMUI_SELECTION_AREA_STYLE_SPACE_AFTER_APOSTROPHE)
    {
        selBoxStyle |= VCP_SEL_BOX_STYLE_SPACE_AFTER_APOSTROPHE;
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();

    VFX_OBJ_CREATE_EX(selBox, VcpSelBox,  inputBinding->getOwner(), (selBoxStyle));

    VFX_ASSERT(selBox);

    selBox->setHidden(VFX_TRUE);

#if defined(__MMI_TOUCH_SCREEN__)
    selBox->m_signalCandDown.connect(this, &VadpInputServerUI::onSelBoxCandDown);
    selBox->m_signalCandUp.connect(this, &VadpInputServerUI::onSelBoxCandUp);
    selBox->m_signalCandMove.connect(this, &VadpInputServerUI::onSelBoxCandMove);
    selBox->m_signalPreArrowClicked.connect(this, &VadpInputServerUI::onSelBoxPreArrowClicked);
    selBox->m_signalNextArrowClicked.connect(this, &VadpInputServerUI::onSelBoxNextArrowClicked);
#endif
    

    updateSelBoxTheme(selBox);
    
    topLevel->addChildFrame(selBox);

    selBox->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);

    return selBox;
}


#if defined(__MMI_TOUCH_SCREEN__)
void VadpInputServerUI::onSelBoxCandDown(VfxObject *selBox, VfxS32 index)
{
    mmi_imui_message_struct mes_str;

    if (selBox == m_candBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_BOX;
    }
    else if (selBox == m_compBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_DOWN_IN_COMPOSITION_BOX;
    }

#if defined __MMI_IME_SCROLLING_COMPOSITION__
    else if  ( selBox == m_sCompBox )
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_DOWN_IN_COMPOSITION_BOX;
    }

#endif
    else
    {
        VFX_ASSERT(0);
    }
    
    mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_TEXT;
    mes_str.param_1 = 0;

    mmi_imc_pen_event_command_handler(&mes_str);
}


void VadpInputServerUI::onSelBoxCandUp(VfxObject *selBox, VfxS32 index)
{
    mmi_imui_message_struct mes_str;

    if (selBox == m_candBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_BOX;
    }
    else if (selBox == m_compBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX;
    }
#if defined __MMI_IME_SCROLLING_COMPOSITION__
    else if  ( selBox == m_sCompBox )
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX;
    }

#endif
    else
    {
        VFX_ASSERT(0);
    }
#if defined __MMI_IME_CANDIDATE_GRID__
    if(index == 0xFF) 
    {
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_EXPAND;
        mes_str.param_1 = 0;
        //hack <001> to override animation process of vk , as vk is hidden by service when we came here
        //so it will animate it , visually not very appealing , in this case , so have to stop animation
        halt_vk_animation();
    }
    else
#endif
    {
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_TEXT;
        mes_str.param_1 = 0;
    }

    mmi_imc_pen_event_command_handler(&mes_str);
}


void VadpInputServerUI::onSelBoxCandMove(VfxObject *selBox, VfxS32 index)
{
    mmi_imui_message_struct mes_str;

    if (selBox == m_candBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_MOVE_IN_CANDIDATE_BOX;
    }
    else if (selBox == m_compBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_MOVE_IN_COMPOSITION_BOX;
    }
    else
    {
        VFX_ASSERT(0);
    }
    
    mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_TEXT;
    mes_str.param_1 = 0;

    mmi_imc_pen_event_command_handler(&mes_str);
}


void VadpInputServerUI::onSelBoxPreArrowClicked(VfxObject *selBox)
{
    mmi_imui_message_struct mes_str;

    if (selBox == m_candBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_BOX;
    }
    else if (selBox == m_compBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX;
    }
    else
    {
        VFX_ASSERT(0);
    }
    
    mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_LEFT_ARROW;
    mes_str.param_1 = 0;

    mmi_imc_pen_event_command_handler(&mes_str);
}


void VadpInputServerUI::onSelBoxNextArrowClicked(VfxObject *selBox)
{
    mmi_imui_message_struct mes_str;

    if (selBox == m_candBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_BOX;
    }
    else if (selBox == m_compBox)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX;
    }
    else
    {
        VFX_ASSERT(0);
    }
    
    mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_RIGHT_ARROW;
    mes_str.param_1 = 0;

    mmi_imc_pen_event_command_handler(&mes_str);
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


#if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__)
VcpResizableCompositionBox * VadpInputServerUI::createResizableCompositionBox()
{
    VcpResizableCompositionBox *rCompBox = NULL;

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VadpInputServer *inputServer = VFX_OBJ_GET_INSTANCE(VadpInputServer); 
    VsrvInputBinding* inputBinding = inputServer->getBinding();
    VFX_OBJ_CREATE_EX(rCompBox, VcpResizableCompositionBox,  inputBinding->getOwner(), (RESIZEABLE_COMP_AREA_COVERED_BOTTOM_HEIGHT, UI_device_width * 2 / 3));

    VFX_ASSERT(rCompBox);
    
    rCompBox->setHidden(VFX_TRUE);
    
    rCompBox->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);
    
    topLevel->addChildFrame(rCompBox);

    VcpResizableCompositionBoxThemeStruct themeStruct;

    themeStruct.textFont = mapFontDesc(current_ime_theme->text_font);       
    themeStruct.textColor = VfxColor(mapColorValue(current_ime_theme->cand_text_color));   
#if defined(__COSMOS_MMI__) 
    themeStruct.bgImageSmall.setResId(VADP_IMG_IME_INPUT_BG_SMALL);
    themeStruct.bgImageMedium.setResId(VADP_IMG_IME_INPUT_BG_MEDIUM);
    themeStruct.bgImageLarge.setResId(VADP_IMG_IME_INPUT_BG_LARGE);
#else
    themeStruct.bgImageSmall.setMem((const VfxU8 *)current_ime_theme->input_background_small);   
    themeStruct.bgImageMedium.setMem((const VfxU8 *)current_ime_theme->input_background_medium);   
    themeStruct.bgImageLarge.setMem((const VfxU8 *)current_ime_theme->input_background_large); 
#endif
    rCompBox->setTheme(themeStruct);

#if defined(__MMI_TOUCH_SCREEN__)
    rCompBox->m_signalClicked.connect(this, &VadpInputServerUI::onResizeableCompBoxClicked);
#endif
    
    return rCompBox;
}

#if defined(__MMI_TOUCH_SCREEN__)
void VadpInputServerUI::onResizeableCompBoxClicked(VfxObject* rCompBox)
{
    mmi_imui_message_struct mes_str;

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    if (rCompBox == m_inputArea)
    {
        mes_str.message_id = MMI_IMUI_MESSAGE_PEN_UP_IN_INPUT_BOX;
        mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_TEXT;
        mes_str.param_1 = 0;
        mmi_imc_pen_event_command_handler(&mes_str);
    }
    else
    {
#endif
    mes_str.message_id = MMI_IMUI_MESSAGE_PEN_DOWN_IN_COMPOSITION_BOX;
    mes_str.param_0 = MMI_IMUI_SELECTION_AREA_PEN_TEXT;
    mes_str.param_1 = 0;
    mmi_imc_pen_event_command_handler(&mes_str);
#ifdef __MMI_CSTAR_PHRASE_INPUT__
    }
#endif    
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */

#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_IME_FTE_ENHANCE__) */


VfxFontDesc VadpInputServerUI::mapFontDesc(UI_font_type fontStyle)
{
    return VfxFontDesc((VfxU8)fontStyle->size);
/*
    if (fontStyle->size == SMALL_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL);
    }
    else if (fontStyle->size == MEDIUM_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM);
    }
    else if (fontStyle->size == LARGE_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE);
    }
    else
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM);
    }*/
}

VfxU32 VadpInputServerUI::mapColorValue(color colorStruct)
{
    return (VfxU32)VRT_COLOR_MAKE(255, colorStruct.r, colorStruct.g, colorStruct.b);
}


/***************************************************************************** 
 * Class VadpInputServerSingleBlockHWPanel
 *****************************************************************************/


#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined (__MMI_TOUCH_SCREEN__)

#if 0 /* Handwriting stroke layer buffer changes to use ASM anonymous */
#ifdef __MTK_TARGET__
/* under construction !*/
#endif 
#ifndef __MTK_TARGET__
/* under construction !*/
#endif
/* under construction !*/
#if (SINGLE_BLOCK_WIDTH * SINGLE_BLOCK_HEIGHT)  > (SINGLE_BLOCK_WIDTH_ROTATED * SINGLE_BLOCK_HEIGHT_ROTATED)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MTK_TARGET__
/* under construction !*/
#endif 
#endif

VadpInputServerSingleBlockHWPanel::VadpInputServerSingleBlockHWPanel() : 
    m_extraBlock(NULL),
    m_strokeLayerControl(NULL),
	m_strokeLayer(0),
    m_strokeColor(VFX_COLOR_RED),
    m_strokeLayerBuffer(NULL)
{
}

void VadpInputServerSingleBlockHWPanel::setExtraBlockImg(VfxId imgId)
{
    if (m_extraBlock)
    {
        m_extraBlock->setImgContent(VfxImageSrc(imgId));
    }
}


void VadpInputServerSingleBlockHWPanel::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_extraBlock, VfxImageFrame, this);

    VFX_OBJ_CREATE(m_strokeLayerControl, VfxLayerControl, this);
#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->addChildFrame(m_extraBlock);
    topLevel->addChildFrame(m_strokeLayerControl);
#endif

    updateSize();

    m_strokeLayerControl->setIsOnTop(VFX_TRUE);
    m_strokeLayerControl->setHidden(VFX_TRUE);
    m_strokeLayerControl->setIsUnhittable(VFX_TRUE);
}


void VadpInputServerSingleBlockHWPanel::rotate()
{
    updateSize();
}


void VadpInputServerSingleBlockHWPanel::updateSize()
{
    m_strokeLayerControl->setLayerHandle(0);
        
    if (m_strokeLayer != 0)
	{
		gdi_layer_free(m_strokeLayer);
        m_strokeLayer = 0;
	}

    if (m_strokeLayerBuffer != NULL)
    {
        mmi_frm_asm_free_anonymous(m_strokeLayerBuffer);
        m_strokeLayerBuffer = NULL;
	}

    VfxS32 layerBufferSize = 0;
    if (mmi_imc_is_rotated())
    {
        layerBufferSize = SINGLE_BLOCK_WIDTH_ROTATED * SINGLE_BLOCK_HEIGHT_ROTATED * 2;
    }
    else
    {
        layerBufferSize = SINGLE_BLOCK_WIDTH * SINGLE_BLOCK_HEIGHT * 2;
    }

    m_strokeLayerBuffer = mmi_frm_asm_alloc_anonymous_nc(layerBufferSize);

    /* If asserts here, please contact IME owner for help */
    VFX_DEV_ASSERT(m_strokeLayerBuffer); 

    if (m_strokeLayerBuffer)
    {
        if (mmi_imc_is_rotated())
        {
            m_extraBlock->setPos(SINGLE_BLOCK_EXTRA_BLOCK_ICON_X_ROTATED, SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y_ROTATED);
            
            m_strokeLayerControl->setRect(SINGLE_BLOCK_X_ROTATED, SINGLE_BLOCK_Y_ROTATED, SINGLE_BLOCK_WIDTH_ROTATED, SINGLE_BLOCK_HEIGHT_ROTATED);
            
            gdi_layer_create_cf_using_outside_memory((gdi_color_format)2, SINGLE_BLOCK_X_ROTATED, SINGLE_BLOCK_Y_ROTATED, SINGLE_BLOCK_WIDTH_ROTATED, SINGLE_BLOCK_HEIGHT_ROTATED, &m_strokeLayer, (U8*)m_strokeLayerBuffer, layerBufferSize);
        }
        else
        {
            
            m_extraBlock->setPos(SINGLE_BLOCK_EXTRA_BLOCK_ICON_X, SINGLE_BLOCK_EXTRA_BLOCK_ICON_Y);
        
            m_strokeLayerControl->setRect(SINGLE_BLOCK_X,SINGLE_BLOCK_Y , SINGLE_BLOCK_WIDTH, SINGLE_BLOCK_HEIGHT);

            gdi_layer_create_cf_using_outside_memory((gdi_color_format)2, SINGLE_BLOCK_X, SINGLE_BLOCK_Y, SINGLE_BLOCK_WIDTH, SINGLE_BLOCK_HEIGHT, &m_strokeLayer, (U8*)m_strokeLayerBuffer, layerBufferSize);
        }
        
        gdi_layer_push_and_set_active(m_strokeLayer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

        vrt_size_struct screenSize;
        vrt_color_type_enum noUse;
        vrt_sys_get_main_screen_info(&screenSize, &noUse);

#ifndef __MMI_IME_V3__
        if (mmi_imc_is_rotated())
        {
            gdi_layer_set_position((S32)0, screenSize.height - SINGLE_BLOCK_HEIGHT_ROTATED);
        }
        else
        {
            gdi_layer_set_position((S32)0, screenSize.height - SINGLE_BLOCK_HEIGHT);
        }
#else
        if (mmi_imc_is_rotated())
        {
            gdi_layer_set_position(SINGLE_BLOCK_X_ROTATED, SINGLE_BLOCK_Y_ROTATED);
        }
        else
        {
            gdi_layer_set_position(SINGLE_BLOCK_X, SINGLE_BLOCK_Y);
        }
#endif
        gdi_layer_pop_and_restore_active();                

        m_strokeLayerControl->setLayerHandle(m_strokeLayer);
    }
}


void VadpInputServerSingleBlockHWPanel::onDeinit()
{
    VfxControl::onDeinit();

    m_strokeLayerControl->setLayerHandle(0);

    gdi_layer_enter_draw_section();
    gdi_layer_exit_draw_section();

    if (m_strokeLayer != 0)
    {
        gdi_layer_free(m_strokeLayer);        
        m_strokeLayer = 0;
    }

    if (m_strokeLayerBuffer != NULL)
    {
        mmi_frm_asm_free_anonymous(m_strokeLayerBuffer);
        m_strokeLayerBuffer = NULL;
    }
}


void VadpInputServerSingleBlockHWPanel::drawStroke(VfxPoint prevPoint, VfxPoint point)
{
    if (!m_strokeLayer)
    {
        return;
    }
    
    m_strokeLayerControl->setHidden(VFX_FALSE);
    
    color gdiStrokeColor;

    gdiStrokeColor.alpha =  m_strokeColor.getA();
    gdiStrokeColor.r =  m_strokeColor.getR();
    gdiStrokeColor.g =  m_strokeColor.getG();
    gdiStrokeColor.b =  m_strokeColor.getB();

    gdi_layer_push_and_set_active(m_strokeLayer);
#ifndef __MMI_IME_V3__
    gui_line(prevPoint.x, prevPoint.y, point.x, point.y, gdiStrokeColor);
    gui_line(prevPoint.x + 1, prevPoint.y, point.x + 1, point.y, gdiStrokeColor);
    gui_line(prevPoint.x, prevPoint.y + 1, point.x, point.y + 1, gdiStrokeColor);
    gui_line(prevPoint.x - 1, prevPoint.y, point.x - 1, point.y, gdiStrokeColor);
    gui_line(prevPoint.x, prevPoint.y - 1, point.x, point.y - 1, gdiStrokeColor);
#if defined(__MMI_MAINLCD_480X800__)
    gui_line(prevPoint.x + 2, prevPoint.y, point.x + 2, point.y, gdiStrokeColor);
    gui_line(prevPoint.x, prevPoint.y + 2, point.x, point.y + 2, gdiStrokeColor);
    gui_line(prevPoint.x - 2, prevPoint.y, point.x - 2, point.y, gdiStrokeColor);
    gui_line(prevPoint.x, prevPoint.y - 2, point.x, point.y - 2, gdiStrokeColor);
#endif

	
#else
	U8 uWidth = mmi_imm_handwriting_get_stroke_width();	
	color cr = mmi_imm_handwriting_get_current_stroke_color();
	gui_wline(prevPoint.x, prevPoint.y, point.x, point.y,cr, uWidth);
#endif //__MMI_IME_V3__

    S32 min_x, min_y, max_x, max_y;

    S32 layerX, layerY;
    
    gdi_layer_get_position(&layerX, &layerY);

    VfxPoint preBltPoint(prevPoint.x + layerX, prevPoint.y + layerY);
    VfxPoint bltPoint(point.x + layerX, point.y + layerY);

    if (preBltPoint.x > bltPoint.x)
    {
        min_x = (S32)bltPoint.x;
        max_x = (S32)preBltPoint.x;
    }
    else
    {
        max_x = (S32)bltPoint.x;
        min_x = (S32)preBltPoint.x;            
    }

    if (preBltPoint.y > bltPoint.y)
    {
        min_y = (S32)bltPoint.y;
        max_y = (S32)preBltPoint.y;
    }
    else
    {
        max_y = (S32)bltPoint.y;
        min_y = (S32)preBltPoint.y;            
    }

    gdi_handle layers[4];

    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);

#if defined(__MMI_MAINLCD_480X800__)
    gdi_layer_blt_previous(min_x - 2, min_y - 2, max_x + 2, max_y + 2);
#else
    gdi_layer_blt_previous(min_x - 1, min_y - 1, max_x + 1, max_y + 1);
#endif

    gdi_layer_pop_and_restore_active();
}


void VadpInputServerSingleBlockHWPanel::clearStroke()
{
    if (!m_strokeLayer)
    {
        return;
    }
    
    gdi_layer_push_and_set_active(m_strokeLayer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();             

    m_strokeLayerControl->setHidden(VFX_TRUE);
}


void VadpInputServerSingleBlockHWPanel::setStrokColor(VfxColor strokeColor)
{
    m_strokeColor = strokeColor;
}


VfxBool VadpInputServerSingleBlockHWPanel::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(this);

    mmi_pen_point_struct plutoPos;

    plutoPos.x = pos.x;
    plutoPos.y = pos.y;

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
            //vrt_canvas_suspend();
            mmi_imc_pen_stroke_down_handler(plutoPos);
            return VFX_TRUE;


        case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
            mmi_imc_pen_stroke_move_handler(plutoPos);
            return VFX_TRUE;


        case VFX_PEN_EVENT_TYPE_STROKE_UP:
            mmi_imc_pen_stroke_up_handler(plutoPos);
            //vrt_canvas_resume();
            return VFX_TRUE;


        default:
            return VFX_TRUE;
    }


}

#endif /* #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) */
