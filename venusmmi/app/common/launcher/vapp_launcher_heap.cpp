/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_heap.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements launcher's heap.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "GlobalResDef.h"
#include "mmi_frm_gprot.h"

#include "vadp_asm.h"
#include "vapp_platform_context.h"
#include "vapp_launcher_heap.h"
#include "mmi_rp_vapp_launcher_heap_def.h"


/*****************************************************************************
 * Launcher Heap
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherHeap", VappLauncherHeap, VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherHeap);


VappLauncherHeap::VappLauncherHeap()
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    :
    m_asmGid(GRP_ID_INVALID),
    m_isWaitForRelease(VFX_FALSE),
    m_memPtr(NULL),
    m_asmContext(NULL)
#endif /* defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
{
    // Do nothing.
}


VfxContext *VappLauncherHeap::createContext()
{
#if !defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    return VFX_OBJ_GET_INSTANCE(VappPlatformContext);
#else
    return createAsmContext();
#endif /* defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
}


void VappLauncherHeap::releaseContext()
{
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    releaseAsmContext();
#endif
}


VfxContext *VappLauncherHeap::get()
{
#if !defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    return VFX_OBJ_GET_INSTANCE(VappPlatformContext);
#else
    return m_asmContext;
#endif /* defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
}


#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
VfxContext *VappLauncherHeap::createAsmContext()
{
    //
    // Init ASM.
    //
    initAsmMemory();

    //
    // Allocate heap memory.
    //
    VFX_ASSERT(!m_memPtr);
    m_memPtr = (VfxU8 *)asmMalloc(VAPP_LAUNCHER_HEAP_ASM_SIZE);
    VFX_ASSERT(m_memPtr);

    //
    // Create context object.
    //
    VFX_ASSERT(!m_asmContext);

    VFX_OBJ_CREATE(
        m_asmContext,
        VfxContext,
        VFX_OBJ_GET_INSTANCE(VappPlatformContext));

    m_asmContext->assignPool(m_memPtr, VAPP_LAUNCHER_HEAP_ASM_SIZE);

    return m_asmContext;
}


void VappLauncherHeap::releaseAsmContext()
{
    //
    // Close context object.
    //
    VFX_OBJ_CLOSE(m_asmContext);

    //
    // Free heap memory.
    //
    if (m_memPtr)
    {
        asmFree(m_memPtr);
        m_memPtr = NULL;
    }

    //
    // Deinit ASM.
    //
    deinitAsmMemory();
}


void *VappLauncherHeap::asmMalloc(VfxU32 size)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    // Allow to return a NULL pointer if the memory pool is exhausted.

    return vadpAsmAlloc(m_asmGid, size);
}


void VappLauncherHeap::asmFree(void *mem)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    vadpAsmFree(m_asmGid, mem);
}


void VappLauncherHeap::initAsmMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        return; // already initialized.
    }

    m_isWaitForRelease = VFX_FALSE;

    VadpAsmProperty property;

    m_asmGid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_VAPP_LAUNCHER_HEAP_ASM,
                &onAsmGroupEvent,
                getObjHandle());

    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    // Don't reserve the memory such that once OOM happens, we can release our
    // ASM pool and other APP can use these memory.
    //
    // And, hide this pool in OOM dialog since we always free it voluntarily.
    VadpAsm::getProperty(m_asmGid, property);
    property.f_prepare_w_reserve = 0;
    property.f_hide_in_oom       = 1;
    VadpAsm::setProperty(m_asmGid, property);
}


void VappLauncherHeap::deinitAsmMemory()
{
    if (m_asmGid == GRP_ID_INVALID)
    {
        return; // already de-initialized.
    }

    mmi_frm_group_close(m_asmGid);
    m_asmGid = GRP_ID_INVALID;

    if (m_isWaitForRelease)
    {
        mmi_frm_asm_notify_stop_finished(
            GRP_ID_VAPP_LAUNCHER_HEAP_ASM,
            MMI_TRUE);

        m_isWaitForRelease = VFX_FALSE;
    }
}


void VappLauncherHeap::handleAsmFreeReq()
{
    m_signalVolunteerFree.emit();

    //
    // If APP doesn't free the ASM immediately, it means APP wants to do it in
    // an async way. Turn on this flag and wait for APP to release the context.
    //
    if (m_asmGid != GRP_ID_INVALID)
    {
        m_isWaitForRelease = VFX_TRUE;
    }
}


mmi_ret VappLauncherHeap::onAsmGroupEvent(mmi_event_struct *evt)
{
    VappLauncherHeap *_this;

    _this = (VappLauncherHeap *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(_this);

    mmi_ret ret = MMI_RET_OK;

    switch(evt->evt_id)
    {
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        {
            // Keep dangle group.
            ret = MMI_RET_ERR;
            break;
        }
        case EVT_ID_ASM_FREE_REQ:           // volunteer free
        case EVT_ID_ASM_FREE_REQ_NO_WAIT:   // volunteer free
        case EVT_ID_ASM_FORCE_FREE:         // force free
        {
            _this->handleAsmFreeReq();

            if (_this->m_isWaitForRelease)
            {
                ret = MMI_FRM_ASM_WAITING_TO_FREE;
            }
            else
            {
                ret = MMI_FRM_ASM_FREED;
            }

            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}

#endif /* defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */

