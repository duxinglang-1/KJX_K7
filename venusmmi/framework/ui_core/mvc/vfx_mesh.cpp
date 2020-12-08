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
 *  vfx_mesh.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vrt_3d.h"

#include "vfx_font_desc.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_buffer.h"
#include "vfx_texture.h"


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

/***************************************************************************** 
 * Class VfxMesh
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Mesh", VfxMesh, VfxNode);


VfxMesh::VfxMesh(VfxU32 subMeshCount) : m_assetSrc()
{
    m_materials.init(this);
    m_materials.resize(subMeshCount);
    m_invisibilities.init(this);
    m_invisibilities.resize(subMeshCount);
}


void VfxMesh::setResId(VfxResId resId)
{
    // we does not support to reload mesh, yet.
    VFX_DEV_ASSERT(m_assetSrc.isNull());
    m_assetSrc.setResId(resId);
}


void VfxMesh::setPath(const VfxWString &path)
{
    // we does not support to reload mesh, yet.
    VFX_DEV_ASSERT(m_assetSrc.isNull());
    m_assetSrc.setPath(path);
}


VfxResId VfxMesh::getResId() const
{
    return m_assetSrc.getResId();
}


const VfxWString &VfxMesh::getPath() const
{
    return m_assetSrc.getPath();
}


void VfxMesh::setSubMeshCount(VfxU32 count)
{
    m_materials.resize(count);
    m_invisibilities.resize(count);
    setPropertyDirty(VFX_MESH_MATERIAL_DIRTY);
    setPropertyDirty(VFX_MESH_VISIBILITY_DIRTY);
}


VfxU32 VfxMesh::getSubMeshCount() const
{
    return m_materials.size();
}


void VfxMesh::createHandle() const
{

    switch (m_assetSrc.getType())
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        //m_handle = vrt_create_mesh();
        break;
    case VFX_ASSET_SRC_TYPE_RES_ID:
        {
            m_handle = vrt_create_mesh_from_resource(m_assetSrc.getResId());
        }
        break;
    case VFX_ASSET_SRC_TYPE_PATH:
        {
            const VfxWString filePath = m_assetSrc.getPath();
            m_handle = vrt_create_mesh_from_path(filePath.getBuf(), filePath.isDynamic() ? VRT_TRUE : VRT_FALSE);
        }
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }

}


void VfxMesh::disposeHandle() const
{
    if (m_handle)
    {
        VfxU32 i;
        for (i = 0; i < m_materials.size(); i++)
        {
            // material
            const VfxMaterial *material = m_materials[i].get();
            if (material)
            {
                material->disposeHandle();
            }
        }

        VfxNode::disposeHandle();
    }
}


void VfxMesh::syncData() const
{
    VfxNode::syncData();

    // material
    VfxU32 i;
    for (i = 0; i < m_materials.size(); i++)
    {
        const VfxMaterial *material = m_materials[i].get();

        if (isPropertyDirty(VFX_MESH_MATERIAL_DIRTY))
        {
            vrt_mesh_set_material(m_handle, i, material ? material->getSyncHandle() : NULL);
        }
        if (material)
        {
            material->syncData();
        }

        if (isPropertyDirty(VFX_MESH_VISIBILITY_DIRTY))
        {
            vrt_mesh_set_submesh_visible(m_handle, i, !m_invisibilities[i]);
        }
    }

    // TODO: morph weight
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    clearPropertyDirty(VFX_MESH_ALL_DIRTY);
}


void VfxMesh::setMaterial(VfxU32 idx, VfxMaterial *material)
{
    m_materials[idx] = material;
    setPropertyDirty(VFX_MESH_MATERIAL_DIRTY);
}


VfxMaterial *VfxMesh::getMaterial(VfxU32 idx) const
{
    return m_materials[idx].get();
}


void VfxMesh::setSubMeshVisible(VfxU32 idx, VfxBool value)
{
    m_invisibilities[idx] = !value;
    setPropertyDirty(VFX_MESH_VISIBILITY_DIRTY);
}


VfxBool VfxMesh::isSubMeshVisible(VfxU32 idx) const
{
    return !m_invisibilities[idx];
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
 * Class VfxPlaneMesh
 *****************************************************************************/

VfxPlaneMesh::VfxPlaneMesh(VfxFloat size) :
    VfxMesh((VfxU32)1),
    m_width(size),
    m_height(size)
{
}


VfxPlaneMesh::VfxPlaneMesh(VfxFloat width, VfxFloat height) :
    VfxMesh((VfxU32)1),
    m_width(width),
    m_height(height)
{
}


VfxFloat VfxPlaneMesh::getWidth() const
{
    return m_width;
}


VfxFloat VfxPlaneMesh::getHeight() const
{
    return m_height;
}


void VfxPlaneMesh::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_create_plane_mesh(m_width, m_height);
}


/***************************************************************************** 
 * Class VfxBoxMesh
 *****************************************************************************/

VfxBoxMesh::VfxBoxMesh(VfxFloat size) : 
    VfxMesh((VfxU32)1), 
    m_length(size), 
    m_width(size), 
    m_height(size)
{
}


VfxBoxMesh::VfxBoxMesh(VfxFloat length, VfxFloat width, VfxFloat height) : 
    VfxMesh((VfxU32)1), 
    m_length(length), 
    m_width(width), 
    m_height(height)
{
}


void VfxBoxMesh::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);
    m_handle = vrt_create_box_mesh(m_length, m_width, m_height);
}


/***************************************************************************** 
 * Class VfxSphereMesh
 *****************************************************************************/

VfxSphereMesh::VfxSphereMesh(VfxFloat radius) : 
    VfxMesh((VfxU32)1), 
    m_radius(radius)
{
}


void VfxSphereMesh::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);
    m_handle = vrt_create_sphere_mesh(m_radius);
}


/***************************************************************************** 
 * Class VfxProceduralMesh
 *****************************************************************************/

VfxProceduralMesh::VfxProceduralMesh() : 
    VfxMesh((VfxU32)1)
{
}


void VfxProceduralMesh::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    const IVrtProceduralMesh *pm = static_cast<const IVrtProceduralMesh *>(this);
    m_handle = vrt_create_procedural_mesh(reinterpret_cast<const void *>(pm));
}


/***************************************************************************** 
 * Class VfxTextMesh
 *****************************************************************************/

VfxTextMesh::VfxTextMesh(
    VfxFloat w, 
    VfxFloat h, 
    const VfxWString &text, 
    VfxFloat lineHeight,
    VfxTextMeshAlignModeEnum alignMode,
    VfxTextMeshValignModeEnum valignMode) :    
        VfxPlaneMesh(w, h), 
        m_lineHeight(lineHeight),
        m_alignMode(alignMode),
        m_valignMode(valignMode),
        m_textImage(NULL),
        m_texture(NULL),
        m_svTexCoordScale(NULL),
        m_svTexCoordBias(NULL)
{
    setup(w, h, text, VFX_FONT_DESC_MEDIUM);
    layout();
}


void VfxTextMesh::setString(const VfxWString &value)
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    m_textImage->setString(value);
    layout();
}


void VfxTextMesh::setFont(const VfxFontDesc &value)
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    m_textImage->setFont(value);
    layout();
}


void VfxTextMesh::setTextColor(const VfxColor &value)
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    m_textImage->setTextColor(value);
}


void VfxTextMesh::setTextBorderColor(const VfxColor &value)
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    m_textImage->setTextBorderColor(value);
}


void VfxTextMesh::setBackgroundColor(const VfxColor &value)
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    m_textImage->setBackgroundColor(value);
}


const VfxWString &VfxTextMesh::getString() const
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    return m_textImage->getString();
}


const VfxFontDesc &VfxTextMesh::getFont() const
{
    VFX_DEV_ASSERT(m_textImage != NULL);
    return m_textImage->getFont();
}


void VfxTextMesh::setup(VfxFloat w, VfxFloat h, const VfxWString &text, const VfxFontDesc &font)
{
    VFX_DEV_ASSERT(m_textImage == NULL && m_texture == NULL);

    VfxMaterial *material;
    VFX_OBJ_CREATE(material, VfxMaterial, this);
    setMaterial(0, material);

    VfxPass *pass1;
    VFX_OBJ_CREATE(pass1, VfxPass, material);
    material->setPass(0, pass1);

    static const vrt_char vShader1[] =
    "attribute vec4 v3d_Position; \n"
    "attribute vec2 v3d_TexCoord; \n"
    "varying vec2 vTexCoord; \n"
    "uniform vec2 texCoordScale; \n"
    "uniform vec2 texCoordBias; \n"
    "uniform vec4 v3d_PositionScale; \n"
    "uniform vec4 v3d_PositionBias; \n"
    "uniform vec4 v3d_TexCoordScale; \n"
    "uniform vec4 v3d_TexCoordBias; \n"
    "uniform mat4 v3d_MVPSMatrix; \n"
    "uniform float v3d_Opacity; \n"
    "void main() \n"
    "{ \n"
    "    gl_Position = v3d_MVPSMatrix * (v3d_Position * v3d_PositionScale + v3d_PositionBias); \n"
    "    vTexCoord = (vec4(v3d_TexCoord, 0.0, 0.0) * v3d_TexCoordScale + v3d_TexCoordBias).xy * texCoordScale + texCoordBias; \n"
    "} \n";

    static const vrt_char fShader1[] =
    "precision mediump float; \n"
    "varying vec2 vTexCoord; \n"
    "uniform sampler2D frameTex; \n"
    "void main() \n"
    "{ \n"
    "    gl_FragColor = texture2D(frameTex, vTexCoord); \n"
    "} \n";

    VfxShaderProgram *program1;
    VFX_OBJ_CREATE_EX(program1, VfxShaderProgram, pass1, (vShader1, fShader1));
    pass1->setShaderProgram(program1);

    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass1);
    pass1->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(m_textImage, VfxImageText, this, (text, font));

    VFX_OBJ_CREATE_EX(m_texture, VfxTexture2D, this, (m_textImage));

    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("frameTex"), VFX_TYPE_ID_SAMPLER, 1);
    var->setValue(m_texture);

    m_svTexCoordScale = uniforms->addUniformVariable(VFX_STR("texCoordScale"), VFX_TYPE_ID_VEC2, 1);
    m_svTexCoordBias = uniforms->addUniformVariable(VFX_STR("texCoordBias"), VFX_TYPE_ID_VEC2, 1);
}


void VfxTextMesh::layout()
{
    VFX_DEV_ASSERT(m_textImage != NULL && m_texture != NULL);

    VfxFloat planeWidth = getWidth();
    VfxFloat planeHeight = getHeight();

    VfxU32 textWidth = m_textImage->getWidth();
    VfxU32 textHeight = m_textImage->getHeight();
    if (textWidth == 0 || textHeight == 0)
    {
        // Avoid zero
        textWidth = 1;
        textWidth = 1;
    }
    
    VfxFloat lineHeight = m_lineHeight != 0.0f ? m_lineHeight : planeHeight;

    VFX_DEV_ASSERT(lineHeight != 0.0f && textWidth != 0 && textHeight != 0);
    
    VfxFloat yScale = planeHeight / lineHeight;
    VfxFloat yBias = 0.0f;
    VfxFloat xScale = planeWidth / (lineHeight * textWidth / textHeight);
    VfxFloat xBias = 0.0f;

    VfxTextMeshAlignModeEnum alignMode = m_alignMode;
    if (alignMode == VFX_TEXT_MESH_ALIGN_MODE_NATUAL)
    {
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
        switch (dir)
        {
            case MG_TEXT_DIR_TYPE_L2R:
                alignMode = VFX_TEXT_MESH_ALIGN_MODE_LEFT;
                break;
            case MG_TEXT_DIR_TYPE_R2L:
                alignMode = VFX_TEXT_MESH_ALIGN_MODE_RIGHT;
                break;
            default:
                VFX_ASSERT(0);
                break;
        }
    }

    switch (alignMode)
    {
        case VFX_TEXT_MESH_ALIGN_MODE_CENTER:
            xBias = (1.0f - xScale) / 2;
            break;
        case VFX_TEXT_MESH_ALIGN_MODE_LEFT:
            xBias = 0.0f;
            break;
        case VFX_TEXT_MESH_ALIGN_MODE_RIGHT:
            xBias = 1.0f - xScale;
            break;
        default:
            VFX_ASSERT(0);
            break;
    }

    switch (m_valignMode)
    {
        case VFX_TEXT_MESH_VALIGN_MODE_CENTER:
            yBias = (1.0f - yScale) / 2;
            break;
        case VFX_TEXT_MESH_VALIGN_MODE_TOP:
            yBias = 0.0f;
            break;
        case VFX_TEXT_MESH_VALIGN_MODE_BOTTOM:
            yBias = 1.0f - yScale;
            break;
        default:
            VFX_ASSERT(0);
            break;
    }
    
    // Flip the y coordinate
    m_svTexCoordScale->setValue(xScale, -yScale);
    m_svTexCoordBias->setValue(xBias, yScale + yBias);
}

#pragma arm section code, rodata
