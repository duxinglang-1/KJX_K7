#ifdef __CLOUD_SUPPORT__

#ifndef __BACKUP_RESTORE_SRV_H__
#define __BACKUP_RESTORE_SRV_H__

#include "CloudSrvGprot.h"
#ifdef __SMS_CLOUD_SUPPORT__
#include "EmailSrvGprot.h"
#include "EmailSrvIprot.h"
#endif /* __SMS_CLOUD_SUPPORT__ */
#include "app2vcrd_struct.h"
#include "SsoSrvGprot.h"
#include "FS_Gprot.h"
#include "custom_phb_config.h"
#include "CloudPlugin.h"
#include "SsoSrvGprot.h"
#include "app2vcrd_struct.h"
#include "Fs_gprot.h"
#include "custom_cloud_config.h"

#define TRC_SRV_CLD_GRP TRACE_GROUP_8

#define SRV_CLD_SMS_HDLR (1)
#define SRV_CLD_VCARD_HDLR (2)
#define SRV_CLD_MAX_SMS_NUM (SMS_PHONE_ENTRY)
#define SRV_CLD_MAX_VCRD_NUM (MAX_PHB_PHONE_ENTRY)
#define SRV_CLD_TRC_GROUP                 TRACE_GROUP_8
#define SRV_CLD_GET_HOST_REQ_ID  (80962)
#define SRV_CLOUD_NAME_LEN (64)
#define SRV_CLOUD_URL_LEN (256)
#define SRV_CLD_FILE_NAME_LEN     (40)
#define SRV_CLD_COOKIE_EXPIRE_ERROR_CODE (401)
#define SRV_CLD_PLUGIN_FILE_NAME_LEN   (260)

#if defined(__SMS_CLOUD_SUPPORT__) && defined(__VCARD_CLOUD_SUPPORT__) 
#define SRV_CLD_ADM_SIZE   (36 * 1024)      /* 48K */
#elif defined(__VCARD_CLOUD_SUPPORT__) 
#define SRV_CLD_ADM_SIZE    (10 * 1024)
#elif defined(__SMS_CLOUD_SUPPORT__)
#define SRV_CLD_ADM_SIZE    (30 * 1024)
#else
#define SRV_CLD_ADM_SIZE    (10 * 1024)
#endif

#define SRV_CLD_UID_FILE              L"SevUidList"
#define SRV_CLD_PUT_DATA_FILE         L"vCardBackup"
#define SRV_CLD_RESTORE_DATA_FILE     L"vCardRestore"
#define SRV_CLD_RESTORE_UID_FILE      L"vCardSevUid"
#define SRV_CLD_GET_DATA_FILE         L"vCardData"

#define SRV_CLD_INTER_FILE_PATH_LEN 20
typedef struct server_info_struct
{
    cloud_plugin_provider_struct server_info;
    WCHAR vpp_path[SRV_CLD_PLUGIN_FILE_NAME_LEN];
    struct server_info_struct * next;    
}srv_cloud_server_info_node_struct;


typedef struct
{
    U32 hash;
    U16 index;
}srv_cloud_sort_item_struct;

typedef struct
{
    srv_cloud_uid_struct * index; //malloc ADM
    U16 num;
}srv_cloud_restore_uid_struct;

typedef struct
{
    U8 * flag; //malloc ADM
}srv_cloud_backup_uid_struct;


typedef enum
{
    SRV_CLD_STATE_NULL,
    SRV_CLD_STATE_INIT_DONE,
    SRV_CLD_STATE_CREATE,
    SRV_CLD_STATE_PUT_DATA,
    SRV_CLD_STATE_PUT_DATA_DONE,
    SRV_CLD_STATE_GET_DATA,
    SRV_CLD_STATE_CLOSE,
    SRV_CLD_STATE_RETRY,
    SRV_CLD_STATE_TOTAL
}srv_cloud_status_enum;

#ifdef __SMS_CLOUD_SUPPORT__
typedef enum
{
    SRV_CLD_SMS_OP_STATE_INIT = 0,
    SRV_CLD_SMS_OP_STATE_CONN,
    SRV_CLD_SMS_OP_STATE_GET_UID,
    SRV_CLD_SMS_OP_STATE_MARK_UID,
    SRV_CLD_SMS_OP_STATE_GET_MSG,
    SRV_CLD_SMS_OP_STATE_NOTIFY_APP,
    SRV_CLD_SMS_OP_STATE_GET_DATA,
    SRV_CLD_SMS_OP_STATE_FINISH,
} srv_cloud_sms_op_state_enum;

typedef struct
{
    srv_cloud_uid_struct temp_uid;
    srv_cloud_set_opt_acct_info_struct acct;/* vendor id and user account id*/
    U8 * backup_index;
    S32 handler;
    srv_cloud_sort_item_struct * sort_list_ptr; /* point to a block of memory, store sort list*/
    U16 used_num;                           /* num of sort item*/
    srv_cloud_dtype_enum data_type;         /*App use buffer or file to put data */
    U32 uid_count;                          /*used to gen uid*/
    MMI_BOOL used;
    srv_cloud_op_enum op_type;
    srv_cloud_status_enum state;

    srv_email_conn_opt_for_cld_srv_struct conn;
    VMUINT sso_library;

    EMAIL_ACCT_HANDLE email_acct_hd;
    EMAIL_MSG_HANDLE email_msg_hd;
    EMAIL_ACCT_ID email_acct_id;
    EMAIL_REQ_ID req_id;
    WCHAR     uid_file[SRV_CLD_INTER_FILE_PATH_LEN + 1];
    U8 drive;
    MMI_BOOL check_drive;
    U32       uid_download_max;
    FS_HANDLE uid_fhd;
    U16       uid_items_num;
    U16       uid_hd_index;
    srv_cloud_sms_op_state_enum op_state;

    srv_cloud_sms_struct* data;
    U32 sms_index;

    U32 schdl_req_id;
}srv_cloud_sms_ctx_struct;
#endif /* __SMS_CLOUD_SUPPORT__ */

typedef struct
{
    U8 index;
    MMI_BOOL is_file;
}srv_cloud_get_data_file_ctx;

typedef struct
{
    srv_cloud_uid_struct temp_uid;
    srv_cloud_set_opt_acct_info_struct acct; /* vendor id and user account id*/
    srv_cloud_px_info_struct proxy;
    U32 acct_id;
    U8 * backup_index;
    S32 handler;
    srv_cloud_sort_item_struct * sort_list_ptr; /* point to a block of memory, store sort list*/
    U16 used_num; /* num of sort item*/
    U32 channel_id;
    vcrd_hdl hdl;
    vcrd_hdl data_hdl;
    CHAR temp_url[SRV_CLOUD_URL_LEN];
    int get_data_fp;
    U32 get_uid_count;
    U32 uid_count; /*used to gen uid*/
    U16 update_index;
    U16 index;
    U16  url_len;    
    MMI_BOOL used;
    srv_cloud_op_enum op_type;
    srv_cloud_status_enum state;
    srv_cloud_dtype_enum data_type; /*App use buffer or file to put data */
    MMI_BOOL active_cbm_flag;
    MMI_BOOL parse_stop;
    U8 is_add;
    MMI_BOOL no_need_upgrade;
    MMI_BOOL is_change;
    srv_cloud_mem_alloc malloc_func;
    srv_cloud_mem_free free_func;
    srv_cloud_set_opt_cb_t opt_cb_func;  /* for asynchronous to set option */
    VMUINT sso_library;                  /* for asynchronous to set option */
    S32 refresh_id;
    srv_cloud_get_data_file_ctx get_data_context;
}srv_cloud_vcard_ctx_struct;

typedef struct
{
    srv_cloud_set_opt_acct_info_struct acct;
    U8 url[SRV_CLOUD_URL_LEN];                  //uid list
    U32 url_len;
    U8 ctag[SRV_CLD_CTAG_LEN];
    WCHAR user_name[SRV_SSO_NAME_SIZE];
}srv_cloud_vcard_url_srtuct;


typedef struct
{
    srv_cloud_uid_struct uid;
    U16 index;
    MMI_BOOL is_add;
}srv_cloud_uid_ctx_struct;

typedef struct
{
    srv_cloud_uid_ctx_struct uid_ctx[SRV_CLD_RESTORE_NUM]; 
    U16 used_num;
    MMI_BOOL parse_uid_done;
}srv_cloud_restore_buf_ctrl_struct;

typedef struct
{
    U8 * restore_content_ptr[SRV_CLD_RESTORE_NUM];
    U32 length[SRV_CLD_RESTORE_NUM];
    U16 refer_id[SRV_CLD_RESTORE_NUM];
    U8 is_valid[SRV_CLD_RESTORE_NUM];
    U16 used_num;
    U16 app_get_num;/*the num of app already get*/
    U16 valid_num;
    MMI_BOOL is_file[SRV_CLD_RESTORE_NUM];
}srv_cloud_restore_content_struct;


typedef enum
{
    SRV_CLD_GET_UID,
    SRV_CLD_BACKUP,
    SRV_CLD_RESTORE
}srv_cloud_req_enum;

typedef struct
{
    srv_cloud_uid_struct uid;
    U16 index;
}srv_cloud_store_item_struct;

typedef union
{
    U32 i;
    CHAR a[4];
}srv_cloud_str_to_int_union;


typedef struct
{
    fs_overlapped_struct overlapped;
    U32 write_byte;
    S32 job_id;
    const U8 * buf;
    U16 index;
}srv_cloud_async_write_ctx_struct;

typedef struct
{
    U8 * url;
    U8 ctag[SRV_CLD_CTAG_LEN];
}srv_cloud_url_struct;

typedef struct srv_cloud_preload_vpp {
    U32 provider;
    const U8 *addr;
} srv_cloud_preload_vpp_struct;




typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_cloud_type_enum type; 
}srv_cloud_sort_list_ind_evt_struct;



typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    U16 * buffer;
    U16 num;
    U16 total;
    srv_cloud_type_enum type; 
}srv_cloud_async_add_evt_struct;



typedef struct
{
#ifdef __BUILD_DOM__
        U16 evt_id;             /* MMI_EVENT_ID */
        U16 size;               /* EVENT SIZE */
        void *user_data;        /* Piggyback user data */
#endif
        /* DOM-NOT_FOR_SDK-BEGIN */
        MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
        /* DOM-NOT_FOR_SDK-END */
        U32 block;
        U32 num;
        U8 * content_ptr;
        int file_id;
}srv_cloud_store_backup_data_evt_struct;


typedef struct
{
#ifdef __BUILD_DOM__
        U16 evt_id;             /* MMI_EVENT_ID */
        U16 size;               /* EVENT SIZE */
        void *user_data;        /* Piggyback user data */
#endif
        /* DOM-NOT_FOR_SDK-BEGIN */
        MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
        /* DOM-NOT_FOR_SDK-END */
}srv_cloud_post_pause_evt_struct;


typedef struct
{
#ifdef __BUILD_DOM__
            U16 evt_id;             /* MMI_EVENT_ID */
            U16 size;               /* EVENT SIZE */
            void *user_data;        /* Piggyback user data */
#endif
            /* DOM-NOT_FOR_SDK-BEGIN */
            MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
            /* DOM-NOT_FOR_SDK-END */
            U16 index;
}srv_cloud_post_sort_sms_evt_struct;

typedef struct
{
#ifdef __BUILD_DOM__
            U16 evt_id;             /* MMI_EVENT_ID */
            U16 size;               /* EVENT SIZE */
            void *user_data;        /* Piggyback user data */
#endif
            /* DOM-NOT_FOR_SDK-BEGIN */
            MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
            /* DOM-NOT_FOR_SDK-END */
            U16 index;
}srv_cloud_post_sort_vcard_evt_struct;



/* Backup Restore context*/
#ifdef __SMS_CLOUD_SUPPORT__
extern srv_cloud_sms_ctx_struct g_srv_cloud_sms_ctx;
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
extern srv_cloud_vcard_ctx_struct g_srv_cloud_vcard_ctx;

extern srv_cloud_async_write_ctx_struct g_srv_cloud_async_write_ctx;

extern CHAR g_srv_cloud_backup_filename[SRV_CLD_FILE_NAME_LEN];
extern CHAR g_srv_cloud_uid_filename[SRV_CLD_FILE_NAME_LEN];
extern CHAR g_srv_cloud_restore_filename[SRV_CLD_FILE_NAME_LEN];
extern CHAR g_srv_cloud_sev_uid_filename[SRV_CLD_FILE_NAME_LEN];
extern CHAR g_srv_cloud_get_data_filename[SRV_CLD_FILE_NAME_LEN];

extern srv_cloud_restore_buf_ctrl_struct g_srv_cloud_restore_buf_ctx;

extern srv_cloud_restore_content_struct g_srv_cloud_restore_content;

#endif

/* ADM pool */
extern U8 g_srv_cld_mem_addr[SRV_CLD_ADM_SIZE];
extern KAL_ADM_ID g_srv_cld_mem_id;

//extern MMI_BOOL stop;
extern srv_cloud_url_struct g_srv_uid_list_url;
extern cloud_plugin_server_info_struct * g_srv_server_info;


extern srv_cloud_server_info_node_struct* g_srv_server_info_list;


#define __BACKUP_RESTORE_MODULE_INIT__
extern mmi_ret srv_cloud_init(mmi_event_struct *evt);
#ifdef __SMS_CLOUD_SUPPORT__
extern void srv_cloud_post_sort_sms_evt(U16 index);
extern mmi_ret srv_cloud_sort_sms_list(mmi_event_struct *param);
#endif
#ifdef __VCARD_CLOUD_SUPPORT__
extern void srv_cloud_post_sort_vcard_evt(U16 index);
extern mmi_ret srv_cloud_sort_vcard_list(mmi_event_struct *param);
#endif
extern void srv_cloud_plugin_discover(void);


#define __BACKUP_RESTORE_MEM__
extern int srv_cloud_create_mem_pool(void);
extern int srv_cloud_delete_mem_pool(void);
extern void *srv_cloud_calloc(kal_uint32 n, kal_uint32 size);
extern void *srv_cloud_malloc(U32 size);
extern void srv_cloud_free(void *ptr);
extern U32 srv_cloud_get_max_alloc_size(void);


#define __BACKUP_RESTORE_API_UTIL__
extern MMI_BOOL srv_cloud_is_exist(srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_is_init_done(srv_cloud_type_enum type);
extern S32 srv_cloud_init_ctx(srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_get_server_info(U32 id, cloud_plugin_server_info_struct** server, srv_cloud_type_enum type);
#ifdef __VCARD_CLOUD_SUPPORT__
extern S32 srv_cloud_setopt_vcard(const srv_cloud_opt_struct *option);
#endif

#ifdef __SMS_CLOUD_SUPPORT__
extern S32 srv_cloud_setopt_sms(const srv_cloud_opt_struct *option);
#endif
extern S32 srv_cloud_init_backup_list(S32 hdl);

extern S32 srv_cloud_binary_search(srv_cloud_sort_item_struct * array, U32 key,int n);
#ifdef __MMI_CLOUD_VPP_UPGRADE__
extern S32 srv_cloud_upgrade_plugin();
#endif

#define __BACKUP_RESTOE_UID_FUNCTION__
extern U32 srv_cloud_gen_hash_value(srv_cloud_uid_struct * uid);
extern MMI_BOOL srv_cloud_insert_sort_list(U16 index, U32 hash, srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_del_sort_list(U16 index, srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_update_sort_list(U16 index, U32 hash, srv_cloud_type_enum type);

extern void srv_cloud_store_is_change_flag(srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_add_item_check(U16 index, srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_del_item_check(U16 index, srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_update_item_check(U16 index, srv_cloud_type_enum type);
extern void srv_cloud_update_nvram(U16 index, srv_cloud_type_enum type);
extern void srv_cloud_del_nvram(U16 index, srv_cloud_type_enum type);
extern void srv_cloud_add_nvram(U16 index, srv_cloud_type_enum type);
extern MMI_BOOL srv_cloud_gen_uid(srv_cloud_uid_struct * uid, srv_cloud_type_enum type);
extern void srv_cloud_store_uid_account(srv_cloud_type_enum type);
extern void srv_cloud_store_ctag(U8* ctag);
extern void srv_cloud_update_etag(CHAR * tag);
extern mmi_ret srv_cloud_async_add_item(mmi_event_struct *param);



#define __BACKUP_RESTORE_NETWORK_FUCNTION__
extern void srv_cloud_post_backup_item_done_evt(srv_cloud_type_enum type, S16 result);
extern void srv_cloud_post_async_done_evt(srv_cloud_type_enum type);

#ifdef __VCARD_CLOUD_SUPPORT__
extern S32 srv_cloud_setup_bearer(void);
extern mmi_ret srv_cloud_bearer_info_ind(mmi_event_struct * evt);
extern S32 srv_cloud_get_proxy_info(void);
extern U8 srv_cloud_get_host_by_name_ind(void *msg);
extern void srv_cloud_set_channel_req(srv_cloud_type_enum type);
extern void srv_cloud_set_channel_rsp_hdlr(void * info);
extern void srv_cloud_send_remove_channel_req(void);
extern void srv_cloud_remove_channel_rsp_hdlr(void * info);



#define __BACKUP_RESTORE_FILE_SYSTEM__
extern S32 srv_cloud_open_file(WCHAR * filename, CHAR * name_buf);
extern MMI_BOOL srv_cloud_compose_file_name(WCHAR * filename, CHAR * name_buf);
extern S32 srv_cloud_async_write_file(S32 file, const U8* buf, U32 len, U16 index, fs_async_callback callback);
extern S32 srv_cloud_fs_async_put_data_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data);
extern MMI_BOOL srv_cloud_backup_file_exist(const WCHAR *filename);
extern U32 srv_cloud_parse_server_data(void *data, const vcrd_uri_struct *uri, const vcrd_prop_set_struct *results);
extern S32 srv_cloud_fs_async_get_data_cb(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data);




#define __BACKUP_RESTORE_GET_SEND_DATA__
extern MMI_BOOL srv_cloud_get_uid_list(U8 * url, U32 url_len);
extern void srv_cloud_method_rsp_hdlr(void * info);
extern U32 srv_cloud_handle_uid(void *data, const vcrd_uri_struct *uri, const vcrd_prop_set_struct *results);
extern void srv_cloud_post_pause_evt(void);
extern void srv_cloud_abort_rsp_hdlr(void * info);
extern void srv_cloud_progress_ind_hdlr(void * info);
extern mmi_ret srv_cloud_store_pause_hdlr(mmi_event_struct *param);
extern void srv_cloud_send_data( U16 index );
extern void srv_cloud_get_data_from_server(void );
extern U32 srv_cloud_write_uid_file(WCHAR * name);
#endif


typedef void (*srv_cloud_schdl_funcptr_type)(void *data);

extern U32 srv_cloud_schdl_start_job(srv_cloud_schdl_funcptr_type callback, void *user_data);
extern void srv_cloud_schdl_stop_job(U32 req_id);

#endif

#endif /* __CLOUD_SUPPORT__ */
