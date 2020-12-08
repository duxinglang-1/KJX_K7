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
 *  vapp_wallpaper_3d_earth.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  3D earth wallpaper class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifndef __VAPP_WALLPAPER_3D_EARTH_H__
#define __VAPP_WALLPAPER_3D_EARTH_H__

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
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"  
#include "vfx_animation.h"  
#include "vrt_datatype.h"


/*****************************************************************************
 * Include
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_WALLPAPER_EARTH_MOON_POS_X              133    // 503 + 40(status bar)
#define VAPP_WALLPAPER_EARTH_MOON_POS_Y              593    // 503 + 40(status bar)
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_WALLPAPER_EARTH_MOON_POS_X               90
#define VAPP_WALLPAPER_EARTH_MOON_POS_Y              360
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_WALLPAPER_EARTH_MOON_POS_X               67
#define VAPP_WALLPAPER_EARTH_MOON_POS_Y              280
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_WALLPAPER_EARTH_MOON_POS_X               67
#define VAPP_WALLPAPER_EARTH_MOON_POS_Y              225
#else
#define VAPP_WALLPAPER_EARTH_MOON_POS_X               89
#define VAPP_WALLPAPER_EARTH_MOON_POS_Y              326
#endif

#define VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_UP_AREA_RATIO   0.2
#define VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_DOWN_AREA_RATIO 0.8

#define VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR        60000
#define VAPP_WALLPAPER_EARTH_ACCERATION_TIME         25000
#define VAPP_WALLPAPER_EARTH_MAX_SWIPE_NUM           3
#define VAPP_WALLPAPER_EARTH_EAR_ROT_RPM             1.0
#define VAPP_WALLPAPER_EARTH_CLD_ROT_RPM             2.0


/*****************************************************************************
 * Class VappEarth
 *****************************************************************************/

class VappEarth : public VfxFrame
{
    VFX_DECLARE_CLASS(VappEarth);

// Enum
public:
    enum VappEarthSwipeDirEnum
    {
        VAPP_EARTH_CW_SWIPE,
        VAPP_EARTH_CCW_SWIPE
    };

// Constructor
public:
    VappEarth();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    
// Method
public:
    VfxBool isStopRot();
    void accerateRot(VappEarthSwipeDirEnum swipeDir);
    void startRot();
    void stopRot();
    void suspend();
    void resume();
    
private:
    void onRefTlEarthRotStoppod(VfxBaseTimeline *timeline, VfxBool isCompleted);

//Variable
private:
    VfxBool m_flagStopRot;
    VfxS32  m_rotateBySwipe;
    VappEarthSwipeDirEnum m_curRotDir;

    VfxFloatTimeline *m_refTlEarthRot;
    VfxFloatTimeline *m_refTlCloudRot;
    VfxFloatTimeline *m_refTlLightRot;
};


/*****************************************************************************
 * Home screen UI componet: 3D Earth wallpaper class
 *****************************************************************************/
class VappWallpaper3DEarth : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaper3DEarth);

    VAPP_WALLPAPER_CREATE(VappWallpaper3DEarth);

private:
    enum
    {
        //  The distance, in x-axis, we consider the user swipes the desktop.
    #if defined(__MMI_MAINLCD_480X800__)
        SENSITIVITY = 24,
    #elif defined(__MMI_MAINLCD_320X480__)
        SENSITIVITY = 16,
    #elif defined(__MMI_MAINLCD_240X400__)
        SENSITIVITY = 12,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        SENSITIVITY = 12,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        // The time, in msec., we consider the user swipes the desktop.
        SWIPE_CRITERIA = 800,

        // The duration, in msec., that we animate the page sliding from one to
        // another.
        SLIDE_DURATION = 250
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaper3DEarth();

// Override
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

protected:
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    
    virtual void onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds
    );

//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);

    // Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();

//Variable
public:
    VfxImageFrame *m_space;
    VfxImageFrame *m_moon;
    VappEarth     *m_earth;
};
#endif /* __VAPP_WALLPAPER_3D_EARTH_H__ */

