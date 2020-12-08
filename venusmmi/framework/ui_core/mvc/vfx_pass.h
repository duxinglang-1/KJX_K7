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
 *  vfx_pass.h
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
#ifndef __VFX_PASS_H__
#define __VFX_PASS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"
#include "vrt_vector.h"
#include "vfx_weak_ptr.h"
#include "vfx_container.h"
#include "vfx_string.h"
#include "vfx_vector.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_MAX_TESSELLATION_LEVEL          99

#define VFX_PASS_BEGIN_FLAG                 (VFX_OBJECT3D_END_FLAG)
#define VFX_PASS_SHADER_PROGRAM_DIRTY       (VFX_PASS_BEGIN_FLAG << 1)
#define VFX_PASS_SHADER_UNIFORMS_DIRTY      (VFX_PASS_BEGIN_FLAG << 2)
#define VFX_PASS_POLYGON_MODE_DIRTY         (VFX_PASS_BEGIN_FLAG << 3)
#define VFX_PASS_COMPOSITING_MODE_DIRTY     (VFX_PASS_BEGIN_FLAG << 4)
#define VFX_PASS_RENDER_TARGET_DIRTY        (VFX_PASS_BEGIN_FLAG << 5)
#define VFX_PASS_TESSELLATION_LEVEL_DIRTY   (VFX_PASS_BEGIN_FLAG << 6)
#define VFX_PASS_RENDER_MODE_DIRTY          (VFX_PASS_BEGIN_FLAG << 7)
#define VFX_PASS_END_FLAG                   (VFX_PASS_RENDER_MODE_DIRTY)
#define VFX_PASS_ALL_DIRTY                  (VFX_PASS_SHADER_PROGRAM_DIRTY | \
                                             VFX_PASS_SHADER_UNIFORMS_DIRTY | \
                                             VFX_PASS_POLYGON_MODE_DIRTY | \
                                             VFX_PASS_COMPOSITING_MODE_DIRTY | \
                                             VFX_PASS_RENDER_TARGET_DIRTY | \
                                             VFX_PASS_TESSELLATION_LEVEL_DIRTY | \
                                             VFX_PASS_RENDER_MODE_DIRTY)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxRenderMode;
class VfxPolygonMode;
class VfxCompositingMode;
class VfxShaderProgram;
class VfxShaderUniforms;
class VfxShaderVariable;
class VfxRenderTarget;


/***************************************************************************** 
 * Class VfxPass
 *****************************************************************************/

/*
 * VfxPass is the pass object in 3D material.
 */
class VfxPass : public VfxObject3D
{
    VFX_DECLARE_CLASS(VfxPass);

// Constructor / Destructor
public:
    // Default constructor
    VfxPass(VfxPassGeometryType type = VFX_PASS_GEOMETRY_DEFAULT);

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set tessellation level.
    //
    // NOTE: Default values are 1 and 1.
    void setTessellationLevel(VfxU16 uLevel, VfxU16 vLevel);

    // Set tessellation level.
    //
    // NOTE: Default value is (1, 1).
    void setTessellationLevel(VfxVector2us level);

    // Get tessellation level.
    //
    // NOTE: Default value is (1, 1).
    const VrtVector2us &getTessellationLevel() const;

    // Set render mode.
    void setRenderMode(VfxRenderMode *mode);

    // Get render mode.
    VfxRenderMode *getRenderMode() const;

    // Set polygon mode.
    void setPolygonMode(VfxPolygonMode *mode);

    // Get polygon mode.
    VfxPolygonMode *getPolygonMode() const;

    // Set compositing mode.
    void setCompositingMode(VfxCompositingMode *mode);

    // Get compositing mode.
    VfxCompositingMode *getCompositingMode() const;

    // Set shader program.
    void setShaderProgram(VfxShaderProgram *program);

    // Get shader program.
    VfxShaderProgram *getShaderProgram() const;

    // Add shader uniforms to uniform list.
    void addShaderUniforms(VfxShaderUniforms *uniforms);

    // Get uniform variable by name.
    //
    // RETURNS: Return the last variable with name in the uniform list.
    //  Return NULL if variable with name is not in the list.
    VfxShaderVariable *getUniformVariable(const VfxString &name) const;

    // Set render target.
    void setRenderTarget(VfxRenderTarget *rt);

    // Get render target.
    VfxRenderTarget *getRenderTarget() const;

    // Get shader uniform list.
    const VfxList< VfxWeakPtr<VfxShaderUniforms> > &getShaderUniformList() const;

// Implementation
protected:

    VfxWeakPtr< VfxShaderProgram > m_shaderProgram;
    VfxList< VfxWeakPtr< VfxShaderUniforms > > m_shaderUniformsList;
    VfxWeakPtr< VfxRenderMode > m_renderMode;
    VfxWeakPtr< VfxPolygonMode > m_polygonMode;
    VfxWeakPtr< VfxCompositingMode > m_compositingMode;
    VfxWeakPtr< VfxRenderTarget > m_renderTarget;

    VfxVector2us m_tessellationLevel;
    VfxPassGeometryType m_passType;
};


inline void VfxPass::setTessellationLevel(VfxU16 uLevel, VfxU16 vLevel)
{
    setTessellationLevel(VfxVector2us(uLevel, vLevel));    
}

inline const VrtVector2us &VfxPass::getTessellationLevel() const
{
    return m_tessellationLevel;
}

#endif /* __VFX_PASS_H__ */

