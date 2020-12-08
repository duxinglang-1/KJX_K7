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
 *  vcp_activity_indicator.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Activity and progress indicator components
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
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "GlobalResDef.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_res.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_activity_indicator.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "mmi_rp_srv_venus_component_activity_indicator_def.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"
#include "vfx_signal.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpActivityIndicator 
 *****************************************************************************/  
void VcpActivityIndicator::onInit()
{
    VfxFrame::onInit();

    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_image, VfxControl, this); 
    setHiddenWhenStopped(VFX_TRUE); 

    for (VfxS32 i = 0; i < BALL_NUM; i++)
    {            
        VFX_OBJ_CREATE(m_ball[i], VfxImageFrame, this);
        m_ball[i]->setAnchor(0.5f, 0.5f);
        m_ball[i]->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
    }    

    //setAnchor(0.5f, 0.5f);
    m_signalBoundsChanged.connect(this, &VcpActivityIndicator::onBoundsChanged);
    setSize(WIDTH, HEIGHT); 
}


void VcpActivityIndicator::setBounds(const VfxRect &value)
{
    if (value != m_bounds)
    {
        onSize(value);
    }

    VfxFrame::setBounds(value);
}


void VcpActivityIndicator::onSize(const VfxRect &bounds)
{
    if (m_image)
    {
        m_image->setSize(bounds.size);
        m_image->setPos(bounds.size.width / 2, bounds.size.height / 2);
    }
}


void VcpActivityIndicator::start()
{
    if (m_isAnimating)
    {
        return;
    }

	for (VfxS32 i = 0; i < BALL_NUM; i++)
    {
        m_ball[i]->setOpacity(0.2f);
    }  
    setHidden(VFX_FALSE);

    VfxObjHandle visualObjHandle = getObjHandle();
    watchFrameFPEUserDataStruct watchFrameUserData;

    watchFrameUserData.visual = visualObjHandle;
    watchFrameUserData.lastUpdateTime = 0;
    
    // Set FPE to binding frame for only one dirty rectangle everytime 
    setPropertyEffectCallback(
                this,
                &VcpActivityIndicator::watchFramePropertyEffectCallback, 
                &watchFrameUserData, 
                sizeof(watchFrameFPEUserDataStruct),
                VRT_FPE_TRIGGER_TYPE_EVERYTIME); 

    VfxMsec startTime = (VfxMsec)vrt_get_current_frame_time();

    for (VfxS32 i = 0; i < BALL_NUM; i++)
    {
        ballFPEUserDataStruct userData;

        userData.visual = visualObjHandle;
        userData.lastUpdateTime = 0;
        userData.startTime = startTime;
        userData.index = i;
        
        m_ball[i]->setPropertyEffectCallback(
                this,
                &VcpActivityIndicator::ballFramePropertyEffectCallback, 
                &userData, // UI engine will copy the user data 
                sizeof(ballFPEUserDataStruct),
                VRT_FPE_TRIGGER_TYPE_EVERYTIME); 
    }

    m_isAnimating = VFX_TRUE;
}


void VcpActivityIndicator::stop()
{
    if (m_isAnimating)
    {
        // stop playing
        setPropertyEffectCallback(
                            NULL,
                            NULL,
                            NULL,
                            0);

        for (VfxS32 i = 0; i < BALL_NUM; i++)
        {
            m_ball[i]->setPropertyEffectCallback(
                            NULL,
                            NULL,
                            NULL,
                            0);
        }
        m_isAnimating = VFX_FALSE;
    }

    // auto hidden if stopped
    if (getHiddenWhenStopped())
    {
        setHidden(VFX_TRUE);
    }
}


vrt_render_dirty_type_enum VcpActivityIndicator::watchFramePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(watch_frame != NULL);

    watchFrameFPEUserDataStruct *fpeUserData = (watchFrameFPEUserDataStruct *)user_data;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VfxMsec curTime = (VfxMsec)vrt_get_current_frame_time();

    if (fpeUserData->lastUpdateTime == 0 ||
        curTime - fpeUserData->lastUpdateTime >= VCP_ACTIVITY_INDICATOR_UPDATE_INTERVAL)
    {
        fpeUserData->lastUpdateTime = curTime; // FPS control

        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }        

    return VRT_RENDER_DIRTY_TYPE_NONE;
}


vrt_render_dirty_type_enum VcpActivityIndicator::ballFramePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(watch_frame != NULL);

    ballFPEUserDataStruct *fpeUserData = (ballFPEUserDataStruct *)user_data;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    VfxMsec curTime = (VfxMsec)vrt_get_current_frame_time();

    if (!(fpeUserData->lastUpdateTime == 0 ||
        curTime - fpeUserData->lastUpdateTime >= VCP_ACTIVITY_INDICATOR_UPDATE_INTERVAL))
    {
        return VRT_RENDER_DIRTY_TYPE_NONE; // FPS control
    }   

    fpeUserData->lastUpdateTime = curTime;

    VfxMsec startTime = fpeUserData->startTime + (fpeUserData->index * BALL_TIME);
        
    if (startTime > curTime)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    VfxFloat t = ((VfxFloat)((curTime - startTime) % REPEAT_DURATION)) / REPEAT_DURATION;

    VfxFloat data[4] = { 0.42f, 0.0f, 0.58f, 1.0f }; // Bezier control points
        
    VfxFloat transformTime = easyInOutTimingFuncBezier(t, data, sizeof(vrt_float) * 4); // For easy in easy out timing
                
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;

    target_frame->transform.data.affine.sx = interpolateFloat(BALL_SCALE_RATIO_MAX, BALL_SCALE_RATIO_MIN, transformTime);

    target_frame->transform.data.affine.sy = interpolateFloat(BALL_SCALE_RATIO_MAX, BALL_SCALE_RATIO_MIN, transformTime);

    VfxFloat opacityTime = t;

    target_frame->opacity = interpolateFloat(1.0f, BALL_OPACITY_MIN, opacityTime); // Linear timing

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}



VfxFloat VcpActivityIndicator::easyInOutTimingFuncBezier(VfxFloat x, void *data, VfxU32 data_size)
{
    VfxS32 i;
    VfxFloat *control_point;
    VfxFloat by, bx, x1, x2, y1, y2;
    VfxFloat c0, c1, c2;
    VfxFloat lt, rt, t;
    /* x must be in [0, 1]. */
    VFX_ASSERT((x >= 0.0f) && (x <= 1.0f));
    
    control_point = (VfxFloat*)data;
    x1 = control_point[0];
    y1 = control_point[1];
    x2 = control_point[2];
    y2 = control_point[3];

    c0 = 3.0f * x1;
    c1 = 3.0f * (x2 - 2.0f * x1);
    c2 = 1.0f + 3.0f * (x1 - x2);

    lt = 0;
    rt = 1.0f;
    t = 0.5f;

    /* use binary search to approximate t for x(t) = x */
    for (i = 0; i < BEZIER_BINARY_SEARCH_LOOP_NUM; i++)
    {
        /* calculate x of B(t) */
        bx = t * (c2 * t * t + c1 * t + c0);

        /* approach bx to x */
        if (bx > x)
        {
            rt = t;
        }
        else
        {
            lt = t;
        }

        t = (lt + rt) / 2.0f;
    }

    /* calculate y of B(t) from the approximated t */
    c0 = 3.0f * y1;
    c1 = 3.0f * (y2 - 2.0f * y1);
    c2 = 1.0f + 3.0f * (y1 - y2);

    by = t * (c2 * t * t + c1 * t + c0);

    return by;
}


VfxFloat VcpActivityIndicator::interpolateFloat(VfxFloat from_value, VfxFloat to_value, VfxFloat t) 
{
    return (to_value - from_value) * t + from_value;
}


void VcpActivityIndicator::onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    if (source->getSize() == oldBounds.size)
    {
        return;
    }
    
    VfxS32 total_size = source->getSize().width;
    VfxId ballImage = VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_MEDIUM;
    if(total_size < BALL_SIZE_THRESH_1)
    {
        ballImage = VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_SMALL;
    }
    else if(total_size > BALL_SIZE_THRESH_2)
    {
        ballImage = VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_LARGE;
    }

    VfxPoint center = VfxPoint(source->getSize().width / 2, source->getSize().height / 2);
    VfxS32   radius = VFX_MIN(center.x, center.y);
    
    VfxS32 ball_w = ((VfxFloat)(VfxImageSrc(ballImage).getSize().width)) * BALL_SCALE_RATIO_MAX;
    VfxS32 ball_h = ((VfxFloat)(VfxImageSrc(ballImage).getSize().height)) * BALL_SCALE_RATIO_MAX;
    
    radius -= VFX_MAX(ball_w/2, ball_h/2);

    // put each ball on the circle euqally
    for (VfxS32 i = 0; i < BALL_NUM; i++)
    {
        m_ball[i]->setSize(ball_w, ball_h);

        m_ball[i]->setPos(
                    center.x + (VfxS32)(radius * (VfxFloat)vfxCos(VFX_DEG_TO_RAD(360 / BALL_NUM * i - 90))),
                    center.y + (VfxS32)(radius * (VfxFloat)vfxSin(VFX_DEG_TO_RAD(360 / BALL_NUM * i - 90))));  
        m_ball[i]->setOpacity(0.0f);
        m_ball[i]->setResId(ballImage);
    }    
} 
