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
 *  vcp_button_internal.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_button_internal.h"

#ifdef __cplusplus
extern "C"
{
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/
}
#endif 

#include "MMI_features.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "vfx_frame.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "gui_typedef.h"
#include "vfx_renderer.h"
#include "vrt_canvas.h"
#include "vfx_draw_context.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VCP_BUTTON_PEN_INNER_MARGIN 30
#define VCP_BUTTON_PEN_OUTER_MARGIN 40


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VCP_BUTTON_CLASS_NAME, VcpButtonInternal, VfxControl);


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::VcpButtonInternal
 * DESCRIPTION
 *  Object constructor
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VcpButtonInternal::VcpButtonInternal():    
    m_frameBackgroundUp(NULL),    
    m_frameBackgroundDown(NULL),
    m_frameInterior(NULL),
    m_keyCode(VFX_KEY_CODE_BEGIN),
    m_timerLongpress(NULL),
    m_timerRepeat(NULL),
    m_stateDown(VFX_FALSE),
    m_penDown(VFX_FALSE),
    m_isDisabled(VFX_FALSE),
    m_isDisableUpRedraw(VFX_FALSE)
{

}


VfxKeyCodeEnum VcpButtonInternal::getKeyCode() const
{
    return m_keyCode;   
}


void VcpButtonInternal::setKeyCode(VfxKeyCodeEnum value)
{
    // TODO: check this
    VfxKeypad::unregisterHandler(m_keyCode, this);

    m_keyCode = value;
    
    VfxKeypad::registerHandler(value, this);
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setBackgroundUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setBackgroundUp(VfxFrame    *f)
{
    VFX_OBJ_ASSERT_VALID(f);

    replaceChildFrameWith(m_frameBackgroundUp, f);

    VFX_OBJ_CLOSE(m_frameBackgroundUp);
    
    m_frameBackgroundUp = f;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setBackgroundUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setBackgroundUp(const VfxImageSrc &image, VfxBool autoResizeButton)
{

    m_frameBackgroundUp->setImgContent(image);
    
    if (autoResizeButton)
    {
        this->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundUp->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundDown->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameInterior->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::getBackgroundUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxFrame * VcpButtonInternal::getBackgroundUp()
{
    return m_frameBackgroundUp;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setBackgroundDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setBackgroundDown(VfxFrame    *f)
{
    VFX_OBJ_ASSERT_VALID(f);
    
    replaceChildFrameWith(m_frameBackgroundDown, f);

    VFX_OBJ_CLOSE(m_frameBackgroundDown);
    
    m_frameBackgroundDown = f;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setBackgroundDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setBackgroundDown(const VfxImageSrc &image, VfxBool autoResizeButton)
{

    m_frameBackgroundDown->setImgContent(image);
    
    if (autoResizeButton)
    {
        this->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundUp->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundDown->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameInterior->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::getBackgroundDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxFrame * VcpButtonInternal::getBackgroundDown()
{
    return m_frameBackgroundDown;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setInterior
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setInterior(VfxFrame *f)
{
    VFX_OBJ_ASSERT_VALID(f);

    replaceChildFrameWith(m_frameInterior, f);
    
    VFX_OBJ_CLOSE(m_frameInterior);
    
    m_frameInterior = f;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::setInterior
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::setInterior(const VfxImageSrc &image, VfxBool autoResizeButton)
{

    m_frameInterior->setImgContent(image);
    
    if (autoResizeButton)
    {
        this->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundUp->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameBackgroundDown->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
        m_frameInterior->setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::getFrameInterior
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxFrame * VcpButtonInternal::getFrameInterior()
{
    return m_frameInterior;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::onInit()
{
    VfxKeyCodeEnum value;

    VfxControl::onInit();

    this->setBounds(VfxRect(0, 0, VCP_BUTTON_DEFAULT_WIDTH, VCP_BUTTON_DEFAULT_HEIGHT));

    VFX_OBJ_CREATE(m_frameBackgroundUp, VfxFrame, this);
    m_frameBackgroundUp->setBgColor(VFX_COLOR_TRANSPARENT);
    m_frameBackgroundUp->setPos(VFX_POINT_ZERO);
    m_frameBackgroundUp->setBounds(this->getBounds());

    VFX_OBJ_CREATE(m_frameBackgroundDown, VfxFrame, this);
    m_frameBackgroundDown->setBgColor(VFX_COLOR_TRANSPARENT);
    m_frameBackgroundDown->setPos(VFX_POINT_ZERO);
    m_frameBackgroundDown->setBounds(this->getBounds());

    VFX_OBJ_CREATE(m_frameInterior, VfxFrame, this);
    m_frameInterior->setBgColor(VFX_COLOR_TRANSPARENT);
    m_frameInterior->setPos(VFX_POINT_ZERO);
    m_frameInterior->setBounds(this->getBounds());

    VFX_OBJ_CREATE(m_timerLongpress, VfxTimer, this);
    m_timerLongpress->setStartDelay(VCP_BUTTON_TIMER_START_DELAY_LONGPRESS);
    m_timerLongpress->setDuration(0);
    m_timerLongpress->m_signalTick.connect(this, &VcpButtonInternal::onTimerLongpress);

    VFX_OBJ_CREATE(m_timerRepeat, VfxTimer, this);
    m_timerRepeat->setStartDelay(VCP_BUTTON_TIMER_START_DELAY_REPEAT);
    m_timerRepeat->setDuration(VCP_BUTTON_TIMER_DURATION_REPEAT);
    m_timerRepeat->m_signalTick.connect(this, &VcpButtonInternal::onTimerRepeat);

    /*
     * Register keys
     */
    value = (VfxKeyCodeEnum) getKeyCode();
    VfxKeypad::registerHandler(value, this);
    
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onDeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::onDeinit()
{
    if (m_timerLongpress->getIsEnabled())
    {
        m_timerLongpress->stop();
    }

    if (m_timerRepeat->getIsEnabled())
    {
        m_timerRepeat->stop();
    }

    VfxControl::onDeinit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onKeyInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxBool VcpButtonInternal::onKeyInput(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    if (m_isDisabled)
    {
        return VFX_FALSE;
    }

    if ((VfxS32)event.keyCode == getKeyCode())
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            buttonDown();
            ret = VFX_TRUE;
        }
        else if ((event.type == VFX_KEY_EVENT_TYPE_UP) &&
                 (m_stateDown == VFX_TRUE))
        {
            buttonUp();    
            ret = VFX_TRUE;
        }
           
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onPenInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VfxBool VcpButtonInternal::onPenInput(VfxPenEvent &event)
{
    VfxBool           ret;  
    VfxPoint pos;

    if (m_isDisabled)
    {
        return VFX_FALSE;
    }

    pos = event.getRelPos(this);
    ret = VFX_TRUE;
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (containPoint(pos))
        {
            m_penDown = VFX_TRUE;
            buttonDown();
        #ifdef __MMI_TOUCH_SCREEN__
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        #endif
        }
        else
        {
            ret = VFX_FALSE;
        }
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_penDown = VFX_FALSE;
        if (m_stateDown)
        {
            buttonUp();    
        }
        else
        {
            buttonMoveOut();
        }
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (m_penDown)
        {
            {
                VfxRect bounds = getBounds();
                if (m_stateDown)
                {   
                    // reset button while move out of button
                    VfxRect outerBounds(
                        bounds.getX() - VCP_BUTTON_PEN_OUTER_MARGIN, 
                        bounds.getY() - VCP_BUTTON_PEN_OUTER_MARGIN, 
                        bounds.getWidth() + 2 * VCP_BUTTON_PEN_OUTER_MARGIN, 
                        bounds.getHeight() + 2 * VCP_BUTTON_PEN_OUTER_MARGIN);
                    if (!outerBounds.contains(pos))
                    {
                        buttonMoveOut();
                    }
                }
                else
                {
                    VfxRect innerBounds(
                        bounds.getX() - VCP_BUTTON_PEN_INNER_MARGIN, 
                        bounds.getY() - VCP_BUTTON_PEN_INNER_MARGIN, 
                        bounds.getWidth() + 2 * VCP_BUTTON_PEN_INNER_MARGIN, 
                        bounds.getHeight() + 2 * VCP_BUTTON_PEN_INNER_MARGIN);
                    if (innerBounds.contains(pos))
                    {
                        buttonMoveIn();
                    }
                }
            }
        }
    }

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::buttonDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::buttonDown()
{
    m_stateDown = VFX_TRUE;
    
    if (m_timerLongpress->getIsEnabled())
    {
        m_timerLongpress->stop();
    }
    
    m_timerLongpress->start();

    m_frameBackgroundDown->setHidden(VFX_FALSE);
    m_frameBackgroundUp->setHidden(VFX_TRUE);   

    //invalidate();
    m_eventDown.emit();    

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();        
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::buttonUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::buttonUp()
{
    m_stateDown = VFX_FALSE;            

    if (m_timerLongpress->getIsEnabled())
    {
        m_timerLongpress->stop();
    }

    if (m_timerRepeat->getIsEnabled())
    {
        m_timerRepeat->stop();
    }
    if(m_isDisableUpRedraw == MMI_FALSE)
    {
        //invalidate();
        m_frameBackgroundUp->setHidden(VFX_FALSE);
        m_frameBackgroundDown->setHidden(VFX_TRUE);
    }   
    m_eventUp.emit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::buttonMoveIn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::buttonMoveIn()
{
    m_stateDown = VFX_TRUE;
    
    if (m_timerLongpress->getIsEnabled())
    {
        m_timerLongpress->stop();
    }
    
    m_timerLongpress->start();

    invalidate();

}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::buttonMoveOut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::buttonMoveOut()
{
    m_stateDown = VFX_FALSE;            

    if (m_timerLongpress->getIsEnabled())
    {
        m_timerLongpress->stop();
    }

    if (m_timerRepeat->getIsEnabled())
    {
        m_timerRepeat->stop();
    }

    invalidate();

}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onDraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::onDraw(VfxDrawContext &dc)
{
    VFX_UNUSED(dc);

    if (m_stateDown == VFX_FALSE)
    {
        m_frameBackgroundDown->setHidden(VFX_TRUE);
        m_frameBackgroundUp->setHidden(VFX_FALSE);
    }
    else
    {
       m_frameBackgroundDown->setHidden(VFX_FALSE);
       m_frameBackgroundUp->setHidden(VFX_TRUE);   
    }
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onTimerLongpress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::onTimerLongpress(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_timerRepeat->start();
    
    m_eventLongpress.emit();
}


/*****************************************************************************
 * FUNCTION
 *  VcpButtonInternal::onTimerRepeat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void VcpButtonInternal::onTimerRepeat(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_eventRepeat.emit();
}


