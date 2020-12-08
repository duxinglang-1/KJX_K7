#ifndef __SNS_SRV_PLUGIN_MGR_H__
#define __SNS_SRV_PLUGIN_MGR_H__

#include "SnsSrvController.h"

#define SNS_PLUGIN_FOLDER     L"mre_sns"
#define SNS_PLUGIN_PATH       "%c:\\%w\\"
#ifdef WIN32
#define SNS_PLUGIN_EXT L"*.dll"
#else
#define SNS_PLUGIN_EXT L"*.vpp"
#endif
#define SNS_PLUGIN_FREE_LIBRARY_TIMER_INTERVAL 60000

typedef enum {
    SNS_PLUGIN_PRIORITY_HIGH,
    SNS_PLUGIN_PRIORITY_MEDIUM,
    SNS_PLUGIN_PRIORITY_LOW,
    SNS_PLUGIN_PRIORITY_TOTAL
} sns_plugin_priority_enum;

typedef enum {
    SNS_PLUGIN_REQ_STATE_PENDING,
    SNS_PLUGIN_REQ_STATE_RUNNING,
    SNS_PLUGIN_REQ_STATE_DONE,
} sns_plugin_req_state_enum;

typedef struct sns_plugin_req {
    S32 id;
    U32 provider;   
    S32 process_id;
    sns_plugin_priority_enum priority;
    sns_plugin_req_state_enum state;
    void *func;
    srv_sns_result result;
    U32 count;
    U32 paging;
    void *data;
} sns_plugin_req_struct;

typedef struct sns_plugin_preload_vpp {
    U32 provider;
    const U8 *(*func)(void);
} sns_plugin_preload_vpp_struct;

typedef struct sns_plugin_preload_dll {
    U32 provider;
    const U8 *(*func)(void);
    WCHAR filename[64];
    const U8 *addr;
    U32 size;
} sns_plugin_preload_dll_struct;

#define SNS_PLUGIN_INVOKE_PREPARE(library) vm_pmng_set_ctx(library)
#define SNS_PLUGIN_INVOKE_FINISH(library) vm_pmng_reset_ctx()

void sns_plugin_discover(void);
void sns_plugin_check(void);
void sns_plugin_add_request(sns_process_struct *process, U32 provider);
void sns_plugin_remove_reqs_by_process(S32 process_id);
void sns_plugin_remove_reqs_by_provider(U32 provider);
void sns_plugin_result_callback(S16 result, S32 req_id);
void sns_plugin_data_callback(S16 result, U32 count, void *data, U32 paging, S32 req_id);
void sns_plugin_deinit(srv_sns_result reason);
MMI_BOOL sns_plugin_upgrade(U32 provider, WCHAR *path);

#endif
