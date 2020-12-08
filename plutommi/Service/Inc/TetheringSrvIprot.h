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
 *  TetheringSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * internet connection sharing service internal prototype header.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __TETHERING_SRV_IPROT_H__
#define __TETHERING_SRV_IPROT_H__

#include "mmi_features.h"
#ifdef __MMI_TETHERING__
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "hostap_abm_msgs.h"
#include "TetheringSrvGprot.h"

/****************************************************************************
* Define
*****************************************************************************/

/* Max buffer length of SSID */
#define SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN           (HOSTAP_SSID_MAX_LEN + 1)
/* Max buffer length of pre-shared key */
#define SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN            (HOSTAP_PSK_MAX_LEN + 1)
/* Tethering disconnect reactivate time */
#define SRV_TETHERING_MAX_REACTIVATE_TIME               600 //seconds
/* Tethering disconnect reactivated retry times */
#define SRV_TETHERING_MAX_REACTIVATE_RETRY_TIMES        15
/* Tethering disconnect reactivate retry frequency */
#define SRV_TETHERING_MAX_REACTIVATE_RETRY_FREQ         1   //seconds
/* Wi-Fi tethering auto turn off time for power saving */
#define SRV_TETHERING_WIFI_AUTO_TURN_OFF_TIME           90  //seconds

/* Tethering status enum */
typedef enum
{
    SRV_TETHERING_STATUS_SRV_OFF,           /* Tethering service off */
    SRV_TETHERING_STATUS_SRV_ON,            /* Tethering service on */
    SRV_TETHERING_STATUS_ON_SWITCHING_OFF,  /* Tethering on switching off status */
    SRV_TETHERING_STATUS_ON_SWITCHING_ON,   /* Tethering on switching on status */
    SRV_TETHERING_STATUS_END                /* End of tethering status enum */
} srv_tethering_status_enum;

/* Tethering extended status enum */
typedef enum
{
    SRV_TETHERING_EXT_STATUS_NONE,                                      /* Status none */
    SRV_TETHERING_EXT_STATUS_UPDATE_SETTINGS,                           /* On updating settings */
    SRV_TETHERING_EXT_STATUS_SWITCH_ON_ROLL_BACK,                       /* On roll back switch */
    SRV_TETHERING_EXT_STATUS_DEINIT_WLAN,                               /* On deinit Wlan */
    SRV_TETHERING_EXT_STATUS_FORCE_STOP,                                /* Force stop tethering */
    SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_NO_SERVICE,                  /* Network disconnect cause no service */
    SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_CM_DISC,                     /* Network disconnect cause conection management disconnect */
    SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_FLIGHT_MODE,                 /* Network disconnect cause on flight mode */
    SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_SIM_RECOVERY,                /* Network disconnect cause by SIM recovery */
    SRV_TETHERING_EXT_STATUS_NETWORK_DISCONNECT_APP_UNABLE_REACTIVATE,  /* Network disconnect and the application could not reactivate */
    SRV_TETHERING_EXT_STATUS_BEARER_DISCONNECT,                         /* Bearer disconnect */
    SRV_TETHERING_EXT_STATUS_REACTIVATE,                                /* On reactivate */
    SRV_TETHERING_EXT_STATUS_DISCONN_AUTO_RETRY,                        /* Disconnect auto retry */
    SRV_TETHERING_EXT_STATUS_AUTO_TURN_OFF,                             /* Disconnect caused by countdown timeout */
    SRV_TETHERING_EXT_STATUS_END                                        /* End of enum */
} srv_tethering_ext_status_enum;

/* Wi-Fi hotspot auth mode enum */
typedef enum
{
    SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN,       /* Auth mode open network */
    SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK,   /* Auth mode WPA2 pre-shared key */
    SRV_TETHERING_WIFI_HS_AUTH_MODE_TOTAL       /* Total number of auth mode */
} srv_tethering_wifi_hs_auth_mode_enum;

/* Tethering disconnect cause */
typedef enum
{
    SRV_TETHERING_DISCONNECT_CAUSE_NONE,            /* Idle status */
    SRV_TETHERING_DISCONNECT_CAUSE_NETWORK,         /* Disconnect by network problem */
    SRV_TETHERING_DISCONNECT_CAUSE_SIM_OFF,         /* Disconnect by SIM off */
    SRV_TETHERING_DISCONNECT_CAUSE_BEARER,          /* Disconnect by bearer problem */
    SRV_TETHERING_DISCONNECT_CAUSE_CM_DISC,         /* Disconnect by connection management */
    SRV_TETHERING_DISCONNECT_CAUSE_FLIGHT_MODE,     /* Disconnect by turning on flight mode */
    SRV_TETHERING_DISCONNECT_CAUSE_AUTO_TURN_OFF,   /* Disconnect by auto turn off */
    SRV_TETHERING_DISCONNECT_CAUSE_END              /* End of enum */
} srv_tethering_disconn_cause_enum;

/* Tethering launch result value */
typedef enum
{
    SRV_TETHERING_LAUNCH_RESULT_OK                              = 0,    /* Launch OK */
    SRV_TETHERING_LAUNCH_RESULT_ERROR                           = -1,   /* Launch error */
    SRV_TETHERING_LAUNCH_RESULT_ALREADY_ACTIVATED               = -2,   /* Tethering is already activated */
    SRV_TETHERING_LAUNCH_RESULT_ON_SWITCHING                    = -3,   /* Tethering is on switching */
    SRV_TETHERING_LAUNCH_RESULT_WIFI_TETHERING_ACTIVATED        = -4,   /* Wi-Fi tethering is activated (for some conflict case) */
    SRV_TETHERING_LAUNCH_RESULT_USB_TETHERING_ACTIVATED         = -5,   /* USB tethering is activated (for some conflict case) */
    SRV_TETHERING_LAUNCH_RESULT_WLAN_ACTIVATED                  = -6,   /* Wlan is activated (conflict with Wi-Fi tethering) */
    SRV_TETHERING_LAUNCH_RESULT_DIALUP_ACTIVATED                = -7,   /* Dialup is activated (conflict with USB tethering) */
    SRV_TETHERING_LAUNCH_RESULT_UNAVAILABLE_SIM                 = -8,   /* SIM is not available */
    SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY               = -9,   /* Network is not ready (not in full service) */
    SRV_TETHERING_LAUNCH_RESULT_SIM_MODE_OFF                    = -10,  /* SIM mode is off */
    SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE                     = -11,  /* In flight mode */
    SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT                 = -12,  /* Used data account is invalid */
    SRV_TETHERING_LAUNCH_RESULT_INCALL                          = -13,  /* 2G incall, it could not connect network */
    SRV_TETHERING_LAUNCH_RESULT_END                             = -100  /* End of enum */
} srv_tethering_launch_result_enum;


typedef enum
{
    SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_NONE,
    SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_IN_CHARGING,
    SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_TOTAL
} srv_tethering_wifi_power_change_type_enum;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_switch_cb_funcptr_type
 * DESCRIPTION
 *  Tethering app callback function type which notify app the switching result.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  result:             [IN] Operation result
 *  des_status:         [IN] Destination status
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_switch_cb_funcptr_type)(
                srv_tethering_type_enum tethering_type,
                MMI_BOOL result,
                srv_tethering_status_enum des_status,
                void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_conn_info_notify_funcptr_type
 * DESCRIPTION
 *  Tethering app callback function type which notify connection information.
 *  Wi-Fi tethering use mmi_abm_hotspot_info_struct as info_data structure.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  info_data:          [IN] Information data
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_conn_info_notify_funcptr_type)(
                srv_tethering_type_enum tethering_type,
                void *info_data,
                void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_disconnect_notify_funcptr_type
 * DESCRIPTION
 *  Tethering app callback function type which notify disconnection.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  cause:              [IN] Disconnection cause
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_disconnect_notify_funcptr_type)(
                srv_tethering_type_enum tethering_type,
                srv_tethering_disconn_cause_enum cause,
                void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_app_avail_status_change_notify_funcptr_type
 * DESCRIPTION
 *  Tethering app callback function type which notify tethering application available status changed.
 *  Such as in flight mode user could not entry tethering menu.
 * PARAMETERS
 *  enable_flag:     [IN] Tethering type
 *  user_data:       [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_app_avail_status_change_notify_funcptr_type)(
                MMI_BOOL enable_flag,
                void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_reactivate_demand_ind_func_ptr_type
 * DESCRIPTION
 *  Tethering app callback function type which demand tethering application to reactivate connection.
 *  For example, turn on USB tethering, turn on flight mode, later turn off
 *  flight mode and service will call this callback function to ask USB tethering reactivate.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_reactivate_demand_ind_func_ptr_type)(
                srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_dtcnt_changed_notify_func_ptr_type
 * DESCRIPTION
 *  Tethering app callback function type which notify app the data account is changed.
 * PARAMETERS
 *  sim:            [IN] SIM type
 *  new_acct:       [IN] New data account id
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_dtcnt_changed_notify_func_ptr_type)(
                srv_dtcnt_sim_type_enum sim,
                U32 new_acct);

/* Store the srv_tethering_switch_cb_funcptr_type callback function information */
typedef struct
{
    srv_tethering_switch_cb_funcptr_type funcptr;
    void *user_data;
} srv_tethering_switch_req_info_struct;

/* Store the srv_tethering_conn_info_notify_funcptr_type callback function information */
typedef struct
{
    srv_tethering_conn_info_notify_funcptr_type funcptr;
    void *user_data;
} srv_tethering_conn_info_notify_struct;

/* Store the srv_tethering_disconnect_notify_funcptr_type callback function information */
typedef struct
{
    srv_tethering_disconnect_notify_funcptr_type funcptr;
    void *user_data;
} srv_tethering_disconnect_notify_struct;

/* Store the srv_tethering_app_avail_status_change_notify_funcptr_type callback function information */
typedef struct
{
    srv_tethering_app_avail_status_change_notify_funcptr_type avail_status_change_cb_hdlr;
    void *user_data;
} srv_tethering_app_avail_status_change_info_struct;

/* Wi-Fi tethering settings structure */
typedef struct
{
    srv_tethering_wifi_hs_auth_mode_enum    auth_mode;
    kal_int8                                ssid[SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN];
    kal_int8                                psk[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
    kal_int8                                max_sta_num;
} srv_tethering_wifi_hs_settings_struct;

typedef struct
{
    srv_tethering_status_enum               status;
    srv_tethering_ext_status_enum           ext_status;
    srv_tethering_switch_req_info_struct    switch_req_info;
    U32                                     account_id;
    U8                                      cbm_app_id;
    U8                                      curr_sta_num;
    MMI_BOOL                                reactivate_flag;
    MMI_BOOL                                auto_turn_off_flag;
    S32                                     remaining_time;
    srv_tethering_reactivate_demand_ind_func_ptr_type reactivate_demand_func_ptr;
    srv_tethering_disconn_cause_enum disconn_cause;
} srv_tethering_common_info_struct;

/* Tethering connection information structure */
typedef struct
{
    U32 common_account_id;
    cbm_sim_id_enum used_sim;
    srv_tethering_conn_info_notify_struct conn_info_notify;
    srv_tethering_disconnect_notify_struct disconnect_notify;
} srv_tethering_conn_info_struct;


typedef struct
{
    srv_tethering_common_info_struct common_info[SRV_TETHERING_TYPE_ALL];
    srv_tethering_conn_info_struct conn_info;
    srv_tethering_app_avail_status_change_info_struct app_avail_status_change_info;
    MMI_BOOL dialup_status;
    FuncPtr usb_cable_disconnect_func_ptr;
    srv_tethering_dtcnt_changed_notify_func_ptr_type dtcnt_changed_notify_func_ptr;
    S32 reactivate_retry_times;
    U8 common_cbm_app_id;
    srv_tethering_wifi_power_change_type_enum   wifi_power_change_type;
    U32 dtcnt_id[MMI_SIM_TOTAL];
} srv_tethering_cntx_struct;

/****************************************************************************
* Global variable
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/
/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_bootup_init
 * DESCRIPTION
 *  Function of handling bootup event.
 * PARAMETERS
 *  evt:     [IN] Boot up event
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret srv_tethering_bootup_init(mmi_event_struct *evt);

extern void srv_tethering_init(void);
extern void srv_tethering_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_launch_main_menu_capab
 * DESCRIPTION
 *  Function of checking tethering application is able to launch.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_tethering_launch_result_enum
 *****************************************************************************/
extern srv_tethering_launch_result_enum srv_tethering_check_launch_main_menu_capab(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_reg_app_avail_status_change_cb
 * DESCRIPTION
 *  Function for application register status change callback.
 * PARAMETERS
 *  funcptr:        [IN] Callback function pointer
 *  user_data:      [IN] User data
 * RETURNS
 *  MMI_TRUE: tethering is able to launch
 *  MMI_FALSE: tethering is unable to launch
 *****************************************************************************/
extern void srv_tethering_reg_app_avail_status_change_cb(
        srv_tethering_app_avail_status_change_notify_funcptr_type funcptr,
        void *user_data);
extern void srv_tethering_notify_app_change_avail_status(MMI_BOOL enable_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_switch_on
 * DESCRIPTION
 *  Function for application to switch on tethering.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_switch_on(
                srv_tethering_type_enum tethering_type,
                srv_tethering_switch_cb_funcptr_type funcptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_switch_off
 * DESCRIPTION
 *  Function for application to switch off tethering.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_switch_off(
                srv_tethering_type_enum tethering_type,
                srv_tethering_switch_cb_funcptr_type funcptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_reactivate
 * DESCRIPTION
 *  Function for application to reactivate tethering.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_reactivate(
                srv_tethering_type_enum tethering_type,
                srv_tethering_switch_cb_funcptr_type funcptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_abm_update_settings
 * DESCRIPTION
 *  Function for application to update settings. It will deactivate current tethering
 *  and activate with the new settings.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_abm_update_settings(
                srv_tethering_type_enum tethering_type,
                srv_tethering_switch_cb_funcptr_type funcptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_dtcnt
 * DESCRIPTION
 *  Function for application to get data account id by sim type. (Currently used for Cosmos)
 * PARAMETERS
 *  sim_type:     [IN] SIM type
 * RETURNS
 *  data account id
 *****************************************************************************/
extern U32 srv_tethering_get_dtcnt(srv_dtcnt_sim_type_enum sim_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_save_dtcnt
 * DESCRIPTION
 *  Function for application to save data account id by sim type. (Currently used for Cosmos)
 * PARAMETERS
 *  sim_type:           [IN] SIM type
 *  data_account_id:    [IN] Data account id
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_save_dtcnt(srv_dtcnt_sim_type_enum sim_type, U32 data_account_id);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern void srv_tethering_set_curr_common_dtcnt(U32 data_account_id);
extern U32 srv_tethering_get_curr_common_dtcnt(void);
extern void srv_tethering_set_curr_dtcnt(srv_tethering_type_enum tethering_type, U32 data_account_id);
extern U32 srv_tethering_get_curr_dtcnt(srv_tethering_type_enum tethering_type);
extern U32 srv_tethering_reset_dtcnt(srv_dtcnt_sim_type_enum sim_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_used_dtcnt
 * DESCRIPTION
 *  Function for application to get the used data account id while tethering is activated.
 * PARAMETERS
 *  void
 * RETURNS
 *  data account id
 *****************************************************************************/
extern U32 srv_tethering_get_used_dtcnt(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_used_dtcnt_apn
 * DESCRIPTION
 *  Function for application to get the APN string of the used data account.
 * PARAMETERS
 *  apn_wstr:    [OUT] APN wchar string
 *  apn_len:     [IN] APN string length
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_get_used_dtcnt_apn(WCHAR *apn_wstr, U16 apn_len);

extern U32 srv_tethering_get_auto_dtcnt(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_dtcnt_set_changed_notify_cb
 * DESCRIPTION
 *  Function for application to register data account changed notification callback function.
 * PARAMETERS
 *  cb:    [IN] Changed notification callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_dtcnt_set_changed_notify_cb(
                srv_tethering_dtcnt_changed_notify_func_ptr_type cb);
extern void srv_tethering_dtcnt_changed_notify_app(srv_dtcnt_sim_type_enum sim, U32 new_acct);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_set_conn_info
 * DESCRIPTION
 *  Function for application to set the connection information.
 *  Must be called before switch on tethering.
 * PARAMETERS
 *  conn_info:    [IN] Connection information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_set_conn_info(srv_tethering_conn_info_struct *conn_info);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_conn_info
 * DESCRIPTION
 *  Function for application to get the current connection information.
 * PARAMETERS
 *  conn_info:    [OUT] Connection information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_get_conn_info(srv_tethering_conn_info_struct *conn_info);

extern void srv_tethering_set_status(srv_tethering_type_enum tethering_type, srv_tethering_status_enum status);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_status
 * DESCRIPTION
 *  Function to get the current status.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 * RETURNS
 *  srv_tethering_status_enum
 *****************************************************************************/
extern srv_tethering_status_enum srv_tethering_get_status(srv_tethering_type_enum tethering_type);
extern void srv_tethering_set_ext_status(srv_tethering_type_enum tethering_type, srv_tethering_ext_status_enum status);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_ext_status
 * DESCRIPTION
 *  Function to get the extended status.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 * RETURNS
 *  srv_tethering_ext_status_enum
 *****************************************************************************/
extern srv_tethering_ext_status_enum srv_tethering_get_ext_status(srv_tethering_type_enum tethering_type);

extern void srv_tethering_set_sta_num(srv_tethering_type_enum tethering_type, U8 sta_num);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_get_sta_num
 * DESCRIPTION
 *  Function to get the Wi-Fi tethering current connection station number.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 * RETURNS
 *  station number
 *****************************************************************************/
extern U8 srv_tethering_get_sta_num(srv_tethering_type_enum tethering_type);

extern void srv_tethering_abm_send_activate_req(srv_tethering_type_enum tethering_type);
extern void srv_tethering_abm_activate_cnf_hdlr(void *msg);
extern void srv_tethering_abm_send_deactivate_req(srv_tethering_type_enum tethering_type);
extern void srv_tethering_abm_deactivate_cnf_hdlr(void *msg);
extern void srv_tethering_abm_send_bearer_share_query_req(srv_tethering_type_enum tethering_type);
extern void srv_tethering_abm_bearer_share_query_cnf_hdlr(void *msg);
extern void srv_tethering_report_app_switch_cnf(srv_tethering_type_enum tethering_type, srv_tethering_status_enum dest_status, MMI_BOOL result);
extern U8 srv_tethering_abm_bearer_info_ind_hdlr(void *msg);

extern void srv_tethering_conn_info_changed_notify(srv_tethering_type_enum tethering_type, void *info_data);
extern void srv_tethering_disconnect_hdlr(srv_tethering_type_enum tethering_type);
extern void srv_tethering_disconnect_notify_app(srv_tethering_type_enum tethering_type, srv_tethering_disconn_cause_enum cause);
extern void srv_tethering_reactivate_start_timer(srv_tethering_type_enum tethering_type);
extern void srv_tethering_reactivate_timeout_hdlr(void *arg);
extern void srv_tethering_reactivate_stop_timer(srv_tethering_type_enum tethering_type);
extern void srv_tethering_reactivate_retry(srv_tethering_type_enum tethering_type);
extern void srv_tethering_reacivate_retry_timeout_hdlr(void* arg);

extern cbm_bearer_enum srv_tethering_type_srv_to_ps(srv_tethering_type_enum tethering_type);
extern srv_tethering_type_enum srv_tethering_type_ps_to_srv(cbm_bearer_enum bearer_type);
extern U8 srv_tethering_get_cbm_app_id(srv_tethering_type_enum tethering_type);
extern U8 srv_tethering_get_common_cbm_app_id(void);

extern void srv_tethering_show_status_icon(srv_tethering_type_enum tethering_type);
extern void srv_tethering_hide_status_icon(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_wifi_hs_get_settings
 * DESCRIPTION
 *  Function to get the Wi-Fi tethering settings.
 * PARAMETERS
 *  settings:    [OUT] Wi-Fi tethering settings
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_wifi_hs_get_settings(srv_tethering_wifi_hs_settings_struct *settings);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_wifi_hs_save_settings
 * DESCRIPTION
 *  Function to save the Wi-Fi tethering settings.
 * PARAMETERS
 *  settings:    [IN] Wi-Fi tethering settings
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_wifi_hs_save_settings(srv_tethering_wifi_hs_settings_struct *settings);
extern void srv_tethering_wifi_hs_reset_settings(void);

extern hostap_auth_alg_enum srv_tethering_wifi_hs_auth_mode_srv_to_ps(srv_tethering_wifi_hs_auth_mode_enum app_auth_mode);
extern srv_tethering_wifi_hs_auth_mode_enum srv_tethering_wifi_hs_auth_mode_ps_to_srv(hostap_auth_alg_enum ps_auth_mode);

extern mmi_ret srv_tethering_wifi_wlan_deinit_res_ind_hdlr(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_usb_reg_cable_disconnect_cb_hdlr
 * DESCRIPTION
 *  Function to register USB cable disconnect notification callback function.
 * PARAMETERS
 *  cb:    [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_usb_reg_cable_disconnect_cb_hdlr(FuncPtr cb);
extern void srv_tethering_usb_cable_disconnect_notify_app(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_launch_capab
 * DESCRIPTION
 *  Function for application to check tethering launch capability.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 * RETURNS
 *  srv_tethering_launch_result_enum
 *****************************************************************************/
extern srv_tethering_launch_result_enum srv_tethering_check_launch_capab(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_launch_capab_common
 * DESCRIPTION
 *  Function for application to check tethering launch capability.
 *  This is for common checking.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 * RETURNS
 *  srv_tethering_launch_result_enum
 *****************************************************************************/
extern srv_tethering_launch_result_enum srv_tethering_check_launch_capab_common(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_launch_capab_nw
 * DESCRIPTION
 *  Function for application to check tethering launch capability.
 *  This is for network checking.
 * PARAMETERS
 *  sim:    [IN] SIM type
 * RETURNS
 *  srv_tethering_launch_result_enum
 *****************************************************************************/
extern srv_tethering_launch_result_enum srv_tethering_check_launch_capab_nw(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_launch_capab_acct
 * DESCRIPTION
 *  Function for application to check tethering launch capability.
 *  This is for data account checking.
 * PARAMETERS
 *  tethering_type:    [IN] Tethering type
 *  data_account_id:   [IN] Data account id
 * RETURNS
 *  srv_tethering_launch_result_enum
 *****************************************************************************/
extern srv_tethering_launch_result_enum srv_tethering_check_launch_capab_acct(srv_tethering_type_enum tethering_type, U32 data_account_id);

extern void srv_tethering_set_reactivate_flag(srv_tethering_type_enum tethering_type, MMI_BOOL reactivate_flag);
extern MMI_BOOL srv_tethering_get_reactivate_flag(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_reg_reactivate_demand_cb_hdlr
 * DESCRIPTION
 *  Function for application to register demand reactivate callback function.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  cb:                 [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_reg_reactivate_demand_cb_hdlr(
                srv_tethering_type_enum tethering_type,
                srv_tethering_reactivate_demand_ind_func_ptr_type cb);
extern void srv_tethering_reactivate_demand_ind_app(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_enable_auto_turn_off
 * DESCRIPTION
 *  Function to enable auto turn off function.
 * PARAMETERS
 *  enable_flag:     [IN] Is to enable auto turn off
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_enable_auto_turn_off(MMI_BOOL enable_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_check_auto_turn_off_flag
 * DESCRIPTION
 *  Function to check if the auto turn off function is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: auto turn off is on
 *  MMI_FALSE: auto turn off is off
 *****************************************************************************/
extern MMI_BOOL srv_tethering_check_auto_turn_off_flag(void);
extern void srv_tethering_start_auto_turn_off_timer(void);
extern void srv_tethering_stop_auto_turn_off_timer(void);
extern void srv_tethering_auto_turn_off_timer_timeout_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_auto_turn_off_get_remaining_time
 * DESCRIPTION
 *  Function to get the auto turn off countdown remaining time.
 * PARAMETERS
 *  void
 * RETURNS
 *  remaining time
 *****************************************************************************/
extern S32 srv_tethering_auto_turn_off_get_remaining_time(void);


extern void srv_tethering_wifi_hs_set_power(S8 power_db, S8 power_dbm);
extern void srv_tethering_wifi_change_power(srv_tethering_wifi_power_change_type_enum power_change_type);
#endif /* __MMI_TETHERING__ */
#endif /* __TETHERING_SRV_IPROT_H__ */
