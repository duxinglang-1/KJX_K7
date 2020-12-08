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
 *  vapp_wallpaper_comet.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  "Comet" live wallpaper implementation 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__

#ifndef __VAPP_WALLPAPER_COMET_H__
#define __VAPP_WALLPAPER_COMET_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"


class VappWallpaperComet;

/**
 * CometAnimation is a helper class that represents a comet animation.
 * Although it holds reference to frame and timeline, it is not the their parent.
 */
class CometAnimation
{
public:
    // the duration of comet falling animation
    static const VfxMsec MOVE_TIME = 1300;
public:
    // initializes data members
    CometAnimation();

    // Create resources under parent
    void init(VappWallpaperComet *parent);

    // start a falling animation, with a given position and angle
    void start(const VfxPoint &startPos, VfxFloat degree = 0.0f);

    // pause the falling animation
    void stop();

    // RETURN VFX_TRUE if this animation is not running
    VfxBool isAvailable();

    // Callback function for timeline. This animation is restored to "available",
    // if the 
    VfxBool notifyTimelineStopped(VfxBaseTimeline *timeline);
    
    // Meteor are larger comets. Must be called before start().
    void switchToMeteor();

    // Ordinary comets. Must be called before start().
    void switchToComet();

public:
    // FPE callback for tail position & size
    static vrt_render_dirty_type_enum tailEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                         const vrt_frame_visual_property_struct *watch_frame,
                                                         void *user_data,
                                                         vrt_u32 user_data_size);
    
    // FPE callback for head position & size
    static vrt_render_dirty_type_enum coreEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                         const vrt_frame_visual_property_struct *watch_frame,
                                                         void *user_data,
                                                         vrt_u32 user_data_size);
    
    // FPE callback for explosion position & scale
    static vrt_render_dirty_type_enum explosionEffectCallback(vrt_frame_visual_property_struct *target_frame,
                                                              const vrt_frame_visual_property_struct *watch_frame,
                                                              void *user_data,
                                                              vrt_u32 user_data_size);

// data members
private:
    // image of the comet head
    VfxImageFrame *m_core;

    // image of comet tail
    VfxImageFrame *m_comet;

    // image of the explosion glow
    VfxImageFrame *m_explosion;

    // animation that holds timlines for images
    VfxAnimation *m_anim;
    
    // for determining if whole animation has finished
    VfxFloatTimeline *m_lastTimeline;

    // accessed in FPE, translation of images
    VfxFloat m_animDeltaX;    

    // accessed in FPE, translation of images
    VfxFloat m_animDeltaY;    

    // accessed in FPE, scale of the tail
    VfxFloat m_animScale;     

    // VFX_TRUE if the animation is not running
    VfxBool m_available;

    // VFX_TRUE if this animation is a "meteor" (larger)
    VfxBool m_isMeteor; 
};

/**
 * The wallpaper component for Comet live wallpaper.
 */
class VappWallpaperComet : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperComet);
	VAPP_WALLPAPER_CREATE(VappWallpaperComet);

// Implementation
private:
    static const int MAX_COMET_NUM = 3;
    static const int MAX_BOMB_COUNT = 1;
    CometAnimation m_comets[MAX_COMET_NUM];
    VfxPoint m_bombDropPos;
    VfxTimer *m_bombardTimer;
    VfxTimer *m_idleTimer;
    VfxFloatTimeline *m_waveTimeline;
    VfxFrame *m_mountainFrame;
    VfxFrame *m_bgFrame;
    VfxFloat m_bombDropAngle;
    VfxS32 m_bombFireCount;

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperComet();

    void onCometAnimationStopped(VfxBaseTimeline *timeline, VfxBool stopped);
    VfxBool activateOneComet(const VfxPoint &startPos, VfxBool useMeteor = VFX_FALSE);
    void onGenerateComet(VfxTimer *timer);
    void onBombMeteor(VfxTimer *timer);
    

// Overrides
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

protected:
	// Init wallpaper
	virtual void onCreateView();

    // for pen interaction
    virtual VfxBool onPenInput(VfxPenEvent &e);

    // Handle pause/resume
    virtual void onSuspend();
    virtual void onResume();

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.	
    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);
}; 

/**
 * Class that draws reflection on the bottom of screen.
 */
class WaveFilter : public VfxFrameFilter
{
// Overridable
protected:
    virtual BufferModeEnum onGetBufferMode() const;
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);
};

#endif // #ifndef __VAPP_WALLPAPER_COMET_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__
