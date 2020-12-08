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
 *  vfx_compositing_mode.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_stencil.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * VfxCompositingMode
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxCompositingMode::VfxCompositingMode()
: m_colorMask(0xFFFFFFFF)
, m_depthOffsetFactor(0.0f)
, m_depthOffsetUnits(0.0f)
, m_depthTest(VFX_TRUE)
, m_depthWriteEnable(VFX_TRUE)
, m_depthFunc(VFX_DEPTH_FUNC_LESS)
, m_dither(VFX_TRUE)
{
}

void VfxCompositingMode::createHandle() const
{
    m_handle = vrt_create_compositing_mode();
}

void VfxCompositingMode::disposeHandle() const
{
    if (m_handle)
    {
        if (m_blender.get())
        {
            m_blender->disposeHandle();
        }

        if (m_stencil.get())
        {
            m_stencil->disposeHandle();
        }

        VfxObject3D::disposeHandle();
    }
}

void VfxCompositingMode::syncData() const
{
    VfxObject3D::syncData();

    VfxBlender *blender = m_blender.get();
    if (isPropertyDirty(VFX_COMPOSITING_MODE_BLENDER_DIRTY))
    {
        vrt_compositing_mode_set_blender(m_handle, blender ? blender->getSyncHandle() : NULL);
    }
    if (blender)
    {
        blender->syncData();
    }

    VfxStencil *stencil = m_stencil.get();
    if (isPropertyDirty(VFX_COMPOSITING_MODE_STENCIL_DIRTY))
    {
        vrt_compositing_mode_set_stencil(m_handle, stencil ? stencil->getSyncHandle() : NULL);
    }
    if (stencil)
    {
        stencil->syncData();
    }

    if (isPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_TEST_DIRTY))
    {
        vrt_compositing_mode_set_depth_test_enable(m_handle, m_depthTest);
    }
    if (isPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_WRITE_DIRTY))
    {
        vrt_compositing_mode_set_depth_write_enable(m_handle, m_depthWriteEnable);
    }
    if (isPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_FUNC_DIRTY))
    {
        vrt_compositing_mode_set_depth_func(m_handle, (VrtDepthFunc)m_depthFunc);
    }
    if (isPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_OFFSET_DIRTY))
    {
        vrt_compositing_mode_set_depth_offset(m_handle, m_depthOffsetFactor, m_depthOffsetUnits);
    }
    if (isPropertyDirty(VFX_COMPOSITING_MODE_COLOR_WRITE_DIRTY))
    {
        vrt_compositing_mode_set_color_mask(m_handle, m_colorMask);
    }
    if (isPropertyDirty(VFX_COMPOSITING_MODE_DITHER_DIRTY))
    {
        vrt_compositing_mode_set_dither(m_handle, m_dither);
    }

    clearPropertyDirty(VFX_COMPOSITING_MODE_ALL_DIRTY);
}

void VfxCompositingMode::setBlender(VfxBlender *blender)
{
    m_blender = blender;
    setPropertyDirty(VFX_COMPOSITING_MODE_BLENDER_DIRTY);
}

void VfxCompositingMode::setStencil(VfxStencil *stencil)
{
    m_stencil = stencil;
    setPropertyDirty(VFX_COMPOSITING_MODE_STENCIL_DIRTY);
}

void VfxCompositingMode::setDepthTestEnable(VfxBool enable)
{
    m_depthTest = enable;
    setPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_TEST_DIRTY);
}

void VfxCompositingMode::setDepthWriteEnable(VfxBool enable)
{
    m_depthWriteEnable = enable;
    setPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_WRITE_DIRTY);
}

void VfxCompositingMode::setDepthFunc(VfxDepthFunc func)
{
    m_depthFunc = func;
    setPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_FUNC_DIRTY);
}

void VfxCompositingMode::setDepthOffset(VfxFloat factor, VfxFloat units)
{
    m_depthOffsetFactor = factor;
    m_depthOffsetUnits = units;
    setPropertyDirty(VFX_COMPOSITING_MODE_DEPTH_OFFSET_DIRTY);
}

void VfxCompositingMode::setColorWriteMask(VfxU32 mask)
{
    m_colorMask = mask;
    setPropertyDirty(VFX_COMPOSITING_MODE_COLOR_WRITE_DIRTY);
}

void VfxCompositingMode::setDitherEnable(VfxBool enable)
{
    m_dither = enable;
    setPropertyDirty(VFX_COMPOSITING_MODE_DITHER_DIRTY);
}

VfxBlender *VfxCompositingMode::getBlender() const
{
    return m_blender.get();
}

#pragma arm section code, rodata
