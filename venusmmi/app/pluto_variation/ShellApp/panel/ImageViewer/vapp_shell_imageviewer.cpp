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
 *  vapp_shell_imageviewer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell Image Viewer Panel
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
#include "vapp_shell_imageviewer.h"
#include "mmi_rp_app_shellapp_base_def.h"
#include "mmi_rp_app_venus_shell_iv_def.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_filemanager_def.h"
#endif
#include "mmi_rp_srv_phnset_onoff_def.h"
#if !defined(__COSMOS_MMI__)
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "trc/vadp_app_trc.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "FileMgrSrvGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "MediaCacheSrvGprot.h"
#include "kal_trace.h"
#include "mmi_rp_file_type_def.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "CustMenuRes.h"
#ifdef __cplusplus
}
#endif
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_auto_animate.h"
#include "vadp_shell_imageviewer.h"
#include "vfx_system.h"
#include "vfx_image_src.h"
#include "vfx_renderer.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_signal.h"
#include "vcp_wheel_menu.h"
#include "vrt_system.h"
#include "vcp_frame_effect.h"
#include "vcp_frame_effect_type.h"
#include "vapp_shell_panel.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vcp_segment_button.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vfx_top_level.h"
#include "vcp_popup.h"
#include "vcp_waiting_icon.h"

/*****************************************************************************
 * VappShellIV Implementation
 *****************************************************************************/
#ifdef __VUI_SHELL_IV_FPE_TRANSFORM_AFFINE__
/*
AFFINE:
    {Sx,    0, Tx,   0, Sy,    Ty,         0, 0, 1.0f}
 */
static const vrt_matrix3x3_struct g_shellIVTransformArray[8] =
{
    {0.30f, 0, 0,    0, 0.30f,  300.0f,    0, 0, 1.0f}, //-3
    {0.45f, 0, 0,    0, 0.45f,  200.0f,    0, 0, 1.0f}, //-2
    {0.60f, 0, 0,    0, 0.60f,  100.0f,    0, 0, 1.0f}, //-1
    {1.00f, 0, 0,    0, 1.0f,   0,         0, 0, 1.0f},//1
    {0.60f, 0, 0,    0, 0.60f, -100.0f,    0, 0, 1.0f}, // 1
    {0.45f, 0, 0,    0, 0.45f, -200.0f,    0, 0, 1.0f}, // 2
    {0.30f, 0, 0,    0, 0.30f, -300.0f,    0, 0, 1.0f}, // 3
    {0.20f, 0, 0,    0, 0.20f, -400.0f,    0, 0, 1.0f}  // 4
};
#else
static const vrt_matrix3x3_struct g_shellIVTransformArray[8] =
{
    {0.51717f,  0.11239f, -0.00008f,    -0.15534f,  0.53883f, -0.00006f,    -14.00000f,   312.00000f,  1.00000f}, //-3
    {0.53976f, -0.09029f,  0.00012f,     0.13353f,  0.48235f, -0.00021f,    -10.00000f,   235.00000f,  1.00000f}, //-2
    {0.77253f,  0.14300f, -0.00005f,    -0.15707f,  0.72928f, -0.00001f,    -56.00000f,   101.00000f,  1.00000f}, //-1
    {1.0f,      0,         0,            0,         1.0f,      0,            0,           0,           1.0f},//1
    {0.95262f, -0.20283f,  0.00010f,     0.20760f,  0.86347f, -0.00004f,     146.00000f, -52.00000f,   1.00000f}, // 1
    {0.63000f, -0.22639f,  0.00004f,     0.22708f,  0.62832f, -0.00005f,     165.00000f, -145.00000f,  1.00000f}, // 2
    {0.58645f, -0.11764f,  0.00005f,     0.12499f,  0.54077f, -0.00008f,     317.00000f, -200.00000f,  1.00000f}, // 3
    {0.60153f, -0.13789f,  0.00016f,     0.09723f,  0.47313f, -0.00003f,     380.00000f, -219.00000f,  1.00000f}  // 4
};
#endif


VfxU8 VappShellIVPanel::m_storage = 0;

/*****************************************************************************
 * Class VappShellIVCell
 *****************************************************************************/
VappShellIVCell::VappShellIVCell(VfxS32 index) :
    m_index(index),
    m_state(STATE_EXIT),
    m_width(0),
    m_height(0),
    m_imageWidth(0),
    m_imageHeight(0),
    m_isHighlight(VFX_FALSE),
    m_imageBuf(NULL),
    m_picFrame(NULL),
    m_border(NULL),
    m_timer(NULL)
{

}


VappShellIVCell::~VappShellIVCell()
{
    m_index = 0;
    m_state = STATE_EXIT;
    m_imageBuf = NULL;
}


void VappShellIVCell::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_picFrame, VfxFrame, this);
    VFX_OBJ_CREATE(m_border, VfxFrame, this);

    setOpacity(1);
#ifdef __VUI_SHELL_IV_ANTI_ALIAS__
    setQuality(VFX_RENDER_QUALITY_HIGH);
#endif
    setIsCached(VFX_TRUE);
    m_border->setAnchor(0.5f, 0.5f);
    m_border->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_picFrame->setIsOpaque(VFX_TRUE);
    m_picFrame->setAnchor(0.5f, 0.5f);
#ifndef __VUI_SHELL_IV_ANTI_ALIAS__
    setIsOpaque(VFX_TRUE);
#endif
    /*
     * If define anti-alias, the operation will become 32 bits from 16 bits.
     * The frame rate will degrade too much. But the frame quality will be greate.
     */
}


void VappShellIVCell::onDeinit()
{
    if (m_timer)
        m_timer->stop();

    m_state = STATE_EXIT;

    VfxControl::onDeinit();
}


void VappShellIVCell::onHightLight()
{
    m_isHighlight = VFX_TRUE;
    bringToFront();
}


void VappShellIVCell::onDeHightLight()
{
    m_isHighlight = VFX_FALSE;
}


void VappShellIVCell::updatePos(const VfxRect& r, VfxBool animation)
{
    setAutoAnimate(animation);
    setPos(VfxPoint(r.getMinX(), r.getMinY()));

    m_width = r.getWidth();
    m_height = r.getHeight();

    setBounds(VfxRect(0, 0, m_width, m_height));

    m_picFrame->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_picFrame->setSize(m_width, m_height);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_picFrame->setBgColor(VFX_COLOR_TRANSPARENT);
    VfxAutoAnimate::commit();
}


VfxBool VappShellIVCell::updateImage(VfxS32 type)
{
    srv_mediacache_image_source_enum source;
    VfxS32 error_code;

    if (m_state == STATE_IMAGE)
        return VFX_TRUE;

    /* Call MediaLib to decode image */
    if (type == DATA_TYPE_MEMORY)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE;
    }
    else if (type == DATA_TYPE_DB)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
    }
    else if (type == DATA_TYPE_FILE)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE;
    }

    if (type == DATA_TYPE_MEMORY || type == DATA_TYPE_DB || type == DATA_TYPE_FILE)
    {
    #if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        error_code = vadp_shell_imgviewer_cache_srv_get_lock_image_buffer(m_index, source, &m_imageBuf);

    #if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        if (error_code == SRV_MEDIACACHE_OK)
        {
            setImageBuffer(m_imageBuf);
        }
        else if (error_code == SRV_MEDIACACHE_ERR_NOT_SUPPORT)
        {
            setErrorIcon();
        }
        else if (error_code == VADP_SHELLIV_DRM_LOCKED)
        {
            setDRMIcon();
        }
        else if (m_state != STATE_DEFAULT)
        {
            setDefaultIcon();
        }

        VFX_LOG(VFX_INFO, VAPP_SHELLIV_CELL_UPDATE_IMAGE, error_code);
    }
    else
    {
        /* type == DATE_TYPE_DEFAULT */
        setDefaultIcon();
    }

    return VFX_TRUE;
}


void VappShellIVCell::closeImage()
{
    if (m_state == STATE_IMAGE && m_imageBuf)
    {
        vadp_shell_imgviewer_cache_srv_free_image_buffer((void*)m_imageBuf);
    }
}


void VappShellIVCell::setDefaultIcon()
{
    m_state = STATE_DEFAULT;

    m_border->setAnchor(0.5f, 0.5f);
    m_border->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_border->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2*VappShellIVMenu::BORDER_PIXELS,
        VappShellIVMenu::DEFAULT_HEIGHT + 2*VappShellIVMenu::BORDER_PIXELS);
#ifdef __VUI_SHELL_IV_ANTI_ALIAS__
    m_border->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_BORDER));
    m_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else
    m_border->setBorder(VFX_COLOR_WHITE, VappShellIVMenu::BORDER_PIXELS);
#endif
    m_picFrame->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1) ,
        VappShellIVMenu::DEFAULT_HEIGHT + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1));
    m_picFrame->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_DEFAULT_ICON));
    m_picFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_picFrame->setBgColor(VFX_COLOR_SILVER);
    VfxAutoAnimate::commit();
}


void VappShellIVCell::setErrorIcon()
{
    m_state = STATE_IMAGE;

    m_border->setAnchor(0.5f, 0.5f);
    m_border->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_border->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2*VappShellIVMenu::BORDER_PIXELS,
        VappShellIVMenu::DEFAULT_HEIGHT + 2*VappShellIVMenu::BORDER_PIXELS);
#ifdef __VUI_SHELL_IV_ANTI_ALIAS__
    m_border->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_BORDER));
    m_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else
    m_border->setBorder(VFX_COLOR_WHITE, VappShellIVMenu::BORDER_PIXELS);
#endif
    m_picFrame->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1),
        VappShellIVMenu::DEFAULT_HEIGHT + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1));
    m_picFrame->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_UNSUPPORT_ICON));
    m_picFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_picFrame->setBgColor(VFX_COLOR_SILVER);
    VfxAutoAnimate::commit();
}

void VappShellIVCell::setDRMIcon()
{
    m_state = STATE_IMAGE;

    m_border->setAnchor(0.5f, 0.5f);
    m_border->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_border->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2*VappShellIVMenu::BORDER_PIXELS,
        VappShellIVMenu::DEFAULT_HEIGHT + 2*VappShellIVMenu::BORDER_PIXELS);
#ifdef __VUI_SHELL_IV_ANTI_ALIAS__
    m_border->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_BORDER));
    m_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else
    m_border->setBorder(VFX_COLOR_WHITE, VappShellIVMenu::BORDER_PIXELS);
#endif
    m_picFrame->setSize(
        VappShellIVMenu::DEFAULT_WIDTH + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1),
        VappShellIVMenu::DEFAULT_HEIGHT + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1));
    m_picFrame->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_DRM_LOCKED_ICON));
    m_picFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_picFrame->setBgColor(VFX_COLOR_SILVER);
    VfxAutoAnimate::commit();
}


void VappShellIVCell::setImageBuffer(void *buffer_p)
{
    VfxS32 ret;
    VfxS32 prev_state = m_state;

    m_imageBuf = buffer_p;

#define BORDER_THRESHOLD (0.4f)

    ret = vadp_shell_imgviewer_cache_srv_get_image_info(m_index, &m_imageWidth, &m_imageHeight);

    if (ret >= SRV_MEDIACACHE_OK)
    {
        m_state = STATE_IMAGE;

        VFX_LOG(VFX_INFO, VAPP_SHELLIV_CELL_SET_IMAGEBUFFER, m_index, m_imageWidth, m_imageHeight);

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
        m_timer->setDuration(0);
        m_timer->m_signalTick.connect(this, &VappShellIVCell::onSetImageTimerTick);

        m_border->setAutoAnimate(VFX_TRUE);
        m_picFrame->setAutoAnimate(VFX_TRUE);

        VfxS32 width;
        VfxS32 height;
        if (VfxFloat(m_imageWidth * m_imageHeight)/VfxFloat(m_width * m_height) > BORDER_THRESHOLD)
        {
            width = m_imageWidth;
            height = m_imageHeight;
        }
        else
        {
            if (m_imageWidth >= m_imageHeight)
            {
                width = (VappShellIVMenu::DEFAULT_WIDTH <= VappShellIVMenu::IMG_MAX_WIDTH) ? VappShellIVMenu::DEFAULT_WIDTH : VappShellIVMenu::IMG_MAX_WIDTH;
                height = (VappShellIVMenu::DEFAULT_HEIGHT <= VappShellIVMenu::IMG_MAX_HEIGHT) ? VappShellIVMenu::DEFAULT_HEIGHT : VappShellIVMenu::IMG_MAX_HEIGHT;
            }
            else
            {
                width = (VappShellIVMenu::DEFAULT_HEIGHT <= VappShellIVMenu::IMG_MAX_WIDTH) ? VappShellIVMenu::DEFAULT_HEIGHT : VappShellIVMenu::IMG_MAX_WIDTH;
                height = (VappShellIVMenu::DEFAULT_WIDTH <= VappShellIVMenu::IMG_MAX_HEIGHT) ? VappShellIVMenu::DEFAULT_WIDTH : VappShellIVMenu::IMG_MAX_HEIGHT;
            }
        }

        m_border->setAnchor(0.5f, 0.5f);
        m_border->setPos(getBounds().getMidX(), getBounds().getMidY());
            m_border->setSize(
                width + 2*VappShellIVMenu::BORDER_PIXELS,
                height + 2*VappShellIVMenu::BORDER_PIXELS);
        #ifdef __VUI_SHELL_IV_ANTI_ALIAS__
            m_border->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_IV_BORDER));
            m_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        #else
            m_border->setBorder(VFX_COLOR_WHITE, VappShellIVMenu::BORDER_PIXELS);
        #endif
            m_picFrame->setSize(
                width + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1),
                height + 2 * ((VappShellIVMenu::BORDER_PIXELS >> 1) - 1));

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_picFrame->setBgColor(VFX_COLOR_SILVER);
        VfxAutoAnimate::commit();

        if (prev_state == STATE_EXIT)
        {
            onSetImageTimerTick(NULL);
        }
        else
        {
            m_timer->start();
        }
    }

}


void VappShellIVCell::onSetImageTimerTick(VfxTimer *source)
{
#define BORDER_THRESHOLD (0.4f)

    m_timer->stop();
    VFX_OBJ_CLOSE(m_timer);

    VfxImageBuffer imageBuf;

    imageBuf.ptr = (VfxU8*)m_imageBuf;
    imageBuf.pitchBytes = m_imageWidth * 2;
    imageBuf.width = m_imageWidth;
    imageBuf.height = m_imageHeight;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    if (VfxFloat(m_imageWidth * m_imageHeight)/VfxFloat(m_width * m_height) > BORDER_THRESHOLD)
    {
        m_picFrame->setBgColor(VFX_COLOR_TRANSPARENT);
    }
    else
    {
        m_picFrame->setBgColor(VFX_COLOR_BLACK);
    }
    VfxAutoAnimate::commit();

    m_picFrame->setImgContent(VfxImageSrc(imageBuf));
    m_picFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
}


VfxBool VappShellIVCell::getIsBorderContainPoint(const VfxPoint &point) const
{
    VfxPoint borderPos;
    const VfxSize& borderSize = m_border->getSize();


    /* Because cell anchor is (0.5f, 0.5f) */
    borderPos.x = getPos().x - (m_border->getSize().width)/2;
    borderPos.y = getPos().y - (m_border->getSize().height)/2;

    if (point.x >= borderPos.x && point.x <= borderPos.x + borderSize.width &&
        point.y >= borderPos.y && point.y <= borderPos.y + borderSize.height)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;

}


VfxRect VappShellIVCell::getBorderRect() const
{
    VfxPoint borderPos;
    VfxRect rect;

    /* Because cell anchor is (0.5f, 0.5f) */
    borderPos.x = getPos().x - (m_border->getSize().width)/2;
    borderPos.y = getPos().y - (m_border->getSize().height)/2;

    rect.origin = borderPos;
    rect.size.width = m_border->getSize().width;
    rect.size.height = m_border->getSize().height;

    return rect;
}


void VappShellIVCell::stopSetImageTimer()
{
    if (m_timer)
        m_timer->stop();
}


/*****************************************************************************
 * Class VappShellIVMenu
 *****************************************************************************/
void VappShellIVMenu::onInit()
{
    VcpWheelMenu::onInit();

    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;

    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
    m_lcdWidth = mainScreenSize.width;
    m_lcdHeight = mainScreenSize.height;

    m_behindCount = CELL_ITEM_AHEAD_COUNT;
    m_aheadCount = CELL_ITEM_BEHIND_COUNT;
    setIsZSortChild(VFX_TRUE);

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(100);
    m_timer->setDuration(100);
    m_timer->m_signalTick.connect(this, &VappShellIVMenu::onTimerTick);

    VFX_OBJ_CREATE(m_delAnimateTimer, VfxTimer, this);
    m_delAnimateTimer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_delAnimateTimer->setDuration(0);
    m_delAnimateTimer->m_signalTick.connect(this, &VappShellIVMenu::onDelTimerTick);

    m_isDragging = VFX_FALSE;
    m_isDeleting = VFX_FALSE;

    VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);

    m_removedFrame = NULL;
}


void VappShellIVMenu::onDeinit()
{
    m_timer->stop();
    VcpWheelMenu::onDeinit();
}


void VappShellIVMenu::setCount(VfxS32 count)
{
    m_count = count;
}


VfxS32 VappShellIVMenu::getCount()
{
    return m_count;
}


VcpWheelMenuFrameEffectCBFuncPtr VappShellIVMenu::getFrameEffectCB()
{
    return &VappShellIVMenu::FrameEffectCB;
}


vrt_render_dirty_type_enum VappShellIVMenu::FrameEffectCB(
    VfxS32                              cell,           /* [IN] the cell index */
    VfxS32                              subCell,        /* [IN] the sub cell index */
    VfxFloat                            cellRelPos,     /* [IN] the cell position */
    vrt_frame_visual_property_struct    *target_frame,  /* [IN] the cell frame */
    VfxFloat                            fPos,           /* [IN] animating index value */
    VfxS32                              focus,          /* the focus value of the menu */
    VfxRect                             viewBounds,     /* the menu bounds */
    void                                *userData,      /* user data */
    VfxU32                              userDataSize,   /* user data size */
    VcpWheelMenuState                   state,          /* [IN] the state of Menu */
    VfxFloat                            level           /* [IN] the level of state */
    )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(viewBounds);
    VFX_UNUSED(userDataSize);
    VFX_UNUSED(state);
    VFX_UNUSED(level);
    VFX_DEV_ASSERT(target_frame != NULL);

    VfxFloat offset = cellRelPos;
    /* becase focused index = 3 */
    VfxFloat index = 3 + offset;
    vrt_matrix3x3_struct tempTransform;

    /* check out of range, then set boundary transform */
    if (index < 0)
    {
        tempTransform = g_shellIVTransformArray[0];
    }
    else if (index > 7)
    {
        tempTransform = g_shellIVTransformArray[7];
    }
    else
    {
        /* find out the lowIndex and upIndex for linear interpolation. */
        VfxS32 lowIndex = VfxS32(index);
        VfxS32 upIndex = lowIndex + 1;
        VfxS32 i;

        for (i = 0; i < 9; i++)
        {
            tempTransform.m[i] = ((VfxFloat)upIndex - index) * g_shellIVTransformArray[lowIndex].m[i] + (index - lowIndex) * g_shellIVTransformArray[upIndex].m[i];
        }
    }

#ifdef __VUI_SHELL_IV_FPE_TRANSFORM_AFFINE__
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = tempTransform.m[0];
    target_frame->transform.data.affine.sy = tempTransform.m[4];
    target_frame->transform.data.affine.ty = tempTransform.m[5];
#else
    target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    target_frame->transform.data.matrix3x3 = tempTransform;
#endif /* __VUI_SHELL_IV_FPE_TRANSFORM_MATRIX3X3__ */

    target_frame->pos_z = VFX_ABS(offset);
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


VfxFrame* VappShellIVMenu::createCell(VfxS32 pos, VfxS32 subcell)
{
    VappShellIVCell *cell;

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_MENU_CREATE_CELL, pos);

    VFX_OBJ_CREATE_EX(
        cell,
        VappShellIVCell,
        this,
        (pos));    /* constructor parameters */

    if (getFocus() == pos)
    {
        cell->onHightLight();
    }

    VfxS32 pos_x = (getBounds().getWidth())/2;
    VfxS32 pos_y = (getBounds().getHeight())/2;
    cell->setAnchor(VfxFPoint(0.5, 0.5));
    cell->updatePos(VfxRect(pos_x, pos_y, IMG_MAX_WIDTH + 2*BORDER_PIXELS, IMG_MAX_HEIGHT+ 2*BORDER_PIXELS), VFX_FALSE);

    return cell;
}


void VappShellIVMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VappShellIVCell* item = (VappShellIVCell*) cellFrame;
    VfxS32 type = VappShellIVCell::DATA_TYPE_DB;

    if (m_isDragging || m_isDeleting)
    {
        type = VappShellIVCell::DATA_TYPE_MEMORY;
        return;
    }

    if (cell == getFocus())
    {
        item->onHightLight();
    }

    item->updateImage(type);
}


void VappShellIVMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VappShellIVCell *item = (VappShellIVCell *)cellFrame;

    item->closeImage();
    VFX_UNUSED(item);
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_MENU_CLOSE_CELL, cell);
}


void VappShellIVMenu::onAfterUpdateCell()
{
    VFX_LOG(VFX_INFO, VAPP_SHELLIV_MENU_AFTERUPDATE);

    updateCellImage();
}

void VappShellIVMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    if (VCP_WHEELMENU_IS_VALID_INDEX(previousFocusItem))
    {
        VappShellIVCell* cell = (VappShellIVCell*) getCellIfPresent(previousFocusItem);
        if (cell)
        {
            cell->onDeHightLight();
        }
    }
    if (VCP_WHEELMENU_IS_VALID_INDEX(focusItem))
    {
        VappShellIVCell* cell = (VappShellIVCell*) getCellIfPresent(focusItem);
        if (cell)
        {
            cell->onHightLight();
        }

        m_eventFocusChange.emit(focusItem);
    }
}


void VappShellIVMenu::onDragStart()
{
    VcpWheelMenu::onDragStart();
    m_isDragging = VFX_TRUE;
    vadp_shell_imgviewer_cache_srv_pause_bgdecode();
}


void VappShellIVMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);

#define SPEED_MOD 500.0f
    VcpWheelMenu::onDragEnd(xspeed, yspeed);

    m_isDragging = VFX_FALSE;
    if (yspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s  = yspeed > 0 ? -1 : 1;
        VfxFloat m  = VFX_ABS(yspeed) / SPEED_MOD;

        if (m > 3) m = 3;

        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
    }

    vadp_shell_imgviewer_cache_srv_resume_bgdecode();
}


void VappShellIVMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpWheelMenu::onDrag(xoffset, yoffset);

    VfxFloat perc = getScrollIndex() + VfxFloat(yoffset) / CELL_ITEM_HEIGHT;

    setScrollIndex(perc, 0);
}


void VappShellIVMenu::onTap(VfxPoint pt)
{
    VappShellIVCell* cell = (VappShellIVCell*)getCellIfPresent(getFocus());

    if (!cell)
        return;

    VfxRect focusBorderRect = cell->getBorderRect();
    VfxS32 up   = focusBorderRect.origin.y;
    VfxS32 down = up + focusBorderRect.getHeight();

    if (pt.y >= up && pt.y <= down)
    {
        /* because maybe the scroll index is changing by drag, fix it */
        setFocus(getFocus());
        cell->onHightLight();

        if (cell->getIsBorderContainPoint(pt))
        {
            if (!m_isDragging)
                vadp_shell_imgviewer_enter_kernal_app(getFocus());
        }
    }
    else if (pt.y < up)
    {
        setFocus(getFocus() + 1);
    }
    else if (pt.y > down)
    {
        setFocus(getFocus() - 1);
    }
}


void VappShellIVMenu::updateCellImage()
{
    VappShellIVCell* cell;
    void *buffer_p;
    VfxS32 ret = 0;
    VfxS32 start_index;
    VfxS32 radius;
    VfxS32 k;
    VfxBool is_stop = VFX_FALSE;

    if (m_isDragging == VFX_TRUE || m_isDeleting == VFX_TRUE)
    {
        m_timer->stop();
        return;
    }

    cell = (VappShellIVCell*) getCellIfPresent(getFocus());
    start_index = getFocus();

    radius = ((getLastVisibleIndex() - getFirstVisibleIndex()) >> 1) + 1;

    for (VfxS32 i = 0; i < radius; i++)
    {
        for(VfxS32 j = i*(-1); j <= i; j++)
        {
            k = start_index + j;
            VFX_TRACE(("[SHELL IV] updateCellImage : i = %d, j= %d, k= %d\n", i,j,k));
            if (k >= 0)
            {
                cell = (VappShellIVCell*)getCellIfPresent(k, 0);
                if (cell && (cell->getImageState() != VappShellIVCell::STATE_IMAGE))
                {
                    VFX_TRACE(("[SHELL IV] updateCellImage decode: k= %d\n",k));
                    VAPP_SHELLIV_START_LOGGING("UNB");
                    ret = vadp_shell_imgviewer_cache_srv_get_lock_image_buffer_nonblocking(
                            (void*)this,
                            k,
                            decodeCallBack,
                            &buffer_p);
                    VAPP_SHELLIV_STOP_LOGGING("UNB");

                    VFX_LOG(VFX_INFO, VAPP_SHELLIV_MENU_UPDATECELLIMAGE, ret);
                    if (ret == SRV_MEDIACACHE_OK)
                    {
                        cell->setImageBuffer(buffer_p);
                        m_timer->start();
                    }
                    else if (ret == SRV_MEDIACACHE_ERR_NOT_SUPPORT)
                    {
                        cell->setErrorIcon();
                        m_timer->start();
                    }
                    else if (ret == VADP_SHELLIV_DRM_LOCKED)
                    {
                        cell->setDRMIcon();
                        m_timer->start();
                    }
                    is_stop = VFX_TRUE;
                    break;
                }
            }
        }
        if (is_stop)
            break;
    }

}


void VappShellIVMenu::closeCellImage()
{
    VappShellIVCell* cell;
    VfxS32 start_index;

    cell = (VappShellIVCell*) getCellIfPresent(getFocus());

    start_index = getFirstVisibleIndex();
    for (VfxS32 i = start_index; i < getLastVisibleIndex(); i++)
    {
        cell = (VappShellIVCell*)getCellIfPresent(i, 0);
        if (cell && (cell->getImageState() == VappShellIVCell::STATE_IMAGE))
        {
            cell->stopSetImageTimer();
            cell->closeImage();
            cell->setDefaultIcon();
            VFX_LOG(VFX_INFO, VAPP_SHELLIV_CLOSE_IMG, i);
        }
    }

}


void VappShellIVMenu::updateDecodeResult(VfxS32 index, VfxS32 error_code)
{
    VappShellIVCell* cell;

    cell = (VappShellIVCell*)getCellIfPresent(index, 0);

    if (cell && (cell->getImageState() != VappShellIVCell::STATE_IMAGE))
    {
        if (error_code == SRV_MEDIACACHE_OK)
            cell->updateImage(VappShellIVCell::DATA_TYPE_DB);
        else if (error_code == VADP_SHELLIV_DRM_LOCKED)
            cell->setDRMIcon();
        else
            cell->setErrorIcon();
    }

    updateCellImage();

}


void VappShellIVMenu::decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code)
{
    VappShellIVMenu* this_ptr = (VappShellIVMenu*) user_data;

    VAPP_SHELLIV_START_LOGGING("DCB");
    if (this_ptr->isValid())
        this_ptr->updateDecodeResult(index, error_code);
    VAPP_SHELLIV_STOP_LOGGING("DCB");
}


void VappShellIVMenu::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_timer->stop();
    if (!m_isDragging)
    {
        updateCellImage();
    }
}


void VappShellIVMenu::onDelTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_delAnimateTimer->stop();
    m_eventDelAnimateEnd.emit();

}


void VappShellIVMenu::onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
{
    VFX_LOG(VFX_INFO, VAPP_SHELLIV_FRAMEEFFECT, m_removedFrame);

    if (m_removedFrame)
    {
        VappShellIVCell* cell = (VappShellIVCell*)m_removedFrame;
        VfxS32 delete_index = cell->getIndex();

        m_frameEffect->m_signalFinished.disconnect(this,&VappShellIVMenu::onFrameEffectFinished);

        m_isDeleting = VFX_TRUE;
        withdrawCell(delete_index);

        m_delAnimateTimer->start();
    }
}


void VappShellIVMenu::onAfterWithdrawCellClosed()
{
    if (m_removedFrame)
    {
        VappShellIVCell* cell = (VappShellIVCell*)m_removedFrame;
        VfxS32 delete_index = cell->getIndex();

        VFX_OBJ_CLOSE(m_removedFrame);
        m_count--;
        vadp_shell_imgviewer_withdraw_file(delete_index);
    }
}


void VappShellIVMenu::deleteFocusItem()
{
    VfxS32 delete_index = getFocus();

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_MENU_DELETEFOCUS, delete_index);

    setIsDisabled(VFX_TRUE); /* make the menu not receive pen event */

    m_removedFrame = pullOutSubCell(delete_index, 0);

    VappShellIVCell* cell = (VappShellIVCell*)m_removedFrame;
    if (cell)
        cell->closeImage();

    if (m_removedFrame)
    {
        m_frameEffect->applyEffect(m_removedFrame, VCP_EFFECT_RECTANGLE_ROTATE_OUT, DELETE_ANIMATION_DURATION);
        m_frameEffect->m_signalFinished.connect(this,&VappShellIVMenu::onFrameEffectFinished);
    }

}

VfxS32 VappShellIVMenu::getHighlightIndex()
{
    return getFocus();
}

void VappShellIVMenu::resizeImgCallback(VfxU32* handle, VfxS32* layer_w, VfxS32* layer_h, srv_mediacache_rect_struct *img_org, srv_mediacache_rect_struct *img_resized, void *user_data)
{
#define RESIZE_THRESHOLD (0.94f)
#define RESIZE_RATIO     (0.92f)

    VappShellIVMenu* this_ptr = (VappShellIVMenu*) user_data;

    if (this_ptr->isValid())
    {
        VfxS32 cellWidth = IMG_MAX_WIDTH;
        VfxS32 cellHeight = IMG_MAX_HEIGHT;
        VfxS32 resizeOffsetX, resizeOffsetY, resizeWidth, resizeHeight;

        vadp_shell_imgviewer_fit_img(
            cellWidth,
            cellHeight,
            img_org->width,
            img_org->height,
            &resizeOffsetX,
            &resizeOffsetY,
            &resizeWidth,
            &resizeHeight);

        if (VfxFloat(resizeWidth * resizeHeight)/VfxFloat(cellWidth * cellHeight) > RESIZE_THRESHOLD)
        {
            VfxFloat new_width = (VfxFloat)cellWidth * RESIZE_RATIO;
            VfxFloat new_height = (VfxFloat)cellHeight * RESIZE_RATIO;

            vadp_shell_imgviewer_fit_img(
                (VfxS32)new_width,
                (VfxS32)new_height,
                img_org->width,
                img_org->height,
                &resizeOffsetX,
                &resizeOffsetY,
                &resizeWidth,
                &resizeHeight);
        }

        img_resized->width = resizeWidth;
        img_resized->height = resizeHeight;
        *layer_w = resizeWidth;
        *layer_h = resizeHeight;
    }
}


/*****************************************************************************
 * Class VappShellIVPanel
 *****************************************************************************/
void VappShellIVPanel::onInit()
{
    VappShellPanel::onInit();

    m_storage = vadp_shell_imgviewer_get_storage();

    if (vadp_shell_imgviewer_check_is_valid_drv(m_storage))
        vadp_shell_imgviewer_create_filelist();

    m_menu = NULL;
    m_toolBar = NULL;
    m_waitingIcon = NULL;
    m_popupMenu = NULL;
    m_noImageIcon = NULL;
    m_noImageString = NULL;
    m_isDelAnimateDone = VFX_FALSE;
    m_deleteIdx = -1;

}


void VappShellIVPanel::onDeinit()
{
    vadp_shell_imgviewer_free_filelist();

    VappShellPanel::onDeinit();
}


void VappShellIVPanel::onInitView()
{
    VappShellPanel::onInitView();
    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_ONINIT);

    /* back group image */
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    m_bg->setBgColor(VFX_COLOR_BLACK);
    m_bg->setIsOpaque(VFX_TRUE);

    VFX_OBJ_CREATE(m_noStorageStr, VfxTextFrame, this);

    VfxBool isStorageReady = vadp_shell_imgviewer_check_is_valid_drv(vadp_shell_imgviewer_get_storage());
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        isStorageReady = VFX_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!isStorageReady)
    {
        /* include to draw card remove string */
        drawNoStorageStr();
        m_isListReday = VFX_FALSE;
    }

    VFX_OBJ_CREATE(m_toolBar, VcpSegmentButton, this);
    m_toolBar->setType(VCP_SEGMENT_BUTTON_TYPE_GROUP);
    m_toolBar->setStyle(VCP_SEGMENT_BUTTON_STYLE_IMAGE_ONLY);
    m_toolBar->setPos(TOOLBAR_POS_X, TOOLBAR_POS_Y);
    m_toolBar->setSize(TOOLBAR_WIDTH, TOOLBAR_HEIGHT);
    m_toolBar->addButton(
        BUTTON_STORAGE,
        VcpStateImage(VAPP_SHELL_IMG_IV_STORAGE_UP, VAPP_SHELL_IMG_IV_STORAGE_DOWN, VAPP_SHELL_IMG_IV_STORAGE_DISABLE, NULL),
        VFX_WSTR_NULL);
    m_toolBar->addButton(
        BUTTON_SENDAS,
        VcpStateImage(VAPP_SHELL_IMG_IV_SEND_UP, VAPP_SHELL_IMG_IV_SEND_DOWN, VAPP_SHELL_IMG_IV_SEND_DISABLE, NULL),
        VFX_WSTR_NULL);
    m_toolBar->addButton(
        BUTTON_USEAS,
        VcpStateImage(VAPP_SHELL_IMG_IV_USE_UP, VAPP_SHELL_IMG_IV_USE_DOWN, VAPP_SHELL_IMG_IV_USE_DISABLE, NULL),
        VFX_WSTR_NULL);
    m_toolBar->addButton(
        BUTTON_DELETE,
        VcpStateImage(VAPP_SHELL_IMG_DELETE_NOR, VAPP_SHELL_IMG_DELETE_PRE, VAPP_SHELL_IMG_DELETE_DIS, NULL),
        VFX_WSTR_NULL);

    if (isStorageReady)
    {
        VfxU8 currStorage = vadp_shell_imgviewer_get_storage();
        if (m_storage != currStorage)
        {
            m_toolBar->setHidden(VFX_TRUE);
            m_storage = currStorage;
            vadp_shell_imgviewer_free_filelist();

            m_isListReday = VFX_FALSE;
            drawWaiting();
            vadp_shell_imgviewer_set_focus_index(0);
            vadp_shell_imgviewer_create_filelist();
            vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
        }
        else
        {
            m_isListReday = vadp_shell_imgviewer_is_list_ready() != 0 ? VFX_TRUE : VFX_FALSE;

            if (!m_isListReday)
            {
                drawWaiting();
                vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
            }

            if (!m_isListReday)
                m_toolBar->setHidden(VFX_TRUE);
            else
            {
                checkFileCount();
                createMenu();

                if (m_menu)
                    m_menu->setIsDisabled(VFX_TRUE);
            }
        }
    }
    else
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (srv_usb_is_in_mass_storage_mode())
        {
            m_toolBar->setButtonIsDisabled(BUTTON_STORAGE, VFX_TRUE);
        }
    #endif /* __USB_IN_NORMAL_MODE__ */
        m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_TRUE);
    }
}


void VappShellIVPanel::onDeinitView()
{
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CLOSE(m_noStorageStr);
    VFX_OBJ_CLOSE(m_bg);

    if (m_menu)
        vadp_shell_imgviewer_set_focus_index(m_menu->getHighlightIndex());
    else
    {
        /* do nothing to keep the focus index in adapter no changing */
    }

    destroyMenu();

    stopDrawWaiting();

    vadp_shell_imgviewer_register_list_ready_callback((void*)NULL, NULL);
    vadp_shell_imgviewer_register_delete_done_callback((void*)NULL, NULL);

    if (m_isDelAnimateDone == VFX_FALSE && m_deleteIdx >= 0)
    {
        if (m_deleteIdx == vadp_shell_imgviewer_get_file_count() - 1)
            vadp_shell_imgviewer_set_focus_index(m_deleteIdx - 1);
        else
            vadp_shell_imgviewer_set_focus_index(m_deleteIdx);

        vadp_shell_imgviewer_delete_file_nonblocking(m_deleteIdx, this, deleteDoneCallBack);
        m_isListReday = VFX_FALSE;
        m_isDelAnimateDone = VFX_TRUE;
        m_deleteIdx = -1;
    }

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_ONDEINIT);
    VappShellPanel::onDeinitView();
}


void VappShellIVPanel::onEnterView()
{
    VappShellPanel::onEnterView();
    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_ONENTER);

    VfxBool isStorageReady = vadp_shell_imgviewer_check_is_valid_drv(vadp_shell_imgviewer_get_storage());
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        isStorageReady = VFX_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!isStorageReady)
    {
        destroyMenu();
        drawNoStorageStr();
        m_isListReday = VFX_FALSE;

    #ifdef __USB_IN_NORMAL_MODE__
        if (srv_usb_is_in_mass_storage_mode())
        {
            m_toolBar->setButtonIsDisabled(BUTTON_STORAGE, VFX_TRUE);
        }
    #endif /* __USB_IN_NORMAL_MODE__ */
    }
    else if (!m_noImageIcon && !m_menu && !m_noStorageStr->getHidden())
    {
        VfxU8 currStorage = vadp_shell_imgviewer_get_storage();
        if (m_storage != currStorage)
        {
            m_toolBar->setHidden(VFX_TRUE);
            m_storage = currStorage;
            vadp_shell_imgviewer_free_filelist();

            m_isListReday = VFX_FALSE;
            drawWaiting();
            vadp_shell_imgviewer_set_focus_index(0);
            vadp_shell_imgviewer_create_filelist();
            vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
        }
        else
        {
            m_isListReday = vadp_shell_imgviewer_is_list_ready() != 0 ? VFX_TRUE : VFX_FALSE;

            if (!m_isListReday)
            {
                drawWaiting();
                vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
            }

            if (!m_isListReday)
                m_toolBar->setHidden(VFX_TRUE);
            else
            {
                checkFileCount();
                createMenu();

                if (m_menu)
                    m_menu->setIsDisabled(VFX_TRUE);
            }
        }
        m_toolBar->setButtonIsDisabled(BUTTON_STORAGE, VFX_FALSE);
    }
    enterView();
}


void VappShellIVPanel::onExitView(ShellExitCauseEnum cause)
{
    exitView();

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_ONEXIT);
    VappShellPanel::onExitView(cause);
}


void VappShellIVPanel::enterView()
{
    if (m_menu)
    {
        vadp_shell_imgviewer_cache_srv_register_clip_cb(m_menu, &VappShellIVMenu::resizeImgCallback);
        vadp_shell_imgviewer_cache_srv_start();
        vadp_shell_imgviewer_cache_srv_register_filelist_refresh_cb((void*)this, refreshingListCallBack);
        m_menu->setIsDisabled(VFX_FALSE);

        m_menu->update();
    }

    m_toolBar->m_signalButtonClicked.connect(this, &VappShellIVPanel::onToolBarButtonClicked);
}


void VappShellIVPanel::exitView()
{
    VFX_OBJ_CLOSE(m_popupMenu);

    if (m_menu)
    {
        m_menu->setIsDisabled(VFX_TRUE);

        m_menu->closeCellImage();
        vadp_shell_imgviewer_cache_srv_register_clip_cb(m_menu, NULL);
        vadp_shell_imgviewer_cache_srv_register_filelist_refresh_cb((void*)NULL, NULL);
        vadp_shell_imgviewer_cache_srv_close();
    }
    m_toolBar->m_signalButtonClicked.disconnect(this, &VappShellIVPanel::onToolBarButtonClicked);
}


void VappShellIVPanel::onDelAnimateDone()
{
    if (m_menu)
        m_menu->m_eventDelAnimateEnd.disconnect(this, &VappShellIVPanel::onDelAnimateDone);

    m_isDelAnimateDone = VFX_TRUE;

    if (m_deleteIdx >= 0)
    {
        if (m_deleteIdx == vadp_shell_imgviewer_get_file_count() - 1)
            vadp_shell_imgviewer_set_focus_index(m_deleteIdx - 1);
        else
            vadp_shell_imgviewer_set_focus_index(m_deleteIdx);

        VfxS32 ret = vadp_shell_imgviewer_delete_file_nonblocking(m_deleteIdx, this, deleteDoneCallBack);
        m_isListReday = VFX_FALSE;

        if (ret < 0)
        {
            m_isListReday = vadp_shell_imgviewer_is_list_ready() != 0 ? VFX_TRUE : VFX_FALSE;
            if (!m_isListReday)
            {
                vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
            }
        }

        if (!m_isListReday)
        {
            drawWaiting();
            destroyMenu();
            vadp_shell_imgviewer_cache_srv_close();
        }

    }
}


void VappShellIVPanel::onToolBarButtonClicked(VfxObject* sender, VfxId buttonId)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    if (buttonId == BUTTON_STORAGE)
    {
        showStorageSelect();
    }
    else if (buttonId == BUTTON_SENDAS)
    {
        showSendAsSelect();
    }
    else if (buttonId == BUTTON_USEAS)
    {
        showUseAsSelect();
    }
    else if (buttonId == BUTTON_DELETE)
    {
        showDeleteSelect();
    }
}


void VappShellIVPanel::onStorageMenuButtonClicked(VfxObject* sender, VfxId buttonId)
{
    if (buttonId != STORAGE_MENU_ID_CANCEL && buttonId != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        srv_fmgr_drv_type_enum drv_enum;
        VfxU8 drv;

        drv_enum = (srv_fmgr_drv_type_enum)buttonId;
        drv = srv_fmgr_drv_get_letter_by_type(drv_enum);

        if (drv != m_storage)
        {
            m_noStorageStr->setHidden(VFX_TRUE);
            m_storage = drv;
            vadp_shell_imgviewer_set_storage(drv);
            vadp_shell_imgviewer_free_filelist();

            m_isListReday = VFX_FALSE;
            drawWaiting();
            destroyMenu();
            vadp_shell_imgviewer_cache_srv_close();
            vadp_shell_imgviewer_set_focus_index(0);
            vadp_shell_imgviewer_create_filelist();
            vadp_shell_imgviewer_register_list_ready_callback((void*)this, listReadyCallBack);
        }
    }
}


void VappShellIVPanel::onSendAsMenuButtonClicked(VfxObject* sender, VfxId buttonId)
{
    if (buttonId != OPTION_MENU_ID_CANCEL && buttonId != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        VfxWChar  filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
        VfxS32 index = m_menu->getHighlightIndex();

        if (vadp_shell_imgviewer_get_image_path_by_index(index, filepath, SRV_FMGR_PATH_BUFFER_SIZE))
        {
            srv_fmgr_types_launch_option(filepath, buttonId);
        }
    }
}


void VappShellIVPanel::onUseAsMenuButtonClicked(VfxObject* sender, VfxId buttonId)
{
    if (buttonId != OPTION_MENU_ID_CANCEL && buttonId != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        VfxWChar  filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
        VfxS32 index = m_menu->getHighlightIndex();

        if (vadp_shell_imgviewer_get_image_path_by_index(index, filepath, SRV_FMGR_PATH_BUFFER_SIZE))
            srv_fmgr_types_launch_option(filepath, buttonId);
    }
}


void VappShellIVPanel::onDlelteMenuButtonClicked(VfxObject* sender, VfxId buttonId)
{
    if (buttonId == DELETE_MENU_ID_DELETE && buttonId != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        m_isDelAnimateDone = VFX_FALSE;
        if (m_menu)
        {
            m_deleteIdx = m_menu->getFocus();
            m_menu->deleteFocusItem();

            m_menu->m_eventDelAnimateEnd.connect(this, &VappShellIVPanel::onDelAnimateDone);
        }

        if (m_toolBar)
        {
            m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);
            m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
            m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_TRUE);
        }

    }
}


void VappShellIVPanel::onFocusChange(VfxS32 index)
{
    VfxWChar  filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
    VfxS32 menu_id;

    if (m_isDelAnimateDone == VFX_FALSE && m_deleteIdx >= 0)
        return;

    if (vadp_shell_imgviewer_get_image_path_by_index(index, filepath, SRV_FMGR_PATH_BUFFER_SIZE))
    {
        menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (VfxWChar*)filepath);
        if (menu_id > 0)
            m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_FALSE);
        else
            m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);

        menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (VfxWChar*)filepath);
        if (menu_id > 0)
            m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_FALSE);
        else
            m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
    }
    else
    {
        m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_TRUE);
    }
}


void VappShellIVPanel::createMenu()
{
    VFX_OBJ_CREATE(m_noImageIcon, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_noImageString, VfxTextFrame, this);
    hideNoImageIcon();
    m_noStorageStr->setHidden(VFX_TRUE);

    if (m_cellCount <= 0)
    {
        drawNoImageIcon();
    }
    else
    {
        hideNoImageIcon();

        if (m_toolBar)
        {
            m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_FALSE);
            m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_FALSE);
            m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_FALSE);
        }

        VFX_OBJ_CREATE(m_menu, VappShellIVMenu, this);

        VfxRect bounds = VappShellPanel::getAppBounds();

        m_menu->m_eventFocusChange.connect(this, &VappShellIVPanel::onFocusChange);

        m_menu->setRect(bounds);
        m_menu->setFocused(VFX_TRUE);
        m_menu->setCount(m_cellCount);
        m_menu->setFocus(vadp_shell_imgviewer_get_focus_index());
    }

    if (m_toolBar)
    {
        m_toolBar->bringToFront();
        m_toolBar->setHidden(VFX_FALSE);
    }
}


void VappShellIVPanel::destroyMenu()
{
    if (m_menu)
    {
        m_menu->setIsDisabled(VFX_TRUE);
        m_menu->m_eventFocusChange.disconnect(this, &VappShellIVPanel::onFocusChange);
        VFX_OBJ_CLOSE(m_menu);
    }

    VFX_OBJ_CLOSE(m_noImageIcon);
    VFX_OBJ_CLOSE(m_noImageString);

    if (m_toolBar)
    {
        m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_TRUE);
    }
}


void VappShellIVPanel::checkFileCount()
{
    m_cellCount = vadp_shell_imgviewer_get_file_count();

    if (m_cellCount <= 0 && m_toolBar)
    {
        m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_TRUE);
        m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_TRUE);
    }
    else if (m_toolBar)
    {
        m_toolBar->setButtonIsDisabled(BUTTON_SENDAS, VFX_FALSE);
        m_toolBar->setButtonIsDisabled(BUTTON_USEAS, VFX_FALSE);
        m_toolBar->setButtonIsDisabled(BUTTON_DELETE, VFX_FALSE);
    }
}


void VappShellIVPanel::drawNoStorageStr()
{
    VfxRect bounds = VappShellPanel::getAppBounds();

    m_noStorageStr->setAnchor(0.5f,0.5f);
    m_noStorageStr->setPos(bounds.getMidX(), bounds.getMidY());
    m_noStorageStr->setSize(bounds.getWidth(), bounds.getHeight());
    m_noStorageStr->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_noStorageStr->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_noStorageStr->setMaxLines(4);
    m_noStorageStr->setAutoResized(VFX_TRUE);
    m_noStorageStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
    #if !defined(__COSMOS_MMI__)
        m_noStorageStr->setString(VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE));
    #endif
    }
    else
#endif /* __USB_IN_NORMAL_MODE__ */
    {
        m_noStorageStr->setString(VFX_WSTR_RES(VAPP_SHELL_STR_IV_CARD_REMOVE));
    }
    m_noStorageStr->setHidden(VFX_FALSE);

}

void VappShellIVPanel::drawNoImageIcon()
{
    VfxRect bounds = VappShellPanel::getAppBounds();

    m_noImageIcon->setResId(VAPP_SHELL_IMG_IV_NO_IMAGE);
    m_noImageIcon->setPos(NOIMAGE_ICON_POS_X, NOIMAGE_ICON_POS_Y);
    m_noImageIcon->setHidden(VFX_FALSE);

    m_noImageString->setAnchor(0.5f,0);
    m_noImageString->setPos(bounds.getMidX(), NOIMAGE_STR_POS_Y);
    m_noImageString->setSize(bounds.getWidth(), NOIMAGE_STR_HEIGHT);
    m_noImageString->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_noImageString->setString(VFX_WSTR_RES(VAPP_SHELL_STR_NO_IMAGE));
    m_noImageString->setHidden(VFX_FALSE);

}


void VappShellIVPanel::hideNoImageIcon()
{
    m_noImageIcon->setHidden(VFX_TRUE);
    m_noImageString->setHidden(VFX_TRUE);
}


void VappShellIVPanel::drawWaiting()
{
    VfxRect bounds = VappShellPanel::getAppBounds();

    if (m_waitingIcon)
       VFX_OBJ_CLOSE(m_waitingIcon);

    VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, this);
    m_waitingIcon->setAnchor(0.5f, 0.5f);
    m_waitingIcon->setPos(bounds.getMidX(), bounds.getMidY());
    m_waitingIcon->start();

    if (m_toolBar)
        m_toolBar->setHidden(VFX_TRUE);
}


void VappShellIVPanel::stopDrawWaiting()
{
    if (m_waitingIcon)
       VFX_OBJ_CLOSE(m_waitingIcon);

    if (m_toolBar)
        m_toolBar->setHidden(VFX_FALSE);
}


void VappShellIVPanel::showStorageSelect()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VFX_OBJ_CREATE(m_popupMenu, VcpCommandPopup, findScreen());
    VfxU8 drv_num;
    VfxS8 drv_enum;
    VfxU8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    VfxU8 drv;

    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_num = srv_fmgr_drivelist_count(drvlist);

    m_popupMenu->setText(VFX_WSTR_RES(VAPP_SHELL_STR_SELECT_STORAGE));

    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        drv_enum = srv_fmgr_drv_get_type(drv);

        if (vadp_shell_imgviewer_check_is_valid_drv(drv))
            m_popupMenu->addItem(drv_enum, VFX_WSTR_RES(srv_fmgr_drv_get_string((U8)drv)));
    }
    m_popupMenu->addItem(STORAGE_MENU_ID_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    m_popupMenu->setAutoDestory(VFX_TRUE);
    m_popupMenu->show(VFX_TRUE);
    m_popupMenu->m_signalButtonClicked.connect(this, &VappShellIVPanel::onStorageMenuButtonClicked);

    srv_fmgr_drivelist_destroy(drvlist);
}


void VappShellIVPanel::showSendAsSelect()
{
    VfxS32 menu_id;
    VfxWChar  filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
    VfxS32 index = m_menu->getHighlightIndex();

    if (vadp_shell_imgviewer_get_image_path_by_index(index, filepath, SRV_FMGR_PATH_BUFFER_SIZE))
    {
        menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (VfxWChar*)filepath);
        if (menu_id > 0)
        {
            VfxU16 itemStrList[OPTION_MAX_COUNT];
            VfxU16 itemIDList[OPTION_MAX_COUNT];
            U8 i = 0;

            for (i = 0; i < OPTION_MAX_COUNT; i++)
            {
                itemStrList[i] = 0;
                itemIDList[i] = 0;
            }

            GetSequenceStringIds_Ext(menu_id, itemStrList);
            GetSequenceItemIds_Ext(menu_id, itemIDList);

            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            VFX_OBJ_CREATE(m_popupMenu, VcpCommandPopup, findScreen());
            m_popupMenu->setText(VFX_WSTR_RES(STR_GLOBAL_SEND));
            m_popupMenu->setImage(VFX_IMAGE_SRC_NULL);

            i = 0;
            while(itemStrList[i] != 0)
            {
                m_popupMenu->addItem(itemIDList[i], VFX_WSTR_RES(itemStrList[i]));
                i++;
            }
            m_popupMenu->addItem(OPTION_MENU_ID_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

            m_popupMenu->setAutoDestory(VFX_TRUE);
            m_popupMenu->show(VFX_TRUE);
            m_popupMenu->m_signalButtonClicked.connect(this, &VappShellIVPanel::onSendAsMenuButtonClicked);

        }
    }
}


void VappShellIVPanel::showUseAsSelect()
{
    VfxS32 menu_id;
    VfxWChar  filepath[(SRV_FMGR_PATH_MAX_LEN+1)];
    VfxS32 index = m_menu->getHighlightIndex();

    if (vadp_shell_imgviewer_get_image_path_by_index(index, filepath, SRV_FMGR_PATH_BUFFER_SIZE))
    {
        menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (VfxWChar*)filepath);
        if (menu_id > 0)
        {
            VfxU16 itemStrList[OPTION_MAX_COUNT];
            VfxU16 itemIDList[OPTION_MAX_COUNT];
            U8 i = 0;

            for (i = 0; i < OPTION_MAX_COUNT; i++)
            {
                itemStrList[i] = 0;
                itemIDList[i] = 0;
            }

            GetSequenceStringIds_Ext(menu_id, itemStrList);
            GetSequenceItemIds_Ext(menu_id, itemIDList);

            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            VFX_OBJ_CREATE(m_popupMenu, VcpCommandPopup, findScreen());
            m_popupMenu->setText(VFX_WSTR_RES(STR_GLOBAL_USE));
            m_popupMenu->setImage(VFX_IMAGE_SRC_NULL);

            i = 0;
            while(itemStrList[i] != 0)
            {
            #ifdef __MMI_POWER_ON_OFF_DISPLAY__
                if (itemIDList[i] != MENU_ID_FMGR_FWD_POWER_ON && itemIDList[i] != MENU_ID_FMGR_FWD_POWER_OFF)
            #endif
                {
                    m_popupMenu->addItem(itemIDList[i], VFX_WSTR_RES(itemStrList[i]));
                }
                i++;
            }
            m_popupMenu->addItem(OPTION_MENU_ID_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

            m_popupMenu->setAutoDestory(VFX_TRUE);
            m_popupMenu->show(VFX_TRUE);
            m_popupMenu->m_signalButtonClicked.connect(this, &VappShellIVPanel::onUseAsMenuButtonClicked);

        }
    }
}


void VappShellIVPanel::showDeleteSelect()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VFX_OBJ_CREATE(m_popupMenu, VcpCommandPopup, findScreen());

    m_popupMenu->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_popupMenu->setText(VFX_WSTR_RES(VAPP_SHELL_STR_DELETE_IMAGE));
    m_popupMenu->addItem(DELETE_MENU_ID_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_POPUP_BUTTON_TYPE_WARNING);
    m_popupMenu->addItem(DELETE_MENU_ID_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_popupMenu->setAutoDestory(VFX_TRUE);
    m_popupMenu->show(VFX_TRUE);
    m_popupMenu->m_signalButtonClicked.connect(this, &VappShellIVPanel::onDlelteMenuButtonClicked);
}


void VappShellIVPanel::listReadyCallBack(void* user_data)
{
    VappShellIVPanel* this_ptr = (VappShellIVPanel*) user_data;

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_LISTREADYCB);
    if (this_ptr->isValid())
    {
        this_ptr->stopDrawWaiting();

        this_ptr->m_isListReday = VFX_TRUE;

        VfxU8 state = this_ptr->getPanelState();

        this_ptr->checkFileCount();

        if (state == APP_SHELL_ENTER_VIEW || state == APP_SHELL_INIT_VIEW)
        {
            this_ptr->createMenu();

            if (state == APP_SHELL_INIT_VIEW)
            {
                if (this_ptr->m_menu)
                    this_ptr->m_menu->setIsDisabled(VFX_TRUE);
            }
            else if (state == APP_SHELL_ENTER_VIEW)
                this_ptr->enterView();
        }
    }
}


void VappShellIVPanel::deleteDoneCallBack(void* user_data)
{
    vadp_shell_imgviewer_register_delete_done_callback((void*)NULL, NULL);

    VappShellIVPanel* this_ptr = (VappShellIVPanel*) user_data;

    VFX_LOG(VFX_INFO, VAPP_SHELLIV_PANEL_DELETEDONECB);
    if (this_ptr->isValid())
    {
        this_ptr->m_deleteIdx = -1;
        this_ptr->m_isListReday = vadp_shell_imgviewer_is_list_ready() != 0 ? VFX_TRUE : VFX_FALSE;

        if (!this_ptr->m_isListReday)
        {
            vadp_shell_imgviewer_register_list_ready_callback((void*)this_ptr, listReadyCallBack);
        }
    }
}


void VappShellIVPanel::refreshingListCallBack(void* user_data)
{
    VappShellIVPanel* this_ptr = (VappShellIVPanel*) user_data;

    if (this_ptr->isValid())
    {
        VFX_LOG(VFX_INFO, VAPP_SHELLIV_RELOADLING);

        if (this_ptr->m_menu)
        {
            vadp_shell_imgviewer_set_focus_index(this_ptr->m_menu->getHighlightIndex());
        }

        vadp_shell_imgviewer_register_list_ready_callback((void*)this_ptr, listReadyCallBack);

        this_ptr->drawWaiting();
        this_ptr->destroyMenu();
        vadp_shell_imgviewer_cache_srv_close();
    }
}


#endif /* __MMI_VUI_SHELL_IMAGE_VIEWER__ */
