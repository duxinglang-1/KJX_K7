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
 *  vfx_owner_draw.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Owner Draw Class 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_owner_draw.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vrt_system.h"
#include "vrt_canvas.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_system.h"
#endif

extern "C"
{
    #include "cache_sw.h"
    #include "mmi_frm_mem_gprot.h"
}

/***************************************************************************** 
 * Class VfxOwnerDraw
 *****************************************************************************/

VfxOwnerDraw::VfxOwnerDraw()
: m_dirtyRect(VFX_RECT_ZERO), 
  m_bInit(VFX_FALSE), 
  m_targetFrame(NULL), 
  m_isNeedHWRenderingBuffer(VRT_FALSE),
  m_isNeedHWRenderingBufferVrt(VRT_FALSE)
{
}

VfxOwnerDraw::~VfxOwnerDraw()
{
    VFX_DEV_ASSERT(!m_bInit);
}

void VfxOwnerDraw::onCallback(
    const vrt_image_buffer_struct *image_buffer,
    const vrt_rect_struct *dst_rect,
    const vrt_rect_struct *src_rect,
    void *param)
{
    VFX_ASSERT(image_buffer != NULL);
    VFX_ASSERT(param != NULL);

    VfxOwnerDraw *ownerDraw = static_cast<VfxOwnerDraw *>((IVrtOwnerDraw *)param);
    VfxImageBuffer dstBuf(*image_buffer);
    VfxRect dstRect(*dst_rect);
    VfxRect srcRect(*src_rect);
    vrt_canvas_before_using_resource();
    ownerDraw->onDraw((VfxImageBuffer &)dstBuf, (VfxRect &)dstRect, (VfxRect &)srcRect);
    vrt_canvas_after_using_resource();
}

void VfxOwnerDraw::setResourceFromResId(VfxId key, VfxResId resId)
{
    m_ImageSrcList.setItemWithResId(key, resId);
}


void VfxOwnerDraw::setResourceFromPath(VfxId key, const VfxWString &path)
{
    m_ImageSrcList.setItemWithPath(key, path);
}

void VfxOwnerDraw::setResourceFromRawData(VfxId key, VfxU8* buf_p, VfxU32 imageSize, VfxFileRawDataFormatEnum imageFormat)
{
	VfxImageSrc raw_data(buf_p, imageSize, imageFormat);
    m_ImageSrcList.setItem(key, raw_data);
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
void VfxOwnerDraw::setResource(VfxId key, const VfxImageSrc &imgSrc)
{
    m_ImageSrcList.setItem(key, imgSrc);
}
#endif


void VfxOwnerDraw::setTargetFrame(VfxFrame *ptr)
{
    m_targetFrame = ptr;
}


void VfxOwnerDraw::removeResource(VfxId key)
{
    m_ImageSrcList.removeItem(key);
}


VfxBool VfxOwnerDraw::getResource(VfxId key, VfxImageBuffer &imgBuf) const
{
    vrt_image_source_struct image_src;
    vrt_image_buffer_struct img_buf;
    VfxBool succeed;

    const VfxImageSrc &imgSrc = m_ImageSrcList.getItem(key);

    switch (imgSrc.getType())
    {
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        image_src.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        image_src.data.img_ptr = vrt_sys_res_image_lock(imgSrc.getResId());
        break;
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
        image_src.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        image_src.data.img_ptr = vpi_sys_get_vm_resource(imgSrc.getHandle(), imgSrc.getMreResId(), VFX_TRUE);
        break;
#endif
    case VFX_IMAGE_SRC_TYPE_MEM:
        image_src.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        image_src.data.img_ptr = imgSrc.getMem();
        break;
    case VFX_IMAGE_SRC_TYPE_PATH:
        image_src.type = VRT_IMAGE_SOURCE_TYPE_FILE;
        image_src.data.filename.hash = vrt_wstr_hash(imgSrc.getPath());
        image_src.data.filename.str = imgSrc.getPath();
        break;
    case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
        image_src.type = VRT_IMAGE_SOURCE_TYPE_IMG_RAW_DATA;
        image_src.data.raw_data.buf_p = imgSrc.getImageRawDataBuffer().ptr;
        image_src.data.raw_data.image_format = (vrt_raw_data_image_format_enum)imgSrc.getImageRawDataBuffer().imageFormat;
        image_src.data.raw_data.image_size= imgSrc.getImageRawDataBuffer().imageSize;
        break;
    default:
        return VFX_FALSE;
    }
    succeed = vrt_canvas_get_resource(&image_src, &img_buf)? VFX_TRUE : VFX_FALSE;
    imgBuf = img_buf;
    return succeed;
}


void VfxOwnerDraw::onDeinit()
{
    // NOTE: Should call VfxFrame::setOwnerDraw(NULL) first, then close the owner draw.
    VFX_DEV_ASSERT(m_targetFrame == NULL);
}

void VfxOwnerDraw::initResource()
{
    if (!m_bInit)
    {        
        onInitResource();
        m_bInit = VFX_TRUE;
    }
}

void VfxOwnerDraw::deinitResource()
{
    if (m_bInit)
    {        
        onDeinitResource();
        m_bInit = VFX_FALSE;
    }
}

void VfxOwnerDraw::onInitResource()
{
}

void VfxOwnerDraw::onDeinitResource()
{
}


vrt_render_owner_draw_dirty_type_enum VfxOwnerDraw::executeAnimation(vrt_msec_type currFrameTime)
{
    VfxRect dirtyRect;

    vrt_render_owner_draw_dirty_type_enum dirtyType = onExecuteAnimation(currFrameTime, dirtyRect);

    if ((dirtyType == VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NORMAL || 
         dirtyType == VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_TIME_LINE_DIRTY) &&
         !dirtyRect.isEmpty())
    {
        setDirtyRect(dirtyRect);

        return dirtyType;
    }

    return VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE;
}


void VfxOwnerDraw::getDirtyRect(vrt_rect_struct &rect) const
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    rect.origin.x = m_dirtyRect.origin.x;
    rect.origin.y = m_dirtyRect.origin.y;
    rect.size.width = m_dirtyRect.size.width;
    rect.size.height = m_dirtyRect.size.height;

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDraw::setDirtyRect(VfxRect &rect)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    if (m_dirtyRect.isEmpty())
    {
        m_dirtyRect = rect;
    }
    else
    {
        m_dirtyRect.unionWith(rect);
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDraw::resetDirtyRect()
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    m_dirtyRect = VFX_RECT_ZERO;

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


vrt_bool VfxOwnerDraw::isDirty() const
{
    vrt_bool ret = VRT_FALSE;
    
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    if (!m_dirtyRect.isEmpty())
    {
        ret = VRT_TRUE;
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;

    return ret;
}


void VfxOwnerDraw::commitCallback()
{
    onCommit();

    m_isNeedHWRenderingBufferVrt = m_isNeedHWRenderingBuffer;
}

/***************************************************************************** 
 * Class VfxOwnerDrawWrapper
 *****************************************************************************/

#define OWNER_DRAW_MEM_ALIGNMENT 32

#define OWNER_DRAW_MEM_LEFT_ALIGN(x) (x & ~(OWNER_DRAW_MEM_ALIGNMENT - 1))
#define OWNER_DRAW_MEM_ALIGN(x) ((((VfxU32)x) + OWNER_DRAW_MEM_ALIGNMENT - 1) / OWNER_DRAW_MEM_ALIGNMENT * OWNER_DRAW_MEM_ALIGNMENT)

#define OWNER_DRAW_MEM_PADDING(x) ((x) + OWNER_DRAW_MEM_ALIGNMENT - 1 + OWNER_DRAW_MEM_ALIGNMENT - 1)
#define OWNER_DRAW_MEM_PADDING_ALIGN(x) (OWNER_DRAW_MEM_ALIGN(x))


VfxOwnerDrawWrapper::VfxOwnerDrawWrapper() : 
    m_callback(NULL),
    m_userData(NULL),
    m_userDataSize(0),
    m_animationCallback(NULL),
    m_animationUserData(NULL),
    m_animationUserDataSize(0),
    m_commitCallback(NULL),
    m_commitUserData(NULL),
    m_commitUserDataSize(0),
    m_frameWidth(0),
    m_frameHeight(0),
    m_frameColorFormat(VRT_COLOR_TYPE_UNKNOWN)
{
    resetFrameBuffer();
}


VfxOwnerDrawWrapper::~VfxOwnerDrawWrapper()
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    if (m_userData)
    {
        VFX_FREE_MEM(m_userData);
    }

    m_userData = NULL;
    m_userDataSize = 0;

    if (m_animationUserData)
    {
        VFX_FREE_MEM(m_animationUserData);
    }

    m_animationUserData = NULL;
    m_animationUserDataSize = 0;

    if (m_commitUserData)
    {
        VFX_FREE_MEM(m_commitUserData);
    }

    m_commitUserData = NULL;
    m_commitUserDataSize = 0;

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}

void VfxOwnerDrawWrapper::setFrameBuffer(VfxImageBuffer &buffer)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    if (buffer != m_frameBuffer)
    {
        resetFrameBuffer();

        m_frameBuffer= buffer;
    }
    
    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


const VfxImageBuffer &VfxOwnerDrawWrapper::getFrameBuffer() const
{
    return m_frameBuffer;
}


void VfxOwnerDrawWrapper::resetFrameBuffer()
{
    m_frameBuffer.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
    m_frameBuffer.height = 0;
    m_frameBuffer.width = 0;
    m_frameBuffer.pitchBytes = 0;
    m_frameBuffer.ptr = NULL;
}


void VfxOwnerDrawWrapper::setOwnerDrawCallback(VfxOwnerDrawCallbackFuncptrType callback, void *userData, VfxU32 userDataSize)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    m_callback = callback;

    if (m_userData)
    {
        VFX_FREE_MEM(m_userData);
    }

    if (userData && userDataSize)
    {
        VFX_ALLOC_MEM(m_userData, userDataSize, this);
        
        memcpy(m_userData, userData, userDataSize);
        
        m_userDataSize = userDataSize;
    }
    
    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDrawWrapper::setOwnerDrawAnimationCallback(VfxOwnerDrawAnimationCallbackFuncptrType callback, void *userData, VfxU32 userDataSize)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    m_animationCallback = callback;

    if (m_animationUserData)
    {
        VFX_FREE_MEM(m_animationUserData);
    }

    if (userData && userDataSize)
    {
        VFX_ALLOC_MEM(m_animationUserData, userDataSize, this);
        
        memcpy(m_animationUserData, userData, userDataSize);
        
        m_animationUserDataSize = userDataSize;
    }
    
    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDrawWrapper::setCommitCallback(VfxOwnerDrawCommitCallbackFuncptrType callback, void *userData, VfxU32 userDataSize)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    m_commitCallback = callback;

    if (m_commitUserData)
    {
        VFX_FREE_MEM(m_commitUserData);
    }

    if (userData && userDataSize)
    {
        VFX_ALLOC_MEM(m_commitUserData, userDataSize, this);
        
        memcpy(m_commitUserData, userData, userDataSize);
        
        m_commitUserDataSize = userDataSize;
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


void VfxOwnerDrawWrapper::invalidate(VfxRect &rect)
{
    setDirtyRect(rect);
}


void VfxOwnerDrawWrapper::setFrameAttributes(VfxU32 width, VfxU32 height, VfxColorTypeEnum cf)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;
        
    m_frameWidth = width;
    m_frameHeight = height;
    m_frameColorFormat = cf;

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


vrt_render_owner_draw_dirty_type_enum VfxOwnerDrawWrapper::onExecuteAnimation(VfxMsec currFrameTime, VfxRect &dirtyRect)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    vrt_render_owner_draw_dirty_type_enum ret = VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE;

    if (m_animationCallback)
    {
        ret = m_animationCallback(currFrameTime, dirtyRect, m_animationUserData, m_animationUserDataSize);
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;

    return ret;
}


void VfxOwnerDrawWrapper::onCommit()
{
    if (m_commitCallback)
    {
        m_commitCallback(m_commitUserData, m_commitUserDataSize);
    }
}


vrt_bool VfxOwnerDrawWrapper::needHWRenderingBuffer()
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    vrt_bool ret;

    if (m_frameBuffer.ptr || (m_frameWidth && m_frameHeight && m_frameColorFormat))
    {
        // There is temp buffer, ask VRT prepare HW rendering buffer, so the later flatten will be more fast
        ret = VRT_TRUE;
    }
    else
    {
        ret = VfxOwnerDraw::needHWRenderingBuffer();
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;

    return ret;
}


void VfxOwnerDrawWrapper::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION;

    VfxU8 *tempBufferPtr = NULL;
    VfxImageBuffer tempSrcBuffer;
    VfxBool isFlatten = VFX_FALSE;
    
    if (m_callback)
    {
        if (m_frameBuffer.ptr && !m_dirtyRect.isEmpty())
        {
            VfxPoint frameOrigin = VFX_POINT_ZERO;
            
            m_callback(m_frameBuffer, frameOrigin, m_dirtyRect, m_userData, m_userDataSize);
            
            isFlatten = VFX_TRUE;
        }
        else if (m_frameWidth && m_frameHeight && m_frameColorFormat)
        {
            VfxU32 bufferSize = 0;
            
            bufferSize = OWNER_DRAW_MEM_PADDING_ALIGN((m_frameWidth * m_frameHeight * getBitsPerPixel(m_frameColorFormat)) >> 3);

            VFX_ASSERT(bufferSize);

            if (VfxOwnerDraw::needHWRenderingBuffer())
            {
                tempBufferPtr = (VfxU8 *)mmi_frm_asm_alloc_anonymous_nc(bufferSize); // TODO: Temp buffer from VRT temp??
            }
            else
            {
                tempBufferPtr = (VfxU8 *)mmi_frm_asm_alloc_anonymous(bufferSize);
            }

            VFX_ASSERT(tempBufferPtr);

            tempSrcBuffer.ptr = tempBufferPtr;
            tempSrcBuffer.colorFormat = m_frameColorFormat;
            tempSrcBuffer.pitchBytes = (m_frameWidth * getBitsPerPixel(m_frameColorFormat)) >> 3;
            tempSrcBuffer.width = m_frameWidth;
            tempSrcBuffer.height = m_frameHeight;

            VfxPoint frameOrigin = VFX_POINT_ZERO;

            m_callback(tempSrcBuffer, frameOrigin, srcRect, m_userData, m_userDataSize);
            
            isFlatten = VFX_TRUE;
        }
    }

    if (m_frameBuffer.ptr || isFlatten)
    {
        // Flatten the full frame content to the dst buffer
        VfxImageBuffer srcBuffer;

        if (m_frameBuffer.ptr)
        {
            srcBuffer = m_frameBuffer;
        }
        else
        {
            srcBuffer = tempSrcBuffer;
        }

        flattenFrameBuffer(dstBuffer, dstRect, srcBuffer, srcRect);
    }
    else
    {
        // Draw the required frame content to the dst buffer
        VfxSize renderSize;

        renderSize.width = VFX_MIN(dstRect.size.width, srcRect.size.width);
        renderSize.height = VFX_MIN(dstRect.size.height, srcRect.size.height);

        if (!renderSize.isEmpty())
        {
            VfxPoint frameOrigin = VfxPoint(dstRect.origin.x - srcRect.origin.x, dstRect.origin.y - srcRect.origin.y);
            VfxRect dirtyRect = VfxRect(srcRect.origin.x, srcRect.origin.y, renderSize.width, renderSize.height);
            
            m_callback(dstBuffer, 
                frameOrigin,
                dirtyRect,
                m_userData, 
                m_userDataSize);
        }
    }

    if (tempBufferPtr)
    {
        mmi_frm_asm_free_anonymous(tempBufferPtr);
    }

    VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION;
}


VfxU32 VfxOwnerDrawWrapper::getBitsPerPixel(VfxColorTypeEnum cf)
{
    switch (cf)
    {
    case VRT_COLOR_TYPE_RGB565:
    case VRT_COLOR_TYPE_UYVY422:
        return 16;

    case VRT_COLOR_TYPE_RGB888:
    case VRT_COLOR_TYPE_PARGB6666:
        return 24;

    case VRT_COLOR_TYPE_ARGB8888:
    case VRT_COLOR_TYPE_PARGB8888:
        return 32;

    default:
        VFX_ASSERT(0); // Not support the color format
        break;
    }

    return 0;
}


VfxColorTypeEnum VfxOwnerDrawWrapper::mapGdiCFToVfxCF(gdi_color_format cf)
{
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            return VRT_COLOR_TYPE_RGB565;

        case GDI_COLOR_FORMAT_24:
            return VRT_COLOR_TYPE_RGB888;

        case GDI_COLOR_FORMAT_32:
            return VRT_COLOR_TYPE_ARGB8888;

        case GDI_COLOR_FORMAT_32_PARGB:
            return VRT_COLOR_TYPE_PARGB8888;

        case GDI_COLOR_FORMAT_UYVY422:
            return VRT_COLOR_TYPE_UYVY422;

        case GDI_COLOR_FORMAT_PARGB6666:
            return VRT_COLOR_TYPE_PARGB6666;

        default:
            VFX_ASSERT(0);
            break;
    }

    return VRT_COLOR_TYPE_UNKNOWN;
}


gdi_color_format VfxOwnerDrawWrapper::mapVfxCFToGdiCF(VfxColorTypeEnum colorFormat)
{
    gdi_color_format cf;

    cf = GDI_COLOR_FORMAT_16;

    switch (colorFormat)
    {
        case VRT_COLOR_TYPE_RGB565:
            cf = GDI_COLOR_FORMAT_16;
            break;

        case VRT_COLOR_TYPE_RGB888:
            cf = GDI_COLOR_FORMAT_24;
            break;

        case VRT_COLOR_TYPE_ARGB8888:
            cf = GDI_COLOR_FORMAT_32;
            break;

        case VRT_COLOR_TYPE_PARGB8888:
            cf = GDI_COLOR_FORMAT_32_PARGB;
            break;

        case VRT_COLOR_TYPE_UYVY422:
            cf = GDI_COLOR_FORMAT_UYVY422;
            break;

        case VRT_COLOR_TYPE_PARGB6666:
            cf = GDI_COLOR_FORMAT_PARGB6666;
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return cf;
}


void VfxOwnerDrawWrapper::copyFrameBuffer(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxImageBuffer &srcBuffer, VfxRect &srcRect)
{
    VFX_ASSERT(dstBuffer.colorFormat == srcBuffer.colorFormat);
    
    VfxSize copySize;

    copySize.width = VFX_MIN(dstRect.size.width, srcRect.size.width);
    copySize.height = VFX_MIN(dstRect.size.height, srcRect.size.height);

    if (copySize.isEmpty())
    {
        return;
    }

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    VfxBool isDstCached = isCachedBuffer(dstBuffer);
    VfxBool isSrcCached = isCachedBuffer(srcBuffer);

    if (!isDstCached)
    {
        enableBufferDcache(dstBuffer, VFX_TRUE);
    }

    if (!isSrcCached)
    {
        enableBufferDcache(srcBuffer, VFX_TRUE);
    }

#endif /* #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

    VfxU8 *srcBuf, *dstBuf;
    VfxS32 pixelSize, copyLineSize;

    pixelSize = getBitsPerPixel(dstBuffer.colorFormat)>>3;
    
    copyLineSize = copySize.width * pixelSize;

    srcBuf = srcBuffer.ptr + srcRect.origin.y * srcBuffer.pitchBytes + srcRect.origin.x * pixelSize;
    dstBuf = dstBuffer.ptr + dstRect.origin.y * dstBuffer.pitchBytes + dstRect.origin.x * pixelSize;

    if (copySize.width == dstBuffer.width && copySize.width == srcBuffer.width)
    {
        memcpy(dstBuf, srcBuf, copyLineSize * copySize.height);
    }
    else
    {
        for (VfxS32 y = copySize.height - 1; y >= 0; y--)
        {
            memcpy(dstBuf, srcBuf, copyLineSize);
            srcBuf += srcBuffer.pitchBytes;
            dstBuf += dstBuffer.pitchBytes;
        }
    }

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    if (!isDstCached)
    {
        VfxRect invRect(dstRect.origin.x, dstRect.origin.y, copySize.width, copySize.height);

        cleanInvalidateBufferDcacheByRect(dstBuffer, invRect, VFX_TRUE);
        enableBufferDcache(dstBuffer, VFX_FALSE);
    }

    if (!isSrcCached)
    {
        VfxRect invRect(srcRect.origin.x, srcRect.origin.y, copySize.width, copySize.height);

        cleanInvalidateBufferDcacheByRect(srcBuffer, invRect, VFX_TRUE);
        enableBufferDcache(srcBuffer, VFX_FALSE);
    }

#endif /* #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

}


void VfxOwnerDrawWrapper::flattenFrameBuffer(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxImageBuffer &srcBuffer, VfxRect &srcRect)
{
#if 0 // Flatten is more fast than memory copy
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VfxSize flattenSize;

    flattenSize.width = VFX_MIN(dstRect.size.width, srcRect.size.width);
    flattenSize.height = VFX_MIN(dstRect.size.height, srcRect.size.height);

    if (flattenSize.isEmpty())
    {
        return;
    }

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    VfxBool isDstCached = isCachedBuffer(dstBuffer);
    VfxBool isSrcCached = isCachedBuffer(srcBuffer);

    if (isDstCached)
    {
        VfxRect invRect(dstRect.origin.x, dstRect.origin.y, flattenSize.width, flattenSize.height);
        
        cleanInvalidateBufferDcacheByRect(dstBuffer, invRect, VFX_TRUE);
        enableBufferDcache(dstBuffer, VFX_FALSE);
    }

    if (isSrcCached)
    {
        VfxRect invRect(srcRect.origin.x, srcRect.origin.y, flattenSize.width, flattenSize.height);
        
        cleanInvalidateBufferDcacheByRect(srcBuffer, invRect, VFX_TRUE);
        enableBufferDcache(srcBuffer, VFX_FALSE);
    }

#endif /* #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) */   

    gdi_handle srcLayer = GDI_NULL_HANDLE, dstLayer = GDI_NULL_HANDLE;

    gdi_layer_create_cf_using_outside_memory(
        mapVfxCFToGdiCF(dstBuffer.colorFormat),
        0,
        0,
        dstBuffer.width,
        dstBuffer.height,
        &dstLayer,
        dstBuffer.ptr,
        (dstBuffer.width * dstBuffer.height * getBitsPerPixel(dstBuffer.colorFormat))>>3);

    gdi_layer_create_cf_using_outside_memory(
        mapVfxCFToGdiCF(srcBuffer.colorFormat),
        dstRect.origin.x - srcRect.origin.x,
        dstRect.origin.y - srcRect.origin.y,
        srcBuffer.width,
        srcBuffer.height,
        &srcLayer,
        srcBuffer.ptr,
        (srcBuffer.width * srcBuffer.height * getBitsPerPixel(srcBuffer.colorFormat))>>3);

    VFX_ASSERT(srcLayer && dstLayer);

    gdi_layer_push_and_set_active(srcLayer);
    
    if (gdi_layer_get_bit_per_pixel() == 32)
    {
        BOOL opacity_enable;
        VfxU8 opacity_value;

        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        gdi_layer_set_opacity(TRUE, opacity_value);
    }
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dstLayer);
    
    if (gdi_layer_get_bit_per_pixel() == 32)
    {
        gdi_layer_set_opacity(TRUE, 255);
        gdi_layer_set_source_key(FALSE, 0);
        gdi_layer_set_background(0);
    }

    gdi_layer_set_clip(dstRect.origin.x, 
        dstRect.origin.y, 
        dstRect.origin.x + flattenSize.width - 1, 
        dstRect.origin.y + flattenSize.height - 1);

    gdi_layer_flatten_with_clipping(dstLayer, srcLayer, 0, 0);
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(dstLayer);
    gdi_layer_free(srcLayer);


#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    if (isDstCached)
    {
        enableBufferDcache(dstBuffer, VFX_TRUE);
    }

    if (isSrcCached)
    {
        enableBufferDcache(srcBuffer, VFX_TRUE);
    }

#endif /* #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

}

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

#define IS_DCACHE_ALIGNED_ADDR(p) (((VfxU32)(p) & (OWNER_DRAW_MEM_ALIGNMENT - 1)) == 0)

VfxBool VfxOwnerDrawWrapper::isCachedBuffer(VfxImageBuffer &buf)
{
    return INT_QueryIsCachedRAM((VfxU32)buf.ptr, 0) ? VFX_TRUE : VFX_FALSE;
}


void VfxOwnerDrawWrapper::cleanInvalidateBufferDcacheByRect(VfxImageBuffer &buf, VfxRect &rect, VfxBool isInv)
{
    VfxU32 bufPtr;
    
    bufPtr = (VfxU32)buf.ptr;
    
    if (INT_QueryIsNonCachedRAM((VfxU32)bufPtr, 0) || !IS_DCACHE_ALIGNED_ADDR(bufPtr))
    {
        return;
    }

    VfxRect fullRect(0, 0, buf.width, buf.height);
    VfxRect dirtyRect;

    if (rect.isEmpty())
    {   /* clean the whole layer */
        dirtyRect = fullRect;
    }
    else
    {
        dirtyRect = rect;
        dirtyRect = dirtyRect.intersectWith(fullRect);
    }

    if (dirtyRect.isEmpty())
    {
        return;
    }

    VfxS32 pixelSize, dirtyLineSize, pitch, y;
    
    VfxU32 lineAlignedStartAddr, lineStartAddr, lineEndAddr, lineCacheLineSize;

    pixelSize = getBitsPerPixel(buf.colorFormat) >> 3;

    lineStartAddr = bufPtr + (dirtyRect.origin.y * buf.width + dirtyRect.origin.x) * pixelSize;
    dirtyLineSize = dirtyRect.size.width * pixelSize;
    pitch = buf.width * pixelSize;

    /* clean cache line by line */
    for (y = dirtyRect.size.height - 1; y >= 0; y--)
    {
        lineEndAddr = lineStartAddr + dirtyLineSize;

        /* align line start addr to 32-byte */
        lineAlignedStartAddr = OWNER_DRAW_MEM_LEFT_ALIGN(lineStartAddr);
        /* clean size must be mutiples of cache line size */
        lineCacheLineSize = OWNER_DRAW_MEM_LEFT_ALIGN(lineEndAddr - lineAlignedStartAddr);

        if (isInv)
        {
            clean_and_invalidate_dcache((VfxU32)lineAlignedStartAddr, (VfxU32)lineCacheLineSize);
        }
        else
        {
            clean_dcache((VfxU32)lineAlignedStartAddr, (VfxU32)lineCacheLineSize);
        }

        lineStartAddr += pitch;
    }
}


void VfxOwnerDrawWrapper::enableBufferDcache(VfxImageBuffer &buf, VfxBool enable)
{
    /* do nothing if the buffer is not cache-line aligned */
    if (!IS_DCACHE_ALIGNED_ADDR(buf.ptr))
    {
        return;
    }

    if (enable)
    {   /* vrt_sys_phys_to_virt, use virtual address */
        buf.ptr = (VfxU8 *)physToVirt(buf.ptr);
    }
    else
    {   /* vrt_sys_virt_to_phys, use physical address */
        buf.ptr = (VfxU8 *)virtToPhys(buf.ptr);
    }
}


void *VfxOwnerDrawWrapper::physToVirt(void *address)
{
    return (void *)phys_to_virt((void *)address);
}


void *VfxOwnerDrawWrapper::virtToPhys(void *address)
{
    if (INT_QueryIsCachedRAM(address, 0))
    {
        return (void *)virt_to_phys((void *)address);
    }
    else
    {
        return address;
    }
}

#endif /* #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

