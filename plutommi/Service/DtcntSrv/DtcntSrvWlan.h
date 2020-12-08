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
 * DtcntSrvWlan.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal header file of data account Wlan OTAP services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_WLAN_H
#define _DTCNT_SRV_WLAN_H

#include "MMI_features.h"
#include "DtcntSrvIntEnum.h"
#include "DtcntSrvIntStruct.h"
#include "MMIDataType.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "kal_general_types.h"

#ifdef __MMI_WLAN_FEATURES__
#ifdef __MMI_TETHERING_WIFI__
#include "TetheringSrvGprot.h"
#endif
typedef struct
{
    srv_dtcnt_wlan_cb_func_ptr callback;
    void *user_data;
} srv_dtcnt_init_callback_context_struct;

/*************************************************************************/
/*   Extern Var                                                                                                              */
/*************************************************************************/

#ifdef __MMI_WLAN_FEATURES__
extern srv_dtcnt_wlan_ctx_struct g_srv_dtcnt_wlan_ctx;
extern srv_dtcnt_wlan_setting_struct g_srv_dtcnt_wlan_setting_ctx;
extern srv_dtcnt_prof_wlan_struct *g_srv_dtcnt_wlan_prof_list_p[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
extern srv_dtcnt_wlan_prefer_struct g_srv_dtcnt_wlan_prefer_ctx;
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_TETHERING_WIFI__
extern srv_dtcnt_init_callback_context_struct g_init_callback;
#endif

#ifdef __MMI_OP01_WIFI__
extern srv_dtcnt_wlan_proxy_exclusive_ip_addr_list_struct g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list;
#endif /* __MMI_OP01_WIFI__ */



/*************************************************************************/
/* Extern Function                                                       */
/*************************************************************************/

/* action interfaces */
extern void srv_dtcnt_wlan_add_action(srv_dtcnt_wlan_action_enum action, void *data, srv_dtcnt_wlan_job_struct *job);
extern void srv_dtcnt_wlan_delete_action(srv_dtcnt_wlan_action_enum action, srv_dtcnt_wlan_action_del_opt_enum opt);
extern srv_dtcnt_wlan_action_struct *srv_dtcnt_wlan_find_action(srv_dtcnt_wlan_action_enum action);

/* context interfaces */
extern srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_state(void);
extern srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_prev_state(void);
extern srv_dtcnt_wlan_scan_state_enum srv_dtcnt_wlan_scan_state(void);

/* scan job interfaces */
extern U32 srv_dtcnt_wlan_new_scan_job(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data);
//extern U32 srv_dtcnt_wlan_append_scan_job(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data);
extern void srv_dtcnt_wlan_abort_scan_job(srv_dtcnt_wlan_scan_state_enum scan_state, U32 job_id);
extern void srv_dtcnt_wlan_clear_scan_action(void);

/* post event interfaces */
extern void srv_dtcnt_wlan_post_init_res_event(srv_dtcnt_wlan_req_res_enum res);
extern void srv_dtcnt_wlan_post_deinit_res_event(srv_dtcnt_wlan_req_res_enum res);
extern void srv_dtcnt_wlan_post_disc_res_event(srv_dtcnt_wlan_req_res_enum res);
extern U8 srv_dtcnt_wlan_eap_types (U8 idx);
extern U8 srv_dtcnt_wlan_eap_peap_types (U8 idx);
extern U8 srv_dtcnt_wlan_eap_ttls_types (U8 idx);

/* Others */
//extern void srv_dtcnt_wlan_auto_pw_on(void);
extern void srv_dtcnt_wlan_context_init(void);
extern void srv_dtcnt_wlan_wifi_init_cnf_hdlr(void *info);
extern void srv_dtcnt_wlan_curr_ap_info_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_connect_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_ipaddr_update_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_wifi_deinit_cnf_hdlr(void *info);
extern void srv_dtcnt_wlan_ipaddr_conflict_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_disconnect_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_disconnect_cnf_hdlr(void *info);
extern void srv_dtcnt_wlan_connect_cnf_hdlr(void *info);
extern void srv_dtcnt_wlan_ap_list_cnf_hdlr(void *info);
extern void srv_dtcnt_wlan_wifi_activate_req_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_wifi_deactivate_req_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_atcmd_req_hdlr(void *info);
extern void srv_dtcnt_wlan_set_ps_mode_req(srv_dtcnt_wlan_power_mode_enum pwr_mode);
extern void srv_dtcnt_wlan_set_ps_mode_cnf_hdlr(void *info);
#ifdef __WPS_SUPPORT__
extern void srv_dtcnt_wlan_wps_info_ind_hdlr(void *info);
#endif
extern void srv_dtcnt_wlan_wifi_ap_list_query_ind_hdlr(void *info);
extern void srv_dtcnt_wlan_hw_reset(MMI_BOOL on_off_flag, srv_dtcnt_wlan_cb_func_ptr callback, void *user_data);
extern void srv_dtcnt_wlan_save_profiles(U8 idx, U8 replace, srv_dtcnt_wlan_network_type_enum old_network, srv_dtcnt_prof_wlan_struct *dst_prof);
extern void srv_dtcnt_wlan_append_proc_job(srv_dtcnt_wlan_job_struct *job);
extern MMI_BOOL srv_dtcnt_wlan_is_invalid_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *ip_addr);
#ifdef __MMI_TETHERING_WIFI__
extern void srv_dtcnt_wlan_stop_wifi_tethering_callback_func(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
#endif /* __MMI_TETHERING_WIFI__ */
#ifdef __MMI_OP01_WIFI__
extern void srv_dtcnt_wlan_portal_login_start_cnf_hdlr(void);
extern void srv_dtcnt_wlan_portal_login_stop_cnf_hdlr(void);
extern void srv_dtcnt_wlan_portal_logout_cnf_hdlr(void);
#endif /* __MMI_OP01_WIFI__ */
extern MMI_BOOL srv_dtcnt_wlan_check_chip_status(void);
extern void srv_dtcnt_wlan_post_scan_res_event(srv_dtcnt_wlan_scan_result_struct *res);
extern void srv_dtcnt_wlan_post_conn_res_event(srv_dtcnt_wlan_conn_res_struct *res, mmi_rp_srv_dtcnt_event_enum evt_id);

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _DTCNT_SRV_WLAN_H */ 
