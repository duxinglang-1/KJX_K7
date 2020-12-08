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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_launcher_key_widget_menu.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget menu.
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

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_context.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_auto_animate.h"
#include "vcp_wheel_menu.h"
#include "vapp_widget_kit.h"
#include "vapp_widget_system.h"

#include "vapp_launcher_key_gprot.h"
#include "vapp_launcher_key_def.h"
#include "vapp_launcher_key_director.h"
#include "vapp_launcher_key_widget_menu.h"
#include "vapp_launcher_key_primitive.h"
#include "mmi_rp_vapp_launcher_key_def.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"	
#include "lcd_sw_inc.h"
#include "Unicodexdcl.h"
#include "PhnsetWidgetMgrGprot.h"
}
#endif /* __cplusplus */


/*****************************************************************************
 * Adapter for Pluto setting to call Venus Widget Kit function
 *****************************************************************************/
extern "C" S32 vapp_keylauncher_get_widget_total_num(void)
{
	// Init Widget Module, it will be executed only once
	vapp_widget_sys_init();

	VappWidgetKitControl kitControl(VFX_TRUE);
	kitControl.forbit(VAPP_WIDGET_SRC_SHORTCUT);

	VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

	return widgetKit->getTotalNum(&kitControl);
}


extern "C" void vapp_keylauncher_get_widget_ids(S32 *ids)
{
	// Init Widget Module, it will be executed only once
	vapp_widget_sys_init();

	S32 totalNum = vapp_keylauncher_get_widget_total_num();
	
    VappWidgetKitControl kitControl(VFX_TRUE);
    kitControl.forbit(VAPP_WIDGET_SRC_SHORTCUT);

	VappWidgetId ** widgetIds;
    widgetIds = VappWidgetId::newArray(totalNum, VFX_SYS_GLOBAL_CONTEXT);
	
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    widgetKit->getAllId(widgetIds, totalNum, &kitControl);

	for (VfxS32 i = 0; i < totalNum; i++)
    {
		ids[i] = widgetIds[i]->getIntType();
    }

	VappWidgetId::deleteArray(widgetIds, totalNum);	
}


extern "C" void vapp_keylauncher_get_widget_name_list_by_ids(
					mmi_vapp_widget_name_struct * name_array,
					S32 *ids,
					S32 count)
{
	// Init Widget Module, it will be executed only once
	vapp_widget_sys_init();

	S32 totalNum = vapp_keylauncher_get_widget_total_num();
	
    VappWidgetKitControl kitControl(VFX_TRUE);
    kitControl.forbit(VAPP_WIDGET_SRC_SHORTCUT);

	VappWidgetId ** widgetIds;
    widgetIds = VappWidgetId::newArray(totalNum, VFX_SYS_GLOBAL_CONTEXT);
	
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    widgetKit->getAllId(widgetIds, totalNum, &kitControl);

	for (VfxS32 i = 0; i < count/*sizeof(ids)/sizeof(S32)*/; i++)
    {
		for (VfxS32 j = 0; j < totalNum; j++)
		{
			if (widgetIds[j]->getIntType() == ids[i])
			{
				widgetKit->getName(*(widgetIds[j]), (VfxWChar *)(name_array[i]), MMI_VAPP_WIDGET_NAME_MAX_LEN);
				break;
			}
		}
    }

	VappWidgetId::deleteArray(widgetIds, totalNum);	
}



/***************************************************************************** 
 * Home screen UI componet: widget menu
 *****************************************************************************/
//#define __WIDGET_MENU_TEST__


//VFX_IMPLEMENT_CLASS("VappKeyLauncherWidgetMenu", VappKeyLauncherWidgetMenu, VcpWheelMenu);

VfxS32 VappKeyLauncherWidgetMenu::s_focusedIdx = 0;


VappKeyLauncherWidgetMenu::VappKeyLauncherWidgetMenu() :
	m_parent(NULL),
	m_timerFocusOneWidget(NULL),
	m_widgetIds(NULL),
	m_widgetCount(0),	
	m_focusedWidget(NULL),
	m_capture(VFX_FALSE)
{
}


void VappKeyLauncherWidgetMenu::onInit()
{
	VcpWheelMenu::onInit();

	m_parent = (VappKeyLauncherDirector *)getParent();

	setIsZSortChild(VFX_TRUE);

	// Set total widget menu count
	setMenuCount();
#ifdef __WIDGET_MENU_TEST__	
	m_widgetCount = 20;
#else
	// Set Widget Ids and Alloc Widget Icons
	createWidgetData();
#endif
}


void VappKeyLauncherWidgetMenu::onDeinit()
{
	releaseWidgetData();

	releaseWidgetFocused();
	
	VcpWheelMenu::onDeinit();
}


VfxBool VappKeyLauncherWidgetMenu::onPreviewPenInput(VfxPenEvent &event)
{
	//
	// For performance issue
	// We should suspend wallpaper when has pen action
	//	
	if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		m_parent->delayWallpaper(WAlLPAPER_SUSPEND_PEN_DOWN_TIME); // think user max press 10 minutes, move is in this range
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_UP || event.type == VFX_PEN_EVENT_TYPE_ABORT)
	{
		m_parent->delayWallpaper(WAlLPAPER_SUSPEND_PEN_UP_TIME); // think max animation will cost 1 second, then resume wallpaper
	}

	//
	// When widget page is active, and widget focused is display, when pen move left/right,
	// We should capture it to switch widget to previous/next.
	//
	if (event.type == VFX_PEN_EVENT_TYPE_MOVE && m_capture == VFX_FALSE)
	{
		VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_ON_PREVIEW_PEN_INPUT,
                           'M', event.pos.x, event.pos.y));
		
		if (m_focusedWidget != NULL &&
			m_focusedWidget->getHidden() == VFX_FALSE &&
			event.pos.y < WIDGET_AREA_REAL_HEIGHT &&
			event.downPos.y < WIDGET_AREA_REAL_HEIGHT)
			//m_focusedWidget->containPoint(event.getRelPos(m_focusedWidget)) == VFX_TRUE &&
			//m_focusedWidget->containPoint(event.getRelDownPos(m_focusedWidget)) == VFX_TRUE)
		{
			VfxS32   x_moved_distance;
			VfxS32   y_moved_distance;	               
			x_moved_distance = (event.pos.x - event.downPos.x);
			y_moved_distance = VFX_ABS(event.pos.y - event.downPos.y);

			if (VFX_ABS(x_moved_distance) > y_moved_distance &&
				VFX_ABS(x_moved_distance) > 20)
			{
				// We need swipe to next or previous Widget
				m_capture = VFX_TRUE;
				VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_CAPTURE));
				
				if(capture())
				{
					VfxS32 inc = x_moved_distance > 0 ? 1 : -1;
					setFocus(getFocus() - inc);
					return VFX_TRUE;
				}
				else
				{
					m_capture = VFX_FALSE;
					return VFX_FALSE;
				}
			}
		}
	}
	else if (m_capture == VFX_TRUE && event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_ON_PREVIEW_PEN_INPUT,
                           'U', event.pos.x, event.pos.y));
		
		m_capture = VFX_FALSE;
		return VFX_TRUE;
	}
	
    return VcpWheelMenu::onPreviewPenInput(event);
}


VfxBool VappKeyLauncherWidgetMenu::onPenInput(VfxPenEvent &event)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_ON_PEN_INPUT,
                           event.type, event.pos.x, event.pos.y, m_capture));
	
	if (m_capture == VFX_TRUE)
	{
		return VFX_TRUE;
	}
	return VcpWheelMenu::onPenInput(event);
}

void VappKeyLauncherWidgetMenu::setMenuCount()
{
	m_widgetCount = mmi_phnset_widget_get_widget_num();
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_SET_COUNT, m_widgetCount));

	if (m_widgetCount < 0 && s_focusedIdx >= m_widgetCount)
	{
		s_focusedIdx = m_widgetCount - 1; // Indicate User reduce widget count from Setting.
	}
}


void VappKeyLauncherWidgetMenu::createWidgetData()
{
    if (!m_timerFocusOneWidget)
    {
        VFX_OBJ_CREATE(m_timerFocusOneWidget, VfxTimer, this);
		m_timerFocusOneWidget->setStartDelay(FOCUS_WIDGET_TIME);
        m_timerFocusOneWidget->m_signalTick.connect(this, &VappKeyLauncherWidgetMenu::onFocusOneWidget);
    }
	
    if (m_widgetCount <= 0)
    {
		return;
    }

    //
    // Get all widget ID from the widget kit.
    //
	VappWidgetKitControl kitControl(VFX_TRUE);
    kitControl.forbit(VAPP_WIDGET_SRC_SHORTCUT);
	
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
	VfxS32 totalWidgetCount = widgetKit->getTotalNum(&kitControl);
    VappWidgetId ** totalWidgetIds = VappWidgetId::newArray(totalWidgetCount, this);	
    widgetKit->getAllId(totalWidgetIds, totalWidgetCount, &kitControl);
	
    VFX_ASSERT(m_widgetIds == NULL);
	m_widgetIds = VappWidgetId::newArray(m_widgetCount, this);

	S32 ids[15] = {0};
	mmi_phnset_widget_get_widget_ids_list(ids);
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_CREATE_WIDGET_DATA,
                           ids[0], ids[1], ids[2], ids[3], ids[4], 
                           ids[5], ids[6], ids[7], ids[8], ids[9]));

	VfxS32 cnt = 0;
	for (VfxS32 i = 0; i < m_widgetCount; i++)
    {
		for (VfxS32 j = 0; j < totalWidgetCount; j++)
		{
			if (totalWidgetIds[j]->getIntType() == ids[i])
			{
				*(m_widgetIds[cnt++]) = *(totalWidgetIds[j]);
				break;
			}
		}
    }

	VFX_EXT_ASSERT(m_widgetCount == cnt, m_widgetCount, cnt, 0);
	VappWidgetId::deleteArray(totalWidgetIds, totalWidgetCount);
}


void VappKeyLauncherWidgetMenu::releaseWidgetData()
{
	VFX_OBJ_CLOSE(m_timerFocusOneWidget);

	if (m_widgetIds)
	{
		VappWidgetId::deleteArray(m_widgetIds, m_widgetCount);
	}
}


VfxBool VappKeyLauncherWidgetMenu::onKeyInput(VfxKeyEvent & event)
{
	if (m_state != VCP_WHEEL_MENU_NORMAL_STATE)
		return VcpWheelMenu::onKeyInput(event);

	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_ON_KEY_INPUT,
							event.keyCode, event.type, getFocus()));

	if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
         event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
		// Switch highlight to right widget icon
		m_parent->delayWallpaper(WAlLPAPER_SUSPEND_KEY_TIME); // think switch focus will cost 1 second, then resume wallpaper
        setFocus(getFocus() + 1);
		
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
             (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
              event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
		// Switch highlight to left widget icon
		m_parent->delayWallpaper(WAlLPAPER_SUSPEND_KEY_TIME); // think switch focus will cost 1 second, then resume wallpaper
        setFocus(getFocus() - 1);
		
        return VFX_TRUE;
    }
	else if ((event.keyCode == VFX_KEY_CODE_ARROW_RIGHT ||
			  event.keyCode == VFX_KEY_CODE_ARROW_LEFT) &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		// Mean to Don't rount key to parent
		return VFX_TRUE;
	}

	return VcpWheelMenu::onKeyInput(event);
}



void VappKeyLauncherWidgetMenu::setHidden(VfxBool value)
{
	//
	// When set Hidden widget menu, we should
	// 1, set hidden widget menu and widget view
	// 2, set unhittable widget menu and widget view, don't let them receive Pen event
	// 3, set unfocused widget menu and widget view, don't let them receive Key event
	//
	VcpWheelMenu::setHidden(value);	
	setIsUnhittable(value);
	setFocused(value != VFX_TRUE); // for receive Key event

	if (m_focusedWidget)
	{
		m_focusedWidget->setHidden(value);
		m_focusedWidget->setIsUnhittable(value);
		m_focusedWidget->setFocused(value != VFX_TRUE); // for receive Key event
	}
	// We still hidden the focused widget when fly in, then Unhidden it after fly in done
}

VfxS32 VappKeyLauncherWidgetMenu::getCount() 
{
	return m_widgetCount;
}


VfxS32 VappKeyLauncherWidgetMenu::getBehindCount()
{
    return m_widgetCount;
}


VfxS32 VappKeyLauncherWidgetMenu::getAheadCount()
{
    return m_widgetCount;
}

VcpWheelMenuFrameEffectCBFuncPtr VappKeyLauncherWidgetMenu::getFrameEffectCB()
{
	return &VappKeyLauncherWidgetMenu::myFrameEffectCB;
}


vrt_render_dirty_type_enum VappKeyLauncherWidgetMenu::myFrameEffectCB(
    VfxS32                              cell,           /* [IN] the cell index */
    VfxS32                              subCell,        /* [IN] the sub cell index */
    VfxFloat                            cellRelPos,     /* [IN] the cell position */
    vrt_frame_visual_property_struct    *target_frame,  /* [IN] the cell frame */
    VfxFloat                            fPos,           /* [IN] animating index value */
    VfxS32                              focus,          /* the focus value of the menu */
    VfxRect                             viewBounds,     /* the menu bounds */
    void                                *userData,      /* user data */
    VfxU32                              userDataSize,   /* user data size */
    VcpWheelMenuState                   state,          /* [IN] the state of Menu */
    VfxFloat                            level           /* [IN] the level of state */
    )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(viewBounds);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);

#if defined(__MMI_MAINLCD_320X240__)
	
	VfxFloat offset = cellRelPos;
	
	if (state == VCP_WHEEL_MENU_ENTER_STATE)
	{
		offset = offset + 6 * (1 - level); // from right to left, total run getCount()
	}
	else if (state == VCP_WHEEL_MENU_LEAVE_STATE)
	{
		offset = offset - 6 * level;  // from right to left, total run getCount()
	}

	VfxFloat index_offset = offset;
	// calculate the pos by ellipse parametric equation.
	target_frame->pos.x = VfxS32(ELLIPSE_CENTER_X + vfxSin(VFX_DEG_TO_RAD(index_offset * ELLIPSE_SHIFT_ANGLE)) * ELLIPSE_SEMIMAJOR);
	target_frame->pos.y = VfxS32(ELLIPSE_CENTER_Y + vfxCos(VFX_DEG_TO_RAD(index_offset * ELLIPSE_SHIFT_ANGLE)) * ELLIPSE_SEMIMINOR);		

	//scale the item
	target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
	target_frame->transform.data.affine.sx = (8.0f - VFX_ABS(offset)) / 8.0f; //(12 - offset) / 11;
	target_frame->transform.data.affine.sy = target_frame->transform.data.affine.sx;
	target_frame->transform.data.affine.tx = 0; //target_frame->pos.x / 2;
	target_frame->transform.data.affine.ty = 0; //target_frame->pos.y / 2;

	// set opacity
	target_frame->opacity = target_frame->transform.data.affine.sx;
	if (target_frame->opacity < 0)// || offset < ( - 3))
	{
		target_frame->opacity = 0;
	}
#else /* defined(__MMI_MAINLCD_320X240__) */
	VfxFloat offset = cellRelPos + 1; // 1 is highlight index, in the left-bottom corner of ellipise
	
	if (state == VCP_WHEEL_MENU_ENTER_STATE)
	{
		offset = offset + 6 * (1 - level); // from focus+12 index to animation, 4 is ellipse index, 8 is circuit index
	}
	else if (state == VCP_WHEEL_MENU_LEAVE_STATE)
	{
		offset = offset - 5 * level; // after move 4, current menu cell frame will disappear
	}

	// Compute real postion of current menu cell frame
	if (offset >= (2)) /* will follow circuit, 90/ELLIPSE_SHIFT_ANGLE = 2 */
	{
		VfxFloat index_offset = offset	- 2;
		target_frame->pos.x = VfxS32(CIRCUIT_CENTER_X + vfxSin(VFX_DEG_TO_RAD(index_offset * CIRCUIT_SHIFT_ANGLE)) * CIRCUIT_RADIUS);
		target_frame->pos.y = VfxS32(CIRCUIT_CENTER_Y + vfxCos(VFX_DEG_TO_RAD(index_offset * CIRCUIT_SHIFT_ANGLE)) * CIRCUIT_RADIUS);
	}
	else // will follow ellipse
	{
		VfxFloat index_offset = offset + 1;
		// calculate the pos by ellipse parametric equation.
		target_frame->pos.x = VfxS32(ELLIPSE_CENTER_X - vfxCos(VFX_DEG_TO_RAD((index_offset-3) * ELLIPSE_SHIFT_ANGLE + 90)) * ELLIPSE_SEMIMAJOR);
		target_frame->pos.y = VfxS32(ELLIPSE_CENTER_Y + vfxSin(VFX_DEG_TO_RAD((index_offset-3) * ELLIPSE_SHIFT_ANGLE + 90)) * ELLIPSE_SEMIMINOR);		
	}

	//scale the item
	target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
	if (offset >= 1)
	{
		target_frame->transform.data.affine.sx = (9.0f - offset) / 8.0f; //(12 - offset) / 11;
	}
	else
	{
		target_frame->transform.data.affine.sx = (5.0f + offset) / 6.0f; //(3 + offset) / 4;
	}
	target_frame->transform.data.affine.sy = target_frame->transform.data.affine.sx;
	target_frame->transform.data.affine.tx = 0; //target_frame->pos.x / 2;
	target_frame->transform.data.affine.ty = 0; //target_frame->pos.y / 2;

	// set opacity
	target_frame->opacity = target_frame->transform.data.affine.sx;
	if (target_frame->opacity < 0)// || offset < ( - 3))
	{
		target_frame->opacity = 0;
	}
#endif /* defined(__MMI_MAINLCD_320X240__) */

	target_frame->pos_z = VFX_ABS(offset);
	
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


VfxFrame* VappKeyLauncherWidgetMenu::createCell(VfxS32 cell, VfxS32 subcell)
{
#ifdef __WIDGET_MENU_TEST__	
	VfxTextFrame *test;
	VFX_OBJ_CREATE(test, VfxTextFrame, this);
	test->setBgColor(VFX_COLOR_RED);
	test->setAutoAnimate(VFX_TRUE);
	test->setAnchor(0.5, 1.0);
	VfxWChar inputBuf[5 + 1];
    kal_wsprintf((WCHAR *)inputBuf, "%d", cell);
	
	test->setString(VFX_WSTR_MEM(inputBuf));
	return test;
#else

	VfxFrame *img;
	VFX_OBJ_CREATE(img, VfxFrame, this);
	img->setAnchor(0.5, 0.5);

	// The first child frame in Cell frame, Don't change the order
	VfxImageFrame *bg_img;
    VFX_OBJ_CREATE(bg_img, VfxImageFrame, img);
    bg_img->setResId(IMG_ID_VAPP_KEYLAUNCHER_WIDGET_N);	

	// The second child frame in Cell frame, Don't change the order
    VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
	VfxFrame *icon_img = widgetKit->createIcon(*(m_widgetIds[cell]), img);
	
	img->setSize(bg_img->getSize().width, bg_img->getSize().height);
	icon_img->setAnchor(0.5, 0.5);
	icon_img->setPos(img->getSize().width / 2, img->getSize().height / 2);
	//img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
	return img;

#endif
}


void VappKeyLauncherWidgetMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
}


void VappKeyLauncherWidgetMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
#ifdef __WIDGET_MENU_TEST__	
	VfxTextFrame *test = (VfxTextFrame *)cellFrame;
	VFX_OBJ_CLOSE(test);
#else
	VFX_OBJ_CLOSE(cellFrame);
#endif
}


void VappKeyLauncherWidgetMenu::onDragStart()
{
    VcpWheelMenu::onDragStart();
}


void VappKeyLauncherWidgetMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
#define SPEED_MOD 500.0f
    VcpWheelMenu::onDragEnd(xspeed, yspeed);

    if (xspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s  = xspeed < 0 ? -1 : 1;
        VfxFloat m  = VFX_ABS(xspeed) / SPEED_MOD;

        if (m > 3) m = 3;

        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
    }
}


void VappKeyLauncherWidgetMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpWheelMenu::onDrag(xoffset, yoffset);

	if (getCellIfPresent(0) == NULL) // current no widget in this page
		return;
	
    VfxFloat perc = getScrollIndex() - VfxFloat(xoffset) / getCellIfPresent(0)->getSize().width; // CELL_ITEM_HEIGHT;

    setScrollIndex(perc, 0);
}


void VappKeyLauncherWidgetMenu::onTap(VfxPoint pt)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_ONTAP,
                           pt.x, pt.y));
	
	// Need match SPEC, only the front icons can be tapped
	// from focused-1 to focused+2, total 4
#ifdef __MMI_MAINLCD_320X240__
	VfxS32 start = 	getFocus() - 2;
#else
	VfxS32 start = 	getFocus() - 1;	
#endif
	for (VfxS32 i = start; i <= getFocus() + 2; i++)
	{
		if (i == getFocus() || i < 0 || i >= getCount())
			continue;
		
		VfxFrame* cell = getCellIfPresent(i);
	    if (!cell)
	        continue;

	    VfxPoint pos = cell->forceGetPos();
		VfxRect bounds = cell->forceGetBounds();//getBounds();
		VfxRect rect(pos.x - (VfxS32)(cell->getAnchor().x * bounds.getWidth()), 
			pos.y - (VfxS32)(cell->getAnchor().y * bounds.getHeight()), 
			bounds.getWidth(), 
			bounds.getHeight());

	    if (rect.contains(pt))
	    {
	        setFocus(i);
			break;
	    }
	}
}


void VappKeyLauncherWidgetMenu::onStateChangeFinished(VcpWheelMenuState finishedstate)
{
    if (finishedstate == VCP_WHEEL_MENU_ENTER_STATE)
    {
		// When fly in end, let them receive Pen and Key event
		// We needn't care fly out end, becuase them will hidden and restore in unhidden
		setIsUnhittable(VFX_FALSE);
		setFocused(VFX_TRUE);
		if (m_focusedWidget)
		{
			m_focusedWidget->setHidden(VFX_FALSE);
			m_focusedWidget->setIsUnhittable(VFX_FALSE);
			m_focusedWidget->setFocused(VFX_TRUE);
			m_focusedWidget->resume();
		}

		m_signalFly.emit(FLY_IN, FLY_FINISH);
    }
	else if (finishedstate == VCP_WHEEL_MENU_LEAVE_STATE)
	{
		m_signalFly.emit(FLY_OUT, FLY_FINISH);

		// Change to normal state after leave. Because from MM end key to Widget page,
		// We need call setHidde(VFX_FALSE) to show normal state of Widget menu
		changeState(VCP_WHEEL_MENU_NORMAL_STATE);
		if (m_focusedWidget)
		{
			m_focusedWidget->resume();
		}
	}

}

void VappKeyLauncherWidgetMenu::show()
{
	setFocus(s_focusedIdx);
}


void VappKeyLauncherWidgetMenu::fly(FlyType ft)
{
	if (ft == FLY_IN)
	{		
	    // enter effect
	    m_signalFly.emit(FLY_IN, FLY_START);

		if (m_focusedWidget)
		{
			m_focusedWidget->setHidden(VFX_TRUE);
		}
		
	    configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 500, 0, VCP_WHEEL_MENU_INCREASE);
	    changeState(VCP_WHEEL_MENU_ENTER_STATE);
	}
	else // FLY_OUT
	{
		// exit effect
		m_signalFly.emit(FLY_OUT, FLY_START);
		
		configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 500, 0, VCP_WHEEL_MENU_INCREASE);
		changeState(VCP_WHEEL_MENU_LEAVE_STATE);
	}

	// When fly in/out start, we don't let then receive pen and key event
	// When fly in/out end, restort them in function onStateChangeFinished
	setIsUnhittable(VFX_TRUE);
	setFocused(VFX_FALSE);
	if (m_focusedWidget)
	{
		m_focusedWidget->setIsUnhittable(VFX_TRUE);
		m_focusedWidget->setFocused(VFX_FALSE);
		m_focusedWidget->suspend();
	}
}


void VappKeyLauncherWidgetMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 preFocusItem)
{
#ifndef __WIDGET_MENU_TEST__
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_WIDGETMENU_FOCUS_IDX_CHANGE, 
							preFocusItem, focusItem, s_focusedIdx));

	if (s_focusedIdx != focusItem) // Focused index happen changed
	{
		s_focusedIdx = focusItem;
		
		// first release pervious widget full view
		releaseWidgetFocused();
		
		// wiat some time to focus it, in case press quickly
		m_timerFocusOneWidget->start();
	}
	else // Directly show focused widget, not start time to show
	{
		onFocusOneWidget(NULL);
	}
	
	// Modify the focused widget icon' bg image
	VfxFrame* cell = getCellIfPresent(preFocusItem);
	if (cell)
	{
		VfxImageFrame *bg_img = (VfxImageFrame *)(cell->getFirstChildFrame());
		bg_img->setResId(IMG_ID_VAPP_KEYLAUNCHER_WIDGET_N);
		cell->setSize(bg_img->getSize().width, bg_img->getSize().height);

		VfxImageFrame *icon_img = (VfxImageFrame *)(cell->getLastChildFrame());
		icon_img->setPos(cell->getSize().width / 2, cell->getSize().height / 2);
	}
#endif
}


void VappKeyLauncherWidgetMenu::onFocusOneWidget(VfxTimer *timer)
{
	// Modify the focused widget icon' bg image
	VfxFrame* cell = getCellIfPresent(s_focusedIdx);
	if (cell)
	{
		VfxImageFrame *bg_img = (VfxImageFrame *)(cell->getFirstChildFrame());
		bg_img->setResId(IMG_ID_VAPP_KEYLAUNCHER_WIDGET_P);
		cell->setSize(bg_img->getSize().width, bg_img->getSize().height);

		VfxImageFrame *icon_img = (VfxImageFrame *)(cell->getLastChildFrame());
		icon_img->setPos(cell->getSize().width / 2, cell->getSize().height / 2);
	}
	
 	// Maybe directly draw new focus widget full view is OK, maybe start timer to draw
	onWidgetFocused(m_widgetIds[s_focusedIdx]);
}


void VappKeyLauncherWidgetMenu::onWidgetFocused(VappWidgetId * focusedId)
{
	if (m_focusedWidget && (*focusedId == m_focusedWidget->getId()))
	{
		return; // widget ID don't changed, so we needn't release and create again.
	}

	VappWidgetKit *widgetKit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

	// Create focused widget under VappKeyLauncherDirector, not under this menu;
	// It will simple frame scene tree.
	m_focusedWidget = widgetKit->createWidget(*focusedId, this);//getParent());
	m_focusedWidget->createView();
	m_focusedWidget->setPos(VfxPoint(WIDGET_FOCUSED_POINT_MID_X, WIDGET_FOCUSED_POINT_MID_Y));
	m_focusedWidget->setPosZ(0.0);
}


void VappKeyLauncherWidgetMenu::releaseWidgetFocused()
{
	if (m_focusedWidget)
	{
		m_focusedWidget->releaseView();
    	VFX_OBJ_CLOSE(m_focusedWidget);
	}
}


#endif /* __MMI_VUI_LAUNCHER_KEY__ */
