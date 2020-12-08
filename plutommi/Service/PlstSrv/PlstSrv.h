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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  PlstSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PLAY_LIST_SERVICE_H__
#define __PLAY_LIST_SERVICE_H__
#if defined (__PLST_SERVICE_DB_SUPPORT__)
#include "PlstSrvDef.h"
#include "PlstSrvGprot.h"
#include "sqlite3.h"
#include "sqlite3ex.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "kal_public_defs.h"

/*
  Play list service feature configuration
*/

#ifdef __COSMOS_MMI_PACKAGE__
/*--------------------- For cosmos mmi package combination ------------------------*/

    #if !defined(__LOW_COST_SUPPORT_COMMON__)
    #define __PLST_DUAL_DB_SUPPORT__
    #endif

#else
/*-------- For plutommi, FTE package combination (__PLUTO_MMI_PACKAGE__) ----------*/

    #define __PLST_DUAL_DB_SUPPORT__ /* Support phone + card or phone only case */
    #define __PLST_SRV_FEATURE_LIST_SORT_BY_NAME__ /* sort play list by name, either by pinying or unicode */

    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    #define __PLST_SRV_FEATURE_VIDEO_SUPPORT__ /* Scan video files into database in seperate table */
    #define __PLST_SRV_FEATURE_GENRE_SUPPORT__ /* Parse genre field and insert into database */
    #endif

    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    #define __PLST_SRV_FEATURE_MOST_RECENT_LIST__ /* Default play list : most play list and recent play list*/
    #define __PLST_SRV_FEATURE_PREFIX_SEARCH__ /* Prefix search fucntion, currently use in plutommi only now */
    #endif
#endif /* __COSMOS_MMI_PACKAGE__ */

//#define __PLST_SRV_FEATURE_DEFAULT_SHOW_LAST__ /* Support configuration (SRV_PLST_PLST_DEFAULT_SHOW_LAST) to show default play list in the botton of list*/
//#define __PLST_SRV_FEATURE_GROUP_LIST__ /* Group list feature, ex. A in a group, B in a group. Not implemented by APP and this feature is not MP yet */

//#ifdef __MMI_VUI_SHELL_MEDIA_PLAYER__
//#define __PLST_SRV_DEFAULT_LIST__ /* For shell music player, already phase out */
//#endif


#define SRV_PLST_MAX_TRACKNUM_LEN                   (5) 
/* max year is "9999"   4+ 1*/
#define SRV_PLST_MAX_YEAR_LEN                       (5) 
/* max duration for U32 milliseconds type is "1194:59:59"   10 + 1 */
#define SRV_PLST_MAX_DURATION_LEN                   (11)
/* max duration for U32 milliseconds type is "4096.9M"  7 + 1*/
#define SRV_PLST_MAX_SIZE_LEN                       (8) 
/* 2008-09-05 11:23 PM 19 + 1*/
#define SRV_PLST_MAX_TIME_LEN                       (20)
 /* temp value */
#define SRV_PLST_MAX_USER_RATING_LEN                (41) 

/* max quality size*/
#define SRV_PLST_MAX_QUALITY_LEN                    (25)
/* max channel size */
#define SRV_PLST_MAX_CHANNEL_LEN                    (20)
/* max play count size */
#define SRV_PLST_MAX_PLAY_COUNT_LEN                 (20)
/* max volume size */
#define SRV_PLST_MAX_VOLUME_LEN                     (20)

#define SRV_PLST_MAX_SLIDE_NUM                    (5)


#define SRV_PLST_DB_FILENAME                    L"srv_media_lib"
#define SRV_PLST_DB_VERSION                     L"_V10" /* version use for file name */
#define SRV_PLST_DB_VERSION_NUM                 L"V10.1" /* version number (major number + sub number)*/
#define SRV_PLST_DB_EXTENSION                   L"db"
#define SRV_PLST_DB_DEFAULT_FOLDER              L"@service_player_internal"
#define SRV_PLST_DB_DEFAULT_DRV                 SRV_FMGR_PUBLIC_DRV
#define SRV_PLST_DB_JOURNAL_POSTFIX  			L"-journal"


typedef enum
{
    SRV_PLST_DRIVE_PHONE_ONLY,
    SRV_PLST_DRIVE_CARD_EXIST,
    SRV_PLST_DRIVE_CARD_ONLY, /* Only use memory card to store database */
    SRV_PLST_DRIVE_ENUM
}srv_plst_drive_state_enum;

typedef enum
{
    SRV_PLST_GEN_PHASE_INIT,
    SRV_PLST_GEN_PHASE_SET_DRV,
    SRV_PLST_GEN_PHASE_SEARCH_FIRST,
    SRV_PLST_GEN_PHASE_SEARCH_NEXT,
    SRV_PLST_GEN_PHASE_SEARCH_FOLDER,
    SRV_PLST_GEN_PHASE_FORWARDS,
    SRV_PLST_GEN_PHASE_BACKWARDS,
    SRV_PLST_GEN_PHASE_FINISH,
    SRV_PLST_GEN_PHASE_SEARCH_ODF,
    SRV_PLST_GEN_PHASE_CANCEL,
    SRV_PLST_GEN_PAHSE_END
}srv_plst_gen_list_phase_enum;

typedef enum
{
    SRV_PLST_GEN_NONE,
    SRV_PLST_GEN_ADD,
    SRV_PLST_GEN_SYNC_ALL,
    SRV_PLST_GEN_ENUM_END
}srv_plst_gen_run_type_enum;

typedef enum
{
    SRV_PLST_DB_CREATE_TBL_ARTIST,
    SRV_PLST_DB_CREATE_TBL_ALBUM,
    SRV_PLST_DB_CREATE_TBL_ALBUM_ARTWORK,
    SRV_PLST_DB_CREATE_TBL_GENRE,
    SRV_PLST_DB_CREATE_TBL_AUDIO,
    SRV_PLST_DB_CREATE_TBL_META,
    SRV_PLST_DB_CREATE_TBL_META_SLIM,
    SRV_PLST_DB_CREATE_TBL_VIDEO,
    SRV_PLST_DB_CREATE_TBL_STREAM,
    SRV_PLST_DB_CREATE_TBL_PLST,
    SRV_PLST_DB_CREATE_TBL_PLST_ITEM,
    SRV_PLST_DB_CREATE_TBL_PLAYING_INFO,
    SRV_PLST_DB_CREATE_TBL_SECURITY,
    SRV_PLST_DB_CREATE_IDX_ARTIST,
    SRV_PLST_DB_CREATE_IDX_ARTIST_SORT,
    SRV_PLST_DB_CREATE_IDX_ALBUM,
    SRV_PLST_DB_CREATE_IDX_ALBUM_SORT,
    SRV_PLST_DB_CREATE_IDX_GENRE,
    SRV_PLST_DB_CREATE_IDX_AUDIO_NAME,
    SRV_PLST_DB_CREATE_IDX_AUDIO_ARTIST,
    SRV_PLST_DB_CREATE_IDX_AUDIO_ALBUM,
    SRV_PLST_DB_CREATE_IDX_AUDIO_SORT,
    SRV_PLST_DB_CREATE_IDX_AUDIO_ALBUM_SORT,    
    SRV_PLST_DB_CREATE_IDX_AUDIO_PLAY_MAX,
    SRV_PLST_DB_CREATE_IDX_META_SLIM_PATH,
    SRV_PLST_DB_CREATE_IDX_VIDEO,
    SRV_PLST_DB_CREATE_IDX_PLST,
    SRV_PLST_DB_CREATE_IDX_PLST_ITEM_PLAY_MAX,
    SRV_PLST_DB_CREATE_TBL_ENUM_END
}srv_plst_db_create_table_enum;

typedef enum
{
    SRV_PLST_DUMMY_ID = 0, 
    SRV_PLST_ARTIST_ID, /* artist id  type */
    SRV_PLST_ALBUM_ID,  /* album id type */
    SRV_PLST_GENRE_ID,  /* genre id type */
    SRV_PLST_AUTHOR_ID, /* unsupported in 2.0 */
    SRV_PLST_MEDIA_ID,  /* media id type */
    SRV_PLST_PLST_ID,   /* player list id type */
    SRV_PLST_ID_TOTAL     
}srv_plst_id_enum;


typedef struct
{    
    U32  id; /* id in the phone*/
    #if !defined (SRV_PLST_USE_CRC_GEN_UNQIUE)
    U32  id2;  /* id int he card, use 2 id when view artist/album/genre */
    #endif
    S32 idx_in_list;    
}srv_plst_list_cache_struct;

typedef struct
{    
    U32 parent_id;  /* id in the phone db */
    U32 total;
    U32 first_index; /* the first item in the cache 's  item index in the list */
    U32 last_index; /* the last item in the cache 's  item index in the list */
    U32 head;       /*  the circle cache's head */
    U32 tail;         /* the circle cache's tail */
    U16 cache_num;
    srv_plst_list_cache_struct  cache[SRV_PLST_VIEW_LIST_CACHE];    
}srv_plst_list_context_struct;

typedef struct
{
    U32 id[SRV_PLST_VIEW_LIST_DEPTH]; 
    srv_plst_view_type_enum view_type[SRV_PLST_VIEW_LIST_DEPTH];
    S16  current_index;  /* current depth */  
    U32 total_count;
    MMI_BOOL is_mark;
    MMI_BOOL is_mark_all;
    MMI_BOOL is_unmark_all;
}srv_plst_list_view_type_struct;

typedef struct
{
    S32 index[SRV_PLST_VIEW_LIST_DEPTH]; 
    U32 id[SRV_PLST_VIEW_LIST_DEPTH];
    U32 first_view_media_id[SRV_PLST_VIEW_LIST_DEPTH];
    U32 last_view_media_id[SRV_PLST_VIEW_LIST_DEPTH];
    srv_plst_view_type_enum view_type[SRV_PLST_VIEW_LIST_DEPTH];
    srv_plst_view_type_enum hint_type;
    srv_plst_list_group_item_info_struct group[SRV_PLST_VIEW_LIST_DEPTH];
    MMI_BOOL is_id_used[SRV_PLST_VIEW_LIST_DEPTH];
    S16  current_index;  /* current depth */  
    S32 query_index;    /* the top level medium index, used when temp_memory_ptr is not null */
    U32 total_count;  
    U32 default_type;
    U32 plst_id; /* for default playlist entry directly */
    U32 sort_id;  /*for mark all added */
    U32 added_id; /* for mark all added */
    U32 mark_count;
    U32 prog_count;
    UI_character_type search[SRV_PLST_MAX_FILE_LEN];
    UI_character_type string[SRV_PLST_MAX_FILE_LEN];
    MMI_BOOL is_media_in_plst_unique;
    MMI_BOOL bg_loading;
    MMI_BOOL nb_blocking_artwork;
    MMI_BOOL is_cancel;
    MMI_BOOL is_get_data_cancel;
    MMI_BOOL is_stop_update_artwork;
    MMI_BOOL is_nb_update_artwork;
    MMI_BOOL is_add_cancel;
    MMI_BOOL is_delete_cancel;
    MMI_BOOL is_mark_all;
    MMI_BOOL is_unmark_all;
    MMI_BOOL is_mark;
    MMI_BOOL is_reorder;
    MMI_BOOL is_clear;
    MMI_BOOL is_search;
    srv_plst_list_context_struct list_cache[SRV_PLST_VIEW_LIST_DEPTH];
}srv_plst_list_view_history_struct;

typedef struct
{
    U32 total;
    U32 pick_index; /* current media index in the list */
    U32 pick_count; /* pick media(auto next or shuffle on) total from list */
    U32 played_count;/* the song that is auto picked or shuffle picked and played ? */
    U32 current_picked_id; /* current picked media id */
    U32 play_id; /* use in shuffle mode to mark the media played or not, value is MAX(play_count)  */
    U32 ordinal; /* start from total and increase 1 if next and decrease 1 if prev, work with pick_index and pick_count */
    U32 plst_id;/* plst_id/ album/artist/genre id */
    U32 last_active_id;
    U32 active_id; /* for specical view list */
    U32 active_idx; /* for special view list */
    srv_plst_active_list_enum active_type;
    srv_plst_list_view_type_struct  play_info; 
    MMI_BOOL is_load;
    MMI_BOOL is_playing_change;
    MMI_BOOL is_update_index;
    MMI_BOOL pick_no_played;
}srv_plst_playing_context_struct;


typedef struct
{
    S32 err_code;
    U32 srv_hdr;
    U32 Ucount;
    void* sqlite_buf;
    sqlite3*  db;
    sqlite3_instance sqlite_instance;
    UI_character_type db_phone_path[SRV_PLST_MAX_PATH_LEN];
    UI_character_type db_card_path[SRV_PLST_MAX_PATH_LEN];
    char sql_cmd[700];
    srv_plst_open_flag_enum open_flag;
    MMI_BOOL enable_flag;
    MMI_BOOL instance_inited;
    MMI_BOOL db_opened;
    MMI_BOOL in_transaction;
    MMI_BOOL is_phone_sync;
    MMI_BOOL is_card_sync;
}srv_plst_db_context_struct;

typedef struct
{
    U16 level;   /* stack level */
    U16 total_sub_folder;   /* total sub_folder number in this level */
    U16 index;                  /* current index in all sub_folder */
    U16  fs_index;           /* fs index for fs_find_first */
}srv_plst_gen_lib_stack_node_struct;

typedef struct
{
    UI_character_type path[SRV_PLST_MAX_PATH_LEN];
    UI_character_type file_ext[SRV_PLST_MAX_EXT_LEN + 1];
    MMI_BOOL is_short;
}srv_plst_gen_lib_append_path_cache_struct;

typedef struct
{
    U32 found;
    U32 append;
    U32 update_num;
    U32 addc;
    S32 last_error_code;
    FS_HANDLE   search_handle;
    UI_character_type  path_cache[SRV_PLST_MAX_PATH_LEN];
    UI_character_type  temp_path[SRV_PLST_MAX_PATH_LEN];
    CHAR  temp_name[(SRV_PLST_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    srv_plst_gen_lib_stack_node_struct  stack[SRV_PLST_MAX_FOLDER_DEPTH];  
    srv_plst_gen_lib_append_path_cache_struct path[SRV_PLST_MAX_SLIDE_NUM];
    U16  phase;
    U16 stack_index;    
    U8  run_type;    /* add or update */
    U8  drv_idx;
    MMI_BOOL is_short;
    MMI_BOOL reset_flag;
    MMI_BOOL cancel_gen;
    MMI_BOOL append_flag; /* append the find file */
    MMI_BOOL pause_gen;
}srv_plst_gen_lib_context_struct;

typedef struct
{
    void *user_data;
    cb_func callback;
    srv_plst_create_struct  create;
    void *temp_memory_ptr;
    U32 temp_memory_size;
    UI_character_type  title[SRV_PLST_MAX_FILE_LEN + 1];
    U32 srv_handle;
    U32 default_plst_config;
    S32 error_code;
    S32 db_open_error;
    S32 ture_err_code;
    U32 audio_count;
    U32 video_count;
    U32 plstitem_count;
    U8  repeat;
    U8  shuffle;    
    U8 config_play_sequeue;
    srv_plst_plst_reorder_enum config_reorder;
    srv_plst_search_type_enum config_search;
    srv_plst_list_sort_type_enum config_sort_list_view;
    srv_plst_list_sort_type_enum config_plst_view;
    srv_plst_view_sort_type config_view_sort_type;
    srv_plst_playing_info_store_enum config_store_play_info;
    srv_plst_play_cycle_info_enum config_play_cycle_info;
    MMI_BOOL is_open_cancel;
    MMI_BOOL is_refresh;
}srv_plst_base_info_struct;

typedef struct
{
    srv_plst_base_info_struct base_info;
    srv_plst_db_context_struct db_info;
    srv_plst_list_view_history_struct list_view_history;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_playing_context_struct playing_info;
}srv_plst_main_context_struct;


typedef struct
{
    U32  service_reg[SRV_PLST_MAX_SERVICE_SUPPORT]; 
    U8  number;
    srv_plst_drive_state_enum  card_state;
}srv_plst_control_struct;

typedef struct
{
    U32 default_list_flag;
    srv_plst_list_sort_type_enum list_sort;
    srv_plst_list_sort_type_enum plst_sort;
    srv_plst_view_sort_type view_type;
    srv_plst_playing_info_store_enum store_play_info;
    MMI_BOOL dual_db;
}srv_plst_config_info_struct;

typedef struct
{
    UI_character_type ver[SRV_PLST_MAX_TEMP_FILE_LENGTH]; /* SRV_PLST_DB_VERSION_NUM */
    U32   ver_int; /* CRC for ver */
    U32  card_id;
    U32  phone_id;
    U32  artwork_width;
    srv_plst_config_info_struct config;
    MMI_BOOL completed_flag;
}srv_plst_security;

typedef struct
{
    kal_eventgrpid g_pls_event;
} pls_ps_cntx_struct;

#ifdef __MTK_TARGET__
//#define __PLST_SERVICE_SWLA__
#endif 

#ifdef __PLST_SERVICE_SWLA__
#include "SST_sla.h"
#define SRV_PLST_START_MEASURE(_symbol_) \
    SLA_CustomLogging(##_symbol_##, 1); \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_PLST_START_MEASURE, __LINE__);
#define SRV_PLST_STOP_MEASURE(_symbol_) \
    SLA_CustomLogging(##_symbol_##, 0); \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_PLST_STOP_MEASURE, __LINE__);
#else
#define SRV_PLST_START_MEASURE(_symbol_)
#define SRV_PLST_STOP_MEASURE(_symbol_)

#endif

#endif
#endif

