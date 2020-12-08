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
 *  vapp_app_widget_archive.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the widget's archive.
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

#ifndef VAPP_APP_WIDGET_ARCHIVE_H
#define VAPP_APP_WIDGET_ARCHIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_app_widget_primitive.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "fat_fs.h"
}


/*****************************************************************************
 * Widget Archive Utility
 *****************************************************************************/

class VappAppWidgetArchiveUtil : public VfxBase
{
public:
    static VfxBool isNewVersion();

    static void setVersionChecked();

    static void restoreDefault();
};


/*****************************************************************************
 * Widget Archive Encoder
 *
 *  File = Checksum Entity*
 *  Checksum = UINT32
 *  Entity = Source TypeKind TypeUnion
 *  Source = INT32 (i.e., VappAppWidgetSrcEnum)
 *  TypeKind = INT32 (i.e., VappAppWidgetId::TypeKindEnum)
 *  TypeUnion = TypeInteger | TypeString
 *  TypeInteger = INT32
 *  TypeString = Length String
 *  Length = INT32
 *****************************************************************************/

class VappAppWidgetArchiveEncoder : public VfxObject
{
public:
    VappAppWidgetArchiveEncoder();
    ~VappAppWidgetArchiveEncoder();

public:
    VfxBool open();

    void close();

    VfxU32 encode(
        VfxU8 *data,
        VfxU32 size
    );

private:
    VfxU8 *m_buf;
    VfxS32 m_pos;
    VfxS32 m_remainedSize;
};


/*****************************************************************************
 * Widget Archive Header Decoder
 *
 * NOTE: for the header format, please refer to VappAppWidgetArchiveHeaderEncoder.
 *****************************************************************************/

class VappAppWidgetArchiveDecoder : public VfxObject
{
public:
    VappAppWidgetArchiveDecoder();
    ~VappAppWidgetArchiveDecoder();

public:
    VfxBool open();

    void close();

    VfxU32 decode(
        VfxU8 *data,
        VfxU32 size
    );

private:
    VfxU8 *m_buf;
    VfxS32 m_pos;
    VfxS32 m_remainedSize;
};


/*****************************************************************************
 * Widget Archive Source
 *****************************************************************************/

class VappAppWidgetArchiveSource : public VfxObject, public IVfxArchiveSource
{
public:
    enum VappAppWidgetArchiveModeEnum
    {
        VAPP_APP_WIDGET_ARCHIVE_MODE_UNKNOWN,
        VAPP_APP_WIDGET_ARCHIVE_MODE_READ,
        VAPP_APP_WIDGET_ARCHIVE_MODE_WRITE
    };

public:
    VappAppWidgetArchiveSource();

public:
    VfxBool openForRead();

    VfxBool openForWrite();

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
    VappAppWidgetArchiveModeEnum m_mode;
    VappAppWidgetArchiveDecoder *m_decoder;
    VappAppWidgetArchiveEncoder *m_encoder;
};


/*****************************************************************************
 * Widget Archive
 *****************************************************************************/

class VappAppWidgetArchive : public VfxObject
{
public:
    VappAppWidgetArchive();

public:
    void setSource(
        IVfxArchiveSource *arSource
    );

    VfxBool writeS32(
        VfxS32 value
    );

    VfxBool writePos(
        const VfxPoint &pos
    );

    VfxBool writeString(
        const VfxChar *value
    );

    VfxBool writeWidgetId(
        const VappAppWidgetId &id
    );

    VfxBool readS32(
        VfxS32 &value
    );

    VfxBool readPos(
        VfxPoint &pos
    );

    VfxBool readString(
        VfxChar *&value
    );

    VfxBool readWidgetId(
        VappAppWidgetId &id
    );

protected:
    IVfxArchiveSource *m_arSource;
};


/*****************************************************************************
 * Widget Archive Iterator
 *****************************************************************************/

class VappAppWidgetArchiveIterator : public VfxObject
{
public:
    VappAppWidgetArchiveIterator();

public:
    VfxBool readFirst(
        VfxS32 &totalNum
    );

    VfxBool readNext(
        VappAppWidgetId &id,
        VfxPoint &pos
    );

    VfxBool writeFirst(
        VfxS32 totalNum
    );

    VfxBool writeNext(
        const VappAppWidgetId &id,
        const VfxPoint &pos
    );

private:
    VfxS32 m_remainedCount;
    VappAppWidgetArchive *m_ar;

private:
    VfxBool createArchive(
        VfxBool isRead
    );
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_ARCHIVE_H */

