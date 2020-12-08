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
 *  vapp_media_grid_cp.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_MEDIA_GRID_CP_H__
#define __VAPP_MEDIA_GRID_CP_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_base_menu.h"
#include "vapp_gallery_gprot.h"
#include "vcui_gallery_gprot.h"
#include "vapp_media_list.h"

#ifdef __MMI_GALLERY_SLIM__

#ifdef __cplusplus
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gdi_include.h"
#include "mdi_video.h"
};
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMediaGridComponent;
class IVappGalleryMediaList;
class SimpleBitSet;

/***************************************************************************** 
 * Class VappMediaGridComponentCell
 *****************************************************************************/
class VappMediaGridComponentCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappMediaGridComponentCell);

// Declaration
public:
    enum CellDataType
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATA_TYPE_DEFAULT
    };

    // The title position
    enum CellTitlePosition
    {
        STATE_EXIT     = 0,       
        STATE_DEFAULT,
        STATE_IMAGE
    };
    
    enum CellHighlightSize
    {
        HIGHLIGHT_EXTEND_WIDTH = 6,
        HIGHLIGHT_EXTEND_HEIGHT = 6
    };

    static const VfxS32 MARGIN_BADGE_X = 4;   // margin of the "selected" badge
    static const VfxS32 MARGIN_BADGE_Y = 2;   // margin of the "selected" badge
    static const VfxS32 SELECT_BORDER_SIZE = 2;   // thick of the selecting border
    static const VfxS32 LOADING_BG_COLOR = 231;
    
// Constructor / Destructor
public:
    // Default constructor
    VappMediaGridComponentCell();

    // Destructor
    virtual ~VappMediaGridComponentCell();

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
    virtual void onDraw(VfxDrawContext &dc);

private:
    void drawThumb(VfxDrawContext &dc);
    void drawVideoOverlay(VfxDrawContext &dc);
    void draw3dPhotoBadge(VfxDrawContext &dc);
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    void drawCheckBox(VfxDrawContext &dc);
#endif
    void drawDebugInfo(VfxDrawContext &dc);

// Method
public:
    // shortcut to set cell indices
    void setPosIndex(VfxS32 group, VfxS32 index)
    {
        m_group = group;
        m_index = index;
    }

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    void setSelected(VfxBool bIsSelectMode, VfxBool bSelected);
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

    void setVideoOverlay(VfxBool showVideoOverlay);

    void set3dPhotoBadge(VfxBool show);

    VfxBool updateImage(IVappGalleryMediaList *pMediaList, CellDataType type);

    void closeImage(IVappGalleryMediaList *pMediaList);

    void setImageResId(const MMI_IMG_ID imgId);
    void setImageBuffer(const VfxImageBuffer &imageBuf);
    void setErrorIcon(const VfxU32 line);
    void setDRMIcon();
    void setLoadingIcon();

    void updatePos(const VfxRect& r, VfxBool animation);

    void enter(const VfxRect& r, VfxBool animation);

    void leave(const VfxRect& r);

    vcui_gallery_media_state_enum getContentDecodeState() const;

    VfxS32 getImageState()
    {
        return m_state;
    }

    VfxBool getIsHighlight()
    {
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
       return m_isSelected;
#else
	   return VFX_FALSE;
#endif
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

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VfxBool m_isSelected;
    VfxBool m_isSelectMode;
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

    VfxS32 m_group;
    VfxS32 m_index;
    VfxS32 m_state;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxS32 m_innerX;
    VfxS32 m_innerY;
    VfxBool m_showVideoOverlay;
    VfxBool m_show3dPhotoBadge;
    VfxImageSrc m_image;
    void *m_imageBuf;
    const VfxColor m_selectBorderColor;
#ifndef __MMI_GALLERY_SLIM__
private:
    static srv_mediacache_image_source_enum getDecodeMethodFromCellType(VappMediaGridComponentCell::CellDataType type);
#endif
};

class VappMediaGridComponentHeader : public VappMediaGridComponentCell
{
public:
    static const VfxS32 MARGIN_TOP = 5;
    static const VfxS32 MARGIN_LEFT = 6;
public:
    VappMediaGridComponentHeader();
    virtual void onInit();

public:
    void setString(const VfxWString &text);

protected:
    VfxTextFrame *m_caption;
};

/***************************************************************************** 
 * Class VappMediaGridComponentLayout
 *****************************************************************************/

class VappMediaGridComponentLayout : public VcpBaseMenuLayout
{    

// definitions
public:
    static const int CELL_WIDTH = VappGalleryMediaGridConstant::THUMB_WIDTH;
    static const int CELL_HEIGHT = VappGalleryMediaGridConstant::THUMB_HEIGHT;
    
#if defined(__MMI_MAINLCD_320X480__)
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 26;
#elif defined(__MMI_MAINLCD_480X800__)
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 30;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const int GRID_MARGIN = 0;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 1;
    static const int CELL_INNER_Y = 1;
    static const int HEADER_HEIGHT = 20;

#else
    // prevent build error
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 26;
#endif

    static const int CELL_NUM_PER_ROW = LCD_WIDTH / CELL_HEIGHT;
    static const int MAX_GROUP_CACHE_NUM = 3;

// Constructor / Destructor
public:
    VappMediaGridComponentLayout(VcpBaseMenu* menu);
    virtual ~VappMediaGridComponentLayout();
    
// Override
public:
    virtual void onInit();

    // Return the scroll direction
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    VfxBool isMultiGroupMode();

    // Return the number of groups of this layout.
    virtual VfxS32 getGroupCount();

    virtual VfxBool hasGroupHeader(VfxS32 group);

    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(VfxS32 group);

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

    // Return the header rect of a group
    virtual VfxRect queryGroupHeaderRect(VfxS32 group);
    
    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(
        NavDirEnum dir  // [IN] the change focus direction
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
    void setMediaList(IVappGalleryMediaList *mediaList)
    {
        m_mediaList = mediaList;
    }

    void setCellCountCache(VfxS32 cellCount)
    {
        m_cellCountCache = cellCount;
    }

    inline VfxU32 getCellNumPerRow() const
    {
        return CELL_NUM_PER_ROW;
    }

    inline VfxU32 getCellInnerX() const
    {
        return CELL_INNER_X;
    }

    inline VfxU32 getCellInnerY() const
    {
        return CELL_INNER_Y;
    }

    inline void configCellSize(VappMediaGridComponentCell *cell) const
    {
       cell->setCellInnerX(CELL_INNER_X);
       cell->setCellInnerY(CELL_INNER_Y);
    }
   
// Method
private:
    VcpMenuPos getCellByPos(const VfxPoint &pt, VfxBool clampToValidRegion = VFX_TRUE);

    // get cell from a group offset. The original is
    // AFTER the group header. 
    // if clampToValidRegion is VFX_FALSE, an invalid VcpMenuPos is returned.
    // if it is VFX_TRUE, nearest valid VcpMenuPos is returned.
    VcpMenuPos getCellByPosInGroup(VfxS32 group, const VfxPoint &pt, VfxBool clampToValidRegion = VFX_TRUE);

    // return the starting offset (in pixels) of a given group.
    VfxS32 getGroupStart(VfxS32 group, VfxBool forceRefresh = VFX_FALSE);

    VfxS32 getGroupByPos(const VfxPoint &pt);
    
    VfxS32 getContentLengthInGroup(VfxS32 group);
    
// Variable
private:
    IVappGalleryMediaList *m_mediaList; // data model of the layout
    VfxS32 m_groupCount;    // 0~1: single group mode, >1: multi group mode
    VfxS32 m_cellNumPerRow;
    VfxS32 m_groupStartPos[MAX_GROUP_CACHE_NUM];  // Cache starting posistions
    VfxS32 m_cellCountCache;    // cache for group 0. This is used to reduce visual impact when back from Viewer page.
};


/***************************************************************************** 
 * Class VappMediaWall
 *****************************************************************************/
class VappMediaGridComponent : public VcpBaseMenu
{   
    VFX_DECLARE_CLASS(VappMediaGridComponent);
// Constructor / Destructor
public:
    VappMediaGridComponent();

// Signal
public:
    // cell notification when cell is tapped (also emit under select mode)
    VfxSignal2 <VcpMenuPos, VfxFrame*> m_signalThumbTapped;
    VfxSignal1<VcpMenuPos> m_signalThumbLongPressed;

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

    // Notify when a cell or header is interact.
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );

    virtual VfxFrame* createGroupHeader(VfxS32 group);
    
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame);

    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag);

    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );
    
    // Notify the view is scrolling.
    virtual void onViewScrollStart();

    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd();
            
    // Notify before updating cell and group.
    virtual void onAfterUpdate(
        const VcpMenuRegion& currentRegion, // [IN] The region of current valid view
        const VcpMenuRegion& targetRegion   // [IN] The region of target view
    );
    
// Method
public:
    void setMediaList(IVappGalleryMediaList *pThumbSource);

    void setDummyCellCount(VfxS32 cellCount);

    // force all active cells to become "loading" icon,
    // to release any cache image buffer.
    void releaseAllCachedImage();

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    // enter multi-selection mode.
    // in this mode, the cell tap event is handled by grid itself.
    void beginMultiSelect();

    // Returns the internal bitset
    SimpleBitSet* getSelectionBitSet()
    {
        return &m_selectedSet;
    }

    // returns VFX_TRUE if the grid is in multi-selection mode.
    VfxBool isMultiSelecting()const;

    // query if an item is in selected set
    // this method is only available in multi-selection mode.
    VfxBool isSelected(VfxU32 index);

    void setAllSelected(VfxBool isSelected = VFX_TRUE);

    // returns VFX_TRUE if all cells are selected
    VfxBool isAllSelected();

    // returns VFX_TRUE if any cell is selected
    VfxBool isAnySelected();

    // leave multi-selection mode.
    // all selection state will be cleared.
    void endMultiSelect();
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

    VfxBool getIsViewCellReady();
        
    void heavyUpdate();

    void heavyUpdate(
        VfxS32 index, 
        VappGalleryDecodeResult result
    );

    void liteUpdate();
    
    VfxS32 getDisplayIdx();

    // Timer callback
    void onTimerTick(
        VfxTimer *source    // [IN] Timer
    );

    void onTimerFileIndex(
        VfxTimer *source
    );
    
    void onCellFadeOut();

    void onReset();

    void update();

    void onListPrepared(VappGalleryPrepareResult prepareResult);

    void onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result);
    
    void pauseUpdate(const VfxBool pause, const U32 line);

    void onReloadListStart(VcpMenuPos mediaPos);

    void onReloadListFinished(VcpMenuPos mediaPos);

private:
    void showWaitingIcon(const VfxBool show);

    inline VappMediaGridComponentLayout *getLayout()
    {
        // force down-cast
        // VappMediaGridComponentLayout *ret = VFX_OBJ_DYNAMIC_CAST(m_layout, VappMediaGridComponentLayout)
        VappMediaGridComponentLayout *ret = (VappMediaGridComponentLayout*)m_layout;
        return ret;
    }

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
    
// Information
private:
    VfxBool is3dPhoto(VcpMenuPos p) const;

// Variable    
private:
    VfxTimer *m_timer;
    VfxS32 m_liteUpdateLastPos;
    VfxBool m_isScrolling;
    VfxBool m_isViewCellReady;
    VfxBool m_isCellFadeOut;

    VfxWeakPtr<IVappGalleryMediaList> m_mediaList;
	
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    SimpleBitSet            m_selectedSet;
    VfxBool                 m_isMultiSelecting;
#endif /* __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__ */

    VcpActivityIndicator *m_waitingIcon;
};

#else
#ifdef __cplusplus
extern "C"
{
#include "MediaCacheSrvGprot.h"
#include "MediaCacheSrv.h"              // we need this internal header to hook engine
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gdi_include.h"
#include "mdi_video.h"
};
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMediaGridComponent;
class VappGalleryMediaListMediaCache;
class IVappGalleryMediaList;
class SimpleBitSet;

/***************************************************************************** 
 * Class VappMediaGridComponentCell
 *****************************************************************************/
class VappMediaGridComponentCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappMediaGridComponentCell);

// Declaration
public:
    enum CellDataType
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATA_TYPE_DEFAULT
    };

    // The title position
    enum CellTitlePosition
    {
        STATE_EXIT     = 0,       
        STATE_DEFAULT,
        STATE_IMAGE
    };
    
    enum CellHighlightSize
    {
        HIGHLIGHT_EXTEND_WIDTH = 6,
        HIGHLIGHT_EXTEND_HEIGHT = 6
    };

    static const VfxS32 MARGIN_BADGE_X = 4;   // margin of the "selected" badge
    static const VfxS32 MARGIN_BADGE_Y = 2;   // margin of the "selected" badge
    static const VfxS32 SELECT_BORDER_SIZE = 2;   // thick of the selecting border
    static const VfxS32 LOADING_BG_COLOR = 231;
    
// Constructor / Destructor
public:
    // Default constructor
    VappMediaGridComponentCell();

    // Destructor
    virtual ~VappMediaGridComponentCell();

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
    virtual void onDraw(VfxDrawContext &dc);

private:
    void drawThumb(VfxDrawContext &dc);
    void drawVideoOverlay(VfxDrawContext &dc);
    void draw3dPhotoBadge(VfxDrawContext &dc);
    void drawCheckBox(VfxDrawContext &dc);
    void drawDebugInfo(VfxDrawContext &dc);

// Method
public:
    // shortcut to set cell indices
    void setPosIndex(VfxS32 group, VfxS32 index)
    {
        m_group = group;
        m_index = index;
    }

    void setSelected(VfxBool bIsSelectMode, VfxBool bSelected);
    void setVideoOverlay(VfxBool showVideoOverlay);

    void set3dPhotoBadge(VfxBool show);

    VfxBool updateImage(IVappGalleryMediaList *pMediaList, CellDataType type);

    void closeImage(IVappGalleryMediaList *pMediaList);

    void setImageResId(const MMI_IMG_ID imgId);
    void setImageBuffer(const VfxImageBuffer &imageBuf);
    void setErrorIcon(const VfxU32 line);
    void setDRMIcon();
    void setLoadingIcon();

    void updatePos(const VfxRect& r, VfxBool animation);

    void enter(const VfxRect& r, VfxBool animation);

    void leave(const VfxRect& r);

    vcui_gallery_media_state_enum getContentDecodeState() const;

    VfxS32 getImageState()
    {
        return m_state;
    }

    VfxBool getIsHighlight()
    {
       return m_isSelected;
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
    VfxBool m_isSelected;
    VfxBool m_isSelectMode;
    VfxS32 m_group;
    VfxS32 m_index;
    VfxS32 m_state;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxS32 m_innerX;
    VfxS32 m_innerY;
    VfxBool m_showVideoOverlay;
    VfxBool m_show3dPhotoBadge;
    VfxImageSrc m_image;
    void *m_imageBuf;
    const VfxColor m_selectBorderColor;

private:
    static srv_mediacache_image_source_enum getDecodeMethodFromCellType(VappMediaGridComponentCell::CellDataType type);
};

class VappMediaGridComponentHeader : public VappMediaGridComponentCell
{
public:
    static const VfxS32 MARGIN_TOP = 5;
    static const VfxS32 MARGIN_LEFT = 6;
public:
    VappMediaGridComponentHeader();
    virtual void onInit();

public:
    void setString(const VfxWString &text);

protected:
    VfxTextFrame *m_caption;
};

/***************************************************************************** 
 * Class VappMediaGridComponentLayout
 *****************************************************************************/

class VappMediaGridComponentLayout : public VcpBaseMenuLayout
{    

// definitions
public:
    static const int CELL_WIDTH = VappGalleryMediaGridConstant::THUMB_WIDTH;
    static const int CELL_HEIGHT = VappGalleryMediaGridConstant::THUMB_HEIGHT;
    
#if defined(__MMI_MAINLCD_320X480__)
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 26;
#elif defined(__MMI_MAINLCD_480X800__)
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 30;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const int GRID_MARGIN = 0;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 1;
    static const int CELL_INNER_Y = 1;
    static const int HEADER_HEIGHT = 20;

#else
    // prevent build error
    static const int GRID_MARGIN = 2;
    static const int GRID_MARGIN_Y = 2;
    static const int CELL_FADEOUT_DURATION = 300;
    static const int CELL_INNER_X = 2;
    static const int CELL_INNER_Y = 2;
    static const int HEADER_HEIGHT = 26;
#endif

    static const int CELL_NUM_PER_ROW = LCD_WIDTH / CELL_HEIGHT;
    static const int MAX_GROUP_CACHE_NUM = 3;

// Constructor / Destructor
public:
    VappMediaGridComponentLayout(VcpBaseMenu* menu);
    virtual ~VappMediaGridComponentLayout();
    
// Override
public:
    virtual void onInit();

    // Return the scroll direction
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    VfxBool isMultiGroupMode();

    // Return the number of groups of this layout.
    virtual VfxS32 getGroupCount();

    virtual VfxBool hasGroupHeader(VfxS32 group);

    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(VfxS32 group);

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

    // Return the header rect of a group
    virtual VfxRect queryGroupHeaderRect(VfxS32 group);
    
    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(
        NavDirEnum dir  // [IN] the change focus direction
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
    void setMediaList(IVappGalleryMediaList *mediaList)
    {
        m_mediaList = mediaList;
    }

    void setCellCountCache(VfxS32 cellCount)
    {
        m_cellCountCache = cellCount;
    }

    inline VfxU32 getCellNumPerRow() const
    {
        return CELL_NUM_PER_ROW;
    }

    inline VfxU32 getCellInnerX() const
    {
        return CELL_INNER_X;
    }

    inline VfxU32 getCellInnerY() const
    {
        return CELL_INNER_Y;
    }

    inline void configCellSize(VappMediaGridComponentCell *cell) const
    {
       cell->setCellInnerX(CELL_INNER_X);
       cell->setCellInnerY(CELL_INNER_Y);
    }
   
// Method
private:
    VcpMenuPos getCellByPos(const VfxPoint &pt, VfxBool clampToValidRegion = VFX_TRUE);

    // get cell from a group offset. The original is
    // AFTER the group header. 
    // if clampToValidRegion is VFX_FALSE, an invalid VcpMenuPos is returned.
    // if it is VFX_TRUE, nearest valid VcpMenuPos is returned.
    VcpMenuPos getCellByPosInGroup(VfxS32 group, const VfxPoint &pt, VfxBool clampToValidRegion = VFX_TRUE);

    // return the starting offset (in pixels) of a given group.
    VfxS32 getGroupStart(VfxS32 group, VfxBool forceRefresh = VFX_FALSE);

    VfxS32 getGroupByPos(const VfxPoint &pt);
    
    VfxS32 getContentLengthInGroup(VfxS32 group);
    
// Variable
private:
    IVappGalleryMediaList *m_mediaList; // data model of the layout
    VfxS32 m_groupCount;    // 0~1: single group mode, >1: multi group mode
    VfxS32 m_cellNumPerRow;
    VfxS32 m_groupStartPos[MAX_GROUP_CACHE_NUM];  // Cache starting posistions
    VfxS32 m_cellCountCache;    // cache for group 0. This is used to reduce visual impact when back from Viewer page.
};


/***************************************************************************** 
 * Class VappMediaWall
 *****************************************************************************/
class VappMediaGridComponent : public VcpBaseMenu
{   
    VFX_DECLARE_CLASS(VappMediaGridComponent);
// Constructor / Destructor
public:
    VappMediaGridComponent();

// Signal
public:
    // cell notification when cell is tapped (also emit under select mode)
    VfxSignal2 <VcpMenuPos, VfxFrame*> m_signalThumbTapped;
    VfxSignal1<VcpMenuPos> m_signalThumbLongPressed;

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

    // Notify when a cell or header is interact.
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );

    virtual VfxFrame* createGroupHeader(VfxS32 group);
    
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame);

    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag);

    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );
    
    // Notify the view is scrolling.
    virtual void onViewScrollStart();

    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd();
            
    // Notify before updating cell and group.
    virtual void onAfterUpdate(
        const VcpMenuRegion& currentRegion, // [IN] The region of current valid view
        const VcpMenuRegion& targetRegion   // [IN] The region of target view
    );
    
// Method
public:
    void setMediaList(IVappGalleryMediaList *pThumbSource);

    void setDummyCellCount(VfxS32 cellCount);

    // force all active cells to become "loading" icon,
    // to release any cache image buffer.
    void releaseAllCachedImage();

    // enter multi-selection mode.
    // in this mode, the cell tap event is handled by grid itself.
    void beginMultiSelect();

    // Returns the internal bitset
    SimpleBitSet* getSelectionBitSet()
    {
        return &m_selectedSet;
    }

    // returns VFX_TRUE if the grid is in multi-selection mode.
    VfxBool isMultiSelecting()const;

    // query if an item is in selected set
    // this method is only available in multi-selection mode.
    VfxBool isSelected(VfxU32 index);

    void setAllSelected(VfxBool isSelected = VFX_TRUE);

    // returns VFX_TRUE if all cells are selected
    VfxBool isAllSelected();

    // returns VFX_TRUE if any cell is selected
    VfxBool isAnySelected();

    // leave multi-selection mode.
    // all selection state will be cleared.
    void endMultiSelect();

    VfxBool getIsViewCellReady();
        
    void heavyUpdate();

    void heavyUpdate(
        VfxS32 index, 
        VappGalleryDecodeResult result
    );

    void liteUpdate();
    
    VfxS32 getDisplayIdx();

    // Timer callback
    void onTimerTick(
        VfxTimer *source    // [IN] Timer
    );

    void onTimerFileIndex(
        VfxTimer *source
    );
    
    void onCellFadeOut();

    void onReset();

    void update();

    void onListPrepared(VappGalleryPrepareResult prepareResult);

    void onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result);
    
    void pauseUpdate(const VfxBool pause, const U32 line);

    void onReloadListStart(VcpMenuPos mediaPos);

    void onReloadListFinished(VcpMenuPos mediaPos);

private:
    void showWaitingIcon(const VfxBool show);

    inline VappMediaGridComponentLayout *getLayout()
    {
        // force down-cast
        // VappMediaGridComponentLayout *ret = VFX_OBJ_DYNAMIC_CAST(m_layout, VappMediaGridComponentLayout)
        VappMediaGridComponentLayout *ret = (VappMediaGridComponentLayout*)m_layout;
        return ret;
    }

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
    
// Information
private:
    VfxBool is3dPhoto(VcpMenuPos p) const;

// Variable    
private:
    VfxTimer *m_timer;
    VfxS32 m_liteUpdateLastPos;
    VfxBool m_isScrolling;
    VfxBool m_isViewCellReady;
    VfxBool m_isCellFadeOut;

    VfxWeakPtr<IVappGalleryMediaList> m_mediaList;
    SimpleBitSet            m_selectedSet;
    VfxBool                 m_isMultiSelecting;
    VcpActivityIndicator *m_waitingIcon;
};

#endif

#endif /* __VAPP_GALLERY_SHOOTING_H__ */

