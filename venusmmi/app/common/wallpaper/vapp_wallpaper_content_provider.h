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
 *  vapp_wallpaper_content_provider.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VAPP_WALLPAPER_CONTENT_PROVIDER_H__
#define __VAPP_WALLPAPER_CONTENT_PROVIDER_H__

#include "vapp_wallpaper_def.h"
/***************************************************************************** 
 * C-style API for PLUTO
 *****************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif
#include "MMIDataType.h"

#define VAPP_WALLPAPER_PROVIDER_WORKING_MEMORY_SIZE (10 * 1024)  // 10KB wokring memory
typedef void* VAPP_WALLPAPER_PROVIDER_HANDLE;
typedef void* VAPP_WALLPAPER_ID_HANDLE;

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_create
 * DESCRIPTION
 *  Create an Wallpaper Provider on Venus system heap
 *  Client must call vapp_wallpaper_provider_close() to prevent memory leak
 * PARAMETERS
 *  handlePtr   [OUT]   Pointer to recieve handle to created Wallpaper Provider object
 * RETURNS
 *  MMI_TRUE if the object is created successfully
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_provider_create(VAPP_WALLPAPER_PROVIDER_HANDLE* handlePtr);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_create_ex
 * DESCRIPTION
 *  Create an Wallpaper Provider, memory provided by client
 *  The memory should be cachable memory.
 *  buf_size should be at least VAPP_WALLPAPER_PROVIDER_WORKING_MEMORY_SIZE
 *  Client must call vapp_wallpaper_provider_close() to prevent memory leak
 * PARAMETERS
 *  handlePtr   [OUT]   Pointer to recieve handle to created Wallpaper Provider object
 * RETURNS
 *  MMI_TRUE if the object is created successfully
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_provider_create_ex(VAPP_WALLPAPER_PROVIDER_HANDLE* handlePtr, U8 *working_buf, U32 buf_size);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_close
 * DESCRIPTION
 *  Close (destroy) the created Wallpaper Provider
 * PARAMETERS
 *  handle   [IN]   Handle to created Wallpaper Provider object
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_wallpaper_provider_close(VAPP_WALLPAPER_PROVIDER_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_id_handle_close
 * DESCRIPTION
 *  Close (destroy) the id handle.
 * PARAMETERS
 *  handle   [IN]   Handle to an VappWallpaperId
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_wallpaper_id_handle_close(VAPP_WALLPAPER_ID_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_live_wallpaper_total_num
 * DESCRIPTION
 *  Retrieve valid Live Wallpaper number. Live Wallpaper does not contain base
 *  classes such as "VappWallpaperWide" or "VappWallpaperVideo"
 * PARAMETERS
 *  handle   [IN]   Handle to created Wallpaper Provider object
 * RETURNS
 *  Number of available Live Wallpapers
 *****************************************************************************/
S32 vapp_wallpaper_provider_get_live_wallpaper_total_num(VAPP_WALLPAPER_PROVIDER_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_live_wallpaper_id_handle
 * DESCRIPTION
 *  Convert item index to a handle to an VappWallpapdId
 * PARAMETERS
 *  handle   [IN]   Handle to created Wallpaper Provider object
 *  item_idx [IN]   item index (ranges from 0 ~ total_num - 1)
 * RETURNS
 *  Wallpaper ID handle (VAPP_WALLPAPER_ID_HANDLE).
 *  Must call vapp_wallpaper_id_handle_close() to close it.
 *****************************************************************************/
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_live_wallpaper_id_handle(VAPP_WALLPAPER_PROVIDER_HANDLE handle, S32 item_idx);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_current_live_wallpaper_id_handle
 * DESCRIPTION
 *  Get handle of current wallpaper setting
 * PARAMETERS
 *  source   [IN]   VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
 *  item_idx [IN]   item index (ranges from 0 ~ total_num - 1)
 * RETURNS
 *  Wallpaper ID handle (VAPP_WALLPAPER_ID_HANDLE).
 *  Must call vapp_wallpaper_id_handle_close() to close it.
 *****************************************************************************/
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_current_live_wallpaper_id_handle(VappWallpaperSrcEnum source);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_live_wallpaper_name_from_item_idx
 * DESCRIPTION
 *  Retrieve name of an item index.
 *  The memory of the name will NOT be available after handle is closed.
 * PARAMETERS
 *  handle   [IN]   Handle to created Wallpaper Provider object
 *  item_idx [IN]   item index (ranges from 0 ~ total_num - 1)
 *  name_buf [IN/OUT] buffer to receive the wallpaper name.
 *  buf_len  [IN]   length of the name_buf, in WCHAR count.
 * RETURNS
 *  Name length. When name_buff is NULL, requred name lenghth in WCHAR count will be returned.
 *****************************************************************************/
S32 vapp_wallpaper_provider_get_live_wallpaper_name_from_item_idx(VAPP_WALLPAPER_PROVIDER_HANDLE handle, S32 item_idx, WCHAR *name_buf, S32 buf_len);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_live_wallpaper_name_from_wallpaper_id_handle
 * DESCRIPTION
 *  Retrieve name of an wallpaper ID handle
 * PARAMETERS
 *  id_handle   [IN]   Wallpaper id handle
 *  name_buf [IN/OUT] buffer to receive the wallpaper name.
 *  buf_len  [IN]   length of the name_buf, in WCHAR count.
 * RETURNS
 *  Name length. When name_buff is NULL, requred name lenghth in WCHAR count will be returned.
 *****************************************************************************/
S32 vapp_wallpaper_provider_get_live_wallpaper_name_from_wallpaper_id_handle(VAPP_WALLPAPER_ID_HANDLE id_handle, WCHAR *name_buf, S32 buf_len);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_get_current_live_wallpaper_item_idx
 * DESCRIPTION
 *  Retrieve default wallpaper index from current setting
 * PARAMETERS
 *  handle     [IN]   Handle to created Wallpaper Provider object
 *  settingSrc [IN]   source of the wallpaper (e.g. VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK)
 * RETURNS
 *  Index of the wallpaper. If the wallpaper ID is not valid, 0 will be returned.
 *****************************************************************************/
S32 vapp_wallpaper_provider_get_current_live_wallpaper_item_idx(VAPP_WALLPAPER_PROVIDER_HANDLE handle, VappWallpaperSrcEnum source);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_setting_save_wallpaper_id_handle
 * DESCRIPTION
 *  Set a wallpaper id as current wallpaper
 * PARAMETERS
 *  source     [IN]   VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
 *  hId        [IN]   wallpaper id handle
 * RETURNS
 *  Save success or not
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_setting_save_wallpaper_id_handle(VappWallpaperSrcEnum source, VAPP_WALLPAPER_ID_HANDLE hId);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_is_current_wallpaper_file_based
 * DESCRIPTION
 *  If current home screen or lock screen wallpaper is file-based (must handle card removal event)
 * PARAMETERS
 *  source     [IN]   VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
 * RETURNS
 *  MMI_TRUE if wallpaper is file-based.
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_provider_is_current_wallpaper_file_based(VappWallpaperSrcEnum source);

// *  DEPRECATED
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_video_wallpaper_id_handle();

// *  DEPRECATED
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_image_wallpaper_id_handle();

// *  Must call vapp_wallpaper_id_handle_close() to close the handle
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_res_video_wallpaper_id_handle(MMI_ID video_res_id);

// *  Must call vapp_wallpaper_id_handle_close() to close the handle
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_res_image_wallpaper_id_handle(MMI_ID image_res_id);

// *  Must call vapp_wallpaper_id_handle_close() to close the handle
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_user_image_wallpaper_id_handle(WCHAR *image_path);

// *  Must call vapp_wallpaper_id_handle_close() to close the handle
VAPP_WALLPAPER_ID_HANDLE vapp_wallpaper_provider_get_user_video_wallpaper_id_handle(WCHAR *video_path);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_set_usb_mode
 * DESCRIPTION
 *  Notifies wallpaper provider that USB Mass storage mode is active.
 *  This causes provider to return default resource image ID, if the default
 *  wallpaper is file-based
 * PARAMETERS
 *  isMassStorageMode     [IN]  MMI_TRUE if enter mass storage mode, MMI_FALSE if leaving.
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_wallpaper_provider_set_usb_mass_storage_mode(MMI_BOOL isMassStorageMode);


/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_activate_by_vm
 * DESCRIPTION
 *  Set a given MRE package as active wallpaper.
 * PARAMETERS
 *  packageName     [IN]  MRE package name, e.g. "mre.wallpaper.MediaTek.Steam"
 *  usage           [IN]  VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
 * RETURNS
 *  MMI_TRUE if wallpaper activated successfully.
 *  MMI_FALSE if failed to activate (e.g. no MRE wallpaper support)
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_provider_activate_by_vm(CHAR *packageName, VappWallpaperSrcEnum usage);

/*****************************************************************************
 * FUNCTION
 *  vapp_wallpaper_provider_mre_is_activated
 * DESCRIPTION
 *  Queries if an MRE package is set as wallpaper
 * PARAMETERS
 *  packageName     [IN]  MRE package name, e.g. "mre.wallpaper.MediaTek.Steam"
 *  usage           [IN]  VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
 * RETURNS
 *  MMI_TRUE if the package is set as active wallpaper
 *  MMI_FALSE if the package is not current active wallpaper
 *****************************************************************************/
MMI_BOOL vapp_wallpaper_provider_mre_is_activated(CHAR *packageName, VappWallpaperSrcEnum usage);

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * C++ API for COSMOS
 *****************************************************************************/
#ifdef __cplusplus
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_wallpaper_id.h"

class VappWallpaperKit;

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
#endif

/***************************************************************************** 
 * Wallpaper setting 
 *****************************************************************************/
class VappLiveWallpaperContentProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappLiveWallpaperContentProvider);
public:
    // helper functions to retrieve wallpaper id from a static resource image
    static void getStaticImageWallpaperId(VappWallpaperId &wid, VfxResId imgId);
    static void getResourceVideoWallpaperId(VappWallpaperId &wid, VfxResId vidId);
    static void getUserWallpaperId(VappWallpaperId &wid, const VfxWString &filePath);
    static void getUserImageWallpaperId(VappWallpaperId &wid, const VfxWString &imgPath);
    static void getUserVideoWallpaperId(VappWallpaperId &wid, const VfxWString &vidPath);

// Constructor
public:
    VappLiveWallpaperContentProvider();

// Method
public:
    virtual void onInit();
    virtual void onDeinit();

    // This function return total number of live wallpaper
    S32 getLiveWallpaperTotalNum();

    // Get wallpaper id by index
    // @param item_idx [IN] 0 ~ getLiveWallpaperTotalNum() - 1
    // @param id [OUT] wallpaper id
    void getLiveWallpaperId(S32 item_idx, VappWallpaperId &id);
    
    // return live wallpaper thumb according to item_idx
    MMI_IMG_ID getLiveWallpaperThumb(S32 item_idx);

    // Blocking decode of live wallpaper. This should take very less time.
    VfxBool decodeLiveWallpaperThumb(S32 item_idx, VfxImageBuffer &buf);

    // return live wallpaper name according to item_idx
    void getLiveWallpaperName(S32 item_idx, VfxWString &name);

    // return live wallpaper name according to wallpaper id
    void getLiveWallpaperNameFromId(const VappWallpaperId &wid, VfxWString &name);

    // This function is used to create live wallpaper object
    // Purpose is for live wallpaper preview by wallpaper picker gallery cui
    void* getLiveWallpaper(U32 item_idx, void* parent_frame);

    // This funciton translate wallpaper ID into 0-based index
    // Pluto setting requires this function to locate selected wallpaper
    S32 translateLiveWallpaperIdToIndex(const VappWallpaperId &wid);

private:
    VappWallpaperKit *m_kit;                   // wallpaper kit
};
#endif /* __cplusplus */

#endif /* __VAPP_WALLPAPER_CONTENT_PROVIDER_H__ */

