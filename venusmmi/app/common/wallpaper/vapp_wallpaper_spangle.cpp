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
 *  vapp_wallpaper_spangle.cpp
 *
 * Project:
 * --------
 *  Venus Live Wallpaper
 *
 * Description:
 * ------------
 *  Home screen wave wallpaper class
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
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_spangle.h"
#include "mmi_rp_app_venus_wallpaper_spangle_def.h"
#include "stdlib.h"
extern "C"
{
#include "gdi_primitive.h"
#include "gdi_lcd_config.h"
#include "App_mem_med.h"
#include "CustDataRes.h"
#include "lcd_sw_inc.h"
#include "vrt_canvas.h"
}

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_animation.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_image_src.h"
#include "vfx_primitive_frame.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#include "gles2\gl2ext.h"
#endif

/***************************************************************************** 
 * Function definition of utility functions
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __VENUS_3D_UI_ENGINE__
#define GL_CHECK_ERROR

#ifdef GL_CHECK_ERROR
    #define GL_CHECK(x) \
            x; \
            { \
                GLenum glError = glGetError(); \
                VRT_EXT_ASSERT(glError == GL_NO_ERROR, glError, glError, glError); \
            }
#else
    #define GL_CHECK(x)    x;
#endif
#endif

/***************************************************************************** 
 * Global constants and statics
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
static const VfxU32 SPRITE_WIDTH = 30;
static const VfxU32 SPRITE_HEIGHT = 30;
#else
static const VfxU32 SPRITE_WIDTH = 24;
static const VfxU32 SPRITE_HEIGHT = 24;
#endif

#ifdef __VENUS_3D_UI_ENGINE__
#if defined(__MMI_MAINLCD_480X800__)
static const VfxU8 BG_COLOR_R = 21;
static const VfxU8 BG_COLOR_G = 21;
static const VfxU8 BG_COLOR_B = 21;
#else
static const VfxU8 BG_COLOR_R = 66;
static const VfxU8 BG_COLOR_G = 46;
static const VfxU8 BG_COLOR_B = 2;
#endif
#endif // __VENUS_3D_UI_ENGINE__

static const VfxU32 SPRITE_BPP = 2; // we assume 16-bit RGB565
static const VfxU32 SP_ROW = 20;
static const VfxU32 SP_COL = 3;
VfxU32 VappHsSpangleDraw::SPRITE_PITCH_PIXEL = SP_COL * SpangleCellState::VARIATION_NUM * SPRITE_WIDTH;
VfxU32 VappHsSpangleDraw::SPRITE_LIST_RES_ID = VAPP_WALLPAPER_IMG_SPANGLE_SPRITE_LIST_GOLD;
static const int SCRN_H = GDI_LCD_HEIGHT;
static const int SCRN_W = GDI_LCD_WIDTH;

/***************************************************************************** 
 * Home screen UI componet: wave wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Spangle Wallpaper", VappWallpaperSpangleGold, VappWallpaper);

VappWallpaperSpangleGold::VappWallpaperSpangleGold():
    m_wallpaper(NULL),
    m_wallpaperDrawer(NULL),
    m_sparkToActivate(0),
    m_animTimeline(NULL),
    m_triggerSparkTimer(NULL),
    m_isPenDown(VFX_FALSE)
{
}

const VfxFloat VappHsSpangleDraw::FILTER_PROG_MAX = 10.f;

void VappWallpaperSpangleGold::onCreateView()
{
    // create the wallpaper "background" frame
    // it is then drawn by a frame filter.
    VFX_OBJ_CREATE(m_wallpaper, VfxFrame, this);
    VFX_OBJ_CREATE(m_wallpaperDrawer, VappHsSpangleDraw, m_wallpaper);
#ifdef __VENUS_3D_UI_ENGINE__    
    m_wallpaper->setOwnerDraw(m_wallpaperDrawer);
#else
    m_wallpaper->setFilter(m_wallpaperDrawer);
#endif
    m_wallpaper->setPropertyEffectCallback(m_wallpaper, VappHsSpangleDraw::onUpdate, &m_wallpaperDrawer, sizeof(m_wallpaperDrawer), VRT_FPE_TRIGGER_TYPE_EVERYTIME);
    m_wallpaper->setSize(getSize());
    m_wallpaper->setPos(0, 0);
    m_wallpaper->setIsUnhittable(VFX_FALSE);
    m_wallpaper->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_wallpaper->setHidden(VFX_FALSE);

#ifdef __VENUS_3D_UI_ENGINE__   
    m_wallpaperDrawer->setSize(getSize());
#endif
    
    // initilaize timeline for filter animation
    VfxFloatTimeline *timeline = NULL;
    VFX_OBJ_CREATE(timeline, VfxFloatTimeline, m_wallpaper);
    timeline->setTarget(m_wallpaper);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    timeline->setFromValue(0.0f);
    timeline->setToValue(VappHsSpangleDraw::FILTER_PROG_MAX);
    timeline->setDurationTime(VappHsSpangleDraw::DURATION);
    timeline->setAutoReversed(VFX_FALSE);
    timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_animTimeline = timeline;

    // initialize spark animations
    for(int i = 0; i < MAX_SPARK; ++i)
    {
        m_sparks[i].init(this);
    }

    // Interval Timer to show spark animation
    VfxTimer *timer = NULL;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(SPARK_INTERVAL);
    timer->m_signalTick.connect(this, &VappWallpaperSpangleGold::onTimerTick);
    m_triggerSparkTimer = timer;
}

void VappWallpaperSpangleGold::onReleaseView()
{
}


MMI_IMG_ID VappWallpaperSpangleGold::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_SPANGLE_THUMBNAIL;
}

void VappWallpaperSpangleGold::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_SPANGLEGOLD);
    return;
}

VfxBool VappWallpaperSpangleGold::onAllowSuspendOnSwipe()
{
	return VFX_FALSE;
}

void VappWallpaperSpangleGold::onWidgetDropped(VfxPoint pos, VfxControl *targetWidget)
{
    VappWallpaper::onWidgetDropped(pos, targetWidget);
    m_wallpaperDrawer->setTriggerFromScreenPos(pos);
    startSpark(pos);
}

void VappWallpaperSpangleGold::onSuspend()
{
    m_animTimeline->stop();
    m_triggerSparkTimer->stop();
    for(int i = 0; i < MAX_SPARK; ++i)
	{
	    if(!m_sparks[i].available())
        {
            m_sparks[i].stop();
        }
	}
    m_wallpaperDrawer->setSuspend(VFX_TRUE);
    VappWallpaper::onSuspend();
}

void VappWallpaperSpangleGold::onResume()
{
    m_animTimeline->start();
    m_triggerSparkTimer->start();
    m_wallpaperDrawer->setSuspend(VFX_FALSE);
    VappWallpaper::onResume();
}

VfxBool VappWallpaperSpangleGold::onPenInput(VfxPenEvent &e)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    // multi desktop configuration, we
    // track mouse usage
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        m_isPenDown = VFX_TRUE;
    }
    else if(VFX_PEN_EVENT_TYPE_UP == e.type)
    {
        m_isPenDown = VFX_FALSE;
        if(m_pageChangeInfo.m_desktopChanged)
        {
            m_pageChangeInfo.m_desktopChanged = VFX_FALSE;
            desktopChangeAnimation(m_pageChangeInfo.m_directionRight);
            return VFX_FALSE;
        }
    }
#endif
    // non-multi desktop configuration,
    // trigger animation on pen down immediately.
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
	{
        const VfxPoint &pos = e.getRelDownPos(this);
	    startSpark(pos);
        m_wallpaperDrawer->setTriggerFromScreenPos(pos);
        // trigger maximum sparks continuously. 
        // But leave 1 room for next spark.
        // This is for MAUI_02442155 : No Shine base on click position
        m_sparkToActivate = MAX_RANDOM_SPARK; 
    }
    // Bypass pen event since we're wallpaper
	return VFX_FALSE;
}

void VappWallpaperSpangleGold::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    // detect if old & new bounds belong to 2 different desktop.
    const int totalPage = getTotalPage();
    const int desktopWidth = getSize().width;
    const int oldDeskIdx = vfxMin(totalPage - 1, (int)(oldPos * totalPage));
    const int newDeskIdx = vfxMin(totalPage - 1, (int)(curPos * totalPage));
    if(oldDeskIdx == newDeskIdx)
    {
        return;
    }
    
    // page change direction
    const bool bRight = newDeskIdx > oldDeskIdx;
    
    if(m_isPenDown)
    {
        // user drag case, 
        // record desktop change, and display animation after pen up
        m_pageChangeInfo.m_desktopChanged = VFX_TRUE;
        m_pageChangeInfo.m_directionRight = bRight;
    }
    else
    {
        // Center Key case,
        // display animation directly.
        desktopChangeAnimation(bRight);
    }
    
    return;
#endif
}

void VappWallpaperSpangleGold::desktopChangeAnimation(VfxBool bRight)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    VfxPoint startPos(bRight? (SCRN_W - 1) : 0, SCRN_H / 2);
    startSpark(startPos);
    m_wallpaperDrawer->setTriggerFromScreenPos(startPos, VFX_TRUE);
    m_sparkToActivate = MAX_RANDOM_SPARK; // trigger maximum sparks continuously
#endif
}

void VappWallpaperSpangleGold::onTimerTick(VfxTimer *timer)
{
    const int margin = 10;
    startSpark(VfxPoint(rand() % (SCRN_W - margin * 2) + margin, 
                        rand() % (SCRN_H - margin * 2) + margin), 
               MAX_RANDOM_SPARK);
    if(m_sparkToActivate >= 0)
    {
        --m_sparkToActivate;
        timer->setStartDelay(SPARK_INTERVAL_FAST);
    }
    else
    {
        timer->setStartDelay(SPARK_INTERVAL);
    }
    timer->start();
}

void VappWallpaperSpangleGold::startSpark(const VfxPoint &pos, const int limitActiveCount)
{
    if(limitActiveCount)
    {
        int activeCount = 0;
        for(int i = 0; i < MAX_SPARK; ++i)
	    {
            // count active spark animation
	        if(!m_sparks[i].available())
            {
                ++activeCount;
                // direct return if there are too many
                // spark animation running.
                if(limitActiveCount <= activeCount)
                {
                    return;
                }   
            }     
        }
    }

	for(int i = 0; i < MAX_SPARK; ++i)
	{
	    if(m_sparks[i].available())
        {
            m_sparks[i].start(pos);
            return;
        }
	}
}

/***************************************************************************** 
 * SpangleCellState implemntation classes
 *****************************************************************************/

void SpangleCellState::init()
{ 
    variation = rand() % VARIATION_NUM;
    // during initialization, we use special rule of initial timing
    // to make the spangle start moving faster.
    decideNextStartTime(rand() % 10);
}

void SpangleCellState::startPatternAnimation(int stateOffset, int speedRatio)
{   
    isMoving = VFX_TRUE;
    animSpeed = speedRatio;
    stateTime = 0;
    state = (ANIM_TRIGGER_START + stateOffset) % ANIM_FRAMES;
    decideNextStartTime();
}

void SpangleCellState::decideNextStartTime(VfxMsec offset)
{
    if(0 == offset)
    {
        offset = 1000;
    }
    nextStartTime = (rand() % 50) * 100 + offset;
}

SpangleCellState::StepResult SpangleCellState::update(const VfxMsec timeOffset)
{
    // first, update time stayed in current state
    stateTime += timeOffset;
    
    // state transition based on time passed
    if(!isAnimState())
    {
        if(nextStartTime < stateTime)
        {
            // start animation
            stateTime = stateTime - nextStartTime;
            state += 1;
            isMoving = VFX_TRUE;
            decideNextStartTime();
        }        
    }
    else
    {
        updateAnimStep();
    }
    return ST_UPDATE;

}

SpangleCellState::StepResult SpangleCellState::updateAnimStep()
{
	VFX_DEV_ASSERT(isAnimState()); // Should only be called when cell is moving

    
    if(VFX_FALSE)
    {
        // TEST: force advance per frame
        //state += 1;
    }
	else
    {
        int step = stateTime / MSEC_PER_STEP;
	    if(!step)
	    {
		    return ST_NO_UPDATE;
	    }
        if(animSpeed > 1)
        {
            step *= animSpeed;
        }
	    state += step;
    }
    
	// once the animation stops, reset it to static
	if(state >= ANIM_FRAMES)
	{
		state = 0;
        isMoving = VFX_FALSE;
        animSpeed = 1;
        decideNextStartTime();
	}
	stateTime = stateTime % MSEC_PER_STEP;
	return ST_UPDATE;
}


/***************************************************************************** 
 * StateTable implemntation classes
 *****************************************************************************/
void SpangleCellStateTable::initCells()
{
    for(VfxU32 c = 0; c < CELL_COUNT; ++c)
    {
        m_table[c].init();
    }
}

const SpangleCellState& SpangleCellStateTable::getCellState(const int cellIndex) const
{
	VFX_DEV_ASSERT(cellIndex >= 0 && cellIndex < CELL_COUNT); // should not out-of-bound
	return m_table[cellIndex];
}

SpangleCellState& SpangleCellStateTable::getCell(const int row, const int col)
{
    VFX_DEV_ASSERT(row >= 0 && row < LayoutInfo::ROW);
    VFX_DEV_ASSERT(col >= 0 && col < LayoutInfo::COL);
    return m_table[row * LayoutInfo::COL + col];
}

VfxBool SpangleCellStateTable::updateState(VfxMsec timeOffset)
{
	VfxBool stateChanged = VFX_FALSE;
	for(VfxU32 c = 0; c < CELL_COUNT; ++c)
	{
		m_table[c].update(timeOffset);
	}
	return stateChanged;
}

/***************************************************************************** 
 * VappHsSpangleDraw Implementations
 *****************************************************************************/
VappHsSpangleDraw::VappHsSpangleDraw():
	m_lastUpdateTiming(0.0f),
    m_suspended(VFX_FALSE)
{
}

void VappHsSpangleDraw::onInit()
{
    prepareSpriteImage();
    
    // prepare the cells
	m_stateTable.initCells();
}


void VappHsSpangleDraw::setSuspend(VfxBool bSuspended)
{
    m_lastUpdateTiming = 0;
    m_suspended = bSuspended;
}

vrt_render_dirty_type_enum VappHsSpangleDraw::onUpdate(vrt_frame_visual_property_struct *target_frame,
                                                       const vrt_frame_visual_property_struct *watch_frame,
                                                       void *user_data,
                                                       vrt_u32 user_data_size)
{
	VappHsSpangleDraw *pThis = *reinterpret_cast<VappHsSpangleDraw**>(user_data);
    VFX_DEV_ASSERT(pThis);

    if(pThis->m_suspended)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

	const VfxFloat &timing = watch_frame->filter_timing;
    
    // We calculate the actual time offset
	const VfxMsec timeOffset = pThis->calculateOffsetTime(timing);
    pThis->m_lastUpdateTiming = timing;

    if(0 == timeOffset)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
	
    // update sprite state
    pThis->updateState(timeOffset);
    pThis->updateTriggerAnim(timeOffset);

    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}

#ifndef __VENUS_3D_UI_ENGINE__
VfxBool VappHsSpangleDraw::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    const VfxU8 tailValue = *(outBuf + (inBuf.height * inBuf.pitchBytes));
    VfxImageBuffer dstBuffer(inBuf);
    VfxRect scrnRect(0, 0, SCRN_W, SCRN_H);

    VFX_DEV_ASSERT(inBuf.width == SCRN_W);
    VFX_DEV_ASSERT(inBuf.height == SCRN_H);

    drawSprites(dstBuffer, scrnRect, scrnRect);
    const VfxU8 postTailValue = *(outBuf + (inBuf.height * inBuf.pitchBytes));
    VFX_DEV_ASSERT(tailValue == postTailValue);
    VFX_UNUSED(tailValue);
    VFX_UNUSED(postTailValue);
    return VFX_TRUE;
}
#endif

VfxBool VappHsSpangleDraw::prepareSpriteImage()
{
    // use VRT resource mechanism
    setResourceFromResId('SPR0', SPRITE_LIST_RES_ID);
    // setResourceFromPath('SPR0', VFX_WSTR("D:\\sprites.PNG"));
	return VFX_TRUE;
}

VfxU16 *VappHsSpangleDraw::getSpritePtr(const SpangleCellState &cell, const VfxImageBuffer &spriteBuf) const
{
    // The sprite tile layout looks like this:
    //    a0  a40  a80  b0
    //    a1  a41  a81  b1
    //    a2  a42  a82  b2
    //    a3  a43  a83  b3
    //    ...................
    //    a39 a79  a119 b39

    // note: we use 16-bit format, and sprites is a VfxU16 pointer.
    VFX_DEV_ASSERT(spriteBuf.colorFormat == VRT_COLOR_TYPE_RGB565);
    VfxU16 *sprites = reinterpret_cast<VfxU16*>(spriteBuf.ptr);
    
    const int mappedState = SpangleCellState::mapStateToSpriteIdx(cell.state);
    
    // looking for the actual sprite
    const VfxU32 px = cell.variation * SP_COL * SPRITE_WIDTH + (mappedState / SP_ROW) * SPRITE_WIDTH;
    const VfxU32 py = (mappedState % SP_ROW) * SPRITE_HEIGHT;
    return sprites + (py * SPRITE_PITCH_PIXEL) + px;
}

inline void VappHsSpangleDraw::drawSingleSprite(
                    gdi_img_buf_struct &dst,
                    const SpangleCellState &state, 
                    const VfxImageBuffer &spriteSourceImage) const
{
    // memory copy to draw a single sprite
    VfxU16 *pSprite = getSpritePtr(state, spriteSourceImage);
    gdi_img_buf_struct src;    
    src.color_format = GDI_IMG_BUF_COLOR_FORMAT_RGB565;
    src.ptr = reinterpret_cast<VfxU8*>(pSprite);
    src.pitch_bytes = SPRITE_BPP * SPRITE_PITCH_PIXEL;
    gdi_img_buf_copy(&dst, &src, SPRITE_WIDTH, SPRITE_HEIGHT);
    return;
}

static gdi_img_buf_color_format_enum getCF(VfxColorTypeEnum vrtCF)
{
    switch(vrtCF)
    {
        case VRT_COLOR_TYPE_RGB565:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB565;
        case VRT_COLOR_TYPE_RGB888:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB888;
        case VRT_COLOR_TYPE_PARGB6666:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB6666;
        case VRT_COLOR_TYPE_PARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;
        case VRT_COLOR_TYPE_ARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return GDI_IMG_BUF_COLOR_FORMAT_UNKNOWN;
    }
}

static VfxU32 getBPP(VfxColorTypeEnum vrtCF)
{
    switch(vrtCF)
    {   
        case VRT_COLOR_TYPE_RGB565:
            return 2;
        case VRT_COLOR_TYPE_RGB888:
            return 3;
        case VRT_COLOR_TYPE_PARGB6666:
            return 3;
        case VRT_COLOR_TYPE_PARGB8888:
            return 4;
        case VRT_COLOR_TYPE_ARGB8888:
            return 4;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return 2;
    }
}

void VappHsSpangleDraw::drawSprites(VfxImageBuffer &inBuf, const VfxRect &dstRect, const VfxRect &srcRect) const
{
    VFX_DEV_ASSERT(VRT_COLOR_TYPE_RGB565 == inBuf.colorFormat ||
                   VRT_COLOR_TYPE_RGB888 == inBuf.colorFormat); // we consider only 16-bit RGB565 case
    VFX_DEV_ASSERT(dstRect.size == srcRect.size);
    VFX_DEV_ASSERT(dstRect.origin.y >= 0);
    VFX_DEV_ASSERT(dstRect.origin.x >= 0);
    VFX_DEV_ASSERT(srcRect.origin.y >= 0);
    VFX_DEV_ASSERT(srcRect.origin.x >= 0);

    // prepare constants
    const VfxU32 &pitch = inBuf.pitchBytes;
    const VfxU32 screenWidth = vfxMin(inBuf.width, (VfxU32)(dstRect.size.width));
    const VfxU32 DST_BPP = getBPP(inBuf.colorFormat);
    // prepare struct for color filling
    gdi_img_buf_struct s;    
    s.color_format = getCF(inBuf.colorFormat);
    s.pitch_bytes = pitch;

    VfxImageBuffer spriteBuf;
    getResource('SPR0', spriteBuf);
    if(NULL == spriteBuf.ptr)
    {
        return;
    }

    // We assume the background color is defined by pixel (0, 0) of first cell sprite
    const VfxU16 bg565 = *reinterpret_cast<VfxU16*>(getSpritePtr(m_stateTable.getCellState(0), spriteBuf));
    gdi_color BG_COLOR = (GDI_IMG_BUF_COLOR_FORMAT_RGB888 == s.color_format) ? gdi_rgb565_to_rgb888(bg565) : bg565;

    // fill top "status bar" area
    VfxU8 *outBuf = inBuf.ptr + dstRect.origin.y * inBuf.pitchBytes + dstRect.origin.x * 2;
    VfxPoint paintStart(srcRect.origin);
    const VfxU16 sbarColor = BG_COLOR;
    const int sbarHeight = LayoutInfo::STATUS_BAR_HEIGHT;
    if(sbarHeight > paintStart.y)
    {
        s.ptr = outBuf;
        gdi_img_buf_fill_color(&s, sbarColor, screenWidth, sbarHeight - paintStart.y);
        paintStart.y = sbarHeight;
    }
    
    // margin of (left, top)
    // right and bottom are decided by width and height
    const int margin[2] = {LayoutInfo::LEFT_MARGIN, LayoutInfo::TOP_MARGIN};
    // fill top margin
    // TODO: consider srcRect's y position (paintStart.y)
    s.ptr = outBuf + pitch * sbarHeight;
    gdi_img_buf_fill_color(&s, BG_COLOR, screenWidth, margin[1]);

    // for each cell, draw the sprite
    const VfxU32 pad[2] = {LayoutInfo::PAD_X, LayoutInfo::PAD_Y}; // both horizontal and vertical padding between sprites
    VfxU8 *spritePos = outBuf + pitch * (sbarHeight + margin[1]);
    for(VfxU32 r = 0, cellIdx = 0; r < LayoutInfo::ROW; ++r)
    {
        // fill left margin
        s.ptr = spritePos;
        gdi_img_buf_fill_color(&s, BG_COLOR, margin[0], SPRITE_HEIGHT);
        
        VfxU8 *rowBuf = spritePos + DST_BPP * margin[0];        
        gdi_img_buf_struct dst;
        dst.color_format = s.color_format;
        for(VfxU32 c = 0; c < LayoutInfo::COL; ++c, ++cellIdx)
        {
            const SpangleCellState &cs = m_stateTable.getCellState(cellIdx);
            dst.ptr = rowBuf;
            dst.pitch_bytes = pitch;
            drawSingleSprite(dst, cs, spriteBuf);
            rowBuf += DST_BPP * SPRITE_WIDTH;

            // fill cell horizontal padding
            s.ptr = rowBuf;
            if(pad[0] > 0)
            {
                gdi_img_buf_fill_color(&s, BG_COLOR, pad[0], SPRITE_HEIGHT);
                rowBuf += DST_BPP * pad[0];
            }
        }
        // fill right margin
        s.ptr = rowBuf;
        const S32 rightMarginWidth = (inBuf.width * DST_BPP - (int)(rowBuf - spritePos)) / DST_BPP;
        if(rightMarginWidth > 0)
        {
            gdi_img_buf_fill_color(&s, BG_COLOR, rightMarginWidth, SPRITE_HEIGHT);
        }
        // advance to next sprite
        spritePos += pitch * SPRITE_HEIGHT;
        // fill vertical padding
        s.ptr = spritePos;
        if(pad[1] > 0)
        {
            gdi_img_buf_fill_color(&s, BG_COLOR, screenWidth, pad[1]);
            spritePos += pitch * pad[1];
        }
    }   

    // fill bottom margin till end
    s.ptr = spritePos;
    const VfxS32 remainHeight = inBuf.height - ((spritePos - outBuf) / pitch);
    if(remainHeight > 0)
    {
        VFX_DEV_ASSERT(s.ptr + remainHeight * DST_BPP < inBuf.ptr + (inBuf.height * inBuf.pitchBytes));
        gdi_img_buf_fill_color(&s, BG_COLOR, screenWidth, remainHeight);
    }

    return;
}

VfxMsec VappHsSpangleDraw::calculateOffsetTime(VfxFloat timing) const
{
	VfxFloat timeOffset = timing - m_lastUpdateTiming;
	if(timeOffset < 0.f)
    {
        // round trip back from FILTER_PROG_MAX
        timeOffset = (FILTER_PROG_MAX - m_lastUpdateTiming) + timing;
    }
	return static_cast<VfxMsec>(timeOffset / FILTER_PROG_MAX * DURATION);
}

VfxBool VappHsSpangleDraw::updateState(const VfxMsec timeOffset)
{
    return m_stateTable.updateState(timeOffset);
}

void VappHsSpangleDraw::setTriggerFromScreenPos(const VfxPoint &pos, VfxBool isLineShape)
{
    // convert screen coordinate to cell index
    VfxPoint cellPos;
    cellPos.x = pos.x * LayoutInfo::COL / SCRN_W;
    cellPos.y = pos.y * LayoutInfo::ROW / SCRN_H; 

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    if(isLineShape)
    {
        m_triggerInfoDesktop.reset(cellPos);
        m_triggerInfoDesktop.m_isLineShapeAnim = isLineShape;
    }
    else
    {
        m_triggerInfo.reset(cellPos);
        m_triggerInfo.m_isLineShapeAnim = isLineShape;
    }
#else
    m_triggerInfo.reset(cellPos);
    m_triggerInfo.m_isLineShapeAnim = isLineShape;
#endif
}

void VappHsSpangleDraw::animateByTriggerInfo(SpangleTriggerInfo &triggerInfo, VfxMsec timeOffset)
{
    // ripple animation style
    const VfxS32 prevStep = triggerInfo.m_progress / triggerInfo.STEP_DURATION;
    triggerInfo.m_progress += timeOffset;
    if(!triggerInfo.isActive())
    {
        triggerInfo.m_processing = VFX_FALSE;
        return;
    }
    const VfxS32 nextStep = triggerInfo.m_progress / triggerInfo.STEP_DURATION;

    // generate ripple animation by trigger cells according to time
    if(nextStep > prevStep || !triggerInfo.m_initialStepDone)
    {
        const VfxS32 &triggerCol = triggerInfo.m_sourcePos.x;
        const VfxS32 &triggerRow = triggerInfo.m_sourcePos.y;
        for(VfxU32 i = 0; i < SpangleCellStateTable::CELL_COUNT; ++i)
        {
            const VfxS32 row = i / LayoutInfo::COL;
            const VfxS32 col = i % LayoutInfo::COL;
            const VfxS32 dy = vfxAbs(int(row - triggerRow));
            const VfxS32 dx = vfxAbs(int(col-triggerCol));
            
            // By adjusting distance function,
            // we can achieve different patterns.
            const VfxS32 dist = triggerInfo.m_isLineShapeAnim ? dx : vfxSqrt(float(dx*dx + dy*dy));
            const VfxS32 speed = triggerInfo.m_isLineShapeAnim ? 3 : 2;

            // need to consider cross more than 1 step case.
            if((dist <= nextStep) && (dist > prevStep || (prevStep == 0 && dist == 0)))
            {
                m_stateTable.m_table[i].startPatternAnimation(-1 * (rand() % 6), speed);
            }
        }
    }
    
    triggerInfo.m_initialStepDone = VFX_TRUE;
}

void VappHsSpangleDraw::updateTriggerAnim(VfxMsec timeOffset)
{
    if(m_triggerInfo.isActive())
    {
        animateByTriggerInfo(m_triggerInfo, timeOffset);
    }

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    if(m_triggerInfoDesktop.isActive())
    {
        animateByTriggerInfo(m_triggerInfoDesktop, timeOffset);
    }
#endif

}

#ifdef __VENUS_3D_UI_ENGINE__
void VappHsSpangleDraw::setSize(VfxSize size)
{
    m_size = size;
}

void VappHsSpangleDraw::onInitResource()
{
    SpangleUserData *userData = &m_data;


    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    userData->programObject = 0;

    // Load the vertex/fragment shaders
// resource mode
//#if 0    
    vertexShader = loadWPShader ( GL_VERTEX_SHADER, VAPP_WALLPAPER_SPANGLE_VERTEX_SHADER );
    fragmentShader = loadWPShader ( GL_FRAGMENT_SHADER, VAPP_WALLPAPER_SPANGLE_FRAGMENT_SHADER );    
//#endif

// file mode
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
#endif    

    // Create the program object
    programObject = GL_CHECK(glCreateProgram());

    VFX_DEV_ASSERT(programObject);

    GL_CHECK( glAttachShader ( programObject, vertexShader ) );
    GL_CHECK( glAttachShader ( programObject, fragmentShader ) );

    // Link the program
    GL_CHECK( glLinkProgram ( programObject ) );
    
    // Check the link status
    GL_CHECK( glGetProgramiv ( programObject, GL_LINK_STATUS, &linked ) );

    if ( !linked ) 
    {
        GLint infoLen = 0;
        GL_CHECK( glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen) );
        if(infoLen > 1)
        {
            //glGetProgramInfoLog(programObject, infoLen, NULL, vShaderStr);
            //kal_printf("Error linking program:\n%s\n", vShaderStr);
        }    
        glDeleteProgram ( programObject );
        VFX_DEV_ASSERT(0);
    }

    userData->uFrameSizeLoc = GL_CHECK( glGetUniformLocation(programObject, "uFrameSize") );
    userData->uFrameAnchorLoc = GL_CHECK( glGetUniformLocation ( programObject, "uFrameAnchor" ) );    
    userData->aPositionLoc = GL_CHECK( glGetAttribLocation (programObject, "aPosition" ) );
    userData->aTexCoordLoc = GL_CHECK( glGetAttribLocation (programObject, "aTexCoord" ) );
    userData->uTexSampler = GL_CHECK( glGetUniformLocation ( programObject, "tex" ) );
    userData->textureId = VappWallpaper::loadResourceTexture(SPRITE_LIST_RES_ID);

    // decide background color by draw SPRITE_LIST_RES_ID
    // 3D case, we cannot decode KTX, so use layout info.
    m_bgColorB = BG_COLOR_B;
    m_bgColorG = BG_COLOR_G;
    m_bgColorR = BG_COLOR_R;
    m_bgColorA = 255;
        
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);    

    // Store the program object
    if(status == GL_FRAMEBUFFER_COMPLETE)    
        userData->programObject = programObject;

    glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
  
}

void VappHsSpangleDraw::onDeinitResource()
{
    SpangleUserData *userData = &m_data;
    
    if (userData->programObject)
    {
        glDeleteProgram(userData->programObject);
        userData->programObject = 0;
    }      
    if (userData->textureId)
    {
        glDeleteTextures(1, &userData->textureId);
        userData->textureId = 0;
    }       
}

void VappHsSpangleDraw::clearBuffer(vrt_color_type color)
{
    GL_CHECK( glClearDepthf(1.0f) );
    GL_CHECK( glClearStencil(0) );

    GL_CHECK( glClearColor(
                VRT_COLOR_GET_R(color) / 255.0f,
                VRT_COLOR_GET_G(color) / 255.0f,
                VRT_COLOR_GET_B(color) / 255.0f,
                VRT_COLOR_GET_A(color) / 255.0f) );
    
    GL_CHECK( glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT) );

#ifdef GL_FLUSH_DRAW_CALL
    GL_CHECK( glFlush() );
#endif

}

void VappHsSpangleDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    // get current viewport
    GLint viewportsize[4];    
    GL_CHECK( glGetIntegerv(GL_VIEWPORT, viewportsize) );

    //const VfxU16 BG_COLOR = *reinterpret_cast<VfxU16*>(getSpritePtr(m_stateTable.getCellState(0), spriteBuf));

    // Clear the color buffer
    clearBuffer(VRT_COLOR_MAKE(m_bgColorA, m_bgColorR, m_bgColorG, m_bgColorB));    

    for(VfxU32 r = 0, cellIdx = 0; r < LayoutInfo::ROW; ++r)
    {
        for(VfxU32 c = 0; c < LayoutInfo::COL; ++c, ++cellIdx)
        {
            SpangleUserData *userData = &m_data;
            GLfloat vVertices[12] = {0.0f};
            GLfloat vTexcoord[8] = {0.0f};        

            // ====================================================================================
            // gen the mesh for the string flow
            // the mesh will be
            //
            // 1--------0
            //  \
            //   \
            //    \
            //     \
            //      \
            //       \
            //        \
            //         \            
            // 3--------2
            //

            const int sbarHeight = LayoutInfo::STATUS_BAR_HEIGHT;
            const int margin[2] = {LayoutInfo::LEFT_MARGIN, LayoutInfo::TOP_MARGIN};
            const VfxU32 pad[2] = {LayoutInfo::PAD_X, LayoutInfo::PAD_Y};

            const VfxU32 xx = c * (pad[0] + SPRITE_WIDTH) + margin[0];
            const VfxU32 yy = sbarHeight + r * (pad[1] + SPRITE_HEIGHT) + margin[1];           
            
            vVertices[0] = ((xx) + SPRITE_WIDTH); 
            vVertices[1] = yy;
            vVertices[3] = (xx); 
            vVertices[4] = yy;
            vVertices[6] = ((xx) + SPRITE_WIDTH); 
            vVertices[7] = (yy + SPRITE_HEIGHT);
            vVertices[9] = (xx); 
            vVertices[10] = (yy + SPRITE_HEIGHT);
            
            // normalize                         
            VfxFloat anc_x = srcRect.origin.x ;
            VfxFloat anc_y = m_size.height - (srcRect.origin.y + srcRect.size.height);
            //printf("===============\n");            
            for(VfxU16 j = 0; j < 12; j++)
            {
                if(j%3 == 0)
                {
                    vVertices[j] = ((vVertices[j] - anc_x) / dstRect.size.width) * 2 - 1.0f; 
                }
                else if(j%3 == 1)
                {
                    vVertices[j] = ((vVertices[j] - anc_y - srcRect.origin.y)/ dstRect.size.height) * 2 - 1.0f;                     
                    vVertices[j] = -1 * vVertices[j];                        
                }          
                //printf("i = %d, j = %d : V[%d] = %f\n",r,c,j,vVertices[j]);                        
            }
            //printf("===============\n\n\n\n");
            // ====================================================================================
          
            // ====================================================================================
            // gen the texture coord for the string flow

            const SpangleCellState &cs = m_stateTable.getCellState(cellIdx);
            
            const int mappedState = SpangleCellState::mapStateToSpriteIdx(cs.state);
            
            // looking for the actual sprite textiure pos
            const VfxU32 px = cs.variation * SP_COL * SPRITE_WIDTH + (mappedState / SP_ROW) * SPRITE_WIDTH;
            const VfxU32 py = (mappedState % SP_ROW) * SPRITE_HEIGHT;                     
            
            vTexcoord[0] = px + SPRITE_WIDTH;
            vTexcoord[1] = py;
            vTexcoord[2] = px;
            vTexcoord[3] = py;
            vTexcoord[4] = px + SPRITE_WIDTH;
            vTexcoord[5] = py + SPRITE_HEIGHT;
            vTexcoord[6] = px;
            vTexcoord[7] = py + SPRITE_HEIGHT;            


            // normalize 
            for(VfxU16 j = 0; j < 8; j++)
            {
                if(j%2 == 0)
                {
                    vTexcoord[j] = (vTexcoord[j] / SPRITE_PITCH_PIXEL); 
                }
                else
                {
                    vTexcoord[j] = (vTexcoord[j] / (SP_ROW*SPRITE_HEIGHT));                     
                }
                printf("r = %d, c = %d : V[%d] = %f\n",r,c,j,vTexcoord[j]);                     
            }
            // ====================================================================================         

            // Set the viewport
            glViewport ( 0, 0, dstRect.size.width, dstRect.size.height );

            // Use the program object
            glUseProgram ( userData->programObject );

            GL_CHECK( glViewport (dstRect.origin.x, dstBuffer.height - (dstRect.origin.y + dstRect.size.height),
                        dstRect.size.width, dstRect.size.height ) );

            GL_CHECK( glUniform2f(userData->uFrameSizeLoc, (GLfloat)m_size.width , (GLfloat)m_size.height) );
            GL_CHECK( glUniform2f(userData->uFrameAnchorLoc, (GLfloat)srcRect.origin.x  , (GLfloat)(m_size.height - (srcRect.origin.y + srcRect.size.height))) );

            // Load the vertex data
            GL_CHECK( glVertexAttribPointer (userData->aPositionLoc, 3, GL_FLOAT, GL_FALSE, 0, vVertices ));
            GL_CHECK( glEnableVertexAttribArray (userData->aPositionLoc ));

            GL_CHECK( glVertexAttribPointer(userData->aTexCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, vTexcoord) );
            GL_CHECK( glEnableVertexAttribArray(userData->aTexCoordLoc) );
  
            GL_CHECK( glActiveTexture ( GL_TEXTURE0 ) );
            GL_CHECK( glBindTexture ( GL_TEXTURE_2D, userData->textureId) );
            GL_CHECK( glUniform1i ( userData->uTexSampler, 0 ) );

            glVertexAttrib4f ( 1, 0.0, 1.0, 0.0, 1.0 );
            glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );        

        }
    }
    
    // set back the original view port
    GL_CHECK( glViewport( viewportsize[0], viewportsize[1], viewportsize[2], viewportsize[3]) );

}

vrt_bool VappHsSpangleDraw::isUsingGLAPI() const
{
    return VRT_TRUE;
}

GLuint VappHsSpangleDraw::loadWPShader (GLenum type, const U16 resId)
{
    GLuint shader;
    GLint compiled;
    U32 size = 0;
    char *shaderSrc = NULL;
    vrt_bool isBinary = VRT_FALSE;
    GLenum glError;

    // Create the shader object
    shader = glCreateShader ( type );

    if ( shader == 0 )
    {
        return 0;
    }

    // TODO: implement vrt_sys_res_shader_lock
    //shaderSrc = (vrt_char *)vrt_sys_res_shader_lock(vrtshader->getResourceId());

    const char *start = (const char*)GetBinary(resId);
    if (start == NULL)
    {
        return 0;
    }
    /* first byte is type, 2~5 is size */
    const unsigned char *header = (const unsigned char*)start;
    size = *((U32*)(header+1));
    //   size = header[1] | header[2] << 8 | header[3] << 16 | header[4] << 24;
    start += 8;

#ifndef __MTK_TARGET__
    char *source = (char *)applib_asm_alloc_anonymous_nc(sizeof(char) * (size + 1));
    memcpy(source, start, size);

    // WORKAROUND: add null-terminal after source from res
    source[size] = 0;
    shaderSrc = source;
#else
    shaderSrc = (vrt_char*)start;
    isBinary = VRT_TRUE;
#endif

    if (isBinary)
    {
        GLenum MALI_SHADER_BINARY_ARM = 0x8F60;
        glShaderBinary (1, &shader, MALI_SHADER_BINARY_ARM, (const void* )shaderSrc, size);
        glError = glGetError();
        VRT_DEV_ASSERT(glError == GL_NO_ERROR);
    }
    else
    {
        // Load the shader source
        glShaderSource ( shader, 1, (const char **)&shaderSrc, NULL );
        glError = glGetError();
        VRT_DEV_ASSERT(glError == GL_NO_ERROR);

        // Compile the shader
        glCompileShader ( shader );
        glError = glGetError();
        VRT_DEV_ASSERT(glError == GL_NO_ERROR);

        // Check the compile status
        glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
        glError = glGetError();
        VRT_DEV_ASSERT(glError == GL_NO_ERROR);

        if ( !compiled )
        {
            glDeleteShader ( shader );
            glError = glGetError();
            VRT_DEV_ASSERT(glError == GL_NO_ERROR);

            return 0;
        }
    }

    return shader;

}

GLuint VappHsSpangleDraw::loadWPShaderFileMode ( GLenum type, const char *shaderSrc )
{
    GLuint shader;
    GLint compiled;

    // Create the shader object
    shader = glCreateShader ( type );

    if ( shader == 0 )
    return 0;

    // Load the shader source
    glShaderSource ( shader, 1, &shaderSrc, NULL );

    // Compile the shader
    glCompileShader ( shader );

    // Check the compile status
    glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

    if ( !compiled ) 
    {
      glDeleteShader ( shader );
      return 0;
    }

    return shader;
}

#endif

/***************************************************************************** 
 * SpangleTriggerInfo implemntation class
 * a class stores animation trigger state
 *****************************************************************************/
SpangleTriggerInfo::SpangleTriggerInfo():
      m_progress(0), 
      m_duration(0),
      m_inputTime(0.0f), 
      m_processing(VFX_FALSE), 
      m_initialStepDone(VFX_FALSE),
      m_isLineShapeAnim(VFX_FALSE)
{
}

void SpangleTriggerInfo::reset(const VfxPoint &pos)
{
    m_sourcePos.x = pos.x;
    m_sourcePos.y = pos.y;
    m_processing = VFX_TRUE;
    m_progress = 0;
    m_isLineShapeAnim = VFX_FALSE;
    // duration must be long enough to cover entire table.
    // so we multiply by maximum dimension of the table.
    m_duration = STEP_DURATION * (LayoutInfo::COL + LayoutInfo::ROW);
    m_initialStepDone = VFX_FALSE;
}

VfxBool SpangleTriggerInfo::isActive() const
{
    return m_processing && (m_progress <= m_duration);
}

/***************************************************************************** 
 * SpangleSparkAnimation implemntation class
 * a class representing "sparkling" animation and image
 *****************************************************************************/
void VappHsSpangleSparkAnim::init(VfxFrame *pParent)
{
    // the spark image 
    VfxImageSrc imgSpark;
    imgSpark.setResId(VAPP_WALLPAPER_IMG_SPANGLE_SPARK);
    VFX_OBJ_CREATE(m_spark, VfxImageFrame, pParent);
    m_spark->setImgContent(imgSpark);
    m_spark->setIsOpaque(VFX_FALSE);
	m_spark->setAnchor(0.5f, 0.5f);
    m_spark->setHidden(VFX_TRUE);
    m_spark->setIsUnhittable(VFX_TRUE);
    m_spark->setAutoAnimate(VFX_FALSE); // we'll use timeline to animate it

    
    // add into the animation    
    VFX_OBJ_CREATE(m_anim, VfxAnimation, pParent);

    // rotating the spark
    const VfxMsec ROT_DURATION = 2000;
    VfxFloatTimeline *pRotation;
    VFX_OBJ_CREATE(pRotation, VfxFloatTimeline, m_anim);
    pRotation->setFromValue(VFX_DEG_TO_RAD(0));
    pRotation->setToValue(VFX_DEG_TO_RAD(90));
    pRotation->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    pRotation->setAutoReversed(VFX_FALSE);
    pRotation->setDurationTime(ROT_DURATION);
    pRotation->setRepeatCount(1);
    pRotation->setTarget(m_spark);
    pRotation->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ);
    
    // spark flash-in
    const VfxMsec IN_DURATION = 300;
    const VfxMsec OUT_DURATION = 1700;
    VfxFloatTimeline *pOpacityIn;
    VFX_OBJ_CREATE(pOpacityIn, VfxFloatTimeline, m_anim);
    pOpacityIn->setFromValue(0.0f);
    pOpacityIn->setToValue(1.0f);
    pOpacityIn->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    pOpacityIn->setAutoReversed(VFX_FALSE);
    pOpacityIn->setDurationTime(IN_DURATION);
    pOpacityIn->setTarget(m_spark);
    pOpacityIn->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);

    // spark flash-out
    VfxFloatTimeline *pOpacityOut;
    VFX_OBJ_CREATE(pOpacityOut, VfxFloatTimeline, m_anim);
    pOpacityOut->setFromValue(1.0f);
    pOpacityOut->setToValue(0.0f);
    pOpacityOut->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    pOpacityOut->setAutoReversed(VFX_FALSE);
    pOpacityOut->setDurationTime(OUT_DURATION);
    pOpacityOut->setStartDelay(IN_DURATION);
    pOpacityOut->setTarget(m_spark);
    pOpacityOut->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);

    // notify status update after spark fade-out
	pOpacityOut->m_signalStopped.connect(this, &VappHsSpangleSparkAnim::onTimelineStopped);
}

void VappHsSpangleSparkAnim::start(const VfxPoint &pos)
{
	m_spark->setHidden(VFX_FALSE);
	m_spark->setPos(pos);
	m_anim->start();
}

void VappHsSpangleSparkAnim::stop()
{
    m_spark->setHidden(VFX_TRUE);
    m_anim->stop();
}

void VappHsSpangleSparkAnim::onTimelineStopped(VfxBaseTimeline *timeline, VfxBool stopped)
{
    m_anim->stop();
    m_spark->setHidden(VFX_TRUE);
}

#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__ */
