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
 *  vfx_debug_panel.h
 *
 * Project:
 * --------
 *  Venus UI Core
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

#ifndef __VFX_DEBUG_PANEL_H__
#define __VFX_DEBUG_PANEL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"
// For vrt_dbg_performance_hint_type
#include "vrt_debug.h"
#include "mmi_features.h"

extern "C"
{
#include "gdi_image_9slice.h"
}

    
/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxDebugPanel registered name
#define VFX_DEBUG_PANEL_CLASS_NAME      "DebugPanel"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-define classes
class VfxTimer;
class VfxContext;
class VfxDebugPenCursor;    


/***************************************************************************** 
 * Class VfxDebugPanel
 *****************************************************************************/




/*
 * Internal used. Debug panel in engineering mode.
 */
class VfxDebugPanel : public VfxControl
{
    VFX_DECLARE_CLASS(VfxDebugPanel);

// Define
public:

    enum
    {
        SETTING_ITEM_COUNT      = 4,
#if defined(__MMI_MAINLCD_480X800__)
        CHANGE_MODE_AREA_WIDTH = 45,
        CHANGE_MODE_AREA_HEIGHT = 30,
        DISPLAY_TEXT_HEIGHT     = 30,
        TITLE_HEIGHT            = 45,
#else
        CHANGE_MODE_AREA_WIDTH = 30,
        CHANGE_MODE_AREA_HEIGHT = 20,
        DISPLAY_TEXT_HEIGHT     = 20,
        TITLE_HEIGHT            = 30,
#endif
        HINTS_HEIGHT            = DISPLAY_TEXT_HEIGHT * SETTING_ITEM_COUNT,
#ifndef __MTK_TARGET__
        MEM_DEBUG_HEIGHT        = DISPLAY_TEXT_HEIGHT,
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
        OVL_HEIGHT              = DISPLAY_TEXT_HEIGHT,
        CROSS_HEIGHT            = DISPLAY_TEXT_HEIGHT,
#if defined(GDI_9SLICE_USING_DITHERING)         
        SLICE9_DITHERING_HEIGHT = DISPLAY_TEXT_HEIGHT,
#endif        
#if 0
/* under construction !*/
#endif
        CACHE_OOM_HEIGHT        = DISPLAY_TEXT_HEIGHT,
#ifdef __COSMOS_3D_V10__
        PAT_LOG_HEIGHT          = DISPLAY_TEXT_HEIGHT, 
        PAT_LOGDUMP_HEIGHT      = DISPLAY_TEXT_HEIGHT, 
#endif /*__COSMOS_3D_V10__*/
        /* ADD items before me */
        CACHE_SIZE_HEIGHT       = DISPLAY_TEXT_HEIGHT
    };

    // The display mode of debug panel
    enum DisplayMode
    {
        DISPLAY_MODE_FPS_LITE = 0,      // Display only FPS
        DISPLAY_MODE_FULL,              // Display full memory monitor 
        DISPLAY_MODE_ANIMATION_FPS,     // Display only FPS
        DISPLAY_MODE_RESPONSE_TIME,     // Display for response time profiling
        DISPLAY_MODE_PEN_EVENT,         // Display for pen relative information
        DISPLAY_MODE_AUTO_CACHE,        // Display auto cache info 
        DISPLAY_MODE_VRT_MEMORY,        // Display vrt memory usage
        DISPLAY_MODE_FRAME_TIME,        // Display frame time
#if 0
/* under construction !*/
/* under construction !*/
#endif
        DISPLAY_MODE_SETTINGS,          // Settings
        DISPLAY_MODE_NONE,              // No panel information
        DISPLAY_MODE_END_OF_ENUM
    };

    enum DisplayPlace
    {
        DISPLAY_PLACE_UNKNOWN = 0,
        DISPLAY_PLACE_LEFT_TOP,
        DISPLAY_PLACE_LEFT_BUTTOM,
        DISPLAY_PLACE_RIGHT_BUTTOM,
        DISPLAY_PLACE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxDebugPanel();

// Method
public:
    void handlePenEvent(VfxPenEvent &event);
    void handlePenEvent2(VfxPenEvent &event);

    // Return the current display mode
    // RETURNS: The current display mode
    DisplayMode getDisplayMode() const
    {
        return m_mode;
    }

    // get the the position of display the debug panel
    DisplayPlace getDisplayPlace() const
    {
        return m_placement;
    }

    // Set a context to be watched
    void setMonitorContext(
        VfxContext *context         // [IN] The context to be watched
    )
    {
        m_monitorContext = context;
    }
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext &dc);
    virtual VfxBool onContainPoint(const VfxPoint &point) const;
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementaion
private:
    void toggleDisplayMode();
    
    // Set display mode
    void setDisplayMode(
        DisplayMode mode            // [IN] Display mode to set
    );

    // set the the position of display the debug panel
    void setDisplayPlace(
        DisplayPlace placement
    );

// Implementation
private:
    // Constant values
    enum
    {
#if defined(__MMI_MAINLCD_480X800__)
        SINGLE_LINE_HEIGHT          = 30,
        FULL_MODE_PANEL_WIDTH       = 360,
        FULL_MODE_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*9,
        AUTO_CACHE_PANEL_WIDTH      = 360,
        AUTO_CACHE_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT*7,
        VRT_MEMORY_PANEL_WIDTH      = 360,
        VRT_MEMORY_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT*3,
        RESPONSE_TIME_PANEL_WIDTH   = 360,
        RESPONSE_TIME_PANEL_HEIGHT  = SINGLE_LINE_HEIGHT*5,
        PEN_EVENT_PANEL_WIDTH       = 360,
        PEN_EVENT_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*2,
        FRAME_TIME_PANEL_WIDTH      = 360,
        FRAME_TIME_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT,
        HW_TIME_PANEL_WIDTH         = 360,
        HW_TIME_PANEL_HEIGHT        = SINGLE_LINE_HEIGHT,
        OVER_DRAW_PANEL_WIDTH       = 225,
        OVER_DRAW_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*10,
        FPS_LITE_PANEL_WIDTH        = 60,
        FPS_LITE_PANEL_HEIGHT       = SINGLE_LINE_HEIGHT,
        SETTINGS_PANEL_WIDTH        = 165,
#else
        SINGLE_LINE_HEIGHT          = 15,
        FULL_MODE_PANEL_WIDTH       = 240,
        FULL_MODE_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*9,
        AUTO_CACHE_PANEL_WIDTH      = 240,
        AUTO_CACHE_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT*7,
        VRT_MEMORY_PANEL_WIDTH      = 240,
        VRT_MEMORY_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT*3,
        RESPONSE_TIME_PANEL_WIDTH   = 240,
        RESPONSE_TIME_PANEL_HEIGHT  = SINGLE_LINE_HEIGHT*5,
        PEN_EVENT_PANEL_WIDTH       = 240,
        PEN_EVENT_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*2,
        FRAME_TIME_PANEL_WIDTH      = 240,
        FRAME_TIME_PANEL_HEIGHT     = SINGLE_LINE_HEIGHT,
        HW_TIME_PANEL_WIDTH         = 240,
        HW_TIME_PANEL_HEIGHT        = SINGLE_LINE_HEIGHT,
        OVER_DRAW_PANEL_WIDTH       = 150,
        OVER_DRAW_PANEL_HEIGHT      = SINGLE_LINE_HEIGHT*10,
        FPS_LITE_PANEL_WIDTH        = 40,
        FPS_LITE_PANEL_HEIGHT       = SINGLE_LINE_HEIGHT,
        SETTINGS_PANEL_WIDTH        = 110,
#endif        

        SETTINGS_PANEL_HEIGHT       = TITLE_HEIGHT +
                                      HINTS_HEIGHT +
#ifndef __MTK_TARGET__
                                      MEM_DEBUG_HEIGHT +
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
                                      OVL_HEIGHT +
                                      CROSS_HEIGHT +
#if defined(GDI_9SLICE_USING_DITHERING)         
                                      SLICE9_DITHERING_HEIGHT +
#endif                                      
#if 0
/* under construction !*/
#endif
                                      CACHE_OOM_HEIGHT +
#ifdef __COSMOS_3D_V10__
                                      PAT_LOG_HEIGHT  +
                                      PAT_LOGDUMP_HEIGHT+
#endif /*__COSMOS_3D_V10__*/
                                      CACHE_SIZE_HEIGHT
    };

    DisplayMode m_mode;
    DisplayPlace m_placement;
    
    VfxTimer *m_controlUpdateTimer;

    VfxBool m_isDebugDirtyRect;    

    // Pointer to monitor context
    VfxWeakPtr <VfxContext> m_monitorContext;
    
    vrt_canvas_dbg_statistics_struct m_vrtStatistics;
#ifndef __MTK_TARGET__
    VfxBool m_vrtDbgMemory;
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
    VfxBool m_vrtHWOVL;
    VfxBool m_vrtCross;
#if defined(GDI_9SLICE_USING_DITHERING)             
    VfxBool m_9sliceDithering;
#endif
    VfxBool m_vfxLogSwitch;
    VfxBool m_cacheOOMEnable;
    VfxU32  m_cacheSize;
#ifdef __COSMOS_3D_V10__
    VfxBool m_PATLogEnable;
    VfxBool m_PATLogDumpEnable;
#endif /*__COSMOS_3D_V10__*/
    vrt_dbg_performance_hint_type m_vrtDbgSettings;
    
    vfx_sys_mem_pool_status_struct m_globalPoolStatistics;
    vfx_sys_mem_pool_status_struct m_appPoolStatistics;
    vfx_sys_mem_pool_status_struct m_vrtPoolStatistics;

    VfxDebugPenCursor *m_cursorDown;
    VfxDebugPenCursor *m_cursorUp;
    VfxU16 m_cursorPressure;
    VfxFrame *m_cursorRange;

    void onUpdateTimerTick(VfxTimer *source);

    void WriteCacheSize(vrt_u32 cacheSize);
    void ReadCacheSize(vrt_u32 &cacheSize);
};

#endif /* __VFX_DEBUG_PANEL_H__ */

