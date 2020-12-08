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
 *  vfx_light.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_light.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxLight
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_CLASS("Light", VfxLight, VfxNode);

VfxLight::VfxLight()
: m_color(VFX_COLOR_WHITE) 
, m_intensity(1.0f)
{
}

void VfxLight::createHandle() const
{
    m_handle = vrt_create_light();
}

void VfxLight::resetProperty(vrt_object_property_id_enum propertyId)
{
    switch (propertyId)
    {
    case VRT_LIGHT_PROPERTY_ID_LIGHT_COLOR:
        setPropertyDirty(VFX_LIGHT_COLOR_DIRTY);
        break;
    case VRT_LIGHT_PROPERTY_ID_LIGHT_INTENSITY:
        setPropertyDirty(VFX_LIGHT_INTENSITY_DIRTY);
        break;
    default:
        VfxNode::resetProperty(propertyId);
    }
}

void VfxLight::syncData() const
{
    VfxNode::syncData();

    if (isPropertyDirty(VFX_LIGHT_COLOR_DIRTY))
    {
        vrt_light_set_color(m_handle, m_color);
    }

    if (isPropertyDirty(VFX_LIGHT_INTENSITY_DIRTY))
    {
        vrt_light_set_intensity(m_handle, m_intensity);
    }

    clearPropertyDirty(VFX_LIGHT_ALL_DIRTY);
}

void VfxLight::setColor(VfxColor color)
{
    m_color = color;
    setPropertyDirty(VFX_LIGHT_COLOR_DIRTY);
}

void VfxLight::setIntensity(VfxFloat intensity)
{
    m_intensity = intensity;
    setPropertyDirty(VFX_LIGHT_INTENSITY_DIRTY);
}

#pragma arm section code, rodata
