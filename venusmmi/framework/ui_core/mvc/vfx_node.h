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
 *  vfx_node.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_NODE_H__
#define __VFX_NODE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_transformable.h"
#include "vfx_weak_ptr.h"
#include "vfx_container.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define VFX_NODE_BEGIN_FLAG             (VFX_TRANSFORMABLE_END_FLAG)
#define VFX_NODE_OPACITY_DIRTY          (VFX_NODE_BEGIN_FLAG << 1)
#define VFX_NODE_VISIBLE_DIRTY          (VFX_NODE_BEGIN_FLAG << 2)
#define VFX_NODE_END_FLAG               (VFX_NODE_VISIBLE_DIRTY)
#define VFX_NODE_ALL_DIRTY              (VFX_NODE_OPACITY_DIRTY | VFX_NODE_VISIBLE_DIRTY)

#define VFX_NODE_FLAG_VISIBLE           (1 << 0)
#define VFX_NODE_FLAG_PICKABLE          (1 << 1)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxNode;
class VfxGroup;
class VfxWorld;
class VfxBoundingVolume;


/***************************************************************************** 
 * Class VfxNodePickReturn
 *****************************************************************************/

class VfxNodePickReturn : public VfxBase
{  
// Variable
public:
    VfxNode *m_node;
    VfxVector3f m_point;

public:
    void clear();
};


/***************************************************************************** 
 * Class VfxNode
 *****************************************************************************/

/*
 * VfxNode is the base node object in 3D scene.
 */
class VfxNode : public VfxTransformable
{
    VFX_DECLARE_CLASS(VfxNode);

    friend class VfxGroup;
public:
    typedef VfxMap< VfxString, VfxWeakPtr< VfxAnimatable > > AnimTargetMap;
    typedef AnimTargetMap::It AnimTargetMapItr;

// Constructor / Destructor
public:
    // Default constructor
    VfxNode();
    // Destructor
    virtual ~VfxNode();

// Override
public:
    virtual void resetProperty(vrt_object_property_id_enum propertyId);

    virtual void syncData() const;

// Property
public:
    // Set node visible.
    void setVisible(VfxBool value);

    // Whether the node is visible.
    VfxBool isVisible() const;

    // Set node pickable.
    void setPickable(VfxBool value);

    // Whether the node is pickable.
    VfxBool isPickable() const;

    // Set node opacity.
    void setOpacity(VfxFloat value);

    // Get node opacity.
    VfxFloat getOpacity() const;

    // Get the parent group.
    VfxGroup *getParentNode() const;

    // Get the world node.
    VfxWorld *getWorld() const;

    // Clear the name/object table for animation loading.
    //
    // SEE ALSO: VfxNode::setTargetLookup, VfxNode::getTargetLookup
    void clearAnimTargetMap();

    // Set or replace an entry in the name/object table for animation loading.
    //
    // RETURNS: Return the replaced object if the entry was already in the table.
    //  Otherwise return NULL.
    //
    // SEE ALSO: VfxAssetLoader::loadScene, VfxAssetLoader::loadSceneBegin
    VfxAnimatable *setTargetLookup(const VfxString &name, VfxAnimatable *objPtr);

    // Get an object by name from the name/object table.
    //
    // RETURNS: Return object by name. Return NULL if object with name cannot be found.
    //
    // SEE ALSO: VfxAssetLoader::loadAnimation
    VfxAnimatable *getTargetLookup(const VfxString &name);

    // Get the world transform of the node.
    void getWorldTransform(
        VfxMatrix4f &worldMatrix    // [OUT] world transform matrix
    ) const;

    // Get the world position of the node.
    void getWorldPosition(
        VfxVector3f &worldPosition  // [OUT] world position vector
    ) const;

    // Set the bounding volume of the node.
    void setBoundingVolume(const VfxBoundingVolume &value);

    // Get the bounding volume of the node.
    //
    // RETURNS: Return the bounding volume. Return NULL if the bounding volume is never set.
    const VfxBoundingVolume *getBoundingVolume() const;

    // Change the node to the last one of group's child node.
    void bringToFront();

    // Change the node to the first one of group's child node.
    void sendToBack();

    // Return the pickable node containing the specified ray, including this node.
    //
    // RETURNS: Return the node that is intersected with the given ray.
    VfxNode *pick(
        const VfxVector3f &rayOrigin,       // [IN] testing ray origin on this node coordiate
        const VfxVector3f &rayDirection     // [IN] testing ray direction on this node coordiate
    ) const;

    // Return the pickable node containing the specified ray, including this node.
    void pick(
        VfxNodePickReturn &ret,             // [OUT] pick return data
        const VfxVector3f &rayOrigin,       // [IN] testing ray origin on this node coordiate
        const VfxVector3f &rayDirection     // [IN] testing ray direction on this node coordiate
    ) const;

// Overridable
protected:
    // Process picking test and find the picked node, from this node.
    virtual void processPick(
        VfxNodePickReturn &ret,             // [OUT] pick return data
        const VfxVector3f &rayOrigin,       // [IN] testing ray origin on this node coordiate
        const VfxVector3f &rayDirection     // [IN] testing ray direction on this node coordiate
    ) const;

// Override
protected:
    virtual void onDeinit();
    void onAfterDeinit();
    virtual void onObjectNotify(VfxId eventId, void *userData);

// Implementation
protected:
    VfxNode *getRootNode() const;

    // Internal used. Set the parent node.
    void setParentNode(VfxGroup *parent);

    AnimTargetMap *getAnimTargetMap();

    VfxWeakPtr <VfxGroup> m_parent;
    VfxBoundingVolume *m_boundingVolume;

    VfxFloat m_opacity;
    VfxFlag m_nodeFlags;
};


#endif /* __VFX_NODE_H__ */

