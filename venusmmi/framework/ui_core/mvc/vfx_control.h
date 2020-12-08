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
 *  vfx_control.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Core Class VfxControl
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CONTROL_H__
#define __VFX_CONTROL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxFrame
#include "vfx_frame.h"
// For VfxKeyCodeEnum
#include "vfx_input_event.h"

#include "vfx_input_event.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// The VfxControl registered name
#define VFX_CONTROL_CLASS_NAME          "Control"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*
 * Predefine Classes
 */
class VfxArchive;
class VfxKeyEvent;
class VfxPenEvent;
class VfxScreen;


/***************************************************************************** 
 * Class VfxControl
 *****************************************************************************/

/*
 * VfxControl is a base class for Venus UI components, inherit from VfxFrame.
 */
class VfxControl : public VfxFrame
{
    VFX_DECLARE_CLASS(VfxControl);    

// Static method
public:
    // Return the root control.
    //
    // RETURNS: The root control. Return NULL if there is no root control.
    static VfxControl *getRootControl();

// Constructor / Destructor
public:
    // Default constructor
    VfxControl();

// Property
public:
    // Return the disabled states.
    //
    // RETURNS: VFX_TRUE if the control is disabled.
    virtual VfxBool getIsDisabled() const;

    // Set the control to disabled state.
    virtual void setIsDisabled(
        VfxBool isDisabled   // [IN] The disable state
    );
    
// Control hierarchy method
public:
    // Return the parent control.
    //
    // RETURNS: The parent control.
    VfxControl *getParentControl() const;

    // Find the screen that contains the control
    //
    // RETURNS: The screen that contains the control.
    //  Returns NULL if there is no screen contains the control.
    VfxScreen *findScreen() const;

// Serialize method
public:
    // Serialize this control state to given archive.
    VfxBool serialize(
        VfxArchive &ar          // [IN] The archive to serialize to
    );
    
    // Restore this control state from given archive.
    void restore(
        VfxArchive &ar          // [IN] The archive to restore from
    );

// Framework method
public:
    // Internal used.
    //
    // SEE ALSO: onPreviewPenInput
    VfxBool previewPenInput(
        VfxPenEvent &event
    )
    {
        return onPreviewPenInput(event);
    }
    
    // Internal used for processing pen input.
    //
    // SEE ALSO: onPenInput
    VfxBool penInput(VfxPenEvent &event);

    VfxBool penAbortAccepted(
        VfxControl *aborter,                                        // [IN] aborter control
        VfxPenAbortReasonEnum reason = VFX_PEN_ABORT_REASON_DEFAULT // [IN] abort reason
    );

// Pen input method
public:
    // Try to set the pen capture control to this control.
    //
    // RETURNS: Return VFX_TRUE if successful. Otherwise, return VFX_FALSE.
    //
    // SEE ALSO: VfxPenEventTypeEnum
    VfxBool capture(
        VfxPenAbortReasonEnum reason = VFX_PEN_ABORT_REASON_DEFAULT
    );

// Key Input Method
public:
    // Register an accelerator key. When the key is pressed, 
    //  and no one focus control handle it, your onKeyInput will be invoked.
    //
    // SEE ALSO: unregisterKeyHandler, onKeyInput
    void registerKeyHandler(VfxKeyCodeEnum keyCode)
    {
        processRegisterAccessKeyHandler(keyCode, this);
    }

    // Unregister an accelerator key.
    //
    // SEE ALSO: registerKeyHandler
    void unregisterKeyHandler(VfxKeyCodeEnum keyCode)
    {
        processUnregisterAccessKeyHandler(keyCode, this);
    }

    // Unregister all accelerator keys.
    //
    // SEE ALSO: registerKeyHandler
    void unregisterAllKeyHandler()
    {
        processUnregisterAllAccessKeyHandler(this);
    }

    // Set the frame is focused
    virtual void setFocused(
        VfxBool value   // [IN] VFX_TRUE means this frame will get focus
    )
    {
        VfxFrame::setFocused(value);
    }

    // Check focus state of this frame
    VfxBool getFocused()
    {
        return VfxFrame::getFocused();
    }

    // Make no child is focused
    void resetFocusChild()
    {
        VfxFrame::resetFocusChild();
    }

// Update
public:
    // This function will post emit the onUpdate function.
    // And this function will only invoke once onUpdate function even you call it many times.
    void checkUpdate();

// Signal
public:    

// Overridable
protected:
    // Override to handle this control to be serialized
    //
    // RETURNS: 
    //  VFX_TRUE if the control would like to serialize itself.
    //  VFX_FALSE if the control does not support serialize.
    virtual VfxBool onSerialize(
        VfxArchive &ar
    );
    
    // Override to handle the control to be restored
    virtual void onRestore(
        VfxArchive &ar
    );

    // Override to handle the preview pen input event.
    //
    // NOTE: The default behavior is doing nothing and return VFX_FALSE.
    //
    // RETURNS: Return VFX_TRUE if the event has been handled. 
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: onPenInput, VfxPenEvent
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event          // [IN] The pen event to be handled
    );
    
    // Override to handle the pen input event.
    //
    // NOTE: The default behavior is doing nothing and return VFX_FALSE.
    //
    // RETURNS: Return VFX_TRUE if the event has been handled. 
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxPenEvent
    virtual VfxBool onPenInput(
        VfxPenEvent &event          // [IN] The pen event to be handled
    );

    // Override to change the behavior of register access key handler
    //
    // NOTE: The default behavior is ask parent control to handle
    virtual void processRegisterAccessKeyHandler(
        VfxKeyCodeEnum keyCode, 
        VfxControl *target
    );

    // Override to change the behavior of unregister access key handler
    //
    // NOTE: The default behavior is ask parent control to handle
    virtual void processUnregisterAccessKeyHandler(
        VfxKeyCodeEnum keyCode,
        VfxControl *target
    );
    
    // Override to change the behavior of unregister all access key handler
    //
    // NOTE: The default behavior is ask parent control to handle
    virtual void processUnregisterAllAccessKeyHandler(
        VfxControl *target
    );
    
    // Override to handle the key input event.
    // This function will be called when your frame is focused or 
    // the frame register access key handler.
    //
    // NOTE: The default behavior is doing nothing and return VFX_FALSE.
    //
    // RETURNS: Return VFX_TRUE if the event has been handled. 
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxKeyEvent
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event          // [IN] The key event to be handled
    );

    // onUpdate will be called after someone call checkUpdate.
    //
    // SEE ALSO: VfxControl::checkUpdate
    virtual void onUpdate() {}

// Override
public:
    virtual VfxBool processFocusKey(VfxKeyEvent &event);
    virtual VfxBool processAccessKey(VfxKeyEvent &event);

public:
    // Override this to accept capture pen abort or not.
    // RETURNS: VFX_TRUE if pen abort is accepeted; otherwise VFX_FALSE.
    virtual VfxBool onPenAbortAccepted(
        VfxControl *aborter,            // [IN] aborter control
        VfxPenAbortReasonEnum reason    // [IN] abort reason
    );

// Varialbe
protected:
    VfxBool     m_checkUpdate;  // Internal used. It is used to merge onUpdate events.
    VfxBool     m_isDisabled;   // Whether the control is disabled.
    VfxBool     m_noAnimUpdate; // Internal used. No animation in onUpdate.

// Implementation
protected:
    // Pointer to the bind visual
    void processUpdate();
};


// Weak Pointer to VfxControl
typedef VfxWeakPtr <VfxControl> VfxControlWeakPtr;

#endif /* __VFX_CONTROL_H__ */

