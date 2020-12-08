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
 *  vapp_archive_nvram.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the NVRAM archive.
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

#ifndef VAPP_ARCHIVE_NVRAM_H
#define VAPP_ARCHIVE_NVRAM_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"


/*****************************************************************************
 * NVRAM Archive Encoder
 *****************************************************************************/

class VappArchiveNvramEncoder : public VfxObject
{
    VFX_DECLARE_CLASS(VappArchiveNvramEncoder);

// Constructor / Destructor
public:
    // Default constructor.
    VappArchiveNvramEncoder();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // Open an encoder.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool open(
        nvram_lid_enum lid,     // [IN] NVRAM logic ID
        VfxU16 lidIndex,        // [IN] LID index
        VfxS32 lidSize          // [IN] LID size
    );

    // Close the encoder.
    void close();

    // Encode the data.
    // RETURNS: the encoded data size.
    VfxU32 encode(
        const VfxU8 *data,      // [IN] Data
        VfxU32 size             // [IN] Data size
    );

// Variable
private:
    // NVRAM Logic ID.
    nvram_lid_enum m_lid;

    // LID index.
    VfxU16 m_lidIndex;
    
    // LID size.
    VfxS32 m_lidSize;

    // Buffer.
    VfxU8 *m_buf;

    // Current buffer position.
    VfxU32 m_pos;

    // Remained size of the buffer.
    VfxU32 m_remainedSize;
};


/*****************************************************************************
 * NVRAM Archive Decoder
 *****************************************************************************/

class VappArchiveNvramDecoder : public VfxObject
{
    VFX_DECLARE_CLASS(VappArchiveNvramDecoder);

// Constructor / Destructor
public:
    // Default constructor.
    VappArchiveNvramDecoder();

// protected
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // Open an decoder.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool open(
        nvram_lid_enum lid,     // [IN] NVRAM logic ID
        VfxU16 lidIndex,        // [IN] LID index
        VfxS32 lidSize          // [IN] LID size
    );

    // Close the decoder.
    void close();

    // Decode the data
    // RETURNS: the decoded size.
    VfxU32 decode(
        VfxU8 *data,            // [OUT] Data
        VfxU32 size             // [IN] Data size
    );

// Variable
private:
    // NVRAM Logic ID.
    nvram_lid_enum m_lid;

    // LID index.
    VfxU16 m_lidIndex;

    // LID size.
    VfxS32 m_lidSize;

    // Buffer
    VfxU8 *m_buf;

    // Current buffer position.
    VfxU32 m_pos;

    // Remained size of the buffer.
    VfxU32 m_remainedSize;
};


/*****************************************************************************
 * NVRAM Archive Source
 *****************************************************************************/

class VappArchiveNvramSource : public VfxObject, public IVfxArchiveSource
{
    VFX_DECLARE_CLASS(VappArchiveNvramSource);

// Enum
public:
    // Archive source mode
    enum SourceModeEnum
    {
        // Unknown
        SOURCE_MODE_UNKNOWN,

        // Read only mode.
        SOURCE_MODE_READ,

        // Write only mode.
        SOURCE_MODE_WRITE
    };

// Constructor / Destructor
public:
    // Default constructor.
    VappArchiveNvramSource();

// protected
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // Open a archive source.
    VfxBool open(
        nvram_lid_enum lid,     // [IN] NVRAM logic ID
        VfxU16 lidIndex,        // [IN] LID index
        VfxS32 lidSize,         // [IN] LID size
        SourceModeEnum mode     // [IN] Source mode
    );

    // Close the archive source
    void close();

// Method
public:
    // Please refer to IVfxArchiveSource.
    virtual VfxU32 write(
        VfxU8 *data,
        VfxU32 size
    );

    // Please refer to IVfxArchiveSource.
    virtual VfxU32 read(
        VfxU8 *data,
        VfxU32 size
    );

// Variable
private:
    // Source mode.
    SourceModeEnum m_mode;

    // NVRAM decoder.
    VappArchiveNvramDecoder *m_decoder;

    // NVRAM encoder.
    VappArchiveNvramEncoder *m_encoder;
};

#endif /* VAPP_ARCHIVE_NVRAM_H */

