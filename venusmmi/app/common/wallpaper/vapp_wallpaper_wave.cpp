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
 *  vapp_wallpaper_wave.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wave wallpaper class
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

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_wave.h"
//#include "HomeScreen/vadp_v2p_hs.h"
#include "mmi_rp_app_venus_wallpaper_wave_def.h"

/* RHR start */
#include "vfx_cpp_base.h"   
#include "vfx_object.h"    
#include "vfx_sys_memory.h"    
#include "vapp_wallpaper.h"  
#include "vfx_class_info.h"   
#include "vfx_datatype.h"   
#include "vfx_primitive_frame.h"  
#include "vapp_hs_def.h"    
#include "vfx_basic_type.h"    
#include "vrt_datatype.h"  
#include "vfx_animation.h"   
#include "vrt_canvas.h"    
#include "vfx_input_event.h"  
#include "vfx_frame.h"     
#include "vfx_owner_draw.h"  
#include "vfx_image_src.h"
/* RHR end */


#ifdef __cplusplus
extern "C"
{
#endif

#include "gdi_primitive.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Home screen UI componet: wave wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Wave Wallpaper", VappWallpaperWave, VappWallpaper);

VappWallpaperWave::VappWallpaperWave()
{
}

void VappWallpaperWave::onCreateView()
{
    this->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
    m_imgBg->setIsOpaque(VFX_TRUE);

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
#if defined(__MMI_MAINLCD_240X320__)
    VfxSize imgSize(320,320);
#elif defined(__MMI_MAINLCD_240X400__)
    VfxSize imgSize(400,400);
#elif defined(__MMI_MAINLCD_320X480__)
    VfxSize imgSize(480,480);
#elif defined(__MMI_MAINLCD_480X800__)
    VfxSize imgSize(800,800);
#endif
    m_imgBg->setSize(imgSize);
    m_imgBg->setAutoAnimate(VFX_TRUE);
#else
    m_imgBg->setSize(this->getSize());
#endif

    VFX_OBJ_CREATE(m_imgFg, VfxImageFrame, this);

    m_imgFg->setResId(VAPP_WALLPAPER_IMG_REFLECTEDFG);

    m_imgFg->setAnchor(0.0, 1.0);
    m_imgFg->setPos(0, this->getSize().height);
    m_imgFg->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_draw, VappWaveDraw, this);
    m_imgBg->setOwnerDraw(m_draw);
    m_imgBg->setPropertyEffectCallback(m_imgBg, m_draw->onUpdate, &m_draw, sizeof(VappWaveDraw*), VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

    // start filter timeline
    VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
    m_timeline->setFromValue(0.0f);
    m_timeline->setToValue(1.0f);
    m_timeline->setDurationTime(2000);
    m_timeline->setAutoReversed(VFX_FALSE);
    m_timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_timeline->setTarget(m_imgBg);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_timeline->start();
}


void VappWallpaperWave::onReleaseView()
{
    m_imgBg->setOwnerDraw(NULL);
    VFX_OBJ_CLOSE(m_timeline);
    VFX_OBJ_CLOSE(m_draw);
    VFX_OBJ_CLOSE(m_imgBg);
    VFX_OBJ_CLOSE(m_imgFg);
}


MMI_IMG_ID VappWallpaperWave::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_WAVE_THUMBNAIL;
}

void VappWallpaperWave::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_WAVE);
    return;
}

void VappWallpaperWave::onSuspend()
{
    m_timeline->stop();
    m_draw->m_isSuspend = VFX_TRUE;
}

void VappWallpaperWave::onResume()
{
    m_timeline->start();
    m_draw->m_isSuspend = VFX_FALSE;

}

VfxBool VappWallpaperWave::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            return VFX_TRUE;
        }
    }
    return VFX_TRUE;

}

void VappWallpaperWave::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    if(m_imgBg)
    {
        VfxSize size = m_imgBg->getBounds().size;
        VfxPoint pos = m_imgBg->getPos();
        VfxS32 b = size.width - getScreenSize().width;
        if (b > 0)
        {
            // calculate the bounds of the wallpaper
            const VfxS32 m = vfxMin(b, vfxMax((VfxS32)(b * curPos), (VfxS32)0));

            // Change wallpaper position
            pos.x = -m;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

            m_imgBg->setPos(pos);
            m_imgFg->setPos(pos.x, m_imgFg->getPos().y);

            VfxAutoAnimate::commit();
        }
    }
#endif
}


/*****************************************************************************
 * Class VappWaveDraw
 *****************************************************************************/
VappWaveDraw::VappWaveDraw() : m_debug(0), m_level(0), m_isSuspend(VFX_FALSE)
{
}

void VappWaveDraw::onInit()
{
    VfxOwnerDraw::onInit();
    setResourceFromResId('WAV1', VAPP_WALLPAPER_IMG_REFLECTED);
}


vrt_render_dirty_type_enum VappWaveDraw::onUpdate(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    VappWaveDraw *draw = *(VappWaveDraw **) user_data;
    if(draw->m_isSuspend)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    draw->m_level = target_frame->filter_timing;
    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}
 

void VappWaveDraw::drawReflection(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    VfxImageBuffer imgBuf;
    VfxS32 scrn_height = dstBuffer.height;
    VfxS32 halfHeight;

    getResource('WAV1', imgBuf);
    VFX_ASSERT(imgBuf.ptr != NULL);

#if defined(__MMI_MAINLCD_240X320__)
    halfHeight = 193;
#elif defined(__MMI_MAINLCD_240X400__)
    halfHeight = 215;
#elif defined(__MMI_MAINLCD_320X480__)
    halfHeight = 261;
#elif defined(__MMI_MAINLCD_480X800__)
     halfHeight = 453;
 #endif

    // memory copy to draw background
    gdi_img_buf_struct dst;
    dst.color_format = transformVRTColorFormatToGDIColorFormat(dstBuffer.colorFormat);
    dst.ptr = dstBuffer.ptr;
    dst.pitch_bytes = dstBuffer.pitchBytes;
    gdi_img_buf_struct src;
    src.color_format = transformVRTColorFormatToGDIColorFormat(imgBuf.colorFormat);
    src.ptr = imgBuf.ptr;
    src.pitch_bytes = imgBuf.pitchBytes;

    // used to clip rectangle
    VfxPoint dstStartPoint;
    VfxPoint dstEndPoint;
    dstStartPoint.x = dstRect.getX();
    dstStartPoint.y = dstRect.getY();
    dstEndPoint.x = dstRect.getMaxX()+1;
    dstEndPoint.y = dstRect.getMaxY()+1;

    VfxPoint srcStartPoint;
    VfxPoint srcEndPoint;
    srcStartPoint.x = srcRect.getX();
    srcStartPoint.y = srcRect.getY();
    srcEndPoint.x = srcRect.getMaxX()+1;
    srcEndPoint.y = srcRect.getMaxY()+1;


    VfxU32 dstWidth = dstRect.getWidth();
    VfxU32 dstHeight = dstRect.getHeight();

    /*
     * copy upper half picture
     */
    if(srcStartPoint.y <= halfHeight && srcEndPoint.y <= halfHeight)
    {
        dst.ptr = dst.ptr + dstStartPoint.y*dst.pitch_bytes + dstStartPoint.x*sizeof(VfxU16);
        src.ptr = src.ptr + srcStartPoint.y*src.pitch_bytes + srcStartPoint.x*sizeof(VfxU16);
        gdi_img_buf_copy(&dst, &src, dstWidth, dstEndPoint.y-dstStartPoint.y);
        return;
    }

    VfxS32 dispy        = 0;
    VfxU32 i;   
    
    if(srcStartPoint.y <= halfHeight && srcEndPoint.y > halfHeight)
    {
        dst.ptr = dst.ptr + dstStartPoint.y*dst.pitch_bytes + dstStartPoint.x*sizeof(VfxU16);
        src.ptr = src.ptr + srcStartPoint.y*src.pitch_bytes + srcStartPoint.x*sizeof(VfxU16);
        gdi_img_buf_copy(&dst, &src, dstWidth, halfHeight-srcStartPoint.y);

        dst.ptr = dst.ptr + (halfHeight-srcStartPoint.y)*dst.pitch_bytes;
        src.ptr = src.ptr + (halfHeight-srcStartPoint.y)*src.pitch_bytes;

        /*
         * draw lake reflection
         */
        VfxFloat p1 = 2 * VFX_PI * m_level;

        for (i = halfHeight; i < dstHeight + srcStartPoint.y; i++)
        {

            // shift y
            dispy = (halfHeight/14.0) * ((i-halfHeight)+28.0)                       \
                    * vfxSin(((halfHeight/14.0)*(VfxFloat)(halfHeight - (i-halfHeight)))        \
                    /((i-halfHeight) + 1.0) + p1)/(VfxFloat)halfHeight;

    //      if(m_debug)
    //      {
    //          VFX_TRACE(("[VappHsWaveFilter] onProcess[dispy == %d]\n", dispy));
    //      }
            if( ((i-halfHeight)+dispy <= 0) || ((i+dispy) >= (scrn_height)))
            {
                dispy = -dispy;
            }
            src.ptr = src.ptr + dispy * src.pitch_bytes;
            gdi_img_buf_copy(&dst, &src, dstWidth, 1);
            src.ptr = src.ptr - dispy * src.pitch_bytes;

            src.ptr = src.ptr + src.pitch_bytes;
            dst.ptr = dst.ptr + dst.pitch_bytes;
        }
        return;
    }

    if(srcStartPoint.y > halfHeight && srcEndPoint.y > halfHeight)
    {
        dst.ptr = dst.ptr + dstStartPoint.y*dst.pitch_bytes + dstStartPoint.x*sizeof(VfxU16);
        src.ptr = src.ptr + srcStartPoint.y*src.pitch_bytes + srcStartPoint.x*sizeof(VfxU16);

        VfxFloat p1 = 2 * VFX_PI * m_level;

        for (i = dstStartPoint.y; i < dstEndPoint.y; i++)
        {

            // shift y
            dispy = (halfHeight/14.0) * ((i-halfHeight)+28.0)                       \
                    * vfxSin(((halfHeight/14.0)*(VfxFloat)(halfHeight - (i-halfHeight)))        \
                    /((i-halfHeight) + 1.0) + p1)/(VfxFloat)halfHeight;

    //      if(m_debug)
    //      {
    //          VFX_TRACE(("[VappHsWaveFilter] onProcess[dispy == %d]\n", dispy));
    //      }
            if( ((i-halfHeight)+dispy <= 0) || ((i+dispy) >= (scrn_height)))
            {
                dispy = -dispy;
            }
            src.ptr = src.ptr + dispy * src.pitch_bytes;
            gdi_img_buf_copy(&dst, &src, dstWidth, 1);
            src.ptr = src.ptr - dispy * src.pitch_bytes;

            src.ptr = src.ptr + src.pitch_bytes;
            dst.ptr = dst.ptr + dst.pitch_bytes;
        }
        return;
    }    
}

void VappWaveDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    VFX_DEV_ASSERT(dstRect.getWidth() == srcRect.getWidth());
    VFX_DEV_ASSERT(dstRect.getHeight() == srcRect.getHeight());
    drawReflection(dstBuffer, dstRect, srcRect);
}


gdi_img_buf_color_format_enum VappWaveDraw::transformVRTColorFormatToGDIColorFormat(VfxColorTypeEnum vrtColorFormat)
{
    switch(vrtColorFormat)
    {
        case VRT_COLOR_TYPE_RGB565:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB565;
            
        case VRT_COLOR_TYPE_RGB888:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB888;
            
        case VRT_COLOR_TYPE_ARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
            
        case VRT_COLOR_TYPE_PARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;
    }

    // default
    return GDI_IMG_BUF_COLOR_FORMAT_RGB565;
}

#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__ */

