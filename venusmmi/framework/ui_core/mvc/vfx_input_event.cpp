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
 *  vfx_input_event.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Define Venus input event
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_input_event.h"

#include "vfx_frame.h"
#include "vfx_renderer.h"
#include "vfx_top_level.h"

#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_datatype.h"
#include "vpi_object.h"
#include "vpi_data_type_convertion.h"
#endif

/***************************************************************************** 
 * Class VfxKeyEvent
 *****************************************************************************/

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxKeyEvent::VfxKeyEvent(vm_key_event_struct &event) :
    type(vpi_m2v_convert_key_type(event.type)),
    keyCode(vpi_m2v_convert_key_code(event.keycode)),
    ucs2(event.ucs2),
    specialKeyFlag(vpi_m2v_convert_key_flag(event.specialKeyFlag)),
    timeStamp(event.timeStamp)   
{
}


VfxKeyEvent::operator vm_key_event_struct()
{
    vm_key_event_struct evt;
    VM_STRUCT_INIT(evt, vm_key_event_struct);
    evt.keycode = vpi_v2m_convert_key_code(keyCode);
    evt.specialKeyFlag = vpi_v2m_convert_key_flag(specialKeyFlag);
    evt.timeStamp = timeStamp;
    evt.type = vpi_v2m_convert_key_type(type);
    evt.ucs2 = ucs2;
    return evt;
}
#endif


/***************************************************************************** 
 * Class VfxTouchEvent
 *****************************************************************************/

VfxPoint VfxTouchEvent::getRelPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return pos;
    }
    
    return root->convertPointTo(pos, relTo);
}

VfxPoint VfxTouchEvent::getRelPrevPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return prevPos;
    }
    
    return root->convertPointTo(prevPos, relTo);
}

VfxPoint VfxTouchEvent::getRelDownPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return downPos;
    }
    
    return root->convertPointTo(downPos, relTo);
}


/***************************************************************************** 
 * Class VfxPenEvent
 *****************************************************************************/
 
VfxPoint VfxPenEvent::getRelPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return pos;
    }
    
    return root->convertPointTo(pos, relTo, toplevel->isActiveScreenCustomRotate());
}

VfxPoint VfxPenEvent::getRelPrevPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return prevPos;
    }
    
    return root->convertPointTo(prevPos, relTo, toplevel->isActiveScreenCustomRotate());
}

VfxPoint VfxPenEvent::getRelDownPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return downPos;
    }
    
    return root->convertPointTo(downPos, relTo, toplevel->isActiveScreenCustomRotate());
}

VfxPoint VfxPenEvent::getRelPredictPos(const VfxFrame *relTo) const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    const VfxFrame *root = renderer->getRootFrame();
    if (root == NULL)
    {
        return predictPos;
    }

    return root->convertPointTo(predictPos, relTo, toplevel->isActiveScreenCustomRotate());
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxPenEvent::VfxPenEvent(vm_pen_event_struct &event) :
    type(vpi_m2v_convert_pen_type(event.type)),
    timeStamp(event.timeStamp),
    prevTimeStamp(event.prevTimeStamp),
    downTimeStamp(event.downTimeStamp),
    pos(event.pos),
    predictPos(event.predictPos),
    prevPos(event.prevPos),
    downPos(event.downPos),
    touchCount(1)
{
    source = NULL;
    target = NULL;
    if (event.source)
    {
        source = (VfxObject *)event.source->getObjectHandle();
    }
    if (event.target)
    {
        target = (VfxObject *)event.target->getObjectHandle();
    }

    vm_object_list_entry_struct *entry;
    for (entry = event.relObjList.head; entry != NULL; entry = entry->next)
    {
        VfxObject *obj = NULL;
        if (entry->object)
        {
            obj = (VfxObject *)entry->object->getObjectHandle();
        }
        if (obj)
        {
            relObjList.append(obj);
        }
    }
}


VfxPenEvent::operator vm_pen_event_struct()
{
    vm_pen_event_struct vm_evt;
    VM_STRUCT_INIT(vm_evt, vm_pen_event_struct);

    vm_evt.type = vpi_v2m_convert_pen_type(type);
    vm_evt.downPos = downPos;
    vm_evt.timeStamp = timeStamp;
    vm_evt.prevTimeStamp = prevTimeStamp;
    vm_evt.downTimeStamp = downTimeStamp;
    vm_evt.pos = pos;
    vm_evt.predictPos = predictPos;
    vm_evt.prevPos = prevPos;
    vm_evt.downPos = downPos;

    return vm_evt;
}
#endif


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfxKeyCodeCheck
 * DESCRIPTION
 *  Check the test key code whatever own the given normal key code
 * PARAMETERS
 *  testKeyCode   [IN]    the key code to be checked
 *  normalKeyCode [IN]    the normal key code to check
 * RETURNS
 *
 *****************************************************************************/
VfxBool vfxKeyCodeCheck(VfxKeyCodeEnum testKeyCode, VfxKeyCodeEnum normalKeyCode)
{
    VFX_ASSERT(testKeyCode < VFX_KEY_CODE_END_OF_ENUM);
    VFX_ASSERT(normalKeyCode < VFX_KEY_CODE_END_OF_NORMAL);

    /*
     * Always not matched if testKeyCode or normalKeyCode is unknown key code
     */
    if (testKeyCode == VFX_KEY_CODE_UNKNOWN || normalKeyCode == VFX_KEY_CODE_UNKNOWN)
    {
        return VFX_FALSE;
    }
        
    /*
     * Spcial key codes
     */
    if (testKeyCode == VFX_KEY_CODE_SPECIAL_ALL)
    {
        return VFX_TRUE;
    }
    else if (testKeyCode == VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS)
    {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        if (((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_0 && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_9)
            || ((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_A && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_Z)
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_STAR
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_POUND
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_QUESTION
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_PERIOD
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_DOLLAR)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
#else
        if (((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_0 && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_9)
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_STAR
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_POUND
            || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_QWERTY)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
#endif
    }
    else if (testKeyCode == VFX_KEY_CODE_SPECIAL_ALL_SOFT_KEYS)
    {
        if ((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_LSK &&
            (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_CSK)
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (testKeyCode == VFX_KEY_CODE_SPECIAL_ALL_ARROW)
    {
        if ((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_ARROW_UP &&
            (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_ARROW_RIGHT)
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else if (testKeyCode == VFX_KEY_CODE_SPECIAL_ALL_NUMBER)
    {
        if ((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_0 &&
            (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_9)
        {
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    // Others (Always put the test here)
    return testKeyCode == normalKeyCode;
}

