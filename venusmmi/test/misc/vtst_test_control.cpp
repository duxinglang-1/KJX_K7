/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_test_control.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus test application. This file is in mmi_framework module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_test_control.h"

#include "vtst_test_button.h"
#include "vfx_screen.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_control.h"


/***************************************************************************** 
 * Class VtstTestControlScr
 *****************************************************************************/
 
VtstTestControlScr::VtstTestControlScr() :
    m_controlText(NULL),
    m_controlButton1(NULL),
    m_controlButton2(NULL),
    m_timer(NULL),
    m_animation(NULL)
{
}

void VtstTestControlScr::onInit()
{
    VfxScreen::onInit();
    
    // Initialize the control
    setBgColor(VFX_COLOR_GREEN);
    
    // Create a text frame
    VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
    m_controlText->setPos(VfxPoint(10, 50));
    m_controlText->setBgColor(VFX_COLOR_BLUE);
    m_controlText->setColor(VFX_COLOR_RED);
    m_controlText->setString(VFX_WSTR("Event"));
    
    // Create a test button
    VFX_OBJ_CREATE(m_controlButton1, VtstButton, this);
    m_controlButton1->setPos(VfxPoint(10, 240));
    m_controlButton1->setBounds(VfxRect(0, 0, 100, 40));
    m_controlButton1->setBgColor(VFX_COLOR_SILVER);
    m_controlButton1->setLabel(VFX_WSTR("Button #1"));
    m_controlButton1->setPressKey(VFX_KEY_CODE_LSK);
    m_controlButton1->m_signalClicked.connect(this, &VtstTestControlScr::onControlButton1Pressed);
    
    // Create a test button
    VFX_OBJ_CREATE(m_controlButton2, VtstButton, this);
    m_controlButton2->setPos(VfxPoint(10, 300));
    m_controlButton2->setBounds(VfxRect(0,0, 100, 40));
    m_controlButton2->setLabel(VFX_WSTR("Button #2"));
    m_controlButton2->setPressKey(VFX_KEY_CODE_RSK);
    m_controlButton2->m_signalClicked.connect(this, &VtstTestControlScr::onControlButton2Pressed);

    // Create an timer
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(1000);
    m_timer->setDuration(50);
    m_timer->m_signalTick.connect(this, &VtstTestControlScr::onTimerTick);

    // Create an animation with one timeline
    VFX_OBJ_CREATE(m_animation, VfxAnimation, this);
    
    VfxFloatTimeline *timeline1;
    VFX_OBJ_CREATE(timeline1, VfxFloatTimeline, m_animation);
    timeline1->setTarget(m_controlButton2);
    timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    timeline1->setFromValue(1.0f);
    timeline1->setToValue(0.0f);
    timeline1->setDurationTime(500);
    timeline1->setRepeatCount(1000);
    timeline1->setAutoReversed(VFX_TRUE);
}


void VtstTestControlScr::onDeinit()
{
    VfxControl::onDeinit();
}


VfxBool VtstTestControlScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
    {
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
    {    }        return VFX_FALSE;
}


void VtstTestControlScr::onControlButton1Pressed(VtstButton *source)
{
    VFX_UNUSED(source);
    
    if (!m_timer->getIsEnabled())
    {
        m_controlText->setString(VFX_WSTR("Timer started"));
        m_controlButton1->setLabel(VFX_WSTR("Stop"));
        m_timer->start();
    }
    else
    {
        m_controlText->setString(VFX_WSTR("Timer stopped"));
        m_controlButton1->setLabel(VFX_WSTR("Start"));
        m_timer->stop();
    }
}


void VtstTestControlScr::onControlButton2Pressed(VtstButton *source)
{
    VFX_UNUSED(source);
    
    if (!m_animation->getIsEnabled())
    {
        m_controlText->setString(VFX_WSTR("Animation started"));
        m_controlButton2->setLabel(VFX_WSTR("Stop"));
        m_animation->start();
    }
    else
    {
        m_controlText->setString(VFX_WSTR("Animation stopped"));
        m_controlButton2->setLabel(VFX_WSTR("Start"));
        m_animation->stop();
    }
}


void VtstTestControlScr::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    VfxPoint  buttonPos     = m_controlButton1->getPos();
    VfxRect   buttonBounds  = m_controlButton1->getBounds();
    VfxRect   frameBounds   = getBounds();

    buttonPos.x += 8;
    if (buttonPos.x >= frameBounds.getMaxX())
    {
        buttonPos.x = frameBounds.getMinX() - buttonBounds.getWidth();
    }

    m_controlButton1->setPos(buttonPos);
}

