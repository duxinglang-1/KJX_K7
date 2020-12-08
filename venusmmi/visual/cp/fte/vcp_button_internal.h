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
 *  vcp_button_internal.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Button for Venus UI
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_BUTTON_INTERNAL_H__
#define __VCP_BUTTON_INTERNAL_H__

#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vfx_signal.h"
#include "vfx_timer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VCP_BUTTON_TIMER_START_DELAY_LONGPRESS      2000
#define VCP_BUTTON_TIMER_START_DELAY_REPEAT           1000
#define VCP_BUTTON_TIMER_DURATION_REPEAT                1000
#define VCP_BUTTON_CLASS_NAME             "Button"

#define VCP_BUTTON_DEFAULT_WIDTH                            51
#define VCP_BUTTON_DEFAULT_HEIGHT                           38


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class VcpButtonInternal
 *****************************************************************************/
 
/*
 * VcpButtonInternal is a class that can create a button.
 *
 * EXAMPLE
 * <code>
 *  VcpButtonInternal *button;
 *  VFX_OBJ_CREATE(button, VcpButtonInternal, this);
 * </code>
 */
class VcpButtonInternal : public VfxControl
{
VFX_DECLARE_CLASS(VcpButtonInternal);

// Constructor / Destructor
public:
    // <group DOM_Button_VcpButtonInternal_Constructor/Destructor>
    // Default constructor.
    VcpButtonInternal();   

// Method
public:
    // <group DOM_Button_VcpButtonInternal_Method>
    // Get the key code which to response.
    virtual VfxKeyCodeEnum getKeyCode() const;
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set the key code which to response.
    virtual void setKeyCode(VfxKeyCodeEnum value);

// Method
public:
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set background of button when it is in up state.
    void setBackgroundUp(
        VfxFrame    *f  // [IN] Is the frame pointer of button's background when it is up
    );
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set background of button by image id when it is in up state.
    void setBackgroundUp(
        const VfxImageSrc &image, // [IN] Is the image pointer of button's background when it is up
        VfxBool autoResizeButton = VFX_TRUE // [IN] auto resize button or not (default value is VFX_TRUE)
    );

    // <group DOM_Button_VcpButtonInternal_Method>
    // Get background of button when it is in up state.
    // RETURNS: Frame pointer of button's background when it is up.
    VfxFrame * getBackgroundUp();

    // <group DOM_Button_VcpButtonInternal_Method>
    // Set background of button when it is in down state.
    void setBackgroundDown(
        VfxFrame    *f // [IN] Is the frame pointer of button's background when it is down
    );
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set background of button by image id when it is in down state.
    void setBackgroundDown(
        const VfxImageSrc &image, // [IN] Is the image pointer of button's background when it is down
        VfxBool autoResizeButton = VFX_TRUE // [IN] auto resize button or not (default value is VFX_TRUE)
    );
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Get background of button when it is in down state.
    // RETURNS: Frame pointer of button's background when it is down.
    VfxFrame * getBackgroundDown();
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set interior frame on button.
    void setInterior(
        VfxFrame *f // [IN] Is the frame pointer of button's toppest frame
    );
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Set interior image by image id.
    void setInterior(
        const VfxImageSrc &image, // [IN] Is the image pointer of button's toppest frame
        VfxBool autoResizeButton = VFX_FALSE // [IN] auto resize button or not (default value is VFX_FALSE)
    );
    
    // <group DOM_Button_VcpButtonInternal_Method>
    // Get interior frame on button.
    // RETURNS: Frame pointer of button's toppest frame.
    VfxFrame * getFrameInterior();

    // <group DOM_Button_VcpButtonInternal_Method>
    // Set disable button or not.
    void disable(VfxBool isDisabled) {
        m_isDisabled = isDisabled; // [IN] disable button or not
    }

    // <group DOM_Button_VcpButtonInternal_Method>
    // Set disable button up redraw for softkey case.
    void disableUpRedraw(VfxBool isDisabled) {
        m_isDisableUpRedraw = isDisabled; // [IN] disable button up redraw
    }

// Overridable
protected:
    // <group DOM_Button_VcpButtonInternal_Overridable>
    // Handle down event of button.
    virtual void buttonDown();

    // <group DOM_Button_VcpButtonInternal_Overridable>
    // Handle up event of button.
    virtual void buttonUp();

    // <group DOM_Button_VcpButtonInternal_Overridable>
    // Handle pen move in event of button.
    virtual void buttonMoveIn();

    // <group DOM_Button_VcpButtonInternal_Overridable>
    // Handle pen move out event of button.
    virtual void buttonMoveOut();

// Override
protected:
    // <group DOM_Button_VcpButtonInternal_Override>
    virtual void onInit();

    // <group DOM_Button_VcpButtonInternal_Override>
    virtual void onDeinit();
    
    // <group DOM_Button_VcpButtonInternal_Override>
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    // <group DOM_Button_VcpButtonInternal_Override>
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // <group DOM_Button_VcpButtonInternal_Override>
    virtual void onDraw(
        VfxDrawContext &dc
    );

// Variable
public:
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the event of button down.
    VfxSignal0  m_eventDown;
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the event of button up.
    VfxSignal0  m_eventUp;
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the event of button repeat.
    VfxSignal0  m_eventRepeat; 
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the event of button long press.
    VfxSignal0  m_eventLongpress;   

protected:
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the background image of button up.
    VfxFrame    *m_frameBackgroundUp;
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the background image of button down.
    VfxFrame    *m_frameBackgroundDown;
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Is the frame shown on button.
    VfxFrame    *m_frameInterior;

private:
    // <group DOM_Button_VcpButtonInternal_Variable>
    //Key code which to response
    VfxKeyCodeEnum m_keyCode;

    // <group DOM_Button_VcpButtonInternal_Variable>
    // Timer is used to emit button long press event.
    VfxTimer *m_timerLongpress;
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Timer is used to emit button repeat event.
    VfxTimer *m_timerRepeat;    
    
    // <group DOM_Button_VcpButtonInternal_Variable>
    // Down state of button.
    VfxBool   m_stateDown;

    // <group DOM_Button_VcpButtonInternal_Variable>
    // Pen dow on button.
    VfxBool   m_penDown;

    // <group DOM_Button_VcpButtonInternal_Variable>
    // button is disabled.
    VfxBool   m_isDisabled;

    // <group DOM_Button_VcpButtonInternal_Variable>
    // don't redraw when pen up or key up.
    VfxBool   m_isDisableUpRedraw;

// Implementation   
protected:
    // <group DOM_Button_VcpButtonInternal_Implementation>
    // Handle button longpress.
    // RETURNS: void
    void onTimerLongpress(
        VfxTimer *source // [IN] source
    );    
    
    // <group DOM_Button_VcpButtonInternal_Implementation>
    // Handle button repeat.
    // RETURNS: void
    void onTimerRepeat(
        VfxTimer *source // [IN] source
    );    
};


#endif /* __VCP_BUTTON_INTERNAL_H__ */

