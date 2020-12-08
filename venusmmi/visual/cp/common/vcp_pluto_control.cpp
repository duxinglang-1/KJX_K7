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
 *  vcp_pluto_control.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Adaptor to Pluto UI component 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For __MMI_VUI_COSMOS_CP_SLIM__
#include "mmi_features.h"

#include "vcp_pluto_control.h"

#include "vadp_v2p_inputbox.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vfx_renderer.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_draw_context.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_sys_memory.h"
#include "vfx_font_desc.h"
#include "vfx_string.h"

extern "C"
{
#include "GlobalResDef.h"

#include "MMIDataType.h"
#include "gui_data_types.h"
#ifdef  __MED_IN_ASM__
#include "app_mem_med.h"
#else
#include "med_utility.h"
#endif
#include "med_smalloc.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_mutex.h"

#include "PixcomFontEngine.h"

#include "mmi_frm_input_gprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/          

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


/***************************************************************************** 
 * Class VcpPlutoControl 
 *****************************************************************************/          

VFX_IMPLEMENT_VIRTUAL_CLASS("PlutoControl", VcpPlutoControl, VfxControl);

VcpPlutoControl::VcpPlutoControl() :
    m_isNeedRedrawPluto(VFX_FALSE),
    m_layerForPluto(0),
    m_gdiLayerBuffer(NULL),
    m_layerBufferSize(0),
    m_gdiCurrLockIndex(-1)
{
}


void VcpPlutoControl::beginUseGdiLayer()
{
    VFX_DEV_ASSERT(m_layerForPluto != NULL);
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPT", SA_start);
#endif

    // Work around solution, to safty use GDI layer buffer
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit();
    
    gdi_layer_push_and_set_active((gdi_handle) m_layerForPluto);

    // set alpha blending source layer to the same layer because VRT can do alpha blending later
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle) m_layerForPluto);    

    // Note: Get layer lock count after gdi_layer_push_and_set_active()
    // because gdi_layer_push_and_set_active() also acquires GDI lock, 
    // and it enters a critical section here.
    m_gdiCurrLockIndex++;
    VFX_ASSERT(m_gdiCurrLockIndex >= 0 && m_gdiCurrLockIndex < MAX_USE_GDI_LAYER_DEPTH);
    m_gdiCurrLockCnt[m_gdiCurrLockIndex] = gdi_fast_mutex_get_count();   
}


void VcpPlutoControl::endUseGdiLayer()
{
    VFX_DEV_ASSERT(m_layerForPluto != NULL);
    
    // Pluto UI component must use GDI mutex correctly; otherwise, it may make VRT crash
    // The following API must be paired well in Pluto code:
    //      1. gdi_layer_push_clip()/gdi_layer_pop_clip() 
    //      2. gdi_layer_lock_frame_buffer()/gdi_layer_unlock_frame_buffer()
    VFX_ASSERT(m_gdiCurrLockIndex >= 0);    
    VFX_ASSERT(m_gdiCurrLockCnt[m_gdiCurrLockIndex] == gdi_fast_mutex_get_count());
    m_gdiCurrLockIndex--;

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XPT", SA_stop);
#endif
}


void VcpPlutoControl::onInit()
{
    VfxControl::onInit();
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    // Get the preferred size (if available)
    VfxSize preferredSize = onPlutoGetPreferredSize();
    if (!preferredSize.isZero())
    {
        // change the size of bounds
        setSize(preferredSize);
    }

    // Property value changed callback
    m_signalBoundsChanged.connect(this, &VcpPlutoControl::onPropertyBoundsChanged);
}


VfxBool VcpPlutoControl::onPenInput(VfxPenEvent & event)
{
    if (m_layerForPluto == NULL)
    {
        // layer is not created, do nothing
        return VFX_FALSE;
    }
    
    if (!onPlutoAcceptPenEvents())
    {
        return VFX_FALSE;
    }

    VfxS32 plutoPenEvent;
    VfxBool isStrokeEvent;
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            plutoPenEvent = MMI_PEN_EVENT_DOWN;
            isStrokeEvent = VFX_FALSE;
            break;
            
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            plutoPenEvent = MMI_PEN_EVENT_LONG_TAP;
            isStrokeEvent = VFX_FALSE;
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            plutoPenEvent = MMI_PEN_EVENT_MOVE;
            isStrokeEvent = VFX_FALSE;
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            plutoPenEvent = MMI_PEN_EVENT_UP;
            isStrokeEvent = VFX_FALSE;
            break;
            
        case VFX_PEN_EVENT_TYPE_ABORT:
            plutoPenEvent = MMI_PEN_EVENT_ABORT;
            isStrokeEvent = VFX_FALSE;
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
            plutoPenEvent = MMI_PEN_STROKE_DOWN;
            isStrokeEvent = VFX_TRUE;
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
            plutoPenEvent = MMI_PEN_STROKE_MOVE;
            isStrokeEvent = VFX_TRUE;
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_UP:
            plutoPenEvent = MMI_PEN_STROKE_UP;
            isStrokeEvent = VFX_TRUE;
            break;

        default:
            plutoPenEvent = MMI_PEN_EVENT_ABORT;
            isStrokeEvent = VFX_FALSE;
            VFX_ASSERT(0);
    }


    VfxPoint pos = event.getRelPos(this);
    VfxBool ret;
    
    beginUseGdiLayer();
    // Pluto CP may invoke updateScreenForPluto() here
    if (isStrokeEvent)
    {
        ret = onPlutoStrokeHandler(plutoPenEvent, (VfxS16) pos.x, (VfxS16) pos.y); 
    }
    else
    {
        ret = onPlutoPenHandler(plutoPenEvent, (VfxS16) pos.x, (VfxS16) pos.y); 
    }
    endUseGdiLayer();

    return ret;
}


void VcpPlutoControl::onDraw(VfxDrawContext &dc)
{
    if (!m_layerForPluto)
    {
        return;
    }
    
    /* Draw on Pluto */
    drawPlutoComponent();

    // Initialize a image buffer and draw
    VfxImageBuffer imageBuf;
    initImageBufferByGdiLayer(imageBuf, m_layerForPluto);
    dc.drawImageBuffer(getBounds().origin, imageBuf);
}


void VcpPlutoControl::onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    if (!m_layerForPluto)
    {
        return;
    }
    
    // Work around solution, to safty use GDI layer buffer
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit();
    
    // Free Pluto layer
    freeGdiLayer();
    // Create new Pluto layer
    createGdiLayer();

    resizePlutoComponent();
}


void VcpPlutoControl::initImageBufferByGdiLayer(VfxImageBuffer &imageBuf, VfxU32 handle)
{
    gdi_layer_struct *layer = (gdi_layer_struct *)handle;
    VFX_DEV_ASSERT(layer != NULL);

    VfxColorTypeEnum colorFormat;
    switch (layer->vcf)
    {
        case GDI_COLOR_FORMAT_16:
            colorFormat = VRT_COLOR_TYPE_RGB565;
            break;
        case GDI_COLOR_FORMAT_32:
            colorFormat = VRT_COLOR_TYPE_ARGB8888;
            break;
        case GDI_COLOR_FORMAT_32_PARGB:
            colorFormat = VRT_COLOR_TYPE_PARGB8888;
            break;
        default:
            VFX_DEV_ASSERT(0);
            colorFormat = VRT_COLOR_TYPE_UNKNOWN;
            break;
    };

    imageBuf.ptr            = layer->buf_ptr;
    imageBuf.pitchBytes     = layer->width * layer->bits_per_pixel / 8;
    imageBuf.width          = layer->width;
    imageBuf.height         = layer->height;
    imageBuf.colorFormat    = colorFormat;
}


void VcpPlutoControl::freeGdiLayer()
{
    m_isNeedRedrawPluto = VFX_FALSE;
    
    if (m_layerForPluto == NULL)
    {
        VFX_DEV_ASSERT(m_gdiLayerBuffer == NULL);
        VFX_DEV_ASSERT(m_layerBufferSize == 0);
        
        // Do nothing
        return;
    }

    VFX_DEV_ASSERT(m_gdiLayerBuffer != NULL);
    VFX_DEV_ASSERT(m_layerBufferSize != 0);
        
    gdi_layer_free((gdi_handle) m_layerForPluto);
    
#ifdef  __MED_IN_ASM__
    applib_asm_free_anonymous((void*) m_gdiLayerBuffer);
#else
    med_free_ext_mem((void **) &m_gdiLayerBuffer);
#endif
    
    m_layerForPluto = 0;
    m_gdiLayerBuffer = NULL;    
    m_layerBufferSize = 0;
}


void VcpPlutoControl::createGdiLayer()
{
    //VFX_DEV_ASSERT(m_layerForPluto == 0);
    //VFX_DEV_ASSERT(m_gdiLayerBuffer == NULL);
    //VFX_DEV_ASSERT(m_layerBufferSize == 0);
    if (m_layerForPluto != NULL)
    {
        //already create layer
        return;
    }

    VfxSize size = getCurrentSize();
    if (size.isZero())
    {
        size = VfxSize(1, 1);
    }

    VfxU32 layer_pixel_size;
    gdi_color_format layer_cf;
    VfxBool use_source_key;
    if (onPlutoNeedAlphaChannel())
    {
        layer_pixel_size = 4;
    #ifdef GDI_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT
        // Use HW support for PARGB8888
        layer_cf = GDI_COLOR_FORMAT_32_PARGB;
    #else /* GDI_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT */
        // Use HW support for ARGB8888
        layer_cf = GDI_COLOR_FORMAT_32;
    #endif /* GDI_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT */
        use_source_key = VFX_FALSE;
    }
    else
    {
        layer_pixel_size = 2;
        layer_cf = GDI_COLOR_FORMAT_16;
        use_source_key = VFX_TRUE;        
    }

    // Caculate bufferSize, up-align size to 4
    VfxU32 frameBufferSize = (size.width * size.height * layer_pixel_size + 3) & (~3);
    
#ifdef  __MED_IN_ASM__
    VfxU8 *frameBuffer = (VfxU8 *) applib_asm_alloc_anonymous_nc(frameBufferSize);
#else
    VfxU8 *frameBuffer = (VfxU8 *) med_alloc_ext_mem_topmost_noncacheable(frameBufferSize);
#endif

    // Set image content if the buffer doesn't created
    if (frameBuffer == NULL)
    {
        setImgContent(VfxImageSrc(IMG_GLOBAL_DEFAULT));
        
        m_layerBufferSize = 0;
        m_gdiLayerBuffer = NULL;
        return;
    }

    // Clear image content
    setImgContent(VFX_IMAGE_SRC_NULL);

    // Create GDI Layer for pluto control
    gdi_layer_create_cf_using_outside_memory(
        layer_cf, 
        0, 
        0, 
        size.width, 
        size.height, 
        (gdi_handle *) &m_layerForPluto, 
        frameBuffer, 
        frameBufferSize);
    // Out of layer handle
    VFX_ASSERT(m_layerForPluto != NULL);
    m_layerBufferSize = frameBufferSize;
    m_gdiLayerBuffer = frameBuffer;

    // Setup layer
    gdi_layer_push_and_set_active((gdi_handle) m_layerForPluto);
    gdi_layer_set_source_key(use_source_key, GDI_COLOR_TRANSPARENT); // do not use source color key
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);    
    gdi_layer_pop_and_restore_active();
}


void VcpPlutoControl::clearLayerBackground()
{
    if (m_layerForPluto == NULL)
    {
        return;
    }

    gdi_layer_push_and_set_active((gdi_handle) m_layerForPluto);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
}


void VcpPlutoControl::createPlutoComponent()
{
    if (m_layerForPluto == NULL)
    {
        // layer is not created, do nothing
        return;
    }
    
    beginUseGdiLayer();
    onPlutoCreate();
    m_isNeedRedrawPluto = VFX_TRUE;    
    endUseGdiLayer();
}

void VcpPlutoControl::processCreateHandle()
{
    VfxControl::processCreateHandle();
    
    createGdiLayer();
    createPlutoComponent();
    
    m_isNeedRedrawPluto = VFX_TRUE;    
}


void VcpPlutoControl::processReleaseHandle()
{
    closePlutoComponent();
    freeGdiLayer();
    
    VfxControl::processReleaseHandle();
}


void VcpPlutoControl::closePlutoComponent()
{
    if (m_layerForPluto == NULL)
    {
        // layer is not created, do nothing
        return;
    }
    
    beginUseGdiLayer();
    onPlutoClose();
    m_isNeedRedrawPluto = VFX_FALSE;        
    endUseGdiLayer();
}


void VcpPlutoControl::drawPlutoComponent()
{
    if (m_layerForPluto == NULL)
    {
        // layer is not created, do nothing
        return;
    }
    
    if (!m_isNeedRedrawPluto)
    {
        // No need to redraw, do nothing
        return;
    }
    
    m_isNeedRedrawPluto = VFX_FALSE;    

    beginUseGdiLayer();
    onPlutoDraw();
    endUseGdiLayer();

    VfxRendererProfiling::setHasPlutoControl();
}


void VcpPlutoControl::resizePlutoComponent()
{
    if (m_layerForPluto == NULL)
    {
        // layer is not created, do nothing
        return;
    }
    
    beginUseGdiLayer();
    onPlutoResize();
    setNeedRedrawPluto();
    endUseGdiLayer();
}


void VcpPlutoControl::updateScreenForPluto(void *object)
{
    VcpPlutoControl *pc = (VcpPlutoControl *) object;

    VFX_OBJ_ASSERT_VALID(pc);

    //pc->invalidate();
    pc->setContentDirty();

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();
}

void VcpPlutoControl::updateScreenForPlutoNeedRedraw(void *object)
{
    VcpPlutoControl *pc = (VcpPlutoControl *) object;

    VFX_OBJ_ASSERT_VALID(pc);

    pc->m_isNeedRedrawPluto = VFX_TRUE;   

    pc->invalidate();
}


void VcpPlutoControl::setNeedRedrawPluto() 
{
    m_isNeedRedrawPluto = VFX_TRUE; 
    invalidate();
}

void VcpPlutoControl::setNeedSwapDoubleBuffer() 
{
    invalidate();
}


#if 0  //phase out
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */
/* under construction !*/
#endif
