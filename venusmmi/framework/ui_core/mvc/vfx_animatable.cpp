/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vfx_animatable.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_animatable.h"
#include "vfx_animation.h"
#include "vfx_class_info.h"
// For VfxRenderer
#include "vfx_renderer.h"
// For close Timers
#include "vfx_timer.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VfxAnimatableCustomVar
 *****************************************************************************/

VfxAnimatableCustomVar::VfxAnimatableCustomVar(vrt_type_id_enum typeId, vrt_allocator_handle allocator) :
    m_typeId(typeId),
    m_data(NULL)
{
    const VfxChar *filename;
    VfxU32 line;
    vrt_u32 dataSize = vrt_get_size_of_type(typeId);
    VFX_DEV_ASSERT(allocator != NULL);

    VFX_MEM_FILL_FILENAME(filename, line);
    m_data = vrt_allocator_alloc_int(allocator, dataSize, 0, filename, line);
    memset(m_data, 0, dataSize);
}


VfxAnimatableCustomVar::~VfxAnimatableCustomVar()
{
    // TODO: VRT maybe is using m_data. Need new mechanism to void de-performance
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit();

    vrt_allocator_free(m_data);    
}


/***************************************************************************** 
 * Class VfxAnimatable
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("Animatable", VfxAnimatable, VfxObject);

VfxAnimatable *VfxAnimatable::s_initFrameListHead = NULL;
VfxAnimatable *VfxAnimatable::s_initFrameListTail = NULL;


VfxAnimatable::VfxAnimatable() :
    m_handle(NULL),
    m_enabledTimelineListHead(NULL),
    m_enabledTimelineListTail(NULL),
    m_animatableFlags(0)
{
    m_initframelink.prev = NULL;
    m_initframelink.next = NULL;
}


void VfxAnimatable::onInit()
{
    VfxObject::onInit();

    // Insert to initial frame list
    if (s_initFrameListHead == NULL)
    {
        s_initFrameListHead = this;
    }
    if (s_initFrameListTail != NULL)
    {
        s_initFrameListTail->setNextInitFrame(this);
        setPrevInitFrame(s_initFrameListTail);
    }
    s_initFrameListTail = this;  

    m_customVariableList.init(this);
}


void VfxAnimatable::onDeinit()
{
    // Remove from initial frame list if needed
    if (isInitializing())
    {
        //
        // NOTE: Assert here if some object forget to call its super class onInit()
        //
        VFX_DEV_ASSERT(s_initFrameListHead != NULL);
        VFX_DEV_ASSERT(s_initFrameListTail != NULL);

        if (getInitFrame().prev == NULL)
        {
            s_initFrameListHead = getInitFrame().next;
        }
        else
        {
            getInitFrame().prev->setNextInitFrame(getInitFrame().next);
        }

        if (getInitFrame().next == NULL)
        {
            s_initFrameListTail = getInitFrame().prev;
        }
        else
        {
            getInitFrame().next->setPrevInitFrame(getInitFrame().prev);
        }

        resetInitFrame();
    }
    
    // dispose all enabled timelines
    removeAllTimeline();
    //removeAllCustomVariable();

    VfxObject::onDeinit();
}


void VfxAnimatable::processCreateHandle()
{
}


void VfxAnimatable::processReleaseHandle()
{
}


void VfxAnimatable::onAddTimeline()
{
}


void VfxAnimatable::onRemoveTimeline()
{
}


void VfxAnimatable::prepareAnimationHandle() const
{
    prepareAllTimeline();
}


void VfxAnimatable::disposeAnimationHandle() const
{
    disposeAllTimeline();
}


void VfxAnimatable::addTimeline(VfxBaseTimeline *timeline)
{
    VFX_OBJ_ASSERT_VALID(timeline);
    
    VFX_DEV_ASSERT(timeline->m_enabledTimelineEntryPrev == NULL);
    VFX_DEV_ASSERT(timeline->m_enabledTimelineEntryNext == NULL);

    if (m_enabledTimelineListHead == NULL)
    {
        m_enabledTimelineListHead = timeline;
    }

    timeline->m_enabledTimelineEntryNext = NULL;
    timeline->m_enabledTimelineEntryPrev = m_enabledTimelineListTail;
    if (m_enabledTimelineListTail != NULL)
    {
        m_enabledTimelineListTail->m_enabledTimelineEntryNext = timeline;
    }
    m_enabledTimelineListTail = timeline;

    // Settings
    timeline->m_enabledObject = this;

//    onAddTimeline();
    onObjectNotify(VFX_ANIMATABLE_NOTIFY_ID_ADD_TIMELINE, NULL);
}


void VfxAnimatable::removeTimeline(VfxBaseTimeline *timeline)
{
    VFX_OBJ_ASSERT_VALID(timeline);
    VFX_DEV_ASSERT(timeline->m_enabledObject == this);

//    onRemoveTimeline();
    onObjectNotify(VFX_ANIMATABLE_NOTIFY_ID_REMOVE_TIMELINE, NULL);

    if (timeline->m_enabledTimelineEntryPrev != NULL)
    {
        timeline->m_enabledTimelineEntryPrev->m_enabledTimelineEntryNext = 
            timeline->m_enabledTimelineEntryNext;
    }
    else
    {
        VFX_DEV_ASSERT(m_enabledTimelineListHead == timeline);
        m_enabledTimelineListHead = 
            timeline->m_enabledTimelineEntryNext;
    }

    if (timeline->m_enabledTimelineEntryNext != NULL)
    {
        timeline->m_enabledTimelineEntryNext->m_enabledTimelineEntryPrev = 
            timeline->m_enabledTimelineEntryPrev;
    }
    else
    {
        VFX_ASSERT(m_enabledTimelineListTail == timeline);
        m_enabledTimelineListTail = 
            timeline->m_enabledTimelineEntryPrev;
    }

    timeline->m_enabledTimelineEntryPrev = NULL;
    timeline->m_enabledTimelineEntryNext = NULL;
    timeline->m_enabledObject = NULL;
    
    timeline->disposeHandle();
}


void VfxAnimatable::prepareAllTimeline() const
{
    // prepare all enabled timelines
    VfxBaseTimeline *timeline;
    for (timeline = m_enabledTimelineListHead;
        timeline != NULL;
        timeline = timeline->m_enabledTimelineEntryNext)
    {
        timeline->prepareHandle();
    }
}


void VfxAnimatable::disposeAllTimeline() const
{
    // dispose all enabled timelines
    VfxBaseTimeline *timeline;
    for (timeline = m_enabledTimelineListTail;
        timeline != NULL;
        timeline = timeline->m_enabledTimelineEntryPrev)
    {
        timeline->disposeHandle();
    }
}


void VfxAnimatable::removeAllTimeline()
{
    VfxBaseTimeline *timeline = m_enabledTimelineListHead;
    while (timeline != NULL)
    {
        VfxBaseTimeline *nextTimeline = timeline->m_enabledTimelineEntryNext;

        timeline->m_enabledTimelineEntryPrev = NULL;
        timeline->m_enabledTimelineEntryNext = NULL;        
        timeline->m_enabledObject = NULL;
        
        timeline->disposeHandle();
        
        timeline = nextTimeline;
    }

    m_enabledTimelineListHead = NULL;
    m_enabledTimelineListTail = NULL;
}


void VfxAnimatable::removeAllApplyingTimeline(vrt_object_property_id_enum targetPropertyId)
{
    VfxBaseTimeline *timeline = m_enabledTimelineListHead;
    while (timeline != NULL)
    {
        VfxBaseTimeline *nextTimeline = timeline->m_enabledTimelineEntryNext;
        if (timeline->m_timelineState == VFX_TIMELINE_STATE_APPLYING &&
            timeline->getTargetPropertyId() == targetPropertyId)
        {
            VFX_OBJ_CLOSE(timeline->m_stopTimer);
            VFX_OBJ_CLOSE(timeline->m_startTimer);
            removeTimeline(timeline);
            timeline->m_timelineState = VFX_TIMELINE_STATE_STOP;            
        }
        
        timeline = nextTimeline;
    }
}


VfxAnimatableCustomVar *VfxAnimatable::addCustomVariable(vrt_type_id_enum typeId, vrt_allocator_handle allocator)
{
    VfxAnimatableCustomVar *var;
    VFX_ALLOC_NEW_EX(var, VfxAnimatableCustomVar, this, (typeId, allocator));
    
    m_customVariableList.pushBack(var);

    return var;
}


void VfxAnimatable::removeCustomVariable(VfxAnimatableCustomVar *var)
{
    VFX_ASSERT(var != NULL);
    
    m_customVariableList.remove(var);

    VFX_DELETE(var);
}


void VfxAnimatable::removeAllCustomVariable()
{
    if (m_customVariableList.empty())
    {
        return;
    }

    VfxList <VfxAnimatableCustomVar *>::It i;
    for (i = m_customVariableList.begin(); !i.isNull(); ++i)
    {
        VfxAnimatableCustomVar *var = *i;
        VFX_DELETE(var);
    }

    m_customVariableList.clear();
}


void VfxAnimatable::setAutoAnimate(VfxBool value)
{
    value ? 
        VFX_FLAG_SET(m_animatableFlags, FLAGS_AUTO_ANIMATE) :
        VFX_FLAG_CLEAR(m_animatableFlags, FLAGS_AUTO_ANIMATE);
}


VfxBool VfxAnimatable::getAutoAnimate() const
{
    return VFX_FLAG_HAS(m_animatableFlags, FLAGS_AUTO_ANIMATE);
}


void VfxAnimatable::finishInitialingFrameList()
{
    VfxAnimatable *frame = s_initFrameListHead;
    if (frame == NULL)
    {
        VFX_DEV_ASSERT(s_initFrameListTail == NULL);
        // Do nothing if emptry
        return;
    }
    
    VFX_DEV_ASSERT(s_initFrameListTail != NULL);

    while (frame != NULL)
    {
        VfxAnimatable *next = frame->getInitFrame().next;
        
        VFX_FLAG_SET(frame->m_animatableFlags, FLAGS_INITIALIZED);
        frame->resetInitFrame();
        
        frame = next;
    }

    s_initFrameListHead = NULL;
    s_initFrameListTail = NULL;
}


const VfxAnimatable::frameLinkEntry &VfxAnimatable::getInitFrame(void) const
{
    return m_initframelink;
}


void VfxAnimatable::setPrevInitFrame(VfxAnimatable *frame)
{
    m_initframelink.prev = frame;
}


void VfxAnimatable::setNextInitFrame(VfxAnimatable *frame)
{
    m_initframelink.next = frame;
}


void VfxAnimatable::resetInitFrame(void)
{
    m_initframelink.prev = NULL;
    m_initframelink.next = NULL;
}

