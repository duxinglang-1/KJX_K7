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
 *  vapp_wallpaper_firefly.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  Matirx live wallpaper implementation 
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__

#ifndef __VAPP_WALLPAPER_FIREFLY_H__
#define __VAPP_WALLPAPER_FIREFLY_H__

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
#include "vfx_control.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"
#include "vapp_hs_def.h"


/***************************************************************************** 
 * Home screen UI componet: firefly wallpaper class
 *****************************************************************************/

class StaticFirefly;
class Firefly;

class VappWallpaperFirefly : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperFirefly);
    VAPP_WALLPAPER_CREATE(VappWallpaperFirefly);

// Variables
private:
    // background layer
    VfxFrame *m_bgFrame;

    // firefly layer
    VfxFrame *m_fireflyLayer;

    // This timer is used to 
    VfxTimer *m_timer;

    // Foreground layer 1 (near)
    VfxFrame *m_grassLayer1;

    // Foreground layer 2 (far)
    VfxFrame *m_grassLayer2;

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    static const VfxU32 STATIC_FLY_COUNT_FG1 = 7;
    static const VfxU32 STATIC_FLY_COUNT_FG2 = 3;
#else
    static const VfxU32 STATIC_FLY_COUNT_FG1 = 4;
    static const VfxU32 STATIC_FLY_COUNT_FG2 = 1;
#endif

    StaticFirefly* m_fg1Fireflies[STATIC_FLY_COUNT_FG1];
    StaticFirefly* m_fg2Fireflies[STATIC_FLY_COUNT_FG2];

    static const VfxU32 MAX_FLY_COUNT = 20;
    Firefly* m_fireflies[MAX_FLY_COUNT];
    
// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperFirefly();

// Override method
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);
protected:
    // Init wallpaper
    virtual void onCreateView();

    // Deinit
    virtual void onReleaseView(); 
   
    virtual VfxBool onPenInput(VfxPenEvent &e);

    // Wallpaper can motion when the widget dragged
    virtual void onWidgetDropped(
        VfxPoint pos,               // Wallpaper position
        VfxControl *targetWidget    // Target widget pointer
    );

    virtual void onSuspend();
    virtual void onResume();

    virtual void onSerializeView();
    virtual void onRestoreView();
    
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos);

// Implementations
private:
    void createFirefly(Firefly *f, const VfxPoint LT, const VfxPoint RB, const VfxFloat scale, const VfxBool isFly=VFX_TRUE);
    void createStaticFirefly(StaticFirefly *f, const VfxPoint LT, const VfxPoint RB, const VfxFloat scale);
    void onTimerTick(VfxTimer *timer);
    void moveWallpaperFrame(const VfxU32 totalPage, VfxFloat curPos, VfxFrame *target);
    
}; 


/***************************************************************************** 
 * Home screen UI componet: static firefly class
 *****************************************************************************/

class StaticFirefly : public VfxFrame
{
// Variables
private:
    VfxS32 m_delay;
    VfxS32 m_duration;
    VfxFloatTimeline *m_timeline;
    VfxBool m_isSuspended;
    
// Constructor / Destructor
public:
    // Default constructor
    StaticFirefly():
        m_delay(0),
        m_duration(0),
        m_timeline(NULL),
        m_isSuspended(VFX_TRUE)
        {};

// Override method
protected:
    virtual void onInit();

// Public method
public:
    // Set the firefly to specific position and size
    void born(const VfxPoint pos, const VfxS32 scale);

    void suspend();
    void resume();

// Implementations
private:
    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);

    static vrt_render_dirty_type_enum FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);
};



/***************************************************************************** 
 * FlyFilter is a frame filter that draws the firefly image
 *****************************************************************************/

class FlyFilter : public VfxFrameFilter
{
// Variables
private:
    VfxS32 m_hlCounter;

// Constructor / Destructor
public:
    FlyFilter() :
      m_hlCounter(0)
    {}

// Public methods
public:
    void setHighlight();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);

    
// Implementation
private:
    // Load the string flow list image
    void loadImage();

    // Draw the screen
    inline void drawImage(VfxU8 *outBuf, const VfxImageBuffer &inBuf) const;
};



/***************************************************************************** 
 * Home screen UI componet: firefly class
 *****************************************************************************/

class Firefly : public VfxFrame
{
// Variables
private:
    FlyFilter *m_filter;
    VfxFloatTimeline *m_timeline;
    VfxU32 m_duration;

    // Current target position
    VfxPoint m_targetPos;
    VfxFloat m_ySpeed;
    VfxFloat m_yPos;
    VfxS32 m_twinkleCounter;

    // Flag to indicate this firefly is flying or on the ground
    VfxBool m_fly;

    // Flag to indicate if this firefly is available for new born
    VfxBool m_isAvailable;

    // Flag to indicate if this firefly is suspended
    VfxBool m_isSuspended;

// Constructor / Destructor
public:
    // Default constructor
    Firefly():
        m_filter(NULL),
        m_timeline(NULL),
        m_duration(0),
        m_targetPos(0, 0),
        m_ySpeed(0),
        m_twinkleCounter(-1),
        m_yPos(0),
        m_fly(VFX_TRUE),
        m_isAvailable(VFX_TRUE),
        m_isSuspended(VFX_FALSE)
        {};

// Override method
protected:
    virtual void onInit();
    virtual void onDeinit();

// Public method
public:
    // Set the firefly to specific position and size
    void born(const VfxPoint pos, const VfxS32 scale, const VfxBool isFly);

    // Start the fly
    void fly();

    // Return if the firefly is flying
    VfxBool isAvailable() const;

    // Set m_isAvailable
    void setAvailable(const VfxBool isAvailable);
    
    void suspend();
    void resume();

// Implementations
private:
    void onAnimComplete(VfxBaseTimeline *timeline, VfxBool stopped);

    static vrt_render_dirty_type_enum FpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size);
        
}; 



#endif // #ifndef __VAPP_WALLPAPER_FIREFLY_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__

