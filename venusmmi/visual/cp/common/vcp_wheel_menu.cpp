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
 *  vcp_wheel_menu.cpp
 *
 * Project:
 * --------
 *  A basic menu framework for venus wheel menu
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
 * removed!
 * removed!
 * removed!
 *
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
#include "vcp_wheel_menu.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include <string.h>
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vrt_canvas.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_auto_animate.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"

#ifdef __MTK_TARGET__
#ifdef __VENUS_SWLA_DBG_ON__
#define __MAUI_SOFTWARE_LA__
#endif
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C" 
{
#include "SST_sla.h"
}
#endif

#define TRACE(a) VFX_TRACE a
// #define TRACE(a)

// This flag indicates this cell is removed. So FPE don't need to render it.
#define CELL_FLAG_DUMMY         1

struct VcpWheelMenuCellHeader
{
    VfxU32 flag;
    VfxS32 cell;
    VfxS32 subCell;
    VfxS32 indexOffset;
    VfxU32 indexOffsetTick;
    VcpWheelMenuState state;
};

#define CELL_HEADER_SIZE sizeof(VcpWheelMenuCellHeader)
/***************************************************************************** 
 * Class VcpWheelMenuCache
 *****************************************************************************/

VcpWheelMenuCache::VcpWheelMenuCache() : 
    m_itemCount(0), 
    m_itemTotalCount(VCP_MENUCACHE_ADDITION),
    m_items(NULL),
    m_menu(NULL)
{
}

VcpWheelMenuCache::~VcpWheelMenuCache()
{
    VFX_DEV_ASSERT(m_itemTotalCount == 0);
    VFX_DEV_ASSERT(m_itemCount == 0);
    VFX_DEV_ASSERT(m_items == NULL);
}

void VcpWheelMenuCache::init(VcpWheelMenu* parent)
{
    VFX_DEV_ASSERT(m_menu == NULL);
    m_menu = parent;
   
    VFX_ALLOC_MEM(m_items, m_itemTotalCount * sizeof(ItemPtr), m_menu);
    memset(m_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
}

void VcpWheelMenuCache::deinit()
{
    VFX_DEV_ASSERT(m_itemCount == 0);
    VFX_DEV_ASSERT(m_menu);

    VFX_FREE_MEM(m_items);

    m_menu = NULL;
    m_items = NULL;
    m_itemCount = 0;
    m_itemTotalCount = 0;
}

VfxBool VcpWheelMenuCache::isInCache(Key p)
{
    if (!p.isValid())
        return VFX_FALSE;

    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
        return VFX_TRUE;
    
    return VFX_FALSE;
}

VfxFrame* VcpWheelMenuCache::getItem(Key p)
{
    if (!p.isValid())
        return NULL;
    
    VfxS32 idx = bisect_left(p);
    if (idx >= m_itemCount) // cannot find
        return NULL;

    if (m_items[idx]->key != p)
        return NULL;

    return m_items[idx]->ptr.get();
}

void VcpWheelMenuCache::setItem(Key p, VfxFrame* frame)
{
    if (!p.isValid())
    {
        VFX_ASSERT(0);
        return;
    }
    
    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        m_items[idx]->ptr = frame;
    }
    else
    {
        VFX_DEV_ASSERT(idx <= m_itemCount);

        if (m_itemCount == m_itemTotalCount)
        {
            // the space is not enough
            ItemPtr *new_items;

            m_itemTotalCount += VCP_MENUCACHE_ADDITION;

            //VFX_NEW_ARRAY(new_items, ItemPtr, m_itemTotalCount);
            VFX_ALLOC_MEM(new_items, m_itemTotalCount * sizeof(ItemPtr), m_menu);

            memset(new_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
            memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
            
            VFX_FREE_MEM(m_items);

            m_items = new_items;
        }
    
        VFX_DEV_ASSERT(m_itemTotalCount > m_itemCount);

        m_itemCount++;
        for (VfxS32 i = m_itemCount - 1; i > idx; i--)
        {
            m_items[i] = m_items[i - 1];
        }
        VFX_ALLOC_NEW(m_items[idx], Item, m_menu);
        m_items[idx]->key = p;
        m_items[idx]->ptr = frame;
        m_items[idx]->timelinePtr = NULL;
    }
}

void VcpWheelMenuCache::setItemTimeline(Key p, VfxFloatTimeline *timeline)
{
    if (!p.isValid())
    {
        return;
    }
    
    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        m_items[idx]->timelinePtr = timeline;
    }
}


VfxFloatTimeline* VcpWheelMenuCache::getItemTimeline(Key p)
{
    if (!p.isValid())
    {
        return VFX_FALSE;
    }
    
    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        return m_items[idx]->timelinePtr.get();
    }
    return NULL;
}

void VcpWheelMenuCache::closeItem(Key p)
{
    VFX_DEV_ASSERT(m_menu);
    VfxFrame* frame = getItem(p);
    removeItem(p);
    if (frame)
    {
        m_menu->closeCell(p.cell, p.subCell, frame);
    }
}

void VcpWheelMenuCache::removeItem(Key p)
{
    if (!p.isValid())
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    if (m_itemCount == 0)
    {
        // nothing can remove
        return;
    }

    VfxS32 idx = bisect_left(p);

    if (idx >= m_itemCount || m_items[idx]->key != p)
    {
        // Cannot found item
        return;
    }

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        VFX_DELETE(m_items[idx]);
        for (VfxS32 i = idx; i < m_itemCount - 1; i++)
        {
            m_items[i] = m_items[i + 1];
        }
        m_itemCount--;
    }

    // we can reduce space
    if (m_itemTotalCount - m_itemCount >= 2 * VCP_MENUCACHE_ADDITION)
    {
        // the space is not enough

        VfxS32 newTotal = VFX_MAX(m_itemCount, VCP_MENUCACHE_ADDITION);

        newTotal = VCP_MENUCACHE_ADDITION * ((newTotal + VCP_MENUCACHE_ADDITION - 1) / VCP_MENUCACHE_ADDITION);

        ItemPtr *new_items;
        //VFX_NEW_ARRAY(new_items, ItemPtr, newTotal);
        VFX_ALLOC_MEM(new_items, newTotal * sizeof(ItemPtr), m_menu);
        memset(new_items, 0, sizeof(ItemPtr) * newTotal);

        memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
        m_itemTotalCount = newTotal;
        //VFX_DELETE_ARRAY(m_items);
        VFX_FREE_MEM(m_items);
        m_items = new_items;

    }
}

void VcpWheelMenuCache::clear()
{
    for (VfxS32 i = m_itemCount - 1; i >= 0; i--)
    {
        Key p = m_items[i]->key;            

        m_menu->closeCell(p.cell, p.subCell, m_items[i]->ptr.get());
        VFX_DELETE(m_items[i]);

        m_itemCount--;
    }
    VFX_DEV_ASSERT(m_itemCount == 0);
}

VfxS32 VcpWheelMenuCache::bisect_left(Key key)
{
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (m_items[mid]->key < key) 
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

/***************************************************************************** 
 * Class VcpWheelMenu
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VcpWheelMenu", VcpWheelMenu, VfxControl);

VcpWheelMenu::VcpWheelMenu() : 
    m_subCellCount(1),
    m_focus(-1),
    m_firstVisibleItem(0), 
    m_lastVisibleItem(0),
    m_defaultAnimTime(VFX_TIMELINE_DEFAULT_DUR_TIME),
    m_maxMoveOffset(0),
    m_isToSendWarning(VFX_FALSE),
    m_isToSendError(VFX_FALSE),
	m_isScrolling(VFX_FALSE),
    m_state(VCP_WHEEL_MENU_NORMAL_STATE),
    m_changeStateTimer(NULL),
    m_isSliding(VFX_FALSE)
{
}

VfxS32 VcpWheelMenu::getSubCellCount()
{
    return m_subCellCount;
}

void VcpWheelMenu::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh1", SA_start);
#endif
    Super::onInit();

    // save this
    m_signature = (VfxU32)getObjHandle();

    m_cache.init(this);

    m_signalBoundsChanged.connect(this, &Self::onViewBoundsChanged);
    registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);

	// Tracker is a invisible object for FPE
    VFX_OBJ_CREATE(m_tracker, VfxFrame, this);
    m_tracker->setOpacity(0);
    m_tracker->setAutoAnimate(VFX_TRUE);
    m_tracker->setFilterTiming(0.0f);

	// Create the monitor timeline
    VFX_OBJ_CREATE(m_monitorTl, VfxFloatTimeline, this);

	// Create the timer to detect scrolling state
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &Self::onTimerTick);

    // Create the timer to detect scrolling state
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
    VFX_OBJ_CREATE(m_changeStateTimer, VfxTimer, this);
    m_changeStateTimer->m_signalTick.connect(this, &Self::onEndofChangeTimer);
#endif

    // Get the sub cell count
    m_subCellCount = getSubCellCount();

    checkUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh1", SA_stop);
#endif
}

void VcpWheelMenu::onDeinit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh2", SA_start);
#endif
    m_cache.clear();
    m_cache.deinit();
    Super::onDeinit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh2", SA_stop);
#endif
}

VfxFrame* VcpWheelMenu::getCellIfPresent(VfxS32 cell, VfxS32 subcell)
{
    // if dummy cell, just return NULL
    const VcpWheelMenuCellHeader* header = getCellHeader(Key(cell, subcell));
    if (header && (header->flag & CELL_FLAG_DUMMY))
    {
        return NULL;
    }
    return m_cache.getItem(Key(cell, subcell));
}

vrt_render_dirty_type_enum VcpWheelMenu::dummyFramePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    return VRT_RENDER_DIRTY_TYPE_NONE;
}

vrt_render_dirty_type_enum VcpWheelMenu::framePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(watch_frame != NULL);

    VcpWheelMenuFrameEffectCBFuncPtr cb = (VcpWheelMenuFrameEffectCBFuncPtr)watch_frame->pos.x;

    VcpWheelMenuCellHeader* header = (VcpWheelMenuCellHeader*)user_data;
    VfxFloat fPos = watch_frame->filter_timing;
    VfxFloat cellRelPos = header->cell - fPos;

    // if index offset is enabled,
    // we need to offset cell relative pos according to tick.
    if (header->indexOffset != 0)
    {
        kal_uint32 tick;
        kal_get_time(&tick);

        VfxU32 animTick = kal_milli_secs_to_ticks(VFX_TIMELINE_DEFAULT_DUR_TIME);

        if (tick >= header->indexOffsetTick && tick < header->indexOffsetTick + animTick)
        {
            VfxFloat per = 1.0f - (tick - header->indexOffsetTick) / VfxFloat(animTick);
            cellRelPos += header->indexOffset * per;
        }
        else
        {
            // Turn off index offset to speed up performance
            header->indexOffset = 0;
        }
    }

    return (*cb)(
        header->cell,
        header->subCell,
        cellRelPos,
        target_frame, 
        fPos, 
        watch_frame->pos.y,
        watch_frame->bounds,
        user_data_size > CELL_HEADER_SIZE ? (VfxU8*)user_data + CELL_HEADER_SIZE : NULL,
        user_data_size > CELL_HEADER_SIZE ? user_data_size - CELL_HEADER_SIZE : 0,
        header->state,
        target_frame->fpe_user_0
    );
}

void VcpWheelMenu::update()
{
    checkUpdate();
}

void VcpWheelMenu::cleanAllCell()
{
    // Clear cache and sub cell item
    m_cache.clear();
    
    
    m_focus             = -1;
    m_firstVisibleItem  = 0;
    m_lastVisibleItem   = 0;

    checkUpdate();
}

VfxFloat VcpWheelMenu::getScrollIndex()
{
    return m_tracker->getFilterTiming();
}


void VcpWheelMenu::onTimerTick(VfxTimer *source)
{
	if (m_isScrolling)
	{
		m_isScrolling = VFX_FALSE;
		m_endScrolling.postEmit(this);
	}
    m_isSliding = VFX_FALSE;
}

void VcpWheelMenu::setScrollIndex(VfxFloat perc, VfxMsec animTime)
{
    VFX_TRACE(("setScrollIndex: %f %d\n", perc, animTime));
    
	// Stop the timer fisrt
	m_timer->stop();

	// detect whether we need to fire scrolling event
	if (!m_isScrolling)
	{
		m_isScrolling = VFX_TRUE;
		m_beginScrolling.postEmit(this);
	}

	// If the timer value is -1, means use default value
    if (animTime == -1)
        animTime = m_defaultAnimTime;

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(animTime <= 0);
    VfxAutoAnimate::setTimingFunc(getMoveTimeFunction());
    VfxAutoAnimate::setDuration(animTime);
    m_tracker->setFilterTiming(perc);
    VfxAutoAnimate::commit();

    if (animTime <= 0)
    {
        // becasue when animTime <= 0, 
        // we can directly use vfx value to gain better performance
        updateContent(VFX_TRUE);
    }
    else
    {
        updateContent(VFX_FALSE);
    }

    m_timer->setStartDelay(animTime);
	m_timer->start();
}

struct VcpWheelMenuMonitorData
{
    VfxS32 cstart;
    VfxS32 cend;
    VfxS32 wstart;
    VfxS32 wend;
    VfxS32 ahead;
    VfxS32 behind;
    VfxS32 count;
    void* self;
    VfxU32 signature;
};

void VcpWheelMenu::emitContentWarning(void *arg)
{
    VfxObject *obj = VfxObject::handleToObject((VfxObjHandle)arg);

    if (obj)
    {
        VcpWheelMenu *menu = VFX_OBJ_DYNAMIC_CAST(obj, VcpWheelMenu);

        //TODO: threading issue here
        if (menu == NULL || !menu->isValid() || !menu->isKindOf(VFX_OBJ_CLASS_INFO(VcpWheelMenu)))
        return;

        menu->updateContent(VFX_FALSE);
    }
}

void VcpWheelMenu::emitContentError(void *arg)
{
    VfxObject *obj = VfxObject::handleToObject((VfxObjHandle)arg);

    if (obj)
    {
        VcpWheelMenu *menu = VFX_OBJ_DYNAMIC_CAST(obj, VcpWheelMenu);

        //TODO: threading issue here
        if (menu == NULL || !menu->isValid() || !menu->isKindOf(VFX_OBJ_CLASS_INFO(VcpWheelMenu)))
        return;

        menu->updateContent(VFX_FALSE);
    }
}

VfxTimelineInterpolationRetEnum VcpWheelMenu::indexMonitorFuncCallback(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
)
{
    vrt_float now, begin, end;
    VcpWheelMenuMonitorData *mdata = (VcpWheelMenuMonitorData*)data;

    VfxObject *obj = VfxObject::handleToObject((VfxObjHandle)mdata->signature);
    
    if (obj == NULL)
    {
        return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
    }
   
    VcpWheelMenu *wheelMenu = (VcpWheelMenu*)mdata->self;
    
    VFX_UNUSED(fromValue);
    VFX_UNUSED(toValue);
    VFX_UNUSED(typeId);
    VFX_UNUSED(t);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    now = *((vrt_float*)output);

    begin = now - mdata->ahead;
    if (begin < 0)
        begin = 0;

    end = now + mdata->behind + 1;
    if (end > mdata->count)
        end = VfxFloat(mdata->count);

    // check if the view port is outside the warning content rect

    if (end > mdata->cend || begin < mdata->cstart)
    {
        // emit stop signal
        if (wheelMenu->m_isToSendError)
        {
            vrt_invoke_mmi_rpc(emitContentError, (void*)mdata->signature);
        }                

        wheelMenu->m_isToSendError = VRT_FALSE;
        return VFX_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE;
    }
    else if (end > mdata->wend || begin < mdata->wstart)
    {
         // emit stop signal
        if (wheelMenu->m_isToSendWarning)
        {
            vrt_invoke_mmi_rpc(emitContentWarning, (void*)mdata->signature);
        }                

        wheelMenu->m_isToSendWarning = VRT_FALSE;
    }
    return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
}

void VcpWheelMenu::updateContent(bool force)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh4", SA_start);
#endif
    // Backup
    VfxS32 preFirstVisibleItem  = m_firstVisibleItem;
    VfxS32 preLastVisibleItem   = m_lastVisibleItem;

    VfxFloat index;
    if (force)
    {
        index = m_tracker->getFilterTiming();
    }
    else
    {   
        index = m_tracker->forceGetFilterTiming();
    }

    // change region
    m_firstVisibleItem = VfxS32(index) - getAheadCount();
    
    if (m_firstVisibleItem < 0)
    {
        m_firstVisibleItem = 0;
    }

    m_lastVisibleItem = VfxS32(index + 0.999f) + getBehindCount() + 1;
    if (m_lastVisibleItem > getCount())
    {
        m_lastVisibleItem = getCount();
    }

    onBeforeUpdateCell();

    int i = 0;
    for (i = preFirstVisibleItem; i < preLastVisibleItem; i++)
    {
        if (i >= m_firstVisibleItem && i < m_lastVisibleItem)
            continue;
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Wh5", SA_start);
    #endif
        closeCell(i);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("Wh5", SA_stop);
    #endif
    }        

    for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    {
        for (VfxS32 j = 0; j < m_subCellCount; j++)
        {
            VfxFrame* item = m_cache.getItem(Key(i, j));

            // // create sub cell if need 
            if (item == NULL)
            {
                // Set for adding a new entry
                Key key(i, j);

                m_cache.setItem(key, NULL);  
            #ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("Wh6", SA_start);
            #endif
                item = createCell(i, j);
            #ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("Wh6", SA_stop);
            #endif
                m_cache.setItem(key, item);

                VcpWheelMenuCellHeader header = {0};
                header.cell = i;
                header.subCell = j;

                setCellHeader(Key(i, j), &header);
            }
            const VcpWheelMenuCellHeader* header = getCellHeader(Key(i, j));
            if (header && (header->flag & CELL_FLAG_DUMMY))
            {
                // dummy cell won't call onUpdate
                continue;
            }
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("Wh7", SA_start);
        #endif
            onUpdateCell(i, j, item);
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("Wh7", SA_stop);
        #endif
        }
    }

    onAfterUpdateCell();

    // Start Monitor
    VcpWheelMenuMonitorData data;
    data.cstart = m_firstVisibleItem;
    data.cend = m_lastVisibleItem;
    data.wstart = m_firstVisibleItem;
    data.wend = m_lastVisibleItem;
    data.ahead = getAheadCount();
    data.behind = getBehindCount();
    data.count = getCount();

    data.self = this;
    data.signature = m_signature;

    // reset m_isToSendError , m_isToSendWarning
    m_isToSendError = VFX_TRUE;
    m_isToSendWarning = VFX_TRUE;

    // Set monitor
    m_monitorTl->setTarget(m_tracker);
    m_monitorTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_monitorTl->setCustomInterpolateFunc(indexMonitorFuncCallback, &data, sizeof(VcpWheelMenuMonitorData));
    m_monitorTl->setDurationTime(0xFFFFFF);
    m_monitorTl->setRepeatDuration(0xFFFFFF);
    m_monitorTl->start();

    VFX_TRACE(("updateContent: %f %d %d %d\n", index, m_focus, m_firstVisibleItem, m_lastVisibleItem));

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh4", SA_stop);
#endif
}

void VcpWheelMenu::setFocus(VfxS32 focus, VfxMsec animTime)
{
    VfxS32 preFocus = m_focus;
    
    if (focus < 0)
    {
        focus = 0;
    }

    if (focus >= getCount())
    {
        focus = getCount() - 1;
    }

    // Update property
    m_focus = focus;

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_tracker->setPos(VfxPoint(m_tracker->getPos().x, m_focus));
    VfxAutoAnimate::commit(); 

    setScrollIndex(VfxFloat(focus), animTime);
    
    if (preFocus != m_focus)
    {
        onFocusIndexChange(m_focus, preFocus);
    }
}

void VcpWheelMenu::onViewBoundsChanged(VfxFrame *view, const VfxRect &old)
{
    checkUpdate();

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_tracker->setBounds(getBounds());
    VfxAutoAnimate::commit(); 
}

const VcpWheelMenuCellHeader* VcpWheelMenu::getCellHeader(Key key)
{
    VfxFrame* frame = m_cache.getItem(key);
    if (frame == NULL)
        return NULL;

    return (VcpWheelMenuCellHeader*) frame->getPropertyEffectCallbackUserDataPtr();
}

void VcpWheelMenu::setCellHeader(Key key, VcpWheelMenuCellHeader* header)
{
    VfxFrame* frame = m_cache.getItem(key);
    if (frame == NULL)
        return;

    VFX_DEV_ASSERT(header);

    VfxU32 bufferSize = frame->getPropertyEffectCallbackUserDataSize();

    if (bufferSize == 0)
    {
        frame->setPropertyEffectCallback(
            m_tracker,
            &VcpWheelMenu::framePropertyEffectCallback, 
            header,
            CELL_HEADER_SIZE,
            VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
    }
    else if (bufferSize >= CELL_HEADER_SIZE)
    {
        VfxU8* pBuffer;
        VFX_ALLOC_MEM(pBuffer, bufferSize, this);
        // Copy back the userdata
        memcpy(pBuffer, frame->getPropertyEffectCallbackUserDataPtr(), bufferSize);
        // Overwrite the header
        memcpy(pBuffer, header, CELL_HEADER_SIZE);

        frame->setPropertyEffectCallback(
            m_tracker,
            &VcpWheelMenu::framePropertyEffectCallback, 
            pBuffer,
            bufferSize,
            VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

        VFX_FREE_MEM(pBuffer);
    }
    else
    {
        // It is impossible, else our code logic is wrong.
        VFX_DEV_ASSERT(0);
    }

}

void VcpWheelMenu::setCellUserData(VfxS32 cell, VfxS32 subCell, VfxFrame* frame, void* data, VfxU32 dataSize)
{
    VFX_DEV_ASSERT(frame);

    // If the frame is not existed, just exit
    if (!frame)
    {
        return;
    }

    VfxU32 bufferSize = CELL_HEADER_SIZE + dataSize;
    VfxU8* pBuffer;
    VFX_ALLOC_MEM(pBuffer, bufferSize, this);
    VcpWheelMenuCellHeader* header = (VcpWheelMenuCellHeader*) pBuffer;

    if (frame->getPropertyEffectCallbackUserDataSize() != 0)
    {
        VFX_DEV_ASSERT(frame->getPropertyEffectCallbackUserDataPtr());
        VFX_DEV_ASSERT(frame->getPropertyEffectCallbackUserDataSize() >= CELL_HEADER_SIZE);

        // Copy back the original header
        memcpy(header, frame->getPropertyEffectCallbackUserDataPtr(), CELL_HEADER_SIZE);
    }
    else
    {
        header->cell = cell;
        header->subCell = subCell;
        header->flag = 0;
        header->indexOffset = 0;
        header->indexOffsetTick = 0;
    }

    Key key(cell, subCell);

    if (m_cache.getItem(key))
    {
        VFX_DEV_ASSERT(m_cache.getItem(key) == frame);
    }

    // Copy user data
    memcpy(pBuffer + CELL_HEADER_SIZE, data, dataSize);

    frame->setPropertyEffectCallback(
        m_tracker,
        &VcpWheelMenu::framePropertyEffectCallback, 
        pBuffer,
        bufferSize,
        VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

    VFX_FREE_MEM(pBuffer);
}

void VcpWheelMenu::setCellUserData(VfxS32 index, void* data, VfxU32 dataSize)
{
    for (VfxS32 i = 0; i < m_subCellCount; i++)
    {
        Key key(index, i);
        VfxFrame* frame = m_cache.getItem(key);
        setCellUserData(index, i, frame, data, dataSize);
    }
}

void VcpWheelMenu::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh3", SA_start);
#endif
    Super::onUpdate();

    VfxS32 preCellCount = m_subCellCount;
    m_subCellCount = getSubCellCount();
    VFX_ASSERT(m_subCellCount >= 1);

    // check whether need to remove extra sub cell
    if (preCellCount > m_subCellCount)
    {
        for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
        {
            for (VfxS32 j = m_subCellCount; j < preCellCount; j++)
            {
                m_cache.closeItem(Key(i, j));
            }
        }
    }

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    // Assign user cb into X value.
    VcpWheelMenuFrameEffectCBFuncPtr cb = getFrameEffectCB();
    
    m_tracker->setPos(VfxPoint(VfxS32(cb), m_focus));

    VfxAutoAnimate::commit(); 

    // adjust focus index
    if (getCount() > 0)
    {
        if (m_focus < 0)
        {
            m_focus = 0;
        }

        if (m_focus >= getCount())
        {
            m_focus = getCount() - 1;
        }

        setScrollIndex(VfxFloat(m_focus), m_defaultAnimTime);
    }
    else
    {
        m_focus             = -1;
        m_firstVisibleItem  = 0;
        m_lastVisibleItem   = 0;
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("Wh3", SA_stop);
#endif
}

VfxBool VcpWheelMenu::onKeyInput(VfxKeyEvent &event)
{
    return Super::onKeyInput(event);
}

VfxS32 VcpWheelMenu::getFirstVisibleIndex()
{
    return m_firstVisibleItem;
}

VfxS32 VcpWheelMenu::getLastVisibleIndex()
{
    return m_lastVisibleItem;
}


void VcpWheelMenu::handleDragStart()
{
    if (m_state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        onDragStart();
    }
}


void VcpWheelMenu::handleDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    if (m_state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        onDragEnd(xspeed, yspeed);
    }
}


void VcpWheelMenu::handleDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    if (m_state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        onDrag(xoffset, yoffset);
    }
}


void VcpWheelMenu::handleTap(VfxPoint pt)
{
    if (m_state == VCP_WHEEL_MENU_NORMAL_STATE && !m_isSliding)
    {
        onTap(pt);
    }
}


VfxBool VcpWheelMenu::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_maxMoveOffset = 0;
        handleDragStart();
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        if (m_maxMoveOffset <= getTapThreshold())
        {
            // this is a tap            
            VfxPoint dowmpt = event.getRelDownPos(this);
            handleDragEnd(0, 0);
            handleTap(dowmpt);
        }
        else if (event.timeStamp > event.downTimeStamp)
        {
            VfxPoint dowmpt = event.getRelDownPos(this);
            VfxPoint pt     = event.getRelPos(this);
            VfxS32   yv      = (1000 * (pt.y - dowmpt.y)) / (event.timeStamp - event.downTimeStamp);
            VfxS32   xv      = (1000 * (pt.x - dowmpt.x)) / (event.timeStamp - event.downTimeStamp);

            // the onTap event will disable
            m_isSliding = VFX_TRUE;

            handleDragEnd(xv, yv);
        }
        else
        {
            handleDragEnd(0, 0);            
        }
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        handleDragEnd(0, 0);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {   
        VfxPoint dowmpt = event.getRelDownPos(this);
        VfxPoint prept  = event.getRelPrevPos(this);
        VfxPoint pt     = event.getRelPos(this);
        
        VfxS32 xoffset = VFX_ABS(pt.x - dowmpt.x);
        VfxS32 yoffset = VFX_ABS(pt.y - dowmpt.y);
        
        m_maxMoveOffset = yoffset > m_maxMoveOffset ? yoffset : m_maxMoveOffset;
        m_maxMoveOffset = xoffset > m_maxMoveOffset ? xoffset : m_maxMoveOffset;

        if (m_maxMoveOffset > getTapThreshold())
        {
            handleDrag(pt.x - prept.x, pt.y - prept.y);
        }

        return VFX_TRUE;
    }
    return Super::onPenInput(event);
}

void VcpWheelMenu::closeCell(VfxS32 cell, VfxS32 subCell, VfxFrame* frame)
{
    VFX_DEV_ASSERT(cell >= 0);
    VFX_DEV_ASSERT(subCell >= 0);

    // if the cell is dummy cell

    const VcpWheelMenuCellHeader* header = getCellHeader(Key(cell, subCell));

    if (header && (header->flag & CELL_FLAG_DUMMY))
    {
        // close it directly
        VFX_OBJ_CLOSE(frame);
        return;
    }

    onCloseCell(cell, subCell, frame);
}

void VcpWheelMenu::closeCell(VfxS32 cell)
{
    VFX_DEV_ASSERT(cell >= 0);

    for (VfxS32 i = 0; i < m_subCellCount; i++)
    {
        m_cache.closeItem(Key(cell, i));
    }
}

void VcpWheelMenu::resetCell(VfxS32 index)
{
    closeCell(index);
    update();
}

void VcpWheelMenu::withdrawCell(VfxS32 index, VfxBool behindItemGoAhead)
{
    // Backup original value
    VfxS32 preFocus = getFocus();
    VfxBool isRemoveFocus = (index == preFocus);

	// check the index is in valid range
    if (index < m_firstVisibleItem || index >= m_lastVisibleItem)
        return;

    // It is impossible that remove index 0 but not behide item go ahead
    if (index == 0)
    {
        behindItemGoAhead = VFX_TRUE;
    }

	// close the withdraw cell
    closeCell(index);

	// make the tracker dirty during withdraw process
	m_tracker->setBorderWidth((m_tracker->getBorderWidth() % 2) + 1);

	// adjust cache and index
	VfxS32 i;
    kal_uint32 tick;
    kal_get_time(&tick);

    for (i = index; i < m_lastVisibleItem; i++)
    {
        for (VfxS32 j = 0; j < m_subCellCount; j++)
        {
			Key new_key(i, j);
			Key org_key(i+1, j);

            VfxFrame* item = m_cache.getItem(org_key);
            m_cache.removeItem(org_key);

			// check whether the cell is existed
			if (item)
            {
                m_cache.setItem(new_key, item);

			    // re-fill userdata
                VcpWheelMenuCellHeader header;
                header = *getCellHeader(new_key);
                header.cell = i;
                header.subCell = j;
                setCellHeader(new_key, &header);
            }
        }
    }

    onAfterWithdrawCellClosed();
	// re-update new cell, new cell will create now
	updateContent(VFX_FALSE);

    if (behindItemGoAhead)
    {
        for (i = index; i < m_lastVisibleItem; i++)
        {
            for (VfxS32 j = 0; j < m_subCellCount; j++)
            {
			    Key key(i, j);

			    // check whether the cell is existed
			    if (m_cache.getItem(key) == NULL)
				    continue; 

			    // re-fill userdata
                VcpWheelMenuCellHeader header;
                header.cell = i;
                header.subCell = j;
                header.indexOffset = 1;
                header.indexOffsetTick = tick;
                setCellHeader(Key(i, j), &header);
            }
        }
    }
    else
    {
        setFocus(getFocus()-1, 0);
	    // re-update new cell, new cell will create now
	    updateContent(VFX_TRUE);

        for (i = m_firstVisibleItem; i < index; i++)
        {
            for (VfxS32 j = 0; j < m_subCellCount; j++)
            {
			    Key key(i, j);

			    // check whether the cell is existed
			    if (m_cache.getItem(key) == NULL)
				    continue; 

			    // re-fill userdata
                VcpWheelMenuCellHeader header;
                header.cell = i;
                header.subCell = j;
                header.indexOffset = -1;
                header.indexOffsetTick = tick;
                setCellHeader(Key(i, j), &header);
            }
        }
    }

    // check whether need notify focus change
    if (m_focus >= getCount() && getCount() > 0)
    {
        setFocus(getCount() - 1);
    }
    else if (preFocus != getFocus() || isRemoveFocus)
    {
        onFocusIndexChange(getFocus(), preFocus);
    }

	// notify wheel menu to refresh
    update();
}


VfxFrame* VcpWheelMenu::pullOutSubCell(VfxS32 cell, VfxS32 subCell)
{
    VfxFrame* item = m_cache.getItem(Key(cell, subCell));;
 
    if (item == NULL)
    {
        return NULL;
    }

    Key key(cell, subCell);

    VcpWheelMenuCellHeader header;
    header = *getCellHeader(key);

    // If the cell has been removed before
    if (header.flag & CELL_FLAG_DUMMY)
    {
        return NULL;
    }

    // Create dummy frame
    VfxFrame* frame;
    VFX_OBJ_CREATE(frame, VfxFrame, this);
    frame->setOpacity(0);

    // Copy back the userdata

    VfxU32 bufferSize = item->getPropertyEffectCallbackUserDataSize();

    if (bufferSize)
    {
        VfxU8* pBuffer;
        VFX_ALLOC_MEM(pBuffer, bufferSize, this);
        memcpy(pBuffer, item->getPropertyEffectCallbackUserDataPtr(), bufferSize);

        // set up dummy flag
        VcpWheelMenuCellHeader* h = (VcpWheelMenuCellHeader*)pBuffer;
        h->flag |= CELL_FLAG_DUMMY;

        // set FPE to dummy frame
        frame->setPropertyEffectCallback(
            m_tracker, 
            &VcpWheelMenu::dummyFramePropertyEffectCallback, 
            pBuffer, 
            bufferSize,
            VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

        VFX_FREE_MEM(pBuffer);
    }
    else
    {
        VFX_DEV_ASSERT(0);
    }

    m_cache.setItem(key, frame);

	// make the tracker dirty during withdraw process
	m_tracker->invalidate();

    // set a dummy FPE to workaround FPE cannot remove issue
    
    item->setPropertyEffectCallback(
        NULL,
        NULL,
        NULL,
        0);
        
    return item;
}


void VcpWheelMenu::pushInSubCell(VfxFrame *frame, VfxS32 cell, VfxS32 subCell)
{
    VfxFrame* item = m_cache.getItem(Key(cell, subCell));;

    // only dummy Cell can be replace by input frame
    if (item == NULL || frame == NULL)
    {
        VFX_ASSERT(0);
    }

    Key key(cell, subCell);

    VcpWheelMenuCellHeader header;
    header = *getCellHeader(key);

    // only dummy Cell can be replace by input frame
    if (!(header.flag & CELL_FLAG_DUMMY))
    {
        VFX_ASSERT(0);
    }

    /*
    // Create dummy frame
    VfxFrame* frame;
    VFX_OBJ_CREATE(frame, VfxFrame, this);
    frame->setOpacity(0);
    */
    // Copy back the userdata

    VfxU32 bufferSize = item->getPropertyEffectCallbackUserDataSize();

    if (bufferSize)
    {
        VfxU8* pBuffer;
        VFX_ALLOC_MEM(pBuffer, bufferSize, this);
        memcpy(pBuffer, item->getPropertyEffectCallbackUserDataPtr(), bufferSize);

        // set up dummy flag
        VcpWheelMenuCellHeader* h = (VcpWheelMenuCellHeader*)pBuffer;
        h->flag &= ~CELL_FLAG_DUMMY;

        // set FPE to dummy frame
        frame->setPropertyEffectCallback(
            m_tracker, 
            &VcpWheelMenu::framePropertyEffectCallback, 
            pBuffer, 
            bufferSize,
            VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

        VFX_FREE_MEM(pBuffer);
    }
    else
    {
        VFX_DEV_ASSERT(0);
    }

    m_cache.setItem(key, frame);

    VFX_OBJ_CLOSE(item);
	// make the tracker dirty during withdraw process
	m_tracker->invalidate();
}

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

void VcpWheelMenu::configureStatePara(
        VcpWheelMenuState state, 
        VfxMsec durationPerCell,     
        VfxMsec delay,                          
        VcpWheelMenuOrder order
        )
{
    VfxS32 index;
    if (state ==  VCP_WHEEL_MENU_ENTER_STATE)
    {
        index = 0;
    }
    else if (state ==  VCP_WHEEL_MENU_LEAVE_STATE)
    {
        index = 1;
    }
    else
    {
        // no use
        return;
    }
    m_durationPerCell[index] = durationPerCell;
    m_delay[index] = delay;
    m_order[index] = order;
}


void VcpWheelMenu::changeState(VcpWheelMenuState state)
{
    VfxS32 index;
    int i,j;
    // This timeline count not include subCell's timeline
    VfxS32 timelineCount = 0;
    VfxS32 aheadIndex = 0; 
    VfxS32 behindIndex = 0;
    VfxBool lastAhead;
    VfxMsec totalDuration = 0;

    // stop last change state timer
    m_changeStateTimer->stop();
    
    // Already in that state
    if (m_state == state)
    {
        return;
    }
    // if destination is normal just set state without open timeline
    if (state == VCP_WHEEL_MENU_NORMAL_STATE)
    {
        m_state = VCP_WHEEL_MENU_NORMAL_STATE;
        onStateChangeFinished(m_state);
        // stop all the timeline
        for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
        {
            for (j = 0; j < m_subCellCount; j++)
            {
                VfxFloatTimeline *filterTimeline = m_cache.getItemTimeline(Key(i, j));
                VFX_OBJ_CLOSE(filterTimeline);
                m_cache.setItemTimeline(Key(i, j), NULL);
            }
        }
        // set FPE back of trigger content Dirty
        changeFPETriggerMethod(VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
        return;
    }
    
    if (state == VCP_WHEEL_MENU_ENTER_STATE)
    {
        index = 0;
        m_state = VCP_WHEEL_MENU_ENTER_STATE;
    }    
    else if (state ==  VCP_WHEEL_MENU_LEAVE_STATE)
    {
        index = 1;
        m_state = VCP_WHEEL_MENU_LEAVE_STATE;
    }
    else
    {
        // no use
        return;
    }

    // set state timeline count before all timeline start
    //m_stateTimelineCount = (m_lastVisibleItem - m_firstVisibleItem) * m_subCellCount;
    m_stateTimelineCount = 0;

    switch (m_order[index])
    {    
        case VCP_WHEEL_MENU_INCREASE:
            for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
            {
                m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * (i - m_firstVisibleItem));
            }
            totalDuration = (m_lastVisibleItem - m_firstVisibleItem - 1) * m_delay[index] + m_durationPerCell[index];
            break;
        case VCP_WHEEL_MENU_DECREASE:
            for (i = m_lastVisibleItem - 1; i >= m_firstVisibleItem; i--)
            {
                m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * (m_lastVisibleItem - i));
            }
            totalDuration = (m_lastVisibleItem - m_firstVisibleItem - 1) * m_delay[index] + m_durationPerCell[index];
            break;
        case VCP_WHEEL_MENU_FOCUS_FISRT:       
            i = m_focus;
            m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], 0);
            timelineCount ++;
            
            if (getAheadCount() > getBehindCount())
            {
                aheadIndex ++;
                lastAhead = VFX_TRUE;
                i = m_focus - aheadIndex;
            }
            else
            {
                behindIndex ++;
                lastAhead = VFX_FALSE;
                i = m_focus + behindIndex;
            }

            m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * timelineCount);
            timelineCount ++;

            while (!(aheadIndex == getAheadCount() && behindIndex == getBehindCount()))
            {
                if (getAheadCount() - aheadIndex  > getBehindCount() - behindIndex)
                {
                    aheadIndex ++;
                    lastAhead = VFX_TRUE;
                    i = m_focus - aheadIndex;
                }
                else if (getAheadCount() - aheadIndex  == getBehindCount() - behindIndex)
                {
                    // if ahead count == behind count we chose differet from last chose
                    if (lastAhead)
                    {
                        behindIndex ++;
                        lastAhead = VFX_FALSE;
                        i = m_focus + behindIndex;
                    }
                    else
                    {
                        aheadIndex ++;
                        lastAhead = VFX_TRUE;
                        i = m_focus - aheadIndex;
                    }
                }
                else
                {
                    behindIndex ++;
                    lastAhead = VFX_FALSE;
                    i = m_focus + behindIndex;
                }
                m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * timelineCount);
                timelineCount ++;
            }
            totalDuration = (m_lastVisibleItem - m_firstVisibleItem - 1) * m_delay[index] + m_durationPerCell[index];
            break;
        case VCP_WHEEL_MENU_FOCUS_LAST:

            if (getAheadCount() > getBehindCount())
            {
                i = m_focus - getAheadCount() + aheadIndex;
                aheadIndex ++;
                lastAhead = VFX_TRUE;
            }
            else
            {
                i = m_focus + getBehindCount() - behindIndex;
                behindIndex ++;
                lastAhead = VFX_FALSE;
            }

            m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], 0);
            timelineCount ++;

            while (!(aheadIndex == getAheadCount() && behindIndex == getBehindCount()))
            {
                if (getAheadCount() - aheadIndex  > getBehindCount() - behindIndex)
                {
                    i = m_focus - getAheadCount() + aheadIndex;
                    aheadIndex ++;
                    lastAhead = VFX_TRUE;
                }
                else if (getAheadCount() - aheadIndex  == getBehindCount() - behindIndex)
                {
                    // if ahead count == behind count we chose differet from last chose
                    if (lastAhead)
                    {
                        i = m_focus + getBehindCount() - behindIndex;
                        behindIndex ++;
                        lastAhead = VFX_FALSE;
                    }
                    else
                    {
                        i = m_focus - getAheadCount() + aheadIndex;
                        aheadIndex ++;
                        lastAhead = VFX_TRUE;
                    }
                }
                else
                {
                    i = m_focus + getBehindCount() - behindIndex;
                    behindIndex ++;
                    lastAhead = VFX_FALSE;
                }
                
                m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * timelineCount);
                timelineCount ++;
            }

            i = m_focus;
            m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], m_delay[index] * timelineCount);
            totalDuration = (m_lastVisibleItem - m_firstVisibleItem - 1) * m_delay[index] + m_durationPerCell[index];
            break;
        case VCP_WHEEL_MENU_ALL_TOGETHER:
            for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
            {
                m_stateTimelineCount += startCellFilterTimeline(i, m_durationPerCell[index], 0);
            }
            totalDuration = m_durationPerCell[index];
            break;
        default:
            VFX_ASSERT(0);
            
    }
    // start a timer to get the end event
    m_changeStateTimer->setStartDelay(totalDuration);
	m_changeStateTimer->start();
    // set FPE trigger EveryTime when enter/leave state
    changeFPETriggerMethod(VRT_FPE_TRIGGER_TYPE_EVERYTIME);
}


void VcpWheelMenu::onEndofChangeTimer(VfxTimer *source)
{
	onStateChangeFinished(m_state);
    // change to normal state when enter is finished
    if (m_state == VCP_WHEEL_MENU_ENTER_STATE)
    {
        changeState(VCP_WHEEL_MENU_NORMAL_STATE);
    }
}

void VcpWheelMenu::changeFPETriggerMethod(vrt_frame_property_effect_trigger_type_enum value)
{
    VfxS32 i, j;

    for (i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    {
        for (j = 0; j < m_subCellCount; j++)
        {

            // Copy back the userdata
            VfxFrame* item = m_cache.getItem(Key(i, j));
            VfxU32 bufferSize = item->getPropertyEffectCallbackUserDataSize();

            if (bufferSize)
            {
                VfxU8* pBuffer;
                VFX_ALLOC_MEM(pBuffer, bufferSize, this);
                memcpy(pBuffer, item->getPropertyEffectCallbackUserDataPtr(), bufferSize);

                // set up dummy flag
                VcpWheelMenuCellHeader* h = (VcpWheelMenuCellHeader*)pBuffer;
                h->state = m_state;
                // set FPE to dummy frame
                item->setPropertyEffectCallback(
                    m_tracker, 
                    &VcpWheelMenu::framePropertyEffectCallback, 
                    pBuffer, 
                    bufferSize,
                    value);

                VFX_FREE_MEM(pBuffer);
            }
            else
            {
                VFX_DEV_ASSERT(0);
            }
        }
    }
}


VfxS32 VcpWheelMenu::startCellFilterTimeline(VfxS32 cell, VfxMsec duration, VfxMsec delay)
{
    VfxS32 j;
    VfxS32 count = 0;
    for (j = 0; j < m_subCellCount; j++)
    {
        VfxFrame* item = m_cache.getItem(Key(cell, j));
        if (item)
        {
            VfxFloatTimeline *filterTimeline = m_cache.getItemTimeline(Key(cell, j));
            if (filterTimeline == NULL)
            {
                VFX_OBJ_CREATE(filterTimeline, VfxFloatTimeline, item);
                m_cache.setItemTimeline(Key(cell, j), filterTimeline);
            }
            
            filterTimeline->setFromValue(0.0f);
            filterTimeline->setToValue(1.0f);
            filterTimeline->setDurationTime(duration);
            filterTimeline->setRepeatCount(1);
            filterTimeline->setTarget(item);
            filterTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
            filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
            filterTimeline->setStartTime(delay);
            filterTimeline->start();

            // keep in init state
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            item->setFpeUser0(1);
            item->setFpeUser0(0);
            VfxAutoAnimate::commit();
            count ++;
        }
    }
    return count;
}

#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */
