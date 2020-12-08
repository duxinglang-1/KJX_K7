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
 *  vcp_scrollable.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Scrollable class
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
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
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include <math.h>

#ifdef __MTK_TARGET__
#ifdef __VENUS_SWLA_DBG_ON__
#define __MAUI_SOFTWARE_LA__
#else
//#define __MAUI_SOFTWARE_LA__
#endif
#endif



#include "trc/vadp_sys_trc.h"


extern "C"
{
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"


#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}


#include "vfx_uc_include.h"
#include "vcp_scrollable.h"




#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_auto_animate.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"
#include "vfx_object.h"
#include "vfx_system.h"
#include "vfx_control.h"
#include "vfx_sys_memory.h"
#include "vfx_animation.h"
#include "vrt_system.h"
#include "vfx_input_event.h"
#include "vfx_renderer.h"
#include "vfx_class_info.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_scrollable_def.h"
#include "vfx_image_src.h"
#include "vfx_pen.h"
#include "vfx_frame_aligner.h"
#include "Gui_Setting.h"


#ifdef __COSMOS_3D_V10__
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"
#endif
// pen down delay time in ms
#define VCP_SCROLLABLE_PEN_DOWN_DELAY   125

#define VCP_SCROLLABLE_MORE_ACCEL_RATE  0.75f

#define VCP_SCROLLABLE_FREE_RUN_MIN_INITIAL_SPEED 0.5f

#define VCP_SCROLLABLE_FPS (30)

#define VCP_SCROLLABLE_UPDATE_INTERVAL (1000.0f / VCP_SCROLLABLE_FPS)

#define ARRAY(_target,_index) ((VfxS32*)&_target)[_index]


/***************************************************************************** 
 * class VcpScrollableView
 *****************************************************************************/

// elastic margins
const VfxFloat VcpScrollableView::ELASTIC_LEFT_MARGIN = 0;
const VfxFloat VcpScrollableView::ELASTIC_RIGHT_MARGIN = 0;
const VfxFloat VcpScrollableView::ELASTIC_TOP_MARGIN = 0.0;
const VfxFloat VcpScrollableView::ELASTIC_BOTTOM_MARGIN = 0.0;
// margin force factor [0, 1] for dragging in elastic areas, the push back force is larger with a smaller value. 
const VfxFloat VcpScrollableView::MARGIN_FORCE_FACTOR = 0.0;

// smooth scrolling
const VfxFloat VcpScrollableView::MAX_BOUNCE_VELOCITY = 1000.0f;

#define VCP_SCROLLABLE_BASE_LCD_HEIGHT 800

#if defined(__COSMOS_MMI__)
    const VfxFloat VcpScrollableView::MAX_INITIAL_VELOCITY = 1600.0f * MAIN_LCD_DEVICE_HEIGHT / VCP_SCROLLABLE_BASE_LCD_HEIGHT;
    const VfxFloat VcpScrollableView::INITIAL_VELOCITY_FACTOR = 1000.0f;            

    #if defined(__TOUCH_PANEL_CAPACITY__)
        const VfxFloat VcpScrollableView::FRICTION_DECELERATION = 1200.0f * MAIN_LCD_DEVICE_HEIGHT / VCP_SCROLLABLE_BASE_LCD_HEIGHT;				
    #else
        const VfxFloat VcpScrollableView::FRICTION_DECELERATION = 600.0f * MAIN_LCD_DEVICE_HEIGHT / VCP_SCROLLABLE_BASE_LCD_HEIGHT;				
    #endif
#else
    #if defined(__MMI_VUI_LAUNCHER__)
        const VfxFloat VcpScrollableView::MAX_INITIAL_VELOCITY = 700.0f;
        const VfxFloat VcpScrollableView::FRICTION_DECELERATION = 200.0f; 
        const VfxFloat VcpScrollableView::INITIAL_VELOCITY_FACTOR = 468.0f;         
    #else
        const VfxFloat VcpScrollableView::MAX_INITIAL_VELOCITY = 700.0f;
        const VfxFloat VcpScrollableView::FRICTION_DECELERATION = 600.0f; 
        const VfxFloat VcpScrollableView::INITIAL_VELOCITY_FACTOR = 468.0f;        
    #endif
#endif
VFX_IMPLEMENT_CLASS("VcpScrollableView", VcpScrollableView, VfxControl);

VcpScrollableView::VcpScrollableView() :
    m_validContentRect(VFX_RECT_ZERO),
    m_warningContentRect(VFX_RECT_ZERO),
    m_isTracking(VFX_FALSE),
    m_isDragging(VFX_FALSE),
    m_isDecelerating(VFX_FALSE),
    m_isResizing(VFX_FALSE),
    m_contentOrigin(VFX_POINT_ZERO),
    m_unit(VfxSize(1,1)),
    m_isResumedParent(VFX_FALSE),
    m_limitDirection(VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_NONE),
    m_isLimited(VFX_FALSE),
    m_parentScrollableView(NULL), 
    m_contentSize(VFX_SIZE_ZERO),
    m_marginForceFactor(MARGIN_FORCE_FACTOR),
    m_freeRunSlowFactor(1.0f),
    m_boundsTlNeedMerge(VFX_FALSE),
    m_isPenDown(VFX_FALSE),        
    m_penDownOrigin(VFX_POINT_ZERO),
    m_isToSendWarning(VFX_FALSE),
    m_isToSendError(VFX_FALSE),
    m_isAbleSendWarning(VFX_TRUE),
    m_isAbleSendError(VFX_TRUE),    
    m_lastUpdateTime(0),
    m_signature(0),
    m_isCapturing(VFX_FALSE),
    m_sureDragging(VFX_FALSE),
    m_penDownTimer(NULL),
    m_penMoveTimer(NULL),
    m_isIntersectScreen(VFX_FALSE),
    m_intersectRect(VFX_RECT_ZERO) 
{
    m_freeRunPara[0] = m_freeRunPara[1] = m_freeRunPara[2] = m_freeRunPara[3] = 0;
    m_elasticMargin[0] = ELASTIC_LEFT_MARGIN;
    m_elasticMargin[1] = ELASTIC_TOP_MARGIN;
    m_elasticMargin[2] = ELASTIC_RIGHT_MARGIN;
    m_elasticMargin[3] = ELASTIC_BOTTOM_MARGIN;    
    m_isBounce[0] = m_isBounce[1] = VFX_FALSE;
    m_slowFactor[0] = m_slowFactor[1] = 1.0f;
    m_maxScrollDist[0] = m_maxScrollDist[1] = 0;
    
}


void VcpScrollableView::setBoundsInternal(const VfxRect &value, VfxBool isForced)
{
#ifdef __MAUI_SOFTWARE_LA__
       SLA_CustomLogging("SSB", SA_start);
#endif 
    VfxRect oldValue = m_bounds;

    if ((m_bounds != value) || isForced)
    {
        stopBoundsAnimation();
        
        if (getAutoAnimate() && !VfxAutoAnimate::getDisable() && !isInitializing())
        {
            // auto animation is enabled
            m_isTracking = VFX_FALSE;
            m_isDragging = VFX_FALSE;
            m_isDecelerating = VFX_TRUE;
            m_penMoveTimer->stop();

            // emit scroll start event
            m_signalScrollStarted.emit(VFX_TRUE);
            
            VfxMsec dur = VfxAutoAnimate::getDuration();            
            dur = dur == 0 ? VRT_TIMELINE_DEFAULT_DUR_TIME : dur;
            
            if(!m_boundsTlNeedMerge)
            {
                m_boundsTl->setFromValue(forceGetBounds());
            }            
            m_boundsTl->setToValue(value);            
            m_boundsTl->setDurationTime(dur);            
            m_boundsTl->m_signalStopped.connect(this, &VcpScrollableView::onScrollAnimStop);
            m_boundsTl->start();

            if(m_boundsTl->getFromValue().size != m_boundsTl->getToValue().size)
            {
                m_isResizing = VFX_TRUE;
            }            
            //m_boundsTlNeedMerge = !getHandle() ? VFX_TRUE : VFX_FALSE; //don't workaround merge because timline and VK fixed
            VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_SET_BOUNDS_AUTO_ANIM, this, value.origin.x, value.origin.y, value.size.width, value.size.height);
        }
        else
        {
            m_isDecelerating = VFX_FALSE;
            m_isResizing = VFX_FALSE;
            // direct set              
            vrt_rect_struct vrtValue = value;
            VfxAutoAnimate::setAnimatableProperty(
                this,
                VRT_FRAME_PROPERTY_ID_BOUNDS,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue));
            //must show next frame so won't merge commit
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            renderer->mustShowNextFrame();
            VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_SET_BOUNDS_DIRECT, this, value.origin.x, value.origin.y, value.size.width, value.size.height);
        }               
        
        updateBoundsValue(value);


        VfxFrameAligner::alignChildFrames(this);

    }
#ifdef __MAUI_SOFTWARE_LA__
       SLA_CustomLogging("SSB", SA_stop);
#endif     
}

VfxBool VcpScrollableView::updateBoundsValue(VfxRect rect)
{
    if(m_bounds != rect)
    {
        VfxRect old = m_bounds;
        m_bounds = rect;
        m_signalBoundsChanged.emit(this, old);        
        return VFX_TRUE;    
    }
    
    return VFX_FALSE;    
}

void VcpScrollableView::setBounds(const VfxRect &value)
{
    setBoundsInternal(value, VFX_FALSE);
}


void VcpScrollableView::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("SVI", SA_start);
#endif     
    VfxControl::onInit();

    // save this
    m_signature = (VfxU32)getObjHandle();

    VFX_OBJ_CREATE(m_freeRunTl, VfxRectTimeline, this);
    VFX_OBJ_CREATE(m_recoverTl, VfxRectTimeline, this);
    VFX_OBJ_CREATE(m_boundsTl, VfxRectTimeline, this);    
    VFX_OBJ_CREATE(m_penDownTimer, VfxTimer, this);                    
    VFX_OBJ_CREATE(m_penMoveTimer, VfxTimer, this);

    m_freeRunTl->setTarget(this);
    m_freeRunTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS);
    m_freeRunTl->setIsFromCurrent(VFX_TRUE);
    m_recoverTl->setTarget(this);
    m_recoverTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS);
    m_recoverTl->setIsFromCurrent(VFX_TRUE);
    m_recoverTl->setDurationTime(RECOVER_TIME_DURATION);
    m_recoverTl->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_boundsTl->setTarget(this);
    m_boundsTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS);
    m_penMoveTimer->setStartDelay(25);
    m_penMoveTimer->m_signalTick.connect(this, &VcpScrollableView::onPenMoveTimerTick);       
    m_penDownTimer->setStartDelay(VCP_SCROLLABLE_PEN_DOWN_DELAY);
    m_penDownTimer->m_signalTick.connect(this, &VcpScrollableView::onPenDownTimerTick);     

    // start bounds monitor timeline
    startMonitor();
#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("SVI", SA_stop);
#endif         
}


void VcpScrollableView::onDeinit()
{
#ifdef __MAUI_SOFTWARE_LA__
              SLA_CustomLogging("SVD", SA_start);
#endif
    // close will invoke stop, so we do no need to stop animation here
    VFX_OBJ_CLOSE(m_freeRunTl);
    VFX_OBJ_CLOSE(m_recoverTl);
    VFX_OBJ_CLOSE(m_boundsTl);
 

    VcpScrollable *scrollable = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpScrollable);
    if(scrollable)
    {
        scrollable->m_view = NULL;
    }

    
    VfxControl::onDeinit();
#ifdef __MAUI_SOFTWARE_LA__
              SLA_CustomLogging("SVD", SA_stop);
#endif
}


void VcpScrollableView::startMonitor()
{        
#ifdef __MAUI_SOFTWARE_LA__
              SLA_CustomLogging("SSM", SA_start);
#endif 
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    MonitorData userdata;
    userdata.screenBounds = topLevel->getBounds();
    userdata.view = this;
    userdata.signature = m_signature;
    userdata.validRect = m_validContentRect;
    userdata.warningRect = m_warningContentRect;
    userdata.contentSize = m_contentSize; 
    userdata.contentOrigin = m_contentOrigin;

    setPropertyMonitorCallback(boundsMonitorFuncCallback, &userdata, sizeof(MonitorData));

#ifdef __MAUI_SOFTWARE_LA__
          SLA_CustomLogging("SSM", SA_stop);
#endif     

}


void VcpScrollableView::setWarningContentRect(
    VfxRect &rect   // [IN] warning content rect
)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SWR", SA_label);
#endif       

    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_SET_WARNING_RECT, this, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

    m_isToSendWarning = VFX_TRUE;
    m_warningContentRect = rect;

    startMonitor();   

}


void VcpScrollableView::setValidContentRect(
    VfxRect &rect   // [IN] valid content rect
)
{      
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SVR", SA_label);
#endif   
VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_SET_VALID_RECT, this, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

    m_isToSendError = VFX_TRUE;
    m_validContentRect = rect;

    startMonitor();

}



VfxBool VcpScrollableView::limitBoundsOrigin(const VfxRect &bounds, VfxS32 *x, VfxS32 *y)
{
    VfxS32 b[2];
    VfxBool isOriginChanged = VFX_FALSE;

    b[0] = *x;
    b[1] = *y;

    for (VfxS32 i = 0; i < 2; ++i)
    {
        if (ARRAY(m_contentSize, i) < ARRAY(bounds.size, i)) // single page, return y to 0
        {   
            b[i] = ARRAY(m_contentOrigin, i);        
        }
        else // limited in avalible area
        {
            b[i] = VFX_MIN(VFX_MAX(ARRAY(m_contentOrigin, i), b[i]), ARRAY(m_contentSize, i) + ARRAY(m_contentOrigin, i) - ARRAY(bounds.size, i));
        }        
    }
    
    if (*x != b[0] || *y != b[1])
    {
        *x = b[0];
        *y = b[1];
        isOriginChanged = VFX_TRUE;
    }

    return isOriginChanged;
}


VfxS32 VcpScrollableView::limitElasticDragMovement(VfxS32 origin, VfxS32 pos, VfxS32 contentSize, VfxS32 boundsSize)
{        
    // out of margin push back force
    if ((pos < origin) || ((pos > origin) && (contentSize <= boundsSize)))
    {   // beginning margin area
        pos = origin + (VfxS32)((VfxFloat)(pos - origin) * m_marginForceFactor);
    }
    else if ((contentSize > boundsSize) && (pos > origin + contentSize - boundsSize))
    {   // ending margin area
        pos = origin + contentSize - boundsSize + (VfxS32)((VfxFloat)(pos - (origin + contentSize - boundsSize)) * m_marginForceFactor);
    }

    return pos;
}


VfxRect VcpScrollableView::getElasticRect()
{
    VfxS32 p[4] = {0};
    VfxRect bounds = getBounds();    

    for (VfxS32 i = 0; i < 2; ++i)
    {
        p[i] = ARRAY(m_contentOrigin, i);
        p[i + 2] = ARRAY(m_contentOrigin, i) + VFX_MAX(ARRAY(bounds.size, i), ARRAY(m_contentSize, i));
        
        if (m_isBounce[i])
        {
            p[i] += -(VfxS32)(m_elasticMargin[i] * (VfxFloat)ARRAY(bounds.size, i));
            p[i + 2] += (VfxS32)(m_elasticMargin[i + 2] * (VfxFloat)ARRAY(bounds.size, i));
        }        
    }
    
    return VfxRect(p[0], p[1], p[2] - p[0] + 1, p[3] - p[1] + 1);
}


void VcpScrollableView::rectToCoord(const VfxRect &rect, VfxS32 *x1, VfxS32 *y1, VfxS32 *x2, VfxS32 *y2)
{
    VFX_ASSERT(!rect.isEmpty());

    *x1 = rect.origin.x;
    *y1 = rect.origin.y;
    *x2 = *x1 + rect.size.width - 1;
    *y2 = *y1 + rect.size.height - 1;
}


vrt_bool VcpScrollableView::isContainRect(vrt_rect_struct *a, vrt_rect_struct *b)
{
    vrt_rect_struct intersect;
    intersect = vrt_rect_intersect(a, b);
    
    return vrt_rect_equal(&intersect, b);
}


void VcpScrollableView::emitContentWarning(void *arg)
{
    VcpScrollableView *view = (VcpScrollableView*)VfxObject::handleToObject((VfxObjHandle)arg);

    if (view == NULL)
    {
        return;
    }


#ifdef __MAUI_SOFTWARE_LA__
          SLA_CustomLogging("SEw", SA_label);
#endif            

    view->m_isAbleSendWarning = VFX_TRUE;
    
    // emit warning signal
    view->m_signalContentWarning.emit(view);

    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_CONTENT_WARNING, view, view->m_warningContentRect.origin.x, view->m_warningContentRect.origin.y, view->m_warningContentRect.size.width, view->m_warningContentRect.size.height);
}


void VcpScrollableView::emitContentError(void *arg)
{
    VcpScrollableView *view = (VcpScrollableView*)VfxObject::handleToObject((VfxObjHandle)arg);

    if (view == NULL)
    {
        return;
    }

    
#ifdef __MAUI_SOFTWARE_LA__
     SLA_CustomLogging("SEe", SA_label);
#endif            


    view->m_isAbleSendError = VFX_TRUE;
    
    // emit valid rect error signal
    view->m_signalContentError.emit(view);

    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_CONTENT_ERROR, view, view->m_validContentRect.origin.x, view->m_validContentRect.origin.y, view->m_validContentRect.size.width, view->m_validContentRect.size.height);
}
void VcpScrollableView::emitContentWarningError(void *arg)
{
    VcpScrollableView *view = (VcpScrollableView*)VfxObject::handleToObject((VfxObjHandle)arg);

    if (view == NULL)
    {
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__
          SLA_CustomLogging("SEb", SA_label);
#endif            

    view->m_isAbleSendWarning = VFX_TRUE;
    view->m_isAbleSendError = VFX_TRUE;

    // emit warning signal
    view->m_signalContentWarning.emit(view);
    // emit valid rect error signal
    view->m_signalContentError.emit(view);


    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_CONTENT_WARNING_ERROR, view, view->m_warningContentRect.origin.x, view->m_warningContentRect.origin.y, view->m_warningContentRect.size.width, view->m_warningContentRect.size.height, view->m_validContentRect.origin.x, view->m_validContentRect.origin.y, view->m_validContentRect.size.width, view->m_validContentRect.size.height);
}


vrt_frame_property_monitor_type_enum VcpScrollableView::boundsMonitorFuncCallback(
            vrt_frame_property_handle target_frame, void *user_data, vrt_u32 user_data_size)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SBM", SA_start);
#endif 
    vrt_rect_struct rect, validRect, warningRect, screenRect;    
    VfxRect *r;
    vrt_frame_property_monitor_type_enum ret = VRT_FPM_TYPE_NONE;
    
    MonitorData *userdata = (MonitorData*)user_data;    
    VcpScrollableView *view = userdata->view;
    screenRect = userdata->screenBounds;
    
    
    if (VfxObject::handleToObject((VfxObjHandle)userdata->signature) == NULL)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SBM", SA_stop);
        SLA_CustomLogging("SMN", SA_label);
#endif 
        return VRT_FPM_TYPE_NONE;
    }
    vrt_frame_visual_property_struct *fp = vrt_canvas_get_frame_visual_property(target_frame);    
    rect = fp->bounds;

    // get valid rect  
    r = &(userdata->validRect);
    validRect = vrt_rect_make(r->getX(), r->getY(), r->getWidth(), r->getHeight());

    // get warning rect
    r = &(userdata->warningRect);
    warningRect = vrt_rect_make(r->getX(), r->getY(), r->getWidth(), r->getHeight());
  
    if ((rect.size.height <=0 || rect.size.width <=0) || 
        (vrt_rect_is_empty(&warningRect) && vrt_rect_is_empty(&validRect)))
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SBM", SA_stop);
        SLA_CustomLogging("SMN", SA_label);
#endif         
        return VRT_FPM_TYPE_NONE;
    }

  
 
    if (view->m_isIntersectScreen)
    {  
        vrt_point_struct viewOrigin = g_vrt_point_zero;
    
        // Get the coordinate offest of coordinate convertion from view to screen
        vrt_canvas_convert_point_to_root_frame(target_frame, &viewOrigin); 

        screenRect.origin.x += -viewOrigin.x; //transfer to view coordinate
        screenRect.origin.y += -viewOrigin.y;
            
        VfxPoint top, bottom;
        top.x = VFX_MAX(rect.origin.x, screenRect.origin.x);
        top.y = VFX_MAX(rect.origin.y, screenRect.origin.y);
        bottom.x = VFX_MIN(rect.origin.x + rect.size.width, screenRect.origin.x + screenRect.size.width);
        bottom.y = VFX_MIN(rect.origin.y + rect.size.height, screenRect.origin.y + screenRect.size.height);

        rect.origin = top;
        rect.size = VfxSize(bottom.x - top.x, bottom.y - top.y);

        if (rect.size.height <= 0 || rect.size.width <= 0)
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("SBM", SA_stop);
            SLA_CustomLogging("SMN", SA_label);
#endif             
            return VRT_FPM_TYPE_NONE;
        }
        
    }
   
    
    // allow bounce
    for (VfxS32 i = 0; i < 2; ++i)
    {
        if (ARRAY(rect.origin, i) > ARRAY(userdata->contentSize, i) - ARRAY(rect.size, i) + ARRAY(userdata->contentOrigin, i))
        {
            ARRAY(rect.size, i) -= ARRAY(rect.origin, i) - (ARRAY(userdata->contentSize, i) - ARRAY(rect.size, i) + ARRAY(userdata->contentOrigin, i));
            ARRAY(rect.origin, i) = ARRAY(userdata->contentSize, i) - ARRAY(rect.size, i) + ARRAY(userdata->contentOrigin, i);
        }
        
        if (ARRAY(rect.origin, i) < ARRAY(userdata->contentOrigin, i))
        {
            ARRAY(rect.size, i) -= (ARRAY(userdata->contentOrigin, i) - ARRAY(rect.origin, i));
            ARRAY(rect.origin, i) = ARRAY(userdata->contentOrigin, i);
        }
    }
   

    if (rect.size.height <=0 || rect.size.width <=0 ) 
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SBM", SA_stop);
        SLA_CustomLogging("SMN", SA_label);
#endif         
        return VRT_FPM_TYPE_NONE;
    }
    if (view->m_intersectRect != rect)
    {
        view->m_intersectRect = rect;
        if(view->m_isDecelerating)
        {
            ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY; // Prevent that a large parent frame is cached
        }
        else
        {
            ret = VRT_FPM_TYPE_CONTENT_DIRTY; 
        }
    }
 
    
    VfxMsec curTime = (VfxMsec)vrt_get_current_frame_time();
    VfxBool emitable = VRT_TRUE; // dont do FPS control

    if (view->m_lastUpdateTime == 0 ||
        (curTime - view->m_lastUpdateTime) >= VCP_SCROLLABLE_UPDATE_INTERVAL)
    {
        view->m_lastUpdateTime = curTime; // FPS control
        emitable = VRT_TRUE;      
    }     
    VfxBool needSendWarning = VFX_FALSE;
    VfxBool needSendError = VFX_FALSE;    
     
    // check if the view port is outside the warning content rect
    if (!vrt_rect_is_empty(&warningRect) && !isContainRect(&warningRect, &rect))
    {
        // emit warning signal
        if (view->m_isToSendWarning && view->m_isAbleSendWarning && emitable)
        {             
            needSendWarning = VFX_TRUE;
        }
    }

    if (!vrt_rect_is_empty(&validRect) && !isContainRect(&validRect, &rect))
    {
        // emit stop signal
        if (view->m_isToSendError && view->m_isAbleSendError && emitable)
        {
            needSendError = VFX_TRUE;            
        }            
        ret = VRT_FPM_TYPE_FREEZE;
    }

    if(needSendWarning && needSendError)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SEB", SA_label);
#endif                    
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_MONITOR_WARNING_ERROR, view, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, warningRect.origin.x, warningRect.origin.y, warningRect.size.width, warningRect.size.height, validRect.origin.x, validRect.origin.y, validRect.size.width, validRect.size.height);
        vrt_invoke_mmi_rpc(emitContentWarningError, (void*)userdata->signature);
        view->m_isToSendError = VRT_FALSE;
        view->m_isToSendWarning = VRT_FALSE;   
        view->m_isAbleSendError = VRT_FALSE;
        view->m_isAbleSendWarning = VRT_FALSE;   
    }
    else if(needSendWarning)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SEW", SA_label);
#endif            

        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_MONITOR_WARNING, view, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, warningRect.origin.x, warningRect.origin.y, warningRect.size.width, warningRect.size.height);
        vrt_invoke_mmi_rpc(emitContentWarning, (void*)userdata->signature);
        view->m_isToSendWarning = VRT_FALSE;   
        view->m_isAbleSendWarning = VRT_FALSE;   
    }
    else if(needSendError)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SEE", SA_label);
#endif            
        
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_MONITOR_ERROR, view, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, validRect.origin.x, validRect.origin.y, validRect.size.width, validRect.size.height);
        vrt_invoke_mmi_rpc(emitContentError, (void*)userdata->signature);
        view->m_isToSendError = VRT_FALSE;
        view->m_isAbleSendError = VRT_FALSE;   
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SBM", SA_stop);
    
    switch (ret)
    {
        case VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY:
            SLA_CustomLogging("SMD", SA_label);
        break;
        case VRT_FPM_TYPE_CONTENT_DIRTY:
            SLA_CustomLogging("SMd", SA_label);
        break;
        case VRT_FPM_TYPE_FREEZE:
            SLA_CustomLogging("SMF", SA_label);
        break;
        case VRT_FPM_TYPE_NONE:
            SLA_CustomLogging("SMN", SA_label);
        break;
        default:
        break;        
    }    
#endif 

    return ret;
}


static VfxFloat decelerationTimingFuncCallback(VfxFloat t, void *data, VfxU32 dataSize)
{
    vrt_float s;
    vrt_float *p = (vrt_float*)data;
    vrt_float vs;

    VFX_UNUSED(dataSize);

    // to prevent error when the timeline is ended, t = 1.0f must be mapped to 1.0f
    if (t == 1.0f)
    {
        return 1.0f;
    }

    t = t * p[3];
    
    vs = t * (p[0] + 0.5f * p[1] * t);

    s = p[2] == 0 ? 0 : vs / p[2];

    VFX_LOG(VFX_INFO3, VCP_SCROLLABLE_INFO_FRPARA_VIEW, (vrt_s32)(1000 * t / p[3]), (vrt_s32)(1000 * s), (vrt_s32)p[0], (vrt_s32)p[1], (vrt_s32)p[2], (vrt_s32)( 1000 * p[3]));        
    return s;
}



VfxBool VcpScrollableView::resumeParentScrollable(VfxPenEvent& event)
{
    VfxS32 p[4];
    rectToCoord(getElasticRect(), &p[0], &p[1], &p[2], &p[3]);            

    VfxRect bounds = forceGetBounds();         

    VfxBool intendScroll[2] = {0}, isParentScroll[2] = {0}, isScroll[2] = {0};
    
    for (VfxS32 i = 0; i < 2; ++i)
    {        
        VfxFloat penMoveOffset = (VfxFloat)(((VfxS32*)&event.pos)[i] - ((VfxS32*)&event.prevPos)[i]);
        intendScroll[i] = (VfxBool)(VFX_ABS(penMoveOffset) > DRAG_START_MOVE_THRESHOLD);
        isScroll[i] = (VfxBool)(((VfxS32*)&m_contentSize)[i] > ((VfxS32*)&getSize())[i]);      
        if(m_parentScrollableView)
        {            
            isParentScroll[i] = (VfxBool)(((VfxS32*)&m_parentScrollableView->getContentSize())[i] > ((VfxS32*)&m_parentScrollableView->getBounds().size)[i]);
        }        
    }

    for (VfxS32 i = 0; i < 2; ++i)
    {                            
        if (intendScroll[i])
        {              
            VfxFloat penMoveOffset = (VfxFloat)(((VfxS32*)&event.pos)[i] - ((VfxS32*)&event.prevPos)[i]);            
            VfxFloat movement = (VfxFloat)((VfxS32*)&bounds.origin)[i] - (VfxFloat)(m_slowFactor[i] * (VfxFloat)penMoveOffset);
            
            if(movement< p[i])
            {           
                if((!isScroll[i]) || (m_isLimited && m_limitDirection == i))
                {
                    if(m_parentScrollableView && isParentScroll[i] && (!isScroll[1 - i] || !intendScroll[1 - i]))
                    {
                        m_parentScrollableView->m_isResumedParent = VFX_TRUE;
                        m_parentScrollableView->capture(VFX_PEN_ABORT_REASON_DEFAULT);    
                        return VFX_TRUE;
                    }
                    
                }
                else
                {
                    m_limitDirection = i;
                } 
            }
            else if(movement + ((VfxS32*)&getSize())[i] > p[i + 2])
            {
                if((!isScroll[i]) || (m_isLimited && m_limitDirection == i + 2))
                {
                    if(m_parentScrollableView && isParentScroll[i] && (!isScroll[1 - i] || !intendScroll[1 - i]))
                    {
                        m_parentScrollableView->m_isResumedParent = VFX_TRUE;
                        m_parentScrollableView->capture(VFX_PEN_ABORT_REASON_DEFAULT);    
                        return VFX_TRUE;
                    }                    
                }
                else
                {
                    m_limitDirection = i + 2;
                }   
            }
            else
            {
                m_isLimited = VFX_FALSE;
                m_limitDirection = VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_NONE;
            }
        }
    }
     

    return  VFX_FALSE;
}


void VcpScrollableView::getDecelerateStopData(VfxFloat v0, VfxFloat a, VfxFloat *stopT, VfxFloat *dist)
{
    VfxFloat t;

    // get the time when v = 0
    t = -v0 / a;    
    *stopT = t;
    
    // get the moving distance when v = 0
    *dist = t * (v0 + 0.5f * a * t);
}


VfxFloat VcpScrollableView::getDecelerateTimeByDist(VfxFloat v0, VfxFloat a, VfxS32 moveDist)
{
    VfxFloat t, temp;

    temp = (VfxFloat)(v0 * v0 + (VfxFloat)(2 * moveDist) * a);

    // prevent a minus number from root-squared
    if (temp < 0)
    {
        temp = 0;

        // return a minus t to let caller know this is unsolvable
        return -1.0f;
    }
    
    temp = (VfxFloat)vfxSqrt(temp);

    if (v0 < 0)
    {
        t = (-v0 - temp) / a;
    }
    else
    {
        t = (-v0 + temp) / a;
    }

    return t;
}


void VcpScrollableView::getDecelerateBounceStopData(VfxFloat *v, VfxFloat *a, VfxS32 origin, VfxS32 direction, VfxFloat *stopT, VfxFloat *dist)
{
    VfxPoint contentOffset;
    VfxRect elasticRect = getElasticRect();
        

    VfxS32 distToBoundary = 0, freeRunEnd = origin, targetOffset, maxBounceDist = 0, maxOriginMovableDist = 1;
    VfxS32 contentOrigin, contentSize, bsize, elasticSize;    
    
      
    // calculate the time and dist when v = 0
    getDecelerateStopData(*v, *a, stopT, dist);    
    
    freeRunEnd = (VfxS32)(*dist) + origin;

    // override freerun stop y
    contentOffset = VfxPoint(freeRunEnd, freeRunEnd);
    onFreeRunSetTargetContentOffset(contentOffset);

    contentOrigin = ARRAY(m_contentOrigin, direction);
    contentSize = ARRAY(m_contentSize, direction);
    bsize = ARRAY(getSize(), direction);
    targetOffset = ARRAY(contentOffset, direction);
    elasticSize = ARRAY(elasticRect.size, direction);
   
    if (m_maxScrollDist[direction] != 0 && VFX_ABS(targetOffset - ARRAY(m_penDownOrigin, direction)) > m_maxScrollDist[direction])
    {
        if (targetOffset > ARRAY(m_penDownOrigin, direction))
        {
            targetOffset = ARRAY(m_penDownOrigin, direction) + m_maxScrollDist[direction];
        }
        else
        {
            targetOffset = ARRAY(m_penDownOrigin, direction) - m_maxScrollDist[direction];            
        }       
    }

    VfxS32 normalizedDist = targetOffset - contentOrigin;
    VfxS32 reminder = normalizedDist % VFX_MAX(ARRAY(m_unit, direction), 1);

    if (targetOffset > origin && reminder != 0)
    {
        normalizedDist -= reminder;                
    }
    else if (targetOffset < origin && reminder != 0)
    {
        normalizedDist += (ARRAY(m_unit, direction) - reminder);              
    }  

    VfxS32 normalizedOffset = contentOrigin + normalizedDist;

    if (targetOffset < origin && normalizedOffset > origin)
    {
        normalizedOffset -= VFX_MAX(ARRAY(m_unit, direction), 1);
    }
    else if (targetOffset > origin && normalizedOffset < origin)
    {
        normalizedOffset += VFX_MAX(ARRAY(m_unit, direction), 1);        
    }

    targetOffset = normalizedOffset;

    
  
    if(contentSize > bsize)
    {
        maxOriginMovableDist = contentSize - bsize;
    }


    // must recalculate time duration if the target offset is changed
    if (freeRunEnd != targetOffset)
    {
        VfxFloat old_t;

        old_t = *stopT;
        freeRunEnd = targetOffset;
        VfxS32 d = freeRunEnd - origin;
        
        *stopT = (VfxFloat) getDecelerateTimeByDist(*v, *a, d);
        if (*stopT < 0)
        {
            // unsolvable t, recalculate a based on v and old t
            *stopT = old_t;
            if (reminder != 0)
            {
                *v = (VfxFloat)(d - 0.5 * (*a) * (*stopT) * (*stopT)) / (*stopT);
            }
            else
            {
                *a = 2.0f * (d - (*v) * (*stopT)) / ((*stopT) * (*stopT));
            }
            
        }
    }
      
    
    // update yS based on the new offset
    *dist = (VfxFloat)(freeRunEnd - origin);

    // if the distance@v=0 exceeds the normal bound, have to bounce back (recover)
    maxBounceDist = (elasticSize - contentSize) / 2;
    if (freeRunEnd < contentOrigin)
    {        
        distToBoundary = -(origin - contentOrigin) ; // bounce from left     
    }
    else if (freeRunEnd > maxOriginMovableDist + contentOrigin)
    {                
        distToBoundary = maxOriginMovableDist + contentOrigin - origin; // bounce from right
    }        



    // recalculate the final target time and position if bounce is necessary
    //if (distToBoundary)
    if (freeRunEnd < contentOrigin || freeRunEnd > maxOriginMovableDist + contentOrigin)
    {          
         VfxFloat s;
         VfxFloat bounceV;
         VfxFloat t;

         t = getDecelerateTimeByDist(*v, *a, distToBoundary);
         if (t >= 0)
         {
             // resolve velocity when meeting the elastic boundary
             bounceV = *v + (*a) * t;
             bounceV = VFX_ABS(bounceV);
             if (bounceV > MAX_BOUNCE_VELOCITY)
             {
                 bounceV = MAX_BOUNCE_VELOCITY;
             }

             // the distance going into the elastic area is propotional to the velocity
             s = maxBounceDist * bounceV / MAX_BOUNCE_VELOCITY;
             if (v < 0)
             {
                 s = -s;
             }

             // get the stop time at the stop distance (moveDist + s)
             if(s != 0)
             {
                 t = getDecelerateTimeByDist(*v, *a, distToBoundary + (VfxS32)s);
             }            
         }

         // VFX_ASSERT(t >= 0);
         if (t > 0)
         {
             *stopT = t;
             *dist =  t * (*v + 0.5f * (*a) * t);
         }     
         else
         {
             *stopT = 0;
             *dist = 0;
         }
          
    }
}

VfxBool VcpScrollableView::stopBoundsAnimation()
{
    // stop all timelines about the bounds
    if (m_boundsTl->getIsEnabled() || m_recoverTl->getIsEnabled() || m_freeRunTl->getIsEnabled())
    {   
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_STOP_BOUNDS_ANIMATION, this, m_boundsTl->getIsEnabled(), m_recoverTl->getIsEnabled(), m_freeRunTl->getIsEnabled());
        
        // to make sure the previous animation stop signal emit before the later start signal
        // because stop callback is post emit
        m_boundsTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);
        m_recoverTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);
        m_freeRunTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimRecover);        
        m_freeRunTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);

        m_freeRunTl->stop();
        m_recoverTl->stop();
        m_boundsTl->stop();

        m_signalScrollStopped.emit(NULL, VFX_TRUE);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VcpScrollableView::onPenInput(VfxPenEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
     SLA_CustomLogging("SPI", SA_start);
#endif

    if (m_isResizing)
    {
        return VFX_TRUE;
    }
    
    VfxRect bounds = forceGetBounds();
    VfxFloat b[2];   
    b[0] = (VfxFloat) bounds.origin.x;
    b[1] = (VfxFloat) bounds.origin.y;


    VfxBool isScroll[2];    
    isScroll[0] = (VfxBool)(m_contentSize.width > bounds.size.width);
    isScroll[1] = (VfxBool)(m_contentSize.height > bounds.size.height);
    

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_PEN_DOWN, this, event.pos.x, event.pos.y, b[0], b[1]);   


        m_isPenDown = VFX_TRUE;

        if (m_isDecelerating == VFX_FALSE)
        {
            onPenDown();
        }
         
    }
    else if (m_isPenDown && (event.type == VFX_PEN_EVENT_TYPE_MOVE))
    {
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_PEN_MOVE, this, event.pos.x, event.pos.y, b[0], b[1]);       
      
        
        if(resumeParentScrollable(event))
        {
            return VFX_TRUE; // pen captured by parent
        }


        if (m_penMoveTimer->getIsEnabled())
        {
            m_penMoveTimer->stop();

            if (!m_isTracking)
            {
                m_penMoveTimer->start(); //if not tracking, start timer again to check pen stopped or not
            }                   
        }
        

     
        if (!m_isDecelerating)
        {                  
            // update state
            m_isTracking = VFX_TRUE;
            m_isDragging = VFX_TRUE;
            m_isDecelerating = VFX_FALSE;    
            m_isResizing = VFX_FALSE;

                   
            //single page or not intend to scroll
            if ((!(m_isBounce[0] || isScroll[0])) && (!(m_isBounce[1] || isScroll[1])))
            {        
                VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_STATE, this, m_isTracking, m_isDragging, m_isDecelerating);
                return VFX_TRUE;
            }
        

            // disable auto animation when moving to reduce response time
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE); 

            VfxRect elastic = getElasticRect();
            VfxS32 elasticRect[4];
            VfxPoint p = bounds.origin;    
            rectToCoord(elastic, &elasticRect[0], &elasticRect[1], &elasticRect[2], &elasticRect[3]);	                 

            for (VfxS32 i = 0; i < 2; ++i)
            {                               
                VfxFloat penMoveOffset = m_slowFactor[i] * (ARRAY(event.pos, i) - ARRAY(event.prevPos, i));
               
                if (isScroll[i] || m_isBounce[i])
                {                  
                    // restore drag movement in the elastic margin
                    if (b[i] < ARRAY(m_contentOrigin, i) || ((b[i] > ARRAY(m_contentOrigin, i)) && (ARRAY(m_contentSize, i) <= ARRAY(bounds.size,i))))
                    {
                        b[i] = ARRAY(m_contentOrigin, i) - (ARRAY(m_contentOrigin, i) - b[i]) / m_marginForceFactor;
                    }
                    else if (ARRAY(m_contentSize, i) > ARRAY(bounds.size, i) && b[i] > ARRAY(m_contentOrigin, i) + ARRAY(m_contentSize, i) - ARRAY(bounds.size, i))
                    {
                        b[i] = ARRAY(m_contentOrigin, i) + ARRAY(m_contentSize, i) - ARRAY(bounds.size, i) + (b[i] - ARRAY(m_contentOrigin, i) - ARRAY(m_contentSize, i) + ARRAY(bounds.size, i)) / m_marginForceFactor;
                    }              
                    b[i] -= penMoveOffset;
                    b[i] = (VfxFloat)limitElasticDragMovement(((VfxS32*)&m_contentOrigin)[i], (VfxS32)b[i], ARRAY(m_contentSize, i), ARRAY(bounds.size, i));
                    b[i] = VFX_MIN(elasticRect[i + 2] - ARRAY(bounds.size, i), VFX_MAX(b[i], elasticRect[i])); 

                    //for boundarylight
                    ARRAY(p, i) = (VfxS32)(b[i] - 0.7 * (ARRAY(event.pos, i) - ARRAY(event.downPos, i))); 
                }               
            } 
               
            // emit scrolling
            m_signalScrolling.emit(p, elastic);

            // change the bounds
            setBounds(VfxRect(VfxPoint((VfxS32)b[0], (VfxS32)b[1]), bounds.size));

            VfxAutoAnimate::commit();

            // start bounds monitor timeline
        }

        
    }
    else if (m_isPenDown && (event.type == VFX_PEN_EVENT_TYPE_UP))
    {
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_PEN_UP, this, event.pos.x, event.pos.y, b[0], b[1]);

        if(m_limitDirection != VCP_SCROLLABLE_VIEW_LIMIT_DIRECTION_NONE)
        {
            m_isLimited = VFX_TRUE;
        }

        // update state
        m_isPenDown = VFX_FALSE;      
        m_isTracking = VFX_FALSE;
        m_isDragging = VFX_FALSE;
        m_isDecelerating = VFX_FALSE;
        m_isResizing = VFX_FALSE;


        VfxRect originRect;

        originRect.origin = m_contentOrigin;
        originRect.size.width = VFX_MAX(m_contentSize.width - bounds.size.width, 1);
        originRect.size.height = VFX_MAX(m_contentSize.height - bounds.size.height, 1);        

        VfxBool isRecover = VFX_FALSE, isFreeRun = VFX_FALSE;

        VfxFloat v[2] = {0}, a[2] = {0}, m[2] = {0};                        
        // only free run when the current bounds origin is valid in the content
        if ((isScroll[0] || isScroll[1]) &&  originRect.contains(bounds.origin))
        {
            VfxMsec dt = event.timeStamp - event.downTimeStamp;
            VfxFloat d[2];            
          
            //drag then swipe       
            if(dt > 200) 
            {   
                m_freeRunPara[0] = m_freeRunPara[1] = m_freeRunPara[2] = m_freeRunPara[3] = 0;
                dt = VFX_MAX(event.timeStamp - event.prevTimeStamp, 10);	
                for (VfxS32 i = 0; i < 2; ++i)
                {

                    d[i] = (VfxFloat)(ARRAY(event.predictPos, i) - ARRAY(event.prevPos, i));
                    if (VFX_ABS(d[i]) < DRAG_START_MOVE_THRESHOLD * 3 || VFX_ABS(d[i]) / dt < VCP_SCROLLABLE_FREE_RUN_MIN_INITIAL_SPEED)
                    {
                        d[i] = 0;
                    }
                    d[i] *= 1000;

                }
            }
            else
            {
                for (VfxS32 i = 0; i < 2; ++i)
                {
                    d[i] = (VfxFloat)(ARRAY(event.predictPos, i) - ARRAY(event.downPos, i));
                    if (VFX_ABS(d[i]) < DRAG_START_MOVE_THRESHOLD)
                    {
                        d[i] = 0;
                    }                    
                }                    
            }

            
      
            for (VfxS32 i = 0; i < 2; ++i)
            {
                if (isScroll[i] && VFX_ABS(d[i]) > 0)
                {         
                    VfxFloat S = 0, T = 0;
                    v[i] = - d[i] * m_freeRunSlowFactor * INITIAL_VELOCITY_FACTOR / (VfxFloat)dt;   
                    v[i] = VFX_MAX(VFX_MIN(MAX_INITIAL_VELOCITY, v[i]), -MAX_INITIAL_VELOCITY);                                
                    if (v[i] * m_freeRunPara[i] > 0) //the same direction
                    {
                        v[i] += m_freeRunPara[i] * VCP_SCROLLABLE_MORE_ACCEL_RATE;
                    }
                    v[i] = VFX_MAX(VFX_MIN(MAX_INITIAL_VELOCITY * 2 , v[i]), -MAX_INITIAL_VELOCITY * 2);

                    // the friction force direction is opposed to the velocity.
                    a[i] = v[i] > 0 ? -FRICTION_DECELERATION : FRICTION_DECELERATION;
                    getDecelerateBounceStopData(&v[i], &a[i], (VfxS32)b[i], i, &T, &S);                     
                    if (T > 0)
                    {
                        v[i] = (VfxFloat)((S - 0.5 * a[i] * T * T) / T);
                        m[i] = S;
                    }
                    else
                    {
                        a[i] = v[i] = m[i] = 0;
                    }
                 }
            }

            if ((a[0] == 0 && a[1] == 0) &&
                ((VfxS32)(b[0] - m_contentOrigin.x) % VFX_MAX(ARRAY(m_unit, 0), 1) != 0 ||
                (VfxS32)(b[1] - m_contentOrigin.y) % VFX_MAX(ARRAY(m_unit, 1), 1) != 0))
            {
               
                for (VfxS32 i = 0; i < 2; ++i)
                {
                   VfxS32 r = (VfxS32)(b[i] - ARRAY(m_contentOrigin, i)) % VFX_MAX(ARRAY(m_unit, i), 1);
                   VfxFloat q = (b[i] - ARRAY(m_contentOrigin, i) - r) / VFX_MAX(ARRAY(m_unit, i), 1);
                   if (r > 0.5 * VFX_MAX(ARRAY(m_unit, 0), 1))
                   {
                       q++;
                   }   
                   VfxFloat S = 0, T = 0.125;
                   S = q * VFX_MAX(ARRAY(m_unit, 0), 1) - b[i];       
                   if (S != 0)
                   {
                       a[i] = S > 0 ? -FRICTION_DECELERATION : FRICTION_DECELERATION;
                       v[i] = (VfxFloat)((S - 0.5 * a[i] * T * T) / T);
                       m[i] = S;
                   }
                   else
                   {
                       a[i] = v[i] = m[i] = 0;
                   }               
                }                       
            }                  

            m_freeRunPara[0] = m_freeRunPara[1] = 0;        
            
            if (a[0] !=0 || a[1] !=0)
            {
                VfxFloat p[4] = {0};

                for (VfxS32 i = 0; i < 2; ++i)
                {
                    b[i] += m[i];
                    p[0] += v[i] * v[i]; 
                    p[1] += a[i] * a[i]; 
                    p[2] += m[i] * m[i]; 

                }       
                p[0] = vfxSqrt(p[0]); 
                p[1] = -vfxSqrt(p[1]);
                p[2] = vfxSqrt(p[2]); 
                p[3] = getDecelerateTimeByDist(p[0], p[1], (VfxS32)p[2]);
               

                if(p[3] > 0)
                {
                    isFreeRun = VFX_TRUE;   
                    m_freeRunPara[0] = v[0];
                    m_freeRunPara[1] = v[1];
                    // set custom timing
                    m_freeRunTl->setCustomTimingFunc(decelerationTimingFuncCallback, p, sizeof(p));
                    m_freeRunTl->setToValue(VfxRect(VfxPoint((VfxS32)b[0], (VfxS32)b[1]), bounds.size));
                    m_freeRunTl->setDurationTime((VfxMsec)(p[3] * 1000.0f));   
                }

            }        
        }
             

        
        VfxPoint newOrigin = VfxPoint((VfxS32)b[0], (VfxS32)b[1]);

        // if the bounds origin exceed normal bounds, must set it back to the normal position
        isRecover = limitBoundsOrigin(bounds, &(newOrigin.x), &(newOrigin.y));      
        
        if (isRecover || isFreeRun)
        {
            // decelerating
            m_isDecelerating = VFX_TRUE;
            
            //stop freeRunTl first, don't trigger its stop slots
            m_freeRunTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);
            m_freeRunTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimRecover);  
            m_freeRunTl->stop(); 
            m_recoverTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);
            m_recoverTl->stop();            
            m_penMoveTimer->stop();               
            
            if (isFreeRun)
            {          
                if(isRecover)
                {
                    // free run and recover, run recover when free run animation is finished.
                    m_freeRunTl->m_signalStopped.connect(this, &VcpScrollableView::onScrollAnimRecover);               
                }
                else
                {
                    m_freeRunTl->m_signalStopped.connect(this, &VcpScrollableView::onScrollAnimStop);                    
                }
                m_freeRunTl->start();
                
                newOrigin = VfxPoint((VfxS32)b[0], (VfxS32)b[1]);
            }
            else
            {          
                // recover only, no free run
                m_recoverTl->setToValue(VfxRect(newOrigin, bounds.size));                
                m_recoverTl->m_signalStopped.connect(this, &VcpScrollableView::onScrollAnimStop);                
                m_recoverTl->start();
            }

            // emit scrolling
            m_signalScrolling.emit(bounds.origin, getElasticRect());

            // update target view bounds
            updateBoundsValue(VfxRect(newOrigin, bounds.size));          

            VcpScrollable *scrollable = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpScrollable);
            if (scrollable)
            {
                scrollable->emitStartFreerun(this);
            }
        }
        else
        {        
            if (m_penMoveTimer->getIsEnabled())
            {
                m_penMoveTimer->stop();

                if (!m_recoverTl->getIsEnabled())
                {                    
                    onPenDown();  
                    m_isTracking = VFX_FALSE; // pen released
                }
            }
            // move and pen up
            if (!m_recoverTl->getIsEnabled())
            {
                m_signalScrollStopped.emit(NULL, VFX_TRUE);
            }
             
        }
 
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_PEN_UP_TIMELINE, this, isRecover, isFreeRun, m_freeRunTl->getDuration());        

    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_PEN_ABORT, this);
        VfxPoint newOrigin = VfxPoint((VfxS32)b[0], (VfxS32)b[1]);        
        limitBoundsOrigin(bounds, &(newOrigin.x), &(newOrigin.y));		
        VfxRect rect = VfxRect(newOrigin, bounds.size);		

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);     
        if(m_bounds != rect && (m_boundsTl->getIsEnabled() || m_recoverTl->getIsEnabled() || m_freeRunTl->getIsEnabled()))
        {
            vrt_rect_struct vrtValue = rect;
            VfxAutoAnimate::setAnimatableProperty(
                this,
                VRT_FRAME_PROPERTY_ID_BOUNDS,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue));   
	        updateBoundsValue(rect);   
        }

        VfxAutoAnimate::commit(); //put here to keep auto animation of scrollbar

        if(!stopBoundsAnimation())
        {
            m_signalScrollStopped.emit(NULL, VFX_TRUE);
        }

        
    }

    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_INFO_STATE, this, m_isTracking, m_isDragging, m_isDecelerating);


#ifdef __MAUI_SOFTWARE_LA__
      SLA_CustomLogging("SPI", SA_stop);
#endif
    
    return VFX_TRUE;
}


VfxBool VcpScrollableView::onPreviewPenInput(VfxPenEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
             SLA_CustomLogging("SPP", SA_start);
#endif
    
    if(m_isResizing)
    {
        return VFX_FALSE;
    }
    
    VfxRect bounds = getBounds();
    VfxBool isHScroll, isVScroll;
   

    
    isHScroll = (VfxBool)(m_contentSize.width > bounds.size.width);
    isVScroll = (VfxBool)(m_contentSize.height > bounds.size.height);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_marginForceFactor = MARGIN_FORCE_FACTOR;

        m_sureDragging = VFX_TRUE;
        if(m_isResumedParent)
        {
            VcpScrollableView::onPenInput(event);
            m_isResumedParent = VFX_FALSE;
            return VFX_TRUE;
        }
        else if(m_isDecelerating == VFX_TRUE) // when decelerating, capture and don't let child get pen
        {
            if(m_recoverTl->getIsEnabled())
            {
                m_recoverTl->m_signalStopped.disconnect(this, &VcpScrollableView::onScrollAnimStop);
                m_recoverTl->stop();
                //m_signalScrollStopped.emit(NULL, VFX_TRUE);
                m_isDecelerating = VFX_FALSE;
                VcpScrollableView::onPenInput(event);
            }
            else
            {
                if(!m_boundsTl->getIsEnabled())
                {
                    m_penMoveTimer->start();                               
                }
                VcpScrollableView::onPenInput(event);                       
            }            

            m_marginForceFactor = 1.0; // for better UE, don't change pos during bounce back
   
            return VFX_TRUE;
        }
        else if (!m_isCapturing)
        {               
            // delay event when first pen down
            VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
            if (penSrv->delayEvent(this, event))
            {
                // do not call child class onPenInput
                VcpScrollableView::onPenInput(event);
                m_penDownTimer->start();
                m_sureDragging = VFX_FALSE;
            }            
        }

        
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (!m_sureDragging)
        {
            VfxS32 penMoveOffsetX, penMoveOffsetY;            
            penMoveOffsetX = event.pos.x - event.downPos.x;
            penMoveOffsetY = event.pos.y - event.downPos.y;
            
            if (isHScroll || m_isBounce[0] || isVScroll || m_isBounce[1])
            {                                                
                if (m_penDownTimer->getIsEnabled())
                {   
                    m_sureDragging = VFX_TRUE;                    
                    m_penDownTimer->stop(); // start to drag before the timer expires, start to drag                    
                    return VFX_FALSE;
                }
                else if (((isHScroll || m_isBounce[0]) && (VFX_ABS(penMoveOffsetX) >= DRAG_START_MOVE_THRESHOLD)) ||
                         ((isVScroll || m_isBounce[1]) && (VFX_ABS(penMoveOffsetY) >= DRAG_START_MOVE_THRESHOLD)))
                {
                    m_sureDragging = VFX_TRUE;
                    // timer expired, capture pen
                    m_isCapturing = VFX_TRUE;
                    capture(VFX_PEN_ABORT_REASON_CAPTURE_SWIPE);
                    m_isCapturing = VFX_FALSE;
                    return VFX_TRUE;                            
                }
            }
            
            //ask parent process pen move or not when we don't want capture
            if(resumeParentScrollable(event))
            {
                return VFX_TRUE;
            }

        }        
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // kal_printf("PREVIEW UP %d %d\n", pos.x, pos.y);
        m_sureDragging = VFX_FALSE;

        if (m_isDecelerating == VFX_FALSE && m_isDragging == VFX_FALSE)
        {
            if (m_penDownTimer->getIsEnabled())
            {   // pen click
                m_penDownTimer->stop();
                
                VfxS32 penMoveOffsetX, penMoveOffsetY;

                penMoveOffsetX = event.predictPos.x  - event.downPos.x;
                penMoveOffsetY = event.predictPos.y  - event.downPos.y;

                if (((!isHScroll && !m_isBounce[0]) || (VFX_ABS(penMoveOffsetX) < DRAG_START_MOVE_THRESHOLD)) &&
                    ((!isVScroll && !m_isBounce[1]) || (VFX_ABS(penMoveOffsetY) < DRAG_START_MOVE_THRESHOLD)))
                {
                    // the pen up may not go to VcpScrollable if the child control gets the pen input
                    if (m_isPenDown && !stopBoundsAnimation())
                    {
                        m_signalScrollStopped.emit(NULL, VFX_TRUE);
                    }

                    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
                    penSrv->resumeDelayedEvent();

                    return VFX_TRUE;
                }
            }
        }
    
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_penDownTimer->stop();
    }        

#ifdef __MAUI_SOFTWARE_LA__
       SLA_CustomLogging("SPP", SA_stop);
#endif
    return VfxControl::onPreviewPenInput(event);
}


void VcpScrollableView::onScrollAnimRecover(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VfxRect bounds = getBounds();
    VfxS32 bx, by, bw, bh;

    VFX_UNUSED(timeline);

    if (isCompleted)
    {
        bx = bounds.origin.x;
        by = bounds.origin.y;
        bw = bounds.size.width;
        bh = bounds.size.height;

        limitBoundsOrigin(bounds, &bx, &by);
        m_recoverTl->setToValue(VfxRect(bx, by, bw, bh));        
        m_recoverTl->m_signalStopped.connect(this, &VcpScrollableView::onScrollAnimStop);        
        m_recoverTl->start();

        // update bounds property             
        updateBoundsValue(VfxRect(bx, by, bw, bh));      
   
    }
}


void VcpScrollableView::onScrollAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_boundsTlNeedMerge = VFX_FALSE;
    m_isDecelerating = VFX_FALSE;
    m_isResizing = VFX_FALSE;
    m_freeRunPara[0] = m_freeRunPara[1] = m_freeRunPara[2] = m_freeRunPara[3] = 0;
    m_signalScrollStopped.emit(timeline, isCompleted);
    if (m_penMoveTimer->getIsEnabled()) 
    {
        onPenDown();
        m_penMoveTimer->stop(); // stop in the end because we check penDownTimer in onPenDown
        
    }

     VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_SCROLL_ANIM_STOP, this, m_isTracking, m_isDragging, m_isDecelerating);
}


void VcpScrollableView::stopScrolling()
{
    // update state
    m_isTracking = VFX_FALSE;
    m_isDragging = VFX_FALSE;
    m_isDecelerating = VFX_FALSE;
    m_isResizing = VFX_FALSE;
    
    // suspend VRT to let the screen freezed
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
           
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    // stop bounds related animation
    stopBoundsAnimation();
    
    // force set bound, must get the current bounds (visually correct)
    setBoundsInternal(VfxRect(forceGetBounds().origin, getSize()), VFX_TRUE);        
    VfxAutoAnimate::commit();

}


void VcpScrollableView::onPenDownTimerTick(VfxTimer *source)
{
    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    penSrv->resumeDelayedEvent();

    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_DOWN_TIMER_TICK, this, m_isTracking, m_isDragging, m_isDecelerating, m_freeRunTl->getIsEnabled());
}


void VcpScrollableView::onPenMoveTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);    

    if (m_freeRunTl->getIsEnabled() || m_recoverTl->getIsEnabled())
    {
        onPenDown();
    }
    VFX_LOG(VFX_INFO2, VCP_SCROLLABLE_MOVE_TIMER_TICK, this, m_isTracking, m_isDragging, m_isDecelerating, m_freeRunTl->getIsEnabled());
}


void VcpScrollableView::onPenDown()
{
       
   // update state
    m_isTracking = VFX_TRUE;
    m_isDragging = VFX_FALSE;
    m_isDecelerating = VFX_FALSE;
    m_isResizing = VFX_FALSE;

    
    // must get the current bounds (visually correct)
    VfxRect bounds = forceGetBounds();        
    m_penDownOrigin = bounds.origin;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);   
    if(m_bounds != bounds)
    {
        vrt_rect_struct vrtValue = bounds;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_BOUNDS,
            &vrtValue,
            &vrtValue,
            sizeof(vrtValue));      
        updateBoundsValue(bounds);  
    }
    VfxAutoAnimate::commit();       


    VfxBool isBoundsAnimationStopped = stopBoundsAnimation();

    // start to do scrolling
    if (m_penMoveTimer->getIsEnabled()) 
    {
        m_signalScrollStarted.emit(VFX_TRUE);
    }
    else
    {
        m_signalScrollStarted.emit(isBoundsAnimationStopped);
    }

}
VfxBool VcpScrollableView::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    VFX_UNUSED(aborter);

    if(reason == VFX_PEN_ABORT_REASON_CAPTURE_SWIPE)
    {
      
        VfxBool isHScroll, isVScroll; 
       
        isHScroll = (VfxBool)(m_contentSize.width > getSize().width);
        isVScroll = (VfxBool)(m_contentSize.height > getSize().height);
       
        if (!isHScroll&&!isVScroll)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }        

    }
    else
    {
        return VFX_TRUE;
    }

}


/***************************************************************************** 
 * Class VcpScrollable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpScrollable", VcpScrollable, VfxControl);

/*
 * scrollable class configuable parameters
 */
#if defined(__COSMOS_MMI__)
    const VfxFloat VcpScrollable::SCROLL_INDICATOR_OPACITY = 1.0f;
#elif defined(__MMI_VUI_SHELL_APP__) && defined(__MMI_FTE_SUPPORT__)
    const VfxFloat VcpScrollable::SCROLL_INDICATOR_OPACITY = 0.9f;
#else
    const VfxFloat VcpScrollable::SCROLL_INDICATOR_OPACITY = 0.5f;
#endif    

#if defined(__COSMOS_MMI__)
    #define SCROLL_INDICATOR_GAP 2
    #define SCROLL_BOUNDARY_LIGHT_COLOR VFX_COLOR_RES(VCP_CLR_SCROLLABLE_LIGHT)
#else
    #define SCROLL_INDICATOR_GAP 0
    #define SCROLL_BOUNDARY_LIGHT_COLOR VFX_COLOR_NULL    
#endif

VcpScrollable::VcpScrollable() :
    m_view(NULL),
    m_scrollIndicatorStyle(VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_OVERLAY),
    m_indicatorColor(VFX_COLOR_NULL),
    m_viewRect(VFX_RECT_ZERO),
    m_parentScrollableView(NULL),
    m_boundaryLight(NULL),
    m_isBoundaryLight(VFX_TRUE),
    m_boundaryLightColor(SCROLL_BOUNDARY_LIGHT_COLOR)    
{
    m_scrollIndicator[0] = m_scrollIndicator[1] = NULL;
    m_isEnableIndicator[0] = m_isEnableIndicator[1] = VFX_TRUE;
}


void VcpScrollable::onInit()
{
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SIN", SA_start);
#endif                    
    VfxControl::onInit();
    // create the view
    m_view = onCreateView();
    m_view->m_parentScrollableView = m_parentScrollableView;
    
    // must use the frame class onAddChild since addChild is redirected to view
    addChildFrame(m_view);
    // connect bounds change for scroll bar update
    m_view->m_signalBoundsChanged.connect(this, &VcpScrollable::onViewBoundsValueChange);

    // connect scroll start/end notification
    m_view->m_signalScrollStarted.connect(this, &VcpScrollable::onScrollStart);
    m_view->m_signalScrollStopped.connect(this, &VcpScrollable::onScrollStop);
    m_view->m_signalScrolling.connect(this, &VcpScrollable::onScrolling);


    // connect view content warning event
    m_view->m_signalContentWarning.connect(this, &VcpScrollable::emitContentWarning);
    // connect view content error event    
    m_view->m_signalContentError.connect(this, &VcpScrollable::emitContentError);


#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SIN", SA_stop);
#endif         
}


void VcpScrollable::onDeinit()
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("SDI", SA_start);
#endif     
    // close the view
    onCloseView();

    VfxControl::onDeinit();    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SDI", SA_stop);
#endif    
}

void VcpScrollable::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            VfxObject* obj = (VfxObject*)userData;
            onAddChild(obj);
            return; 
        }
        case VFX_FRAME_NOTIFY_ID_UPDATE_VIEW_FOR_IME:
        {          
            VfxFrameUpdateViewForImeData* data = (VfxFrameUpdateViewForImeData*)userData;
            data->ret = updateViewForIme(data->focusFrame);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            VfxFrame *frame = (VfxFrame*)userData;         
            onParentFrameChanged(frame);
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }

}

void VcpScrollable::setWarningContentRect(
    VfxRect rect    // [IN]  warning content rect
)
{     
    m_view->setWarningContentRect(rect);
}


void VcpScrollable::setValidContentRect(
    VfxRect rect    // [IN] valid content rect
)
{    
    m_view->setValidContentRect(rect);
}

void VcpScrollable::onAddChild(VfxObject *child)
{       
    VfxControl::onAddChild(child);

    VfxFrame *frameChild = VFX_OBJ_DYNAMIC_CAST(child, VfxFrame);
    if (frameChild != NULL)
    {
        if (m_view)
        {
            m_view->addChildFrame(frameChild);
        }    
    }
}


void VcpScrollable::onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    
    VFX_LOG(VFX_INFO, VCP_SCROLLABLE_INFO_SCROLL_BOUNDS_CHANGE, this);
}


void VcpScrollable::setContentSize(const VfxSize &size)
{
    m_view->setContentSize(size);
    onCreateIndicators();
}


VcpScrollableView *VcpScrollable::onCreateView()
{
    VcpScrollableView *view;
    
    VFX_OBJ_CREATE(view, VcpScrollableView, this);

    return view;
}


void VcpScrollable::onCloseView()
{
    VFX_OBJ_CLOSE(m_view);
}


void VcpScrollable::setViewRect(const VfxRect &rect)
{
    m_viewRect = rect;
    m_view->setRect(rect);    
    onCreateIndicators();   
}

void VcpScrollable::setBounds(const VfxRect &value)
{
    VfxRect oldbounds = m_bounds;    
    VfxControl::setBounds(value);
    
    VfxSize vs = m_view->getSize();    
    VfxSize bs = value.size;
    if (m_view)
    {
        if(m_viewRect == VFX_RECT_ZERO)
        {            
            setViewRect(VfxRect(0, 0, value.size.width, value.size.height));
        }
        else
        {            
            VfxS32 marginx = oldbounds.size.width - (m_viewRect.origin.x + m_viewRect.size.width);
            VfxS32 marginy = oldbounds.size.height - (m_viewRect.origin.y + m_viewRect.size.height);

            VfxRect rect;            
            rect.origin = m_viewRect.origin;            
            rect.size.width = value.size.width - rect.origin.x - marginx;
            rect.size.height = value.size.height - rect.origin.y - marginy;                        
            setViewRect(rect);
        }                
    }    
}


void VcpScrollable::onCreateIndicators(VfxBool fixed){

    VfxRect bounds = m_view->getBounds();    
    VfxSize size = m_view->getContentSize();        


    for (VfxS32 i = 0; i < 2; ++i)
    {        
        if ((ARRAY(size, i) > ARRAY(bounds.size, i) && m_isEnableIndicator[i]) || fixed)
        {   
            if (m_scrollIndicator[i] == NULL)
            {            
                // create horizontal scrollbar
                VFX_OBJ_CREATE(m_scrollIndicator[i], VcpScrollIndicator, this);
            addChildFrame(m_scrollIndicator[i]);

            m_scrollIndicator[i]->setIsUnhittable(VFX_TRUE);
            m_scrollIndicator[i]->setAutoAnimate(VFX_TRUE);
            m_scrollIndicator[i]->setStyle(i);
            m_scrollIndicator[i]->setTargetFPE(m_view);
            m_scrollIndicator[i]->setIndicatorColor(m_indicatorColor);
            m_scrollIndicator[i]->setIndicatorImg(m_indicatorImg);


            if(m_scrollIndicatorStyle == VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED)
            {
                m_scrollIndicator[i]->setOpacity(SCROLL_INDICATOR_OPACITY);            
            }
            else
            {
                m_scrollIndicator[i]->setOpacity(0);
            }

            }        
        }
        else
        {
            VFX_OBJ_CLOSE(m_scrollIndicator[i]);
        }
    }
    updateIndicator();
}



void VcpScrollable::setScrollIndicatorStyle(VcScrollableScrollIndicatorStyleEnum style)
{
    m_scrollIndicatorStyle = style;

    if (style == VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED)
    {
        for (VfxS32 i = 0; i < 2; ++i)
        {
            if (m_scrollIndicator[i])
            {
                m_scrollIndicator[i]->setOpacity(SCROLL_INDICATOR_OPACITY);
                m_scrollIndicator[i]->setHidden(VFX_FALSE);
            }
        }
    }    
}


void VcpScrollable::enableHorizontalScrollIndicator(VfxBool isEnable)
{
    m_isEnableIndicator[0]= isEnable;
    onCreateIndicators();
    if(m_scrollIndicator[0])
    {
        m_scrollIndicator[0]->setHidden(isEnable ? VFX_FALSE : VFX_TRUE);
    }
}


void VcpScrollable::enableVerticalScrollIndicator(VfxBool isEnable)
{
    m_isEnableIndicator[1]= isEnable;
    onCreateIndicators();
    if(m_scrollIndicator[1])
    {
        m_scrollIndicator[1]->setHidden(isEnable ? VFX_FALSE : VFX_TRUE);
    }
}


void VcpScrollable::setContentOffset(VfxPoint offset, VfxBool isAnimated)
{
    VfxRect b;

    // only change bounds origin
    b = m_view->getBounds();
    
    if (b.origin == offset)
    {
        return;
    }    

    b.origin = offset;

    scrollRectToVisible(b, isAnimated);
}


void VcpScrollable::scrollRectToVisible(VfxRect rect, VfxBool isAnimated)
{
    VfxBool aa = m_view->getAutoAnimate();

    // TODO: align rect to center    
    VFX_LOG(VFX_INFO, VCP_SCROLLABLE_INFO_SCROLL_TO_VISIBLE, this, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, isAnimated);

    // stop bounds animation
    m_view->stopBoundsAnimation();
    m_view->setAutoAnimate(isAnimated);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnimated);

    if (!isAnimated)
    {
        onScrollStart(VFX_TRUE);
    }
    
    // must force set bounds. The scroll start/stop signal will be emitted from the view if auto animation is enabled.
    m_view->setBoundsInternal(rect, VFX_TRUE);
    
    VfxAutoAnimate::commit();    

    if (!isAnimated)
    {
        onScrollStop(NULL, VFX_TRUE);
    }    

    m_view->setAutoAnimate(aa);
}


VfxBool VcpScrollable::updateViewForIme(VfxFrame * focusFrame)
{
    VfxRect rect = focusFrame->convertRectTo(focusFrame->getBounds(), m_view);
    VfxRect bounds = m_view->getBounds();
    VfxRect oldBounds = bounds;

    if (focusFrame != this)
    {
        if (rect.getMaxY() > bounds.getMaxY())
        {
            bounds.origin.y += rect.getMaxY() - bounds.getMaxY();
        }
        else if (rect.getMinY() < bounds.getMinY())
        {
            bounds.origin.y -= bounds.getMinY() - rect.getMinY();
        }

        // re-calculate for a special case (bounds size is smaller than rect size)
        // to keep at the same position
        if (rect.getMaxY() > bounds.getMaxY())
        {
            bounds.origin.y += rect.getMaxY() - bounds.getMaxY();            
        }
        else if (rect.getMinY() < bounds.getMinY())
        {
            bounds.origin.y -= bounds.getMinY() - rect.getMinY();        
        }


        if (bounds.origin.y != oldBounds.origin.y)
        {
            scrollRectToVisible(bounds, VFX_TRUE);
        }        
    }

    return VFX_TRUE;
}

void VcpScrollable::onScrollStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    // TODO: FIX THIS INTERFACE
    VFX_UNUSED(timeline);

    if (isCompleted)
    {
        if (m_scrollIndicatorStyle != VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(SCROLL_INDICATOR_FADE_OUT_DURATION);

            for (VfxS32 i = 0; i < 2; ++i)
            {
                if (m_scrollIndicator[i])
                {
                    m_scrollIndicator[i]->setOpacity(0);
                }
            }
            VfxAutoAnimate::commit();

        }
              
        if(m_boundaryLight)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_FALSE);
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            VfxAutoAnimate::setDuration(SCROLL_INDICATOR_FADE_OUT_DURATION);
            m_boundaryLight->setAutoAnimate(VFX_TRUE);
            m_boundaryLight->setOpacity(0);
            VfxAutoAnimate::commit();
        }         

        
    }

    VFX_LOG(VFX_INFO, VCP_SCROLLABLE_INFO_SCROLL_STOP, this, isCompleted);

    // emit stop scroll signal
    m_signalScrollStopped.emit(this);
}


void VcpScrollable::onScrollStart(VfxBool isShowIndicator)
{
    if (isShowIndicator)
    {
        showScrollIndicator();
    }        

    VFX_OBJ_CLOSE(m_boundaryLight);
    VFX_LOG(VFX_INFO, VCP_SCROLLABLE_INFO_SCROLL_START, this);
    
    // emit scroll start signal
    m_signalScrollStarted.emit(this);
}

void VcpScrollable::onScrolling(VfxPoint origin, VfxRect elasticRect)
{   
    VFX_LOG(VFX_INFO, VCP_SCROLLABLE_INFO_SCROLL_ING, this);
    showScrollIndicator();
    showBoundaryLight(origin, elasticRect);

	m_signalScrolling.emit(this);
}

void VcpScrollable::showScrollIndicator()
{
    // show scrollbars without animation    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    for (VfxS32 i = 0; i < 2; ++i)
    {
        if (m_isEnableIndicator[i] && !isInitializing())
        {
            if (m_scrollIndicator[i])
            {
                m_scrollIndicator[i]->setOpacity(SCROLL_INDICATOR_OPACITY);
            }
        }
    }
    VfxAutoAnimate::commit();
}


void VcpScrollable::showBoundaryLight(VfxPoint origin, VfxRect elasticRect)
{         
    VfxS32 bh = m_view->getSize().height;
    VfxS32 bw = m_view->getSize().width;    
    VfxS32 by = origin.y;
    VfxS32 topY = elasticRect.origin.y;
    VfxS32 bottomY = elasticRect.origin.y + elasticRect.size.height - 1;
//    VfxS32 leftX = elasticRect.origin.x;
//    VfxS32 rightX = elasticRect.origin.x + elasticRect.size.width - 1;

    VfxS32 maxlightheight = bh / 10;       
            
    // apply elastic margin hard limit
    if (by < topY && m_isBoundaryLight)
    {               
#if 0           //2D boundary light
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        BoundaryLightData data;
        data.anchor = VfxFPoint(0.0, 0.0);
//      data.rect.origin = VfxPoint(m_view->getPos().x, m_view->getPos().y);  //attached to view            
        data.rect.origin = VfxPoint(0, topY - getViewBounds().origin.y);  //attached to scrollable
        data.rect.size = VfxSize(bw, VFX_MIN(maxlightheight, topY - by));
        data.direction = 2; //top
        onCreateBoundaryLight(data);                            
    } 
    else if (by + bh > bottomY && m_isBoundaryLight)
    {              
#if 0           //2D boundary light    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        BoundaryLightData data;
        data.anchor = VfxFPoint(0.0, 1.0);
//        data.rect.origin = VfxPoint(m_view->getPos().x, m_view->getPos().y + bh - 1); //attached to view       
        data.rect.origin = VfxPoint(0, getSize().height + bottomY - getViewBounds().getMaxY()); //attached to scrollable
        data.rect.size = VfxSize(bw, VFX_MIN(maxlightheight, by + bh - bottomY));
        data.direction = 4; //bottom
        onCreateBoundaryLight(data);
    }
    else
    {
        VFX_OBJ_CLOSE(m_boundaryLight);        
    }

}




void VcpScrollable::onCreateBoundaryLight(BoundaryLightData userdata)
{
#ifdef __COSMOS_3D_V10__


    if(m_boundaryLight == NULL)
    {
        
#if 0                   //2D boundary light
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        VFX_OBJ_CREATE(m_boundaryLight, VfxImageFrame, this);
        addChildFrame(m_boundaryLight);



        m_boundaryLight->bringToFront();                        
        m_boundaryLight->setBgColor(m_boundaryLightColor);
        m_boundaryLight->setOpacity(0.6f);
        m_boundaryLight->setIsUnhittable(VFX_TRUE);

        
        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxImage2D *image;
        VfxShaderUniforms *uniforms;
        VfxTexture2D *tex;

        VfxCompositingMode *cm;        
        VfxBlender *blender;
        

        VFX_OBJ_CREATE_EX(material, VfxMaterial, m_boundaryLight, (1));
        m_boundaryLight->setMaterial(material);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_SCROLLABLE_BOUNDARY_LIGHT));
//        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR("D:\\vcp_scrollable_boundarylight.fs")));
        pass->setShaderProgram(program);


        VFX_OBJ_CREATE_EX(image, VfxImage2D, material, (VCP_IMG_SCROLLABLE_BOUNDARY_LIGHT));
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, material, (image));
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);                                               
        
        uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);
        uniforms->addUniformVariable(VFX_STR("direction"), VFX_TYPE_ID_S32, 1)->setValue(userdata.direction);


        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);
        
    }
    if(m_boundaryLight)
    {            
        m_boundaryLight->setAnchor(userdata.anchor);
        m_boundaryLight->setPos(userdata.rect.origin);                   
        m_boundaryLight->setSize(userdata.rect.size);
        m_boundaryLight->getMaterial()->getPass(0)->getUniformVariable(VFX_STR("direction"))->setValue(userdata.direction);   
    }

#endif    
}

void VcpScrollable::setMaxDecelerationDistance(VfxS32 horizontalDist, VfxS32 verticalDist)
{
    m_view->m_maxScrollDist[0] = horizontalDist;
    m_view->m_maxScrollDist[1] = verticalDist;
}



void VcpScrollable::setContentOrigin(const VfxPoint &origin)
{
    m_view->setContentOrigin(origin);
}


void VcpScrollable::updateIndicator()
{

    VfxRect bounds = m_view->getBounds();    
    

    for (VfxS32 i = 0; i < 2; ++i)
    {
        if (m_isEnableIndicator[i])
        {
            if (m_scrollIndicator[i])
            {
            	VfxSize contentSize = getContentSize();
                m_scrollIndicator[i]->setHidden(ARRAY(contentSize, i) <= ARRAY(bounds.size, i));    
                if (m_scrollIndicatorStyle == VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED)
                {
                    m_scrollIndicator[i]->setHidden(VFX_FALSE);
                }
            }
        }
    }
     

    VfxS32 reserve_space;

    // must leave a space to prevent intersection of two scroll bars
    if (m_isEnableIndicator[0] && m_isEnableIndicator[1] &&
        m_scrollIndicator[0] && m_scrollIndicator[1] &&
        ((m_view->getContentSize().width > bounds.size.width) && (m_view->getContentSize().height > bounds.size.height)))
    {
        reserve_space = SCROLL_INDICATOR_SIZE;
    }
    else
    {
        reserve_space = 0;
    }

    for (VfxS32 i = 0; i < 2; ++i)
    {     
        if (m_scrollIndicator[i])
        {
            VfxS32 tmp[2] = {0};
			VfxRect viewBounds;
			VfxSize contentSize;
            tmp[i] = 0;
            tmp[1 - i] = ARRAY(getSize(), 1 - i) - SCROLL_INDICATOR_SIZE - SCROLL_INDICATOR_GAP;
            m_scrollIndicator[i]->setPos(tmp[0], tmp[1]);
            tmp[i] = ARRAY(getSize(), 1) - reserve_space;
            tmp[1 - i] = SCROLL_INDICATOR_SIZE;
			viewBounds = m_view->getBounds();
			contentSize = getContentSize();
            m_scrollIndicator[i]->setBounds(VfxRect(0, 0, tmp[0], tmp[1]));
            m_scrollIndicator[i]->setScrollScale(ARRAY(viewBounds.size, i));    
            m_scrollIndicator[i]->setScrollRange(ARRAY(contentSize, i));    
        }
 
    }
 
    
}


void VcpScrollable::onParentFrameChanged(VfxFrame *origParentFrame)
{
    VfxControl::onParentFrameChanged(origParentFrame);
    if(m_parentScrollableView) 
    {    
        m_parentScrollableView = NULL;    
        if(m_view)
        {
            m_view->m_parentScrollableView = NULL;
        }
        
    }
    VfxFrame *parentFrame = getParentFrame();
    while(parentFrame)
    {
        VcpScrollableView *parentScrollableView = VFX_OBJ_DYNAMIC_CAST(parentFrame, VcpScrollableView); //new parent
        if (parentScrollableView != NULL)
        {
            m_parentScrollableView = parentScrollableView;
            if(m_view)
            {
                m_view->m_parentScrollableView = m_parentScrollableView;                
            }
                
            break;
        }              
        parentFrame = parentFrame->getParentFrame();
    } 
}


/***************************************************************************** 
 * class VcpScrollIndicator
 *****************************************************************************/

VcpScrollIndicator::VcpScrollIndicator() :
    m_view(NULL),
    m_range(UNKNOWN_VALUE),
    m_scale(UNKNOWN_VALUE),
    m_style(VCP_SCROLL_INDICATOR_STYLE_NONE),
    m_minSize(SCROLL_INDICATOR_MIN_SIZE),
    m_checkUpdate(VFX_FALSE)
{    
}


void VcpScrollIndicator::onInit()
{
    VfxFrame::onInit();

    // create indicator
    VFX_OBJ_CREATE(m_indicator, VfxFrame, this);

#if defined(__MMI_VUI_SHELL_APP__) && defined(__MMI_FTE_SUPPORT__)
    m_indicator->setImgContent(VfxImageSrc(VCP_IMG_SCROLLABLE_INDICATOR));    
    m_indicator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else
    m_indicator->setBgColor(VFX_COLOR_WHITE);
#endif

}



void VcpScrollIndicator::checkUpdate()
{
    if (!m_checkUpdate)
    {
        m_checkUpdate = VFX_TRUE;
        vfxPostInvoke0(this, &VcpScrollIndicator::processUpdate);
    }
}


void VcpScrollIndicator::processUpdate()
{
    if (m_checkUpdate)
    {
        m_checkUpdate = VFX_FALSE;
        onUpdate();
    }
}


void VcpScrollIndicator::setScrollRange(VfxS32 range)
{
    m_range = range;

    checkUpdate();
}


void VcpScrollIndicator::setScrollScale(VfxS32 scale)
{
    m_scale = scale;

    checkUpdate();
}


void VcpScrollIndicator::setStyle(VfxU32 style) 
{
    m_style = style;

    checkUpdate();
}


void VcpScrollIndicator::onUpdate()
{
    VFX_ASSERT(m_view);    
    setTargetFPE(m_view);
}


void VcpScrollIndicator::setIndicatorMinSize(VfxU32 minSize)
{
    m_minSize = minSize;
}


VfxU32 VcpScrollIndicator::getIndicatorMinSize()
{
    return m_minSize;
}


void VcpScrollIndicator::setIndicatorColor(
    const VfxColor &value   // [IN] indicator color
)
{
    if (value != VfxColor(VFX_COLOR_NULL))
    {
#ifdef __COSMOS_3D_V10__     
        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;

        VfxFloat R = VfxFloat(value.getR()) / 255.f;
        VfxFloat G = VfxFloat(value.getG()) / 255.f;
        VfxFloat B = VfxFloat(value.getB()) / 255.f;
       
        VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));
        m_indicator->setMaterial(material);
        
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);
        
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_SCROLLABLE_INDICATOR));
        pass->setShaderProgram(program);    
        
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);                                               
        
        uniforms->addUniformVariable(VFX_STR("color"), VFX_TYPE_ID_VEC3, 1)->setValue(R, G, B);
        pass->addShaderUniforms(uniforms);


#else        
        m_indicator->setImgContent(VFX_IMAGE_SRC_NULL);
        m_indicator->setBgColor(value);
#endif    

    }
    else
    {
        m_indicator->setImgContent(VfxImageSrc(VCP_IMG_SCROLLABLE_INDICATOR));    
        m_indicator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_indicator->setBgColor(value);

#ifdef __COSMOS_3D_V10__ 
        m_indicator->setMaterial(NULL);
#endif
    }    
}


void VcpScrollIndicator::setIndicatorImg(const VfxImageSrc &value)
{
    if(!value.isNull())
    {
        m_indicator->setImgContent(value);    
        m_indicator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }
}

void VcpScrollIndicator::setTargetFPE(
    VcpScrollableView *view
)
{

    m_view = view;
    
    if ((m_scale == UNKNOWN_VALUE) || (m_range == UNKNOWN_VALUE))
    {
        return;
    }


    // handle size <= 0 special case, simply hide me
    if (m_range <= 0)
    {
        m_range = UNKNOWN_VALUE;
        setHidden(VFX_TRUE);
        
        return;        
    }
    
    FramePropertyEffectData data;
    data.contentOrigin  = view->getContentOrigin();
    data.scale = m_scale;
    data.range = m_range;
    data.style = m_style;
    data.minSize = m_minSize;
    data.width = getBounds().size.width;
    data.height = getBounds().size.height;
    

    m_indicator->setPropertyEffectCallback(
        view,
        indicatorEffectCallBack,
        &data,
        sizeof(data),
        VRT_FPE_TRIGGER_TYPE_DIRTY
    );    
}


vrt_render_dirty_type_enum VcpScrollIndicator::indicatorEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame);
    VFX_DEV_ASSERT(watch_frame);

    VFX_DEV_ASSERT(user_data_size == sizeof(FramePropertyEffectData));
    FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;

    VfxRect bounds = watch_frame->bounds;      
    VfxS32 pos, range, start, end, diff;
    VfxS32 factor = 20;



    if (userData->style & VCP_SCROLL_INDICATOR_STYLE_HORIZONTAL)
    {
        diff = factor * VRT_MAX((bounds.origin.x + bounds.size.width) - (userData->contentOrigin.x + userData->range), 0);
        start = VRT_MIN(bounds.origin.x, userData->contentOrigin.x) - diff;               
 
        diff = factor * VRT_MAX(userData->contentOrigin.x - bounds.origin.x, 0);      
        end = VRT_MAX(bounds.origin.x + bounds.size.width, userData->contentOrigin.x + userData->range) + diff;
     
        range = end - start;        
        pos = (VfxS32) VFX_MIN(bounds.origin.x - start, range * (1.0f - (VfxFloat)userData->minSize / (VfxFloat)userData->width));

        
        target_frame->pos.x = pos * userData->width / userData->range;
        target_frame->bounds.size.width = VFX_MIN(VFX_MAX(userData->scale * userData->width / range, (VfxS32)userData->minSize), userData->width);
        target_frame->bounds.size.height = userData->height;
    }
    else
    {
        // vertical

        diff = factor * VRT_MAX((bounds.origin.y + bounds.size.height) - (userData->contentOrigin.y + userData->range), 0);
        start = VRT_MIN(bounds.origin.y, userData->contentOrigin.y) - diff;               
 
        diff = factor * VRT_MAX(userData->contentOrigin.y - bounds.origin.y, 0);      
        end = VRT_MAX(bounds.origin.y + bounds.size.height, userData->contentOrigin.y + userData->range) + diff;

        range = end - start;        
        pos = (VfxS32) VFX_MIN(bounds.origin.y - start, range * (1.0f - (VfxFloat)userData->minSize / (VfxFloat)userData->height));


        target_frame->pos.y = pos * userData->height / range;	          
        target_frame->bounds.size.width = userData->width;
        target_frame->bounds.size.height = VFX_MIN(VFX_MAX(userData->scale * userData->height / range, (VfxS32)userData->minSize), userData->height);
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}
