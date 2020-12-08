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
 *  vfx_light.h
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
#ifndef __VFX_LIGHT_H__
#define __VFX_LIGHT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_node.h"
#include "vfx_basic_type.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_LIGHT_BEGIN_FLAG            (VFX_NODE_END_FLAG)
#define VFX_LIGHT_COLOR_DIRTY           (VFX_LIGHT_BEGIN_FLAG << 1)
#define VFX_LIGHT_INTENSITY_DIRTY       (VFX_LIGHT_BEGIN_FLAG << 2)
#define VFX_LIGHT_END_FLAG              (VFX_LIGHT_INTENSITY_DIRTY)
#define VFX_LIGHT_ALL_DIRTY             (VFX_LIGHT_COLOR_DIRTY | VFX_LIGHT_INTENSITY_DIRTY)

/***************************************************************************** 
 * Class VfxLight
 *****************************************************************************/

/*
 * VfxLight is the light object in 3D scene.
 */
class VfxLight : public VfxNode
{
    VFX_DECLARE_CLASS(VfxLight);

// Constructor / Destructor
public:
    // Default constructor
    VfxLight();

// Override
public:
    virtual void createHandle() const;

    virtual void resetProperty(vrt_object_property_id_enum propertyId);

    virtual void syncData() const;

// Property
public:
    // Set lighting color.
    //
    // NOTE: Default value is VFX_COLOR_WHITE.
    void setColor(VfxColor color);

    // Get lighting color.
    //
    // NOTE: Default value is VFX_COLOR_WHITE.
    VfxColor getColor() const;

    // Set lighting intensity.
    //
    // NOTE: Default value is 1.0.
    void setIntensity(VfxFloat intensity);

    // Get lighting intensity.
    //
    // NOTE: Default value is 1.0.
    VfxFloat getIntensity() const;

// Implementation
protected:

    VfxColor m_color;
    VfxFloat m_intensity;
};


inline VfxColor VfxLight::getColor() const
{
    return m_color;
}

inline VfxFloat VfxLight::getIntensity() const
{
    return m_intensity;
}

#endif /* __VFX_LIGHT_H__ */

