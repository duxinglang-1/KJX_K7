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
 *  vfx_owner_draw_control.cpp
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_owner_draw_control.h"

extern "C"
{
    #include "cache_sw.h"
}

/***************************************************************************** 
 * Class VfxOwnerDrawControl
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxOwnerDrawControl", VfxOwnerDrawControl, VfxControl);

VfxOwnerDrawControl::VfxOwnerDrawControl() :
    m_ownerDraw(NULL)
{
    m_curDstBuffer.ptr = NULL;
    m_curDstBuffer.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
    m_curDstBuffer.pitchBytes = 0;
    m_curDstBuffer.width = 0;
    m_curDstBuffer.height = 0;

    m_switched = VFX_FALSE;
}


void VfxOwnerDrawControl::setFrameBuffer(VfxImageBuffer &buffer)
{
    if (m_ownerDraw->getFrameBuffer() != buffer)
    {
        VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;
        
        setSize((VfxS32)buffer.width, (VfxS32)buffer.height);
            
        m_ownerDraw->setFrameBuffer(buffer);

        VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
    }
}


VfxImageBuffer VfxOwnerDrawControl::getFrameBuffer() const
{
    VfxImageBuffer ret = m_ownerDraw->getFrameBuffer();

    return ret;
}


void VfxOwnerDrawControl::invalidateFrameBuffer(VfxRect rect)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    if (rect == VFX_RECT_ZERO)
    {
        VfxRect bounds = getBounds();
        m_ownerDraw->invalidate(bounds);
    }
    else
    {
        m_ownerDraw->invalidate(rect);
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
    
}


void VfxOwnerDrawControl::setFrameAttributes(VfxU32 width, VfxU32 height, VfxColorTypeEnum cf)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;
    
    m_ownerDraw->setFrameAttributes(width, height, cf);

    setSize(width, height);

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDrawControl::beginUpdateRenderProperties()
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;
}


void VfxOwnerDrawControl::endUpdateRenderProperties()
{
    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

#define OWNER_DRAW_CONTROL_MEM_ALIGNMENT 32

#define OWNER_DRAW_CONTROL_MEM_LEFT_ALIGN(x) (x & ~(OWNER_DRAW_CONTROL_MEM_ALIGNMENT - 1))
#define OWNER_DRAW_CONTROL_MEM_ALIGN(x) ((((VfxU32)x) + OWNER_DRAW_CONTROL_MEM_ALIGNMENT - 1) / OWNER_DRAW_CONTROL_MEM_ALIGNMENT * OWNER_DRAW_CONTROL_MEM_ALIGNMENT)

#define OWNER_DRAW_CONTROL_MEM_PADDING(x) ((x) + OWNER_DRAW_CONTROL_MEM_ALIGNMENT - 1 + OWNER_DRAW_CONTROL_MEM_ALIGNMENT - 1)
#define OWNER_DRAW_CONTROL_MEM_PADDING_ALIGN(x) (OWNER_DRAW_CONTROL_MEM_ALIGN(x))

#define OWNER_DRAW_CONTROL_IS_DCACHE_ALIGNED_ADDR(p) (((VfxU32)(p) & (OWNER_DRAW_CONTROL_MEM_ALIGNMENT - 1)) == 0)

#endif

VfxU8 *VfxOwnerDrawControl::beginHWRendering()
{
    VFX_ASSERT(m_curDstBuffer.ptr); // Please use beginHWRendering()/endHWRendering() in onDrawFrameBuffer()
    
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    VFX_ASSERT(OWNER_DRAW_CONTROL_IS_DCACHE_ALIGNED_ADDR(m_curDstBuffer.ptr));

    VfxU8 *ptr = m_curDstBuffer.ptr;

    vrt_dynamic_switch_cacheable_region(&ptr, 
        OWNER_DRAW_CONTROL_MEM_ALIGN(m_curDstBuffer.width * m_curDstBuffer.height * vrt_bytes_of_pixel(m_curDstBuffer.colorFormat)),
        VRT_FALSE);

    m_switched = (ptr != m_curDstBuffer.ptr);
        
    m_curDstBuffer.ptr = ptr;
#endif
    
    return m_curDstBuffer.ptr;

}


VfxU8 *VfxOwnerDrawControl::endHWRendering()
{
    VFX_ASSERT(m_curDstBuffer.ptr); // Please use beginHWRendering()/endHWRendering() in onDrawFrameBuffer()
    
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    if (m_switched)
    {
        VFX_ASSERT(OWNER_DRAW_CONTROL_IS_DCACHE_ALIGNED_ADDR(m_curDstBuffer.ptr));

        vrt_dynamic_switch_cacheable_region(&m_curDstBuffer.ptr, 
            OWNER_DRAW_CONTROL_MEM_ALIGN(m_curDstBuffer.width * m_curDstBuffer.height * vrt_bytes_of_pixel(m_curDstBuffer.colorFormat)),
            VRT_TRUE);
    }

    m_switched = VFX_FALSE;
#endif

    return m_curDstBuffer.ptr;
}


void VfxOwnerDrawControl::setNeedHWRenderingBuffer(VfxBool isNeeded)
{
    m_ownerDraw->setNeedHWRenderingBuffer(isNeeded);
}


VfxBool VfxOwnerDrawControl::getNeedHWRenderingBuffer()
{
    return m_ownerDraw->getNeedHWRenderingBuffer();
}


void VfxOwnerDrawControl::setBounds(const VfxRect &value)
{
    if (getBounds() != value)
    {
        VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;
        
        if (m_ownerDraw->getFrameBuffer().ptr != NULL)
        {
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        }
        
        VfxFrame::setBounds(value);

        VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
    }
}


void VfxOwnerDrawControl::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_ownerDraw, VfxOwnerDrawWrapper, this);

    VfxObjHandle objHandle = getObjHandle();

    m_ownerDraw->setOwnerDrawCallback(VfxOwnerDrawControl::onOwnerDraw, &objHandle, sizeof(VfxObjHandle));

    m_ownerDraw->setOwnerDrawAnimationCallback(VfxOwnerDrawControl::onOwnerDrawAnimation, &objHandle, sizeof(VfxObjHandle));

    m_ownerDraw->setCommitCallback(VfxOwnerDrawControl::onCommitCallback, &objHandle, sizeof(VfxObjHandle));

    setOwnerDraw(m_ownerDraw);
}


void VfxOwnerDrawControl::onOwnerDraw(VfxImageBuffer &dstBuffer, const VfxPoint &frameOrigin, const VfxRect &dirtyRect, void *userData, VfxU32 userDataSize)
{
    VFX_ASSERT(userDataSize == sizeof(VfxObjHandle));

    VfxOwnerDrawControl *ownerDrawControl = (VfxOwnerDrawControl *)handleToObject(*((VfxObjHandle *)userData));

    if (!ownerDrawControl)
    {
        return;
    }

    ownerDrawControl->m_curDstBuffer = dstBuffer;
    
    ownerDrawControl->onDrawFrameBuffer(dstBuffer, frameOrigin, dirtyRect);

    ownerDrawControl->m_curDstBuffer.ptr = NULL;
    ownerDrawControl->m_curDstBuffer.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
    ownerDrawControl->m_curDstBuffer.pitchBytes = 0;
    ownerDrawControl->m_curDstBuffer.width = 0;
    ownerDrawControl->m_curDstBuffer.height = 0;
}


vrt_render_owner_draw_dirty_type_enum VfxOwnerDrawControl::onOwnerDrawAnimation(vrt_msec_type currFrameTime, VfxRect &dirtyRect, void *userData, VfxU32 userDataSize)
{
    VFX_ASSERT(userDataSize == sizeof(VfxObjHandle));

    VfxOwnerDrawControl *ownerDrawControl = (VfxOwnerDrawControl *)handleToObject(*((VfxObjHandle *)userData));

    if (!ownerDrawControl)
    {
        return VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE;
    }

    return ownerDrawControl->onExecuteAnimation(currFrameTime, dirtyRect);
}


void VfxOwnerDrawControl::onCommitCallback(void *userData, VfxU32 userDataSize)
{
    VFX_ASSERT(userDataSize == sizeof(VfxObjHandle));

    VfxOwnerDrawControl *ownerDrawControl = (VfxOwnerDrawControl *)handleToObject(*((VfxObjHandle *)userData));

    if (!ownerDrawControl)
    {
        return;
    }

    ownerDrawControl->onCommit();
}


