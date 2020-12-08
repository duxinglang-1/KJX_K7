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
 *  ImpsSrv.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines local contant, structure, enum, and function prototypes forIMPS service.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IMPS_SRV_H__
#define __IMPS_SRV_H__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "FileMgrSrvGProt.h"

#include "mmi2imps_struct.h"
#include "ImpsSrvGprot.h"

#define SRV_IMPS_LOG(x)                      MMI_TRACE(MMI_INET_TRC_G8_IMPS, x)
#define SRV_IMPS_LOG1(x, x1)                 MMI_TRACE(MMI_INET_TRC_G8_IMPS, x, x1)
#define SRV_IMPS_LOG2(x, x1, x2)             MMI_TRACE(MMI_INET_TRC_G8_IMPS, x, x1, x2)

/* Maximum handler number of service to support application */
#define SRV_IMPS_MAX_HANDLE_NUM             (2)

/* Maximum of event queue of app */
#define SRV_IMPS_MAX_QUEUE_NUM              (2)

#define SRV_IMPS_MAX_CHAT_MSG_COUNT         (5)       /* maximum number of session hold in MMI task */

#define SRV_IMPS_MAX_PEND_INVITATION        (10)      /* maximum number of pending invitation */

#define SRV_IMPS_MAX_PENDING_PA_AUTH        (10)

#define SRV_IMPS_ABOUT_PIC_PREFIX           L"about." /* file name of picture */

/* status */
#define SRV_IMPS_LOGIN_RAC_READY            (0x01)    /* GPRS ready to activate */
#define SRV_IMPS_LOGIN_PS_READY             (0x02)    /* IMPS task ready to serve MMI */
#define SRV_IMPS_LOGIN_IDLE_REACHED         (0x04)    /* MMI reaches IDLE screen */
#define SRV_IMPS_LOGIN_READY                (0x07)    /* IMPS application ready to login, the previous two items shall ready together. */
#define SRV_IMPS_LOGIN_ALREADY              (0x08)    /* already login */

/* chat */
#define SRV_IMPS_CHAT_FILENAME_LEN          (128)
#define SRV_IMPS_MAX_SEQ_NUM                (65535)   /* maximum sqeunce number of session id */
#define SRV_IMPS_MAX_CHAT_MESSAGE_LEN       ((260 + 1) * ENCODING_LENGTH)

/* contact */
#define SRV_IMPS_TOTAL_CONT_COUNT           (SRV_IMPS_MAX_CONTACT_LIST_COUNT + SRV_IMPS_MAX_CONT_COUNT)

/* invite */
#define SRV_IMPS_MAX_INVITE_SESSION         (5)      /* maximum number of invitation that can be sent at the same time */
#define SRV_IMPS_MAX_PENDING_INVITATION     (10)

/* contact list */
#define SRV_IMPS_CONT_PA_READY              0x01
#define SRV_IMPS_CONT_BLOCK                 0x02
#define SRV_IMPS_CONT_NEW_MSG               0x04

#define SRV_IMPS_PA_ATTR_VALUE IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS|IMPS_PA_STATUS_CONTENT|IMPS_PA_CLIENT_INFO
#define SRV_IMPS_PA_ATTR_VALUE_NO_PIC IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS|IMPS_PA_CLIENT_INFO
#define SRV_IMPS_PA_MY_ATTR_VALUE IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS

/* filename for rejected user list */
#define SRV_IMPS_REJECTED_USER              L"rejected"

#define SRV_IMPS_PUBLIC_PROFILE             L"pp.dat"
#define SRV_IMPS_PA_AUTH                    L"pa_auth"
#define SRV_IMPS_INVITE_FILE                L"invite.dat"
#define SRV_IMPS_FR_PP_FILE                 L"frpp.dat"

#define SRV_IMPS_CHAT_SESSION_FILE          L"chat_session"

#define SRV_IMPS_SYS_FILE_DIRECTORY         L"Z:\\@imps\\"

typedef struct
{
    U8 ref_count;
    U16 msg_len;
} imps_local_para_hdr;

#define IMPS_MEMSET(addr, value, structure) memset(((U8*)addr)+sizeof(imps_local_para_hdr), value, (S32)(sizeof(structure) - sizeof(imps_local_para_hdr)))

typedef enum
{
    SRV_IMPS_GROUP_JOIN_FROM_APP = 0,
    SRV_IMPS_GROUP_JOIN_FROM_INVITE_REPLY,
    SRV_IMPS_GROUP_JOIN_END_OF_ENUM
} srv_imps_group_join_type_enum;

typedef enum
{
    SRV_IMPS_PA_AUTH_FROM_INVITE = 0,
    SRV_IMPS_PA_AUTH_FROM_GENERAL_NOTIFY,
    SRV_IMPS_PA_AUTH_FROM_AUTH_IND,
    SRV_IMPS_PA_AUTH_END_OF_ENUM
} srv_imps_pa_auth_type_enum;

typedef enum
{
    SRV_IMPS_SEARCH_RESEULT_FILE = 0,
    SRV_IMPS_WATCHER_LIST_FILE,
    SRV_IMPS_GROUP_MEMBER_FILE,
    SRV_IMPS_GROUP_JOINED_USER_FILE,
    SRV_IMPS_GROUP_REJECTED_USER_FILE,  
    SRV_IMPS_SYSTEM_MESSAGE_FILE,
    SRV_IMPS_PA_AUTH_FILE,
    SRV_IMPS_MESSAGE_NOTIFY_FILE,
    SRV_IMPS_INTERNAL_FILE_END_OF_ENUM
} srv_imps_internal_file_type;

typedef struct
{
    S32 hd;
    U32 event[SRV_IMPS_MAX_QUEUE_NUM];
    U32 dt_acct;
    MMI_BOOL is_used;
    U8 sort_type;   
    U8 ps_ready_state;
    srv_imps_event_callback_ptr handle;    
} srv_imps_handler_info_struct;


typedef struct
{
    srv_imps_status_enum status;
	U8  imps_version;
} srv_imps_gen_info_struct;

typedef struct
{
   	CHAR login_server[IMPS_MAX_SERVER_ADDRESS_LEN]; /* server address for current login */
    CHAR login_username[IMPS_MAX_USERID_LEN];           /* user name for current login */    
} srv_imps_account_info_struct;

/* general information of all contacts */
typedef struct
{
    srv_imps_contact_struct cont[SRV_IMPS_MAX_CONT_COUNT];   /* array of contacts */     
    U32 curr_cont;                                       /* index of contact: add, edit, delete */
    U32 no_cont;                                         /* number of contact */    
    U32 index_no;                                       /* the index number */    
    WCHAR cont_img[IMPS_MAX_FILE_NAME_LEN]; /* store image */
    U32 img_cont_index;                                 /* contact index stored image */
} srv_imps_cont_info_struct;

typedef struct
{
	MMI_BOOL authorize_pa_p;
    U32 pa_value;
    MMI_BOOL display_name_p;
    WCHAR name[IMPS_MAX_NAME_LEN];
} srv_imps_edit_contact_list_struct;

/* overall information of groups */
typedef struct
{    
    srv_imps_contact_list_struct cont_list[SRV_IMPS_MAX_CONTACT_LIST_COUNT];    /* list of groups */
    U32 no_cont_list;                                        /* number of groups */
    U32 curr_item;                                           /* current handle item */ 
    U8 curr_update;                                         /* current update item */
    U32 index_no;
	U32 curr_subs;                                            /* current subscribe pa item */
    U32 curr_get_pa;
    srv_imps_edit_contact_list_struct *edit_info;
} srv_imps_cont_list_info_struct;

/* overall information of groups */
typedef struct
{    
    U32 by_name[SRV_IMPS_TOTAL_CONT_COUNT];  /* list of groups */
    U32 by_status[SRV_IMPS_TOTAL_CONT_COUNT];  /* list of groups */
    U8 type;
} srv_imps_sort_info_struct;


typedef struct
{    
    U32 id;
    S32 app_hd;
    U32 room_index;
} srv_imps_chat_session_struct;

typedef struct
{    
    S32 seq_no;         /* global sequence number for chat and invite session */
    srv_imps_chat_session_struct chat_session[SRV_IMPS_MAX_CHAT_MSG_COUNT];
} srv_imps_chat_info_struct;

typedef struct
{
    //S32 app_handle;                                         /* indentification for app */    
	srv_imps_room_prop_struct room_prop;
	CHAR room_id[IMPS_MAX_ID_LEN];                             /* id of the room */
	CHAR room_id_tmp[IMPS_MAX_ID_LEN];                        /* temp id for one-to-one ExtendConversation */    
    U32 index;                                             /* the index of room, 0 is for not used */        
    MMI_BOOL is_closed;    
} srv_imps_room_struct;

/* overall information of chat rooms */
typedef struct
{
    srv_imps_room_struct room[SRV_IMPS_MAX_ROOM_COUNT];   /* list of chat rooms */
    U32 index_no;
    U32 curr_room;
    U16 group_abort_event;
    MMI_BOOL join_from_ec;
    U16 join_type;
    U32 group_entity_index;
    U8 pri_level;
} srv_imps_room_info_struct;

/* overall information of message */
typedef struct
{
    MMI_BOOL after_list_message;
    MMI_BOOL pending_notify[SRV_IMPS_MAX_PEND_MSG_COUNT];
    U16 offline_msg_num;
    U16 curr_offline_msg;
    WCHAR offline_msg_path[IMPS_MAX_FILE_PATH_LEN];
} srv_imps_message_info_struct;

/* invite session */
typedef struct
{
    S32 hd;
    U32 session_id;    /* session id */
    WCHAR recipient[IMPS_MAX_ID_LEN];
    U32 room_index;    /* chat room to invite */    
} srv_imps_invite_session_struct;

typedef struct 
{
    CHAR group_id[IMPS_MAX_ID_LEN];
    WCHAR sname[IMPS_MAX_NAME_LEN];
} srv_imps_group_invite_accept_struct;

/* invite information */
typedef struct
{
    MMI_BOOL pending_invite[SRV_IMPS_MAX_PENDING_INVITATION];
    srv_imps_invite_session_struct invite_session[SRV_IMPS_MAX_INVITE_SESSION];  /* invite sent out */
    U8 curr_pend_invite;
    srv_imps_group_invite_accept_struct group_accept;
} srv_imps_invite_info_struct;

/* invite information */
typedef struct
{
    U16 event_id;
    U32 search_count;
} srv_imps_search_info_struct;

typedef struct
{    
    U8 channel_id;
    U16 request_id;    
} srv_imps_http_auth_struct;

/* data structure used in processing system message */
typedef struct
{    
    U8 curr_index;          /* current processing index */
    U8 total;               /* total */ 
} srv_imps_system_message_info_struct;

typedef struct  
{
    imps_entity_struct entity;
    U32 attr_list;
} srv_imps_pa_auth_ind_struct;

/* the structure used in 3 cases: general notify for ATCL, ANC, AND, ANU
   invite presence and pa authorization indication */
typedef struct
{
    U16 type;    /* srv_imps_pa_auth_type_enum */
    union
    {
        mmi_imps_invite_ind_struct invite;
        srv_imps_pa_auth_ind_struct pa_ind;
    } content;
} srv_imps_pa_auth_struct;

typedef struct 
{
    MMI_BOOL list[SRV_IMPS_MAX_PENDING_PA_AUTH];    
} srv_imps_pa_auth_info_struct;

typedef struct
{
    srv_imps_handler_info_struct app_handler[SRV_IMPS_MAX_HANDLE_NUM];
    srv_imps_gen_info_struct gen_info;
	srv_imps_account_info_struct acct_info;
    srv_imps_cont_list_info_struct cont_list_info;
    srv_imps_cont_info_struct cont_info; 
    srv_imps_sort_info_struct sort_info;
    srv_imps_chat_info_struct chat_info;
	srv_imps_room_info_struct room_info;
    srv_imps_message_info_struct msg_info;
    srv_imps_invite_info_struct invite_info;
    srv_imps_search_info_struct search_info;    
    srv_imps_http_auth_struct http_auth;
    srv_imps_system_message_info_struct sys_msg;
    srv_imps_public_profile_struct *pp;
    srv_imps_pa_auth_info_struct pa_auth_info;
    WCHAR temp_buff[(SRV_FMGR_PATH_MAX_LEN + 1)]; 
} srv_imps_context_struct;
    
extern srv_imps_context_struct *srv_imps_p;

extern void srv_imps_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern MMI_BOOL srv_imps_is_care_event_rsp(void);
extern void srv_imps_notify_app(U16 event_id, void *response_data);
extern void srv_imps_general_notify_app(U16 event_id, S32 result,
                                 imps_detail_struct *detail);
extern S32 srv_imps_get_app_handle(U16 event_id);
extern S32 srv_imps_handle_event_pa(U16 event_id, void *user_data);
extern S32 srv_imps_handle_event_message(S32 hd, U16 event_id, void *user_data);
extern S32 srv_imps_handle_event_group(U16 event_id, void *user_data);
extern S32 srv_imps_handle_event_invite(S32 hd, U16 event_id, void *user_data);

extern void srv_imps_init_fm_event_handle(void);
extern void srv_imps_init_pa_event_handle(void);
extern void srv_imps_init_chat_event_handle(void);
extern void srv_imps_init_group_event_handle(void);
extern void srv_imps_init_invite_event_handle(void);

extern void srv_imps_init_cont_info(void);
extern void srv_imps_init_chat_folder(void);
extern void srv_imps_ps_ready_ind(void *msg);
extern void srv_imps_init_ps_before_idle(void);
extern MMI_BOOL srv_imps_is_rac_ready(U32 dt_acct);

extern void srv_imps_load_cont_info(void);
extern void srv_imps_reset_cont_info(void);
extern void srv_imps_get_contact_list_req(void);
extern void srv_imps_update_cont_list(mmi_imps_get_contact_list_rsp_struct *rsp);
extern void srv_imps_sync_cont_list(void);
extern void srv_imps_reset_cont_info(void);
extern S32 srv_imps_set_cont_list_pa(srv_imps_contact_list_struct *cont_list_p, U32 value);
extern void srv_imps_set_cont_pa(CHAR *contact_id, imps_pa_value_struct *pa_value);
extern void srv_imps_update_cont(mmi_imps_view_contact_list_rsp_struct *rsp);
extern S32 srv_imps_get_cont_list(U32 index);
extern S32 srv_imps_get_cont_list_index(CHAR *cont_list_id);
extern S32 srv_imps_get_cont_list_from_id(CHAR *cont_list_id);
extern S32 srv_imps_get_contact(U32 index);
extern S32 srv_imps_get_contact_index_from_id(const CHAR *contact_id);
extern S32 srv_imps_get_free_contact_slot(void);
extern S32 srv_imps_write_cont_list(void);
extern S32 srv_imps_write_cont(void);
extern void srv_imps_reset_cntx(void);
extern void srv_imps_sort_contact(void);
extern U32 srv_imps_get_cont_index_in_cont_list(U32 cont_list_index, U32 *buff);
extern void srv_imps_del_local_contact_img(void);

extern void srv_imps_list_message_req(void);
extern void srv_imps_get_user_name_from_id(CHAR *name, CHAR* id, U16 size);
extern void srv_imps_get_room_name_from_id(WCHAR *name, CHAR* id, U32 size);

extern MMI_BOOL srv_imps_get_temp_folder_path(WCHAR *filepath);
extern MMI_BOOL srv_imps_get_filename(S32 hd, U16 file_type, WCHAR *filepath);
extern MMI_BOOL srv_imps_get_group_filename(CHAR *group_id, U16 file_type, WCHAR *filepath);
extern MMI_BOOL srv_imps_get_entity_from_file(WCHAR *filename, imps_entity_struct *buff, U32 index);

extern void srv_imps_add_cont_invite_presence(S32 hd, U32 cont_index);

extern CHAR srv_imps_stricmp(const CHAR *src, const CHAR *dest);
extern S32 srv_imps_get_chat_room(U32 room_index);
extern void srv_imps_room_reset_cntx(srv_imps_room_struct *room);
extern S32 srv_imps_get_room_no(CHAR *id, MMI_BOOL group_only);

extern S32 srv_imps_join_group_req(U16 join_type, void *user_data);

extern void srv_imps_notify_anu(imps_pa_notification_struct *pa_notify);
extern void srv_imps_notify_cld(imps_entity_list_struct *entity_list);
extern void srv_imps_notify_ac(imps_pa_notification_struct *pa_notify);
extern void srv_imps_notify_clc(mmi_imps_notify_ind_struct *ind);
extern void srv_imps_notify_clcr(imps_entity_list_struct *entity_list);
extern void srv_imps_notify_atcl(imps_entity_struct *user);
extern S32 srv_imps_get_block_list_req(void);

extern void srv_imps_add_pa_auth_ind(srv_imps_pa_auth_struct *pa);
extern S32 srv_imps_invite_pr_reply_req(mmi_imps_invite_ind_struct *ind,MMI_BOOL accept, 
                                        MMI_BOOL background);

#endif
