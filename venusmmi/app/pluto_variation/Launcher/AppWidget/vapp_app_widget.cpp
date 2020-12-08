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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_app_widget.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget's base class
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

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget.h"
#include "mmi_rp_vapp_app_widget_def.h"


/*****************************************************************************
 * Widget Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VappAppWidget", VappAppWidget, VfxControl);


VappAppWidget::VappAppWidget() :
    m_isCreated(VFX_FALSE),
    m_isSlim(VFX_FALSE),
    m_isInEditMode(VFX_FALSE),
    m_numOfChild(0),
    m_dndState(DND_NULL),
    m_originalPosition(VFX_POINT_ZERO),
    m_button(NULL)
{
    // Do nothing.
}


VappAppWidget::~VappAppWidget()
{
    // Do nothing.
}


void VappAppWidget::setPos(const VfxPoint &value)
{
    VfxControl::setPos(value);

    // Update the position of the button since FPE will not actually change
    // the property in UI engine. It only changes the property in VRT
    // context.
    if (m_button)
    {
        m_button->setStickyPos(value);
    }
}


void VappAppWidget::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    // Update the position of the button; otherwise, the position will be wrong
    // when the size of the widget changes.
    //
    // SEE ALSO: VappAppWidgetStickyButton::setStickyTo
    if (m_button)
    {
        m_button->setStickyPos(getPos());
    }
}


void VappAppWidget::setIsUnhittable(VfxBool value)
{
    VfxControl::setIsUnhittable(value);

    if (m_button)
    {
        m_button->setIsUnhittable(value);
    }
}


void VappAppWidget::setFilter(VfxFrameFilter *value)
{
    VfxControl::setFilter(value);

    if (m_button)
    {
        m_button->setFilter(value);
    }
}


void VappAppWidget::setHidden(VfxBool value)
{
    VfxControl::setHidden(value);

    if (m_button)
    {
        //
        // If we want to hide this widget, we can also hide the sticky button
        // undoubtedly. However, if we want to show this widget, we can only
        // show the sticky button when the widget is in the edit mode.
        //
        if (value)
        {
            m_button->setHidden(VFX_TRUE);
        }
        else
        {
            if (isInEditMode())
            {
                m_button->setHidden(VFX_FALSE);
            }
        }
    }
}


void VappAppWidget::onInit()
{
    VfxControl::onInit();

    setAutoAnimate(VFX_TRUE);
    setAnchor(0.5f, 0.5f);

    //
    // Myself UI component
    //
    VFX_OBJ_CREATE(m_button, VappAppWidgetStickyButton, this);
    m_button->setHidden(VFX_TRUE);
}


void VappAppWidget::onDeinit()
{
    VfxControl::onDeinit();
}


void VappAppWidget::onParentFrameChanged(VfxFrame *oldParentFrame)
{
    VfxControl::onParentFrameChanged(oldParentFrame);

    if (m_button)
    {
        VfxFrame *parentFrame = getParentFrame();

        if (!parentFrame)
        {
            m_button->removeFromParentFrame();
        }
        else
        {
            parentFrame->addChildFrame(m_button);
        }
    }
}


VfxBool VappAppWidget::onPreviewPenInput(VfxPenEvent &event)
{
    //
    // For scenario 1 (please read the 'onPenInput' for the details):
    //
    // When the pen is not captured yet and the pen is not handled by this
    // control itself, we capture it if the criteria meets.
    //
    if (m_dndState == DND_NULL && isDndCriteriaFit(event))
    {
        m_dndState = DND_CAPTURE_FROM_OTHERS;

        if (capture())
        {
            return VFX_TRUE;
        }
        else
        {
            m_dndState = DND_NULL;
        }
    }

    return VfxControl::onPreviewPenInput(event);
}


VfxBool VappAppWidget::onPenInput(VfxPenEvent &event)
{
    //
    // THIS PART IS COMPLICATED. BE PATIENT.
    //
    // Scenario 1:
    //
    //  The pen is originally captured by the child control. This parent control
    //  captures it on the 'onPreviewPenInput'.
    //
    //
    // Scenario 2:
    //
    //  The pen is directly captured by the parent control. We listen to the
    //  'long-tap' event to start the drag-and-drop (DnD) process.
    //
    if (m_dndState == DND_CAPTURE_FROM_OTHERS)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            onDrag(event);
            m_signalDrag.emit(this, event);
        }
    }
    else
    {
        //
        // Remeber the pen event is already captured by itself such that in the
        // onPreviewPenInput, we will not capture the pen event from itself.
        //
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            m_dndState = DND_CAPTURE_BY_ITSELF;
        }

        //
        // Wait for the 'long-tap' event to check if we can start the DnD
        // process.
        //
        if (isDndCriteriaFit(event))
        {
            m_dndState = DND_LONG_TAPPED_BY_ITSELF;
            onDrag(event);
            m_signalDrag.emit(this, event);
        }

        //
        // Above criteria does not meet. Wait for the next event to start the
        // DnD process, or reset the state if this event life cycle ends.
        //
        if (m_dndState != DND_LONG_TAPPED_BY_ITSELF)
        {
            // Criteria doesn't meet even the 'pen-up' or 'pen-abort' comes.
            // Reset the state to finish this pen event life cycle.
            if (event.type == VFX_PEN_EVENT_TYPE_UP ||
                event.type == VFX_PEN_EVENT_TYPE_ABORT)
            {
                m_dndState = DND_NULL;
            }

            // Check if this is a tap operation. If yes, invoke the operation.
            if (canInvokeTap(event))
            {
                invokeTap(event);
            }

            return VFX_TRUE;
        }
    }

    //
    // For both scenarios, we can drag the widget now.
    //
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_MOVE:
            onMove(event);
            m_signalMove.emit(this, event);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            onDrop(event);
            m_signalDrop.emit(this, event);
            m_dndState = DND_NULL;
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            onAbort(event);
            m_signalAbort.emit(this, event);
            m_dndState = DND_NULL;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappAppWidget::onObjectNotify(VfxId id,void * userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            VfxFrame *frame = (VfxFrame *)userData;
            onParentFrameChanged(frame);
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id,userData);
            return;
        }
    }
}


void VappAppWidget::onCreateView()
{
    // Do nothing.
}


void VappAppWidget::onReleaseView()
{
    // Do nothing.
}


void VappAppWidget::onEnterSlimView()
{
    // Do nothing.
}


void VappAppWidget::onExitSlimView()
{
    // Do nothing.
}


void VappAppWidget::onEnterEditMode()
{
    // Do nothing.
}


void VappAppWidget::onExitEditMode()
{
    // Do nothing.
}


void VappAppWidget::onTap(const VfxPoint &pos)
{
    VFX_UNUSED(pos);

    // Do nothing.
}


void VappAppWidget::onDrag(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappAppWidget::onMove(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappAppWidget::onDrop(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappAppWidget::onAbort(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


VfxPoint VappAppWidget::onGetEditButtonOffset()
{
    return VFX_POINT_ZERO;
}


void VappAppWidget::createView()
{
    if (!m_isCreated)
    {
        // Used to check memory leak.
        m_numOfChild = getChildCount();

        //
        // Myself UI components.
        //
        m_button->setImgId(IMG_ID_VAPP_APP_WIDGET_BUTTON_DELETE);
        m_button->setId((VfxId)this);
        m_button->setStickyTo(this, onGetEditButtonOffset());
        m_button->setStickyPos(getPos());

        m_button->m_signalClicked.connect(this, &VappAppWidget::onButtonClicked);

        VfxFrame *parentFrame = getParentFrame();
        if (!parentFrame)
        {
            m_button->removeFromParentFrame();
        }
        else
        {
            parentFrame->addChildFrame(m_button);
        }

        //
        // Create this widget's specific UI components.
        //
        onCreateView();

        m_isCreated = VFX_TRUE;
    }
}


void VappAppWidget::releaseView()
{
    if (m_isCreated)
    {
        // Release this widget's specific UI components.
        onReleaseView();

        VfxS32 numOfChild = getChildCount();
        VFX_ASSERT(m_numOfChild == numOfChild);

        m_isCreated = VFX_FALSE;
    }
}


void VappAppWidget::enterSlimView()
{
    if (!m_isSlim)
    {
        onEnterSlimView();

        m_isSlim = VFX_TRUE;
    }
}


void VappAppWidget::exitSlimView()
{
    if (m_isSlim)
    {
        onExitSlimView();

        m_isSlim = VFX_FALSE;
    }
}


void VappAppWidget::backupPosition()
{
    m_originalPosition = getPos();
}


void VappAppWidget::restorePosition()
{
    setPos(m_originalPosition);
}


void VappAppWidget::enterEditMode()
{
    if (!m_isInEditMode)
    {
        if (m_button)
        {
            m_button->setHidden(VFX_FALSE);
        }

        onEnterEditMode();

        m_isInEditMode = VFX_TRUE;
    }
}


void VappAppWidget::exitEditMode()
{
    if (m_isInEditMode)
    {
        if (m_button)
        {
            m_button->setHidden(VFX_TRUE);
        }

        onExitEditMode();

        m_isInEditMode = VFX_FALSE;
    }
}


VfxSize VappAppWidget::getMaxRoomSize() const
{
    return VfxSize(VAPP_DESKTOP_PAGE_MAX_ROOM_WIDTH,
                   VAPP_DESKTOP_PAGE_MAX_ROOM_HEIGHT);
}


VfxSize VappAppWidget::getRoomSize(
    VfxS32 horizTileNum,
    VfxS32 vertiTileNum) const
{
    VFX_ASSERT(horizTileNum <= VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM);
    VFX_ASSERT(vertiTileNum <= VAPP_DESKTOP_PAGE_VERTI_TILE_NUM);

    return VfxSize(VAPP_DESKTOP_PAGE_TILE_WIDTH * horizTileNum,
                   VAPP_DESKTOP_PAGE_TILE_HEIGHT * vertiTileNum);
}


VfxS32 VappAppWidget::calcDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


VfxBool VappAppWidget::isDndCriteriaFit(const VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP &&
        calcDistance(event.downPos, event.pos) <= VAPP_APP_WIDGET_DND_CRITERIA)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappAppWidget::canInvokeTap(const VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP &&
        containPoint(event.getRelPos(this)))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappAppWidget::invokeTap(const VfxPenEvent &event)
{
    VfxPoint *penPos;

    VFX_ALLOC_MEM(penPos, sizeof(VfxPoint), this);
    *penPos = event.getRelDownPos(this);

    vfxPostInvoke(this, &VappAppWidget::handleOnTap, penPos);
}


void VappAppWidget::handleOnTap(void *userData)
{
    VFX_ASSERT(userData);

    // Copy the data to the stack memory to avoid from the complication.
    VfxPoint penPos = (*(VfxPoint *)userData);
    VFX_FREE_MEM(userData);

    // Callback to the child.
    onTap(penPos);
}


void VappAppWidget::onButtonClicked(VappAppWidgetStickyButton *obj)
{
    m_signalDeselect.emit(this);
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

