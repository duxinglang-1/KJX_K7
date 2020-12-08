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
 *  vtst_test_button.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_test_button.h"

#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "vfx_control.h"
#include "vfx_draw_context.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Class VtstButton
 *****************************************************************************/
 
VtstButton::VtstButton() :
    m_label(VFX_WSTR("Label")),
    m_pressed(VFX_FALSE),
    m_pressKey(VFX_KEY_CODE_UNKNOWN)
{
}


const VfxWString &VtstButton::getLabel() const
{
    return m_label;
}


VfxBool VtstButton::getPressed() const
{
    return m_pressed;
}


VfxKeyCodeEnum VtstButton::getPressKey() const
{
    return m_pressKey;
}


void VtstButton::setLabel(const VfxWString &value)
{
    m_label = value;

    invalidate();
}


void VtstButton::setPressed(VfxBool value)
{
    m_pressed = value;

    invalidate();
}


void VtstButton::setPressKey(VfxKeyCodeEnum value)
{
    VfxKeypad::unregisterHandler(m_pressKey, this);
    VfxKeypad::registerHandler(value, this);

    m_pressKey = value;
}


void VtstButton::onInit()
{
    VfxControl::onInit();
}


void VtstButton::onDeinit()
{
    VfxKeypad::unregisterAllHandler(this);
    
    VfxControl::onDeinit();
}


void VtstButton::onDraw(VfxDrawContext &dc)
{
    // Draw background
    VfxRect bounds = getBounds();
    
    dc.setFillColor(VFX_COLOR_SILVER);
    dc.fillRect(bounds.origin.x + 1, bounds.origin.y + 1, bounds.size.width - 2, bounds.size.height - 2);

    // Draw label and border
    VfxBool is_pressed = getPressed();
    if (is_pressed)
    {
        dc.setFillColor(VFX_COLOR_BLACK);
        dc.drawText(bounds.getMinX() + 3, bounds.getMinY() + 3, getLabel());
        
        dc.setStrokeColor(VFX_COLOR_GREY);
        dc.drawLine(bounds.getMinX() + 1, bounds.getMinY(), bounds.getMaxX() - 1, bounds.getMinY());
        dc.drawLine(bounds.getMinX(), bounds.getMinY() + 1, bounds.getMinX(), bounds.getMaxY() - 1);
        
        dc.setStrokeColor(VFX_COLOR_WHITE);
        dc.drawLine(bounds.getMaxX(), bounds.getMinY() + 1, bounds.getMaxX(), bounds.getMaxY() - 1);
        dc.drawLine(bounds.getMinX() + 1, bounds.getMaxY(), bounds.getMaxX() - 1, bounds.getMaxY());
    }
    else
    {
        dc.setFillColor(VFX_COLOR_BLACK);
        dc.drawText(bounds.getMinX() + 2, bounds.getMinY() + 2, getLabel());
        
        dc.setStrokeColor(VFX_COLOR_WHITE);
        dc.drawLine(bounds.getMinX() + 1, bounds.getMinY(), bounds.getMaxX() - 1, bounds.getMinY());
        dc.drawLine(bounds.getMinX(), bounds.getMinY() + 1, bounds.getMinX(), bounds.getMaxY() - 1);
        
        dc.setStrokeColor(VFX_COLOR_GREY);
        dc.drawLine(bounds.getMaxX(), bounds.getMinY() + 1, bounds.getMaxX(), bounds.getMaxY() - 1);
        dc.drawLine(bounds.getMinX() + 1, bounds.getMaxY(), bounds.getMaxX() - 1, bounds.getMaxY());
    }
}


VfxBool VtstButton::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        setPressed(VFX_TRUE);
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        setPressed(VFX_FALSE);

        // If pen up at this button, emit clicked event
        if (containPoint(pos))
        {
            m_signalClicked.emit(this);
        }
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            setPressed(VFX_TRUE);
        }
        else
        {
            setPressed(VFX_FALSE);
        }
        return VFX_TRUE;
    }
    
    return VfxControl::onPenInput(event);
}


VfxBool VtstButton::onKeyInput(VfxKeyEvent &event)
{
    VfxKeyCodeEnum press_key = (VfxKeyCodeEnum) getPressKey();
    if (event.keyCode == press_key)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            setPressed(VFX_TRUE);
            m_signalClicked.emit(this);
            return VFX_TRUE;
        }
        else if (event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            setPressed(VFX_FALSE);
            return VFX_TRUE;
        }
    }
    
    return VfxControl::onKeyInput(event);
}

