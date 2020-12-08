#ifndef __SNS_SRV_DS_MGR_H__
#define __SNS_SRV_DS_MGR_H__

#include "SnsDataStorage.h"

typedef enum {
    SNS_DS_EMPTY,
    SNS_DS_INIT,
    SNS_DS_READY,
    SNS_DS_RUNNING,
    SNS_DS_DEINIT,
} sns_ds_state;

typedef enum {
    SNS_DS_OP_SELECT,
    SNS_DS_OP_INSERT,
    SNS_DS_OP_UPDATE,
    SNS_DS_OP_DELETE,
    SNS_DS_OP_LOGOUT,
    SNS_DS_OP_LOGIN,
} sns_ds_op;

typedef enum {
    SNS_DS_REQ_STATUS_QUEUED,
    SNS_DS_REQ_STATUS_RUNNING,
    SNS_DS_REQ_STATUS_DONE
} sns_ds_req_status;

typedef void (*sns_ds_cleanup_func)(void *data);

typedef struct {
    U32 provider;
    U32 count;
    void *data;
    srv_sns_ds_refresh_enum refresh;
    sns_ds_cleanup_func cleanup;
} sns_ds_insert_struct;

struct sns_ds_request;

typedef void (*sns_ds_callback)(struct sns_ds_request *ds_req, sns_ds_req_status msg, void *arg);

typedef struct sns_ds_request {
    sns_ds_op op;
    srv_sns_tables_enum table;
    union {
        srv_sns_ds_filter_struct filter; // SNS_DS_OP_SELECT, SNS_DS_OP_DELETE
        srv_sns_ds_update_struct update; // SNS_DS_OP_UPDATE
        sns_ds_insert_struct insert;     // SNS_DS_OP_INSERT
        U32 provider;                    // SNS_DS_OP_LOGOUT
    } arg;
    sns_ds_callback callback;
    void *user_data;
    sns_ds_req_status status;
} sns_ds_request_struct;

typedef struct sns_ds_result {
    S32 result;
    srv_sns_ds_rsp_data_struct *rsp;
} sns_ds_result_struct;

typedef void (*sns_ds_init_cb_func)(S32 result);
typedef void (*sns_ds_deinit_cb_func)(void);

void sns_ds_init(sns_ds_init_cb_func callback);
void sns_ds_query(srv_sns_tables_enum table, srv_sns_ds_filter_struct *filter, sns_ds_callback callback, void *user_data);
void sns_ds_insert(srv_sns_tables_enum table, U32 provider, U32 count, void *input, srv_sns_ds_refresh_enum refresh, sns_ds_cleanup_func cleanup, sns_ds_callback callback, void *user_data);
void sns_ds_update(srv_sns_tables_enum table, srv_sns_ds_update_struct *update, sns_ds_callback callback, void *user_data);
void sns_ds_delete(srv_sns_tables_enum table, srv_sns_ds_filter_struct *filter, sns_ds_callback callback, void *user_data);
void sns_ds_logout(U32 provider, sns_ds_callback callback, void *user_data);
void sns_ds_login(U32 provider);
void sns_ds_cancel(void *user_data);
void sns_ds_deinit(sns_ds_deinit_cb_func callback);

#endif
