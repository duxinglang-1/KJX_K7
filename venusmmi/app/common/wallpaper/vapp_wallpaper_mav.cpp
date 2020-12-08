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
 *  vapp_wallpaper_mav.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen frame fast video wallpaper class
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_mav.h"
//#include "HomeScreen/vadp_v2p_hs.h"

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
#include "vadp_asm.h"
#include "vapp_wallpaper_file.h"
#include "vapp_mav_motion_translator.h"

/* RHR end */
#include "vapp_wallpaper_setting_provider.h"

extern "C"
{
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif
// for reg gpio event
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "gdi_primitive.h"
#include "gdi_imgdec.h"
#include "FileMgrSrvGProt.h"
#include "App_mem_med.h"
}

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_usb_gprot.h"
#else
extern "C"
{
#include "SettingGprots.h"
#include "PhoneSetupGprots.h"
}
#endif

#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#if defined(__MTK_TARGET__) && defined(__MAUI_SOFTWARE_LA__)
extern "C"
{
#include "SST_sla.h"
}
#endif

static VfxBool isFileExist(const WCHAR *filePath)
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

static VfxBool checkUSBMSMode()
{
#if defined(__MMI_USB_SUPPORT__)
    if(srv_usb_is_in_mass_storage_mode_ext())
    {
        #if defined(__COSMOS_MMI_PACKAGE__)
        vapp_usb_unavailable_popup(SRV_USB_ERROR_UNAVAILABLE);
        #endif
        return VFX_TRUE;
    }
#endif
    return VFX_FALSE;
}

static VfxBool isFileusable(const WCHAR *filePath)
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

#include "vapp_wallpaper_file.h"

/*****************************************************************************
 * Home screen UI componet: frame video wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("MAV Wallpaper", VappWallpaperMAV, VappWallpaper);

VappWallpaperMAV::VappWallpaperMAV() :
    m_asmGroupId(0)
    ,m_draw(NULL)
    ,m_timeline(NULL)
    ,m_isFileValid(VFX_FALSE)
    ,m_fallbackImgId(0)
    ,m_fallbackWallpaper(NULL)
#ifdef __VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__
    ,m_sensor(NULL)
#endif
{
    kal_mem_set(&m_sourceFileName[0], 0, sizeof(m_sourceFileName));
}

void VappWallpaperMAV::onSerializeView()
{
    onReleaseView();
}

void VappWallpaperMAV::onRestoreView()
{
    onCreateView();
}

void VappWallpaperMAV::onCreateView()
{
    setSize(LCD_WIDTH, LCD_HEIGHT);
    setBgColor(VFX_COLOR_TRANSPARENT);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    m_isFileValid = VFX_FALSE;

    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappWallpaperId fallbackWallpaperId;
    setting->getFallbackWallpaperId(fallbackWallpaperId, VFX_TRUE);
    if(VAPP_WALLPAPER_FACTORY_IMAGE == fallbackWallpaperId.getSource())
    {
        m_fallbackImgId = fallbackWallpaperId.getIntType();
    }

    VFX_OBJ_CREATE(m_fallbackWallpaper, VfxFrame, this);
    m_fallbackWallpaper->setPos(0, 0);
    m_fallbackWallpaper->setSize(getSize());
    m_fallbackWallpaper->setImgContent(VfxImageSrc());
    m_fallbackWallpaper->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    if(initASMScreenGroup() && isFileusable(m_sourceFileName))
    {
        VFX_OBJ_CREATE_EX(m_draw, VappMAVDraw, this, (m_asmGroupId));
        m_draw->setFallbackImgId(m_fallbackImgId);
        checkPlay();
        registerEvents(VFX_TRUE);
    }
    else
    {
        // no memory, use fallback image
        m_fallbackWallpaper->setImgContent(VfxImageSrc(m_fallbackImgId));
        restoreWallpaperSetting();
    }

    trySetupMotionSensor();
}

void VappWallpaperMAV::onReleaseView()
{
    teardownMotionSensor();
    setOwnerDraw(NULL);
    setPropertyEffectCallback(this, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

    VFX_OBJ_CLOSE(m_draw);
    VFX_OBJ_CLOSE(m_fallbackWallpaper);
    VFX_OBJ_CLOSE(m_timeline);

    registerEvents(VFX_FALSE);

    deinitASMScreenGroup();
}

VfxBool VappWallpaperMAV::getThumbnailImage(VfxImageBuffer &output)
{
    VfxWString path((VfxWChar*)m_sourceFileName);
    return VappWallpaperFileBase::decodeFileThumb(path, output);
}

void VappWallpaperMAV::getName(VfxWString &wallpaperName)
{
    wallpaperName.setEmpty();
}

void VappWallpaperMAV::setSourceFile(WCHAR *srcFile)
{
    if(srcFile)
    {
        mmi_wcscpy(m_sourceFileName, srcFile);
    }
    else
    {
        kal_mem_set(&m_sourceFileName[0], 0, sizeof(m_sourceFileName));
    }
}

VfxBool VappWallpaperMAV::onAllowSuspendOnSwipe()
{
    return VFX_TRUE;
}

VfxBool VappWallpaperMAV::onAllowSuspendOnPenDown()
{
    // if it is interactive wallpaper, the desktop transition still need to update content
    return VFX_TRUE;
}

void VappWallpaperMAV::onSuspend()
{
    teardownMotionSensor();
    if(m_timeline)
    {
        m_timeline->stop();
    }
    if(m_draw)
    {
        m_draw->m_isSuspend = VFX_TRUE;
    }
}

void VappWallpaperMAV::onResume()
{
    trySetupMotionSensor();
    if(m_draw)
    {
        m_draw->m_isSuspend = VFX_FALSE;
    }
    invalidate();
}

VfxBool VappWallpaperMAV::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            return VFX_TRUE;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            return VFX_TRUE;
        }
    }
    return VFX_TRUE;

}

void VappWallpaperMAV::onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos)
{
#if defined(__VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__) && defined(__MTK_TARGET__) 
    // has sensor, do nothing since sensor event will trigger update.
    if(m_sensor)
    {
        return;
    }
#endif
    if(NULL == m_draw)
    {
        return;
    }
    // No motion sensor or disabled, 
    // use desktop change event to display animation.
    const VfxS32 totalPage = getTotalPage();
    m_draw->m_totalPage = totalPage;
    if(totalPage <= 1)
    {
        // only 1 page, we cannot do animation.
        return;
    }

    #if 1 // spread type
    if(m_timeline)
    {
        // spread -1.0 ~ 1.0 evenly between pages
        m_timeline->setToValue(curPos * 2.0f - 1.0f);
    }
    #else   // trigger type
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
    #endif
    invalidate();
}

void VappWallpaperMAV::checkPlay(void)
{
    VfxBool currntFileStatus = isFileusable(m_sourceFileName);

    if(m_isFileValid)
    {
        if(currntFileStatus)
        {
            ;
        }
        else
        {
            m_fallbackWallpaper->setImgContent(VfxImageSrc(m_fallbackImgId));
            setOwnerDraw(NULL);
            setPropertyEffectCallback(this, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
            if(m_draw)
            {
                m_draw->destoryFileInfo();
            }
        }
    }
    else
    {
        if(currntFileStatus)
        {
            m_fallbackWallpaper->setImgContent(VfxImageSrc());

            setOwnerDraw(m_draw);
            VfxObjHandle hDraw = m_draw->getObjHandle();
            setPropertyEffectCallback(this, m_draw->onUpdate, &hDraw, sizeof(hDraw), VRT_FPE_TRIGGER_TYPE_DIRTY);

            m_draw->setFileSrc(m_sourceFileName);
            if(!m_draw->createFileInfo())
            {
                setPropertyEffectCallback(this, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

                m_fallbackWallpaper->setImgContent(VfxImageSrc(m_fallbackImgId));

                currntFileStatus = VFX_FALSE;
            }
            else
            {
                // display center frame
                setPosZ(m_draw->m_frameCnt / 2);
            }
        }
        else
        {
            setOwnerDraw(NULL);
            setPropertyEffectCallback(this, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

            m_fallbackWallpaper->setImgContent(VfxImageSrc(m_fallbackImgId));
            m_fallbackWallpaper->bringToFront();
        }
    }
    m_isFileValid = currntFileStatus;

}

mmi_ret VappWallpaperMAV::handleEvent(mmi_event_struct *param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            if(!isFileExist(m_sourceFileName))
            {
                restoreWallpaperSetting(NULL);
                m_draw->m_errorCode = 4001;
                m_fallbackWallpaper->setImgContent(VfxImageSrc(m_fallbackImgId));
                setOwnerDraw(NULL);
                setPropertyEffectCallback(this, NULL, NULL, NULL, VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);
                if(m_draw)
                {
                    m_draw->destoryFileInfo();
                }            
            }
            break;

    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
            checkPlay();
            break;
    #endif // #ifdef __MMI_USB_SUPPORT__

    }
    return MMI_RET_OK;
}

VfxBool VappWallpaperMAV::checkResource()
{
    return VappWallpaperFileBase::checkFile(VFX_WSTR_MEM((WCHAR*)m_sourceFileName));
}

void * VappWallpaperMAV::mem_alloc(mmi_id asmGroup, unsigned int items, unsigned int size)
{
    unsigned int total_bytes = items * size;
    void *buffer_ptr = NULL;
    
#ifdef __COSMOS_MMI_PACKAGE__
    buffer_ptr = applib_asm_alloc_nc_r(asmGroup, total_bytes);
#else
    buffer_ptr = med_alloc_ext_mem(total_bytes);
#endif
    ASSERT(buffer_ptr != NULL);
    return buffer_ptr;
}

void VappWallpaperMAV::mem_free(mmi_id asmGroup, void *address)
{
#ifdef __COSMOS_MMI_PACKAGE__
    applib_asm_free_r(asmGroup, address);
#else
    med_free_ext_mem((void**)&address);
#endif
   return;
}

VfxBool VappWallpaperMAV::initASMScreenGroup()
{
#ifdef __COSMOS_MMI_PACKAGE__
    if(GRP_ID_INVALID != m_asmGroupId)
    {
        // already initialized
        return VFX_TRUE;
    }

    const MMI_ID gid = APP_VENUS_WALLPAPER_MAV;

    // check if the group is already created.
    // if so, treat as create fail.
    mmi_group_node_struct node_info;
    if(MMI_RET_OK == mmi_frm_group_get_info (gid, &node_info))
    {
        // already created, fail,
        // since we don't want to mess with existing wallpaper instance.
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_VAPP_WALLPAPER_MAV_INIT_ASMSCREEN_GROUP_FAIL_DUE_TO_ALREADY_CREATED);
        return VFX_FALSE;
    }
    
    VadpAsmProperty p;
    m_asmGroupId = mmi_frm_group_create(GRP_ID_ROOT,
                                      gid,
                                      &onScreenGroupEvent,
                                      getObjHandle());
    if(GRP_ID_INVALID != m_asmGroupId)
    {
        U32 size = mmi_res_get_app_base_mem_size(APP_VENUS_WALLPAPER_MAV) + 
                   mmi_res_get_app_fg_mem_size(APP_VENUS_WALLPAPER_MAV);
        if (mmi_frm_asm_check_enough(m_asmGroupId, size) == MMI_FALSE)
        {
            mmi_frm_group_close(m_asmGroupId);
            m_asmGroupId = GRP_ID_INVALID;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_VAPP_WALLPAPER_MAV_INIT_ASMSCREEN_GROUP_FAIL_MMI_FRM_ASM_CHECK_ENOUGH);
            return VFX_FALSE;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_VAPP_WALLPAPER_MAV_INIT_ASMSCREEN_GROUP_CREATES_GROUP_D, m_asmGroupId);
        VadpAsm::getProperty(m_asmGroupId, p);
        p.f_prepare_w_reserve = 0;
        p.f_hide_in_oom = 0;
        VadpAsm::setProperty(m_asmGroupId, p);
        return VFX_TRUE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_VAPP_WALLPAPER_MAV_INIT_ASMSCREEN_GROUP_FAILED);
        return VFX_FALSE;
    }
#endif
    return VFX_TRUE;
}

void VappWallpaperMAV::deinitASMScreenGroup()
{
#ifdef __COSMOS_MMI_PACKAGE__
    // since video CP depends on group id,
    // make sure it is destroyed.
    if(m_asmGroupId)
    {
        setOwnerDraw(NULL);
        VFX_OBJ_CLOSE(m_draw);
        VFX_OBJ_CLOSE(m_timeline);
        VFX_ASSERT(0 == applib_mem_ap_get_single_usage(m_asmGroupId));
        mmi_frm_group_close(m_asmGroupId);
        m_asmGroupId = NULL;
    }
#endif
}

mmi_ret VappWallpaperMAV::onScreenGroupEvent(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        // keep dangle group
        return MMI_RET_ERR;
    case EVT_ID_ASM_FREE_REQ:   // volunteer free
    case EVT_ID_ASM_FREE_REQ_NO_WAIT: // volunteer free
    case EVT_ID_ASM_FORCE_FREE: // force free
        {
            VappWallpaperMAV *pThis = (VappWallpaperMAV*)VfxObject::handleToObject(evt->user_data);
            if(pThis)
            {
                pThis->onReleaseView();
                // pThis->m_fallbackWallpaper->setImgContent(VfxImageSrc(pThis->m_fallbackImgId));
            }
        }
        return MMI_FRM_ASM_FREED;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * Class VappMAVDraw
 *****************************************************************************/
VappMAVDraw::VappMAVDraw(mmi_id asmGroupId) : 
    m_isSuspend(VFX_FALSE)
    ,m_asmGroupId(asmGroupId)
    ,m_framePtr(0)
    ,m_errorCode(0)
    ,m_bpp(2)
    ,m_cf(VRT_COLOR_TYPE_RGB565)
    ,m_totalPage(1)
    ,m_fallbackImgId(0)
{
}

void VappMAVDraw::onInit()
{
    VfxOwnerDraw::onInit();
    
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (24 == MAIN_MEDIA_LAYER_BITS_PER_PIXEL)
    const VfxU32 BPP = 3;
#else
    const VfxU32 BPP = 2;
#endif
    m_contentBuffer = (VfxU8*)VappWallpaperMAV::mem_alloc(m_asmGroupId, 1, LCD_WIDTH*LCD_HEIGHT*BPP);
    ASSERT(m_contentBuffer != NULL);
    m_isErrorHappended = VFX_FALSE;
}


void VappMAVDraw::onDeinit()
{
    VappWallpaperMAV::mem_free(m_asmGroupId, m_contentBuffer);
    VfxOwnerDraw::onDeinit();
}

void VappMAVDraw::setFileSrc(WCHAR* src)
{
    mmi_wcscpy(m_sourceFileName, src);
    const int decType = wallpaperDecGetTypeFromFileName(src);
    if(-1 != decType)
    {
        wallpaperDecSetType(decType);
    }
}

void VappMAVDraw::setFallbackImgId(VfxResId imgId)
{
    m_fallbackImgId = imgId;
}


static void fitImage(const VfxSize &originalDim, 
                     VfxS32 &offsetX,
                     VfxS32 &offsetY,
                     VfxS32 &targetW,
                     VfxS32 &targetH,
                     VfxBool &mustClearBlack)
{
    const VfxSize outputDim(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    offsetX = 0;
    offsetY = 0;
    targetW = 2;
    targetH = 2;

    // decide crop region
    const VfxS32 &originalW = originalDim.width;
    const VfxS32 &originalH = originalDim.height;
    mustClearBlack = VFX_TRUE;

    //if(originalW <= outputDim.width ||
    //   originalH <= outputDim.height)
    if(0)
    {
        mustClearBlack = VFX_TRUE;
        const VfxS32 layer_w = outputDim.width;
        const VfxS32 layer_h = outputDim.height;
        
        if (originalW > layer_w && originalH > layer_h)
        {
            const VfxS32 v_rate = originalH * 1000 / layer_h;
            const VfxS32 h_rate = originalW * 1000 / layer_w;

            if (v_rate < h_rate)
            {
                targetH = layer_h;
                targetW = layer_h * originalW / originalH;
            }
            else
            {
                targetW = layer_w;
                targetH = layer_w * originalH / originalW;
            }
        }
        else
        {
            targetW = originalW;
            targetH = originalH;
        }
        if (targetW > layer_w)
        {
            offsetX -= (targetW - layer_w)/2;
        }
        else
        {
            offsetX += (layer_w - targetW)/2;
        }
        if (targetH > layer_h)
        {
            offsetY -= (targetH - layer_h)/3;
        }
        else
        {
            offsetY += (layer_h - targetH)/2;
        }
    }
    else
    {
        mustClearBlack = VFX_FALSE;
        // this only works when original > target
        gdi_util_fit_box(
                        GDI_UTIL_MODE_SHORT_SIDE_FIT,
                        outputDim.width,
                        outputDim.height,
                        originalW,
                        originalH,
                        &offsetX,
                        &offsetY,
                        &targetW,
                        &targetH
                        );
    }
    
    targetW = (targetW / 2) * 2;
    targetH = (targetH / 2) * 2;
    
}

GDI_RESULT VappMAVDraw::drawFrame(VfxU32 frameIndex)
{
    U32 gdi_cf = GDI_COLOR_FORMAT_16;
    if(m_cf == VRT_COLOR_TYPE_RGB888)
    {
        gdi_cf = GDI_COLOR_FORMAT_24;
    }
    
    GDI_RESULT res = 0;
    gdi_handle contentLayer = NULL;
    do
    {
        res = gdi_layer_create_cf_using_outside_memory(gdi_cf, 
                                                   0, 0, 
                                                   GDI_LCD_WIDTH, 
                                                   GDI_LCD_HEIGHT, 
                                                   &contentLayer,
                                                   m_contentBuffer, 
                                                   GDI_LCD_WIDTH*GDI_LCD_HEIGHT*m_bpp);
        if(GDI_SUCCEED != res)
            break;
        
        S32 imgWidth = 0;
        S32 imgHeight = 0;
        res = gdi_image_get_dimension_file((S8*)m_sourceFileName, &imgWidth, &imgHeight);
        if(GDI_SUCCEED != res)
            break;

        // center-crop the image
        S32 imgOffsetX = 0;
        S32 imgOffsetY = 0;
        S32 imgSrcWidth = 2;
        S32 imgSrcHeight = 2;
        VfxBool mustClearBlack;
        imgOffsetX = ((S32)m_FrameWidth - imgWidth) / 2;
        imgOffsetY = ((S32)m_FrameHeight - imgHeight) / 2;

        fitImage(VfxSize(imgWidth, imgHeight), imgOffsetX, imgOffsetY, imgSrcWidth, imgSrcHeight, mustClearBlack);

        // clear BG color if image is smaller than LCD
        if(mustClearBlack)
        {
            gdi_layer_clear_nb_concurrent(contentLayer, GDI_COLOR_BLACK);
        }
        
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        res = gdi_imgdec_draw_resized_file_frames(contentLayer, 
                                            imgOffsetX, 
                                            imgOffsetY, 
                                            imgSrcWidth,
                                            imgSrcHeight,
                                            (U8*)m_sourceFileName,
                                            frameIndex);
        #endif
        
    }while(0);

    if(GDI_SUCCEED != res)
    {
        // center-crop the image
        S32 imgWidth = 0;
        S32 imgHeight = 0;
        S32 imgOffsetX = 0;
        S32 imgOffsetY = 0;
        gdi_image_get_dimension_id(m_fallbackImgId, &imgWidth, &imgHeight);
        imgOffsetX = ((S32)GDI_LCD_WIDTH - imgWidth) / 2;
        imgOffsetY = ((S32)GDI_LCD_HEIGHT - imgHeight) / 2;

        gdi_layer_push_and_set_active(contentLayer);
        gdi_image_draw_id(imgOffsetX, imgOffsetY, m_fallbackImgId);
        gdi_layer_pop_and_restore_active();
    }
    
    if(contentLayer)
    {
        gdi_layer_free(contentLayer);
    }

    return res;
}

VfxBool VappMAVDraw::createFileInfo(void)
{
    GDI_RESULT res = GDI_SUCCEED;
    do
    {
        S32 count = 0;
        res = gdi_image_get_frame_count_file((U8*)m_sourceFileName, &count);
        if(GDI_SUCCEED != res)
            break;
        m_frameCnt = count;
        m_FrameWidth = GDI_LCD_WIDTH;
        m_FrameHeight = GDI_LCD_HEIGHT;
        
        VfxS32 initFrame = m_frameCnt / 2;
        res = drawFrame(initFrame);
        m_framePtr = initFrame;
        if(GDI_SUCCEED != res)
            break;
        
        return VFX_TRUE;
    }while(0);
    
    return VFX_FALSE; 
}

VfxBool VappMAVDraw::destoryFileInfo(void)
{
    return VFX_TRUE;
}

vrt_render_dirty_type_enum VappMAVDraw::onUpdate(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MUP", SA_start);
    #endif
    VfxObjHandle hDraw = *((VfxObjHandle*)user_data);
    VappMAVDraw *draw = (VappMAVDraw*)VfxObject::handleToObject(hDraw);

    if(NULL == draw || draw->m_isSuspend)
    {
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MUP", SA_stop);
        #endif
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }


    // calculate which frame to draw
    VfxU32 frameIndex = watch_frame->pos_z;
    
    // clamp to valid region
    if(frameIndex >= draw->m_frameCnt)
    {
        frameIndex = draw->m_frameCnt - 1;
    }
    if(frameIndex < 0)
    {
        frameIndex = 0;
    }
    
    if(frameIndex == draw->m_framePtr)
    {
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MUP", SA_stop);
        #endif
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
    
    GDI_RESULT res = 0;
    res = draw->drawFrame(frameIndex);
    draw->m_framePtr = frameIndex;
    if (res != GDI_SUCCEED)
    {
        vrt_invoke_mmi_rpc(onVRTError, hDraw);
        draw->m_isErrorHappended = VFX_TRUE;
    }

    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MUP", SA_stop);
    #endif
    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
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

static gdi_img_buf_color_format_enum getCF(VfxColorTypeEnum vrtCF)
{
    switch(vrtCF)
    {
        case VRT_COLOR_TYPE_RGB565:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB565;
        case VRT_COLOR_TYPE_RGB888:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB888;
        case VRT_COLOR_TYPE_PARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;
        case VRT_COLOR_TYPE_ARGB8888:
            return GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return GDI_IMG_BUF_COLOR_FORMAT_UNKNOWN;
    }
}

void VappMAVDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDR", SA_start);
    #endif

    if(m_errorCode != 0)
    {
        #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDR", SA_stop);
        #endif
        // even if error happens, we still draw the fallback image
    }

    VfxU8 *ptr = dstBuffer.ptr;
    VfxU8 *q = m_contentBuffer;

    // offset to origin
    ptr +=  dstRect.origin.y * dstBuffer.pitchBytes + dstRect.origin.x * getBPP(dstBuffer.colorFormat);
    q +=  srcRect.origin.y * m_FrameWidth * m_bpp + srcRect.origin.x * m_bpp;

    // copy draw region
    gdi_img_buf_struct dst;
    dst.ptr = ptr;
    dst.pitch_bytes = dstBuffer.pitchBytes;
    dst.color_format = getCF(dstBuffer.colorFormat);
    gdi_img_buf_struct src;
    src.ptr = q;
    src.pitch_bytes = m_FrameWidth * m_bpp;
    src.color_format = getCF(m_cf);
    gdi_img_buf_copy(&dst, &src, dstRect.getWidth(), dstRect.getHeight());

    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDR", SA_stop);
    #endif
}

// this function is called when error happen on VRT stack and send back to MMI to restore
void VappMAVDraw::onVRTError(void *arg)
{
    VfxObjHandle drawHandle = (VfxObjHandle)arg;
    VappMAVDraw *draw = (VappMAVDraw*)VfxObject::handleToObject(drawHandle);
    if(draw)
    {
        draw->restoreWallpaperSetting(draw->m_errorCode);
    }
}

void VappMAVDraw::restoreWallpaperSetting(VfxU32 errCode)
{
    m_errorCode = errCode;

#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_GLOBAL_DRM_INVALID_FORMAT));
#endif

    VfxObject *parentFrame = getParent();
    VappWallpaper *wp = VFX_OBJ_DYNAMIC_CAST(parentFrame, VappWallpaper);
    if(wp)
    {
        wp->restoreWallpaperSetting();
    }
}

VfxBool VappWallpaperMAV::trySetupMotionSensor()
{
#if defined(__VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__) && defined(__MTK_TARGET__) 
    if(NULL == m_sensor)
    {
        VFX_OBJ_CREATE(m_sensor, VappMavMotionTranslator, this);
        m_sensor->m_sigSensorEvent.connect(this, &VappWallpaperMAV::handleSensorEvent);
        VfxBool sensorAvailable = m_sensor->startListen(GM_TILT, NULL);
        kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_3, 
                      "[Wallpaper][MAV] enable G-Sensor support, start success=%d", sensorAvailable);
        if(!sensorAvailable)
        {
            VFX_OBJ_CLOSE(m_sensor);
        }
        return sensorAvailable;
    }
    return VFX_TRUE;
#else
    return VFX_FALSE;
#endif
}

void VappWallpaperMAV::teardownMotionSensor()
{
#if defined(__VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__) && defined(__MTK_TARGET__) 
    if(m_sensor)
    {
        m_sensor->stopListen(GM_TILT);
        VFX_OBJ_CLOSE(m_sensor);
        kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_3, 
                  "[Wallpaper][MAV] G-Sensor support stopped");
    }
#endif
}

void VappWallpaperMAV::handleSensorEvent(VfxFloat offset)
{
#if defined(__VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__) && defined(__MTK_TARGET__) 
    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEN", SA_start);
    #endif
    if(NULL == m_draw)
    {
        return;
    }

    if(0 == m_draw->m_frameCnt)
    {
        return;
    }

    // offset ranges from -1.0f ~ 1.0f
    VfxS32 offsetFrame = (VfxS32)VFX_MAX(-1.f, VFX_MIN(1.f, offset * 10.f));
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_HANDLE_SENSOR_EVENT_D, (VfxS32)(offsetFrame * 10000));
    const VfxU32 currentFrame = getPosZ();
    const VfxS32 oldValue = currentFrame;
    VfxS32 newValue = oldValue + offsetFrame; 

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_HANDLE_SENSOR_EVENT_1_OLD_VALUE_D_NEW_VALUE_D, oldValue, newValue);
    const VfxS32 maxFrameIndex = m_draw->m_frameCnt - 1;
    const VfxS32 minFrameIndex = 0;
    newValue  = VFX_MAX(minFrameIndex, VFX_MIN(newValue, maxFrameIndex));
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_HANDLE_SENSOR_EVENT_2_NEW_VALUE_D, newValue);

    // value ranges from 0 ~ (MAX_FRAME_COUNT - 1)
    VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setPosZ(newValue);
    VfxAutoAnimate::commit();
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_MAV_HANDLE_SENSOR_EVENT_3);
    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SEN", SA_stop);
    #endif
#endif
}

 
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__ */
