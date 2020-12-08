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
 *  vapp_gallery_viewer.cpp
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
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_GALLERY_SLIM__

extern "C"
{
#include "gdi_include.h"
#include "gdi_linear_transform.h"
#include "gdi_layer.h"
#include "cache_sw.h"
#include "custom_scatstruct.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"

#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "RightsMgrGProt.h"
#include "Drm_errcode.h"
#endif
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_slider_def.h"
}

#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_shooting.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_list_menu.h"
#include "vcp_text_view.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

#include "vcui_gallery_gprot.h"
#include "vapp_gallery_slim.h"
#include "cp\vapp_image_viewer_cp.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"
#include "vapp_gallery_slim_setting.h"
#include "vapp_gallery_slim_index.h"
#include "vfx_owner_draw.h"

#include "vapp_wallpaper.h"
#include "cp\vapp_video_player_cp.h"

#include "FileMgrServiceResDef.h"
#include "kal_trace.h"

#ifdef __MMI_COSMOS_PHOTOEDITOR__
#define __GALLERY_PHOTO_EDIT__
#else
#undef __GALLERY_PHOTO_EDIT__
#endif

#ifdef __GALLERY_PHOTO_EDIT__
#include "vapp_imgedt_gprot.h"
#endif

extern "C"
{
#include "MMI_media_app_trc.h"
#include "gdi_primitive.h"
#include "gdi_imgdec.h"
}

/*****************************************************************************
 * Macro copied from VRT (This is for dcache flush)
 *****************************************************************************/
#define VRT_MEM_ALIGNMENT 32
#define VAPP_GALLERY_IS_DCACHE_ALIGNED_ADDR(p) (((vrt_u32)(p) & (VRT_MEM_ALIGNMENT - 1)) == 0)

/*****************************************************************************
 * Typedef
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
enum VappImageViewerComponentLayout
{
    HAS_ZOOM_LABEL_ICON = 1,    // 1 means have +/- icons
    TOOLBAR_HEIGHT = 50,        // the same as Toolbar_BG_N.9slice.png
    ZOOM_SLIDER_CENTER = 25,
    ZOOM_LABEL_CX = 25,

    ZOOM_SLIDER_TOP = 90,
    ZOOM_IN_LABEL_CY = 74,

    TOOL_BAR_PADDING = 8,
    LABEL_PADDING = 0,
    LABEL_HEIGHT = 20,          // same as Add.png
    ZOOM_OUT_LABEL_BOTTOM_PORTRAIT = 2 * TOOLBAR_HEIGHT + TOOL_BAR_PADDING * 2,
    ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE = TOOLBAR_HEIGHT + TOOL_BAR_PADDING,
    ZOOM_SLIDER_BOTTOM_PORTRAIT = ZOOM_OUT_LABEL_BOTTOM_PORTRAIT + LABEL_PADDING + LABEL_HEIGHT,
    ZOOM_SLIDER_BOTTOM_LANDSCAPE = ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE + LABEL_PADDING + LABEL_HEIGHT,

    HAS_HORZ_ZOOM_SLIDER = 0,   // 1 means use horizontal zoom slider in landscape mode.
    HORZ_ZOOM_SLIDER_CENTER = 170,
    HORZ_SIDE_PADDING = 15,
    HORZ_LABEL_PADDING = 10,

    // View control
    VIEW_SLIDER_X = 160,
    VIEW_SLIDER_Y = 334,
    VIEW_SLIDER_LENGTH = 200,
    VIEW_SLIDER_ARROW_L_X =  19,
    VIEW_SLIDER_ARROW_R_X = 281,
    VIEW_SLIDER_ARROW_W = 19,
    VIEW_SLIDER_ARROW_H = 19,

    HORZ_VIEW_SLIDER_X = 240,
    HORZ_VIEW_SLIDER_Y = 234,
    HORZ_VIEW_SLIDER_LENGTH = 200,
    HORZ_VIEW_SLIDER_ARROW_L_X =  83,
    HORZ_VIEW_SLIDER_ARROW_R_X = 345,
};
#elif defined(__MMI_MAINLCD_480X800__)
enum VappImageViewerComponentLayout
{
    HAS_ZOOM_LABEL_ICON = 1,    // 1 means have +/- icons
    TOOLBAR_HEIGHT = 85,        // the same as Toolbar_BG_N.9slice.png
    ZOOM_SLIDER_CENTER = 38,    //480 - 442
    ZOOM_LABEL_CX = 38,         // 480 - 442

    ZOOM_SLIDER_TOP = 177,
    ZOOM_IN_LABEL_CY = 153,

    TOOL_BAR_PADDING = 10,
    LABEL_PADDING = 0,
    LABEL_HEIGHT = 40,          // same as Add.png
    ZOOM_OUT_LABEL_BOTTOM_PORTRAIT = 2 * TOOLBAR_HEIGHT + TOOL_BAR_PADDING * 2,
    ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE = TOOLBAR_HEIGHT + TOOL_BAR_PADDING,
    ZOOM_SLIDER_BOTTOM_PORTRAIT = ZOOM_OUT_LABEL_BOTTOM_PORTRAIT + LABEL_PADDING + LABEL_HEIGHT,
    ZOOM_SLIDER_BOTTOM_LANDSCAPE = ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE + LABEL_PADDING + LABEL_HEIGHT,

    HAS_HORZ_ZOOM_SLIDER = 0,   // 1 means use horizontal zoom slider in landscape mode.
    HORZ_ZOOM_SLIDER_CENTER = 170,
    HORZ_SIDE_PADDING = 15,
    HORZ_LABEL_PADDING = 10,

    // View control
    VIEW_SLIDER_X = 240,
    VIEW_SLIDER_Y = 580,
    VIEW_SLIDER_LENGTH = 326,
    VIEW_SLIDER_ARROW_L_X =  33,
    VIEW_SLIDER_ARROW_R_X = 420,
    VIEW_SLIDER_ARROW_W = 27,
    VIEW_SLIDER_ARROW_H = 27,

    HORZ_VIEW_SLIDER_X = 400,
    HORZ_VIEW_SLIDER_Y = 350,
    HORZ_VIEW_SLIDER_LENGTH = 384,
    HORZ_VIEW_SLIDER_ARROW_L_X = 172,
    HORZ_VIEW_SLIDER_ARROW_R_X = 601,
};
#elif defined(__MMI_MAINLCD_240X320__)
enum VappImageViewerComponentLayout
{
    HAS_ZOOM_LABEL_ICON = 1,    // 1 means have +/- icons
    TOOLBAR_HEIGHT = 45,        // the same as Toolbar_BG_N.9slice.png
    ZOOM_SLIDER_CENTER = 21,
    ZOOM_LABEL_CX = 21,

    ZOOM_SLIDER_TOP = 106,
    ZOOM_IN_LABEL_CY = 92,

    TOOL_BAR_PADDING = 4,
    LABEL_PADDING = 0,
    LABEL_HEIGHT = 16,          // same as Add.png
    ZOOM_OUT_LABEL_BOTTOM_PORTRAIT = 2 * TOOLBAR_HEIGHT + TOOL_BAR_PADDING * 2,
    ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE = TOOLBAR_HEIGHT + TOOL_BAR_PADDING,
    ZOOM_SLIDER_BOTTOM_PORTRAIT = ZOOM_OUT_LABEL_BOTTOM_PORTRAIT + LABEL_PADDING + LABEL_HEIGHT,
    ZOOM_SLIDER_BOTTOM_LANDSCAPE = ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE + LABEL_PADDING + LABEL_HEIGHT,

    HAS_HORZ_ZOOM_SLIDER = 1,   // 1 means use horizontal zoom slider in landscape mode.
    HORZ_ZOOM_SLIDER_CENTER = 170,
    HORZ_SIDE_PADDING = 15,
    HORZ_LABEL_PADDING = 10,

    // View control
    VIEW_SLIDER_X = 120,
    VIEW_SLIDER_Y = 196,
    VIEW_SLIDER_LENGTH = 172,
    VIEW_SLIDER_ARROW_L_X =  8,
    VIEW_SLIDER_ARROW_R_X = 213,
    VIEW_SLIDER_ARROW_W = 19,
    VIEW_SLIDER_ARROW_H = 19,

    HORZ_VIEW_SLIDER_X = 160,
    HORZ_VIEW_SLIDER_Y = 158,
    HORZ_VIEW_SLIDER_LENGTH = 190,
    HORZ_VIEW_SLIDER_ARROW_L_X =  37,
    HORZ_VIEW_SLIDER_ARROW_R_X = 264,
};
#elif defined(__MMI_MAINLCD_240X400__)
enum VappImageViewerComponentLayout
{
    HAS_ZOOM_LABEL_ICON = 1,    // 1 means have +/- icons
    TOOLBAR_HEIGHT = 45,        // the same as Toolbar_BG_N.9slice.png
    ZOOM_SLIDER_CENTER = 21,
    ZOOM_LABEL_CX = 21,

    ZOOM_SLIDER_TOP = 106,
    ZOOM_IN_LABEL_CY = 92,

    TOOL_BAR_PADDING = 4,
    LABEL_PADDING = 0,
    LABEL_HEIGHT = 16,          // same as Add.png
    ZOOM_OUT_LABEL_BOTTOM_PORTRAIT = 2 * TOOLBAR_HEIGHT + TOOL_BAR_PADDING * 2,
    ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE = TOOLBAR_HEIGHT + TOOL_BAR_PADDING,
    ZOOM_SLIDER_BOTTOM_PORTRAIT = ZOOM_OUT_LABEL_BOTTOM_PORTRAIT + LABEL_PADDING + LABEL_HEIGHT,
    ZOOM_SLIDER_BOTTOM_LANDSCAPE = ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE + LABEL_PADDING + LABEL_HEIGHT,

    HAS_HORZ_ZOOM_SLIDER = 1,   // 1 means use horizontal zoom slider in landscape mode.
    HORZ_ZOOM_SLIDER_CENTER = 170,
    HORZ_SIDE_PADDING = 15,
    HORZ_LABEL_PADDING = 10,

    // View control
    VIEW_SLIDER_X = 120,
    VIEW_SLIDER_Y = 271,
    VIEW_SLIDER_LENGTH = 172,
    VIEW_SLIDER_ARROW_L_X =  8,
    VIEW_SLIDER_ARROW_R_X = 213,
    VIEW_SLIDER_ARROW_W = 19,
    VIEW_SLIDER_ARROW_H = 19,

    HORZ_VIEW_SLIDER_X = 200,
    HORZ_VIEW_SLIDER_Y = 153,
    HORZ_VIEW_SLIDER_LENGTH = 228,
    HORZ_VIEW_SLIDER_ARROW_L_X =  60,
    HORZ_VIEW_SLIDER_ARROW_R_X = 321,
};
#else
enum VappImageViewerComponentLayout
{
    HAS_ZOOM_LABEL_ICON = 1,    // 1 means have +/- icons
    TOOLBAR_HEIGHT = 85,        // the same as Toolbar_BG_N.9slice.png
    ZOOM_SLIDER_CENTER = 38,    //480 - 442
    ZOOM_LABEL_CX = 38,         // 480 - 442

    ZOOM_SLIDER_TOP = 177,
    ZOOM_IN_LABEL_CY = 153,

    TOOL_BAR_PADDING = 10,
    LABEL_PADDING = 0,
    LABEL_HEIGHT = 40,          // same as Add.png
    ZOOM_OUT_LABEL_BOTTOM_PORTRAIT = 2 * TOOLBAR_HEIGHT + TOOL_BAR_PADDING * 2,
    ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE = TOOLBAR_HEIGHT + TOOL_BAR_PADDING,
    ZOOM_SLIDER_BOTTOM_PORTRAIT = ZOOM_OUT_LABEL_BOTTOM_PORTRAIT + LABEL_PADDING + LABEL_HEIGHT,
    ZOOM_SLIDER_BOTTOM_LANDSCAPE = ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE + LABEL_PADDING + LABEL_HEIGHT,

    HAS_HORZ_ZOOM_SLIDER = 0,   // 1 means use horizontal zoom slider in landscape mode.
    HORZ_ZOOM_SLIDER_CENTER = 170,
    HORZ_SIDE_PADDING = 15,
    HORZ_LABEL_PADDING = 10,

    // View control
    VIEW_SLIDER_X = 240,
    VIEW_SLIDER_Y = 334,
    VIEW_SLIDER_LENGTH = 200,
    VIEW_SLIDER_ARROW_L_X =  19,
    VIEW_SLIDER_ARROW_R_X = 281,
    VIEW_SLIDER_ARROW_W = 19,
    VIEW_SLIDER_ARROW_H = 19,

    HORZ_VIEW_SLIDER_X = 112,
    HORZ_VIEW_SLIDER_Y = 234,
    HORZ_VIEW_SLIDER_LENGTH = 200,
    HORZ_VIEW_SLIDER_ARROW_L_X =  83,
    HORZ_VIEW_SLIDER_ARROW_R_X = 345,
};
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_GALLERY_DISTANCE(pos1, pos2)   sqrt((VfxFloat)((pos1).x - (pos2).x) * ((pos1).x - (pos2).x) + ((pos1).y - (pos2).y) * ((pos1).y - (pos2).y))

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
const float VappImageViewerComponent::ZOOM_MIN = 1.0f;
const float VappImageViewerComponent::ZOOM_MAX = 5.0f;
#endif

const VfxFloat VappImageViewerComponent::GESTURE_FACTOR = 1.f / sqrt((VfxFloat)(LCD_WIDTH * LCD_WIDTH + LCD_HEIGHT * LCD_HEIGHT));

/*****************************************************************************
 * Global Function
 *****************************************************************************/
static void resetImageBuffer(VfxImageBuffer &imgBuf)
{
    imgBuf.ptr = NULL;
    imgBuf.width = 0;
    imgBuf.height = 0;
    imgBuf.pitchBytes = 0;
}

/*****************************************************************************
 * C Funtion Implementation
 *****************************************************************************/
extern "C"
{
extern void mmi_gallery_image_viewer_sap_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
    msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}
}

/*****************************************************************************
 * utility
 *****************************************************************************/
static U8* _ensure_non_cachable_address(U8* mem_addr)
{
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    U8* physicalAddr = (U8*) virt_to_phys((U32*)mem_addr);
    return physicalAddr;
#else
    return mem_addr;
#endif
}

static gdi_handle _convertImageBufferToLayer(const VfxImageBuffer &imgBuf, VfxBool clearCache = VFX_FALSE, VfxS32 overrideSize = 0)
{
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;

    // GDI layer only support zero-padded pitch
    VFX_ASSERT(imgBuf.pitchBytes == imgBuf.width * getBytePerPixel(imgBuf.colorFormat));
    GALLERY_MEASURE_TIME_START("Ggl");
    res = gdi_layer_create_cf_using_outside_memory(convertCF_VRT2GDI(imgBuf.colorFormat),
                                                   0, 0,
                                                   imgBuf.width,
                                                   imgBuf.height,
                                                   &thumbLayer,
                                                   _ensure_non_cachable_address(imgBuf.ptr),
                                                   overrideSize ? overrideSize : (imgBuf.pitchBytes * imgBuf.height));
    GALLERY_MEASURE_TIME_STOP("Ggl");
    VFX_ASSERT(GDI_SUCCEED == res);
    return thumbLayer;
}

void _flushCachedBuffer(VfxImageBuffer &dstBuffer, const VfxRect &dstRect)
{
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    /* do nothing if the buffer is not cached or not cache-line aligned */
    if (INT_QueryIsNonCachedRAM(dstBuffer.ptr, 0) || !VAPP_GALLERY_IS_DCACHE_ALIGNED_ADDR(dstBuffer.ptr))
    {
        return;
    }

    // flush buffer
    const VfxU32 line_start_addr = (VfxU32)dstBuffer.ptr;
    const VfxU32 line_end_addr = line_start_addr + dstBuffer.height * dstBuffer.pitchBytes;

    /* align line start addr to 32-byte */
    const VfxU32 line_aligned_start_addr = line_start_addr & ~(CPU_CACHE_LINE_SIZE - 1);
    /* clean size must be mutiples of cache line size */
    const VfxU32 line_cache_line_size = (((line_end_addr - line_aligned_start_addr) + (CPU_CACHE_LINE_SIZE - 1)) / CPU_CACHE_LINE_SIZE) * CPU_CACHE_LINE_SIZE;

    /* clean (flush) values to physical adress and invalidate the cache */
    clean_and_invalidate_dcache((kal_uint32)line_aligned_start_addr, (kal_uint32)line_cache_line_size);
#endif
}

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class VappGalleryImageDrawer : public VfxOwnerDraw
{
// constructor
public:
    // Default constructor
    VappGalleryImageDrawer();

// override
public:
    void setBufferSource(const VfxImageBuffer *previewBuf, const VfxImageBuffer *enhanceBuf);

    static vrt_render_dirty_type_enum onFPECallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

// method
public:
    // file specific info
    void setFilePath(const VfxWString &filePath){m_filePath = filePath;};
    void setFrameClipWindow(const VfxRect rect) {m_frameClipWindow = rect;};
    void setOrifinalDim(VfxSize s)              {m_originalDim = s;};

    // draw hint for drawer to choose LT or resizer
    void setDrawHint(DrawHint hint){m_drawHint = hint;};
    DrawHint getDrawHint(){return m_drawHint;};

protected:
    // choose proper buffer to use according to final output image size.
    const VfxImageBuffer& selectBufferBySize(const VfxSize &outputSize, VfxBool &choosePreviewBuf);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // enhance buffer
    VfxBool hasEnhanceBuf() {return ((m_enhanceBuf.ptr) ? VFX_TRUE : VFX_FALSE);}
#endif

    // draw frame content of the specific file
    void drawFrame(VfxImageBuffer &imgBuf, const VfxWString &filePath, const VfxRect clipWindow, const VfxS32 frameIndex);

enum HighQualityDrawState
{
    NO_NEED,
    NEED_DRAW,
    DRAWN
};

protected:
    DrawHint m_drawHint;
    VfxBool m_forceDrawFrame;       // force draw 1 frame in owner draw. VRT owner draw func will reset this flag.

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    VfxImageBuffer m_enhanceBuf;
#endif

    VfxImageBuffer m_previewBuf;
    vrt_frame_visual_property_struct m_visualProperty;
    HighQualityDrawState m_shouldDrawHighQuality;

    // file specific data
    VfxWString m_filePath;
    VfxRect m_frameClipWindow;
    VfxSize m_originalDim;

    VfxMatrix3x3Ex m_mDecodeLayerInverse;
    VfxRect m_enhanceMemento;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
// partial enhance decode data & method
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
public:
    VfxSignal2<VfxSize, VfxRect> m_signalStartToDecodeEnhanceBuf;
    const static VfxS32 FORCE_USE_PREVIEW_BUFF = 1;

    VfxRect getEnhanceMemento()const
    {
        return m_enhanceMemento;
    }
    void setIsEnhanceBufReady(const VfxBool b)
    {
        m_isEnhanceBufReady = b;
    }
    VfxBool getIsEnhanceBufReady() const
    {
        return m_isEnhanceBufReady;
    }
    void cancleEnhanceDecode()
    {
        m_enhanceMemento = VfxRect(0, 0, 0, 0);
        m_isEnhanceBufReady = VFX_FALSE;
    }

    void setupZoomSize(VfxSize enhanceMaxSize)
    {
        m_enhanceMaxSize = enhanceMaxSize;
    }

protected:
    void updateEnhanceBuf();
    static void onNotifyStartDecodeEnhance(void *arg);

    VfxBool m_forceUsePreviewBuf;
    VfxBool m_isEnhanceBufReady;
    VfxSize m_decodedSize;
    VfxSize m_enhanceMaxSize;
#endif
#endif

};

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappImageViewerComponent", VappImageViewerComponent, VfxControl);

/*****************************************************************************
 * VappGalleryImageDrawer Implementation
 *****************************************************************************/
VappGalleryImageDrawer::VappGalleryImageDrawer()
{
    kal_mem_set(&m_visualProperty, 0, sizeof(m_visualProperty));

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    kal_mem_set(&m_enhanceBuf, 0, sizeof(m_enhanceBuf));
#endif

    kal_mem_set(&m_previewBuf, 0, sizeof(m_previewBuf));
    m_shouldDrawHighQuality = NO_NEED;
    m_filePath = VFX_WSTR_EMPTY;
    m_drawHint = DH_NONE;
    m_originalDim = VfxSize(1, 1);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    m_forceUsePreviewBuf = VFX_FALSE;
    m_isEnhanceBufReady = VFX_FALSE;
    m_enhanceMaxSize  = VfxSize(1, 1);
#endif
#endif
}

void VappGalleryImageDrawer::setBufferSource(const VfxImageBuffer *previewBuf, const VfxImageBuffer *enhanceBuf)
{
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    if(NULL == previewBuf)
    {
        kal_mem_set(&m_previewBuf, 0, sizeof(m_previewBuf));
    }
    else
    {
        m_previewBuf = *previewBuf;
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    if(NULL == enhanceBuf)
    {

        kal_mem_set(&m_enhanceBuf, 0, sizeof(m_enhanceBuf));
    }
    else
    {
        m_enhanceBuf = *enhanceBuf;
    }

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    // check that enhance buffer is really larger than preview buffer
    if(m_previewBuf.ptr && m_enhanceBuf.ptr)
    {
        VFX_ASSERT(m_enhanceBuf.height * m_enhanceBuf.width >= m_previewBuf.height * m_previewBuf.width);
    }
#endif
#endif

    m_forceDrawFrame = VFX_TRUE;
}

vrt_render_dirty_type_enum VappGalleryImageDrawer::onFPECallback(
                        vrt_frame_visual_property_struct *target_frame,
                        const vrt_frame_visual_property_struct *watch_frame,
                        void *user_data,
                        vrt_u32 user_data_size)
{
    VFX_ASSERT(user_data);
    VFX_ASSERT(user_data_size == sizeof(VappGalleryImageDrawer*));
    VappGalleryImageDrawer *pThis = *reinterpret_cast<VappGalleryImageDrawer**>(user_data);
    if(!pThis->isValid())
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    if(NULL == watch_frame)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    const vrt_frame_visual_property_struct &t = pThis->m_visualProperty;
    const vrt_frame_visual_property_struct &w = *watch_frame;
    do{
        if(pThis->m_forceDrawFrame)
        {
            pThis->m_forceDrawFrame = VFX_FALSE;
            break;
        }

        if(t.anchor_point.x != w.anchor_point.x)
            break;
        if(t.anchor_point.y != w.anchor_point.y)
            break;
        if(t.bounds.size.width != w.bounds.size.width)
            break;
        if(t.bounds.size.height != w.bounds.size.height)
            break;
        if(t.transform.data.affine.rz != w.transform.data.affine.rz)
            break;
        if(t.pos.x != w.pos.x)
            break;
        if(t.pos.y != w.pos.y)
            break;

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
        if((VfxS32)(t.pos_z)!= (VfxS32)(w.pos_z))
        {
            pThis->drawFrame(pThis->m_previewBuf, pThis->m_filePath, pThis->m_frameClipWindow, (VfxS32)w.pos_z);
            break;
        }
#endif

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#if defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__)
        const VfxSize outputSize(w.bounds.size.width, w.bounds.size.height);
        if((FORCE_USE_PREVIEW_BUFF != (VfxS32)(w.fpe_user_0)) &&
           (outputSize.width * outputSize.height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT))
        {
            pThis->updateEnhanceBuf();
            break;
        }
#endif
#endif
        if(pThis->m_shouldDrawHighQuality == NO_NEED)
        {
            pThis->m_shouldDrawHighQuality = NEED_DRAW;
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        else if (pThis->m_shouldDrawHighQuality == NEED_DRAW)
        {
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }while(0);

    pThis->m_shouldDrawHighQuality = NO_NEED;
    pThis->m_visualProperty = *watch_frame;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

const VfxImageBuffer& VappGalleryImageDrawer::selectBufferBySize(const VfxSize &outputSize, VfxBool &choosePreviewBuf)
{ 
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	// make sure at least one buffer is available.
	VFX_ASSERT(m_previewBuf.ptr || m_enhanceBuf.ptr);
    // note outputSize is size of watch frame
    if(NULL == m_enhanceBuf.ptr)
    {
        choosePreviewBuf = VFX_TRUE;
        return m_previewBuf;
    }

    if(NULL == m_previewBuf.ptr)
    {
        choosePreviewBuf = VFX_FALSE;
        return m_enhanceBuf;
    }

    // if the resized image size is smaller than LCD,
    // use L1 preview buffer to prevent aliasing.
    if(outputSize.width * outputSize.height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT)
    {
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
        choosePreviewBuf = VFX_FALSE;
        return m_enhanceBuf;
        #else
        // if async decoding use preview buf
        if(m_forceUsePreviewBuf)
        {
            choosePreviewBuf = VFX_TRUE;
            return m_previewBuf;
        }
        if(!getIsEnhanceBufReady())
        {
             choosePreviewBuf = VFX_TRUE;
            return m_previewBuf;
        }

        choosePreviewBuf = VFX_FALSE;
        return m_enhanceBuf;
    #endif
    }
    else
    {
        choosePreviewBuf = VFX_TRUE;
        return m_previewBuf;
    }
#else
	// make sure at least one buffer is available.
	VFX_ASSERT(m_previewBuf.ptr);
	choosePreviewBuf = VFX_TRUE;
    return m_previewBuf;
#endif
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
void VappGalleryImageDrawer::onNotifyStartDecodeEnhance(void *arg)
{
    VfxObjHandle drawHandle = (VfxObjHandle)arg;
    VappGalleryImageDrawer *pDraw = (VappGalleryImageDrawer*)VfxObject::handleToObject(drawHandle);
    if(pDraw)
    {
        pDraw->m_signalStartToDecodeEnhanceBuf.emit(pDraw->m_decodedSize, pDraw->m_enhanceMemento);
    }
}
#endif
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
void VappGalleryImageDrawer::updateEnhanceBuf()
{
    if(1 >= m_originalDim.width || 1 >= m_originalDim.height)
    {
        return;
    }

    if(1 >= m_enhanceMaxSize.width || 1 >= m_enhanceMaxSize.height)
    {
        return;
    }

    const vrt_frame_visual_property_struct &vp = m_visualProperty;
    VfxSize decodeDstSize;
    VfxSize maxDstSize;
    VfxRect rect;
    do
    {
        // query layer size
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        const VfxScrRotateTypeEnum screenRotation = renderer->getScreenRotateType();
        switch (screenRotation)
        {
        case VFX_SCR_ROTATE_TYPE_0:
        case VFX_SCR_ROTATE_TYPE_180:
            maxDstSize.width = GDI_LCD_WIDTH;
            maxDstSize.height = GDI_LCD_HEIGHT;
            break;
        case VFX_SCR_ROTATE_TYPE_90:
        case VFX_SCR_ROTATE_TYPE_270:
            maxDstSize.width = GDI_LCD_HEIGHT;
            maxDstSize.height = GDI_LCD_WIDTH;
            break;
        }

        // determine src size
        // note there are different limitaion for different image decoder
        // ex: PNG decoder does not support upscale
        //     BMP, GIF support up to 640 px
        // so we upscale to "orginal size" of enhance image, i.e. the fit size of full decoded enhnace buf
        const VfxSize vpSize = VfxSize(vp.bounds.size.width, vp.bounds.size.height);
        const VfxFloat ratioWFrameToEnhance_X = vpSize.width * 1.0f / m_enhanceMaxSize.width;
        const VfxFloat ratioWFrameToEnhance_Y = vpSize.height * 1.0f / m_enhanceMaxSize.height;
        const VfxFloat ratioWFrameToEnhance = vfxMax(ratioWFrameToEnhance_X, ratioWFrameToEnhance_Y);
        const VfxSize srcSize = (1.0 < ratioWFrameToEnhance)? m_enhanceMaxSize : vpSize;

        // m: src to dst
        VfxMatrix3x3Ex m;
        m.setTranslation(-1 * vp.anchor_point.x * srcSize.width,
                         -1 * vp.anchor_point.y * srcSize.height);
        VfxMatrix3x3Ex s;
        s.setScale(vp.bounds.size.width * 1.0f / srcSize.width,
                   vp.bounds.size.height * 1.0f / srcSize.height);
        VfxMatrix3x3Ex r;
        r.setRotateByZ(vp.transform.data.affine.rz);
        VfxMatrix3x3Ex p;
        p.setTranslation((float)vp.pos.x, (float)vp.pos.y);
        m = s * m;
        m = r * m;
        m = p * m;

        // m_1: dst to src
        VfxMatrix3x3Ex m_1;
        m_1 = m;
        m_1.inverse();

        // init dst rect size
        VfxRect dstRect = VfxRect(0, 0, maxDstSize.width, maxDstSize.height);

        // calculate left-top and right-bottom point (ie pLT and pRB) in orgignal image
        VfxPoint p1(0, 0);
        VfxPoint p2(maxDstSize.width - 1, 0);
        VfxPoint p3(maxDstSize.width - 1, maxDstSize.height - 1);
        VfxPoint p4(0, maxDstSize.height - 1);
        VfxPoint pt1 = m_1.transform(p1);
        VfxPoint pt2 = m_1.transform(p2);
        VfxPoint pt3 = m_1.transform(p3);
        VfxPoint pt4 = m_1.transform(p4);

        pt1.x = vfxMax(vfxMin(srcSize.width -1, pt1.x), 0);
        pt1.y = vfxMax(vfxMin(srcSize.height-1, pt1.y), 0);
        pt3.x = vfxMax(vfxMin(srcSize.width -1, pt3.x), 0);
        pt3.y = vfxMax(vfxMin(srcSize.height-1, pt3.y), 0);

        VfxPoint pLT, pRB;
        pLT.x = vfxMin(pt1.x, pt3.x);
        pLT.y = vfxMin(pt1.y, pt3.y);
        pRB.x = vfxMax(pt1.x, pt3.x);
        pRB.y = vfxMax(pt1.y, pt3.y);

        // calculate decoded layer size
        decodeDstSize.width = VFX_ABS(pLT.x - pRB.x) + 1;
        decodeDstSize.height = VFX_ABS(pLT.y - pRB.y) + 1;

        // fix to 2X
        if(GDI_LCD_WIDTH * GDI_LCD_HEIGHT < decodeDstSize.width * decodeDstSize.height)
        {
            decodeDstSize.width  = (decodeDstSize.width  / 2) * 2;
            decodeDstSize.height = (decodeDstSize.height / 2) * 2;
        }

        // calculate matrix from src to decoded layer
        VfxMatrix3x3Ex mSrc2DecodeLayer;
        mSrc2DecodeLayer.setIdentity();
        mSrc2DecodeLayer.setTranslation((-1.0f) * pLT.x, (-1.0f) * pLT.y);
        m_mDecodeLayerInverse = mSrc2DecodeLayer;
        m_mDecodeLayerInverse.inverse();

        rect.origin.x = (-1) * pLT.x;
        rect.origin.y = (-1) * pLT.y;
        rect.size.width = srcSize.width;
        rect.size.height = srcSize.height;
    }while(0);

    // notify MMI to start async decode
    setIsEnhanceBufReady(VFX_FALSE);
    m_enhanceMemento = rect;
    m_decodedSize = decodeDstSize;
    vrt_invoke_mmi_rpc(onNotifyStartDecodeEnhance, getObjHandle());
}
#endif
#endif
void VappGalleryImageDrawer::drawFrame(
                                VfxImageBuffer &imgBuf,
                                const VfxWString &filePath,
                                const VfxRect clipWindow,
                                const VfxS32 frameIndex)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRAWER_DRAW_FRAME, clipWindow.origin.x, clipWindow.origin.y, clipWindow.size.width, clipWindow.size.height, frameIndex);

    _START("");
    gdi_handle dstLayer = _convertImageBufferToLayer(imgBuf, VFX_FALSE);
    _STOP("[Gallery][ViewerCP] convert frame buffer, dur = %d, line = %d");

    _START("");
    gdi_imgdec_draw_resized_file_frames(
        dstLayer,
        clipWindow.origin.x,
        clipWindow.origin.y,
        clipWindow.size.width,
        clipWindow.size.height,
        (U8*)filePath.getBuf(),
        frameIndex);
    _STOP("[Gallery][ViewerCP] gdi_imgdec_draw_resized_file_frames, dur = %d, line = %d");
    gdi_layer_free(dstLayer);
}

void VappGalleryImageDrawer::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    GALLERY_MEASURE_TIME("DRW");
    // 1. a. choose proper source image buffer
    //    b. create matrix from m_visualProperty
    //    c. convert m_enhanceBuf mem address to GDI Layer
    // 2. culling dstRect
    // 3. call gdi_2d_transform

    // if src buffer is 32 byte aligned size and address, and dynamic switchable
    // it can convet to cachable address by driver to accerlate SW LT performance

    // TODO: unsafe to call VfxMatrix methods in VRT?
    VfxBool needProductDecodeMaxtrix = VFX_FALSE;
    VfxBool choosePreviewBuf = VFX_TRUE;

    const vrt_frame_visual_property_struct &vp = m_visualProperty;
    const VfxSize outputSize(vp.bounds.size.width, vp.bounds.size.height);
    const VfxImageBuffer &imgBuf = selectBufferBySize(outputSize, choosePreviewBuf);
    gdi_lt_matrix_struct gdi_matrix;
    VfxBool isUsingRGBResizer = VFX_FALSE;

    // for project which dose not support decode full enhance image,
    // in case of draw enhance image, we draw enhance buffer with 1xCD size clip window
    #if !defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__)
    needProductDecodeMaxtrix = (choosePreviewBuf) ? VFX_FALSE : VFX_TRUE ;
    #endif

#if 0
/* under construction !*/
    #if defined(__ARM1176__) && defined(VAPP_GALLERY_IMG_VIEWER_BPP) && (VAPP_GALLERY_IMG_VIEWER_BPP == 3)
/* under construction !*/
    #else
/* under construction !*/
    #endif
#else
    // disable resizer because result of LT and resizer are different
    // this different may cause color inconsistant in some dirty region while
    // we use resizer in full update and use LT in partial update
    const VfxBool forceDisableResizer = VFX_TRUE;
#endif
    // if no need to do rotation, use Resizer instead of LT
    if (!forceDisableResizer && vp.transform.data.affine.rz == 0 && m_shouldDrawHighQuality == NEED_DRAW && m_drawHint != DH_RECOMMAND_LT)
    {
        isUsingRGBResizer = VFX_TRUE;
        m_shouldDrawHighQuality = DRAWN;
    }
    else
    {
        const VfxSize enhanceSize = m_enhanceMemento.size; //VfxSize(vp.bounds.size.width, vp.bounds.size.height)
        const VfxSize inputRectSize = needProductDecodeMaxtrix ? enhanceSize : VfxSize(imgBuf.width, imgBuf.height);
        VfxMatrix3x3Ex m;
        m.setTranslation(-1 * vp.anchor_point.x * inputRectSize.width,
                         -1 * vp.anchor_point.y * inputRectSize.height);
        VfxMatrix3x3Ex s;
        s.setScale(vp.bounds.size.width * 1.0f / inputRectSize.width,
                   vp.bounds.size.height * 1.0f / inputRectSize.height);

        VfxMatrix3x3Ex r;
        r.setRotateByZ(vp.transform.data.affine.rz);

        VfxMatrix3x3Ex p;
        p.setTranslation((float)(vp.pos.x + (dstRect.origin.x - srcRect.origin.x)),
                         (float)(vp.pos.y + (dstRect.origin.y - srcRect.origin.y)));

        m = s * m;
        m = r * m;
        m = p * m;
        if(needProductDecodeMaxtrix)
            m = m * m_mDecodeLayerInverse;
        m.transpose();
        kal_mem_cpy(&gdi_matrix.m[0], &m.m[0], sizeof(gdi_matrix.m));
    }

    // flush dst buffer first, since it maybe cachable
    _flushCachedBuffer(dstBuffer, dstRect);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // for source layer, we pass entire buffer to GDI.
    // this is because GDI will check the overall size of buffer
    // to see if it can be dynamically switched between cachable/non-cachable.
    const S32 actualBufSize = (imgBuf.ptr == m_enhanceBuf.ptr) ? VappGalleryEnhancedImage::IMAGE_BUF_SIZE : GDI_LCD_HEIGHT * GDI_LCD_WIDTH * VAPP_GALLERY_IMG_VIEWER_BPP;
    gdi_handle srcLayer = _convertImageBufferToLayer(imgBuf, VFX_FALSE, actualBufSize);
#else
	gdi_handle srcLayer = _convertImageBufferToLayer(imgBuf, VFX_FALSE, GDI_LCD_HEIGHT * GDI_LCD_WIDTH * VAPP_GALLERY_IMG_VIEWER_BPP);
#endif

    gdi_handle dstLayer = _convertImageBufferToLayer(dstBuffer, VFX_FALSE);

    // work around for [MAUI_02947396] side effect in 76 chip
    // do not use scr key to avoid using SW LT to ensure do LT by HW
    gdi_layer_push_and_set_active(srcLayer);
    /* do not enable source key for the src layer with alpha; otherwise, the edge quality will be unacceptable for HW LT */
    //if(gdi_layer_get_bit_per_pixel() != 32)
    {
        gdi_layer_set_source_key(VRT_FALSE, GDI_COLOR_TRANSPARENT);
    }
    gdi_layer_pop_and_restore_active();

    // color replacement for VRT
    gdi_layer_push_and_set_active(dstLayer);
    /* prevent output source key color */
    gdi_layer_set_source_key(VRT_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        dstRect.origin.x,
        dstRect.origin.y,
        dstRect.origin.x + dstRect.size.width - 1,
        dstRect.origin.y + dstRect.size.height - 1);

    gdi_draw_solid_rect(
                    dstRect.origin.x,
                    dstRect.origin.y,
                    dstRect.origin.x + dstRect.size.width - 1,
                    dstRect.origin.y + dstRect.size.height - 1,
                    GDI_COLOR_BLACK);

    if (isUsingRGBResizer == VFX_TRUE)
    {
        _START("[Gallery][ImageDrawer]gdi_bitblt_resized_with_resizer: %d ms, line: %d");
        S32 dx1,dx2,dy1,dy2;

        dx1 = (S32)((-1.0f)*vp.anchor_point.x * vp.bounds.size.width)+vp.pos.x+dstRect.origin.x-srcRect.origin.x;
        dx2 = dx1 + (vp.bounds.size.width-1);
        dy1 = (S32)((-1.0f)*vp.anchor_point.y * vp.bounds.size.height)+vp.pos.y+dstRect.origin.y-srcRect.origin.y;
        dy2 = dy1 + (vp.bounds.size.height-1);

        gdi_bitblt_resized_with_resizer(
            srcLayer,
            0,
            0,
            imgBuf.width-1,
            imgBuf.height-1,
            dx1,
            dy1,
            dx2,
            dy2,
            GDI_RESIZER_DEFAULT);
        _STOP("[Gallery][ImageDrawer]gdi_bitblt_resized_with_resizer: %d ms, line: %d");
    }
    else
    {
        _START("[Gallery][ImageDrawer]gdi_lt_projective_transform_ext: %d ms, line: %d");
        gdi_lt_projective_transform_ext(
                        &gdi_matrix,
                        srcLayer,
                        0,
                        0,
                        imgBuf.width,
                        imgBuf.height,
                        0,
                        0,
                        dstBuffer.width,
                        dstBuffer.height,
                        GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                        GDI_COLOR_TRANSPARENT,
                        GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
                        0);
        _STOP("[Gallery][ImageDrawer]gdi_lt_projective_transform_ext: %d ms, line: %d");
    }


    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(srcLayer);
    gdi_layer_free(dstLayer);

    #if defined(VAPP_GALLERY_IMG_VIEWER_BPP) && (VAPP_GALLERY_IMG_VIEWER_BPP == 3) && \
        (MAIN_LCD_OUTPUT_FORMAT == LCM_18BIT_18_BPP_RGB666_1)
    {
    GALLERY_MEASURE_TIME("DIT");
    // if we're RGB888 but LCM is RGB666, then we need to dither.
    iul_sd_rgb888_2bits_dithering_ip(dstBuffer.ptr,
                                     dstRect.size.width,
                                     dstRect.size.height,
                                     dstBuffer.pitchBytes / VAPP_GALLERY_IMG_VIEWER_BPP);
    }
    #endif

    return;
}

/*****************************************************************************
 * VappGalleryPreviewImage Implementation
 *****************************************************************************/
VappGalleryPreviewImage::VappGalleryPreviewImage()
{
}

void VappGalleryPreviewImage::onInit()
{
    VfxAnimImageFrame::onInit();
    // VfxImageFrame auto resizes its size to fit image content
    // ViewCP treats VappGalleryPreviewImage as the watch frame, we want to control its size by zoom level
    // so disable auto resize to control frame size
    setAutoResize(VFX_FALSE);
}

void VappGalleryPreviewImage::onDeinit()
{
    VfxAnimImageFrame::onDeinit();
}

/*****************************************************************************
 * VappGalleryViewerMediaState Implementation
 *****************************************************************************/
VappGalleryViewerMediaState::VappGalleryViewerMediaState():
	m_refreshed(VFX_FALSE),
	m_displayed(VFX_FALSE),
	m_useIndexInList(VFX_TRUE),
    m_imageOnly(VFX_TRUE),
    m_videoOnly(VFX_FALSE),   
    m_autoPlaySlideshow(VFX_FALSE),
    m_allowEmptyPage(VFX_FALSE),
    m_confirmScenario(VFX_FALSE),
    m_singleFileCheckResult(DECODING),
    m_focusIndex(0),
    m_sortMethod(FS_SORT_NAME),    
    m_isSyncContentProvider(VFX_TRUE),
    m_hasCustomFilter(VFX_FALSE), 
    m_disableSwitchBalloon(VFX_FALSE)
{
    FMGR_FILTER_INIT(&m_fileFilter);
    FMGR_FILTER_SET_ALL(&m_fileFilter);

    m_focusFile.setNull();
    m_folderPath.setNull();

    m_cacheCount = 3;
}

VfxBool VappGalleryViewerMediaState::isSingleFile()
{
    return ((m_folderPath.isNull() || m_folderPath.isEmpty()) && m_isSyncContentProvider);
}


VappGalleryMediaListCommon* VappGalleryViewerMediaState::createMediaList(VfxObject *parent)
{
    // use file manager data source
    VappGalleryMediaListCommon *pList = NULL;
    VFX_OBJ_CREATE_EX(pList, VappGalleryMediaListCommon, parent, (CACHE_TYPE_L1));

    // TODO: 1. extract drive from input folder path.
    //       2. should handle read-only media?
    VappGalleryStorageSetting setting;
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage(VFX_FALSE));

    if(!m_focusFile.isEmpty() &&
       !m_useIndexInList)
    {
        // search for pattern
        pList->configPath(
            m_folderPath,
            &m_focusFile
            );
    }
    else
    {
        // don't search for file,
        // use index instead
        pList->configPath(m_folderPath);
    }

    if(m_hasCustomFilter)
    {
        pList->configFileTypeFilter(&m_fileFilter);
    }
    else if(m_imageOnly)
    {
        // image folder scans only image, no video
        FMGR_FILTER filter;
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
        pList->configFileTypeFilter(&filter);
    }
    else if(m_videoOnly)
    {
        // image folder scans only image, no video
        FMGR_FILTER filter;
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_VIDEO(&filter);
        pList->configFileTypeFilter(&filter);
    }

    pList->configSortMethod(m_sortMethod);

    return pList;

}

/*****************************************************************************
 * VappGalleryGestureTranslator Implementation
 *****************************************************************************/
VappGalleryGestureTranslator::VappGalleryGestureTranslator():
    m_prevTimeStamp(0),
    m_prevX(0),
    m_draggingMode(VFX_FALSE),
    m_delayedTap(VFX_FALSE), 
    m_tapTimer(NULL)
{
}

void VappGalleryGestureTranslator::onInit()
{
    VfxObject::onInit();
    VFX_OBJ_CREATE(m_tapTimer, VfxTimer, this);
    m_tapTimer->m_signalTick.connect(this, &VappGalleryGestureTranslator::onTapTimer);
    m_tapTimer->setStartDelay(DOUBLE_TAP_INTERVAL);
}

void VappGalleryGestureTranslator::reset()
{
    m_prevTimeStamp = 0;
    m_prevX = 0;
    m_draggingMode = VFX_FALSE;
    m_delayedTap = VFX_FALSE;
    m_delayedTapPos.setZero();
}

void VappGalleryGestureTranslator::onTapTimer(VfxTimer *sender)
{
    // signal TAP event
    m_delayedTap = VFX_FALSE;
    m_signalGestureRecognized.emit(this, VG_TAP);
}

const VfxPenEvent& VappGalleryGestureTranslator::getLastPenEvent()
{
    return m_lastPenEvent;
}

VfxS32 VappGalleryGestureTranslator::getSquaredDistance(const VfxPoint &p1, const VfxPoint &p2)
{
    return vfxAbs(p1.x - p2.x) + vfxAbs(p1.y - p2.y);
}

void VappGalleryGestureTranslator::processPenEvent(VfxFrame *component, const VfxPenEvent &e)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_TRANSLATE_GESTURE, e.type, e.pos.x, e.pos.y);
    const VfxS32 cpWidth = component->getSize().width;
    const VfxS32 cpHeight = component->getSize().height;
    const VfxS32 DRAG_THRESHOLD = cpWidth / 20;
    const VfxS32 DOUBLE_TAP_THRESHOLD = cpWidth / 5 + cpHeight / 5;
    m_lastPenEvent = e;

    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        m_prevTimeStamp = e.timeStamp;
        m_prevX = e.downPos.x;
        m_draggingMode = VFX_FALSE;
    }
    else if(VFX_PEN_EVENT_TYPE_UP == e.type)
    {
        VappGalleryGesture gesture = VG_NONE;
        do
        {
            if(!m_draggingMode) // only move a little, so this is a TAP.
            {
                const VfxS32 doubleTapDist = getSquaredDistance(m_delayedTapPos, e.pos);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_DOUBLE_TAP_DIST_D_THRESHOLD_D, doubleTapDist, DOUBLE_TAP_THRESHOLD);
                if(m_delayedTap && DOUBLE_TAP_THRESHOLD > doubleTapDist)
                {
                    // already a TAP waiting, and the two tap are very near,
                    // so this is a double-tap
                    m_delayedTap = VFX_FALSE;
                    m_tapTimer->stop();
                    gesture = VG_DOUBLE_TAP;
                }
                else
                {
                    // single TAP, wait a while (make sure it is not a double-tap)
                    m_tapTimer->stop();
                    m_tapTimer->start();
                    m_delayedTap = VFX_TRUE;
                    m_delayedTapPos = e.prevPos;
                }
                break;
            }
            else
            {
                // if swipe very quickly, treat as a GO NEXT/PREV gesture
                const VfxS32 swipeDist = vfxAbs(e.pos.x - e.downPos.x);
                if(0 == swipeDist)
                {
                    break;
                }
                const VfxMsec swipeTime = vfxMsecDiff(e.timeStamp, e.downTimeStamp);
                const VfxFloat swipeSpeed = swipeDist * MSEC_PER_SEC * 1.0f /
                                            swipeTime;
                const VfxMsec SWIPE_TIME_THRESHOLD = 500;
                const VfxFloat SWIPE_SPEED_THRESHOLD = cpWidth / 18.0f;
                const VfxS32 SWIPE_DISTANCE_THRESHOLD = cpWidth / 15;
                if(swipeTime <= SWIPE_TIME_THRESHOLD &&
                   swipeSpeed >= SWIPE_SPEED_THRESHOLD &&
                   swipeDist >= SWIPE_DISTANCE_THRESHOLD)
                {
                    gesture = e.pos.x > e.downPos.x ? VG_GO_PREV : VG_GO_NEXT;
                    break;
                }
            }
        }while(false);

        // clear swipe info
        m_prevTimeStamp = 0;
        m_prevX = 0;
        if(VG_NONE != gesture)
        {
            m_signalGestureRecognized.emit(this, gesture);
        }

        if(m_draggingMode && VG_GO_PREV != gesture && VG_GO_NEXT != gesture)
        {
            m_draggingMode = VFX_FALSE;
            m_signalGestureRecognized.emit(this, VG_DRAG_END);
        }
    }
    else if(VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
        // maintain swipe info
        if(m_prevX != e.pos.x)
        {
            m_prevTimeStamp = e.timeStamp;
            m_prevX = e.pos.x;
        }

        if(DRAG_THRESHOLD <= getSquaredDistance(e.pos, e.downPos))
        {
            m_draggingMode = VFX_TRUE;
        }

        if(m_draggingMode)
        {
            // any finger movement is a drag event
            m_signalGestureRecognized.emit(this, VG_DRAG);
        }
    }
}

/*****************************************************************************
 * VappGalleryViewerPage Implementation
 *****************************************************************************/
VappImageViewerComponent::VappImageViewerComponent() :
	m_asyncProvider(NULL)
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    ,m_zoomSlider(NULL)
    ,m_zoomInLabel(NULL)
    ,m_zoomOutLabel(NULL)
#endif

	,m_keypadLongPressTimer(NULL)
    ,m_zoomOffset(0)
    ,m_viewSlider(NULL)
    ,m_viewPrevLabel(NULL)
    ,m_viewNextLabel(NULL)
    
    ,m_mavIconFrame(NULL)
    ,m_isViewSliderDraging(VFX_FALSE)
    ,m_enableGSensorSupport(VFX_TRUE)
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    ,m_gSensor(NULL)
#endif

    ,m_3dRedBlueImageIcon(NULL)
    ,m_isDuringFileOperation(VFX_FALSE)
    ,m_viewerPanelContainer(NULL)
    ,m_mediaList(NULL)
    ,m_currentIndex(0)

	,m_drmConsumer(NULL)
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	,m_enhancedImage(NULL)
	,m_enhancer(NULL)
#endif

	,m_imageChecker(NULL)
	,m_imageCheckerOutput(NULL)

    ,m_previewTimer(NULL)
    ,m_panelShiftFinishTimer(NULL)

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	,m_isSliderZooming(VFX_FALSE)
#endif

    ,m_warningPoppedDuringGesture(VFX_FALSE)
    ,m_hasShownLastPhotoHint(VFX_FALSE)
    ,m_hasShownFirstPhotoHint(VFX_FALSE)
	,m_gestureTranslator(NULL)

    ,m_isMultiTouchMode(VFX_FALSE)
    ,m_multiTouchZoomGesture(VFX_FALSE)
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
	,m_slideshowContainer(NULL)
    ,m_slideshowStillImageTimer(NULL)
    ,m_shuffleIndex(NULL)
    ,m_slideshowCurrentIndex(0)
#endif
{
    for(int i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        m_viewPanels[i] = NULL;
    }
}

VappImageViewerComponent::VappImageViewerComponent(VappImageViewerComponentOption option) :
	m_asyncProvider(NULL)
    ,m_option(option)

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    ,m_zoomSlider(NULL)
    ,m_zoomInLabel(NULL)
    ,m_zoomOutLabel(NULL)
#endif

	,m_keypadLongPressTimer(NULL)
    ,m_zoomOffset(0)
    
    ,m_viewSlider(NULL)
    ,m_viewPrevLabel(NULL)
    ,m_viewNextLabel(NULL)
    ,m_mavIconFrame(NULL)
    ,m_isViewSliderDraging(VFX_FALSE)
    ,m_enableGSensorSupport(VFX_TRUE)
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    ,m_gSensor(NULL)
#endif

	,m_3dRedBlueImageIcon(NULL)
    ,m_isDuringFileOperation(VFX_FALSE)
    
    ,m_viewerPanelContainer(NULL)
    ,m_mediaList(NULL)
    ,m_currentIndex(0)

	,m_drmConsumer(NULL)
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	,m_enhancedImage(NULL)
	,m_enhancer(NULL)
#endif

	,m_imageChecker(NULL)
	,m_imageCheckerOutput(NULL)

    ,m_previewTimer(NULL)
    ,m_panelShiftFinishTimer(NULL)

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	,m_isSliderZooming(VFX_FALSE)
#endif

    ,m_warningPoppedDuringGesture(VFX_FALSE)
    ,m_hasShownLastPhotoHint(VFX_FALSE)
    ,m_hasShownFirstPhotoHint(VFX_FALSE)
	,m_gestureTranslator(NULL)

    ,m_isMultiTouchMode(VFX_FALSE)
    ,m_multiTouchZoomGesture(VFX_FALSE)
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    ,m_slideshowContainer(NULL)
    ,m_slideshowStillImageTimer(NULL)
    ,m_shuffleIndex(NULL)
    ,m_slideshowCurrentIndex(0)
#endif

{
    for(int i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        m_viewPanels[i] = NULL;
    }
}

void VappImageViewerComponent::onInit()
{
    VfxFrame::onInit();

    // setup gesture recognizer
    VFX_OBJ_CREATE(m_gestureTranslator, VappGalleryGestureTranslator, this);
    m_gestureTranslator->m_signalGestureRecognized.connect(this, &VappImageViewerComponent::onGesture);

    // setup timer for refreshing preview panels
    VFX_OBJ_CREATE(m_previewTimer, VfxTimer, this);
    m_previewTimer->setDuration(100);
    m_previewTimer->m_signalTick.connect(this, &VappImageViewerComponent::onPreviewTimerCheck);

    // create DRM consumer object
    VFX_OBJ_CREATE(m_drmConsumer, VappGalleryDRMConsumer, this);
    m_drmConsumer->m_signalRightExpired.connect(this, &VappImageViewerComponent::onFileRightExpired);


    // view panel container and view panels
    VFX_OBJ_CREATE(m_viewerPanelContainer, VfxFrame, this);
    ASSERT(NULL != m_viewerPanelContainer);
    m_viewerPanelContainer->setAutoAnimate(VFX_FALSE);
    m_viewerPanelContainer->setBgColor(VFX_COLOR_BLACK);
    m_viewerPanelContainer->setIsUnhittable(VFX_TRUE);

    layoutViewerPanelContainer(m_viewerPanelContainer);

    // then, put viewer panels in the container
    for(int i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        VappGalleryViewerPanel *panel = createViewerPanel();
        m_viewPanels[i] = panel;
    }

    // set focus panel to panel 0
    m_currentPanel = 0;
    m_viewPanels[m_currentPanel]->bringToFront();

    // update inital position
    // LEFT    CURRENT   RIGHT
    //  2        0         1
    snapPanelToInitialPosition(CURRENT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(LEFT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // zoom slider
    createZoomSlider();
#endif

    createViewControl();

    createGSensor();

    m_signalBoundsChanged.connect(this, &VappImageViewerComponent::onBoundsChange);
}

void VappImageViewerComponent::layoutViewerPanelContainer(VfxFrame *viewerPanelContainer)
{
    viewerPanelContainer->setSize(getSize());
    viewerPanelContainer->setPos(0, 0);
    viewerPanelContainer->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappImageViewerComponent::onDeinit()
{
    if(NULL != m_previewTimer)
    {
        m_previewTimer->stop();
        VFX_OBJ_CLOSE(m_previewTimer);
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // [MAUI_03115066] close enhance image decoder first and then release enhance buffer
    VFX_OBJ_CLOSE(m_enhancer);
    VFX_OBJ_CLOSE(m_enhancedImage);
#endif

    destroyGSensor();

    VfxFrame::onDeinit();
}

void VappImageViewerComponent::handleEnter(const VfxBool blockRefresh, VappGalleryViewerMediaState initState)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_HANDLE_ENTER, blockRefresh);

    // update initstate
    m_initState = initState;

    // detect invalidated media list
    if(m_mediaList && m_mediaList->canCheckDirty()&& m_mediaList->checkDirty() && !blockRefresh)
    {
        m_mediaList->release();
        m_mediaList = NULL;
    }

    // single file case does not create MediaList
    if(NULL == m_mediaList &&
      (!m_initState.isSingleFile() || !m_option.isSyncContentProvider))
    {
        if(!m_option.isSyncContentProvider && m_asyncProvider)
        {
#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
            VappGalleryMediaListAsync *pList = NULL;
            VFX_OBJ_CREATE_EX(pList, VappGalleryMediaListAsync, this, (CACHE_TYPE_L1));
            pList->configProvider(m_asyncProvider);
            m_mediaList = pList;
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */
        }
        else if(!m_initState.isSingleFile())
        {
            const VfxS32 cacheCount  = (shouldReserveAdjacentPreview())? 3 : 1;
            m_initState.m_cacheCount = cacheCount;
            m_mediaList = m_initState.createMediaList(this);
        }

        if(m_mediaList)
        {
            m_mediaList->getListEvent()->connect(this, &VappImageViewerComponent::onListUpdated);
            m_mediaList->getDecodeEvent()->connect(this, &VappImageViewerComponent::onDecodeResult);
        }
    }

    getCurrentPanel()->setIcon(VIT_DEFAULT);
    if(m_initState.isSingleFile())
    {
        verifyInputFile();
    }

    // may came back from interrupt,
    // resume instead of start.
    if(m_drmConsumer)
    {
        m_drmConsumer->resumeConsume();
    }

    // make sure panels are correctly placed.
    m_viewPanels[m_currentPanel]->bringToFront();
    // update inital position
    // LEFT    CURRENT   RIGHT
    //  2        0         1
    snapPanelToInitialPosition(CURRENT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(LEFT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);

    // reset UI logic
    m_isViewSliderDraging = VFX_FALSE;
}

void VappImageViewerComponent::handleEntered(const VfxBool blockRefresh)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_HANDLE_ENTERED, blockRefresh);

    // check if content is dirty
    if(m_mediaList && !m_mediaList->isPrepared())
    {
        m_mediaList->prepareList();
        if(m_previewTimer)
        {
            m_previewTimer->stop();
        }
    }
    else if(m_mediaList && m_mediaList->canCheckDirty() && m_mediaList->checkDirty() && !blockRefresh)
    {
        // if file list is dirty, force to config by file name
        m_initState.m_useIndexInList = VFX_FALSE;

        // media list is now dirty, we should refresh it
        m_mediaList->refreshList();
        m_mediaList->obtainForegroundMemory();
    }
    else if(m_previewTimer && m_mediaList)
    {
        // directly return to FG mode without refreshing
        m_mediaList->obtainForegroundMemory();
        m_previewTimer->start();
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // currently we only enhance image in multi-file viewer case.
    // if not, there is no need to create VappGalleryEnhancedImage
    if(NULL == m_enhancedImage && m_mediaList && m_option.supportZoom)
    {
        VFX_OBJ_CREATE(m_enhancedImage, VappGalleryEnhancedImage, this);
    }
#endif

    // CABC backlight mode
#if defined(__MMI_CABC__)
    getRootApp()->setCABCMode(MMI_FRM_CABC_MODE_STILL);
#endif

    // set multi touch mode
#if (defined(__TOUCH_PANEL_TRUE_MULTITOUCH__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && (__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif
}

void VappImageViewerComponent::handleExit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_HANDLE_EXIT);
	
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    // must leave slideshow preview first
    if(isPlayingSlideshow())
    {
        stopSlideshow();
    }
#endif

    stopAllDecoding();

    if(m_keypadLongPressTimer)
    {
        m_keypadLongPressTimer->stop();
    }

    if(m_drmConsumer)
    {
        // we may just be pushed to background by interrupt,
        // so pause instead of stop.
        m_drmConsumer->pauseConsume();
    }

    if(m_gestureTranslator)
    {
        m_gestureTranslator->reset();
    }

    if(m_previewTimer)
        m_previewTimer->stop();

    stopVerifyInputFile();

    // reset to multi-touch mode
    m_multiTouchZoomGesture = VFX_FALSE;
#if (defined(__TOUCH_PANEL_TRUE_MULTITOUCH__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && (__MTK_INTERNAL__)
/* under construction !*/
#endif

    teardownGSensor();
}

void VappImageViewerComponent::handleExited2(const VfxBool releaseForegroundOnly)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_HANDLE_EXITED2, releaseForegroundOnly);

    // update init state
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    // free image resources
    // that relies on mediaList
    // but, remember view state first.
    if(m_mediaList)
    {
        m_initState.m_focusIndex = (m_mediaList->isPrepared()) ? m_currentIndex : m_initState.m_focusIndex;
        m_initState.m_displayed = VFX_FALSE;
        // reset the m_useIndexInList logic
        // force to use file name search only if file list s dirty while entry
        m_initState.m_useIndexInList = VFX_TRUE;
        // recorrd the name of the file we last preview
        VfxWString path = VFX_WSTR_EMPTY;
        getCurrentMediaPath(path);
        m_initState.m_focusFile = VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr((WCHAR*)path.getBuf()));

#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
        // if it is asyn provider, unlock cache
        VappGalleryMediaListAsync *asyncMediaList = VFX_OBJ_DYNAMIC_CAST(m_mediaList, VappGalleryMediaListAsync);
        if(asyncMediaList)
        {
            asyncMediaList->stopDecode();
            VfxImageBuffer buff;
            const MediaIndex nextIdx = getNextIndex();
            const MediaIndex prevIdx = getPrevIndex();
            asyncMediaList->unlockThumb(VcpMenuPos(0, m_currentIndex), buff);
            asyncMediaList->unlockThumb(VcpMenuPos(0, nextIdx), buff);
            asyncMediaList->unlockThumb(VcpMenuPos(0, prevIdx), buff);
        }
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */
    }

    if(!m_initState.isSingleFile())
    {
        clearAllPanel();
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        updateZoomSliderByPanel(getCurrentPanel());
#endif

    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // [MAUI_03115066] close enhance image decoder first and then release enhance buffer
    VFX_OBJ_CLOSE(m_enhancer);
    VFX_OBJ_CLOSE(m_enhancedImage);
#endif

    // reset CABC mode
#if defined(__MMI_CABC__)
    getRootApp()->resetCABCMode();
#endif

    // release foreground memory or entire media list.
    if(m_mediaList)
    {
        if(releaseForegroundOnly)
        {
            m_mediaList->releaseForegroundMemory();
        }
        else
        {
            m_mediaList->release();
            m_mediaList = NULL;
        }
    }

    // reset UI logic
    m_isViewSliderDraging = VFX_FALSE;
}

VfxBool VappImageViewerComponent::handleBack()
{
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    if(isPlayingSlideshow())
    {
        stopSlideshow();
        return VFX_TRUE;
    }
    else
#endif
    {
        // stop all decode to make sure back animation is smooth
        stopAllDecoding();
        return VFX_FALSE;
    }
}

// TODO: modofy condition
void VappImageViewerComponent::startUpdate()
{
    if(NULL == m_mediaList)
    {
        if(!m_initState.m_isSyncContentProvider && m_asyncProvider)
        {
#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
            VappGalleryMediaListAsync *pList = NULL;
            VFX_OBJ_CREATE_EX(pList, VappGalleryMediaListAsync, this, (CACHE_TYPE_L1));
            pList->configProvider(m_asyncProvider);
            m_mediaList = pList;

            m_mediaList->getListEvent()->connect(this, &VappImageViewerComponent::onListUpdated);
            m_mediaList->getDecodeEvent()->connect(this, &VappImageViewerComponent::onDecodeResult);
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */      
        }
        else
        {
            return;
        }
    }

    if(m_mediaList->isPrepared())
    {
        onListUpdated(PREPARE_OK);
    }
    else
    {
        m_mediaList->getListEvent()->connect(this, &VappImageViewerComponent::onListUpdated);
        m_mediaList->prepareList();
    }
}

void VappImageViewerComponent::handleQueryRotate()
{
    teardownGSensor();
}

void VappImageViewerComponent::handleRotate()
{
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    layoutZoomSlider();
#endif

    layoutViewControl();
    layout3DRedBlueIcon();

    // after rotation, panels will adjust their position to properly fit the Viewer rect.
    // therefore, we need to re-order their position and z-order again.
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    if(curPanel)
    {
        curPanel->bringToFront();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
        // [MAUI_03219606] partial decode project + phone rotation + mav 
        // we do not support zoom function for MAV, 
        // so skip cancelling partial decode to prevent clean drawer data wrongly for MAV file
        if(!isCurrentPreviewMAV())
        {
            curPanel->onCancelPartialEnhanceDecode();
            stopEnhance();
        }
#endif
#endif
    }
	
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    updateZoomSliderByPanel(curPanel);
#endif

    snapPanelToInitialPosition(CURRENT_PANEL, VFX_TRUE);
    snapPanelToInitialPosition(LEFT_PANEL, VFX_TRUE);
    snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);

    if(isCurrentPreviewMAV())
        setupGSensor();
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
void VappImageViewerComponent::createZoomSlider()
{
    if(!hasZoomSlider()){return;}

    if(NULL == m_zoomSlider)
    {
        if(HAS_ZOOM_LABEL_ICON)
        {
            VFX_OBJ_CREATE(m_zoomInLabel, VfxImageFrame, this);
            VFX_OBJ_CREATE(m_zoomOutLabel, VfxImageFrame, this);
            m_zoomInLabel->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IMG_ZOOM_IN));
            m_zoomOutLabel->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IMG_ZOOM_OUT));
        }

        VFX_OBJ_CREATE(m_zoomSlider, VcpSlider, this);
        // set auto animate ON because we support orientation change.
        m_zoomSlider->setAutoAnimate(VFX_TRUE);
        m_zoomSlider->setMaxValue(ZOOM_MAX);
        m_zoomSlider->setMinValue(ZOOM_MIN);
        m_zoomSlider->setCurrentValue(ZOOM_MIN);
        m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        m_zoomSlider->m_signalThumbPressed.connect(this, &VappImageViewerComponent::onBeginZoom);
        m_zoomSlider->m_signalThumbReleased.connect(this, &VappImageViewerComponent::onEndZoom);
        m_zoomSlider->m_signalThumbDrag.connect(this, &VappImageViewerComponent::onZoom);
        m_zoomSlider->setIsHapticTouchEnabled(VFX_TRUE);

        hideZoomSlider(VFX_TRUE);
    }
    layoutZoomSlider();
}

void VappImageViewerComponent::layoutZoomSlider()
{
    VfxScrRotateTypeEnum pageRotation = findScreen()->getRotateType();
    VfxBool landscape = VFX_FALSE;
    switch(pageRotation)
    {
    case VFX_SCR_ROTATE_TYPE_0:
    case VFX_SCR_ROTATE_TYPE_180:
        landscape = VFX_FALSE;
        break;
    case VFX_SCR_ROTATE_TYPE_90:
    case VFX_SCR_ROTATE_TYPE_270:
        landscape = VFX_TRUE;
        break;
    }

    const VfxSize s = getSize();

    if(HAS_HORZ_ZOOM_SLIDER && landscape)
    {
        if(m_zoomInLabel)
        {
            m_zoomInLabel->setAnchor(1.0f, 0.5f);
            m_zoomInLabel->setPos(s.width - HORZ_SIDE_PADDING, HORZ_ZOOM_SLIDER_CENTER);
            m_zoomInLabel->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_NONE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_NONE);
        }
        if(m_zoomOutLabel)
        {
            m_zoomOutLabel->setAnchor(0.0f, 0.5f);
            m_zoomOutLabel->setPos(HORZ_SIDE_PADDING, HORZ_ZOOM_SLIDER_CENTER);
            m_zoomOutLabel->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_NONE,
                        VFX_FRAME_ALIGNER_MODE_NONE);
        }
        if(m_zoomSlider)
        {
            m_zoomSlider->setAnchor(0.0f, 0.5f);
            const VfxS32 labelWidth = m_zoomInLabel ? m_zoomInLabel->getSize().width : 0;
            m_zoomSlider->setPos(
                        HORZ_SIDE_PADDING + HORZ_LABEL_PADDING + labelWidth,
                        HORZ_ZOOM_SLIDER_CENTER
                        );
            m_zoomSlider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
            VfxImageSrc trackImg(IMG_ID_VAPP_GALLERY_IMG_ZOOM_HORZ_SLIDER);
            m_zoomSlider->setImageFullTrack(trackImg);
            m_zoomSlider->setLength(s.width - 2 * (HORZ_SIDE_PADDING + HORZ_LABEL_PADDING + labelWidth));
            m_zoomSlider->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_NONE);
        }
        return;
    }


    if(m_zoomInLabel)
    {
        m_zoomInLabel->setAnchor(0.5f, 0.5f);
        m_zoomInLabel->setPos(s.width - ZOOM_LABEL_CX, ZOOM_IN_LABEL_CY);
        m_zoomInLabel->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_NONE);
    }
    if(m_zoomOutLabel)
    {
        m_zoomOutLabel->setAnchor(0.5f, 1.0f);
        m_zoomOutLabel->setPos(
            s.width - ZOOM_LABEL_CX,
            s.height - (landscape ? ZOOM_OUT_LABEL_BOTTOM_LANDSCAPE : ZOOM_OUT_LABEL_BOTTOM_PORTRAIT));
        m_zoomOutLabel->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE,
                    VFX_FRAME_ALIGNER_MODE_NONE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    if(m_zoomSlider)
    {
        m_zoomSlider->setAnchor(0.5f, 0.0f);
        m_zoomSlider->setPos(s.width - ZOOM_SLIDER_CENTER, ZOOM_SLIDER_TOP);
        m_zoomSlider->setLayout(VCP_SLIDER_LAYOUT_VERT);
        m_zoomSlider->setLength(
            s.height - ZOOM_SLIDER_TOP
            - (landscape ? ZOOM_SLIDER_BOTTOM_LANDSCAPE : ZOOM_SLIDER_BOTTOM_PORTRAIT));
        m_zoomSlider->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_NONE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}

void VappImageViewerComponent::hideZoomSlider(const VfxBool hide)
{
    if(m_zoomInLabel)
        m_zoomInLabel->setHidden(hide);
    if(m_zoomOutLabel)
        m_zoomOutLabel->setHidden(hide);
    if(m_zoomSlider)
        m_zoomSlider->setHidden(hide);
}

VfxBool VappImageViewerComponent::hasZoomSlider()
{
    // check full-app case or Image Viewer CUI case
    VcuiGalleryImageViewer *cui = VFX_OBJ_DYNAMIC_CAST(getRootApp(), VcuiGalleryImageViewer);

    // in ImageViewer CUI, there is no slider.
    if(cui)
    {
        return VFX_FALSE;
    }
    return m_option.supportZoom;
}

VcpSlider* VappImageViewerComponent::getZoomSlider()
{
    return m_zoomSlider;
}

VfxImageFrame* VappImageViewerComponent::getZoomOutLabel()
{
    return m_zoomOutLabel;
}

VfxImageFrame* VappImageViewerComponent::getZoomInLabel()
{
    return m_zoomInLabel;
}
#endif

void VappImageViewerComponent::createViewControl()
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
    if(m_viewSlider){return;}

    const VfxSize s = getSize();

    VFX_OBJ_CREATE(m_viewSlider, VcpSlider, this);
    m_viewSlider->setMaxValue(1);
    m_viewSlider->setMinValue(0);
    m_viewSlider->setCurrentValue(0.5f);
    m_viewSlider->m_signalThumbPressed.connect(this, &VappImageViewerComponent::onBeginChangeView);
    m_viewSlider->m_signalThumbReleased.connect(this, &VappImageViewerComponent::onEndChangeView);
    m_viewSlider->m_signalThumbDrag.connect(this, &VappImageViewerComponent::onChangeView);
    m_viewSlider->setAnchor(0.5f, 0.5f);
    m_viewSlider->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_viewPrevLabel, VfxFrame, this);
    VFX_OBJ_CREATE(m_viewNextLabel, VfxFrame, this);
    m_viewPrevLabel->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IMG_MAV_LEFT));
    m_viewNextLabel->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IMG_MAV_RIGHT));
    m_viewPrevLabel->setSize(VIEW_SLIDER_ARROW_W, VIEW_SLIDER_ARROW_H);
    m_viewNextLabel->setSize(VIEW_SLIDER_ARROW_W, VIEW_SLIDER_ARROW_H);
    m_viewPrevLabel->setAnchor(0.f, 0.5f);
    m_viewNextLabel->setAnchor(0.f, 0.5f);
    m_viewPrevLabel->setHidden(VFX_TRUE);
    m_viewNextLabel->setHidden(VFX_TRUE);

    layoutViewControl();
#else
    if(m_mavIconFrame){return;}

    VfxImageSrc imgMavIcon(IMG_ID_VAPP_GALLERY_IMG_MAV_ICON);
    VFX_OBJ_CREATE(m_mavIconFrame, VfxFrame, this);
    m_mavIconFrame->setSize(imgMavIcon.getSize());
    m_mavIconFrame->setAnchor(0.5f, 0.5f);

    m_mavIconFrame->setIsUnhittable(VFX_TRUE);
    m_mavIconFrame->setImgContent(imgMavIcon);
    m_mavIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_mavIconFrame->setHidden(VFX_TRUE);
#endif
#endif //__MULTIPLE_ANGLE_VIEW_SUPPORT__
}

void VappImageViewerComponent::layoutViewControl()
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if((NULL == m_viewSlider || NULL == m_viewPrevLabel || NULL == m_viewNextLabel)
        && (NULL == m_mavIconFrame))
    {
        VFX_OBJ_CLOSE(m_viewSlider);
        VFX_OBJ_CLOSE(m_viewPrevLabel);
        VFX_OBJ_CLOSE(m_viewNextLabel);
        VFX_OBJ_CLOSE(m_mavIconFrame);
        createViewControl();
    }

    VfxScrRotateTypeEnum screenRotation = findScreen()->getRotateType();
    switch(screenRotation)
    {
    case VFX_SCR_ROTATE_TYPE_0:
    case VFX_SCR_ROTATE_TYPE_180:
        #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
        m_viewSlider->setLength(VIEW_SLIDER_LENGTH);
        m_viewSlider->setPos(VIEW_SLIDER_X, VIEW_SLIDER_Y);
        m_viewPrevLabel->setPos(VIEW_SLIDER_ARROW_L_X, VIEW_SLIDER_Y);
        m_viewNextLabel->setPos(VIEW_SLIDER_ARROW_R_X, VIEW_SLIDER_Y);
        #else
        m_mavIconFrame->setPos(VIEW_SLIDER_X, VIEW_SLIDER_Y);
        #endif
        break;
    case VFX_SCR_ROTATE_TYPE_90:
    case VFX_SCR_ROTATE_TYPE_270:
        #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
        m_viewSlider->setLength(HORZ_VIEW_SLIDER_LENGTH);
        m_viewSlider->setPos(HORZ_VIEW_SLIDER_X, HORZ_VIEW_SLIDER_Y);
        m_viewPrevLabel->setPos(HORZ_VIEW_SLIDER_ARROW_L_X, HORZ_VIEW_SLIDER_Y);
        m_viewNextLabel->setPos(HORZ_VIEW_SLIDER_ARROW_R_X, HORZ_VIEW_SLIDER_Y);
        #else
        m_mavIconFrame->setPos(HORZ_VIEW_SLIDER_X, HORZ_VIEW_SLIDER_Y);
        #endif
        break;
    }
#endif //__MULTIPLE_ANGLE_VIEW_SUPPORT__
}

void VappImageViewerComponent::updateViewControlByPanel(VappGalleryViewerPanel *panel)
{
    if(NULL == m_viewSlider && NULL == m_mavIconFrame)
    {
        return;
    }

    GALLERY_MEASURE_TIME_START("Guv");

    VfxWString filePath = VFX_WSTR_EMPTY;
    if(OK != getMediaPath(panel, filePath))
    {
        #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
        m_viewSlider->setHidden(VFX_TRUE);
        m_viewPrevLabel->setHidden(VFX_TRUE);
        m_viewNextLabel->setHidden(VFX_TRUE);
        #else
        m_mavIconFrame->setHidden(VFX_TRUE);
        #endif

        GALLERY_MEASURE_TIME_STOP("Guv");
        return;
    }

    VfxS32 frameCount = panel->getFrameCount();
    if(0 < frameCount )
    {
        // update UI
        #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
        m_viewSlider->setMinValue(0);
        m_viewSlider->setMaxValue(1);
        VfxS32 frameIndex = panel->getFrameIndex();
        VfxFloat value = (VfxFloat)frameIndex / (VfxFloat)(frameCount - 1);
        value = VFX_MIN(frameCount - 1, VFX_MAX(0, value));
        m_viewSlider->setCurrentValue(value);
        m_viewSlider->setHidden(VFX_FALSE);
        m_viewPrevLabel->setHidden(VFX_FALSE);
        m_viewNextLabel->setHidden(VFX_FALSE);
        #else
        m_mavIconFrame->setHidden(VFX_FALSE);
        #endif

        // G sensor logic
        if(getCurrentPanel() == panel)
        {
            setupGSensor();
        }
    }
    else
    {
        // update UI
        #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
        m_viewSlider->setHidden(VFX_TRUE);
        m_viewPrevLabel->setHidden(VFX_TRUE);
        m_viewNextLabel->setHidden(VFX_TRUE);
        #else
        m_mavIconFrame->setHidden(VFX_TRUE);
        #endif

        // G sensor logic
        if(getCurrentPanel() == panel)
        {
            teardownGSensor();
        }
    }

    GALLERY_MEASURE_TIME_STOP("Guv");
}

VcpSlider* VappImageViewerComponent::getViewSlider()
{
    return m_viewSlider;
}

VfxFrame* VappImageViewerComponent::getViewPrevLabel()
{
    return m_viewPrevLabel;
}

VfxFrame* VappImageViewerComponent::getViewNextLabel()
{
    return m_viewNextLabel;
}

VfxFrame* VappImageViewerComponent::getMavIconFrame()
{
    return m_mavIconFrame;
}

void VappImageViewerComponent::setupGSensor()
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_SETUP_G_SENSOR);

    if(!m_enableGSensorSupport || m_isDuringFileOperation){return;}
    m_gSensor->startListen(GM_TILT, NULL);
#endif
}

void VappImageViewerComponent::teardownGSensor()
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_TEARDOWN_G_SENSOR);
    m_gSensor->stopListen(GM_TILT);
#endif
}

void VappImageViewerComponent::enableGSensorSupport(const VfxBool enable)
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENABLE_G_SENSOR_SUPPORT, enable);
    if(enable)
    {
        m_enableGSensorSupport = VFX_TRUE;
    }
    else
    {
        m_enableGSensorSupport = VFX_FALSE;
        // make sure we tear down G sensor support
        teardownGSensor();
    }
#endif
}

void VappImageViewerComponent::create3DRedBlueIcon()
{
#ifdef __VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
    if(m_3dRedBlueImageIcon){return;}

    VfxImageSrc icon(IMG_ID_VAPP_GALLERY_IMG_3D_RB_ICON);
    VFX_OBJ_CREATE(m_3dRedBlueImageIcon, VfxFrame, this);
    m_3dRedBlueImageIcon->setSize(icon.getSize());
    m_3dRedBlueImageIcon->setAnchor(0.5f, 0.5f);

    m_3dRedBlueImageIcon->setImgContent(icon);
    m_3dRedBlueImageIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_3dRedBlueImageIcon->setHidden(VFX_TRUE);
    m_3dRedBlueImageIcon->setIsUnhittable(VFX_TRUE);
#endif //__VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
}

void VappImageViewerComponent::layout3DRedBlueIcon()
{
#ifdef __VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
    if(NULL == m_3dRedBlueImageIcon)
    {
        create3DRedBlueIcon();
    }

    VfxScrRotateTypeEnum screenRotation = findScreen()->getRotateType();
    switch(screenRotation)
    {
    case VFX_SCR_ROTATE_TYPE_0:
    case VFX_SCR_ROTATE_TYPE_180:
        m_3dRedBlueImageIcon->setPos(VIEW_SLIDER_X, VIEW_SLIDER_Y);
        break;
    case VFX_SCR_ROTATE_TYPE_90:
    case VFX_SCR_ROTATE_TYPE_270:
        m_3dRedBlueImageIcon->setPos(HORZ_VIEW_SLIDER_X, HORZ_VIEW_SLIDER_Y);
        break;
    }
#endif //__VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
}

void VappImageViewerComponent::update3DRedBlueIcon(VappGalleryViewerPanel *panel)
{
#ifdef __VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
    if(NULL == m_3dRedBlueImageIcon || NULL == panel)
    {
        return;
    }

    GALLERY_MEASURE_TIME_START("Gur");
    const VfxBool is3dRedBlueImg = panel->getIs3DRedBlueImage(); 
    m_3dRedBlueImageIcon->setHidden(!is3dRedBlueImg);
    GALLERY_MEASURE_TIME_STOP("Gur");
#endif //__VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
}

VfxFrame* VappImageViewerComponent::get3DRedBlueIcon()
{
    return m_3dRedBlueImageIcon;
}

void VappImageViewerComponent::handlePageUiAnim(const VfxBool disableAutoAnim, const VfxU64 duration)
{
#if !defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__)
    // tap event trigger UI auto high animation
    if(getCurrentPanel())
        getCurrentPanel()->startAnimTimer(disableAutoAnim, (VfxMsec)duration, __LINE__);
#endif
}

void VappImageViewerComponent::createKeypadLongPressTimer()
{
    if(NULL == m_keypadLongPressTimer)
    {
        VFX_OBJ_CREATE(m_keypadLongPressTimer, VfxTimer, this);
        m_keypadLongPressTimer->setStartDelay(0);
        m_keypadLongPressTimer->setDuration(KEYPAD_LONG_PRESS_TIMER_DURATION);
        m_keypadLongPressTimer->m_signalTick.connect(this, &VappImageViewerComponent::onKeypadLongPressimeout);
    }
}

VappGalleryViewerPanel* VappImageViewerComponent::createViewerPanel()
{
    // create panel in the panel container,
    // so their z-order is grouped.
    VappGalleryViewerPanel* panel = NULL;
    VFX_OBJ_CREATE(panel, VappGalleryViewerPanel, this->m_viewerPanelContainer);
    VFX_DEV_ASSERT(panel);

    // initialize panel properties
    panel->setPos(0, 0);
    panel->setSize(getSize());
    panel->setAutoAnimate(VFX_TRUE);
    panel->m_signalPlayCommand.connect(this, &VappImageViewerComponent::onPlayMedia);
    panel->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    return panel;
}

void VappImageViewerComponent::clearAllPanel()
{
    // release panel resources
    for(int i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        VappGalleryViewerPanel *panel = m_viewPanels[i];
        if(panel)
        {
            clearPanel(panel);
        }
    }
}

VappGalleryViewerPanel* VappImageViewerComponent::getPanel(PanelPosition panelPos)
{
    switch(panelPos)
    {
    case LEFT_PANEL:
        return m_viewPanels[getLeftPanelIndex()];
    case RIGHT_PANEL:
        return m_viewPanels[getRightPanelIndex()];
    case CURRENT_PANEL:
        return m_viewPanels[m_currentPanel];
    }
	return NULL;
}

void VappImageViewerComponent::clearPanel(VappGalleryViewerPanel *panel)
{
    if(NULL == panel)
    {
        return;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CLEAR_PANEL, panel->getMediaIndex(), panel->hasCachedBuffer());

    do
    {
        if(NULL == m_mediaList)
            break;
#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
        VappGalleryMediaListAsync *asyncMediaList = VFX_OBJ_DYNAMIC_CAST(m_mediaList, VappGalleryMediaListAsync);
        if(NULL == asyncMediaList)
            break;

        VcpMenuPos menuPos;
        menuPos.group = 0;
        menuPos.pos = panel->getMediaIndex();
        asyncMediaList->stopDecode(menuPos);
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */
    }while(0);

    if(panel->hasCachedBuffer())
    {
        ASSERT(panel->hasMediaIndex());
        MediaIndex idx = panel->getMediaIndex();
        VfxImageBuffer cachedBuf;
        panel->getPreviewCachedBuffer(cachedBuf);

        // update panel content first
        panel->clear();
        // then release cache buffer
        m_mediaList->unlockThumb(VcpMenuPos(0, idx), cachedBuf);
    }
    else
    {
        // update panel content
        panel->clear();
    }
}

void VappImageViewerComponent::onPlayMedia(MediaIndex mediaIdx)
{
    if(NULL == m_mediaList)
    {
        return;
    }
    const VcpMenuPos mediaPos(0, mediaIdx);
    if(MEDIA_GROUP_VIDEO == m_mediaList->getMediaGroupType(mediaPos))
    {
        VfxWString path;
        if(OK == m_mediaList->getMediaPath(mediaPos, path))
        {
            notifyMediaPlayCommand(path);
        }
    }
}

void VappImageViewerComponent::rotateImagePreview()
{
    getCurrentPanel()->rotateCW();
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    updateZoomSliderByPanel(getCurrentPanel());
#endif
}

VappGalleryViewerPanel* VappImageViewerComponent::getCurrentPanel()
{
    return m_viewPanels[m_currentPanel];
}

void VappImageViewerComponent::suspendDecodeByFileOpInterrupt()
{
    m_isDuringFileOperation = VFX_TRUE;
    enableGSensorSupport(VFX_FALSE);
    stopAllDecoding();
}

void VappImageViewerComponent::resumeDecodeAfterFileOpInterrupt()
{
    m_isDuringFileOperation = VFX_FALSE;
    enableGSensorSupport(VFX_TRUE);
    if(m_previewTimer)
    {
        m_previewTimer->start();
    }

    if(m_mediaList && m_mediaList->isPrepared())
    {
        m_mediaList->enableBackgroundDecode(VFX_TRUE);
    }
}

void VappImageViewerComponent::handleFileDeleted(const VfxBool result)
{
    if(result)
    {
        // delete file successfully
        // update file list and set new focused file
        clearAllPanel();
        if(m_mediaList && m_mediaList->canRefreshList())
        {
            if(m_previewTimer)
            {
                m_previewTimer->stop();
            }
            m_mediaList->refreshList();
        }
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        updateZoomSliderByPanel(getCurrentPanel());
#endif

        updateViewControlByPanel(getCurrentPanel());
        update3DRedBlueIcon(getCurrentPanel());
        return;
    }

    // delete file failed, check if provider should refresh now
    if(shouldRefreshProvider())
    {
        m_mediaList->refreshList();
    }
    else
    {
        if(isCurrentPreviewMAV())
            setupGSensor();
    }
}

void VappImageViewerComponent::stopAllDecoding()
{
    // stop checking panels
    if(m_previewTimer)
    {
        m_previewTimer->stop();
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    stopEnhance();  // this resumes preview decode
#endif

    // stop review decode
    if(m_mediaList && m_mediaList->isPrepared())
    {
        m_mediaList->enableBackgroundDecode(VFX_FALSE);
    }

    // also need to stop animated GIF decoding
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    VfxWString path;
    const VappGalleryDecodeResult resPath = getCurrentMediaPath(path);
    if(curPanel && curPanel->isDisplayImage() && (OK == resPath) && curPanel->getIsAnimedGif())
    {
        curPanel->setPreviewImageAnimated(VFX_FALSE);
    }
}

VfxScrRotateTypeEnum VappImageViewerComponent::getScreenRotation() const
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxScrRotateTypeEnum screenRotation = renderer->getPreScreenRotateType();
    return screenRotation;
}

void VappImageViewerComponent::notifyGestureEvent(VappGalleryGesture gesture, VfxS32 index)
{
    m_signalGesture.emit(gesture, index);
}

void VappImageViewerComponent::notifyCurrentPanelChanged(const VfxS32 currentIndex)
{
    m_signalCurrentPanelChanged.emit(currentIndex);
}

void VappImageViewerComponent::notifyProviderUpdatedEvent(const VfxS32 meidaCount)
{
    m_signalProviderUpdated.emit(meidaCount);
}

void VappImageViewerComponent::notifyMediaPlayCommand(VfxWString &path)
{
    m_signalMediaPlayCommand.emit(path);
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
void VappImageViewerComponent::notifyZoomSliderEvent(VfxBool isZooming)
{
    m_signalZoomSlider.emit(isZooming);
}
#endif

void VappImageViewerComponent::notifyViewSliderEvent(VfxBool isDragging)
{
    m_signalViewSlider.emit(isDragging);
}

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
void VappImageViewerComponent::notifySlideshowStopped()
{
    m_signalSideshowStopped.emit();
}
#endif

void VappImageViewerComponent::notifyStartDisplayMedia()
{
    m_signalStartDisplayMedia.emit();
}

VfxApp* VappImageViewerComponent::getRootApp()const
{
    return VfxMainScr::findMainScr(getParentFrame())->getApp();
}

void VappImageViewerComponent::sendCurrentViewedFilePathMsg()
{
    if(!getCurrentPanel()->hasMediaIndex()){return;}
    if(NULL == m_mediaList){return;}

    VcpMenuPos menuPos;
    menuPos.group = 0;
    menuPos.pos = getCurrentPanel()->getMediaIndex();

    sendFilePathMsg(menuPos, 0);
}

void VappImageViewerComponent::sendFilePathMsg(const VcpMenuPos menuPos, const VfxS32 serialNum)
{
    if(!getCurrentPanel()->hasMediaIndex()){return;}
    if(NULL == m_mediaList){return;}

    // send message to inidicates that file path of the decoded image
    VfxWString path = VFX_WSTR_EMPTY;
    m_mediaList->getMediaPath(menuPos, path);
}

void VappImageViewerComponent::setInitState(VappGalleryViewerMediaState initState)
{
    m_initState = initState;
}

VappGalleryViewerMediaState VappImageViewerComponent::getInitState() const
{
    return m_initState;
}

void VappImageViewerComponent::consumeDRM(VfxImageSrc src)
{
    if(m_drmConsumer)
    {
        m_drmConsumer->setFileAndUserData(src.getPath(), NULL);
        m_drmConsumer->startConsume();
    }
}

VappImageViewerComponent::GestureEvent* VappImageViewerComponent::getGestureEvent()
{
    return &m_signalGesture;
}

VappImageViewerComponent::CurrentPanelChangedEvent* VappImageViewerComponent::getCurrentPanelChangedEvent()
{
    return &m_signalCurrentPanelChanged;
}

VappImageViewerComponent::ProviderUpdatedEvent* VappImageViewerComponent::getProviderUpdatedEvent()
{
    return &m_signalProviderUpdated;
}

VappImageViewerComponent::MediaPlayCommandEvent* VappImageViewerComponent::getMediaPlayCommandEvent()
{
    return &m_signalMediaPlayCommand;
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
VappImageViewerComponent::ZoomSliderEvent* VappImageViewerComponent::getZoomSliderEvent()
{
    return &m_signalZoomSlider;
}
#endif

VappImageViewerComponent::ViewSliderEvent* VappImageViewerComponent::getViewSliderEvent()
{
    return &m_signalViewSlider;
}

VappImageViewerComponent::StartDisplayMediaEvent* VappImageViewerComponent::getStartDisplayMediaEvent()
{
    return &m_signalStartDisplayMedia;
}

VappGalleryDecodeResult VappImageViewerComponent::getMediaPath(VappGalleryViewerPanel *panel, VfxWString &path)
{
    if(NULL == panel)
    {
        return UNEXPECTED;
    }

    if(!panel->hasMediaIndex())
    {
        // from single file
        VfxImageSrc src;
        if(!panel->getPreviewImage(src) ||
            src.getType() != VFX_IMAGE_SRC_TYPE_PATH)
        {
            return UNEXPECTED;
        }

        path = src.getPath();
        return OK;
    }
    else
    {
        // from media list
        VcpMenuPos menuPos;
        menuPos.group = 0;
        menuPos.pos = panel->getMediaIndex();
        return m_mediaList->getMediaPath(menuPos, path);
    }
}

VappGalleryDecodeResult VappImageViewerComponent::getCurrentMediaPath(VfxWString &path)
{
    return getMediaPath(getCurrentPanel(), path);
}

void VappImageViewerComponent::getCurrentMediaName(VfxWString &fileName)
{
    fileName = VFX_WSTR_EMPTY;
    if(m_initState.isSingleFile())
    {
        VfxWString path;
        if(OK == getCurrentMediaPath(path))
        {
            fileName = VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr((WCHAR*)path.getBuf()));
        }
    }
    else if(m_mediaList && m_mediaList->isPrepared())
    {
        VcpMenuPos currentPos(0, m_currentIndex);
        m_mediaList->getMediaName(currentPos, fileName);
    }
}

VfxBool VappImageViewerComponent::isProviderPrepared() const
{
    return (m_mediaList && m_mediaList->isPrepared());
}

VfxBool VappImageViewerComponent::isCurrentPreviewImageVisible()
{
    const VfxBool isImageVisible = (m_mediaList &&
                                    m_mediaList->isPrepared() &&
                                    getCurrentPanel() &&
                                    isPanelReady(getCurrentPanel(), m_currentIndex) &&
                                    getCurrentPanel()->isDisplayImage());
    return isImageVisible;
}

VfxBool VappImageViewerComponent::isCurrentPreviewVideo()
{
    const VfxBool isVideo = (m_mediaList &&
                             m_mediaList->isPrepared() &&
                             MEDIA_GROUP_VIDEO == m_mediaList->getMediaGroupType(VcpMenuPos(0, m_currentIndex)));
    return isVideo;
}

VfxBool VappImageViewerComponent::isCurrentPreviewMAV()
{
    if(m_mediaList && m_mediaList->isPrepared())
    {
        VfxWString path = VFX_WSTR_EMPTY;
        if(OK != getCurrentMediaPath(path))
        {
            return VFX_FALSE;
        }

        VappGalleryViewerPanel *panel = getCurrentPanel();
        return (panel ? panel->getIsMAV() : VFX_FALSE);
    }

    return VFX_FALSE;
}

VfxBool VappImageViewerComponent::hasValidMediaList() const
{
    return ((m_mediaList)? VFX_TRUE : VFX_FALSE);
}

VfxBool VappImageViewerComponent::canCheckDirty() const
{
    if(NULL == m_mediaList){return VFX_FALSE;}
    return m_mediaList->canCheckDirty();
}

VfxBool VappImageViewerComponent::checkDirty() const
{
    if(NULL == m_mediaList){return VFX_FALSE;}
    return m_mediaList->checkDirty();
}

VfxBool VappImageViewerComponent::canRefresh() const
{
    if(NULL == m_mediaList){return VFX_FALSE;}
    return m_mediaList->canRefreshList();
}

VfxBool VappImageViewerComponent::shouldRefreshProvider() const
{
    return (m_mediaList &&
            m_mediaList->canRefreshList() &&
            m_mediaList->canCheckDirty() &&
            m_mediaList->checkDirty());
}

void VappImageViewerComponent::refresh()
{
    if(NULL == m_mediaList)
    {
        return;
    }
    // update search pattern
    VappGalleryMediaListCommon *mediaCacheList = static_cast<VappGalleryMediaListCommon*>(m_mediaList);
    if(mediaCacheList)
    {
        mediaCacheList->configSearchPattern(&(m_initState.m_focusFile));
    }
    // refresh
    m_mediaList->refreshList();
}

void VappImageViewerComponent::hideAllPanel(const VfxBool isHide)
{
    if(m_viewerPanelContainer)
        m_viewerPanelContainer->setHidden(isHide);

}

void VappImageViewerComponent::onBoundsChange(VfxFrame *frm, const VfxRect &oldRect)
{
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    layoutZoomSlider();
#endif

    layoutViewControl();
    layout3DRedBlueIcon();

    // Apps may create viewerCP after page onInit, miss timing for panel init pos correction in onEnter, and
    // VfxFrameAligner::alignParentFrame change panel pos to align viewCP
    // in order to guarantee corrent init pos of panels,
    // we always set panel viewerCP's size in viewerCP::onBoundsChange callback instead of align panel to viewCP
    getPanel(CURRENT_PANEL)->setSize(getSize());
    getPanel(LEFT_PANEL)->setSize(getSize());
    getPanel(RIGHT_PANEL)->setSize(getSize());

    snapPanelToInitialPosition(CURRENT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(LEFT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);
}

void VappImageViewerComponent::onListUpdated(VappGalleryPrepareResult prepareResult)
{
    if(NULL == m_mediaList)
    {
        return;
    }
    m_initState.m_refreshed = VFX_TRUE;

    const VfxU32 mediaCount = m_mediaList->getMediaCountInGroup(0);
    notifyProviderUpdatedEvent(mediaCount);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_LIST_UPDATED_MEDIA_COUNT, mediaCount);
    if(0 < mediaCount)
    {
        hideAllPanel(VFX_FALSE);
    }

    // adjust current media index, in case of file count change.
    if(!m_initState.m_displayed)
    {
        m_initState.m_displayed = VFX_TRUE;

        if(m_initState.m_useIndexInList)
        {
            // use "focused index"
            m_currentIndex = m_initState.m_focusIndex;
        }
        else if(!m_initState.m_isSyncContentProvider)
        {
            // async provider, always use index
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_LIST_UPDATED_MEDIA_COUNT_ASYNC_PROVIDER_FOCUS, m_initState.m_focusIndex);
            m_initState.m_useIndexInList = VFX_TRUE;
            m_currentIndex = m_initState.m_focusIndex;
        }
        else
        {
            // TODO: async case, shall we case async media list
            // use "focused file"
            VappGalleryMediaListCommon *mediaCacheList = static_cast<VappGalleryMediaListCommon*>(m_mediaList);
            VcpMenuPos pos;
            mediaCacheList->getStartingIndex(pos);
            m_currentIndex = pos.pos;
        }
    }

    // decide which file to focus:
    // if there is next file, focus it.
    // if last file, show previous one.
    // if no file left after deletion,
    // go back to thumbnail grid (which shows "no pictures").
    clearAllPanel();
    if(m_currentIndex >= (VfxS32)mediaCount)
    {
        m_currentIndex = (mediaCount - 1);
    }

    if(m_initState.m_autoPlaySlideshow)
    {
        m_initState.m_autoPlaySlideshow = VFX_FALSE;
        // make sure all panel's media id are assigned correctly
        checkAllPanel(__LINE__);
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
        playSlideshow();
#endif
    }
    else
    {
        // default case, start loading images
        m_previewTimer->start();
    }
}

VfxBool VappImageViewerComponent::isPanelReady(VappGalleryViewerPanel *panel, MediaIndex mediaIdx)
{
    if(NULL == panel)
        return VFX_FALSE;

    if(!panel->hasMediaIndex())
        return VFX_FALSE;

    if(panel->getMediaIndex() != mediaIdx)
        return VFX_FALSE;

    if(panel->isLoading())
        return VFX_FALSE;

    // media index match and already decoded.
    // this means this panel can be properly displayed.
    return VFX_TRUE;
}

void VappImageViewerComponent::onPreviewTimerCheck(VfxTimer *sender)
{
    if(NULL == m_mediaList || !m_mediaList->isPrepared())
    {
        sender->stop();
        return;
    }

    GALLERY_MEASURE_TIME_START("ATC");
    checkAllPanel(__LINE__);
    GALLERY_MEASURE_TIME_STOP("ATC");
}

void VappImageViewerComponent::onShiftAnimationFinish(VfxTimer *sender)
{
    VFX_UNUSED(sender);

    if(m_initState.isSingleFile())
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_SHIFT_ANIMATION_FINISH);
    VappGalleryViewerPanel *lp = getPanel(LEFT_PANEL);
    VappGalleryViewerPanel *rp = getPanel(RIGHT_PANEL);
    if(lp)
        lp->resetViewState();
    if(rp)
        rp->resetViewState();

    resetToInitViewedFrame(lp);
    resetToInitViewedFrame(rp);

    // reset mav g sensor logic
    enableGSensorSupport(VFX_TRUE);
    if(isCurrentPreviewMAV())
    {
        setupGSensor();
    }

    // update toolbar & slider
    // prepare new panel after updating current
    checkAllPanel(__LINE__);
    m_previewTimer->start();
}

VfxBool VappImageViewerComponent::isAsyncMediaListScenario()
{
#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
    if(m_mediaList)
    {
        VappGalleryMediaListAsync *pAsyncMediaList = VFX_OBJ_DYNAMIC_CAST(m_mediaList, VappGalleryMediaListAsync);
        if(pAsyncMediaList)
            return VFX_TRUE;
    }
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */
    return VFX_FALSE;
}

VfxBool VappImageViewerComponent::shouldReserveAdjacentPreview()
{
  return VFX_TRUE;
}

void VappImageViewerComponent::checkAllPanel(const VfxU32 line, VfxBool startEnhance)
{
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    if(NULL == curPanel || NULL == m_mediaList)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, -100);
        return;
    }

    // is current ready?
    if(!isPanelReady(curPanel, m_currentIndex) &&
        updatePanelMedia(curPanel, m_currentIndex))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, -200);
        return;
    }

    if(shouldReserveAdjacentPreview())
    {
        const MediaIndex nextIdx = getNextIndex();
        const MediaIndex prevIdx = getPrevIndex();

        // prepare next photo, if any
        if(nextIdx != m_currentIndex &&
           updatePanelMedia(getPanel(RIGHT_PANEL), nextIdx))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, -300);
            return;
        }

        // prepare prev photo, if any
        if(prevIdx != m_currentIndex &&
           updatePanelMedia(getPanel(LEFT_PANEL), prevIdx))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, -400);
            return;
        }
    }

    // at this point, all panels have preview image.
    // we now enhance it, or start playing it.
    if(!startEnhance)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, -500);
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHECK_ALL_PANEL, startEnhance, m_currentIndex, line, 0);

    // check if current panel is animated GIF, if so, start playing it,
    // otherwise see if we need to enhnace it
    if(curPanel->isDisplayImage() && curPanel->getIsAnimedGif())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_CHECK_ALL_PANEL_FOUND_ANIMATED_IMAGE_D, m_currentIndex);
        // for animated files, directly pass the file path
        if(curPanel->isOwnerDraw())
        {
            VcpMenuPos mediaPos(0, m_currentIndex);
            VfxImageSrc src;
            m_mediaList->getMediaSource(mediaPos, src);
            curPanel->setPreviewImage(src);
        }
        // check if we're about to display the current image.
        onStartDisplayMedia(m_currentIndex);

        // no further enhnace required for animated images
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    else if(isPanelReady(curPanel, m_currentIndex) && curPanel->isDisplayImage())
    {
        // start decode enhnace img immedidatly if project supports full enhance image decode
        // otherwise, we delay partial enhnace until recieves drawer start enhance callback
        #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
        if(enhancePanelMedia(curPanel, m_currentIndex))
            return;
        #endif
    }
#endif

    // all panels are ready to display, no need futher check
    m_previewTimer->stop();
}

VfxBool VappImageViewerComponent::updatePanelMedia(VappGalleryViewerPanel *panel, MediaIndex mediaIdx)
{
    // is the panel already display the media?
    // if so, return VFX_FALSE directly.
    if(isPanelReady(panel, mediaIdx))
    {
        return VFX_FALSE;
    }
	
    VcpMenuPos mediaPos(0, mediaIdx);
	VappGalleryMediaGroupType groupType = m_mediaList->getMediaGroupType(mediaPos);
	VfxImageBuffer resultBuf;
    VappGalleryDecodeResult result = DECODING;
	if(groupType == MEDIA_GROUP_ERROR)
	{
		result = UNEXPECTED;
	}
	else if(groupType != MEDIA_GROUP_WAIT_DECODING)
	{
		VfxBool isVideo = (MEDIA_GROUP_VIDEO == groupType);

	    // if the panel is displaying other media
	    // clear content first
	    // and update file info
	    if(panel->getMediaIndex() != mediaIdx)
	    {
	        // make sure there is no other panel displaying same media,
	        // since MediaCache cannot lock twice
	        VappGalleryViewerPanel *panelWithSameIndex = getPanelByMediaIndex(mediaIdx);
	        if(panelWithSameIndex)
	        {
	            clearPanel(panelWithSameIndex);
	        }

	        clearPanel(panel);

	        panel->setMediaIndex(mediaIdx, isVideo);

	        // if the panel have video button, we need to make its parent hittable.
	        // if not, make its parent unhittable, so that zoom slider fuzzy touch can work.
	        if((panel == getCurrentPanel()) && m_viewerPanelContainer)
	        {
	            m_viewerPanelContainer->setIsUnhittable(!panel->hasPlayButton());
	        }

	        // udpate file type info
	        updatePanelFileInfoImpl(panel, isVideo);
	    }

	    // if the new mediaIdx is invliad,
	    // no need further processing.
	    if(-1 == mediaIdx)
	    {
	        return VFX_FALSE;
	    }

	    // even if it is already decoding, we keep retry.
	    VfxBool enableVideoThumbDecode = VFX_FALSE;
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_VIDEO_THUMBAIL__
	    enableVideoThumbDecode = VFX_TRUE;
#endif

	    
	    if(!enableVideoThumbDecode && isVideo)
	        result = FORMAT_UNSUPPORTED;
	    else
	        result = m_mediaList->startDecodeThumb(mediaPos, resultBuf);
	}
    assignLockResultToPanel(mediaIdx, panel, result, resultBuf);
    return VFX_TRUE;
}

void VappImageViewerComponent::updatePanelFileInfoImpl(VappGalleryViewerPanel *panel, VfxBool isVideo)
{
    GALLERY_MEASURE_TIME_START("Guf");
    const MediaIndex mediaIdx = (panel) ? (panel->getMediaIndex()) : (-1);
    VfxWString filePath = VFX_WSTR_EMPTY;
    do
    {
        if(-1 == mediaIdx)
            return;
        if(OK != m_mediaList->getMediaPath(VcpMenuPos(0, mediaIdx), filePath))
            return;
        if(filePath.isNull() || filePath.isEmpty())
            return;
    }while(0);


    VfxU16 gdiImgFileType = GDI_IMAGE_TYPE_INVALID;
    VfxSize originalDim(0, 0);
    VfxBool isAnimatedGif = VFX_FALSE;
    VfxBool is3DRedBlue = VFX_FALSE;
    VfxS32 frameCount = 0;
    do
    {
        if(isVideo)
            break;

        // get image file type
        GALLERY_MEASURE_TIME_START("Ggf");
        gdiImgFileType = gdi_image_get_type_from_file((CHAR*)filePath.getBuf());
        GALLERY_MEASURE_TIME_STOP("Ggf");

        // get dimension
        GALLERY_MEASURE_TIME_START("Ggd");
        const GDI_RESULT dimRes = gdi_image_get_dimension_file((CHAR*)filePath.getBuf(), &originalDim.width, &originalDim.height);
        GALLERY_MEASURE_TIME_STOP("Ggd");

        // animated gif
        isAnimatedGif = isAnimatedImage(mediaIdx);

        // 3D red blue image
        is3DRedBlue = is3DRedBlueImage(filePath.getBuf(), gdiImgFileType);

        // update frame count and frameClipWindow for MAV type file
        #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        if(GDI_IMAGE_TYPE_MAV_FILE == gdiImgFileType || GDI_IMAGE_TYPE_MAV == gdiImgFileType)
        {
            GALLERY_MEASURE_TIME_START("Ggc");
            gdi_image_get_frame_count_file((U8*)filePath.getBuf(), &frameCount);
            GALLERY_MEASURE_TIME_STOP("Ggc");

            // because clip window calculation need to refer image buf size info,
            // calculat it in decode callback
        }
        #endif
    }while(0);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_UPDATE_FILE_INFO_IMPL, panel, mediaIdx, gdiImgFileType, frameCount);

    panel->setIsVideo(isVideo);
    panel->setImageType(gdiImgFileType);
    panel->setImageOriginalDimension(originalDim);
    panel->setIsAnimedGif(isAnimatedGif);
    panel->setIs3DRedBlueImage(is3DRedBlue);
    panel->setFrameCount(frameCount);
    GALLERY_MEASURE_TIME_STOP("Guf")
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
VfxBool VappImageViewerComponent::canEnhanceMedia(MediaIndex mediaIdx)
{
    // input check
    if(NULL == m_mediaList ||
       -1 == mediaIdx)
    {
        return VFX_FALSE;
    }

    VappGalleryViewerPanel *panel = getPanelByMediaIndex(mediaIdx);
    do
    {
        if(NULL == panel)
            return VFX_FALSE;
        if(panel->getIsVideo())
            return VFX_FALSE;
        if(panel->getIsAnimedGif())
            return VFX_FALSE;
        if(panel->getIsMAV())
            return VFX_FALSE;
    }while(0);
    return VFX_TRUE;
}

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
void VappImageViewerComponent::onPartialEnhnaceDecodeStart(VfxSize decodedLayerSize, VfxRect clipRect)
{
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    const MediaIndex mediaIdx = m_currentIndex;
    const VcpMenuPos mediaPos(0, mediaIdx);

    if(m_isSliderZooming)
        return;

    const EnhanceMediaCheckResult preCheckRes = enhancePanelMediaPreCheckImpl(curPanel, mediaIdx);
    if(ENHANCE_MEDIA_CHECK_BUF_NOT_READY == preCheckRes)
    {
        // because we will reset enhance buff ptr later, skip buffer not ready check
    }
    else if( ENHANCE_MEDIA_CHECK_SUCCESS > preCheckRes)
    {
        // other error caused by input media, not allow to decode enhance buffer
        return;
    }

    VfxWString path = VFX_WSTR_EMPTY;
    if(OK != getCurrentMediaPath(path))
        return;

    if(NULL == m_enhancedImage)
        return;

    // otherwise we start enhance it
    // since there is only 1 enhance image.
    // clear other panel's enhance state first
    for(VfxS32 i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        if(m_viewPanels[i] && m_viewPanels[i]->hasEnhancedBuffer())
        {
            m_viewPanels[i]->clearEnhnacedBuffer();
        }
    }

    // re-init enhance buffer
    VfxImageBuffer enhanceBuf;
    resetImageBuffer(enhanceBuf);
    if(!m_enhancedImage->setFileAndGetOutputBuffer(mediaIdx, path, enhanceBuf, decodedLayerSize))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ON_PARTIAL_ENHANCE_DECODE_START, mediaIdx, -1);
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ON_PARTIAL_ENHANCE_DECODE_START, mediaIdx, 0);

    // update enhance buffer according to clip window in current draw scenario
    m_enhanceChecksum = clipRect;

    // start decode
    VFX_OBJ_CLOSE(m_enhancer);
    VFX_OBJ_CREATE_EX(m_enhancer, VappGalleryImageThumbnail, this, (VFX_TRUE));
    m_enhancer->getReadySignal()->connect(this, &VappImageViewerComponent::onPartialEnhnaceDecodeFinished);
    m_enhancer->decode(path, enhanceBuf, clipRect, curPanel->getImageOriginalDimension());
}

void VappImageViewerComponent::onPartialEnhnaceDecodeFinished(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ON_PARTIAL_ENHANCE_DECODE_FINISHED, result);
    do
    {
        if(OK != result)
            break;

        VappGalleryViewerPanel *curPanel = getCurrentPanel();
        if(NULL == m_enhancedImage ||
           NULL == curPanel ||
           !curPanel->hasMediaIndex() ||
           -1 == curPanel->getMediaIndex())
        {
            break;
        }

        m_enhancedImage->finishDecode();
        if(!m_enhancedImage->isReadyToDecode(curPanel->getMediaIndex()))
            break;

        VfxImageBuffer buf;
        if(!m_enhancedImage->getOutputBuffer(buf))
            break;

        // update enhance buff
        if(curPanel->updateEnhanceBufToDraw(m_enhanceChecksum))
        {
            curPanel->setEnhancedBuffer(buf);
            curPanel->onFinishPartialEnhanceDecode(m_enhanceChecksum);
            updateZoomSliderByPanel(curPanel);
            return;
        }
    }while(0);

    stopEnhance();
}
#endif

void VappImageViewerComponent::onPartialEnhnaceDecodeCanceled()
{
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    m_enhanceChecksum = VfxRect(0, 0, 0, 0);
    VFX_OBJ_CLOSE(m_enhancer);
    VappGalleryViewerPanel *panel = getCurrentPanel();
    panel->onCancelPartialEnhanceDecode();
#endif
}

VappImageViewerComponent::EnhanceMediaCheckResult VappImageViewerComponent::enhancePanelMediaPreCheckImpl(VappGalleryViewerPanel *panel, MediaIndex mediaIdx)
{
    // input check
    if(NULL == m_mediaList ||
       NULL == panel ||
       NULL == m_enhancedImage ||
       -1 == mediaIdx ||
       !panel->hasMediaIndex() ||
       mediaIdx != panel->getMediaIndex())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 1, ENHANCE_MEDIA_CHECK_BUF_NOT_READY);
        return ENHANCE_MEDIA_CHECK_ERROR;
    }

    // if already enhanced, do nothing
    if(m_enhancedImage->isReadyToDecode(mediaIdx))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 2, ENHANCE_MEDIA_CHECK_BUF_NOT_READY);
        return ENHANCE_MEDIA_CHECK_BUF_NOT_READY;
    }

    // if decoding, keep waiting
    if(m_enhancedImage->isDecoding(mediaIdx))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 3, ENHANCE_MEDIA_CHECK_IS_DECODING);
        return ENHANCE_MEDIA_CHECK_IS_DECODING;
    }

    // make sure it's an enhancable media
    if(!canEnhanceMedia(mediaIdx))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 4, ENHANCE_MEDIA_CHECK_ERROR);
        return ENHANCE_MEDIA_CHECK_ERROR;
    }

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    // make sure we do not decode enhance buffer while slideshow is playing
    if(isPlayingSlideshow())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 5, ENHANCE_MEDIA_CHECK_ERROR);
        return ENHANCE_MEDIA_CHECK_ERROR;
    }
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA_PRE_CHECK_IMPL, mediaIdx, 6, ENHANCE_MEDIA_CHECK_SUCCESS);
    return ENHANCE_MEDIA_CHECK_SUCCESS;
}

VfxBool VappImageViewerComponent::enhancePanelMedia(
    VappGalleryViewerPanel *panel,
    MediaIndex mediaIdx)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_TRY_ENHANCE_PANEL_MEDIA);
    // 1. input check,
    // only preCheckRes is ENHANCE_MEDIA_CHECK_SUCCESS, we can start full enhance decode
    EnhanceMediaCheckResult preCheckRes = enhancePanelMediaPreCheckImpl(panel, mediaIdx);
    do
    {
        if(ENHANCE_MEDIA_CHECK_SUCCESS == preCheckRes)
            break;
        if(ENHANCE_MEDIA_CHECK_IS_DECODING == preCheckRes)
            return VFX_TRUE;
        return VFX_FALSE;
    }while(0);

    // otherwise we start enhance it
    // since there is only 1 enhance image.
    // clear other panel's enhance state first
    for(VfxS32 i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        if(m_viewPanels[i] && m_viewPanels[i]->hasEnhancedBuffer())
        {
            m_viewPanels[i]->clearEnhnacedBuffer();
        }
    }

    // 2. then, prepare the image buffer with new size
    VfxImageBuffer enhanceBuf;
    resetImageBuffer(enhanceBuf);
    const VcpMenuPos mediaPos(0, mediaIdx);
    VfxWString path;
    if(OK == m_mediaList->getMediaPath(mediaPos, path) &&
       !m_enhancedImage->setFileAndGetOutputBuffer(mediaIdx, path, enhanceBuf))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA, mediaIdx, -100,  enhanceBuf.width, enhanceBuf.height);
        return VFX_FALSE;
    }

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    // make MediaCache pause decoding L1 previews
    if(m_mediaList)
    {
        m_mediaList->enableBackgroundDecode(VFX_FALSE);
    }

    if(NULL == m_enhancer)
    {
        VFX_OBJ_CREATE(m_enhancer, VappGalleryImageThumbnail, this);
        m_enhancer->getReadySignal()->connect(this, &VappImageViewerComponent::onEnhanceResult);
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_ENHANCE_PANEL_MEDIA, mediaIdx, mediaIdx, 0,  enhanceBuf.width, enhanceBuf.height);
    m_enhancer->decode(path, enhanceBuf);
#endif
    // enhance starts
    return VFX_TRUE;
}

void VappImageViewerComponent::onEnhanceResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ENHANCE_RESULT_D, result);
    do
    {
        if(OK != result)
            break;

        VappGalleryViewerPanel *curPanel = getCurrentPanel();
        if(NULL == m_enhancedImage ||
           NULL == curPanel ||
           !curPanel->hasMediaIndex() ||
           -1 == curPanel->getMediaIndex())
        {
            break;
        }

        m_enhancedImage->finishDecode();
        if(!m_enhancedImage->isReadyToDecode(curPanel->getMediaIndex()))
            break;

        VfxImageBuffer buf;
        if(!m_enhancedImage->getOutputBuffer(buf))
            break;

        // update enhance buff
        curPanel->setEnhancedBuffer(buf);
        updateZoomSliderByPanel(curPanel);
        return;
    }while(0);

    stopEnhance();
}

void VappImageViewerComponent::stopEnhance()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_STOP_ENHANCE);
    if(m_enhancer)
    {
        VFX_OBJ_CLOSE(m_enhancer);
        m_enhancer = NULL;
    }
    if(m_enhancedImage)
    {
    	m_enhancedImage->reset();
    }

    // resume MediaCache background decoding
    if(m_mediaList && m_mediaList->isPrepared())
    {
        m_mediaList->enableBackgroundDecode(VFX_TRUE);
    }
}
#endif

VfxS32 VappImageViewerComponent::getPanelInitialPos(PanelPosition panelPos)
{
    if(CURRENT_PANEL == panelPos)
    {
        return 0;
    }
    const VfxS32 viewWidth = PANEL_PADDING + getSize().width;
    if(LEFT_PANEL == panelPos)
        return -viewWidth;
    else
        return viewWidth;
}

void VappImageViewerComponent::offsetVisiblePanels(VfxS32 offsetX, VfxBool isAnim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_OFFSET_VISIBLE_PANELS_OFFSET_X_D_IS_ANIM_D, offsetX, isAnim);
    if(NULL == getCurrentPanel())
    {
        return;
    }
    const VfxPoint curPanelPos = getCurrentPanel()->getPos();

    VfxBool goNext = offsetX < 0;

    if(goNext && !canGoNext() && curPanelPos.x <= 0)
    {
        getCurrentPanel()->setPos(0, curPanelPos.y);
        showBallonIfMultiFile(STR_ID_VAPP_GALLERY_IMG_LAST_PHOTO);
        return;
    }
    else if(!goNext && !canGoPrevious() && curPanelPos.x >= 0)
    {
        getCurrentPanel()->setPos(0, curPanelPos.y);
        showBallonIfMultiFile(STR_ID_VAPP_GALLERY_IMG_FIRST_PHOTO);
        return;
    }

    // stop g-sensor
    teardownGSensor();

    for(VfxS32 i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        VappGalleryViewerPanel *panel = m_viewPanels[i];
        if(NULL == panel || panel->getHidden())
        {
            continue;
        }

        // since we started moving, disable GIF animation
        panel->setPreviewImageAnimated(VFX_FALSE);

        panel->startAnimTimer(!isAnim, PANNING_ANIM_DURATION, __LINE__);
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(!isAnim);
        VfxAutoAnimate::setDuration(PANNING_ANIM_DURATION);

        VfxPoint pos = panel->getPos();
        pos.x += offsetX;
        panel->setPos(pos);

        VfxAutoAnimate::commit();
    }
}

void VappImageViewerComponent::snapPanelToInitialPosition(PanelPosition panelPos, VfxBool isAnim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_SNAP_PANEL_TO_INITIAL_POSITION_PANEL_D_IS_ANIM_D, panelPos, isAnim);
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    VfxAutoAnimate::setDuration(SLIDE_ANIM_DURATION);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    VappGalleryViewerPanel *panel = getPanel(panelPos);
    if(panel)
    {
        VfxPoint curPos = panel->getPos();
        curPos.x = getPanelInitialPos(panelPos);
        panel->setPos(curPos);
    }

    if(isAnim)
    {
        // after animation,
        // we should reset the zoom setting of panels,
        // re-enable UI and
        if(NULL == m_panelShiftFinishTimer)
        {
            VFX_OBJ_CREATE(m_panelShiftFinishTimer, VfxTimer, this);
            m_panelShiftFinishTimer->setStartDelay(SLIDE_ANIM_DURATION);
            m_panelShiftFinishTimer->m_signalTick.connect(this, &VappImageViewerComponent::onShiftAnimationFinish);
        }
        else
        {
            m_panelShiftFinishTimer->stop();
        }
        enableGSensorSupport(VFX_FALSE);
        m_panelShiftFinishTimer->start();

        if(panel)
            panel->startAnimTimer(VFX_FALSE, SLIDE_ANIM_DURATION, __LINE__);
    }

    VfxAutoAnimate::commit();
}

void VappImageViewerComponent::shiftPanel(VfxBool isGoNext)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_GO_NEXT_DIR_D_IDX_D_PANEL_D, isGoNext, m_currentIndex, m_currentPanel);
    GALLERY_MEASURE_TIME("VSP");

    // stop g sensor to avoid tearing caused by decode image frame
    teardownGSensor();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    onPartialEnhnaceDecodeCanceled();
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    VappGalleryViewerPanel *pOldCurrentPanel = getCurrentPanel();
    if(pOldCurrentPanel)
    {
        pOldCurrentPanel->m_signalStartDecodeL1EnhanceBuf.disconnect(this, &VappImageViewerComponent::onPartialEnhnaceDecodeStart);
    }
    #endif
#endif

    // 1. Check if panel have proper media index
    // 2. Assign panel as current panel
    // 3. Assign panel's media index as current media index
    const MediaIndex newMediaIndex = isGoNext ? getNextIndex() : getPrevIndex();
    const panelID newCurrentPanel = isGoNext ? getRightPanelIndex() : getLeftPanelIndex();

    // note: after update current index,
    //       the meaning has changed:
    //
    //       LEFT   CURRENT   RIGHT         (Before update index)
    //      <--------Swipe left to go NEXT-------
    //
    //       RIGHT  LEFT  CURRENT           (After update index)

    m_currentIndex = newMediaIndex;
    m_currentPanel = newCurrentPanel;

#if 1
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_START_TIMER0);
        // use timer 0 to start animation before handle panel change.
        // handle panel change may cause blocking (when cancel JPEG decoding)
        VfxTimer *timer = NULL;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->setStartDelay(0);
        timer->m_signalTick.connect(this, &VappImageViewerComponent::onTimer0);
        timer->start();
    }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // movePanel is visible panel that should move with current panel
    PanelPosition movePanel = isGoNext ? LEFT_PANEL : RIGHT_PANEL;
    // freePanel should be invisible and update with new content
    PanelPosition freePanel = isGoNext ? RIGHT_PANEL : LEFT_PANEL;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_SNAP_PANEL_TO_INITIAL_POSITION);
    // move the current panel and visible panel to destination
    snapPanelToInitialPosition(CURRENT_PANEL, VFX_TRUE);
    snapPanelToInitialPosition(movePanel, VFX_TRUE);
    snapPanelToInitialPosition(freePanel, VFX_FALSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_CLEAR_PANEL);
    // clear free panel content
    clearPanel(getPanel(freePanel));

    if(!shouldReserveAdjacentPreview())
    {
        clearPanel(getPanel(movePanel));
    }

    // try lock panel preview earlier,
    // but don't start enhance (we haven't cancel enhance at this point.)
    checkAllPanel(__LINE__, VFX_FALSE);

    if(m_previewTimer)
    {
        m_previewTimer->stop();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_SHIFT_PANEL_RETURN);
}

void VappImageViewerComponent::onTimer0(VfxTimer *sender)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_TIMER0);
    VFX_OBJ_CLOSE(sender);
    onCurrentPanelChanged();
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
void VappImageViewerComponent::onBeginZoom(VcpSlider *slider, VfxFloat value)
{
    onPartialEnhnaceDecodeCanceled();
    m_isSliderZooming = VFX_TRUE;
}

void VappImageViewerComponent::onEndZoom(VcpSlider *slider, VfxFloat value)
{
    m_isSliderZooming = VFX_FALSE;
}

void VappImageViewerComponent::onZoom(VcpSlider *slider, VfxFloat value)
{
    if(!m_multiTouchZoomGesture)
    {
        notifyZoomSliderEvent(VFX_TRUE);
    }

    VappGalleryViewerPanel *panel = getCurrentPanel();

    panel->setZoom(value);
    return;
}
#endif

void VappImageViewerComponent::onBeginChangeView(VcpSlider *slider, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHANGE_VIEW, 100, VAPP_GALLERY_INTERNAL_UNUSED_PARAM);
    m_isViewSliderDraging = VFX_TRUE;
    teardownGSensor();
}

void VappImageViewerComponent::onChangeView(VcpSlider *slider, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHANGE_VIEW, 200, (VfxS32)(value * 10000.f));

    VFX_UNUSED(slider);
    updateCurrentImageFrame(value);
    notifyViewSliderEvent(VFX_TRUE);
}

void VappImageViewerComponent::onEndChangeView(VcpSlider *slider, VfxFloat value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_CHANGE_VIEW, 300, (VfxS32)(value * 10000.f));

    VFX_UNUSED(slider);
    setupGSensor();
    updateCurrentImageFrame(value);
}

void VappImageViewerComponent::resetToInitViewedFrame(VappGalleryViewerPanel *panel)
{
    if(NULL == panel || (1 >= panel->getFrameCount()))
        return;

    updateImageFrame(panel, 0.5f);
}

void VappImageViewerComponent::updateImageFrame(VappGalleryViewerPanel *panel, const VfxFloat frameIndexHint, VfxBool isRelativeHint)
{
    if(NULL == panel)
        return;

    if(-1 == panel->getMediaIndex())
        return;

    VfxWString filePath = VFX_WSTR_EMPTY;
    if(OK != getMediaPath(panel, filePath))
    {
        return;
    }

    if(filePath.isEmpty() || filePath.isNull())
    {
        return;
    }

    // check if preview buffer exist
    VfxImageBuffer buffer;
    if(!panel->getPreviewCachedBuffer(buffer))
    {
        return;
    }

    // calculate frame index
    VfxS32 maxFrameIndex = panel->getMaxFrameIndex();
    VfxS32 minFrameIndex = panel->getMinFrameIndex();
    VfxS32 frameIndex = (VfxS32)(frameIndexHint * maxFrameIndex);
    frameIndex  = VFX_MAX(minFrameIndex, VFX_MIN(frameIndex, maxFrameIndex));
    if(panel->getFrameIndex() == frameIndex)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_UPDATE_IMAGE_FRAME_ERR, frameIndex, isRelativeHint, -100);
        return;
    }

    if(isRelativeHint)
    {
        frameIndex = ( panel->getFrameIndex() < frameIndex) ? (panel->getFrameIndex() + 1) : (panel->getFrameIndex() -1 );
        frameIndex  = VFX_MAX(minFrameIndex, VFX_MIN(frameIndex, maxFrameIndex));
    }

    // change frame
#ifdef __VENUS_3D_UI_ENGINE__
    panel->teardownOwnerDraw();
    VfxWString path;
    getMediaPath(panel,path);

    VfxImageBuffer imgBuf;
    panel->getPreviewCachedBuffer(imgBuf);

    VfxRect clipWindow;
    calculateClipWindow(imgBuf, path, clipWindow);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_UPDATE_IMAGE_FRAME,
        frameIndex, isRelativeHint,
        clipWindow.origin.x, clipWindow.origin.y, clipWindow.size.width, clipWindow.size.height);

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    gdi_handle dstLayer = _convertImageBufferToLayer(imgBuf, VFX_FALSE);
    _START("");
    gdi_imgdec_draw_resized_file_frames(
        dstLayer,
        clipWindow.origin.x,
        clipWindow.origin.y,
        clipWindow.size.width,
        clipWindow.size.height,
        (U8*)filePath.getBuf(),
        frameIndex);
    _STOP("[Gallery][ViewerCP] gdi_imgdec_draw_resized_file_frames, dur = %d, line = %d");
    gdi_layer_free(dstLayer);
    panel->setFrameIndex(frameIndex);
    panel->setupOwnerDraw();
#else
    panel->setFrameIndex(frameIndex);
#endif
}

void VappImageViewerComponent::updateCurrentImageFrame(const VfxFloat frameIndexHint, VfxBool isRelativeHint)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_UPDATE_CURRENT_IMAGE_FRAME, (VfxS32)(frameIndexHint * 10000.f), isRelativeHint);
    m_isViewSliderDraging = VFX_FALSE;
    updateImageFrame(getCurrentPanel(), frameIndexHint, isRelativeHint);
}

void VappImageViewerComponent::calculateClipWindow(VfxImageBuffer buffer, VfxWString filePath, VfxRect &clipWindow)
{
    if(filePath.isEmpty() || filePath.isNull() || NULL == buffer.ptr)
    {
        return;
    }

    VfxSize originalDim;
GALLERY_MEASURE_TIME_START("Ggd");
    const GDI_RESULT dimRes = gdi_image_get_dimension_file((CHAR*)filePath.getBuf(), &originalDim.width, &originalDim.height);
GALLERY_MEASURE_TIME_STOP("Ggd");
    if(GDI_SUCCEED != dimRes)
    {
        return;
    }

    VfxS32 offsetX = 0;
    VfxS32 offsetY = 0;
    VfxS32 targetW = 1;
    VfxS32 targetH = 1;
GALLERY_MEASURE_TIME_START("Ggb");
    gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    buffer.width,           // buffer size (dst)
                    buffer.height,
                    originalDim.width,      // original image size (src)
                    originalDim.height,
                    &offsetX,               // draw offset
                    &offsetY,
                    &targetW,
                    &targetH
                    );
GALLERY_MEASURE_TIME_STOP("Ggb");
    clipWindow = VfxRect(offsetX, offsetY, targetW, targetH);
}

VfxBool VappImageViewerComponent::onPenInput(VfxPenEvent &event)
{
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    onPartialEnhnaceDecodeCanceled();
#endif

    if(m_isMultiTouchMode)
    {
        if(2 == event.touchCount)
        {
            return handleMultiTouchPenInput(event);
        }
        else if(1 == event.touchCount)
        {
            // convert to the pen input in single touch mode (all attributes except predictPos, relObjList )
            VfxPenEvent evt;
            evt.type   = event.touchEvents[0].type;
            evt.timeStamp     = event.touchEvents[0].timeStamp;
            evt.prevTimeStamp = event.touchEvents[0].prevTimeStamp;
            evt.downTimeStamp = event.touchEvents[0].downTimeStamp;
            evt.pos     = event.touchEvents[0].pos;
            evt.prevPos = event.touchEvents[0].prevPos;
            evt.downPos = event.touchEvents[0].downPos;
            return handleSingleTouchPenInput(evt);
        }
    }
    else
    {
        // process the single touch event
        return handleSingleTouchPenInput(event);
    }
    return VFX_TRUE;
}

VfxBool VappImageViewerComponent::onKeyInput(VfxKeyEvent &event)
{
    // note video player page always in horizontal screen and
    // keypad will remapping when rotate screen
    VfxScrRotateTypeEnum screenRotation = findScreen()->getRotateType();
    VfxKeyCodeEnum navigationUp    = VFX_KEY_CODE_ARROW_UP;
    VfxKeyCodeEnum navigationDown  = VFX_KEY_CODE_ARROW_DOWN;
    VfxKeyCodeEnum navigationLeft  = VFX_KEY_CODE_ARROW_LEFT;
    VfxKeyCodeEnum navigationRight = VFX_KEY_CODE_ARROW_RIGHT;
	if(VFX_SCR_ROTATE_TYPE_90 == screenRotation)
    {
        navigationUp    = VFX_KEY_CODE_ARROW_RIGHT;
        navigationDown  = VFX_KEY_CODE_ARROW_LEFT;
        navigationLeft  = VFX_KEY_CODE_ARROW_DOWN;
        navigationRight = VFX_KEY_CODE_ARROW_UP;
    }
    else if(VFX_SCR_ROTATE_TYPE_270 == screenRotation)
    {
        navigationUp    = VFX_KEY_CODE_ARROW_LEFT;
        navigationDown  = VFX_KEY_CODE_ARROW_RIGHT;
        navigationLeft  = VFX_KEY_CODE_ARROW_UP;
        navigationRight = VFX_KEY_CODE_ARROW_DOWN;
    }
	/*
		if(VFX_SCR_ROTATE_TYPE_90 == screenRotation)
	    {
	        VfxKeyCodeEnum navigationUp    = VFX_KEY_CODE_ARROW_RIGHT;
	        VfxKeyCodeEnum navigationDown  = VFX_KEY_CODE_ARROW_LEFT;
	        VfxKeyCodeEnum navigationLeft  = VFX_KEY_CODE_ARROW_DOWN;
	        VfxKeyCodeEnum navigationRight = VFX_KEY_CODE_ARROW_UP;
	    }
	    else if(VFX_SCR_ROTATE_TYPE_270 == screenRotation)
	    {
	        VfxKeyCodeEnum navigationUp    = VFX_KEY_CODE_ARROW_LEFT;
	        VfxKeyCodeEnum navigationDown  = VFX_KEY_CODE_ARROW_RIGHT;
	        VfxKeyCodeEnum navigationLeft  = VFX_KEY_CODE_ARROW_UP;
	        VfxKeyCodeEnum navigationRight = VFX_KEY_CODE_ARROW_DOWN;
	    }
	*/

    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    if(NULL == curPanel)
    {
        return VfxControl::onKeyInput(event);
    }


    // stop slideshow
    if(navigationUp == event.keyCode ||
       navigationDown == event.keyCode ||
       navigationLeft == event.keyCode ||
       navigationRight == event.keyCode)
    {
        curPanel->setOwnerDrawHint(DH_NONE);
        curPanel->setOwnerDrawBufferHint(VFX_FALSE);

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
        if(isPlayingSlideshow())
        {
            stopSlideshow();
        }
#endif

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        onPartialEnhnaceDecodeCanceled();
#endif
    }

    if(navigationUp == event.keyCode || (navigationDown == event.keyCode))
    {
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        if(!canZoomPanel(curPanel))
        {
            return VFX_TRUE;
        }

        curPanel->setOwnerDrawHint(DH_RECOMMAND_LT);
        curPanel->setOwnerDrawBufferHint(VFX_TRUE);

        // unit offset while press navigation key to seek
        VfxFloat zoomMax = ZOOM_MAX, zoomMin = ZOOM_MIN;
        curPanel->getMaxZoom(zoomMax);
        curPanel->getMinZoom(zoomMin);
        m_zoomOffset = (zoomMax - zoomMin) / 50.f;
        if(navigationDown == event.keyCode){ m_zoomOffset = - m_zoomOffset;}

        // handle seek behavior
        switch(event.type)
        {
            case VFX_KEY_EVENT_TYPE_DOWN:
            {
                onBeginZoom(NULL, NULL);
                createKeypadLongPressTimer();
                m_keypadLongPressTimer->start();
                break;
            }
            case VFX_KEY_EVENT_TYPE_UP:
            {
                if(m_keypadLongPressTimer){m_keypadLongPressTimer->stop(); }
                onEndZoom(NULL, NULL);
                break;
            }
            default:
                break;
        }
#endif

        return VFX_TRUE;
    }
    else if(navigationLeft == event.keyCode || (navigationRight == event.keyCode))
    {
		//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        if(curPanel->isZoomed())
        {
            // do nothing
            return VFX_TRUE;
        }
#endif
    	// allow popping warning message again
    	m_warningPoppedDuringGesture = VFX_FALSE;

        VappGalleryGesture endGesture = VG_GO_NEXT;
        if(navigationLeft == event.keyCode)
        {
            endGesture = VG_GO_PREV;
        }

        if(VFX_KEY_EVENT_TYPE_DOWN == event.type || VFX_KEY_EVENT_TYPE_REPEAT == event.type)
        {
            onGesture(NULL, endGesture);
        }
        return VFX_TRUE;
    }

    return VfxControl::onKeyInput(event);
}

void VappImageViewerComponent::createGSensor()
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__    
    // reject async case
    if(isAsyncMediaListScenario())
        return;

    const mmi_id appId = findRootAppId(this);    
    VFX_OBJ_CREATE_EX(m_gSensor, VappMavMotionTranslator, this, (VFX_TRUE, appId));
    m_gSensor->m_sigSensorEvent.connect(this, &VappImageViewerComponent::onGSensorEvent);
#endif
}

void VappImageViewerComponent::destroyGSensor()
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    // reject async case
    if(isAsyncMediaListScenario())
        return;

    if(m_gSensor)
    {
        m_gSensor->m_sigSensorEvent.disconnect(this, &VappImageViewerComponent::onGSensorEvent);
        VFX_OBJ_CLOSE(m_gSensor);
    }
#endif
}

void VappImageViewerComponent::onGSensorEvent(VfxFloat offset)
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    VfxS32 offsetFrame = (VfxS32)VFX_MAX(-1.f, VFX_MIN(1.f, offset * 10.f));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][GSensor] onGSensorEvent[%d]", (VfxS32)(offsetFrame * 10000));
    VfxS32 oldValue = (-1 == getCurrentPanel()->getFrameIndex())? 0 : (getCurrentPanel()->getFrameIndex());
    VfxS32 newValue = oldValue + offsetFrame;

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][ViewerCP] onGSensorEvent_1, oldValue[%d], newValue[%d]", oldValue, newValue);
    VfxS32 maxFrameIndex = getCurrentPanel()->getMaxFrameIndex();
    VfxS32 minFrameIndex = getCurrentPanel()->getMinFrameIndex();
    newValue  = VFX_MAX(minFrameIndex, VFX_MIN(newValue, maxFrameIndex));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][ViewerCP] onGSensorEvent_2,newValue[%d]", newValue);

    VfxFloat value = ((VfxFloat)newValue / (VfxFloat)maxFrameIndex);

    // update view slider
    #ifdef __VAPP_GALLERY_MAV_VIEW_CONTROL__
    m_viewSlider->setCurrentValue(value);
    #endif

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][ViewerCP] onGSensorEvent_3, maxframe = %d, value[%d]", maxFrameIndex, (VfxS32)(value * 10000.f));
    updateCurrentImageFrame(value, VFX_TRUE);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][ViewerCP] onGSensorEvent_4");
#endif
}

void VappImageViewerComponent::onGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_GESTURE_D, gesture);

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    if(isPlayingSlideshow())
    {
        if(m_slideshowContainer && m_slideshowContainer->handleGesture(sender, gesture))
        {
            return;
        }
        else
        {
            // [MAUI_03112275] stop slideshow if slideshow dose not handle it
            stopSlideshow();
        }
        return;
    }
#endif

    if(m_isViewSliderDraging)
    {
        return;
    }

    // if we're using media list and it is not ready, better do nothing.
    if(m_mediaList && !m_mediaList->isPrepared())
    {
        return;
    }

    VfxBool treatAsDragEnd = VFX_FALSE;
    // normal mode, determine behavior by gesture
    switch(gesture)
    {
    case VG_TAP:
        break;
    case VG_DOUBLE_TAP:

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        GALLERY_MEASURE_TIME_LABEL("gdt");
        if(m_zoomSlider && !m_zoomSlider->getHidden())
        {
            VappGalleryViewerPanel *currentPanel = getCurrentPanel();
            if(NULL == currentPanel)
            {
                break;
            }

            VfxFloat newZoom = 1.0f;
            if(currentPanel->isZoomed())
            {
                // restore to original
                currentPanel->getMinZoom(newZoom);
            }
            else
            {
                // zoom-in according to original image size
                currentPanel->getDoubleTapZoom(newZoom);
            }
            currentPanel->setZoom(newZoom);
            m_zoomSlider->setCurrentValue(newZoom);
        }
#endif

        break;
    case VG_GO_NEXT:
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        // don't swipe when zoomed
        if(getCurrentPanel()->isZoomed())
        {
            treatAsDragEnd = VFX_TRUE;
            break;
        }
#endif
        if(canGoNext())
        {
            shiftPanel(VFX_TRUE);
        }
        else
        {
            showBallonIfMultiFile(STR_ID_VAPP_GALLERY_IMG_LAST_PHOTO);
            snapPanelToInitialPosition(CURRENT_PANEL, VFX_TRUE);
            snapPanelToInitialPosition(LEFT_PANEL, VFX_FALSE);
            snapPanelToInitialPosition(RIGHT_PANEL, VFX_TRUE);
        }
        break;
    case VG_GO_PREV:
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        // don't swipe when zoomed
        if(getCurrentPanel()->isZoomed())
        {
            treatAsDragEnd = VFX_TRUE;
            break;
        }
#endif

        if(canGoPrevious())
        {
            shiftPanel(VFX_FALSE);
        }
        else
        {
            showBallonIfMultiFile(STR_ID_VAPP_GALLERY_IMG_FIRST_PHOTO);
            snapPanelToInitialPosition(CURRENT_PANEL, VFX_TRUE);
            snapPanelToInitialPosition(LEFT_PANEL, VFX_TRUE);
            snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);
        }
        break;
    case VG_DRAG:
        {
            // unregistor G sensor to avoid lag drag effect caused by unused frame decode
            // which is trigered by G sensor
            enableGSensorSupport(VFX_FALSE);
            // drag logic
            const VfxPenEvent &event = sender->getLastPenEvent();
            VfxS32 xOffset = (event.pos.x - event.prevPos.x);
            VfxS32 yOffset = (event.pos.y - event.prevPos.y);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
            VappGalleryViewerPanel *panel = getCurrentPanel();
            VfxFloat zoomMin, zoomMax;
            panel->getZoomRange( zoomMin, zoomMax);
            VfxFloat zoomValue = 1.f;
            panel->getZoom(zoomValue);

            if(getCurrentPanel()->hasEnhancedBuffer() && zoomMin != zoomValue)
            {
                const VfxS32 t = event.timeStamp - event.prevTimeStamp;
                const VfxFloat vThreshold = 0.00075f;

                VfxFloat d = VAPP_GALLERY_DISTANCE(event.pos,event.prevPos);
                VfxFloat v = d * GESTURE_FACTOR / t;
                VfxFloat factor = (v > vThreshold)? 1.1f : 1.f;
                xOffset = (VfxS32)((event.pos.x - event.prevPos.x)* factor);
                yOffset = (VfxS32)((event.pos.y - event.prevPos.y)* factor);
            }
#endif

            m_inertiaPan.processPenEvent(event);

            onPan(xOffset, yOffset, treatAsDragEnd);
        }
        break;
    case VG_DRAG_END:
        {
            treatAsDragEnd = VFX_TRUE;

            const VfxPenEvent &event = sender->getLastPenEvent();
            m_inertiaPan.processPenEvent(event);
        }
        break;
    default:
        break;
    }

    VappGalleryGesture notifyGesture = gesture;
    if(treatAsDragEnd)
    {
        onDragEnd(VFX_TRUE);
        notifyGesture = VG_DRAG_END;
    }
    notifyGestureEvent(notifyGesture, m_currentIndex);

    return;
}

void VappImageViewerComponent::onPan(VfxS32 xOffset, VfxS32 yOffset, VfxBool treatAsDragEnd)
{
    VappGalleryViewerPanel *currentPanel = getCurrentPanel();
    const VfxPoint panelPos = currentPanel->getPos();
    const VfxS32 panelInitPosX = getPanelInitialPos(CURRENT_PANEL);
    const VfxS32 panelPosDiff = panelPos.x - panelInitPosX;
    VfxS32 xOffsetRemain = xOffset;

    // check if offset moves panel back
    if(panelPosDiff * xOffset < 0)
    {
        if(vfxAbs(panelPosDiff) >= vfxAbs(xOffset))
        {
            offsetVisiblePanels(xOffset, VFX_TRUE);
            return;
            //break;
        }
        else
        {
            xOffsetRemain = xOffset + panelPosDiff;
            offsetVisiblePanels(-panelPosDiff, VFX_TRUE);
        }
    }

    // then we move the view rect inside the panel
    VfxS32 xOffsetRemainAfterViewOffset = xOffsetRemain;
    currentPanel->offsetView(
                        xOffsetRemain,
                        yOffset,
                        VappGalleryViewerPanel::MOVE,
                        xOffsetRemainAfterViewOffset
                        );

    // and finally move the panel again if still offsets
    if(xOffsetRemainAfterViewOffset != 0 && !treatAsDragEnd)
    {
        offsetVisiblePanels(xOffsetRemainAfterViewOffset, VFX_TRUE);
    }

}

void VappImageViewerComponent::onDragEnd(const VfxBool needInertia)
{
    VappGalleryViewerPanel *currentPanel = getCurrentPanel();

    if(needInertia)
    {
        // then we move the view rect inside the panel with inertia
        VfxS32 panX = 0;
        VfxS32 panY = 0;
        if(m_inertiaPan.getInertiaPan(panX, panY) && currentPanel)
        {
            VfxS32 dontCare = 0;
            currentPanel->offsetView(
                                panX,
                                panY,
                                VappGalleryViewerPanel::INERTIA,
                                dontCare
            );
        }
    }

    const VfxPoint pos = currentPanel->getPos();
    // if the current panel only move less than 2x padding,
    // snapback. Otherwise reveal the new panel according to direction
    const VfxBool isSnapBack = vfxAbs(pos.x) < (2 * PANEL_PADDING);
    // determine which non-current panel is being displayed.
    // the other panel does not need animation.
    const VfxBool isGoNext = pos.x < 0;

    if(isSnapBack)
    {
        snapPanelToInitialPosition(CURRENT_PANEL, VFX_TRUE);
        snapPanelToInitialPosition(LEFT_PANEL, !isGoNext);
        snapPanelToInitialPosition(RIGHT_PANEL, isGoNext);
    }
    else
    {
        shiftPanel(isGoNext);
    }
}

void VappImageViewerComponent::onCurrentPanelChanged()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_CURRENT_PANEL_CHANGED_L_D, __LINE__);
    checkUpdate();
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    updateZoomSliderByPanel(curPanel);
#endif

    updateViewControlByPanel(curPanel);
    update3DRedBlueIcon(getCurrentPanel());

    m_hasShownLastPhotoHint = VFX_FALSE; 
    m_hasShownFirstPhotoHint = VFX_FALSE; 

    // since we've changed current image,
    // we should stop consume.
    if(m_drmConsumer)
    {
        m_drmConsumer->stopConsume();
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_CURRENT_PANEL_CHANGED_L_D, __LINE__);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    stopEnhance();
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_CURRENT_PANEL_CHANGED_L_D, __LINE__);
    // when switch new media, hide the OSD,
    // since their state may change,
    // this is to reduce visual impact.
    // if the new current panel has a ready media,
    // we're "start to display it"
    if(isPanelReady(curPanel, curPanel->getMediaIndex()))
    {
        onStartDisplayMedia(curPanel->getMediaIndex());
    }

 //use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
	if(curPanel)
	{
	    curPanel->m_signalStartDecodeL1EnhanceBuf.connect(this, &VappImageViewerComponent::onPartialEnhnaceDecodeStart);
	}
#endif
#endif

    // if the panel have video button, we need to make its parent hittable.
    // if not, make its parent unhittable, so that zoom slider fuzzy touch can work.
    m_viewerPanelContainer->setIsUnhittable(!curPanel->hasPlayButton());
    // notify APP current panel had changed
    notifyCurrentPanelChanged(curPanel->getMediaIndex());
}

void VappImageViewerComponent::onStartDisplayMedia(MediaIndex mediaIdx)
{
    GALLERY_MEASURE_TIME_START("Gsm");

    VappGalleryViewerPanel *curPanel = getCurrentPanel();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    updateZoomSliderByPanel(curPanel);
#endif

    updateViewControlByPanel(curPanel);
    update3DRedBlueIcon(getCurrentPanel());
    notifyStartDisplayMedia();

    if(NULL == m_mediaList)
    {
        GALLERY_MEASURE_TIME_STOP("Gsm");
        return;
    }

    // start consume DRM
    VfxWString path;
    if(m_drmConsumer && OK == m_mediaList->getMediaPath(VcpMenuPos(0, mediaIdx), path))
    {
        m_drmConsumer->setFileAndUserData(path, mediaIdx);
        m_drmConsumer->startConsume();
    }

    if(curPanel->getIsAnimedGif())
    {
        curPanel->setPreviewImageAnimated(VFX_TRUE);
    }

    // if the panel have video button, we need to make its parent hittable.
    // if not, make its parent unhittable, so that zoom slider fuzzy touch can work.
    if(curPanel && m_viewerPanelContainer)
    {
        m_viewerPanelContainer->setIsUnhittable(!curPanel->hasPlayButton());
    }

GALLERY_MEASURE_TIME_STOP("Gsm");

    // IOT test
    sendCurrentViewedFilePathMsg();
}

VfxBool VappImageViewerComponent::isAnimatedImage(MediaIndex mediaIdx)
{
    if(NULL == m_mediaList)
    {
        return VFX_FALSE;
    }

    VfxWString path;
    const VcpMenuPos mediaPos(0, mediaIdx);
    if(OK != m_mediaList->getMediaPath(mediaPos, path))
    {
        return VFX_FALSE;
    }

    return isAnimatedImage(path);
}

VfxBool VappImageViewerComponent::isAnimatedImage(const VfxWString &filePath)
{
    // for Animated GIF support, we use Venus to display its animation.
    MMI_BOOL isAnim = MMI_FALSE;
    GALLERY_MEASURE_TIME_START("Gia");
    GDI_RESULT result = gdi_image_is_animation_file((U8*)filePath.getBuf(), &isAnim);
    GALLERY_MEASURE_TIME_STOP("Gia");
    if(GDI_SUCCEED == result && MMI_TRUE == isAnim)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappImageViewerComponent::isMAVImage(MediaIndex mediaIdx)
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if(NULL == m_mediaList)
    {
        return VFX_FALSE;
    }

    VfxWString path;
    const VcpMenuPos mediaPos(0, mediaIdx);
    if(OK != m_mediaList->getMediaPath(mediaPos, path))
    {
        return VFX_FALSE;
    }
    return isMAVImage(path);
#else
    return VFX_FALSE;
#endif
}

VfxBool VappImageViewerComponent::isMAVImage(const VfxWString &filePath)
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if(filePath.isEmpty() || filePath.isNull())
    {
        return VFX_FALSE;
    }

    GALLERY_MEASURE_TIME_START("Ggf");
    const U16 gdiFileType = gdi_image_get_type_from_file((CHAR*)filePath.getBuf());
    GALLERY_MEASURE_TIME_STOP("Ggf");
    if(GDI_IMAGE_TYPE_MAV_FILE == gdiFileType ||
       GDI_IMAGE_TYPE_MAV == gdiFileType)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][ViewerCP] is mav file");
        return VFX_TRUE;
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif
}

void VappImageViewerComponent::getViewFrameCount(const VfxWString &filePath, VfxS32 &frameCount)
{
    frameCount = 0;
    const VfxBool isMAV = isMAVImage(filePath);
    if(isMAV)
    {
        GALLERY_MEASURE_TIME_START("Ggc");
        gdi_image_get_frame_count_file((U8*)filePath.getBuf(), &frameCount);
        GALLERY_MEASURE_TIME_STOP("Ggc");
    }
}

void VappImageViewerComponent::onFileRightExpired(VappGalleryDRMConsumer *sender, VfxS32 index, drm_proc_enum reason)
{
    if(NULL == sender)
    {
        return;
    }

    if(DRM_RESULT_NO_MEMORY == reason)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY));
    }

    VappGalleryViewerPanel *panel = getPanelByMediaIndex(index);
    if(panel)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_FILE_RIGHT_EXPIRED_IDX_D, index);
        // lock the panel immediately
        clearPanel(panel);
        VfxImageBuffer buf;
        assignLockResultToPanel(index, panel, DRM_LOCKED, buf);
    }

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    // if playing slideshow, we should black-list the image.
    if(isPlayingSlideshow())
    {
        m_slideshowBlackList.set(index);
    }
#endif
}

void VappImageViewerComponent::onDecodeResult(VcpMenuPos menuPos, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_DECODE_RESULT_IDX_D_RES_D, menuPos.pos, result);
    GALLERY_MEASURE_TIME_START("GDR");

    // if the decdoed result is in nearby index,
    // lock the buffer right away.
    const MediaIndex index = menuPos.pos;
    VappGalleryViewerPanel *panel = getPanelByMediaIndex(index);
    if(panel)
    {
        VfxImageBuffer imgBuf;
        if(OK == result)
        {
            VappGalleryDecodeResult result = m_mediaList->lockThumb(menuPos, imgBuf);
            assignLockResultToPanel(index, panel, result, imgBuf);
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
            if(!isPlayingSlideshow())
#endif
            {
                checkAllPanel(__LINE__);
                m_previewTimer->start();
            }
        }
        else
        {
            assignLockResultToPanel(index, panel, result, imgBuf);
        }
    }
    GALLERY_MEASURE_TIME_STOP("GDR");
}

void VappImageViewerComponent::assignLockResultToPanel(MediaIndex mediaIdx, VappGalleryViewerPanel *panel, const VappGalleryDecodeResult result, const VfxImageBuffer imgBuf)
{
    GALLERY_MEASURE_TIME_START("Gar");

    // decode finished, so we update the image buffer / error icon
    // first we clear the panel
    if(panel->hasMediaIndex() && panel->getMediaIndex() != mediaIdx)
    {
        clearPanel(panel);
    }

    // if the new media is still invalid, then we need do nothing
    if(mediaIdx < 0)
    {
        return;
    }

    VFX_ASSERT(mediaIdx >= 0);
    const VcpMenuPos mediaPos(0, mediaIdx);
    VfxBool isVideo = (MEDIA_GROUP_VIDEO == m_mediaList->getMediaGroupType(mediaPos));
    panel->setMediaIndex(mediaIdx, isVideo);
    // since we may update the video button,
    // we need to make sure
    if(panel == getCurrentPanel() && m_viewerPanelContainer)
    {
        m_viewerPanelContainer->setIsUnhittable(!panel->hasPlayButton());
    }

    if(OK != result)
    {
        #if defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_VIDEO_THUMBAIL__)
        const VfxBool showErrorIcon = VFX_TRUE;
        #else
        // if we do not support video thumb, do not show error icon in video case
        const VfxBool showErrorIcon = isVideo ? VFX_FALSE : VFX_TRUE;
        #endif

        switch(result)
        {
        case DECODING:
            panel->setIsLoading();
            panel->setIcon(VIT_DEFAULT);
            break;
        case CANCELLED:
        case UNEXPECTED:
        case FORMAT_UNSUPPORTED:
            if(showErrorIcon)
            {
                panel->setIcon(VIT_ERROR);
            }
            break;
        case DRM_LOCKED:
            panel->setIcon(VIT_DRM);
            break;
        }
        panel->setSize(getSize());
    }
    else
    {
        // then we update the image buffer
        panel->setSize(getSize());

        // if we can really enhance the image,
        // we should set zoom ratio based on enhanced size
        VfxWString path;
        VfxS32 maxZoomDim = 0;
        VfxSize enhancedSize;
        enhancedSize.width = 0;
        enhancedSize.height = 0;
        if(OK == m_mediaList->getMediaPath(mediaPos, path))
        {
 //use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
            maxZoomDim = VappGalleryEnhancedImage::getMaxEnhanceDimensionByPath(path, panel->getImageType());
#endif
        }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        if(0 != maxZoomDim && canEnhanceMedia(mediaIdx))
        {
            if(NULL == m_enhancedImage && m_option.supportZoom)
            {
                VFX_OBJ_CREATE(m_enhancedImage, VappGalleryEnhancedImage, this);
            }

            if(!m_enhancedImage->getEnhancedImageSize(path, enhancedSize, panel->getImageType(), panel->getImageOriginalDimension()))
            {
                enhancedSize.width = 0;
                enhancedSize.height = 0;
                VFX_OBJ_CLOSE(m_enhancedImage);
            }
        }
#else
		// update enhanced size
		gdi_imgdec_get_dimension_file(path.getBuf(), &enhancedSize.width, &enhancedSize.height);
		// update max zoom dim
		VfxU16 srcType = panel->getImageType();
		if(GDI_IMAGE_TYPE_INVALID == srcType)
	    {
	        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_ENHANCE_GET_MAX_ENHANCE_DIM_BY_PATH, srcType);
	        GALLERY_MEASURE_TIME_START("Ggf");
	        srcType = gdi_image_get_type_from_file((CHAR*)path.getBuf());
	        GALLERY_MEASURE_TIME_STOP("Ggf");
	    }
		// GIF special case: do not enhace if the GIF file is animated image.
	    switch(srcType)
	    {
	    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
	    case GDI_IMAGE_TYPE_GIF:
	    case GDI_IMAGE_TYPE_GIF_FILE:
	        if(VappImageViewerComponent::isAnimatedImage(path))
	        {
	            maxZoomDim = 0;
	        }
	    }
	    switch(srcType)
	    {
	    // GDI images are not allowed to resize/zoom/enhance
	    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
	    case GDI_IMAGE_TYPE_GIF:
	    case GDI_IMAGE_TYPE_GIF_FILE:
	    case GDI_IMAGE_TYPE_BMP:
	    case GDI_IMAGE_TYPE_BMP_SEQUENCE:
	    case GDI_IMAGE_TYPE_BMP_FILE:
	    case GDI_IMAGE_TYPE_WBMP_FILE:
	    case GDI_IMAGE_TYPE_WBMP:
	        maxZoomDim = GDI_MAX_RESIZE_WIDTH;
	    default:
	        maxZoomDim = vfxMin(VFX_FRAME_MAX_WIDTH, VFX_FRAME_MAX_HEIGHT);
	    }
	    maxZoomDim = vfxMin(VFX_FRAME_MAX_WIDTH, VFX_FRAME_MAX_HEIGHT);
		VfxS32 offsetX = 0, offsetY = 0;
	    gdi_util_fit_box(
	            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
	            maxZoomDim,
	            maxZoomDim,
	            enhancedSize.width,
	            enhancedSize.height,
	            &offsetX,           // ignore this
	            &offsetY,           // ignore this
	            &enhancedSize.width,
	            &enhancedSize.height);
#endif
	
        // set mav file to make sure setup owner draw for mav file
        VfxRect clipwindow;
        const VfxS32 frameCount = panel->getFrameCount();
        panel->setFrameIndex(frameCount / 2);

        calculateClipWindow(imgBuf, path, clipwindow);
        // set preview cache buffer
        panel->setPreviewCachedBuffer(
                            imgBuf,
                            maxZoomDim,
                            (enhancedSize.width != 0 && enhancedSize.height != 0) ? &enhancedSize : NULL,
                            path,
                            clipwindow);

        // we're about to display the current image.
        if(getCurrentPanel() == panel)
        {
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
            #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
            panel->m_signalStartDecodeL1EnhanceBuf.connect(this, &VappImageViewerComponent::onPartialEnhnaceDecodeStart);
            #endif
#endif

            onStartDisplayMedia(mediaIdx);
        }
    }

    // update general UI logic
    if(getCurrentPanel() == panel)
    {
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        updateZoomSliderByPanel(panel);
#endif
        updateViewControlByPanel(panel);
    	update3DRedBlueIcon(getCurrentPanel());
    }

    GALLERY_MEASURE_TIME_STOP("Gar");
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
VfxBool VappImageViewerComponent::canZoomPanel(VappGalleryViewerPanel *panel)
{
    VfxBool canZoom = VFX_FALSE;
    do
    {
        if(NULL == panel)
            break;

        if(panel->getHidden())
            break;

        if(m_initState.isSingleFile())
        {
            VfxImageSrc src;
            src.setNull();
            if(!panel->getPreviewImage(src) ||
               src.isNull() ||
               src.isEmpty())
            {
                break;
            }

            // reject MAV
            VfxWString path = src.getPath();
            if(isMAVImage(path))
            {
                break;
            }
        }
        else
        {
            // reject invalid environemnt
            if(NULL == m_mediaList ||
               !panel->hasMediaIndex())
                break;

            // reject loading state
            if(!isPanelReady(panel, panel->getMediaIndex()))
                break;

            // reject non-decoded image
            if(!panel->isDisplayImage())
                break;

            // reject video
            if(MEDIA_GROUP_VIDEO == m_mediaList->getMediaGroupType(VcpMenuPos(0, panel->getMediaIndex())))
                break;

            // reject anim GIF
            if(panel->getIsAnimedGif())
                break;

            // reject MAV
            if(isMAVImage(panel->getMediaIndex()))
                break;
        }

        canZoom = VFX_TRUE;
    }while(0);

    return canZoom;
}

void VappImageViewerComponent::updateZoomSliderByPanel(VappGalleryViewerPanel *panel)
{
    if(NULL == m_zoomSlider)
    {
        return;
    }

    GALLERY_MEASURE_TIME_START("Guz");

    const VfxBool canZoom = canZoomPanel(panel);

    VfxFloat zoomMin = 1.0f;
    VfxFloat zoomMax = 1.0f;
    if(panel)
    {
        panel->getZoomRange(zoomMin, zoomMax);
    }

    if(!canZoom || zoomMin >= zoomMax)
    {
        m_zoomSlider->setCurrentValue(m_zoomSlider->getMinValue());
        hideZoomSlider(VFX_TRUE);

        GALLERY_MEASURE_TIME_STOP("Guz");
        return;
    }

    hideZoomSlider(VFX_FALSE);

    m_zoomSlider->setMinValue(zoomMin);
    m_zoomSlider->setMaxValue(zoomMax);
    m_zoomSlider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    VfxFloat currentZoom = zoomMin;
    panel->getZoom(currentZoom);
    m_zoomSlider->setCurrentValue(currentZoom);

    GALLERY_MEASURE_TIME_STOP("Guz");
}
#endif

VappGalleryViewerPanel* VappImageViewerComponent::getPanelByMediaIndex(MediaIndex index)
{
    for(int i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        VappGalleryViewerPanel *p = m_viewPanels[i];
        if(p->hasMediaIndex() && index == p->getMediaIndex())
        {
            return p;
        }
    }
    return NULL;
}

VfxBool VappImageViewerComponent::canGoNext()
{
    if(!m_mediaList)
    {
        return VFX_FALSE;
    }

    return VfxBool((m_currentIndex + 1) < m_mediaList->getMediaCountInGroup(0));
}

VfxBool VappImageViewerComponent::canGoPrevious()
{
    if(!m_mediaList)
    {
        return VFX_FALSE;
    }

    if(m_currentIndex > 0 && m_mediaList->getMediaCountInGroup(0) > 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

MediaIndex VappImageViewerComponent::getNextIndex()const
{
    if(NULL == m_mediaList)
    {
        return 0;
    }

    return vfxMin(m_mediaList->getMediaCountInGroup(0) - 1, m_currentIndex + 1);
}

MediaIndex VappImageViewerComponent::getPrevIndex()const
{
    return vfxMax(0, m_currentIndex - 1);
}

void VappImageViewerComponent::showBallonIfMultiFile(const VfxId ballonTextId)
{
    if(m_warningPoppedDuringGesture)
    {
        return;
    }

    if(m_initState.isSingleFile())
    {
        return;
    }

    if(m_initState.m_disableSwitchBalloon)
    {
        return;
    }

    // no need to show when there is no file at all.
    if(NULL == m_mediaList ||
       m_mediaList->getMediaCountInGroup(0) <= 0)
    {
        return;
    }

    // allow show fist/last photo hint for current panel only once
    if((STR_ID_VAPP_GALLERY_IMG_LAST_PHOTO == ballonTextId && m_hasShownLastPhotoHint) ||
       (STR_ID_VAPP_GALLERY_IMG_FIRST_PHOTO == ballonTextId && m_hasShownFirstPhotoHint))
    {
        return;
    }
    
    if(STR_ID_VAPP_GALLERY_IMG_LAST_PHOTO == ballonTextId)
    {
        m_hasShownLastPhotoHint = VFX_TRUE;  
    }
    else if(STR_ID_VAPP_GALLERY_IMG_FIRST_PHOTO == ballonTextId)
    {
        m_hasShownFirstPhotoHint = VFX_TRUE; 
    }

    m_warningPoppedDuringGesture = VFX_TRUE;
    VfxWString ballonText = VFX_WSTR_RES(ballonTextId);
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, ballonText);
}

/*****************************************************************************
 * Class Implementation of VappImageViewerComponent (Slideshow section)
 *****************************************************************************/
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
VappImageViewerComponent::SlideshowStoppedEvent* VappImageViewerComponent::getSlideshowStoppedEvent()
{
    return &m_signalSideshowStopped;
}
VfxBool VappImageViewerComponent::isPlayingSlideshow() const
{
    return (NULL != m_slideshowContainer);
}

VfxBool VappImageViewerComponent::getSlideshowOrientationLimit(VfxBool &hasOrientationLimit, VfxScrRotateTypeEnum &orientation)
{
    if(!isPlayingSlideshow())
    {
        return VFX_FALSE;
    }

    VFX_ASSERT(m_slideshowContainer);
    m_slideshowContainer->getOrientationLimit(hasOrientationLimit, orientation);
    return VFX_TRUE;
}

VfxBool VappImageViewerComponent::playSlideshow()
{
    if(isPlayingSlideshow())
    {
        return VFX_FALSE;
    }

    // stop preview pre-loading logic
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    stopEnhance();
#endif

    if(m_previewTimer)
    {
        m_previewTimer->stop();
    }

    createSlideshowContainer();

    VFX_ASSERT(NULL != m_slideshowContainer);
    VfxFrame *curFrame = getCurrentPanel();

    // remember starting position
    m_slideshowStartIndex = m_currentIndex;
    m_slideshowCurrentIndex = m_currentIndex;

    if(m_slideshowSetting.getShuffle() && m_shuffleIndex)
    {
        m_shuffleIndex->ensureMediaIndexInPos(m_slideshowCurrentIndex);
    }

    // clear left/right panels, since we may be assign different media.
    // and we must make sure they unlock media cache
    clearPanel(getPanel(LEFT_PANEL));
    clearPanel(getPanel(RIGHT_PANEL));

    playFirstMedia(NULL);

    return VFX_TRUE;
}

void VappImageViewerComponent::setupSlideshowPanel(VappGalleryViewerPanel *panel)
{
    // Use L1 Buffer if possible
    // e.g. a GIF animation is playing
    VfxImageBuffer buf;
    if(panel->isOwnerDraw())
    {
        // try to keep rotate state
        return;
    }
    else if(panel->hasCachedBuffer() && panel->getPreviewCachedBuffer(buf))
    {
        // re-setup L1 Buffer as image content
        panel->setPreviewImage(VfxImageSrc(buf), VFX_FALSE);
    }
    else if(m_mediaList)
    {
        // finally use file if there is no cache (strange)
        VcpMenuPos mediaPos(0, panel->getMediaIndex());
        VfxImageSrc src;
        m_mediaList->getMediaSource(mediaPos, src);
        panel->setPreviewImage(src);
    }
    panel->setPreviewImageAnimated(VFX_FALSE);
}

void VappImageViewerComponent::playFirstMedia(VfxTimer *sender)
{
	if(!isPlayingSlideshow())
    {
        VFX_OBJ_CLOSE(sender);
        return;
    }

    // if current media is already ready,
    // prepare next media to display.
    // if not ready, check again with timer.
    VappGalleryViewerPanel *panel = getCurrentPanel();
    if(isPanelReady(panel, m_currentIndex))
    {
        setupSlideshowPanel(panel);
        m_slideshowContainer->setNextMedia(panel);
        m_slideshowContainer->playMedia();
        prepareNextSlideshowMediaPanel();

        // release the timer
        VFX_OBJ_CLOSE(sender);
    }
    else
    {
        // current image should stay for a while
        // according to user setting
        if(NULL == sender)
        {
            VFX_OBJ_CREATE(sender, VfxTimer, this);
            sender->m_signalTick.connect(this, &VappImageViewerComponent::playFirstMedia);
        }
        sender->setStartDelay(SLIDESHOW_WAIT_IMG_INTERVAL);
        sender->start();
    }
}

void VappImageViewerComponent::stopSlideshow()
{
	closeSlideshowContainer();
    stopAllDecoding();

    // resume MediaCache background decoding
    if(m_mediaList && m_mediaList->isPrepared())
    {
        m_mediaList->enableBackgroundDecode(VFX_TRUE);
    }

    // move all panels to viewing position
    snapPanelToInitialPosition(CURRENT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(LEFT_PANEL, VFX_FALSE);
    snapPanelToInitialPosition(RIGHT_PANEL, VFX_FALSE);

    // prepare new panel after updating current
    // instead of checking every UI state for panel,
    // we clean all panel to re-initialize panel to avoid abnormal UI state such as
    // - [MAUI_03117105] zoomslider opacity is 1.0 but it is hidden in scene tree
    // - [MAUI_03116884] not reassign path resource to panel's image content and set animated hint
    // - [MAUI_03119132] re-init owner draw logic and cache mode of panels
    clearAllPanel();
    checkAllPanel(__LINE__);
    checkUpdate();

    // restart preview pre-loading logic
    m_previewTimer->start();

    ///////hideAllBars(shouldHideAllBars);
    notifySlideshowStopped();
}
#endif


void VappImageViewerComponent::onKeypadLongPressimeout(VfxTimer *timer)
{
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    VFX_UNUSED(timer);
    if(NULL == m_zoomSlider){return;}
    VfxFloat zoomMax = ZOOM_MAX, zoomMin = ZOOM_MIN;
    getCurrentPanel()->getMaxZoom(zoomMax);
    getCurrentPanel()->getMinZoom(zoomMin);

    VfxFloat value = m_zoomSlider->getCurrentValue() + m_zoomOffset;
    value = vfxMin(vfxMax(zoomMin, value), zoomMax);
    m_zoomSlider->setCurrentValue(value);
    onZoom(m_zoomSlider, value);
#endif
}

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
void VappImageViewerComponent::onSlideshowAnimFinish(
            VfxFrame * target,
            VappGallerySlideshowBase::FinishType type,
            VfxBool isFinished)
{
    // this signal is post-emit, so
    // it is possible that slideshow Container is already destroyed.
    if(NULL == m_slideshowContainer)
    {
        return;
    }

    // ending animation finished, really stop slideshow
    if(type == VappGallerySlideshowBase::FT_ENDING)
    {
        stopSlideshow();
        return;
    }

    // start ending animation if reach end
    const MediaIndex newMediaIndex = getNextPlaybackIndex();
    if(INVALID_MEDIA_INDEX == newMediaIndex)
    {
        if(m_slideshowContainer->canPlayMedia())
        {
            m_slideshowContainer->playEnding();
        }
        else if(m_slideshowStillImageTimer)
        {
            // wait until user resumes slideshow playback
            m_slideshowStillImageTimer->setStartDelay(m_slideshowSetting.getDelayTime());
            m_slideshowStillImageTimer->start();
        }
        return;
    }

    // slide show case, we start play animated image immediately
    VappGalleryViewerPanel *curPanel = getCurrentPanel();
    if(curPanel && curPanel->getIsAnimedGif())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_SLIDESHOW_START_ANIMATED_GIF, m_currentIndex);
        // for animated files, directly pass the file path
        {
            if(curPanel->isOwnerDraw())
            {
                VcpMenuPos mediaPos(0, m_currentIndex);
                VfxImageSrc src;
                m_mediaList->getMediaSource(mediaPos, src);
                curPanel->setPreviewImage(src);
            }
            // check if we're about to display the current image.
            onStartDisplayMedia(m_currentIndex);
            // no further enhnace required for animated images
        }
    }

    // start decoding next file
    prepareNextSlideshowMediaPanel();

    if(m_slideshowStillImageTimer)
    {
        m_slideshowStillImageTimer->setStartDelay(m_slideshowSetting.getDelayTime());
        m_slideshowStillImageTimer->start();
    }
}

MediaIndex VappImageViewerComponent::getNextPlaybackIndex()
{
    // normal case, we play all media once
    const VfxS32 mediaCount = m_mediaList->getMediaCountInGroup(0);
    do
    {
        const MediaIndex nextIndex = (m_slideshowCurrentIndex + 1) % mediaCount;

        // we have "looped" if we are the same as starting index
        // after increment
        if(nextIndex == m_slideshowStartIndex)
        {
            if(!m_slideshowSetting.getRepeat())
            {
                // reach end and not repeat
                return INVALID_MEDIA_INDEX;
            }
            else if(m_slideshowBlackList.isAllSet(0, 0, mediaCount))
            {
                // all files are broken, cannot repeat
                return INVALID_MEDIA_INDEX;
            }
        }

        MediaIndex realMediaIndex = nextIndex;
        // shuffle requires an shuffled array.
        if(m_slideshowSetting.getShuffle())
        {
            VFX_ASSERT(m_shuffleIndex);
            realMediaIndex = m_shuffleIndex->getShuffledIndex(nextIndex);
        }

        // if the found media is a video,
        // directly considered as "cannot play"
        if(m_mediaList &&
           MEDIA_GROUP_VIDEO == m_mediaList->getMediaGroupType(VcpMenuPos(0, realMediaIndex)))
        {
            m_slideshowBlackList.set(realMediaIndex);
        }

        // block *.mav file
        if(m_mediaList && isMAVImage(realMediaIndex))
        {
            m_slideshowBlackList.set(realMediaIndex);
        }

        // check if this index can really be played
        if(!m_slideshowBlackList.isSet(realMediaIndex))
        {
            // yes it can (or never tried)
            return realMediaIndex;
        }

        // otherwise we keep trying next one
        // note that we silently update the current slideshow index.
        m_slideshowCurrentIndex = (m_slideshowCurrentIndex + 1) % mediaCount;
    }while(1);
}

VfxBool VappImageViewerComponent::prepareNextSlideshowMediaPanel()
{
    const MediaIndex newMediaIndex = getNextPlaybackIndex();
    if(INVALID_MEDIA_INDEX == newMediaIndex ||
       m_currentIndex == newMediaIndex)
    {
        // we cannot find next media at all
        clearPanel(getPanel(RIGHT_PANEL));
        return VFX_FALSE;
    }
    return updatePanelMedia(getPanel(RIGHT_PANEL), newMediaIndex);
}

void VappImageViewerComponent::onSlideshowStillImageTimer(VfxTimer *source)
{
    VFX_UNUSED(source);

    if(!isPlayingSlideshow())
    {
        return;
    }

    // still image time up,
    // check if we can start transition to next image.
    // if not (e.g. next image is still decoding),
    // then we keep waiting with a shorter retry interval
    VappGalleryViewerPanel *nextPanel = getPanel(RIGHT_PANEL);
    VappGalleryViewerPanel *currentPanel = getPanel(CURRENT_PANEL);

    // since we want to play transition,
    // we need to wait for both images are ready
    if(!isPanelReady(currentPanel, currentPanel->getMediaIndex()))
    {
        m_slideshowStillImageTimer->setStartDelay(SLIDESHOW_WAIT_IMG_INTERVAL);
        m_slideshowStillImageTimer->start();
    }
    else if(prepareNextSlideshowMediaPanel() && nextPanel->isLoading())
    {
        // next file is not ready
        m_slideshowStillImageTimer->setStartDelay(SLIDESHOW_WAIT_IMG_INTERVAL);
        m_slideshowStillImageTimer->start();
    }
    else if(!m_slideshowContainer->canPlayMedia())
    {
        // slideshow container not ready
        m_slideshowStillImageTimer->setStartDelay(SLIDESHOW_WAIT_IMG_INTERVAL);
        m_slideshowStillImageTimer->start();
    }
    else if(!nextPanel->hasMediaIndex())
    {
        // there is no next file
        m_slideshowContainer->playEnding();
    }
    else
    {
        VFX_ASSERT(nextPanel->hasMediaIndex());

        // check if next panel is a successfully decoded to display
        if(!nextPanel->isDisplayImage())
        {
            // some error happend, this image is incorrect,
            // set into blacklist
            m_slideshowBlackList.set(nextPanel->getMediaIndex());

            // keep seaching next one,
            // possibly end slideshow if no more media available
            prepareNextSlideshowMediaPanel();
            if(isPlayingSlideshow() && m_slideshowStillImageTimer)
            {
                m_slideshowStillImageTimer->setStartDelay(SLIDESHOW_WAIT_IMG_INTERVAL);
                m_slideshowStillImageTimer->start();
            }
            return;
        }

        // next panel snap to current panel position
        nextPanel->setPos(getPanelInitialPos(CURRENT_PANEL), 0);
        nextPanel->bringToFront();

        // if "original" current panel is animated gif, stop to play
        setupSlideshowPanel(getCurrentPanel());
        // set preview image content
        setupSlideshowPanel(nextPanel);
        // ready to play, transition to next image
        // and start prepare next media
        m_slideshowContainer->setNextMedia(nextPanel);
        m_slideshowContainer->playMedia();

        // update "current"
        // Note:
        // we use "m_slideshowCurrentIndex" when playing slideshow
        m_currentIndex = nextPanel->getMediaIndex();
        m_currentPanel = getRightPanelIndex();
        onCurrentPanelChanged();
        const VfxS32 mediaCount = m_mediaList->getMediaCountInGroup(0);
        m_slideshowCurrentIndex = m_slideshowCurrentIndex + 1;
        if(m_slideshowCurrentIndex >= mediaCount)
        {
            m_slideshowCurrentIndex = 0;
        }
    }
}

VappGallerySlideshowBase *VappImageViewerComponent::createSlideshowInstance(VfxBool isTransition, VcpPageEffectType transitionType)
{
    VappGallerySlideshowBase *ret = NULL;
    if(isTransition)
    {
        VappGalleryTransitionSlideshow *transitionSlideshow = NULL;
        VFX_OBJ_CREATE(transitionSlideshow, VappGalleryTransitionSlideshow, this);
        transitionSlideshow->configEffectType(transitionType);
        // transition slideshow can use any orientation
        transitionSlideshow->setPos(0, 0);
        transitionSlideshow->setSize(getSize());
        ret = transitionSlideshow;
    }
    else
    {
#ifdef __COSMOS_3D_V10__
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        VappGallerySceneSlideshow *sceneSlideshow = NULL;
        VFX_OBJ_CREATE(sceneSlideshow, VappGallerySceneSlideshow, this);
        ret = sceneSlideshow;
        // scene slideshow support only full screen landscape
        sceneSlideshow->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
        sceneSlideshow->setPos(0, 0);
        VfxAutoAnimate::commit();
#endif
    }

    VFX_ASSERT(ret);
    return ret;
}

void VappImageViewerComponent::createSlideshowContainer()
{
    // prepare timer (for duration of image stay still)
    if(NULL == m_slideshowStillImageTimer)
    {
        VFX_OBJ_CREATE(m_slideshowStillImageTimer, VfxTimer, this);
    }
    m_slideshowStillImageTimer->setStartDelay(m_slideshowSetting.getDelayTime());
    m_slideshowStillImageTimer->m_signalTick.connect(this, &VappImageViewerComponent::onSlideshowStillImageTimer);

    // clear all bits
    m_slideshowBlackList.clearAll();

    // prepare shuffle index, if necessary
    if(m_slideshowSetting.getShuffle())
    {
        VFX_ASSERT(NULL == m_shuffleIndex);
        VFX_ASSERT(m_mediaList);
        const VfxS32 mediaCount = m_mediaList->getMediaCountInGroup(0);
        VFX_OBJ_CREATE_EX(m_shuffleIndex, VappGalleryShuffleIndex, this, (mediaCount));
    }

    VFX_ASSERT(NULL == m_slideshowContainer);

    // create slideshow effect object from slideshow setting
    VfxBool isTransitionSlideshow = VFX_TRUE;
    VcpPageEffectType transitionType = VCP_PAGE_EFFECT_NONE;
    m_slideshowSetting.getEffect(isTransitionSlideshow, transitionType);
    m_slideshowContainer = createSlideshowInstance(isTransitionSlideshow, transitionType);

    // if a slideshow has limitation on orientation, adjust it now.
    VfxBool hasLimitation = VFX_FALSE;
    VfxScrRotateTypeEnum slideshowOrientation = VFX_SCR_ROTATE_TYPE_NORMAL;
    if(getSlideshowOrientationLimit(hasLimitation, slideshowOrientation) && hasLimitation)
    {

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->setScreenRotateType(slideshowOrientation);
        // set to black to prevent white background to appear
        // during rotation
        findScreen()->setBgColor(VFX_COLOR_BLACK);
    }

    // hook slideshow end callback
    m_slideshowContainer->m_signalFinished.connect(this, &VappImageViewerComponent::onSlideshowAnimFinish);

    // disable all auto animation of viewer panels
    for(VfxS32 i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        m_viewPanels[i]->setAutoAnimate(VFX_FALSE);
        m_viewPanels[i]->setHidden(VFX_TRUE);
    }
    m_viewerPanelContainer->setHidden(VFX_TRUE);

    // turn off backlight timer
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
}

void VappImageViewerComponent::closeSlideshowContainer()
{
    // move all view panels to normal container,
    // so they don't destroyed with slideshow container
    for(VfxS32 i = 0; i < TOTAL_PANEL_NUM; ++i)
    {
        m_viewerPanelContainer->addChildFrame(m_viewPanels[i]);
        m_viewPanels[i]->setHidden(VFX_FALSE);
        m_viewPanels[i]->setAutoAnimate(VFX_TRUE);
    }
    m_viewerPanelContainer->setHidden(VFX_FALSE);
    getCurrentPanel()->bringToFront();
    m_slideshowBlackList.clearAll();
    VFX_OBJ_CLOSE(m_slideshowContainer);

    if(m_slideshowStillImageTimer)
    {
        m_slideshowStillImageTimer->stop();
        VFX_OBJ_CLOSE(m_slideshowStillImageTimer);
    }
    VFX_OBJ_CLOSE(m_shuffleIndex);

    // resume "permanament" to setting
    srv_backlight_turn_off();
}
#endif

void VappImageViewerComponent::verifyInputFile()
{
    if(!m_initState.isSingleFile() ||
       VFX_IMAGE_SRC_TYPE_PATH != m_initState.m_singleFileSrc.getType())
    {
        // already verified, or not a single file case,
        // or the input source needs no verification
        m_initState.m_singleFileCheckResult = OK;

        // if no need to verify file, display image directly
        if(m_initState.isSingleFile())
        {
            displaySingleFileImage();
        }
        return;
    }

    if(!VappGalleryFileUtil::isFileExist(m_initState.m_singleFileSrc.getPath().getBuf()))
    {
        // file does not exist anymore
        m_initState.m_singleFileCheckResult = FORMAT_UNSUPPORTED;
        stopVerifyInputFile();
        displaySingleFileImage();
        return;
    }

    if(DECODING != m_initState.m_singleFileCheckResult)
    {
        displaySingleFileImage();
        return;
    }

    stopVerifyInputFile();

    // start verify
    VFX_OBJ_CREATE(m_imageCheckerOutput, VappGalleryCachedImage, this);
    m_imageCheckerOutput->lockBuffer(getRootApp()->getGroupId(), VERIFY_DIM, VERIFY_DIM);
    VfxImageSrc src;
    if(!m_imageCheckerOutput->fillImageSrc(src))
    {
        m_imageCheckerOutput->unlockBuffer();
        VFX_OBJ_CLOSE(m_imageCheckerOutput);
        onVerifyResult(NULL, UNEXPECTED);
        return;
    }

    // start verify the image by decoding it to the m_imageCheckerOutput buffer
    VFX_OBJ_CREATE(m_imageChecker, VappGalleryImageThumbnail, this);
    VfxImageBuffer imgBuf = src.getImageBuffer();
    m_initState.m_singleFileCheckResult = DECODING;
    m_imageChecker->getReadySignal()->connect(this, &VappImageViewerComponent::onVerifyResult);
    m_imageChecker->decode(m_initState.m_singleFileSrc.getPath(), imgBuf);
}

void VappImageViewerComponent::stopVerifyInputFile()
{
    VFX_OBJ_CLOSE(m_imageChecker);
    if(m_imageCheckerOutput)
    {
        m_imageCheckerOutput->unlockBuffer();
    }
    VFX_OBJ_CLOSE(m_imageCheckerOutput);
}

void VappImageViewerComponent::onVerifyResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result)
{
    m_initState.m_singleFileCheckResult = result;
    stopVerifyInputFile();
    displaySingleFileImage();
}

void VappImageViewerComponent::displaySingleFileImage()
{
    VfxImageSrc &src = m_initState.m_singleFileSrc;
    VappGalleryViewerPanel *panel = getCurrentPanel();

    panel->setPos(0, 0);
    // block buffer source here,
    // since it will be confused with image buffers from MediaCache.
    ASSERT(VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER != src.getType());
    switch(m_initState.m_singleFileCheckResult)
    {
    case DRM_LOCKED:
        panel->setIcon(VIT_DRM);
        break;
    case UNEXPECTED:
    case AUDIO_ONLY:
    case PATH_TOO_DEEP:
    case FORMAT_UNSUPPORTED:
        panel->setIcon(VIT_ERROR);
        break;
    case OK:
    case CANCELLED:
    case DECODING:
    default:
        panel->setPreviewImage(src, VFX_TRUE);
        if(VFX_IMAGE_SRC_TYPE_PATH == src.getType() &&
        isAnimatedImage(src.getPath()))
        {
            panel->setPreviewImageAnimated(VFX_TRUE);
        }
        break;
    }

    panel->bringToFront();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    updateZoomSliderByPanel(panel);
#endif

    updateViewControlByPanel(panel);
    update3DRedBlueIcon(getCurrentPanel());
    checkUpdate();
}

void VappImageViewerComponent::setMultiTouchMode(VfxBool isMultiTouchMode)
{
#if (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && (__MTK_TARGET__)
    VfxPen *pensrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    if(isMultiTouchMode)
        pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_MULTI_TOUCH);
    else
        pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_SINGLE_TOUCH);
    m_isMultiTouchMode = isMultiTouchMode;
#endif
}

VfxBool VappImageViewerComponent::handleSingleTouchPenInput(VfxPenEvent &event)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_HANDLE_SINGLE_TOUCH_PEN_INPUT, event.type, event.pos.x, event.pos.y);

    VappGalleryViewerPanel *currentPanel = getCurrentPanel();
    if(NULL == currentPanel)
    {
        return VfxControl::onPenInput(event);
    }

    if(VFX_PEN_EVENT_TYPE_UP == event.type)
    {
        // allow popping warning message again
        m_warningPoppedDuringGesture = VFX_FALSE;
        currentPanel->setOwnerDrawHint(DH_NONE);
        currentPanel->setOwnerDrawBufferHint(VFX_FALSE);
    }

    if(VFX_PEN_EVENT_TYPE_DOWN == event.type)
    {
        currentPanel->setOwnerDrawHint(DH_RECOMMAND_LT);
        currentPanel->setOwnerDrawBufferHint(VFX_TRUE);
        // stop panning immediately
        VfxS32 dontCare = 0;
        currentPanel->offsetView(
                            0,
                            0,
                            VappGalleryViewerPanel::STOP,
                            dontCare
                            );
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    if(m_isSliderZooming)
    {
        // mouse event should be handled by slider during zooming
        return VfxControl::onPenInput(event);
    }
#endif

    m_gestureTranslator->processPenEvent(this, event);
    return VFX_TRUE;
}

VfxBool VappImageViewerComponent::handleMultiTouchPenInput(VfxPenEvent &event)
{
    if(2 != event.touchCount)
    {
        return VFX_TRUE;
    }

    VappGalleryViewerPanel *currentPanel = getCurrentPanel();
    if(NULL == currentPanel)
    {
        return VFX_TRUE;
    }

    if( VFX_PEN_EVENT_TYPE_DOWN == event.touchEvents[0].type ||
        VFX_PEN_EVENT_TYPE_DOWN == event.touchEvents[1].type )

    {
        currentPanel->setOwnerDrawHint(DH_RECOMMAND_LT);
        currentPanel->setOwnerDrawBufferHint(VFX_TRUE);
		
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
        if(isPlayingSlideshow())
        {
            stopSlideshow(/*VFX_TRUE*/);
        }
#endif
        return VFX_TRUE;
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    if(!hasZoomSlider() || NULL == m_zoomSlider)
    {
        return VFX_TRUE;
    }
    // chck if content is zoomable
    if(!canZoomPanel(currentPanel))
#endif

    {
        if( VFX_PEN_EVENT_TYPE_UP == event.touchEvents[0].type ||
            VFX_PEN_EVENT_TYPE_UP == event.touchEvents[1].type )
        {
            currentPanel->setOwnerDrawHint(DH_NONE);
            currentPanel->setOwnerDrawBufferHint(VFX_FALSE);
            onDragEnd(VFX_FALSE);
        }
        return VFX_TRUE;
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_MULTI_TOUCH_EVENT_POS, 0, event.touchEvents[0].pos.x, event.touchEvents[0].pos.y, event.touchEvents[0].prevPos.x, event.touchEvents[0].prevPos.y);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_MULTI_TOUCH_EVENT_POS, 1, event.touchEvents[1].pos.x, event.touchEvents[1].pos.y, event.touchEvents[1].prevPos.x, event.touchEvents[1].prevPos.y);

    // hide all bars
    m_multiTouchZoomGesture = VFX_TRUE;

    // set parameters
    VfxU8 zoomAcelerateFactor = 2;
    VfxBool treatAsDragEnd = VFX_FALSE;
    if( VFX_PEN_EVENT_TYPE_UP == event.touchEvents[0].type ||
        VFX_PEN_EVENT_TYPE_UP == event.touchEvents[1].type )
    {
        zoomAcelerateFactor = 1;
        treatAsDragEnd = VFX_TRUE;
    }

    // calculate the zoom  value
    VfxFloat zoomMax = 0.f, zoomMin = 0.f;
    getCurrentPanel()->getMaxZoom(zoomMax);
    getCurrentPanel()->getMinZoom(zoomMin);

    VfxFloat d1 = VAPP_GALLERY_DISTANCE(event.touchEvents[0].prevPos, event.touchEvents[1].prevPos);
    VfxFloat d2 = VAPP_GALLERY_DISTANCE(event.touchEvents[0].pos,     event.touchEvents[1].pos);

    VfxFloat dZoom = (d2- d1)* (zoomMax - zoomMin) * GESTURE_FACTOR * zoomAcelerateFactor;
    VfxFloat value = m_zoomSlider->getCurrentValue() + dZoom;
    value = vfxMin(vfxMax(ZOOM_MIN, value), ZOOM_MAX);

    onBeginZoom(NULL, NULL);
    m_zoomSlider->setCurrentValue(value);
    onZoom(m_zoomSlider, value);
    onEndZoom(NULL, NULL);

    // pan
    VfxFloat prevCenterX = (event.touchEvents[0].prevPos.x + event.touchEvents[1].prevPos.x) / 2.0f;
    VfxFloat prevCenterY = (event.touchEvents[0].prevPos.y + event.touchEvents[1].prevPos.y) / 2.0f;
    VfxFloat centerX = (event.touchEvents[0].pos.x + event.touchEvents[1].pos.x) / 2.0f;
    VfxFloat centerY = (event.touchEvents[0].pos.y + event.touchEvents[1].pos.y) / 2.0f;
    VfxS32 panDx = (VfxS32)(centerX - prevCenterX);
    VfxS32 panDy = (VfxS32)(centerY - prevCenterY);
    onPan(panDx, panDy, treatAsDragEnd);

    if(treatAsDragEnd)
    {
        onDragEnd(VFX_FALSE);
    }

    if( VFX_PEN_EVENT_TYPE_UP == event.touchEvents[0].type ||
        VFX_PEN_EVENT_TYPE_UP == event.touchEvents[1].type )
    {
        m_multiTouchZoomGesture = VFX_FALSE;
    }
    return VFX_TRUE;
#endif
}

/*****************************************************************************
 * Class Implementation of VappGalleryShuffleIndex
 *****************************************************************************/
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
VappGalleryShuffleIndex::VappGalleryShuffleIndex(VfxU16 mediaCount):
	m_mediaCount(mediaCount), 
    m_indices(NULL)
{
}

void VappGalleryShuffleIndex::onInit()
{
    VfxObject::onInit();
    if(m_mediaCount)
    {
        // create an array of 0 ~ mediacount-1
        VFX_ALLOC_MEM(m_indices, (m_mediaCount * sizeof(VfxU16)), this);
        for(VfxU16 i = 0; i < m_mediaCount; ++i)
        {
            m_indices[i] = i;
        }

        // shuffle the array
        for(VfxU16 i=0; i< m_mediaCount; ++i)
        {
            const VfxU16 r = i + (rand() % (m_mediaCount-i)); // Random remaining position.
            if(i != r)
            {
                vfxSwap(m_indices[i], m_indices[r]);
            }
        }
    }
}

void VappGalleryShuffleIndex::onDeinit()
{
    if(m_indices)
    {
        VFX_FREE_MEM(m_indices);
        m_indices = NULL;
    }
    VfxObject::onDeinit();
}

MediaIndex VappGalleryShuffleIndex::getShuffledIndex(MediaIndex originalIndex)
{
    if(NULL == m_indices || originalIndex < 0 || originalIndex >= m_mediaCount)
    {
        return INVALID_MEDIA_INDEX;
    }

    return (MediaIndex)m_indices[originalIndex];
}

// e.g. ensureMediaIndexInPos(3) makes getShuffledIndex(3) == 3
void VappGalleryShuffleIndex::ensureMediaIndexInPos(MediaIndex originalIndex)
{
    if(NULL == m_indices || originalIndex < 0 || originalIndex >= m_mediaCount)
    {
        return;
    }

    for(VfxS32 pos = 0; pos < m_mediaCount; ++pos)
    {
        if(m_indices[pos] == originalIndex)
        {
            if(pos != originalIndex)
            {
                vfxSwap(m_indices[pos], m_indices[originalIndex]);
            }
            return;
        }
    }

}
#endif

/*****************************************************************************
 * Class Implementation of VappGalleryViewerPanel
 *****************************************************************************/
VappGalleryViewerPanel::VappGalleryViewerPanel():
	m_isVideo(VFX_FALSE)
	,m_imageFileType(GDI_IMAGE_TYPE_INVALID)
	,m_imageOriginalDimension(0, 0)
	,m_isAnimedGif(VFX_FALSE)
    ,m_is3DRedBlue(VFX_FALSE)
	,m_frameClipWindow(0, 0, 0, 0)
	,m_frameCount(0)
	,m_isLoading(VFX_FALSE)
	,m_mediaIndex(-1)
    ,m_previewImg(NULL)
    ,m_waitIcon(NULL)
    ,m_errIcon(NULL)
    ,m_playBtn(NULL)
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
	,m_maxZoomDim(0)
#endif
    ,m_currentRotation(ROTATE_0)        
    ,m_draw(NULL)

    #ifdef __VENUS_3D_UI_ENGINE__
    ,m_enhancedImg(NULL)
    #endif
    ,m_animTimer(NULL)
{
}

void VappGalleryViewerPanel::onInit()
{
    VfxFrame::onInit();
    m_mediaIndex = -1;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    m_maxZoomDim = 0;
#endif

    // setup render attributes
    setBgColor(VFX_COLOR_BLACK); // check if there are messed image
    setCacheMode(VFX_CACHE_MODE_AUTO);
    m_signalBoundsChanged.connect(this, &VappGalleryViewerPanel::onBoundsChange);

    const VfxPoint center(getSize().width / 2, getSize().height / 2);

    // error icon (default hidden)
    VFX_OBJ_CREATE(m_errIcon, VfxImageFrame, this);
    m_errIcon->setBgColor(VFX_COLOR_BLACK);
    m_errIcon->setAnchor(0.5, 0.5);
    m_errIcon->setPos(center);
    m_errIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON));
    m_errIcon->setHidden(VFX_TRUE);
    m_errIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID);
    m_errIcon->setAutoAnimate(VFX_TRUE);

    // create preview/icon image frame
    // note: geometry is adjusted in onBoundsChange().
    VFX_OBJ_CREATE(m_previewImg, VappGalleryPreviewImage, this);
    m_previewImg->setBgColor(VFX_COLOR_BLACK);
    m_previewImg->setAutoAnimate(VFX_TRUE);
    m_previewImg->setAnchor(0.5, 0.5);

    resetImageBuffer(m_cachedBuffer);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    resetImageBuffer(m_enhancedBuffer);
#endif

    VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
    m_waitIcon->setPos(center);
    m_waitIcon->setAnchor(0.5, 0.5);
    m_waitIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID);

    m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
    m_waitIcon->setAutoAnimate(VFX_TRUE);

    // create play button in the center
    // but hide it first
    VcpStateImage  playImgList;  // image resources for play button
    VfxImageSrc playIcon(IMG_ID_VAPP_GALLERY_IMG_ICON_VIDEO);
    playImgList.setImage(
            playIcon,
            playIcon,
            playIcon,
            playIcon);
    VFX_OBJ_CREATE(m_playBtn, VcpImageButton, this);
    m_playBtn->setImage(playImgList);
    m_playBtn->setSize(playIcon.getSize());
    m_playBtn->setEffectSize(playIcon.getSize());
    m_playBtn->setIsEffect(VFX_TRUE);
    m_playBtn->setAnchor(0.5f, 0.5f);
    m_playBtn->setPos(center);
    m_playBtn->setHidden(VFX_TRUE);
    m_playBtn->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID,
                              VFX_FRAME_ALIGNER_MODE_MID);
    m_playBtn->setAutoAnimate(VFX_TRUE);
    m_playBtn->m_signalClicked.connect(this, &VappGalleryViewerPanel::onPlayBtnClicked);
}

void VappGalleryViewerPanel::onDeinit()
{
    VfxFrame::onDeinit();
}

VfxBool VappGalleryViewerPanel::isLoading()
{
    return m_isLoading;
}

void VappGalleryViewerPanel::setIsLoading()
{
    m_isLoading = VFX_TRUE;
}

void VappGalleryViewerPanel::setMediaIndex(MediaIndex idx, VfxBool isVideo)
{
    m_mediaIndex = idx;
    setIcon(VIT_DEFAULT);
    m_playBtn->setHidden(!isVideo);
}

VfxBool VappGalleryViewerPanel::hasPlayButton()
{
    if(NULL == m_playBtn)
    {
        return VFX_FALSE;
    }
    return !m_playBtn->getHidden();
}

VfxBool VappGalleryViewerPanel::hasMediaIndex() const
{
    return m_mediaIndex != -1;
}

MediaIndex VappGalleryViewerPanel::getMediaIndex() const
{
    return m_mediaIndex;
}

void VappGalleryViewerPanel::clear()
{
    m_mediaIndex = -1;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    m_maxZoomDim = 0;
#endif

    m_frameCount = 0;
    // reset animation timer
    setPreviewImageAnimated(VFX_FALSE);

    // set as NULL content to release cache
    m_previewImg->setImgContent(VfxImageSrc());

    teardownOwnerDraw();
    resetImageBuffer(m_cachedBuffer);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    resetImageBuffer(m_enhancedBuffer);
#endif

    setIsVideo(VFX_FALSE);
    setImageType(GDI_IMAGE_TYPE_INVALID);
    setImageOriginalDimension(VfxSize(0, 0));
    setIsAnimedGif(VFX_FALSE);
    setFrameIndex(0);
    setIs3DRedBlueImage(VFX_FALSE);

    // return back to default icon
    // setIcon(VIT_DEFAULT);

    closeAnimTimer();
}

void VappGalleryViewerPanel::calculateBaseSizeFromSourceImage(VfxSize &sz)
{
    // UE spec rule:
    //  1. picture size > view size (at any axis) ==> fit view
    //  2. picture size < view size (both axis) ==> center
    //  ==>  GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT suits our need.
    VfxS32 l = 0;
    VfxS32 t = 0;

    VfxS32 src_w = m_sizeOriginal.width;
    VfxS32 src_h = m_sizeOriginal.height;
    VfxS32 dst_w = getSize().width;
    VfxS32 dst_h = getSize().height;
    if(0 != (m_currentRotation % 2))
    {
        vfxSwap(src_w, src_h);
    }

    gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                dst_w,
                dst_h,
                src_w,
                src_h,
                &l,
                &t,
                &sz.width,
                &sz.height);
    if(0 != (m_currentRotation % 2))
    {
        vfxSwap(sz.width, sz.height);
    }
    return;
}

VfxBool VappGalleryViewerPanel::checkImageDRMRights(const VfxImageSrc src)
{
#ifdef __DRM_SUPPORT__
    // only check file-based sources
    if(VFX_IMAGE_SRC_TYPE_PATH != src.getType())
        return VFX_TRUE;

    if(DRM_METHOD_NONE == DRM_get_object_method(NULL, (kal_wchar*)src.getPath().getBuf()))
        return VFX_TRUE;

    if(!DRM_validate_permission(0, (kal_wchar*)src.getPath().getBuf(), DRM_PERMISSION_DISPLAY))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
#else
    return VFX_TRUE;
#endif
}

void VappGalleryViewerPanel::setIcon(ViewIconType icon)
{
    // set as NULL content to release cache
    teardownOwnerDraw();
    m_previewImg->setImgContent(VfxImageSrc());
    m_previewImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_previewImg->setSize(getSize());
    m_previewImg->setHidden(VFX_TRUE);
    resetImageBuffer(m_cachedBuffer);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    resetImageBuffer(m_enhancedBuffer);
#endif

    // loading is wait spin
    if(VIT_DEFAULT == icon)
    {
        m_errIcon->setHidden(VFX_TRUE);
        m_waitIcon->start();
        setCacheMode(VFX_CACHE_MODE_PREVENT);
    }
    else
    {
        m_errIcon->setHidden(VFX_FALSE);
        m_waitIcon->stop();
        setCacheMode(VFX_CACHE_MODE_AUTO);
        m_isLoading = VFX_FALSE;
        switch(icon)
        {
        case VIT_ERROR:
            m_errIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON));
            break;
        case VIT_DRM:
            m_errIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_DRM_ICON));
            break;
        default:
            VFX_DEV_ASSERT(0);
            m_errIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON));
            break;
        }
    }
    return;
}

void VappGalleryViewerPanel::setPreviewImage(const VfxImageSrc &imgSrc, VfxBool drmCheck)
{
    if(drmCheck && !checkImageDRMRights(imgSrc))
    {
        setIcon(VIT_DRM);
        return;
    }

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    if(VFX_IMAGE_SRC_TYPE_PATH == imgSrc.getType())
    {
        m_maxZoomDim = VappGalleryEnhancedImage::getMaxEnhanceDimensionByPath(imgSrc.getPath());
    }
    else
    {
        m_maxZoomDim = 0;
    }
#endif

    teardownOwnerDraw();
    m_waitIcon->stop();
    m_errIcon->setHidden(VFX_TRUE);
    m_isLoading = VFX_FALSE;
    m_sizeOriginal = imgSrc.getSize();
    m_previewImg->setImgContent(imgSrc);
    m_previewImg->setHidden(VFX_FALSE);
    setCacheMode(VFX_CACHE_MODE_AUTO);
    m_previewImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    resetViewState();
}

VfxBool VappGalleryViewerPanel::getPreviewImage(VfxImageSrc &imgSrc)
{
    VfxImageSrc src = m_previewImg->getImgContent();
    if(VFX_IMAGE_SRC_TYPE_NULL == src.getType())
    {
        return VFX_FALSE;
    }

    imgSrc = src;
    return VFX_TRUE;
}

void VappGalleryViewerPanel::setPreviewImageAnimated(VfxBool isAnim)
{
    if(m_previewImg)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_SET_PREVIEW_IMAGE_ANIMATED_THIS_X_ANIM_D, this, isAnim);
        // do not allow zoom for animated images
        if(isAnim)
        {
            m_previewImg->play();
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
            m_maxZoomDim = 0;
#endif
        }
        else
        {
            //m_previewImg->stop();
            m_previewImg->suspend();
        }
    }
}

VfxBool VappGalleryViewerPanel::isOwnerDraw()
{
    // owner draw or
    // buffer source (3D case, only buffer source but not owner draw)
#ifdef __VENUS_3D_UI_ENGINE__
    return (NULL != m_previewImg->getMaterial() || NULL != m_enhancedImg);
#else
    return (NULL != getOwnerDraw());
#endif
}

VfxBool VappGalleryViewerPanel::setOwnerDrawHint(DrawHint hint)
{
    if(m_draw)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWERCP_SET_OWNER_DRAWER_HINT, hint);
        m_draw->setDrawHint(hint);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappGalleryViewerPanel::isPreviewImageAnimated()
{
    if(NULL == m_previewImg)
    {
        return VFX_FALSE;
    }

    const VfxImageSrc src = m_previewImg->getImgContent();
    if(src.isNull() ||
       src.isEmpty() ||
       isOwnerDraw())
    {
        return VFX_FALSE;
    }

    // note: for NULL SRC, this will return TRUE,
    // so we check NULL SRC first.
    return m_previewImg->getHasAnimateImage();
}

VfxBool VappGalleryViewerPanel::isDisplayImage()
{
    if(isOwnerDraw() &&
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
       (hasEnhancedBuffer() || hasCachedBuffer()))
#else
		hasCachedBuffer())
#endif

    {
        return VFX_TRUE;
    }
    if(NULL == m_previewImg)
    {
        return VFX_FALSE;
    }
    VfxImageSrc src = m_previewImg->getImgContent();
    if(src.isNull() || src.isEmpty())
    {
        return VFX_FALSE;
    }
    if(VFX_IMAGE_SRC_TYPE_RES_ID == src.getType())
    {
        return VFX_FALSE;
    }
    if(src.getSize().width == 0 ||
       src.getSize().height == 0)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappGalleryViewerPanel::hasCachedBuffer()const
{
    return (NULL != m_cachedBuffer.ptr);
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
VfxBool VappGalleryViewerPanel::hasEnhancedBuffer()
{
    return (NULL != m_enhancedBuffer.ptr);
}
#endif
void VappGalleryViewerPanel::setPreviewCachedBuffer(const VfxImageBuffer &imgBuf,
                                                           VfxS32 maxZoomDim,
                                                           const VfxSize *originalImageSize,
                                                           const VfxWString &path,
                                                           VfxRect clipWindow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_SET_PREVIEW_CACHED_BUFFER);
    VFX_ASSERT(imgBuf.ptr);

    // allow user to assign a maximum zoom dimension.
    // e.g. some file format are not allowed to zoom
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    m_maxZoomDim = maxZoomDim;
#endif

    // preview buffer size may be different from
    // actual image original size
    if(originalImageSize)
    {
        m_sizeOriginal = *originalImageSize;
    }
    else
    {
        m_sizeOriginal.width = imgBuf.width;
        m_sizeOriginal.height = imgBuf.height;
    }

    // stop waiting icon and set up owner draw
    m_waitIcon->stop();
    m_errIcon->setHidden(VFX_TRUE);
    m_isLoading = VFX_FALSE;

    m_cachedBuffer = imgBuf;
    setupOwnerDraw();
    if(m_draw)
    {
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        m_draw->setBufferSource(
                    &m_cachedBuffer,
                    m_enhancedBuffer.ptr ? &m_enhancedBuffer : NULL
                    );
#else
	m_draw->setBufferSource(&m_cachedBuffer, NULL);
#endif
        m_draw->setFilePath(path);
        m_draw->setFrameClipWindow(clipWindow);
    }
    resetViewState();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    if(m_draw)
        m_draw->setupZoomSize(m_sizeOriginal);
    #endif
#endif
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
void VappGalleryViewerPanel::clearEnhnacedBuffer()
{
    resetImageBuffer(m_enhancedBuffer);
    teardownOwnerDraw();

    if(hasCachedBuffer() && m_previewImg)
    {
        setupOwnerDraw();
        if(m_draw)
        {
            m_draw->setBufferSource(
                        &m_cachedBuffer,
                        m_enhancedBuffer.ptr ? &m_enhancedBuffer : NULL
                        );
        }
        m_previewImg->setImgContent(VfxImageSrc(m_cachedBuffer));
        m_previewImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    }
    else if(m_previewImg)
    {
        m_previewImg->setImgContent(VfxImageSrc());
    }
}

void VappGalleryViewerPanel::setEnhancedBuffer(const VfxImageBuffer &imgBuf)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_SET_ENHANCED_BUFFER);
    VFX_ASSERT(imgBuf.ptr);
    VFX_ASSERT(m_cachedBuffer.ptr != NULL); // must called setPreviewCachedBuffer() first

    m_enhancedBuffer = imgBuf;
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    m_sizeOriginal.width = m_enhancedBuffer.width;
    m_sizeOriginal.height = m_enhancedBuffer.height;
#endif
    setupOwnerDraw();
    if(m_draw)
    {
        m_draw->setBufferSource(
                    &m_cachedBuffer,
                    &m_enhancedBuffer
                    );
    }

    // unlike setPreviewCachedBuffer(), we don't reset view state here.
    invalidate();
}
#endif

void VappGalleryViewerPanel::setupOwnerDraw()
{
    if(NULL == m_previewImg)
    {
        return;
    }

#ifdef __VENUS_3D_UI_ENGINE__
    {
        setupZoomFrames();
        return;
    }
#endif
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_OWNER_DRAW, 1);

    // enhance should keep current view state
    setCacheMode(VFX_CACHE_MODE_PREVENT);

    // hide the preview image
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_previewImg->setOpacity(0.0f);
    m_previewImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_previewImg->setBgColor(VFX_COLOR_BLACK);
    m_previewImg->setImgContent(VfxImageSrc());
    m_previewImg->setHidden(VFX_FALSE);
    VfxAutoAnimate::commit();

    // set owner draw
    if(NULL == m_draw || NULL == getOwnerDraw())
    {
        if(NULL == m_draw)
        {
            VFX_OBJ_CREATE(m_draw, VappGalleryImageDrawer, this);
        }
        setOwnerDraw(m_draw);
        setPropertyEffectCallback(
                                m_previewImg,
                                VappGalleryImageDrawer::onFPECallback,
                                &m_draw,
                                sizeof(m_draw),
                                VRT_FPE_TRIGGER_TYPE_DIRTY);

        m_draw->setOrifinalDim(m_imageOriginalDimension);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
        m_draw->setupZoomSize(m_sizeOriginal);
        m_draw->m_signalStartToDecodeEnhanceBuf.connect(this, &VappGalleryViewerPanel::onStartPartialEnhanceDecode);
        #endif
#endif
    }
}

void VappGalleryViewerPanel::teardownOwnerDraw()
{
#ifdef __VENUS_3D_UI_ENGINE__
    {
        teardownZoomFrames();
    }
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_OWNER_DRAW, 0);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    if(m_draw)
    {
        m_draw->m_signalStartToDecodeEnhanceBuf.disconnect(this, &VappGalleryViewerPanel::onStartPartialEnhanceDecode);
    }
    #endif
#endif

    // clear owner draw and FPE
    setOwnerDraw(NULL);
    setPropertyEffectCallback(
                            NULL,
                            NULL,
                            NULL,
                            0,
                            VRT_FPE_TRIGGER_TYPE_DIRTY);
    VFX_OBJ_CLOSE(m_draw);
    setCacheMode(VFX_CACHE_MODE_AUTO);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_previewImg->setOpacity(1.0f);
    VfxAutoAnimate::commit();
}

VfxBool VappGalleryViewerPanel::getPreviewCachedBuffer(VfxImageBuffer &buf)
{
    if(NULL == m_cachedBuffer.ptr)
    {
        return VFX_FALSE;
    }

    buf = m_cachedBuffer;
    return VFX_TRUE;
}

void VappGalleryViewerPanel::resetViewState(VfxBool resetSize)
{
    // reset without animation
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    // make the image center-placed in the preview area
    m_currentRotation = ROTATE_0;
    calculateBaseSizeFromSourceImage(m_baseSize);
    VfxTransform t;
    t.setIdentity();
    m_previewImg->setTransform(t);
    m_previewImg->setSize(m_baseSize);
    m_previewImg->setAnchor(0.5f, 0.5f);
    m_previewImg->setPos(getSize().width / 2,
                         getSize().height / 2);
    VfxAutoAnimate::commit();

    // stop playing animation when resetted.
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_SET_HAS_ANIMATE_IMAGE_VFX_FALSE_THIS_X, this);
    //m_previewImg->stop();
    // in order to maintain same frame content as panel switch befefore, call suspend
    // VfxAnimaated froame will help to stop anim play while content change 
    m_previewImg->suspend();
    return;
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
void VappGalleryViewerPanel::setZoom(VfxFloat zoomLevel)
{
	GALLERY_MEASURE_TIME_START("GVZ");

    // clamp to valid zoom range
    VfxFloat zoomMin = 1.0f, zoomMax = 1.0f;
    getZoomRange(zoomMin, zoomMax);
    zoomLevel = vfxMin(vfxMax(zoomMin, zoomLevel), zoomMax);

    startAnimTimer(VFX_FALSE, 50, __LINE__);

    // zoom the preview image by setting size of the Image
    const VfxSize &initSize = m_baseSize;
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);
    VfxAutoAnimate::setDuration(50);
    m_previewImg->setSize((VfxS32)(initSize.width * zoomLevel), (VfxS32)(initSize.height * zoomLevel));
    VfxAutoAnimate::commit();

    // update anchor if necessary (out-of-bound)
    VfxFPoint currentAnchor = m_previewImg->getAnchor();
    clampAnchorPointWithinMargin(currentAnchor);
    m_previewImg->setAnchor(currentAnchor);
    GALLERY_MEASURE_TIME_STOP("GVZ");
}

void VappGalleryViewerPanel::getZoomRange(VfxFloat &zoomMin, VfxFloat &zoomMax)
{
    getMinZoom(zoomMin);
    getMaxZoom(zoomMax);
    return;
}

VfxBool VappGalleryViewerPanel::isZoomed()
{
    if(NULL == m_previewImg || !isDisplayImage())
    {
        return VFX_FALSE;
    }

    const VfxSize visibleSize = m_previewImg->getSize();

    return visibleSize.width > m_baseSize.width ||
           visibleSize.height > m_baseSize.height;
}

void VappGalleryViewerPanel::getZoom(VfxFloat &zoomLevel)
{
    if(NULL == m_previewImg)
    {
        getMinZoom(zoomLevel);
        return;
    }
    // since m_baseSize is un-rotated,
    // check the un-rotated size of image.
    const VfxSize previewSize = m_previewImg->getSize();
    zoomLevel = vfxMax(previewSize.width * 1.0f /  m_baseSize.width,
                       previewSize.height * 1.0f /  m_baseSize.height);
    return;
}

void VappGalleryViewerPanel::getMinZoom(VfxFloat &zoomLevel)
{
    // minimum zoom is always default "fit-panel-or-no-resize" zoom
    // it is 1.0f with normal orientation.
    zoomLevel = 1.0f;
    return;
}

void VappGalleryViewerPanel::getMaxZoom(VfxFloat &zoomLevel)
{
    if(0 == m_maxZoomDim ||
       0 == m_baseSize.width ||
       0 == m_baseSize.height)
    {
        zoomLevel = 1.0f;
        return;
    }

    const VfxSize scrSize = getSize();
    const VfxSize &picSize = m_sizeOriginal;

    // 1. if original picture is smaller than screen size
    //    zoom to it's own 2x
    VfxS32 minPic = vfxMin(picSize.width, picSize.height);
    VfxS32 maxPic = vfxMax(picSize.width, picSize.height);
    VfxS32 minScr = vfxMin(scrSize.width, scrSize.height);
    VfxS32 maxScr = vfxMax(scrSize.width, scrSize.height);
    if(minPic <= minScr && maxPic <= maxScr)
    {
        zoomLevel = 2.0f;
        return;
    }

    // 3. Otherwise, zoom to enhanced buffer size or 4X LCD size
    //    The enhanced buffer size is determined by
    //    VappGalleryEnhancedImage::getEnhancedImageSize(),
    //    Which is max 3x LCD size
    const VfxFloat zoomToOrigin = vfxMax(picSize.width * 1.0f / m_baseSize.width,
                                         picSize.height * 1.0f / m_baseSize.height);
    const VfxFloat ratioLCD4X = vfxSqrt(GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 4.0f / (picSize.width * picSize.height));
    const VfxFloat zoomTo4XLCD = vfxMax(picSize.width * ratioLCD4X / m_baseSize.width,
                                        picSize.height * ratioLCD4X / m_baseSize.height);
    zoomLevel = vfxMax(zoomTo4XLCD, zoomToOrigin);

    // However, there are HW constraints that limits our zoom ratio
    zoomLevel = vfxMin(vfxMin(m_maxZoomDim * 1.0f / m_baseSize.width,
                              m_maxZoomDim * 1.0f / m_baseSize.height),
                       zoomLevel);
    return;
}

void VappGalleryViewerPanel::getDoubleTapZoom(VfxFloat &zoomLevel)
{
    // in current UE, double tap goes to max zoom
    getMaxZoom(zoomLevel);
    return;
}
#endif

void VappGalleryViewerPanel::setIsVideo(const VfxBool isVideo)
{
    m_isVideo = isVideo;
}

void VappGalleryViewerPanel::setImageType(const VfxU16 imageType)
{
    m_imageFileType = imageType;
}

void VappGalleryViewerPanel::setImageOriginalDimension(const VfxSize s)
{
    m_imageOriginalDimension = s;
}

void VappGalleryViewerPanel::setIsAnimedGif(const VfxBool isAnim)
{
    m_isAnimedGif = isAnim;
}

void VappGalleryViewerPanel::setIs3DRedBlueImage(const VfxBool is3DRedBlue)
{
    m_is3DRedBlue = is3DRedBlue;
}

VfxU16 VappGalleryViewerPanel::getImageType() const
{
    return m_imageFileType;
}

VfxBool VappGalleryViewerPanel::getIsVideo() const
{
    return m_isVideo;
}

VfxBool VappGalleryViewerPanel::getIsAnimedGif() const
{
    return m_isAnimedGif;
}

VfxBool VappGalleryViewerPanel::getIs3DRedBlueImage() const
{
    return m_is3DRedBlue;
}

VfxSize VappGalleryViewerPanel::getImageOriginalDimension() const
{
    return m_imageOriginalDimension;
}

void VappGalleryViewerPanel::setFrameIndex(VfxS32 frameIndex)
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if(m_previewImg)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_SET_FRAME_INDEX, frameIndex);
        // disable autoainmate to avoid redundant frame decode cause by autoainmate interpolation
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_previewImg->setPosZ((VfxFloat)frameIndex);
        VfxAutoAnimate::commit();
    }
#endif
}

VfxS32 VappGalleryViewerPanel::getFrameIndex()
{
    return (m_previewImg)? (VfxS32)m_previewImg->getPosZ() : 0;
}

VfxS32 VappGalleryViewerPanel::getMaxFrameIndex()
{
    return ((0 < m_frameCount)? m_frameCount - 1 : 0 );
}

VfxS32 VappGalleryViewerPanel::getMinFrameIndex()
{
    return 0;
}

VfxBool VappGalleryViewerPanel::getIsMAV()
{
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if(GDI_IMAGE_TYPE_MAV_FILE == m_imageFileType|| GDI_IMAGE_TYPE_MAV == m_imageFileType)
        return VFX_TRUE;
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif
}

VfxSize VappGalleryViewerPanel::getCurrentPreviewSize() const
{
    if(NULL == m_previewImg)
    {
        return VfxSize(0, 0);
    }

    VfxSize s = m_previewImg->getSize();

    switch(m_currentRotation)
    {
    case ROTATE_90:
    case ROTATE_270:
        vfxSwap(s.width, s.height);
        break;
    default:
        break;
    }
    return s;
}

VfxFPoint VappGalleryViewerPanel::getMaxAnchorMargin() const
{
    const VfxSize currentSize = getCurrentPreviewSize();
    const VfxSize viewSize = getSize();
    VfxFPoint maxMargin(vfxMin(0.5f, (viewSize.width / 2.0f) / (VfxFloat)currentSize.width),
                              vfxMin(0.5f, (viewSize.height / 2.0f) / (VfxFloat)currentSize.height));

    // rotated 90 or 270
    if(0 != m_currentRotation % 2)
    {
        vfxSwap(maxMargin.x, maxMargin.y);
    }
    return maxMargin;
}

void VappGalleryViewerPanel::clampAnchorPointWithinMargin(VfxFPoint &anchorPoint) const
{
    const VfxFPoint margin = getMaxAnchorMargin();
    anchorPoint.x = vfxMin(1.0f - margin.x, anchorPoint.x);
    anchorPoint.x = vfxMax(margin.x, anchorPoint.x);
    anchorPoint.y = vfxMin(1.0f - margin.y, anchorPoint.y);
    anchorPoint.y = vfxMax(margin.y, anchorPoint.y);
}

void VappGalleryViewerPanel::offsetView(VfxS32 offsetX, VfxS32 offsetY, PanningHint hint, VfxS32 &remainOffsetX)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_OFFSET_VIEW, offsetX, offsetY, hint, m_mediaIndex);

    // this is rotated size
    VfxSize currentSize = getCurrentPreviewSize();

    // calcuate movement ratio w.r.t. preview size
    // note that anchor moving direction and image moving direction
    // are opposite.
    VfxFPoint anchorOffset(-offsetX / (VfxFloat)currentSize.width,
                           -offsetY / (VfxFloat)currentSize.height);

    // transform view offset back to canvas offset
    switch(m_currentRotation)
    {
    case ROTATE_0:
        break;
    case ROTATE_90:
        vfxSwap(anchorOffset.x, anchorOffset.y);
        anchorOffset.y *= -1;
        break;
    case ROTATE_180:
        anchorOffset.x *= -1;
        anchorOffset.y *= -1;
        break;
    case ROTATE_270:
        vfxSwap(anchorOffset.x, anchorOffset.y);
        anchorOffset.x *= -1;
        break;
    }

    const VfxFPoint margin = getMaxAnchorMargin();

    VfxFPoint currentAnchor;

    if(STOP == hint)
    {
        currentAnchor = m_previewImg->forceGetAnchor();
    }
    else
    {
        currentAnchor = m_previewImg->getAnchor();
    }

    currentAnchor.x += anchorOffset.x;
    currentAnchor.y += anchorOffset.y;

    const VfxFPoint inputAnchor = currentAnchor;

    // clamp within margin
    clampAnchorPointWithinMargin(currentAnchor);

    // check how many offset is out-of-boundary and return to caller
    switch(m_currentRotation)
    {
    case ROTATE_0:
        remainOffsetX = (VfxS32)(currentSize.width * (currentAnchor.x - inputAnchor.x));
        break;
    case ROTATE_180:
        remainOffsetX = (VfxS32)(currentSize.width * (currentAnchor.x - inputAnchor.x) * -1);
        break;
    case ROTATE_90:
        remainOffsetX = (VfxS32)(currentSize.width * (currentAnchor.y - inputAnchor.y) * -1);
        break;
    case ROTATE_270:
        remainOffsetX = (VfxS32)(currentSize.width * (currentAnchor.y - inputAnchor.y));
        break;
    }

    // update anchor point to translate image
    VfxAutoAnimate::begin();
    if(MOVE == hint || STOP == hint)
    {
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    }
    else if(INERTIA == hint)
    {
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    }

    VfxMsec animTime = VappImageViewerComponent::PANNING_ANIM_DURATION;
    switch(hint)
    {
    case STOP:
        animTime = 0;
        break;
    case INERTIA:
        animTime = VappGalleryInertiaPan::INERTIA_ANIM_TIME;
        break;
    case MOVE:
        animTime = VappImageViewerComponent::PANNING_ANIM_DURATION / 4;
        break;
    }

    VfxAutoAnimate::setDuration(animTime); //VappGalleryViewerPage::PANNING_ANIM_DURATION);
    m_previewImg->setAnchor(currentAnchor);
    VfxAutoAnimate::commit();

    if(STOP != hint)
    {
        startAnimTimer(VFX_FALSE, animTime, __LINE__);
    }
}

void VappGalleryViewerPanel::setRotate(PreviewRotation r, VfxBool isAnim)
{
    if(m_currentRotation == r)
    {
        return;
    }

    m_currentRotation = r;


    // update new preview rectangle, note UE behavior is reset zoom level
    calculateBaseSizeFromSourceImage(m_baseSize);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    VfxFloat minZoom = 1.0f;
    getMinZoom(minZoom);
    setZoom(minZoom);
#else
	startAnimTimer(VFX_FALSE, 50, __LINE__);

    // zoom the preview image by setting size of the Image
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);
    VfxAutoAnimate::setDuration(50);
    m_previewImg->setSize(m_baseSize);
    VfxAutoAnimate::commit();

    // update anchor if necessary (out-of-bound)
    VfxFPoint currentAnchor = m_previewImg->getAnchor();
    clampAnchorPointWithinMargin(currentAnchor);
    m_previewImg->setAnchor(currentAnchor);   
#endif

    // rules:
    // 1. no matter which zoom level, we always reset to fit preview area.
    // 2. if the rotation is over 270 degree, change it to -90 degree
    VfxTransform t = m_previewImg->getTransform();
    const VfxFloat rz = VFX_DEG_TO_RAD(VfxS32(m_currentRotation) * 90.0f);
    if(rz - t.data.affine.rz < 0)
    {
        // set new rotation interpolation start value
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
        m_previewImg->setTransform(t);
        VfxAutoAnimate::commit();
    }
    t.data.affine.rz = rz;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    m_previewImg->setAnchor(0.5f, 0.5f);
    m_previewImg->setPos(getRect().getMidPoint());
    m_previewImg->setTransform(t);
    VfxAutoAnimate::commit();
}

VappGalleryViewerPanel::PreviewRotation VappGalleryViewerPanel::getRotate()
{
    return m_currentRotation;
}

void VappGalleryViewerPanel::rotateCW(VfxBool isAnim)
{
    PreviewRotation r = getRotate();
    r = (PreviewRotation)(((VfxS32)r + 1) % ROTATE_ENUM_COUNT);
    setRotate(r, isAnim);
    return;
}

void VappGalleryViewerPanel::onBoundsChange(VfxFrame *frm, const VfxRect &oldRect)
{
    if(NULL == m_previewImg)
    {
        return;
    }

    // if old rect is 0,0, then we should avoid animation
    if(oldRect.size.width == 0 || oldRect.size.height == 0)
    {
        resetViewState();
        return;
    }

    const VfxRect newRect = getRect();
    m_previewImg->setAutoAnimate(VFX_TRUE);
    // if not zoomed, or the zoom image is smaller than rect
    const VfxSize oldPreviewImgSize = getCurrentPreviewSize();
    const VfxPoint pageCenter(newRect.size.width / 2,
                              newRect.size.height / 2);
    const VfxBool notZoomed = (oldPreviewImgSize.width <= m_baseSize.width
                              && oldPreviewImgSize.height <= m_baseSize.height);

    calculateBaseSizeFromSourceImage(m_baseSize);
    m_previewImg->setPos(pageCenter);


//use compile option to remove zoom in/out code 2012-11-19
#ifndef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    if(notZoomed)
    {
        // not zoomed case, put to center directly
        // and zoom to max
        m_previewImg->setAnchor(0.5f, 0.5f);
    }
	startAnimTimer(VFX_FALSE, 50, __LINE__);
    // zoom the preview image by setting size of the Image
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);
    VfxAutoAnimate::setDuration(50);
    m_previewImg->setSize(m_baseSize);
    VfxAutoAnimate::commit();
#else
	VfxFloat prevZoom = 1.0f;
    if(notZoomed)
    {
        // not zoomed case, put to center directly
        // and zoom to max
        m_previewImg->setAnchor(0.5f, 0.5f);
        prevZoom = 1.0f;
    }
    else
    {
        // otherwise clamp zoom size and adjust anchor
        getZoom(prevZoom);
    }
	// update new zoom size
    setZoom(prevZoom);
#endif

    // update new zoom size
    VfxFPoint currentAnchor = m_previewImg->getAnchor();
    clampAnchorPointWithinMargin(currentAnchor);
    m_previewImg->setAnchor(currentAnchor);
}

void VappGalleryViewerPanel::onPlayBtnClicked(VfxObject *sender, VfxId btnId)
{
    if(hasMediaIndex())
    {
        m_signalPlayCommand.emit(getMediaIndex());
    }
}

VfxBool VappGalleryViewerPanel::setOwnerDrawBufferHint(VfxBool forceUsePreviewBuf)
{
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    if(m_previewImg)
    {
        const VfxFloat hint = (forceUsePreviewBuf) ? (VappGalleryImageDrawer::FORCE_USE_PREVIEW_BUFF) : 0.f;
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_previewImg->setFpeUser0(hint);
        VfxAutoAnimate::commit();
        return VFX_TRUE;
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif
#else
	return VFX_FALSE;
#endif
}

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
void VappGalleryViewerPanel::onStartPartialEnhanceDecode(VfxSize decodedLayerSize, VfxRect clipRect)
{
    m_signalStartDecodeL1EnhanceBuf.emit(decodedLayerSize, clipRect);
}

void VappGalleryViewerPanel::onCancelPartialEnhanceDecode()
{
    if(m_draw)
    {
        m_draw->cancleEnhanceDecode();
        clearEnhnacedBuffer();
    }
}

VfxBool VappGalleryViewerPanel::updateEnhanceBufToDraw(const VfxRect clipRectCheckSum)
{
    if(clipRectCheckSum == VfxRect(0, 0, 0, 0))
        return VFX_FALSE;
    if(m_draw)
    {
        VfxRect r = m_draw->getEnhanceMemento();
        const VfxBool res = (r == clipRectCheckSum) ? VFX_TRUE : VFX_FALSE;
        return res;
    }
    return VFX_FALSE;
}

void VappGalleryViewerPanel::onFinishPartialEnhanceDecode(const VfxRect clipRectCheckSum)
{
    if(m_draw)
    {
        m_draw->setIsEnhanceBufReady(VFX_TRUE);
        m_previewImg->invalidate();
        invalidate();
    }
}
#endif
#endif

void VappGalleryViewerPanel::startAnimTimer(const VfxBool disabledAnimTimer, const VfxMsec duration, const VfxU32 line)
{
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    if(NULL == m_animTimer)
    {
        VFX_OBJ_CREATE(m_animTimer, VfxTimer, this);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PANEL_START_ANIM_TIMER, disabledAnimTimer, duration, line, m_mediaIndex);

    // make sure anim timer is already stopped
    stopAnimTimer();

    // check if we skip to launch anim timer
    if(disabledAnimTimer)
    {
        return;
    }

    // disable to draw enhance
    setOwnerDrawBufferHint(VFX_TRUE);

    m_animTimer->setDuration(duration);
    m_animTimer->setStartDelay(duration);
    m_animTimer->m_signalTick.connect(this, &VappGalleryViewerPanel::onAnimTimeout);
    m_animTimer->start();
#endif
}

void VappGalleryViewerPanel::stopAnimTimer()
{
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    if(NULL == m_animTimer){return;}
    m_animTimer->m_signalTick.disconnect(this, &VappGalleryViewerPanel::onAnimTimeout);
    m_animTimer->stop();
#endif
}

void VappGalleryViewerPanel::closeAnimTimer()
{
    stopAnimTimer();
    VFX_OBJ_CLOSE(m_animTimer);
}

void VappGalleryViewerPanel::onAnimTimeout(VfxTimer *timer)
{
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    stopAnimTimer();

    setOwnerDrawBufferHint(VFX_FALSE);

    //TODO: check if we aleardy set enhance image
    invalidate();
    m_previewImg->invalidate();
#endif
}

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoPage
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoCell
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoParser
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryWallpaperPreviewPage
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryDRMConsumer
 *****************************************************************************/
VfxObjHandle VappGalleryDRMConsumer::g_instances[VappGalleryDRMConsumer::MAX_CONSUMER_INSTANCE] = {0};


VappGalleryDRMConsumer::VappGalleryDRMConsumer():
    m_userData(-1),
	m_jobId(-1),
    m_shouldConsume(VFX_FALSE),
    m_state(STATE_IDLE)
{
}

void VappGalleryDRMConsumer::onInit()
{
    VfxObject::onInit();
}

void VappGalleryDRMConsumer::onDeinit()
{
    // must stop consuming.
    stopConsume();
    // unregister object from global table
    unregisterInstance();
    VfxObject::onDeinit();
}

VfxBool VappGalleryDRMConsumer::registerInstance()
{
    // register instance pointer into global table
    for(VfxS32 i = 0; i < MAX_CONSUMER_INSTANCE; ++i)
    {
        if(NULL == g_instances[i] || NULL == handleToObject(g_instances[i]))
        {
            g_instances[i] = this->getObjHandle();
            return VFX_TRUE;
        }
    }

    // slot full, cannot register
    return VFX_FALSE;
}

void VappGalleryDRMConsumer::unregisterInstance()
{
    // unregister instance pointer from global table
    for(VfxS32 i = 0; i < MAX_CONSUMER_INSTANCE; ++i)
    {
        if(g_instances[i])
        {
            VfxObject *obj = handleToObject(g_instances[i]);

            // clear any invalid object we found
            // and clear ourself
            if(NULL == obj ||
               static_cast<VfxObject*>(this) == obj)
            {
                g_instances[i] = NULL;
            }
        }
    }
}

void VappGalleryDRMConsumer::setFileAndUserData(const VfxWString &filePath, VfxS32 userData)
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_SET_FILE);

    // ignore same-file request,
    // since we don't want to consume too much count.
    if(m_filePath == filePath && m_shouldConsume)
    {
        return;
    }

    stopConsume();

    m_filePath = filePath;
    m_userData = userData;
    m_shouldConsume = VFX_FALSE;

    FS_HANDLE hDRMFile = DRM_open_file((kal_wchar*)m_filePath.getBuf(), FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if(hDRMFile < FS_NO_ERROR)
    {
        return;
    }

    do
    {
        // NO DRM available, no need to consume
        if(DRM_METHOD_NONE == DRM_get_object_method(hDRMFile, NULL))
        {
            break;
        }

        // No permission to display, no need to consume
        if(KAL_FALSE == DRM_validate_permission(hDRMFile, NULL, DRM_PERMISSION_DISPLAY))
        {
            m_signalRightExpired.postEmit(this, m_userData, (drm_proc_enum)m_jobId);
            break;
        }

        m_shouldConsume = VFX_TRUE;
    }while(0);

    DRM_close_file(hDRMFile);
    hDRMFile = -1;
#endif
}

void VappGalleryDRMConsumer::startConsume()
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_START_CONSUME);

    if(!m_shouldConsume)
        return;

    if(STATE_CONSUME == m_state)
        return;

    if(STATE_PAUSED_CONSUME == m_state)
    {
        resumeConsume();
        return;
    }
    /*
    // in DRM 2.0, which is time consume based and supports pause/resume consume
    // DRM count is decreased while APPs calls DRM_stop_consume
    // so we call comsumeDRMCountImpl when viewer start consume
    consumeDRMCountImpl();
    */
#endif
}

void VappGalleryDRMConsumer::stopConsume()
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_STOP_CONSUME);
    if(!m_shouldConsume)
    {
        return;
    }

    // change for DRM 2.0 phase out, current DRM is count consume based
    // in DRM 1.0, DRM count is decreased while APPs calls DRM_consume_rights
    // so we consume count when viewer stop consume
    consumeDRMCountImpl();

    if(STATE_CONSUME == m_state ||
       STATE_PAUSED_CONSUME == m_state)
    {
        DRM_stop_consume(m_jobId);
        m_jobId = 0;
        m_state = STATE_IDLE;
        unregisterInstance();
    }
#endif
}

void VappGalleryDRMConsumer::consumeDRMCountImpl()
{
#ifdef __DRM_SUPPORT__
    FS_HANDLE hDRMFile = DRM_open_file((kal_wchar*)m_filePath.getBuf(), FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if(hDRMFile < FS_NO_ERROR)
    {
        return;
    }

    // register instances, since we're going to receiving DRM callbacks.
    if(!registerInstance())
    {
        // already failed?
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_START_CONSUME_REGISTER_INSTANCE_FAILED);
        DRM_close_file(hDRMFile);
        hDRMFile = -1;
        m_state = STATE_IDLE;
        m_signalRightExpired.emit(this, m_userData, DRM_RESULT_NO_MEMORY);
        return;
    }

    // start consuming rights
    m_jobId = DRM_consume_rights(hDRMFile, DRM_PERMISSION_DISPLAY, onRightExpired);
    DRM_close_file(hDRMFile);
    hDRMFile = -1;
    if(m_jobId > 0)
    {
        m_state = STATE_CONSUME;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_START_CONSUME_RIGHT_FAILED);
        // already failed?
        m_signalRightExpired.emit(this, m_userData, (drm_proc_enum)m_jobId);
        m_state = STATE_IDLE;
    }
#endif
}

void VappGalleryDRMConsumer::pauseConsume()
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_PAUSE_CONSUME);
    if(!m_shouldConsume)
    {
        return;
    }

    if(STATE_CONSUME == m_state)
    {
        DRM_pause_consume(m_jobId);
        m_state = STATE_PAUSED_CONSUME;
    }
#endif
}

void VappGalleryDRMConsumer::resumeConsume()
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_RESUME_CONSUME);
    if(!m_shouldConsume)
    {
        return;
    }

    // check right again before resume consumption
    // ...why?
    /*
    if(DRM_get_object_method(-1, m_filePath.getBuf()) != DRM_METHOD_NONE)
    {
        if(!DRM_validate_permission(-1, m_filePath.getBuf(), DRM_PERMISSION_DISPLAY))
        {
            img_info->drm_valid &= ~(MMI_IVEX_DRM_RET_DISPLAY_VALID);
        }
    }
    */

    switch(m_state)
    {
    case STATE_PAUSED_CONSUME:
        DRM_resume_consume(m_jobId);
        m_state = STATE_CONSUME;
        break;
    case STATE_IDLE:
        startConsume();
        break;
    case STATE_CONSUME:
        break;
    }
    return;
#endif
}

void VappGalleryDRMConsumer::handleRightExpired(kal_int32 result)
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_HANDLE_RIGHT_EXPIRED);
    // stop consumption
    stopConsume();
    // alert client
    m_signalRightExpired.emit(this, m_userData, (drm_proc_enum)result);
    // re-check if we should consume rights
    setFileAndUserData(m_filePath, m_userData);
#endif
}

void VappGalleryDRMConsumer::onRightExpired(kal_int32 result, kal_int32 id)
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_DRM_ON_RIGHT_EXPIRED);
    for(VfxS32 i = 0; i < MAX_CONSUMER_INSTANCE; ++i)
    {
        if(g_instances[i])
        {
            VappGalleryDRMConsumer *obj = static_cast<VappGalleryDRMConsumer*>(handleToObject(g_instances[i]));
            if(obj && obj->m_jobId == id)
            {
                obj->handleRightExpired(result);
            }
            return;
        }
    }
    // found no matching VappGalleryDRMConsumer instances, do nothing
#endif
}

/*****************************************************************************
 * Class Implementation of VappGalleryEnhancedImage
 *****************************************************************************/

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
VfxS32 VappGalleryEnhancedImage::getMaxImageFrameSize()
{
    const VfxS32 MAX_APP_ENHANCE_DIM = vfxMin(VFX_FRAME_MAX_WIDTH, VFX_FRAME_MAX_HEIGHT);
    return MAX_APP_ENHANCE_DIM;
}

VappGalleryEnhancedImage::VappGalleryEnhancedImage():
    m_mediaIndex(-1),
    m_rawBuf(NULL),
    m_bufLength(0),
    m_imgBuf()
{
}

void VappGalleryEnhancedImage::onInit()
{
    VfxObject::onInit();

    // allocate 9x LCD pixel buffer
    m_rawBuf = applib_asm_alloc_nc_r(
                        findRootAppId(this),
                        IMAGE_BUF_SIZE);
    VFX_ASSERT(m_rawBuf);
    m_bufLength = IMAGE_BUF_SIZE;
    m_imgBuf.ptr = (VfxU8*)m_rawBuf;
    m_imgBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
    m_imgBuf.width = 0;
    m_imgBuf.height = 0;
    m_imgBuf.pitchBytes = 0;
}

void VappGalleryEnhancedImage::onDeinit()
{
    // free 9x LCD pixel buffer
    if(m_rawBuf)
    {
        applib_asm_free_r(findRootAppId(this), m_rawBuf);
        m_rawBuf = NULL;
    }
    m_bufLength = 0;
    m_mediaIndex = -1;
    m_imgBuf.ptr = NULL;
    m_imgBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
    m_imgBuf.width = 0;
    m_imgBuf.height = 0;
    m_imgBuf.pitchBytes = 0;

    VfxObject::onDeinit();
}

VfxBool VappGalleryEnhancedImage::reset()
{
    m_mediaIndex = -1;
    m_imgBuf.width = 0;
    m_imgBuf.height = 0;
    m_imgBuf.pitchBytes = 0;
    return VFX_TRUE;
}

VfxBool VappGalleryEnhancedImage::isReadyToDecode(MediaIndex index)
{
    return (m_rawBuf && m_bufLength && index == m_mediaIndex && -1 != m_mediaIndex);
}

VfxBool VappGalleryEnhancedImage::isDecoding(MediaIndex index)
{
    if(-1 == m_mediaIndex ||
       -1 == index ||
       m_mediaIndex != index ||
       NULL == m_rawBuf)
    {
        return VFX_FALSE;
    }

    return m_isDecoding;
}

void VappGalleryEnhancedImage::finishDecode()
{
    if(-1 != m_mediaIndex &&
       NULL != m_rawBuf)
    {
        m_isDecoding = VFX_FALSE;
    }
}

VfxBool VappGalleryEnhancedImage::getOutputBuffer(VfxImageBuffer &outputBuf)
{
    if(-1 == m_mediaIndex ||
       m_mediaPath.isNull() ||
       m_mediaPath.isEmpty() ||
       m_isDecoding)
    {
        return VFX_FALSE;
    }

    if(0 == m_imgBuf.height * m_imgBuf.width)
    {
        return VFX_FALSE;
    }

    outputBuf = m_imgBuf;
    return VFX_TRUE;
}

VfxBool VappGalleryEnhancedImage::getEnhancedImageSize(
    const VfxWString &path,
    VfxSize &size,
    VfxU16 fileTypeHint,
    VfxSize originalDim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_ENHANCE_GET_MAX_ENHANCE_IMG_SIZE, fileTypeHint, originalDim.width, originalDim.height);

    // initial
    // TODO: should let decoder decide these restrictions?
    VfxS32 srcWidth = originalDim.width;
    VfxS32 srcHeight = originalDim.height;
    VfxU16 srcType = fileTypeHint;

    if(GDI_IMAGE_TYPE_INVALID == srcType)
    {
        GALLERY_MEASURE_TIME_START("Ggf");
        srcType = gdi_image_get_type_from_file(
                                        (CHAR*)path.getBuf());
        GALLERY_MEASURE_TIME_STOP("Ggf");
    }
    if(0 == srcWidth || 0 == srcHeight)
    {
        GALLERY_MEASURE_TIME_START("Ggd");
        GDI_RESULT gdiResult = gdi_imgdec_get_dimension_file(path.getBuf(), &srcWidth, &srcHeight);

        GALLERY_MEASURE_TIME_STOP("Ggd");
        if(GDI_SUCCEED != gdiResult)
            return VFX_FALSE;
    }

    if(srcWidth <= 0 || srcHeight <= 0 || GDI_IMAGE_TYPE_INVALID == srcType)
    {
        // no need to enhance
        return VFX_FALSE;
    }

    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    const VfxS32 maxPixelCount = m_bufLength / VAPP_GALLERY_IMG_VIEWER_BPP;
    #else
    const VfxS32 maxPixelCount = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO;
    #endif
    const VfxS32 srcPixelCount = srcWidth * srcHeight;

    VfxS32 enhanceWidth = srcWidth;
    VfxS32 enhanceHeight = srcHeight;
    if(srcPixelCount > maxPixelCount)
    {
        const VfxFloat scale = vfxSqrt(maxPixelCount * 1.0f / srcPixelCount);
        enhanceWidth = (VfxS32)(srcWidth * scale);
        enhanceHeight = (VfxS32)(srcHeight * scale);
    }

    /*Check GDI Limitation*/
    const VfxS32 maxDim = getMaxEnhanceDimensionByPath(path);
    if(0 == maxDim)
    {
        // no need to enhance
        return VFX_FALSE;
    }
    VfxS32 offsetX = 0, offsetY = 0;
    gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            maxDim,
            maxDim,
            enhanceWidth,
            enhanceHeight,
            &offsetX,           // ignore this
            &offsetY,           // ignore this
            &enhanceWidth,
            &enhanceHeight);

    enhanceWidth = vfxMax(1, enhanceWidth);
    enhanceHeight = vfxMax(1, enhanceHeight);

    size.height = enhanceHeight;
    size.width = enhanceWidth;

    return VFX_TRUE;
}

VfxBool VappGalleryEnhancedImage::setFileAndGetOutputBuffer(
    MediaIndex mediaIdx,
    const VfxWString &path,
    VfxImageBuffer &outputBuf,
    VfxSize bufferSizeHint)
{
    // check input
    if(-1 == mediaIdx)
        return VFX_FALSE;

    // check self-consistency
    if(NULL == m_rawBuf || 0 >= m_bufLength)
        return VFX_FALSE;

    VfxSize enhanceSize;
    if(!getEnhancedImageSize(path, enhanceSize))
    {
        return VFX_FALSE;
    }

    // setup image buffer
    m_imgBuf.ptr = (VfxU8*)m_rawBuf;
    m_imgBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    m_imgBuf.width = enhanceSize.width;
    m_imgBuf.height = enhanceSize.height;
    m_imgBuf.pitchBytes = enhanceSize.width * VAPP_GALLERY_IMG_VIEWER_BPP;
#else
    if(0 == bufferSizeHint.width || 0 == bufferSizeHint.height)
    {
        m_imgBuf.width = GDI_LCD_WIDTH;
        m_imgBuf.height = GDI_LCD_HEIGHT;
    }
    else
    {
        m_imgBuf.width = bufferSizeHint.width;
        m_imgBuf.height = bufferSizeHint.height;
    }
    m_imgBuf.pitchBytes = (m_imgBuf.width) * VAPP_GALLERY_IMG_VIEWER_BPP;
#endif

    outputBuf = m_imgBuf;

    // enter decoding state
    m_mediaIndex = mediaIdx;
    m_mediaPath = path;
    m_isDecoding = VFX_TRUE;
    return VFX_TRUE;
}

VfxS32 VappGalleryEnhancedImage::getMaxEnhanceDimensionByPath(const VfxWString &path, VfxU16 fileTypeHint)
{
    VfxU16 srcType = fileTypeHint;
    if(GDI_IMAGE_TYPE_INVALID == srcType)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_ENHANCE_GET_MAX_ENHANCE_DIM_BY_PATH, fileTypeHint);
        GALLERY_MEASURE_TIME_START("Ggf");
        const VfxU16 srcType = gdi_image_get_type_from_file((CHAR*)path.getBuf());
        GALLERY_MEASURE_TIME_STOP("Ggf");
    }

    // GIF special case: do not enhace if the GIF file is animated image.
    switch(srcType)
    {
    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
    case GDI_IMAGE_TYPE_GIF:
    case GDI_IMAGE_TYPE_GIF_FILE:
        if(VappImageViewerComponent::isAnimatedImage(path))
        {
            return 0;
        }
    }
    return getMaxEnhanceDimensionByType(srcType);
}

VfxS32 VappGalleryEnhancedImage::getMaxEnhanceDimensionByType(VfxU16 gdiImageType)
{
    switch(gdiImageType)
    {
    // GDI images are not allowed to resize/zoom/enhance
    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
    case GDI_IMAGE_TYPE_GIF:
    case GDI_IMAGE_TYPE_GIF_FILE:
    case GDI_IMAGE_TYPE_BMP:
    case GDI_IMAGE_TYPE_BMP_SEQUENCE:
    case GDI_IMAGE_TYPE_BMP_FILE:
    case GDI_IMAGE_TYPE_WBMP_FILE:
    case GDI_IMAGE_TYPE_WBMP:
        return GDI_MAX_RESIZE_WIDTH;
    default:
        return getMaxImageFrameSize();
    }
}
#endif
/*****************************************************************************
* Class Implementation of VappGalleryInertiaPan
*****************************************************************************/

VappGalleryInertiaPan::VappGalleryInertiaPan():
    m_lastOffsetX(0),
    m_lastOffsetY(0),
    m_lastTimeDiff(0)
{

}

void VappGalleryInertiaPan::processPenEvent(const VfxPenEvent &e)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        m_lastOffsetX = 0;
        m_lastOffsetY = 0;
        m_lastTimeDiff = 0;
        return;
    }

    const VfxS32 xOffset = (e.pos.x - e.prevPos.x);
    const VfxS32 yOffset = (e.pos.y - e.prevPos.y);

    // note: for UP event, Capacity touch does NOT have prediction,
    // so offset will be 0.
    if(VFX_PEN_EVENT_TYPE_MOVE == e.type ||
       (VFX_PEN_EVENT_TYPE_UP == e.type && (xOffset != 0 || yOffset != 0)))
    {
        m_lastOffsetX = xOffset;
        m_lastOffsetY = yOffset;
        m_lastTimeDiff = e.timeStamp - e.prevTimeStamp;
    }
}

VfxBool VappGalleryInertiaPan::getInertiaPan(VfxS32 &offsetX, VfxS32 &offsetY)
{
    if(0 == m_lastTimeDiff)
    {
        return VFX_FALSE;
    }

    // we assuem that the remaining movement distance
    // is linearly decay the speed, so,
    // distance = (time * speed) / 2

    // lastMoveDistance * PRECISION_FACTOR * animationDuration / lastMoveTime / PRECISION_FACTOR / 2,
    offsetX = ((m_lastOffsetX << 10) * INERTIA_ANIM_TIME / m_lastTimeDiff) >> 11;
    offsetY = ((m_lastOffsetY << 10) * INERTIA_ANIM_TIME / m_lastTimeDiff) >> 11;
    return VFX_TRUE;
}

#endif // #ifdef __MMI_FTO_GALLERY__
