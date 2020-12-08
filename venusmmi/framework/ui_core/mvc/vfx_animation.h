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
 *  vfx_animation.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_ANIMATION_H__
#define __VFX_ANIMATION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"
#include "vrt_canvas.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_transform.h"
#include "vfx_object_list.h"
#include "vfx_vector.h"
#include "vfx_matrix.h"
#include "vfx_quaternion.h"
#include "vfx_string.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_asset_src.h"
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxBaseTimeline registered name
#define VFX_BASE_TIMELINE_CLASS_NAME   "Timeline"
// The VfxS32Timeline registered name
#define VFX_S32_TIMELINE_CLASS_NAME    "S32Timeline"
// The VfxFloatTimeline registered name
#define VFX_FLOAT_TIMELINE_CLASS_NAME  "FloatTimeline"

#define VFX_MAX_CUSOM_TIMING_FUNC_DATA_SIZE  16

// Default timeline dutaion time
#define VFX_TIMELINE_DEFAULT_DUR_TIME  VRT_TIMELINE_DEFAULT_DUR_TIME
// The value to repeat timeline on infinite times
#define VFX_TIMELINE_REPEAT_INFINITE   VRT_TIMELINE_REPEAT_INFINITE


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-defined classes
class VfxAnimatableCustomVar;
class VfxAnimatable;
class VfxTimer;
class VfxBaseTimeline;


enum VfxTimelineStateEnum
{
    VFX_TIMELINE_STATE_STOP = 0,
    VFX_TIMELINE_STATE_RUNNING,
    VFX_TIMELINE_STATE_APPLYING,
    VFX_TIMELINE_STATE_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxBaseTimeline 
 *****************************************************************************/

/*
 * VfxBaseTimeline is the base class of all timeline classes
 */
class VfxBaseTimeline : public VfxObject
{
    VFX_DECLARE_CLASS(VfxBaseTimeline);
    VFX_DECLARE_NO_COPY_CLASS(VfxBaseTimeline);

// Constructor / Destructor
protected:
    // Internal used. Constructor with target type
    VfxBaseTimeline(vrt_type_id_enum target_type);

// VRT Method
public:
    // Return the VRT timeline handle
    //
    // RETURNS: The VRT timeline handle
    vrt_timeline_handle getHandle() const
    {
        return m_timelineHandle;
    }

// Property
public:
    // The start delay of the timeline, in milisecond.
    //
    // NOTE: Default value is 0.
    VfxMsec getStartTime() const
    {
        return m_startTime;
    }
    
    // The duration time of the timeline, in milisecond.
    //
    // NOTE: Default value is 0.
    VfxMsec getDurationTime() const
    {
        return m_durationTime;
    }

    // The update rate.
    //
    // NOTE: Default value is 0.
    VfxMsec getUpdateDuration() const
    {
        return m_updateDuration;
    }

    // The repeat duration time of the timeline, in milisecond.
    //
    // NOTE: Default value is 0. 
    //  If the value is small than m_propertyDurationTime, it will be m_propertyDurationTime    
    VfxMsec getRepeatDuration() const
    {
        return m_repeatDuration;
    }

    // The repeat count
    //
    // NOTE: Default value is 1. 
    VfxS32 getRepeatCount() const
    {
        return m_repeatCount;
    }

    // Whether the timeline is auto reversed
    //
    // NOTE: Default value is VFX_FALSE. 
    VfxBool getAutoReversed() const;

    // Whether the timeline is from current value
    //
    // NOTE: Default value is VFX_TRUE. 
    VfxBool getIsFromCurrent() const;

    // Whether the timeline has by value
    //
    // NOTE: Default value is VFX_FALSE. 
    VfxBool getHasByValue() const;

    // Set start time of timeline.
    //
    // NOTE: Default value is 0.
    void setStartTime(
        VfxMsec value           // [IN] time(millisecond) to start animation.
    )
    {
        VRT_ASSERT(value >= 0);    
        m_startTime = value;
    }

    // Set duration time of timeline.
    //
    // NOTE: Default value is 0.
    void setDurationTime(
        VfxMsec value           // [IN] time(millisecond) to end animation.
    )
    {
        VRT_ASSERT(value >= 0);        
        m_durationTime = value;
    }

    // Set frame rate of timeline. 0 or 1 means update the timeline each frame.
    //
    // NOTE: Default value is 0.
    void setUpdateDuration(VfxMsec value)
    {
        VRT_ASSERT(value >= 0);
        m_updateDuration = value;
    }

    // Set durtaion time to start repeat.
    //
    // NOTE: Default value is 0.
    void setRepeatDuration(
        VfxMsec value           // [IN] time(millisecond) to repeat animation.
    )
    {
        VRT_ASSERT(value >= 0);
        m_repeatDuration = value;
    }

    // Set repeat count of timeline.
    //
    // NOTE: Default value is 1.
    void setRepeatCount(
        VfxS32  value           // [IN] repeat count, VFX_TIMELINE_REPEAT_INFINITE means infinite times.
    )
    {
        VRT_ASSERT(value >= 0 || value == VFX_TIMELINE_REPEAT_INFINITE);        
        m_repeatCount = value;
    }

    // Whether the timeline will automatically reverse at each repeat duration time.
    //    
    // NOTE: Default value is VFX_FALSE.
    void setAutoReversed(VfxBool value);

    // Whether the value of timeline will start from current value.
    //
    // NOTE: Default value is VFX_TRUE.
    void setIsFromCurrent(VfxBool value);

    // Whether the value of timeline has by-value
    //
    // NOTE: Default value is VFX_FALSE.
    void setHasByValue(VfxBool value);

    // Whether the timeline is enabled
    VfxBool getIsEnabled() const;

    // An alias to getStartTime
    //
    // RETURNS: The start delay of the timeline
    VfxMsec getStartDelay() const
    {
        return getStartTime();
    }

    // An alias to setStartTime
    void setStartDelay(
        VfxMsec value   // [IN] The start delay of the timeline
    )
    {
        setStartTime(value);
    }

    // An alias to getDurationTime
    //
    // RETURNS: The duration time of the timeline
    VfxMsec getDuration() const
    {
        return getDurationTime();
    }

    // An alias to setDurationTime
    void setDuration(
        VfxMsec value   // [IN] The duration time of the timeline
    )
    {
        setDurationTime(value);
    }

    // The data type of target value.
    //
    // NOTE: Default value is 0.
    vrt_type_id_enum getTargetType() const
    {
        return m_targetType;
    }

// Setting method
public:
    // Return the target object.
    //
    // RETURNS: The target object.
    VfxAnimatable *getTarget() const;
    
    // Assign the target object.
    void setTarget(
        VfxAnimatable *value             // [IN] The object to assign
    );
    
    // Return the target property ID.
    //
    // RETURNS: The target property ID. 
    vrt_object_property_id_enum getTargetPropertyId() const;
    
    // Assign the target property ID.
    void setTargetPropertyId(
        vrt_object_property_id_enum value    // [IN] The property ID to assign
    );

    // Assign the timing function with timing function ID.
    //
    // SEE ALSO: VfxTimingFuncIdEnum
    void setTimingFunc(
        VfxTimingFuncIdEnum value
    );

    // Assign the timing function with customized timing function.
    // 
    // SEE ALSO: VfxTimelineTimingFuncPtr
    void setCustomTimingFunc(
        VfxTimelineTimingFuncPtr callback,  // [IN] The callback function to assign
        const void *userData,               // [IN] The user data of timing function
        VfxU32 userDataSize                 // [IN] The size of user data 
    );                   

    // Assign the interpolation function.
    // 
    // SEE ALSO: VfxTimelineInterpolateFuncPtr
    void setCustomInterpolateFunc(
        VfxTimelineInterpolateFuncPtr callback, // [IN] The callback function to assign
        const void *userData,                   // [IN] The user data of callback function
        VfxU32 userDataSize                     // [IN] The size of user data 
    );

    // Assign the VfxFloatTimeline object as time of timeline.    
    //
    // SEE ALSO: VfxFloatTimeline
    void setTimelineTime(
        VfxBaseTimeline *time,
        VfxFloat scale = 1.0f,
        VfxFloat bias = 0.0f,
        VfxTimelineTimeWrapTypeEnum wrapType = VFX_TIMELINE_TIME_WRAP_TYPE_NONE
    );

// Method
public:
    // Start the timeline.
    void start();

    // Stop the timeline.
    void stop();

// Signal
public:
    // Emit when the timeline is started
    VfxSignal1 <VfxBaseTimeline *> m_signalStarted;
    // Emit when the timeline is stopped.
    VfxSignal2 <VfxBaseTimeline *, VfxBool> m_signalStopped;

// Override
protected:
    virtual void onDeinit();

// Overridable
protected:
    // Update timeline to VRT.
    virtual VfxBool onQueryHasFromToValue() const;
    virtual void onUpdateTimelineValue() = 0;
    virtual void onUpdateCustomTimingCallback();
    virtual void onUpdateCustomInterpolateCallback();
    
// Implementation
protected:
    //friend class VfxAnimatable;
    friend class VfxAnimatable;

    enum
    {
        // Whether the timeline is auto reversed.
        FLAGS_AUTO_REVERSED = (1 << 0),
        // Whether the timeline is from current value.
        FLAGS_FROM_CURRENT  = (1 << 1),
        FLAGS_TO_STEP       = (1 << 2),
        FLAGS_DEFAULT       = FLAGS_FROM_CURRENT
    };

    // State
    VfxTimelineStateEnum m_timelineState;

    // VRT handle
    vrt_timeline_handle m_timelineHandle;

    VfxAnimatable   *m_enabledObject;               // Set to target object when timeline is enabled. Otherwise, set it to NULL. 
    VfxBaseTimeline *m_enabledTimelineEntryPrev;    // Previous enabled timeline in the same object.
    VfxBaseTimeline *m_enabledTimelineEntryNext;    // Next enabled timieline in the same object.

    void prepareHandle();   // Prepare VRT timeline handle.
    void disposeHandle();   // Dispose VRT timeline handle.

    void processStart();

    void startThisAndAllReferers();
    
    void stopThisAndAllReferers(
        VfxBool isComplete  // [IN] Whether the timeline is completed.
    );
    
    void processStop(
        VfxBool isComplete,  // [IN] Whether the timeline is completed.
        VfxBool forceApply
    );

    vrt_timeline_timing_callback_struct *createTimingCallback(
        VfxTimelineTimingFuncPtr callback, 
        const void *userData, 
        VfxU32 userDataSize        
    );

    vrt_timeline_interplation_callback_struct *createInterpolateCallback(
        VfxTimelineInterpolateFuncPtr callback, 
        const void *userData, 
        VfxU32 userDataSize
    );

    // Settings    
    VfxWeakPtr <VfxAnimatable>  m_targetPtr;        // Weak reference to target object.
    vrt_type_id_enum            m_targetType;       // Target data type.
    vrt_object_property_id_enum  m_targetPropertyId; // Target property type.

    VfxMsec m_startTime;        // Start time.
    VfxMsec m_durationTime;     // Duration time.
    VfxMsec m_updateDuration;   // Timeline update rate, unit is msec..
    VfxMsec m_repeatDuration;   // Duration time to start repeating.
    VfxS32  m_repeatCount;      // Repeat count.
    VfxFlag m_timelineFlags;    // Flags, see FLAGS_XXX

    vrt_timeline_timing_callback_struct *m_customTimingCallback;    // Custom timing callback function.
    vrt_timeline_interplation_callback_struct *m_customInterpolateCallback; // Custom interpolation callback function.

    struct TimelineTimeReferenceData
    {
        VfxBaseTimeline *referrerFirst;
        VfxBaseTimeline *referrerTail;
    };
    
    struct TimelineTimeReferrerData
    {
        VfxBaseTimeline *target;

        VfxFloat bias;
        VfxFloat scale;
        VfxTimelineTimeWrapTypeEnum wrapType;
        
        VfxBaseTimeline *next;
        VfxBaseTimeline *prev;
    };

    VfxAnimatableCustomVar *prepareCustomVariable();
    void removeCustomVariable();

    void addTimelineTimeReferrer(VfxBaseTimeline *referrer, VfxFloat scale, VfxFloat bias, VfxTimelineTimeWrapTypeEnum wrapType);
    void removeFromTimelineTimeReference();
    void removeAllTimelineTimeReferrer();

    VfxTimer *m_startTimer;     // Timer for start time.
    VfxTimer *m_stopTimer;      // Timer for stop time.

    void onStartTimerTick(VfxTimer *source);    // Timer callback to trigger started signal.
    void onStopTimerTick(VfxTimer *source);     // Timer callback to trigger stopped signal.
};


/***************************************************************************** 
 * Class VfxS32Timeline
 *****************************************************************************/

/*
 * VfxS32Timeline is timeline for target property type VfxS32.
 */
class VfxS32Timeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxS32Timeline);

// Constructor / Destructor    
public:
    // Default constructor
    VfxS32Timeline();

// Property
public:
    // Get from-value.
    VfxS32 getFromValue() const;

    // Get to-value.
    VfxS32 getToValue() const;

    // Set from-value.
    void setFromValue(VfxS32 value);

    // Set to-value.    
    void setToValue(VfxS32 value);

    // Set by-value.
    void setByValue(VfxS32 value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxS32 m_fromValue;
    // To-value or by-value of the timeline
    VfxS32 m_toByValue;
};


/***************************************************************************** 
 * Class VfxFloatTimeline
 *****************************************************************************/
 
/*
 * VfxFloatTimeline is timeline for target property type VfxFloat.
 */
class VfxFloatTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxFloatTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxFloatTimeline();

// Property
public:
    // Get from-value.
    VfxFloat getFromValue() const;
    
    // Get to-value.
    VfxFloat getToValue() const;

    // Set from-value.
    void setFromValue(VfxFloat value);
    
    // Set to-value.
    void setToValue(VfxFloat value);
    
    // Set by-value.
    void setByValue(VfxFloat value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxFloat m_fromValue;
    // To-value or by-value of the timeline
    VfxFloat m_toByValue;
};


/***************************************************************************** 
 * Class VfxColorTimeline 
 *****************************************************************************/
 
/*
 * VfxColorTimeline is timeline for target property type VfxColor.
 */
class VfxColorTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxColorTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxColorTimeline();

// Property
public:
    // Get from-value.
    const VfxColor &getFromValue() const;
    
    // Get to-value.
    const VfxColor &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxColor &value);
    
    // Set to-value.
    void setToValue(const VfxColor &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxColor m_fromValue;
    // To-value of the timeline
    VfxColor m_toValue;
};


/***************************************************************************** 
 * Class VfxPointTimeline 
 *****************************************************************************/
 
/*
 * VfxPointTimeline is timeline for target property type VfxPoint.
 */
class VfxPointTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxPointTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxPointTimeline();

// Property
public:
    // Get from-value.
    const VfxPoint &getFromValue() const;
       
    // Get to-value.
    const VfxPoint &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxPoint &value);
    
    // Set to-value.
    void setToValue(const VfxPoint &value);
    
    // Set by-value.
    void setByValue(const VfxPoint &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxPoint m_fromValue;
    // To-value or by-value of the timeline
    VfxPoint m_toByValue;
};


/***************************************************************************** 
 * Class VfxPointTimeline 
 *****************************************************************************/
 
/*
 * VfxS32Timeline is timeline for target property type VfxFPoint.
 */
class VfxFPointTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxFPointTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxFPointTimeline();

// Property
public:
    // Get from-value.
    const VfxFPoint &getFromValue() const;

    // Get to-value.
    const VfxFPoint &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxFPoint &value);
    
    // Set to-value.
    void setToValue(const VfxFPoint &value);
    
    // Set by-value.
    void setByValue(const VfxFPoint &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxFPoint m_fromValue;
    // To-value or by-value of the timeline
    VfxFPoint m_toByValue;
};


/***************************************************************************** 
 * Class VfxSizeTimeline 
 *****************************************************************************/
 
/*
 * VfxSizeTimeline is timeline for target property type VfxSize.
 */
class VfxSizeTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSizeTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxSizeTimeline();

// Property
public:
    // Get from-value.
    const VfxSize &getFromValue() const;
    
    // Get to-value.
    const VfxSize &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxSize &value);
    
    // set to-value.
    void setToValue(const VfxSize &value);
    
    // set by-value.
    void setByValue(const VfxSize &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxSize m_fromValue;
    // To-value or by-value of the timeline
    VfxSize m_toByValue;
};


/***************************************************************************** 
 * Class VfxRectTimeline 
 *****************************************************************************/
 
/*
 * VfxS32Timeline is timeline for target property type VfxRect.
 */
class VfxRectTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxRectTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxRectTimeline();

// Property
public:
    // Get from-value.
    const VfxRect &getFromValue() const;
    
    // Get to-value.
    const VfxRect &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxRect &value);
    
    // Set to-value.
    void setToValue(const VfxRect &value);
    
    // Set by-value.
    void setByValue(const VfxRect &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxRect m_fromValue;
    // To-value or by-value of the timeline
    VfxRect m_toByValue;
};


/***************************************************************************** 
 * Class VfxTransformTimeline 
 *****************************************************************************/
 
/*
 * VfxTransformTimeline is timeline for target property type VfxTransform.
 */
class VfxTransformTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxTransformTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxTransformTimeline();

// Property
public:
    // Get from-value.
    const VfxTransform &getFromValue() const;
    
    // Get to-value.
    const VfxTransform &getToValue() const;

    // Set from-value.    
    void setFromValue(const VfxTransform &value);
    
    // Set to-value.
    void setToValue(const VfxTransform &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxTransform m_fromValue;
    // To-value of the timeline
    VfxTransform m_toValue;
};


/***************************************************************************** 
 * Class VfxVector2fTimeline 
 *****************************************************************************/
 
/*
 * VfxVector2fTimeline is timeline for target property type Vector3f.
 */
class VfxVector2fTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxVector2fTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxVector2fTimeline();

// Property
public:
    // Get from-value.
    const VfxVector2f &getFromValue() const;
    
    // Get to-value.
    const VfxVector2f &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxVector2f &value);
    
    // Set to-value.
    void setToValue(const VfxVector2f &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxVector2f m_fromValue;
    // To-value of the timeline
    VfxVector2f m_toValue;
};



/***************************************************************************** 
 * Class VfxVector3fTimeline 
 *****************************************************************************/
 
/*
 * VfxVector3fTimeline is timeline for target property type Vector3f.
 */
class VfxVector3fTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxVector3fTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxVector3fTimeline();

// Property
public:
    // Get from-value.
    const VfxVector3f &getFromValue() const;
    
    // Get to-value.
    const VfxVector3f &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxVector3f &value);
    
    // Set to-value.
    void setToValue(const VfxVector3f &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxVector3f m_fromValue;
    // To-value of the timeline
    VfxVector3f m_toValue;
};



/***************************************************************************** 
 * Class VfxVector4fTimeline 
 *****************************************************************************/
 
/*
 * VfxVector4fTimeline is timeline for target property type Vector3f.
 */
class VfxVector4fTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxVector4fTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxVector4fTimeline();

// Property
public:
    // Get from-value.
    const VfxVector4f &getFromValue() const;
    
    // Get to-value.
    const VfxVector4f &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxVector4f &value);
    
    // Set to-value.
    void setToValue(const VfxVector4f &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxVector4f m_fromValue;
    // To-value of the timeline
    VfxVector4f m_toValue;
};


/***************************************************************************** 
 * Class VfxQuaternionfTimeline 
 *****************************************************************************/
 
/*
 * VfxQuaternionfTimeline is timeline for target property type Vector3f.
 */
class VfxQuaternionfTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxQuaternionfTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxQuaternionfTimeline();

// Property
public:
    // Get from-value.
    const VfxQuaternionf &getFromValue() const;
    
    // Get to-value.
    const VfxQuaternionf &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxQuaternionf &value);
    
    // Set to-value.
    void setToValue(const VfxQuaternionf &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxQuaternionf m_fromValue;
    // To-value of the timeline
    VfxQuaternionf m_toValue;
};


/***************************************************************************** 
 * Class VfxMatrix3fTimeline 
 *****************************************************************************/
 
/*
 * VfxMatrix3fTimeline is timeline for target property type Vector3f.
 */
class VfxMatrix3fTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxMatrix3fTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxMatrix3fTimeline();

// Property
public:
    // Get from-value.
    const VfxMatrix3f &getFromValue() const;
    
    // Get to-value.
    const VfxMatrix3f &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxMatrix3f &value);
    
    // Set to-value.
    void setToValue(const VfxMatrix3f &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxMatrix3f m_fromValue;
    // To-value of the timeline
    VfxMatrix3f m_toValue;
};


/***************************************************************************** 
 * Class VfxMatrix4fTimeline 
 *****************************************************************************/
 
/*
 * VfxMatrix4fTimeline is timeline for target property type Vector3f.
 */
class VfxMatrix4fTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxMatrix4fTimeline);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxMatrix4fTimeline();

// Property
public:
    // Get from-value.
    const VfxMatrix4f &getFromValue() const;
    
    // Get to-value.
    const VfxMatrix4f &getToValue() const;

    // Set from-value.
    void setFromValue(const VfxMatrix4f &value);
    
    // Set to-value.
    void setToValue(const VfxMatrix4f &value);
    
// Override    
protected:
    virtual void onUpdateTimelineValue();

// Implementation
private:
    // From-value of the timeline
    VfxMatrix4f m_fromValue;
    // To-value of the timeline
    VfxMatrix4f m_toValue;
};

#ifdef __VENUS_3D_UI_ENGINE__

/***************************************************************************** 
 * Class VfxKeyframeSequence
 *****************************************************************************/

/*
 * VfxKeyframeSequence is used for run-time keyframe sequence data.
 */
class VfxKeyframeSequence : public VfxObject
{
// Constructor / Destructor
public:
    // Constructor with key count and type.
    VfxKeyframeSequence(VfxU32 keyCount, VfxTypeIdEnum typeId);

// Property
public:
    // Set keyframe time and value at index.
    void setKeyframe(VfxId index, VfxMsec time, void *value);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implementation
private:
    friend class VfxKeyframeTimeline;

    static VfxU32 getKeyframeDataSize(VfxU32 keyCount, VfxTypeIdEnum typeId);

    VfxU32 getDataSize() const;    

    VfxU32 m_keyCount;
    VfxTypeIdEnum m_typeId;
    VfxU8 *m_keyframeData;
};


/***************************************************************************** 
 * Class VfxKeyframeTimeline
 *****************************************************************************/

/*
 * VfxKeyframeTimeline is timeline using keyframe sequence interpolation.
 */
class VfxKeyframeTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_CLASS(VfxKeyframeTimeline);
    VFX_DECLARE_NO_COPY_CLASS(VfxKeyframeTimeline);
    
// Constructor / Destructor
public:
    // Default constructor
    VfxKeyframeTimeline(VfxKeyframeSequence *kfs = NULL);

// Property
public:
    // Set keyframe interpolation function.
    void setKeyframeInterpolation(VfxInterpolationFuncIdEnum interpolation);

    // Set keyframe sequence data from asset source.
    void setKeyframeSource(const VfxAssetSrc &kfsSrc);

    // Set keyframe sequence data object.
    void setKeyframeSequence(VfxKeyframeSequence *kfs);

    // Get keyframe sequence data object.
    VfxKeyframeSequence *getKeyframeSequence() const;

// Override    
protected:
    virtual void onInit();

    virtual VfxBool onQueryHasFromToValue() const;
    virtual void onUpdateTimelineValue();
    virtual void onUpdateCustomInterpolateCallback();
    
// Implementation
private:
    VfxTimelineInterpolateFuncPtr m_keyframeInterpolationCallback;
    VfxAssetSrc m_keyframeSource;
};

#endif /* __VENUS_3D_UI_ENGINE__ */

/***************************************************************************** 
 * Class VfxAnimation 
 *****************************************************************************/

/*
 * VfxAnimation is a collection of timelines.
 */
class VfxAnimation : public VfxObject
{
    //VFX_DECLARE_CLASS(VfxAnimation);
    VFX_DECLARE_NO_COPY_CLASS(VfxAnimation);
    
// Constructor / Destructor    
public:
    // Default constructor
    VfxAnimation() : 
        m_isEnabled(VFX_FALSE)
    {
    }

// Method
public:
    // Whether the animation is enabled.
    VfxBool getIsEnabled() const
    {
        return m_isEnabled;
    }

    // Start all timelines
    void start();
    // Stop all timelines
    void stop();

    // Caculate the total duration of all child timelines.
    //
    // RETURNS: the total duration of all child timelines.
    VfxMsec getTotalDuration() const;

    // Assign the timing function with timing function ID to all timelines
    //
    // SEE ALSO: VfxTimingFuncIdEnum
    void setTimingFunc(
        VfxTimingFuncIdEnum value
    );

    // Assign the timing function with customized timing function to all timelines
    // 
    // SEE ALSO: VfxTimelineTimingFuncPtr
    void setCustomTimingFunc(
        VfxTimelineTimingFuncPtr callback,  // [IN] The callback function to assign
        const void *userData,               // [IN] The user data of timing function
        VfxU32 userDataSize                 // [IN] The size of user data 
    );                   

    // Assign the interpolation function to all timelines
    // 
    // SEE ALSO: VfxTimelineInterpolateFuncPtr
    void setCustomInterpolateFunc(
        VfxTimelineInterpolateFuncPtr callback, // [IN] The callback function to assign
        const void *userData,                   // [IN] The user data of callback function
        VfxU32 userDataSize                     // [IN] The size of user data 
    );

    // Set timeline time to all timelines 
    void setTimelineTime(
        VfxBaseTimeline *time,
        VfxFloat scale = 1.0f,
        VfxFloat bias = 0.0f,
        VfxTimelineTimeWrapTypeEnum wrapType = VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP
    );

// Override
protected:
    void onAddChild(VfxObject *objChild);
    void onRemoveChild(VfxObject *objChild);
    virtual void onObjectNotify(VfxId eventId, void *userData);

// Implementation
private:
    VfxBool m_isEnabled;
    VfxObjList m_timelineList;
};

#endif /* __VFX_ANIMATION_H__ */

