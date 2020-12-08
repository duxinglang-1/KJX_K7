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
 *  vfx_pen.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Pen Input Sub-system
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
#ifndef __VFX_PEN_H__
#define __VFX_PEN_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_weak_ptr.h"
#include "vfx_timer.h"
#include "vfx_object_list.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// The VfxPen registered name
#define VFX_PEN_CLASS_NAME              "Pen"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxControl;


/*
 * VfxPenDeviceInfo is a structure provides pen device information.
 *
 * SEE ALSO: VfxPen, vfxPenProcessPenInput, vfxPenProcessStrokeInput.
 */
class VfxPenDeviceInfo : public VfxBase
{
public:
    VfxMsec             timeStamp;      // invoke time.
    VfxPoint            pos;            // pen position.
    VfxPenEventTypeEnum eventType;      // pen event type.
    VfxU16              pressure;
};


/*
 * Internal used. It should only be changed by framework.
 */
enum VfxPenStateEnum
{
    VFX_PEN_STATE_UNKNOWN = 0,
    VFX_PEN_STATE_STARTUP,     // Startup
    VFX_PEN_STATE_SHUTDOWN,    // Shutdown
    VFX_PEN_STATE_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxPen
 *****************************************************************************/

/*
 * VfxPen is a singletion class. VfxPen receives pen input events from system, 
 * and dispatch them.
 *
 * SEE ALSO: VfxPenEvent, VfxControl
 */
class VfxPen : public VfxObject
{
    VFX_DECLARE_CLASS(VfxPen);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxPen);

// Constructor / Destructor
public:
    // Default constructor
    VfxPen();

// Method
public:
    // Get the current pen event type.
    //
    // RETURNS: Current pen event type. Return VFX_PEN_EVENT_TYPE_UNKNOWN if
    //  the pen is not on the touch panel.
    //
    // SEE ALSO: VfxPenEventTypeEnum
    VfxPenEventTypeEnum getCurPenEventType() const
    {
        return m_curEventType;
    }

    // Get the current pen event time stamp.
    //
    // RETURNS: Current pen event time stamp.
    //
    // SEE ALSO: getCurPenEventType
    VfxMsec getCurTimeStamp() const
    {
        return m_eventTimeStamp[0];
    }

    // Get the current pen event position.
    //
    // RETURNS: Current pen event position on global coordinate.
    //
    // SEE ALSO: getCurPenEventType
    VfxPoint getCurPenPos() const
    {
        return m_eventPos[0];
    }

    // Get the previous pen event time stamp.
    //
    // RETURNS: Previous pen event time stamp.
    VfxMsec getPrevTimeStamp() const
    {
        return m_eventTimeStamp[1];
    }

    // Get the previous pen event position.
    //
    // RETURNS: Previous pen event position on global coordinate.
    VfxPoint getPrevPos() const
    {
        return m_eventPos[1];
    }

    // Get the pen down event time stamp.
    //
    // RETURNS: Pen down event time stamp.
    VfxMsec getDownTimeStamp() const
    {
        return m_downTimeStamp;
    }

    // Get the pen down event position.
    //
    // RETURNS: Pen down event position on global coordinate.
    VfxPoint getDownPos() const
    {
        return m_downPos;
    }

// Signal
public:
    // Emit on an event has been proceesed
    VfxSignal2 <
        VfxPenEvent &,  // Processed pen input.
        VfxControl *    // control which handled the event. NULL if no control handled.
    > m_signalEventProcessed;

// Framework method
public:
    void startup();
    void shutdown();
    void reset();

    // Internal used. Set the given control as the captured control. 
    // Use VfxControl::getCapture to instead.
    //
    // NOTE: The original captured control will get a VFX_PEN_EVENT_TYPE_ABORT
    //  event. The parameter control can be NULL to release current captured control.
    //  
    // RETURNS: Return VFX_TRUE if successful. Otherwise, return VFX_FALSE.
    // 
    // SEE ALSO: VfxPenEventTypeEnum, VfxControl::getCapture
    VfxBool setCapture(
        VfxControl *control,             // [IN] The control to capture
        VfxPenAbortReasonEnum reason = VFX_PEN_ABORT_REASON_DEFAULT // [IN] Pen abort reason
    );

    // Experimental method.
    VfxBool delayEvent(VfxControl *delayer, VfxPenEvent &event);
    
    // Experimental method.
    void resumeDelayedEvent();

    // Internal used. Predict pen position.
    void predictPenInput(
        VfxPenDeviceInfo &penStatus
    );

    // Internal used. Dispatch a given pen event.
    VfxBool processPenInput(
        const VfxPenDeviceInfo &penStatus   // [IN] The status of the pen input event
    );

    // Internal used.
    void processAfterPenInput(
        VfxPenEventTypeEnum eventType,
        VfxPenEvent &event, 
        VfxControl *handledControl);

    // Internal used.
    void startCaptureStrokes(
        VfxControl *control,
        VfxPenStrokePoint *points,
        VfxU32 maxPointCount,
        const VfxPenStrokeHandWritingRegion *areas,
        VfxU32 areaCount,
        const VfxPenStrokeHandWritingRegion *extArea = NULL
    );

    // Internal used.
    void stopCaptureStrokes(
        VfxControl *control
    );

    // Internal used.
    void beginStrokesOfCharacter(
        VfxControl *control
    );
        
    // Internal used.
    void endStrokesOfCharacter(
        VfxControl *control
    );
    
    // Internal used.
    void changeHandWritingArea(
        VfxControl *control,
        const VfxPenStrokeHandWritingRegion *areas,
        VfxU32 areaCount,
        const VfxPenStrokeHandWritingRegion *extArea
    );
    
    // Internal used.
    void changeHandWritingAreaEx(
        VfxControl *control,
        const VfxPenStrokeHandWritingRegion *areas,
        VfxU32 areaCount,
        const VfxPenStrokeHandWritingRegion *extArea
    );
    
    // Internal used. Dispatch a given stroke pen event.
    VfxBool processStrokeInput(
        const VfxPenDeviceInfo &penStatus   // [IN] The status of the stroke pen input event
    );

    // Internal used.
    VfxBool isPenDownByFramework();

// Override
protected:
    virtual vrt_allocator_handle getAllocator();

// Implementation
private:
    enum
    {
        EVENT_QUEUE_COUNT = 3
    };

    // Current pen input sub-system state
    VfxPenStateEnum m_state;

    // Pointer to captured control
    VfxControlWeakPtr m_capturedControlPtr;
    VfxControlWeakPtr m_hitControl;

    // Event queue, 0 is the current pen event
    VfxPenEventTypeEnum m_curEventType;
    VfxU16   m_curEventPressure;
    VfxMsec  m_eventTimeStamp[EVENT_QUEUE_COUNT];
    VfxPoint m_eventPos[EVENT_QUEUE_COUNT];

    // Pluto event queue, for pen up position prediction
    VfxMsec  m_hwEventTimeStamp[EVENT_QUEUE_COUNT];
    VfxPoint m_hwEventPos[EVENT_QUEUE_COUNT];
    VfxPoint m_predictPos;

    VfxMsec  m_downTimeStamp;
    VfxPoint m_downPos;

    // Timer for long lap
    VfxTimer *m_longTapTimer;

    // Flag if in delayed event mode
    VfxBool             m_delayed;
    VfxControlWeakPtr   m_delayedControl;
    VfxObjList          m_delayedList;


    void updatePenStatus(
        const VfxPenDeviceInfo &penStatus
    );

    // Handle the long tap timer
    void onLongTapTimerTick(VfxTimer *source);

    // Intialize a event structure
    void initPenEvent(
        VfxPenEvent &event,             // [OUT]    the event to be initialized
        VfxControl *targetControl       // [IN]     the target control of the pen event
    );

    VfxControl *findHitControl(
        const VfxPoint &pos
    );

    void makeRoutingList(
        VfxObjList &list,
        VfxControl *control
    );

    VfxControl *routePenEvent(
        VfxPenEvent &event,
        VfxControl *from = NULL,
        VfxBool previewOnly = VFX_FALSE
    );

    void doSendPenAbort(VfxMsec timeStamp, VfxPoint pos);
    void doSendPenDown(VfxMsec timeStamp, VfxPoint downPos, VfxBool withPenUp, VfxPoint upPos);
    void doSendPenUp(VfxMsec timeStamp, VfxPoint pos);

    // Stroke pen input event
    VfxControlWeakPtr m_strokeControlPtr;    
    VfxBool m_isStrokeTranslate;

// Multi-touch
public:
    void setTouchMode(VfxPenTouchModeEnum mode);
    VfxPenTouchModeEnum getTouchMode();

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
public:
    VfxBool processMultiPenInput(VfxPenEvent &event);

private:
    void initMultiPenEvent(VfxPenEvent &event, VfxControl *targetControl);
    void processAfterMultiPenInput(VfxPenEventTypeEnum eventType, VfxPenEvent &event, VfxControl *handledControl);

private:
    class VfxPenMultiTouchPoint
    {
    public:
        VfxS16              id;
        VfxPenEventTypeEnum type;
        VfxMsec             timeStamp;
        VfxPoint            pos;
    };
    VfxPenMultiTouchPoint m_event[VFX_PEN_MULTI_TOUCH_MAX_FINGER];
#endif /* defined(__TOUCH_PANEL_CAPACITY__) */
};

#endif /* __VFX_CONTROL_H__ */

