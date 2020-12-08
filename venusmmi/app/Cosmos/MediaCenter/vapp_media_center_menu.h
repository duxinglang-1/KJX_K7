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
 *  vapp_media_center_menu.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  MediaCenter APP, screen and CUI classes
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_MEDIA_CENTER_MENU_H__
#define __VAPP_MEDIA_CENTER_MENU_H__

#include "MMI_features.h"
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"

#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_light.h"
#include "vfx_bounding_volume.h"
#include "vfx_render_buffer.h"

#include "vapp_media_center_item.h"
#include "vapp_media_center_anim.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMediaCenterPage;
class VappMediaCenterMenuCache;
class VappMediaCenterMenu;
class VappMediaCenterTextBoard;

/***************************************************************************** 
 * Class 
 *****************************************************************************/

class VappMediaCenterPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMediaCenterPage);    
public:
    VappMediaCenterPage();
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBack);
    virtual void onExit(VfxBool isBack);
    virtual void onEntered();
    virtual void onExited();
    virtual void onExited2();
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    void get3DResourcePath(VfxId id, VfxWString &path) const;
    void get3DResourcePath(VfxId id, VfxResId &path) const;
        
    void setupBackground();
    void onBgAnimPlayFinished(VfxBaseTimeline *timeline, VfxBool isStop);
    void setupMenu();
    
    void createDelayEnteredTimer();
    void destroyDelayEnteredTimer();
    void onDelayEntered(VfxTimer *timer);
    
private:
    VfxWorld *m_world;
    VappMediaCenterMenu *m_menu;
    VappMediaCenterAnimTimeline *m_bgAnimPly; 
    VfxTimer *m_delayEnteredTimer;
    VfxS32 m_mementoFocus;
};

/***************************************************************************** 
 * Class : VappMediaCenterMenuCache
 * VappMediaCenterMenuCache is the class to store the data of 3D media center cells
 *****************************************************************************/
class VappMediaCenterMenuCache : public VfxBase
{
// Declaration
public:
    typedef void* DATAPTR;
    typedef VfxWeakPtr <VfxFloatTimeline> VfxFloatTimelineWeakPtr;
    typedef VfxWeakPtr <VfxGroup> VfxFloatMeshPtr;

    class Key : public VfxBase
    {
    public:
        VfxS32 cell;
        VfxS32 subCell;

        Key() : 
            cell(-1), subCell(-1) {}

        Key(const Key& another) : 
            cell(another.cell), subCell(another.subCell) {}

        Key(VfxS32 _cell, VfxS32 _subCell) :  
            cell(_cell), subCell(_subCell) {}

        bool operator == (const Key& another)
        {
            return cell == another.cell && subCell == another.subCell;
        }
        bool operator != (const Key& another)
        {
            return cell != another.cell || subCell != another.subCell;
        }
        bool operator < (const Key& another)
        {
            VfxU64 key1 = VfxU64((VfxU64(cell) << 32) + (VfxU32)subCell);
            VfxU64 key2 = VfxU64((VfxU64(another.cell) << 32) + (VfxU32)another.subCell);

            return key1 < key2;
        }
        bool isValid()
        {
            return cell >= 0 && subCell >= 0;
        }
    };

    class Item : public VfxBase
    {
    public:
        Key                         key;
        VfxFloatMeshPtr             ptr;
    };
    typedef Item* ItemPtr;
    
// Constructor / Destructor
public:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Constructor/Destructor>
    // Constructor
    VappMediaCenterMenuCache();
    // <group DOM_WheelMenu_VcpWheelMenuCache_Constructor/Destructor>
    // Destructor
    virtual ~VappMediaCenterMenuCache();

// Method
public:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Correlate the menu and the cache
    void init(VappMediaCenterMenu* parent);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Disconnect the menu and the cache
    void deinit();

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Whether a pos is in cache
    VfxBool isInCache(Key p);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Get a item by position
    VfxGroup* getItem(Key p);
    
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Set a item to cahce.
    void setItem(Key p, VfxGroup* group);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Remove a item by position
    void removeItem(Key p);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Close a item (remove it from cache and close it)
    void closeItem(Key p);
    
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Clear all cache
    void clear();

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Get Item count
    VfxS32 getCount()
    {
        return m_itemCount;
    }
    VfxS32 getChellIndex(Key key);

// Variable
protected:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VfxS32          m_itemCount;        // Item count in cache.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VfxS32          m_itemTotalCount;   // Item pool size.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    ItemPtr         *m_items;           // Item pool.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VappMediaCenterMenu    *m_menu;            // The menu object.

// Implementation
protected:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Implementation>
    // Binary search in the cache pool.
    // RETURNS: the search index in the pool.
    VfxS32 bisect_left(Key key);
};


/***************************************************************************** 
 * Class : VappMediaCenterMenu
 *****************************************************************************/
struct VappMediaCenterMenuCellHeader
{
    VfxU32 flag;
    VfxS32 cell;
    VfxS32 subCell;
    VfxS32 indexOffset;
    VfxU32 indexOffsetTick;
    void *self;
};

class VappMediaCenterMenu : public VfxControl
{
    VFX_DECLARE_CLASS(VappMediaCenterMenu);
    typedef VappMediaCenterMenu              Self;
    typedef VfxControl                       Super;
    typedef VappMediaCenterMenuCache         Cache;
    typedef VappMediaCenterMenuCache::Key    Key;
    
public:
    VappMediaCenterMenu();

// Override
public:
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onInit();
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onDeinit();

public:
    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the cell frame if the frame is exist
    VfxGroup* getCellIfPresent(
        VfxS32 cell,        // [IN] The cell index
        VfxS32 subCell = 0  // [IN] The sub cell index
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set the focus item to index.
    void setFocus(
        VfxS32 index,               // [IN] The focus item
        VfxMsec animTime = -1       // [IN] The animation time, 0 means no need animation. -1 means use default value.
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the focus index.
    VfxS32 getFocus() const
    {
        return m_focus;
    };

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set the scrolling index.
    void setScrollIndex(
        VfxFloat perc,              // [IN] The focus item
        VfxMsec animTime = -1       // [IN] The animation time, 0 means no need animation. -1 means use default value.
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the scrolling index.
    VfxFloat getScrollIndex();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Whenever any property change, call it to refresh wheel menu.
    void update();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Return the min index that is visible in the screen.
    VfxS32 getFirstVisibleIndex();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Return the max index that is visible in the screen.
    // NOTE: This return index is not visible in the screen, if you would like to loop all visible
    //       items, you don't need to include this value.
    // EXAMPLES:
    //      <code>for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++) {} </code>
    VfxS32 getLastVisibleIndex();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	// <group DOM_WheelMenu_VcpWheelMenu_Method>
	// Return the state of scroll animation.
	// If the menu is scrolling, the return value is VFX_TRUE;
	VfxBool getIsScrolling()
	{
		return m_isScrolling;
	}

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Force close a cell (including subcell) and re-create cell again.
    // This is usually used when users want to change the cell objects.
    void resetCell(
        VfxS32 index    // [IN] The cell index which will be create again.
    );
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    VfxS32 getFocusedNum();
    VfxS32 getVisibleCount();
    void updateMenu();
    VfxGroup* getItem(const VfxS32 index);

    // loop wheel menu supported    
    VfxS32  getRealCellIndex(const VfxS32 item);
    VfxBool isValidCellIndex(const VfxS32 item);
    VfxS32  getLoopRelCellIndex(const VfxS32 index);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the count of menu items.
    // Derived class should override this function.
    virtual VfxS32 getCount();

// TODO: class mediaCenterItemGroup 

// <group DOM_WheelMenu_VcpWheelMenu_Overridable>
protected:  
    void setFirstVisibleIndex(const VfxS32 index);
    void setLastVisibleIndex(const VfxS32 index);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the sub cell count of a cell.
    virtual VfxS32 getSubCellCount();
/*
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the count of menu items.
    // Derived class should override this function.
    virtual VfxS32 getCount();
*/    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the visible menu item count which behind the focus item.
    // Derived class should override this function.
    virtual VfxS32 getBehindCount();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the visible menu item count which ahead the focus item.
    // Derived class should override this function.
    virtual VfxS32 getAheadCount();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a sub cell object 
    virtual VfxGroup* createCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell,          // [IN] The sub cell index
        VfxBool &isNewCreated    // [OUT] If the cell is new created
    );

    // TODO: 
    // onUpdateCell is called while cell is created or focus update
    // FPE: focus move path, 
    // onUpdateCell: process easy animation, ex: change color
    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify to update a cell's position.
    // Inheritor should override this function.
    virtual void onUpdateCell(
        VfxS32      cell,        // [IN] The cell index
        VfxS32      subCell,     // [IN] The sub cell index
        VfxGroup*   group        // [IN] The cell object
    ){};

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell,          // [IN] The sub cell index
        VfxGroup* group          // [IN] The sub cell frame which will be closed
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify about Wheel menu is starting updating cell.
    virtual void onBeforeUpdateCell();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify about Wheel menu has completed updating cell.
    virtual void onAfterUpdateCell();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VfxS32 focusItem,               // [IN] The focus item index now
        VfxS32 preFocusItem             // [IN] The previous focus item index
    );

    virtual void onFocusIndexChangedImpl(const VfxS32 focusIndex);
    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user start drag the menu
    virtual void handleDragStart();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user start drag the menu except enter/leave state
    virtual void onDragStart();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user stop drag the menu 
    virtual void handleDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
        );

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user stop drag the menu except enter/leave state
    virtual void onDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    ); 

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is dragged
    virtual void handleDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is dragged except enter/leave state
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset); 

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is tapped
    virtual VfxBool handleTap(VfxPoint pt);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is tapped and cell does not move.
    virtual VfxBool onTap(VfxPoint pt);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when withdraw cell closed 
    virtual void onAfterWithdrawCellClosed()
        {}

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Get the threshold to trigger onTap()
    virtual VfxS32 getTapThreshold()
        {
            return 20;
        }
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Get the time function when setFocus()
    virtual VfxTimingFuncIdEnum getMoveTimeFunction()
    {
        return VFX_TIMING_FUNC_ID_LINEAR;
    }

// Implementation
public:

    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void cleanAllCell();
#if 0
/* under construction !*/
/* under construction !*/
#endif

    // Force update menu cell
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void updateContent(
        bool force  // [IN] FALSE means use VRT runtime position to update menu.
    );
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Timeline monitor callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static VfxTimelineInterpolationRetEnum indexMonitorFuncCallback(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum interpolateFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum opacityFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum freezeFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxFloat normalizingTimingFuncCallback(VfxFloat t, void *data, VfxU32 dataSize);

    // Notify content warning callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static void emitContentWarning(void *arg);

    // Notify content error callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static void emitContentError(void *arg);


// Event
public:
	// <group DOM_WheelMenu_VcpWheelMenu_Event>
	// Emit Signal when menu is at start of scrolling.
	// void YourClass::onBeginScrolling(VfxObject* sender)
	VfxSignal1<VfxObject*> m_beginScrolling;

	// <group DOM_WheelMenu_VcpWheelMenu_Event>
	// Emit Signal when menu is at end of scrolling.
	// void YourClass::onEndScrolling(VfxObject* sender)
	VfxSignal1<VfxObject*> m_endScrolling;

protected:    
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onUpdate();

    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slot
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Slot>
    void onViewBoundsChanged(VfxFrame *view, const VfxRect &old);
	// <group DOM_WheelMenu_VcpWheelMenu_Slot>
	void onTimerTick(VfxTimer *source);

    
//  <group DOM_WheelMenu_VcpWheelMenu_Variable>
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxS32              m_subCellCount;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxS32              m_focus;            // The focus index
    VfxS32              m_firstVisibleItem, // The first visible index
                        m_lastVisibleItem;  // The last visible index
    VfxS32              m_visibleItemCount;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxFrame            *m_tracker;         // Tracker is a invisible frame. Use for frame property effect.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VappMediaCenterMenuCache   m_cache;            // The cache pool object.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_updating;         // Whether need to update the menu.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
                                            // This variable is planned to removed.
    VfxFloatTimeline    *m_monitorTl;       // The timeline is used to monitor the menu region.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxMsec             m_defaultAnimTime;  // Default item change aniamtion time.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
                                            // For example, in setScrollIndex, you can assign -1 to use this value.
    VfxS32              m_maxMoveOffset;    // The max offset when drag. This is used for detecting tap or scroll.
	// <group DOM_WheelMenu_VcpWheelMenu_Variable>
	VfxTimer            *m_timer;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isToSendWarning;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isToSendError;
	// <group DOM_WheelMenu_VcpWheelMenu_Variable>
	VfxBool				m_isScrolling;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxMsec             m_durationPerCell[2];                
    VfxMsec             m_delay[2];                          
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxU32              m_stateTimelineCount;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxTimer            *m_changeStateTimer;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isSliding;

private:
    VfxFloatTimeline *m_mainTimeline;    
    // media center page
    //VappMediaCenterPage *m_page;
	// Last created cell index
	VfxS32				m_preCreatedCell;

    // 
    VfxS32              m_focusedNum;
    VfxS32              m_totalCount;

private:
    // Get the cell header that in front of userdata.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    //const VappMusicPlayerCoverFlow3DMenuCellHeader* getCellHeader(Key key);

    // Set the cell header
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void setCellHeader(Key key, VappMediaCenterMenuCellHeader* header, VfxBool isNewCreated);

// API that Cache will use
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    friend class VappMediaCenterMenuCache;
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void closeCell(VfxS32 cell, VfxS32 subCell, VfxGroup* group);
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void closeCell(VfxS32 cell);

// implement
public:
    void configWorldAndCamera(VfxWorld *world);
    void configContentProvider(VappMediaCenterAppItems *provider);    
    void changeCameraView(const VfxVector3f axis, 
                                 const VfxFloat theta, 
                                 const VfxS64 duration = 250);
    void onChangeCameraView(VfxBaseTimeline *timeline, VfxBool isStop);
    void resetCameraView();
    VfxBool stopChangingCameraView();

private:
    void setIsDragging(const VfxBool b);
    VfxBool getIsDragging() const;

    void onEndScrolling(VfxObject *sender);
    
    void startDelayFocusCellOpeningTimer();    
    void stopDelayFocusCellOpeningTimer();
    void closeDelayFocusCellOpeningTimer();
    void onDelayFocusCellOpeningTimeout(VfxTimer *timer);
    
    void calculatePenEventSpeed(VfxPenEvent &event, VfxFloat &xSpeed, VfxFloat &ySpeed);
    void calcualteMaxAndCurrentMoveOffset(VfxPenEvent &event, VfxS32 &dX, VfxS32 &dY);

    void createTitleBoard(); 
    void destroyTitleBoard(); 
    void updateTitleBoardString(const VfxWString &title);
    void playTitleBoardTransitionAnim(const VfxBool playInAnim);
    
    void get3DResourcePath(VfxId id, VfxWString &path) const;
    void get3DResourcePath(VfxId id, VfxResId &path) const;
    void convertPos2DTo3D(const VfxPoint p1, VfxVector3f &p2);
    VfxBool getCameraPos(VfxVector3f &pCamera)
    {
        VfxCamera *camera = m_world->getActiveCamera();
        if(NULL == camera)
        {    
            VFX_DEV_ASSERT(camera);
            return VFX_FALSE;
        }
        VfxVector3f pVFX, pVRT;
        camera->getWorldPosition(pVFX);
        camera->forceGetTranslation(pVRT);
        pCamera = pVFX;
        VFX_TRACE(("[MediaCenter] camera @(%f, %f, %f)\n", pCamera.x, pCamera.y, pCamera.z));
        return VFX_TRUE;
    };
    
private:
    VfxWorld *m_world;
    VfxCamera *m_camera;
    VfxQuaternionfTimeline *m_cameraQTL;  
    VappMediaCenterAppItems *m_provider;    

    VappMediaCenterTextBoard *m_titleTextBoard;
    VfxTimer *m_delayFocusCellOpeningTimer;
    VfxBool m_isDraging;
};

/***************************************************************************** 
 * Class Implementation : VappMediaCenterTextBoard
 *****************************************************************************/ 
class VappMediaCenterTextBoard : public VfxGroup
{    
    VFX_DECLARE_CLASS(VappMediaCenterTextBoard);
    
public:
    VappMediaCenterTextBoard():
                m_titleMesh(NULL),
                m_boardRoot(NULL),
                m_iconMesh(NULL),
                m_tex2D(NULL),
                m_img2D(NULL),
                m_animPlayer(NULL){};

    virtual void onDeinit();
    void setupAppearance(const VappMediaCenter3DResPath path);
    void setupAnims(const VappMediaCenter3DResPath inPath, const VappMediaCenter3DResPath outPath);
    void playAnim(const VfxBool playInAnim);
    void setIcon(const VfxImageSrc &imgSrc);
    void setTitleString(const VfxWString &value);

    void meshTest();

private:
    void createTitleTextMesh();
private:
    VfxTextMesh *m_titleMesh;
    VfxGroup *m_boardRoot;
    VfxMesh *m_iconMesh;
    // for changing frame
    VfxTexture2D *m_tex2D;
    VfxImage2D *m_img2D;

    VappMediaCenterAnimPlayer *m_animPlayer;
};

#endif // __COSMOS_3D_MEDIA_CENTER__
#endif // __VAPP_MEDIA_CENTER_MENU_H__ 

