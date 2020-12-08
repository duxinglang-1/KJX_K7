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
 *  vtst_rt_aligner.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for aligner testing
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)
#include "vtst_rt_main.h"

#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_keypad.h"
#include "vfx_string.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Class VtstMyControl
 *****************************************************************************/
class VtstMyControl : public VfxControl
{
// Constructor / Destructor
public:
    VtstMyControl() {}

public:
    VfxSignal3<VfxControl*, VfxPenEvent&, VfxBool&> m_signalPenInput;

// Override
protected:
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    )
    {
        VfxBool ret;
        m_signalPenInput.emit(this, event, ret);
        return ret;
    }
};



/***************************************************************************** 
 * Class VtstRtCommandTitleScr
 *****************************************************************************/
class VtstRtAlignerScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtAlignerScr() {}

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 1;}

    virtual VfxS32 phase(VfxS32 idx);

// Implementation
private:
    VfxFrame    *m_frameMain;
    VfxFrame    *m_frameLine1;
    VfxFrame    *m_frameLine2;
    VtstMyControl  *m_controlMainUp;
    VtstMyControl  *m_controlMainDown;
    VtstMyControl  *m_controlMainLeft;
    VtstMyControl  *m_controlMainRight;

    VfxFrame    *m_frameSub;
    VtstMyControl  *m_controlSubUp;
    VtstMyControl  *m_controlSubDown;
    VtstMyControl  *m_controlSubLeft;
    VtstMyControl  *m_controlSubRight;

    void onMainBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);
    void onMainPenSignal(VfxControl* sender, VfxPenEvent &event, VfxBool &handled);

    void onSubBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);
    void onSubPenSignal(VfxControl* sender, VfxPenEvent &event, VfxBool &handled);

    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


void VtstRtAlignerScr::onSubBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VfxS32 w = 5;
    VfxRect bounds = m_frameSub->getBounds();

    m_controlSubUp->setPos(VfxPoint(0, 0));
    m_controlSubUp->setBounds(VfxRect(0, 0, bounds.size.width, w));

    m_controlSubDown->setPos(VfxPoint(0, bounds.size.height - w));
    m_controlSubDown->setBounds(VfxRect(0, 0, bounds.size.width, w));

    m_controlSubLeft->setPos(VfxPoint(0, 0));
    m_controlSubLeft->setBounds(VfxRect(0, 0, w, bounds.size.height));

    m_controlSubRight->setPos(VfxPoint(bounds.size.width - w, 0));
    m_controlSubRight->setBounds(VfxRect(0, 0, w, bounds.size.height));
}


void VtstRtAlignerScr::onSubPenSignal(VfxControl* sender, VfxPenEvent &event, VfxBool &handled)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxFrameAlignerModeEnum mode;
        VfxColor c = sender->getBgColor();
    
        if (c == VfxColor(VFX_COLOR_SILVER))
        {
            c = VFX_COLOR_OLIVE;
            mode = VFX_FRAME_ALIGNER_MODE_SIDE;
        }
        else if (c == VfxColor(VFX_COLOR_OLIVE))
        {
            c = VFX_COLOR_PURPLE;
            mode = VFX_FRAME_ALIGNER_MODE_MID;
        }
        else
        {
            c = VFX_COLOR_SILVER;
            mode = VFX_FRAME_ALIGNER_MODE_NONE;
        }
        sender->setBgColor(c);

        VfxFrameAlignerSideEnum side = VFX_FRAME_ALIGNER_SIDE_TOP;

        if (sender == m_controlSubUp)
        {
            side = VFX_FRAME_ALIGNER_SIDE_TOP;
        }
        else if (sender == m_controlSubDown)
        {
            side = VFX_FRAME_ALIGNER_SIDE_BOTTOM;
        }
        else if (sender == m_controlSubLeft)
        {
            side = VFX_FRAME_ALIGNER_SIDE_LEFT;
        }
        else if (sender == m_controlSubRight)
        {
            side = VFX_FRAME_ALIGNER_SIDE_RIGHT;
        }
        m_frameSub->setAlignParent(side, mode);
    }

    handled = VFX_TRUE;
}


void VtstRtAlignerScr::onMainBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VfxS32 w = 5;
    VfxRect bounds = m_frameMain->getBounds();

    m_frameLine1->setPos(VfxPoint(0, bounds.getMidY()));
    m_frameLine1->setBounds(VfxRect(0, 0, bounds.size.width, 1));

    m_frameLine2->setPos(VfxPoint(bounds.getMidX(), 0));
    m_frameLine2->setBounds(VfxRect(0, 0, 1, bounds.size.height));

    m_controlMainUp->setPos(VfxPoint(0, 0));
    m_controlMainUp->setBounds(VfxRect(0, 0, bounds.size.width, w));

    m_controlMainDown->setPos(VfxPoint(0, bounds.size.height - w));
    m_controlMainDown->setBounds(VfxRect(0, 0, bounds.size.width, w));

    m_controlMainLeft->setPos(VfxPoint(0, 0));
    m_controlMainLeft->setBounds(VfxRect(0, 0, w, bounds.size.height));

    m_controlMainRight->setPos(VfxPoint(bounds.size.width - w, 0));
    m_controlMainRight->setBounds(VfxRect(0, 0, w, bounds.size.height));
}


void VtstRtAlignerScr::onMainPenSignal(VfxControl* sender, VfxPenEvent &event, VfxBool &handled)
{
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            sender->setBgColor(VFX_COLOR_GREY);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                VfxPoint pos = m_frameMain->getPos();
                VfxRect bounds = m_frameMain->getBounds();
                VfxS32 dist;

                if (sender == m_controlMainUp)
                {
                    dist = event.pos.y - event.prevPos.y;
                    pos.y += dist;
                    bounds.size.height -= dist;
                }
                else if (sender == m_controlMainDown)
                {
                    dist = event.pos.y - event.prevPos.y;
                    bounds.size.height += dist;
                }
                else if (sender == m_controlMainLeft)
                {
                    dist = event.pos.x - event.prevPos.x;
                    pos.x += dist;
                    bounds.size.width -= dist;
                }
                else if (sender == m_controlMainRight)
                {
                    dist = event.pos.x - event.prevPos.x;
                    bounds.size.width += dist;
                }
                m_frameMain->setPos(pos);
                m_frameMain->setBounds(bounds);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            sender->setBgColor(VFX_COLOR_TEAL);
            break;

        default:
            break;
    }
    handled = VFX_TRUE;
}


VfxBool VtstRtAlignerScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VfxRect bounds = m_frameMain->getBounds();

        if (event.keyCode == VFX_KEY_CODE_VOL_UP)
        {
            bounds.size.width += 25;
            bounds.size.height += 25;
            m_frameMain->setBounds(bounds);
        }
        if (event.keyCode == VFX_KEY_CODE_VOL_DOWN)
        {
            bounds.size.width -= 25;
            bounds.size.height -= 25;
            m_frameMain->setBounds(bounds);
        }
        if (event.keyCode == VFX_KEY_CODE_5)
        {
            m_controlSubUp->setBgColor(VFX_COLOR_SILVER);
            m_controlSubDown->setBgColor(VFX_COLOR_SILVER);
            m_controlSubLeft->setBgColor(VFX_COLOR_SILVER);
            m_controlSubRight->setBgColor(VFX_COLOR_SILVER);

            m_frameSub->resetAlignParent();
        }
        if (event.keyCode == VFX_KEY_CODE_4)
        {
            m_controlSubUp->setBgColor(VFX_COLOR_OLIVE);
            m_controlSubDown->setBgColor(VFX_COLOR_OLIVE);
            m_controlSubLeft->setBgColor(VFX_COLOR_OLIVE);
            m_controlSubRight->setBgColor(VFX_COLOR_OLIVE);

            m_frameSub->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        }
        if (event.keyCode == VFX_KEY_CODE_2)
        {
            m_frameSub->setPos(VfxPoint(15, 88));
            m_frameSub->setBounds(VfxRect(0, 0, 88, 51));
        }
        if (event.keyCode == VFX_KEY_CODE_3)
        {
            m_frameSub->alignParent();
        }
    }
    
    return VtstRtScr::onKeyInput(event);
}


void VtstRtAlignerScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_BLUE);

    VFX_OBJ_CREATE(m_frameMain, VfxFrame, this);
    m_frameMain->setPos(VfxPoint(50, 100));
    m_frameMain->setBgColor(VFX_COLOR_WHITE);
    m_frameMain->m_signalBoundsChanged.connect(this, &VtstRtAlignerScr::onMainBoundsValueChange);
    m_frameMain->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_frameLine1, VfxFrame, m_frameMain);
    m_frameLine1->setBgColor(VFX_COLOR_BLACK);
    m_frameLine1->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_frameLine2, VfxFrame, m_frameMain);
    m_frameLine2->setBgColor(VFX_COLOR_BLACK);
    m_frameLine2->setAutoAnimate(VFX_TRUE);


    VFX_OBJ_CREATE(m_frameSub, VfxFrame, m_frameMain);
    m_frameSub->setPos(VfxPoint(50, 50));
    m_frameSub->setAnchor(VfxFPoint(0.5, 0.5));
    m_frameSub->setBgColor(VFX_COLOR_AQUA);
    m_frameSub->m_signalBoundsChanged.connect(this, &VtstRtAlignerScr::onSubBoundsValueChange);
    m_frameSub->setAutoAnimate(VFX_TRUE);


    VFX_OBJ_CREATE(m_controlMainUp, VtstMyControl, m_frameMain);
    m_controlMainUp->setBgColor(VFX_COLOR_TEAL);
    m_controlMainUp->m_signalPenInput.connect(this, &VtstRtAlignerScr::onMainPenSignal);
    m_controlMainUp->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlMainDown, VtstMyControl, m_frameMain);
    m_controlMainDown->setBgColor(VFX_COLOR_TEAL);
    m_controlMainDown->m_signalPenInput.connect(this, &VtstRtAlignerScr::onMainPenSignal);
    m_controlMainDown->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlMainLeft, VtstMyControl, m_frameMain);
    m_controlMainLeft->setBgColor(VFX_COLOR_TEAL);
    m_controlMainLeft->m_signalPenInput.connect(this, &VtstRtAlignerScr::onMainPenSignal);
    m_controlMainLeft->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlMainRight, VtstMyControl, m_frameMain);
    m_controlMainRight->setBgColor(VFX_COLOR_TEAL);
    m_controlMainRight->m_signalPenInput.connect(this, &VtstRtAlignerScr::onMainPenSignal);
    m_controlMainRight->setAutoAnimate(VFX_TRUE);


    VFX_OBJ_CREATE(m_controlSubUp, VtstMyControl, m_frameSub);
    m_controlSubUp->setBgColor(VFX_COLOR_SILVER);
    m_controlSubUp->m_signalPenInput.connect(this, &VtstRtAlignerScr::onSubPenSignal);
    m_controlSubUp->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlSubDown, VtstMyControl, m_frameSub);
    m_controlSubDown->setBgColor(VFX_COLOR_SILVER);
    m_controlSubDown->m_signalPenInput.connect(this, &VtstRtAlignerScr::onSubPenSignal);
    m_controlSubDown->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlSubLeft, VtstMyControl, m_frameSub);
    m_controlSubLeft->setBgColor(VFX_COLOR_SILVER);
    m_controlSubLeft->m_signalPenInput.connect(this, &VtstRtAlignerScr::onSubPenSignal);
    m_controlSubLeft->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlSubRight, VtstMyControl, m_frameSub);
    m_controlSubRight->setBgColor(VFX_COLOR_SILVER);
    m_controlSubRight->m_signalPenInput.connect(this, &VtstRtAlignerScr::onSubPenSignal);
    m_controlSubRight->setAutoAnimate(VFX_TRUE);


    m_frameMain->setBounds(VfxRect(0, 0, 100, 100));
    m_frameSub->setBounds(VfxRect(0, 0, 50, 50));

    VfxKeypad::registerHandler(VFX_KEY_CODE_VOL_UP, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_VOL_DOWN, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_4, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_5, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_6, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_2, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_3, this);
}


VfxS32 VtstRtAlignerScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Frame Aligner"));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_aligner(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAlignerScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
