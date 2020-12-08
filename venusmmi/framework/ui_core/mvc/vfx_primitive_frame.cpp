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
 *  vfx_primitive_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Primitive frame types
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vfx_primitive_frame.h"

#include "vfx_frame.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"


/***************************************************************************** 
 * Class VfxImageFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_IMAGE_FRAME_CLASS_NAME, VfxImageFrame, VfxFrame);


VfxImageFrame::VfxImageFrame() :
    m_isAutoResize(VFX_TRUE)
{
}


const VfxWString &VfxImageFrame::getPath() const
{
    return getImgContent().getPath();
}


VfxS32 VfxImageFrame::getResId() const
{
    return getImgContent().getResId();
}


void VfxImageFrame::onInit()
{
    VfxFrame::onInit();
}


void VfxImageFrame::updateSize()
{
    VfxRect bounds = getBounds();    
    bounds.size = getImgContent().getSize();
    setBounds(bounds);
}


void VfxImageFrame::setImgContent(const VfxImageSrc &value)
{
    VfxBool needUpdate = VFX_FALSE;
    
    if (m_isAutoResize && getImgContent() != value)
        needUpdate = VFX_TRUE;

    VfxFrame::setImgContent(value);

    if (needUpdate)
    {
        updateSize();
        invalidate();
    }
}


/***************************************************************************** 
 * Class VfxAnimImageFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_ANIM_IMAGE_FRAME_CLASS_NAME, VfxAnimImageFrame, VfxImageFrame);


VfxAnimImageFrame::VfxAnimImageFrame() :
    m_repeatCount(VFX_ANIM_IMAGE_FRAME_PLAY_COUNT_INFINIT),
    m_endIndex(VFX_ANIM_IMAGE_FRAME_MAX_INDEX),
    m_state(INIT),
    m_suspendIndex(VFX_ANIM_IMAGE_FRAME_MAX_INDEX)
{
}

VfxBool VfxAnimImageFrame::setRepeatCount(VfxU32 repeatCount)
{
    if (m_state == INIT)
    {
        m_repeatCount = repeatCount;

        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxU32 VfxAnimImageFrame::getRepeatCount() const
{
    return m_repeatCount;
}


void VfxAnimImageFrame::setEndIndex(VfxU32 endIndex)
{
    m_endIndex = endIndex;
}


VfxU32 VfxAnimImageFrame::getEndIndex() const
{
    if (m_endIndex == VFX_ANIM_IMAGE_FRAME_MAX_INDEX)
    {
        // TODO: Get the animation image frame count
    }

    return m_endIndex;
}


void VfxAnimImageFrame::play()
{
    if (m_state == PLAYING) 
    {
        stop();
    }

    if (m_state == SUSPENDED)
    {
        resume();
        return;
    }
    
    vrt_frame_play_img_content_struct playImgStruct;
    
    playImgStruct.play_counts  = m_repeatCount;
    playImgStruct.end_callback = vrtPlayEndCallbackHelper;
    playImgStruct.user_data    = (vrt_u8 *)getObjHandle();

    vrt_frame_play_img_content(m_handle, &playImgStruct);

    m_state = PLAYING;

    setCacheMode(VFX_CACHE_MODE_FORCE);

    updateControlData();
}


void VfxAnimImageFrame::stop()
{
    if (m_state == INIT) 
    {
        return;
    }
    
    vrt_frame_play_img_content(m_handle, NULL);
        
    m_state = INIT;

    setCacheMode(VFX_CACHE_MODE_AUTO);

    setPropertyMonitorCallback(NULL, NULL, 0);
}


void VfxAnimImageFrame::suspend(VfxU32 suspendAtIndex)
{
    if (m_state == SUSPENDED) 
    {
        return;
    }
    
    if (m_state == PLAYING) 
    {
        m_suspendIndex = suspendAtIndex;
        
        m_state = SUSPENDED;

        updateControlData();
    }
}


void VfxAnimImageFrame::resume()
{
    if (m_state == PLAYING) 
    {
        return;
    }
    
    if (m_state == SUSPENDED) 
    {
        m_state = PLAYING;

        updateControlData();
    }
}


void VfxAnimImageFrame::playAndSuspend(VfxU32 suspendAtIndex)
{
    play();
    suspend(suspendAtIndex);
}



void VfxAnimImageFrame::vrtPlayEndCallbackHelper(void *userdata)
{
    VFX_DEV_ASSERT(userdata != NULL);

    VfxAnimImageFrame *frame = (VfxAnimImageFrame*)VfxObject::handleToObject((VfxObjHandle) userdata);
    
    if (frame == NULL)
    {
        return;
    }

    vfxPostInvoke0(frame, &VfxAnimImageFrame::playEndCallback);
}


void VfxAnimImageFrame::playEndCallback()
{
    m_signalEnd.postEmit(this);
}


vrt_frame_property_monitor_type_enum VfxAnimImageFrame::vrtFramePropertyMonitorCallback(
            vrt_frame_property_handle target_frame, void *user_data, vrt_u32 user_data_size)
{
    if (!user_data || user_data_size != sizeof(anim_control_data_struct))
    {
        return VRT_FPM_TYPE_NONE;
    }
    
    vrt_animation_image_status_struct *anim = vrt_canvas_get_animation_image_status(target_frame);

    if (!anim)
    {
       return VRT_FPM_TYPE_NONE;
    }

    anim_control_data_struct *controlData = (anim_control_data_struct *)user_data;
    vrt_frame_property_monitor_type_enum ret = VRT_FPM_TYPE_NONE;

    if (anim->user_data == 0xFFFFFFFF)
    {
        anim->user_data = (vrt_u32)INIT;
    }

    anim_state_enum state = (anim_state_enum)anim->user_data;

    switch (state)
    {
    case INIT:
        ret = vrtProcessInitState(controlData, anim);
        break;

    case PLAYING:
        ret = vrtProcessPlayingState(controlData, anim);
        break;

    case SUSPENDED:
        ret = vrtProcessSuspendedState(controlData, anim);
        break;

    default:
        VFX_ASSERT(0);
        break;
    }

    return ret;
}


VfxBool VfxAnimImageFrame::vrtExecuteAnimationImage(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim)
{
    vrt_msec_type cur_time;

    cur_time = vrt_get_current_frame_time();

    if (cur_time >= anim->last_draw_time + anim->delay)
    {
        anim->current_index++;

        if ((anim->count && (anim->current_index >= anim->count)) ||
            anim->current_index > controlData->endIndex)
        {
            if (anim->loop_count)
            {
                anim->loop_count--;
                anim->current_index = 0;
            }
        }

        if (anim->loop_count)
        {
            anim->last_draw_time = cur_time;

            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


vrt_frame_property_monitor_type_enum VfxAnimImageFrame::vrtProcessInitState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim)
{
    vrt_frame_property_monitor_type_enum ret = VRT_FPM_TYPE_NONE;

    //vrt_msec_type cur_time;

    //cur_time = vrt_get_current_frame_time();
    
    switch (controlData->state)
    {
    case INIT:
        break;

    case PLAYING:
        
        anim->user_data = (vrt_u32)PLAYING;
        
        if (vrtExecuteAnimationImage(controlData, anim))
        {
            ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY;
        }
        
        break;

    case SUSPENDED:
        if (controlData->suspendIndex == VFX_ANIM_IMAGE_FRAME_MAX_INDEX)
        {
            anim->user_data = (vrt_u32)SUSPENDED;
        }
        else
        {
            anim->user_data = (vrt_u32)PLAYING;
            
            if (vrtExecuteAnimationImage(controlData, anim))
            {
                if (anim->current_index == controlData->suspendIndex)
                {
                    anim->user_data = (vrt_u32)SUSPENDED;
                    ret = VRT_FPM_TYPE_CONTENT_DIRTY;
                }
                else
                {
                    ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY;
                }
            }
            else if (anim->current_index == controlData->suspendIndex)
            {
                anim->user_data = (vrt_u32)SUSPENDED;
            }
        }
        break;

    default:
        VFX_ASSERT(0);
        break;
    }

    return ret;
}


vrt_frame_property_monitor_type_enum VfxAnimImageFrame::vrtProcessPlayingState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim)
{
    vrt_frame_property_monitor_type_enum ret = VRT_FPM_TYPE_NONE;
    
    switch (controlData->state)
    {
    case INIT:
        /* Stop is handled by vrt render, it will remove the animation before excuting FPM callback */
        break;

    case PLAYING:
        if (vrtExecuteAnimationImage(controlData, anim))
        {
            ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY;
        }
        break;

    case SUSPENDED:
        if (controlData->suspendIndex == VFX_ANIM_IMAGE_FRAME_MAX_INDEX)
        {
            anim->user_data = (vrt_u32)SUSPENDED;
        }
        else
        {
            if (vrtExecuteAnimationImage(controlData, anim))
            {
                if (anim->current_index == controlData->suspendIndex)
                {
                    anim->user_data = (vrt_u32)SUSPENDED;
                    ret = VRT_FPM_TYPE_CONTENT_DIRTY;
                }
                else
                {
                    ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY;
                }
            }
            else if (anim->current_index == controlData->suspendIndex)
            {
                anim->user_data = (vrt_u32)SUSPENDED;
            }
        }
        break;

    default:
        VFX_ASSERT(0);
        break;
    }

    return ret;
}


vrt_frame_property_monitor_type_enum VfxAnimImageFrame::vrtProcessSuspendedState(anim_control_data_struct *controlData, vrt_animation_image_status_struct *anim)
{
    vrt_frame_property_monitor_type_enum ret = VRT_FPM_TYPE_NONE;
    
    switch (controlData->state)
    {
    case INIT:
        /* Stop is handled by vrt render, it will remove the animation before excuting FPM callback */
        break;

    case PLAYING:
        anim->user_data = (vrt_u32)PLAYING;
        
        if (vrtExecuteAnimationImage(controlData, anim))
        {
            ret = VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY;
        }
        break;

    case SUSPENDED:
        break;

    default:
        VFX_ASSERT(0);
        break;
    }

    return ret;
}


void VfxAnimImageFrame::processCreateHandle()
{
    VfxImageFrame::processCreateHandle();

    if (m_state != INIT)
    {
        vrt_frame_play_img_content_struct playImgStruct;
    
        playImgStruct.play_counts  = m_repeatCount;
        playImgStruct.end_callback = vrtPlayEndCallbackHelper;
        playImgStruct.user_data    = (vrt_u8 *)getObjHandle();

        vrt_frame_play_img_content(m_handle, &playImgStruct);
    }
}


void VfxAnimImageFrame::setImgContent(const VfxImageSrc &value)
{
    if (getImgContent() != value)
    {
        stop();
    }

    VfxImageFrame::setImgContent(value);
}



void VfxAnimImageFrame::updateControlData()
{
    anim_control_data_struct controlData;

    controlData.endIndex = m_endIndex;
    controlData.repeatCount = m_repeatCount;
    controlData.suspendIndex = m_suspendIndex;
    controlData.state = m_state;

    setPropertyMonitorCallback(vrtFramePropertyMonitorCallback, &controlData, sizeof(anim_control_data_struct));
}



