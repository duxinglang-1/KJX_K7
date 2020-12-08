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
 *  vfx_blender.cpp
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

#include "vfx_blender.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxBlender
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxBlender::VfxBlender()
: m_blendColor(VRT_COLOR_NULL)
, m_blendColorEquation(VFX_BLEND_EQUATION_ADD)
, m_blendAlphaEquation(VFX_BLEND_EQUATION_ADD)
, m_blendSrcColorFactor(VFX_BLEND_FACTOR_SRC_ALPHA)
, m_blendDstColorFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
, m_blendSrcAlphaFactor(VFX_BLEND_FACTOR_ONE)
, m_blendDstAlphaFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
{
}

void VfxBlender::createHandle() const
{
    m_handle = vrt_create_blender();
}

void VfxBlender::syncData() const
{
    VfxObject3D::syncData();

    if (isPropertyDirty(VFX_BLENDER_EQUATION_DIRTY))
    {
        vrt_blender_set_blend_equation(
            m_handle,
            (VrtBlendEquation)m_blendColorEquation,
            (VrtBlendEquation)m_blendAlphaEquation);
    }
    if (isPropertyDirty(VFX_BLENDER_FUNCTION_DIRTY))
    {
        vrt_blender_set_blend_function(
            m_handle,
            (VrtBlendFactor)m_blendSrcColorFactor,
            (VrtBlendFactor)m_blendDstColorFactor,
            (VrtBlendFactor)m_blendSrcAlphaFactor,
            (VrtBlendFactor)m_blendDstAlphaFactor);
    }
    if (isPropertyDirty(VFX_BLENDER_COLOR_DIRTY))
    {
        vrt_blender_set_blend_color(
            m_handle,
            m_blendColor);
    }

    clearPropertyDirty(VFX_BLENDER_ALL_DIRTY);
}

void VfxBlender::setBlendEquation(
    VfxBlendEquation colorEquation,
    VfxBlendEquation alphaEquation)
{
    VFX_DEV_ASSERT(colorEquation < VFX_BLEND_EQUATION_END_OF_ENUM);
    VFX_DEV_ASSERT(alphaEquation < VFX_BLEND_EQUATION_END_OF_ENUM);
    m_blendColorEquation = colorEquation;
    m_blendAlphaEquation = alphaEquation;
    setPropertyDirty(VFX_BLENDER_EQUATION_DIRTY);
}

void VfxBlender::setBlendFunc(
    VfxBlendFactor srcColorFactor,
    VfxBlendFactor dstColorFactor,
    VfxBlendFactor srcAlphaFactor,
    VfxBlendFactor dstAlphaFactor)
{
    VFX_DEV_ASSERT(srcColorFactor < VFX_BLEND_FACTOR_END_OF_ENUM);
    VFX_DEV_ASSERT(dstColorFactor < VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);
    VFX_DEV_ASSERT(srcAlphaFactor < VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);
    VFX_DEV_ASSERT(dstAlphaFactor < VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);
    m_blendSrcColorFactor = srcColorFactor;
    m_blendDstColorFactor = dstColorFactor;
    m_blendSrcAlphaFactor = srcAlphaFactor;
    m_blendDstAlphaFactor = dstAlphaFactor;
    setPropertyDirty(VFX_BLENDER_FUNCTION_DIRTY);
}

void VfxBlender::setBlendColor(VfxColor color)
{
    m_blendColor = color;
    setPropertyDirty(VFX_BLENDER_COLOR_DIRTY);
}

#pragma arm section code, rodata
