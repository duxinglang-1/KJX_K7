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
 *  vtst_rt_scrollable.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for scrollable
 *
 * Description:
 * ------------
 *  
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

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vcp_scrollable.h"
#include "vfx_timer.h"
#include "vfx_string.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Scrollable Test Implementation
 *****************************************************************************/

class VtstRtScrollable : public VtstRtScr
{
    class VfxMyControl : public VfxControl
    {
        VfxPoint m_downPos;
    public:
        virtual void onInit()
        {
            VfxControl::onInit();
        }

        VfxBool onPenInput(VfxPenEvent &event)
        {
            VfxPoint pos(event.getRelPos(this));

            if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
            {
                m_downPos = pos;
            }
            else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
            {
                if (VFX_ABS(pos.y - m_downPos.y) > 20)
                {
                    getParentControl()->capture();
                }
            }
            else if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                // Handle Click Item Here
                setBgColor(VRT_COLOR_WHITE);
            }
            return VFX_TRUE;
        }
    };

// Variable
public:
    VcpScrollable *m_body;
    VfxMyControl  *m_testCtl[40];
    VfxTimer      *m_timer;
    int           m_tick;

// Constructor / Destructor
public:
    VtstRtScrollable() : m_body(NULL), m_tick(0) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Scrollable Test"));
        setStatus(VFX_WSTR("Please hit box"));

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(0);
        m_timer->setDuration(300);
        m_timer->m_signalTick.connect(this, &VtstRtScrollable::onTimerTick);

        // scrollable body
        VFX_OBJ_CREATE(m_body, VcpScrollable, this);
        
        m_body->setPos(VfxPoint(10, 100));
        m_body->setBounds(VfxRect(0, 0, 200, 200));
        m_body->setContentSize(VfxSize(200, 4000));
        m_body->setViewRect(VfxRect(0, 0, 200, 200));
        m_body->setBgColor(VFX_COLOR_BLACK);


        VfxMyControl *testCtl = NULL;

        VfxColor colorlst[] = {
            VfxColor(VRT_COLOR_WHITE),
            VfxColor(VRT_COLOR_RED),
            VfxColor(VRT_COLOR_GREEN),
            VfxColor(VRT_COLOR_BLUE),
            VfxColor(VRT_COLOR_AQUA),
            VfxColor(VRT_COLOR_FUCHSIA),
            VfxColor(VRT_COLOR_YELLOW),
            VfxColor(VRT_COLOR_GREY),
            VfxColor(VRT_COLOR_TEAL),
            VfxColor(VRT_COLOR_PURPLE),
            VfxColor(VRT_COLOR_OLIVE),
            VfxColor(VRT_COLOR_SILVER),
        };

        for (int i = 0; i < 40; i++)
        {
            // Create a color rectangle
            VFX_OBJ_CREATE(testCtl, VfxMyControl, m_body);
            testCtl->setPos(VfxPoint(10, i * 100));
            testCtl->setBounds(VfxRect(0, 0, 40, 50));
            testCtl->setBgColor(colorlst[i % (sizeof(colorlst) / sizeof(colorlst[0]))]);

            m_testCtl[i] = NULL;
        }       
    }

    void onTimerTick(VfxTimer *source)
    {
        VfxColor colorlst[] = {
            VfxColor(VRT_COLOR_WHITE),
            VfxColor(VRT_COLOR_RED),
            VfxColor(VRT_COLOR_GREEN),
            VfxColor(VRT_COLOR_BLUE),
            VfxColor(VRT_COLOR_AQUA),
            VfxColor(VRT_COLOR_FUCHSIA),
            VfxColor(VRT_COLOR_YELLOW),
            VfxColor(VRT_COLOR_GREY),
            VfxColor(VRT_COLOR_TEAL),
            VfxColor(VRT_COLOR_PURPLE),
            VfxColor(VRT_COLOR_OLIVE),
            VfxColor(VRT_COLOR_SILVER),
        };

        int i;
        int base = m_tick % 40;
        //int end = (base + 10) % 40;        

        for (i = 0; i < 10; i++)
        {
            int idx = (base + i) % 40;
            
            // Create a color rectangle
            if (m_testCtl[idx] == NULL)
            {      
                VFX_OBJ_CREATE(m_testCtl[idx], VfxMyControl, m_body);
                m_testCtl[idx]->setPos(VfxPoint(10 + 50, idx * 100));
                m_testCtl[idx]->setBounds(VfxRect(0, 0, 40, 50));
                m_testCtl[idx]->setBgColor(colorlst[idx % (sizeof(colorlst) / sizeof(colorlst[0]))]);
            }
        }              

        for (i = 0; i < 30; i++)
        {
            int idx = (base + i + 10) % 40;
            
            // Create a color rectangle
            if (m_testCtl[idx])
            {      
                VFX_OBJ_CLOSE(m_testCtl[idx]);
            }
        }              
    
        m_tick++;
        
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        m_timer->start();
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_scrollable(VfxU32 param)
{
    VTST_START_SCRN(VtstRtScrollable);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

