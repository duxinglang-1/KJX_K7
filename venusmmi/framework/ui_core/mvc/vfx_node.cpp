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
 *  vfx_node.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_node.h"
#include "vfx_group.h"
#include "vfx_world.h"
#include "vrt_3d.h"
#include "vfx_bounding_volume.h"
#include "vfx_auto_animate.h"


/***************************************************************************** 
 * Global function
 *****************************************************************************/
 
extern "C" vrt_timeline_handle vrt_animatable_search_property_timeline(
    vrt_object_handle object_handle, 
    vrt_object_property_id_enum property_id);


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

/***************************************************************************** 
 * Class VfxNodePickReturn
 *****************************************************************************/
 
void VfxNodePickReturn::clear()
{
    m_node = NULL;
    m_point = VfxVector3f();
}


/***************************************************************************** 
 * Class VfxNode
 *****************************************************************************/

#define VFX_NODE_PROP_ID_ANIM_TARGET_MAP    0x1020101

VFX_IMPLEMENT_VIRTUAL_CLASS("Node", VfxNode, VfxTransformable);

VfxNode::VfxNode(): 
    m_parent(NULL), 
    m_boundingVolume(NULL),
    m_opacity(1.0f),
    m_nodeFlags(VFX_TRUE)
{
}


VfxNode::~VfxNode()
{
    VFX_DELETE(m_boundingVolume);
}


VfxGroup *VfxNode::getParentNode() const
{
    return m_parent.get();
}


VfxNode *VfxNode::getRootNode() const
{
    VfxNode *root = const_cast <VfxNode *> (this);
    VfxGroup *parent = root->getParentNode();
    while (parent != NULL)
    {
        root = parent;
        parent = root->getParentNode();
    }
    return root;
}


VfxWorld *VfxNode::getWorld() const
{
    VfxNode *root = getRootNode();
    return VFX_OBJ_DYNAMIC_CAST(root, VfxWorld);
}


void VfxNode::onDeinit()
{
    clearAnimTargetMap();

    VfxTransformable::onDeinit();
}


void VfxNode::onAfterDeinit()
{
    // remove from parent node
    VfxGroup *parent = getParentNode();
    if (parent)
    {
        parent->removeChildNode(this);
    }
    
    VfxTransformable::onAfterDeinit();
}


void VfxNode::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT:
        {
            onAfterDeinit();
            return;
        }
        default:
        {
            VfxTransformable::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxNode::resetProperty(vrt_object_property_id_enum propertyId)
{
    switch (propertyId)
    {
    case VRT_NODE_PROPERTY_ID_OPACITY:
        setPropertyDirty(VFX_NODE_OPACITY_DIRTY);
        break;
    default:
        VfxTransformable::resetProperty(propertyId);
    }
}


void VfxNode::syncData() const
{
    VfxTransformable::syncData();

    /* Find if there is a property timeline exist */
    vrt_object_handle object_handle = getSyncHandle();
    vrt_timeline_handle timeline = vrt_animatable_search_property_timeline(object_handle, VRT_NODE_PROPERTY_ID_OPACITY);
    if (isPropertyDirty(VFX_NODE_OPACITY_DIRTY) && (timeline == NULL))
    {
        vrt_node_set_opacity(m_handle, m_opacity);
    }

    if (isPropertyDirty(VFX_NODE_VISIBLE_DIRTY))
    {
        vrt_node_set_visible(m_handle, VFX_FLAG_HAS(m_nodeFlags, VFX_NODE_FLAG_VISIBLE));
    }

    clearPropertyDirty(VFX_NODE_ALL_DIRTY);
}


void VfxNode::setVisible(VfxBool value)
{
    value ?
        VFX_FLAG_SET(m_nodeFlags, VFX_NODE_FLAG_VISIBLE) :
        VFX_FLAG_CLEAR(m_nodeFlags, VFX_NODE_FLAG_VISIBLE);
    setPropertyDirty(VFX_NODE_VISIBLE_DIRTY);
}


VfxBool VfxNode::isVisible() const
{
    return VFX_FLAG_HAS(m_nodeFlags, VFX_NODE_FLAG_VISIBLE);
}


void VfxNode::setPickable(VfxBool value)
{
    value ?
        VFX_FLAG_SET(m_nodeFlags, VFX_NODE_FLAG_PICKABLE) :
        VFX_FLAG_CLEAR(m_nodeFlags, VFX_NODE_FLAG_PICKABLE);
}


VfxBool VfxNode::isPickable() const
{
    return VFX_FLAG_HAS(m_nodeFlags, VFX_NODE_FLAG_PICKABLE);
}


void VfxNode::setOpacity(VfxFloat value)
{
    if (getOpacity() != value)
    {
        /* auto animation */
        vrt_float fromValue = getOpacity();
        vrt_float vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_NODE_PROPERTY_ID_OPACITY,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        m_opacity = value;

        setPropertyDirty(VFX_NODE_OPACITY_DIRTY);
    }
}


VfxFloat VfxNode::getOpacity() const
{
    return m_opacity;
}


void VfxNode::setParentNode(VfxGroup *parent)
{
    m_parent = parent;
}


/* animation target hash table */
VfxNode::AnimTargetMap *VfxNode::getAnimTargetMap()
{
    AnimTargetMap **ppmap = (AnimTargetMap**)getAttachProperty(VFX_NODE_PROP_ID_ANIM_TARGET_MAP, sizeof(AnimTargetMap*));
    if (ppmap)
    {
        return *ppmap;
    }
    else
    {
        AnimTargetMap *pmap;
        VFX_ALLOC_NEW(pmap, AnimTargetMap, this);
        pmap->init(this);
        setAttachProperty(VFX_NODE_PROP_ID_ANIM_TARGET_MAP, &pmap, sizeof(AnimTargetMap*));
        return pmap;
    }
}


void VfxNode::clearAnimTargetMap()
{
    AnimTargetMap **ppmap = (AnimTargetMap**)getAttachProperty(VFX_NODE_PROP_ID_ANIM_TARGET_MAP, sizeof(AnimTargetMap*));
    if (ppmap)
    {
        VFX_DELETE(*ppmap);
        setAttachProperty(VFX_NODE_PROP_ID_ANIM_TARGET_MAP, NULL, 0);
    }
}


VfxAnimatable *VfxNode::setTargetLookup(const VfxString &name, VfxAnimatable *objPtr)
{
    VFX_DEV_ASSERT(!name.isEmpty());

    AnimTargetMap *pmap = getAnimTargetMap();
    AnimTargetMapItr iter = pmap->find(name);
    VfxAnimatable *old = NULL;

    if (iter != pmap->end())
    {
        old = iter.getValue().get();
    }

    if (objPtr)
    {
        if (iter != pmap->end())
        {
            iter.getValue() = objPtr;
        }
        else
        {
            pmap->insert(name, objPtr);
        }
    }
    else
    {
        pmap->erase(iter);
    }

    if (pmap->empty())
    {
        clearAnimTargetMap();
    }

    return old;
}


VfxAnimatable *VfxNode::getTargetLookup(const VfxString &name)
{
    VFX_DEV_ASSERT(!name.isEmpty());

    AnimTargetMap *pmap = getAnimTargetMap();
    AnimTargetMapItr iter = pmap->find(name);
    VfxAnimatable *objPtr = NULL;

    if (iter != pmap->end())
    {
        objPtr = iter.getValue().get();
    }

    return objPtr;
}


void VfxNode::getWorldTransform(VfxMatrix4f &worldMatrix) const
{
    getTransform(worldMatrix);

    const VfxGroup *parent = getParentNode();
    while (parent)
    {
        VfxMatrix4f parentMatrix;
        parent->getTransform(parentMatrix);
        worldMatrix = parentMatrix * worldMatrix;
        parent = parent->getParentNode();
    }
}


void VfxNode::getWorldPosition(VfxVector3f &worldPosition) const
{
    VfxMatrix4f worldMatrix;
    getWorldTransform(worldMatrix);
    worldPosition = worldMatrix[3].xyz();
}


void VfxNode::setBoundingVolume(const VfxBoundingVolume &value)
{
    VFX_DELETE(m_boundingVolume);

    VFX_ALLOC_NEW_EX(m_boundingVolume, VfxBoundingVolume, this, (value));
}


const VfxBoundingVolume *VfxNode::getBoundingVolume() const
{
    return m_boundingVolume;
}


VfxNode *VfxNode::pick(const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    VfxNodePickReturn ret;
    processPick(ret, rayOrigin, rayDirection);
    return ret.m_node;
}


void VfxNode::pick(VfxNodePickReturn &ret, const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    processPick(ret, rayOrigin, rayDirection);
}


void VfxNode::processPick(VfxNodePickReturn &ret, const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    if (!VFX_FLAG_HAS_ALL(m_nodeFlags, VFX_NODE_FLAG_VISIBLE | VFX_NODE_FLAG_PICKABLE) ||
        m_boundingVolume == NULL ||
        !m_boundingVolume->intersectWithDirRay(rayOrigin, rayDirection))
    {
        ret.clear();
        return;
    }

    ret.m_node = const_cast <VfxNode *> (this);
    ret.m_point = m_boundingVolume->m_center;
}


void VfxNode::bringToFront()
{
    VfxGroup *parent = getParentNode();
    if (parent == NULL)
    {
        // Do nothing if there is no parent
        return;
    }

    parent->removeChildNode(this);
    parent->addChildNode(this);
}


void VfxNode::sendToBack()
{
    VfxGroup *parent = getParentNode();
    if (parent == NULL)
    {
        // Do nothing if there is no parent
        return;
    }
    
    parent->removeChildNode(this);
    parent->addChildNodeToFirst(this);
}

#pragma arm section code, rodata
