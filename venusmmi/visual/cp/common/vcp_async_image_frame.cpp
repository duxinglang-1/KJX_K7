/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_async_image_frame.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Async Image Frame
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_async_image_frame.h"
#include "vadp_sys_trc.h"

extern "C"
{
#include "mmi_platform.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_scenario_gprot.h"
}

#ifdef __MTK_TARGET__
#ifdef __VENUS_SWLA_DBG_ON__
#define __MAUI_SOFTWARE_LA__
#endif
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Global function
 *****************************************************************************/
extern "C" void VcpAsyncImageFrame_done_callback(GDI_RESULT result,gdi_handle handle)
{
    VcpAsyncImageFrame::onGdiCallback(result, handle);
}

/***************************************************************************** 
 * Class VcpAsyncImageFrame
 *****************************************************************************/  

VcpAsyncImageFrame * VcpAsyncImageFrame::m_firstObject;

VcpAsyncImageFrame::VcpAsyncImageFrame(const VfxWString &imagePath, VfxS32 previewImageId, VfxSize size):
    m_nextObject(NULL),
    m_imagePath(imagePath),
    m_imageSrc(VFX_IMAGE_SRC_NULL),
    m_previewImageId(previewImageId),
    m_size(size),
    m_data(NULL),
    m_handle(GDI_NULL_HANDLE),
    m_layer(GDI_NULL_HANDLE),
    m_timer(NULL),
    m_isAppMem(VFX_FALSE),
    m_bytePerPixel(4),
    m_gdiMode(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT)
{
}
VcpAsyncImageFrame::VcpAsyncImageFrame(const VfxWChar *imagePath, VfxS32 previewImageId, VfxSize size):
    m_nextObject(NULL),
    m_imagePath(VFX_WSTR_MEM(imagePath)),
    m_imageSrc(VFX_IMAGE_SRC_NULL),
    m_previewImageId(previewImageId),
    m_size(size),
    m_data(NULL),
    m_handle(GDI_NULL_HANDLE),
    m_layer(GDI_NULL_HANDLE),
    m_timer(NULL),
    m_isAppMem(VFX_FALSE),
    m_bytePerPixel(4),
    m_gdiMode(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT)
{
}
VcpAsyncImageFrame::VcpAsyncImageFrame(
    const VfxWString &imagePath, 
    VfxS32 previewImageId, 
    VfxSize size, 
    VfxS32 bytePerPixel, 
    VcpAsyncImageFrameMemAlloc allocFunc, 
    VcpAsyncImageFrameMemFree freeFunc,
    void *userData,
    gdi_util_mode_enum gdiMode
    ):
    m_nextObject(NULL),
    m_imagePath(imagePath),
    m_imageSrc(VFX_IMAGE_SRC_NULL),
    m_previewImageId(previewImageId),
    m_size(size),
    m_data(NULL),
    m_handle(GDI_NULL_HANDLE),
    m_layer(GDI_NULL_HANDLE),
    m_timer(NULL),
    m_isAppMem(VFX_TRUE),
    m_bytePerPixel(bytePerPixel),
    m_allocFunc(allocFunc),
    m_freeFunc(freeFunc),
    m_userData(userData),
    m_gdiMode(gdiMode)
{
}
VcpAsyncImageFrame::VcpAsyncImageFrame(
    const VfxWChar *imagePath, 
    VfxS32 previewImageId, 
    VfxSize size, 
    VfxS32 bytePerPixel, 
    VcpAsyncImageFrameMemAlloc allocFunc, 
    VcpAsyncImageFrameMemFree freeFunc,
    void *userData,
    gdi_util_mode_enum gdiMode
    ):
    m_nextObject(NULL),
    m_imagePath(VFX_WSTR_MEM(imagePath)),
    m_imageSrc(VFX_IMAGE_SRC_NULL),
    m_previewImageId(previewImageId),
    m_size(size),
    m_data(NULL),
    m_handle(GDI_NULL_HANDLE),
    m_layer(GDI_NULL_HANDLE),
    m_timer(NULL),
    m_isAppMem(VFX_TRUE),
    m_bytePerPixel(bytePerPixel),
    m_allocFunc(allocFunc),
    m_freeFunc(freeFunc),
    m_userData(userData),
    m_gdiMode(gdiMode)
{
}

VcpAsyncImageFrame::VcpAsyncImageFrame(
    const VfxImageSrc &imageSrc,
    VfxS32 previewImageId, 
    VfxSize size, 
    VfxS32 bytePerPixel, 
    VcpAsyncImageFrameMemAlloc allocFunc, 
    VcpAsyncImageFrameMemFree freeFunc,
    void *userData,
    gdi_util_mode_enum gdiMode
    ):
    m_nextObject(NULL),
    m_imagePath(VFX_WSTR_NULL),
    m_imageSrc(imageSrc),
    m_previewImageId(previewImageId),
    m_size(size),
    m_data(NULL),
    m_handle(GDI_NULL_HANDLE),
    m_layer(GDI_NULL_HANDLE),
    m_timer(NULL),
    m_isAppMem(VFX_TRUE),
    m_bytePerPixel(bytePerPixel),
    m_allocFunc(allocFunc),
    m_freeFunc(freeFunc),
    m_userData(userData),
    m_gdiMode(gdiMode)
{
}


void VcpAsyncImageFrame::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As1", SA_start);
#endif
    VfxFrame::onInit();


    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &VcpAsyncImageFrame::onTimer);

    setSize(m_size);


    if (m_firstObject == NULL)
    {
        m_firstObject = this;
    }
    else
    {
        VcpAsyncImageFrame * lastObject = m_firstObject;
        while (lastObject->m_nextObject != NULL)
        {
            lastObject = lastObject->m_nextObject;
        }
        lastObject->m_nextObject = this;
    }

    setImgContent(VfxImageSrc(m_previewImageId));
    // Check image type
    if (m_imageSrc.getType() != VFX_IMAGE_SRC_TYPE_NULL &&
        m_imageSrc.getType() != VFX_IMAGE_SRC_TYPE_MEM &&
        m_imageSrc.getType() != VFX_IMAGE_SRC_TYPE_PATH)
    {
        m_gdiResultCallback.postEmit(GDI_FAILED);
        return;
    }
    
    // init image buffer
    if (m_isAppMem)
    {
        m_data = (VfxU8 *)m_allocFunc(m_size.width * m_size.height * m_bytePerPixel, m_userData);

        VFX_LOG(VFX_INFO, VCP_ASYNC_IMAGE_FRAME_CREATE_BUFF_BY_APP, m_data);

        if (m_data == NULL)
        {
            m_gdiResultCallback.postEmit(GDI_FAILED);
            return;
        }
        //VFX_ASSERT(m_data != NULL);
        memset(m_data, 0, m_size.width * m_size.height * m_bytePerPixel);
    }
    else
    {
        m_gid = mmi_frm_group_get_active_id();
        m_data = (VfxU8 *)mmi_frm_asm_alloc_nc_r(m_gid, m_size.width * m_size.height * m_bytePerPixel);

        VFX_LOG(VFX_INFO, VCP_ASYNC_IMAGE_FRAME_CREATE_BUFF, m_data);

        //VFX_ASSERT(m_data != NULL);
        if (m_data == NULL)
        {
            m_gdiResultCallback.postEmit(GDI_FAILED);
            return;
        }
        memset(m_data, 0, m_size.width * m_size.height * m_bytePerPixel);
    }
    
    m_imageBuffer.ptr = m_data;
    m_imageBuffer.width = m_size.width;
    m_imageBuffer.height = m_size.height;
    m_imageBuffer.pitchBytes = m_size.width * m_bytePerPixel;
    
    if (m_bytePerPixel == 4)
    {
        m_imageBuffer.colorFormat = VRT_COLOR_TYPE_ARGB8888;
    }
    else
    {
        m_imageBuffer.colorFormat = VRT_COLOR_TYPE_RGB565;
    }

    loadImage();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As1", SA_stop);
#endif
}

void VcpAsyncImageFrame::onTimer(VfxTimer *source)
{
    loadImage();
}

void VcpAsyncImageFrame::loadImage()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As3", SA_start);
#endif

    gdi_color_format cf;
    if (m_bytePerPixel == 4)
    {
        cf = GDI_COLOR_FORMAT_32;
    }
    else
    {
        cf = GDI_COLOR_FORMAT_16;
    }

    gdi_layer_create_cf_using_outside_memory(
        cf,
        0,
        0,
        m_size.width,
        m_size.height,
        &m_layer,
        m_data,
        m_size.width * m_size.height * 4);

    gdi_layer_set_source_key_nb_concurrent(m_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);

    if (m_imageSrc.getType() == VFX_IMAGE_SRC_TYPE_NULL)
    {

        m_handle = gdi_imgdec_nb_aspect_draw_resized_file_with_flag(
                                         m_layer, 
                                         0, 
                                         0, 
                                         m_size.width,
                                         m_size.height, 
                                         (U8*)m_imagePath.getBuf(), 
                                         VcpAsyncImageFrame_done_callback,
                                         GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT,
                                         m_gdiMode);
    }
    else
    {
        switch (m_imageSrc.getType())
        {
            case VFX_IMAGE_SRC_TYPE_MEM:
                m_handle = gdi_imgdec_nb_aspect_draw_resized_with_flag(
                                         m_layer, 
                                         0, 
                                         0, 
                                         m_size.width,
                                         m_size.height, 
                                         (U8*)m_imageSrc.getMem(), 
                                         VcpAsyncImageFrame_done_callback,
                                         GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT,
                                         m_gdiMode);
                break;
            case VFX_IMAGE_SRC_TYPE_PATH:
                m_handle = gdi_imgdec_nb_aspect_draw_resized_file_with_flag(
                                         m_layer, 
                                         0, 
                                         0, 
                                         m_size.width,
                                         m_size.height, 
                                         (U8*)m_imageSrc.getPath().getBuf(), 
                                         VcpAsyncImageFrame_done_callback,
                                         GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT,
                                         m_gdiMode);
                break;
            default : 
                // unsupported type
                VFX_ASSERT(0);
        }
    }

    if (m_handle == 0)
    {
        gdi_layer_free(m_layer);
        m_layer = GDI_NULL_HANDLE;
        m_timer->setStartDelay(100);
        m_timer->start();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As3", SA_stop);
#endif
}

void VcpAsyncImageFrame::onDeinit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As2", SA_start);
#endif
    VFX_LOG(VFX_INFO, VCP_ASYNC_IMAGE_FRAME_DEINIT, m_handle, m_layer, m_data);
    
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

    VcpAsyncImageFrame * pObject = m_firstObject;
    if (pObject == this)
    {
        m_firstObject = m_nextObject;
    }
    else
    {
        while (true)
        {
            if (pObject->m_nextObject == NULL)
            {
                VFX_ASSERT(false);
                break;
            }

            if (pObject->m_nextObject == this)
            {
                pObject->m_nextObject = m_nextObject;
                m_nextObject = NULL;
                break;
            }
            pObject = pObject->m_nextObject;
        }
    }
    
	if (m_handle != GDI_NULL_HANDLE)
	{
		gdi_imgdec_nb_stop(m_handle);
	}
	if (m_layer != GDI_NULL_HANDLE)
	{
		gdi_layer_free(m_layer);
	}

    
    if (m_data)
    {
        if (m_isAppMem)
        {
            m_freeFunc(m_data, m_userData);
        }
        else
        {
            mmi_frm_asm_free_r(m_gid, m_data);
        }
        m_data = NULL;
    }

    VfxFrame::onDeinit();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("As2", SA_stop);
#endif
}


void VcpAsyncImageFrame::onGdiCallback(GDI_RESULT result, gdi_handle handle)
{
    VcpAsyncImageFrame * pObject = m_firstObject;

    while (pObject != NULL)
    {
        if (pObject->m_handle == handle)
        {
            pObject->onHandleGdiCallback(result);
            break;
        }
        pObject = pObject->m_nextObject;
    }
}


void VcpAsyncImageFrame::onHandleGdiCallback(GDI_RESULT result)
{
    VFX_LOG(VFX_INFO, VCP_ASYNC_IMAGE_FRAME_ERROR, result, m_layer, m_data);
	
	if (m_layer != GDI_NULL_HANDLE)
	{
		gdi_layer_free(m_layer);
		m_layer = GDI_NULL_HANDLE;
	}

    if (result == GDI_SUCCEED)
    {
        setImgContent(VfxImageSrc(m_imageBuffer));
    }
    else if (result == GDI_IMAGE_ERR_DECODE_TIME_OUT)
    {
    }
    else
    {
        // retry?
        // loadImage();
    }
    m_gdiResultCallback.postEmit(result);
}


