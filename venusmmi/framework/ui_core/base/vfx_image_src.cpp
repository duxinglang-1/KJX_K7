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
 *  vfx_image_src.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Image Source Type
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
 
#include "vfx_image_src.h"

#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vrt_system.h"
#include "vfx_sys_memory.h"
#include "vfx_basic_type.h"
#include <string.h>

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_data_type_convertion.h"
#endif

/***************************************************************************** 
 * Class VfxImageBuffer
 *****************************************************************************/
 
VfxImageBuffer::VfxImageBuffer(const vrt_image_buffer_struct &other)
{
    ptr         = other.buf_p;
    pitchBytes  = other.pitch_bytes;
    width       = other.width;
    height      = other.height;
    colorFormat = other.color_format;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxImageBuffer::VfxImageBuffer(const vm_image_buffer_struct &other)
{
    ptr         = other.buf_p;
    pitchBytes  = other.pitch_bytes;
    width       = other.width;
    height      = other.height;
    colorFormat = vpi_m2v_convert_color_type(other.color_format);
}
#endif


void VfxImageBuffer::initVrtImageBuffer(vrt_image_buffer_struct &vrt_image_buffer) const
{
    vrt_image_buffer.buf_p          = ptr;
    vrt_image_buffer.pitch_bytes    = pitchBytes;
    vrt_image_buffer.width          = width;
    vrt_image_buffer.height         = height;
    vrt_image_buffer.color_format   = colorFormat;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxImageBuffer::operator vm_image_buffer_struct() const
{
    vm_image_buffer_struct ret;
    ret.buf_p = ptr;
    ret.pitch_bytes = pitchBytes;
    ret.width = width;
    ret.height = height;
    ret.color_format = vpi_v2m_convert_color_type(colorFormat);
    return ret;
}
#endif /* __MMI_VENUS_PLUG_IN_ENGINE__ */


void VfxImageBuffer::assignWith(const VfxImageBuffer &other)
{
    ptr         = other.ptr;
    pitchBytes  = other.pitchBytes;
    width       = other.width;
    height      = other.height;
    colorFormat = other.colorFormat;
}


VfxBool VfxImageBuffer::compareWith(const VfxImageBuffer &other) const
{
    return 
        ptr == other.ptr && 
        pitchBytes == other.pitchBytes &&
        width == other.width && 
        height == other.height &&
        colorFormat == other.colorFormat;
}


/***************************************************************************** 
 * Class VfxFileRawData
 *****************************************************************************/

void VfxFileRawData::initVrtImageBuffer(vrt_file_raw_data_buffer_struct &vrt_image_buffer) const
{
    vrt_image_buffer.buf_p          = ptr;
    vrt_image_buffer.image_format   = (vrt_raw_data_image_format_enum)imageFormat;
    vrt_image_buffer.image_size     = imageSize;   
}


void VfxFileRawData::assignWith(const VfxFileRawData &other)
{
    ptr         = other.ptr;
    imageSize   = other.imageSize;
    imageFormat = other.imageFormat;
}


VfxBool VfxFileRawData::compareWith(const VfxFileRawData &other) const
{
    return ptr == other.ptr && imageSize == other.imageSize && imageFormat == other.imageFormat;
}

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxFileRawData::VfxFileRawData(const vm_file_raw_data_struct &other)
{
    ptr = other.ptr;
    imageSize = other.image_size;
    imageFormat = vpi_m2v_convert_file_raw_data_format_type(other.image_format);
}
VfxFileRawData::operator vm_file_raw_data_struct() const
{
    vm_file_raw_data_struct ret;
    ret.ptr = ptr;
    ret.image_size = imageSize;
    ret.image_format = vpi_v2m_convert_file_raw_data_format_type(imageFormat);
   
    return ret;
}
#endif

/***************************************************************************** 
 * Class VfxImageSrc
 *****************************************************************************/

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxImageSrc::VfxImageSrc(const vm_image_source_struct &other)
{
    struct vm_image_source_struct_have_file_info
    {
        VM_STRUCT_HEADER
        vm_image_source_type_enum m_type;
        vm_size_struct m_proxySize;
        VMINT m_handle;
        union
        {
            VMRESID                 resIdValue;
            const VMUINT8           *memValue;
            vm_image_buffer_struct  imgBuf;
            vm_wstring_struct       path;
            vm_file_raw_data_struct rawData;
        } m_value;
        void *m_fileInfo;
    };

    m_type = vpi_m2v_convert_image_src_type(other.m_type);

    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing
            break;

        case VFX_IMAGE_SRC_TYPE_RES_ID:
            initWithResId(other.m_value.resIdValue);
            break;

        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
            m_value.mreResIdValue.handle = other.m_handle;
            m_value.mreResIdValue.id = other.m_value.resIdValue;
            m_cachedSize = other.m_proxySize;
            break;

        case VFX_IMAGE_SRC_TYPE_MEM:
            initWithMem(other.m_value.memValue);
            break;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            initWithImageBuffer(VfxImageBuffer(other.m_value.imgBuf));
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            if (VM_STRUCT_SIZE(other) >= sizeof(vm_image_source_struct_have_file_info) && other.m_fileInfo != NULL)
            {
                VFX_SYS_NEW(m_value.fileInfoPtr, FileInfo);
                m_value.fileInfoPtr->path = VfxWString(other.m_value.path);
                vfx_sys_mem_copy(&m_value.fileInfoPtr->imageInfo, other.m_fileInfo, sizeof(vrt_sys_image_info_struct));
                m_cachedSize = VfxSize(m_value.fileInfoPtr->imageInfo.size);
            }
            else
            {
                initWithPath(other.m_value.path);
            }
            break;

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            initWithFileRawData(VfxFileRawData(other.m_value.rawData));         
            break;

        default:
            VFX_DEV_ASSERT(0);
    }
}


VfxImageSrc::operator vm_image_source_struct() const
{
    vm_image_source_struct ret;
    VM_STRUCT_INIT(ret, vm_image_source_struct);
    ret.m_type = vpi_v2m_convert_image_src_type(m_type);

    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing
            break;

        case VFX_IMAGE_SRC_TYPE_RES_ID:
            ret.m_value.resIdValue = m_value.resIdValue;
            ret.m_proxySize = m_cachedSize;
            break;

        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
            ret.m_handle = m_value.mreResIdValue.handle;
            ret.m_value.resIdValue = m_value.mreResIdValue.id;
            ret.m_proxySize = m_cachedSize;
            break;

        case VFX_IMAGE_SRC_TYPE_MEM:
            ret.m_value.memValue = m_value.memValue;
            ret.m_proxySize = m_cachedSize;
            break;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            ret.m_value.imgBuf = *m_value.imgBufPtr;
            ret.m_proxySize = m_cachedSize;
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            ret.m_value.path = m_value.fileInfoPtr->path;
            ret.m_proxySize = m_cachedSize;
            ret.m_fileInfo = NULL;
            break;

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            ret.m_value.rawData = *m_value.fileRawDataPtr;
            ret.m_proxySize = m_cachedSize;

        default:
            VFX_DEV_ASSERT(0);
    }

    return ret;
}
#endif


VfxImageSrc &VfxImageSrc::operator =(const VfxImageSrc &other)
{
    if (m_type != other.m_type)
    {
        deinit();
        m_type = other.m_type;
        initWith(other);
    }
    else
    {
        assignWith(other);
    }

    return *this;
}

 
void VfxImageSrc::setResId(VfxResId resId)
{
    if (resId == 0)
    {
        deinit();
        return;
    }
    
    if (m_type != VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        deinit();
        m_type = VFX_IMAGE_SRC_TYPE_RES_ID;
        initWithResId(resId);
    }
    else
    {    
        assignWithResId(resId);
    }
}


void VfxImageSrc::setMem(const VfxU8 *mem)
{
    if (mem == NULL)
    {
        deinit();
        return;
    }
    
    if (m_type != VFX_IMAGE_SRC_TYPE_MEM)
    {
        deinit();
        m_type = VFX_IMAGE_SRC_TYPE_MEM;
        initWithMem(mem);
    }
    else
    {    
        assignWithMem(mem);
    }
}


void VfxImageSrc::setImageBuffer(const VfxImageBuffer &imgBuf)
{
    if (imgBuf.ptr == NULL)
    {
        deinit();
        return;
    }
    
    if (m_type != VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
    {
        deinit();
        m_type = VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER;
        initWithImageBuffer(imgBuf);
    }
    else
    {
        assignWithImageBuffer(imgBuf);
    }
}


void VfxImageSrc::setPath(const VfxWString &path)
{
    if (path.isNull())
    {
        deinit();
        return;
    }
    
    if (m_type != VFX_IMAGE_SRC_TYPE_PATH)
    {
        deinit();
        m_type = VFX_IMAGE_SRC_TYPE_PATH;
        initWithPath(path);
    }
    else
    {    
       assignWithPath(path);
    }
}


void VfxImageSrc::invalidate()
{
    updateCachedSize();
}


void VfxImageSrc::initWithResId(VfxResId resId)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_RES_ID);
    
    m_value.resIdValue = resId;
    m_cachedSize = vrt_sys_image_get_size_from_res_id(resId);
}


void VfxImageSrc::initWithMem(const VfxU8 *mem)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_MEM);
    
    m_value.memValue = mem;
    m_cachedSize = vrt_sys_image_get_size_from_mem(mem);
}


void VfxImageSrc::initWithImageBuffer(const VfxImageBuffer &imgBuf)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER);

    VFX_SYS_NEW_EX(m_value.imgBufPtr, VfxImageBuffer, (imgBuf));
    m_cachedSize = VfxSize(imgBuf.width, imgBuf.height);
}


void VfxImageSrc::initWithPath(const VfxWString &path)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_PATH);
    
    VFX_SYS_NEW(m_value.fileInfoPtr, FileInfo);
    m_value.fileInfoPtr->path = path;
    vrt_sys_image_get_info_from_file(path.getBuf(), &m_value.fileInfoPtr->imageInfo);
    m_cachedSize = VfxSize(m_value.fileInfoPtr->imageInfo.size);
}


void VfxImageSrc::initWithFileRawData(const VfxFileRawData &fileRawData)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA);
    VFX_DEV_ASSERT(fileRawData.imageFormat < VFX_IMAGE_FORMAT_TYPE_END_OF_ENUM);

    VFX_SYS_NEW_EX(m_value.fileRawDataPtr, VfxFileRawData, (fileRawData));
    m_cachedSize = vrt_sys_image_get_size_from_file_raw_data(
        m_value.fileRawDataPtr->ptr, 
        m_value.fileRawDataPtr->imageSize, 
        (vrt_raw_data_image_format_enum)m_value.fileRawDataPtr->imageFormat);
}


void VfxImageSrc::initWith(const VfxImageSrc &other)
{
    VFX_DEV_ASSERT(m_type == other.m_type);
    
    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing
            break;
            
        case VFX_IMAGE_SRC_TYPE_RES_ID:
            m_value.resIdValue = other.m_value.resIdValue;
            break;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
            m_value.mreResIdValue.id = other.m_value.mreResIdValue.id;
            m_value.mreResIdValue.handle = other.m_value.mreResIdValue.handle;
            break;
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
            m_value.memValue = other.m_value.memValue;
            break;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            VFX_DEV_ASSERT(other.m_value.imgBufPtr != NULL);
            VFX_SYS_NEW_EX(m_value.imgBufPtr, VfxImageBuffer, (*other.m_value.imgBufPtr));
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            VFX_DEV_ASSERT(other.m_value.fileInfoPtr != NULL);
            VFX_SYS_NEW(m_value.fileInfoPtr, FileInfo);
            m_value.fileInfoPtr->path = other.m_value.fileInfoPtr->path;
            m_value.fileInfoPtr->imageInfo = other.m_value.fileInfoPtr->imageInfo;
            break;

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            VFX_DEV_ASSERT(other.m_value.fileRawDataPtr != NULL);
            VFX_SYS_NEW_EX(m_value.fileRawDataPtr, VfxFileRawData, (*other.m_value.fileRawDataPtr));
            break;
            
        default:
            VFX_DEV_ASSERT(0);
    }

    m_cachedSize = other.m_cachedSize;    
}


void VfxImageSrc::deinit()
{
    // TODO: This is a workaround implementation for ADS compiler
    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
        case VFX_IMAGE_SRC_TYPE_RES_ID:
        case VFX_IMAGE_SRC_TYPE_MEM:
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
#endif
            // Do nothing
            break;
            
        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            VFX_DEV_ASSERT(m_value.imgBufPtr != NULL);
            VFX_DELETE(m_value.imgBufPtr);
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
            VFX_DELETE(m_value.fileInfoPtr);
            break;

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            VFX_DEV_ASSERT(m_value.fileRawDataPtr != NULL);
            VFX_DELETE(m_value.fileRawDataPtr);
            break;
        default:
            VFX_DEV_ASSERT(0);
    }

    m_type = VFX_IMAGE_SRC_TYPE_NULL;
    m_cachedSize.setZero();
}


void VfxImageSrc::assignWithResId(VfxResId resId)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_RES_ID);
    
    m_value.resIdValue = resId;
    m_cachedSize = vrt_sys_image_get_size_from_res_id(resId);
}


void VfxImageSrc::assignWithMem(const VfxU8 *mem)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_MEM);
    
    m_value.memValue = mem;
    m_cachedSize = vrt_sys_image_get_size_from_mem(mem);
}


void VfxImageSrc::assignWithImageBuffer(const VfxImageBuffer &imgBuf)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER);

    VFX_DEV_ASSERT(m_value.imgBufPtr != NULL);
    *m_value.imgBufPtr = imgBuf;
    m_cachedSize = VfxSize(imgBuf.width, imgBuf.height);
}


void VfxImageSrc::assignWithPath(const VfxWString &path)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_PATH);

    VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
    m_value.fileInfoPtr->path = path;
    vrt_sys_image_get_info_from_file(path.getBuf(), &m_value.fileInfoPtr->imageInfo);
    m_cachedSize = VfxSize(m_value.fileInfoPtr->imageInfo.size);
}


void VfxImageSrc::assignWithFileInfo(const VfxImageSrc::FileInfo &fileInfo)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_PATH);

    VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
    m_value.fileInfoPtr->path = fileInfo.path;
    m_value.fileInfoPtr->imageInfo = fileInfo.imageInfo;
    m_cachedSize = VfxSize(m_value.fileInfoPtr->imageInfo.size);
}


void VfxImageSrc::assignWithFileRawData(const VfxFileRawData &fileRawData)
{
    VFX_DEV_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA);

    VFX_DEV_ASSERT(m_value.fileRawDataPtr != NULL);
    *m_value.fileRawDataPtr = fileRawData;
    m_cachedSize = vrt_sys_image_get_size_from_file_raw_data(
        fileRawData.ptr, 
        fileRawData.imageSize, 
        (vrt_raw_data_image_format_enum)fileRawData.imageFormat);
}


void VfxImageSrc::assignWith(const VfxImageSrc &other)
{
    VFX_DEV_ASSERT(m_type == other.m_type);

    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing
            break;
            
        case VFX_IMAGE_SRC_TYPE_RES_ID:
            assignWithResId(other.m_value.resIdValue);
            break;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
            m_value.mreResIdValue.handle = other.m_value.mreResIdValue.handle;
            m_value.mreResIdValue.id = other.m_value.mreResIdValue.id;
            m_cachedSize = other.m_cachedSize;
            break;
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
            assignWithMem(other.m_value.memValue);
            break;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            VFX_DEV_ASSERT(other.m_value.imgBufPtr != NULL);
            assignWithImageBuffer(*other.m_value.imgBufPtr);
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            VFX_DEV_ASSERT(other.m_value.fileInfoPtr != NULL);
            assignWithFileInfo(*other.m_value.fileInfoPtr);
            break;
            
        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            VFX_DEV_ASSERT(other.m_value.fileRawDataPtr != NULL);
            assignWithFileRawData(*other.m_value.fileRawDataPtr);
            break;

        default:
            VFX_DEV_ASSERT(0);
    }
}


VfxBool VfxImageSrc::compareWith(const VfxImageSrc &other) const
{
    if (m_type != other.m_type)
    {
        return VFX_FALSE;
    }

    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Always return true
            return VFX_TRUE;
            
        case VFX_IMAGE_SRC_TYPE_RES_ID:
            return m_value.resIdValue == other.m_value.resIdValue;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
            return (m_value.mreResIdValue.id == other.m_value.mreResIdValue.id) &&
                   (m_value.mreResIdValue.handle == other.m_value.mreResIdValue.handle);
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
            return m_value.memValue == other.m_value.memValue;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            VFX_DEV_ASSERT(m_value.imgBufPtr != NULL && other.m_value.imgBufPtr != NULL);
            return *m_value.imgBufPtr == *other.m_value.imgBufPtr;

        case VFX_IMAGE_SRC_TYPE_PATH:
            VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL && other.m_value.fileInfoPtr != NULL);
            return m_value.fileInfoPtr->path == other.m_value.fileInfoPtr->path;
            
        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            VFX_DEV_ASSERT(m_value.fileRawDataPtr != NULL && other.m_value.fileRawDataPtr != NULL);
            return *m_value.fileRawDataPtr == *other.m_value.fileRawDataPtr;
            
        default:
            VFX_DEV_ASSERT(0);
    }

    return VFX_FALSE;
}


void VfxImageSrc::updateCachedSize()
{
    switch (m_type)
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
#endif
            // Do nothing
            break;
            
        case VFX_IMAGE_SRC_TYPE_RES_ID:
            m_cachedSize = vrt_sys_image_get_size_from_res_id(m_value.resIdValue);
            break;

        case VFX_IMAGE_SRC_TYPE_MEM:
            m_cachedSize = vrt_sys_image_get_size_from_mem(m_value.memValue);
            break;

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
            VFX_DEV_ASSERT(m_value.imgBufPtr != NULL);
            m_cachedSize = VfxSize(m_value.imgBufPtr->width, m_value.imgBufPtr->height);
            break;

        case VFX_IMAGE_SRC_TYPE_PATH:
            VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
            vrt_sys_image_get_info_from_file(
                m_value.fileInfoPtr->path.getBuf(),
                &m_value.fileInfoPtr->imageInfo);
            m_cachedSize = VfxSize(m_value.fileInfoPtr->imageInfo.size);
            break;
            
        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
            VFX_DEV_ASSERT(m_value.fileRawDataPtr != NULL);
            m_cachedSize = vrt_sys_image_get_size_from_file_raw_data(
                m_value.fileRawDataPtr->ptr, 
                m_value.fileRawDataPtr->imageSize, 
                (vrt_raw_data_image_format_enum)m_value.fileRawDataPtr->imageFormat);
            break;

        default:
            VFX_DEV_ASSERT(0);
    }
}


/***************************************************************************** 
 * Class VfxImageList
 *****************************************************************************/

VFX_IMPLEMENT_CONST(g_vfxImageListNullImgSrc, VfxImageSrc, ());


VfxImageList::VfxImageList(const VfxImageList &other) : 
    m_imgDescArray(NULL),
    m_imgDescCount(0)
{
    if (other.m_imgDescArray == NULL)
    {
        VFX_DEV_ASSERT(other.m_imgDescCount == 0);        
        // Do nothing.
        return;
    }
    
    // Prepare array
    VfxU32 arraySize = needArraySize(other.m_imgDescCount);
    prepareArray(arraySize);
    
    // Create with the other image list    
    VfxU32 i;
    for (i = 0; i < other.m_imgDescCount; i++)
    {
        ImageDescArrayElement *otherElement = other.m_imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        createElement(i, otherElement->key, otherElement->value);
    }
    m_imgDescCount = other.m_imgDescCount;
}


void VfxImageList::setItem(VfxId key, const VfxImageSrc &imgSrc)
{
    // If the key is exist
    VfxU32 index = findElement(key);

    // If the imgSrc is null, remove the item
    if (imgSrc.isNull())
    {
        removeElement(index);
        return;
    }

    // If the key is exist, assigned with the new value    
    if (index < m_imgDescCount)
    {
        m_imgDescArray[index]->value = imgSrc;
        return;
    }

    // Add a new element
    addElement(key, imgSrc);
}


const VfxImageSrc &VfxImageList::getItemWithIndex(VfxU32 index) const
{
    // The key is not found
    if (index >= m_imgDescCount)
    {
        return VFX_GET_CONST(g_vfxImageListNullImgSrc);
    }    
    
    VFX_DEV_ASSERT(m_imgDescArray != NULL);
    return m_imgDescArray[index]->value;
}


void VfxImageList::prepareArray(VfxU32 arraySize)
{
    VFX_DEV_ASSERT(m_imgDescArray == NULL);
    
    if (arraySize == 0)
    {
        // Do nothing
        return;
    }
    
    VFX_SYS_ALLOC_MEM(m_imgDescArray, sizeof(ImageDescArrayElementPtr) * arraySize);
    memset(m_imgDescArray, 0, sizeof(ImageDescArrayElementPtr) * arraySize);
}


void VfxImageList::createElement(VfxU32 index, VfxId key, const VfxImageSrc &value)
{
    VFX_DEV_ASSERT(m_imgDescArray != NULL);
    VFX_DEV_ASSERT(m_imgDescArray[index] == NULL);
    
    VFX_SYS_NEW(m_imgDescArray[index], ImageDescArrayElement);
    m_imgDescArray[index]->key = key;
    m_imgDescArray[index]->value = value;
}


void VfxImageList::assignElement(VfxU32 index, VfxId key, const VfxImageSrc &value)
{
    VFX_DEV_ASSERT(m_imgDescArray != NULL);
    VFX_DEV_ASSERT(m_imgDescArray[index] != NULL);
    
    m_imgDescArray[index]->key = key;
    m_imgDescArray[index]->value = value;
}


void VfxImageList::copyElements(ImageDescArrayElementPtr *to, const ImageDescArrayElementPtr *from, VfxU32 count)
{
    if (count == 0)
    {
        // Do nothing
        return;
    }
    
    VFX_DEV_ASSERT(to != NULL && from != NULL);
    vfx_sys_mem_copy(to, from, sizeof(ImageDescArrayElementPtr) * count);    
}


void VfxImageList::cloneWithOtherArray(const ImageDescArrayElementPtr *imgDescArray, VfxU32 count)
{    
    VfxU32 i;
    for (i = 0; i < count; i++)
    {
        const ImageDescArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        createElement(i, otherElement->key, otherElement->value);
    }
}


void VfxImageList::assignWithOtherArray(const ImageDescArrayElementPtr *imgDescArray, VfxU32 count)
{
    VfxU32 i;
    for (i = 0; i < vfxMin(count, m_imgDescCount); i++)
    {
        const ImageDescArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        assignElement(i, otherElement->key, otherElement->value);
    }
    for (;i < count; i++)
    {
        const ImageDescArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        createElement(i, otherElement->key, otherElement->value);
    }
    for (;i < m_imgDescCount; i++)
    {
        VFX_SYS_DELETE(m_imgDescArray[i]);
    }
}


void VfxImageList::assignWith(const VfxImageList &other)
{
    if (m_imgDescArray == other.m_imgDescArray)
    {
        // Self assignmenet, do nothing
        return;
    }
    
    if (other.m_imgDescArray == NULL)
    {
        VFX_DEV_ASSERT(other.m_imgDescCount == 0);        
        clear();
        return;
    }

    VfxU32 currentArraySize = needArraySize(m_imgDescCount);
    VfxU32 assignedArraySize = needArraySize(other.m_imgDescCount);
    if (currentArraySize != assignedArraySize)
    {
        // Prepare a new array if needed
        clear();
        prepareArray(assignedArraySize);
        
        cloneWithOtherArray(other.m_imgDescArray, other.m_imgDescCount);
    }
    else
    {
        assignWithOtherArray(other.m_imgDescArray, other.m_imgDescCount);
    }

    // Update the data count
    m_imgDescCount = other.m_imgDescCount;
}


void VfxImageList::clear()
{
    VfxU32 i;
    for (i = 0; i < m_imgDescCount; i++)
    {
        VFX_SYS_DELETE(m_imgDescArray[i]);
    }    
    VFX_SYS_FREE_MEM(m_imgDescArray);
    m_imgDescCount = 0;
}


VfxU32 VfxImageList::findElement(VfxId key) const
{
    VfxU32 i;
    for (i = 0; i < m_imgDescCount; i++)
    {
        VFX_DEV_ASSERT(m_imgDescArray[i] != NULL);
        if (m_imgDescArray[i]->key == key)
        {
            break;
        }
    }
    return i;
}


void VfxImageList::addElement(VfxId key, const VfxImageSrc &value)
{
    VfxU32 newIndex = m_imgDescCount;
    VfxU32 currentArraySize = needArraySize(m_imgDescCount);
    VfxU32 addedArraySize = needArraySize(m_imgDescCount + 1);    
    VFX_DEV_ASSERT(addedArraySize >= currentArraySize);

    if (addedArraySize != currentArraySize)
    {
        // Backup old array
        ImageDescArrayElementPtr *oldArray = m_imgDescArray;

        // Clone array with bigger size
        m_imgDescArray = NULL;
        prepareArray(addedArraySize);
        copyElements(m_imgDescArray, oldArray, m_imgDescCount);

        // Delete old array
        VFX_SYS_FREE_MEM(oldArray);
    }

    // Create a new element and assign the     
    createElement(newIndex, key, value);

    // Update the data count
    m_imgDescCount++;
}


void VfxImageList::removeElement(VfxU32 index)
{
    if (index >= m_imgDescCount)
    {
        // Do nothing
        return;
    }

    // itemPos is must in the range of array
    VFX_DEV_ASSERT(m_imgDescArray != NULL && m_imgDescCount != 0);
    VFX_DEV_ASSERT(index < m_imgDescCount);
    VFX_DEV_ASSERT(m_imgDescArray[index] != NULL);

    // free the element
    VFX_SYS_DELETE(m_imgDescArray[index]);

    VfxU32 currentNeedSize = needArraySize(m_imgDescCount);
    VfxU32 removedNeedSize = needArraySize(m_imgDescCount - 1);
    VFX_DEV_ASSERT(removedNeedSize <= currentNeedSize);

    // Backup the current array
    ImageDescArrayElementPtr *oldArray = m_imgDescArray;

    // Check if need to reduce the array size
    if (currentNeedSize != removedNeedSize)
    {
        m_imgDescArray = NULL;
        prepareArray(removedNeedSize);
        copyElements(m_imgDescArray, oldArray, index);
    }

    // Copy elements after index
    if (removedNeedSize - index != 0)
    {
        copyElements(
            m_imgDescArray + index, 
            oldArray + index + 1, 
            removedNeedSize - index);
    }

    // Update the data count
    m_imgDescCount--;

    // Free old array if needed
    if (currentNeedSize != removedNeedSize)
    {
        VFX_SYS_FREE_MEM(oldArray);
    }
}

