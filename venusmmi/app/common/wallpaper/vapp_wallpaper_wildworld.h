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
 *  vapp_wallpaper_wildworld.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  Wild world live wallpaper implementation 
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__

#ifndef __VAPP_WALLPAPER_WILDWORLD_H__
#define __VAPP_WALLPAPER_WILDWORLD_H__

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


/***************************************************************************** 
 * Home screen UI componet: wild world wallpaper class
 *****************************************************************************/
class VappWildWorldDayAndNightLayer;
class VappWildWorldPterosaur;
class VappWildWorldDinoLayer;
class VappWildWorldLayer;
class VappWildWorldFireball;
class VappWallpaperGestureTranslator;

enum VappWallpaperGesture
{
    VWG_NONE,        // no gesture or not recognized
    VWG_TAP,         // user taps
    VWG_DOUBLE_TAP,  // user double taps
};

class VappWallpaperWildWorld : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperWildWorld);
    VAPP_WALLPAPER_CREATE(VappWallpaperWildWorld);

// Variables
private:
    // Background frame
    VappWildWorldDayAndNightLayer *m_background;

    VfxFrame *m_contentLayer;

    // Character Pterosaur frame
    VappWildWorldPterosaur *m_pterosaur;

    // Character Dinosaur near layer
    VappWildWorldDinoLayer *m_dinoLayer1;
    
    // Character Dinosaur far layer
    VappWildWorldDinoLayer *m_dinoLayer2;

    // Volcano layer
    VappWildWorldLayer *m_volcanoLayer;

    VappWildWorldLayer *m_layer1;
    VappWildWorldLayer *m_layer2;
    VappWildWorldLayer *m_layer3;
    VappWildWorldLayer *m_layer4;

    // Fireball layer
    VfxFrame *m_fireballLayer;

    // This timer runs the character into screen randomly
    VfxTimer *m_charTimer;

    // Fireball array
    const static VfxU32 MAX_FIREBALL_COUNT = 8;
    VappWildWorldFireball* m_fireballs[MAX_FIREBALL_COUNT];

    VappWallpaperGestureTranslator *m_gestureTranslator;

// Constructor / Destructor
public:
    VappWallpaperWildWorld();
    
// Override method
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

protected:
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView(); 

    virtual void onSuspend();
    virtual void onResume();

    virtual VfxBool onPenInput(VfxPenEvent &e);

    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);

    void onGesture(VappWallpaperGestureTranslator *sender, VappWallpaperGesture gesture);

// Implementations
private:
    // Run a character into screen
    void runChar() const;
    
    // Check if hit the volcano area
    VfxBool volcanoHitTest(const VfxPoint p) const;

    // Launch several fireballs
    void volcanoLaunch(const VfxPoint p) const;
    
    // Trigger by timer
    void onTimerTick(VfxTimer *timer);
}; 


/***************************************************************************** 
 * Home screen UI componet: character class
 *****************************************************************************/

class VappWildWorldCharBase : public VfxFrame
{
// Variables
protected:
    // Character image
    VfxFrame *m_image;
    
    // Distance from the screen, which is the nearest layer to the eye (value: near 0.0 -> far 1.0)
    VfxFloat m_distance;

    // Speed of layer movement, positive to the left, negative to the right (unit: pixel/sec)
    VfxS32 m_speed;

    // Flag to indicate if this character is running in the screen
    VfxBool m_isRunning;

    VfxBool m_isSuspended;

// Constructor / Destructor
public:
    VappWildWorldCharBase():
        m_distance(0.0f),
        m_speed(0),
        m_isRunning(VFX_FALSE),
        m_isSuspended(VFX_FALSE)
    {};
        
// Override method
protected:
    // Init char
    virtual void onInit();

// Public method
public:
    // check if this character is running in the screen
    const VfxBool isRunning() const;
};


/***************************************************************************** 
 * Home screen UI componet: Pterosaur class
 *****************************************************************************/

class VappWildWorldPterosaur : public VappWildWorldCharBase
{
// Variable
private:
    VfxS32Timeline *m_timelineX;
    VfxS32Timeline *m_timelineY;
    VfxSize m_defSize;
    VfxU32 m_level;
    VfxU32 m_xDuration;
    VfxU32 m_yDuration;
    VfxU32 m_yTop;
    VfxU32 m_yBottom;

// Constructor / Destructor
public:
    VappWildWorldPterosaur():
        m_timelineX(NULL),
        m_timelineY(NULL),
        m_defSize(0, 0),
        m_level(1),
        m_xDuration(0),
        m_yDuration(0),
        m_yTop(0),
        m_yBottom(0)
        {};

// Override method
protected:
    virtual void onInit();

// Public method
public:
    // Run the pterosaur into screen
    void run(const VfxU32 level);

    void suspend();
    void resume();

// Implementation
private:
    // Stop the animation
    void onXAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);
    void onYAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);
};


/***************************************************************************** 
 * Home screen UI componet: Dinosaur class
 *****************************************************************************/

class VappWildWorldDinosaur : public VappWildWorldCharBase
{
// Variable
private:
    VfxS32 m_stepDuration;
    VfxS32 m_stopDuration;
    VfxS32 m_stepX;
    VfxS32 m_stepY;
    VfxU32 m_duration;
    VappWildWorldDinoLayer *m_parent;
    VfxS32Timeline *m_timelineX;
    VfxS32Timeline *m_timelineY;

// Constructor / Destructor
public:
    VappWildWorldDinosaur():
        m_stepDuration(0),
        m_stopDuration(0),
        m_stepX(0),
        m_stepY(0),
        m_duration(0),
        m_parent(NULL),
        m_timelineX(NULL),
        m_timelineY(NULL)
        {};

// Override method
protected:
    virtual void onInit();

// Public methods
public:
    // Init char animation
    void initAnim(VappWildWorldDinoLayer *pParent, VfxU32 duration, VfxS32 stepX, VfxS32 stepY);

    void run();

    void suspend();
    void resume();
    
// Implementation
private:
    // Stop the animation
    void onXAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);
};


/***************************************************************************** 
 * Home screen UI componet: background layer class
 *****************************************************************************/

class VappWildWorldLayer : public VfxFrame
{
// Variables
private:
    // Distance from the screen, which is the nearest layer to the eye (value: near 0.0 -> far 1.0)
    VfxFloat m_distance;

    // Speed of layer movement, positive to the right, negative to the left (unit: pixel/sec)
    VfxS32 m_speed;

    VfxS32Timeline *m_timeline;

    VfxU32 m_duration;

    VfxBool m_isSuspended;

// Constructor / Destructor
public:
    VappWildWorldLayer():
        m_distance(0.0f),
        m_speed(0),
        m_timeline(NULL),
        m_duration(0),
        m_isSuspended(VFX_FALSE)
    {};

// Public methods
public:
    // Init layer iamge layout
    void initLayerImage(
        const VfxFloat distance, 
        const VfxS32 speed, 
        const VfxResId resIDUp, 
        const VfxSize sizeUp, 
        const VfxResId resIDDown,
        const VfxSize sizeDown,
        const VfxBool rareTranslucent = VFX_FALSE);

    void suspend();
    void resume();

// Implementation
private:
    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);

    static vrt_render_dirty_type_enum FpeCallback1(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum FpeCallback2(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum FpeCallback3(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);
};


/***************************************************************************** 
 * Home screen UI componet: day and night background layer class
 *****************************************************************************/

class VappWildWorldDayAndNightLayer : public VfxFrame
{
// Variables
private:
    // Day frame
    VfxFrame *m_frameDayUp;
    VfxFrame *m_frameDayDown;

    // Night frame
    VfxFrame *m_frameNightUp;
    VfxFrame *m_frameNightDown;

    // Time line for day and night frame
    VfxS32Timeline *m_timelineDay;
    VfxS32Timeline *m_timelineNight;

    // Animation duration
    VfxU32 m_duration;

    // Flag to indicate current state
    VfxBool m_isDay;

    // Flag to indicate if in animation
    VfxBool m_inAnim;

// Constructor / Destructor
public:
    VappWildWorldDayAndNightLayer():
        m_frameDayUp(NULL),
        m_frameDayDown(NULL),
        m_frameNightUp(NULL),
        m_frameNightDown(NULL),
        m_timelineDay(NULL),
        m_timelineNight(NULL),
        m_duration(0),
        m_isDay(VFX_TRUE),
        m_inAnim(VFX_FALSE)
    {};

// Public methods
public:
    // Init upper and lower image
    void initLayer(
           const VfxU32 duration, 
           const VfxResId resIdDayUp, const VfxSize sizeDayUp, 
           const VfxResId resIdDayDown, const VfxSize sizeDayDown, 
           const VfxResId resIdNightUp, const VfxSize sizeNightUp,
           const VfxResId resIdNightDown, const VfxSize sizeNightDown);

    // Trigger the switching by mouse position
    const VfxBool mouseDown(const VfxPoint pos);

    void suspend();
    void resume();

// Implemenations
private:
    void switchToNight();
    void switchToDay();

    static VfxTimelineInterpolationRetEnum interpolationFunc(
        void *output, 
        const void *fromValue, 
        const void *toValue, 
        VfxTypeIdEnum typeId, 
        VfxFloat t,  
        void *data, 
        VfxU32 dataSize);    

    // Stop the animation
    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);

    static vrt_render_dirty_type_enum FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);
};

/***************************************************************************** 
 * Home screen UI componet: dinosaur layer class
 *****************************************************************************/

class VappWildWorldDinoLayer : public VfxFrame
{
// Variables
private:
    // Distance from the screen, which is the nearest layer to the eye (value: near 0.0 -> far 1.0)
    VfxFloat m_distance;

    // Speed of layer movement, positive to the right, negative to the left (unit: pixel/sec)
    VfxS32 m_speed;

    // Dinosaur object
    VappWildWorldDinosaur *m_dino;

    VfxS32Timeline *m_timeline;

    VfxU32 m_duration;

    VfxBool m_isSuspended;

// Constructor / Destructor
public:
    VappWildWorldDinoLayer():
        m_distance(0.0f),
        m_speed(0),
        m_dino(NULL),
        m_timeline(NULL),
        m_duration(0),
        m_isSuspended(VFX_FALSE)
    {};

// Public methods
public:
    // Init layer iamge layout
    void initLayer(const VfxFloat distance, const VfxS32 speed);

    // Run the dinosaur into screen
    void run();

    void stop();

    // Check if dinosaur is running
    const VfxBool isRunning() const;

    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);
    
    void suspend();
    void resume();

// Implementation

};


/***************************************************************************** 
 * Home screen UI componet: Volcano fireball class
 *****************************************************************************/

class VappWildWorldFireball : public VfxFrame
{
// Variables
private:
    VfxU32 m_duration;
    VfxS32Timeline *m_timelineX;
    VfxS32Timeline *m_timelineY;
    VfxFloatTimeline *m_timelineR;
    VfxS32 m_dir;

    // Flag to indicate if this fireball is available for new born
    VfxBool m_isAvailable;

    // Flag to indicate if this fireball is suspended
    VfxBool m_isSuspended;
    
// Constructor / Destructor
public:
    VappWildWorldFireball() : 
        m_duration(1300),
        m_timelineX(NULL),
        m_timelineY(NULL),
        m_timelineR(NULL),
        m_dir(1),
        m_isAvailable(VFX_TRUE),
        m_isSuspended(VFX_FALSE)
        {};

// Override method
protected:
    virtual void onInit();
    
// Public methods
public:
    // Randomly launch several fireballs into sky
    void launch(const VfxPoint pos);

    VfxBool isAvailable() const;
    
    void suspend();
    void resume();

// Implementation
private:
    // Stop the animation
    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);
};


#endif // #ifndef __VAPP_WALLPAPER_WILDWORLD_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
