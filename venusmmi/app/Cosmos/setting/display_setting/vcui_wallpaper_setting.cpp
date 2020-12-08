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
 *  vcui_wallpaper_setting.cpp
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcui_wallpaper_setting.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_wallpaper_setting_method.h"
#include "vapp_wallpaper_id.h"
#include "vapp_wallpaper_setting_provider.h"
#include "vapp_wallpaper_content_provider.h"

#include "vcui_imgedt_gprot.h"
#include "vcp_global_popup.h"
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "GlobalResDef.h"
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#include "mdi_video.h"
#include "Vcui_gallery_gprot.h"
#include "mmi_rp_vapp_setting_def.h"
#include "UCMSrvGprot.h"
#endif //__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
}
#include "vapp_nmgr_gprot.h" // for vapp_nmgr_global_popup_show_confirm_two_button_id

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define WALLPAPER_SETTING_CUI_TEMP_DRIVE      (SRV_FMGR_PUBLIC_DRV)
#define WALLPAPER_SETTING_CUI_TEMP_FOLDER     ("Settings")
#define WALLPAPER_SETTING_CUI_TEMP_FILENAME   ("WallTemp")
#define WALLPAPER_SETTING_CUI_TEMP_FILE_TYPE  ("jpg")
#define WALLPAPER_SETTING_WARNING_MAX_SIZE  1024*250

typedef struct
{
    VfxU32 width;
    VfxU32 height;    
} vcui_wallpaper_default_size;

const static vcui_wallpaper_default_size g_vcui_wallpaper_default_size[CUI_WALLPAPER_SETTING_SCREEN_TYPE_END] =
{
        {LCD_HEIGHT, LCD_HEIGHT},
        {LCD_WIDTH,  LCD_HEIGHT}
};

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
mmi_id vcui_wallpaper_setting_create(mmi_id parent_gid, cui_wallpaper_setting_create_struct *data)
{
    if (!data || !data->filename)
	{
	    return GRP_ID_INVALID;
	}
    
    #ifdef __DRM_SUPPORT__        
    if (!VappWpSettingFileDirectSetting::isDRMVaild(data->filename))
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE, 
        VFX_WSTR_RES(STR_GLOBAL_DRM_PROHIBITED).getBuf());
        
        return GRP_ID_INVALID;
    }
    #endif /* __DRM_SUPPORT__ */

    #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VfxU16 res_type = srv_fmgr_types_find_group_by_filename_str(data->filename);   
    if (res_type == FMGR_GROUP_VIDEO)
    {
        mmi_id cui_id = VfxAppLauncher::createCui(
                                            VCUI_WALLPAPER_SETTING,
                                            VFX_OBJ_CLASS_INFO(VappVideoWallpaperSettingCui),
                                            parent_gid,
                                            data,
                                            sizeof(*data));
        return cui_id; 
    }
    
    #endif //__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__

    VfxBool shouldSkipClipperCheck = VFX_FALSE;
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__)
    if(FMGR_TYPE_MAV == srv_fmgr_types_find_type_by_filepath(data->filename))
    {
        shouldSkipClipperCheck = VFX_TRUE;
    }
    #endif
    
    #if defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
    if (!shouldSkipClipperCheck && cui_vapp_imgclip_is_file_support(data->filename) != CUI_IMGEDT_OK)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE, 
        VFX_WSTR_RES(STR_GLOBAL_UNSUPPORTED_FORMAT).getBuf());
        
        return GRP_ID_INVALID;
    }
    #endif /* __MMI_COSMOS_IMAGECLIPPER__ && !defined(__LOW_COST_SUPPORT_COMMON__) */   

    if(gdi_image_check_image_file_valid((CHAR*)data->filename) == MMI_FALSE)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE, 
        VFX_WSTR_RES(STR_GLOBAL_UNSUPPORTED_FORMAT).getBuf());
        
        return GRP_ID_INVALID;
    }
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_WALLPAPER_SETTING,
                                        VFX_OBJ_CLASS_INFO(VappWallpaperSettingCui),
                                        parent_gid,
                                        data,
                                        sizeof(*data));
    return cui_id;
}

void vcui_wallpaper_setting_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}
void vcui_wallpaper_setting_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappWallpaperSettingCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWallpaperSettingCui", VappWallpaperSettingCui, VfxCui);
    
void VappWallpaperSettingCui::onDeinit()
{
    if (!m_isSetProcessing)
    {
        clearTempFile();	
    }

#if defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
    if (m_imgClipperId)
	{
	    cui_vapp_imgclip_close(m_imgClipperId);
        m_imgClipperId = 0;
	}
#endif //defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
}
void VappWallpaperSettingCui::onRun(void* args, VfxU32 argSize)
{
    cui_wallpaper_setting_create_struct *data = (cui_wallpaper_setting_create_struct*)args;
    ASSERT(data && data->filename);
    
    m_screenType = data->screen_type;
    m_filename = VFX_WSTR_MEM(data->filename);
    m_userData = data->user_data;

    VfxSize imgSize;
    gdi_image_get_dimension_file((CHAR*)m_filename.getBuf(), &imgSize.width, &imgSize.height);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onRun width %d, height %d", imgSize.width, imgSize.height);
    
    if (imgSize.width == 0 || imgSize.height == 0)
    {
        showErrorConfirmPopup(STR_GLOBAL_INVALID_FORMAT);
        return;
    }

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__)
    // MAV files should direct set, no image clipper,
    // since image clipper will export only 1st frame.
    if(FMGR_TYPE_MAV == srv_fmgr_types_find_type_by_filepath((const WCHAR*)m_filename.getBuf()))
    {
        directlySet(m_filename);
        #if !defined(__LOW_COST_SUPPORT_COMMON__)
        onSettingFinished(VAPP_WALLPAPER_SETTING_NO_ERROR);
        #endif
        return;
    }
#endif
#if !defined(__MMI_COSMOS_IMAGECLIPPER__) && defined(__LOW_COST_SUPPORT_COMMON__)
   SRV_FMGR_FILEINFO_HANDLE handle;
   srv_fmgr_fileinfo_create((const WCHAR*)m_filename.getBuf(), &handle);
   VfxU32 size = srv_fmgr_fileinfo_get_size(handle);

    if(size > WALLPAPER_SETTING_WARNING_MAX_SIZE)
    {
        vapp_nmgr_global_popup_show_confirm_two_button_id(
            MMI_SCENARIO_ID_HIGH_SCRN,
            VCP_POPUP_TYPE_WARNING, 
            STR_ID_VAPP_WALLPAPER_SETTING_CONFIRM, 
            STR_ID_VAPP_WALLPAPER_SETTING_CONTINUE, 
            STR_GLOBAL_CANCEL,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            &VappWallpaperSettingCui::onConfirmPopup,
            this);
        return;
    }
#endif

#if defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] Prepare image clipper CUI");
    initFolder();
    clearTempFile();

    // Launch image clipper CUI
    cui_imgclip_launch_struct arg;
    arg.scr_file_path = (U8*)m_filename.getBuf();
        
    m_imgClipperId = cui_vapp_imgclip_create(getGroupId(), &arg);
    
    cui_vapp_imgclip_set_ratio_fixed(m_imgClipperId, MMI_TRUE);
    
    m_tempFilename.setEmpty();
    m_tempFilename.format(
        "%c:\\%s\\%s.%s",
        WALLPAPER_SETTING_CUI_TEMP_DRIVE,
        WALLPAPER_SETTING_CUI_TEMP_FOLDER,
        WALLPAPER_SETTING_CUI_TEMP_FILENAME,
        WALLPAPER_SETTING_CUI_TEMP_FILE_TYPE);
    
    cui_vapp_imgclip_set_dest_path(m_imgClipperId, (U8*)m_tempFilename.getBuf());

    VfxU32 maxHeight = g_vcui_wallpaper_default_size[m_screenType].height;
    VfxU32 maxWidth = g_vcui_wallpaper_default_size[m_screenType].width;

    cui_vapp_imgclip_set_ratio(m_imgClipperId, maxWidth, maxHeight);
    cui_vapp_imgclip_set_dest_size(m_imgClipperId, maxWidth, maxHeight);
    
    cui_vapp_imgclip_run(m_imgClipperId);
#else
    directlySet(m_filename);
#endif /* defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__) */
}

#if !defined(__MMI_COSMOS_IMAGECLIPPER__) && defined(__LOW_COST_SUPPORT_COMMON__)
void VappWallpaperSettingCui::onConfirmPopup(VfxId id, void *userData)
{
   
    VappWallpaperSettingCui* wallpapersetting = (VappWallpaperSettingCui*)userData;
    switch (id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        wallpapersetting->onSettingFinished(VAPP_WALLPAPER_SETTING_NO_ERROR);  
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_POPUP_BUTTON_NO_PRESSED:
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
        wallpapersetting->postEvent(EVT_ID_CUI_WALLPAPER_SETTING_ERROR, CUI_WALLPAPER_SETTING_NO_ERROR);
        break;
    default:
        break;
    }
}
#endif

void VappWallpaperSettingCui::initFolder()
{
#if !defined(__LOW_COST_SUPPORT_COMMON__)
    /* Create cache folder */
    VfxWString path = VFX_WSTR_EMPTY;
    path.format("%c:\\%s", WALLPAPER_SETTING_CUI_TEMP_DRIVE, WALLPAPER_SETTING_CUI_TEMP_FOLDER);
      
    FS_HANDLE fsHandle = FS_Open(path.getBuf(), FS_OPEN_DIR | FS_READ_ONLY);
        
    /* Folder Exists */
    if (fsHandle > 0)
    {
        VfxS32 folderAttribute = FS_GetAttributes(path.getBuf());
        if (!(folderAttribute & FS_ATTR_DIR) || !(folderAttribute & FS_ATTR_HIDDEN))
    	{
            FS_SetAttributes(path.getBuf(), FS_ATTR_DIR | FS_ATTR_HIDDEN);	
    	}

        FS_Close(fsHandle);
    }
    /* Folder Does Not Exist */
    else if (FS_CreateDir(path.getBuf()) == FS_NO_ERROR)
    {
        /* Create Success */
        FS_SetAttributes(path.getBuf(), FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }    
#endif // !defined(__LOW_COST_SUPPORT_COMMON__)
}
void VappWallpaperSettingCui::directlySet(VfxWString filename)
{
    m_isSetProcessing = VFX_TRUE;
    
#ifdef __LOW_COST_SUPPORT_COMMON__  
    onSettingFinished(VAPP_WALLPAPER_SETTING_NO_ERROR);
#else 
    VappWallpaperSettingInterface *wpSettingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wpSettingInterface->m_signalSettingFinished.connect(this, &VappWallpaperSettingCui::onSettingFinished);
    VappWpSetErrorCode errorCode = wpSettingInterface->setWallpaperFile((VappWallpaperType)m_screenType, filename);
    if (errorCode != VAPP_WALLPAPER_SETTING_NO_ERROR)
    {
        m_isSetProcessing = VFX_FALSE;
        showErrorConfirmPopup(wpSettingInterface->getErrorString(errorCode));
    }

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] directlySet %d", errorCode);
#endif  /*__LOW_COST_SUPPORT_COMMON__*/
    
}

void VappWallpaperSettingCui::clearTempFile()
{
#if !defined(__LOW_COST_SUPPORT_COMMON__)
    // Delete temp file
    VfxWString tempFileFilter = VFX_WSTR_EMPTY;
    tempFileFilter.format(
        "%c:\\%s\\%s.*",
        WALLPAPER_SETTING_CUI_TEMP_DRIVE,
        WALLPAPER_SETTING_CUI_TEMP_FOLDER,
        WALLPAPER_SETTING_CUI_TEMP_FILENAME);

    FS_HANDLE file_hnd;    
    FS_DOSDirEntry file_info;
    WCHAR filename[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)];    
    memset(filename, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    
    // Search for temp file
    file_hnd = FS_FindFirst(
                (const WCHAR*)tempFileFilter.getBuf(),
                0,
                0,
                &file_info,
                (WCHAR*)filename,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);    

    if (file_hnd >= 0)
    {
        do
    	{
            // Prepare temp file name
            VfxWString tempFile = VFX_WSTR_EMPTY;
            tempFile.format(
                "%c:\\%s\\",
                WALLPAPER_SETTING_CUI_TEMP_DRIVE,
                WALLPAPER_SETTING_CUI_TEMP_FOLDER);
    	    tempFile += VFX_WSTR_MEM(filename);

            // Delete temp file
            VfxS32 attribute = FS_GetAttributes(tempFile.getBuf());
            if (attribute & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes(tempFile.getBuf(), (U8) (attribute & ~(FS_ATTR_READ_ONLY)));
            }
            if(FS_Delete((const WCHAR*)tempFile.getBuf()) < FS_NO_ERROR)
            {
                MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] Delete failed");
               return;
            }       

        }
        while (FS_FindNext(file_hnd, &file_info, (U16*)filename, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH) == FS_NO_ERROR);
    }
    FS_FindClose(file_hnd);
#endif //!defined(__LOW_COST_SUPPORT_COMMON__)
}


#if defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
mmi_ret VappWallpaperSettingCui::onProc(mmi_event_struct *evt)
{
    cui_imgclip_event_struct *clipperEvt = (cui_imgclip_event_struct*)evt;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onProc %d", clipperEvt->evt_id);
    switch (evt->evt_id)
    {     
        case EVT_ID_CUI_IMGCLIP_SAVE_NEW:
        case EVT_ID_CUI_IMGCLIP_SAVE_OVERWRITE:
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onProc EVT_ID_CUI_IMGCLIP_SAVE_NEW %d", clipperEvt->result);
            if (clipperEvt->result != CUI_IMGEDT_OK)
            {
                showErrorConfirmPopup(cui_vapp_imgclip_get_error_string(m_imgClipperId, clipperEvt->result));
                postEvent(EVT_ID_CUI_WALLPAPER_SETTING_ERROR, CUI_WALLPAPER_SETTING_FAIL_TO_SAVE);
            }
            else
            {
                directlySet(m_tempFilename);
            }
            return MMI_RET_DONT_CARE;
        }
            
        case EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST:
            // Operation of image clipper is finished
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onProc EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST");
            postEvent(EVT_ID_CUI_WALLPAPER_SETTING_CANCEL, CUI_WALLPAPER_SETTING_NO_ERROR);    //IMGCLIP CLOSE
            break;
    		
    	default:
            break;		
    }
    return MMI_RET_OK;
}
#endif //defined(__MMI_COSMOS_IMAGECLIPPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)

void VappWallpaperSettingCui::postEvent(cui_wallpaper_setting_event_enum event, cui_wallpaper_setting_error_enum error)
{
    cui_wallpaper_setting_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, event, getGroupId());
    evt.error_code = error;
    evt.user_data = m_userData;
    postToCaller((mmi_group_event_struct*)&evt);
}

void VappWallpaperSettingCui::onSettingFinished(VfxU8 error)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onSettingFinished %d", error);
    m_isSetProcessing = VFX_FALSE;
    
    if (error == VAPP_WALLPAPER_SETTING_NO_ERROR)
	{          
#ifdef __LOW_COST_SUPPORT_COMMON__  
        // Adopt setting provider
        VappWallpaperId wid;

        VappLiveWallpaperContentProvider::getUserWallpaperId(wid, m_filename);
        VappWallpaperSettingProvider *provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
        VappWallpaperSrcEnum src;
        src = VAPP_WALLPAPER_HOME_SCREEN == (VappWallpaperType)m_screenType ? VAPP_WALLPAPER_SRC_HOMESCREEN : VAPP_WALLPAPER_SRC_LOCK;
        provider->setDefaultWallpaper(
        src,
        wid,
        this);
        
        provider->notifyWallpaperUpdate(src);
        
#endif   

            
        postEvent(EVT_ID_CUI_WALLPAPER_SETTING_DONE, CUI_WALLPAPER_SETTING_NO_ERROR);
	}
    else
    {
    
        VappWallpaperSettingInterface *wpSettingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
        wpSettingInterface->restoreWallpaper((VappWallpaperType)m_screenType);
        showErrorConfirmPopup(STR_GLOBAL_FAILED_TO_SAVE);
    }
}

// Display the error popup, send EVT_ID_CUI_WALLPAPER_SETTING_ERROR after user confirmed
void VappWallpaperSettingCui::showErrorConfirmPopup(VfxResId stringId)
{
    mmi_frm_nmgr_balloon(
    MMI_SCENARIO_ID_DEFAULT,
    MMI_EVENT_INFO_BALLOON,
    MMI_NMGR_BALLOON_TYPE_FAILURE, 
    VFX_WSTR_RES(stringId).getBuf());

    postEvent(EVT_ID_CUI_WALLPAPER_SETTING_ERROR, m_errorCode);
}

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
/***************************************************************************** 
 * VappVideoWallpaperSettingCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappVideoWallpaperSettingCui", VappVideoWallpaperSettingCui, VfxCui);
void VappVideoWallpaperSettingCui::onRun(void* args, VfxU32 argSize)
{
    m_rcvData = (cui_wallpaper_setting_create_struct*)args;
    ASSERT(m_rcvData && m_rcvData->filename);

    if (!m_prewScr)
    {
        VFX_OBJ_CREATE_EX(m_prewScr, VappGalleryVideoPreviewScr, this, (m_rcvData));
        m_prewScr->show();
    }
}

/*****************************************************************************
 * Class Implementation of VappGalleryVideoPreviewPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryVideoPreviewPage", VappGalleryVideoPreviewPage, VfxPage);

VappGalleryVideoPreviewPage::VappGalleryVideoPreviewPage()
{
}

VappGalleryVideoPreviewPage::VappGalleryVideoPreviewPage(cui_wallpaper_setting_create_struct* rcvData)
    : m_rcvData(rcvData), m_wallpaperType((VappWallpaperType)rcvData->screen_type),
    m_fileName(VFX_WSTR_MEM(rcvData->filename)), m_activeLiveWallpaper(NULL)//, m_questionPop(NULL)
{
}

void VappGalleryVideoPreviewPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *titleBar = NULL;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    WCHAR* name = srv_fmgr_path_get_filename_ptr((WCHAR *)(m_fileName.getBuf()));        
    titleBar->setTitle(VFX_WSTR_MEM(name));
    setTopBar(titleBar);

    m_isSeted = VFX_FALSE;
    createToolbar();    

    setBgColor(VFX_COLOR_BLACK);
    setTranslucent(VFX_TRUE);
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryVideoPreviewPage::devPlugOutHdlr, this);
}

// Create wallpaper preview page tool bar.
void VappGalleryVideoPreviewPage::createToolbar()
{
    VcpToolBar *tbar = NULL;
    VFX_OBJ_CREATE(tbar, VcpToolBar, this);
    tbar->addItem('OKAY', (VfxResId)STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    tbar->addItem('BACK', (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    tbar->m_signalButtonTap.connect(this, &VappGalleryVideoPreviewPage::onToolbarClicked);
    setBottomBar(tbar);
}

void VappGalleryVideoPreviewPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryVideoPreviewPage::devPlugOutHdlr, this);
    VfxPage::onDeinit();
}

mmi_ret VappGalleryVideoPreviewPage::devPlugOutHdlr(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
	{
	    VappGalleryVideoPreviewPage *page = VFX_OBJ_DYNAMIC_CAST((VfxObject*)evt->user_data, VappGalleryVideoPreviewPage);
        if (page)
    	{            
            page->postEvent(EVT_ID_CUI_WALLPAPER_SETTING_ERROR, CUI_WALLPAPER_SETTING_NO_ERROR);        
    	}
	}
    return MMI_RET_OK;
}


void VappGalleryVideoPreviewPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    // register the UCM.
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_INDICATION, &VappGalleryVideoPreviewPage::onEvent, this); 
    m_isEntered = VFX_FALSE;
    m_isVideoOpened = VFX_FALSE;
    if(!m_fileName.isEmpty() && NULL == m_activeLiveWallpaper)
    {
        // video wallpaper & live wallpaper requires re-creation
        createWallpaperFrameFromInfo();
    }
    if (!m_fileName.isEmpty() && NULL != m_activeLiveWallpaper)
    {
        m_activeLiveWallpaper->openFile(m_fileName);
    }
    

    setToolBarUnHittable(VFX_TRUE);
}

void VappGalleryVideoPreviewPage::onEntered()
{
    VfxPage::onEntered();
    
    m_isEntered = VFX_TRUE;
    if (m_isVideoOpened)
    {
        playVideo(m_activeLiveWallpaper, m_openStatus);
    }
}


// Set some feature option and create the video player.
void VappGalleryVideoPreviewPage::createWallpaperFrameFromInfo()
{
    VFX_OBJ_CLOSE(m_activeLiveWallpaper);

    VappVideoPlayerPlayOption option;
    if (VAPP_WALLPAPER_HOME_SCREEN == m_wallpaperType || VAPP_WALLPAPER_LOCK_SCREEN == m_wallpaperType)
    {
        option.configAsWallpaperVideoPreview();
    }

    VFX_OBJ_CREATE_EX(m_activeLiveWallpaper, VappVideoPlayerComponent, this, (option));
    m_activeLiveWallpaper->setPos(0, 0);
    m_activeLiveWallpaper->setSize(LCD_WIDTH, LCD_HEIGHT);
    m_activeLiveWallpaper->m_signalFileOpened.connect(this, &VappGalleryVideoPreviewPage::onVideoOpened);
    m_activeLiveWallpaper->m_signalPlaybackFinished.connect(this, &VappGalleryVideoPreviewPage::onVideoFinished);
}

void VappGalleryVideoPreviewPage::onExited2()
{
    // register the UCM.
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_INDICATION, &VappGalleryVideoPreviewPage::onEvent, this); 

    if(m_activeLiveWallpaper)
    {
        m_activeLiveWallpaper->closeFile();
        VFX_OBJ_CLOSE(m_activeLiveWallpaper);
    }    
    if (m_isSeted)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] video wallpaper: %s is set", m_fileName.getBuf());
        VappWallpaperSettingInterface *wpSettingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);

        //update /kemy
    }
    
    VfxPage::onExited2();
}

void VappGalleryVideoPreviewPage::onExit(VfxBool isBackward)
{
    if (m_activeLiveWallpaper)
    {
      m_activeLiveWallpaper->pause();
      m_activeLiveWallpaper->swithVideoLayerToSW(VFX_TRUE);
    }
    VfxPage::onExit(isBackward);
}

void VappGalleryVideoPreviewPage::onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    setToolBarUnHittable(VFX_FALSE);
    m_openStatus = result;
    if(MDI_RES_VDOPLY_SUCCEED != m_openStatus &&
       MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != m_openStatus)
    {
        setOKayStatus(VFX_FALSE);
        return;
    }

    m_isVideoOpened = VFX_TRUE;
    if (m_isEntered)
    {
        playVideo(sender, m_openStatus);
    }
}

void VappGalleryVideoPreviewPage::playVideo(VappVideoPlayerComponent *player, MDI_RESULT openStatus)
{
    MDI_RESULT playResult = MDI_RES_VDOPLY_SUCCEED;
    if(player && MDI_RES_VDOPLY_SUCCEED == openStatus)
    {
        playResult = player->play();
    }
    if(MDI_RES_VDOPLY_SUCCEED != playResult &&
       MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != playResult)
    {
        setOKayStatus(VFX_FALSE);
    }
    else
    {
        setOKayStatus(VFX_TRUE);
    }
}

void VappGalleryVideoPreviewPage::onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    if(MDI_RES_VDOPLY_SUCCEED != result &&
       MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != result)
    {
        //disableOKButton();
        postEvent(EVT_ID_CUI_WALLPAPER_SETTING_CANCEL, CUI_WALLPAPER_SETTING_NO_ERROR);
  		return ;
    }
}

void VappGalleryVideoPreviewPage::setOKayStatus(VfxBool status)
{
    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    VcpToolBar *tbar = VFX_OBJ_DYNAMIC_CAST(bar, VcpToolBar);
    if(tbar)
    {
        tbar->setDisableItem('OKAY', !status);
    }
}

void VappGalleryVideoPreviewPage::setToolBarUnHittable(VfxBool hittable)
{
    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    VcpToolBar *tbar = VFX_OBJ_DYNAMIC_CAST(bar, VcpToolBar);
    tbar->setIsUnhittable(hittable);
}

// handle the UCM
mmi_ret VappGalleryVideoPreviewPage::onEvent(mmi_event_struct *param)
{
    VappGalleryVideoPreviewPage *pThis = VFX_OBJ_DYNAMIC_CAST(((VfxObject*)param->user_data), VappGalleryVideoPreviewPage);
    if(NULL == pThis)
    {
        return MMI_TRUE;
    }

    switch(param->evt_id)
    {
        case EVT_ID_SRV_UCM_INDICATION:
        // handle background call finish to resume video
        if(NULL != pThis->m_activeLiveWallpaper)
        {
            srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)param;
            if (ind->ind_type == SRV_UCM_RELEASE_IND && !srv_ucm_is_any_call())
            {
                MDI_RESULT playResult = MDI_RES_VDOPLY_SUCCEED;
                playResult = pThis->m_activeLiveWallpaper->play();

                pThis->setOKayStatus(MDI_RES_VDOPLY_SUCCEED == playResult ||
                                          MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT == playResult);
            }
        }
        break;
    }

    return MMI_TRUE;

}


void VappGalleryVideoPreviewPage::onToolbarClicked(VfxObject* sender, VfxId btnId)
{
    if('OKAY' == btnId)
    {
        if (m_wallpaperType == VAPP_WALLPAPER_HOME_SCREEN|| m_wallpaperType == VAPP_WALLPAPER_LOCK_SCREEN
            || m_wallpaperType == VAPP_VIDEO_PWR_ON_SCREEN || m_wallpaperType == VAPP_VIDEO_PWR_OFF_SCREEN)
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] VappGalleryVideoPreviewPage::onToolbarClicked OK");
            setVideoFileName(m_fileName);
        }
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
        #endif

       return ;
    }
    else if('BACK' == btnId)
    {
        postEvent(EVT_ID_CUI_WALLPAPER_SETTING_CANCEL, CUI_WALLPAPER_SETTING_NO_ERROR);
        return;
    }
	
    VFX_DEV_ASSERT(VFX_FALSE);  // unrecognized command
}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappGalleryVideoPreviewPage::postEvent(cui_wallpaper_setting_event_enum event, cui_wallpaper_setting_error_enum error)
{
    cui_wallpaper_setting_event_struct evt;
    VfxApp* thisApp = getApp();
    VfxId groupId = thisApp->getGroupId();
    MMI_FRM_INIT_GROUP_EVENT(&evt, event, groupId);
    evt.error_code = error;
    evt.user_data = m_rcvData->user_data;
    thisApp->postToCaller((mmi_group_event_struct*)&evt);
}


void VappGalleryVideoPreviewPage::setVideoFileName(VfxWString filename)
{
    if (srv_fmgr_fs_path_exist(filename.getBuf()) < 0)
    {
        postEvent(EVT_ID_CUI_WALLPAPER_SETTING_ERROR, CUI_WALLPAPER_SETTING_FAIL_TO_SAVE);        
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_FAILED).getBuf());
        return ;
    }
    if(VAPP_WALLPAPER_HOME_SCREEN == m_wallpaperType ||
           VAPP_WALLPAPER_LOCK_SCREEN == m_wallpaperType)
    {
         // store the wallpaper id
        VappWallpaperId id;
        VappLiveWallpaperContentProvider::getUserVideoWallpaperId(id, filename);
        
        VappWallpaperSettingProvider *wallpaperStore = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
        const VappWallpaperSrcEnum src = (m_wallpaperType == CUI_WALLPAPER_SETTING_HOME_SCREEN) ? VAPP_WALLPAPER_SRC_HOMESCREEN : VAPP_WALLPAPER_SRC_LOCK;
        wallpaperStore->setDefaultWallpaper(src, id, this);
    }
    else if (VAPP_VIDEO_PWR_ON_SCREEN == m_wallpaperType ||
           VAPP_VIDEO_PWR_OFF_SCREEN == m_wallpaperType)
    {
        VappWallpaperSettingInterface *wpSettingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
        wpSettingInterface->setWallpaperFile(m_wallpaperType, filename);

    }

	onSettingFinished();
}

void VappGalleryVideoPreviewPage::onSettingFinished(void)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Wallpaper CUI] onSettingFinished");
    m_isSeted = VFX_TRUE;
    postEvent(EVT_ID_CUI_WALLPAPER_SETTING_DONE, CUI_WALLPAPER_SETTING_NO_ERROR);

}
#endif // __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
