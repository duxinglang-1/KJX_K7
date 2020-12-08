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
 *  vfx_stream.h
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
#ifndef __VFX_STREAM_H__
#define __VFX_STREAM_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase 
#include "vfx_cpp_base.h"
// For vfx_sys_file_handle, etc.
#include "vfx_system.h"

#include "vfx_datatype.h"


/***************************************************************************** 
 * class VfxInputStream
 *****************************************************************************/

/*
 * VfxInputSream is a pure virtual interface. Defines an input stream.
 */
class VfxInputStream : public VfxBase
{
    VFX_DECLARE_NO_COPY_CLASS(VfxInputStream);
    
public:
    VfxInputStream();
    virtual ~VfxInputStream();

    template <class T> inline VfxU32 readValue(T &v)
    {
        return read((VfxU8 *)&v, sizeof(T));
    }

    virtual VfxU32 seekTo(VfxU32 offset) = 0;
    virtual VfxU32 read(VfxU8 *buf, VfxU32 bufSize) = 0;
    virtual VfxU32 ignore(VfxU32 size) = 0;
    virtual VfxU32 tell() const = 0;
};


/***************************************************************************** 
 * class VfxMemIstream
 *****************************************************************************/

class VfxMemIstream : public VfxInputStream
{
    VFX_DECLARE_NO_COPY_CLASS(VfxMemIstream);
    
public:
    VfxMemIstream();
    virtual ~VfxMemIstream();

    void open(const VfxU8 *head, const VfxU8 *tail = NULL);
    void close();

    virtual VfxU32 seekTo(VfxU32 offset);
    virtual VfxU32 read(VfxU8 *buf, VfxU32 bufSize);
    virtual VfxU32 ignore(VfxU32 size);
    virtual VfxU32 tell() const;

private:
    const VfxU8 *m_head;
    const VfxU8 *m_tail;
    const VfxU8 *m_currentPtr;
};


/***************************************************************************** 
 * class VfxFileIstream
 *****************************************************************************/

class VfxFileIstream : public VfxInputStream
{
    VFX_DECLARE_NO_COPY_CLASS(VfxFileIstream);
    
public:
    VfxFileIstream();
    virtual ~VfxFileIstream();

    VfxBool open(const VfxWChar *filename);
    void close();

    virtual VfxU32 seekTo(VfxU32 offset);
    virtual VfxU32 read(VfxU8 *buf, VfxU32 bufSize);
    virtual VfxU32 ignore(VfxU32 size);
    virtual VfxU32 tell() const;

private:
    vfx_sys_file_handle m_handle;
};


#endif /* __VFX_STREAM_H__ */

