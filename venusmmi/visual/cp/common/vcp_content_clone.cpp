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
 *  vcp_cloner.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets.
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

#include "vcp_content_clone.h"
#include "vrt_canvas.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_renderer.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "string.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Class VcpAlertPopup
 *****************************************************************************/

VcpContentClone::VcpContentClone() :
    m_targetFrame(NULL),
    m_notifyFrame(NULL),
    m_filterType(VCP_CONTENT_CLONE_FILTER_TYPE_COPY),
    m_filter(NULL),
    m_outputAlpha(NULL)
    {
    }


void VcpContentClone::onInit()
{
    VfxControl::onInit();    
    setCacheMode(VFX_CACHE_MODE_RESOURCE);

    VFX_OBJ_CREATE(m_notifyFrame, VfxFrame, this);
    VFX_ASSERT(m_notifyFrame);
    m_notifyFrame->setCacheMode(VFX_CACHE_MODE_PREVENT);
}

void VcpContentClone::onDeinit()
{
    // Work around solution, to safty free buffers
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit(); 

    if (m_targetFrame.isValid())
    {
        m_targetFrame->setFilter(NULL);
    }

    VfxControl::onDeinit();    
}

void VcpContentClone::onUpdate()
{
    if(m_targetFrame.get() && m_targetRect != VfxRect(0,0,0,0))
    {   
        // calculate intersection
        m_targetRect.intersectWith(m_targetFrame->getBounds());
        setBounds(VfxRect(0,0, m_targetRect.getWidth(), m_targetRect.getHeight()));

        m_notifyFrame->setBounds(VfxRect(0,0, m_targetRect.getWidth(), m_targetRect.getHeight()));
        // createBuffer


        if (m_outputAlpha)
        {
            setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
        }
        else
        {
            setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
        }
       

        switch (m_filterType)
        {
            case VCP_CONTENT_CLONE_FILTER_TYPE_COPY:
                VFX_OBJ_CREATE(m_filter, copyFilter, this);
                break;
            case VCP_CONTENT_CLONE_FILTER_TYPE_REFLECTION:
                VFX_OBJ_CREATE(m_filter, reflectionFilter, this);           
                break;
            case VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION:
                VFX_OBJ_CREATE(m_filter, gradientReflectionFilter, this);
                break;
            default:
                VFX_ASSERT(0);
        }
        
		m_filter->m_destFrame = this;
        m_filter->m_rect = m_targetRect;
        m_filter->m_outputAlpha = m_outputAlpha;

        m_targetFrame->setFilter(m_filter);

        m_notifyFrame->setPropertyEffectCallback(
            m_targetFrame.get(), 
            framePropertyEffectCallback, 
            NULL,
            0,
            VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
    }
}


VfxBool VcpContentClone::cloneBaseFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
{
    VFX_UNUSED(outBuf);
    VFX_UNUSED(level);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (inBuf.colorFormat == VRT_COLOR_TYPE_RGB565)
    {
        if (m_outputAlpha)
        {
            if (vrt_get_default_alpha_color_format() == VRT_COLOR_TYPE_ARGB8888)
            {
                processRGB565toARGB8888(inBuf);
            }
            else if (vrt_get_default_alpha_color_format() == VRT_COLOR_TYPE_PARGB8888)
            {
                processRGB565toPARGB8888(inBuf);
            }
            else if (vrt_get_default_alpha_color_format() == VRT_COLOR_TYPE_PARGB6666)
            {
                processRGB565toPARGB6666(inBuf);
            }
            else
            {
                VFX_ASSERT(0);
            }
        }
        else
        {
            processRGB565toRGB565(inBuf);
        }
    }
    else if (inBuf.colorFormat == VRT_COLOR_TYPE_ARGB8888)
    {
        if (m_outputAlpha)
        {
            processARGB8888toARGB8888(inBuf);
        }
        else
        {
            // please set outputAplha
            VFX_ASSERT(0);
        }
    }
    else if (inBuf.colorFormat == VRT_COLOR_TYPE_PARGB8888)
    {
        if (m_outputAlpha)
        {
            processPARGB8888toPARGB8888(inBuf);
        }
        else
        {
            // please set outputAplha
            VFX_ASSERT(0);
        }
    }
    else if (inBuf.colorFormat == VRT_COLOR_TYPE_PARGB6666)
    {
        if (m_outputAlpha)
        {
            processPARGB6666toPARGB6666(inBuf);
        }
        else
        {
            // please set outputAplha
            VFX_ASSERT(0);
        }
    }
    else
    {
        VFX_ASSERT(0);
    }
    return VFX_FALSE;
}


void *VcpContentClone::cloneBaseFilter::lockCloneBuffer()
{
    void *buffer = vrt_frame_lock_cache_buffer(m_destFrame->getHandle(), VRT_CACHE_LOCK_MODE_WRITE);
    if (buffer == NULL)
    {
        vrt_frame_unlock_cache_buffer(m_destFrame->getHandle());
    }
    return buffer;
}


void VcpContentClone::cloneBaseFilter::unlockCloneBuffer()
{
    vrt_frame_unlock_cache_buffer(m_destFrame->getHandle());
}


void VcpContentClone::copyFilter::processRGB565toARGB8888(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
    VfxU32 *out_pixel_p = (VfxU32*)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 i, j;

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    
    for (j = height-1 ; j >=0; j--)
    {
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                pixel = (0xFF000000) | (R << 19) + (G << 10) + (B << 3);
            }

            *out_pixel_p = pixel;
            out_pixel_p ++;
            in_pixel_p ++;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::copyFilter::processRGB565toPARGB8888(VfxImageBuffer &inBuf)
{
    processRGB565toARGB8888(inBuf);
}



void VcpContentClone::copyFilter::processRGB565toRGB565(VfxImageBuffer &inBuf)
{
    copyFrameCommon(inBuf);
}


void VcpContentClone::copyFilter::processARGB8888toARGB8888(VfxImageBuffer &inBuf)
{
    copyFrameCommon(inBuf);
}


void VcpContentClone::copyFilter::processPARGB8888toPARGB8888(VfxImageBuffer &inBuf)
{
    copyFrameCommon(inBuf);
}


void VcpContentClone::copyFilter::processRGB565toPARGB6666(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
    VfxU8 *out_pixel_p = (VfxU8*)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 i, j;

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    
    for (j = height-1 ; j >=0; j--)
    {
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                pixel = (0x3F << 18) | (R << 13) + (G << 6) + (B << 1);
            }
           
            out_pixel_p[0] = pixel & 0xFF;
            out_pixel_p[1] = pixel >> 8;
            out_pixel_p[2] = pixel >> 16;            
            
            out_pixel_p +=3;
            
            in_pixel_p ++;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::copyFilter::processPARGB6666toPARGB6666(VfxImageBuffer &inBuf)
{
    copyFrame6666(inBuf);
}


#ifdef __MTK_TARGET__
#pragma arm
#endif


void VcpContentClone::copyFilter::copyFrameCommon(VfxImageBuffer &inBuf)
{   
    VfxS32 bytePerPixel = 2;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }

    if (m_outputAlpha)
    {
        bytePerPixel = 4;
    }

    if (m_rect == VfxRect(0, 0, inBuf.width, inBuf.height))
    {
        memcpy(out_pixel_p, inBuf.ptr, inBuf.width * inBuf.height * bytePerPixel);
    }
    else 
    {   
        VfxS32 pitch_size = inBuf.pitchBytes;
        
        VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
        
        /* offset buffer pointers to the rect origin */
        in_pixel_p += m_rect.getY() * pitch_size + m_rect.getX();
        /* line-by-line copy */
        VfxS32 j;
        VfxS32 width = m_rect.getWidth();
        VfxS32 height = m_rect.getHeight();

        if (width <= 0 || height <= 0)
        {
            return;
        }
        for (j = height - 1; j >= 0; j--)
        {
            memcpy(out_pixel_p, in_pixel_p, width * bytePerPixel);
            in_pixel_p += pitch_size;
            out_pixel_p += width * bytePerPixel;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::copyFilter::copyFrame6666(VfxImageBuffer &inBuf)
{   
    VfxS32 bytePerPixel = 3;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }

    if (m_rect == VfxRect(0, 0, inBuf.width, inBuf.height))
    {
        memcpy(out_pixel_p, inBuf.ptr, inBuf.width * inBuf.height * bytePerPixel);
    }
    else 
    {   
        VfxS32 pitch_size = inBuf.pitchBytes;
        
        VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
        
        /* offset buffer pointers to the rect origin */
        in_pixel_p += m_rect.getY() * pitch_size + m_rect.getX();
        /* line-by-line copy */
        VfxS32 j;
        VfxS32 width = m_rect.getWidth();
        VfxS32 height = m_rect.getHeight();

        if (width <= 0 || height <= 0)
        {
            return;
        }
        for (j = height - 1; j >= 0; j--)
        {
            memcpy(out_pixel_p, in_pixel_p, width * bytePerPixel);
            in_pixel_p += pitch_size;
            out_pixel_p += width * bytePerPixel;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processRGB565toARGB8888(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU32 *out_pixel_p = (VfxU32 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                pixel = (0x3F000000) | (R << 19) + (G << 10) + (B << 3);
            }
           
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processRGB565toPARGB8888(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU32 *out_pixel_p = (VfxU32 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >> (13);
                G = (pixel << 21) >> (28);           
                B = (pixel << 27) >> 29;
                pixel = (0x3F000000) | (R << 19) + (G << 10) + (B << 3);
            }
           
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processRGB565toRGB565(VfxImageBuffer &inBuf)
{
    //VfxU16 maskShift1 = 0x7BEF;
    VfxU16 maskShift2 = 0x39E7;

    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU16 *out_pixel_p = (VfxU16 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            pixel >>= 2;
            pixel &= maskShift2;
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processARGB8888toARGB8888(VfxImageBuffer &inBuf)
{
    VfxS32 pitch_size = inBuf.pitchBytes;
        
    VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();

    if (out_pixel_p == NULL)
    {
        return;
    }

    /* offset buffer pointers to the rect origin */
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + (m_rect.getX() + width) * 4;
    out_pixel_p += width * height * 4 - 4;
    VfxU8 *next_in_pixel_p = in_pixel_p -4;
    /* line-by-line copy */
    VfxS32 i,j;
    VfxU8 alpha;

    for (j = height - 1; j >= 0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        
        for (i = width-1 ; i >= 0; i--)
        {            
            memcpy(out_pixel_p, in_pixel_p, 3);

            alpha = (VfxU8)(*(in_pixel_p+3));
            *(out_pixel_p+3) = alpha >> 2;
            in_pixel_p -=4;
            out_pixel_p -=4;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processPARGB8888toPARGB8888(VfxImageBuffer &inBuf)
{
    //VfxU32 maskShift1 = 0x7F7F7F7F;
    VfxU32 maskShift2 = 0x3F3F3F3F;

    VfxU32 pixel;
    VfxU32 *in_pixel_p = (VfxU32*)inBuf.ptr;
	VfxU32 *out_pixel_p = (VfxU32 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/4;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU32 *next_in_pixel_p = in_pixel_p -1;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            pixel >>= 2;
            pixel &= maskShift2;
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processRGB565toPARGB6666(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height * 3 - 3;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >> (13);
                G = (pixel << 21) >> (28);           
                B = (pixel << 27) >> 29;
                pixel = (0xF << 18) | (R << 13) + (G << 6) + (B << 1);
            }
           
            out_pixel_p[0] = pixel & 0xFF;
            out_pixel_p[1] = pixel >> 8;
            out_pixel_p[2] = pixel >> 16;            
            
            out_pixel_p -=3;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::reflectionFilter::processPARGB6666toPARGB6666(VfxImageBuffer &inBuf)
{
    VfxU32 maskShift2 = 0x3CF3CF;

    VfxU32 pixel;
    VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/3;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += ((m_rect.getY() - 1) * pitch_size + m_rect.getX() + width) * 3;
    out_pixel_p += (width * height -1) * 3;
    VfxU8 *next_in_pixel_p = in_pixel_p - 3;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size * 3;
        in_pixel_p = next_in_pixel_p;
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = in_pixel_p[2] << 16;
            pixel += in_pixel_p[1] << 8;
            pixel += in_pixel_p[0];

            pixel >>= 2;
            pixel &= maskShift2;

            out_pixel_p[0] = pixel & 0xFF;
            out_pixel_p[1] = pixel >> 8;
            out_pixel_p[2] = pixel >> 16;            
            
            out_pixel_p -=3;
            in_pixel_p -=3;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processRGB565toARGB8888(VfxImageBuffer &inBuf)
{
    VfxU32 A,R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU32 *out_pixel_p = (VfxU32 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;
    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        A = (VfxU32)(255 * factor);
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                pixel = (A << 24) | (R << 19) + (G << 10) + (B << 3);
            }
           
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processRGB565toPARGB8888(VfxImageBuffer &inBuf)
{
    VfxU32 A,R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU32 *out_pixel_p = (VfxU32 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;
    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 
    VfxS32 AA;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        A = (VfxU32)(255 * factor);
        AA = (VfxS32)(factor * 255 + 0.5);
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {    
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                //R *= factor;
                //G *= factor;
                //B *= factor;
                R = (((R * AA) + 128) * 257) >> 16;
                G = (((G * AA) + 128) * 257) >> 16;
                B = (((B * AA) + 128) * 257) >> 16;
                pixel = (A << 24) | (R << 19) + (G << 10) + (B << 3);
            }
           
            *out_pixel_p = pixel;
            
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}



void VcpContentClone::gradientReflectionFilter::processRGB565toRGB565(VfxImageBuffer &inBuf)
{
    VfxU32 R,G,B;
    
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
    VfxU16 *out_pixel_p = (VfxU16 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    //VfxS32 X = m_rect.getX();
    //VfxS32 Y = m_rect.getY();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += width * height -1;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;
    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 
    VfxS32 AA;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        AA = (VfxS32)(factor * 255 + 0.5);
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0x1F;
            }
            else
            {
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;

                //R *= factor;
                //G *= factor;
                //B *= factor;
                R = (((R * AA) + 128) * 257) >> 16;
                G = (((G * AA) + 128) * 257) >> 16;
                B = (((B * AA) + 128) * 257) >> 16;

                pixel = (R << 11) + (G << 5) + B;
            }
           
            *out_pixel_p = pixel;
            out_pixel_p --;
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processARGB8888toARGB8888(VfxImageBuffer &inBuf)
{
    VfxS32 pitch_size = inBuf.pitchBytes;
        
    VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
    VfxU8 *out_pixel_p = (VfxU8*)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }
    
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    /* offset buffer pointers to the rect origin */
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + (m_rect.getX() + width) * 4;
    out_pixel_p += width * height * 4 - 4;
    VfxU8 *next_in_pixel_p = in_pixel_p -4;
    /* line-by-line copy */
    VfxS32 i,j;
    VfxU8 alpha;

    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 

    for (j = height - 1; j >= 0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        for (i = width-1 ; i >= 0; i--)
        {            
            memcpy(out_pixel_p, in_pixel_p, 3);

            alpha = (VfxU8)(*(in_pixel_p+3));
            *(out_pixel_p+3) = (VfxU8)(alpha * factor);
            in_pixel_p -=4;
            out_pixel_p -=4;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processPARGB8888toPARGB8888(VfxImageBuffer &inBuf)
{
    VfxS32 pitch_size = inBuf.pitchBytes;
        
    VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
    VfxU8 *out_pixel_p = (VfxU8*)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }
    
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    /* offset buffer pointers to the rect origin */
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + (m_rect.getX() + width) * 4;
    out_pixel_p += width * height * 4 - 4;
    VfxU8 *next_in_pixel_p = in_pixel_p -4;
    /* line-by-line copy */
    VfxS32 i,j;

    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 
    VfxS32 AA;
    VfxU32 temp;
    for (j = height - 1; j >= 0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        AA = (VfxS32)(factor * 255 + 0.5);
        for (i = width-1 ; i >= 0; i--)
        {            
            //*(out_pixel_p) = (VfxU8)((*(in_pixel_p)) * factor);
            //*(out_pixel_p+1) = (VfxU8)((*(in_pixel_p+1)) * factor);
            //*(out_pixel_p+2) = (VfxU8)((*(in_pixel_p+2)) * factor);
            //*(out_pixel_p+3) = (VfxU8)((*(in_pixel_p+3)) * factor);
            temp = *(in_pixel_p);
            *(out_pixel_p) = (VfxU8) (((temp * AA + 128) * 257) >> 16);
            temp = *(in_pixel_p+1);
            *(out_pixel_p+1) = (VfxU8) (((temp * AA + 128) * 257) >> 16);
            temp = *(in_pixel_p+2);
            *(out_pixel_p+2) = (VfxU8) (((temp * AA + 128) * 257) >> 16);
            temp = *(in_pixel_p+3);
            *(out_pixel_p+3) = (VfxU8) (((temp * AA + 128) * 257) >> 16);
            
            in_pixel_p -=4;
            out_pixel_p -=4;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processRGB565toPARGB6666(VfxImageBuffer &inBuf)
{
    VfxU32 A,R,G,B;
    VfxU32 pixel;
    VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
	VfxU8 *out_pixel_p = (VfxU8 *)lockCloneBuffer();
    VfxS32 i, j;

    if (out_pixel_p == NULL)
    {
        return;
    }

    VfxS32 pitch_size = inBuf.pitchBytes/2;
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + m_rect.getX() + width;
    out_pixel_p += (width * height -1) * 3;
    VfxU16 *next_in_pixel_p = in_pixel_p -1;
    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 
    VfxS32 AA;

    for (j = height-1 ; j >=0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        A = (VfxU32)(255 * factor);
        AA = (VfxS32)(factor * 255 + 0.5);
        for (i = width-1 ; i >= 0; i--)
        {
            pixel = (VfxU32)(*(in_pixel_p));

            if (pixel == 0x1F)
            {
                pixel = 0;
            }
            else
            {    
                R = pixel >>11;
                G = (pixel << 21) >> 26;           
                B = (pixel << 27) >> 27;
                R = (((R * AA) + 128) * 257) >> 16;
                G = (((G * AA) + 128) * 257) >> 16;
                B = (((B * AA) + 128) * 257) >> 16;
                pixel = (A << 18) | (R << 13) + (G << 6) + (B << 1);
            }
            out_pixel_p[0] = pixel & 0xFF;
            out_pixel_p[1] = pixel >> 8;
            out_pixel_p[2] = pixel >> 16;            
            
            out_pixel_p -=3;
            
            in_pixel_p --;
        }
    }

    unlockCloneBuffer();
}


void VcpContentClone::gradientReflectionFilter::processPARGB6666toPARGB6666(VfxImageBuffer &inBuf)
{
    VfxS32 pitch_size = inBuf.pitchBytes;

    VfxU32 pixel, pixelOut;
    VfxU8 A,R,G,B;
    VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
    VfxU8 *out_pixel_p = (VfxU8*)lockCloneBuffer();

    if (out_pixel_p == NULL)
    {
        return;
    }
    
    VfxS32 width = m_rect.getWidth();
    VfxS32 height = m_rect.getHeight();
    /* offset buffer pointers to the rect origin */
    in_pixel_p += (m_rect.getY() - 1) * pitch_size + (m_rect.getX() + width) * 3;
    out_pixel_p += width * height * 3 - 3;
    VfxU8 *next_in_pixel_p = in_pixel_p -3;
    /* line-by-line copy */
    VfxS32 i,j;

    VfxFloat factor = 0;
    VfxFloat factorInc = 0.5f / height; 
    VfxS32 AA;
    
    for (j = height - 1; j >= 0; j--)
    {
        next_in_pixel_p += pitch_size;
        in_pixel_p = next_in_pixel_p;
        factor += factorInc;
        AA = (VfxS32)(factor * 255 + 0.5);
        for (i = width-1 ; i >= 0; i--)
        {   
            pixel = in_pixel_p[2] << 16;
            pixel += in_pixel_p[1] << 8;
            pixel += in_pixel_p[0];

            A = pixel >> (18);
            R = (pixel << 14) >> (26);
            G = (pixel << 20) >> (26);           
            B = (pixel << 26) >> 26;
  
            A = ((A * AA + 128) * 257) >> 16;
            R = ((R * AA + 128) * 257) >> 16;
            G = ((G * AA + 128) * 257) >> 16;  
            B = ((B * AA + 128) * 257) >> 16;
            
            pixelOut = (A << 18) + (R << 12) + (G << 6) + B; 
            
            out_pixel_p[0] = pixelOut & 0xFF;
            out_pixel_p[1] = pixelOut >> 8;
            out_pixel_p[2] = pixelOut >> 16;            
            
            out_pixel_p -=3;
            in_pixel_p -=3;
            
        }
    }

    unlockCloneBuffer();
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */
