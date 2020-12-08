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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_asset_loader.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_ASSET_LOADER_H__
#define __VFX_ASSET_LOADER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_datatype.h"
#include "vfx_object_3d.h"
#include "vfx_weak_ptr.h"
#include "vfx_container.h"
#include "vfx_string.h"

#include "vrt_asset_file.h"

#include "vadp_sys_trc.h"


/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Asset index type
typedef vrt_obj_index_type      VfxAssetIndexType;
// Asset file custom data
typedef vrt_file_custom_data    VfxAssetFileDataStruct;

class VfxInputStream;
class VfxMemIstream;
class VfxFileIstream;
class VfxAssetSrc;

class VfxMesh;
class VfxSkinnedMesh;
class VfxMaterial;
class VfxPolygonMode;
class VfxBlender;
class VfxStencil;
class VfxCompositingMode;
class VfxShaderProgram;
class VfxTexture;
class VfxShaderVariable;
class VfxShaderUniforms;
class VfxRenderTarget;
class VfxPass;
class VfxNode;
class VfxGroup;
class VfxBone;
class VfxCamera;
class VfxLight;
class VfxKeyframeTimeline;
class VfxAnimation;

// Asset loader type
enum VfxAssetLoaderSrcTypeEnum
{
    VFX_ASSET_LOADER_SRC_TYPE_NULL = 0,        // Null asset
    VFX_ASSET_LOADER_SRC_TYPE_RES_ID,          // Asset from resource ID
    VFX_ASSET_LOADER_SRC_TYPE_PATH,            // Asset from file path

    VFX_ASSET_LOADER_SRC_TYPE_END_OF_ENUM
};

/***************************************************************************** 
 * Class VfxAssetLoader
 *****************************************************************************/

/*
 * VfxAssetLoader is used to load 3D asset
 */
class VfxAssetLoader : public VfxBase
{
// Method
public:
    // Load geometry into mesh from resource.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadMesh(
        VfxMesh *mesh,
        const VfxResId resId
    );

    // Load geometry into mesh from file.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadMesh(
        VfxMesh *mesh,
        const VfxWString &filename
    );

    // Load geometry into skinned mesh from resource.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadSkinnedMesh(
        VfxSkinnedMesh *mesh,
        const VfxResId resid
    );

    // Load geometry into skinned mesh from file.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadSkinnedMesh(
        VfxSkinnedMesh *mesh,
        const VfxWString &filename
    );

    // Load material settings from resource.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadMaterial(
        VfxMaterial *mtl,
        const VfxResId resId
    );

    // Load material settings from file.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadMaterial(
        VfxMaterial *mtl,
        const VfxWString &filename
    );

    // Load 3D scene group from resource.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadAnimation
    static VfxBool loadScene(
        VfxGroup *root,
        const VfxResId resId,
        VfxBool createTargetLookup = VFX_TRUE,  // [IN] create name/object table for animation loading
        VfxBool createBindingLookup = VFX_FALSE // [IN] create var_name/binding table for post-binding
    );

    // Load 3D scene group from file.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadAnimation
    static VfxBool loadScene(
        VfxGroup *root,
        const VfxWString &filename,
        VfxBool createTargetLookup = VFX_TRUE,  // [IN] create name/object table for animation loading
        VfxBool createBindingLookup = VFX_FALSE // [IN] create var_name/binding table for post-binding
    );

    // Load keyframe sequence into timeline from resource.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadKeyframe(
        VfxKeyframeTimeline *kft,
        const VfxResId resId
    );

    // Load keyframe sequence into timeline from file.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    static VfxBool loadKeyframe(
        VfxKeyframeTimeline *kft,
        const VfxWString &filename
    );

    // Load animation onto 3D scene from resource, base on the name/object table in node.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadScene
    static VfxBool loadAnimation(
        VfxAnimation *anim,
        VfxNode *node,              // [IN] node with the name/object table for the loading to be based on
        const VfxResId resId
    );

    // Load animation onto 3D scene from file, base on the name/object table in node.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadScene
    static VfxBool loadAnimation(
        VfxAnimation *anim,
        VfxNode *node,              // [IN] node with the name/object table for the loading to be based on
        const VfxWString &filename
    );

    // Begin loading 3D scene group from resource.
    //
    // NOTE: Must call loadSceneEnd afterward to finish loading.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneEnd, VfxAssetLoader::loadScene, VfxAssetLoader::findObjByName
    static VfxBool loadSceneBegin(
        VfxGroup *root,
        const VfxResId resId,
        VfxBool createTargetLookup = VFX_TRUE,  // [IN] create name/object table for animation loading
        VfxBool createBindingLookup = VFX_FALSE // [IN] create var_name/binding table for post-binding
    );

    // Begin loading 3D scene group from file.
    //
    // NOTE: Must call loadSceneEnd afterward to finish loading.
    //
    // RETURNS: Return VFX_TRUE if loading is succeeded.
    //  Otherwise return VFX_FALSE.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneEnd, VfxAssetLoader::loadScene, VfxAssetLoader::findObjByName
    static VfxBool loadSceneBegin(
        VfxGroup *root,
        const VfxWString &filename,
        VfxBool createTargetLookup = VFX_TRUE,  // [IN] create name/object table for animation loading
        VfxBool createBindingLookup = VFX_FALSE // [IN] create var_name/binding table for post-binding
    );

    // End loading 3D scene group.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadScene
    static void loadSceneEnd();

    // Find object by name from the loading 3D scene.
    //
    // NOTE: Must be called between a successful loadSceneBegin and loadSceneEnd.
    //
    // RETURNS: Return object by name. Return NULL if object with name cannot be found.
    //
    // SEE ALSO: VfxAssetLoader::loadSceneBegin, VfxAssetLoader::loadSceneEnd
    static VfxObject3D *findObjByName(const VfxString &name);

// Implementation
private:

    static VfxAssetLoader   *s_curSceneLoader;

    static VfxAssetIndexType loadMeshImp(VfxMesh *mesh, const VfxResId resId);
    static VfxAssetIndexType loadMeshImp(VfxMesh *mesh, const VfxWString &filename);
    static VfxAssetIndexType loadMeshImp(VfxMesh *mesh, const VfxAssetSrc &source);
    static VfxAssetIndexType loadMaterialImp(VfxMaterial *mtl, const VfxResId resId);
    static VfxAssetIndexType loadMaterialImp(VfxMaterial *mtl, const VfxWString &filename);
    static VfxAssetIndexType loadMaterialImp(VfxMaterial *mtl, const VfxAssetSrc &source);
    static VfxAssetIndexType loadKeyframeImp(VfxKeyframeTimeline *kft, const VfxResId resId);
    static VfxAssetIndexType loadKeyframeImp(VfxKeyframeTimeline *kft, const VfxWString &filename);
    static VfxAssetIndexType loadAnimationImp(VfxAnimation *anim, VfxNode *node, const VfxResId resId);
    static VfxAssetIndexType loadAnimationImp(VfxAnimation *anim, VfxNode *node, const VfxWString &filename);
    static VfxAssetIndexType loadSceneBeginImp(
        VfxGroup *root, const VfxResId resId, VfxBool createTargetLookup, VfxBool createBindingLookup);
    static VfxAssetIndexType loadSceneBeginImp(
        VfxGroup *root, const VfxWString &filename, VfxBool createTargetLookup, VfxBool createBindingLookup);
    static void              loadSceneEndImp();

    VfxObject3D             *findObjByNameImp(const VfxString &name) const;

    class NameTableEntry : public VfxBase
    {
    public:
        NameTableEntry *next;
        VfxString       name;
        VfxWeakPtr< VfxObject3D > objPtr;
    };

    class AssetMapEntry : public VfxBase
    {
    public:
        ////VfxWString          name;
        //VfxAssetIndexType   index;
        VfxObjWeakPtr       objPtr;
        VfxS32              refCnt;
    };

    typedef VfxArray< AssetMapEntry > VfxAssetObjectMap;

    VfxInputStream     &m_is;
    VfxWString          m_folder;
    VfxAssetObjectMap   m_objMap;
    NameTableEntry     *m_nameTableHead;

    // asset from res or file, use const string if res
    VfxAssetLoaderSrcTypeEnum m_type;
    
    // the memory pointer if m_type == res
    const VfxU8 *m_mem;

    // constructor
    VfxAssetLoader(VfxFileIstream &is, const VfxWString &filename);
    VfxAssetLoader(VfxMemIstream &is, const VfxResId &resId);

    // destructor
    ~VfxAssetLoader();

    // read variable-length type
    void                readString(VfxString &str);
    void                readWString(VfxWString &wstr);
    void                readReference(VfxAssetSrc &ref, VfxAssetFileDataStruct *data = NULL);
    void                normalizePath(VfxWString &path);

    // create look-up table
    void                addNameTableEntry(const VfxString &name, VfxObject3D *objPtr);
    void                clearNameTable();
    void                createAnimTargetMap(VfxNode *node);

    // cache object
    void                addAssetMapEntry(const VfxAssetIndexType &index, VfxObject *objPtr);
    void                clearAssetMap();

    // get cached object
    VfxObject          *getAssetMapObject(const VfxAssetIndexType &index, const VfxClassInfo *type, VfxS32 &shared);
    VfxObject3D        *getObject3DFromMap(const VfxAssetIndexType &index);
    VfxShaderProgram   *getProgramFromMap(const VfxAssetIndexType &index);
    VfxTexture         *getTextureFromMap(const VfxAssetIndexType &index);
    VfxShaderUniforms  *getUniformsFromMap(const VfxAssetIndexType &index);
    VfxRenderTarget    *getRenderTargetFromMap(const VfxAssetIndexType &index);
    VfxPass            *getPassFromMap(const VfxAssetIndexType &index);
    VfxCamera          *getCameraFromMap(const VfxAssetIndexType &index);
    VfxNode            *getNodeFromMap(const VfxAssetIndexType &index);
    VfxGroup           *getGroupFromMap(const VfxAssetIndexType &index);
    VfxBone            *getBoneFromMap(const VfxAssetIndexType &index);
    VfxSkinnedMesh     *getSkinnedMeshFromMap(const VfxAssetIndexType &index);
    VfxBaseTimeline    *getTimelineFromMap(const VfxAssetIndexType &index);

    // load object stream
    VfxAssetIndexType   loadFromStream(VfxObject *obj, VfxNode *ref = NULL);
    VfxAssetIndexType   loadSceneFromStream(VfxGroup *root, VfxBool createBindingLookup);

    // parse object data
    VfxBool             parseMesh(VfxMesh *mesh);
    VfxBool             parseSkinnedMesh(VfxSkinnedMesh *mesh);
    VfxBool             parseMaterial(VfxMaterial *material);
    VfxBool             parseSceneInfo(VfxGroup *root);
    VfxBool             parseTimeline(VfxKeyframeTimeline *timeline);
    VfxBool             parseAnimation(VfxAnimation *anim, VfxNode *node);

    // parse node object and create node on demand
    VfxBool             parseAndCreateNode(VfxNode **ppnode, const VfxClassInfo *type);

    // create object with owner
    //VfxMesh            *createMesh(VfxGroup *owner);
    VfxPolygonMode     *createPolygonMode(VfxObject *owner);
    VfxBlender         *createBlender(VfxObject *owner);
    VfxStencil         *createStencil(VfxObject *owner);
    VfxCompositingMode *createCompositingMode(VfxObject *owner);
    VfxShaderProgram   *createShaderProgram(VfxObject *owner);
    VfxTexture         *createTexture(VfxObject *owner);
    VfxShaderUniforms  *createShaderUniforms(VfxObject *owner);
    VfxRenderTarget    *createRenderTarget(VfxObject *owner);
    VfxPass            *createPass(VfxObject *owner);
    //VfxMaterial        *createMaterial(VfxObject *owner);

    // create object in scene graph
    VfxGroup           *createGroupNode(const VfxClassInfo *type);
    VfxCamera          *createCameraNode();
    VfxLight           *createLightNode();
    VfxMesh            *createMeshNode(VfxGroup *mtlowner, const VfxClassInfo *type);
    VfxShaderUniforms  *createShaderBindings(VfxGroup *root, VfxBool createLookup);

};


#endif /* __VFX_ASSET_LOADER_H__ */

