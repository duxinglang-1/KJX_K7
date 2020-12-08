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
 *  vapp_wallpaper_matrix.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "stdlib.h"
#include "vapp_wallpaper_matrix.h"
#include "mmi_rp_app_venus_wallpaper_matrix_def.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"
#include "vapp_hs_def.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#include "gles2\gl2ext.h"
#endif

extern "C"
{
#include "gdi_primitive.h"
}

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

static const VfxU32 SCREEN_WIDTH = GDI_LCD_WIDTH;
static const VfxU32 SCREEN_HEIGHT = GDI_LCD_HEIGHT;

#if defined(__MMI_MAINLCD_240X320__)
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxS32 WALLPAPER_WIDTH = 512;
#else
static const VfxS32 WALLPAPER_WIDTH = 240;
#endif  /* VAPP_HS_CFG_MULTI_DESKTOP */
static const VfxS32 CHAR_WIDTH = 16;
static const VfxS32 CHAR_HEIGHT = 16;
static const VfxS32 CHAR_NUM = 20;

#elif defined(__MMI_MAINLCD_240X400__)
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxS32 WALLPAPER_WIDTH = 512;
#else
static const VfxS32 WALLPAPER_WIDTH = 240;
#endif  /* VAPP_HS_CFG_MULTI_DESKTOP */
static const VfxS32 CHAR_WIDTH = 16;
static const VfxS32 CHAR_HEIGHT = 16;
static const VfxS32 CHAR_NUM = 26;

#elif defined(__MMI_MAINLCD_320X480__)
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxS32 WALLPAPER_WIDTH = 684;
#else
static const VfxS32 WALLPAPER_WIDTH = 324;
#endif  /* VAPP_HS_CFG_MULTI_DESKTOP */
static const VfxS32 CHAR_WIDTH = 18;
static const VfxS32 CHAR_HEIGHT = 18;
static const VfxS32 CHAR_NUM = 20;

#elif defined(__MMI_MAINLCD_480X800__)
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxS32 WALLPAPER_WIDTH = 1024;
#else
static const VfxS32 WALLPAPER_WIDTH = 480;
#endif  /* VAPP_HS_CFG_MULTI_DESKTOP */
static const VfxS32 CHAR_WIDTH = 32;
static const VfxS32 CHAR_HEIGHT = 32;
static const VfxS32 CHAR_NUM = 25;

#else
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxS32 WALLPAPER_WIDTH = 684;
#else
static const VfxS32 WALLPAPER_WIDTH = 324;
#endif  /* VAPP_HS_CFG_MULTI_DESKTOP */
static const VfxS32 CHAR_WIDTH = 18;
static const VfxS32 CHAR_HEIGHT = 18;
static const VfxS32 CHAR_NUM = 20;

#endif  /* __MMI_MAINLCD_XXXXXXX__ */

static const VfxS32 STRING_WIDTH = CHAR_WIDTH;
static const VfxS32 STRING_HEIGHT = CHAR_NUM * CHAR_HEIGHT;
static const VfxS32 STRING_NUM = CHAR_NUM;
static const VfxS32 STRING_PITCH_PIXEL = STRING_NUM * STRING_WIDTH;
static const VfxS32 BPP = 2;                    // Byte per pixel
static const VfxS32 STRING_ANIM_DURATION = 100; // animation step duration of each string
static const VfxS32 STRING_CREATE_RATE = 2;     // 2->10, high->low


/***************************************************************************** 
 * VappWallpaperMatrix implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Matrix Wallpaper", VappWallpaperMatrix, VappWallpaper);

VappWallpaperMatrix::VappWallpaperMatrix():
    m_wallpaper(NULL),
    m_timer(NULL),
    m_timeline(NULL)
{
}

void VappWallpaperMatrix::onCreateView()
{
    VFX_OBJ_CREATE(m_wallpaper, VfxFrame, this);
    VFX_OBJ_CREATE(m_drawer, VfxMatrixDrawer, m_wallpaper);
#ifdef __VENUS_3D_UI_ENGINE__
    m_wallpaper->setOwnerDraw(m_drawer);
#else
    m_wallpaper->setFilter(m_drawer);
#endif
    m_wallpaper->setSize(WALLPAPER_WIDTH, SCREEN_HEIGHT);
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    m_wallpaper->setPos(0, 0);
#else
    m_wallpaper->setPos(-2, 0);
#endif
    m_wallpaper->setBgColor(VFX_COLOR_BLACK);
    m_wallpaper->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_drawer->setStringFow(m_strFlows);
#ifdef __VENUS_3D_UI_ENGINE__   
    m_drawer->setSize(getSize());
#endif

    m_wallpaper->setPropertyEffectCallback(m_wallpaper, VfxMatrixDrawer::onUpdate, &m_drawer, sizeof(m_drawer), VRT_FPE_TRIGGER_TYPE_EVERYTIME);
    m_wallpaper->setAutoAnimate(VFX_TRUE);
       
    // Initialize base timer
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(0);
    m_timer->setDuration(STRING_ANIM_DURATION);
    m_timer->m_signalTick.connect(this, &VappWallpaperMatrix::onTimerTick);
    
    VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, m_wallpaper);
    m_timeline->setTarget(m_wallpaper);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_timeline->setFromValue(1);
    m_timeline->setToValue(10);
    m_timeline->setDuration(1000);  // 10 FPS
    m_timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
}

void VappWallpaperMatrix::onReleaseView()
{
}

MMI_IMG_ID VappWallpaperMatrix::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_MATRIX_THUMBNAIL;
}

void VappWallpaperMatrix::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_MATRIX);
    return;
}

void VappWallpaperMatrix::onWidgetDropped(VfxPoint pos, VfxControl *targetWidget)
{
    VappWallpaper::onWidgetDropped(pos, targetWidget);
}

VfxBool VappWallpaperMatrix::onPenInput(VfxPenEvent &e)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type || VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
        const VfxPoint &pos = e.getRelPos(this);
        createFocusStringFlow(pos.x - m_wallpaper->getPos().x);
    }
    return VFX_FALSE;
}

void VappWallpaperMatrix::onSuspend()
{
    m_timer->stop();
    m_timeline->stop();
    m_drawer->suspend();
}

void VappWallpaperMatrix::onResume()
{
    m_timer->start();
    m_timeline->start();
    m_drawer->resume();
}

void VappWallpaperMatrix::onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos)
{

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)

    if (m_wallpaper)
    {
        VfxSize size = m_wallpaper->getBounds().size;
        VfxPoint pos = m_wallpaper->getPos();

        VfxS32 b = size.width - SCREEN_WIDTH;
        if (b > 0)
        {
            // calculate the bounds of the wallpaper
            const VfxS32 m = vfxMin(b, vfxMax((VfxS32)(b * curPos), (VfxS32)0));

            // Change wallpaper position
            pos.x = -m;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

            m_wallpaper->setPos(pos);

            VfxAutoAnimate::commit();
        }
    }
#endif
}

void VappWallpaperMatrix::onTimerTick(VfxTimer *timer)
{
    createStringFlow();
}

inline void VappWallpaperMatrix::doCreateStringFlow(const VfxPoint pos, const VfxS32 animStep)
{
    for (VfxS32 i = 0; i < MAX_STRING_FLOW_NUM; i++)
    {
        if (m_strFlows[i].isAvailable())
        {
            m_strFlows[i].init(pos, rand()%CHAR_NUM, animStep);
            m_strFlows[i].run();
            break;
        }
    }
    return;
}

void VappWallpaperMatrix::createStringFlow()
{
    const VfxS32 strNum = m_wallpaper->getSize().width / STRING_WIDTH + 1;
    const VfxS32 randNum1 = rand();
    VfxS32 randNum2 = 0;

    // STRING_CREATE_RATE decides the amount of created strings
    if (randNum1 % STRING_CREATE_RATE == 0)
    {
        // Create 0~2 string at one time
        const VfxS32 newStrCount = 1 + randNum1 % 4;
        for (VfxS32  i = 0; i < newStrCount; i++)
        {
            randNum2 = rand();
            doCreateStringFlow(VfxPoint((randNum2 % strNum) * STRING_WIDTH, -STRING_HEIGHT - (randNum2 % 8) * CHAR_HEIGHT));
        }
    }
}

void VappWallpaperMatrix::createFocusStringFlow(const VfxS32 x)
{
    const VfxS32 newx = int(x / STRING_WIDTH) * STRING_WIDTH;
    const VfxS32 strNum = getSize().width / STRING_WIDTH;
    const VfxS32 randNum1 = rand();
    VfxS32 randNum2 = rand();
    VfxS32 randNum3 = 0;
    VfxS32 sign = 1;
    VfxS32 shiftX = 0;
    const VfxS32 newStrCount = randNum1 % 2 + 1;

    doCreateStringFlow(VfxPoint(newx, -STRING_HEIGHT - (randNum2 % 3) * CHAR_HEIGHT), randNum2 % 2 + 1);
    
    for (VfxS32 i = 0; i < newStrCount + 1; i++)
    {
        randNum2 = rand();
        randNum3 = rand();

        if (randNum2 % 2 == 0)
        {
            sign = -1;
        }
        shiftX = sign * (randNum3 % 4) * STRING_WIDTH;
        VfxS32 xPos = newx + shiftX;

        if (xPos < 0 || xPos > SCREEN_WIDTH)
        {
            continue;
        }

        doCreateStringFlow(VfxPoint(xPos, -STRING_HEIGHT - (randNum2 % 3) * CHAR_HEIGHT));
    }

}


/***************************************************************************** 
 * MatrixStringFlowInfo implementaton
 *****************************************************************************/

void MatrixStringFlowInfo::init(VfxPoint startPos, VfxS32 startStrIdx, VfxS32 animStep)
{
    m_startStrIdx = startStrIdx;
    m_strIdx = 0;
    m_pos = startPos;
    m_animStep = animStep;
    m_lastUpdateTiming = -1;
    m_animState = AS_IDLE;
}

void MatrixStringFlowInfo::run()
{
    m_animState = AS_RUNNING;
}


/***************************************************************************** 
 * VfxMatrixDrawer implementaton
 *****************************************************************************/
void VfxMatrixDrawer::onInit()
{
#ifdef __VENUS_3D_UI_ENGINE__
    VfxOwnerDraw::onInit();
#else
    VfxFrameFilter::onInit();
#endif
    loadImage();
}

void VfxMatrixDrawer::onDeinit()
{
#ifdef __VENUS_3D_UI_ENGINE__
    VfxOwnerDraw::onDeinit();
#else
    VfxFrameFilter::onDeinit();
#endif
    m_strFlows = NULL;
}

vrt_render_dirty_type_enum VfxMatrixDrawer::onUpdate(vrt_frame_visual_property_struct *target_frame,
                                                   const vrt_frame_visual_property_struct *watch_frame,
                                                   void *user_data,
                                                   vrt_u32 user_data_size)
{
    VfxMatrixDrawer *drawer = *reinterpret_cast<VfxMatrixDrawer**>(user_data);
    VFX_DEV_ASSERT(drawer);

    // Return if under suspended
    if (drawer->isSuspend())
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

#ifdef __VENUS_3D_UI_ENGINE__
    VfxS32 t = VfxS32(watch_frame->filter_timing);
    if (t != drawer->m_timing)
    {
        VfxS32 timingOffset = t > drawer->m_timing ? t - drawer->m_timing : 9 - drawer->m_timing + t;
        drawer->m_timing = t;

        drawer->m_updateTiming = (drawer->m_lastUpdateTiming + timingOffset) % 10000;
    }
#endif

    VfxS32 updateTiming = drawer->getUpdateTiming();
    VfxS32 lastUpdateTiming = drawer->getLastUpdateTiming();
    VfxS32 timingOffset = 0;

    // Check timing if need to be updated
    if (updateTiming == lastUpdateTiming)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
    
    for (VfxS32 i = 0; i < VappWallpaperMatrix::MAX_STRING_FLOW_NUM; i++)
    {
        if (drawer->m_strFlows[i].m_animState == MatrixStringFlowInfo::AS_RUNNING)
        {
            // Stop update this string flow if going out of screen
            if (drawer->m_strFlows[i].m_pos.y > VfxS32(SCREEN_HEIGHT))
            {
                drawer->m_strFlows[i].m_animState = MatrixStringFlowInfo::AS_IDLE;
                drawer->m_strFlows[i].m_lastUpdateTiming = -1;
                continue;
            }

            if (drawer->m_strFlows[i].m_lastUpdateTiming == -1)
            {
                drawer->m_strFlows[i].m_lastUpdateTiming = lastUpdateTiming;
            }

            timingOffset = updateTiming >= drawer->m_strFlows[i].m_lastUpdateTiming ? updateTiming - drawer->m_strFlows[i].m_lastUpdateTiming : 9999 - drawer->m_strFlows[i].m_lastUpdateTiming + updateTiming; // consider wrap around case
            drawer->m_strFlows[i].m_pos.y += CHAR_HEIGHT * drawer->m_strFlows[i].m_animStep * timingOffset;
            drawer->m_strFlows[i].m_strIdx += (drawer->m_strFlows[i].m_animStep * timingOffset) % CHAR_NUM;
            drawer->m_strFlows[i].m_lastUpdateTiming = updateTiming;
        }
    }

    drawer->setLastUpdateTiming(updateTiming);

    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}

#ifndef __VENUS_3D_UI_ENGINE__
VfxBool VfxMatrixDrawer::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    VfxS32 t = VfxS32(timing);
    if (t != m_timing)
    {
        VfxS32 timingOffset = t > m_timing ? t - m_timing : 9 - m_timing + t;
        m_timing = t;

        m_updateTiming = (m_lastUpdateTiming + timingOffset) % 10000;
    }
    drawImage(outBuf, inBuf);
    return VFX_TRUE;
}
#endif

VfxBool VfxMatrixDrawer::loadImage()
{
    setResourceFromResId('STR1', VAPP_WALLPAPER_IMG_MATRIX_STRING_LIST);
    return VFX_TRUE;
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

inline void VfxMatrixDrawer::drawImage(VfxU8 *outBuf, const VfxImageBuffer &inBuf) const
{
    VfxImageBuffer imageBuf;
    getResource('STR1', imageBuf);
    
    VFX_DEV_ASSERT(imageBuf.ptr);
    VfxU16 *bufferSrc = reinterpret_cast<VfxU16*>(imageBuf.ptr);

    gdi_img_buf_struct src;
    src.color_format = getCF(imageBuf.colorFormat);
    src.pitch_bytes = STRING_PITCH_PIXEL * BPP;

    VfxU16 *bufferDst = reinterpret_cast<VfxU16*>(outBuf);
    const VfxU32 DST_BPP = getBPP(inBuf.colorFormat);
    gdi_img_buf_struct dst;
    dst.color_format = getCF(inBuf.colorFormat);
    dst.pitch_bytes = inBuf.pitchBytes;

    VfxFrame *p = reinterpret_cast<VfxFrame*>(getParent());
    VfxS32 offsetX = -p->forceGetPos().x;
    
    for (VfxS32 i = 0; i < VappWallpaperMatrix::MAX_STRING_FLOW_NUM; i++)
    {
        MatrixStringFlowInfo *sfInfo = &m_strFlows[i];
        if (sfInfo->m_animState == MatrixStringFlowInfo::AS_RUNNING)
        {
            if (offsetX < sfInfo->m_pos.x + STRING_WIDTH && sfInfo->m_pos.x < offsetX + SCREEN_WIDTH)
            {
                // Check if the string flow is going out the right side of wallpaper frame
                const VfxS32 copyStrWidth = VRT_MIN(WALLPAPER_WIDTH - sfInfo->m_pos.x, STRING_WIDTH);

                if (sfInfo->m_pos.y < 0 && sfInfo->m_pos.y + STRING_HEIGHT > 0) // Upper part is out of screen
                {
                    VfxS32 outCharNum = -sfInfo->m_pos.y / CHAR_HEIGHT;
                    VfxS32 idx = (sfInfo->m_startStrIdx + sfInfo->m_strIdx) % CHAR_NUM;
                    src.ptr = reinterpret_cast<VfxU8*>(bufferSrc + idx * STRING_WIDTH + outCharNum * CHAR_HEIGHT * STRING_WIDTH * STRING_NUM);
                    dst.ptr = reinterpret_cast<VfxU8*>(bufferDst) + sfInfo->m_pos.x * DST_BPP;
                    gdi_img_buf_copy(&dst, &src, copyStrWidth, (CHAR_NUM - outCharNum) * CHAR_HEIGHT);
                }
                else if (sfInfo->m_pos.y < SCREEN_HEIGHT && sfInfo->m_pos.y + STRING_HEIGHT > SCREEN_HEIGHT)    // Lower part is out of screen
                {
                    VfxS32 idx = (sfInfo->m_startStrIdx + sfInfo->m_strIdx) % CHAR_NUM;
                    src.ptr = reinterpret_cast<VfxU8*>(bufferSrc + idx * STRING_WIDTH);
                    dst.ptr = reinterpret_cast<VfxU8*>(bufferDst) + (sfInfo->m_pos.x + sfInfo->m_pos.y * WALLPAPER_WIDTH) * DST_BPP;
                    gdi_img_buf_copy(&dst, &src, copyStrWidth, SCREEN_HEIGHT - sfInfo->m_pos.y);
                }
                else if (sfInfo->m_pos.y >= 0 && sfInfo->m_pos.y + STRING_HEIGHT <= SCREEN_HEIGHT)  // Totally in the screen
                {
                    VfxS32 idx = (sfInfo->m_startStrIdx + sfInfo->m_strIdx) % CHAR_NUM;
                    src.ptr = reinterpret_cast<VfxU8*>(bufferSrc + idx * STRING_WIDTH);
                    dst.ptr = reinterpret_cast<VfxU8*>(bufferDst) + (sfInfo->m_pos.x + sfInfo->m_pos.y * WALLPAPER_WIDTH) * DST_BPP;
                    gdi_img_buf_copy(&dst, &src, copyStrWidth, STRING_HEIGHT);
                }
            }
        }
    }
}

void VfxMatrixDrawer::setStringFow(MatrixStringFlowInfo *strFlows)
{
    m_strFlows = strFlows;
}

void VfxMatrixDrawer::suspend()
{   
    m_isSuspended = VFX_TRUE;
}

void VfxMatrixDrawer::resume()
{   
    m_isSuspended = VFX_FALSE;
}

VfxBool VfxMatrixDrawer::isSuspend() const
{
    return m_isSuspended;
}

VfxFloat VfxMatrixDrawer::getTiming() const
{
    return m_timing;
}

void VfxMatrixDrawer::setUpdateTiming(const VfxS32 timing)
{
    m_updateTiming = timing;
}

VfxFloat VfxMatrixDrawer::getUpdateTiming() const
{
    return m_updateTiming;
}

void VfxMatrixDrawer::setLastUpdateTiming(const VfxS32 timing)
{
    m_lastUpdateTiming = timing;
}

VfxFloat VfxMatrixDrawer::getLastUpdateTiming() const
{
    return m_lastUpdateTiming;
}

#ifdef __VENUS_3D_UI_ENGINE__
void VfxMatrixDrawer::setSize(VfxSize size)
{
    m_size = size;
}

GLuint VfxMatrixDrawer::loadWPShader (GLenum type, const U16 resId)
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

GLuint VfxMatrixDrawer::loadWPShaderFileMode ( GLenum type, const char *shaderSrc )
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

GLuint VfxMatrixDrawer::CreateWPTexture2D(const U16 resId, GLenum type)
{
    // Texture object handle
    GLuint textureId;

    GLenum error;

    // Use tightly packed data
    glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

    // Generate a texture object
    glGenTextures ( 1, &textureId );

    // Bind the texture object
    glBindTexture ( GL_TEXTURE_2D, textureId );


    S32 imgWidth, imgHeight;
    PU8 mem_buffer;

    gdi_image_get_dimension_id(resId, &imgWidth, &imgHeight);

    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE imgLayer = GDI_LAYER_EMPTY_HANDLE;

    mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
    if(NULL == mem_buffer)
    {
        return 0;
    }
    res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32,
                                                      0, 0,
                                                      imgWidth,
                                                      imgHeight,
                                                      &imgLayer,
                                                      (PU8)mem_buffer,
                                                      imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
    gdi_layer_push_and_set_active(imgLayer);
    gdi_image_draw_id(0, 0, resId);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(imgLayer);

    glTexImage2D ( GL_TEXTURE_2D, 0, type, imgWidth, imgHeight, 0, type, GL_UNSIGNED_BYTE, mem_buffer );
    applib_asm_free_anonymous(mem_buffer);

    // Set the filtering mode
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    error = glGetError();

    return textureId;
}

void VfxMatrixDrawer::onInitResource()
{
    MatrixUserData *userData = &m_data;

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    userData->programObject = 0;

    // Load the vertex/fragment shaders
// resource mode
//#if 0    
    vertexShader = loadWPShader ( GL_VERTEX_SHADER, VAPP_WALLPAPER_MATRIX_VERTEX_SHADER );
    fragmentShader = loadWPShader ( GL_FRAGMENT_SHADER, VAPP_WALLPAPER_MATRIX_FRAGMENT_SHADER );    
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
    userData->textureId = VappWallpaper::loadResourceTexture(VAPP_WALLPAPER_IMG_MATRIX_STRING_LIST);
        
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);    

    // Store the program object
    if(status == GL_FRAMEBUFFER_COMPLETE)    
        userData->programObject = programObject;

    glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f ); 
}

void VfxMatrixDrawer::onDeinitResource()
{
    MatrixUserData *userData = &m_data;
    
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

void VfxMatrixDrawer::clearBuffer(vrt_color_type color)
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

void VfxMatrixDrawer::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    // get current viewport
    GLint viewportsize[4];    
    GL_CHECK( glGetIntegerv(GL_VIEWPORT, viewportsize) );
    
    // Clear the color buffer
    clearBuffer(VRT_COLOR_MAKE(255, 0, 0, 0));    

    for (VfxS32 i = 0; i < VappWallpaperMatrix::MAX_STRING_FLOW_NUM; i++)
    {
        MatrixStringFlowInfo *sfInfo = &m_strFlows[i];
        if (sfInfo->m_animState == MatrixStringFlowInfo::AS_RUNNING)
        {

            VfxFrame *p = reinterpret_cast<VfxFrame*>(getParent());
            VfxS32 offsetX = -p->forceGetPos().x;            

            if (offsetX < sfInfo->m_pos.x + STRING_WIDTH && sfInfo->m_pos.x < offsetX + SCREEN_WIDTH)
            {

                MatrixUserData *userData = &m_data;
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
                
                vVertices[0] = ((sfInfo->m_pos.x) + STRING_WIDTH); 
                vVertices[1] = sfInfo->m_pos.y;
                vVertices[3] = (sfInfo->m_pos.x); 
                vVertices[4] = sfInfo->m_pos.y;
                vVertices[6] = ((sfInfo->m_pos.x) + STRING_WIDTH); 
                vVertices[7] = (sfInfo->m_pos.y + STRING_HEIGHT);
                vVertices[9] = (sfInfo->m_pos.x); 
                vVertices[10] = (sfInfo->m_pos.y + STRING_HEIGHT);

                // normalize                         
                VfxFloat anc_x = srcRect.origin.x ;
                VfxFloat anc_y = m_size.height - (srcRect.origin.y + srcRect.size.height);
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
                }
                // ====================================================================================


                // ====================================================================================
                // gen the texture coord for the string flow

                VfxS32 startP = (sfInfo->m_startStrIdx + sfInfo->m_strIdx) % CHAR_NUM;
                VfxFloat xx = ((startP * 1.0f) / CHAR_NUM) * SCREEN_HEIGHT;
                
                vTexcoord[0] = xx + STRING_WIDTH;
                vTexcoord[1] = 0;
                vTexcoord[2] = xx;
                vTexcoord[3] = 0;
                vTexcoord[4] = xx + STRING_WIDTH;
                vTexcoord[5] = STRING_HEIGHT;
                vTexcoord[6] = xx;
                vTexcoord[7] = STRING_HEIGHT;            


                // normalize 
                for(VfxU16 j = 0; j < 8; j++)
                {
                    if(j%2 == 0)
                    {
                        vTexcoord[j] = (vTexcoord[j] / SCREEN_HEIGHT); 
                    }
                    else
                    {
                        vTexcoord[j] = (vTexcoord[j] / STRING_HEIGHT);                     
                    }
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
      
                GL_CHECK( glBindTexture ( GL_TEXTURE_2D, userData->textureId) );

                glVertexAttrib4f ( 1, 0.0, 1.0, 0.0, 1.0 );
                glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );
            }
        }
    }
    
    // set back the original view port
    GL_CHECK( glViewport( viewportsize[0], viewportsize[1], viewportsize[2], viewportsize[3]) );


}

vrt_bool VfxMatrixDrawer::isUsingGLAPI() const
{
    return VRT_TRUE;
}

#endif

#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__

