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
 *  vapp_wallpaper_sakura.cpp
 *
 * Project:
 * --------
 *  Venus Live Wallpaper
 *
 * Description:
 * ------------
 *  Home screen wild world wallpaper class
 *
 * Author:
 * -------
 *  
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "stdlib.h"
#include "vapp_wallpaper_sakura.h"
#include "mmi_rp_app_venus_wallpaper_sakura_def.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vapp_hs_def.h"
#include "MMI_common_app_trc.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#define SWITCH_PAGE_DURATION    (250)

#define ANIMATION1_DURATION      (3000)
#define ANIMATION2_DURATION      (2700)
#define SAKURA_ROTATE_DEGREE    (2)
#define SHADOW_ROTATE_DEGREE    (3)

#define SUNSHINE_MOVE_DURATION  (1500)
#define SUNSHINE_MOVE_SLOPE     (-1.78f)
#define SUNSHINE_MOVE_RANGE     (10)

#define BUTTERFLY_VELOCITY_X    (-60)   // per second
#define BUTTERFLY_VELOCITY_Y    (-40)   // per second
#define BUTTERFLY_MOVE_DURATION  (1000)
#define BUTTERFLY_VELOCITY_RANGE (20)
#define BUTTERFLY_DISTANCE      (50)

#define PETAL_G1_VELOCITY_X    (80)   // per second
#define PETAL_G1_VELOCITY_Y    (160)   // per second
#define PETAL_G2_VELOCITY_X    (-1)   // per second
#define PETAL_G2_VELOCITY_Y    (160)   // per second
#define PETAL_G3_VELOCITY_X    (-60)   // per second
#define PETAL_G3_VELOCITY_Y    (160)   // per second

#define PETAL_MOTIONSENSOR_ACC_X (10)
#define PETAL_MOTIONSENSOR_ACC_Z (15)
#define PETAL_MOTIONSENSOR_VELOCITY_X (40)

#define PETAL_VELOCITY_RANGE (120)
#define PETAL_PLAY_INTERVAL (300)

typedef struct petalFPEUserData
{
    void* pWallpaper;
    VfxU8 index;
};


/***************************************************************************** 
 * VappWallpaperSakura class implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Sakura Wallpaper", VappSakuraFlyImageFrame, VfxImageFrame);

VappSakuraFlyImageFrame::VappSakuraFlyImageFrame()  
{
}


void VappSakuraFlyImageFrame::onInit()
{
    VfxAnimImageFrame::onInit();
    m_base.x = 0;
    m_base.y = 0;
}


void VappSakuraFlyImageFrame::setInitPosRandRange(const VfxPoint& start, const VfxPoint& end)
{
    VfxU32 xLength = VFX_ABS(end.x - start.x);
    VfxU32 yLength = VFX_ABS(end.y - start.y);

    VfxU32 xRand = rand() % xLength;
    VfxU32 yRand = rand() % yLength;
#if 1
    m_base.x = start.x + xRand;
    m_base.y = start.y + yRand;

    setPos(m_base.x, m_base.y);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void VappSakuraFlyImageFrame::setInitVelocityRandRange(const VfxPoint& nowVelocity, VfxU8 interval, VfxU8 direction)
{
    m_velocity = nowVelocity;
    VfxS8 direct; 

    if (interval <= 0)
        return;

    if (direction == VELOCITY_RAND_DIRECT_BOTH)
    {
        if (rand() % 2 == 0)
            direct = 1;
        else
            direct = -1;
    }
    else if (direction == VELOCITY_RAND_DIRECT_INCREASE)
        direct = 1;
    else
        direct = -1;

    VfxU8 diff;

    diff = rand() % interval;
    m_velocity.y = m_velocity.y + direct*diff;
}


void VappSakuraFlyImageFrame::setBasePoint(const VfxPoint& point)
{
    m_base.x = point.x;
    m_base.y = point.y;    
}


VFX_IMPLEMENT_CLASS("Sakura Wallpaper", VappWallpaperSakura, VappWallpaper);

VappWallpaperSakura::VappWallpaperSakura():
    m_isSuspended(VFX_FALSE),
    m_isDelayPlay(VFX_TRUE),
    m_switchPageTimeline(NULL),
    m_sakuraFg1Timeline(NULL),
    m_sakuraFg2Timeline(NULL),
    m_sunshineTimeline(NULL),
    m_flyTimeline(NULL),
    m_grass(NULL),
    m_sakuraBg1(NULL),
    m_sakuraBg2(NULL),
    m_sakuraShadow(NULL),    
    m_bench(NULL),
    m_referenceObj(NULL),
    m_butterfly0(NULL),
    m_butterfly1(NULL),
    m_butterfly2(NULL),
    m_branch(NULL),
    m_sakuraFg1(NULL),
    m_sakuraFg2(NULL),
    m_sunshine2(NULL),
    m_sunshine1(NULL),
    m_petalPlayIndex(0),
    m_petalPlayTimer(NULL),
    m_currPage(0.0f)
{

}


void VappWallpaperSakura::initPetalPos(VfxU8 index)
{
    VfxPoint initStart, initEnd, velocity;
    VfxU8 range;
        
    if (index < G1_PETAL_COUNT)
    {
        initStart.x = PETAL_G1_INIT_X;
        initStart.y = PETAL_G1_INIT_Y;
        initEnd.x = PETAL_G1_END_X;
        initEnd.y = PETAL_G1_END_Y;
        velocity.x = PETAL_G1_VELOCITY_X;
        velocity.y = PETAL_G1_VELOCITY_Y;
        range = PETAL_VELOCITY_RANGE;
    #ifdef MOTION_SENSOR_SUPPORT
        if (m_xGravity < 0)
        {
            initStart.x = ((1- VFX_ABS(m_xGravity))*PETAL_G1_INIT_X) + (VFX_ABS(m_xGravity)* PETAL_G1_END_X);//PETAL_G1_END_X
            initEnd.x = ((1- VFX_ABS(m_xGravity))*PETAL_G1_END_X) + (VFX_ABS(m_xGravity)* (GDI_LCD_WIDTH - PETAL_G1_INIT_X));//GDI_LCD_WIDTH - PETAL_G1_INIT_X
            velocity.x = ((1- VFX_ABS(m_xGravity)))*PETAL_G1_VELOCITY_X + VFX_ABS(m_xGravity)*(-PETAL_G1_VELOCITY_X); //-PETAL_G1_VELOCITY_X
        }
    #endif        
    }
    else if (index >= G1_PETAL_COUNT && index < G1_PETAL_COUNT + G2_PETAL_COUNT)
    {
        initStart.x = PETAL_G2_INIT_X;
        initStart.y = PETAL_G2_INIT_Y;
        initEnd.x = PETAL_G2_END_X;
        initEnd.y = PETAL_G2_END_Y;
        velocity.x = PETAL_G2_VELOCITY_X;
        velocity.y = PETAL_G2_VELOCITY_Y;
        range = 0;
    }
    else
    {
        initStart.x = PETAL_G3_INIT_X;
        initStart.y = PETAL_G3_INIT_Y;
        initEnd.x = PETAL_G3_END_X;
        initEnd.y = PETAL_G3_END_Y;
        velocity.x = PETAL_G3_VELOCITY_X;
        velocity.y = PETAL_G3_VELOCITY_Y;
        range = PETAL_VELOCITY_RANGE;
    }
    
    m_petal[index]->setAnchor(0.5, 0.5);
    m_petal[index]->setInitPosRandRange(
                        initStart, 
                        initEnd);
    m_petal[index]->setInitVelocityRandRange(
                        velocity, 
                        range,
                        VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_INCREASE);

}

static vrt_render_dirty_type_enum wallpaperFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}

void VappWallpaperSakura::onCreateView()
{

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SAK", SA_start);
#endif
    m_drawnAfterCreated = VFX_FALSE;
    setBgColor(VFX_COLOR_WHITE);
    
    VFX_OBJ_CREATE(m_switchPageTimeline, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_sakuraFg1Timeline, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_sakuraFg2Timeline, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_sunshineTimeline, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_flyTimeline, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_grass, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_sakuraBg1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_sakuraBg2, VfxImageFrame, this);
#ifdef __SAKURA_SHADOW_SUPPORT__    
    VFX_OBJ_CREATE(m_sakuraShadow, VfxImageFrame, this);
#endif
    VFX_OBJ_CREATE(m_bench, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_referenceObj, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_butterfly0, VfxAnimImageFrame, this);
    VFX_OBJ_CREATE(m_butterfly1, VappSakuraFlyImageFrame, this);
    VFX_OBJ_CREATE(m_butterfly2, VappSakuraFlyImageFrame, this);
    VFX_OBJ_CREATE(m_branch, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_sakuraFg1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_sakuraFg2, VfxImageFrame, this);
#if !defined(__MMI_MAINLCD_480X800__)
    VFX_OBJ_CREATE(m_sunshine2, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_sunshine1, VfxImageFrame, this);
#endif
    VFX_OBJ_CREATE(m_petalPlayTimer, VfxTimer, this);

    VfxS32 totalPage = getTotalPage();
    VfxS32 currentPage = (totalPage - 1) / 2;
    VfxFloat unit = 1.0f, currentPageRatio = 1.0f;
    
    if (totalPage > 1)
        unit = 1.0/(VfxFloat)(totalPage - 1);     
    else
        currentPage = 0;
    
    currentPageRatio = currentPage * unit;
    
    VappWallpaperSakura *pThis = this;

    m_switchPageTimeline->setTarget(m_referenceObj);
    m_switchPageTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_switchPageTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_switchPageTimeline->setFromValue(currentPage*unit);
    m_switchPageTimeline->setIsFromCurrent(VFX_TRUE);
    
    VfxImageSrc grass(VAPP_WALLPAPER_IMG_SAKURA_GRASS);
    m_grass->setImgContent(grass);
    m_grass->setPos(
                0, 
                GRASS_LEFTMOST_PAGE_START_Y + currentPageRatio * (GRASS_RIGHTMOST_PAGE_START_Y - GRASS_LEFTMOST_PAGE_START_Y));
    m_grass->setSize(grass.getSize().width, grass.getSize().height);
    m_grass->setPropertyEffectCallback(
                                m_referenceObj,
                                grassFpeCallback, 
                                &pThis,
                                sizeof(pThis));
    
    VfxImageSrc sakuraBg1(VAPP_WALLPAPER_IMG_SAKURA_BG1);
    m_sakuraBg1->setImgContent(sakuraBg1);
    m_sakuraBg1->setPos(
        0, 
        SAKURA_LEFTMOST_PAGE_START_Y + currentPageRatio * (SAKURA_RIGHTMOST_PAGE_START_Y - SAKURA_LEFTMOST_PAGE_START_Y));
    m_sakuraBg1->setSize(sakuraBg1.getSize().width, sakuraBg1.getSize().height);
    m_sakuraBg1->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sakuraBg1FpeCallback, 
                                    &pThis,
                                    sizeof(pThis));  
    
    VfxImageSrc sakuraBg2(VAPP_WALLPAPER_IMG_SAKURA_BG2);
    m_sakuraBg2->setImgContent(sakuraBg2);
    m_sakuraBg2->setPos(
        m_sakuraBg1->getPos().x, 
        m_sakuraBg1->getPos().y + m_sakuraBg1->getBounds().getHeight());
    m_sakuraBg2->setSize(sakuraBg2.getSize().width, sakuraBg2.getSize().height);    
    m_sakuraBg2->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sakuraBg2FpeCallback, 
                                    &pThis,
                                    sizeof(pThis));  

#ifdef __SAKURA_SHADOW_SUPPORT__
    VfxImageSrc sakuraShadow(VAPP_WALLPAPER_IMG_SAKURA_SHADOW);
    m_sakuraShadow->setImgContent(sakuraShadow);
    m_sakuraShadow->setPos(
                        SHADOW_LEFTMOST_PAGE_START_X, 
                        SHADOW_LEFTMOST_PAGE_START_Y + currentPageRatio * (SHADOW_RIGHTMOST_PAGE_START_Y - SHADOW_LEFTMOST_PAGE_START_Y));
    m_sakuraShadow->setSize(sakuraShadow.getSize().width, sakuraShadow.getSize().height);
    m_sakuraShadow->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sakuraShadowFpeCallback, 
                                    &pThis,
                                    sizeof(pThis),
                                    VRT_FPE_TRIGGER_TYPE_EVERYTIME); 
#endif    
    VfxImageSrc bench(VAPP_WALLPAPER_IMG_SAKURA_BENCH);
    m_bench->setImgContent(bench);
    m_bench->setPos(
                BENCH_LEFTMOST_PAGE_START_X, 
                BENCH_LEFTMOST_PAGE_START_Y + currentPageRatio * (BENCH_RIGHTMOST_PAGE_START_Y - BENCH_LEFTMOST_PAGE_START_Y));
    m_bench->setSize(bench.getSize().width, bench.getSize().height);
    m_bench->setPropertyEffectCallback(
                                    m_referenceObj,
                                    benchFpeCallback, 
                                    &pThis,
                                    sizeof(pThis));  

    m_referenceObj->setPos(
                0, 
                0);
    m_referenceObj->setSize(10, 10);
    m_referenceObj->setOpacity(0.0f);

    // make this wallpaper content dirty.
    setPropertyEffectCallback(m_referenceObj,
                            wallpaperFpeCallback,
                            0, 
                            NULL,
                            VRT_FPE_TRIGGER_TYPE_DIRTY);
    VfxImageSrc butterfly0(VAPP_WALLPAPER_IMG_SAKURA_BUTTERFLY0);
    m_butterfly0->setAnchor(0.5, 0.5);
    m_butterfly0->setImgContent(butterfly0);
    m_butterfly0->setPos(
                BUTTERFLY0_LEFTMOST_PAGE_CENTER_X,
                BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y + currentPageRatio * (BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y - BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y));
    m_butterfly0->setSize(butterfly0.getSize().width, butterfly0.getSize().height);
    //m_butterfly0->playImgContent();
    m_butterfly0->play();
    m_butterfly0->setPropertyEffectCallback(
                                    m_referenceObj,
                                    butterfly0FpeCallback, 
                                    &pThis,
                                    sizeof(pThis)); 
    

    VfxImageSrc butterfly(VAPP_WALLPAPER_IMG_SAKURA_BUTTERFLY);
    m_butterfly1->setAnchor(0.5, 0.5);
    m_butterfly1->setInitPosRandRange(
                        VfxPoint(BUTTERFLY_INIT_X, BUTTERFLY_INIT_Y), 
                        VfxPoint(BUTTERFLY_END_X, BUTTERFLY_END_Y));
    m_butterfly1->setInitVelocityRandRange(
                        VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                        BUTTERFLY_VELOCITY_RANGE,
                        VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_INCREASE);
    m_butterfly1->setImgContent(butterfly);
    m_butterfly1->setSize(butterfly.getSize().width, butterfly.getSize().height);
    //m_butterfly1->playImgContent();
    m_butterfly1->play();
    m_butterfly1->setPropertyEffectCallback(
                                    m_referenceObj,
                                    butterfly1FpeCallback, 
                                    &pThis,
                                    sizeof(pThis));
    
    m_butterfly2->setAnchor(0.5, 0.5);
    m_butterfly2->setInitPosRandRange(
                        VfxPoint(BUTTERFLY_INIT_X+BUTTERFLY_DISTANCE, BUTTERFLY_INIT_Y), 
                        VfxPoint(BUTTERFLY_END_X+BUTTERFLY_DISTANCE, BUTTERFLY_END_Y));
    m_butterfly2->setInitVelocityRandRange(
                        VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                        BUTTERFLY_VELOCITY_RANGE,
                        VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_DECREASE);
    m_butterfly2->setImgContent(butterfly);
    m_butterfly2->setSize(butterfly.getSize().width, butterfly.getSize().height);
    m_butterfly2->setPropertyEffectCallback(
                                    m_referenceObj,
                                    butterfly2FpeCallback, 
                                    &pThis,
                                    sizeof(pThis));
   
    VfxImageSrc branch(VAPP_WALLPAPER_IMG_SAKURA_BRANCH);
    m_branch->setImgContent(branch);
    m_branch->setPos(
                BRANCH_LEFTMOST_PAGE_START_X, 
                BRANCH_LEFTMOST_PAGE_START_Y + currentPageRatio * (BRANCH_RIGHTMOST_PAGE_START_Y - BRANCH_LEFTMOST_PAGE_START_Y));
    m_branch->setSize(branch.getSize().width, branch.getSize().height);
    m_branch->setPropertyEffectCallback(
                                    m_referenceObj,
                                    branchFpeCallback, 
                                    &pThis,
                                    sizeof(pThis));
    
    VfxImageSrc sakuraFg1(VAPP_WALLPAPER_IMG_SAKURA_FG1);
    m_sakuraFg1->setImgContent(sakuraFg1);
    m_sakuraFg1->setPos(
                    SAKURAFG1_LEFTMOST_PAGE_START_X,
                    SAKURAFG1_LEFTMOST_PAGE_START_Y + currentPageRatio * (SAKURAFG1_RIGHTMOST_PAGE_START_Y - SAKURAFG1_LEFTMOST_PAGE_START_Y));
    m_sakuraFg1->setSize(sakuraFg1.getSize().width, sakuraFg1.getSize().height);
    m_sakuraFg1->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sakuraFg1FpeCallback,
                                    &pThis,
                                    sizeof(pThis),
                                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);

    VfxImageSrc sakuraFg2(VAPP_WALLPAPER_IMG_SAKURA_FG2);
    m_sakuraFg2->setImgContent(sakuraFg2);
    m_sakuraFg2->setPos(
                    SAKURAFG2_LEFTMOST_PAGE_START_X, 
                    SAKURAFG2_LEFTMOST_PAGE_START_Y + currentPageRatio * (SAKURAFG2_RIGHTMOST_PAGE_START_Y - SAKURAFG2_LEFTMOST_PAGE_START_Y));
    m_sakuraFg2->setSize(sakuraFg2.getSize().width, sakuraFg2.getSize().height);
    m_sakuraFg2->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sakuraFg2FpeCallback,
                                    &pThis,
                                    sizeof(pThis),
                                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);
#if !defined(__MMI_MAINLCD_480X800__)
    VfxImageSrc sunshine1(VAPP_WALLPAPER_IMG_SAKURA_SUNSHINE1);
    VfxImageSrc sunshine2(VAPP_WALLPAPER_IMG_SAKURA_SUNSHINE2);
    m_sunshine1->setImgContent(sunshine2);
    m_sunshine1->setAnchor(0.5, 0.5);
    m_sunshine1->setPos(
                    SUNSHINE1_LEFTMOST_PAGE_CENTER_X,
                    SUNSHINE1_LEFTMOST_PAGE_CENTER_Y + currentPageRatio * (SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y - SUNSHINE1_LEFTMOST_PAGE_CENTER_Y));
    m_sunshine1->setSize(sunshine2.getSize().width, sunshine2.getSize().height);
    m_sunshine1->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sunshine1FpeCallback,
                                    &pThis,
                                    sizeof(pThis),
                                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);

    m_sunshine2->setImgContent(sunshine2);
    m_sunshine2->setAnchor(0.5, 0.5);
    m_sunshine2->setPos(
                    SUNSHINE2_LEFTMOST_PAGE_CENTER_X,
                    SUNSHINE2_LEFTMOST_PAGE_CENTER_Y + currentPageRatio * (SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y - SUNSHINE2_LEFTMOST_PAGE_CENTER_Y));
    m_sunshine2->setSize(sunshine2.getSize().width, sunshine2.getSize().height);
    m_sunshine2->setPropertyEffectCallback(
                                    m_referenceObj,
                                    sunshine2FpeCallback,
                                    &pThis,
                                    sizeof(pThis),
                                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);
#endif /* !defined(__MMI_MAINLCD_480X800__) */   
    //============================================================================================//
    m_sakuraFg1Timeline->setTarget(m_referenceObj);
    m_sakuraFg1Timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
    m_sakuraFg1Timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_sakuraFg1Timeline->setFromValue(0.0);
    m_sakuraFg1Timeline->setToValue(1.0);
    m_sakuraFg1Timeline->setIsFromCurrent(VFX_TRUE);
    m_sakuraFg1Timeline->setDuration(ANIMATION1_DURATION);
    m_sakuraFg1Timeline->m_signalStopped.connect(this, &VappWallpaperSakura::onAnim1Complete);
    m_sakuraFg1Timeline->start();

    m_sakuraFg2Timeline->setTarget(m_referenceObj);
    m_sakuraFg2Timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_sakuraFg2Timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_sakuraFg2Timeline->setFromValue(0.0);
    m_sakuraFg2Timeline->setToValue(1.0);
    m_sakuraFg2Timeline->setIsFromCurrent(VFX_TRUE);
    m_sakuraFg2Timeline->setDuration(ANIMATION2_DURATION);
    m_sakuraFg2Timeline->m_signalStopped.connect(this, &VappWallpaperSakura::onAnim2Complete);
    m_sakuraFg2Timeline->start();
    
    m_sakuraFg1Transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    m_sakuraFg1Transform.data.matrix3x3.m[0] = vfxCos(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE));
    m_sakuraFg1Transform.data.matrix3x3.m[1] = vfxSin(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE));
    m_sakuraFg1Transform.data.matrix3x3.m[2] = 0;
    m_sakuraFg1Transform.data.matrix3x3.m[3] = -vfxSin(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE));
    m_sakuraFg1Transform.data.matrix3x3.m[4] = vfxCos(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE));
    m_sakuraFg1Transform.data.matrix3x3.m[5] = 0;
    m_sakuraFg1Transform.data.matrix3x3.m[6] = -vfxCos(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE))*SAKURAFG1_ROTATE_PIVOT_X +
                                                vfxSin(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE))*SAKURAFG1_ROTATE_PIVOT_Y + 
                                               SAKURAFG1_ROTATE_PIVOT_X;
    m_sakuraFg1Transform.data.matrix3x3.m[7] = -vfxSin(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE))*SAKURAFG1_ROTATE_PIVOT_X - 
                                                vfxCos(VFX_DEG_TO_RAD(-SAKURA_ROTATE_DEGREE))*SAKURAFG1_ROTATE_PIVOT_Y +
                                               SAKURAFG1_ROTATE_PIVOT_Y;
    m_sakuraFg1Transform.data.matrix3x3.m[8] = 1;


    m_shadowTransform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    m_shadowTransform.data.matrix3x3.m[0] = vfxCos(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
    m_shadowTransform.data.matrix3x3.m[1] = vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
    m_shadowTransform.data.matrix3x3.m[2] = 0;
    m_shadowTransform.data.matrix3x3.m[3] = -vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
    m_shadowTransform.data.matrix3x3.m[4] = vfxCos(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
    m_shadowTransform.data.matrix3x3.m[5] = 0;
    m_shadowTransform.data.matrix3x3.m[6] = -vfxCos(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE))*SHADOW_ROTATE_PIVOT_X +
                                                vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE))*SHADOW_ROTATE_PIVOT_Y + 
                                               SHADOW_ROTATE_PIVOT_X;
    m_shadowTransform.data.matrix3x3.m[7] = -vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE))*SHADOW_ROTATE_PIVOT_X - 
                                                vfxCos(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE))*SHADOW_ROTATE_PIVOT_Y +
                                               SHADOW_ROTATE_PIVOT_Y;
    m_shadowTransform.data.matrix3x3.m[8] = 1;


    m_sakuraFg2Transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    m_sakuraFg2Transform.data.matrix3x3.m[0] = vfxCos(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE));
    m_sakuraFg2Transform.data.matrix3x3.m[1] = vfxSin(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE));
    m_sakuraFg2Transform.data.matrix3x3.m[2] = 0;
    m_sakuraFg2Transform.data.matrix3x3.m[3] = -vfxSin(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE));
    m_sakuraFg2Transform.data.matrix3x3.m[4] = vfxCos(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE));
    m_sakuraFg2Transform.data.matrix3x3.m[5] = 0;
    m_sakuraFg2Transform.data.matrix3x3.m[6] = -vfxCos(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE))*SAKURAFG2_ROTATE_PIVOT_X +
                                                vfxSin(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE))*SAKURAFG2_ROTATE_PIVOT_Y + 
                                               SAKURAFG2_ROTATE_PIVOT_X;
    m_sakuraFg2Transform.data.matrix3x3.m[7] = -vfxSin(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE))*SAKURAFG2_ROTATE_PIVOT_X - 
                                                vfxCos(VFX_DEG_TO_RAD(SAKURA_ROTATE_DEGREE))*SAKURAFG2_ROTATE_PIVOT_Y +
                                               SAKURAFG2_ROTATE_PIVOT_Y;
    m_sakuraFg2Transform.data.matrix3x3.m[8] = 1;


    m_sunshineTimeline->setTarget(m_referenceObj);
    m_sunshineTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_X);
    m_sunshineTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_sunshineTimeline->setFromValue(0.0);
    m_sunshineTimeline->setToValue(1.0);
    m_sunshineTimeline->setIsFromCurrent(VFX_TRUE);
    m_sunshineTimeline->setDuration(SUNSHINE_MOVE_DURATION);
    m_sunshineTimeline->m_signalStopped.connect(this, &VappWallpaperSakura::onSunshineAnimComplete);
    m_sunshineTimeline->start();

    m_flyTimeline->setTarget(m_referenceObj);
    m_flyTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_Y);
    m_flyTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_flyTimeline->setFromValue(0.0);
    m_flyTimeline->setToValue(1.0);
    m_flyTimeline->setRepeatCount(1);
    m_flyTimeline->setDuration(BUTTERFLY_MOVE_DURATION);
    m_flyTimeline->m_signalStopped.connect(this, &VappWallpaperSakura::onFlyAnimComplete);
    m_flyTimeline->start();

#ifdef MOTION_SENSOR_SUPPORT
    m_motionHandle = -1;
    m_xGravity = 0;
    m_yGravity = 0;
    m_zGravity = 0;
    m_motionHandle = srv_sensor_start_listen(
                                SRV_SENSOR_MOTION_TILT,
                                NULL, 
                                onMotionTiltDetailCallback,
                                (void*)pThis);
#endif 

    m_petalPlayTimer->setStartDelay(0);
    m_petalPlayTimer->setDuration(PETAL_PLAY_INTERVAL);
    m_petalPlayTimer->m_signalTick.connect(this, &VappWallpaperSakura::onTimerTick);

    petalFPEUserData userData;
    userData.pWallpaper = (void*)pThis;
    VfxImageSrc petal(VAPP_WALLPAPER_IMG_SAKURA_PETAL);
    
    for (VfxU8 i = 0; i < MAX_PETAL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_petal[i], VappSakuraFlyImageFrame, this);
        userData.index = i;
        
        m_petal[i]->setAnchor(0.5, 0.5);
        m_petal[i]->setImgContent(petal);
        m_petal[i]->setSize(petal.getSize().width, petal.getSize().height);
        m_petal[i]->setPropertyEffectCallback(
                                    m_referenceObj,
                                    petalFpeCallback, 
                                    &userData,
                                    sizeof(userData)); 

        initPetalPos(i);
    }
    m_petalPlayTimer->start();


}


void VappWallpaperSakura::onReleaseView()
{
    m_drawnAfterCreated = VFX_FALSE;
#ifdef MOTION_SENSOR_SUPPORT
    if (m_motionHandle > 0)
    {
        srv_sensor_stop_listen(m_motionHandle);
        m_xGravity = 0;
        m_yGravity = 0;
        m_zGravity = 0;
        m_motionHandle = -1;
    }
#endif 

    m_petalPlayIndex = 0;
    for (VfxU8 i = 0; i < MAX_PETAL_COUNT; i++)
        VFX_OBJ_CLOSE(m_petal[i]);

    VFX_OBJ_CLOSE(m_petalPlayTimer);
#if !defined(__MMI_MAINLCD_480X800__)    
    VFX_OBJ_CLOSE(m_sunshine1);
    VFX_OBJ_CLOSE(m_sunshine2);
#endif  
    VFX_OBJ_CLOSE(m_sakuraFg2);
    VFX_OBJ_CLOSE(m_sakuraFg1);    
    VFX_OBJ_CLOSE(m_branch);
    VFX_OBJ_CLOSE(m_butterfly2);
    VFX_OBJ_CLOSE(m_butterfly1);
    VFX_OBJ_CLOSE(m_butterfly0);
    VFX_OBJ_CLOSE(m_referenceObj);
    VFX_OBJ_CLOSE(m_bench);
#ifdef __SAKURA_SHADOW_SUPPORT__
    VFX_OBJ_CLOSE(m_sakuraShadow);
#endif
    VFX_OBJ_CLOSE(m_sakuraBg2);
    VFX_OBJ_CLOSE(m_sakuraBg1);
    VFX_OBJ_CLOSE(m_grass);
    VFX_OBJ_CLOSE(m_flyTimeline);
    VFX_OBJ_CLOSE(m_sunshineTimeline);
    VFX_OBJ_CLOSE(m_sakuraFg2Timeline);
    VFX_OBJ_CLOSE(m_sakuraFg1Timeline);
    VFX_OBJ_CLOSE(m_switchPageTimeline);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SAK", SA_stop);
#endif
}


void VappWallpaperSakura::onSerializeView()
{

}

void VappWallpaperSakura::onRestoreView()
{

}


void VappWallpaperSakura::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_SAKURA);
}


MMI_IMG_ID VappWallpaperSakura::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_SAKURA_THUMBNAIL;
}


void VappWallpaperSakura::onSuspend()
{
    // stop timeline
    m_isSuspended = VFX_TRUE;
//    m_switchPageTimeline->stop();
    m_sakuraFg1Timeline->stop();
    m_sakuraFg2Timeline->stop();
    m_sunshineTimeline->stop();
    m_flyTimeline->stop();
    m_petalPlayTimer->stop();

    m_grass->setPos(m_grass->forceGetPos());
    m_sakuraBg1->setPos(m_sakuraBg1->forceGetPos());
    m_sakuraBg2->setPos(m_sakuraBg2->forceGetPos());
#ifdef __SAKURA_SHADOW_SUPPORT__
    m_sakuraShadow->setPos(m_sakuraShadow->forceGetPos());
#endif
    m_bench->setPos(m_bench->forceGetPos());    
    m_referenceObj->setPos(m_referenceObj->forceGetPos());
    m_butterfly0->setPos(m_butterfly0->forceGetPos());
    m_branch->setPos(m_branch->forceGetPos());
    m_sakuraFg1->setPos(m_sakuraFg1->forceGetPos());
    m_sakuraFg2->setPos(m_sakuraFg2->forceGetPos());
#if !defined(__MMI_MAINLCD_480X800__) 
    m_sunshine2->setPos(m_sunshine2->forceGetPos());
    m_sunshine1->setPos(m_sunshine1->forceGetPos());
#endif    
    //m_butterfly0->stopImgContent();
    m_butterfly0->stop();
    //m_butterfly1->stopImgContent();
    m_butterfly1->stop();
    //m_butterfly2->stopImgContent();
    m_butterfly2->stop();

    m_butterfly1->setInitPosRandRange(
                        VfxPoint(BUTTERFLY_INIT_X, BUTTERFLY_INIT_Y), 
                        VfxPoint(BUTTERFLY_END_X, BUTTERFLY_END_Y));
    m_butterfly1->setInitVelocityRandRange(
                        VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                        BUTTERFLY_VELOCITY_RANGE,
                        VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_INCREASE);

    m_butterfly2->setInitPosRandRange(
                        VfxPoint(BUTTERFLY_INIT_X, BUTTERFLY_INIT_Y), 
                        VfxPoint(BUTTERFLY_END_X, BUTTERFLY_END_Y));
    m_butterfly2->setInitVelocityRandRange(
                        VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                        BUTTERFLY_VELOCITY_RANGE,
                        VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_DECREASE);
            
    for (VfxU8 i = 0; i < MAX_PETAL_COUNT; i++)
    {
        m_petal[i]->setHidden(VFX_TRUE);
        //m_petal[i]->stopImgContent();
        m_petal[i]->stop();

        initPetalPos(i);
    }
    m_petalPlayIndex = 0;

    
}

void VappWallpaperSakura::onResume()
{
    // resume timeline
    m_isSuspended = VFX_FALSE;
//    m_switchPageTimeline->start();
    m_sakuraFg1Timeline->start();
    m_sakuraFg2Timeline->start();
    m_sunshineTimeline->start();
    m_flyTimeline->start();

    //m_butterfly0->playImgContent();
    m_butterfly0->play();
    //m_butterfly1->playImgContent();
    m_butterfly1->play();
    
    for (VfxU8 i = 0; i < MAX_PETAL_COUNT; i++)
    {
        m_petal[i]->setHidden(VFX_FALSE);
    }    
    m_petalPlayTimer->start();

#if defined(__MMI_MAINLCD_480X800__)
    m_switchPageTimeline->setToValue(m_currPage);
    m_switchPageTimeline->setDuration(SWITCH_PAGE_DURATION);
    m_switchPageTimeline->start();
#endif    
}

void VappWallpaperSakura::onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos)
{
    VfxFloat newPageIndex = curPos;
    if (newPageIndex < 0) 
        newPageIndex = 0;
    else if (newPageIndex > 1)
        newPageIndex = 1;
        
    m_currPage = newPageIndex;
    VfxFloat oldPageIndex = oldPos;

    // in the first commit, make sure the 
    // frame's FPE has a healty current value.
    if(!m_drawnAfterCreated && m_referenceObj)
    {
        m_referenceObj->setPosZ(newPageIndex);
    }   
    // set animation value
    m_switchPageTimeline->setToValue(newPageIndex);
    m_switchPageTimeline->setDuration(SWITCH_PAGE_DURATION);
    
    m_switchPageTimeline->start();
    VFX_TRACE(("[SAKURA] onDesktopBoundsChanged oldPageIndex = %f newPageIndex = %f\n", oldPageIndex, newPageIndex));
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_SAKURA_DESKTOPCHANGE_NEW, (VfxU32)(oldPageIndex*100), (VfxU32)(newPageIndex*100));

}


vrt_render_dirty_type_enum VappWallpaperSakura::grassFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    pThis->m_drawnAfterCreated = VFX_TRUE;
    if (pThis->isValid() && pThis->m_switchPageTimeline->getIsEnabled())
    {
//        VFX_TRACE(("[SAKURA] FPE watch_frame->pos_z = %f\n", watch_frame->pos_z));
        target_frame->pos.y = GRASS_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (GRASS_RIGHTMOST_PAGE_START_Y - GRASS_LEFTMOST_PAGE_START_Y);
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


void VappWallpaperSakura::onAnim1Complete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        VfxFloat From = m_sakuraFg1Timeline->getFromValue();
        VfxFloat To = m_sakuraFg1Timeline->getToValue();

        if (To == 1.0f) // Fade in complete
        {
            m_sakuraFg1Timeline->setFromValue(1.0f);
            m_sakuraFg1Timeline->setToValue(0.0f);
        }
        else // To == 0.0f Fade out complete
        {
            m_sakuraFg1Timeline->setFromValue(0.0f);
            m_sakuraFg1Timeline->setToValue(1.0f);
        }

        m_sakuraFg1Timeline->setIsFromCurrent(VFX_TRUE);
        m_sakuraFg1Timeline->setDuration(ANIMATION1_DURATION);
        m_sakuraFg1Timeline->start();
    }

}


void VappWallpaperSakura::onAnim2Complete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        VfxFloat From = m_sakuraFg2Timeline->getFromValue();
        VfxFloat To = m_sakuraFg2Timeline->getToValue();

        if (To == 1.0f) // Fade in complete
        {
            m_sakuraFg2Timeline->setFromValue(1.0f);
            m_sakuraFg2Timeline->setToValue(0.0f);
        }
        else // To == 0.0f Fade out complete
        {
            m_sakuraFg2Timeline->setFromValue(0.0f);
            m_sakuraFg2Timeline->setToValue(1.0f);
        }

        m_sakuraFg2Timeline->setIsFromCurrent(VFX_TRUE);
        m_sakuraFg2Timeline->setDuration(ANIMATION2_DURATION);
        m_sakuraFg2Timeline->start();
    }

}


void VappWallpaperSakura::onSunshineAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        VfxFloat From = m_sunshineTimeline->getFromValue();
        VfxFloat To = m_sunshineTimeline->getToValue();

        if (To == 1.0f) // Fade in complete
        {
            m_sunshineTimeline->setFromValue(1.0f);
            m_sunshineTimeline->setToValue(0.0f);
        }
        else // To == 0.0f Fade out complete
        {
            m_sunshineTimeline->setFromValue(0.0f);
            m_sunshineTimeline->setToValue(1.0f);
        }

        m_sunshineTimeline->setDuration(SUNSHINE_MOVE_DURATION);
        m_sunshineTimeline->start();
    }

}


void VappWallpaperSakura::onFlyAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {  
        VfxPoint basePoint;
        VfxU8 i = 0;

        basePoint.x = m_butterfly1->getBasePoint().x + m_butterfly1->getVelocity().x;
        basePoint.y = m_butterfly1->getBasePoint().y + m_butterfly1->getVelocity().y;
        m_butterfly1->setBasePoint(basePoint);

        basePoint.x = m_butterfly2->getBasePoint().x + m_butterfly2->getVelocity().x;
        basePoint.y = m_butterfly2->getBasePoint().y + m_butterfly2->getVelocity().y;
        m_butterfly2->setBasePoint(basePoint);

        for (i = 0; i < MAX_PETAL_COUNT; i++)
        {
            if (i < m_petalPlayIndex)
            {
    //            basePoint.x = m_petal[i]->getBasePoint().x + m_petal[i]->getVelocity().x;
    //            basePoint.y = m_petal[i]->getBasePoint().y + m_petal[i]->getVelocity().y;
                basePoint = m_petal[i]->forceGetPos();
                m_petal[i]->setBasePoint(basePoint);
            }
        }
        
        if (m_butterfly1->getBasePoint().x + m_butterfly1->getSize().width < -100 ||  
            m_butterfly1->getBasePoint().y + m_butterfly1->getSize().height< -100 )
        {
            m_butterfly1->setInitPosRandRange(
                                VfxPoint(BUTTERFLY_INIT_X, BUTTERFLY_INIT_Y), 
                                VfxPoint(BUTTERFLY_END_X, BUTTERFLY_END_Y));
            m_butterfly1->setInitVelocityRandRange(
                                VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                                BUTTERFLY_VELOCITY_RANGE,
                                VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_INCREASE);
        }

        if (m_butterfly2->getBasePoint().x + m_butterfly2->getSize().width < -100 ||  
            m_butterfly2->getBasePoint().y + m_butterfly2->getSize().height< -100 )
        {
            m_butterfly2->setInitPosRandRange(
                                VfxPoint(BUTTERFLY_INIT_X, BUTTERFLY_INIT_Y), 
                                VfxPoint(BUTTERFLY_END_X, BUTTERFLY_END_Y));
            m_butterfly2->setInitVelocityRandRange(
                                VfxPoint(BUTTERFLY_VELOCITY_X, BUTTERFLY_VELOCITY_Y), 
                                BUTTERFLY_VELOCITY_RANGE,
                                VappSakuraFlyImageFrame::VELOCITY_RAND_DIRECT_DECREASE);
        }

        for (i = 0; i < MAX_PETAL_COUNT; i++)
        {
            if (m_petal[i]->getBasePoint().x + m_petal[i]->getSize().width > GDI_LCD_WIDTH ||  
                m_petal[i]->getBasePoint().y + m_petal[i]->getSize().height> GDI_LCD_HEIGHT )
            {
                initPetalPos(i);
            }
        }
        
        m_flyTimeline->setFromValue(0.0f);
        m_flyTimeline->setToValue(1.0f);
        m_flyTimeline->start();
    }
}

vrt_render_dirty_type_enum VappWallpaperSakura::sakuraBg1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && 
        pThis->m_sakuraBg1->isValid() && 
        pThis->m_switchPageTimeline->getIsEnabled())
    {
        target_frame->pos.y = SAKURA_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (SAKURA_RIGHTMOST_PAGE_START_Y - SAKURA_LEFTMOST_PAGE_START_Y);

        VFX_TRACE(("[SAKURA] sakuraBg1FpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] sakuraBg1FpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sakuraBg2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && 
        pThis->m_sakuraBg2->isValid() && 
        pThis->m_switchPageTimeline->getIsEnabled())
    {
        target_frame->pos.y = 
            SAKURA_LEFTMOST_PAGE_START_Y + 
            pThis->m_sakuraBg1->getBounds().getHeight() + 
            watch_frame->pos_z * (SAKURA_RIGHTMOST_PAGE_START_Y - SAKURA_LEFTMOST_PAGE_START_Y);
        
        VFX_TRACE(("[SAKURA] sakuraBg2FpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] sakuraBg2FpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sakuraShadowFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
#ifdef __SAKURA_SHADOW_SUPPORT__
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && pThis->m_sakuraShadow->isValid() && !pThis->m_isSuspended)
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
            target_frame->pos.y = 
                        SHADOW_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (SHADOW_RIGHTMOST_PAGE_START_Y - SHADOW_LEFTMOST_PAGE_START_Y);

        vrt_matrix3x3_struct tempTransform;
        VfxTransform identity;
        identity.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        identity.setIdentity();
        
        for (VfxU8 i = 0; i < 9; i++)
        {
            tempTransform.m[i] = ((VfxFloat)1 - watch_frame->fpe_user_0) * identity.data.matrix3x3.m[i] + 
                                 ((VfxFloat)watch_frame->fpe_user_0) * pThis->m_shadowTransform.data.matrix3x3.m[i];
        }

        target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        target_frame->transform.data.matrix3x3 = tempTransform;

        VFX_TRACE(("[SAKURA] sakuraShadowFpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
#endif
    VFX_TRACE(("[SAKURA] sakuraShadowFpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::benchFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && 
        pThis->m_bench->isValid() &&
        pThis->m_switchPageTimeline->getIsEnabled())
    {
        target_frame->pos.y = BENCH_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (BENCH_RIGHTMOST_PAGE_START_Y - BENCH_LEFTMOST_PAGE_START_Y);

        VFX_TRACE(("[SAKURA] benchFpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] benchFpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::branchFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && 
        pThis->m_branch->isValid() &&
        pThis->m_switchPageTimeline->getIsEnabled())
    {
        target_frame->pos.y = BRANCH_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (BRANCH_RIGHTMOST_PAGE_START_Y - BRANCH_LEFTMOST_PAGE_START_Y);

        VFX_TRACE(("[SAKURA] branchFpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] branchFpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sakuraFg1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    vrt_render_dirty_type_enum dirtyRet = VRT_RENDER_DIRTY_TYPE_NONE;
    
    if (pThis->isValid() && pThis->m_sakuraFg1->isValid())
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            target_frame->pos.y = SAKURAFG1_LEFTMOST_PAGE_START_Y + watch_frame->pos_z * (SAKURAFG1_RIGHTMOST_PAGE_START_Y - SAKURAFG1_LEFTMOST_PAGE_START_Y);
//            VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback FPE watch_frame->pos_z = %f\n", watch_frame->pos_z));
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_SAKURA_FG1FPECALLBACK, (VfxU32)(watch_frame->pos_z*100), target_frame->pos.y);
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        
        if (!pThis->m_isSuspended)
        {
        #if !defined(__MMI_MAINLCD_480X800__)
            vrt_matrix3x3_struct tempTransform;
            VfxTransform identity;
            identity.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            identity.setIdentity();
            
            for (VfxU8 i = 0; i < 9; i++)
            {
                tempTransform.m[i] = ((VfxFloat)1 - watch_frame->fpe_user_0) * identity.data.matrix3x3.m[i] + 
                                     ((VfxFloat)watch_frame->fpe_user_0) * pThis->m_sakuraFg1Transform.data.matrix3x3.m[i];
            }

            target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            target_frame->transform.data.matrix3x3 = tempTransform;

//            VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback FPE watch_frame->fpe_user_0 = %f\n", watch_frame->fpe_user_0));
        #else
//            VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback FPE watch_frame->fpe_user_0 = %f\n", watch_frame->fpe_user_0));           
            target_frame->pos.y = 
                        SAKURAFG1_LEFTMOST_PAGE_START_Y + 
                        watch_frame->pos_z * (SAKURAFG1_RIGHTMOST_PAGE_START_Y - SAKURAFG1_LEFTMOST_PAGE_START_Y);            
   
            target_frame->pos.y += watch_frame->fpe_user_0 * VFX_ABS(SAKURAFG1_ROTATE_PIVOT_X - SAKURAFG1_LEFTMOST_PAGE_START_X) * vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
//            VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback 2. target_frame->pos.y = %d\n", target_frame->pos.y));
            
        #endif
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        }

    }

#if !defined(__MTK_TARGET__)        
    if (dirtyRet == VRT_RENDER_DIRTY_TYPE_DIRTY)
        VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback Dirty\n"));
    else
        VFX_TRACE(("[SAKURA] sakuraFg1FpeCallback No Dirty\n"));
#endif    
    return dirtyRet;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sakuraFg2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    vrt_render_dirty_type_enum dirtyRet = VRT_RENDER_DIRTY_TYPE_NONE;
    
    if (pThis->isValid() && pThis->m_sakuraFg2->isValid())
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            target_frame->pos.y = 
                    SAKURAFG2_LEFTMOST_PAGE_START_Y + 
                    watch_frame->pos_z * (SAKURAFG2_RIGHTMOST_PAGE_START_Y - SAKURAFG2_LEFTMOST_PAGE_START_Y);
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        
        if (!pThis->m_isSuspended)
        {
        #if !defined(__MMI_MAINLCD_480X800__)  
            vrt_matrix3x3_struct tempTransform;
            VfxTransform identity;
            identity.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            identity.setIdentity();
            
            for (VfxU8 i = 0; i < 9; i++)
            {
                tempTransform.m[i] = ((VfxFloat)1 - watch_frame->filter_timing) * identity.data.matrix3x3.m[i] + 
                                     ((VfxFloat)watch_frame->filter_timing) * pThis->m_sakuraFg2Transform.data.matrix3x3.m[i];
            }

            target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            target_frame->transform.data.matrix3x3 = tempTransform;
        #else
            target_frame->pos.y = 
                        SAKURAFG2_LEFTMOST_PAGE_START_Y + 
                        watch_frame->pos_z * (SAKURAFG2_RIGHTMOST_PAGE_START_Y - SAKURAFG2_LEFTMOST_PAGE_START_Y);

            target_frame->pos.y += watch_frame->fpe_user_0 * VFX_ABS(SAKURAFG2_ROTATE_PIVOT_X - SAKURAFG2_LEFTMOST_PAGE_START_X) * vfxSin(VFX_DEG_TO_RAD(-SHADOW_ROTATE_DEGREE));
        #endif
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        
        }
    }
#if !defined(__MTK_TARGET__)        
    if (dirtyRet == VRT_RENDER_DIRTY_TYPE_DIRTY)
        VFX_TRACE(("[SAKURA] sakuraFg2FpeCallback Dirty\n"));
    else
        VFX_TRACE(("[SAKURA] sakuraFg2FpeCallback No Dirty\n"));
#endif 
    return dirtyRet;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sunshine1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    vrt_render_dirty_type_enum dirtyRet = VRT_RENDER_DIRTY_TYPE_NONE;

#if !defined(__MMI_MAINLCD_480X800__)     
    if (pThis->isValid() && pThis->m_sunshine1->isValid())
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            target_frame->pos.y = 
                    SUNSHINE1_LEFTMOST_PAGE_CENTER_Y + 
                    watch_frame->pos_z * (SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y - SUNSHINE1_LEFTMOST_PAGE_CENTER_Y);
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        }

        if (!pThis->m_isSuspended)
        {
            target_frame->pos.x = SUNSHINE1_LEFTMOST_PAGE_CENTER_X + SUNSHINE_MOVE_RANGE * watch_frame->anchor_point.x;
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;

//            VFX_TRACE(("[SAKURA] sunshine1FpeCallback FPE watch_frame->anchor_point.x = %f, target_frame->pos.x = %d\n", watch_frame->anchor_point.x, target_frame->pos.x));    
        }
    }
#endif /* !defined(__MMI_MAINLCD_480X800__) */   

#if !defined(__MTK_TARGET__)        
    if (dirtyRet == VRT_RENDER_DIRTY_TYPE_DIRTY)
        VFX_TRACE(("[SAKURA] sunshine1FpeCallback Dirty\n"));
    else
        VFX_TRACE(("[SAKURA] sunshine1FpeCallback No Dirty\n"));
#endif
    return dirtyRet;
}


vrt_render_dirty_type_enum VappWallpaperSakura::sunshine2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    vrt_render_dirty_type_enum dirtyRet = VRT_RENDER_DIRTY_TYPE_NONE;
#if !defined(__MMI_MAINLCD_480X800__)     
    if (pThis->isValid() && pThis->m_sunshine2->isValid())
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            target_frame->pos.y = 
                    SUNSHINE2_LEFTMOST_PAGE_CENTER_Y + 
                    watch_frame->pos_z * (SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y - SUNSHINE2_LEFTMOST_PAGE_CENTER_Y);
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        }

        if (!pThis->m_isSuspended)
        {
            target_frame->pos.x = SUNSHINE2_LEFTMOST_PAGE_CENTER_X - SUNSHINE_MOVE_RANGE * watch_frame->anchor_point.x;
            dirtyRet = VRT_RENDER_DIRTY_TYPE_DIRTY;
        
//            VFX_TRACE(("[SAKURA] sunshine2FpeCallback FPE watch_frame->anchor_point.x = %f, target_frame->pos.x = %d\n", watch_frame->anchor_point.x, target_frame->pos.x));    
        }
    }
#endif /* !defined(__MMI_MAINLCD_480X800__)   */

#if !defined(__MTK_TARGET__)        
    if (dirtyRet == VRT_RENDER_DIRTY_TYPE_DIRTY)
        VFX_TRACE(("[SAKURA] sunshine2FpeCallback Dirty\n"));
    else
        VFX_TRACE(("[SAKURA] sunshine2FpeCallback No Dirty\n"));
#endif
    return dirtyRet;
}


vrt_render_dirty_type_enum VappWallpaperSakura::butterfly0FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && 
        pThis->m_butterfly0->isValid() &&
        pThis->m_switchPageTimeline->getIsEnabled())
    {
        target_frame->pos.y = BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y + watch_frame->pos_z * (BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y - BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y);

        VFX_TRACE(("[SAKURA] butterfly0FpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] butterfly0FpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}

vrt_render_dirty_type_enum VappWallpaperSakura::butterfly1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && pThis->m_butterfly1->isValid() && !pThis->m_isSuspended)
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            ;
        }

        target_frame->pos.x = pThis->m_butterfly1->getBasePoint().x + pThis->m_butterfly1->getVelocity().x* watch_frame->anchor_point.y;
        target_frame->pos.y = pThis->m_butterfly1->getBasePoint().y + pThis->m_butterfly1->getVelocity().y * watch_frame->anchor_point.y;

        VfxFloat temp;

        if (watch_frame->anchor_point.y <= 0.5)
            temp = 2*vfxSin(2*VFX_DEG_TO_RAD(watch_frame->anchor_point.y * 360));
        else
            temp = 6*vfxSin(2*VFX_DEG_TO_RAD(watch_frame->anchor_point.y * 360));
        
        target_frame->pos.y += temp;

//        VFX_TRACE(("[SAKURA] butterfly1FpeCallback temp = %f\n", temp));   
//        VFX_TRACE(("[SAKURA] butterfly1FpeCallback watch_frame->anchor_point.y = %f, x = %d, y = %d\n", watch_frame->anchor_point.y, target_frame->pos.x, target_frame->pos.y));   

        VFX_TRACE(("[SAKURA] butterfly1FpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] butterfly1FpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::butterfly2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    VappWallpaperSakura *pThis = *reinterpret_cast<VappWallpaperSakura**>(user_data);
    
    if (pThis->isValid() && pThis->m_butterfly2->isValid() && !pThis->m_isSuspended)
    {
        if (pThis->m_switchPageTimeline->getIsEnabled())
        {
            ;
        }

        target_frame->pos.x = pThis->m_butterfly2->getBasePoint().x + pThis->m_butterfly2->getVelocity().x* watch_frame->anchor_point.y;
        target_frame->pos.y = pThis->m_butterfly2->getBasePoint().y + pThis->m_butterfly2->getVelocity().y * watch_frame->anchor_point.y;

        VfxFloat temp;

        if (watch_frame->anchor_point.y <= 0.5)
            temp = 2*vfxSin(2*VFX_DEG_TO_RAD(watch_frame->anchor_point.y * 360));
        else
            temp = 6*vfxSin(2*VFX_DEG_TO_RAD(watch_frame->anchor_point.y * 360));
        
        target_frame->pos.y += temp;

        VFX_TRACE(("[SAKURA] butterfly2FpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] butterfly2FpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VappWallpaperSakura::petalFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size)
{
    petalFPEUserData* pPetalUserData = (petalFPEUserData*)user_data;
    VappWallpaperSakura *pThis = (VappWallpaperSakura*)(pPetalUserData->pWallpaper);
    VfxU8 index = (VfxU8)(pPetalUserData->index);
    
    if (pThis->isValid() && 
        pThis->m_petal[index]->isValid() && 
        index < pThis->m_petalPlayIndex && 
        !pThis->m_isSuspended)
    {
            target_frame->pos.x = pThis->m_petal[index]->getBasePoint().x + 
                                  (pThis->m_petal[index]->getVelocity().x * watch_frame->anchor_point.y);
            target_frame->pos.y = pThis->m_petal[index]->getBasePoint().y + 
                                  (pThis->m_petal[index]->getVelocity().y * watch_frame->anchor_point.y);
    #ifdef MOTION_SENSOR_SUPPORT
        if (target_frame->pos.y > 10 && target_frame->pos.x > 0 && index < G1_PETAL_COUNT)
        {
            VfxFloat time = (VfxFloat)(target_frame->pos.y) / (VfxFloat)pThis->m_petal[index]->getVelocity().y;
            VfxPoint newVelocity;

//            VFX_TRACE(("[SAKURA] petalFpeCallback old target_frame->pos.x = %d\n", target_frame->pos.x));

            newVelocity = pThis->m_petal[index]->getVelocity();
            newVelocity.x += pThis->m_xGravity * PETAL_MOTIONSENSOR_ACC_X * time;
//            newVelocity.x += (pThis->m_zGravity * -1) * PETAL_MOTIONSENSOR_ACC_Z * time;
            pThis->m_petal[index]->setVelocity(newVelocity);
            
            target_frame->pos.x = pThis->m_petal[index]->getBasePoint().x + 
                                  (pThis->m_petal[index]->getVelocity().x * watch_frame->anchor_point.y);

//            VFX_TRACE(("[SAKURA] petalFpeCallback new target_frame->pos.x = %d\n", target_frame->pos.x));
        }
    #endif /* MOTION_SENSOR_SUPPORT */

//        VFX_TRACE(("[SAKURA] petalFpeCallback index = %d\n", index));   
//        VFX_TRACE(("[SAKURA] petalFpeCallback watch_frame->anchor_point.y = %f, x = %d, y = %d\n", watch_frame->anchor_point.y, target_frame->pos.x, target_frame->pos.y));        
        VFX_TRACE(("[SAKURA] petalFpeCallback Dirty\n"));
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }
    VFX_TRACE(("[SAKURA] petalFpeCallback No Dirty\n"));
    return VRT_RENDER_DIRTY_TYPE_NONE;
}


void VappWallpaperSakura::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    ASSERT(m_petalPlayIndex < MAX_PETAL_COUNT);

    if (m_petalPlayIndex == 2)
        //m_butterfly2->playImgContent();  
        m_butterfly2->play();  
    
    //m_petal[m_petalPlayIndex++]->playImgContent();
    m_petal[m_petalPlayIndex++]->play();
   
    if (m_petalPlayIndex >= MAX_PETAL_COUNT)
        m_petalPlayTimer->stop();
}

#ifdef MOTION_SENSOR_SUPPORT
void VappWallpaperSakura::onMotionTiltDetailCallback(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    VappWallpaperSakura *pThis = (VappWallpaperSakura*)(user_data);
    
    srv_sensor_motion_tilt_struct *p_tilt;
    p_tilt = (srv_sensor_motion_tilt_struct *)sensor_data;

    //VfxFloat cos_theta = cos(p_tilt->angle.gx * PI / 180);
    //VfxFloat sin_theta = sin(p_tilt->angle.gy * PI / 180);
    //ownerDraw->setGravity(cos_theta, sin_theta, 0);

    pThis->m_xGravity = (VfxFloat)p_tilt->acc.x / 980.0;
    pThis->m_yGravity = (VfxFloat)p_tilt->acc.y / 980.0;
    pThis->m_zGravity = (VfxFloat)p_tilt->acc.z / 980.0;

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_SAKURA_MOTION_TILT, p_tilt->acc.x, p_tilt->acc.y, p_tilt->acc.z);
}
#endif /* MOTION_SENSOR_SUPPORT */

#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
