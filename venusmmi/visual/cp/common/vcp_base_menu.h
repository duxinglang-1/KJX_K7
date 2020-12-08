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
 *  vcp_base_menu.h
 *
 * Project:
 * --------
 *  A basic menu framework for venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifndef _VCP_BASE_MENU_H_
#define _VCP_BASE_MENU_H_

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_weak_ptr.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vcp_scrollable.h"
#include "vfx_input_event.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vfx_timer.h"

#include "vfx_container.h"
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
#include "vmsys.h"
#endif
/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VcpBaseMenu;
class VcpBaseMenuView;
class VcpBaseMenuLayout;

// <group DOM_BaseMenu_VcpBaseMenu_Enum>
// This enum is for margin area.
enum VcpBaseMenuMarginAreaEnum 
{
    VCP_BASE_MENU_MARGIN_AREA_TOP,       // top area
    VCP_BASE_MENU_MARGIN_AREA_BOTTOM,    // bottom area
    VCP_BASE_MENU_MARGIN_AREA_END
};


// <group DOM_BaseMenu_VcpBaseMenu_Enum>
// This enum is for margin item placement.
enum VcpBaseMenuMarginAreaFramePlacementEnum 
{
    VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_LEFT,     // placement left
    VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_CENTER,   // placement center
    VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_RIGHT,    // placement right
    VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL,     // placement full
    VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_END
};

enum VcpBaseMenuCacheStyle
{
    VCP_BASE_MENU_CACHE_STYLE_PREDICT,     
    VCP_BASE_MENU_CACHE_STYLE_CENTER,   
    VCP_BASE_MENU_CACHE_STYLE_END,
};

/***************************************************************************** 
 * Class VcpMenuPos
 *****************************************************************************/

/*
 *  VcpMenuPos is a class for indicate a position in menu.
 */
class VcpMenuPos : public VfxBase
{
// Variable
public:
    // <group DOM_BaseMenu_VcpMenuPos_Variable>
    VfxS32 group;   // the group index in the menu
    // <group DOM_BaseMenu_VcpMenuPos_Variable>
    VfxS32 pos;     // the cell index in the group, -1 means the header of a group

// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpMenuPos_Constructor/Destructor>
    // Constructor
    VcpMenuPos(
        VfxS32 g,                   // [IN] group of a cell
        VfxS32 p                    // [IN] pos of a cell
    ) : group(g), pos(p) {}
    
    // <group DOM_BaseMenu_VcpMenuPos_Constructor/Destructor>
    // Constructor
    VcpMenuPos() : group(-1), pos(-1) {}
    
    // <group DOM_BaseMenu_VcpMenuPos_Constructor/Destructor>
    // Constructor
    VcpMenuPos(
        const VcpMenuPos &other     // [IN] other menu pos which we want to copy
    ) : group(other.group), pos(other.pos) {}

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
    // <group DOM_BaseMenu_VcpMenuPos_Constructor/Destructor>
    // Constructor for MRE
    VcpMenuPos(
        const vm_base_menu_pos_struct &other    // [IN] MRE menu pos which we want to copy
    ) : group(other.group), pos(other.pos) {}

#endif
// Method
public:
    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Operator for compare
    // RETURNS: true if the menu pos is the same as pass-in menu pos
    bool operator == (
        const VcpMenuPos &other // [IN] the menu pos which we want to test
    ) const
    {
        return (group == other.group && pos == other.pos);
    }

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Operator for compare
    // RETURNS: true if the menu pos is not the same as pass-in menu pos
    bool operator != (
        const VcpMenuPos &other // [IN] the menu pos which we want to test
    ) const
    {
        return (group != other.group || pos != other.pos);
    }

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // A helper operator that can write following code:
    // <code>
    //    VcpMenuPos p = ...;
    //    if (p) { do something; }
    // </code>
    operator bool() const
    {
        return isValid();
    }
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
    operator vm_base_menu_pos_struct() const;
#endif

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Return whether this pos is in a valid pos
    // RETURNS: VFX_TRUE if the menu pos is valid
    VfxBool isValid() const
    {
        return (group >= 0) && (pos >= -1);
    }
    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Make the position as invalid
    void invalid()
    {
        group = -1;
        pos = -1;
    }
    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Whether this position is a header
    // RETURNS: VFX_TRUE if the menu pos is a group header 
    VfxBool isGroupHeader() const
    {
        return (group >= 0) && (pos == -1);
    }

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Indicate the pos to header
    void setGroupHeader(
        VfxS32 g        // [IN] the group number
    )
    {
        group = g;
        pos = -1;
    }

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Indicate the pos to a cell
    void setCell(
        VfxS32 g,       // [IN] group of the cell
        VfxS32 p        // [IN] pos of the cell
    )
    {
        VFX_DEV_ASSERT(g >= 0 && p >= 0);
        group = g;
        pos = p;
    }

    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Get the next pos according to a layout
    // RETURNS: the next menu pos
    VcpMenuPos getNextPos(
        VcpBaseMenuLayout* layout,          // [IN] the layouter
        VfxBool includeHeader = VFX_TRUE    // [IN] whether stop at header
    ) const;
    
    // <group DOM_BaseMenu_VcpMenuPos_Method>
    // Get the next pos according to a layout
    // RETURNS: the previous menu pos
    VcpMenuPos getPrevPos(
        VcpBaseMenuLayout* layout,          // [IN] the layouter
        VfxBool includeHeader = VFX_TRUE    // [IN] whether stop at header
    ) const;
};

/***************************************************************************** 
 * Class VcpMenuRegion
 *****************************************************************************/

/*
 *  VcpMenuRegion indicates a range of menu.
 */
class VcpMenuRegion : public VfxBase
{
// Variable
public:
    // <group DOM_BaseMenu_VcpMenuRegion_Variable>
    VcpMenuPos begin;   // The begin menu pos of the region
    // <group DOM_BaseMenu_VcpMenuRegion_Variable>
    VcpMenuPos end;     // The end menu pos of the region.
        
// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpMenuRegion_Constructor/Destructor>
    // Default constructor
    VcpMenuRegion() {}
    // <group DOM_BaseMenu_VcpMenuRegion_Constructor/Destructor>
    // Constructor
    VcpMenuRegion(
        VfxS32 bg,          // [IN] group of begin cell index
        VfxS32 bp,          // [IN] pos of begin cell index
        VfxS32 eg,          // [IN] group of end cell index
        VfxS32 ep           // [IN] pos of end cell index
    ) : 
        begin(bg, bp), end(eg, ep)
    {
    }

    // <group DOM_BaseMenu_VcpMenuRegion_Constructor/Destructor>
    // Constructor
    VcpMenuRegion(
        VcpMenuPos b,       // [IN] index of begin cell
        VcpMenuPos e        // [IN] index of end cell
    ) : 
        begin(b), end(e)
    {
    }
    // <group DOM_BaseMenu_VcpMenuRegion_Constructor/Destructor>
    // Copy Constructor
    VcpMenuRegion(
        const VcpMenuRegion &other  // [IN] copy from other region object
    ) : 
        begin(other.begin),
        end(other.end)
    {
    }
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
    // <group DOM_BaseMenu_VcpMenuRegion_Constructor/Destructor>
    // Constructor for MRE
    VcpMenuRegion(
        const vm_base_menu_region_struct &other // [IN] MRE menu region which we want to copy
    ) : begin(other.begin), end(other.end) {}
#endif
// Method
    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Check whether this region is empty
    VfxBool isEmpty() const
    {
        return (!begin.isValid());
    }

    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // make the region empty
    void empty()
    {
        begin.invalid();
        end.invalid();
    }

    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Union a region and return this result
    // RETURNS: the result menu region object
    VcpMenuRegion unionRegion(
        const VcpMenuRegion &rgn    // [IN] region object which want to be union
    ) const;
    
    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Intersect a region and return this region
    // RETURNS: the result menu region object
    VcpMenuRegion intersectRegion(
        const VcpMenuRegion &rgn    // [IN] region object which want to be intersected
    ) const;
    
    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Whether a group is in the region
    // RETURNS: VFX_TRUE if the group is in the region
    VfxBool isWithin(
        VfxS32 group                // [IN] the group number which we want to test
    ) const
    {
        return (group >= begin.group) && (group <= end.group);
    }
    
    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Whether a menu position is in the region
    // RETURNS: VFX_TRUE if a menu pos is in the region
    VfxBool isWithin(
        VcpMenuPos pos              // [IN] the menu pos which we want to test
    ) const
    {
        return isWithin(pos.group, pos.pos);
    }
    
    // <group DOM_BaseMenu_VcpMenuRegion_Method>
    // Whether a menu position is in the region
    // RETURNS: VFX_TRUE if a menu pos is in the region
    VfxBool isWithin(
        VfxS32 group,               // [IN] group of the cell which we want to test
        VfxS32 pos                  // [IN] pos of the cell which we want to test
    ) const;
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__ 
// Operator
public:
    operator vm_base_menu_region_struct() const;
#endif
};

/***************************************************************************** 
 * Class VcpMenuCache
 *****************************************************************************/

#define VCP_MENUCACHE_ADDITION 16

// Extra flag for cache item

// Hit means the item is in the screen in this update process
#define VCP_MENUCACHE_FLAG_HIT      1
// Keep means the item will not be close even out of view
#define VCP_MENUCACHE_FLAG_KEEP     2
// Dummy means the item is a empty frame, not user's type
#define VCP_MENUCACHE_FLAG_DUMMY    4

/*
 *  VcpMenuCache is dictionary for resource manager. It can map a position to a frame.
 */
class VcpMenuCache : public VfxBase
{
// Declaration
public:

    // Key type to store (group, pos) in cache
    typedef VfxU64 Key;

/* DOM-NOT_FOR_SDK-BEGIN */    
    // Item is a data structure to record a cache entry in cache.
    class Item : public VfxBase
    {
    public:
        Key             key;    // The key index
        VfxFrameWeakPtr ptr;    // The object pointer
        VfxU32          flag;   // The extra flag for resource management. 
    };
/* DOM-NOT_FOR_SDK-END */

    typedef Item* ItemPtr;
    
// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpMenuCache_Constructor/Destructor>
    // Constructor
    VcpMenuCache();
    // <group DOM_BaseMenu_VcpMenuCache_Constructor/Destructor>
    // Destructor
    virtual ~VcpMenuCache();

// Method
public:

/* DOM-NOT_FOR_SDK-BEGIN */

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Set parent's pointer. Please carefully, cache will not maintain this pointer, 
    // so this pointer should be always valid when the cache is alive.
    void setParent(
        VcpBaseMenu* pMenu  // [IN] the cache's parent object
    );

/* DOM-NOT_FOR_SDK-END */

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Whether a pos is in cache
    // RETURNS: VFX_TRUE if the menu pos is in cache, otherwise return VFX_FALSE
    VfxBool isInCache(
        VcpMenuPos p    // [IN] the menu pos
    )
    {
        return isInCache(p.group, p.pos);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Whether a pos is in cache
    // RETURNS: VFX_TRUE if the menu pos is in cache, otherwise return VFX_FALSE
    VfxBool isInCache(
        VfxS32 group,   // [IN] the group of cell
        VfxS32 pos      // [IN] the pos of cell
    );
    
    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Get a item by position
    // RETURNS: the frame object pointer
    VfxFrame* getItem(
        VcpMenuPos p    // [IN] the menu pos
    )
    {
        return getItem(p.group, p.pos);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Get a item by position
    // RETURNS: the frame object pointer
    VfxFrame* getItem(
        VfxS32 group,   // [IN] the group of cell
        VfxS32 pos      // [IN] the pos of cell
    );
    
    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Set a item into cache
    void setItem(
        VcpMenuPos p,       // [IN] the menu pos
        VfxFrame* frame     // [IN] the cell object pointer
    )
    {
        setItem(p.group, p.pos, frame);
    }
    
    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Set a item into cache
    void setItem(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos,         // [IN] the pos of cell
        VfxFrame* frame     // [IN] the cell object pointer
    );
    
    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Remove a item by position from cache
    void removeItem(
        VcpMenuPos p        // [IN] the menu pos
    )
    {
        removeItem(p.group, p.pos);
    }
    
    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Remove a item by position
    void removeItem(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos          // [IN] the pos of cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Clear all cache
    void clear();

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Clear cache items which are not hit
    void clearIfNotHit();

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Hit a item. This is for cache operation
    void hit(
        VcpMenuPos pos      // [IN] the menu index
    )
    {
        hit(pos.group, pos.pos);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Hit a item. This is for cache operation
    void hit(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos          // [IN] the pos of cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Reset all hit flag
    void clearHitFlag();

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Reserve an item so it will not be free
    void setKeepFlag(
        VcpMenuPos pos,     // [IN] the menu index
        VfxBool isKeep      // [IN] whether keep the item in the cache
    )
    {
        setKeepFlag(pos.group, pos.pos, isKeep);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Reserve an item so it will not be free
    void setKeepFlag(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos,         // [IN] the pos of cell
        VfxBool isKeep      // [IN] whether keep the item in the cache
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Set an item as dummy, so it will be place a dummy empty frame.
    void setDummyFlag(
        VcpMenuPos pos,     // [IN] the menu index
        VfxBool isDummy     // [IN] whether the cell is a dummy cell
    )
    {
        setDummyFlag(pos.group, pos.pos, isDummy);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Set an item as dummy, so it will be place a dummy empty frame.
    void setDummyFlag(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos,         // [IN] the pos of cell
        VfxBool isDummy     // [IN] whether the cell is a dummy cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Get item count in the cache
    // RETURNS: the number of cell items
    VfxS32 getCount()
    {
        return m_itemCount;
    }

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // A helper function to set the extra flag in an item.
    void setFlag(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos,         // [IN] the pos of cell
        VfxU32 flag,        // [IN] the extra flag you want to set or clear
        VfxBool setFlag     // [IN] VFX_TRUE if you want to set the flag, otherwise set VFX_FALSE
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // A helper function to get the extra flag in an item.
    // RETURNS: the cell flag of a cell
    VfxU32 getFlag(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos          // [IN] the pos of cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Remove an item and shift forward item index in the group
    void withdrawItem(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos          // [IN] the pos of cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Shift backward item index in the group
    void putinItem(
        VfxS32 group,       // [IN] the group of cell
        VfxS32 pos          // [IN] the pos of cell
    );

    // <group DOM_BaseMenu_VcpMenuCache_Method>
    // Debug function for dump cache content.
    void debugDump();

/* DOM-NOT_FOR_SDK-BEGIN */

// Variable
protected:
    // <group DOM_BaseMenu_VcpMenuCache_Variable>
    VfxS32  m_itemCount;        // The item count in the cache
    // <group DOM_BaseMenu_VcpMenuCache_Variable>
    VfxS32  m_itemTotalCount;   // The memory pool size
    // <group DOM_BaseMenu_VcpMenuCache_Variable>
    ItemPtr *m_items;           // The entry pool pointer
    // <group DOM_BaseMenu_VcpMenuCache_Variable>
    VcpBaseMenu* m_pMenu;       // The parent pointer

// Implementation
protected:
    // <group DOM_BaseMenu_VcpMenuCache_Implementation>
    // Combine group and pos into a index value.
    // RETURNS: The index value.
    Key makeKey(
        VfxS32 group,   // [IN] The group index
        VfxS32 pos      // [IN] The pos index in a group
    )
    {
        // we offset pos 1, because -1 is a special key for header
        return (VfxU64(group) << 32) + VfxU32(pos + 1);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Implementation>
    // Combine group and pos into a index value with VcpMenuPos input.
    // RETURNS: The index value.
    Key makeKey(
        VcpMenuPos p    // [IN] The menu position
    )
    {
        return makeKey(p.group, p.pos);
    }
    
    // <group DOM_BaseMenu_VcpMenuCache_Implementation>
    // Invert key back to group and pos.
    // RETURNS: the menu position.
    VcpMenuPos decodeKey(
        Key key         // [IN] The key index
    )
    {
        return VcpMenuPos(VfxS32(key >> 32), VfxS32(key & 0xFFFFFFFF) - 1);
    }

    // <group DOM_BaseMenu_VcpMenuCache_Implementation>
    // Do binary search in the entry pool.
    // RETURNS: the search position in the pool.
    VfxS32 bisect_left(
        Key key         // [IN] The key index
    );

/* DOM-NOT_FOR_SDK-END */

};


class VcpMenuMarginItem : public VfxBase
{
// Constructor
public:
    VcpMenuMarginItem():
        m_mpos(VcpMenuPos()), m_placement(VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_END), m_framePtr(NULL), m_accumulatedLength(0)
    {};

    VcpMenuMarginItem(VcpMenuPos pos, VcpBaseMenuMarginAreaFramePlacementEnum placement, VfxFrame *frame):
        m_mpos(pos), m_placement(placement), m_framePtr(frame), m_accumulatedLength(frame->getSize().height)
    {};


// Variable
public:
    VcpMenuPos m_mpos;
    VcpBaseMenuMarginAreaFramePlacementEnum m_placement;    
    VfxFrameWeakPtr m_framePtr;
    VfxS32 m_accumulatedLength;
};



/***************************************************************************** 
 * Class VcpBaseMenuLayout
 *****************************************************************************/

/*
 *   VcpBaseMenuLayout is a interface that can make user plugin the layout logic.
 */
class VcpBaseMenuLayout : public VfxObject
{
// Enum
public:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Enum>
    // This enum is for navigation key.
    enum NavDirEnum
    {
        NAV_DIR_NONE,       // No direction 
        NAV_DIR_UP,         // Up direction
        NAV_DIR_DOWN,       // Down direction
        NAV_DIR_LEFT,       // Left direction
        NAV_DIR_RIGHT       // Right direction 
    };

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Enum>
    // This enum is for margin index.
    enum MarginEnum
    {
        MARGIN_LEFT     = 0,    // Left side of margin
        MARGIN_UP       = 1,    // Up side of margin
        MARGIN_RIGHT    = 2,    // Right side of margin
        MARGIN_DOWN     = 3     // Down side of margin
    };

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Enum>
    // This enum is for scrolling direction.
    enum ScrollDirEnum
    {
        SCROLLDIR_HORZ,         // Horizontal scroll direction
        SCROLLDIR_VERT          // Vertical scroll direction
    };

// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Constructor/Destructor>
    // Constructor
    VcpBaseMenuLayout() {}
    VcpBaseMenuLayout(VcpBaseMenu* menu) : m_pMenu(menu) {}
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Constructor/Destructor>
    // Destructor
    virtual ~VcpBaseMenuLayout() {}

// Method
public:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // set menu
    void setMenu(VcpBaseMenu* menu) {m_pMenu = menu;}
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // Call this function to notify menu to relayout cell.
    void update();

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // Return whether the scrolling direction is vertical
    bool isScrollVert()
    {
        return getScrollDir() == SCROLLDIR_VERT;
    }

protected:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // Return the view size of the menu.
    // RETURNS: The menu view size.
    const VfxSize& getViewSize() const
    {
        return m_viewRect.size;
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // Return the view position of the menu.
    // RETURNS: The menu view position.
    const VfxPoint& getViewPos() const
    {
        return m_viewRect.origin;
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Method>
    // Make a menu item visible in the screen.
    void makeVisible(
        VcpMenuPos p,               // [IN] The menu index
        VfxBool isAnim = VFX_TRUE   // [IN] Whether need do animation
    );

// Overridable
public:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the scroll direction
    // RETURNS: the enum about scroll direction
    virtual ScrollDirEnum getScrollDir() = 0;

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the number of groups of this layout.
    // Inherit should override this method.
    // RETURNS: the number of group count
    virtual VfxS32 getGroupCount()
    {
        return 1;
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return whether there are group headers
    // RETURNS: VFX_TRUE if has group header, otherwise return VFX_FALSE
    virtual VfxBool hasGroupHeader(
        VfxS32 group    // [IN] The group index
    )
    {
        VFX_UNUSED(group);
        return VFX_FALSE;
    }
    
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the number of cells of a group.
    // Inherit should override this method.
    // RETURNS: The number of cell count
    virtual VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
    ) 
    {
        VFX_UNUSED(group);
        return 0;
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the whole size of the menu.
    // Inherit should override this method.
    // RETURNS: the length of content area
    virtual VfxS32 getContentLength() = 0;

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the region within a rectangle.
    // RETURNS: The region object about the input rect
    virtual VcpMenuRegion queryRegion(
        const VfxRect& r    // [IN] The rectangle to query the menu region
    ) = 0;

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return the header rect of a group
    // RETURNS: the region object for the input group 
    virtual VfxRect queryGroupHeaderRect(
        VfxS32 group    // [IN] The group index
    )
    {
        VFX_UNUSED(group);
        return VfxRect(0, 0, 0, 0);
    }

    virtual VfxRect queryMarginItemRect(VcpMenuPos pos)
    {
        VFX_UNUSED(pos);
        return VfxRect(0, 0, 0, 0);
    }  



    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Return a cell rect
    // RETURNS: the rect for the input menu pos 
    virtual VfxRect queryCellRect(
        VcpMenuPos pos  // [IN] The cell index to query
    )
    {
        VFX_UNUSED(pos);
        return VfxRect(0, 0, 0, 0);
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Notify the layout that the view is changed.
    // Inheritor can override to adjustment the view or focus item
    virtual void onViewChanged()
    {
    }

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Change the Focus Index
    virtual void setFocusItem(
        VcpMenuPos focus,                   // [IN] The focus index
        VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Query the focus index
    // RETURNS: the menu pos about focus item
    virtual VcpMenuPos getFocusItem() const;

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Clear Focus, so the lauout will clear focus index.
    virtual void clearFocusItem();

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VfxBool navDir(
        NavDirEnum dir  // [IN] the change focus direction
    );

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Get the focus margin.
    // Focus margin is the prefer space that focus item should not be over.
    virtual void getPreferFocusMargin(
        VfxS32 margin[4] // [OUT] the focus margin in Left, Up, Right, Down
    );

    // <group DOM_BaseMenu_VcpBaseMenuLayout_Overridable>
    // Notify layout to fix the stop point
    virtual void onStopPosFix(
        VfxPoint& pos   // [IN/OUT] the stop position that sub-class want to fix
    )
    {
    }

    virtual VfxS32 getMarginLength(VcpBaseMenuMarginAreaEnum area);

    virtual VfxS32 getTotalLength();



/* DOM-NOT_FOR_SDK-BEGIN */

// BaseMenu Protocol
public:
    // The API is call by Menu when the view rectangle is changed.
    void setViewRect(VfxRect r)
    {
        if (m_viewRect != r)
        {
            m_viewRect = r;
            onViewChanged();
        }
    }

// Override
public:

// Variable    
protected:
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Variable>
    VfxRect m_viewRect;

    
    // <group DOM_BaseMenu_VcpBaseMenuLayout_Variable>
    VcpBaseMenu *m_pMenu;   // The menu object that is using this layout.

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__    
    friend class VpiBaseMenuLayoutProxy;
#endif

/* DOM-NOT_FOR_SDK-END */
};


/***************************************************************************** 
 * Class VcpMenuRegionIter
 *****************************************************************************/

/*
 *  VcpMenuRegionIter is a helper class to help you get all cell in a loop.
 */
class VcpMenuRegionIter : public VfxBase
{
// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpMenuRegionIter_Constructor/Destructor>
    // Constructor
    VcpMenuRegionIter(VcpBaseMenuLayout* layout, VcpMenuRegion r);
    // <group DOM_BaseMenu_VcpMenuRegionIter_Constructor/Destructor>
    // Constructor
    VcpMenuRegionIter(VcpBaseMenu* menu, VcpMenuRegion r);

// Method
public:
    // <group DOM_BaseMenu_VcpMenuRegionIter_Method>
    // set the default parameters
    void reset(VcpBaseMenuLayout* layout, VcpMenuRegion r);

    // <group DOM_BaseMenu_VcpMenuRegionIter_Method>
    // The loop is end?
    // RETURNS: VfxTrue if the menu is in the end
    VfxBool isEnd()
    {
        return !m_pos.isValid();
    }

    // <group DOM_BaseMenu_VcpMenuRegionIter_Method>
    // Get next cell index
    // RETURNS: next cell index
    VcpMenuPos next();

// Variable
private:
    VcpMenuRegion           m_region;   // The menu region that contains the menu range.
    VcpMenuPos              m_pos;      // The current index.
    VcpBaseMenuLayout*      m_layout;   // The related layout object. 

// Implementation
private:
};


/***************************************************************************** 
 * Class VcpBaseMenuView
 *****************************************************************************/

// VcpBaseMenuView is used to hook pen state from Scrollable.
// It will pass pen input to menu class.
class VcpBaseMenuView : public VcpScrollableView
{
// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpBaseMenuView_Constructor/Destructor>
    // Constructor
    VcpBaseMenuView();
    // <group DOM_BaseMenu_VcpBaseMenuView_Constructor/Destructor>
    // Destructor
    virtual ~VcpBaseMenuView(){}

// Method
public:
    // <group DOM_BaseMenu_VcpBaseMenuView_Method>
    // Get the menu object pointer.
    // RETURNS: The associated menu object
    VcpBaseMenu* getMenu();

// Override
public:
    // <group DOM_BaseMenu_VcpBaseMenuView_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);
    // <group DOM_BaseMenu_VcpBaseMenuView_Override>
    virtual void onFreeRunSetTargetContentOffset(VfxPoint &offset);

// Variable
protected:
    // <group DOM_BaseMenu_VcpBaseMenuView_Variable>
    VfxBool m_isDraged;     // Is current in drag state?

// Implementation
protected:
    // <group DOM_BaseMenu_VcpBaseMenuView_Implementation>
    friend class VcpBaseMenu;
};


/***************************************************************************** 
 * Struct VcpBaseMenuViewState
 *****************************************************************************/

// This structure is used to record the current menu position.
struct VcpBaseMenuViewState
{
    VfxS32      contentXOffset;     // The X value of content offset
    VfxS32      contentYOffset;     // The Y value of content offset
    VfxS32      focusGroup;         // The group value of focus cell
    VfxS32      focusPos;           // The pos value of focus cell
};


/***************************************************************************** 
 * Class VcpBaseMenu
 *****************************************************************************/

// The following flag is for onUpdateGroupHeader and onUpdateCell

// Indicate the cell is in target region
#define VCP_CELL_FLAG_TARGET        (1 << 0)

// Indicate this is the first time to update this cell
#define VCP_CELL_FLAG_FIRSTINIT     (1 << 1)

// Indicate menu is in opening animation state
#define VCP_CELL_FLAG_OPENING       (1 << 2)

// Indicate menu is in closing animation state
#define VCP_CELL_FLAG_CLOSING       (1 << 3)

// Current no used. Plan to remove.
#define VCP_CELL_FLAG_FORCESET      (1 << 4)

/*
 *  VcpBaseMenu provides a basic framework for venus menu.
 *  You should inherit it and provides your layouter.
 */
class VcpBaseMenu : public VcpScrollable
{
    VFX_DECLARE_CLASS(VcpBaseMenu);

// Enum
public:
    // <group DOM_BaseMenu_VcpBaseMenu_Enum>
    // The menu state enum
    enum MenuStateEnum
    {
        Normal,         // Normal state means the stable state of menu. In most of time, menu should keep in this state.
        Opening,        // Opening state is an unstable state happend when menu is showing new content.
        Closing,        // Closing state is an unstable state happend when menu is removing old content.
        WaitClosing     // WaitClosing state is a half state about closing old item. 
                        // It is an unstable state when menu is waiting for post event for removing items.
    };
    // <group DOM_BaseMenu_VcpBaseMenu_Enum>
    // The touch event type enum
    enum CellTouchTypeEnum
    {
        TouchDown,      // User's finger or pen is press down the cell.
        TouchUp,        // User's finger or pen is release up the cell.
        TouchTap,       // User's finger or pen is press down and up on a cell, and FW think it is a tap event.
        TouchLongTap    // User's finger or pen is press down on a cell very long.
    };

// Constructor / Destructor
public:
    // <group DOM_BaseMenu_VcpBaseMenu_Constructor/Destructor>
    // Constructor
    VcpBaseMenu();
    // <group DOM_BaseMenu_VcpBaseMenu_Constructor/Destructor>
    // Destructor
    virtual ~VcpBaseMenu(){}

// Method
public:
    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Return the layout object which return from createLayout function.
    // RETURNS: the layout object
    VcpBaseMenuLayout* getLayout()
    {
        return m_layout;
    }

/* DOM-NOT_FOR_SDK-BEGIN */
// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void reset();    
    virtual void setBounds(const VfxRect &value);
    virtual VcpScrollableView *onCreateView();
/* DOM-NOT_FOR_SDK-END */

// Method
public:

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // add a margin area item, the newer, the inner
    virtual void addMarginItem(
       VcpBaseMenuMarginAreaEnum area,                     // [IN] The margin area type
       VcpBaseMenuMarginAreaFramePlacementEnum placement,  // [IN] The frame placement
       VfxFrame *frame                                     // [IN] The frame to be added
    );


    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // remove margin item by frame
    virtual void removeMarginItem(
       VfxFrame *frame // [IN] The frame to be removed
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // remove margin item by MenuPos (group is VcpBaseMenuMarginAreaEnum, pos is from 0 to COUNT-1 and the inner, the smaller)
    virtual void removeMarginItem(
        VcpMenuPos pos // [IN] The frame to be removed
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    VfxFrame* getMarginItem(VcpMenuPos pos);

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Change the Focus Index
    virtual void setFocusItem(
       VcpMenuPos focus,                   // [IN] The focus index
       VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );   

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Query the focus index
    // RETURNS: the menu pos about focus item
    virtual VcpMenuPos getFocusItem() const;   

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Clear Focus
    virtual void clearFocusItem();

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Change the Focus Margin Index
    virtual void setFocusMarginItem(
       VcpMenuPos focus,                   // [IN] The focus index
       VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );   

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Query the focus margin index
    // RETURNS: the menu pos about focus margin item
    virtual VcpMenuPos getFocusMarginItem() const;   

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Clear Focus margin item
    virtual void clearFocusMarginItem();    


    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the focus item is change
    virtual void onFocusMarginIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Scroll a rectangle into view
    void makeMarginVisible(
        VcpMenuPos p,               // [IN] the menu index we want to make it visible
        VfxBool isAnim = VFX_TRUE   // [IN] whether need scroll with animation
    );

   

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // This method notify the menu that the layout changed, 
    //  so menu need to do re-layout.
    void updateLayout();

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Get the cell frame if the frame is exist
    VfxFrame* getCellIfPresent(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Get the header frame if the frame is exist
    VfxFrame* getHeaderIfPresent(
        VfxS32 group            // [IN] The group index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Query the region about valid view. This function will convert rect into region object.
    // RETURNS: The region about real content rect
    VcpMenuRegion getRealContentRegion()
    {
        return m_curRegion;
    }

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Calculate the visible offset.
    // This function will reference refer focus margin.
    // RETURNS: The offset to make this rectangle visible.
    VfxPoint calVisibleOffset(
        const VfxRect& r    // [IN] The rect we want to calculate the visible offset
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Scroll the view to make the cell visible
    void makeVisible(
        VcpMenuPos p,               // [IN] the menu index we want to make it visible
        VfxBool isAnim = VFX_TRUE   // [IN] whether need scroll with animation
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Scroll a rectangle into view
    void makeVisible(
        const VfxRect& r,           // [IN] the rect we want to make it visible
        VfxBool isAnim = VFX_TRUE   // [IN] whether need scroll with animation
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Scroll view port to a point
    void scrollContent(
        VfxPoint pt,                // [IN] The new top-left point of view
        VfxBool isAnim = VFX_TRUE   // Whether need animation
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Close Group Header
    void closeGroupHeader(
        VfxS32 group            // [IN] The group index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Close Cell
    void closeCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Swap Cell
    void swapCell(
        VcpMenuPos pos1,        // [IN] the pos 1 will be swap
        VcpMenuPos pos2         // [IN] the pos 2 will be swap
    );    

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Get the current view state, you can set the data back to base menu to restore previous view state.
    void getViewState(
        VcpBaseMenuViewState* history // [OUT] the current menu history
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Restore the menu view state, you can get the view state by getViewState API.
    void setViewState(
        VcpBaseMenuViewState* history // [IN] the menu history
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Set cache length (in pixel), such that base menu will cache the cell items in the area "view + cache length"
    // If len = 0, use default cache length
    void setCacheLen(
        VfxS32 len      // [IN] cache length, in pixel
    )
    {
        m_cacheLen = len;
    }

    // Set cache style, center means cache range set the current view as center
    // predict means cache range will set according to the scrolling direction
    void setCacheStyle(VcpBaseMenuCacheStyle style)
    {
        m_cacheStyle = style;
    }
// Method
protected:
    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Remove a menu cell from base menu with placement a dummy cell
    // RETURNS: the frame about previous cell
    VfxFrame* pullOutCell(
        VcpMenuPos pos      // the cell index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Remove item and shift menu item index in a group
    void withdrawCell(
        VfxS32 group,       // the group of cell 
        VfxS32 pos          // the pos of cell 
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Method>
    // Shift menu item index after a cell in a group
    void putinCell(
        VfxS32 group,       // the group of cell 
        VfxS32 pos          // the pos of cell 
    );

// Overridable
protected:
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Create a layout object for menu.
    // Inheritor should override this function.
    // RETURNS: a layout object 
    // SEE ALSO: VcpBaseLayout
    virtual VcpBaseMenuLayout* createLayout() = 0;
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // After menu create a new layout and query basic information.
    virtual void onAfterCreateLayout() {};

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Create a group header.
    // Inheritor should override this function.
    // RETURNS: a group object 
    // SEE ALSO: VcpBaseLayout
    virtual VfxFrame* createGroupHeader(
        VfxS32 group // [IN] The group index
    )
    {
        VFX_UNUSED(group);
        return NULL;
    };

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a cell object 
    // SEE ALSO: VcpBaseLayout
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    ) = 0;
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // A notify that menu is going to close a header
    virtual void onCloseGroupHeader(
        VfxS32 group,           // [IN] The group index
        VfxFrame* groupFrame    // [IN] The group will be closed
    )
    {
        VFX_UNUSED(group);
        VFX_UNUSED(groupFrame);
    }
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    ) = 0;

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify before updating cell and group.
    virtual void onBeforeUpdate(
        const VcpMenuRegion& currentRegion, // [IN] The region of current valid view
        const VcpMenuRegion& targetRegion   // [IN] The region of target view
    )
    {
        VFX_UNUSED(currentRegion);
        VFX_UNUSED(targetRegion);
    }

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify before updating cell and group.
    virtual void onAfterUpdate(
        const VcpMenuRegion& currentRegion, // [IN] The region of current valid view
        const VcpMenuRegion& targetRegion   // [IN] The region of target view
    )
    {
        VFX_UNUSED(currentRegion);
        VFX_UNUSED(targetRegion);
    }
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify to update a header's attributes
    // Inheritor should override this function.
    virtual void onUpdateGroupHeader(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxFrame* groupObject,  // [IN] The group object
        VfxU32 flag             // [IN] The state about this header
    )
    {
        VFX_UNUSED(rect);
        VFX_UNUSED(group);
        VFX_UNUSED(groupObject);
        VFX_UNUSED(flag);
    }
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    ) = 0;

    virtual void onUpdateMarginItem(const VfxRect &rect, VcpMenuPos pos, VfxFrame* frame)
    {
        VFX_UNUSED(pos);
        if (frame && rect != frame->getRect())
        {
            frame->setRect(rect);
        }        
    }


    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when a group header is clicked
    virtual void onTapGroupHeader(
        VfxS32 group,           // [IN] The group index
        VfxFrame* groupObject   // [IN] The group object
    )
    {
        VFX_UNUSED(group);
        VFX_UNUSED(groupObject);
    }
    
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when a cell is clicked
    virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    )
    {
        VFX_UNUSED(group);
        VFX_UNUSED(pos);
        VFX_UNUSED(cell);
    }

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when a cell or header is interact.
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    )
    {
        VFX_UNUSED(cellPos);
        VFX_UNUSED(touchType);
        VFX_UNUSED(pt);
        VFX_UNUSED(cell);
    }

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the user start drag the menu
    virtual void onDragStart();

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the user stop drag the menu
    virtual void onDragEnd();

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify the view is scrolling.
    virtual void onViewScrollStart();

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd();

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the menu is tapped
    virtual void onTap(
        const VfxPoint &pt  // [IN] The tap position
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Notify when the view is dragged
    virtual void onDrag(
        VfxS32 xoffset,     // the x value about drag offset
        VfxS32 yoffset      // the y value about drag offset
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Override>
    // Override this function to decide your stop position.
    // NOTE: Default this function will call layout->onStopPosFix() to fix the stop position.
    virtual void onScrollStopPosFix(
        VfxPoint& pos // [IN/OUT] The stop position, modify this value to have new stop point.
    );

    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // Override this function to decide whether your menu support transition effect.
    // If you return True in this function, base menu will enter closing and opening state when reset layout.
    // Usually it can use to do some animation effect when change content.
    // Default value in base class is True.
    // RETURNS: VFX_TRUE if support transition, otherwise return VFX_FALSE
    virtual VfxBool IsSupportTransition();

// Signal
public:
    // <group DOM_BaseMenu_VcpBaseMenu_Overridable>
    // This event is invoked when menu re-create the layout object.
    // It is invoked when you call reset API.
    // void YouClass::onResetLayout(VcpBaseMenu* sender)
    VfxSignal1<
        VcpBaseMenu*        // [IN] The caller object
    > m_signalResetLayout;

/* DOM-NOT_FOR_SDK-BEGIN */

// Override    
protected:
    virtual void onUpdate();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

// Slot
protected:
    virtual void onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);  

/* DOM-NOT_FOR_SDK-END */

// Variable
public:
    VfxArray <VcpMenuMarginItem> m_marginItemArray[VCP_BASE_MENU_MARGIN_AREA_END];

protected:

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuPos m_focusItem; // The current focus item

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuPos m_focusMarginItem;   // The current focus item    

    
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool m_isPenProcessing;

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpBaseMenuLayout   *m_layout;              // The layout object pointer
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxTimer            *m_timer;               // The timer use for animation.

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuCache        m_cache;                // The object cache container
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxS32              m_preScrollDir;         // Record the old scroll direction. 
                                                // 1 means scroll to high position.
                                                // -1 means scroll to low position.
                                                // It can help cache algorithm.

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxS32              m_contentLength;        // The menu content length.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxRect             m_curValidRect;         // The rect of valid region.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuRegion       m_curRegion;            // Current Real Content region.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuRegion       m_targetRegion;         // Target region.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_needRelayout;         // Whether need to do relayout in next update.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool 			m_needMarginItemRelayout;
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_needCellRelayout;     // Whether need to update again cells.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_forceResetScrollPos;  // Scroll content is call. So in cache logic, don't use real view.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_isScrolling;          // Whether the menu is scrolling.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    MenuStateEnum       m_state;                // The menu state in opening, closing, etc...
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxS32              m_opeingTimeMS;         // The duration about opening animation.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxS32              m_closingTimeMS;        // The duration about closing animation.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxS32              m_cacheLen;             // The cache length. 0 means to use default value.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VcpMenuPos          m_clickedPos;           // The tapped cell index.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxFrameWeakPtr     m_clickedCell;          // The tapped cell reference.
    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_preExistCell;         // Whether base menu has cells, if not, can speed up some operations.

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VfxBool             m_isOnDeinit;           // Whether current stage is in deinit

    #define VCP_BASEMENU_VISIBLEVIEW_FLAG_ANIM           1
    #define VCP_BASEMENU_VISIBLEVIEW_FLAG_OFFSET         2
    #define VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS          4
    #define VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS_MARGIN   8   
    #define VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT          16 


    // Please take care each field has no virtual function
    struct VisibleView
    {
        VfxU32      flag;           // Which field is valid
        VfxPoint    contentOffset;  // view offset, valid when VCP_BASEMENU_VISIBLEVIEW_FLAG_OFFSET
        VcpMenuPos  focus;          // focus item, valid when VCP_BASEMENU_VISIBLEVIEW_FLAG_FOCUS
        VfxRect     rect;           // rect of visible rect, valid when VCP_BASEMENU_VISIBLEVIEW_FLAG_RECT
    };

    // <group DOM_BaseMenu_VcpBaseMenu_Variable>
    VisibleView         *m_pVisibleView;    // Which view that APP want to visible. Since base menu have some async operation, 
                                            // so in transition state, the operation need to queue and wait for onUpdate.
    VcpBaseMenuCacheStyle m_cacheStyle;
    VfxBool m_isContentWarning;

/* DOM-NOT_FOR_SDK-BEGIN */

// Implementation
protected:
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        newLayout();
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    VfxFrame*   getCell(VcpMenuPos pos, VfxU32& flag);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        delCell(VcpMenuPos pos);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        updateCell(const VfxRect &rect, VcpMenuPos pos, VfxU32 flag);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        resetInternal();
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    VfxS32      getMaxScrollLength();
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    VfxRect     calValidView();
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    VfxSize     getLayoutContentSize();
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        tapView(const VfxPoint &pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        dragView(VfxBool isDrag, const VfxPoint& pt, const VfxPoint& down_pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        penDown(const VfxPoint &pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        penUp(const VfxPoint &pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        penLongDown(const VfxPoint &pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    void        penAbort(const VfxPoint &pt);
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    VcpMenuPos  hitTestCell(const VfxPoint &pt);
    
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    friend class VcpMenuCache;
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    friend class VcpMenuRegionIter;
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    friend class VcpBaseMenuLayout;
    // <group DOM_BaseMenu_VcpBaseMenu_Implementation>
    friend class VcpBaseMenuView;

// Slot
protected:
    void onTimerTick(VfxTimer *source);
    void onContentWarning(VcpScrollableView* sender);
    void notifyScrollStart(VcpScrollable* sender);
    void notifyScrollEnd(VcpScrollable* sender);

/* DOM-NOT_FOR_SDK-END */
};


// Base Menu Utility
#if defined(__MMI_VUI_COSMOS_CP__)
void vcpBaseMenuLayoutQueryMarginRectByPt(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxPoint & p, VfxRect & result);

VfxBool vcpBaseMenuNavDirHelper(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, VcpBaseMenuLayout::NavDirEnum dir, const VcpMenuPos & pos, const VcpMenuPos & newPos, VfxRect & targetRect);

#else // defined(__MMI_VUI_COSMOS_CP__)
VcpMenuPos vcpBaseMenuLayoutQueryMarginItemByPt(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxPoint & p);

#endif // defined(__MMI_VUI_COSMOS_CP__)

VfxRect queryMarginItemRectHelper(VcpBaseMenu * menu, VcpBaseMenuLayout * layout, const VfxRect & viewRect, VcpMenuPos pos, VfxBool reverse);

#endif // _VCP_BASE_MENU_H_
