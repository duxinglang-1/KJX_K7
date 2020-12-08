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
 *  vtst_auto_animate.cpp
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
 * removed!
 * removed!
 * removed!
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

#include "vtst_auto_animate.h"

#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_keypad.h"
#include "vfx_screen.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"


/***************************************************************************** 
 * Class VtstAutoAnimateScr
 *****************************************************************************/

VtstAutoAnimateScr::VtstAutoAnimateScr() :
    m_controlText(NULL),
    m_controlRect(NULL),
    m_timingFuncId(VFX_TIMING_FUNC_ID_LINEAR)    
{
}


void VtstAutoAnimateScr::onInit()
{
    VfxAppCatScr::onInit();
    
    // Initialize the control
    setBgColor(VFX_COLOR_BLUE);
    
    // Create a color rectangle
    VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
    m_controlRect->setPos(VfxPoint(120, 200));
    m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
    m_controlRect->setAnchor(VfxFPoint(0.5, 0.5));
    m_controlRect->setBgColor(VFX_COLOR_RED);
    m_controlRect->setAutoAnimate(VFX_TRUE);
    
    // Create a text
    VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
    m_controlText->setPos(VfxPoint(10, 80));
    m_controlText->setColor(VFX_COLOR_BLACK);
    m_controlText->setBgColor(VFX_COLOR_GREY);
    m_controlText->setAutoAnimate(VFX_TRUE);
    m_controlText->setString(VFX_WSTR("Press arrow keys or LSK"));
}


void VtstAutoAnimateScr::onDeinit()
{
    VfxKeypad::unregisterAllHandler(this);
    
    VfxScreen::onDeinit();
}


VfxBool VtstAutoAnimateScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_LSK)
        {
            VfxBool auto_animte = m_controlRect->getAutoAnimate();
            if (auto_animte)
            {
                m_controlText->setString(VFX_WSTR("Direct change"));
                m_controlRect->setAutoAnimate(VFX_FALSE);
            }
            else
            {
                m_controlText->setString(VFX_WSTR("Auto animate is ON"));
                m_controlRect->setAutoAnimate(VFX_TRUE);
            }
        }
        else if (event.keyCode == VFX_KEY_CODE_RSK)
        {
            if (m_timingFuncId == VFX_TIMING_FUNC_ID_LINEAR)
            {
                m_controlText->setString(VFX_WSTR("Ease-In"));
                m_timingFuncId = VFX_TIMING_FUNC_ID_EASE_IN;
            }
            else if (m_timingFuncId == VFX_TIMING_FUNC_ID_EASE_IN)
            {
                m_controlText->setString(VFX_WSTR("Ease-Out"));
                m_timingFuncId = VFX_TIMING_FUNC_ID_EASE_OUT;
            }
            else if (m_timingFuncId == VFX_TIMING_FUNC_ID_EASE_OUT)
            {
                m_controlText->setString(VFX_WSTR("Ease-In-Out"));
                m_timingFuncId = VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT;
            }
            else
            {
                m_controlText->setString(VFX_WSTR("Linear"));
                m_timingFuncId = VFX_TIMING_FUNC_ID_LINEAR;
            }
            
            VfxAutoAnimate::setTimingFunc(m_timingFuncId);
            
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
        {
            m_controlRect->setPos(VfxPoint(120, 100));
            m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
            m_controlRect->setBgColor(VFX_COLOR_GREEN);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
        {
            m_controlRect->setPos(VfxPoint(120, 300));
            m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
            m_controlRect->setBgColor(VFX_COLOR_RED);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            m_controlRect->setBounds(VfxRect(0, 0, 50, 150));
            m_controlRect->setBgColor(VFX_COLOR_YELLOW);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            m_controlRect->setBounds(VfxRect(0, 0, 150, 50));
            m_controlRect->setBgColor(VFX_COLOR_PURPLE);
            return VFX_TRUE;
        }
    }
    
    return VfxAppCatScr::onKeyInput(event);
}

