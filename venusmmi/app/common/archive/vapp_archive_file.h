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
 *  vapp_archive_file.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the file archive.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_ARCHIVE_FILE_H
#define VAPP_ARCHIVE_FILE_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "fs_gprot.h"
}


/*****************************************************************************
 * Temp solution to support C99 snprintf on MoDIS.
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
extern "C" VfxS32 snprintfC99(
    VfxChar *buf,
    VfxS32 size,
    const VfxChar *format,
    ...
);
#endif /* !defined(__MTK_TARGET__) */


/*****************************************************************************
 * File Archive Utility
 *****************************************************************************/

class VappArchiveFileUtil : public VfxBase
{
public:
    enum
    {
        MAX_NAME_LEN = 64,
        MAX_NAME_SIZE = MAX_NAME_LEN + 1
    };

public:
    static VfxS32 openFile(
        const VfxWChar *filename,
        VfxU32 flag
    );

    static VfxBool getUniqueFilename(
        VfxS32 drive,
        VfxChar *baseFolder,
        VfxChar *extension,
        VfxWString &filename
    );

private:
    enum
    {
        MAX_RAND_FILENAME_TIME = 10
    };

private:
    static VfxBool s_srandSeeded;

private:
    static void randFilename(
        VfxS32 drive,
        VfxChar *baseFolder,
        VfxChar *externsion,
        VfxWString &filename
    );

    static VfxBool isFileExist(
        const VfxWChar *filename
    );

    static VfxU32 getCurrentTime();

    static VfxWChar *getFolderName(
        const VfxWChar *filename
    );

    static VfxS32 createDir(
        const VfxWChar *path
    );
};


/*****************************************************************************
 * File Archive Checksum
 *****************************************************************************/

class VappArchiveFileChecksum : public VfxBase
{
public:
    VappArchiveFileChecksum();

public:
    VfxU32 get() const;

    void init();

    void update(
        const VfxU8 *buf,
        VfxS32 size
    );

private:
    VfxU32 m_checksum;
    VfxU32 m_adler32S1;
    VfxU32 m_adler32S2;
};


/*****************************************************************************
 * File Archive Encoder
 *
 *  File = Checksum Body
 *  Checksum = UINT32
 *  Body = Octet*
 *****************************************************************************/

class VappArchiveFileEncoder : public VfxBase
{
public:
    VappArchiveFileEncoder();
    ~VappArchiveFileEncoder();

public:
    VfxBool open(
        const VfxWChar *filename
    );

    void close();

    VfxU32 encode(
        VfxU8 *data,
        VfxU32 size
    );

private:
    FS_HANDLE m_handle;
    VappArchiveFileChecksum m_checksum;

private:
    VfxU32 encodeChecksum();
};


/*****************************************************************************
 * File Archive Decoder
 *
 * NOTE: for the header format, please refer to VappArchiveFileEncoder.
 *****************************************************************************/

class VappArchiveFileDecoder : public VfxBase
{
public:
    VappArchiveFileDecoder();
    ~VappArchiveFileDecoder();

public:
    VfxBool open(
        const VfxWChar *filename
    );

    void close();

    VfxU32 decode(
        VfxU8 *data,
        VfxU32 size
    );

private:
    enum
    {
        MAX_ADLER32_BUF_SIZE = 128
    };

private:
    FS_HANDLE m_handle;

private:
    VfxBool sanityTest(
        VfxU32 fileChecksum
    );

    VfxU32 decodeChecksum(
        VfxU32 &output
    );
};


/*****************************************************************************
 * File Archive Source
 *****************************************************************************/

class VappArchiveFileSource : public VfxObject, public IVfxArchiveSource
{
public:
    enum SourceModeEnum
    {
        SOURCE_MODE_UNKNOWN,
        SOURCE_MODE_READ,
        SOURCE_MODE_WRITE
    };

public:
    VappArchiveFileSource();
    virtual ~VappArchiveFileSource();

public:
    VfxBool open(
        const VfxWChar *filename,
        SourceModeEnum mode
    );

    void close();

public:
    virtual VfxU32 write(
        VfxU8 *data,
        VfxU32 size
    );

    virtual VfxU32 read(
        VfxU8 *data,
        VfxU32 size
    );

private:
    SourceModeEnum m_mode;
    VappArchiveFileDecoder m_decoder;
    VappArchiveFileEncoder m_encoder;
};


#endif /* VAPP_ARCHIVE_FILE_H */

