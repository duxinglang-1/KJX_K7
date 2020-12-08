/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_key_widget_menu.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the widget menu.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_KEYLAUNCHER_WIDGET_MENU_H
#define VAPP_KEYLAUNCHER_WIDGET_MENU_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vcp_wheel_menu.h"

#include "vapp_widget.h"
#include "vapp_widget_primitive.h"


class VappKeyLauncherDirector;

/***************************************************************************** 
 * Home screen UI componet: widget menu
 *****************************************************************************/

class VappKeyLauncherWidgetMenu : public VcpWheelMenu
{
//	VFX_DECLARE_CLASS(VappKeyLauncherWidgetMenu);
	
// Constructor / Destructor
public:
    // Default constructor
    VappKeyLauncherWidgetMenu();

// Override
protected:
    // On init
    virtual void onInit();

	// On deinit
	virtual void onDeinit();

	// On preview pen input
	virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

	// On pen input
	virtual VfxBool onPenInput(VfxPenEvent &event);

	// On Key input
	virtual VfxBool onKeyInput(VfxKeyEvent & event);

public:
	// Set frame visibility.
	virtual void setHidden(VfxBool value);

// Overridable from VcpWheelMenu
protected:
	// Return the count of menu items.
    virtual VfxS32 getCount();

    // Return the visible menu item count which behind the focus item.
    virtual VfxS32 getBehindCount();

    // Return the visible menu item count which ahead the focus item.
    virtual VfxS32 getAheadCount();

    // Return the frame effect callback.
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

    // Create a cell object.
    // RETURNS: a cell object 
    virtual VfxFrame* createCell(
        VfxS32 cell,              // [IN] The cell index
        VfxS32 subcell
    );
    
    // Notify to update a cell's position.
    virtual void onUpdateCell(
        VfxS32 cell,                // [IN] The cell index in the group
        VfxS32 subcell,             // [IN] The sub cell index in the group
        VfxFrame* cellFrame         // [IN] The cell object
    );

    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 cell,                // [IN] The cell index in the group
        VfxS32 subcell,             // [IN] The sub cell index in the group
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

    // Notify when the user start drag the menu except enter/leave state
    virtual void onDragStart();

    // Notify when the user stop drag the menu except enter/leave state
    virtual void onDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    );

    // Notify when the menu is dragged except enter/leave state
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset);

	    // Notify when the menu is tapped and cell does not move.
    virtual void onTap(VfxPoint pt);
            
    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VfxS32 focusItem,               // [IN] The focus item index now
        VfxS32 preFocusItem             // [IN] The previous focus item index
    );

	// Notify when enter/leave state change finished 
	virtual void onStateChangeFinished(
        VcpWheelMenuState finishedstate // [IN] finished state.
    );

public:
	// Effect callback for wheel menu to call
	static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );

    enum MenuPathData
    {
    #if defined(__MMI_MAINLCD_320X480__)
		ELLIPSE_SEMIMAJOR = 130,
		ELLIPSE_SEMIMINOR = 84,
		ELLIPSE_SHIFT_ANGLE = 40,
		ELLIPSE_CENTER_X = 159,
		ELLIPSE_CENTER_Y = 315, //295,
		CIRCUIT_CENTER_X = ELLIPSE_CENTER_X,
		CIRCUIT_CENTER_Y = 259, //239,
		CIRCUIT_RADIUS = ELLIPSE_CENTER_Y - CIRCUIT_CENTER_Y + ELLIPSE_SEMIMINOR,
		CIRCUIT_SHIFT_ANGLE = 30,

		WIDGET_FOCUSED_POINT_MID_X = 159,
		WIDGET_FOCUSED_POINT_MID_Y = 199 - 5,
		WIDGET_AREA_REAL_HEIGHT    = 320, // on global coordinate
		
    #elif defined(__MMI_MAINLCD_240X400__)
		ELLIPSE_SEMIMAJOR = 101-5,
		ELLIPSE_SEMIMINOR = 62,
		ELLIPSE_SHIFT_ANGLE = 47,
		ELLIPSE_CENTER_X = 120,
		ELLIPSE_CENTER_Y = 276,
		CIRCUIT_CENTER_X = ELLIPSE_CENTER_X,
		CIRCUIT_CENTER_Y = 234,
		CIRCUIT_RADIUS = ELLIPSE_CENTER_Y - CIRCUIT_CENTER_Y + ELLIPSE_SEMIMINOR,
		CIRCUIT_SHIFT_ANGLE = 30,

		WIDGET_FOCUSED_POINT_MID_X = 120,
		WIDGET_FOCUSED_POINT_MID_Y = 162,
		WIDGET_AREA_REAL_HEIGHT    = 280,
		
    #elif defined(__MMI_MAINLCD_240X320__)
		ELLIPSE_SEMIMAJOR = 101-5,
		ELLIPSE_SEMIMINOR = 62,
		ELLIPSE_SHIFT_ANGLE = 47,
		ELLIPSE_CENTER_X = 120,
		ELLIPSE_CENTER_Y = 197 + 8,
		CIRCUIT_CENTER_X = ELLIPSE_CENTER_X,
		CIRCUIT_CENTER_Y = 155 + 8,
		CIRCUIT_RADIUS = ELLIPSE_CENTER_Y - CIRCUIT_CENTER_Y + ELLIPSE_SEMIMINOR,
		CIRCUIT_SHIFT_ANGLE = 30,

		WIDGET_FOCUSED_POINT_MID_X = 120,
		WIDGET_FOCUSED_POINT_MID_Y = 110 + 10,
		WIDGET_AREA_REAL_HEIGHT    = 240,

	#else // defined(__MMI_MAINLCD_320X240__)
		ELLIPSE_SEMIMAJOR = 254,
		ELLIPSE_SEMIMINOR = 138,
		ELLIPSE_SHIFT_ANGLE = 13,
		ELLIPSE_CENTER_X = 160,
		ELLIPSE_CENTER_Y = 68,
		CIRCUIT_CENTER_X = ELLIPSE_CENTER_X,
		CIRCUIT_CENTER_Y = 160,
		CIRCUIT_RADIUS = ELLIPSE_CENTER_Y - CIRCUIT_CENTER_Y + ELLIPSE_SEMIMINOR,
		CIRCUIT_SHIFT_ANGLE = 30,

		WIDGET_FOCUSED_POINT_MID_X = 160,
		WIDGET_FOCUSED_POINT_MID_Y = 92,
		WIDGET_AREA_REAL_HEIGHT    = 170, // on global coordinate
		
    #endif
    };

// Enum
public:
	enum FlyType
	{
		FLY_IN,  // Widget menu fly in screen when enter widget page, if need
		FLY_OUT, // Widget menu fly out screen when exit widget page, if need
	};

	enum FlyState
	{
		FLY_START,  // Start to fly in or fly out
		FLY_FINISH, // Fly in or fly out finish
	};

	enum DataValue
	{
		FOCUS_WIDGET_TIME = 600, // 600 ms to focus one widget when switch widget menu
		WAlLPAPER_SUSPEND_KEY_TIME = 1000, // 1000 ms to supend live wallpaper when have LNK/RNK
		WAlLPAPER_SUSPEND_PEN_TIME = 1000, // 1000 ms to supend live wallpaper when have pen down/move/up/abort
		WAlLPAPER_SUSPEND_PEN_DOWN_TIME = 600000, // think user max press pen 10 minutes
		WAlLPAPER_SUSPEND_PEN_UP_TIME = 1000, // think max animation will cost 1 second, then resume wallpaper
	};

// Method
public:
	// 
	void show();

	// On menu enter/exit state, All widget icon menu fly in to its owner position or  fly out to disappear
	void fly(
		FlyType ft     // [IN] fly in or fly out
	);

private:
	// Create Widget Menu
	void createWidgetData();

	// Release Widget Menu
	void releaseWidgetData();
	
	// Switch widget menu to highlight pervious or next widget icon
	// switch highlight to next widget icon if toNext is VFX_TRUE
	// void switchMenu(VfxBool toNext);

	// Timer callback, in case user press key quickly, so we need wait a moment to focus one widget
	void onFocusOneWidget(VfxTimer *timer);

	//
	void notifyUpdated();

	// Set total widget menu count in onInit.
	void setMenuCount();

// Signal
public:
	// Signal about Widget menu fly in/out, start/finsh
	VfxSignal2 <FlyType, FlyState>    m_signalFly;

private:
	// Parent point, we need use its delayWallpaper to tune performance
	VappKeyLauncherDirector *m_parent;
	
	// Current highlight menu index in widget menu
	static VfxS32  s_focusedIdx;

	// Timer to focus one widget after switch widget menu.
    VfxTimer *m_timerFocusOneWidget;

	// All widget Id list which get from widgetkit
	VappWidgetId ** m_widgetIds;

	// Total count of widget
	VfxS32 m_widgetCount;

//
// This block implements the widget menu.
//

// Variable
public:	
	// Current widget is showing with full view in widget page.
	VappWidget * m_focusedWidget;

// Implementation
private:
	// This function is called when widget menu finished switch and focused one widget.
	void onWidgetFocused(
		VappWidgetId * focusedId        //[IN]  which widget is focused
	);

	// This funciton release focused widget
	void releaseWidgetFocused();

private:
	// If capture pen move when pen move left/right in Widget focused view
	VfxBool m_capture;

};

#endif /* __MMI_VUI_LAUNCHER_KEY__ */
#endif /* VAPP_KEYLAUNCHER_WIDGET_MENU_H */
