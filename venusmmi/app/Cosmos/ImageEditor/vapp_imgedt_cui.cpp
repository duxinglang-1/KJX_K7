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
 *  vapp_imgto_editor.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
extern "C" 
{
    #include "MMI_features.h" 
}

#ifdef __MMI_COSMOS_PHOTOEDITOR__

#include "vapp_imgedt_gprot.h"
#include "vapp_imgedt_cui.h"
#include "vapp_imgedt_util.h"
#include "mmi_rp_vapp_imgedt_def.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vcp_res.h"


extern "C"
{
#include "gdi_layer.h"
#include "gd_include.h"
#include "gdi_include.h"
#include "kal_public_api.h"
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "mmi_rp_srv_filemanager_def.h" //need error id
#include "Mmi_cb_mgr_gprot.h" 
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif /*__MMI_USB_SUPPORT__*/
#ifdef __DRM_SUPPORT__
#include "Drm_Gprot.h"
#endif
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    #define __COSMOS_PHOTEDT_SMALL_SCREEN_SYTLE__
#endif /* (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) */
 
typedef struct ScrollPanelStruct_s
{
    VfxS32   pos;
    VfxS32   type;
    VfxResId strid;
    VfxResId icon;
    void     (*enter_func)(VappImgEdtBasePage**, VfxObject*, void* param);

}ScrollPanelStruct;

void dummy_func(void){};

typedef enum
{
    IMGEDT_MATTS_COLOR,
    IMGEDT_MATTS_CLIPART,
    IMGEDT_MATTS_DOODLE,

    IMGEDT_MATTS_TOTAL
} cosmos_imgedt_matts_style_enum;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

// ImgEdtSrv running memory
#if defined(__MMI_COSMOS_IMGEDT_SLIM__)
static const VfxS32   IMGEDT_IES_SRV_MEM_SIZE_FULL = 1024*1024*6;
#elif defined(__MMI_COSMOS_IMGEDT_PARTIAL__)
static const VfxS32   IMGEDT_IES_SRV_MEM_SIZE_FULL = 1024*1024*8;
#else
static const VfxS32   IMGEDT_IES_SRV_MEM_SIZE_FULL = 1024*1024*10;
#endif /* __MMI_COSMOS_IMGEDT_SLIM__ */

static const VfxFloat IMGEDT_BUTTON_DISABLE_OPACITY = 0.3f;

static const VfxS32   IMGEDT_DOODLE_UPDATE_INTERVAL = 15;

static const ScrollPanelStruct m_scrollPanelInfo[EDIT_TOTAL] = 
{
    {0, EDIT_ROTATE,  STR_ID_VAPP_IMGEDT_ROTATE,  IMG_ID_IMGEDT_TITLEBAR_ROTATE,  &VappImgEdtRotatePage::enterRotatePage},        
    {1, EDIT_CROP,    STR_ID_VAPP_IMGEDT_CROP,    IMG_ID_IMGEDT_TITLEBAR_CLIP,    &VappImgEdtClipPage::enterClipPage},
    {2, EDIT_ADJUST,  STR_ID_VAPP_IMGEDT_ADJUST,  IMG_ID_IMGEDT_TITLEBAR_ADJUST,  &VappImgEdtAdjustPage::enterAdjustPage},
    {3, EDIT_EFFECT,  STR_ID_VAPP_IMGEDT_EFFECT,  IMG_ID_IMGEDT_TITLEBAR_EFFECT,  &VappImgEdtEffectPage::enterEffectPage},      
    {4, EDIT_FLIP,    STR_ID_VAPP_IMGEDT_FLIP,    IMG_ID_IMGEDT_TITLEBAR_FLIP,    &VappImgEdtFlipPage::enterFlipPage},
    {5, EDIT_FRAME,   STR_ID_VAPP_IMGEDT_FRAME,   IMG_ID_IMGEDT_TITLEBAR_FRAME,   &VappImgEdtFramePage::enterFramePage},
    {6, EDIT_CLIPART, STR_ID_VAPP_IMGEDT_CLIPART, IMG_ID_IMGEDT_TITLEBAR_CLIPART, &VappImgEdtIconPage::enterIconPage},
    {7, EDIT_TEXT,    STR_ID_VAPP_IMGEDT_TEXT,    IMG_ID_IMGEDT_TITLEBAR_TEXT,    &VappImgEdtTextPage::enterTextPage},
#ifdef __COSMOS_PHOTEDT_SMALL_SCREEN_SYTLE__
    {8, EDIT_DOODLE,  STR_ID_VAPP_IMGEDT_DOODLE,  IMG_ID_IMGEDT_TITLEBAR_DOODLE,  &VappImgEdtDoodlePage2::enterDoodlePage2}
#else
    {8, EDIT_DOODLE,  STR_ID_VAPP_IMGEDT_DOODLE,  IMG_ID_IMGEDT_TITLEBAR_DOODLE,  &VappImgEdtDoodlePage::enterDoodlePage}
#endif
};

static const imgedt_color g_imgedt_text_color_list[IMGEDT_TEXT_COLOR_COUNT] = 
{
    {0, 0, 0},
    {0, 200, 255},//{0, 0, 255},    /* pure blue will treat as none */
    {61, 102, 206},
    {115, 241, 252},
    {145, 61, 206},
    {203, 161, 205},
    {255, 53, 240},
    {244, 154, 193},
    {254, 132, 0},
    {255, 240, 0},
    {254, 0, 24},
    {249, 173, 129},
    {89, 189, 69},
    {201, 231, 197},
    {0, 114, 54},
    {196, 223, 155},
    {96, 57, 19},
    {200, 159, 113},
    {27, 20, 100},
    {255, 255, 255},
    {200, 200, 200},
    {150, 150, 150},
    {100, 100, 100},
};


static const VfxResId g_imgedt_clip_ratio_vert_string_list[VappImgEdtClipPage::CLIP_RATIO_TOTAL] =
{
    STR_ID_VAPP_IMGEDT_RATIO_FREE,
    STR_ID_VAPP_IMGEDT_RATIO_ORIGINAL,
    STR_ID_VAPP_IMGEDT_RATIO_SCREEN,
    STR_ID_VAPP_IMGEDT_RATIO_1_1,
    STR_ID_VAPP_IMGEDT_RATIO_3_4,
    STR_ID_VAPP_IMGEDT_RATIO_9_16
};

static const VfxResId g_imgedt_clip_ratio_horz_string_list[VappImgEdtClipPage::CLIP_RATIO_TOTAL] =
{
    STR_ID_VAPP_IMGEDT_RATIO_FREE,
    STR_ID_VAPP_IMGEDT_RATIO_ORIGINAL,
    STR_ID_VAPP_IMGEDT_RATIO_SCREEN,
    STR_ID_VAPP_IMGEDT_RATIO_1_1,
    STR_ID_VAPP_IMGEDT_RATIO_4_3,
    STR_ID_VAPP_IMGEDT_RATIO_16_9
};


/***************************************************************************** 
 * C part
 *****************************************************************************/
extern "C"
{

MMI_BOOL vapp_imgedt_is_file_support(const WCHAR *filePath)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IS_FILE_SUPPORT, __LINE__);
    VFX_ASSERT(NULL != filePath);
    srv_ies_result res = srv_ies_util_is_file_supported(filePath);
    if (SRV_IES_OK == res)
    {
    #ifdef __DRM_SUPPORT__
        if(DRM_METHOD_NONE != DRM_get_object_method(0, (kal_wchar*)filePath))
        {
            VAPP_IMGEDT_INFO_TRACE(SRV_IES_E_FILE_ACCESS_DENIED);
            return MMI_FALSE;
        }
    #endif /* __DRM_SUPPORT__ */
        VAPP_IMGEDT_INFO_TRACE(0);
        return MMI_TRUE;
    }
    else
    {
        VAPP_IMGEDT_ERROR_TRACE(res);
        return MMI_FALSE;
    }
}

mmi_id vapp_imgedt_launch(void *param, U32 param_size)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_LAUNCH_APP, param, param_size);
    vapp_imgedt_launch_struct *info = (vapp_imgedt_launch_struct*)param; 
    
    mmi_id id =  VfxAppLauncher::launch( 
                            VAPP_IMGEDT,
                            VFX_OBJ_CLASS_INFO(VappImgEdtApp),
                            info->parent_id,
                            (void*)param,
                            param_size);
    VAPP_IMGEDT_INFO_TRACE(id);
    return id;
}

mmi_ret vapp_imgedt_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

void RenderOverCallback(srv_ies_result result, void *pUserData)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_RENDER_OVER_CALLBACK, result);
    VappImgEdtIesHdlr* ies = (VappImgEdtIesHdlr*)pUserData;
    ies->onRenderOver(result);
}

void CreateMetaCallback(srv_ies_result result, void *pUserData)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREATE_META_CALLBACK, result);
    VappImgEdtIesHdlr* ies = (VappImgEdtIesHdlr*)pUserData;
    ies->onCreateMetaOver(result);
}

}/* extern "C" */

/***************************************************************************** 
 * C++ part
 *****************************************************************************/
VcpImgEdtPreviewLayer::VcpImgEdtPreviewLayer(VfxU8* buf):
m_layerHdl(0),
m_layerBuffer(buf),
m_layerBufferSize(0)
{
    VFX_ASSERT(NULL != buf);
}

void VcpImgEdtPreviewLayer::setNeedRedrawPluto() 
{
    invalidate();
}

void VcpImgEdtPreviewLayer::getLayerBuffer(VfxU8** pbuf)
{
    VFX_ASSERT(NULL != m_layerBuffer);
    *pbuf = m_layerBuffer;
}
    
void VcpImgEdtPreviewLayer::onInit()
{
    VfxControl::onInit();
    VfxFrame::setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    // Get the frame size
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;        
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
    VfxSize preferredSize = VfxSize(mainScreenSize.width, mainScreenSize.height);
    setSize(preferredSize);
    setIsUnhittable(VFX_TRUE);

    createGdiLayer();
    setCacheMode(VFX_CACHE_MODE_RESOURCE);
    m_signalBoundsChanged.connect(this, &VcpImgEdtPreviewLayer::onPropertyBoundsChanged);
}

void VcpImgEdtPreviewLayer::onDeinit()
{
    freeGdiLayer();
    VfxControl::onDeinit();  
}

VfxBool VcpImgEdtPreviewLayer::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
    case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
    case VFX_PEN_EVENT_TYPE_STROKE_UP:
        return VFX_TRUE;

    case VFX_PEN_EVENT_TYPE_DOWN:       
    case VFX_PEN_EVENT_TYPE_LONG_TAP:    
    case VFX_PEN_EVENT_TYPE_MOVE:
    case VFX_PEN_EVENT_TYPE_UP:
    default:
        return VFX_FALSE;
    }
}

void VcpImgEdtPreviewLayer::onDraw(VfxDrawContext &dc)
{
    if (0 == m_layerHdl)
    {
        VAPP_IMGEDT_ERROR_TRACE(m_layerHdl);
        return;
    }

    // Work around solution, to safty use GDI layer buffer
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit();
        
    // Initialize a image buffer and draw
    VfxImageBuffer imageBuf;
    gdi_layer_struct *layer = (gdi_layer_struct *)m_layerHdl;
    imageBuf.ptr            = layer->buf_ptr;
    imageBuf.pitchBytes     = layer->width * 2;
    imageBuf.width          = layer->width;
    imageBuf.height         = layer->height;
    imageBuf.colorFormat    = VRT_COLOR_TYPE_RGB565;
    
    gdi_layer_push_and_set_active((gdi_handle) m_layerHdl);
	
    gdi_act_replace_src_key(
	    imageBuf.ptr,
	    imageBuf.width,
	    0,
	    0,
	    0,
	    0,
	    imageBuf.width - 1,
	    imageBuf.height - 1,
	    GDI_COLOR_TRANSPARENT,
	    imageBuf.width,
	    imageBuf.height);
				
    gdi_layer_pop_and_restore_active();
	
    dc.drawImageBuffer(getBounds().origin, imageBuf);
}
    
void VcpImgEdtPreviewLayer::createGdiLayer()
{
    VFX_ASSERT(m_layerBuffer != NULL);
    VFX_ASSERT(m_layerHdl == 0);    
    VFX_ASSERT(m_layerBufferSize == 0);

    // Caculate bufferSize, up-align size to 4
    VfxSize size = getBounds().size;
    m_layerBufferSize = (size.width * size.height * 2 + 3) & (~3);

    // Clear image content
    setImgContent(VFX_IMAGE_SRC_NULL);
    
    // Create GDI Layer for pluto control
    gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_16, 
            0, 
            0, 
            size.width, 
            size.height, 
            (gdi_handle *) &m_layerHdl, 
            m_layerBuffer, 
            m_layerBufferSize);
    // Out of layer handle
    VFX_ASSERT(m_layerHdl != NULL);
    
    // Setup layer
    gdi_layer_push_and_set_active((gdi_handle) m_layerHdl);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();
}

void VcpImgEdtPreviewLayer::freeGdiLayer()
{
    if (m_layerHdl == NULL)
    {
        VFX_ASSERT(m_layerBuffer == NULL);
        VFX_ASSERT(m_layerBufferSize == 0);
        VAPP_IMGEDT_ERROR_TRACE(0);
        return;
    }

    VFX_ASSERT(m_layerBuffer != NULL);
    VFX_ASSERT(m_layerBufferSize != 0);

    gdi_layer_free((gdi_handle) m_layerHdl);    
    m_layerHdl = 0;
    m_layerBuffer = NULL;    
    m_layerBufferSize = 0;
}

void VcpImgEdtPreviewLayer::onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    if (NULL != m_layerHdl)
    {
        // Work around solution, to safty use GDI layer buffer
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->suspendUntilCommit();
       
        VfxSize size = source->getSize();
            
        gdi_layer_push_and_set_active((gdi_handle) m_layerHdl);
        gdi_layer_resize(size.width, size.height);    
        gdi_layer_pop_and_restore_active();
    }    
}


/***************************************************************************** 
 * Class VappImgEdtIesHdlr
 *****************************************************************************/
VfxApp* VappImgEdtIesHdlr::m_curApp = NULL;
VappImgEdtIesHdlr* VappImgEdtIesHdlr::m_iesHdlr = NULL;

VappImgEdtIesHdlr::VappImgEdtIesHdlr():
m_hApp(NULL),
m_hImg(NULL),
m_hMeta(NULL),
m_hPreview(NULL),
m_lastError(SRV_IES_OK),
m_currType(EDIT_TYPE_NONE),
m_layerInfo(NULL),
m_renderTimer(NULL),                        
m_bEnalbeAll(VFX_TRUE),
m_bLargeFile(VFX_FALSE),
m_bImgRectChanged(VFX_TRUE),
m_maxSize(0,0),
m_minSize(0,0),
m_scrnSize(0, 0),
m_zoomFactor(1.0f),
m_zoom(1.0f),
m_bVertFlip(VFX_FALSE),
m_bHorzFlip(VFX_FALSE),
m_bUndoValid(VFX_FALSE),
m_bRedoValid(VFX_FALSE),
m_hJob(NULL)                   
{
}


void VappImgEdtIesHdlr::onDeinit()
{    
    closeInstance();
    (VappImgEdtIesHdlr::m_curApp) = NULL;
    VfxObject::onDeinit();
}

VappImgEdtIesHdlr* VappImgEdtIesHdlr::getInstance()
{
    return VappImgEdtIesHdlr::m_iesHdlr;
}

VfxS32 VappImgEdtIesHdlr::reprepareInstance(VfxId app_id, 
                                            void *memBuf,
                                            VfxS32 memSize, 
                                            const VfxWChar *path,
                                            VfxApp *parent)
{
    VFX_ASSERT(NULL !=  memBuf);
    VFX_ASSERT(memSize > 0);
    VFX_ASSERT(NULL != path);
    
    if (NULL != VappImgEdtIesHdlr::m_curApp)
    {
        (VappImgEdtIesHdlr::m_curApp)->exit();
        (VappImgEdtIesHdlr::m_curApp) = NULL;
    }
    VappImgEdtIesHdlr::m_curApp = parent;
    return VappImgEdtIesHdlr::createInstance(app_id, memBuf, memSize, path, parent);
}

VfxS32 VappImgEdtIesHdlr::createInstance(VfxId app_id,
                                         void *memBuf,
                                         VfxS32 memSize,
                                         const VfxWChar *path,
                                         VfxApp *parent)
{
    VFX_ASSERT(NULL !=  memBuf);
    VFX_ASSERT(memSize > 0);
    VFX_ASSERT(NULL != path);
    VFX_ASSERT(NULL == m_iesHdlr);
    VFX_ASSERT(VappImgEdtIesHdlr::m_curApp == parent);

    VappImgEdtIesHdlr *ies;
    VFX_OBJ_CREATE(ies, VappImgEdtIesHdlr, parent);
    VappImgEdtIesHdlr::m_iesHdlr = ies;

    srv_ies_feature_enum feature;
    if (VCUI_IMGCLIP == app_id)
    {
        ies->m_bImageReady = VFX_TRUE;
        feature = SRV_IES_FEATURE_EDIT;
    }
    else
    {
        ies->m_bImageReady = VFX_FALSE;
        feature = SRV_IES_FEATURE_ALL;
    }
    ies->m_lastError = srv_ies_app_session_create(app_id, feature, memBuf, memSize, &(ies->m_hApp));
    if (ies->m_lastError < 0)
    {
        return ies->m_lastError;
    }
    
    ies->m_lastError = srv_ies_image_create_from_file(ies->m_hApp, (const WCHAR*)path, NULL, &(ies->m_hImg));
    if (ies->m_lastError < 0)
    {
        return ies->m_lastError;
    }

#ifdef __MMI_COSMOS_IMGEDT_SLIM__
    VfxS32 w, h;
    GDI_RESULT gdiRet = gdi_image_get_dimension_file((CHAR*)path, &w, &h);
    if (GDI_SUCCEED == gdiRet)
    {
        if (w*h > 2592*1944)
        {
            m_iesHdlr->setIsLargeFile(VFX_TRUE);
        }
    }
#endif /* __MMI_COSMOS_IMGEDT_SLIM__ */

    //init static parameter
    ies->loadStaticInfo();
    return ies->m_lastError;
}

void VappImgEdtIesHdlr::closeInstance()
{
    if (EDIT_TYPE_CREATE_META == m_currType)
    {
        cancelMeta();
    }
    if (NULL != m_hImg)
    {
        srv_ies_image_destroy(m_hImg);
        m_hImg = NULL;
    }
    destroyMeta();
    if (NULL != m_hApp)
    {
        srv_ies_app_session_destroy(m_hApp);
        m_hApp = NULL;
    }
    VappImgEdtIesHdlr::m_iesHdlr = NULL;
}

VfxS32 VappImgEdtIesHdlr::createMeta(VfxWChar* path, VfxS32 width, VfxS32 height)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREATE_META_BEGIN, m_hMeta);
    if (NULL != m_hMeta)
    {
        return 0;
    }
    
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 ret = (VfxS32)srv_ies_meta_create_from_file_async(m_hApp,
                                                            (const WCHAR*) path,
                                                            width,
                                                            height,
                                                            CreateMetaCallback,
                                                            (void*)this,
                                                            &m_hJob);
    if (0 == ret)
    {
        m_bEnalbeAll = VFX_FALSE;
        m_currType = EDIT_TYPE_CREATE_META;
    }
    else
    {
        m_bImageReady = VFX_TRUE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREATE_META_END, ret);
    return ret;  
}

VfxS32 VappImgEdtIesHdlr::cancelMeta()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CANCEL_META_BEGIN, m_currType);

    srv_ies_result res = SRV_IES_OK;
    if(EDIT_TYPE_CREATE_META == m_currType)
    {
        res = srv_ies_job_cancel(m_hJob);
        m_currType = EDIT_TYPE_NONE;
    }
    m_bImageReady = VFX_TRUE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CANCEL_META_END, res);
    return res;
}

void VappImgEdtIesHdlr::onCreateMetaOver(srv_ies_result result)
{    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CERATEE_META_CALLBACK_BEGIN, m_currType, result);
    if (EDIT_TYPE_CREATE_META != m_currType)
    {
        return;
    }
    
    VfxS32 ret = result;
    if (SRV_IES_OK == ret)
    {
        ret = (VfxS32)srv_ies_job_get_meta(m_hJob, &m_hMeta);
        if (SRV_IES_OK == ret)
        {
            ret = (VfxS32)srv_ies_image_set_meta_info(m_hImg, m_hMeta);
        }
    }
    m_bImageReady = VFX_TRUE;
    m_bEnalbeAll = VFX_TRUE;
    m_currType = EDIT_TYPE_NONE;
    m_signalCreateMetaCallback.emit(ret);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CERATEE_META_CALLBACK_END, ret);
}

VfxS32 VappImgEdtIesHdlr::destroyMeta()
{
    VfxS32 ret = 0;
    if (NULL != m_hMeta)
    {
        ret = srv_ies_meta_destroy(m_hMeta);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DESTORY_META, ret);
        m_hMeta = 0;
    }
    VAPP_IMGEDT_INFO_TRACE(ret);
    return ret;
}


void VappImgEdtIesHdlr::cancelAll()
{
    VAPP_IMGEDT_INFO_TRACE(m_currType);
    switch (m_currType)
    {
    case EDIT_TYPE_ROTATE:
        rotateEnd(VFX_FALSE);
        break;

    case EDIT_TYPE_ADJUST:
        adjustEnd(VFX_FALSE);
        break;
        
    case EDIT_TYPE_EFFECT:
        effectEnd(VFX_FALSE);
        break;
        
    case EDIT_TYPE_FLIP:
        flipEnd(VFX_FALSE);
        break;
        
    case EDIT_TYPE_DOODLE:
        doodleEnd(VFX_FALSE);
        break;

    case EDIT_TYPE_ADD_FRAME:
        addFrameEnd(VFX_FALSE);
        break;
        
    case EDIT_TYPE_RENDER:
        cancelSave();
        break;

    case EDIT_TYPE_CREATE_META:
        cancelMeta();
        break;

    default:
        break;
    }
    m_currType = EDIT_TYPE_NONE;
}
    

VfxS32 VappImgEdtIesHdlr::renderPreview(srv_ies_preview_handle preview)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_RENDER_PREVIEW_BEGIN, preview);
    /* Should not render preview */
    if (EDIT_TYPE_RENDER == m_currType || EDIT_TYPE_CREATE_META == m_currType)
    {
        VAPP_IMGEDT_WARN_TRACE(m_currType);
        return 0;
    }

    if (!m_bImageReady)
    {
        VAPP_IMGEDT_WARN_TRACE(m_currType);
        return 0;
    }
    
    srv_ies_result res;
    if (NULL == preview)
    {
        res = srv_ies_preview_render(m_hPreview);
        if (SRV_IES_OK != res)
        {
            cancelAll();
            setUndoValid(VFX_FALSE);
            m_bEnalbeAll = VFX_FALSE;
        }
    }
    else
    {
        res = srv_ies_preview_render(preview);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_RENDER_PREVIEW_END, res);
    m_layerInfo->setNeedRedrawPluto();
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleRenderPreview(VfxBool isUpdate)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_RENDER_PREVIEW_BEGIN, isUpdate);

    srv_ies_result res = SRV_IES_OK;
    
    if (isUpdate)
    {
        res = srv_ies_preview_render(m_hPreview);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_RENDER_PREVIEW_END, res);
        m_layerInfo->setNeedRedrawPluto();
        VAPP_IMGEDT_INFO_TRACE(res);
    }        
    return res;
}

VcpImgEdtPreviewLayer *VappImgEdtIesHdlr::getPreviewInternal()
{
    return m_layerInfo;
}

VfxS32 VappImgEdtIesHdlr::createPreviewInternal(VfxU8* buf, VfxSize &previewSize)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_BEGIN, __LINE__);
    VFX_ASSERT(NULL != buf);
    
    VFX_OBJ_CREATE_EX(m_layerInfo, VcpImgEdtPreviewLayer, this, (buf));
    m_scrnSize = previewSize;
    m_layerInfo->setSize(m_scrnSize);

    srv_ies_result res = SRV_IES_OK;
    res = srv_ies_preview_create(m_hImg, 
                                 &m_hPreview, 
                                 buf, 
                                 previewSize.width * previewSize.height * 2, 
                                 previewSize.width, previewSize.height,
                                 previewSize.width * 2, 
                                 SRV_IES_COLORFORMAT_RGB565);
    if (res < SRV_IES_OK)
    {
        VAPP_IMGEDT_ERROR_TRACE(res);
        return res;
    }

    res = (srv_ies_result)renderPreview();
    if (res < SRV_IES_OK)
    {
        VAPP_IMGEDT_ERROR_TRACE(res);
        return res;
    }
    
    getZoomAndPan(&m_orgZoom, &m_orgPanX, &m_orgPanY);
    //check if is specail ratio image
    VfxRect scrnRect;
    getScrnArea(&scrnRect);
    if ((scrnRect.getWidth() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getHeight() == previewSize.height))
    {
        VAPP_IMGEDT_WARN_TRACE(scrnRect.getWidth());
        m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getWidth();
    }
    else if ((scrnRect.getHeight() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getWidth() == previewSize.width))
    {
        VAPP_IMGEDT_WARN_TRACE(scrnRect.getHeight());
        m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getHeight();
    }
    setZoomAndPan(m_orgZoom, m_orgPanX, m_orgPanY);
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::setPreviewParent(VfxObject *parent)
{
    VFX_ASSERT(NULL != m_layerInfo);
    //m_layerInfo->setParent(parent);
    return SRV_IES_OK;
}

VfxS32 VappImgEdtIesHdlr::createPreview(VcpImgEdtPreviewLayer *info, srv_ies_preview_handle *preview, VfxSize size)
{
    VfxU8* buff ;
    info->getLayerBuffer(&buff);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_BEGIN, __LINE__);
    srv_ies_result res = srv_ies_preview_create(
                                 m_hImg, 
                                 preview, 
                                 buff, 
                                 size.width * size.height * 2, 
                                 size.width, size.height,
                                 size.width * 2, 
                                 SRV_IES_COLORFORMAT_RGB565);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_END, res);
    res = srv_ies_preview_set_zoom_and_pan(*preview, m_orgZoom, m_orgPanX, m_orgPanY);
    renderPreview(*preview);
    return res;
}

VfxS32 VappImgEdtIesHdlr::createPreview(VfxU8* buf, srv_ies_preview_handle *preview,VfxSize size)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_BEGIN, __LINE__);
    srv_ies_result res = srv_ies_preview_create(
                                 m_hImg, 
                                 preview, 
                                 buf, 
                                 size.width * size.height * 2, 
                                 size.width, size.height,
                                 size.width * 2, 
                                 SRV_IES_COLORFORMAT_RGB565); 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_CREAET_PREVIEW_END, res);
    res = srv_ies_preview_set_zoom_and_pan(*preview, m_orgZoom, m_orgPanX, m_orgPanY);
    renderPreview(*preview);
    return res;
}


VfxS32 VappImgEdtIesHdlr::getImageSize(VfxSize &size)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMAGE_GET_SIZE_BEGIN);
    //new IES
    srv_ies_result res = srv_ies_image_get_current_size(m_hImg, &size.width,&size.height);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMAGE_GET_SIZE_END, res);
    return res;

}

VfxS32 VappImgEdtIesHdlr::updateImageInfo(VfxBool isForced)
{
    if (isForced || m_bImgRectChanged)
    {
        //update zoom factor
        m_zoom = m_orgZoom;
        setZoomAndPan(m_orgZoom, m_orgPanX, m_orgPanY);
        VfxRect scrnRect;
        VfxSize imgSize;
        getScrnArea(&scrnRect);
        getCurrImageSize(imgSize);
        m_maxSize = imgSize;
        getMaxZoomSize(m_maxSize);
        
        m_zoomFactor = ((VfxFloat)(m_maxSize.width - scrnRect.size.width))/(VfxFloat)scrnRect.size.width;

        if ((imgSize.width <= m_scrnSize.width) && 
            (imgSize.height <= m_scrnSize.height))
        {
            m_distancePerPixel = 1.0f;    
        }
        else
        {
            m_distancePerPixel= (VfxFloat)imgSize.width / (VfxFloat)scrnRect.getWidth();
        }
    }
    return 0;
}

void VappImgEdtIesHdlr::getMaxZoomSize(VfxSize &maxSize)
{
    VFX_ASSERT(!m_scrnSize.isEmpty());
    VfxFloat scrnRatio = (VfxFloat)(m_scrnSize.width/m_scrnSize.height);
    VfxFloat imgRatio = (VfxFloat)(maxSize.width/maxSize.height);
    VfxBool bCheckW = (imgRatio >= scrnRatio) ? VFX_TRUE : VFX_FALSE;

    if (bCheckW)
    {
        if (maxSize.width < (m_scrnSize.width) * 2)
        {
            maxSize.width = maxSize.width * 2;
            maxSize.height = maxSize.height * 2;
        }
    }
    else
    {
        if (maxSize.height < (m_scrnSize.height) * 2)
        {
            maxSize.width = maxSize.width * 2;
            maxSize.height = maxSize.height * 2;
        }
    }
}


VfxS32 VappImgEdtIesHdlr::destroyPreview(srv_ies_preview_handle preview)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DESTROY_PREVIEW_BEGIN, preview);
    srv_ies_result res = SRV_IES_OK;
    if (NULL == preview)
    {
        if (NULL != m_hPreview)
        {
            res = srv_ies_preview_destroy(m_hPreview);
            m_hPreview = NULL;
        }        
    }
    else
    {
        res = srv_ies_preview_destroy(preview);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DESTROY_PREVIEW_END, res);
    return 0;
} 

VfxS32 VappImgEdtIesHdlr::getScrnArea(VfxRect *rect)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SCRN_GET_AREA_BEGIN);
    srv_ies_result res = srv_ies_preview_get_canvas_rect(m_hPreview, 
                                                         &rect->origin.x,
                                                         &rect->origin.y,
                                                         &rect->size.width, 
                                                         &rect->size.height);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SCRN_GET_AREA_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::getImageArea(VfxRect *rect)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMAGE_GET_AREA_BEGIN);
    srv_ies_result res = srv_ies_preview_get_screen_rect(
                                    m_hPreview, 
                                    &rect->origin.x,
                                    &rect->origin.y,
                                    &rect->size.width, 
                                    &rect->size.height);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMAGE_GET_AREA_END, res);
    return res;        
}

VfxS32 VappImgEdtIesHdlr::getCurrImageRect(VfxRect *pRect)
{
    VfxS32 res = getImageArea(pRect);    
    if (pRect->getX() < 0)
    {
        pRect->size.width += (pRect->getX() * 2);
    }
    if (pRect->getY() < 0)
    {
        pRect->size.height += (pRect->getY() * 2);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_GET_CURR_IMAGE_RECT, pRect->size.width, pRect->size.height);
    return res;
}

VfxS32 VappImgEdtIesHdlr::getCurrImageSize(VfxSize &size)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_GET_MAX_IMAGE_RECT, m_zoom);
    VfxS32 ret = srv_ies_image_get_current_size(m_hImg, &size.width, &size.height);
    return ret;
}


VfxS32 VappImgEdtIesHdlr::setImageArea(const VfxRect &rect)
{
    srv_ies_result res = srv_ies_preview_set_zoom_rect(
                                   m_hPreview, 
                                   rect.origin.x,
                                   rect.origin.y,
                                   rect.size.width, 
                                   rect.size.height);
    renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_PREVIEW_SET_RECT, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::convtDistanceScrn2Img(VfxS32 distance)
{
    VfxS32 imgDistance;
    imgDistance = (VfxS32)(distance * m_distancePerPixel / m_zoom);
    return imgDistance;
}

VfxPoint VappImgEdtIesHdlr::convtPointScrn2Img(VfxPoint &point)
{
    VfxPoint imgPoint;
    VfxRect imgRect;
    getImageArea(&imgRect);

    imgPoint.x += convtDistanceScrn2Img(point.x) + imgRect.getX();
    imgPoint.y += convtDistanceScrn2Img(point.y) + imgRect.getY();
    
    return imgPoint;
}

VfxPoint VappImgEdtIesHdlr::convtPointImg2SScrn(VfxPoint &point)
{
    return VfxPoint(0,0);
}

VfxS32 VappImgEdtIesHdlr::zoomAniBegin(VfxS32 origIndx, VfxBool bLarger)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_ANI_START_BEGIN, bLarger, origIndx);
    m_zoomOrigIndx = origIndx;
    if (bLarger)
    {
        m_zoomAnimDst = m_zoomFactor + m_orgZoom;
        m_zoomAnimCount = 50 - m_zoomOrigIndx; 
    }
    else
    {
        m_zoomAnimDst = m_orgZoom;
        m_zoomAnimCount = origIndx;
    }
    VfxS32 res = (VfxS32)srv_ies_animation_begin(m_hPreview, m_zoomAnimDst, m_zoomAnimCount);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_ANI_START_END, res);
    return res;
}


VfxS32 VappImgEdtIesHdlr::zoomAniAdjust(VfxS32 index, VfxBool bLarger)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_ANI_ADJUST_BEGIN, index, bLarger);
    VfxS32 aniIndx;
    if (bLarger)
    {
        aniIndx = index - m_zoomOrigIndx;
    }
    else
    {
        aniIndx = m_zoomOrigIndx - index;
    }
    VFX_ASSERT((aniIndx >= 0) && (aniIndx <= m_zoomAnimCount));

    VfxS32 res = (VfxS32)srv_ies_animation_render(m_hPreview, aniIndx);
    m_layerInfo->setNeedRedrawPluto();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_ANI_ADJUST_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::zoomAniEnd(VfxBool isCancel)
{
    VfxS32 res;
    if (isCancel)
    {
        res = (VfxS32)srv_ies_animation_end(m_hPreview);
    }
    else
    {
        res = (VfxS32)srv_ies_animation_end(m_hPreview);
    }
    m_layerInfo->setNeedRedrawPluto();
    VfxFloat panX, panY;
    getZoomAndPan(&m_zoom, &panX, &panY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_ANI_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::setZoomSmart(VfxFloat zoomValue)
{
    VfxFloat zoom, panX, panY;
    VfxS32 ret = getZoomAndPan(&zoom, &panX, &panY);
    if (0 == ret)
    {
        m_zoom = zoomValue*m_zoomFactor +  m_orgZoom;
        ret = setZoomAndPan(m_zoom, panX, panY);
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SET_ZOOM_SMART);
    return ret;
}


VfxS32 VappImgEdtIesHdlr::setDragSmart(VfxSize &distance)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SET_DRAG_SMART_BEGIN, distance.width, distance.height);
    if (1 == m_zoom)
    {
        return 0;
    }

    VfxSize refDistance = VfxSize(0 - distance.width, 0 - distance.height);
    VfxS32 ret = (VfxS32)srv_ies_preview_set_pan_delta(m_hPreview, refDistance.width, refDistance.height);
    ret = renderPreview();
    return ret;
}


VfxS32 VappImgEdtIesHdlr::getZoomAndPan(VfxFloat *zoom, VfxFloat *panX, VfxFloat *panY)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_GET_ZOOM_AND_PAN_BEGIN);
    srv_ies_result res = srv_ies_preview_get_zoom_and_pan(m_hPreview, zoom, panX, panY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_GET_ZOOM_AND_PAN_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::setZoomAndPan(VfxFloat zoom, VfxFloat panX, VfxFloat panY)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SET_ZOOM_AND_PAN_BEGIN);
    VfxS32 res = (VfxS32)srv_ies_preview_set_zoom_and_pan(m_hPreview, zoom, panX, panY);
    res = renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SET_ZOOM_AND_PAN_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doClip(const VfxRect &rect, VfxBool needUpdate)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SET_ZOOM_AND_PAN_BEGIN, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 res = (VfxS32)srv_ies_image_crop(m_hImg, 
                                            rect.origin.x,
                                            rect.origin.y,
                                            rect.size.width,
                                            rect.size.height);


    setUndoValid(VFX_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DO_CLIP_END, res);

    if (!needUpdate)
    {
        //for clip cui, do not need check image resolution and return directly
        return res;
    }

    //check if is specail ratio image
    if (m_orgZoom > 1.0f)
    {
        VAPP_IMGEDT_INFO_TRACE(0);
        setZoomAndPan(1, m_orgPanX, m_orgPanY);
        VfxRect scrnRect;
        getScrnArea(&scrnRect);
        if ((scrnRect.getWidth() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getHeight() == m_scrnSize.height))
        {
            VAPP_IMGEDT_WARN_TRACE(scrnRect.getWidth());
            m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getWidth();
        }
        else if ((scrnRect.getHeight() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getWidth() == m_scrnSize.width))
        {
            VAPP_IMGEDT_WARN_TRACE(scrnRect.getHeight());
            m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getHeight();
        }
        else
        {
            m_orgZoom = 1.0f;
            VAPP_IMGEDT_INFO_TRACE(1);
        }
        res = setZoomAndPan(m_orgZoom, m_orgPanX, m_orgPanY);
    }
    return res;
}

VfxS32 VappImgEdtIesHdlr::rotateBegin()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_BEGIN_1, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    srv_ies_result res = srv_ies_image_rotate_begin(m_hImg);
    if (SRV_IES_OK == res)
    {
        m_currType = EDIT_TYPE_ROTATE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_BEGIN_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::rotateAjust(srv_ies_rot_enum rot,VfxBool auto_render)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_ADJUST_1, rot);

    if (EDIT_TYPE_ROTATE != m_currType)
    {
        return -1;
    }
    VfxS32 res = (VfxS32)srv_ies_image_rotate_adjust(m_hImg, rot);
    if (auto_render)
    {
        res = renderPreview();
    }    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_ADJUST_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::rotateEnd(VfxBool isApply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_END_1, isApply);
    
    if (EDIT_TYPE_ROTATE != m_currType)
    {
        return -1;
    }
    
    srv_ies_result res;
    if (isApply)
    {
        res = srv_ies_image_rotate_end(m_hImg);
        setUndoValid(VFX_TRUE);
    }
    else
    {
        res = srv_ies_image_rotate_cancel(m_hImg);
    }
    m_currType = EDIT_TYPE_NONE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ROTATE_END_2, res);
    return res;
}


VfxS32 VappImgEdtIesHdlr::flipBegin()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_BEGIN_1, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    srv_ies_result res = srv_ies_image_flip_begin(m_hImg);
    if (SRV_IES_OK == res)
    {
        m_currType = EDIT_TYPE_FLIP;
        m_bVertFlip = m_bHorzFlip = MMI_FALSE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_BEGIN_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::flipAdjust(VfxBool isHorz, VfxBool isVert)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_ADJUST_1, isHorz, isVert);
    if (EDIT_TYPE_FLIP != m_currType)
    {
        return -1;
    }
    if (isHorz)
    {
        m_bHorzFlip = m_bHorzFlip ? MMI_FALSE : MMI_TRUE;
    }
    if (isVert)
    {
        m_bVertFlip = m_bVertFlip ? MMI_FALSE : MMI_TRUE;
    }   
    VfxS32 res = (VfxS32)srv_ies_image_flip_adjust(m_hImg, (MMI_BOOL)m_bHorzFlip, (MMI_BOOL)m_bVertFlip);
    VfxFloat zoom,panX,panY;
    getZoomAndPan(&zoom,&panX,&panY);
    //setZoomAndPan(zoom + 0.1f, panX, panY);
    srv_ies_preview_set_zoom_and_pan(m_hPreview, zoom + 0.1f, panX, panY); //It is not  a good usage.
    res = setZoomAndPan(zoom, panX, panY);
    //res = renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_ADJUST_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::flipEnd(VfxBool isApply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_END_1, isApply);
    
    if (EDIT_TYPE_FLIP != m_currType)
    {
        return -1;
    }
    
    VfxS32 res = 0;
    if (isApply)
    {
        res = (VfxS32)srv_ies_image_flip_end(m_hImg);
        setUndoValid(VFX_TRUE);
    }
    else
    {
        res = (VfxS32)srv_ies_image_flip_cancel(m_hImg);
    }
    m_currType = EDIT_TYPE_NONE;
    m_bVertFlip = m_bHorzFlip = MMI_FALSE;
    res = renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_FLIP_END_2, res);
    return res;
}

void VappImgEdtIesHdlr::getAdjustInitValue(VfxS32 type, VfxS32 *def, VfxS32 *min, VfxS32 *max)
{
    *def = m_adjustItem[type].getDefValue();
    *min = m_adjustItem[type].getMinValue();
    *max = m_adjustItem[type].getMaxValue();
}

VfxResId VappImgEdtIesHdlr::getAjdustStrId(VfxS32 type)
{
    return m_adjustItem[type].getStrId();
}

VfxS32 VappImgEdtIesHdlr::adjustBegin()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_BEGIN_1, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    srv_ies_result res = srv_ies_effect_begin_adjust(m_hImg, SRV_IES_EFFECT_COLOR_ADJUST);
    if (0 == res)
    {
        m_currType = EDIT_TYPE_ADJUST;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_BEGIN_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::adjustSet(VfxS32 type, VfxS32 value)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_SET_1, type, value);
    if (EDIT_TYPE_ADJUST != m_currType)
    {
        return -1;
    }
    VfxS32 res = (VfxS32)srv_ies_effect_set_param_int(
                                        m_hImg, 
                                        (U32) type, 
                                        value);
    res = renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_SET_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::adjustEnd(VfxBool is_apply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_END_1, is_apply);
    
    if (EDIT_TYPE_ADJUST != m_currType)
    {
        return -1;
    }
    
    VfxS32 res = 0;
    if (is_apply)
    {
        res = srv_ies_effect_end_adjust(m_hImg);
        setUndoValid(VFX_TRUE);
    }
    else
    {
        res = srv_ies_effect_cancel_adjust(m_hImg);
    }
    m_currType = EDIT_TYPE_NONE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADJSUT_END_2, res);
    return res;
}


VfxS32 VappImgEdtIesHdlr::effectBegin()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_EFFECT_BEGIN, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    m_currType = EDIT_TYPE_EFFECT;
    m_currEffectIndex = EFFECT_TYPE_NONE;
    return 0;
}

VfxS32 VappImgEdtIesHdlr::effectSet(VfxS32 type)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_EFFECT_SET_1, m_currEffectIndex, type);
    VFX_ASSERT(EDIT_TYPE_EFFECT == m_currType);
    if (m_currEffectIndex == type)
    {
        return -1;
    }
    VfxS32 res = SRV_IES_OK;
    if (m_currEffectIndex > EFFECT_TYPE_NONE)
    {
        res = (VfxS32)srv_ies_effect_cancel_adjust(m_hImg);
    }
    
    m_currEffectIndex = type;
    if (m_currEffectIndex > EFFECT_TYPE_NONE)
    {
        res = (VfxS32)srv_ies_effect_begin_adjust(m_hImg, (srv_ies_effect_enum)m_effectItem[m_currEffectIndex].getId());
        if (res < SRV_IES_OK)
        {
            m_currEffectIndex = 0;
        }
    }
    if (SRV_IES_OK == res)
    {
        res = renderPreview();
    }    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_EFFECT_SET_2, res);
    return res;
}


VfxS32 VappImgEdtIesHdlr::effectEnd(VfxBool is_apply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_EFFECT_END_1, is_apply);
    if (EDIT_TYPE_EFFECT != m_currType)
    {
        return -1;
    }

    srv_ies_result res = SRV_IES_OK;

    if (m_currEffectIndex > EFFECT_TYPE_NONE)
    {
        if (is_apply)
        {
            res = srv_ies_effect_end_adjust(m_hImg);
            setUndoValid(VFX_TRUE);
        }
        else
        {
            res = srv_ies_effect_cancel_adjust(m_hImg);
        }
    }
    m_currType = EDIT_TYPE_NONE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_EFFECT_END_2, res);
    return res;
}

VfxResId VappImgEdtIesHdlr::effectGetImgId(VfxS32 type)
{
    return m_effectItem[type].getImgId();
}

VfxResId VappImgEdtIesHdlr::effectGetStrId(VfxS32 type)
{
    return m_effectItem[type].getStrId();
}


VfxS32 VappImgEdtIesHdlr::addFrameBegin(VfxResId id)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_BEGIN_1, id, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 res = (VfxS32)srv_ies_frame_begin_from_id(m_hImg, id);
    if (0 == res)
    {
        /* if begin return OK, should set m_currType, in order to call end */
        m_currType = EDIT_TYPE_ADD_FRAME;
        res = renderPreview();       
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_BEGIN_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::addFrameChange(VfxResId id)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_CHANGE_1, id);
    if (EDIT_TYPE_ADD_FRAME != m_currType)
    {
        VAPP_IMGEDT_ERROR_TRACE(m_currType);
        return -1;
    }
    VfxS32 res = (VfxS32)srv_ies_frame_cancel(m_hImg);
    VAPP_IMGEDT_INFO_TRACE(res);
    res = (VfxS32)srv_ies_frame_begin_from_id(m_hImg, id);
    if (0 == res)
    {
        res = renderPreview();
    }
    else
    {
        /* if begin return fail, should reset m_currType, in order to skip call end */
        m_currType = EDIT_TYPE_NONE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_CHANGE_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::addFrameEnd(VfxBool is_apply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_END_1, is_apply);
    if (EDIT_TYPE_ADD_FRAME != m_currType)
    {
        VAPP_IMGEDT_ERROR_TRACE(m_currType);
        return -1;
    }

    VfxS32 res = SRV_IES_OK;

    if (is_apply)
    {
        res = (VfxS32)srv_ies_frame_end(m_hImg);
        m_currType = EDIT_TYPE_NONE;
        setUndoValid(VFX_TRUE);
    }
    else
    {
        res = (VfxS32)srv_ies_frame_cancel(m_hImg);
        m_currType = EDIT_TYPE_NONE;
        if (SRV_IES_OK == res)
        {
            res = renderPreview();
        }
    }   

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_FRAME_END_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::addIcon(VfxResId id, VfxRect &rect)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_ICON_BEGIN,
             id, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 res = (VfxS32)srv_ies_icon_begin_from_id(m_hImg, id);

    if (SRV_IES_OK == res)
    {
        VfxPoint centerPoint(rect.getMidX(), rect.getMidY());
        VfxPoint imgCenter = convtPointScrn2Img(centerPoint);
        VfxS32 width = convtDistanceScrn2Img(rect.getWidth());
        VfxS32 height = convtDistanceScrn2Img(rect.getHeight());
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_ICON_BEGIN, imgCenter.x, imgCenter.y, width, height);
        res = (VfxS32)srv_ies_icon_adjust(m_hImg, 
                                          imgCenter.x, 
                                          imgCenter.y, 
                                          width, 
                                          height, 
                                          SRV_IES_ROT_0);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ICON_ADJUST_END, res);
        srv_ies_icon_end(m_hImg);
        setUndoValid(VFX_TRUE);
    }
    if (SRV_IES_OK == res)
    {
        res = renderPreview();
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_ICON_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::addText(VfxU8 *buff, VfxRect &rect)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_TEXT_BEGIN,
             buff, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 res = (VfxS32)srv_ies_icon_begin_from_raw_buffer(
                                             m_hImg,
                                             buff,
                                             rect.getWidth()*rect.getHeight()*4,
                                             rect.getWidth(),
                                             rect.getHeight(),
                                             rect.getWidth() * 4,
                                             SRV_IES_COLORFORMAT_RGBA8888);

    if (SRV_IES_OK == res)
    {
        VfxPoint centerPoint(rect.getMidX(), rect.getMidY());
        VfxPoint imgCenter = convtPointScrn2Img(centerPoint);
        VfxS32 width = convtDistanceScrn2Img(rect.getWidth());
        VfxS32 height = convtDistanceScrn2Img(rect.getHeight());
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_ICON_BEGIN, imgCenter.x, imgCenter.y, width, height);
        res = (VfxS32)srv_ies_icon_adjust(m_hImg, 
                                          imgCenter.x, 
                                          imgCenter.y, 
                                          width, 
                                          height, 
                                          SRV_IES_ROT_0);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ICON_ADJUST_END, res);
        srv_ies_icon_end(m_hImg);
        setUndoValid(VFX_TRUE);
    }
    if (SRV_IES_OK == res)
    {
        res = renderPreview();
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ADD_TEXT_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleBegin(VfxU32 width, imgedt_color color)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_BEGIN_1, width, color, m_currType);
    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    VfxS32 res;
    res = srv_ies_doodle_create(m_hPreview,  &m_hDoodle);
    if (SRV_IES_OK == res)
    {
        m_currType = EDIT_TYPE_DOODLE;
        res = srv_ies_doodle_set_line_width(m_hDoodle, width);
        res = srv_ies_doodle_set_color(m_hDoodle, color.r, color.g, color.b);
        res = renderPreview();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_BEGIN_2, res);
    return res;

}

VfxS32 VappImgEdtIesHdlr::doodleDraw(VfxPoint begin, VfxPoint end)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_DRAW_1);
    if (EDIT_TYPE_DOODLE != m_currType)
    {
        return -1;
    }    
    srv_ies_result res;
    res = srv_ies_doodle_add_line(m_hDoodle,
                                  begin.x,
                                  begin.y,
                                  end.x,
                                  end.y);
    //renderPreview();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_DRAW_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleErase(VfxPoint begin, VfxPoint end, VfxU32 radius)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_ERASE_1, radius);
    if (EDIT_TYPE_DOODLE != m_currType)
    {
        return -1;
    }    

    srv_ies_result res;
    res = srv_ies_doodle_erase_line(m_hDoodle,
                                  begin.x,
                                  begin.y,
                                  end.x,
                                  end.y,
                                  radius);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_ERASE_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleEnd(VfxBool is_apply)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_END_1, is_apply);
    
    if (EDIT_TYPE_DOODLE != m_currType)
    {
        return -1;
    }
    srv_ies_result res;
    if (is_apply)
    {
        res = srv_ies_doodle_commit_and_destroy(m_hDoodle);
        setUndoValid(VFX_TRUE);
    }
    else
    {
        res = srv_ies_doodle_cancel_and_destroy(m_hDoodle);
    }
    m_currType = EDIT_TYPE_NONE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_DOODLE_END_2, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleSetColor(imgedt_color color)
{
    srv_ies_result res;
    res = srv_ies_doodle_set_color(m_hDoodle, color.r, color.g, color.b);
    return res;
}

VfxS32 VappImgEdtIesHdlr::doodleSetWidth(VfxU32 width)
{
    srv_ies_result res;
    res = srv_ies_doodle_set_line_width(m_hDoodle, width);
    return res;
}

VfxS32 VappImgEdtIesHdlr::undo()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_UNDO_BEGIN, m_bUndoValid);
    if (!m_bUndoValid)
    {
        return -1;
    }

    srv_ies_result res = srv_ies_image_undo(m_hImg);
    renderPreview();
    
    if (SRV_IES_OK == res)
    {
        //check if is specail ratio image
        VfxFloat tempZoom = m_orgZoom;
        setZoomAndPan(1, m_orgPanX, m_orgPanY);
        VfxRect scrnRect;
        getScrnArea(&scrnRect);
        if ((scrnRect.getWidth() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getHeight() == m_scrnSize.height))
        {
            VAPP_IMGEDT_WARN_TRACE(scrnRect.getWidth());
            m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getWidth();
        }
        else if ((scrnRect.getHeight() < IMGEDT_CLIP_MIN_LENGHTH) && (scrnRect.getWidth() == m_scrnSize.width))
        {
            VAPP_IMGEDT_WARN_TRACE(scrnRect.getHeight());
            m_orgZoom = (VfxFloat)IMGEDT_CLIP_MIN_LENGHTH / (VfxFloat)scrnRect.getHeight();
        }
        else
        {
            m_orgZoom = 1.0f;
            VAPP_IMGEDT_INFO_TRACE(1);
        }
        setZoomAndPan(m_orgZoom, m_orgPanX, m_orgPanY);
        if (tempZoom != m_orgZoom)
        {            
            updateImageInfo(VFX_TRUE);
            renderPreview();
        }
    }        

    if (res == SRV_IES_OK)
    {
        setUndoValid(VFX_FALSE);
        setRedoValid(VFX_TRUE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_UNDO_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::redo()
{
   /* 
    *Redo is not supportted in final service implement
    *

    if (!m_bRedoValid)
    {
        return -1;
    }
    
    srv_ies_result res = srv_ies_image_redo(m_hImg);
    renderPreview();
    if (res == SRV_IES_OK)
    {
        setUndoValid(VFX_TRUE);
        setRedoValid(VFX_FALSE);
    }
    */
    return 0;
}

VfxS32 VappImgEdtIesHdlr::save(VfxSize size, const VfxWChar* path)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SAVE_BEGIN, size.width, size.height);

    VFX_ASSERT(EDIT_TYPE_NONE == m_currType);
    
    srv_ies_result res;
    res = srv_ies_image_render_file_async(
                    m_hImg,
                    (const WCHAR*)path,
                    size.width,
                    size.height,
                    SRV_IES_RENDER_STRETCH,
                    RenderOverCallback,                                
                    (void*)this,
                    &m_hJob);

    if (SRV_IES_OK == res)
    {
        VFX_OBJ_CREATE(m_renderTimer, VfxTimer, this);
        m_renderTimer->setDuration(500);
        m_renderTimer->setStartDelay(500);
        m_renderTimer->m_signalTick.connect(this, &VappImgEdtIesHdlr::onRenderTimeout);
        m_renderTimer->start();
        m_currType = EDIT_TYPE_RENDER;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SAVE_END, res);
    return res;
}

VfxS32 VappImgEdtIesHdlr::cancelSave()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SAVE_CANCEL_BEGIN, m_currType);

    srv_ies_result res = SRV_IES_OK;
    if(EDIT_TYPE_RENDER == m_currType)
    {
        res = srv_ies_job_cancel(m_hJob);
        m_currType = EDIT_TYPE_NONE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SAVE_CANCEL_END, res);
    }
    if ((NULL != m_renderTimer) && (m_renderTimer->isValid()))
    {
        m_renderTimer->stop();
        VFX_OBJ_CLOSE(m_renderTimer);
        m_renderTimer = NULL;
    }
    return res;
}


VfxS32 VappImgEdtIesHdlr::getRenderProgress()
{
    if (NULL == m_hJob || EDIT_TYPE_RENDER != m_currType)
    {
        return -1;
    }
    VfxU32 percent; 
    srv_ies_result res = srv_ies_job_query_progress(m_hJob, &percent);
    VAPP_IMGEDT_INFO_TRACE(res);

    return percent;
}

void VappImgEdtIesHdlr::onRenderTimeout(VfxTimer *timer)
{
    if (EDIT_TYPE_RENDER == m_currType)
    {
        VfxS32 progress = getRenderProgress();
        m_signalRenderProgress.emit(progress);
    }
}

void VappImgEdtIesHdlr::onRenderOver(srv_ies_result result)
{
    if ((NULL != m_renderTimer) && (m_renderTimer->isValid()))
    {
        m_renderTimer->stop();
        VFX_OBJ_CLOSE(m_renderTimer);
        m_renderTimer = NULL;
    }
    m_currType = EDIT_TYPE_NONE;
    m_signalRenderCallback.emit(result);
}

VfxResId VappImgEdtIesHdlr::getErrorString(srv_ies_result ies_error_result)
{
    VfxResId res = (VfxResId)srv_ies_util_error_get_string(ies_error_result);
    VAPP_IMGEDT_INFO_TRACE(res);
    return res;
}

VfxS32  VappImgEdtIesHdlr::getCurrState()
{
    VAPP_IMGEDT_INFO_TRACE(m_currType);
    return m_currType;
}

VfxS32 VappImgEdtIesHdlr::getEffectIdByType(EffectType type)
{
    VfxS32 id;
    switch(type)
    {
    case EFFECT_TYPE_NONE:
        id = -1;
        break;
    case EFFECT_TYPE_NEGATIVE:
        id = SRV_IES_EFFECT_NEGATIVE;
        break;
    case EFFECT_TYPE_GRAYSCALE:
        id = SRV_IES_EFFECT_GRAYSCALE;
        break;
    case EFFECT_TYPE_MIRROR:
        id = SRV_IES_EFFECT_MIRROR;
        break;
    case EFFECT_TYPE_SEPIA:
        id = SRV_IES_EFFECT_SEPIA;
        break;
    case EFFECT_TYPE_SHARPNESS:
        id = SRV_IES_EFFECT_SHARPNESS;
        break;
    case EFFECT_TYPE_OILPAINT:
        id = SRV_IES_EFFECT_OILPAINT;
        break;
    default:
        id = -1;
        break;
    }
    return id;
}

VfxBool VappImgEdtIesHdlr::checkEffectValid(EffectType type, EffectInfo &effectInfo)
{
    VFX_ASSERT(type != EFFECT_TYPE_NONE); //EFFECT_TYPE_NONE not support by service
    
    VfxS32 id = getEffectIdByType(type);
    VfxBool isValid = (VfxBool)srv_ies_effect_is_available((srv_ies_effect_enum)id);
    effectInfo.setId(id);
    effectInfo.setValid(isValid);
    return isValid;
}

VfxS32 VappImgEdtIesHdlr::loadEffectInfo(VfxS32 index, S32 id)
{
    VFX_ASSERT(index != EFFECT_TYPE_NONE); //EFFECT_TYPE_NONE not support by service
    
    VfxS32 para_count;
    srv_ies_result ies_ret = srv_ies_effect_get_param_count((srv_ies_effect_enum)id, (U32 *)&para_count);
    return ies_ret;
}


VfxS32 VappImgEdtIesHdlr::loadAdjustInfo()
{
    srv_ies_result ies_ret;
    VfxS32 para_count, defValue, minValue, maxValue;
    VfxResId  nameId;
    
    ies_ret = srv_ies_effect_get_param_count(SRV_IES_EFFECT_COLOR_ADJUST, (U32 *)&para_count);
    VFX_ASSERT(0 != para_count);                  
    ies_ret = srv_ies_effect_get_effect_name(
                        SRV_IES_EFFECT_COLOR_ADJUST,
                        (MMI_STR_ID*)&nameId);

    for (VfxS32 index = 0; index < para_count; index++)
    {
        ies_ret = srv_ies_effect_get_param_name(SRV_IES_EFFECT_COLOR_ADJUST, index, (MMI_STR_ID*)&nameId);
        ies_ret = srv_ies_effect_get_param_default(SRV_IES_EFFECT_COLOR_ADJUST, index, &defValue);
        ies_ret = srv_ies_effect_get_param_range(SRV_IES_EFFECT_COLOR_ADJUST, index, &minValue, &maxValue);

        m_adjustItem[index].setValid(VFX_TRUE);
        m_adjustItem[index].setValue(defValue, minValue, maxValue);
    }
    //do not use string supply by service, instead of self define
    m_adjustItem[ADJUST_TYPE_BRIGHTNESS].setStrId(STR_ID_VAPP_IMGEDT_BRIGHTNESS);
    m_adjustItem[ADJUST_TYPE_CONTRAST].setStrId(STR_ID_VAPP_IMGEDT_CONTRAST);
    m_adjustItem[ADJUST_TYPE_SATURATION].setStrId(STR_ID_VAPP_IMGEDT_SATURATION);
    m_adjustItem[ADJUST_TYPE_HUE].setStrId(STR_ID_VAPP_IMGEDT_HUE);
    return ies_ret;
}

VfxS32 VappImgEdtIesHdlr::loadStaticInfo()
{
    //set no effect item
    m_effectItem[EFFECT_TYPE_NONE].setId(-1);
    m_effectItem[EFFECT_TYPE_NONE].setStrId(STR_ID_VAPP_IMGEDT_NO_EFFECT);
    m_effectItem[EFFECT_TYPE_NONE].setValid(VFX_TRUE);

    //init effect string
    m_effectItem[EFFECT_TYPE_NEGATIVE].setStrId(STR_ID_VAPP_IMGEDT_NEGATIVE);
    m_effectItem[EFFECT_TYPE_GRAYSCALE].setStrId(STR_ID_VAPP_IMGEDT_GRAYSCALE);
    m_effectItem[EFFECT_TYPE_MIRROR].setStrId(STR_ID_VAPP_IMGEDT_MIRROR);
    m_effectItem[EFFECT_TYPE_SEPIA].setStrId(STR_ID_VAPP_IMGEDT_SEPIA);
    m_effectItem[EFFECT_TYPE_SHARPNESS].setStrId(STR_ID_VAPP_IMGEDT_SHARPEN);
    m_effectItem[EFFECT_TYPE_OILPAINT].setStrId(STR_ID_VAPP_IMGEDT_WATER_COLOR);

    //load Effect info
    for (VfxS32 i = EFFECT_TYPE_NONE + 1; i < EFFECT_TOTAL; i++)
    {
        if (checkEffectValid((EffectType)i, m_effectItem[i]))
        {
            loadEffectInfo(i, m_effectItem[i].getId());
        }
    }
    //load adjust info
    loadAdjustInfo();
    return 0;
}

void VappImgEdtIesHdlr::setUndoValid(VfxBool valid)
{
    m_bUndoValid = valid;
}

void VappImgEdtIesHdlr::setRedoValid(VfxBool valid)
{
    m_bRedoValid = valid;
}

VfxBool VappImgEdtIesHdlr::checkUndoValid()
{
    return m_bUndoValid;
}

VfxBool VappImgEdtIesHdlr::checkRedoValid()
{
    return m_bRedoValid;
}

VFX_IMPLEMENT_CLASS("VappImgEdtApp", VappImgEdtApp, VfxApp);
VappImgEdtApp::VappImgEdtApp():
m_imgEdtScr(NULL),
m_pMemPool(NULL),
m_poolId(0),
m_pIesSrvMem(NULL),
m_pPreviewLayerMem(NULL),
m_pAvatarLayerMem(NULL)
{
    for (VfxS32 i = 0; i < IMGEDT_ADD_TEXT_MAX_COUNT ; i++)
    {
        m_pTextLayerMem[i] = NULL;
    }
}

void VappImgEdtApp::prepareMem()
{
    // prepare cacheable memory
    m_pIesSrvMem = applib_asm_alloc_r(VAPP_IMGEDT, IMGEDT_IES_SRV_MEM_SIZE_FULL);
    
    // prepare non-cacheable memory    
    VfxS32 layerMemSize = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2;
    VfxS32 poolSize = layerMemSize*2 + GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2;
    m_pMemPool = applib_asm_alloc_nc_r(VAPP_IMGEDT, poolSize);
    m_poolId = kal_adm_create(m_pMemPool, poolSize, NULL, KAL_TRUE);
    m_pPreviewLayerMem = kal_adm_alloc_noncacheable(m_poolId, layerMemSize, NULL);
    m_pAvatarLayerMem = kal_adm_alloc_noncacheable(m_poolId, layerMemSize, NULL);

    VFX_ASSERT(NULL != m_pMemPool);
    VFX_ASSERT(NULL != m_poolId);
    VFX_ASSERT(NULL != m_pIesSrvMem);
    VFX_ASSERT(NULL != m_pPreviewLayerMem);
    VFX_ASSERT(NULL != m_pAvatarLayerMem);

}

void VappImgEdtApp::unPrepareMem()
{
    VFX_ASSERT(NULL != m_pIesSrvMem);
    VFX_ASSERT(NULL != m_pPreviewLayerMem);
    VFX_ASSERT(NULL != m_pAvatarLayerMem);
    VFX_ASSERT(NULL != m_pMemPool);
    VFX_ASSERT(NULL != m_poolId);

    for (VfxS32 i = 0; i < IMGEDT_ADD_TEXT_MAX_COUNT ; i++)
    {
        if (NULL != m_pTextLayerMem[i])
        {
            kal_adm_free(m_poolId, m_pTextLayerMem[i]);
            m_pTextLayerMem[i] = NULL;
        }
    }
    kal_adm_free(m_poolId, m_pAvatarLayerMem);
    kal_adm_free(m_poolId, m_pPreviewLayerMem);
    kal_adm_delete(m_poolId);

    applib_asm_free_r(VAPP_IMGEDT, m_pMemPool);
    applib_asm_free_r(VAPP_IMGEDT, m_pIesSrvMem);

    m_pIesSrvMem = NULL;
    m_pPreviewLayerMem = NULL;
    m_pAvatarLayerMem = NULL;
    m_pMemPool = NULL;
    m_poolId = NULL;

}

void VappImgEdtApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    prepareMem();
     
    //save arg info
    vapp_imgedt_launch_struct *info = (vapp_imgedt_launch_struct *)args;
    m_srcFilePath.loadFromMem(info->filePath);
    m_rotate = info->rotate;
    
    VappImgEdtIesHdlr::reprepareInstance(VAPP_IMGEDT,
                                         m_pIesSrvMem,
                                         IMGEDT_IES_SRV_MEM_SIZE_FULL,
                                         (VfxWChar *)m_srcFilePath.getBuf(),
                                         VFX_OBJ_DYNAMIC_CAST(this, VfxApp)
                                         );

#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif /* __MMI_USB_SUPPORT__ */
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, VFX_TRUE);

    VFX_OBJ_CREATE(m_namingHelper, VcpImgEdtNamingHelper, this);
    
    VFX_OBJ_CREATE(m_imgEdtScr, VappImgEdtScr, this);
    m_imgEdtScr->setScrRotate(getRotation());
    m_imgEdtScr->show();
}

void VappImgEdtApp::onDeinit()
{
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif /* __MMI_USB_SUPPORT__ */
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, VFX_FALSE);

    VappImgEdtIesHdlr *ies = VappImgEdtIesHdlr::getInstance();
    if (NULL != ies)
    {
        ies->closeInstance();
    }

    unPrepareMem();
    
    VfxApp::onDeinit();
}

mmi_ret VappImgEdtApp::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
#ifdef __MMI_USB_SUPPORT__
    case EVT_ID_USB_ENTER_MS_MODE:
        {
            VappImgEdtIesHdlr *ies = VappImgEdtIesHdlr::getInstance();
            if (NULL != ies)
            {
                ies->cancelAll();
            }
        }
        exit();
        break;
#endif /*__MMI_USB_SUPPORT__*/

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
    {
        srv_fmgr_notification_dev_plug_event_struct *event = (srv_fmgr_notification_dev_plug_event_struct *)evt;
        for (VfxU32 i = 0; i < event->count; i++)
        {
            if (event->drv_letters[i] == m_srcFilePath[0])
            {
                VappImgEdtIesHdlr *ies = VappImgEdtIesHdlr::getInstance();
                if (NULL != ies)
                {
                    ies->cancelAll();
                }
                exit();
                break;
            }
        }
    }
        break;
    default:
        break;
    }
    return VfxApp::onProc(evt);
}


VfxU8* VappImgEdtApp::getPreviewLayerMem()
{
    return (VfxU8*)m_pPreviewLayerMem;
}

VfxU8* VappImgEdtApp::getAvatarLayerMem()
{
    return (VfxU8*)m_pAvatarLayerMem;
}

VfxU8* VappImgEdtApp::getTextLayerMem(VfxS32 size)
{
    VfxS32 index = -1;
    for (VfxS32 i = 0; i < IMGEDT_ADD_TEXT_MAX_COUNT; i++)
    {
        if (NULL == m_pTextLayerMem[i])
        {
            index = i;
            break;
        }
    }
    if (-1 == index)
    {
        return NULL;
    }
    
    VfxS32 leftSize = kal_adm_get_total_left_size(m_poolId);
    if (leftSize < size)
    {
        return NULL;
    }

    m_pTextLayerMem[index] = kal_adm_alloc_noncacheable(m_poolId, size, NULL);
    return (VfxU8*)m_pTextLayerMem[index];
}

void VappImgEdtApp::discardLastTextMem()
{
    VfxS32 index = -1;
    for (VfxS32 i = 0; i < IMGEDT_ADD_TEXT_MAX_COUNT; i++)
    {
        if (NULL != m_pTextLayerMem[i])
        {
            index = i;
        }
    }
    VFX_ASSERT(-1 != index);
    kal_adm_free(m_poolId, m_pTextLayerMem[index]);
    m_pTextLayerMem[index] = NULL;
}

VfxWString VappImgEdtApp::getFileName()
{
    return m_namingHelper->getOrgFileName(m_srcFilePath);
}

VfxWString &VappImgEdtApp::getNewFilePath(VfxWString &name)
{
    m_destFilePath = m_namingHelper->getNewPathByName(m_srcFilePath, name);
    return m_destFilePath;
}

VfxWString &VappImgEdtApp::getNewFilePath()
{
    return m_destFilePath;
}

VfxScrRotateTypeEnum VappImgEdtApp::getRotation()
{
    VfxScrRotateTypeEnum rot;
    switch (m_rotate)
    {
    case VAPP_IMGEDT_SCR_ROTATE_0:
        rot = VFX_SCR_ROTATE_TYPE_0;
        break;

    case VAPP_IMGEDT_SCR_ROTATE_270:
        rot = VFX_SCR_ROTATE_TYPE_270;
        break;

    case VAPP_IMGEDT_SCR_ROTATE_90:        
        rot = VFX_SCR_ROTATE_TYPE_90;
        break;

    default:
        rot = VFX_SCR_ROTATE_TYPE_90;
        break;
    }
    return rot;
}


VFX_IMPLEMENT_CLASS("VappImgEdtScr", VappImgEdtScr, VappImgEdtBaseScr);

void VappImgEdtScr::on1stReady()
{
    VappImgEdtBaseScr::on1stReady();
    
    VFX_OBJ_CREATE(m_previewPage, VappImgEdtPreviewPage, this);
    pushPage(0, m_previewPage);
}

void VappImgEdtScr::on2ndReady()
{
	m_previewPage->onInitStage2();
}

void VappImgEdtScr::enterEditPage(VfxS32 pos, void *param)
{
    if (NULL != m_scrollPanelInfo[pos].enter_func)
    {
        m_scrollPanelInfo[pos].enter_func(&m_editPage, this, param);
        pushPage(VFX_ID_NULL, m_editPage);
    }
}


VFX_IMPLEMENT_CLASS("VappImgEdtPreviewPage", VappImgEdtPreviewPage, VfxPage);

VappImgEdtPreviewPage::VappImgEdtPreviewPage():
m_bottomBar(NULL),
m_iesHdlr(NULL),
m_savePopup(NULL),
m_menu(NULL),
m_saveIndPopup(NULL),
m_topHL(NULL),
m_createPreviewRes(0),
m_lastMovePos(0,0),
m_bMoving(VFX_FALSE),
m_bgRange(0, 0, 0, 0),
m_bHaveErrorPopup(VFX_FALSE),
m_isFirstEnter(VFX_TRUE),
m_indWeakPtr(NULL)
{
}

void VappImgEdtPreviewPage::onInit()
{
    VfxPage::onInit();
    VfxFrame::setBgColor(VFX_COLOR_BLACK);

    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappImgEdtBaseScr);
    VfxBool is_vert;
    if (scr->checkVertMode())
    {
        is_vert = VFX_TRUE;
        m_scrnSize = VfxSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }
    else
    {
        is_vert = VFX_FALSE;
        m_scrnSize = VfxSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }
    
    /*VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VfxU8* buf = app->getPreviewLayerMem();
    VFX_ASSERT(NULL != buf);
    
    m_iesHdlr = VappImgEdtIesHdlr::getInstance();
    VFX_ASSERT (NULL != m_iesHdlr);
    m_createPreviewRes = m_iesHdlr->getLastError();
    if (0 == m_createPreviewRes)
    {
        m_createPreviewRes = m_iesHdlr->createPreviewInternal(buf, m_scrnSize);
        if (0 != m_createPreviewRes)
        {
            VAPP_IMGEDT_ERROR_TRACE(m_createPreviewRes);
        }
    }
    else
    {
        VAPP_IMGEDT_ERROR_TRACE(m_createPreviewRes);
    }*/

    setStatusBar(VFX_TRUE);
    setTranslucent(VFX_TRUE);

    VfxS32  topBarHeight = MMI_STATUS_BAR_HEIGHT;
    // scrollable body
    VFX_OBJ_CREATE_EX(m_menu, VcpImgEdtScrollPanel, this, (is_vert));
    if (is_vert)
    {
        m_menu->setPos(VfxPoint(0, topBarHeight));
        m_menu->setBounds(VfxRect(0, 0, m_scrnSize.width, IMGEDT_TOP_BAR_BTN_HEIGHT));
    }
    else
    {
        m_menu->setPos(VfxPoint(m_scrnSize.width - IMGEDT_TOP_BAR_BTN_WIDTH, topBarHeight));
        m_menu->setBounds(VfxRect(0, 0, IMGEDT_TOP_BAR_BTN_WIDTH, m_scrnSize.height - topBarHeight));       
    }
    m_menu->m_tapCell.connect(this, &VappImgEdtPreviewPage::onTapEdtBtn);
    m_menu->m_signalHighLight.connect(this, &VappImgEdtPreviewPage::onHighlightChanged);
	updateTopBar();

    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtToolBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_TOOL_BAR_HEIGHT);
    if (is_vert)
    {
        m_bottomBar->setSize(m_scrnSize);
    }
    else
    {
        m_bottomBar->setSize(VfxSize(m_scrnSize.width - IMGEDT_TOP_BAR_BTN_WIDTH, m_scrnSize.height));
    } 
    m_bottomBar->addItem(TOOLBAR_SAVE, IMG_ID_IMGEDT_BOTTOMBAR_SAVE);
    m_bottomBar->addItem(TOOLBAR_UNDO, IMG_ID_IMGEDT_BOTTOMBAR_UNDO);
    m_bottomBar->show();
    m_bottomBar->setBtnDisabled(TOOLBAR_SAVE,VFX_TRUE);
	updateBottomBar();
    
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtPreviewPage::onToolBarBtnClicked);

    VFX_OBJ_CREATE(m_topHL, VfxFrame, this);
    VfxSize iconSize = VfxImageSrc(IMG_ID_IMGEDT_TITLEBAR_CLIP).getSize();
    VfxSize haloSize;
    VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
    m_topHL->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BUTTON_HALO));
    m_topHL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_topHL->setSize(haloSize);
    m_topHL->setAnchor(0.5f, 0.5f);
    m_topHL->setHidden(VFX_TRUE);

    /*if (0 == m_createPreviewRes)
    {
        prepareImageBegin();
    }*/
}

void VappImgEdtPreviewPage::onInitStage2()
{
	m_isFirstEnter = VFX_FALSE;
	
	VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VfxU8* buf = app->getPreviewLayerMem();
    VFX_ASSERT(NULL != buf);
    
    m_iesHdlr = VappImgEdtIesHdlr::getInstance();
    VFX_ASSERT (NULL != m_iesHdlr);
    m_createPreviewRes = m_iesHdlr->getLastError();
    if (0 == m_createPreviewRes)
    {
        m_createPreviewRes = m_iesHdlr->createPreviewInternal(buf, m_scrnSize);
        if (0 != m_createPreviewRes)
        {
            VAPP_IMGEDT_ERROR_TRACE(m_createPreviewRes);
        }
    }
    else
    {
        VAPP_IMGEDT_ERROR_TRACE(m_createPreviewRes);
    }
    if (0 == m_createPreviewRes)
    {
        prepareImageBegin();
    }

	VcpImgEdtPreviewLayer *preview = m_iesHdlr->getPreviewInternal();
	if (NULL != preview)
	{
		insertChildFrameBefore(m_menu, preview);
	}
	updateBottomBar();

	if ((0 == m_createPreviewRes) && 
		(VappImgEdtIesHdlr::EDIT_TYPE_RENDER != m_iesHdlr->getCurrState()) &&
		(VappImgEdtIesHdlr::EDIT_TYPE_CREATE_META != m_iesHdlr->getCurrState()))
	{
		m_iesHdlr->updateImageInfo(VFX_TRUE);
		m_iesHdlr->renderPreview();
		updateTopBar();
		m_iesHdlr->getScrnArea(&m_bgRange);
	}
	
    if ((0 != m_createPreviewRes) && (!m_bHaveErrorPopup))
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)m_createPreviewRes);
        onErrorPopup(strId);
        m_bHaveErrorPopup = VFX_TRUE;
    }
	
}

void VappImgEdtPreviewPage::onDeinit()
{
    //if(m_saveIndPopup!=NULL)
    if (m_indWeakPtr.isValid())
    {
        m_saveIndPopup->m_signalCanceled.disconnect(this, 
            &VappImgEdtPreviewPage::onSaveCanceled);
        m_saveIndPopup->exit(VFX_TRUE);
        m_saveIndPopup = NULL;
    }

	if(m_iesHdlr!=NULL)
	{
	    m_iesHdlr->cancelAll();
	    m_iesHdlr->destroyPreview();
	}
    VfxPage::onDeinit();
}

void VappImgEdtPreviewPage::onEnter(VfxBool isBackward)
{   
    VfxPage::onEnter(isBackward);
	if(!m_isFirstEnter)
	{
	    setStatusBar(VFX_TRUE);
	    VcpImgEdtPreviewLayer *preview = m_iesHdlr->getPreviewInternal();
	    if (NULL != preview)
	    {
	        insertChildFrameBefore(m_menu, preview);
	    }
	    updateBottomBar();

	    if ((0 == m_createPreviewRes) && 
	        (VappImgEdtIesHdlr::EDIT_TYPE_RENDER != m_iesHdlr->getCurrState()) &&
	        (VappImgEdtIesHdlr::EDIT_TYPE_CREATE_META != m_iesHdlr->getCurrState()))
	    {
	        m_iesHdlr->updateImageInfo(VFX_TRUE);
	        m_iesHdlr->renderPreview();
	        updateTopBar();
	        m_iesHdlr->getScrnArea(&m_bgRange);
	    }
	}
}

void VappImgEdtPreviewPage::onEntered()
{
    VfxPage::onEntered();

    if ((0 != m_createPreviewRes) && (!m_bHaveErrorPopup)&&(!m_isFirstEnter))
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)m_createPreviewRes);
        onErrorPopup(strId);
        m_bHaveErrorPopup = VFX_TRUE;
    }
}

void VappImgEdtPreviewPage::onExit(VfxBool isBackward)
{
    VfxPage::onExit(isBackward);
}

/*VfxScrRotateTypeEnum VappImgEdtPreviewPage::onQueryRotate(const VfxScreenRotateParam &param)
{
    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(),VappImgEdtBaseScr);
    return scr->getScrRotate();
}
*/

void VappImgEdtPreviewPage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(),VappImgEdtBaseScr);
	param.rotateTo = scr->getScrRotate();
}

VfxBool VappImgEdtPreviewPage::onPenInput(VfxPenEvent &event)
{
    VfxBool ret = VFX_FALSE;
    VfxSize distance;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if (m_bMoving)
        {
            distance = VfxSize((event.pos.x - m_lastMovePos.x), 
                               (event.pos.y - m_lastMovePos.y));
            m_iesHdlr->setDragSmart(distance);
            m_bMoving = VFX_FALSE;
            ret = VFX_TRUE;
        }        
        break;
    
    case VFX_PEN_EVENT_TYPE_DOWN:
        if (m_bgRange.contains(event.pos))
        {
            m_lastMovePos = event.pos;
            m_bMoving = VFX_TRUE;
            ret = MMI_TRUE;
        }        
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_bMoving)
        {
            if (abs(m_lastMovePos.x - event.pos.x) >= IMGEDT_IMAGE_MOVE_MIN_RADIUS ||
                abs(m_lastMovePos.y - event.pos.y) >= IMGEDT_IMAGE_MOVE_MIN_RADIUS)
            {
                distance = VfxSize((event.pos.x - m_lastMovePos.x), 
                                   (event.pos.y - m_lastMovePos.y));
                m_iesHdlr->setDragSmart(distance);
                m_lastMovePos = event.pos;
            }
            ret = VFX_TRUE;
        }        
        break;
    case VFX_PEN_EVENT_TYPE_ABORT:
        m_bMoving = VFX_FALSE;
    default:
        ret = VFX_TRUE;
        break;
    }    
    return ret;
}


void VappImgEdtPreviewPage::onTapEdtBtn(VfxS32 pos, VfxFrame* cell)
{

    VappImgEdtScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(),VappImgEdtScr);
    scr->enterEditPage(pos, NULL);
}

void VappImgEdtPreviewPage::onHighlightChanged(VfxBool is_on, VfxS32 pos, VfxFrame* cell)
{
    if (is_on)
    {
        VfxPoint pos = cell->getPos();
        VfxRect rect = cell->convertRectTo(cell->getRect(), this);
        VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappImgEdtBaseScr);
        if (scr->checkVertMode())
        {
            m_topHL->setPos(rect.getMidX() - pos.x, rect.getMidY());
        }
        else
        {
            m_topHL->setPos(rect.getMidX(), rect.getMidY() - pos.y);
        }
        
        m_topHL->setHidden(VFX_FALSE);
    }
    else
    {
        m_topHL->setHidden(VFX_TRUE);
    }
}

void VappImgEdtPreviewPage::onToolBarBtnClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
    case TOOLBAR_SAVE:
        saveImage();
        break;

    case TOOLBAR_UNDO:
        m_iesHdlr->undo();
        updateBottomBar();
        updateTopBar();
        m_iesHdlr->getScrnArea(&m_bgRange);
        break;

    case TOOLBAR_REDO:
        m_iesHdlr->redo();
        updateBottomBar();
        updateTopBar();
        break;

    case TOOLBAR_CANCEL:
        getApp()->exit();
        break;
    }
}

void VappImgEdtPreviewPage::saveImage()
{
    VfxSize size;
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    
    VFX_OBJ_CREATE(m_savePopup, VcpImgEdtSavePopup, this);
    m_iesHdlr->getCurrImageSize(size);
    m_savePopup->setMaxSize(size);
    m_savePopup->setText(app->getFileName(), SRV_FMGR_PATH_MAX_FILE_NAME_LEN, VFX_FALSE);
    
	VfxS8 *ext;
    VFX_ALLOC_MEM(ext, 5*2, this);
  	mmi_ucs2cpy((CHAR *)ext,".jpg");
	m_savePopup->setExt((VfxS8 *)ext);
	VFX_FREE_MEM(ext);
	
    VfxWString str = m_savePopup->getText();
    VfxWString path = app->getNewFilePath(str);
    m_savePopup->setPath(path);
    m_savePopup->show(VFX_TRUE);
    m_savePopup->m_signalButtonClicked.connect(this, &VappImgEdtPreviewPage::onSavePopupBtnClicked);
}

void VappImgEdtPreviewPage::onSavePopupBtnClicked(VfxObject*  obj, VcpInputPopupButtonEnum type)
{    
    if (VCP_INPUT_POPUP_BTN_OK == type)
    {
        if(m_savePopup->isValidFilePath() >= FS_NO_ERROR)
        {
            VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
            VfxWString str = m_savePopup->getText();
            const VfxWChar *path = app->getNewFilePath(str).getBuf();
            if (FS_NO_ERROR == srv_fmgr_fs_path_exist(path))
            {
                m_savePopup->setHidden(VFX_TRUE);
                displayOverWritePopup();
            }
            else
            {
                onSaveStart();
            }
        }
        else
        {
            m_savePopup->setErrorText(VFX_WSTR_RES(srv_fmgr_fs_error_get_string
                (m_savePopup->isValidFilePath()) ));
            //m_savePopup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_INVALID_FILENAME));
        }
    }
    else if (VCP_INPUT_POPUP_BTN_CANCEL == type)
    {
        m_savePopup->exit(VFX_TRUE);
        m_savePopup = NULL;
    }  
}

void VappImgEdtPreviewPage::displayOverWritePopup()
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpCommandPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setText(VFX_WSTR_RES(STR_GLOBAL_FILENAME_ALREADY_EXISTS));
    m_confirmPopup->addItem((VfxId)'Rena', VFX_WSTR_RES(STR_GLOBAL_RENAME));
    m_confirmPopup->addItem((VfxId)'Over', VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_OVER_WRITE));
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappImgEdtPreviewPage::onCommandClicked);
}

void VappImgEdtPreviewPage::onCommandClicked(VfxObject *obj, VfxId command)
{
    m_confirmPopup->leave(VFX_TRUE);
    switch (command)
    {
    case 'Rena':
    case VCP_POPUP_BUTTON_NO_PRESSED:
        m_savePopup->getInputbox()->showSoftInput();
        m_savePopup->setHidden(VFX_FALSE);
        break;
        
    case 'Over':
        onSaveStart(); 
        break;

    default:
        VAPP_IMGEDT_WARN_TRACE(command);
        break;
    }
}

void VappImgEdtPreviewPage::onSaveStart()
{
    //send event to 
    vapp_imgedt_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_IMGEDT_BEGIN_SAVE, getApp()->getGroupId());
    evt.filePath = (VfxWChar *)NULL;
    getApp()->sendToCaller((mmi_group_event_struct*)&evt); 

    VfxSize size = m_savePopup->getCurrSize();
    VfxWString str = m_savePopup->getText();
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VFX_OBJ_CLOSE(m_savePopup);
    m_savePopup = NULL;

    VfxS32 ret = m_iesHdlr->save(size, app->getNewFilePath(str));

    if (0 == ret)
    {
        VFX_OBJ_CREATE(m_saveIndPopup, VcpIndicatorPopup, this);
        m_saveIndPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
        m_saveIndPopup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));
        m_saveIndPopup->setProgress(0.0f);
        m_saveIndPopup->show(VFX_TRUE);
        m_saveIndPopup->m_signalCanceled.connect(this, &VappImgEdtPreviewPage::onSaveCanceled);
        m_iesHdlr->m_signalRenderProgress.connect(this, &VappImgEdtPreviewPage::onSaveProgress);
        m_iesHdlr->m_signalRenderCallback.connect(this, &VappImgEdtPreviewPage::onSaveEnd);
        m_indWeakPtr = m_saveIndPopup;
    }
    else
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId, VFX_FALSE);
    }
}

void VappImgEdtPreviewPage::onSaveProgress(VfxS32 progress)
{
    if (!m_indWeakPtr.isValid())
        return;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_SAVE_PROGRESS, progress, __LINE__);
    m_saveIndPopup->setProgress((VfxFloat)progress/100);
}

void VappImgEdtPreviewPage::onSaveEnd(srv_ies_result result)
{
    if (SRV_IES_OK == result)
    {
        m_saveIndPopup->setProgress(1.0);
        VfxTimer *timer;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->setStartDelay(2);
        timer->setDuration(0);
        timer->m_signalTick.connect(this, &VappImgEdtPreviewPage::onSaveEndTimer);
        timer->start();
    }
    else
    {
        VfxResId strId = m_iesHdlr->getErrorString(result);
        onErrorPopup(strId, VFX_FALSE);
        m_saveIndPopup->leave(VFX_TRUE);
    }    
}

void VappImgEdtPreviewPage::onSaveCanceled(VfxObject* obj, VfxFloat progress)
{
    if (!m_indWeakPtr.isValid())
            return;
  
    m_iesHdlr->cancelSave();
}

void VappImgEdtPreviewPage::onSaveEndTimer(VfxTimer *source)
{
    vapp_imgedt_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_IMGEDT_SAVED, getApp()->getGroupId());
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    evt.filePath = (VfxWChar *)app->getNewFilePath().getBuf();
    getApp()->sendToCaller((mmi_group_event_struct*)&evt); 
    m_saveIndPopup->leave(VFX_TRUE);
    //do not popup done and exit directly.
    getApp()->exit();
}

void VappImgEdtPreviewPage::updateBottomBar()
{
	if(m_iesHdlr==NULL)
	{
		m_bottomBar->setBtnDisabled(TOOLBAR_REDO,VFX_TRUE);
        m_bottomBar->setBtnDisabled(TOOLBAR_UNDO,VFX_TRUE);
		return;
	}

    if (m_iesHdlr->checkRedoValid())
    {
        m_bottomBar->setBtnDisabled(TOOLBAR_REDO,VFX_FALSE);
    }
    else
    {
        m_bottomBar->setBtnDisabled(TOOLBAR_REDO,VFX_TRUE);
    }
    if (m_iesHdlr->checkUndoValid())
    {
        m_bottomBar->setBtnDisabled(TOOLBAR_UNDO,VFX_FALSE);
    }
    else
    {
        m_bottomBar->setBtnDisabled(TOOLBAR_UNDO,VFX_TRUE);
    }
}


void VappImgEdtPreviewPage::updateTopBar()
{
	if(m_iesHdlr!=NULL)
	{
	    if (!m_iesHdlr->checkAllEnabled())
	    {
	        m_menu->setBtnDisabled(EDIT_ROTATE, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_CROP, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_ADJUST, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_EFFECT, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_FLIP, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_FRAME, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_CLIPART, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_TEXT, VFX_TRUE);
	        m_menu->setBtnDisabled(EDIT_DOODLE, VFX_TRUE);
	    }
	    else
	    {
	        VfxSize size;
	        m_iesHdlr->getCurrImageSize(size);
	        VfxBool bDisabled = VFX_FALSE;
	        if ((size.width < IMGEDT_CLIP_MIN_LENGHTH) || (size.height < IMGEDT_CLIP_MIN_LENGHTH))
	        {
	            bDisabled = VFX_TRUE;   
	        }
	        m_menu->setBtnDisabled(EDIT_ROTATE, VFX_FALSE);
	        m_menu->setBtnDisabled(EDIT_CROP, bDisabled);
	        m_menu->setBtnDisabled(EDIT_ADJUST, VFX_FALSE);
	        m_menu->setBtnDisabled(EDIT_EFFECT, VFX_FALSE);
	        m_menu->setBtnDisabled(EDIT_FLIP, VFX_FALSE);
	        m_menu->setBtnDisabled(EDIT_FRAME, bDisabled);
	        m_menu->setBtnDisabled(EDIT_CLIPART, bDisabled);
	        m_menu->setBtnDisabled(EDIT_TEXT, bDisabled);
	        m_menu->setBtnDisabled(EDIT_DOODLE, bDisabled);

	        /* Not allow add frame for large file > 5M */
	        if (m_iesHdlr->checkIsLargeFile())
	        {
	            m_menu->setBtnDisabled(EDIT_FRAME, VFX_TRUE);
	        }        
	    }
	}
	else
	{
		m_menu->setBtnDisabled(EDIT_ROTATE, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_CROP, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_ADJUST, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_EFFECT, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_FLIP, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_FRAME, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_CLIPART, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_TEXT, VFX_TRUE);
        m_menu->setBtnDisabled(EDIT_DOODLE, VFX_TRUE);
	}
}

void VappImgEdtPreviewPage::prepareImageBegin()
{
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VfxWString path = app->getSrcFilePath();
    m_iesHdlr->m_signalCreateMetaCallback.connect(this, &VappImgEdtPreviewPage::prepareImageEnd);
    VfxS32 ret = m_iesHdlr->createMeta((VfxWChar*)path.getBuf(), m_scrnSize.width, m_scrnSize.height);
    if (ret < 0)
    {
        ret = m_iesHdlr->renderPreview();
        if (ret < 0)
        {
            m_createPreviewRes = ret;
        }
        return;
    }

    //hide & disable UI element
    m_iesHdlr->getPreviewInternal()->setHidden(VFX_TRUE);
    m_bottomBar->setBtnDisabled(TOOLBAR_SAVE,VFX_TRUE);
    updateTopBar();
    
    //create waiting icon
    VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
    m_waitIcon->setPos(VfxPoint(getSize().width/2, getSize().height/2));
    m_waitIcon->setAnchor(0.5, 0.5);
    m_waitIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID);    
    m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
    m_waitIcon->setAutoAnimate(VFX_TRUE);
    m_waitIcon->start();
}

void VappImgEdtPreviewPage::prepareImageEnd(VfxS32 result)
{
    m_waitIcon->stop();
    VFX_OBJ_CLOSE(m_waitIcon);
    m_waitIcon = NULL;

    m_iesHdlr->getPreviewInternal()->setHidden(VFX_FALSE);
    m_bottomBar->setBtnDisabled(TOOLBAR_SAVE,VFX_FALSE);
    
    VfxS32 ret = m_iesHdlr->renderPreview();
    if (ret < 0)
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
    else
    {
        m_iesHdlr->updateImageInfo(VFX_TRUE);
        m_iesHdlr->renderPreview();
        updateBottomBar();
        updateTopBar();
        m_iesHdlr->getScrnArea(&m_bgRange);
    }           
}

VFX_IMPLEMENT_CLASS("VappImgEdtBasePage", VappImgEdtBasePage, VfxPage);

VappImgEdtBasePage::VappImgEdtBasePage():
m_hintBtn(NULL),
m_zoomSlider(NULL),
m_zoomAdd(NULL),
m_zoomDec(NULL),
m_iesHdlr(NULL),
m_bottomBar(NULL),
m_zoomTimer(NULL),
m_pressedKey(VFX_KEY_CODE_UNKNOWN),
m_pageState(STATE_PREVIEW),
m_scrnSize(0,0),
m_lastMovePos(0,0),
m_bgRange(0, 0, 0, 0),
m_lastZoomIndx(0),
m_bMoving(VFX_FALSE),
m_keyDownRet(0)
{
    setTranslucent(VFX_TRUE);
}
    
void VappImgEdtBasePage::onInit()
{
    VfxPage::onInit();
    VfxFrame::setBgColor(VFX_COLOR_BLACK);
    
    VFX_OBJ_CREATE(m_markDummy, VfxFrame, this);

    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappImgEdtBaseScr);
    m_iesHdlr = VappImgEdtIesHdlr::getInstance();
    m_vertMode = scr->checkVertMode();
    if (m_vertMode)
    {
        m_scrnSize = VfxSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }
    else
    {
        m_scrnSize = VfxSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }    
    setStatusBar(VFX_FALSE);
}

void VappImgEdtBasePage::onDeinit()
{
    VfxPage::onDeinit();
}

void VappImgEdtBasePage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (!isBackward)
    {
        setStatusBar(VFX_FALSE);
        VcpImgEdtPreviewLayer *preview = m_iesHdlr->getPreviewInternal();
        if (NULL != preview)
        {
            insertChildFrameBefore(m_markDummy, preview);
            
            m_iesHdlr->updateImageInfo(VFX_TRUE);
            m_iesHdlr->getScrnArea(&m_bgRange);
        }
    }    
}
void VappImgEdtBasePage::onEntered()
{
    VfxPage::onEntered();
	/*if(VFX_KEY_CODE_ARROW_UP == m_pressedKey 
		|| VFX_KEY_CODE_ARROW_DOWN  == m_pressedKey
		|| VFX_KEY_CODE_ARROW_LEFT  == m_pressedKey
		|| VFX_KEY_CODE_ARROW_RIGHT == m_pressedKey
		)
		{
			VfxFloat curVal = m_zoomSlider->getCurrentValue();
			onZoomSliderReleased(m_zoomSlider, curVal);
			m_pressedKey = VFX_KEY_CODE_UNKNOWN;
		}*/
}

void VappImgEdtBasePage::onExit(VfxBool isBackward)
{
    stopZoomTimer();
	if(VFX_KEY_CODE_ARROW_UP == m_pressedKey 
		|| VFX_KEY_CODE_ARROW_DOWN == m_pressedKey
		|| VFX_KEY_CODE_ARROW_LEFT == m_pressedKey 
		|| VFX_KEY_CODE_ARROW_RIGHT == m_pressedKey
		)
	{
		VfxFloat curVal = m_zoomSlider->getCurrentValue();
		onZoomSliderReleased(m_zoomSlider, curVal);
		m_pressedKey = VFX_KEY_CODE_UNKNOWN;
	}
    VfxPage::onExit(isBackward);
}


/*VfxScrRotateTypeEnum VappImgEdtBasePage::onQueryRotate(const VfxScreenRotateParam &param)
{
    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(),VappImgEdtBaseScr);
    return scr->getScrRotate();
}
*/

void VappImgEdtBasePage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(),VappImgEdtBaseScr);
	param.rotateTo = scr->getScrRotate();
}

VfxBool VappImgEdtBasePage::isAllowMove()
{
    if (NULL == m_zoomSlider)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

VfxBool VappImgEdtBasePage::onPenInput(VfxPenEvent &event)
{
    VfxBool ret = VFX_FALSE;
    VfxSize distance;

    if (!isAllowMove())
    {
        return ret;
    }

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if (m_bMoving)
        {
            distance = VfxSize((event.pos.x - m_lastMovePos.x), 
                               (event.pos.y - m_lastMovePos.y));
            m_iesHdlr->setDragSmart(distance);
            m_bMoving = VFX_FALSE;
            ret = VFX_TRUE;
        }        
        break;
    
    case VFX_PEN_EVENT_TYPE_DOWN:
        if (isImageContains(event))
        {
            m_lastMovePos = event.pos;
            m_bMoving = VFX_TRUE;
            ret = MMI_TRUE;
        }        
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_bMoving)
        {
            if (abs(m_lastMovePos.x - event.pos.x) >= IMGEDT_IMAGE_MOVE_MIN_RADIUS ||
                abs(m_lastMovePos.y - event.pos.y) >= IMGEDT_IMAGE_MOVE_MIN_RADIUS)
            {
                distance = VfxSize((event.pos.x - m_lastMovePos.x), 
                                   (event.pos.y - m_lastMovePos.y));
                m_iesHdlr->setDragSmart(distance);
                m_lastMovePos = event.pos;
            }
            ret = VFX_TRUE;
        }        
        break;
    case VFX_PEN_EVENT_TYPE_ABORT:
        m_bMoving = VFX_FALSE;
    default:
        ret = VFX_TRUE;
        break;
    }    
    return ret;
}

VfxBool VappImgEdtBasePage::onKeyInput(VfxKeyEvent & event)
{
    switch (event.keyCode)
    {
    case VFX_KEY_CODE_CSK:
        return onCenterKeyInput(event);

    case VFX_KEY_CODE_ARROW_UP:
    case VFX_KEY_CODE_ARROW_DOWN:
	case VFX_KEY_CODE_ARROW_LEFT:
	case VFX_KEY_CODE_ARROW_RIGHT:	
        return onArrowKeyInput(event);
        
    default:
        break;
    }
    return VfxPage::onKeyInput(event);
}

void VappImgEdtBasePage::createZoomSlider(VfxObject *parent)
{
    VFX_OBJ_CREATE(m_zoomSlider, VcpSlider, parent);
    m_zoomSlider->setAnchor(0.5f, 0.5f);
    if (m_vertMode)
    {
        m_zoomSlider->setPos(IMGEDT_ZOOM_SLIDER_X_V, m_scrnSize.height/2);
        m_zoomSlider->setLength(IMGEDT_ZOOM_SLIDER_LENGTH_V);
    }
    else
    {
        m_zoomSlider->setPos(IMGEDT_ZOOM_SLIDER_X_H, m_scrnSize.height/2);
        m_zoomSlider->setLength(IMGEDT_ZOOM_SLIDER_LENGTH_H);
    }
    m_zoomSlider->setMaxValue(1);
    m_zoomSlider->setMinValue(0);
    m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_zoomSlider->m_signalThumbPressed.connect(this, &VappImgEdtBasePage::onZoomSliderPressed);
    m_zoomSlider->m_signalThumbDrag.connect(this, &VappImgEdtBasePage::onZoomSliderMove);
    m_zoomSlider->m_signalThumbReleased.connect(this, &VappImgEdtBasePage::onZoomSliderReleased);
    m_zoomSlider->setLayout(VCP_SLIDER_LAYOUT_VERT);

    m_lastZoomIndx = 0;

    VFX_OBJ_CREATE(m_zoomAdd, VfxImageFrame, parent);
    m_zoomAdd->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_ADD_ICON));
    m_zoomAdd->setAnchor(0.5f, 0.5f);
    m_zoomAdd->setPos(m_zoomSlider->getPos().x, m_zoomSlider->getRect().getMinY() - IMGEDT_ZOOM_ADD_OFFSET_Y);
    m_zoomAdd->setIsUnhittable(VFX_TRUE);
        
    VFX_OBJ_CREATE(m_zoomDec, VfxImageFrame, parent);
    m_zoomDec->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_REDUCE_ICON));
    m_zoomDec->setAnchor(0.5f, 0.5f);
    m_zoomDec->setPos(m_zoomSlider->getPos().x, m_zoomSlider->getRect().getMaxY() + IMGEDT_ZOOM_DEC_OFFSET_Y);
    m_zoomDec->setIsUnhittable(VFX_TRUE);

    #if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) 
    if(!m_vertMode)
    {
        m_zoomSlider->setPos(m_scrnSize.width/2,m_bottomBar->getPos().y-IMGEDT_ZOOM_TOOLBAR_OFFSET_Y);
        m_zoomSlider->setLayout(VCP_SLIDER_LAYOUT_HORZ);

        //m_zoomAdd->setPos(m_zoomSlider->getRect().getMaxX() + IMGEDT_ZOOM_ADD_OFFSET_X, m_zoomSlider->getPos().y);
        
        //m_zoomDec->setPos(m_zoomSlider->getRect().getMinX() - IMGEDT_ZOOM_DEC_OFFSET_X, m_zoomSlider->getPos().y);
		
        m_zoomAdd->setPos(m_zoomSlider->getRect().getMaxX() + IMGEDT_ZOOM_ADD_OFFSET_X, 
        	m_bottomBar->getPos().y-IMGEDT_ZOOM_TOOLBAR_OFFSET_Y);
        
        m_zoomDec->setPos(m_zoomSlider->getRect().getMinX() - IMGEDT_ZOOM_DEC_OFFSET_X, 
			m_bottomBar->getPos().y-IMGEDT_ZOOM_TOOLBAR_OFFSET_Y);
	}
	#else
    if(!m_vertMode)
	{
		if(m_bottomBar->getbtnNum(1)>0)
		{
        	m_zoomSlider->setPos(IMGEDT_ZOOM_SLIDER_X_H, (m_scrnSize.height-(m_bottomBar->getSize().height>>1))/2);
	        m_zoomSlider->setLength(IMGEDT_ZOOM_SLIDER_LENGTH_H - (m_bottomBar->getSize().height>>1));
			m_zoomDec->setPos(m_zoomSlider->getPos().x, m_zoomSlider->getRect().getMaxY() + IMGEDT_ZOOM_DEC_OFFSET_Y);
		}
	}
    #endif
    
}

void VappImgEdtBasePage::deleteZoomSlider()
{
    VFX_OBJ_CLOSE(m_zoomSlider);
    VFX_OBJ_CLOSE(m_zoomAdd);
    VFX_OBJ_CLOSE(m_zoomDec);
    m_zoomSlider = NULL;
    m_zoomAdd = NULL;
    m_zoomDec = NULL;
}

void VappImgEdtBasePage::createHindBtn(VfxObject *parent)
{
    VFX_OBJ_CREATE(m_hintBtn, VcpImgEdtHintBtn, parent);
    VcpStateImage imgList(IMG_ID_IMGEDT_BOTTOMBAR_FOLD,
                          IMG_ID_IMGEDT_BOTTOMBAR_FOLD,
                          IMG_ID_IMGEDT_BOTTOMBAR_FOLD,
                          IMG_ID_IMGEDT_BOTTOMBAR_FOLD);
    m_hintBtn->setImage(imgList);
    m_hintBtn->setBounds(VfxRect(0, 0, IMGEDT_HIDE_BTN_SIZE, IMGEDT_HIDE_BTN_SIZE));
    m_hintBtn->setIsHighlight(VFX_TRUE);
    if (m_vertMode)
    {
        m_hintBtn->setPos(IMGEDT_HIDE_BTN_X_V, IMGEDT_HIDE_BTN_Y_V);
    }
    else
    {
        m_hintBtn->setPos(IMGEDT_HIDE_BTN_X_H, IMGEDT_HIDE_BTN_Y_H);
    }
    m_hintBtn->setIsEffect(VFX_TRUE);
    VfxSize iconSize = VfxImageSrc(IMG_ID_IMGEDT_BOTTOMBAR_FOLD).getSize();
    VfxSize haloSize;
    VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
    m_hintBtn->setEffectSize(haloSize);
    
    m_hintBtn->m_signalClicked.connect(this, &VappImgEdtBasePage::onHintBtnClicked);

    if (m_pageState == STATE_PREVIEW)
    {
        m_hintBtn->setHidden(VFX_TRUE);
    }
    else
    {
        m_hintBtn->setHidden(VFX_FALSE);
        m_hintBtn->bringToFront();
    }    
}

void VappImgEdtBasePage::onStateChange(PageState state)
{
    if (STATE_WITH_PANEL == state)
    {
        m_hintBtn->setHidden(VFX_TRUE);
        m_pageState = STATE_PREVIEW;   
    }
    else
    {
        m_hintBtn->setHidden(VFX_FALSE);
        m_hintBtn->bringToFront();
        m_pageState = STATE_EDIT;
    }
}

    
void VappImgEdtBasePage::onHintBtnClicked(VfxObject *obj, VfxId id)
{
    if (STATE_FULL_SCREEN == m_pageState)
    {
        onStateChange(STATE_PREVIEW);       
    }
}

void VappImgEdtBasePage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VFX_UNUSED(obj);
    VFX_UNUSED(id);
}

void VappImgEdtBasePage::onZoomSliderPressed(VcpSlider *sender, VfxFloat val)
{
    VfxS32 index = (VfxS32)(val*50);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_PRESS_BEGIN, index);

    onZoomStart();
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) 
	if(!m_vertMode)
	{
		if (VFX_KEY_CODE_ARROW_RIGHT == m_pressedKey)
	    {
	        m_zoomLarger = VFX_TRUE;
	    }
	    else if (VFX_KEY_CODE_ARROW_LEFT == m_pressedKey)
	    {
	        m_zoomLarger = VFX_FALSE;
	    }
	    else
	    {
	        m_zoomLarger = VFX_FALSE;
	        if ((0 == m_lastZoomIndx) || (index > m_lastZoomIndx))
	        {
	            m_zoomLarger = VFX_TRUE;
	        }
	    }
	}
	else	
#endif
	{
        if (VFX_KEY_CODE_ARROW_UP == m_pressedKey)
        {
            m_zoomLarger = VFX_TRUE;
        }
        else if (VFX_KEY_CODE_ARROW_DOWN == m_pressedKey)
        {
            m_zoomLarger = VFX_FALSE;
        }
        else
        {
            m_zoomLarger = VFX_FALSE;
            if ((0 == m_lastZoomIndx) || (index > m_lastZoomIndx))
            {
                m_zoomLarger = VFX_TRUE;
            }
        }
	}

    
    VfxS32 ret = m_iesHdlr->zoomAniBegin(m_lastZoomIndx, m_zoomLarger);
    m_keyDownRet = ret;
	
    if (0 == ret)
    {
        if (index != m_lastZoomIndx)
        {
            onZoomSliderMove(sender, val);
        }
    }       
    if (0 != ret)
    {
        m_zoomSlider->m_signalThumbPressed.disconnect(this, &VappImgEdtBasePage::onZoomSliderPressed);
        m_zoomSlider->m_signalThumbDrag.disconnect(this, &VappImgEdtBasePage::onZoomSliderMove);
        m_zoomSlider->m_signalThumbReleased.disconnect(this, &VappImgEdtBasePage::onZoomSliderReleased);
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
    else
    {
        m_lastZoomIndx = index;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_PRESS_END, m_zoomLarger, ret);
}

void VappImgEdtBasePage::onZoomSliderMove(VcpSlider *sender, VfxFloat val)
{
    VfxS32 index = val*(50.0f);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_MOVE_BEGIN, index);
    
    //check if move is valid
    if (m_lastZoomIndx == index)
    {
        VAPP_IMGEDT_INFO_TRACE(m_lastZoomIndx);
        return;
    }

    VfxBool bLarger = (index > m_lastZoomIndx) ? VFX_TRUE : VFX_FALSE;
    VfxS32 ret = 0;
    if (m_zoomLarger !=  bLarger)
    {
        m_iesHdlr->zoomAniEnd(VFX_TRUE);
        m_zoomLarger = bLarger;
        ret = m_iesHdlr->zoomAniBegin(m_lastZoomIndx, m_zoomLarger);
        if (ret < 0)
        {
            m_zoomSlider->m_signalThumbPressed.disconnect(this, &VappImgEdtBasePage::onZoomSliderPressed);
            m_zoomSlider->m_signalThumbDrag.disconnect(this, &VappImgEdtBasePage::onZoomSliderMove);
            m_zoomSlider->m_signalThumbReleased.disconnect(this, &VappImgEdtBasePage::onZoomSliderReleased);
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
            return;
        }
    }
    if (0 == ret)
    {
        ret = m_iesHdlr->zoomAniAdjust(index, m_zoomLarger);
    }
    if (0 != ret)
    {
        m_zoomSlider->m_signalThumbPressed.disconnect(this, &VappImgEdtBasePage::onZoomSliderPressed);
        m_zoomSlider->m_signalThumbDrag.disconnect(this, &VappImgEdtBasePage::onZoomSliderMove);
        m_zoomSlider->m_signalThumbReleased.disconnect(this, &VappImgEdtBasePage::onZoomSliderReleased);
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
        m_iesHdlr->zoomAniEnd();
    }
    else
    {
        m_lastZoomIndx = index;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_MOVE_END, m_zoomLarger, ret);
}

void VappImgEdtBasePage::onZoomSliderReleased(VcpSlider *sender, VfxFloat val)
{
    VfxS32 index = (VfxS32)(val*50);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_RELEASE_BEGIN, index);    
    
    if (m_lastZoomIndx != index)
    {
        onZoomSliderMove(sender, val);
    }
    VfxS32 ret = m_iesHdlr->zoomAniEnd();
    if (0 != ret)
    {
        m_zoomSlider->m_signalThumbPressed.disconnect(this, &VappImgEdtBasePage::onZoomSliderPressed);
        m_zoomSlider->m_signalThumbDrag.disconnect(this, &VappImgEdtBasePage::onZoomSliderMove);
        m_zoomSlider->m_signalThumbReleased.disconnect(this, &VappImgEdtBasePage::onZoomSliderReleased);
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
    else
    {
        m_iesHdlr->getScrnArea(&m_bgRange);
        onZoomEnd();
        m_iesHdlr->renderPreview();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_ZOOM_SLIDER_RELEASE_END, m_zoomLarger, ret);
}


void VappImgEdtBasePage::onErrorPopupCallback(VfxObject* sender,VfxId btn_id)
{
    getMainScr()->popPage();
}

void VappImgEdtBasePage::onErrorPopup(VfxResId strId, VfxBool needCallback)
{
    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    if (needCallback)
    {
        popup->m_signalButtonClicked.connect(this, &VappImgEdtBasePage::onErrorPopupCallback);
    }
    VcpImgEdtPopup::popupError(popup, strId);
} 


VfxBool VappImgEdtBasePage::isImageContains(const VfxPenEvent &event)
{
    if (m_bgRange.contains(event.pos))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappImgEdtBasePage::onZoomNextStep(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    if (NULL == m_zoomSlider)
    {
        return;
    }
    else if (m_zoomSlider->getHidden())
    {
        return;
    }
    VfxBool is_up;
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) 
	if(!m_vertMode)
	{
		if (VFX_KEY_CODE_ARROW_RIGHT == m_pressedKey)
	    {
	        is_up = VFX_TRUE;
	    }
	    else if (VFX_KEY_CODE_ARROW_LEFT == m_pressedKey)
	    {
	        is_up = VFX_FALSE;
	    }
	    else
	    {
	        VAPP_IMGEDT_ERROR_TRACE(m_pressedKey);
	        return;
	    }
	}
	else
#endif
	{
        if (VFX_KEY_CODE_ARROW_UP == m_pressedKey)
        {
            is_up = VFX_TRUE;
        }
        else if (VFX_KEY_CODE_ARROW_DOWN == m_pressedKey)
        {
            is_up = VFX_FALSE;
        }
        else
        {
            VAPP_IMGEDT_ERROR_TRACE(m_pressedKey);
            return;
        }
	}
    VfxFloat curVal = m_zoomSlider->getCurrentValue();
    if (((curVal >= 1.0f) && is_up) ||
        ((curVal <= 0.0f) && (!is_up)))
    {
        return;
    }

    VfxFloat newVal;
    if (is_up)
    {
        newVal = curVal + 0.02f;
    }
    else
    {
        newVal = curVal - 0.02f;
    }
    if (newVal > 1.0f) newVal = 1.0f;
    if (newVal < 0.0f) newVal = 0.0f;

    m_zoomSlider->setCurrentValue(newVal);
    onZoomSliderMove(m_zoomSlider, newVal);
}

VfxBool VappImgEdtBasePage::onCenterKeyInput(VfxKeyEvent & event)
{
    if (!m_bottomBar->isValid())
    {
        return VFX_FALSE;
    }

    switch (event.type)
    {
    case VFX_KEY_EVENT_TYPE_DOWN:
        m_bottomBar->setBtnHilit(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_TRUE);
        break;

    case VFX_KEY_EVENT_TYPE_UP:
        m_bottomBar->setBtnHilit(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_FALSE);
        onBottomBtnClicked((VfxObject*)m_bottomBar, VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK);
        break;

    default:
        break;
    }

    return VFX_TRUE;
}


VfxBool VappImgEdtBasePage::onArrowKeyInput(VfxKeyEvent & event)
{
    if (NULL == m_zoomSlider)
    {
        return VFX_FALSE;
    }
    else if (m_zoomSlider->getHidden())
    {
        return VFX_FALSE;
    }    
    
    VfxFloat curVal = m_zoomSlider->getCurrentValue();

    switch (event.type)
    {
    case KEY_EVENT_DOWN:
        if (VFX_KEY_CODE_UNKNOWN == m_pressedKey)
        {
    	#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) 
		    if(!m_vertMode)
	    	{
				if (((VFX_KEY_CODE_ARROW_LEFT == event.keyCode) && (0.0f == curVal)) ||
					((VFX_KEY_CODE_ARROW_RIGHT == event.keyCode) && (1.0f == curVal)))
					{
						return VFX_FALSE;
					}
	    	}
			else				
		#endif
			{
            	if (((VFX_KEY_CODE_ARROW_DOWN == event.keyCode) && (0.0f == curVal)) ||
                	((VFX_KEY_CODE_ARROW_UP == event.keyCode) && (1.0f == curVal)))
            	{
                	return VFX_FALSE;
            	}         
			}
            m_pressedKey = event.keyCode;
            onZoomSliderPressed(m_zoomSlider, curVal);
			
			if(m_keyDownRet==0)
			{
            	onZoomNextStep(NULL);
			}
			m_keyDownRet = 0;
        }
        else
        {
            VFX_ASSERT(0);
        }
        break;

    case KEY_EVENT_LONG_PRESS:
        if (event.keyCode == m_pressedKey)
        {
            startZoomTimer();
        }
        break;
        
    case KEY_EVENT_UP:
        stopZoomTimer();
        if (event.keyCode == m_pressedKey)
        {
            onZoomSliderReleased(m_zoomSlider, curVal);
        }
        else
        {
            VAPP_IMGEDT_ERROR_TRACE(m_pressedKey);
        }        
        m_pressedKey = VFX_KEY_CODE_UNKNOWN;
        break;
        
    default:
        break;
    }
    return VFX_TRUE;
}

void VappImgEdtBasePage::startZoomTimer()
{
    stopZoomTimer();
    VFX_OBJ_CREATE(m_zoomTimer, VfxTimer, this);
    m_zoomTimer->setDuration(150);
    m_zoomTimer->m_signalTick.connect(this, &VappImgEdtBasePage::onZoomNextStep);
    m_zoomTimer->start();
}

void VappImgEdtBasePage::stopZoomTimer()
{
    if ((NULL != m_zoomTimer) && m_zoomTimer->isValid())
    {
        m_zoomTimer->stop();
        m_zoomTimer = NULL;
    }
}

VcpImgEdtDialPanel::VcpImgEdtDialPanel():
m_dialBtn(NULL)
{
}

void VcpImgEdtDialPanel::onInit()
{
    m_mode = ROTATE_MODE_NONE;

    VfxControl::onInit();

    VfxImageSrc imgSrc = VfxImageSrc(IMG_ID_IMGEDT_ROTATE_BG);
    setImgContent(imgSrc);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
     
    VFX_OBJ_CREATE(m_dialBtn, VfxFrame, this);
    m_dialBtn->setAnchor(0.5f, 0.5f);
    m_dialBtn->setBounds(0, 0, IMGEDT_ROTATE_BTN_SIZE, IMGEDT_ROTATE_BTN_SIZE);
    m_dialBtn->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALL_SMALL));

    VFX_OBJ_CREATE(m_btnHL, VfxFrame, this);
    m_btnHL->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BUTTON_HALO));
    m_btnHL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_btnHL->setAnchor(0.5, 0.5);
    VfxSize iconSize = VfxImageSrc(IMG_ID_IMGEDT_BALL_SMALL).getSize();
    VfxSize haloSize;
    VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
    m_btnHL->setSize(haloSize.width, haloSize.height);
    m_btnHL->setHidden(VFX_TRUE);
}

void VcpImgEdtDialPanel::setInitInfo(VfxSize bgSize, VfxS32 radius)
{
    setBounds(0, 0, bgSize.width, bgSize.height);
    m_stub = VfxPoint(bgSize.width>>1, bgSize.height>>1);
    m_radius = radius;
    VfxPoint btnPoint = VfxPoint(bgSize.width>>1, (bgSize.height/2)-m_radius);
    m_dialBtn->setPos(btnPoint);
    m_btnHL->setPos(btnPoint);
    m_sin = -1.0f;
    m_cos = 0.0f;
    m_radian = 0.0f;
}

void VcpImgEdtDialPanel::setDisabled(VfxBool is_disabled)
{
    m_isDisabled = is_disabled;
}

void VcpImgEdtDialPanel::resetDialBtn()
{
    VfxPoint p = getPosByRadian(m_radian);
    m_dialBtn->setPos(p);
    m_btnHL->setPos(p);
}
 
VfxBool VcpImgEdtDialPanel::onPenInput(VfxPenEvent &event)
{
    if (m_isDisabled)
    {
        return getParentControl()->penInput(event); 
    }

    VfxBool bRet = VFX_FALSE;
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        if (m_dialBtn->getRect().contains(event.pos))
        {
            m_btnHL->setHidden(VFX_FALSE);
            m_lastPos = event.pos;
            m_signalDialMove.emit(m_radian, event.type);
            m_mode = ROTATE_MODE_FOLLOW;
            bRet = VFX_TRUE;
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_UP:
        m_btnHL->setHidden(VFX_TRUE);
        m_mode = ROTATE_MODE_NONE;
        if (m_radian < (VfxFloat)VFX_DEG_TO_RAD(45) || 
            m_radian > (VfxFloat)VFX_DEG_TO_RAD(315))
        {
            m_radian = VFX_DEG_TO_RAD(0);
            m_signalDialMove.emit(m_radian, event.type);
            resetDialBtn();
        }
        else if (m_radian > (VfxFloat)VFX_DEG_TO_RAD(45) &&
                 m_radian < (VfxFloat)VFX_DEG_TO_RAD(135))
        {
            m_radian = VFX_DEG_TO_RAD(90);
            m_signalDialMove.emit(m_radian, event.type);
            resetDialBtn();
        }
        else if (m_radian > (VfxFloat)VFX_DEG_TO_RAD(135) &&
                 m_radian < (VfxFloat)VFX_DEG_TO_RAD(225))
        {
            m_radian = VFX_DEG_TO_RAD(180);
            m_signalDialMove.emit(m_radian, event.type);
            resetDialBtn();
        }
        else if (m_radian > (VfxFloat)VFX_DEG_TO_RAD(225) &&
                 m_radian < (VfxFloat)VFX_DEG_TO_RAD(315))
        {
            m_radian = VFX_DEG_TO_RAD(270);
            m_signalDialMove.emit(m_radian, event.type);
            resetDialBtn();
        }
        bRet = VFX_TRUE;
        break;
    case VFX_PEN_EVENT_TYPE_MOVE:
        if ((abs(event.pos.x - m_lastPos.x) > IMGEDT_DOOLE_DIAL_MIN_RADIUS) ||
            (abs(event.pos.y - m_lastPos.y) > IMGEDT_DOOLE_DIAL_MIN_RADIUS))
        {
            m_lastPos = event.pos;
            VfxPoint p = getPosByPoint(event.pos);
            m_dialBtn->setPos(p);
            m_btnHL->setPos(p);
            m_signalDialMove.emit(m_radian, event.type);
        }            
        bRet = VFX_TRUE;
        break;
    }
    return bRet;
}

void VcpImgEdtDialPanel::getAngleInfo(VfxPoint p, VfxFloat *sin, VfxFloat *cos, VfxFloat *radian)
{
    VfxSize s;
    s.width = p.x - m_stub.x;
    s.height = p.y - m_stub.y;
    VfxFloat r = (VfxFloat)vfxSqrt((s.width*s.width) + (s.height*s.height));
    *sin = (VfxFloat)((VfxFloat)s.height/r);
    *cos = (VfxFloat)((VfxFloat)s.width/r);
    *radian = (VfxFloat)asin(*sin);
    if (s.width < 0)
    {
        *radian = 3.1415926f - *radian;
    }

    *radian += (VfxFloat)3.1415926f;
    *radian -= (VfxFloat)VFX_DEG_TO_RAD(90);
}

VfxPoint VcpImgEdtDialPanel::getPosByPoint(VfxPoint pos)
{
    VfxPoint newP;
    
    getAngleInfo(pos, &m_sin, &m_cos, &m_radian);
    
    newP.x = m_radius * m_cos + m_stub.x;
    newP.y = m_radius * m_sin + m_stub.y;

    return newP;
}
  
VfxPoint VcpImgEdtDialPanel::getPosByRadian(VfxFloat radian)
{
    VfxPoint p;
    radian -= VFX_DEG_TO_RAD(90);
    p.x = (VfxS32)(vfxCos(radian)*m_radius) + m_stub.x;
    p.y = (VfxS32)(vfxSin(radian)*m_radius) + m_stub.y;
    return p;
}


VFX_IMPLEMENT_CLASS("VappImgEdtRotatePage", VappImgEdtRotatePage, VappImgEdtBasePage);

void VappImgEdtRotatePage::enterRotatePage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtRotatePage, parent);
}

VappImgEdtRotatePage::VappImgEdtRotatePage():
m_avatarFrame(NULL),
m_avatarPreview(NULL),
m_gdiHdl(NULL)
{
}

void VappImgEdtRotatePage::onInit()
{
    VappImgEdtBasePage::onInit();

    VfxRect imgRect;
    m_iesHdlr->getScrnArea(&imgRect);
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VfxU8* buf = app->getAvatarLayerMem();
    VFX_ASSERT(NULL != buf);

    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16,
                                             0,
                                             0,
                                             imgRect.getWidth(),
                                             imgRect.getHeight(),
                                             &m_gdiHdl,
                                             (U8*)buf,
                                             imgRect.getWidth() * imgRect.getHeight() * 2);
    gdi_layer_push_and_set_active((gdi_handle) m_gdiHdl);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();

    //render preview after entered for better performance
    VfxImageBuffer imgBuf;
    imgBuf.ptr = buf;
    imgBuf.pitchBytes = imgRect.getWidth() * 2;
    imgBuf.width = imgRect.getWidth();
    imgBuf.height = imgRect.getHeight();
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    
    VFX_OBJ_CREATE(m_avatarFrame, VfxFrame, this);
    m_avatarFrame->setImgContent(VfxImageSrc(imgBuf));
    m_avatarFrame->setSize(imgRect.getWidth(), imgRect.getHeight());
    m_avatarFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_avatarFrame->setAnchor(0.5f, 0.5f);
    m_avatarFrame->setPos(imgRect.getMidX(),imgRect.getMidY());
    m_avatarFrame->setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
    m_avatarFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_dialPanel, VcpImgEdtDialPanel, this);
    m_dialPanel->setInitInfo(m_scrnSize, IMGEDT_DIAL_PANEL_RADIUS);
    m_dialPanel->setPos(0, 0);
    m_dialPanel->setDisabled(VFX_FALSE);
    m_dialPanel->m_signalDialMove.connect(this, &VappImgEdtRotatePage::onRotateImage);

    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtRotatePage::onBottomBtnClicked);
    m_bottomBar->show();

    //prepare first entry view
    m_imageView = m_iesHdlr->getPreviewInternal();
    VFX_ASSERT(NULL != m_imageView);
}

void VappImgEdtRotatePage::onDeinit()
{
    m_iesHdlr->rotateEnd(VFX_FALSE);
    m_imageView->setHidden(VFX_FALSE);
    m_avatarFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CLOSE(m_avatarFrame);
    m_avatarFrame = NULL;
    m_iesHdlr->destroyPreview(m_avatarPreview);
    m_avatarPreview = NULL;
    
    gdi_layer_free(m_gdiHdl);
    m_gdiHdl = NULL;
    
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtRotatePage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
}

void VappImgEdtRotatePage::onEntered()
{
    VappImgEdtBasePage::onEntered();

    if (VappImgEdtIesHdlr::EDIT_TYPE_ROTATE != m_iesHdlr->getCurrState())
    {
        if(NULL == m_avatarPreview)
        {
            VfxRect imgRect;
            m_iesHdlr->getScrnArea(&imgRect);
            VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
            VfxU8* buf = app->getAvatarLayerMem();
            m_iesHdlr->createPreview(buf, &m_avatarPreview, imgRect.size);
            m_iesHdlr->renderPreview(m_avatarPreview);
            gd_replace_src_key_16(
                buf,
                imgRect.getWidth(),
                0,
                0,
                0,
                0,
                imgRect.getWidth() - 1,
                imgRect.getHeight() - 1,
                GDI_COLOR_TRANSPARENT,
                imgRect.getWidth(),
                imgRect.getHeight());

            VfxS32 ret = m_iesHdlr->rotateBegin();
            if (0 == ret)
            {
                prepareRotate();
                m_avatarFrame->setHidden(VFX_FALSE);
                m_imageView->setHidden(VFX_TRUE);
            }
            else
            {
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }   
        }
    }
}

void VappImgEdtRotatePage::onExit(VfxBool isBackward)
{
    if (isBackward)
    {
		if(!(getMainScr()->getIsSnapshotDrawing()))  //if small screen redraw, don't hidden
		{
            m_imageView->setHidden(VFX_FALSE);
            m_avatarFrame->setHidden(VFX_TRUE);
        }
    }
    VappImgEdtBasePage::onExit(isBackward);
}

void VappImgEdtRotatePage::onBack()
{
    m_iesHdlr->rotateEnd(VFX_FALSE);
    VfxPage::onBack();
}

void VappImgEdtRotatePage::onRotateImage(VfxFloat &radian, VfxPenEventTypeEnum &type)
{
    VfxTransform tempTransform;        
    tempTransform.data.affine.rz = radian;
    m_avatarFrame->setTransform(tempTransform);

    VfxSize new_size;
    VfxFloat rate = 1.0f;
    
    if (radian >= VFX_DEG_TO_RAD(0) && radian < VFX_DEG_TO_RAD(90))
    {
        rate = ((VFX_DEG_TO_RAD(90)) - radian)/(VFX_DEG_TO_RAD(90));
    }
    else if (radian >= VFX_DEG_TO_RAD(90) && radian < VFX_DEG_TO_RAD(180))
    {
        rate = (radian - VFX_DEG_TO_RAD(90))/(VFX_DEG_TO_RAD(90));
    }
    else if (radian >= VFX_DEG_TO_RAD(180) && radian < VFX_DEG_TO_RAD(270))
    {
        rate = (VFX_DEG_TO_RAD(270) - radian)/(VFX_DEG_TO_RAD(90));
    }
    else if (radian >= VFX_DEG_TO_RAD(270) && radian < VFX_DEG_TO_RAD(360))
    {
        rate = (radian - VFX_DEG_TO_RAD(270))/(VFX_DEG_TO_RAD(90));
    }

    switch(m_resizeTrend)
    {
    case RESIZE_SMALLER:
        new_size.width= (m_maxSize.width - m_minSize.width) * rate + m_minSize.width;
        new_size.height = (m_maxSize.height - m_minSize.height) * rate + m_minSize.height;
        m_avatarFrame->setSize(new_size.width, new_size.height);
        break;
    
    case RESIZE_LARGER:
        new_size.width= m_maxSize.width - (m_maxSize.width - m_minSize.width) * rate ;
        new_size.height = m_maxSize.height - (m_maxSize.height - m_minSize.height) * rate ;
        m_avatarFrame->setSize(new_size.width, new_size.height);
        break;

    case RESIZE_NOCHANGE:
    default:
        break;
    }

    if ((VFX_PEN_EVENT_TYPE_UP == type) || (VFX_PEN_EVENT_TYPE_DOWN == type))
    {        
        if (VFX_DEG_TO_RAD(90) == radian)
        {
            m_iesHdlr->rotateAjust(SRV_IES_ROT_90, VFX_FALSE);
        }
        else if(VFX_DEG_TO_RAD(180) == radian)
        {
            m_iesHdlr->rotateAjust(SRV_IES_ROT_180, VFX_FALSE);
        }
        else if (VFX_DEG_TO_RAD(270) == radian)
        {
            m_iesHdlr->rotateAjust(SRV_IES_ROT_270, VFX_FALSE);
        }
         else if (VFX_DEG_TO_RAD(0) == radian)
        {
            m_iesHdlr->rotateAjust(SRV_IES_ROT_0, VFX_FALSE);
        }
    }    
}

void VappImgEdtRotatePage::prepareRotate()
{
    VfxRect org_rect, rotate_rect;
    m_iesHdlr->getScrnArea(&org_rect);
    m_iesHdlr->rotateAjust(SRV_IES_ROT_90, VFX_FALSE);
    m_iesHdlr->getScrnArea(&rotate_rect);
    m_iesHdlr->rotateAjust(SRV_IES_ROT_0, VFX_FALSE);

    if ((org_rect.getWidth() == rotate_rect.getHeight()) &&
        (org_rect.getHeight() == rotate_rect.getWidth()))
    {
        m_resizeTrend = RESIZE_NOCHANGE;
    }
    else if ((org_rect.getWidth() >= rotate_rect.getHeight()) &&
             (org_rect.getHeight() >= rotate_rect.getWidth()))
    {
        m_maxSize = VfxSize(org_rect.size);
        m_minSize = VfxSize(rotate_rect.getHeight(), rotate_rect.getWidth());
        m_resizeTrend = RESIZE_SMALLER;
    }
    else if ((org_rect.getWidth() <= rotate_rect.getHeight()) &&
             (org_rect.getHeight() <= rotate_rect.getWidth()))
    {
        m_maxSize = VfxSize(rotate_rect.getHeight(), rotate_rect.getWidth());
        m_minSize = VfxSize(org_rect.size);
        m_resizeTrend = RESIZE_LARGER;
    }
    else
    {
        VAPP_IMGEDT_ERROR_TRACE(RESIZE_NOCHANGE);
        m_resizeTrend = RESIZE_NOCHANGE;
    }
}

void VappImgEdtRotatePage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        m_iesHdlr->rotateEnd(VFX_TRUE);
        getMainScr()->popPage();
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        m_iesHdlr->rotateEnd(VFX_FALSE);
        getMainScr()->popPage();
        break;
        
    default:
        break;
    }
}

VFX_IMPLEMENT_CLASS("VappImgEdtClipPage", VappImgEdtClipPage, VfxPage);

VappImgEdtClipPage::VappImgEdtClipPage():
        m_ratioMode(CLIP_RATIO_FREE),
        m_isZoom(VFX_TRUE),
        m_isRatioSelected(VFX_TRUE)
{
}

void VappImgEdtClipPage::onInit()
{
    VappImgEdtBasePage::onInit();

    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappImgEdtBaseScr);
    if (m_vertMode)
    {
        m_scrnSize = VfxSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }
    else
    {
        m_scrnSize = VfxSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }
    
    
    VFX_OBJ_CREATE(m_clipWd, VcpImgEdtClipWindow, this);
    m_clipWd->setBounds(0, 0, m_scrnSize.width, m_scrnSize.height);
    m_clipWd->setFreeze(VFX_FALSE);

    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setTranslucent(VFX_TRUE);
    if (m_isRatioSelected)
    {
        m_bottomBar->addItem(BOTTOM_BTN_SELECT_RATIO, IMG_ID_IMGEDT_BOTTOMBAR_CLIP_LIST);
    }    
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtClipPage::onBottomBtnClicked);
    m_bottomBar->show();

    VfxRect rect = m_bottomBar->getRect();
    m_clipWd->setDetectRect(rect);
    m_clipWd->m_signalDetectAreaTouched.connect(this, &VappImgEdtClipPage::onBottomTouched);

    if (m_isZoom)
    {
        createZoomSlider(VFX_OBJ_DYNAMIC_CAST(m_clipWd,VfxObject));
        m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    }
    
    createHindBtn(VFX_OBJ_DYNAMIC_CAST(m_clipWd,VfxObject));    
}

void VappImgEdtClipPage::enterClipPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtClipPage, parent);
}

void VappImgEdtClipPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);

    VfxRect imgRect;
    m_iesHdlr->getScrnArea(&imgRect);
    m_clipWd->setImgRect(imgRect);
    m_clipWd->show();
}

void VappImgEdtClipPage::onExit(VfxBool isBackward)
{
    VappImgEdtBasePage::onExit(isBackward);
}

void VappImgEdtClipPage::onZoomEnd()
{
    m_clipWd->setImgRect(m_bgRange);
}

void VappImgEdtClipPage::setIsZoom(VfxBool isZoom)
{
    m_isZoom = isZoom;
}

void VappImgEdtClipPage::setRatioFixed(VfxBool isFixed)
{
    m_clipWd->setRatioFixed(isFixed);
}

void VappImgEdtClipPage::setRatio(VfxS32 ratio_w, VfxS32 ratio_h)
{
    m_clipWd->setRatio(ratio_w, ratio_h);
}

void VappImgEdtClipPage::setRatioSelected(VfxBool is_selected)
{
    m_isRatioSelected = is_selected;
}

void VappImgEdtClipPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{    
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
    {
        VfxS32 res = onClip(VFX_TRUE);
        if (SRV_IES_OK == res)
        {
            //ClipCUI do not need render preview, so only do renderPreview at here
            res = m_iesHdlr->renderPreview();
            if (SRV_IES_OK == res)
            {
                getMainScr()->popPage();
                break;
            }
        }
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)res);
        onErrorPopup(strId);
    }
        break;
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        getMainScr()->popPage();
        break;
    case BOTTOM_BTN_SELECT_RATIO:
        showRatioSelPopup();
        break;

    default:
        break;
    }
}

VfxS32 VappImgEdtClipPage::onClip(VfxBool needUpdate)
{
    VfxRect imgRect, scrnRect, clipRect;
    m_iesHdlr->getCurrImageRect(&imgRect);
    m_iesHdlr->getScrnArea(&scrnRect);
    m_clipWd->getClipRect(&clipRect);

    VfxFloat factor = (VfxFloat)((VfxFloat)imgRect.getWidth() / (VfxFloat)scrnRect.size.width);

    clipRect.size.width = clipRect.size.width * factor;
    clipRect.size.height = clipRect.size.height * factor;
    clipRect.origin.x -= scrnRect.origin.x;
    clipRect.origin.y -= scrnRect.origin.y;
    clipRect.origin.x = clipRect.origin.x * factor;
    clipRect.origin.y = clipRect.origin.y * factor;
    if (imgRect.origin.x > 0)
    {
        clipRect.origin.x += imgRect.origin.x;
    }
    if (imgRect.origin.y > 0)
    {
        clipRect.origin.y += imgRect.origin.y;
    }
    VfxS32 ret = m_iesHdlr->doClip(clipRect, needUpdate);
    if (ret < 0)
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
    return ret;
}

void VappImgEdtClipPage::onBottomTouched()
{
    if (STATE_WITH_PANEL == m_pageState)
    {
        onStateChange(STATE_FULL_SCREEN);
    }
}

void VappImgEdtClipPage::onDragImage(VfxSize &drag)
{
    m_iesHdlr->setDragSmart(drag);
}

void VappImgEdtClipPage::onRatioSelectionChanged(VfxObject* sender, VfxU32 index)
{
    ClipFrameRatio newRatio = (ClipFrameRatio)m_ratioPopup->getFirstSeletedId();
    VfxSize imgSize;
    m_iesHdlr->getImageSize(imgSize);    
    if (m_ratioMode == newRatio)
    {
        return;
    }
    if (newRatio == CLIP_RATIO_FREE)
    {
        m_clipWd->setRatioFixed(VFX_FALSE);
    }
    else
    {
        switch (newRatio)
        {
        case CLIP_RATIO_ORIGINAL:
            m_clipWd->changeRatio(imgSize.width, imgSize.height, VFX_TRUE);
            break;

        case CLIP_RATIO_SCREEN:
            m_clipWd->changeRatio(m_scrnSize.width, m_scrnSize.height, VFX_TRUE);
            break;

        case CLIP_RATIO_1_1:
            m_clipWd->changeRatio(1, 1, VFX_TRUE);
            break;

        case CLIP_RATIO_3_4:
            if (m_vertMode)
            {
                m_clipWd->changeRatio(3, 4, VFX_TRUE);
            }
            else
            {
                m_clipWd->changeRatio(4, 3, VFX_TRUE);
            }            
            break;

        case CLIP_RATIO_9_16:
            if (m_vertMode)
            {
                m_clipWd->changeRatio(9, 16, VFX_TRUE);
            }
            else
            {
                m_clipWd->changeRatio(16, 9, VFX_TRUE);
            }            
            break;
        default:
            VFX_ASSERT(0);
        }
    } 
    m_ratioMode = newRatio;
    m_ratioPopup->leave(VFX_TRUE);
}


void VappImgEdtClipPage::showRatioSelPopup()
{
    VFX_OBJ_CREATE(m_ratioPopup, VcpSelectPopup, this);
    m_ratioPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_CROP_RATIO));
    m_ratioPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    for (VfxS32 i = CLIP_RATIO_FREE; i < CLIP_RATIO_TOTAL; i++)
    {
        VfxResId id;
        if (m_vertMode)
        {
            id = g_imgedt_clip_ratio_vert_string_list[i];
        }
        else
        {
            id = g_imgedt_clip_ratio_horz_string_list[i];
        }
        if (m_ratioMode == i)
        {
            m_ratioPopup->addItem(i, VFX_WSTR_RES(id), VFX_TRUE);
        }
        else
        {
            m_ratioPopup->addItem(i, VFX_WSTR_RES(id), VFX_FALSE);
        }
    }
    m_ratioPopup->setAutoDestory(VFX_TRUE);
    m_ratioPopup->m_signalButtonClicked.connect(this, &VappImgEdtClipPage::onRatioSelectionChanged);
    m_ratioPopup->show(VFX_TRUE);
}

void VappImgEdtClipPage::onStateChange(PageState state)
{
    switch(state)
    {
    case STATE_FULL_SCREEN:
        m_bottomBar->setHidden(VFX_TRUE);
        m_clipWd->m_signalDetectAreaTouched.disconnect(this, &VappImgEdtClipPage::onBottomTouched);      
        break;

    case STATE_WITH_PANEL:
        m_bottomBar->setHidden(VFX_FALSE);
        m_clipWd->m_signalDetectAreaTouched.connect(this, &VappImgEdtClipPage::onBottomTouched);
        break;

    default:
        VFX_ASSERT(state);
    }

    VappImgEdtBasePage::onStateChange(state);
}

VcpImgEdtAdjustBar::VcpImgEdtAdjustBar():
m_slider(NULL),
m_text(NULL),
m_id(0),
m_sliderBg(0),
m_lastAdjustTime(0)
{
}

void VcpImgEdtAdjustBar::onInit()
{
    VfxFrame::onInit();

    setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);
}

void VcpImgEdtAdjustBar::setValue(VfxS32 def, VfxS32 min, VfxS32 max)
{       
    m_slider->setMaxValue(max);
    m_slider->setMinValue(min);
    m_slider->setCurrentValue(def);
}

void VcpImgEdtAdjustBar::setId(VfxS32 id)
{
    m_id = id;
}

void VcpImgEdtAdjustBar::setDescription(const VfxWString& str)
{
    m_text->setString(str);
}

void VcpImgEdtAdjustBar::setSliderBgImage(VfxResId id)
{
    m_sliderBg = id;
}

void VcpImgEdtAdjustBar::setSliderPos(VfxPoint pos)
{
    m_sliderPos = pos;
}
void VcpImgEdtAdjustBar::setTextPos(VfxPoint pos)
{
    m_textPos = pos;
}

void VcpImgEdtAdjustBar::setSliderLen(VfxS32 len)
{
    m_sliderLen = len;
}

void VcpImgEdtAdjustBar::show()
{
    //Slider   
    m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_slider->setLength(m_sliderLen);
    m_slider->setPos(m_sliderPos);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    if (0 != m_sliderBg)
    {
        VfxImageSrc img(m_sliderBg);
        m_slider->setImageFullTrack(img);
    }
    m_slider->m_signalThumbPressed.connect(this, &VcpImgEdtAdjustBar::onValueChangedBegin);
    m_slider->m_signalThumbDrag.connect(this, &VcpImgEdtAdjustBar::onValueChanged);
    m_slider->m_signalThumbReleased.connect(this, &VcpImgEdtAdjustBar::onValueChangedEnd);
    
    //text
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(IMGEDT_ADJUST_BAR_FONT_SIZE);
    m_text->setFont(fontDesc);
    m_text->setColor(VfxColor(255,255,255,255));
    m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_text->setPos(m_textPos);
}

void VcpImgEdtAdjustBar::onValueChangedBegin(VcpSlider *obj, VfxFloat value)
{
    kal_get_time(&m_lastAdjustTime);
    m_signalValueChanged.emit(m_id, value);
}

void VcpImgEdtAdjustBar::onValueChanged(VcpSlider *obj, VfxFloat value)
{
    VfxU32 tempStamp;
    kal_get_time(&tempStamp);
    if (tempStamp - m_lastAdjustTime >= IMGEDT_ADJUST_MIN_TICKS)
    {
        VAPP_IMGEDT_INFO_TRACE(tempStamp);
        m_lastAdjustTime = tempStamp;
        m_signalValueChanged.emit(m_id, value); 
    }
    else
    {
        VAPP_IMGEDT_INFO_TRACE(tempStamp);
    }
}

void VcpImgEdtAdjustBar::onValueChangedEnd(VcpSlider *obj, VfxFloat value)
{
    m_lastAdjustTime = 0;
    m_signalValueChanged.emit(m_id, value);
}


VFX_IMPLEMENT_CLASS("VappImgEdtAdjustPage", VappImgEdtAdjustPage, VappImgEdtBasePage);

void VappImgEdtAdjustPage::enterAdjustPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtAdjustPage, parent);
}

VappImgEdtAdjustPage::VappImgEdtAdjustPage():
m_BscActived(VFX_TRUE),
m_adjustPanelHue(NULL),
m_adjustPanelBcs(NULL)
{
    for (VfxS32 i = VappImgEdtIesHdlr::ADJUST_TYPE_BRIGHTNESS; 
         i < VappImgEdtIesHdlr::ADJUST_TOTAL; i++)
    {
        m_adjustItem[i] = NULL;
    }
}


void VappImgEdtAdjustPage::onInit()
{
    VappImgEdtBasePage::onInit();

    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_BCS, 
                         IMG_ID_IMGEDT_BOTTOMBAR_ADJUST_BCS, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L1,
                         VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_HUE, 
                         IMG_ID_IMGEDT_BOTTOMBAR_ADJUST_HUE,
                         VcpImgEdtBottomBar::BOTTOM_BTN_L1,
                         VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtAdjustPage::onBottomBtnClicked);
    m_bottomBar->show();
    m_bottomBar->setDownState(VFX_TRUE, BOTTOM_BTN_SHOW_BCS);

    VfxS32  bgHeight, sliderLen;
    VfxPoint sliderPos, textPos;
    if (m_vertMode)
    {
        bgHeight = IMGEDT_ADJUST_BAR_HEIGHT_V;
        sliderPos = VfxPoint(IMGEDT_ADJUST_BAR_SLIDER_X_V, IMGEDT_ADJUST_BAR_SLIDER_Y_V);
        textPos = VfxPoint(IMGEDT_ADJUST_BAR_FONT_X_V, IMGEDT_ADJUST_BAR_FONT_Y_V);
        sliderLen = IMGEDT_ADJUST_BAR_SLIDER_LEN_V;
    }
    else
    {
        bgHeight = IMGEDT_ADJUST_BAR_HEIGHT_H;
        sliderPos = VfxPoint(IMGEDT_ADJUST_BAR_SLIDER_X_H, IMGEDT_ADJUST_BAR_SLIDER_Y_H);
        textPos = VfxPoint(IMGEDT_ADJUST_BAR_FONT_X_H, IMGEDT_ADJUST_BAR_FONT_Y_H);
        sliderLen = IMGEDT_ADJUST_BAR_SLIDER_LEN_H;
    }

    //BCS panel
    VFX_OBJ_CREATE(m_adjustPanelBcs, VfxFrame, this);
    m_adjustPanelBcs->setBgColor(VFX_COLOR_TRANSPARENT);
    m_adjustPanelBcs->setOpacity(1.0f);
    m_adjustPanelBcs->setPos(0, m_scrnSize.height - IMGEDT_BOTTOM_BAR_HEIGHT - (bgHeight * 3) + 1);
    m_adjustPanelBcs->setBounds(0 ,0, m_scrnSize.width, bgHeight * 3);
    
    VfxS32 def, min, max;
    VfxWString str;
    VfxS32 curHeight = 0;
    VfxS32 index = VappImgEdtIesHdlr::ADJUST_TYPE_BRIGHTNESS;
    for (; index <= VappImgEdtIesHdlr::ADJUST_TYPE_SATURATION; index++)
    {
        m_iesHdlr->getAdjustInitValue(index, &def, &min, &max);
        VFX_OBJ_CREATE(m_adjustItem[index], VcpImgEdtAdjustBar, m_adjustPanelBcs);
        m_adjustItem[index]->setBounds(0, 0, m_scrnSize.width, bgHeight - 1);
        m_adjustItem[index]->setPos(0, curHeight);
        str = VFX_WSTR_RES(m_iesHdlr->getAjdustStrId(index));
        m_adjustItem[index]->setDescription(str);
        m_adjustItem[index]->setValue(def, min, max);
        m_adjustItem[index]->setId(index);
        m_adjustItem[index]->setSliderPos(sliderPos);
        m_adjustItem[index]->setTextPos(textPos);
        m_adjustItem[index]->setSliderLen(sliderLen);
        m_adjustItem[index]->m_signalValueChanged.connect(this, &VappImgEdtAdjustPage::onValueChanged);
        m_adjustItem[index]->show();

        curHeight += bgHeight;
    }
    
    //Hue panel
    VFX_OBJ_CREATE(m_adjustPanelHue, VfxFrame, this);
    m_adjustPanelHue->setBgColor(VFX_COLOR_TRANSPARENT);
    m_adjustPanelHue->setOpacity(1.0f);
    m_adjustPanelHue->setBounds(0 ,0, m_scrnSize.width, bgHeight);
    m_adjustPanelHue->setPos(0, m_scrnSize.height - IMGEDT_BOTTOM_BAR_HEIGHT - bgHeight + 1);

    index = VappImgEdtIesHdlr::ADJUST_TYPE_HUE;
    m_iesHdlr->getAdjustInitValue(index, &def, &min, &max);
    VFX_OBJ_CREATE(m_adjustItem[index], VcpImgEdtAdjustBar, m_adjustPanelHue);
    m_adjustItem[index]->setBounds(0, 0, m_scrnSize.width, bgHeight - 1);
    m_adjustItem[index]->setPos(0, 0);
    m_adjustItem[index]->setSliderBgImage(IMG_ID_IMGEDT_HUE_BG);
    str = VFX_WSTR_RES(m_iesHdlr->getAjdustStrId(index));
    m_adjustItem[index]->setDescription(str);    
    m_adjustItem[index]->setValue(def, min, max);
    m_adjustItem[index]->setId(index);
    m_adjustItem[index]->setSliderPos(sliderPos);
    m_adjustItem[index]->setTextPos(textPos);
    m_adjustItem[index]->setSliderLen(sliderLen);
    m_adjustItem[index]->m_signalValueChanged.connect(this, &VappImgEdtAdjustPage::onValueChanged);
    m_adjustItem[index]->show();
    
    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject));
    showAdjustPanel(VFX_FALSE);
    VfxS32 ret = m_iesHdlr->adjustBegin();
    if (ret < 0)
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
}

void VappImgEdtAdjustPage::onDeinit()
{
    m_iesHdlr->adjustEnd(VFX_FALSE);
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtAdjustPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
}

void VappImgEdtAdjustPage::onExit(VfxBool isBackward)
{
    VappImgEdtBasePage::onExit(isBackward);    
}

void VappImgEdtAdjustPage::onBack()
{
    m_iesHdlr->adjustEnd(VFX_FALSE);
    VfxPage::onBack();
}

void VappImgEdtAdjustPage::onValueChanged(VfxS32 id,VfxFloat value)
{
    switch (id)
    {
    case VappImgEdtIesHdlr::ADJUST_TYPE_BRIGHTNESS:
    case VappImgEdtIesHdlr::ADJUST_TYPE_CONTRAST:
    case VappImgEdtIesHdlr::ADJUST_TYPE_SATURATION:
    case VappImgEdtIesHdlr::ADJUST_TYPE_HUE:
        {
            VfxS32 ret = m_iesHdlr->adjustSet(id, (S32)value);
            if (ret < 0)
            {
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }
        }
        break;
        
    default:
        VFX_ASSERT(0);
    }    
}

void VappImgEdtAdjustPage::onBottomBtnClicked(VfxObject* obj, VfxId id)
{
    VfxS32 ret = 0;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        ret = m_iesHdlr->adjustEnd(VFX_TRUE);
        if (0 == ret)
        {
            getMainScr()->popPage();
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        ret = m_iesHdlr->adjustEnd(VFX_FALSE);
        if (0 == ret)
        {
            getMainScr()->popPage();
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }
        break;

    case BOTTOM_BTN_SHOW_BCS: 
        showAdjustPanel(VFX_FALSE);  
        m_BscActived = VFX_TRUE;
        m_bottomBar->clearDownState(VFX_TRUE, BOTTOM_BTN_SHOW_BCS);
        break;

    case BOTTOM_BTN_SHOW_HUE:
        showAdjustPanel(VFX_TRUE);
        m_BscActived = VFX_FALSE;
        m_bottomBar->clearDownState(VFX_TRUE, BOTTOM_BTN_SHOW_HUE);
        break;

    default:
        break;
    }
}

void VappImgEdtAdjustPage::showAdjustPanel(VfxBool is_hue)
{
    if (is_hue)
    {
        m_adjustPanelHue->setHidden(VFX_FALSE);
        m_adjustPanelBcs->setHidden(VFX_TRUE);
    }
    else
    {
        m_adjustPanelHue->setHidden(VFX_TRUE);
        m_adjustPanelBcs->setHidden(VFX_FALSE);
    }    
}


VFX_IMPLEMENT_CLASS("VappImgEdtEffectPage", VappImgEdtEffectPage, VappImgEdtBasePage);

void VappImgEdtEffectPage::enterEffectPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtEffectPage, parent);
}

VappImgEdtEffectPage::VappImgEdtEffectPage():m_focusIndex(0)
{
}

void VappImgEdtEffectPage::onInit()
{
    VappImgEdtBasePage::onInit();
    
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    if (m_vertMode)
    {
        m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
        m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_ADDEFFECT_BAR_HEIGHT + IMGEDT_BOTTOM_BAR_HEIGHT));
    }
    else
    {
        m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
        m_bottomBar->setBgSize(VfxSize(m_scrnSize.width - IMGEDT_ADDEFFECT_BAR_HEIGHT, IMGEDT_BOTTOM_BAR_HEIGHT));    
    }
    
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtEffectPage::onBottomBtnClicked);
    m_bottomBar->show();


    //bottom scrollble
    VfxFrame *bg;
    if (m_vertMode)
    {
        VFX_OBJ_CREATE(bg, VfxFrame, m_bottomBar);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        bg->setPos(0, IMGEDT_BOTTOM_BAR_HEIGHT);
        bg->setSize(m_scrnSize.width, IMGEDT_ADDEFFECT_BAR_HEIGHT);
        
        VFX_OBJ_CREATE_EX(m_effectPanel, VcpImgEdtEffectPanel, m_bottomBar, (m_vertMode));
        m_effectPanel->setPos(VfxPoint(0, IMGEDT_BOTTOM_BAR_HEIGHT));
        m_effectPanel->setBounds(VfxRect(0, 0, m_scrnSize.width, IMGEDT_ADDEFFECT_BAR_HEIGHT));
    }
    else
    {
        VFX_OBJ_CREATE(bg, VfxFrame, this);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        bg->setPos(m_scrnSize.width - IMGEDT_ADDEFFECT_BAR_HEIGHT, 0);
        bg->setSize(IMGEDT_ADDEFFECT_BAR_HEIGHT, m_scrnSize.height);
        
        VFX_OBJ_CREATE_EX(m_effectPanel, VcpImgEdtEffectPanel, this, (m_vertMode));
        m_effectPanel->setPos(VfxPoint(m_scrnSize.width - IMGEDT_ADDEFFECT_BAR_HEIGHT, 0));
        m_effectPanel->setBounds(VfxRect(0, 0, IMGEDT_ADDEFFECT_BAR_HEIGHT, m_scrnSize.height));
    }
    m_effectPanel->m_tapCell.connect(this, &VappImgEdtEffectPage::onTapEdtBtn);
    m_effectPanel->setOpacity((VfxFloat)1.0f);
    m_effectPanel->getLayout()->setFocusItem(VcpMenuPos(0, m_focusIndex), VFX_TRUE);

    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject)); 

    m_iesHdlr->effectBegin();
}

void VappImgEdtEffectPage::onDeinit()
{
    m_iesHdlr->effectEnd(VFX_FALSE); 
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtEffectPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
}

void VappImgEdtEffectPage::onExit(VfxBool isBackward)
{       
    VappImgEdtBasePage::onExit(isBackward);  
}

void VappImgEdtEffectPage::onBack()
{
    m_iesHdlr->effectEnd(VFX_FALSE); 
    VfxPage::onBack();
}

void VappImgEdtEffectPage::onTapEdtBtn(VfxS32 pos, VfxFrame* cell)
{
    if (m_focusIndex != pos)
    {
        
        m_focusIndex = pos;
        VfxS32 ret = m_iesHdlr->effectSet(pos);
        if (ret < 0)
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }        
    }
    else
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(IMG_GLOBAL_INFO, VFX_WSTR_RES(m_iesHdlr->effectGetStrId(pos)));
    }
}

void VappImgEdtEffectPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        m_iesHdlr->effectEnd(VFX_TRUE);
        getMainScr()->popPage();
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        m_iesHdlr->effectEnd(VFX_FALSE);
        getMainScr()->popPage();
        break;
        
    default:
        break;
    }
}

void VappImgEdtEffectPage::onStateChange(PageState state)
{
    switch(state)
    {
    case STATE_FULL_SCREEN:
        if (!m_vertMode)
        {
            m_effectPanel->setHidden(VFX_TRUE);
            m_bottomBar->setAutoAnimate(VFX_TRUE);
        }
        m_bottomBar->setHidden(VFX_TRUE);
        m_bottomBar->setAutoAnimate(VFX_TRUE);
        break;

    case STATE_WITH_PANEL:
        if (!m_vertMode)
        {
            m_effectPanel->setHidden(VFX_FALSE);
            m_bottomBar->setAutoAnimate(VFX_TRUE);
        }
        m_bottomBar->setHidden(VFX_FALSE);
        m_bottomBar->setAutoAnimate(VFX_TRUE);
        break;

    default:
        VFX_ASSERT(state);
    }

    VappImgEdtBasePage::onStateChange(state);
}

VfxBool VappImgEdtEffectPage::onPenInput(VfxPenEvent &event)
{
    VfxBool ret = VFX_FALSE;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if (STATE_WITH_PANEL == m_pageState)
        {
            onStateChange(STATE_FULL_SCREEN);
            ret = MMI_TRUE;
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_DOWN:
        ret = MMI_TRUE;
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        break;

    default:
        break;
    }
    
    return ret;
}

VFX_IMPLEMENT_CLASS("VappImgEdtFlipPage", VappImgEdtFlipPage, VappImgEdtBasePage);

VappImgEdtFlipPage::VappImgEdtFlipPage():
m_avatarPreview(NULL),
m_imageView(NULL),
m_avatarFrame(NULL)
{
}

void VappImgEdtFlipPage::enterFlipPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtFlipPage, parent);
}

void VappImgEdtFlipPage::onInit()
{
    VappImgEdtBasePage::onInit();

    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
    VfxU8* buf  =  app->getAvatarLayerMem();

    VFX_OBJ_CREATE_EX(m_avatarFrame, VcpImgEdtPreviewLayer, this, (buf));
    m_avatarFrame->setPos(0, 0);
    m_avatarFrame->setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
    m_avatarFrame->setHidden(VFX_TRUE);

    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtFlipPage::onBottomBtnClicked);
    m_bottomBar->show();

    createFlipPanel();

    VFX_OBJ_CREATE(m_effectBefore, VcpFrameEffect, this);
    VFX_OBJ_CREATE(m_effectAfter, VcpFrameEffect, this);
    m_effectBefore->m_signalFinished.connect(this, &VappImgEdtFlipPage::onFlipFinished);

    m_imageView = m_iesHdlr->getPreviewInternal();
    VFX_ASSERT(NULL != m_imageView);
}

void VappImgEdtFlipPage::onDeinit()
{
    m_iesHdlr->flipEnd(VFX_FALSE);
    
    m_iesHdlr->destroyPreview(m_avatarPreview);
    m_avatarPreview = NULL;
    VFX_OBJ_CLOSE(m_avatarFrame);
    m_avatarFrame = NULL;
    VappImgEdtBasePage::onDeinit();
}


void VappImgEdtFlipPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
}

void VappImgEdtFlipPage::onEntered()
{    
    if (VappImgEdtIesHdlr::EDIT_TYPE_FLIP != m_iesHdlr->getCurrState())
    {
        if (NULL == m_avatarPreview)
        {        
            VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
            VfxU8* buf  =  app->getAvatarLayerMem();
            m_iesHdlr->createPreview(buf, &m_avatarPreview, m_scrnSize);
			m_iesHdlr->renderPreview(m_avatarPreview);
			
			gd_replace_src_key_16(
				buf,
				getBounds().getWidth(),
				0,
				0,
				0,
				0,
				getBounds().getWidth() - 1,
				getBounds().getHeight() - 1,
				GDI_COLOR_TRANSPARENT,
				getBounds().getWidth(),
				getBounds().getHeight());


            VfxS32 ret = m_iesHdlr->flipBegin();
            if (ret < 0)
            {
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }
        }        
    }
}

void VappImgEdtFlipPage::onExit(VfxBool isBackward)
{
    VappImgEdtBasePage::onExit(isBackward);
}

void VappImgEdtFlipPage::onBack()
{
    m_iesHdlr->flipEnd(VFX_FALSE);
    VfxPage::onBack();
}

void VappImgEdtFlipPage::createFlipPanel()
{
    VfxS32 distance = GDI_LCD_WIDTH >> 1;

    VFX_OBJ_CREATE(m_borderFrame, VfxFrame, this);
    m_borderFrame->setAnchor(0.5f, 0.5f);
    m_borderFrame->setSize(distance + 4, distance + 4);
    m_borderFrame->setPos(m_scrnSize.width>>1, m_scrnSize.height>>1);
    m_borderFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME));
    m_borderFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    for (VfxS32 i = 0; i < FLIP_DIRECT_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_flipBtn[i], VcpImageButton, this);
        m_flipBtn[i]->setIsEffect(VFX_TRUE);
        m_flipBtn[i]->setId(i);
        m_flipBtn[i]->setBgColor(VRT_COLOR_TRANSPARENT);
        m_flipBtn[i]->setAnchor(0.5, 0.5);
        m_flipBtn[i]->setBounds(VfxRect(0, 0, IMGEDT_FLIP_BTN_SIZE, IMGEDT_FLIP_BTN_SIZE));
        m_flipBtn[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        m_flipBtn[i]->m_signalClicked.connect(this, &VappImgEdtFlipPage::onFlipBtnClick);
    }
    VcpStateImage vertImgList(IMG_ID_IMGEDT_FLIP_VERT,
                              IMG_ID_IMGEDT_FLIP_VERT,
                              IMG_ID_IMGEDT_FLIP_VERT,
                              IMG_ID_IMGEDT_FLIP_VERT);
    VcpStateImage horzImgList(IMG_ID_IMGEDT_FLIP_HORZ,
                              IMG_ID_IMGEDT_FLIP_HORZ,
                              IMG_ID_IMGEDT_FLIP_HORZ,
                              IMG_ID_IMGEDT_FLIP_HORZ);

    m_flipBtn[FLIP_DIRECT_UP]->setPos(m_scrnSize.width>>1, (m_scrnSize.height - distance)/2);
    m_flipBtn[FLIP_DIRECT_UP]->setImage(vertImgList);
    m_flipBtn[FLIP_DIRECT_DOWN]->setPos(m_scrnSize.width>>1, (m_scrnSize.height + distance)/2);
    m_flipBtn[FLIP_DIRECT_DOWN]->setImage(vertImgList);
    m_flipBtn[FLIP_DIRECT_LEFT]->setPos((m_scrnSize.width - distance)/2, m_scrnSize.height/2);
    m_flipBtn[FLIP_DIRECT_LEFT]->setImage(horzImgList);
    m_flipBtn[FLIP_DIRECT_RIGHT]->setPos((m_scrnSize.width + distance)/2, m_scrnSize.height/2);
    m_flipBtn[FLIP_DIRECT_RIGHT]->setImage(horzImgList);

    for (VfxS32 i = 0; i < FLIP_DIRECT_TOTAL; i++)
    {
        m_flipBtn[i]->setIsEffect(VFX_TRUE);
        m_flipBtn[i]->setEffectRatio(2.0);
    }
}


void VappImgEdtFlipPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        m_iesHdlr->flipEnd(VFX_TRUE);
        getMainScr()->popPage();
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        m_iesHdlr->flipEnd(VFX_FALSE);
        getMainScr()->popPage();
        break;
        
    default:
        break;
    }
}

void VappImgEdtFlipPage::onFlipBtnClick(VfxObject *obj, VfxId id)
{
	//m_iesHdlr->renderPreview(m_avatarPreview);
    m_avatarFrame->setNeedRedrawPluto();
    m_avatarFrame->setHidden(VFX_FALSE);

	VcpEffectTypeDirection direction;
	direction = VCP_EFFECT_DIRECTION_FROM_NONE;
    VfxS32 ret = 0;
	VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    switch (id)
    {
    case FLIP_DIRECT_UP:
        ret = m_iesHdlr->flipAdjust(VFX_FALSE, VFX_TRUE);
		direction = VCP_EFFECT_DIRECTION_FROM_UP;    
        break;
        
    case FLIP_DIRECT_DOWN:
        ret = m_iesHdlr->flipAdjust(VFX_FALSE, VFX_TRUE);
		direction = VCP_EFFECT_DIRECTION_FROM_BOTTOM;
        break;

    case FLIP_DIRECT_LEFT:
        ret = m_iesHdlr->flipAdjust(VFX_TRUE, VFX_FALSE);
		direction = VCP_EFFECT_DIRECTION_FROM_LEFT;        
        break;
        
    case FLIP_DIRECT_RIGHT:
        ret = m_iesHdlr->flipAdjust(VFX_TRUE, VFX_FALSE);
		direction = VCP_EFFECT_DIRECTION_FROM_RIGHT;          
        break;

    default:
        VFX_ASSERT(0 && id);
    }

	if (0 == ret)
	{
		VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
		VfxU8*buf	=  app->getPreviewLayerMem();

		gdi_handle gdi_hdl;
		gdi_layer_create_using_outside_memory(
			0,
			0,
			getBounds().getWidth() - 1,
			getBounds().getHeight() - 1,
			&gdi_hdl,
			(U8*)buf,
			getBounds().getWidth() * getBounds().getHeight() * 2);
		gdi_layer_push_and_set_active((gdi_handle)gdi_hdl);

    	//gd_replace_src_key_16(
		gdi_act_replace_src_key(
			buf,
			getBounds().getWidth(),
			0,
			0,
			0,
			0,
			getBounds().getWidth() - 1,
			getBounds().getHeight() - 1,
			GDI_COLOR_TRANSPARENT,
			getBounds().getWidth(),
			getBounds().getHeight());
		
		gdi_layer_pop_and_restore_active();
		if (gdi_hdl != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(gdi_hdl);
            gdi_hdl = GDI_LAYER_EMPTY_HANDLE;
        }
		
		m_imageView->setNeedRedrawPluto();
	    m_effectAfter->applyEffect(m_imageView, VCP_EFFECT_FLIP, 500, direction);
	    m_effectBefore->applyEffect(m_avatarFrame, VCP_EFFECT_FLIP, 500, direction, VFX_TRUE);
	}

    VAPP_IMGEDT_INFO_TRACE(ret);
    if (ret < 0)
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
}

void VappImgEdtFlipPage::onFlipFinished(VfxFrame * frame,VfxBool isFinished)
{
    if (isFinished)
    {
        m_avatarFrame->setHidden(VFX_TRUE);
    }
}

VFX_IMPLEMENT_CLASS("VappImgEdtFramePage", VappImgEdtFramePage, VappImgEdtBasePage);

void VappImgEdtFramePage::enterFramePage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtFramePage, parent);
}

VappImgEdtFramePage::VappImgEdtFramePage():
m_firstFrameId(0),
m_focusIndex(0),
m_noFrame(VFX_TRUE)
{
}

void VappImgEdtFramePage::onInit()
{  
    VappImgEdtBasePage::onInit();
    if (m_vertMode)
    {
        m_firstFrameId = IMG_ID_IMGEDT_FRAME_VERT_L1;
    }
    else
    {
        m_firstFrameId = IMG_ID_IMGEDT_FRAME_HORZ_L1;
    }

    //Bottom bar
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    if (m_vertMode)
    {
        m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
        m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT + IMGEDT_FRAME_PENAL_VERT_H));
    }
    else
    {
        m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
        m_bottomBar->setBgSize(VfxSize(m_scrnSize.width - IMGEDT_FRAME_PENAL_VERT_H, IMGEDT_BOTTOM_BAR_HEIGHT));
    }
    
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtFramePage::onBottomBtnClicked);
    m_bottomBar->show();

    //bottom scrollble
    VfxFrame *bg;
    if (m_vertMode)
    {
        VFX_OBJ_CREATE(bg, VfxFrame, m_bottomBar);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        bg->setPos(0, IMGEDT_BOTTOM_BAR_HEIGHT);
        bg->setSize(m_scrnSize.width, IMGEDT_FRAME_PENAL_VERT_H);
        
        VFX_OBJ_CREATE_EX(m_framePanel, VcpImgEdtFramePanel, m_bottomBar, (m_vertMode));
        m_framePanel->setAnchor(0.5f, 0.0f);
        m_framePanel->setPos(VfxPoint(m_scrnSize.width>>1, IMGEDT_BOTTOM_BAR_HEIGHT + 1));
        VfxRect rect = m_framePanel->getBounds();
        m_framePanel->setBounds(VfxRect(rect.getX(), rect.getY(), rect.getWidth(), IMGEDT_FRAME_PENAL_VERT_H));
    }
    else
    {
        VFX_OBJ_CREATE(bg, VfxFrame, this);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        bg->setPos(m_scrnSize.width - IMGEDT_FRAME_PENAL_HORZ_W, 0);
        bg->setSize(IMGEDT_FRAME_PENAL_HORZ_W, m_scrnSize.height);
        
        VFX_OBJ_CREATE_EX(m_framePanel, VcpImgEdtFramePanel, this, (m_vertMode));
        m_framePanel->setAnchor(0.0f, 0.5f);
        m_framePanel->setPos(VfxPoint(m_scrnSize.width - IMGEDT_FRAME_PENAL_HORZ_W, m_scrnSize.height>>1));
        VfxRect rect = m_framePanel->getBounds();
        m_framePanel->setBounds(VfxRect(rect.getX(), rect.getY(), IMGEDT_FRAME_PENAL_HORZ_W, rect.getHeight()));
    }
    m_framePanel->m_tapCell.connect(this, &VappImgEdtFramePage::onTapEdtBtn);
    m_framePanel->setOpacity((VfxFloat)1.0f);
    m_framePanel->getLayout()->setFocusItem(VcpMenuPos(0, m_focusIndex), VFX_TRUE);

    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject)); 
}

void VappImgEdtFramePage::onDeinit()
{
    m_iesHdlr->addFrameEnd(VFX_FALSE);
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtFramePage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
}

void VappImgEdtFramePage::onExit(VfxBool isBackward)
{
    VappImgEdtBasePage::onExit(isBackward);
}

void VappImgEdtFramePage::onBack()
{
    m_iesHdlr->addFrameEnd(VFX_FALSE);
    VappImgEdtBasePage::onBack();
}

void VappImgEdtFramePage::onTapEdtBtn(VfxS32 pos, VfxFrame* cell)
{
    VfxResId id = 0;
    VfxS32 ret;
    if (m_noFrame)
    {
        if (pos > 0)
        {
            id = m_firstFrameId + pos - 1;
            ret = m_iesHdlr->addFrameBegin(id);
            if (ret < 0)
            {
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }
            else
            {
                m_noFrame = VFX_FALSE;
            }
        }        
    }
    else
    {
        if (0 == pos)
        {
            ret = m_iesHdlr->addFrameEnd(VFX_FALSE);
            m_noFrame = VFX_TRUE;
        }
        else
        {
            if (m_focusIndex != pos)
            {
                id  = m_firstFrameId + pos - 1;
                ret = m_iesHdlr->addFrameChange(id);
                if (ret < 0)
                {
                    VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                    onErrorPopup(strId);
                }
            }
        
        }
    }
    m_focusIndex = pos;
}


void VappImgEdtFramePage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        {
            VfxS32 ret = 0;
            if (!m_noFrame)
            {
                ret = m_iesHdlr->addFrameEnd(VFX_TRUE);
            }
            if (0 == ret)
            {
                getMainScr()->popPage();
            }
            else
            {   
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }
        }
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        if (!m_noFrame)
        {
            m_iesHdlr->addFrameEnd(VFX_FALSE);
        }
        getMainScr()->popPage();
        break;

    default:
        break;
    }
}

void VappImgEdtFramePage::onStateChange(PageState state)
{
    switch(state)
    {
    case STATE_WITH_PANEL:
        m_bottomBar->setHidden(VFX_FALSE);
        m_bottomBar->setAutoAnimate(VFX_TRUE);
        if (!m_vertMode)
        {
            m_framePanel->setHidden(VFX_FALSE);
            m_bottomBar->setAutoAnimate(VFX_TRUE);
        }
        
        break;

    case STATE_FULL_SCREEN:
        if (!m_vertMode)
        {
            m_framePanel->setHidden(VFX_TRUE);
            m_bottomBar->setAutoAnimate(VFX_TRUE);
        }
        m_bottomBar->setHidden(VFX_TRUE);
        m_bottomBar->setAutoAnimate(VFX_TRUE);
        break;

    default:
        VFX_ASSERT(state);
    }

    VappImgEdtBasePage::onStateChange(state);
}

VfxBool VappImgEdtFramePage::onPenInput(VfxPenEvent &event)
{
    VfxBool ret = VFX_FALSE;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if (STATE_WITH_PANEL == m_pageState)
        {
            onStateChange(STATE_FULL_SCREEN);
            ret = MMI_TRUE;
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_DOWN:
        ret = MMI_TRUE;
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        ret = VFX_TRUE;
        break;

    default:
        break;
    }
    
    return ret;
}


VcpImgEdtCtrlFrame:: VcpImgEdtCtrlFrame():
m_contentFrame(NULL),
m_edgeFrame(NULL),
m_btnHL(NULL),
m_movePole(0, 0),
m_orgSize(0, 0),
m_maxRect(0, 0, 0, 0),
m_curRect(0, 0, 0, 0),
m_bSupportResize(VFX_FALSE),
m_resetResizeInfo(VFX_TRUE),
m_validResizeRect(0,0,0,0),
m_detectRect(0,0,0,0)
{
    m_ctrlState = CTRL_STATE_NONE;
    m_focusBtnInx = CORNER_TOTAL;
}

void VcpImgEdtCtrlFrame::onInit()
{
    VfxControl::onInit();

    //black hide frame
    for (VfxS32 i = 0; i < DIRECT_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_hideFrame[i], VfxFrame, this);
        m_hideFrame[i]->setOpacity(1.0f);
        m_hideFrame[i]->setBgColor(VFX_COLOR_BLACK);
        m_hideFrame[i]->setBounds(0, 0, 0, 0);
    }
    //edge frame
    VFX_OBJ_CREATE(m_edgeFrame, VfxFrame, this);
    m_edgeFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME));
    m_edgeFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_btnHL, VfxFrame, this);
    m_btnHL->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BUTTON_HALO));
    m_btnHL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_btnHL->setAnchor(0.5f, 0.5f);
    m_btnHL->setHidden(VFX_TRUE);
    VfxSize iconSize, haloSize;
    iconSize = VfxImageSrc(IMG_ID_IMGEDT_BALL_LARGE).getSize();
    VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
    m_btnHL->setSize(haloSize.width, haloSize.height);
}

VfxRect VcpImgEdtCtrlFrame::getIconRect()
{
    return m_curRect;
}

void VcpImgEdtCtrlFrame::setDetectRect(VfxRect &rect)
{
    m_detectRect = rect;
}

void VcpImgEdtCtrlFrame::setContentFrame(VfxFrame* frame, VfxRect bgRect)
{
    if (NULL == m_contentFrame)
    {
        m_contentFrame = frame;
        m_orgSize = frame->getBounds().size;
        m_maxRect = bgRect;
        
        m_curRect.size = m_orgSize;
        m_curRect.origin.x = (m_maxRect.getWidth() - m_orgSize.width)/2 + m_maxRect.getX();
        m_curRect.origin.y = (m_maxRect.getHeight() - m_orgSize.height)/2 + m_maxRect.getY();
        updateLayout();
    }
}

void VcpImgEdtCtrlFrame::setContentFrame(VfxFrame* frame, VfxPoint iconPos, VfxRect bgRect)
{
    if (NULL == m_contentFrame)
    {
        m_contentFrame = frame;
        m_orgSize = frame->getBounds().size;
        m_maxRect = bgRect;
        
        m_curRect.size = m_orgSize;
        m_curRect.origin = iconPos;
        //check if curRect is inside bgRect
        if (m_curRect.origin.x > m_maxRect.getMaxX())
        {
            m_curRect.origin.x = m_maxRect.getMaxX();
        }
        if (m_curRect.origin.y > m_maxRect.getMaxY())
        {
            m_curRect.origin.y = m_maxRect.getMaxY();
        }
        if (m_curRect.getMaxX() < m_maxRect.getX())
        {
            m_curRect.origin.x = m_maxRect.getX() - m_curRect.getWidth();
        }
        if (m_curRect.getMaxY() < m_maxRect.getY())
        {
            m_curRect.origin.y = m_maxRect.getY() - m_curRect.getHeight();
        }        
        updateLayout();
    }
}


void VcpImgEdtCtrlFrame::setBgMaxRect(VfxRect &maxRect)
{
    m_maxRect = maxRect;
    if (m_curRect.getX() > m_maxRect.getMaxX())
    {
        m_curRect.origin.x = m_maxRect.getMaxX();
    }
    if (m_curRect.getY() > m_maxRect.getMaxY())
    {
        m_curRect.origin.y = m_maxRect.getMaxY();
    }
    if (m_curRect.getMaxX() < m_maxRect.getX())
    {
        m_curRect.origin.x = m_maxRect.getX() - m_curRect.size.width;
    }
    if (m_curRect.getMaxY() < m_maxRect.getY())
    {
        m_curRect.origin.y = m_maxRect.getY() - m_curRect.size.height;
    }
    m_resetResizeInfo = VFX_TRUE;
    updateLayout();
}

void VcpImgEdtCtrlFrame::setHideFrameDisabled(VfxBool isDisabled)
{
    for (VfxS32 i = 0; i < DIRECT_TOTAL; i++)
    {
        m_hideFrame[i]->setHidden(isDisabled);
    }
}

void VcpImgEdtCtrlFrame::setResizeEnabled(VfxBool bEnabled)
{
    if (bEnabled && (!m_bSupportResize))
    {
        m_bSupportResize = bEnabled;
        for (VfxS32 i = 0; i < CORNER_TOTAL; i++)
        {
            VFX_OBJ_CREATE(m_cornerBtn[i], VfxFrame, this);
            m_cornerBtn[i]->setSize(IMGEDT_CLIP_BTN_SIZE, IMGEDT_CLIP_BTN_SIZE);
            m_cornerBtn[i]->setAnchor(0.5f, 0.5f);
            m_cornerBtn[i]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALL_LARGE));
            m_cornerBtn[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        }
        updateLayout();
    }
}

VfxBool VcpImgEdtCtrlFrame::onPenInput(VfxPenEvent &event)
{
    VfxBool bRet = MMI_FALSE;
    if (event.pos.x < 0)
    {
        event.pos.x = 0;
    }
    if (event.pos.y < 0)
    {
        event.pos.y = 0;
    }
    if (event.pos.x > getBounds().getMaxX())
    {
        event.pos.x = getBounds().getMaxX();
    }
    if (event.pos.y > getBounds().getMaxY())
    {
        event.pos.y = getBounds().getMaxY();
    }
    
    if (m_detectRect.contains(event.pos))
    {
        m_signalDetectAreaTouched.emit();
    }
    
    switch (event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        if (onPenDownCheck(event))
        {
            if (CTRL_STATE_MOVE == m_ctrlState)
            {
                setEdgeFrameFocus(VFX_TRUE);   
            }
            else if (CTRL_STATE_RESIZE == m_ctrlState)
            {
                setBtnFocus(VFX_TRUE);
            }        
            bRet = VFX_TRUE;
        }
    case VFX_PEN_EVENT_TYPE_MOVE:
        if (CTRL_STATE_MOVE == m_ctrlState)
        {
            onIconMove(event);
            bRet = VFX_TRUE;
        }
        else if (CTRL_STATE_RESIZE == m_ctrlState)
        {
            onIconResize(event);
            bRet = VFX_TRUE;
        }
        break;
    case VFX_PEN_EVENT_TYPE_UP:
    case VFX_PEN_EVENT_TYPE_ABORT:  
        if (CTRL_STATE_NONE != m_ctrlState)
        {            
            if (CTRL_STATE_MOVE == m_ctrlState)
            {
                onIconMove(event);
                setEdgeFrameFocus(VFX_FALSE);
            }
            else if (CTRL_STATE_RESIZE == m_ctrlState)
            {
                onIconResize(event);
                setBtnFocus(VFX_FALSE);
            }
            m_ctrlState = CTRL_STATE_NONE;
            bRet = VFX_TRUE;
        }
        break;
    default:
        break;
    }

    return bRet;
}

VfxBool VcpImgEdtCtrlFrame::onPenDownCheck(VfxPenEvent &event)
{
    m_ctrlState = CTRL_STATE_NONE;
    if (m_bSupportResize)
    {
        for (VfxS32 i = CORNER_LEFT_UP; i < CORNER_TOTAL ; i++)
        {            
            if (m_cornerBtn[i]->getRect().contains(event.pos))
            {
                m_ctrlState = CTRL_STATE_RESIZE;
                if (m_focusBtnInx != i)
                {
                    m_resetResizeInfo = VFX_TRUE;
                    m_focusBtnInx = i;
                }            
                return VFX_TRUE;
            }
        }
    }
    if (m_edgeFrame->getRect().contains(event.pos))
    {
        m_movePole = event.pos;
        m_ctrlState = CTRL_STATE_MOVE;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VcpImgEdtCtrlFrame::onIconMove(VfxPenEvent &event)
{
    m_resetResizeInfo = VFX_TRUE;

    VfxSize moveDistance;
    moveDistance.width = event.pos.x- m_movePole.x;
    moveDistance.height = event.pos.y - m_movePole.y;

    if (moveDistance.width > 0)
    {
        if ((m_curRect.getMaxX() + moveDistance.width) > (m_maxRect.getMaxX() + m_curRect.getWidth() - 1))
        {
            moveDistance.width = m_maxRect.getMaxX() - m_curRect.getMaxX() + m_curRect.getWidth() - 1;
        }
    }
    else if (moveDistance.width < 0)
    {
        if ((m_curRect.getX() + moveDistance.width) < (m_maxRect.getX() - m_curRect.getWidth() + 1))
        {
            moveDistance.width = m_maxRect.getX() - m_curRect.getX()- m_curRect.getWidth() + 1;
        }
    }
    if (moveDistance.height > 0)
    {
       if ((m_curRect.getMaxY() + moveDistance.height) > (m_maxRect.getMaxY() + m_curRect.getHeight() - 1))
       {
           moveDistance.height = m_maxRect.getMaxY() - m_curRect.getMaxY() + m_curRect.getHeight() - 1;
       }
    }
    else if (moveDistance.height < 0)
    {
        if ((m_curRect.getY() + moveDistance.height) < (m_maxRect.getY() - m_curRect.getHeight() + 1))
        {
            moveDistance.height = m_maxRect.getY() - m_curRect.getY() - m_curRect.getHeight() + 1;
        }
    }
    
    VfxFlag flag = VFX_FALSE;
    if (moveDistance.width != 0)
    {
        m_curRect.origin.x += moveDistance.width;
        m_movePole.x += moveDistance.width;
        flag = VFX_TRUE;
    }
    if (moveDistance.height != 0)
    {
        m_curRect.origin.y += moveDistance.height;
        m_movePole.y += moveDistance.height;
        flag = VFX_TRUE;
    }

    if (flag)
    {
        updateLayout();
    }
   
}

VfxBool VcpImgEdtCtrlFrame::checkInputValid(VfxPoint pos)
{
    VfxBool bRet = VFX_TRUE;
    VfxSize refMove;
    
    /*check logic:
     *1. should not make the the size
     *2. should not larger and smaller at the same time
     */
    switch(m_focusBtnInx)
    {
    case CORNER_LEFT_UP:
        refMove.width = pos.x - m_curRect.getX();
        refMove.height = pos.y - m_curRect.getY();
        if ((pos.x >= m_curRect.getMaxX()) || 
            (pos.y >= m_curRect.getMaxY()) ||
            (refMove.width * refMove.height <= 0))
        {
            bRet = VFX_FALSE;
        }      
        break;
        
    case CORNER_LEFT_DOWN:
        refMove.width = pos.x - m_curRect.getX();
        refMove.height = pos.y - m_curRect.getMaxY();
        if ((pos.x >= m_curRect.getMaxX()) || 
            (pos.y <= m_curRect.getY()) ||
            (refMove.width * refMove.height >= 0))
        {
            bRet = VFX_FALSE;
        }
        break;
    case CORNER_RIGHT_UP:
        refMove.width = pos.x - m_curRect.getMaxX();
        refMove.height = pos.y - m_curRect.getY();
        if ((pos.x <= m_curRect.getX()) || 
            (pos.y >= m_curRect.getMaxY()) || 
            (refMove.width * refMove.height >= 0))
        {
            bRet = VFX_FALSE;
        }
        break;
    case CORNER_RIGHT_DOWN:
        refMove.width = pos.x - m_curRect.getMaxX();
        refMove.height = pos.y - m_curRect.getMaxY();
        if ((pos.x <= m_curRect.getX()) || 
            (pos.y <= m_curRect.getY()) ||
            (refMove.width * refMove.height <= 0))
        {
            bRet = VFX_FALSE;
        }
        break;
    default:
        VFX_ASSERT(0);
        break;
    }
    return bRet;
}

void VcpImgEdtCtrlFrame::resetValidRect()
{
    VfxSize minSize, maxSize;
    minSize = VfxSize(m_orgSize.width/2, m_orgSize.height/2);
    maxSize = VfxSize(m_orgSize.width*2, m_orgSize.height*2);
    VfxPoint pos1, pos2, pos3;    
    switch (m_focusBtnInx)
    {
       /*
        +--+--+--+--+
        |pos3       | 
        |           |
        +           +
        |           |
        |  orgSize  |
        +     +--+--+
        |     |     |
        |     |pos2 |
        +     |  +--+
        |     |  |  |  
        |     |  |  |
        +--+--+--+--+pos1
      */
    case CORNER_LEFT_UP:
        pos1 = VfxPoint(m_curRect.getMaxX(), m_curRect.getMaxY());
        pos2 = VfxPoint(pos1.x - minSize.width, pos1.y - minSize.height);
        pos3 = VfxPoint(pos1.x - maxSize.width, pos1.y - maxSize.height);
        VFX_ASSERT(pos3.x <= m_maxRect.getMaxX());
        VFX_ASSERT(pos3.y <= m_maxRect.getMaxY());
        if (pos2.x > m_maxRect.getMaxX())
        {
            pos2.x = m_maxRect.getMaxX();
        }       
        if (pos2.y > m_maxRect.getMaxY())
        {
            pos2.y = m_maxRect.getMaxY();
        }
        m_validResizeRect = VfxRect(pos3.x, pos3.y, pos2.x - pos3.x + 1, pos2.y - pos3.y + 1);
        break;

        /*
        +--+--+--+--+pos1
        |     |  |  | 
        |     |  |  |
        +     |  +--+
        |     |pos2 |
        |     |     |
        +     +--+--+
        |   orgSize |
        |           |
        +           +
        |           |  
        |pos3       |
        +--+--+--+--+
      */
    case CORNER_LEFT_DOWN:
        pos1 = VfxPoint(m_curRect.getMaxX(), m_curRect.getY());
        pos2 = VfxPoint(pos1.x - minSize.width, pos1.y + minSize.height);
        pos3 = VfxPoint(pos1.x - maxSize.width, pos1.y + maxSize.height);
        VFX_ASSERT(pos3.x <= m_maxRect.getMaxX());
        VFX_ASSERT(pos3.y >= m_maxRect.getY());
        if (pos2.x > m_maxRect.getMaxX())
        {
            pos2.x = m_maxRect.getMaxX();
        }
        if (pos2.y < m_maxRect.getY())
        {
            pos2.y = m_maxRect.getY();
        }
        m_validResizeRect = VfxRect(pos3.x, pos2.y, pos2.x - pos3.x + 1, pos3.y - pos2.y + 1);
        break;

        /*
        +--+--+--+--+ pos3
        |           | 
        |           |
        +           +
        |           |
        |   orgSize |
        +--+--+     +
        |     |     |
        | pos2|     |
        +--+  |     +
        |  |  |     |  
        |  |  |     |
  pos1  +--+--+--+--+
      */
    case CORNER_RIGHT_UP:
        pos1 = VfxPoint(m_curRect.getX(), m_curRect.getMaxY());
        pos2 = VfxPoint(pos1.x + minSize.width, pos1.y - minSize.height);
        pos3 = VfxPoint(pos1.x + maxSize.width, pos1.y - maxSize.height);
        VFX_ASSERT(pos3.x >= m_maxRect.getX());
        VFX_ASSERT(pos3.y <= m_maxRect.getMaxY());
        if (pos2.x < m_maxRect.getX())
        {
            pos2.x = m_maxRect.getX();
        }
        if (pos2.y > m_maxRect.getMaxY())
        {
            pos2.y = m_maxRect.getMaxY();
        }
        m_validResizeRect = VfxRect(pos2.x, pos3.y, pos3.x - pos2.x + 1, pos2.y - pos3.y + 1);
        break;

     /*
      pos1+--+--+--+--+ 
          |  |  |     | 
          |  |  |     |
          +--+  |     +
          | pos2|     |
          |     |     |
          +--+--+     +
          |   orgSize |
          |           |
          +           +
          |           |  
          |           |
          +--+--+--+--+ pos3
        */
    case CORNER_RIGHT_DOWN:
        pos1 = VfxPoint(m_curRect.getX(), m_curRect.getY());
        pos2 = VfxPoint(pos1.x + minSize.width, pos1.y + minSize.height);
        pos3 = VfxPoint(pos1.x + maxSize.width, pos1.y + maxSize.height);
        VFX_ASSERT(pos3.x >= m_maxRect.getX());
        VFX_ASSERT(pos3.y >= m_maxRect.getY());
        if (pos2.x < m_maxRect.getX())
        {
            pos2.x = m_maxRect.getX();
        }
        if (pos2.y < m_maxRect.getY())
        {
            pos2.y = m_maxRect.getY();
        }
        m_validResizeRect = VfxRect(pos2.x, pos2.y, pos3.x - pos2.x + 1, pos3.y - pos2.y + 1);
        break;
    default:
        VFX_ASSERT(0);
    }
    return;
}

void VcpImgEdtCtrlFrame::ajustInputPos(VfxPoint &pos)
{
    if (pos.x < m_validResizeRect.getX())
    {
        pos.x = m_validResizeRect.getX();
    }
    if (pos.y < m_validResizeRect.getY())
    {
        pos.y = m_validResizeRect.getY();
    }
    if (pos.x > m_validResizeRect.getMaxX())
    {
        pos.x = m_validResizeRect.getMaxX();
    }
    if (pos.y > m_validResizeRect.getMaxY())
    {
        pos.y = m_validResizeRect.getMaxY();
    }
}

void VcpImgEdtCtrlFrame::onIconResize(VfxPenEvent &event)
{
    if (!checkInputValid(event.pos))
    {
        return;
    }
    if (m_resetResizeInfo)
    {
        resetValidRect();
        m_resetResizeInfo = VFX_FALSE;
    }
    VfxPoint validPos = event.pos;
    if (!m_validResizeRect.contains(validPos))
    {
        ajustInputPos(validPos);
    }    

    VfxFloat ratio_w_h = ((VfxFloat)m_orgSize.width)/((VfxFloat)m_orgSize.height);
    VfxFloat ratio_h_w = ((VfxFloat)m_orgSize.height)/((VfxFloat)m_orgSize.width);     

    VfxSize  refMove;
    VfxS32   a;
    VfxFloat temp_ratio;
    switch(m_focusBtnInx)
    {
    case CORNER_LEFT_UP:
        refMove.width = validPos.x - m_curRect.getX();
        refMove.height = validPos.y - m_curRect.getY();
        if (0 == refMove.width * refMove.height)
        {
            refMove = VfxSize(0,0);
            break;
        }
        a = (refMove.width * refMove.height >= 0) ? 1 : -1;
        temp_ratio = a*((VfxFloat)refMove.width/(VfxFloat)refMove.height);
        if (ratio_w_h >= temp_ratio)
        {
            refMove.height = a * refMove.width * ratio_h_w;
        }
        else
        {
            refMove.width = a * refMove.height * ratio_w_h;
        }
        m_curRect.origin.x += refMove.width;
        m_curRect.origin.y += refMove.height;
        m_curRect.size.width -= refMove.width;
        m_curRect.size.height -= refMove.height;
        break;

    case CORNER_LEFT_DOWN:
        refMove.width = validPos.x - m_curRect.getX();
        refMove.height = validPos.y - m_curRect.getMaxY();
        if (0 == refMove.width * refMove.height)
        {
            refMove = VfxSize(0,0);
            break;
        }
        a = (refMove.width * refMove.height >= 0) ? 1 : -1;
        temp_ratio = a*((VfxFloat)refMove.width/(VfxFloat)refMove.height);
        if (ratio_w_h >= temp_ratio)
        {
            refMove.height = a * refMove.width * ratio_h_w;
        }
        else
        {
            refMove.width = a * refMove.height * ratio_w_h;
        }
        m_curRect.origin.x += refMove.width;
        m_curRect.size.width -= refMove.width;
        m_curRect.size.height += refMove.height;
        break;

    case CORNER_RIGHT_UP:
        refMove.width = validPos.x - m_curRect.getMaxX();
        refMove.height = validPos.y - m_curRect.getY();
        if (0 == refMove.width * refMove.height)
        {
            refMove = VfxSize(0,0);
            break;
        }
        a = (refMove.width * refMove.height >= 0) ? 1 : -1;
        temp_ratio = a*((VfxFloat)refMove.width/(VfxFloat)refMove.height);
        if (ratio_w_h >= temp_ratio)
        {
            refMove.height = a * refMove.width * ratio_h_w;
        }
        else
        {
            refMove.width = a * refMove.height * ratio_w_h;
        }
        m_curRect.origin.y += refMove.height;
        m_curRect.size.width += refMove.width;
        m_curRect.size.height -= refMove.height;
        break;

    case CORNER_RIGHT_DOWN:
        refMove.width = validPos.x - m_curRect.getMaxX();
        refMove.height = validPos.y - m_curRect.getMaxY();
        if (0 == refMove.width * refMove.height)
        {
            refMove = VfxSize(0,0);
            break;
        }
        a = (refMove.width * refMove.height >= 0) ? 1 : -1;
        temp_ratio = a*((VfxFloat)refMove.width/(VfxFloat)refMove.height);
        if (ratio_w_h >= temp_ratio)
        {
            refMove.height = a * refMove.width * ratio_h_w;
        }
        else
        {
            refMove.width = a * refMove.height * ratio_w_h;
        }
        m_curRect.size.width += refMove.width;
        m_curRect.size.height += refMove.height;
        break;
    default:
        VFX_ASSERT(0);
    }
    
    if (!refMove.isZero())
    {
        updateLayout();
    }   
}

void VcpImgEdtCtrlFrame::updateLayout()
{
    if (NULL == m_contentFrame)
    {
        return;
    }
    if (m_curRect.isEmpty() || m_maxRect.isEmpty())
    {
        return;
    }

    //resize&move contect frame
    m_contentFrame->setBounds(0, 0, m_curRect.getWidth(), m_curRect.getHeight());
    m_contentFrame->setPos(m_curRect.getX(), m_curRect.getY());

    //resize&move edge frame
    m_edgeFrame->setBounds(0, 0, 
                           IMGEDT_EDGE_FRAME_BORDER*2 + m_curRect.getWidth(), 
                           IMGEDT_EDGE_FRAME_BORDER*2 + m_curRect.getHeight());
    m_edgeFrame->setPos(m_curRect.getX() - IMGEDT_EDGE_FRAME_BORDER, 
                        m_curRect.getY() - IMGEDT_EDGE_FRAME_BORDER);
    //hide frame
    if (m_curRect.getX() < m_maxRect.getX())
    {
        m_hideFrame[DIRECT_LEFT]->setPos(m_curRect.getX(), m_curRect.getY());
        m_hideFrame[DIRECT_LEFT]->setBounds(0, 0, 
                                            m_maxRect.getX() - m_curRect.getX(), 
                                            m_curRect.getHeight());
    }
    else
    {
        m_hideFrame[DIRECT_LEFT]->setBounds(0, 0, 0, 0);
    }
    if (m_curRect.getY() < m_maxRect.getY())
    {
        m_hideFrame[DIRECT_UP]->setPos(m_curRect.getX(), m_curRect.getY());
        m_hideFrame[DIRECT_UP]->setBounds(0, 0, 
                                          m_curRect.getWidth(),
                                          m_maxRect.getY() - m_curRect.getY());
    }
    else
    {
        m_hideFrame[DIRECT_UP]->setBounds(0, 0, 0, 0);
    }
    if (m_curRect.getMaxX() > m_maxRect.getMaxX())
    {
        m_hideFrame[DIRECT_RIGHT]->setPos(m_maxRect.getMaxX() + 1, m_curRect.getY());
        m_hideFrame[DIRECT_RIGHT]->setBounds(0, 0, 
                                             m_curRect.getMaxX() - m_maxRect.getMaxX(), 
                                             m_curRect.getHeight());
    }
    else
    {
        m_hideFrame[DIRECT_RIGHT]->setBounds(0, 0, 0, 0);
    }
    if (m_curRect.getMaxY() > m_maxRect.getMaxY())       
    {
        m_hideFrame[DIRECT_DOWN]->setPos(m_curRect.getX(), m_maxRect.getMaxY() + 1);
        m_hideFrame[DIRECT_DOWN]->setBounds(0, 0, 
                                            m_curRect.getWidth(),
                                            m_curRect.getMaxY() - m_maxRect.getMaxY());
    }
    else
    {
        m_hideFrame[DIRECT_DOWN]->setBounds(0, 0, 0, 0);
    }
    
    //button
    if (m_bSupportResize)
    {
        m_cornerBtn[CORNER_LEFT_UP]->setPos(m_curRect.getX() - 1, m_curRect.getY() - 1);
        m_cornerBtn[CORNER_LEFT_DOWN]->setPos(m_curRect.getX() - 1, m_curRect.getMaxY() + 1);
        m_cornerBtn[CORNER_RIGHT_UP]->setPos(m_curRect.getMaxX() + 1, m_curRect.getY() - 1);
        m_cornerBtn[CORNER_RIGHT_DOWN]->setPos(m_curRect.getMaxX() + 1, m_curRect.getMaxY() + 1);
        if ((CTRL_STATE_RESIZE == m_ctrlState) && 
            (NULL != m_btnHL) && (m_focusBtnInx < CORNER_TOTAL))
        {
            m_btnHL->setPos(m_cornerBtn[m_focusBtnInx]->getRect().getMidX(),
                            m_cornerBtn[m_focusBtnInx]->getRect().getMidY());
            m_btnHL->setHidden(VFX_FALSE);
        }
    }
}


void VcpImgEdtCtrlFrame::setEdgeFrameFocus(VfxBool bFocus)
{
    if (bFocus)
    {
        m_edgeFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME_HL));
    }
    else
    {
        m_edgeFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME));
    } 
}

void VcpImgEdtCtrlFrame::setBtnFocus(VfxBool bFocus)
{
    if (!m_bSupportResize)
    {
        return;
    }
    
    if (bFocus)
    {
        if (m_focusBtnInx < CORNER_TOTAL)
        {
            m_btnHL->setPos(m_cornerBtn[m_focusBtnInx]->getRect().getMidX(),
                            m_cornerBtn[m_focusBtnInx]->getRect().getMidY());
            m_btnHL->setHidden(VFX_FALSE);
       }
    }
    else
    {
        if (NULL != m_btnHL)
        {
            m_btnHL->setHidden(VFX_TRUE);
        }
    }
}


void VcpImgEdtIconCellProvider::getImageContent(VfxS32 index, VfxFrame *frame)
{

    VfxResId id = IMG_ID_IMGEDT_ICON_L1 + index;
    VfxImageSrc img(id);
    frame->setImgContent(img); 
    frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}


VFX_IMPLEMENT_CLASS("VappImgEdtIconPage", VappImgEdtIconPage, VappImgEdtBasePage);

void VappImgEdtIconPage::enterIconPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtIconPage, parent);
}

VappImgEdtIconPage::VappImgEdtIconPage():
m_iconCtrlFrame(NULL),
m_iconPopup(NULL),
m_iconFrame(NULL),
m_iconId(0),
m_iconIndex(0),
m_firstEnter(VFX_FALSE),
m_exitPage(VFX_FALSE)
{
}

void VappImgEdtIconPage::onInit()
{
    VappImgEdtBasePage::onInit();

    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_ICON, IMG_ID_IMGEDT_BOTTOMBAR_CLIP_LIST);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtIconPage::onBottomBtnClicked);
    m_bottomBar->show();
    m_bottomBar->setDisabled(VFX_TRUE);

    createZoomSlider(VFX_OBJ_DYNAMIC_CAST(this,VfxObject));
    m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject)); 
}

void VappImgEdtIconPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
    if (!isBackward)
    {
        m_firstEnter = VFX_TRUE;
    }
    VAPP_IMGEDT_INFO_TRACE(m_firstEnter);
}

void VappImgEdtIconPage::onEntered()
{
    if (m_firstEnter)
    {
        m_firstEnter = VFX_FALSE;
        VFX_OBJ_CREATE_EX(m_iconPopup ,VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_CLIPART));
        m_iconPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_ICON));
        m_iconPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_CLIPART));
        m_iconPopup->setContentProvider((IVcpImgEdtMattsCellProvider*)&m_provider);
        m_iconPopup->m_selectIcon.connect(this, &VappImgEdtIconPage::onIconSelected);
        m_iconPopup->m_signalMattsPopupCancel.connect(this, &VappImgEdtIconPage::onMattsPopupCanceled);
        m_iconPopup->m_signalPopupState.connect(this, &VappImgEdtIconPage::onMattsPopupStateChange);
        m_iconPopup->show(VFX_TRUE);
    }
}

void VappImgEdtIconPage::onExit(VfxBool isBackward)
{
    if (isBackward && (m_iconId != 0))
    {
        m_iconCtrlFrame->setHidden(VFX_TRUE);
        m_iconFrame->setHidden(VFX_TRUE);
    }
    VappImgEdtBasePage::onExit(isBackward);
}


void VappImgEdtIconPage::setClipArtIcon(VfxResId id)
{
    if (m_iconCtrlFrame != NULL)
    {
        VFX_OBJ_CLOSE(m_iconCtrlFrame);
    }
    if (m_iconFrame != NULL)
    {
        VFX_OBJ_CLOSE(m_iconFrame);
    }
    m_iconId = id;
    VfxImageSrc iconSrc(m_iconId);
    VfxSize iconSize = iconSrc.getSize();
    VFX_OBJ_CREATE(m_iconFrame, VfxFrame, this);
    m_iconFrame->setImgContent(iconSrc);
    m_iconFrame->setSize(iconSize);
    m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VfxRect rect;    
    VFX_OBJ_CREATE(m_iconCtrlFrame, VcpImgEdtCtrlFrame, this);
    m_iconCtrlFrame->setBounds(0, 0, m_scrnSize.width, m_scrnSize.height);
    m_iesHdlr->getScrnArea(&rect); 
    m_iconCtrlFrame->setContentFrame(m_iconFrame, rect);   
    m_iconCtrlFrame->setResizeEnabled(VFX_TRUE);
    rect = m_bottomBar->getRect();
    m_iconCtrlFrame->setDetectRect(rect);
    m_iconCtrlFrame->m_signalDetectAreaTouched.connect(this, &VappImgEdtIconPage::onBottomTouched);

    m_bottomBar->bringToFront();
    m_zoomSlider->bringToFront();
    m_zoomAdd->bringToFront();
    m_zoomDec->bringToFront();
}

void VappImgEdtIconPage::onIconSelected(VfxS32 pos)
{
    if (0 == m_iconId)
    {
        m_bottomBar->setDisabled(VFX_FALSE);
    }
    m_iconIndex = pos;
    setClipArtIcon(IMG_ID_IMGEDT_ICON_L1 + m_iconIndex);
}

void VappImgEdtIconPage::onMattsPopupCanceled()
{
    if (0 == m_iconId)
    {
        m_exitPage = VFX_TRUE;
    }
    VAPP_IMGEDT_INFO_TRACE(m_exitPage);
}

void VappImgEdtIconPage::onMattsPopupStateChange(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        if (0 == m_iconId && m_exitPage)
        {
            VfxPage::exit();
        }
    }
}

void VappImgEdtIconPage::onStateChange(PageState state)
{
    switch(state)
    {
    case STATE_FULL_SCREEN:
        m_bottomBar->setHidden(VFX_TRUE);
        m_iconCtrlFrame->m_signalDetectAreaTouched.disconnect(this, &VappImgEdtIconPage::onBottomTouched);      
        break;

    case STATE_WITH_PANEL:
        m_bottomBar->setHidden(VFX_FALSE);
        m_bottomBar->bringToFront();
        m_iconCtrlFrame->m_signalDetectAreaTouched.connect(this, &VappImgEdtIconPage::onBottomTouched);
        break;

    default:
        VFX_ASSERT(state);
    }

    VappImgEdtBasePage::onStateChange(state);
}

void VappImgEdtIconPage::onZoomStart()
{
    m_iconCtrlFrame->setHideFrameDisabled(VFX_TRUE);
};

void VappImgEdtIconPage::onZoomEnd()
{
    m_iconCtrlFrame->setHideFrameDisabled(VFX_FALSE);
    m_iconCtrlFrame->setBgMaxRect(m_bgRange);    
}


void VappImgEdtIconPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        {
            rect = m_iconCtrlFrame->getIconRect();
            VfxS32 ret = m_iesHdlr->addIcon(m_iconId, rect);
            if (0 == ret)
            {
                getMainScr()->popPage();
            }
            else
            {   
                VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
                onErrorPopup(strId);
            }
        }
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        getMainScr()->popPage();
        break;
        
    case BOTTOM_BTN_SHOW_ICON:        
        VFX_OBJ_CREATE_EX(m_iconPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_CLIPART));
        m_iconPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_ICON));
        m_iconPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_CLIPART));
        m_iconPopup->setContentProvider((IVcpImgEdtMattsCellProvider*)&m_provider);
        m_iconPopup->show(VFX_TRUE);
        m_iconPopup->setFocus(m_iconIndex);
        m_iconPopup->m_selectIcon.connect(this, &VappImgEdtIconPage::onIconSelected);
        m_iconPopup->m_signalPopupState.connect(this, &VappImgEdtIconPage::onMattsPopupStateChange);
        break;
        
    default:
        break;
    }    
}

void VappImgEdtIconPage::onBottomTouched()
{
    if (STATE_WITH_PANEL == m_pageState)
    {
        onStateChange(STATE_FULL_SCREEN);
    }
}

VfxBool VappImgEdtIconPage::onPenInput(VfxPenEvent &event)
{

    VfxBool bRet = VFX_FALSE;
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        bRet = VappImgEdtBasePage::onPenInput(event);
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_bottomBar->getRect().contains(event.pos))
        {
            onStateChange(STATE_FULL_SCREEN);
        }
        bRet = VappImgEdtBasePage::onPenInput(event);
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_UP:
        bRet = VappImgEdtBasePage::onPenInput(event);
        break;

    default:
        break;
    }
    
    return bRet;
}

void VcpImgEdtColorCellProvider::getImageContent(VfxS32 index, VfxFrame *frame)
{
    VfxColor color = VRT_COLOR_MAKE(255, 
                                    g_imgedt_text_color_list[index].r, 
                                    g_imgedt_text_color_list[index].g, 
                                    g_imgedt_text_color_list[index].b);
    
    frame->setBgColor(color);
}


void  VcpImgEdtPenProvider::getImageContent(VfxS32 index, VfxFrame *frame)
{
    VfxImageSrc img(IMG_ID_IMGEDT_BRUSH_L1 + index);
    frame->setImgContent(img);
}

void  VcpImgEdtEraseProvider::getImageContent(VfxS32 index, VfxFrame *frame)
{
    VfxImageSrc img(IMG_ID_IMGEDT_ERASE_L1 + index);
    frame->setImgContent(img);
}

void  VcpImgEdtTextProvider::getImageContent(VfxS32 index, VfxFrame *frame)
{
    VfxImageSrc img(IMG_ID_IMGEDT_TEXT_L1 + index);
    frame->setImgContent(img);
}

VFX_IMPLEMENT_CLASS("VappImgEdtTextPage", VappImgEdtTextPage, VappImgEdtBasePage);

void VappImgEdtTextPage::enterTextPage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtTextPage, parent);
}

VappImgEdtTextPage::VappImgEdtTextPage():
m_textCtrlFrame(NULL),
m_textFrame(NULL),
m_buff(NULL),
m_gdiHdl(0),
m_string(VFX_WSTR_NULL),
m_colorIndx(0),
m_firstEnter(VFX_FALSE),
m_exitPage(VFX_FALSE)
{
    m_fontIndex = FONT_SIZE_L4;
    m_fontSize[FONT_SIZE_L1] = IMGEDT_ADD_TEXT_FONT_SIZE_L1;
    m_fontSize[FONT_SIZE_L2] = IMGEDT_ADD_TEXT_FONT_SIZE_L2;
    m_fontSize[FONT_SIZE_L3] = IMGEDT_ADD_TEXT_FONT_SIZE_L3;
    m_fontSize[FONT_SIZE_L4] = IMGEDT_ADD_TEXT_FONT_SIZE_L4;
}

void VappImgEdtTextPage::onInit()
{
    VappImgEdtBasePage::onInit();

    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT*2));
    m_bottomBar->setTranslucent(VFX_TRUE);

    m_bottomBar->addItem(BOTTOM_BTN_SHOW_TEXT, IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_SIZE, VcpImgEdtBottomBar::BOTTOM_BTN_L1, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_COLOR, IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_COLOR, VcpImgEdtBottomBar::BOTTOM_BTN_L1);
    m_bottomBar->addItem(BOTTOM_BTN_TEXT_L1, IMG_ID_IMGEDT_TEXT_L1, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_TEXT_L2, IMG_ID_IMGEDT_TEXT_L2, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_TEXT_L3, IMG_ID_IMGEDT_TEXT_L3, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_TEXT_L4, IMG_ID_IMGEDT_TEXT_L4, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtTextPage::onBottomBtnClicked);
    m_bottomBar->show();
    m_bottomBar->setVisibleMode(MMI_TRUE);
    m_bottomBar->setDownState(VFX_TRUE, BOTTOM_BTN_SHOW_TEXT);
    m_bottomBar->setDownState(VFX_FALSE, BOTTOM_BTN_TEXT_L4);
    m_bottomBar->setDisabled(VFX_TRUE);

    //create other element
    createZoomSlider(VFX_OBJ_DYNAMIC_CAST(this,VfxObject));
    m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject)); 
    m_bottomBar->bringToFront();
}

void VappImgEdtTextPage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
    if (!isBackward)
    {
        m_firstEnter = VFX_TRUE;
    }
    VAPP_IMGEDT_INFO_TRACE(m_firstEnter);
}

void VappImgEdtTextPage::onEntered()
{
    if (m_firstEnter)
    {
        m_firstEnter = VFX_FALSE;
        VFX_OBJ_CREATE(m_textPopup ,VcpInputPopup, this);
        m_textPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_ADD_TEXT));
        m_textPopup->setText(VFX_WSTR_EMPTY, 10, VFX_FALSE);
        m_textPopup->setIME(IMM_INPUT_TYPE_SENTENCE); 
        m_textPopup->m_signalButtonClicked.connect(this, &VappImgEdtTextPage::onTextPopupBtnClick);
        m_textPopup->m_signalPopupState.connect(this, &VappImgEdtTextPage::onTextPopupStateChange);
        m_textPopup->show(VFX_TRUE);
        //get image w&h
        VfxRect imgRect;
        m_iesHdlr->getCurrImageRect(&imgRect);
        m_imgSize = imgRect.size;
    }
}

void VappImgEdtTextPage::onExit(VfxBool isBackward)
{
    if (isBackward && (!m_string.isNull()))
    {
        if (NULL != m_textCtrlFrame)
        {
            m_textCtrlFrame->setHidden(VFX_TRUE);
        }
        if (NULL != m_textFrame)
        {
            m_textFrame->setHidden(VFX_TRUE);
        }        
    }
    VappImgEdtBasePage::onExit(isBackward);
}

void VappImgEdtTextPage::onDeinit()
{
    if (m_gdiHdl != 0)
    {
        VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);
        gdi_layer_free(m_gdiHdl);
        m_gdiHdl = 0;
        app->discardLastTextMem();
        m_buff = NULL;
    }
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtTextPage::setTextContent(VfxWString &str)
{
    m_string = str;    
    updateTextFrame();
    m_bottomBar->setDisabled(VFX_FALSE);
}

void VappImgEdtTextPage::updateTextColor()
{
    prepareTextInfo();
    redrawText();
    m_textFrame->invalidate();
}

void VappImgEdtTextPage::onTextPopupBtnClick(VfxObject* sender, VcpInputPopupButtonEnum type)
{
    if (VCP_INPUT_POPUP_BTN_OK == type)
    {
        VfxWString str(m_textPopup->getText());
        m_textPopup->leave(VFX_TRUE);
        setTextContent(str);
    }
    else if (VCP_INPUT_POPUP_BTN_CANCEL == type)
    {
        m_textPopup->leave(VFX_TRUE);
        //User should not press key, when there is no string
        if (m_string.isNull())
        {
            m_bottomBar->setDisabled(VFX_TRUE);
            m_exitPage = VFX_TRUE;
        }
    }
}  

void VappImgEdtTextPage::onPageExitTimeout(VfxTimer *timer)
{
    getMainScr()->popPage();
    timer->stop();
    VFX_OBJ_CLOSE(timer);
}

void VappImgEdtTextPage::onTextPopupStateChange(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        if (m_string.isNull() && m_exitPage)
        {
            VfxTimer *exitTimer;
            VFX_OBJ_CREATE(exitTimer, VfxTimer, this);
            exitTimer->setDuration(1);
            exitTimer->m_signalTick.connect(this, &VappImgEdtTextPage::onPageExitTimeout);
            exitTimer->start();
        }
    }
}

void VappImgEdtTextPage::updateTextFrame()
{
    VfxBool bChangeFont = VFX_FALSE;
    VfxPoint lastPos(0,0);

    if (NULL != m_textCtrlFrame)
    {
        bChangeFont = VFX_TRUE;
        lastPos = m_textCtrlFrame->getIconRect().getMidPoint();
        VFX_OBJ_CLOSE(m_textCtrlFrame);
        m_textCtrlFrame = NULL;
    }

    prepareTextInfo();
    if (!recreateText())
    {
        onErrorPopup(STR_GLOBAL_NOT_ENOUGH_MEMORY);
        VAPP_IMGEDT_ERROR_TRACE(0);
        return;
    }
    redrawText();

    VfxRect rect;    
    VFX_OBJ_CREATE(m_textCtrlFrame, VcpImgEdtCtrlFrame, this);
    m_textCtrlFrame->setBounds(0, 0, m_scrnSize.width, m_scrnSize.height);
    m_iesHdlr->getScrnArea(&rect); 
    if (bChangeFont)
    {
        VfxPoint newPos;
        newPos.x = lastPos.x - (m_textFrameSize.width/2);
        newPos.y = lastPos.y - (m_textFrameSize.height/2);
        m_textCtrlFrame->setContentFrame(m_textFrame, newPos, rect);
    }
    else
    {
        m_textCtrlFrame->setContentFrame(m_textFrame, rect);
    }       
    rect = m_bottomBar->getRect();
    m_textCtrlFrame->setDetectRect(rect);
    m_textCtrlFrame->m_signalDetectAreaTouched.connect(this, &VappImgEdtTextPage::onBottomTouched);
    m_bottomBar->bringToFront();
    m_zoomSlider->bringToFront();
    m_zoomAdd->bringToFront();
    m_zoomDec->bringToFront();
}

void VappImgEdtTextPage::prepareTextInfo()
{
    stFontAttribute stF;
    UI_font_type f = &stF;
    f->bold = 1;
    f->italic = 0;
    f->underline = 0;  /* underline style */
    f->size = FONT_PIXEL_SIZE(m_fontSize[m_fontIndex]);
    f->color = 0;      /* font color */
    f->type = 1;       /* font type */
    f->oblique = 0;    /* oblique style */
    f->smallCaps = 0;  /* smallCaps style */

    gui_set_font(f);
    gui_measure_string((UI_string_type)m_string.getBuf(), &m_strSize.width, &m_strSize.height);
}

VfxBool VappImgEdtTextPage::recreateText()
{
    VappImgEdtApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgEdtApp);

    if (m_gdiHdl != 0)
    {
        gdi_layer_free(m_gdiHdl);
        m_gdiHdl = 0;
        app->discardLastTextMem();
        m_buff = NULL;
    }

    if (NULL != m_textFrame)
    {
        VFX_OBJ_CLOSE(m_textFrame);
        m_textFrame = NULL;
    }

    //check frame size:
    m_textFrameSize = m_strSize;
    if (m_strSize.width < m_imgSize.width/64.0)
    {
        m_textFrameSize.width = (m_imgSize.width + 63)/64;
        VAPP_IMGEDT_INFO_TRACE(m_textFrameSize.width);
    }
    if (m_strSize.height < m_imgSize.height/64.0)
    {
        m_textFrameSize.height = (m_imgSize.height + 63)/64;
        VAPP_IMGEDT_INFO_TRACE(m_textFrameSize.height);
    }

    VfxS32 size = m_textFrameSize.width * m_textFrameSize.height * 4;
    m_buff = app->getTextLayerMem(size);
    if (NULL == m_buff)
    {
        return VFX_FALSE;
    }

    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32_PARGB,
                                             0,
                                             0,
                                             m_textFrameSize.width,
                                             m_textFrameSize.height,
                                             &m_gdiHdl,
                                             (U8*)m_buff,
                                             m_textFrameSize.width * m_textFrameSize.height * 4);
    
    VfxImageBuffer imgBuf;
    imgBuf.ptr = m_buff;
    imgBuf.pitchBytes = m_textFrameSize.width * 4;
    imgBuf.width = m_textFrameSize.width;
    imgBuf.height = m_textFrameSize.height;
    imgBuf.colorFormat = VRT_COLOR_TYPE_ARGB8888;
    
    VFX_OBJ_CREATE(m_textFrame, VfxFrame, this);
    m_textFrame->setImgContent(VfxImageSrc(imgBuf));
    m_textFrame->setSize(m_textFrameSize);

    return VFX_TRUE;
}

void VappImgEdtTextPage::redrawText()
{
    VFX_ASSERT(m_gdiHdl != 0);
    VfxPoint offset(0,0);
    offset.x =  (m_textFrameSize.width - m_strSize.width)/2;
    offset.y = (m_textFrameSize.height - m_strSize.height)/2;
    VAPP_IMGEDT_INFO_TRACE(offset.x);
    VAPP_IMGEDT_INFO_TRACE(offset.y);
    
    gdi_layer_push_and_set_active(m_gdiHdl);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gui_push_text_clip();
    gui_set_text_color(gui_color(g_imgedt_text_color_list[m_colorIndx].r, 
                                 g_imgedt_text_color_list[m_colorIndx].g, 
                                 g_imgedt_text_color_list[m_colorIndx].b));
    gui_set_text_clip(offset.x, offset.y, offset.x + m_strSize.width, offset.y + m_strSize.height);
    if (vrt_sys_get_text_dir() == MG_TEXT_DIR_TYPE_R2L)
    {
        gui_move_text_cursor(offset.x + m_strSize.width - 1, offset.y);
    }
    else
    {
        gui_move_text_cursor(offset.x, offset.y);
    }
    gdi_push_and_set_alpha_blending_source_layer(m_gdiHdl);
    gui_print_text((UI_string_type)m_string.getBuf());
    gdi_pop_and_restore_alpha_blending_source_layer();
    gui_pop_text_clip();
    gdi_layer_pop_and_restore_active();   
}

void VappImgEdtTextPage::createColorSelector()
{
    VFX_OBJ_CREATE_EX(m_colorPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_COLOR));
    m_colorPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_COLOR));
    m_colorPopup->setContentProvider(&m_provider);
    m_colorPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_COLOR));
    m_colorPopup->show(VFX_TRUE);
    m_colorPopup->m_selectIcon.connect(this, &VappImgEdtTextPage::onColorSelected);
    m_colorPopup->m_signalPopupState.connect(this, &VappImgEdtTextPage::onColorPopupState);
    m_colorPopup->setFocus(m_colorIndx);
}

void VappImgEdtTextPage::onColorSelected(VfxS32 pos)
{
    if (pos != m_colorIndx)
    {
        m_colorIndx = pos;
        updateTextColor();
    }    
}

void VappImgEdtTextPage::onColorPopupState(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        m_bottomBar->setDownState(VFX_TRUE, BOTTOM_BTN_SHOW_TEXT);
    }
}

void VappImgEdtTextPage::onZoomStart()
{
    m_textCtrlFrame->setHideFrameDisabled(VFX_TRUE);
};

void VappImgEdtTextPage::onZoomEnd()
{
    m_textCtrlFrame->setHideFrameDisabled(VFX_FALSE);
    m_textCtrlFrame->setBgMaxRect(m_bgRange);    
}

void VappImgEdtTextPage::onStateChange(PageState state)
{
    switch(state)
    {
    case STATE_FULL_SCREEN:
        m_bottomBar->setHidden(VFX_TRUE);
        break;

    case STATE_WITH_PANEL:
        m_bottomBar->setHidden(VFX_FALSE);
        m_bottomBar->bringToFront();
        break;

    default:
        VFX_ASSERT(state);
    }

    VappImgEdtBasePage::onStateChange(state);
}

void VappImgEdtTextPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect;
    VfxS32 ret = 0;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        rect = m_textFrame->getRect();
        ret = m_iesHdlr->addText(m_buff, rect);
        if (ret < 0)
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }
        else
        {
            getMainScr()->popPage();
        }        
        if (m_gdiHdl != 0)
        {
            gdi_layer_free(m_gdiHdl);
            m_gdiHdl = 0;
        }
        m_buff = NULL;
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        getMainScr()->popPage();
        break;

    case BOTTOM_BTN_SHOW_TEXT:
        m_bottomBar->setVisibleMode(VFX_TRUE);
        break;

    case BOTTOM_BTN_SHOW_COLOR:
        createColorSelector();
        break;

    case BOTTOM_BTN_TEXT_L1:
        m_fontIndex = FONT_SIZE_L1;
        updateTextFrame();
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_TEXT_L1);
        break;
        
    case BOTTOM_BTN_TEXT_L2:
        m_fontIndex = FONT_SIZE_L2;
        updateTextFrame();
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_TEXT_L2);
        break;
        
    case BOTTOM_BTN_TEXT_L3:
        m_fontIndex = FONT_SIZE_L3;
        updateTextFrame();
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_TEXT_L3);
        break;
        
    case BOTTOM_BTN_TEXT_L4:
        m_fontIndex = FONT_SIZE_L4;
        updateTextFrame();
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_TEXT_L4);
        break;
        
    default:
        break;
    }    
}

void VappImgEdtTextPage::onBottomTouched()
{
    if (STATE_WITH_PANEL == m_pageState)
    {
        onStateChange(STATE_FULL_SCREEN);
    }
}


VfxBool VappImgEdtTextPage::onPenInput(VfxPenEvent &event)
{

    VfxBool bRet = VFX_FALSE;
    VfxSize distance;
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        bRet = VappImgEdtBasePage::onPenInput(event);     
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_bottomBar->getRect().contains(event.pos))
        {
            onStateChange(STATE_FULL_SCREEN);
        }
        bRet = VappImgEdtBasePage::onPenInput(event);
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_UP:
        bRet = VappImgEdtBasePage::onPenInput(event);
        break;

    default:
        break;
    }
    
    return bRet;
}


VFX_IMPLEMENT_CLASS("VappImgEdtDoodlePage", VappImgEdtDoodlePage, VappImgEdtBasePage);

void VappImgEdtDoodlePage::enterDoodlePage(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtDoodlePage, parent);
}

VappImgEdtDoodlePage::VappImgEdtDoodlePage():
m_bStrokeMode(VFX_FALSE),
m_bAdjustState(VFX_TRUE),
m_lastDoodlePos(0,0),
m_colorIndx(0)
{
    m_penSizeIndx = PEN_SIZE_L5;
    m_penSize[PEN_SIZE_L1] = 10 + 1;
    m_penSize[PEN_SIZE_L2] = 8 + 1;
    m_penSize[PEN_SIZE_L3] = 6 + 1;
    m_penSize[PEN_SIZE_L4] = 4 + 1;
    m_penSize[PEN_SIZE_L5] = 2 + 1;

    m_eraseSizeIndx = ERASE_SIZE_L5;
    m_eraseSize[ERASE_SIZE_L1] = 10;
    m_eraseSize[ERASE_SIZE_L2] = 8;
    m_eraseSize[ERASE_SIZE_L3] = 6;
    m_eraseSize[ERASE_SIZE_L4] = 4;
    m_eraseSize[ERASE_SIZE_L5] = 2;
}

void VappImgEdtDoodlePage::onInit()
{
    m_activeBtn = BOTTOM_BTN_TOTAL;
    VappImgEdtBasePage::onInit();

    createBottomBar();

    createZoomSlider(VFX_OBJ_DYNAMIC_CAST(this,VfxObject));
    m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    
    createHindBtn(VFX_OBJ_DYNAMIC_CAST(this,VfxObject)); 
    m_hintBtn->m_hintBtnPress.connect(this, &VappImgEdtDoodlePage::onHideBtnStateChanged);

    m_bottomBar->bringToFront();
}

void VappImgEdtDoodlePage::onHideBtnStateChanged(VfxBool isDown)
{
    if (isDown)
    {
        mmi_pen_disable_stroke_event();
    }
    else
    {
        mmi_pen_enable_stroke_event();
    }
}

void VappImgEdtDoodlePage::onHintBtnClicked(VfxObject *obj, VfxId id)
{
    startStroke();
    VappImgEdtBasePage::onHintBtnClicked(obj, id);
}


void VappImgEdtDoodlePage::createBottomBar()
{
    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT * 2));    
    m_bottomBar->setTranslucent(VFX_TRUE);

    m_bottomBar->addItem(BOTTOM_BTN_SHOW_SIZE, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_SIZE, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L1,
                         VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_COLOR, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_COLOR, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L1,
                         VFX_FALSE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_ERASE, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_ERASER, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L1,
                         VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_L2_1, IMG_ID_IMGEDT_BRUSH_L1, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_L2_2, IMG_ID_IMGEDT_BRUSH_L2, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_L2_3, IMG_ID_IMGEDT_BRUSH_L3, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_L2_4, IMG_ID_IMGEDT_BRUSH_L4, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    m_bottomBar->addItem(BOTTOM_BTN_L2_5, IMG_ID_IMGEDT_BRUSH_L5, VcpImgEdtBottomBar::BOTTOM_BTN_L2, VFX_TRUE);
    
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtDoodlePage::onBottomBtnClicked);
    m_bottomBar->show();
    m_bottomBar->setVisibleMode(MMI_FALSE);
}

void VappImgEdtDoodlePage::onDeinit()
{
    m_iesHdlr->doodleEnd(VFX_FALSE);
    //set preview page hittable
    m_iesHdlr->getPreviewInternal()->setIsUnhittable(VFX_FALSE);
    VappImgEdtBasePage::onDeinit();
}

void VappImgEdtDoodlePage::onEnter(VfxBool isBackward)
{
    VappImgEdtBasePage::onEnter(isBackward);
    if (!m_bAdjustState)
    {
        startStroke();
    }
}

void VappImgEdtDoodlePage::onExit(VfxBool isBackward)
{
    endStroke();
    VappImgEdtBasePage::onExit(isBackward);    
}

void VappImgEdtDoodlePage::onBack()
{
    m_iesHdlr->doodleEnd(VFX_FALSE);
    VfxPage::onBack();
}

void VappImgEdtDoodlePage::setDoodleSize(VfxBool isPen, VfxS32 index)
{
    if (isPen)
    {
        m_penSizeIndx = index;
        m_iesHdlr->doodleSetWidth(m_penSize[m_penSizeIndx]);
    }
    else
    {
        m_eraseSizeIndx = index;
    }
}

void VappImgEdtDoodlePage::updateBottomBarL2(VfxBool isPen)
{
    VfxResId btnId = PEN_SIZE_L1;
    if (isPen)
    {
        //set L2 as pen size icon
        m_bottomBar->resetItemImage(0, IMG_ID_IMGEDT_BRUSH_L1, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(1, IMG_ID_IMGEDT_BRUSH_L2, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(2, IMG_ID_IMGEDT_BRUSH_L3, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(3, IMG_ID_IMGEDT_BRUSH_L4, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(4, IMG_ID_IMGEDT_BRUSH_L5, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        switch (m_penSizeIndx)
        {
        case PEN_SIZE_L1:
            btnId = BOTTOM_BTN_L2_1;
            break;   
        case PEN_SIZE_L2:
            btnId = BOTTOM_BTN_L2_2;
            break;
        case PEN_SIZE_L3:
            btnId = BOTTOM_BTN_L2_3;
            break;
        case PEN_SIZE_L4:
            btnId = BOTTOM_BTN_L2_4;
            break;
        case PEN_SIZE_L5:
            btnId = BOTTOM_BTN_L2_5;
            break;
        default:
            VFX_ASSERT(0);
        }
    }
    else
    {
        //set L2 as erase size icon
        m_bottomBar->resetItemImage(0, IMG_ID_IMGEDT_ERASE_L1, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(1, IMG_ID_IMGEDT_ERASE_L2, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(2, IMG_ID_IMGEDT_ERASE_L3, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(3, IMG_ID_IMGEDT_ERASE_L4, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        m_bottomBar->resetItemImage(4, IMG_ID_IMGEDT_ERASE_L5, VcpImgEdtBottomBar::BOTTOM_BTN_L2);
        
        switch (m_eraseSizeIndx)
        {
        case ERASE_SIZE_L1:
            btnId = BOTTOM_BTN_L2_1;
            break;   
        case ERASE_SIZE_L2:
            btnId = BOTTOM_BTN_L2_2;
            break;
        case ERASE_SIZE_L3:
            btnId = BOTTOM_BTN_L2_3;
            break;
        case ERASE_SIZE_L4:
            btnId = BOTTOM_BTN_L2_4;
            break;
        case ERASE_SIZE_L5:
            btnId = BOTTOM_BTN_L2_5;
            break;
        default:
            VFX_ASSERT(0);
        }        
    }
    m_bottomBar->setDownState(VFX_FALSE, btnId);
}

void VappImgEdtDoodlePage::createColorSelector()
{
    VFX_OBJ_CREATE_EX(m_selectPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_COLOR));
    m_selectPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_COLOR));
    m_selectPopup->setContentProvider(&m_colorProvider);
    m_selectPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_COLOR));
    m_selectPopup->show(VFX_TRUE);
    m_selectPopup->m_selectIcon.connect(this, &VappImgEdtDoodlePage::onColorSelected);
    m_selectPopup->m_signalPopupState.connect(this, &VappImgEdtDoodlePage::onPopupStateChanged);
    m_selectPopup->setFocus(m_colorIndx);
}

void VappImgEdtDoodlePage::onColorSelected(VfxS32 pos)
{
    m_colorIndx = pos;
    m_iesHdlr->doodleSetColor(g_imgedt_text_color_list[pos]);
	startStroke();
}

void VappImgEdtDoodlePage::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (VFX_BASE_POPUP_BEFORE_START_ANIMATION == state)
    {
        endStroke();
    }
    else if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        //startStroke();
    }
}

void VappImgEdtDoodlePage::onStateChange(PageState state)
{
    VappImgEdtBasePage::onStateChange(state);
    
    switch(state)
    {
    case STATE_FULL_SCREEN:
        m_bottomBar->setHidden(VFX_TRUE);
        updateStroke();
        break;

    case STATE_WITH_PANEL:  
        m_bottomBar->setHidden(VFX_FALSE);
        m_bottomBar->bringToFront();
        updateStroke();
        break;

    default:
        VFX_ASSERT(state);
    }    
}

void VappImgEdtDoodlePage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect;
    VfxS32 ret = 0;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        m_iesHdlr->doodleEnd(VFX_TRUE);
        getMainScr()->popPage();
        break;
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        m_iesHdlr->doodleEnd(VFX_FALSE);
        getMainScr()->popPage();
        break;
    case BOTTOM_BTN_SHOW_SIZE:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            m_activeBtn = BOTTOM_BTN_SHOW_SIZE;
            updateBottomBarL2(VFX_TRUE);
            m_bottomBar->setVisibleMode(VFX_TRUE);
            m_bottomBar->clearDownState(VFX_TRUE, BOTTOM_BTN_SHOW_SIZE);
            updateStroke();
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }        
        break;

    case BOTTOM_BTN_SHOW_COLOR:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            updateStroke();
            endStroke();
            createColorSelector();
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }  
        
        break;

    case BOTTOM_BTN_SHOW_ERASE:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            m_activeBtn = BOTTOM_BTN_SHOW_ERASE;
            updateBottomBarL2(VFX_FALSE);
            m_bottomBar->setVisibleMode(VFX_TRUE);
            m_bottomBar->clearDownState(VFX_TRUE, BOTTOM_BTN_SHOW_ERASE);
            updateStroke();
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }        
        break;
        
    case BOTTOM_BTN_L2_5:
        if (BOTTOM_BTN_SHOW_SIZE == m_activeBtn)
        {
            setDoodleSize(VFX_TRUE, PEN_SIZE_L5);
        }
        else if(BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
        {
            setDoodleSize(VFX_FALSE, ERASE_SIZE_L5);
        }
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_L2_5);
        break;
        
    case BOTTOM_BTN_L2_4:
        if (BOTTOM_BTN_SHOW_SIZE == m_activeBtn)
        {
            setDoodleSize(VFX_TRUE, PEN_SIZE_L4);
        }
        else if(BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
        {
            setDoodleSize(VFX_FALSE, ERASE_SIZE_L4);
        }
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_L2_4);
        break;

    case BOTTOM_BTN_L2_3:
        if (BOTTOM_BTN_SHOW_SIZE == m_activeBtn)
        {
            setDoodleSize(VFX_TRUE, PEN_SIZE_L3);
        }
        else if(BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
        {
            setDoodleSize(VFX_FALSE, ERASE_SIZE_L3);
        }
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_L2_3);
        break;
        
    case BOTTOM_BTN_L2_2:
        if (BOTTOM_BTN_SHOW_SIZE == m_activeBtn)
        {
            setDoodleSize(VFX_TRUE, PEN_SIZE_L2);
        }
        else if(BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
        {
            setDoodleSize(VFX_FALSE, ERASE_SIZE_L2);
        }
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_L2_2);
        break;
        
    case BOTTOM_BTN_L2_1:
        if (BOTTOM_BTN_SHOW_SIZE == m_activeBtn)
        {
            setDoodleSize(VFX_TRUE, PEN_SIZE_L1);
        }
        else if(BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
        {
            setDoodleSize(VFX_FALSE, ERASE_SIZE_L1);
        }
        m_bottomBar->clearDownState(VFX_FALSE, BOTTOM_BTN_L2_1);
        break;
        
    default:
        break;
    }    
}

VfxBool VappImgEdtDoodlePage::onPenInput(VfxPenEvent &event)
{

    VfxBool bRet = VFX_FALSE;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        if (m_bAdjustState)
        {
            VappImgEdtBasePage::onPenInput(event);
        }
        bRet = VFX_TRUE;
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        if (m_bAdjustState)
        {
            bRet = VappImgEdtBasePage::onPenInput(event);
        }
        break;

    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_UP:
        if (m_bAdjustState)
        {
            bRet = VappImgEdtBasePage::onPenInput(event);;
        }
        break;

    case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
        if (!m_bAdjustState)
        {
            doodleCommand(event.pos, event.pos);
            if (0 != doodleRender(VFX_TRUE))
            {
                bRet = VFX_FALSE;
                break;
            }
        }
        bRet = VFX_TRUE;
        break;
        
    case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
        if ((abs(m_lastDoodlePos.x - event.pos.x) >= IMGEDT_DOOLE_MOVE_MIN_RADIUS) ||
            (abs(m_lastDoodlePos.y - event.pos.y) >= IMGEDT_DOOLE_MOVE_MIN_RADIUS))
        {
            doodleCommand(m_lastDoodlePos, event.pos);
            if (0 != doodleRender(VFX_FALSE))
            {
                bRet = VFX_FALSE;
                break;
            }
        }            
        if (STATE_WITH_PANEL == m_pageState)
        {
            if (m_bottomBar->getRect().contains(event.pos))
            {
                onStateChange(STATE_FULL_SCREEN); 
            }
        }
        bRet = VFX_TRUE;
        break;
        
    case VFX_PEN_EVENT_TYPE_STROKE_UP:
        //call updateStroke, and FW will send PEN_DOWN event every time.
        updateStroke();
        if (0 != doodleRender(VFX_TRUE))
        {
           bRet = VFX_FALSE;
        }
        else
        {
            bRet = VFX_TRUE;
        }
            
    default:
        break;
    }

    VAPP_IMGEDT_INFO_TRACE(bRet);
    return bRet;
}

VfxS32 VappImgEdtDoodlePage::doodleCommand(VfxPoint start, VfxPoint end)
{
    VfxS32 ret;
    m_lastDoodlePos = end;
    if (BOTTOM_BTN_SHOW_ERASE == m_activeBtn)
    {
        ret = m_iesHdlr->doodleErase(start, end, m_eraseSize[m_eraseSizeIndx]);
    }
    else
    {
        ret = m_iesHdlr->doodleDraw(start, end);
    }
    return ret;
}

VfxS32 VappImgEdtDoodlePage::doodleRender(VfxBool forceRender)
{
    
    VfxBool isUpdate = forceRender ? VFX_TRUE : VFX_FALSE;
    if (isUpdate)
    {
        kal_get_time((kal_uint32*)&m_lastUpdateTick);
        VAPP_IMGEDT_INFO_TRACE(m_lastUpdateTick);
    }
    else
    {
        VfxU32  curTick;
        kal_get_time((kal_uint32*)&curTick);
        if (curTick - m_lastUpdateTick >= IMGEDT_DOODLE_UPDATE_INTERVAL)
        {
            isUpdate = VFX_TRUE;
            m_lastUpdateTick = curTick;
            VAPP_IMGEDT_INFO_TRACE(m_lastUpdateTick);
        }
    } 

    VfxS32 ret = m_iesHdlr->doodleRenderPreview(isUpdate);
    if (ret < 0)
    {
        VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
        onErrorPopup(strId);
    }
    return ret;
}

VfxS32 VappImgEdtDoodlePage::setAjustStateEnd()
{
    VfxS32 ret = 0;
    if (m_bAdjustState)
    {       
        //entry Doodle begin mode
        ret = m_iesHdlr->doodleBegin(m_penSize[m_penSizeIndx], g_imgedt_text_color_list[0]);
        if (0 == ret)
        {
            m_bAdjustState = MMI_FALSE;
            deleteZoomSlider();
            m_iesHdlr->getScrnArea(&m_bgRange);
            startStroke();
        }
    }
    return ret;
}

void VappImgEdtDoodlePage::startStroke()
{    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_START_STROKE, m_bStrokeMode, __LINE__);
    if (m_bStrokeMode)
    {
        return;
    }
    VfxPenStrokeHandWritingRegion area;
    getStrokeRect(area);

    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->startCaptureStrokes(this, m_strokePoint, 10, &area, 1); 
    m_bStrokeMode = VFX_TRUE;
    
    //set preview page unhittable
    m_iesHdlr->getPreviewInternal()->setIsUnhittable(VFX_TRUE);
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_START_STROKE, m_bStrokeMode, __LINE__);
}

void VappImgEdtDoodlePage::updateStroke()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_START_STROKE, m_bStrokeMode, __LINE__);
    if (!m_bStrokeMode)
    {
        return;
    }
    VfxPenStrokeHandWritingRegion area;
    getStrokeRect(area);

    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->changeHandWritingArea(this, &area, 1, NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_START_STROKE, m_bStrokeMode, __LINE__);
}

void VappImgEdtDoodlePage::endStroke()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_END_STROKE, m_bStrokeMode, __LINE__);
    if (!m_bStrokeMode)
    {
        return;
    }
    VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
    penService->stopCaptureStrokes(this);
    m_bStrokeMode = VFX_FALSE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_END_STROKE, m_bStrokeMode, __LINE__);
}

void VappImgEdtDoodlePage::getStrokeRect(VfxPenStrokeHandWritingRegion &area)
{
    area.x1 = m_bgRange.getX();
    area.y1 = m_bgRange.getY();
    area.x2 = m_bgRange.getMaxX();
    area.y2 = m_bgRange.getMaxY(); 

    if (STATE_WITH_PANEL == m_pageState)
    {
        if (m_bgRange.getMaxY() > m_bottomBar->getRect().getY())
        {
            area.y2 -= (m_bgRange.getMaxY() - m_bottomBar->getRect().getY());
        }
    }  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_GET_STROKE_AREA, area.x1, area.y1, area.x2, area.y2);
}


VFX_IMPLEMENT_CLASS("VappImgEdtDoodlePage2", VappImgEdtDoodlePage2, VappImgEdtDoodlePage);

void VappImgEdtDoodlePage2::enterDoodlePage2(VappImgEdtBasePage **page, VfxObject* parent, void *param)
{
    VFX_OBJ_CREATE(*page, VappImgEdtDoodlePage2, parent);
}

VappImgEdtDoodlePage2::VappImgEdtDoodlePage2()
{
}

void VappImgEdtDoodlePage2::createBottomBar()
{
    //create panel
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setBgSize(VfxSize(m_scrnSize.width, IMGEDT_BOTTOM_BAR_HEIGHT * 2));    
    m_bottomBar->setTranslucent(VFX_TRUE);

    m_bottomBar->addItem(BOTTOM_BTN_SHOW_SIZE, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_SIZE, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L2,
                         VFX_FALSE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_COLOR, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_COLOR, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L2,
                         VFX_FALSE);
    m_bottomBar->addItem(BOTTOM_BTN_SHOW_ERASE, 
                         IMG_ID_IMGEDT_BOTTOMBAR_BRUSH_ERASER, 
                         VcpImgEdtBottomBar::BOTTOM_BTN_L2,
                         VFX_FALSE);
    
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtDoodlePage2::onBottomBtnClicked);
    m_bottomBar->show();
    m_bottomBar->setVisibleMode(MMI_TRUE);
}

void VappImgEdtDoodlePage2::createSelector(DoodleSelectType type)
{
    switch(type)
    {
    case SELECT_PEN_COLOR:
        VFX_OBJ_CREATE_EX(m_selectPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_COLOR));
        m_selectPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_COLOR));
        m_selectPopup->setContentProvider(&m_colorProvider);
        m_selectPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_COLOR));
        m_selectPopup->show(VFX_TRUE);
        m_selectPopup->m_selectIcon.connect(this, &VappImgEdtDoodlePage2::onColorSelected);
        m_selectPopup->m_signalPopupState.connect(this, &VappImgEdtDoodlePage2::onPopupStateChanged);
        m_selectPopup->setFocus(m_colorIndx);
        break;

    case SELECT_PEN_SIZE:
        VFX_OBJ_CREATE_EX(m_selectPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_DOODLE));
        m_selectPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_PEN));
        m_selectPopup->setContentProvider(&m_penProvider);
        m_selectPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_PEN_SIZE));
        m_selectPopup->show(VFX_TRUE);
        m_selectPopup->m_selectIcon.connect(this, &VappImgEdtDoodlePage2::onPenSelected);
        m_selectPopup->m_signalPopupState.connect(this, &VappImgEdtDoodlePage2::onPopupStateChanged);
        m_selectPopup->setFocus(m_penSizeIndx);
        break;

    case SELECT_ERASE_SIZE:
        VFX_OBJ_CREATE_EX(m_selectPopup, VcpImgEdtMattsPopup, this, (IMGEDT_MATTS_DOODLE));
        m_selectPopup->setContentSize(VfxSize(IMGEDT_MATTS_AREA_WIDTH, IMGEDT_MATTS_AREA_HEIGHT_ERASE));
        m_selectPopup->setContentProvider(&m_eraseProvider);
        m_selectPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_ERASE_SIZE));
        m_selectPopup->show(VFX_TRUE);
        m_selectPopup->m_selectIcon.connect(this, &VappImgEdtDoodlePage2::onEraseSelected);
        m_selectPopup->m_signalPopupState.connect(this, &VappImgEdtDoodlePage2::onPopupStateChanged);
        m_selectPopup->setFocus(m_eraseSizeIndx);
        break;

    default:
        VFX_ASSERT(0);
    }    
}

void VappImgEdtDoodlePage2::onPenSelected(VfxS32 pos)
{
    setDoodleSize(VFX_TRUE, pos);
	startStroke();
}

void VappImgEdtDoodlePage2::onEraseSelected(VfxS32 pos)
{
    setDoodleSize(VFX_FALSE, pos);
	startStroke();
}

void VappImgEdtDoodlePage2::onBottomBtnClicked(VfxObject *obj, VfxId id)
{
    VfxRect rect;
    VfxS32 ret;
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        m_iesHdlr->doodleEnd(VFX_TRUE);
        getMainScr()->popPage();
        break;
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        m_iesHdlr->doodleEnd(VFX_FALSE);
        getMainScr()->popPage();
        break;
    case BOTTOM_BTN_SHOW_SIZE:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            m_activeBtn = BOTTOM_BTN_SHOW_SIZE;
            updateStroke();
            //endStroke must called after udpateStoke
            endStroke();
            createSelector(SELECT_PEN_SIZE);
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }
        break;

    case BOTTOM_BTN_SHOW_COLOR:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            updateStroke();
            //endStroke must called after udpateStoke
            endStroke();
            createSelector(SELECT_PEN_COLOR);
        } 
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }        
        break;

    case BOTTOM_BTN_SHOW_ERASE:
        ret = setAjustStateEnd();
        if (0 == ret)
        {
            m_activeBtn = BOTTOM_BTN_SHOW_ERASE;
            updateStroke();
            //endStroke must called after udpateStoke
            endStroke();
            createSelector(SELECT_ERASE_SIZE);
        }
        else
        {
            VfxResId strId = m_iesHdlr->getErrorString((srv_ies_result)ret);
            onErrorPopup(strId);
        }
        break;
       
    default:
        break;
    }    
}

#define __IMGEDT_CP_MATTS_PENAL__
VcpBaseMenuLayout::ScrollDirEnum VcpImgEdtMattsLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}

void VcpImgEdtMattsLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
}


VfxS32 VcpImgEdtMattsLayout::getGroupCount()
{
    return 1;
}
    
VfxS32 VcpImgEdtMattsLayout::getCellCount(VfxS32 group)
{
    if (group == 0)
    {
        return m_cellCount;
    }            
    return 0;
}

VfxS32 VcpImgEdtMattsLayout::getContentLength()
{
    return ((getCellCount(0) + m_cellColCount - 1) / m_cellColCount) * (m_cellSize.height + m_cellGapSize.height);
}

VcpMenuRegion VcpImgEdtMattsLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
                getCellByPos(r.origin),
                getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
                );
}

VfxRect VcpImgEdtMattsLayout::queryCellRect(VcpMenuPos pos)
{
    VFX_DEV_ASSERT(pos.isValid());
    VFX_DEV_ASSERT(!pos.isGroupHeader());

    VfxRect rect;
    VfxS32  row, col;
    
    row = pos.pos / m_cellColCount;
    col = pos.pos % m_cellColCount;
    
   rect = VfxRect(
        m_cellGapSize.width + (m_cellGapSize.width + m_cellSize.width) * col,
        m_cellGapSize.height + (m_cellGapSize.height + m_cellSize.height) * row,
        m_cellSize.width,
        m_cellSize.height);

   return rect;
}
    
void VcpImgEdtMattsLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = 0;
    margin[1] = 0;
    margin[2] = 0;
    margin[3] = 0;
}

VcpMenuPos VcpImgEdtMattsLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    VfxS32 row, col;
    
    p.group = 0;
   
    row = pt.y / (m_cellGapSize.height + m_cellSize.height);
    col = pt.x / (m_cellGapSize.width + m_cellSize.width);
    if (col >= m_cellColCount)
    {
        col = m_cellColCount;
    }
    else if (col < 0)
    {
        col = 0;
    }

    p.pos = row * m_cellColCount + col;

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

void VcpImgEdtMattsLayout::setCellCount(VfxS32 count)
{
   m_cellCount = count;
}

void VcpImgEdtMattsLayout::setCellSize(VfxSize size)
{
    m_cellSize = size; 
}

void VcpImgEdtMattsLayout::setColCount(VfxS32 col)
{
    m_cellColCount = col;
}

void VcpImgEdtMattsLayout::setCellGaps(VfxSize size)
{
    m_cellGapSize = size;
}

VcpImgEdtMattsPanel::VcpImgEdtMattsPanel(VfxS32 style):
VcpBaseMenu(),
m_contentProvider(NULL),
m_focusPos(-1),
m_style(style)
{
}

void VcpImgEdtMattsPanel::onInit()
{
    VcpBaseMenu::onInit();
    enableVerticalScrollIndicator(VFX_TRUE);
}

void VcpImgEdtMattsPanel::setContentProvider(IVcpImgEdtMattsCellProvider *contentProvider)
{
    m_contentProvider = contentProvider;
}

void VcpImgEdtMattsPanel::setFocus(VfxS32 index)
{
    VFX_ASSERT(index >= 0);
    m_focusPos = index;
    getLayout()->setFocusItem(VcpMenuPos(0, m_focusPos), VFX_TRUE);
}

VcpImgEdtMattsLayout* VcpImgEdtMattsPanel::createLayout()
{
    VcpImgEdtMattsLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VcpImgEdtMattsLayout, this, (this));

    // Not good programme constructure, but for QVGA urgent design change. 
    VfxS32  colCount = 0, cellCount = 0;
    switch (m_style)
    {
    case IMGEDT_MATTS_COLOR:
        cellCount = IMGEDT_TEXT_COLOR_COUNT;
        colCount = IMGEDT_MATTS_COL_COUNT;
        m_cellSize = VfxSize(IMGEDT_MATTS_CELL_WIDTH, IMGEDT_MATTS_CELL_HEIGHT);
        break;

    case IMGEDT_MATTS_CLIPART:
        cellCount = IMGEDT_CLIPART_COUNT;
        colCount = IMGEDT_MATTS_COL_COUNT;
        m_cellSize = VfxSize(IMGEDT_MATTS_CELL_WIDTH, IMGEDT_MATTS_CELL_HEIGHT);
        break;

    case IMGEDT_MATTS_DOODLE:
        cellCount = 5;
        colCount = 3;
        m_cellSize = VfxSize(63, 63);
        break;

    default:
        ASSERT(0);
        break;
        
    }

    layout->setCellSize(m_cellSize);
    layout->setCellCount(cellCount);
    layout->setColCount(colCount);
    layout->setCellGaps(VfxSize(IMGEDT_MATTS_CELL_GAPS, IMGEDT_MATTS_CELL_GAPS));
        
    return layout;
}
    
VfxFrame* VcpImgEdtMattsPanel::createCell(VfxS32 group, VfxS32 pos)
{    
    VcpBaseMenuLayout* layout = getLayout();
    VcpMenuPos p(group, pos);

    VfxFrame *cell;
    VFX_OBJ_CREATE(cell, VfxFrame, this);
    VcpMenuPos focusPos = layout->getFocusItem();
    if (focusPos.pos == pos)
    {
        cell->setBorderColor(IMGEDT_HIGHLIGHT_CELL_COLOR);
    }
    else
    {

        cell->setBorderColor(IMGEDT_MATTS_CELL_BORDER_COLOR);
    }    
    m_contentProvider->getImageContent(pos, cell);
    cell->setBorderWidth(1);
    cell->setSize(m_cellSize);
    cell->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        
    VfxRect r = layout->queryCellRect(p);
            
    cell->setPos(VfxPoint(r.getX(), r.getY()));
    return cell;
}
    
void VcpImgEdtMattsPanel::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}
    
void VcpImgEdtMattsPanel::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VfxFrame *prevCell = getCellIfPresent(0, previousFocusItem.pos);
    if (NULL != prevCell)
    {
        prevCell->setBorderColor(IMGEDT_MATTS_CELL_BORDER_COLOR);
    }
    VfxFrame *focusCell = getCellIfPresent(0, focusItem.pos);
    if (NULL != focusCell)
    {
        focusCell->setBorderColor(IMGEDT_HIGHLIGHT_CELL_COLOR);
    }
    else
    {
        return ;
    }
}
    
void VcpImgEdtMattsPanel::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
}

void VcpImgEdtMattsPanel::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    m_focusPos = pos;
    getLayout()->setFocusItem(VcpMenuPos(group, pos), VFX_TRUE);
    m_tapCell.emit(pos, cell);
}
    
void VcpImgEdtMattsPanel::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    getLayout()->setFocusItem(VcpMenuPos(0, m_focusPos), VFX_FALSE);
}

void VcpImgEdtMattsPanel::onTouchCell(VcpMenuPos cellPos,CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell)
{
    switch(touchType)
    {
    case TouchDown:
        getLayout()->setFocusItem(cellPos, VFX_TRUE);
        break;
        
    case TouchUp:
        getLayout()->setFocusItem(VcpMenuPos(0, m_focusPos),  VFX_FALSE);
        break;
        
    case TouchTap:
    case TouchLongTap:
        break;
    }
}


VcpImgEdtMattsPopup::VcpImgEdtMattsPopup(VfxS32 style) :
VfxBasePopup(),
m_backgroundTop(NULL),
m_titleFrame(NULL),
m_style(style),
m_upRegionHeight(VCP_SELECT_POPUP_UP_HEIGHT),
m_bottomRegionHeight(0)
{
}

void VcpImgEdtMattsPopup::onInit()
{
    VfxBasePopup::onInit();

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 width;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0)
    {
        width = IMGEDT_POPUP_POPUP_WIDTH_VERT;
    }
    else
    {
        width = IMGEDT_POPUP_POPUP_WIDTH_VERT;
    } 

    setBounds(0, 0, width, VCP_SELECT_POPUP_UP_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this);
    m_backgroundTop->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    m_backgroundTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundTop->setBounds(0, 0, width, VCP_SELECT_POPUP_UP_HEIGHT);
    m_backgroundTop->setIsCached(VFX_TRUE);
    m_backgroundTop->setAutoAnimate(VFX_TRUE);
    m_backgroundTop->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    m_backgroundBottom->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_backgroundBottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setPos(0, m_upRegionHeight);

    VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, m_backgroundTop);
    m_titleFrame->setRect(VCP_SELECT_POPUP_TEXT_X, VCP_SELECT_POPUP_TEXT_Y, VCP_SELECT_POPUP_TEXT_WIDTH, 20);
    m_titleFrame->setAnchor(0.5,0.5);
    m_titleFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_titleFrame->setColor(VfxColor(255,255,255,255));
    m_titleFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_titleFrame->setAutoAnimate(VFX_TRUE);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_SELECT_POPUP_TEXT_SIZE);
    m_titleFrame->setFont(fontDesc);
    m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    VFX_OBJ_CREATE_EX(m_matts, VcpImgEdtMattsPanel, m_backgroundBottom, (m_style));
    m_matts->setAnchor(0.5f, 0.0f);
    m_matts->m_tapCell.connect(this, &VcpImgEdtMattsPopup::onTapIconCell);

    //add cancel button
    VFX_OBJ_CREATE(m_cancelButton, VcpButton, m_backgroundBottom);    
    m_cancelButton->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_cancelButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_cancelButton->setRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                0,
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                             ));
    m_cancelButton->m_signalClicked.connect(this, &VcpImgEdtMattsPopup::onButtonClick);
    m_cancelButton->setStyle(VCP_BUTTON_STYLE_GREY);
    m_cancelButton->setTextColor(VfxColor(255,255,255,255));
    m_cancelButton->setMargin(VCP_CONFIRM_POPUP_TEXT_LEFT_MARGIN, 0, 0, 0);
}

VfxBool VcpImgEdtMattsPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        onButtonClick(m_cancelButton, 0);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}


void VcpImgEdtMattsPopup::setContentSize(VfxSize contentSize)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 width;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0)
    {
        width = IMGEDT_POPUP_POPUP_WIDTH_VERT;
    }
    else
    {
        width = IMGEDT_POPUP_POPUP_WIDTH_VERT;
    } 
    m_matts->setPos(width>>1, 0);
    m_matts->setBounds(VfxRect(0, 0, contentSize.width, contentSize.height));
    VfxS32 curHeight = contentSize.height + IMGEDT_MATTS_CELL_GAPS;
    m_cancelButton->setPos(VCP_CONFIRM_POPUP_BUTTON_X, curHeight);
    
    curHeight += VCP_CONFIRM_POPUP_BUTTON_HEIGHT;
    curHeight += VCP_SELECT_POPUP_BOTTOM_HEIGHT;
    m_backgroundBottom->setBounds(0, 0, width, curHeight);

    curHeight += VCP_SELECT_POPUP_UP_HEIGHT;
    setBounds(0, 0, width, curHeight);
}

void VcpImgEdtMattsPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    m_signalMattsPopupCancel.emit();
    leave(VFX_TRUE);
}

void VcpImgEdtMattsPopup::setFocus(VfxS32 index)
{
    m_matts->setFocus(index);
}

void VcpImgEdtMattsPopup::setTitle(const VfxWString &text)
{
    m_titleFrame->setString(text);
}

const VfxWString& VcpImgEdtMattsPopup::getTitle() const
{
    return m_titleFrame->getString();
}

void VcpImgEdtMattsPopup::setContentProvider(IVcpImgEdtMattsCellProvider *contentProvider)
{
    m_matts->setContentProvider(contentProvider);
}


void VcpImgEdtMattsPopup::onTapIconCell(VfxS32 pos, VfxFrame* cell)
{
    m_selectIcon.emit(pos);
    leave(VFX_TRUE);
}

VcpImgEdtInfoBalloon::VcpImgEdtInfoBalloon():
m_arrowPos(0,0)
{
}

void VcpImgEdtInfoBalloon::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_backgroundLeft, VfxFrame, this);
    m_backgroundLeft->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundLeft->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALLOON_LEFT));
    m_backgroundLeft->setPos(0, 0);

    VFX_OBJ_CREATE(m_backgroundCenter, VfxFrame, this);
    m_backgroundCenter->setBounds(VfxRect(0, 0, IMGEDT_BALLOON_ARROW_WIDTH, IMGEDT_BALLOON_ARROW_HEIGHT));
    m_backgroundCenter->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundCenter->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALLOON_CENTER));

    VFX_OBJ_CREATE(m_backgroundRight, VfxFrame, this);
    m_backgroundRight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundRight->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALLOON_RIGHT));
    
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    m_textFrame->setAnchor(0.5f, 0.5f);
    m_textFrame->setColor(IMGEDT_BALLOON_FONT_COLOR);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(IMGEDT_BALLOON_FONT_SIZE);
    m_textFrame->setFont(fontDesc);
}

void VcpImgEdtInfoBalloon::setInfo(const VfxPoint &arrow, const VfxWString &str)
{
    m_textFrame->setString(str);
    m_arrowPos = arrow;
    updateLayout();
}

void VcpImgEdtInfoBalloon::updateLayout()
{
    if (m_arrowPos.isZero() || m_textFrame->getSize().isEmpty())
    {
        return;
    }

    VfxS32 textWidth = m_textFrame->getSize().width;
    VfxS32 totalWidth = textWidth + (IMGEDT_BALLOON_LR_MARGIN * 2);
    setBounds(0, 0, totalWidth, IMGEDT_BALLOON_ARROW_HEIGHT);
    setAnchor(0.5f, 0.0f);
    setPos(m_arrowPos.x, m_arrowPos.y - IMGEDT_BALLOON_ARROW_HEIGHT);

    VfxS32 leftWidth = (totalWidth - IMGEDT_BALLOON_ARROW_WIDTH)>>1;
    VfxS32 rightWidth = totalWidth - leftWidth - IMGEDT_BALLOON_ARROW_WIDTH;
    m_backgroundLeft->setBounds(0, 0, leftWidth, IMGEDT_BALLOON_LR_HEIGHT);
    m_backgroundCenter->setPos(leftWidth, 0);
    m_backgroundRight->setBounds(0, 0, rightWidth, IMGEDT_BALLOON_LR_HEIGHT);
    m_backgroundRight->setPos(leftWidth + IMGEDT_BALLOON_ARROW_WIDTH, 0);

    m_textFrame->setPos(getBounds().getMidX(), IMGEDT_BALLON_TEXT_HEIGHT);    
}


VcpImgEdtSavePopup::VcpImgEdtSavePopup():
m_resizeSlider(NULL),
m_maxText(NULL),
m_minText(NULL),
m_hintTextFrame2(NULL),
m_hintBalloon(NULL),
m_bSimpleMode(VFX_FALSE)
{
}

void VcpImgEdtSavePopup::onInit()
{
    VappFileNameEditorPopup::onInit();
    setTitle(VFX_WSTR_RES(STR_GLOBAL_SAVE));
    setHintText(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_PHOTO_NAME));

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0)
    {
        m_totalWidth = IMGEDT_SAVE_POPUP_WIDTH_VERT;
    }
    else
    {
        m_totalWidth = IMGEDT_SAVE_POPUP_WIDTH_HORZ;
    }
    VfxPoint ok_pos = m_okButton->getPos();    
    m_okButton->setText(VFX_WSTR_RES(STR_GLOBAL_SAVE));

    VfxSize size = VfxFrame::getSize();
    VfxS32 curHeight = ok_pos.y;

    // hint text
    VFX_OBJ_CREATE(m_hintTextFrame2, VfxTextFrame, this);
    m_hintTextFrame2->setString(VFX_WSTR_RES(STR_ID_VAPP_IMGEDT_PHOTO_SIZE));
    m_hintTextFrame2->setRect(VCP_INPUT_POPUP_TITLE_X, 
                             curHeight, 
                             VCP_INPUT_POPUP_TEXT_WIDTH, 
                             VCP_INPUT_POPUP_TEXT_HEIGHT);
    m_hintTextFrame2->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_HINT_TXT));
    m_hintTextFrame2->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_SELECT_POPUP_TEXT_SIZE);
    m_hintTextFrame2->setFont(fontDesc);

    //hint size:
    curHeight += (m_hintTextFrame2->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
    VFX_OBJ_CREATE(m_minText, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(IMGEDT_BALLOON_FONT_SIZE);
    m_minText->setFont(fontDesc);
    m_minText->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_HINT_TXT));
    m_minText->setPos(VCP_INPUT_POPUP_TITLE_X, curHeight);    
    m_minText->setAutoResized(VFX_TRUE);

    VFX_OBJ_CREATE(m_maxText, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(IMGEDT_BALLOON_FONT_SIZE);
    m_maxText->setFont(fontDesc);
    m_maxText->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_HINT_TXT));
    m_maxText->setPos(VCP_INPUT_POPUP_TITLE_X, curHeight); 
    m_maxText->setAutoResized(VFX_TRUE);

    VFX_OBJ_CREATE(m_hintBalloon, VcpImgEdtInfoBalloon, this);
    m_hintBalloon->setHidden(VFX_TRUE);

    //Slider
    curHeight += (m_minText->getBounds().getHeight() + 3);
    VFX_OBJ_CREATE(m_resizeSlider, VcpSlider, this);
    m_resizeSlider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_resizeSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_resizeSlider->setPos(VCP_INPUT_POPUP_TITLE_X, curHeight);
    m_resizeSlider->setLength(m_totalWidth - (VCP_INPUT_POPUP_TITLE_X * 2));
    m_resizeSlider->m_signalThumbPressed.connect(this, &VcpImgEdtSavePopup::onThumbPressed);
    m_resizeSlider->m_signalThumbDrag.connect(this, &VcpImgEdtSavePopup::onValueChanged);
    m_resizeSlider->m_signalThumbReleased.connect(this, &VcpImgEdtSavePopup::onThumbReleased);
    
    //button
    curHeight += (m_resizeSlider->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
    m_okButton->setPos(VCP_INPUT_POPUP_LR_GAP, curHeight);
    m_cancelButton->setPos(VCP_INPUT_POPUP_LR_GAP + VCP_INPUT_POPUP_BUTTON_WIDTH + VCP_INPUT_POPUP_BUTTON_GAP, curHeight);
    
    // set bounds
    curHeight += (VCP_INPUT_POPUP_BUTTON_HEIGHT + VCP_INPUT_POPUP_LR_GAP);

    checkUpdate();
}

void VcpImgEdtSavePopup::onUpdate()
{
    VappFileNameEditorPopup::onUpdate();

    if (!m_bSimpleMode)
    {
        VfxPoint ok_pos = m_okButton->getPos();    
        VfxPoint cancel_pos = m_cancelButton->getPos();
        VfxSize size = VfxFrame::getSize();
        VfxS32 curHeight = ok_pos.y;
        
        // hint text
        m_hintTextFrame2->setRect(VCP_INPUT_POPUP_TITLE_X, 
                                  curHeight, 
                                  VCP_INPUT_POPUP_TEXT_WIDTH, 
                                  VCP_INPUT_POPUP_TEXT_HEIGHT);
        
       //hint size
        curHeight += (m_hintTextFrame2->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
        VfxPoint textPos = m_minText->getPos();
        m_minText->setPos(textPos.x, curHeight);
        textPos = m_maxText->getPos();
        m_maxText->setPos(textPos.x, curHeight);
        
        //Slider
        curHeight += (m_minText->getBounds().getHeight() + 3);
        m_resizeSlider->setPos(VCP_INPUT_POPUP_TITLE_X, curHeight);
        if (m_minSize == m_maxSize)
        {
            m_resizeSlider->setOpacity(IMGEDT_BUTTON_DISABLE_OPACITY);
            m_resizeSlider->setSliderMode(VCP_SLIDER_MODE_NON_INTERACTIVE);
        }
           
        //button
        curHeight += (m_resizeSlider->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
        m_okButton->setPos(ok_pos.x, curHeight);
        m_cancelButton->setPos(cancel_pos.x, curHeight);
        
        VfxWString str;
        str.format("%dX%d", m_currSize.width, m_currSize.height);
        m_hintBalloon->setInfo(VfxPoint(m_totalWidth>>1, m_resizeSlider->getPos().y), str);
        
        // set bounds    
        curHeight += (VCP_INPUT_POPUP_BUTTON_HEIGHT + VCP_INPUT_POPUP_BOTTOM_GAP);
        m_background->setBounds(0, 0, m_totalWidth, curHeight - VCP_INPUT_POPUP_TITLE_HEIGHT);
        setBounds(0, 0, m_totalWidth, curHeight);
    }   
}

void VcpImgEdtSavePopup::setMaxSize(const VfxSize &maxSize)
{
    m_maxSize = maxSize;
    m_minSize = getMinSize(m_maxSize);
    m_currSize = m_maxSize;

    if (m_minSize == m_maxSize)
    {
        m_bSimpleMode = VFX_TRUE;
        m_resizeSlider->setHidden(VFX_TRUE);
        m_maxText->setHidden(VFX_TRUE);
        m_minText->setHidden(VFX_TRUE);
        m_hintTextFrame2->setHidden(VFX_TRUE);
        m_hintBalloon->setHidden(VFX_TRUE); 
    }
    else
    {
        m_bSimpleMode = VFX_FALSE;
        VfxWString str;
        str.format("%dX%d", m_minSize.width, m_minSize.height);
        m_minText->setString(str);

        str.format("%dX%d", m_maxSize.width, m_maxSize.height);
        m_maxText->setString(str);
        VfxPoint pos = m_minText->getPos();
        VfxRect textRect = m_maxText->getMeasureBounds();
        m_maxText->setPos(m_totalWidth - VCP_INPUT_POPUP_LR_GAP - textRect.getWidth(), pos.y);

        if (m_maxSize.width >= m_maxSize.height)
        {
            m_resizeSlider->setMaxValue(m_maxSize.height);
            m_resizeSlider->setMinValue(m_minSize.height);
            m_resizeSlider->setCurrentValue(m_maxSize.height);
        }
        else
        {
            m_resizeSlider->setMaxValue(m_maxSize.width);
            m_resizeSlider->setMinValue(m_minSize.width);
            m_resizeSlider->setCurrentValue(m_currSize.width);
        }
    }    
    onUpdate();
}

VfxSize VcpImgEdtSavePopup::getCurrSize()
{
    return m_currSize;
}


void VcpImgEdtSavePopup::onValueChanged(VcpSlider *obj, VfxFloat value)
{
    if (m_maxSize.width >= m_maxSize.height)
    {
        m_currSize.height = (VfxS32)value;
        m_currSize.width = (VfxS32)(m_currSize.height * m_maxSize.width / m_maxSize.height);
    }
    else
    {
        m_currSize.width = (VfxS32)value;
        m_currSize.height = (VfxS32)(m_currSize.width * m_maxSize.height / m_maxSize.width);
    }
    VfxWString str;
    str.format("%dX%d", m_currSize.width, m_currSize.height);
    m_hintBalloon->setInfo(VfxPoint(m_totalWidth>>1, m_resizeSlider->getPos().y), str);
}

void VcpImgEdtSavePopup::onThumbPressed(VcpSlider *obj, VfxFloat value)
{
    m_hintBalloon->setHidden(VFX_FALSE);
    onValueChanged(obj, value);
}

void VcpImgEdtSavePopup::onThumbReleased(VcpSlider *obj, VfxFloat value)
{
    m_hintBalloon->setHidden(VFX_TRUE);
}


VfxSize VcpImgEdtSavePopup::getMinSize(VfxSize maxSize)
{
    VfxSize minSize(0,0);
    VfxFloat factor;
    if (maxSize.width >= maxSize.height)
    {
        factor = (VfxFloat)maxSize.height/IMGEDT_RESIVE_MIN_LENGTH;
    }
    else
    {
        factor = (VfxFloat)maxSize.width/IMGEDT_RESIVE_MIN_LENGTH;
    }
    if (factor <= 1.0f)
    {
        minSize = maxSize;
    }
    else
    {
        if (maxSize.width >= maxSize.height)
        {
            minSize.height = IMGEDT_RESIVE_MIN_LENGTH;
            minSize.width = maxSize.width / factor;
        }
        else
        {
            minSize.width = IMGEDT_RESIVE_MIN_LENGTH;
            minSize.height = maxSize.height / factor;
        }  
    }
    return minSize;
}



#define __PHOEDT_CP_SCROLL_PENAL__

VcpImgEdtScrollLayout::VcpImgEdtScrollLayout(VcpBaseMenu* menu) : 
VcpBaseMenuLayout(menu),
m_offset(0, 0),
m_gaps(0)
{
}

void VcpImgEdtScrollLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
}

VcpBaseMenuLayout::ScrollDirEnum VcpImgEdtScrollLayout::getScrollDir()
{
    return m_style;
}

VfxS32 VcpImgEdtScrollLayout::getGroupCount()
{
    return 1;
}
    
VfxS32 VcpImgEdtScrollLayout::getCellCount(VfxS32 group)
{
    if (group == 0)
    {
        return m_cellCount;
    }            
    return 0;
}

VfxS32 VcpImgEdtScrollLayout::getContentLength()
{
    VfxS32 length;
    if (SCROLLDIR_HORZ == m_style)
    {
        length = getCellCount(0) * m_cellSize.width +
                 ((getCellCount(0) - 1) * m_gaps) + 
                 (2 * m_offset.x) - 1;
    }
    else
    {
        length = getCellCount(0) * m_cellSize.height +
                 ((getCellCount(0) - 1) * m_gaps) + 
                 (2 * m_offset.y) - 1;
    }
    return length;
}

VcpMenuRegion VcpImgEdtScrollLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
                getCellByPos(r.origin),
                getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
                );
}

VfxRect VcpImgEdtScrollLayout::queryCellRect(VcpMenuPos pos)
{
    VFX_DEV_ASSERT(pos.isValid());
    VFX_DEV_ASSERT(!pos.isGroupHeader());

    VfxRect rect;
    if (SCROLLDIR_HORZ == m_style)
    {
        rect = VfxRect(m_offset.x + pos.pos * (m_cellSize.width + m_gaps), 
                       m_offset.y, 
                       m_cellSize.width, 
                       m_cellSize.height);
    }
    else
    {
        rect = VfxRect(m_offset.x, 
                       m_offset.y  + pos.pos * (m_cellSize.height + m_gaps),
                       m_cellSize.width, 
                       m_cellSize.height);
    }
    return rect;
}
    
void VcpImgEdtScrollLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = 0;
    margin[1] = 0;
    margin[2] = 0;
    margin[3] = 0;
}

VcpMenuPos VcpImgEdtScrollLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;

    p.group = 0;
    if (SCROLLDIR_HORZ == m_style)
    {
        p.pos = (pt.x - m_offset.x) / (m_cellSize.width + m_gaps);
    }
    else
    {
        p.pos = (pt.y - m_offset.y) / (m_cellSize.height + m_gaps);
    }

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

void VcpImgEdtScrollLayout::setCellCount(VfxS32 count)
{
   m_cellCount = count;
}

void VcpImgEdtScrollLayout::setStyle(ScrollDirEnum style)
{
    m_style = style;
}

void VcpImgEdtScrollLayout::setCellSize(VfxSize size)
{
    m_cellSize = size; 
}

void VcpImgEdtScrollLayout::setGaps(VfxS32 gap)
{
    m_gaps = gap;
}
void VcpImgEdtScrollLayout::setOffset(VfxPoint offset)
{
    m_offset = offset;
}

VFX_IMPLEMENT_CLASS("VcpImgEdtScrollBtn", VcpImgEdtScrollBtn, VfxControl);

VcpImgEdtScrollBtn::VcpImgEdtScrollBtn():
m_index(0),
m_disabled(VFX_FALSE)
{
}

void VcpImgEdtScrollBtn::setIndex(VfxS32 pos)
{
    m_index = pos;
}

void VcpImgEdtScrollBtn::setDisabled(VfxBool bDisabled)
{
    m_disabled = bDisabled;
    if (m_disabled)
    {
        setOpacity(IMGEDT_BUTTON_DISABLE_OPACITY);
    }
    else
    {
        setOpacity(1.0f);
    }
}

VfxBool VcpImgEdtScrollBtn::getDisabled()
{
    return m_disabled;
}

void VcpImgEdtScrollBtn::onInit()
{
    VfxControl::onInit();

    VfxFrame::setSize(IMGEDT_SCROLL_BTN_WIDTH ,IMGEDT_SCROLL_BTN_HEIGHT);
}

VfxBool VcpImgEdtScrollBtn::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        
        break;

    case VFX_PEN_EVENT_TYPE_UP:
        break;

    case VFX_PEN_EVENT_TYPE_LONG_TAP:
        m_longTapCell.emit(event, m_index);
        break;
    }

    return getParentControl()->penInput(event);   
}

VcpImgEdtScrollPanel::VcpImgEdtScrollPanel(VfxBool bVertMode):
VcpBaseMenu(),
m_focusPos(0)
{
    m_bVertMode = bVertMode;
    for (VfxS32 i = 0; i < EDIT_TOTAL; i++)
    {
        m_edtBtn[i] = NULL;
        m_bgFrame[i] = NULL;
        m_disabled[i] = VFX_FALSE;
    }
}

void VcpImgEdtScrollPanel::setBtnDisabled(ScrollPanelEnum type, VfxBool bDisabled)
{
    m_disabled[type] = bDisabled;

    if (NULL != m_edtBtn[type])
    {
        if (bDisabled)
        {
            m_edtBtn[type]->setOpacity(IMGEDT_BUTTON_DISABLE_OPACITY);
        }
        else
        {
            m_edtBtn[type]->setOpacity(1.0f);
        }    
    }
}

void VcpImgEdtScrollPanel::onInit()
{
    VcpBaseMenu::onInit();
    enableHorizontalScrollIndicator(VFX_FALSE);
    enableVerticalScrollIndicator(VFX_FALSE);
}

VcpImgEdtScrollLayout* VcpImgEdtScrollPanel::createLayout()
{
    VcpImgEdtScrollLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VcpImgEdtScrollLayout, this, (this));
        
    layout->setCellSize(VfxSize(IMGEDT_TOP_BAR_BTN_WIDTH, IMGEDT_TOP_BAR_BTN_HEIGHT));
    layout->setCellCount(EDIT_TOTAL);
    if (m_bVertMode)
    {
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_HORZ);
    }
    else
    {
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_VERT);
    }         
    return layout;
}
    
VfxFrame* VcpImgEdtScrollPanel::createCell(VfxS32 group, VfxS32 pos)
{    
    VcpBaseMenuLayout* layout = getLayout();
    VcpMenuPos p(group, pos);

    VFX_OBJ_CREATE(m_bgFrame[pos], VfxFrame, this);
    m_bgFrame[pos]->setBounds(0, 0, IMGEDT_TOP_BAR_BTN_WIDTH, IMGEDT_TOP_BAR_BTN_HEIGHT);
    if (m_bVertMode)
    {        
        m_bgFrame[pos]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
    }
    else
    {
        m_bgFrame[pos]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_HORZ));
    }
    
    m_bgFrame[pos]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_edtBtn[pos], VfxImageFrame, this);

    VfxImageSrc img(m_scrollPanelInfo[pos].icon);
    m_edtBtn[pos]->setImgContent(img);
    m_edtBtn[pos]->setSize(IMGEDT_SCROLL_BTN_WIDTH ,IMGEDT_SCROLL_BTN_HEIGHT);
    if (m_disabled[pos])
    {
        m_edtBtn[pos]->setOpacity(IMGEDT_BUTTON_DISABLE_OPACITY);
    }
    else
    {
        m_edtBtn[pos]->setOpacity(1.0f);
    }
        
    VfxRect r = layout->queryCellRect(p);
            
    m_edtBtn[pos]->setPos(VfxPoint(r.getX(), r.getY()));
    m_bgFrame[pos]->setPos(r.getX(), r.getY());
    return m_edtBtn[pos];
}
    
void VcpImgEdtScrollPanel::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(m_bgFrame[pos]);
    VFX_OBJ_CLOSE(m_edtBtn[pos]);
    m_bgFrame[pos] = NULL;
    m_edtBtn[pos] = NULL;
}
    
void VcpImgEdtScrollPanel::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    m_focusPos = focusItem.pos;
}

void VcpImgEdtScrollPanel::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{               
    if (!m_disabled[pos])
    {
        getLayout()->setFocusItem(VcpMenuPos(group, pos));
        m_tapCell.emit(pos, cell);
    }   
}

void VcpImgEdtScrollPanel::onTouchCell(VcpMenuPos cellPos,CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell)
{
    if (m_disabled[cellPos.pos])
    {
        return;
    }
    
    switch(touchType)
    {
    case TouchDown:
        m_signalHighLight.emit(VFX_TRUE, cellPos.pos, cell);
        break;
        
    case TouchUp:
        m_signalHighLight.emit(VFX_FALSE, cellPos.pos, cell);
        break;

    case TouchTap:
        break;

    case TouchLongTap:
        if (m_focusPos != cellPos.pos)        
        {
            getLayout()->setFocusItem(VcpMenuPos(cellPos), VFX_TRUE);
        }
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(IMG_GLOBAL_INFO, VFX_WSTR_RES(m_scrollPanelInfo[cellPos.pos].strid));
        break;
    }
}

void VcpImgEdtScrollPanel::onDrag(VfxS32 xoffset,VfxS32 yoffset)
{
    m_signalHighLight.emit(VFX_FALSE, 0, NULL);
}
    
void VcpImgEdtScrollPanel::onLongTapCell(VfxPenEvent &event, VfxS32 pos)
{
    if (m_focusPos != pos)        
    {
        getLayout()->setFocusItem(VcpMenuPos(0, pos), VFX_TRUE);
    }
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    balloon->addItem(IMG_GLOBAL_INFO, VFX_WSTR_RES(m_scrollPanelInfo[pos].strid));
}

VcpImgEdtFramePanel::VcpImgEdtFramePanel(VfxBool bVertMode):
VcpBaseMenu(),
m_cellCount(0)    
{
    m_bVertMode = bVertMode;
}

void VcpImgEdtFramePanel::onInit()
{
    m_cellCount = IMGEDT_ADD_FRAME_COUNT + 1;

    VcpBaseMenu::onInit();
    enableHorizontalScrollIndicator(VFX_FALSE);
    enableVerticalScrollIndicator(VFX_FALSE);
}

VfxBool VcpImgEdtFramePanel::onKeyInput(VfxKeyEvent & event)
{
    VfxS32 index = m_layout->getFocusItem().pos;
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
    	if(m_bVertMode)
    	{
        	switch (event.keyCode)
        	{
        	case VFX_KEY_CODE_ARROW_LEFT:
            	if ((--index) >= 0)
            	{
                	onTapCell(0, index, m_frameCell[index]);
                	return VFX_TRUE;
            	}
            	break;
            
        	case VFX_KEY_CODE_ARROW_RIGHT:
            	if ((++index) <= IMGEDT_ADD_FRAME_COUNT)
            	{
            	    onTapCell(0, index, m_frameCell[index]);
                	return VFX_TRUE;
            	}
            	break;
            
        	default:
            	break;
        	}
    	}    
		else
		{
			switch (event.keyCode)
	        {
	        case VFX_KEY_CODE_ARROW_UP:
	            if ((--index) >= 0)
	            {
	                onTapCell(0, index, m_frameCell[index]);
	                return VFX_TRUE;
	            }
	            break;
	            
	        case VFX_KEY_CODE_ARROW_DOWN:
	            if ((++index) <= IMGEDT_ADD_FRAME_COUNT)
	            {
	                onTapCell(0, index, m_frameCell[index]);
	                return VFX_TRUE;
	            }
	            break;
	            
	        default:
	            break;
        	}
		}
    }    
    return VcpBaseMenu::onKeyInput(event);
}


VcpImgEdtScrollLayout* VcpImgEdtFramePanel::createLayout()
{
    VcpImgEdtScrollLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VcpImgEdtScrollLayout, this, (this));

    layout->setCellCount(m_cellCount);
    layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_HORZ);
    layout->setOffset(VfxPoint(IMGEDT_ADDFRAME_OFFSET_X, IMGEDT_ADDFRAME_OFFSET_Y));
    layout->setGaps(IMGEDT_ADDFRAME_CELL_GAPS);
    if (m_bVertMode)
    {
        layout->setCellSize(VfxSize(IMGEDT_ADDFRAME_CELL_WIDTH, IMGEDT_ADDFRAME_CELL_HEIGHT));
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_HORZ);
    }
    else
    {
        layout->setCellSize(VfxSize(IMGEDT_ADDFRAME_CELL_HEIGHT, IMGEDT_ADDFRAME_CELL_WIDTH));
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_VERT);
    }
    return layout;
}

void VcpImgEdtFramePanel::onAfterCreateLayout()
{
    VfxSize size = getLayoutContentSize();
    setBounds(VfxRect(0, 0, size.width, size.height));
}
    
VfxFrame* VcpImgEdtFramePanel::createCell(VfxS32 group, VfxS32 pos)
{    
    VcpBaseMenuLayout* layout = getLayout();
    VcpMenuPos p(group, pos);

    VFX_OBJ_CREATE(m_frameCell[pos], VfxFrame, this);
    VcpMenuPos focusPos = layout->getFocusItem();
    if (focusPos.pos == pos)
    {
        m_frameCell[pos]->setBorder(IMGEDT_HIGHLIGHT_CELL_COLOR, IMGEDT_HILIGHT_BORDER_WIDTH);
    }
    else
    {
        m_frameCell[pos]->setBorder(VRT_COLOR_WHITE, IMGEDT_HILIGHT_BORDER_WIDTH);
    }    
    VfxResId id = 0;
    if (pos > 0)
    {
        if (m_bVertMode)
        {
            id = IMG_ID_IMGEDT_FRAME_VERT_L1 + pos - 1;
        }
        else
        {
            id = IMG_ID_IMGEDT_FRAME_HORZ_L1 + pos - 1;
        }
    }
    if (0 != id)
    {
        VfxImageSrc img(id);
        m_frameCell[pos]->setImgContent(img);
    }
    m_frameCell[pos]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_frameCell[pos]->setBgColor(VRT_COLOR_WHITE);
    m_frameCell[pos]->setBorderWidth(IMGEDT_HILIGHT_BORDER_WIDTH);
    if (m_bVertMode)
    {
        m_frameCell[pos]->setSize(IMGEDT_ADDFRAME_CELL_WIDTH, IMGEDT_ADDFRAME_CELL_HEIGHT);
    }
    else
    {
        m_frameCell[pos]->setSize(IMGEDT_ADDFRAME_CELL_HEIGHT, IMGEDT_ADDFRAME_CELL_WIDTH);
    }   
    VfxRect r = layout->queryCellRect(p);
            
    m_frameCell[pos]->setPos(VfxPoint(r.getX(), r.getY()));
    return m_frameCell[pos];
}

void VcpImgEdtFramePanel::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}
    
void VcpImgEdtFramePanel::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VfxFrame *prevCell = getCellIfPresent(0, previousFocusItem.pos);
    if (NULL != prevCell)
    {
        prevCell->setBorderColor(VRT_COLOR_WHITE);
    }
    VfxFrame *focusCell = getCellIfPresent(0, focusItem.pos);
    if (NULL != focusCell)
    {
        focusCell->setBorderColor(IMGEDT_HIGHLIGHT_CELL_COLOR);
    }

}

void VcpImgEdtFramePanel::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
               
    getLayout()->setFocusItem(VcpMenuPos(group, pos));
    m_tapCell.emit(pos, cell);
}

VcpImgEdtEffectPanel::VcpImgEdtEffectPanel(VfxBool bVertMode)
:VcpBaseMenu(),
m_cellCount(0)
{
    m_bVertMode = bVertMode;
}

    
void VcpImgEdtEffectPanel::onInit()
{
    m_cellCount = IMGEDT_ADD_EFFECT_COUNT;

    VcpBaseMenu::onInit();
    enableHorizontalScrollIndicator(VFX_FALSE);
    enableVerticalScrollIndicator(VFX_FALSE);
}

VfxBool VcpImgEdtEffectPanel::onKeyInput(VfxKeyEvent & event)
{
    VfxS32 index = m_layout->getFocusItem().pos;
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        if(m_bVertMode)
        {
            switch (event.keyCode)
            {
            case VFX_KEY_CODE_ARROW_LEFT:
                if ((--index) >= 0)
                {
                    onTapCell(0, index, m_frameCell[index]);
                    return VFX_TRUE;
                }
                break;
            
            case VFX_KEY_CODE_ARROW_RIGHT:
                if ((++index) < VappImgEdtIesHdlr::EFFECT_TOTAL)
                {
                    onTapCell(0, index, m_frameCell[index]);
                    return VFX_TRUE;
                }
                break;
            
            default:
                break;
            }
        }  
		else
		{
			switch (event.keyCode)
	        {
	        case VFX_KEY_CODE_ARROW_UP:
	            if ((--index) >= 0)
	            {
	                onTapCell(0, index, m_frameCell[index]);
	                return VFX_TRUE;
	            }
	            break;
	            
	        case VFX_KEY_CODE_ARROW_DOWN:
	            if ((++index) < VappImgEdtIesHdlr::EFFECT_TOTAL)
	            {
	                onTapCell(0, index, m_frameCell[index]);
	                return VFX_TRUE;
	            }
	            break;
	            
	        default:
	            break;
			}
		}
    }    
    return VcpBaseMenu::onKeyInput(event);
}

VcpImgEdtScrollLayout* VcpImgEdtEffectPanel::createLayout()
{
    VcpImgEdtScrollLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VcpImgEdtScrollLayout, this, (this));
        
    layout->setCellSize(VfxSize(IMGEDT_ADDEFFECT_CELL_WIDTH, IMGEDT_ADDEFFECT_CELL_WIDTH));
    layout->setOffset(VfxPoint(IMGEDT_ADDEFFECT_OFFSET_X, IMGEDT_ADDEFFECT_OFFSET_Y));
    layout->setGaps(IMGEDT_ADDEFFECT_CELL_GAPS);
    layout->setCellCount(m_cellCount);
    if (m_bVertMode)
    {
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_HORZ);
    }
    else
    {
        layout->setStyle(VcpBaseMenuLayout::SCROLLDIR_VERT);
    } 
           
    return layout;
}
    
VfxFrame* VcpImgEdtEffectPanel::createCell(VfxS32 group, VfxS32 pos)
{    
    VcpBaseMenuLayout* layout = getLayout();
    VcpMenuPos p(group, pos);

    VFX_OBJ_CREATE(m_frameCell[pos], VfxFrame, this);
    VcpMenuPos focusPos = layout->getFocusItem();
    if (focusPos.pos == pos)
    {
        m_frameCell[pos]->setBorder(IMGEDT_HIGHLIGHT_CELL_COLOR, IMGEDT_HILIGHT_BORDER_WIDTH);
    }
    else
    {
        m_frameCell[pos]->setBorder(VRT_COLOR_WHITE, IMGEDT_HILIGHT_BORDER_WIDTH);
    } 
    VfxResId id = IMG_ID_IMGEDT_EFFECT_NONE + pos;
    VfxImageSrc img(id);
    m_frameCell[pos]->setImgContent(img);
    m_frameCell[pos]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_frameCell[pos]->setBgColor(VRT_COLOR_WHITE);
    m_frameCell[pos]->setSize(IMGEDT_ADDEFFECT_CELL_WIDTH, IMGEDT_ADDEFFECT_CELL_HEIGHT);
    
    VfxRect r = layout->queryCellRect(p);
            
    m_frameCell[pos]->setPos(VfxPoint(r.getX(), r.getY()));
    return m_frameCell[pos];
}

  
void VcpImgEdtEffectPanel::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}
    
void VcpImgEdtEffectPanel::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VfxFrame *prevCell = getCellIfPresent(0, previousFocusItem.pos);
    if (NULL != prevCell)
    {
        prevCell->setBorderColor(VRT_COLOR_WHITE);
    }
    VfxFrame *focusCell = getCellIfPresent(0, focusItem.pos);
    if (NULL != focusCell)
    {
        focusCell->setBorderColor(IMGEDT_HIGHLIGHT_CELL_COLOR);
    }
}

void VcpImgEdtEffectPanel::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{               
    getLayout()->setFocusItem(VcpMenuPos(group, pos));
    m_tapCell.emit(pos, cell);
}


/***************************************************************************** 
 * Class VcpImgEdtToolBar 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpImgEdtToolBar", VcpImgEdtToolBar, VfxPageBar);

VcpImgEdtToolBar::VcpImgEdtToolBar():
m_btnNum(0),
m_background(NULL),
m_btnSize(0, 0),
m_size(0, 0) 
{
}

void VcpImgEdtToolBar::addItem(VfxId btn_id,VfxResId button_icon)
{
    m_btnNum++;
    VFX_ASSERT(m_btnNum <= IMGEDT_TOOLBAR_MAX_BTNS_COUNT);

    VFX_OBJ_CREATE(m_btnArray[m_btnNum - 1], VcpImageButton, this);
    m_btnArray[m_btnNum - 1]->setId(btn_id);
    VcpStateImage imgList(button_icon,button_icon,button_icon,button_icon);
    m_btnArray[m_btnNum - 1]->setImage(imgList);
    m_btnArray[m_btnNum - 1]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_btnArray[m_btnNum - 1]->m_signalClicked.connect(this, &VcpImgEdtToolBar::onBtnClicked);
}

void VcpImgEdtToolBar::show()
{

    m_btnSize.width = m_size.width / m_btnNum;

    VfxFrame::setPos(VfxPoint(0, m_size.height- m_btnSize.height));
    VfxFrame::setBounds(VfxRect(0, 0, m_size.width, m_btnSize.height));

    VfxS32 posX = 0;
    VfxFrame *bg;
    for (VfxS32 i = 0; i < m_btnNum; i++)
    {       
        VfxS32 btn_w = m_btnSize.width;
        if (i == m_btnNum -1)
        {
            btn_w = m_size.width - posX + 1;
        }
        VFX_OBJ_CREATE(bg, VfxFrame, this);
        bg->setSize(btn_w, m_btnSize.height);
        bg->setPos(posX, 0);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BOTTOM_BAR));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        
        m_btnArray[i]->setPos(posX, 0);
        m_btnArray[i]->bringToFront();
        m_btnArray[i]->setSize(btn_w, m_btnSize.height);
        VfxImageSrc img = m_btnArray[i]->getImage().getImageNormal();
        VfxSize imgSize = img.getSize();
        VfxSize haloSize;
        VappImgEdtBaseScr::getHaloSize(imgSize, haloSize);
        m_btnArray[i]->setIsEffect(VFX_TRUE);
        m_btnArray[i]->setEffectSize(haloSize);

        posX += m_btnSize.width;
    }
}

void VcpImgEdtToolBar::setSize(VfxSize size)
{
    m_size = size;
}

void VcpImgEdtToolBar::setBtnHeight(VfxS32 height)
{
    m_btnSize.height = height;
}

void VcpImgEdtToolBar::onBtnClicked(VfxObject *obj, VfxId id)
{
    m_signalBtnTap.emit(obj, id);
}

void VcpImgEdtToolBar::setBtnDisabled(VfxId btn_id, VfxBool bDisabled)
{
    for (VfxS32 i = 0; i < m_btnNum; i++)
    { 
        if (btn_id == m_btnArray[i]->getId())
        {
            m_btnArray[i]->setIsDisabled(bDisabled);
            if (bDisabled)
            {
                m_btnArray[i]->setOpacity(IMGEDT_BUTTON_DISABLE_OPACITY);
            }
            else
            {
                m_btnArray[i]->setOpacity(1.0f);
            }
            break;
        }
    }
    
}

#else /* __MMI_COSMOS_PHOTOEDITOR__ */

// ------- dummy functions begin --------- //
extern "C"
{
#include "MMIDataType.h"
extern MMI_BOOL vapp_imgedt_is_file_support(const WCHAR *filePath){return MMI_TRUE;}
extern mmi_id vapp_imgedt_launch(void *param, U32 param_size){return 0;}
extern mmi_ret vapp_imgedt_package_proc(mmi_event_struct* param){return 0;}
}
// ------- dummy functions begin --------- //
#endif /* __MMI_COSMOS_PHOTOEDITOR__ */

// ------- dummy functions for pluto begin ------- //
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_PHOTOEDITOR__
extern "C" 
{

#include "MMIDataType.h"
#include "PhotoEditorGProt.h"
#include "photoeditorcuigprot.h"
#include "FileMgrSrvGprot.h"

extern void mmi_phoedt_file_type_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo){}

extern void mmi_phoedt_launch(void){}
extern mmi_ret mmi_phoedt_fmgr_notify_handler(mmi_event_struct *evt){return 0;}
extern void mmi_phoedt_hilight_app(void){}


void mmi_phoedt_init_app(void){}

/* can export to vendor end */
#ifdef __PHOEDT_FEATURE_PHOART__
S32 mmi_phoedt_get_spin_width(void){return 0;}
#endif
BOOL mmi_phoedt_notify_hdlr(U32 notify_flag, void* para){return 0;}
U32 mmi_phoedt_get_appmem_requirement(void){return 0;}


MMI_ID cui_phoart_create(MMI_ID parent_id){return 0;}
void cui_phoart_run(p_cui_phoart_run_struct p_args){}
void cui_phoart_close(MMI_ID cui_gid){}
void cui_phoart_struct_init(p_cui_phoart_run_struct p_args){}
MMI_BOOL cui_phoart_is_phoart_event(mmi_event_struct *evt){return MMI_TRUE;}
void mmi_phoedt_file_type_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                                          const srv_fmgr_fileinfo_struct* fileinfo){}
}
#endif  /* __MMI_PHOTOEDITOR__ */
#endif /* __COSMOS_MMI_PACKAGE__ */
// ------- dummy functions pluto end -------- //


