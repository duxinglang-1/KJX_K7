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
 *  vapp_widget_3d.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the base class of the 3D widget.
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

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_3d.h"


/*****************************************************************************
 * 3D Widget Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VappWidget3D", VappWidget3D, VappWidget);


VappWidget3D::VappWidget3D() :
    m_penEventState(PEN_EVENT_STATE_NULL)
{
    // Do nothing.
}


VappWidget3D::~VappWidget3D()
{
    // Do nothing.
}


VfxBool VappWidget3D::onPreviewPenInput(VfxPenEvent &event)
{
    //
    // For scenario 1 (please read the 'onPenInput' for the details):
    //
    // When the pen is not captured yet and the pen is not handled by this
    // control itself, we capture it if the criteria meets in order to drag or
    // rotate the widget.
    //
    if (m_penEventState == PEN_EVENT_STATE_NULL)
    {
        //
        // If the pen movement is small enough when the 'long-tap' event comes,
        // capture the pen event to drag the widget.
        //
        if (isDndCriteriaFit(event))
        {
            m_penEventState = PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_DND;

            if (capture())
            {
                return VFX_TRUE;
            }
            else
            {
                m_penEventState = PEN_EVENT_STATE_NULL;
            }
        }

        //
        // If the vertical pen movement is large enough, capture the pen event
        // to rotate the widget.
        //
        if (isRotationCriteriaFit(event))
        {
            m_penEventState = PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_ROTATE;

            if (capture())
            {
                return VFX_TRUE;
            }
            else
            {
                m_penEventState = PEN_EVENT_STATE_NULL;
            }
        }
    }

    return VFX_FALSE;
}


VfxBool VappWidget3D::onPenAbortAccepted(
    VfxControl *aborter,
    VfxPenAbortReasonEnum reason)
{
    if (m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_DND ||
        m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_ROTATE ||
        m_penEventState == PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_DND ||
        m_penEventState == PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_ROTATE)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VappWidget3D::onPenInput(VfxPenEvent &event)
{
    //
    // THIS PART IS COMPLICATED. BE PATIENT.
    //
    // Scenario 1:
    //
    //  The pen is originally captured by the child control. This parent control
    //  captures it on the 'onPreviewPenInput'.
    //
    // Scenario 2:
    //
    //  The pen is directly captured by the parent control. We listen to the
    //  'long-tap' event to drag the widget or the 'move' event to rotate the
    //  widget.
    //
    if (m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_DND)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            onDrag(event);
            m_signalDrag.emit(this, event);
        }
    }
    else if (m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_ROTATE)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            onRotateStart(event);
            m_signalRotateStart.emit(this, event);
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
            m_penEventState = PEN_EVENT_STATE_CAPTURE_BY_ITSELF;
        }

        //
        // Monitor the further pen event if we can drag the widget or rotate the
        // widget.
        //
        if (m_penEventState == PEN_EVENT_STATE_CAPTURE_BY_ITSELF)
        {
            if (isRotationCriteriaFit(event))
            {
                m_penEventState = PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_ROTATE;

                onRotateStart(event);
                m_signalRotateStart.emit(this, event);

                return VFX_TRUE;
            }

            if (isDndCriteriaFit(event))
            {
                m_penEventState = PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_DND;

                onDrag(event);
                m_signalDrag.emit(this, event);

                return VFX_TRUE;
            }
        }

        //
        // We cannot drag or rotate the widget. Return and wait for the next pen
        // event.
        //
        if (m_penEventState != PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_ROTATE &&
            m_penEventState != PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_DND)
        {
            // Criteria doesn't meet even the 'pen-up' or 'pen-abort' comes.
            // Reset the state to finish this pen event life cycle.
            if (event.type == VFX_PEN_EVENT_TYPE_UP ||
                event.type == VFX_PEN_EVENT_TYPE_ABORT)
            {
                m_penEventState = PEN_EVENT_STATE_NULL;
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
    // We can drag or rotate the widget now.
    //
    if (m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_DND ||
        m_penEventState == PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_DND)
    {
        onPenInputToDnd(event);
    }
    else if (m_penEventState == PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_ROTATE ||
             m_penEventState == PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_ROTATE)
    {
        onPenInputToRotate(event);
    }

    return VFX_TRUE;
}


VfxBool VappWidget3D::onPenInputToDnd(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_MOVE:
            onMove(event);
            m_signalMove.emit(this, event);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            onDrop(event);
            m_signalDrop.emit(this, event);
            m_penEventState = PEN_EVENT_STATE_NULL;
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            onAbort(event);
            m_signalAbort.emit(this, event);
            m_penEventState = PEN_EVENT_STATE_NULL;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


VfxBool VappWidget3D::onPenInputToRotate(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_MOVE:
            onRotate(event);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            onRotateEnd(event);
            m_penEventState = PEN_EVENT_STATE_NULL;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappWidget3D::onRotateStart(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappWidget3D::onRotate(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


void VappWidget3D::onRotateEnd(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // Do nothing.
}


VfxBool VappWidget3D::isVerticalPenMove(const VfxPenEvent &event)
{
    VfxS32 xDiff = vfxAbs(event.pos.x - event.downPos.x);
    VfxS32 yDiff = vfxAbs(event.pos.y - event.downPos.y);

    return yDiff > xDiff ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappWidget3D::isRotationCriteriaFit(const VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_MOVE &&
        calcDistance(event.downPos, event.pos) > ROTATE_START_OFFSET &&
        isVerticalPenMove(event))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__) */

