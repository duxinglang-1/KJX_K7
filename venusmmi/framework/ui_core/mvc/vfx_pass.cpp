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
 *  vfx_pass.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_pass.h"
#include "vfx_render_mode.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_target.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxPass
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_CLASS("Pass", VfxPass, VfxObject3D);

VfxPass::VfxPass(VfxPassGeometryType type) :
    m_tessellationLevel(1, 1), 
    m_passType(type)
{
    m_shaderUniformsList.init(this);
}


void VfxPass::createHandle() const
{
    m_handle = vrt_create_pass((VrtPassGeometryType)m_passType);
}


void VfxPass::disposeHandle() const
{
    if (m_handle)
    {
        if (m_shaderProgram.get())
        {
            m_shaderProgram->disposeHandle();
        }

        VfxList< VfxWeakPtr< VfxShaderUniforms > >::ConstIt itr;
        for (itr = m_shaderUniformsList.begin();
             itr != m_shaderUniformsList.end();
             ++itr)
        {
            if (itr->get())
            {
                (*itr)->disposeHandle();
            }
        }

        if (m_renderMode.get())
        {
            m_renderMode->disposeHandle();
        }

        if (m_polygonMode.get())
        {
            m_polygonMode->disposeHandle();
        }

        if (m_compositingMode.get())
        {
            m_compositingMode->disposeHandle();
        }
        
        if (m_renderTarget.get())
        {
            m_renderTarget->disposeHandle();
        }

        VfxObject3D::disposeHandle();
    }
}


void VfxPass::syncData() const
{
    VfxObject3D::syncData();

    if (isPropertyDirty(VFX_PASS_TESSELLATION_LEVEL_DIRTY))
    {
        vrt_pass_set_tessellation_level(m_handle, m_tessellationLevel.x, m_tessellationLevel.y);
    }

    VfxShaderProgram *program = m_shaderProgram.get();
    if (isPropertyDirty(VFX_PASS_SHADER_PROGRAM_DIRTY))
    {
        vrt_pass_set_program(m_handle, program ? program->getSyncHandle() : NULL);
    }
    if (program)
    {        
        program->syncData();
    }


    if (isPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY))
    {
        vrt_pass_remove_all_uniforms(m_handle);
    }
    VfxList< VfxWeakPtr< VfxShaderUniforms > >::ConstIt itr;
    for (itr = m_shaderUniformsList.begin();
         itr != m_shaderUniformsList.end();
         ++itr)
    {
        VfxShaderUniforms *uniforms = itr->get();
        if (uniforms)
        {
            if (isPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY))
            {
                vrt_pass_add_uniforms(m_handle, uniforms->getSyncHandle());
            }
            uniforms->syncData();
        }
    }

    VfxCompositingMode *cm = m_compositingMode.get();
    if (isPropertyDirty(VFX_PASS_COMPOSITING_MODE_DIRTY))
    {
        vrt_pass_set_compositing_mode(m_handle, cm ? cm->getSyncHandle() : NULL);
    }
    if (cm)
    {        
        cm->syncData();
    }

    VfxPolygonMode *pm = m_polygonMode.get();
    if (isPropertyDirty(VFX_PASS_POLYGON_MODE_DIRTY))
    {
        vrt_pass_set_polygon_mode(m_handle, pm ? pm->getSyncHandle() : NULL);
    }
    if (pm)
    {        
        pm->syncData();
    }

    VfxRenderMode *rm = m_renderMode.get();
    if (isPropertyDirty(VFX_PASS_RENDER_MODE_DIRTY))
    {
        vrt_pass_set_render_mode(m_handle, rm ? rm->getSyncHandle() : NULL);
    }
    if (rm)
    {
        rm->syncData();
    }

    VfxRenderTarget *rt = m_renderTarget.get();
    if (isPropertyDirty(VFX_PASS_RENDER_TARGET_DIRTY))
    {
        vrt_pass_set_render_target(m_handle, rt ? rt->getSyncHandle() : NULL);
    }
    if (rt)
    {        
        rt->syncData();
    }

    clearPropertyDirty(VFX_PASS_ALL_DIRTY);
}


void VfxPass::setTessellationLevel(VrtVector2us level)
{
    m_tessellationLevel = level;
    setPropertyDirty(VFX_PASS_TESSELLATION_LEVEL_DIRTY);
}


void VfxPass::setRenderMode(VfxRenderMode *mode)
{
    m_renderMode = mode;
    setPropertyDirty(VFX_PASS_RENDER_MODE_DIRTY);
}


VfxRenderMode *VfxPass::getRenderMode() const
{
    return m_renderMode.get();
}


void VfxPass::setPolygonMode(VfxPolygonMode *mode)
{
    m_polygonMode = mode;
    setPropertyDirty(VFX_PASS_POLYGON_MODE_DIRTY);
}


VfxPolygonMode *VfxPass::getPolygonMode() const
{
    return m_polygonMode.get();
}


void VfxPass::setCompositingMode(VfxCompositingMode *mode)
{
    m_compositingMode = mode;
    setPropertyDirty(VFX_PASS_COMPOSITING_MODE_DIRTY);
}


VfxCompositingMode *VfxPass::getCompositingMode() const
{
    return m_compositingMode.get();
}


void VfxPass::setShaderProgram(VfxShaderProgram *program)
{
    m_shaderProgram = program;
    setPropertyDirty(VFX_PASS_SHADER_PROGRAM_DIRTY);
}


VfxShaderProgram *VfxPass::getShaderProgram() const
{
    return m_shaderProgram.get();
}


void VfxPass::addShaderUniforms(VfxShaderUniforms *uniforms)
{
    m_shaderUniformsList.pushBack(uniforms);
    setPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY);
}


VfxShaderVariable *VfxPass::getUniformVariable(const VfxString &name) const
{
    VfxList< VfxWeakPtr< VfxShaderUniforms > >::ConstIt itr;
    for (itr = m_shaderUniformsList.rbegin();
         itr != m_shaderUniformsList.rend();
         --itr)
    {
        if (itr->get())
        {
            VfxShaderVariable *var = (*itr)->getUniformVariable(name);
            if (var != NULL)
            {
                return var;
            }
        }
    }
    return NULL;
}


void VfxPass::setRenderTarget(VfxRenderTarget *rt)
{
    m_renderTarget = rt;
    setPropertyDirty(VFX_PASS_RENDER_TARGET_DIRTY);
}


VfxRenderTarget *VfxPass::getRenderTarget() const
{
    return m_renderTarget.get();
}


const VfxList< VfxWeakPtr<VfxShaderUniforms> > &VfxPass::getShaderUniformList() const
{
    return m_shaderUniformsList;
}

#pragma arm section code, rodata
