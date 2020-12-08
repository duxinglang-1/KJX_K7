#ifndef __SNS_SRV_LIST_MGR_H__
#define __SNS_SRV_LIST_MGR_H__

#include "SnsSrvTypes.h"
#include "SnsSrvDsMgr.h"
#include "SnsSrvController.h"

#define SNS_LIST_CACHE_RANGE_ACCOUNTS      SRV_SNS_MAX_NUM_PROVIDERS
#ifdef __COSMOS_MMI_PACKAGE__            
#define SNS_LIST_CACHE_RANGE_ACTIVITIES    30
#else
#define SNS_LIST_CACHE_RANGE_ACTIVITIES    10
#endif
#define SNS_LIST_CACHE_TOTAL_ACTIVITIES    90
#define SNS_LIST_CACHE_RANGE_COMMENTS      30
#define SNS_LIST_CACHE_RANGE_FRIENDS       30
#define SNS_LIST_FETCH_RANGE_FRIENDS       60
#define SNS_LIST_CACHE_RANGE_GROUPS        SRV_SNS_MAX_NUM_GROUPS
#define SNS_LIST_CACHE_RANGE_REQUESTS      30
#define SNS_LIST_CACHE_RANGE_NOTIFICATIONS 30
#define SNS_LIST_CACHE_RANGE_THREADS_INIT  10
#define SNS_LIST_CACHE_RANGE_THREADS       20
#define SNS_LIST_CACHE_RANGE_MESSAGES      30
#define SNS_LIST_CACHE_RANGE_ALBUMS        30
#define SNS_LIST_CACHE_RANGE_PHOTOS        30
#define SNS_LIST_CACHE_RANGE_EVENTS        30

#define SNS_LIST_NEXT(p) *((void **)p)

typedef enum {
   SNS_LIST_ACCOUNTS, 
   SNS_LIST_ACTIVITIES,
   SNS_LIST_ACTIVITIES_NON_CACHEABLE,
   SNS_LIST_COMMENTS,
   SNS_LIST_FRIENDS,
   SNS_LIST_INFO,
   SNS_LIST_GROUPS,
   SNS_LIST_REQUESTS,
   SNS_LIST_NOTIFICATIONS,
   SNS_LIST_THREADS,
   SNS_LIST_MESSAGES,
   SNS_LIST_ALBUMS,
   SNS_LIST_ALBUMS_NON_CACHEABLE,
   SNS_LIST_PHOTOS,
   SNS_LIST_EVENTS,
   SNS_LIST_MEMBERS,
   SNS_LIST_LINK_CONTACTS,
   SNS_LIST_TOTAL
} sns_list_type_enum;

typedef struct sns_list {
   U32                 list_id;
   sns_list_type_enum  type;
   sns_process_struct  *process;
   S16                 start_index;
   S16                 end_index;
   U16                 total;
   void                *data;
   MMI_BOOL            valid;
   MMI_BOOL            more;
   MMI_BOOL            is_loading;
   srv_sns_result      result;
} sns_list_struct;

sns_list_struct *sns_list_find(S32 list_id);
void sns_list_ds_callback(sns_ds_request_struct *ds_req, sns_ds_req_status msg, void *arg);
MMI_BOOL sns_list_append_data(sns_list_struct *list, void *new_data);
void sns_list_process_data(sns_list_struct *list, U16 total, void *new_data);
srv_sns_activity_struct *sns_list_merge_data(srv_sns_activity_struct *data, srv_sns_activity_struct *new_data, U32 *total);
MMI_BOOL sns_list_check_data_before_insert(sns_list_struct *list, void *data);
U32 sns_list_get_cache_length(sns_list_type_enum type);
U32 sns_list_get_cache_length_total(sns_list_type_enum type);
S32 sns_list_get_pic(S32 list_id, S16 index, S16 index2, srv_sns_pic_enum type, U32 *provider, WCHAR **pic);
void sns_list_invalidate(sns_list_type_enum type, srv_sns_list_invalidated_reason reason, U32 provider);
MMI_BOOL sns_list_group_name_exists(U32 group_id, WCHAR *name);
srv_sns_friend_struct *sns_user_array_to_friend_list(srv_sns_user_list_struct *user_list, U8 count, U16 *total_out);

void sns_post_evt_list_updated(sns_list_struct *list, S32 result);
void sns_post_evt_item_updated(S32 list_id, S16 index, srv_sns_pic_enum pic_type, WCHAR *path, S32 result);
void sns_post_evt_item_ext_updated(S32 list_id, S16 index, srv_sns_object_enum type, char *obj_id, S32 result);
void sns_post_evt_list_invalidated(S32 list_id, srv_sns_list_invalidated_reason reason, U32 provider);
void sns_post_cb_evt_list_net_fetch(MMI_BOOL is_end, sns_list_struct *list);
#define sns_post_cb_evt_list_net_fetch_start(list) sns_post_cb_evt_list_net_fetch(MMI_FALSE,list)
#define sns_post_cb_evt_list_net_fetch_end(list)   sns_post_cb_evt_list_net_fetch(MMI_TRUE, list)

#endif
