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
 *  vfx_shader_uniforms.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_shader_uniforms.h"
#include "vfx_texture.h"
#include "vfx_stream.h"
#include "vrt_3d.h"


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

/***************************************************************************** 
 * Class VfxShaderVariable
 *****************************************************************************/

VfxShaderVariable::VfxShaderVariable(const VfxString &name, VfxTypeIdEnum type, VfxU16 count)
: m_name(name)
, m_type(type)
, m_count(count)
, m_dataType(VFX_VARIABLE_TYPE_NULL)
{
    if (m_type == VFX_TYPE_ID_SAMPLER)
    {
        // changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
        VFX_ALLOC_MEM(m_data, vrt_get_size_of_type((vrt_type_id_enum)type) * count, this);
        m_dataType = VFX_VARIABLE_TYPE_DYNAMIC_BUF;
    }
}

VfxShaderVariable::~VfxShaderVariable()
{
    changeDataType(VFX_VARIABLE_TYPE_NULL);
}

void VfxShaderVariable::changeDataType(const VfxVariableType dataType)
{
    if (m_dataType == dataType)
    {
        return;
    }

    if (m_dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF)
    {
        VFX_FREE_MEM(m_data);
    }
    else if (m_dataType == VFX_VARIABLE_TYPE_BINDING)
    {
        *(VfxWeakPtr< VfxObject3D > *)m_refObjBuffer = NULL;
    }

    if (dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF)
    {
        VFX_ALLOC_MEM(m_data, getDataSize(), this);
    }
    else if (dataType == VFX_VARIABLE_TYPE_BINDING)
    {
        new (m_refObjBuffer) VfxWeakPtr< VfxObject3D >();
    }

    m_dataType = dataType;
}

void VfxShaderVariable::createHandle() const
{
    if (m_type == VFX_TYPE_ID_SAMPLER)
    {
        m_handle = vrt_create_shader_variable(m_name.getBuf(), m_name.isDynamic() ? VRT_TRUE : VRT_FALSE, (vrt_type_id_enum)m_type, m_count, NULL);
    }
    else
    {
        m_handle = vrt_create_shader_variable(m_name.getBuf(), m_name.isDynamic() ? VRT_TRUE : VRT_FALSE, (vrt_type_id_enum)m_type, m_count, getDataPtr());
        clearPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
    }
}

void VfxShaderVariable::disposeHandle() const
{
    if (m_handle)
    {
        if (m_type == VFX_TYPE_ID_SAMPLER)
        {
            VFX_DEV_ASSERT(m_dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF);
            VfxTexture *texture =  *reinterpret_cast<VfxTexture **>(m_data);
            if (texture)
            {
                texture->disposeHandle();
            }
        }
        VfxObject3D::disposeHandle();
    }
}


void VfxShaderVariable::resetProperty(vrt_object_property_id_enum propertyId)
{
    switch (propertyId)
    {
    case VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_VEC2:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_VEC3:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_QUAT:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_MAT2:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_MAT3:
    case VRT_SHADER_VARIABLE_PROPERTY_ID_MAT4:
        setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
        break;
    default:
        //VfxObject3D::resetProperty(propertyId);
        break;
    }
}


void VfxShaderVariable::syncData() const
{
    VfxObject3D::syncData();

    if (m_type == VFX_TYPE_ID_SAMPLER && *reinterpret_cast<VfxTexture **>(m_data))
    {
        VFX_DEV_ASSERT(m_dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF);
        VfxTexture *texture =  *reinterpret_cast<VfxTexture **>(m_data);
        vrt_object_handle tex_handle = texture->getSyncHandle();
        if (isPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY))
        {
            vrt_shader_variable_set_value(m_handle, &tex_handle);
        }
        texture->syncData();
    }
    else
    {
        if (isPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY))
        {
            vrt_shader_variable_set_value(m_handle, getDataPtr());
        }
    }

    VfxObject3D *obj = getBindObj();
    if (isPropertyDirty(VFX_SHADER_VARIABLE_BIND_DIRTY))
    {
        vrt_shader_variable_bind_uniform(m_handle, obj ? obj->getSyncHandle() : NULL, (VrtBindingProperty)m_propertyID);
    }
    if (obj)
    {
        obj->syncData();
    }

    clearPropertyDirty(VFX_SHADER_VARIABLE_ALL_DIRTY);
}

void VfxShaderVariable::setValue(VfxFloat x)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_FLOAT);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxFloat *>(m_data) = x;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxS32 x)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_S32);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxS32 *>(m_data) = x;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxBool x)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_BOOL);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxBool *>(m_data) = x;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(const VfxMatrix3f &mat)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_MAT3);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxMatrix3f *>(m_data) = mat;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(const VfxMatrix4f &mat)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_MAT4);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxMatrix4f *>(m_data) = mat;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxTexture *tex)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_SAMPLER);
    VFX_DEV_ASSERT(m_dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VfxTexture **>(m_data) = tex;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxFloat x, VfxFloat y)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_VEC2);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector2f *>(m_data) = VrtVector2f(x, y);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxS32 x, VfxS32 y)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_IVEC2);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector2i*>(m_data) = VrtVector2i(x, y);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxBool x, VfxBool y)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_BVEC2);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector2b*>(m_data) = VrtVector2b(x, y);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxFloat x, VfxFloat y, VfxFloat z)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_VEC3);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector3f *>(m_data) = VrtVector3f(x, y, z);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxS32 x, VfxS32 y, VfxS32 z)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_IVEC3);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector3i*>(m_data) = VrtVector3i(x, y, z);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxBool x, VfxBool y, VfxBool z)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_BVEC3);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector3b*>(m_data) = VrtVector3b(x, y, z);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxFloat x, VfxFloat y, VfxFloat z, VfxFloat w)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_VEC4);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector4f *>(m_data) = VrtVector4f(x, y, z, w);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxS32 x, VfxS32 y, VfxS32 z, VfxS32 w)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_IVEC4);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector4i*>(m_data) = VrtVector4i(x, y, z, w);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValue(VfxBool x, VfxBool y, VfxBool z, VfxBool w)
{
    VFX_DEV_ASSERT(m_type == VRT_TYPE_ID_BVEC4);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    *reinterpret_cast<VrtVector4b*>(m_data) = VrtVector4b(x, y, z, w);
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValueFromConstBuf(void *values)
{
    VFX_DEV_ASSERT(m_type != VRT_TYPE_ID_SAMPLER);
    changeDataType(VFX_VARIABLE_TYPE_CONST_BUF);
    m_data = values;
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::setValueFromDynamicBuf(void *values)
{
    VFX_DEV_ASSERT(m_type != VRT_TYPE_ID_SAMPLER);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    memcpy(m_data, values, getDataSize());
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::readValueStream(VfxInputStream &is)
{
    VFX_DEV_ASSERT(m_type != VRT_TYPE_ID_SAMPLER);
    changeDataType(VFX_VARIABLE_TYPE_DYNAMIC_BUF);
    is.read((VfxU8 *)m_data, getDataSize());
    setPropertyDirty(VFX_SHADER_VARIABLE_VALUE_DIRTY);
}

void VfxShaderVariable::bindValue(VfxObject3D *obj, VfxVariableBindingProperty property_id)
{
    VFX_DEV_ASSERT(m_type != VRT_TYPE_ID_SAMPLER);
    changeDataType(VFX_VARIABLE_TYPE_BINDING);
    if (((VfxWeakPtr< VfxObject3D > *)m_refObjBuffer)->get() != obj || m_propertyID != property_id)
    {
        m_propertyID = property_id;
        *(VfxWeakPtr< VfxObject3D > *)m_refObjBuffer = obj;
        setPropertyDirty(VFX_SHADER_VARIABLE_BIND_DIRTY);
    }
}


/***************************************************************************** 
 * Class VfxShaderUniforms
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("ShaderUniforms", VfxShaderUniforms, VfxObject3D);

VfxShaderUniforms::VfxShaderUniforms()
{
    m_variables.init(this);
}


void VfxShaderUniforms::createHandle() const
{
    m_handle = vrt_create_uniforms();
}


void VfxShaderUniforms::disposeHandle() const
{
    if (m_handle)
    {
        VariableList::ConstIt itr;
        for (itr = m_variables.begin(); itr != m_variables.end(); ++itr)
        {
            (*itr)->disposeHandle();
        }
        VfxObject3D::disposeHandle();
    }
}


void VfxShaderUniforms::syncData() const
{
    VfxObject3D::syncData();

    VariableList::ConstIt itr;

    // remove all shader variable and bindings
    if (isPropertyDirty(VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY))
    {
        vrt_uniforms_remove_all(m_handle);
    }

    for (itr = m_variables.begin(); itr != m_variables.end(); ++itr)
    {
        VfxShaderVariable *var = *itr;
        if (isPropertyDirty(VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY))
        {
            vrt_uniforms_add_variable(m_handle, var->getSyncHandle());
        }
        var->syncData();
    }

    clearPropertyDirty(VFX_SHADER_UNIFORMS_ALL_DIRTY);
}


VfxShaderVariable *VfxShaderUniforms::addUniformVariable(const VfxString &name, VfxTypeIdEnum type, VfxU16 count)
{
    // TODO: check if the variable (via name) is already existing

    VfxShaderVariable *var;
    VFX_OBJ_CREATE_EX(var, VfxShaderVariable, this, (name, type, count));
    m_variables.pushBack(var);
    setPropertyDirty(VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY);
    return var;
}


void VfxShaderUniforms::removeUniformVariable(VfxShaderVariable *variable)
{
    VariableList::It itr = m_variables.find(variable);
    if (!itr.isNull())
    {
        m_variables.erase(itr);
        setPropertyDirty(VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY);
        VFX_OBJ_CLOSE(variable);
    }
}


VfxShaderVariable *VfxShaderUniforms::getUniformVariable(const VfxString &name) const
{
    VariableList::ConstIt itr;
    for (itr = m_variables.rbegin(); itr != m_variables.rend(); --itr)
    {
        VfxShaderVariable *var = *itr;
        if (var->getName() == name)
        {
            return var;
        }
    }
    return NULL;
}


const VfxShaderUniforms::VariableList &VfxShaderUniforms::getVariableList() const
{
    return m_variables;
}

#pragma arm section code, rodata
