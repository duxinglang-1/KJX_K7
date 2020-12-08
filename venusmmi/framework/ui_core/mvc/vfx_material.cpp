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
 *  vfx_material.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_string.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxMaterial
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxMaterial::VfxMaterial(VfxU32 passCount)
{
    m_passes.init(this);
    m_passes.resize(passCount);
}


/*
VfxResId VfxMaterial::getResId() const
{
    return m_assetSrc.getResId();
}


const VfxWString &VfxMaterial::getPath() const
{
    return m_assetSrc.getPath();
}


void VfxMaterial::setResId(VfxResId resId)
{
    // we does not support to reload material, yet.
    VFX_DEV_ASSERT(m_assetSrc.isNull());
    m_assetSrc.setResId(resId);
}


void VfxMaterial::setPath(const VfxWString &path)
{
    // we does not support to reload material, yet.
    VFX_DEV_ASSERT(m_assetSrc.isNull());
    m_assetSrc.setPath(path);
}
*/


void VfxMaterial::setPassCount(VfxU32 count)
{
    m_passes.resize(count);
    setPropertyDirty(VFX_MATERIAL_PASS_DIRTY);
}


void VfxMaterial::createHandle() const
{
    m_handle = vrt_create_material(m_passes.size());
}


void VfxMaterial::disposeHandle() const
{
    if (m_handle)
    {
        VfxU32 i;
        for (i = 0; i < m_passes.size(); i++)
        {
            VfxPass *pass = m_passes[i].get();
            if (pass)
            {
                pass->disposeHandle();
            }
        }

        VfxObject3D::disposeHandle();
    }
}


void VfxMaterial::syncData() const
{
    VfxObject3D::syncData();

    VfxU32 i = 0;
    for (i = 0; i < m_passes.size(); i++)
    {
        VfxPass *pass = m_passes[i].get();
        VFX_DEV_ASSERT(pass);
        if (isPropertyDirty(VFX_MATERIAL_PASS_DIRTY))
        {
            vrt_material_set_pass(m_handle, i, pass->getSyncHandle());
        }
        pass->syncData();
    }

    clearPropertyDirty(VFX_MATERIAL_ALL_DIRTY);
}


VfxU32 VfxMaterial::getPassCount() const
{
    return m_passes.size();
}


void VfxMaterial::setPass(VfxU32 idx, VfxPass *pass)
{
    m_passes[idx] = pass;
    setPropertyDirty(VFX_MATERIAL_PASS_DIRTY);
}


VfxPass *VfxMaterial::getPass(VfxU32 idx) const
{
    return m_passes[idx].get();
}

#pragma arm section code, rodata
