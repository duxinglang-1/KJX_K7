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
 *  vtst_rt_frame_property_effect.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Programmable Frame Property Effect
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * VtstRtFramePropertyEffect Implementation
 *****************************************************************************/

class VtstRtFramePropertyEffect : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    VfxFrame *m_frame2;
    VfxTimer *m_timer;
    VfxS32 m_tick;


// Constructor / Destructor
public:
    VtstRtFramePropertyEffect() : 
        m_frame1(NULL),
        m_frame2(NULL),
        m_timer(NULL),
        m_tick(0)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Programmable Frame Effect"));
        
        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setRect(VfxRect(50, 150, 30, 30));
        m_frame2->setBgColor(VFX_COLOR_WHITE);
        m_frame2->setBorderWidth(3);
        m_frame2->setBorderColor(VFX_COLOR_YELLOW);
    }

    virtual int start()
    {
        FramePropertyEffectData data;
        data.magicNumber1 = 0x12345678; 
        data.range = 20;
        data.magicNumber2 = 0x87654321; 
        data.borderColor = VFX_COLOR_GREEN;

        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setRect(VfxRect(50, 50, 30, 30));
        m_frame1->setBgColor(VFX_COLOR_RED);

        m_frame2->setPropertyEffectCallback(
            m_frame1, 
            framePropertyEffectCallback, 
            &data,
            sizeof(data));

        VfxPointTimeline *timeline;
        VFX_OBJ_CREATE(timeline, VfxPointTimeline, this);
        timeline->setTarget(m_frame1);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        timeline->setFromValue(VfxPoint(50, 50));
        timeline->setToValue(VfxPoint(150, 50));
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setDurationTime(2000);
        timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        timeline->start();
            
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(1000);
        m_timer->setDuration(1000);
        m_timer->m_signalTick.connect(this, &VtstRtFramePropertyEffect::onTimerTick);
        m_timer->start();
        
        return 1;
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
        {
            invalidate();
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
        {
            m_frame2->setPropertyEffectCallback(
                m_frame1, 
                NULL, 
                NULL,
                0);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            m_frame2->setPropertyEffectCallback(
                m_frame1, 
                NULL, 
                NULL,
                0);
            m_frame2->setPropertyEffectCallback(
                m_frame1, 
                NULL, 
                NULL,
                0);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            FramePropertyEffectData data;
            data.magicNumber1 = 0x12345678; 
            data.range = 20;
            data.magicNumber2 = 0x87654321; 
            data.borderColor = VFX_COLOR_GREEN;

            m_frame2->setPropertyEffectCallback(
                m_frame1, 
                framePropertyEffectCallback, 
                &data,
                sizeof(data));

            m_frame2->setPropertyEffectCallback(
                m_frame1, 
                framePropertyEffectCallback, 
                &data,
                sizeof(data));
            return VFX_TRUE;
        }
    
        return VtstRtScr::onKeyInput(event);
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it correct?"));
        return -1;
    }

    void onTimerTick(VfxTimer *source)
    {
        VFX_UNUSED(source);

        FramePropertyEffectData data;
        data.magicNumber1 = 0x12345678; 
        data.range = 20;
        data.magicNumber2 = 0x87654321; 

        if (m_tick % 2)
        {
            m_frame2->setBgColor(VFX_COLOR_GREY);
            m_frame2->setIsOpaque(VFX_FALSE);
            data.borderColor = VFX_COLOR_WHITE;
        }
        else
        {
            m_frame2->setBgColor(VFX_COLOR_WHITE);
            m_frame2->setIsOpaque(VFX_TRUE);
            data.borderColor = VFX_COLOR_GREY;
        }
        m_tick++;

        // Repeatly setting callback
        m_frame2->setPropertyEffectCallback(
            m_frame1, 
            framePropertyEffectCallback, 
            &data,
            sizeof(data));
    }

private:
    struct FramePropertyEffectData
    {
        VfxU32 magicNumber1;
        VfxS32 range;
        VfxU32 magicNumber2;
        VfxColor borderColor;
    };
    
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
    {
        VFX_DEV_ASSERT(target_frame != NULL);
        VFX_DEV_ASSERT(watch_frame != NULL);
        VFX_DEV_ASSERT(user_data != NULL && user_data_size == sizeof(FramePropertyEffectData));

        FramePropertyEffectData *data = (FramePropertyEffectData *)user_data;
        VfxS32 offsetY = 
            (VfxS32)(vfxSin(VFX_PI * 8 * (watch_frame->pos.x - 50) / 100) * data->range);
        target_frame->pos.x = watch_frame->pos.x;
        target_frame->pos.y = 150 + offsetY;
        target_frame->border_color = data->borderColor;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
};


VtstTestResultEnum vtst_rt_frame_property_effect(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFramePropertyEffect);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__


