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

#ifndef VM_SOCK_SDK_H
#define VM_SOCK_SDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/* connected status */
#define VM_TCP_EVT_CONNECTED	1

/* write status */
#define VM_TCP_EVT_CAN_WRITE	2

/* read status */
#define VM_TCP_EVT_CAN_READ		3

/* broken status */
#define VM_TCP_EVT_PIPE_BROKEN	4

/* not find host */
#define VM_TCP_EVT_HOST_NOT_FOUND	5

/* tcp pipe closed */
#define VM_TCP_EVT_PIPE_CLOSED	6

/* no enough resource to create tcp connection */
#define VM_TCP_ERR_NO_ENOUGH_RES	-1

/* create tcp connection failed */
#define VM_TCP_ERR_CREATE_FAILED	-2

/* use cmnet to connect */
#define VM_TCP_APN_CMNET		(1)

/* use cmwap to connect */
#define VM_TCP_APN_CMWAP		(2)

/* use wifi to connect */
#define VM_TCP_APN_WIFI		(3)

/* only use cmnet to connect */
#define VM_TCP_APN_CMNET_ONLY (4)

/* only use cmwap to connect */
#define VM_TCP_APN_CMWAP_ONLY (5)

/* only use when conbined with vm_dtacct_set */
#define VM_APN_USER_DEFINE (6)



/* write status */
#define VM_UDP_EVT_WRITE	2

/* read status */
#define VM_UDP_EVT_READ		3

/* broken status */
#define VM_UDP_EVT_PIPE_BROKEN	4

/* udp pipe closed */
#define VM_UDP_EVT_PIPE_CLOSED	6


typedef struct  
{
	VMINT		apn_info_id;
	VMINT		proxy_port;
	VMCHAR     operator_id[8];
	VMCHAR     operator_name[64];
	VMCHAR     proxy_ip[16];
	VMCHAR     apn_proxy[32];
	VMCHAR     apn_no_proxy[32];
	VMCHAR     user_name[16];
	VMCHAR     pass_word[16];
}vm_apn_info_ext;

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_connect
 * DESCRIPTION
 *  create tcp connection.
 * PARAMETERS
 *  host : [IN] dest host ip.
 *  port : [IN] dest host port.
 *  apn : [IN] apn id, only support VM_TCP_APN_CMNET,VM_TCP_APN_CMWAP,VM_TCP_APN_WIFI.
 *  callback : [IN] callback function for tcp connection.
 * RETURNS
 *  create tcp success or not.
 * RETURN VALUES
 *  tcp handle, if value >=0, that is right, else is wrong
*****************************************************************************/
VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn,
	void (*callback)(VMINT handle, VMINT event));

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_close
 * DESCRIPTION
 *  close tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
*****************************************************************************/
void vm_tcp_close(VMINT handle);

#define VM_TCP_READ_EOF				(-1)

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_read
 * DESCRIPTION
 *  read data from tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
 *  buf : [OUT] data buffer.
 *  len : [OUT] data length.
 * RETURNS
 *  read data size.
 * RETURN VALUES
 *  read size, if value = VM_TCP_READ_EOF, means finishing reading.
*****************************************************************************/
VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len);

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_write
 * DESCRIPTION
 *  write data to tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
 *  buf : [IN] data to write.
 *  len : [IN] data length.
 * RETURNS
 *  write data success or not.
 * RETURN VALUES
 *  if value >= 0 , it is right, else is wrong.
*****************************************************************************/
VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len);


/*****************************************************************************
 * FUNCTION
 *    vm_is_support_wifi
 * DESCRIPTION
 *  query wifi support.
 * RETURNS
 *  support or not support wifi.
 * RETURN VALUES
 *  TRUE : support wifi
 *  FALSE : not support wifi
*****************************************************************************/
VMINT vm_is_support_wifi(void);


/*****************************************************************************
 * FUNCTION
 *    vm_wifi_is_connected
 * DESCRIPTION
 *  query wifi contect.
 * RETURNS
 *  contected or not contected wifi.
 * RETURN VALUES
 *  TRUE : wifi contect.
 *  FALSE : wifi not contected.
*****************************************************************************/
VMINT vm_wifi_is_connected(void);


/*****************************************************************************
 * FUNCTION
 *  vm_get_apn_info
 * DESCRIPTION
 *  Get Apn info after network connected
 * PARAMETERS
 *  current_apn_info : [OUT] apn info of current connection
 * RETURNS
 *  0 means successful
 * RETURN VALUES
 *  0 : successful
*****************************************************************************/
VMINT vm_get_apn_info(vm_apn_info_ext *current_apn_info);

/*****************************************************************************
 * FUNCTION
 *    vm_get_default_apn_info
 * DESCRIPTION
 *  get current default apn infomation.
 * RETURNS
 *  avaliable or not.
 * RETURN VALUES
 *  0 sucess, else failure
*****************************************************************************/
VMINT vm_get_default_apn_info( vm_apn_info_ext *apn_info);


#define VM_SOC_DNS_MAX_ADDR 5

/* Socket return codes, negative values stand for errors */
typedef enum
{
    VM_E_SOC_SUCCESS           = 0,     /* success */
    VM_E_SOC_ERROR             = -1,    /* error */
    VM_E_SOC_WOULDBLOCK        = -2,    /* not done yet */
    VM_E_SOC_LIMIT_RESOURCE    = -3,    /* limited resource */
    VM_E_SOC_INVALID_SOCKET    = -4,    /* invalid socket */
    VM_E_SOC_INVALID_ACCOUNT   = -5,    /* invalid account id */
    VM_E_SOC_NAMETOOLONG       = -6,    /* address too long */
    VM_E_SOC_ALREADY           = -7,    /* operation already in progress */
    VM_E_SOC_OPNOTSUPP         = -8,    /* operation not support */
    VM_E_SOC_CONNABORTED       = -9,    /* Software caused connection abort */
    VM_E_SOC_INVAL             = -10,   /* invalid argument */
    VM_E_SOC_PIPE              = -11,   /* broken pipe */
    VM_E_SOC_NOTCONN           = -12,   /* socket is not connected */
    VM_E_SOC_MSGSIZE           = -13,   /* msg is too long */
    VM_E_SOC_BEARER_FAIL       = -14,   /* bearer is broken */
    VM_E_SOC_CONNRESET         = -15,   /* TCP half-write close, i.e., FINED */
    VM_E_SOC_DHCP_ERROR        = -16,   /* DHCP error */
    VM_E_SOC_IP_CHANGED        = -17,   /* IP has changed */
    VM_E_SOC_ADDRINUSE         = -18,   /* address already in use */
    VM_E_SOC_CANCEL_ACT_BEARER = -19    /* cancel the activation of bearer */
} vm_soc_error_enum;


typedef struct
{
    VMUINT address[VM_SOC_DNS_MAX_ADDR];
    VMINT num;
    VMINT error_cause; /* vm_ps_cause_enum */
}vm_soc_dns_result;
/*
VMINT vm_soc_get_host_by_name(const VMCHAR * host,
                                                            VMBYTE * addr,
                                                            VMBYTE * addr_len,
                                                            VMINT (*callback)(VMBYTE * addr, VMINT addr_len));
*/          
    
/*****************************************************************************
 * FUNCTION
 *  vm_soc_get_host_by_name
 * DESCRIPTION
 *  this function retrieves IP addresses associated with the specified host name. 
 * PARAMETERS
 * apn : [IN] 
 * host : [IN] domain to be resolved.
 * result : [OUT] DNS parsed result.
 * callback : [IN] point to the callback.
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :			     Get IP address successfully, result is filled.
 *  VM_E_SOC_WOULDBLOCK :		     wait response from network, result could be gotten from callback.
 *  VM_E_SOC_INVAL :			         invalid arguments: null domain_name, etc.
 *  VM_E_SOC_ERROR :			         unspecified error
 *  VM_E_SOC_LIMIT_RESOURCE :		 socket resources not available
 *  VM_E_SOC_INVALID_ACCOUNT :      invalid data account id
*****************************************************************************/
VMINT vm_soc_get_host_by_name(VMINT apn, 
                                                                            const VMCHAR * host, 
                                                                            vm_soc_dns_result * result, 
                                                                            VMINT (*callback)(vm_soc_dns_result *));
                                                                            
/*****************************************************************************
 * FUNCTION
 *  vm_get_encoded_dtacct_id
 * DESCRIPTION
 *  this function retrieves data account id. 
 * PARAMETERS
 * apn : [IN] apn id, only support VM_TCP_APN_CMNET, VM_TCP_APN_WIFI
 * dtacct_id : [OUT] point to data account id.
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
*  VM_E_SOC_SUCCESS :               Get IP address successfully, result is filled.
*  VM_E_SOC_INVAL :                     invalid arguments: null domain_name, etc.
*  VM_E_SOC_INVALID_ACCOUNT :      invalid data account id
*****************************************************************************/
VMINT vm_get_encoded_dtacct_id(VMINT apn, VMUINT * dtacct_id);







#define VM_WLAN_LOC_MAC_ADDR_LEN 6
#define VM_WLAN_LOC_MAX_AP_LIST_NUM 30

typedef enum
{
    VM_WLAN_LOC_ERR_LOGICAL = -7,
    VM_WLAN_LOC_ERR_INTERNAL, 
    VM_WLAN_LOC_ERR_BUSY,
    VM_WLAN_LOC_ERR_BAD_PARAM,
    VM_WLAN_LOC_ERR_NO_RESOURCE,
    VM_WLAN_LOC_ERR_NOT_SUPPORT,
    VM_WLAN_LOC_ERR_NO_AUTHORIZATION,
    VM_WLAN_LOC_ERR_SUCCESS = 0
}vm_wlan_loc_error_t;

typedef enum
{
    VM_WLAN_LOC_SCAN_RESULT_SUCCESS = 0,   /* WLAN scan success */
    VM_WLAN_LOC_SCAN_RESULT_FAILED,        /* WLAN scan failed */
    VM_WLAN_LOC_SCAN_RESULT_ABORTED,       /* WLAN scan service is aborted */
    VM_WLAN_LOC_SCAN_RESULT_TOTAL
} vm_wlan_loc_scan_result_enum;

typedef struct
{
    VMUINT8 bssid[VM_WLAN_LOC_MAC_ADDR_LEN]; /* MAC address */
    VMINT rssi;
}vm_wlan_loc_supc_abm_bss_info_struct;

typedef struct
{
    const vm_wlan_loc_supc_abm_bss_info_struct * ap_list[VM_WLAN_LOC_MAX_AP_LIST_NUM]; /* bss info array */
    VMINT handle;
    vm_wlan_loc_scan_result_enum result;     /* scan result enum */
    VMUINT8 ap_list_num;/* total num of searched ap list */
}vm_wlan_loc_data_t;


/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_search
 * DESCRIPTION
 *  The function is used to scan the AP list for applications.
 * PARAMETERS
 *  callback    :   [IN]    scan result callback notify function for APP
 *  user_data   :   [IN]    application piggyback data
 * RETURNS
 *  return value >= 0 : search handle id created successfully.
 *  return value < 0 : failure
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BUSY : busy, could retry later
 *  VM_WLAN_LOC_ERR_NO_RESOURCE : no avalible resource
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
*****************************************************************************/
VMINT vm_wlan_loc_search(void (*callback)(vm_wlan_loc_data_t * data, void * user_data), void * user_data);

/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_search_abort
 * DESCRIPTION
 *  The function is used to abort the scanning AP list process for applications.
 * PARAMETERS
 *  handle  :   [IN]    created handle id from calling vm_wlan_loc_search
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BAD_PARAM : invalid input param
 *  VM_WLAN_LOC_ERR_NO_RESOURCE : no avalible resource
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
 *****************************************************************************/
VMINT vm_wlan_loc_search_abort(VMINT handle);

/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_get_connected_info
 * DESCRIPTION
 *  The function get info form ap which connected already
 * PARAMETERS
 * rssi : [OUT] rssi
 * bssid : [OUT] bssid
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BAD_PARAM : invalid input param
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
 *  VM_WLAN_LOC_ERR_LOGICAL : maybe not connected
*****************************************************************************/
VMINT vm_wlan_loc_get_connected_info(vm_wlan_loc_supc_abm_bss_info_struct * info);

typedef enum
{
    E_PRELOAD_QUERYING,
    E_PRELOAD_AVAILABLE_UPDATE,
    E_PRELOAD_NO_UPDATE,
    E_PRELOAD_CONNECTING,
    E_PRELOAD_CONNECTED,
    E_PRELOAD_DOWNLOADING,
    E_PRELOAD_DOWNLOADED,
    E_PRELOAD_HOST_NOT_FOUND,
    E_PRELOAD_PIPE_CLOSED,
    E_PRELOAD_PIPE_BROKEN,
    E_PRELOAD_FAILURE,
    E_PRELOAD_ERR_PATH,
    E_PRELOAD_ABORT,
}vm_preload_state_e;

typedef struct
{
    VMUINT app_id;
//    VMCHAR ver[8];
//    VMCHAR imsi[32];
//    VMCHAR imei[32];
    VMCHAR * ua;
    /*
    VMCHAR sc[16];
    VMBYTE skb;
    VMBYTE stch;
    VMBYTE sgs;
    VMBYTE scs;
    VMINT w;
    VMINT h;
    */
}vm_preload_query_info_t;

typedef struct
{
    vm_preload_state_e state;
    void * user_data;
}vm_common_t;


/*
state in below
E_PRELOAD_DOWNLOADING,
E_PRELOAD_DOWNLOADED,
*/
typedef struct
{
    vm_common_t head;
    VMINT received;
    VMINT total;
}vm_preload_recv_data_t;

VMINT vm_preload_query(VMINT apn,
                       const VMCHAR * url, 
                       VMINT port,
                       const vm_preload_query_info_t * info,
                       void (*callback)(VMINT hdl, void * para), 
                       void * user_data);
                              
VMINT vm_preload_download_ex(VMINT hdl, const VMWCHAR * data, VMBOOL bDLA,void (*callback)(VMINT hdl, void * para), void * user_data);

VMINT vm_preload_download(VMINT hdl, const VMWCHAR * data, void (*callback)(VMINT hdl, void * para), void * user_data);

VMINT vm_preload_cancel(VMINT hdl);


#define VM_MAX_SOCK_ADDR_LEN 28

typedef struct 
{
    VMINT16	addr_len; /* address length */
    VMUINT16	port; /* port number */
    VMUINT8	addr[VM_MAX_SOCK_ADDR_LEN];
} vm_sockaddr_struct;

/*****************************************************************************
 * FUNCTION
 *    vm_udp_create
 * DESCRIPTION
 *  create udp socket.
 * PARAMETERS
 *  port : [IN] port number for binding.
 *  apn : [IN] apn id.
 *  callback : [IN] callback function for udp notification.
 *  loopback : [IN] loopback flag, non-zero: loopback; zero: no loopback.
 * RETURNS
 *  create udp success or not.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_create(VMINT port, VMINT apn, void (*callback)(VMINT hdl, VMINT event), VMINT loopback);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_sendto
 * DESCRIPTION
 *  send data to the destination.
 * PARAMETERS
 *  hdl : [IN] udp handle.
 *  buf : [IN] buf.
 *  len : [IN] buf len.
 *  addr : [IN] the address of destination.
 * RETURNS
 *  size of sent data.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_sendto(VMINT hdl, const void * buf, VMINT32 len, const vm_sockaddr_struct * addr);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_recvfrom
 * DESCRIPTION
 *  receive data from the destination.
 * PARAMETERS
 *  hdl : [IN] udp handle.
 *  buf : [OUT] buf.
 *  len : [IN] buf len.
 *  addr : [OUT] the address of destination.
 * RETURNS
 *  size of received data.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_recvfrom(VMINT hdl, void * buf, VMINT32 len, vm_sockaddr_struct * addr);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_close
 * DESCRIPTION
 *  create udp socket.
 * PARAMETERS
 *  port : [IN] dest host port.
 *  apn : [IN] apn id.
 *  callback : [IN] callback function for udp notification.
 * RETURNS
 *  create udp success or not.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_close(VMINT hdl);



typedef enum
{
    VM_NETWORK_NONE = 0, /* No bit-wise operation for none case */
    VM_GSM = 0x0100, /* GSM protocol */
    VM_WCDMA = 0x0200, /* WCDMA protocol */
    VM_NETWORK_END_OF_ENUM /* reserved */
}vm_network_enum_t;

/*****************************************************************************
 * FUNCTION
 *  vm_srv_nw_info_get_protocol
 * DESCRIPTION
 *  Get the protocol of current network.
 * PARAMETERS
 *  sim_card : [IN] SIM index, eg: 0x1-SIM1, 0x2-SIM2
 * RETURNS
 *  vm_network_enum_t
 * RETURN VALUES
 *  VM_GSM, VM_WCDMA, failure if less than 0
 *****************************************************************************/
VMINT vm_srv_nw_info_get_protocol(VMINT sim_card);


typedef enum
{
    VM_NETWORK_CAPABILITY_NONE = 0,
    VM_GPRS  = 0x0010,
    VM_EDGE  = 0x0020,
    VM_HSDPA = 0x0040,
    VM_HSUPA = 0x0080,
    VM_NETWORK_CAPABILITY_END_OF_ENUM
} vm_network_capability_enum;

/*****************************************************************************
 * FUNCTION
 *  vm_srv_nw_info_get_protocol
 * DESCRIPTION
 *  Query if current channel supports the capability.
 * PARAMETERS
 *  sim         : [IN] Which protocol layer of SIM
 *  type        : [IN] Protocol capability. refer to vm_network_capability_enum
 * RETURNS
 *  -1: no authorization
 *  -2: invalid param
 *  not support if 0, else support.
 *****************************************************************************/
VMINT vm_srv_nw_info_channel_supports(VMINT sim_card, vm_network_capability_enum type);


/*****************************************************************************
 * FUNCTION
 *  vm_dtacct_set
 * DESCRIPTION
 *  set the current data account info that got from vm_dtacct_select. if app need to do connection 
 *  use this data account of the sim_id, VM_APN_USER_DEFINE should be passed as apn param. eg, 
 *  vm_tcp_connect(xx, xxx, VM_APN_USER_DEFINE, xxxx);
 * PARAMETERS
 *  sim_id : [IN] SIM index, eg: 0-SIM1, 1-SIM2, ...
 *  dtacct : [IN] account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_dtacct_set(VMINT sim_id, VMUINT32 dtacct);

/*****************************************************************************
 * FUNCTION
 *  vm_dtacct_select
 * DESCRIPTION
 *  show the current available data account list of the required sim_id. call back app when user selected
 *  one of them. app may record this data account value, for the vm_dtacct_set if necessary.
 * PARAMETERS
 *  sim_id : [IN] SIM index, eg: 0-SIM1, 1-SIM2, ...
 *  dtacct : [IN] account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_dtacct_select(VMINT sim_id, VMINT (*callback)(VMUINT32 dtacct));



typedef enum 
{
    VM_RES_TYPE_TCP,
    VM_RES_TYPE_UDP,
    VM_RES_TYPE_HTTP,
    VM_RES_TYPE_HTTPS
}vm_res_type_t;

/*****************************************************************************
 * FUNCTION
 *  vm_cbm_hold_bearer
 * DESCRIPTION
 *  hold the bearer.
 * PARAMETERS
 *  type : [IN] vm_res_type_t
 *  hdl : [IN] TCP : hdl = vm_tcp_connect
 *               UDP : hdl = vm_udp_create
 *               HTTP : hdl = vm_http_get_current_handle
 *                         hdl = vm_http_fetch_handle
 *               HTTPS : channel id
 * RETURN VALUES
 *  success if 0, failure if less than 0
 *****************************************************************************/
VMINT vm_cbm_hold_bearer(vm_res_type_t type, VMINT hdl);

/*****************************************************************************
 * FUNCTION
 *  vm_cbm_release_bearer
 * DESCRIPTION
 *  hold the bearer.
 * RETURN VALUES
 *  success if 0, failure if less than 0
 *****************************************************************************/
VMINT vm_cbm_release_bearer(void);


#define VM_SRV_DTCNT_PROF_MAX     (32)
#define VM_SRV_DTCNT_IP_MAX     (64)

typedef struct
{
    VMUINT8 APN[VM_SRV_DTCNT_PROF_MAX];    /* account name */
    VMUINT8 PrimaryAddr[VM_SRV_DTCNT_IP_MAX];    /* Primary DNS IP Address (ASCII) */
    VMUINT8 use_proxy;   /* use proxy flag */
    VMUINT8 UserName[VM_SRV_DTCNT_PROF_MAX];         /* User string of a Data Account (ASCII) */
    VMUINT8 Passwd[VM_SRV_DTCNT_PROF_MAX];             /* Password for a Data Account (ASCII) */
    VMUINT8 px_addr[VM_SRV_DTCNT_IP_MAX];         /* proxy addr string IP format (ASCII)*/
    VMUINT16 px_port;                                        /* proxy port */
}vm_dtcnt_info_t;

/*****************************************************************************
 * FUNCTION
 *  vm_set_cust_apn_info
 * DESCRIPTION
 *  set customized apn info. if successful, it will output data account(*dtacct) which value could be 
 * passed to 'vm_dtacct_set'. VM_APN_USER_DEFINE should be the param when do operation of network.
 * PARAMETERS
 *  info : [IN] refer to vm_dtcnt_info_t
 *  dtacct : [OUT] data account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_set_cust_apn_info(const vm_dtcnt_info_t * info, VMUINT32 * dtacct);

/*****************************************************************************
 * FUNCTION
 *  vm_get_cust_apn_info
 * DESCRIPTION
 *  get customized apn info. 
 * PARAMETERS
 *  info : [IN] refer to vm_dtcnt_info_t
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_get_cust_apn_info(vm_dtcnt_info_t * info);


/*****************************************************************************
 * FUNCTION
 *  vm_wlan_perfer
 * DESCRIPTION
 *  disable wlan perfer. 
 * PARAMETERS
 *  disable : [IN] disable if no-zero, or else is default.
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_wlan_perfer(VMINT disable);


#ifdef __cplusplus
}
#endif

#endif /* VM_SOCK_SDK_H */
