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
 *  vfx_animation.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 * removed!
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

#include "vfx_animation.h"

#include "vfx_timer.h"
#include "vfx_animatable.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_canvas.h"
#include "vfx_sys_memory.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_object_list.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_stream.h"
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define VFX_TIMELINE_PROP_ID_TTIME_REF      0x10300
#define VFX_TIMELINE_PROP_ID_TTIME_REFER    0x10301
#define VFX_TIMELINE_PROP_ID_VARIABLE       0x10302


/***************************************************************************** 
 * Class VfxBaseTimeline 
 *****************************************************************************/
 
VFX_IMPLEMENT_VIRTUAL_CLASS(VFX_BASE_TIMELINE_CLASS_NAME, VfxBaseTimeline, VfxObject);

 
VfxBaseTimeline::VfxBaseTimeline(vrt_type_id_enum target_type) :
    m_timelineState(VFX_TIMELINE_STATE_STOP),
    m_timelineHandle(NULL),
    m_enabledObject(NULL),
    m_enabledTimelineEntryPrev(NULL),
    m_enabledTimelineEntryNext(NULL),
    m_targetPtr(NULL),
    m_targetType(target_type),
    m_targetPropertyId(VRT_OBJECT_PROPERTY_ID_UNKNOWN),
    m_startTime(0),
    m_durationTime(0),
    m_updateDuration(0),
    m_repeatDuration(0),
    m_repeatCount(1),
    m_timelineFlags(FLAGS_DEFAULT),
    m_customTimingCallback(NULL),
    m_customInterpolateCallback(NULL),
    m_startTimer(NULL),
    m_stopTimer(NULL)
{
}


VfxBool VfxBaseTimeline::getAutoReversed() const
{
    return VFX_FLAG_HAS(m_timelineFlags, FLAGS_AUTO_REVERSED);
}


VfxBool VfxBaseTimeline::getIsFromCurrent() const
{
    return VFX_FLAG_HAS(m_timelineFlags, FLAGS_FROM_CURRENT);
}


VfxBool VfxBaseTimeline::getHasByValue() const
{
    return VFX_FLAG_HAS(m_timelineFlags, FLAGS_TO_STEP);
}


void VfxBaseTimeline::setAutoReversed(VfxBool value)
{
    if (value)
    {
        VFX_FLAG_SET(m_timelineFlags, FLAGS_AUTO_REVERSED);
    }
    else
    {
        VFX_FLAG_CLEAR(m_timelineFlags, FLAGS_AUTO_REVERSED);
    }
}


void VfxBaseTimeline::setIsFromCurrent(VfxBool value)
{
    if (value)
    {
        VFX_FLAG_SET(m_timelineFlags, FLAGS_FROM_CURRENT);
    }
    else
    {
        VFX_FLAG_CLEAR(m_timelineFlags, FLAGS_FROM_CURRENT);
    }
}


void VfxBaseTimeline::setHasByValue(VfxBool value)
{
    if (value)
    {
        VFX_FLAG_SET(m_timelineFlags, FLAGS_TO_STEP);
    }
    else
    {
        VFX_FLAG_CLEAR(m_timelineFlags, FLAGS_TO_STEP);
    }
}


VfxBool VfxBaseTimeline::getIsEnabled() const
{
    return m_timelineState == VFX_TIMELINE_STATE_RUNNING;
}


VfxAnimatable *VfxBaseTimeline::getTarget() const
{
    return m_targetPtr.get();
}


void VfxBaseTimeline::setTarget(VfxAnimatable *value)
{
    VFX_OBJ_ASSERT_VALID(value);        
    m_targetPtr = value;
}


vrt_object_property_id_enum VfxBaseTimeline::getTargetPropertyId() const
{
    VFX_ASSERT(m_targetPropertyId != VRT_OBJECT_PROPERTY_ID_UNKNOWN && m_targetPropertyId < VRT_OBJECT_PROPERTY_ID_END_OF_ENUM);
    return m_targetPropertyId;
}


void VfxBaseTimeline::setTargetPropertyId(vrt_object_property_id_enum value)
{
    m_targetPropertyId = value;
}


void VfxBaseTimeline::setTimingFunc(VfxTimingFuncIdEnum value)
{
    VFX_ASSERT(value < VFX_TIMING_FUNC_ID_END_OF_ENUM);

    const vrt_timeline_timing_callback_struct *callback = 
        vrt_timeline_get_predefined_timing_func((vrt_timing_func_id_enum)value);

    // Free the original callback structure
    VFX_FREE_MEM(m_customTimingCallback);

    if (callback != NULL)
    {
        VfxU32 structSize = VRT_CALLBACK_STRUCT_PTR_SIZE(callback);
        VFX_DEV_ASSERT(structSize != 0);
        
        VFX_ALLOC_MEM(m_customTimingCallback, structSize, this);
        memcpy(m_customTimingCallback, callback, structSize);
    }
}


void VfxBaseTimeline::setCustomTimingFunc(VfxTimelineTimingFuncPtr callback, const void *userData, VfxU32 userDataSize)
{
    // Free the original callback structure
    VFX_FREE_MEM(m_customTimingCallback);

    m_customTimingCallback = createTimingCallback(
        callback, 
        userData, 
        userDataSize);
}


void VfxBaseTimeline::setCustomInterpolateFunc(VfxTimelineInterpolateFuncPtr callback, const void *userData, VfxU32 userDataSize)
{
    // Free the original callback structure
    VFX_FREE_MEM(m_customInterpolateCallback);

    m_customInterpolateCallback = createInterpolateCallback(
        callback, 
        userData, 
        userDataSize);
}


void VfxBaseTimeline::setTimelineTime(
    VfxBaseTimeline *time, 
    VfxFloat scale, 
    VfxFloat bias,
    VfxTimelineTimeWrapTypeEnum wrapType)
{
    if (time != NULL)
    {
        VFX_DEV_ASSERT(
            time->getTargetPropertyId() >= VRT_CUSTOM_PROPERTY_ID_BEGIN &&
            time->getTargetPropertyId() < VRT_CUSTOM_PROPERTY_ID_END_OF_ENUM);
    }

    removeFromTimelineTimeReference();

    if (time == NULL)
    {
        stopThisAndAllReferers(VFX_FALSE);
        return;
    }

    time->addTimelineTimeReferrer(this, scale, bias, wrapType);

    if (time->getIsEnabled())
    {
        startThisAndAllReferers();
    }
    else
    {
        stopThisAndAllReferers(VFX_FALSE);
    }
}


void VfxBaseTimeline::addTimelineTimeReferrer(
    VfxBaseTimeline *referrer, 
    VfxFloat scale, 
    VfxFloat bias,
    VfxTimelineTimeWrapTypeEnum wrapType)
{
    VFX_DEV_ASSERT(referrer != NULL);

    TimelineTimeReferenceData *refData = 
        (TimelineTimeReferenceData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REF, 
            sizeof(TimelineTimeReferenceData));
    
    TimelineTimeReferrerData refer;
    refer.target = this;
    refer.bias = bias;
    refer.scale = scale;
    refer.wrapType = wrapType;
    refer.next = NULL;
    refer.prev = (refData == NULL) ? NULL : refData->referrerTail;
    referrer->setAttachProperty(VFX_TIMELINE_PROP_ID_TTIME_REFER, &refer, sizeof(refer));

    if (refData != NULL)
    {
        TimelineTimeReferrerData *prevData = 
            (TimelineTimeReferrerData *)refData->referrerTail->getAttachProperty(
                VFX_TIMELINE_PROP_ID_TTIME_REFER,
                sizeof(TimelineTimeReferrerData));
        VFX_DEV_ASSERT(prevData != NULL);
        prevData->next = referrer;
    }
    
    TimelineTimeReferenceData ref;
    ref.referrerFirst = (refData == NULL) ? referrer : refData->referrerFirst;
    ref.referrerTail = referrer;
    setAttachProperty(VFX_TIMELINE_PROP_ID_TTIME_REF, &ref, sizeof(TimelineTimeReferenceData));
}


void VfxBaseTimeline::removeFromTimelineTimeReference()
{
    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER, 
            sizeof(TimelineTimeReferrerData));
    if (referData == NULL)
    {
        return;
    }

    VfxBaseTimeline *target = referData->target;
    VFX_DEV_ASSERT(target != NULL);
    
    TimelineTimeReferenceData *refData = 
        (TimelineTimeReferenceData *)target->getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REF, 
            sizeof(TimelineTimeReferenceData));
    VFX_DEV_ASSERT(refData != NULL);

    if (refData->referrerFirst == this)
    {
        refData->referrerFirst = referData->next;
    }

    if (refData->referrerTail == this)
    {
        refData->referrerTail = referData->prev;
    }

    if (referData->prev != NULL)
    {
        TimelineTimeReferrerData *prevData = 
            (TimelineTimeReferrerData *)referData->prev->getAttachProperty(
                VFX_TIMELINE_PROP_ID_TTIME_REFER,
                sizeof(TimelineTimeReferrerData));
        VFX_DEV_ASSERT(prevData != NULL);
        prevData->next = referData->next;
    }
    
    if (referData->next != NULL)
    {
        TimelineTimeReferrerData *nextData = 
            (TimelineTimeReferrerData *)referData->next->getAttachProperty(
                VFX_TIMELINE_PROP_ID_TTIME_REFER,
                sizeof(TimelineTimeReferrerData));
        VFX_DEV_ASSERT(nextData != NULL);
        nextData->prev = referData->prev;
    }

    setAttachProperty(VFX_TIMELINE_PROP_ID_TTIME_REFER, NULL, 0);

    if (refData->referrerFirst == NULL)
    {
        VFX_DEV_ASSERT(refData->referrerTail == NULL);
        target->setAttachProperty(VFX_TIMELINE_PROP_ID_TTIME_REF, NULL, 0);
    }
}


void VfxBaseTimeline::removeAllTimelineTimeReferrer()
{
    TimelineTimeReferenceData *refData = 
        (TimelineTimeReferenceData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REF, 
            sizeof(TimelineTimeReferenceData));
    if (refData == NULL)
    {
        return;
    }

    VfxBaseTimeline *referrer = refData->referrerTail;
    while (referrer != NULL)
    {
        TimelineTimeReferrerData *referData = 
            (TimelineTimeReferrerData *)referrer->getAttachProperty(
                VFX_TIMELINE_PROP_ID_TTIME_REFER,
                sizeof(TimelineTimeReferrerData));
        VFX_DEV_ASSERT(referData != NULL);
        
        VfxBaseTimeline *prev = referData->prev;

        referrer->setAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER,
            NULL,
            0);

        referrer = prev;
    }

    setAttachProperty(VFX_TIMELINE_PROP_ID_TTIME_REF, NULL, 0);
}


void VfxBaseTimeline::start()
{
    // Method start() only do state checking, 
    //  the really work is in startThisAndAllReferers()
    
    // Check the target settings
    VFX_ASSERT(m_targetPtr != NULL);
    VFX_ASSERT(m_targetType != VFX_TYPE_ID_UNKNOWN && m_targetType < VFX_TYPE_ID_END_OF_ENUM);
    VFX_ASSERT(m_targetPropertyId != VRT_OBJECT_PROPERTY_ID_UNKNOWN && m_targetPropertyId < VRT_OBJECT_PROPERTY_ID_END_OF_ENUM);

    // NOTE: Do not start a timeline that has timeline time
    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER,
            sizeof(TimelineTimeReferrerData));
    VFX_ASSERT(referData == NULL);

    startThisAndAllReferers();
}


void VfxBaseTimeline::startThisAndAllReferers()
{
    /*
     * Start this timeline
     */
    processStart();

    /*
     * Start all referer timelines
     */
    TimelineTimeReferenceData *refData = 
        (TimelineTimeReferenceData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REF, 
            sizeof(TimelineTimeReferenceData));
    if (refData != NULL)
    {
        VfxBaseTimeline *referrer = refData->referrerFirst;
        while (referrer != NULL)
        {
            TimelineTimeReferrerData *referData = 
                (TimelineTimeReferrerData *)referrer->getAttachProperty(
                    VFX_TIMELINE_PROP_ID_TTIME_REFER,
                    sizeof(TimelineTimeReferrerData));
            VFX_DEV_ASSERT(referData != NULL);
            
            VfxBaseTimeline *next = referData->next;

            referrer->startThisAndAllReferers();

            referrer = next;
        }
    }
}


void VfxBaseTimeline::processStart()
{
    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER, 
            sizeof(TimelineTimeReferrerData));
    
    processStop(VFX_FALSE, VFX_FALSE);

    // Add to frame enabled timeline list
    m_targetPtr->addTimeline(this);

    // Add 1 for start time 1 is bcause we want the timeline must be applyed to VRT

    // Create timers to emit signal
    VFX_DEV_ASSERT(m_startTimer == NULL && m_stopTimer == NULL);
    VFX_OBJ_CREATE(m_startTimer, VfxTimer, this);
    m_startTimer->m_signalTick.connect(this, &VfxBaseTimeline::onStartTimerTick);
    m_startTimer->setStartDelay(m_startTime + 1);
    m_startTimer->start();

    if (m_repeatCount != VFX_TIMELINE_REPEAT_INFINITE && referData == NULL)
    {
        VfxMsec repeatTime = vfxMax(m_repeatDuration, m_durationTime);
        VfxMsec totalDurationTime = repeatTime * (m_repeatCount - 1) + m_durationTime;
        
        VFX_OBJ_CREATE(m_stopTimer, VfxTimer, this);
        m_stopTimer->m_signalTick.connect(this, &VfxBaseTimeline::onStopTimerTick);
        m_stopTimer->setStartDelay(m_startTime + totalDurationTime + 1);
        m_stopTimer->start();
    }

    m_timelineState = VFX_TIMELINE_STATE_RUNNING;
}


void VfxBaseTimeline::stop()
{
    // Method stop() only do state checking,
    //  the really work is in stopThisAndAllReferers()
    
    // NOTE: Do not stop a timeline that has timeline time
    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER,
            sizeof(TimelineTimeReferrerData));
    VFX_ASSERT(referData == NULL);

    stopThisAndAllReferers(VFX_FALSE);
}


void VfxBaseTimeline::stopThisAndAllReferers(VfxBool isComplete)
{
    VfxBool forceApply = VFX_FALSE;

    /*
     * Stop all referer timelines
     */
    TimelineTimeReferenceData *refData = 
        (TimelineTimeReferenceData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REF, 
            sizeof(TimelineTimeReferenceData));
    if (refData != NULL)
    {
        VfxBaseTimeline *referrer = refData->referrerTail;
        while (referrer != NULL)
        {
            TimelineTimeReferrerData *referData = 
                (TimelineTimeReferrerData *)referrer->getAttachProperty(
                    VFX_TIMELINE_PROP_ID_TTIME_REFER,
                    sizeof(TimelineTimeReferrerData));
            VFX_DEV_ASSERT(referData != NULL);
            
            VfxBaseTimeline *prev = referData->prev;

            referrer->stopThisAndAllReferers(isComplete);
            if (referrer->m_timelineState == VFX_TIMELINE_STATE_APPLYING)
            {
                forceApply = VFX_TRUE;
            }

            referrer = prev;
        }
    }

    /*
     * Stop this timeline
     */
    processStop(isComplete, forceApply);
}


void VfxBaseTimeline::onDeinit()
{
    stopThisAndAllReferers(VFX_FALSE);

#if 1
    // Reset property to VRT
    if (m_targetPtr != NULL && m_targetPropertyId != VRT_OBJECT_PROPERTY_ID_UNKNOWN)
    {
        m_targetPtr->resetProperty(m_targetPropertyId);
    }
#endif

    // Free all memory    
    VFX_FREE_MEM(m_customTimingCallback);
    VFX_FREE_MEM(m_customInterpolateCallback);

    removeAllTimelineTimeReferrer();
    removeFromTimelineTimeReference();
    removeCustomVariable();

    VfxObject::onDeinit();
}


void VfxBaseTimeline::processStop(VfxBool isComplete, VfxBool forceApply)
{
    VfxBool needApply = forceApply || (isComplete && m_timelineHandle == NULL);
    
    if (m_enabledObject == NULL)
    {
        // TODO: These timers should be NULL, why not NULL?
        VFX_OBJ_CLOSE(m_stopTimer);
        VFX_OBJ_CLOSE(m_startTimer);
        m_timelineState = VFX_TIMELINE_STATE_STOP;
        return;
    }

#if 0
/* under construction !*/
#endif

    /*
     * If the timeline doesn't apply to its target, for example, the frame is hidden.
     *  We keep the timeline enabled, and the state change to VFX_TIMELINE_STATE_APPLYING.
     *  It will try to apply the timeline result after the target show.
     */
    if (!needApply)
    {
        VFX_OBJ_CLOSE(m_stopTimer);
        VFX_OBJ_CLOSE(m_startTimer);

        // Disable the timeline (will dispose this timeline handle)
        m_enabledObject->removeTimeline(this);
        VFX_DEV_ASSERT(m_enabledObject == NULL);
    }

    // Emit a signal
    if (m_timelineState == VFX_TIMELINE_STATE_RUNNING)
    {
        m_signalStopped.postEmit(this, isComplete);
    }

    // Update state
    m_timelineState = needApply ? 
        VFX_TIMELINE_STATE_APPLYING :
        VFX_TIMELINE_STATE_STOP;
}


vrt_timeline_timing_callback_struct *VfxBaseTimeline::createTimingCallback(
    VfxTimelineTimingFuncPtr callback, 
    const void *userData, 
    VfxU32 userDataSize)
{
    if (callback == NULL)
    {
        VFX_ASSERT(userData == NULL && userDataSize == 0);
        return NULL;
    }
    
    VfxU32 structSize = VRT_CALLBACK_STRUCT_SIZE(
        vrt_timeline_timing_callback_struct, 
        userDataSize);

    vrt_timeline_timing_callback_struct *ret;
    VFX_ALLOC_MEM(ret, structSize, this);
    ret->callback = (vrt_timing_funcptr_type)callback;
    ret->user_data_size = userDataSize;
    if (userData != NULL)
    {
        VFX_ASSERT(userDataSize != 0);
        memcpy(VRT_CALLBACK_STRUCT_DATA(ret), userData, userDataSize);
    }
    else
    {
        VFX_ASSERT(userDataSize == 0);
    }

    return ret;
}


vrt_timeline_interplation_callback_struct *VfxBaseTimeline::createInterpolateCallback(
    VfxTimelineInterpolateFuncPtr callback, 
    const void *userData, 
    VfxU32 userDataSize)
{
    if (callback == NULL)
    {
        VFX_ASSERT(userData == NULL && userDataSize == 0);
        return NULL;
    }
        
    VfxU32 structSize = VRT_CALLBACK_STRUCT_SIZE(
        vrt_timeline_interplation_callback_struct, 
        userDataSize);

    vrt_timeline_interplation_callback_struct *ret = NULL;
    VFX_ALLOC_MEM(ret, structSize, this);
    ret->callback = (vrt_timeline_interpolation_funcptr_type)callback;
    ret->user_data_size = userDataSize;
    if (userData != NULL)
    {
        VFX_ASSERT(userDataSize != 0);
        memcpy(VRT_CALLBACK_STRUCT_DATA(ret), userData, userDataSize);
    }
    else
    {
        VFX_ASSERT(userDataSize == 0);
    }

    return ret;
}


VfxBool VfxBaseTimeline::onQueryHasFromToValue() const
{
    return VFX_TRUE;
}


void VfxBaseTimeline::onUpdateCustomTimingCallback()
{
    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER, 
            sizeof(TimelineTimeReferrerData));
    if (referData == NULL)
    {
        vrt_timeline_set_custom_timing_func(
            m_timelineHandle, 
            m_customTimingCallback);
        return;
    }

    VfxBaseTimeline *target = referData->target;
    vrt_type_id_enum type_id = target->getTargetType();        

    VfxU32 valueSize = vrt_get_size_of_type(type_id);
    VfxU32 timingDataSize = 
        m_customTimingCallback ? m_customTimingCallback->user_data_size : 0;
    VfxU32 dataSize = 
        VRT_ALIGN_TO_4(sizeof(vrt_timeline_time_user_data_struct)) +
        VRT_ALIGN_TO_4(timingDataSize) +
        VRT_ALIGN_TO_4(valueSize);

    vrt_timeline_timing_callback_struct *timing_cb = NULL;
    VFX_ALLOC_MEM(timing_cb, VRT_ALIGN_TO_4(sizeof(vrt_timeline_timing_callback_struct)) + dataSize, this);
    timing_cb->callback = vrt_timing_func_timeline_time;
    timing_cb->user_data_size = dataSize;

    vrt_timeline_time_user_data_struct *var_cb_data = (vrt_timeline_time_user_data_struct *)(timing_cb + 1);

    target->prepareHandle();
    var_cb_data->time_handle = target->getHandle();
    var_cb_data->bias = referData->bias;
    var_cb_data->scale = referData->scale;
    var_cb_data->wrap_type = (vrt_timeline_time_wrap_type_enum)referData->wrapType;
    var_cb_data->timing_func_cb.callback = m_customTimingCallback ? m_customTimingCallback->callback : NULL;
    var_cb_data->timing_func_cb.user_data_size = m_customTimingCallback ? m_customTimingCallback->user_data_size : 0;

    if (m_customTimingCallback)
    {
        memcpy(
            (VfxU8 *)var_cb_data + VRT_ALIGN_TO_4(sizeof(vrt_timeline_time_user_data_struct)),
            (VfxU8 *)m_customTimingCallback + VRT_ALIGN_TO_4(sizeof(vrt_timeline_timing_callback_struct)),
            m_customTimingCallback->user_data_size
        );
    }

    vrt_timeline_set_custom_timing_func(
        m_timelineHandle, 
        timing_cb);

    VFX_FREE_MEM(timing_cb);
}


void VfxBaseTimeline::onUpdateCustomInterpolateCallback()
{
    if (m_customInterpolateCallback != NULL)
    {
        vrt_timeline_set_custom_interpolation_func(
            m_timelineHandle,
            m_customInterpolateCallback);
    }
}


VfxAnimatableCustomVar *VfxBaseTimeline::prepareCustomVariable()
{
    VfxAnimatableCustomVar **varPtr = 
        (VfxAnimatableCustomVar **)getAttachProperty(
            VFX_TIMELINE_PROP_ID_VARIABLE,
            sizeof(VfxAnimatableCustomVar *));
    VfxAnimatableCustomVar *var = varPtr ? *varPtr : NULL;
    
    if (m_targetPropertyId >= VRT_CUSTOM_PROPERTY_ID_BEGIN &&
        m_targetPropertyId < VRT_CUSTOM_PROPERTY_ID_END_OF_ENUM)
    {
        if (var == NULL)
        {
            var = m_targetPtr->addCustomVariable(m_targetType, this->getAllocator());
            
            setAttachProperty(
                VFX_TIMELINE_PROP_ID_VARIABLE,
                &var,
                sizeof(VfxAnimatableCustomVar *));                
        }
    }
    else
    {
        if (var != NULL)
        {
            setAttachProperty(VFX_TIMELINE_PROP_ID_VARIABLE, NULL, 0);
            m_targetPtr->removeCustomVariable(var);
            var = NULL;
        }
    }

    return var;
}


void VfxBaseTimeline::removeCustomVariable()
{
    VfxAnimatableCustomVar **varPtr = 
        (VfxAnimatableCustomVar **)getAttachProperty(
            VFX_TIMELINE_PROP_ID_VARIABLE,
            sizeof(VfxAnimatableCustomVar *));
    if (varPtr == NULL)
    {
        return;
    }
    
    VfxAnimatableCustomVar *var = *varPtr;

    setAttachProperty(VFX_TIMELINE_PROP_ID_VARIABLE, NULL, 0);
    m_targetPtr->removeCustomVariable(var);
}


void VfxBaseTimeline::prepareHandle()
{
    if (m_timelineHandle != NULL)
    {
        return;
    }

    VFX_DEV_ASSERT(m_targetPtr != NULL);    
    VFX_DEV_ASSERT(m_targetType != VFX_TYPE_ID_UNKNOWN && m_targetType < VFX_TYPE_ID_END_OF_ENUM);
    VFX_DEV_ASSERT(m_targetPropertyId != VRT_OBJECT_PROPERTY_ID_UNKNOWN && m_targetPropertyId < VRT_OBJECT_PROPERTY_ID_END_OF_ENUM);

    TimelineTimeReferrerData *referData = 
        (TimelineTimeReferrerData *)getAttachProperty(
            VFX_TIMELINE_PROP_ID_TTIME_REFER,
            sizeof(TimelineTimeReferrerData));

    // Prepare target handle
    VfxAnimatableCustomVar *var = prepareCustomVariable();
    vrt_object_handle targetHandle = 
        var ? 
            var->getDataBuffer() : 
            m_targetPtr->getHandle();
    
    // Check the type ID is matched
    vrt_type_id_enum type_id = vrt_object_get_property_type(m_targetPropertyId);
    VFX_ASSERT(m_targetType == type_id);

    // Create a timeline handle and update values
    m_timelineHandle = vrt_object_add_timeline(
        targetHandle, 
        m_targetPropertyId,
        onQueryHasFromToValue() ? VRT_TRUE : VRT_FALSE,
        this);
    // Out of memory
    VFX_ASSERT(m_timelineHandle != NULL);

    onUpdateTimelineValue();

    // If has timeline time, duration can be any value (but can not be 0)
    vrt_msec_type durationTime = referData ? 1000 : (vrt_msec_type)m_durationTime;

    // Set time
    // If start timer has been commited, 
    //  it means the timeline is not started on the active screen, 
    //  and currently it active.
    if (m_startTimer != NULL && m_startTimer->m_tickTime)
    {
        // Absolute time
        vrt_timeline_set_time(
            m_timelineHandle, 
            (vrt_msec_type)m_startTimer->m_tickTime, 
            durationTime,
            m_updateDuration,
            VRT_FALSE);
    }
    else
    {
        // Relative time
        vrt_timeline_set_time(
            m_timelineHandle, 
            (vrt_msec_type)m_startTime, 
            durationTime,
            m_updateDuration,
            VRT_TRUE);
    }

    // Set repeat
    VfxMsec repeatTime = vfxMax(m_repeatDuration, durationTime);
    vrt_timeline_set_repeat(
        m_timelineHandle, 
        (vrt_msec_type)repeatTime, 
        referData ? VFX_TIMELINE_REPEAT_INFINITE : (vrt_u32)m_repeatCount,
        getAutoReversed() ? VRT_TRUE : VRT_FALSE);

    onUpdateCustomTimingCallback();
    onUpdateCustomInterpolateCallback();
}


void VfxBaseTimeline::disposeHandle()
{
    if (m_timelineHandle == NULL)
    {
        return;
    }
    
    vrt_object_remove_timeline(m_timelineHandle);
    m_timelineHandle = NULL;
}


void VfxBaseTimeline::onStartTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    m_signalStarted.postEmit(this);
}


void VfxBaseTimeline::onStopTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    // TODO: Check this
    //VFX_DEV_ASSERT(m_enabledObject != NULL);

    stopThisAndAllReferers(VFX_TRUE);
}


/***************************************************************************** 
 * Class VfxS32Timeline
 *****************************************************************************/

VfxS32Timeline::VfxS32Timeline() :
    VfxBaseTimeline(VRT_TYPE_ID_S32),
    m_fromValue(0),
    m_toByValue(0)        
{
}


VfxS32 VfxS32Timeline::getFromValue() const
{
    return m_fromValue;
}


VfxS32 VfxS32Timeline::getToValue() const
{
    return m_toByValue;
}


void VfxS32Timeline::setFromValue(VfxS32 value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxS32Timeline::setToValue(VfxS32 value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}


void VfxS32Timeline::setByValue(VfxS32 value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}


void VfxS32Timeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    VfxS32 from_value       = getFromValue();
    VfxS32 to_value         = getToValue();
    VfxBool is_from_current = getIsFromCurrent();
    VfxBool is_to_step      = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(VfxFloat));
}


/***************************************************************************** 
 * Class VfxFloatTimeline
 *****************************************************************************/

VfxFloatTimeline::VfxFloatTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_FLOAT),
    m_fromValue(0.0f),
    m_toByValue(0.0f)
{
}


VfxFloat VfxFloatTimeline::getFromValue() const
{
    return m_fromValue;
}


VfxFloat VfxFloatTimeline::getToValue() const
{
    return m_toByValue;
}


void VfxFloatTimeline::setFromValue(VfxFloat value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxFloatTimeline::setToValue(VfxFloat value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}


void VfxFloatTimeline::setByValue(VfxFloat value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}


void VfxFloatTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    VfxFloat from_value     = getFromValue();
    VfxFloat to_value       = getToValue();
    VfxBool is_from_current = getIsFromCurrent();
    VfxBool is_to_step      = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(VfxFloat));
}


/***************************************************************************** 
 * Class VfxColorTimeline
 *****************************************************************************/
 
VfxColorTimeline::VfxColorTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_COLOR),
    m_fromValue(VFX_COLOR_BLACK),
    m_toValue(VFX_COLOR_BLACK)        
{
}


const VfxColor &VfxColorTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxColor &VfxColorTimeline::getToValue() const
{
    return m_toValue;
}


void VfxColorTimeline::setFromValue(const VfxColor &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}

void VfxColorTimeline::setToValue(const VfxColor &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}


void VfxColorTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_color_type from_value   = getFromValue();
    vrt_color_type to_value     = getToValue();
    VfxBool is_from_current     = getIsFromCurrent();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        &to_value, 
        NULL,
        sizeof(vrt_color_type));
}


/***************************************************************************** 
 * Class VfxPointTimeline
 *****************************************************************************/
 
VfxPointTimeline::VfxPointTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_POINT),
    m_fromValue(VFX_POINT_ZERO),
    m_toByValue(VFX_POINT_ZERO)        
{
}


const VfxPoint &VfxPointTimeline::getFromValue() const
{
    return m_fromValue;
}

   
const VfxPoint &VfxPointTimeline::getToValue() const
{
    return m_toByValue;
}


void VfxPointTimeline::setFromValue(const VfxPoint &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxPointTimeline::setToValue(const VfxPoint &value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}


void VfxPointTimeline::setByValue(const VfxPoint &value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}


void VfxPointTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_point_struct from_value = getFromValue();
    vrt_point_struct to_value   = getToValue();
    VfxBool is_from_current     = getIsFromCurrent();
    VfxBool is_to_step          = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(vrt_point_struct));
}


/***************************************************************************** 
 * Class VfxPointTimeline
 *****************************************************************************/
 
VfxFPointTimeline::VfxFPointTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_FPOINT),
    m_fromValue(VFX_FPOINT_ZERO),
    m_toByValue(VFX_FPOINT_ZERO)        
{
}


const VfxFPoint &VfxFPointTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxFPoint &VfxFPointTimeline::getToValue() const
{
    return m_toByValue;
}


void VfxFPointTimeline::setFromValue(const VfxFPoint &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxFPointTimeline::setToValue(const VfxFPoint &value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}    


void VfxFPointTimeline::setByValue(const VfxFPoint &value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}    


void VfxFPointTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_fpoint_struct from_value = getFromValue();
    vrt_fpoint_struct to_value   = getToValue();
    VfxBool is_from_current      = getIsFromCurrent();
    VfxBool is_to_step          = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(vrt_fpoint_struct));
}


/***************************************************************************** 
 * VfxSizeTimeline
 *****************************************************************************/
 
VfxSizeTimeline::VfxSizeTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_SIZE),
    m_fromValue(VFX_SIZE_ZERO),
    m_toByValue(VFX_SIZE_ZERO)        
{
}


const VfxSize &VfxSizeTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxSize &VfxSizeTimeline::getToValue() const
{
    return m_toByValue;
}


void VfxSizeTimeline::setFromValue(const VfxSize &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxSizeTimeline::setToValue(const VfxSize &value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}        


void VfxSizeTimeline::setByValue(const VfxSize &value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}        


void VfxSizeTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_size_struct from_value  = getFromValue();
    vrt_size_struct to_value    = getToValue();
    VfxBool is_from_current     = getIsFromCurrent();
    VfxBool is_to_step          = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(vrt_size_struct));
}


/***************************************************************************** 
 * Class VfxRectTimeline
 *****************************************************************************/
 
VfxRectTimeline::VfxRectTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_RECT),
    m_fromValue(VFX_RECT_ZERO),
    m_toByValue(VFX_RECT_ZERO)        
{
}


const VfxRect &VfxRectTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxRect &VfxRectTimeline::getToValue() const
{
    return m_toByValue;
}


void VfxRectTimeline::setFromValue(const VfxRect &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxRectTimeline::setToValue(const VfxRect &value)
{
    m_toByValue = value;
    setHasByValue(VRT_FALSE);
}


void VfxRectTimeline::setByValue(const VfxRect &value)
{
    m_toByValue = value;
    setHasByValue(VRT_TRUE);
}


void VfxRectTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_rect_struct from_value  = getFromValue();
    vrt_rect_struct to_value    = getToValue();
    VfxBool is_from_current     = getIsFromCurrent();
    VfxBool is_to_step          = getHasByValue();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        is_to_step ? NULL : &to_value, 
        is_to_step ? &to_value : NULL,
        sizeof(vrt_rect_struct));
}


/***************************************************************************** 
 * Class VfxTransformTimeline
 *****************************************************************************/
 
VfxTransformTimeline::VfxTransformTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_TRANSFORM),
    m_fromValue(VFX_TRANSFORM_IDENTITY),
    m_toValue(VFX_TRANSFORM_IDENTITY)        
{
}


const VfxTransform &VfxTransformTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxTransform &VfxTransformTimeline::getToValue() const
{
    return m_toValue;
}


void VfxTransformTimeline::setFromValue(const VfxTransform &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxTransformTimeline::setToValue(const VfxTransform &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}                


void VfxTransformTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);
    
    vrt_transform_struct from_value;
    vrt_transform_struct to_value;
    getFromValue().initVrtTransform(from_value, VFX_FALSE);
    getToValue().initVrtTransform(to_value, VFX_FALSE);
    VfxBool is_from_current = getIsFromCurrent();
    vrt_timeline_set_value(
        m_timelineHandle, 
        is_from_current ? NULL : &from_value, 
        &to_value, 
        NULL,
        sizeof(vrt_transform_struct));
}


/***************************************************************************** 
 * Class VfxVector2fTimeline
 *****************************************************************************/
 
VfxVector2fTimeline::VfxVector2fTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_VEC2),
    m_fromValue(0.0f),
    m_toValue(0.0f)
{
}


const VfxVector2f &VfxVector2fTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxVector2f &VfxVector2fTimeline::getToValue() const
{
    return m_toValue;
}


void VfxVector2fTimeline::setFromValue(const VfxVector2f &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxVector2fTimeline::setToValue(const VfxVector2f &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxVector2fTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxVector2f));
}


/***************************************************************************** 
 * Class VfxVector3fTimeline
 *****************************************************************************/
 
VfxVector3fTimeline::VfxVector3fTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_VEC3),
    m_fromValue(0.0f),
    m_toValue(0.0f)
{
}


const VfxVector3f &VfxVector3fTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxVector3f &VfxVector3fTimeline::getToValue() const
{
    return m_toValue;
}


void VfxVector3fTimeline::setFromValue(const VfxVector3f &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxVector3fTimeline::setToValue(const VfxVector3f &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxVector3fTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxVector3f));
}


/***************************************************************************** 
 * Class VfxVector4fTimeline
 *****************************************************************************/
 
VfxVector4fTimeline::VfxVector4fTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_VEC4),
    m_fromValue(0.0f),
    m_toValue(0.0f)
{
}


const VfxVector4f &VfxVector4fTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxVector4f &VfxVector4fTimeline::getToValue() const
{
    return m_toValue;
}


void VfxVector4fTimeline::setFromValue(const VfxVector4f &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxVector4fTimeline::setToValue(const VfxVector4f &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxVector4fTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxVector4f));
}


/***************************************************************************** 
 * Class VfxQuaternionfTimeline
 *****************************************************************************/
 
VfxQuaternionfTimeline::VfxQuaternionfTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_QUAT)
{
}


const VfxQuaternionf &VfxQuaternionfTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxQuaternionf &VfxQuaternionfTimeline::getToValue() const
{
    return m_toValue;
}


void VfxQuaternionfTimeline::setFromValue(const VfxQuaternionf &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxQuaternionfTimeline::setToValue(const VfxQuaternionf &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxQuaternionfTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxQuaternionf));
}


/***************************************************************************** 
 * Class VfxMatrix3fTimeline
 *****************************************************************************/
 
VfxMatrix3fTimeline::VfxMatrix3fTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_MAT3)
{
}


const VfxMatrix3f &VfxMatrix3fTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxMatrix3f &VfxMatrix3fTimeline::getToValue() const
{
    return m_toValue;
}


void VfxMatrix3fTimeline::setFromValue(const VfxMatrix3f &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxMatrix3fTimeline::setToValue(const VfxMatrix3f &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxMatrix3fTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxMatrix3f));
}


/***************************************************************************** 
 * Class VfxMatrix4fTimeline
 *****************************************************************************/
 
VfxMatrix4fTimeline::VfxMatrix4fTimeline() :
    VfxBaseTimeline(VRT_TYPE_ID_MAT4)
{
}


const VfxMatrix4f &VfxMatrix4fTimeline::getFromValue() const
{
    return m_fromValue;
}


const VfxMatrix4f &VfxMatrix4fTimeline::getToValue() const
{
    return m_toValue;
}


void VfxMatrix4fTimeline::setFromValue(const VfxMatrix4f &value)
{
    m_fromValue = value;
    setIsFromCurrent(VFX_FALSE);
}


void VfxMatrix4fTimeline::setToValue(const VfxMatrix4f &value)
{
    m_toValue = value;
    setHasByValue(VRT_FALSE);
}            


void VfxMatrix4fTimeline::onUpdateTimelineValue()
{
    VFX_ASSERT(m_timelineHandle != NULL);

    vrt_timeline_set_value(
        m_timelineHandle, 
        getIsFromCurrent() ? NULL : &getFromValue(), 
        &getToValue(), 
        NULL,
        sizeof(VfxMatrix4f));
}

#ifdef __VENUS_3D_UI_ENGINE__

/***************************************************************************** 
 * Class VfxKeyframeSequence 
 *****************************************************************************/

VfxKeyframeSequence::VfxKeyframeSequence(VfxU32 keyCount, VfxTypeIdEnum typeId) : 
    m_keyCount(keyCount), 
    m_typeId(typeId), 
    m_keyframeData(NULL)
{
    VFX_DEV_ASSERT(keyCount > 1);
    VFX_DEV_ASSERT(typeId < VFX_TYPE_ID_END_OF_ENUM);
}


void VfxKeyframeSequence::onInit()
{
    VfxObject::onInit();

    // TODO: 4 byte align
    VFX_ALLOC_MEM(
        m_keyframeData,
        getDataSize(),
        this);
    if (m_keyframeData)
    {
        vrt_keyframe_sequence_struct *header = (vrt_keyframe_sequence_struct *)m_keyframeData;
        header->key_count = m_keyCount;
        header->type_id = (vrt_type_id_enum)m_typeId;
    }
}


void VfxKeyframeSequence::onDeinit()
{
    VFX_FREE_MEM(m_keyframeData);

    VfxObject::onDeinit();
}


VfxU32 VfxKeyframeSequence::getDataSize() const
{
    return getKeyframeDataSize(m_keyCount, m_typeId);
}


VfxU32 VfxKeyframeSequence::getKeyframeDataSize(VfxU32 keyCount, VfxTypeIdEnum typeId)
{
    return
        sizeof(vrt_keyframe_sequence_struct) + 
        (sizeof(VfxMsec) + vrt_get_size_of_type((vrt_type_id_enum)typeId)) * 
            keyCount;
}


void VfxKeyframeSequence::setKeyframe(VfxId idx, VfxMsec time, void *value)
{
    VFX_DEV_ASSERT(idx < m_keyCount);
    VfxU32 size = vrt_get_size_of_type((vrt_type_id_enum)m_typeId);

    vrt_keyframe_sequence_struct *header = (vrt_keyframe_sequence_struct *)m_keyframeData;
    VfxU8 *data = (VfxU8 *)(header + 1);     
    VfxMsec *keyTime = (VfxMsec *)(data + ((sizeof(VfxMsec) + size) * idx));
    void *keyValue = keyTime + 1;

    *keyTime = time;
    memcpy(keyValue, value, size);
}


/***************************************************************************** 
 * Class VfxKeyframeTimeline 
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("KeyframeTimeline", VfxKeyframeTimeline, VfxBaseTimeline);

VfxKeyframeTimeline::VfxKeyframeTimeline(VfxKeyframeSequence *kfs) :
    VfxBaseTimeline(VRT_TYPE_ID_UNKNOWN),
    m_keyframeSource((const VfxU8 *)kfs)
{
    if (kfs)
    {
        m_targetType = (vrt_type_id_enum)kfs->m_typeId;
    }
}


VfxKeyframeSequence *VfxKeyframeTimeline::getKeyframeSequence() const
{
    return m_keyframeSource.getType() == VFX_ASSET_SRC_TYPE_MEM ?
        (VfxKeyframeSequence *) m_keyframeSource.getMem() : 
        NULL;
}


void VfxKeyframeTimeline::onInit()
{
    VfxBaseTimeline::onInit();

    setIsFromCurrent(VRT_FALSE);
}


void VfxKeyframeTimeline::setKeyframeInterpolation(VfxInterpolationFuncIdEnum interpolation)
{
    VFX_DEV_ASSERT(interpolation < VFX_INTERPOLATE_FUNC_ID_END_OF_ENUM);

    m_keyframeInterpolationCallback = 
        (VfxTimelineInterpolateFuncPtr)
            vrt_timeline_get_predefined_interpolate_func(
                (vrt_interpolate_func_id_enum)interpolation);
}


void VfxKeyframeTimeline::setKeyframeSource(const VfxAssetSrc &kfsSrc)
{
    // call setKeyframeSequence to set keyframe data from buffer
    VFX_DEV_ASSERT(kfsSrc.getType() != VFX_ASSET_SRC_TYPE_MEM);

    m_keyframeSource = kfsSrc;
    m_targetType = VRT_TYPE_ID_UNKNOWN;

    switch (m_keyframeSource.getType())
    {
    case VFX_ASSET_SRC_TYPE_RES_ID:
        {
            VfxU32 keyframeDataSize;
            const VfxU8 *keyframeData = vfx_sys_res_get_binary(m_keyframeSource.getResId(), &keyframeDataSize);

            if (keyframeData && keyframeDataSize)
            {
                const vrt_keyframe_sequence_struct *header = (const vrt_keyframe_sequence_struct *)keyframeData;
                VFX_DEV_ASSERT(header->key_count > 1);
                VFX_DEV_ASSERT(header->type_id < VFX_TYPE_ID_END_OF_ENUM);
                VFX_DEV_ASSERT(keyframeDataSize ==
                    VfxKeyframeSequence::getKeyframeDataSize(header->key_count, (VfxTypeIdEnum)header->type_id));

                m_targetType = header->type_id;
            }
        }
        break;
    case VFX_ASSET_SRC_TYPE_PATH:
        {
            VfxFileIstream is;
            if (is.open(m_keyframeSource.getPath().getBuf()))
            {
                vrt_keyframe_sequence_struct header = {0};
                is.readValue(header);
                VFX_DEV_ASSERT(header.key_count > 1);
                VFX_DEV_ASSERT(header.type_id < VFX_TYPE_ID_END_OF_ENUM);

                m_targetType = header.type_id;

                is.close();
            }
        }
        break;
    }
}


void VfxKeyframeTimeline::setKeyframeSequence(VfxKeyframeSequence *kfs)
{
    m_keyframeSource.setMem((const VfxU8 *)kfs);

    if (m_keyframeSource.isNull())
    {
        m_targetType = VRT_TYPE_ID_UNKNOWN;
        return;
    }

    m_targetType = (vrt_type_id_enum)kfs->m_typeId;
}


VfxBool VfxKeyframeTimeline::onQueryHasFromToValue() const
{
    return VFX_FALSE;
}


void VfxKeyframeTimeline::onUpdateTimelineValue()
{
}


void VfxKeyframeTimeline::onUpdateCustomInterpolateCallback()
{
    VFX_DEV_ASSERT(m_timelineHandle != NULL);

    /*
        vrt_timeline_interplation_callback_struct
            callback = m_keyframeInterpolationCallback
            user_data_size = *
            (user_data) =
                vrt_keyframe_sequence_struct * =
                (vrt_keyframe_sequence_struct) =    // if vrt_keyframe_sequence_struct * == NULL
                    key_count = *
                    type_id = *
                    (data) = keyframe sequence data
                vrt_timeline_interplation_callback_struct
                    callback = m_customInterpolateCallback->callback
                    user_data_size = m_customInterpolateCallback->user_data_size
                    (user_data) =                   // if callback != NULL
                        user_data of m_customInterpolateCallback
     */

    switch (m_keyframeSource.getType())
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        VfxBaseTimeline::onUpdateCustomInterpolateCallback();
        return;

    case VFX_ASSET_SRC_TYPE_RES_ID:
        {
            VfxU32 keyframeDataSize;
            const VfxU8 *keyframeData = vfx_sys_res_get_binary(m_keyframeSource.getResId(), &keyframeDataSize);
            VFX_DEV_ASSERT(keyframeData && keyframeDataSize);

            VfxU32 callbackUserDataSize =
                sizeof(vrt_keyframe_sequence_struct *) +
                sizeof(vrt_timeline_interplation_callback_struct) +
                (m_customInterpolateCallback ? m_customInterpolateCallback->user_data_size : 0);

            vrt_timeline_interplation_callback_struct *callback;
            VFX_ALLOC_MEM(callback, sizeof(vrt_timeline_interplation_callback_struct) + callbackUserDataSize, this);
            callback->callback = (vrt_timeline_interpolation_funcptr_type)m_keyframeInterpolationCallback;
            callback->user_data_size = callbackUserDataSize;

            vrt_keyframe_sequence_struct **keyframeSequencePtr = (vrt_keyframe_sequence_struct **)(callback + 1);
            *keyframeSequencePtr = (vrt_keyframe_sequence_struct *)keyframeData;

            vrt_timeline_interplation_callback_struct *otherCallback = 
                (vrt_timeline_interplation_callback_struct *)(keyframeSequencePtr + 1);
            if (m_customInterpolateCallback != NULL)
            {
                memcpy(
                    otherCallback, 
                    m_customInterpolateCallback,
                    sizeof(vrt_timeline_interplation_callback_struct) + 
                        m_customInterpolateCallback->user_data_size);
            }
            else
            {
                memset(otherCallback, 0, sizeof(vrt_timeline_interplation_callback_struct));
            }

            vrt_timeline_set_custom_interpolation_func(m_timelineHandle, callback);

            VFX_FREE_MEM(callback);
        }
        break;

    case VFX_ASSET_SRC_TYPE_MEM:
        {
            VfxKeyframeSequence *keyframeSequence = getKeyframeSequence();
            VfxU32 keyframeDataSize = keyframeSequence->getDataSize();

            VfxU32 callbackUserDataSize = 
                sizeof(vrt_keyframe_sequence_struct *) +
                keyframeDataSize +
                sizeof(vrt_timeline_interplation_callback_struct) +
                (m_customInterpolateCallback ? m_customInterpolateCallback->user_data_size : 0);

            vrt_timeline_interplation_callback_struct *callback;
            VFX_ALLOC_MEM(callback, sizeof(vrt_timeline_interplation_callback_struct) + callbackUserDataSize, this);
            callback->callback = (vrt_timeline_interpolation_funcptr_type)m_keyframeInterpolationCallback;
            callback->user_data_size = callbackUserDataSize;

            vrt_keyframe_sequence_struct **keyframeSequencePtr = (vrt_keyframe_sequence_struct **)(callback + 1);
            *keyframeSequencePtr = NULL;

            vrt_keyframe_sequence_struct *keyframeSequenceData = (vrt_keyframe_sequence_struct *)(keyframeSequencePtr + 1);
            memcpy(keyframeSequenceData, keyframeSequence->m_keyframeData, keyframeDataSize);

            vrt_timeline_interplation_callback_struct *otherCallback = 
                (vrt_timeline_interplation_callback_struct *)((VfxU8 *)keyframeSequenceData + keyframeDataSize);
            if (m_customInterpolateCallback != NULL)
            {
                memcpy(
                    otherCallback, 
                    m_customInterpolateCallback,
                    sizeof(vrt_timeline_interplation_callback_struct) + 
                        m_customInterpolateCallback->user_data_size);
            }
            else
            {
                memset(otherCallback, 0, sizeof(vrt_timeline_interplation_callback_struct));
            }

            vrt_timeline_set_custom_interpolation_func(m_timelineHandle, callback);

            VFX_FREE_MEM(callback);
        }
        break;

    case VFX_ASSET_SRC_TYPE_PATH:
        {
            VfxFileIstream is;
            VfxBool ret = is.open(m_keyframeSource.getPath().getBuf());
            VFX_DEV_ASSERT(ret);

            vrt_keyframe_sequence_struct header = {0};
            is.readValue(header);
            VfxU32 keyframeDataSize = VfxKeyframeSequence::getKeyframeDataSize(header.key_count, (VfxTypeIdEnum)header.type_id);
            is.seekTo(0);

            VfxU32 callbackUserDataSize =
                sizeof(vrt_keyframe_sequence_struct *) +
                keyframeDataSize +
                sizeof(vrt_timeline_interplation_callback_struct) +
                (m_customInterpolateCallback ? m_customInterpolateCallback->user_data_size : 0);

            vrt_timeline_interplation_callback_struct *callback;
            VFX_ALLOC_MEM(callback, sizeof(vrt_timeline_interplation_callback_struct) + callbackUserDataSize, this);
            callback->callback = (vrt_timeline_interpolation_funcptr_type)m_keyframeInterpolationCallback;
            callback->user_data_size = callbackUserDataSize;

            vrt_keyframe_sequence_struct **keyframeSequencePtr = (vrt_keyframe_sequence_struct **)(callback + 1);
            *keyframeSequencePtr = NULL;

            vrt_keyframe_sequence_struct *keyframeSequenceData = (vrt_keyframe_sequence_struct *)(keyframeSequencePtr + 1);
            is.read((VfxU8 *)keyframeSequenceData, keyframeDataSize);

            vrt_timeline_interplation_callback_struct *otherCallback = 
                (vrt_timeline_interplation_callback_struct *)((VfxU8 *)keyframeSequenceData + keyframeDataSize);
            if (m_customInterpolateCallback != NULL)
            {
                memcpy(
                    otherCallback, 
                    m_customInterpolateCallback,
                    sizeof(vrt_timeline_interplation_callback_struct) + 
                        m_customInterpolateCallback->user_data_size);
            }
            else
            {
                memset(otherCallback, 0, sizeof(vrt_timeline_interplation_callback_struct));
            }

            vrt_timeline_set_custom_interpolation_func(m_timelineHandle, callback);

            VFX_FREE_MEM(callback);

            is.close();
        }
        break;

    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}

#endif /* __VENUS_3D_UI_ENGINE__ */

/***************************************************************************** 
 * Class VfxAnimation
 *****************************************************************************/
 
void VfxAnimation::start()
{
    m_isEnabled = VFX_TRUE;

    VfxObjListEntry *i;
    for (i = m_timelineList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        timeline->start();
    }
}


void VfxAnimation::stop()
{
    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        timeline->stop();
    }    
    
    m_isEnabled = VFX_FALSE;
}


VfxMsec VfxAnimation::getTotalDuration() const
{
    VfxMsec totalDuration = 0;

    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        totalDuration = VFX_MAX(totalDuration, timeline->getStartTime() + timeline->getDuration());
    }

    return totalDuration;
}


void VfxAnimation::setTimingFunc(VfxTimingFuncIdEnum value)
{
    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        timeline->setTimingFunc(value);
    }
}


void VfxAnimation::setCustomTimingFunc(VfxTimelineTimingFuncPtr callback, const void *userData, VfxU32 userDataSize)
{
    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        timeline->setCustomTimingFunc(callback, userData, userDataSize);
    }
}


void VfxAnimation::setCustomInterpolateFunc(VfxTimelineInterpolateFuncPtr callback, const void *userData, VfxU32 userDataSize)
{
    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        timeline->setCustomInterpolateFunc(callback, userData, userDataSize);
    }
}


void VfxAnimation::setTimelineTime(
    VfxBaseTimeline *time, 
    VfxFloat scale, 
    VfxFloat bias,
    VfxTimelineTimeWrapTypeEnum wrapType)    
{
    VfxMsec totalDuration = getTotalDuration();

    VfxObjListEntry *i;
    for (i = m_timelineList.getValidTail(); i != NULL; i = i->getValidPrev())
    {
        VfxBaseTimeline *timeline = (VfxBaseTimeline *)i->get();
        VfxMsec tlDuration = timeline->getDuration();
        VfxFloat tlBias, tlScale;
        if (tlDuration != 0)
        {
            tlBias = VfxFloat(-timeline->getStartTime()) / VfxFloat(tlDuration);
            tlScale = VfxFloat(totalDuration) / VfxFloat(tlDuration);
        }
        else
        {
            tlBias = 0.0f;
            tlScale = 1.0f;
        }

        tlBias = tlScale * bias + tlBias;
        tlScale = tlScale * scale;

        timeline->setTimelineTime(time, tlScale, tlBias, wrapType);
    }
}


void VfxAnimation::onAddChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxBaseTimeline *timeline_child = VFX_OBJ_DYNAMIC_CAST(objChild, VfxBaseTimeline);
    if (timeline_child != NULL)
    {
        m_timelineList.append(timeline_child);
    }
}


void VfxAnimation::onRemoveChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxBaseTimeline *timeline_child = VFX_OBJ_DYNAMIC_CAST(objChild, VfxBaseTimeline);
    if (timeline_child != NULL)
    {
        m_timelineList.removeOne(timeline_child);
    }
}


void VfxAnimation::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            onAddChild((VfxObject *)userData);
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD:
        {
            onRemoveChild((VfxObject *)userData);
            return;
        }
        default:
        {
            VfxObject::onObjectNotify(id, userData);
            return;
        }
    }
}

