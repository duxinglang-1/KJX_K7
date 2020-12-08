/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * vapp_gallery_cui.h
 *
 * Project:
 * --------
 *   COSMOS
 *
 * Description:
 * ------------
 *   Interface of CUI provided by Gallery application. e.g.
 *   Wallpaper picker
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

#ifndef __VCUI_GALLERY_CUI_H__
#define __VCUI_GALLERY_CUI_H__

#include "Vapp_setting_wallpaper_type_def_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_file_type_def.h"
// #include "mmi_rp_vapp_gallery_def.h"

/****************************************************************************
*
* CUI - Event
*
*****************************************************************************/
typedef enum vcui_gallery_evt_enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_GALLERY = VAPP_GALLERY,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_GALLERY_CLOSE_GID,

    EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY,  // only sent when vcui_gallery_picker_set_auto_close(cid, MMI_FALSE);
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_GALLERY_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_gallery_evt_enum;


typedef enum vcui_gallery_result_enum
{
    VCUI_GALLERY_RESULT_OK,                     // operation succeeded
    VCUI_GALLERY_RESULT_CANCEL,                 // operation cancelled by user
    VCUI_GALLERY_RESULT_E_FAIL,                 // operation failed
    VCUI_GALLERY_RESULT_E_OUT_OF_MEMORY,        // failed due to insufficient memory
} vcui_gallery_result_enum;

typedef enum vcui_gallery_media_state_enum
{
    VCUI_GALLERY_MEDIA_STATE_UNKNOWN,            // The media is not processed by Gallery yet
    VCUI_GALLERY_MEDIA_STATE_OK,                 // The media is processed and can be decoded by Gallery
    VCUI_GALLERY_MEDIA_STATE_FORMAT_UNSUPPORTED, // Gallery does not support this media
} vcui_gallery_media_state_enum;

typedef struct vcui_gallery_evt_struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* in header: evt_id, size, user_data, sender_id */
    vcui_gallery_result_enum result;
} vcui_gallery_evt_struct;

/****************************************************************************
*
* CUI - Gallery CUI common functions
*
*****************************************************************************/

/* 
 * DESCRIPTION
 *  Launch the CUI
 * PARAMETERS
 *  cui_id                : [IN]  cui id from cui_gallery_XXX_create functions
 */
extern void vcui_gallery_run(mmi_id cui_id);

/* 
 * DESCRIPTION
 *  Destroy the CUI. Call this function after receiving EVT_ID_VCUI_GALLERY_CLOSE_GID.
 *  The cui_id becomes invalid after calling this function.
 *
 * PARAMETERS
 *  cui_id                : [IN]  cui id from cui_gallery_XXX_create functions
 */
 extern void vcui_gallery_close(mmi_id cui_id);


/* 
 * DESCRIPTION
 *  Override the title(caption) of the CUI. This is optional. 
 *  If this function is not called,
 *  use CUI default behavior (for example, image viewer shows the filename)
 * PARAMETERS
 *  cui_id                : [IN]  cui id from vcui_gallery_xxx_create functions
 *  str_id                : [IN]  string resource
 */
extern void vcui_gallery_set_title_id(mmi_id cui_id, MMI_STR_ID str_id);

/* 
 * DESCRIPTION
 *  Override the title(caption) of the CUI. This is optional. 
 *  If this function is not called,
 *  use CUI default behavior (for example, image viewer shows the filename)
 * PARAMETERS
 *  cui_id                : [IN]  cui id from vcui_gallery_xxx_create functions
 *  title_str_ptr         : [IN]  NULL-terminated WCHAR string. 
 *                                It can be destroyed after this function returns.
 */
extern void vcui_gallery_set_title_str_ptr(mmi_id cui_id, const WCHAR *title_str_ptr);

/****************************************************************************
*
* CUI - Single Image Viewer
*
*****************************************************************************/

/* 
 * DESCRIPTION
 *  Create a single image viewer CUI which can view an single image file
 * PARAMETERS
 *  parent_gid            : [IN]  parent group id
 *  file_path             : [IN]  file path to a single image file.
 */
extern mmi_id vcui_gallery_image_viewer_create(mmi_id parent_gid, const WCHAR* file_path);


/****************************************************************************
*
* CUI - Single Video Player
*
*****************************************************************************/

/* 
 * DESCRIPTION
 *  Create a single video player CUI which can play/pause a single video file
 * PARAMETERS
 *  parent_gid            : [IN]  parent group id
 *  file_path             : [IN]  file path to a single video file.
 */
extern mmi_id vcui_gallery_video_player_create(mmi_id parent_gid, const WCHAR* file_path);



/****************************************************************************
*
* CUI - Image Picker and Video Picker
*
*****************************************************************************/

/* 
 * DESCRIPTION
 *  Pick one or more images from Gallery.
 * PARAMETERS
 *  parent_gid            : [IN]  parent group id
 *  multi_select          : [IN]  MMI_FALSE for single select.
 *  filter                : [IN]  filter is used to list only prefered type of files, for 
 *                                example, PNG only. can be NULL (all images are allowed)
 */
extern mmi_id vcui_gallery_image_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter);

/* 
 * DESCRIPTION
 *  Pick one or more videos from Gallery.
 * PARAMETERS
 *  parent_gid            : [IN]  parent group id
 *  multi_select          : [IN]  MI_FALSE for single select.
 *  filter                : [IN]  filter is used to list only prefered type of files, for 
 *                                example, 3gp only. can be NULL (all videos are allowed)
 */
extern mmi_id vcui_gallery_video_picker_create(mmi_id parent_gid, MMI_BOOL multi_select, const FMGR_FILTER* filter);

/* 
 * DESCRIPTION
 *   Retrieve the user selection result for single select mode
 *   Available only when
 *       - after receiving EVT_ID_VCUI_GALLERY_CLOSE_GID or EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY with result VCUI_GALLERY_RESULT_OK
 *       - and before vcui_gallery_close() is called.
 *   If user cancels, EVT_ID_VCUI_GALLERY_CLOSE_GID with result VCUI_GALLERY_RESULT_CANCEL
 * RETURNS
 *  state of the media being processed by Gallery or not
 * PARAMETERS
 *  cui_id            : [IN]  cui id from vcui_gallery_image_picker_create or vcui_gallery_video_picker_create
 *  result_path       : [OUT] buffer that receives the path user picked
 *  buf_size_bytes    : [IN/OUT] length of result_path, in bytes.
 *                               it will be changed to required buffer size if 
 *                               the size is insufficient.
 */
extern vcui_gallery_media_state_enum vcui_gallery_picker_get_single_path(mmi_id cui_id, WCHAR *result_path, U32 *buf_size_bytes);

/* 
 * DESCRIPTION
 *   Retrieve number of files user has selected in multi-select mode
 *   Available only when
 *       - after receiving EVT_ID_VCUI_GALLERY_CLOSE_GID or EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY with result VCUI_GALLERY_RESULT_OK 
 *       - and before vcui_gallery_close() is called.
 *   If user cancels, EVT_ID_VCUI_GALLERY_CLOSE_GID with result VCUI_GALLERY_RESULT_CANCEL
 * PARAMETERS
 *  cui_id               : [IN]  cui id from vcui_gallery_image_picker_create or vcui_gallery_video_picker_create
 *  selected_path_count  : [OUT] number of files user picked
 */
extern void vcui_gallery_picker_get_multi_path_count(mmi_id cui_id, U32 *selected_path_count);

/* 
 * DESCRIPTION
 *   Retrieve the file path of a given picked file index.
 *   Available only when
 *       - after receiving EVT_ID_VCUI_GALLERY_CLOSE_GID or EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY with result VCUI_GALLERY_RESULT_OK 
 *       - and before vcui_gallery_close() is called.
 * RETURNS
 *  state of the media being processed by Gallery or not
 * PARAMETERS
 *  cui_id            : [IN] cui id from vcui_gallery_image_picker_create or vcui_gallery_video_picker_create
 *  path_index        : [IN] index of the picked path. ranges from 0 ~ (selected_path_count - 1)
 *  result_path       : [OUT] buffer that receives the path user picked
 *  buf_size_bytes    : [IN/OUT] length of result_path, in bytes.
 *                               it will be changed to required buffer size if 
 *                               the size is insufficient.
 */
extern vcui_gallery_media_state_enum vcui_gallery_picker_get_multi_path(mmi_id cui_id, U32 path_index, WCHAR *result_path, U32 *buf_size_bytes);

/* 
 * DESCRIPTION
 *   Enable and disable auto-close the picker CUI after user select an image.
 *   By default, auto-close is MMI_TRUE.
 * PARAMETERS
 *  cui_id            : [IN]  cui id from vcui_gallery_image_picker_create or vcui_gallery_video_picker_create
 *  is_auto_close     : [IN]  MMI_TRUE to enable auto-close. MMI_FALSE to disable it.
 */
extern void vcui_gallery_picker_set_auto_close(mmi_id cui_id, MMI_BOOL is_auto_close);

/****************************************************************************
*
* CUI - Wallpaper picker
*
*****************************************************************************/
/* 
 * DESCRIPTION
 *  Callback that should return IMG ID of the thumbnail (square) of a given item in a group
 *
 * PARAMETERS
 *  is_live_wallpaper_group : [IN]  MMI_FALSE if querying static wallpaper group.
 *  item_idx                : [IN]  index of the wallpaper in the group.
 *  user_data               : [IN]  user_data provided when calling cui_gallery_picker_Wallpaper_set_source_info
 * RETURNS
 *  A valid image resource id representing a square thumbnail image.
 */
typedef MMI_IMG_ID (*PFN_VCUI_GALLERY_GET_ITEM_THUMB_IMG_ID)(VappWpResType wallpaper_type, U32 item_idx, void *user_data);

/* 
 * DESCRIPTION
 *  Callback that should return screen-size IMG ID of a given static wallpaper
 *
 * PARAMETERS
 *  itemIdx                 : [IN]  index of the static wallpaper
 *  user_data               : [IN]  user_data provided when calling cui_gallery_picker_Wallpaper_set_source_info
 * RETURNS
 *  A valid image resource id representing a LCD size wallpaper
 */
typedef MMI_IMG_ID (*PFN_VCUI_GALLERY_GET_ITEM_STATIC_WALLPAPER_IMG_ID)(U32 item_idx, void *user_data);

/* 
 * DESCRIPTION
 *  Callback that should return live wallpaper VfxFrame instance.
 *  for a given index of live wallpaper.
 *  Note live wallpaper is not available under Pluto.
 *
 * PARAMETERS
 *  item_idx                : [IN]  index of the live wallpaper
 *  parent_frame            : [IN]  a VfxFrame-based object, client should create the wallpaper instance as child frame
 *  user_data               : [IN]  user_data provided when calling cui_gallery_picker_Wallpaper_set_source_info
 * RETURNS
 *  A pointer to VfxFrame object, which is actually an live wallpaper.
 */
typedef void* (*PFN_VCUI_GALLERY_GET_ITEM_LIVE_WALLPAPER)(U32 item_idx, void* parent_frame, void *user_data);

/* 
 * DESCRIPTION
 *  IWallpaperSourceStruct provides content for wallpaper
 *  There are 2 groups: static wallpaper and live wallpaper
 */
typedef struct 
{
	U32 width;
    U32 height;     // in pixels
    U32 cf;         // VfxColorTypeEnum color format
    U32 bpp;        // byte per pixel
    U8 *buf_ptr;    // pointer to pixel buffer
} VappWallpaperThumbStruct;

typedef MMI_BOOL (*PFN_VCUI_GALLERY_DECODE_ITEM_THUMB)(U32 item_idx, VappWallpaperThumbStruct *thumb, void *user_data);

/* 
 * DESCRIPTION
 *  IWallpaperSourceStruct provides content for wallpaper
 *  There are 2 groups: static wallpaper and live wallpaper
 */
typedef struct 
{
	U32 live_wallpaper_count;				// number of live wallpapers
	U32 static_wallpaper_count;				// number of static wallpapers
	U32 video_wallpaper_count;              // number of video wallpapers
	MMI_STR_ID live_wallpaper_title;		// UI string id for group title of live wallpapers
	MMI_STR_ID static_wallpaper_title;		// UI string id for group title of sys-defined static wallpapers
	MMI_STR_ID video_wallpaper_title;       // UI string id for group title of video wallpapers
	PFN_VCUI_GALLERY_GET_ITEM_THUMB_IMG_ID get_thumb_img_id;						// callback from client to get thumbnails
	PFN_VCUI_GALLERY_GET_ITEM_STATIC_WALLPAPER_IMG_ID get_static_wallpaper_img_id;	// callback from client to get static wallpaper 
	PFN_VCUI_GALLERY_GET_ITEM_LIVE_WALLPAPER get_live_wallpaper;			        // callback from client to get livewallpaer instance (derived from VfxFrame)
	PFN_VCUI_GALLERY_GET_ITEM_STATIC_WALLPAPER_IMG_ID get_video_wallpaper_vid_id;   // callback from client to get video wallpaper resource id
	PFN_VCUI_GALLERY_DECODE_ITEM_THUMB decode_wallpaper_thumb;                          // if get_thumb_img_id returns 0, this function is called to generate thumbnail buffer
	void *user_data;						// user data from client
} IWallpaperSourceStruct;

/* 
 * DESCRIPTION
 *  creates a wallpaper picker CUI
 * RETURNS
 *  a cui_id of type mmi_id representing the cui instance.
 */
extern mmi_id vcui_gallery_wallpaper_picker_create(mmi_id parent_gid);

/* 
 * DESCRIPTION
 *  Set the wallpaper picer to display a constant group of wallpapers
 * PARAMETERS
 *  cui_id                : [IN]  cui id from vcui_gallery_wallpaper_picker_create
 *  source_ptr            : [IN]  a IWallpaperSourceStruct describing wallpapers
 */
extern void vcui_gallery_wallpaper_picker_set_source_info(
									mmi_id cui_id, 
									IWallpaperSourceStruct *source_ptr);

/* 
 * DESCRIPTION
 *  Retrive the picked result. 
 *  Call this when
 *       - after receiving EVT_ID_VCUI_GALLERY_CLOSE_GID with result VCUI_GALLERY_RESULT_OK 
 *       - and before vcui_gallery_close() is called.
 *   If user cancels, EVT_ID_VCUI_GALLERY_CLOSE_GID with result VCUI_GALLERY_RESULT_CANCEL
 *  
 * PARAMETERS
 *  cui_id				[IN]	the cui id retrived from vcui_gallery_wallpaper_picker_create
 *  is_live_wallpaper	[OUT]	if MMI_TRUE, then user picked an livewallpaper.
 *  item_idx_picked		[OUT]	index of wallpaper user picked.
 */
extern void vcui_gallery_wallpaper_picker_get_picked_wallpaper(
									mmi_id cui_id, 
									VappWpResType *wallpaper_type, 
									U32 *item_idx_picked);

#ifdef __cplusplus
}
#endif

#endif /*__VCUI_GALLERY_CUI_H__*/
