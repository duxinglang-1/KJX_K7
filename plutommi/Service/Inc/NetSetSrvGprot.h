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
* NetSetSrvGprot.h
*
* Project:
* --------
* MAUI
*
* Description:
* ------------
* This file is defines internal interface of network setup service.
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __NETSET_SRV_GPROT_H__
#define __NETSET_SRV_GPROT_H__

#include "MMIDataType.h"
#include "Mmi_msg_struct.h"

/* auto add by kw_check begin */
#include "kal_non_specific_general_types.h"
/* auto add by kw_check end */

/* DOM-NOT_FOR_SDK-BEGIN */
#include "ModeSwitchSrvGprot.h"
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef
****************************************************************************/

/*
 * Event ID for netset service
 */
typedef enum
{
    EVT_ID_SRV_NETSET_GET_PLMN_RSP,
    EVT_ID_SRV_NETSET_ABORT_PLMN_RSP,

    EVT_ID_SRV_NETSET_SET_PLMN_RSP,

    EVT_ID_SRV_NETSET_SET_NW_SELECTION_MODE_RSP,

    EVT_ID_SRV_NETSET_GET_GPRS_CONNECTION_MODE_RSP,
    EVT_ID_SRV_NETSET_SET_GPRS_CONNECTION_MODE_RSP,

    EVT_ID_SRV_NETSET_GET_PREF_LIST_RSP,
    EVT_ID_SRV_NETSET_SET_PREF_LIST_RSP,

    EVT_ID_SRV_NETSET_GET_RAT_MODE_RSP,
    EVT_ID_SRV_NETSET_SET_RAT_MODE_RSP,

    EVT_ID_SRV_NETSET_GET_PCH_MODE_RSP,
    EVT_ID_SRV_NETSET_SET_PCH_MODE_RSP,

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    EVT_ID_SRV_NETSET_GET_PEER_PCH_MODE_RSP,
#endif

    EVT_ID_SRV_NETSET_GET_HSPA_MODE_RSP,
    EVT_ID_SRV_NETSET_SET_HSPA_MODE_RSP,

    EVT_ID_SRV_NETSET_SET_PREF_MODE_RSP,
#ifdef __MMI_3G_SWITCH__
    EVT_ID_SRV_NET_SET_SIM_CAPABILITY_RSP,
    EVT_ID_SRV_NET_GET_SIM_CAPABILITY_RSP,
#endif
 
	EVT_ID_SRV_NETSET_RSP_END
} srv_netset_evt_id_enum;

/*
 * Union for response data
 */
typedef union
{
    mmi_nw_get_plmn_list_rsp_struct *get_plmn_rsp_data;
    mmi_nw_set_plmn_rsp_struct *set_plmn_rsp_data;
    
    mmi_nw_set_plmn_select_mode_rsp_struct *set_nw_selection_mode_rsp_data;
    
    mmi_nw_get_gprs_connect_type_rsp_struct *get_gprs_connection_rsp_data;
    mmi_nw_set_gprs_connect_type_rsp_struct *set_gprs_connection_rsp_data;
    
    mmi_smu_get_preferred_oper_list_rsp_struct *get_pref_list_rsp_data;
    mmi_smu_set_preferred_oper_list_rsp_struct *set_pref_list_rsp_data;

    mmi_nw_get_rat_mode_rsp_struct *get_rat_mode_rsp_data;
    mmi_nw_set_rat_mode_rsp_struct *set_rat_mode_rsp_data;

    mmi_nw_get_gprs_transfer_preference_rsp_struct *get_pch_mode_rsp_data;
    mmi_nw_set_gprs_transfer_preference_rsp_struct *set_pch_mode_rsp_data;
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    mmi_nw_get_monitor_peer_pch_rsp_struct *get_peer_pch_mode_rsp_data;
#endif

    mmi_nw_get_hspa_mode_rsp_struct *get_hspa_mode_rsp_data;    
    mmi_nw_set_hspa_mode_rsp_struct *set_hspa_mode_rsp_data;
#ifdef __MMI_3G_SWITCH__
	mmi_l4c_set_sim_capability_rsp_struct *set_sim_capability_rsp_data;
	mmi_l4c_get_sim_capability_rsp_struct *get_sim_capability_rsp_data;
#endif
	void* general_data;
} srv_netset_rsp_data_type;

/* 
 * Callback data type
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U16 result; // return SRV_NETSET_RSP_RESULT_SUCCESS or SRV_NETSET_RSP_RESULT_BUSY
    srv_netset_rsp_data_type rsp_data;
} srv_netset_rsp_event_struct;

#define SRV_NETSET_RSP_RESULT_SUCCESS 0x01 // the command is send and receive successfully
#define SRV_NETSET_RSP_RESULT_BUSY    0xFF // the command is not send because same operation is running
//typedef void (*mmi_proc_func) (U16 result, srv_netset_rsp_event_struct* data);

/*
 * Preferred mode enum
 */

typedef enum
{
    SRV_NETSET_PREF_MODE_GSM_ONLY,
    SRV_NETSET_PREF_MODE_WLAN_ONLY,
    SRV_NETSET_PREF_MODE_GSM_PREFERRED,
    SRV_NETSET_PREF_MODE_WLAN_PREFERRED,
    SRV_NETSET_PREF_MODE_MODE_END
} srv_netset_pref_mode_enum;

#define P_GSM_ONLY SRV_NETSET_PREF_MODE_GSM_ONLY
#define P_WLAN_ONLY SRV_NETSET_PREF_MODE_WLAN_ONLY
#define P_GSM_PREFERRED SRV_NETSET_PREF_MODE_GSM_PREFERRED
#define P_WLAN_PREFERRED SRV_NETSET_PREF_MODE_WLAN_PREFERRED


/*
 * RAT mode enum, mapping to rat_enum
 */
typedef enum
{
    SRV_NETSET_RAT_NONE = 0,
    SRV_NETSET_RAT_GSM = 1,
    SRV_NETSET_RAT_UMTS = 2,
    SRV_NETSET_RAT_GSM_UMTS = 3
} srv_netset_rat_mode_enum;

/*
 * PCH mode enum, mapping to gprs_transfer_preference_enum
 */
typedef enum
{
    SRV_NETSET_DATA_PREFER,
    SRV_NETSET_CALL_PREFER,
    SRV_NETSET_AS_OPTIMAL
} srv_netset_pch_mode_enum;

/*
 * network selection mode enum, mapping to plmn_selection_mode_enum
 */
typedef enum
{
    SRV_NETSET_MANUAL_SEL = 0, /* Manual select */
    SRV_NETSET_AUTO_SEL = 1    /* Automatic select */
} srv_netset_nw_selection_mode_enum;

/* 
 * GPRS connection mode enum
 */
typedef enum
{
    SRV_NETSET_GPRS_CONNECT_WHEN_NEEDED = 0,
    SRV_NETSET_GPRS_CONNECT_ALWAYS = 1
} srv_netset_gprs_connect_mode_enum;

/*
 * HSPA mode enum mapping to hspa_preference_enum
 */
typedef enum
{
    SRV_NETSET_HSPA_OFF,
    SRV_NETSET_HSPA_ON,
    SRV_NETSET_HSDPA_HSUPA_ON
} srv_netset_hspa_mode_enum;

/*
 * PLMN list structure
 */
typedef struct
{
    U32 plmn_bcd;
    U16 index;
} srv_netset_plmn_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_netset_init
 * DESCRIPTION
 *  this function is to initial network setup service context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret srv_netset_init(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_auto
 * DESCRIPTION
 *  this function is to register network directly
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    set network callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_plmn_auto(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_manual
 * DESCRIPTION
 *  this function is to set network
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  plmn_id     :   [IN]    need register PLMN id
 *  rat         :   [IN]    register PLMN id network type
 *  ptr_func    :   [IN]    set network callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_plmn_manual(mmi_sim_enum sim_type, CHAR* plmn_id, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn
 * DESCRIPTION
 *  this function is to get current network 
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get network callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_plmn(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_abort_plmn
 * DESCRIPTION
 *  this function is to abort search network progress
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    abort network callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_abort_plmn(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_nw_selection_mode
 * DESCRIPTION
 *  this function is to set selection mode
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  sel_mode    :   [IN]    network selection mode
 *  ptr_func    :   [IN]    set selection mode callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_nw_selection_mode(mmi_sim_enum sim_type, srv_netset_nw_selection_mode_enum sel_mode, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_nw_selection_mode
 * DESCRIPTION
 *  this function is to get selection mode
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get selection mode callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 srv_netset_get_nw_selection_mode(mmi_sim_enum sim_type);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_gprs_connection_state
 * DESCRIPTION
 *  this function is to set GPRS connection state
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  gprs        :   [IN]    GPRS connection state
 *  ptr_func    :   [IN]    set GPRS connection state callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_gprs_connection_state(mmi_sim_enum sim_type, srv_netset_gprs_connect_mode_enum gprs, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_gprs_connection_state
 * DESCRIPTION
 *  this function is to get GPRS connection state
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get GPRS state callback function
 * RETURNS
 *  GPRS connection state
 *****************************************************************************/
extern void srv_netset_get_gprs_connection_state(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_list
 * DESCRIPTION
 *  this function is to set preferred network list
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  del_pref    :   [IN]    PLMN to be deleted from list
 *  add_pref    :   [IN]    PLMN to be added in to list
 *  ptr_func    :   [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_pref_list(mmi_sim_enum sim_type, void* del_pref, void* add_pref, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pref_list
 * DESCRIPTION
 *  this function is to get preferred network list
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  req_msg_buff:   [IN]    request message buffer
 *  ptr_func    :   [IN]    get preferred network list callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_pref_list(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_rat_mode
 * DESCRIPTION
 *  this function is to set RAT mode
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get preferred network list callback function
 *  rat         :   [IN]    rat type to be set
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_rat_mode(mmi_sim_enum sim_type, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_rat_mode
 * DESCRIPTION
 *  this function is to get RAT mode
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get preferred network list callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_rat_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pch_mode
 * DESCRIPTION
 *  This function is function of get PCH mode state 
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get preferred network list callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_pch_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pch_mode
 * DESCRIPTION
 *  This function is function of set PCH mode state 
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  pch         :   [IN]    pch mode
 *  ptr_func    :   [IN]    set GPRS connection state callback function 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_pch_mode(mmi_sim_enum sim_type, srv_netset_pch_mode_enum pch, mmi_proc_func ptr_func, void *user_data);

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pch_mode
 * DESCRIPTION
 *  This function is function of get PCH mode state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_peer_pch_mode(mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_peer_pch_mode
 * DESCRIPTION
 *  This function is function of set PCH mode state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_peer_pch_mode(mmi_sim_enum sim, MMI_BOOL monitor_peer_pch_on);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_hspa_mode
 * DESCRIPTION
 *  This function used to get HSPA mode state 
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  ptr_func    :   [IN]    get hspa mode callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_get_hspa_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_hspa_mode
 * DESCRIPTION
 *  This function is for HSPA mode setting 
 * PARAMETERS
 *  sim_type    :   [IN]    SIM id
 *  hspa        :   [IN]    HSPA mode to be set
 *  ptr_func    :   [IN]    set hspa mode callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_hspa_mode(mmi_sim_enum sim_type, srv_netset_hspa_mode_enum hspa, mmi_proc_func ptr_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_mode
 * DESCRIPTION
 *  Set preferred mode in NVRAM 
 * PARAMETERS
 *  srv_netset_pref_mode_enum   :   [IN]    mode
 *  check_sim                   :   [IN]    if need to check SIM status
 *  callback                    :   [IN]    callback function
 *  user_data                    :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_netset_set_pref_mode(srv_netset_pref_mode_enum mode, MMI_BOOL check_sim, mmi_proc_func callback, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pref_mode
 * DESCRIPTION
 *  Get current preferred mode setting 
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
extern srv_netset_pref_mode_enum srv_netset_get_pref_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_is_plmn_roaming
 * DESCRIPTION
 *  Check if the input PLMN is equivalent 
 * PARAMETERS
 *  sim_plmn    :   [IN]    PLMN from SIM will check both 5-digits and 6-digits
 *                          cases
 *  bcch_plmn   :   [IN]    PLMN from bcch
 * RETURNS
 *  MMI_TRUE Equivalent, MMI_FALSE Unequivalent
 *****************************************************************************/
extern MMI_BOOL srv_netset_is_plmn_roaming(CHAR *sim_hplmn, CHAR *bcch_plmn);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_index
 * DESCRIPTION
 *  Get PLMN index in bcdPlmnsToDisplayName table, the index is from string_index
 *  You can use this index to find specific string ID in MMI or check if PLMNs are
 *  from the same operator.
 *  The checking is simplely compare the PLMN BCD.
 * PARAMETERS
 *  plmn    :   [IN]    PLMN string to be searched
 * RETURNS
 *  U16 index
 *****************************************************************************/
extern S16 srv_netset_get_plmn_index(CHAR *plmn);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_index_ext
 * DESCRIPTION
 *  Get PLMN index in bcdPlmnsToDisplayName table, the index is from string_index
 *  You can use this index to find specific string ID in MMI or check if PLMNs are
 *  from the same operator.
 *  The checking using matching criteria of 23.122.
 * PARAMETERS
 *  plmn    :   [IN]    PLMN from BCCH
 * RETURNS
 *  U16 index
 *****************************************************************************/
extern S16 srv_netset_get_plmn_index_ext(const CHAR *plmn, MMI_BOOL is_band_pcs1900);

/*****************************************************************************
* FUNCTION
*  srv_netset_is_t_mobile_us_sim
* DESCRIPTION
*  Check if the inserted SIM is T-Mobile
* PARAMETERS
*  plmn     :   [IN]    input plmn for checking
* RETURNS
*  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL srv_netset_is_t_mobile_us_sim(CHAR *plmn);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_opname
 * DESCRIPTION
 *  Get operator name
 * PARAMETERS
 *  plmn    :   [IN]    PLMN from BCCH
 *  opname  :   [OUT]   output buffer
 * RETURNS
 *  S16 index
 *****************************************************************************/
S16 srv_netset_get_opname(const U8 *plmn, WCHAR *opname);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_sys_plmn_mccmnc
 * DESCRIPTION
 *  Get the MCC/MNC of PLMN in system PLMN table 
 * PARAMETERS
 *  index       :   [IN]    index in system PLMN table
 *  plmn        :   [OUT]   output PLMN string
 *  buffer_len  :   [IN]    plmn buffer length
 * RETURNS
 *  CHAR*
 *****************************************************************************/
extern MMI_BOOL srv_netset_get_sys_plmn_mccmnc(U32 index, CHAR *plmn, U8 buffer_len);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_sys_plmn_opname
 * DESCRIPTION
 *  Get the operator name of PLMN in system PLMN table 
 * PARAMETERS
 *  index       :   [IN]    index in system PLMN table
 *  opname      :   [OUT]   output operator name
 *  buffer_len  :   [IN]    opname buffer length
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern MMI_BOOL srv_netset_get_sys_plmn_opname(U32 index, WCHAR *opname, U8 buffer_len);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_system_plmn_number
 * DESCRIPTION
 *  Get total number of system PLMN table 
 * PARAMETERS
 *  
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_netset_get_system_plmn_number(void);

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_noof_plmn_supported
 * DESCRIPTION
 *  This function returns the value for NoOfPLMNSupported
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 srv_netset_get_noof_plmn_supported(mmi_sim_enum sim_type);

 /* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_save_prev_rf_mode
 * DESCRIPTION
 *  Save previouse RF mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
extern void srv_netset_save_prev_rf_mode(srv_mode_switch_type_enum mode);
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_prev_rf_mode
 * DESCRIPTION
 *  Get previouse RF mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
extern srv_mode_switch_type_enum srv_netset_get_prev_rf_mode(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_3g_capability_sim
 * DESCRIPTION
 *  net set get 3G capacity sim.
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_sim_enum srv_netset_get_3g_capability_sim(void);


#endif /* __NETSET_SRV_GPROT_H__ */
