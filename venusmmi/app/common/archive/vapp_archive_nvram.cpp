/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_archive_nvram.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the NVRAM archive.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_archive_nvram.h"

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
 * NVRAM Archive Encoder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappArchiveNvramEncoder", 
    VappArchiveNvramEncoder,
    VfxObject);

VappArchiveNvramEncoder::VappArchiveNvramEncoder() :
    m_lid(0),
    m_lidIndex(0),
    m_lidSize(0),
    m_buf(NULL),
    m_pos(0),
    m_remainedSize(0)
{
    // Do nothing.
}


void VappArchiveNvramEncoder::onInit()
{
    VfxObject::onInit();

    // Do nothing.    
}


void VappArchiveNvramEncoder::onDeinit()
{
    close();

    VfxObject::onDeinit();
}


VfxBool VappArchiveNvramEncoder::open(
    nvram_lid_enum lid,
    VfxU16 lidIndex,
    VfxS32 lidSize)
{
    VFX_ASSERT(!m_buf);

    //
    // Save the LID information.
    //
    m_lid = lid;
    m_lidIndex = lidIndex;
    m_lidSize = lidSize;

    //
    // Prepare working buffer.
    //
    VFX_ALLOC_MEM(m_buf, lidSize, this);
    m_pos = 0;
    m_remainedSize = lidSize;

    return VFX_TRUE;
}


void VappArchiveNvramEncoder::close()
{
    if (!m_buf)
    {
        return;
    }

    //
    // Write buffer to NVRAM.
    //
    VfxS16 error;

    WriteRecord(m_lid, m_lidIndex, m_buf, m_lidSize, &error);
    VFX_ASSERT(error == NVRAM_WRITE_SUCCESS);

    //
    // Release buffer.
    //
    VFX_FREE_MEM(m_buf);
}


VfxU32 VappArchiveNvramEncoder::encode(const VfxU8 *data, VfxU32 size)
{
    VFX_ASSERT(m_remainedSize >= size);

    kal_mem_cpy(m_buf + m_pos, data, size);

    m_pos += size;
    m_remainedSize -= size;

    return size;
}


/*****************************************************************************
 * NVRAM Archive Decoder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappArchiveNvramDecoder", 
    VappArchiveNvramDecoder,
    VfxObject);

VappArchiveNvramDecoder::VappArchiveNvramDecoder() :
    m_lid(0),
    m_lidIndex(0),
    m_lidSize(0),
    m_buf(NULL),
    m_pos(0),
    m_remainedSize(0)
{
    // Do nothing.
}


void VappArchiveNvramDecoder::onInit()
{
    VfxObject::onInit();

    // Do nothing.
}


void VappArchiveNvramDecoder::onDeinit()
{
    close();

    VfxObject::onDeinit();
}


VfxBool VappArchiveNvramDecoder::open(
    nvram_lid_enum lid,
    VfxU16 lidIndex,
    VfxS32 lidSize)
{
    VFX_ASSERT(!m_buf);

    //
    // Save the LID information.
    //
    m_lid = lid;
    m_lidIndex = lidIndex;
    m_lidSize = lidSize;

    //
    // Prepare working buffer.
    //
    VFX_ALLOC_MEM(m_buf, lidSize, this);
    m_pos = 0;
    m_remainedSize = lidSize;

    //
    // Read setting from NVRAM.
    //
    VfxS16 error;

    ReadRecord(m_lid, m_lidIndex, m_buf, m_lidSize, &error);
    VFX_ASSERT(error == NVRAM_READ_SUCCESS);

    return VFX_TRUE;
}


void VappArchiveNvramDecoder::close()
{
    if (!m_buf)
    {
        return;
    }

    //
    // Release buffer.
    //
    VFX_FREE_MEM(m_buf);
}


VfxU32 VappArchiveNvramDecoder::decode(VfxU8 *data, VfxU32 size)
{
    VFX_ASSERT(m_remainedSize >= size);

    kal_mem_cpy(data, m_buf + m_pos, size);

    m_pos += size;
    m_remainedSize -= size;

    return size;
}


/*****************************************************************************
 * NVRAM Archive Source
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappArchiveNvramSource", 
    VappArchiveNvramSource,
    VfxObject);

VappArchiveNvramSource::VappArchiveNvramSource() :
    m_mode(SOURCE_MODE_UNKNOWN),
    m_decoder(NULL),
    m_encoder(NULL)
{
    // Do nothing.
}


void VappArchiveNvramSource::onInit()
{
    VfxObject::onInit();

    // Do nothing.
}


void VappArchiveNvramSource::onDeinit()
{
    close();

    VfxObject::onDeinit();
}


VfxBool VappArchiveNvramSource::open(
    nvram_lid_enum lid,
    VfxU16 lidIndex,
    VfxS32 lidSize,
    SourceModeEnum mode)
{
    close();

    switch (mode)
    {
        case SOURCE_MODE_READ:
        {
            VFX_OBJ_CREATE(m_decoder, VappArchiveNvramDecoder, this);

            if (!m_decoder->open(lid, lidIndex, lidSize))
            {
                return VFX_FALSE;
            }

            m_mode = SOURCE_MODE_READ;

            break;
        }
        case SOURCE_MODE_WRITE:
        {
            VFX_OBJ_CREATE(m_encoder, VappArchiveNvramEncoder, this);

            if (!m_encoder->open(lid, lidIndex, lidSize))
            {
                return VFX_FALSE;
            }

            m_mode = SOURCE_MODE_WRITE;

            break;
        }
        default:
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}


void VappArchiveNvramSource::close()
{
    VFX_OBJ_CLOSE(m_decoder);
    VFX_OBJ_CLOSE(m_encoder);
}


VfxU32 VappArchiveNvramSource::write(VfxU8 *data, VfxU32 size)
{
    VFX_ASSERT(m_encoder && m_mode == SOURCE_MODE_WRITE);

    return m_encoder->encode(data, size);
}


VfxU32 VappArchiveNvramSource::read(VfxU8 *data, VfxU32 size)
{
    VFX_ASSERT(m_decoder && m_mode == SOURCE_MODE_READ);

    return m_decoder->decode(data, size);
}

