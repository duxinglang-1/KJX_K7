#ifndef __SNS_SRV_UTIL_H__
#define __SNS_SRV_UTIL_H__

#include "SnsSrvGprot.h"
#include "SnsSrvListMgr.h"
#include "SnsSrvPluginMgr.h"
#include "SnsPlugin.h"


//#define SRV_SNS_DEBUG_MEM 1

#define SNS_READY_GUARD() do { if (!srv_sns_is_ready()) return SRV_SNS_NOT_READY; } while(0);
#define SNS_READY_GUARD_CB(CB,UD) do {                      \
    if (!srv_sns_is_ready()) {                              \
        srv_sns_evt_result_struct evt;                      \
        if (CB) {                                           \
           MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SNS_RESULT); \
           evt.result = SRV_SNS_NOT_READY;                  \
           MMI_FRM_POST_EVENT(&evt, CB, UD);                \
        }                                                   \
        return;                                             \
    }                                                       \
} while(0);


#define STR_SIZE(len) (len>0?(len&1?len+1:len+2):0)
#define WSTR_SIZE(len) (len>0?(len+1)*2:0)
#define SET_STR_PTR(obj,field,len,acc) if (len > 0) { obj->field##_len = len; obj->field = (CHAR *)((U32)obj + acc); acc += STR_SIZE(len); }
#define SET_WSTR_PTR(obj,field,len,acc) if (len > 0) { obj->field##_len = len; obj->field = (WCHAR *)((U32)obj + acc); acc += WSTR_SIZE(len); }
#define SET_WSTR_PATH_PTR(obj,field,real_len,path_len,acc) if (real_len > 0) { obj->field##_len = real_len; obj->field = (WCHAR *)((U32)obj + acc); acc += WSTR_SIZE(path_len); }
#define FREE_IF_EXISTS(mem) if (mem) { sns_util_free(mem); }

void sns_util_init_mem(void);
void *sns_util_alloc_by_plugin(U32 size);
void sns_util_free_by_plugin(void *mem);
void *sns_util_alloc_int(U32 size, const char *filename, int lineno);
void sns_util_free_int(void *mem, const char *filename, int lineno);
#ifdef SRV_SNS_DEBUG_MEM
    void sns_util_free_by_plugin_by_provider(void *mem, U32 provider);
    void *sns_util_alloc_by_plugin_fb(U32 size);
    void sns_util_free_by_plugin_fb(void *mem);
    void *sns_util_alloc_by_plugin_tw(U32 size);
    void sns_util_free_by_plugin_tw(void *mem);
    void *sns_util_alloc_by_plugin_rr(U32 size);
    void sns_util_free_by_plugin_rr(void *mem);
    #define sns_util_alloc(size) sns_util_alloc_int(size, __FILE__, __LINE__)
    #define sns_util_free(mem) sns_util_free_int(mem, __FILE__, __LINE__)
    #define FREE_BY_PLUGIN_IF_EXISTS(mem,p) if (mem) { sns_util_free_by_plugin_by_provider(mem,p); }
#else
    #define sns_util_alloc(size) sns_util_alloc_int(size, NULL, 0)
    #define sns_util_free(mem) sns_util_free_int(mem, NULL, 0)
    #define FREE_BY_PLUGIN_IF_EXISTS(mem,p) if (mem) { sns_util_free_by_plugin(mem); }
#endif

srv_sns_activity_struct *sns_util_alloc_activity(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U8 act_id_len, U8 photo_id_len, U16 message_len, U16 link_len, U16 pic_len, U32 blob_size);
srv_sns_comment_struct *sns_util_alloc_comment(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U16 comment_len);
srv_sns_friend_struct *sns_util_alloc_friend(U8 user_id_len, U8 user_name_len, U8 user_pic_len);
srv_sns_info_struct *sns_util_alloc_info(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U8 profile_url_len, U8 birthday_len, U8 phone_len, U8 email_len, U8 address_len, U8 status_len);
srv_sns_thread_struct *sns_util_alloc_thread(U8 thread_id_len, U16 snippet_len);
srv_sns_message_struct *sns_util_alloc_message(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U8 thread_id_len, U8 msg_id_len, U16 message_len);
srv_sns_request_struct *sns_util_alloc_request(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U8 request_id_len, U16 request_len);
srv_sns_notif_struct *sns_util_alloc_notif(U8 user_id_len, U8 user_name_len, U8 user_pic_len, U8 notif_id_len, U8 object_id_len, U16 notification_len, U16 href_len);
srv_sns_album_struct *sns_util_alloc_album(U8 user_id_len, U8 album_id_len, U8 name_len, U8 thumbnail_len);
srv_sns_group_struct *sns_util_alloc_group(U8 name_len);
srv_sns_event_struct *sns_util_alloc_event(U8 event_id_len, U8 name_len, U8 desc_len, U8 location_len);

void sns_util_free_default(void *data);
#define sns_util_free_friends(data) sns_util_free_default(data)
void sns_util_free_threads(srv_sns_thread_struct *thread);
void sns_util_free_members(srv_sns_member_struct *member);
void sns_util_free_link_contacts(srv_sns_link_contact_struct *link_contact);
void sns_util_free_data(sns_list_type_enum type, void *data);
void sns_util_free_plugin_user_account(sns_plugin_user_account_struct *account, U32 provider);
void sns_util_free_plugin_activities(srv_sns_activity_struct *activities);
void sns_util_free_plugin_comments(srv_sns_comment_struct *comments);
void sns_util_free_plugin_notifications(srv_sns_notif_struct *notifs);
void sns_util_free_plugin_requests(srv_sns_request_struct *requests);
void sns_util_free_plugin_friends(srv_sns_info_struct *friends);
void sns_util_free_plugin_threads(srv_sns_thread_struct *threads);
void sns_util_free_plugin_messages(srv_sns_message_struct *messages);
void sns_util_free_plugin_albums(srv_sns_album_struct *albums);
void sns_util_free_plugin_photos(srv_sns_photo_struct *photos);
void sns_util_free_plugin_events(srv_sns_event_struct *events);
void sns_util_free_ret_id(sns_plugin_ret_id_struct *ret_id, U32 provider);
U16 sns_util_trim_data(sns_list_type_enum type, void *data, U16 count);

typedef struct sns_friend_with_pingyin {
    srv_sns_info_struct *friends;
    WCHAR **pingyin;
    U32 count;
} sns_friend_with_pingyin_struct;

sns_friend_with_pingyin_struct *sns_util_friend_with_pingyin(srv_sns_info_struct *friends, U32 count);
void sns_util_free_friend_with_pingyin(sns_friend_with_pingyin_struct *friend_with_pingyin);

// ============================================================================

#define SNS_MAX_LEN_KEY     128
#define SNS_MAX_LEN_SO_NAME 32

/* internal account struct */
typedef struct sns_account {
    struct sns_account *next;
    U32 provider;
    WCHAR *name;
    WCHAR icons[SRV_SNS_LOGO_TOTAL][32];
    void *icon_data[SRV_SNS_LOGO_TOTAL];
    U32 icon_size[SRV_SNS_LOGO_TOTAL];
    U8 features[SRV_SNS_FEATURE_TOTAL];
    srv_sns_user_struct user;
    WCHAR *profile_url;
    WCHAR *login_id;
    CHAR *access_token;
    CHAR *refresh_token;
    U32 created_time;
    U32 expires_in;
    CHAR *api_key;
    CHAR *secret_key;
    CHAR *machine_id;
    MMI_BOOL sync_contacts;
    MMI_BOOL sync_calendar;
    MMI_BOOL sync_phonebook;
    U32 last_friend_synced;
    U8 nvram_record_id;
    WCHAR *so_name;
    MMI_BOOL is_preloaded;
    U32 so_size;
    U32 so_handle;
    sns_plugin_req_struct *so_req;
    srv_sns_counts_struct counts;
} sns_account_struct;

#define SNS_ACCOUNT_UPDATE_ALL      0xFF
#define SNS_ACCOUNT_UPDATE_SETTINGS 0x01
#define SNS_ACCOUNT_UPDATE_TOKENS   0x02
#define SNS_ACCOUNT_UPDATE_COUNTS   0x04

sns_account_struct *sns_util_get_account(U32 provider);
void sns_util_remove_account(U32 provider);
S32 sns_util_write_account(sns_account_struct *account, U8 flag);
void sns_util_clear_account(U32 provider, MMI_BOOL write_through);
sns_account_struct *sns_util_load_account_from_plugin(U32 provider, WCHAR *login_id, sns_plugin_user_account_struct *plugin_account);
void sns_util_load_accounts(void);
void sns_util_logout(U32 provider, srv_sns_log_out_type type);
void sns_post_cb_evt_account_logged_out(U32 provider, srv_sns_log_out_type type);

MMI_BOOL sns_util_clear_counts(U32 provider);
MMI_BOOL sns_util_update_counts(U32 provider, srv_sns_counts_struct *counts);
void sns_util_start_get_counts_timer(void);
void sns_util_start_sync_timer(void);
MMI_BOOL sns_util_any_calendar_syncing(void);


// ============================================================================

typedef struct sns_node_t {
    struct sns_node_t *prev;
    struct sns_node_t *next;
    void *data;
    U16 size;
} sns_node;

typedef struct sns_queue_t {
    sns_node *head;
    sns_node *tail;
    U16 count;
} sns_queue;

typedef MMI_BOOL (*sns_util_node_matcher)(void *data, void *key);

sns_queue *sns_util_queue_create(void);
MMI_BOOL sns_util_queue_is_empty(sns_queue *q);
void *sns_util_enqueue(sns_queue *q, U16 size);
MMI_BOOL sns_util_dequeue(sns_queue *q, void *buf);
void *sns_util_get_node_next(sns_queue *q, sns_util_node_matcher matcher, void *key, void *current);
#define sns_util_get_node(q,mathcer,key) sns_util_get_node_next(q,mathcer,key,NULL)
MMI_BOOL sns_util_remove_node(sns_queue *q, sns_util_node_matcher matcher, void *key, void *buf);

// ============================================================================

typedef enum {
    SNS_MAP_KEY_UNUSED,
    SNS_MAP_KEY_PROVIDER,
    SNS_MAP_KEY_USERNAME,
    SNS_MAP_KEY_PASSWORD,
    SNS_MAP_KEY_RESULT,
    SNS_MAP_KEY_COUNT,
    SNS_MAP_KEY_STATUS,
    SNS_MAP_KEY_DESC,
    SNS_MAP_KEY_PATH,
    SNS_MAP_KEY_CALLBACK,
    SNS_MAP_KEY_USER_ID,
    SNS_MAP_KEY_GROUP,
    SNS_MAP_KEY_ACT_ID,
    SNS_MAP_KEY_ALBUM_ID,
    SNS_MAP_KEY_PHOTO_ID,
    SNS_MAP_KEY_PHOTO_POS,
    SNS_MAP_KEY_THREAD_ID,
    SNS_MAP_KEY_COMMENT,
    SNS_MAP_KEY_MESSAGE,
    SNS_MAP_KEY_TYPE,
    SNS_MAP_KEY_DOWN_PIC,
    SNS_MAP_KEY_REFRESH,
    SNS_MAP_KEY_INDEX,
    SNS_MAP_KEY_INDEX2,
    SNS_MAP_KEY_LOGIN,
    SNS_MAP_KEY_CATEGORY,
    SNS_MAP_KEY_FEATURES,
    SNS_MAP_KEY_NAME,
    SNS_MAP_KEY_LIST,
    SNS_MAP_KEY_LIST2,
    SNS_MAP_KEY_URL,
    SNS_MAP_KEY_CONTACT_ID,
    SNS_MAP_KEY_OFFSET,
    SNS_MAP_KEY_STARTED,
    SNS_MAP_KEY_FINISHED,
    SNS_MAP_KEY_NOTIF_ID,
    SNS_MAP_KEY_REQUEST_ID,
    SNS_MAP_KEY_ACCEPT,
    SNS_MAP_KEY_READ,
    SNS_MAP_KEY_LIKE,
    SNS_MAP_KEY_OBJ_ID,
    SNS_MAP_KEY_SEARCH,
    SNS_MAP_KEY_PAGING,
    SNS_MAP_KEY_BLOB,
    SNS_MAP_KEY_SIZE,    
} sns_map_key_enum;

typedef enum {
    SNS_MAP_VALUE_STR,
    SNS_MAP_VALUE_WSTR,
    SNS_MAP_VALUE_U32,
    SNS_MAP_VALUE_S32,
    SNS_MAP_VALUE_U16,
    SNS_MAP_VALUE_S16,
    SNS_MAP_VALUE_U8,
    SNS_MAP_VALUE_S8,
    SNS_MAP_VALUE_BOOL,
    SNS_MAP_VALUE_VOID,
    SNS_MAP_VALUE_ARRAY,
} sns_map_value_type_enum;

typedef struct sns_pair_t {
    sns_map_key_enum key;
    sns_map_value_type_enum type;
    void *value;
} sns_pair;

typedef struct sns_map_t {
    sns_pair *pairs;
    U8 count;
} sns_map;

sns_map *sns_util_map_create(U8 count);
void sns_util_map_destroy(sns_map *map);
MMI_BOOL sns_util_map_has_key(sns_map *map, sns_map_key_enum key);
#define M_has(map, key) sns_util_map_has_key(map, SNS_MAP_KEY_##key)
void *sns_util_map_get(sns_map *map, sns_map_key_enum key);
#define M_get_str(map, key) ((CHAR *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_wstr(map, key) ((WCHAR *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_u32(map, key) ((U32)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s32(map, key) ((S32)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_u16(map, key) ((U16)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s16(map, key) ((S16)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_u8(map, key) ((U8)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s8(map, key) ((S8)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_bool(map, key) ((MMI_BOOL)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get(map, key) sns_util_map_get(map, SNS_MAP_KEY_##key)
#define M_get_u32s(map, key) ((U32 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s32s(map, key) ((S32 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_u16s(map, key) ((U16 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s16s(map, key) ((S16 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_u8s(map, key) ((U8 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_s8s(map, key) ((S8 *)sns_util_map_get(map, SNS_MAP_KEY_##key))
#define M_get_bools(map, key) ((MMI_BOOL *)sns_util_map_get(map, SNS_MAP_KEY_##key))
void sns_util_map_set(sns_map *map, sns_map_key_enum key, sns_map_value_type_enum type, void *data, U16 count);
#define M_set_str(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_STR, (void *)data, 0)
#define M_set_wstr(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_WSTR, (void *)data, 0)
#define M_set_u32(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U32, (void *)data, 0)
#define M_set_s32(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S32, (void *)data, 0)
#define M_set_u16(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U16, (void *)data, 0)
#define M_set_s16(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S16, (void *)data, 0)
#define M_set_u8(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U8, (void *)data, 0)
#define M_set_s8(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S8, (void *)data, 0)
#define M_set_bool(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_BOOL, (void *)data, 0)
#define M_set_void(map, key, data) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_VOID, (void *)data, 0)
#define M_set_u32s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U32, (void *)data, count)
#define M_set_s32s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S32, (void *)data, count)
#define M_set_u16s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U16, (void *)data, count)
#define M_set_s16s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S16, (void *)data, count)
#define M_set_u8s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_U8, (void *)data, count)
#define M_set_s8s(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_S8, (void *)data, count)
#define M_set_bools(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_BOOL, (void *)data, count)
#define M_set_voids(map, key, data, count) sns_util_map_set(map, SNS_MAP_KEY_##key, SNS_MAP_VALUE_VOID, (void *)data, count)

// ============================================================================

#define SNS_UTIL_MD5_LEN                 16
#define SNS_UTIL_CACHE_DIR               "%c:\\@snsc"
#define SNS_UTIL_CACHE_DIR_PROVIDER      "%c:\\@snsc\\%08x"
#define SNS_UTIL_CACHE_DIR_PROVIDER_TYPE "%c:\\@snsc\\%08x\\%w"
#define SNS_UTIL_CACHE_DIR_TYPE_USER     L"u"
#define SNS_UTIL_CACHE_DIR_TYPE_TEMP     L"t"
#define SNS_UTIL_CACHE_DIR_LOGO_PATH     "%c:\\@snsc\\%08x\\%d.png"
#define SNS_UTIL_PIC_DIR                 "%c:\\sns_pics"
#define SNS_UTIL_PIC_DIR_PROVIDER        "%c:\\sns_pics\\%08x"
#define SNS_UTIL_LOGO_SIZES              {45,32,24,20}

#if defined(__MMI_MAINLCD_480X800__) /* WVGA */
#define SNS_UTIL_LOGO_SMALL              32
#define SNS_UTIL_LOGO_LARGE              45
#elif defined(__MMI_MAINLCD_320X480__) /* HVGA */
#define SNS_UTIL_LOGO_SMALL              20
#define SNS_UTIL_LOGO_LARGE              32
#else /* QVGA & WQVGA */
#define SNS_UTIL_LOGO_SMALL              20
#define SNS_UTIL_LOGO_LARGE              24
#endif

WCHAR *sns_util_gen_md5(WCHAR *input);
WCHAR *sns_util_gen_cache_path(U32 provider, WCHAR *url, srv_sns_pic_enum type);
MMI_BOOL sns_util_cache_exists(WCHAR *path);
void sns_util_remove_cache_folder(U32 provider);
void sns_util_create_dir(WCHAR* path, MMI_BOOL is_hidden);
void sns_util_create_cache_folder(U32 provider);
void sns_util_create_cache_folder_base(void);
void sns_util_write_logos(sns_account_struct *account, void **icon_data, U32 *icon_size);
MMI_BOOL sns_util_prepare_to_upload(WCHAR *path, WCHAR *new_path);
void sns_util_finish_uploading(WCHAR *path);
void sns_util_update_contact_photo(U16 contact_id, WCHAR *path, srv_phb_op_callback_type cb, void *user_data);
MMI_BOOL sns_util_remove_contact_photo(U16 contact_id, U32 provider, srv_phb_op_callback_type cb, void *user_data);

// ============================================================================
    
srv_sns_result sns_util_get_error(S32 error_code);
srv_sns_result sns_util_merge_result(srv_sns_result result, S32 error_code);
MMI_BOOL sns_util_network_available(void);
void sns_util_log(const char *fmt, ...);

#endif
