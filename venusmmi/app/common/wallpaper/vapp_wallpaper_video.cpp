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
 *  vapp_wallpaper_video.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen video wallpaper class
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_video.h"
#include "vfx_cpp_base.h"  
#include "vfx_object.h"   
#include "vfx_sys_memory.h"  
#include "vapp_wallpaper.h"   
#include "vfx_class_info.h"   
#include "vfx_datatype.h"    
#include "vfx_primitive_frame.h"  
#include "vfx_rect_frame.h"   
#include "vfx_basic_type.h"   
#include "vfx_string.h"    
#include "drm_errcode.h"   
#include "drm_def.h"    
#include "vfx_frame.h"  
#include "vfx_auto_animate.h" 
#include "cp\vapp_video_player_cp.h"
#include "vadp_asm.h"

extern "C"
{
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "cbm_api.h"
#include "lcd_sw_inc.h"
#include "gdi_primitive.h"
#include "mdi_include.h"
#include "MRESrvGProt.h"
#include "app_mem.h"
#include "fs_gprot.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "CustDataRes.h"
}

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_wallpaper_setting_provider.h"
#include "vapp_usb_gprot.h"
#else
extern "C"
{
#include "GlobalResDef.h"
#include "drm_errcode.h"
#include "drm_def.h"
#include "SettingGprots.h"
#include "PhoneSetupGprots.h"
#include "WPSSProtos.h"
#include "AlertScreen.h"
extern S8 *idle_screen_wallpaper_name;
extern S8 *idle_screen_wallpaper_name_original;
extern MMI_ID_TYPE idle_screen_wallpaper_ID;
}
#endif

#ifdef __MTK_TARGET__
// #define __MAUI_SOFTWARE_LA__
#endif

#if defined(__MTK_TARGET__) && defined(__MAUI_SOFTWARE_LA__)
extern "C"
{
#include "SST_sla.h"
}
#define SWLA_BEGIN(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define SWLA_END(_symbol_) SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define SWLA_BEGIN(_symbol_)
#define SWLA_END(_symbol_)
#endif


/***************************************************************************** 
 * Layout
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define PAGE_MESSAGE_FONT_SIZE (20)
#elif defined(__MMI_MAINLCD_480X800__)
#define PAGE_MESSAGE_FONT_SIZE (30)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define PAGE_MESSAGE_FONT_SIZE (16)
#else
#define PAGE_MESSAGE_FONT_SIZE (16)
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef MDI_RESULT (*PFN_MDI_CLOSE_FUNC)(void);

/*****************************************************************************
 * Home screen UI componet: video wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Video Wallpaper", VappWallpaperVideo, VappWallpaper);

VappWallpaperVideo::VappWallpaperVideo()  :
    m_video(0),
    m_bufSnapshot(NULL),
    m_errText(NULL),
    m_asmGroupId(0),
    m_isUSBErrorPopped(VFX_FALSE),
    m_resId(0)
{
}

void VappWallpaperVideo::onInit()
{
    VappWallpaper::onInit();

    registerBroadcastEvent(
        VFX_FRAME_BROADCAST_EVENT_BEFORE_EXIT |  // handle screen exit event
        VFX_FRAME_BROADCAST_EVENT_AFTER_EXIT
        );
}

void VappWallpaperVideo::onDeinit()
{
    deinitASMScreenGroup();
    VappWallpaper::onDeinit();
}

void VappWallpaperVideo::onObjectNotify(VfxId id, void *userData)
{
    if(VFX_FRAME_NOTIFY_ID_BROADCAST == id)
    {
        VfxFrameBroadcastData *param = (VfxFrameBroadcastData*)userData;
        switch(param->eventId)
        {
        case VFX_FRAME_BROADCAST_EVENT_BEFORE_EXIT:
            // make sure we suspend the video before exiting
            onSuspend();
            break;
        }
    }
    VappWallpaper::onObjectNotify(id, userData);
}

void VappWallpaperVideo::setResId(VfxId resId)
{
    m_resId = resId;
}

void VappWallpaperVideo::setPath(const VfxWString &path)
{
    m_path = path;
}

VfxBool VappWallpaperVideo::onAllowSuspendOnSwipe()
{
#ifdef __VENUS_3D_UI_ENGINE__
    return VFX_FALSE;
#else
    return VFX_TRUE;
#endif
}

VfxBool VappWallpaperVideo::onAllowSuspendOnPenDown()
{
#ifdef __VENUS_3D_UI_ENGINE__
    return VFX_FALSE;
#else
    return VFX_TRUE;
#endif
}

VfxU32 VappWallpaperVideo::getVrtMemFactor()
{
#ifdef __VENUS_3D_UI_ENGINE__
    // Venus 3D:
    // video wallpaper itself does not require extra VRT memory
    // but we will only reserve what we need,
    // the rest still use as VRT mem factor,
    // to prevent OpenGL OOM.
    const VfxU32 videoMemSize = mmi_res_get_app_base_mem_size(APP_VENUS_WALLPAPER_VIDEO);
    if(VappWallpaper::getVrtMemFactor() > videoMemSize)
    {
        return VappWallpaper::getVrtMemFactor() - videoMemSize;
    }
    else
    {
        return 0;
    }
#else
    return 0;
#endif
}

void VappWallpaperVideo::onSerializeView()
{
    onReleaseView();
}
    
void VappWallpaperVideo::onRestoreView()
{
    onCreateView();
}

void VappWallpaperVideo::onReleaseView()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_ON_RELEASE_VIEW_THIS_D, this);

    VFX_OBJ_CLOSE(m_video);
    releaseSnapshotBuffer();
    showDefaultWallpaperFrame(VFX_FALSE);
    
    // un-register
    registerEvents(VFX_FALSE);
    deinitASMScreenGroup();
}

void VappWallpaperVideo::releaseSnapshotBuffer()
{
    if(m_bufSnapshot)
    {
        VfxImageSrc nullSrc;
        setImgContent(nullSrc);
        VFX_ASSERT(GRP_ID_INVALID != m_asmGroupId);
        applib_asm_free_r(m_asmGroupId, m_bufSnapshot);
        m_bufSnapshot = NULL;
    }
}

VfxBool VappWallpaperVideo::initASMScreenGroup()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP);
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM__)
    if(GRP_ID_INVALID != m_asmGroupId)
    {
        // already initialized
        return VFX_TRUE;
    }

    if(0 != getExternalMemorySource())
    {
        // use external-assigned group first
        m_asmGroupId = getExternalMemorySource();
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_USE_EXTERNAL_ASM_GROU_D, m_asmGroupId);
        return VFX_TRUE;
    }
    
    // since we have multiple wallpaper instances,
    // we need to use differen ID to create different ASM group.
    VfxS32 offset = 0;
#if defined(__COSMOS_MMI_PACKAGE__)
    const VappWallpaperType source = (const VappWallpaperType)getSource();
    switch(source)
    {
    case VAPP_WALLPAPER_HOME_SCREEN:
        offset = 1;
        break;
    case VAPP_WALLPAPER_LOCK_SCREEN:
        offset = 2;
        break;
    }
    if(isStaticWallpaper())
    {
        offset = 3;
    }
#endif
    const MMI_ID gid = APP_VENUS_WALLPAPER_VIDEO + offset;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP_GID_D_OFFSET_D, gid, offset);

    // check if the group is already created.
    // if so, treat as create fail.
    mmi_group_node_struct node_info;
    if(MMI_RET_OK == mmi_frm_group_get_info (gid, &node_info))
    {
        // already created, fail,
        // since we don't want to mess with existing wallpaper instance.
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP_FAIL_DUE_TO_ALREADY_CREATED);
        return VFX_FALSE;
    }
    
    // create ASM group
    VadpAsmProperty p;
    m_asmGroupId = mmi_frm_group_create(GRP_ID_ROOT, 
                                      gid, 
                                      &onScreenGroupEvent, 
                                      getObjHandle());
                                      
    if(GRP_ID_INVALID != m_asmGroupId)
    {
        U32 size = mmi_res_get_app_base_mem_size(APP_VENUS_WALLPAPER_VIDEO) + 
                   mmi_res_get_app_fg_mem_size(APP_VENUS_WALLPAPER_VIDEO);
        if (mmi_frm_asm_check_enough(m_asmGroupId, size) == MMI_FALSE)
        {
            mmi_frm_group_close(m_asmGroupId);
            m_asmGroupId = GRP_ID_INVALID;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP_FAIL_MMI_FRM_ASM_CHECK_ENOUGH);
            return VFX_FALSE;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP_OK);
        VadpAsm::getProperty(m_asmGroupId, p);
        p.f_prepare_w_reserve = 0;
        p.f_hide_in_oom = 0;
        VadpAsm::setProperty(m_asmGroupId, p);
        return VFX_TRUE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_INIT_ASMSCREEN_GROUP_FAIL);
        // cannot create asm group e.g. during small screen redraw
        return VFX_FALSE;
    }
    
#else
    // Pluto case, MED mem is used, no ASM group needed.
    return VFX_TRUE;
#endif
}

void VappWallpaperVideo::deinitASMScreenGroup()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_DEINIT_ASMSCREEN_GROUP);
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM__)
    // since video CP depends on group id,
    // make sure it is destroyed.
    VFX_OBJ_CLOSE(m_video);
    // snapshot also uses ASM buffer
    releaseSnapshotBuffer();
    if(GRP_ID_INVALID != m_asmGroupId)
    {
        if(getExternalMemorySource() != m_asmGroupId)
        {
            mmi_frm_group_close(m_asmGroupId);
        }
        m_asmGroupId = GRP_ID_INVALID;
    }
#else
    // Pluto case, MED mem is used, no ASM group needed.
    return;
#endif
}

mmi_ret VappWallpaperVideo::onScreenGroupEvent(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    switch(evt->evt_id)
    {
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        // keep dangle group
        return MMI_RET_ERR;
    case EVT_ID_ASM_FREE_REQ:   // volunteer free
    case EVT_ID_ASM_FREE_REQ_NO_WAIT: // volunteer free
    case EVT_ID_ASM_FORCE_FREE: // force free
        {
            VappWallpaperVideo *pThis = (VappWallpaperVideo*)VfxObject::handleToObject(evt->user_data);
            if(pThis)
            {
                // force suspend the wallpaper first, since we'll destroy video soon
                pThis->onSuspend();
                // use default image when memory is insufficient
                pThis->handleVideoError(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT);
                pThis->deinitASMScreenGroup();
            }
        }
        return MMI_FRM_ASM_FREED;
    }
    return ret;
}

void VappWallpaperVideo::onCreateView()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_ON_CREATE_VIEW_THIS_D, this);
    // set transparent + fully opaque to prevent VRT 
    // perform redundant background clear color.
    setBgColor(VFX_COLOR_TRANSPARENT);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    registerEvents(VFX_TRUE);

    VfxWString filename;
    VfxResId resId = 0;
    VfxBool isResource = VFX_FALSE;
    if(getWallpaperSource(isResource, filename, resId))
    {
#if !defined(__COSMOS_MMI_PACKAGE__) && !defined(__MED_IN_ASM__)
        // if MRE is running, treat as insufficient memory.
        if(srv_mre_is_using_media_buffer())
        {
            handleVideoError(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT);
            return;
        }
#endif
        if(!initASMScreenGroup())
        {
            handleVideoError(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT);
            return;
        }

        if(isStaticWallpaper())
        {
            VFX_OBJ_CLOSE(m_video);
            // try snapshot
            if(!getVideoSnapshot(isResource, filename, resId))
            {
                // treat as no memory case if snapshot failed
                handleVideoError(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT);
            }
            return;
        }
        
        if(NULL == m_video)            
        {
            
            VappVideoPlayerPlayOption option;
            option.configAsWallpaperVideo();
            option.useAnonymousASM = VFX_FALSE;
            option.asmGroupId = m_asmGroupId;
            VFX_OBJ_CREATE_EX(m_video, VappVideoPlayerComponent, this, (option));
        }
        m_video->setPos(0, 0);
        m_video->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
        m_video->setBgColor(VFX_COLOR_TRANSPARENT);
        m_video->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
        m_video->m_signalFileOpened.connect(this, &VappWallpaperVideo::onVideoOpened);
        m_video->m_signalPlaybackFinished.connect(this, &VappWallpaperVideo::onVideoFinished);
        if(m_errText)
        {
            m_errText->setHidden(VFX_TRUE);
        }
        if(isResource)
        {
            m_video->openResId(resId);
        }
        else if(checkUSBMode())
        {
            m_video->openFile(filename);
        }
    }
}

VfxBool VappWallpaperVideo::getWallpaperSource(VfxBool &isResource, VfxWString &filename, VfxResId &resId)
{
    filename = VFX_WSTR_EMPTY;
    resId = 0;
    VfxBool isSuccess = VFX_FALSE;

    if(m_resId)
    {
        // resource id is set from external, use it first.
        isResource = VFX_TRUE;
        resId = m_resId;
        isSuccess = VFX_TRUE;
    }
    else if(!m_path.isEmpty())
    {
        isResource = VFX_FALSE;
        filename = m_path;
        isSuccess = VFX_TRUE;
    }
    else
    {
        // load system setting
#ifdef __COSMOS_MMI_PACKAGE__
        VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
        const VappWallpaperSrcEnum source = (const VappWallpaperSrcEnum)getSource();
        VFX_ASSERT(VAPP_WALLPAPER_SRC_HOMESCREEN == source || VAPP_WALLPAPER_SRC_LOCK == source);
        VappWallpaperId wpId = setting->getDefaultWallpaper(source, getParent());
        VappWallpaperFactorySrcEnum resType = wpId.getSource();
        
        // Resource type should be static wallpaper or user define wallpaper
        switch(resType)
        {
        case VAPP_WALLPAPER_FACTORY_VIDEO:
            resId = wpId.getIntType();
            isResource = VFX_TRUE;
            isSuccess = VFX_TRUE;
            break;
        case VAPP_WALLPAPER_FACTORY_USERFILE:
            filename.loadFromMem(wpId.getWStringType());
            isResource = VFX_FALSE;
            isSuccess = VFX_TRUE;
            break;
        default:
            {
                VappWallpaperSettingInterface* wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
                wallpaperInterface->restoreWallpaper((VappWallpaperType)source);
            isSuccess = VFX_FALSE;
            break;
        }
        }
#else
        isSuccess = VFX_TRUE;
        resId = (VfxU16)idle_screen_wallpaper_ID;
        isResource = (0 != resId);

        if(!isResource)
        {
            filename.loadFromMem((VfxWChar*)idle_screen_wallpaper_name_original);
        } 
#endif
    }


    return isSuccess;
}

void VappWallpaperVideo::playIfPossible()
{
    if(m_video && !isSuspended() && checkUSBMode())
    {
        SWLA_BEGIN("WPL");
        m_video->play();
        SWLA_END("WPL");
    }
}

void VappWallpaperVideo::createImageBufferFromSnapshotBuffer(VfxImageBuffer &imgBuf)
{
    imgBuf.ptr = m_bufSnapshot;
    imgBuf.pitchBytes = GDI_LCD_WIDTH * 2;
    imgBuf.width = GDI_LCD_WIDTH;
    imgBuf.height = GDI_LCD_HEIGHT;
    
    #if !defined(__MDI_DISPLAY_RGB565_SUPPORT__) && defined(__MDI_DISPLAY_YUYV422_SUPPORT__)
    imgBuf.colorFormat = VRT_COLOR_TYPE_UYVY422;
    #else
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    #endif
    
    return;
}

#if defined(__COSMOS_MMI_PACKAGE__)
inline VfxBool isGroupFromAppId(mmi_id appId, mmi_id groupId)
{
    return (groupId >= appId && groupId < mmi_res_get_app_max(appId));
}
#endif

VfxBool VappWallpaperVideo::isStaticWallpaper()
{
#ifdef __COSMOS_MMI_PACKAGE__
    // Only these APPs are allowed to play video in background
    const mmi_id whiteList[] = {
        VAPP_LAUNCHER,
        VAPP_SCREEN_LOCK,
        };
        
    mmi_id groupId = findRootAppGroupId(this);
    for(VfxS32 i = 0; i < sizeof(whiteList) / sizeof(mmi_id); ++i)
    {
        if(isGroupFromAppId(whiteList[i], groupId))
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
#else
    return VFX_FALSE;
#endif
}

static gdi_handle convertImageBufferToLayer(const VfxImageBuffer &imgBuf)
{
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;

    // Thumbnail must be 16-bit RGB565 or 24-bit RGB888 now
    gdi_color_format gdiCF = GDI_COLOR_FORMAT_16;
    switch(imgBuf.colorFormat)
    {
    case VRT_COLOR_TYPE_RGB565:
        gdiCF = GDI_COLOR_FORMAT_16;
        break;
    case VRT_COLOR_TYPE_UYVY422:
        gdiCF = GDI_COLOR_FORMAT_UYVY422;
        break;
    default:
        VFX_ASSERT(0);  // only support RGB565 and UYVY422 now.
    }
    
    res = gdi_layer_create_cf_using_outside_memory(gdiCF, 
                                                   0, 0, 
                                                   imgBuf.width, 
                                                   imgBuf.height, 
                                                   &thumbLayer,
                                                   imgBuf.ptr, 
                                                   imgBuf.pitchBytes * imgBuf.height);
    VFX_ASSERT(GDI_SUCCEED == res);
    return thumbLayer;
}


VfxBool VappWallpaperVideo::getVideoSnapshot(VfxBool isResource, const VfxWString &filename, VfxResId resId)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT);
    
    if(GRP_ID_INVALID == m_asmGroupId)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_FAIL_D, __LINE__);
        return VFX_FALSE;
    }
    
    // act as static wallpaper, close video frame
    // and use snapshot as static image
    if(NULL == m_bufSnapshot)
    {
        m_bufSnapshot = (VfxU8*)applib_asm_alloc_nc_r(m_asmGroupId, GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2);
    }

    VfxBool ret = VFX_FALSE;
    PFN_MDI_CLOSE_FUNC closeFunc = NULL;
    gdi_handle layer = GDI_LAYER_EMPTY_HANDLE;
    do
    {
        if(NULL == m_bufSnapshot)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_FAIL_D, __LINE__);
            break;
        }

        VfxImageBuffer buf;
        createImageBufferFromSnapshotBuffer(buf);
        layer = convertImageBufferToLayer(buf);
        if(GDI_LAYER_EMPTY_HANDLE == layer)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_FAIL_D, __LINE__);
            break;
        }

        // open video
        // mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_MPEG4);
        MDI_RESULT result = MDI_RES_VDOPLY_SUCCEED;
        mdi_video_info_struct info;
        if(isResource)
        {
            result = mdi_video_ply_open_clip_id(
                    m_asmGroupId,
                    resId, 
                    &info);
            closeFunc = mdi_video_ply_close_file;
        }
        else
        {
            result = mdi_video_ply_open_clip_file(
                    m_asmGroupId,
                    (const CHAR*)filename.getBuf(), 
                    &info);
            closeFunc = mdi_video_ply_close_clip_file;
        }

        if(MDI_RES_VDOPLY_SUCCEED != result)
        {
            closeFunc = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_FAIL_D, __LINE__);
            break;
        }

        // retrieve 1st frame
        mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);
        result = mdi_video_ply_seek_and_get_frame(0, layer);
        if(MDI_RES_VDOPLY_SUCCEED != result)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_FAIL_D, __LINE__);
            break;
        }

        // set as VfxFrame source
        setImgContent(VfxImageSrc(buf));
        if(VRT_COLOR_TYPE_UYVY422 == buf.colorFormat)
        {
            // unfortunately, currently we don't support UYVY422 resize
            setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        }
        else
        {
            setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
        }
        
        
        ret = VFX_TRUE;
    }while(0);

    // Clean up 
    if(closeFunc)
    {
        closeFunc();
    }
    if(GDI_LAYER_EMPTY_HANDLE != layer)
    {
        gdi_layer_free(layer);
        layer = GDI_LAYER_EMPTY_HANDLE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_GET_VIDEO_SNAPSHOT_RET_D, ret);
    return ret;
}

void VappWallpaperVideo::onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    if(sender != m_video)
    {
        return;
    }
    
    if(MDI_RES_VDOPLY_SUCCEED == result)
    {
        // clear background image
        VfxImageSrc nullSrc;
        setImgContent(nullSrc);
        
        // delay 1 frame before start playing
        VfxTimer *timer = NULL;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->m_signalTick.connect(this, &VappWallpaperVideo::onDelayPlay);
        timer->setStartDelay(0);
        timer->start();
    }
    else 
    {
        handleVideoError(result);
    }
}

void VappWallpaperVideo::onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    if(NULL == m_video || sender != m_video)
    {
        return;
    }
    
    if(MDI_RES_VDOPLY_SUCCEED != result)
    {
        handleVideoError(result);
    }
}

void VappWallpaperVideo::handleVideoError(MDI_RESULT result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VIDEO_VAPP_WALLPAPER_VIDEO_HANDLE_VIDEO_ERROR_RESULT_D, result);
    // set default image icon
    VFX_OBJ_CLOSE(m_video);
    showDefaultWallpaperFrame(VFX_TRUE);

    // we tolerate insufficient memory case, 
    // since we use anonymouse memory
    if(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != result)
    {
        restoreWallpaperSetting();
    }
    else
    {
#ifndef __COSMOS_MMI_PACKAGE__
        // show error string in PLUTO case.
        // COSMOS project will have notification balloon by CP.
        mmi_event_notify_enum popupType;
        MMI_ID_TYPE errId = mdi_util_get_mdi_error_info(result, &popupType);
        VfxResId errStrId =  (VfxResId)errId;       
        VfxWString errStr(errStrId);
        if(NULL == m_errText)
        {
            VFX_OBJ_CREATE(m_errText, VfxTextFrame, this);
        }
        m_errText->setColor(VFX_COLOR_WHITE);
        m_errText->setIsUnhittable(VFX_TRUE);
        m_errText->setAnchor(0.5f, 0.5f);
        m_errText->setAutoResized(VFX_TRUE);
        m_errText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(PAGE_MESSAGE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_BORDER));
        const VfxSize size = getSize();
        m_errText->setSize(size.width, size.height / 3);
        m_errText->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_errText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_errText->setPos(size.width / 2, size.height / 2);
        m_errText->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID);
        m_errText->setHidden(VFX_FALSE);
        m_errText->setString(errStr);
        m_errText->bringToFront();
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_errText->setOpacity(1.0f);
        VfxAutoAnimate::commit();

        // delay 1 frame before start playing
        VfxTimer *timer = NULL;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->m_signalTick.connect(this, &VappWallpaperVideo::onHideErrText);
        timer->setStartDelay(1000);
        timer->start();
#endif
    }
}

void VappWallpaperVideo::onDelayPlay(VfxTimer *sender)
{
    VFX_OBJ_CLOSE(sender);
    playIfPossible();
}

void VappWallpaperVideo::onHideErrText(VfxTimer *sender)
{
    VFX_OBJ_CLOSE(sender);
    if(m_errText)
    {
        m_errText->setAutoAnimate(VFX_TRUE);
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);
        m_errText->setOpacity(0.0f);
        VfxAutoAnimate::commit();
        m_errText->setAutoAnimate(VFX_TRUE);
    }
}

void VappWallpaperVideo::onSuspend()
{
    SWLA_BEGIN("WOS");
    if(m_video)
    {
        SWLA_BEGIN("WPS");
        m_video->pause();
        SWLA_END("WPS");

        
        // switch to SW layer, because
        // 1. VRT can blend to OSD layer for better performance
        // 2. Blur effect on Venus3D requires this to work correctly
        SWLA_BEGIN("WSS");
        m_video->swithVideoLayerToSW(VFX_TRUE);
        SWLA_END("WSS");
    }
    SWLA_END("WOS");
}

void VappWallpaperVideo::onResume()
{
    if(m_video)
    {
        SWLA_BEGIN("WSH");
        m_video->swithVideoLayerToHW();
        SWLA_END("WSH");
        
        SWLA_BEGIN("WRS");
        // delay 1 frame before playing
        VfxTimer *timer = NULL;
        VFX_OBJ_CREATE(timer, VfxTimer, this);
        timer->m_signalTick.connect(this, &VappWallpaperVideo::onDelayPlay);
        timer->setStartDelay(0);
        timer->start();
        SWLA_END("WRS");
    }
}

static VfxBool isFileExist(const VfxWString &filePath)
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

mmi_ret VappWallpaperVideo::handleEvent(mmi_event_struct *param)
{
    if(NULL == m_video || NULL == param)
    {
        return MMI_RET_OK;
    }
    
    switch(param->evt_id)
    {
    case EVT_ID_GPIO_AFTER_LCD_SLEEP_IN:
        m_video->pause();
        break;
    case EVT_ID_GPIO_LCD_SLEEP_OUT:
        playIfPossible();
        break;
    case EVT_ID_SRV_UCM_INDICATION:
        {
            // handle background call finish
            srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)param;
            if (ind->ind_type == SRV_UCM_RELEASE_IND && !srv_ucm_is_any_call())
            {
                playIfPossible();
            }
        }
        break;
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            VfxWString filename;
            VfxResId resId = 0;
            VfxBool isResource = VFX_FALSE;
            if(getWallpaperSource(isResource, filename, resId) && !isResource)
            {
                if(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT == param->evt_id)
                {
                    if(!isFileExist(filename))
                    {
                        m_video->pause();
                        // MAUI_03009346: restore wallpaper immediately
                        // restore wallpaper back to default
                        restoreWallpaperSetting();
                    }
                }
                else if(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN == param->evt_id)
                {
                    if(isFileExist(filename))
                    {
                        m_video->closeFile();
                        if(checkUSBMode())
                        {
                            m_video->openFile(filename);
                        }
                    }
                }
            }
        }
        break;
#ifdef __MMI_USB_SUPPORT__
    case EVT_ID_USB_ENTER_MS_MODE:
        // when enter MSC mode, reset the flag.
        m_isUSBErrorPopped = VFX_FALSE;
        m_video->stop();
        break;
    case EVT_ID_USB_EXIT_MS_MODE:
        playIfPossible();
        break;
#endif // #ifdef __MMI_USB_SUPPORT__
    }
    return MMI_RET_OK;
}

VfxBool VappWallpaperVideo::checkUSBMode()
{
#if defined(__MMI_USB_SUPPORT__)
    if(srv_usb_is_in_mass_storage_mode_ext())
    {
        if(!m_isUSBErrorPopped)
        {
            #if defined(__COSMOS_MMI_PACKAGE__)
            vapp_usb_unavailable_popup(SRV_USB_ERROR_UNAVAILABLE);
            #endif
            // only pop message once per MSC mode
            m_isUSBErrorPopped = VFX_TRUE;
        }
        return VFX_FALSE;
    }
#endif
    return VFX_TRUE;
}

#endif  // __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__

