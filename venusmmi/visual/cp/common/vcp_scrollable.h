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
 *  vcp_scrollable.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Scrollable class header file
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
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VCP_SCROLLABLE_H__
#define __VCP_SCROLLABLE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_input_event.h"
#include "vrt_datatype.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_primitive_frame.h"



class VcpScrollableView;

/***************************************************************************** 
 * class VcpScrollIndicator
 *****************************************************************************/
/*
 * scroll bar indicator class
 */ 
class VcpScrollIndicator : public VfxFrame
{
// Declaration
public:
    // <group DOM_Scrollable_VcpScrollIndicator_Enum>
    // indicator style
    enum
    {
        VCP_SCROLL_INDICATOR_STYLE_HORIZONTAL = 0,
        VCP_SCROLL_INDICATOR_STYLE_VERTICAL = 1,
        VCP_SCROLL_INDICATOR_STYLE_NONE
    };

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        SCROLL_INDICATOR_WIDTH = 10,
    #elif defined(__MMI_MAINLCD_320X480__)
        SCROLL_INDICATOR_WIDTH = 6,
    #else
        SCROLL_INDICATOR_WIDTH = 6,
    #endif

        SCROLL_INDICATOR_MIN_SIZE = 6,
        UNKNOWN_VALUE = -99999
    };
private:
    struct FramePropertyEffectData
    {
        VfxPoint contentOrigin;
        VfxS32 range;
        VfxS32 scale;
        VfxU32 style;
        VfxU32 minSize;
        VfxS32 width;
        VfxS32 height;
    };

    static vrt_render_dirty_type_enum indicatorEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

// Constructor / Destructor
public:
    // <group DOM_Scrollable_VcpScrollIndicator_Constructor/Destructor>
    // Default constructor
    VcpScrollIndicator();

// Method
public:
    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Sets the scroll range
    void setScrollRange(
        VfxS32 size // [IN] range
    );

    
    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Sets the scroll scale.
    void setScrollScale(
        VfxS32 scale    // [IN] scale
    );

    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Sets the style
    void setStyle(
        VfxU32 style    // [IN] style
    );

    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Sets the indicator color.
    void setIndicatorColor(
        const VfxColor &value   // [IN] indicator color
    );

    // Sets the indicator image.
    void setIndicatorImg(
        const VfxImageSrc &value // [IN] indicator image
    );
    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Sets the indicator minimum size.
    void setIndicatorMinSize(
        VfxU32 minSize  // [IN] minimum size
    );

    // <group DOM_Scrollable_VcpScrollIndicator_Method>
    // Gets the indicator minimum size.
    // RETURNS: indicator minimum size in pixels
    VfxU32 getIndicatorMinSize();

    void setTargetFPE(VcpScrollableView* view);
	void checkUpdate();
// Overridable
protected:
    virtual void onInit();

// Method
protected:
    void onUpdate();
	void processUpdate();

// Implementation
private:
    VfxFrame *m_indicator;
    VcpScrollableView *m_view;

    VfxS32 m_range;
    VfxS32 m_scale;
    VfxU32 m_style;
    VfxU32 m_minSize;
	VfxBool	m_checkUpdate;
};


/***************************************************************************** 
 * class VcpScrollableView
 *****************************************************************************/

/*
 * Scrollable view is a child frame of Scrollable. Internal usage.
 */
class VcpScrollableView : public VfxControl
{
    VFX_DECLARE_CLASS(VcpScrollableView);
// Constructor / Destructor
public:
    friend class VcpScrollable;
    // Default constructor
    // <group DOM_Scrollable_VcpScrollableView_Constructor/Destructor>
    VcpScrollableView();

// Method
public:
    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the scrollable content width and height.
    void setContentSize(
        const VfxSize &contentSize  // [IN] content size
    )
    {
        m_contentSize = contentSize;
        startMonitor();
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the scrollable content width and height.
    // RETURNS: the scrollable content size
    const VfxSize &getContentSize() const
    {
        return m_contentSize;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the left elastic margin in percent of the bounds width.
    void setLeftElasticMargin(
        VfxFloat leftElasticMargin  // [IN] left elastic margin in percent
    )
    {
        m_elasticMargin[0] = leftElasticMargin;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the left elastic margin in percent of the bounds width.
    // RETURNS: the left elastic margin
    VfxFloat getLeftElasticMargin() const
    {
        return m_elasticMargin[0];
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the right elastic margin in percent of the bounds width.
    void setRightElasticMargin(
        VfxFloat rightElasticMargin // [IN] right elastic margin in percent
    )
    {
        m_elasticMargin[2] = rightElasticMargin;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the right elastic margin in percent of the bounds width.
    // RETURNS: the right elastic margin
    VfxFloat getRightElasticMargin() const
    {
        return m_elasticMargin[2];
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the top elastic margin in percent of the bounds height.
    void setTopElasticMargin(
        VfxFloat topElasticMargin   // [IN] top elastic margin in percent
    )
    {
        m_elasticMargin[1] = topElasticMargin;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the top elastic margin in percent of the bounds height.
    // RETURNS: the top elastic margin
    VfxFloat getTopElasticMargin() const
    {
        return m_elasticMargin[1];
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the bottom elastic margin in percent of the bounds height.
    void setBottomElasticMargin(
        VfxFloat bottomElasticMargin    // [IN] bottom elastic margin in percent
    )
    {
        m_elasticMargin[3] = bottomElasticMargin;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the bottom elastic margin in percent of the bounds height.
    // RETURNS: the bottom elastic margin
    VfxFloat getbottomElasticMargin() const
    {
        return m_elasticMargin[3];
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the warning content rect.
    void setWarningContentRect(
        VfxRect &rect   // [IN] warning content rect
    );

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the warning content rect.
    // RETURNS: warning content rect
    VfxRect getWarningContentRect()
    {
        return m_warningContentRect;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the valid content rect.
    void setValidContentRect(
        VfxRect &rect   // [IN] valid content rect
    );

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the valid content rect.
    // RETURNS: valid content rect
    VfxRect getValidContentRect()
    {
        return m_validContentRect;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Stops scrolling.
    void stopScrolling();

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets the content origin.
    void setContentOrigin(
        const VfxPoint &origin   // [IN] content origin point
    )
    {
        m_contentOrigin = origin;  
		startMonitor();
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets the content origin.
    // RETURNS: content origin
    VfxPoint getContentOrigin()
    {
        return m_contentOrigin;
    }


    // enable or disable view intersection to the current screen size
    void enableIntersectScreen(
        VfxBool isIntersect    // [IN] enable or not
    )        
    {
        m_isIntersectScreen = isIntersect;
        
        if (!isIntersect)
        {
            m_intersectRect = VFX_RECT_ZERO;
        }
        
        startMonitor();
    }


    // Gets if intersect screen enabled
    // RETURNS: enabled or not
    VfxBool getIsIntersectScreen()
    {
        return m_isIntersectScreen;
    }


    // Gets current intersected screen rect
    // RETURNS: the intersected screen rect
    VfxRect getIntersectRect()
    {
        if(m_isIntersectScreen)
        {
            return m_intersectRect;
        }
        else
        {
            return VFX_RECT_ZERO;
        }
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Sets free run moving unit 
    void setFreeRunUnit(
        VfxSize unit    // [IN] unit size
    )
    {
        m_unit = unit;
    }

    // <group DOM_Scrollable_VcpScrollableView_Method>
    // Gets free run unit
    // RETURNS: the unit size
    VfxSize getFreeRunUnit()
    {
        return m_unit;
    }

    
// Variable
public:
    struct MonitorData
    {
        VfxRect screenBounds;
        VcpScrollableView *view;
        VfxU32  signature;
        VfxRect validRect;
        VfxRect warningRect;
        VfxSize contentSize;        
		VfxPoint contentOrigin;
    };
    // <group DOM_Scrollable_VcpScrollableView_Event>
    // scroll start notification
    VfxSignal1 <VfxBool> m_signalScrollStarted;

    // <group DOM_Scrollable_VcpScrollableView_Event>
    // scroll stop notification
    VfxSignal2<VfxBaseTimeline*, VfxBool> m_signalScrollStopped;    

    // <group DOM_Scrollable_VcpScrollableView_Event>
    // scrolling notification, only emit in pen move
    VfxSignal2<VfxPoint, VfxRect> m_signalScrolling;

    // <group DOM_Scrollable_VcpScrollableView_Event>
    // content warning signal
    VfxSignal1<VcpScrollableView*> m_signalContentWarning;
    
    // <group DOM_Scrollable_VcpScrollableView_Event>
    // content error signal (out of valid content rect)
    VfxSignal1<VcpScrollableView*> m_signalContentError;

    // <group DOM_Scrollable_VcpScrollableView_Property>
    // valid content rect
    VfxRect m_validContentRect;
    
    // <group DOM_Scrollable_VcpScrollableView_Property>
    // warning content rect
    VfxRect m_warningContentRect;

    // <group DOM_Scrollable_VcpScrollableView_Property>
    // is between pen down and up
    VfxBool m_isTracking;
    
    // <group DOM_Scrollable_VcpScrollableView_Property>
    // is pen dragging
    VfxBool m_isDragging;
    
    // <group DOM_Scrollable_VcpScrollableView_Property>
    // is free running    
    VfxBool m_isDecelerating;

    // <group DOM_Scrollable_VcpScrollableView_Property>
    // is Resizing    
    VfxBool m_isResizing;
        
    // <group DOM_Scrollable_VcpScrollableView_Property>
    // content origin
    VfxPoint m_contentOrigin;

    // free run moving unit
    VfxSize m_unit;

// Overridable
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

    virtual void onFreeRunSetTargetContentOffset(VfxPoint &offset) { VFX_UNUSED(offset); }


    virtual VfxBool onPenAbortAccepted(
        VfxControl *aborter, 
        VfxPenAbortReasonEnum reason
    );
public:
    virtual void setBounds(const VfxRect &value);
    enum
    {
		VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_LEFT,
        VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_TOP,
        VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_RIGHT,
        VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_BOTTOM,
        VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_NONE,        
        VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_END
    };

    VfxBool m_isResumedParent;
    VfxS32 m_limitDirection;
    VfxBool m_isLimited;
    VcpScrollableView *m_parentScrollableView;

// Implementation
protected:
    VfxSize m_contentSize;

    VfxFloat m_elasticMargin[4]; //left, top, right, bottom
    
    VfxFloat m_marginForceFactor;

    VfxBool m_isBounce[2];
    VfxFloat m_slowFactor[2];
    
    VfxFloat m_freeRunSlowFactor;

    VfxRectTimeline *m_freeRunTl, *m_recoverTl, *m_boundsTl;

    VfxBool m_boundsTlNeedMerge;
// Implementation
private:
    static void emitContentWarning(void *);
    static void emitContentError(void *);
	static void emitContentWarningError(void *);
    static vrt_bool isContainRect(vrt_rect_struct *a, vrt_rect_struct *b);
    static vrt_frame_property_monitor_type_enum boundsMonitorFuncCallback(vrt_frame_property_handle target_frame, void *user_data, vrt_u32 user_data_size);

    void setBoundsInternal(const VfxRect &value, VfxBool isForced = VFX_FALSE);
    void startMonitor();
    VfxBool limitBoundsOrigin(const VfxRect &bounds, VfxS32 *x, VfxS32 *y);
    VfxBool stopBoundsAnimation();

    void onScrollAnimRecover(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onScrollAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void rectToCoord(const VfxRect &rect, VfxS32 *x1, VfxS32 *y1, VfxS32 *x2, VfxS32 *y2);
    VfxRect getElasticRect();
    VfxS32 limitElasticDragMovement(VfxS32 origin, VfxS32 pos, VfxS32 contentSize, VfxS32 boundsSize);

    // deceleration related
    void getDecelerateStopData(VfxFloat v0, VfxFloat a, VfxFloat *stopT, VfxFloat *dist);
    void getDecelerateBounceStopData(VfxFloat *v0, VfxFloat *a, VfxS32 origin, VfxS32 direction, VfxFloat *stopT, VfxFloat *dist);
    VfxFloat getDecelerateTimeByDist(VfxFloat v0, VfxFloat a, VfxS32 moveDist);

    VfxBool updateBoundsValue(VfxRect rect);
	void onPenDown();
    void onPenMoveTimerTick(VfxTimer *source);
    void onPenDownTimerTick(VfxTimer *source);

    VfxBool resumeParentScrollable(VfxPenEvent &event);


private:    
    
    VfxBool m_isPenDown;
    VfxPoint m_penDownOrigin;

    VfxS32 m_maxScrollDist[2];
    
    VfxBool m_isToSendWarning, m_isToSendError;
    VfxBool m_isAbleSendWarning, m_isAbleSendError;
	VfxMsec m_lastUpdateTime;



    // signature to verify scrollable life
    VfxU32 m_signature;

    VfxBool m_isCapturing, m_sureDragging;
    VfxBool m_isPenDownWhenDecelerating;


    // pen down timer
    VfxTimer *m_penDownTimer;
    // pen move timer
    VfxTimer *m_penMoveTimer;

	VfxFloat m_freeRunPara[4];

    VfxBool m_isIntersectScreen;
    VfxRect m_intersectRect;
    // constants
    enum
    {
        FREE_RUN_START_TIME_THRESHOLD = 800,
        FREE_RUN_START_MIN_TIME_THRESHOLD = 5,
        FREE_RUN_TIME_DURATION = 600,
        RECOVER_TIME_DURATION = 250,
        FREE_RUN_START_MOVE_THRESHOLD = 5,
#if defined(__MMI_MAINLCD_480X800__)
        DRAG_START_MOVE_THRESHOLD = 40
#else
        DRAG_START_MOVE_THRESHOLD = 20
#endif        
    };

    // constants
    static const VfxFloat ELASTIC_LEFT_MARGIN;
    static const VfxFloat ELASTIC_RIGHT_MARGIN;
    static const VfxFloat ELASTIC_TOP_MARGIN;
    static const VfxFloat ELASTIC_BOTTOM_MARGIN;
    static const VfxFloat MARGIN_FORCE_FACTOR;

    static const VfxFloat MAX_BOUNCE_VELOCITY;
    static const VfxFloat FRICTION_DECELERATION;
    static const VfxFloat INITIAL_VELOCITY_FACTOR;
    static const VfxFloat MAX_INITIAL_VELOCITY;

};


/***************************************************************************** 
 * Class VcpScrollable
 *****************************************************************************/

/*
 * Scrollable is a simple scrollable view implementation to support smooth scrolling.
 *
 * EXAMPLE:
 * <code>
 *   VFX_OBJ_CREATE(m_scrollable, VcpScrollable, this);
 *   m_scrollable->setPos(VfxPoint(MAIN_POS_X, MAIN_POS_Y));
 *   m_scrollable->setBounds(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT));
 *   m_scrollable->setContentSize(VfxSize(MAIN_WIDTH, NUM_OF_ALM * VappHsWidgetAlarmItem::HEIGHT));
 *   m_scrollable->setViewRect(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT)); 
 * </code>
 */
class VcpScrollable : public VfxControl
{
    VFX_DECLARE_CLASS(VcpScrollable);
// Declaration
public:
    // <group DOM_Scrollable_VcpScrollable_Enum>
    // scroll bar indicator style enum
    enum VcScrollableScrollIndicatorStyleEnum
    {        
        VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_NONE,         // no scroll bar
        VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED,        // fixed scroll bar style        
        VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_AUTO_HIDE,    // auto-hidden scroll bar style
        VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_OVERLAY,      // overlay scroll bar style
        VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_END_OF_ENUM
    };

    // data for displaying boundary light   
	struct BoundaryLightData
	{
		VfxFPoint anchor;
		VfxRect rect;	
		VfxS32 direction;
	};

// Constructor / Destructor
public:
    // <group DOM_Scrollable_VcpScrollable_Constructor/Destructor>
    // Constructor
    VcpScrollable();

// Method
public:    
    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the content size.
    void setContentSize(
        const VfxSize &size // [IN] content size
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the content size.
    // RETURNS: content size
    VfxSize getContentSize()
    {
        return m_view->getContentSize();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the view rect inside the scrollable
    void setViewRect(
        const VfxRect &rect // [IN] view rect
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the scroll bar style.
    void setScrollIndicatorStyle(
        VcScrollableScrollIndicatorStyleEnum style    // [IN]  scroll bar style
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Enables the horizontal scroll bar.
    void enableHorizontalScrollIndicator(
        VfxBool isEnable    // [IN]  enable flag
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Enables the vertical scroll bar.
    void enableVerticalScrollIndicator(
        VfxBool isEnable    // [IN]  enable flag
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Enables bounce in the margin area.
    void enableBounce(
        VfxBool isHorizontalBounce, // [IN] horizontal bounce enable flag (default disabled)
        VfxBool isVerticalBounce    // [IN] vertical bounce enable flag (default enabled)
    )
    {
        VFX_UNUSED(isHorizontalBounce);
        VFX_UNUSED(isVerticalBounce);
        // m_view->m_isHBounce = isHorizontalBounce;
        // m_view->m_isVBounce = isVerticalBounce;
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the content offset.
    void setContentOffset(
        VfxPoint offset,                // [IN] content offset
        VfxBool isAnimated = VFX_FALSE  // [IN] is animated
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Makes the specified rect visible.
    void scrollRectToVisible(
        VfxRect rect,                   // [IN] visible rect
        VfxBool isAnimated = VFX_FALSE  // [IN] is animated
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the deceleration distance limit.
    void setMaxDecelerationDistance(
        VfxS32 horizontalDist,          // [IN] horizontal distance
        VfxS32 verticalDist             // [IN] vertical distance
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the warning content rect.
    void setWarningContentRect(
        VfxRect rect    // [IN]  warning content rect
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the warning content rect.
    // RETURNS: warning content rect
    VfxRect getWarningContentRect()
    {
        return m_view->getWarningContentRect();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the valid content rect.
    void setValidContentRect(
        VfxRect rect    // [IN] valid content rect
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the valid content rect.
    // RETURNS: valid content rect
    VfxRect getValidContentRect()
    {
        return m_view->getValidContentRect();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the current view bounds.
    // RETURNS: current view bounds
    VfxRect getViewBounds()
    {
        return m_view->forceGetBounds();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets slow factors for horizontal/vertical dragging and free run.
    void setSlowFactor(
        VfxFloat horizontalFactor,  // horizontal margin slow factor
        VfxFloat verticalFactor,    // vertical margin slow factor
        VfxFloat freerunFactor      // free run slow factor
    )
    {
        m_view->m_slowFactor[0] = horizontalFactor;
        m_view->m_slowFactor[1] = verticalFactor;
        m_view->m_freeRunSlowFactor = freerunFactor;
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the scroll indicator color.
    void setScrollIndicatorColor(
        const VfxColor &value   // [IN] indicator color
    )
    {
        m_indicatorColor = value;
        if(m_scrollIndicator[0])
        {
            m_scrollIndicator[0]->setIndicatorColor(value);
        }
        if(m_scrollIndicator[1])
        {
            m_scrollIndicator[1]->setIndicatorColor(value);
        }
    }    

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the scroll indicator color.
    // RETURNS: indicator color
    VfxColor getScrollIndicatorColor()
    {
        return m_indicatorColor;     
    } 

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the scroll indicator image.
    void setScrollIndicatorImg(
        const VfxImageSrc &value   // [IN] indicator image
    )
    {
        m_indicatorImg = value;
        if(m_scrollIndicator[0])
        {
            m_scrollIndicator[0]->setIndicatorImg(value);
        }
        if(m_scrollIndicator[1])
        {
            m_scrollIndicator[1]->setIndicatorImg(value);
        }
    }

		
    // <group DOM_Scrollable_VcpScrollable_Method>
    // Stops scrolling.
    void stopScrolling()
    {
        m_view->stopScrolling();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets the content origin.
    void setContentOrigin(
        const VfxPoint &origin   // [IN] content origin point
    );

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets the content origin.
    // RETURNS: content origin
    VfxPoint getContentOrigin()
    {
        return m_view->getContentOrigin();
    }

    // enable or disable view intersection to the current screen size
    void enableIntersectScreen(VfxBool isIntersect)
    {
        m_view->enableIntersectScreen(isIntersect);
    }


    // Gets if intersect screen enabled
    // RETURNS: enabled or not    
    VfxBool getIsIntersectScreen()
    {
        return m_view->getIsIntersectScreen();
    }

    // Gets current intersected screen rect
    // RETURNS: the intersected screen rect
    VfxRect getIntersectRect(){
        return m_view->getIntersectRect();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets free run moving unit 
    void setFreeRunUnit(VfxSize unit)
    {
        m_view->setFreeRunUnit(unit);
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Gets free run unit
    // RETURNS: the unit size
    VfxSize getFreeRunUnit()
    {
        return m_view->getFreeRunUnit();
    }

    // <group DOM_Scrollable_VcpScrollable_Method>
    // Sets bg color to view
    void setViewBgColor(const VfxColor &value)
    {    
        m_view->setBgColor(value);
    }

    // Enable boundary or not
	void enableBoundaryLight(VfxBool isLight)
	{
		m_isBoundaryLight = isLight;
	}

    // Sets boundary light color
	void setBoundaryLightColor(const VfxColor &value)
	{
		m_boundaryLightColor = value;	
	}
    

// Overridable
public:
    // <group DOM_Scrollable_VcpScrollable_Overridable>
    // Creates the view.
    // RETURNS: created view object
    virtual VcpScrollableView *onCreateView();

    // <group DOM_Scrollable_VcpScrollable_Overridable>
    // Closes the view.
    virtual void onCloseView();

    // <group DOM_Scrollable_VcpScrollable_Overridable>
    // Sets bounds.
    virtual void setBounds(
        const VfxRect &value    // [IN] bounds rect
    );

    // <group DOM_Scrollable_VcpScrollable_Overridable>
    // Set the bounds rectangle of the frame
    void setBounds(
        VfxS32 x,                   // [IN] The x coordinate to set
        VfxS32 y,                   // [IN] The y coordinate to set
        VfxS32 width,               // [IN] The width to set
        VfxS32 height               // [IN] The height to set
    )
    {
        setBounds(VfxRect(x, y, width, height));
    }


protected:
    virtual void onInit();
    virtual void onDeinit();
    void onAddChild(VfxObject *child);  
	virtual void onObjectNotify(VfxId id, void *userData);
    void onParentFrameChanged(
        VfxFrame *origParentFrame   // The original parent frame
    );
    
    void updateIndicator();

public:
    VfxBool updateViewForIme(VfxFrame * focusFrame);
    virtual void setAutoAnimate(VfxBool value)
    {
        m_view->setAutoAnimate(value);
        VfxControl::setAutoAnimate(value);
    }

// Variable
public:
    // <group DOM_Scrollable_VcpScrollable_Event>
    // scroll start signal. This signal is invoked when scrolling starts.
    VfxSignal1<VcpScrollable*> m_signalScrollStarted;

	// <group DOM_Scrollable_VcpScrollable_Event>
    // scrolling signal. This signal is invoked when scrolling.
    VfxSignal1<VcpScrollable*> m_signalScrolling;
    
    // <group DOM_Scrollable_VcpScrollable_Event>
    // scroll stop signal. This signal is invoked when scrolling stops.
    VfxSignal1<VcpScrollable*> m_signalScrollStopped;
    
    // <group DOM_Scrollable_VcpScrollable_Event>
    // content warning signal. This signal is invoked when the bounds is out of the warning rect.
    VfxSignal1<VcpScrollableView*> m_signalContentWarning;
    
    // <group DOM_Scrollable_VcpScrollable_Event>
    // content error signal (out of valid rect). This signal is invoked 
    // when the bounds is out of the valid rect and VRT will freeze the display
    // to wait for the application to fill up the new content in the empty area.
    VfxSignal1<VcpScrollableView*> m_signalContentError;

    // <group DOM_Scrollable_VcpScrollable_Method>
    // free run started signal. This signal is invoked 
    // when the view starts to do free run animation
    VfxSignal1<VcpScrollableView*> m_signalStartFreerun;    
    
// Implementation
protected:    
    virtual void onScrollStart(VfxBool isShowIndicator);
    virtual void onScrollStop(VfxBaseTimeline *timeline, VfxBool isCompleted); 
    virtual void onScrolling(VfxPoint origin, VfxRect elasticRect);
    virtual void onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);

    VcpScrollIndicator *m_scrollIndicator[2];
    VcpScrollableView *m_view;

// Implementation
private:    
    void emitContentWarning(VcpScrollableView *view)
    {
        m_signalContentWarning.emit(view);
    }

    void emitContentError(VcpScrollableView *view)
    {
        m_signalContentError.emit(view);
    }

    void emitStartFreerun(VcpScrollableView *view)
    {
        m_signalStartFreerun.emit(view);
    }
    void showScrollIndicator();
    void onCreateIndicators(VfxBool fixed = VFX_FALSE);

  	void showBoundaryLight(VfxPoint origin, VfxRect elasticRect);
	void onCreateBoundaryLight(BoundaryLightData userdata);

private:
    enum
    {
        SCROLL_INDICATOR_SIZE = VcpScrollIndicator::SCROLL_INDICATOR_WIDTH,
        SCROLL_INDICATOR_FADE_OUT_DURATION = 500        
    };
    
    static const VfxFloat SCROLL_INDICATOR_OPACITY;    
    
    VcScrollableScrollIndicatorStyleEnum m_scrollIndicatorStyle;

    VfxBool m_isEnableIndicator[2];

    
    VfxColor m_indicatorColor;
    VfxImageSrc m_indicatorImg;
    VfxRect m_viewRect;
    
    VcpScrollableView *m_parentScrollableView;
	 
	VfxImageFrame *m_boundaryLight;
    VfxBool m_isBoundaryLight;
	VfxColor m_boundaryLightColor;


	
    friend class VcpScrollableView;
};


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __VCP_SCROLLABLE_H__ */


