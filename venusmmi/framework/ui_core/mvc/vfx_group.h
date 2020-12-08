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
 *  vfx_group.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_GROUP_H__
#define __VFX_GROUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_node.h"
#include "vfx_container.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define VFX_GROUP_BEGIN_FLAG            (VFX_NODE_END_FLAG)
#define VFX_GROUP_CHILDREN_DIRTY        (VFX_GROUP_BEGIN_FLAG << 1)
#define VFX_GROUP_MATERIAL_DIRTY        (VFX_GROUP_BEGIN_FLAG << 2)
#define VFX_GROUP_END_FLAG              VFX_GROUP_MATERIAL_DIRTY
#define VFX_GROUP_ALL_DIRTY             (VFX_GROUP_CHILDREN_DIRTY | VFX_GROUP_MATERIAL_DIRTY)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefine Classes
class VfxMaterial;


/***************************************************************************** 
 * Class VfxGroup
 *****************************************************************************/

/*
 * VfxGroup is the group object in 3D scene.
 */
class VfxGroup : public VfxNode
{
    VFX_DECLARE_CLASS(VfxGroup);

public:
    typedef VfxList< VfxWeakPtr<VfxNode> > NodeList;
    typedef NodeList::It NodeListItr;

// Constructor / Destructor
public:
    // Default constructor
    VfxGroup();
    // Destructor
    virtual ~VfxGroup();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set group material.
    void setMaterial(VfxMaterial *material);

    // Get group material.
    VfxMaterial *getMaterial() const;

// Group parent-child hierarchy method
public:
    // Add a child node into the group.
    void addChildNode(
        VfxNode *node   // [IN] the node to add
    );

    // Add a child node to first in the group.
    void addChildNodeToFirst(
        VfxNode *node   // [IN] the node to add
    );

    // Remove a child node from the group.
    void removeChildNode(
        VfxNode *node   // [IN] the node to remove
    );

    // Remove all child nodes from the group.
    void removeAllChildNodes();

    // Insert a node before a child node.
    void insertChildNode(
        VfxNode *child, // [IN] the child node
        VfxNode *node   // [IN] the node to insert
    );

    // Get the child node list.
    const NodeList &getChildren() const;

// Override
protected:
    void onAddChild(VfxObject *objChild);
    void onRemoveChild(VfxObject *objChild);
    virtual void onObjectNotify(VfxId eventId, void *userData);

    virtual void processPick(
        VfxNodePickReturn &ret,
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

// Implementation
protected:
    NodeList m_children;
    VfxWeakPtr< VfxMaterial > m_material;
};

#endif /* __VFX_GROUP_H__ */

