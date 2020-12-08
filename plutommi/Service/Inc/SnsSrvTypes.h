#ifndef __SNS_SRV_TYPES_H__
#define __SNS_SRV_TYPES_H__

#include "MMIDataType.h"
#include "SnsSrvDefs.h"

/**
 * user structure embedded in many of the structures below
 */
typedef struct {
   U32 provider;
   U32 index;                          /**< used by data storage, do not modify it */
   U8 user_id_len;   CHAR *user_id;
   U8 user_name_len; WCHAR *user_name;
   U8 user_pic_len;  WCHAR *user_pic;  /**< local path or URL of the profile picture of the user */
} srv_sns_user_struct;

/**
 * hold a temp list of users to be used by the following functions
 * @see srv_sns_find_in_user_list
 * @see srv_sns_remove_from_user_list
 * @see srv_sns_edit_user_list
 * @see srv_sns_modify_group_member
 * @see srv_sns_modify_link_contact
 * @see srv_sns_send_message
 */
typedef struct srv_sns_user_list {
   U32 provider;
   U32 index;                               /**< used by data storage, do not modify it */
   CHAR user_id[SRV_SNS_MAX_LEN_ID];
   WCHAR user_name[SRV_SNS_MAX_LEN_NAME];
   WCHAR user_pic[SRV_SNS_MAX_LEN_PIC_URL];
} srv_sns_user_list_struct;

/**
 * node structure of for singly linked list of accounts 
 * @see srv_sns_get_accounts
 */
typedef struct srv_sns_account {
   struct srv_sns_account *next;
   U32 provider;
   WCHAR *name;                        /**< point to static memory of service */
   U8 features[SRV_SNS_FEATURE_TOTAL];
   srv_sns_user_struct user;           /**< user_id is NULL if not logged-in  */
   WCHAR *profile_url;
   WCHAR *login_id;
   MMI_BOOL sync_contacts;
   MMI_BOOL sync_calendar;
   MMI_BOOL sync_phonebook;
} srv_sns_account_struct;

/**
 * node structure for singly-linked list of users
 * @see srv_sns_get_list_of_threads
 * @see srv_sns_thread_struct
 */
typedef struct srv_sns_friend {
   struct srv_sns_friend *next;
   srv_sns_user_struct user;
} srv_sns_friend_struct;

/**
 * node structure for singly-linked list of activities (a.k.a happenings, feeds)
 * @see srv_sns_get_list_of_activities
 * @see srv_sns_get_list_of_activities_by_user_with_limit
 * @see srv_sns_get_list_of_activities_by_contact
 * @see srv_sns_get_list_of_activities_by_me
 * @see srv_sns_get_list_of_activity_by_id
 */
typedef struct srv_sns_activity {
   struct srv_sns_activity *next;
   srv_sns_user_struct user;        /**< actor of this activity                                          */
   srv_sns_activity_enum type;      /**< SRV_SNS_ACTIVITY_NEWSFEED                                       */
   U8 act_id_len;   CHAR *act_id;   /**< activity id used for getting comments                           */
   U8 photo_id_len; CHAR *photo_id; /**< photo id used for getting photo details                         */
   U16 message_len; WCHAR *message; /**< text content of this activity                                   */
   U16 link_len;    CHAR *link;     /**< additional url attached with this activity (e.g. a shared link) */
   U8 has_pic;                      /**< TRUE if pic is not NULL                                         */
   U16 pic_len;     WCHAR *pic;     /**< file path or URL of a picture associated with this activity     */
   U32 timestamp;                   /**< time stamp will be in decreasing order in this list             */
   U32 blob_size;                   /**< the size of the extension part of this struct (if available)    */
} srv_sns_activity_struct;          

/**
 * node structure for singly-linked list of comments
 * @see srv_sns_get_list_of_comments
 */
typedef struct srv_sns_comment {
   struct srv_sns_comment *next;
   srv_sns_user_struct user;
   U16 comment_len; WCHAR *comment; /**< text content of this comment                        */
   U32 timestamp;                   /**< time stamp must be in decreasing order in this list */
} srv_sns_comment_struct;

/**
 * notification counts
 * @see srv_sns_get_counts
 * @see srv_sns_get_counts_from_nvram
 */
typedef struct srv_sns_counts {
   U8 messages;      /**< number of unread messages            */
   U8 notifications; /**< number of unread notifications       */
   U8 requests;      /**< number of requests not yet processed */
} srv_sns_counts_struct;

/**
 * node structure for singly-linked list of notifications
 * @see srv_sns_get_list_of_notifications_type
 */
typedef struct srv_sns_notif {
   struct srv_sns_notif *next;
   srv_sns_user_struct user;
   U8 notif_id_len;      CHAR *notif_id;
   U16 notification_len; WCHAR *notification; /**< text content of this notification                   */
   srv_sns_object_enum type;
   U8 object_id_len;     CHAR *object_id;     /**< could be an activity, a photo of a friend           */
   U32 timestamp;                             /**< time stamp must be in decreasing order in this list */
   U16 href_len;         CHAR *href;          /**< link the the content of this notification           */
} srv_sns_notif_struct;

/**
 * node structure for singly-linked list of requests
 * @see srv_sns_get_list_of_requests
 */
typedef struct srv_sns_request {
   struct srv_sns_request *next;
   srv_sns_user_struct user;
   U8 request_id_len; CHAR *request_id;
   U16 request_len;   WCHAR *request;   /**< text content of this request                        */
   U32 timestamp;                       /**< time stamp must be in decreasing order in this list */
} srv_sns_request_struct;

/**
 * node structure for singly-linked list of user infos
 * @see srv_sns_get_list_of_friends
 * @see srv_sns_search_friends
 * @see srv_sns_get_list_of_user_info
 */
typedef struct srv_sns_info {
   struct srv_sns_info *next;
   srv_sns_user_struct user;
   U8 profile_url_len; WCHAR *profile_url;
   srv_sns_gender_enum gender;
   U8 birthday_len;    WCHAR *birthday;    /**< if presented, must be in the format of either "01/31/2011" or "01/31" */
   U8 phone_len;       WCHAR *phone;
   U8 email_len;       WCHAR *email;
   U8 address_len;     WCHAR *address;
   U8 status_len;      WCHAR *status;
   U32 index;                              /**< used by data storage, do not modify it */
} srv_sns_info_struct;

/**
 * node structure for singly-linked list of threads
 * @see srv_sns_get_list_of_threads
 * @see srv_sns_get_list_of_thread_by_id
 */
typedef struct srv_sns_thread {
   struct srv_sns_thread *next;
   U8 participant_count;              /**< the nubmer of participants in the following list     */
   srv_sns_friend_struct *users;      /**< one more more participants                           */
   U8 thread_id_len; CHAR *thread_id;
   U16 snippet_len;  WCHAR *snippet;  /**< some text content of the messages within this thread */
   U8 unread;
   U32 timestamp;                     /**< time stamp must be in decreasing order in this list  */
} srv_sns_thread_struct;

/**
 * node structure for singly-linked list of messages
 * @see srv_sns_get_list_of_messages
 */
typedef struct srv_sns_message {
   struct srv_sns_message *next;
   srv_sns_user_struct user;
   U8 thread_id_len; CHAR *thread_id; /**< the id of the thread this message belongs to        */
   U8 msg_id_len;    CHAR *msg_id;
   U16 message_len;  WCHAR *message;  /**< text content of this message                        */
   U8 unread;
   U32 timestamp;                     /**< time stamp must be in decreasing order in this list */
} srv_sns_message_struct;

/**
 * node structure for singly-linked list of albums
 * @see srv_sns_get_list_of_albums_by_user
 * @see srv_sns_get_list_of_album_by_id
 */
typedef struct srv_sns_album {
   struct srv_sns_album *next;
   U32 provider;
   U8 album_id_len;  CHAR *album_id;
   U8 user_id_len;   CHAR *user_id;     /**< the id of the owner of this album                   */
   U8 name_len;      WCHAR *name;       /**< the title of this album                             */
   U8 thumbnail_len; WCHAR *thumbnail;  /**< local path or URL of the thumbnail                  */
   U16 count;                           /**< number of photos in this album                      */
   U32 timestamp;                       /**< time stamp must be in decreasing order in this list */
} srv_sns_album_struct;

/**
 * node structure for singly-linked list of photos
 * @see srv_sns_get_list_of_photos_by_album
 * @see srv_sns_get_list_of_photo_by_id
 */
typedef struct srv_sns_photo {
   struct srv_sns_photo *next;
   U32 provider;
   U8 album_id_len;     CHAR *album_id;     /**< time stamp must be in decreasing order in this list */
   U8 user_id_len;      CHAR *user_id;
   U8 photo_id_len;     CHAR *photo_id;
   U16 description_len; WCHAR *description;
   U8 has_pic;
   U8 thumbnail_len;    WCHAR *thumbnail;   /**< local path or URL of the thumbnail                  */
   U8 pic_len;          WCHAR *pic;         /**< local path or URL of the full size photo            */
   U16 count;                               /**< number of photos in the same album                  */
   U16 pos;                                 /**< the position of this photo in the album             */
   U32 blob_size;                           /**< the size of the extension part of this struct       */
} srv_sns_photo_struct;

/**
 * time type for event
 * @see srv_sns_event_struct
 */
typedef struct srv_sns_time {
   S16 nYear;
   S8 nMonth;
   S8 nDay;
   S8 nHour;
   S8 nMin;
   S8 nSec;
   S8 DayIndex; /**< 0=Sunday */
} srv_sns_time_struct;

typedef struct srv_sns_alarm {
   srv_sns_time_struct first_launch;
   U8 type;                  
   U8 snooze;    
   U16 tone;         
} srv_sns_alarm_struct;

/**
 * node structure for singly-linked list of events
 * @see srv_sns_get_list_of_events
 */
typedef struct srv_sns_event {
   struct srv_sns_event *next;
   U32 provider;
   U8 event_id_len;  CHAR *event_id;
   U8 name_len;      WCHAR *name;
   U8 desc_len;      WCHAR *desc;
   U8 location_len;  WCHAR *location;
   srv_sns_time_struct start_time;                     
   srv_sns_time_struct end_time;
   srv_sns_event_type type; 
   srv_sns_alarm_struct alarm; 
   srv_sns_time_struct next_launch; 
   U16 index; 
} srv_sns_event_struct;

typedef struct srv_sns_event_search_weekly {
    srv_sns_time_struct date_time;
    U8 start_day_of_week;
} srv_sns_event_search_weekly_struct;

/**
 * see srv_sns_get_list_of_events
 */
typedef struct srv_sns_event_search_filter {
    srv_sns_event_search_type_enum type;
    union {
        srv_sns_event_search_weekly_struct weekly_search; /**< for WEEKLY */
        srv_sns_time_struct date_time;                    /**< for TIME/DAILY/MONTHLY/BEFORE */
        srv_sns_time_struct duration[2];                  /**< for DURATION */
    } u;
} srv_sns_event_search_filter_struct;

/**
 * internal struct for members
 * @see srv_sns_modify_group_member
 */
typedef struct srv_sns_member {
   U32 group_id;
   srv_sns_friend_struct *friends;
} srv_sns_member_struct;

/**
 * internal struct for members
 * @see srv_sns_modify_link_contact
 */
typedef struct srv_sns_link_contact {
   struct srv_sns_link_contact *next;
   U16 contact_id;
   srv_sns_friend_struct *friends;
} srv_sns_link_contact_struct;

/**
 * node structure for singly-linked list of groups
 * @see srv_sns_get_list_of_groups
 */
typedef struct srv_sns_group {
   struct srv_sns_group *next;
   U32 group_id;
   U8 name_len; WCHAR *name;
} srv_sns_group_struct;

/**
 * event structure for EVT_ID_SRV_SNS_READY
 */
typedef struct srv_sns_evt_ready {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   MMI_BOOL is_ready;
   S32 result;
} srv_sns_evt_ready_struct;

/**
 * event structure for EVT_ID_SRV_SNS_LIST_UPDATED
 */
typedef struct srv_sns_evt_list_updated {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 list_id;
   U16 total;
   U16 count;
   S16 start_index;
   S16 end_index;
   MMI_BOOL more;
   srv_sns_result result;
} srv_sns_evt_list_updated_struct;

/**
 * event structure for EVT_ID_SRV_SNS_LIST_INVALIDATED
 */
typedef struct srv_sns_evt_list_invalidated {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 list_id;
   srv_sns_list_invalidated_reason reason;
   U32 provider; // only for reason of LOGIN or LOGOUT
} srv_sns_evt_list_invalidated_struct;

/**
 * event structure for EVT_ID_SRV_SNS_ITEM_UPDATED
 */
typedef struct srv_sns_evt_item_updated {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 list_id;
   S16 index;
   srv_sns_pic_enum pic_type;
   srv_sns_pic_state pic_state;
   WCHAR *path;
   srv_sns_result result;
} srv_sns_evt_item_updated_struct;

/**
 * event structure for EVT_ID_SRV_SNS_ITEM_EXT_UPDATED
 */
typedef struct srv_sns_evt_item_ext_updated {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 list_id;
   S16 index;
   srv_sns_object_enum type;
   CHAR obj_id[SRV_SNS_MAX_LEN_ID];
   S32 result;
} srv_sns_evt_item_ext_updated_struct;

/**
 * event structure for EVT_ID_SRV_SNS_COUNTS_UPDATED
 */
typedef struct srv_sns_evt_counts_updated {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   U8 messages;
   U8 notifications;
   U8 requests;
} srv_sns_evt_counts_updated_struct;

/**
 * event structure for EVT_ID_SRV_SNS_RESULT
 */
typedef struct srv_sns_evt_result {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   srv_sns_result result;
} srv_sns_evt_result_struct;

/**
 * event structure for EVT_ID_SRV_SNS_PROCESS_START
 */
typedef struct srv_sns_evt_process_start {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 process_id;
   srv_sns_bkgd_process_type type;
} srv_sns_evt_process_start_struct;

/**
 * event structure for EVT_ID_SRV_SNS_PROCESS_COMPLETE
 */
typedef struct srv_sns_evt_process_complete {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 process_id;
   srv_sns_bkgd_process_type type;
   U8 success;
   U8 failure;
   U32 providers[SRV_SNS_MAX_NUM_PROVIDERS];
   S32 results[SRV_SNS_MAX_NUM_PROVIDERS];
} srv_sns_evt_process_complete_struct;

/**
 * event structure for EVT_ID_SRV_SNS_NET_FETCH_LIST_START & EVT_ID_SRV_SNS_NET_FETCH_LIST_END
 */
typedef struct srv_sns_evt_net_fetch {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   S32 list_id;
   U8 list_type;
} srv_sns_evt_net_fetch_struct;

/**
 * event structure for EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT
 */
typedef struct srv_sns_evt_account_logged_out {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   U32 provider;
   srv_sns_log_out_type type;
} srv_sns_evt_account_logged_out_struct;

/**
 * event structure for EVT_ID_SRV_SNS_PLUGIN_TO_LOAD
 */
typedef struct srv_sns_evt_plugin_to_load {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
   U32 provider;
} srv_sns_evt_plugin_to_load_struct;

/**
 * event structure for EVT_ID_SRV_SNS_PLUGINS_UNLOADED
 */
typedef struct srv_sns_evt_plugins_unloaded {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   srv_sns_result result;
} srv_sns_evt_plugins_unloaded_struct;

/**
 * event structure for EVT_ID_SRV_SNS_PLUGINS_UPGRADED
 */
typedef struct srv_sns_evt_plugins_upgraded {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
   MMI_EVT_PARAM_HEADER
#endif /* DOXYGEN_SHOULD_SKIP_THIS */      
   MMI_BOOL is_successful;
} srv_sns_evt_plugins_upgraded_struct;

#endif
