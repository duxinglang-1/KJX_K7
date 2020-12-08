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
 *  vtst_rt_vfx.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Venus UI Engine
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
#include "vfx_mmi.h"
#include "vrt_debug.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_draw_context.h"
#include "vfx_font_desc.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_animation.h"
#include "vfx_sys_memory.h"
#include "vfx_app_cat_scr.h"
#include "vfx_context.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_input_event.h"
#include "vfx_transform.h"
#include "vfx_auto_animate.h"

#include "gdi_include.h"

extern "C"
{
#include "GlobalConstants.h"
}


/***************************************************************************** 
 * VtstRtVfxResport Implementation
 *****************************************************************************/

class VtstRtVfxReport : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtVfxReport()
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("VFX Report"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Check the report."));
        return -1;
    }

    virtual void onDraw(VfxDrawContext &dc)
    {
        VfxWString str;
        dc.setFont(VFX_FONT_DESC_SMALL);
        dc.drawText(0, 35, VFX_WSTR("Compare with (W09BW1028)"));
        dc.drawText(0, 55, str.format("VfxBase: %d (1)", sizeof(VfxBase)));
        dc.drawText(0, 70, str.format("VfxObject: %d (32)", sizeof(VfxObject)));
        dc.drawText(0, 85, str.format("VfxFrame: %d (244)", sizeof(VfxFrame)));
        dc.drawText(0, 100, str.format("VfxControl: %d (248)", sizeof(VfxControl)));
        dc.drawText(0, 115, str.format("VfxBaseTimeline: %d (104)", sizeof(VfxBaseTimeline)));
        dc.drawText(0, 135, str.format("VRT Frame: %d (244)", vrt_dbg_get_handle_struct_size(VRT_DBG_HANDLE_TYPE_FRAME)));
        dc.drawText(0, 150, str.format("VRT Timeline: %d (144)", vrt_dbg_get_handle_struct_size(VRT_DBG_HANDLE_TYPE_TIMELINE)));
    }
};


VtstTestResultEnum vtst_rt_vfx_report(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtVfxReport);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VtstRtAllocate Implementation
 *****************************************************************************/

class VtstRtAllocate : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtAllocate()
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Test Memory (Please Wait...)"));
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch(idx)
        {
            case 0:
                {
                    void *ptr;
                    VfxU32 size = 1;
                    VfxS32 i;
                    for (i = 0; i < 12; i++)
                    {
                        VFX_ALLOC_MEM(ptr, size, this);
                        VFX_FREE_MEM(ptr);

                        VFX_ALLOC_MEM(ptr, size + 1, this);
                        VFX_FREE_MEM(ptr);

                        size *= 2;
                    }
                    break;
                }
            case 1:
                {
                    U8 *ptr;                   
                    VFX_ALLOC_MEM_EX(ptr, 10 * 10 * 2, VFX_SYS_MEM_ALLOC_FLAG_FB, this);

                    gdi_handle handle;
                    gdi_layer_create_cf_using_outside_memory(
                        GDI_COLOR_FORMAT_16, 
                        0, 
                        0,
                        10, 
                        10, 
                        &handle,
                        ptr, 
                        10 * 10 * 2);
                    gdi_layer_free(handle);
                    VFX_FREE_MEM(ptr);
                    break;
                }
        };        
        return 0;
    }
};


VtstTestResultEnum vtst_rt_allocate(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAllocate);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VtstRtVfx Implementation
 *****************************************************************************/

class VtstRtVfx : public VtstRtScr
{
    enum
    {
        CHILD_FRAMEC_CNT = 50,
        ALLOC_TEST_TIMES = 40
    };

// Variable
public:
    VfxFrame   *m_frame;

// Constructor / Destructor
public:
    VtstRtVfx() : m_frame(NULL)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("VFX Test (Please Wait...)"));
    }

    VfxU32 getMemUsedSize() const
    {
        vfx_sys_mem_pool_status_struct memPoolStatistics;
        vrt_allocator_handle allocator = getContext()->getAllocator();
        vfx_sys_mem_pool_allocator_get_status(allocator, &memPoolStatistics);
        return memPoolStatistics.used_size;
    }
    
    virtual int start()
    {
        setTitle(VFX_WSTR("Frame memory leak test"));

        VfxContext *context = VtstRtScr::getContext();
        check(context != NULL, VFX_WSTR("Check context"));
        
        // The memory size without canvas usage
        leaveCanvas();
        VfxU32 memSize0 = getMemUsedSize();
        entryCanvas(context);

        // Create a root frame 
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(VfxRect(50, 60, 70, 80));
        m_frame->setBgColor(VFX_COLOR_YELLOW);

        // Create child frames
        VfxS32 i;
        for (i = 0; i < CHILD_FRAMEC_CNT; i++)
        {
            VfxFrame *childFrame;
            VFX_OBJ_CREATE(childFrame, VfxFrame, m_frame);
            childFrame->setRect(VfxRect(i, i, 50, 60));
            childFrame->setBgColor(VFX_COLOR_RED);
        }

        // The memory size before commit these frames
        VfxU32 memSize1 = getMemUsedSize();
        check(memSize1 > memSize0, VFX_WSTR("Check context memory size #1"));

        // Commit to Canvas
        vfx_mmi_check_update();

        // The memory size after commit
        VfxU32 memSize2 = getMemUsedSize();
        check(memSize2 > memSize1, VFX_WSTR("Check context memory size #2"));

        // Remove all frames
        VFX_OBJ_CLOSE(m_frame);

        // The memory size after close (all VFX object memory should be freed)
        VfxU32 memSize3 = getMemUsedSize();
        check(memSize3 < memSize2, VFX_WSTR("Check context memory size #3"));

        // Leave canvas to free all canvas memory
        leaveCanvas();

        // The memory size should be return
        VfxU32 memSize4 = getMemUsedSize();
        check(memSize4 == memSize0, VFX_WSTR("Check context memory size #4"));

        // Re-entry the canvas
        entryCanvas(context);

        // Test many times create and close objects
        VfxS32 j;
        for (j = 0; j < ALLOC_TEST_TIMES; j++)
        {
            VFX_OBJ_CREATE(m_frame, VfxFrame, this);
            m_frame->setRect(VfxRect(50, 60, 70, 80));
            m_frame->setBgColor(VFX_COLOR_YELLOW);

            for (i = 0; i < CHILD_FRAMEC_CNT; i++)
            {
                VfxFrame *childFrame;
                VFX_OBJ_CREATE(childFrame, VfxFrame, m_frame);
                childFrame->setRect(VfxRect(i, i, 50, 60));
                childFrame->setBgColor(VFX_COLOR_RED);
            }

            VFX_OBJ_CLOSE(m_frame);
        }
        
        return 0;
    }
};


VtstTestResultEnum vtst_rt_vfx(VfxU32 param)
{
    VTST_START_SCRN(VtstRtVfx);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VtstRtFirstFrame Implementation
 *****************************************************************************/

class VtstRtFirstFrame : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    
    VfxFrame *m_frameBox1;
    VfxFrame *m_frameBox2;
    
// Constructor / Destructor
public:
    VtstRtFirstFrame() : 
        m_frame1(NULL),
        m_frameBox1(NULL),
        m_frameBox2(NULL)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Renderer Test"));
        
        VFX_OBJ_CREATE(m_frameBox1, VfxFrame, this);
        m_frameBox1->setRect(10, 50, 40, 40);
        m_frameBox1->setBorder(VFX_COLOR_RED, 1);

        VFX_OBJ_CREATE(m_frameBox2, VfxFrame, this);
        m_frameBox2->setRect(150, 200, 40, 40);
        m_frameBox2->setBorder(VFX_COLOR_RED, 1);
    }

    virtual int start()
    {
        setTitle(VFX_WSTR("Press UP to test"));
        return 1;
    }

    VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == KEY_EVENT_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                VFX_OBJ_CLOSE(m_frame1);
                
                VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
                m_frame1->setRect(10, 50, 40, 40);
                m_frame1->setBgColor(VFX_COLOR_YELLOW);
                m_frame1->setAutoAnimate(VFX_TRUE);
                m_frame1->setIsCached(VFX_TRUE);

                VfxS32 i;
                for (i = 0; i < 100; i++)
                {
                    VfxTransform t;
                    t.data.affine.rz = (VfxFloat)i * 5 + 5;
                    
                    VfxFrame *subFrame;
                    VFX_OBJ_CREATE(subFrame, VfxFrame, m_frame1);
                    subFrame->setRect(0, 0, 40, 40);
                    subFrame->setTransform(t);
                    subFrame->setBgColor(VfxColor(0x1f00ff00));
                }

                VfxAutoAnimate::initAnimateBegin();
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(3000);
                m_frame1->setPos(150, 200);
                VfxAutoAnimate::commit();
                VfxAutoAnimate::initAnimateEnd();                
            }
        }
        
        return VtstRtScr::onKeyInput(event);
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Animation OK?"));
        return -1;
    }    
};


VtstTestResultEnum vtst_rt_first_frame(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFirstFrame);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

