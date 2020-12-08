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
 *  vapp_wallpaper_firefly.cpp
 *
 * Project:
 * --------
 *  Venus Live Wallpaper
 *
 * Description:
 * ------------
 *  Home screen firefly wallpaper class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "stdlib.h"
#include "vapp_wallpaper_firefly.h"
#include "mmi_rp_app_venus_wallpaper_firefly_def.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_frame_filter.h"
#include "vapp_hs_def.h"

extern "C"
{
#include "gdi_primitive.h"
#include "gdi_lcd_config.h"
#include "gdi_2d_engine.h"
}
    
static const VfxU32 SCREEN_WIDTH = GDI_LCD_WIDTH;
static const VfxU32 SCREEN_HEIGHT = GDI_LCD_HEIGHT;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxU32 FIREFLY_SIZE = 26;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxU32 LAYER_SKY_WIDTH = 333;
static const VfxU32 LAYER_FG1_WIDTH = 360;
static const VfxU32 LAYER_FG2_WIDTH = 300;
static const VfxU32 LAYER_FF_WIDTH = 360;
#else
static const VfxU32 LAYER_SKY_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG1_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG2_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FF_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_240X400__)
static const VfxU32 FIREFLY_SIZE = 26;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxU32 LAYER_SKY_WIDTH = 333;
static const VfxU32 LAYER_FG1_WIDTH = 360;
static const VfxU32 LAYER_FG2_WIDTH = 300;
static const VfxU32 LAYER_FF_WIDTH = 360;
#else
static const VfxU32 LAYER_SKY_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG1_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG2_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FF_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_320X480__)
static const VfxU32 FIREFLY_SIZE = 32;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxU32 LAYER_SKY_WIDTH = 360;
static const VfxU32 LAYER_FG1_WIDTH = 480;
static const VfxU32 LAYER_FG2_WIDTH = 400;
static const VfxU32 LAYER_FF_WIDTH = 480;
#else
static const VfxU32 LAYER_SKY_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG1_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG2_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FF_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_480X800__)
static const VfxU32 FIREFLY_SIZE = 63;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const VfxU32 LAYER_SKY_WIDTH = 800;
static const VfxU32 LAYER_FG1_WIDTH = 720;
static const VfxU32 LAYER_FG2_WIDTH = 600;
static const VfxU32 LAYER_FF_WIDTH = 720;
#else
static const VfxU32 LAYER_SKY_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG1_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FG2_WIDTH = SCREEN_WIDTH;
static const VfxU32 LAYER_FF_WIDTH = SCREEN_WIDTH;
#endif

#endif

/***************************************************************************** 
 * VappWallpaperFirefly implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Firefly Wallpaper", VappWallpaperFirefly, VappWallpaper);

VappWallpaperFirefly::VappWallpaperFirefly():
    m_bgFrame(NULL),
    m_fireflyLayer(NULL),
    m_timer(NULL),
    m_grassLayer1(NULL),
    m_grassLayer2(NULL)
{
    kal_mem_set(m_fireflies, 0, sizeof(m_fireflies));
}

void VappWallpaperFirefly::onCreateView()
{
#if defined(__MMI_MAINLCD_240X320__)
    const VfxS32 grassLayer1Y = 194;
    const VfxS32 grassLayer1_1H = 126;
    const VfxS32 grassLayer2Y = 152;
    const VfxS32 grassLayer2H = 168;
#elif defined(__MMI_MAINLCD_240X400__)
    const VfxS32 grassLayer1Y = 210;
    const VfxS32 grassLayer1_1H = 142;
    const VfxS32 grassLayer2Y = 155;
    const VfxS32 grassLayer2H = 188;
#elif defined(__MMI_MAINLCD_320X480__)
    const VfxS32 grassLayer1Y = 248;
    const VfxS32 grassLayer1_1H = 189;
    const VfxS32 grassLayer2Y = 170;
    const VfxS32 grassLayer2H = 267;
#elif defined(__MMI_MAINLCD_480X800__)
    const VfxS32 grassLayer1Y = 447;
    const VfxS32 grassLayer1_1H = 315;
    const VfxS32 grassLayer2Y = 248;
    const VfxS32 grassLayer2H = 514;
#endif

    VFX_OBJ_CREATE(m_bgFrame, VfxFrame, this);
    m_bgFrame->setSize(LAYER_SKY_WIDTH, SCREEN_HEIGHT);
    m_bgFrame->setPos(0, 0);
    m_bgFrame->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_BG2));
    m_bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_bgFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_bgFrame->setAutoAnimate(VFX_TRUE);

    // Initialize base timer
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(0);
    m_timer->setDuration(300);
    m_timer->m_signalTick.connect(this, &VappWallpaperFirefly::onTimerTick);

    // Initialize far foreground layer
    VFX_OBJ_CREATE(m_grassLayer2, VfxFrame, this);
    m_grassLayer2->setPos(0, grassLayer2Y);
    m_grassLayer2->setSize(LAYER_FG2_WIDTH, grassLayer2H);
	m_grassLayer2->setAutoAnimate(VFX_TRUE);

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    VfxFrame *imgFrame = NULL;
    VFX_OBJ_CREATE(imgFrame, VfxFrame, m_grassLayer2);
    imgFrame->setPos(0, 0);
    imgFrame->setSize(LAYER_FG2_WIDTH, grassLayer2H);
    imgFrame->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FG_2));
    imgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    imgFrame->setAutoAnimate(VFX_TRUE);
#endif

    // Initialize far foreground layer fireflies
    for (int i = 0; i < STATIC_FLY_COUNT_FG2; i++)
    {
        VFX_OBJ_CREATE(m_fg2Fireflies[i], StaticFirefly, m_grassLayer2);
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    #if defined(__MMI_MAINLCD_480X800__)
        createStaticFirefly(m_fg2Fireflies[i], VfxPoint(130, 240), VfxPoint(700, 350), 60);
    #else
        createStaticFirefly(m_fg2Fireflies[i], VfxPoint(130, 120), VfxPoint(400, 150), 60);
    #endif
#else
        createStaticFirefly(m_fg2Fireflies[i], VfxPoint(130, 120), VfxPoint(300, 150), 60);
#endif
    }

    // Initialize firefly layer
    VFX_OBJ_CREATE(m_fireflyLayer, VfxFrame, this);
    m_fireflyLayer->setSize(LAYER_FF_WIDTH, SCREEN_HEIGHT);
    m_fireflyLayer->setPos(0, 0);
    m_fireflyLayer->setAutoAnimate(VFX_TRUE);

    // Initialize near foreground layer
    VFX_OBJ_CREATE(m_grassLayer1, VfxFrame, this);
    m_grassLayer1->setPos(0, grassLayer1Y);
    m_grassLayer1->setSize(LAYER_FG1_WIDTH, SCREEN_HEIGHT - grassLayer1Y);
    m_grassLayer1->setAutoAnimate(VFX_TRUE);

    VfxFrame *frame1 = NULL;
    VFX_OBJ_CREATE(frame1, VfxFrame, m_grassLayer1);
    frame1->setPos(0, 0);
    frame1->setSize(LAYER_FG1_WIDTH, grassLayer1_1H);
    frame1->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FG_1));
    frame1->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    VfxFrame *frame2 = NULL;
    VFX_OBJ_CREATE(frame2, VfxFrame, m_grassLayer1);
    frame2->setPos(0, grassLayer1_1H);
    frame2->setSize(LAYER_FG1_WIDTH, SCREEN_HEIGHT - grassLayer1Y - grassLayer1_1H);
    frame2->setBgColor(VRT_COLOR_BLACK);
    frame2->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    
    // Initialize near foreground layer fireflies
#if defined(__MMI_MAINLCD_480X800__)
    VfxPoint fg1FireflyPos[] = { VfxPoint(30, 250), 
                                 VfxPoint(88, 220),
                                 VfxPoint(170, 150),
                                 VfxPoint(372, 155),
                                 VfxPoint(642, 50),
                                 VfxPoint(704, 152),
                                 VfxPoint(756, 94)};
#else
    VfxPoint fg1FireflyPos[] = { VfxPoint(15, 123), 
                                 VfxPoint(44, 108),
                                 VfxPoint(88, 75),
                                 VfxPoint(186, 78),
                                 VfxPoint(321, 25),
                                 VfxPoint(446, 74),
                                 VfxPoint(460, 47)};
#endif

    for (int i = 0; i < STATIC_FLY_COUNT_FG1; i++)
    {
        VFX_OBJ_CREATE(m_fg1Fireflies[i], StaticFirefly, m_grassLayer1);
        VfxPoint pos(fg1FireflyPos[i]);
        createStaticFirefly(m_fg1Fireflies[i], pos, VfxPoint(pos.x+1, pos.y+1), 75);
    }
    

    // Initialize flying fireflies
    onRestoreView();
}

void VappWallpaperFirefly::onReleaseView()
{
    for (int i = 0; i < STATIC_FLY_COUNT_FG1; i--)
    {
        VFX_OBJ_CLOSE(m_fg1Fireflies[i]);
        m_fg1Fireflies[i] = NULL;
    }   

    for (int i = 0; i < STATIC_FLY_COUNT_FG2; i--)
    {
        VFX_OBJ_CLOSE(m_fg2Fireflies[i]);
        m_fg2Fireflies[i] = NULL;
    }           

    for (int i = 0; i < MAX_FLY_COUNT; i--)
    {
        VFX_OBJ_CLOSE(m_fireflies[i]);
        m_fireflies[i] = NULL;
    }   
}

void VappWallpaperFirefly::onSerializeView()
{
    // close fire flies
    for (int i = 0; i < MAX_FLY_COUNT; ++i)
    {
        VFX_OBJ_CLOSE(m_fireflies[i]);
        m_fireflies[i] = NULL;
    }   
}

void VappWallpaperFirefly::onRestoreView()
{
    for (int i = 0; i < MAX_FLY_COUNT; ++i)
    {
        if(NULL == m_fireflies[i])
        {
            VFX_OBJ_CREATE(m_fireflies[i], Firefly, m_fireflyLayer);
        }
    }
}

MMI_IMG_ID VappWallpaperFirefly::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_FIREFLY_THUMBNAIL;
}

void VappWallpaperFirefly::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_FIREFLY);
    return;
}

void VappWallpaperFirefly::onSuspend()
{
    m_timer->stop();            

    for (int i = 0; i < STATIC_FLY_COUNT_FG1; i++)
    {
        m_fg1Fireflies[i]->suspend();
    }

    for (int i = 0; i < STATIC_FLY_COUNT_FG2; i++)
    {
        m_fg2Fireflies[i]->suspend();
    }

    for (int i = 0; i < MAX_FLY_COUNT; i++)
    {
        m_fireflies[i]->suspend();
    }
}

void VappWallpaperFirefly::onResume()
{
    m_timer->start();

    for (int i = 0; i < STATIC_FLY_COUNT_FG1; i++)
    {
        m_fg1Fireflies[i]->resume();
    }

    for (int i = 0; i < STATIC_FLY_COUNT_FG2; i++)
    {
        m_fg2Fireflies[i]->resume();
    }

    for (int i = 0; i < MAX_FLY_COUNT; i++)
    {
        m_fireflies[i]->resume();
    }
}

void VappWallpaperFirefly::onWidgetDropped(VfxPoint pos, VfxControl *targetWidget)
{
    VappWallpaper::onWidgetDropped(pos, targetWidget);
}

VfxBool VappWallpaperFirefly::onPenInput(VfxPenEvent &e)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        const VfxPoint &pos = e.getRelDownPos(this);
        VfxPoint newPos(pos.x - m_fireflyLayer->getPos().x, pos.y);
        
        const VfxU32 createNum = rand()%3 + 1;

        for (int i = 0; i < createNum; i++)
        {
            const VfxU32 shiftX = rand() % 20;
            const VfxU32 shiftY = rand() % 20;
            createFirefly(NULL, VfxPoint(newPos.x - shiftX, newPos.y - shiftY), VfxPoint(newPos.x + shiftX, newPos.y + shiftY), rand()%81+60);
        }
    }
    else if(VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
        const VfxPoint &pos = e.getRelPos(this);
        VfxPoint newPos(pos.x - m_fireflyLayer->getPos().x, pos.y);

        const VfxU32 shiftX = rand() % 20;
        const VfxU32 shiftY = rand() % 20;
        
        createFirefly(NULL, VfxPoint(newPos.x - shiftX, newPos.y - shiftY), VfxPoint(newPos.x + shiftX, newPos.y + shiftY), rand()%81+60);
    }
    
    // Bypass pen event since we're wallpaper
    return VFX_FALSE;
}

void VappWallpaperFirefly::onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    const VfxS32 totalPage = getTotalPage();
    moveWallpaperFrame(totalPage, curPos, m_bgFrame);
    moveWallpaperFrame(totalPage, curPos, m_fireflyLayer);
    moveWallpaperFrame(totalPage, curPos, m_grassLayer1);
    moveWallpaperFrame(totalPage, curPos, m_grassLayer2);
#endif
}

void VappWallpaperFirefly::moveWallpaperFrame(const VfxU32 totalPage, VfxFloat curPos, VfxFrame *target)
{
    if (target)
    {
        VfxS32 b = target->getSize().width - SCREEN_WIDTH;
        if (b > 0)
        {
            // calculate the bounds of the wallpaper
            VfxS32 m = b * curPos;

            // Check x value for fail-safe
            m = (m < 0) ? (0) : (m);
            m = (m > b) ? (b) : (m);

            // Change wallpaper position
            VfxPoint pos = target->getPos();
            pos.x = -m;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

            target->setPos(pos);

            VfxAutoAnimate::commit();
        }
    }
}

void VappWallpaperFirefly::onTimerTick(VfxTimer *timer)
{
    VfxU32 randNum = rand();

    if (randNum % 3)
    {
        createFirefly(NULL, VfxPoint(-100, SCREEN_HEIGHT-100), VfxPoint(LAYER_FF_WIDTH+100, SCREEN_HEIGHT-100), randNum%81+60);
    }

}

void VappWallpaperFirefly::createFirefly(Firefly *f, const VfxPoint LT, const VfxPoint RB, const VfxFloat scale, const VfxBool isFly)
{
    VfxPoint pos;
    pos.x = RB.x == LT.x ? LT.x : LT.x + (rand()%(RB.x - LT.x));
    pos.y = RB.y == LT.y ? LT.y : LT.y + (rand()%(RB.y - LT.y));

    if (f)
    {
        f->born(pos, scale, isFly);
        if (isFly)
        {
            f->fly();
        }
    }
    else
    {
        for (int i = 0; i < MAX_FLY_COUNT; i++)
        {
            if (m_fireflies[i] && m_fireflies[i]->isAvailable())
            {
                m_fireflies[i]->born(pos, scale, isFly);
                if (isFly)
                {
                    m_fireflies[i]->fly();
                }
                break;
            }
        }
    }
}


void VappWallpaperFirefly::createStaticFirefly(StaticFirefly *f, const VfxPoint LT, const VfxPoint RB, const VfxFloat scale)
{
    VfxPoint pos;
    pos.x = RB.x == LT.x ? LT.x : LT.x + (rand()%(RB.x - LT.x));
    pos.y = RB.y == LT.y ? LT.y : LT.y + (rand()%(RB.y - LT.y));

    f->born(pos, scale);
}


/***************************************************************************** 
 * Static Firefly implementation
 *****************************************************************************/

void StaticFirefly::onInit()
{
    VfxFrame::onInit();

    setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FLY7));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    setAnchor(0.5f, 0.5f);
    setOpacity(0.0f);
    
    m_delay = 2000 + rand()%4000;
    m_duration = 1500 + rand()%1500;
    
    VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
    m_timeline->setTarget(this);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_timeline->setFromValue(0.0f);
    m_timeline->setToValue(1.0f);
    m_timeline->setDuration(m_duration);
    m_timeline->m_signalStopped.connect(this, &StaticFirefly::onAnimComplete);

    // use FPE to adjust scale
    setPropertyEffectCallback(this,
                              FpeCallback, 
                              NULL,
                              0);
}

void StaticFirefly::born(const VfxPoint pos, const VfxS32 scale)
{
    setPos(pos);
    VfxFloat s = VfxFloat(VRT_MAX(scale, 20) - rand()%10)/100.0f;
    setSize(FIREFLY_SIZE*s, FIREFLY_SIZE*s);    
    
}

void StaticFirefly::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        VfxFloat From = m_timeline->getFromValue();
        VfxFloat To = m_timeline->getToValue();

        if (To == 1.0f) // Fade in complete
        {
            m_timeline->setFromValue(1.0f);
            m_timeline->setToValue(0.0f);
            m_timeline->setStartDelay(0);
        }
        else // To == 0.0f Fade out complete
        {
            m_timeline->setFromValue(0.0f);
            m_timeline->setToValue(1.0f);
            m_timeline->setStartDelay(m_delay);
        }

        m_timeline->setDuration(m_duration);
        m_timeline->start();
    }
}

vrt_render_dirty_type_enum StaticFirefly::FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size)
{
    target_frame->opacity = watch_frame->pos_z;
    target_frame->transform.data.affine.sx = target_frame->transform.data.affine.sy = 0.33f + 0.67f * watch_frame->pos_z;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void StaticFirefly::suspend()
{
    if (!m_isSuspended)
    {
        m_timeline->stop();
        m_isSuspended = VFX_TRUE;
    }
}

void StaticFirefly::resume()
{
    if (m_isSuspended)
    {
        VfxFloat timing = forceGetOpacity();
        VfxFloat From = m_timeline->getFromValue();
        VfxFloat To = m_timeline->getToValue();
        VfxS32 duration = From == To ? m_duration : m_duration * vfxAbs(VfxFloat(To - timing)/(From - To));

        if (timing == 0.0f && To == 1.0f)
        {
            m_timeline->setStartDelay(m_delay);
        }

        m_timeline->setFromValue(timing);
        m_timeline->setDuration(duration);
        m_timeline->start();

        m_isSuspended = VFX_FALSE;
    }
}

/***************************************************************************** 
 * Firefly implementation
 *****************************************************************************/

void Firefly::onInit()
{
    VfxFrame::onInit();

    VfxS32 randNum = rand();

    setPos(-100, -100);
    //setCacheMode(VFX_CACHE_MODE_PREVENT);

    // use frame filter to draw normal or highlight image
    //VFX_OBJ_CREATE(m_filter, FlyFilter, this);

    VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
    m_timeline->setTarget(this);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_timeline->m_signalStopped.connect(this, &Firefly::onAnimComplete);
    
    // use FPE to show twinkle frame
    Firefly *pThis = this;
    setPropertyEffectCallback(this,
                              FpeCallback, 
                              &pThis,
                              sizeof(pThis));
}

void Firefly::onDeinit()
{
    VFX_OBJ_CLOSE(m_timeline);
    setPropertyEffectCallback(NULL, NULL, NULL, 0);
    VfxFrame::onDeinit();
}

void Firefly::born(const VfxPoint pos, const VfxS32 scale, const VfxBool isFly)
{
    setPos(pos);
    VfxFloat s = VfxFloat(VRT_MAX(scale, 20) - rand()%10)/100.0f;
    setSize(FIREFLY_SIZE, FIREFLY_SIZE);
    if (gdi_2d_linear_transform_hw_support())
    {
        VfxTransform trans;
        trans.data.affine.sx = trans.data.affine.sy = scale/100.0f;
        setTransform(trans);
    }
    //setFilter(m_filter);
    setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FLY6));
    m_targetPos = pos;
    m_yPos = pos.y;
    m_fly = isFly;
}

void Firefly::fly()
{
    VfxS32 randNum1 = rand();
    VfxS32 randNum2 = rand();
    VfxS32 dir = randNum1%2 ? 1 : -1;
    m_duration = 3000 + rand()%3000;
    m_targetPos.y = VfxS32(m_yPos);
    
    VfxPoint newPos(m_targetPos.x + dir*(50+randNum1%300), m_targetPos.y - (30+randNum2%300));
    m_ySpeed = (newPos.y - m_targetPos.y) / (m_duration / 1000.0f) / 30.0f;
    
    m_timeline->setFromValue(m_targetPos.x);
    m_timeline->setToValue(newPos.x);
    m_timeline->setDuration(m_duration);
    m_timeline->start();

    //m_filter->setHighlight();

    m_targetPos = newPos;
    m_isAvailable = VFX_FALSE;
}

void Firefly::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        if (m_targetPos.x < -100 || m_targetPos.x > (LAYER_FF_WIDTH+100) || m_yPos < -50)
        {
            m_isAvailable = VFX_TRUE;
        }
        else
        {
            setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FLY7));
            m_twinkleCounter = 1;
            invalidate();

            fly();
        }
    }
}

vrt_render_dirty_type_enum Firefly::FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                             const vrt_frame_visual_property_struct *watch_frame,
                                             void *user_data,
                                             vrt_u32 user_data_size)
{
    Firefly *pThis = *reinterpret_cast<Firefly**>(user_data);
    
    if (!pThis->isAvailable())
    {
        if(!pThis->m_isSuspended)
        {
            pThis->m_yPos += pThis->m_ySpeed;
        }
        target_frame->pos.x = watch_frame->pos_z;
        target_frame->pos.y = pThis->m_yPos;
    }

    if (pThis->m_twinkleCounter > 0)
    {
        pThis->m_twinkleCounter--;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    else if (pThis->m_twinkleCounter == 0)
    {
        pThis->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_FIREFLY_FLY6));
        pThis->m_twinkleCounter--;
        return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
    }
    else
    {
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
}

VfxBool Firefly::isAvailable() const
{
    return m_isAvailable;
}

void Firefly::setAvailable(const VfxBool isAvailable)
{
    m_isAvailable = isAvailable;
}

void Firefly::suspend()
{
    if (!isAvailable())
    {
        m_timeline->stop();
        m_isSuspended = VFX_TRUE;
    }
}

void Firefly::resume()
{
    if (m_isSuspended)
    {
        if (m_fly)
        {
            VfxPoint pos = forceGetPos();
            VfxS32 timing = pos.x;
            VfxS32 From = m_timeline->getFromValue();
            VfxS32 To = m_timeline->getToValue();
            VfxS32 duration = m_duration;

            if (From != To)
            {
                duration = m_duration*vfxAbs(VfxFloat(To - timing)/(From - To));
            }
            else
            {
                duration = 1;
            }

            m_timeline->setFromValue(timing);
            m_timeline->setDuration(duration);
            m_timeline->start();
        }

        m_isSuspended = VFX_FALSE;
    }
}


/***************************************************************************** 
 * FlyFilter implementaton
 *****************************************************************************/

void FlyFilter::onInit()
{
    VfxFrameFilter::onInit();
    loadImage();
}

void FlyFilter::onDeinit()
{
    VfxFrameFilter::onDeinit();
}


VfxBool FlyFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    drawImage(outBuf, inBuf);
    if (m_hlCounter > 0)
    {
        m_hlCounter--;
    }

    return VFX_TRUE;
}

void FlyFilter::loadImage()
{
    setResourceFromResId('NORM', VAPP_WALLPAPER_IMG_FIREFLY_FLY6);
    setResourceFromResId('HIGH', VAPP_WALLPAPER_IMG_FIREFLY_FLY7);
}

inline void FlyFilter::drawImage(VfxU8 *outBuf, const VfxImageBuffer &inBuf) const
{
    VfxImageBuffer imageBuf;
    if (m_hlCounter)
    {
        getResource('HIGH', imageBuf);
    }
    else
    {
        getResource('NORM', imageBuf);
    }
    VFX_DEV_ASSERT(imageBuf.ptr);

    gdi_img_buf_color_format_enum colorFormat;
    switch(inBuf.colorFormat)
    {
        case VRT_COLOR_TYPE_PARGB8888:
            colorFormat = GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;
            break;
        case VRT_COLOR_TYPE_ARGB8888:
            colorFormat = GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return;
    }

    gdi_img_buf_struct src;
    src.color_format = colorFormat;
    src.pitch_bytes = FIREFLY_SIZE * 4;
    src.ptr = reinterpret_cast<VfxU8*>(imageBuf.ptr);

    gdi_img_buf_struct dst;
    dst.color_format = colorFormat;
    dst.pitch_bytes = inBuf.pitchBytes;
    dst.ptr = reinterpret_cast<VfxU8*>(outBuf);

    gdi_img_buf_copy(&dst, &src, FIREFLY_SIZE, FIREFLY_SIZE);
}

void FlyFilter::setHighlight()
{
    m_hlCounter = 1;
}

#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__
