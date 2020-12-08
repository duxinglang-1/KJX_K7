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
 *  vfx_frame_filter.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Frame Filter Class 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame_filter.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_image_src.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vrt_system.h"
#include "vrt_canvas.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_system.h"
#endif

/***************************************************************************** 
 * Class VfxFrameFilter
 *****************************************************************************/

VfxFrameFilter::VfxFrameFilter() :
    m_targetFrame(NULL), m_colorFormat(VRT_COLOR_TYPE_UNKNOWN)
{
}


void VfxFrameFilter::onDeinit()
{
    // NOTE: Should call VfxFrame::setFilter(NULL) first, then close the frame filter.
    VFX_DEV_ASSERT(m_targetFrame == NULL);
}

 
vrt_bool VfxFrameFilter::onCallback(
    const vrt_image_buffer_struct *image_buffer, 
    vrt_u8 *out_buf_p, 
    void *param, 
    vrt_float t)
{
    VFX_ASSERT(image_buffer != NULL);
    VFX_ASSERT(param != NULL);

    VfxFrameFilter *filter = static_cast<VfxFrameFilter *>((IVrtFrameFilter *)param);

    VfxImageBuffer inBuf(*image_buffer);
    vrt_canvas_before_using_resource();    
    vrt_bool ret = filter->process(out_buf_p, inBuf, t) ? VRT_TRUE : VRT_FALSE;
    vrt_canvas_after_using_resource();
    return ret;
}


VfxFrameFilter::BufferModeEnum VfxFrameFilter::onGetBufferMode() const
{
    return BUFFER_MODE_IN_PLACE;
}


VfxBool VfxFrameFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    VFX_UNUSED(outBuf);
    VFX_UNUSED(inBuf);
    VFX_UNUSED(timing);
    return VFX_FALSE;
}


void VfxFrameFilter::setResourceFromResId(VfxId key, VfxResId resId)
{
    m_ImageSrcList.setItemWithResId(key, resId);
}


void VfxFrameFilter::setResourceFromPath(VfxId key, const VfxWString &path)
{
    m_ImageSrcList.setItemWithPath(key, path);
}

void VfxFrameFilter::setResourceFromRawData(VfxId key, VfxU8* buf_p, VfxU32 imageSize, VfxFileRawDataFormatEnum imageFormat)
{
	VfxImageSrc raw_data(buf_p, imageSize, imageFormat);
    m_ImageSrcList.setItem(key, raw_data);
}



#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
void VfxFrameFilter::setResource(VfxId key, const VfxImageSrc &imgSrc)
{
    m_ImageSrcList.setItem(key, imgSrc);
}
#endif


void VfxFrameFilter::setTargetFrame(VfxFrame *ptr)
{
    m_targetFrame = ptr;
}


void VfxFrameFilter::removeResource(VfxId key)
{
    m_ImageSrcList.removeItem(key);
}



VfxBool VfxFrameFilter::getResource(VfxId key, VfxImageBuffer &imgBuf) const
{
    vrt_image_source_struct image_src;
    vrt_image_buffer_struct img_buf = {0};
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


vrt_image_filter_buffer_mode VfxFrameFilter::getFilterBufferMode() const
{
    VFX_DEV_ASSERT(isValid());

    return (vrt_image_filter_buffer_mode)getBufferMode();
}


vrt_color_type_enum VfxFrameFilter::getFilterColorFormat() const
{
    VFX_DEV_ASSERT(isValid());

    return (vrt_color_type_enum)getColorFormat();
}


vrt_image_filter_kernel_callback_funcptr_type VfxFrameFilter::getCallback() const
{
    VFX_DEV_ASSERT(isValid());

    return VfxFrameFilter::onCallback;
}
