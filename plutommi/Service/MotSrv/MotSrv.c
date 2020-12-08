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
 *  MotSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  mot service source file
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MOT_SUPPORT__)

#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "string.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "sqlite3kal.h"
#include "mmi_rp_file_type_def.h"
#include "MotSrvGprot.h"
#include "MotSrv.h"
#include "mdi_video.h"
#include "mmi_rp_srv_mot_def.h"

#define SRV_MOT_SETTING_PATH    L":\\@mot\\"

#define SRV_MOT_PLAYLIST_RECORD_DISK_SPACE (1 * 1024)

#ifdef __SRV_MOT_SQLITE_VERSION__

    #define SRV_MOT_DB_NAME   L"mot.db"

    #define MOT_DATABASE_CURRENT_VERSION 9

    #define MOT_TABLE_DB_VERSION    "CREATE TABLE IF NOT EXISTS db_version (id INTEGER PRIMARY KEY, db_ver INTEGER, is_complete INTEGER)"
    #define MOT_TABLE_META          "CREATE TABLE IF NOT EXISTS meta (id INTEGER PRIMARY KEY, filename TEXT, " \
                                    "filepath TEXT, title TEXT, artist TEXT, date TEXT, duration INTEGER, description TEXT, category INTEGER, thumbnail BLOB);" \
                                "CREATE INDEX IF NOT EXISTS idx_filepath ON meta (filepath)"
    //#define MOT_TABLE_CAT_COUNT     "CREATE TABLE IF NOT EXISTS cat_count (id INTEGER PRIMARY KEY, count INTEGER)"

    //#define MOT_TABLE_FAVORITE      "CREATE TABLE IF NOT EXISTS favorite (id INTEGER PRIMARY KEY, ref_id INTEGER UNIQUE ON CONFLICT REPLACE)"
    #define MOT_TABLE_RECENT_PLAY   "CREATE TABLE IF NOT EXISTS recent_play (id INTEGER PRIMARY KEY, filepath TEXT UNIQUE ON CONFLICT REPLACE, time INTEGER)"

    #define SRV_MOT_PRESERVED_DISK_SPACE   (SRV_MOT_MAX_RECORD_NUMBER * SRV_MOT_THUMBNAIL_SIZE + SRV_MOT_MAX_RECORD_NUMBER * 3072)

#else

    #ifndef MAKE_FOURCC
        #define MAKE_FOURCC(a,b,c,d) (((kal_uint32)a)|(((kal_uint32)b)<<8)|(((kal_uint32)c)<<16)|(((kal_uint32)d)<<24))
    #endif

    typedef struct srv_mot_db_header_t srv_mot_db_header_t;
    typedef struct srv_mot_db_category_num_t srv_mot_db_category_num_t;
    typedef struct srv_mot_db_recent_play_t srv_mot_db_recent_play_t;
    typedef struct srv_mot_db_meta_t srv_mot_db_meta_t;

    #define SRV_MOT_DB_NAME        L"mot.sdb"
    #define SRV_MOT_DB_VER         (3)
    #define SRV_MOT_DB_SIGNATURE   MAKE_FOURCC('M','O','T','D')

    #define SRV_MOT_DB_HEADER_OFFSET (0)
    #define SRV_MOT_DB_HEADER_SIZE (sizeof(srv_mot_db_header_t))

    #define SRV_MOT_DB_CATEGORY_NUM_OFFSET (SRV_MOT_DB_HEADER_OFFSET + SRV_MOT_DB_HEADER_SIZE)
    #define SRV_MOT_DB_CATEGORY_NUM_SIZE (sizeof(srv_mot_db_category_num_t))

    #define SRV_MOT_DB_RECENT_PLAY_OFFSET (SRV_MOT_DB_CATEGORY_NUM_OFFSET + SRV_MOT_DB_CATEGORY_NUM_SIZE)
    #define SRV_MOT_DB_RECENT_PLAY_SIZE (sizeof(srv_mot_db_recent_play_t))

    #define SRV_MOT_DB_META_OFFSET (SRV_MOT_DB_RECENT_PLAY_OFFSET + SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER*SRV_MOT_DB_RECENT_PLAY_SIZE)
    #define SRV_MOT_DB_META_SIZE (sizeof(srv_mot_db_meta_t))

    // add some buffer.
    #define SRV_MOT_PRESERVED_DISK_SPACE   (SRV_MOT_PLAYLIST_RECORD_DISK_SPACE + SRV_MOT_DB_HEADER_SIZE + SRV_MOT_DB_CATEGORY_NUM_SIZE + SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER*SRV_MOT_DB_RECENT_PLAY_SIZE + SRV_MOT_MAX_RECORD_NUMBER*SRV_MOT_DB_META_SIZE)

#endif

#define MOT_META_STR_ACTION_ADVENTURE   L"Action & Adventure"
#define MOT_META_STR_ROMANCE_ETHICS     L"Romance & Ethics"
#define MOT_META_STR_COMEDY_HUMOR       L"Comedy & Humor"
#define MOT_META_STR_TV_DRAMA           L"TV-Series & Drama"
#define MOT_META_STR_ANIMATION_SCIFI    L"Animation & Sci-Fi"
#define MOT_META_STR_THRILLER_MYSTERY   L"Thriller & Mystery"
#define MOT_META_STR_MUSIC_PERFORMANCE  L"Music & Performance"
#define MOT_META_STR_DOCUMENTARY        L"Documentary"
#define MOT_META_STR_OTHERS             L"Others"

#define MOT_META_STR_ADVENTURE_KMV    L"1"
#define MOT_META_STR_ACTION_KMV       L"0"
#define MOT_META_STR_FAMILY_KMV       L"6"
#define MOT_META_STR_ROMANCE_KMV      L"12"
#define MOT_META_STR_COMEDY_KMV       L"3"
#define MOT_META_STR_DRAMA_KMV        L"5"
#define MOT_META_STR_WEATERN_KMV      L"17"
#define MOT_META_STR_WAR_KMV          L"16"
#define MOT_META_STR_SPORTS_KMV       L"14"
#define MOT_META_STR_ANIMATION_KMV    L"2"
#define MOT_META_STR_FANTASY_KMV      L"7"
#define MOT_META_STR_SCIFI_KMV        L"13"
#define MOT_META_STR_HORROR_KMV       L"8"
#define MOT_META_STR_MYSTERY_KMV      L"10"
#define MOT_META_STR_SUSPENSE_KMV     L"15"
#define MOT_META_STR_MUSIC_KMV        L"9"
#define MOT_META_STR_PERFORMANCE_KMV  L"11"
#define MOT_META_STR_DOCUMENTARY_KMV  L"4"
#define MOT_META_STR_OTHERS_KMV       L"18"

#define MOT_BACKGROUND_MOD  MOD_PLS
#define MOT_CONTROL_MOD     MOD_MMI

#define MOT_UPDATE_ROUND_ITERATOR   (5)
#define MOT_UPDATE_COMMIT_FACTOR    (5)

typedef enum
{
    SRV_MOT_TASK_EVENT          = 1 <<  0,
} srv_mot_wait_event_enum;

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

#define MSG_STRUCT(type, name, ilm) \
    type* name  = (type*) ilm->local_para_ptr

#define SRV_MOT_WAIT_EVENT(evt) \
    do { \
        kal_uint32 retrieved_events; \
        kal_retrieve_eg_events(self->req_events, (evt), \
            KAL_OR_CONSUME, &retrieved_events, (kal_uint32) KAL_SUSPEND); \
    } while (0)

#define SRV_MOT_SET_EVENT(evt) \
    kal_set_eg_events(self->req_events, evt, KAL_OR);

/* return value */
typedef enum
{
    SRV_MOT_STATE_IDLE = 0,
    SRV_MOT_STATE_OPENED,
    SRV_MOT_STATE_UPDATING,
    SRV_MOT_STATE_ERROR
}srv_mot_state_enum;

/* return value */
typedef enum
{
    SRV_MOT_QUERY_TYPE_NONE                 = 0,
    SRV_MOT_QUERY_TYPE_NUMBER_BY_CATEGORY   = 1,
    SRV_MOT_QUERY_TYPE_NUMBER_BY_FAVORITE   = 2,
    SRV_MOT_QUERY_TYPE_NUMBER_BY_RECENT_PLAY= 3,
    SRV_MOT_QUERY_TYPE_NUMBER_BY_ALL        = 4,
    SRV_MOT_QUERY_TYPE_BRIEF_BY_CATEGORY    = 5,
    SRV_MOT_QUERY_TYPE_BRIEF_BY_FAVORITE    = 6,
    SRV_MOT_QUERY_TYPE_BRIEF_BY_RECENT_PLAY = 7,
    SRV_MOT_QUERY_TYPE_BRIEF_BY_ALL         = 8,
    SRV_MOT_QUERY_TYPE_CONTENT_DETAIL       = 9,
    SRV_MOT_QUERY_TYPE_CONTENT_PATH         =10,
}srv_mot_query_type_enum;

/* context */
typedef struct
{
    srv_mot_state_enum state;

    S32 (*client_cb)(void* client, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param);
    void* client;
    U16 app_id;

    kal_char drive_letter;
    kal_wchar* med_dir;
    kal_wchar* db_path;
    kal_wchar* fs_search_filter;

#ifdef __SRV_MOT_SQLITE_VERSION__
    kal_wchar* db_journal_path;

    sqlite3_instance sql_ctx;
    sqlite3 *sqlite_db;         /* sqlite database */
    kal_uint8 *sql_buf;
    sqlite3_stmt *stmt;
    sqlite3_stmt *stmt_query;
    sqlite3_stmt *stmt_query_op1;

#else

    FS_HANDLE fh_sdb;
    srv_mot_db_meta_t *curr_db_meta;
    srv_mot_db_category_num_t *category;
    srv_mot_cat_enum last_query_category;
    kal_uint32 last_query_start_idx;

    kal_uint16 query_id_cache[SRV_MOT_MAX_RECORD_NUMBER];

#endif

#ifdef __SRV_MOT_FS_SORT__
    kal_bool fs_xfind;
    kal_uint32 fs_xfind_idx;
    kal_uint32 fs_xfind_pos;
    kal_uint8 fs_sorting_buffer[SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE];
    kal_uint8 fs_working_buffer[SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE];
#endif

    srv_mot_query_type_enum last_query_type;
    srv_mot_sort_dir_enum last_query_dir;

    kal_bool abort_updating;
    FS_HANDLE curr_handle;
    kal_int32 last_fs_error;
    kal_mutexid task_mutex;
    kal_eventgrpid req_events;

    kal_wchar *curr_filename;
    kal_wchar *curr_filepath;
    mdi_video_mot_meta_struct *mot_meta;
    kal_uint32 update_count;

}srv_mot_context_t;

static srv_mot_context_t* g_srv_mot_ctx_p = NULL;
static kal_mutexid g_srv_mot_task_mutex = NULL;
static kal_eventgrpid g_srv_mot_task_event = NULL;

#ifdef __SRV_MOT_SQLITE_VERSION__
    static kal_mutexid g_srv_mot_sql_mutex = NULL;

    static srv_mot_ret_enum _mot_sql_close_db(srv_mot_context_t* self);
#else

    struct srv_mot_db_header_t
    {
        kal_uint32 signature;
        kal_uint32 version;
        kal_uint16 rp_num;
        kal_uint16 content_num;
        kal_uint32 complete;
    };

    struct srv_mot_db_category_num_t
    {
        kal_uint16 num[SRV_MOT_CAT_SYSTEM_DEFINE_NUM + 1];  // 9 + 1, aling to 4 bytes
    };

    struct srv_mot_db_recent_play_t
    {
        kal_uint16 id;
        kal_wchar filepath[SRV_MOT_FILE_PATH_LEN + 1];
        kal_uint64 playtime;
        kal_bool is_valid;
    };

    struct srv_mot_db_meta_t
    {
        kal_uint16 id;
        srv_mot_content_info_struct info;
        srv_mot_file_path_struct path;
    };

#endif

static MMI_BOOL _mot_if_is_video(kal_wchar* filename)
{
    filetypes_group_type_enum   file_grp;
    filetypes_file_type_enum    file_type;

    file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filename_str(filename);
    file_grp = srv_fmgr_types_find_group_by_type(file_type);

    if (file_grp == FMGR_GROUP_VIDEO)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

static void _mot_send_msg(module_type dst, U32 msg_id, void *local_param_ptr)
{
    module_type src_mod_id = stack_get_active_module_id();
    ilm_struct *ilm_ptr = allocate_ilm(src_mod_id);

    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = dst;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type)msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}

static void _mot_send_update_req(srv_mot_context_t* self)
{
    CONSTRUCT_LOCAL_PARAM(srv_mot_update_req_struct, req);

    req->context = (kal_uint32)self;

    _mot_send_msg(MOT_BACKGROUND_MOD, MSG_ID_MOT_UPDATE_REQ, req);
}

static void _mot_send_stop_updating_req(srv_mot_context_t* self)
{
    CONSTRUCT_LOCAL_PARAM(srv_mot_stop_updating_req_struct, req);

    req->context = (kal_uint32)self;

    _mot_send_msg(MOT_BACKGROUND_MOD, MSG_ID_MOT_STOP_UPDATING_REQ, req);
}

static void _mot_send_event_ind(srv_mot_context_t* self, srv_mot_cb_evt_enum event, kal_uint32 param)
{
    CONSTRUCT_LOCAL_PARAM(srv_mot_event_ind_struct, req);

    req->context = (kal_uint32)self;
    req->event = (kal_uint32)event;
    req->param = (kal_uint32)param;

    _mot_send_msg(MOT_CONTROL_MOD, MSG_ID_MOT_EVENT_IND, req);
}

static void* _mot_alloc_mem(srv_mot_context_t* self, kal_uint32 size, long line_p)
{
    kal_uint8* block;

    kal_take_mutex(self->task_mutex);

    block = (kal_uint8*) applib_asm_alloc_nc_r(self->app_id, size);
    if (block)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_MEM_ALLOC, block, size, line_p);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_MEM_ALLOC_FAIL, size, line_p);
        ASSERT(0);
    }

    kal_give_mutex(self->task_mutex);

    return block;
}

static void _mot_free_mem(srv_mot_context_t* self, void** p, long line_p)
{
    kal_take_mutex(self->task_mutex);

    if (*p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_MEM_FREE, *p, line_p);

        applib_asm_free_r(self->app_id, *p);
        *p = NULL;
    }

    kal_give_mutex(self->task_mutex);
}

static void _mot_set_state(srv_mot_context_t* self, srv_mot_state_enum new_state, U32 line)
{
    self->state = new_state;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_STATE, new_state, line);
}

static kal_wchar* _mot_get_db_path(srv_mot_context_t* self, kal_char drv_letter)
{
    kal_wchar* dir = _mot_alloc_mem(self, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar), __LINE__);

    kal_mem_set(dir, 0, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar));

    kal_wsprintf(dir, "%c", drv_letter);
    kal_wstrcpy(dir + 1, SRV_MOT_SETTING_PATH);  /* keep the "X:\\" prefix */

    if (FS_GetAttributes(dir) < 0) {
        FS_CreateDir(dir);
    }

    #ifndef __LOW_COST_SUPPORT_ULC__
        FS_SetAttributes(dir, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    #endif

    kal_wstrcpy(dir + 1 + kal_wstrlen(SRV_MOT_SETTING_PATH), SRV_MOT_DB_NAME);  /* append db name */

    return dir;
}


static kal_wchar* _mot_get_med_dir(srv_mot_context_t* self, kal_char drv_letter)
{
    kal_wchar* dir = _mot_alloc_mem(self, SRV_MOT_FOLDER_LEN * sizeof(kal_wchar), __LINE__);

    kal_mem_set(dir, 0, SRV_MOT_FOLDER_LEN * sizeof(kal_wchar));

    kal_wsprintf(dir, "%c", drv_letter);
    kal_wstrcpy(dir + 1, SRV_MOT_FOLDER_NAME);  /* keep the "X:\\" prefix */

    if (FS_GetAttributes(dir) < 0) {
        FS_CreateDir(dir);
    }

    return dir;
}


static srv_mot_ret_enum _mot_close_core(srv_mot_context_t* self)
{
    if (self->med_dir)
    {
        _mot_free_mem(self, (void*)&self->med_dir, __LINE__);
    }

    if (self->db_path)
    {
        _mot_free_mem(self, (void*)&self->db_path, __LINE__);
    }

    #ifdef __SRV_MOT_SQLITE_VERSION__
        if (self->db_journal_path)
        {
            _mot_free_mem(self, (void*)&self->db_journal_path, __LINE__);
        }
        if (self->sql_buf)
        {
            _mot_free_mem(self, (void*)&self->sql_buf, __LINE__);
        }
    #else
        if (self->curr_db_meta)
        {
            _mot_free_mem(self, (void*)&self->curr_db_meta, __LINE__);
        }
        if (self->category)
        {
            _mot_free_mem(self, (void*)&self->category, __LINE__);
        }
    #endif

    return SRV_MOT_S_OK;
}

#ifdef __SRV_MOT_SQLITE_VERSION__
static srv_mot_ret_enum _mot_sql_commit(srv_mot_context_t* self)
{
    kal_int32 res;

    res = sqlite3_exec(self->sqlite_db, "COMMIT", NULL, 0, NULL);
    sqlite3_exec(self->sqlite_db, "BEGIN TRANSACTION", NULL, 0, NULL);

    if (res == SQLITE_OK || res == SQLITE_DONE)
    {
        return SRV_MOT_S_OK;
    }
    else
    {
        return SRV_MOT_E_FAIL;
    }
}

static srv_mot_ret_enum _mot_sql_update_db_version(srv_mot_context_t *self, const kal_int32 db_version)
{
    kal_int32 res;
    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(self->sqlite_db, "REPLACE INTO db_version (id, db_ver) values (?, ?)",
                                                -1, &stmt, NULL);
    sqlite3_bind_kal_int32(stmt, 1, 0);
    sqlite3_bind_kal_int32(stmt, 2, db_version);
    res = sqlite3_step(stmt);

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    if (res != SQLITE_OK && res != SQLITE_DONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sql_create_table(srv_mot_context_t* self)
{
    kal_int32 res;
    srv_mot_ret_enum ret;

    /* set text encoding */
    sqlite3_exec(self->sqlite_db, "PRAGMA encoding =\"UTF-16be\"", 0, 0, 0);

    /* create db version table */
    res = sqlite3_exec(self->sqlite_db, MOT_TABLE_DB_VERSION, NULL, 0, NULL);
    if (res != SQLITE_OK && res != SQLITE_DONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    res = sqlite3_exec(self->sqlite_db, MOT_TABLE_META, NULL, 0, NULL);
    if (res != SQLITE_OK && res != SQLITE_DONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }
    //sqlite3_exec(self->sqlite_db, MOT_TABLE_FAVORITE, NULL, 0, NULL);
    //sqlite3_exec(self->sqlite_db, MOT_TABLE_CAT_COUNT, NULL, 0, NULL);
    res = sqlite3_exec(self->sqlite_db, MOT_TABLE_RECENT_PLAY, NULL, 0, NULL);
    if (res != SQLITE_OK && res != SQLITE_DONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    ret = _mot_sql_update_db_version(self, MOT_DATABASE_CURRENT_VERSION);

    return ret;
}

static srv_mot_ret_enum _mot_sql_db_check_validity(srv_mot_context_t* self)
{
    kal_int32 res, total_res = 0;
    sqlite3_stmt *stmt;
    kal_uint32 db_ver = (kal_uint32)-1;

    sqlite3_prepare_v2(self->sqlite_db, "SELECT db_ver FROM db_version WHERE id=0",
                                                -1, &stmt, NULL);
    res = sqlite3_step(stmt);

    if (res == SQLITE_ROW)
    {
        db_ver = sqlite3_column_kal_uint32(stmt, 0);
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    if (res != SQLITE_ROW ||
        db_ver != MOT_DATABASE_CURRENT_VERSION)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, db_ver, __LINE__);
        return SRV_MOT_E_FAIL;
    }

    /* SQLITE_OK = 0, test all tables*/
    res = sqlite3_exec(self->sqlite_db, "SELECT COUNT(id) FROM meta", NULL, 0, NULL);
    total_res |= (res << 0);

    if (total_res)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        return SRV_MOT_E_FAIL;
    }

    // check drive letter.
    sqlite3_prepare_v2(self->sqlite_db, "SELECT filepath FROM meta",
                                            -1, &stmt, NULL);
    res = sqlite3_step(stmt);

    if (res == SQLITE_ROW)
    {
        const kal_char* str;

        str = sqlite3_column_kal_str(stmt, 0);

        if (str[0] != self->drive_letter)
        {
            total_res = SRV_MOT_E_FAIL;
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    if (total_res)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, total_res, __LINE__);
        return SRV_MOT_E_FAIL;
    }

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sql_db_error_recover(srv_mot_context_t* self)
{
    kal_int32 res;
    srv_mot_ret_enum ret;

    //kal_trace(TRACE_FUNC, MBBMS_SG_DB_DB_ERROR_RECOVER);

    _mot_sql_close_db(self);
    res = FS_Delete(self->db_path);

    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PRESERVED_DISK_SPACE) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH, __LINE__);

        return SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }

    res = sqlite3_open16(self->db_path, &self->sqlite_db);
    if (res != SQLITE_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        _mot_sql_close_db(self);

        return SRV_MOT_E_DB_OPEN_FAIL;
    }

    sqlite3_exec(self->sqlite_db, "BEGIN TRANSACTION", NULL, 0, NULL);

    ret = _mot_sql_create_table(self);

    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, res, __LINE__);
        _mot_sql_close_db(self);
    }

    return ret;
}

static srv_mot_ret_enum _mot_sql_open_db(srv_mot_context_t* self, const kal_wchar *db_path)
{
    kal_int32 res;
    srv_mot_ret_enum ret = SRV_MOT_S_OK;

    if (self->sqlite_db)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_WRONG_STATE, __LINE__);
        return SRV_MOT_E_WRONG_STATE;
    }

    sqlite3_enter_instance(&self->sql_ctx);

    if (FS_GetAttributes(db_path) < 0)
    {
        // indicate client that DB is not exist, will be opened with empty content.
        ret = SRV_MOT_S_EMPTY;
    }

    /* sqlite open db */
    res = sqlite3_open16(db_path, &self->sqlite_db);
    if (res != SQLITE_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_OPEN_FAIL, __LINE__);
        _mot_set_state(self, SRV_MOT_STATE_ERROR, __LINE__);

        sqlite3_exit_instance(&self->sql_ctx);

        _mot_sql_close_db(self);

        return SRV_MOT_E_DB_OPEN_FAIL;
    }

    sqlite3_exec(self->sqlite_db, "BEGIN TRANSACTION", NULL, 0, NULL);

    sqlite3_exit_instance(&self->sql_ctx);

    return ret;
}

static void _mot_sql_free_query_stmt(srv_mot_context_t* self)
{
    sqlite3_finalize(self->stmt_query);
    sqlite3_finalize(self->stmt_query_op1);
    self->stmt_query = NULL;
    self->stmt_query_op1 = NULL;
    self->last_query_type = SRV_MOT_QUERY_TYPE_NONE;
}

static srv_mot_ret_enum _mot_sql_close_db(srv_mot_context_t* self)
{
    if (!self->sqlite_db)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_S_FALSE, __LINE__);
        return SRV_MOT_S_FALSE;
    }

    sqlite3_enter_instance(&self->sql_ctx);

    _mot_sql_free_query_stmt(self);

    _mot_sql_commit(self);

    sqlite3_close(self->sqlite_db);
    self->sqlite_db = NULL;

    sqlite3_exit_instance(&self->sql_ctx);

    FS_Delete(self->db_journal_path);

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sql_clear_meta(srv_mot_context_t* self)
{
    sqlite3_exec(self->sqlite_db, "DELETE FROM meta", NULL, 0, NULL);

    _mot_sql_commit(self);

    return SRV_MOT_S_OK;
}

srv_mot_ret_enum _mot_sql_purify_recent_playlist(srv_mot_context_t* self)
{
    sqlite3_stmt *stmt;

    /* compare with current time, delete out-of-date data */
    sqlite3_prepare_v2(self->sqlite_db, "DELETE FROM recent_play WHERE filepath NOT IN (SELECT meta.filepath FROM meta JOIN recent_play ON meta.filepath=recent_play.filepath)",
                                                -1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    _mot_sql_commit(self);

    return SRV_MOT_S_OK;
}

#else

static srv_mot_ret_enum _mot_sdb_write_header(srv_mot_context_t* self, kal_uint16 content_num, kal_bool complete)
{
    srv_mot_db_header_t header;
    kal_int32 fserr;

    header.signature = SRV_MOT_DB_SIGNATURE;
    header.version = SRV_MOT_DB_VER;
    header.rp_num = SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER;
    header.content_num = content_num;
    header.complete = complete;

    // write header
    FS_Seek(self->fh_sdb, SRV_MOT_DB_HEADER_OFFSET, FS_FILE_BEGIN);
    fserr = FS_Write(self->fh_sdb, &header, sizeof(header), NULL);
    if (fserr < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sdb_write_category_num(srv_mot_context_t* self)
{
    kal_int32 fserr;

    // write header
    FS_Seek(self->fh_sdb, SRV_MOT_DB_CATEGORY_NUM_OFFSET, FS_FILE_BEGIN);
    fserr = FS_Write(self->fh_sdb, self->category, sizeof(srv_mot_db_category_num_t), NULL);
    if (fserr < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sdb_clean_out_recent_play(srv_mot_context_t* self)
{
    srv_mot_db_recent_play_t rp;
    kal_int32 i;

    // pre-set recent play list
    kal_mem_set(&rp, 0, sizeof(rp));

    FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
    // write recent play record * n
    for (i = 0; i < SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER; i++)
    {
        kal_int32 fserr;
        fserr = FS_Write(self->fh_sdb, &rp, sizeof(rp), NULL);
        if (fserr < 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
            return SRV_MOT_E_DB_IO_ERROR;
        }
    }

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sdb_db_check_validity(srv_mot_context_t* self)
{
    kal_int32 fserr;
    kal_uint32 len;
    srv_mot_db_header_t header;

    FS_Seek(self->fh_sdb, SRV_MOT_DB_HEADER_OFFSET, FS_FILE_BEGIN);
    fserr = FS_Read(self->fh_sdb, &header, sizeof(header), &len);

    if (fserr < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
        return SRV_MOT_E_FAIL;
    }
    else if (len != sizeof(header))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, len, __LINE__);
        return SRV_MOT_E_FAIL;
    }
    else if (header.signature != SRV_MOT_DB_SIGNATURE ||
             header.version != SRV_MOT_DB_VER ||
             header.rp_num != SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER ||
             header.content_num > SRV_MOT_MAX_RECORD_NUMBER ||
             header.complete != KAL_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, header.signature, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, header.version, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, header.rp_num, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, header.content_num, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, header.complete, __LINE__);
        return SRV_MOT_E_FAIL;
    }

    // check drive letter.
    if (header.content_num)
    {
        FS_Seek(self->fh_sdb, SRV_MOT_DB_META_OFFSET, FS_FILE_BEGIN);
        fserr = FS_Read(self->fh_sdb, self->curr_db_meta, sizeof(srv_mot_db_meta_t), &len);
        if (fserr >= 0)
        {
            if ((kal_char)self->curr_db_meta->path.filepath[0] != self->drive_letter)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, self->curr_db_meta->path.filepath[0], __LINE__);
                return SRV_MOT_E_FAIL;
            }
        }
    }

    /*****  DB validate OK *****/

    // load current content number for query.
    self->update_count = header.content_num;

    // read category number
    FS_Seek(self->fh_sdb, SRV_MOT_DB_CATEGORY_NUM_OFFSET, FS_FILE_BEGIN);
    fserr = FS_Read(self->fh_sdb, self->category, sizeof(srv_mot_db_category_num_t), &len);


    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sdb_close_db(srv_mot_context_t* self)
{
    FS_Close(self->fh_sdb);

    self->fh_sdb = 0;
    self->last_query_type = SRV_MOT_QUERY_TYPE_NONE;

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_sdb_create_table(srv_mot_context_t* self)
{
    srv_mot_ret_enum ret;

    ret = _mot_sdb_write_header(self, 0, KAL_TRUE);
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, ret, __LINE__);
        return ret;
    }

    // pre-set category number
    kal_mem_set(self->category, 0, sizeof(srv_mot_db_category_num_t));
    ret = _mot_sdb_write_category_num(self);
    if (ret < 0)
    {
        return ret;
    }

    ret = _mot_sdb_clean_out_recent_play(self);

    return ret;
}

static srv_mot_ret_enum _mot_sdb_db_error_recover(srv_mot_context_t* self)
{
    srv_mot_ret_enum ret;

    _mot_sdb_close_db(self);
    FS_Delete(self->db_path);

    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PRESERVED_DISK_SPACE) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_PRESERVED_DISK_SPACE, __LINE__);

        return SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }

    /* sqlite open db */
    self->fh_sdb = FS_Open(self->db_path, FS_READ_WRITE | FS_OPEN_SHARED | FS_CREATE_ALWAYS);
    if (self->fh_sdb < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_OPEN_FAIL, __LINE__);
        _mot_sdb_close_db(self);

        return SRV_MOT_E_DB_OPEN_FAIL;
    }

    ret = _mot_sdb_create_table(self);
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_IO_ERROR, __LINE__);
        _mot_sdb_close_db(self);
    }

    return ret;
}


static srv_mot_ret_enum _mot_sdb_open_db(srv_mot_context_t* self, const kal_wchar *db_path)
{
    srv_mot_ret_enum ret = SRV_MOT_S_OK;

    // reset this counter if reopen.
    self->update_count = 0;
    self->last_query_type = SRV_MOT_QUERY_TYPE_NONE;

    if (self->fh_sdb != 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_WRONG_STATE, __LINE__);
        return SRV_MOT_E_WRONG_STATE;
    }

    if (FS_GetAttributes(db_path) < 0)
    {
        // indicate client that DB is not exist, will be opened with empty content.
        ret = SRV_MOT_S_EMPTY;
    }

    /* sqlite open db */
    self->fh_sdb = FS_Open(db_path, FS_READ_WRITE | FS_OPEN_SHARED | FS_CREATE);
    if (self->fh_sdb < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_OPEN_FAIL, __LINE__);
        _mot_set_state(self, SRV_MOT_STATE_ERROR, __LINE__);

        _mot_sdb_close_db(self);

        return SRV_MOT_E_DB_OPEN_FAIL;
    }

    return ret;
}

#endif

static srv_mot_ret_enum _mot_update_prepare(srv_mot_context_t* self)
{
    self->curr_filename = _mot_alloc_mem(self, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar), __LINE__);
    self->curr_filepath = _mot_alloc_mem(self, SRV_MOT_FILE_PATH_LEN * sizeof(kal_wchar), __LINE__);
    self->fs_search_filter = (WCHAR*)_mot_alloc_mem(self, SRV_MOT_FOLDER_LEN * sizeof(kal_wchar), __LINE__);
    self->curr_handle = FS_INVALID_FILE_HANDLE;

    self->mot_meta = _mot_alloc_mem(self, sizeof(mdi_video_mot_meta_struct), __LINE__);

    self->mot_meta->title_desc_len = SRV_MOT_TITLE_LEN;
    self->mot_meta->title_desc_ptr = _mot_alloc_mem(self, SRV_MOT_TITLE_LEN * sizeof(kal_wchar), __LINE__);

    self->mot_meta->artist_desc_len = SRV_MOT_ARTIST_LEN;
    self->mot_meta->artist_desc_ptr = _mot_alloc_mem(self, SRV_MOT_ARTIST_LEN * sizeof(kal_wchar), __LINE__);

    self->mot_meta->date_desc_len = SRV_MOT_DATETIME_LEN;
    self->mot_meta->date_desc_ptr = _mot_alloc_mem(self, SRV_MOT_DATETIME_LEN * sizeof(kal_wchar), __LINE__);

    self->mot_meta->annotation_desc_len = SRV_MOT_DESCRIPT_LEN;
    self->mot_meta->annotation_desc_ptr = _mot_alloc_mem(self, SRV_MOT_DESCRIPT_LEN * sizeof(kal_wchar), __LINE__);

    self->mot_meta->type_desc_len = SRV_MOT_CATEGORY_LEN;
    self->mot_meta->type_desc_ptr = _mot_alloc_mem(self, SRV_MOT_CATEGORY_LEN * sizeof(kal_wchar), __LINE__);

    self->mot_meta->thumb_allocated_len = SRV_MOT_THUMBNAIL_SIZE;
    self->mot_meta->thumb_ptr = _mot_alloc_mem(self, SRV_MOT_THUMBNAIL_SIZE, __LINE__);

    self->update_count = 0;

    #ifdef __SRV_MOT_SQLITE_VERSION__

        sqlite3_enter_instance(&self->sql_ctx);

        // make sure all stmt freed.
        _mot_sql_free_query_stmt(self);
        _mot_sql_clear_meta(self);

        if (self->stmt)
        {
            sqlite3_finalize(self->stmt);
        }
        //"CREATE TABLE IF NOT EXISTS meta (id INTEGER PRIMARY KEY, filename TEXT, " \
        //                                "filepath TEXT, title TEXT, artist TEXT, date TEXT, duration INTEGER, description TEXT, category INTEGER, thumbnail BLOB);" \
        //                            "CREATE INDEX IF NOT EXISTS idx_filename ON meta (filename)"
        sqlite3_prepare_v2(self->sqlite_db, "REPLACE INTO meta (id, filename, filepath, title, artist, date, duration, description, category, thumbnail) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                                                    -1, &self->stmt, NULL);

        sqlite3_exit_instance(&self->sql_ctx);

    #else

        _mot_sdb_write_header(self, 0, KAL_FALSE);
        kal_mem_set(self->category, 0, sizeof(srv_mot_db_category_num_t));
        FS_Seek(self->fh_sdb, SRV_MOT_DB_META_OFFSET, FS_FILE_BEGIN);

    #endif

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_update_unprepare(srv_mot_context_t* self)
{
    _mot_free_mem(self, (void**)&self->curr_filename, __LINE__);
    _mot_free_mem(self, (void**)&self->curr_filepath, __LINE__);
    _mot_free_mem(self, (void**)&self->fs_search_filter, __LINE__);

    if (self->curr_handle >= FS_NO_ERROR)
    {
    #ifdef __SRV_MOT_FS_SORT__
        if (self->fs_xfind)
        {
            FS_XFindClose(&self->fs_xfind_pos);
            self->fs_xfind_pos = 0;
        }
        else
    #endif
        {
            FS_FindClose(self->curr_handle);
        }

        self->curr_handle = FS_INVALID_FILE_HANDLE;
    }

    if (self->mot_meta)
    {
        _mot_free_mem(self, (void**)&self->mot_meta->title_desc_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta->artist_desc_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta->date_desc_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta->annotation_desc_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta->type_desc_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta->thumb_ptr, __LINE__);
        _mot_free_mem(self, (void**)&self->mot_meta, __LINE__);
    }

    #ifdef __SRV_MOT_SQLITE_VERSION__
        sqlite3_enter_instance(&self->sql_ctx);

        sqlite3_finalize(self->stmt);
        self->stmt = NULL;

        _mot_sql_purify_recent_playlist(self);

        sqlite3_exit_instance(&self->sql_ctx);
    #else

        // set DB "update complete"
        _mot_sdb_write_header(self, self->update_count, KAL_TRUE);
        _mot_sdb_write_category_num(self);
        _mot_sdb_clean_out_recent_play(self);

    #endif

    return SRV_MOT_S_OK;
}

static srv_mot_ret_enum _mot_update_reset_meta(srv_mot_context_t* self)
{
    kal_mem_set(self->mot_meta->title_desc_ptr, 0, SRV_MOT_TITLE_LEN * sizeof(kal_wchar));
    kal_mem_set(self->mot_meta->artist_desc_ptr, 0, SRV_MOT_ARTIST_LEN * sizeof(kal_wchar));
    kal_mem_set(self->mot_meta->date_desc_ptr, 0, SRV_MOT_DATETIME_LEN * sizeof(kal_wchar));
    kal_mem_set(self->mot_meta->annotation_desc_ptr, 0, SRV_MOT_DESCRIPT_LEN * sizeof(kal_wchar));
    kal_mem_set(self->mot_meta->type_desc_ptr, 0, SRV_MOT_CATEGORY_LEN * sizeof(kal_wchar));
    kal_mem_set(self->mot_meta->thumb_ptr, 0, SRV_MOT_THUMBNAIL_SIZE);

    self->mot_meta->thumb_usaged_len = 0;
    self->mot_meta->thumb_type = MDI_VIDEO_THUMB_NONE;

    return SRV_MOT_S_OK;
}

static srv_mot_cat_enum _mot_update_translate_category_str(kal_wchar* str)
{
    if (str[0] == 0)
    {
        return SRV_MOT_CAT_OTHERS;
    }

    if ((!kal_wstrcmp(str, MOT_META_STR_ACTION_ADVENTURE))
        ||(!kal_wstrcmp(str, MOT_META_STR_ADVENTURE_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_ACTION_KMV)))
    {
        return SRV_MOT_CAT_ACTION_ADVENTURE;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_ROMANCE_ETHICS))
        ||(!kal_wstrcmp(str, MOT_META_STR_FAMILY_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_ROMANCE_KMV)))
    {
        return SRV_MOT_CAT_ROMANCE_ETHICS;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_COMEDY_HUMOR))
        ||(!kal_wstrcmp(str, MOT_META_STR_COMEDY_KMV)))
    {
        return SRV_MOT_CAT_COMEDY_HUMOR;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_TV_DRAMA))
        ||(!kal_wstrcmp(str, MOT_META_STR_DRAMA_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_WEATERN_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_WAR_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_SPORTS_KMV)))
    {
        return SRV_MOT_CAT_TV_DRAMA;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_ANIMATION_SCIFI))
        ||(!kal_wstrcmp(str, MOT_META_STR_ANIMATION_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_FANTASY_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_SCIFI_KMV)))
    {
        return SRV_MOT_CAT_ANIMATION_SCIFI;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_THRILLER_MYSTERY))
        ||(!kal_wstrcmp(str, MOT_META_STR_HORROR_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_MYSTERY_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_SUSPENSE_KMV)))
    {
        return SRV_MOT_CAT_THRILLER_MYSTERY;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_MUSIC_PERFORMANCE))
        ||(!kal_wstrcmp(str, MOT_META_STR_MUSIC_KMV))
        ||(!kal_wstrcmp(str, MOT_META_STR_PERFORMANCE_KMV)))
    {
        return SRV_MOT_CAT_MUSIC_PERFORMANCE;
    }
    else if ((!kal_wstrcmp(str, MOT_META_STR_DOCUMENTARY))
        ||(!kal_wstrcmp(str, MOT_META_STR_DOCUMENTARY_KMV)))
    {
        return SRV_MOT_CAT_DOCUMENTARY;
    }
    else
    {
        return SRV_MOT_CAT_OTHERS;
    }
}

static srv_mot_ret_enum _mot_update_insert_meta(srv_mot_context_t* self, kal_uint64 duration)
{
#ifdef __SRV_MOT_SQLITE_VERSION__
    kal_int32 res;

    sqlite3_bind_null(self->stmt, 1);
    srv_fmgr_fs_path_get_display_name(self->curr_filepath, self->curr_filename, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar));
    sqlite3_bind_kal_wstr(self->stmt, 2, self->curr_filename);
    sqlite3_bind_kal_wstr(self->stmt, 3, self->curr_filepath);
    if (self->mot_meta->title_desc_ptr[0])
    {
        sqlite3_bind_kal_wstr(self->stmt, 4, self->mot_meta->title_desc_ptr);
    }
    else
    {
        sqlite3_bind_null(self->stmt, 4);
    }

    if (self->mot_meta->artist_desc_ptr[0])
    {
        sqlite3_bind_kal_wstr(self->stmt, 5, self->mot_meta->artist_desc_ptr);
    }
    else
    {
        sqlite3_bind_null(self->stmt, 5);
    }

    if (self->mot_meta->date_desc_ptr[0])
    {
        sqlite3_bind_kal_wstr(self->stmt, 6, self->mot_meta->date_desc_ptr);
    }
    else
    {
        sqlite3_bind_null(self->stmt, 6);
    }

    sqlite3_bind_kal_uint64(self->stmt, 7, duration);

    if (self->mot_meta->annotation_desc_ptr[0])
    {
        sqlite3_bind_kal_wstr(self->stmt, 8, self->mot_meta->annotation_desc_ptr);
    }
    else
    {
        sqlite3_bind_null(self->stmt, 8);
    }

    sqlite3_bind_kal_int32(self->stmt, 9, _mot_update_translate_category_str(self->mot_meta->type_desc_ptr));

    if (self->mot_meta->thumb_usaged_len)
    {
        sqlite3_bind_blob(self->stmt,10, self->mot_meta->thumb_ptr, self->mot_meta->thumb_usaged_len, SQLITE_STATIC);
    }
    else
    {
        sqlite3_bind_null(self->stmt,10);
    }

    res = sqlite3_step(self->stmt);
    sqlite3_reset(self->stmt);

    if (res == SQLITE_DONE)
    {
        return SRV_MOT_S_OK;
    }
    else
    {
        return SRV_MOT_E_DB_IO_ERROR;
    }
#else
{
    srv_mot_db_meta_t *meta_p = self->curr_db_meta;
    kal_int32 fserr;

    kal_mem_set(meta_p, 0 , sizeof(srv_mot_db_meta_t));

    srv_fmgr_fs_path_get_display_name(self->curr_filepath, self->curr_filename, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar));

    meta_p->id = self->update_count;
    kal_wstrncpy(meta_p->path.filepath, self->curr_filepath, SRV_MOT_FILE_PATH_LEN);

    kal_wstrncpy(meta_p->info.filename, self->curr_filename, SRV_MOT_FILE_NAME_LEN);
    meta_p->info.duration = duration;
    kal_wstrncpy(meta_p->info.title, self->mot_meta->title_desc_ptr, SRV_MOT_TITLE_LEN);
    kal_wstrncpy(meta_p->info.datetime, self->mot_meta->date_desc_ptr, SRV_MOT_TITLE_LEN);
    kal_wstrncpy(meta_p->info.artist, self->mot_meta->artist_desc_ptr, SRV_MOT_ARTIST_LEN);
    kal_wstrncpy(meta_p->info.descript, self->mot_meta->annotation_desc_ptr, SRV_MOT_TITLE_LEN);

    meta_p->info.category = _mot_update_translate_category_str(self->mot_meta->type_desc_ptr);
    meta_p->info.thumbnail_size = self->mot_meta->thumb_usaged_len;

    if (meta_p->info.thumbnail_size && meta_p->info.thumbnail_size <= SRV_MOT_THUMBNAIL_SIZE)
    {
        kal_mem_cpy(meta_p->info.thumbnail_buf, self->mot_meta->thumb_ptr, self->mot_meta->thumb_usaged_len);
    }
    else
    {
        meta_p->info.thumbnail_size = 0;
    }

    fserr = FS_Write(self->fh_sdb, meta_p, sizeof(srv_mot_db_meta_t), NULL);
    if (fserr < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
        return SRV_MOT_E_DB_IO_ERROR;
    }

    // count category number
    self->category->num[(kal_int32)meta_p->info.category]++;

    return SRV_MOT_S_OK;
}
#endif
}

static srv_mot_ret_enum _mot_update_core(srv_mot_context_t* self)
{
    kal_int32 fs_ret;
    srv_mot_ret_enum ret = SRV_MOT_S_FINISH;
    FS_DOSDirEntry *file_info;
    MDI_RESULT mdi_ret;

    kal_mem_set(self->curr_filename, 0, sizeof(self->curr_filename));
    kal_mem_set(self->curr_filepath, 0, sizeof(self->curr_filepath));
    _mot_update_reset_meta(self);

    file_info = (FS_DOSDirEntry*)_mot_alloc_mem(self, sizeof(FS_DOSDirEntry), __LINE__);
    if (self->curr_handle == FS_INVALID_FILE_HANDLE)
    {
    #ifdef __SRV_MOT_FS_SORT__
        FS_SortingParam sort_param;
    #endif

        kal_mem_set(self->fs_search_filter, 0, SRV_MOT_FOLDER_LEN * sizeof(kal_wchar));
        mmi_ucs2ncpy((CHAR*)self->fs_search_filter, (const CHAR*)self->med_dir, SRV_MOT_FOLDER_LEN);
        mmi_ucs2ncat((CHAR*)self->fs_search_filter, (const CHAR*)L"*.*", 3);

    #ifdef __SRV_MOT_FS_SORT__
        self->fs_xfind = KAL_FALSE;
        self->fs_xfind_idx = 0;
        self->fs_xfind_pos = 0;

        sort_param.Pattern = (WCHAR*) self->fs_search_filter;
        sort_param.PatternArray = NULL;
        sort_param.PatternNum = 0;
        sort_param.ArrayMask = FS_ATTR_DIR;
        sort_param.AttrMask = FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME;
        sort_param.Flag = FS_DIR_TYPE | FS_FILE_TYPE | FS_SORT_NAME;
        sort_param.Timeout = FS_INFINITE;
        sort_param.Position = &self->fs_xfind_pos;
        sort_param.ProgressCallback = NULL;
        sort_param.ProgressCallbackParam = NULL;
        sort_param.CompareFunc = NULL;
        memset((PU8) self->fs_sorting_buffer, 0, SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE);
        sort_param.SortingBuffer = self->fs_sorting_buffer;
        sort_param.SortingBufferSize = sizeof(self->fs_sorting_buffer);
        memset((PU8) self->fs_working_buffer, 0, SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE);
        sort_param.WorkingBuffer = self->fs_working_buffer;
        sort_param.WorkingBufferSize = sizeof(self->fs_working_buffer);

        fs_ret = FS_XFindReset(&sort_param);
        if (fs_ret >= FS_NO_ERROR)
        {
            self->fs_xfind = KAL_TRUE;
        }
    #endif /* __SRV_MOT_FS_SORT__ */


    #ifdef __SRV_MOT_FS_SORT__
        if (self->fs_xfind)
        {
            fs_ret = FS_XFindStart(
                        (PU16) self->fs_search_filter,
                        file_info,
                        (PU16) self->curr_filename,
                        SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar),
                        self->fs_xfind_idx,
                        &self->fs_xfind_pos,
                        FS_FIND_DEFAULT);
            self->fs_xfind_idx++;
            if (fs_ret < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fs_ret, __LINE__);
            }
        }
        else
    #endif
        {
            fs_ret = FS_FindFirstN((WCHAR*)self->fs_search_filter, NULL, 0,
                                FS_ATTR_DIR, 0, FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                                file_info, (WCHAR*)self->curr_filename, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar),
                                0, FS_FIND_DEFAULT);
        }

        if (fs_ret >= FS_NO_ERROR)
        {
            self->curr_handle = fs_ret;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fs_ret, __LINE__);
        }
    }
    else
    {
    #ifdef __SRV_MOT_FS_SORT__
        if (self->fs_xfind)
        {
            fs_ret = FS_XFindStart(
                        (PU16) self->fs_search_filter,
                        file_info,
                        (PU16) self->curr_filename,
                        SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar),
                        self->fs_xfind_idx,
                        &self->fs_xfind_pos,
                        FS_FIND_DEFAULT);
            self->fs_xfind_idx++;
            if (fs_ret < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fs_ret, __LINE__);
            }
        }
        else
    #endif
        {
            fs_ret = FS_FindNextN(self->curr_handle, NULL, 0,
                                  FS_ATTR_DIR, file_info, (WCHAR*)self->curr_filename, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar),
                                  FS_FIND_DEFAULT);
        }
    }
    _mot_free_mem(self, (void**)&file_info, __LINE__);

    /* find media file, start process */
    if (fs_ret >= FS_NO_ERROR)
    {
        if (_mot_if_is_video(self->curr_filename))
        {
            mdi_video_info_struct *video_info;

            kal_wsprintf(self->curr_filepath, "%w%w", self->med_dir, self->curr_filename);

            video_info = (mdi_video_info_struct*)_mot_alloc_mem(self, sizeof(mdi_video_info_struct), __LINE__);

            mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_INFO);
            mdi_ret = mdi_video_ply_open_clip_file(self->app_id, (const CHAR*)self->curr_filepath, video_info);
            if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
            {
                self->mot_meta->thumb_usaged_len = 0;
                mdi_video_ply_get_mot_meta(self->mot_meta);
                mdi_video_ply_close_clip_file();
                ret = _mot_update_insert_meta(self, video_info->total_time_duration);
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, mdi_ret, __LINE__);
                ret = SRV_MOT_S_FALSE;
            }

            _mot_free_mem(self, (void**)&video_info, __LINE__);
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_S_FALSE, __LINE__);
            ret = SRV_MOT_S_FALSE;
        }
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fs_ret, __LINE__);
        // check if DISK IO ERROR?
        if (fs_ret == FS_MSDC_MOUNT_ERROR ||
            fs_ret == FS_MEDIA_CHANGED ||
            fs_ret == FS_INVALID_FILE_HANDLE ||
            fs_ret == FS_MSDC_READ_SECTOR_ERROR)
        {
            ret = SRV_MOT_E_IO_ERROR;
            self->last_fs_error = fs_ret;
        }
    }

    return ret;
}

static srv_mot_ret_enum _mot_update_loop(srv_mot_context_t* self)
{
    srv_mot_ret_enum result = SRV_MOT_S_OK;

    #ifdef __SRV_MOT_SQLITE_VERSION__
        sqlite3_enter_instance(&self->sql_ctx);
    #endif

    while (self->abort_updating != KAL_TRUE && (result == SRV_MOT_S_OK || result == SRV_MOT_S_FALSE))
    {
        result = _mot_update_core(self);

        if (result == SRV_MOT_S_OK)
        {
            self->update_count++;

            #ifdef __SRV_MOT_SQLITE_VERSION__
                if ((self->update_count % MOT_UPDATE_COMMIT_FACTOR) == 0)
                {
                    // if any error happened when flush to disk, it must disk IO error.
                    result = _mot_sql_commit(self);
                }
            #endif

            if (self->update_count >= SRV_MOT_MAX_RECORD_NUMBER)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_S_FINISH, __LINE__);
                result = SRV_MOT_S_FINISH;
                break;
            }

            // jump out for other PLS client.
            if ((self->update_count % MOT_UPDATE_ROUND_ITERATOR) == 0)
            {
                result = SRV_MOT_S_LIMIT;
                break;
            }
        }
    }

    #ifdef __SRV_MOT_SQLITE_VERSION__
        sqlite3_exit_instance(&self->sql_ctx);
    #endif

    if (self->abort_updating && (result == SRV_MOT_S_OK || result == SRV_MOT_S_FALSE))
    {
        result = SRV_MOT_E_ABORTED;
    }

    return result;
}

static srv_mot_ret_enum _mot_update_finish(srv_mot_context_t* self, srv_mot_ret_enum result)
{
    _mot_update_unprepare(self);

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_enter_instance(&self->sql_ctx);

    if (result == SRV_MOT_S_FINISH)
    {
        /* reset instance after updating end.*/
        _mot_sql_close_db(self);
        sqlite3_exit_instance(&self->sql_ctx);
        sqlite3_free_instance(&self->sql_ctx);
        sqlite3_init_instance(&self->sql_ctx, self->sql_buf, SRV_MOT_SQL_BUF_SIZE, g_srv_mot_sql_mutex);
        sqlite3_enter_instance(&self->sql_ctx);
        result = _mot_sql_open_db(self, self->db_path);
        if (result >= 0)
        {
            result = SRV_MOT_S_FINISH;
        }
    }

    sqlite3_exit_instance(&self->sql_ctx);
#endif

    /* if not abort, indicate control mod */
    if (result != SRV_MOT_E_ABORTED)
    {
        _mot_send_event_ind(self, SRV_MOT_CB_EVT_UPDATED, result);
    }

    return SRV_MOT_S_OK;
}

static void _mot_update_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(srv_mot_update_req_struct, req, ilm);
    srv_mot_context_t* self = (srv_mot_context_t*)req->context;
    srv_mot_ret_enum result = SRV_MOT_S_OK;

    if (self->state != SRV_MOT_STATE_UPDATING)
    {
        return;
    }

    if (self->mot_meta == NULL)
    {
        // it means 1st time entry.
        _mot_update_prepare(self);
    }

    result = _mot_update_loop(self);

    if (result == SRV_MOT_S_LIMIT)
    {
        // send msg for next loop
        _mot_send_update_req(self);
    }
    else
    {
        // finished!
        _mot_update_finish(self, result);
    }
}

static void _mot_stop_updating_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(srv_mot_stop_updating_req_struct, req, ilm);
    srv_mot_context_t* self = (srv_mot_context_t*)req->context;

    _mot_update_finish(self, SRV_MOT_E_ABORTED);
    _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);

    SRV_MOT_SET_EVENT(SRV_MOT_TASK_EVENT);
}

static void _mot_event_hdlr(void* local_param)
{
    srv_mot_event_ind_struct* ind = (srv_mot_event_ind_struct*)local_param;
    srv_mot_context_t* self = (srv_mot_context_t*)ind->context;
    srv_mot_cb_evt_enum event = (srv_mot_cb_evt_enum)ind->event;
    srv_mot_ret_enum result = (srv_mot_ret_enum)ind->param;

    /* updated */
    _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);

    // do not callback client if aborted by client
    if (result != SRV_MOT_E_ABORTED)
    {
        self->client_cb(self->client, event, result, self->drive_letter);
    }
}

static srv_mot_query_type_enum _mot_convert_content_number_query_type(srv_mot_cat_enum category)
{
    if (category == SRV_MOT_CAT_RECENT_PLAY)
    {
        return SRV_MOT_QUERY_TYPE_NUMBER_BY_RECENT_PLAY;
    }
    else if (category == SRV_MOT_CAT_ALL)
    {
        return SRV_MOT_QUERY_TYPE_NUMBER_BY_ALL;
    }
    else
    {
        return SRV_MOT_QUERY_TYPE_NUMBER_BY_CATEGORY;
    }
}

static srv_mot_query_type_enum _mot_convert_list_info_query_type(srv_mot_cat_enum category)
{
    if (category == SRV_MOT_CAT_RECENT_PLAY)
    {
        return SRV_MOT_QUERY_TYPE_BRIEF_BY_RECENT_PLAY;
    }
    else if (category == SRV_MOT_CAT_ALL)
    {
        return SRV_MOT_QUERY_TYPE_BRIEF_BY_ALL;
    }
    else
    {
        return SRV_MOT_QUERY_TYPE_BRIEF_BY_CATEGORY;
    }
}

static srv_mot_ret_enum _mot_get_list_info_core(srv_mot_context_t* self, srv_mot_list_info_struct* list_info)
{
#ifdef __SRV_MOT_SQLITE_VERSION__
    kal_int32 res;

    res = sqlite3_step(self->stmt_query);

    if (res == SQLITE_ROW)
    {
        list_info->content_id = sqlite3_column_kal_uint32(self->stmt_query, 0);
        kal_wstrncpy(list_info->filename, sqlite3_column_kal_wstr(self->stmt_query, 1), SRV_MOT_FILE_NAME_LEN);
        list_info->duration = sqlite3_column_kal_uint64(self->stmt_query, 2);

        return SRV_MOT_S_OK;
    }

    return SRV_MOT_E_NO_MORE_DATA;
#else
    kal_uint32 len;
    kal_uint16 id;

    id = self->query_id_cache[self->last_query_start_idx];
    if (id == 0xFFFF)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, self->last_query_start_idx, __LINE__);
        return SRV_MOT_E_NO_MORE_DATA;
    }

    FS_Seek(self->fh_sdb, SRV_MOT_DB_META_OFFSET + id*SRV_MOT_DB_META_SIZE, FS_FILE_BEGIN);
    FS_Read(self->fh_sdb, self->curr_db_meta, sizeof(srv_mot_db_meta_t), &len);

    list_info->content_id = self->curr_db_meta->id;
    kal_wstrncpy(list_info->filename, self->curr_db_meta->info.filename, SRV_MOT_FILE_NAME_LEN);
    list_info->duration = self->curr_db_meta->info.duration;

    self->last_query_start_idx++;

    return SRV_MOT_S_OK;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_mot_update_memory_check
 * DESCRIPTION
 *  check if the memory is enough for update
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_update_memory_check(srv_mot_h handle)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret = SRV_MOT_S_OK;
    srv_fmgr_fileinfo_struct file_info;

    if (self->state != SRV_MOT_STATE_OPENED)
    {
        return SRV_MOT_E_WRONG_STATE;
    }

    srv_fmgr_fs_path_get_fileinfo(self->db_path, &file_info);

    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PRESERVED_DISK_SPACE - file_info.size) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_PRESERVED_DISK_SPACE, __LINE__);

        _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);
        ret = SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }

    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_number
 * DESCRIPTION
 *  get video number of particular category.
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_cat_enum    [IN]      category
 *  U32*                [OUT]     number
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_content_number(srv_mot_h handle, srv_mot_cat_enum category, U32 *number)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_query_type_enum curr_query_type = _mot_convert_content_number_query_type(category);

    *number = 0;

#ifdef __SRV_MOT_SQLITE_VERSION__
    // check if DB state OK?
    if (self->sqlite_db == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, self->state, __LINE__);
        return SRV_MOT_E_WRONG_STATE;
    }

    sqlite3_enter_instance(&self->sql_ctx);

    if (self->last_query_type != curr_query_type)
    {
        _mot_sql_free_query_stmt(self);
        self->last_query_type = curr_query_type;
    }

    if (self->stmt_query)
    {
        sqlite3_reset(self->stmt_query);
    }

    if (curr_query_type == SRV_MOT_QUERY_TYPE_NUMBER_BY_RECENT_PLAY)
    {
        if (self->stmt_query == NULL)
        {
            sqlite3_prepare_v2(self->sqlite_db, "SELECT COUNT(meta.id) FROM meta JOIN recent_play ON meta.filepath=recent_play.filepath",
                                                -1, &self->stmt_query, NULL);
        }
    }
    else if (curr_query_type == SRV_MOT_QUERY_TYPE_NUMBER_BY_ALL)
    {
        if (self->stmt_query == NULL)
        {
            //sqlite3_prepare_v2(self->sqlite_db, "SELECT count FROM cat_count WHERE id=?",
            sqlite3_prepare_v2(self->sqlite_db, "SELECT COUNT(id) FROM meta",
                                                -1, &self->stmt_query, NULL);
        }
        //sqlite3_bind_kal_uint32(self->stmt_query, 1, SRV_MOT_CAT_ALL);
    }
    else
    {
        if (self->stmt_query == NULL)
        {
            sqlite3_prepare_v2(self->sqlite_db, "SELECT COUNT(id) FROM meta WHERE category=?",
                                                -1, &self->stmt_query, NULL);
        }
        sqlite3_bind_kal_int32(self->stmt_query, 1, category);
    }

    sqlite3_step(self->stmt_query);
    *number = sqlite3_column_kal_uint32(self->stmt_query, 0);

    sqlite3_reset(self->stmt_query);

    sqlite3_exit_instance(&self->sql_ctx);
#else
    if (curr_query_type == SRV_MOT_QUERY_TYPE_NUMBER_BY_RECENT_PLAY)
    {
        srv_mot_db_recent_play_t rp;
        kal_int32 count = 0, i, fserr;
        kal_uint32 len;

        FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
        for (i = 0; i < SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER; i++)
        {
            fserr = FS_Read(self->fh_sdb, &rp, sizeof(rp), &len);
            if (fserr < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
                return SRV_MOT_E_DB_IO_ERROR;
            }
            else if (rp.is_valid == KAL_FALSE)
            {
                break;
            }
            else
            {
                count++;
            }
        }

        *number = count;
    }
    else if (curr_query_type == SRV_MOT_QUERY_TYPE_NUMBER_BY_ALL)
    {
        *number = self->update_count;
    }
    else
    {
        *number = self->category->num[category];
    }

    // force reset query type when enter list menu
    self->last_query_type = SRV_MOT_QUERY_TYPE_NONE;

#endif

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_list_info_start
 * DESCRIPTION
 *  get list info of selected index
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_cat_enum    [IN]      category
 *  U32                 [IN]      start index
 *  srv_mot_sort_dir_enum   [IN]  sorting order, ASC or DESC.
 *  srv_mot_list_info_struct* [OUT]      list info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_list_info_start(srv_mot_h handle, srv_mot_cat_enum category,
                                                    U32 start_idx, srv_mot_sort_dir_enum dir, srv_mot_list_info_struct* list_info)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret;
    srv_mot_query_type_enum curr_query_type = _mot_convert_list_info_query_type(category);

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_enter_instance(&self->sql_ctx);

    if (curr_query_type != self->last_query_type ||
        dir != self->last_query_dir)
    {
        _mot_sql_free_query_stmt(self);

        self->last_query_dir = dir;
        self->last_query_type = curr_query_type;
    }

    if (self->stmt_query)
    {
        sqlite3_reset(self->stmt_query);
    }

    if (curr_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_RECENT_PLAY)
    {
        if (self->stmt_query == NULL)
        {
            sqlite3_prepare_v2(self->sqlite_db, "SELECT meta.id, meta.filename, meta.duration FROM meta JOIN recent_play ON meta.filepath=recent_play.filepath ORDER BY recent_play.id DESC LIMIT -1 OFFSET ?",
                                                -1, &self->stmt_query, NULL);
        }
        sqlite3_bind_kal_uint32(self->stmt_query, 1, start_idx);
    }
    else if (curr_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_ALL)
    {
        if (self->stmt_query == NULL)
        {
            if (dir == SRV_MOT_SORT_DIR_ASC)
            {
                sqlite3_prepare_v2(self->sqlite_db, "SELECT id, filename, duration FROM meta ORDER BY filepath LIMIT -1 OFFSET ?",
                                                    -1, &self->stmt_query, NULL);
            }
            else
            {
                sqlite3_prepare_v2(self->sqlite_db, "SELECT id, filename, duration FROM meta ORDER BY filepath DESC LIMIT -1 OFFSET ?",
                                                    -1, &self->stmt_query, NULL);
            }
        }
        sqlite3_bind_kal_uint32(self->stmt_query, 1, start_idx);
    }
    else
    {
        if (self->stmt_query == NULL)
        {
            if (dir == SRV_MOT_SORT_DIR_ASC)
            {
                sqlite3_prepare_v2(self->sqlite_db, "SELECT id, filename, duration FROM meta WHERE category=? ORDER BY filepath LIMIT -1 OFFSET ?",
                                                        -1, &self->stmt_query, NULL);
            }
            else
            {
                sqlite3_prepare_v2(self->sqlite_db, "SELECT id, filename, duration FROM meta WHERE category=? ORDER BY filepath DESC LIMIT -1 OFFSET ?",
                                                        -1, &self->stmt_query, NULL);
            }
        }
        sqlite3_bind_kal_int32(self->stmt_query, 1, category);
        sqlite3_bind_kal_uint32(self->stmt_query, 2, start_idx);
    }

    ret = _mot_get_list_info_core(self, list_info);

    sqlite3_exit_instance(&self->sql_ctx);

#else
{
    kal_int32 i;
    kal_uint16 id;
    kal_uint32 len;
    srv_mot_db_recent_play_t rp;

    self->last_query_start_idx = start_idx;

    if (self->last_query_type != curr_query_type)
    {
        kal_mem_set(self->query_id_cache, 0xFF, sizeof(self->query_id_cache));
    }
    else if (self->last_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_CATEGORY &&
             self->last_query_category != category)
    {
        kal_mem_set(self->query_id_cache, 0xFF, sizeof(self->query_id_cache));
    }
    else if (curr_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_RECENT_PLAY)
    {
        // always reset recent play list, because it might be changed after playback.
        kal_mem_set(self->query_id_cache, 0xFF, sizeof(self->query_id_cache));
    }

    self->last_query_category = category;
    self->last_query_type = curr_query_type;

    // build meta id cache
    if (self->query_id_cache[0] == 0xFFFF)
    {
        if (self->last_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_RECENT_PLAY)
        {
            FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
            for (i = 0; i < SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER; i++)
            {
                FS_Read(self->fh_sdb, &rp, sizeof(rp), &len);
                if (rp.is_valid == KAL_TRUE)
                {
                    self->query_id_cache[i] = rp.id;
                }
                else
                {
                    break;
                }
            }
        }
        else if (self->last_query_type == SRV_MOT_QUERY_TYPE_BRIEF_BY_ALL)
        {
            for (i = 0; i < self->update_count; i++)
            {
                FS_Seek(self->fh_sdb, SRV_MOT_DB_META_OFFSET + i*SRV_MOT_DB_META_SIZE, FS_FILE_BEGIN);
                FS_Read(self->fh_sdb, &id, sizeof(id), &len);
                self->query_id_cache[i] = id;
            }
        }
        else
        {
            kal_int32 hit_num = 0;

            FS_Seek(self->fh_sdb, SRV_MOT_DB_META_OFFSET, FS_FILE_BEGIN);
            for (i = 0; i < self->update_count; i++)
            {
                FS_Read(self->fh_sdb, self->curr_db_meta, sizeof(srv_mot_db_meta_t), &len);
                if (self->curr_db_meta->info.category == category)
                {
                    self->query_id_cache[hit_num] = self->curr_db_meta->id;
                    hit_num++;
                }
            }
        }
    }

    ret = _mot_get_list_info_core(self, list_info);
}
#endif

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_list_info_next
 * DESCRIPTION
 *  get next list info, must called after srv_mot_get_list_info_start().
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_list_info_struct* [OUT]      list info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_list_info_next(srv_mot_h handle, srv_mot_list_info_struct* list_info)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret;

#ifdef __SRV_MOT_SQLITE_VERSION__

    sqlite3_enter_instance(&self->sql_ctx);

    ret = _mot_get_list_info_core(self, list_info);

    sqlite3_exit_instance(&self->sql_ctx);

#else

    ret = _mot_get_list_info_core(self, list_info);

#endif

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_info
 * DESCRIPTION
 *  get selected content details.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  srv_mot_content_info_struct*    [OUT]     content info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_content_info(srv_mot_h handle, U32 content_id,
                                                    srv_mot_content_info_struct* content_info)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret = SRV_MOT_E_NO_MORE_DATA;

#ifdef __SRV_MOT_SQLITE_VERSION__
    kal_uint8* tb_p;
    kal_int32 res;

    sqlite3_enter_instance(&self->sql_ctx);

    if (self->last_query_type != SRV_MOT_QUERY_TYPE_CONTENT_DETAIL)
    {
        _mot_sql_free_query_stmt(self);
        self->last_query_type = SRV_MOT_QUERY_TYPE_CONTENT_DETAIL;
        sqlite3_prepare_v2(self->sqlite_db, "SELECT filename, artist, date, duration, description, title, thumbnail, category FROM meta WHERE id=?",
                                                -1, &self->stmt_query, NULL);
    }
    else
    {
        sqlite3_reset(self->stmt_query);
    }

    sqlite3_bind_kal_uint32(self->stmt_query, 1, content_id);

    res = sqlite3_step(self->stmt_query);
    if (res == SQLITE_ROW)
    {
        const WCHAR* str_p;

        str_p = sqlite3_column_kal_wstr(self->stmt_query, 0);
        kal_wstrncpy(content_info->filename, str_p, SRV_MOT_FILE_NAME_LEN);

        str_p = sqlite3_column_kal_wstr(self->stmt_query, 1);
        if (str_p)
        {
            kal_wstrncpy(content_info->artist, str_p, SRV_MOT_ARTIST_LEN);
        }
        else
        {
            kal_mem_set(content_info->artist, 0, SRV_MOT_ARTIST_LEN * sizeof(WCHAR));
        }

        str_p = sqlite3_column_kal_wstr(self->stmt_query, 2);
        if (str_p)
        {
            kal_wstrncpy(content_info->datetime, str_p, SRV_MOT_DATETIME_LEN);
        }
        else
        {
            kal_mem_set(content_info->datetime, 0, SRV_MOT_DATETIME_LEN * sizeof(WCHAR));
        }

        content_info->duration = sqlite3_column_kal_uint64(self->stmt_query, 3);

        str_p = sqlite3_column_kal_wstr(self->stmt_query, 4);
        if (str_p)
        {
            kal_wstrncpy(content_info->descript, str_p, SRV_MOT_DESCRIPT_LEN);
        }
        else
        {
            kal_mem_set(content_info->descript, 0, SRV_MOT_DESCRIPT_LEN * sizeof(WCHAR));
        }

        str_p = sqlite3_column_kal_wstr(self->stmt_query, 5);
        if (str_p)
        {
            kal_wstrncpy(content_info->title, str_p, SRV_MOT_TITLE_LEN);
        }
        else
        {
            kal_mem_set(content_info->title, 0, SRV_MOT_TITLE_LEN * sizeof(WCHAR));
        }

        tb_p = (kal_uint8*)sqlite3_column_blob(self->stmt_query, 6);
        content_info->thumbnail_size = sqlite3_column_bytes(self->stmt_query, 6);
        if (content_info->thumbnail_size &&
            (content_info->thumbnail_size <= SRV_MOT_THUMBNAIL_SIZE) &&
            tb_p)
        {
            kal_mem_cpy(content_info->thumbnail_buf, tb_p, content_info->thumbnail_size);
        }
        else
        {
            content_info->thumbnail_size = 0;
        }

        content_info->category = (srv_mot_cat_enum)sqlite3_column_kal_int32(self->stmt_query, 7);

        ret = SRV_MOT_S_OK;
    }

    sqlite3_exit_instance(&self->sql_ctx);

#else
{
    kal_uint32 r_offset = SRV_MOT_DB_META_OFFSET + content_id*SRV_MOT_DB_META_SIZE;
    kal_uint32 len;

    if (content_id > self->update_count)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, content_id, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, self->update_count, __LINE__);
        return SRV_MOT_E_INVALID_PARAM;
    }

    FS_Seek(self->fh_sdb, r_offset, FS_FILE_BEGIN);
    FS_Read(self->fh_sdb, self->curr_db_meta, sizeof(srv_mot_db_meta_t), &len);

    kal_mem_cpy(content_info, &self->curr_db_meta->info, sizeof(srv_mot_content_info_struct));

    ret = SRV_MOT_S_OK;
}
#endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_path
 * DESCRIPTION
 *  get selected item file path.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  srv_mot_file_path_struct*       [OUT]     list path
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_content_path(srv_mot_h handle, U32 content_id,
                                                    srv_mot_file_path_struct* path)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret = SRV_MOT_E_NO_MORE_DATA;

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_stmt *stmt;
    kal_int32 res;

    sqlite3_enter_instance(&self->sql_ctx);

    sqlite3_prepare_v2(self->sqlite_db, "SELECT filepath FROM meta WHERE id=?",
                                            -1, &stmt, NULL);

    sqlite3_bind_kal_uint32(stmt, 1, content_id);

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        kal_wstrncpy(path->filepath, sqlite3_column_kal_wstr(stmt, 0), SRV_MOT_FILE_PATH_LEN);
        ret = SRV_MOT_S_OK;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sqlite3_exit_instance(&self->sql_ctx);

#else
{
    kal_uint32 r_offset = SRV_MOT_DB_META_OFFSET + content_id*SRV_MOT_DB_META_SIZE;
    kal_uint32 len;

    if (content_id > self->update_count)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_INVALID_PARAM, __LINE__);
        return SRV_MOT_E_INVALID_PARAM;
    }

    FS_Seek(self->fh_sdb, r_offset, FS_FILE_BEGIN);
    FS_Read(self->fh_sdb, self->curr_db_meta, sizeof(srv_mot_db_meta_t), &len);

    kal_mem_cpy(path, &self->curr_db_meta->path, sizeof(srv_mot_file_path_struct));

    ret = SRV_MOT_S_OK;
}
#endif

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_category_string_id
 * DESCRIPTION
 *  get category string id.
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_cat_enum    [IN]      category
 *  MMI_ID_TYPE*        [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_category_string_id(srv_mot_cat_enum category,
                                                    MMI_ID_TYPE* str_id)
{
    if (category == SRV_MOT_CAT_RECENT_PLAY)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_CAT_RECENT_PLAY;
        return SRV_MOT_S_OK;
    }
    else if (category == SRV_MOT_CAT_ALL)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_CAT_ALL;
        return SRV_MOT_S_OK;
    }
    else if (category > SRV_MOT_CAT_OTHERS)
    {
        return SRV_MOT_E_INVALID_PARAM;
    }

    *str_id = (MMI_ID_TYPE)(STR_ID_SRV_MOT_CAT_ACTION_ADVENTURE + (kal_int32)category);

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_default_string_id
 * DESCRIPTION
 *  get service default string id.
 * PARAMETERS
 *  srv_mot_default_str_enum    [IN]      type
 *  MMI_ID_TYPE*                [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_default_string_id(srv_mot_default_str_enum type,
                                                    MMI_ID_TYPE* str_id)
{
    if (type == SRV_MOT_DEFAULT_STR_MOVIE_NAME)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_DEFAULT_UNNAMED;
        return SRV_MOT_S_OK;
    }
    else if (type == SRV_MOT_DEFAULT_STR_DURATION ||
             type == SRV_MOT_DEFAULT_STR_YEAR ||
             type == SRV_MOT_DEFAULT_STR_STARRING)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_DEFAULT_UNKNOWN;
        return SRV_MOT_S_OK;
    }
    else if (type == SRV_MOT_DEFAULT_STR_PLOT)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_DEFAULT_NO_DETAILS;
        return SRV_MOT_S_OK;
    }

    return SRV_MOT_E_INVALID_PARAM;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_error_string_id
 * DESCRIPTION
 *  get service error string id.
 * PARAMETERS
 *  srv_mot_ret_enum    [IN]      error
 *  MMI_ID_TYPE*        [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_error_string_id(srv_mot_h handle, srv_mot_ret_enum error,
                                                    MMI_ID_TYPE* str_id)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_GET_ERROR_STRING, error);

    if (error >= 0)
    {
        return SRV_MOT_E_INVALID_PARAM;
    }

    if (error == SRV_MOT_E_IO_ERROR)
    {
        if (self->last_fs_error < 0)
        {
            *str_id = srv_fmgr_fs_error_get_string(self->last_fs_error);
        }
        else
        {
            *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_FS_ERR;
        }
    }
    else if (error == SRV_MOT_E_DB_OPEN_FAIL)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_DB_CANNOT_OPEN;
    }
    else if (error == SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH)
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_DB_FREESPACE_NOT_ENOUGH;
    }
    else if (error == SRV_MOT_E_DB_IO_ERROR)
    {
        #ifdef __SRV_MOT_SQLITE_VERSION__
            S32 temp_err;
            temp_err = sqlite3_instance_get_last_io_error(&(self->sql_ctx));
            *str_id = srv_fmgr_fs_error_get_string(temp_err);
        #else
            *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_FS_ERR;
        #endif
    }
    else
    {
        *str_id = (MMI_ID_TYPE)STR_ID_SRV_MOT_UNKNOWN_ERR;
    }

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_add_recent_playlist
 * DESCRIPTION
 *  add content to recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_add_recent_playlist(srv_mot_h handle, U32 content_id, U64 time)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_stmt *stmt;
    kal_int32 res;

    kal_uint32 count, oldest_id;
    srv_mot_file_path_struct path;

    // if not enough space, skip this record.
    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PLAYLIST_RECORD_DISK_SPACE) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH, __LINE__);
        return SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }

    srv_mot_get_content_path(handle, content_id, &path);

    sqlite3_enter_instance(&self->sql_ctx);

    /* delete old record if exist */
    sqlite3_prepare_v2(self->sqlite_db, "DELETE FROM recent_play WHERE filepath=?",
                                                -1, &stmt, NULL);
    sqlite3_bind_kal_wstr(stmt, 1, path.filepath);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    /* check if reach max recent_play number */
    do
    {
        sqlite3_prepare_v2(self->sqlite_db, "SELECT COUNT(id), MIN(id) FROM recent_play",
                                                    -1, &stmt, NULL);
        res = sqlite3_step(stmt);
        count = sqlite3_column_kal_uint32(stmt, 0);
        oldest_id = sqlite3_column_kal_uint32(stmt, 1);
        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);

        // check query error. if DB error or disk error, we can jump out of this loop.
        if (res != SQLITE_ROW)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_IO_ERROR, __LINE__);
            break;
        }

        if (count >= SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER)
        {
            sqlite3_prepare_v2(self->sqlite_db, "DELETE FROM recent_play WHERE id=?",
                                                    -1, &stmt, NULL);
            sqlite3_bind_kal_uint32(stmt, 1, oldest_id);
            sqlite3_step(stmt);
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
        }
    } while (count >= SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER);

    /* insert latest play */
    sqlite3_prepare_v2(self->sqlite_db, "REPLACE INTO recent_play (id, filepath, time) values (?, ?, ?)",
                                                -1, &stmt, NULL);
    sqlite3_bind_null(stmt, 1);
    sqlite3_bind_kal_wstr(stmt, 2, path.filepath);
    sqlite3_bind_kal_uint64(stmt, 3, time);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    _mot_sql_commit(self);

    sqlite3_exit_instance(&self->sql_ctx);

#else
{
    kal_uint32 len;
    kal_int32 fserr, i, end_idx;
    srv_mot_db_recent_play_t rp;
    srv_mot_file_path_struct path;

    // if not enough space, skip this record.
    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PLAYLIST_RECORD_DISK_SPACE) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH, __LINE__);
        return SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }

    // find recent play record if exist, set it as boundary for shifting list.
    FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
    for (i = 0; i < SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER; i++)
    {
        fserr = FS_Read(self->fh_sdb, &rp, sizeof(rp), &len);
        if (fserr < 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, fserr, __LINE__);
            return SRV_MOT_E_DB_IO_ERROR;
        }
        else if (rp.is_valid == KAL_FALSE)
        {
            break;
        }
        else
        {
            if (rp.id == content_id)
            {
                break;
            }
        }
    }
    if (i == SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER)
    {
        end_idx = SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER - 1;
    }
    else
    {
        end_idx = i;
    }

    // shift list for one slot.
    for (i = end_idx; i > 0; i--)
    {
        kal_uint32 w_offset = SRV_MOT_DB_RECENT_PLAY_OFFSET + i*SRV_MOT_DB_RECENT_PLAY_SIZE;
        kal_uint32 r_offset = SRV_MOT_DB_RECENT_PLAY_OFFSET + (i-1)*SRV_MOT_DB_RECENT_PLAY_SIZE;

        FS_Seek(self->fh_sdb, r_offset, FS_FILE_BEGIN);
        fserr = FS_Read(self->fh_sdb, &rp, sizeof(rp), &len);

        FS_Seek(self->fh_sdb, w_offset, FS_FILE_BEGIN);
        fserr = FS_Write(self->fh_sdb, &rp, sizeof(rp), NULL);
    }

    // insert to front
    srv_mot_get_content_path(handle, content_id, &path);

    kal_mem_set(&rp, 0, sizeof(rp));

    rp.id = content_id;
    kal_wstrncpy(rp.filepath, path.filepath, SRV_MOT_FILE_PATH_LEN);
    rp.playtime = time;
    rp.is_valid = KAL_TRUE;

    FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
    fserr = FS_Write(self->fh_sdb, &rp, sizeof(rp), NULL);
}
#endif

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_delete_recent_playlist
 * DESCRIPTION
 *  remove content from recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_delete_recent_playlist(srv_mot_h handle, U32 content_id)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_INVALID_PARAM, __LINE__);

    return SRV_MOT_E_INVALID_PARAM;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_delete_recent_playlist
 * DESCRIPTION
 *  remove content from recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  U64*                            [OUT]     last play time
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_get_recent_playtime(srv_mot_h handle, U32 content_id, U64* time)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_stmt *stmt;
    kal_int32 res;

    srv_mot_file_path_struct path;

    srv_mot_get_content_path(handle, content_id, &path);

    sqlite3_enter_instance(&self->sql_ctx);

    /* delete old record if exist */
    sqlite3_prepare_v2(self->sqlite_db, "SELECT time FROM recent_play WHERE filepath=?",
                                                -1, &stmt, NULL);
    sqlite3_bind_kal_wstr(stmt, 1, path.filepath);
    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        *time = sqlite3_column_kal_uint64(stmt, 0);
    }
    else
    {
        *time = 0;
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sqlite3_exit_instance(&self->sql_ctx);
#else
{
    kal_uint32 i, len;
    kal_int32 fserr;
    srv_mot_db_recent_play_t rp;

    *time = 0;
    FS_Seek(self->fh_sdb, SRV_MOT_DB_RECENT_PLAY_OFFSET, FS_FILE_BEGIN);
    for (i = 0; i < SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER; i++)
    {
        fserr = FS_Read(self->fh_sdb, &rp, sizeof(rp), &len);
        if (fserr < 0 ||
            rp.is_valid == KAL_FALSE)
        {
            break;
        }
        else
        {
            if (rp.id == content_id)
            {
                *time = rp.playtime;
                break;
            }
        }
    }
}
#endif

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_update
 * DESCRIPTION
 *  scan and update mot database
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_update(srv_mot_h handle)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_fmgr_fileinfo_struct file_info;
    srv_mot_ret_enum ret = SRV_MOT_S_ASYNC;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_UPDATE, self->state);
    _mot_set_state(self, SRV_MOT_STATE_UPDATING, __LINE__);

#ifdef __SRV_MOT_SQLITE_VERSION__
    /* reset DB */
    _mot_sql_close_db(self);
    // sqlite DB is not shared, so have to close it for correct file size.
    srv_fmgr_fs_path_get_fileinfo(self->db_path, &file_info);

    ret = _mot_sql_open_db(self, self->db_path);
    if (ret < 0)
    {
        _mot_set_state(self, SRV_MOT_STATE_ERROR, __LINE__);
        _mot_sql_close_db(self);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, ret, __LINE__);
        return ret;
    }

    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PRESERVED_DISK_SPACE - file_info.size) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_PRESERVED_DISK_SPACE, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, file_info.size, __LINE__);
        _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);
        return SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }
#else

    _mot_sdb_close_db(self);

    srv_fmgr_fs_path_get_fileinfo(self->db_path, &file_info);

    if (srv_fmgr_drv_check_free_size(self->drive_letter, SRV_MOT_PRESERVED_DISK_SPACE - file_info.size) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_PRESERVED_DISK_SPACE, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, file_info.size, __LINE__);

        _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);
        ret = SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH;
    }
    else
    {
        // delete old DB to clean out recent played list.
        FS_Delete(self->db_path);
    }

    if (ret >= 0)
    {
        ret = _mot_sdb_open_db(self, self->db_path);
        if (ret < 0)
        {
            _mot_set_state(self, SRV_MOT_STATE_ERROR, __LINE__);
            _mot_sdb_close_db(self);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, ret, __LINE__);
            return ret;
        }
    }
    else
    {
        // did not pass "free space check", reopen old DB.
        _mot_sdb_open_db(self, self->db_path);
    }

    if (ret >= 0)
    {
        ret = SRV_MOT_S_ASYNC;
    }
    else
    {
        return ret;
    }

#endif

    self->abort_updating = KAL_FALSE;

    /* start updating on background mod */
    _mot_send_update_req(self);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_stop_updating
 * DESCRIPTION
 *  stop mot database updating
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_stop_updating(srv_mot_h handle)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_STOP_UPDATING, self->state);

    /* force background mod stop */
    self->abort_updating = KAL_TRUE;

    _mot_send_stop_updating_req(self);

    SRV_MOT_WAIT_EVENT(SRV_MOT_TASK_EVENT);

    _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_open
 * DESCRIPTION
 *  open mot folder and related DB.
 * PARAMETERS
 *  srv_mot_h               [IN]    service handle
 *  srv_mot_open_struct     [IN]    open_param
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_open(srv_mot_h handle, srv_mot_open_struct* open_param)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    srv_mot_ret_enum ret = SRV_MOT_E_DB_OPEN_FAIL;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_OPEN, self->state);

    if (self->state == SRV_MOT_STATE_OPENED ||
        self->state == SRV_MOT_STATE_UPDATING)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_WRONG_STATE, __LINE__);

        return SRV_MOT_E_WRONG_STATE;
    }

    self->drive_letter = open_param->drive_letter;

    if (srv_fmgr_drv_is_accessible(open_param->drive_letter))
    {
        self->med_dir = _mot_get_med_dir(self, open_param->drive_letter);

        ret = SRV_MOT_S_OK;
    }

    /* open DB */
    if (ret == SRV_MOT_S_OK)
    {
        self->db_path = _mot_get_db_path(self, open_param->drive_letter);

        #ifdef __SRV_MOT_SQLITE_VERSION__
            self->db_journal_path = _mot_alloc_mem(self, SRV_MOT_FILE_NAME_LEN * sizeof(kal_wchar), __LINE__);
            kal_wsprintf(self->db_journal_path, "%w%w", self->db_path, L"-journal");

            self->sql_buf = _mot_alloc_mem(self, SRV_MOT_SQL_BUF_SIZE, __LINE__);
            sqlite3_init_instance(&self->sql_ctx, self->sql_buf, SRV_MOT_SQL_BUF_SIZE, g_srv_mot_sql_mutex);
            sqlite3_enter_instance(&self->sql_ctx);

            ret = _mot_sql_open_db(self, self->db_path);

            if (ret >= 0)
            {
                /* check all tables to avoid a corrupted database*/
                ret = _mot_sql_db_check_validity(self);
                if (ret != SRV_MOT_S_OK)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_FAIL, __LINE__);
                    ret = _mot_sql_db_error_recover(self);
                }
            }

            sqlite3_exit_instance(&self->sql_ctx);
            if (ret < 0)
            {
                sqlite3_free_instance(&self->sql_ctx);
                _mot_close_core(self);
                _mot_set_state(self, SRV_MOT_STATE_IDLE, __LINE__);
            }
            else
            {
                _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);
            }

        #else

            if (self->curr_db_meta == NULL)
            {
                self->curr_db_meta = _mot_alloc_mem(self, sizeof(srv_mot_db_meta_t), __LINE__);
            }
            if (self->category == NULL)
            {
                self->category = _mot_alloc_mem(self, sizeof(srv_mot_db_category_num_t), __LINE__);
            }

            ret = _mot_sdb_open_db(self, self->db_path);
            if (ret >= 0)
            {
                /* check all tables to avoid a corrupted database*/
                ret = _mot_sdb_db_check_validity(self);
                if (ret != SRV_MOT_S_OK)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_FAIL, __LINE__);
                    ret = _mot_sdb_db_error_recover(self);
                }
            }

            if (ret < 0)
            {
                _mot_close_core(self);
                _mot_set_state(self, SRV_MOT_STATE_IDLE, __LINE__);
            }
            else
            {
                _mot_set_state(self, SRV_MOT_STATE_OPENED, __LINE__);
            }

        #endif
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mot_close
 * DESCRIPTION
 *  close mot DB.
 * PARAMETERS
 *  srv_mot_h  [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_close(srv_mot_h handle)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_CLOSE, self->state);

    if (self->state == SRV_MOT_STATE_UPDATING)
    {
        srv_mot_stop_updating(handle);
    }

#ifdef __SRV_MOT_SQLITE_VERSION__
    sqlite3_enter_instance(&self->sql_ctx);

    _mot_sql_close_db(self);

    sqlite3_exit_instance(&self->sql_ctx);
    sqlite3_free_instance(&self->sql_ctx);
#else
    _mot_sdb_close_db(self);
#endif

    _mot_close_core(self);

    _mot_set_state(self, SRV_MOT_STATE_IDLE, __LINE__);

    return SRV_MOT_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_list_create
 * DESCRIPTION
 *  create list service, get memory from caller
 * PARAMETERS
 *  srv_mot_create_struct  [IN]      see srv_mot_create_struct
 * RETURNS
 *  return service handle
 *****************************************************************************/
srv_mot_h srv_mot_create(srv_mot_create_struct* create_param)
{
    srv_mot_context_t* self = NULL;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_CREATE);

    self = applib_asm_alloc_nc_r(create_param->app_id, sizeof(srv_mot_context_t));

    g_srv_mot_ctx_p = self;

#ifdef __SRV_MOT_SQLITE_VERSION__
    if (g_srv_mot_sql_mutex == NULL)
    {
        g_srv_mot_sql_mutex = kal_create_mutex("MOTSQL");
    }
#endif

    if (g_srv_mot_task_mutex == NULL)
    {
        g_srv_mot_task_mutex = kal_create_mutex("MOTTASK");
    }
    if (g_srv_mot_task_event == NULL)
    {
        g_srv_mot_task_event = kal_create_event_group("srv_mot_events");
    }

    if (self)
    {
        kal_mem_set(self, 0, sizeof(srv_mot_context_t));

        _mot_set_state(self, SRV_MOT_STATE_IDLE, __LINE__);

        self->client_cb = create_param->callback;
        self->client = create_param->user_data;
        self->app_id = create_param->app_id;
        self->task_mutex = g_srv_mot_task_mutex;
        self->req_events = g_srv_mot_task_event;

        SetProtocolEventHandler(_mot_event_hdlr, MSG_ID_MOT_EVENT_IND);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_ERROR, SRV_MOT_E_OUT_OF_MEMORY, __LINE__);
    }

    return (srv_mot_h)self;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mot_destroy
 * DESCRIPTION
 *  destory mot service
 * PARAMETERS
 *  srv_mot_hdr :         [IN]   service handle
 * RETURNS
 *  return  srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_destroy(srv_mot_h handle)
{
    srv_mot_context_t* self = (srv_mot_context_t*)handle;
    MMI_ID app_id = self->app_id;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SRV_MOT_DESTROY, self->state);

    applib_asm_free_r(app_id, self);

    g_srv_mot_ctx_p = NULL;

    ClearProtocolEventHandler(MSG_ID_MOT_EVENT_IND);

    return SRV_MOT_S_OK;
}

void srv_mot_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
        case MSG_ID_MOT_UPDATE_REQ:
            // make sure service instance is valid
            if (g_srv_mot_ctx_p)
            {
                _mot_update_req_hdlr(ilm);
            }
            break;

        case MSG_ID_MOT_STOP_UPDATING_REQ:
            _mot_stop_updating_req_hdlr(ilm);
            break;

        default:
            break;
    }
}

#endif // #if defined(__MMI_MOT_SUPPORT__)

