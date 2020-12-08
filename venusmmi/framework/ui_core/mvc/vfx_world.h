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
 *  vfx_world.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_WORLD_H__
#define __VFX_WORLD_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame.h"
#include "vfx_group.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_WORLD_BEGIN_FLAG            (VFX_GROUP_END_FLAG)
#define VFX_WORLD_CAMERA_DIRTY          (VFX_WORLD_BEGIN_FLAG << 1)
#define VFX_WORLD_BACKGROUND_DIRTY      (VFX_WORLD_BEGIN_FLAG << 2)
#define VFX_WORLD_ENABLE_CLEAR_DIRTY    (VFX_WORLD_BEGIN_FLAG << 3)
#define VFX_WORLD_END_FLAG              (VFX_WORLD_BACKGROUND_DIRTY)
#define VFX_WORLD_ALL_DIRTY             (VFX_WORLD_CAMERA_DIRTY | VFX_WORLD_BACKGROUND_DIRTY | VFX_WORLD_ENABLE_CLEAR_DIRTY)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxCamera;
class VfxImage2D;


/***************************************************************************** 
 * Class VfxWorld
 *****************************************************************************/

/*
 * VfxWorld is the world object in 3D scene.
 */
class VfxWorld : public VfxGroup
{
    VFX_DECLARE_CLASS(VfxWorld);

public:
    typedef VfxMap< VfxString, VfxWeakPtr< VfxObject3D > > BindingMap;
    typedef BindingMap::It BindingMapItr;

// Constructor / Destructor
public:
    // Default constructor
    VfxWorld();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set active camera of the world.
    void setActiveCamera(VfxCamera *camera);

    // Get active camera of the world.
    VfxCamera *getActiveCamera() const;

    // Set background image of the world.
    void setBackground(VfxImage2D *background);

    // Get background image of the world.
    VfxImage2D *getBackground() const;

    // Enable / disable clear depth buffer.
    void enableClearDepth(VfxBool enable, VfxBool clearBeforeDraw);

    // Enable / disable clear stencil buffer.
    void enableClearStencil(VfxBool enable, VfxBool clearBeforeDraw);

    // Clear the var_name/binding table for post-binding.
    //
    // SEE ALSO: VfxWorld::setBindingLookup, VfxWorld::getBindingLookup
    void clearBindingMap();

    // Set or replace an entry in the var_name/binding table for post-binding.
    //
    // RETURNS: Return the replaced object if the entry was already in the table.
    //  Otherwise return NULL.
    //
    // SEE ALSO: VfxAssetLoader::loadScene, VfxAssetLoader::loadSceneBegin
    VfxObject3D *setBindingLookup(const VfxString &varname, VfxObject3D *objPtr);

    // Get a binding by var_name from the var_name/binding table.
    //
    // RETURNS: Return binding by var_name. Return NULL if binding on var_name cannot be found.
    //
    // SEE ALSO: VfxAssetLoader::loadScene
    VfxObject3D *getBindingLookup(const VfxString &varname);

// Override
protected:
    virtual void onDeinit();

// Implementation
protected:
    BindingMap *getBindingMap();

    VfxWeakPtr<VfxCamera> m_activeCamera;

    VfxWeakPtr<VfxImage2D> m_background;

    VfxBool m_bEnableClearDepth;
    VfxBool m_bClearDepthBeforeDrawWorld;
    VfxBool m_bEnableClearStencil;
    VfxBool m_bClearStencilBeforeDrawWorld;
};


/***************************************************************************** 
 * Class VfxWorld Implementation
 *****************************************************************************/

inline VfxCamera *VfxWorld::getActiveCamera() const
{
    return m_activeCamera.get();
}


inline VfxImage2D *VfxWorld::getBackground() const
{
    return m_background.get();
}


#endif /* __VFX_WORLD_H__ */

