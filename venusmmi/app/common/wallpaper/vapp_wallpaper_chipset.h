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
 *  vapp_wallpaper_chipset.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  "Chipset" live wallpaper implementation 
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
 *
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__

#ifndef __VAPP_WALLPAPER_CHIPSET_H__
#define __VAPP_WALLPAPER_CHIPSET_H__

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
#include "vfx_animation.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"
#include "vrt_datatype.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#endif

/***************************************************************************** 
 * Typedefs
 *****************************************************************************/
typedef int PathID;
class VappHsChipsetFilter;

#ifdef __VENUS_3D_UI_ENGINE__
typedef struct
{
   // Handle to a program object
   GLuint programObject;
   GLint uFrameAnchorLoc; 
   GLint uFrameSizeLoc;
   GLint aPositionLoc;
   GLint aTexCoordLoc;
   GLint samplerLoc;   
   GLuint textureDotId;
   GLuint textureTailId;
   GLuint textureBgId;

} ChipsetUserData;
#endif

/**
 * wallpaper class for Chipset
 */
class VappWallpaperChipset : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperChipset);
	VAPP_WALLPAPER_CREATE(VappWallpaperChipset);

// Implementation
private:
    VfxFrame            *m_wallpaper;
    VfxFrame            *m_backgroundFrame;
    VappHsChipsetFilter *m_wallpaperFilter;
    VfxBaseTimeline *m_animTimeline;
        
// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperChipset();

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

    virtual void onSerializeView();
    virtual void onRestoreView();

    // Override to generate new animation on pen down
    virtual VfxBool onPenInput(VfxPenEvent &e);

    // suspend/resume
    virtual void onSuspend();
    virtual void onResume();

private:
    void createBackground();
}; 

class ChipsetPath
{
public:
#if defined(__MMI_MAINLCD_240X320__)
    const static int MAX_PATH_NUM = 8;
#elif defined(__MMI_MAINLCD_240X400__)
    const static int MAX_PATH_NUM = 8;
#elif defined(__MMI_MAINLCD_320X480__)
    const static int MAX_PATH_NUM = 10;
#elif defined(__MMI_MAINLCD_480X800__)
    const static int MAX_PATH_NUM = 8;
#else
    const static int MAX_PATH_NUM = 1;
#endif
    VfxMsec progress;
    VfxMsec duration;    
    VfxMsec delayShow;
    PathID pathID;
    VfxBool isUp;
    VfxBool active;

public:
    void init(PathID id, VfxBool fast = VFX_FALSE);
    VfxBool update(VfxMsec timePassed);
    VfxBool isVisible() const;
    VfxS32 getYStart() const;
    static PathID findNearestPath(const VfxPoint &pos);
};

class ChipsetPathRenderer;

#ifdef __VENUS_3D_UI_ENGINE__
class VappHsChipsetFilter : public VfxOwnerDraw
#else
class VappHsChipsetFilter : public VfxFrameFilter
#endif
{
// definitions
private:
    static const int SPRITE_BPP = 4; // chipset sprites are 32-bit

#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    static const int IDLE_NUM = 2;
    static const int USER_PATH_NUM = 1; // display 1 running user paths at most
#else
    static const int IDLE_NUM = 4;
    static const int USER_PATH_NUM = 5; // display 5 running user paths at most
#endif
#ifdef __VENUS_3D_UI_ENGINE__
    // size of drawer for pass to shader
    VfxSize m_size;

    // GL owner draw handle
    ChipsetUserData m_data;

    GLfloat *m_tailVertices;
    GLfloat *m_tailTexcoord;
#endif

// member data
public:
    static const int FILTER_PROG_MAX = 1000;
    static const int DURATION = 1000;
    VfxBool m_isSuspend;
    VfxBool m_drawnAfterResume;

    VfxMsec m_lastUpdateTiming;
    ChipsetPath m_idlePaths[ChipsetPath::MAX_PATH_NUM]; // running paths during idle. Each item contains 1 unique path.
    ChipsetPath m_userPaths[USER_PATH_NUM]; // running paths after user input. May have overlapped paths.

// Constructor
public:
	VappHsChipsetFilter();

// Public Methods
public:
    // RETURN VFX_TRUE if an path is activated; VFX_FALSE if resource unavailable.
    VfxBool activateUserPath(PathID pid, VfxBool isUp);
#ifdef __VENUS_3D_UI_ENGINE__    
    static vrt_render_dirty_type_enum onUpdate(vrt_frame_visual_property_struct *target_frame,
                                               const vrt_frame_visual_property_struct *watch_frame,
                                               void *user_data,
                                               vrt_u32 user_data_size);
    void setSize(VfxSize size);
#endif
    VfxMsec calculateOffsetTime(const VfxFloat timing) const;
    void setLastupdatetime(VfxMsec t){m_lastUpdateTiming = t;};


// Overridable
protected:
#ifndef __VENUS_3D_UI_ENGINE__    
    virtual BufferModeEnum onGetBufferMode() const;
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);
#endif
	virtual void onInit();
    virtual void onDeinit();
#ifdef __VENUS_3D_UI_ENGINE__
    virtual void onInitResource();
    virtual void onDeinitResource();
    void clearBuffer(vrt_color_type color);
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);
    virtual vrt_bool isUsingGLAPI() const;
#endif

// implementations
private:
    void drawAndCountActive(VfxMsec timeOffset, const ChipsetPathRenderer &renderer, VfxU32 &activeCount, ChipsetPath *paths, VfxU32 pathCount);
    // Draw a PARGB image buffer on to the output
    void drawDotSprite(VfxU8* outBuf, VfxU32 pitchBytes, const vrt_image_buffer_struct &imgSprite, const VfxPoint &pos, int path);
    void drawTailSprite(VfxU8 *outBuf, VfxU32 pitchBytes, const vrt_image_buffer_struct &imgSprite, const VfxPoint &pos, int path);
#ifdef __VENUS_3D_UI_ENGINE__
    GLuint loadWPShader(GLenum type, const U16 resId);
    GLuint loadWPShaderFileMode ( GLenum type, const char *shaderSrc );
    GLuint CreateWPTexture2D(const U16 resId, GLenum type);    
#endif  

};


#endif // #ifndef __VAPP_WALLPAPER_CHIPSET_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__
