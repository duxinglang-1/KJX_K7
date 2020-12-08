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

/*******************************************************************************
 * Filename:
 * ---------
 * ImpsSrvGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local contant, structure, enum, and function prototypes for
 * IMPS service.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __IMPS_SRV_GPROT_H__
#define __IMPS_SRV_GPROT_H__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"

#include "mmi2imps_struct.h"

/* define the maximum number of contact list */
#define SRV_IMPS_MAX_CONTACT_LIST_COUNT     (5)

/* define the maximum number of contact, one for myself */
#define SRV_IMPS_MAX_CONT_COUNT             (50 + 1)  

/* define the maximum number of chat room */
#define SRV_IMPS_MAX_ROOM_COUNT             (10)

/* define the index of myself in contact information */
#define SRV_IMPS_MYSELF_INDEX               (10000)

/* define the index of on-line contact list for sort type is status */
#define SRV_IMPS_CONT_INDEX_ONLINE          (1)

/* define the index of off-line contact list for sort type is status */
#define SRV_IMPS_CONT_INDEX_OFFLINE         (2)

/* maximum buffer length to store my picture */
#define SRV_IMPS_MAX_PIC_PATH_LEN           (60)

/* maximum number of pend message */
#define SRV_IMPS_MAX_PEND_MSG_COUNT         (10)

/* enumerate events used between app and service */
typedef enum
{
    SRV_IMPS_EVENT_IDLE = 0,

    SRV_IMPS_EVENT_SET_DATA_ACCOUNT, /* service need use data account to judge whether 
                                        it is ok for login */

    SRV_IMPS_EVENT_LOGIN,
    SRV_IMPS_EVENT_ABORT_LOGIN,
    SRV_IMPS_EVENT_LOGOUT,
    SRV_IMPS_EVENT_SEARCH_CONT,             /* 5 */
    SRV_IMPS_EVENT_SEARCH_GROUP,
    SRV_IMPS_EVENT_ABORT_SEARCH,
    SRV_IMPS_EVENT_INVITE_GROUP,
    SRV_IMPS_EVENT_INVITE_PRESENCE,
    SRV_IMPS_EVENT_INVITE_REPLY,            /* 10 */
    SRV_IMPS_EVENT_EXT_CONV,

    SRV_IMPS_EVENT_SEND_MESSAGE,
    SRV_IMPS_EVENT_GET_MESSAGE,
    SRV_IMPS_EVENT_REJECT_MESSAGE,
    SRV_IMPS_EVENT_FORWARD_MESSAGE,         /* 15 */   
    SRV_IMPS_EVENT_GET_BLOCK_LIST,
    SRV_IMPS_EVENT_BLOCK_ENTITY,
    
    SRV_IMPS_EVENT_CREATE_GROUP,
    SRV_IMPS_EVENT_JOIN_GROUP,
    SRV_IMPS_EVENT_DELETE_GROUP,            /* 20 */
    SRV_IMPS_EVENT_LEAVE_GROUP,
    SRV_IMPS_EVENT_GET_GROUP_MEMBER,
    SRV_IMPS_EVENT_GET_JOINED_USER,
    SRV_IMPS_EVENT_GET_REJECTED_USER,
    SRV_IMPS_EVENT_ADD_GROUP_MEMBER,        /* 25 */
    SRV_IMPS_EVENT_REMOVE_GROUP_MEMBER,
    SRV_IMPS_EVENT_CHANGE_MEMBER_ACCESS,
    SRV_IMPS_EVENT_REJECT_GROUP_USER,
    SRV_IMPS_EVENT_REMOVE_REJECT_GROUP_USER,
    SRV_IMPS_EVENT_ABORT_GET_JOINED_USER,   /* 30 */
    SRV_IMPS_EVENT_ABORT_GET_GROUP_MEMBER,
    SRV_IMPS_EVENT_ABORT_GET_REJECTED_USER,

    SRV_IMPS_EVENT_ADD_CONTACT_LIST,
    SRV_IMPS_EVENT_EDIT_CONTACT_LIST,
    SRV_IMPS_EVENT_DEL_CONTACT_LIST,        /* 35 */
    SRV_IMPS_EVENT_VIEW_CONTACT_LIST,
    SRV_IMPS_EVENT_ADD_CONTACT,
    SRV_IMPS_EVENT_ADD_CONTACT_INVITE_PR, /* for add contact, service will send invite pr to contact */
    SRV_IMPS_EVENT_EDIT_CONTACT,          
    SRV_IMPS_EVENT_DEL_CONTACT,             /* 40 */
    SRV_IMPS_EVENT_MOVE_CONTACT,
    SRV_IMPS_EVENT_SUBS_PA,	
    SRV_IMPS_EVENT_GET_MY_PA,
    SRV_IMPS_EVENT_GET_CONTACT_PA,
    SRV_IMPS_EVENT_ABORT_GET_CONTACT_PA,    /* 45 */
    SRV_IMPS_EVENT_GET_ALL_CONTACT_PA,
    SRV_IMPS_EVENT_SUBS_ALL_CONTACT_PA,
    SRV_IMPS_EVENT_UPDATE_PA,
	SRV_IMPS_EVENT_UPDATE_STATUS,
	SRV_IMPS_EVENT_UPDATE_ALIAS,            /* 50 */
    SRV_IMPS_EVENT_GET_MY_PP,
    SRV_IMPS_EVENT_GET_CONT_PP,
    SRV_IMPS_EVENT_GET_STRANGER_PP,
    SRV_IMPS_EVENT_ABORT_GET_PP,
    SRV_IMPS_EVENT_UPDATE_PP,               /* 55 */
    SRV_IMPS_EVENT_PA_AUTH_USER,    
    SRV_IMPS_EVENT_GET_WATCHER_LIST,
    SRV_IMPS_EVENT_ABORT_GET_WATCHER_LIST,
	SRV_IMPS_EVENT_CREATE_ATTRIBUTE_LIST,

    SRV_IMPS_EVENT_HTTP_AUTH_RES,           /* 60 */
    SRV_IMPS_EVENT_SYSTEM_MSG_USER,
    SRV_IMPS_EVENT_SUBS_NOTIFY,
    SRV_IMPS_EVENT_UNSUBS_NOTIFY,    
    SRV_IMPS_EVENT_DL_FILE,
    
    SRV_IMPS_EVENT_LOGIN_READY_IND,  /* related with app data account */

    /* begin of indication, these indication will notify all registered app */
    SRV_IMPS_EVENT_IND_BEGIN,               /* 66 */
    SRV_IMPS_EVENT_LOGIN_PROGRESS_IND = SRV_IMPS_EVENT_IND_BEGIN,	/* 66 */
    SRV_IMPS_EVENT_SERVICE_CAPABILITY_IND,    
    SRV_IMPS_EVENT_CONT_LIST_UPDATE_IND,  /* contact list changed */
    SRV_IMPS_EVENT_CONT_INFO_UPDATE_IND,
    SRV_IMPS_EVENT_CONT_INFO_UPDATE_DONE_IND,
    SRV_IMPS_EVENT_CONT_INFO_SUBS_DONE_IND,     /* 71 */
    SRV_IMPS_EVENT_DISCONNECT_IND,
    SRV_IMPS_EVENT_INVITE_IND,
    SRV_IMPS_EVENT_INVITE_RESPONSE_IND,
    SRV_IMPS_EVENT_INVITE_EC_IND, /* for 1-1 chat, contact has invite others join, 
                                     app need clear unread message flag in contact list */
    SRV_IMPS_EVENT_EXT_CONV_IND,                /* 76 */
    SRV_IMPS_EVENT_NEWMESSAGE_IND,
    SRV_IMPS_EVENT_MESSAGENOTIFY_IND,
    SRV_IMPS_EVENT_OFFLINE_MESSAGE_IND,
    SRV_IMPS_EVENT_GROUP_CHANGE_NOTIFY_IND,
    SRV_IMPS_EVENT_LEAVE_GROUP_IND,             /* 81 */
    SRV_IMPS_EVENT_SYSTEM_MSG_IND,
    SRV_IMPS_EVENT_PA_NOTIFY_IND,
    SRV_IMPS_EVENT_PA_AUTH_IND,
    SRV_IMPS_EVENT_NOTIFY_REQUEST_IND,
    SRV_IMPS_EVENT_HTTP_AUTH_IND,               /* 86 */
    SRV_IMPS_EVENT_IND_END,
    /* end of indication */

    SRV_IMPS_EVENT_END_OF_ENUM
} srv_imps_event_enum;

/* enumerate the event result that service handle */
typedef enum
{
    SRV_IMPS_RESULT_OK = 0,
    SRV_IMPS_RESULT_INVALID_PARAMETERS = -1,
    SRV_IMPS_RESULT_ERROR = -2,
    SRV_IMPS_RESULT_BUSY = -3,
    SRV_IMPS_RESULT_NOT_LOGIN = -4,
    SRV_IMPS_RESULT_LOGIN_BY_OTHER = -5,
	SRV_IMPS_RESULT_SERVER_DISCONN = -6,
    SRV_IMPS_RESULT_CONTACT_LIST_FULL = -7,
    SRV_IMPS_RESULT_CONTACT_FULL = -8,
    SRV_IMPS_RESULT_ROOM_FULL = -9,
    SRV_IMPS_RESULT_CONTACT_EXIST = -10,

    SRV_IMPS_RESULT_END_OF_ENUM
} srv_imps_result_enum;

/* Enumerate IMPS service process status */
typedef enum
{
    SRV_IMPS_STATUS_IDLE = 0,
    SRV_IMPS_STATUS_INIT,               /* initialized */    
    SRV_IMPS_STATUS_LOGING_IN,          /* loging in */
    SRV_IMPS_STATUS_ABORTING_LOGIN,     /* aborting login */
    SRV_IMPS_STATUS_LOGIN,              /* already login */
    SRV_IMPS_STATUS_SYNCING_CONT_LIST,  /* syncing contact list from server */
    SRV_IMPS_STATUS_SYNCING_CONT,       /* syncing contact from server */    
    SRV_IMPS_STATUS_UPDATE_INFO,        /* already update information from server */
	SRV_IMPS_STATUS_LOGING_OUT,         /* loging out */
    SRV_IMPS_STATUS_END_OF_ENUM
} srv_imps_status_enum;

/* Enumerate file type, service save event response result in file, app use file 
   type to get file name and delete this file after finish used */
typedef enum
{    
    SRV_IMPS_GROUP_ENTITY_MEMBER,
    SRV_IMPS_GROUP_ENTITY_JOINED_USER,
    SRV_IMPS_GROUP_ENTITY_REJECTED_USER,    
    SRV_IMPS_GROUP_ENTITY_END_OF_ENUM
} srv_imps_group_entity_type_enum;

/* Enumerate message type used in send message request */
typedef enum
{
    SRV_IMPS_SEND_MSG_TYPE_TEXT = 0,
    SRV_IMPS_SEND_MSG_TYPE_FILE = TRUE,
    SRV_IMPS_SEND_MSG_TYPE_TEMP_FILE = IMPS_CONTENT_STORE_TEMP_FILE,
    SRV_IMPS_SEND_MSG_TYPE_END_OF_ENUM
} srv_imps_send_msg_type_enum;

/* Enumerate type of chat room */
typedef enum
{
    SRV_IMPS_ROOM_TYPE_SINGLE = 0,      /* single talk */
    SRV_IMPS_ROOM_TYPE_GROUP_CREATE,    /* a created group */
    SRV_IMPS_ROOM_TYPE_GROUP_JOIN       /* a joined group */
} srv_imps_room_type_enum;

/* Enumerate type of contact sort */
typedef enum
{    
    SRV_IMPS_CONT_SORT_BY_STATUS,
    SRV_IMPS_CONT_SORT_BY_NAME, 
    SRV_IMPS_CONT_SORT_TYPE_END_OF_ENUM
} srv_imps_cont_sort_type_enum;

/* Enumerate contact presence status */
typedef enum
{
    SRV_IMPS_PA_USER_UNKNOWN = 0,       /* refreshed state */
    SRV_IMPS_PA_USER_OFFLINE,           /* off-line */
    SRV_IMPS_PA_USER_AVAILABLE,         /* on-line */
    SRV_IMPS_PA_USER_DISCREET,          /* busy */
    SRV_IMPS_PA_USER_NOT_AVAILABLE,     /* away */
    SRV_IMPS_PA_USER_STATUS_END_OF_ENUM
} srv_imps_pa_user_status_enum;

typedef enum
{
    SRV_IMPS_GROUP_CHANGE_JOINED_USER,
    SRV_IMPS_GROUP_CHANGE_LEFT_USER,    
    SRV_IMPS_GROUP_CHANGE_JOINED_BLOCK_USER,
    SRV_IMPS_GROUP_CHANGE_LEFT_BLOCK_USER,
    SRV_IMPS_GROUP_CHANGE_TYPE_END_OF_ENUM
} srv_imps_group_change_type_enum;

/* data structure of a contact */
typedef struct
{
    CHAR id[IMPS_MAX_ID_LEN];                       /* contact id */    
    U32 index;                                      /* the index of contact */
    U32 cont_list_index;                            /* contact list id that the contact belonged */ 
    WCHAR nick_name[IMPS_MAX_NAME_LEN];             /* nick name */
    WCHAR alias[IMPS_MAX_NAME_LEN];                 /* alias */
    WCHAR prof_text[IMPS_MAX_PA_STATUS_TEXT_LEN];   /* text profile */    
    U8 availability;                                /* availability */    
    U8 online_status;                               /* on-line status */
    U8 mood;                                        /* mood */ 
    U8 device_type;                                 /* device type */
    MMI_BOOL is_blocked;                            /* whether the contact is blocked */
    MMI_BOOL pa_ready;                              /* whether presence updated from server */ 
    imps_accepted_content_type_list_info_struct content_type; /* mime type supported */
} srv_imps_contact_struct;

/* structure of a contact list */
typedef struct
{
    CHAR id[IMPS_MAX_ID_LEN];                        /* contact_list id */
    U32 index;                                      /* the index of contact list, 0 is reserved */
    WCHAR name[IMPS_MAX_NAME_LEN];                  /* contact list name */    
    S32 no_users;                                   /* number of users in the contact list */
    MMI_BOOL open_status;                           /* opened/hidden state of on-line status */
    MMI_BOOL open_text;                             /* opened/hidden state of text */
    MMI_BOOL open_mood;                             /* opened/hidden state of mood */
    MMI_BOOL open_pic;                              /* opened/hidden state of status content */
    MMI_BOOL open_alias;                            /* opened/hidden state of alias */       
} srv_imps_contact_list_struct;

/* structure for a chat room */
typedef struct
{
    CHAR  room_id[IMPS_MAX_ID_LEN];                 /* room id, for single chat, it's contact id */
    WCHAR room_name[IMPS_MAX_NAME_LEN];             /* name of the chat room */
    WCHAR room_topic[IMPS_MAX_NAME_LEN];            /* topic of the chat room */
    WCHAR welcome[IMPS_MAX_NOTE_LEN];               /* welcome text of the chat room */
    WCHAR sname[IMPS_MAX_NAME_LEN];                 /* screen name of the user in the chat room */    	
    srv_imps_room_type_enum type;                   /* type of chat room (single talk or chat) */    
    U8 pri_level;                                   /* privilege level of the user */    
    MMI_BOOL is_inviting;
} srv_imps_room_prop_struct;

/* structure for message information stored in file */
typedef struct
{
    WCHAR sender_id[IMPS_MAX_ID_LEN];               /* sender, it maybe use nickname, alias or id*/
    MYTIME msg_time;                                /* the time send message or receive message */ 
    WCHAR *content;                                 /* message content */
} srv_imps_message_struct;

/* structure for contact presence */
typedef struct
{    
    WCHAR alias[IMPS_MAX_NAME_LEN];                     /* alias */
    WCHAR status_text[IMPS_MAX_PA_STATUS_TEXT_LEN];     /* text of profile */    
    U8 online_status;                                   /* status of user */    
    U8 availability;                                    /* availability */
    U8 mood;                                            /* mood of user */   
    U8 device_type;                                     /* device type */
} srv_imps_presence_struct;

/* Structure of public profile */
typedef struct
{    
    CHAR  country_code[3];                              /* country code:ISO3166-1*/
    S32   gender;                                       /* Gender */ 
    S32   marital_status;                               /* Marital status */
    WCHAR city[IMPS_MAX_CITY_NAME_LEN];                 /* City */
    WCHAR free_text[IMPS_MAX_FREE_TEXT_LEN];            /* Free text */
    WCHAR intention[IMPS_MAX_INTENTION_LEN];            /* Intention */
    WCHAR hobbies[IMPS_MAX_HOBBY_LEN];                  /* Hobbies */
    WCHAR fname[IMPS_MAX_FRIENDLY_NAME_LEN];            /* Friendly name */      
    WCHAR year_buff[5];                                   /* year buffer */
    WCHAR month_buff[3];                                   /* month buffer */
    WCHAR day_buff[3];                                     /* day buffer */
} srv_imps_public_profile_struct;

/* structure of login request, it is for SRV_IMPS_EVENT_LOGIN */
typedef struct
{   
    CHAR *server;                  /* address of server */
    CHAR *username;                /* user name */
    CHAR *passwd;                  /* password */
    U8 proxy_ip[4];                /* address of proxy server */
    U16 proxy_port;                /* port number */
    CHAR *proxy_username;          /* username */
    CHAR *proxy_passwd;            /* password */
    CHAR *auth_usrn;               /* http auth username */
    CHAR *auth_pwd;                /* http auth password */
    U8 conn_type;                  /* WAP or HTTP */
    U32 dt_acct;                   /* data account */
    MMI_BOOL use_proxy;            /* use proxy or not */
    U8 login_mode;                 /* normal or security */
    U32 timeout;                   /* the value of timeout */
} srv_imps_login_req_struct;

typedef struct 
{
    S32 result;                              /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;              /* detail description for fail reason*/
    CHAR *imps_usrn;
    CHAR *imps_pwd;
} srv_imps_login_rsp_struct;

/* structure of login response, it is for SRV_IMPS_EVENT_LOGIN */
typedef struct 
{
    S32 result;                              /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;              /* detail description for fail reason*/
    imps_not_agreed_services_struct *not_agreed_serv; 
    imps_csp_version_enum imps_version;
    MMI_BOOL not_agreed_all;
} srv_imps_service_capability_ind_struct;

/* structure for disconnect indication, it is for SRV_IMPS_EVENT_DISCONNECT_IND */
typedef struct 
{
    S32 result;                              /* response result value, refer to imps_result_error_enum */
    CHAR *disconnect_reason;
} srv_imps_disconnect_ind_struct;

/* structure for invite group request, it is for SRV_IMPS_EVENT_INVITE */
typedef struct 
{    
    U32 cont_index;
    U32 room_index;                         /* the room index for invite */
    WCHAR *invite_note;                     /* text note for invitation */ 
    WCHAR *sname;
} srv_imps_invite_group_req_struct;

/* structure for invite group response, it is for SRV_IMPS_EVENT_INVITE */
typedef struct 
{    
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/  
    U32 room_index;                         /* the room index for invite */
    WCHAR recipient_id[IMPS_MAX_ID_LEN];
} srv_imps_invite_group_rsp_struct;

/* struct for invite presence request */
typedef struct 
{    
    imps_sender_struct *recipient;          /* the user who receive invitation */   
    WCHAR *invite_note;                     /* text note for invitation */ 
} srv_imps_invite_presence_req_struct;

/* struct for invite response indication */
typedef struct 
{    
    S32 result;
    imps_detail_struct *detail;             /* detail description for fail reason*/
    imps_entity_struct *sender;    
    WCHAR *response_note;
    MMI_BOOL acceptance;
    U32 room_index;
    WCHAR recipient_id[IMPS_MAX_ID_LEN];
} srv_imps_invite_response_ind_struct;

/* struct for invite reply request */
typedef struct
{
    MMI_BOOL acceptance;                    /* indicate whether user accept the invitation */    
    WCHAR *self_sname;                      /* screen name */    
} srv_imps_invite_reply_req_struct;

/* struct for invite reply response */
typedef struct 
{
    S32 result;                              /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;              /* detail description for fail reason*/
    MMI_BOOL acceptance;
    U32 room_index;
    imps_entity_list_info_struct *joined_users_list;    
    WCHAR *welcome_text;
} srv_imps_invite_reply_rsp_struct;

/* struct for extend conversation request */
typedef srv_imps_invite_group_req_struct srv_imps_ext_conv_req_struct;
/* struct for extend conversation response */
typedef srv_imps_invite_group_rsp_struct srv_imps_ext_conv_rsp_struct;

/* struct for extend conversation indication */
typedef struct
{
    S32 result;                              /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;              /* detail description for fail reason*/
    U32 room_index;    
    WCHAR *response_note;
    WCHAR *recipient_id;
} srv_imps_ext_conv_ind_struct;

/* struct for search contact request */
typedef struct 
{    
    U8 search_limit;                      /* the maximum number of search */
    S32 gender;                           /* Gender */
    S32 user_onlinestatus;                /* User on-line status */
    S32 marital_status;                   /* Marital status */    
    WCHAR *user_alias;                    /* User alias */
    WCHAR *user_emailaddr;                /* User email address */
    WCHAR *user_firstname;                /* User first name */
    WCHAR *user_id;                       /* User ID */
    WCHAR *user_lastname;                 /* User last name */
    WCHAR *user_mobile_number;            /* User mobile number */
    WCHAR user_max_age[3];                /* Maximum of user's age. [v13] */
    WCHAR user_min_age[3];                /* Minimum of user's age */
    WCHAR *fname;                         /* Friendly name */
    WCHAR *city;                          /* City */    
    WCHAR *intention;                     /* Intention */
    WCHAR *hobbies;                       /* Hobbies */
    WCHAR country_code[3];                /* country code, ISO3166-1*/    
} srv_imps_search_cont_req_struct;

/* struct for search group request */
typedef struct 
{    
    U8 search_limit;                        /* the maximum number of search */
    WCHAR *group_id;                        /* Indicate the group */
    WCHAR *group_name;                      /* group name */
    WCHAR *group_topic;                     /* group topic */
    WCHAR *group_joined;                    /* the id of user joined the group */
    WCHAR *group_owner;                     /* the id of user who is the owner of group */
    WCHAR *group_autojoin;                  /* the id of user who is auto joined */
} srv_imps_search_group_req_struct;

/* struct for search response */
typedef struct 
{
    S32 result;                         /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;         /* detail description for fail reason*/
    U8 search_count;                    /* the count of search result */    
} srv_imps_search_rsp_struct;

typedef struct
{
    U8 notify_type;                     /* notify type */
    WCHAR *content;                     /* off-line content */
} srv_imps_offline_message_ind_struct;

/* struct for new message indication */
typedef struct
{    
    S32 result;
    imps_detail_struct *detail;
    U32 room_index;
    imps_message_info_struct *message_info;     /* message information */
    U8 use_file;                                /* if message data saved in file */
    WCHAR *message_content;                     /* message data */
} srv_imps_newmessage_ind_struct;

/* struct for get message request */
typedef struct
{    
    S32 app_hd;
    CHAR *id;                                     /* identifier of message to get */
} srv_imps_get_message_req_struct;

/* request struct for rejecting message */
typedef srv_imps_get_message_req_struct srv_imps_reject_message_req_struct;

/* response struct for get message */
typedef srv_imps_newmessage_ind_struct srv_imps_get_message_rsp_struct;

/* request struct for forwarding message */
typedef struct 
{
    CHAR *message_id;    
    imps_entity_struct *recipient;
} srv_imps_forward_message_req_struct;

/* response struct for forward message */
typedef struct
{
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/    
    CHAR *message_id;
} srv_imps_forward_message_rsp_struct;

typedef struct
{    
    U32 room_index;                         /* identifier the message */
    MMI_BOOL delivery_report_require;       /* indicate whether need report */
    MMI_BOOL is_font_p;                     /* indicate whether it need to specify font */
    imps_font_struct *font;                 /* font information */
    U8 send_msg_type;        
    WCHAR *recipient_sname;                 /* it used for private chat in group */
    WCHAR *message_content;                 /* the content of instant message */
    WCHAR *orig_path;                       /* for file resized case, record file original path before resized */
} srv_imps_send_message_req_struct;

/* response struct for sending message */
typedef struct 
{
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/
    U32 room_index;
    WCHAR *message_content;
} srv_imps_send_message_rsp_struct;

/* request struct for block entity */
typedef struct 
{    
    U32 cont_index;
    MMI_BOOL is_block;
} srv_imps_block_entity_req_struct;


typedef struct
{        
    WCHAR *sname;
    U8  access_type;    
    U8  searchable;    
    WCHAR  *name;
    WCHAR  *topic;
    WCHAR  *welcome_note;    
} srv_imps_create_group_req_struct;

typedef struct  
{
    S32 result;                         /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;         /* detail description for fail reason*/
    U32 room_index;
} srv_imps_create_group_rsp_struct;

/* struct for join group request */
typedef struct
{    
    MMI_BOOL user_show_id;       
    CHAR *group_id;
    WCHAR *sname; 
} srv_imps_join_group_req_struct;

/* response struct for joining group */
typedef struct 
{
    S32 result;                         /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;         /* detail description for fail reason*/
    U32 room_index;
    imps_entity_list_info_struct *joined_users_list;    
    WCHAR *welcome_text;
} srv_imps_join_group_rsp_struct;

/* struct for indication that group is closed */
typedef struct
{
    S32 result;                         /* response result value, refer to imps_result_error_enum */ 
    imps_detail_struct detail;          /* detail description for fail reason*/   
    CHAR leave_reason[IMPS_MAX_NOTE_LEN];
    U32 room_index;    
} srv_imps_leave_group_ind_struct;

/* struct for indication that group properties changed */
typedef struct
{
    U32 room_index;
    imps_entity_list_info_struct *joined_user_list;    
    imps_entity_list_info_struct  *left_user_list; 
    imps_entity_list_info_struct *joined_blocked_user_list;
    imps_entity_list_info_struct  *left_blocked_user_list; 
} srv_imps_group_change_notify_ind_struct;

typedef struct
{    
    WCHAR *name;     
    imps_entity_list_struct *user_nick_list;    
    MMI_BOOL authorize_pa_p;
    U32 authorize_pa;    
} srv_imps_add_contact_list_req_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    U32 contact_list_index;                 /* indicate the contact list */
    MMI_BOOL display_name_p;                /* indicate whether there is group name */
    WCHAR *display_name;                    /* text of group name */        
    MMI_BOOL authorize_pa_p;                /* indicate whether use authorization */
    U32 authorize_pa;                       /* indicate the value of authorization */    
} srv_imps_edit_contact_list_req_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    S32 result;
    CHAR contact_list_id[IMPS_MAX_ID_LEN];    /* indicate the contact list */
} srv_imps_cont_update_ind_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    S32 result;
    U32 cont_list_index;                    /* indicate the contact list, 0 is for all contact list */
} srv_imps_cont_list_update_ind_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    U32 cont_list_index;                    /* indicate the contact list */
    CHAR *cont_id;
    WCHAR *nick_name;    
} srv_imps_add_contact_req_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/
    U32 index;
} srv_imps_add_contact_rsp_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/
    MMI_BOOL acceptance;
    WCHAR recipient_id[IMPS_MAX_ID_LEN];
} srv_imps_add_contact_invite_pr_struct;


/* request struct for MMI to edit contact list information */
typedef struct
{    
    U32 cont_index;
    WCHAR *nick_name;    
} srv_imps_edit_contact_req_struct;

/* request struct for deleting contact */
typedef struct
{
    U32 contact_list_index;                 /* indicate the contact list */
    imps_entity_list_struct *user_nick_list;
} srv_imps_del_contact_req_struct;

/* request struct for MMI to edit contact list information */
typedef struct
{
    U32 to_cont_list_index;                 /* indicate the contact list of contact moved to */
    U32 cont_index;    
} srv_imps_move_contact_req_struct;

/* request struct for subscribing presence */
typedef struct
{
    imps_subscribe_entity_list_struct id_list;  /* the list of users for subscribing presence */
    U32 subscribe_pa;                           /* the value of presence to be subscribed */
} srv_imps_subs_pa_req_struct;

/* request struct for getting users presence */
typedef struct
{
    U8 online_status_qualifier;         /* online status qualifier */
    U8 online_status;                   /* online status value */
    U8 user_availability_qualifier;     /* availability qualifier */
    U8 user_availability;               /* availability value */
    U8 alias_qualifier;
    WCHAR *alias;
    MMI_BOOL is_pic_changed;
    WCHAR *pic_file_name;
    U8 status_text_qualifier;           /* status text qualifier */
    WCHAR *status_text;                 /* status text value */
    U8 status_mood_qualifier;           /* mood qualifier */
    U8 status_mood;                     /* mood value */    
} srv_imps_update_pa_req_struct;

/* request struct for getting users presence */
typedef struct
{
    imps_get_pa_entity_list_struct *user_id_list;       /* list of users */
    U32 attr_list;      /* list of presence attributes. An empty or missing list
                           indicates all available presence attributes are desired */
} srv_imps_get_pa_req_struct;

/* request struct for creating attribute list */
typedef struct
{
    MMI_BOOL is_default;                    /* indicate whether it is used as default attribute list */
    U32 attr_list;                          /* the value of attribute list */
    imps_entity_list_struct *user_id_list;  /* list of users whom attribute value is for */
} srv_imps_create_attribute_list_req_struct;

typedef struct
{
    S32 result;                             /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;             /* detail description for fail reason*/
    srv_imps_presence_struct pa;
} srv_imps_get_contact_pa_rsp_struct;

/* request struct for MMI to get watcher list */
typedef struct
{
    MMI_BOOL history_period_p;      /* Indicates whether the hisory period is used or not */
    U32 history_period;             /* Indicates the time period in seconds on the 
                                       longest possible history of the watcher (from 
                                       the time of request) that SHOULD be returned.
                                       In case of absence, it indicates the user request
                                       the watcher list at the time of the request only.
                                       The value 0 MUST NOT be used. */
    MMI_BOOL max_watcher_list_p;    /* Indicates whether the maximum watcher list is used or not */
    U32 max_watcher_list;           /*Indicates the maximum number of Watcher elements in response*/
} srv_imps_get_watcher_list_req_struct;

/* struct for getting watch list response */
typedef struct
{
    S32 result;
    imps_detail_struct *detail;     /* detail description for fail reason*/   
    MMI_BOOL history_period_p;      /* Indicate whether use history period */
    U32 history_period;
    U32 count;
} srv_imps_get_watcher_list_rsp_struct;

/* struct for presence authorization */
typedef struct
{
    MMI_BOOL is_accept;
    CHAR *user_id;
} srv_imps_presence_auth_user_struct;

/* struct for presence authorization indication */
typedef struct
{
	imps_entity_list_struct* id_list; 
    U32 attr_list;
    MMI_BOOL is_default;            /* indicate whether it is used as default attribute list */
} srv_imps_create_attributelist_req_struct;

/* response struct for retrieving group member list of specific group */
typedef struct 
{
    S32 result;                     /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;     /* detail description for fail reason*/   
    U32 adm_num;
    U32 mod_num;
    U32 user_num;    
} srv_imps_get_group_member_rsp_struct;

/* response struct for retrieving joined user list of specific group */
typedef struct
{
    S32 result;                     /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;     /* detail description for fail reason*/   
    U32 adm_num;
    U32 mod_num;
    U32 user_num;
    U32 blocked_num;
} srv_imps_get_joined_user_rsp_struct;

/* response struct for retrieving joined user list of specific group */
typedef struct
{
    S32 result;                     /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;     /* detail description for fail reason*/   
    U32 user_num;    
} srv_imps_get_rejected_user_rsp_struct;

/* request struct for adding member to specific group */
typedef struct
{
    U32 room_index;
    CHAR *user_id;    
} srv_imps_add_group_member_req_struct;

/* request struct for removing member from specific group */
typedef struct
{
    U32 room_index;
    U32 entity_member_index;
} srv_imps_remove_group_member_req_struct;

/* request struct for change group user privilege */
typedef struct
{
    U32 room_index;
    imps_pri_level_enum pri_level;       /* Indicate the privilege level of users */
    U32 entity_member_index;
} srv_imps_member_access_req_struct;

/* request struct for modifying group rejected user list, it may add user to rejected user list 
   or delete user from rejected user list */
typedef struct
{
    U32 room_index;
    MMI_BOOL is_add;                     /* Indicate whether add user to rejected list or not */
    U32 entity_member_index;
} srv_imps_reject_group_user_req_struct;

/* response struct for modifying group rejected user list, it may add user to rejected user list 
   or delete user from rejected user list */
typedef struct 
{
    S32 result;                          /* response result value, refer to imps_result_error_enum */
    imps_detail_struct detail;          /* detail description for fail reason*/   
    imps_entity_list_info_struct user_list;   
} srv_imps_reject_group_user_rsp_struct;

/* request struct for user to reply system message */
typedef struct 
{    
    U32 chosen_option;                          /* Indicate the option value of user choose */
    WCHAR verification_key[IMPS_MAX_URL_LEN];   /* Text string provided by the user in response to the notification */ 
} srv_imps_system_message_user_req_struct;

/* response struct for user to reply system message */
typedef struct 
{
    S32 result;                           /* response result value, refer to imps_result_error_enum */
    imps_detail_struct detail;            /* detail description for fail reason*/   
    CHAR  sm_id[IMPS_MAX_SM_ID_LEN];      /* Indicate the id of system message that user reply */
} srv_imps_system_message_user_rsp_struct;

/* notification indication struct when user subscribed event occur */
typedef struct
{
    imps_notification_type_enum notif_type;         /* Indicate the type of notification */
    imps_notification_element_union notif_element;  /* Indicate the value of event notification */
} srv_imps_notify_ind_struct;

/* response struct for MMI to get user's public profile */
typedef struct
{/*size:1013 bytes*/
    S32 result;                                 /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;                 /* detail description for fail reason*/
    srv_imps_public_profile_struct user_pp;     /* The public profiles value for specific user */
} srv_imps_get_pp_rsp_struct;

/* request struct for MMI to update public profile */
typedef struct
{
    MMI_BOOL    clear_pp;               /* Indicates whether the public profile is cleared or not */
    MMI_BOOL    user_pp_p;              /* Indicates whether the user_pp is used or not */ 
    imps_public_profile_struct user_pp; /* The public profile fields to be updated for the requesting user */
} srv_imps_update_pp_req_struct;

/* to download file from specific URL, MMI task send request to IMPS task */
typedef struct
{
    CHAR  content_url[IMPS_MAX_URL_LEN];        /* URL address for downloading file */
    WCHAR store_path[IMPS_MAX_FILE_PATH_LEN];   /* path for storing file downloaded */  
} srv_imps_dl_file_req_struct;

/* structure for replying http authorization indication */
typedef struct
{
    WCHAR *username;     
    WCHAR *password;   
} srv_imps_http_auth_res_struct;

/* response result struct */
typedef struct 
{
    S32 result;                         /* response result value, refer to imps_result_error_enum */
    imps_detail_struct *detail;         /* detail description for fail reason*/   
} srv_imps_rsp_result_struct;

/* response struct for MMI task to download file from specific URL */
typedef srv_imps_rsp_result_struct srv_imps_dl_file_rsp_struct;

/* response struct for MMI to update public profile */
typedef srv_imps_rsp_result_struct srv_imps_update_pp_rsp_struct;

/* response struct for MMI to unsubscribe some notification from server */
typedef srv_imps_rsp_result_struct srv_imps_unsubs_notify_rsp_struct;

/* response struct for MMI to subscribe some event notification from server */
typedef srv_imps_rsp_result_struct srv_imps_subs_notify_rsp_struct;

/* response struct for modifying group user privilege */
typedef srv_imps_rsp_result_struct srv_imps_member_access_rsp_struct;

/* response struct for removing member from specific group */
typedef srv_imps_rsp_result_struct srv_imps_remove_group_member_rsp_struct;

/* response struct for adding member to specific group */
typedef srv_imps_rsp_result_struct srv_imps_add_group_member_rsp_struct;

/* response struct for leave group */
typedef srv_imps_rsp_result_struct srv_imps_leave_group_rsp_struct;

/* response struct for delete group */
typedef srv_imps_rsp_result_struct srv_imps_delete_group_rsp_struct;

/* response struct for updating presence */
typedef srv_imps_rsp_result_struct srv_imps_update_pa_rsp_struct;

/* response struct for creating attribute list */
typedef srv_imps_rsp_result_struct srv_imps_create_attribute_list_rsp_struct;

/* response struct for unsubscibing presence */
typedef srv_imps_rsp_result_struct srv_imps_unsubs_pa_rsp_struct;

/* response struct for subscibing presence */
typedef srv_imps_rsp_result_struct srv_imps_subs_pa_rsp_struct;

/* response struct for deleting contact */
typedef srv_imps_rsp_result_struct srv_imps_del_contact_rsp_struct;

/* response struct for deleting contact list */
typedef srv_imps_rsp_result_struct srv_imps_del_contact_list_rsp_struct;

/* response struct for editing contact list */
typedef srv_imps_rsp_result_struct srv_imps_edit_contact_list_rsp_struct;

/* response struct for add contact list */
typedef srv_imps_rsp_result_struct srv_imps_add_contact_list_rsp_struct;

/* response struct for block entity */
typedef srv_imps_rsp_result_struct srv_imps_block_entity_rsp_struct;

/* response struct for rejecting message */
typedef srv_imps_rsp_result_struct srv_imps_reject_message_rsp_struct;

/* struct for setting delivery method */
typedef srv_imps_rsp_result_struct srv_imps_delivery_method_rsp_struct;

/* struct for logout response */
typedef srv_imps_rsp_result_struct srv_imps_logout_rsp_struct;

/* event function:  app use this function to handle the event from service */
typedef void (*srv_imps_event_callback_ptr)(
                 U16 id,                /* the index of notification */                  
                 void *data);           /* notification data */

/*****************************************************************************
 * FUNCTION
 *  srv_imps_main_evt_hdlr 
 * DESCRIPTION
 *  IMPS service external event handler.
 * PARAMETERS
 *   event 
 * RETURNS
 *   return
 *****************************************************************************/
mmi_ret srv_imps_main_evt_hdlr(mmi_event_struct *event);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_open 
 * DESCRIPTION
 *  APP that want to use IMPS service should call this function to get app 
 *  handler, this handler will be used for event between app and service  
 * PARAMETERS
 *  void
 * RETURNS
 *   if there is free handler slot, return handler, otherwise return -1.
 *****************************************************************************/
extern S32 srv_imps_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_close 
 * DESCRIPTION
 *  APP should close handler when not need used. refer to srv_imps_open.
 * PARAMETERS
 *  the handler need to be closed.
 * RETURNS
 *   void.
 *****************************************************************************/
extern void srv_imps_close(S32 hd);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_reg_event_callback 
 * DESCRIPTION
 *  APP should register callback function to handle the result of event.
 * PARAMETERS
 *  hd          [IN]        handler to identify app
 *  handle      [IN]        the callback function to registered
 * RETURNS
 *   return the result of register.
 *****************************************************************************/
extern srv_imps_result_enum srv_imps_reg_event_callback(S32 hd, srv_imps_event_callback_ptr handle);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_handle_event
 * DESCRIPTION
 *  the function used for app need service to handle event
 * PARAMETERS
 *  hd              [IN]        app handler
 *  event_id        [IN]        event to handle
 *  user_data       [?]         user data for this event
 * RETURNS
 *  return result of event handle.
 *****************************************************************************/
extern S32 srv_imps_handle_event(S32 hd, U16 event_id, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_init_nvram
 * DESCRIPTION
 *  set protocol handler before service init to avoid missing primitive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_init_nvram(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_notify_idle_reached
 * DESCRIPTION
 *  Notify IDLE screen is reached
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_notify_idle_reached(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_notify_rac_ready
 * DESCRIPTION
 *  Function to indicate that the RAC is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_notify_rac_ready(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_status
 * DESCRIPTION
 *  get IMPS service status, refer to srv_imps_status_enum
 * PARAMETERS
 *  void
 * RETURNS
 *  return the status of service
 *****************************************************************************/
extern U16 srv_imps_get_status(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_current_event
 * DESCRIPTION
 *  get app current event
 * PARAMETERS
 *  hd        [IN]       app handler
 * RETURNS
 *  return event id
 *****************************************************************************/
extern S32 srv_imps_get_current_event(S32 hd);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_event_exist
 * DESCRIPTION
 *  judge whether some event exist or not
 * PARAMETERS
 *  hd              [IN]       app handler
 *  event_id        [IN]       event_id
 * RETURNS
 *  if event exist, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_event_exist(S32 hd, U32 event_id);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_app_idle
 * DESCRIPTION
 *  judge whether some app is idle
 * PARAMETERS
 *  hd              [IN]       app handler
 * RETURNS
 *  if app is idle, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_app_idle(S32 hd);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_login_ready
 * DESCRIPTION
 *  function used for identify whether the app can login already.
 * PARAMETERS
 *  hd          [IN]       app handler 
 * RETURNS
 *  if app reach login condition, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_login_ready(S32 hd);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_contact_list_is_full
 * DESCRIPTION
 *  function used identify whether contact list is full
 * PARAMETERS
 *  void
 * RETURNS
 *  if there is no free contact list to use, return MMI_TRUE, otherwise return
 *  MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_contact_list_is_full(void);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_pa
 * DESCRIPTION
 *  Get contact presence information
 * PARAMETERS
 *  cont_index      [IN]     contact index    
 *  pa              [OUT]    buffer to store pa information         
  * RETURNS
 *  if get successfully, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_contact_pa(srv_imps_presence_struct *pa, U32 cont_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_pp
 * DESCRIPTION
 *  Get contact's pp.
 * PARAMETERS
 *  user_pp         [OUT]         buffer to store detail information
 *  cont_index      [IN]          the index of contact
 * RETURNS
 *  if get successfully, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_contact_pp(srv_imps_public_profile_struct *user_pp, U32 cont_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_myself_pp
 * DESCRIPTION
 *  Get my public profile.
 * PARAMETERS
 *  pp         [OUT]         buffer to store detail information
 * RETURNS
 *  if get successfully, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_myself_pp(srv_imps_public_profile_struct *pp);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_list_num
 * DESCRIPTION
 *  function used to get contact list number
 * PARAMETERS
 *  void
 * RETURNS
 *  return contact list number
 *****************************************************************************/
extern U32 srv_imps_get_contact_list_num(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_list_info
 * DESCRIPTION
 *  function used to get contact list detail information
 * PARAMETERS
 *  buff        [IN/OUT]    buffer store contact list information
 *  index       [IN]        contact list index
 * RETURNS
 *  return result of get contact list information
 *****************************************************************************/
extern S32 srv_imps_get_contact_list_info(srv_imps_contact_list_struct *buff, U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_num
 * DESCRIPTION
 *  function used to get contact number
 * PARAMETERS
 *  void
 * RETURNS
 *  return contact number
 *****************************************************************************/
extern U32 srv_imps_get_contact_num(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_info
 * DESCRIPTION
 *  function used to get contact detail information
 * PARAMETERS
 *  buff        [IN/OUT]    buffer store contact information
 *  index       [IN]        contact index
 * RETURNS
 *  return result of get contact information
 *****************************************************************************/
extern S32 srv_imps_get_contact_info(srv_imps_contact_struct *cont, U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_info
 * DESCRIPTION
 *  function used to get contact detail information
 * PARAMETERS
 *  index                   [IN]        contact index
 *  online_status           [IN/OUT]    contact online status
 *  availability            [IN/OUT]    contact availability
 * RETURNS
 *  return result of get contact availability
 *****************************************************************************/
S32 srv_imps_get_contact_availability(U32 index, U8 *online_status, U8 *availability);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_img_path
 * DESCRIPTION
 *  Get the path to store image
 * PARAMETERS
 *  dest        [OUT]       Buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_contact_img_path(WCHAR *dest, U32 cont_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_num_in_contact_list
 * DESCRIPTION
 *  get contact number in one contact list 
 * PARAMETERS
 *  cont_list_index     [IN]        contact list index
 * RETURNS
 *  return contact number
 *****************************************************************************/
extern U32 srv_imps_get_contact_num_in_contact_list(U32 cont_list_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_list_index
 * DESCRIPTION
 *  get index of contact list .
 * PARAMETERS
 *  hd          [IN]        app handler, use it to know contact sort type
 *  buff        [IN/OUT]    store the contact list index
 *  count       [IN]        number of contact list index to get
 * RETURNS
 *  return the number of get contact list index.
 *****************************************************************************/
extern U32 srv_imps_get_contact_list_index(S32 hd, U32 *buff, U32 count);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_index
 * DESCRIPTION
 *  function used to get index of contact belonged one contact 
 * PARAMETERS
 *  hd                  [IN]        app handler, use it to know contact sort type
 *  cont_list_index     [IN]        contact list index that contact belong
 *  buff                [IN/OUT]    store index of contact     
 *  count               [IN]        the number of get contact index
 * RETURNS
 *  return the number of get contact index
 *****************************************************************************/
extern U32 srv_imps_get_contact_index(S32 hd, U32 cont_list_index, U32 *buff, U32 count);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_all_contact_index
 * DESCRIPTION
 *  get all contact index
 * PARAMETERS
 *  hd          [IN]             app handler
 *  buff        [IN/OUT]         store contact index
 *  count       [IN]             number of contact to get index
 * RETURNS
 *  return the contact number
 *****************************************************************************/
extern U32 srv_imps_get_all_contact_index(S32 hd, U32 *buff, U32 count);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_online_contact_num
 * DESCRIPTION
 *  get number of online contact of one contact list
 * PARAMETERS
 *  cont_list_index     [IN]        
 * RETURNS
 *  return the online contact number
 *****************************************************************************/
extern U32 srv_imps_get_online_contact_num(U32 cont_list_index);

/*****************************************************************************
* FUNCTION
*  srv_imps_get_all_online_contact
* DESCRIPTION
*  get all online contact
* PARAMETERS
*  buff     [OUT]
*  count    [IN]        
* RETURNS
*  return the online contact number
*****************************************************************************/
extern U32 srv_imps_get_all_online_contact(U32 *buff, U32 count);

/*****************************************************************************
* FUNCTION
*  srv_imps_contact_is_online
* DESCRIPTION
*  check whether contact is online
* PARAMETERS
*  cont     [IN]
* RETURNS
*  if contact is online, return MMI_TRUE, otherwise return MMI_FALSE
*****************************************************************************/
extern MMI_BOOL srv_imps_contact_is_online(srv_imps_contact_struct *cont);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_set_contact_sort_type
 * DESCRIPTION
 *  set contact sort type, type value refer to srv_imps_cont_sort_type_enum
 * PARAMETERS
 *  hd      [IN] app handler
 *  type    [IN]    sort type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_set_contact_sort_type(S32 hd, U8 type);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_index_from_room
 * DESCRIPTION
 *  get the index of contact according to room index, it used in single chat room
 * PARAMETERS
 *  room_index      [IN]        room index
 * RETURNS
 *  return contact index
 *****************************************************************************/
extern S32 srv_imps_get_contact_index_from_room(U32 room_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_room_index
 * DESCRIPTION
 * the function used for getting index of room for specified contact, it used
 * for single chat room
 * PARAMETERS
 *  cont_index      [IN]        
 * RETURNS
 *  return index of chat room
 *****************************************************************************/
extern U32 srv_imps_get_room_index(U32 cont_index);

extern S32 srv_imps_get_presence(srv_imps_presence_struct *buff);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_room_is_full
 * DESCRIPTION
 *  function used for check whether all room slots are used
 * PARAMETERS
 *  void
 * RETURNS
 *  if all chat rooms are used, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_room_is_full(void);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_single_room_exist
 * DESCRIPTION
 *  function used to check whether the room for specified contact is existed.
 * PARAMETERS
 *  cont_index      [IN]        
 * RETURNS
 *  if the room is existed, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_single_room_exist(U32 cont_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_create_room
 * DESCRIPTION
 *  create one room for specified contact according to contact index
 * PARAMETERS
 *  cont_index      [IN]        
 * RETURNS
 *  return room index
 *****************************************************************************/
extern U32 srv_imps_create_room(U32 cont_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_create_room_ex
 * DESCRIPTION
 *  create chat room according to contact id, it used for create single chat room.
 * PARAMETERS
 *  cont_id       [IN]     contact id to create room
 * RETURNS
 *  return room index 
 *****************************************************************************/
extern U32 srv_imps_create_room_ex(CHAR *cont_id);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_close_room
 * DESCRIPTION
 *  close room, release room resource, refer to srv_imps_create_room
 * PARAMETERS
 *  index       [IN]        room index
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_close_room(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_room_type
 * DESCRIPTION
 *  get room type
 * PARAMETERS
 *  index       [IN]        room index
 * RETURNS
 *  return room type
 *****************************************************************************/
extern S32 srv_imps_get_room_type(U32 room_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_room_info
 * DESCRIPTION
 *  get room detail information according to room index
 * PARAMETERS
 *  room_prop       [OUT]         store room detail information
 *  index           [IN]        room index
 * RETURNS
 *  if successfully, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_room_info(srv_imps_room_prop_struct *room, U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_chat_message_info
 * DESCRIPTION
 *  get chat message detail information 
 * PARAMETERS
 *  buff            [OUT]         store message detail information
 *  msg_index       [IN]        message index to get
 *  room_index      [IN]        room index
 * RETURNS
 *  if successfully, return message length, otherwise return -1
 *****************************************************************************/
extern S32 srv_imps_get_chat_message_info(srv_imps_message_struct *buff, U32 msg_index, U32 room_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_add_chat_message_info
 * DESCRIPTION
 *  get chat message detail information 
 * PARAMETERS
 *  buff            [OUT]       store message detail information
 *  room_index      [IN]        room index
 * RETURNS
 *  if successfully, return 0, otherwise return -1
 *****************************************************************************/
extern S32 srv_imps_add_chat_message_info(srv_imps_message_struct *msg, U32 room_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_save_chat_message_info
 * DESCRIPTION
 *  get chat message detail information 
 * PARAMETERS
 *  buff            [OUT]       store message detail information
 *  room_index      [IN]        room index
 * RETURNS
 *  if successfully, return 0, otherwise return -1
 *****************************************************************************/
extern MMI_BOOL srv_imps_save_chat_message_info(WCHAR *filepath, U32 room_index);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_message_notify
 * DESCRIPTION
 *  get message notify indication
 * PARAMETERS
 *  buff        [OUT]     store detail information of message notify indication
 * RETURNS
 *  if there is no message notify indication, return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_message_notify(imps_message_info_struct *buff);

/***************************************************************************
 * FUNCTION
 *  srv_imps_get_system_message_info
 * DESCRIPTION
 *  get system message detail information
 * PARAMETERS
 *  buffer     [IN]        the buffer to store system message information
 * RETURNS
 *  if there is system message information, return MMI_TRUE, otherwise, return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_system_message_info(imps_system_message_struct *buff);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_invitation_info
 * DESCRIPTION
 *  get group invitation information
 * PARAMETERS
 *  buff     [IN]        store invitation information
 * RETURNS
 *  if exist group invitation, return MMI_TRUE, otherwise MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_invitation_info(mmi_imps_invite_ind_struct *buff);

#define STRING_IMPS
/*****************************************************************************
 * FUNCTION
 *  srv_imps_string_copy_with_dot
 * DESCRIPTION
 *  Append three dots to the end of string
 * PARAMETERS
 *  source      [IN]            Source buffer.
 *  dest        [IN/OUT]        Destination buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer , including NULL terminate
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_string_copy_with_dot(CHAR *source, CHAR *dest, S32 max_len);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_string_ansi_2_ucs2_menu
 * DESCRIPTION
 *  Generate menu item from ASCII string
 * PARAMETERS
 *  source      [IN]            Source buffer.
 *  dest        [IN/OUT]        Destination buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_string_ansi_2_ucs2_menu(CHAR *source, CHAR *dest, S32 max_len);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_char_tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
extern CHAR srv_imps_char_tolower(CHAR ch);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_strnicmp
 * DESCRIPTION
 *  Compare two string without case with maximum length
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
extern CHAR srv_imps_strnicmp(const CHAR *src, const CHAR *dest, S32 maxlen);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_stricmp
 * DESCRIPTION
 *  Compare two strings without case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
extern CHAR srv_imps_stricmp(const CHAR *src, const CHAR *dest);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_server_addr_valid
 * DESCRIPTION
 *  Check if the input address string is allowable.
 * PARAMETERS
 *  name        [IN]        String of input
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_server_addr_valid(const CHAR *addr);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_id_same
 * DESCRIPTION
 *  Compare if two ids are identical (without wv:)
 * PARAMETERS
 *  id1     [IN]        Id to be compared
 *  id2     [IN]        Id to be compared
 * RETURNS
 *  TRUE if identical; otherwise, FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_id_same(const CHAR *id1, const CHAR *id2);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_contact_list_name_valid
 * DESCRIPTION
 *  Check if the input user name string is allowable.
 *  A user name can only contains string between ASCII 0x20 ~ 0x7E
 *  The plus (+) character can only be placed before numeric character
 * PARAMETERS
 *  name        [IN]        String of input
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_contact_list_name_valid(const WCHAR *name);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_username_valid
 * DESCRIPTION
 *  Check if the input user name string is allowable.
 *  A user name can only contains string between ASCII 0x20 ~ 0x7E
 *  The plus (+) character can only be placed before numeric character
 * PARAMETERS
 *  name        [IN]        String of input
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_is_username_valid(WCHAR *name);


/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_screen_name
 * DESCRIPTION
 *  get screen name for group, if there is freindly name, use it, else if
 *  there is alias, use it. otherwise use user_id;
 * PARAMETERS
 *  name        [IN/OUT]        Screen name.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_screen_name(WCHAR *name);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_disp_name
 * DESCRIPTION
 *  get contact display name, if there is nickname, use it, else use userid
 * PARAMETERS
 *  name        [OUT]        buffer to store display name.
 *  cont_index  [IN]         contact index.
 *  size        [IN]         buffer size of name.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_contact_disp_name(WCHAR *name, U32 cont_index, U32 size);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_disp_name_ex
 * DESCRIPTION
 *  get contact display name, if there is nickname, use it, else use userid
 * PARAMETERS
 *  name        [OUT]        buffer to store display name.
 *  cont        [IN]         contact information.
 *  size        [IN]         buffer size of name.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_contact_disp_name_ex(WCHAR *name, srv_imps_contact_struct *cont, 
                                              U32 size);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_string_append_wv
 * DESCRIPTION
 *  Check if "wv:" string contains in the string.
 *  If not, append it.
 * PARAMETERS
 *  dest        [OUT]       Buffer to be checked andappended.
 *  max_len     [IN]        Max length of buffer
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.(?)(?)(?)(?)
 *****************************************************************************/
extern void srv_imps_string_append_wv(WCHAR *dest, S32 max_len);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_contact_exist
 * DESCRIPTION
 *  Check if the contact already exists in contact list
 * PARAMETERS
 *  id      [IN]        Id of the contact
 * RETURNS
 *  TRUE if the contact exists; otherwise, FALSE
 *****************************************************************************/
MMI_BOOL srv_imps_is_contact_exist(CHAR *id);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_contact_list_exist
 * DESCRIPTION
 *  Check if the contact list already exists
 * PARAMETERS
 *  id      [IN]        Id of the group
 * RETURNS
 *  TRUE if the group exists; otherwise, FALSE
 *****************************************************************************/
MMI_BOOL srv_imps_is_contact_list_exist(WCHAR *name);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_is_room_exist
 * DESCRIPTION
 *  Check if the user has already joined the chat room
 * PARAMETERS
 *  id      [IN]        Id of the chat room
 * RETURNS
 *  TRUE if the user has already joined the chat room; otherwise, FALSE
 *****************************************************************************/
MMI_BOOL srv_imps_is_room_exist(CHAR *id);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_filename_from_fileindex
 * DESCRIPTION
 *  Get filename from file index
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_imps_get_filename_from_fileindex(U32 fileindex, U16 filetype, WCHAR* filename);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_work_path
 * DESCRIPTION
 *  Get path of working directory
 * PARAMETERS
 *  dest        [OUT]       Buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_work_path(WCHAR *dest);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_myself_img_path
 * DESCRIPTION
 *  Get the path to store image
 * PARAMETERS
 *  dest        [OUT]       Buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_imps_get_myself_img_path(WCHAR *dest);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_check_file_exist
 * DESCRIPTION
 *  Check if the file already exists.
 * PARAMETERS
 *  filePathName        [IN]        Full file path + name
 * RETURNS
 *  MMI_TRUE if exists, otherwise, MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_imps_check_file_exist(WCHAR *filePathName);
    
/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_file_size
 * DESCRIPTION
 *  Get size of a file
 * PARAMETERS
 *  filePathPrt     [IN]     file path
 *  fileSizePtr     [OUT]    store file size 
 * RETURNS
 *  Error cause of file open
 *****************************************************************************/
extern S32 srv_imps_get_file_size(WCHAR *filePathPtr, S32 *fileSizePtr);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_resize_image
 * DESCRIPTION
 *  Resize image
 * PARAMETERS
 *  void
 * RETURNS
 *  1: resized. 0: no need to resize. negative: error!
 *****************************************************************************/
extern S32 srv_imps_resize_image(WCHAR *file, WCHAR *dest_file, U32 resize_w, U32 resize_h);

/*****************************************************************************
* FUNCTION
*  srv_imps_delete_group_file
* DESCRIPTION
*  delete file
* PARAMETERS
*  hd         [IN]       app handler
*  type       [IN]       type: srv_imps_group_entity_type_enum 
* RETURNS
*  void
*****************************************************************************/
void srv_imps_delete_group_file(U32 room_index, U16 type);

/*****************************************************************************
* FUNCTION
*  srv_imps_get_group_entity
* DESCRIPTION
*  get group entity information, after use entity, app should call srv_imps_delete_group_file
*  to delete file
* PARAMETERS
*  hd         [IN]         app handler
*  buff       [OUT]        buffer to store entity information
*  index      [IN]         the index of entity 
*  entity_type  [IN]       entity type: srv_imps_group_entity_type_enum 
* RETURNS
*  if successfully get entity, return MMI_TRUE, otherwise return MMI_FALSE.
*****************************************************************************/
MMI_BOOL srv_imps_get_group_entity(U32 room_index, imps_entity_struct *buff, U32 index, U16 entity_type);

/*****************************************************************************
* FUNCTION
*  srv_imps_get_search_entity
* DESCRIPTION
*  get search result entity information, after use entity, app should call srv_imps_delete_search_file
*  to delete file
* PARAMETERS
*  hd         [IN]         app handler
*  buff       [OUT]        buffer to store entity information
*  index      [IN]         the index of entity 
* RETURNS
*  if successfully get entity, return MMI_TRUE, otherwise return MMI_FALSE.
*****************************************************************************/
MMI_BOOL srv_imps_get_search_entity(S32 hd, imps_entity_struct *buff, U32 index);

/*****************************************************************************
* FUNCTION
*  srv_imps_delete_search_file
* DESCRIPTION
*  delete search result file
* PARAMETERS
*  hd         [IN]         app handler 
* RETURNS
*  void
*****************************************************************************/
extern void srv_imps_delete_search_file(S32 hd);


/*****************************************************************************
* FUNCTION
*  srv_imps_get_watcher_entity
* DESCRIPTION
*  get watcher list entity information, after use entity, app should call srv_imps_delete_watcher_file
*  to delete file
* PARAMETERS
*  hd         [IN]         app handler
*  buff       [OUT]        buffer to store entity information
*  index      [IN]         the index of entity 
* RETURNS
*  if successfully get entity, return MMI_TRUE, otherwise return MMI_FALSE.
*****************************************************************************/
MMI_BOOL srv_imps_get_watcher_entity(S32 hd, imps_watcher_entity_struct *buff, U32 index);

/*****************************************************************************
* FUNCTION
*  srv_imps_delete_watcher_file
* DESCRIPTION
*  delete watcher list file
* PARAMETERS
*  hd         [IN]         app handler 
* RETURNS
*  void
*****************************************************************************/
void srv_imps_delete_watcher_file(S32 hd);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_pa_auth
 * DESCRIPTION
 *  Get presence authorization information, when app receive SRV_IMPS_EVNET_PA_AUTH_IND
 *  it should call this function to get who want to get presence authorization
 *  if user agree to authorize presence, app can send SRV_IMPS_EVENT_ADD_CONT.
 * PARAMETERS
 *  user      [OUT]        buffer to store who want to get presence authorization
 * RETURNS
 *  if there is presence authorization, return MMI_TRUE; otherwise, return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_imps_get_pa_auth(imps_entity_struct *user);

/*****************************************************************************
 * FUNCTION
 *  srv_imps_get_contact_index_from_id
 * DESCRIPTION
 *  Find out the index of contact
 * PARAMETERS
 *  contact_id      [IN]        Contact id 
 * RETURNS
 *  if contact doesn't existed, return -1, otherwise return contact index
 *****************************************************************************/
extern S32 srv_imps_get_contact_index_from_id(const CHAR *contact_id);

#endif

