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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_primitive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the launcher primitives.
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

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher_def.h"
#include "vapp_launcher_primitive.h"


/*****************************************************************************
 * Launcher ID
 *****************************************************************************/

VappLauncherId::VappLauncherId() :
    m_source(VAPP_LAUNCHER_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    // Do nothing.
}


VappLauncherId::VappLauncherId(VappLauncherSrcEnum source, VfxS32 type) :
    m_source(VAPP_LAUNCHER_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, type);
}


VappLauncherId::VappLauncherId(
    VappLauncherSrcEnum source,
    const VfxChar *typeString)
    :
    m_source(VAPP_LAUNCHER_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, typeString);
}


VappLauncherId::VappLauncherId(const VappLauncherId &other) :
    m_source(VAPP_LAUNCHER_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(other);
}


VappLauncherId::~VappLauncherId()
{
    clear();
}


VappLauncherId &VappLauncherId::operator =(const VappLauncherId &other)
{
    assignWith(other);

    return *this;
}


VfxBool VappLauncherId::operator ==(const VappLauncherId &other) const
{
    return compareWith(other);
}


VfxBool VappLauncherId::operator !=(const VappLauncherId &other) const
{
    return compareWith(other) ? VFX_FALSE : VFX_TRUE;
}


void VappLauncherId::assignWith(const VappLauncherId &other)
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

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappLauncherId::assignWith(VappLauncherSrcEnum source, VfxS32 type)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_INTEGER;
    m_type.ival = type;
}


void VappLauncherId::assignWith(
    VappLauncherSrcEnum source,
    const VfxChar *typeString)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_STRING;
    assignTypeString(typeString);
}


VfxBool VappLauncherId::compareWith(const VappLauncherId &other) const
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

        default:
            break;
    }

    return VFX_TRUE;
}


VappLauncherSrcEnum VappLauncherId::getSource() const
{
    return m_source;
}


VappLauncherId::TypeKindEnum VappLauncherId::getTypeKind() const
{
    return m_typeKind;
}


VfxS32 VappLauncherId::getIntType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_INTEGER);

    return m_type.ival;
}


const VfxChar *VappLauncherId::getStringType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_STRING);

    return m_type.sval;
}


void VappLauncherId::decodeFromArchive(VfxArchive *ar)
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
            assignWith((VappLauncherSrcEnum)source, (VfxS32)type);
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

            assignWith((VappLauncherSrcEnum)source, string);

            VFX_SYS_FREE_MEM(string);

            break;
        }
        default:
        {
            VFX_ASSERT(0); // Archive file might be corrupted.
            break;
        }
    }
}


void VappLauncherId::encodeToArchive(VfxArchive *ar) const
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
        default:
        {
            VFX_ASSERT(0);  // ID is invalid.
            break;
        }
    }
}


VappLauncherId **VappLauncherId::newArray(VfxS32 size, VfxObject *parent)
{
    VappLauncherId **array;

    VFX_ALLOC_MEM(array, size * sizeof(VappLauncherId *), parent);

    for (VfxS32 i = 0; i < size; i++)
    {
        VFX_ALLOC_NEW(array[i], VappLauncherId, parent);
    }

    return array;
}


void VappLauncherId::deleteArray(VappLauncherId **array, VfxS32 size)
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


void VappLauncherId::clear()
{
    m_typeKind = TYPE_KIND_UNKNOWN;
}


void VappLauncherId::assignTypeString(const VfxChar *typeString)
{
    if (typeString)
    {
        strncpy(m_type.sval, typeString, MMI_APP_NAME_MAX_LEN - 1);
        m_type.sval[MMI_APP_NAME_MAX_LEN - 1] = '\0';
    }
}

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
