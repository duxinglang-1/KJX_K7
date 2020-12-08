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
 *  vtst_rt_auto_animate.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Auto-Animation
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_rt_main.h"

#include "vfx_frame.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_auto_animate.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Auto Animation Test Implementation
 *****************************************************************************/

class VtstRtAutoAnimation : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_controlRect;

// Constructor / Destructor
public:
    VtstRtAutoAnimation() : m_controlRect(NULL) 
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Auto Animation Test"));

        // Create a color rectangle
        VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
        m_controlRect->setPos(120, 200);
        m_controlRect->setSize(100, 100);
        m_controlRect->setAnchor(0.5, 0.5);
        m_controlRect->setBgColor(VFX_COLOR_RED);
        m_controlRect->setAutoAnimate(VFX_TRUE);    

        VfxAutoAnimate::initAnimateBegin();
        m_controlRect->setPos(120, 100);
        m_controlRect->setBgColor(VFX_COLOR_GREEN);
        VfxAutoAnimate::initAnimateEnd();
    }

    virtual int start()
    {      
        return 5;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            confirm(VFX_WSTR("Can you see the animation?"));
            return -1;
        }
        else if (idx == 1)
        {
            m_controlRect->setPos(120, 300);
            m_controlRect->setSize(100, 100);
            m_controlRect->setBgColor(VFX_COLOR_RED);
            return 250;
        }
        else if (idx == 2)
        {
            m_controlRect->setSize(50, 150);
            m_controlRect->setBgColor(VFX_COLOR_YELLOW);
            return 250;
        }
        else if (idx == 3)
        {
            m_controlRect->setSize(150, 50);
            m_controlRect->setBgColor(VFX_COLOR_PURPLE);
            return 250;
        }
        else if (idx == 4)
        {
            confirm(VFX_WSTR("Can you see the animation?"));
            return -1;
        }
        
        return VTST_RT_END_TESTCASE;
    }
};


VtstTestResultEnum vtst_rt_autoanim(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAutoAnimation);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Auto Animation Test 2 Implementation
 *****************************************************************************/

class VtstRtAutoAnimation2 : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_controlRect;
    VfxU32 m_step;

// Constructor / Destructor
public:
    VtstRtAutoAnimation2() : 
        m_controlRect(NULL),
        m_step(0)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Auto Animation Test"));
    }

    virtual int start()
    {
        // Create a color rectangle
        VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
        m_controlRect->setSize(40, 40);
        m_controlRect->setAnchor(0.5, 0.5);
        m_controlRect->setBgColor(VFX_COLOR_WHITE);
        m_controlRect->setAutoAnimate(VFX_TRUE);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setPos(120, 200);
        frame->setSize(40, 40);
        frame->setAnchor(0.5, 0.5);
        frame->setBorder(VFX_COLOR_RED, 1);

        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setPos(220, 200);
        frame->setSize(40, 40);
        frame->setAnchor(0.5, 0.5);
        frame->setBorder(VFX_COLOR_RED, 1);

        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setPos(220, 300);
        frame->setSize(40, 40);
        frame->setAnchor(0.5, 0.5);
        frame->setBorder(VFX_COLOR_RED, 1);

        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setPos(120, 300);
        frame->setSize(40, 40);
        frame->setAnchor(0.5, 0.5);
        frame->setBorder(VFX_COLOR_RED, 1);
        
        VfxTimer *timer;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->setDuration(250);
        timer->m_signalTick.connect(this, &VtstRtAutoAnimation2::onTimer);
        timer->start();

        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Box path is a box?"));
        return -1;
    }

    void onTimer(VfxTimer *source)
    {
        VFX_DEV_ASSERT(m_controlRect != NULL);
        
        switch (m_step % 4)
        {
            case 0:
                m_controlRect->setPos(120, 200);
                break;

            case 1:
                m_controlRect->setPos(220, 200);
                break;
                
            case 2:
                m_controlRect->setPos(220, 300);
                break;
                
            case 3:
                m_controlRect->setPos(120, 300);
                break;
                
            default:
                VFX_DEV_ASSERT(0);
        }

        m_step++;
    }
};


VtstTestResultEnum vtst_rt_autoanim_2(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAutoAnimation2);
    return VTST_TR_OK;
}

