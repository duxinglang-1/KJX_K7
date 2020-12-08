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
 *  vapp_wallpaper_matrix.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__

#ifndef __VAPP_WALLPAPER_MATRIX_H__
#define __VAPP_WALLPAPER_MATRIX_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_frame_filter.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_input_event.h"
#include "vfx_control.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#endif

#ifdef __VENUS_3D_UI_ENGINE__
typedef struct
{
   // Handle to a program object
   GLuint programObject;
   GLint uFrameAnchorLoc; 
   GLint uFrameSizeLoc;
   GLint aPositionLoc;
   GLint aTexCoordLoc;
   GLuint textureId;

} MatrixUserData;
#endif

/***************************************************************************** 
 * MatrixStringFlowInfo class contains necessary info for animation
 *****************************************************************************/

class MatrixStringFlowInfo
{
public:
    enum StringFlowAnimState
    {
        AS_IDLE,
        AS_RUNNING,
        AS_SUSPENDED
    };

public:
    // Current column index of this string flow
    VfxS32 m_strIdx;

    // Beginning column index
    VfxS32 m_startStrIdx;

    // Current position
    VfxPoint m_pos;

    // How many to increase the index for one time
    VfxS32 m_animStep;

    // Timing of last updating
    VfxS32 m_lastUpdateTiming;

    // Animation state
    StringFlowAnimState m_animState;

public:
    MatrixStringFlowInfo():
      m_strIdx(0),
      m_startStrIdx(0),
      m_animStep(1),
      m_lastUpdateTiming(0),
      m_pos(0, 0),
      m_animState(AS_IDLE)
      {}


public:
    void init(VfxPoint startPos, VfxS32 startIdx, VfxS32 animStep);
    void run();
    VfxBool isAvailable() { return m_animState == AS_IDLE; }
    VfxBool isRunning() { return m_animState == AS_RUNNING; }
    VfxBool isSuspended() { return m_animState == AS_SUSPENDED; }
    StringFlowAnimState getAnimState() { return m_animState; }
};


/***************************************************************************** 
 * VfxMatrixDrawer is a frame filter that draws the screen
 *****************************************************************************/
#ifdef __VENUS_3D_UI_ENGINE__
class VfxMatrixDrawer : public VfxOwnerDraw
#else
class VfxMatrixDrawer : public VfxFrameFilter
#endif
{

// Variables
private:
    // Pointers to RAW 16 bit RGB565 pixel buffer of string flow list image
    VfxU16 *m_stringListImage;  

    // Pointer the string flow array of MatrixStringFlowInfo
    MatrixStringFlowInfo *m_strFlows;

    // Flag to indicate if the filter is suspended
    VfxBool m_isSuspended;

    // Store the value of filter timing passed by onProcess, it's value is 1 ~ 10
    VfxS32 m_timing;

    VfxS32 m_updateTiming;

    // Store the value of update timing, it's value is 0 ~ 9999
    VfxS32 m_lastUpdateTiming;

#ifdef __VENUS_3D_UI_ENGINE__
    // size of drawer for pass to shader
    VfxSize m_size;

    // GL owner draw handle
    MatrixUserData m_data;
#endif

// Constructor / Destructor
public:
    VfxMatrixDrawer():
      m_stringListImage(NULL),
      m_strFlows(NULL),
      m_isSuspended(VFX_FALSE),
      m_timing(0),
      m_updateTiming(0),
      m_lastUpdateTiming(0)
      {};

// Public methods
public:

    static vrt_render_dirty_type_enum onUpdate(vrt_frame_visual_property_struct *target_frame,
                                            const vrt_frame_visual_property_struct *watch_frame,
                                            void *user_data,
                                            vrt_u32 user_data_size);

    void setStringFow(MatrixStringFlowInfo *strFlows);

    void suspend();

    void resume();

    VfxBool isSuspend() const;

    VfxFloat getTiming() const;

    void setUpdateTiming(const VfxS32 timing);

    VfxFloat getUpdateTiming() const;

    void setLastUpdateTiming(const VfxS32 timing);

    VfxFloat getLastUpdateTiming() const;

#ifdef __VENUS_3D_UI_ENGINE__    
    void setSize(VfxSize size);
#endif

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
#ifndef __VENUS_3D_UI_ENGINE__
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);
#endif    
#ifdef __VENUS_3D_UI_ENGINE__
    virtual void onInitResource();
    virtual void onDeinitResource();
    void clearBuffer(vrt_color_type color);
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);
    virtual vrt_bool isUsingGLAPI() const;
#endif

// Implementation
private:
    // Load the string flow list image
    VfxBool loadImage();

    // Draw the screen
    inline void drawImage(VfxU8 *outBuf, const VfxImageBuffer &inBuf) const;

#ifdef __VENUS_3D_UI_ENGINE__
    GLuint loadWPShader(GLenum type, const U16 resId);
    GLuint loadWPShaderFileMode ( GLenum type, const char *shaderSrc );
    GLuint CreateWPTexture2D(const U16 resId, GLenum type);    
#endif    
};

/***************************************************************************** 
 * Home screen UI componet: matrix wallpaper class
 *****************************************************************************/

class VappWallpaperMatrix : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperMatrix);
    VAPP_WALLPAPER_CREATE(VappWallpaperMatrix);

// Variables
private:
    // Wallpaper frame
    VfxFrame *m_wallpaper;

    VfxMatrixDrawer *m_drawer;

    // This timer is used to randomly create string flow at different position
    VfxTimer *m_timer;

    // This timeline is used to trigger onProcess of frame filter to update screen
    VfxFloatTimeline *m_timeline;

public:
    // String flow aimation info array
    static const VfxU32 MAX_STRING_FLOW_NUM = 60;
    MatrixStringFlowInfo m_strFlows[MAX_STRING_FLOW_NUM];
    
// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperMatrix();

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

    // Handle screen suspend / resume
    virtual void onSuspend();
    virtual void onResume();

    virtual void onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos);

// Public methods
public:

// Implementations
private:
    void onTimerTick(VfxTimer *timer);

    // Do the string flow creation
    inline void doCreateStringFlow(const VfxPoint pos, const VfxS32 animStep=1);

    // Randomly create new string flow at different place
    void createStringFlow();

    // Create few closed string flows at pen down position
    void createFocusStringFlow(const VfxS32 x);
    
}; 

#endif // #ifndef __VAPP_WALLPAPER_MATRIX_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__

