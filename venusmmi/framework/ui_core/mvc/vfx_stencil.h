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
 *  vfx_stencil.h
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
#ifndef __VFX_STENCIL_H__
#define __VFX_STENCIL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_STENCIL_BEGIN_FLAG              (VFX_OBJECT3D_END_FLAG)
#define VFX_STENCIL_FUNCTION_DIRTY          (VFX_STENCIL_BEGIN_FLAG << 1)
#define VFX_STENCIL_OPERATION_DIRTY         (VFX_STENCIL_BEGIN_FLAG << 2)
#define VFX_STENCIL_MASK_DIRTY              (VFX_STENCIL_BEGIN_FLAG << 3)
#define VFX_STENCIL_END_FLAG                (VFX_STENCIL_MASK_DIRTY)
#define VFX_STENCIL_ALL_DIRTY               (VFX_STENCIL_FUNCTION_DIRTY | \
                                             VFX_STENCIL_OPERATION_DIRTY | \
                                             VFX_STENCIL_MASK_DIRTY)


/***************************************************************************** 
 * Class VfxStencil
 *****************************************************************************/

/*
 * VfxStencil is the object that stores stencil render states.
 */
class VfxStencil : public VfxObject3D
{
// Constructor / Destructor
public:
    // Default constructor
    VfxStencil();

// Override
public:
    virtual void createHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set stencil functions.
    //
    // NOTE: Default values are VFX_STENCIL_FUNC_ALWAYS, 0, 0xFFFFFFFF,
    //  VFX_STENCIL_FUNC_ALWAYS, 0, and 0xFFFFFFFF.
    void setStencilFunc(
            VfxStencilFunc frontFunc,
            VfxS32 frontRefValue,
            VfxU32 frontFuncMask,
            VfxStencilFunc backFunc,
            VfxS32 backRefValue,
            VfxU32 backFuncMask);

    // Set stencil operations.
    //
    // NOTE: Default values are all VFX_STENCIL_OP_KEEP.
    void setStencilOperation(
            VfxStencilOp frontStencilFailOp,
            VfxStencilOp frontDepthFailOp,
            VfxStencilOp frontPassOp,
            VfxStencilOp backStencilFailOp,
            VfxStencilOp backDepthFailOp,
            VfxStencilOp backPassOp);

    // Set stencil write masks.
    //
    // NOTE: Default values are 0xFFFFFFFF and 0xFFFFFFFF.
    void setStencilMask(
            VfxU32 frontWriteMask,
            VfxU32 backWriteMask);

    // Get stencil front function.
    //
    // NOTE: Default value is VFX_STENCIL_FUNC_ALWAYS.
    VfxStencilFunc getFrontFunction() const;

    // Get stencil front reference value.
    //
    // NOTE: Default value is 0.
    VfxS32 getFrontReference() const;

    // Get stencil front function mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    VfxU32 getFrontFuncMask() const;

    // Get front stencil fail operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getFrontStencilFailOperation() const;

    // Get front depth fail operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getFrontDepthFailOperation() const;

    // Get front pass operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getFrontPassOperation() const;

    // Get stencil front write mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    VfxU32 getFrontWriteMask() const;

    // Get stencil back function.
    //
    // NOTE: Default value is VFX_STENCIL_FUNC_ALWAYS.
    VfxStencilFunc getBackFunction() const;

    // Get stencil back reference value.
    //
    // NOTE: Default value is 0.
    VfxS32 getBackReference() const;

    // Get stencil back function mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    VfxU32 getBackFuncMask() const;

    // Get back stencil fail operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getBackStencilFailOperation() const;

    // Get back depth fail operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getBackDepthFailOperation() const;

    // Get back pass operation.
    //
    // NOTE: Default value is VFX_STENCIL_OP_KEEP.
    VfxStencilOp getBackPassOperation() const;

    // Get stencil back write mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    VfxU32 getBackWriteMask() const;

// Implementation
private:

    // Stencil Front
    VfxStencilFunc m_stencilFrontFunction;
    VfxS32 m_stencilFrontRefValue;
    VfxU32 m_stencilFrontFuncMask;
    VfxStencilOp m_stencilFrontStencilFailOp;
    VfxStencilOp m_stencilFrontDepthFailOp;
    VfxStencilOp m_stencilFrontPassOp;
    VfxU32 m_stencilFrontWriteMask;

    // Stencil Back
    VfxStencilFunc m_stencilBackFunction;
    VfxS32 m_stencilBackRefValue;
    VfxU32 m_stencilBackFuncMask;
    VfxStencilOp m_stencilBackStencilFailOp;
    VfxStencilOp m_stencilBackDepthFailOp;
    VfxStencilOp m_stencilBackPassOp;
    VfxU32 m_stencilBackWriteMask;
};




inline VfxStencilFunc VfxStencil::getFrontFunction() const
{
    return m_stencilFrontFunction;
}

inline VfxS32 VfxStencil::getFrontReference() const
{
    return m_stencilFrontRefValue;
}

inline VfxU32 VfxStencil::getFrontFuncMask() const
{
    return m_stencilFrontFuncMask;
}

inline VfxStencilOp VfxStencil::getFrontStencilFailOperation() const
{
    return m_stencilFrontStencilFailOp;
}

inline VfxStencilOp VfxStencil::getFrontDepthFailOperation() const
{
    return m_stencilFrontDepthFailOp;
}

inline VfxStencilOp VfxStencil::getFrontPassOperation() const
{
    return m_stencilFrontPassOp;
}

inline VfxU32 VfxStencil::getFrontWriteMask() const
{
    return m_stencilFrontWriteMask;
}

inline VfxStencilFunc VfxStencil::getBackFunction() const
{
    return m_stencilBackFunction;
}

inline VfxS32 VfxStencil::getBackReference() const
{
    return m_stencilBackRefValue;
}

inline VfxU32 VfxStencil::getBackFuncMask() const
{
    return m_stencilBackFuncMask;
}

inline VfxStencilOp VfxStencil::getBackStencilFailOperation() const
{
    return m_stencilBackStencilFailOp;
}

inline VfxStencilOp VfxStencil::getBackDepthFailOperation() const
{
    return m_stencilBackDepthFailOp;
}

inline VfxStencilOp VfxStencil::getBackPassOperation() const
{
    return m_stencilBackPassOp;
}

inline VfxU32 VfxStencil::getBackWriteMask() const
{
    return m_stencilBackWriteMask;
}


#endif /* __VFX_STENCIL_H__ */

