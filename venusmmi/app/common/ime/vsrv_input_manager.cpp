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
 *  vsrv_input_manager.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __MRE_SDK__
extern "C"
{
    #include "ImeGprot.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
}
#endif

#include "vsrv_input_manager.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_input_event.h"
#include "vfx_sys_mem_config.h"

#ifndef __MRE_SDK__
#include "ime\vadp_v2p_input_server.h"
#endif

#if defined(__MRE_SDK__)
#include <string.h>
#include "vfx_mmi.h"
#endif /* defined(__MRE_SDK__) */

/***************************************************************************** 
 * Class
 *****************************************************************************/

VsrvInputBinding::VsrvInputBinding():
    m_inputType(0),
	m_inputSettingFlags(IME_SETTING_FLAG_NONE),	
	m_inputStyleFlags(IME_INPUT_STYLE_NONE),
	m_inputConnectionPtr(NULL),
	m_vkEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_ENTER),
	m_isVKEnterKeyEnabled(VFX_TRUE),
	m_appDesiredFirstInputMode(IMM_INPUT_MODE_NONE)
{
    m_allowedEvents[0] = IME_INPUT_EVENT_NONE;
	m_disabledEvents[0] = IME_INPUT_EVENT_NONE;
	m_userSpecialInputModeList[0] = IMM_INPUT_MODE_NONE;
}


VsrvInputBinding::VsrvInputBinding(VfxU64 inputType, VfxU32 settingFlags, VfxU32 styleFlags, InputConnection *conn):
	m_inputType(inputType),
	m_inputSettingFlags(settingFlags),	
	m_inputStyleFlags(styleFlags),
	m_inputConnectionPtr(conn)
{
    m_vkEnterKeyStyle = IME_VK_ENTER_KEY_STYLE_ENTER;
    m_isVKEnterKeyEnabled = VFX_TRUE;
    m_appDesiredFirstInputMode = IMM_INPUT_MODE_NONE;
    m_allowedEvents[0] = IME_INPUT_EVENT_NONE;
    m_disabledEvents[0] = IME_INPUT_EVENT_NONE;
    m_userSpecialInputModeList[0] = IMM_INPUT_MODE_NONE;
}

void VsrvInputBinding::initWith(const VsrvInputBinding &other)
{
    m_inputType = other.m_inputType;
    m_inputSettingFlags = other.m_inputSettingFlags;
    m_inputStyleFlags = other.m_inputStyleFlags;
    m_inputConnectionPtr = other.m_inputConnectionPtr;
    m_isVKEnterKeyEnabled = other.m_isVKEnterKeyEnabled;
    m_vkEnterKeyStyle = other.m_vkEnterKeyStyle;
    m_allowedChars = other.m_allowedChars;
    m_disabledChars = other.m_disabledChars;
    m_appDesiredFirstInputMode = other.m_appDesiredFirstInputMode;

    memcpy(&m_allowedEvents[0], &other.m_allowedEvents[0], sizeof(IMEInputEventEnum) * VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM);
    memcpy(&m_disabledEvents[0], &other.m_disabledEvents[0], sizeof(IMEInputEventEnum) * VSRV_INPUT_MANAGER_MAX_DISABLED_EVENT_NUM);
    memcpy(&m_userSpecialInputModeList[0], &other.m_userSpecialInputModeList[0], sizeof(mmi_imm_input_mode_enum) * VSRV_INPUT_MANAGER_MAX_USER_SPECIAL_MODE_NUM);
}

 

void VsrvInputBinding::setAllowedEvents(IMEInputEventEnum *events)
{
    VfxU32 i;

	for (i = 0; events[i] != IME_INPUT_EVENT_NONE; i++)
	{
	    VFX_ASSERT(i < VSRV_INPUT_MANAGER_MAX_ALLOWED_EVENT_NUM);
		
	    m_allowedEvents[i] = events[i];
        }

    m_allowedEvents[i] = IME_INPUT_EVENT_NONE;

    if (i > 0)
    {
        m_inputSettingFlags |= IME_ALLOWED_EVENT_LIST;
    }
}

void VsrvInputBinding::setDisabledEvents(IMEInputEventEnum *events)
{
    VfxU32 i;

	for (i = 0; events[i] != IME_INPUT_EVENT_NONE; i++)
	{
	    VFX_ASSERT(i < VSRV_INPUT_MANAGER_MAX_DISABLED_EVENT_NUM);
		
	    m_disabledEvents[i] = events[i];
        }

    m_disabledEvents[i] = IME_INPUT_EVENT_NONE;

    if (i > 0)
    {
        m_inputSettingFlags |= IME_DISABLED_EVENT_LIST;
    }
}

void VsrvInputBinding::setUserSpecialInputModeList(mmi_imm_input_mode_enum *list)
{
    VfxU32 i;

	for (i = 0; list[i] != IMM_INPUT_MODE_NONE; i++)
	{
	    VFX_ASSERT(i < VSRV_INPUT_MANAGER_MAX_USER_SPECIAL_MODE_NUM);
		
	    m_userSpecialInputModeList[i] = list[i];
    }

	m_userSpecialInputModeList[i] = IMM_INPUT_MODE_NONE;
}

/***************************************************************************** 
 * Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VsrvInputManager", VsrvInputManager, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VsrvInputManager);

#ifdef __MRE_SDK__

VsrvInputManager::VsrvInputManager():
    m_mreServiceInstance(NULL),
    m_currInputBinding(NULL)
{
    
}

vrt_allocator_handle VsrvInputManager::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}


 
VsrvInputManager::~VsrvInputManager()
{

}

// TODO: To be revised
extern "C" 
{
typedef int  VMINT;
extern  VMINT vm_create_service(VMINT clsid, VMINT iid, void ** pptr);
}

void VsrvInputManager::onInit()
{
    VfxObject::onInit();
    
    if (!m_mreServiceInstance)
    {
        vm_create_service(SID_IME, IID_IImeService, (void **)&m_mreServiceInstance);

        VFX_ASSERT(m_mreServiceInstance);
    }
}


void VsrvInputManager::onDeinit()
{
    if (m_mreServiceInstance)
    {
        m_mreServiceInstance->vt->release(m_mreServiceInstance);
        m_mreServiceInstance = NULL;
    }

    VfxObject::onDeinit();
}


VfxBool VsrvInputManager::bindInput(VsrvInputBinding *binding)
{
    m_currInputBinding = binding;

    VFX_ASSERT(m_currInputBinding->getConnection());

	if (m_currInputBinding && m_mreServiceInstance)
	{
	    m_mreServiceInstance->vt->resetInputBinding(m_mreServiceInstance);
        VfxU32 inputType32 = (VfxU32)m_currInputBinding->m_inputType;

	    m_mreServiceInstance->vt->setInputType(m_mreServiceInstance, inputType32);
        m_mreServiceInstance->vt->setSettingFlags(m_mreServiceInstance, m_currInputBinding->m_inputSettingFlags);
        m_mreServiceInstance->vt->setStyleFlags(m_mreServiceInstance, m_currInputBinding->m_inputStyleFlags);
        m_mreServiceInstance->vt->setInputConnectionMsgProc(m_mreServiceInstance, inputConnectionMsgProc);
        m_mreServiceInstance->vt->setAllowedChars(m_mreServiceInstance, m_currInputBinding->getAllowedChars().getBuf());
        m_mreServiceInstance->vt->setDisabledChars(m_mreServiceInstance, m_currInputBinding->getDisabledChars().getBuf());
        m_mreServiceInstance->vt->setAllowedEvents(m_mreServiceInstance, m_currInputBinding->getAllowedEvents());
        m_mreServiceInstance->vt->setDisabledEvents(m_mreServiceInstance, m_currInputBinding->getDisabledEvents());
        m_mreServiceInstance->vt->setUserSpecialInputModeList(m_mreServiceInstance, m_currInputBinding->getUserSpecialInputModeList());

        return m_mreServiceInstance->vt->bindInput(m_mreServiceInstance);
	}
	else
	{
	    return VFX_FALSE;
	}
}

VsrvInputBinding* VsrvInputManager::getBinding()
{
    return m_currInputBinding;
}

VfxBool VsrvInputManager::unbindInput(VsrvInputBinding *binding)
{
	if (m_mreServiceInstance)
	{
	    if (m_currInputBinding == binding && 
            m_mreServiceInstance->vt->unbindInput(m_mreServiceInstance))
	    {
	        m_mreServiceInstance->vt->resetInputBinding(m_mreServiceInstance);
            m_currInputBinding = NULL;
            return VFX_TRUE;
	    }
        else
        {
            return VFX_FALSE;
        }
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::activateInput()
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->activateInput(m_mreServiceInstance);
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::deactivateInput()
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->deactivateInput(m_mreServiceInstance);
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::dispatchKeyEvent(VfxKeyEvent &event)
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->dispatchKeyEvent(m_mreServiceInstance, event.type, event.keyCode, event.ucs2, event.specialKeyFlag, event.timeStamp);
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::dispatchPenEvent(VfxPenEvent &event)
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->dispatchPenEvent(m_mreServiceInstance, 
                    event.type, 
                    event.timeStamp, 
                    event.prevTimeStamp, 
                    event.downTimeStamp,
                    event.pos.x,
                    event.pos.y,
                    event.prevPos.x,
                    event.prevPos.y,
                    event.downPos.x,
                    event.downPos.y);
	}
	else
	{
	    return VFX_FALSE;
	}
}


void VsrvInputManager::override_autocap() 
   {
  
   }


void VsrvInputManager::disableSymbolPicker()
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->disableSymbolPicker(m_mreServiceInstance);
	}
}

void VsrvInputManager::enableSymbolPicker()
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->enableSymbolPicker(m_mreServiceInstance);
	}
}

VfxBool VsrvInputManager::getCharInfor(VfxWChar code, VfxWChar *inforBuf, VfxU32 bufSize, mmi_imm_input_mode_enum mode) const
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->getCharInfor(m_mreServiceInstance, code, inforBuf, bufSize, mode);
	}
	else
	{
	    return VFX_FALSE;
	}
}

VfxBool VsrvInputManager::isIMEState() const
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->isIMEState(m_mreServiceInstance);
	}
	else
	{
	    return VFX_FALSE;
	}
}

void VsrvInputManager::addNewWordsFromText(VfxWChar *text)
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->addNewWordsFromText(m_mreServiceInstance, text);
	}
}

mmi_imm_input_mode_enum VsrvInputManager::getCurrInputMode() const
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->getCurrInputMode(m_mreServiceInstance);
	}
	else
	{
	    return IMM_INPUT_MODE_NONE;
	}
}

mmi_imm_input_type_enum VsrvInputManager::getCurrInputType() const
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->getCurrInputType(m_mreServiceInstance);
	}
	else
	{
	    return IMM_INPUT_TYPE_NONE;
	}
}

mmi_imm_input_mode_enum* VsrvInputManager::getCurrrUserSpecificInputModeList() 
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->getCurrrUserSpecificInputModeList(m_mreServiceInstance);
	}
	else
	{
	    return NULL;
	}
}


VfxU32 VsrvInputManager::getInputMethodHistorySize() const
{
	if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->getInputMethodHistorySize(m_mreServiceInstance);
	}
	else
	{
	    return 0;
	}
}


void VsrvInputManager::getInputMethodHistory(void *historyAddress)
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->getInputMethodHistory(m_mreServiceInstance, historyAddress);
	}
}


void VsrvInputManager::setInputMethodHistory(void *historyAddress)
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->setInputMethodHistory(m_mreServiceInstance, historyAddress);
	}
}


void VsrvInputManager::enableAutoCapInHistory(void *historyAddress)
{
    if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->enableAutoCapInHistory(m_mreServiceInstance, historyAddress);
	}
}


void VsrvInputManager::showSoftInput()
{
    if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->showSoftInput(m_mreServiceInstance);
	}
}


void VsrvInputManager::hideSoftInput()
{
    if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->hideSoftInput(m_mreServiceInstance);
	}
}


VfxBool VsrvInputManager::isSoftInputVisible()
{
    if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->isSoftInputVisible(m_mreServiceInstance);
	}

    return VFX_FALSE;
}


VfxS32 VsrvInputManager::isValidInputString(VfxWChar *string, VfxS32 len)
{
    if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->isValidInputString(m_mreServiceInstance, string, len);
	}
    else
    {
        return 0;
    }
}


VfxBool VsrvInputManager::isValidInputStringForPaste(VfxWChar *string, VfxS32 len)
{
    if (m_mreServiceInstance)
	{
		return m_mreServiceInstance->vt->isValidInputStringForPaste(m_mreServiceInstance, string, len);
	}
    else
    {
        return 0;
    }
}


void VsrvInputManager::cursorPosChanged(VfxRect &cursorRect)
{
    if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->cursorPosChanged(m_mreServiceInstance, &cursorRect.origin.x,
                    &cursorRect.origin.y,
                    &cursorRect.size.width,
                    &cursorRect.size.height);
	}
}


VfxBool VsrvInputManager::isInputMethodUIControl(VfxControl *control)
{
    return VFX_FALSE; // Input method UI control is always in native Venus world
}


void VsrvInputManager::setInputModeSwitchable(VfxBool isSwitchable)
{
	if (m_mreServiceInstance)
	{
		m_mreServiceInstance->vt->setInputModeSwitchable(m_mreServiceInstance, isSwitchable);
	}
}


VfxU32 VsrvInputManager::inputConnectionMsgProc(ImeServiceInputConnectionProxyMsgIDEnum msgID, VfxU32 *args, VfxU32 argSize)
{
    VsrvInputManager *inputManager = VFX_OBJ_GET_INSTANCE(VsrvInputManager);
    
    if (!inputManager->m_currInputBinding)
        return 0;
        
    InputConnection *connection = inputManager->m_currInputBinding->getConnection();

    VFX_ASSERT(connection);

    VfxU32 ret = 0;
        
    switch (msgID)
    {
    case IME_SRV_INPUT_CON_MSG_BEGIN_BATCH_EDIT:

        VFX_ASSERT(argSize == 0);
        
        ret = (connection->beginBatchEdit() == VFX_TRUE) ? 1 : 0;
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_END_BATCH_EDIT:

        VFX_ASSERT(argSize == 0);

        ret = (connection->endBatchEdit() == VFX_TRUE) ? 1 : 0;
        
        break;

    case IME_SRV_INPUT_CON_MSG_INSERT_STRING:

        VFX_ASSERT(argSize == 3);

        ret = (VfxU32)connection->insertText((VfxWChar *)args[0], (VfxS32)args[1], (VfxS32)args[2]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_INSERT_CHAR:

        VFX_ASSERT(argSize == 3);

        ret = (VfxU32)connection->insertText((VfxWChar)args[0], (VfxS32)args[1], (VfxS32)args[2]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_SET_MARKED_TEXT:

        VFX_ASSERT(argSize == 4);

        ret = connection->setMarkedText((VfxWChar *)args[0], (VfxS32)args[1], (VfxS32)args[2], (VfxS32)args[3]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_FINISH_MARKED_TEXT:

        VFX_ASSERT(argSize == 0);

        connection->finishMarkedText();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_SEND_KEY_EVENT:

        VFX_ASSERT(argSize == 5);

        connection->sendKeyEvent((VfxKeyEventTypeEnum)args[0], (VfxKeyCodeEnum)args[1], (VfxWChar)args[2], (VfxU32)args[3], (VfxMsec)args[4]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_CLEAR:

        VFX_ASSERT(argSize == 0);

        connection->clear();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_DELETE_CHARS:

        VFX_ASSERT(argSize == 2);

        ret = connection->deleteChars((VfxS32)args[0], (VfxS32)args[1]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_DELETE:

        VFX_ASSERT(argSize == 0);

        ret = connection->deleteChars();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_DELETE_AT_CURSOR:

        VFX_ASSERT(argSize == 2);

        ret = connection->deleteAtCursor((VfxS32)args[0], (VfxS32)args[1]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_LENGTH:

        VFX_ASSERT(argSize == 0);

        ret = (VfxU32)connection->length();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_MAX_LENGTH:
        VFX_ASSERT(argSize == 0);

        ret = (VfxU32)connection->maxLength();
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_CHAR_BEFORE_CURSOR:

        VFX_ASSERT(argSize == 3);

        ret = (VfxU32)connection->getCharBeforeCursor((VfxS32)args[0], (VfxS32)args[1], (VfxS32 *)args[2]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_CHAR_AFTER_CURSOR:

        VFX_ASSERT(argSize == 3);

        ret = (VfxU32)connection->getCharAfterCursor((VfxS32)args[0], (VfxS32)args[1], (VfxS32 *)args[2]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_SET_SELECTION:

        VFX_ASSERT(argSize == 2);

        ret = (VfxS32)connection->setSelection((VfxS32)args[0], (VfxS32)args[1]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_SELECTION:

        VFX_ASSERT(argSize == 2);

        connection->getSelection((VfxS32 *)args[0], (VfxS32 *)args[1]);
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_TEXT:

        VFX_ASSERT(argSize == 0);

        ret = (VfxU32)connection->getText();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_SET_IME_LAYOUT:

        VFX_ASSERT(argSize == 9);

        connection->setIMEUILayout((VfxS32)args[0], (VfxS32)args[1], (VfxS32)args[2], (VfxS32)args[3], 
            (VfxS32)args[4], (VfxS32)args[5], (VfxS32)args[6], (VfxS32)args[7], ((args[8] == 1) ? VFX_TRUE : VFX_FALSE));
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_CURSOR_INDEX:

        VFX_ASSERT(argSize == 0);

        ret = (VfxU32)connection->getCursorIndex();
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_GET_CURSOR_RECT:

        VFX_ASSERT(argSize == 4);

        ret = (connection->getCursorRect((VfxS32 *)args[0], (VfxS32 *)args[1], (VfxS32 *)args[2], (VfxS32 *)args[3]) == VFX_TRUE) ? 1 : 0;
        
        break;
        
    case IME_SRV_INPUT_CON_MSG_SEND_IME_NOTIFICATION:
        
        VFX_ASSERT(argSize == 2);

        ret = (connection->sendIMENotification((InputNotificationEnum)args[0], (void *)args[1]) == VFX_TRUE) ? 1 : 0;

        break;
        
    default:
        break;
    }

    return ret;
}


void VsrvInputManager::rotate()
{
    if (m_mreServiceInstance)
    {
        m_mreServiceInstance->vt->rotate(m_mreServiceInstance);
    }
}


void VsrvInputManager::beforeRotate()
{
    if (m_mreServiceInstance)
    {
        m_mreServiceInstance->vt->beforeRotate(m_mreServiceInstance);
    }
}


void VsrvInputManager::setSpecialEnterKey(VfxBool isEnabled)
{
    if (m_mreServiceInstance)
    {
        m_mreServiceInstance->vt->setSpecialEnterKey(m_mreServiceInstance, isEnabled);
    }
}


void VsrvInputManager::resetIMEState()
{
    if (m_mreServiceInstance)
    {
        m_mreServiceInstance->vt->resetIMEState(m_mreServiceInstance);
    }
}


IImeService* VsrvInputManager::getMreService()
{
    return m_mreServiceInstance;
}

#else /* #ifdef __MRE_SDK__ */

VsrvInputManager::VsrvInputManager():
	m_currInputServer(NULL),
	m_currInputBinding(NULL)
{
    
}

vrt_allocator_handle VsrvInputManager::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}

VsrvInputManager::~VsrvInputManager()
{

}


void VsrvInputManager::onInit()
{
    VfxObject::onInit();

    // If there is other input server, we should have a input server list
    // and get the current active input server here
	m_currInputServer = VFX_STATIC_CAST(VFX_OBJ_GET_INSTANCE(VadpInputServer), VsrvInputMethodInterface*); 

	VFX_ASSERT(m_currInputServer);
}


void VsrvInputManager::onDeinit()
{
    VFX_OBJ_CLOSE_INSTANCE(VadpInputServer);

    m_currInputServer = NULL;

    VfxObject::onDeinit();
}


VfxBool VsrvInputManager::bindInput(VsrvInputBinding *binding)
{
    m_currInputBinding = binding;

    VFX_ASSERT(m_currInputBinding->getConnection());

	if (m_currInputBinding && m_currInputServer)
	{
	    return m_currInputServer->bindInput(m_currInputBinding);
	}
	else
	{
	    return VFX_FALSE;
	}
}

VsrvInputBinding* VsrvInputManager::getBinding()
{
    if (m_currInputServer)
    {
        return m_currInputServer->getBinding();
    }
    else
    {
        return NULL;
    }
}

VfxBool VsrvInputManager::unbindInput(VsrvInputBinding *binding)
{
	if (m_currInputServer)
	{
	    if (m_currInputServer->unbindInput(binding))
	    {
            m_currInputBinding = NULL;
            return VFX_TRUE;
	    }
        else
        {
            return VFX_FALSE;
        }
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::activateInput()
{
	if (m_currInputServer)
	{
		return m_currInputServer->activateInput();
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::deactivateInput()
{
	if (m_currInputServer)
	{
		return m_currInputServer->deactivateInput();
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::dispatchKeyEvent(VfxKeyEvent &event)
{
	if (m_currInputServer)
	{
		return m_currInputServer->dispatchKeyEvent(event);
	}
	else
	{
	    return VFX_FALSE;
	}
}


VfxBool VsrvInputManager::dispatchPenEvent(VfxPenEvent &event)
{
	if (m_currInputServer)
	{
		return m_currInputServer->dispatchPenEvent(event);
	}
	else
	{
	    return VFX_FALSE;
	}
}



 void VsrvInputManager::override_autocap() 
    {
        if (m_currInputServer)
	    {
		    m_currInputServer->override_autocap();
	    }
    }


void VsrvInputManager::disableSymbolPicker()
{
	if (m_currInputServer)
	{
		m_currInputServer->disableSymbolPicker();
	}
}

void VsrvInputManager::enableSymbolPicker()
{
	if (m_currInputServer)
	{
		m_currInputServer->enableSymbolPicker();
	}
}

VfxBool VsrvInputManager::getCharInfor(VfxWChar code, VfxWChar *inforBuf, VfxU32 bufSize, mmi_imm_input_mode_enum mode) const
{
	if (m_currInputServer)
	{
		return m_currInputServer->getCharInfor(code, inforBuf, bufSize, mode);
	}
	else
	{
	    return VFX_FALSE;
	}
}

VfxBool VsrvInputManager::isIMEState() const
{
	if (m_currInputServer)
	{
		return m_currInputServer->isIMEState();
	}
	else
	{
	    return VFX_FALSE;
	}
}

void VsrvInputManager::addNewWordsFromText(VfxWChar *text)
{
	if (m_currInputServer)
	{
		m_currInputServer->addNewWordsFromText(text);
	}
}

mmi_imm_input_mode_enum VsrvInputManager::getCurrInputMode() const
{
	if (m_currInputServer)
	{
		return m_currInputServer->getCurrInputMode();
	}
	else
	{
	    return IMM_INPUT_MODE_NONE;
	}
}

mmi_imm_input_type_enum VsrvInputManager::getCurrInputType() const
{
	if (m_currInputServer)
	{
		return m_currInputServer->getCurrInputType();
	}
	else
	{
	    return IMM_INPUT_TYPE_NONE;
	}
}

mmi_imm_input_mode_enum* VsrvInputManager::getCurrrUserSpecificInputModeList() 
{
	if (m_currInputServer)
	{
		return m_currInputServer->getCurrrUserSpecificInputModeList();
	}
	else
	{
	    return NULL;
	}
}


VfxU32 VsrvInputManager::getInputMethodHistorySize() const
{
	if (m_currInputServer)
	{
		return m_currInputServer->getInputMethodHistorySize();
	}
	else
	{
	    return 0;
	}
}


void VsrvInputManager::getInputMethodHistory(void *historyAddress)
{
	if (m_currInputServer)
	{
		m_currInputServer->getInputMethodHistory(historyAddress);
	}
}


void VsrvInputManager::setInputMethodHistory(void *historyAddress)
{
	if (m_currInputServer)
	{
		m_currInputServer->setInputMethodHistory(historyAddress);
	}
}


void VsrvInputManager::enableAutoCapInHistory(void *historyAddress)
{
    if (m_currInputServer)
	{
		m_currInputServer->enableAutoCapInHistory(historyAddress);
	}
}


void VsrvInputManager::showSoftInput()
{
    if (m_currInputServer)
	{
		m_currInputServer->showSoftInput();
	}
}


void VsrvInputManager::hideSoftInput()
{
    if (m_currInputServer)
	{
		m_currInputServer->hideSoftInput();
	}
}


VfxBool VsrvInputManager::isSoftInputVisible()
{
    if (m_currInputServer)
	{
		return m_currInputServer->isSoftInputVisible();
	}

    return VFX_FALSE;
}



VfxS32 VsrvInputManager::isValidInputString(VfxWChar *string, VfxS32 len)
{
    if (m_currInputServer)
	{
		return m_currInputServer->isValidInputString(string, len);
	}
    else
    {
        return 0;
    }
}


VfxBool VsrvInputManager::isValidInputStringForPaste(VfxWChar *string, VfxS32 len)
{
    if (m_currInputServer)
	{
		return m_currInputServer->isValidInputStringForPaste(string, len);
	}
    else
    {
        return 0;
    }
}


void VsrvInputManager::cursorPosChanged(VfxRect &cursorRect)
{
    if (m_currInputServer)
	{
		m_currInputServer->cursorPosChanged(cursorRect);
	}
    else
    {
        return;
    }
}


VfxBool VsrvInputManager::isInputMethodUIControl(VfxControl *control)
{
    if (m_currInputServer)
	{
		return m_currInputServer->isInputMethodUIControl(control);
	}
    else
    {
        return VFX_FALSE;
    }
}


void VsrvInputManager::rotate()
{
    if (m_currInputServer)
    {
        m_currInputServer->rotate();
    }
}


void VsrvInputManager::beforeRotate()
{
    if (m_currInputServer)
    {
        m_currInputServer->beforeRotate();
    }
}

void VsrvInputManager::resetIMEState()
{
    if (m_currInputServer)
    {
        m_currInputServer->resetIMEState();
    }
}


void VsrvInputManager::setSpecialEnterKey(VfxBool isEnabled)
{
    if (m_currInputServer)
    {
        m_currInputServer->setSpecialEnterKey(isEnabled);
    }
}


void VsrvInputManager::setInputModeSwitchable(VfxBool isSwitchable)
{
	if (m_currInputServer)
	{
		m_currInputServer->setInputModeSwitchable(isSwitchable);
	}
}

#endif /* #ifdef __MRE_SDK__ */




