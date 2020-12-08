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
 *  vfx_mesh.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_MESH_H__
#define __VFX_MESH_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_node.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vfx_container.h"
#include "vfx_weak_ptr.h"
#include "vfx_asset_src.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_MESH_BEGIN_FLAG             (VFX_NODE_END_FLAG)
#define VFX_MESH_MATERIAL_DIRTY         (VFX_MESH_BEGIN_FLAG << 1)
#define VFX_MESH_VISIBILITY_DIRTY       (VFX_MESH_BEGIN_FLAG << 2)
#define VFX_MESH_END_FLAG               VFX_MESH_VISIBILITY_DIRTY
#define VFX_MESH_ALL_DIRTY              (VFX_MESH_MATERIAL_DIRTY | VFX_MESH_VISIBILITY_DIRTY)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefine Classes
class VfxMaterial;
class VfxImageText;
class VfxTexture2D;
class VfxShaderVariable;


/***************************************************************************** 
 * Class VfxMesh
 *****************************************************************************/

/*
 * VfxMesh is the mesh object in 3D scene.
 */
class VfxMesh : public VfxNode
{
    VFX_DECLARE_CLASS(VfxMesh);

// Constructor / Destructor
public:
    // Default constructor
    VfxMesh(VfxU32 subMeshCount = 1);

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Internal used. Set geometry data resource ID.
    void setResId(VfxResId resId);

    // Internal used. Set geometry data path.
    void setPath(const VfxWString &path);

    // Get geometry data resource ID.
    VfxResId getResId() const;

    // Get geometry data path.
    const VfxWString &getPath() const;

    // Internal used. Set sub-mesh count of the mesh.
    void setSubMeshCount(VfxU32 count);

    // Get sub-mesh count of the mesh.
    VfxU32 getSubMeshCount() const;

    // Set the material of the idx-th sub-mesh.
    void setMaterial(VfxU32 idx, VfxMaterial *material);

    // Get the material of the idx-th sub-mesh.
    VfxMaterial *getMaterial(VfxU32 idx) const;

    // Set the visibility of the idx-th sub-mesh.
    void setSubMeshVisible(VfxU32 idx, VfxBool value);

    // Get the visibility of the idx-th sub-mesh.
    VfxBool isSubMeshVisible(VfxU32 idx) const;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// Implementation
protected:
    VfxAssetSrc m_assetSrc;
    
    typedef VfxArray< VfxWeakPtr< VfxMaterial > > MaterialList;
    MaterialList m_materials;

    VfxArray< VfxBool > m_invisibilities;
};


/***************************************************************************** 
 * Class VfxPlaneMesh
 *****************************************************************************/

/*
 * VfxPlaneMesh is a plane mesh object in 3D scene.
 */
class VfxPlaneMesh : public VfxMesh
{
// Constructor / Destructor
public:
    // Default constructor
    VfxPlaneMesh(VfxFloat size = 1.0f);
    // Constructor with width and height
    VfxPlaneMesh(VfxFloat width, VfxFloat height);

// Property
public:
    // Get width.
    VfxFloat getWidth() const;
    // Get height.
    VfxFloat getHeight() const;

// Override
public:
    virtual void createHandle() const;

// Implementation
protected:
    VfxFloat m_width;
    VfxFloat m_height;
};


/***************************************************************************** 
 * Class VfxBoxMesh
 *****************************************************************************/

/*
 * VfxBoxMesh is a box mesh object in 3D scene.
 */
class VfxBoxMesh : public VfxMesh
{
// Constructor / Destructor
public:
    // Default constructor
    VfxBoxMesh(VfxFloat size = 1.0f);
    // Constructor with length, width, and height
    VfxBoxMesh(VfxFloat length, VfxFloat width, VfxFloat height);

// Override
public:
    virtual void createHandle() const;

// Implementation
protected:
    VfxFloat m_length;
    VfxFloat m_width;
    VfxFloat m_height;
};


/***************************************************************************** 
 * Class VfxSphereMesh
 *****************************************************************************/

/*
 * VfxSphereMesh is a spheric mesh object in 3D scene.
 */
class VfxSphereMesh : public VfxMesh
{
// Constructor / Destructor
public:
    // Default constructor
    VfxSphereMesh(VfxFloat radius = 1.0f);

// Override
public:
    virtual void createHandle() const;

// Implementation
protected:
    VfxFloat m_radius;        
};


/***************************************************************************** 
 * Class VfxProceduralMesh
 *****************************************************************************/

/*
 * VfxProceduralMesh is a custom mesh object in 3D scene.
 */
class VfxProceduralMesh : public VfxMesh, public IVrtProceduralMesh
{
// Constructor / Destructor
public:
    // Default constructor
    VfxProceduralMesh();

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Text mesh align modes */
enum VfxTextMeshAlignModeEnum
{
    VFX_TEXT_MESH_ALIGN_MODE_NATUAL = 0,
    VFX_TEXT_MESH_ALIGN_MODE_LEFT,
    VFX_TEXT_MESH_ALIGN_MODE_RIGHT,
    VFX_TEXT_MESH_ALIGN_MODE_CENTER,
    VFX_TEXT_MESH_ALIGN_MODE_END_OF_ENUM
};

/* Text mesh v-align modes */
enum VfxTextMeshValignModeEnum
{
    VFX_TEXT_MESH_VALIGN_MODE_CENTER = 0,
    VFX_TEXT_MESH_VALIGN_MODE_TOP,
    VFX_TEXT_MESH_VALIGN_MODE_BOTTOM,
    VFX_TEXT_MESH_VALIGN_MODE_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxTextMesh
 *****************************************************************************/

/*
 * VfxTextMesh is a text mesh object in 3D scene.
 */
class VfxTextMesh : public VfxPlaneMesh
{
// Constructor / Destructor
public:
    // Constructor with properties
    VfxTextMesh(
        VfxFloat w, 
        VfxFloat h, 
        const VfxWString &text, 
        VfxFloat lineHeight = 0,
        VfxTextMeshAlignModeEnum alignMode = VFX_TEXT_MESH_ALIGN_MODE_CENTER,
        VfxTextMeshValignModeEnum valignMode = VFX_TEXT_MESH_VALIGN_MODE_CENTER
    );

// Property
public:
    // Set string.
    void setString(const VfxWString &value);
    // Set font.
    void setFont(const VfxFontDesc &value);
    // Set text color.
    void setTextColor(const VfxColor &value);
    // Set text border color.
    void setTextBorderColor(const VfxColor &value);
    // Set background color.
    void setBackgroundColor(const VfxColor &value);

    // Get string.
    const VfxWString &getString() const;
    // Get font.
    const VfxFontDesc &getFont() const;

// Impelementation
protected:
    void setup(VfxFloat w, VfxFloat h, const VfxWString &text, const VfxFontDesc &font);
    void layout();

    const VfxFloat m_lineHeight;
    const VfxTextMeshAlignModeEnum m_alignMode;
    const VfxTextMeshValignModeEnum m_valignMode;

    VfxImageText *m_textImage;    
    VfxTexture2D *m_texture;
    VfxShaderVariable *m_svTexCoordScale;
    VfxShaderVariable *m_svTexCoordBias;
};

#endif /* __VFX_MESH_H__ */

