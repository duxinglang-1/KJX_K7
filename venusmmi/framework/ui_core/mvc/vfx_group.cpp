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
 *  vfx_group.cpp
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

#include "vfx_group.h"
#include "vfx_material.h"
#include "vrt_3d.h"

#include "vfx_matrix.h"


/***************************************************************************** 
 * Class VfxGroup
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_CLASS("VfxGroup", VfxGroup, VfxNode);

VfxGroup::VfxGroup()
: m_material(NULL)
{
    m_children.init(this);
}


VfxGroup::~VfxGroup()
{
    removeAllChildNodes();
}


void VfxGroup::createHandle() const
{
    m_handle = vrt_create_group();
}


void VfxGroup::disposeHandle() const
{
    if (m_handle)
    {
        NodeList::ConstIt itr;
        for (itr = m_children.begin(); itr != m_children.end(); ++itr)
        {
            VfxNode *node = itr->get();
            VFX_DEV_ASSERT(node);
            node->disposeHandle();
        }

        VfxMaterial *material = m_material.get();
        if (material)
        {
            material->disposeHandle();
        }

        VfxNode::disposeHandle();
    }
}


void VfxGroup::syncData() const
{
    VfxNode::syncData();

    if (isPropertyDirty(VFX_GROUP_CHILDREN_DIRTY))
    {
        vrt_group_remove_all_children(m_handle);
    }

    NodeList::ConstIt itr;
    for (itr = m_children.begin(); itr != m_children.end(); ++itr)
    {
        VfxNode *node = itr->get();
        VFX_DEV_ASSERT(node);
        if (isPropertyDirty(VFX_GROUP_CHILDREN_DIRTY))
        {
            vrt_group_add_child(m_handle, node->getSyncHandle());
        }
        node->syncData();
    }

    /* material */
    VfxMaterial *material = m_material.get();
    if (isPropertyDirty(VFX_GROUP_MATERIAL_DIRTY))
    {
        vrt_group_set_material(m_handle, material ? material->getSyncHandle() : NULL);
    }
    if (material)
    {
        material->syncData();
    }

    clearPropertyDirty(VFX_GROUP_ALL_DIRTY);
}


void VfxGroup::setMaterial(VfxMaterial *material)
{
    m_material = material;
    setPropertyDirty(VFX_GROUP_MATERIAL_DIRTY);
}


VfxMaterial *VfxGroup::getMaterial() const
{
    return m_material.get();
}


void VfxGroup::addChildNode(VfxNode *node)
{
    m_children.pushBack(node);
    node->setParentNode(this);

    setPropertyDirty(VFX_GROUP_CHILDREN_DIRTY);
}

void VfxGroup::addChildNodeToFirst(VfxNode *node)
{
    m_children.pushFront(node);
    node->setParentNode(this);

    setPropertyDirty(VFX_GROUP_CHILDREN_DIRTY);
}


void VfxGroup::removeChildNode(VfxNode *node)
{
    NodeList::It itr = m_children.find(node);
    if (!itr.isNull())
    {
        m_children.erase(itr);
        node->setParentNode(NULL);
    }

    setPropertyDirty(VFX_GROUP_CHILDREN_DIRTY);
}


void VfxGroup::removeAllChildNodes()
{
    NodeList::It itr;
    for (itr = m_children.begin(); itr != m_children.end(); ++itr)
    {
        (*itr)->setParentNode(NULL);
    }
    m_children.clear();

    setPropertyDirty(VFX_GROUP_CHILDREN_DIRTY);
}


void VfxGroup::insertChildNode(VfxNode *child, VfxNode *node)
{
    NodeList::It itr = m_children.find(child);
    if (!itr.isNull())
    {
        m_children.insert(itr, node);
        node->setParentNode(this);
    }

    setPropertyDirty(VFX_GROUP_CHILDREN_DIRTY);
}


const VfxGroup::NodeList &VfxGroup::getChildren() const
{
    return m_children;
}


void VfxGroup::onAddChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxNode *childNode = VFX_OBJ_DYNAMIC_CAST(objChild, VfxNode);
    if (childNode != NULL)
    {
        addChildNode(childNode);
    }
}


void VfxGroup::onRemoveChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxNode *childNode = VFX_OBJ_DYNAMIC_CAST(objChild, VfxNode);
    if (childNode != NULL)
    {
        removeChildNode(childNode);
    }
}


void VfxGroup::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            onAddChild((VfxObject *)userData);
            return;
        }

        case VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD:
        {
            onRemoveChild((VfxObject *)userData);
            return;
        }
        default:
        {
            VfxNode::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxGroup::processPick(VfxNodePickReturn &ret, const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    VfxFloat nearestPickDistance = 0.0f;

    ret.clear();

    NodeList::ConstIt itr;
    for (itr = m_children.begin(); itr != m_children.end(); itr++)
    {
        VfxNode *child = itr->get();
        if (child == NULL)
        {
            continue;
        }

        VfxMatrix4f childTransform;
        child->forceGetTransform(childTransform);
        VfxMatrix4f childTransformInverse;
        childTransformInverse = inverse(childTransform);
            
        VfxVector4f childRayOrigin = childTransformInverse * VfxVector4f(rayOrigin, 1.0f);
        VfxVector4f childRayDirection = childTransformInverse * VfxVector4f(rayDirection, 0.0f);

        VfxNodePickReturn pickRet;
        child->pick(pickRet, childRayOrigin.xyz(), childRayDirection.xyz());
        if (pickRet.m_node == NULL)
        {
            continue;
        }

        VfxVector3f pickPoint = 
            (childTransform * VfxVector4f(pickRet.m_point, 1.0f)).xyz() - rayOrigin;
        VfxFloat pickDistance = dot(rayDirection, pickPoint);
        
        if (ret.m_node == NULL || pickDistance < nearestPickDistance)
        {
            nearestPickDistance = pickDistance;
            ret.m_node = pickRet.m_node;
            ret.m_point = pickPoint;
        }
    }

    // Pick a child node
    if (ret.m_node != NULL)
    {
        return;
    }

    // Try to pick the Group
    VfxNode::processPick(ret, rayOrigin, rayDirection);
}

#pragma arm section code, rodata
