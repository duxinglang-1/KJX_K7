#ifndef __SNS_SRV_GPROT_H__
#define __SNS_SRV_GPROT_H__

#include "mmi_frm_gprot.h"
#include "PhbSrvGprot.h"
#include "TodolistSrvGprot.h"
#include "SnsSrvTypes.h"
#include "SnsSrvDefs.h"

typedef struct
{
    LOCAL_PARA_HDR
    S32 req_id;
    S32 result;        /**< == 0, success; <0, failed */
    void *user_data;
} sns_encode_jpeg_rsp_struct;

/**
 * service initialization
 */
void srv_sns_init(void);

/**
 * get error string by error code
 * @param error_code error code from plug-in, data storage, service
 * @returns string id
 */
MMI_STR_ID srv_sns_get_error_string(S16 error_code);

/**
 * check whether sns service is ready or not
 * @returns true when ready; false when not ready
 */
MMI_BOOL srv_sns_is_ready(void);

/**
 * similiar to srv_sns_is_ready but the return is srv_sns_result 
 * @returns SRV_SNS_OK when ready; SRV_SNS_DEV_PLUG_OUT or SRV_SNS_USB_MS_MODE when not ready
 */
srv_sns_result srv_sns_get_ready(void);

/**
 * service initialization
 */
MMI_BOOL srv_sns_check_ready(void);

/**
 * enter app, do not free library
 */
void srv_sns_enter_app(void);

/**
 * exit app, free library if necessary
 */
void srv_sns_exit_app(void);

/**
 * get the number of instances which using SNS SRV
 */
U8 srv_sns_get_instances(void);

/**
 * force unload all plug-ins
 */
void srv_sns_free_libraries(void);

/**
 * cancel a pending or running process
 * @param [in] process_id request to cancel
 * @returns srv_sns_result
 */
srv_sns_result srv_sns_cancel(
   S32 process_id
);

/**
 * stop an operation which might be able to retry later
 * @param [in] process_id request to stop
 * @returns srv_sns_result
 */
srv_sns_result srv_sns_stop(
   S32 process_id
);

/**
 * check if the user is still logged-in to all the providers of the failed requests
 * @param [in] process_id request to retry
 * @returns true if srv_sns_retry can be called
 */
MMI_BOOL srv_sns_can_retry(S32 process_id);

/**
 * retry a failed request
 * @param [in] process_id request to retry
 * @returns srv_sns_result
 */
srv_sns_result srv_sns_retry(
   S32 process_id
);

/**
 * get accounts filtered by login status and features
 * @param [in] login filter accounts by login status
 * @param [in] category the category of the feature to match
 * @param [in] features bit mask of required features returning accounts must support
 * @param [out] count number of accounts in the return list
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_account_struct
 */
S32 srv_sns_get_accounts( // srv_sns_account_struct
   srv_sns_login_enum       login,
   srv_sns_feature_category category,
   U8                       features,
   U16                      *count
);

/**
 * get account structure by provider id
 * @param [in] provider provider id
 * @param [out] account account structure
 * @returns srv_sns_result
 */
S32 srv_sns_get_account(
   U32                      provider,
   srv_sns_account_struct   *account
);

/**
  * @returns
  */
MMI_BOOL srv_sns_is_login(
   U32 provider
);

#define srv_sns_is_any_login_acocunt() srv_sns_is_login(0)

/**
 * get icon for specified provider
 * @param [in] provider the provider to get icon
 * @param [in] size the size of the icon to get: big or small
 * @returns icon path
 */
WCHAR *srv_sns_get_provider_icon(
   U32                      provider,
   srv_sns_logo_enum        size
);

/**
 * get icon for specified provider
 * @param [in] provider the provider to get icon
 * @param [in] size the size of the icon to get: big or small
 * @returns icon raw data
 */
void *srv_sns_get_provider_icon_data(
   U32                      provider,
   srv_sns_logo_enum        size
);

/**
 * get icon for specified provider
 * @param [in] provider the provider to get icon
 * @param [in] size the size of the icon to get: big or small
 * @returns icon raw data size
 */
U32 srv_sns_get_provider_icon_size(
   U32                      provider,
   srv_sns_logo_enum        size
);

/**
 * get name for specified provider
 * @param [in] provider the provider to get name
 * @returns name
 */
WCHAR *srv_sns_get_provider_name(
   U32                      provider
);

/**
 * check features supported by a provider
 * @param [in] provider the provider to check
 * @param [in] category the category of the feature to match
 * @param [in] features bit mask of required features the provider have to support
 * @returns true if all if the provider supports all features specified; false otherwise
 */
MMI_BOOL srv_sns_check_feature(
   U32                      provider,
   srv_sns_feature_category category,
   U8                       features
);

/**
 * login to the specific provider with username and password
 * @param [in] provider  which provider to login in
 * @param [in] username  username
 * @param [in] password  password
 * @param [in] done_cb  callback will be called when the operation is done
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_login(
   U32                      provider,
   WCHAR                    *username,
   WCHAR                    *password,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * logout to the specific provider
 * @param [in] provider  which provider to logout in
 * @param [in] done_cb  callback will be called when the operation is done
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_logout(
   U32                      provider,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * load a list from local storage or database to memory
 * @param [in] list_id  list to load
 * @param [in] index  which item to load
 * @param [in] done_cb  will be called when the list finishes loading
 * @param [in] user_data will be passed along in the callback
 * @returns srv_sns_result
 * @see srv_sns_evt_list_updated
 */
srv_sns_result srv_sns_load_list(
   S32                      list_id, 
   S16                      index, 
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_LIST_UPDATED
   void                     *user_data
);

/**
 * check whether the list is valid from which to get items 
 * @param [in] list_id  the list 
 * @param [out] start_index start index of valid data in the list
 * @param [out] end_index end index of valid data in the list
 * @param [out] total tatal number of data (including not loaded) in the list 
 * @returns true for valid; false for invalid
 */
MMI_BOOL srv_sns_check_list(
   S32                      list_id,
   S16                      *start_index,
   S16                      *end_index,
   U16                      *total
);

/**
 * check whether the list is loading
 * @param [in] list_id  the list 
 * @returns true if loading
 */
MMI_BOOL srv_sns_is_list_loading(
   S32                      list_id
);


/**
 * get the point to the item specified by its index
 * @param [in] list_id  from which list to get item from 
 * @param [in] index  the index of the item
 * @param [out] out will point to the result item
 * @returns srv_sns_result
 */
srv_sns_result srv_sns_get_item(
   S32                      list_id, 
   S16                      index,
   void                     **out
);

/**
 * same as srv_sns_get_item except not check whether the list is valid
 * @see srv_sns_get_item
 */
srv_sns_result srv_sns_get_item2(S32 list_id, S16 index, void **out);


/**
 * release the list
 * @param [in] list_id  list to release
 * @param [in] del this parameter is deprecated
 * @returns srv_sns_result
 */
srv_sns_result srv_sns_release_list(
   S32                      list_id,
   MMI_BOOL                 del
);

/**
 * refresh the list
 * @param [in] list_id  list to refresh
 * @param [in] done_cb  will be called when the list finishes loading
 * @param [in] user_data will be passed along in the callback
 * @returns srv_sns_result
 * @see srv_sns_evt_list_updated
 */
srv_sns_result srv_sns_refresh_list(
   S32                      list_id,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_LIST_UPDATED
   void                     *user_data
);

/**
 * get activities from a specific provider or group, get all if none provided
 * @param [in] type  acvitity type to get
 * @param [in] provider from which provider
 * @param [in] group  from which group
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_activity_struct
 */
S32 srv_sns_get_list_of_activities( // srv_sns_activity_struct
   srv_sns_activity_enum    type,
   U32                      provider,    // either select by provider
   U32                      group,       // or select by group
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get activity by id
 * @param [in] provider  where the activity is from
 * @param [in] act_id  the identity on that provider of the activity
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_activity_struct
 */
S32 srv_sns_get_list_of_activity_by_id( // srv_sns_activity_struct
   U32                      provider,
   CHAR                     *act_id,
   MMI_BOOL                 down_pic
);

/**
 * get activities from one friend
 * @param [in] provider  provider_id
 * @param [in] user_id  an array of pointers to user_ids
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @param [in] limit number of activities to fetch, 0 to use default
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_activity_struct
 */
S32 srv_sns_get_list_of_activities_by_user_with_limit( // srv_sns_activity_struct
   U32                      provider,
   CHAR                     *user_id,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh,
   U32                      limit
);
#define srv_sns_get_list_of_activities_by_user(provider,user_id,down_pic,refresh) srv_sns_get_list_of_activities_by_user_with_limit(provider,user_id,down_pic,refresh,0)

/**
 * get activities from one or more sns friends linked by the same phonebook contact
 * @param [in] contact_id contact id in phonebook
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_activity_struct
 */
S32 srv_sns_get_list_of_activities_by_contact( // srv_sns_activity_struct
   U16                      contact_id,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get activities from logged-in accounts 
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_activity_struct
 */
S32 srv_sns_get_list_of_activities_by_me( // srv_sns_activity_struct
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get comments of an object
 * @param [in] provider  the provider to get comments from
 * @param [in] type the type of object to get comments
 * @param [in] obj_id the id of the object to get comments
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_comment_struct
 */
S32 srv_sns_get_list_of_comments( // srv_sns_comment_struct
   U32                      provider,
   srv_sns_object_enum      type,
   CHAR                     *obj_id,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * comment on an activity
 * @param [in] provider  the provider which the activity is from
 * @param [in] type the type of the object to add comment to
 * @param [in] obj_id  the id of the object to add comment to
 * @param [in] comment  the comment string
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_add_comment(
   U32                      provider,
   srv_sns_object_enum      type,
   CHAR                     *obj_id,
   WCHAR                    *comment
);

/**
 * get number of messages, notifications, requests asynchronously. a EVT_ID_SRV_SNS_COUNTS_UPDATED will be posted if the counts are updated
 */
void srv_sns_fetch_counts(void);

/**
 * get number of messages, notifications, requests cached at memory
 * @param [out] counts result
 * @returns total
 */
U16 srv_sns_get_counts(
   srv_sns_counts_struct*   counts
);

/**
 * get number of messages, notifications, requests stored at NVRAM
 * @param [out] counts result
 * @returns total
 */
U16 srv_sns_get_counts_from_nvram(
   srv_sns_counts_struct*   counts
);

/**
 * clear notification counts
 * @param [in] provider specific one provider id or SRV_SNS_PROVIDER_ALL
 * @param [in] memory clear counts in memory
 * @param [in] nvram clear counts in nvram
 */
void srv_sns_clear_counts(
   U32                      provider, 
   MMI_BOOL                 memory,
   MMI_BOOL                 nvram
);

/**
 * get notifications
 * @param [in] provider  the provider to get notifications, or SRV_SNS_PROVIDER_ALL for all
 * @param [in] type the type of notifications to get, filtered at the client side only
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_notif_struct
 */
S32 srv_sns_get_list_of_notifications_type( // srv_sns_notif_struct
   U32                      provider,
   srv_sns_object_enum      type,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

#define srv_sns_get_list_of_notifications(provider,down_pic,refresh) srv_sns_get_list_of_notifications_type(provider,SRV_SNS_OBJECT_TOTAL,down_pic,refresh)

/**
 * clear notification unread status
 * @param [in] provider  the provider which the notification is from
 * @param [in] notif_ids an array of notification ids to be cleared
 * @param [in] count the number of items in the array above
 * @param [in] done_cb  callback will be called when the operation is done
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_clear_notification(
   U32                      provider,
   CHAR                     **notif_ids, 
   U8                       count,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * get requests 
 * @param [in] provider  the provider to get requests, or SRV_SNS_PROVIDER_ALL for all 
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_request_struct
 */
S32 srv_sns_get_list_of_requests( // srv_sns_request_struct
   U32                      provider,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * accept or ignore a request
 * @param [in] provider  the provider which the request is from
 * @param [in] request_id  the id of the request to reply to
 * @param [in] accept  true to accept this request, false to ignore
 * @param [in] done_cb  callback will be called when the operation is done
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_respond_to_request(
   U32                      provider,
   CHAR                     *request_id,
   MMI_BOOL                 accept,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * get friends by provider or group
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_info_struct
 */
S32 srv_sns_get_list_of_friends( // srv_sns_info_struct
   U32                        provider,
   S32                        group,
   U16                        contact,
   WCHAR                      *name
);
#define srv_sns_get_all_friends()                                                     srv_sns_get_list_of_friends(0, 0, SRV_PHB_INVALID_INDEX, NULL)
#define srv_sns_get_friends_by_provider(provider)                                     srv_sns_get_list_of_friends(provider, 0, SRV_PHB_INVALID_INDEX, NULL)
#define srv_sns_get_friends_by_group(group)                                           srv_sns_get_list_of_friends(0, group, SRV_PHB_INVALID_INDEX, NULL)
#define srv_sns_get_friends_by_contact(contact)                                       srv_sns_get_list_of_friends(0, 0, contact, NULL)
#define srv_sns_get_friends_by_not_in_group(group)                                    srv_sns_get_list_of_friends(0, -group, SRV_PHB_INVALID_INDEX, NULL)
#define srv_sns_get_friends_by_not_in_group_in_provider(provider, group)              srv_sns_get_list_of_friends(provider, -group, SRV_PHB_INVALID_INDEX, NULL)
#define srv_sns_get_friends_by_name(name)                                             srv_sns_get_list_of_friends(0, 0, SRV_PHB_INVALID_INDEX, name)
#define srv_sns_get_friends_by_name_and_group(name,group)                             srv_sns_get_list_of_friends(0, group, SRV_PHB_INVALID_INDEX, name)
#define srv_sns_get_friends_by_name_and_provider(name,provider)                       srv_sns_get_list_of_friends(provider, 0, SRV_PHB_INVALID_INDEX, name)
#define srv_sns_get_friends_by_name_and_not_in_group(name,group)                      srv_sns_get_list_of_friends(0, -group, SRV_PHB_INVALID_INDEX, name)
#define srv_sns_get_friends_by_name_and_not_in_group_in_provider(name,group,provider) srv_sns_get_list_of_friends(provider, -group, SRV_PHB_INVALID_INDEX, name)

/**
 * add search key to a existing friend list; the original list data will be freed
 * @param [in] list_id based on which list to search for friends
 * @param [in] name the key to search for friend
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_info_struct
 */
S32 srv_sns_search_friends(
   S32                        list_id,
   WCHAR                      *name,
   void                       *user_data
);

/**
 * get info of a sns friend
 * @param [in] provider  where the user is from
 * @param [in] user_id  the identity on that provider of the user
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_info_struct
 */
S32 srv_sns_get_list_of_user_info( // srv_sns_info_struct
   U32                      provider,
   CHAR                     *user_id,
   MMI_BOOL                 down_pic
);

/**
 * get all groups
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_group_struct
 */
S32 srv_sns_get_list_of_groups( // srv_sns_group_struct
   void
);

/**
 * add a new group
 * @param [in] name  name of the group to create
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_add_group(
   WCHAR                    *name,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * rename a group
 * @param [in] group  the group to rename
 * @param [in] name  new name
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_rename_group(
   U32                      group,
   WCHAR                    *name,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * remove a group
 * @param [in] groups an array of group ids to removed
 * @param [in] count number of items in the array above
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_remove_group(
   U32                      *groups,
   U8                       count,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * check whether the user is in the list
 * @param [in] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] list_id  the list which the selected user comes from
 * @param [in] index  the index of that user in the list 
 * @returns >= 0 for the index of the user, 0xff if not found
 */
U8 srv_sns_find_in_user_list(
   srv_sns_user_list_struct *user_list,
   U8                       count,
   S32                      list_id,
   S16                      index
);

/**
 * remove user from the list
 * @param [in] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] index  the index of that user in the list 
 * @returns MMI_TRUE for successful operation, MMI_FALSE otherwise
 */
void srv_sns_remove_from_user_list(
   srv_sns_user_list_struct *user_list,
   U8                       count,
   S16                      index
);

/**
 * add/remove user to/from the list
 * @param [out] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] list_id  the list which the selected user comes from
 * @param [in] index  the index of that user in the list 
 * @param [in] to_add  true to add, false to remove
 * @returns MMI_TRUE for successful operation, MMI_FALSE otherwise
 */
MMI_BOOL srv_sns_edit_user_list(
   srv_sns_user_list_struct *user_list,
   U8                       count,
   S32                      list_id,
   S16                      index,
   MMI_BOOL                 to_add
);

/**
 * add/remove member to/from a group
 * @param [in] group  the group to add member to 
 * @param [in] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] to_add  true to add, false to remove
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_modify_group_member(
   U32                      group,
   srv_sns_user_list_struct *user_list,
   U8                       count,
   MMI_BOOL                 to_add,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * link/unlink sns friend for a contact
 * @param [in] contact_id  the contact id to link/unlik 
 * @param [in] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] to_add  true to link, false to unlink
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_modify_link_contact(
   U16                      contact_id,
   srv_sns_user_list_struct *user_list,
   U8                       count,
   MMI_BOOL                 to_add,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * update status on a list of providers
 * @param [in] status  the status to update
 * @param [in] providers  an array of providers to update 
 * @param [in] count  the number of providers
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_update_status(
   WCHAR                    *status,
   U32                      *providers,
   U8                       count
);

/**
 * upload a photo
 * @param [in] desc  description of the photo
 * @param [in] path  path of the photo in the file system
 * @param [in] providers  an array of providers to update 
 * @param [in] count  the number of providers
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_upload_photo(
   WCHAR                    *desc,
   WCHAR                    *path,
   U32                      *providers,
   U8                       count
);

/**
 * get threads
 * @param [in] provider the provider to threads from, or SRV_SNS_PROVIDER_ALL to get all
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_thread_struct
 */
S32 srv_sns_get_list_of_threads( // srv_sns_thread_struct
   U32                      provider,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get a specific thread by id
 * @param [in] provider the provider which the specific thread_id is from
 * @param [in] thread_id  will get the message of the specified thread 
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_thread_struct
 */
S32 srv_sns_get_list_of_thread_by_id( // srv_sns_thread_struct
   U32                      provider,
   CHAR                     *thread_id, 
   MMI_BOOL                 down_pic
);

/**
 * get messages
 * @param [in] provider the provider which the specific thread_id is from
 * @param [in] thread_id  will get the message of the specified thread 
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_message_struct
 */
S32 srv_sns_get_list_of_messages( // srv_sns_message_struct
   U32                      provider,
   CHAR                     *thread_id, 
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get the max number of recipients the user can send to a provider
 * @param [in] provider  which provider to send message to
 * @returns recipient count
 */
U8 srv_sns_get_max_recipients(
   U32                      provider
);

/**
 * send a new message
 * @param [in] provider  which provider to send message to
 * @param [in] user_list  the buffer provided by the caller to hold the selected users
 * @param [in] count  the number of srv_sns_user_list_struct the buffer can hold
 * @param [in] message  the message to send
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_send_message(
   U32                      provider,
   srv_sns_user_list_struct *user_list,
   U8                       count,
   WCHAR                    *message
);

/**
 * reply a message/thread
 * @param [in] provider  which provider to send message to
 * @param [in] thread_id  the thread_id to reply to
 * @param [in] message  the message to send
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_reply_message(
   U32                      provider,
   CHAR                     *thread_id,
   WCHAR                    *message
);

/**
 * mark a message as read/unread
 * @param [in] provider  which provider to send message to
 I @param [in] thread_id  thread id
 * @param [in] read  true for read, false for unread
 * @param [in] done_cb  callback will be called when the operation is done
 * @param [in] user_data will be passed along in the callback
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_mark_message(
   U32                      provider,
   CHAR                     *thread_id,
   MMI_BOOL                 read,
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);

/**
 * get albums fo a user
 * @param [in] provider  where the user is from
 * @param [in] user_id  the identity on that provider of the user
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_album_struct
 */
S32 srv_sns_get_list_of_albums_by_user( // srv_sns_album_struct
   U32                      provider,
   CHAR                     *user_id,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get album by id
 * @param [in] provider  where the album is from
 * @param [in] album_id  the identity on that provider of the album
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_album_struct
 */
S32 srv_sns_get_list_of_album_by_id( // srv_sns_album_struct
   U32                      provider,
   CHAR                     *album_id,
   MMI_BOOL                 down_pic
);

/**
 * get photos in an album
 * @param [in] provider  where the album is from
 * @param [in] album_id  the identity on that provider of the album
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @param [in] refresh  must return results from server if true
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_photo_struct
 */
S32 srv_sns_get_list_of_photos_by_album( // srv_sns_photo_struct
   U32                      provider,
   CHAR                     *album_id,
   MMI_BOOL                 down_pic,
   MMI_BOOL                 refresh
);

/**
 * get photo by id
 * @param [in] provider  where the photo is from
 * @param [in] photo_id  the identity on that provider of the photo
 * @param [in] down_pic  whether or not to download pictures not in file cache
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_photo_struct
 */
S32 srv_sns_get_list_of_photo_by_id( // srv_sns_photo_struct
   U32                      provider,
   CHAR                     *photo_id,
   MMI_BOOL                 down_pic
);

/**
 * get events 
 * @param [in] provider which provider to get events 
 * @param [in] type the type of events to retrieve
 * @param [in] search how to look for events
 * @returns > 0 for list id; < 0 for srv_sns_result
 * @see srv_sns_event_struct
 */
S32 srv_sns_get_list_of_events( // srv_sns_event_struct
   U32                                provider,
   srv_sns_event_type                 type,
   srv_sns_event_search_filter_struct *search
);

/**
 * check whether the picture is a ur
 * @param [in] pic the picture url/path field
 * @returns true if it is a url
 */
MMI_BOOL srv_sns_is_url(WCHAR *pic);

/**
 * download picture of an item in a list
 * @param [in] list_id  the list 
 * @param [in] index  the index   
 * @param [in] type the type of picture to download
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_down_pic(
   S32                      list_id,
   S16                      index,
   srv_sns_pic_enum         type
);

/**
 * update a setting for specific account
 * @param [in] provider  which account to update
 * @param [in] setting  the enum of setting to set
 * @param [in] value  the new value
 * @returns <= 0 for srv_sns_result
 */
S32 srv_sns_set_account_setting(
   U32                      provider,
   srv_sns_setting_enum     setting, 
   U32                      value
);

/**
 * get global setting value
 * @param [in] setting  the enum of setting to set
 * @param [out] value  the new value
 * @returns <= 0 for srv_sns_result
 */
S32 srv_sns_get_global_setting(
   srv_sns_setting_enum     setting, 
   U32                      *value
);

/**
 * update global setting value
 * @param [in] setting  the enum of setting to set
 * @param [in] value  the new value
 * @returns <= 0 for srv_sns_result
 */
S32 srv_sns_set_global_setting(
   srv_sns_setting_enum     setting, 
   U32                      value
);

/**
 * get the number of secords between interval for get notification counts (news reminder setting)
 * @returns 0 if news reminder is set to never
 * >0 seconds
 */
U32 srv_sns_get_news_reminder_secs(void);

/**
 * check if SNS SRV is syncing friends for a specific provider
 * @param [in] provider  
 */
MMI_BOOL srv_sns_is_syncing_friends(
   U32                      provider
);

/**
 * check if SNS SRV is syncing friends at all
 */
MMI_BOOL srv_sns_any_friend_syncing(void);

/**
 * check if srv_sns_sync_unsynced_friends needs to be called in order to show a specific friend list
 * @param [in] list_id 
 */
MMI_BOOL srv_sns_need_to_sync_friends(S32 list_id);

/**
 * sync friends for a specific provider
 * @param [in] provider 
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_sync_friends(
   U32                      provider
);

/**
 * sync friends for all unsynced providers
 */
MMI_BOOL srv_sns_sync_unsynced_friends(void);

/**
 * cancel all friend syncing processes
 */
void srv_sns_cancel_sync_friends(void);

/**
 * check if SNS SRV is syncing calendar
 * @param [in] provider  
 * @returns TRUE if syncing calendar
 */
MMI_BOOL srv_sns_is_syncing_calendar(
   U32                      provider
);

/**
 * sync calendar for a specific provider
 * @param [in] provider 
 * @returns > 0 for process id; < 0 for srv_sns_result
 */
S32 srv_sns_sync_calendar(
   U32                      provider
);

/**
 * Called by MMI. In order to wait for encoding finish. Then keep on onDeinit
 */
void srv_sns_encode_stop(kal_uint32 req_id);

/**
 * Called by MMI. Send DB task to encode JPEG
 */
kal_uint32 srv_sns_send_encode_req(WCHAR *dst, S32 dest_width, S32 dest_height, U8 cf, U8 *buf_ptr, S32 buf_size, void *user_data);

#ifdef __MMI_SNS_CALENDAR__

/**
 * convert provider id into srv_tdl_event_source_enum
 * @param [in] provider provider id
 * @returns srv_tdl_event_source_enum
 */
srv_tdl_event_source_enum srv_sns_provider_to_tdl_source(U32 provider);

/**
 * convert srv_tdl_event_source_enum into provider id
 * @param [in] source tdl source enum
 * @returns provider id
 */
U32 srv_sns_provider_from_tdl_source(srv_tdl_event_source_enum source);

#endif /* __MMI_SNS_CALENDAR__ */

#ifdef __MMI_SNS_CONTACTS__

/**
 * unlink all friends linked by a contact
 * @param [in] group  the contact  to unlink
 * @param [in] done_cb  will be called when the item is ready
 * @param [in] user_data will be passed along in the callback
 */
void srv_sns_remove_contact(
   U16                      contact_id, 
   mmi_proc_func            done_cb, // EVT_ID_SRV_SNS_RESULT
   void                     *user_data
);    

/**
 * test if a contact is linked by an sns friend
 * @returns whether the contact is linked
 */
MMI_BOOL srv_sns_is_contact_linked(
   S16                        contact,
   S32                        *result
);

/**
 * to be called by PHB SRV to notify SNS SRV of the start to deleting multiple contacts
 */
void srv_sns_phb_start_multi_op(void);

/**
 * to be called by PHB SRV to notify SNS SRV of the end to deleting multiple contacts
 */
void srv_sns_phb_stop_multi_op(void);

#endif /* __MMI_SNS_CONTACTS__ */

/**
 * ask Upgrade Service to check if new version of plug-ins are available for download
 */
void srv_sns_check_update(void);

#endif
