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
 *  vapp_wallpaper_spangle.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  Spangle City (shiny pieces) live wallpaper implementation 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__

#ifndef __VAPP_WALLPAPER_SPANGLE_H__
#define __VAPP_WALLPAPER_SPANGLE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vfx_animation.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_timer.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_frame_filter.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"

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
   GLint uTexSampler;
   GLint aPositionLoc;
   GLint aTexCoordLoc;
   GLuint textureId;

} SpangleUserData;
#endif

extern "C"
{
#include "gdi_primitive.h"
}

/***************************************************************************** 
 * VappHsSpangleSparkAnim is a composite for shinning spark animation
 *****************************************************************************/
class VappHsSpangleSparkAnim : public VfxObject
{
// implementation
private:
	VfxImageFrame *m_spark;	// spark icons
	VfxAnimation *m_anim; // animation for sparks

// constructor
public:
    VappHsSpangleSparkAnim():m_spark(NULL), m_anim(NULL){};

// public methods
public:
    // Create animation & image frame Vfx objects
    // Note their life cycle are controlled by pParent
    void init(VfxFrame *pParent);

    // Start the spark animation in given pos
	void start(const VfxPoint &pos);
    void stop();

    // check if this animation is playing
	inline VfxBool available() const
    { return m_anim && !m_anim->getIsEnabled(); }

// private methods
private:
    // animation callback functions. used to reset available status.
    void onTimelineStopped(VfxBaseTimeline *timeline, VfxBool stopped);

};

class PageChangeInfo
{
public:
    VfxBool m_desktopChanged;
    VfxBool m_directionRight;

public:
    PageChangeInfo():
      m_desktopChanged(VFX_FALSE),
      m_directionRight(VFX_FALSE)
    {
    }
};

/***************************************************************************** 
 * Home screen UI componet: spangle wallpaper class
 *****************************************************************************/
class VappHsSpangleDraw;

class VappWallpaperSpangleGold : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperSpangleGold);
	VAPP_WALLPAPER_CREATE(VappWallpaperSpangleGold);

// Implementation
private:
   	const static int MAX_SPARK = 7;
    const static int MAX_RANDOM_SPARK = 4;
    const static VfxMsec SPARK_INTERVAL = 1100;
    const static VfxMsec SPARK_INTERVAL_FAST = 100;
    VappHsSpangleSparkAnim m_sparks[MAX_SPARK];
    VfxFrame *m_wallpaper;
    VappHsSpangleDraw *m_wallpaperDrawer;
    VfxS32 m_sparkToActivate; 
    VfxFloatTimeline *m_animTimeline;
    VfxTimer *m_triggerSparkTimer;
    VfxBool m_isPenDown;
    PageChangeInfo m_pageChangeInfo;

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperSpangleGold();

	virtual VfxBool onAllowSuspendOnSwipe();

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

    // Wallpaper can motion when the widget dragged
	virtual void onWidgetDropped(
		VfxPoint pos,				// Wallpaper position
		VfxControl *targetWidget	// Target widget pointer
	);

    // TODO: widget interaction demo
    virtual VfxBool onPenInput(VfxPenEvent &e);

    virtual void onSuspend();
    virtual void onResume();

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.	
    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);

private:

    // Generates a spark animation.
    // PARAM pos    generate a spark on given pos. 
    // PARMM limitActiveCount   If not 0, make sure there is no more than 
    //                          limitActiveCount of spark animation running.
    void startSpark(const VfxPoint &pos, const int limitActiveCount = 0);

    void onTimerTick(VfxTimer *timer);
    void desktopChangeAnimation(VfxBool bRight);
}; 

/***************************************************************************** 
 * VappHsSpangleDraw is a frame filter that draws the spangles
 *****************************************************************************/
class SpangleCellState
{
public:
    VfxU32 variation; // 1 of VARIATION_NUM sprites
    VfxU32 state; // representing a cell state
    const static VfxU32 VARIATION_NUM = 4;
private:
    VfxMsec stateTime;  // time the cell remain in current state
    VfxMsec nextStartTime; // randomized time to start moving
    VfxBool isMoving; // flag to see if this Spangle is moving
    VfxS32 animSpeed; // speed ratio of the animation triggered by user
private:
    const static VfxU32 ANIM_FRAMES = 120; // number of animated frames
    const static VfxU32 MSEC_PER_STEP = 33; // assume 30 fps (33.33 msec per frame)
    const static VfxU32 ANIM_TRIGGER_START = 30; // This state is the "brightest" state.


public:
    SpangleCellState():
      variation(0),
      state(0),
      stateTime(0),
      nextStartTime(0),
      isMoving(VFX_FALSE),
      animSpeed(1)
    {}
   
    void init();

    // Result of state transition
    enum StepResult{
        ST_NO_UPDATE,
        ST_UPDATE,
        ST_UPDATE_SPARK
    };
    StepResult update(const VfxMsec timeOffset);

    void startPatternAnimation(int stateOffset = 0, int speedRatio = 1);
    static inline int mapStateToSpriteIdx(int state);

private:
    StepResult updateAnimStep();
    
    inline VfxBool isAnimState() const
    { return isMoving; }

    void decideNextStartTime(VfxMsec offset = 0);

};

inline int SpangleCellState::mapStateToSpriteIdx(int state)
{
    // Assume a 120 frame animation, the sprite image arrange in this fashion: 
    //     normal => brighest (30 frame), narmal => darkest (30 frame)
    // so, the actual animation is
    // frame 0 -> frame 29 -> frame 0; frame 30 -> frame 59 -> frame 30.
    const int halfStage = ANIM_FRAMES / 2;
    const int halfAnimFrames = halfStage / 2;
    const int stage = state / halfStage;
    const int prog = state % halfStage;
    const int side = prog / halfAnimFrames;
    const int diff = prog % halfAnimFrames;
    const int mappedState = stage * halfAnimFrames + side * (halfAnimFrames - 1) + diff * (side ? -1 : 1);
    return mappedState;
}

class LayoutInfo
{
public:
#if defined(__MMI_MAINLCD_240X320__)
    const static int ROW = 12;
    const static int COL = 10;
    const static int STATUS_BAR_HEIGHT = 20;
    const static int LEFT_MARGIN = 0;
    const static int TOP_MARGIN = 6;
    const static int PAD_X = 0;
    const static int PAD_Y = 0;

#elif defined(__MMI_MAINLCD_240X400__)

#if defined(__COSMOS_MMI_PACKAGE__) || (!defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__))
    const static int ROW = 15;
#else
    const static int ROW = 13;  // reduce rows since they will be covered by shell toolbar
#endif    
    const static int COL = 10;
    const static int STATUS_BAR_HEIGHT = 20;
    const static int LEFT_MARGIN = 0;
    const static int TOP_MARGIN = 6;
    const static int PAD_X = 0;
    const static int PAD_Y = 0;

#elif defined(__MMI_MAINLCD_320X480__)
    const static int ROW = 18;
    const static int COL = 12;
    const static int STATUS_BAR_HEIGHT = 20;
    const static int LEFT_MARGIN = 10;
    const static int TOP_MARGIN = 6;
    const static int PAD_X = 1;
    const static int PAD_Y = 1;

#elif defined(__MMI_MAINLCD_480X800__)
    const static int ROW = 26;
    const static int COL = 16;
    const static int STATUS_BAR_HEIGHT = 20;
    const static int LEFT_MARGIN = 0;
    const static int TOP_MARGIN = 0;
    const static int PAD_X = 0;
    const static int PAD_Y = 0;

#endif
};

class SpangleCellStateTable
{
// public properties
public:
    const static int CELL_COUNT = LayoutInfo::ROW * LayoutInfo::COL;
    
// internal members
// TODO: change it back to private!
public:
    SpangleCellState m_table[CELL_COUNT]; // table of states

// public methods
public:
    // initializes state of each cell in the table
    void initCells();
    // retrieve state of a given cell
    const SpangleCellState& getCellState(const int cellIndex) const;

    // retrieve modifiable cell
    SpangleCellState& getCell(const int row, const int col);

    // update all cell state with a given time offset
    VfxBool updateState(VfxMsec timeOffset);
};

class SpangleTriggerInfo
{
// Definitions
public:
    VfxPoint m_sourcePos; // triggered cell position (x, y)
    VfxMsec m_progress; // time passed for this trigger
    VfxMsec m_duration;
    VfxFloat m_inputTime;  // stores last UI input time. For animation trigger.
    VfxBool m_processing;  // flag to make sure UI input are not processed twice
    VfxBool m_initialStepDone; // flag to handle 1st frame issues.
    VfxBool m_isLineShapeAnim; // if this is VFX_TRUE, display vertical move animation instead of ripple animation.

public:
    const static VfxS32 STEP_DURATION = 40;
public:
    SpangleTriggerInfo();
    void reset(const VfxPoint &pos);
    VfxBool isActive() const;
// public utility methods
public:
    VfxU32 getSourceCellIndex() const;
    VfxU32 getCellIndex(VfxU32 row, VfxU32 col) const;
    VfxU32 getDistanceToSource(VfxU32 cellIndex) const;
};

#ifdef __VENUS_3D_UI_ENGINE__
class VappHsSpangleDraw : public VfxOwnerDraw
#else
class VappHsSpangleDraw : public VfxFrameFilter
#endif
{
// Definitions
private:
    SpangleCellStateTable m_stateTable;	// The animation state table	
    SpangleTriggerInfo m_triggerInfo;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    SpangleTriggerInfo m_triggerInfoDesktop;
#endif
    VfxFloat m_lastUpdateTiming;  // stores last update timing so that we can know intervals
    VfxBool m_suspended;
#ifdef __VENUS_3D_UI_ENGINE__
    VfxSize m_size;
    SpangleUserData m_data;
    VfxU8 m_bgColorA;
    VfxU8 m_bgColorR;
    VfxU8 m_bgColorG;
    VfxU8 m_bgColorB;    
#endif    

// definitions
public:
 	static const int DURATION = 10000;
    static const VfxFloat FILTER_PROG_MAX;
    static VfxU32 SPRITE_PITCH_PIXEL;
    static VfxU32 SPRITE_LIST_RES_ID;

// Constructor
public:
	VappHsSpangleDraw();

// Public Methods
public:
    void setSuspend(VfxBool bSuspended);
    void setTriggerFromScreenPos(const VfxPoint &pos, VfxBool isLineShape = VFX_FALSE);
    static vrt_render_dirty_type_enum onUpdate(vrt_frame_visual_property_struct *target_frame,
                                               const vrt_frame_visual_property_struct *watch_frame,
                                               void *user_data,
                                               vrt_u32 user_data_size);
#ifdef __VENUS_3D_UI_ENGINE__    
    void setSize(VfxSize size);
#endif

// Overridable
protected:
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
	virtual void onInit();

// implementations
private:
    VfxMsec calculateOffsetTime(const VfxFloat timing) const;
	VfxBool updateState(const VfxMsec timeOffset);
    void updateTriggerAnim(const VfxMsec timeOffset);
    void animateByTriggerInfo(SpangleTriggerInfo &triggerInfo, VfxMsec timeOffset);
    VfxBool prepareSpriteImage();
    VfxU16* getSpritePtr(const SpangleCellState &state, const VfxImageBuffer &spriteSourceImage) const;
    void drawSprites(VfxImageBuffer &inBuf, const VfxRect &dstRect, const VfxRect &srcRect) const;
    inline void drawSingleSprite(gdi_img_buf_struct &dst,
                                 const SpangleCellState &cell, 
                                 const VfxImageBuffer &spriteSourceImage) const;
#ifdef __VENUS_3D_UI_ENGINE__    
    GLuint loadWPShader(GLenum type, const U16 resId);
    GLuint loadWPShaderFileMode ( GLenum type, const char *shaderSrc );
    GLuint CreateWPTexture2D(const U16 resId, GLenum type);    
#endif    
};


#endif // #ifndef __VAPP_WALLPAPER_SPANGLE_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__

