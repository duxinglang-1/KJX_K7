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
 *  vapp_app_widget_archive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget's archive.
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

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "vfx_uc_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget_archive.h"
#include "mmi_rp_vapp_app_widget_def.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
}


/*****************************************************************************
 * Widget Archive Utility
 *****************************************************************************/

VfxBool VappAppWidgetArchiveUtil::isNewVersion()
{
    //
    // Use a byte lid to know if the version is new. If the byte lid valud is
    // the default 0xFF, it means the version is new.
    //
    U8 flag;
    S16 err;

    ReadValue(NVRAM_VAPP_APP_WIDGET_VERSION_CHECK_FLAG, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_READ_SUCCESS);

    VAPP_APP_WIDGET_LOG((TRC_VAPP_APP_WIDGET_ARCHIVE_NEW_VERSION,
                     flag == 0xFF ? 'Y' : 'N'));

    return flag == 0xFF ? VFX_TRUE : VFX_FALSE;
}


void VappAppWidgetArchiveUtil::setVersionChecked()
{
    U8 flag;
    S16 err;

    flag = 0x00;

    WriteValue(NVRAM_VAPP_APP_WIDGET_VERSION_CHECK_FLAG, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


void VappAppWidgetArchiveUtil::restoreDefault()
{
    U8 flag;
    S16 err;

    flag = 0xFF;

    WriteValue(NVRAM_VAPP_APP_WIDGET_VERSION_CHECK_FLAG, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


/*****************************************************************************
 * AppWidgetArchive File Encoder
 *****************************************************************************/

VappAppWidgetArchiveEncoder::VappAppWidgetArchiveEncoder() :
    m_buf(NULL),
    m_pos(0),
    m_remainedSize(0)
{
    // Do nothing.
}


VappAppWidgetArchiveEncoder::~VappAppWidgetArchiveEncoder()
{
    close();
}


VfxBool VappAppWidgetArchiveEncoder::open()
{
    VFX_ASSERT(!m_buf);

    //
    // Init.
    //
    VFX_ALLOC_MEM(m_buf, NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE, this);

    m_pos = 0;
    m_remainedSize = NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE;

    return VFX_TRUE;
}


void VappAppWidgetArchiveEncoder::close()
{
    if (!m_buf)
    {
        return;
    }

    //
    // Read setting from NVRAM.
    //
    VfxS16 error;

    WriteRecord(
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID,
        1,
        m_buf,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE,
        &error);
    VFX_ASSERT(error == NVRAM_WRITE_SUCCESS);

    //
    // Deinit
    //
    m_pos = 0;
    m_remainedSize = 0;

    VFX_FREE_MEM(m_buf);
}


VfxU32 VappAppWidgetArchiveEncoder::encode(VfxU8 *data, VfxU32 size)
{
    if (size > m_remainedSize)
    {
        return 0;
    }

    kal_mem_cpy(m_buf + m_pos, data, size);

    m_pos += size;
    m_remainedSize -= size;

    return size;
}


/*****************************************************************************
 * Widget Archive File Decoder
 *****************************************************************************/

VappAppWidgetArchiveDecoder::VappAppWidgetArchiveDecoder() :
    m_buf(NULL),
    m_pos(0),
    m_remainedSize(0)
{
    // Do nothing.
}


VappAppWidgetArchiveDecoder::~VappAppWidgetArchiveDecoder()
{
    close();
}


VfxBool VappAppWidgetArchiveDecoder::open()
{
    VFX_ASSERT(!m_buf);

    //
    // Init.
    //
    VFX_ALLOC_MEM(m_buf, NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE, this);

    m_pos = 0;
    m_remainedSize = NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE;

    //
    // Read setting from NVRAM.
    //
    VfxS16 error;

    ReadRecord(
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID,
        1,
        m_buf,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE,
        &error);
    VFX_ASSERT(error == NVRAM_READ_SUCCESS);

    return VFX_TRUE;
}


void VappAppWidgetArchiveDecoder::close()
{
    if (!m_buf)
    {
        return;
    }

    m_pos = 0;
    m_remainedSize = 0;

    VFX_FREE_MEM(m_buf);
}


VfxU32 VappAppWidgetArchiveDecoder::decode(VfxU8 *data, VfxU32 size)
{
    if (size > m_remainedSize)
    {
        return 0;
    }

    kal_mem_cpy(data, m_buf + m_pos, size);

    m_pos += size;
    m_remainedSize -= size;

    return size;
}


/*****************************************************************************
 * Widget Archive Source
 *****************************************************************************/

VappAppWidgetArchiveSource::VappAppWidgetArchiveSource() :
    m_mode(VAPP_APP_WIDGET_ARCHIVE_MODE_UNKNOWN),
    m_decoder(NULL),
    m_encoder(NULL)
{
    // Do nothing.
}


VfxBool VappAppWidgetArchiveSource::openForRead()
{
    close();

    VFX_ASSERT(!m_decoder);

    VFX_OBJ_CREATE(m_decoder, VappAppWidgetArchiveDecoder, this);

    if (!m_decoder->open())
    {
        return VFX_FALSE;
    }

    m_mode = VAPP_APP_WIDGET_ARCHIVE_MODE_READ;

    return VFX_TRUE;
}


VfxBool VappAppWidgetArchiveSource::openForWrite()
{
    close();

    VFX_ASSERT(!m_encoder);

    VFX_OBJ_CREATE(m_encoder, VappAppWidgetArchiveEncoder, this);

    if (!m_encoder->open())
    {
        return VFX_FALSE;
    }

    m_mode = VAPP_APP_WIDGET_ARCHIVE_MODE_WRITE;

    return VFX_TRUE;
}



void VappAppWidgetArchiveSource::close()
{
    if (m_mode == VAPP_APP_WIDGET_ARCHIVE_MODE_READ)
    {
        VFX_OBJ_CLOSE(m_decoder);
    }
    else if (m_mode == VAPP_APP_WIDGET_ARCHIVE_MODE_WRITE)
    {
        VFX_OBJ_CLOSE(m_encoder);
    }
}


VfxU32 VappAppWidgetArchiveSource::write(VfxU8 *data, VfxU32 size)
{
    if (m_mode != VAPP_APP_WIDGET_ARCHIVE_MODE_WRITE)
    {
        return 0;
    }

    return m_encoder->encode(data, size);
}


VfxU32 VappAppWidgetArchiveSource::read(VfxU8 *data, VfxU32 size)
{
    if (m_mode != VAPP_APP_WIDGET_ARCHIVE_MODE_READ)
    {
        return 0;
    }

    return m_decoder->decode(data, size);
}


/*****************************************************************************
 * Widget Archive
 *****************************************************************************/

VappAppWidgetArchive::VappAppWidgetArchive() :
    m_arSource(NULL)
{
    // Do nothing.
}


void VappAppWidgetArchive::setSource(IVfxArchiveSource *arSource)
{
    m_arSource = arSource;
}


VfxBool VappAppWidgetArchive::writeS32(VfxS32 value)
{
    VfxS32 dataSize;
    VfxU32 writtenSize;

    dataSize = sizeof(VfxS32);
    writtenSize = m_arSource->write((VfxU8 *)&value, dataSize);

    return dataSize == writtenSize ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappAppWidgetArchive::writePos(const VfxPoint &pos)
{
    if (writeS32(pos.x) && writeS32(pos.y))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchive::writeString(const VfxChar *value)
{
    VfxS32 len = strlen(value);

    if (!writeS32(len))
    {
        return VFX_FALSE;
    }

    VfxU32 dataSize, writtenSize;

    dataSize = sizeof(VfxChar) * len;
    writtenSize = m_arSource->write((VfxU8 *)value, dataSize);

    return dataSize == writtenSize ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappAppWidgetArchive::writeWidgetId(const VappAppWidgetId &id)
{
    //
    // Source and TypeKind
    //
    VfxS32 source = (VfxS32)id.getSource();
    VfxS32 typeKind = (VfxS32)id.getTypeKind();

    if (!writeS32(source) || !writeS32(typeKind))
    {
        return VFX_FALSE;
    }

    //
    // Type
    //
    switch (typeKind)
    {
        case VappAppWidgetId::TYPE_KIND_INTEGER:
        {
            VfxS32 type = (VfxS32)id.getIntType();

            if (!writeS32(type))
            {
                return VFX_FALSE;
            }

            break;
        }
        case VappAppWidgetId::TYPE_KIND_STRING:
        {
            const VfxChar *typeString = id.getStringType();

            if (!writeString(typeString))
            {
                return VFX_FALSE;
            }

            break;
        }
        default:
        {
            return VFX_FALSE;
            break;
        }
    }

    return VFX_TRUE;
}


VfxBool VappAppWidgetArchive::readS32(VfxS32 &value)
{
    VfxS32 dataSize, readSize;

    dataSize = sizeof(VfxS32);
    readSize = m_arSource->read((VfxU8 *)&value, dataSize);

    return dataSize == readSize ? VFX_TRUE : VFX_FALSE;
}


VfxBool VappAppWidgetArchive::readPos(VfxPoint &pos)
{
    if (readS32(pos.x) && readS32(pos.y))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchive::readString(VfxChar *&value)
{
    VfxS32 dataSize, readSize, len;

    if (!readS32(len))
    {
        return VFX_FALSE;
    }

    VFX_SYS_ALLOC_MEM(value, sizeof(VfxChar) * (len + 1)); // 1 for '\0'

    dataSize = sizeof(VfxChar) * len;
    readSize = m_arSource->read((VfxU8 *)value, dataSize);

    if (dataSize == readSize)
    {
        value[len] = '\0';
        return VFX_TRUE;
    }
    else
    {
        VFX_SYS_FREE_MEM(value);
        return VFX_FALSE;
    }
}



VfxBool VappAppWidgetArchive::readWidgetId(VappAppWidgetId &id)
{
    //
    // Source and TypeKind
    //
    VfxS32 source, typeKind;

    if (!readS32(source) || !readS32(typeKind))
    {
        return VFX_FALSE;
    }

    //
    // Type
    //
    switch (typeKind)
    {
        case VappAppWidgetId::TYPE_KIND_INTEGER:
        {
            VfxS32 type;

            if (!readS32(type))
            {
                return VFX_FALSE;
            }

            id.assignWith(
                (VappAppWidgetSrcEnum)source,
                (VfxS32)type);

            break;
        }
        case VappAppWidgetId::TYPE_KIND_STRING:
        {
            VfxChar *typeString;

            if (!readString(typeString))
            {
                return VFX_FALSE;
            }

            id.assignWith(
                (VappAppWidgetSrcEnum)source,
                typeString);

            VFX_SYS_FREE_MEM(typeString);

            break;
        }
        default:
        {
            return VFX_FALSE;
            break;
        }
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * Widget Archive Iterator
 *****************************************************************************/

VappAppWidgetArchiveIterator::VappAppWidgetArchiveIterator() :
    m_remainedCount(0),
    m_ar(NULL)
{
    // Do nothing.
}


VfxBool VappAppWidgetArchiveIterator::readFirst(VfxS32 &totalNum)
{
    if (!createArchive(VFX_TRUE))
    {
        return VFX_FALSE;
    }

    if (m_ar->readS32(totalNum))
    {
        m_remainedCount = totalNum;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchiveIterator::readNext(
    VappAppWidgetId &id,
    VfxPoint &pos)
{
    if (!m_ar || m_remainedCount <= 0)
    {
        return VFX_FALSE;
    }

    if (m_ar->readWidgetId(id) && m_ar->readPos(pos))
    {
        --m_remainedCount;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchiveIterator::writeFirst(VfxS32 totalNum)
{
    if (!createArchive(VFX_FALSE))
    {
        return VFX_FALSE;
    }

    if (m_ar->writeS32(totalNum))
    {
        m_remainedCount = totalNum;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchiveIterator::writeNext(
    const VappAppWidgetId &id,
    const VfxPoint &pos)
{
    if (!m_ar || m_remainedCount <= 0)
    {
        return VFX_FALSE;
    }

    if (m_ar->writeWidgetId(id) && m_ar->writePos(pos))
    {
        --m_remainedCount;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappAppWidgetArchiveIterator::createArchive(VfxBool isRead)
{
    //
    // Close the old archive if it's present.
    //
    if (m_ar)
    {
        VFX_OBJ_CLOSE(m_ar);
    }

    VFX_OBJ_CREATE(m_ar, VappAppWidgetArchive, this);

    //
    // Create.
    //
    VappAppWidgetArchiveSource *arSource;

    VFX_OBJ_CREATE(arSource, VappAppWidgetArchiveSource, m_ar);

    VfxBool isSuccess;

    if (isRead)
    {
        isSuccess = arSource->openForRead();
    }
    else
    {
        isSuccess = arSource->openForWrite();
    }

    if (isSuccess)
    {
        m_ar->setSource(arSource);
    }
    else
    {
        VFX_OBJ_CLOSE(m_ar);
    }

    return isSuccess;
}
#endif /* defined(__MMI_VUI_LAUNCHER__) */

