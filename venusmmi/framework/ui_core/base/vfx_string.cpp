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
 *  vfx_string.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Basic String Type Class
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
 * removed!
 *
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
 
#include "vfx_string.h"
// For vfx_sys_wcslen(), etc.
#include "vfx_system.h"

#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_cpp_base.h"
#include "vfx_config.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>


/***************************************************************************** 
 * Class VfxWString
 *****************************************************************************/

VfxWString::VfxWString(VfxResId resId) :
    m_bufType(BUF_TYPE_NONE)
{
    m_value.buf = NULL;

    const VfxWChar *buf = vfxSysResGetStr(resId);
    if (buf != NULL)
    {
        m_value.resId = resId;
        m_bufType = BUF_TYPE_RESOURCE;
    }
}


VfxWString::VfxWString(const VfxWChar *str) :
    m_bufType(BUF_TYPE_DYNAMIC)
{
    m_value.buf = cloneBuf(str);

    if (m_value.buf == NULL)
    {
        m_bufType = BUF_TYPE_NONE;
    }
}


VfxWString::VfxWString(const VfxWStringConstHelper &initializer) :
    m_bufType(BUF_TYPE_NONE)
{
    m_value.buf = initializer.getString();
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxWString::VfxWString(const vm_wstring_struct &string) :
    m_bufType(BUF_TYPE_NONE)
{
    m_value.buf = NULL;

    if (string.m_buf == NULL)
    {
        // do nothing
        return;
    }

    // Clone the string data
    VfxU32 len = vfx_sys_wcslen(string.m_buf);
    VfxWChar *buf;
    VFX_SYS_ALLOC_MEM(buf, sizeof(VfxWChar) * (len + 1));
    vfx_sys_wcscpy(buf, string.m_buf);
    m_value.buf = buf;
    m_bufType = BUF_TYPE_DYNAMIC;
}


VfxWString::operator vm_wstring_struct() const
{
    vm_wstring_struct ret;
    ret.m_bufType = (vm_wstring_buf_type_enum)m_bufType;
    ret.m_buf = m_value.buf;
    return ret;
}

#endif


VfxWString &VfxWString::operator =(const VfxWString &other)
{    
    if ((m_bufType != other.m_bufType) || (getBuf() != other.getBuf()))
    {
        clear();
        assignWith(other);
    }
    return *this;
}


VfxWChar *VfxWString::lockBuf(VfxU32 initialLength)
{
    VFX_ASSERT(initialLength > 0);
    // NOTE: The string buffer is locked
    VFX_ASSERT(!VFX_FLAG_HAS(m_bufType, BUF_TYPE_LOCK));

    // Create new buffer
    VfxWChar *buf;
    const VfxWChar *oriBuf;
    VFX_SYS_ALLOC_MEM(buf, initialLength * sizeof(VfxWChar));

    oriBuf = getBuf(); 

    // Copy content of original buffer 
    if (oriBuf != NULL)
    {
        VfxU32 originLength = vfx_sys_wcslen(oriBuf) + 1;
        if (originLength <= initialLength)
        {
            memcpy(buf, oriBuf, originLength * sizeof(VfxWChar));
        }
        else
        {
            memcpy(buf, oriBuf, (initialLength - 1) * sizeof(VfxWChar));
            buf[initialLength - 1] = 0;
        }
    }
    else
    {
        buf[0] = 0;
    }

    clear();

    // Update
    m_value.buf = buf;
    m_bufType = BUF_TYPE_LOCK;

    return buf;
}


void VfxWString::unlockBuf()
{
    // NOTE: The string buffer is not locked
    VFX_ASSERT(VFX_FLAG_HAS(m_bufType, BUF_TYPE_LOCK));
    
    VFX_DEV_ASSERT(m_value.buf != NULL);

    const VfxWChar *buf = cloneBuf(m_value.buf);

    // free
    VfxWChar *p = (VfxWChar *)m_value.buf;
    VFX_SYS_FREE_MEM(p);

    // Update
    m_value.buf = buf;
    m_bufType = BUF_TYPE_DYNAMIC;
}


const VfxWChar *VfxWString::getBuf() const
{
    if (m_bufType == BUF_TYPE_RESOURCE)
    {
        return vfxSysResGetStr(m_value.resId);
    }

    return m_value.buf;
}


VfxU32 VfxWString::getLength() const
{
    const VfxWChar *buf = getBuf();
    return buf ? vfx_sys_wcslen(buf) : 0;
}


VfxWString &VfxWString::setEmpty()
{
    // Clear the original data
    clear();

    m_value.buf = (const VfxWChar *)L"";
    m_bufType = BUF_TYPE_NONE;

    return *this;
}


VfxWString &VfxWString::loadFromRes(VfxResId res_id)
{
    // Clear the original data
    clear();

    const VfxWChar *buf = vfxSysResGetStr(res_id);
    if (buf != NULL)
    {
        // Update
        m_value.resId = res_id;
        m_bufType = BUF_TYPE_RESOURCE;
    }

    return *this;
}


VfxWString &VfxWString::loadFromMem(const VfxWChar *mem)
{
    // Clear the original data
    clear();

    const VfxWChar *buf = cloneBuf(mem);
    if (buf != NULL)
    {
        // Update
        m_value.buf = buf;
        m_bufType = BUF_TYPE_DYNAMIC;
    }

    return *this;
}


VfxWString &VfxWString::format(const VfxChar *formatStr, ...)
{
    // Clear the original data
    clear();

    // Generate the string data
    VfxChar tmpBuf[VFX_WSTRING_FORMAT_MAX_LEN];
    va_list args;
    va_start(args, formatStr);    
    VfxU32 length = vsprintf(
        tmpBuf, 
        //VFX_WSTRING_FORMAT_MAX_LEN - 1, 
        formatStr, 
        args);
    va_end(args);

    // Clone the string data
    VfxWChar *buf;
    VFX_SYS_ALLOC_MEM(buf, sizeof(VfxWChar) * (length + 1));
    vfx_sys_mbstowcs(buf, tmpBuf, length + 1);

    // Update
    m_value.buf = buf;
    m_bufType = BUF_TYPE_DYNAMIC;

    return *this;
}


VfxWString &VfxWString::format(const VfxWChar *formatStr, ...)
{
    // Clear the original data
    clear();

    // Generate the string data
    VfxWChar tmpBuf[VFX_WSTRING_FORMAT_MAX_LEN];
    va_list args;
    va_start(args, formatStr);
    VfxU32 length = vfx_sys_vswprintf(
        tmpBuf, 
        VFX_WSTRING_FORMAT_MAX_LEN - 1, 
        formatStr, 
        args);
    va_end(args);

    // Clone the string data
    VfxWChar *buf;
    VFX_SYS_ALLOC_MEM(buf, sizeof(VfxWChar) * (length + 1));
    vfx_sys_wcscpy(buf, tmpBuf);

    // Update
    m_value.buf = buf;
    m_bufType = BUF_TYPE_DYNAMIC;

    return *this;
}


const VfxWChar *VfxWString::cloneBuf(const VfxWChar *buf)
{
    if (buf == NULL)
    {
        return NULL;
    }
    
    // Clone the string data
    VfxU32 size = sizeof(VfxWChar) * (vfx_sys_wcslen(buf) + 1);
    VfxWChar *cloned;
    VFX_SYS_ALLOC_MEM(cloned, size);
    memcpy(cloned, buf, size);
    return cloned;
}


void VfxWString::clear()
{
    // Free buffer if needed (the buffer is allocated from dynamic pool)
    if (VFX_FLAG_HAS(m_bufType, BUF_TYPE_DYNAMIC))
    {
        // De-const
        VfxWChar *p = (VfxWChar *)m_value.buf;
        VFX_SYS_FREE_MEM(p);
    }

    // Update
    m_value.buf = NULL;
    m_bufType = BUF_TYPE_NONE;
}


void VfxWString::assignWith(const VfxWString &other)
{
    VFX_ASSERT(m_bufType == BUF_TYPE_NONE && m_value.buf == NULL);

    if (other.isNull())
    {
        // do nothing
        return;
    }

    if (VFX_FLAG_HAS(other.m_bufType, BUF_TYPE_DYNAMIC))
    {
        // Clone the string data
        VfxU32 size = sizeof(VfxWChar) * (vfx_sys_wcslen(other.m_value.buf) + 1);
        VfxWChar *buf;
        VFX_SYS_ALLOC_MEM(buf, size);
        vfx_sys_wcscpy(buf, other.m_value.buf);
        m_value.buf = buf;
    }
    else if (VFX_FLAG_HAS(other.m_bufType, BUF_TYPE_RESOURCE))
    {
        m_value.resId = other.m_value.resId;
    }
    else
    {
        // Direct copy the pointer
        m_value.buf = other.m_value.buf;
    }
    
    // Update
    m_bufType = other.m_bufType;
}


void VfxWString::appendWith(const VfxWString &other)
{
    if (other.isNull() || other.isEmpty())
    {
        // Do nothing
        return;
    }
    
    if (isNull() || isEmpty())
    {
        clear();
        assignWith(other);
        return;
    }

    // Alloc a new buffer and copy the the content
    VfxU32 len_this = getLength();
    VfxU32 len_other = other.getLength(); 
    
    VfxWChar *buf;
    VFX_SYS_ALLOC_MEM(buf, sizeof(VfxWChar) * (len_this + len_other + 1));
    vfx_sys_wcscpy(buf, getBuf());
    vfx_sys_wcscpy(buf + len_this, other.getBuf());

    // Clear the original buffer
    clear();

    // Update the buffer and its type
    m_value.buf = buf;
    m_bufType = BUF_TYPE_DYNAMIC;
}


VfxS32 VfxWString::compareWith(const VfxWString &other) const
{
    const VfxWChar *buf = getBuf();
    const VfxWChar *otherBuf = other.getBuf();

    // If pointer to the same buffer, return 0
    if (buf == otherBuf)
    {
        return 0;
    }

    // Check if there is a NULL string    
    if (buf != NULL && otherBuf == NULL)
    {
        return -1;
    }
    else if (buf == NULL && otherBuf != NULL)
    {
        return 1;
    }

    return vfx_sys_wcscmp(buf, otherBuf);
}

