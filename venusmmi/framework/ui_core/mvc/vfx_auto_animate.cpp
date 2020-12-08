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
 *  vfx_auto_animate.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vfx_auto_animate.h"

#include "vfx_frame.h"
#include "vfx_animation.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_canvas.h"
#include "vrt_datatype.h"
#include "vfx_system.h"
#include <string.h>


/***************************************************************************** 
 * Class VfxAutoAnimate
 *****************************************************************************/

VfxAutoAnimate::StackContext VfxAutoAnimate::s_contextStack[VFX_AUTO_ANIMATE_STACK_SIZE];
VfxU32 VfxAutoAnimate::s_contextStackTop = 0;
VfxBool VfxAutoAnimate::s_initAnimate = VFX_FALSE;
    
VfxAutoAnimate::StackContext VfxAutoAnimate::s_currentContext =
{
    VFX_FALSE,    
    VFX_TIMELINE_DEFAULT_DUR_TIME,
    NULL
};


VfxBool VfxAutoAnimate::getDisable()
{
    return s_currentContext.isDisabled;
}


void VfxAutoAnimate::setDisable(VfxBool value)
{
    s_currentContext.isDisabled = value;
}


VfxMsec VfxAutoAnimate::getDuration()
{
    return s_currentContext.durTime;
}


void VfxAutoAnimate::setDuration(VfxMsec value)
{
    VFX_ASSERT(value >= 0);
    
    s_currentContext.durTime = value;
}


void VfxAutoAnimate::setTimingFunc(VfxTimingFuncIdEnum value)
{
    VFX_ASSERT(value < VFX_TIMING_FUNC_ID_END_OF_ENUM);

    const vrt_timeline_timing_callback_struct *callback = 
        vrt_timeline_get_predefined_timing_func((vrt_timing_func_id_enum)value);

    // Free the original callback structure
    if (s_currentContext.customTimingCallback != NULL)
    {
        VFX_SYS_FREE_MEM(s_currentContext.customTimingCallback);
        s_currentContext.customTimingCallback = NULL;
    }

    if (callback != NULL)
    {
        VfxU32 structSize = VRT_CALLBACK_STRUCT_PTR_SIZE(callback);
        VFX_DEV_ASSERT(structSize != 0);
        
        VFX_SYS_ALLOC_MEM(s_currentContext.customTimingCallback, structSize);
        memcpy(s_currentContext.customTimingCallback, callback, structSize);
    }
}


void VfxAutoAnimate::setCustomTimingFunc(VfxTimelineTimingFuncPtr callback, const void *userData, VfxU32 userDataSize)
{
    // Free the original callback structure
    if (s_currentContext.customTimingCallback != NULL)
    {
        VFX_SYS_FREE_MEM(s_currentContext.customTimingCallback);
        s_currentContext.customTimingCallback = NULL;
    }

    // Create a new callback structure
    if (callback != NULL)
    {
        VfxU32 structSize = VRT_CALLBACK_STRUCT_SIZE(
            vrt_timeline_timing_callback_struct, 
            userDataSize);

        VFX_SYS_ALLOC_MEM(s_currentContext.customTimingCallback, structSize);
        s_currentContext.customTimingCallback->callback = (vrt_timing_funcptr_type)callback;
        s_currentContext.customTimingCallback->user_data_size = userDataSize;
        if (userData != NULL)
        {
            VFX_ASSERT(userDataSize != 0);
            memcpy(
                VRT_CALLBACK_STRUCT_DATA(s_currentContext.customTimingCallback),
                userData,
                userDataSize);
        }
        else
        {
            VFX_ASSERT(userDataSize == 0);
        }
    }
    else
    {
        VFX_ASSERT(userData == NULL);
    }    
}


void VfxAutoAnimate::begin()
{
    VFX_ASSERT(s_contextStackTop < VFX_AUTO_ANIMATE_STACK_SIZE);

    s_contextStack[s_contextStackTop] = s_currentContext;
    s_contextStackTop++;

    s_currentContext.customTimingCallback = NULL;
}


void VfxAutoAnimate::commit()
{
    VFX_ASSERT(s_contextStackTop > 0);

    if (s_currentContext.customTimingCallback != NULL)
    {
        VFX_SYS_FREE_MEM(s_currentContext.customTimingCallback);
        s_currentContext.customTimingCallback = NULL;
    }

    s_contextStackTop--;
    s_currentContext = s_contextStack[s_contextStackTop];
}


void VfxAutoAnimate::initAnimateBegin()
{
    VFX_ASSERT(!s_initAnimate);
    s_initAnimate = VFX_TRUE;
}


void VfxAutoAnimate::initAnimateEnd()
{
    VFX_ASSERT(s_initAnimate);
    s_initAnimate = VFX_FALSE;
}


void VfxAutoAnimate::setAnimatableProperty(
    VfxAnimatable *animatable,
    vrt_object_property_id_enum property_id,
    const void *fromValue, 
    const void *toValue, 
    VfxU32 valueSize)
{
    VFX_DEV_ASSERT(animatable != NULL);
    VFX_DEV_ASSERT(toValue != NULL);

    VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(animatable, VfxFrame);

    // If the object is initialing and in init-animation mode, 
    //  prepare handle to apply the auto-animation
    if (animatable->isInitializing() && s_initAnimate)
    {
        if (frame != NULL && frame->isNullParent())
        {
            // The frame is not in the scene, do nothing.
            return;
        }
        
        if (vfx_sys_get_canvas_state() != VFX_SYS_STATE_ENTRY)
        {
            // VRT is not running
            return;
        }

        if (animatable->getHandle() == NULL)
        {
            animatable->processCreateHandle();
        }
    }

    vrt_object_handle object_handle = animatable->getHandle();
    if (object_handle == NULL)
    {
        // This is for timeline definition.
        //  If a timeline is stopped, set property should has effect.
        //  So we need to remove all applying timelines, 
        //  or these timelines will apply at after next commit.
        animatable->removeAllApplyingTimeline(property_id);
        return;
    }
    
    if ((animatable->getAutoAnimate() == VFX_FALSE) || 
        s_currentContext.isDisabled ||
        (animatable->isInitializing() && (s_initAnimate == VFX_FALSE)))
    {
        // If auto animation is disable, remove the property timeline if it exist
        vrt_object_remove_property_timeline(
            object_handle,
            property_id);

        if (frame == NULL)
        {
            // for 3d obj, no need to create a pulse timeline
            return;
        }
        else
        {
            // for vfxFrame, create a pulse timeline to set value to vrt
            vrt_object_add_property_timeline(
                object_handle,
                property_id,
                toValue,
                toValue,
                valueSize,
                0,
                s_currentContext.customTimingCallback);
        }
    }
    else
    {
        // If auto animation is enable, , create a from-to timeline
        vrt_object_add_property_timeline(
            object_handle,
            property_id,
            fromValue,
            toValue,
            valueSize,
            s_currentContext.durTime,
            s_currentContext.customTimingCallback);
    }
}

