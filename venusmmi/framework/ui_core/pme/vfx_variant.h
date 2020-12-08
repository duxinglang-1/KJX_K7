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
 *  vfx_variant.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  VfxVariant is a union for the most common types.
 *  It supports these types:
 *  - VfxBool
 *  - VfxS32
 *  - VfxFloat
 *  - VfxColor
 *  - VfxPoint
 *  - VfxSize
 *  - VfxRect
 *  - VfxTransform
 *  - VfxWString
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_VARIANT_H__
#define __VFX_VARIANT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"

#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Class VfxVariant
 *****************************************************************************/

/*
 * VfxVariant is a union for the common types
 */
class VfxVariant : public VfxBase
{
// Define
public:
    // Value type enum
    enum ValueTypeEnum
    {
        // Null type
        DATA_TYPE_NULL,
        // VfxBool type
        DATA_TYPE_BOOL,
        // VfxS32 type
        DATA_TYPE_S32,
        // VfxFloat type
        DATA_TYPE_FLOAT,
        // VfxColor type
        DATA_TYPE_COLOR,
        // VfxPoint type
        DATA_TYPE_POINT,
        // VfxSize type
        DATA_TYPE_SIZE,
        // VfxRect type
        DATA_TYPE_RECT,
        // VfxFPoint type
        DATA_TYPE_FPOINT,
        // VfxTransfrom type
        DATA_TYPE_TRANSFORM,
        // VfxWString type
        DATA_TYPE_WSTRING,
        DATA_TYPE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxVariant() : m_type(DATA_TYPE_NULL)
    {
    }
    
    // Copy constructor
    explicit VfxVariant(const VfxVariant &other) : m_type(DATA_TYPE_NULL)
    {
        initWith(other);
    }
    
    // Destructor
    ~VfxVariant()
    {
        deinit();
    }

    /*
     * construct by value in different types
     */
    explicit VfxVariant(VfxBool value);
    explicit VfxVariant(VfxS32 value);
    explicit VfxVariant(VfxFloat value);
    explicit VfxVariant(const VfxColor &value);
    explicit VfxVariant(const VfxPoint &value);
    explicit VfxVariant(const VfxSize &value);
    explicit VfxVariant(const VfxRect &value);
    explicit VfxVariant(const VfxFPoint &value);
    explicit VfxVariant(const VfxTransform &value);
    explicit VfxVariant(const VfxWString &value);

// Method
public:
    // Return the value type of the variant
    ValueTypeEnum get_type() const
    {
        return m_type;
    }

    // Get value as VfxBool type in the variant
    VfxBool asBool() const;
    // Get value as VfxS32 type in the variant
    VfxS32 asS32() const;
    // Get value as VfxFloat type in the variant
    VfxFloat asFloat() const;
    // Get value as VfxColor type in the variant
    const VfxColor &asColor() const;
    // Get value as VfxPoint type in the variant
    const VfxPoint &asPoint() const;
    // Get value as VfxSize type in the variant
    const VfxSize &asSize() const;
    // Get value as VfxRect type in the variant
    const VfxRect &asRect() const;
    // Get value as VfxFPoint type in the variant
    const VfxFPoint &asFPoint() const;
    // Get value as VfxTransform type in the variant
    const VfxTransform &asTransform() const;
    // Get value as VfxWString type in the variant
    const VfxWString &asWString() const;

// Operator
public:
    // operator =
    VfxVariant &operator = (const VfxVariant &other);

private:
    // the type of the value stored in the variant
    ValueTypeEnum m_type;

    // the value stored in the variant
    union
    {
        /*
         * Primitive types
         */
        VfxBool     boolValue;
        VfxS32      s32Value;
        VfxFloat    floatValue;

        /*
         * Classes
         */
        VfxU8       colorBuffer[sizeof(VfxColor)];
        VfxU8       pointBuffer[sizeof(VfxPoint)];
        VfxU8       sizeBuffer[sizeof(VfxSize)];
        VfxU8       rectBuffer[sizeof(VfxRect)];
        VfxU8       fpointBuffer[sizeof(VfxFPoint)];
        VfxU8       transformBuffer[sizeof(VfxTransform)];
        VfxU8       wstringBuffer[sizeof(VfxWString)];
    } m_value;

    void initWith(const VfxVariant &other);
    void deinit();
    void assignWith(const VfxVariant &other);    
};

inline
VfxVariant::VfxVariant(VfxBool value) : m_type(DATA_TYPE_BOOL)
{
    m_value.boolValue = value;
}

inline
VfxVariant::VfxVariant(VfxS32 value) : m_type(DATA_TYPE_S32)
{
    m_value.s32Value = value;
}

inline
VfxVariant::VfxVariant(VfxFloat value) : m_type(DATA_TYPE_FLOAT)
{
    m_value.floatValue = value;
}

inline
VfxVariant::VfxVariant(const VfxColor &value) : m_type(DATA_TYPE_COLOR)
{
    new (m_value.colorBuffer) VfxColor(value);
}

inline
VfxVariant::VfxVariant(const VfxPoint &value) : m_type(DATA_TYPE_POINT)
{
    new (m_value.pointBuffer) VfxPoint(value);
}

inline
VfxVariant::VfxVariant(const VfxSize &value) : m_type(DATA_TYPE_SIZE)
{
    new (m_value.sizeBuffer) VfxSize(value);
}

inline
VfxVariant::VfxVariant(const VfxRect &value) : m_type(DATA_TYPE_RECT)
{
    new (m_value.rectBuffer) VfxRect(value);
}

inline
VfxVariant::VfxVariant(const VfxFPoint &value) : m_type(DATA_TYPE_FPOINT)
{
    new (m_value.fpointBuffer) VfxFPoint(value);
}

inline
VfxVariant::VfxVariant(const VfxTransform &value) : m_type(DATA_TYPE_TRANSFORM)
{
    new (m_value.transformBuffer) VfxTransform(value);
}

inline
VfxVariant::VfxVariant(const VfxWString &value) : m_type(DATA_TYPE_WSTRING)
{
    new (m_value.wstringBuffer) VfxWString(value);
}

inline
VfxBool VfxVariant::asBool() const
{
    VFX_ASSERT(m_type == DATA_TYPE_BOOL);
    return m_value.boolValue;
}

inline
VfxS32 VfxVariant::asS32() const
{
    VFX_ASSERT(m_type == DATA_TYPE_S32);
    return m_value.s32Value;
}

inline
VfxFloat VfxVariant::asFloat() const
{
    VFX_ASSERT(m_type == DATA_TYPE_FLOAT);
    return m_value.floatValue;
}

inline
const VfxColor &VfxVariant::asColor() const
{
    VFX_ASSERT(m_type == DATA_TYPE_COLOR);
    return *(VfxColor *)m_value.colorBuffer;
}

inline
const VfxPoint &VfxVariant::asPoint() const
{
    VFX_ASSERT(m_type == DATA_TYPE_POINT);
    return *(VfxPoint *)m_value.pointBuffer;
}

inline
const VfxSize &VfxVariant::asSize() const
{
    VFX_ASSERT(m_type == DATA_TYPE_SIZE);
    return *(VfxSize *)m_value.sizeBuffer;
}

inline
const VfxRect &VfxVariant::asRect() const
{
    VFX_ASSERT(m_type == DATA_TYPE_RECT);
    return *(VfxRect *)m_value.rectBuffer;
}

inline
const VfxFPoint &VfxVariant::asFPoint() const
{
    VFX_ASSERT(m_type == DATA_TYPE_FPOINT);
    return *(VfxFPoint *)m_value.fpointBuffer;
}

inline
const VfxTransform &VfxVariant::asTransform() const
{
    VFX_ASSERT(m_type == DATA_TYPE_TRANSFORM);
    return *(VfxTransform *)m_value.transformBuffer;
}

inline
const VfxWString &VfxVariant::asWString() const
{
    VFX_ASSERT(m_type == DATA_TYPE_WSTRING);
    return *(VfxWString *)m_value.wstringBuffer;
}


/***************************************************************************** 
 * Class VfxVariantUtil
 *****************************************************************************/
 
/*
 * Internal used. VfxVariantUtil provides the type information.
 */
template <class _value_type>
class VfxVariantUtil
{
public:
    typedef _value_type ret_type;
    typedef _value_type arg_type;
};


template <>
class VfxVariantUtil <VfxBool>
{
public:
    typedef VfxBool ret_type;
    typedef VfxBool arg_type;
    
    inline
    static VfxBool getVariantValue(const VfxVariant &variant)
    {
        return variant.asBool();
    }
};

template <>
class VfxVariantUtil <VfxS32>
{
public:
    typedef VfxS32 ret_type;
    typedef VfxS32 arg_type;
    
    inline
    static VfxS32 getVariantValue(const VfxVariant &variant)
    {
        return variant.asS32();
    }
};

template <>
class VfxVariantUtil <VfxFloat>
{
public:
    typedef VfxFloat ret_type;
    typedef VfxFloat arg_type;
    
    inline
    static VfxFloat getVariantValue(const VfxVariant &variant)
    {
        return variant.asFloat();
    }
};

template <>
class VfxVariantUtil <VfxColor>
{
public:
    typedef const VfxColor &ret_type;
    typedef const VfxColor &arg_type;
    
    inline
    static const VfxColor &getVariantValue(const VfxVariant &variant)
    {
        return variant.asColor();
    }
};

template <>
class VfxVariantUtil <VfxPoint>
{
public:
    typedef const VfxPoint &ret_type;
    typedef const VfxPoint &arg_type;
    
    inline
    static const VfxPoint &getVariantValue(const VfxVariant &variant)
    {
        return variant.asPoint();
    }
};

template <>
class VfxVariantUtil <VfxSize>
{
public:
    typedef const VfxSize &ret_type;
    typedef const VfxSize &arg_type;
    
    inline
    static const VfxSize &getVariantValue(const VfxVariant &variant)
    {
        return variant.asSize();
    }
};

template <>
class VfxVariantUtil <VfxRect>
{
public:
    typedef const VfxRect &ret_type;
    typedef const VfxRect &arg_type;
    
    inline
    static const VfxRect &getVariantValue(const VfxVariant &variant)
    {
        return variant.asRect();
    }
};

template <>
class VfxVariantUtil <VfxFPoint>
{
public:
    typedef const VfxFPoint &ret_type;
    typedef const VfxFPoint &arg_type;
    
    inline
    static const VfxFPoint &getVariantValue(const VfxVariant &variant)
    {
        return variant.asFPoint();
    }
};

template <>
class VfxVariantUtil <VfxTransform>
{
public:
    typedef const VfxTransform &ret_type;
    typedef const VfxTransform &arg_type;
    
    inline
    static const VfxTransform &getVariantValue(const VfxVariant &variant)
    {
        return variant.asTransform();
    }
};

template <>
class VfxVariantUtil <VfxWString>
{
public:
    typedef const VfxWString &ret_type;
    typedef const VfxWString &arg_type;
    
    inline
    static const VfxWString &getVariantValue(const VfxVariant &variant)
    {
        return variant.asWString();
    }
};

#endif /* __VFX_VARIANT_H__ */

