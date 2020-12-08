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
 *  vfx_blender.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_BLENDER_H__
#define __VFX_BLENDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_basic_type.h"
#include "vfx_3d_enum.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_BLENDER_BEGIN_FLAG              (VFX_OBJECT3D_END_FLAG)
#define VFX_BLENDER_EQUATION_DIRTY          (VFX_BLENDER_BEGIN_FLAG << 1)
#define VFX_BLENDER_FUNCTION_DIRTY          (VFX_BLENDER_BEGIN_FLAG << 2)
#define VFX_BLENDER_COLOR_DIRTY             (VFX_BLENDER_BEGIN_FLAG << 3)
#define VFX_BLENDER_END_FLAG                (VFX_BLENDER_COLOR_DIRTY)
#define VFX_BLENDER_ALL_DIRTY               (VFX_BLENDER_EQUATION_DIRTY | \
                                             VFX_BLENDER_FUNCTION_DIRTY | \
                                             VFX_BLENDER_COLOR_DIRTY)


/***************************************************************************** 
 * Class VfxBlender
 *****************************************************************************/

/*
 * VfxBlender is the object that stores blending render states.
 */
class VfxBlender : public VfxObject3D
{
// Constructor / Destructor
public:
    // Default constructor
    VfxBlender();

// Override
public:
    virtual void createHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set blend equations.
    //
    // NOTE: Default values are VFX_BLEND_EQUATION_ADD and VFX_BLEND_EQUATION_ADD.
    void setBlendEquation(
            VfxBlendEquation colorEquation,
            VfxBlendEquation alphaEquation);

    // Set blend functions.
    //
    // NOTE: Default values are VFX_BLEND_FACTOR_SRC_ALPHA, VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
    //  VFX_BLEND_FACTOR_ONE, and VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA.
    void setBlendFunc(
            VfxBlendFactor srcColorFactor,
            VfxBlendFactor dstColorFactor,
            VfxBlendFactor srcAlphaFactor,
            VfxBlendFactor dstAlphaFactor);

    // Set blend color.
    //
    // NOTE: Default value is VFX_COLOR_NULL.
    void setBlendColor(VfxColor color);

    // Get color blend equation.
    //
    // NOTE: Default value is VFX_BLEND_EQUATION_ADD.
    VfxBlendEquation getColorEquation() const;

    // Get alpha blend equation.
    //
    // NOTE: Default value is VFX_BLEND_EQUATION_ADD.
    VfxBlendEquation getAlphaEquation() const;

    // Get source color blend factor.
    //
    // NOTE: Default value is VFX_BLEND_FACTOR_SRC_ALPHA.
    VfxBlendFactor getSourceColorFactor() const;

    // Get destination color blend factor.
    //
    // NOTE: Default value is VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA.
    VfxBlendFactor getDestinationColorFactor() const;

    // Get source alpha blend factor.
    //
    // NOTE: Default value is VFX_BLEND_FACTOR_ONE.
    VfxBlendFactor getSourceAlphaFactor() const;

    // Get destination alpha blend factor.
    //
    // NOTE: Default value is VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA.
    VfxBlendFactor getDestinationAlphaFactor() const;

    // Get blend color.
    //
    // NOTE: Default value is VFX_COLOR_NULL.
    VfxColor getBlendColor() const;

// Implementation
private:

    // Blending
    VfxColor m_blendColor;
    VfxBlendEquation m_blendColorEquation;
    VfxBlendEquation m_blendAlphaEquation;
    VfxBlendFactor m_blendSrcColorFactor;
    VfxBlendFactor m_blendDstColorFactor;
    VfxBlendFactor m_blendSrcAlphaFactor;
    VfxBlendFactor m_blendDstAlphaFactor;
};




inline VfxBlendEquation VfxBlender::getColorEquation() const
{
    return m_blendColorEquation;
}

inline VfxBlendEquation VfxBlender::getAlphaEquation() const
{
    return m_blendAlphaEquation;
}

inline VfxBlendFactor VfxBlender::getSourceColorFactor() const
{
    return m_blendSrcColorFactor;
}

inline VfxBlendFactor VfxBlender::getDestinationColorFactor() const
{
    return m_blendDstColorFactor;
}

inline VfxBlendFactor VfxBlender::getSourceAlphaFactor() const
{
    return m_blendSrcAlphaFactor;
}

inline VfxBlendFactor VfxBlender::getDestinationAlphaFactor() const
{
    return m_blendDstAlphaFactor;
}

inline VfxColor VfxBlender::getBlendColor() const
{
    return m_blendColor;
}


#endif /* __VFX_BLENDER_H__ */

