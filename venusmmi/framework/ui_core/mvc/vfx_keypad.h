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
 *  vfx_keypad.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_KEYPAD_H__
#define __VFX_KEYPAD_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// VfxObject
#include "vfx_object.h"

#include "vfx_input_event.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// The VfxKeypad registered name
#define VFX_KEYPAD_CLASS_NAME           "Keypad"
// The VfxAccessKeyMgr registered name
#define VFX_ACCESSKEY_MGR               "VfxAccessKeyMgr"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxControl;


/***************************************************************************** 
 * Class VfxAccessKeyMgr
 *****************************************************************************/

/*
 * VfxAccessKeyMgr is an helper manager to receive key and dispatch to 
 * registered controls.
 *
 * SEE ALSO: VfxKeyEvent, VfxControl
 */
class VfxAccessKeyMgr : public VfxObject
{
    VFX_DECLARE_CLASS(VfxAccessKeyMgr);

// Constructor / Destructor
public:
    // Default constructor
    VfxAccessKeyMgr();
    // Destructor
    virtual ~VfxAccessKeyMgr();

// Framework methods
public:
    // Internal used. Dispatch a given key event.
    VfxBool processKeyInput(
        VfxKeyEvent &event      // [IN] the key input event
    );

// Method    
public:
    // Registers key event by control
    void registerHandler(
        VfxKeyCodeEnum keyCode,     // key code
        VfxControl *control         // control to be 
    );

    // Unregisters key event by control
    void unregisterHandler(
        VfxKeyCodeEnum keyCode,     // key code
        VfxControl *control         // control
    );

    // Unregisters all key event by control
    void unregisterAllHandler(
        VfxControl *control         // control
    );

// Implemenetation
private:
    class HandlerStackEntry : public VfxBase
    {
    public:
        VfxKeyCodeEnum          m_keyCode;
        VfxWeakPtr <VfxControl> m_controlPtr;
        
        HandlerStackEntry  *m_prev;
        HandlerStackEntry  *m_next;
    };

    HandlerStackEntry *m_handlerStackHead;
    HandlerStackEntry *m_handlerStackTail;

    HandlerStackEntry *findHandler(VfxKeyCodeEnum keyCode, VfxControl *control);
    void deleteHandler(HandlerStackEntry *handler);
    void removeAllInvalidHandler();
    void clearAllHandlers();
};

/***************************************************************************** 
 * Class VfxKeypad
 *****************************************************************************/

/*
 * VfxKeypad is a singletion class. VfxKeypad receives key input events from system, 
 * and dispatch them.
 *
 * SEE ALSO: VfxKeyEvent, VfxControl
 */
class VfxKeypad : public VfxObject
{
    VFX_DECLARE_CLASS(VfxKeypad);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxKeypad);

// Constructor / Destructor
public:
    // Default constructor
    VfxKeypad();

// Framework methods
public:
    // Internal used
    void reset();

    // Internal used, dispatch a key event
    VfxBool processKeyInput(
        VfxKeyEvent &event     // [IN] The pen input event
    );

    // Internal used, start Receive Key event from framework
    void registerTranslateKey();

// Static Method
public:    
    // Register a key code to a control.
    static void registerHandler(
        VfxKeyCodeEnum keyCode,     // [IN] The key code to register
        VfxControl *control         // [IN] The control to register
    );
    // Unregister a key code to a control.
    static void unregisterHandler(
        VfxKeyCodeEnum keyCode,     // [IN] The key code to unregister
        VfxControl *control         // [IN] The control to unregister
    );
    // Unregister all key codes to a control.
    static void unregisterAllHandler(
        VfxControl *control         // [IN] The control to unregister
    );
    static void sendIncompleteKeyToNewScreen(VfxBool enable);

// Implementation
private:
    VfxBool m_sendKeyToNewScreen;
};


#endif /* __VFX_KEYPAD_H__ */

