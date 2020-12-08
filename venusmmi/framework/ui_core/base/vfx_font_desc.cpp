/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vfx_font_desc.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_font_desc.h"
// For VfxWString
#include "vfx_string.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vrt_system.h"
#include "vfx_system.h"

#include "PixcomFontEngine.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_data_type_convertion.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define MAKE_VRT_FE_COLOR(fe_color, c)\
    { \
        fe_color.a = VRT_COLOR_GET_A(c); \
        fe_color.r = VRT_COLOR_GET_R(c); \
        fe_color.g = VRT_COLOR_GET_G(c); \
        fe_color.b = VRT_COLOR_GET_B(c); \
    }

/***************************************************************************** 
 * Class VfxFontDesc
 *****************************************************************************/

VfxFontDesc::VfxFontDesc(const vrt_font_struct &in)
{
    size = in.size;
    attr = 0;
    effect = VFX_FONT_DESC_EFFECT_NONE;
    
    if (in.bold)
    {
        VFX_FLAG_SET(attr, VFX_FONT_DESC_ATTR_BOLD);
    }
    if (in.italic)
    {
        VFX_FLAG_SET(attr, VFX_FONT_DESC_ATTR_ITALIC);
    }
    if (in.underline)
    {
        VFX_FLAG_SET(attr, VFX_FONT_DESC_ATTR_UNDERLINE);
    }    
    if (in.oblique)
    {
        VFX_FLAG_SET(attr, VFX_FONT_DESC_ATTR_OBLIQUE);
    }
    if (in.type == FONT_TYPE_FIXED_WIDTH)
    {
        VFX_FLAG_SET(attr, VFX_FONT_DESC_ATTR_MONOSPACE);
    }
    if (in.border)
    {
        effect = VFX_FONT_DESC_EFFECT_BORDER;
    }

	if(in.smallCaps)
	{
	    effect = in.smallCaps;
	}
}


void VfxFontDesc::initVrtFont(vrt_font_struct &font) const
{
    font.bold       = VFX_FLAG_HAS(attr, VFX_FONT_DESC_ATTR_BOLD) ? 1 : 0;
    font.italic     = VFX_FLAG_HAS(attr, VFX_FONT_DESC_ATTR_ITALIC) ? 1 : 0;
    font.underline  = VFX_FLAG_HAS(attr, VFX_FONT_DESC_ATTR_UNDERLINE) ? 1 : 0;
    font.size       = size;
    font.color      = 0;
    font.type       = VFX_FLAG_HAS(attr, VFX_FONT_DESC_ATTR_MONOSPACE) ? FONT_TYPE_FIXED_WIDTH : 1;
    font.oblique    = VFX_FLAG_HAS(attr, VFX_FONT_DESC_ATTR_OBLIQUE) ? 1 : 0;
    font.smallCaps  = (vrt_u8)effect;
    font.border     = (effect == VFX_FONT_DESC_EFFECT_BORDER) ? VRT_TRUE : VRT_FALSE;
}


VfxSize VfxFontDesc::measureStr(const VfxWChar *string) const
{
    if (string == NULL)
    {
        return VFX_SIZE_ZERO;
    }

    vrt_font_struct vrtFont;
    initVrtFont(vrtFont);    
    return vrt_sys_font_measure_str(&vrtFont, string);
}


VfxSize VfxFontDesc::measureStr(const VfxWString &string) const
{
    return measureStr(string.getBuf());
}


void VfxFontDesc::setResId(VfxResId resId)
{
    vfx_sys_res_font_struct fontStyle;

    vfx_sys_res_get_font(resId, &fontStyle);

    size = (VfxU8)fontStyle.size;
    attr = (VfxFlag)fontStyle.attribute;
    effect = fontStyle.effect;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxFontDesc::VfxFontDesc(const vm_font_desc_struct &in)
{
    size = vpi_m2v_convert_font_desc_size(in.size);
    attr = vpi_m2v_convert_font_desc_attr(in.attr);
    effect = vpi_m2v_convert_font_desc_effect(in.effect);
}


VfxFontDesc::operator vm_font_desc_struct() const
{
    vm_font_desc_struct ret;
    VM_STRUCT_INIT(ret, vm_font_desc_struct);
    ret.size = vpi_v2m_convert_font_desc_size(size);
    ret.attr = vpi_v2m_convert_font_desc_attr(attr);
    ret.effect = vpi_v2m_convert_font_desc_effect(effect);
    return ret;
}
#endif

/***************************************************************************** 
 * Class VfxFontEffect
 *****************************************************************************/
VfxFontEffect::VfxFontEffect()
{
    memset(&m_desc, 0, sizeof(FontEffectData));
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxFontEffect::VfxFontEffect(vm_font_effect_struct effect)
{
    m_desc.attr.shadow_degree = effect.shadow_degree;
    m_desc.attr.engraved_degree = effect.engraved_degree;
    m_desc.attr.shadow_distant = effect.shadow_distant;
    m_desc.attr.shadow_range = effect.shadow_range;
    m_desc.attr.shadow_transparency = effect.shadow_transparency;
    m_desc.attr.border_size = effect.border_size;
    m_desc.attr.gradient_direction = effect.gradient_direction;
    m_desc.attr.gradient_transparency = effect.gradient_transparency;
    m_desc.attr.outerglow_range = effect.outerglow_range;
    m_desc.attr.outerglow_transparency = effect.outerglow_transparency;
    m_desc.attr.engraved_transparency = effect.engraved_transparency;
    m_desc.attr.border_transparency = effect.border_transparency;

    vpi_m2v_convert_fe_color(&effect.bordered_color, &m_desc.color.bordered_color);
    vpi_m2v_convert_fe_color(&effect.first_gradient_color, &m_desc.color.first_gradient_color);
    vpi_m2v_convert_fe_color(&effect.second_gradient_color, &m_desc.color.second_gradient_color);
    vpi_m2v_convert_fe_color(&effect.shadow_color, &m_desc.color.shadow_color);
    vpi_m2v_convert_fe_color(&effect.outerglow_color, &m_desc.color.outerglow_color);
    vpi_m2v_convert_fe_color(&effect.upper_engraved_color, &m_desc.color.upper_engraved_color);
    vpi_m2v_convert_fe_color(&effect.lower_engraved_color, &m_desc.color.lower_engraved_color);

    m_desc.attribute_id = effect.attribute_id;
    m_desc.effect_type = vpi_m2v_convert_font_effect_type(effect.effect_type);
    m_desc.node_type = effect.node_type;
    m_desc.next = NULL;
}
#endif


VfxFontEffect::~VfxFontEffect()
{
    if (m_desc.attribute_id > 0)
    {
        #ifdef __MMI_FONT_EFFECTS__
        // delete this effect from system effect pool
        ::removeFontEffectAttributeNode(m_desc.attribute_id);
        #endif
    }
}


void VfxFontEffect::setType(VfxFontEffectTypeEnum effect)
{
    m_desc.effect_type = effect;
}


void VfxFontEffect::setShadow(VfxColor color, VfxS16 degree, VfxU8 distant, VfxU8 range, VfxU8 transparency)
{
    MAKE_VRT_FE_COLOR(m_desc.color.shadow_color, color);

    // mapping light degree to shadow degree
    if (degree > 0)
        degree = degree - 180;
    else
        degree = 180 + degree;
    
    m_desc.attr.shadow_degree = degree;
    m_desc.attr.shadow_distant = distant;
    m_desc.attr.shadow_range = range;
    m_desc.attr.shadow_transparency = transparency;
}


void VfxFontEffect::setOuterGlow(VfxColor color, VfxU8 range, VfxU8 transparency)
{
    MAKE_VRT_FE_COLOR(m_desc.color.outerglow_color, color);
    m_desc.attr.outerglow_range = range;
    m_desc.attr.outerglow_transparency = transparency;
}


void VfxFontEffect::setEnhancedEngrave(VfxColor upper_color, VfxColor lower_color, VfxS16 degree, VfxU8 transparency)
{
    MAKE_VRT_FE_COLOR(m_desc.color.upper_engraved_color, upper_color);
    MAKE_VRT_FE_COLOR(m_desc.color.lower_engraved_color, lower_color);
    m_desc.attr.engraved_degree = degree;
    m_desc.attr.engraved_transparency = transparency;
}


void VfxFontEffect::setGradient(VfxColor first_color, VfxColor second_color, VfxU8 direction, VfxU8 transparency)
{
    MAKE_VRT_FE_COLOR(m_desc.color.first_gradient_color, first_color);
    MAKE_VRT_FE_COLOR(m_desc.color.second_gradient_color, second_color);
    m_desc.attr.gradient_direction = direction;
    m_desc.attr.gradient_transparency = transparency;
}


void VfxFontEffect::setEnhancedBorder(VfxColor color, VfxU8 width, VfxU8 transparency)
{
    MAKE_VRT_FE_COLOR(m_desc.color.bordered_color, color);
    m_desc.attr.border_size = width;
    m_desc.attr.border_transparency = transparency;
}


VfxU8 VfxFontEffect::getEffectId()
{
    // add this font effect to system font effect pool and get a handle id
    if (m_desc.attribute_id == 0)
    {
        #ifdef __MMI_FONT_EFFECTS__
        m_desc.attribute_id = ::addFontEffectAttributeNode((stFontAttributeNode *)&m_desc);
        #endif
    }

    return m_desc.attribute_id;
}

