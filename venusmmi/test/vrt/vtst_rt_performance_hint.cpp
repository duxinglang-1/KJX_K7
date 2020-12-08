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
 *  vtst_rt_performance_hint.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for performance hint
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include <stdlib.h>
#include "vtst_rt_main.h"
#include "vrt_debug.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"
#include "vfx_transform.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Cache base class Implementation
 *****************************************************************************/

class VtstRtCache : public VtstRtScr
{
public:
    virtual void onDeinit()
    {
        vrt_canvas_dbg_performance_hint(VRT_DBG_PERFORMANCE_HINT_NONE);
        VtstRtScr::onDeinit();
    }

    virtual VfxS32 start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};


/***************************************************************************** 
 * Cache abuse Test Implementation
 *****************************************************************************/

class VtstRtCacheAbuse : public VtstRtCache
{
// Variable
public:

// Constructor / Destructor
public:

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Detect cache abuse"));

        VfxFrame* root;
        VfxFrame* child;
        VfxS32Timeline* timeline;

        const VfxS32 x = 10;
        const VfxS32 offset_y = 20;
        VfxS32 y = 50;
        const VfxS32 w = 50;
        const VfxS32 h = 50;
        const VfxS32 sw = 25;
        const VfxS32 sh = 25;
        const VfxS32 offset_anim = 150;
        const VfxS32 duration = 2500;
        const VfxS32 repeat_duration = 5000;

        /* normal: always use cache */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_GREY);
        root->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(w - sw, h - sh, sw, sw);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(offset_anim);
        timeline->setDuration(duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(root);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        /* abuse: no dirty, no update (it should be free when cache insufficient) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_GREY);
        root->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);

        y += (h + offset_y);

        /* abuse: always update cache */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_GREY);
        root->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);
 
        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(w-sw);
        timeline->setDuration(duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(child);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        /* abuse: sometimes update cache (AP has the knowledge to dynamic enable / disable cache. Can we detect in timeline?) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_GREY);
        root->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);
        
        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(offset_anim);
        timeline->setDuration(duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(root);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(w-sw);
        timeline->setDuration(duration);
        timeline->setRepeatDuration(repeat_duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(child);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        vrt_canvas_dbg_performance_hint(VRT_DBG_PERFORMANCE_HINT_CACHE_ABUSE);
    }
};


/***************************************************************************** 
 * Cache requirement detection Test Implementation
 *****************************************************************************/

class VtstRtCacheRequire : public VtstRtCache
{
// Variable
public:

// Constructor / Destructor
public:

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Detect cache requirement"));

        VfxFrame* root;
        VfxFrame* child;
        VfxFrame* child2;
        VfxS32Timeline* timeline;

        const VfxS32 x = 10;
        const VfxS32 offset_y = 20;
        VfxS32 y = 50;
        const VfxS32 w = 50;
        const VfxS32 h = 50;
        const VfxS32 sw = 25;
        const VfxS32 sh = 25;
        const VfxS32 sw2 = 15;
        const VfxS32 sh2 = 15;
        const VfxS32 offset_anim = 150;
        const VfxS32 duration = 2500;
        const VfxS32 repeat_duration = 5000;

        /* normal: no need cache */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, root);
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        y += (h + offset_y);

        /* normal: use cache */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_GREY);
        root->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sw);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(offset_anim);
        timeline->setDuration(duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(root);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        /* root require cache: root is moving but children are not. (detect root) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sw);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(offset_anim);
        timeline->setDuration(duration);
        timeline->setRepeatDuration(repeat_duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(root);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        /* child require cache: child is moving but child2 is not. (detect child) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sw);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(w-sw);
        timeline->setDuration(duration);
        timeline->setRepeatDuration(repeat_duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(child);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        /* Do not need cache: child2 does not have any children. */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setRect(0, 0, sw, sw);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        VFX_OBJ_CREATE(timeline, VfxS32Timeline, this);
        timeline->setFromValue(0);
        timeline->setToValue(sw-sw2);
        timeline->setDuration(duration);
        timeline->setAutoReversed(VFX_TRUE);
        timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        timeline->setTarget(child2);
        timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        timeline->start();

        y += (h + offset_y);

        vrt_canvas_dbg_performance_hint(VRT_DBG_PERFORMANCE_HINT_CACHE_REQUIRE);
    }

};



/***************************************************************************** 
 * Cache miss detection Test Implementation
 *****************************************************************************/

class VtstRtCacheMiss : public VtstRtCache
{
// Variable
public:

// Constructor / Destructor
public:

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Detect cache miss"));

        
        VfxFrame* root;
        VfxFloatTimeline* timeline;

        const VfxS32 offset_x = 10;
        const VfxS32 offset_y = 10;
        const VfxS32 w = 100;
        const VfxS32 h = 200;
        const VfxS32 duration = 2500;
        int i, j;

        for (i = 0; i < 2; ++i )
        {            
            VfxS32 x = 10;
            VfxS32 y = 50 + i * 210;

            for (j = 0; j < 12; ++j )
            {
                VFX_OBJ_CREATE(root, VfxFrame, this);
                root->setRect(x, y, w, h);
                root->setBgColor(0xFF000000 | ((rand() & 0xFF) << 16) | ((rand() & 0xFF) << 8) | (rand() & 0xFF));
                root->setIsCached(VFX_TRUE);

                VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
                timeline->setFromValue(0.8f);
                timeline->setToValue(1.0f);
                timeline->setDuration(duration);
                timeline->setAutoReversed(VFX_TRUE);
                timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
                timeline->setTarget(root);
                timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
                timeline->start();
                x += offset_x;
                y += offset_y;
            }
        }

        vrt_canvas_dbg_performance_hint(VRT_DBG_PERFORMANCE_HINT_CACHE_MISS);
    }
};


/***************************************************************************** 
 * Temp buffer detection Test Implementation
 *****************************************************************************/

class VtstRtTempBuffer : public VtstRtCache
{
// Variable
public:

// Constructor / Destructor
public:

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Detect temp buffer"));

        VfxFrame* root;
        VfxFrame* child;
        VfxFrame* child2;

        const VfxS32 x = 10;
        const VfxS32 offset_y = 20;
        VfxS32 y = 50;
        const VfxS32 w = 50;
        const VfxS32 h = 50;
        const VfxS32 sw = 25;
        const VfxS32 sh = 25;
        const VfxS32 sw2 = 15;
        const VfxS32 sh2 = 15;
        
        VfxTransform rotate;
        rotate.data.affine.rz = VFX_PI / 20;

        VfxTransform scale;
        scale.data.affine.sx = 1.1f;
        scale.data.affine.sy = 0.9f;


        /* identity */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setAnchor(VfxFPoint(0.5f, 0.5f));
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setAnchor(VfxFPoint(0.5f, 0.5f));
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setAnchor(VfxFPoint(0.5f, 0.5f));
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        y += (h + offset_y);

        /* rotate with cache */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setAnchor(VfxFPoint(0.5f, 0.5f));
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setAnchor(VfxFPoint(0.5f, 0.5f));
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_GREY);
        child->setIsCached(VFX_TRUE);
        child->setTransform(rotate);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setAnchor(VfxFPoint(0.5f, 0.5f));
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        y += (h + offset_y);

        /* rotate without cache (should use temp buffer) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setAnchor(VfxFPoint(0.5f, 0.5f));
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setAnchor(VfxFPoint(0.5f, 0.5f));
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);
        child->setTransform(rotate);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setAnchor(VfxFPoint(0.5f, 0.5f));
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        y += (h + offset_y);

        /* scale without cache (should use temp buffer) */
        VFX_OBJ_CREATE(root, VfxFrame, this);
        root->setAnchor(VfxFPoint(0.5f, 0.5f));
        root->setRect(x, y, w, h);
        root->setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(child, VfxFrame, root);
        child->setAnchor(VfxFPoint(0.5f, 0.5f));
        child->setRect(0, 0, sw, sh);
        child->setBgColor(VFX_COLOR_WHITE);
        child->setTransform(scale);

        VFX_OBJ_CREATE(child2, VfxFrame, child);
        child2->setAnchor(VfxFPoint(0.5f, 0.5f));
        child2->setRect(0, 0, sw2, sh2);
        child2->setBgColor(VRT_COLOR_AQUA);

        vrt_canvas_dbg_performance_hint(VRT_DBG_PERFORMANCE_HINT_BUFFER_USE);
    }

};


VtstTestResultEnum vtst_rt_cache_abuse(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCacheAbuse);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_cache_require(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCacheRequire);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_cache_miss(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCacheMiss);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_buffer_use(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTempBuffer);
    return VTST_TR_OK;
}



#endif // __AFX_RT_TEST__

