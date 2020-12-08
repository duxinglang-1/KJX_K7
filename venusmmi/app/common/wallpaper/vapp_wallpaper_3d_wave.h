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
 *  vapp_wallpaper_3d_wave.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  3D wave wallpaper class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __VAPP_WALLPAPER_3D_WAVE_H__
#define __VAPP_WALLPAPER_3D_WAVE_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "gles2\gl2.h"
#include "vfx_owner_draw.h"

#ifdef MOTION_SENSOR_SUPPORT
#define __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
#endif // MOTION_SENSOR_SUPPORT

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
// for motion sensor
extern "C" {
#include "SensorSrvGport.h"
}
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__

/*****************************************************************************
 * Define
 *****************************************************************************/

static const VfxS32 VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT = 4;

enum VappWave3DClickType
{
    VAPP_WAVE_3D_CLICK_START, // click from the pen down
    VAPP_WAVE_3D_CLICK_SWIPE, // click from the pen move/up
    VAPP_WAVE_3D_CLICK_ONE_POINT  // click to form 1 point ripple
};

struct VappWave3DClick
{
    VfxS32 xClick;
    VfxS32 yClick;
    VfxS32 xPrevious;
    VfxS32 yPrevious;
    float clickIncrement;
    VappWave3DClickType clickType;

    VappWave3DClick(): xClick(0), yClick(0), clickIncrement(-100.0f), clickType(VAPP_WAVE_3D_CLICK_START)
    {
    }
};

#define VAPP_WALLPAPER_WAVE_3D_USE_16BIT_HEIGHT_MAP

#ifdef VAPP_WALLPAPER_WAVE_3D_USE_16BIT_HEIGHT_MAP
typedef VfxS16 HeightType;
#else
typedef VfxS32 HeightType;
#endif

//typedef VfxU32 DiffMapType;
typedef VfxU16 DiffMapType;

class VappWave3DDraw : public VfxOwnerDraw
{
public:
    VappWave3DDraw(VfxS32 width, VfxS32 height);
    void clickStart(VfxS32 x, VfxS32 y);
    void click(VfxS32 x, VfxS32 y);
    void clickOnePoint(VfxS32 x, VfxS32 y);
    VfxS32 getWidth();
    VfxS32 getHeight();
#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    void setGravity(VfxFloat xGravity, VfxFloat yGravity);
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__

protected:
    virtual void onInit();
    
    virtual void onInitResource();

    virtual void onDeinitResource();

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

    virtual vrt_bool isUsingGLAPI() const;

private:
    const VfxS32 m_width;
    const VfxS32 m_height;

    DiffMapType * m_buffer;
    HeightType * m_pData1;
    HeightType * m_pData2;

    GLuint m_bgTexId;
    GLuint m_texId;
    GLuint m_vertexShader;
    GLuint m_fragmentShader;
    GLuint m_programObject;

    GLint  m_positionLoc;
    GLint  m_texCoordLoc;
    GLint  m_samplerLoc;
    GLint  m_baseTexLoc;

    void processWave();
    void processTexture();
    VappWave3DClick getBaseClick(VfxS32 x, VfxS32 y, VappWave3DClickType clickType);
    void addClick(VappWave3DClick click);
    VfxPoint boundedClickPoint(VfxS32 x, VfxS32 y);

    void leaveMotions();

    static const VfxU32 CLICK_DATA_COUNT = 20;
    VappWave3DClick clickData[CLICK_DATA_COUNT];
    VappWave3DClick m_drop;
    VfxU32 m_clickIndex;

    float m_incremental;
    VfxFrame * m_leaves[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_leaveXPos[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_leaveYPos[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_leaveXVelocity[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_leaveYVelocity[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_rotation[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];
    VfxFloat m_rotationV[VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT];

    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    VfxFloat m_xGravity;
    VfxFloat m_yGravity;
    VfxFloat m_xGravityDiff;
    VfxFloat m_yGravityDiff;

#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
};

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
extern "C" void onWallpaper3DWaveMotionTiltDetailCallback(
            srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);

#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__

/*****************************************************************************
 * Home screen UI componet: 3D wave wallpaper class
 *****************************************************************************/
class VappWallpaper3DWave : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaper3DWave);

    VAPP_WALLPAPER_CREATE(VappWallpaper3DWave);

private:

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaper3DWave();

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

	// Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();

//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);

    virtual void onWidgetDropped(VfxPoint pos, VfxControl *targetWidget);

// Method
private:

//Variable
private:
    VappWave3DDraw *m_wave;
    VfxFloatTimeline * m_zTimeline;
    VfxTimer * m_randomWaveTimer;

    void onWaveTimer(VfxTimer *obj);
    void setAnimating();
#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    SRV_SENSOR_HANDLE m_motionTiltHandle;
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
};

#endif // __VAPP_WALLPAPER_3D_WAVE_H__

