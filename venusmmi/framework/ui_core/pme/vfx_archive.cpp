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
 *  vfx_archive.cpp
 *
 * Project:
 * --------
 *  Venus UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_archive.h"

#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include <string.h>


/***************************************************************************** 
 * Class VfxMemArchiveSource
 *****************************************************************************/

VfxMemArchiveSource::VfxMemArchiveSource(VfxU32 spaceSize) :
    m_mode(VfxMemArchiveSource::WRITE_MODE),
    m_dataSize(0),
    m_freeSpaceSize(spaceSize),
    isLimit(VFX_TRUE)
{
    // default to write mode
    VFX_ALLOC_MEM(m_dataPtr, m_freeSpaceSize, this);
    VFX_DEV_ASSERT(m_dataPtr);
}


VfxMemArchiveSource::VfxMemArchiveSource() :
    m_mode(VfxMemArchiveSource::WRITE_MODE),
    m_dataSize(0),
    m_freeSpaceSize(ARCHIVE_DEFAULT_SPACE_SIZE),
    isLimit(VFX_FALSE)
{
    // default to write mode
    VFX_ALLOC_MEM(m_dataPtr, m_freeSpaceSize, this);
    VFX_DEV_ASSERT(m_dataPtr);
}


VfxMemArchiveSource::~VfxMemArchiveSource()
{
    VFX_FREE_MEM(m_dataPtr);
}


VfxU32 VfxMemArchiveSource::write(VfxU8* data, VfxU32 size)
{
    VFX_DEV_ASSERT(m_mode == VfxMemArchiveSource::WRITE_MODE);

    if (size > 0)
    {
        VFX_DEV_ASSERT(m_dataPtr);
        if (size > m_freeSpaceSize)
        {
            if (isLimit)
            {
                // AP use more memory than default limit.
                VFX_ASSERT(0);
            }        
            enlargeSpace(size);
        }
        memcpy(m_dataPtr+m_dataSize, data, size);
        m_dataSize += size;
        m_freeSpaceSize -= size;
    }
    return size;
}


VfxU32 VfxMemArchiveSource::read(VfxU8* data, VfxU32 size)
{
    VFX_DEV_ASSERT(m_mode == VfxMemArchiveSource::READ_MODE);

    VfxU32 readSize = m_dataPtr + m_dataSize - m_readPtr;    
    if (size < readSize)
    {
        readSize = size;
    }
    
    if (readSize)
    {
        memcpy(data, m_readPtr, readSize);
        m_readPtr += readSize;
    }
    
    return readSize;
}


void VfxMemArchiveSource::attachBuffer(VfxU8 *buf, VfxU32 dataSize)
{
    // zero dataSize is valid
    VFX_ASSERT(buf);  

    VFX_FREE_MEM(m_dataPtr);

    // buffer is attached, change to read mode
    m_mode          = VfxMemArchiveSource::READ_MODE;
    
    m_dataPtr       = buf;
    m_dataSize      = dataSize;
    m_readPtr       = buf;
}


void VfxMemArchiveSource::detachBuffer(VfxU8 **buf, VfxU32 *dataSize)
{
    if (!m_dataPtr)
    {
        *buf        = NULL;
        *dataSize   = 0;
        return;
    }
    
    *buf        = m_dataPtr;
    *dataSize   = m_dataSize;
    m_dataPtr   = NULL;
    m_dataSize  = 0;
}


void VfxMemArchiveSource::enlargeSpace(VfxU32 extraRequired)
{
    VfxU8 *newPtr;

    // double space by default
    if (extraRequired <= m_dataSize)
    {
        extraRequired = m_dataSize;
    }

    VFX_ALLOC_MEM(newPtr, m_dataSize + extraRequired, this);
    VFX_DEV_ASSERT(newPtr);
    
    memcpy(newPtr, m_dataPtr, m_dataSize);
    VFX_FREE_MEM(m_dataPtr);
    
    m_freeSpaceSize = extraRequired;
    m_dataPtr = newPtr;
}


/***************************************************************************** 
 * Class VfxArchive
 *****************************************************************************/

VfxArchive::VfxArchive() : 
    m_arSource(NULL)
{
}


void VfxArchive::setSource(IVfxArchiveSource *arSource)
{
    m_arSource = arSource;
}


void VfxArchive::write(VfxU8 *data, VfxU32 size)
{
    m_arSource->write(data, size);
}


void VfxArchive::writeU8(VfxU8 data)
{
    m_arSource->write((VfxU8*)&data, sizeof(VfxU8));
}


void VfxArchive::writeU16(VfxU16 data)
{
    m_arSource->write((VfxU8*)&data, sizeof(VfxU16));
}


void VfxArchive::writeU32(VfxU32 data)
{
    m_arSource->write((VfxU8*)&data, sizeof(VfxU32));
}


void VfxArchive::writeWString(const VfxWString &str)
{
    VfxU32 length = str.getLength();
    writeU32(length);
    if (length != 0)
    {
        write((VfxU8 *)str.getBuf(), length * sizeof(VfxWChar));
    }
}


void VfxArchive::writePoint(const VfxPoint &pt)
{
    writeU32((VfxU32)pt.x);
    writeU32((VfxU32)pt.y);
}


void VfxArchive::writeFPoint(const VfxFPoint &fpt)
{
    write((VfxU8 *)&(fpt.x), sizeof(fpt.x));
    write((VfxU8 *)&(fpt.y), sizeof(fpt.y));
}


void VfxArchive::writeSize(const VfxSize &size)
{
    write((VfxU8 *)&(size.width), sizeof(size.width));
    write((VfxU8 *)&(size.height), sizeof(size.height));
}


void VfxArchive::writeRect(const VfxRect &rect)
{
    writePoint(rect.origin);
    writeSize(rect.size);
}


void VfxArchive::writeColor(const VfxColor &color)
{
    writeU32(color.value);
}


VfxU32 VfxArchive::read(VfxU8 *data, VfxU32 size)
{
    return m_arSource->read(data, size);
}


VfxU8 VfxArchive::readU8()
{
    VfxU8 data;
    m_arSource->read((VfxU8*)&data, sizeof(VfxU8));
    return data;
}


VfxU16 VfxArchive::readU16()
{
    VfxU16 data;
    m_arSource->read((VfxU8*)&data, sizeof(VfxU16));
    return data;
}


VfxU32 VfxArchive::readU32()
{
    VfxU32 data;
    m_arSource->read((VfxU8*)&data, sizeof(VfxU32));
    return data;
}


void VfxArchive::readWString(VfxWString &str)
{
    str.setEmpty();
    
    VfxU32 length = readU32();
    if (length != 0)
    {
        VfxWChar *buf = str.lockBuf(length + 1);
        read((VfxU8 *)buf, length * sizeof(VfxWChar));
        buf[length] = 0;
        str.unlockBuf();
    }
}


void VfxArchive::readPoint(VfxPoint &pt)
{
    pt.x = (VfxS32)readU32();
    pt.y = (VfxS32)readU32();
}


void VfxArchive::readFPoint(VfxFPoint &fpt)
{
    read((VfxU8 *)&(fpt.x), sizeof(fpt.x));
    read((VfxU8 *)&(fpt.y), sizeof(fpt.y));
}


void VfxArchive::readSize(VfxSize &size)
{
    read((VfxU8 *)&(size.width), sizeof(size.width));
    read((VfxU8 *)&(size.height), sizeof(size.height));
}


void VfxArchive::readRect(VfxRect &rect)
{
    readPoint(rect.origin);
    readSize(rect.size);
}


void VfxArchive::readColor(VfxColor &color)
{
    color.value = readU32();
}


VfxArchive::ArchiveStatus VfxArchive::queryStatus(void)
{
    return ARCHIVE_SUCCESS;
}


void VfxArchive::reset(void)
{
}

