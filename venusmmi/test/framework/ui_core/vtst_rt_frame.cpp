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
 *  vtst_rt_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VfxFrame
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
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_weak_ptr.h"
#include "vfx_app_cat_scr.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"

#include "vfx_primitive_filter.h"

/***************************************************************************** 
 * VfxFrame Creation Test Implementation
 *****************************************************************************/

class VtstRtTestFrame : public VfxFrame
{
// Override
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();

        // In onInit(), object parent and frame parent should be exist
        VFX_ASSERT(getParent() != NULL);
        VFX_ASSERT(getParentFrame() != NULL);
    }

    
    virtual void onDeinit()
    {
        // In onDeinit(), object parent and frame parent should be exist
        VFX_ASSERT(getParent() != NULL);
        VFX_ASSERT(getParentFrame() != NULL);
        
        VfxFrame::onDeinit();
    }
};


class VtstRtFrameCreate : public VtstRtScr
{
private:
    VtstRtTestFrame *m_frame0;
    VfxFrameWeakPtr m_frame1;
    VfxFrameWeakPtr m_frame2;
    VfxFrameWeakPtr m_frame3;
    
// Constructor / Destructor
public:
    VtstRtFrameCreate()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Frame Create Test"));
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        switch (idx)
        {
        case 0:
            phase0();
            break;
        case 1:
            phase1();
            break;
        }
        
        return 0;
    }

    void phase0()
    {
        VFX_OBJ_CREATE(m_frame0, VtstRtTestFrame, this);
        m_frame0->setRect(50, 50, 50, 50);
        m_frame0->setBgColor(VFX_COLOR_RED);
        
        VFX_OBJ_CREATE(m_frame1, VtstRtTestFrame, m_frame0);        
        m_frame1->setRect(10, 10, 20, 20);
        m_frame1->setBgColor(VFX_COLOR_YELLOW);

        VFX_OBJ_CREATE(m_frame2, VtstRtTestFrame, m_frame0);        
        m_frame2->setRect(30, 30, 10, 10);
        m_frame2->setBgColor(VFX_COLOR_GREEN);

        VFX_OBJ_CREATE(m_frame3, VfxFrame, this);
        m_frame3->setRect(20, 20, 10, 10);
        m_frame3->setBgColor(VFX_COLOR_BLACK);
        m_frame0->addChildFrame(m_frame3.get());
    }

    void phase1()
    {
        VFX_OBJ_CLOSE(m_frame0);

        check(m_frame0 == NULL, VFX_WSTR("Frame Create #0"));
        check(m_frame1 == NULL, VFX_WSTR("Frame Create #1"));
        check(m_frame2 == NULL, VFX_WSTR("Frame Create #2"));
        check(m_frame3 != NULL, VFX_WSTR("Frame Create #3"));
    }
};


VtstTestResultEnum vtst_rt_frame_create(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameCreate);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VfxFrame Test Implementation
 *****************************************************************************/

class VtstRtFrame : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame[10];

// Constructor / Destructor
public:
    VtstRtFrame()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Create in onInit"));
        
        // Test create order
        VfxS32 i;
        for (i = 0; i < 10; i++)
        {
            VFX_OBJ_CREATE(m_frame[i], VfxFrame, this);
            m_frame[i]->setRect(30 + i * 10, 30 + i * 10, 50, 50);
            m_frame[i]->setBgColor(VFX_COLOR_BLACK);
            m_frame[i]->setBorder(VFX_COLOR_WHITE);
            if (i % 2 == 1)
            {
                m_frame[i]->setHidden(VFX_TRUE);
            }
        }
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        //m_timer->start();
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_frame(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrame);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VfxFrame Test Z Order Implementation
 *****************************************************************************/

class VtstRtFrameZOrder : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frameBase1;
    VfxFrame *m_frameBase2;
    
    VfxFrame *m_frame;
    VfxFloatTimeline *m_timelineZ;
    VfxColorTimeline *m_timelineColor;
    VfxFloatTimeline *m_timelineSx;
    VfxFloatTimeline *m_timelineSy;

// Constructor / Destructor
public:
    VtstRtFrameZOrder() : 
        m_frameBase1(NULL),
        m_frameBase2(NULL),
        m_frame(NULL),
        m_timelineZ(NULL),
        m_timelineColor(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Z Order"));

        // Enable z sort
        setIsZSortChild(VFX_TRUE);
        
        VFX_OBJ_CREATE(m_frameBase1, VfxFrame, this);
        m_frameBase1->setRect(30, 50, 50, 80);
        m_frameBase1->setBgColor(VFX_COLOR_GREY);
        m_frameBase1->setBorder(VFX_COLOR_WHITE);
        m_frameBase1->setOpacity(0.5f);
        m_frameBase1->setPosZ(10.0f);

        VFX_OBJ_CREATE(m_frameBase2, VfxFrame, this);
        m_frameBase2->setRect(100, 60, 40, 64);
        m_frameBase2->setBgColor(VFX_COLOR_BLACK);
        m_frameBase2->setBorder(VFX_COLOR_GREY);
        m_frameBase2->setOpacity(0.4f);
        m_frameBase2->setPosZ(30.0f);
        
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(90, 90, 80, 40);
        m_frame->setBgColor(VFX_COLOR_RED);
        m_frame->setBorder(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(m_timelineZ, VfxFloatTimeline, this);
        m_timelineZ->setTarget(m_frame);
        m_timelineZ->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
        m_timelineZ->setFromValue(0.0f);
        m_timelineZ->setToValue(40.0f);
        m_timelineZ->setDuration(1000);
        m_timelineZ->setAutoReversed(VFX_TRUE);
        m_timelineZ->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        VFX_OBJ_CREATE(m_timelineColor, VfxColorTimeline, this);
        m_timelineColor->setTarget(m_frame);
        m_timelineColor->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
        m_timelineColor->setFromValue(VFX_COLOR_RED);
        m_timelineColor->setToValue(0xff3f0000);
        m_timelineColor->setDuration(1000);
        m_timelineColor->setAutoReversed(VFX_TRUE);
        m_timelineColor->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        m_frame->setAnchor(0.5f, 0.5f);
        m_frame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(m_timelineSx, VfxFloatTimeline, this);
        m_timelineSx->setTarget(m_frame);
        m_timelineSx->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SX);
        m_timelineSx->setFromValue(1.0f);
        m_timelineSx->setToValue(0.5f);
        m_timelineSx->setDuration(1000);
        m_timelineSx->setAutoReversed(VFX_TRUE);
        m_timelineSx->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        
        VFX_OBJ_CREATE(m_timelineSy, VfxFloatTimeline, this);
        m_timelineSy->setTarget(m_frame);
        m_timelineSy->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SY);
        m_timelineSy->setFromValue(1.0f);
        m_timelineSy->setToValue(0.5f);
        m_timelineSy->setDuration(1000);
        m_timelineSy->setAutoReversed(VFX_TRUE);
        m_timelineSy->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    }

    virtual int start()
    {
        m_timelineZ->start();
        m_timelineColor->start();
        m_timelineSx->start();
        m_timelineSy->start();
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_frame_z_order(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameZOrder);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VfxFrame Test Z Order hitTest() Implementation
 *****************************************************************************/

class VtstRtFrameZOrderHitTest : public VtstRtScr
{
private:
    class hitChild : public VfxControl
    {
    // Constructor / Destructor
    public:
        // Constructor
        hitChild() : m_bgColorIdx(-1)
        {
        };

    private:
        VfxColor getNextColor()
        {
            const VfxColor tbl[] = {
                VFX_COLOR_RED,
                VFX_COLOR_GREEN,
                VFX_COLOR_BLUE,
                VFX_COLOR_AQUA,
                VFX_COLOR_FUCHSIA,
                VFX_COLOR_YELLOW
            };
        
            m_bgColorIdx = (m_bgColorIdx+1) % (sizeof(tbl)/sizeof(VfxColor));
            return tbl[m_bgColorIdx];
        }

    protected:
        virtual void onInit(void)
        {
            VfxControl::onInit();
            setBorder(VFX_COLOR_WHITE);
            setBgColor(getNextColor());
        }
        virtual VfxBool onPenInput(VfxPenEvent &event)
        {
            if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
            {
                setBgColor(getNextColor());
                setPosZ(getPosZ() - 1.0f);
                return VFX_TRUE;
            }
            
            return VfxControl::onPenInput(event);
        }

    private:
        VfxS32 m_bgColorIdx;
    };

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Z Order hitTest"));

        // Enable z sort
        setIsZSortChild(VFX_TRUE);

        hitChild *childCtrl;
        
        VFX_OBJ_CREATE(childCtrl, hitChild, this);
        childCtrl->setRect(50, 40, 100, 70);

        VFX_OBJ_CREATE(childCtrl, hitChild, this);
        childCtrl->setRect(40, 50, 70, 100);

        VFX_OBJ_CREATE(childCtrl, hitChild, this);
        childCtrl->setRect(90, 50, 70, 100);

        VFX_OBJ_CREATE(childCtrl, hitChild, this);
        childCtrl->setRect(50, 90, 100, 70);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_frame_z_order_ht(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameZOrderHitTest);
    return VTST_TR_OK;
}

/***************************************************************************** 
 * VfxFrame Test Attach property Implementation
 *****************************************************************************/

class VtstRtFrameAttachProp : public VtstRtScr
{
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Frame Attach prop"));
    }

    virtual int start()
    {
        return -1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if(idx == 0)
        {
            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, this);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(20);

            VfxDarkenFilter *filter;
            VFX_OBJ_CREATE(filter, VfxDarkenFilter, this);

            frame->setPosZ(0.989f);
            frame->setBgColor(VFX_COLOR_RED);
            frame->setOpacity(0.5f);
            frame->setTransform(t);
            frame->setBorderColor(VFX_COLOR_BLUE);
            frame->setBorderWidth(3);
            frame->setFilter(filter);
            frame->setFilterTiming(2.2f);
            frame->setFpeUser0(0.123f);
            frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT);
            frame->setQuality(VFX_RENDER_QUALITY_HIGH);
            frame->setCacheMode(VFX_CACHE_MODE_FORCE);
            frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
            frame->setCullingType(VFX_FRAME_CULLING_TYPE_FRONT);
            frame->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
            frame->setPropertyEffectCallback(this, NULL, NULL, 0);
            frame->alignParent();

            check(frame->getPosZ() == 0.989f, VFX_WSTR("PosZ 0"));
            check(frame->getBgColor() == VfxColor(VFX_COLOR_RED), VFX_WSTR("BgColor 0"));
            check(frame->getOpacity() == 0.5f, VFX_WSTR("Opacity 0"));
            check(frame->getTransform() == t, VFX_WSTR("Transform 0"));
            check(frame->getBorderColor() == VfxColor(VFX_COLOR_BLUE), VFX_WSTR("BorderColor 0"));
            check(frame->getBorderWidth() == 3, VFX_WSTR("BorderWidth 0"));
            check(frame->getFilter() == filter, VFX_WSTR("Filter 0"));
            check(frame->getFilterTiming() == 2.2f, VFX_WSTR("FilterTiming 0"));
            check(frame->getFpeUser0() == 0.123f, VFX_WSTR("FpeUser0 0"));
            check(frame->getContentPlacement() == VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT, VFX_WSTR("ContentPlacement 0"));
            check(frame->getQuality() == VFX_RENDER_QUALITY_HIGH, VFX_WSTR("Quality 0"));
            check(frame->getCacheMode() == VFX_RENDER_QUALITY_HIGH, VFX_WSTR("CacheMode 0"));
            check(frame->getOpaqueMode() == VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE, VFX_WSTR("OpaqueMode 0"));
            check(frame->getCullingType() == VFX_FRAME_CULLING_TYPE_FRONT, VFX_WSTR("CullingType 0"));
            check(frame->getHints() == VFX_FRAME_HINTS_SW_OVERLAY, VFX_WSTR("Hints 0"));

            VFX_OBJ_CLOSE(frame);
            return 0;
        }
        else if(idx == 1)
        {
            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, this);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(20);

            VfxDarkenFilter *filter;
            VFX_OBJ_CREATE(filter, VfxDarkenFilter, this);

            frame->setBgColor(VFX_COLOR_BLUE);
            frame->setOpacity(0.0f);
            frame->setTransform(t);
            frame->setBorderColor(VFX_COLOR_BLUE);
            frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
            frame->setFilter(filter);
            frame->setFilterTiming(1.2f);
            frame->setBorderWidth(3);
            frame->setPosZ(0.989f);
            frame->setCacheMode(VFX_CACHE_MODE_FORCE);
            frame->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
            frame->setFilter(NULL);
            frame->setOpacity(0.5f);
            frame->setFpeUser0(0.123f);
            frame->setPropertyEffectCallback(this, NULL, NULL, 0);
            frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT);
            frame->setQuality(VFX_RENDER_QUALITY_HIGH);
            frame->setFilterTiming(2.2f);
            frame->setBorderWidth(3);
            frame->setBgColor(VFX_COLOR_RED);
            frame->setFilter(filter);
            frame->setCullingType(VFX_FRAME_CULLING_TYPE_FRONT);
            frame->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
            frame->alignParent();

            check(frame->getPosZ() == 0.989f, VFX_WSTR("PosZ 1"));
            check(frame->getBgColor() == VfxColor(VFX_COLOR_RED), VFX_WSTR("BgColor 1"));
            check(frame->getOpacity() == 0.5f, VFX_WSTR("Opacity 1"));
            check(frame->getTransform() == t, VFX_WSTR("Transform 1"));
            check(frame->getBorderColor() == VfxColor(VFX_COLOR_BLUE), VFX_WSTR("BorderColor 1"));
            check(frame->getBorderWidth() == 3, VFX_WSTR("BorderWidth 1"));
            check(frame->getFilter() == filter, VFX_WSTR("Filter 1"));
            check(frame->getFilterTiming() == 2.2f, VFX_WSTR("FilterTiming 1"));
            check(frame->getFpeUser0() == 0.123f, VFX_WSTR("FpeUser0 1"));
            check(frame->getContentPlacement() == VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT, VFX_WSTR("ContentPlacement 1"));
            check(frame->getQuality() == VFX_RENDER_QUALITY_HIGH, VFX_WSTR("Quality 1"));
            check(frame->getCacheMode() == VFX_RENDER_QUALITY_HIGH, VFX_WSTR("CacheMode 1"));
            check(frame->getOpaqueMode() == VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE, VFX_WSTR("OpaqueMode 1"));
            check(frame->getCullingType() == VFX_FRAME_CULLING_TYPE_FRONT, VFX_WSTR("CullingType 1"));
            check(frame->getHints() == VFX_FRAME_HINTS_SW_OVERLAY, VFX_WSTR("Hints 1"));

            VFX_OBJ_CLOSE(frame);
            return 0;
        }
        else if(idx == 2)
        {
            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, this);

            VfxTransform t;
            t.setIdentity();
            t.data.affine.rz = VFX_DEG_TO_RAD(20);

            VfxDarkenFilter *filter;
            VFX_OBJ_CREATE(filter, VfxDarkenFilter, this);

            frame->setPosZ(0.989f);
            frame->setBgColor(VFX_COLOR_RED);
            frame->setOpacity(0.5f);
            frame->setTransform(t);
            frame->setBorderColor(VFX_COLOR_BLUE);
            frame->setBorderWidth(3);
            frame->setFilter(filter);
            frame->setFilterTiming(2.2f);
            frame->setFpeUser0(0.123f);
            frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
            frame->setQuality(VFX_RENDER_QUALITY_HIGH);
            frame->setCacheMode(VFX_CACHE_MODE_FORCE);
            frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
            frame->setCullingType(VFX_FRAME_CULLING_TYPE_FRONT);
            frame->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
            frame->setPropertyEffectCallback(this, NULL, NULL, 0);
            frame->alignParent();

            // reset default
            frame->setPosZ(VRT_FRAME_DEFAULT_POS_Z);
            frame->setBgColor(VRT_FRAME_DEFAULT_BG_COLOR);
            frame->setOpacity(VRT_FRAME_DEFAULT_OPACITY);
            frame->setTransform(VRT_FRAME_DEFAULT_TRANSFORM);
            frame->setBorderColor(VRT_FRAME_DEFAULT_BORDER_COLOR);
            frame->setBorderWidth(VRT_FRAME_DEFAULT_BORDER_WIDTH);
            frame->setFilter(NULL);
            frame->setFilterTiming(0.0f);
            frame->setFpeUser0(0.0f);
            frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
            frame->setQuality(VFX_RENDER_QUALITY_DEFAULT);
            frame->setCacheMode(VFX_CACHE_MODE_AUTO);
            frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_AUTO);
            frame->setCullingType(VFX_FRAME_CULLING_TYPE_NONE);
            frame->setHints(VFX_FRAME_HINTS_DEFAULT);
            frame->setPropertyEffectCallback(NULL, NULL, NULL, 0);
            frame->resetAlignParent();

            check(frame->getPosZ() == VRT_FRAME_DEFAULT_POS_Z, VFX_WSTR("PosZ 2"));
            check(frame->getBgColor() == VfxColor(VRT_FRAME_DEFAULT_BG_COLOR), VFX_WSTR("BgColor 2"));
            check(frame->getOpacity() == VRT_FRAME_DEFAULT_OPACITY, VFX_WSTR("Opacity 2"));
            check(frame->getTransform() == VfxTransform(VRT_FRAME_DEFAULT_TRANSFORM), VFX_WSTR("Transform 2"));
            check(frame->getBorderColor() == VfxColor(VRT_FRAME_DEFAULT_BORDER_COLOR), VFX_WSTR("BorderColor 2"));
            check(frame->getBorderWidth() == VRT_FRAME_DEFAULT_BORDER_WIDTH, VFX_WSTR("BorderWidth 2"));
            check(frame->getFilter() == NULL, VFX_WSTR("Filter 2"));
            check(frame->getFilterTiming() == 0.0f, VFX_WSTR("FilterTiming 2"));
            check(frame->getFpeUser0() == 0.0f, VFX_WSTR("FpeUser0 2"));
            check(frame->getContentPlacement() == VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER, VFX_WSTR("ContentPlacement 2"));
            check(frame->getQuality() == VFX_RENDER_QUALITY_DEFAULT, VFX_WSTR("Quality 2"));
            check(frame->getCacheMode() == VFX_CACHE_MODE_AUTO, VFX_WSTR("CacheMode 2"));
            check(frame->getOpaqueMode() == VFX_FRAME_OPAQUE_MODE_AUTO, VFX_WSTR("OpaqueMode 2"));
            check(frame->getCullingType() == VFX_FRAME_CULLING_TYPE_NONE, VFX_WSTR("CullingType 2"));
            check(frame->getHints() == VFX_FRAME_HINTS_DEFAULT, VFX_WSTR("Hints 2"));

            VFX_OBJ_CLOSE(frame);
            return 0;
        }
        return VTST_RT_END_TESTCASE;
    }
};


VtstTestResultEnum vtst_rt_frame_attach_prop(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameAttachProp);
    return VTST_TR_OK;
}



#endif // __AFX_RT_TEST__

