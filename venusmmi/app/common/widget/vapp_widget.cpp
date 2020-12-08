/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

#include "mmi_rp_vapp_widget_system_def.h"


/*****************************************************************************
 * Widget Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VappWidget", VappWidget, VfxControl);


VappWidget::VappWidget() :
    m_isCreated(VFX_FALSE),
    m_isSerialized(VFX_FALSE),
    m_isSerializedForPageSwitch(VFX_FALSE),
    m_isProcessPenCapture(VFX_FALSE),
    m_isSuspended(VFX_FALSE),
    m_isSlim(VFX_FALSE),
    m_isInEditMode(VFX_FALSE),
    m_isFocused(VFX_FALSE),
    m_isVisible(VFX_FALSE),
    m_numOfChild(0),
    m_dndState(DND_NULL),
    m_originalPosition(VFX_POINT_ZERO),
    m_archiveSource(NULL),
    m_archiveSourceForPageSwitch(NULL),
    m_button(NULL)
{
    // Do nothing.
}


VappWidget::~VappWidget()
{
    // Do nothing.
}


void VappWidget::setPos(const VfxPoint &value)
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


void VappWidget::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    // Update the position of the button; otherwise, the position will be wrong
    // when the size of the widget changes.
    //
    // SEE ALSO: VappWidgetStickyButton::setStickyTo
    if (m_button)
    {
        m_button->setStickyPos(getPos());
    }
}


void VappWidget::setIsUnhittable(VfxBool value)
{
    VfxControl::setIsUnhittable(value);

    if (m_button)
    {
        m_button->setIsUnhittable(value);
    }
}


void VappWidget::setFilter(VfxFrameFilter *value)
{
    VfxControl::setFilter(value);

    if (m_button)
    {
        m_button->setFilter(value);
    }
}


void VappWidget::setHidden(VfxBool value)
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


void VappWidget::processPenCapture()
{
    m_isProcessPenCapture = VFX_TRUE;
    capture();
}


void VappWidget::onInit()
{
    VfxControl::onInit();

    setAutoAnimate(VFX_TRUE);
    setAnchor(0.5f, 0.5f);
}


void VappWidget::onDeinit()
{
    // Fail-safe. If the view isn't released, release it automatically.
    if (isCreated())
    {
        releaseView();
    }

    VfxControl::onDeinit();
}


void VappWidget::setWidgetDragged(VfxBool isDragged)
{
    m_dndState = DND_CAPTURE_FROM_MM;
}


void VappWidget::onParentFrameChanged(VfxFrame *oldParentFrame)
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


VfxBool VappWidget::onPreviewPenInput(VfxPenEvent &event)
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
        m_isProcessPenCapture = VFX_TRUE;

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


VfxBool VappWidget::onPenInput(VfxPenEvent &event)
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
            m_isProcessPenCapture = VFX_FALSE;
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
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN && m_dndState != DND_CAPTURE_FROM_MM)
        {
            m_dndState = DND_CAPTURE_BY_ITSELF;
        }

        //
        // Wait for the 'long-tap' event to check if we can start the DnD
        // process.
        //
        if (isDndCriteriaFit(event) || m_dndState == DND_CAPTURE_FROM_MM)
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


void VappWidget::onObjectNotify(VfxId id,void * userData)
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


VappWidgetId VappWidget::getId() const
{
    return VappWidgetId(); // Invalid widget ID.
}


VfxS32 VappWidget::getName(VfxWChar *string, VfxS32 size) const
{
    return 0;
}


VfxSize VappWidget::getMaxSize() const
{
    return VFX_SIZE_ZERO;
}


VfxFrame *VappWidget::createIcon(VfxObject *parentObj)
{
    return NULL;
}


void VappWidget::onCreateView()
{
    // Do nothing.
}


void VappWidget::onReleaseView()
{
    // Do nothing.
}


VfxBool VappWidget::getCreateViewFailure(VfxWString &errorString)
{
    return VFX_FALSE;
}


void VappWidget::onSerializeView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


void VappWidget::onRestoreView(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


void VappWidget::onSerializeViewForPageSwitch(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


void VappWidget::onRestoreViewForPageSwitch(VfxArchive *ar)
{
    VFX_UNUSED(ar);

    // Do nothing.
}


void VappWidget::onSuspend()
{
    // Do nothing.
}


void VappWidget::onResume()
{
    // Do nothing.
}


void VappWidget::onEnterSlimView()
{
    // Do nothing.
}


void VappWidget::onExitSlimView()
{
    // Do nothing.
}


void VappWidget::onEnterEditMode()
{
    // Do nothing.
}


void VappWidget::onExitEditMode()
{
    // Do nothing.
}


void VappWidget::onFocus()
{
    // Do nothing.
}


void VappWidget::onDefocus()
{
    // Do nothing.
}


void VappWidget::onVisibleChanged(VfxBool isVisible)
{
    VFX_UNUSED(isVisible);

    // Do nothing.
}


void VappWidget::onTap(const VfxPoint &pos)
{
    VFX_UNUSED(pos);

    // Do nothing.
}


void VappWidget::onDrag(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappWidget::onMove(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappWidget::onDrop(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappWidget::onAbort(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


VfxPoint VappWidget::onGetEditButtonOffset()
{
    return VFX_POINT_ZERO;
}


void VappWidget::createView()
{
    if (!m_isCreated)
    {
        // Used to check memory leak.
        m_numOfChild = getChildCount();

        //
        // Create this widget's specific UI components.
        //
        onCreateView();

        //
        // If failed, check there isn't memory leak. If successful, change the
        // widget's state accordingly.
        //
        VfxWString errorString;

        if (getCreateViewFailure(errorString))
        {
            VfxS32 numOfChild = getChildCount();
            VFX_ASSERT(m_numOfChild == numOfChild);
        }
        else
        {
            m_isCreated = VFX_TRUE;
        }
    }
}


void VappWidget::releaseView()
{
    if (m_isCreated)
    {
        // If the serialized memory archive source is present, close it.
        VFX_OBJ_CLOSE(m_archiveSource);
        m_isSerialized = VFX_FALSE;

        // If the serialized memory archive source is present, close it.
        VFX_OBJ_CLOSE(m_archiveSourceForPageSwitch);
        m_isSerializedForPageSwitch = VFX_FALSE;

        //
        // m_button is created/deleted in the edit mode period,
        // but widget may be deleted when change launcher in setting during widget is in edit mode,
        // so it needs to check it if button is still alive and then delete it.
        //
        VFX_OBJ_CLOSE(m_button);

        // Release this widget's specific UI components.
        onReleaseView();

        VfxS32 numOfChild = getChildCount();
        VFX_ASSERT(m_numOfChild == numOfChild);

        // reset variable
        m_isCreated = VFX_FALSE;
        m_isSlim = VFX_FALSE;
        m_isInEditMode = VFX_FALSE;
        m_isFocused = VFX_FALSE;
        m_isVisible = VFX_FALSE;
    }
}


void VappWidget::serializeView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    VAPP_WIDGET_LOG((TRC_VAPP_WIDGET_SERIALIZE_VIEW, m_isSerialized, 200));

    if (!m_isSerialized)
    {
        VfxArchive *archive;

        VFX_ASSERT(!m_archiveSource);
        VFX_OBJ_CREATE(m_archiveSource, VfxMemArchiveSource, this);

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSource);

        onSerializeView(archive);

        VFX_OBJ_CLOSE(archive);

        m_isSerialized = VFX_TRUE;
    }
}


void VappWidget::restoreView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    VAPP_WIDGET_LOG((TRC_VAPP_WIDGET_RESTORE_VIEW, m_isSerialized, 200));

    if (m_isSerialized)
    {
        VfxArchive *archive;
        VfxU8 *buf;
        VfxU32 size;

        VFX_ASSERT(m_archiveSource);

        // TODO:
        //
        // Archive source shall support to switch from write mode to read mode
        // directly.
        m_archiveSource->detachBuffer(&buf, &size);
        if (buf)
        {
            m_archiveSource->attachBuffer(buf, size);
        }

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSource);

        onRestoreView(archive);

        VFX_OBJ_CLOSE(archive);
        VFX_OBJ_CLOSE(m_archiveSource);

        m_isSerialized = VFX_FALSE;
    }
}


void VappWidget::serializeViewForPageSwitch()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    VAPP_WIDGET_LOG((TRC_VAPP_WIDGET_SERIALIZE_VIEW_FOR_PAGE_SWITCH, m_isSerializedForPageSwitch, 200));

    if (!m_isSerializedForPageSwitch)
    {
        VfxArchive *archive;

        VFX_ASSERT(!m_archiveSourceForPageSwitch);
        VFX_OBJ_CREATE(m_archiveSourceForPageSwitch, VfxMemArchiveSource, this);

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSourceForPageSwitch);

        onSerializeViewForPageSwitch(archive);

        VFX_OBJ_CLOSE(archive);

        m_isSerializedForPageSwitch = VFX_TRUE;
    }
}


void VappWidget::restoreViewForPageSwitch()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    VAPP_WIDGET_LOG((TRC_VAPP_WIDGET_RESTORE_VIEW_FOR_PAGE_SWITCH, m_isSerializedForPageSwitch, 200));

    if (m_isSerializedForPageSwitch)
    {
        VfxArchive *archive;
        VfxU8 *buf;
        VfxU32 size;

        VFX_ASSERT(m_archiveSourceForPageSwitch);

        // TODO:
        //
        // Archive source shall support to switch from write mode to read mode
        // directly.
        m_archiveSourceForPageSwitch->detachBuffer(&buf, &size);
        if (buf)
        {
            m_archiveSourceForPageSwitch->attachBuffer(buf, size);
        }

        VFX_OBJ_CREATE(archive, VfxArchive, this);

        archive->setSource(m_archiveSourceForPageSwitch);

        onRestoreViewForPageSwitch(archive);

        VFX_OBJ_CLOSE(archive);
        VFX_OBJ_CLOSE(m_archiveSourceForPageSwitch);

        m_isSerializedForPageSwitch = VFX_FALSE;
    }
}


void VappWidget::suspend()
{
    VFX_ASSERT(m_isCreated);

    if (!m_isSuspended)
    {
        onSuspend();

        m_isSuspended = VFX_TRUE;
    }
}


void VappWidget::resume()
{
    VFX_ASSERT(m_isCreated);

    if (m_isSuspended)
    {
        onResume();

        m_isSuspended = VFX_FALSE;
    }
}


void VappWidget::enterSlimView()
{
    VFX_ASSERT(m_isCreated);

    if (!m_isSlim)
    {
        onEnterSlimView();

        m_isSlim = VFX_TRUE;
    }
}


void VappWidget::exitSlimView()
{
    VFX_ASSERT(m_isCreated);

    if (m_isSlim)
    {
        onExitSlimView();

        m_isSlim = VFX_FALSE;
    }
}


void VappWidget::backupPosition()
{
    m_originalPosition = getPos();
}


void VappWidget::restorePosition()
{
    setPos(m_originalPosition);
}


void VappWidget::enterEditMode()
{
    if (!m_isInEditMode)
    {
        //
        // Create widget delete button
        //
        VFX_OBJ_CREATE(m_button, VappWidgetStickyButton, this);
        m_button->setImgId(IMG_ID_VAPP_WIDGET_BUTTON_DELETE);
        m_button->setId((VfxId)this);
        m_button->setStickyTo(this, onGetEditButtonOffset());
        m_button->setStickyPos(getPos());

        m_button->m_signalClicked.connect(this, &VappWidget::onButtonClicked);

        VfxFrame *parentFrame = getParentFrame();
        if (!parentFrame)
        {
            m_button->removeFromParentFrame();
        }
        else
        {
            parentFrame->addChildFrame(m_button);
        }

        onEnterEditMode();

        m_isInEditMode = VFX_TRUE;
    }
}


void VappWidget::exitEditMode()
{
    if (m_isInEditMode)
    {
        VFX_OBJ_CLOSE(m_button);

        onExitEditMode();

        m_isInEditMode = VFX_FALSE;
    }
}


void VappWidget::focusView()
{
    if (!m_isFocused)
    {
        onFocus();

        m_isFocused = VFX_TRUE;
    }
}


void VappWidget::defocusView()
{
    if (m_isFocused)
    {
        onDefocus();

        m_isFocused = VFX_FALSE;
    }
}


void VappWidget::setVisible(VfxBool isVisible)
{
    if (m_isVisible && !isVisible)
    {
        m_isVisible = VFX_FALSE;

        onVisibleChanged(VFX_FALSE);
    }
    else if (!m_isVisible && isVisible)
    {
        m_isVisible = VFX_TRUE;

        onVisibleChanged(VFX_TRUE);
    }
}


#if defined(__COSMOS_3D_V10__)
void VappWidget::setEditButtonMaterial(VfxMaterial *material)
{
    if (m_button)
    {
        m_button->setMaterial(material);
    }
}
#endif /* defined(__COSMOS_3D_V10__) */


VfxS32 VappWidget::calcDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return VFX_ABS(p1.x - p2.x) + VFX_ABS(p1.y - p2.y);
}


VfxBool VappWidget::isDndCriteriaFit(const VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP &&
        calcDistance(event.downPos, event.pos) <= VAPP_WIDGET_DND_CRITERIA)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappWidget::canInvokeTap(const VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP &&
        containPoint(event.getRelPos(this)))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappWidget::invokeTap(const VfxPenEvent &event)
{
    VfxPoint *penPos;

    VFX_ALLOC_MEM(penPos, sizeof(VfxPoint), this);
    *penPos = event.getRelDownPos(this);

    vfxPostInvoke(this, &VappWidget::handleOnTap, penPos);
}


void VappWidget::handleOnTap(void *userData)
{
    VFX_ASSERT(userData);

    // Copy the data to the stack memory to avoid from the complication.
    VfxPoint penPos = (*(VfxPoint *)userData);
    VFX_FREE_MEM(userData);

    // Callback to the child.
    onTap(penPos);
}


void VappWidget::onButtonClicked(VappWidgetStickyButton *obj)
{
    m_signalDeselect.emit(this);
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */

