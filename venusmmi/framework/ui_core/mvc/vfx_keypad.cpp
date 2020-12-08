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
 *  vfx_keypad.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Keypad Input Sub-system
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_keypad.h"

#include "vfx_input_event.h"
#include "vfx_control.h"
#include "vfx_screen.h"
#include "vfx_top_level.h"
#include "vfx_renderer.h"

#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vrt_datatype.h"
#include "vfx_system.h"

#include "vadp_sys_trc.h"
extern "C"
{
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

extern "C"
{
#include "vrt_logger_rsp_time.h"
}

/***************************************************************************** 
 * Local Declaration
 *****************************************************************************/

static MMI_BOOL vfx_frm_translate_keyhandler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    // TODO: Revise to get form driver (outside of Venus)
    VfxMsec currentTime = (VfxMsec)vrt_sys_get_time();

    // Create a keypad input event
    VfxKeyEvent event;
    event.source            = NULL;
    event.target            = NULL;
    event.type              = (VfxKeyEventTypeEnum) mmi_key_type;
    event.keyCode           = (VfxKeyCodeEnum)mmi_key_code;
    event.ucs2              = ucs2_value;
    event.specialKeyFlag    = special_key_flag;    
    event.timeStamp         = currentTime;

    switch (event.type)
    {
    case VFX_KEY_EVENT_TYPE_DOWN:
        VfxRendererProfiling::reset();
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XKD", SA_start);
#endif
        break;
    case VFX_KEY_EVENT_TYPE_UP:
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XKU", SA_start);
#endif
        break;
    }

    VfxKeypad* keypad = VFX_OBJ_GET_INSTANCE(VfxKeypad);

    // Response time utility starts    
    switch(event.type)
    {
        case VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN:
        //case VFX_KEY_EVENT_TYPE_DOWN: // Already covered in VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN
        {
            /* vrt_log_rsp_time_logging_var(2001); */
            vrt_log_rsp_time_set_event(VRT_LOG_RSP_TIME_EVENT_KEY_DOWN);
            break;
        }
        case VFX_KEY_EVENT_TYPE_UP:
        {
            /* vrt_log_rsp_time_logging_var(2002); */
            vrt_log_rsp_time_set_event(VRT_LOG_RSP_TIME_EVENT_KEY_UP);
            break;
        }
        default:
            break;
    }
    // Response time utility completes    

    MMI_BOOL ret = keypad->processKeyInput(event) ? MMI_TRUE : MMI_FALSE;
    if (ret)
    {
        // Force commit if the key event has been handled
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
    }
    
    switch (event.type)
    {
    case VFX_KEY_EVENT_TYPE_DOWN:
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XKD", SA_stop);
#endif
        break;
    case VFX_KEY_EVENT_TYPE_UP:
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XKU", SA_stop);
#endif
        break;
    }

    return ret;    
}

// This is a dummy key handler, it will ignore the input
static void vfx_frm_key_dummy_handler(void)
{
}


/***************************************************************************** 
 * Class VfxAccessKeyMgr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_ACCESSKEY_MGR, VfxAccessKeyMgr, VfxObject);


VfxAccessKeyMgr::VfxAccessKeyMgr() :
    m_handlerStackHead(NULL),
    m_handlerStackTail(NULL)
{
}


VfxAccessKeyMgr::~VfxAccessKeyMgr()
{
    // TODO: move to ondeinit()
    clearAllHandlers();
}


VfxBool VfxAccessKeyMgr::processKeyInput(VfxKeyEvent &event)
{  
    VfxBool is_handled = VFX_FALSE;
    
    // Do nothign if stack is empty
    if (m_handlerStackHead == NULL)
    {
        return VFX_FALSE;
    }

    // Maintain the accesskey flag
    VfxBool preAccessKeyFlag = event.isAccessKey();
    event.specialKeyFlag |= VFX_SPECIAL_KEY_FLAG_ACCESSKEY;

    HandlerStackEntry *i;
        
    // Input event handling
    for (i = m_handlerStackTail; i != NULL; i = i->m_prev)
    {
        if (vfxKeyCodeCheck(i->m_keyCode, event.keyCode))
        {
            VfxControl *control = i->m_controlPtr.get();
            // Ignore hidden frames
            if (control && !control->getHidden())
            {
                is_handled = control->processAccessKey(event);
                
                if (is_handled)
                {
                    break;
                }
            }
        }
    }

    // restore the access key flag
    if (preAccessKeyFlag)
    {
        event.specialKeyFlag |= VFX_SPECIAL_KEY_FLAG_ACCESSKEY;
    }
    else
    {
        event.specialKeyFlag &= ~VFX_SPECIAL_KEY_FLAG_ACCESSKEY;
    }

    return is_handled;
}


void VfxAccessKeyMgr::registerHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_ASSERT(keyCode < VFX_KEY_CODE_END_OF_ENUM);
    VFX_OBJ_ASSERT_VALID(control);

    removeAllInvalidHandler();

    // Do nothing if key code is unknown
    if (keyCode == VFX_KEY_CODE_UNKNOWN)
    {
        return;
    }

    // Create a new handler
    HandlerStackEntry *handler;;
    VFX_SYS_NEW_EX(handler, HandlerStackEntry, ());
    handler->m_keyCode     = keyCode;
    handler->m_controlPtr  = control;

    if (m_handlerStackHead == NULL)
    {
        // If handler stack is empty
        handler->m_prev = NULL;
        handler->m_next = NULL;
        m_handlerStackHead = handler;
        m_handlerStackTail = handler;
    }
    else
    {
        // Push to handler stack list tail
        handler->m_prev = m_handlerStackTail;
        handler->m_next = NULL;
        m_handlerStackTail->m_next = handler;
        m_handlerStackTail = handler;
    }
}


void VfxAccessKeyMgr::unregisterHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_ASSERT(keyCode < VFX_KEY_CODE_END_OF_ENUM);
    VFX_OBJ_ASSERT_VALID(control);

    removeAllInvalidHandler();

    // Do nothing if key code is unknown
    if (keyCode == VFX_KEY_CODE_UNKNOWN)
    {
        return;
    }

    HandlerStackEntry *handler = findHandler(keyCode, control);
    if (handler != NULL)
    {
        deleteHandler(handler);
    }
}


void VfxAccessKeyMgr::unregisterAllHandler(VfxControl *control)
{
    VFX_OBJ_ASSERT_VALID(control);

    HandlerStackEntry **handler_ptr = &m_handlerStackHead;
    while (*handler_ptr != NULL)
    {
        HandlerStackEntry *handler = *handler_ptr;
        if (!handler->m_controlPtr.isValid())
        {
            deleteHandler(handler);
        }
        else if(handler->m_controlPtr == control)
        {
            deleteHandler(handler);
        }
        else
        {
            handler_ptr = &handler->m_next;
        }
    }
}


VfxAccessKeyMgr::HandlerStackEntry *VfxAccessKeyMgr::findHandler(
    VfxKeyCodeEnum keyCode, 
    VfxControl *control)
{
    HandlerStackEntry *i;
    for (i = m_handlerStackTail; i != NULL; i = i->m_prev)
    {
        if (i->m_keyCode == keyCode && i->m_controlPtr == control)
        {
            break;
        }
    }
    return i;
}


void VfxAccessKeyMgr::deleteHandler(HandlerStackEntry *handler)
{
    VFX_ASSERT(handler != NULL);
    
    if (handler->m_prev != NULL)
    {
        handler->m_prev->m_next = handler->m_next;
    }
    else
    {
        m_handlerStackHead = handler->m_next;
    }

    if (handler->m_next != NULL)
    {

        handler->m_next->m_prev = handler->m_prev;
    }
    else
    {
        m_handlerStackTail = handler->m_prev;
    }

    VFX_SYS_DELETE(handler);
}


void VfxAccessKeyMgr::removeAllInvalidHandler()
{
    HandlerStackEntry **handler_ptr = &m_handlerStackHead;
    while (*handler_ptr != NULL)
    {
        HandlerStackEntry *handler = *handler_ptr;
        if (!handler->m_controlPtr.isValid())
        {
            deleteHandler(handler);
        }
        else
        {
            handler_ptr = &handler->m_next;
        }
    }
}


void VfxAccessKeyMgr::clearAllHandlers()
{
    HandlerStackEntry *i = m_handlerStackHead;
    while (i != NULL)
    {
        HandlerStackEntry *next = i->m_next;
        VFX_DELETE(i);
        i = next;
    }
}


/***************************************************************************** 
 * Class VfxKeypad
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_KEYPAD_CLASS_NAME, VfxKeypad, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxKeypad);

VfxKeypad::VfxKeypad() : m_sendKeyToNewScreen(VFX_FALSE)
{
}


void VfxKeypad::reset()
{
    if (!m_sendKeyToNewScreen)
    {
        ClearKeyEvents();
    }
    else
    {
        m_sendKeyToNewScreen = VFX_FALSE;
    }
}


VfxBool VfxKeypad::processKeyInput(VfxKeyEvent &event)
{   
    VFX_LOG(VFX_INFO, VFX_KEYPAD_PROCESS, event.type, event.keyCode, event.timeStamp);        

    VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    return topLevel->processFocusKey(event);
}


void VfxKeypad::registerHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_LOG(VFX_INFO, VFX_KEYPAD_REGISTER, keyCode, control);

    VFX_OBJ_ASSERT_VALID(control);

    control->registerKeyHandler(keyCode);
}


void VfxKeypad::unregisterHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_LOG(VFX_INFO, VFX_KEYPAD_UNREGISTER, keyCode, control);        

    VFX_OBJ_ASSERT_VALID(control);

    control->unregisterKeyHandler(keyCode);
}


void VfxKeypad::unregisterAllHandler(VfxControl *control)
{
    VFX_LOG(VFX_INFO, VFX_KEYPAD_UNREGISTER_ALL, control);        

    VFX_OBJ_ASSERT_VALID(control);

    control->unregisterAllKeyHandler();
}


void VfxKeypad::registerTranslateKey()
{
    SetKeyHandler(vfx_frm_key_dummy_handler, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(vfx_frm_key_dummy_handler, KEY_CSK, KEY_EVENT_DOWN);
    mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_VENUS, vfx_frm_translate_keyhandler);
}


void VfxKeypad::sendIncompleteKeyToNewScreen(VfxBool enable)
{
    VfxKeypad *keypad = VFX_OBJ_GET_INSTANCE(VfxKeypad);
    keypad->m_sendKeyToNewScreen = enable;
}

