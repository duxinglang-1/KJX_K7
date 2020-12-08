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
 *  vfx_render_mode.cpp
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_render_mode.h"
#include "vfx_camera.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxRenderMode
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxRenderMode::VfxRenderMode()
: m_renderCamera(NULL)
, m_scope(VFX_RENDER_SCOPE_DEFAULT)
{
}

void VfxRenderMode::createHandle() const
{
    m_handle = vrt_create_render_mode();
}

void VfxRenderMode::disposeHandle() const
{
    if (m_handle)
    {
        if (m_renderCamera.get())
        {
            m_renderCamera->disposeHandle();
        }
        VfxObject3D::disposeHandle();
    }
}

void VfxRenderMode::syncData() const
{
    VfxObject3D::syncData();

    /* camera */
    VfxCamera *camera = m_renderCamera.get();
    if (isPropertyDirty(VFX_RENDER_MODE_CAMERA_DIRTY))
    {
        vrt_render_mode_set_render_camera(m_handle, camera ? camera->getSyncHandle() : NULL);
    }

    if (camera)
    {
        camera->syncData();
    }

    if (isPropertyDirty(VFX_RENDER_MODE_SCOPE_DIRTY))
    {
        vrt_render_mode_set_scope(m_handle, m_scope);
    }

    clearPropertyDirty(VFX_RENDER_MODE_ALL_DIRTY);
}

void VfxRenderMode::setRenderCamera(VfxCamera *camera)
{
    m_renderCamera = camera;
    setPropertyDirty(VFX_RENDER_MODE_CAMERA_DIRTY);
}

void VfxRenderMode::setScope(VfxU32 scope)
{
    m_scope = scope;
    setPropertyDirty(VFX_RENDER_MODE_SCOPE_DIRTY);
}

#pragma arm section code, rodata
