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
 *  vfx_stream.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Input stream from file, memory and resource
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

#include "vfx_stream.h"

#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
#include <string.h>


/***************************************************************************** 
 * class VfxInputStream
 *****************************************************************************/

VfxInputStream::VfxInputStream()
{
}


VfxInputStream::~VfxInputStream()
{
}


/***************************************************************************** 
 * class VfxMemIstream
 *****************************************************************************/

VfxMemIstream::VfxMemIstream() :
    m_head(NULL),
    m_tail(NULL),
    m_currentPtr(NULL)
{
}


VfxMemIstream::~VfxMemIstream()
{
    close();
}


void VfxMemIstream::open(const VfxU8 *head, const VfxU8 *tail)
{
    VFX_ASSERT(m_head == NULL);
    VFX_ASSERT(m_currentPtr == NULL);
    
    m_head = head;
    m_tail = tail;
    m_currentPtr = head;
}


void VfxMemIstream::close()
{
    m_head = NULL;
    m_tail = NULL;
    m_currentPtr = NULL;
}


VfxU32 VfxMemIstream::seekTo(VfxU32 offset)
{
    VFX_ASSERT(m_head != NULL);

    VfxU32 seek_size = offset;
        
    if (m_tail != NULL && m_head + seek_size > m_tail)
    {
        seek_size = m_tail - m_head;
    }

    m_currentPtr = m_head + seek_size;

    return seek_size;
}


VfxU32 VfxMemIstream::read(VfxU8 *buf, VfxU32 bufSize)
{
    VFX_ASSERT(m_currentPtr != NULL);
    
    VfxU32 read_size = bufSize;

    if (m_tail != NULL && m_currentPtr + read_size > m_tail)
    {
        read_size = m_tail - m_currentPtr;
    }
    
    if (read_size > 0)
    {
        memcpy(buf, m_currentPtr, read_size);
        m_currentPtr += read_size;
    }

    return read_size;
}


VfxU32 VfxMemIstream::ignore(VfxU32 size)
{
    VFX_ASSERT(m_currentPtr != NULL);

    VfxU32 seek_size = size;
    
    if (m_tail != NULL && m_currentPtr + seek_size > m_tail)
    {
        seek_size = m_tail - m_currentPtr;
    }

    m_currentPtr += seek_size;    

    return seek_size;
}


VfxU32 VfxMemIstream::tell() const
{
    return (m_currentPtr - m_head);
}


/***************************************************************************** 
 * class VfxFileIstream
 *****************************************************************************/

VfxFileIstream::VfxFileIstream() :
    m_handle(NULL)
{
}


VfxFileIstream::~VfxFileIstream()
{
    close();
}


VfxBool VfxFileIstream::open(const VfxWChar *filename)
{
    VFX_ASSERT(m_handle == NULL);
    VFX_ASSERT(filename != NULL);

    m_handle = vfx_sys_file_open(filename, VFX_UC_SYS_FILE_OPEN_MODE_READ);
    if (m_handle == NULL)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VfxFileIstream::close()
{
    if (m_handle == NULL)
    {
        // Do nothing
        return;
    }

    vfx_sys_file_close(m_handle);
    m_handle = NULL;
}


VfxU32 VfxFileIstream::seekTo(VfxU32 offset)
{
    VFX_ASSERT(m_handle != NULL);
        
    if(!vfx_sys_file_seek(
        m_handle, 
        (VfxS32)offset, 
        VFX_UC_SYS_FILE_SEEK_ORIGIN_BEGIN))
    {
        return 0;
    }

    return vfx_sys_file_get_pos(m_handle);
}


VfxU32 VfxFileIstream::read(VfxU8 *buf, VfxU32 bufSize)
{
    VFX_ASSERT(m_handle != NULL);
        
    return vfx_sys_file_read(m_handle, buf, bufSize);
}


VfxU32 VfxFileIstream::ignore(VfxU32 size)
{
    VFX_ASSERT(m_handle != NULL);

    VfxU32 pos_before = vfx_sys_file_get_pos(m_handle);
    vfx_sys_file_seek(
        m_handle, 
        (VfxS32)size, 
        VFX_UC_SYS_FILE_SEEK_ORIGIN_CURRENT);
    VfxU32 pos_after = vfx_sys_file_get_pos(m_handle);

    return pos_after - pos_before;
}


VfxU32 VfxFileIstream::tell() const
{
    return vfx_sys_file_get_pos(m_handle);
}

