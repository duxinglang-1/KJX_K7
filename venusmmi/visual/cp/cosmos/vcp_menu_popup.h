/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  vcp_menu_popup.h
*
* Project:
* --------
*  VenusMMI
*
* Description:
* ------------
*  Menu Popup header
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

#ifndef __VCP_MENU_POPUP_H__
#define __VCP_MENU_POPUP_H__


/***************************************************************************** 
* Include
*****************************************************************************/
#include "vcp_base_menu.h"
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vfx_control.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vfx_frame_aligner.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_base_popup.h"
#include "vfx_input_event.h"
#include "vfx_screen.h"
#include "vcp_button.h"

#if defined(__MMI_VUI_COSMOS_CP__) 

/***************************************************************************** 
* Define
*****************************************************************************/
// 320x480 

#define VCP_MENU_POPUP_TITLE_TEXT_COLOR    VFX_COLOR_RES(VCP_COL_MENU_POPUP_TITLE_TEXT)
#define VCP_MENU_POPUP_CELL_N_TEXT_COLOR   VFX_COLOR_RES(VCP_COL_MENU_POPUP_CELL_N_TEXT)
#define VCP_MENU_POPUP_CELL_H_TEXT_COLOR   VFX_COLOR_RES(VCP_COL_MENU_POPUP_CELL_H_TEXT)
#define VCP_MENU_POPUP_CELL_HINT_TEXT_COLOR   VFX_COLOR_RES(VCP_COL_MENU_POPUP_CELL_HINT_TEXT)


#if defined(__MMI_MAINLCD_320X480__)
#define  VCP_MENU_POPUP_LEFT_CONTENT_MARGIN 10
#define VCP_MENU_POPUP_ICON_TEXT_GAP	5
#define  VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN 10
#define VCP_MENU_POPUP_CELL_HEIGHT                           51
#define VCP_MENU_POPUP_WIDTH_POTRAIT                     259
#define VCP_MENU_POPUP_WIDTH_LANDSCAPE               340
#define VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE        20
#define VCP_MENU_POPUP_TITLE_FONT_SIZE                   15
#elif defined(__MMI_MAINLCD_480X800__)
#define  VCP_MENU_POPUP_LEFT_CONTENT_MARGIN   32
#define VCP_MENU_POPUP_ICON_TEXT_GAP	5
#define  VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN 21
#define VCP_MENU_POPUP_CELL_HEIGHT                           86
#define VCP_MENU_POPUP_WIDTH_POTRAIT                     388
#define VCP_MENU_POPUP_WIDTH_LANDSCAPE               546
#define VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE        30
#define VCP_MENU_POPUP_TITLE_FONT_SIZE                   24
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define  VCP_MENU_POPUP_LEFT_CONTENT_MARGIN 11
#define VCP_MENU_POPUP_ICON_TEXT_GAP	5
#define  VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN 11
#define VCP_MENU_POPUP_CELL_HEIGHT                           45
#define VCP_MENU_POPUP_WIDTH_POTRAIT                     222
#define VCP_MENU_POPUP_WIDTH_LANDSCAPE               242
#define VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE        16
#define VCP_MENU_POPUP_TITLE_FONT_SIZE                   13
#else
#define  VCP_MENU_POPUP_LEFT_CONTENT_MARGIN 10
#define VCP_MENU_POPUP_ICON_TEXT_GAP	5
#define  VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN 10
#define VCP_MENU_POPUP_CELL_HEIGHT                           51
#define VCP_MENU_POPUP_WIDTH_POTRAIT                     259
#define VCP_MENU_POPUP_WIDTH_LANDSCAPE               340
#define VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE        20
#define VCP_MENU_POPUP_TITLE_FONT_SIZE                   15
#endif
#define VCP_MENU_POPUP_SEP_LINE_HEIGHT   2
#define VCP_MENU_POPUP_SEP_LINE_COLOR_1 VRT_COLOR_MAKE(30, 128, 128, 128)
#define VCP_MENU_POPUP_SEP_LINE_COLOR_2 VRT_COLOR_MAKE(80, 128, 128, 128)
/***************************************************************************** 
* Typedef
*****************************************************************************/

enum VcpMenuPopupBaseMenuEventEnum
{
    VCP_MENU_POPUP_BASE_MENU_EVENT_ITEM_SELECTED,
    VCP_MENU_POPUP_BASE_MENU_EVENT_END_OF_ENUM
};  

enum VcpMenuPopupItemEventEnum
{
    VCP_MENU_POPUP_ITEM_EVENT_TAP,
    VCP_MENU_POPUP_ITEM_EVENT_SET_FOCUS,
    VCP_MENU_POPUP_ITEM_EVENT_END_OF_ENUM
};

// <group DOM_MenuPopup_Macro&Enum_Enum>
// Enum of event type notified by the menu popup 
enum VcpMenuPopupEventEnum
{
    VCP_MENU_POPUP_EVENT_ITEM_SELECTED,    // a menu item is selected
    VCP_MENU_POPUP_EVENT_MENU_CANCEL,      // the menu is cancelled by click outside or the close button
    VCP_MENU_POPUP_EVENT_MENU_CLOSE        // the menu is to be closed
};

enum VcpMenuPopupItemType
{
    VCP_MENU_POPUP_ITEM_TYPE_1,
    VCP_MENU_POPUP_ITEM_TYPE_2       
};

enum VcpMenuPopupItemType2HintPlacement
{
    VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_RIGHT,
    VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_BOTTOM       
};


// DOM-NOT_FOR_SDK-BEGIN

/***************************************************************************** 
* class VcpMenuPopupBaseMenuLayout (Helper class)
* This a helper class, that helps to layout the menu.
* If no custoimization is needed, this class API is not directly accessed by client applications
*****************************************************************************/
class VcpMenuPopupBaseMenuLayout : public VcpBaseMenuLayout
{
    friend class VcpMenuPopupBaseMenu;

    // Constructor / Destructor
public:    
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Constructor/Destructor>
    VcpMenuPopupBaseMenuLayout(VcpBaseMenu* menu);

    // Override
public:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Override>
    virtual void onInit();

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual ScrollDirEnum getScrollDir();

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VfxS32 getGroupCount();

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VfxS32 getCellCount(VfxS32 group);

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VfxS32 getContentLength();

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VcpMenuRegion queryRegion(const VfxRect& r);

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    VcpMenuPos getCellByPos(VfxPoint pt);

    // Return a cell rect
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VfxRect queryCellRect(VcpMenuPos pos);

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual void getPreferFocusMargin(VfxS32 margin[4]);

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Overridable>
    virtual VfxBool navDir(NavDirEnum dir);

public:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Property>
    VfxS32 getCellNum() const;

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Property>
    void setCellNum(VfxS32 num);

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Property>
    const VfxSize getCellSize() const;

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Property>
    void setCellSize(const VfxSize &cellSize);

    // Variable
protected:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Implementation>
    VfxS32 m_cellHeight;
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Implementation>
    VfxS32 m_cellWidth;    
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenuLayout_Implementation>
    VfxS32 m_cellCount;
};

// DOM-NOT_FOR_SDK-END

/***************************************************************************** 
* Class VcpMenuPopupItem
* This class defines a single item in the menu.
* VcpMneuPopup automatically creates this class's object when it adds new menu items
* This class can be inherited to have customized menu items.
* If no custoimization is needed, this class API is not directly accessed by client applications
*****************************************************************************/
class VcpMenuPopupItem : public VfxControl
{
    // Constructor / Destructor
public:
    // Default constructor
    // <group DOM_MenuPopup_VcpMenuPopupItem_Constructor/Destructor>
    VcpMenuPopupItem();    

    // Overridable
protected:
    // <group DOM_MenuPopup_VcpMenuPopupItem_Override>
    virtual void onInit();

public:
    // <group DOM_MenuPopup_VcpMenuPopupItem_Override>
    virtual void setBounds(const VfxRect &value);    
    
    // <group DOM_MenuPopup_VcpMenuPopupItem_Override>
    virtual void onUpdate();
        
    // Set text
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    virtual void setText(VfxResId resId);
    
    // Set text
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    virtual void setText(const VfxWChar *mem);

    // Set text
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    virtual void setText(const VfxWString &str);
    
    // Get current text
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    VfxWString getText() const;

    // Set the icon.
    // It dispays on the right end of menu item
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    virtual void setIcon(const VfxImageSrc &img);
    
    // Get the icon.    
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    const VfxImageSrc &getIcon() const;

    // Set the item ID
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    void setId(VfxId id)
    {
        m_id = id;
    }

    // Get the item ID
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
    VfxId getId() const
    {
        return m_id;
    }

    // This function is called whenever there is an event on the menu item (basically touch event)
    // <group DOM_MenuPopup_VcpMenuPopupItem_Overridable>
    virtual VfxBool onEvent(VcpMenuPopupItemEventEnum event, VfxU32 param, VfxU32 *ret);
    
    // This function is called whenever there is a change in parent menu bounds.
    // <group DOM_MenuPopup_VcpMenuPopupItem_Slot>
    void onMenuBoundsChange(VfxFrame *frm, const VfxRect &rect);    

protected:
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>    
    VfxWString m_text;
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxU32 m_flag;    
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxId m_id;
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxTextFrame *m_textFrame;
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxFrame *m_icon;
private:
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxFrame *m_separator;
};

/***************************************************************************** 
* Class VcpMenuPopupItemType2
* This class defines a single item in the menu.
* VcpMneuPopup automatically creates this class's object when it adds new menu items
* This class can be inherited to have customized menu items.
* If no custoimization is needed, this class API is not directly accessed by client applications
*****************************************************************************/
class VcpMenuPopupItemType2 : public VcpMenuPopupItem
{
public:
	// Default constructor
	// <group DOM_MenuPopup_VcpMenuPopupItem_Constructor/Destructor>
	VcpMenuPopupItemType2();    

protected:
	// <group DOM_MenuPopup_VcpMenuPopupItem_Override>
	virtual void onInit();

public:
	// <group DOM_MenuPopup_VcpMenuPopupItem_Override>
	virtual void setBounds(const VfxRect &value);	 
	
	// <group DOM_MenuPopup_VcpMenuPopupItem_Override>
	virtual void onUpdate();

public:
	// <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	void setHintText(VfxResId resId);

	// <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	void setHintText(const VfxWChar *mem);

	// <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	void setHintText(const VfxWString &hint);
	
	// <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	const VfxWString &getHintText();
		
    // <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	void setHintTextPlacement(VcpMenuPopupItemType2HintPlacement placement);
	
	// <group DOM_MenuPopup_VcpMenuPopupItem_Property>
	VcpMenuPopupItemType2HintPlacement getHintTextPlacement() const;
		

protected:
    // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VfxTextFrame *m_hintTextFrame;

     // <group DOM_MenuPopup_VcpMenuPopupItem_Implementation>
    VcpMenuPopupItemType2HintPlacement m_hintPlacement;

private:
     VfxWString m_hintText;
};

// DOM-NOT_FOR_SDK-BEGIN

/*****************************************************************************
* Class VcpMenuPopupBaseMenu
* This is the menu part of the Menu popup.
* VcpMenuPopup creates a single instance of this class to use as its menu.
* If no custoimization is needed, this class API is not directly accessed by client applications
*****************************************************************************/
class VcpMenuPopupBaseMenu : public VcpBaseMenu
{
public:
    // Default constructor
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Constructor/Destructor>
    VcpMenuPopupBaseMenu() {}

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Method>
    void update()
    {
        // clear layout cache
        m_cache.clear();
        updateLayout();
    }
    
    // Get the cell frame pointer.
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Method>
    VfxFrame *getCellByPos(VfxS32 pos);

    void insertItemAsChildFrame(VfxFrame *itemFrm);
protected:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onInit();

    // Create the base menu layout.
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual VcpBaseMenuLayout* createLayout()
    {
        VFX_OBJ_CREATE_EX(m_layout, VcpMenuPopupBaseMenuLayout, this, (this));
        return m_layout;
    }        

    // Create a single cell object
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index        
        )
    {
        VFX_UNUSED(group);
        return getCellByPos(pos);
    }


    // A handler that is called when menu is going to close a cell
    // Create the base menu layout.
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
        )
    {
        VFX_UNUSED(group);
        VFX_UNUSED(pos);
        VFX_UNUSED(cellFrame);
        // VFX_OBJ_CLOSE(cellFrame);
    }

    // A handler that is called when menu is going to update a cell's attributes        
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
        );

    // A handler that is called when a cell receives a touch event
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
        );

    // A handler that is called when menu changes focused cell        
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
        );

    // A handler that is called when menu is beign dragged for scrolling        
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Override>
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

public:
    // menu event signal
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Event>
    VfxSignal3 <VcpMenuPopupBaseMenu*,      // This menu object pointer (this)
        VcpMenuPopupEventEnum, // The current event type
        VcpMenuPopupItem*>      // The target cell
        m_signalMenu;

private:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void expandGroup(VfxFrame *groupParent);
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void foldGroup(VfxFrame *groupParent);
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void setRadioGroupExclusive(VfxFrame *checkedGroupItem);
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void onSubGroupAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void stopSubGroupAnim();

private:
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>    
    VcpMenuPopupBaseMenuLayout *m_layout;

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    void tapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
        );

    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    VfxFrame *m_subGroupClip;
    // <group DOM_MenuPopup_VcpMenuPopupBaseMenu_Implementation>
    VfxS32Timeline *m_subGroupClipTl;
};

// DOM-NOT_FOR_SDK-END

/*****************************************************************************
* Class VcpMenuPopup
* Main Menu Popup class.
* It displays in the center of the screen, and it's size is automatically set, depending on number of items.
* Create its instance as a popup, and then use its API to add menu items
* This popup is supposed to be used as a context menu.
* There is no maximum limit on number of items. If there are large number of items, the menu is scrollable.
* Note: It does not support disabled items. It expects that only the active menu items would be created.* 
*****************************************************************************/
class VcpMenuPopup : public VfxBasePopup
{
public:    
    // Lists all the dimensional constants for Menu Popup
    // <group DOM_MenuPopup_VcpMenuPopup_Enum>
    enum dimensions 
    {
        TITLE_FONT_SIZE = VCP_MENU_POPUP_TITLE_FONT_SIZE,
        MENU_FONT_SIZE = VCP_MENU_POPUP_MENU_ITEM_FONT_SIZE,
#if defined(__MMI_MAINLCD_320X480__)
        MENU_TITLE_HEIGHT = 25,
        CELL_HEIGHT = 51,

        MENU_MARGIN_LEFT = 4,
        MENU_MARGIN_TOP = 0,
        MENU_MARGIN_RIGHT = 4,
        MENU_MARGIN_BOTTOM = 15,

        MAX_VISIBLE_CELLS_POTRAIT = 6,
    MAX_VISIBLE_CELLS_LANDSCAPE = 3,
#elif defined(__MMI_MAINLCD_480X800__)
        MENU_TITLE_HEIGHT = 45,
        CELL_HEIGHT = 86,

        MENU_MARGIN_LEFT = 7,
        MENU_MARGIN_TOP = 0,
        MENU_MARGIN_RIGHT = 7,
        MENU_MARGIN_BOTTOM = 35,

        MAX_VISIBLE_CELLS_POTRAIT = 6,
        MAX_VISIBLE_CELLS_LANDSCAPE = 3,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        MENU_TITLE_HEIGHT = 20,
        CELL_HEIGHT = 45,

        MENU_MARGIN_LEFT = 3,
        MENU_MARGIN_TOP = 0,
        MENU_MARGIN_RIGHT = 3,
        MENU_MARGIN_BOTTOM = 13,

        MAX_VISIBLE_CELLS_POTRAIT = 6,
    MAX_VISIBLE_CELLS_LANDSCAPE = 3,
#else
        MENU_TITLE_HEIGHT = 25,
        CELL_HEIGHT = 51,

        MENU_MARGIN_LEFT = 4,
        MENU_MARGIN_TOP = 0,
        MENU_MARGIN_RIGHT = 4,
        MENU_MARGIN_BOTTOM = 15,

        MAX_VISIBLE_CELLS_POTRAIT = 6,
    MAX_VISIBLE_CELLS_LANDSCAPE = 3,
#endif

    TITLE_MARGIN_LEFT = VCP_MENU_POPUP_LEFT_CONTENT_MARGIN + MENU_MARGIN_LEFT,
    TITLE_MARGIN_TOP = 0,
    TITLE_MARGIN_RIGHT = VCP_MENU_POPUP_RIGHT_CONTENT_MARGIN + MENU_MARGIN_RIGHT,
    TITLE_MARGIN_BOTTOM = 0,

    };

    // <group DOM_MenuPopup_VcpMenuPopup_Constructor/Destructor>
    // Default constructor
    VcpMenuPopup();

    // Override
protected:
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onInit();
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onPenInputOnOutside(VfxPenEvent &event);
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onEnter();
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onExit();
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onLeaveStack();

public:
    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onUpdate();

    // Sets the title string
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    virtual void setTitle(
        VfxResId resId // [IN] title string
        );

    
    // Sets the title string
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    virtual void setTitle(
        const VfxWChar *mem // [IN] title string
        );

    // Sets the title string
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    virtual void setTitle(
        const VfxWString &title // [IN] title string
        );

    // Gets the title string
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    VfxWString getTitle() const
    {
        return m_titleText;
    }        

    // Sets the auto close flag
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    void setIsAutoClose(
        VfxBool isAutoClose     // [IN] auto close flagf
        )
    {
        m_isAutoClose = isAutoClose;
    }

    // Gets the auto close flag
    // RETURNS: auto close flag
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    VfxBool getIsAutoClose() const
    {
        return m_isAutoClose;
    }

    // Sets the auto cancel flag to enable/disable auto closing
    // menu when clicking outside the menu
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    void setIsAutoCancel(
        VfxBool isAutoCancel    // [IN] auto cancel flag
        )
    {
        m_isAutoCancel = isAutoCancel;
    }

    // Gets the auto cancel flag
    // RETURNS: auto cancel flag
    // <group DOM_MenuPopup_VcpMenuPopup_Property>
    VfxBool getIsAutoCancel() const
    {
        return m_isAutoCancel;
    }

    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, VfxResId resId, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);
    
    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, const VfxWChar *mem, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, VfxWString itemText, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);
    
    // Inserts an item after the specified item    
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, VfxResId resId, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item after the specified item    
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, const VfxWChar *mem, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item after the specified item    
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, VfxWString itemText, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, VfxResId resId, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, const VfxWChar *mem, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item at the end
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *addItem(VfxId id, VfxWString itemText, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);
    
    // Inserts an item after the specified item	
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, VfxResId resId, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item after the specified item	
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, const VfxWChar *mem, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Inserts an item after the specified item	
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *insertItem(VfxId id, VfxId afterId, VfxWString itemText, const VfxImageSrc &img, VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1);

    // Removes an item
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    void removeItem(
        VcpMenuPopupItem* item     // [IN] menu item object
        );

    // Get item pointer for given ID
    // <group DOM_MenuPopup_VcpMenuPopup_Method>
    VcpMenuPopupItem *getItemById(VfxId);

    // <group DOM_MenuPopup_VcpMenuPopup_Override>
    virtual void onRotate(const VfxScreenRotateParam &param);

    // Inserts an item after the specified item
    void insertItem(
        VcpMenuPopupItem* parent,          // [IN] parent menu item, NULL if the item to be inserted in the first level
        VcpMenuPopupItem* insertAfterItem, // [IN] insert after this item 
        VcpMenuPopupItem* item             // [IN] item to be inserted
        );
	

    // Event 
public:
    // Menu event signal
    // <group DOM_MenuPopup_VcpMenuPopup_Event>
    VfxSignal3 <VcpMenuPopup*,     // Sender MenuPopup object
        VcpMenuPopupEventEnum,     // Event type
        VcpMenuPopupItem*>  // Target menu item pointer
       m_signalMenuCallback;

protected:
    // title background image frame
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxFrame *m_titleBg;
    // title text frame
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxTextFrame *m_titleFrame;


    // title string
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxWString m_titleText;
    // menu layout
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VcpMenuPopupBaseMenuLayout *m_layout;
    // menu
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VcpMenuPopupBaseMenu *m_menu;

    // background image
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxFrame *m_background;

    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxU32 m_width;
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    VfxU32 m_maxVisibleCells;

    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    virtual void onSize();    
    // <group DOM_MenuPopup_VcpMenuPopup_Implementation>
    void onMenuItemEvent(VcpMenuPopupBaseMenu *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    
// DOM-NOT_FOR_SDK-BEGIN

// =============================    
// Deprecated part below
// =============================

private: // Deprecated part
    // auto close flag
    VfxBool m_isAutoClose;
    // auto cancel flag
    VfxBool m_isAutoCancel;    
    // title close button
    VcpButton *m_closeButton;

    VfxBool m_showCancelButton;

public:
    // Shows the menu popup
    void showMenu() // Deprecated
    {        
        show(VFX_TRUE);
    }

    // Creates a text menu item
    // RETURNS: created menu item    
    // Deprecated 
    VcpMenuPopupItem* createMenuItem(
        VfxId itemId,           // [IN] item id
        VfxResId resId,    // [IN] item iext
        VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1
        );
    
    // Creates a text menu item
    // RETURNS: created menu item    
    // Deprecated 
    VcpMenuPopupItem* createMenuItem(
        VfxId itemId,           // [IN] item id
        const VfxWChar *mem,    // [IN] item iext
        VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1
        );
    
    // Creates a text menu item
    // RETURNS: created menu item    
    // Deprecated 
    VcpMenuPopupItem* createMenuItem(
        VfxId itemId,           // [IN] item id
        VfxWString itemText,    // [IN] item iext
        VcpMenuPopupItemType itemType = VCP_MENU_POPUP_ITEM_TYPE_1
        );

private:


    // Closes an item
    // Deprecated
    void closeItem(
        VcpMenuPopupItem* item     // [IN] menu item object
        );

// DOM-NOT_FOR_SDK-END    

};


#endif
#endif /* __VCP_MENU_POPUP_H__ */


