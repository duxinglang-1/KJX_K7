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
 *  vtst_frame_anchor.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  A Frame Anchor Point example for Venus UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_frame_anchor.h"

#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "vfx_draw_context.h"


/***************************************************************************** 
 * Class VtstFrameAnchorScr
 *****************************************************************************/

VtstFrameAnchorScr::VtstFrameAnchorScr() :
    m_controlText(NULL),
    m_controlRect(NULL)
{
}


void VtstFrameAnchorScr::onInit()
{
    VfxAppCatScr::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_BLUE);

    /*
     * Add controls to screen
     */
    VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
    m_controlText->setPos(VfxPoint(120, 10));
    m_controlText->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_controlText->setString(VFX_WSTR("Press arrow keys or Pen Down"));
    m_controlText->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlRect, VfxTextFrame, this);
    m_controlRect->setPos(VfxPoint(120, 160));
    m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
    m_controlRect->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_controlRect->setBgColor(VfxColor(127, 255, 0, 0));
    m_controlRect->setAutoAnimate(VFX_TRUE);

    /*
     * Register keys
     */
    VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW, this);
}


void VtstFrameAnchorScr::onDraw(VfxDrawContext &dc)
{
    // Draw cross lines
    dc.setStrokeColor(VFX_COLOR_WHITE);
    dc.drawLine(120, 40, 120, 280);
    dc.drawLine(20, 160, 220, 160);
}


VfxBool VtstFrameAnchorScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VfxFPoint anchor = m_controlRect->getAnchor();
        
        if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
        {
            anchor.y -= 0.25f;
            anchor.y = VFX_MAX(0.0f, anchor.y);
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
        {
            anchor.y += 0.25f;
            anchor.y = VFX_MIN(1.0f, anchor.y);
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            anchor.x -= 0.25f;
            anchor.x = VFX_MAX(0.0f, anchor.x);
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            anchor.x += 0.25f;
            anchor.x = VFX_MIN(1.0f, anchor.x);
        }

        m_controlRect->setAnchor(anchor);

        // Update anchor point position on screen
        VfxWString str;
        str.format("Anchor = (%0.2f, %0.2f)", anchor.x, anchor.y);
        m_controlText->setString(str);
    }
    
    return VFX_TRUE;
}


VfxBool VtstFrameAnchorScr::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxPoint pen_pos = event.getRelPos(this);
        VfxRect rect = m_controlRect->getRect();
        if (rect.contains(pen_pos))
        {
            m_controlText->setString(VFX_WSTR("Inside"));
        }
        else
        {
            m_controlText->setString(VFX_WSTR("Outside"));
        }
    }
    
    return VFX_TRUE;
}

