/**********************************************************************************
*Filename:     kjx_socket.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if !defined(KJX_SOCKET_H)
#define KJX_SOCKET_H

#if defined(__KJX_FUN__)

#include "DtcntSrvGprot.h"
#include "DtcntSrvIntStruct.h"
#include "DtcntSrvIprot.h"
#include "kal_general_types.h"

#define KJX_SOCKET_RECV_BUFF_SIZE 1024*8
#define KJX_SOCKET_SEND_BUFF_SIZE 1024*2
typedef void (*kjxPsFunc) (void);
typedef void (*set_data_acc_rsp) (void *,void *,void *,int);

/* mmi_soc_demo_app_enum */
typedef enum
{ 
    KJX_SOC_PRO=0x12,
    KJX_SOC_AGPS=0x11,
    KJX_SOC_MAX
} kjx_access_id;

typedef enum
{
  KJX_ACTIVE_CARD_EMPTY = 0,
  KJX_ACTIVE_CARD_SIM1,
  KJX_ACTIVE_CARD_SIM2
}kjx_sim_enum;
/***************************************************************************************/

/***************************************************************************************/
typedef void (*socket_notify) (void);
typedef void (*socket_notify_point) (void *);
typedef void (*socket_notify_id) (kal_int8);
typedef void (*socket_event_void) (void);
typedef kal_int8 (*socket_event_1)(U32);
typedef kal_int8 (*socket_event_2)(kal_int8, U8*, U16);
typedef kal_int8 (*socket_event_3)(kal_int8, const S8*, S32);
typedef kal_int8 (*socket_event_4)(kal_int8);
typedef kjx_sim_enum (*socket_active_card)(void);
typedef srv_dtcnt_result_enum (*socket_net_1)(void *,S8 *, U32 *, S8 ,U8 );
typedef MMI_BOOL (*socket_net_2)(void);
typedef srv_dtcnt_account_info_st* (*socket_net_3)(S8 *, S8 );
typedef int (*socket_net_4) (void *,U8 *, U8 *, srv_dtcnt_prof_gprs_auth_type_enum , U8 *, U8 *, U8 *, U8 ,U8 * );
typedef void (*socket_net_5)(void *,U32 , kal_int32 , const S8 *,kal_uint16 , char );
typedef kal_int32 (*socket_net_6) (void *,void*);
typedef void (*socket_net_point) (void *);
typedef void (*socket_recvbuf) (kal_int32 );
typedef void (*gps_work_mode)(S32);

typedef struct
{
    socket_notify_id socket_notify_read;//void (*socket_notify_read)(void);
    socket_notify socket_notify_write;//void (*socket_notify_write)(void);
    socket_notify socket_notify_accept;//void (*socket_notify_accept)(void);
    socket_notify_id socket_notify_connect;//void (*socket_notify_connect)(void);
    socket_notify socket_notify_close;//void (*socket_notify_close)(void);
    socket_notify socket_notify_default;//void (*socket_notify_default)(void);
    socket_notify_point socket_notify_notify;//void (*socket_notify_notify)(void *inMsg);
    socket_notify_id socket_notify_error;//void (*socket_notify_error)(void);
} kjx_socket_notify_func;

typedef struct
{
    socket_event_void socket_restart;//void (*socket_restart)(void);
    socket_event_1 socket_event_create;//kal_int8 (*socket_event_create)(U32 account_id);
    socket_event_2 socket_event_connect;//kal_int8 (*socket_event_connect)(kal_int8 socketId, U8 ip[], U16 port);
    socket_event_3 socket_event_send;//kal_int8 (*socket_event_send)(kal_int8 socketId, const S8 *buf, S32 len);
    socket_event_3 socket_event_recv;//kal_int8 (*socket_event_recv)(kal_int8 socketId, const S8 *buf, S32 len);
    socket_event_4 socket_event_close;//kal_int8 (*socket_event_close)(kal_int8 socketId);
    socket_active_card get_active_card;//kjx_sim_enum (*get_active_card)(void);
    socket_net_1 get_acc_id_by_apn;//srv_dtcnt_result_enum (*get_acc_id_by_apn)(void *socket_func,S8 *apn, U32 *acc_id_out, S8 SimId,U8 app_id);
    socket_net_2 store_status_check;//MMI_BOOL (*store_status_check)(void);
    socket_net_3 store_get_acc_info_by_apn;//srv_dtcnt_account_info_st (*store_get_acc_info_by_apn)(S8 *apn, S8 SimId);
    socket_net_4 gprs_data_account_req;//int (*gprs_data_account_req) (void *socket_func,U8 *name, U8 *apn, srv_dtcnt_prof_gprs_auth_type_enum auth_type, U8 *user_name, U8 *passwd, U8 *dns, U8 proxy,U8 * proxy_add);
    socket_net_5 get_host_by_name_req;//void (*get_host_by_name_req)(void *socket_func,U32 acctId, kal_int32 request_id, const S8 *hostName,kal_uint16 dstPort, char access_id);
    socket_net_point get_host_by_name_rsp;//void (*get_host_by_name_rsp)(void* inMsg);
    socket_event_void socket_get_host_fail;//void (*socket_get_host_fail)(void);
    socket_net_6 socket_connect_again;//kal_int32 (*socket_connect_again)(void* socket_event_func);
    socket_event_void socket_connet_success;//void (*socket_connet_success)(void);
    socket_event_void socket_connet_wouldblock;//void (*socket_connet_wouldblock)(void);
    socket_event_void socket_connet_error;//void (*socket_connet_error)(void);
    socket_notify_id socket_get_host_error;//void (*socket_get_host_error)(void);
    socket_event_void socket_login_again;
    socket_recvbuf recvbuf_hex_to_acsii;//void kjx_socket_recvbuf_hex_to_acsii(kal_int32 len)
    socket_event_void socket_send_gps;
    gps_work_mode handle_gps_work_mode;
} kjx_socket_event_func;

typedef struct
{
	kal_int8 socket_id;
	kal_int8 access_id;
	kal_int8 app_id;
	S8 pRecvBuff[KJX_SOCKET_RECV_BUFF_SIZE];
	S8 pSendBuff[KJX_SOCKET_SEND_BUFF_SIZE];
	kal_int32 totalSize;
} kjx_socket_context;


/*********************************************************************************/
#endif/*__KJX_FUN__*/
#endif/*KJX_SOCKET_H*/

