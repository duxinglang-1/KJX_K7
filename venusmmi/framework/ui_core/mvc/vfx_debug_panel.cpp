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
 *  vfx_debug_panel.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  The debug panel of Venus UI engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_debug_panel.h"

#include "vfx_sys_config.h"
#include "vfx_draw_context.h"
#include "vfx_timer.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_mem_config.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vrt_debug.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vrt_canvas.h"
#include "vfx_input_event.h"
#include "vfx_context.h"
#include "vfx_logger.h"

#include <float.h>

extern "C"
{
#include "gdi_include.h"
#ifdef __COSMOS_3D_V10__
#include "gpu_instrumented_ctrl.h"
#endif
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_DEBUG_CACHE_SIZE_FILE_NAME L"Z:\\CacheSize.txt"


/***************************************************************************** 
 * Global Functions
 *****************************************************************************/

extern "C" vrt_allocator_handle vfx_sys_get_vrt_context_allocator(void);


/***************************************************************************** 
 * Class VfxDebugPenCursor
 *****************************************************************************/

class VfxDebugPenCursor : public VfxFrame
{
public:
    enum Type
    {
        PEN_DOWN,
        PEN_UP
    };

public:
    VfxDebugPenCursor();

    void setup(Type type, const VfxColor &cursorColor, const VfxColor &backgroundColor);

protected:
    virtual void onInit();
    virtual void onDraw(VfxDrawContext &dc);


private:
    Type m_type;
    VfxColor m_cursorColor;
};


VfxDebugPenCursor::VfxDebugPenCursor() :
    m_type(PEN_DOWN),
    m_cursorColor(VFX_COLOR_RED)
{
}


void VfxDebugPenCursor::setup(Type type, const VfxColor &cursorColor, const VfxColor &backgroundColor)
{
    setBorder(cursorColor);
    setBgColor(backgroundColor);

    m_type = type;
    m_cursorColor = cursorColor;
    invalidate();
}


void VfxDebugPenCursor::onInit()
{
    VfxFrame::onInit();

    setIsUnhittable(VFX_TRUE);
    setAnchor(0.5f, 0.5f);
    setOpacity(0.5f);
}


void VfxDebugPenCursor::onDraw(VfxDrawContext &dc)
{
    VfxRect bounds = getBounds();

    VfxS32 x1 = bounds.origin.x;
    VfxS32 y1 = bounds.origin.y;
    VfxS32 x2 = bounds.origin.x + bounds.size.width - 1;
    VfxS32 y2 = bounds.origin.y + bounds.size.height - 1;
    VfxS32 xm = (x1 + x2) / 2;
    VfxS32 ym = (y1 + y2) / 2;

    dc.setStrokeColor(m_cursorColor);

    switch (m_type)
    {
        case PEN_DOWN:
            dc.drawLine(x1, y1, x2, y2);
            dc.drawLine(x2, y1, x1, y2);
            break;
            
        case PEN_UP:
            dc.drawLine(x1, ym, x2, ym);
            dc.drawLine(xm, y1, xm, y2);
            break;

        default:
            break;
    }
}


/***************************************************************************** 
 * Class VfxDebugPanel
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_DEBUG_PANEL_CLASS_NAME, VfxDebugPanel, VfxControl);

VfxDebugPanel::VfxDebugPanel() : 
    m_mode(DISPLAY_MODE_FPS_LITE),
    m_placement(DISPLAY_PLACE_UNKNOWN),
    m_controlUpdateTimer(NULL),
    m_isDebugDirtyRect(VFX_FALSE),    
#ifndef __MTK_TARGET__
    m_vrtDbgMemory(VFX_FALSE),
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
    m_vrtHWOVL(vrt_canvas_is_enable_hw_ovl() ? VFX_TRUE : VFX_FALSE),
    m_vrtCross(vrt_canvas_is_enable_show_cross() ? VFX_TRUE : VFX_FALSE),
#if defined(GDI_9SLICE_USING_DITHERING)
    m_9sliceDithering(gdi_image_9slice_get_dither() ? VFX_TRUE : VFX_FALSE),
#endif
    m_vfxLogSwitch(vfx_logger_is_enable_log()),
    m_cacheOOMEnable(VFX_FALSE),
#ifdef __COSMOS_3D_V10__
    m_PATLogEnable(VFX_FALSE),
    m_PATLogDumpEnable(VFX_FALSE),
#endif /*__COSMOS_3D_V10__*/
    m_vrtDbgSettings(VRT_DBG_PERFORMANCE_HINT_NONE),
    m_cursorDown(NULL),
    m_cursorUp(NULL),
    m_cursorPressure(0),
    m_cursorRange(NULL)
{
    vrt_canvas_dbg_get_statistics(&m_vrtStatistics);
    vfx_sys_mem_zero(&m_globalPoolStatistics, sizeof(m_globalPoolStatistics));
    vfx_sys_mem_zero(&m_appPoolStatistics, sizeof(m_appPoolStatistics));
    vfx_sys_mem_zero(&m_vrtPoolStatistics, sizeof(m_vrtPoolStatistics));
}


void VfxDebugPanel::handlePenEvent(VfxPenEvent &event)
{
    if (event.type != VFX_PEN_EVENT_TYPE_UP)
    {
        // Do nothing
        return;
    }
    
    VfxFrame *parent = getParentFrame();
    if (parent == NULL)
    {
        // Do nothing
        return;
    }

    DisplayPlace placement = getDisplayPlace();
    VfxRect bounds = parent->getBounds();
    VfxPoint penPos = event.getRelPos(parent);

    // Test where to placement
    DisplayPlace targetPlacement;    
    if (penPos.x < bounds.getMinX() + CHANGE_MODE_AREA_WIDTH &&
        penPos.y < bounds.getMinY() + CHANGE_MODE_AREA_HEIGHT)
        
    {
        targetPlacement = DISPLAY_PLACE_LEFT_TOP;
    }
    else if (penPos.x < bounds.getMinX() + CHANGE_MODE_AREA_WIDTH && 
        penPos.y >= bounds.getMaxY() - VfxDebugPanel::CHANGE_MODE_AREA_HEIGHT)
    {
        targetPlacement = DISPLAY_PLACE_LEFT_BUTTOM;
    }
    else if (penPos.x >= bounds.getMaxX() - CHANGE_MODE_AREA_WIDTH && 
        penPos.y >= bounds.getMaxY() - VfxDebugPanel::CHANGE_MODE_AREA_HEIGHT)
    {
        targetPlacement = DISPLAY_PLACE_RIGHT_BUTTOM;
    }
    else if (penPos.x >= bounds.getMaxX() - CHANGE_MODE_AREA_WIDTH && 
        penPos.y < bounds.getMinY() + CHANGE_MODE_AREA_HEIGHT)
    {
        // Switch to output dirty rectangle
        m_isDebugDirtyRect = !m_isDebugDirtyRect;
        vrt_canvas_dbg_enable_dirty_rect((vrt_bool)m_isDebugDirtyRect);

        if (!m_isDebugDirtyRect)
        {
            invalidate();
        }
        return;
    }
    else 
    {
        targetPlacement = DISPLAY_PLACE_UNKNOWN;
    }

    // Doesn't click any mode
    if (targetPlacement == DISPLAY_PLACE_UNKNOWN)
    {
        return;
    }

    // Click at same placement, toggle mode
    if (targetPlacement == placement)
    {
        toggleDisplayMode();    
        return;
    }

    setDisplayPlace(targetPlacement);
}


void VfxDebugPanel::handlePenEvent2(VfxPenEvent &event)
{
    if (getDisplayMode() != DISPLAY_MODE_PEN_EVENT)
    {
        VFX_OBJ_CLOSE(m_cursorUp);
        VFX_OBJ_CLOSE(m_cursorDown);
        VFX_OBJ_CLOSE(m_cursorRange);
        return;
    }

    VfxFrame *parent = getParentFrame();
    if (parent == NULL)
    {
        // Do nothing
        return;
    }

    if (m_cursorRange == NULL)
    {
        VFX_OBJ_CREATE(m_cursorRange, VfxFrame, this);
        m_cursorRange->setPosZ(-FLT_MAX);
        m_cursorRange->setBgColor(VfxColor(0xff007f00));
        m_cursorRange->setBorder(VfxColor(0xff00ff00));
        m_cursorRange->setOpacity(0.5f);
        parent->addChildFrame(m_cursorRange);
    }
    if (m_cursorDown == NULL)
    {
        VFX_OBJ_CREATE(m_cursorDown, VfxDebugPenCursor, this);
        m_cursorDown->setPosZ(-FLT_MAX);
        m_cursorDown->setSize(9, 9);
        m_cursorDown->setup(VfxDebugPenCursor::PEN_DOWN, VFX_COLOR_YELLOW, VFX_COLOR_BLACK);
        parent->addChildFrame(m_cursorDown);
    }
    if (m_cursorUp == NULL)
    {
        VFX_OBJ_CREATE(m_cursorUp, VfxDebugPenCursor, this);
        m_cursorUp->setPosZ(-FLT_MAX);
        m_cursorUp->setSize(5, 5);
        m_cursorUp->setup(VfxDebugPenCursor::PEN_UP, VFX_COLOR_RED, VFX_COLOR_BLACK);
        parent->addChildFrame(m_cursorUp);
    }
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_cursorDown->setPos(event.pos);
        m_cursorUp->setOpacity(0.0f);
        m_cursorRange->setRect(event.pos.x, event.pos.y, 1, 1);
    }
    else
    {
        VfxS32 x0 = vfxMin(m_cursorRange->getRect().getMinX(), event.pos.x);
        VfxS32 y0 = vfxMin(m_cursorRange->getRect().getMinY(), event.pos.y);
        VfxS32 x1 = vfxMax(m_cursorRange->getRect().getMaxX(), event.pos.x);
        VfxS32 y1 = vfxMax(m_cursorRange->getRect().getMaxY(), event.pos.y);
        m_cursorUp->setPos(event.pos);
        m_cursorUp->setOpacity(1.0f);
        m_cursorRange->setRect(x0, y0, x1 - x0 + 1, y1 - y0 + 1);
    }

    m_cursorPressure = event.pressure;

    invalidate();
}


void VfxDebugPanel::toggleDisplayMode()
{
    VfxU32 mode = getDisplayMode();
    
    mode++;
    if (mode >= DISPLAY_MODE_END_OF_ENUM)
    {
        mode = 0;
    }
    
    setDisplayMode((DisplayMode)mode);    
}


void VfxDebugPanel::setDisplayMode(DisplayMode mode)
{
    if (mode == m_mode)
    {
        // Do nothing.
        return;
    }

    VfxU32 panelWidth = 0;
    VfxU32 panelHeight = 0;

    switch (mode)
    {
        case DISPLAY_MODE_FULL:
            panelWidth = FULL_MODE_PANEL_WIDTH;
            panelHeight = FULL_MODE_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_AUTO_CACHE:
            panelWidth = AUTO_CACHE_PANEL_WIDTH;
            panelHeight = AUTO_CACHE_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_VRT_MEMORY:
            panelWidth = VRT_MEMORY_PANEL_WIDTH;
            panelHeight = VRT_MEMORY_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_RESPONSE_TIME:
            panelWidth = RESPONSE_TIME_PANEL_WIDTH;
            panelHeight = RESPONSE_TIME_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_PEN_EVENT:
            panelWidth = PEN_EVENT_PANEL_WIDTH;
            panelHeight = PEN_EVENT_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_FRAME_TIME:
            panelWidth = FRAME_TIME_PANEL_WIDTH;
            panelHeight = FRAME_TIME_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case DISPLAY_MODE_FPS_LITE:
            panelWidth = FPS_LITE_PANEL_WIDTH;
            panelHeight = FPS_LITE_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_ANIMATION_FPS:
            panelWidth = FPS_LITE_PANEL_WIDTH;
            panelHeight = FPS_LITE_PANEL_HEIGHT;
            m_controlUpdateTimer->start();
            break;

        case DISPLAY_MODE_SETTINGS:
            panelWidth = SETTINGS_PANEL_WIDTH;
            panelHeight = SETTINGS_PANEL_HEIGHT;
            m_controlUpdateTimer->stop();
            break;

        case DISPLAY_MODE_NONE:
            panelWidth = 0;
            panelHeight = 0;
            m_controlUpdateTimer->stop();
            break;
    }

    setSize(panelWidth, panelHeight);

    switch (m_placement)
    {
        case DISPLAY_PLACE_LEFT_TOP:
            setAnchor(0.0f, 0.0f);
            setPos(0, 0);
            break;
    
        case DISPLAY_PLACE_LEFT_BUTTOM:
            setAnchor(0.0f, 1.0f);
            setPos(0, LCD_HEIGHT - 1);
            break;
    
        case DISPLAY_PLACE_RIGHT_BUTTOM:
            setAnchor(1.0f, 1.0f);
            setPos(LCD_WIDTH - 1, LCD_HEIGHT - 1);
            break;
    }

    m_mode = mode;
    invalidate();
}


void VfxDebugPanel::setDisplayPlace(DisplayPlace placement)
{
    if (m_placement == placement)
    {
        return;
    }
    
    m_placement = placement;

    DisplayMode currMode = m_mode;
    m_mode = DISPLAY_MODE_NONE;

    setDisplayMode(currMode);
}


void VfxDebugPanel::onInit()
{
    VfxControl::onInit();

    // Set properties    
    setSize(FPS_LITE_PANEL_WIDTH, FPS_LITE_PANEL_HEIGHT);
    setIsOpaque(VFX_TRUE);
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    setBgColor(VFX_COLOR_BLACK);
    setOpacity(0.6f);

    // Create update timer and start
    VFX_OBJ_CREATE(m_controlUpdateTimer, VfxTimer, this);
    m_controlUpdateTimer->setDuration(1000);
    m_controlUpdateTimer->m_signalTick.connect(this, &VfxDebugPanel::onUpdateTimerTick);
    m_controlUpdateTimer->start();

    // read cache size
    m_cacheSize = VFX_SYS_MEM_VRT_CACHE_MAX_SIZE;
    ReadCacheSize(m_cacheSize);
    vfx_set_cache_config_size(m_cacheSize);

    setDisplayPlace(DISPLAY_PLACE_LEFT_TOP);
}


void VfxDebugPanel::onDeinit()
{
    vrt_canvas_dbg_enable_dirty_rect(VRT_FALSE);

    VfxControl::onDeinit();
}


void VfxDebugPanel::onDraw(VfxDrawContext &dc)
{
    VfxRect bounds = getBounds();

    VfxWString str;
    VfxFontDesc fontDesc(g_vrt_font_small);
    
    dc.setFont(fontDesc);

    VfxS32 x = 0;
    VfxS32 y = 0;
    VfxS32 lineHeight = SINGLE_LINE_HEIGHT;

    if (m_mode == DISPLAY_MODE_FULL)
    {
        dc.drawText(x, y, VFX_WSTR("[VRT]"));
        dc.drawText(x, y + lineHeight*1, str.format("F: %u (%u)", m_vrtStatistics.cur_frame_cnt, m_vrtStatistics.max_frame_cnt));
        dc.drawText(x, y + lineHeight*2, str.format("T: %u (%u)", m_vrtStatistics.cur_timeline_cnt, m_vrtStatistics.max_timeline_cnt));
        dc.drawText(x, y + lineHeight*3, str.format("DC: %u (%u)", m_vrtStatistics.cur_draw_cmd_cnt, m_vrtStatistics.max_draw_cmd_cnt));
        dc.drawText(x, y + lineHeight*4, str.format("DB: %u (%u)", m_vrtStatistics.cur_draw_cmd_data_buf_size, m_vrtStatistics.max_draw_cmd_data_buf_size));
        dc.drawText(x, y + lineHeight*5, str.format("VRT: %u", m_vrtStatistics.cur_vrt_ext_free_size));
        dc.drawText(x, y + lineHeight*7, str.format("AC: %u (%u %u)", m_vrtStatistics.asm_pool_size, m_vrtStatistics.cur_asm_cache_alloc_size, m_vrtStatistics.max_asm_cache_alloc_size));
        dc.drawText(x, y + lineHeight*8, str.format("PC: %u (%u %u)", m_vrtStatistics.app_pool_size, m_vrtStatistics.cur_app_cache_alloc_size, m_vrtStatistics.max_app_cache_alloc_size));
        dc.drawText(x, y + lineHeight*9, str.format("VC: %u (%u %u)", m_vrtStatistics.vrt_default_pool_size, m_vrtStatistics.cur_med_cache_alloc_size, m_vrtStatistics.max_med_cache_alloc_size));
    
        x = bounds.getMidX();    
        
        dc.drawText(x, y, VFX_WSTR("[VFX]"));
        dc.drawText(x, y + lineHeight*1, str.format("G: %u (%u)", m_globalPoolStatistics.used_size, m_globalPoolStatistics.max_used_size));
        dc.drawText(x, y + lineHeight*2, str.format("GT: %u", m_globalPoolStatistics.total_size));
        dc.drawText(x, y + lineHeight*3, str.format("A: %u (%u)", m_appPoolStatistics.used_size, m_appPoolStatistics.max_used_size));
        dc.drawText(x, y + lineHeight*4, str.format("AT: %u", m_appPoolStatistics.total_size));
        dc.drawText(x, y + lineHeight*5, str.format("V: %u (%u)", m_vrtPoolStatistics.used_size, m_vrtPoolStatistics.max_used_size));
        dc.drawText(x, y + lineHeight*6, str.format("VT: %u", m_vrtPoolStatistics.total_size));
    }
    else if(m_mode == DISPLAY_MODE_AUTO_CACHE)
    {
        if (m_vrtStatistics.cur_cache_suggest_size > (m_vrtStatistics.asm_pool_size + m_vrtStatistics.app_pool_size + m_vrtStatistics.vrt_default_pool_size))
        {
            dc.setFillColor(VFX_COLOR_RED);
        }
        dc.drawText(x, y, str.format("[Auto Cache]"));
        dc.drawText(x, y + lineHeight*1, str.format("ASM: %u (%u %u)", m_vrtStatistics.asm_pool_size >> 10, m_vrtStatistics.cur_asm_cache_alloc_size >> 10, m_vrtStatistics.max_asm_cache_alloc_size >> 10));
        dc.drawText(x, y + lineHeight*2, str.format("APP: %u (%u %u)", m_vrtStatistics.app_pool_size >> 10, m_vrtStatistics.cur_app_cache_alloc_size >> 10, m_vrtStatistics.max_app_cache_alloc_size >> 10));
        dc.drawText(x, y + lineHeight*3, str.format("VRT: %u (%u %u)", m_vrtStatistics.vrt_default_pool_size >> 10, m_vrtStatistics.cur_med_cache_alloc_size >> 10, m_vrtStatistics.max_med_cache_alloc_size >> 10));
        dc.drawText(x, y + lineHeight*4, str.format("AC : %u (%u %u)", m_vrtStatistics.cur_cache_alloc_size >> 10, m_vrtStatistics.cur_cache_suggest_size >> 10, m_vrtStatistics.max_cache_suggest_size >> 10));

        dc.drawText(x, y + lineHeight*5, str.format("C(%u %u %u %u)", 
            m_vrtStatistics.cur_cache_c_alloc_count,
            m_vrtStatistics.max_cache_c_alloc_count,
            m_vrtStatistics.cur_cache_c_alloc_size >> 10,
            m_vrtStatistics.max_cache_c_alloc_size >> 10));

        dc.drawText(x, y + lineHeight*6, str.format("NC(%u %u %u %u)", 
            m_vrtStatistics.cur_cache_nc_alloc_count,
            m_vrtStatistics.max_cache_nc_alloc_count,
            m_vrtStatistics.cur_cache_nc_alloc_size >> 10,
            m_vrtStatistics.max_cache_nc_alloc_size >> 10));            
    }
    else if(m_mode == DISPLAY_MODE_VRT_MEMORY)
    {
        dc.drawText(x, y, str.format("AC %u (%u %u) %u",
            m_vrtStatistics.cur_cache_alloc_size >> 10,
            m_vrtStatistics.cur_cache_suggest_size >> 10,
            m_vrtStatistics.max_cache_suggest_size >> 10,
            m_vrtStatistics.cache_max_alloc_size >> 10
        ));
        dc.drawText(x, y + lineHeight*1, str.format("TB %u (%u %u))",
            m_vrtStatistics.tmp_pool_size >> 10,
            m_vrtStatistics.cur_tmp_buffer_alloc_size >> 10,
            m_vrtStatistics.max_tmp_buffer_alloc_size >> 10
        ));
        dc.drawText(x, y + lineHeight*2, str.format("SUM %u (%u %u)",
            (m_vrtStatistics.asm_pool_size + m_vrtStatistics.app_pool_size + m_vrtStatistics.vrt_default_pool_size + m_vrtStatistics.tmp_pool_size) >> 10,
            (m_vrtStatistics.cur_cache_alloc_size + m_vrtStatistics.cur_tmp_buffer_alloc_size) >> 10,
            m_vrtStatistics.max_total_suggest_size >> 10
        ));
    }
    else if(m_mode == DISPLAY_MODE_RESPONSE_TIME)
    {
        VfxU32 i;
        for (i = 0; i < VfxRendererProfiling::getCount(); i++)
        {
            const VfxRendererProfilingData &data = VfxRendererProfiling::getData(i);
            dc.drawText(x, y + lineHeight * i, str.format("C %u(%u %u)%s%s%s",
                data.commitTime,
                data.prepareHandleTime,
                data.prepareSceneGraphTime,
                data.isBlocking ? "B" : "",
                data.hasPlutoControl ? "P" : "",
                data.hasDebugPanelUpdate ? "?" : ""));
        }
    }
    else if(m_mode == DISPLAY_MODE_PEN_EVENT)
    {
        VfxU32 LcdFps = vrt_sys_get_fps(VRT_SYS_DISPLAY_MAIN_LCD);
        VfxU32 samplingMsec = 1000 / LcdFps;
        VfxU32 samplingPeriod = vfxMax(samplingMsec / 10, (VfxU32)1);
        
        dc.drawText(x, y, str.format("Lfps%u Ldpi%u P%u M%u L%u F%u",
            LcdFps,
            LCM_DPI,
            samplingPeriod,
            VFX_SYS_PEN_SKIP_MOVE_OFFSET,
            VFX_SYS_PEN_SKIP_LONGTAP_OFFSET,
            VFX_TOUCH_FINGER_WIDTH));
        if (m_cursorDown != NULL && m_cursorUp != NULL)
        {
            dc.drawText(x, y + lineHeight, str.format("D(%d,%d) (%d,%d) P:%u",
                m_cursorDown->getPos().x,
                m_cursorDown->getPos().y,
                m_cursorUp->getPos().x,
                m_cursorUp->getPos().y,
                m_cursorPressure));
        }            
    }
    else if(m_mode == DISPLAY_MODE_FRAME_TIME)
    {
        dc.drawText(x, y, str.format("%u(%u %u %u %u %u)(%u %u %u %u %u %u %u %u)",
            m_vrtStatistics.draw_frame_time,
            m_vrtStatistics.animation_time,
            m_vrtStatistics.dirty_scan_time,
            m_vrtStatistics.auto_cache_time,
            m_vrtStatistics.display_time,
            m_vrtStatistics.output_time,

            m_vrtStatistics.transform_time,
            m_vrtStatistics.overlay_time,
            m_vrtStatistics.clear_color_time,
            m_vrtStatistics.filter_time,
            m_vrtStatistics.owner_draw_time,
            m_vrtStatistics.world_time,
            m_vrtStatistics.text_time,
            m_vrtStatistics.hw_blt_time            
        ));
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    else if(m_mode == DISPLAY_MODE_FPS_LITE)
    {
        dc.drawText(x, y, str.format("%3.1f", m_vrtStatistics.avg_fps));
    }
    else if(m_mode == DISPLAY_MODE_ANIMATION_FPS)
    {
        dc.drawText(x, y, str.format("%3.1f", m_vrtStatistics.last_fps));
    }
    else if(m_mode == DISPLAY_MODE_SETTINGS)
    {
        VfxS32 w = SETTINGS_PANEL_WIDTH, h = DISPLAY_TEXT_HEIGHT;
        
        dc.drawText(x, y, VFX_WSTR("Settings"));
        y += TITLE_HEIGHT;

        const VfxS32 margin = 1;
        const VfxS32 size = DISPLAY_TEXT_HEIGHT;
        const VfxWChar* strNames[] = 
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            (const VfxWChar*)L"Frame Time",
            (const VfxWChar*)L"Image Time",
            (const VfxWChar*)L"Cache Size",
            (const VfxWChar*)L"Color Mode"
        };
        const VfxColor bgColors[] = 
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            VRT_COLOR_BLACK,
            VRT_COLOR_BLACK,
            VRT_COLOR_BLACK,
            VRT_COLOR_BLACK
        };
        const VfxColor fontColors[] = 
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            VFX_COLOR_WHITE,
            VFX_COLOR_GREEN,
            VFX_COLOR_YELLOW,
            VFX_COLOR_WHITE
        };

        int i;
        for (i = 0; i < SETTING_ITEM_COUNT; i++)
        {
            dc.setFillColor(bgColors[i]);
            dc.fillRect(x, y, w, h);
            dc.setFillColor(fontColors[i]);
            dc.drawText(x, y, strNames[i]);
            if (m_vrtDbgSettings & (1 << i))
            {
                dc.setFillColor(VRT_COLOR_WHITE);
                dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
            }
            y += DISPLAY_TEXT_HEIGHT;
        }
#ifndef __MTK_TARGET__
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("Debug Memory"));
        if (m_vrtDbgMemory)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += MEM_DEBUG_HEIGHT;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("HW OVL"));
        if (m_vrtHWOVL)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += OVL_HEIGHT;

        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("Cross"));
        if (m_vrtCross)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += CROSS_HEIGHT;

#if defined(GDI_9SLICE_USING_DITHERING)         
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("Dithering"));
        if (m_9sliceDithering)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += SLICE9_DITHERING_HEIGHT;
#endif        
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("$ OOM"));
        if (m_cacheOOMEnable)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += CACHE_OOM_HEIGHT;        

#ifdef __COSMOS_3D_V10__
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("GPUPAT_EN"));
        if (m_PATLogEnable)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += PAT_LOG_HEIGHT;
                
                
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);
        dc.setFillColor(VRT_COLOR_WHITE);
        dc.drawText(x, y, VFX_WSTR("GPUDUMP_EN"));
        if (m_PATLogDumpEnable)
        {
            dc.setFillColor(VRT_COLOR_WHITE);
            dc.fillRect(w - size + margin, y + margin, w - 2 * margin, h - 2 * margin);
        }
        y += PAT_LOGDUMP_HEIGHT;
#endif /*__COSMOS_3D_V10__*/
                
        dc.setFillColor(VRT_COLOR_BLACK);
        dc.fillRect(x, y, w, h);        
        dc.setFillColor(VRT_COLOR_TEAL);
        dc.fillRect(x, y, (VfxS32)((VfxFloat)w * (VfxFloat)m_cacheSize / (VfxFloat)VFX_SYS_MEM_VRT_CACHE_MAX_SIZE) ,h);
        dc.setFillColor(VRT_COLOR_WHITE);
        VfxWString sizeStr;
        sizeStr.format(VFX_WSTR("$ SIZE %d KB"), m_cacheSize >> 10);                
        dc.drawText(x, y, sizeStr);        
        y += CACHE_SIZE_HEIGHT;
        
    }
    else if(m_mode == DISPLAY_MODE_NONE)
    {
    }
    else
    {
        VFX_ASSERT(0);
    }
}


VfxBool VfxDebugPanel::onContainPoint(const VfxPoint &point) const
{
    if (m_mode == DISPLAY_MODE_SETTINGS &&
        point.x < SETTINGS_PANEL_WIDTH &&
        point.x >= 0 &&
        point.y > TITLE_HEIGHT &&
        point.y < SETTINGS_PANEL_HEIGHT)
    {
        return VFX_TRUE;
    }
    // Can not touch the panel
    return VFX_FALSE;
}


VfxBool VfxDebugPanel::onPenInput(
    VfxPenEvent &event          // [IN] The pen event to be handled
)
{
    // update cache size slider
    if ((m_mode == DISPLAY_MODE_SETTINGS) && 
        (event.type == VFX_PEN_EVENT_TYPE_MOVE) || (event.type == VFX_PEN_EVENT_TYPE_UP) &&
        (event.pos.y >= SETTINGS_PANEL_HEIGHT - DISPLAY_TEXT_HEIGHT))
    {        
        m_cacheSize = (VfxU32)((VfxFloat)VFX_SYS_MEM_VRT_CACHE_MAX_SIZE * (VfxFloat)event.pos.x / (VfxFloat)getSize().width);
        if (m_cacheSize > VFX_SYS_MEM_VRT_CACHE_MAX_SIZE)
        {
            m_cacheSize = VFX_SYS_MEM_VRT_CACHE_MAX_SIZE;
        }
        vfx_set_cache_config_size(m_cacheSize);
        WriteCacheSize(m_cacheSize);
        
        invalidate();
        return VFX_TRUE;
    }

    if (event.type != VFX_PEN_EVENT_TYPE_DOWN)
        return VFX_TRUE;
    VfxPoint& point = event.pos;
    if (m_placement == DISPLAY_PLACE_LEFT_TOP)
    VFX_ASSERT( m_mode == DISPLAY_MODE_SETTINGS &&
                point.x < SETTINGS_PANEL_WIDTH &&
                point.y > TITLE_HEIGHT &&
                point.y < SETTINGS_PANEL_HEIGHT);

    if (m_placement == DISPLAY_PLACE_LEFT_BUTTOM)
        VFX_ASSERT( m_mode == DISPLAY_MODE_SETTINGS &&
                    point.x < SETTINGS_PANEL_WIDTH &&
                    point.y > getPos().y + TITLE_HEIGHT &&
                    point.y < LCD_HEIGHT);
    
    if (m_placement == DISPLAY_PLACE_RIGHT_BUTTOM)
        VFX_ASSERT( m_mode == DISPLAY_MODE_SETTINGS &&
                    point.x > getPos().x &&
                    point.y > getPos().y + TITLE_HEIGHT &&
                    point.y < LCD_HEIGHT);

    VfxS32 y = point.y - getPos().y - TITLE_HEIGHT;

    if (y > HINTS_HEIGHT)
    {
        do
        {
            y -= HINTS_HEIGHT;

#ifndef __MTK_TARGET__
            /* enable/disable memory debug */
            if (y < MEM_DEBUG_HEIGHT)
            {
                m_vrtDbgMemory = !m_vrtDbgMemory;
                vrt_debug_enable_remap(m_vrtDbgMemory);
                break;
            }
            y -= MEM_DEBUG_HEIGHT;
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            /* enable/disable HW OVL */
            if (y < OVL_HEIGHT)
            {
                m_vrtHWOVL= !m_vrtHWOVL;
                vrt_canvas_enable_hw_ovl((vrt_bool)m_vrtHWOVL);
                break;
            }
            y -= OVL_HEIGHT;

            /* enable/disable cross bar */
            if (y < CROSS_HEIGHT)
            {
                m_vrtCross= !m_vrtCross;
                vrt_canvas_enable_show_cross((vrt_bool)m_vrtCross);
                break;
            }
            y -= CROSS_HEIGHT;

#if defined(GDI_9SLICE_USING_DITHERING)
            /* enable/disable 9-slice dithering */
            if (y < SLICE9_DITHERING_HEIGHT)
            {
                m_9sliceDithering = !m_9sliceDithering;
                gdi_image_9slice_set_dither(m_9sliceDithering ? KAL_TRUE : KAL_FALSE);
                break;
            }
            y -= SLICE9_DITHERING_HEIGHT;
#endif  /* GDI_9SLICE_USING_DITHERING */            
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            /* enable/disable VRT cache OOM assert */
            if (y < CACHE_OOM_HEIGHT)
            {
                m_cacheOOMEnable = !m_cacheOOMEnable;
                vrt_dbg_set_parameter(VRT_DBG_PARAMETER_CACHE_ALLOC_NULL_ASSERT, (void*)m_cacheOOMEnable);
                break;
            }
            y -= CACHE_OOM_HEIGHT;
            
#ifdef __COSMOS_3D_V10__
            /* enable/disable GPU PAT logging */
            if (y < PAT_LOG_HEIGHT)
            {
                m_PATLogEnable = !m_PATLogEnable;                
                /// call driver export API to set PAT log flag  
                if (VFX_TRUE == m_PATLogEnable)
                {                  
                   gpu_instrumented_info_ctrl_flag_set(GPU_INSTRUMENT_DUMP_COUNTERS|GPU_INSTRUMENT_DUMP_FRAMEBUFFER);
                }
                else
                {
                   gpu_instrumented_info_ctrl_flag_set(0);                
                }                  
                break;
            }
            y -= PAT_LOG_HEIGHT;

            /* enable/disable GPU PAT dump file */
            if (y < PAT_LOGDUMP_HEIGHT)
            {
                m_PATLogDumpEnable = !m_PATLogDumpEnable;                
                /// call driver export API to set PAT log flag  
                if (VFX_TRUE == m_PATLogDumpEnable)
                {                  
                   gpu_instrumented_info_dump_enable();
                }
                else
                {
                   gpu_instrumented_info_dump_disable();                
                }                  
                break;
            }
            y -= PAT_LOGDUMP_HEIGHT;
#endif /*__COSMOS_3D_V10__*/

            y -= CACHE_SIZE_HEIGHT;
            
        } while (0);
    }
    else
    {
        ((VfxU32&)m_vrtDbgSettings) ^= 1 << ((y / DISPLAY_TEXT_HEIGHT) % SETTING_ITEM_COUNT);
        vrt_canvas_dbg_performance_hint(m_vrtDbgSettings);
    }
    invalidate();
    return VFX_TRUE;
}


void VfxDebugPanel::onUpdateTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    vrt_canvas_dbg_get_statistics(&m_vrtStatistics);

    vfx_sys_mem_pool_allocator_get_status(
        vfx_sys_mem_get_global_allocator(), 
        &m_globalPoolStatistics);

    VfxContext *monitorContext = m_monitorContext.get();
    if (monitorContext != NULL)
    {
        // Update context pool status
        monitorContext->statistics(m_appPoolStatistics);
    }
    else
    {
        vfx_sys_mem_zero(&m_appPoolStatistics, sizeof(m_appPoolStatistics));
    }

    vfx_sys_mem_pool_allocator_get_status(
        vfx_sys_get_vrt_context_allocator(), 
        &m_vrtPoolStatistics);

    VfxRendererProfiling::setHasDebugPanelUpdate();
    
    invalidate();
}


void VfxDebugPanel::WriteCacheSize(vrt_u32 cacheSize)
{
    vfx_sys_file_handle fp;

    fp = vfx_sys_file_open(
        (const VfxWChar *)VFX_DEBUG_CACHE_SIZE_FILE_NAME, 
        VFX_UC_SYS_FILE_OPEN_MODE_CREATE | VFX_UC_SYS_FILE_OPEN_MODE_WRITE);
    if (fp >= 0)
    {
        vfx_sys_file_write(fp, (const VfxU8 *)&cacheSize, sizeof(vrt_u32));
        vfx_sys_file_close(fp);
    }        
}


void VfxDebugPanel::ReadCacheSize(vrt_u32 &cacheSize)
{
    vfx_sys_file_handle fp;

    fp = vfx_sys_file_open(
        (const VfxWChar *)VFX_DEBUG_CACHE_SIZE_FILE_NAME, 
        VFX_UC_SYS_FILE_OPEN_MODE_READ);
    if (fp >= 0)
    {
        vfx_sys_file_read(fp, (VfxU8 *)&cacheSize, sizeof(vrt_u32));
        vfx_sys_file_close(fp);
    }
    
    if (cacheSize > VFX_SYS_MEM_VRT_CACHE_MAX_SIZE)
    {
        cacheSize = VFX_SYS_MEM_VRT_CACHE_MAX_SIZE;
    }
}

