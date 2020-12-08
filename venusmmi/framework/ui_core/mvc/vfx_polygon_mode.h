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
 *  vfx_polygon_mode.h
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
#ifndef __VFX_POLYGON_MODE_H__
#define __VFX_POLYGON_MODE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_POLYGON_MODE_BEGIN_FLAG                 (VFX_OBJECT3D_END_FLAG)
#define VFX_POLYGON_MODE_WINDING_DIRTY              (VFX_POLYGON_MODE_BEGIN_FLAG << 1)
#define VFX_POLYGON_MODE_CULLING_DIRTY              (VFX_POLYGON_MODE_BEGIN_FLAG << 2)
#define VFX_POLYGON_MODE_END_FLAG                   (VFX_POLYGON_MODE_CULLING_DIRTY)
#define VFX_POLYGON_MODE_ALL_DIRTY                  (VFX_POLYGON_MODE_WINDING_DIRTY | \
                                                     VFX_POLYGON_MODE_CULLING_DIRTY)


/***************************************************************************** 
 * Class VfxPolygonMode
 *****************************************************************************/

/*
 * VfxPolygonMode is the object that stores polygon render states.
 */
class VfxPolygonMode : public VfxObject3D
{
// Constructor / Destructor
public:
    // Default constructor
    VfxPolygonMode();

// Override
public:
    virtual void createHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set winding mode.
    //
    // NOTE: Default value is VFX_WINDING_CCW.
    void setWinding(VfxWindingMode mode);

    // Set culling mode.
    //
    // NOTE: Default value is VFX_CULLING_BACK.
    void setCulling(VfxCullingMode mode);

    // Get winding mode.
    //
    // NOTE: Default value is VFX_WINDING_CCW.
    VfxWindingMode getWinding() const;

    // Get culling mode.
    //
    // NOTE: Default value is VFX_CULLING_BACK.
    VfxCullingMode getCulling() const;

// Implementation
private:

    VfxWindingMode m_winding;
    VfxCullingMode m_culling;
};


inline VfxWindingMode VfxPolygonMode::getWinding() const
{
    return m_winding;
}

inline VfxCullingMode VfxPolygonMode::getCulling() const
{
    return m_culling;
}


#endif /* __VFX_POLYGON_MODE_H__ */

