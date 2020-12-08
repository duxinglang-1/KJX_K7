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
 *  vfx_stencil.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_stencil.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxStencil
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxStencil::VfxStencil()
: m_stencilFrontFunction(VFX_STENCIL_FUNC_ALWAYS)
, m_stencilFrontRefValue(0)
, m_stencilFrontFuncMask(0xFFFFFFFF)
, m_stencilFrontStencilFailOp(VFX_STENCIL_OP_KEEP)
, m_stencilFrontDepthFailOp(VFX_STENCIL_OP_KEEP)
, m_stencilFrontPassOp(VFX_STENCIL_OP_KEEP)
, m_stencilFrontWriteMask(0xFFFFFFFF)
, m_stencilBackFunction(VFX_STENCIL_FUNC_ALWAYS)
, m_stencilBackRefValue(0)
, m_stencilBackFuncMask(0xFFFFFFFF)
, m_stencilBackStencilFailOp(VFX_STENCIL_OP_KEEP)
, m_stencilBackDepthFailOp(VFX_STENCIL_OP_KEEP)
, m_stencilBackPassOp(VFX_STENCIL_OP_KEEP)
, m_stencilBackWriteMask(0xFFFFFFFF)
{
}

void VfxStencil::createHandle() const
{
    m_handle = vrt_create_stencil();
}

void VfxStencil::syncData() const
{
    VfxObject3D::syncData();

    if (isPropertyDirty(VFX_STENCIL_FUNCTION_DIRTY))
    {
        vrt_stencil_set_stencil_function(
            m_handle,
            (VrtStencilFunc)m_stencilFrontFunction,
            m_stencilFrontRefValue,
            m_stencilFrontFuncMask,
            (VrtStencilFunc)m_stencilBackFunction,
            m_stencilBackRefValue,
            m_stencilBackFuncMask);
    }
    if (isPropertyDirty(VFX_STENCIL_OPERATION_DIRTY))
    {
        vrt_stencil_set_stencil_operation(
            m_handle,
            (VrtStencilOp)m_stencilFrontStencilFailOp,
            (VrtStencilOp)m_stencilFrontDepthFailOp,
            (VrtStencilOp)m_stencilFrontPassOp,
            (VrtStencilOp)m_stencilBackStencilFailOp,
            (VrtStencilOp)m_stencilBackDepthFailOp,
            (VrtStencilOp)m_stencilBackPassOp);
    }
    if (isPropertyDirty(VFX_STENCIL_MASK_DIRTY))
    {
        vrt_stencil_set_stencil_mask(
            m_handle,
            m_stencilFrontWriteMask,
            m_stencilBackWriteMask);
    }

    clearPropertyDirty(VFX_STENCIL_ALL_DIRTY);
}

void VfxStencil::setStencilFunc(
    VfxStencilFunc frontFunc,
    VfxS32 frontRefValue,
    VfxU32 frontFuncMask,
    VfxStencilFunc backFunc,
    VfxS32 backRefValue,
    VfxU32 backFuncMask)
{
    VFX_DEV_ASSERT(frontFunc < VFX_STENCIL_FUNC_END_OF_ENUM);
    VFX_DEV_ASSERT(backFunc < VFX_STENCIL_FUNC_END_OF_ENUM);
    m_stencilFrontFunction = frontFunc;
    m_stencilFrontRefValue = frontRefValue;
    m_stencilFrontFuncMask = frontFuncMask;
    m_stencilBackFunction = backFunc;
    m_stencilBackRefValue = backRefValue;
    m_stencilBackFuncMask = backFuncMask;
    setPropertyDirty(VFX_STENCIL_FUNCTION_DIRTY);
}

void VfxStencil::setStencilOperation(
    VfxStencilOp frontStencilFailOp,
    VfxStencilOp frontDepthFailOp,
    VfxStencilOp frontPassOp,
    VfxStencilOp backStencilFailOp,
    VfxStencilOp backDepthFailOp,
    VfxStencilOp backPassOp)
{
    VFX_DEV_ASSERT(frontStencilFailOp < VFX_STENCIL_OP_END_OF_ENUM);
    VFX_DEV_ASSERT(frontDepthFailOp < VFX_STENCIL_OP_END_OF_ENUM);
    VFX_DEV_ASSERT(frontPassOp < VFX_STENCIL_OP_END_OF_ENUM);
    VFX_DEV_ASSERT(backStencilFailOp < VFX_STENCIL_OP_END_OF_ENUM);
    VFX_DEV_ASSERT(backDepthFailOp < VFX_STENCIL_OP_END_OF_ENUM);
    VFX_DEV_ASSERT(backPassOp < VFX_STENCIL_OP_END_OF_ENUM);
    m_stencilFrontStencilFailOp = frontStencilFailOp;
    m_stencilFrontDepthFailOp = frontDepthFailOp;
    m_stencilFrontPassOp = frontPassOp;
    m_stencilBackStencilFailOp = backStencilFailOp;
    m_stencilBackDepthFailOp = backDepthFailOp;
    m_stencilBackPassOp = backPassOp;
    setPropertyDirty(VFX_STENCIL_OPERATION_DIRTY);
}

void VfxStencil::setStencilMask(
    VfxU32 frontWriteMask,
    VfxU32 backWriteMask)
{
    m_stencilFrontWriteMask = frontWriteMask;
    m_stencilBackWriteMask = backWriteMask;
    setPropertyDirty(VFX_STENCIL_MASK_DIRTY);
}

#pragma arm section code, rodata
