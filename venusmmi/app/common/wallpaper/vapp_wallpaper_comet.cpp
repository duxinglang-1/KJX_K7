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
 *  vapp_wallpaper_comet.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_comet.h"
#include "mmi_rp_app_venus_wallpaper_comet_def.h"
#include "stdlib.h"
extern "C"
{
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "vrt_canvas.h"
#include "vrt_datatype.h"
#include "string.h"
}
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_primitive_frame.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_auto_animate.h"
#include "vfx_transform.h"
#include "vfx_frame_filter.h"


/***************************************************************************** 
 * Global definitions
 *****************************************************************************/

static const VfxS32 SCRN_W = GDI_LCD_WIDTH;

#if defined(__MMI_MAINLCD_240X320__)
static const int REFLECT_LINE = 256;  // Y pos of the horizon of the lake
static const VfxS32 HORIZON = 236; // horizon for hit test of explosion, not necessary the "reflect line" of water
static const VfxU32 MOUNTAIN_TOP = 184;  // vertical pos of the mountain
static const int REFLECT_OFFSET = 15;

#elif defined(__MMI_MAINLCD_240X400__)
static const int REFLECT_LINE = 310;  // Y pos of the horizon of the lake
static const VfxS32 HORIZON = 280; // horizon for hit test of explosion, not necessary the "reflect line" of water
static const VfxU32 MOUNTAIN_TOP = 230;  // vertical pos of the mountain
static const int REFLECT_OFFSET = 30;

#elif defined(__MMI_MAINLCD_320X480__)
static const int REFLECT_LINE = 320;  // Y pos of the horizon of the lake
static const VfxS32 HORIZON = 290; // horizon for hit test of explosion, not necessary the "reflect line" of water
static const VfxU32 MOUNTAIN_TOP = 247;  // vertical pos of the mountain
static const int REFLECT_OFFSET = 0;

#elif defined(__MMI_MAINLCD_480X800__)
static const int REFLECT_LINE = 514;  // Y pos of the horizon of the lake
static const VfxS32 HORIZON = 460; // horizon for hit test of explosion, not necessary the "reflect line" of water
static const VfxU32 MOUNTAIN_TOP = 340;  // vertical pos of the mountain
static const int REFLECT_OFFSET = 0;

#endif

/***************************************************************************** 
 * Home screen UI componet: Comet wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Comet Wallpaper", VappWallpaperComet, VappWallpaper);

VappWallpaperComet::VappWallpaperComet() :
    m_bombardTimer(NULL),
    m_idleTimer(NULL),
    m_bombDropAngle(0.0f),
    m_bombFireCount(0),
    m_waveTimeline(NULL),
    m_mountainFrame(NULL),
    m_bgFrame(NULL)
{
}

void VappWallpaperComet::onCreateView()
{
    // Create the background "starry night" frame
    VFX_OBJ_CREATE(m_bgFrame, VfxImageFrame, this);    
    VfxImageSrc bgImg(VAPP_WALLPAPER_IMG_COMET_BG);
    m_bgFrame->setImgContent(bgImg);
    m_bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT);
    m_bgFrame->setSize(bgImg.getSize().width, REFLECT_LINE);
    m_bgFrame->setPos(0, 0);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_bgFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE); // force RGB565 format

    // initialize comets, which are VfxFrame.
    for(int i = 0; i < MAX_COMET_NUM; ++i)
    {
        m_comets[i].init(this);
    }

    // create the wallpaper "mountain" frame
    // this frame is the topmost foreground.
    // It will scroll under multi-page desktop.
    VFX_OBJ_CREATE(m_mountainFrame, VfxFrame, this);

    VfxImageSrc mountainImg(VAPP_WALLPAPER_IMG_COMET_MOUNTAIN);
    m_mountainFrame->setImgContent(mountainImg);
    m_mountainFrame->setSize(mountainImg.getSize());
    m_mountainFrame->setPos(0, MOUNTAIN_TOP);
    m_mountainFrame->setIsOpaque(VFX_FALSE);
    m_mountainFrame->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    // set auto-animate for multi-desktop
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    m_mountainFrame->setAutoAnimate(VFX_TRUE);
    m_bgFrame->setAutoAnimate(VFX_TRUE);
#endif

    // create timer for "random" comet animation
    VfxTimer *pTimer = NULL;
    VFX_OBJ_CREATE(pTimer, VfxTimer, this);
    pTimer->setStartDelay(3000);
    pTimer->m_signalTick.connect(this, &VappWallpaperComet::onGenerateComet);
    m_idleTimer = pTimer;

    // create timer for "bombard" comet animation
    m_bombardTimer = NULL;
    VFX_OBJ_CREATE(m_bombardTimer, VfxTimer, this);
    m_bombardTimer->setStartDelay(0);
    m_bombardTimer->setDuration(300);
    m_bombardTimer->m_signalTick.connect(this, &VappWallpaperComet::onBombMeteor);

    // we add water reflection
    WaveFilter *pWaveFilter = NULL;
    VFX_OBJ_CREATE(pWaveFilter, WaveFilter, this);
    this->setFilter(pWaveFilter);
    // timeline for wave filter
    m_waveTimeline = NULL;
    VFX_OBJ_CREATE(m_waveTimeline, VfxFloatTimeline, this);
    m_waveTimeline->setFromValue(0.0f);
    m_waveTimeline->setToValue(1.0f);
    m_waveTimeline->setDurationTime(2000);
	m_waveTimeline->setAutoReversed(VFX_FALSE);
    m_waveTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_waveTimeline->setTarget(this);
    m_waveTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
}


MMI_IMG_ID VappWallpaperComet::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_COMET_THUMBNAIL;
}

void VappWallpaperComet::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_COMET);
    return;
}

VfxBool VappWallpaperComet::onPenInput(VfxPenEvent &e)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
	{
        const VfxPoint &startPt = e.getRelDownPos(this);
        // Make sure the comet/meteor always appear above the mountain.
        m_bombDropPos.y = vfxMin(int(MOUNTAIN_TOP), int(startPt.y));
        m_bombDropPos.x = startPt.x;
        m_bombDropAngle = 11.0f;
        m_bombFireCount = 0;
        m_bombardTimer->start();
    }   
    // Bypass pen event since we're wallpaper
    return VappWallpaper::onPenInput(e);
}
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static void moveDesktop(VfxFrame* bgFrame, VfxFloat cursor)
{
    const VfxU32 frameWidth = bgFrame->getSize().width;
    const VfxFloat offset = (frameWidth - SCRN_W) * cursor * -1.0f;
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    bgFrame->setPos(offset, bgFrame->getPos().y);
    VfxAutoAnimate::commit();
}
#endif
void VappWallpaperComet::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    moveDesktop(m_mountainFrame, curPos);
#endif
    return;
}

void VappWallpaperComet::onBombMeteor(VfxTimer *timer)
{
    if(m_bombFireCount >= MAX_BOMB_COUNT)
    {
        timer->stop();
        return;
    }

    ++m_bombFireCount;

    // drop one bomb metor
    for(int i = 0; i < MAX_COMET_NUM; ++i)
    {
        if(m_comets[i].isAvailable())
        {
            activateOneComet(m_bombDropPos);
            m_bombDropPos.x += 25;
            if(m_bombDropPos.x >= SCRN_W)
            {
                m_bombDropPos.x = 50 + (m_bombDropPos.x % (SCRN_W - 50));
            }
            m_bombDropAngle -= 2.0f;
            return;
        }
    }

    // all slots are used, stop bombing
    timer->stop();
    return;
}

void VappWallpaperComet::onGenerateComet(VfxTimer *timer)
{
    do
    {
        // only generate comet if there is none
        // so we return immediately if any comet is running
        for(int i = 0; i < MAX_COMET_NUM; ++i)
        {
            if(!m_comets[i].isAvailable())
            {
                break;
            }
        }
        // decide a random position
        static const int minimumHeightAboveHorizon = 150;
        VfxS32 x = rand() % getSize().width;
        VfxS32 y = rand() % (HORIZON - minimumHeightAboveHorizon);        
        activateOneComet(VfxPoint(x, y));
    }while(false);
    
    // set next start time
    static const VfxMsec minimumInterval = 1500;
    static const VfxMsec intervalStep = 100;
    static const VfxMsec step = 10;
    VfxMsec nextTime = minimumInterval + intervalStep * (rand() % step);
    timer->setStartDelay(nextTime);
    timer->start();
}

VfxBool VappWallpaperComet::activateOneComet(const VfxPoint &startPos, VfxBool useMeteor)
{
    for(int i = 0; i < MAX_COMET_NUM; ++i)
    {
        if(m_comets[i].isAvailable())
        {
            if(useMeteor)
            {
                m_comets[i].switchToMeteor();
                m_comets[i].start(startPos, m_bombDropAngle);
            }
            else
            {
                m_comets[i].switchToComet();
                m_comets[i].start(startPos);
            }
            
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappWallpaperComet::onSuspend()
{
    VappWallpaper::onSuspend();
    m_bombardTimer->stop();
    m_waveTimeline->stop();
    m_idleTimer->stop();
    for(int i = 0; i < MAX_COMET_NUM; ++i)
    {
        m_comets[i].stop();
    }
}

void VappWallpaperComet::onResume()
{
    m_bombardTimer->start();
    m_waveTimeline->start();
    m_idleTimer->start();
    VappWallpaper::onResume();
}

void VappWallpaperComet::onCometAnimationStopped(VfxBaseTimeline *timeline, VfxBool stopped)
{
    for(int i = 0; i < MAX_COMET_NUM; ++i)
    {
        m_comets[i].notifyTimelineStopped(timeline);
    }
}

CometAnimation::CometAnimation():
    m_anim(NULL),
    m_lastTimeline(NULL),
    m_comet(NULL),
    m_core(NULL),    
    m_animDeltaX(0.0f),
    m_animDeltaY(0.0f),
    m_animScale(1.0f),
    m_available(VFX_FALSE),
    m_isMeteor(VFX_FALSE)
{
}
        
VfxBool CometAnimation::isAvailable()
{
    return m_available;
}

VfxBool CometAnimation::notifyTimelineStopped(VfxBaseTimeline *timeline)
{
    // if this is our opacity timeline,
    // this means the animation has ended.
    // therefore this CometAnimation is available again.
    if(timeline == m_lastTimeline)
    {
        VFX_DEV_ASSERT(!m_available);
        m_comet->setHidden(VFX_TRUE);
        m_core->setHidden(VFX_TRUE);
        m_explosion->setHidden(VFX_TRUE);
        m_available = VFX_TRUE;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void CometAnimation::init(VappWallpaperComet *parent)
{
    // Create the comet core
    VfxImageFrame *pCore = NULL;
    VFX_OBJ_CREATE(pCore, VfxImageFrame, parent);
    pCore->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_DOT));
    pCore->setIsOpaque(VFX_FALSE);
    pCore->setAnchor(0.5f, 0.5f);
    pCore->setOpacity(0.0f);
    pCore->setHidden(VFX_TRUE);

    // Create the "comet" tail
    VfxImageFrame *pComet = NULL;
    VFX_OBJ_CREATE(pComet, VfxImageFrame, parent);
    pComet->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_TAIL));
    pComet->setIsOpaque(VFX_FALSE);
    pComet->setHidden(VFX_TRUE);
    const VfxPoint pos(0, 0);
    pComet->setPos(pos);
    pComet->setAnchor(0.5f, 0.973f);

    VfxImageFrame *pExplosion = NULL;
    VFX_OBJ_CREATE(pExplosion, VfxImageFrame, parent);
    pExplosion->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_EXPLODE));
    pExplosion->setIsOpaque(VFX_FALSE);
    pExplosion->setAnchor(0.5f, 0.63f);
    pExplosion->setOpacity(0.0f);
    pExplosion->setHidden(VFX_TRUE);

    // set of animations
    VFX_OBJ_CREATE(m_anim, VfxAnimation, pComet);
         
    // Setup FPE user property;
    // we shall calculate scaleY, alpha and translate by ourselves.
    // keyframe time point in Yan He's flash desgin:
    // 0, 0.2, 0.5, 1.1, 1.3
    // const VfxMsec timingData[] = {0, 400, 1000, 1400, 1600, 2800};
    const VfxMsec timingData[] = {0, 200, 500, 700, 900, 1400};
    
    const int timingDataLen = sizeof(timingData) / sizeof(VfxMsec);
    for(int i = 1; i < timingDataLen; ++i)
    {        
        VfxFloatTimeline *pUserTiming = NULL;
        VFX_OBJ_CREATE(pUserTiming, VfxFloatTimeline, m_anim);
        pUserTiming->setTarget(pComet);
        // use Z-pos instead of user_0 because Z-pos would trigger dirty. 
        // (using filter timing would trigger content dirty instead)
        pUserTiming->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
        // we use integer part to prepresent stage
        // use fraction part
        pUserTiming->setFromValue(VfxFloat(i - 1));
        pUserTiming->setToValue(VfxFloat(i));
        pUserTiming->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
        pUserTiming->setStartDelay(timingData[i - 1]);
        pUserTiming->setDurationTime(timingData[i] - timingData[i - 1]);

        // use to ensure the animation has stopped,
        // so we record last timeline here.
        if(timingDataLen == i + 1)
        {
            m_lastTimeline = pUserTiming;
        }
    }
    
    m_comet = pComet;
    m_core = pCore;
    m_explosion = pExplosion;
    m_available = VFX_TRUE;
    VFX_DEV_ASSERT(m_lastTimeline);
    m_lastTimeline->m_signalStopped.connect(parent, &VappWallpaperComet::onCometAnimationStopped);
    
    CometAnimation *pThis = this;
    // use FPE to adjust tail length & alpha
    pComet->setPropertyEffectCallback(pComet,
                                      tailEffectCallback, 
                                      &pThis,
                                      sizeof(pThis));

    // use FPE to adjust core size, which depends on tail timing
    pCore->setPropertyEffectCallback(pComet,
                                     coreEffectCallback, 
                                     &pThis,
                                     sizeof(pThis));

    // the explosion when comet hit the earth
    pExplosion->setPropertyEffectCallback(pComet,
                                          explosionEffectCallback, 
                                          &pThis,
                                          sizeof(pThis));
}

vrt_render_dirty_type_enum CometAnimation::tailEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame);
    VFX_DEV_ASSERT(watch_frame);
    VFX_DEV_ASSERT(target_frame == watch_frame);
    VFX_DEV_ASSERT(target_frame->transform.type == VRT_TRANSFORM_TYPE_AFFINE);
    float timingData = watch_frame->pos_z;
    int stage = (int)timingData;
    float prog = timingData - stage;
    target_frame->opacity = 1.0f;

    // retrieve this pointer
    const CometAnimation * const pThis = *reinterpret_cast<CometAnimation**>(user_data);

    // adjust translation
    VFX_DEV_ASSERT(pThis);
    const VfxFloat arcLengths[6] = {0.0f, 0.64f, 0.87f, 0.87f, 0.87f, 0.87f};
    if(stage >= 0 && stage < sizeof(arcLengths) / sizeof(VfxFloat))
    {
        const VfxFloat &tStart = arcLengths[stage];
        const VfxFloat &tEnd = arcLengths[stage + 1];
        const VfxFloat offsetRatio = tStart + (tEnd - tStart) * prog;
        target_frame->transform.data.affine.tx = pThis->m_animDeltaX * offsetRatio;
        target_frame->transform.data.affine.ty = pThis->m_animDeltaY * offsetRatio;
    }
    
    // adjust scale and poacity
    switch(stage)
    {
    case 0:
        target_frame->transform.data.affine.sy = 0.33f + (1.0f - 0.33f) * prog;
        break;
    case 1:
        target_frame->transform.data.affine.sy = 1.0f + (1.176f - 1.0f) * prog;
        break;
    case 2:
        target_frame->transform.data.affine.sy = 1.176f + (0.756f - 1.176f) * prog;
        break;
    case 3:
        target_frame->transform.data.affine.sy = 0.756f;
        target_frame->opacity = 1.0f + (0.0f - 1.0f) * prog;
        break;
    default:
        target_frame->transform.data.affine.sy = 0.1f;
        target_frame->opacity = 0.0f;
        break;
    }
    
    // resize according to global scale factor
    target_frame->transform.data.affine.sy *= pThis->m_animScale;
    target_frame->transform.data.affine.tx *= pThis->m_animScale;
    target_frame->transform.data.affine.ty *= pThis->m_animScale;
    if(pThis->m_isMeteor)
        target_frame->transform.data.affine.sy *= 2;
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum CometAnimation::coreEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame->transform.type == VRT_TRANSFORM_TYPE_AFFINE);
    // core's position follows tails.
    // however, it has it's own resize routines
    // relied on tail's FPE_USER_0 (which is a timing information)
    target_frame->pos = watch_frame->pos;
    vrt_affine_parameter_struct &target_affine = target_frame->transform.data.affine;
    const vrt_affine_parameter_struct &watch_affine = watch_frame->transform.data.affine;
    target_affine = watch_affine;
    target_affine.rz = 0;
    target_affine.sx = 1.0f;
    target_affine.sy = 1.0f;

    // retrieve this pointer
    const CometAnimation * const pThis = *reinterpret_cast<CometAnimation**>(user_data);

    // Decide alpha and scale according to time.
    float timingData = watch_frame->pos_z;
    int stage = (int)timingData;
    float prog = timingData - stage;
    // resize: 100, 84.6, 77.4, 47.8, 36.5
    float scale = 1.0f;
    float alpha = 1.0f;
    switch(stage)
    {
    case 0:
        scale = 1.0f + (0.846f - 1.0f) * prog;
        break;
    case 1:
        scale = 0.846f + (0.774f - 0.846f) * prog;
        break;
    case 2:
        scale = 0.774f + (0.478f - 0.774f) * prog;
        break;
    case 3:
        scale = 0.478f + (0.365f - 0.478f) * prog;
        alpha = 1.0f + (0.0f - 1.0f) * prog;
        break;
    default:
        scale = 0.1f;
        alpha = 0.0f;
        break;
    }

    target_frame->transform.data.affine.sy = scale * pThis->m_animScale;
    target_frame->transform.data.affine.sx = scale * pThis->m_animScale;
    VFX_DEV_ASSERT(target_frame->transform.data.affine.sx > 0.0f);
    VFX_DEV_ASSERT(target_frame->transform.data.affine.sy > 0.0f);

    target_frame->opacity = alpha;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum CometAnimation::explosionEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                                   const vrt_frame_visual_property_struct *watch_frame,
                                                                   void *user_data,
                                                                   vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame->transform.type == VRT_TRANSFORM_TYPE_AFFINE);
    target_frame->pos = watch_frame->pos;
    vrt_affine_parameter_struct &target_affine = target_frame->transform.data.affine;
    const vrt_affine_parameter_struct &watch_affine = watch_frame->transform.data.affine;
    target_affine = watch_affine;
    target_affine.rz = 0;

    float timingData = watch_frame->pos_z;
    int stage = (int)timingData;
    float prog = timingData - stage;
    float scale = 1.0f;
    float alpha = 0.0f;

    // comet should only explode when hit near the mountain
    if(stage == 4 && (target_frame->pos.y + target_affine.ty) >= MOUNTAIN_TOP)
    {
        // the explosion effect
        scale = 0.68f + (5.55f - 0.68f) * prog;
        alpha = 1.0f - 1.0f * prog;   
        float oldY = target_affine.ty;
        target_affine.ty = VfxFloat(HORIZON - target_frame->pos.y);
        target_affine.tx = (target_affine.ty - oldY) / oldY * target_affine.tx + target_affine.tx;
    }
    else
    {
        scale = 0.1f;
        alpha = 0.0f;
    }
    target_affine.sy = scale;
    target_affine.sx = scale;
    target_frame->opacity = alpha;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void CometAnimation::start(const VfxPoint &startPos, VfxFloat defaultDegree)
{
    m_available = VFX_FALSE;
    
    // setup random fall angle and length
    const VfxPoint &pos = startPos;
    // between 5 ~ 35 degree.
    const float degree = defaultDegree == 0.0f ? 5 + rand() % 30 : defaultDegree;
    const float rad = (3.1415f * 2.0f) * degree / 360.0f;

    if(m_isMeteor)
    {
        m_animScale = 1.0f;
    }
    else
    {
        m_animScale = 0.6f + 0.4f / 20 * (rand() % 20);
    }
    
    m_comet->setPos(pos);
    VfxTransform trans;
    trans.type = VRT_TRANSFORM_TYPE_AFFINE;
    trans.data.affine.rz = rad;
    trans.data.affine.sy = 0.33f;
    m_comet->setTransform(trans);
    m_comet->setOpacity(1.0f);
    
    // calculate offset vector and start animation
    const int lengthScale = m_isMeteor ? 2 : 1;
    const float len = m_comet->getSize().height * lengthScale;
    m_animDeltaX = len * vfxSin(-rad);
    m_animDeltaY = len * vfxCos(-rad);

    // activate the animation timeline
    m_core->setHidden(VFX_FALSE);
    m_comet->setHidden(VFX_FALSE);
    m_explosion->setHidden(VFX_FALSE);
    m_anim->start();
}

void CometAnimation::stop()
{
    if(!m_available)
        m_anim->stop();
}

void CometAnimation::switchToMeteor()
{
    if(m_isMeteor)
        return;
    m_isMeteor = VFX_TRUE;
}

void CometAnimation::switchToComet()
{
    if(!m_isMeteor)
        return;
    m_core->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_DOT));
    m_comet->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_TAIL));
    m_explosion->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_COMET_EXPLODE));
    m_isMeteor = VFX_FALSE;
}

/***************************************************************************** 
 * Water reflection
 *****************************************************************************/
VfxFrameFilter::BufferModeEnum WaveFilter::onGetBufferMode() const
{
    return VfxFrameFilter::BUFFER_MODE_IN_PLACE;
}

VfxBool WaveFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    // Draw the reflection
    const VfxU32 &pitchBytes = inBuf.pitchBytes;

    // instead of a perfect mirror, we
    // slightly offset the reflect source.
    // This reduces the "shadow region" in the water.
    VfxU8 *inPtr = inBuf.ptr + (REFLECT_LINE - REFLECT_OFFSET) * pitchBytes;
    VfxU8 *outPtr = outBuf + REFLECT_LINE * pitchBytes;

    const VfxFloat p1 = 2 * VFX_PI * timing;
	const float fReflectLine = REFLECT_LINE;
    const VfxU32 &scrn_height = inBuf.height;
    VfxS32 dispy = 0;
    for(VfxU32 i = REFLECT_LINE + 1; i < scrn_height; i++)
    {
		// shift y
        const int dist = i - REFLECT_LINE + 50;
		dispy = (fReflectLine/14.0) * (dist+28.0)	
				* vfxSin(((fReflectLine/14.0)*(fReflectLine - dist))
				/(dist + 1.0) + p1)/fReflectLine;

		if((dist+dispy <= 0) || ((i+dispy) >= (scrn_height)))
		{
			dispy = -dispy;
		}
        
        inPtr = inPtr - dispy * pitchBytes;
        memcpy(outPtr,inPtr, pitchBytes);
        inPtr = inPtr + dispy * pitchBytes;
        
        // step to next line
        inPtr = inPtr - pitchBytes;
        outPtr = outPtr + pitchBytes;
    }

    return VFX_TRUE;
}
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__ */
