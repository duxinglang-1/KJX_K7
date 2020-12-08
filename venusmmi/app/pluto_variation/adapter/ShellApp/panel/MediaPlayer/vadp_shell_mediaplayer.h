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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_shell_imageviewer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Pluto APP <---> adaptor <---> Venus APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_SEHLL_MEDIAPLAYER_H__
#define __VADP_SEHLL_MEDIAPLAYER_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_MEDIA_PLAYER__

#include "ui_core\base\vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif
//#include "FileMgrGProt.h"
#include "MediaCacheSrvGprot.h"
#include "PlstSrvGprot.h"
//#include "MediaPlayerEnumDef.h"
#if defined(__MMI_AVRCP_SUPPORT__)
#if defined(__MMI_BT_BCHS_SUPPORT__)
#include "BCHSMMIAVRCPGProt.h"
#elif defined(__MMI_BT_SUPPORT__)
//#include "BTMMIScr.h"
//#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif 
#endif /* __MMI_AVRCP_SUPPORT__ */ 
#include "gdi_include.h"
#include "MediaCacheSrvMem.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#ifdef __cplusplus
}   /* extern "C" */
#endif

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_SHELLIV_START_LOGGING(_symbol_)
#define VAPP_SHELLIV_STOP_LOGGING(_symbol_)
#endif
typedef void (*vadp_shell_mediaplay_callback)(void* user_data);
typedef void (*medply_shell_play_callback)(void);
/**********************************************************************
 * Enumeration definition:
 **********************************************************************/
enum
{   
    VADP_SHELLMP_NO_SERVICE = -0x00222222,
    VADP_SHELLMP_DRM_LOCKED = -0x00333333    
};

enum
{   
    VADP_SHELLMP_VIEW_FIXED_NUM = 6    
};

typedef enum
{
    VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,
    VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,
    VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION
} vadp_shell_mediaplayer_player_info_enum;


typedef enum
{
    VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_INIT,
    VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY,
    VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PROCESS
}vadp_shell_mediaplayer_player_state_enum;

enum vadp_shell_mediaplayer_repeat_mode_enum
{
    VADP_SHELL_MEDIAPLAYER_REPEAT_ALL,
    VADP_SHELL_MEDIAPLAYER_REPEAT_ONE,
    VADP_SHELL_MEDIAPLAYER_REPEAT_OFF,
    VADP_SHELL_MEDIAPLAYER_REPEAT_TOTAL_COUNT
};


typedef enum
{   
    VADP_SHELLMP_VIEW_FIXED = 0,
    VADP_SHELLMP_VIEW_SWIPE,

    VADP_SHELLMP_VIEW_COUNT
}vadp_shell_mediaplayer_mode_enum;


typedef enum
{
    VADP_SHELL_MEDIAPLAYER_STATE_IDLE = 0,
    VADP_SHELL_MEDIAPLAYER_STATE_LOADING,
    VADP_SHELL_MEDIAPLAYER_STATE_DECODING,

    VADP_SHELL_MEDIAPLAYER_STATE_END
} vadp_shell_mediaplayer_decode_state_enum;


#if defined(__SQLITE3_SUPPORT__)
#define VADP_SHELL_MP_SQLITE_BUFFER_SIZE (SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT)
#else
#define VADP_SHELL_MP_SQLITE_BUFFER_SIZE (0)
#endif


/* @TODO: Yaling will remove it to  MediaCacheSrvGprot.h , delete later */
//#define SRV_PLST_ARTWORK_RESIZED_WIDTH   175
//#define SRV_PLST_ARTWORK_RESIZED_HEIGHT  175

#include "ShellApp\panel\MediaPlayer\vapp_shell_mediaplayer.h"

/* MediaCache memory size configuration */
#define VADP_SHELL_MP_SMALL_CACHE_COUNT       12
#define VADP_SHELL_MP_SMALL_CACHE_BUF_SIZE      ((VappShellMediaplayerMenu::CELL_ITEM_PHOTO_WIDTH * VappShellMediaplayerMenu::CELL_ITEM_PHOTO_HEIGHT* GDI_MAINLCD_BIT_PER_PIXEL)>>3)*VADP_SHELL_MP_SMALL_CACHE_COUNT

#define VADP_SHELL_MP_LARGE_CACHE_COUNT       3
#define VADP_SHELL_MP_LARGE_CACHE_BUF_SIZE      ((VappShellMediaplayerMainScreen::ALBUM_PHOTO_WIDTH * VappShellMediaplayerMainScreen::ALBUM_PHOTO_HEIGHT* GDI_MAINLCD_BIT_PER_PIXEL)>>3)*VADP_SHELL_MP_LARGE_CACHE_COUNT

#define VADP_SHELL_MP_RUN_BUF_COUNT (18)
#define VADP_SHELL_MP_RUN_BUF_SIZE      (SRV_MEDIACACHE_RUN_BUF_SIZE(VADP_SHELL_MP_RUN_BUF_COUNT))

/* MediaCache total size */
#define VADP_SHELL_MP_MEDCACHE_MEM_SIZE    ((VADP_SHELL_MP_SMALL_CACHE_BUF_SIZE)\
                                             + (VADP_SHELL_MP_RUN_BUF_SIZE) \
                                             + (VADP_SHELL_MP_ARTWORK_IMAGE_SIZE))
                                             //+VADP_SHELL_MP_LARGE_CACHE_BUF_SIZE\
                                             //+VADP_SHELL_MP_SQLITE_BUFFER_SIZE)

/* Plst memory size configuration */
#define VADP_SHELL_MP_DETAILS_COUNT (20)
#define VADP_SHELL_MP_DETAILS_MEM_SIZE      ((VADP_SHELL_MP_DETAILS_COUNT)* sizeof(srv_plst_media_details_struct ))
#define VADP_SHELL_MP_ARTWORK_IMAGE_SIZE    (((SRV_PLST_ARTWORK_RESIZED_WIDTH*SRV_PLST_ARTWORK_RESIZED_HEIGHT*2)/4 + 1)*4)
#define VADP_SHELL_MP_DETAILS_SLOT_MEM_SIZE ((VADP_SHELL_MP_DETAILS_COUNT)*sizeof(S32))

/* Plst total size */
#define VADP_SHELL_MP_PLST_MEM_SIZE (VADP_SHELL_MP_ARTWORK_IMAGE_SIZE*3)+(VADP_SHELL_MP_DETAILS_MEM_SIZE)+(VADP_SHELL_MP_DETAILS_SLOT_MEM_SIZE)

/* Shell total memory size */
#define VADP_SHELL_MP_MEM_SIZE    (VADP_SHELL_MP_MEDCACHE_MEM_SIZE)+(VADP_SHELL_MP_PLST_MEM_SIZE)


/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef void(*vapp_shell_mediaplayer_decode_callback)(void*, S32, S32);
typedef void(*vapp_shell_mediaplayer_list_ready_callback)(void*);
typedef void(*vapp_shell_mediaplayer_delete_done_callback)(void*);

/**********************************************************************
 * External Interfaces:
 **********************************************************************/
extern VfxBool g_tapToPlay;
extern VfxBool vadp_shell_mediaplayer_is_list_ready(void);
extern S32 vadp_shell_mediaplayer_init(void);

extern S32 vadp_shell_mediaplayer_get_active_item_count();
extern S32 vadp_shell_mediaplayer_get_menu_item_count();

extern S32 vadp_shell_mediaplayer_get_active_index(void);
extern S32 vadp_shell_mediaplayer_cache_init_srv(S32 num_all);
extern S32 vadp_shell_mediaplayer_cache_set_index(S32 index);
extern void vadp_shell_mediaplayer_deinit_cache_srv(void);
extern void vadp_shell_mediaplayer_unregister_cache_callback(void);
extern void vadp_shell_mediaplayer_deinit_plst(void);
extern void vadp_shell_mediaplayer_get_cur_artwork(void** buf_ptr, S32 width, S32 height);
extern S32 vadp_shell_mediaplayer_cache_srv_free_image_buffer(void* buffer);
extern S32 vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer, S32 *resized_width, S32 *resized_height);
extern VfxS32 vadp_shell_mediaplayer_get_focus_index(void);
extern S32 vadp_shell_mediaplayer_get_song_title(S32 index, void* title_str, S32 title_str_buf_size);
extern S32 vadp_shell_mediaplayer_get_details(S32 index, srv_plst_media_details_struct *details);
extern S32 vadp_shell_mediaplayer_get_active_details(S32 index, srv_plst_media_details_struct *details);
extern S32 vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer_nonblocking(void *user_data, S32 index,vapp_shell_mediaplayer_decode_callback callback, void** buffer_pp);
extern MMI_BOOL vadp_shell_mediaplayer_player_set_index(S32 index);
extern MMI_BOOL vadp_shell_mediaplayer_player_apply_picked_file(void);
extern void vadp_shell_mediaplayer_player_get_info(vadp_shell_mediaplayer_player_info_enum info_type, void *result_ptr);
extern void vadp_shell_mediaplayer_player_set_shuffle(VfxBool shuf);
extern VfxBool vadp_shell_mediaplayer_player_is_shuffle();
extern void vadp_shell_mediaplayer_player_sync_shuffle_with_medply(VfxBool shuf);
extern void vadp_shell_mediaplayer_player_set_repeat_mode(vadp_shell_mediaplayer_repeat_mode_enum r);
extern vadp_shell_mediaplayer_repeat_mode_enum vadp_shell_mediaplayer_player_get_repeat_mode();
extern void vadp_shell_mediaplayer_player_sync_repeat_mode_to_medply(vadp_shell_mediaplayer_repeat_mode_enum  repeat_mode);
#if defined(__MMI_AVRCP_SUPPORT__)
extern void vadp_shell_mediaplayer_player_avrcp_callback(void *userdata, VfxU8(*callback)(void*, VfxU8, mmi_avrcp_key_events));
#endif
extern void vadp_shell_mediaplayer_player_register_callback(void *userdata, void (*callback) (void *, U32, void *));
extern void vadp_shell_mediaplayer_deregister_callback(void);
extern void vadp_shell_mediaplayer_player_play(void);
extern void vadp_shell_mediaplayer_player_pause(void);
extern void vadp_shell_mediaplayer_player_stop(void);
extern S32 vadp_shell_mediaplayer_player_previous(void);
extern S32 vadp_shell_mediaplayer_player_next(void);
extern S32 vadp_shell_mediaplayer_cache_srv_get_image_info(S32 index, S32 *resized_width, S32 *resized_height);
extern VfxU8 vadp_shell_mediaplayer_player_get_volume();
extern void vadp_shell_mediaplayer_player_set_volume(VfxU8 volume);
//extern void vadp_shell_mediaplayer_entry_library(medply_shell_play_callback cb);
extern void vadp_shell_mediaplayer_entry_library(vadp_shell_mediaplay_callback cb, void* user_data);
extern VfxU8 vadp_shell_mediaplayer_get_storage();

extern void vadp_shell_mediaplayer_set_storage(VfxU8 storage);

extern void vadp_shell_mediaplayer_register_list_ready_callback(void* user_data, vapp_shell_mediaplayer_list_ready_callback cb);

extern void vadp_shell_mediaplayer_register_delete_done_callback(void* user_data, vapp_shell_mediaplayer_delete_done_callback cb);

extern void vadp_shell_mediaplayer_delete_file_nonblocking(VfxU32 index, void* user_data, vapp_shell_mediaplayer_delete_done_callback cb);

extern void vadp_shell_mediaplayer_create_filelist(void);

extern void vadp_shell_mediaplayer_free_filelist(void);
    
extern VfxBool vadp_shell_mediaplayer_is_list_ready(void);

extern VfxU32 vadp_shell_mediaplayer_get_file_count(void);

extern VfxU32 vadp_shell_mediaplayer_get_folder_path(void);

extern void vadp_shell_mediaplayer_cache_srv_start(vadp_shell_mediaplayer_mode_enum view_mode);

extern void vadp_shell_mediaplayer_cache_srv_close(void);

extern VfxBool vadp_shell_mediaplayer_get_image_path_by_index(VfxS32 index, VfxWChar *buffer_ptr, VfxU32 length);

extern void vadp_shell_mediaplayer_enter_kernal_app(VfxS32 index);


#endif /* __MMI_VUI_SHELL_MEDIA_PLAYER__ */
#endif /* __VADP_SEHLL_MEDIAPLAYER_H__ */
