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
 *  vfx_object_3d.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vrt_canvas.h"
#include "vrt_3d.h"


extern "C" void vrt_animatable_commit(vrt_animatable_handle object_handle);


/***************************************************************************** 
 * Class VfxObject3D
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_VIRTUAL_CLASS("Object3D", VfxObject3D, VfxAnimatable);

VfxObject3D::VfxObject3D() : 
    m_dirtyFlag(0)
{
}


vrt_object_handle VfxObject3D::getSyncHandle() const
{
    if (m_handle == NULL)
    {
        createHandle();

        if (m_handle != NULL)
        {
            vrt_object_set_sync_object(m_handle, (void *)static_cast<const IVrtSyncObject *>(this));
        }
    }
    return m_handle;
}


void VfxObject3D::onDeinit()
{
    if (m_handle)
    {
        vrt_object_release(m_handle);
        m_handle = NULL;
    }

    VfxAnimatable::onDeinit();
}


void VfxObject3D::onAddTimeline()
{
    setPropertyDirty(VFX_OBJECT3D_TIMELINE_DIRTY);
}


void VfxObject3D::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_ANIMATABLE_NOTIFY_ID_ADD_TIMELINE:
        {
            onAddTimeline();
            return;
        }
        default:
        {
            VfxObject::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxObject3D::resetProperty(vrt_object_property_id_enum propertyId)
{
}


void VfxObject3D::disposeHandle() const
{
    VfxAnimatable::disposeAnimationHandle();

    if (m_handle)
    {
        vrt_object_release(m_handle);
        m_handle = NULL;
    }

    setPropertyDirty(0xffffffff);
}


void VfxObject3D::processCreateHandle()
{
    VfxAnimatable::processCreateHandle();
    
    getSyncHandle();
}


void VfxObject3D::processReleaseHandle()
{
    disposeHandle();

    VfxAnimatable::processReleaseHandle();
}


void VfxObject3D::syncData() const
{
    VFX_DEV_ASSERT(m_handle != NULL);

    if (VFX_FLAG_HAS(m_dirtyFlag, VFX_OBJECT3D_PROPERTY_DIRTY))
    {
        VFX_FLAG_CLEAR(m_dirtyFlag, VFX_OBJECT3D_PROPERTY_DIRTY);
        vrt_frame_set_3d_dirty();
    }

    VfxAnimatable::prepareAnimationHandle();

    vrt_animatable_commit(m_handle);

    clearPropertyDirty(VFX_OBJECT3D_ALL_DIRTY);
}


void VfxObject3D::destroy() const
{
    m_handle = NULL;
    setPropertyDirty(0xffffffff);
}

#pragma arm section code, rodata
