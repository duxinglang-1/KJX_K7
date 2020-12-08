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
 *  vfx_archive.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_ARCHIVE_H__
#define __VFX_ARCHIVE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define ARCHIVE_DEFAULT_SPACE_SIZE  (32)


/***************************************************************************** 
 * Interface IVfxArchiveSource
 *****************************************************************************/

class IVfxArchiveSource
{
// overridable
public:
    virtual VfxU32 write(VfxU8* data, VfxU32 size) = 0;
    virtual VfxU32 read(VfxU8* data, VfxU32 size) = 0;
};


/***************************************************************************** 
 * Class VfxMemArchiveSource
 *****************************************************************************/

class VfxMemArchiveSource : public VfxObject, public IVfxArchiveSource
{
public:

// declaration

    enum Mode {
        READ_MODE,      // archive source is in read mode
        WRITE_MODE      // archive source is in write mode
    };

// Constructor / Destructor
    VfxMemArchiveSource();
    VfxMemArchiveSource(VfxU32 spaceSize);
    virtual ~VfxMemArchiveSource();

// override
    // write data to archive source
    // RETURNS: actual data written
    virtual VfxU32 write(
                        VfxU8* data,    // [IN] pointer to data
                        VfxU32 size);   // [IN] data size to write

    // read data from archive source
    // RETURNS: actual data read
    virtual VfxU32 read(
                        VfxU8* data,    // [IN/OUT] buffer to put read out data
                        VfxU32 size);   // [IN]     data size to read

// method
    // detach buffer from archive source after write
    // you must take care buffer's lifecycle, i.e. you may need to free it, after detaching it.
    void detachBuffer(
                VfxU8 **buf,            // [IN/OUT] pointer to buffer pointer
                VfxU32 *dataSize);      // [IN/OUT] pointer to data size

    // attach buffer to archive source to read
    void attachBuffer(
                VfxU8 *buf,             // [IN] buffer to attach
                VfxU32 dataSize);       // [IN] actual data size in buffer

// implementation
private:

    VfxMemArchiveSource::Mode m_mode;

    // pointer to archive data
    VfxU8 *m_dataPtr;
    // size of data archived
    VfxU32 m_dataSize;
    // free space can be used to archive
    VfxU32 m_freeSpaceSize;
    // read index
    VfxU8 *m_readPtr;
    // limit memory size
    VfxBool isLimit;

    void enlargeSpace(VfxU32 extraRequired);
};


/***************************************************************************** 
 * Class VfxArchive
 *****************************************************************************/

class VfxArchive : public VfxObject
{
// Declaration
public:
    enum ArchiveStatus {
        ARCHIVE_SUCCESS,
        ARCHIVE_FAIL,
        ARCHIVE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    VfxArchive();

// Method
public:
    // set archive source
    void setSource(IVfxArchiveSource *arSource);

    // write data to archive source
    void write(
                VfxU8 *data,            // [IN] pointer to data
                VfxU32 size);           // [IN] data size to write

    // write 1 byte to archive source
    void writeU8(VfxU8 data);           // [IN] VfxU8 data to write

    // write 2 bytes to archive source
    void writeU16(VfxU16 data);         // [IN] VfxU16 data to write

    // write 4 bytes to archive source
    void writeU32(VfxU32 data);         // [IN] VfxU32 data to write

    // write VfxWString to archive source
    void writeWString(const VfxWString &str); // [IN] string object to write

    // write VfxPoint to archive source
    void writePoint(const VfxPoint &pt);      // [IN] point object to write

    // write VfxFPoint to archive source
    void writeFPoint(const VfxFPoint &fpt);   // [IN] fpoint object to write

    // write VfxSize to archvie source
    void writeSize(const VfxSize &size);      // [IN] size object to write

    // write VfxRect to archive source
    void writeRect(const VfxRect &rect);      // [IN] rect object to write

    // write VfxColor to archive source
    void writeColor(const VfxColor &color);   // [IN] color object to write

    // read data from archive source
    // RETURNS: actual size read
    VfxU32 read(
                VfxU8 *data,            // [IN/OUT] buffer to put read out data
                VfxU32 size);           // [IN]     data size to read

    // read 1 byte from archive source
    // RETURNS: data read
    VfxU8 readU8();

    // read 2 bytes from archive source
    // RETURNS: data read
    VfxU16 readU16();

    // read 4 bytes from archive source
    // RETURNS: data read
    VfxU32 readU32();

    // read VfxWString from archive source
    void readWString(VfxWString &str);  // [IN/OUT] reference to string object

    // read VfxPoint from archive source
    void readPoint(VfxPoint &pt);       // [IN/OUT] reference to point object

    // read VfxFPoint from archive source
    void readFPoint(VfxFPoint &fpt);    // [IN/OUT] reference to fpoint object

    // read VfxSize from archvie source
    void readSize(VfxSize &size);       // [IN/OUT] reference to size object

    // read VfxRect from archive source
    void readRect(VfxRect &rect);       // [IN/OUT] reference to rect object

    // read VfxColor from archive source
    void readColor(VfxColor &color);    // [IN/OUT] reference to color object

    // query archive status
    ArchiveStatus queryStatus();

    // reset status
    void reset();

// Implementation
private:
    IVfxArchiveSource *m_arSource;
};

#endif /* __VFX_ARCHIVE_H__ */

