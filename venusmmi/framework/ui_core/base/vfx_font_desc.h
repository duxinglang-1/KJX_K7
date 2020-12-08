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
 *  vfx_font_desc.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
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
#ifndef __VFX_FONT_DESC_H__
#define __VFX_FONT_DESC_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase 
#include "vfx_cpp_base.h"
// For VfxSize
#include "vfx_basic_type.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_datatype.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_FONT_DESC_SMALL             VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL)   // Default small size font descripion
#define VFX_FONT_DESC_MEDIUM            VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM)  // Default medium size font descripion
#define VFX_FONT_DESC_LARGE             VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE)   // Default large size font descripion


// Define vector font size
//
// EXAMPLE:
// <code>
//  VfxFontDesc font;
//  font.size = VFX_FONT_DESC_VF_SIZE(30)
// </code>
#define VFX_FONT_DESC_VF_SIZE(_size)    (0x80 | (_size))


//
// Define a VfxFontDesc with a resource ID.
//
// EXAMPLE:
// <code>
//  font = VFX_FONT_RES(FONT_ID_HELLO);
// </code>
//
#define VFX_FONT_RES(_id)                       VfxFontDesc(VfxFontResHelper((VfxResId)(_id)))


// Font attribute flags

#define VFX_FONT_DESC_ATTR_NORMAL           0           // Normal style
#define VFX_FONT_DESC_ATTR_BOLD             (1 << 0)    // Bold style
#define VFX_FONT_DESC_ATTR_OBLIQUE          (1 << 1)    // Oblique style
#define VFX_FONT_DESC_ATTR_ITALIC           (1 << 2)    // Italic style
#define VFX_FONT_DESC_ATTR_UNDERLINE        (1 << 3)    // Underline style
#define VFX_FONT_DESC_ATTR_STRIKETHROUGH    (1 << 4)    // Strike through style
#define VFX_FONT_DESC_ATTR_MONOSPACE        (1 << 5)    // Monospace style


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-define class
class VfxWString;


// Font effect type enumeration
enum VfxFontEffectTypeEnum
{
    VFX_FONT_EFFECT_NONE = 0,                            // No effect
    VFX_FONT_EFFECT_SHADOW = 2,                          // Drop-shadow effect
    VFX_FONT_EFFECT_OUTER_GLOW,                          // Outer-glow effect
    VFX_FONT_EFFECT_ENHANCED_ENGRAVE,                    // Enhanced engrave effect
    VFX_FONT_EFFECT_GRADIENT,                            // Gradient effect
    VFX_FONT_EFFECT_ENHANCED_BORDER,                     // Enhanced Border effect
    VFX_FONT_EFFECT_GRADIENT_DROP_SHADOW,                // Gradient and Drop-shadow effect
    VFX_FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE,           // Grandient and enhanced engrave effect
    VFX_FONT_EFFECT_END_OF_ENUM
};

// Pre-defined Effect ID Enum
enum VfxFontDescEffectEnum
{
    VFX_FONT_DESC_EFFECT_NONE = 0,                       // No effect
    VFX_FONT_DESC_EFFECT_STRIKETHROUGH,                  // Strikethrough effect
    VFX_FONT_DESC_EFFECT_BORDER,                         // Border effect
    /* Predefined ID */
    /* Shadow */
    VFX_FE1_1 = 3,
    VFX_FE1_2,
    VFX_FE1_3,
    VFX_FE1_4,
    VFX_FE1_5,
    VFX_FE1_6,
    VFX_FE1_7,
    VFX_FE1_8,
    VFX_FE1_9,
    /* Outer Glow */
    VFX_FE2_1,
    /* Enhanced Engraved */
    VFX_FE3_1,
    /* Gradient */
    VFX_FE4_1,
    /* Enhanced Bordered */
    VFX_FE5_1,
    FE_EFFECT_END_OF_ENUM,
    /* the following id will be removed. now it's only for avoid build error */
    VFX_FONT_DESC_EFFECT_ENGRAVE,                        // Engrave effect
    VFX_FONT_DESC_EFFECT_DROP_SHADOW,                    // Drop-shadow effect
    VFX_FONT_DESC_EFFECT_OUTER_GLOW,                     // Outer-glow effect
    VFX_FONT_DESC_EFFECT_ENHANCED_ENGRAVE,               // Enhanced engrave effect
    VFX_FONT_DESC_EFFECT_GRADIENT,                       // Gradient effect
    VFX_FONT_DESC_EFFECT_ENHANCED_BORDER,                // Enhanced Border effect
    VFX_FONT_DESC_EFFECT_GRADIENT_DROP_SHADOW,           // Gradient and Drop-shadow effect
    VFX_FONT_DESC_EFFECT_GRADIENT_ENHANCED_ENGRAVE      // Grandient and enhanced engrave effect
};


// Font size enumeration
enum VfxFontDescSizeEnum
{
    VFX_FONT_DESC_SIZE_SMALL = 0,       // Small font size
    VFX_FONT_DESC_SIZE_MEDIUM,          // Medium font size
    VFX_FONT_DESC_SIZE_LARGE,           // Large font size
    VFX_FONT_DESC_SIZE_SUBLCD,          // font size for sub LCD
    VFX_FONT_DESC_SIZE_DIALER,          // font size for dialer
#if defined(__MMI_MAINLCD_320X480__)
    VFX_FONT_DESC_SIZE_NUM_1,
    VFX_FONT_DESC_SIZE_NUM_2,
    VFX_FONT_DESC_SIZE_VK,
    VFX_FONT_DESC_SIZE_VK_LARGE,
#else
    VFX_FONT_DESC_SIZE_VK,
#endif            
    VFX_FONT_DESC_SIZE_END_OF_ENUM
};


/***************************************************************************** 
 * class VfxFontResHelper
 *****************************************************************************/
/*
 * Internal Used. Use macro VFX_FONT_RES.
 */
class VfxFontResHelper : public VfxBase
{
// Constructor / Destructor        
public:
    // Default constructor
    VfxFontResHelper(VfxResId resId) : 
        m_resId(resId)
    {
    }

// Method
public:
    VfxResId getResId() const
    {
        return m_resId;
    }

private:
    VfxResId m_resId;
};


/***************************************************************************** 
 * Class VfxFontDesc
 *****************************************************************************/

/*
 * VfxFontDesc specifiy a font description for its size, attribute and effect. 
 *
 * SEE ALSO: VfxFontDescSizeEnum
 */
class VfxFontDesc : public VfxBase
{
// Constructor
public:
    // Default constructor
    VfxFontDesc() :
        size(VFX_FONT_DESC_SIZE_MEDIUM),
        attr(VFX_FONT_DESC_ATTR_NORMAL),
        effect(VFX_FONT_DESC_EFFECT_NONE)
    {
    }

    // Construct with a VRT font structure
    explicit VfxFontDesc(
        const vrt_font_struct &in       // [IN] VRT font structure
    );

    // Initialized with resource ID
    VfxFontDesc(const VfxFontResHelper &initializer)
    {
        setResId(initializer.getResId());
    }

    // Copy constructor
    VfxFontDesc(const VfxFontDesc &in) :
        size(in.size), attr(in.attr), effect(in.effect)
    {
    }

    // Construct with font size, attribute and effect
    //
    // SEE ALSO: VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_ATTR_BOLD, VFX_FONT_DESC_ATTR_OBLIQUE, 
    explicit VfxFontDesc(
        VfxU8 size_in,                                      // [IN] font size
        VfxFlag attr_in = VFX_FONT_DESC_ATTR_NORMAL,        // [IN] font attribute
        VfxFontDescEffectEnum effect_in = VFX_FONT_DESC_EFFECT_NONE) :  // [IN] font effect
            size(size_in), attr(attr_in), effect(effect_in)
    {
    }

    // Construct with font size and effect
    //
    // SEE ALSO: VfxFontDescEffectEnum
    explicit VfxFontDesc(
        VfxU8 size_in,                      // [IN] font size
        VfxFontDescEffectEnum effect_in) :  // [IN] font effect
            size(size_in), attr(VFX_FONT_DESC_ATTR_NORMAL), effect(effect_in)
    {
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    VfxFontDesc(const vm_font_desc_struct &in);
#endif

// Operator
public:
    // Assigned with another font description.
    //
    // RETURNS: Reference to the point.
    VfxFontDesc &operator =(const VfxFontDesc &in);
    
    // Compared with another font attr
    //
    // RETURNS: Return VFX_TRUE the font description is equal to the input.    
    VfxBool operator ==(const VfxFontDesc &in) const
    {
        return compareWith(in);
    }
    
    // Compared with another font description.
    //
    // RETURNS: Return VFX_TRUE the font description is *NOT* equal to the input.
    VfxBool operator !=(const VfxFontDesc &in) const
    {
        return !compareWith(in);
    }    

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_font_desc_struct() const;
#endif

// Method
public:
    // Internal used. Use the font description to initialize a VRT font structre.
    void initVrtFont(
        vrt_font_struct &font   // [OUT] The VRT font structure to be intialized
    ) const;

    // Set font attribute
    void setAttr(
        VfxFlag attr_in         // [IN] font attribute
    )
    {
        VFX_FLAG_SET(attr, attr_in);
    }

    // Clear specified font attribute
    void clearAttr(
        VfxFlag attr_in         // [IN] font attribute
    )
    {
        VFX_FLAG_CLEAR(attr, attr_in);
    }

    // Check if font description have specified font attribute
    // RETURNS: Return VFX_TURE if font description has this attributes
    VfxBool hasAttr(
        VfxFlag attr_in         // [IN] font attribute
    ) const
    {
        return (VfxBool)VFX_FLAG_HAS(attr, attr_in);
    }

    // Measure the display size of given string 
    // RETURNS: Returns the size of string to be shown
    VfxSize measureStr(
        const VfxWChar *string  // [IN] String to be measured
    ) const;
    
    // Measure the display size of given string 
    // RETURNS: Returns the size of string to be shown
    VfxSize measureStr(
        const VfxWString &string    // [IN] String to be measured
    ) const;

    // Set the font source to a given resource ID
    void setResId(
        VfxResId resId
    );

// Property
public:
    VfxU8 size;         // Font size. Default size is VFX_FONT_DESC_SIZE_MEDIUM.
    VfxFlag attr;       // Font attribute. Default attribute is VFX_FONT_DESC_ATTR_NORMAL.
    VfxU8 effect;       // Font effect. Default effect is VFX_FONT_DESC_EFFECT_NONE.

// Implementation
private:
    VfxBool compareWith(const VfxFontDesc &in) const
    {
        return ((size == in.size) && (attr == in.attr) && (effect == in.effect));
    }
};


inline
VfxFontDesc &VfxFontDesc::operator =(const VfxFontDesc &in)
{
    size = in.size;
    attr = in.attr;
    effect = in.effect;
    return *this;
}


/***************************************************************************** 
 * Class VfxFontEffect
 *****************************************************************************/

/*
 * VfxFontEffect specifiy one font effect with details params 
 *
 * Note: VFX_FONT_DESC_EFFECT_STRIKETHROUGH is not supported
 */

typedef struct _FontEffectData_
{
    vrt_font_effect_attr attr;
    vrt_font_effect_color color;
    VfxU8 attribute_id;
    VfxU8 effect_type;
    VfxU8 node_type;
    struct _FontEffectDesc_ *next;
}FontEffectData;


class VfxFontEffect : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VfxFontEffect();
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Constructor
    VfxFontEffect(vm_font_effect_struct effect);
#endif
    // Destructor
    virtual ~VfxFontEffect();

// Property
public:
    // set the font effect type 
    void setType(VfxFontEffectTypeEnum effect);
    
    // set the parameters for VFX_FONT_DESC_EFFECT_SHADOW
    void setShadow(
        VfxColor color,         // [IN] The shadow color
        VfxS16 degree,          // [IN] The degree of change of shadow color. Range is (-180) ~ (+180)
        VfxU8 distant,          // [IN] The distant between the shadow original to the text original
        VfxU8 range,            // [IN] The shadow range
        VfxU8 transparency      // [IN] The shadow intensity
        );

    // set the parameters for VFX_FONT_DESC_EFFECT_OUTER_GLOW
    void setOuterGlow(
        VfxColor color,         // [IN] The outer glow color
        VfxU8 range,            // [IN] The outer glow range
        VfxU8 transparency      // [IN] The shadow intensity
        );

    // set the parameters for VFX_FONT_DESC_EFFECT_ENHANCED_ENGRAVE
    void setEnhancedEngrave(
        VfxColor upper_color,           // [IN] The engraved color
        VfxColor lower_color,           // [IN] The engraved color
        VfxS16 degree,                  // [IN] The degree of change of shadow color. Range is (-180) ~ (+180)
        VfxU8 transparency              // [IN] The shadow intensity
        );

    // set the parameters for VFX_FONT_DESC_EFFECT_GRADIENT
    void setGradient(
        VfxColor first_color,           // [IN] The text color for gradient effect. It works with existing text color to present the gradient effect
        VfxColor second_color,          // [IN] The text color for gradient effect. It works with existing text color to present the gradient effect
        VfxU8 direction,               // [IN] The direction of gradient
        VfxU8 transparency              // [IN] The shadow intensity
        );

    // set the parameters for VFX_FONT_DESC_EFFECT_ENHANCED_BORDER
    void setEnhancedBorder(
        VfxColor color,                 // [IN] border color
        VfxU8 width,                    // [IN] The border width
        VfxU8 transparency              // [IN] The border intensity
        );
    
//Method
public:
    // get an system effect id for this effect
    VfxU8 getEffectId();

// Implementation
private:    
    FontEffectData m_desc;
};

#endif /* __VFX_FONT_DESC_H__ */

