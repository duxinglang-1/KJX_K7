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
 *  vtst_drag.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Drag example for Venus UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_drag.h"

#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_app_cat_scr.h"
#include "vfx_timer.h"
#include "vfx_datatype.h"


/***************************************************************************** 
 * Class VtstDragTarget
 *****************************************************************************/

VtstDragTarget::VtstDragTarget()
{
}

void VtstDragTarget::onInit()
{
    VfxControl::onInit();

    setAnchor(VfxFPoint(0.5, 0.5));
    setBounds(VfxRect(0, 0, 30, 30));
    setAutoAnimate(VFX_TRUE);
}

VfxBool VtstDragTarget::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_signalDrag.emit(this, event);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        m_signalMove.emit(this, event);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_signalDrop.emit(this, event);
    }
    
    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VtstDragBarItem
 *****************************************************************************/

VtstDragBarItem::VtstDragBarItem()
{
}

void VtstDragBarItem::onInit()
{
    VfxControl::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_RED);
    setAnchor(VfxFPoint(0.5, 0.5));
    setBounds(VfxRect(0, 0, 30, 30));
}

VfxBool VtstDragBarItem::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_signalDragStart.emit(this);
    }
    
    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VtstDragBar
 *****************************************************************************/

VtstDragBar::VtstDragBar()
{
}

void VtstDragBar::addItem(const VfxPoint &pos)
{
    VtstDragBarItem *item;
    VFX_OBJ_CREATE(item, VtstDragBarItem, this);
    item->setPos(pos);
    item->m_signalDragStart.connect(this, &VtstDragBar::onItemDragStart);
}

void VtstDragBar::onInit()
{
    VfxControl::onInit();

    setBorderWidth(1);
    setBorderColor(VFX_COLOR_WHITE);
}

void VtstDragBar::onItemDragStart(VtstDragBarItem *obj)
{
    m_signalDragStart.emit(obj);
}


/***************************************************************************** 
 * Class VtstDragScr
 *****************************************************************************/

VtstDragScr::VtstDragScr() : 
    m_controlBar(NULL),
    m_controlTarget(NULL),
    m_timerDropTargetToBar(NULL)
{
}

void VtstDragScr::onInit()
{
    VfxAppCatScr::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_BLUE);

    /*
     * Add a text frame to screen
     */
    VFX_OBJ_CREATE(m_controlBar, VtstDragBar, this);
    m_controlBar->setPos(VfxPoint(10, 10));
    m_controlBar->setBounds(VfxRect(0, 0, 150, 100));
    m_controlBar->m_signalDragStart.connect(this, &VtstDragScr::onItemDragStart);
    m_controlBar->addItem(VfxPoint(80, 80));
    
    VFX_OBJ_CREATE(m_timerDropTargetToBar, VfxTimer, this);
    m_timerDropTargetToBar->m_signalTick.connect(this, &VtstDragScr::onTimerDropTargetToBarTick);
}

void VtstDragScr::onItemDragStart(VtstDragBarItem *obj)
{
    VtstDragTarget *dragTarget;
    VFX_OBJ_CREATE(dragTarget, VtstDragTarget, this);
    dragTarget->setBgColor(VFX_COLOR_SILVER);
    dragTarget->m_signalDrag.connect(this, &VtstDragScr::onTargetDrag);
    dragTarget->m_signalMove.connect(this, &VtstDragScr::onTargetMove);
    dragTarget->m_signalDrop.connect(this, &VtstDragScr::onTargetDrop);
    dragTarget->capture();

    VFX_OBJ_CLOSE(obj);
}

void VtstDragScr::onTargetDrag(VtstDragTarget *obj, VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(this);
    obj->setBgColor(VFX_COLOR_YELLOW);
    obj->forcePos(pos);

    m_timerDropTargetToBar->stop();
}

void VtstDragScr::onTargetMove(VtstDragTarget *obj, VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(this);
    obj->forcePos(pos);

    if (m_controlBar->getRect().contains(pos))
    {
        obj->setBounds(VfxRect(0, 0, 30, 30));
    }
    else
    {
        obj->setBounds(VfxRect(0, 0, 100, 100));
    }
}

void VtstDragScr::onTargetDrop(VtstDragTarget *obj, VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(this);
    obj->setBgColor(VFX_COLOR_SILVER);
    obj->forcePos(pos);

    if (m_controlBar->getRect().contains(pos))
    {
        m_controlTarget = obj;
        obj->setPos(VfxPoint(m_controlBar->getRect().getMidX(), m_controlBar->getRect().getMidY()));
        m_timerDropTargetToBar->setStartDelay(250);
        m_timerDropTargetToBar->start();
    }
}

void VtstDragScr::onTimerDropTargetToBarTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    VfxPoint pos = m_controlTarget->getPos();
    m_controlBar->addItem(m_controlBar->convertPointFrom(pos, this));
    VFX_OBJ_CLOSE(m_controlTarget);
}

