/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_wallpaper_id.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the screen lock's primitive class
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include <string.h>

#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_id.h"
extern "C"
{
#include "Unicodexdcl.h"
}
/*****************************************************************************
 * Screen Lock Id Class
 *****************************************************************************/

VappWallpaperId::VappWallpaperId() :
    m_source(VAPP_WALLPAPER_FACTORY_UNKNOWN),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    // Do nothing.
}

VappWallpaperId::VappWallpaperId(VappWallpaperFactorySrcEnum source, VfxS32 type) :
    m_source(VAPP_WALLPAPER_FACTORY_UNKNOWN),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, type);
}


VappWallpaperId::VappWallpaperId(
    VappWallpaperFactorySrcEnum source,
    const VfxChar *typeString)
    :
    m_source(VAPP_WALLPAPER_FACTORY_UNKNOWN),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, typeString);
}


VappWallpaperId::VappWallpaperId(const VappWallpaperId &other) :
    m_source(VAPP_WALLPAPER_FACTORY_UNKNOWN),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(other);
}


VappWallpaperId::~VappWallpaperId()
{
    clear();
}


VappWallpaperId &VappWallpaperId::operator =(const VappWallpaperId &other)
{
    assignWith(other);

    return *this;
}


VfxBool VappWallpaperId::operator ==(const VappWallpaperId &other) const
{
    return compareWith(other);
}


VfxBool VappWallpaperId::operator !=(const VappWallpaperId &other) const
{
    return compareWith(other) ? VFX_FALSE : VFX_TRUE;
}


void VappWallpaperId::assignWith(const VappWallpaperId &other)
{
    clear();

    m_source = other.m_source;
    m_typeKind = other.m_typeKind;

    switch (other.m_typeKind)
    {
        case TYPE_KIND_INTEGER:
            m_type.ival = other.m_type.ival;
            break;

        case TYPE_KIND_STRING:
            assignTypeString(other.m_type.sval);
            break;

        case TYPE_KIND_INT_PAIR:
            m_type.pval = other.m_type.pval;
            break;

        case TYPE_KIND_WSTRING:
            assignTypeWString(other.m_type.wsval);
            break;
        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappWallpaperId::assignWith(VappWallpaperFactorySrcEnum source, VfxS32 type)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_INTEGER;
    m_type.ival = type;
}


void VappWallpaperId::assignWith(
    VappWallpaperFactorySrcEnum source,     // [IN] Source
    VfxU32 first,                    // [IN] Integer type
    VfxU32 second)
{
    clear();
    m_source = source;
    m_typeKind = TYPE_KIND_INT_PAIR;
    m_type.pval.first = first;
    m_type.pval.second = second;
}

void VappWallpaperId::assignWith(
    VappWallpaperFactorySrcEnum source,
    const VfxChar *typeString)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_STRING;
    assignTypeString(typeString);
}

void VappWallpaperId::assignWith(
    VappWallpaperFactorySrcEnum source,
    const VfxWChar *type)
{
    clear();
    m_source = source;
    m_typeKind = TYPE_KIND_WSTRING;
    assignTypeWString(type);
}

VfxBool VappWallpaperId::compareWith(const VappWallpaperId &other) const
{
    if (m_source != other.m_source || m_typeKind != other.m_typeKind)
    {
        return VFX_FALSE;
    }

    switch (m_typeKind)
    {
        case TYPE_KIND_INTEGER:
            if (m_type.ival != other.m_type.ival)
            {
                return VFX_FALSE;
            }
            break;

        case TYPE_KIND_STRING:
            if (strcmp(m_type.sval, other.m_type.sval) != 0)
            {
                return VFX_FALSE;
            }
            break;
            
        case TYPE_KIND_INT_PAIR:
            if (m_type.pval.first != other.m_type.pval.first ||
                m_type.pval.second != other.m_type.pval.second)
            {
                return VFX_FALSE;
            }
            break;

        case TYPE_KIND_WSTRING:
            if (mmi_wcscmp(m_type.wsval, other.m_type.wsval) != 0)
            {
                return VFX_FALSE;
            }
            break;
        default:
            break;
    }

    return VFX_TRUE;
}


VappWallpaperFactorySrcEnum VappWallpaperId::getSource() const
{
    return m_source;
}


VappWallpaperId::TypeKindEnum VappWallpaperId::getTypeKind() const
{
    return m_typeKind;
}


VfxS32 VappWallpaperId::getIntType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_INTEGER);

    return m_type.ival;
}

void VappWallpaperId::getIntPairType(VfxU32 &first, VfxU32 &second) const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_INT_PAIR);
    first = m_type.pval.first;
    second = m_type.pval.second;
    return;
}

const VfxChar *VappWallpaperId::getStringType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_STRING);
    return m_type.sval;
}

const VfxWChar *VappWallpaperId::getWStringType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_WSTRING);
    return m_type.wsval;
}

void VappWallpaperId::decodeFromArchive(VfxArchive *ar)
{
    //
    // Source and TypeKind
    //
    VfxU32 source = ar->readU32();
    VfxU32 typeKind = ar->readU32();

    //
    // Type
    //
    switch (typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            VfxU32 type = ar->readU32();
            assignWith((VappWallpaperFactorySrcEnum)source, (VfxS32)type);
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = ar->readU32();

            VfxChar *string;

            VFX_SYS_ALLOC_MEM(string, sizeof(VfxChar) * (length + 1));
            if (length > 0)
            {
                ar->read((VfxU8 *)string, sizeof(VfxChar) * length);
            }

            string[length] = '\0';

            assignWith((VappWallpaperFactorySrcEnum)source, string);

            VFX_SYS_FREE_MEM(string);

            break;
        }
        case TYPE_KIND_INT_PAIR:
        {
            const VfxU32 first = ar->readU32();
            const VfxU32 second = ar->readU32();
            assignWith((VappWallpaperFactorySrcEnum)source, first, second);
            break;
        }

        case TYPE_KIND_WSTRING:
        {
            VfxWString wstr;
            ar->readWString(wstr);
            assignWith((VappWallpaperFactorySrcEnum)source, wstr.getBuf());
            break;
        }
        
        default:
        {
            VFX_ASSERT(0); // Archive file might be corrupted.
            break;
        }
    }
}


void VappWallpaperId::encodeToArchive(VfxArchive *ar) const
{
    //
    // Source and TypeKind
    //
    ar->writeU32(m_source);
    ar->writeU32(m_typeKind);

    //
    // Type
    //
    switch (m_typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            ar->writeU32(m_type.ival);
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = strlen(m_type.sval);

            ar->writeU32(length);

            if (length > 0)
            {
                ar->write((VfxU8 *)m_type.sval, sizeof(VfxChar) * length);
            }
            break;
        }
        case TYPE_KIND_INT_PAIR:
        {
            ar->writeU32(m_type.pval.first);
            ar->writeU32(m_type.pval.second);
            break;
        }
        
        case TYPE_KIND_WSTRING:
        {
            VfxWString wstr = VFX_WSTR_MEM(m_type.wsval);
            ar->writeWString(wstr);
            break;
        }
        
        default:
        {
            VFX_ASSERT(0);  // ID is invalid.
            break;
        }
    }
}


VappWallpaperId **VappWallpaperId::newArray(VfxS32 size, VfxObject *parent)
{
    VappWallpaperId **array;

    VFX_ALLOC_MEM(array, size * sizeof(VappWallpaperId *), parent);

    for (VfxS32 i = 0; i < size; i++)
    {
        VFX_ALLOC_NEW(array[i], VappWallpaperId, parent);
    }

    return array;
}


void VappWallpaperId::deleteArray(VappWallpaperId **array, VfxS32 size)
{
    if (array)
    {
        for (VfxS32 i = 0; i < size; i++)
        {
            VFX_DELETE(array[i]);
        }

        VFX_FREE_MEM(array);
    }
}


void VappWallpaperId::clear()
{
    if (m_typeKind == TYPE_KIND_STRING && m_type.sval)
    {
        VFX_SYS_FREE_MEM(m_type.sval);
    }
    else if(m_typeKind == TYPE_KIND_WSTRING && m_type.wsval)
    {
        VFX_SYS_FREE_MEM(m_type.wsval);
    }

    m_typeKind = TYPE_KIND_UNKNOWN;
}


void VappWallpaperId::assignTypeString(const VfxChar *typeString)
{
    if (typeString)
    {
        VfxS32 len = strlen(typeString);

        VFX_SYS_ALLOC_MEM(m_type.sval, sizeof(VfxChar) * (len + 1));

        strncpy(m_type.sval, typeString, len);
        m_type.sval[len] = '\0';
    }
}

void VappWallpaperId::assignTypeWString(const VfxWChar *typeString)
{
    if (typeString)
    {
        VfxS32 len = mmi_wcslen(typeString);

        VFX_SYS_ALLOC_MEM(m_type.wsval, sizeof(VfxWChar) * (len + 1));

        mmi_wcsncpy(m_type.wsval, typeString, len);
        m_type.wsval[len] = '\0';
    }
}
