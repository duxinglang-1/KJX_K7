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
 *  vcp_activity_indicator.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Activity and progress component header
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VCP_ACTIVTY_INDICATOR_H__
#define __VCP_ACTIVTY_INDICATOR_H__

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_animation.h"
#include "vfx_signal.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_progress_indicator.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_ACTIVITY_INDICATOR_UPDATE_FPS  (6)
#define VCP_ACTIVITY_INDICATOR_UPDATE_INTERVAL  (1000/VCP_ACTIVITY_INDICATOR_UPDATE_FPS)
#define BEZIER_BINARY_SEARCH_LOOP_NUM   20

#define BALL_SCALE_RATIO_MAX 1.0f
#define BALL_SCALE_RATIO_MIN 0.2f
#define BALL_OPACITY_MIN	0.4f

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpActivityIndicator
 *  Use this class to create an animated indicator to show an ongoing activity.
 *****************************************************************************/
class VcpActivityIndicator : public VfxFrame
{
    // Internal macros
    enum
    {        
#ifdef __MMI_MAINLCD_480X800__
        WIDTH           = 50,
        HEIGHT          = 50,
        BALL_SIZE_THRESH_1 = 70,
        BALL_SIZE_THRESH_2 = 100,        
#elif defined(__MMI_MAINLCD_320X480__)
        WIDTH           = 32,
        HEIGHT          = 32,
        BALL_SIZE_THRESH_1 = 45,
        BALL_SIZE_THRESH_2 = 64,
#elif defined(__MMI_MAINLCD_240X400__)
        WIDTH           = 26,
        HEIGHT          = 26,
        BALL_SIZE_THRESH_1 = 36,
        BALL_SIZE_THRESH_2 = 52,
#elif defined(__MMI_MAINLCD_240X320__)
        WIDTH           = 26,
        HEIGHT          = 26,
        BALL_SIZE_THRESH_1 = 36,
        BALL_SIZE_THRESH_2 = 52,
#else 
        WIDTH           = 26,
        HEIGHT          = 26,
        BALL_SIZE_THRESH_1 = 36,
        BALL_SIZE_THRESH_2 = 52,
#endif
        BALL_NUM        = 8,
        REPEAT_DURATION = 1000,
        BALL_TIME       = REPEAT_DURATION / BALL_NUM
    };     

// Constructor / Destructor
public:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Constructor/Destructor>
    // Constructor block.
    VcpActivityIndicator() : 
        m_isAnimating(VFX_FALSE),
        m_isHiddenWhenStopped(VFX_TRUE),
        m_image(NULL)
    {
        for (VfxS32 i = 0; i < BALL_NUM; i++)
        {
            m_ball[i] = NULL; 
        }    
    }

// Method
public:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Method>
    // Starts animation.
    void start();

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Method>
    // Stops animation.
    void stop();

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Method>
    // Returns whether animation is running
    // RETURNS :
    // VFX_TRUE if animation is running, otherwise VFX_FALSE.
    VfxBool isAnimating()
    {
        return m_isAnimating;
    }

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Method>
    // Gets auto hidden flag.
    // RETURNS :
    // VFX_FALSE if flag is disabled, otherwise VFX_TRUE.
    VfxBool getHiddenWhenStopped() const
    {
        return m_isHiddenWhenStopped;
    }

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Method>
    // Sets auto hidden flag when stopped.
    void setHiddenWhenStopped(
        VfxBool isHiddenWhenStopped     // [IN] hidden when stopped flag
    )
    {
        m_isHiddenWhenStopped = isHiddenWhenStopped;
    }

// Overridable:
public:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Overridable>
    // Sets the size of activity indicator. 
    virtual void setBounds(const VfxRect &value);

// Overridable
protected:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Overridable>
    // Initializing routine.
    virtual void onInit();

// Implementation
private:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Implementation>
    void onSize(const VfxRect &bounds);

// Variable
private:
    // <group DOM_ActivityIndicator_VcpActivityIndicator_Implementation>
    // Flag to check whether activity indicator is already animating!
    VfxBool m_isAnimating;

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Implementation>
    // Flag to check whether activity indicator should hide when stop animating! 
    VfxBool m_isHiddenWhenStopped;

    // <group DOM_ActivityIndicator_VcpActivityIndicator_Implementation>
    // Activity indicator image.
    VfxControl *m_image;

// Animation mechanism
private:
    typedef struct
    {
        VfxObjHandle visual;
        VfxMsec lastUpdateTime;
        VfxMsec startTime;
        VfxS32 index;
    }ballFPEUserDataStruct, *ballFPEUserDataStructp;

    typedef struct
    {
        VfxObjHandle visual;
        VfxMsec lastUpdateTime;
    }watchFrameFPEUserDataStruct, *watchFrameFPEUserDataStructp;

    VfxImageFrame           *m_ball[BALL_NUM];

    void onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds); 

    static vrt_render_dirty_type_enum ballFramePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
    
    static vrt_render_dirty_type_enum watchFramePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
    
    static VfxFloat interpolateFloat(VfxFloat from_value, VfxFloat to_value, VfxFloat t);
    static VfxFloat easyInOutTimingFuncBezier(VfxFloat x, void *data, VfxU32 data_size);
};
 
#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_ACTIVTY_INDICATOR_H__ */

