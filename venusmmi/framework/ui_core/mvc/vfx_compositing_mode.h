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
 *  vfx_compositing_mode.h
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
#ifndef __VFX_COMPOSITING_MODE_H__
#define __VFX_COMPOSITING_MODE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxBlender;
class VfxStencil;


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_COMPOSITING_MODE_BEGIN_FLAG                 (VFX_OBJECT3D_END_FLAG)
#define VFX_COMPOSITING_MODE_BLENDER_DIRTY              (VFX_COMPOSITING_MODE_BEGIN_FLAG << 1)
#define VFX_COMPOSITING_MODE_STENCIL_DIRTY              (VFX_COMPOSITING_MODE_BEGIN_FLAG << 2)
#define VFX_COMPOSITING_MODE_DEPTH_TEST_DIRTY           (VFX_COMPOSITING_MODE_BEGIN_FLAG << 3)
#define VFX_COMPOSITING_MODE_DEPTH_WRITE_DIRTY          (VFX_COMPOSITING_MODE_BEGIN_FLAG << 4)
#define VFX_COMPOSITING_MODE_DEPTH_FUNC_DIRTY           (VFX_COMPOSITING_MODE_BEGIN_FLAG << 5)
#define VFX_COMPOSITING_MODE_DEPTH_OFFSET_DIRTY         (VFX_COMPOSITING_MODE_BEGIN_FLAG << 6)
#define VFX_COMPOSITING_MODE_COLOR_WRITE_DIRTY          (VFX_COMPOSITING_MODE_BEGIN_FLAG << 7)
#define VFX_COMPOSITING_MODE_DITHER_DIRTY               (VFX_COMPOSITING_MODE_BEGIN_FLAG << 8)
#define VFX_COMPOSITING_MODE_END_FLAG                   (VFX_COMPOSITING_MODE_COLOR_WRITE_DIRTY)
#define VFX_COMPOSITING_MODE_ALL_DIRTY                  (VFX_COMPOSITING_MODE_BLENDER_DIRTY | \
                                                         VFX_COMPOSITING_MODE_STENCIL_DIRTY | \
                                                         VFX_COMPOSITING_MODE_DEPTH_TEST_DIRTY | \
                                                         VFX_COMPOSITING_MODE_DEPTH_WRITE_DIRTY | \
                                                         VFX_COMPOSITING_MODE_DEPTH_FUNC_DIRTY | \
                                                         VFX_COMPOSITING_MODE_DEPTH_OFFSET_DIRTY | \
                                                         VFX_COMPOSITING_MODE_COLOR_WRITE_DIRTY | \
                                                         VFX_COMPOSITING_MODE_DITHER_DIRTY)


/***************************************************************************** 
 * Class VfxCompositingMode
 *****************************************************************************/

/*
 * VfxCompositingMode is the object that stores compositing render states.
 */
class VfxCompositingMode : public VfxObject3D
{
// Constructor / Destructor
public:
    // Default constructor
    VfxCompositingMode();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set blender.
    void setBlender(VfxBlender *blender);

    // Set stencil.
    void setStencil(VfxStencil *stencil);

    // Set depth test enable.
    //
    // NOTE: Default value is VFX_TRUE.
    void setDepthTestEnable(VfxBool enable);

    // Set depth write enable.
    //
    // NOTE: Default value is VFX_TRUE.
    void setDepthWriteEnable(VfxBool enable);

    // Set depth function.
    //
    // NOTE: Default value is VFX_DEPTH_FUNC_LESS.
    void setDepthFunc(VfxDepthFunc func);

    // Set depth offset.
    //
    // NOTE: Default values are 0.0 and 0.0.
    void setDepthOffset(VfxFloat factor, VfxFloat units);

    // Set color write mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    void setColorWriteMask(VfxU32 mask); 

    // Set dither enable.
    //
    // NOTE: Default value is VFX_TRUE.
    void setDitherEnable(VfxBool enable);

    // Get blender.
    VfxBlender *getBlender() const;

    // Get stencil.
    VfxStencil *getStencil() const;

    // Whether depth test enabled.
    //
    // NOTE: Default value is VFX_TRUE.
    VfxBool isDepthTestEnabled() const;

    // Whether depth write enable.
    //
    // NOTE: Default value is VFX_TRUE.
    VfxBool isDepthWriteEnabled() const;

    // Get depth function.
    //
    // NOTE: Default value is VFX_DEPTH_FUNC_LESS.
    VfxDepthFunc getDepthFunc() const;

    // Get depth offset factor.
    //
    // NOTE: Default value is 0.0.
    VfxFloat getDepthOffsetFactor() const;

    // Get depth offset units.
    //
    // NOTE: Default value is 0.0.
    VfxFloat getDepthOffsetUnits() const;

    // Get color write mask.
    //
    // NOTE: Default value is 0xFFFFFFFF.
    VfxU32 getColorWriteMask() const;

    // Get dither enable.
    //
    // NOTE: Default value is VFX_TRUE.
    VfxBool getDitherEnable() const;

// Implementation
private:

    VfxWeakPtr< VfxBlender > m_blender;
    VfxWeakPtr< VfxStencil > m_stencil;

    VfxU32 m_colorMask;
    
    VfxFloat m_depthOffsetFactor;
    VfxFloat m_depthOffsetUnits;

    VfxBool m_depthTest;
    VfxBool m_depthWriteEnable;
    VfxDepthFunc m_depthFunc;
    VfxBool m_dither;
};


inline VfxBool VfxCompositingMode::isDepthTestEnabled() const
{
    return m_depthTest;
}

inline VfxBool VfxCompositingMode::isDepthWriteEnabled() const
{
    return m_depthWriteEnable;
}

inline VfxDepthFunc VfxCompositingMode::getDepthFunc() const
{
    return m_depthFunc;
}

inline VfxFloat VfxCompositingMode::getDepthOffsetFactor() const
{
    return m_depthOffsetFactor;
}

inline VfxFloat VfxCompositingMode::getDepthOffsetUnits() const
{
    return m_depthOffsetUnits;
}

inline VfxU32 VfxCompositingMode::getColorWriteMask() const
{
    return m_colorMask;
}

inline VfxBool VfxCompositingMode::getDitherEnable() const
{
    return m_dither;
}


#endif /* __VFX_COMPOSITING_MODE_H__ */

