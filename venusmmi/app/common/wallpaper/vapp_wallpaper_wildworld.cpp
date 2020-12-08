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
 *  vapp_wallpaper_wildworld.cpp
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "stdlib.h"
#include "vapp_wallpaper_wildworld.h"
#include "mmi_rp_app_venus_wallpaper_wildworld_def.h"
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
#include "custom_mmi_default_value.h"
#include "vapp_hs_def.h"

extern "C"
{
#include "mmi_frm_nvram_gprot.h"
}

static const VfxU32 SCREEN_WIDTH = GDI_LCD_WIDTH;
static const VfxU32 SCREEN_HEIGHT = GDI_LCD_HEIGHT;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxU32 LAYER_IMG_WIDTH = 240;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 WALLPAPER_WIDTH = 360;
#else
    static const VfxU32 WALLPAPER_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_240X400__)
static const VfxU32 LAYER_IMG_WIDTH = 240;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 WALLPAPER_WIDTH = 360;
#else
    static const VfxU32 WALLPAPER_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_320X480__)
static const VfxU32 LAYER_IMG_WIDTH = 320;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 WALLPAPER_WIDTH = 480;
#else
    static const VfxU32 WALLPAPER_WIDTH = SCREEN_WIDTH;
#endif

#elif defined(__MMI_MAINLCD_480X800__)
static const VfxU32 LAYER_IMG_WIDTH = 480;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 WALLPAPER_WIDTH = 720;
#else
    static const VfxU32 WALLPAPER_WIDTH = SCREEN_WIDTH;
#endif

#else
static const VfxU32 LAYER_IMG_WIDTH = 320;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 WALLPAPER_WIDTH = 480;
#else
    static const VfxU32 WALLPAPER_WIDTH = SCREEN_WIDTH;
#endif

#endif  /* __MMI_MAINLCD_XXXXXXX__ */


class VappWallpaperGestureTranslator : public VfxObject
{
public:
    VappWallpaperGestureTranslator();
    virtual void onInit();
    
public:
    // Client should feed pen event and itself with this function
    void processPenEvent(VfxFrame *component, const VfxPenEvent &evt);
    // Retrieve last pen event fed to the translator
    const VfxPenEvent& getLastPenEvent();
    // signal invoked when a gesture is recognized
    VfxSignal2<VappWallpaperGestureTranslator*,   // sender object
               VappWallpaperGesture>             // gesture recognized
               m_signalGestureRecognized;

    // clear internal state of gesture recognizer.
    void reset();
protected:
    void onTapTimer(VfxTimer *sender);
    static VfxS32 getSquaredDistance(const VfxPoint &p1, const VfxPoint &p2);
    
private:
    static const VfxMsec DOUBLE_TAP_INTERVAL = 300;
    // we track movement by ourselves,
    // because VfxPenEvent may have exactly the same prevPos,
    // which breaks the swipe detection.
    VfxMsec m_prevTimeStamp;
    VfxS32 m_prevX;
    VfxBool m_draggingMode;
    VfxBool m_delayedTap;       // VFX_TRUE if a VG_TAP is recognized but haven't sent
    VfxPoint m_delayedTapPos;   // records position of the delayed tap gesture
    VfxTimer *m_tapTimer;       // delay timer. because we want to distinguish tap from double-tap
    VfxPenEvent m_lastPenEvent; // last pen event received
};

VappWallpaperGestureTranslator::VappWallpaperGestureTranslator():
    m_prevTimeStamp(0),
    m_prevX(0),
    m_draggingMode(VFX_FALSE),
    m_tapTimer(NULL),
    m_delayedTap(VFX_FALSE)
{
}

void VappWallpaperGestureTranslator::onInit()
{
    VfxObject::onInit();
    VFX_OBJ_CREATE(m_tapTimer, VfxTimer, this);
    m_tapTimer->m_signalTick.connect(this, &VappWallpaperGestureTranslator::onTapTimer);
    m_tapTimer->setStartDelay(DOUBLE_TAP_INTERVAL);
}

void VappWallpaperGestureTranslator::reset()
{
    m_prevTimeStamp = 0;
    m_prevX = 0;
    m_draggingMode = VFX_FALSE;
    m_delayedTap = VFX_FALSE;
    m_delayedTapPos.setZero();
}

void VappWallpaperGestureTranslator::onTapTimer(VfxTimer *sender)
{
    // signal TAP event
    m_delayedTap = VFX_FALSE;
    m_signalGestureRecognized.emit(this, VWG_TAP);
}

const VfxPenEvent& VappWallpaperGestureTranslator::getLastPenEvent()
{
    return m_lastPenEvent;
}

VfxS32 VappWallpaperGestureTranslator::getSquaredDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return vfxAbs(p1.x - p2.x) + vfxAbs(p1.y - p2.y);
}

void VappWallpaperGestureTranslator::processPenEvent(VfxFrame *component, const VfxPenEvent &e)
{
    const VfxS32 cpWidth = component->getSize().width;
    const VfxS32 cpHeight = component->getSize().height;
    const VfxS32 DRAG_THRESHOLD = cpWidth / 20;
    const VfxS32 DOUBLE_TAP_THRESHOLD = cpWidth / 5 + cpHeight / 5;
    m_lastPenEvent = e;

    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        m_prevTimeStamp = e.timeStamp;
        m_prevX = e.downPos.x;
        m_draggingMode = VFX_FALSE;
    }
    else if(VFX_PEN_EVENT_TYPE_UP == e.type)
    {
        VappWallpaperGesture gesture = VWG_NONE;
        do
        {   
            if(!m_draggingMode) // only move a little, so this is a TAP.
            {
                const VfxS32 doubleTapDist = getSquaredDistance(m_delayedTapPos, e.pos);
                if(m_delayedTap && DOUBLE_TAP_THRESHOLD > doubleTapDist)
                {
                    // already a TAP waiting, and the two tap are very near,
                    // so this is a double-tap
                    m_delayedTap = VFX_FALSE;
                    m_tapTimer->stop();
                    gesture = VWG_DOUBLE_TAP;
                }
                else
                {
                    // single TAP, wait a while (make sure it is not a double-tap)
                    m_tapTimer->stop();
                    m_tapTimer->start();
                    m_delayedTap = VFX_TRUE;
                    m_delayedTapPos = e.prevPos;
                }
                break;
            }
        }while(false);

        // clear swipe info
        m_prevTimeStamp = 0;
        m_prevX = 0;
        if(VWG_NONE != gesture)
        {
            m_signalGestureRecognized.emit(this, gesture);
        }

        if(m_draggingMode)
        {
            m_draggingMode = VFX_FALSE;
        }
    }
    else if(VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
        // maintain swipe info
        if(m_prevX != e.pos.x)
        {
            m_prevTimeStamp = e.timeStamp;
            m_prevX = e.pos.x;
        }

        if(DRAG_THRESHOLD <= getSquaredDistance(e.pos, e.downPos))
        {
            m_draggingMode = VFX_TRUE;
        }        
    }
}



/***************************************************************************** 
 * VappWallpaperWildWorld class implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Wild World Wallpaper", VappWallpaperWildWorld, VappWallpaper);

VappWallpaperWildWorld::VappWallpaperWildWorld():
    m_background(NULL),
    m_contentLayer(NULL),
    m_pterosaur(NULL),
    m_dinoLayer1(NULL),
    m_dinoLayer2(NULL),
    m_layer1(NULL),
    m_layer2(NULL),
    m_layer3(NULL),
    m_layer4(NULL),
    m_volcanoLayer(NULL),
    m_fireballLayer(NULL),
    m_charTimer(NULL),
    m_gestureTranslator(NULL)
{
}

void VappWallpaperWildWorld::onCreateView()
{
#if defined(__MMI_MAINLCD_240X320__)
    const VfxS32 bgSpeed = 25;  
    const VfxS32 bgDLayerH = 222;
    const VfxS32 bgDLayerH_2 = 14;
    const VfxS32 bgNLayerH = 222;
    const VfxS32 bgNLayerH_2 = 15;
    const VfxS32 fbLayerH = 170;
    const VfxS32 vcnLayerH = 79;
    const VfxS32 vcnLayerH_2 = 7;
    const VfxS32 vcnLayerY = 121;
    const VfxS32 layer4H = 12;
    const VfxS32 layer4H_2 = 6;
    const VfxS32 layer4Y = 197;
    const VfxS32 dinoLayer2H = 135;
    const VfxS32 dinoLayer2Y = 102; 
    const VfxS32 layer3H = 9;
    const VfxS32 layer3H_2 = 19;
    const VfxS32 layer3Y = 206;
    const VfxSize pteroSize(100, 72);   
    const VfxS32 dinoLayer1H = 160;
    const VfxS32 dinoLayer1Y = 94;
    const VfxS32 layer2H = 17;
    const VfxS32 layer2H_2 = 40;
    const VfxS32 layer2Y = 213;
    const VfxS32 layer1H = 38;
    const VfxS32 layer1H_2 = 55;
    const VfxS32 layer1Y = 227;

#elif defined(__MMI_MAINLCD_240X400__)
    const VfxS32 bgSpeed = 25;  
    const VfxS32 bgDLayerH = 288;
    const VfxS32 bgDLayerH_2 = 18;
    const VfxS32 bgNLayerH = 288;
    const VfxS32 bgNLayerH_2 = 18;
    const VfxS32 fbLayerH = 250;
    const VfxS32 vcnLayerH = 81;
    const VfxS32 vcnLayerH_2 = 14;
    const VfxS32 vcnLayerY = 177;
    const VfxS32 layer4H = 13;
    const VfxS32 layer4H_2 = 15;
    const VfxS32 layer4Y = 260;
    const VfxS32 dinoLayer2H = 163;
    const VfxS32 dinoLayer2Y = 145; 
    const VfxS32 layer3H = 10;
    const VfxS32 layer3H_2 = 26;
    const VfxS32 layer3Y = 270;
    const VfxSize pteroSize(134, 96);   
    const VfxS32 dinoLayer1H = 190;
    const VfxS32 dinoLayer1Y = 138;
    const VfxS32 layer2H = 16;
    const VfxS32 layer2H_2 = 49;
    const VfxS32 layer2Y = 282;
    const VfxS32 layer1H = 39;
    const VfxS32 layer1H_2 = 65;
    const VfxS32 layer1Y = 296;

#elif defined(__MMI_MAINLCD_320X480__)
    const VfxS32 bgSpeed = 30;  
    const VfxS32 bgDLayerH = 339;
    const VfxS32 bgDLayerH_2 = 21;
    const VfxS32 bgNLayerH = 335;
    const VfxS32 bgNLayerH_2 = 25;
    const VfxS32 fbLayerH = 400;
    const VfxS32 vcnLayerH = 104;
    const VfxS32 vcnLayerH_2 = 11;
    const VfxS32 vcnLayerY = 206;
    const VfxS32 layer4H = 15;
    const VfxS32 layer4H_2 = 9;
    const VfxS32 layer4Y = 304;
    const VfxS32 dinoLayer2H = 250;
    const VfxS32 dinoLayer2Y = 145;
    const VfxS32 layer3H = 11;
    const VfxS32 layer3H_2 = 27;
    const VfxS32 layer3Y = 315;
    const VfxSize pteroSize(179, 128);
    const VfxS32 dinoLayer1H = 250;
    const VfxS32 dinoLayer1Y = 135;
    const VfxS32 layer2H = 19;
    const VfxS32 layer2H_2 = 57;
    const VfxS32 layer2Y = 329;
    const VfxS32 layer1H = 48;
    const VfxS32 layer1H_2 = 76;
    const VfxS32 layer1Y = 355;

#elif defined(__MMI_MAINLCD_480X800__)
    const VfxS32 bgSpeed = 35;  
    const VfxS32 bgDLayerH = 478;
    const VfxS32 bgDLayerH_2 = 42;
    const VfxS32 bgNLayerH = 478;
    const VfxS32 bgNLayerH_2 = 42;
    const VfxS32 fbLayerH = 600;
    const VfxS32 vcnLayerH = 173;
    const VfxS32 vcnLayerH_2 = 58;
    const VfxS32 vcnLayerY = 292;
    const VfxS32 layer4H = 28;
    const VfxS32 layer4H_2 = 32;
    const VfxS32 layer4Y = 469;
    const VfxS32 dinoLayer2H = 280;
    const VfxS32 dinoLayer2Y = 265;
    const VfxS32 layer3H = 44;
    const VfxS32 layer3H_2 = 49;
    const VfxS32 layer3Y = 481;
    const VfxSize pteroSize(272, 196);
    const VfxS32 dinoLayer1H = 380;
    const VfxS32 dinoLayer1Y = 269;
    const VfxS32 layer2H = 39;
    const VfxS32 layer2H_2 = 99;
    const VfxS32 layer2Y = 529;
    const VfxS32 layer1H = 75;
    const VfxS32 layer1H_2 = 135;
    const VfxS32 layer1Y = 590;

#else
    const VfxS32 bgSpeed = 30;  
    const VfxS32 bgDLayerH = 339;
    const VfxS32 bgDLayerH_2 = 21;
    const VfxS32 bgNLayerH = 335;
    const VfxS32 bgNLayerH_2 = 25;
    const VfxS32 fbLayerH = 400;
    const VfxS32 vcnLayerH = 104;
    const VfxS32 vcnLayerH_2 = 11;
    const VfxS32 vcnLayerY = 206;
    const VfxS32 layer4H = 15;
    const VfxS32 layer4H_2 = 9;
    const VfxS32 layer4Y = 304;
    const VfxS32 dinoLayer2H = 250;
    const VfxS32 dinoLayer2Y = 145;
    const VfxS32 layer3H = 11;
    const VfxS32 layer3H_2 = 27;
    const VfxS32 layer3Y = 315;
    const VfxSize pteroSize(179, 128);
    const VfxS32 dinoLayer1H = 250;
    const VfxS32 dinoLayer1Y = 135;
    const VfxS32 layer2H = 19;
    const VfxS32 layer2H_2 = 57;
    const VfxS32 layer2Y = 329;
    const VfxS32 layer1H = 48;
    const VfxS32 layer1H_2 = 76;
    const VfxS32 layer1Y = 355;

#endif

    VFX_OBJ_CREATE(m_gestureTranslator, VappWallpaperGestureTranslator, this);
    m_gestureTranslator->m_signalGestureRecognized.connect(this, &VappWallpaperWildWorld::onGesture);

    // Background day and night layer
    VFX_OBJ_CREATE(m_background, VappWildWorldDayAndNightLayer, this);
    m_background->initLayer(700, 
        VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_DAY, VfxSize(LAYER_IMG_WIDTH, bgDLayerH),
        VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_DAY_2, VfxSize(LAYER_IMG_WIDTH, bgDLayerH_2),
        VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_NIGHT, VfxSize(LAYER_IMG_WIDTH, bgNLayerH),
        VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_NIGHT_2, VfxSize(LAYER_IMG_WIDTH, bgNLayerH_2));

    VFX_OBJ_CREATE(m_contentLayer, VfxFrame, this);
    m_contentLayer->setPos(0, 0);
    m_contentLayer->setSize(WALLPAPER_WIDTH, SCREEN_HEIGHT);
    m_contentLayer->setAutoAnimate(VFX_TRUE);

    // Fireball layer
    VFX_OBJ_CREATE(m_fireballLayer, VfxFrame, m_contentLayer);
    m_fireballLayer->setSize(WALLPAPER_WIDTH, fbLayerH);
    m_fireballLayer->setPos(0, 0);

    // Initialize fireball array
    for (int i = 0; i < MAX_FIREBALL_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_fireballs[i], VappWildWorldFireball, m_fireballLayer);
    }
    
    // Volcano layer
    VFX_OBJ_CREATE(m_volcanoLayer, VappWildWorldLayer, m_contentLayer);
    m_volcanoLayer->setSize(SCREEN_WIDTH*3, vcnLayerH + vcnLayerH_2);
    m_volcanoLayer->setPos(0, vcnLayerY);
    m_volcanoLayer->initLayerImage(0.95, bgSpeed,
                                   VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_5, VfxSize(LAYER_IMG_WIDTH, vcnLayerH),
                                   VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_5_2, VfxSize(LAYER_IMG_WIDTH, vcnLayerH_2),
                                   VFX_TRUE);

    // Layer4
    VFX_OBJ_CREATE(m_layer4, VappWildWorldLayer, m_contentLayer);
    m_layer4->setSize(SCREEN_WIDTH*3, layer4H + layer4H_2);
    m_layer4->setPos(0, layer4Y);
    m_layer4->initLayerImage(0.9, bgSpeed,
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_4, VfxSize(LAYER_IMG_WIDTH, layer4H),
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_4_2, VfxSize(LAYER_IMG_WIDTH, layer4H_2));

    // Dinosaur layer 2 (far)
    VFX_OBJ_CREATE(m_dinoLayer2, VappWildWorldDinoLayer, m_contentLayer);
    m_dinoLayer2->setSize(SCREEN_WIDTH*4, dinoLayer2H);
    m_dinoLayer2->setPos(0, dinoLayer2Y);
    m_dinoLayer2->initLayer(0.85, bgSpeed);
    
    // Layer3
    VFX_OBJ_CREATE(m_layer3, VappWildWorldLayer, m_contentLayer);
    m_layer3->setSize(SCREEN_WIDTH*3, layer3H + layer3H_2);
    m_layer3->setPos(0, layer3Y);
    m_layer3->initLayerImage(0.8, bgSpeed,
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_3, VfxSize(LAYER_IMG_WIDTH, layer3H),
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_3_2, VfxSize(LAYER_IMG_WIDTH, layer3H_2));

    // Pterosaur
    VFX_OBJ_CREATE(m_pterosaur, VappWildWorldPterosaur, m_contentLayer);
    m_pterosaur->setSize(pteroSize.width, pteroSize.height);
    m_pterosaur->setPos(-pteroSize.width, -pteroSize.height);
    m_pterosaur->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_WILDWORLD_CHAR_PTEROSAUR));
    m_pterosaur->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    
    // Dinosaur layer 1 (near)
    VFX_OBJ_CREATE(m_dinoLayer1, VappWildWorldDinoLayer, m_contentLayer);
    m_dinoLayer1->setSize(SCREEN_WIDTH*4, dinoLayer1H);
    m_dinoLayer1->setPos(0, dinoLayer1Y);
    m_dinoLayer1->initLayer(0.7, bgSpeed);
    
    // Layer2
    VFX_OBJ_CREATE(m_layer2, VappWildWorldLayer, m_contentLayer);
    m_layer2->setSize(SCREEN_WIDTH*3, layer2H + layer2H_2);
    m_layer2->setPos(0, layer2Y);
    m_layer2->initLayerImage(0.6, bgSpeed,
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_2, VfxSize(LAYER_IMG_WIDTH, layer2H),
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_2_2, VfxSize(LAYER_IMG_WIDTH, layer2H_2));
    // Layer1
    VFX_OBJ_CREATE(m_layer1, VappWildWorldLayer, m_contentLayer);
    m_layer1->setSize(SCREEN_WIDTH*3, layer1H + layer1H_2);
    m_layer1->setPos(0, layer1Y);
    m_layer1->initLayerImage(0, bgSpeed,
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_1, VfxSize(LAYER_IMG_WIDTH, layer1H),
                           VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_1_2, VfxSize(LAYER_IMG_WIDTH, layer1H_2));

    // Initialize timer to run the charactacter
    VFX_OBJ_CREATE(m_charTimer, VfxTimer, this);
    m_charTimer->setStartDelay(100);
    m_charTimer->setDuration(3000);
    m_charTimer->m_signalTick.connect(this, &VappWallpaperWildWorld::onTimerTick);

}

void VappWallpaperWildWorld::onReleaseView()
{
    VFX_OBJ_CLOSE(m_gestureTranslator);
    for (int i = 0; i < MAX_FIREBALL_COUNT; i++)
    {
        VFX_OBJ_CLOSE(m_fireballs[i]);
        m_fireballs[i] = NULL;
    }
}


MMI_IMG_ID VappWallpaperWildWorld::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_WILDWORLD_THUMBNAIL;
}

void VappWallpaperWildWorld::getName(VfxWString &wallpaperName)
{
    wallpaperName = VFX_WSTR_RES(STR_ID_WALLPAPER_VUI_LIVE_WILDWORLD);
    return;
}

void VappWallpaperWildWorld::onSuspend()
{
    m_charTimer->stop();
#ifndef __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__    
    m_layer1->suspend();
    m_layer2->suspend();
    m_layer3->suspend();
    m_layer4->suspend();
    m_volcanoLayer->suspend();
#endif    
    m_pterosaur->suspend();
    m_dinoLayer1->suspend();
    m_dinoLayer2->suspend();
    m_background->suspend();
    for (int i = 0; i < MAX_FIREBALL_COUNT; i++)
    {
        m_fireballs[i]->suspend();
    }
}

void VappWallpaperWildWorld::onResume()
{
    m_charTimer->start();
#ifndef __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__        
    m_layer1->resume();
    m_layer2->resume();
    m_layer3->resume();
    m_layer4->resume();
    m_volcanoLayer->resume();
#endif
    m_pterosaur->resume();
    m_dinoLayer1->resume();
    m_dinoLayer2->resume();
    m_background->resume();
    for (int i = 0; i < MAX_FIREBALL_COUNT; i++)
    {
        m_fireballs[i]->resume();
    }
}

VfxBool VappWallpaperWildWorld::onPenInput(VfxPenEvent &e)
{
    if(m_gestureTranslator)
    {
        m_gestureTranslator->processPenEvent(this, e);
    }
    
    // Bypass pen event since we're wallpaper
    return VFX_FALSE;
}

void VappWallpaperWildWorld::onGesture(VappWallpaperGestureTranslator *sender, VappWallpaperGesture gesture)
{
    if(VWG_TAP == gesture && sender)
    {
        const VfxPoint &pos = sender->getLastPenEvent().getRelDownPos(this);

        // Mouse down can trigger 3 types of interaction:
        // 1. Click on sun or moon to switch day and night
        // 2. Click on volcano to launch fireballs
        // 3. Run a character into screen
        if (m_background->mouseDown(pos))
        {
            return;
        }
        else if (volcanoHitTest(pos))
        {
            volcanoLaunch(pos);
        }
        else
        {
            runChar();
        }
    }
}

void VappWallpaperWildWorld::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    if (m_contentLayer)
    {
        VfxSize size = m_contentLayer->getBounds().size;
        VfxPoint pos = m_contentLayer->getPos();

        VfxS32 b = size.width - SCREEN_WIDTH;
        if (b > 0)
        {
            // calculate the bounds of the wallpaper
            const VfxS32 m = vfxMin(b, vfxMax((VfxS32)(b * curPos), (VfxS32)0));

            // Change wallpaper position
            pos.x = -m;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

            m_contentLayer->setPos(pos);

            VfxAutoAnimate::commit();
        }
    }

#endif
}

void VappWallpaperWildWorld::onTimerTick(VfxTimer *timer)
{
    if (rand()%2)
    {
        runChar();
    }
}

void VappWallpaperWildWorld::runChar() const
{
    if (m_pterosaur->isRunning())
    {
        // if Pterosaur is running, run the dinosaur
        if (!m_dinoLayer1->isRunning() && !m_dinoLayer2->isRunning())
        {
            if (rand()%2)
            {
                m_dinoLayer1->run();
            }
            else
            {
                m_dinoLayer2->run();
            }
        }
    }
    else
    {
        if (m_dinoLayer1->isRunning() || m_dinoLayer2->isRunning())
        {
            // if dinosaur is running, run the pterosaur
            m_pterosaur->run(rand()%3);
        }
        else
        {
            // nobody is running, pick one to run
            switch(rand()%3)
            {
            case 0:
                m_pterosaur->run(rand()%3);
                break;
            case 1:
                m_dinoLayer1->run();
                break;
            case 2:
                m_dinoLayer2->run();
                break;
            default:
                ;
            }
        }
    }
}

VfxBool VappWallpaperWildWorld::volcanoHitTest(const VfxPoint p) const
{
    const VfxPoint pos(m_volcanoLayer->forceGetPos());
    const VfxPoint contentPos(m_contentLayer->getPos());
    VfxS32 layerX = (-m_volcanoLayer->forceGetPos().x -m_contentLayer->getPos().x + p.x) % LAYER_IMG_WIDTH;

    // Define the volcano area
#if defined(__MMI_MAINLCD_240X320__)
    return (0 <= layerX && layerX <= 120) && (132 <= p.y && p.y <= 195);
#elif defined(__MMI_MAINLCD_240X400__)
    return (0 <= layerX && layerX <= 120) && (177 <= p.y && p.y <= 250);
#elif defined(__MMI_MAINLCD_320X480__)
    return (0 <= layerX && layerX <= 160) && (215 <= p.y && p.y <= 315);
#elif defined(__MMI_MAINLCD_480X800__)
    return (0 <= layerX && layerX <= 220) && (320 <= p.y && p.y <= 450);
#else
    return (0 <= layerX && layerX <= 160) && (215 <= p.y && p.y <= 315);
#endif  
}

void VappWallpaperWildWorld::volcanoLaunch(const VfxPoint scrPos) const
{
    const VfxPoint vcnLayerPos(m_volcanoLayer->forceGetPos());
    const VfxPoint cntLayerPos(m_contentLayer->getPos());
    VfxS32 relX = scrPos.x - cntLayerPos.x;

#if defined(__MMI_MAINLCD_240X320__)
    const VfxS32 yPos = 130;
    const VfxS32 vcnXPos = 60;
#elif defined(__MMI_MAINLCD_240X400__)
    const VfxS32 yPos = 188;
    const VfxS32 vcnXPos = 60;
#elif defined(__MMI_MAINLCD_320X480__)
    const VfxS32 yPos = 214;
    const VfxS32 vcnXPos = 80;
#elif defined(__MMI_MAINLCD_480X800__)
    const VfxS32 yPos = 320;
    const VfxS32 vcnXPos = 114;
#else
    const VfxS32 yPos = 214;
    const VfxS32 vcnXPos = 80;
#endif  

    VfxS32 nearX = 10000;
    VfxU32 nearIdx = 0;
    VfxS32 tempX = 0;
    VfxS32 wpWidth = (VfxS32)LAYER_IMG_WIDTH;
    for (VfxS32 i = 0; i < 3; i++)
    {
        tempX = vfxAbs(relX - (wpWidth*i + vcnXPos + vcnLayerPos.x));
        if (tempX < nearX)
        {
            nearX = tempX;
            nearIdx = i;
        }
    }

    VfxU32 num = rand()%3 + 2;
    for (VfxU32 i = 0; i < num; i++)
    {
        // Launch the fireball from the top of volcano
        VfxU32 j;
        for (j = 0; j < MAX_FIREBALL_COUNT; j++)
        {
            if (m_fireballs[j]->isAvailable())
            {
                m_fireballs[j]->launch(VfxPoint(wpWidth*nearIdx + vcnXPos + vcnLayerPos.x, yPos));
                break;
            }
        }

        if (j == MAX_FIREBALL_COUNT)
        {
            break;
        }
    }
}

/***************************************************************************** 
 * VappWildWorldCharBase class implementation
 *****************************************************************************/

void VappWildWorldCharBase::onInit()
{
    VfxFrame::onInit();
}

const VfxBool VappWildWorldCharBase::isRunning() const
{
    return m_isRunning;
}


/***************************************************************************** 
 * VappWildWorldPterosaur class implementation
 *****************************************************************************/

void VappWildWorldPterosaur::onInit()
{
    VappWildWorldCharBase::onInit();

    m_distance = 1.0f;
#if defined(__MMI_MAINLCD_240X320__)
    m_speed = 75;
    m_defSize = VfxSize(110, 72);
#elif defined(__MMI_MAINLCD_240X400__)
    m_speed = 75;
    m_defSize = VfxSize(134, 96);
#elif defined(__MMI_MAINLCD_320X480__)
    m_speed = 90;
    m_defSize = VfxSize(179, 128);
#elif defined(__MMI_MAINLCD_480X800__)
    m_speed = 105;
    m_defSize = VfxSize(272, 196);
#else
    m_speed = 90;
    m_defSize = VfxSize(179, 128);
#endif
    
    setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    VFX_OBJ_CREATE(m_timelineX, VfxS32Timeline, this);
    m_timelineX->setTarget(this);
    m_timelineX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    m_timelineX->m_signalStopped.connect(this, &VappWildWorldPterosaur::onXAnimComplete);

    VFX_OBJ_CREATE(m_timelineY, VfxS32Timeline, this);
    m_timelineY->setTarget(this);
    m_timelineY->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_timelineY->setIsFromCurrent(VFX_TRUE);
    m_timelineY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_timelineY->m_signalStopped.connect(this, &VappWildWorldPterosaur::onYAnimComplete);

    setHidden(VFX_TRUE);
}

void VappWildWorldPterosaur::run(const VfxU32 level)
{
    if (isRunning())
    {
        return;
    }

    // Define 3 different level of distance
    // Y position, speed, swing height would be initialized randomly

    m_level = level;

    VfxFloat scale; // 0 ~ 2 -> near ~ far
    switch(level)
    {
    case 2:
        scale = 0.7f;
        break;
    case 1:
        scale = 0.85f;
        break;
    default:
        scale = 1.0f;
    }

    setSize(m_defSize.width*scale, m_defSize.height*scale);

#if defined(__MMI_MAINLCD_240X320__)
    VfxS32 vDistance = 25;
    VfxS32 yRange = 15;
    VfxS32 yBase = 25;
#elif defined(__MMI_MAINLCD_240X400__)
    VfxS32 vDistance = 25;  
    VfxS32 yRange = 15;
    VfxS32 yBase = 25;
#elif defined(__MMI_MAINLCD_320X480__)
    VfxS32 vDistance = 30;
    VfxS32 yRange = 20;
    VfxS32 yBase = 14;
#elif defined(__MMI_MAINLCD_480X800__)
    VfxS32 vDistance = 40;
    VfxS32 yRange = 30;
    VfxS32 yBase = 20;
#else
    VfxS32 vDistance = 30;
    VfxS32 yRange = 20;
    VfxS32 yBase = 14;
#endif

    VfxU32 verDistance = vDistance * scale;
    m_yDuration = 1500;
    m_xDuration = 1000 * (WALLPAPER_WIDTH + getSize().width * scale) / vfxAbs((m_speed + rand()%30) * scale);
    
    int rand1 = rand()%yRange;
    m_yTop = yBase + rand1;
    m_yBottom = yBase + rand1 + verDistance;
    m_timelineY->setFromValue(m_yTop);
    m_timelineY->setToValue(m_yBottom);
    m_timelineY->setDuration(m_yDuration);
    m_timelineY->start();

    m_timelineX->setFromValue(-getSize().width);
    m_timelineX->setToValue(WALLPAPER_WIDTH);
    m_timelineX->setDuration(m_xDuration/scale);
    m_timelineX->start();

    m_isRunning = VFX_TRUE;

    setHidden(VFX_FALSE);
}

void VappWildWorldPterosaur::onXAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended)
    {
        m_isRunning = VFX_FALSE;
        m_timelineY->stop();
    }
}

void VappWildWorldPterosaur::onYAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (m_isRunning && !m_isSuspended && stopped)
    {
        VfxS32 From = m_timelineY->getFromValue();
        VfxS32 To = m_timelineY->getToValue();
        m_timelineY->setFromValue(To);
        m_timelineY->setToValue(From);
        m_timelineY->setDuration(m_yDuration);
        m_timelineY->start();
    }
}

void VappWildWorldPterosaur::suspend()
{
    if (m_isRunning)
    {
        m_timelineX->stop();
        m_timelineY->stop();
        m_isSuspended = VFX_TRUE;
    }
}

void VappWildWorldPterosaur::resume()
{
    if (m_isSuspended)
    {
        VfxPoint pos(forceGetPos());
        setPos(pos);
        VfxS32 FromX = m_timelineX->getFromValue();
        VfxS32 ToX = m_timelineX->getToValue();
        VfxS32 xDuration = FromX == ToX ? m_xDuration : m_xDuration * vfxAbs(VfxFloat(ToX - pos.x)/(FromX - ToX));

        VfxFloat scale; // 0 ~ 2 -> near ~ far
        switch(m_level)
        {
        case 2:
            scale = 0.7f;
            break;
        case 1:
            scale = 0.85f;
            break;
        default:
            scale = 1.0f;
        }

        m_timelineX->setFromValue(pos.x);
        m_timelineX->setDuration(xDuration/scale);
        m_timelineX->start();
        
        VfxS32 FromY = m_timelineY->getFromValue();
        VfxS32 ToY = m_timelineY->getToValue();
        VfxS32 yDuration = FromY == ToY ? m_yDuration : m_yDuration * vfxAbs(VfxFloat(ToY - pos.y)/(FromY - ToY));

        m_timelineY->setFromValue(pos.y);
        m_timelineY->setDuration(yDuration);
        m_timelineY->start();

        m_isSuspended = VFX_FALSE;
    }
}

/***************************************************************************** 
 * VappWildWorldDinosaur class implementation
 *****************************************************************************/

void VappWildWorldDinosaur::onInit()
{
    VappWildWorldCharBase::onInit();

    m_stepDuration = 700;
    m_stopDuration = 600;
}

void VappWildWorldDinosaur::initAnim(VappWildWorldDinoLayer *pParent, VfxU32 duration, VfxS32 stepX, VfxS32 stepY)
{
    setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    m_stepX = stepX;
    m_stepY = stepY;
    m_duration = duration*1000;
    m_parent = pParent;

    VFX_OBJ_CREATE(m_timelineX, VfxS32Timeline, this);
    m_timelineX->setTarget(this);
    m_timelineX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    m_timelineX->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_timelineX->m_signalStopped.connect(this, &VappWildWorldDinosaur::onXAnimComplete);
    
    VFX_OBJ_CREATE(m_timelineY, VfxS32Timeline, this);
    m_timelineY->setTarget(this);
    m_timelineY->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_timelineY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_timelineY->setAutoReversed(VFX_FALSE);
    m_timelineY->setAutoReversed(VFX_TRUE);
}

void VappWildWorldDinosaur::run()
{
    // Step up a single step animation
    VfxPoint pos(forceGetPos());

    m_timelineX->setFromValue(pos.x);
    m_timelineX->setToValue(pos.x - m_stepX * m_stepDuration / 1000);
    m_timelineX->setStartDelay(m_stopDuration);
    m_timelineX->setDuration(m_stepDuration);
    m_timelineX->start();

    m_timelineY->setFromValue(10 - m_stepY);
    m_timelineY->setToValue(10);
    m_timelineY->setStartDelay(m_stopDuration);
    m_timelineY->setDuration(m_stepDuration);
    m_timelineY->start();
    
    m_isRunning = VFX_TRUE;
}

void VappWildWorldDinosaur::onXAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended)
    {
        // Check if next step is needed
        // Dino moves from right to left (dinoDistance), dino layer moves from left to right (layerDistance)
        // (dinoDistance - layerDistance < SCREEN_WIDTH + getSize().width) means it walks out the screen
        VfxPoint pos(forceGetPos());
        VfxS32 dinoDistance = SCREEN_WIDTH * 4 - pos.x;
        VfxS32 layerDistance = m_parent->forceGetPos().x + (SCREEN_WIDTH * 4 - WALLPAPER_WIDTH);
        if (dinoDistance - layerDistance < WALLPAPER_WIDTH + getSize().width + 20)
        {
            setPos(pos);
            run();
        }
        else
        {
            m_parent->stop();
            m_isRunning = VFX_FALSE;
            setPos(SCREEN_WIDTH * 4, getPos().y);
        }
    }
}

void VappWildWorldDinosaur::suspend()
{
    if (isRunning())
    {
        m_timelineX->stop();
        m_timelineY->stop();
        VfxPoint pos(forceGetPos());
        setPos(pos.x, 10);
        m_isSuspended = VFX_TRUE;
    }
}

void VappWildWorldDinosaur::resume()
{
    if (m_isSuspended)
    {
        run();
        m_isSuspended = VFX_FALSE;
    }
}

/***************************************************************************** 
 * VappWildWorldDinoLayer class implementation
 *****************************************************************************/

void VappWildWorldDinoLayer::initLayer(const VfxFloat distance, const VfxS32 speed)
{
    m_distance = distance;
    m_speed = speed;
    VfxFloat scale = 1.7 - distance;
    m_duration = 1000 * SCREEN_WIDTH * 4 / vfxAbs(speed) / (1.0f - distance);
    
#if defined(__MMI_MAINLCD_240X320__)
    VfxSize dinoSize(178 * scale, 149 * scale);
    VfxU32 stepX = 70 * scale;
    VfxU32 stepY = 6 * scale;       
    VfxU32 y = 10;
#elif defined(__MMI_MAINLCD_240X400__)
    VfxSize dinoSize(213 * scale, 178 * scale);
    VfxU32 stepX = 75 * scale;
    VfxU32 stepY = 6 * scale;       
    VfxU32 y = 10;
#elif defined(__MMI_MAINLCD_320X480__)
    VfxSize dinoSize(284 * scale, 238 * scale);
    VfxU32 stepX = 90 * scale;
    VfxU32 stepY = 7 * scale;
    VfxU32 y = 20;
#elif defined(__MMI_MAINLCD_480X800__)
    VfxSize dinoSize(429 * scale, 361 * scale);
    VfxU32 stepX = 105 * scale;
    VfxU32 stepY = 11 * scale;
    VfxU32 y = 20;
#else
    VfxSize dinoSize(284 * scale, 238 * scale);
    VfxU32 stepX = 90 * scale;
    VfxU32 stepY = 7 * scale;
    VfxU32 y = 20;
#endif

    VFX_OBJ_CREATE(m_dino, VappWildWorldDinosaur, this);
    m_dino->setSize(dinoSize);
    m_dino->setPos(SCREEN_WIDTH * 4, y);
    m_dino->setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_WILDWORLD_CHAR_DINOSAUR));
    m_dino->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_dino->initAnim(this, m_duration, stepX, stepY);

    VFX_OBJ_CREATE(m_timeline, VfxS32Timeline, this);
    m_timeline->setTarget(this);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    m_timeline->setDuration(m_duration);
}

void VappWildWorldDinoLayer::run()
{
    if (isRunning())
    {
        return;
    }

#ifdef __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__
    setPos(-(SCREEN_WIDTH * 4 - WALLPAPER_WIDTH), getPos().y);
#else
    m_timeline->setFromValue(-(SCREEN_WIDTH * 4 - WALLPAPER_WIDTH));
    m_timeline->setToValue(WALLPAPER_WIDTH - SCREEN_WIDTH);
    m_timeline->start();
#endif
    m_dino->run();
}

void VappWildWorldDinoLayer::stop()
{
    m_timeline->stop();
    setPos(-(SCREEN_WIDTH * 4 - WALLPAPER_WIDTH), getPos().y);
}

const VfxBool VappWildWorldDinoLayer::isRunning() const
{
    return m_dino->isRunning();
}

void VappWildWorldDinoLayer::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended)
    {
        m_timeline->stop();
    }
}

void VappWildWorldDinoLayer::suspend()
{
    if (isRunning())
    {
        m_timeline->stop();
        m_dino->suspend();
        m_isSuspended = VFX_TRUE;
    }
}

void VappWildWorldDinoLayer::resume()
{
    if (m_isSuspended)
    {
        VfxPoint pos(forceGetPos());
        setPos(pos);
        VfxS32 From = m_timeline->getFromValue();
        VfxS32 To = m_timeline->getToValue();
        VfxS32 TLDuration = m_duration / (1 - m_distance);
        VfxS32 duration = From == To ? TLDuration : TLDuration*vfxAbs(VfxFloat(To - pos.x)/(From - To));

        
#ifdef __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__
        setPos(pos);
#else
        m_timeline->setFromValue(pos.x);
        m_timeline->setDuration(duration);
        m_timeline->start();
#endif

        m_dino->resume();

        m_isSuspended = VFX_FALSE;
    }
}

/***************************************************************************** 
 * VappWildWorldLayer class implementation
 *****************************************************************************/

void VappWildWorldLayer::initLayerImage(const VfxFloat distance, 
                                        const VfxS32 speed, 
                                        const VfxResId resIDUp, 
                                        const VfxSize sizeUp, 
                                        const VfxResId resIDDown, 
                                        const VfxSize sizeDown,
                                        const VfxBool rareTranslucent)
{
    // The layer use seamless image to play infinitely repeated horizontal animation
    // The layer movement is in reverse ratio to the distance from the nearest layer

    m_distance = distance;
    m_speed = speed;
    int dirSign = m_speed > 0 ? 1 : -1;

    m_duration = 1000 * SCREEN_WIDTH / vfxAbs(speed) / (1.0f - distance);

    VfxFrame *img1Up;
    VFX_OBJ_CREATE(img1Up, VfxFrame, this->getParent());
    img1Up->setImgContent(VfxImageSrc(resIDUp));
    img1Up->setSize(sizeUp);
    img1Up->setPos(0, getPos().y);
    if (rareTranslucent)
    {
        img1Up->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    }
    img1Up->setPropertyEffectCallback(this,
                                    FpeCallback1, 
                                    NULL,
                                    0);
    VfxFrame *img1Down;
    VFX_OBJ_CREATE(img1Down, VfxFrame, this->getParent());
    img1Down->setImgContent(VfxImageSrc(resIDDown));
    img1Down->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    img1Down->setSize(sizeDown);
    img1Down->setPos(0, getPos().y + sizeUp.height);
    img1Down->setPropertyEffectCallback(this,
                                    FpeCallback1, 
                                    NULL,
                                    0);

    VfxFrame *img2Up;
    VFX_OBJ_CREATE(img2Up, VfxFrame, this->getParent());
    img2Up->setImgContent(VfxImageSrc(resIDUp));
    img2Up->setSize(sizeUp);
    img2Up->setPos(sizeUp.width, getPos().y);
    if (rareTranslucent)
    {
        img2Up->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    }
    img2Up->setPropertyEffectCallback(this,
                                    FpeCallback2, 
                                    NULL,
                                    0);
    VfxFrame *img2Down;
    VFX_OBJ_CREATE(img2Down, VfxFrame, this->getParent());
    img2Down->setImgContent(VfxImageSrc(resIDDown));
    img2Down->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    img2Down->setSize(sizeDown);
    img2Down->setPos(sizeUp.width, getPos().y + sizeUp.height);
    img2Down->setPropertyEffectCallback(this,
                                    FpeCallback2, 
                                    NULL,
                                    0);

    VfxFrame *img3Up;
    VFX_OBJ_CREATE(img3Up, VfxFrame, this->getParent());
    img3Up->setImgContent(VfxImageSrc(resIDUp));
    img3Up->setSize(sizeUp);
    img3Up->setPos(sizeUp.width*2, getPos().y);
    if (rareTranslucent)
    {
        img3Up->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
    }
    img3Up->setPropertyEffectCallback(this,
                                    FpeCallback3, 
                                    NULL,
                                    0);
    VfxFrame *img3Down;
    VFX_OBJ_CREATE(img3Down, VfxFrame, this->getParent());
    img3Down->setImgContent(VfxImageSrc(resIDDown));
    img3Down->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    img3Down->setSize(sizeDown);
    img3Down->setPos(sizeUp.width*2, getPos().y + sizeUp.height);
    img3Down->setPropertyEffectCallback(this,
                                    FpeCallback3, 
                                    NULL,
                                    0);

    VFX_OBJ_CREATE(m_timeline, VfxS32Timeline, this);
    m_timeline->setTarget(this);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    m_timeline->setFromValue(-dirSign * LAYER_IMG_WIDTH);
    m_timeline->setToValue(0);
    m_timeline->setDurationTime(m_duration);
    m_timeline->setAutoReversed(VFX_FALSE);
    m_timeline->m_signalStopped.connect(this, &VappWildWorldLayer::onAnimComplete);
}

void VappWildWorldLayer::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    if (!m_isSuspended && stopped)
    {
        int dirSign = m_speed > 0 ? 1 : -1;
        m_timeline->setFromValue(-dirSign * LAYER_IMG_WIDTH);
        m_timeline->setToValue(0);
        m_timeline->setDurationTime(m_duration);
        m_timeline->start();
    }
}

vrt_render_dirty_type_enum VappWildWorldLayer::FpeCallback1(vrt_frame_visual_property_struct *target_frame,
                                                         const vrt_frame_visual_property_struct *watch_frame,
                                                         void *user_data,
                                                         vrt_u32 user_data_size)
{
    target_frame->pos.x = watch_frame->pos.x;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

vrt_render_dirty_type_enum VappWildWorldLayer::FpeCallback2(vrt_frame_visual_property_struct *target_frame,
                                                         const vrt_frame_visual_property_struct *watch_frame,
                                                         void *user_data,
                                                         vrt_u32 user_data_size)
{
    target_frame->pos.x = watch_frame->pos.x + target_frame->bounds.size.width;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

vrt_render_dirty_type_enum VappWildWorldLayer::FpeCallback3(vrt_frame_visual_property_struct *target_frame,
                                                         const vrt_frame_visual_property_struct *watch_frame,
                                                         void *user_data,
                                                         vrt_u32 user_data_size)
{
    target_frame->pos.x = watch_frame->pos.x + target_frame->bounds.size.width * 2;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VappWildWorldLayer::suspend()
{
    m_timeline->stop();
    m_isSuspended = VFX_TRUE;
}

void VappWildWorldLayer::resume()
{
    if (m_isSuspended)
    {
        VfxPoint pos(forceGetPos());
        setPos(pos);
        VfxS32 From = m_timeline->getFromValue();
        VfxS32 To = m_timeline->getToValue();
        VfxS32 duration = From == To ? m_duration : m_duration*vfxAbs(VfxFloat(To - pos.x)/(From - To));

        m_timeline->setFromValue(pos.x);
        m_timeline->setDuration(duration);
        m_timeline->start();

        m_isSuspended = VFX_FALSE;
    }
}


/***************************************************************************** 
 * VappWildWorldDayAndNightLayer class implementation
 *****************************************************************************/

void VappWildWorldDayAndNightLayer::initLayer(const VfxU32 duration, 
                                              const VfxResId resIdDayUp, 
                                              const VfxSize sizeDayUp, 
                                              const VfxResId resIdDayDown, 
                                              const VfxSize sizeDayDown, 
                                              const VfxResId resIdNightUp, 
                                              const VfxSize sizeNightUp,
                                              const VfxResId resIdNightDown, 
                                              const VfxSize sizeNightDown)
{
    m_duration = duration;

    setSize(SCREEN_WIDTH, sizeDayUp.height + sizeDayDown.height);
    setPos(0, 0);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    // Create night background frame    
    //VFX_OBJ_CREATE(m_frameNight, VfxFrame, this);
    //m_frameNight->setSize(SCREEN_WIDTH, sizeNightUp.height + sizeNightUp.height);
    //m_frameNight->setPos(0, -20);
    
    //VfxFrame *frameNightUp = NULL;
    VFX_OBJ_CREATE(m_frameNightUp, VfxFrame, this);
    m_frameNightUp->setImgContent(VfxImageSrc(resIdNightUp));
    m_frameNightUp->setSize(sizeNightUp);
    m_frameNightUp->setPos(0, -20);
    m_frameNightUp->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    //VfxFrame *frameNightDown = NULL;
    VFX_OBJ_CREATE(m_frameNightDown, VfxFrame, this);
    m_frameNightDown->setImgContent(VfxImageSrc(resIdNightDown));
    m_frameNightDown->setSize(sizeNightDown);
    m_frameNightDown->setPos(0, -20 + sizeNightUp.height);
    m_frameNightDown->setPropertyEffectCallback(m_frameNightUp,
                                                FpeCallback, 
                                                NULL,
                                                0);

    // Create day background frame
    //VFX_OBJ_CREATE(m_frameDay, VfxFrame, this);
    //m_frameDay->setSize(SCREEN_WIDTH, sizeDayUp.height + sizeDayUp.height);
    //m_frameDay->setPos(0, -20);
    
    //VfxFrame *frameDayUp = NULL;
    VFX_OBJ_CREATE(m_frameDayUp, VfxFrame, this);
    m_frameDayUp->setImgContent(VfxImageSrc(resIdDayUp));
    m_frameDayUp->setSize(sizeDayUp);
    m_frameDayUp->setPos(0, -20);
    m_frameDayUp->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    //VfxFrame *frameDayDown = NULL;
    VFX_OBJ_CREATE(m_frameDayDown, VfxFrame, this);
    m_frameDayDown->setImgContent(VfxImageSrc(resIdDayDown));
    m_frameDayDown->setSize(sizeDayDown);
    m_frameDayDown->setPos(0, -20 + sizeDayUp.height);
    m_frameDayDown->setPropertyEffectCallback(m_frameDayUp,
                                            FpeCallback, 
                                            NULL,
                                            0);

    VFX_OBJ_CREATE(m_timelineDay, VfxS32Timeline, this);
    m_timelineDay->setTarget(m_frameDayUp);
    m_timelineDay->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);

    VFX_OBJ_CREATE(m_timelineNight, VfxS32Timeline, this);
    m_timelineNight->setTarget(m_frameNightUp);
    m_timelineNight->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);

    // Restore the state day or night
    VfxS16 sError;
    VfxU8 isDay = 0;
    ReadValue(NVRAM_PHNSET_LIVE_WALLPAPER_WILDWORLD_DN, &isDay, DS_BYTE, &sError);
    
    if (!isDay)
    {
        m_frameDayUp->sendToBack();
        m_frameDayDown->sendToBack();
        m_isDay = VFX_FALSE;
    }   

}

const VfxBool VappWildWorldDayAndNightLayer::mouseDown(const VfxPoint pos)
{
    // Check if hit the sun or moon

    if (!m_inAnim)
    {
#if defined(__MMI_MAINLCD_240X320__)
        const VfxS32 sLeft = 163;
        const VfxS32 sRight = 163+64;       
        const VfxS32 sTop = 14;
        const VfxS32 sBottom = 14+64;
        const VfxS32 mLeft = 26;
        const VfxS32 mRight = 26+58;        
        const VfxS32 mTop = 26;
        const VfxS32 mBottom = 26+58;
#elif defined(__MMI_MAINLCD_240X400__)
        const VfxS32 sLeft = 153;
        const VfxS32 sRight = 153+77;       
        const VfxS32 sTop = 21;
        const VfxS32 sBottom = 21+77;
        const VfxS32 mLeft = 33;
        const VfxS32 mRight = 33+77;        
        const VfxS32 mTop = 22;
        const VfxS32 mBottom = 22+77;
#elif defined(__MMI_MAINLCD_320X480__)
        const VfxS32 sLeft = 204;
        const VfxS32 sRight = 204+120;      
        const VfxS32 sTop = 14;
        const VfxS32 sBottom = 14+120;
        const VfxS32 mLeft = 38;
        const VfxS32 mRight = 38+106;       
        const VfxS32 mTop = 22;
        const VfxS32 mBottom = 22+106;
#elif defined(__MMI_MAINLCD_480X800__)
        const VfxS32 sLeft = 314;
        const VfxS32 sRight = 314+135;      
        const VfxS32 sTop = 31;
        const VfxS32 sBottom = 31+165;
        const VfxS32 mLeft = 74;
        const VfxS32 mRight = 74+135;       
        const VfxS32 mTop = 31;
        const VfxS32 mBottom = 31+165;
#else
        const VfxS32 sLeft = 204;
        const VfxS32 sRight = 204+120;      
        const VfxS32 sTop = 14;
        const VfxS32 sBottom = 14+120;
        const VfxS32 mLeft = 38;
        const VfxS32 mRight = 38+106;       
        const VfxS32 mTop = 22;
        const VfxS32 mBottom = 22+106;
#endif  
        if (m_isDay && (sLeft < pos.x && pos.x < sRight) && (sTop < pos.y && pos.y < sBottom))
        {
            switchToNight();
            return VFX_TRUE;
        }
        else if (!m_isDay && (mLeft < pos.x && pos.x < mRight) && (mTop < pos.y && pos.y < mBottom))
        {
            switchToDay();
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

void VappWildWorldDayAndNightLayer::switchToNight()
{
    m_frameNightUp->setPos(0, -20);
    m_frameNightDown->setPos(0, -20 + m_frameNightUp->getSize().height);
    m_frameNightUp->setHidden(VFX_FALSE);
    m_frameNightDown->setHidden(VFX_FALSE);

    m_timelineDay->setFromValue(-20);
    m_timelineDay->setToValue(-20 - m_frameDayUp->getSize().height - m_frameDayDown->getSize().height - 40);
    m_timelineDay->setDurationTime(m_duration);
    m_timelineDay->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_timelineDay->setCustomInterpolateFunc(interpolationFunc, this, sizeof(VappWildWorldDayAndNightLayer));
    m_timelineDay->m_signalStopped.connect(this, &VappWildWorldDayAndNightLayer::onAnimComplete);
    m_timelineDay->start();

    m_inAnim = VFX_TRUE;
    m_isDay = VFX_FALSE;

    // Store the state day or night
    VfxU8 isDay = m_isDay ? 1 : 0;
    VfxS16 sError;
    WriteValue(NVRAM_PHNSET_LIVE_WALLPAPER_WILDWORLD_DN, (void*)&isDay, DS_BYTE, &sError);
}

void VappWildWorldDayAndNightLayer::switchToDay()
{
    m_frameDayUp->setPos(0, -20);
    m_frameDayDown->setPos(0, -20 + m_frameDayUp->getSize().height);
    m_frameDayUp->setHidden(VFX_FALSE);
    m_frameDayDown->setHidden(VFX_FALSE);

    m_timelineNight->setFromValue(-20);
    m_timelineNight->setToValue(-20 - m_frameNightUp->getSize().height - m_frameNightDown->getSize().height - 40);
    m_timelineNight->setDurationTime(m_duration);
    m_timelineNight->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_timelineNight->setCustomInterpolateFunc(interpolationFunc, this, sizeof(VappWildWorldDayAndNightLayer));
    m_timelineNight->m_signalStopped.connect(this, &VappWildWorldDayAndNightLayer::onAnimComplete);
    m_timelineNight->start();

    m_inAnim = VFX_TRUE;
    m_isDay = VFX_TRUE;

    // Store the state day or night
    VfxU8 isDay = m_isDay ? 1 : 0;
    VfxS16 sError;
    WriteValue(NVRAM_PHNSET_LIVE_WALLPAPER_WILDWORLD_DN, (void*)&isDay, DS_BYTE, &sError);
}

VfxTimelineInterpolationRetEnum VappWildWorldDayAndNightLayer::interpolationFunc(
    void *output, 
    const void *fromValue, 
    const void *toValue, 
    VfxTypeIdEnum typeId, 
    VfxFloat t,  
    void *data, 
    VfxU32 dataSize)
{
    // Customize the move path to simulate a pull down then up animation
    VfxS32 from = *((VfxS32*)fromValue);
    VfxS32 to = *((VfxS32*)toValue);
    int curValue = from + (to - from) * t;
    VfxS32 *yPos = (VfxS32*)output;

    if (curValue >= -40)
    {
        *yPos = -(20 + curValue) - 20;
        return VFX_TIMELINE_INTERPOLATION_RET_DONE; 
    }
    else
    {
        *yPos = curValue + 40;
        return VFX_TIMELINE_INTERPOLATION_RET_DONE; 
    }

    return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;  
}

void VappWildWorldDayAndNightLayer::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    m_inAnim = VFX_FALSE;

    if (m_isDay)
    {
        m_frameNightUp->sendToBack();
        m_frameNightDown->sendToBack();
        m_frameNightUp->setPos(0, -SCREEN_HEIGHT);
        m_frameNightDown->setPos(0, -SCREEN_HEIGHT + m_frameNightUp->getSize().height);
        m_frameNightUp->setHidden(VFX_TRUE);
        m_frameNightDown->setHidden(VFX_TRUE);
    }
    else
    {
        m_frameDayUp->sendToBack();
        m_frameDayDown->sendToBack();
        m_frameDayUp->setPos(0, -SCREEN_HEIGHT);
        m_frameDayDown->setPos(0, -SCREEN_HEIGHT + m_frameDayUp->getSize().height);
        m_frameDayUp->setHidden(VFX_TRUE);
        m_frameDayDown->setHidden(VFX_TRUE);
    }
}

vrt_render_dirty_type_enum VappWildWorldDayAndNightLayer::FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                                     const vrt_frame_visual_property_struct *watch_frame,
                                                                     void *user_data,
                                                                     vrt_u32 user_data_size)
{
    target_frame->pos.y = watch_frame->pos.y + watch_frame->bounds.size.height;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VappWildWorldDayAndNightLayer::suspend()
{
    if (m_inAnim)
    {
        if (m_isDay)
        {
            m_timelineNight->stop();
        }
        else
        {
            m_timelineDay->stop();
        }
    }
}

void VappWildWorldDayAndNightLayer::resume()
{
    if (m_inAnim)
    {
        if (m_isDay)
        {
            m_timelineNight->start();
        }
        else
        {
            m_timelineDay->start();
        }
    }
}


/***************************************************************************** 
 * VappWildWorldFireball class implementation
 *****************************************************************************/

void VappWildWorldFireball::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_timelineX, VfxS32Timeline, this);
    m_timelineX->setTarget(this);
    m_timelineX->setIsFromCurrent(VFX_TRUE);
    m_timelineX->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);

    VFX_OBJ_CREATE(m_timelineY, VfxS32Timeline, this);
    m_timelineY->setTarget(this);
    m_timelineY->setIsFromCurrent(VFX_TRUE);
    m_timelineY->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_timelineY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    VFX_OBJ_CREATE(m_timelineR, VfxFloatTimeline, this);
    m_timelineR->setTarget(this);
    m_timelineR->setIsFromCurrent(VFX_TRUE);
    m_timelineR->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ);
}

void VappWildWorldFireball::launch(const VfxPoint pos)
{
	if(m_isSuspended)
		return;
	
#if defined(__MMI_MAINLCD_240X320__)
    VfxU32 speedBase = 83;
    VfxSize fireballSize(26, 39);
#elif defined(__MMI_MAINLCD_240X400__)
    VfxU32 speedBase = 83;
    VfxSize fireballSize(31, 47);
#elif defined(__MMI_MAINLCD_320X480__)
    VfxU32 speedBase = 100;
    VfxSize fireballSize(41, 63);
#elif defined(__MMI_MAINLCD_480X800__)
    VfxU32 speedBase = 115;
    VfxSize fireballSize(70, 105);
#else
    VfxU32 speedBase = 100;
    VfxSize fireballSize(41, 63);
#endif

    // Randomly initialize some move path parameters
    VfxS32 rand1 = rand();
    VfxU32 speed = speedBase + rand1 % speedBase;
    VfxFloat scale = 0.8 + float(rand1%3)/10;
    VfxS32 dir = rand1%2 ? 1 : -1;
    m_duration = 1300 + rand1%400;
    VfxU32 startTime = rand()%1000;

    setImgContent(VfxImageSrc(VAPP_WALLPAPER_IMG_WILDWORLD_FIREBALL));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);

    setSize(fireballSize.width*scale, fireballSize.height*scale);
    setAnchor(0.5, 0.4);
    setPos(-100, -100);

    m_timelineX->setFromValue(pos.x);
    m_timelineX->setToValue(pos.x + dir * speed);
    m_timelineX->setDurationTime(m_duration);
    m_timelineX->setStartTime(startTime);
    m_timelineX->m_signalStopped.connect(this, &VappWildWorldFireball::onAnimComplete);
    m_timelineX->start();
    
    m_timelineY->setFromValue(pos.y);
    m_timelineY->setToValue(-83);
    m_timelineY->setDurationTime(m_duration);
    m_timelineY->setStartTime(startTime);
    m_timelineY->start();

    m_timelineR->setFromValue(0);
    m_timelineR->setToValue(VFX_DEG_TO_RAD(dir*(60 + rand1%20)));
    m_timelineR->setDurationTime(m_duration);
    m_timelineR->setStartTime(startTime);
    m_timelineR->start();

    m_isAvailable = VFX_FALSE;
}

void VappWildWorldFireball::onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped)
{
    m_isAvailable = VFX_TRUE;
}

VfxBool VappWildWorldFireball::isAvailable() const
{
    return m_isAvailable;
}

void VappWildWorldFireball::suspend()
{
    if (!isAvailable())
    {
        m_timelineX->stop();
        m_timelineY->stop();
        m_timelineR->stop();
        m_isSuspended = VFX_TRUE;
    }
}

void VappWildWorldFireball::resume()
{
    if (m_isSuspended)
    {
        // must set to a different position so that the frame would be actually redraw
        VfxS32 x = (getPos().x == -100) ? -101 : -100;
        setPos(x, x);

		VfxBool isTimerResumeX = VFX_FALSE;
		VfxBool isTimerResumeY = VFX_FALSE;		
        
        VfxPoint pos(forceGetPos());
        
        VfxS32 From = m_timelineY->getFromValue();
        VfxS32 To = m_timelineY->getToValue();
        VfxS32 duration = From == To ? 0 : m_duration*vfxAbs(VfxFloat(To - pos.x)/(From - To));

		if(duration != 0 && pos.y != To && pos.y > To)
	    {
	        isTimerResumeY = VFX_TRUE;
	        m_timelineY->setFromValue(pos.y);
	        m_timelineY->setDuration(duration);		
	        m_timelineY->setStartTime(0);		
	        m_timelineY->start();						
        }
        
        From = m_timelineX->getFromValue();
        To = m_timelineX->getToValue();
        
		if(duration != 0 && pos.x != To)
	    {
	        isTimerResumeX = VFX_TRUE;	    
	        m_timelineX->setFromValue(pos.x);
	        m_timelineX->setDuration(duration);		
	        m_timelineX->setStartTime(0);
	        m_timelineX->start();
        }
        
		if(!isTimerResumeX && !isTimerResumeY)
	    {		
	        m_isAvailable = VFX_TRUE;
	    }      
        else
        {
            m_isAvailable = VFX_FALSE;
        }
        m_isSuspended = VFX_FALSE;		
    }
}

#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
