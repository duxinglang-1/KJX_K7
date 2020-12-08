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
 *  vfx_world.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_render_buffer.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_WORLD_PROP_ID_BINDING_MAP   0x1020201


/***************************************************************************** 
 * Class VfxWorld
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_CLASS("World", VfxWorld, VfxGroup);

VfxWorld::VfxWorld()
: m_activeCamera(NULL)
, m_background(NULL)
, m_bEnableClearDepth(VFX_FALSE)
, m_bClearDepthBeforeDrawWorld(VFX_FALSE)
, m_bEnableClearStencil(VFX_FALSE)
, m_bClearStencilBeforeDrawWorld(VFX_FALSE)
{
}

void VfxWorld::onDeinit()
{
    clearBindingMap();

    VfxGroup::onDeinit();
}

void VfxWorld::createHandle() const
{
    m_handle = vrt_create_world();
}

void VfxWorld::disposeHandle() const
{
    if (m_handle)
    {
        if (m_activeCamera.get())
        {
            m_activeCamera->disposeHandle();
        }

        if (m_background.get())
        {
            m_background->disposeHandle();
        }
        VfxGroup::disposeHandle();
    }
}

void VfxWorld::syncData() const
{
    VfxGroup::syncData();

    /* camera */
    VfxCamera *camera = m_activeCamera.get();
    if (isPropertyDirty(VFX_WORLD_CAMERA_DIRTY))
    {
        vrt_world_set_active_camera(m_handle, camera ? camera->getSyncHandle() : NULL);
    }
    
    if (camera)
    {
        camera->syncData();
    }

    /* background */
    VfxImage2D *bg = m_background.get();
    if (isPropertyDirty(VFX_WORLD_BACKGROUND_DIRTY))
    {
        vrt_world_set_background(m_handle, bg ? bg->getSyncHandle() : NULL);
    }

    /* clear enable */
    if (isPropertyDirty(VFX_WORLD_ENABLE_CLEAR_DIRTY))
    {
        vrt_world_enable_clear_depth(m_handle, m_bEnableClearDepth, m_bClearDepthBeforeDrawWorld);
        vrt_world_enable_clear_stencil(m_handle, m_bEnableClearStencil, m_bClearStencilBeforeDrawWorld);
    }
    
    if (bg)
    {
        bg->syncData();
    }

    clearPropertyDirty(VFX_WORLD_ALL_DIRTY);
}


void VfxWorld::setActiveCamera(VfxCamera *camera)
{
    m_activeCamera = camera;
    setPropertyDirty(VFX_WORLD_CAMERA_DIRTY);
}


void VfxWorld::setBackground(VfxImage2D *background)
{
    m_background = background;
    setPropertyDirty(VFX_WORLD_BACKGROUND_DIRTY);
}


void VfxWorld::enableClearDepth(VfxBool enable, VfxBool clearBeforeDraw)
{
    m_bEnableClearDepth = enable;
    m_bClearDepthBeforeDrawWorld = clearBeforeDraw;
    setPropertyDirty(VFX_WORLD_ENABLE_CLEAR_DIRTY);
}


void VfxWorld::enableClearStencil(VfxBool enable, VfxBool clearBeforeDraw)
{
    m_bEnableClearStencil = enable;
    m_bClearStencilBeforeDrawWorld = clearBeforeDraw;
    setPropertyDirty(VFX_WORLD_ENABLE_CLEAR_DIRTY);
}


/* variable binding hash table */
VfxWorld::BindingMap *VfxWorld::getBindingMap()
{
    BindingMap **ppmap = (BindingMap**)getAttachProperty(VFX_WORLD_PROP_ID_BINDING_MAP, sizeof(BindingMap*));
    if (ppmap)
    {
        return *ppmap;
    }
    else
    {
        BindingMap *pmap;
        VFX_ALLOC_NEW(pmap, BindingMap, this);
        pmap->init(this);
        setAttachProperty(VFX_WORLD_PROP_ID_BINDING_MAP, &pmap, sizeof(BindingMap*));
        return pmap;
    }
}


void VfxWorld::clearBindingMap()
{
    BindingMap **ppmap = (BindingMap**)getAttachProperty(VFX_WORLD_PROP_ID_BINDING_MAP, sizeof(BindingMap*));
    if (ppmap)
    {
        VFX_DELETE(*ppmap);
        setAttachProperty(VFX_WORLD_PROP_ID_BINDING_MAP, NULL, 0);
    }
}


VfxObject3D *VfxWorld::setBindingLookup(const VfxString &varname, VfxObject3D *objPtr)
{
    VFX_DEV_ASSERT(!varname.isEmpty());

    BindingMap *pmap = getBindingMap();
    BindingMapItr iter = pmap->find(varname);
    VfxObject3D *old = NULL;

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
            pmap->insert(varname, objPtr);
        }
    }
    else
    {
        pmap->erase(iter);
    }

    if (pmap->empty())
    {
        clearBindingMap();
    }

    return old;
}


VfxObject3D *VfxWorld::getBindingLookup(const VfxString &varname)
{
    VFX_DEV_ASSERT(!varname.isEmpty());

    BindingMap *pmap = getBindingMap();
    BindingMapItr iter = pmap->find(varname);
    VfxObject3D *objPtr = NULL;

    if (iter != pmap->end())
    {
        objPtr = iter.getValue().get();
    }

    return objPtr;
}

#pragma arm section code, rodata

