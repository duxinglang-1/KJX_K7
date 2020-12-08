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
 *  vapp_widget_3d.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the 3D widget.
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

#ifndef VAPP_WIDGET_3D_H
#define VAPP_WIDGET_3D_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"


/*****************************************************************************
 * 3D Widget Base Class
 *****************************************************************************/

/*
 * 3D Widget Base Class
 */
class VappWidget3D : public VappWidget
{
    VFX_DECLARE_CLASS(VappWidget3D);

// Constructor / Destructor
public:
    // Default constructor
    VappWidget3D();

    // Default destructor
    virtual ~VappWidget3D();

// Signal
public:
    // 'rotate-start' signal
    VfxSignal2 <
        VappWidget3D *,     // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalRotateStart;

    // 'rotate' signal
    VfxSignal2 <
        VappWidget3D *,     // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalRotate;

    // 'rotate-end' signal
    VfxSignal2 <
        VappWidget3D *,     // [IN] This widget
        VfxPenEvent &       // [IN] Pen event
    > m_signalRotateEnd;

// Override
protected:
    // Please refer to VfxControl.
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event
    );

    // Please refer to VfxControl.
    virtual VfxBool onPenAbortAccepted(
        VfxControl *aborter,
        VfxPenAbortReasonEnum reason
    );

    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // This function handles the pen event to drag the widget.
    // RETURNS: On processed, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool onPenInputToDnd(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the pen event to rotate the widget.
    // RETURNS: On processed, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool onPenInputToRotate(
        VfxPenEvent &event      // [In] Pen event
    );

// Override
protected:
    // This function is called when the user starts to rotate the 3D widget.
    virtual void onRotateStart(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is called when teh user is rotating the 3D widget.
    virtual void onRotate(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is called when the user stops rotating the 3D widget.
    virtual void onRotateEnd(
        VfxPenEvent &event      // [IN] Pen event
    );

// Enum
private:
    // This enum defines the constants to control the behavior of the widget.
    enum
    {
        // The offset in pixels that the widget will capture the pen event and
        // start to rotate up or down when the user taps the touch screen.
        ROTATE_START_OFFSET = VAPP_WIDGET_DND_CRITERIA
    };

// Enum
private:
    // This enum defines the states of the FSM to handle the pen event. The pen
    // event is used to drag or rotate the widget.
    enum PenEventStateEnum
    {
        // No pen event is received yet.
        PEN_EVENT_STATE_NULL,

        // Pen event is captured from a child frame and will be used to drag the
        // widget.
        PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_DND,

        // Pen event is captured from a child frame and will be used to rotate
        // widget.
        PEN_EVENT_STATE_CAPTURE_FROM_OTHERS_TO_ROTATE,

        // Pen event is captured by this frame. We need to monitor the following
        // pen events to determine if we can drag the widget or rotate the
        // widget.
        PEN_EVENT_STATE_CAPTURE_BY_ITSELF,

        // Pen event is captured by this frame and we can drag the widget.
        PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_DND,

        // Pen event is captured by this frame and we can rotate the widget.
        PEN_EVENT_STATE_CAPTURE_BY_ITSELF_TO_ROTATE,

        // End of the enum.
        PEN_EVENT_STATE_END_OF_ENUM
    };

// Variable
private:
    // FSM state for the pen event handling.
    PenEventStateEnum m_penEventState;

// Implementation
private:
    // This function checks if the pen moves in the vertical direction.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isVerticalPenMove(
        const VfxPenEvent &event    // [IN] Pen event
    );

    // This function checks if the rotation criteria meets.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isRotationCriteriaFit(
        const VfxPenEvent &event    // [IN] Pen event
    );
};

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_3D_V10__) */
#endif /* VAPP_WIDGET_3D_H */

