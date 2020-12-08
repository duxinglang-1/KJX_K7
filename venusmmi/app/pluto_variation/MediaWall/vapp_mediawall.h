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
 *  vapp_mediawall.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Meida Wall category
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MEDIAWALL_H__
#define __VAPP_MEDIAWALL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_MEDIAWALL__
#include "vcp_base_menu.h"
#include "MediaWall/vadp_mediawall.h"
#include "vcp_status_icon_bar.h"
#include "vcp_base_menu.h"
#include "vadp_mediawall.h"
#include "vcp_status_icon_bar.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_timer.h"
#include "vfx_transform.h"
#include "vfx_app_cat_scr.h"
#include "vcp_content_clone.h"
#include "vcp_marquee.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
// LCD check
#if defined(__MMI_MAINLCD_240X320__) || \
    defined(__MMI_MAINLCD_240X400__) || \
    defined(__MMI_MAINLCD_320X240__) || \
    defined(__MMI_MAINLCD_320X480__) || \
    defined(__MMI_MAINLCD_480X800__)
#else
    #error "Venus Media Wall does not support this LCD resolution."
#endif

#if defined(__HW_G2D_LT_SUPPORT__)
#define __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappMediaWallButton
 *****************************************************************************/

/*
 * VappMediaWallButton is a class that support the button of Media Wall.
 *
 * EXAMPLE
 * <code>
 *  VappMediaWallButton *button;
 *  VFX_OBJ_CREATE(button, VappMediaWallButton, this);
 *  button->setPos(VfxPoint(13, 34));
 * </code>
 */ 
class VappMediaWallButton : public VfxControl
{

// Constructor / Destructor      
public:
    // Default constructor
    VappMediaWallButton();

    // Destructor
    virtual ~VappMediaWallButton();

// Signal
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;

    // Pen up signal
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;

// Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 upImage,     // [IN] up image ID
        VfxS32 downImage    // [IN] down image ID
    );

    // Set image resource ID
    void setImageHighLight(
        VfxS32 highLightImage     // [IN] highlight image ID
    );
    
    // Set display flag
    void setDisplay(
        VfxBool isDisplay   // [IN] display flag
    );

    void setDraw(
        VfxPenEventTypeEnum type        
    );

// Override    
private:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

// Variable
private:
    // Image frame
    VfxImageFrame *m_image;

    // Image frame
    VfxImageFrame *m_imageHighLight;
    
    // Up image resource ID
    VfxS32 m_imageUpId;

    // Down image resource ID
    VfxS32 m_imageDownId;

    // Highlight image resource ID
    VfxS32 m_imageHighLightId;

    // Current pen type
    VfxS32 m_curr_pentype;
};

 
/***************************************************************************** 
 * Class VappMediaWallCell
 *****************************************************************************/
class VappMediaWallCell : public VfxControl
{
// Declaration
public:
    enum
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATE_TYPE_DEFAULT
    };

    // The title position
    enum
    {
        STATE_EXIT     = 0,       
        STATE_DEFAULT,
        STATE_IMAGE
    };
    
    enum
    {
        HIGHLIGHT_EXTEND_WIDTH = 6,
        HIGHLIGHT_EXTEND_HEIGHT = 6
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VappMediaWallCell(VfxS32 index);

    // Destructor
    virtual ~VappMediaWallCell();

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
// Method
public:
    //setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    //bringToFront();
    void onHightLight();

    void onDeHightLight();
    
    VfxBool updateImage(VfxS32 type);

    void closeImage();

    void setErrorIcon();

    void setDRMIcon();

    void setImageBuffer(void *buffer_p);

    void setHighlight();
    
    void updatePos(const VfxRect& r, VfxBool animation);

    void enter(const VfxRect& r, VfxBool animation);

    void leave(const VfxRect& r);

    VfxS32 getImageState()
    {
        return m_state;
    }

    VfxBool getIsHighlight()
    {
       return m_isHighlight;
    }

    void setCellInnerX(VfxS32 value)
    {
        m_innerX = value;
    }

    void setCellInnerY(VfxS32 value)
    {
        m_innerY = value;
    }
    
// Variable
private:
    VfxS32 m_index;
    VfxS32 m_state;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxImageSrc m_image;
    VfxBool m_isHighlight;
    VfxS32 m_innerX;
    VfxS32 m_innerY;
    void *m_imageBuf;
};

/***************************************************************************** 
 * Class VappMediaWallVerLayout
 *****************************************************************************/

class VappMediaWallVerLayout : public VcpBaseMenuLayout
{    
// Constructor / Destructor
public:
    VappMediaWallVerLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    
    // Destructor
    virtual ~VappMediaWallVerLayout();
    
// Override
public:
    virtual void onInit();

    // Return the scroll direction
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
    ) 
    {
        return m_cellCount;
    }

    // Return the whole size of the menu.
    // Inherit should override this method.
    virtual VfxS32 getContentLength();

    // Return the region within a rectangle.
    virtual VcpMenuRegion queryRegion(
        const VfxRect& r    // [IN] The rectangle to query the menu region
    );


    // Return the position by a point
    virtual VcpMenuPos queryPosByPt(
        const VfxPoint& pt    // [IN] The point wants to do hittest
    );

    // Return a cell rect
    virtual VfxRect queryCellRect(
        VcpMenuPos pos  // [IN] The cell index to query
    );

    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(
        NavDirEnum dir  // [IN] the change focus direction
    );

    // Get the focus margin.
    // Focus margin is the prefer space that focus item should not be over.
    virtual void getPreferFocusMargin(
        VfxS32 margin[4] // [OUT] the focus margin in Left, Up, Right, Down
    );

    // Change the Focus Index
    virtual void setFocusItem(
        VcpMenuPos focus,                   // [IN] The focus index
        VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );

    // Make a menu item visible in the screen.
    void makeVisible(
        VcpMenuPos p,               // [IN] The menu index
        VfxBool isAnim = VFX_TRUE   // [IN] Whether need do animation
    );
    
    const VfxPoint getViewPosition() const;

    const VfxSize getViewDimension() const;
    
// Method
public:
   void setCellWidth(
    VfxS32 value
   )
   {
        m_cellWidth = value;
   }

   void setCellHeight(
    VfxS32 value
   )
   {
        m_cellHeight = value;
   }   

   void setCellNumPerRow(
    VfxS32 value
   )
   {
        m_cellNumPerRow = value;
   } 

   void setCellCount(
    VfxS32 value
   )
   {
        m_cellCount = value;
   }

   void setCellInnerX(
    VfxS32 value
   )
   {
        m_cellInnerX = value;
   }   

   void setCellInnerY(
    VfxS32 value
   )
   {
        m_cellInnerY = value;
   } 

   void setMenuCutLength(
    VfxS32 value
   )
   {
        m_menuCutLength = value;
   }
   
   VfxS32 getCellInnerX()
   {
        return m_cellInnerX;
   }   

   VfxS32 getCellInnerY()
   {
        return m_cellInnerY;
   }

   VfxS32 getCellNumPerRow()
   {
        return m_cellNumPerRow;
   }
   
// Method
private:
    VcpMenuPos getCellByPos(
        VfxPoint pt
    );
    
// Variable
private:
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_cellNumPerRow;
    VfxS32 m_cellInnerX;
    VfxS32 m_cellInnerY;
    VfxS32 m_menuCutLength;
};


/***************************************************************************** 
 * Class VappMediaWallVerLayout
 *****************************************************************************/

class VappMediaWallHorLayout : public VcpBaseMenuLayout
{    
// Constructor / Destructor
public:
    VappMediaWallHorLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
    
    // Destructor
    virtual ~VappMediaWallHorLayout();
    
// Override
public:
    virtual void onInit();

    // Return the scroll direction
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_HORZ;
    }

    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
    ) 
    {
        return m_cellCount;
    }

    // Return the whole size of the menu.
    // Inherit should override this method.
    virtual VfxS32 getContentLength();

    // Return the region within a rectangle.
    virtual VcpMenuRegion queryRegion(
        const VfxRect& r    // [IN] The rectangle to query the menu region
    );


    // Return the position by a point
    virtual VcpMenuPos queryPosByPt(
        const VfxPoint& pt    // [IN] The point wants to do hittest
    );

    // Return a cell rect
    virtual VfxRect queryCellRect(
        VcpMenuPos pos  // [IN] The cell index to query
    );

    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(
        NavDirEnum dir  // [IN] the change focus direction
    );

    // Get the focus margin.
    // Focus margin is the prefer space that focus item should not be over.
    virtual void getPreferFocusMargin(
        VfxS32 margin[4] // [OUT] the focus margin in Left, Up, Right, Down
    );

    // Change the Focus Index
    virtual void setFocusItem(
        VcpMenuPos focus,                   // [IN] The focus index
        VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );

    // Make a menu item visible in the screen.
    void makeVisible(
        VcpMenuPos p,               // [IN] The menu index
        VfxBool isAnim = VFX_TRUE   // [IN] Whether need do animation
    );
    
    const VfxPoint getViewPosition() const;

    const VfxSize getViewDimension() const;
    
// Method
public:
   void setCellWidth(
    VfxS32 value
   )
   {
        m_cellWidth = value;
   }

   void setCellHeight(
    VfxS32 value
   )
   {
        m_cellHeight = value;
   }   

   void setCellNumPerColumn(
    VfxS32 value
   )
   {
        m_cellNumPerColumn = value;
   } 

   void setCellCount(
    VfxS32 value
   )
   {
        m_cellCount = value;
   }

   void setCellInnerX(
    VfxS32 value
   )
   {
        m_cellInnerX = value;
   }   

   void setCellInnerY(
    VfxS32 value
   )
   {
        m_cellInnerY = value;
   } 

   void setMenuCutLength(
    VfxS32 value
   )
   {
        m_menuCutLength = value;
   } 
   
   VfxS32 getCellInnerX()
   {
        return m_cellInnerX;
   }   

   VfxS32 getCellInnerY()
   {
        return m_cellInnerY;
   }

   VfxS32 getCellNumPerColumn()
   {
        return m_cellNumPerColumn;
   }
   
// Method
private:
    VcpMenuPos getCellByPos(
        VfxPoint pt
    );
    
// Variable
private:
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_cellNumPerColumn;
    VfxS32 m_cellInnerX;
    VfxS32 m_cellInnerY;
    VfxS32 m_menuCutLength;
};


/***************************************************************************** 
 * Class VappMediaWall
 *****************************************************************************/

class VappMediaWallMenu : public VcpBaseMenu
{       
// Declaration
public:
    enum
    {
        PORTRAIT = 0,
        LANDSCAPE
    };

    enum
    {
        CELL_FADEOUT_DURATION = 300,
        CELL_WIDTH = 80,
        CELL_HEIGHT = 80
    };

    enum
    {
    #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
        BASEPLANE_EXTEND = CELL_WIDTH * 1,
    #else
        BASEPLANE_EXTEND = 0,
    #endif     
        PERSPECTIVE_ANGLE_LIMIT= 15,
        PERSPECTIVE_ANGLE_STEP = 3,
        REFLECTION_INTERVAL = 5,
        PERSPECTIVE_SPEED_STEP = 20,
    #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__    
        REFLECTION_HEIGHT = 60,
    #else
        REFLECTION_HEIGHT = 0,
    #endif
        PERSPECTIVE_RESET_TIMER_DURATION = 1000,
        PERSPECTIVE_DECREASE_TIMER_DURATION = 150,//300
        SPEED_THRESHOLD = 3
    };
    
    enum
    {
        NEARPLANE = 240,
        CAMERADISTANCE = NEARPLANE,
        CAMERAUP = 0,
        CAMERADISTANCE_LIMIT = NEARPLANE + 30,
        CAMERADISTANCE_STEP = 6
    };
    
// Constructor / Destructor
public:
    VappMediaWallMenu(VfxS32 style, VfxFrame *viewFrame);

// Signal
public:
    // Pen down signal
    VfxSignal1 <VfxS32> m_eventFocusChange;
    VfxSignal1 <VfxS32> m_eventNotifyNewFocus;
    VfxSignal1 <VfxS32> m_eventRotateTimelineStart;
    VfxSignal1 <VfxS32> m_eventRotateTimelineEnd;

// Override
public:
    // On init
    virtual void onInit();

    virtual void onDeinit();
    
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    virtual VcpBaseMenuLayout* createLayout();
    
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );
    
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );
    
    // Notify when a cell is clicked
    virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );

    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );

    // Notify when the user start drag the menu
    virtual void onDragStart();

    // Notify when the user stop drag the menu
    virtual void onDragEnd();

    // Notify when the view is dragged, maybe remove the focus
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset
    );

    // Notify the view is scrolling.
    virtual void onViewScrollStart();

    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd();
    
    void onRotateTimeLineStop(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted);
        
    // Notify before updating cell and group.
    virtual void onAfterUpdate(
        const VcpMenuRegion& currentRegion, // [IN] The region of current valid view
        const VcpMenuRegion& targetRegion   // [IN] The region of target view
    );
    
// Method
public:
    VfxBool getIsViewCellReady();
        
    void heavyUpdate();

    void heavyUpdate(
        VfxS32 index, 
        VfxS32 error_code
    );

    void liteUpdate();

    void setCellWidth(
        VfxS32 value
    );

    void setCellHeight(
        VfxS32 value
    );  

    void setCellNumPerRow(
        VfxS32 value
    );

    void setCellCount(
        VfxS32 value
    );

    void setCellInnerX(
        VfxS32 value
    );   

    void setCellInnerY(
        VfxS32 value
    );  

    void setCutLength(
        VfxS32 value
    );
    
    void setHighLightIdx(
        VfxS32 value
    );

    VfxS32 getHighLightIdx();

    VfxS32 getDisplayIdx();

    // Timer callback
    void onTimerTick(
        VfxTimer *source    // [IN] Timer
    );

    void onTimerFileIndex(
        VfxTimer *source
    );

    void setStyle(
        VfxS32 value
    )
    {
        m_style = value;
    }

    void onCellFadeOut();

    void onReset();

    void update();   

    static void decodeCallBack(
                void* user_data, 
                VfxS32 index, 
                VfxS32 error_code
            );

    static void cancelNonBlockingDecode()
    {
        m_indexNonBlocking = -1;
    }

    void setCameraPara(
        VfxFloat cameraDistance = NEARPLANE
    );

    void setOnDragMatrix();

    void setOnDragTimeLine();
    
private:
    
    void launchImageViewer();

    // Check if the whole cell rectangle is in the view region 
    VfxBool getIsInViewRegion(
        VcpMenuPos Pos
    );

    // Check if the cell could be seen in the view region 
    VfxBool getIsCellVisiable(
        VcpMenuPos Pos
    );
    
    void postSetBounds(
        VfxS32 l, 
        VfxS32 t, 
        VfxS32 w, 
        VfxS32 h
    );
    
    void postSetPos(
        VfxS32 x, 
        VfxS32 y
    );
    
    void onDecreaseTimerTick(
        VfxTimer *source
    );
    
    void onResetTimerTick(
        VfxTimer *source
    );
    
// Variable    
private:
    VfxTimer *m_timer;
    VfxTimer *m_timerFileIndex;
    VfxS32 m_style;
    VfxS32 m_liteUpdateLastPos;
    static VfxS32 m_indexNonBlocking;
    VfxBool m_isFocusCellMissed;
    VfxBool m_isScrolling;
    VfxBool m_isViewCellReady;
    VfxBool m_isCellFadeOut;

    VfxMatrix4x4            m_camera;
    VfxMatrix4x4            m_model;
    VfxS32                  m_rotateAngle;
    VfxTransformTimeline   *m_rotateTimeline;
    VfxTimer               *m_decreaseTimer;
    VfxTimer               *m_resetTimer;
    VfxS32                  m_lastXOffset;
    VfxFloat                m_cameraDistance;
    VfxFrame*               m_parentViewFrame;
};

/***************************************************************************** 
 * Class VappMediaWall
 *****************************************************************************/

class VappMediaWallScr : public VfxAppCatScr
{
// Declaration
public:
    enum
    {
        VIEW_PORTRAIT = 0,
        VIEW_LANDSCAPE,
        
        VIEW_COUNT
    };

// Declaration
private:
    // Position, size and constant
    enum
    {
#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_LSK_VER_CENTER_OFFSET_X  = 22,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_LSK_VER_CENTER_OFFSET_X  = 23,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_LSK_VER_CENTER_OFFSET_X  = 27,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_LSK_VER_CENTER_OFFSET_X  = 32, 
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_LSK_VER_CENTER_OFFSET_X  = 32,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_LSK_VER_CENTER_OFFSET_Y  = 303,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_LSK_VER_CENTER_OFFSET_Y  = 380,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_LSK_VER_CENTER_OFFSET_Y  = 220,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_LSK_VER_CENTER_OFFSET_Y  = 454,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_LSK_VER_CENTER_OFFSET_Y  = 454,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_RSK_VER_CENTER_OFFSET_X  = 216,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_RSK_VER_CENTER_OFFSET_X  = 216,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_RSK_VER_CENTER_OFFSET_X  = 291,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_RSK_VER_CENTER_OFFSET_X  = 290,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_RSK_VER_CENTER_OFFSET_X  = 290,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_RSK_VER_CENTER_OFFSET_Y  = 303,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_RSK_VER_CENTER_OFFSET_Y  = 380,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_RSK_VER_CENTER_OFFSET_Y  = 220,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_RSK_VER_CENTER_OFFSET_Y  = 454, 
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_RSK_VER_CENTER_OFFSET_Y  = 454,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_ROT_VER_CENTER_OFFSET_X  = 120,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_ROT_VER_CENTER_OFFSET_X  = 117,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_ROT_VER_CENTER_OFFSET_X  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_ROT_VER_CENTER_OFFSET_X  = 161, 
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_ROT_VER_CENTER_OFFSET_X  = 161,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_ROT_VER_CENTER_OFFSET_Y  = 303,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_ROT_VER_CENTER_OFFSET_Y  = 380,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_ROT_VER_CENTER_OFFSET_Y  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_ROT_VER_CENTER_OFFSET_Y  = 454,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_ROT_VER_CENTER_OFFSET_Y  = 454,
#endif


#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_X  = 296,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_X  = 377,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_X  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_X  = 450,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_X  = 450,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_Y  = 217,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_Y  = 216,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_Y  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_Y  = 290,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_LSK_HOR_CENTER_OFFSET_Y  = 290,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_X  = 296,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_X  = 377,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_X  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_X  = 450, 
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_X  = 450,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_Y  = 24,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_Y  = 24,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_Y  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_Y  = 33,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_RSK_HOR_CENTER_OFFSET_Y  = 33,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_X  = 296,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_X  = 377,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_X  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_X  = 450,
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_X  = 450,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_Y  = 121,
#elif defined(__MMI_MAINLCD_240X400__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_Y  = 119,
#elif defined(__MMI_MAINLCD_320X240__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_Y  = 0,    
#elif defined(__MMI_MAINLCD_320X480__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_Y  = 159, 
#elif defined(__MMI_MAINLCD_480X800__)
        SK_BUT_ROT_HOR_CENTER_OFFSET_Y  = 159,
#endif


#if defined(__MMI_MAINLCD_240X320__)
        FILENAME_START_OFFSET_X  = 50,
#elif defined(__MMI_MAINLCD_240X400__)
        FILENAME_START_OFFSET_X  = 50,
#elif defined(__MMI_MAINLCD_320X240__)
        FILENAME_START_OFFSET_X  = 50,    
#elif defined(__MMI_MAINLCD_320X480__)
        FILENAME_START_OFFSET_X  = 50, 
#elif defined(__MMI_MAINLCD_480X800__)
        FILENAME_START_OFFSET_X  = 50,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILENAME_START_OFFSET_Y  = 22,
#elif defined(__MMI_MAINLCD_240X400__)
        FILENAME_START_OFFSET_Y  = 22,
#elif defined(__MMI_MAINLCD_320X240__)
        FILENAME_START_OFFSET_Y  = 22,    
#elif defined(__MMI_MAINLCD_320X480__)
        FILENAME_START_OFFSET_Y  = 24, 
#elif defined(__MMI_MAINLCD_480X800__)
        FILENAME_START_OFFSET_Y  = 24,
#endif


#if defined(__MMI_MAINLCD_240X320__)
        FILENAME_END_OFFSET_X  = 190,
#elif defined(__MMI_MAINLCD_240X400__)
        FILENAME_END_OFFSET_X  = 190,
#elif defined(__MMI_MAINLCD_320X240__)
        FILENAME_END_OFFSET_X  = 270,    
#elif defined(__MMI_MAINLCD_320X480__)
        FILENAME_END_OFFSET_X  = 270, 
#elif defined(__MMI_MAINLCD_480X800__)
        FILENAME_END_OFFSET_X  = 270,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILENAME_END_OFFSET_Y  = 42,
#elif defined(__MMI_MAINLCD_240X400__)
        FILENAME_END_OFFSET_Y  = 42,
#elif defined(__MMI_MAINLCD_320X240__)
        FILENAME_END_OFFSET_Y  = 42,    
#elif defined(__MMI_MAINLCD_320X480__)
        FILENAME_END_OFFSET_Y  = 44, 
#elif defined(__MMI_MAINLCD_480X800__)
        FILENAME_END_OFFSET_Y  = 44,
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILECOUNT_START_OFFSET_X  = 50,
#elif defined(__MMI_MAINLCD_240X400__)
        FILECOUNT_START_OFFSET_X  = 50,
#elif defined(__MMI_MAINLCD_320X240__)
        FILECOUNT_START_OFFSET_X  = 50,    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        FILECOUNT_START_OFFSET_X  = 50, 
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILECOUNT_START_OFFSET_Y  = 26,
#elif defined(__MMI_MAINLCD_240X400__)
        FILECOUNT_START_OFFSET_Y  = 34,
#elif defined(__MMI_MAINLCD_320X240__)
        FILECOUNT_START_OFFSET_Y  = 26,    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        FILECOUNT_START_OFFSET_Y  = 36, 
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILECOUNT_END_OFFSET_X  = 190,
#elif defined(__MMI_MAINLCD_240X400__)
        FILECOUNT_END_OFFSET_X  = 190,
#elif defined(__MMI_MAINLCD_320X240__)
        FILECOUNT_END_OFFSET_X  = 270,    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        FILECOUNT_END_OFFSET_X  = 270, 
#endif

#if defined(__MMI_MAINLCD_240X320__)
        FILECOUNT_END_OFFSET_Y  = 48,
#elif defined(__MMI_MAINLCD_240X400__)
        FILECOUNT_END_OFFSET_Y  = 48,
#elif defined(__MMI_MAINLCD_320X240__)
        FILECOUNT_END_OFFSET_Y  = 48,    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        FILECOUNT_END_OFFSET_Y  = 56, 
#endif

        MAX_ITEM = 14
    };

    enum
    {
        IMG_TITLE_SHADOW_WIDTH = LCD_WIDTH,
        IMG_SOFTKEYBAR_BG_WIDTH = LCD_WIDTH,
        IMG_SOFTKEYBAR_SHADOW_WIDTH = LCD_WIDTH,  
        IMG_STATUSBAR_BG_WIDTH = LCD_WIDTH,
        IMG_TITLE_WIDTH = LCD_WIDTH,
        IMG_MENU_SHADOW_HEIGHT = LCD_WIDTH,
        
    #if defined(__MMI_MAINLCD_240X320__)
        IMG_MENU_SHADOW_WIDTH = 65,
        IMG_TITLE_SHADOW_HEIGHT = 13,
        IMG_SOFTKEYBAR_BG_HEIGHT = 38,
        IMG_SOFTKEYBAR_SHADOW_HEIGHT = 13,
        IMG_STATUSBAR_BG_HEIGHT = 20,
        IMG_TITLE_HEIGHT = 34,
    #elif defined(__MMI_MAINLCD_240X400__)
        IMG_MENU_SHADOW_WIDTH = 65,
        IMG_TITLE_SHADOW_HEIGHT = 13,
        IMG_SOFTKEYBAR_BG_HEIGHT = 44,
        IMG_SOFTKEYBAR_SHADOW_HEIGHT = 13,
        IMG_STATUSBAR_BG_HEIGHT = 20,
        IMG_TITLE_HEIGHT = 42,
    #elif defined(__MMI_MAINLCD_320X240__)    
        IMG_MENU_SHADOW_WIDTH = 65,
        IMG_TITLE_SHADOW_HEIGHT = 13,
        IMG_SOFTKEYBAR_BG_HEIGHT = 38,
        IMG_SOFTKEYBAR_SHADOW_HEIGHT = 13,
        IMG_STATUSBAR_BG_HEIGHT = 20,
        IMG_TITLE_HEIGHT = 34,
    #elif defined(__MMI_MAINLCD_320X480__)
        IMG_MENU_SHADOW_WIDTH = 65,
        IMG_TITLE_SHADOW_HEIGHT = 13,
        IMG_SOFTKEYBAR_BG_HEIGHT = 51,
        IMG_SOFTKEYBAR_SHADOW_HEIGHT = 13,
        IMG_STATUSBAR_BG_HEIGHT = 20,
        IMG_TITLE_HEIGHT = 52,
    #endif    
        IMG_END
    };

    enum
    {
        STATE_NORMAL     = 0,       
        STATE_SWITCHING
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VappMediaWallScr(
        vadp_mediawall_init_struct init
    );
    
// Override
public:
    VfxBool onKeyInput(
        VfxKeyEvent &event
    );
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(const VfxScreenRotateParam &param);
    

// Method
public:
    VfxS32 getHighLightIndex();
    
    VfxS32 getDisplayIndex();

    void changeLsk(VfxU16 strID);
    
    void setFileCountString(
        VfxS32 index
    ); 

    void setFileNameString(
        VfxS32 index
    );
    
    static VfxS32 getViewMode()
    {
        return m_viewMode;
    }

    static void setViewMode(
        VfxS32 value
    )
    {
        m_viewMode = value;
    }

    void setRotate();
    
// Method
private:
    void onEventUpLsk(
        VfxPenEvent &event
    );
    
    void onEventDownLsk(
        VfxPenEvent &event
    ); 
    
    void onEventUpRsk(
        VfxPenEvent &event
    );
    
    void onEventDownRsk(
        VfxPenEvent &event
    );

    void onEventUpRotate(
        VfxPenEvent &event
    );
    
    void onEventFocusChange(
        VfxS32 index
    );

    void onEventRedrawFileCount(
        VfxS32 index
    );

    void onEventRotateTimelineStart(
        VfxS32 rotateAngle
    );

    void onEventRotateTimelineEnd(
        VfxS32 rotateAngle
    );
    
    // Timer callback
    void onTimerTick(
        VfxTimer *source    // [IN] Timer
    );

    void drawViewMode(
        VfxS32 viewmode
    );

    void onRotate();
    
// Slot
protected:    
    void onLayoutReset(
        VcpBaseMenu* sender
    );

// Variable
private:
    VfxFrame            *m_viewPanel;
    VfxFrame            *m_menuPanel;
    VappMediaWallMenu   *m_menu;
    VcpContentClone     *m_reflection;
    VfxS32 m_lcdWidth;
    VfxS32 m_lcdHeight;
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_cellNumPerRow;
    VfxS32 m_cellInnerX;
    VfxS32 m_cellInnerY;
    VfxS32 m_highLightIdx;
    VfxBool m_lskOn;
    VfxU16 m_titleStrId;

    VfxImageFrame *m_titleBg;
    VfxImageFrame *m_titleShadow;
    VfxImageFrame *m_skBarBg;
    VfxImageFrame *m_skBarShadow;
    VfxImageFrame *m_statusBarBg;
    VfxImageFrame *m_menuShadowLeft;
    VfxImageFrame *m_menuShadowRight;
    VcpMarquee    *m_fileCount;
    VcpMarquee    *m_fileName;
    VcpMarquee    *m_hintStr;
    VappMediaWallButton *m_butLsk;
    VappMediaWallButton *m_butRsk;
    VappMediaWallButton *m_butRotate;
    VcpStatusIconBar *m_statusBar;
    static VfxS32  m_viewMode;
    VfxTimer *m_timer;
    VfxS32 m_state;
    VfxImageFrame *m_imageHighLight;
};

#endif /* __MMI_VUI_MEDIAWALL__ */
#endif /* __VAPP_MEDIAWALL_H__ */

