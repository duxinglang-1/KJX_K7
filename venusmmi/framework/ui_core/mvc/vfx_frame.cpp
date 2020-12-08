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
 *  vfx_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame.h"

#include "vfx_draw_context.h"
#include "vfx_frame_filter.h"
#include "vfx_owner_draw.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"
#include "vfx_renderer.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_material.h"
#include "vfx_world.h"
#endif

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vrt_datatype.h"
#include "vfx_transform.h"
#include "vfx_image_src.h"
#include "vfx_signal.h"
#include "vrt_canvas.h"
#include "vfx_input_event.h"

#include <string.h>


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


#define VFX_FRAME_PROP_ID_TRANSFORM        0x10100
#define VFX_FRAME_PROP_ID_BORDER_COLOR     0x10101
#define VFX_FRAME_PROP_ID_BORDER_WIDTH     0x10102
#define VFX_FRAME_PROP_ID_FILTER           0x10104
#define VFX_FRAME_PROP_ID_FILTER_TIMING    0x10105
#define VFX_FRAME_PROP_ID_FPE_USER_0       0x10106
#define VFX_FRAME_PROP_ID_OWNER_DRAW       0x10107
#define VFX_FRAME_PROP_ID_QUALITY          0x10108
#define VFX_FRAME_PROP_ID_CACHE_MODE       0x10109
#define VFX_FRAME_PROP_ID_OPAQUE_MODE      0x1010A
#define VFX_FRAME_PROP_ID_CULLING_TYPE     0x1010B
#define VFX_FRAME_PROP_ID_HINTS            0x1010C
#define VFX_FRAME_PROP_ID_OPACITY          0x1010D
#define VFX_FRAME_PROP_ID_CONTENT_PLACE    0x1010E
#define VFX_FRAME_PROP_ID_BG_COLOR         0x1010F
#define VFX_FRAME_PROP_ID_POS_Z            0x10110
#define VFX_FRAME_PROP_ID_PROP_EFFECT      0x10111
#define VFX_FRAME_PROP_ID_ALIGNER          0x10112
#define VFX_FRAME_PROP_ID_LAYER_HDL        0x10113
#define VFX_FRAME_PROP_ID_FALLBACK_IMAGE   0x10114
#define VFX_FRAME_PROP_ID_PROP_MONITOR     0x10118

/***************************************************************************** 
 * Class VfxVirtualTimeline
 *****************************************************************************/

class VfxVirtualTimeline : public VfxBaseTimeline
{
    VFX_DECLARE_NO_COPY_CLASS(VfxVirtualTimeline);
   
public:
    VfxVirtualTimeline()
    : VfxBaseTimeline(VRT_TYPE_ID_FLOAT)
    {
        setDurationTime(3);
        m_signalStopped.connect(this, &VfxVirtualTimeline::onPreCacheStop);
    }

protected:
    virtual VfxBool onQueryHasFromToValue() const { return VFX_FALSE; }
    virtual void onUpdateTimelineValue() {};    

private:
    // Free precache timeline
    void onPreCacheStop(VfxBaseTimeline *timeline, VfxBool is_stop)
    {
        VFX_OBJ_CLOSE(timeline);
        /* be careful! this has been destroyed */
    }
};


/***************************************************************************** 
 * Class VfxFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_FRAME_CLASS_NAME, VfxFrame, VfxAnimatable);

VfxFrame::VfxFrame() : 
    m_flags(0),
    m_nextFrame(NULL),
    m_firstChildFrame(NULL),
    m_imgContent(),
    m_imgContentCommandIndex(0),
    m_imgContentCommitCounter(0),
    m_prevFrame(NULL),
    m_lastChildFrame(NULL),
    m_parentFrame(NULL),
    m_lastParentFrameNum(0),
    m_pos(VRT_FRAME_DEFAULT_POS),
    //m_posZ(VRT_FRAME_DEFAULT_POS_Z),
    m_bounds(VRT_FRAME_DEFAULT_BOUNDS),
    m_anchor(VRT_FRAME_DEFAULT_ANCHOR),
    //m_bgColor(VRT_FRAME_DEFAULT_BG_COLOR),
    //m_opacity(VRT_FRAME_DEFAULT_OPACITY),
    //m_transform(VRT_FRAME_DEFAULT_TRANSFORM),
    //m_borderColor(VRT_FRAME_DEFAULT_BORDER_COLOR),
    //m_borderWidth(VRT_FRAME_DEFAULT_BORDER_WIDTH),
    //m_content(NULL),
    //m_filter(NULL),
    //m_filterTiming(0.0f),
    //m_fpeUser0(0.0f),
    //m_ownerDraw(NULL),
#ifdef __VENUS_3D_UI_ENGINE__
    m_material(NULL),
    m_world(NULL),
#endif
    //m_contentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER),
    //m_quality(VFX_RENDER_QUALITY_DEFAULT),
    //m_cacheMode(VFX_CACHE_MODE_AUTO),
    //m_opaqueMode(VFX_FRAME_OPAQUE_MODE_AUTO),
    //m_cullingType(VFX_FRAME_CULLING_TYPE_NONE),
    //m_frameHints(VFX_FRAME_HINTS_DEFAULT),
    //m_propertyEffectWatchFrame(NULL),
    //m_propertyEffectCallback(NULL),
    //m_aligner(NULL),
    //m_layerHandle(0),
    m_nullParentListEntry(NULL),
    m_focusChildFrame(NULL),
    m_needBroadcastEvents(0),
    m_childBroadcastEvents(0)
{
}


VfxFrame::~VfxFrame()
{
    // Assert here if loss to call VfxFrame::onDeinit()
    VFX_DEV_ASSERT(m_handle == NULL);
}


const VfxPoint &VfxFrame::getPos() const
{
    return m_pos;
}


VfxFloat VfxFrame::getPosZ() const
{
    VfxFloat *v = (VfxFloat*)getAttachProperty(VFX_FRAME_PROP_ID_POS_Z, sizeof(VfxFloat));
    if(v)
        return *v;
    else
        return VRT_FRAME_DEFAULT_POS_Z;
}


const VfxRect &VfxFrame::getBounds() const
{
    return m_bounds;
}


const VfxFPoint &VfxFrame::getAnchor() const
{
    return m_anchor;
}


const VfxColor &VfxFrame::getBgColor() const
{
    static VfxColor def(VRT_FRAME_DEFAULT_BG_COLOR);
    VfxColor *v = (VfxColor*)getAttachProperty(VFX_FRAME_PROP_ID_BG_COLOR, sizeof(VfxColor));
    if(v)
        return *v;
    else
        return def;
}


VfxFloat VfxFrame::getOpacity() const
{
    VfxFloat *v = (VfxFloat*)getAttachProperty(VFX_FRAME_PROP_ID_OPACITY, sizeof(VfxFloat));
    if(v)
        return *v;
    else
        return VRT_FRAME_DEFAULT_OPACITY;
}


const VfxTransform &VfxFrame::getTransform() const
{
    static VfxTransform def(VRT_FRAME_DEFAULT_TRANSFORM);
    VfxTransform *v = (VfxTransform*)getAttachProperty(VFX_FRAME_PROP_ID_TRANSFORM, sizeof(VfxTransform));
    if(v)
        return *v;
    else
        return def;
}


const VfxColor &VfxFrame::getBorderColor() const
{
    static VfxColor def(VRT_FRAME_DEFAULT_BORDER_COLOR);
    VfxColor *v = (VfxColor*)getAttachProperty(VFX_FRAME_PROP_ID_BORDER_COLOR, sizeof(VfxColor));
    if(v)
        return *v;
    else
        return def;
}


VfxS32 VfxFrame::getBorderWidth() const
{
    VfxS32 *v = (VfxS32*)getAttachProperty(VFX_FRAME_PROP_ID_BORDER_WIDTH, sizeof(VfxS32));
    if(v)
        return *v;
    else
        return VRT_FRAME_DEFAULT_BORDER_WIDTH;
}


VfxFrameContentPlacementTypeEnum VfxFrame::getContentPlacement() const
{
    if (!VFX_FLAG_HAS(m_flags, FLAGS_HAS_CONTENT_PLACEMENT))
    {
        return VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER;
    }
    
    VfxFrameContentPlacementTypeEnum *v = (VfxFrameContentPlacementTypeEnum*)
        getAttachProperty(VFX_FRAME_PROP_ID_CONTENT_PLACE, sizeof(VfxFrameContentPlacementTypeEnum));
    VFX_DEV_ASSERT(v != NULL);

    return *v;
}


VfxFrameFilter *VfxFrame::getFilter() const
{
    if (!VFX_FLAG_HAS(m_flags, FLAGS_HAS_FILTER))
    {
        return NULL;
    }
    
    VfxFrameFilter **v = (VfxFrameFilter **)getAttachProperty(VFX_FRAME_PROP_ID_FILTER, sizeof(VfxFrameFilter *));
    VFX_DEV_ASSERT(v != NULL);
    
    return *v;
}


VfxOwnerDraw *VfxFrame::getOwnerDraw() const
{
    if (!VFX_FLAG_HAS(m_flags, FLAGS_HAS_OWNER_DRAW))
    {
        return NULL;
    }
    
    VfxOwnerDraw **v = (VfxOwnerDraw **)getAttachProperty(VFX_FRAME_PROP_ID_OWNER_DRAW, sizeof(VfxOwnerDraw *));
    VFX_DEV_ASSERT(v != NULL);
    
    return *v;
}


VfxFloat VfxFrame::getFilterTiming() const
{
    VfxFloat *v = (VfxFloat*)getAttachProperty(VFX_FRAME_PROP_ID_FILTER_TIMING, sizeof(VfxFloat));
    if(v)
        return *v;
    else
        return 0.0f;
}


VfxFloat VfxFrame::getFpeUser0() const
{
    VfxFloat *v = (VfxFloat*)getAttachProperty(VFX_FRAME_PROP_ID_FPE_USER_0, sizeof(VfxFloat));
    if(v)
        return *v;
    else
        return 0.0f;
}


VfxBool VfxFrame::getIsUnhittable() const
{
    return VFX_FLAG_HAS(m_flags, FLAGS_UNHITTABLE);
}


VfxBool VfxFrame::getIsOpaque() const
{
    return getOpaqueMode() != VRT_FRAME_OPAQUE_MODE_TRANSLUCENT;
}


VfxRenderQualityEnum VfxFrame::getQuality() const
{
    VfxRenderQualityEnum *v = (VfxRenderQualityEnum*)getAttachProperty(VFX_FRAME_PROP_ID_QUALITY, sizeof(VfxRenderQualityEnum));
    if(v)
        return *v;
    else
        return VFX_RENDER_QUALITY_DEFAULT;
}


VfxBool VfxFrame::getIsCached() const
{
    return VFX_FLAG_HAS(m_flags, FLAGS_CACHED);
}


VfxCacheModeEnum VfxFrame::getCacheMode() const
{
    VfxCacheModeEnum *v = (VfxCacheModeEnum*)getAttachProperty(VFX_FRAME_PROP_ID_CACHE_MODE, sizeof(VfxCacheModeEnum));
    if(v)
        return *v;
    else
        return VFX_CACHE_MODE_AUTO;
}


VfxFrameOpaqueModeEnum VfxFrame::getOpaqueMode() const
{
    VfxFrameOpaqueModeEnum *v = (VfxFrameOpaqueModeEnum*)getAttachProperty(VFX_FRAME_PROP_ID_OPAQUE_MODE, sizeof(VfxFrameOpaqueModeEnum));
    if(v)
        return *v;
    else
        return VFX_FRAME_OPAQUE_MODE_AUTO;
}


VfxFrameCullingTypeEnum VfxFrame::getCullingType() const
{
    VfxFrameCullingTypeEnum *v = (VfxFrameCullingTypeEnum*)getAttachProperty(VFX_FRAME_PROP_ID_CULLING_TYPE, sizeof(VfxFrameCullingTypeEnum));
    if(v)
        return *v;
    else
        return VFX_FRAME_CULLING_TYPE_NONE;
}


VfxBool VfxFrame::getIsZSortChild() const
{
    return VFX_FLAG_HAS(m_flags, FLAGS_Z_SORT_CHILD);
}


void VfxFrame::setPos(const VfxPoint &value)
{
    if (m_pos != value)
    {
        vrt_point_struct fromValue = m_pos;
        vrt_point_struct vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_POS,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        m_pos = value;
    }
}


void VfxFrame::setPosZ(VfxFloat value)
{
    if (getPosZ() != value)
    {
        vrt_float fromValue = getPosZ();
        vrt_float vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_POS_Z,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VRT_FRAME_DEFAULT_POS_Z)
            setAttachProperty(VFX_FRAME_PROP_ID_POS_Z, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_POS_Z, (void*)&value, sizeof(VfxFloat));
    }
}


void VfxFrame::setBounds(const VfxRect &value)
{
    VfxRect oldValue = m_bounds;

    if (m_bounds != value)
    {
        vrt_rect_struct fromValue = m_bounds;
        vrt_rect_struct vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_BOUNDS,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        m_bounds = value;
        
        // Emit the bounds changed signal
        m_signalBoundsChanged.emit(this, oldValue);

        VfxFrameAligner::alignChildFrames(this);
    }
}


void VfxFrame::setAnchor(const VfxFPoint &value)
{
    if (m_anchor != value)
    {
        vrt_fpoint_struct fromValue = m_anchor;
        vrt_fpoint_struct vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_ANCHOR_POINT,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        m_anchor = value;
    }
}


void VfxFrame::setBgColor(const VfxColor &value)
{
    if (getBgColor() != value)
    {
        vrt_color_type fromValue = getBgColor();
        vrt_color_type vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VfxColor(VRT_FRAME_DEFAULT_BG_COLOR))
            setAttachProperty(VFX_FRAME_PROP_ID_BG_COLOR, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_BG_COLOR, (void*)&value, sizeof(VfxColor));
    }
}


void VfxFrame::setOpacity(VfxFloat value)
{
    if (getOpacity() != value)
    {
        vrt_float fromValue = getOpacity();
        vrt_float vrtValue = (vrt_float)value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_OPACITY,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VRT_FRAME_DEFAULT_OPACITY)
            setAttachProperty(VFX_FRAME_PROP_ID_OPACITY, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_OPACITY, (void*)&value, sizeof(VfxFloat));
    }
}


void VfxFrame::setTransform(const VfxTransform &value)
{
    if (getTransform() != value)
    {
        vrt_transform_struct vrtValue, fromValue;
        value.initVrtTransform(vrtValue);
        getTransform().initVrtTransform(fromValue);
        
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_TRANSFORM,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VfxTransform(VRT_FRAME_DEFAULT_TRANSFORM))
            setAttachProperty(VFX_FRAME_PROP_ID_TRANSFORM, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_TRANSFORM, (void*)&value, sizeof(VfxTransform));
    }
}


void VfxFrame::setBorderColor(const VfxColor &value)
{
    if (getBorderColor() != value)
    {
        vrt_color_type fromValue = getBorderColor();
        vrt_color_type vrtValue = value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_BORDER_COLOR,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VfxColor(VRT_FRAME_DEFAULT_BORDER_COLOR))
            setAttachProperty(VFX_FRAME_PROP_ID_BORDER_COLOR, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_BORDER_COLOR, (void*)&value, sizeof(VfxColor));
    }
}


void VfxFrame::setBorderWidth(VfxS32 value)
{
    if (getBorderWidth() != value)
    {
        vrt_s32 fromValue = getBorderWidth();
        vrt_s32 vrtValue = (vrt_s32)value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_BORDER_WIDTH,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == VRT_FRAME_DEFAULT_BORDER_WIDTH)
            setAttachProperty(VFX_FRAME_PROP_ID_BORDER_WIDTH, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_BORDER_WIDTH, (void*)&value, sizeof(VfxS32));
    }
}


void VfxFrame::setFilterTiming(VfxFloat value)
{
    if (getFilterTiming() != value)
    {
        vrt_float fromValue = getFilterTiming();
        vrt_float vrtValue = (vrt_float)value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_FILTER_TIMING,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == 0.0f)
            setAttachProperty(VFX_FRAME_PROP_ID_FILTER_TIMING, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_FILTER_TIMING, (void*)&value, sizeof(VfxFloat));
    }
}


void VfxFrame::setFpeUser0(VfxFloat value)
{
    if (getFpeUser0() != value)
    {
        vrt_float fromValue = getFpeUser0();
        vrt_float vrtValue = (vrt_float)value;
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_FRAME_PROPERTY_ID_FPE_USER_0,
            &fromValue,
            &vrtValue,
            sizeof(vrtValue));

        if(value == 0.0f)
            setAttachProperty(VFX_FRAME_PROP_ID_FPE_USER_0, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_FPE_USER_0, (void*)&value, sizeof(VfxFloat));
    }
}


void VfxFrame::setImgContent(const VfxImageSrc &value)
{
    if (m_imgContent != value)
    {
        m_imgContent = value;

        setDirty();
    }

    // We alwyas flush image content's cache data.
    //  For example here is a image source by file path, and the file state may
    //  be updated.
    m_imgContent.invalidate();
}


void VfxFrame::setContentPlacement(VfxFrameContentPlacementTypeEnum value)
{
    if (getContentPlacement() == value)
    {
        return;
    }

    if (value == VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER)
    {
        setAttachProperty(VFX_FRAME_PROP_ID_CONTENT_PLACE, NULL, 0);
        VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_CONTENT_PLACEMENT);
    }
    else
    {
        setAttachProperty(VFX_FRAME_PROP_ID_CONTENT_PLACE, (void*)&value, sizeof(VfxFrameContentPlacementTypeEnum));
        VFX_FLAG_SET(m_flags, FLAGS_HAS_CONTENT_PLACEMENT);
    }
    
    setDirty();
}


void VfxFrame::setFilter(VfxFrameFilter *value)
{
    VfxFrameFilter *oldValue = getFilter();
    VfxFrame* i = NULL;
    if (oldValue == value)
    {
        return;
    }

    if (oldValue)
    {
        oldValue->setTargetFrame(NULL);
    }

    if (value == NULL)
    {
        setAttachProperty(VFX_FRAME_PROP_ID_FILTER, NULL, 0);
        VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_FILTER);

        for (i = this; i != NULL; i = i->getParentFrame())
        {
            VFX_FLAG_CLEAR(i->m_flags, FLAGS_UPDATE_ALWAYS); 
        }

        // TODO: move this suspend to delete filter
        // Work around solution, to safty free buffers
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->suspendUntilCommit();
    }
    else
    {
        value->setTargetFrame(this);
        
        setAttachProperty(VFX_FRAME_PROP_ID_FILTER, (void*)&value, sizeof(VfxFrameFilter *));
        VFX_FLAG_SET(m_flags, FLAGS_HAS_FILTER);
        for (i = this; i != NULL; i = i->getParentFrame())
        {
            if (VFX_FLAG_HAS(i->m_flags, FLAGS_UPDATE_ALWAYS))
            {
                break;
            }
            VFX_FLAG_SET(i->m_flags, FLAGS_UPDATE_ALWAYS); 
        }
    }

    vrt_frame_set_filter(m_handle, static_cast<IVrtFrameFilter *>(value));
    setDirty();
}


void VfxFrame::setOwnerDraw(VfxOwnerDraw *value)
{
    VfxOwnerDraw *oldValue = getOwnerDraw();
    VfxFrame *i = NULL;
    if (oldValue == value)
    {
        return;
    }

    if (oldValue)
    {
        oldValue->setTargetFrame(NULL);
    }

    if (value == NULL)
    {
        setAttachProperty(VFX_FRAME_PROP_ID_OWNER_DRAW, NULL, 0);
        VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_OWNER_DRAW);
        for (i = this; i != NULL; i = i->getParentFrame())
        {
            VFX_FLAG_CLEAR(i->m_flags, FLAGS_UPDATE_ALWAYS); 
        }

        // TODO: move this suspend to delete filter
        // Work around solution, to safty free buffers
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->suspendUntilCommit();
    }
    else
    {
        value->setTargetFrame(this);
        
        setAttachProperty(VFX_FRAME_PROP_ID_OWNER_DRAW, &value, sizeof(VfxOwnerDraw *));
        VFX_FLAG_SET(m_flags, FLAGS_HAS_OWNER_DRAW);
        for (i = this; i != NULL; i = i->getParentFrame())
        {
            VFX_FLAG_SET(i->m_flags, FLAGS_UPDATE_ALWAYS); 
        }
    }
    
    vrt_frame_set_owner_draw(m_handle, static_cast <IVrtOwnerDraw *>(value));
    setDirty();
}


#ifdef __VENUS_3D_UI_ENGINE__
void VfxFrame::setMaterial(VfxMaterial *material)
{
    if (m_material != material)
    {
        m_material = material;
        if (m_handle)
        {
            vrt_frame_set_material(m_handle, m_material != NULL ? m_material->getSyncHandle() : NULL);
        }
        setDirty();
    }
}


void VfxFrame::setWorld(VfxWorld *world)
{
    if (m_world != world)
    {
        m_world = world;
        if (m_handle)
        {
            vrt_frame_set_world(m_handle, m_world != NULL ? m_world->getSyncHandle() : NULL);
        }
        setDirty();
    }
}
#endif /* __VENUS_3D_UI_ENGINE__ */


void VfxFrame::setHidden(VfxBool value)
{
    if (VFX_FLAG_HAS(m_flags, FLAGS_HIDDEN) && !value)
    {
        VFX_FLAG_CLEAR(m_flags, FLAGS_HIDDEN);

        // Set dirty
        VfxFrame *parentFrame = getParentFrame();
        if (parentFrame != NULL)
        {
            parentFrame->setDirty();
        }
    }
    else if (!VFX_FLAG_HAS(m_flags, FLAGS_HIDDEN) && value)
    {
        VFX_FLAG_SET(m_flags, FLAGS_HIDDEN);

        // Set dirty
        VfxFrame *parentFrame = getParentFrame();
        if (parentFrame != NULL)
        {
            parentFrame->setDirty();
        }
        
        if (!VFX_FLAG_HAS(m_flags, FLAGS_NEED_UPDATE_CMDS))
        {
            markNeedUpdateCmds();
        }
    }
    else
    {
        // Do nothing
    }
}
void VfxFrame::markNeedUpdateCmds()
{
    VfxFrame *i;

    if(!VFX_FLAG_HAS(m_flags, FLAGS_NEED_UPDATE_CMDS))
    {
        VFX_FLAG_SET(m_flags, FLAGS_NEED_UPDATE_CMDS);
        for (i = this->getFirstChildFrame(); i != NULL; i = i->getNextFrame())
        {       
              i->markNeedUpdateCmds();  
        }
    }
}

void VfxFrame::setIsUnhittable(VfxBool value)
{
    value ? 
        VFX_FLAG_SET(m_flags, FLAGS_UNHITTABLE) :
        VFX_FLAG_CLEAR(m_flags, FLAGS_UNHITTABLE);
}


void VfxFrame::setIsOpaque(VfxBool value)
{
    setOpaqueMode(
        value ? 
            VFX_FRAME_OPAQUE_MODE_COLOR_KEY : 
            VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
}


void VfxFrame::setQuality(VfxRenderQualityEnum value)
{
    if (getQuality() != value)
    {
        if(value == VFX_RENDER_QUALITY_DEFAULT)
            setAttachProperty(VFX_FRAME_PROP_ID_QUALITY, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_QUALITY, (void*)&value, sizeof(VfxRenderQualityEnum));
        
        vrt_frame_set_quality(m_handle, (vrt_render_quality_enum)value);
    }
}


void VfxFrame::setIsCached(VfxBool value)
{
    if (VFX_FLAG_HAS(m_flags, FLAGS_CACHED) && !value)
    {
        VFX_FLAG_CLEAR(m_flags, FLAGS_CACHED);

        vrt_frame_set_is_cached(m_handle, (vrt_bool)value);
    }
    else if (!VFX_FLAG_HAS(m_flags, FLAGS_CACHED) && value)
    {
        VFX_FLAG_SET(m_flags, FLAGS_CACHED);

        vrt_frame_set_is_cached(m_handle, (vrt_bool)value);
    }
    else
    {
        // Do nothing
    }        
}


void VfxFrame::setCacheMode(VfxCacheModeEnum value)
{
    if (getCacheMode() != value)
    {
        if(value == VFX_CACHE_MODE_AUTO)
            setAttachProperty(VFX_FRAME_PROP_ID_CACHE_MODE, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_CACHE_MODE, (void*)&value, sizeof(VfxCacheModeEnum));
        
        vrt_frame_set_cache_mode(m_handle, (vrt_cache_mode_enum)value);
    }
}


void VfxFrame::setOpaqueMode(VfxFrameOpaqueModeEnum value)
{
    if (getOpaqueMode() != value)
    {
        if(value == VFX_FRAME_OPAQUE_MODE_AUTO)
            setAttachProperty(VFX_FRAME_PROP_ID_OPAQUE_MODE, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_OPAQUE_MODE, (void*)&value, sizeof(VfxFrameOpaqueModeEnum));
        
        vrt_frame_set_opaque_mode(m_handle, (vrt_frame_opaque_mode_enum)value);
    }
}


void VfxFrame::setCullingType(VfxFrameCullingTypeEnum value)
{
    if (getCullingType() != value)
    {
        if(value == VFX_FRAME_CULLING_TYPE_NONE)
            setAttachProperty(VFX_FRAME_PROP_ID_CULLING_TYPE, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_CULLING_TYPE, (void*)&value, sizeof(VfxFrameCullingTypeEnum));
        
        vrt_frame_set_culling_type(m_handle, (vrt_frame_culling_type_enum)value);
    }
}


void VfxFrame::setIsZSortChild(VfxBool value)
{
    if (VFX_FLAG_HAS(m_flags, FLAGS_Z_SORT_CHILD) && !value)
    {
        VFX_FLAG_CLEAR(m_flags, FLAGS_Z_SORT_CHILD);

        vrt_frame_set_is_z_sort_child(m_handle, (vrt_bool)value);
    }
    else if (!VFX_FLAG_HAS(m_flags, FLAGS_Z_SORT_CHILD) && value)
    {
        VFX_FLAG_SET(m_flags, FLAGS_Z_SORT_CHILD);

        vrt_frame_set_is_z_sort_child(m_handle, (vrt_bool)value);
    }
    else
    {
        // Do nothing
    }        
}


VfxFrameHintsEnum VfxFrame::getHints() const
{
    VfxFrameHintsEnum *v = (VfxFrameHintsEnum*)getAttachProperty(VFX_FRAME_PROP_ID_HINTS, sizeof(VfxFrameHintsEnum));
    if (v == NULL)
    {
        return VFX_FRAME_HINTS_DEFAULT;
    }
    
    return *v;
}


void VfxFrame::setHints(VfxFrameHintsEnum value)
{
    if (getHints() == value)
    {
        return;
    }
    
    if(value == VFX_FRAME_HINTS_DEFAULT)
    {
        setAttachProperty(VFX_FRAME_PROP_ID_HINTS, NULL, 0);
    }
    else
    {
        setAttachProperty(VFX_FRAME_PROP_ID_HINTS, (void*)&value, sizeof(VfxFrameHintsEnum));
    }
    
    vrt_frame_set_hints(m_handle, (vrt_frame_hints_enum)value);
}


void VfxFrame::setHintFlag(VfxFrameHintsEnum flags)
{
    VfxFlag hints = getHints();
    VFX_FLAG_SET(hints, (VfxFlag)flags);
    setHints((VfxFrameHintsEnum)hints);
}


void VfxFrame::clearHintFlag(VfxFrameHintsEnum flags)
{
    VfxFlag hints = getHints();
    VFX_FLAG_CLEAR(hints, (VfxFlag)flags);
    setHints((VfxFrameHintsEnum)hints);
}


void VfxFrame::setLayerHandle(VfxU32 value)
{
    if (getLayerHandle() != value)
    {
        if(value == 0)
            setAttachProperty(VFX_FRAME_PROP_ID_LAYER_HDL, NULL, 0);
        else
            setAttachProperty(VFX_FRAME_PROP_ID_LAYER_HDL, (void*)&value, sizeof(VfxU32));
        
        vrt_frame_set_layer_frame(m_handle, (vrt_u32)value);
    }
}


VfxU32 VfxFrame::getLayerHandle() const
{
    VfxU32 *v = (VfxU32*)getAttachProperty(VFX_FRAME_PROP_ID_LAYER_HDL, sizeof(VfxU32));
    if(v)
        return *v;
    else
        return 0;
}


void VfxFrame::setFallbackImage(VfxResId resId)
{
    if (getFallbackImage() != resId)
    {
        if(resId == 0)
        {
            setAttachProperty(VFX_FRAME_PROP_ID_FALLBACK_IMAGE, NULL, 0);
            VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_FALLBACK_IMAGE);
        }
        else
        {
            setAttachProperty(VFX_FRAME_PROP_ID_FALLBACK_IMAGE, (void*)&resId, sizeof(VfxResId));
            VFX_FLAG_SET(m_flags, FLAGS_HAS_FALLBACK_IMAGE);
        }
    }
}


VfxResId VfxFrame::getFallbackImage() const
{
    if (VFX_FLAG_HAS(m_flags, FLAGS_HAS_FALLBACK_IMAGE))
    {
        VfxResId *v = (VfxResId*)getAttachProperty(VFX_FRAME_PROP_ID_FALLBACK_IMAGE, sizeof(VfxResId));
        return *v;
    }
    else
    {
        return 0;
    }
}


VfxBool VfxFrame::getHasAnimateImage() const
{
    return (vrt_frame_get_has_animation(m_handle) == VRT_TRUE);
}


void VfxFrame::addChildFrame(VfxFrame *newFrame)
{
    VFX_OBJ_ASSERT_VALID(newFrame);

    if (this != newFrame->getParentFrame())
    {
        VfxFrame *origParentFrame = newFrame->processRemoveFromParentFrame();

        // Add
        newFrame->m_parentFrame = this;
        newFrame->m_prevFrame = m_lastChildFrame;
        newFrame->m_nextFrame = NULL;

        // If there is no child newFrame, set the new frame to the first one
        if (m_firstChildFrame == NULL)
        {
            m_firstChildFrame = newFrame;
        }
        
        if (m_lastChildFrame != NULL)
        {
            m_lastChildFrame->m_nextFrame = newFrame;
        }
        m_lastChildFrame = newFrame;

        if (VFX_FLAG_HAS(m_flags, FLAGS_NEED_UPDATE_CMDS) &&
            !VFX_FLAG_HAS(newFrame->m_flags, FLAGS_NEED_UPDATE_CMDS))
        {
            newFrame->markNeedUpdateCmds();
        }

        // Process parent frame changed
        newFrame->processParentFrameChanged(origParentFrame);
    }
    else
    {
        newFrame->bringToFront();
    }
}


VfxFrame *VfxFrame::processRemoveFromParentFrame()
{
    VfxFrame *origParentFrame = m_parentFrame;    
    if (origParentFrame == NULL)
    {
        // No parent frame, do nothing
        VFX_DEV_ASSERT(m_prevFrame == NULL);
        VFX_DEV_ASSERT(m_nextFrame == NULL);
        return NULL;
    }

    // Remove form parent's child frame list
    if (m_prevFrame != NULL)
    {
        m_prevFrame->m_nextFrame = m_nextFrame;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentFrame->m_firstChildFrame == this);
        m_parentFrame->m_firstChildFrame = m_nextFrame;
    }

    if (m_nextFrame != NULL)
    {
        m_nextFrame->m_prevFrame = m_prevFrame;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentFrame->m_lastChildFrame == this);
        m_parentFrame->m_lastChildFrame = m_prevFrame;
    }

    // Setting focus
    if (m_parentFrame->m_focusChildFrame == this)
    {
        if (getFocused())
        {
            VfxFrame *ptr = this;
            while (ptr)
            {
                ptr->processOnFocusChanged(VFX_FALSE);
                ptr = ptr->m_focusChildFrame;
            }
        }
        m_parentFrame->m_focusChildFrame = NULL;
    }

    m_parentFrame = NULL;
    m_prevFrame = NULL;
    m_nextFrame = NULL;

    return origParentFrame;
}


void VfxFrame::removeFromParentFrame()
{
    VfxFrame *origParentFrame = processRemoveFromParentFrame();
    if (origParentFrame == NULL)
    {
        // No original parent frame, do nothing
        return;
    }
    
    processParentFrameChanged(origParentFrame);
}


void VfxFrame::insertChildFrameAfter(VfxFrame *childFrame, VfxFrame *newFrame)
{
    VFX_OBJ_ASSERT_VALID(childFrame);
    VFX_OBJ_ASSERT_VALID(newFrame);
    VFX_ASSERT(childFrame->m_parentFrame == this);

    VfxFrame *origParentFrame = newFrame->processRemoveFromParentFrame();

    // Insert
    VfxFrame *origNextFrame = childFrame->m_nextFrame;

    newFrame->m_parentFrame = this;
    newFrame->m_prevFrame = childFrame;
    newFrame->m_nextFrame = origNextFrame;
    
    if (origNextFrame != NULL)
    {
        origNextFrame->m_prevFrame = newFrame;
    }
    else
    {
        m_lastChildFrame = newFrame;
    }
    childFrame->m_nextFrame = newFrame;
    
    // Process parent frame changed
    newFrame->processParentFrameChanged(origParentFrame);
}


void VfxFrame::insertChildFrameBefore(VfxFrame *childFrame, VfxFrame *newFrame)
{
    VFX_OBJ_ASSERT_VALID(childFrame);
    VFX_OBJ_ASSERT_VALID(newFrame);
    VFX_ASSERT(childFrame->m_parentFrame == this);

    VfxFrame *origParentFrame = newFrame->processRemoveFromParentFrame();

    // Insert
    VfxFrame *origPrevFrame = childFrame->m_prevFrame;

    newFrame->m_parentFrame = this;
    newFrame->m_prevFrame = origPrevFrame;
    newFrame->m_nextFrame = childFrame;
    
    if (origPrevFrame != NULL)
    {
        origPrevFrame->m_nextFrame = newFrame;
    }
    else
    {
        m_firstChildFrame = newFrame;
    }
    childFrame->m_prevFrame = newFrame;
    
    // Process parent frame changed
    newFrame->processParentFrameChanged(origParentFrame);
}


void VfxFrame::replaceChildFrameWith(VfxFrame *oldFrame, VfxFrame *newFrame)
{
    VFX_OBJ_ASSERT_VALID(oldFrame);
    VFX_OBJ_ASSERT_VALID(newFrame);
    VFX_ASSERT(oldFrame->m_parentFrame == this);

    // Do nothing if old and new frames are the same
    if (oldFrame == newFrame)
    {
        return;
    }

    VfxBool needFocus = VFX_FALSE;
    if (m_focusChildFrame == oldFrame)
    {
        resetFocusChild();
        m_focusChildFrame = newFrame;
        needFocus = VFX_TRUE;
    }

    // Insert the new frame and remove the old frame from parent
    insertChildFrameAfter(oldFrame, newFrame);
    // Remove oldFrame from the frame's child list
    oldFrame->removeFromParentFrame();
    
    // Get the focus back if need
    if (needFocus)
    {
        newFrame->setFocused(VFX_TRUE);
    }
}


void VfxFrame::bringToFront()
{
    if (m_parentFrame == NULL)
    {
        // Do nothing if there is no parent
        return;
    }

    if (m_parentFrame->m_lastChildFrame == this)
    {
        // Do nothing if the frame is already the front one
        return;
    }

    // Remove from current position
    if (m_prevFrame != NULL)
    {
        m_prevFrame->m_nextFrame = m_nextFrame;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentFrame->m_firstChildFrame == this);
        m_parentFrame->m_firstChildFrame = m_nextFrame;
    }
    VFX_DEV_ASSERT(m_nextFrame != NULL);
    m_nextFrame->m_prevFrame = m_prevFrame;

    // Append the frame to the last one
    m_prevFrame = m_parentFrame->m_lastChildFrame;
    m_nextFrame = NULL;
    m_parentFrame->m_lastChildFrame->m_nextFrame = this;
    m_parentFrame->m_lastChildFrame = this;
    
    // Set dirty
    m_parentFrame->setDirty();
}


void VfxFrame::sendToBack()
{
    if (m_parentFrame == NULL)
    {
        // Do nothing if there is no parent
        return;
    }

    if (m_parentFrame->m_firstChildFrame == this)
    {
        // Do nothing if the frame is already the back one
        return;
    }

    // Remove from current position
    if (m_nextFrame != NULL)
    {
        m_nextFrame->m_prevFrame = m_prevFrame;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentFrame->m_lastChildFrame == this);
        m_parentFrame->m_lastChildFrame = m_prevFrame;
    }
    VFX_DEV_ASSERT(m_prevFrame != NULL);
    m_prevFrame->m_nextFrame = m_nextFrame;

    // Append the frame to the first one
    m_nextFrame = m_parentFrame->m_firstChildFrame;
    m_prevFrame = NULL;
    m_parentFrame->m_firstChildFrame->m_prevFrame = this;
    m_parentFrame->m_firstChildFrame = this;

    // Set dirty
    m_parentFrame->setDirty();
}


void VfxFrame::onFocusChanged(VfxBool value)
{
    VFX_UNUSED(value);
    // Do nothing
}


void VfxFrame::processOnFocusChanged(VfxBool focused)
{
    onObjectNotify(VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED, (void *)&focused);
}


void VfxFrame::setFocused(VfxBool value)
{
    VfxBool preFocus = getFocused();

    if (value)
    {
        // the frame has got the focus
        if (preFocus)
        {
            // no thing
        }
        else
        {    
            // If the control is not in scene graph or can't be focused, change the focus list, 
            //  but don't need to invoke events
            VfxFrame* ptr = this;
            VfxFrame *focusControllerFrame = NULL;
                
            while(ptr && ptr->m_parentFrame)
            {
//                if (ptr->m_parentFrame->queryFocusChange(ptr))
                VfxFrameQueryFocusChangeData data;
                data.childFrame = ptr;
                data.ret = VFX_FALSE;

                ptr->m_parentFrame->onObjectNotify(VFX_FRAME_NOTIFY_ID_QUERY_FOCUS_CHANGE, (void *)&data);
                if (data.ret)
                {
                    ptr = ptr->m_parentFrame;
                }
                else
                {
                    focusControllerFrame = ptr->m_parentFrame;
                    break;
                }
            }

            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            if (renderer->getRootFrame() != ptr)
            {
                // maintain the focus list, but don't invoke event
                // that is because the whole list is not focused now
                ptr = this;
                
                while(ptr && ptr->m_parentFrame)
                {
                    if (ptr->m_parentFrame->m_focusChildFrame != ptr)
                    {
                        if (focusControllerFrame && focusControllerFrame == ptr->m_parentFrame)
                        {
                            break;
                        }
                        else
                        {
                            ptr->m_parentFrame->m_focusChildFrame = ptr;
                        }
                    }
                    
                    ptr = ptr->m_parentFrame;
                }
            }
            else
            {
                // This focus tree can be focus
                // Use recursive to make the root focused first, so that the event order can be correct
                // That's said, the parent should get focus event first
                m_parentFrame->setFocusHelper(this);
            }
        }
    }
    // The control want to lost focus
    else
    {
        // break the focus list
        if (m_parentFrame && m_parentFrame->m_focusChildFrame == this)
            m_parentFrame->m_focusChildFrame = NULL;

        if (preFocus)
        {
            VfxFrame* ptr = this;
            while(ptr)
            {
//                ptr->onFocusChanged(VFX_FALSE);
                ptr->processOnFocusChanged(VFX_FALSE);
                ptr = ptr->m_focusChildFrame;
            }
        }
    }
}


VfxBool VfxFrame::setFocusHelper(VfxFrame* focusChild)
{
    VfxFrame* preFocus = m_focusChildFrame;
    m_focusChildFrame = focusChild;
    VfxBool preFocused = VFX_TRUE;

    if (m_parentFrame)
    {
        preFocused = m_parentFrame->setFocusHelper(this);
    }
    else
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        preFocused = (this == renderer->getRootFrame());
    }

    // If the parent is focused
    if (preFocused)
    {
        // and no focus child change
        if (preFocus == focusChild)
        {
            return VFX_TRUE;
        }

        // Notify the previous focused list 
        VfxFrame* ptr = preFocus;
        while (ptr)
        {
//            ptr->onFocusChanged(VFX_FALSE);
            ptr->processOnFocusChanged(VFX_FALSE);
            ptr = ptr->m_focusChildFrame;
        }

        // Notify the new focused list 
        ptr = m_focusChildFrame;
        while (ptr)
        {
//            ptr->onFocusChanged(VFX_TRUE);
            ptr->processOnFocusChanged(VFX_TRUE);
            ptr = ptr->m_focusChildFrame;
        }
        return VFX_FALSE;
    }
    return VFX_FALSE;
}


VfxBool VfxFrame::getFocused()
{
    VfxFrame* ptr = this;
    while (ptr && ptr->m_parentFrame)
    {
        if (ptr->m_parentFrame->m_focusChildFrame != ptr)
        {
            return VFX_FALSE;
        }
        ptr = ptr->m_parentFrame;
    }
    
    // Check the ptr is root
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    return (renderer->getRootFrame() == ptr);
}


VfxBool VfxFrame::queryFocusChange(VfxFrame *childFrame)
{
    VFX_DEV_ASSERT(childFrame);
    VFX_DEV_ASSERT(childFrame->m_parentFrame == this);

    return VFX_TRUE; // focus is changeable in default
}


void VfxFrame::resetFocusChild()
{
    if (getFocused())
    {
        // Notify the focused child that we lost focus
        VfxFrame *ptr = m_focusChildFrame;
        m_focusChildFrame = NULL; // break the focus test
        while (ptr)
        {
//            ptr->onFocusChanged(VFX_FALSE);
            ptr->processOnFocusChanged(VFX_FALSE);
            ptr = ptr->m_focusChildFrame;
        }
    }
    m_focusChildFrame = NULL;
}

    
VfxBool VfxFrame::processFocusKey(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    if (m_focusChildFrame)
    {
        ret = m_focusChildFrame->processFocusKey(event);
    }

    if (!ret)
    {
        ret = onKeyInput(event);
    }

    return ret;
}


VfxBool VfxFrame::processAccessKey(VfxKeyEvent &event)
{
    return onKeyInput(event);
}


VfxBool VfxFrame::onKeyInput(VfxKeyEvent &event)
{
    VFX_UNUSED(event);
    
    // do nothing
    return VFX_FALSE;
}


VfxFrame *VfxFrame::hitTest(const VfxPoint &point, const VfxBool transform) const
{
#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
    if (containPoint(point, VFX_FALSE) || containPoint(point, VFX_TRUE))
#else
    if (containPoint(point, VFX_FALSE))
#endif
    {
        return hitTestHelper1(point, getBounds(), transform);
    }

    return NULL;
}


VfxFrame *VfxFrame::hitTestHelper1(const VfxPoint &point, const VfxRect &rect, const VfxBool transform) const
{
    VfxFrame *ret;

    // Exactly hit test
    ret = hitTestHelper2(point, rect, VFX_FALSE, transform);
    if (ret != NULL)
    {
        return ret;
    }

#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
    // Fuzzy hit test
    if (VFX_FLAG_HAS(m_flags, FLAGS_CHILD_FUZZY))
    {
        ret = hitTestHelper2(point, rect, VFX_TRUE, transform);
        if (ret != NULL)
        {
            return ret;
        }
    }
#endif

    return VFX_CONST_CAST(this, VfxFrame *);
}


VfxFrame *VfxFrame::hitTestHelper2(const VfxPoint &point, const VfxRect &rect, const VfxBool isFuzzy, const VfxBool transform) const
{
    // Test if any child of this frame is hitted
    // Reversed check whatever a child frame contains the point
    if (getIsZSortChild())
    {
        VfxFrame *destFrame = NULL;
        VfxFloat destZ = 0.0f;

        VfxFrame *i;
        for (i = m_lastChildFrame; i != NULL; i = i->m_prevFrame)
        {
            // Ignore hidden frames
            if (i->getHidden())
            {
                continue;
            }

            VfxRect r = rect;
#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
            r.intersectWith(i->getRect());
            if (r == VFX_RECT_ZERO)
            {
                continue;
            }
#endif
            VfxPoint child_pos = point;
            i->convertPointFromParent(child_pos, transform);
            if (!i->containPoint(child_pos, isFuzzy))
            {
                continue;
            }

#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
            i->convertRectFromParent(r);
#endif
            VfxFrame *hitFrame = i->hitTestHelper1(child_pos, r);
            if(!destFrame || destZ > i->getPosZ())
            {
                destFrame = hitFrame;
                destZ = i->getPosZ();
            }
        }
        return destFrame;
    }
    else
    {
        VfxFrame *i;
        for (i = m_lastChildFrame; i != NULL; i = i->m_prevFrame)
        {
            // Ignore hidden frames
            if (i->getHidden())
            {
                continue;
            }

            VfxRect r = rect;
#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
            r.intersectWith(i->getRect());
            if (r == VFX_RECT_ZERO)
            {
                continue;
            }
#endif
            VfxPoint child_pos = point;
            i->convertPointFromParent(child_pos, transform);
            if (i->containPoint(child_pos, isFuzzy))
            {
#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
                i->convertRectFromParent(r);
#endif
                return i->hitTestHelper1(child_pos, r);
            }
        }
    }

    return NULL;
}


VfxBool VfxFrame::containPoint(const VfxPoint &point, const VfxBool isFuzzy) const
{
    if (getIsUnhittable())
    {
        return VFX_FALSE;
    }

#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
    if (isFuzzy && (VFX_FLAG_HAS(m_flags, FLAGS_FUZZY) || VFX_FLAG_HAS(m_flags, FLAGS_CHILD_FUZZY)))
    {
        return onContainPointFuzzy(point);
    }
#endif

    return onContainPoint(point);
}


void VfxFrame::setFuzzy(VfxBool value)
{
#if defined(VFX_CFG_PEN_FUZZY_TOUCH)
    VfxFrame *frame = getParentFrame();

    if (value)
    {
        VFX_FLAG_SET(m_flags, FLAGS_FUZZY);
        for (; frame; frame = frame->getParentFrame())
        {
            VFX_FLAG_SET(frame->m_flags, FLAGS_CHILD_FUZZY);
        }
    }
    else
    {
        VFX_FLAG_CLEAR(m_flags, FLAGS_FUZZY);
        for (; frame; frame = frame->getParentFrame())
        {
            VfxFrame* child;
            for (child = frame->getFirstChildFrame(); child; child = child->getNextFrame())
            {
                if (VFX_FLAG_HAS(child->m_flags, FLAGS_FUZZY) || VFX_FLAG_HAS(child->m_flags, FLAGS_CHILD_FUZZY))
                {
                    break;
                }
            }
            if (child)
            {
                break;
            }
            VFX_FLAG_CLEAR(frame->m_flags, FLAGS_CHILD_FUZZY);
        }
    }
#endif
}


VfxRect VfxFrame::getRect() const
{
    VfxRect frameRect(getBounds());
    convertRectToParent(frameRect);
    return frameRect;
}


void VfxFrame::setRect(const VfxRect &rect)
{
    VfxFPoint frameAnchor(getAnchor());
    VfxPoint framePos(rect.origin);
    
    framePos.x += (VfxS32)(rect.size.width * frameAnchor.x);
    framePos.y += (VfxS32)(rect.size.height * frameAnchor.y);
    
    setPos(framePos);
    setSize(rect.size);
}


VfxPoint VfxFrame::convertPointFrom(const VfxPoint &point, const VfxFrame *frame, VfxBool transform) const
{
    VFX_ASSERT(frame != NULL);
    
    VfxPoint cur_point(point);
    
    // translate position from the frame to root
    const VfxFrame *i;
    for (i = frame; i != NULL; i = i->m_parentFrame)
    {
        i->convertPointToParent(cur_point);
    }

    if (transform)
    {
        VfxObjList list;
        VfxObjListEntry *entry;

        for (i = this; i != NULL; i = i->m_parentFrame)
        {
            list.prepend((VfxObject *)i);
        }

        for (entry = list.getHead(); entry!= NULL; entry = entry->getNext())
        {
            i = (VfxFrame *)entry->get();
            i->convertPointFromParent(cur_point, transform);
        }

        return cur_point;
    }

    // TODO: this is not a corrent code
    // translate from root to the given frame
    for (i = this; i != NULL; i = i->m_parentFrame)
    {
        i->convertPointFromParent(cur_point);
    }

    return cur_point;
}


VfxPoint VfxFrame::convertPointTo(const VfxPoint &point, const VfxFrame *frame, VfxBool transform) const
{
    VFX_ASSERT(frame != NULL);
    
    VfxPoint cur_point(point);
    
    // translate position from the frame to root
    const VfxFrame *i;
    for (i = this; i != NULL; i = i->m_parentFrame)
    {
        i->convertPointToParent(cur_point);
    }

    if (transform)
    {
        VfxObjList list;
        VfxObjListEntry *entry;
        
        for (i = frame; i != NULL; i = i->m_parentFrame)
        {
            list.prepend((VfxObject *)i);
        }

        for (entry = list.getHead(); entry != NULL; entry = entry->getNext())
        {
            i = (VfxFrame *)entry->get();
            i->convertPointFromParent(cur_point, transform);
        }

        return cur_point;
    }

    // TODO: this is not a corrent code
    // translate from root to the given frame
    for (i = frame; i != NULL; i = i->m_parentFrame)
    {
        i->convertPointFromParent(cur_point);
    }

    return cur_point;
}


VfxRect VfxFrame::convertRectFrom(const VfxRect &rect, const VfxFrame *frame) const
{
    VFX_ASSERT(frame != NULL);
    
    VfxRect cur_rect(rect);
    
    // translate position from the frame to root
    const VfxFrame *i;
    for (i = frame; i != NULL; i = i->m_parentFrame)
    {
        i->convertRectToParent(cur_rect);
    }

    // TODO: this is not a corrent code
    // translate from root to the given frame
    for (i = this; i != NULL; i = i->m_parentFrame)
    {
        i->convertRectFromParent(cur_rect);
    }

    return cur_rect;
}


VfxRect VfxFrame::convertRectTo(const VfxRect &rect, const VfxFrame *frame) const
{
    VFX_ASSERT(frame != NULL);
    
    VfxRect cur_rect(rect);
    
    // translate position from the frame to root
    const VfxFrame *i;
    for (i = this; i != NULL; i = i->m_parentFrame)
    {
        i->convertRectToParent(cur_rect);
    }

    // TODO: this is not a corrent code
    // translate from root to the given frame
    for (i = frame; i != NULL; i = i->m_parentFrame)
    {
        i->convertRectFromParent(cur_rect);
    }

    return cur_rect;
}


void VfxFrame::forcePos(const VfxPoint &pos)
{
    m_pos = pos;

    vrt_point_struct value;
    value.x = pos.x;
    value.y = pos.y;
    
    vrt_object_force_set_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_POS,
        &value, 
        sizeof(value));
}


void VfxFrame::forceImgContent(const VfxImageSrc &value)
{
    VFX_ASSERT(value.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER);
        
    if (m_imgContentCommitCounter != vrt_frame_get_commit_counter())
    {
        // The frame doesn't committed and has no command index,
        //  or the commandIndex has been changed
        setImgContent(value);
        return;
    }

    // Update VFX frame data
    m_imgContent = value;

    // Force update VRT data
    vrt_image_buffer_struct vrtImageBuf;
    value.getImageBuffer().initVrtImageBuffer(vrtImageBuf);
    vrt_frame_force_swap_img_buf(
        m_handle, 
        m_imgContentCommandIndex, 
        &vrtImageBuf);
}


void VfxFrame::setContentDirty()
{
    vrt_frame_set_content_dirty(m_handle);
}

void VfxFrame::preCache()
{
    VfxVirtualTimeline *tl;
    VFX_OBJ_CREATE(tl, VfxVirtualTimeline, this);
    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_VIRTUAL_DIRTY);
    tl->setTarget(this);
    tl->start();
}

void VfxFrame::preCacheChildren()
{
    VfxVirtualTimeline *tl;
    VFX_OBJ_CREATE(tl, VfxVirtualTimeline, this);
    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_VIRTUAL_CONTENT_DIRTY);
    tl->setTarget(this);
    tl->start();
    // TODO: do not change frame hints
    setHintFlag(VFX_FRAME_HINTS_PRECACHE_CHILDREN);
}

VfxPoint VfxFrame::forceGetPos() const
{
    if (m_handle == NULL)
    {
        return m_pos;
    }
    
    vrt_point_struct value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_POS, 
        &value, 
        sizeof(value));

    return VfxPoint(value);
}


VfxRect VfxFrame::forceGetBounds() const
{
    if (m_handle == NULL)
    {
        return m_bounds;
    }
    
    vrt_rect_struct value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_BOUNDS, 
        &value, 
        sizeof(value));
    return VfxRect(value);
}


VfxFloat VfxFrame::forceGetOpacity() const
{
    if (m_handle == NULL)
    {
        return getOpacity();
    }
    
    vrt_float value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_OPACITY, 
        &value, 
        sizeof(value));
    return VfxFloat(value);
}


VfxFPoint VfxFrame::forceGetAnchor() const
{
    if (m_handle == NULL)
    {
        return m_anchor;
    }
    
    vrt_fpoint_struct value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_ANCHOR_POINT, 
        &value, 
        sizeof(value));
    return VfxFPoint(value);
}


VfxTransform VfxFrame::forceGetTransform() const
{
    if (m_handle == NULL)
    {
        return getTransform();
    }
    
    vrt_transform_struct value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_TRANSFORM, 
        &value, 
        sizeof(value));
    return VfxTransform(value);
}


VfxColor VfxFrame::forceGetBgColor() const
{
    if (m_handle == NULL)
    {
        return getBgColor();
    }
    
    vrt_color_type value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR, 
        &value, 
        sizeof(value));
    return VfxColor(value);
}


VfxColor VfxFrame::forceGetBorderColor() const
{
    if (m_handle == NULL)
    {
        return getBorderColor();
    }
    
    vrt_color_type value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_BORDER_COLOR, 
        &value, 
        sizeof(value));
    return VfxColor(value);
}


VfxS32 VfxFrame::forceGetBorderWidth() const
{
    if (m_handle == NULL)
    {
        return getBorderWidth();
    }
    
    vrt_s32 value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_BORDER_WIDTH, 
        &value, 
        sizeof(value));
    return VfxS32(value);
}


VfxFloat VfxFrame::forceGetFilterTiming() const
{
    if (m_handle == NULL)
    {
        return getFilterTiming();
    }
    
    vrt_float value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_FILTER_TIMING, 
        &value, 
        sizeof(value));
    return VfxFloat(value);
}


VfxFloat VfxFrame::forceGetFpeUser0() const
{
    if (m_handle == NULL)
    {
        return getFpeUser0();
    }
    
    vrt_float value;
    vrt_frame_force_get_property_value(
        m_handle, 
        VRT_FRAME_PROPERTY_ID_FPE_USER_0, 
        &value, 
        sizeof(value));
    return VfxFloat(value);
}


void VfxFrame::setAlignParent(VfxFrameAlignerSideEnum side, VfxFrameAlignerModeEnum mode)
{
    VfxFrameAligner *aligner = getAligner();
    
    if (aligner == NULL)
    {
        VFX_OBJ_CREATE(aligner, VfxFrameAligner, this);
    }
    
    VfxS32 dist = 0;
    VfxRect bounds = convertRectTo(getBounds(), getParentFrame());
    VfxRect pbounds = getParentFrame()->getBounds();

    if (mode != VFX_FRAME_ALIGNER_MODE_NONE)
    {
        switch(side)
        {
            case VFX_FRAME_ALIGNER_SIDE_TOP:
                dist = (mode == VFX_FRAME_ALIGNER_MODE_SIDE) ?
                    (pbounds.getMinY() - bounds.getMinY()):
                    (pbounds.getMidY() - bounds.getMinY());
                break;
    
            case VFX_FRAME_ALIGNER_SIDE_BOTTOM:
                dist = (mode == VFX_FRAME_ALIGNER_MODE_SIDE) ?
                    (pbounds.getMaxY() - bounds.getMaxY()):
                    (pbounds.getMidY() - bounds.getMaxY());
                break;
    
            case VFX_FRAME_ALIGNER_SIDE_LEFT:
                dist = (mode == VFX_FRAME_ALIGNER_MODE_SIDE) ?
                    (pbounds.getMinX() - bounds.getMinX()):
                    (pbounds.getMidX() - bounds.getMinX());
                break;
    
            case VFX_FRAME_ALIGNER_SIDE_RIGHT:
                dist = (mode == VFX_FRAME_ALIGNER_MODE_SIDE) ?
                    (pbounds.getMaxX() - bounds.getMaxX()):
                    (pbounds.getMidX() - bounds.getMaxX());
                break;
    
            default:
                break;
        }
    }

    aligner->setAlignment(side, mode, dist);

    // we do not need aligner anymore if it is empty
    if (aligner->isEmpty())
    {
        VFX_OBJ_CLOSE(aligner);
    }

    if (aligner == NULL)
    {
        setAttachProperty(VFX_FRAME_PROP_ID_ALIGNER, NULL, 0);
        VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_ALIGNER);
        return;
    }
    
    setAttachProperty(VFX_FRAME_PROP_ID_ALIGNER, &aligner, sizeof(VfxFrameAligner*));
    VFX_FLAG_SET(m_flags, FLAGS_HAS_ALIGNER);
}


void VfxFrame::setAlignParent(
        VfxFrameAlignerModeEnum modeLeft,
        VfxFrameAlignerModeEnum modeTop,
        VfxFrameAlignerModeEnum modeRight,
        VfxFrameAlignerModeEnum modeBottom)
{
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, modeLeft);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, modeTop);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, modeRight);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, modeBottom);
}


void VfxFrame::setAlignParentEx(const VfxFrameAlignStruct& modes)
{
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, modes.modeLeft);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, modes.modeTop);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, modes.modeRight);
    setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, modes.modeBottom);
}


void VfxFrame::resetAlignParent()
{
    VfxFrameAligner *aligner = getAligner();
    if (aligner)
    {
        VFX_OBJ_CLOSE(aligner);
        setAttachProperty(VFX_FRAME_PROP_ID_ALIGNER, NULL, 0);
        VFX_FLAG_CLEAR(m_flags, FLAGS_HAS_ALIGNER);        
    }
}


void VfxFrame::alignParent()
{
    if (getAligner())
    {
        getAligner()->alignParentFrame(this);
    }
}


VfxFrameAligner* VfxFrame::getAligner() const
{
    if (!VFX_FLAG_HAS(m_flags, FLAGS_HAS_ALIGNER))
    {
        return NULL;
    }
    
    VfxFrameAligner **v = (VfxFrameAligner**)getAttachProperty(VFX_FRAME_PROP_ID_ALIGNER, sizeof(VfxFrameAligner*));
    VFX_DEV_ASSERT(v != NULL);
    
    return *v;
}


void VfxFrame::setPropertyEffectCallback(
    VfxFrame *watchFrame,
    vrt_frame_property_effect_funcptr_type callback,    
    void *userData,
    VfxU32 userDataSize,
    vrt_frame_property_effect_trigger_type_enum trigger_type)
{
    propEffectCallback peData = getPropertyEffectCallback();

    peData.frame = watchFrame;
        
    if (peData.callback != NULL)
    {
        VFX_FREE_MEM(peData.callback);
        peData.callback = NULL;
    }

    if (callback != NULL)
    {
        VfxU32 structSize = VRT_CALLBACK_STRUCT_SIZE(
            vrt_frame_property_effect_callback_struct, 
            userDataSize);

        VFX_ALLOC_MEM(peData.callback, structSize, this);
        peData.callback->callback = callback;
        peData.callback->trigger_type = trigger_type;
        peData.callback->user_data_size = userDataSize;
        if (userData != NULL)
        {
            VFX_ASSERT(userDataSize != 0);
            memcpy(
                VRT_CALLBACK_STRUCT_DATA(peData.callback),
                userData,
                userDataSize);
        }
        else
        {
            VFX_ASSERT(userDataSize == 0);
        }
    }
    else
    {
        VFX_ASSERT(userData == NULL && userDataSize == 0);
    }

    // Prepare handle
    if (m_handle != NULL)
    {
        if (watchFrame != NULL)
        {
            watchFrame->setHintFlag(VFX_FRAME_HINTS_WATCH_FRAME);
            if (watchFrame->m_handle == NULL)
            {
                watchFrame->processCreateHandle();
            }
            vrt_frame_set_property_effect_callback(
                m_handle,
                watchFrame->m_handle,
                peData.callback);
        }
        else
        {
            vrt_frame_set_property_effect_callback(
                m_handle,
                NULL,
                NULL);
        }
    }

    if(peData.frame == NULL && peData.callback == NULL)
        setAttachProperty(VFX_FRAME_PROP_ID_PROP_EFFECT, NULL, 0);
    else
        setAttachProperty(VFX_FRAME_PROP_ID_PROP_EFFECT, &peData, sizeof(peData));
    
}


VfxFrame::propEffectCallback &VfxFrame::getPropertyEffectCallback(void) const
{
    static propEffectCallback def = {NULL, NULL};

    propEffectCallback *v = (propEffectCallback*)getAttachProperty(VFX_FRAME_PROP_ID_PROP_EFFECT, sizeof(propEffectCallback));
    if(v)
        return *v;
    else
        return def;
}


void *VfxFrame::getPropertyEffectCallbackUserDataPtr() const
{
    return getPropertyEffectCallback().callback ?
        VRT_CALLBACK_STRUCT_DATA(getPropertyEffectCallback().callback) :
        NULL;
}


VfxU32 VfxFrame::getPropertyEffectCallbackUserDataSize() const
{
    return getPropertyEffectCallback().callback ?
        getPropertyEffectCallback().callback->user_data_size :
        0;
}


void VfxFrame::setPropertyMonitorCallback(
    vrt_frame_property_monitor_funcptr_type callback,    
    void *userData,
    VfxU32 userDataSize)
{
    propMonitorCallback pmData = getPropertyMonitorCallback();
        
    if (pmData.callback != NULL)
    {
        VFX_FREE_MEM(pmData.callback);
        pmData.callback = NULL;
    }

    if (callback != NULL)
    {
        VfxU32 structSize = VRT_CALLBACK_STRUCT_SIZE(
            vrt_frame_property_monitor_callback_struct, 
            userDataSize);

        VFX_ALLOC_MEM(pmData.callback, structSize, this);
        pmData.callback->callback = callback;
        pmData.callback->user_data_size = userDataSize;
        if (userData != NULL)
        {
            VFX_ASSERT(userDataSize != 0);
            memcpy(
                VRT_CALLBACK_STRUCT_DATA(pmData.callback),
                userData,
                userDataSize);
        }
        else
        {
            VFX_ASSERT(userDataSize == 0);
        }
    }
    else
    {
        VFX_ASSERT(userData == NULL && userDataSize == 0);
    }

    // Prepare handle
    if (m_handle != NULL)
    {
       vrt_frame_set_property_monitor_callback(
           m_handle,
           pmData.callback);
    }

    if(pmData.callback == NULL)
        setAttachProperty(VFX_FRAME_PROP_ID_PROP_MONITOR, NULL, 0);
    else
        setAttachProperty(VFX_FRAME_PROP_ID_PROP_MONITOR, &pmData, sizeof(pmData));
    
}


VfxFrame::propMonitorCallback &VfxFrame::getPropertyMonitorCallback(void) const
{
    static propMonitorCallback def = {NULL};

    propMonitorCallback *v = (propMonitorCallback*)getAttachProperty(VFX_FRAME_PROP_ID_PROP_MONITOR, sizeof(propMonitorCallback));
    if(v)
        return *v;
    else
        return def;
}


void *VfxFrame::getPropertyMonitorCallbackUserDataPtr() const
{
    return getPropertyMonitorCallback().callback ?
        VRT_CALLBACK_STRUCT_DATA(getPropertyMonitorCallback().callback) :
        NULL;
}


VfxU32 VfxFrame::getPropertyMonitorCallbackUserDataSize() const
{
    return getPropertyMonitorCallback().callback ?
        getPropertyMonitorCallback().callback->user_data_size :
        0;
}

void VfxFrame::onParentFrameChanged(VfxFrame *origParentFrame)
{
    VFX_UNUSED(origParentFrame);
    // do nothing
}


void VfxFrame::onDraw(VfxDrawContext &dc)
{
    VFX_UNUSED(dc);
    // do nothing
}


VfxBool VfxFrame::onContainPoint(const VfxPoint &point) const
{
    return getBounds().contains(point);
}


VfxBool VfxFrame::onContainPointFuzzy(const VfxPoint &point) const
{
    VfxRect bounds = getBounds();
    bounds.origin.x -= VFX_TOUCH_FINGER_WIDTH;
    bounds.origin.y -= VFX_TOUCH_FINGER_WIDTH;
    bounds.size.height += VFX_TOUCH_FINGER_WIDTH << 1;
    bounds.size.width += VFX_TOUCH_FINGER_WIDTH << 1;
    return bounds.contains(point);
}


void VfxFrame::registerBroadcastEvent(VfxFlag events)
{
    m_needBroadcastEvents = events;

    // Infect all parent frames
    VfxFrame *parentFrame = getParentFrame();
    if (parentFrame != NULL)
    {
        parentFrame->infectBroadcastEvent(m_needBroadcastEvents | m_childBroadcastEvents);
    }
}


void VfxFrame::broadcastEvent(VfxU32 eventId, void *eventData)
{
    VfxFrameBroadcastData param;
    param.eventId = eventId;
    param.sender = this;
    param.eventData = eventData;    
    processBroadcastEvent(param);
}


void VfxFrame::processBroadcastEvent(VfxFrameBroadcastData &param)
{
    if (VFX_FLAG_HAS(m_needBroadcastEvents, param.eventId))
    {
        onObjectNotify(VFX_FRAME_NOTIFY_ID_BROADCAST, &param);
    }

    if (!VFX_FLAG_HAS(m_childBroadcastEvents, param.eventId))
    {
        // No child need the event, do nothing
        return;
    }

    // Recursive for all child frames
    VfxFrame *i;
    for (i = getFirstChildFrame(); i != NULL; i = i->getNextFrame())
    {
        VfxFlag childNeedEvents = i->m_needBroadcastEvents | i->m_childBroadcastEvents;
        if (VFX_FLAG_HAS(childNeedEvents, param.eventId))
        {
            i->processBroadcastEvent(param);
        }
    }
}


void VfxFrame::infectBroadcastEvent(VfxFlag infectEvents)
{
    VfxFrame *i, *j;
    for (i = this; i != NULL; i = i->getParentFrame())
    {
        if (i->m_childBroadcastEvents == infectEvents)
        {
            break;
        }

        // If remove some events, then recaculate infect events with all children
        if (VFX_FLAG_HAS(i->m_childBroadcastEvents, ~infectEvents))
        {
            infectEvents = 0;
            for (j = i->getFirstChildFrame(); j != NULL; j = j->getNextFrame())
            {
                VFX_FLAG_SET(infectEvents, j->m_childBroadcastEvents | j->m_needBroadcastEvents);
            }
        }

        i->m_childBroadcastEvents = infectEvents;
        VFX_FLAG_SET(infectEvents, i->m_needBroadcastEvents);
    }
}


void VfxFrame::onInit()
{
    VfxAnimatable::onInit();

    setDirty();

    // Parent frame changed
    processParentFrameChanged(NULL);
}


void VfxFrame::onBeforeDeinit()
{
    setFocused(VFX_FALSE);

    VfxAnimatable::onBeforeDeinit();
}


void VfxFrame::onDeinit()
{
    // TODO: work-around to avoid free the filter or FPE
    if (getFilter() != NULL || 
        getOwnerDraw() != NULL || 
        getPropertyEffectCallback().callback != NULL)
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->suspendUntilCommit();

        if (getOwnerDraw() != NULL)
        {
            /* We should release 3D resource here before destroying owner draw */
            setOwnerDraw(NULL);
        }

        if (getFilter() != NULL)
        {
            setFilter(NULL);
        }
    }

    // Release handle
    if (m_handle != NULL)
    {
        processReleaseHandle();
    }

    // Free FPE data
    if (getPropertyEffectCallback().callback != NULL)
    {
        VFX_FREE_MEM(getPropertyEffectCallback().callback);
        getPropertyEffectCallback().callback = NULL;
    }

    
    // Free FPM data
    if (getPropertyMonitorCallback().callback != NULL)
    {
        VFX_FREE_MEM(getPropertyMonitorCallback().callback);
        getPropertyMonitorCallback().callback = NULL;
    }
    
    VfxAnimatable::onDeinit();
}


void VfxFrame::onAfterDeinit()
{
    // Remove all relation to child frames
    clearChildFrames();
    // Remove the relation to parent frame
    removeFromParentFrame();

    // TODO: need to improve performance
    // Remove from null parent list    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->removeFromNullParentFrameList(this);

    VfxAnimatable::onAfterDeinit();
}


void VfxFrame::onAddChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxFrame *frameChild = VFX_OBJ_DYNAMIC_CAST(objChild, VfxFrame);
    if (frameChild != NULL)
    {
        addChildFrame(frameChild);
    }
}


void VfxFrame::onRemoveChild(VfxObject *objChild)
{
    VFX_OBJ_ASSERT_VALID(objChild);
    
    VfxFrame *frameChild = VFX_OBJ_DYNAMIC_CAST(objChild, VfxFrame);
    if (frameChild != NULL)
    {
        frameChild->removeFromParentFrame();
    }
}


void VfxFrame::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_ANIMATABLE_NOTIFY_ID_ADD_TIMELINE:
        case VFX_ANIMATABLE_NOTIFY_ID_REMOVE_TIMELINE:
        {
            setNeedPrepare();
            return ;
        }
        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT:
        {
            onAfterDeinit();
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            onAddChild((VfxObject *)userData);
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD:
        {
            onRemoveChild((VfxObject *)userData);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_QUERY_FOCUS_CHANGE:
        {
            VfxFrameQueryFocusChangeData *para = (VfxFrameQueryFocusChangeData *)userData;
            para->ret = queryFocusChange(para->childFrame);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
        {
            VfxFrameImeModeEnum ret = getImeMode();
            *((VfxFrameImeModeEnum *)userData) = ret;
            return;
        }
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_RESIZE:
        {
            VfxFrameAdjustImeResizeData *para = (VfxFrameAdjustImeResizeData *)userData;
            adjustImeResize(para->size, para->focusFrame);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_SHIFT:
        {
            VfxFrameAdjustImeShiftData *para = (VfxFrameAdjustImeShiftData *)userData;
            adjustImeShift(para->pos, para->focusFrame);
            return;
        }
        case VFX_FRAME_NOTIFY_ID_UPDATE_VIEW_FOR_IME:
        {
            VfxFrameUpdateViewForImeData *para = (VfxFrameUpdateViewForImeData *)userData;
            para->ret = updateViewForIme((VfxFrame *)para->focusFrame);
            return;
        }
        default:
        {
            VfxObject::onObjectNotify(id, userData);
            return;
        }
    }
}


VfxFrameImeModeEnum VfxFrame::processGetImeMode()
{
    VfxFrameImeModeEnum ret;

    onObjectNotify(VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE, (void *)&ret);
    return ret;
}


void VfxFrame::processAdjustImeShift(const VfxPoint &pos, VfxFrame *focusFrame)
{
    VfxFrameAdjustImeShiftData data = {pos, focusFrame};
    data.pos = pos;
    data.focusFrame = focusFrame;

    onObjectNotify(VFX_FRAME_NOTIFY_ID_ADJUST_IME_SHIFT, (void *)&data);
}


void VfxFrame::processAdjustImeResize(const VfxSize &size, VfxFrame *focusFrame)
{
    VfxFrameAdjustImeResizeData data;
    data.size = size;
    data.focusFrame = focusFrame;

    onObjectNotify(VFX_FRAME_NOTIFY_ID_ADJUST_IME_RESIZE, (void *)&data);
}


VfxBool VfxFrame::processUpdateViewForIme(VfxFrame *focusFrame)
{
    VfxFrameUpdateViewForImeData data;
    data.focusFrame = focusFrame;
    data.ret = VFX_FALSE;

    onObjectNotify(VFX_FRAME_NOTIFY_ID_UPDATE_VIEW_FOR_IME, (void *)&data);
    return data.ret;
}


VfxBool VfxFrame::prepareHandle()
{
    // NOTE:
    //  Assert here if the frame forget to call super class's onInit()
    VFX_ASSERT(!isInitializing());
    
    // The frame doesn't need to prepare
    if (!VFX_FLAG_HAS(m_flags, FLAGS_NEED_PREPARE))
    {
        return VFX_FALSE;
    }
    VFX_FLAG_CLEAR(m_flags, FLAGS_NEED_PREPARE | FLAGS_HAS_PARENT_CHANGED);

    // prepare frame handle
    if (m_handle == NULL)
    {
        processCreateHandle();
    }
    VFX_DEV_ASSERT(m_handle != NULL);

    VfxBool needUpdateScene = VFX_FALSE;

    // Check if need to redraw
    if (VFX_FLAG_HAS(m_flags, FLAGS_CONTENT_DIRTY))
    {
        //VFX_FLAG_CLEAR(m_flags, FLAGS_CONTENT_DIRTY);
        
        vrt_frame_set_content_dirty(m_handle);

        needUpdateScene = VFX_TRUE;
    }

    if (m_lastParentFrameNum > 0)
    {
        m_lastParentFrameNum = 0;
        
        vrt_frame_set_content_dirty(m_handle);
        
        needUpdateScene = VFX_TRUE;
    }

    // prepare all enabled timelines
    VfxAnimatable::prepareAnimationHandle();

    // prepare all child frames
    VfxFrame *childFrame;
    for (childFrame = m_firstChildFrame; 
        childFrame != NULL; 
        childFrame = childFrame->m_nextFrame)
    {
        if (childFrame->prepareHandle())
        {
            needUpdateScene = VFX_TRUE;
        }
    }

    // If the frame is hidden, it does't need to update scene graph
    //  When a frame set hidden first time, its parent frame will set dirty
    if (getHidden())
    {
        return VFX_FALSE;
    }

    return needUpdateScene;
}


void VfxFrame::disposeHandle()
{
#ifdef __VENUS_3D_UI_ENGINE__
    // dispose material
    if (m_material.get())
    {
        m_material->disposeHandle();
    }

    // dispose world
    if (m_world.get())
    {
        m_world->disposeHandle();
    }
#endif

    // dispose all child frames
    VfxFrame *childFrame;
    for (childFrame = m_lastChildFrame; 
        childFrame != NULL; 
        childFrame = childFrame->m_prevFrame)
    {
        childFrame->disposeHandle();
    }

    // dispose all enabled timelines
    VfxAnimatable::disposeAnimationHandle();

    if (m_handle != NULL)
    {
        processReleaseHandle();
        setDirty();
    }
}


void VfxFrame::resetProperty(vrt_object_property_id_enum propertyId)
{
    switch (propertyId)
    {
        case VRT_OBJECT_PROPERTY_ID_UNKNOWN:
            // Do nothing
            break;
            
        case VRT_FRAME_PROPERTY_ID_POS:
        case VRT_FRAME_PROPERTY_ID_POS_X:            
        case VRT_FRAME_PROPERTY_ID_POS_Y:
        {
            vrt_point_struct vrtValue = getPos();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_POS,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
        
        case VRT_FRAME_PROPERTY_ID_POS_Z:
        {
            vrt_float vrtValue = getPosZ();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_POS_Z,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
        
        case VRT_FRAME_PROPERTY_ID_BOUNDS:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_X:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_Y:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_WIDTH:
        case VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_HEIGHT:
        {
            vrt_rect_struct vrtValue = getBounds();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_BOUNDS,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }

        case VRT_FRAME_PROPERTY_ID_OPACITY:
        {
            vrt_float vrtValue = (vrt_float)getOpacity();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_OPACITY,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_ANCHOR_POINT:
        case VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_X:
        case VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_Y:
        {
            vrt_fpoint_struct vrtValue = getAnchor();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_ANCHOR_POINT,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_TRANSFORM:
        case VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SX:
        case VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SY:    
        case VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ:    
        case VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TX:    
        case VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TY:    
        {
            vrt_transform_struct vrtValue;
            getTransform().initVrtTransform(vrtValue);
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_TRANSFORM,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR:
        {
            vrt_color_type vrtValue = getBgColor();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_BORDER_COLOR:
        {
            vrt_color_type vrtValue = getBorderColor();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_BORDER_COLOR,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_BORDER_WIDTH:
        {
            vrt_s32 vrtValue = (vrt_s32)getBorderWidth();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_BORDER_WIDTH,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }
            
        case VRT_FRAME_PROPERTY_ID_FILTER_TIMING:
        {
            vrt_float vrtValue = (vrt_float)getFilterTiming();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_FILTER_TIMING,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }        
        
        case VRT_FRAME_PROPERTY_ID_FPE_USER_0:
        {
            vrt_float vrtValue = (vrt_float)getFpeUser0();
            vrt_object_add_property_timeline(
                m_handle,
                VRT_FRAME_PROPERTY_ID_FPE_USER_0,
                &vrtValue,
                &vrtValue,
                sizeof(vrtValue),
                0,
                NULL);
            break;
        }  

        case VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT:
        case VRT_FRAME_PROPERTY_ID_VIRTUAL_DIRTY:
        case VRT_FRAME_PROPERTY_ID_VIRTUAL_CONTENT_DIRTY:
            break;

        default:
            VFX_DEV_ASSERT(0);
    };    
}


void VfxFrame::processDraw(VfxDrawContext &dc)
{
   VFX_FLAG_CLEAR(m_flags, FLAGS_CONTENT_DIRTY | FLAGS_HAS_CHILD_DIRTY | FLAGS_NEED_UPDATE_CMDS);

    VfxFrameFilter *filter = getFilter();
    if (filter)
    {
        VfxU32 i;
        for (i = 0; i < filter->m_ImageSrcList.getCount(); ++i)
        {
            dc.setResource(filter->m_ImageSrcList.getItemWithIndex(i));
        }
    }

    VfxOwnerDraw *ownerDraw = getOwnerDraw();
    if (ownerDraw)
    {
        VfxU32 i;
        for (i = 0; i < ownerDraw->m_ImageSrcList.getCount(); ++i)
        {
            dc.setResource(ownerDraw->m_ImageSrcList.getItemWithIndex(i));
        }
    }
    
    const VfxResId imageId = getFallbackImage();
    if (imageId != 0 )
    {
        dc.setFallbackImage(imageId);
    }

    const VfxImageSrc &imageContent = getImgContent();    
    if (!imageContent.isNull())
    {
        // Draw image content        
        VfxU32 commandIndex = dc.drawImageContent(
            imageContent, 
            (VfxFrameContentPlacementTypeEnum)getContentPlacement());
        if (commandIndex != 0)
        {
            // Because the scene graph deosn't commit yet, the new index will be next.
            //  So index add 1
            m_imgContentCommandIndex = commandIndex;
            m_imgContentCommitCounter = vrt_frame_get_commit_counter() + 1; 
        }
        else
        {
            m_imgContentCommitCounter = 0;
        }        
    }
#ifdef __VENUS_3D_UI_ENGINE__
    else if (m_world.get())
    {
        dc.drawWorld(m_world.get());
    }
#endif
    else
    {
        // No image content, use virtual function onDraw()
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XDC", SA_start);
#endif
        onDraw(dc);
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("XDC", SA_stop);
#endif
    }    
}


void VfxFrame::processCreateHandle()
{
    VfxAnimatable::processCreateHandle();
    
    // The method only can be used without handle
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_frame_create(this);
    // Out of memory
    VFX_ASSERT(m_handle != NULL);

    // Initialize properties
    vrt_frame_visual_property_struct *property = vrt_frame_init_property(m_handle);
    property->pos               = getPos();
    property->pos_z             = getPosZ();
    property->bounds            = getBounds();
    property->anchor_point      = getAnchor();
    property->opacity           = getOpacity();
    getTransform().initVrtTransform(property->transform);    
    property->background_color  = getBgColor();
    property->border_color      = getBorderColor();
    property->border_width      = getBorderWidth();
    property->filter_timing     = getFilterTiming();
    property->fpe_user_0        = getFpeUser0();
    
    if (getFilter() != NULL)
    {
        vrt_frame_set_filter(m_handle, static_cast<IVrtFrameFilter *>(getFilter()));
    }

    if (getOwnerDraw() != NULL)
    {
        vrt_frame_set_owner_draw(m_handle, static_cast<IVrtOwnerDraw *>(getOwnerDraw()));
    }

    if (getPropertyEffectCallback().callback != NULL)
    {
        VfxFrame *peFrm = getPropertyEffectCallback().frame;
        VFX_DEV_ASSERT(peFrm != NULL);
        
        if (peFrm->m_handle == NULL)
        {
            peFrm->processCreateHandle();
        }
        
        vrt_frame_set_property_effect_callback(
            m_handle,
            peFrm->m_handle,
            getPropertyEffectCallback().callback);
    }

    if (getPropertyMonitorCallback().callback != NULL)
    {
        vrt_frame_set_property_monitor_callback(
            m_handle,
            getPropertyMonitorCallback().callback);
    }

#ifdef __VENUS_3D_UI_ENGINE__
    if (m_material != NULL)
    {
        vrt_frame_set_material(m_handle, m_material->getSyncHandle());
    }

    if (m_world != NULL)
    {
        vrt_frame_set_world(m_handle, m_world->getSyncHandle());
    }
#endif

    vrt_frame_set_opaque_mode(m_handle, (vrt_frame_opaque_mode_enum)getOpaqueMode());
    vrt_frame_set_quality(m_handle, (vrt_render_quality_enum)getQuality());
    vrt_frame_set_is_cached(m_handle, (vrt_bool)getIsCached());
    vrt_frame_set_cache_mode(m_handle, (vrt_cache_mode_enum)getCacheMode());
    vrt_frame_set_culling_type(m_handle, (vrt_frame_culling_type_enum)getCullingType());
    vrt_frame_set_is_z_sort_child(m_handle, (vrt_bool)getIsZSortChild());
    vrt_frame_set_hints(m_handle, (vrt_frame_hints_enum)getHints());
    vrt_frame_set_layer_frame(m_handle, (vrt_u32)getLayerHandle());
}


void VfxFrame::processReleaseHandle()
{
    VFX_DEV_ASSERT(m_handle != NULL);

    // Because the frame handle will be released,
    //  the image content index has no used anymore.
    m_imgContentCommitCounter = 0;
    
    vrt_frame_release(m_handle);
    m_handle = NULL;

    VfxAnimatable::processReleaseHandle();
}


void VfxFrame::processParentFrameChanged(VfxFrame *origParentFrame)
{
    VfxFrame *newParentFrame = m_parentFrame;

    // Update dirty state
    if (origParentFrame != NULL)
    {
        if (VFX_FLAG_HAS(m_flags, FLAGS_HAS_PARENT_CHANGED))
        {
			if (origParentFrame->m_lastParentFrameNum > 0)
			{
				origParentFrame->m_lastParentFrameNum--;
				origParentFrame->setNeedPrepare();
			}
			else
			{
				origParentFrame->setDirty();
			}
        }
		else
		{
		    origParentFrame->setDirty();
		}
    }
    if (newParentFrame != NULL)
    {
        newParentFrame->setNeedPrepare();
        newParentFrame->m_lastParentFrameNum++;
		VFX_FLAG_SET(m_flags, FLAGS_HAS_PARENT_CHANGED);
    }

    // Update renderer null parent frame list    
    // (From NULL parent to NULL parent is oaky for this method)
    if (newParentFrame != NULL)
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->removeFromNullParentFrameList(this);
    }
    else
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->addToNullParentFrameList(this);
        if (!VFX_FLAG_HAS(m_flags, FLAGS_NEED_UPDATE_CMDS))
        {
            markNeedUpdateCmds();
        }
    }

    // Return if change the frame order only
    if (origParentFrame == newParentFrame)
    {
        return;
    }

    // Update broadcast events    
    if (origParentFrame != NULL)
    {
        origParentFrame->infectBroadcastEvent(0);
    }
    if (newParentFrame != NULL)
    {
        newParentFrame->infectBroadcastEvent(m_needBroadcastEvents | m_childBroadcastEvents);
    }
    
    // Callback
    onObjectNotify(VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED, (void *)origParentFrame);
}


void VfxFrame::setNeedPrepare()
{
    VfxFrame *i;
    for (i = this; i != NULL; i = i->getParentFrame())
    {
        if (VFX_FLAG_HAS(i->m_flags, FLAGS_NEED_PREPARE) &&  VFX_FLAG_HAS(i->m_flags, FLAGS_HAS_CHILD_DIRTY))
        {
            break;
        }
        VFX_FLAG_SET(i->m_flags, FLAGS_NEED_PREPARE);
        VFX_FLAG_SET(i->m_flags, FLAGS_HAS_CHILD_DIRTY);
    }
}

VfxBool VfxFrame::hasChildDirty()
{
    return VFX_FLAG_HAS(m_flags, FLAGS_HAS_CHILD_DIRTY);
}

VfxBool VfxFrame::isNeedUpdate()
{
    return VFX_FLAG_HAS(m_flags, (FLAGS_CONTENT_DIRTY | FLAGS_NEED_UPDATE_CMDS | FLAGS_UPDATE_ALWAYS));
}


void VfxFrame::setDirty()
{
    VFX_FLAG_SET(m_flags, FLAGS_CONTENT_DIRTY);

    setNeedPrepare();
}


void VfxFrame::clearChildFrames()
{
    VfxFrame *i = m_firstChildFrame;
    
    // Remove all child frames from child list.
    m_firstChildFrame = NULL;
    m_lastChildFrame = NULL;

    while (i != NULL)
    {
        VfxFrame *next = i->m_nextFrame;
        i->m_parentFrame = NULL;
        i->m_prevFrame = NULL;
        i->m_nextFrame = NULL;
        i->processParentFrameChanged(this);
        i = next;
    }
}


void VfxFrame::convertPointFromParent(VfxPoint &point, VfxBool transform) const
{
    VfxPoint        frame_pos       = getPos();
    VfxRect         frame_bounds    = getBounds();
    VfxFPoint       frame_anchor    = getAnchor();
    VfxTransform    frame_trans     = getTransform();

    point.x += -frame_pos.x + (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
    point.y += -frame_pos.y + (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;

    if (transform && frame_trans.type == VFX_TRANSFORM_TYPE_AFFINE && !frame_trans.isIdentity())
    {
        point.x -= (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
        point.y -= (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;

        vrt_transform_struct tmp;
        VfxMatrix3x3Ex m;
        frame_trans.initVrtTransform(tmp);
        m.setAffine(tmp.data.affine);
        m.inverse();
        point = m.transform(point);

        point.x += (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
        point.y += (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;
    }
}


void VfxFrame::convertPointToParent(VfxPoint &point, VfxBool transform) const
{
    VfxPoint        frame_pos       = getPos();
    VfxRect         frame_bounds    = getBounds();
    VfxFPoint       frame_anchor    = getAnchor();
    VfxTransform    frame_trans     = getTransform();
    
    if (transform && frame_trans.type == VFX_TRANSFORM_TYPE_AFFINE && !frame_trans.isIdentity())
    {
        point.x -= (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
        point.y -= (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;

        vrt_transform_struct tmp;
        VfxMatrix3x3Ex m;
        frame_trans.initVrtTransform(tmp);
        m.setAffine(tmp.data.affine);
        point = m.transform(point);

        point.x += (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
        point.y += (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;
    }

    point.x += -frame_bounds.origin.x - (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_pos.x;
    point.y += -frame_bounds.origin.y - (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_pos.y;
}


void VfxFrame::convertRectFromParent(VfxRect &rect) const
{
    VfxPoint  frame_pos       = getPos();
    VfxRect   frame_bounds    = getBounds();
    VfxFPoint frame_anchor    = getAnchor();
    
    // TODO: transform
    rect.origin.x += -frame_pos.x + (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_bounds.origin.x;
    rect.origin.y += -frame_pos.y + (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_bounds.origin.y;
}


void VfxFrame::convertRectToParent(VfxRect &rect) const
{
    VfxPoint  frame_pos       = getPos();
    VfxRect   frame_bounds    = getBounds();
    VfxFPoint frame_anchor    = getAnchor();
    
    // TODO: transform
    rect.origin.x += -frame_bounds.origin.x - (VfxS32)(frame_bounds.size.width * frame_anchor.x) + frame_pos.x;
    rect.origin.y += -frame_bounds.origin.y - (VfxS32)(frame_bounds.size.height * frame_anchor.y) + frame_pos.y;
}

