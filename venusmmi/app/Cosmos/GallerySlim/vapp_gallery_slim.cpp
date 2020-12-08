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
 *  vapp_gallery_app.cpp
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
#include "vtst_rt_main.h"
#include "Vfx_config.h"

extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
}

#ifdef __MMI_GALLERY_SLIM__

#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_setting.h"
#include "vapp_gallery_slim_index.h"
#include "vapp_gallery_slim_shooting.h"
#include "vapp_gallery_slim_viewer.h"
#include "vapp_gallery_slim_player.h"
#include "vapp_gallery_slim_video.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"

extern "C"
{
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "cbm_api.h"
#include "AppMgrSrvGprot.h"
#include "DLAgentSrvGProt.h"
#include "UcmSrvGprot.h"
#include "DmSrvGprot.h"
#include "GpioSrvGprot.h"

#if defined(__MMI_VIDEO_STREAM__) && defined(__MMI_URI_AGENT__)
#include "UriAgentSrvGprot.h"
#include "AsciiProt.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "vapp_usb_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif

#include "vapp_screen_lock_gprot.h"
}

#include "vapp_fmgr_table.h"
#include "vapp_wallpaper_setting_method_gprot.h"

extern "C"
{
#include "MMI_media_app_trc.h"
#include "app_url.h"
#include "app_str.h"
}

/***************************************************************************** 
 * Macro
 *****************************************************************************/
#ifdef __MMI_USB_SUPPORT__
#define CHECK_MASS_STORAGE_AND_RETURN_NULL() if(srv_usb_is_in_mass_storage_mode())\
                                             {\
                                                vapp_usb_unavailable_popup(SRV_USB_ERROR_UNAVAILABLE);\
                                                return NULL;\
                                             }
#else
#define CHECK_MASS_STORAGE_AND_RETURN_NULL()
#endif // __MMI_USB_SUPPORT__

/***************************************************************************** 
 * APP Global variable
 *****************************************************************************/
static kal_uint8 g_galleryCBMId = 0;    // APP id for CBM (network acces) this is NOT Venus APP id.

/***************************************************************************** 
 * Progressive Download (PDL)
 *****************************************************************************/
enum VappGalleryPDLSessionEnum
{
    INVALID_PGDL_SESSION_ID = -1,
};
#ifdef __MMI_VIDEO_PDL__
// Since PDL may be triggered when Application is not running,
// we use a global space to record running PDL session
class VappGalleryPDLState
{
public:
    S32 sessionId;             // PGDL session id, from DLAgentSrv
    mmi_id grpId;              // if launched, the group id of the VfxVappLauncher or VfxApp
    VfxBool hasLaunched;       // launched before due to PGDL. Resume PGDL would clear this flag.
                               // note this flag remains VFX_TRUE even if the app has been closed (e.g OOM)
    VfxBool isYouTube;

    WCHAR filePath[SRV_FMGR_PATH_BUFFER_SIZE];  // file path to the PGDL file
    
public:
    void reset();
    void resume();
    VfxBool isPlayerAlive() const;
    VfxBool isLaunched() const;
    VfxBool isRunning() const;
    const char *getAppIdString() const;
};
static VappGalleryPDLState g_galleryPDLState;

void VappGalleryPDLState::reset()
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_reset_pdl_state, session=%d", sessionId);
    sessionId = INVALID_PGDL_SESSION_ID;
    grpId = GRP_ID_INVALID;
    hasLaunched = VFX_FALSE;
    isYouTube = VFX_FALSE;

    kal_mem_set(filePath, 0, sizeof(filePath));
}

void VappGalleryPDLState::resume()
{
    // reset flag so that we can launch again
    hasLaunched = VFX_FALSE;
}

VfxBool VappGalleryPDLState::isLaunched() const
{
    return hasLaunched;
}

VfxBool VappGalleryPDLState::isPlayerAlive() const
{
    if(GRP_ID_INVALID == grpId)
    {
        return VFX_FALSE;
    }
    
    const VfxBool launching = VfxAppLauncher::getObject(grpId) != NULL;
    const VfxBool running = VfxApp::getObject(grpId) != NULL;
    return launching || running;
}

VfxBool VappGalleryPDLState::isRunning() const
{
    const VfxBool running = VfxApp::getObject(grpId) != NULL;
    return running;
}

const char *VappGalleryPDLState::getAppIdString() const
{
    #ifdef __MMI_VIDEO_PDL_YOUTUBE__
    if(isYouTube)
    {
        return "native.mtk.gallery.youtube.pgdl.player";
    }
    #endif

    return "native.mtk.gallery.video.player";
}
    
#endif // __MMI_VIDEO_PDL__

/***************************************************************************** 
 * APP Exported Function
 *****************************************************************************/
extern "C"
{
extern MMI_ID vapp_gallery_launch_cui_test(void* param, U32 param_size);

extern void vapp_gallery_image_viewer_launch_option_init(vapp_gallery_image_viewer_launch_option_struct *);
extern MMI_ID vapp_gallery_image_viewer_launch(const WCHAR* file_path, const vapp_gallery_image_viewer_launch_option_struct *option);
extern MMI_ID vapp_gallery_image_viewer_folder_launch(const WCHAR* folder_path, const vapp_gallery_image_viewer_launch_option_struct *option);
extern void vapp_gallery_video_player_launch_option_init(vapp_gallery_video_player_launch_option_struct *option);
extern MMI_ID vapp_gallery_video_player_launch(const WCHAR* file_path, const vapp_gallery_video_player_launch_option_struct *option);
extern void vapp_gallery_last_play_struct_init(vapp_gallery_last_play_struct * last_play_struct);

#if defined(__MMI_VIDEO_STREAM__) && defined(__MMI_URI_AGENT__)
static void vapp_gallery_rtsp_uri_handler(
                                srv_uriagent_appid_enum ura_appid,
                                char *url,
                                char *param,
                                srv_uriagent_options_enum options,
                                srv_uriagent_uri_request_hdlr_cb uri_agent_cb);
#endif

// Initialization during boot-up, be careful!
mmi_ret vapp_gallery_init(mmi_event_struct *event)
{
#if defined(__MMI_VIDEO_STREAM__)
    
#if defined(__MMI_URI_AGENT__)
    // register rtsp scheme handler
    srv_uriagent_err_enum uriAgentResult = srv_uriagent_register_hdlr_by_scheme("rtsp", &vapp_gallery_rtsp_uri_handler, MMI_FALSE);
    VFX_ASSERT(uriAgentResult == SRV_URIAGENT_ERR_OK);
#endif 

#ifdef __TCPIP__
    // register runtime app id with CBM.
    // this is required to apply data account (network access)
    cbm_app_info_struct info;
    memset(&info, 0, sizeof(info));
    info.app_str_id = STR_ID_VAPP_GALLERY_AP_NAME;
    info.app_icon_id = IMG_ID_VAPP_GALLERY_APP_ICON;
    info.app_type = DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_SKIP_CSD;
    kal_uint8 app_id = 0;
    kal_int8 ret = cbm_register_app_id_with_app_info(&info, &app_id);
    if(CBM_OK == ret)
    {
        g_galleryCBMId = app_id;
    }
#endif

#ifdef __MMI_VIDEO_PDL__
    g_galleryPDLState.reset();
#endif

#endif /* defined(__MMI_VIDEO_STREAM__) */

    return MMI_RET_OK;
}


// Launches Gallery application
MMI_ID vapp_gallery_launch(void* param, U32 param_size)
{
    // TEST:
    // return vapp_gallery_image_viewer_launch((const WCHAR*)L"D:\\Shooting\\SB_Default.gif", NULL);
    // return vapp_gallery_launch_cui_test(param, param_size);

    CHECK_MASS_STORAGE_AND_RETURN_NULL();

    // check scenario to prevent launch app to prevent strange UE
    // ex: [MAUI_03208778] launch player while phone locks
    const MMI_BOOL scenarioPreCheck = mmi_frm_is_scrn_priority_enough(MMI_SCENARIO_ID_DEFAULT);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] launch app senario check, appId[%d], res[%d], Line[%d]", VAPP_GALLERY, scenarioPreCheck, __LINE__);
    if(!scenarioPreCheck)
    {
        return GRP_ID_INVALID;
    }

    return VfxAppLauncher::launch(VAPP_GALLERY,
                                  VFX_OBJ_CLASS_INFO(VappGalleryApp),
                                  GRP_ID_ROOT);
}

mmi_ret vapp_gallery_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

class VappGalleryLaunchOption
{
public:
    VfxBool isRTSPLink;
    VfxBool isImageOnly;
    VfxBool isFolder;    
    VfxBool useQVGAVideoSpec;
    VfxBool disableSSE;
    VfxBool confirmScenario;
    VfxBool isYouTubeTitle;
    VfxBool contentIsImage;                        // hint for error handle. VFX_TRUE if content suppose to IMAGE. VFX_FALSE for video
    VfxBool forceEntryViewer; // default is VFX_FALSE. Choose first page according to file typ
                              // VFX_TRUE only if we want to use viewer page as 1st page. 
    FMGR_FILTER *fileFilter;
    filetypes_group_type_enum fileGroup;
    VfxS32 sortMethod;
    VfxS32 pdlSessionId;    // -1: not a PDL file, >= 0: PDL session id
    U64 startTimeHint;
    PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC userProc;
    void* userData;
    WCHAR filePath[1];      // TODO: union with VAPP_GALLERY_URL_MAX_BUF_LENGTH and SRV_FMGR_PATH_BUFFER_SIZE
};

static void _initGalleryLaunchOption(VappGalleryLaunchOption *option)
{
    if(NULL == option)
    {
        return;
    }

    option->sortMethod = FS_SORT_NAME;
    option->isRTSPLink = VFX_FALSE;
    option->isImageOnly = VFX_FALSE;
    option->isFolder = VFX_FALSE;
    option->useQVGAVideoSpec = VFX_FALSE;
    option->disableSSE = VFX_FALSE; 
    option->confirmScenario = VFX_FALSE;
    option->isYouTubeTitle = VFX_FALSE;
    option->contentIsImage = VFX_TRUE;
    option->forceEntryViewer = VFX_FALSE;
    option->fileFilter = NULL;
    option->fileGroup = FMGR_GROUP_IMAGE;
    option->pdlSessionId = INVALID_PGDL_SESSION_ID;
    option->startTimeHint = 0;
    option->userProc = NULL;
    option->userData = NULL;
    option->filePath[0] = NULL;
}


#if defined(__MMI_VIDEO_STREAM__)
static MMI_BOOL _vapp_gallery_can_connect_streaming_video()
{
#ifndef __MMI_VIDEO_STREAM__
    return MMI_FALSE;
#else

    // During phone call, video streaming should be blocked
#if !defined( __RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
           
        return MMI_FALSE;
    }
#endif // !defined( __RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)

    // Phone locked, disable all functions
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING)
    {
        return MMI_FALSE;
    }
#endif  // __DM_LAWMO_SUPPORT__

    return MMI_TRUE;
#endif  // __MMI_VIDEO_STREAM__
}
#endif

static MMI_ID _vapp_gallery_file_open_handler(
                            const WCHAR* filepath,
                            filetypes_file_type_enum filetype, 
                            MMI_BOOL fromFileMgr,
                            MMI_BOOL isFolder, 
                            MMI_BOOL content_is_image,
                            MMI_BOOL disable_SSE = MMI_FALSE, 
                            MMI_BOOL confirm_scenario = MMI_FALSE,
                            FMGR_FILTER *fileFilter = NULL,
                            S32 pdlSessionId = INVALID_PGDL_SESSION_ID,
                            U64 start_time_hint = 0,
                            PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC user_proc= NULL,
                            void* user_data = NULL
                            )
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_LAUNCH_VAPP_GALLERY_FILE_OPEN_HANDLER_S_D_D, filepath, filetype, fromFileMgr);
    // bring actual file path down to gallery ImageViewer
    if(NULL == filepath)
    {
        return vapp_gallery_launch(NULL, 0);
    }

    CHECK_MASS_STORAGE_AND_RETURN_NULL();

    const VfxS32 pathLen = mmi_wcslen(filepath) + 1;
    const VfxS32 optionBufLen = vfxMin((VfxS32)SRV_FMGR_PATH_BUFFER_SIZE, 
                                       (VfxS32)(pathLen * sizeof(WCHAR)))\
                                + sizeof(VappGalleryLaunchOption);

    // allocate continuous option struct
    VappGalleryLaunchOption *pOption = NULL;
    VFX_SYS_ALLOC_MEM(pOption, optionBufLen);
    VFX_ASSERT(pOption);
    _initGalleryLaunchOption(pOption);

    // filll option
    pOption->fileFilter = fileFilter;
    pOption->disableSSE = VFX_TRUE;
    pOption->confirmScenario = confirm_scenario ? VFX_TRUE : VFX_FALSE;
    filetypes_group_type_enum fileGroup = srv_fmgr_types_find_group_by_type(filetype);
    pOption->fileGroup = fileGroup;
    pOption->contentIsImage = content_is_image ? VFX_TRUE : VFX_FALSE;
    pOption->isRTSPLink = VFX_FALSE;
    pOption->isFolder = (MMI_TRUE == isFolder);
    pOption->pdlSessionId = pdlSessionId;

    // workaround for incorrect PDL filename
    if(INVALID_PGDL_SESSION_ID != pOption->pdlSessionId)
    {
        pOption->fileGroup = fileGroup = FMGR_GROUP_VIDEO;
    }

    #ifdef __MMI_VIDEO_PDL_YOUTUBE__
    pOption->isYouTubeTitle = g_galleryPDLState.isYouTube;
    #endif
    
    pOption->startTimeHint = start_time_hint;
    pOption->userProc = user_proc;
    pOption->userData = user_data;

#ifdef __MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__
    pOption->isImageOnly = (MMI_TRUE == fromFileMgr && fileGroup == FMGR_GROUP_IMAGE);
#else
    // [MAUI_03213430] work arround for Cosmos project
    // Recomcoder/Camcoder dose not parse last record vdieo or photo in Cosmos project
    // so it launch Gallery with Shooting folder while format phone or reboot, even there are some files in Shooting
    // in such case, always entry Image Viewer with image ONLY in project which split image and video in image viewer 
    #if defined(__LOW_COST_SUPPORT_COMMON__)
    const VfxBool videoContentWithFolder = VFX_FALSE;
    #else
    const VfxBool videoContentWithFolder = (MMI_FALSE == content_is_image && FMGR_TYPE_FOLDER == filetype);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] videoContentWithFolder[%d]", videoContentWithFolder);
    #endif
    pOption->isImageOnly = (content_is_image || videoContentWithFolder) ? MMI_TRUE : MMI_FALSE;
#endif
    if(fromFileMgr)
    {
        pOption->sortMethod = srv_fmgr_sort_get();
    }
    else
    {
        // camera case, sort by date/time
        pOption->sortMethod = FS_SORT_TIME;
    }
    
    mmi_wcsncpy(pOption->filePath, filepath, pathLen);

#ifdef __MMI_VIDEO_STREAM__
    // check if file type is allows
    if(FMGR_GROUP_STREAM == fileGroup && MMI_FALSE == _vapp_gallery_can_connect_streaming_video())
    {
        // cannot launch streaming video files
        return NULL;
    }
#endif

    // determine app id
    mmi_id appClsId = VAPP_GALLERY;
    do
    {    
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__)    
        // in SLIM project which supports video in image viewer, launch image viewer for better UE     
        pOption->forceEntryViewer= VFX_TRUE;
        appClsId = VAPP_GALLERY_IMAGE_VIEWER;        
    #else
        // [MAUI_03099926] split image viewer and video player for projects with small ASM memory configuration    
        pOption->forceEntryViewer= VFX_FALSE;
        if(FMGR_GROUP_VIDEO == fileGroup)
        {
            appClsId = VAPP_GALLERY_VIDEO_PLAYER;
        }
        else
        {
            // in case of file open, launch either video player or image viewer
            // does not launch full Gallery 
            appClsId = VAPP_GALLERY_IMAGE_VIEWER;
        }
    #endif

        // [MAUI_03213816] special case handle:
        // there is no conntent in Shooring folder 
        // Recorder passes Shooting folder while user press thumb, and then user inserts memory card with content
        // because image viewer's memory configuration is smaller than player, video always open failed in such case
        // use full gallery app id to insufficient memory to open file
        #if defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__)    
        if(!content_is_image && isFolder && NULL == fileFilter && !fromFileMgr)
        {
            // video case with shooting forlder launch
            appClsId = VAPP_GALLERY;
        }
        #endif

        #ifdef __MMI_VIDEO_STREAM__        
        // For RTSP streaming, launch by streaming app 
        if(FMGR_GROUP_STREAM == fileGroup)
        {            
            pOption->forceEntryViewer= VFX_FALSE;
            appClsId = VAPP_GALLERY_STREAM_PLAYER;
        }
        #endif
        #ifdef __MMI_VIDEO_PDL_YOUTUBE__
        // For YouTube, we use special player since we already know the memory config.
        if(INVALID_PGDL_SESSION_ID != pOption->pdlSessionId &&
        g_galleryPDLState.isYouTube)
        {            
            pOption->forceEntryViewer= VFX_FALSE;
            appClsId = VAPP_GALLERY_YOUTUBE_PGDL_PLAYER;
        }
        #endif
    }while(0);

    // check scenario to prevent launch app to prevent strange UE
    // ex: [MAUI_03208778] launch player while phone locks
    const MMI_BOOL scenarioPreCheck = mmi_frm_is_scrn_priority_enough(MMI_SCENARIO_ID_DEFAULT);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] launch app senario check, appId[%d], res[%d], Line[%d]", appClsId, scenarioPreCheck, __LINE__);

    mmi_id appId = GRP_ID_INVALID;
    do
    {
        if(!scenarioPreCheck)
        {
            break;
        }

        // ensure single-instance of Gallery/Viewer/Player application
        // Note that we still allow Gallery -> MMS CUI -> player scenario,
        // since VAPP_GALLERY is different from VAPP_GALLERY_VIDEO_PLAYER
        VfxAppLauncher::killApp(
            appClsId, 
            VFX_OBJ_CLASS_INFO(VappGalleryApp), 
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

        appId = VfxAppLauncher::launch( 
                                appClsId,
                                VFX_OBJ_CLASS_INFO(VappGalleryApp),
                                GRP_ID_ROOT, 
                                (void*)pOption,
                                optionBufLen);
    }while(0);

    VFX_SYS_FREE_MEM(pOption);    
    return appId;
}

void vapp_gallery_image_option_open_handler(mmi_menu_id item_id, 
                                            const WCHAR* filepath, 
                                            const srv_fmgr_fileinfo_struct* fileinfo)
{
    VFX_ASSERT(fileinfo);
    _vapp_gallery_file_open_handler(filepath, (filetypes_file_type_enum)fileinfo->type, MMI_TRUE, MMI_FALSE, MMI_TRUE);
}

void vapp_gallery_video_option_open_handler(mmi_menu_id item_id, 
                                            const WCHAR* filepath, 
                                            const srv_fmgr_fileinfo_struct* fileinfo)
{
    VFX_ASSERT(fileinfo);
    _vapp_gallery_file_open_handler(filepath, (filetypes_file_type_enum)fileinfo->type, MMI_TRUE, MMI_FALSE, MMI_FALSE);
}

void vapp_gallery_stream_option_open_handler(mmi_menu_id item_id, 
                                            const WCHAR* filepath, 
                                            const srv_fmgr_fileinfo_struct* fileinfo)
{
    VFX_ASSERT(fileinfo);
    _vapp_gallery_file_open_handler(filepath, (filetypes_file_type_enum)fileinfo->type, MMI_TRUE, MMI_FALSE, MMI_FALSE);
}

extern void vapp_gallery_image_viewer_launch_option_init(vapp_gallery_image_viewer_launch_option_struct *option)
{
    option->title_string = NULL; 
    option->content_is_image = MMI_TRUE;
    option->show_blank_page = MMI_TRUE;
    option->disable_SSE = MMI_FALSE;
    option->confirm_scenario = MMI_FALSE; 
    option->filter = NULL; 
}

extern MMI_ID vapp_gallery_image_viewer_launch(const WCHAR* file_path, const vapp_gallery_image_viewer_launch_option_struct *option)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(file_path);
    return _vapp_gallery_file_open_handler(file_path, fileType, MMI_FALSE, MMI_FALSE, option->content_is_image, option->disable_SSE, option->confirm_scenario, option->filter);
}

extern MMI_ID vapp_gallery_image_viewer_folder_launch(const WCHAR* folder_path, const vapp_gallery_image_viewer_launch_option_struct *option)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    return _vapp_gallery_file_open_handler(folder_path, FMGR_TYPE_FOLDER, MMI_FALSE, MMI_TRUE, option->content_is_image);
}

extern void vapp_gallery_video_player_launch_option_init(vapp_gallery_video_player_launch_option_struct *option)
{
    option->title_string = NULL;
    option->disable_SSE = MMI_FALSE;
    option->start_time_hint = 0;
    option->user_proc = NULL;
    option->user_data = NULL;
}

extern MMI_ID vapp_gallery_video_player_launch(const WCHAR* file_path, const vapp_gallery_video_player_launch_option_struct *option)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    if(NULL == file_path)
    {
        return vapp_gallery_launch(NULL, 0);
    }
    
    
    const VfxS32 pathLen = mmi_wcslen(file_path) + 1;
    const VfxS32 optionBufLen = vfxMin((VfxS32)SRV_FMGR_PATH_BUFFER_SIZE, 
                                       (VfxS32)(pathLen * sizeof(WCHAR)))\
                                        + sizeof(VappGalleryLaunchOption);
    
    // allocate continuous option struct
    VappGalleryLaunchOption *pOption = NULL;
    VFX_SYS_ALLOC_MEM(pOption, optionBufLen);
    VFX_ASSERT(pOption);
    _initGalleryLaunchOption(pOption);
    
    // filll option
    //pOption->disableSSE = option->disable_SSE ? VFX_TRUE : VFX_FALSE;
    pOption->disableSSE = VFX_TRUE;
    pOption->fileGroup = FMGR_GROUP_VIDEO;
    pOption->startTimeHint = option->start_time_hint;
    pOption->userProc = option->user_proc;
    pOption->userData = option->user_data;
    mmi_wcsncpy(pOption->filePath, file_path, pathLen);
    
    const mmi_id appClsId = VAPP_GALLERY_VIDEO_PLAYER;

    // check scenario to prevent launch app to prevent strange UE
    // ex: [MAUI_03208778] launch player while phone locks
    const MMI_BOOL scenarioPreCheck = mmi_frm_is_scrn_priority_enough(MMI_SCENARIO_ID_DEFAULT);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] launch app senario check, appId[%d], res[%d], Line[%d]", appClsId, scenarioPreCheck, __LINE__);
    
    mmi_id appId = GRP_ID_INVALID;
    do
    {
        if(!scenarioPreCheck)
        {
            break;
        }
        // launch
        appId = VfxAppLauncher::launch( 
                                    appClsId,
                                    VFX_OBJ_CLASS_INFO(VappGalleryApp),
                                    GRP_ID_ROOT, 
                                    (void*)pOption,
                                    optionBufLen);
    }while(0);

    VFX_SYS_FREE_MEM(pOption);    
    return appId;
}

extern void vapp_gallery_last_play_struct_init(vapp_gallery_last_play_struct * last_play_struct)
{
    last_play_struct->file_path = NULL;
    last_play_struct->last_play_time = 0;
}

#if defined(__MMI_VIDEO_STREAM__) && defined(__MMI_URI_AGENT__)
void vapp_gallery_rtsp_uri_handler(
    srv_uriagent_appid_enum ura_appid,
    char *url,
    char *param,
    srv_uriagent_options_enum options,
    srv_uriagent_uri_request_hdlr_cb uri_agent_cb)
{
    // uri_agent_cb is used to notify URL agent that handler process done
    // no matter whether launch streaming player successfully, make sure we calls uri_agent_cb at the end of this handler
    if(MMI_FALSE == _vapp_gallery_can_connect_streaming_video())
    { 
        if(uri_agent_cb != NULL)
        {
            uri_agent_cb(ura_appid, SRV_URIAGENT_APPID_STREAMING, SRV_URIAGENT_ERR_OK);
        }
        return; 
    }

    // TODO: show pop up AFTER enter video player
    // if option is options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP
    
    const VfxS32 urlLen = AsciiStrlen(url) + 1;
    const VfxS32 optionBufLen = (urlLen * sizeof(WCHAR))
                                + sizeof(VappGalleryLaunchOption);

    // allocate continuous option struct
    VappGalleryLaunchOption *pOption = NULL;
    VFX_SYS_ALLOC_MEM(pOption, optionBufLen);
    VFX_ASSERT(pOption);
    _initGalleryLaunchOption(pOption);
    // filll option
    
    pOption->fileGroup = FMGR_GROUP_STREAM;
    pOption->isRTSPLink = VFX_TRUE;
    pOption->useQVGAVideoSpec = VFX_TRUE;
    mmi_asc_n_to_ucs2((CHAR*)pOption->filePath, (CHAR*)url, urlLen);

    // check scenario to prevent launch app to prevent strange UE
    // ex: [MAUI_03208778] launch player while phone locks
    const MMI_BOOL scenarioPreCheck = mmi_frm_is_scrn_priority_enough(MMI_SCENARIO_ID_DEFAULT);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] launch app senario check, appId[%d], res[%d], Line[%d]", VAPP_GALLERY_STREAM_PLAYER, scenarioPreCheck, __LINE__);
    do
    {
        if(!scenarioPreCheck)
        {
            break;
        }
        // ensure single-instance of Gallery/Viewer/Player application
        // Note that we still allow Gallery -> MMS CUI -> player scenario,
        // since VAPP_GALLERY is different from VAPP_GALLERY_VIDEO_PLAYER
        VfxAppLauncher::killApp(
            VAPP_GALLERY_STREAM_PLAYER, 
            VFX_OBJ_CLASS_INFO(VappGalleryApp), 
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
        mmi_id appId = VfxAppLauncher::launch( 
                                VAPP_GALLERY_STREAM_PLAYER,
                                VFX_OBJ_CLASS_INFO(VappGalleryApp),
                                GRP_ID_ROOT, 
                                (void*)pOption,
                                optionBufLen);
    
    }while(0);
    
    VFX_SYS_FREE_MEM(pOption);
    if(uri_agent_cb != NULL)
    {
        uri_agent_cb(ura_appid, SRV_URIAGENT_APPID_STREAMING, SRV_URIAGENT_ERR_OK);
    }
    return;
}
#endif // defined(__MMI_VIDEO_STREAM__) && defined(__MMI_URI_AGENT__)

#ifdef __MMI_VIDEO_PDL__
/***************************************************************************** 
 * Global function for Progressive Download (PDL)
 *****************************************************************************/
static void vapp_gallery_reset_pdl_state(VappGalleryPDLState &pdlState)
{
    pdlState.reset();
}

static void vapp_gallery_pdl_notify_app(const VappGalleryPDLState &pdlState, vapp_gallery_event_enum event)
{
    const VfxU32 MAX_VIDEO_INSTANCE_NUM = 5;
    U32 instanceCount = srv_appmgr_query_instance_num(pdlState.getAppIdString());
    mmi_event_struct cancelEvent;
    kal_mem_set(&cancelEvent, 0, sizeof(cancelEvent));
    cancelEvent.evt_id = event;
    cancelEvent.size = sizeof(cancelEvent);
    cancelEvent.user_data = (void*)pdlState.sessionId;
    MMI_ID instances[MAX_VIDEO_INSTANCE_NUM] = {0};
    if(GRP_ID_INVALID != pdlState.grpId)
    {
        srv_appmgr_send_evt(pdlState.grpId, pdlState.grpId, &cancelEvent);
    }
    else if(MMI_RET_OK == srv_appmgr_query_instance_id(pdlState.getAppIdString(), instances, instanceCount) && instanceCount)
    {
        for(VfxU32 i = 0; i < instanceCount; ++i)
        {
            srv_appmgr_send_evt(instances[i], instances[i], &cancelEvent);
        }
    }
}

// download agent callback to initialize a download session
static BOOL vapp_gallery_pdl_da_video_filepath_hdlr(
                S32 session_id,
                S32 mime_type, 
                S32 mime_subtype, 
                PU16 filepath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PDL_VAPP_GALLERY_PDL_DA_VIDEO_FILEPATH_HDLR_CALLED_SESSION_ID_D, session_id);

    if(INVALID_PGDL_SESSION_ID == g_galleryPDLState.sessionId || !g_galleryPDLState.isPlayerAlive())
    {
        // begin a new session, and remember the file path
        g_galleryPDLState.sessionId = session_id;
        g_galleryPDLState.resume();
        vapp_gallery_pdl_notify_app(g_galleryPDLState, EVT_ID_VAPP_GALLERY_DA_RESUME);
        mmi_ucs2cpy((CHAR*)g_galleryPDLState.filePath, (CHAR*)filepath);
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_video_filepath_hdlr, session start, prev id = %d", g_galleryPDLState.sessionId);
    }
    else
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_video_filepath_hdlr, ignore by session %d", g_galleryPDLState.sessionId);
    }

    // note that we DID NOT launch gallery at this moment
    return TRUE;
}

// download agent callback for Video PDL files
// this callback may be repeatedly called
static void vapp_gallery_pdl_da_report_hdlr(
                S32 session_id,
                S32 status,
                S32 cause,
                U32 seq_num,
                U32 acc_size, 
                U32 total_size)
{ 
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PDL_VAPP_GALLERY_PDL_DA_REPORT_HDLR_WITH_SESSION_ID_D, session_id);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_report_hdlr status=%d cause=%d", status, cause);

    if(g_galleryPDLState.sessionId != session_id)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_report_hdlr session id does not match");
        return;
    }
    
    // is Gallery already running?
    U32 instanceCount = srv_appmgr_query_instance_num(g_galleryPDLState.getAppIdString());
    if(0 < instanceCount || g_galleryPDLState.isRunning())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PDL_VAPP_GALLERY_PDL_DA_REPORT_HDLR_PROGRESS_REPORT);
        // already running
        switch (status)
        {
        case SRV_DA_STATE_DOWNLOADING:
            // already handle download
            break;
        case SRV_DA_STATE_COMPLETE:
            g_galleryPDLState.reset();
            break;
        case SRV_DA_STATE_PAUSE:
            vapp_gallery_pdl_notify_app(g_galleryPDLState, EVT_ID_VAPP_GALLERY_DA_PAUSE);
            break;
        case SRV_DA_STATE_ABORT:
        case SRV_DA_STATE_USER_CANCEL:
            vapp_gallery_pdl_notify_app(g_galleryPDLState, EVT_ID_VAPP_GALLERY_DA_USER_CANCEL);
            vapp_gallery_reset_pdl_state(g_galleryPDLState);
            break;
        }
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PDL_VAPP_GALLERY_PDL_DA_REPORT_HDLR_FIRST_RUN);
        // not running
        switch (status)
        {
            case SRV_DA_STATE_DOWNLOADING:
            case SRV_DA_STATE_COMPLETE:
                // launch PDL video player
                if(!g_galleryPDLState.isPlayerAlive() && !g_galleryPDLState.isLaunched() &&
                    (MMI_TRUE == srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD)) &&
                    (MMI_FALSE == vapp_screen_lock_is_exist()))
                {
                    filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(g_galleryPDLState.filePath);
                    #ifdef __MMI_VIDEO_PDL_YOUTUBE__
                    // explicitly checking for YTS
                    if(0 == app_ucs2_stricmp((kal_int8*)L"YTS", (kal_int8*)srv_fmgr_path_get_extension_ptr(g_galleryPDLState.filePath))
                       || g_galleryPDLState.isYouTube)
                    {
                        g_galleryPDLState.isYouTube = VFX_TRUE;
                        fileType = FMGR_TYPE_MP4;
                    }
                    #endif
                    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_report_hdlr launch player");
                    g_galleryPDLState.grpId = _vapp_gallery_file_open_handler(
                                    g_galleryPDLState.filePath, 
                                    fileType,
                                    MMI_FALSE,  // fromFileMgr
                                    MMI_FALSE,  // isFolder
                                    MMI_FALSE,  // content_is_image
                                    MMI_FALSE,  // disable_SSE
                                    MMI_FALSE,  // confirm_scenario
                                    NULL,       // fileFilter
                                    session_id  // pass PDL session id if downloading or completed
                                    );
                    g_galleryPDLState.hasLaunched = VFX_TRUE;
                }
                if(SRV_DA_STATE_COMPLETE == status)
                {
                    vapp_gallery_reset_pdl_state(g_galleryPDLState);
                }
                break;
            case SRV_DA_STATE_ABORT:
            case SRV_DA_STATE_USER_CANCEL:
                vapp_gallery_reset_pdl_state(g_galleryPDLState);
                break;
            case SRV_DA_STATE_PAUSE:
                break;
        }
    }
}


// download agent callback for video file (3GP)
extern void vapp_gallery_pdl_da_notify_video_file(
            S32 session_id,
            S32 mime_type,                  
            S32 mime_subtype, 
            S32 action,
            U32 filesize,
            CHAR *url,                        
            CHAR *mime_type_string,           
            U32 content_len,
            CHAR *content,
            srv_da_setting_struct *settings_p)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_notify_video_file");
    // fill default download setting
    srv_da_default_setting(
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        settings_p);

    // only handle WAP/HTTP download
    if(MMI_DA_WAP_DOWNLOAD != action)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_notify_video_file reject @%d", __LINE__);
        return;
    }

    // only handle PDL file formats
    MMI_BOOL is_pdl = MMI_FALSE;
    mdi_video_progressive_is_pdl_format((PU8)content, content_len, &is_pdl);
    if(MMI_FALSE == is_pdl)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_notify_video_file reject @%d with content len=%d", __LINE__, content_len);
        return;
    }

    // prevent re-enter Gallery Video Player if it is already running
    if(0 < srv_appmgr_query_instance_num("native.mtk.gallery.video.player") ||
       0 < srv_appmgr_query_instance_num("native.mtk.gallery.youtube.pgdl.player") )
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_notify_video_file reject @%d", __LINE__);
        return;
    }

    // If this session is already launched,
    // don't launch again
    if(session_id == g_galleryPDLState.sessionId &&
       g_galleryPDLState.isPlayerAlive())
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] vapp_gallery_pdl_da_notify_video_file reject @%d", __LINE__);
        return;
    }

    #if defined(__MMI_VIDEO_PDL_YOUTUBE__)
    do
    {
        applib_url_struct urlInfo;
        if(0 != applib_parse_url(url, &urlInfo))
        {
            break;
        }

        if(applib_scheme_http != urlInfo.scheme_type &&
           applib_scheme_https != urlInfo.scheme_type)
        {
            break;
        }

        VfxBool isYouTube = VFX_FALSE;
        VfxString hostName = VFX_STR_DYNAMIC((kal_char*)(urlInfo.parts[APPLIB_URL_HOST_PART]));
        app_strtolower(hostName.lockBuf(hostName.getLength()));
        hostName.unlockBuf();
        if((strstr(hostName.getBuf(), "youtube")))
        {
            isYouTube = VFX_TRUE;
        }

        if(isYouTube)
        {
            // scramble and notify APP to stop download when leave
            g_galleryPDLState.isYouTube = isYouTube;

            // scramble the content
            MDI_RESULT scrambleResult = mdi_video_progressive_scramble_buffer((U8*)content, (S32)content_len);
        }
    }while(0);

    #else
    // No special handling for other websites
    g_galleryPDLState.isYouTube = VFX_FALSE;
    #endif
    
    // all OK, change setting to let Gallery handle it
    settings_p->filepath_hdlr = vapp_gallery_pdl_da_video_filepath_hdlr;  /* notify where is the file */
    settings_p->report_hdlr = vapp_gallery_pdl_da_report_hdlr;    /* download status report */
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PDL_VAPP_GALLERY_PDL_DA_NOTIFY_VIDEO_FILE_WITH_SESSION_ID_D, session_id);
}

#endif // #ifdef __MMI_VIDEO_PDL__


} // extern "C"

#ifdef __AFX_RT_TEST__

#ifdef __VAPP_GALLERY_CUI_TEST__
// This class is for testing CUI only.
class VappGalleryTestCui : public VfxApp
{
    VFX_DECLARE_CLASS(VappGalleryTestCui);

// Override
public:
    VappGalleryTestCui():
      m_cid(NULL)
    {
    }

    virtual void onInit()
    {
        VfxApp::onInit();
    }

    virtual void onDeinit()
    {
        VfxApp::onDeinit();
    }
    
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VfxApp::onRun(args, argSize);

        m_cid = vcui_gallery_image_viewer_create(getGroupId(), (const WCHAR*)VFX_WSTR("E:\\image\\IMG40100.jpg"));

        // test image picker
        // m_cid = vcui_gallery_image_picker_create(getGroupId(), MMI_FALSE, NULL);

        // test video picker
        // m_cid = vcui_gallery_video_picker_create(getGroupId(), MMI_FALSE, NULL);
        
        vcui_gallery_run(m_cid);
    }

    virtual mmi_ret onProc(mmi_event_struct *evt)
    {
        if(EVT_ID_VCUI_GALLERY_CLOSE_GID == evt->evt_id ||
           EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY == evt->evt_id)
        {
            // test video picker
            WCHAR ppp[600] = {0};
            U32 bufSize = 0;
            vcui_gallery_picker_get_single_path(m_cid, NULL, &bufSize);
            bufSize = sizeof(ppp);
            vcui_gallery_media_state_enum st = vcui_gallery_picker_get_single_path(m_cid, ppp, &bufSize);
            
            vcui_gallery_close(m_cid);
            m_cid = NULL;
            exit();
            return MMI_RET_OK;
        }
        return VfxApp::onProc(evt);
    }

private:
    mmi_id m_cid;
};

VFX_IMPLEMENT_CLASS("VappGalleryTestCui", VappGalleryTestCui, VfxApp);

extern "C"
{
extern MMI_ID vapp_gallery_launch_cui_test(void* param, U32 param_size)
{
    return VfxAppLauncher::launch(VAPP_GALLERY,
                                  VFX_OBJ_CLASS_INFO(VappGalleryTestCui),
                                  GRP_ID_ROOT);
    
}
}
#endif


extern VtstTestResultEnum vtst_rt_vapp_gallery(VfxU32 param)
{
#ifdef __VAPP_GALLERY_CUI_TEST__
    vapp_gallery_launch_cui_test(NULL, 0);
#else
    vapp_gallery_launch(NULL, 0);
#endif
    return VTST_TR_OK;
}
#endif

/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryApp", VappGalleryApp, VfxApp);
VFX_IMPLEMENT_CLASS("VappGalleryScreen", VappGalleryScreen, VfxMainScr);
VFX_IMPLEMENT_CLASS("VappGalleryPage", VappGalleryPage, VfxPage);

VFX_IMPLEMENT_CLASS("VcuiGalleryBase", VcuiGalleryBase, VfxCui);
VFX_IMPLEMENT_CLASS("VcuiGalleryImageViewer", VcuiGalleryImageViewer, VcuiGalleryBase);
VFX_IMPLEMENT_CLASS("VcuiGalleryVideoPlayer", VcuiGalleryVideoPlayer, VcuiGalleryBase);

VFX_IMPLEMENT_CLASS("VcuiGalleryPickerBase", VcuiGalleryPickerBase, VcuiGalleryBase);
VFX_IMPLEMENT_CLASS("VcuiGalleryImagePicker", VcuiGalleryImagePicker, VcuiGalleryPickerBase);
VFX_IMPLEMENT_CLASS("VcuiGalleryVideoPicker", VcuiGalleryVideoPicker, VcuiGalleryPickerBase);
VFX_IMPLEMENT_CLASS("VcuiGalleryWallpaperPicker", VcuiGalleryWallpaperPicker, VcuiGalleryBase);

/***************************************************************************** 
 * Common framework event handling between App and CUI
 *****************************************************************************/
template<typename T> void registerCommonFrameWorkEvent(T *pThis, VfxBool isRegister)
{
    typedef mmi_ret (*PFNFrameworkRegFunc)(U16 evt_id, mmi_proc_func call_back, void *user_data);
    PFNFrameworkRegFunc action = isRegister ? &mmi_frm_cb_reg_event : &mmi_frm_cb_dereg_event;
    action(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &T::onDevicePlugIn, pThis);
    action(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &T::onDevicePlugOut, pThis);
#ifdef __MMI_USB_SUPPORT__
    action(EVT_ID_USB_ENTER_MS_MODE, &T::onUSBEnterMS, pThis);
#endif

    // to route call change even to screen and page
    pThis->registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, isRegister);
}

/***************************************************************************** 
 * Class Implementation : VappGalleryApp
 *****************************************************************************/
void VappGalleryApp::onInit()
{
    VfxApp::onInit();
    m_overrideCurrentDrive = 0;
    m_noDriveUsed = VFX_FALSE;
    #ifdef __MMI_VIDEO_PDL__
    m_pdlSessionId = INVALID_PGDL_SESSION_ID;
    #endif
    registerCommonFrameWorkEvent(this, VFX_TRUE);
}

void VappGalleryApp::onDeinit()
{
    m_overrideCurrentDrive = 0;
    m_noDriveUsed = VFX_FALSE;
    registerCommonFrameWorkEvent(this, VFX_FALSE);
    #ifdef __MMI_VIDEO_PDL__
    if(INVALID_PGDL_SESSION_ID != m_pdlSessionId && g_galleryPDLState.sessionId == m_pdlSessionId)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] VappGalleryApp::onDeinit resets PDL state");
        #if defined(__MMI_VIDEO_PDL_YOUTUBE__)
        if(g_galleryPDLState.isYouTube)
        {
            srv_da_stop_pdl(m_pdlSessionId);
        }
        #endif
        m_pdlSessionId = INVALID_PGDL_SESSION_ID;
        vapp_gallery_reset_pdl_state(g_galleryPDLState);
    }
    #endif
    VfxApp::onDeinit();
}

mmi_ret VappGalleryApp::onUSBEnterMS(mmi_event_struct *param)
{
    // exit Gallery application when enter Mass storage mode
    VfxApp *pThis = (VfxApp*)param->user_data;
    pThis->exit();
    return MMI_RET_OK;
}

mmi_ret VappGalleryApp::onDevicePlugIn(mmi_event_struct *param)
{
    // VappGalleryApp *pThis = reinterpret_cast<VappGalleryApp*>(evt->user_data);
    // VFX_ASSERT(pThis);
    return MMI_RET_OK;
}

mmi_ret VappGalleryApp::onDevicePlugOut(mmi_event_struct *param)
{
    srv_fmgr_notification_dev_plug_event_struct *evt = reinterpret_cast<srv_fmgr_notification_dev_plug_event_struct*>(param);
    VFX_ASSERT(evt->size == sizeof(srv_fmgr_notification_dev_plug_event_struct));

    VappGalleryApp *pThis = reinterpret_cast<VappGalleryApp*>(evt->user_data);
    return pThis->handleDevicePlugOut(evt);
}

mmi_ret VappGalleryApp::handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt)
{
    if(m_noDriveUsed)
    {
        return MMI_RET_OK;
    }
    // update current storage setting first
    const U8 defaultDrv = queryActiveDrive();
    if(!isMatchingStorage(*evt, defaultDrv))
    {
        // ejected storage is non of our concern
        return MMI_RET_OK;
    }

    // TODO: Check current top page's current storage is ejected ?

    // If current storage changed,
    // pop to index page if index page is in page history.
    // index page would refresh itself automatically.
    // Otherwise, simply terminate the program    
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(getScreen(getBottomScreenId()), VfxMainScr);
    VFX_ASSERT(mainScr);
    VappGalleryIndexPage *indexPage = NULL;
    VfxPage *p = NULL;
    VfxBool directRefresh = VFX_TRUE;
    while(NULL == indexPage && mainScr->getPageCount() > 0)
    {
        // get page
        p = mainScr->getPage();
        #ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
        // check if setting related page
        if(VappGallerySettingPage::isSettingRelatedPage(p))
        {
            break;
        }
        #endif
        // if we are in index page matching storage, update index
        indexPage = VFX_OBJ_DYNAMIC_CAST(p, VappGalleryIndexPage);
        if(indexPage)
        {
            // Note: popPage() does not immediately call VfxPage::onExit() and onDeinit().
            // so we post invoke here.
            vfxPostInvoke1(indexPage, &VappGalleryIndexPage::refreshStorage, directRefresh);
            break;
        }
        // there are other pages on top, do not refresh index page immediately
        directRefresh = VFX_FALSE;
        mainScr->popPage();
    }
    
    // if the page count reaches 0, this APP will auto-close
    return MMI_RET_OK; 
}


U8 VappGalleryApp::queryActiveDrive()
{
    if(0 != m_overrideCurrentDrive && !m_noDriveUsed)
    {
        return m_overrideCurrentDrive;
    }

    // update current storage setting first
    VappGalleryStorageSetting setting;
    // don't correct invalid storage, since we're handling device removal
    const srv_fmgr_drv_type_enum defaultStorage = setting.getDefaultStorage(VFX_FALSE);
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(defaultStorage);
    return defaultDrv;
}


kal_uint8 VappGalleryApp::getCBMAppId()
{
    return g_galleryCBMId;
}

VfxS32 VappGalleryApp::getPDLSessionId()
{
#ifdef __MMI_VIDEO_PDL__
    return m_pdlSessionId;
#else
    return INVALID_PGDL_SESSION_ID;
#endif
}

VfxBool VappGalleryApp::isMatchingStorage(const srv_fmgr_notification_dev_plug_event_struct &evt, U8 drv)
{
    for(VfxS32 i = 0; i < evt.count; ++i)
    {
        if (evt.drv_letters[i] == drv)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappGalleryApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappGalleryScreen *scr = NULL;
    VFX_OBJ_CREATE(scr, VappGalleryScreen, this);
    
    if(NULL == args)
    {
        // display main screen
        scr->show();    
    }
    else
    {
        const VappGalleryLaunchOption *pOption = reinterpret_cast<VappGalleryLaunchOption*>(args);
        const VfxWChar* path = pOption->filePath;
        const WCHAR *name = srv_fmgr_path_get_filename_ptr((WCHAR*)path);

        // config SSE option
        const VfxBool disableSSE = (pOption->disableSSE) ? VFX_TRUE : VFX_FALSE; 
        scr->setIsSSEDisabled(disableSSE);

        // config lite toolbar option and file type filter
        const VfxBool confirmScenario = (pOption->confirmScenario) ? VFX_TRUE : VFX_FALSE; 
        FMGR_FILTER *fileTypeFilter = (pOption->fileFilter);

        // [MAUI_03118340] since we launch full gallery/image viewer/video player depends on type        
        // add default file type to avoid launch wrong app caused by invalid file path
        filetypes_group_type_enum defaultFileGroup = pOption->fileGroup;
        mmi_id appId = getGroupId();
        switch(appId)
        {
        case VAPP_GALLERY_VIDEO_PLAYER:
        #ifdef __MMI_VIDEO_PDL_YOUTUBE__
        case VAPP_GALLERY_YOUTUBE_PGDL_PLAYER:
        #endif
            defaultFileGroup = FMGR_GROUP_VIDEO;
            break;
        case VAPP_GALLERY_IMAGE_VIEWER:
        case VAPP_GALLERY:
        default:
            defaultFileGroup = FMGR_GROUP_IMAGE;
        }
        // assign file group to default value for invalid file path case
        const filetypes_group_type_enum fileGroup = (0 == srv_fmgr_fs_path_exist(path)) ? pOption->fileGroup : defaultFileGroup;

        VfxBool isStreaming = VFX_FALSE;
#ifdef __MMI_VIDEO_STREAM__
        isStreaming = (FMGR_GROUP_STREAM == fileGroup || pOption->isRTSPLink);
#endif
        // Update used drive info
        if(isStreaming)
        {
            m_noDriveUsed = VFX_TRUE;
        }
        else
        {
            m_overrideCurrentDrive = ((U8*)path)[0];
        }

        const VfxBool forseUseViewerAs1stPage = pOption->forceEntryViewer;
        #ifdef __MMI_VIDEO_PDL_YOUTUBE__
        // MAUI_03215041: YouTube player has very tight memory, can only show player page
        const VfxBool strictPlayerMemory = pOption->isYouTubeTitle;
        if(strictPlayerMemory)
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL][YouTube] strictPlayerMemory=VFX_TRUE");
        }
        #else
        const VfxBool strictPlayerMemory = VFX_FALSE;
        #endif
        if((FMGR_GROUP_VIDEO == fileGroup && !forseUseViewerAs1stPage) 
            || isStreaming
            || strictPlayerMemory
            )
        {
            VappGalleryPlayerPage *playerPage = NULL;
            VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, scr);
            
            if(pOption->isRTSPLink)
            {
                playerPage->setRTSPLink(path);
            }
            else
            {
                const U64 startTimeHint = pOption->startTimeHint;
                playerPage->setLocalFile(path, startTimeHint, INVALID_PGDL_SESSION_ID != pOption->pdlSessionId ? VFX_TRUE : VFX_FALSE);
                #ifdef __MMI_VIDEO_PDL__
                m_pdlSessionId = pOption->pdlSessionId;
                #endif
                #ifdef __MMI_VIDEO_PDL_YOUTUBE__
                if(pOption->isYouTubeTitle)
                {
                    playerPage->setCustomTitle(VFX_WSTR("YouTube"));
                }
                #endif
            }
            
            playerPage->configUserProcAndData(pOption->userProc, pOption->userData);
            scr->setFirstPage(playerPage);
        }
        else 
        {
            // Image, unknown file case, or forceEntryViewer case
            // create image viewer page
            VappGalleryViewerPage *viewerPage = NULL;
            VFX_OBJ_CREATE_EX(viewerPage, VappGalleryViewerPage, scr, (confirmScenario));

            VfxWString folder = VFX_WSTR_MEM(path);
            if(!pOption->isFolder)
            {
                srv_fmgr_path_remove_slash((WCHAR*)folder.lockBuf(folder.getLength() + 1));
                folder.unlockBuf();
            }

            // even if the input is not folder,
            // we still check if the file path exists.
            // if not, we open it's parent folder instead
            if(!pOption->isFolder)
            {
                SRV_FMGR_FILEINFO_HANDLE hInfo = NULL;
                VfxS32 fmgrRet = srv_fmgr_fileinfo_create(folder.getBuf(), &hInfo);
                if(0 != fmgrRet || 
                   NULL == hInfo || 
                   (MMI_FALSE == srv_fmgr_fileinfo_is_folder(hInfo)))
                {
                    srv_fmgr_path_remove_filename((WCHAR*)folder.lockBuf(folder.getLength() + 1));    // note this is destructive
                    folder.unlockBuf();
                }
                if(hInfo)
                {
                    srv_fmgr_fileinfo_destroy(hInfo);
                    hInfo = NULL;
                }
            }
                        
            if(FMGR_GROUP_IMAGE == fileGroup && !pOption->isFolder)
            {
                // it is a image file, display it
                viewerPage->configFolderAndFilename(folder,
                                        VFX_WSTR_MEM(name),
                                        pOption->isImageOnly,
                                        pOption->sortMethod, 
                                        fileTypeFilter);
            }
            else
            {
                // unknown format, simply open the folder and display 1st image

                // [MAUI_03207089]workaround for UE change
                // in SLIM project with __MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__ support, alwyas entry image viewer
                // otherwise, entry image viewer or video player acoording to file type
                // folder case with content is video, show no video...
                VfxBool isVideoOnly = VFX_FALSE;
                #if defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__)    
                if(!pOption->contentIsImage && pOption->isFolder && NULL == fileTypeFilter)
                {
                    // video case with shooting forlder launch
                    // use specifuc error message
                    isVideoOnly = VFX_TRUE;
                }
                #endif

                viewerPage->configFolderAndIndex(folder,
                                        0,
                                        pOption->isImageOnly,
                                        isVideoOnly,
                                        pOption->sortMethod,
                                        VFX_TRUE,
                                        fileTypeFilter);
            }
            
            scr->setFirstPage(viewerPage);
        }

        scr->show();
    }
}

mmi_ret VappGalleryApp::onProc(mmi_event_struct *evt)
{
#ifdef __MMI_VIDEO_PDL__
    const VfxS32 sessionId = getPDLSessionId();
    do
    {

        if(INVALID_PGDL_SESSION_ID == sessionId)
            break;

        if(NULL == evt)
            break;

        // TODO: evt user data is not controlled by sender
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] DA_EVENT: %d", evt->evt_id);
        switch(evt->evt_id)
        {
        case EVT_ID_VAPP_GALLERY_DA_USER_CANCEL:
            exit();
            break;
        case EVT_ID_VAPP_GALLERY_DA_PAUSE:
        case EVT_ID_VAPP_GALLERY_DA_RESUME:
            {
                VfxMainScr *scr = VFX_OBJ_DYNAMIC_CAST(getTopScreen(), VfxMainScr);
                if(NULL == scr)
                    break;
                
                VappGalleryPlayerPage *player = VFX_OBJ_DYNAMIC_CAST(scr->getPage(), VappGalleryPlayerPage);
                if(NULL == player)
                    break;

                player->onProc(evt);
            }
            break;
        }
    }while(0);
#endif
    return VfxApp::onProc(evt);
}

/***************************************************************************** 
 * Class Implementation : VappGalleryScreen
 *****************************************************************************/
VappGalleryScreen::VappGalleryScreen() : 
    m_firstPage(NULL),
    m_isSSEDisabled(VFX_FALSE)
{
    #ifdef __VENUS_3D_UI_ENGINE__
    // default is 0, which causes VRT to use ALL vrt_mem_factor as cache mem.
    // so we set 1, to preserve space for OpenGL.
    setVrtCacheLimitSize(1);
    #endif
}

void VappGalleryScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VfxPage *page = NULL;
    if(NULL == m_firstPage)
    {
        VFX_OBJ_CREATE(page, VappGalleryIndexPage, this);
    }
    else
    {
        page = m_firstPage;   
    }

    pushPage(0, page);
}

void VappGalleryScreen::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);
    if(m_isSSEDisabled)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
    }        
}

void VappGalleryScreen::onExit(VfxBool isBackward)
{
    if(m_isSSEDisabled)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);
    }
    VfxMainScr::onExit(isBackward);
}

void VappGalleryScreen::setFirstPage(VfxPage *firstPage)
{
    m_firstPage = firstPage;
}

VfxPage *VappGalleryScreen::getFirstPage()
{
    return m_firstPage;
}

void VappGalleryScreen::setIsSSEDisabled(const VfxBool disabled)
{
    m_isSSEDisabled = disabled;
}

VfxBool VappGalleryScreen::onPageBack(VfxPage* page)
{
    VfxBool ret = VfxMainScr::onPageBack(page);
    if(page == m_firstPage)
    {
        m_signalLastPagePopped.emit();
        // if screen is not auto-close,
        // don't allow closing last page
        if(!getAutoClose())
        {
            return VFX_FALSE;
        }
    }
    return ret;
}

// #define __GALLERY_TEST_LOCK_SCREEN__

#ifdef __GALLERY_TEST_LOCK_SCREEN__
#include "vapp_screen_lock_gprot.h"
#endif

VfxBool VappGalleryScreen::onKeyInput(VfxKeyEvent &event)
{
#ifdef __GALLERY_TEST_LOCK_SCREEN__
    if(VFX_KEY_CODE_END == event.keyCode)
    {
        vapp_screen_lock_launch();
        return VFX_TRUE;
    }
#endif
    return VfxMainScr::onKeyInput(event);
}

/***************************************************************************** 
 * CUI Implementation
 *****************************************************************************/
extern "C"
{

void vcui_gallery_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void vcui_gallery_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

mmi_id vcui_gallery_wallpaper_picker_create(mmi_id parent_gid)
{
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)
    // IVLW requires on-memory file, so cannot be accessed
    // in mass storage mode
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    #endif
    return VfxAppLauncher::createCui(
                                VCUI_GALLERY_WALLPAPER_PICKER,
                                VFX_OBJ_CLASS_INFO(VcuiGalleryWallpaperPicker),
                                parent_gid,
                                NULL,
                                0);
}

mmi_id vcui_gallery_image_viewer_create(mmi_id parent_gid, const WCHAR* file_path)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    if(NULL == file_path)
    {
        return NULL;
    }
    return VfxAppLauncher::createCui(
                            VCUI_GALLERY_IMAGE_VIEWER,
                            VFX_OBJ_CLASS_INFO(VcuiGalleryImageViewer),
                            parent_gid,
                            (void*)file_path,
                            (1 + mmi_wcslen(file_path)) * 2);
}

static mmi_id vcui_gallery_video_player_create_internal(mmi_id parent_gid, const WCHAR* file_path, VfxId appClassId)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    if(NULL == file_path)
    {
        return NULL;
    }
    return VfxAppLauncher::createCui(
                            appClassId,
                            VFX_OBJ_CLASS_INFO(VcuiGalleryVideoPlayer),
                            parent_gid,
                            (void*)file_path,
                            (1 + mmi_wcslen(file_path)) * 2);
}

mmi_id vcui_gallery_video_player_create(mmi_id parent_gid, const WCHAR* file_path)
{
    return vcui_gallery_video_player_create_internal(parent_gid, file_path, VCUI_GALLERY_VIDEO_PLAYER);
}

mmi_id vcui_gallery_image_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    VcuiGalleryPickerLaunchParam param;
    param.m_multiSelect = (multi_select == MMI_TRUE);
    if(filter)
    {
        // MAUI_03015816 prevent client set video filter into image picker
        FMGR_FILTER imageFilter;
        FMGR_FILTER_INIT(&imageFilter);
        FMGR_FILTER_SET_IMAGE(&imageFilter);
        intersectFmgrFilter(imageFilter, *filter);
        param.m_customFileFilter = imageFilter;
    }
    return VfxAppLauncher::createCui(
                                VCUI_GALLERY_IMAGE_PICKER,
                                VFX_OBJ_CLASS_INFO(VcuiGalleryImagePicker),
                                parent_gid,
                                &param,
                                sizeof(param));
}

mmi_id vcui_gallery_video_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter)
{
    CHECK_MASS_STORAGE_AND_RETURN_NULL();
    VcuiGalleryPickerLaunchParam param;
    param.m_multiSelect = (multi_select == MMI_TRUE);
    if(filter)
    {
        param.m_customFileFilter = *filter;
    }
    return VfxAppLauncher::createCui(
                                VCUI_GALLERY_VIDEO_PICKER,
                                VFX_OBJ_CLASS_INFO(VcuiGalleryVideoPicker),
                                parent_gid,
                                &param,
                                sizeof(param));
}

void vcui_gallery_set_title_id(mmi_id cui_id, MMI_STR_ID str_id)
{
    VcuiGalleryBase *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryBase);
    if(NULL == cui)
    {
        return;
    }

    cui->setTitleCatpion(VFX_WSTR_RES(str_id));
    return;
}

void vcui_gallery_set_title_str_ptr(mmi_id cui_id, const WCHAR *title_str_ptr)
{
    VcuiGalleryBase *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryBase);
    if(NULL == cui)
    {
        return;
    }

    cui->setTitleCatpion(VFX_WSTR_MEM(title_str_ptr));
    return;
}

void vcui_gallery_picker_set_auto_close(mmi_id cui_id, MMI_BOOL is_auto_close)
{
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryPickerBase);
    if(NULL == cui)
    {
        return;
    }

    cui->setAutoClose(is_auto_close == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    return;
}

vcui_gallery_media_state_enum vcui_gallery_picker_get_single_path(mmi_id cui_id, WCHAR *result_path, U32 *buf_size_bytes)
{
    return vcui_gallery_picker_get_multi_path(cui_id, 0, result_path, buf_size_bytes);
}

void vcui_gallery_picker_get_multi_path_count(mmi_id cui_id, U32 *selected_path_count)
{
    if(NULL == selected_path_count)
    {
        return;
    }
    
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryPickerBase);
    if(NULL == cui)
    {
        return;
    }

    *selected_path_count = cui->getPickCount();
    return;
}

vcui_gallery_media_state_enum vcui_gallery_picker_get_multi_path(mmi_id cui_id, U32 path_index, WCHAR *result_path, U32 *buf_size_bytes)
{
    // size must be avilalble.
    // it is okay to pass NULL result_path (just to query size)
    if(NULL == buf_size_bytes)
    {
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryPickerBase);
    if(NULL == cui)
    {
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    if(0 >= cui->getPickCount())
    {
        if(result_path)
        {
            result_path[0] = NULL;
        }
        buf_size_bytes = 0;
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    // retrieve first path and return
    VfxWString path;
    const vcui_gallery_media_state_enum mediaState = cui->getPickedPath(path_index, path);
    const U32 sizeReq = sizeof(WCHAR) * (path.getLength() + 1);
    if(*buf_size_bytes < sizeReq)
    {
        *buf_size_bytes = sizeReq;
    }

    if(NULL == result_path)
    {
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    // copy the string to result_path buffer
    mmi_wcsncpy(result_path, path.getBuf(), path.getLength());

    return mediaState;
}

void vcui_gallery_wallpaper_picker_set_source_info(
                                    mmi_id cui_id, 
                                    IWallpaperSourceStruct *source_ptr)
{
    VcuiGalleryWallpaperPicker *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryWallpaperPicker);
    if(NULL == obj)
    {
        return;
    }
    obj->setWallpaperSource(source_ptr);
    return;
}

void vcui_gallery_wallpaper_picker_get_picked_wallpaper(
                                    mmi_id cui_id, 
                                    VappWpResType *wallpaper_type, 
                                    U32 *item_idx_picked)
{
    VcuiGalleryWallpaperPicker *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiGalleryWallpaperPicker);
    if(NULL == obj)
    {
        return;
    }
    
    VappWpResType type = VAPP_WALLPAPER_STATIC_WALLPAPER;
    U32 idxPicked = (U32)-1;
    obj->getPickedWallpaper(type, idxPicked);

    if(wallpaper_type)
    {
        *wallpaper_type = type;
    }
    if(item_idx_picked)
    {
        *item_idx_picked = idxPicked;
    }
    return;
}

} /* extern "C" */

/***************************************************************************** 
 * Class Implementation : VappGalleryPage
 *****************************************************************************/

VappGalleryPage::VappGalleryPage():
    m_messageFrame(NULL),
    m_waitIcon(NULL)
{
    m_customTitle.setNull();
    m_pageMessage.setNull();
}

void VappGalleryPage::onInit()
{
    VfxPage::onInit();
}

VfxBool VappGalleryPage::hasCustomTitle() const
{
    return !m_customTitle.isNull();
}

void VappGalleryPage::setCustomTitle(const VfxWString &title)
{
    m_customTitle = title;
    VfxPageBar *topBar = getBar(VFX_PAGE_BAR_LOCATION_TOP);
    if(NULL == topBar || m_customTitle.isNull())
    {
        return;
    }

    VcpTitleBar *titleBar = VFX_OBJ_DYNAMIC_CAST(topBar, VcpTitleBar);
    if(titleBar)
    {
        titleBar->setTitle(m_customTitle);
    }

}

void VappGalleryPage::getCustomTitle(VfxWString &title) const
{
    title = m_customTitle;
}

void VappGalleryPage::setPageMessage(const VfxWString &message)
{
    m_pageMessage = message;
}

void VappGalleryPage::showPageMessage(VfxBool isShow, VfxBool whiteText)
{
    if(!isShow && m_messageFrame)
    {
        m_messageFrame->setHidden(VFX_TRUE);
        return;
    }

    if(NULL == m_messageFrame)
    {
        VFX_OBJ_CREATE(m_messageFrame, VfxTextFrame, this);
        if(whiteText)
        {
            m_messageFrame->setColor(VFX_COLOR_WHITE);
        }
        else
        {
            //m_messageFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
            m_messageFrame->setColor(VfxColor(255, 140, 140, 140));
        }
        
        m_messageFrame->setIsUnhittable(VFX_TRUE);
        m_messageFrame->setAnchor(0.5f, 0.5f);
        m_messageFrame->setAutoResized(VFX_TRUE);
        m_messageFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(PAGE_MESSAGE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_messageFrame->setSize((VfxS32)(getSize().width * VCP_LIST_MENU_EMPTY_TEXT_WITH_RATIO), getSize().height / 3);
        m_messageFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_messageFrame->setPos(getSize().width / 2, getSize().height / 2);
        m_messageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID);
    }
    m_messageFrame->setHidden(VFX_FALSE);
    m_messageFrame->setString(m_pageMessage);
    m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_messageFrame->bringToFront();
}

void VappGalleryPage::showPageWaitIcon(VfxBool isShow)
{
    if(!isShow && m_waitIcon)
    {
        m_waitIcon->stop();
        m_waitIcon->sendToBack();
        return;
    }
    
    if(NULL == m_waitIcon)
    {
        VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->setAnchor(0.5f, 0.5f);
        m_waitIcon->setPos(getSize().width / 2, getSize().height / 2);
        m_waitIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID);
        
    }
    m_waitIcon->start();
    m_waitIcon->bringToFront();
}

VfxBool VappGalleryPage::getPageCurrentStorage(U8 &drvLetter)
{
    return VFX_FALSE;
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
void VappGalleryPage::setSelectUnselectButton(VfxBool selectAll)
{
    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    if(NULL == bar)
    {
        return;
    }
    
    VcpToolBar *selectBar = VFX_OBJ_DYNAMIC_CAST(bar, VcpToolBar);
    if(NULL == selectBar)
    {
        return;
    }

    VfxWString name;
    MMI_IMG_ID imgId = NULL;
    getButtonNameImageById(selectAll ? 'SALL' : 'UALL', name, imgId);
    // note: we use SAME button id for select/unselect on toolbar
    selectBar->changeItem('SALL', name, imgId);    
}

void VappGalleryPage::disableMultiCommandButton(VfxBool isDisabled)
{
    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    if(NULL == bar)
    {
        return;
    }
    
    VcpToolBar *selectBar = VFX_OBJ_DYNAMIC_CAST(bar, VcpToolBar);
    if(NULL == selectBar)
    {
        return;
    }

    // since there will only 1 multi-select button,
    // we try all possible commands.
    VfxId multiFileCmds[] = {'SHAR', 'MOVE', 'DELE'};
    for(VfxS32 i = 0; i < sizeof(multiFileCmds) / sizeof(multiFileCmds[0]); ++i)
    {
        selectBar->setDisableItem(multiFileCmds[i], isDisabled);
    }
}
#endif

void VappGalleryPage::getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId)
{
    switch(id)
    {
    case 'DELE':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
        break;

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    case 'SALL':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
        break;
    case 'UALL':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_UNSELECT_ALL);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL;
        break;
#endif

    case 'CNCL':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
        break;
    case 'OKAY':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
        break;
    }
    return;
}

/***************************************************************************** 
 * Class Implementation : VcuiGalleryBase
 *****************************************************************************/
VcuiGalleryBase::VcuiGalleryBase():
    m_cuiScreen(NULL),
    m_isDestroying(VFX_FALSE)
{
    m_customTitleCaption.setNull();
}

void VcuiGalleryBase::onInit()
{
    VfxCui::onInit();
    m_isDestroying = VFX_FALSE;
    registerCommonFrameWorkEvent(this, VFX_TRUE);
}

void VcuiGalleryBase::onDeinit()
{
    registerCommonFrameWorkEvent(this, VFX_FALSE);
    VfxCui::onDeinit();
}

void VcuiGalleryBase::setTitleCatpion(const VfxWString &caption)
{
    m_customTitleCaption = caption;
    if(isRunning())
    {
        VfxAppScr *topScreen = getScreen(getTopScreenId());
        VappGalleryScreen *configurableScreen = VFX_OBJ_DYNAMIC_CAST(topScreen, VappGalleryScreen);
        if(configurableScreen)
        {
            VfxPage *firstPage = configurableScreen->getFirstPage();
            setPageCustomTitle(firstPage);
        }
    }
}

VfxBool VcuiGalleryBase::getTitleCaption(VfxWString &caption)
{
    if(m_customTitleCaption.isNull())
    {
        return VFX_FALSE;
    }

    caption = m_customTitleCaption;
    return VFX_TRUE;
}

VfxBool VcuiGalleryBase::isDestroying()
{
    return m_isDestroying;
}

void VcuiGalleryBase::onRun(void *arg, VfxU32 argSize)
{
    VfxCui::onRun(arg, argSize);

    // create and display main screen
    VFX_ASSERT(NULL == m_cuiScreen);
    VFX_OBJ_CREATE(m_cuiScreen, VappGalleryScreen, this);

    // Do NOT auto-close, we should send close request to 
    // CUI client instead.
    m_cuiScreen->setAutoClose(VFX_FALSE);
    m_cuiScreen->m_signalLastPagePopped.connect(this, &VcuiGalleryBase::onLastPagePopped);

    // create first page and show it
    VfxPage *firstPage = this->createFirstPage(m_cuiScreen);
    VFX_ASSERT(firstPage);
    setPageCustomTitle(firstPage);
    m_cuiScreen->setFirstPage(firstPage);
    m_cuiScreen->show();
}

void VcuiGalleryBase::onLastPagePopped()
{
    // last page popped;
    // since we disabled AutoClose, 
    // we won't exit().
    // Notify CUI client to explicitly close CUI.
    // back is always regarded as cancel.
    vcui_gallery_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_CLOSE_GID, getGroupId());
    evt.result = VCUI_GALLERY_RESULT_CANCEL;
    m_isDestroying = VFX_TRUE;
    postToCaller((mmi_group_event_struct*)&evt);
}

VfxPage* VcuiGalleryBase::createFirstPage(VfxAppScr *screen)
{
    // by default, first page is NULL.
    // This causes Index Page to be used instead.
    return NULL;
}

void VcuiGalleryBase::setPageCustomTitle(VfxPage *page)
{
    // config title of the page if it is configurable
    if(!m_customTitleCaption.isNull())
    {
        VappGalleryPage *cuiPage = VFX_OBJ_DYNAMIC_CAST(page, VappGalleryPage);
        if(cuiPage)
        {
            cuiPage->setCustomTitle(m_customTitleCaption);
        }
    }
}

mmi_ret VcuiGalleryBase::onUSBEnterMS(mmi_event_struct *param)
{
    VcuiGalleryBase *pThis = reinterpret_cast<VcuiGalleryBase*>(param->user_data);
    if(pThis)
    {
        return pThis->handleUSBEnterMS(param);
    }
    return MMI_RET_OK;
}

mmi_ret VcuiGalleryBase::handleUSBEnterMS(mmi_event_struct *param)
{
    // by default, notify parent group to close ourselves.
    onLastPagePopped();
    return MMI_RET_OK;
}

mmi_ret VcuiGalleryBase::onDevicePlugIn(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

mmi_ret VcuiGalleryBase::onDevicePlugOut(mmi_event_struct *param)
{
    srv_fmgr_notification_dev_plug_event_struct *evt = reinterpret_cast<srv_fmgr_notification_dev_plug_event_struct*>(param);
    VFX_ASSERT(evt->size == sizeof(srv_fmgr_notification_dev_plug_event_struct));

    VcuiGalleryBase *pThis = reinterpret_cast<VcuiGalleryBase*>(evt->user_data);
    // note: different CUI handles device plug out differently
    return pThis->handleDevicePlugOut(evt);
}

U8 VcuiGalleryBase::onQueryActiveDrive()
{
    // update current storage setting first
    VappGalleryStorageSetting setting;
    // don't correct invalid storage, since we're handling device removal
    const srv_fmgr_drv_type_enum defaultStorage = setting.getDefaultStorage(VFX_FALSE);
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(defaultStorage);
    return defaultDrv;
}

VfxBool VcuiGalleryBase::onQueryActiveFile(VfxWString &activePath)
{
    return VFX_FALSE;
}

mmi_ret VcuiGalleryBase::handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt)
{    
    do
    {
        const U8 activeDrv = onQueryActiveDrive();
        if(VappGalleryApp::isMatchingStorage(*evt, activeDrv))
        {
            // match, should handle
            break;
        }
        
        // also check if there's an active file and it is now missing,
        // to handle virtual file path case
        VfxWString activeFile;
        if(onQueryActiveFile(activeFile))
        {
            if(!VappGalleryFileUtil::isFileExist(activeFile.getBuf()))
            {
                // file not exist anymore, should handle
                break;
            }
        }

        // ejected storage is non of our concern
        return MMI_RET_OK;
    }while(0);
    
    
    // If current storage changed,
    // pop to index page if index page is in page history.
    // index page would refresh itself automatically.
    // Otherwise, simply terminate the program    
    VFX_ASSERT(m_cuiScreen);
    VappGalleryIndexPage *indexPage = NULL;
    VfxBool directRefresh = VFX_TRUE;
    while(NULL == indexPage && m_cuiScreen->getPageCount() > 0)
    {
        indexPage = VFX_OBJ_DYNAMIC_CAST(m_cuiScreen->getPage(), VappGalleryIndexPage);
        if(indexPage)
        {
            // Note: popPage() does not immediately call VfxPage::onExit() and onDeinit().
            // so we post invoke here.
            vfxPostInvoke1(indexPage, &VappGalleryIndexPage::refreshStorage, directRefresh);
            break;
        }
        directRefresh = VFX_FALSE;
        m_cuiScreen->popPage();
    }
    
    // if page count reaches 0, onLastPagePopped() won't invoke since, since we pop the page by ourselves.
    if(0 == m_cuiScreen->getPageCount())
    {
        m_cuiScreen->m_signalLastPagePopped.emit();
    }
    return MMI_RET_OK; 
}


/***************************************************************************** 
 * Class Implementation : VcuiGalleryImageViewer
 *****************************************************************************/
void VcuiGalleryImageViewer::onRun(void *arg, VfxU32 argSize)
{
    VFX_DEV_ASSERT(arg && argSize);
    const VfxWChar* path = reinterpret_cast<const VfxWChar*>(arg);
    m_inputPath = VFX_WSTR_MEM(path);
    return VcuiGalleryBase::onRun(arg, argSize);
}

VfxPage* VcuiGalleryImageViewer::createFirstPage(VfxAppScr *screen)
{
    VappGalleryViewerPage *viewerPage = NULL;
    VFX_OBJ_CREATE(viewerPage, VappGalleryViewerPage, screen);
    VfxImageSrc src;
    src.setPath(m_inputPath);
    viewerPage->configSingleFile(src);
    return viewerPage;
}

U8 VcuiGalleryImageViewer::onQueryActiveDrive()
{
    if(m_inputPath.isNull() || m_inputPath.isEmpty())
    {
        return 0;
    }
    
    return (U8)m_inputPath.getBuf()[0];
}

VfxBool VcuiGalleryImageViewer::onQueryActiveFile(VfxWString &activePath)
{
    if(m_inputPath.isNull() || m_inputPath.isEmpty())
    {
        return VFX_FALSE;
    }

    activePath = m_inputPath;
    return VFX_TRUE;
}


/***************************************************************************** 
 * Class Implementation : VcuiGalleryVideoPlayer
 *****************************************************************************/
void VcuiGalleryVideoPlayer::onRun(void *arg, VfxU32 argSize)
{
    VFX_DEV_ASSERT(arg && argSize);
    const VfxWChar* path = reinterpret_cast<const VfxWChar*>(arg);
    m_inputPath = VFX_WSTR_MEM(path);
    return VcuiGalleryBase::onRun(arg, argSize);
}

VfxPage* VcuiGalleryVideoPlayer::createFirstPage(VfxAppScr *screen)
{
    VappGalleryPlayerPage *playerPage = NULL;
    VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, screen);
    playerPage->setLocalFile(m_inputPath);
    return playerPage;
}

U8 VcuiGalleryVideoPlayer::onQueryActiveDrive()
{
    if(m_inputPath.isNull() || m_inputPath.isEmpty())
    {
        return 0;
    }
    
    return (U8)m_inputPath.getBuf()[0];
}

VfxBool VcuiGalleryVideoPlayer::onQueryActiveFile(VfxWString &activePath)
{
    if(m_inputPath.isNull() || m_inputPath.isEmpty())
    {
        return VFX_FALSE;
    }

    activePath = m_inputPath;
    return VFX_TRUE;
}

/***************************************************************************** 
 * Class Implementation : VcuiGalleryPickerBase
 *****************************************************************************/
VcuiGalleryPickerLaunchParam::VcuiGalleryPickerLaunchParam() :
    m_multiSelect(VFX_FALSE)
{
    FMGR_FILTER_INIT(&m_customFileFilter);
    FMGR_FILTER_SET_ALL(&m_customFileFilter);
}

VcuiGalleryPickerBase::VcuiGalleryPickerBase() :
    m_launchParam(),
    m_mediaList(NULL),
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    m_selectedSet(NULL),
#else
	m_group(-1), 
	m_pos(-1),
#endif
	m_singleMediaState(VCUI_GALLERY_MEDIA_STATE_UNKNOWN), 
    m_isAutoClose(VFX_TRUE)
{    
    m_pickedFilePath.setEmpty();
}

void VcuiGalleryPickerBase::onRun(void *arg, VfxU32 argSize)
{
    VFX_ASSERT(sizeof(VcuiGalleryPickerLaunchParam) == argSize);
    m_launchParam = *reinterpret_cast<VcuiGalleryPickerLaunchParam*>(arg);
    return VcuiGalleryBase::onRun(arg, argSize);
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
VfxBool VcuiGalleryPickerBase::isMultiSelectMode()
{
    return m_launchParam.m_multiSelect;
}

void VcuiGalleryPickerBase::notifyPickOperationDone(
                vcui_gallery_result_enum result,       
                IVappGalleryMediaList *mediaList,   
                SimpleBitSet *selectedSet,
                vcui_gallery_media_state_enum mediaState)
{
    vcui_gallery_evt_struct evt;

    // if auto-close is OFF,
    // then we should not send pick operation when actually picked
    if(!m_isAutoClose && VCUI_GALLERY_RESULT_OK == result)
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY, getGroupId());
        evt.result = result;
    }
    else
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_CLOSE_GID, getGroupId());
        evt.result = result;
        // workaround for "quickly press back key twice to leave CUI" case.
        m_isDestroying = VFX_TRUE;
    }

    VFX_ASSERT(mediaList);
    VFX_ASSERT(selectedSet);
    m_mediaList = mediaList;
    m_selectedSet = selectedSet;
    m_singleMediaState = mediaState;

    // stroe picked file path. It is limited to single file path 
    // retrieve first path and return
    if(VCUI_GALLERY_RESULT_OK == result)
    {
        const vcui_gallery_media_state_enum mediaState = getPickedPath(0, m_pickedFilePath);
    }
    else
    {
        m_pickedFilePath.setEmpty();
    }

    postToCaller(reinterpret_cast<mmi_group_event_struct*>(&evt));
}
#else
void VcuiGalleryPickerBase::notifyPickOperationDone(
                vcui_gallery_result_enum result,       
                IVappGalleryMediaList *mediaList,   
                VfxS32 nGroup,
                VfxS32 nPos, 
                vcui_gallery_media_state_enum mediaState)
{
    vcui_gallery_evt_struct evt;

    // if auto-close is OFF,
    // then we should not send pick operation when actually picked
    if(!m_isAutoClose && VCUI_GALLERY_RESULT_OK == result)
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY, getGroupId());
        evt.result = result;
    }
    else
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_CLOSE_GID, getGroupId());
        evt.result = result;
        // workaround for "quickly press back key twice to leave CUI" case.
        m_isDestroying = VFX_TRUE;
    }

    VFX_ASSERT(mediaList);
    m_mediaList = mediaList;
    m_singleMediaState = mediaState;

    // stroe picked file path. It is limited to single file path 
    // retrieve first path and return
    if(VCUI_GALLERY_RESULT_OK == result)
    {
        const vcui_gallery_media_state_enum mediaState = getPickedPath(0, m_pickedFilePath);
    }
    else
    {
        m_pickedFilePath.setEmpty();
    }
	m_group = nGroup;
	m_pos = nPos;
    postToCaller(reinterpret_cast<mmi_group_event_struct*>(&evt));
}
#endif

VfxS32 VcuiGalleryPickerBase::getPickCount()
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    if(!m_mediaList.isValid() || NULL == m_selectedSet)
#else
	if(!m_mediaList.isValid())
#endif
    {
        if((VCUI_GALLERY_RESULT_OK == m_singleMediaState) &&
           (!m_pickedFilePath.isEmpty() && !m_pickedFilePath.isNull()))
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][picker] getPickCount, 1, special case");
            return 1;
        }
        return 0;
    }
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VfxS32 pickCount = 0;
    const VfxU32 groupCount = m_mediaList.get()->getGroupCount();
    ASSERT(groupCount <= SimpleBitSet::MAX_GROUP_COUNT);
    for(VfxU32 g = 0; g < groupCount; ++g)
    {
        for(int i = 0; i < m_mediaList.get()->getMediaCountInGroup(g); ++i)
        {
            if(m_selectedSet->isSet(VcpMenuPos(g, i)))
            {
                ++pickCount;
            }
        }
    }

    return pickCount;
#else
	return  m_group >= 0 && m_pos >= 0 ? 1 : 0;
#endif
}

const FMGR_FILTER* VcuiGalleryPickerBase::getTypeFilter()
{
    return &m_launchParam.m_customFileFilter;
}

vcui_gallery_media_state_enum VcuiGalleryPickerBase::getPickedPath(VfxS32 index, VfxWString &filePath)
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    if(!m_mediaList.isValid() || NULL == m_selectedSet)
#else
	if(!m_mediaList.isValid())
#endif
    {
        if((VCUI_GALLERY_RESULT_OK == m_singleMediaState) &&
           (!m_pickedFilePath.isEmpty() && !m_pickedFilePath.isNull()))
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][picker] getPickedPath, 1, special case");
            filePath = m_pickedFilePath;
        }
        filePath.setNull();
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    // naive implementation
    VfxS32 pickCount = 0;
    const VfxU32 groupCount = m_mediaList.get()->getGroupCount();
    ASSERT(groupCount <= SimpleBitSet::MAX_GROUP_COUNT);
    for(VfxU32 g = 0; g < groupCount; ++g)
    {
        for(int i = 0; i < m_mediaList.get()->getMediaCountInGroup(g); ++i)
        {
            if(m_selectedSet->isSet(VcpMenuPos(g, i)))
            {
                if(pickCount == index)
                {
                    if(OK != m_mediaList.get()->getMediaPath(VcpMenuPos(g, i), filePath))
                    {
                        // path not okay
                        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
                    }
                    else
                    {
                        // note: currently, m_mediaList cannot query the "current state" of a media
                        //       so we rely on the value passed from UI in notifyPickOperationDone.
                        //       this is only valid for single-media case.
                        return 0 == index ? m_singleMediaState : VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
                    }
                }

                ++pickCount;
            }
        }
    }

    return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
#else
	const VfxU32 groupCount = m_mediaList.get()->getGroupCount();
    ASSERT(groupCount <= SimpleBitSet::MAX_GROUP_COUNT);
	if (m_group >= 0 && m_pos >= 0)
	{
		if(OK != m_mediaList.get()->getMediaPath(VcpMenuPos(m_group, m_pos), filePath))
		{
            // path not okay
            return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
        }
        else
        {
            // note: currently, m_mediaList cannot query the "current state" of a media
            //       so we rely on the value passed from UI in notifyPickOperationDone.
            //       this is only valid for single-media case.
            return 0 == index ? m_singleMediaState : VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
        }
	}
	return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
#endif
}

void VcuiGalleryPickerBase::setAutoClose(VfxBool isAutoClose)
{
    m_isAutoClose = isAutoClose;
}

VfxBool VcuiGalleryPickerBase::getAutoClose()
{
    return m_isAutoClose;
}

/***************************************************************************** 
 * Class Implementation : VcuiGalleryImagePicker
 *****************************************************************************/
VfxPage* VcuiGalleryImagePicker::createFirstPage(VfxAppScr *screen)
{
    VappGalleryIndexPage *indexPage = NULL;
    VFX_OBJ_CREATE(indexPage, VappGalleryIndexPage, screen);
    // note: index page would check if call from CUI or APP
    return indexPage;
}



/***************************************************************************** 
 * Class Implementation : VcuiGalleryVideoPicker
 *****************************************************************************/
VfxPage* VcuiGalleryVideoPicker::createFirstPage(VfxAppScr *screen)
{
    VappGalleryIndexPage *indexPage = NULL;
    VFX_OBJ_CREATE(indexPage, VappGalleryIndexPage, screen);
    // note: index page would check if call from VideoPicker CUI or APP
    return indexPage;
}

/***************************************************************************** 
 * Class Implementation : VcuiGalleryWallpaperPicker
 *****************************************************************************/
VcuiGalleryWallpaperPicker::VcuiGalleryWallpaperPicker():
    m_firstPage(NULL)
{
    memset(&m_sourceInfo, 0, sizeof(m_sourceInfo));
    m_pickResult.type = WALLPAPER_PICK_OK;
    m_pickResult.pickPos.invalid();
}

VfxPage* VcuiGalleryWallpaperPicker::createFirstPage(VfxAppScr *screen)
{
    VappGalleryShootingPage *wallPaperThumbPage = NULL;
    VFX_OBJ_CREATE(wallPaperThumbPage, VappGalleryShootingPage, screen);
    wallPaperThumbPage->configWallpaperMode(&m_sourceInfo);
    return wallPaperThumbPage;
}

void VcuiGalleryWallpaperPicker::setWallpaperSource(IWallpaperSourceStruct *sourceInfo)
{
    // Note: we perform value copy to keep the source info object,
    //       since clienty by release the sourceInfo later
    m_sourceInfo = *sourceInfo;

#ifndef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__    
    // if video wallpaper is not enabled, remove them.
    m_sourceInfo.video_wallpaper_count = 0;
    m_sourceInfo.get_video_wallpaper_vid_id = NULL;
    m_sourceInfo.video_wallpaper_title = NULL;
#endif
}

void VcuiGalleryWallpaperPicker::getPickedWallpaper(VappWpResType &wallpaperType, U32 &selectedIndex)
{
    if(WALLPAPER_PICK_OK == m_pickResult.type)
    {
        wallpaperType = (VappWpResType)m_pickResult.pickPos.group;
        selectedIndex = m_pickResult.pickPos.pos;
        return;
    }
    else
    {
        wallpaperType = VAPP_WALLPAPER_STATIC_WALLPAPER;
        selectedIndex = (U32)-1;
        return;
    }
}

void VcuiGalleryWallpaperPicker::finishPickOperation(ResultType type, VcpMenuPos pickPos)
{
    m_pickResult.type = type;
    m_pickResult.pickPos = pickPos;

    vcui_gallery_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_GALLERY_CLOSE_GID, getGroupId());
    switch(type)
    {
    case WALLPAPER_PICK_OK:
        evt.result = VCUI_GALLERY_RESULT_OK;
        break;
    case WALLPAPER_PICK_Cancel:
        evt.result = VCUI_GALLERY_RESULT_CANCEL;
        break;
    }

    m_isDestroying = VFX_TRUE;
    postToCaller(reinterpret_cast<mmi_group_event_struct*>(&evt));
}

mmi_ret VcuiGalleryWallpaperPicker::handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt)
{
    // wallpaper picker are system resource, not related to memory card.
    return MMI_RET_OK;
}

mmi_ret VcuiGalleryWallpaperPicker::handleUSBEnterMS(mmi_event_struct *param)
{
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)
    // IVLW requries on-disk files,
    // so still need to exit under MSC mode
    return VcuiGalleryBase::handleUSBEnterMS(param);
#else
    // for wallpaper picker, we want to ignore USB mode,
    // since we only pick system build in resources
    return MMI_RET_OK;
#endif
}

#else // __MMI_FTO_GALLERY__

/***************************************************************************** 
 * Entry point dummy Implementation
 *****************************************************************************/
extern "C" 
{

void vapp_gallery_launch(void)
{
    
}

mmi_ret vapp_gallery_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

void vapp_gallery_image_option_open_handler(mmi_menu_id item_id, 
                                            const WCHAR* filepath, 
                                            const srv_fmgr_fileinfo_struct* fileinfo)
{
    return;
}

void vapp_gallery_video_option_open_handler(mmi_menu_id item_id, 
                                            const WCHAR* filepath, 
                                            const srv_fmgr_fileinfo_struct* fileinfo)
{
    return;
}
#ifdef __AFX_RT_TEST__
extern VtstTestResultEnum vtst_rt_vapp_gallery(VfxU32 param)
{
    // prevent build error when Gallery is turned off
    return VTST_TR_OK;
}
#endif

// dummy function, declare void ptr instead of vapp_gallery_image_viewer_launch_option_struct
extern MMI_ID vapp_gallery_image_viewer_launch(const WCHAR* file_path, void *option)
{
    return NULL;
}

// dummy function, declare void ptr instead of vapp_gallery_video_player_launch_option_struct
extern MMI_ID vapp_gallery_video_player_launch(const WCHAR* file_path, void *option)
{
    return NULL;
}

} // extern "C"


/***************************************************************************** 
 * CUI dummy Implementation
 *****************************************************************************/
extern "C" 
{

void vcui_gallery_run(mmi_id cui_id)
{
    // prevent build error when Gallery is turned off
}

void vcui_gallery_close(mmi_id cui_id)
{
    // prevent build error when Gallery is turned off
}

mmi_id vcui_gallery_wallpaper_picker_create(mmi_id parent_gid)
{
    return NULL;
}

mmi_id vcui_gallery_image_viewer_create(mmi_id parent_gid, const WCHAR* file_path)
{
    return NULL;
}

mmi_id vcui_gallery_video_player_create(mmi_id parent_gid, const WCHAR* file_path)
{
    return NULL;
}

mmi_id vcui_gallery_image_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter)
{
    return NULL;
}

mmi_id vcui_gallery_video_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter)
{
    return NULL;
}

void vcui_gallery_set_title_id(mmi_id cui_id, MMI_STR_ID str_id)
{
    // prevent build error when Gallery is turned off
}

void vcui_gallery_set_title_str_ptr(mmi_id cui_id, const WCHAR *title_str_ptr)
{
    // prevent build error when Gallery is turned off
}

vcui_gallery_media_state_enum vcui_gallery_picker_get_single_path(mmi_id cui_id, WCHAR *result_path, U32 *buf_size_bytes)
{
    // prevent build error when Gallery is turned off
    return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
}

void vcui_gallery_picker_get_multi_path_count(mmi_id cui_id, U32 *selected_path_count)
{
    // prevent build error when Gallery is turned off
}

vcui_gallery_media_state_enum vcui_gallery_picker_get_multi_path(mmi_id cui_id, U32 path_index, WCHAR *result_path, U32 *buf_size_bytes)
{
    // prevent build error when Gallery is turned off
    return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
}

void vcui_gallery_picker_set_auto_close(mmi_id cui_id, MMI_BOOL is_auto_close)
{
}

#ifndef IWallpaperSourceStruct
typedef struct IWallpaperSourceStruct IWallpaperSourceStruct;
#endif
void vcui_gallery_wallpaper_picker_set_source_info(
                                    mmi_id cui_id, 
                                    IWallpaperSourceStruct *source_ptr)
{
    // prevent build error when Gallery is turned off
}

void vcui_gallery_wallpaper_picker_get_picked_wallpaper(
                                    mmi_id cui_id, 
                                    VappWpResType *wallpaper_type, 
                                    U32 *item_idx_picked)
{
    // prevent build error when Gallery is turned off
}

} // extern "C"

#endif // __MMI_FTO_GALLERY__

// Dummy function section for remove media_app_2

#ifdef __COSMOS_MMI_PACKAGE__

/*  Try to prevent following linking errors:
Error: L6218E: Undefined symbol mmi_imgview_highlight_app (referred from readres.obj).
Error: L6218E: Undefined symbol mmi_imgview_highlight_entry_photoeditor (referred from readres.obj).
Error: L6218E: Undefined symbol mmi_imgview_highlight_view_detail (referred from readres.obj).
Error: L6218E: Undefined symbol mmi_imgview_hint_set_storage (referred from readres.obj).
Error: L6218E: Undefined symbol mmi_imgview_hint_view_style (referred from readres.obj).
Error: L6218E: Undefined symbol mmi_imgview_launch (referred from camcorderapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_set_storage (referred from camcorderapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_load_setting (referred from mediaplayermain.obj).
Error: L6218E: Undefined symbol cui_imgview_close (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_create (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_run (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_set_app_id (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_set_display_cap (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_set_mode_filename (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_set_title (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol cui_imgview_set_ui_direction (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol mmi_imgview_bpp_print_file (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol mmi_imgview_is_image_type_printable (referred from filemgrservicehdlr.obj).
Error: L6218E: Undefined symbol mmi_imgview_init_app (referred from funandgamessrc.obj).
Error: L6218E: Undefined symbol mmi_imgview_get_drm_result (referred from wgui_categories_multimedia.obj).
Error: L6218E: Undefined symbol mmi_imgview_fmgr_notify_hdlr (referred from mmi_rp_callback_mgr_table.obj).
Error: L6218E: Undefined symbol mmi_imgview_enter_view_screen (referred from vadp_mediawall.obj).
Error: L6218E: Undefined symbol mmi_imgview_set_rotate (referred from vadp_mediawall.obj).
Error: L6218E: Undefined symbol mmi_imgview_file_type_enabler (referred from mmi_rp_file_type_table.obj).
Error: L6218E: Undefined symbol mmi_imgview_file_type_handler (referred from mmi_rp_file_type_table.obj).
*/
extern "C"
{

extern void mmi_imgview_highlight_app(void){}
extern void mmi_imgview_highlight_entry_photoeditor(void){}
extern void mmi_imgview_highlight_view_detail(void){}
extern void mmi_imgview_hint_set_storage(U16 index){}
void mmi_imgview_hint_view_style(U16 index){}
void mmi_imgview_launch(void){}
void mmi_imgview_set_storage(U16 storage){}
void mmi_imgview_load_setting(void){}

extern mmi_id cui_imgview_create(mmi_id parent_gid){return NULL;}
extern void cui_imgview_run(mmi_id image_viewer_id){}
extern void cui_imgview_close(mmi_id image_viewer_id){}
extern void cui_imgview_set_app_id(mmi_id image_viewer_id, U16 app_id){}
extern void cui_imgview_set_display_cap(
                    mmi_id image_viewer_id, 
                    U32 item_id, 
                    MMI_BOOL is_enable){}
extern void cui_imgview_set_mode_filename(mmi_id image_viewer_id, CHAR *filename){}
extern void cui_imgview_set_mode_filelist(
                    mmi_id image_viewer_id, 
                    SRV_FMGR_FILELIST_HANDLE filelist, 
                    U32 start_index){}
extern void cui_imgview_set_mode_filename_array(
                    mmi_id image_viewer_id, 
                    CHAR **name_array, 
                    U32 array_count, 
                    U32 start_index){}
extern void cui_imgview_set_mode_prefetch_filename_func(
                mmi_id image_viewer_id, 
                U32 start_index,
                U32 total_count,
                void *user_data){}
extern void cui_imgview_set_mode_imageid_array(
                mmi_id image_viewer_id,
                U32 *imageid_array, 
                U32 count,
                U32 start_index){}
extern void cui_imgview_set_ui_direction(
                    mmi_id image_viewer_id, 
                    U32 direction){}
extern void cui_imgview_set_title(mmi_id image_viewer_id, WCHAR* string, U16 icon){}

extern void mmi_imgview_bpp_print_file(CHAR *filepath,BOOL is_short){}
extern BOOL mmi_imgview_is_image_type_printable(mmi_fmgr_filetype_enum image_type,U32 method){return MMI_FALSE;}

extern void mmi_imgview_init_app(void){}
extern S32 mmi_imgview_get_drm_result(void){return 0;}
mmi_ret mmi_imgview_fmgr_notify_hdlr(mmi_event_struct *event){return MMI_FALSE;}
extern void mmi_imgview_enter_view_screen(void){}
extern void mmi_imgview_set_rotate(U16 rotate_value){}
void mmi_imgview_file_type_enabler(mmi_menu_id item_id, const WCHAR* filepath, 
                                          const srv_fmgr_fileinfo_struct* fileinfo){}
void mmi_imgview_file_type_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                                          const srv_fmgr_fileinfo_struct* fileinfo){}

/*  Try to prevent following linking errors:
[MT6268.log]plutommi\mtkapp\video\videosrc\StreamingOTAP.c                                      7
<Error_logs>
Error: L6218E: Undefined symbol mmi_medply_del_all_app_screen (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_get_cbm_app_id (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_get_string_id_and_icon_id (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_is_profile_in_use (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_load_profile (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_set_active_profile (referred from StreamingOTAP.obj).
Error: L6218E: Undefined symbol mmi_medply_store_profile (referred from StreamingOTAP.obj).

[MT6268.log]vendor\vre30\src\arch\mtk\vmmacrostub.c                                             2
<Error_logs>
Error: L6218E: Undefined symbol mmi_medply_single_play_stream_from_rtsp_link (referred from vmmacrostub.obj).
Error: L6218E: Undefined symbol mmi_medply_single_play_stream_from_sdp_file (referred from vmmacrostub.obj).

<Error_logs>
Error: L6218E: Undefined symbol mmi_imgview_create_file_dir (referred from UcmVtCallScr.obj).
Error: L6218E: Undefined symbol mmi_imgview_get_storage_file_path (referred from UcmVtCallScr.obj).
Error: L6218E: Undefined symbol mmi_medply_get_next_snapshot_filename (referred from UcmVtCallScr.obj).

[MT6268.log]plutommi\mtkapp\dlagent\dlagentsrc\dlagentconfig.c                                  3
<Error_logs>
Error: L6218E: Undefined symbol mmi_medply_single_stream_receive_da_file (referred from dlagentconfig.obj).
Error: L6218E: Undefined symbol mmi_medply_sinlge_pdl_da_notify_audio_file (referred from dlagentconfig.obj).
Error: L6218E: Undefined symbol mmi_medply_sinlge_pdl_da_notify_video_file (referred from dlagentconfig.obj).

[MT6268.log]plutommi\mmi\emailapp\emailappsrc\EmailAppCompose.c                                 2
<Error_logs>
Error: L6218E: Undefined symbol mmi_medply_single_play_stream_from_ram_file (referred from EmailAppCompose.obj).
Error: L6218E: Undefined symbol mmi_medply_single_play_stream_from_sdp_file_with_title (referred from EmailAppCompose.obj).

*/


void mmi_medply_del_all_app_screen(void){}
U16 mmi_medply_get_cbm_app_id(void){return 0;}
void mmi_medply_get_string_id_and_icon_id(U16 *string_id, U16 *icon_id){}
MMI_BOOL mmi_medply_is_profile_in_use(U8 index){return MMI_FALSE;}
void mmi_medply_load_profile(U8 index, void *prof_p){}
void mmi_medply_set_active_profile(U8 index){}
void mmi_medply_store_profile(U8 index,void *prof_p){}
void mmi_medply_single_play_stream_from_rtsp_link(void *rtsp_url){}
void mmi_medply_single_play_stream_from_sdp_file(void *sdp_file, MMI_BOOL is_short){}
S32 mmi_imgview_create_file_dir(CHAR *filepath){return 0;}
void mmi_imgview_get_storage_file_path(CHAR *filepath){}
void mmi_medply_get_next_snapshot_filename(CHAR *file_buf, CHAR *file_path){}
void mmi_medply_single_stream_receive_da_file(
        S32 session_id, 
        S32 mime_type, 
        S32 mime_subtype, 
        S32 action, 
        PU16 file_path, 
        CHAR *url, 
        CHAR *mime_type_string){}
void mmi_medply_sinlge_pdl_da_notify_audio_file(
        S32 session_id,
        S32 mime_type,                  
        S32 mime_subtype, 
        S32 action,
        U32 filesize,
        CHAR *url,                        
        CHAR *mime_type_string,           
        U32 content_len,
        CHAR *content,
        void *settings_p){}
void mmi_medply_sinlge_pdl_da_notify_video_file(
        S32 session_id,
        S32 mime_type,                  
        S32 mime_subtype, 
        S32 action,
        U32 filesize,
        CHAR *url,                        
        CHAR *mime_type_string,           
        U32 content_len,
        CHAR *content,
        void *settings_p){}
void mmi_medply_single_play_stream_from_ram_file(void *ram_file, MMI_BOOL is_short){}
void mmi_medply_single_play_stream_from_sdp_file_with_title(void* sdp_file, MMI_BOOL is_short, void* title){}

/*
[MT6235.log]build\HUAQIN35_DEMO\gprs\MT6235o\lib\media_app_2.lib                                6
<Error_logs>
Error: L6218E: Undefined symbol mmi_imgview_del_scr_callback (referred from cameraapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_get_storage (referred from cameraapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_is_storage_ready (referred from cameraapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_set_storage_not_ready (referred from cameraapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_set_storage_ready (referred from cameraapp.obj).
Error: L6218E: Undefined symbol mmi_imgview_select_drive_callback (referred from cameramenu.obj).
*/
U8 mmi_imgview_del_scr_callback(void* ptr){return 0;}
U16 mmi_imgview_get_storage(void){return 0;}
BOOL mmi_imgview_is_storage_ready(void){return VFX_FALSE;}
void mmi_imgview_set_storage_not_ready(void){}
void mmi_imgview_set_storage_ready(void){}
void mmi_imgview_select_drive_callback( CHAR drv_letter ){}
/* fix 
Error: L6218E: Undefined symbol mmi_streaming_proc_cca_doc (referred from CcaSrvDispatcher.obj).
*/
void mmi_streaming_proc_cca_doc(void *msg){}
}   // extern "C"

#endif // __COSMOS_MMI_PACKAGE__
