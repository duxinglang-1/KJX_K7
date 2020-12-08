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
 *  vapp_file_archive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the file archive.
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "vfx_uc_include.h"
#include "vapp_archive_file.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "Unicodexdcl.h"    // mmi_asc_n_to_wcs
#include "fs_gprot.h"
#include "app_datetime.h"
}


/*****************************************************************************
 * Temp solution to support C99 snprintf on MoDIS.
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
VfxS32 snprintfC99(
    VfxChar *buf,
    VfxS32 size,
    const VfxChar *format,
    ...)
{
    va_list param;

    va_start(param, format);

    int length = _vscprintf(format, param);

    if (buf && size > 0)
    {
        _vsnprintf_s(buf, size, _TRUNCATE, format, param);
    }

    va_end(param);

    return length;
}

#undef kal_snprintf
#define kal_snprintf snprintfC99
#endif /* !defined(__MTK_TARGET__) */


/*****************************************************************************
 * File Archive Utility
 *****************************************************************************/

VfxBool VappArchiveFileUtil::s_srandSeeded = VFX_FALSE;


VfxS32 VappArchiveFileUtil::openFile(const VfxWChar *filename, VfxU32 flag)
{
    VfxWChar *folderName = NULL;

    VfxS32 ret = FS_Open(filename, flag);

    if (ret == FS_PATH_NOT_FOUND || ret == FS_FILE_NOT_FOUND)
    {
        folderName = getFolderName(filename);

        if (createDir(filename) >= 0)
        {
            ret = FS_Open(filename, flag);
        }
    }

    if (folderName)
    {
        VFX_SYS_FREE_MEM(folderName);
    }

    return ret;
}


VfxBool VappArchiveFileUtil::getUniqueFilename(
    VfxS32 drive,
    VfxChar *baseFolder,
    VfxChar *extension,
    VfxWString &filename)
{
    VfxS32 time = 0;

    do
    {
        randFilename(drive, baseFolder, extension, filename);
        ++time;
    } while(isFileExist(filename) && time <= MAX_RAND_FILENAME_TIME);

    if (time > MAX_RAND_FILENAME_TIME)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappArchiveFileUtil::randFilename(
    VfxS32 drive,
    VfxChar *baseFolder,
    VfxChar *extension,
    VfxWString &filename)
{
    VfxU32 currentTime = getCurrentTime();

    //
    // 'srand' if it does not be seeded yet.
    //
    if (!s_srandSeeded)
    {
        srand(currentTime);
        s_srandSeeded = VFX_TRUE;
    }

    //
    // Get a random ASCII filename and convert it to UCS2 string.
    //
    VfxU32 fileNum = rand() * currentTime;

    const VfxS32 size = 1 + kal_snprintf(
                                NULL,
                                0,
                                "%c:\\%s\\%08lx.%s",
                                drive,
                                baseFolder,
                                fileNum,
                                extension);

    kal_char *name;

    VFX_SYS_ALLOC_MEM(name, size * sizeof(kal_char));

    kal_snprintf(
        name,
        size,
        "%c:\\%s\\%08lx.%s",
        drive,
        baseFolder,
        fileNum,
        extension);

    //
    // Convert the ASCII string to the UCS2 string for output.
    //
    VfxWChar *wideName;

    VFX_SYS_ALLOC_MEM(wideName, size * sizeof(VfxWChar));

    mmi_asc_n_to_wcs((WCHAR *)wideName, (CHAR *)name, size - 1);

    filename.loadFromMem(wideName);

    VFX_SYS_FREE_MEM(wideName);
    VFX_SYS_FREE_MEM(name);
}


VfxBool VappArchiveFileUtil::isFileExist(const VfxWChar *filename)
{
    VFX_ASSERT(filename);

    FS_HANDLE handle = FS_Open(filename, FS_READ_ONLY);

    if (handle >= 0)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU32 VappArchiveFileUtil::getCurrentTime()
{
    applib_time_struct t;

    applib_dt_get_secure_time(&t);

    return (VfxU32)applib_dt_mytime_2_utc_sec(&t, KAL_TRUE);
}


VfxWChar *VappArchiveFileUtil::getFolderName(const VfxWChar *filename)
{
    VfxWChar *folderName;

    VfxS32 len = vfx_sys_wcslen(filename);

    VFX_SYS_ALLOC_MEM(folderName, sizeof(VfxWChar) * (len + 1));
    vfx_sys_wcsncpy(folderName, filename, len);

    for (VfxS32 i = len; i >= 0; i--)
    {
        if (folderName[i] == L'\\')
        {
            folderName[i] = L'\0';
            break;
        }
    }

    return folderName;
}


VfxS32 VappArchiveFileUtil::createDir(const VfxWChar *path)
{
    //
    // Backup the original path.
    //
    VfxS32 len = vfx_sys_wcslen(path);

    VfxWChar *p;

    VFX_SYS_ALLOC_MEM(p, sizeof(VfxWChar) * (len + 1));
    vfx_sys_wcsncpy(p, path, len);

    //
    // Create the directory recursively.
    //
    VfxBool isDriveSplashPassed = VFX_FALSE;
    VfxS32 ret = -1;

    for (VfxS32 i = 0; i < len; i++)
    {
        if (p[i] == L'\\')
        {
            if (!isDriveSplashPassed)
            {
                isDriveSplashPassed = VFX_TRUE;
            }
            else
            {
                p[i] = L'\0';

                ret = FS_CreateDir(p);
                if (ret < 0 && ret != FS_FILE_EXISTS)
                {
                    break;
                }

                p[i] = L'\\';
            }
        }
    }

    VFX_SYS_FREE_MEM(p);

    return ret == FS_FILE_EXISTS ? FS_NO_ERROR : ret;
}


/*****************************************************************************
 * File Archive Checksum
 *****************************************************************************/

VappArchiveFileChecksum::VappArchiveFileChecksum() :
    m_checksum(0),
    m_adler32S1(1),
    m_adler32S2(0)
{
    // Do nothing.
}


VfxU32 VappArchiveFileChecksum::get() const
{
    return m_checksum;
}


void VappArchiveFileChecksum::init()
{
    m_checksum  = 0;
    m_adler32S1 = 1;
    m_adler32S2 = 0;
}


void VappArchiveFileChecksum::update(const VfxU8 *buf, VfxS32 size)
{
    if (buf == NULL || size <= 0)
    {
        return;
    }

    for (VfxS32 i = 0; i < size; i++)
    {
        m_adler32S1 += buf[i];

        if (m_adler32S1 >= 65521)
        {
            m_adler32S1 -= 65521;
        }

        m_adler32S2 += m_adler32S1;

        if (m_adler32S2 >= 65521)
        {
            m_adler32S2 -= 65521;
        }
    }

    m_checksum = m_adler32S1 + (m_adler32S2 << 16);
}


/*****************************************************************************
 * File Archive Encoder
 *****************************************************************************/

VappArchiveFileEncoder::VappArchiveFileEncoder() :
    m_handle(-1),
    m_checksum()
{
    // Do nothing.
}


VappArchiveFileEncoder::~VappArchiveFileEncoder()
{
    if (m_handle >= 0)
    {
        close();
    }
}


VfxBool VappArchiveFileEncoder::open(const VfxWChar *filename)
{
    m_handle = VappArchiveFileUtil::openFile(
                filename,
                FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (m_handle < 0)
    {
        return VFX_FALSE;
    }

    //
    // Skip 4 bytes, which is for the checksum.
    //
    m_checksum.init();

    if (FS_Seek(m_handle, sizeof(VfxU32), FS_FILE_BEGIN) < 0)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappArchiveFileEncoder::close()
{
    if (m_handle < 0)
    {
        return;
    }

    encodeChecksum();

    FS_Close(m_handle);
    m_handle = -1;
}


VfxU32 VappArchiveFileEncoder::encode(VfxU8 *data, VfxU32 size)
{
    VfxU32 writtenSize;

    VFX_ASSERT(m_handle >= 0);

    VfxS32 ret = FS_Write(m_handle, data, size, &writtenSize);

    if (ret >= 0)
    {
        m_checksum.update(data, writtenSize);
    }

    return ret >= 0 ? writtenSize : 0;
}


VfxU32 VappArchiveFileEncoder::encodeChecksum()
{
    VfxU32 writtenSize;

    VFX_ASSERT(m_handle >= 0);

    //
    // Checksum is written in the beginning of the file.
    //
    if (FS_Seek(m_handle, 0, FS_FILE_BEGIN) < 0)
    {
        return 0;
    }

    //
    // Write checksum.
    //
    VfxU32 checksum = m_checksum.get();

    VfxS32 ret = FS_Write(m_handle, &checksum, sizeof(VfxU32), &writtenSize);

    return ret >= 0 ? writtenSize : 0;
}


/*****************************************************************************
 * File Archive Decoder
 *****************************************************************************/

VappArchiveFileDecoder::VappArchiveFileDecoder() :
    m_handle(-1)
{
    // Do nothing.
}


VappArchiveFileDecoder::~VappArchiveFileDecoder()
{
    if (m_handle >= 0)
    {
        close();
    }
}


VfxBool VappArchiveFileDecoder::open(const VfxWChar *filename)
{
    m_handle = VappArchiveFileUtil::openFile(filename, FS_READ_ONLY);
    if (m_handle < 0)
    {
        return VFX_FALSE;
    }

    VfxU32 checksum;

    if (decodeChecksum(checksum) == 0 || sanityTest(checksum) == VFX_FALSE)
    {
        FS_Close(m_handle);
        m_handle = -1;
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappArchiveFileDecoder::close()
{
    if (m_handle < 0)
    {
        return;
    }

    FS_Close(m_handle);
    m_handle = -1;
}


VfxU32 VappArchiveFileDecoder::decode(VfxU8 *data, VfxU32 size)
{
    VfxU32 readSize;

    VFX_ASSERT(m_handle >= 0);

    VfxS32 ret = FS_Read(m_handle, data, size, &readSize);

    return ret >= 0 ? readSize : 0;
}


VfxBool VappArchiveFileDecoder::sanityTest(VfxU32 fileChecksum)
{
    VfxU8 buf[MAX_ADLER32_BUF_SIZE];
    VappArchiveFileChecksum checksum;
    VfxU32 originalPosition, readSize;

    VFX_ASSERT(m_handle >= 0);

    //
    // Save the original file position.
    //
    if (FS_GetFilePosition(m_handle, &originalPosition) < 0)
    {
        return VFX_FALSE;
    }

    //
    // Compute the checksum.
    //
    checksum.init();

    while (FS_Read(m_handle, buf, MAX_ADLER32_BUF_SIZE, &readSize) >= 0 &&
           readSize > 0)
    {
        checksum.update(buf, readSize);
    }

    //
    // Compare the checksum and restore the file position.
    //
    if (checksum.get() == fileChecksum &&
        FS_Seek(m_handle, originalPosition, FS_FILE_BEGIN) >= 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxU32 VappArchiveFileDecoder::decodeChecksum(VfxU32 &output)
{
    VfxU32 readSize;

    VFX_ASSERT(m_handle >= 0);

    VfxS32 ret = FS_Read(m_handle, &output, sizeof(VfxU32), &readSize);

    return ret >= 0 ? readSize : 0;
}


/*****************************************************************************
 * File Archive Source
 *****************************************************************************/

VappArchiveFileSource::VappArchiveFileSource() :
    m_mode(SOURCE_MODE_UNKNOWN),
    m_decoder(),
    m_encoder()
{
    // Do nothing.
}


VappArchiveFileSource::~VappArchiveFileSource()
{
    // Do nothing.
}


VfxBool VappArchiveFileSource::open(
    const VfxWChar *filename,
    SourceModeEnum mode)
{
    close();

    switch (mode)
    {
        case SOURCE_MODE_READ:
        {
            if (!m_decoder.open(filename))
            {
                return VFX_FALSE;
            }

            m_mode = SOURCE_MODE_READ;

            break;
        }
        case SOURCE_MODE_WRITE:
        {
            if (!m_encoder.open(filename))
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


void VappArchiveFileSource::close()
{
    if (m_mode == SOURCE_MODE_READ)
    {
        m_decoder.close();
    }
    else if (m_mode == SOURCE_MODE_WRITE)
    {
        m_encoder.close();
    }
}


VfxU32 VappArchiveFileSource::write(VfxU8 *data, VfxU32 size)
{
    if (m_mode != SOURCE_MODE_WRITE)
    {
        return 0;
    }

    return m_encoder.encode(data, size);
}


VfxU32 VappArchiveFileSource::read(VfxU8 *data, VfxU32 size)
{
    if (m_mode != SOURCE_MODE_READ)
    {
        return 0;
    }

    return m_decoder.decode(data, size);
}

