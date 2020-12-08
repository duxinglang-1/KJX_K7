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
 *  vapp_wallpaper_content_provider.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#include "vfx_context.h"
#include "vapp_wallpaper_content_provider.h"

#include "vcp_include.h"
#include "vfx_uc_include.h"

#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_file.h"
#include "vapp_wallpaper_setting_provider.h"
#include "vapp_wallpaper_native_factory.h"
#include "vapp_wallpaper_file_factory.h"

/***************************************************************************** 
 * VappScreenLockPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappLiveWallpaperContentProvider", VappLiveWallpaperContentProvider, VfxObject);

VappLiveWallpaperContentProvider::VappLiveWallpaperContentProvider():
    m_kit(NULL)
{
}

void VappLiveWallpaperContentProvider::onInit()
{
    VfxObject::onInit();
    VFX_ASSERT(NULL == m_kit);
    VFX_OBJ_CREATE(m_kit, VappWallpaperKit, this);
}

void VappLiveWallpaperContentProvider::onDeinit()
{
    VFX_OBJ_CLOSE(m_kit);
    VfxObject::onDeinit();
}

MMI_IMG_ID VappLiveWallpaperContentProvider::getLiveWallpaperThumb(S32 item_idx)
{
    VappWallpaperId wid;
    if(m_kit->getLiveWallpaperId(item_idx, wid) &&
       VAPP_WALLPAPER_FACTORY_NATIVE == wid.getSource())
    {
        return m_kit->getLiveWallpaperThumbnail(wid);
    }
    else
    {
        // file wallpaper does not have resource thumbnail.
        return 0;
    }
}

VfxBool VappLiveWallpaperContentProvider::decodeLiveWallpaperThumb(S32 item_idx, VfxImageBuffer &buf)
{
    VappWallpaperId wid;
    if(!m_kit->getLiveWallpaperId(item_idx, wid))
    {
        return VFX_FALSE;
    }

    switch(wid.getSource())
    {
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)
    case VAPP_WALLPAPER_FACTORY_FILE:
    {
        WallpaperFile f;
        WallpaperFile::fromWallpaperId(wid, f);
        // file wallpaper, decode as ABM (MWP) format
        VfxWString path = f.getFilePath();
        VfxBool decodeRet = VappWallpaperFileBase::decodeFileThumb(path, buf);
        return decodeRet;
    }
    #endif
    #if defined(__MMI_VUI_WALLPAPER_MRE__)
    case VAPP_WALLPAPER_FACTORY_MRE:
    {
        VappWallpaper *wp = m_kit->create(wid, this);
        VfxImageSrc src;
        VfxBool decodeRet = VFX_FALSE;
        do
        {
            decodeRet = wp->getThumbnailImageSrc(src);
            if(!decodeRet)
                break;

            if(VFX_IMAGE_SRC_TYPE_PATH != src.getType() &&
               VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA != src.getType())
            {
                decodeRet = VFX_FALSE;
                break;
            }

            GDI_HANDLE layer = GDI_NULL_HANDLE;
            GDI_RESULT res;
            res = gdi_layer_create_cf_using_outside_memory(
                                                   GDI_COLOR_FORMAT_16, 
                                                   0, 0, 
                                                   buf.width, 
                                                   buf.height, 
                                                   &layer,
                                                   buf.ptr, 
                                                   buf.width * buf.height * 2);
            if(GDI_SUCCEED != res)
            {
                decodeRet = VFX_FALSE;
                break;
            }
            
            gdi_layer_push_and_set_active(layer);
            switch(src.getType())
            {
            // use gdi_image instead of imgdec because GDI imgdec APIs don't support PBM format.
            // MRE may use PBM as thumbnail format.
            case VFX_IMAGE_SRC_TYPE_PATH:
                res = gdi_image_draw_resized_file(0, 0, buf.width, buf.height, (U8*)src.getPath().getBuf());
                break;
            case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
                {
                    const VfxFileRawData data = src.getImageRawDataBuffer();

                    
                    VfxU8 image_type = vrt_sys_image_get_type_from_raw_data_image(data.ptr, (vrt_raw_data_image_format_enum)data.imageFormat);
                    res = gdi_image_draw_resized_mem(0, 0, buf.width, buf.height, data.ptr, image_type, data.imageSize);
                }
                break;
            }
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(layer);
            layer = GDI_NULL_HANDLE;
            decodeRet = (res == GDI_SUCCEED);
        }while(0);
        
        VFX_OBJ_CLOSE(wp);
        return decodeRet;
    }    
    #endif
    default:
        break;
    }

    // only File-based wallpapers can be decoded.
    return VFX_FALSE;
}

void VappLiveWallpaperContentProvider::getLiveWallpaperName(S32 item_idx, VfxWString &name)
{
    VappWallpaperId wid;
    if(m_kit->getLiveWallpaperId(item_idx, wid))
    {
        getLiveWallpaperNameFromId(wid, name);
    }
}

void VappLiveWallpaperContentProvider::getLiveWallpaperNameFromId(const VappWallpaperId &wid, VfxWString &name)
{
    VFX_ASSERT(m_kit);
    VappWallpaper *wallpaper = m_kit->create(wid, this);
    wallpaper->getName(name);
    VFX_OBJ_CLOSE(wallpaper);
}

static VfxBool isGroupFromAppId(mmi_id appId, mmi_id groupId)
{
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM__)
    return (groupId >= appId && groupId < mmi_res_get_app_max(appId));
#else
    return VFX_FALSE;
#endif
}

void* VappLiveWallpaperContentProvider::getLiveWallpaper(U32 item_idx, void* parent_frame)
{
    // create wallpaper for Setting Preview
    VFX_ASSERT(m_kit);
    VappWallpaperId wid;
    if(!m_kit->getLiveWallpaperId(item_idx, wid))
    {
        return NULL;
    }

    VappWallpaper *wallpaper = m_kit->create(wid, (VfxFrame*)parent_frame);
    if(wallpaper)
    {
        // Setting APP should provide the memory
        VfxId grpId = VappWallpaper::findRootAppGroupId((VfxFrame*)parent_frame);
        if(grpId)
        {
            wallpaper->setExternalMemorySource(grpId);
        }
        wallpaper->setTotalPage(1);
        wallpaper->setSource(VAPP_WALLPAPER_SRC_LOCK);
        wallpaper->setPreview(VFX_TRUE);
        wallpaper->createView();
        wallpaper->setDesktopBoundsChanged(
                1,
                (VfxFrame*)parent_frame,
                ((VfxFrame*)parent_frame)->getBounds());
        wallpaper->suspend();
        wallpaper->resume();
    }
    return wallpaper;
}

S32 VappLiveWallpaperContentProvider::getLiveWallpaperTotalNum()
{
    return m_kit->getLiveWallpaperTotalNum();
}

void VappLiveWallpaperContentProvider::getLiveWallpaperId(S32 item_idx, VappWallpaperId &id)
{
    m_kit->getLiveWallpaperId(item_idx, id);
}

S32 VappLiveWallpaperContentProvider::translateLiveWallpaperIdToIndex(const VappWallpaperId &wid)
{
    VFX_ASSERT(m_kit);
    const S32 total = m_kit->getLiveWallpaperTotalNum();
    VappWallpaperId widTemp;
    for(S32 i = 0; i < total; ++i)
    {
        if(m_kit->getLiveWallpaperId(i, widTemp) &&
           widTemp == wid)
        {
            return i;
        }
    }
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_PROVIDER_WALLPAPER_ENUM_MAPS_TO_1);
    return -1;
}


// helper functions to retrieve wallpaper id from a static resource image
void VappLiveWallpaperContentProvider::getStaticImageWallpaperId(VappWallpaperId &wid, VfxResId imgId)
{
    wid.assignWith(VAPP_WALLPAPER_FACTORY_IMAGE, imgId);
}

void VappLiveWallpaperContentProvider::getResourceVideoWallpaperId(VappWallpaperId &wid, VfxResId vidId)
{
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    wid.assignWith(VAPP_WALLPAPER_FACTORY_VIDEO, vidId);
#endif
}

void VappLiveWallpaperContentProvider::getUserWallpaperId(VappWallpaperId &wid, const VfxWString &filePath)
{
#if !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
    return getUserImageWallpaperId(wid, filePath);
#else
    const S32 fileType = srv_fmgr_types_find_type_by_filepath(filePath.getBuf());
    const S32 groupType = srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)fileType);
    if(FMGR_GROUP_VIDEO == groupType)
    {
        return getUserVideoWallpaperId(wid, filePath);
    }
    else
    {
        return getUserImageWallpaperId(wid, filePath);
    }
#endif
}

void VappLiveWallpaperContentProvider::getUserImageWallpaperId(VappWallpaperId &wid, const VfxWString &imgPath)
{
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    // create MAV wallpapper if file is of MAV type.
    S32 fileType = srv_fmgr_types_find_type_by_filepath(imgPath.getBuf());
    if(FMGR_TYPE_MAV == fileType)
    {
        wid.assignWith(VAPP_WALLPAPER_FACTORY_USERFILE, imgPath.getBuf());
    }
    else
    {
        wid.assignWith(VAPP_WALLPAPER_FACTORY_IMAGE, (WCHAR*)imgPath.getBuf());
    }
#else
    // always create "Wide" image wallpaper
    wid.assignWith(VAPP_WALLPAPER_FACTORY_IMAGE, (WCHAR*)imgPath.getBuf());
#endif
}

void VappLiveWallpaperContentProvider::getUserVideoWallpaperId(VappWallpaperId &wid, const VfxWString &vidPath)
{
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    wid.assignWith(VAPP_WALLPAPER_FACTORY_VIDEO, vidPath);
#endif
}

/***************************************************************************** 
 * C-style API for Pluto setting
 *****************************************************************************/
extern "C"
{
MMI_BOOL
vapp_wallpaper_provider_create(VAPP_WALLPAPER_PROVIDER_HANDLE* handlePtr)
{
    if(NULL == handlePtr)
    {
        return MMI_FALSE;
    }
    
    // Create on Venus System Pool
    VappLiveWallpaperContentProvider *pThis;
    VFX_OBJ_CREATE(pThis, VappLiveWallpaperContentProvider, VFX_SYS_GLOBAL_CONTEXT);
    VFX_ASSERT(pThis->getParent() == VFX_SYS_GLOBAL_CONTEXT);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_PROVIDER_CREATE_ON_SYS_CONTEXT);
    if(pThis)
    {
        *handlePtr = (void*)pThis;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

MMI_BOOL
vapp_wallpaper_provider_create_ex(VAPP_WALLPAPER_PROVIDER_HANDLE* handlePtr, U8 *working_buf, U32 buf_size)
{
    if(NULL == handlePtr)
    {
        return MMI_FALSE;
    }

    if(VAPP_WALLPAPER_PROVIDER_WORKING_MEMORY_SIZE > buf_size || NULL == working_buf)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_PROVIDER_CREATE_EX_FAILED_BUFFER_TOO_SMALL);
        return MMI_FALSE;

    }

    VfxContext *cntx = NULL;
    VFX_OBJ_CREATE(cntx, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    cntx->assignPool(working_buf, buf_size, VFX_TRUE);

    // Create on Venus System Pool
    VappLiveWallpaperContentProvider *pThis;
    VFX_OBJ_CREATE(pThis, VappLiveWallpaperContentProvider, cntx);
    VFX_ASSERT(pThis->getParent() == cntx);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_PROVIDER_CREATE_ON_CONTEXT_X_BUF_X, cntx, working_buf);
    
    if(pThis)
    {
        *handlePtr = (void*)pThis;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

static VappLiveWallpaperContentProvider* _handle_to_ptr(VAPP_WALLPAPER_PROVIDER_HANDLE handle)
{
    VappLiveWallpaperContentProvider *pThis = (VappLiveWallpaperContentProvider*)handle;
    VFX_ASSERT(pThis);
    return pThis;
}

static VappWallpaperId* _handle_to_id(VAPP_WALLPAPER_ID_HANDLE hId)
{
    VappWallpaperId *pThis = (VappWallpaperId*)hId;
    VFX_ASSERT(pThis);
    return pThis;
}

void
vapp_wallpaper_provider_close(VAPP_WALLPAPER_PROVIDER_HANDLE handle)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_PROVIDER_CLOSE);
    VappLiveWallpaperContentProvider *pThis = _handle_to_ptr(handle);
    VfxContext *cntx = VFX_OBJ_DYNAMIC_CAST(pThis->getParent(), VfxContext);
    VFX_OBJ_CLOSE(pThis);
    if(cntx != VFX_SYS_GLOBAL_CONTEXT)
    {
        vfx_sys_mem_pool_status_struct stat;
        cntx->statistics(stat);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_PROVIDER_CLOSE_CUSTOM_CONTEXT_MAX_USAGE_D_BYTES, stat.max_used_size);
        VFX_OBJ_CLOSE(cntx); 
    }
}

void
vapp_wallpaper_id_handle_close(VAPP_WALLPAPER_ID_HANDLE handle)
{
    VappWallpaperId *pThis = _handle_to_id(handle);
    VFX_SYS_DELETE(pThis);
}

S32
vapp_wallpaper_provider_get_live_wallpaper_total_num(VAPP_WALLPAPER_PROVIDER_HANDLE handle)
{
    return _handle_to_ptr(handle)->getLiveWallpaperTotalNum();
}

VAPP_WALLPAPER_ID_HANDLE
vapp_wallpaper_provider_get_live_wallpaper_id_handle(VAPP_WALLPAPER_PROVIDER_HANDLE handle, S32 item_idx)
{
    // How to pass VappWallpaperId to PLUTO applications?
    VappLiveWallpaperContentProvider *provider = _handle_to_ptr(handle);
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    provider->getLiveWallpaperId(item_idx, *pid);
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE
vapp_wallpaper_provider_get_current_live_wallpaper_id_handle(VappWallpaperSrcEnum source)
{
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    *pid = setting->getDefaultWallpaper(source, setting);
    return pid;
}

S32
vapp_wallpaper_provider_get_current_live_wallpaper_item_idx(VAPP_WALLPAPER_PROVIDER_HANDLE handle, VappWallpaperSrcEnum source)
{
    // How to pass VappWallpaperId to PLUTO applications?
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappLiveWallpaperContentProvider *provider = _handle_to_ptr(handle);
    VappWallpaperId wid = setting->getDefaultWallpaper(source, provider);
    S32 index = provider->translateLiveWallpaperIdToIndex(wid);
    if(index == -1)
    {
        index = 0;
    }
    return index;
}

MMI_BOOL
vapp_wallpaper_setting_save_wallpaper_id_handle(VappWallpaperSrcEnum source, VAPP_WALLPAPER_ID_HANDLE hId)
{
    // How to pass VappWallpaperId to PLUTO applications?
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    setting->setDefaultWallpaper(source, *_handle_to_id(hId), setting);
    return MMI_TRUE;
}

S32
vapp_wallpaper_provider_get_live_wallpaper_name_from_item_idx(VAPP_WALLPAPER_PROVIDER_HANDLE handle, S32 item_idx, WCHAR *name_buf, S32 buf_len)
{
    VfxWString name;
    _handle_to_ptr(handle)->getLiveWallpaperName(item_idx, name);

    const S32 reqLen = name.getLength() + 1;
    if(name_buf && buf_len >= reqLen)
    {
        mmi_wcsncpy(name_buf, name.getBuf(), buf_len);
    }
    return reqLen;
}

S32
vapp_wallpaper_provider_get_live_wallpaper_name_from_wallpaper_id_handle(VAPP_WALLPAPER_ID_HANDLE id_handle, WCHAR *name_buf, S32 buf_len)
{
    // kit will be destroyed within this function,
    // so we use system pool directly.
    VappWallpaperKit *kit = NULL;
    VFX_OBJ_CREATE(kit, VappWallpaperKit, VFX_SYS_GLOBAL_CONTEXT);
    VappWallpaper *wallpaper = kit->create(*_handle_to_id(id_handle), kit);
    VfxWString name;
    if(wallpaper)
    {
        wallpaper->getName(name);
        VFX_OBJ_CLOSE(wallpaper);
    }
    else
    {
        name.setEmpty();
    }
    VFX_OBJ_CLOSE(kit);

    const S32 reqLen = name.getLength() + 1;
    if(name_buf && buf_len >= reqLen)
    {
        mmi_wcsncpy(name_buf, name.getBuf(), buf_len);
    }
    return reqLen;
}

MMI_BOOL vapp_wallpaper_provider_is_current_wallpaper_file_based(VappWallpaperSrcEnum source)
{
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappWallpaperId wid = setting->getDefaultWallpaper(source, setting);
    if(VappWallpaperKit::isFileBasedWallpaper(wid))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_video_wallpaper_id_handle()
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getResourceVideoWallpaperId(*pid, 0);
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_image_wallpaper_id_handle()
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getStaticImageWallpaperId(*pid, 0);
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_res_video_wallpaper_id_handle(MMI_ID video_res_id)
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getResourceVideoWallpaperId(*pid, video_res_id);
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_res_image_wallpaper_id_handle(MMI_ID image_res_id)
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getStaticImageWallpaperId(*pid, image_res_id);
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_user_image_wallpaper_id_handle(WCHAR *image_path)
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getUserImageWallpaperId(*pid, VFX_WSTR_MEM(image_path));
    return pid;
}

VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_user_video_wallpaper_id_handle(WCHAR *video_path)
{
    VappWallpaperId *pid = NULL;
    VFX_SYS_NEW(pid, VappWallpaperId);
    VappLiveWallpaperContentProvider::getUserVideoWallpaperId(*pid, VFX_WSTR_MEM(video_path));
    return pid;
}

void vapp_wallpaper_provider_set_usb_mass_storage_mode(MMI_BOOL isMassStorageMode)
{
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    setting->setUsbMassStorageMode((MMI_TRUE == isMassStorageMode) ? VFX_TRUE : VFX_FALSE);
}

MMI_BOOL vapp_wallpaper_provider_activate_by_vm(CHAR *packageName, VappWallpaperSrcEnum usage)
{
#if defined(__MMI_VUI_WALLPAPER_MRE__)
    VappWallpaperId wid;
    wid.assignWith(VAPP_WALLPAPER_FACTORY_MRE, packageName);
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    setting->setDefaultWallpaper(usage, wid, setting);

    #ifdef __COSMOS_MMI_PACKAGE__
    setting->notifyWallpaperUpdate(usage);
    #endif
    
    return MMI_TRUE;
#else
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_VAPP_WALLPAPER_ACTIVATE_BY_VM_FAILED_WITH_NO_MRE_WALLPAPER);
    return MMI_FALSE;
#endif
}

MMI_BOOL vapp_wallpaper_provider_mre_is_activated(CHAR *packageName, VappWallpaperSrcEnum usage)
{
#if defined(__MMI_VUI_WALLPAPER_MRE__)
    // construct corresponding wallpaper ID of the given package
    const VappWallpaperId checkWid(VAPP_WALLPAPER_FACTORY_MRE, packageName);

    // query active wallpaper id
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    const VappWallpaperId currentWid = setting->getDefaultWallpaper(usage, setting);

    // return compare result
    MMI_BOOL ret = (currentWid == checkWid) ? MMI_TRUE : MMI_FALSE;
    kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_3, "[Wallpaper] vapp_wallpaper_provider_mre_is_activated ret=%d usage=%d pakage=%s", ret, usage, packageName);
    return ret;
#else
    return MMI_FALSE;
#endif
}

} /* extern "C" */
