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
 *  vfx_renderer.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Engine Renderer
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vfx_renderer.h"

#include "vfx_timer.h"
#include "vfx_draw_context.h"
#include "vfx_frame.h"
#include "vfx_animation.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"
#include "vfx_system.h"
#include "vfx_object_list.h"
#include "vrt_system.h"

#include "vadp_sys_trc.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_material.h"
#include "vfx_world.h"
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_RENDERER_COMMIT_MAX_DUR     500


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


/***************************************************************************** 
 * Global function
 *****************************************************************************/

extern "C" void vrt_get_time(vrt_u32 *t);
extern "C" vrt_u32 vrt_get_duration_ms(vrt_u32 start_time, vrt_u32 end_time);


/***************************************************************************** 
 * Class VfxRendererProfiling
 *****************************************************************************/

VfxBool VfxRendererProfiling::s_hasDebugPanelUpdate = VFX_FALSE;
VfxBool VfxRendererProfiling::s_hasPlutoControl = VFX_FALSE;
VfxRendererProfilingData VfxRendererProfiling::s_data[VfxRendererProfiling::DATA_MAX_COUNT];
VfxU32 VfxRendererProfiling::s_dataCount = 0;

void VfxRendererProfiling::setHasDebugPanelUpdate()
{
    if (s_dataCount >= DATA_MAX_COUNT)
    {
        return;
    }

    s_hasDebugPanelUpdate = VFX_TRUE;
}


void VfxRendererProfiling::setHasPlutoControl()
{
    if (s_dataCount >= DATA_MAX_COUNT)
    {
        return;
    }

    s_hasPlutoControl = VFX_TRUE;
}


void VfxRendererProfiling::reset()
{
    s_dataCount = 0;
}


void VfxRendererProfiling::addData(const VfxRendererProfilingData &data)
{
    if (s_dataCount >= DATA_MAX_COUNT)
    {
        return;
    }

    s_data[s_dataCount] = data;
    s_data[s_dataCount].hasDebugPanelUpdate = s_hasDebugPanelUpdate;
    s_data[s_dataCount].hasPlutoControl = s_hasPlutoControl;
    s_dataCount++;

    s_hasDebugPanelUpdate = VFX_FALSE;
    s_hasPlutoControl = VFX_FALSE;
}


VfxU32 VfxRendererProfiling::getCount()
{
    return s_dataCount;
}


const VfxRendererProfilingData &VfxRendererProfiling::getData(VfxU32 index)
{
    VFX_DEV_ASSERT(index < DATA_MAX_COUNT);
    return s_data[index];
}


/***************************************************************************** 
 * Class VfxRenderer
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_RENDERER_CLASS_NAME, VfxRenderer, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxRenderer);


VfxRenderer::VfxRenderer() :
    m_state(VFX_RENDERER_STATE_UNKNOWN),
    m_isSuspendUntilCommit(VFX_FALSE),
    m_isSuspendByRenderer(VFX_FALSE),
    m_rootFramePtr(NULL),
    m_mustShowNextFrame(VFX_FALSE),
    m_waitDrawFinishNextFrame(VFX_FALSE),
    m_blockAfterNextCommitTime(0),
    m_mustShowTime(0),
    m_mustShowTimeEnabled(VFX_FALSE),
    m_mustShowAbsTime(0),
    m_preCommitTime(0)
{
#ifndef __MTK_TARGET__
    debugDumpFrameDummy();
#endif
}


void VfxRenderer::setRootFrame(VfxFrame *frame)
{
    VfxFrame *rootFrame = m_rootFramePtr.get();
    if (rootFrame == frame)
    {
        // The given frame is already the root frame, do nothing.
        return;
    }

    // Does not release VRT handles here,
    //  because the root frame may change back soon.
    //  It will automatically release in VfxRenderer::shutdown().
    m_rootFramePtr = NULL;

    if (frame != NULL)
    {
        VFX_OBJ_ASSERT_VALID(frame);        
        m_rootFramePtr = frame;
        m_rootFramePtr->invalidate();

        // Does not create VRT handles here,
        //  because the Canvas Engine may not be ready.
        //  It will automatically create in VfxRenderer::updateScene().
    }
}


void VfxRenderer::pushRootFrame(VfxFrame *frame)
{
    VFX_ASSERT(frame != NULL);
    VFX_ASSERT(m_stackFramePtr == NULL);

    m_stackFramePtr = m_rootFramePtr;
    setRootFrame(frame);
}


void VfxRenderer::popRootFrame()
{
    VfxFrame *rootFrame = m_stackFramePtr.get();
    
    m_stackFramePtr = NULL;
    setRootFrame(rootFrame);
}


void VfxRenderer::pauseAllImgAnim(VfxObject *requester)
{
    VFX_OBJ_ASSERT_VALID(requester);

    if (m_pauseAllImgAnimRequesters.contains(requester))
    {
        // The requester has paused image animation,
        //  do nothing.
        return;
    }

    if (m_pauseAllImgAnimRequesters.isEmpty())
    {
        // The requester is the first one to pause
        vrt_canvas_pause_img_anim();
    }

    m_pauseAllImgAnimRequesters.append(requester);
}


void VfxRenderer::resumeAllImgAnim(VfxObject *requester)
{
    VFX_OBJ_ASSERT_VALID(requester);

    if (!m_pauseAllImgAnimRequesters.removeOne(requester))
    {
        // The requester is not exist, do nothing
        return;
    }

    if (!m_pauseAllImgAnimRequesters.isEmpty())
    {
        // There are some requesters to pause image animation,
        //  do not resume.
        return;
    }
    
    vrt_canvas_resume_img_anim();
}


void VfxRenderer::mustShowNextFrame()
{
    m_mustShowNextFrame = VFX_TRUE;
}


void VfxRenderer::waitDrawFinishNextFrame()
{
    m_waitDrawFinishNextFrame = VFX_TRUE;
}


void VfxRenderer::blockAfterNextCommit(VfxMsec waitTime, VfxCallback0 callback)
{
    if (waitTime > m_blockAfterNextCommitTime)
    {
        m_blockAfterNextCommitTime = waitTime;
    }

    if (callback.m_objPtr != NULL && callback.m_callback != NULL)
    {
        m_blockAfterNextCommitCallbackList.appendSlot(callback.m_objPtr.get(), callback.m_callback);
    }
}


void VfxRenderer::removeBlockAfterNextCommitCallback(VfxCallback0 callback)
{
    if (callback.m_objPtr != NULL && callback.m_callback != NULL)
    {
        m_blockAfterNextCommitCallbackList.removeSlot(callback.m_objPtr.get(), callback.m_callback);
    }
}


void VfxRenderer::mustShowTime(VfxMsec relTime)
{
    if (relTime > m_mustShowTime)
    {
        m_mustShowTime = relTime;
    }
}


void VfxRenderer::startup()
{
    VFX_LOG(VFX_INFO, VFX_RENDERER_STARTUP);

    m_state = VFX_RENDERER_STATE_STARTUP;

    // Need blocking for first frame
    m_isSuspendByRenderer = VFX_FALSE;
    m_mustShowNextFrame = VFX_TRUE;
    m_waitDrawFinishNextFrame = VFX_TRUE;
    
    m_blockAfterNextCommitTime = 0;
    m_mustShowTimeEnabled = VFX_FALSE;
}


void VfxRenderer::shutdown()
{
    VFX_LOG(VFX_INFO, VFX_RENDERER_STUTDOWN);

    // dispose all VRT handles
    VfxObjListEntry *i;
    for (i = m_nullParentFrameList.getHead();
        i != NULL;
        i = i->getNext())
    {
        VfxFrame *frame = (VfxFrame *)i->get();

        // Because it will remove from null parent list when a frame is closed
        VFX_DEV_ASSERT(frame != NULL);
        
        frame->disposeHandle();
    }

    m_state = VFX_RENDERER_STATE_SHUTDOWN;
}


void VfxRenderer::beforeSleepIn()
{
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_UNKNOWN)
    {
        return;
    }

    m_signalBacklightSwitch2.emit(VFX_FALSE);
}


void VfxRenderer::afterSleepIn()
{
    setBacklightState(VFX_FALSE);
}


void VfxRenderer::beforeSleepOut()
{
    setBacklightState(VFX_TRUE);
}


void VfxRenderer::afterSleepOut()
{
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_UNKNOWN)
    {
        return;
    }

    m_signalBacklightSwitch2.emit(VFX_TRUE);
}


void VfxRenderer::addToNullParentFrameList(VfxFrame *frame)
{
    VFX_DEV_ASSERT(frame != NULL);

    if (frame->m_nullParentListEntry != NULL)
    {
        // Already in the null list, do nothing
        return;
    }

    frame->m_nullParentListEntry = m_nullParentFrameList.append(frame);
}


void VfxRenderer::removeFromNullParentFrameList(VfxFrame *frame)
{
    VFX_DEV_ASSERT(frame != NULL);
    
    if (frame->m_nullParentListEntry == NULL)
    {
        // Not in the null list, do nothing
        return;
    }
    
    m_nullParentFrameList.removePos(frame->m_nullParentListEntry);
    frame->m_nullParentListEntry = NULL;
}


void VfxRenderer::setBacklightState(VfxBool on)
{
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_UNKNOWN)
    {
        return;
    }

    m_signalBacklightSwitch.emit(on);
}


void VfxRenderer::suspendUntilCommit()
{    
    VFX_LOG(VFX_INFO, VFX_RENDERER_SUSPEND_UNTIL_COMMIT);

    if (m_isSuspendUntilCommit)
    {
        // Already suspend, do nothing
        return;
    }

    m_isSuspendUntilCommit = VFX_TRUE;

    if (vrt_canvas_get_state() != VRT_CANVAS_STATE_OPERATE)
    {
        // VRT not running, no need to suspend
        return;
    }
    
    vrt_canvas_suspend();
    m_isSuspendByRenderer = VFX_TRUE;
}


VfxBool VfxRenderer::needCommitSoon() const
{
    VfxMsec currTime = VfxTimer::getCurrentSystemTime();
    VfxS32 diff = (currTime - m_preCommitTime);
    
    return m_mustShowNextFrame || m_blockAfterNextCommitTime > 0 || diff > VFX_RENDERER_COMMIT_MAX_DUR;
}


void VfxRenderer::waitForRenderingComplete()
{
    vrt_canvas_wait_rendering_complete();
}


VfxScrRotateTypeEnum VfxRenderer::getScreenRotateType() const
{
    return (VfxScrRotateTypeEnum)vrt_sys_get_screen_rotation();
}


VfxScrRotateTypeEnum VfxRenderer::getPreScreenRotateType() const
{
    return (VfxScrRotateTypeEnum)vrt_sys_get_pre_screen_rotation();
}


void VfxRenderer::setScreenRotateType(VfxScrRotateTypeEnum type)
{
    VFX_ASSERT(type < VFX_SCR_ROTATE_TYPE_END_OF_ENUM);

    VfxScrRotateTypeEnum origType = getScreenRotateType();
    if (origType == type)
    {
        // Do nothing;
        return;
    }

    suspendUntilCommit();
    
    vrt_sys_set_screen_rotation((vrt_sys_screen_rotate_enum)type);
}


VfxBool VfxRenderer::snapshot(VfxImageBuffer &snapshotBuffer)
{
    if (vfx_sys_get_canvas_state() != VFX_SYS_STATE_ENTRY)
    {
        return VFX_FALSE;
    }

    vrt_image_buffer_struct vrtImageBuf;

    snapshotBuffer.initVrtImageBuffer(vrtImageBuf);

    return vrt_canvas_snapshot(&vrtImageBuf) ? VFX_TRUE : VFX_FALSE;
}


VfxMsec VfxRenderer::updateScene(VfxBool commitToVrt, VfxRendererCommitActionEnum commitAction)
{
    // NOTES:
    // The method should be very light if nothing to do.
    //
    // This method should not emit any send signal,
    //  because the renderer may be shutdown.

    if (m_state == VFX_RENDERER_STATE_COMMIT)
    {
        // Avoid recursive update scene
        return VfxTimer::getCurrentTime();
    }

    VFX_LOG(VFX_INFO2, VFX_MMI_UPDATE_SCENE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XUS", SA_start);
#endif
    VfxRendererProfilingData profilingData;
    vrt_u32 commitStart;
    vrt_get_time(&commitStart);

    // Update State
    VfxRendererStateEnum oldState = m_state;
    m_state = VFX_RENDERER_STATE_COMMIT;
    
    VfxAnimatable::finishInitialingFrameList();

    VfxBool sceneChanged = VFX_FALSE;
    
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_ENTRY && commitToVrt)
    {
        VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_BEGIN);

        VfxFrame *stackFrame = m_stackFramePtr.get();
        VfxFrame *rootFrame = m_rootFramePtr.get();

        // Prepare handle stage
        if (rootFrame != NULL)
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MPH", SA_start);
#endif
            vrt_u32 prepareHandleStart;
            vrt_get_time(&prepareHandleStart);

            sceneChanged = rootFrame->prepareHandle();
            if (stackFrame != NULL && sceneChanged)
            {
                stackFrame->prepareHandle();
            }
            
            vrt_u32 prepareHandleEnd;
            vrt_get_time(&prepareHandleEnd);
            profilingData.prepareHandleTime = vrt_get_duration_ms(prepareHandleStart, prepareHandleEnd);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MPH", SA_stop);
#endif
        }

        // Prepare new scene graph (Draw context) if needed
        if (sceneChanged)
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MSC", SA_start);
#endif
            VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_DRAW_FRAME_BEGIN);
            vrt_u32 prepareSceneGraphStart;
            vrt_get_time(&prepareSceneGraphStart);

            // Guarantee the call stack is good before drawDraw() recursive call
            VFX_CHECK_CALL_STACK();
            
            vrt_canvas_begin();

            VfxDrawContext dc;
            drawRootFrame(dc);

            vrt_canvas_end();

            // NOTE: Test if the drawDrame() recursive call causes stack overflow
            VFX_CHECK_CALL_STACK();

            vrt_u32 prepareSceneGraphEnd;
            vrt_get_time(&prepareSceneGraphEnd);
            profilingData.prepareSceneGraphTime = vrt_get_duration_ms(prepareSceneGraphStart, prepareSceneGraphEnd);
            VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_DRAW_FRAME_END);            
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MSC", SA_stop);
#endif
        }
    }

    // Get previous commit time
    m_preCommitTime = VfxTimer::getCurrentSystemTime();
    
    // Get current time here, 
    //  because we only want to get the time just commiting
    VfxMsec currentTime = VfxTimer::getCurrentTime();

    vrt_bool isCommit = VRT_FALSE;
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_ENTRY && commitToVrt)
    {
        vrt_frame_commit_action_enum action;
        if (commitAction == VFX_RENDERER_COMMIT_ACTION_FORCE_SUSPEND)
        {
            action = VRT_FRAME_COMMIT_ACTION_FORCE_SUSPEND;
        }
        else if (commitAction == VFX_RENDERER_COMMIT_ACTION_FORCE_RESUME)
        {
            action = VRT_FRAME_COMMIT_ACTION_FORCE_RESUME;
        }
        else if (m_isSuspendByRenderer)
        {
            action = VRT_FRAME_COMMIT_ACTION_FORCE_RESUME;
        }
        else
        {
            action = VRT_FRAME_COMMIT_ACTION_KEEP;
        }

        // if m_blockAfterNextCommitTime != 0, it will block MMI just later.
        //  Doesn't need to block at this time.
        vrt_frame_commit_block_type_enum blockType;
        if (m_blockAfterNextCommitTime != 0)
        {
            blockType = VRT_FRAME_COMMIT_BLOCK_TYPE_NONE;
        }
        else if (commitAction != VFX_RENDERER_COMMIT_ACTION_KEEP)
        {
            blockType = VRT_FRAME_COMMIT_BLOCK_TYPE_RENDER_END;
        }
        else if (m_mustShowNextFrame)
        {
            blockType = VRT_FRAME_COMMIT_BLOCK_TYPE_RENDER_START;
        }
        else
        {
            blockType = VRT_FRAME_COMMIT_BLOCK_TYPE_NONE;
        }

        // Commit all VRT objects and Scene Graph
        VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_COMMIT_BEGIN);
        vrt_frame_commit_beign(currentTime, (vrt_bool)sceneChanged, action, blockType);
        // Here the VRT is suspended
        isCommit = vrt_frame_commit_end();
        VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_COMMIT_END);
        VFX_LOG(VFX_INFO3, VFX_RENDERER_UPDATE_SCENE_END, 0);
        
        profilingData.isBlocking = (blockType != VRT_FRAME_COMMIT_BLOCK_TYPE_NONE);
    }

    // Update important time
    if (m_mustShowTime > 0)
    {
        VfxMsec importantAbsTime = currentTime + m_mustShowTime;

        if (!m_mustShowTimeEnabled)
        {
            m_mustShowTimeEnabled = VFX_TRUE;
            m_mustShowAbsTime = importantAbsTime;
        }
        else if(vfxMsecDiff(importantAbsTime, m_mustShowAbsTime) > 0)
        {
            m_mustShowAbsTime = importantAbsTime;
        }

        m_mustShowTime = 0;
    }

    m_state = oldState;
    m_isSuspendUntilCommit = VFX_FALSE;
    m_isSuspendByRenderer = VFX_FALSE;
    m_mustShowNextFrame = VFX_FALSE;
    m_waitDrawFinishNextFrame = VFX_FALSE;

    vrt_u32 commitEnd;
    vrt_get_time(&commitEnd);
    profilingData.commitTime = vrt_get_duration_ms(commitStart, commitEnd);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XUS", SA_stop);
#endif

    if (isCommit)
    {
        VfxRendererProfiling::addData(profilingData);
    }

    return currentTime;
}


void VfxRenderer::processBlockNextCommit(VfxMsec currentTime)
{
    if (m_blockAfterNextCommitTime > 0)
    {
        VfxTimer::blockUntil(currentTime + m_blockAfterNextCommitTime);
        m_blockAfterNextCommitTime = 0;
    }

    VfxSlotList callbackList(m_blockAfterNextCommitCallbackList);
    m_blockAfterNextCommitCallbackList.clear();

    VfxSlotList::SlotListEntry *i;
    for (i = callbackList.getHead(); i != NULL; i = i->m_next)
    {
        if (!i->m_slot.isValid())
        {
            continue;
        }

        VfxCallback0 callback(i->m_slot.m_objPtr.get(), i->m_slot.m_callback);
        callback.invoke();        
    }
}


void VfxRenderer::processMustShowTime()
{
    // Because the VRT is not running at this time,
    //  so the timer is not running. we can not block at this time.
    if (m_isSuspendUntilCommit)
    {
        m_mustShowTimeEnabled = VFX_FALSE;
        return;
    }
    
    if (m_mustShowTimeEnabled)
    {
        VfxTimer::blockUntil(m_mustShowAbsTime);
        m_mustShowTimeEnabled = VFX_FALSE;
    }
}


void VfxRenderer::drawRootFrame(VfxDrawContext &dc)
{
    VfxFrame *rootFrame = m_rootFramePtr.get();
    if (rootFrame == NULL || rootFrame->getHidden())
    {
        return;
    }
    
    dc.pushAndSetActiveFrame(rootFrame);

    // Draw the content of the frame
    rootFrame->processDraw(dc);

    VfxFrame *stackFrame = m_stackFramePtr.get();
    if (stackFrame != NULL)
    {
        drawFrame(dc, stackFrame);
    }

    VfxFrame *i;
    for (i = rootFrame->getFirstChildFrame(); i != NULL; i = i->getNextFrame())
    {
        drawFrame(dc, i);
    }

    dc.popAndRestoreFrame();
}


void VfxRenderer::drawFrame(VfxDrawContext &dc, VfxFrame *frame)
{
    VFX_DEV_ASSERT(frame != NULL);
    
    // Do nothing if invisible
    if (frame->getHidden())
    {
        return;
    }

    if (frame->hasChildDirty() && !frame->isNeedUpdate())
    {  
        dc.pushAndSetActiveFrame(frame);   
        vrt_canvas_copy_draw_cmds(frame->getHandle());    
        frame->clearHasChildDirtyFlag();             
    } 
    else if (!frame->isNeedUpdate())
    {
        vrt_canvas_copy_subtree(frame->getHandle());
        return;
    }
    else
    {
    	dc.pushAndSetActiveFrame(frame);
    	frame->processDraw(dc);
    }

    VfxFrame *i;
    for (i = frame->getFirstChildFrame(); i != NULL; i = i->getNextFrame())
    {
        drawFrame(dc, i);
    }

    dc.popAndRestoreFrame();
}


vrt_allocator_handle VfxRenderer::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}

