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
 *  vapp_mediawall.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_MEDIAWALL__
#include "vapp_mediawall.h"
#include "MediaWall\vadp_mediawall.h"
#include "vapp_mediawall_res.h"
#include "trc/vadp_app_trc.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MediaCacheSrvGprot.h"
#include "FileMgrResDef.h"
#include "gui_touch_feedback.h"
#include "gui_typedef.h"
#include "mmi_rp_app_mediawall_def.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "vrt_system.h"
#include "MMIDataType.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"

#if !defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_filemanager_def.h"
#endif

#ifdef __cplusplus
}
#endif
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
#include "vcp_base_menu.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"
#include "vfx_string.h"
#include "vfx_system.h"
#include "vfx_transform.h"
#include "vfx_weak_ptr.h"
#include "vfx_app_cat_scr.h"
#include "vcp_status_icon_bar.h"
#include "vcp_marquee.h"
#include "vcp_content_clone.h"
#include "vrt_canvas.h"

    
extern void vadp_mediawall_set_rotating(VfxBool is_rotating);
extern VfxBool vadp_mediawall_is_over_fs_sorting_limit(void);
extern void vadp_mediawall_enter_imgviewer(void);

VfxS32 VappMediaWallScr::m_viewMode = VappMediaWallScr::VIEW_PORTRAIT;
VfxS32 VappMediaWallMenu::m_indexNonBlocking = -1;
/***************************************************************************** 
 * Media Wall app category
 *****************************************************************************/

/*****************************************************************************
 * Class VappHsWidgetFmrButton
 *****************************************************************************/

VappMediaWallButton::VappMediaWallButton() : m_image(NULL), m_imageHighLight(NULL)
{   
}


VappMediaWallButton::~VappMediaWallButton()
{

}

void VappMediaWallButton::onInit(void)
{
    VfxControl::onInit();

    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);

    m_image->setAnchor(VfxFPoint(0.5, 0.5));
    setBounds(VfxRect(0, 0, 1, 1));
}


void VappMediaWallButton::onDeinit(void)
{
    VfxControl::onDeinit();
}


void VappMediaWallButton::setImage(VfxS32 upImage,VfxS32 downImage)
{
    m_imageUpId= upImage;
    m_imageDownId = downImage;

    if (m_curr_pentype == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (m_image->getResId() != downImage)
        {
            m_image->setResId(downImage);
        }
    }
    else
    {
        if (m_image->getResId() != upImage)
        {
            m_image->setResId(upImage);
        }
    }

    VfxRect bounds = getBounds();
    if (bounds.getWidth() < m_image->getBounds().getWidth() || 
        bounds.getHeight() < m_image->getBounds().getHeight())
    {
        setBounds(m_image->getBounds());
    }
    m_image->setPos(VfxPoint(getBounds().getMidX(),getBounds().getMidY()));
}


void VappMediaWallButton::setImageHighLight(VfxS32 highLightImage)
{
    m_imageHighLightId = highLightImage;
}


void VappMediaWallButton::setDisplay(VfxBool isDisplay)
{
    if (isDisplay)
    {
        setHidden(VFX_FALSE);
    }
    else
    {
        VFX_OBJ_CLOSE(m_imageHighLight);
        setHidden(VFX_TRUE);
    }
}


void VappMediaWallButton::setDraw(VfxPenEventTypeEnum type)
{
    if (type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_image->setResId(m_imageDownId);

        if (getHidden() == VFX_FALSE)
        {
            if (!m_imageHighLight)
                VFX_OBJ_CREATE(m_imageHighLight, VfxImageFrame, this->findScreen());

            VfxPoint parentPt = this->convertPointTo(VfxPoint(getBounds().getMidX(),getBounds().getMidY()), this->findScreen());
            
            m_imageHighLight->setPos(parentPt.x, parentPt.y);
            m_imageHighLight->setAnchor(VfxFPoint(0.5, 0.5));
            m_imageHighLight->setResId(m_imageHighLightId);
            m_imageHighLight->setIsUnhittable(VFX_TRUE);  
        }
    }
    else if (VFX_PEN_EVENT_TYPE_UP)
    {
        m_image->setResId(m_imageUpId);

        if (m_imageHighLight)
            VFX_OBJ_CLOSE(m_imageHighLight);      
    }
}
    

VfxBool VappMediaWallButton::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;

        if (getHidden() == VFX_FALSE)
        {
            VFX_OBJ_CREATE(m_imageHighLight, VfxImageFrame, this->findScreen());

            VfxPoint parentPt = this->convertPointTo(VfxPoint(getBounds().getMidX(),getBounds().getMidY()), this->findScreen());
            
            m_imageHighLight->setPos(parentPt.x, parentPt.y);
            m_imageHighLight->setAnchor(VfxFPoint(0.5, 0.5));
            m_imageHighLight->setResId(m_imageHighLightId);
            m_imageHighLight->setIsUnhittable(VFX_TRUE);
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
        m_image->setResId(m_imageDownId);
        
        m_eventPenDown.emit(event);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
        m_image->setResId(m_imageUpId);
        
        VFX_OBJ_CLOSE(m_imageHighLight);
        
        m_eventPenUp.emit(event);
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
            m_image->setResId(m_imageDownId);
            
            if (m_imageHighLight)
                m_imageHighLight->setHidden(VFX_FALSE);
        }
        else
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
            m_image->setResId(m_imageUpId);

            if (m_imageHighLight)
                m_imageHighLight->setHidden(VFX_TRUE);
        }
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
        m_image->setResId(m_imageUpId);
        VFX_OBJ_CLOSE(m_imageHighLight);
        
        return VFX_TRUE;
    }
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    return VfxControl::onPenInput(event);
}


/*****************************************************************************
 * Class VappMediaWallCell
 *****************************************************************************/
VappMediaWallCell::VappMediaWallCell(VfxS32 index) : 
    m_index(index), 
    m_state(STATE_EXIT),
    m_width(0),
    m_height(0),
    m_isHighlight(VFX_FALSE),
    m_innerX(0),
    m_innerY(0),
    m_imageBuf(NULL)
{

}


VappMediaWallCell::~VappMediaWallCell()
{
    m_index = 0;
    m_state = STATE_EXIT;
    m_imageBuf = NULL;
}


void VappMediaWallCell::onInit()
{
    VfxControl::onInit();

    setBgColor(VFX_COLOR_BLACK);
    setOpacity(1);
    setAnchor(VfxFPoint(0.5, 0.5));
    setIsCached(VFX_TRUE);

    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
}


void VappMediaWallCell::onDeinit()
{
    VfxControl::onDeinit();
}


void VappMediaWallCell::onHightLight()
{
    m_isHighlight = VFX_TRUE;
    setAutoAnimate(VFX_TRUE);
    setBounds(VfxRect(0, 0, m_width, m_height));
    setImgContent(m_image);
    setBgColor(VFX_COLOR_YELLOW);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    bringToFront();

}


void VappMediaWallCell::onDeHightLight()
{
    m_isHighlight = VFX_FALSE;
    setAutoAnimate(VFX_FALSE);
    setBounds(VfxRect(0, 0, m_width - m_innerX, m_height - m_innerY));
    setBgColor(VFX_COLOR_BLACK);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
}


VfxBool VappMediaWallCell::updateImage(VfxS32 type)
{
    srv_mediacache_image_source_enum source;
    VfxS32 error_code = 0;

    if (m_state == STATE_IMAGE)
        return VFX_TRUE;
    
    // Call MediaLib to decode image
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
        
        error_code = vadp_mediawall_srv_get_lock_image_buffer(m_index, source, &m_imageBuf);

    #if defined(__MTK_INTERNAL__)       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif      
    }

    if (type == DATE_TYPE_DEFAULT)
    {
        m_image.setResId(VAPP_MEDIAWALL_IMG_DEFAULT_ICON);
        m_state = STATE_DEFAULT;        
        invalidate();
    }
    else if (error_code == SRV_MEDIACACHE_OK)
    {
        VfxImageBuffer imageBuf;

        imageBuf.ptr = (VfxU8*)m_imageBuf;
        imageBuf.pitchBytes = (m_width - m_innerX) * 2;
        imageBuf.width = m_width - m_innerX;
        imageBuf.height = m_height - m_innerY;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        m_image.setImageBuffer(imageBuf);

        m_state = STATE_IMAGE;
        invalidate();
    }
    else if (error_code == SRV_MEDIACACHE_ERR_NOT_SUPPORT)
    {
        setErrorIcon();
    }
    else if (error_code == VADP_MEDIAWALL_DRM_LOCKED)
    {
        setDRMIcon();       
    }
    else if (m_state != STATE_DEFAULT)
    {
        m_image.setResId(VAPP_MEDIAWALL_IMG_DEFAULT_ICON);
        m_state = STATE_DEFAULT;
        invalidate();
    }

    if (m_isHighlight)
    {
        setAutoAnimate(VFX_TRUE);
        setBounds(VfxRect(0, 0, m_width, m_height));
        setImgContent(m_image);
        setBgColor(VFX_COLOR_YELLOW);
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    }
    else
    {
        setImgContent(m_image);
        setBounds(VfxRect(0, 0, m_width - m_innerX, m_height - m_innerY));
        setBgColor(VFX_COLOR_BLACK);
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    }
    
    return VFX_TRUE;
}


void VappMediaWallCell::closeImage()
{
    if (m_state == STATE_IMAGE && m_image.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
    {
        vadp_mediawall_srv_free_image_buffer(m_index, (void*)m_imageBuf);
    }
}


void VappMediaWallCell::setErrorIcon()
{
    m_image.setResId(VAPP_MEDIAWALL_IMG_UNSUPPORT_ICON);
    setImgContent(m_image);
    
    m_state = STATE_IMAGE;
    invalidate();
}


void VappMediaWallCell::setDRMIcon()
{
    m_image.setResId(VAPP_MEDIAWALL_IMG_DRM_LOCKED_ICON);
    setImgContent(m_image);
    
    m_state = STATE_IMAGE;
    invalidate();
}


void VappMediaWallCell::setImageBuffer(void *buffer_p)
{
    VfxImageBuffer imageBuf;

    m_imageBuf = buffer_p;
    
    imageBuf.ptr = (VfxU8*)m_imageBuf;
    imageBuf.pitchBytes = (m_width - m_innerX) * 2;
    imageBuf.width = m_width - m_innerX;
    imageBuf.height = m_height - m_innerY;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    m_image.setImageBuffer(imageBuf);
    setImgContent(m_image);
    
    m_state = STATE_IMAGE;
    invalidate();
}


void VappMediaWallCell::setHighlight()
{
    m_isHighlight = VFX_TRUE;
}


void VappMediaWallCell::updatePos(const VfxRect& r, VfxBool animation)
{
    setAutoAnimate(animation);
    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    if (m_isHighlight)
    {
        setBounds(VfxRect(0, 0, m_width, m_height));
    }
    else
    {
        setBounds(VfxRect(0, 0, r.getWidth() - m_innerX, r.getHeight() - m_innerY));
    }
            
    m_width = r.getWidth();
    m_height = r.getHeight();
}


void VappMediaWallCell::enter(const VfxRect& r, VfxBool animation)
{
    if (animation)
    {
        setPos(VfxPoint(r.getMidX(), r.getMidY()));
        updatePos(r, VFX_TRUE);
        setOpacity(1.0f);
    }
    else
    {
        updatePos(r, VFX_FALSE);
        setOpacity(1.0f);
    }
}


void VappMediaWallCell::leave(const VfxRect& r)
{
    setAutoAnimate(VFX_TRUE);
    updatePos(r, VFX_FALSE);
    setOpacity(0);
}


/*****************************************************************************
 * Class VappMediaWallVerLayout
 *****************************************************************************/
VappMediaWallVerLayout::~VappMediaWallVerLayout()
{
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellNumPerRow = 0;
    m_menuCutLength = 0;
}


void VappMediaWallVerLayout::onInit()
{
    VcpBaseMenuLayout::onInit();

    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellNumPerRow = 0;
    m_menuCutLength = 0;
}


VfxS32 VappMediaWallVerLayout::getContentLength()
{
    if (m_cellNumPerRow== 0)
        return 0;

    VfxS32 row = (m_cellCount+ m_cellNumPerRow - 1) / m_cellNumPerRow;

    return row * m_cellHeight;  
}


VcpMenuRegion VappMediaWallVerLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
                getCellByPos(r.origin),
                getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
            );  
}


VcpMenuPos VappMediaWallVerLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;

    if (m_cellNumPerRow== 0)
    {
        p.group = 0;
        p.pos = 0;

        return p;
    }
    
    p.group = 0;
    
    VfxS32 row = pt.y / m_cellHeight;
    VfxS32 col = VFX_MAX(pt.x - 1, 0) / m_cellWidth;
    p.pos = row * m_cellNumPerRow + col;

    if (p.pos < 0)
    {
        p.pos = 0;
    }
    if (p.pos >= getCellCount(p.group))
    {
        p.pos = getCellCount(p.group) - 1;
    }
    return p;
}


VcpMenuPos VappMediaWallVerLayout::queryPosByPt(const VfxPoint& pt)
{
    VcpMenuPos p;

    if (m_cellNumPerRow== 0)
    {
        p.group = 0;
        p.pos = 0;

        return p;
    }   
        
    p.group = 0;
    VfxS32 row = pt.y / m_cellHeight;
    VfxS32 col = VFX_MAX(pt.x - 1, 0) / m_cellWidth;
    p.pos = row * m_cellNumPerRow + col;

    if (p.pos < 0)
    {
        p.invalid();
    }
    else if (p.pos >= getCellCount(p.group))
    {
        p.invalid();
    }
    return p;
}


VfxRect VappMediaWallVerLayout::queryCellRect(VcpMenuPos pos)
{
    if (pos.group < 0 || pos.pos < -1 || m_cellNumPerRow == 0)
        return VfxRect(-1, -1, 0, 0);

    if (pos.group >= 1 || pos.pos >= getCellCount(pos.group))
        return VfxRect(-1, -1, 0, 0);

    VfxS32 row = (pos.pos / m_cellNumPerRow) * m_cellHeight;
    VfxS32 col = (pos.pos % m_cellNumPerRow) * m_cellWidth;
                
    return VfxRect(col, row, m_cellWidth, m_cellHeight);    
}


VfxBool VappMediaWallVerLayout::navDir(NavDirEnum dir)
{
    // If there is no one is focused, we pick up one in the screen
    if (!getFocusItem().isValid())
    {
        VcpMenuPos p = getCellByPos(m_viewRect.origin);
        // we cannot focus on the header
        if (p.isGroupHeader()) 
        {
            p.pos = 0;
        }
        setFocusItem(p);
        return VFX_TRUE;
    }

    VcpMenuPos p;
    if (dir == NAV_DIR_UP)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_cellNumPerRow;
        VfxS32 r = p.pos / m_cellNumPerRow;
        VfxS32 group_row = (getCellCount(p.group)-1) / m_cellNumPerRow;

        if (r > 0)
        {
            r--;
            p.pos = r * m_cellNumPerRow + c;
        }
        else
        {
            if (p.group <= 0)
            {
                p.group = 0;
                if (group_row > 0)
                {
                    p.pos += group_row * m_cellNumPerRow;
                    if (p.pos > getCellCount(p.group)-1)
                    {
                        p.pos = getCellCount(p.group)-1;                   
                    }
                }
                else
                    p.pos = 0;
            }
            else
            {
                p.group--;

                VfxS32 n_group_row = getCellCount(p.group) / m_cellNumPerRow;

                p.pos = n_group_row * m_cellNumPerRow + c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
    }
    else if (dir == NAV_DIR_DOWN)
    {
        p = getFocusItem();

        VfxS32 c = p.pos % m_cellNumPerRow;
        VfxS32 r = p.pos / m_cellNumPerRow;
        VfxS32 group_row = (getCellCount(p.group) - 1) / m_cellNumPerRow;

        if (r >= group_row)
        {
            p.group++;
            if (p.group >= getGroupCount())
            {
                p.group = getGroupCount() - 1;
                if (group_row > 0)
                    p.pos = c;
                else
                    p.pos = getCellCount(p.group) - 1;
            }
            else
            {
                p.pos = c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        else
        {
            p.pos = (r + 1) * m_cellNumPerRow + c;
            if (p.pos >= getCellCount(p.group))
            {
                p.pos = getCellCount(p.group) - 1;
            }
        }
    }
    else if (dir == NAV_DIR_LEFT)
    {
        p = getFocusItem();
        if (p.pos == 0)
            p.pos = getCellCount(p.group) - 1;
        else
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
    }
    else if (dir == NAV_DIR_RIGHT)
    {
        p = getFocusItem();
        if (p.pos == getCellCount(p.group) - 1)
            p.pos = 0;
        else      
            p = getFocusItem().getNextPos(this, VFX_FALSE);
    }
    if (p)
    {
        setFocusItem(p);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappMediaWallVerLayout::getPreferFocusMargin(VfxS32 margin[4])
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  
    margin[0] = 0;
    margin[1] = 0;
    margin[2] = 0;
    margin[3] = m_menuCutLength;
}


void VappMediaWallVerLayout::setFocusItem(VcpMenuPos focus,  VfxBool isMoveToVisible)
{
    VcpBaseMenuLayout:: setFocusItem(focus, isMoveToVisible);
}


void VappMediaWallVerLayout::makeVisible(VcpMenuPos p, VfxBool isAnim)
{
    VcpBaseMenuLayout:: makeVisible(p, isAnim);
}


const VfxPoint VappMediaWallVerLayout::getViewPosition() const
{
    VfxPoint pos = getViewPos();

    return pos;
}


const VfxSize VappMediaWallVerLayout::getViewDimension() const
{
    VfxSize size = getViewSize();

    return size;
}


/*****************************************************************************
 * Class VappMediaWallHorLayout
 *****************************************************************************/
VappMediaWallHorLayout::~VappMediaWallHorLayout()
{
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellNumPerColumn = 0;
    m_menuCutLength = 0;
}


void VappMediaWallHorLayout::onInit()
{
    VcpBaseMenuLayout::onInit();

    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellNumPerColumn = 0;
    m_menuCutLength = 0;
    
}


VfxS32 VappMediaWallHorLayout::getContentLength()
{
    if (m_cellNumPerColumn == 0)
        return 0;
    
    VfxS32 column = (m_cellCount+ m_cellNumPerColumn - 1) / m_cellNumPerColumn;

    return column * m_cellWidth + 2 * VappMediaWallMenu::BASEPLANE_EXTEND + m_menuCutLength;    
}


VcpMenuRegion VappMediaWallHorLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
                getCellByPos(r.origin),
                getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
            );  
}


VcpMenuPos VappMediaWallHorLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    
    if (m_cellNumPerColumn == 0)
    {
        p.group = 0;
        p.pos = 0;

        return p;
    }
        
    p.group = 0;
    
    VfxS32 col = (pt.x - VappMediaWallMenu::BASEPLANE_EXTEND) / m_cellWidth;
    VfxS32 row = VFX_MAX(pt.y - 1, 0) / m_cellHeight;
    p.pos = col * m_cellNumPerColumn + row;

    if (p.pos < 0)
    {
        p.pos = 0;
    }
    if (p.pos >= getCellCount(p.group))
    {
        p.pos = getCellCount(p.group) - 1;
    }
    return p;
}


VcpMenuPos VappMediaWallHorLayout::queryPosByPt(const VfxPoint& pt)
{
    VcpMenuPos p;

    if (m_cellNumPerColumn == 0)
    {
        p.group = 0;
        p.pos = 0;

        return p;
    }
    
    p.group = 0;
    VfxS32 col = (pt.x - VappMediaWallMenu::BASEPLANE_EXTEND) / m_cellWidth;
    VfxS32 row = VFX_MAX(pt.y - 1, 0) / m_cellHeight;
    p.pos = col * m_cellNumPerColumn + row;

    if (p.pos < 0)
    {
        p.invalid();
    }
    else if (p.pos >= getCellCount(p.group))
    {
        p.invalid();
    }
    return p;
}


VfxRect VappMediaWallHorLayout::queryCellRect(VcpMenuPos pos)
{
    if (pos.group < 0 || pos.pos < -1 || m_cellNumPerColumn == 0 )
        return VfxRect(-1, -1, 0, 0);

    if (pos.group >= 1 || pos.pos >= getCellCount(pos.group))
        return VfxRect(-1, -1, 0, 0);

    VfxS32 col = (pos.pos / m_cellNumPerColumn) * m_cellWidth + VappMediaWallMenu::BASEPLANE_EXTEND;
    VfxS32 row = (pos.pos % m_cellNumPerColumn) * m_cellHeight;
                
    return VfxRect(col, row, m_cellWidth, m_cellHeight);    
}


VfxBool VappMediaWallHorLayout::navDir(NavDirEnum dir)
{
    // If there is no one is focused, we pick up one in the screen
    if (!getFocusItem().isValid())
    {
        VcpMenuPos p = getCellByPos(m_viewRect.origin);
        // we cannot focus on the header
        if (p.isGroupHeader()) 
        {
            p.pos = 0;
        }
        setFocusItem(p);
        return VFX_TRUE;
    }

    VcpMenuPos p;
    if (dir == NAV_DIR_UP)
    {
        p = getFocusItem();
        if (p.pos == 0)
            p.pos = getCellCount(p.group) - 1;
        else     
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
    }
    else if (dir == NAV_DIR_DOWN)
    {
        p = getFocusItem();
        if (p.pos == getCellCount(p.group) - 1)
            p.pos = 0;
        else
            p = getFocusItem().getNextPos(this, VFX_FALSE);
    }
    else if (dir == NAV_DIR_LEFT)
    {
        p = getFocusItem();

        VfxS32 r = p.pos % m_cellNumPerColumn;
        VfxS32 c = p.pos / m_cellNumPerColumn;
        VfxS32 group_column = (getCellCount(p.group)-1) / m_cellNumPerColumn;

        if (c > 0)
        {
            c--;
            p.pos = c * m_cellNumPerColumn + r;
        }
        else
        {
            if (p.group <= 0)
            {
                p.group = 0;
                if (group_column > 0)
                {
                    p.pos += group_column * m_cellNumPerColumn;
                    if (p.pos > getCellCount(p.group)-1)
                        p.pos = getCellCount(p.group)-1;
                }
                else    
                    p.pos = 0;
            }
            else
            {
                p.group--;

                VfxS32 n_group_column = getCellCount(p.group) / m_cellNumPerColumn;

                p.pos = n_group_column * m_cellNumPerColumn + r;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }       
    }
    else if (dir == NAV_DIR_RIGHT)
    {
        p = getFocusItem();

        VfxS32 r = p.pos % m_cellNumPerColumn;
        VfxS32 c = p.pos / m_cellNumPerColumn;
        VfxS32 group_column = (getCellCount(p.group) - 1) / m_cellNumPerColumn;

        if (c >= group_column)
        {
            p.group++;
            if (p.group >= getGroupCount())
            {
                p.group = getGroupCount() - 1;
                if (group_column > 0)
                    p.pos = r;
                else
                    p.pos = getCellCount(p.group) - 1;
            }
            else
            {
                p.pos = r;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        else
        {
            p.pos = (c + 1) * m_cellNumPerColumn + r;
            if (p.pos >= getCellCount(p.group))
            {
                p.pos = getCellCount(p.group) - 1;
            }
        }       
    }
    if (p)
    {
        setFocusItem(p);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappMediaWallHorLayout::getPreferFocusMargin(VfxS32 margin[4])
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    margin[0] = VappMediaWallMenu::BASEPLANE_EXTEND;
    margin[1] = 0;
    margin[2] = VappMediaWallMenu::BASEPLANE_EXTEND + m_menuCutLength;
    margin[3] = 0;
}


void VappMediaWallHorLayout::setFocusItem(VcpMenuPos focus,  VfxBool isMoveToVisible)
{
    VcpBaseMenuLayout:: setFocusItem(focus, isMoveToVisible);
    
}


void VappMediaWallHorLayout::makeVisible(VcpMenuPos p, VfxBool isAnim)
{
    VcpBaseMenuLayout:: makeVisible(p, isAnim);
}


const VfxPoint VappMediaWallHorLayout::getViewPosition() const
{
    VfxPoint pos = getViewPos();

    return pos;
}


const VfxSize VappMediaWallHorLayout::getViewDimension() const
{
    VfxSize size = getViewSize();

    return size;
}


/*****************************************************************************
 * Class VappMediaWallMenu
 *****************************************************************************/
VappMediaWallMenu::VappMediaWallMenu(VfxS32 style, VfxFrame *viewFrame) : 
    m_style(style), 
    m_isFocusCellMissed(VFX_FALSE),
    m_isViewCellReady(VFX_FALSE),
    m_isCellFadeOut(VFX_FALSE),
    m_rotateAngle(0),
    m_lastXOffset(0),
    m_cameraDistance(NEARPLANE)
{
    m_parentViewFrame = viewFrame;
}


void VappMediaWallMenu::onInit()
{
    VcpBaseMenu::onInit();

#define FreerunFactor (1.3f)

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(100);
    m_timer->setDuration(100);
    m_timer->m_signalTick.connect(this, &VappMediaWallMenu::onTimerTick);

    VFX_OBJ_CREATE(m_timerFileIndex, VfxTimer, this);
    m_timerFileIndex->setStartDelay(100);
    m_timerFileIndex->setDuration(100);
    m_timerFileIndex->m_signalTick.connect(this, &VappMediaWallMenu::onTimerFileIndex);
    
    m_state = Opening;

    setSlowFactor(1.0f, 1.0f, FreerunFactor);
    m_isScrolling = VFX_FALSE;
#ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__    
    VFX_OBJ_CREATE(m_rotateTimeline, VfxTransformTimeline, this);
    VFX_OBJ_CREATE(m_decreaseTimer, VfxTimer, this);
    m_decreaseTimer->m_signalTick.connect(this, &VappMediaWallMenu::onDecreaseTimerTick);
    VFX_OBJ_CREATE(m_resetTimer, VfxTimer, this);
    m_resetTimer->m_signalTick.connect(this, &VappMediaWallMenu::onResetTimerTick);
#endif /* __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__ */    
}


void VappMediaWallMenu::onDeinit()
{
    m_timer->stop();

    VcpBaseMenu::onDeinit();
}

VfxBool VappMediaWallMenu::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_UP
            || event.keyCode == VFX_KEY_CODE_ARROW_DOWN
            || event.keyCode == VFX_KEY_CODE_ARROW_LEFT
            || event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            VcpMenuPos  p   = getLayout()->getFocusItem();
            VcpMenuRegion r = getRealContentRegion();

            // The current focus item is not in view
            if (!r.isWithin(p) && !m_targetRegion.isWithin(p))
            {
                VcpMenuRegionIter itr(getLayout(), r);
                VcpMenuPos p2 = itr.next();

                if (p2)
                {
                    getLayout()->setFocusItem(p2);
                    return VFX_TRUE;
                }
            }
        }
    }
    return VcpBaseMenu::onKeyInput(event);
}

VcpBaseMenuLayout* VappMediaWallMenu::createLayout()
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout;
        VFX_OBJ_CREATE_EX(layout, VappMediaWallVerLayout, this, (this));
        return layout;
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout;
        VFX_OBJ_CREATE_EX(layout, VappMediaWallHorLayout, this, (this));
    #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  
        enableHorizontalScrollIndicator(VFX_FALSE);
    #endif
        return layout;      
    }
    else
        VFX_ASSERT(0);
}

    
VfxFrame* VappMediaWallMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VappMediaWallCell *cell;
    
    VFX_OBJ_CREATE_EX(
        cell,
        VappMediaWallCell, 
        this, 
        (pos));    /* constructor parameters */ 

    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout* layout = (VappMediaWallVerLayout*)m_layout;
        cell->setCellInnerX(layout->getCellInnerX());
        cell->setCellInnerY(layout->getCellInnerY());
    }
    else
    {
        VappMediaWallHorLayout* layout = (VappMediaWallHorLayout*)m_layout;
        cell->setCellInnerX(layout->getCellInnerX());
        cell->setCellInnerY(layout->getCellInnerY());
    }

    if (m_isFocusCellMissed)
    {
        if (getHighLightIdx() == pos)
        {
            cell->setHighlight();
            m_isFocusCellMissed = VFX_FALSE;
        }
    }
    
    return cell;
}


void VappMediaWallMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VappMediaWallCell *cell = (VappMediaWallCell *)cellFrame;

    cell->closeImage();
    VFX_OBJ_CLOSE(cellFrame);
}


void VappMediaWallMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VappMediaWallCell* item = (VappMediaWallCell*) cell;
    VfxS32 type = VappMediaWallCell::DATA_TYPE_MEMORY;

    VFX_ASSERT(item != NULL);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(rect, VFX_TRUE);
            item->updateImage(type);    
        }
        else
        {
            item->enter(rect, VFX_FALSE);
            item->updateImage(type);
        }
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(rect);
    }
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->updateImage(type);
        item->updatePos(rect, VFX_FALSE);
    }
    else
    {
        item->updateImage(type);
        item->updatePos(rect, VFX_TRUE);
    }

    // TODO: Remove the below part if have update end event
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
    

void VappMediaWallMenu::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    VappMediaWallCell* item = (VappMediaWallCell*) cell;
    if (!item->getIsHighlight())
    {
        m_layout->setFocusItem(VcpMenuPos(group, pos));
//      vadp_mediawall_set_highlight(pos);
    }
    else
    {
        vfxPostInvoke0(this, &VappMediaWallMenu::launchImageViewer);
    }
}


void VappMediaWallMenu::onCellFadeOut()
{
    VfxS32 denominator;
    VfxS32 index;
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    
    VcpMenuRegionIter itr(this, getRealContentRegion());
    
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

    m_isCellFadeOut = VFX_TRUE;
    stopScrolling();
    
    while(!itr.isEnd())
    {
        VcpMenuPos p = itr.next();
        S32 moveLength;
 
        VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(p.group, p.pos);
        cell->setAutoAnimate(VFX_TRUE);
        if (cell)
        {
            if (m_style == PORTRAIT)
            {   
                VappMediaWallVerLayout* layout = (VappMediaWallVerLayout*)m_layout;
                denominator = layout->getCellNumPerRow() / 2;
                index = p.pos % layout->getCellNumPerRow();

                moveLength = mainScreenSize.width * (layout->getCellNumPerRow()/2 + 1) /layout->getCellNumPerRow();
                    
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(CELL_FADEOUT_DURATION);
                
                if (index / denominator == 0)
                {               
                    cell->setPos(VfxPoint((-moveLength) + cell->getPos().x, cell->getPos().y));
                }
                else if (index / denominator == 1 && index % denominator == 0)
                {
                    if ((p.pos / layout->getCellNumPerRow()) % 2 == 0)
                    {
                        cell->setPos(VfxPoint((-moveLength) + cell->getPos().x, cell->getPos().y));
                    }
                    else
                    {
                        cell->setPos(VfxPoint(moveLength + cell->getPos().x, cell->getPos().y));
                    }
                }
                else/* if (index / denominator > 1)*/
                {
                    cell->setPos(VfxPoint(moveLength + cell->getPos().x, cell->getPos().y));
                }

                VfxAutoAnimate::commit();

            }
            else if (m_style == LANDSCAPE)
            {
                VappMediaWallHorLayout* layout = (VappMediaWallHorLayout*)m_layout;
                denominator = layout->getCellNumPerColumn() / 2;
                index = p.pos % layout->getCellNumPerColumn();              

                moveLength = mainScreenSize.height * (layout->getCellNumPerColumn()/2 + 1) /layout->getCellNumPerColumn();
                    
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(CELL_FADEOUT_DURATION);
                
                if (index / denominator == 0)
                {               
                    cell->setPos(VfxPoint(cell->getPos().x, -(moveLength) + cell->getPos().y));
                }
                else if (index / denominator == 1 && index % denominator == 0)
                {
                    if ((p.pos / layout->getCellNumPerColumn()) % 2 == 0)
                    {
                        cell->setPos(VfxPoint(cell->getPos().x, -(moveLength) + cell->getPos().y));
                    }
                    else
                    {
                        cell->setPos(VfxPoint(cell->getPos().x, moveLength + cell->getPos().y));
                    }
                }
                else
                {
                    cell->setPos(VfxPoint(cell->getPos().x, moveLength + cell->getPos().y));
                }

                VfxAutoAnimate::commit();
            }
        }
    }
}


void VappMediaWallMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VappMediaWallCell* item = (VappMediaWallCell*)getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);

    if (item)
    {
        item->onDeHightLight();
    }

    item = (VappMediaWallCell*)getCellIfPresent(focusItem.group, focusItem.pos);    
    if (item)
    {
        m_isFocusCellMissed = VFX_FALSE;
        
        if (m_rotateAngle == 0)
            item->onHightLight();
        
        vadp_mediawall_set_highlight(focusItem.pos);
    }
    else
        m_isFocusCellMissed = VFX_TRUE;

    m_eventFocusChange.emit(focusItem.pos);
}


void VappMediaWallMenu::onDragStart()
{
    VcpBaseMenu::onDragStart();
}


void VappMediaWallMenu::onDragEnd()
{
    VcpBaseMenu::onDragEnd();
    
    // Perspective
    m_lastXOffset = 0;

    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAGEND, m_lastXOffset);
}


void VappMediaWallMenu::onResetTimerTick(VfxTimer *source)
{   
    source->stop();

    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_RESTTIMER_TIMELINE_STOP);

    VfxMsec durationTime = PERSPECTIVE_DECREASE_TIMER_DURATION * VFX_ABS(m_rotateAngle)/PERSPECTIVE_ANGLE_STEP;

    if (durationTime == 0)
        durationTime = PERSPECTIVE_DECREASE_TIMER_DURATION;
    
    m_rotateTimeline->stop();
    m_rotateTimeline->setTarget(getParentFrame());
    m_rotateTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_rotateTimeline->setDurationTime(durationTime);
    m_rotateTimeline->setRepeatCount(1);
    m_rotateTimeline->setIsFromCurrent(VFX_TRUE);
    m_rotateTimeline->setToValue(VfxTransform(VFX_TRANSFORM_TYPE_MATRIX3X3));
    m_rotateTimeline->m_signalStopped.connect(this,&VappMediaWallMenu::onRotateTimeLineStop);
    m_rotateTimeline->start();
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_RESTTIMER_TIMELINE_START);
 
    m_decreaseTimer->setStartDelay(PERSPECTIVE_DECREASE_TIMER_DURATION);
    m_decreaseTimer->setDuration(PERSPECTIVE_DECREASE_TIMER_DURATION);
    m_decreaseTimer->start();
}


void VappMediaWallMenu::postSetBounds(VfxS32 l, VfxS32 t, VfxS32 w, VfxS32 h)
{
    setBounds(VfxRect(l,t,w,h));
    update();
}


void VappMediaWallMenu::postSetPos(VfxS32 x, VfxS32 y)
{
    setPos(x,y);
    update();
}


void VappMediaWallMenu::onDecreaseTimerTick(VfxTimer *source)
{
    if (m_rotateAngle > 0)
    {
        m_rotateAngle -= PERSPECTIVE_ANGLE_STEP;
        m_cameraDistance -= CAMERADISTANCE_STEP;
    }
    else if (m_rotateAngle < 0)
    {
        m_rotateAngle += PERSPECTIVE_ANGLE_STEP;
        m_cameraDistance -= CAMERADISTANCE_STEP;
    }
    else if (m_rotateAngle == 0)
    {
        source->stop();
        onRotateTimeLineStop(NULL, VFX_TRUE);
    }
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_DECREASEIMTER_TICK, m_rotateAngle, (VfxS32)m_cameraDistance);
    
}


void VappMediaWallMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpBaseMenu::onDrag(xoffset, yoffset);
    if (xoffset != 0 || yoffset != 0)
    {
        VcpMenuPos focus = m_layout->getFocusItem();
        if (focus.isValid())
        {
            VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(focus.group, focus.pos);
            if (cell)
            {
                cell->onDeHightLight();
            }
        }
    }
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAG, xoffset, m_lastXOffset, m_rotateAngle);

#ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__      
    if (m_style == LANDSCAPE)
    {
        if (m_lastXOffset == 0)
        {
            VfxS32 width = getBounds().getWidth() + 2*BASEPLANE_EXTEND;
            VfxS32 height = getBounds().getHeight();
        }

        m_resetTimer->stop();

        VfxBool is_reverse = VFX_FALSE;
        VfxS32  speed = xoffset - m_lastXOffset;

        if ((xoffset > 0 && m_lastXOffset < 0) ||
            (xoffset < 0 && m_lastXOffset > 0))
        {
            is_reverse = VFX_TRUE;
        }

        VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAGINFO_0, speed, m_rotateAngle);
 //       VFX_TRACE(("[MEDIAWALL] VappMediaWallMenu::onDrag speed = %d m_rotateAngle = %d\n", speed, m_rotateAngle));
        
        if (is_reverse)
        {
            if (VFX_ABS(speed) > SPEED_THRESHOLD)
            {
                VfxS32 angle = VFX_ABS(speed)/(PERSPECTIVE_SPEED_STEP/2) * PERSPECTIVE_ANGLE_STEP;

                if (angle == 0)
                    angle = PERSPECTIVE_ANGLE_STEP;

                if (speed > 0)
                    m_rotateAngle += angle;
                else
                    m_rotateAngle -= angle;
            
                m_cameraDistance += CAMERADISTANCE_STEP;

                if (m_rotateAngle > PERSPECTIVE_ANGLE_LIMIT)
                    m_rotateAngle = PERSPECTIVE_ANGLE_LIMIT;
                else if (m_rotateAngle < -PERSPECTIVE_ANGLE_LIMIT)
                    m_rotateAngle = -PERSPECTIVE_ANGLE_LIMIT;

                if (m_cameraDistance > CAMERADISTANCE_LIMIT)
                    m_cameraDistance = CAMERADISTANCE_LIMIT;
            }
            setOnDragMatrix();
            setOnDragTimeLine();
            
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAG_TIMELINE_START, __LINE__);
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAGINFO_1, m_rotateAngle, (VfxS32)m_cameraDistance);
        }    
        else if (xoffset >= 0 && m_rotateAngle < PERSPECTIVE_ANGLE_LIMIT)
        {
            m_rotateAngle += (speed/PERSPECTIVE_SPEED_STEP) * PERSPECTIVE_ANGLE_STEP;
            m_cameraDistance += VFX_ABS(speed)/PERSPECTIVE_SPEED_STEP * CAMERADISTANCE_STEP;
            
            if (m_rotateAngle > PERSPECTIVE_ANGLE_LIMIT)
                m_rotateAngle = PERSPECTIVE_ANGLE_LIMIT;
            
            if (m_cameraDistance > CAMERADISTANCE_LIMIT)
                m_cameraDistance = CAMERADISTANCE_LIMIT;
            
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAG_TIMELINE_START, __LINE__);

            setOnDragMatrix();
            setOnDragTimeLine();
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAGINFO_2, m_rotateAngle, (VfxS32)m_cameraDistance);
        }
        else if (xoffset < 0 && m_rotateAngle > -PERSPECTIVE_ANGLE_LIMIT)
        {
            m_rotateAngle += ((speed/PERSPECTIVE_SPEED_STEP) * PERSPECTIVE_ANGLE_STEP);
            m_cameraDistance += VFX_ABS(speed)/PERSPECTIVE_SPEED_STEP * CAMERADISTANCE_STEP;
            
            if (m_rotateAngle < -PERSPECTIVE_ANGLE_LIMIT)
                m_rotateAngle = -PERSPECTIVE_ANGLE_LIMIT;

            if (m_cameraDistance > CAMERADISTANCE_LIMIT)
                m_cameraDistance = CAMERADISTANCE_LIMIT;
            
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAG_TIMELINE_START, __LINE__);

            setOnDragMatrix();
            setOnDragTimeLine();
            VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONDRAGINFO_3, m_rotateAngle, (VfxS32)m_cameraDistance);
        }
        m_lastXOffset = xoffset;  
        m_resetTimer->setStartDelay(PERSPECTIVE_RESET_TIMER_DURATION);
        m_resetTimer->start();        

        m_eventRotateTimelineStart.emit(m_rotateAngle);

    }
#endif /* __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  */    
}


void VappMediaWallMenu::onViewScrollStart()
{
    VcpBaseMenu::onViewScrollStart();
    
    m_timer->stop();

    m_isScrolling = VFX_TRUE;

    #ifdef __MMI_FTE_SUPPORT_SLIM__
    vadp_mediawall_srv_pause_bgdecode();
    #endif

    m_isViewCellReady = VFX_FALSE;

    m_timerFileIndex->start();
}


void VappMediaWallMenu::onViewScrollEnd()
{
    VcpBaseMenu::onViewScrollEnd();
    
    m_isScrolling = VFX_FALSE;

    #ifdef __MMI_FTE_SUPPORT_SLIM__
    vadp_mediawall_srv_resume_bgdecode();
    #endif
    
    m_timer->stop();
    m_timerFileIndex->stop();
    
    m_liteUpdateLastPos = -1;
    
#ifdef __MMI_VUI_MEDIAWALL_LITE_DISPLAY__
    liteUpdate();
#else
    heavyUpdate();
#endif
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONVEIWSCROLLEND_1, __LINE__, (VfxS32)m_cameraDistance, (VfxS32)m_rotateAngle, m_isScrolling);
#ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ONVEIWSCROLLEND_2, __LINE__, (VfxS32)m_rotateTimeline->getIsEnabled());       

    if (m_rotateTimeline->getIsEnabled())
        return;
#endif
    if (m_isCellFadeOut)
        return;

    VappMediaWallCell* cell;
    VcpMenuPos focus = m_layout->getFocusItem();
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VcpMenuPos p;
    VfxRect rect;
    VfxU32 num;
    VfxU32 index = 0;
    
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
        num = vLayout->getCellNumPerRow();
    }
    else
    {
        VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
        num = hLayout->getCellNumPerColumn();
    }
                
    if (focus.isValid())
    {
        cell = (VappMediaWallCell*)getCellIfPresent(focus.group, focus.pos);
        if (cell && getIsInViewRegion(focus))
        {
            if (!cell->getIsHighlight())
            {
                cell->onHightLight();
            }
        }
        // is the drag end event NOT invoked by focus changed?
        else
        {
            p = itr.next();
            do
            {
                if (getIsInViewRegion(p))
                {
                    focus.pos = p.pos;
                    m_layout->setFocusItem(VcpMenuPos(focus.group, focus.pos));                 
                    break;
                }
                else
                {
//                    p.pos += num;
                    for (index = 0; index < num; index++)
                        p = itr.next();
                }

            }while(!itr.isEnd());
        }
    }
    
    focus = m_layout->getFocusItem();
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;
        if (layout)
        {
            layout->makeVisible(focus, VFX_TRUE);
        }

    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;

        if (layout)
        {
            layout->makeVisible(focus, VFX_TRUE);
        }
    }

    m_eventNotifyNewFocus.emit(focus.pos);
}


void VappMediaWallMenu::onRotateTimeLineStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ROTATETIMELINESTOP, __LINE__, isCompleted, (VfxS32)m_rotateAngle, m_isScrolling);
    
    if (isCompleted && m_rotateAngle == 0 && !m_isScrolling)
    {
        VappMediaWallCell* cell;
        VcpMenuPos focus = m_layout->getFocusItem();
        VcpMenuRegionIter itr(this, getRealContentRegion());
        VcpMenuPos p;
        VfxRect rect;
        VfxU32 num;
        VfxU32 index = 0;
        
        if (m_style == PORTRAIT)
        {
            VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
            num = vLayout->getCellNumPerRow();
        }
        else
        {
            VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
            num = hLayout->getCellNumPerColumn();
        }
    
        if (focus.isValid())
        {
            cell = (VappMediaWallCell*)getCellIfPresent(focus.group, focus.pos);
            if (cell && getIsInViewRegion(focus))
            {
                if (!cell->getIsHighlight())
                {
                    cell->onHightLight();
//                    VFX_TRACE(("[MEDIAWALL]onRotateTimeLineStop->onHightLight\n"));
                }
            }
            // is the drag end event NOT invoked by focus changed?
            else
            {
                p = itr.next();
                do
                {
                    if (getIsInViewRegion(p))
                    {
//                        VFX_TRACE(("[MEDIAWALL]onRotateTimeLineStop->setFocusItem [%d][Line = %d]\n", focus.pos, __LINE__));
                        focus.pos = p.pos;
                        m_layout->setFocusItem(VcpMenuPos(focus.group, focus.pos));                 
                        break;
                    }
                    else
                    {
                        for (index = 0; index < num; index++)
                            p = itr.next();
                    }

                }while(!itr.isEnd());
            }
        }
        
        focus = m_layout->getFocusItem();
        if (m_style == PORTRAIT)
        {
            VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;
            if (layout)
            {
                layout->makeVisible(focus, VFX_TRUE);
            }

        }
        else if (m_style == LANDSCAPE)
        {
            VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;

            if (layout)
            {
                layout->makeVisible(focus, VFX_TRUE);
            }
        }
        m_eventRotateTimelineEnd.emit(m_rotateAngle);
    }
}

    
void VappMediaWallMenu::onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion)
{
    if (!m_isScrolling)
    {
        heavyUpdate();

        VcpMenuPos focus = m_layout->getFocusItem();
        if (focus.isValid())
        {
            VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(focus.group, focus.pos);
            if (cell && !cell->getIsHighlight())
            {
                if (m_rotateAngle == 0)
                    cell->onHightLight();
            }
        }
    }
}


VfxBool VappMediaWallMenu::getIsViewCellReady()
{
    VappMediaWallCell* cell;
    VcpMenuPos p;
    VfxBool ret = VFX_TRUE;
    VcpMenuRegionIter itr(this, getRealContentRegion());

    ret = VFX_TRUE;
    while(!itr.isEnd())
    {
        p = itr.next();
 
        cell = (VappMediaWallCell*)getCellIfPresent(p.group, p.pos);
        if (cell && (cell->getImageState() != VappMediaWallCell::STATE_IMAGE) && getIsCellVisiable(p))
        {
           ret = VFX_FALSE;
           break;
        }
    }
    return ret;
}


void VappMediaWallMenu::heavyUpdate(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappMediaWallCell* cell;
    VcpMenuPos p;
    void *buffer_p;
    VfxS32 ret = 0;
    VfxBool isCellDecode = VFX_FALSE;
    
    if (m_isScrolling)
        return;
        
    while(!itr.isEnd())
    {
        p = itr.next();
 
        cell = (VappMediaWallCell*)getCellIfPresent(p.group, p.pos);

        isCellDecode = VFX_FALSE;
        if (!m_isViewCellReady && getIsCellVisiable(p))
        {
            isCellDecode = VFX_TRUE;
        }
        else if (m_isViewCellReady)
        {
            isCellDecode = VFX_TRUE;
        }

        if (cell && (cell->getImageState() != VappMediaWallCell::STATE_IMAGE) && isCellDecode)
        {
            VAPP_MEDIAWALL_START_LOGGING("UNB");
            ret = vadp_mediawall_srv_get_lock_image_buffer_nonblocking(
                    (void*)this, 
                    p.pos, 
                    decodeCallBack, 
                    &buffer_p);
            VAPP_MEDIAWALL_STOP_LOGGING("UNB");
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
            else if (ret == VADP_MEDIAWALL_DRM_LOCKED)
            {
                cell->setDRMIcon();
                m_timer->start();            
            }
            break;

        }       
   
    }

    if (!m_isViewCellReady && getIsViewCellReady())
    {
        m_isViewCellReady = VFX_TRUE;
        m_timer->start();
    }

}


void VappMediaWallMenu::heavyUpdate(VfxS32 index, VfxS32 error_code)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappMediaWallCell* cell;
    VcpMenuPos p;

    p.group = 0;
    p.pos = index;
    cell = (VappMediaWallCell*)getCellIfPresent(p.group, p.pos);

    if (cell && (cell->getImageState() != VappMediaWallCell::STATE_IMAGE))
    {
        if (error_code == SRV_MEDIACACHE_OK)
            cell->updateImage(VappMediaWallCell::DATA_TYPE_DB);
        else if (error_code == VADP_MEDIAWALL_DRM_LOCKED)
            cell->setDRMIcon();
        else
            cell->setErrorIcon();
    }

    heavyUpdate();
}


void VappMediaWallMenu::liteUpdate(void)
{
    VcpMenuPos p;
    VcpMenuRegion currRegion = getRealContentRegion();
    VappMediaWallCell* cell;
    VfxBool is_end = VFX_FALSE;

    if (currRegion.begin.pos >= 0 && currRegion.end.pos >= 0 && m_liteUpdateLastPos < 0)
    {
        m_liteUpdateLastPos = currRegion.begin.pos;
        is_end = VFX_FALSE;
    }
    else
    {
        m_liteUpdateLastPos++;
        if (m_liteUpdateLastPos > currRegion.end.pos)
        {
            is_end = VFX_TRUE;
        }
        else
        {
            is_end = VFX_FALSE;
        }
    }

    if (is_end)
    {
        m_liteUpdateLastPos = -1;
        heavyUpdate();
    }
    else
    {   
        p.group = 0;
        p.pos = m_liteUpdateLastPos;
        cell = (VappMediaWallCell*)getCellIfPresent(p.group, p.pos);
        if (cell && cell->getImageState() != VappMediaWallCell::STATE_IMAGE)
        {
            cell->updateImage(VappMediaWallCell::DATA_TYPE_DB);
        }
        m_timer->start();
    }

}


void VappMediaWallMenu::update(void)
{
    VcpBaseMenu::updateLayout();
}


void VappMediaWallMenu::setCellWidth(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;
        if (layout)
        {
            layout->setCellWidth(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;
        if (layout)
        {
            layout->setCellWidth(value);
        }
    }
    else
        VFX_ASSERT(0);  
}


void VappMediaWallMenu::setCellHeight(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;
        
        if (layout)
        {
            layout->setCellHeight(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;
        
        if (layout)
        {
            layout->setCellHeight(value);
        }
    }
    else
        VFX_ASSERT(0);  
}


void VappMediaWallMenu::setCellNumPerRow(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;
        
        if (layout)
        {
            layout->setCellNumPerRow(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;
        
        if (layout)
        {
            layout->setCellNumPerColumn(value);
        }
    }
    else
        VFX_ASSERT(0);
}


void VappMediaWallMenu::setCellCount(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;

        if (layout)
        {
            layout->setCellCount(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;

        if (layout)
        {
            layout->setCellCount(value);
        }
    }
    else
        VFX_ASSERT(0);
}


void VappMediaWallMenu::setCellInnerX(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;

        if (layout)
        {
            layout->setCellInnerX(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;

        if (layout)
        {
            layout->setCellInnerX(value);
        }
    }
    else
        VFX_ASSERT(0);
}


void VappMediaWallMenu::setCellInnerY(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;

        if (layout)
        {
            layout->setCellInnerY(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;

        if (layout)
        {
            layout->setCellInnerY(value);
        }   
    }
    else
        VFX_ASSERT(0);
}


void VappMediaWallMenu::setCutLength(VfxS32 value)
{
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *layout = (VappMediaWallVerLayout*)m_layout;

        if (layout)
        {
            layout->setMenuCutLength(value);
        }
    }
    else if (m_style == LANDSCAPE)
    {
        VappMediaWallHorLayout *layout = (VappMediaWallHorLayout*)m_layout;

        if (layout)
        {
            layout->setMenuCutLength(value);
        }   
    }
    else
        VFX_ASSERT(0);
}


void VappMediaWallMenu::setHighLightIdx(VfxS32 value)
{

    VcpMenuPos focus;
    focus.group = 0;
    focus.pos = value;

    m_layout->setFocusItem(focus, VFX_TRUE);
    
    VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(focus.group, focus.pos);
    if (cell)
        cell->onHightLight();
}


VfxS32 VappMediaWallMenu::getHighLightIdx()
{
    VcpMenuPos focus = m_layout->getFocusItem();
    
    if (focus.isValid())
    {
        return focus.pos;
    }
    return -1;
}


VfxS32 VappMediaWallMenu::getDisplayIdx()
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VcpMenuPos p = itr.next();
    
    return p.pos;
}


void VappMediaWallMenu::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_timer->stop();
    if (!m_isScrolling)
    {
        if (m_liteUpdateLastPos >= 0)
            liteUpdate();
        else
            heavyUpdate();      
    }
}


void VappMediaWallMenu::onTimerFileIndex(VfxTimer *source)
{
    VFX_UNUSED(source);

    VfxU32 num;
    VfxPoint viewPoint;
    VfxSize viewSize;
    VfxRect rect;
    
    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
        num = vLayout->getCellNumPerRow();
        viewPoint = getViewBounds().origin;
        viewSize = vLayout->getViewDimension();        
    }
    else
    {
        VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
        num = hLayout->getCellNumPerColumn();
        viewPoint = getViewBounds().origin;
        viewSize = hLayout->getViewDimension();
    }
    VcpMenuPos focus = m_layout->getFocusItem();
    
    if (getIsInViewRegion(focus))
        return;
        
    VfxS32 index = 0;
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VcpMenuPos p;
    // Set the top-left cell index in current view
        
    p = itr.next();
    do
    {
        if (m_style == PORTRAIT)
        {
            VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
            rect = vLayout->queryCellRect(p);
        }
        else
        {
            VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
            rect = hLayout->queryCellRect(p);
        }
    
        if (p.isValid() && 
            rect.getMinX() >= viewPoint.x && 
            rect.getMinY() >= viewPoint.y &&
            rect.getMaxX() <= viewPoint.x + viewSize.width &&
            rect.getMaxY() <= viewPoint.y + viewSize.height)
        {     
            m_eventNotifyNewFocus.emit(p.pos);
            break;
        }
        else
        {
            for (index = 0; index < num; index++)
                p = itr.next();
        }

    }while(!itr.isEnd());  
    
}


void VappMediaWallMenu::onReset()
{
    reset();
}


void VappMediaWallMenu::launchImageViewer()
{
    vadp_mediawall_enter_imgviewer();
}


void VappMediaWallMenu::decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code)
{
    VappMediaWallMenu* this_ptr = (VappMediaWallMenu*) user_data;
    VfxObjWeakPtr weak_ptr = this_ptr;

    VAPP_MEDIAWALL_START_LOGGING("DCB");
    if (weak_ptr != NULL)
        this_ptr->heavyUpdate(index, error_code);
    VAPP_MEDIAWALL_STOP_LOGGING("DCB");
}


VfxBool VappMediaWallMenu::getIsInViewRegion(VcpMenuPos Pos)
{
    VfxPoint viewPoint;
    VfxSize viewSize;
    VfxRect rect;
    VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(Pos.group, Pos.pos);;

    if (!cell)
        return VFX_FALSE;

    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
        viewPoint = vLayout->getViewPosition();
        viewSize = vLayout->getViewDimension();
        rect = vLayout->queryCellRect(Pos);

        if (rect.getMinX() >= viewPoint.x && 
            rect.getMinY() >= viewPoint.y && 
            rect.getMaxX() <= viewPoint.x + viewSize.width && 
            rect.getMaxY() <= viewPoint.y + viewSize.height)
        {
            return VFX_TRUE;
        }
        
    }
    else
    {
        VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
        VfxPoint parentViewPoint;
        VfxSize parentViewSize;
        
        viewPoint = hLayout->getViewPosition();
        viewSize = hLayout->getViewDimension();

        parentViewPoint = convertPointFrom(viewPoint, m_parentViewFrame);
        parentViewSize = m_parentViewFrame->getSize();

        rect = hLayout->queryCellRect(Pos);

        if (rect.getMinX() >= parentViewPoint.x && 
            rect.getMinY() >= parentViewPoint.y && 
            rect.getMaxX() <= parentViewPoint.x + parentViewSize.width && 
            rect.getMaxY() <= parentViewPoint.y + parentViewSize.height)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;

}


VfxBool VappMediaWallMenu::getIsCellVisiable(VcpMenuPos Pos)
{
    VfxPoint viewPoint;
    VfxSize viewSize;
    VfxRect rect;
    VappMediaWallCell* cell = (VappMediaWallCell*)getCellIfPresent(Pos.group, Pos.pos);;

    if (!cell)
        return VFX_FALSE;

    if (m_style == PORTRAIT)
    {
        VappMediaWallVerLayout *vLayout = (VappMediaWallVerLayout*)m_layout;
        viewPoint = vLayout->getViewPosition();
        viewSize = vLayout->getViewDimension();
        rect = vLayout->queryCellRect(Pos);
      
        if (rect.getMinX() >= viewPoint.x && 
            rect.getMinY() >= viewPoint.y + viewSize.height && 
            rect.getMaxX() >= viewPoint.x && 
            rect.getMaxY() >= viewPoint.y + viewSize.height)
        {
            return VFX_FALSE;
        }
        else if (rect.getMinX() >= viewPoint.x && 
                 rect.getMinY() <= viewPoint.y && 
                 rect.getMaxX() >= viewPoint.x && 
                 rect.getMaxY() <= viewPoint.y)
        {
            return VFX_FALSE;
        }

    }
    else
    {
        VappMediaWallHorLayout* hLayout = (VappMediaWallHorLayout*)m_layout;
        VfxPoint parentViewPoint;
        VfxSize parentViewSize;
        
        viewPoint = hLayout->getViewPosition();

        parentViewPoint = convertPointFrom(viewPoint, m_parentViewFrame);
        parentViewSize = m_parentViewFrame->getSize();

        rect = hLayout->queryCellRect(Pos);

        if (rect.getMinX() >= parentViewPoint.x + parentViewSize.width && 
            rect.getMinY() >= parentViewPoint.y && 
            rect.getMaxX() >= parentViewPoint.x + parentViewSize.width && 
            rect.getMaxY() >= parentViewPoint.y)
        {
            return VFX_FALSE;
        }
        else if (rect.getMinX() <= parentViewPoint.x && 
                 rect.getMinY() >= parentViewPoint.y && 
                 rect.getMaxX() <= parentViewPoint.x && 
                 rect.getMaxY() >= parentViewPoint.y)
        {
            return VFX_FALSE;
        }

    }

    return VFX_TRUE;    

}


void VappMediaWallMenu::setCameraPara(VfxFloat cameraDistance)
{
    m_camera.setCamera(
                1.0f,
                1.0f, 
                getParentFrame()->getSize().width / 2, 
                getParentFrame()->getSize().height / 2, 
                VfxFloat(NEARPLANE), 
                cameraDistance, 
                VfxFloat(CAMERAUP),
                0.0f, 
                0.0f);
    
    m_cameraDistance = cameraDistance;    
    m_model.setTranslation(-(getParentFrame()->getSize().width/2), -(getParentFrame()->getSize().height/2), 0);
}


void VappMediaWallMenu::setOnDragMatrix()
{
    setCameraPara(m_cameraDistance);
            
    VfxMatrix4x4 rotateByY, totalProject;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(m_rotateAngle));
    totalProject = m_camera * rotateByY * m_model;

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    m_decreaseTimer->stop();

    getParentFrame()->setTransform(tempTransform);
}


void VappMediaWallMenu::setOnDragTimeLine()
{
    setCameraPara(m_cameraDistance);
            
    VfxMatrix4x4 rotateByY, totalProject;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(m_rotateAngle));
    totalProject = m_camera * rotateByY * m_model;

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    m_decreaseTimer->stop();

    m_rotateTimeline->setTarget(getParentFrame());
    m_rotateTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_rotateTimeline->setDurationTime(500);
    m_rotateTimeline->setRepeatCount(1);
    m_rotateTimeline->setIsFromCurrent(VFX_TRUE);
    m_rotateTimeline->setToValue(tempTransform);
    m_rotateTimeline->m_signalStopped.disconnect(this,&VappMediaWallMenu::onRotateTimeLineStop);
    m_rotateTimeline->start();
}


/*****************************************************************************
 * Class VappMediaWallSrc
 *****************************************************************************/
VappMediaWallScr::VappMediaWallScr(vadp_mediawall_init_struct init) :
    m_viewPanel(NULL),
    m_menuPanel(NULL),
    m_menu(NULL), 
    m_reflection(NULL),
    m_fileCount(0), 
    m_fileName(NULL),
    m_menuShadowLeft(NULL),
    m_menuShadowRight(NULL)
{
    m_cellCount = init.cellcount;
    m_cellNumPerRow = init.cellnum_per_row;
    m_cellHeight = init.cell_height;
    m_cellWidth = init.cell_width;
    m_cellInnerX = init.cell_inner_x;
    m_cellInnerY = init.cell_inner_y;
    m_highLightIdx = init.highlight_idx;
    m_lskOn = (VfxBool)init.is_lsk_on;
    m_titleStrId = init.title_string_id;
}


void VappMediaWallScr::onLayoutReset(VcpBaseMenu* sender)
{
    drawViewMode(m_viewMode);
    m_state = STATE_NORMAL;
}


void VappMediaWallScr::onInit()
{
    VfxAppCatScr::onInit();
    VfxS32 mode = 0;

    if (m_viewMode == VIEW_PORTRAIT)
    {
        mode = VappMediaWallMenu::PORTRAIT;
    }
    else if(m_viewMode == VIEW_LANDSCAPE)
    {
        mode = VappMediaWallMenu::LANDSCAPE;
    }

    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);            
    VFX_OBJ_CREATE(m_titleBg, VfxImageFrame, this); 
    VFX_OBJ_CREATE(m_skBarBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_statusBarBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    VFX_OBJ_CREATE(m_fileName, VcpMarquee, this);
    VFX_OBJ_CREATE(m_hintStr, VcpMarquee, this);
    VFX_OBJ_CREATE(m_fileCount, VcpMarquee, this);
    if (m_cellCount)
    {
        VFX_OBJ_CREATE(m_viewPanel, VfxFrame, this);
        VFX_OBJ_CREATE(m_menuPanel, VfxFrame, m_viewPanel);
        VFX_OBJ_CREATE_EX(m_menu, VappMediaWallMenu, m_menuPanel, (mode, m_viewPanel));
        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  
        VFX_OBJ_CREATE(m_reflection, VcpContentClone, m_menuPanel);
        VFX_OBJ_CREATE(m_menuShadowLeft, VfxImageFrame, m_menuPanel);
        VFX_OBJ_CREATE(m_menuShadowRight, VfxImageFrame, m_menuPanel);
        #endif
    }
    VFX_OBJ_CREATE(m_butLsk, VappMediaWallButton, this);
    VFX_OBJ_CREATE(m_butRsk, VappMediaWallButton, this);
    VFX_OBJ_CREATE(m_butRotate, VappMediaWallButton, this);
    VFX_OBJ_CREATE(m_titleShadow, VfxImageFrame, this); 
    VFX_OBJ_CREATE(m_skBarShadow, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageHighLight, VfxImageFrame, this);
    
    if (m_menu)
        m_menu->m_signalResetLayout.connect(this, &VappMediaWallScr::onLayoutReset);

    m_timer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timer->setDuration(VappMediaWallMenu::CELL_FADEOUT_DURATION);
    m_timer->m_signalTick.connect(this, &VappMediaWallScr::onTimerTick);
    
    m_titleBg->setIsCached(VFX_TRUE);       
    m_titleBg->setResId(VAPP_MEDIAWALL_IMG_TITLE);

    m_titleShadow->setIsCached(VFX_TRUE);
    m_titleShadow->setResId(VAPP_MEDIAWALL_IMG_TITLE_SHADOW);
    m_titleShadow->setIsUnhittable(VFX_TRUE);

    m_skBarBg->setIsCached(VFX_TRUE);
    m_skBarBg->setResId(VAPP_MEDIAWALL_IMG_SOFTKEYBAR_BG);

    m_skBarShadow->setIsCached(VFX_TRUE);
    m_skBarShadow->setResId(VAPP_MEDIAWALL_IMG_SOFTKEYBAR_SHADOW);
    m_skBarShadow->setIsUnhittable(VFX_TRUE);

    m_statusBarBg->setIsCached(VFX_TRUE);
    m_statusBarBg->setResId(VAPP_MEDIAWALL_IMG_STATUSBAR_BG);

    m_butLsk->setIsCached(VFX_TRUE);
    m_butRsk->setIsCached(VFX_TRUE);
    m_butRotate->setIsCached(VFX_TRUE);

    m_imageHighLight->setResId(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
    m_imageHighLight->setHidden(VFX_TRUE);

    m_titleBg->setSize(IMG_TITLE_WIDTH, IMG_TITLE_HEIGHT);
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_titleShadow->setSize(IMG_TITLE_SHADOW_WIDTH, IMG_TITLE_SHADOW_HEIGHT);
    m_titleShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_skBarBg->setSize(IMG_SOFTKEYBAR_BG_WIDTH, IMG_SOFTKEYBAR_BG_HEIGHT);
    m_skBarBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_skBarShadow->setSize(IMG_SOFTKEYBAR_SHADOW_WIDTH, IMG_SOFTKEYBAR_SHADOW_HEIGHT);
    m_skBarShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_statusBarBg->setSize(IMG_STATUSBAR_BG_WIDTH, IMG_STATUSBAR_BG_HEIGHT);
    m_statusBarBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);


#ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
    if (m_menuShadowLeft && m_menuShadowRight)
    {
        m_menuShadowLeft->setResId(VAPP_MEDIAWALL_IMG_MENU_SHADOW_LEFT);
        m_menuShadowLeft->setHidden(VFX_TRUE);

        m_menuShadowRight->setResId(VAPP_MEDIAWALL_IMG_MENU_SHADOW_RIGHT);
        m_menuShadowRight->setHidden(VFX_TRUE);

        m_menuShadowLeft->setSize(IMG_MENU_SHADOW_WIDTH, IMG_MENU_SHADOW_HEIGHT);
        m_menuShadowLeft->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        m_menuShadowRight->setSize(IMG_MENU_SHADOW_WIDTH, IMG_MENU_SHADOW_HEIGHT);
        m_menuShadowRight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }
#endif
    
    drawViewMode(m_viewMode);
    
    m_butLsk->m_eventPenUp.connect(this, &VappMediaWallScr::onEventUpLsk);
    m_butRsk->m_eventPenUp.connect(this, &VappMediaWallScr::onEventUpRsk);
    m_butRotate->m_eventPenUp.connect(this, &VappMediaWallScr::onEventUpRotate);

    if (m_menu)
    {
        m_menu->m_eventFocusChange.connect(this, &VappMediaWallScr::onEventFocusChange);
        if (m_viewMode == VIEW_PORTRAIT)
           m_menu->m_eventNotifyNewFocus.connect(this, &VappMediaWallScr::onEventRedrawFileCount);

        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
        m_menu->m_eventRotateTimelineStart.connect(this, &VappMediaWallScr::onEventRotateTimelineStart);
        m_menu->m_eventRotateTimelineEnd.connect(this, &VappMediaWallScr::onEventRotateTimelineEnd);
        #endif
    }

    registerKeyHandler(VFX_KEY_CODE_LSK);
    registerKeyHandler(VFX_KEY_CODE_RSK);
    m_state = STATE_NORMAL;
}


void VappMediaWallScr::onDeinit()
{
    if (m_timer->getIsEnabled())
    {
        if (m_viewMode == VIEW_PORTRAIT)
            m_viewMode = VIEW_LANDSCAPE;
        else
            m_viewMode = VIEW_PORTRAIT;
    }
    m_timer->stop();
    VfxAppCatScr::onDeinit();
}


void VappMediaWallScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (m_viewMode == VIEW_LANDSCAPE)
        param.rotateTo = VFX_SCR_ROTATE_TYPE_LANDSCAPE;
    else
        param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}


void VappMediaWallScr::onRotate(const VfxScreenRotateParam &param)
{
    VfxRect parentBounds = getParentFrame()->getBounds();
    setSize(parentBounds.size);

    drawViewMode(m_viewMode);
}


void VappMediaWallScr::onEventUpLsk(VfxPenEvent &event)
{
    if (m_butLsk->containPoint(event.getRelPos(m_butLsk)))
    {
        if(m_menu)
            m_menu->stopScrolling();

        if (m_viewMode == VIEW_LANDSCAPE)
        {
            m_butLsk->setHidden(VFX_TRUE);
            m_butRsk->setHidden(VFX_TRUE);
            m_butRotate->setHidden(VFX_TRUE);
        }
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        
        vadp_mediawall_lsk_up();
    }
}


void VappMediaWallScr::onEventDownLsk(VfxPenEvent &event)
{

}


void VappMediaWallScr::onEventUpRsk(VfxPenEvent &event)
{
    if (m_butRsk->containPoint(event.getRelPos(m_butRsk)))
    {
        vadp_mediawall_rsk_up();
    }
}


void VappMediaWallScr::onEventDownRsk(VfxPenEvent &event)
{

}


void VappMediaWallScr::onEventUpRotate(VfxPenEvent &event)
{
//#define EXTEND_LEN (10)

    if (m_butRotate->containPoint(event.getRelPos(m_butRotate)))
    {
        onRotate();
    }

}


void VappMediaWallScr::onEventFocusChange(VfxS32 index)
{
    if (m_cellCount)
    {
        setFileCountString(index);
//      setFileNameString(index);
        vadp_mediawall_set_highlight(index);
    }
}


void VappMediaWallScr::onEventRedrawFileCount(VfxS32 index)
{
    if (m_cellCount)
    {
        setFileCountString(index);
    }
}


void VappMediaWallScr::onEventRotateTimelineStart(VfxS32 rotateAngle)
{        
    if (m_viewMode == VIEW_LANDSCAPE && 
        m_menuShadowLeft && 
        m_menuShadowRight)
    {
        if (rotateAngle > 0)
        {
            m_menuShadowLeft->setHidden(VFX_FALSE);
            m_menuShadowRight->setHidden(VFX_TRUE);
        }
        else
        {
            m_menuShadowLeft->setHidden(VFX_TRUE);
            m_menuShadowRight->setHidden(VFX_FALSE);
        }
    }    
}


void VappMediaWallScr::onEventRotateTimelineEnd(VfxS32 rotateAngle)
{
    if (m_viewMode == VIEW_LANDSCAPE && 
        m_menuShadowLeft && 
        m_menuShadowRight)
    {
        m_menuShadowLeft->setHidden(VFX_TRUE);
        m_menuShadowRight->setHidden(VFX_TRUE);
    } 
}


VfxBool VappMediaWallScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_LSK)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            m_butLsk->setDraw(VFX_PEN_EVENT_TYPE_DOWN);
        }
        else if(event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            if (!m_timer->getIsEnabled())
            {
                m_butLsk->setDraw(VFX_PEN_EVENT_TYPE_UP);
                
                if(m_menu)
                    m_menu->stopScrolling();

                if (m_viewMode == VIEW_LANDSCAPE)
                {
                    m_butLsk->setHidden(VFX_TRUE);
                    m_butRsk->setHidden(VFX_TRUE);
                    m_butRotate->setHidden(VFX_TRUE);
                }
                VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                renderer->mustShowNextFrame();
        
                vadp_mediawall_lsk_up();
            }
            return VFX_TRUE;
        }
    }
    else if(event.keyCode == VFX_KEY_CODE_RSK)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            m_butRsk->setDraw(VFX_PEN_EVENT_TYPE_DOWN);
        }
        else if(event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            if (!m_timer->getIsEnabled())
            {
                m_butRsk->setDraw(VFX_PEN_EVENT_TYPE_UP);
                vadp_mediawall_rsk_up();
            }
            return VFX_TRUE;            
        }
    }
#if !defined(__MMI_MAINLCD_320X240__)    
    else if(event.keyCode == VFX_KEY_CODE_ENTER)
    {
        if (m_butRotate->getHidden() == VFX_FALSE)
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_butRotate->setDraw(VFX_PEN_EVENT_TYPE_DOWN);
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                m_butRotate->setDraw(VFX_PEN_EVENT_TYPE_UP);
                onRotate();
            }
        }
        return VFX_TRUE;
    }
#endif
    return VfxAppCatScr::onKeyInput(event);
}


void VappMediaWallScr::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_ROTATE_TIMER, m_state);
    
    if (m_state == STATE_NORMAL)
    {
        if (m_menu)
        {
            m_menu->onCellFadeOut();
        }
        m_state = STATE_SWITCHING;
    }
    else if (m_state == STATE_SWITCHING)
    {
        m_timer->stop();

        vadp_mediawall_srv_pause_bgdecode();
        
        if (m_menu)
            m_menu->onReset();

        if (m_viewMode == VIEW_PORTRAIT)
        {
            m_viewMode = VIEW_LANDSCAPE;
            if (m_menu)
                m_menu->setStyle(VappMediaWallMenu::LANDSCAPE);
            /* This is a trick, need FW support further */
            vadp_mediawall_set_rotating(VFX_TRUE);
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            GoBackHistory();
            vadp_mediawall_check_is_mediachange();
        }
        else if (m_viewMode == VIEW_LANDSCAPE)
        {
            m_viewMode = VIEW_PORTRAIT;
            if (m_menu)
                m_menu->setStyle(VappMediaWallMenu::PORTRAIT);
            /* This is a trick, need FW support further */
            vadp_mediawall_set_rotating(VFX_TRUE);
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            GoBackHistory();
            vadp_mediawall_check_is_mediachange();
        }
    }
}


VfxS32 VappMediaWallScr::getHighLightIndex()
{
    if (m_menu)
        return m_menu->getHighLightIdx();
    else
        return 0;
}


VfxS32 VappMediaWallScr::getDisplayIndex()
{
    if (m_menu)
        return m_menu->getDisplayIdx();
    else
        return 0;
}


void VappMediaWallScr::setFileCountString(VfxS32 index)
{
    if (m_cellCount)
    {
        VfxWString temp;
        temp.format("%d/%d", index + 1, m_cellCount);
        m_fileCount->setAutoResized(VFX_TRUE);
        m_fileCount->setMovableFrame(temp, VCP_MARQUEE_DEFAULT_FONT);
        m_fileCount->startScroll(); 
    }
}


void VappMediaWallScr::changeLsk(VfxU16 strID)
{
    if (strID > 0)
    {
        m_lskOn = VFX_TRUE;
        m_butLsk->setDisplay(VFX_TRUE);
    }
    else
    {
        m_lskOn = VFX_FALSE;
        m_butLsk->setDisplay(VFX_FALSE);  
    }
}


void VappMediaWallScr::setFileNameString(VfxS32 index)
{
    VfxWString temp;
            
    if (m_cellCount)
    {
        VfxChar filename[256];

        vadp_mediawall_srv_get_filename(index, (void*)filename, 256);

        temp = VFX_WSTR_MEM((const U16*)filename);  
    }
    else
    {
        temp.loadFromRes((VfxResId)m_titleStrId);
    }
    m_fileName->setAutoResized(VFX_TRUE);
    m_fileName->setMovableFrame(temp, VFX_FONT_DESC_SMALL);
    m_fileName->startScroll();  
}


void VappMediaWallScr::setRotate()
{
    VFX_LOG(VFX_INFO, VAPP_MEDIAWALL_SETROTATE);
    onRotate();
}


void VappMediaWallScr::drawViewMode(VfxS32 viewmode)
{
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

    m_lcdWidth = mainScreenSize.width;
    m_lcdHeight = mainScreenSize.height;

    if (m_cellCount)
        m_hintStr->setHidden(VFX_TRUE);

    if (m_lskOn)
        m_butLsk->setHidden(VFX_FALSE);
    else
        m_butLsk->setHidden(VFX_TRUE);

#if defined(MOTION_SENSOR_SUPPORT) && defined(__MTK_TARGET__)
    m_butRotate->setHidden(VFX_TRUE);
#endif
    m_fileName->setHidden(VFX_TRUE);

    if (viewmode == VIEW_PORTRAIT)
    {
//      VFX_ASSERT(m_cellWidth * m_cellNumPerRow <= m_lcdWidth);
        
        m_viewMode = viewmode;
        m_butLsk->setImage(VAPP_MEDIAWALL_IMG_SOFTKEY_LSK_INSET, VAPP_MEDIAWALL_IMG_SOFTKEY_LSK_INSET);
        m_butLsk->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
        m_butRsk->setImage(VAPP_MEDIAWALL_IMG_SOFTKEY_RSK_INSET, VAPP_MEDIAWALL_IMG_SOFTKEY_RSK_INSET);
        m_butRsk->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
    #if !defined(__MMI_MAINLCD_320X240__) 
        m_butRotate->setImage(VAPP_MEDIAWALL_IMG_PORTRAIT_ROTATE, VAPP_MEDIAWALL_IMG_PORTRAIT_ROTATE);
        m_butRotate->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
    #endif
        m_butLsk->setAnchor(VfxFPoint(0.5, 0.5));
        m_butRsk->setAnchor(VfxFPoint(0.5, 0.5));
    #if !defined(__MMI_MAINLCD_320X240__) 
        m_butRotate->setAnchor(VfxFPoint(0.5, 0.5));
    #endif    
        m_butLsk->setPos(VfxPoint(SK_BUT_LSK_VER_CENTER_OFFSET_X, SK_BUT_LSK_VER_CENTER_OFFSET_Y)); 
        m_butRsk->setPos(VfxPoint(SK_BUT_RSK_VER_CENTER_OFFSET_X, SK_BUT_RSK_VER_CENTER_OFFSET_Y));
    #if !defined(__MMI_MAINLCD_320X240__) 
        m_butRotate->setPos(VfxPoint(SK_BUT_ROT_VER_CENTER_OFFSET_X, SK_BUT_ROT_VER_CENTER_OFFSET_Y));
    #endif    
        if (m_menu)
        {
            m_viewPanel->setPos(0, m_statusBarBg->getBounds().getHeight() + m_titleBg->getBounds().getHeight());
            m_viewPanel->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth, 
                                        m_lcdHeight - m_skBarBg->getBounds().getHeight() - m_statusBarBg->getBounds().getHeight() - m_titleBg->getBounds().getHeight()));

            m_viewPanel->setIsCached(VFX_TRUE);
            m_viewPanel->setCacheMode(VFX_CACHE_MODE_PREVENT);
            
            m_menuPanel->setPos(0, 0);
            m_menuPanel->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_viewPanel->getBounds().getWidth(), 
                                        m_viewPanel->getBounds().getHeight()));

            m_menuPanel->setIsCached(VFX_TRUE);
            
            m_menu->setPos(VfxPoint(0, 0));
            m_menu->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_menuPanel->getBounds().getWidth(), 
                                        m_menuPanel->getBounds().getHeight()));
            m_menu->setCutLength(0);
        }
        m_fileName->setHalign(VcpMarquee::HALIGN_CENTER);
        m_fileName->setValign(VcpMarquee::VALIGN_CENTER);
        m_fileName->setPos(VfxPoint(FILENAME_START_OFFSET_X, FILENAME_START_OFFSET_Y));
        m_fileName->setBounds(VfxRect(
                                    0, 
                                    0, 
                                    FILENAME_END_OFFSET_X - FILENAME_START_OFFSET_X + 1, 
                                    FILENAME_END_OFFSET_Y - FILENAME_START_OFFSET_Y + 1));

        m_fileCount->setHidden(VFX_FALSE);
        m_fileCount->setHalign(VcpMarquee::HALIGN_CENTER);
        m_fileCount->setValign(VcpMarquee::VALIGN_CENTER);
//      m_fileCount->setAnchor(VfxFPoint(0.5, 0.5));
        m_fileCount->setPos(VfxPoint(FILECOUNT_START_OFFSET_X, FILECOUNT_START_OFFSET_Y));
        m_fileCount->setBounds(VfxRect(
                                    0, 
                                    0, 
                                    FILECOUNT_END_OFFSET_X - FILECOUNT_START_OFFSET_X + 1, 
                                    FILECOUNT_END_OFFSET_Y - FILECOUNT_START_OFFSET_Y + 1));

        m_hintStr->setPos(VfxPoint(0, m_statusBarBg->getBounds().getHeight() + m_titleBg->getBounds().getHeight()));
        m_hintStr->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth, 
                                        m_lcdHeight - m_skBarBg->getBounds().getHeight() - m_statusBarBg->getBounds().getHeight() - m_titleBg->getBounds().getHeight()));
        
        setFileCountString(m_highLightIdx);
//      setFileNameString(m_highLightIdx);

        m_statusBar->setHidden(VFX_FALSE);
        m_statusBar->setPos(VfxPoint(0,0));     
        m_titleBg->setHidden(VFX_FALSE);
        m_titleBg->setPos(VfxPoint(0,m_statusBarBg->getBounds().getHeight()));
        m_titleShadow->setHidden(VFX_FALSE);
        m_titleShadow->setPos(VfxPoint(0,m_titleBg->getPos().y + m_titleBg->getBounds().getHeight()));
        m_skBarBg->setHidden(VFX_FALSE);
        m_skBarBg->setPos(VfxPoint(0,m_lcdHeight - m_skBarBg->getBounds().getHeight()));
        m_skBarShadow->setHidden(VFX_FALSE);
        m_skBarShadow->setPos(VfxPoint(0,m_skBarBg->getPos().y - m_skBarShadow->getBounds().getHeight()));

        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  
        if (m_reflection)
            m_reflection->setHidden(VFX_TRUE);
        #endif
    }
    else if (viewmode == VIEW_LANDSCAPE)
    {
//      VFX_ASSERT(m_cellHeight * m_cellNumPerRow <= m_lcdHeight);
        
        m_viewMode = viewmode;
        m_butLsk->setImage(VAPP_MEDIAWALL_IMG_SOFTKEY_LSK, VAPP_MEDIAWALL_IMG_SOFTKEY_LSK);
        m_butLsk->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
        m_butRsk->setImage(VAPP_MEDIAWALL_IMG_SOFTKEY_RSK, VAPP_MEDIAWALL_IMG_SOFTKEY_RSK);
        m_butRsk->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
        m_butRotate->setImage(VAPP_MEDIAWALL_IMG_LANDSCAPE_ROTATE, VAPP_MEDIAWALL_IMG_LANDSCAPE_ROTATE);
        m_butRotate->setImageHighLight(VAPP_MEDIAWALL_IMG_BUT_HIGHLIGHT);
        
        m_butLsk->setAnchor(VfxFPoint(0.5, 0.5));
        m_butRsk->setAnchor(VfxFPoint(0.5, 0.5));
        m_butRotate->setAnchor(VfxFPoint(0.5, 0.5));
        
        m_butLsk->setPos(VfxPoint(SK_BUT_LSK_HOR_CENTER_OFFSET_X, SK_BUT_LSK_HOR_CENTER_OFFSET_Y));     
        m_butRsk->setPos(VfxPoint(SK_BUT_RSK_HOR_CENTER_OFFSET_X, SK_BUT_RSK_HOR_CENTER_OFFSET_Y));
        m_butRotate->setPos(VfxPoint(SK_BUT_ROT_HOR_CENTER_OFFSET_X, SK_BUT_ROT_HOR_CENTER_OFFSET_Y));

        if (m_menu)
        {
            m_viewPanel->setPos(0, 0);
            m_viewPanel->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth, 
                                        m_lcdHeight));
            m_viewPanel->setIsCached(VFX_TRUE);
            
            m_menuPanel->setPos(-VappMediaWallMenu::BASEPLANE_EXTEND, 0);
        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  
            m_menuPanel->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth + 2 * VappMediaWallMenu::BASEPLANE_EXTEND, 
                                        m_lcdHeight + VappMediaWallMenu::REFLECTION_INTERVAL + VappMediaWallMenu::REFLECTION_HEIGHT));
        #else
            m_menuPanel->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        SK_BUT_LSK_HOR_CENTER_OFFSET_X - m_imageHighLight->getBounds().getWidth()/2 - 1, 
                                        m_lcdHeight));
        #endif      
            m_menuPanel->setIsCached(VFX_TRUE);
            m_menuPanel->setBgColor(VFX_COLOR_BLACK);
            m_menuPanel->setTransform(VfxTransform(VFX_TRANSFORM_TYPE_MATRIX3X3));
                
            m_menu->setPos(VfxPoint(0, 0));
        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__
            m_menu->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth + 2 * VappMediaWallMenu::BASEPLANE_EXTEND, 
                                        m_lcdHeight));
        #else
            m_menu->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        SK_BUT_LSK_HOR_CENTER_OFFSET_X - m_imageHighLight->getBounds().getWidth()/2 - 1, 
                                        m_lcdHeight));        
        #endif
//            m_menu->setBgColor(VFX_COLOR_BLACK);
            m_menu->setCutLength(0);
            m_menu->setIsCached(VFX_TRUE);
            m_menu->setCacheMode(VFX_CACHE_MODE_PREVENT);

        #ifdef __VAPP_MEDIAWALL_PERSPECTIVE_REFLECTION_SUPPORT__  
            if (m_reflection)
            {
                VFX_OBJ_CLOSE(m_reflection);
                VFX_OBJ_CREATE(m_reflection, VcpContentClone, m_menuPanel);
            
                m_reflection->setPos(0, 
                                     m_menu->getPos().y + m_menu->getBounds().getHeight() + VappMediaWallMenu::REFLECTION_INTERVAL);

                m_reflection->setSize(m_menu->getBounds().getWidth(), VappMediaWallMenu::REFLECTION_HEIGHT);
                m_reflection->setTargetFrame(m_menu);
                m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
                m_reflection->setBgColor(VFX_COLOR_BLACK);
                m_reflection->setTargetRect(VfxRect(0,
                                                    m_menu->getBounds().getHeight() - VappMediaWallMenu::REFLECTION_HEIGHT,
                                                    m_menu->getBounds().getWidth(),
                                                    VappMediaWallMenu::REFLECTION_HEIGHT));
                m_reflection->setHidden(VFX_FALSE);
            }
            if (m_menuShadowLeft && m_menuShadowRight)
            {
                m_menuShadowLeft->setPos(0, 0);
                m_menuShadowRight->setPos(m_menuPanel->getSize().width - m_menuShadowRight->getSize().width, 0);
            }
        #endif
        }

        m_fileCount->setHidden(VFX_TRUE);
        m_statusBar->setHidden(VFX_TRUE);
        m_titleBg->setHidden(VFX_TRUE);
        m_titleShadow->setHidden(VFX_TRUE);
        m_skBarBg->setHidden(VFX_TRUE);
        m_skBarShadow->setHidden(VFX_TRUE);
        m_statusBarBg->setHidden(VFX_TRUE);
        m_hintStr->setPos(VfxPoint(0, 0));
        m_hintStr->setBounds(VfxRect(
                                        0, 
                                        0, 
                                        m_lcdWidth, 
                                        m_lcdHeight));
    }
    if (m_menu)
    {
        m_menu->setCellCount(m_cellCount);
        m_menu->setCellNumPerRow(m_cellNumPerRow);
        m_menu->setCellWidth(m_cellWidth);
        m_menu->setCellHeight(m_cellHeight);
        m_menu->setCellInnerX(m_cellInnerX);
        m_menu->setCellInnerY(m_cellInnerY);
        m_menu->setHighLightIdx(m_highLightIdx);
        m_menu->setCameraPara();
    }
    m_hintStr->setHalign(VcpMarquee::HALIGN_CENTER);
    m_hintStr->setValign(VcpMarquee::VALIGN_CENTER);
    m_hintStr->setMovableFrame(VFX_WSTR_RES(STR_ID_FMGR_NO_FILES), VCP_MARQUEE_DEFAULT_FONT);
    m_hintStr->startScroll();

    vadp_mediawall_set_highlight(m_highLightIdx);
    vadp_mediawall_srv_resume_bgdecode();
}


void VappMediaWallScr::onRotate()
{
#define EXTEND_LEN (10)

    setIsDisabled(VFX_TRUE);
    if (m_viewMode == VIEW_PORTRAIT)
    {
        VfxS32 max_height; 
        max_height = VFX_MAX(m_statusBar->getBounds().getHeight(), m_fileCount->getBounds().getHeight());
        max_height = VFX_MAX(max_height, m_statusBarBg->getBounds().getHeight());
        max_height = VFX_MAX(max_height, m_skBarBg->getBounds().getHeight());
            
        m_statusBar->setAutoAnimate(VFX_TRUE);
        m_statusBar->setPos(VfxPoint(0, -(max_height + EXTEND_LEN)));
        m_statusBarBg->setAutoAnimate(VFX_TRUE);
        m_statusBarBg->setPos(VfxPoint(0, -(max_height + EXTEND_LEN)));
        m_fileName->setAutoAnimate(VFX_TRUE);
        m_fileName->setPos(VfxPoint(m_fileName->getPos().x, -(max_height + EXTEND_LEN)));
        m_fileCount->setAutoAnimate(VFX_TRUE);
        m_fileCount->setPos(VfxPoint(m_fileCount->getPos().x, -(max_height + EXTEND_LEN)));
        m_titleBg->setAutoAnimate(VFX_TRUE);
        m_titleBg->setPos(VfxPoint(0, -(max_height + EXTEND_LEN)));
        m_titleShadow->setAutoAnimate(VFX_TRUE);
        m_titleShadow->setPos(VfxPoint(0, -(max_height + EXTEND_LEN)));
        m_butRotate->setAutoAnimate(VFX_TRUE);
        m_butRotate->setPos(VfxPoint(m_butRotate->getPos().x, m_lcdHeight + max_height + EXTEND_LEN));
        m_skBarBg->setAutoAnimate(VFX_TRUE);
        m_skBarBg->setPos(VfxPoint(0, m_lcdHeight + max_height + EXTEND_LEN));
        m_skBarShadow->setAutoAnimate(VFX_TRUE);
        m_skBarShadow->setPos(VfxPoint(0, m_lcdHeight + max_height + EXTEND_LEN));
        m_butLsk->setAutoAnimate(VFX_TRUE);
        m_butLsk->setPos(VfxPoint(m_butLsk->getPos().x, m_lcdHeight + max_height + EXTEND_LEN));
        m_butRsk->setAutoAnimate(VFX_TRUE);
        m_butRsk->setPos(VfxPoint(m_butRsk->getPos().x, m_lcdHeight + max_height + EXTEND_LEN));
    }
    else if (m_viewMode == VIEW_LANDSCAPE)
    {
        VfxS32 max_width; 
        max_width = VFX_MAX(m_butLsk->getBounds().getWidth(), m_butRsk->getBounds().getWidth());
        max_width = VFX_MAX(max_width, m_butRotate->getBounds().getWidth());

        m_butLsk->setAutoAnimate(VFX_TRUE);
        m_butLsk->setPos(VfxPoint(m_lcdWidth + max_width + EXTEND_LEN, m_butLsk->getPos().y));
        m_butRsk->setAutoAnimate(VFX_TRUE);
        m_butRsk->setPos(VfxPoint(m_lcdWidth + max_width + EXTEND_LEN, m_butRsk->getPos().y));
        m_butRotate->setAutoAnimate(VFX_TRUE);
        m_butRotate->setPos(VfxPoint(m_lcdWidth + max_width + EXTEND_LEN, m_butRotate->getPos().y));          
    }
    m_hintStr->setAutoAnimate(VFX_TRUE);
    m_hintStr->setOpacity(0.0f);

    m_timer->start();
}

#endif /* __MMI_VUI_MEDIAWALL__ */
