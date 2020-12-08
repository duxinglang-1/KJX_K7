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
 *  vfx_value.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_variant.h"

#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Class VfxVariant
 *****************************************************************************/
 
VfxVariant &VfxVariant::operator = (const VfxVariant &other)
{
    if (m_type == other.m_type)
    {
        assignWith(other);
    }
    else
    {
        deinit();
        initWith(other);
    }

    return *this;
}


void VfxVariant::initWith(const VfxVariant &other)
{
    VFX_ASSERT(m_type == DATA_TYPE_NULL);

    // Assign new type
    m_type = other.m_type;
    
    // Call the destructor
    switch (other.m_type)
    {
    case DATA_TYPE_NULL:
        // Do nothing
        break;
        
    case DATA_TYPE_BOOL:
        m_value.boolValue = other.asBool();
        break;
        
    case DATA_TYPE_S32:
        m_value.s32Value = other.asS32();
        break;
        
    case DATA_TYPE_FLOAT:
        m_value.floatValue = other.asFloat();
        break;

    case DATA_TYPE_COLOR:
        new (m_value.colorBuffer) VfxColor(other.asColor());
        break;
        
    case DATA_TYPE_POINT:
        new (m_value.pointBuffer) VfxPoint(other.asPoint());
        break;
        
    case DATA_TYPE_SIZE:
        new (m_value.sizeBuffer) VfxSize(other.asSize());
        break;
        
    case DATA_TYPE_RECT:
        new (m_value.rectBuffer) VfxRect(other.asRect());
        break;
        
    case DATA_TYPE_FPOINT:
        new (m_value.fpointBuffer) VfxFPoint(other.asFPoint());
        break;
        
    case DATA_TYPE_TRANSFORM:
        new (m_value.transformBuffer) VfxTransform(other.asTransform());
        break;

    case DATA_TYPE_WSTRING:
        new (m_value.wstringBuffer) VfxWString(other.asWString());
        break;
        
    default:
        VFX_ASSERT(0);
    }
}


void VfxVariant::deinit()
{
    // TODO: Workaround for ADS compiler
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    // Call the destructor
    switch (m_type)
    {
    case DATA_TYPE_NULL:
    case DATA_TYPE_BOOL:
    case DATA_TYPE_S32:
    case DATA_TYPE_FLOAT:
    case DATA_TYPE_COLOR:
    case DATA_TYPE_POINT:
    case DATA_TYPE_SIZE:
    case DATA_TYPE_RECT:
    case DATA_TYPE_FPOINT:
    case DATA_TYPE_TRANSFORM:
        // no destructor for primitive types, do nothing
        break;

    case DATA_TYPE_WSTRING:
        ((VfxWString *)m_value.wstringBuffer)->setNull();
        break;
        
    default:
        VFX_ASSERT(0);
    }
#endif

    m_type = DATA_TYPE_NULL;
}


void VfxVariant::assignWith(const VfxVariant &other)
{
    VFX_ASSERT(m_type == other.m_type);

    switch (m_type)
    {
    case DATA_TYPE_NULL:
        // do nothing
        break;

    case DATA_TYPE_BOOL:
        m_value.boolValue = other.m_value.boolValue;
        break;

    case DATA_TYPE_S32:
        m_value.s32Value = other.m_value.s32Value;
        break;

    case DATA_TYPE_FLOAT:
        m_value.floatValue = other.m_value.floatValue;
        break;

    case DATA_TYPE_COLOR:
        *(VfxColor *)m_value.colorBuffer = *(VfxColor *)other.m_value.colorBuffer;
        break;
        
    case DATA_TYPE_POINT:
        *(VfxPoint *)m_value.pointBuffer = *(VfxPoint *)other.m_value.pointBuffer;
        break;
        
    case DATA_TYPE_SIZE:
        *(VfxSize *)m_value.sizeBuffer = *(VfxSize *)other.m_value.sizeBuffer;
        break;
        
    case DATA_TYPE_RECT:
        *(VfxRect *)m_value.rectBuffer = *(VfxRect *)other.m_value.rectBuffer;
        break;
        
    case DATA_TYPE_FPOINT:
        *(VfxFPoint *)m_value.fpointBuffer = *(VfxFPoint *)other.m_value.fpointBuffer;
        break;
        
    case DATA_TYPE_TRANSFORM:
        *(VfxTransform *)m_value.transformBuffer = *(VfxTransform *)other.m_value.transformBuffer;
        break;
        
    case DATA_TYPE_WSTRING:
        *(VfxWString *)m_value.wstringBuffer = *(VfxWString *)other.m_value.wstringBuffer;
        break;
        
    default:
        VFX_ASSERT(0);
    }    
}

