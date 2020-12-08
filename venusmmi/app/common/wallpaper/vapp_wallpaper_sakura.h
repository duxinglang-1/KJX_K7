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
 *  vapp_wallpaper_sakura.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  Sakura live wallpaper implementation 
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "gdi_primitive.h"
#include "gdi_lcd_config.h"
#include "gdi_2d_engine.h"

#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#endif
#ifdef __cplusplus
}
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__

#ifndef __VAPP_WALLPAPER_SAKURA_H__
#define __VAPP_WALLPAPER_SAKURA_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"


//#define __SAKURA_SHADOW_SUPPORT__
/***************************************************************************** 
 * Home screen UI componet: Sakura wallpaper class
 *****************************************************************************/
class VappSakuraFlyImageFrame : public VfxAnimImageFrame
{
    VFX_DECLARE_CLASS(VappSakuraFlyImageFrame);
public:
    enum
    {
        VELOCITY_RAND_DIRECT_BOTH = 0,
        VELOCITY_RAND_DIRECT_INCREASE,
        VELOCITY_RAND_DIRECT_DECREASE
    };

// Constructor / Destructor
public:
    VappSakuraFlyImageFrame();

// methods
public:
    void setInitPosRandRange(
            const VfxPoint& start, 
            const VfxPoint& end);

    void setInitVelocityRandRange(
            const VfxPoint& nowVelocity, 
            VfxU8 interval, 
            VfxU8 direction = VELOCITY_RAND_DIRECT_BOTH);

    void setBasePoint(const VfxPoint& point);
    
    const VfxPoint& getBasePoint() const
    {
        return m_base;
    }

    const VfxPoint& getVelocity() const
    {
        return m_velocity;
    }

    void setVelocity(const VfxPoint& velocity)
    {
        m_velocity = velocity;
    }    
    
// Override methods
protected:
    virtual void onInit();
    
private:
    VfxPoint m_base;
    VfxPoint m_velocity;
    
};


class VappWallpaperSakura : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperSakura);
    VAPP_WALLPAPER_CREATE(VappWallpaperSakura);

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        GRASS_LEFTMOST_PAGE_START_Y = 360,
        GRASS_RIGHTMOST_PAGE_START_Y = 420,

        SAKURA_LEFTMOST_PAGE_START_Y = -80,
        SAKURA_RIGHTMOST_PAGE_START_Y = 0,

        SHADOW_LEFTMOST_PAGE_START_X = -50,
        SHADOW_LEFTMOST_PAGE_START_Y = 505,
        SHADOW_RIGHTMOST_PAGE_START_Y = 565,
        
        BENCH_LEFTMOST_PAGE_START_X = 115,
        BENCH_LEFTMOST_PAGE_START_Y = 382,
        BENCH_RIGHTMOST_PAGE_START_Y = 442,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 134,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 437,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 497,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = 40,
        BRANCH_RIGHTMOST_PAGE_START_Y = 170,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -10,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 238,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 460,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 262,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 466,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y = 736,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 286,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 98,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 130,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 306,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 106,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 138,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 338,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 605,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 566,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 350,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 450,

        PETAL_G1_INIT_X = -250,
        PETAL_G1_INIT_Y = -350,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -50,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -350,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -50,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -350,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 250,
        PETAL_G3_END_Y = -50,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
    #elif defined(__MMI_MAINLCD_320X480__)
        GRASS_LEFTMOST_PAGE_START_Y = 200,
        GRASS_RIGHTMOST_PAGE_START_Y = 230,

        SAKURA_LEFTMOST_PAGE_START_Y = -140,
        SAKURA_RIGHTMOST_PAGE_START_Y = -80,

        SHADOW_LEFTMOST_PAGE_START_X = -50,
        SHADOW_LEFTMOST_PAGE_START_Y = 290,
        SHADOW_RIGHTMOST_PAGE_START_Y = 330,
        
        BENCH_LEFTMOST_PAGE_START_X = 75,
        BENCH_LEFTMOST_PAGE_START_Y = 235,
        BENCH_RIGHTMOST_PAGE_START_Y = 265,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 86,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 272,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 302,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = -8,
        BRANCH_RIGHTMOST_PAGE_START_Y = 72,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -10,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 120,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 260,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 145,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 280,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y = 440,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 190,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 21,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 51,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 215,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 26,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 56,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 210,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 440,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 440,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 300,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 400,

        PETAL_G1_INIT_X = -250,
        PETAL_G1_INIT_Y = -350,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -50,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -350,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -50,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -350,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 250,
        PETAL_G3_END_Y = -50,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
  #elif defined(__MMI_MAINLCD_240X400__)      
        GRASS_LEFTMOST_PAGE_START_Y = 200,
        GRASS_RIGHTMOST_PAGE_START_Y = 220,

        SAKURA_LEFTMOST_PAGE_START_Y = -62,
        SAKURA_RIGHTMOST_PAGE_START_Y = -24,

        SHADOW_LEFTMOST_PAGE_START_X = -30,
        SHADOW_LEFTMOST_PAGE_START_Y = 260,
        SHADOW_RIGHTMOST_PAGE_START_Y = 280,
        
        BENCH_LEFTMOST_PAGE_START_X = 48,
        BENCH_LEFTMOST_PAGE_START_Y = 214,
        BENCH_RIGHTMOST_PAGE_START_Y = 234,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 60,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 243,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 263,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = 26,
        BRANCH_RIGHTMOST_PAGE_START_Y = 86,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -5,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 124,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 226,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 115,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 255,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y = 360,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 140,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 25,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 50,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 165,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 30,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 55,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 210,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 440,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 440,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 200,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 300,

        PETAL_G1_INIT_X = -150,
        PETAL_G1_INIT_Y = -250,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -30,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -250,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -30,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -250,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 150,
        PETAL_G3_END_Y = -30,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
  #elif defined(__MMI_MAINLCD_240X320__)      
        GRASS_LEFTMOST_PAGE_START_Y = 190,
        GRASS_RIGHTMOST_PAGE_START_Y = 202,

        SAKURA_LEFTMOST_PAGE_START_Y = -41,
        SAKURA_RIGHTMOST_PAGE_START_Y = -11,

        SHADOW_LEFTMOST_PAGE_START_X = -15,
        SHADOW_LEFTMOST_PAGE_START_Y = 230,
        SHADOW_RIGHTMOST_PAGE_START_Y = 242,
        
        BENCH_LEFTMOST_PAGE_START_X = 48,
        BENCH_LEFTMOST_PAGE_START_Y = 173,
        BENCH_RIGHTMOST_PAGE_START_Y = 185,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 60,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 202,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 214,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = 22,
        BRANCH_RIGHTMOST_PAGE_START_Y = 62,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -5,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 92,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 170,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 115,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 215,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y = 295,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 140,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 25,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 50,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 165,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 30,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 55,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 210,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 440,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 440,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 200,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 300,

        PETAL_G1_INIT_X = -150,
        PETAL_G1_INIT_Y = -250,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -30,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -250,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -30,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -250,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 150,
        PETAL_G3_END_Y = -30,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
#elif defined(__MMI_MAINLCD_320X240__)      
        GRASS_LEFTMOST_PAGE_START_Y = 157,
        GRASS_RIGHTMOST_PAGE_START_Y = 157,

        SAKURA_LEFTMOST_PAGE_START_Y = 0,
        SAKURA_RIGHTMOST_PAGE_START_Y =0,

        SHADOW_LEFTMOST_PAGE_START_X = -15,
        SHADOW_LEFTMOST_PAGE_START_Y = 230,
        SHADOW_RIGHTMOST_PAGE_START_Y = 230,
        
        BENCH_LEFTMOST_PAGE_START_X = 93,
        BENCH_LEFTMOST_PAGE_START_Y = 96,
        BENCH_RIGHTMOST_PAGE_START_Y = 96,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 105,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 115,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 115,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = -10,
        BRANCH_RIGHTMOST_PAGE_START_Y =-10,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -5,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 60,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 60,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 230,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 150,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y =150,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 190,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 25,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 25,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 215,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 30,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 30,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 210,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 440,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 440,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 200,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 300,

        PETAL_G1_INIT_X = -250,
        PETAL_G1_INIT_Y = -250,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -30,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -250,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -30,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -250,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 250,
        PETAL_G3_END_Y = -30,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
  #else
        GRASS_LEFTMOST_PAGE_START_Y = 200,
        GRASS_RIGHTMOST_PAGE_START_Y = 230,

        SAKURA_LEFTMOST_PAGE_START_Y = -140,
        SAKURA_RIGHTMOST_PAGE_START_Y = -80,

        SHADOW_LEFTMOST_PAGE_START_X = -50,
        SHADOW_LEFTMOST_PAGE_START_Y = 290,
        SHADOW_RIGHTMOST_PAGE_START_Y = 330,
        
        BENCH_LEFTMOST_PAGE_START_X = 85,
        BENCH_LEFTMOST_PAGE_START_Y = 225,
        BENCH_RIGHTMOST_PAGE_START_Y = 275,

        BUTTERFLY0_LEFTMOST_PAGE_CENTER_X = 100,
        BUTTERFLY0_LEFTMOST_PAGE_CENTER_Y = 262,
        BUTTERFLY0_RIGHTMOST_PAGE_CENTER_Y = 312,
        
        BRANCH_LEFTMOST_PAGE_START_X = 0,
        BRANCH_LEFTMOST_PAGE_START_Y = -8,
        BRANCH_RIGHTMOST_PAGE_START_Y = 52,

        SAKURAFG1_LEFTMOST_PAGE_START_X = -10,
        SAKURAFG1_LEFTMOST_PAGE_START_Y = 120,
        SAKURAFG1_RIGHTMOST_PAGE_START_Y = 260,

        SAKURAFG2_LEFTMOST_PAGE_START_X = 145,
        SAKURAFG2_LEFTMOST_PAGE_START_Y = 280,
        SAKURAFG2_RIGHTMOST_PAGE_START_Y = 440,

        SUNSHINE1_LEFTMOST_PAGE_CENTER_X = 190,
        SUNSHINE1_LEFTMOST_PAGE_CENTER_Y = 5,
        SUNSHINE1_RIGHTMOST_PAGE_CENTER_Y = 35,

        SUNSHINE2_LEFTMOST_PAGE_CENTER_X = 215,
        SUNSHINE2_LEFTMOST_PAGE_CENTER_Y = 10,
        SUNSHINE2_RIGHTMOST_PAGE_CENTER_Y = 40,
        
        SAKURAFG1_ROTATE_PIVOT_X = -220,
        SAKURAFG1_ROTATE_PIVOT_Y = 210,
        SHADOW_ROTATE_PIVOT_X = -140,
        SHADOW_ROTATE_PIVOT_Y = 440,
        SAKURAFG2_ROTATE_PIVOT_X = 520,
        SAKURAFG2_ROTATE_PIVOT_Y = 440,

        BUTTERFLY_INIT_X = GDI_LCD_WIDTH + 100,
        BUTTERFLY_INIT_Y = 300,
        BUTTERFLY_END_X = GDI_LCD_WIDTH*3/2 + 100,
        BUTTERFLY_END_Y = 400,

        PETAL_G1_INIT_X = -250,
        PETAL_G1_INIT_Y = -350,
        PETAL_G1_END_X = GDI_LCD_WIDTH*4/5,
        PETAL_G1_END_Y = -50,

        PETAL_G2_INIT_X = GDI_LCD_WIDTH/3,
        PETAL_G2_INIT_Y = -350,
        PETAL_G2_END_X = GDI_LCD_WIDTH,
        PETAL_G2_END_Y = -50,

        PETAL_G3_INIT_X = GDI_LCD_WIDTH/2,
        PETAL_G3_INIT_Y = -350,
        PETAL_G3_END_X = GDI_LCD_WIDTH + 250,
        PETAL_G3_END_Y = -50,

        PETAL_G1_X_SHIFT = GDI_LCD_WIDTH*3/2,
  #endif
        END
    };

// Variables
private:
    
// Constructor / Destructor
public:
    VappWallpaperSakura();
    
// Override method
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();

     virtual void getName(VfxWString &wallpaperName);
    
protected:
    void initPetalPos(VfxU8 index);
    
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView(); 

    virtual void onSerializeView();

    virtual void onRestoreView();
    
    virtual void onSuspend();
    virtual void onResume();

    // desktop switch
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,     // [IN] Current scroll position, ranges from 0.0f ~ 1.0f
        VfxFloat oldPos      // [IN] Previous scroll position, ranges from 0.0f ~ 1.0f
    );

    virtual VfxBool onAllowSuspendOnSwipe()
    {
        return VFX_FALSE;
    }
// Implementations
private:
    void onAnim1Complete(
            VfxBaseTimeline *timeline, 
            VfxBool stopped);

    void onAnim2Complete(
            VfxBaseTimeline *timeline, 
            VfxBool stopped);

    void onSunshineAnimComplete(
            VfxBaseTimeline *timeline, 
            VfxBool stopped);

    void onFlyAnimComplete(
            VfxBaseTimeline *timeline, 
            VfxBool stopped);
    
    static vrt_render_dirty_type_enum grassFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum sakuraBg1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum sakuraBg2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);
    
    static vrt_render_dirty_type_enum sakuraShadowFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);
    
    static vrt_render_dirty_type_enum benchFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum branchFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);    

    static vrt_render_dirty_type_enum sakuraFg1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum sakuraFg2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum sunshine1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum sunshine2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);    

    static vrt_render_dirty_type_enum butterfly0FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size); 
    
    static vrt_render_dirty_type_enum butterfly1FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size); 

    static vrt_render_dirty_type_enum butterfly2FpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);    

    static vrt_render_dirty_type_enum petalFpeCallback(
                                                    vrt_frame_visual_property_struct *target_frame,
                                                    const vrt_frame_visual_property_struct *watch_frame,
                                                    void *user_data,
                                                    vrt_u32 user_data_size);
    void onTimerTick(VfxTimer *source);

#ifdef MOTION_SENSOR_SUPPORT
    static void onMotionTiltDetailCallback(
                                    srv_sensor_type_enum sensor_type, 
                                    void *sensor_data, 
                                    void *user_data);
#endif

// Variables
private:
    VfxBool m_isSuspended;
    VfxBool m_isDelayPlay;
    VfxFloatTimeline *m_switchPageTimeline;
    VfxFloatTimeline *m_sakuraFg1Timeline;
    VfxFloatTimeline *m_sakuraFg2Timeline;
    VfxFloatTimeline *m_sunshineTimeline;
    VfxFloatTimeline *m_flyTimeline;
    VfxImageFrame *m_grass;    
    VfxImageFrame *m_sakuraBg1;
    VfxImageFrame *m_sakuraBg2;    
    VfxImageFrame *m_sakuraShadow;    
    VfxImageFrame *m_bench;
    VfxImageFrame *m_referenceObj;
    VfxAnimImageFrame *m_butterfly0;
    VappSakuraFlyImageFrame *m_butterfly1;
    VappSakuraFlyImageFrame *m_butterfly2;
    VfxImageFrame *m_branch;
    VfxImageFrame *m_sakuraFg1;
    VfxImageFrame *m_sakuraFg2;
    VfxImageFrame *m_sunshine2;
    VfxImageFrame *m_sunshine1;
#if !defined(__MMI_MAINLCD_480X800__)
    static const VfxU32 G1_PETAL_COUNT = 16;
#else
    static const VfxU32 G1_PETAL_COUNT = 7;
#endif
    static const VfxU32 G2_PETAL_COUNT = 2;
    static const VfxU32 G3_PETAL_COUNT = 1;
    static const VfxU32 MAX_PETAL_COUNT = G1_PETAL_COUNT + G2_PETAL_COUNT + G2_PETAL_COUNT;
    VappSakuraFlyImageFrame* m_petal[MAX_PETAL_COUNT];
    
    VfxTransform   m_sakuraFg1Transform;
    VfxTransform   m_shadowTransform;
    VfxTransform   m_sakuraFg2Transform;
    VfxTimer      *m_petalPlayTimer;
    VfxU8          m_petalPlayIndex;
    VfxFloat       m_currPage;
    VfxBool        m_drawnAfterCreated;
#ifdef MOTION_SENSOR_SUPPORT
    SRV_SENSOR_HANDLE m_motionHandle;
    VfxFloat m_xGravity;
    VfxFloat m_yGravity;
    VfxFloat m_zGravity;
#endif
};


#endif // #ifndef __VAPP_WALLPAPER_SAKURA_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
