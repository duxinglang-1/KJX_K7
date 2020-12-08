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
 *  vfx_pen.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_pen.h"

#include "vfx_input_event.h"
#include "vfx_frame.h"
#include "vfx_renderer.h"
#include "vfx_top_level.h"
#include "vfx_timer.h"
#include "vfx_control.h"
#include "vfx_mmi.h"

#include "vfx_basic_type.h"
#include "vrt_system.h"
#include "vfx_object.h"
#include "vfx_config.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_system.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_object_list.h"

#include "vadp_sys_trc.h"

extern "C"
{
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_cb_mgr_gprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

extern "C"
{
#include "vrt_logger_rsp_time.h"
}


/***************************************************************************** 
 * Local Functions
 *****************************************************************************/

// TODO: Check if need to move to adapation layer
#ifdef __MMI_TOUCH_SCREEN__

#define VFX_PEN_LONG_TAP_TIME           (MMI_PEN_LONGTAP_TIME * 10)

VfxBool g_vfxPenEnabled = VFX_FALSE;


static VfxPenEventTypeEnum vfxPenTranslateType(mmi_pen_event_type_enum type)
{
    switch (type)
    {
        case MMI_PEN_EVENT_DOWN:
            return VFX_PEN_EVENT_TYPE_DOWN;

        case MMI_PEN_EVENT_UP:
            return VFX_PEN_EVENT_TYPE_UP;

        case MMI_PEN_EVENT_MOVE:
            return VFX_PEN_EVENT_TYPE_MOVE;

        case MMI_PEN_EVENT_ABORT:
            return VFX_PEN_EVENT_TYPE_ABORT;
    }

    return VFX_PEN_EVENT_TYPE_UNKNOWN;
}


static VfxBool vfxPenProcessPenInput(VfxPenDeviceInfo &penStatus)
{
    vfx_mmi_before_process_msg();

    VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);

    // NOTE: Pen touch enhancement - pen up position prediect
    pen->predictPenInput(penStatus);

    VfxBool ret = pen->processPenInput(penStatus);
    if (ret)
    {
        // Force commit if the pen event has been handled
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
    }
    
    return ret;
}


static VfxBool vfxPenHandleSingleTouchMode(const mmi_multi_touch_event_struct *evt)
{
    static VfxBool isPenDownCaptured = VFX_FALSE;

    const mmi_touch_data_struct &touchData = evt->touch_data[0];
    U32 timeStampTick = touchData.currpos.timestamp;    

    VfxPenDeviceInfo penStatus;
    penStatus.timeStamp = kal_ticks_to_milli_secs(timeStampTick);
    penStatus.pos       = VfxPoint(touchData.currpos.pos.x, touchData.currpos.pos.y);
    penStatus.eventType = vfxPenTranslateType(touchData.event);
    penStatus.pressure  = touchData.area;
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_UNKNOWN)
    {
        // Ignore unsupport event types
        return isPenDownCaptured;
    }

#ifdef __MTK_TARGET__
    // Handle abort type
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        mmi_pen_abort_type_enum abortType = mmi_pen_get_pen_abort_type();
        if (abortType == MMI_PEN_ABORT_TYPE_DRVQ_FULL)
        {
            penStatus.eventType = VFX_PEN_EVENT_TYPE_UP;
        }
    }
#endif /* __MTK_TARGET__ */

    // Log before process
    switch (penStatus.eventType)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            VfxRendererProfiling::reset();
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPD", SA_start);
#endif
            break;
        case VFX_PEN_EVENT_TYPE_MOVE:
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPM", SA_start);
#endif
            break;
        case VFX_PEN_EVENT_TYPE_UP:
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPU", SA_start);
#endif
            break;
    }

    // Process
    VfxBool isHandled = vfxPenProcessPenInput(penStatus);    

    // Log after process
    switch (penStatus.eventType)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPD", SA_stop);
            break;
#endif
        case VFX_PEN_EVENT_TYPE_MOVE:
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPM", SA_stop);
#endif
            break;
        case VFX_PEN_EVENT_TYPE_UP:
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XPU", SA_stop);
#endif
            break;
    }

    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        isPenDownCaptured = isHandled;
    }
    else if (penStatus.eventType == VFX_PEN_EVENT_TYPE_UP || 
        penStatus.eventType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        isPenDownCaptured = VFX_FALSE;
    }

    return isPenDownCaptured;
}


#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
static VfxBool vfxPenProcessMultiPenInput(VfxPenEvent& event)
{
    vfx_mmi_before_process_msg();

    VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
    VfxBool ret = pen->processMultiPenInput(event);

    return ret;
}
#endif /* defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__) */


static VfxBool vfxPenHandleMultiTouchMode(const mmi_multi_touch_event_struct *evt)
{
    VfxBool isHandled = VFX_FALSE;
    
#if (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && defined(__MTK_TARGET__)
    // Prepare event
    VfxPenEvent event;
    event.type = vfxPenTranslateType(evt->main_point.event);
    event.pos.x = evt->main_point.currpos.pos.x;
    event.pos.y = evt->main_point.currpos.pos.y;
    event.predictPos = event.pos;

    // Get multi touch data
    event.touchCount = evt->touch_num;

    VfxU16 mergeCount = 0;
    VfxU8 i;
    for (i = 0; i < event.touchCount; i++)
    {
        event.touchEvents[i].id = evt->touch_data[i].id;
        event.touchEvents[i].type = vfxPenTranslateType(evt->touch_data[i].event);
//            event.touchEvents[i].prevType = vfxPenTranslateType(evt->touch_data[i].pre_event);

        // current position
        mmi_touch_pos_struct point = evt->touch_data[i].currpos;
        if (evt->touch_data[i].event == MMI_PEN_EVENT_MOVE && evt->touch_data[i].merge_num > mergeCount)
        {
            mergeCount = evt->touch_data[i].merge_num;
        }
        event.touchEvents[i].timeStamp = kal_ticks_to_milli_secs(point.timestamp);
        event.touchEvents[i].pos.x = point.pos.x;
        event.touchEvents[i].pos.y = point.pos.y;

        // previous position
        //point = evt->touch_data[i].pre_pos;
        //event.touchEvents[i].prevTimeStamp = point.timestamp;
        //event.touchEvents[i].prevPos.x = point.pos.x;
        //event.touchEvents[i].prevPos.y = point.pos.y;

        // down position
        point = evt->touch_data[i].down_pos;
        event.touchEvents[i].downTimeStamp = kal_ticks_to_milli_secs(point.timestamp);
        event.touchEvents[i].downPos.x = point.pos.x;
        event.touchEvents[i].downPos.y = point.pos.y;
    }

    isHandled = vfxPenProcessMultiPenInput(event);

    // send all merged points
    VfxU8 j;
    for (j = 0; j < mergeCount; j++)
    {
        for (i = 0; i < event.touchCount; i++)
        {
            // only send move events here
            if (event.touchEvents[i].type != VFX_PEN_EVENT_TYPE_MOVE || evt->touch_data[i].merge_num <= j)
            {
                event.touchEvents[i].type = VFX_PEN_EVENT_TYPE_UNKNOWN;
                continue;
            }
            
            mmi_touch_pos_struct currpos = evt->touch_data[i].merge_points[j];

            //event.touchEvents[i].prevType = VFX_PEN_EVENT_TYPE_MOVE;
            //event.touchEvents[i].prevTimeStamp = event.touchEvents[i].timeStamp;
            //event.touchEvents[i].prevPos.x = event.touchEvents[i].pos.x;
            //event.touchEvents[i].prevPos.y = event.touchEvents[i].pos.y;

            event.touchEvents[i].timeStamp = kal_ticks_to_milli_secs(currpos.timestamp);
            event.touchEvents[i].pos.x = currpos.pos.x;
            event.touchEvents[i].pos.y = currpos.pos.y;
        }

        vfxPenProcessMultiPenInput(event);
    }
#endif // (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && defined(__MTK_TARGET__)

    return isHandled;
}


static mmi_ret vfxPenPrePenEventProc(mmi_event_struct *param)
{
    if (!g_vfxPenEnabled)
    {
        return MMI_RET_OK;
    }

    mmi_multi_touch_event_struct *evt = (mmi_multi_touch_event_struct *)param;
    VFX_DEV_ASSERT(evt != NULL);
    
    VfxBool isHandled = VFX_FALSE;
    mmi_frm_touch_mode mode = mmi_frm_touch_get_mode();

    // Response time utility starts
    static VfxBool vfx_log_rsp_time_event_pen_first_move = VFX_TRUE;
    switch(evt->main_point.event)
    {
        case MMI_PEN_EVENT_DOWN:
        {
            /* vrt_log_rsp_time_logging_var(3001); */
            vrt_log_rsp_time_set_event(VRT_LOG_RSP_TIME_EVENT_PEN_DOWN);
            break;
        }
        case MMI_PEN_EVENT_MOVE:
        {
            if(vfx_log_rsp_time_event_pen_first_move)
            {
                /* vrt_log_rsp_time_logging_var(3002); */
                vrt_log_rsp_time_set_event(VRT_LOG_RSP_TIME_EVENT_PEN_FIRST_MOVE);
                vfx_log_rsp_time_event_pen_first_move = VFX_FALSE;
            }
            /*
            else
            {
                vrt_log_rsp_time_logging_var(3005);
            }
            */
            break;
        }
        case MMI_PEN_EVENT_UP:
        {
            /* vrt_log_rsp_time_logging_var(3003); */
            vrt_log_rsp_time_set_event(VRT_LOG_RSP_TIME_EVENT_PEN_UP);
            vfx_log_rsp_time_event_pen_first_move = VFX_TRUE;
            break;
        }
        default:
            break;
    }
    // Response time utility completes
    
    switch (mode)
    {
        case MMI_FRM_SINGLE_TOUCH:
            isHandled = vfxPenHandleSingleTouchMode(evt);
            break;
        case MMI_FRM_MULTI_TOUCH:
            isHandled = vfxPenHandleMultiTouchMode(evt);
            break;
        default:
            VFX_ASSERT(0);
            break;
    }

    if (isHandled)
    {
        return MMI_RET_STOP_TOUCH_HANDLE;
    }
    
    return MMI_RET_OK;
}


static void vfxPenProcessStrokeInput(VfxPenEventTypeEnum eventType, const VfxPoint &pos)
{
    vfx_mmi_before_process_msg();

    VfxPenDeviceInfo penStatus;
    penStatus.timeStamp = VfxTimer::getCurrentSystemTime();
    penStatus.pos       = pos;
    penStatus.eventType = eventType;
    penStatus.pressure  = 0;

    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    penSrv->processStrokeInput(penStatus);
}


static void vfxPenOnStrokeDown(mmi_pen_point_struct pos)
{
    vfxPenProcessStrokeInput(VFX_PEN_EVENT_TYPE_STROKE_DOWN, VfxPoint(pos.x, pos.y));
}


static void vfxPenOnStrokeMove(mmi_pen_point_struct pos)
{
    vfxPenProcessStrokeInput(VFX_PEN_EVENT_TYPE_STROKE_MOVE, VfxPoint(pos.x, pos.y));
}


static void vfxPenOnStrokeUp(mmi_pen_point_struct pos)
{
    vfxPenProcessStrokeInput(VFX_PEN_EVENT_TYPE_STROKE_UP, VfxPoint(pos.x, pos.y));
}


static void vfxPenRegisterPenEvents()
{
    VfxU32 samplingMsec = 1000 / vrt_sys_get_fps(VRT_SYS_DISPLAY_MAIN_LCD);
    VfxU32 samplingPeriod = vfxMax(samplingMsec / 10, (VfxU32)1);

    mmi_pen_config_sampling_period(
        samplingPeriod,
        MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_move_offset(
        VFX_SYS_PEN_SKIP_MOVE_OFFSET,
        VFX_SYS_PEN_SKIP_MOVE_OFFSET,
        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET,
        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET);
    
    if (!mmi_frm_cb_has_event_reg(EVT_ID_PRE_TOUCH_EVT_ROUTING, vfxPenPrePenEventProc, NULL))
    {
        mmi_frm_cb_reg_event(EVT_ID_PRE_TOUCH_EVT_ROUTING, vfxPenPrePenEventProc, NULL);
    }
    
    g_vfxPenEnabled = VFX_TRUE;

    mmi_pen_register_stroke_down_handler(vfxPenOnStrokeDown);
    mmi_pen_register_stroke_move_handler(vfxPenOnStrokeMove);
    mmi_pen_register_stroke_up_handler(vfxPenOnStrokeUp);    
}


static void vfxPenUnregisterPenEvents()
{
    mmi_pen_register_stroke_down_handler(NULL);
    mmi_pen_register_stroke_move_handler(NULL);
    mmi_pen_register_stroke_up_handler(NULL);    

    //mmi_frm_cb_dereg_event(EVT_ID_PRE_TOUCH_EVT_ROUTING, vfxPenPrePenEventProc, NULL);
    // Can't dereg the event!!!
    g_vfxPenEnabled = VFX_FALSE;

    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);

    mmi_pen_config_sampling_period(
        MMI_PEN_SAMPLING_PERIOD_1, 
        MMI_PEN_SAMPLING_PERIOD_2);
}


static void vfxPenReset()
{
    mmi_pen_reset();
}


static void vfxPenStartCaptureStrokes(
    VfxPenStrokePoint *points,
    VfxU32 maxPointCount,
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea
)
{
    mmi_pen_start_capture_strokes(
        maxPointCount,
        (mmi_pen_point_struct *)points,
        areaCount,
        (const mmi_pen_handwriting_area_struct *)areas,
        (const mmi_pen_handwriting_area_struct *)extArea);        
}


static void vfxPenStopCaptureStrokes()
{
    mmi_pen_stop_capture_strokes();
}


static void vfxPenBeginStrokesOfCharacter()
{
    mmi_pen_begin_strokes_of_character();
}

    
static void vfxPenEndStrokesOfCharacter()
{
    mmi_pen_end_strokes_of_character();
}


static void vfxPenChangeHandWritingArea(
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    mmi_pen_change_handwriting_area(
        areaCount, 
        (const mmi_pen_handwriting_area_struct *)areas, 
        (const mmi_pen_handwriting_area_struct *)extArea);
}


static void vfxPenChangeHandWritingAreaEx(
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    mmi_pen_change_handwriting_area_ex(
        areaCount, 
        (const mmi_pen_handwriting_area_struct *)areas, 
        (const mmi_pen_handwriting_area_struct *)extArea);
}


static VfxBool vfxPenIsPenDownByFramework()
{
    return mmi_pen_is_sw_pen_down() == MMI_TRUE;
}

#else // __MMI_TOUCH_SCREEN__

#define VFX_PEN_LONG_TAP_TIME           (600)


static void vfxPenRegisterPenEvents()
{
    // Do nothing
}


static void vfxPenUnregisterPenEvents()
{
    // Do nothing
}


static void vfxPenStartCaptureStrokes(
    VfxPenStrokePoint *points,
    VfxU32 maxPointCount,
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea
)
{
    // Do nothing
}


static void vfxPenReset()
{
    // Do nothing
}


static void vfxPenStopCaptureStrokes()
{
    // Do nothing
}


static void vfxPenBeginStrokesOfCharacter()
{
    // Do nothing
}

    
static void vfxPenEndStrokesOfCharacter()
{
    // Do nothing
}


static void vfxPenChangeHandWritingArea(
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    // Do nothing
}


static void vfxPenChangeHandWritingAreaEx(
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    // Do nothing
}


static VfxBool vfxPenIsPenDownByFramework()
{
    return VFX_FALSE;
}

#endif // __MMI_TOUCH_SCREEN__


/***************************************************************************** 
 * Class VfxPen
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_PEN_CLASS_NAME, VfxPen, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxPen);


VfxPen::VfxPen() :
    m_state(VFX_PEN_STATE_UNKNOWN),
    m_capturedControlPtr(NULL),
    m_curEventType(VFX_PEN_EVENT_TYPE_UNKNOWN),
    m_curEventPressure(0),
    m_downTimeStamp(0),
    m_longTapTimer(NULL),
    m_delayed(VFX_FALSE),
    m_isStrokeTranslate(VFX_FALSE)
{
    // Init all timestamp
    VfxS32 i;
    for (i = 0; i < EVENT_QUEUE_COUNT; i++)
    {
        m_eventTimeStamp[i] = 0;
        m_hwEventTimeStamp[i] = 0;
    }
#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
    for (i = 0; i < VFX_PEN_MULTI_TOUCH_MAX_FINGER; i++)
    {
        m_event[i].id = -1;
    }
#endif
}


vrt_allocator_handle VfxPen::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}


void VfxPen::startup()
{
    VFX_LOG(VFX_INFO, VFX_PEN_STARTUP);
    
    vfxPenRegisterPenEvents();

    // Prepare a timer for long tap
    VFX_DEV_ASSERT(m_longTapTimer == NULL);
    VFX_OBJ_CREATE(m_longTapTimer, VfxTimer, this);
    m_longTapTimer->setStartDelay(VFX_PEN_LONG_TAP_TIME);
    m_longTapTimer->m_signalTick.connect(this, &VfxPen::onLongTapTimerTick);

    m_state = VFX_PEN_STATE_STARTUP;
}


void VfxPen::shutdown()
{
    VFX_LOG(VFX_INFO, VFX_PEN_STUTDOWN);

    // Reset all pointer
    m_capturedControlPtr = NULL;
    m_strokeControlPtr = NULL;
    m_hitControl = NULL;

    // Close timer for long tap
    VFX_OBJ_CLOSE(m_longTapTimer);

    vfxPenUnregisterPenEvents();

    m_state = VFX_PEN_STATE_SHUTDOWN;
}


void VfxPen::reset()
{
    vfxPenReset();
}


VfxBool VfxPen::setCapture(VfxControl *control, VfxPenAbortReasonEnum reason)
{
    if (m_capturedControlPtr == control)
    {
        // Do nothing if the given control is captured already.
        return VFX_TRUE;
    }

    VFX_LOG(VFX_INFO, VFX_PEN_SET_CAPTURE, control, m_curEventType, m_capturedControlPtr.get());

    VfxPenEventTypeEnum eventType = m_curEventType;
    
    // Only can set capture on pen down or pen move
    if (eventType < VFX_PEN_EVENT_TYPE_DOWN ||
        eventType > VFX_PEN_EVENT_TYPE_UP)
    {
        return VFX_FALSE;
    }

    // Query if the abortee accepts capture
    if (m_capturedControlPtr != NULL)
    {
        if (!m_capturedControlPtr->penAbortAccepted(control, reason))
        {
            return VFX_FALSE;
        }
    }

    VfxMsec eventTime = m_eventTimeStamp[0];

    // Send a pen abort if needed
    if (m_capturedControlPtr != NULL)
    {
        VfxPenDeviceInfo penStatus;
        penStatus.timeStamp     = eventTime;
        penStatus.pos           = m_eventPos[0];
        penStatus.eventType     = VFX_PEN_EVENT_TYPE_ABORT;
        penStatus.pressure      = 0;
        updatePenStatus(penStatus);        

        VfxPenEvent event;
        initPenEvent(event, m_capturedControlPtr.get());
        routePenEvent(event);
    }

    m_capturedControlPtr = control;

    // Send a new pen down if needed
    if (m_capturedControlPtr != NULL &&
        eventType != VFX_PEN_EVENT_TYPE_UP)
    {
        VfxPenDeviceInfo penStatus;
        penStatus.timeStamp     = eventTime;
        penStatus.pos           = m_eventPos[0];
        penStatus.eventType     = VFX_PEN_EVENT_TYPE_DOWN;
        penStatus.pressure      = m_curEventPressure;
        updatePenStatus(penStatus);
        
        VfxPenEvent event;
        initPenEvent(event, m_capturedControlPtr.get());
        routePenEvent(event);
    }

    // Stop the long tap timer
    if (m_longTapTimer != NULL)
    {
        m_longTapTimer->stop();
    }

    return VFX_TRUE;
}


VfxBool VfxPen::delayEvent(VfxControl *delayer, VfxPenEvent &event)
{
    VFX_OBJ_ASSERT_VALID(delayer);
    
    VfxObjListEntry *i;
    for (i = event.relObjList.getValidTail(); 
        i != NULL;
        i = i->getValidPrev())
    {
        VfxControl *control = (VfxControl *)i->get();
        if (control == delayer)
        {
            break;
        }
           
        if (!control->penAbortAccepted(
            delayer, 
            VFX_PEN_ABORT_REASON_CAPTURE_SWIPE))
        {
            return VFX_FALSE;
        }
    }
    
    m_delayed = VFX_TRUE;

    return VFX_TRUE;
}


void VfxPen::resumeDelayedEvent()
{
    VfxControl *delayedControl = m_capturedControlPtr.get();
    if (delayedControl == NULL)
    {
        return;
    }

    VfxPenEventTypeEnum eventType = m_curEventType;
    VfxMsec timeStamp = VfxTimer::getCurrentSystemTime();
    VfxPoint pos = m_eventPos[0];
    VfxBool isPenUp = (eventType == VFX_PEN_EVENT_TYPE_UP);

    m_delayedControl = delayedControl;

    // Send pen abort
    vfxPostInvoke2(this, &VfxPen::doSendPenAbort, timeStamp, pos);    
    vfxPostInvoke4(this, &VfxPen::doSendPenDown, timeStamp, m_downPos, isPenUp, pos);
}


void VfxPen::predictPenInput(VfxPenDeviceInfo &penStatus)
{
    VfxMsec timeStamp = penStatus.timeStamp;
    VfxPoint pos = penStatus.pos;

    // Predict
    m_predictPos = pos;
#if defined(__MTK_TARGET__)
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxPoint v1(
            m_hwEventPos[1].x - m_hwEventPos[2].x,
            m_hwEventPos[1].y - m_hwEventPos[2].y);
        VfxPoint v0(
            m_hwEventPos[0].x - m_hwEventPos[1].x,
            m_hwEventPos[0].y - m_hwEventPos[1].y);
        VfxPoint a(v0.x - v1.x, v0.y - v1.y);

        if ((v0.x * a.x + v0.y * a.y) <= 0 && 
            (a.x * a.x + a.y * a.y) >= (v0.x * v0.x + v0.y * v0.y))
        {
            // Do nothing
        }
#if (!defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__))
        else if ((m_hwEventTimeStamp[1] - m_hwEventTimeStamp[2] > VFX_SYS_PEN_SAMPLE_MSEC) ||
                 (m_hwEventTimeStamp[0] - m_hwEventTimeStamp[1] > VFX_SYS_PEN_SAMPLE_MSEC))
        {
            // Do nothing
        }
#endif
        else
        {
            m_predictPos.x += v0.x + a.x;
            m_predictPos.y += v0.y + a.y;
#if (!defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__))
            penStatus.pos = m_predictPos;
#endif
        }
    }
    else if (penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_DOWN)
    {
        // Reset the pen down information
        VfxS32 i;
        for (i = 0; i < EVENT_QUEUE_COUNT; i++)
        {
            m_hwEventPos[i] = pos;
            m_hwEventTimeStamp[i] = timeStamp;
        }
    }
    else
    {
        VfxS32 i;
        for (i = EVENT_QUEUE_COUNT - 1; i >= 1; i--)
        {
            m_hwEventPos[i] = m_hwEventPos[i - 1];
            m_hwEventTimeStamp[i] = m_hwEventTimeStamp[i - 1];
        }

        m_hwEventPos[0] = pos;
        m_hwEventTimeStamp[0] = timeStamp;
    }
#endif
}


VfxBool VfxPen::processPenInput(const VfxPenDeviceInfo &penStatus)
{
    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS, penStatus.timeStamp, penStatus.pos.x, penStatus.pos.y, penStatus.eventType);

    VFX_DEV_ASSERT(
        penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_MOVE ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_UP ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_ABORT);
    
    // Update pen status
    updatePenStatus(penStatus);

    // Setup the target control
    VfxWeakPtr<VfxControl> targetControl;
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        targetControl = findHitControl(penStatus.pos);
    }
    else
    {
        targetControl = m_capturedControlPtr.get();
    }

    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS_TARGET, (void*) &targetControl);

    // Prepare event
    VfxPenEvent event;
    initPenEvent(event, targetControl.get());
    
    // Make and route the event
    VfxControl *handledControl = NULL;
    if (targetControl != NULL)
    {
        handledControl = routePenEvent(event);
    }
    else if (m_hitControl != NULL)
    {
        // Make sure onPreviewPenInput() will receive paired events
        initPenEvent(event, m_hitControl.get());
        handledControl = routePenEvent(event, NULL, VFX_TRUE);
    }

    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_hitControl = targetControl;
    }
    else if (penStatus.eventType == VFX_PEN_EVENT_TYPE_UP || penStatus.eventType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_hitControl = NULL;
    }

    VfxPen::processAfterPenInput(penStatus.eventType, event, handledControl);

    return (handledControl != NULL);
}


void VfxPen::processAfterPenInput(VfxPenEventTypeEnum eventType, VfxPenEvent &event, VfxControl *handledControl)
{
    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS_HANDLED, handledControl);

    VfxControl *capturedControl = m_capturedControlPtr.get();
    
    // Update the captured control
    if (eventType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VFX_LOG(VFX_INFO, VFX_PEN_PROCESS_DOWN, handledControl);

        // Switch handled control to be captured control 
        if (capturedControl == NULL)
        {
            m_capturedControlPtr = handledControl;
        }

        // Stop the long tap timer
        if (m_longTapTimer != NULL)
        {
            m_longTapTimer->start();
        }
    }
    else if (eventType == VFX_PEN_EVENT_TYPE_UP || eventType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        VFX_LOG(VFX_INFO, VFX_PEN_PROCESS_UP, capturedControl);

        // Reset captured control
        m_capturedControlPtr = NULL;

        m_curEventType = VFX_PEN_EVENT_TYPE_UNKNOWN;

        // Stop the long tap timer
        if (m_longTapTimer != NULL)
        {
            m_longTapTimer->stop();
        }
    }

    // Emit signal
    m_signalEventProcessed.emit(event, handledControl);
}


void VfxPen::startCaptureStrokes(
    VfxControl *control,
    VfxPenStrokePoint *points,
    VfxU32 maxPointCount,
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea
)
{
    VFX_LOG(VFX_INFO, VFX_PEN_START_CAPTURE_STROKES, control);
    
    VFX_OBJ_ASSERT_VALID(control);
    VFX_ASSERT(m_strokeControlPtr == NULL);

    m_strokeControlPtr = control;
    vfxPenStartCaptureStrokes(points, maxPointCount, areas, areaCount, extArea);
}


void VfxPen::stopCaptureStrokes(VfxControl *control)
{
    VFX_LOG(VFX_INFO, VFX_PEN_STOP_CAPTURE_STROKES, control);
    
    VFX_OBJ_ASSERT_VALID(control);
    //VFX_ASSERT(m_strokeControlPtr == control);

    vfxPenStopCaptureStrokes();
    
    m_strokeControlPtr = NULL;
}


void VfxPen::beginStrokesOfCharacter(VfxControl *control)
{
    VFX_OBJ_ASSERT_VALID(control);
    VFX_ASSERT(m_strokeControlPtr == control);

    vfxPenBeginStrokesOfCharacter();
}


void VfxPen::endStrokesOfCharacter(VfxControl *control)
{
    VFX_OBJ_ASSERT_VALID(control);
    //VFX_ASSERT(m_strokeControlPtr == control);

    vfxPenEndStrokesOfCharacter();
}


void VfxPen::changeHandWritingArea(
    VfxControl *control,
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    VFX_OBJ_ASSERT_VALID(control);
    VFX_ASSERT(m_strokeControlPtr == control);

    vfxPenChangeHandWritingArea(areas, areaCount, extArea);
}


void VfxPen::changeHandWritingAreaEx(
    VfxControl *control,
    const VfxPenStrokeHandWritingRegion *areas,
    VfxU32 areaCount,
    const VfxPenStrokeHandWritingRegion *extArea)
{
    VFX_OBJ_ASSERT_VALID(control);
    VFX_ASSERT(m_strokeControlPtr == control);

    vfxPenChangeHandWritingAreaEx(areas, areaCount, extArea);
}


VfxBool VfxPen::processStrokeInput(const VfxPenDeviceInfo &penStatus)
{
    VFX_LOG(VFX_INFO, VFX_PEN_PROCESS_STROKE, penStatus.timeStamp, penStatus.pos.x, penStatus.pos.y, penStatus.eventType);
    
    VFX_DEV_ASSERT(
        penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_DOWN ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_MOVE ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_UP);

    VfxBool ret = VFX_FALSE;

    // If stroke down did't hit the registered stroke control, translate the stroke events to pen events
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_DOWN &&
        findHitControl(penStatus.pos) != m_strokeControlPtr.get())
    {
        m_isStrokeTranslate = VFX_TRUE;
    }

    if (!m_isStrokeTranslate)
    {
        // Update pen status
        updatePenStatus(penStatus);

        // Callback VfxControl::onPenInput()
        VfxControl *targetControl = m_strokeControlPtr.get();
        if (targetControl != NULL)
        {
            VfxPenEvent event;
            initPenEvent(event, targetControl);
            ret = m_strokeControlPtr->penInput(event);
        }
    }
    else
    {
        VfxPenDeviceInfo info = penStatus;
        switch (penStatus.eventType)
        {
            case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
                info.eventType = VFX_PEN_EVENT_TYPE_DOWN;
                break;

            case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
                info.eventType = VFX_PEN_EVENT_TYPE_MOVE;
                break;

            case VFX_PEN_EVENT_TYPE_STROKE_UP:
                info.eventType = VFX_PEN_EVENT_TYPE_UP;
                break;

            default:
                info.eventType = VFX_PEN_EVENT_TYPE_UNKNOWN;
        }

        predictPenInput(info);
        ret = processPenInput(info);
    }

    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_UP ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_UP)
    {
        m_isStrokeTranslate = VFX_FALSE;
    }

    return ret;
}


void VfxPen::updatePenStatus(const VfxPenDeviceInfo &penStatus)
{
    VfxMsec timeStamp = penStatus.timeStamp;
    VfxPoint pos = penStatus.pos;
        
    m_curEventType      = penStatus.eventType;
    m_curEventPressure  = penStatus.pressure;
    
    if (penStatus.eventType == VFX_PEN_EVENT_TYPE_DOWN ||
        penStatus.eventType == VFX_PEN_EVENT_TYPE_STROKE_DOWN)
    {
        // Reset the pen down information
        VfxS32 i;
        for (i = 0; i < EVENT_QUEUE_COUNT; i++)
        {
            m_eventTimeStamp[i] = timeStamp;
            m_eventPos[i]       = pos;
        }

        m_downTimeStamp = timeStamp;
        m_downPos       = pos;
    }
    else
    {
        VfxS32 i;
        for (i = EVENT_QUEUE_COUNT - 1; i >= 1; i--)
        {
            m_eventTimeStamp[i] = m_eventTimeStamp[i - 1];
            m_eventPos[i]       = m_eventPos[i - 1];
        }
        
        m_eventTimeStamp[0] = timeStamp;
        m_eventPos[0]       = pos;
    }
}


void VfxPen::onLongTapTimerTick(VfxTimer *source)
{
    // Only callback on pen is still on the screen
    if (m_curEventType != VFX_PEN_EVENT_TYPE_DOWN &&
        m_curEventType != VFX_PEN_EVENT_TYPE_MOVE)
    {
        return;
    }

    // Send a new pen down if needed
    if (m_capturedControlPtr == NULL)
    {
        return;
    }

    // Send a long tap event
    VfxPenDeviceInfo penStatus;
    penStatus.timeStamp     = VfxTimer::getCurrentTime();
    penStatus.pos           = m_eventPos[0];
    penStatus.eventType     = VFX_PEN_EVENT_TYPE_LONG_TAP;
    penStatus.pressure      = m_curEventPressure;
    updatePenStatus(penStatus);
    
    VfxPenEvent event;
    initPenEvent(event, m_capturedControlPtr.get());
    routePenEvent(event);
}


void VfxPen::initPenEvent(VfxPenEvent &event, VfxControl *targetControl)
{
    event.source        = this;
    event.target        = targetControl;
    event.type          = m_curEventType;
    event.timeStamp     = m_eventTimeStamp[0];
    event.prevTimeStamp = m_eventTimeStamp[1];
    event.downTimeStamp = m_downTimeStamp;
    event.pos           = m_eventPos[0];
    event.prevPos       = m_eventPos[1];
    event.downPos       = m_downPos;
    event.predictPos    = m_predictPos;
    event.touchCount    = 0;
    event.pressure      = m_curEventPressure;

    if (targetControl != NULL)
    {
        makeRoutingList(event.relObjList, targetControl);
    }
    else
    {
        event.relObjList.clear();
    }
}


VfxControl *VfxPen::findHitControl(const VfxPoint &pos)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxFrame *rootFrame = renderer->getRootFrame();
    if (rootFrame == NULL)
    {
        return NULL; 
    }

    VfxControl *hitControl = NULL;
    VfxFrame *hitFrame = rootFrame->hitTest(pos, toplevel->isActiveScreenCustomRotate());
    VfxFrame *i;
    for (i = hitFrame; i != NULL; i = i->getParentFrame())
    {
        VfxControl *control = VFX_OBJ_DYNAMIC_CAST(i, VfxControl);
        if (control != NULL)
        {
            hitControl = control;
            break;
        }
    }

    return hitControl;
}


void VfxPen::makeRoutingList(VfxObjList &list, VfxControl *control)
{
    list.clear();

    // Add all parent controls to the rounting list
    VfxControl *i;
    for (i = control; i != NULL; i = i->getParentControl())
    {
        list.prepend(i);
    }
}


VfxControl *VfxPen::routePenEvent(VfxPenEvent &event, VfxControl *from, VfxBool previewOnly)
{
    // Ignore before given control
    VfxBool ignore = (from != NULL);
    
    VfxObjList &list = event.relObjList;
    VfxObjListEntry *i;

    // Preview event
    for (i = list.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxControl *control = (VfxControl *)i->get();

        // Ignore this control if needed
        if (ignore)
        {
            if (control == from)
            {
                ignore = VFX_FALSE;
            }
            continue;
        }

        // If a control is disabled, 
        //  it will always handle the event but do nothing
        if (control->getIsDisabled())
        {
            if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
            {
                return NULL;
            }
            else
            {
                event.type = VFX_PEN_EVENT_TYPE_ABORT;
            }
        }
        
        if (control->previewPenInput(event))
        {
            return control;
        }

        if (m_delayed)
        {
            m_delayed = VFX_FALSE;
            m_delayedList = list;

            return control;
        }
    }

    // All control ignored
    if (ignore)
    {
        return NULL;
    }
    
    if (previewOnly)
    {
        return NULL;
    }

    // input event
    for (i = list.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxControl *control = (VfxControl *)i->get();
        if (control->penInput(event))
        {
            return control;
        }
    }

    return NULL;
}


void VfxPen::doSendPenAbort(VfxMsec timeStamp, VfxPoint pos)
{
    VfxPenDeviceInfo info;
    info.timeStamp  = timeStamp;
    info.pos        = pos;
    info.eventType  = VFX_PEN_EVENT_TYPE_ABORT;   
    info.pressure   = 0;
    processPenInput(info);
}


void VfxPen::doSendPenDown(VfxMsec timeStamp, VfxPoint downPos, VfxBool withPenUp, VfxPoint upPos)
{
    VfxPenDeviceInfo penStatus;
    penStatus.timeStamp     = timeStamp;
    penStatus.pos           = downPos;
    penStatus.eventType     = VFX_PEN_EVENT_TYPE_DOWN;
    penStatus.pressure      = m_curEventPressure;
    updatePenStatus(penStatus);
    
    VfxPenEvent event;
    initPenEvent(event, NULL);
    event.relObjList = m_delayedList;

    VfxControl *delayedControl = m_delayedControl.get();

    // Reset
    m_delayedControl = NULL;
    m_delayedList.clear();
    
    VfxControl *handledControl = routePenEvent(event, delayedControl);

    processAfterPenInput(VFX_PEN_EVENT_TYPE_DOWN, event, handledControl);
            
    if (withPenUp && m_capturedControlPtr != NULL)
    {
        // TODO: review this
        vfx_mmi_update_scene();
        
        vfxPostInvoke2(this, &VfxPen::doSendPenUp, timeStamp, upPos);
        return;
    }
}


void VfxPen::doSendPenUp(VfxMsec timeStamp, VfxPoint pos)
{
    VfxPenDeviceInfo info;
    info.timeStamp  = timeStamp;
    info.pos        = pos;
    info.eventType  = VFX_PEN_EVENT_TYPE_UP;
    info.pressure   = 0;
    processPenInput(info);
}


VfxBool VfxPen::isPenDownByFramework()
{
    return vfxPenIsPenDownByFramework();
}


void VfxPen::setTouchMode(VfxPenTouchModeEnum mode)
{
#if defined (__MTK_TARGET__) && (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__))
    switch (mode)
    {
        case VFX_PEN_TOUCH_MODE_SINGLE_TOUCH:
            mmi_frm_touch_set_mode(MMI_FRM_SINGLE_TOUCH);
            break;

        case VFX_PEN_TOUCH_MODE_MULTI_TOUCH:
            mmi_frm_touch_set_mode(MMI_FRM_MULTI_TOUCH);
            break;

        default:
            VFX_ASSERT(0);
    }
#endif
}


VfxPenTouchModeEnum VfxPen::getTouchMode()
{
#if defined (__MTK_TARGET__) && (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__))
    switch (mmi_frm_touch_get_mode())
    {
        case MMI_FRM_SINGLE_TOUCH:
            return VFX_PEN_TOUCH_MODE_SINGLE_TOUCH;

        case MMI_FRM_MULTI_TOUCH:
            return VFX_PEN_TOUCH_MODE_MULTI_TOUCH;

        default:
            break;
    }

    VFX_ASSERT(0);
    return VFX_PEN_TOUCH_MODE_END_OF_ENUM; // Added only to remove build warning
#else
    return VFX_PEN_TOUCH_MODE_SINGLE_TOUCH;
#endif
}


#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
VfxBool VfxPen::processMultiPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS, event.touchEvents[0].timeStamp, event.touchEvents[0].pos.x, event.touchEvents[0].pos.y, event.touchEvents[0].type + 16);

    // Setup the target control
    VfxControl *targetControl;
    VfxPenEventTypeEnum overallType = VFX_PEN_EVENT_TYPE_UNKNOWN;
    VfxU8 i;

    for (i = 0; i < event.touchCount; i++)
    {
        if (event.touchEvents[i].type != VFX_PEN_EVENT_TYPE_DOWN)
        {
            break;
        }
    }
    if (i == event.touchCount)
    {
        // First down
        overallType = VFX_PEN_EVENT_TYPE_DOWN;
        targetControl = findHitControl(event.pos);
    }
    else
    {
        targetControl = m_capturedControlPtr.get();
    }

    for (i = 0; i < event.touchCount; i++)
    {
        if (event.touchEvents[i].type != VFX_PEN_EVENT_TYPE_UP && event.touchEvents[i].type != VFX_PEN_EVENT_TYPE_ABORT)
        {
            break;
        }
    }
    if (i == event.touchCount)
    {
        // All fingers up
        overallType = VFX_PEN_EVENT_TYPE_UP;
    }

    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS_TARGET, targetControl);

    // backward compatibility
    //event.type          = event.touchEvents[0].type;
    //event.pos           = event.touchEvents[0].pos;
    //event.predictPos    = event.touchEvents[0].pos;
    event.timeStamp     = event.touchEvents[0].timeStamp;

    VfxPenDeviceInfo penStatus;
    penStatus.eventType = event.type;
    penStatus.pos = event.pos;
    penStatus.timeStamp = event.timeStamp;
    penStatus.pressure  = event.pressure;
    updatePenStatus(penStatus);
    event.prevPos       = m_eventPos[1];
    event.prevTimeStamp = m_eventTimeStamp[1];
    event.downPos       = m_downPos;
    event.downTimeStamp = m_downTimeStamp;

    // Prepare event
    initMultiPenEvent(event, targetControl);

    // Make and route the event
    VfxControl *handledControl = NULL;
    if (targetControl != NULL)
    {
        handledControl = routePenEvent(event);
    }

    VfxPen::processAfterMultiPenInput(overallType, event, handledControl);

    return (handledControl != NULL);
}


void VfxPen::processAfterMultiPenInput(VfxPenEventTypeEnum eventType, VfxPenEvent &event, VfxControl *handledControl)
{
    VFX_LOG(VFX_INFO3, VFX_PEN_PROCESS_HANDLED, handledControl);

    VfxControl *capturedControl = m_capturedControlPtr.get();

    // Update the captured control
    if (eventType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VFX_LOG(VFX_INFO, VFX_PEN_PROCESS_DOWN, handledControl);

        // Switch handled control to be captured control 
        if (capturedControl == NULL)
        {
            m_capturedControlPtr = handledControl;
        }
    }
    else if (eventType == VFX_PEN_EVENT_TYPE_UP || eventType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        VFX_LOG(VFX_INFO, VFX_PEN_PROCESS_UP, capturedControl);

        // Reset captured control
        m_capturedControlPtr = NULL;

        m_curEventType = VFX_PEN_EVENT_TYPE_UNKNOWN;
    }

    // Emit signal
    m_signalEventProcessed.emit(event, handledControl);
}


void VfxPen::initMultiPenEvent(VfxPenEvent &event, VfxControl *targetControl)
{
    VfxU8 i, j;

    event.source        = this;
    event.target        = targetControl;

    if (targetControl != NULL)
    {
        makeRoutingList(event.relObjList, targetControl);
    }
    else
    {
        event.relObjList.clear();
    }

    // handle previous postion
    for (i = 0; i < event.touchCount; i++)
    {
        VfxTouchEvent* evt = &event.touchEvents[i];

        if (evt->type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            for (j = 0; j < VFX_PEN_MULTI_TOUCH_MAX_FINGER; j++)
            {
                if (m_event[j].id == -1)
                {
                    evt->prevType = evt->type;
                    evt->prevPos = evt->pos;
                    evt->prevTimeStamp = evt->timeStamp;

                    m_event[j].id = evt->id;
                    m_event[j].type = evt->type;
                    m_event[j].pos = evt->pos;
                    m_event[j].timeStamp = evt->timeStamp;
                    break;
                }
            }
        }
        else
        {
            for (j = 0; j < VFX_PEN_MULTI_TOUCH_MAX_FINGER; j++)
            {
                if (m_event[j].id == evt->id)
                {
                    evt->prevType = m_event[j].type;
                    evt->prevPos = m_event[j].pos;
                    evt->prevTimeStamp = m_event[j].timeStamp;

                    if (evt->type == VFX_PEN_EVENT_TYPE_UP || evt->type == VFX_PEN_EVENT_TYPE_ABORT)
                    {
                        m_event[j].id = -1;
                    }
                    else if (evt->type == VFX_PEN_EVENT_TYPE_MOVE)
                    {
                        m_event[j].type = evt->type;
                        m_event[j].pos = evt->pos;
                        m_event[j].timeStamp = evt->timeStamp;
                    }
                    break;
                }
            }
        }
    }
}

#endif /* defined(__TOUCH_PANEL_CAPACITY__) */

