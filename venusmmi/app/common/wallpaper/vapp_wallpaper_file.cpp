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
 *  vapp_wallpaper_file.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Wallpaper that requries external file to work
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)

#include "vapp_wallpaper_file.h"
#include "vapp_wallpaper_cfg.h"
#include "mmi_rp_app_venus_wallpaper_frame_video_def.h"
extern "C"
{
#include "MMI_trc.h"
#include "vapp_wallpaper_video_decoder.h"
#include "FileMgrSrvGProt.h"
#include "cache_sw.h"
#include "custom_scatstruct.h"   
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
#include "gdi_const.h"
#include "gdi_layer.h"
#include "gdi_include.h"
#include "gdi_linear_transform.h"
#include "Unicodexdcl.h"
#include "med_utility.h"
}
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_usb_gprot.h"
#endif

/*****************************************************************************
 * Macro
 *****************************************************************************/
 #define CHECK_AND_BREAK(_statment)  if(VAPP_WP_DEC_STATUS_OK != _statment)\
                                {\
                                    break;\
                                }

/*****************************************************************************
 * Functions
 *****************************************************************************/
static void *working_mem_malloc_frame_buf(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr;

    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;

#ifdef __COSMOS_MMI_PACKAGE__
    buffer_ptr = applib_asm_alloc_anonymous_nc(total_bytes);
    ASSERT(buffer_ptr != NULL);
#else
    buffer_ptr = med_alloc_ext_mem(total_bytes);
#endif

    return buffer_ptr;
}

static void *working_mem_malloc(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr;

    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;

#ifdef __COSMOS_MMI_PACKAGE__
    buffer_ptr = applib_asm_alloc_anonymous(total_bytes);
    ASSERT(buffer_ptr != NULL);
#else
    buffer_ptr = med_alloc_ext_mem_cacheable(total_bytes);
#endif

    return buffer_ptr;
}

static void working_mem_free(void *opaque, void *address)
{
#ifdef __COSMOS_MMI_PACKAGE__
    applib_asm_free_anonymous(address);
#else
    med_free_ext_mem((void**)&address);
#endif

   return;
}

static U8* _ensure_non_cachable_address(U8* mem_addr)
{
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    U8* physicalAddr = (U8*)virt_to_phys(mem_addr);  // in 11A, use MAP2CREGPA instead.
    return physicalAddr;
#else
    return mem_addr;
#endif
}

static VfxU32 getBPP(VfxColorTypeEnum vrtCF)
{
    switch(vrtCF)
    {
        case VRT_COLOR_TYPE_RGB565:
            return 2;
        case VRT_COLOR_TYPE_RGB888:
            return 3;
        case VRT_COLOR_TYPE_PARGB8888:
            return 4;
        case VRT_COLOR_TYPE_ARGB8888:
            return 4;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return 2;
    }
}

static gdi_color_format getCF(VfxColorTypeEnum vrtCF)
{
    switch(vrtCF)
    {
        case VRT_COLOR_TYPE_RGB565:
            return GDI_COLOR_FORMAT_16;
        case VRT_COLOR_TYPE_RGB888:
            return GDI_COLOR_FORMAT_24;
        case VRT_COLOR_TYPE_ARGB8888:
            return GDI_COLOR_FORMAT_32;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return GDI_COLOR_FORMAT_END;
    }
}


static gdi_handle _convertImageBufferToLayer(const VfxImageBuffer &imgBuf, VfxBool clearCache = VFX_FALSE, VfxS32 overrideSize = 0)
{
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;

    // GDI layer only support zero-padded pitch
    VFX_ASSERT(imgBuf.pitchBytes == imgBuf.width * getBPP(imgBuf.colorFormat));
    res = gdi_layer_create_cf_using_outside_memory(getCF(imgBuf.colorFormat), 
                                                   0, 0, 
                                                   imgBuf.width, 
                                                   imgBuf.height, 
                                                   &thumbLayer,
                                                   _ensure_non_cachable_address(imgBuf.ptr), 
                                                   overrideSize ? overrideSize : (imgBuf.pitchBytes * imgBuf.height));
    VFX_ASSERT(GDI_SUCCEED == res);
    return thumbLayer;
}

VfxBool VappWallpaperFileBase::checkFile(const VfxWString &filePath)
{
    #if defined(__MMI_USB_SUPPORT__)
    if(srv_usb_is_in_mass_storage_mode_ext())
    {
        return VFX_FALSE;
    }
    #endif

    const int decType = wallpaperDecGetTypeFromFileName((WCHAR*)filePath.getBuf());
    if(-1 == decType)
    {
        return VFX_FALSE;
    }
    wallpaperDecSetType(decType);

    VAPP_WP_DECODER_HANDLE *pDecoder = NULL;
    VAPP_WP_DEC_STATUS status = VAPP_WP_DEC_STATUS_OK;
    STFSAL fsal;
    kal_mem_set(&fsal, 0, sizeof(fsal));
    do
    {
        if(FSAL_Open(&fsal, (void *)(filePath.getBuf()), FSAL_READ) != FSAL_OK)
        {
            status = VAPP_WP_DEC_STATUS_NG;
            break;
        }

        VfxU32                  frameCnt = 0;                     
        VfxU32                  frameWidth = 0;                   
        VfxU32                  frameHeight = 0;                  
        
        CHECK_AND_BREAK(wallpaperDecGetHandle(&pDecoder));
        CHECK_AND_BREAK(wallpaperDecSetAllocAndFree(pDecoder, working_mem_malloc, working_mem_free));
        CHECK_AND_BREAK(wallpaperDecSetSrcFile(pDecoder, &fsal));
        CHECK_AND_BREAK(wallpaperDecQuerySrcResolution(pDecoder, &frameWidth, &frameHeight));
        CHECK_AND_BREAK(wallpaperDecQueryFrameCount(pDecoder, &frameCnt));

        if(frameWidth != LCD_WIDTH || frameHeight != LCD_HEIGHT)
        {
            // resolution does not match
            status = VAPP_WP_DEC_STATUS_NG;
            break;
        }
    }while(0);

    if(pDecoder)
    {
        wallpaperDecReleaseHandle(&pDecoder);
    }
    FSAL_Close(&fsal);

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_FILE_VAPP_WALLPAPER_FILE_BASE_CHECK_FILE_STATUS_D, status);
    return status == VAPP_WP_DEC_STATUS_OK;
}


VfxBool VappWallpaperFileBase::decodeFileThumb(const VfxWString &filePath, VfxImageBuffer &outputThumbBuffer)
{
    int decType = wallpaperDecGetTypeFromFileName((WCHAR*)filePath.getBuf());
    if(-1 == decType)
    {
        return VFX_FALSE;
    }

    STFSAL fsal = {0};
    if(FSAL_OK != FSAL_Open(&fsal, (void *)(filePath.getBuf()), FSAL_READ))
    {
        return VFX_FALSE;
    }
    const VfxBool useABM = decType;
    VfxBool decodeResult = decodeFileThumbByFSAL(useABM, fsal, outputThumbBuffer);
    FSAL_Close(&fsal);
    return decodeResult;
}

VfxBool VappWallpaperFileBase::decodeFileThumbByHandle(VfxBool useABM, FS_HANDLE hFile, VfxImageBuffer &outputThumbBuffer)
{
    STFSAL fsal = {0};
    if(FSAL_OK != FSAL_Open_WithHandle(&fsal, (void*)hFile))
    {
        return VFX_FALSE;
    }
    // FSAL_Open_WithHandle needs not (and cannot) call FSAL_Close().
    return decodeFileThumbByFSAL(useABM, fsal, outputThumbBuffer);
}

VfxBool VappWallpaperFileBase::decodeFileThumbByFSAL(VfxBool useABM, STFSAL fsal, VfxImageBuffer &outputThumbBuffer)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("WDT", SA_start);
#endif
    wallpaperDecSetType(useABM ? 1 : 0);

    VAPP_WP_DECODER_HANDLE *pDecoder = NULL;
    VAPP_WP_DEC_STATUS status = VAPP_WP_DEC_STATUS_NG;
    VfxU8 *srcBuf = NULL;
    VfxU8 *dstBuf = NULL;
    gdi_handle dstLayer = GDI_NULL_HANDLE;
    gdi_handle thumbLayer = GDI_NULL_HANDLE;
    do
    {
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("WDO", SA_start);
        #endif
        VfxU32                  frameHeaderLen = 0;               
        VfxU32                  frameCnt = 0;                     
        const VfxS32            bpp = 2;                          
        VfxU32                  frameWidth = 0;                   
        VfxU32                  frameHeight = 0;                  
        VAPP_WP_COLOR_FORMAT srcFormat = VAPP_WP_RGB565;
        

        CHECK_AND_BREAK(wallpaperDecGetHandle(&pDecoder));
        CHECK_AND_BREAK(wallpaperDecSetAllocAndFree(pDecoder, working_mem_malloc, working_mem_free));
        CHECK_AND_BREAK(wallpaperDecSetSrcFile(pDecoder, &fsal));
        CHECK_AND_BREAK(wallpaperDecQuerySrcResolution(pDecoder, &frameWidth, &frameHeight));
        CHECK_AND_BREAK(wallpaperDecSetDstFormat(pDecoder, VAPP_WP_RGB565));
        CHECK_AND_BREAK(wallpaperDecQuerySrcFormat(pDecoder, &srcFormat));
        CHECK_AND_BREAK(wallpaperDecQueryFrameCount(pDecoder, &frameCnt));
        CHECK_AND_BREAK(wallpaperDecQueryFrameHeaderLength(pDecoder, &frameHeaderLen));

        VfxU32 srcBufSize = 0;
        const VfxU32 thumbFrameIdx = 0;
        status = wallpaperDecQuerySrcFrameBufSize(pDecoder, thumbFrameIdx, &srcBufSize);
        if(frameWidth != LCD_WIDTH || frameHeight != LCD_HEIGHT)
        {
            // resolution does not match
            status = VAPP_WP_DEC_STATUS_NG;
            break;
        }

        const VfxU32 dstBufSize = (LCD_WIDTH * LCD_HEIGHT * bpp + frameHeaderLen + 31) / 32 * 32;
        srcBuf = (VfxU8*)working_mem_malloc(NULL, 1, srcBufSize);
        dstBuf = (VfxU8*)working_mem_malloc_frame_buf(NULL, 1, dstBufSize);
        VfxU32 readSize = 0;
        status = wallpaperDecGetFrameSrcBuf(
                    pDecoder,
                    VAPP_WP_READ_FILE_SYNC,
                    thumbFrameIdx,
                    srcBuf,
                    srcBufSize,
                    &readSize,
                    NULL,
                    NULL);
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("WDO", SA_start);
        #endif
        CHECK_AND_BREAK(status);
        status = wallpaperDecGetFramePixelData(
                    pDecoder,
                    srcBuf,
                    srcBufSize,
                    dstBuf,
                    dstBufSize);
        CHECK_AND_BREAK(status);

        // resize
        VfxImageBuffer dstImg;        
        dstImg.colorFormat = VRT_COLOR_TYPE_RGB565;
        dstImg.ptr = dstBuf;
        dstImg.width = LCD_WIDTH;
        dstImg.height = LCD_HEIGHT;
        dstImg.pitchBytes = LCD_WIDTH * bpp;

        VfxImageBuffer &thumbImg = outputThumbBuffer;
        dstLayer = _convertImageBufferToLayer(dstImg, VFX_FALSE, dstBufSize);
        thumbLayer = _convertImageBufferToLayer(thumbImg, VFX_FALSE);

        VfxS32 l = 0;
        VfxS32 t = 0;
        VfxS32 fitWidth = 0;
        VfxS32 fitHeight = 0;
        gdi_util_fit_box(
            GDI_UTIL_MODE_SHORT_SIDE_FIT,
            outputThumbBuffer.width,
            outputThumbBuffer.height,
            LCD_WIDTH, 
            LCD_HEIGHT,
            &l,
            &t,
            &fitWidth,
            &fitHeight);

        /* disable source key to speed up */
        gdi_layer_push_and_set_active(dstLayer);
        gdi_layer_set_source_key(VRT_FALSE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();

        /* prevent output source key color */
        gdi_layer_push_and_set_active(thumbLayer);
        gdi_layer_set_source_key(VRT_TRUE, GDI_COLOR_TRANSPARENT);
        if(dstImg.colorFormat == thumbImg.colorFormat)
        {
            gdi_bitblt_resized_with_resizer(
                    dstLayer,
                    0,
                    0,
                    LCD_WIDTH - 1,
                    LCD_HEIGHT - 1,
                    l,
                    t,
                    l + fitWidth - 1,
                    t + fitHeight - 1,
                    GDI_RESIZER_SW_QUALITY_HIGH);
        }
        else
        {
            VfxMatrix3x3Ex m;
            m.setTranslation(l, t);
            VfxMatrix3x3Ex s;
            s.setScale(fitWidth * 1.0f / (LCD_WIDTH - 1),
                       fitHeight * 1.0f / (LCD_HEIGHT - 1));

            m = s * m;
            m.transpose();
            gdi_lt_matrix_struct gdi_matrix;
            kal_mem_cpy(&gdi_matrix.m[0], &m.m[0], sizeof(gdi_matrix.m));
            gdi_lt_projective_transform_ext(
                            &gdi_matrix,
                            dstLayer,
                            0,
                            0,
                            LCD_WIDTH - 1,
                            LCD_HEIGHT - 1,
                            0,
                            0,
                            outputThumbBuffer.width,
                            outputThumbBuffer.height,
                            GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                            GDI_COLOR_TRANSPARENT,
                            GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
                            0);
        }
        gdi_layer_pop_and_restore_active();
        
#if 0
/* under construction !*/
/* under construction !*/
#endif
    }while(0);

    if(dstLayer)
    {
        gdi_layer_free(dstLayer);
        dstLayer = GDI_NULL_HANDLE;
    }
    if(thumbLayer)
    {
        gdi_layer_free(thumbLayer);
        thumbLayer = GDI_NULL_HANDLE;
    }
    if(srcBuf)
    {
        working_mem_free(NULL, srcBuf);
        srcBuf = NULL;
    }
    if(dstBuf)
    {
        working_mem_free(NULL, dstBuf);
        dstBuf = NULL;
    }
    if(pDecoder)
    {
        wallpaperDecReleaseHandle(&pDecoder);
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("WDT", SA_stop);
#endif

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_FILE_VAPP_WALLPAPER_FILE_BASE_DECODE_FILE_THUMB_BY_FSAL_STATUS_D, status);
    return (VAPP_WP_DEC_STATUS_OK == status);
}

VfxBool VappWallpaperFileBase::isFileExist(const WCHAR *filePath)
{
    FS_HANDLE handle;
    handle = FS_Open(filePath, FS_READ_ONLY);
    if(handle > 0)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappWallpaperFileBase::checkUSBMSMode()
{
#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    if(srv_usb_is_in_mass_storage_mode_ext())
    {
        vapp_usb_unavailable_popup(SRV_USB_ERROR_UNAVAILABLE);
        return VFX_TRUE;
    }
#endif
    return VFX_FALSE;
}

VfxBool VappWallpaperFileBase::isFileusable(const WCHAR *filePath)
{
    if(isFileExist(filePath))
    {
        if(checkUSBMSMode())
            return VFX_FALSE;
        else
            return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}
#endif /* defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__) */
