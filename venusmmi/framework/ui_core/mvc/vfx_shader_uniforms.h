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
 *  vfx_shader_uniforms.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_SHADER_UNIFORMS_H__
#define __VFX_SHADER_UNIFORMS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"
#include "vfx_container.h"
#include "vfx_matrix.h"
#include "vfx_weak_ptr.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxTexture;
class VfxInputStream;


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SHADER_VARIABLE_BEGIN_FLAG              (VFX_OBJECT3D_END_FLAG)
#define VFX_SHADER_VARIABLE_VALUE_DIRTY             (VFX_SHADER_VARIABLE_BEGIN_FLAG << 1)
#define VFX_SHADER_VARIABLE_BIND_DIRTY              (VFX_SHADER_VARIABLE_BEGIN_FLAG << 2)
#define VFX_SHADER_VARIABLE_END_FLAG                (VFX_SHADER_VARIABLE_BIND_DIRTY)
#define VFX_SHADER_VARIABLE_ALL_DIRTY               (VFX_SHADER_VARIABLE_VALUE_DIRTY | VFX_SHADER_VARIABLE_BIND_DIRTY)


/***************************************************************************** 
 * Class VfxShaderVariable
 *****************************************************************************/

/*
 * VfxShaderVariable is the variable object in 3D material pass.
 */
class VfxShaderVariable : public VfxObject3D
{
// Constructor / Destructor
public:
    // Constructor with variable name, data type, and data count
    VfxShaderVariable(const VfxString &name, VfxTypeIdEnum type, VfxU16 count);
    // Destructor
    virtual ~VfxShaderVariable();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void resetProperty(vrt_object_property_id_enum propertyId);

    virtual void syncData() const;

// Property
public:
    // Get variable name.
    const VfxString &getName() const;

    // Get data type.
    VfxTypeIdEnum getDataType() const;

    // Get data count.
    VfxU16 getDataCount() const;

    // Get data total size.
    VfxU32 getDataSize() const;

    // Get variable data.
    void *getDataPtr() const;

    // Get variable binding.
    VfxObject3D *getBindObj() const;

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_FLOAT.
    void setValue(VfxFloat x);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_S32.
    void setValue(VfxS32 x);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_BOOL.
    void setValue(VfxBool x);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_MAT3.
    void setValue(const VfxMatrix3f &mat);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_MAT4.
    void setValue(const VfxMatrix4f &mat);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_SAMPLER.
    void setValue(VfxTexture *tex);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_VEC2.
    void setValue(VfxFloat x, VfxFloat y);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_IVEC2.
    void setValue(VfxS32 x, VfxS32 y);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_BVEC2.
    void setValue(VfxBool x, VfxBool y);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_VEC3.
    void setValue(VfxFloat x, VfxFloat y, VfxFloat z);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_IVEC3.
    void setValue(VfxS32 x, VfxS32 y, VfxS32 z);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_BVEC3.
    void setValue(VfxBool x, VfxBool y, VfxBool z);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_VEC4.
    void setValue(VfxFloat x, VfxFloat y, VfxFloat z, VfxFloat w);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_IVEC4.
    void setValue(VfxS32 x, VfxS32 y, VfxS32 z, VfxS32 w);

    // Set data value.
    //
    // NOTE: data type must be VFX_TYPE_ID_BVEC4.
    void setValue(VfxBool x, VfxBool y, VfxBool z, VfxBool w);

    // Set data value from const buffer.
    //
    // NOTE: data type must *NOT* be VFX_TYPE_ID_SAMPLER.
    void setValueFromConstBuf(void *values);

    // Set data value from dynamic buffer.
    //
    // NOTE: data type must *NOT* be VFX_TYPE_ID_SAMPLER.
    void setValueFromDynamicBuf(void *values);

    // Read data value from stream.
    //
    // NOTE: data type must *NOT* be VFX_TYPE_ID_SAMPLER.
    void readValueStream(VfxInputStream &is);

    // Bind variable to object property.
    //
    // NOTE: data type must *NOT* be VFX_TYPE_ID_SAMPLER.
    void bindValue(VfxObject3D *obj, VfxVariableBindingProperty property_id);

// Implementation
protected:
    enum VfxVariableType
    {
        VFX_VARIABLE_TYPE_NULL = 0,
        VFX_VARIABLE_TYPE_CONST_BUF,
        VFX_VARIABLE_TYPE_DYNAMIC_BUF,
        VFX_VARIABLE_TYPE_BINDING,
        VFX_VARIABLE_TYPE_END_OF_ENUM
    };

    void changeDataType(const VfxVariableType dataType);

    VfxString m_name;
    union
    {
        void *m_data;
        VfxU8 m_refObjBuffer[sizeof(VfxWeakPtr< VfxObject3D >)];    // Binding object
    };
    VfxU16 m_count;
    VfxTypeIdEnum m_type;
    VfxVariableType m_dataType;
    VfxVariableBindingProperty m_propertyID;        // Binding property
};



/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SHADER_UNIFORMS_BEGIN_FLAG              (VFX_OBJECT3D_END_FLAG)
#define VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY          (VFX_SHADER_UNIFORMS_BEGIN_FLAG << 1)
#define VFX_SHADER_UNIFORMS_END_FLAG                (VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY)
#define VFX_SHADER_UNIFORMS_ALL_DIRTY               (VFX_SHADER_UNIFORMS_UNIFORMS_DIRTY)


/***************************************************************************** 
 * Class VfxShaderUniforms
 *****************************************************************************/

/*
 * VfxShaderUniforms is a collection of shader variables.
 */
class VfxShaderUniforms : public VfxObject3D
{
    VFX_DECLARE_CLASS(VfxShaderUniforms);

// Constructor / Destructor
public:
    // Default constructor
    VfxShaderUniforms();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Add uniform variable by variable name, data type, and data count.
    //
    // RETURNS: Return the created shader variable.
    VfxShaderVariable *addUniformVariable(const VfxString &name, VfxTypeIdEnum type, VfxU16 count);

    // Remove the uniform variable from the uniforms.
    void removeUniformVariable(VfxShaderVariable *variable);

    // Get uniform variable by variable name.
    //
    // RETURNS: Return the shader variable with name.
    //  Return NULL if variable with name is not in the uniforms.
    VfxShaderVariable *getUniformVariable(const VfxString &name) const;

    typedef VfxList<VfxShaderVariable *> VariableList;

    // Get uniform variable list.
    const VariableList &getVariableList() const;

// Implementation
protected:
    
    VariableList m_variables;
};


inline const VfxString &VfxShaderVariable::getName() const
{
    return m_name;
}

inline VfxTypeIdEnum VfxShaderVariable::getDataType() const
{
    return m_type;
}

inline VfxU16 VfxShaderVariable::getDataCount() const
{
    return m_count;
}

inline VfxU32 VfxShaderVariable::getDataSize() const
{
    return vrt_get_size_of_type((vrt_type_id_enum)m_type) * m_count;
}

inline void *VfxShaderVariable::getDataPtr() const
{
    return (m_dataType == VFX_VARIABLE_TYPE_CONST_BUF || m_dataType == VFX_VARIABLE_TYPE_DYNAMIC_BUF) ? m_data : NULL;
}

inline VfxObject3D *VfxShaderVariable::getBindObj() const
{
    return (m_dataType == VFX_VARIABLE_TYPE_BINDING) ? ((VfxWeakPtr< VfxObject3D > *)m_refObjBuffer)->get() : NULL;
}

#endif /* __VFX_SHADER_UNIFORMS_H__ */

