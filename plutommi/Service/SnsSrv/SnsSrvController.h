#ifndef __SNS_SRV_CONTROLLER_H__
#define __SNS_SRV_CONTROLLER_H__

#include "SnsSrvGprot.h"
#include "SnsSrvDsMgr.h"

typedef enum {
    SNS_CONTROL_LOAD,
    SNS_CONTROL_LOAD_FROM_DS,
    SNS_CONTROL_LOAD_FROM_SERVER,
    SNS_CONTROL_INSERT,
    SNS_CONTROL_UPDATE,
    SNS_CONTROL_DELETE,
    SNS_CONTROL_DS_SELECTED,
    SNS_CONTROL_DS_INSERTED,
    SNS_CONTROL_DS_UPDATED,
    SNS_CONTROL_DS_DELETED,
    SNS_CONTROL_DS_LOGGED_OUT,
    SNS_CONTROL_INIT,
    SNS_CONTROL_RUN,
    SNS_CONTROL_NEXT,
    SNS_CONTROL_INVOKE,
    SNS_CONTROL_INVOKE_RESULT,
    SNS_CONTROL_RETURN,
    SNS_CONTROL_REMOVE,
    SNS_CONTROL_JOIN,
} sns_control_enum;

typedef enum {
    SNS_PROCESS_LOGIN                     = 1,
    SNS_PROCESS_LOGOUT                    = 2,
    SNS_PROCESS_ADD_COMMENT               = 3,
    SNS_PROCESS_UPDATE_STATUS             = 4,
    SNS_PROCESS_UPLOAD_PHOTO              = 5,
    SNS_PROCESS_SEND_MESSAGE              = 6,
    SNS_PROCESS_REPLY_MESSAGE             = 7,
    SNS_PROCESS_MODIFY_GROUP_MEMBER       = 8,
    SNS_PROCESS_MODIFY_LINK_CONTACT       = 9,
    SNS_PROCESS_ADD_GROUP                 = 10,
    SNS_PROCESS_RENAME_GROUP              = 11,
    SNS_PROCESS_REMOVE_GROUP              = 12,
    SNS_PROCESS_REMOVE_CONTACT            = 13,
    SNS_PROCESS_GET_ACCOUNTS              = 14,
    SNS_PROCESS_GET_FRIENDS               = 15,
    SNS_PROCESS_GET_GROUPS                = 16,
    SNS_PROCESS_GET_EVENTS                = 17,
    SNS_PROCESS_GET_ACTIVITIES            = 18,
    SNS_PROCESS_GET_ACTIVITY_BY_ID        = 19,
    SNS_PROCESS_GET_ACTIVITIES_BY_USER    = 20,
    SNS_PROCESS_GET_ACTIVITIES_BY_CONTACT = 21,
    SNS_PROCESS_GET_ACTIVITIES_BY_ME      = 22,
    SNS_PROCESS_GET_COMMENTS              = 23,
    SNS_PROCESS_GET_NOTIFICATIONS         = 24,
    SNS_PROCESS_GET_REQUESTS              = 25,
    SNS_PROCESS_GET_INFO                  = 26,
    SNS_PROCESS_GET_NOTIFICATION_COUNTS   = 27,
    SNS_PROCESS_GET_THREADS               = 28,
    SNS_PROCESS_GET_MESSAGES              = 29,
    SNS_PROCESS_GET_ALBUMS_BY_USER        = 30,
    SNS_PROCESS_GET_ALBUM_BY_ID           = 31,
    SNS_PROCESS_GET_PHOTOS_BY_ALBUM       = 32,
    SNS_PROCESS_GET_PHOTO_BY_ID           = 33,
    SNS_PROCESS_DOWNLOAD_SMALL            = 34,
    SNS_PROCESS_DOWNLOAD_BIG              = 35,
    SNS_PROCESS_SYNC_FRIENDS              = 36,
    SNS_PROCESS_SYNC_CALENDAR             = 37,
    SNS_PROCESS_CLEAR_NOTIFICATION        = 38,
    SNS_PROCESS_RESPOND_TO_REQUEST        = 39,
    SNS_PROCESS_MARK_MESSAGE              = 40,
    SNS_PROCESS_FB_LIKE                   = 41,
    SNS_PROCESS_FB_WRITE_WALL             = 42,
    SNS_PROCESS_TWT_FAVORITE              = 44,
    SNS_PROCESS_TWT_REPLY_TO_STATUS       = 45,
    SNS_PROCESS_TWT_RETWEET               = 46,
} sns_process_enum;

typedef enum {
    SNS_PROCESS_INIT,
    SNS_PROCESS_LOAD_FROM_CACHE_1,
    SNS_PROCESS_LOAD_FROM_CACHE_2,
    SNS_PROCESS_REFRESH_FROM_SERVER,
    SNS_PROCESS_READY,
} sns_process_state;

struct sns_process;
typedef struct sns_map_t sns_map;

typedef void (*sns_process_handler)(struct sns_process *process, sns_control_enum msg, void *arg);
    
typedef struct sns_process {
    S32                 process_id;
    sns_process_enum    op;
    sns_process_state   state;
    sns_process_handler handler;
    sns_map             *args;
    void                *callback;
    void                *userdata;
    struct sns_process  *parent;
    struct sns_process  *child;
} sns_process_struct;

typedef struct {
   MMI_EVT_PARAM_HEADER
   S32 process_id;
   sns_control_enum msg;
   void *arg;
} sns_process_command;

void sns_defer_process(sns_process_struct *process, sns_control_enum msg, void *arg);
#define SNS_PROCESS_RUN(PROCESS,MSG,ARG) PROCESS->handler(PROCESS, MSG, (void *)ARG)
#define SNS_PROCESS_RUN_LATER(PROCESS,MSG,ARG) sns_defer_process(PROCESS, MSG, (void *)ARG)
void sns_process_ds_callback(sns_ds_request_struct *ds_req, sns_ds_req_status msg, void *arg);

typedef MMI_BOOL (*sns_process_matcher)(sns_process_struct *process, void *key);
sns_process_struct *sns_find_process(sns_process_matcher matcher, void *key);
sns_process_struct *sns_find_process_by_op(sns_process_enum op);
sns_process_struct *sns_find_process_by_id(S32 id);

sns_process_struct *sns_add_process(U8 count, sns_process_handler handler, sns_process_enum op, void *cb, void *user_data);
// LIST, INDEX, OFFSET
#define sns_add_list_fetching_process(count, handler, op) sns_add_process(count+3, handler, op, NULL, NULL)
void sns_remove_process(sns_process_struct *process);

void sns_accounts_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_generic_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_friends_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_groups_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_thread_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_notification_counts_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_non_cacheable_data_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_group_and_contact_editor(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_member_and_link_contact_editor(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_login_process_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_logout_process_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_multi_providers_bkgd_process_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_single_provider_bkgd_process_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_generic_op_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_sync_friends_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_sync_friends_picture_sub_process(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_single_item_picture_downloader(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_multi_pictures_downloader(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_feed_by_users_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
#ifdef __MMI_SNS_CALENDAR__
void sns_events_fetcher(sns_process_struct *process, sns_control_enum msg, void *arg);
void sns_sync_calendar_controller(sns_process_struct *process, sns_control_enum msg, void *arg);
#endif

void sns_post_evt_result(sns_process_struct *process, S32 result);
void sns_post_cb_evt_counts_updated(void);
void sns_post_cb_evt_process_start(sns_process_struct *process);
void sns_post_cb_evt_process_complete(sns_process_struct *process, U8 success, U8 failure, U32 *providers, S32 *results);
void sns_post_cb_evt_ready(S32 result);

#endif
