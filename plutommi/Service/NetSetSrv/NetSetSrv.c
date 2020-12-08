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
 * NetSetSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is network setup service 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"

/***************************************************************************** 
* Include
*****************************************************************************/
#include "NetSetSrvProt.h"
#include "NetSetSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_msg_struct.h"
#include "NWInfoSrvGprot.h"
#include "PLMNEnum.h"
#include "Mmi_rp_srv_netset_def.h"
#include "IdleGprot.h"
#include "app_str.h"
#include "app_plmn.h"
#include "Unicodexdcl.h"
/* auto add by kw_check begin */
#include "stack_msgs.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "ps_public_enum.h"
#include "string.h"
#include "l4crac_enums.h"
#include "kal_public_api.h"
#include "l3_inc_enums.h"
#include "smu_common_enums.h"
#include "sim_common_enums.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "CustDataRes.h"
/* auto add by kw_check end */
#include "ProtocolEvents.h"
#include "NwInfoSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_utility_gprot.h"

typedef struct
{
    U16 req_msg_id;
    U16 rsp_msg_id;
    PsExtFuncPtr srv_rsp_func;
} srv_netset_op_msg_node;  

typedef struct
{
    mmi_proc_func ptr_func[MMI_MAX_SIM_NUM];
    void* user_data[MMI_MAX_SIM_NUM];
} srv_netset_op_data_node;

typedef struct srv_netset_app_sync
{
    srv_netset_nw_selection_mode_enum nw_selection_mode;
    U16 plmn_supported_num;
} srv_netset_app_sync;
/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
static srv_netset_app_sync g_netset_app_srv_vars[MMI_MAX_SIM_NUM];
//extern mmi_netset_cntx_struct g_netset_cntx[];

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Network Service Common API */
static void PLMNSelectionModeIndication(void *info, int mod_src);
static void srv_netset_update_noof_plmn_supported(void *iMsg, int mod_src);

static void srv_netset_set_op_cntx(mmi_sim_enum sim_type, srv_netset_op_type_enum op_type, void* req_msg_buff);

static MMI_BOOL srv_netset_set_op_rsp_func(mmi_sim_enum sim_type, srv_netset_op_type_enum op, mmi_proc_func cb_func, void *user_data);
static MMI_BOOL srv_netset_clear_op_rsp_func(mmi_sim_enum sim_type, srv_netset_op_type_enum op);

static mmi_sim_enum srv_netset_trans_modsrc_to_simid(int mod_src);


/* Auto Register Network */
static void srv_netset_set_plmn_auto_rsp(void* rsp_msg_buff, int mod_src);

/* Manual Search Network */
static void srv_netset_get_plmn_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_abort_plmn_rsp(void* rsp_msg_buff, int mod_src);

/* Manual Register Network */
static void srv_netset_set_plmn_manual_rsp(void* rsp_msg_buff, int mod_src);

/* Change Network Selection Mode */
/*static void srv_netset_get_selection_mode_rsp(void* rsp_msg_buff, int mod_src);*/
static void srv_netset_set_selection_mode_rsp(void* rsp_msg_buff, int mod_src);

/* Preferred Network List */
static void srv_netset_get_pref_list_rsp(void* rsp_msg_buff, int mod_src);
void srv_netset_set_pref_list_int(mmi_sim_enum sim_type, void* del_req, void* add_req);
static void srv_netset_set_pref_list_rsp(void* rsp_msg_buff, int mod_src);

/* RAT Mode */
static void srv_netset_get_rat_mode_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_set_rat_mode_rsp(void* rsp_msg_buff, int mod_src);

/* GPRS Connection State */
static void srv_netset_get_gprs_connection_state_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_set_gprs_connection_state_rsp(void* rsp_msg_buff, int mod_src);

/* PCH state */
static void srv_netset_get_pch_mode_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_set_pch_mode_rsp(void* rsp_msg_buff, int mod_src);
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
static void srv_netset_get_peer_pch_mode_rsp(void* rsp_msg_buff, int mod_src);
#endif
/* HSPA state */
static void srv_netset_get_hspa_mode_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_set_hspa_mode_rsp(void* rsp_msg_buff, int mod_src);

#ifdef __MMI_3G_SWITCH__
static void srv_netset_set_3g_sim_capability_rsp(void* rsp_msg_buff, int mod_src);
static void srv_netset_get_3g_sim_capability_rsp(void* rsp_msg_buff, int mod_src);
static MMI_RET	srv_net_get_sim_capability_set_init(mmi_event_struct *param);

#endif

/* Preferred mode */
void srv_netset_save_prev_rf_mode(srv_mode_switch_type_enum mode);
srv_mode_switch_type_enum srv_netset_get_prev_rf_mode(void);
#ifdef __MMI_WLAN_FEATURES__
static void srv_netset_save_pref_mode(U8 mode);
static mmi_ret srv_netset_set_pref_mode_rsp(mmi_event_struct *evt);
#endif


/* PLMN check */
static U32 srv_netset_plmn_str_2_bcd_short(const CHAR *plmn);

/***************************************************************************** 
* External Function
*****************************************************************************/
static srv_netset_op_data_node g_srv_netset_op_data[SRV_NETSET_OP_NUM];
const static srv_netset_op_msg_node g_srv_netset_msg_data[] =
{
    /* SRV_NETSET_OP_GET_PLMN */
    {
        MSG_ID_MMI_NW_GET_PLMN_LIST_REQ, 
        MSG_ID_MMI_NW_GET_PLMN_LIST_RSP, 
        srv_netset_get_plmn_rsp
    },

	/* SRV_NETSET_OP_ABORT_PLMN */
	{
		MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ,
        MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP, 
        srv_netset_abort_plmn_rsp
	},

    /* SRV_NETSET_OP_SET_PLMN_AUTO */
    {
        MSG_ID_MMI_NW_SET_PLMN_REQ,
        MSG_ID_MMI_NW_SET_PLMN_RSP, 
        srv_netset_set_plmn_auto_rsp
    },

    /* SRV_NETSET_OP_SET_PLMN_MANUAL */
    {
        MSG_ID_MMI_NW_SET_PLMN_REQ,
        MSG_ID_MMI_NW_SET_PLMN_RSP, 
        srv_netset_set_plmn_manual_rsp
    },

    /* SRV_NETSET_OP_SET_SELECT_MODE */
    {
        MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ, 
        MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP, 
        srv_netset_set_selection_mode_rsp
    },

    /* SRV_NETSET_OP_GET_GPRS_STATUS */
    {
        MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ, 
        MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP, 
        srv_netset_get_gprs_connection_state_rsp
    },

    /* SRV_NETSET_OP_SET_GPRS_STATUS */
    {
        MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ, 
        MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP, 
        srv_netset_set_gprs_connection_state_rsp
    },

    /* SRV_NETSET_OP_GET_PREF_LIST */
    {
        MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ, 
        MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP, 
        srv_netset_get_pref_list_rsp
    },

    /* SRV_NETSET_OP_SET_PREF_LIST */
    {
        MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ, 
        MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP, 
            srv_netset_set_pref_list_rsp
    },

	/* SRV_NETSET_OP_GET_RAT */
	{
		MSG_ID_MMI_NW_GET_RAT_MODE_REQ, 
        MSG_ID_MMI_NW_GET_RAT_MODE_RSP, 
        srv_netset_get_rat_mode_rsp
	},

	/* SRV_NETSET_OP_SET_RAT */
	{
		MSG_ID_MMI_NW_SET_RAT_MODE_REQ, 
        MSG_ID_MMI_NW_SET_RAT_MODE_RSP, 
		srv_netset_set_rat_mode_rsp
	},

	/* SRV_NETSET_OP_GET_PCH */
	{
        MSG_ID_MMI_NW_GET_GPRS_TRANSFER_PREFERENCE_REQ, 
        MSG_ID_MMI_NW_GET_GPRS_TRANSFER_PREFERENCE_RSP,
        srv_netset_get_pch_mode_rsp
	},
	
    /* SRV_NETSET_OP_SET_PCH */
	{
        MSG_ID_MMI_NW_SET_GPRS_TRANSFER_PREFERENCE_REQ, 
        MSG_ID_MMI_NW_SET_GPRS_TRANSFER_PREFERENCE_RSP,
        srv_netset_set_pch_mode_rsp
	},	
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
	/* SRV_NETSET_OP_GET_PEER_PCH */
	{
        MSG_ID_MMI_NW_GET_MONITOR_PEER_PCH_REQ, 
        MSG_ID_MMI_NW_GET_MONITOR_PEER_PCH_RSP,
        srv_netset_get_peer_pch_mode_rsp
	},
#endif	
    /* SRV_NETSET_OP_GET_HSPA */
    {
        MSG_ID_MMI_NW_GET_HSPA_MODE_REQ, 
        MSG_ID_MMI_NW_GET_HSPA_MODE_RSP,
        srv_netset_get_hspa_mode_rsp
    },

    /* SRV_NETSET_OP_SET_HSPA */
    {
        MSG_ID_MMI_NW_SET_HSPA_MODE_REQ, 
        MSG_ID_MMI_NW_SET_HSPA_MODE_RSP,
        srv_netset_set_hspa_mode_rsp
    },
#ifdef __MMI_3G_SWITCH__
	{
		MSG_ID_MMI_L4C_SET_SIM_CAPABILITY_REQ,
		MSG_ID_MMI_L4C_SET_SIM_CAPABILITY_RSP,
		srv_netset_set_3g_sim_capability_rsp
    },
    {
		MSG_ID_MMI_L4C_GET_SIM_CAPABILITY_REQ,
		MSG_ID_MMI_L4C_GET_SIM_CAPABILITY_RSP,
		srv_netset_get_3g_sim_capability_rsp
    },
#endif

};

const static mmi_id g_srv_netset_op_evt_id[] = 
{
    EVT_ID_SRV_NETSET_GET_PLMN_RSP,
    EVT_ID_SRV_NETSET_ABORT_PLMN_RSP,

    EVT_ID_SRV_NETSET_SET_PLMN_RSP,
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
    
#ifdef __MMI_3G_SWITCH__
	EVT_ID_SRV_NET_SET_SIM_CAPABILITY_RSP,
	EVT_ID_SRV_NET_GET_SIM_CAPABILITY_RSP,
#endif
};

static U16 srv_netset_get_op_evt_id(srv_netset_op_type_enum op)
{
    return (g_srv_netset_op_evt_id[op - SRV_NETSET_OP_GET_PLMN]);
}

static void srv_netset_op_rsp_busy(srv_netset_op_type_enum op, mmi_proc_func ptr_func, void *user_data)
{
    srv_netset_rsp_event_struct failed_event;
    
    failed_event.evt_id = srv_netset_get_op_evt_id(op);
    failed_event.result = SRV_NETSET_RSP_RESULT_BUSY;
    failed_event.user_data = user_data;        
    ptr_func((mmi_event_struct*)&failed_event);
}

static void srv_netset_op_rsp_done(mmi_sim_enum sim, srv_netset_op_type_enum op, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_frm_sim_to_index(sim);
    srv_netset_rsp_event_struct rsp_data;
    U16 event_id = srv_netset_get_op_evt_id(op);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_op_rsp_done(%d %d)", sim, op);

	ASSERT(event_id < EVT_ID_SRV_NETSET_RSP_END);
    srv_netset_clear_event_handler(sim, g_srv_netset_msg_data[op].rsp_msg_id);   
    
    rsp_data.result = SRV_NETSET_RSP_RESULT_SUCCESS;
    rsp_data.evt_id = event_id;
    rsp_data.user_data = g_srv_netset_op_data[op].user_data[index];

	if (event_id != EVT_ID_SRV_NETSET_ABORT_PLMN_RSP &&
		event_id != EVT_ID_SRV_NETSET_SET_PREF_MODE_RSP)
	{
		rsp_data.rsp_data.general_data = data;
	}
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
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_3G_SWITCH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_3G_SWITCH__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

    (*g_srv_netset_op_data[op].ptr_func[index])((mmi_event_struct*)&rsp_data);
    
    srv_netset_clear_op_rsp_func(sim, op);
}

/* temp functions */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_operator
 * DESCRIPTION
 *  This function is to do network setup operator
 * PARAMETERS
 *  sim_type [IN]   : 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_op_cntx(mmi_sim_enum sim_type, srv_netset_op_type_enum op_type, void* req_msg_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE3(0, "[NetSetSrv.c] srv_netset_set_op_cntx(%d %d %x)", sim_type, op_type, req_msg_buff);
    if (g_srv_netset_msg_data[op_type].req_msg_id == 0)
    {
        // Need message queue support
    }
    else
    {
        /* set protocol event handler with global context */
        srv_netset_set_event_handler(sim_type, g_srv_netset_msg_data[op_type].rsp_msg_id, 
            g_srv_netset_msg_data[op_type].srv_rsp_func);

        /* Send message with request message buffer */
//        srv_netset_send_msg(sim_type, g_srv_netset_msg_data[op_type].req_msg_id, req_msg_buff);
        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(sim_type),
            (oslMsgType)(g_srv_netset_msg_data[op_type].req_msg_id),
            (oslParaType*)req_msg_buff,
            NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_op_rsp_func
 * DESCRIPTION
 *  This function is to set application callback function to global context
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_netset_set_op_rsp_func(mmi_sim_enum sim_type, srv_netset_op_type_enum op, mmi_proc_func cb_func, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_frm_sim_to_index(sim_type);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE3(0, "[NetSetSrv.c] srv_netset_set_op_rsp_func(%d %d %d)", sim_type, op, cb_func);
    if (g_srv_netset_op_data[op].ptr_func[index])
    {
        /* callback function existed */
        /* Send busy event to callback */
//        MMI_ASSERT(0);  /// need modify
        srv_netset_op_rsp_busy(op, cb_func, user_data);
        return MMI_FALSE;
    }
    else
    {
        g_srv_netset_op_data[op].ptr_func[index] = cb_func;
        g_srv_netset_op_data[op].user_data[index] = user_data;
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_clear_op_rsp_func
 * DESCRIPTION
 *  This function is to clear application callback function to global context
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_netset_clear_op_rsp_func(mmi_sim_enum sim_type, srv_netset_op_type_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_frm_sim_to_index(sim_type);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_clear_op_rsp_func(%d %d)", sim_type, op);
    if (g_srv_netset_op_data[op].ptr_func[index])
    {
        g_srv_netset_op_data[op].ptr_func[index] = NULL;
        g_srv_netset_op_data[op].user_data[index] = NULL;
        return MMI_TRUE;
    }
    else
    {
        NETSET_TRACE0(0, "[NetSetSrv.c] srv_netset_clear_op_rsp_func() no func");
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_clear_op_rsp_func
 * DESCRIPTION
 *  This function is to clear application callback function to global context
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_sim_enum srv_netset_trans_modsrc_to_simid(int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_trans_modsrc_to_simid(%d)", mod_src);
    return mmi_frm_l4c_mod_to_sim((module_type)mod_src);
}

/* Network Setup Auto Register Network */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_auto
 * DESCRIPTION
 *  This function is to register network automatic
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_plmn_auto(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_plmn_auto(%d %d)", sim_type, ptr_func);
    /* set callback function in global context with SIM type and operator */
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_PLMN_AUTO, ptr_func, user_data))
    {
        req_msg = (mmi_nw_set_plmn_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_req_struct));
        req_msg->opcode = 0;    /* 0 : auto select  1 : manual select */
        memset(req_msg->oper, 0, MAX_PLMN_LEN + 1);
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif  /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_PLMN_AUTO, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_auto_rsp
 * DESCRIPTION
 *  This function is to search network or auto register network
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_plmn_auto_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_plmn_auto_rsp(%d %d)", rsp_msg_buff, mod_src);
    
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_PLMN_AUTO, 
        rsp_msg_buff);
}
/* Network Setup Auto Register Network */


/* Network Setup Manual Register Network */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_manual
 * DESCRIPTION
 *  This function is to manual register network
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_plmn_manual(mmi_sim_enum sim_type, CHAR* plmn_id, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_req_struct *req_msg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_plmn_manual(sim[%d], ptr_func[%d])", sim_type, ptr_func);
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_plmn_manual(plmn_id[%s], rat[%d])", plmn_id, rat);

    /* set callback function in global context with SIM type and operator */
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_PLMN_MANUAL, ptr_func, user_data))
    {
        req_msg = (mmi_nw_set_plmn_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_req_struct));
        req_msg->opcode = 1;

        memset(req_msg->oper, 0, MAX_PLMN_LEN + 1);
        memcpy(req_msg->oper, plmn_id, MAX_PLMN_LEN + 1);

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__) */
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_PLMN_MANUAL, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_plmn_manual_rsp
 * DESCRIPTION
 *  This function is to manual register network
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_plmn_manual_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_plmn_manual_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_PLMN_MANUAL, 
        rsp_msg_buff);
}
/* Network Setup Manual Register Network */


/* Network Setup Get PLMN List */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn
 * DESCRIPTION
 *  This function is to get PLMN list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_get_plmn(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_plmn(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_PLMN, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_PLMN, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_rsp
 * DESCRIPTION
 *  This function is to receive response of get PLMN list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_plmn_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_plmn_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_PLMN, 
        rsp_msg_buff);

}
/* Network Setup Get PLMN List */


/* Network Setup Abort PLMN List search */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_abort_plmn
 * DESCRIPTION
 *  This function is to abort PLMN list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_abort_plmn(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_abort_plmn(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_ABORT_PLMN, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_ABORT_PLMN, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_abort_plmn_rsp
 * DESCRIPTION
 *  This function is to receive response of get PLMN list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_abort_plmn_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_abort_plmn_rsp(%d %d)", rsp_msg_buff, mod_src);
    /* Clear the get PLMN data */
    srv_netset_clear_event_handler(sim_id, g_srv_netset_msg_data[SRV_NETSET_OP_GET_PLMN].rsp_msg_id);
    srv_netset_clear_op_rsp_func(sim_id, SRV_NETSET_OP_GET_PLMN);

    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_ABORT_PLMN, 
        rsp_msg_buff);
}
/* Network Setup Abort PLMN List search */



/* Network Setup Change Selection Mode */

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_nw_selection_mode
 * DESCRIPTION
 *  Temporary used for get network selection mode 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_netset_get_nw_selection_mode(mmi_sim_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MANUAL_MODE_NW_SEL__
    return (U8)g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_type)].nw_selection_mode;    
#else /* __MANUAL_MODE_NW_SEL__ */ 
    return SRV_NETSET_AUTO_SEL;
#endif /* __MANUAL_MODE_NW_SEL__ */    
}
 

#ifdef __MANUAL_MODE_NW_SEL__
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_nw_selection_mode
 * DESCRIPTION
 *  This function is to search network or auto register network
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_nw_selection_mode(mmi_sim_enum sim_type, srv_netset_nw_selection_mode_enum sel_mode, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_select_mode_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE3(0, "[NetSetSrv.c] srv_netset_set_nw_selection_mode(%d %d %d)", sim_type, sel_mode, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_SELECT_MODE, ptr_func, user_data))
    {
        req_msg = (mmi_nw_set_plmn_select_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_select_mode_req_struct));
        req_msg->mode = sel_mode;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_SELECT_MODE, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_selection_mode_rsp
 * DESCRIPTION
 *  This function is response function of set selection mode 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_selection_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = MMI_SIM_NONE;
    mmi_nw_set_plmn_select_mode_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_selection_mode_rsp(%d %d)", rsp_msg_buff, mod_src);
    sim_id = srv_netset_trans_modsrc_to_simid(mod_src);
    rsp_msg = (mmi_nw_set_plmn_select_mode_rsp_struct*) rsp_msg_buff;
    
    if (rsp_msg->result)
    {   
        if (srv_netset_get_nw_selection_mode(sim_id) == SRV_NETSET_AUTO_SEL)
        {
            g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_id)].nw_selection_mode = SRV_NETSET_MANUAL_SEL;
        }
        else
        {
            g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_id)].nw_selection_mode = SRV_NETSET_AUTO_SEL;
    	}
    }
    
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_SELECT_MODE, 
        rsp_msg_buff);    
}
#endif /* __MANUAL_MODE_NW_SEL__ */
/* Network Setup Change Selection Mode */


/* Network Setup Preferred Network List */
static mmi_smu_set_preferred_oper_list_req_struct temp_msg;
static U8 add_pref_flag = 0;
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_list
 * DESCRIPTION
 *  This function is function of set prefer network list request 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_pref_list(mmi_sim_enum sim_type, void* del_req, void* add_req, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pref_list(sim[%d] ptr_func[%d])", sim_type, ptr_func);
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pref_list(del_req[%d] add_req[%d])", del_req, add_req);

    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_PREF_LIST, ptr_func, user_data))
    {
        srv_netset_set_pref_list_int(sim_type, del_req, add_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_list
 * DESCRIPTION
 *  This function is function of set prefer network list request 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_pref_list_int(mmi_sim_enum sim_type, void* del_req, void* add_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *input_msg = NULL;
    mmi_smu_set_preferred_oper_list_req_struct *req_msg = NULL;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pref_list_int(del_req[%d] add_req[%d])", del_req, add_req);
    if (!del_req && !add_req)
    {
        ASSERT(0);
    }

    if (add_req && del_req)
    {
		add_pref_flag = 1;
        memcpy(&temp_msg, add_req, sizeof(mmi_smu_set_preferred_oper_list_req_struct));    
    }
    
    req_msg = (mmi_smu_set_preferred_oper_list_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));

    if (del_req)
    {
        input_msg = (mmi_smu_set_preferred_oper_list_req_struct *)del_req;
        req_msg->opcode = SMU_REMOVE_PLMNSEL;        
    }
    else
    {
        input_msg = (mmi_smu_set_preferred_oper_list_req_struct *)add_req;
        req_msg->opcode = SMU_ADD_PLMNSEL;
    }
    req_msg->index = input_msg->index;
    req_msg->rat = input_msg->rat;
    memcpy(req_msg->oper, input_msg->oper, (MAX_PLMN_LEN + 1));

    srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_PREF_LIST, req_msg);
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_list_rsp
 * DESCRIPTION
 *  This function is function of set prefer network list response
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_pref_list_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id = MMI_SIM_NONE;
    mmi_smu_set_preferred_oper_list_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pref_list_rsp(%d %d)", rsp_msg_buff, mod_src);
    sim_id = srv_netset_trans_modsrc_to_simid(mod_src);
    rsp_msg = (mmi_smu_set_preferred_oper_list_rsp_struct*) rsp_msg_buff;

	NETSET_TRACE1(0, "[NetSetSrv.c] add_pref_flag(%d)", add_pref_flag);
    
	if (rsp_msg->result)
    {
		if (add_pref_flag)
		{
			add_pref_flag = 0;
			srv_netset_set_pref_list_int(sim_id, NULL, &temp_msg);
            return;
		}
	}
	else
	{
		add_pref_flag = 0;
	}
    
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_PREF_LIST, 
        rsp_msg_buff);

}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pref_list
 * DESCRIPTION
 *  This function is function of get prefer network list request 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_get_pref_list(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_preferred_oper_list_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_pref_list(%d %d)", sim_type, ptr_func);

    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_PREF_LIST, ptr_func, user_data))
    {
        req_msg = (mmi_smu_get_preferred_oper_list_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_get_preferred_oper_list_req_struct));
        req_msg->num = g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_type)].plmn_supported_num;	

        req_msg->index = 0;
        req_msg->file_idx_req = FILE_NONE;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_PREF_LIST, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pref_list_rsp
 * DESCRIPTION
 *  This function is function of set prefer network list response
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_pref_list_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_pref_list_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_PREF_LIST, 
        rsp_msg_buff);

}

/* Network Setup Preferred Network List */


/* Network Setup GPRS connection */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_gprs_connection_state
 * DESCRIPTION
 *  This function is function of set GPRS connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_gprs_connection_state(mmi_sim_enum sim_type, srv_netset_gprs_connect_mode_enum gprs, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_gprs_connect_type_req_struct *req_msg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE3(0, "[NetSetSrv.c] srv_netset_set_gprs_connection_state(%d %d %d)", sim_type, gprs, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_GPRS_STATUS, ptr_func, user_data))
    {
        req_msg = (mmi_nw_set_gprs_connect_type_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_gprs_connect_type_req_struct));
        req_msg->type = (U8)gprs;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_GPRS_STATUS, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_gprs_connection_state_rsp
 * DESCRIPTION
 *  This function is response function of set GPRS connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_gprs_connection_state_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_gprs_connection_state_rsp(%d %d)", rsp_msg_buff, mod_src);
    
    /* need start 2 seconds timer to avoid power off during the set GPRS mode period */
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_GPRS_STATUS, 
        rsp_msg_buff);

}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_gprs_connection_state
 * DESCRIPTION
 *  This function is function of get GPRS connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_get_gprs_connection_state(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_gprs_connection_state(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_GPRS_STATUS, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_GPRS_STATUS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_gprs_connection_state_rsp
 * DESCRIPTION
 *  This function is response function of get GPRS connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_gprs_connection_state_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_gprs_connection_state_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_GPRS_STATUS, 
        rsp_msg_buff);
}
/* Network Setup GPRS connection */


/* WCDMA & UMTS Function Support */
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_rat_mode
 * DESCRIPTION
 *  This function is function of get RAT mode state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_get_rat_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_rat_mode(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_RAT, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_RAT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_gprs_connection_state_rsp
 * DESCRIPTION
 *  This function is response function of get GPRS connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_rat_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_rat_mode_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_RAT, 
        rsp_msg_buff);
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_rat_mode
 * DESCRIPTION
 *  This function is function of set RAT mode state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_rat_mode(mmi_sim_enum sim_type, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_rat_mode_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_RAT, ptr_func, user_data))
    {
		req_msg = (mmi_nw_set_rat_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_rat_mode_req_struct));
		if(user_data)
		{
			req_msg->prefer_rat = *(U8*)(user_data);
		}
        req_msg->rat_mode = (U8)rat;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_RAT, req_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_gprs_connection_state_rsp
 * DESCRIPTION
 *  This function is response function of set rat status 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_rat_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_RAT, 
        rsp_msg_buff);

}
/* WCDMA & UMTS Function Support */


/* PCH Function Support */
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
void srv_netset_get_pch_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_pch_mode(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_PCH, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_PCH, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pch_mode_rsp
 * DESCRIPTION
 *  This function is response function of get PCH state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_pch_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_pch_mode_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_PCH, 
        rsp_msg_buff);
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pch_mode
 * DESCRIPTION
 *  This function is function of set PCH mode state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_pch_mode(mmi_sim_enum sim_type, srv_netset_pch_mode_enum pch, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_gprs_transfer_preference_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pch_mode(%d %d)", sim_type, pch);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_PCH, ptr_func, user_data))
    {
		req_msg = (mmi_nw_set_gprs_transfer_preference_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_gprs_transfer_preference_req_struct));
        req_msg->prefer = (U8)pch;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_PCH, req_msg);
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pch_mode_rsp
 * DESCRIPTION
 *  This function is response function of set PCH status 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_set_pch_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_PCH, 
        rsp_msg_buff);
}

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
void srv_netset_get_peer_pch_mode(mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_get_peer_pch_mode(%d)", ptr_func);
    if (srv_netset_set_op_rsp_func(MMI_SIM1, SRV_NETSET_OP_GET_PEER_PCH, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(MMI_SIM1, SRV_NETSET_OP_GET_PEER_PCH, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_pch_mode_rsp
 * DESCRIPTION
 *  This function is response function of get PCH state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_get_peer_pch_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_peer_pch_mode_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_PEER_PCH, 
        rsp_msg_buff);
}


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
void srv_netset_set_peer_pch_mode(mmi_sim_enum sim, MMI_BOOL monitor_peer_pch_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_monitor_peer_pch_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_msg = (mmi_nw_set_monitor_peer_pch_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_monitor_peer_pch_req_struct));
    req_msg->on_off = monitor_peer_pch_on;

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(sim), MSG_ID_MMI_NW_SET_MONITOR_PEER_PCH_REQ, (oslParaType*)req_msg, NULL);
}
#endif
/* PCH Function Support */

/* HSPA Function */
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
void srv_netset_get_hspa_mode(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_hspa_mode(%d %d)", sim_type, ptr_func);
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_HSPA, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_HSPA, NULL);
    }
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_hspa_mode_rsp
 * DESCRIPTION
 *  RSP function for get HSPA mode state 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_get_hspa_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_get_hspa_mode_rsp(%d %d)", rsp_msg_buff, mod_src);
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_HSPA, 
        rsp_msg_buff);
}
 
 
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_hspa_mode
 * DESCRIPTION
 *  This function is for HSPA mode setting 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_hspa_mode(mmi_sim_enum sim_type, srv_netset_hspa_mode_enum hspa, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_hspa_mode_req_struct *req_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_HSPA, ptr_func, user_data))
    {
		req_msg = (mmi_nw_set_hspa_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_hspa_mode_req_struct));
        req_msg->hspa_mode = (U8)hspa;
        req_msg->apply_mode = 0;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_HSPA, req_msg);
    }
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_hspa_mode_rsp
 * DESCRIPTION
 *  RSP function for set HSPA mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_set_hspa_mode_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_HSPA, 
        rsp_msg_buff);
}
#ifdef __MMI_3G_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_3g_sim_capability_req
 * DESCRIPTION
 *  This function is for 3g sim capability request 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_3g_sim_capability_req(mmi_sim_enum sim_type, srv_netset_rat_mode_enum rat, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_set_sim_capability_req_struct *req_msg = NULL;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_SET_3G_SIM_CAPABILITY, ptr_func, user_data))
    {
		req_msg = (mmi_l4c_set_sim_capability_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_set_sim_capability_req_struct));
        req_msg->setting = sim_type;
        req_msg->new_rat = L4C_RAT_GSM_UMTS;
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_SET_3G_SIM_CAPABILITY, req_msg);
    }
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_3g_sim_capability_rsp
 * DESCRIPTION
 *  This function is for 3g sim capability rsp 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_set_3g_sim_capability_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_SET_3G_SIM_CAPABILITY, 
        rsp_msg_buff);
}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_3g_sim_capability_req
 * DESCRIPTION
 *  This function is to get 3g sim capability req 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_get_3g_sim_capability_req(mmi_sim_enum sim_type, mmi_proc_func ptr_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_netset_set_op_rsp_func(sim_type, SRV_NETSET_OP_GET_3G_SIM_CAPABILITY, ptr_func, user_data))
    {
        srv_netset_set_op_cntx(sim_type, SRV_NETSET_OP_GET_3G_SIM_CAPABILITY, NULL);
    }

}

 
/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_3g_sim_capability_rsp
 * DESCRIPTION
 *  This function is to get 3g sim capability rsp 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_get_3g_sim_capability_rsp(void* rsp_msg_buff, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_op_rsp_done(
        mmi_frm_l4c_mod_to_sim((module_type)mod_src), 
        SRV_NETSET_OP_GET_3G_SIM_CAPABILITY, 
        rsp_msg_buff);

}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_update_noof_plmn_supported
 * DESCRIPTION
 *  This function is a call back for MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND
 * PARAMETERS
 *  iMsg        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET	srv_net_get_sim_capability_set_init(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	mmi_l4c_get_sim_capability_rsp_struct *rsp_msg = NULL;
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)param)->rsp_data.get_sim_capability_rsp_data;
	
    WriteValue(NVRAM_NETSET_3G_CAPACITY_SIM, &rsp_msg->setting, DS_BYTE, &error);
	return MMI_RET_OK;
}

#endif /* __MMI_3G_SWITCH__ */
 
/*
 *    Preferred Mode
 */
#ifdef __MMI_WLAN_FEATURES__
static srv_netset_pref_mode_enum g_srv_netset_current_pref_mode;
static srv_netset_pref_mode_enum g_srv_netset_select_pref_mode;
static mmi_proc_func g_srv_netset_pref_mode_callback;
static void *g_srv_netset_set_pref_mode_user_data;
#endif
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
srv_netset_pref_mode_enum srv_netset_get_pref_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    srv_netset_init_pref_mode();

    return g_srv_netset_current_pref_mode;
#else /* __MMI_WLAN_FEATURES__ */
    return P_GSM_ONLY;
#endif /* __MMI_WLAN_FEATURES__ */
}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_mode
 * DESCRIPTION
 *  Set preferred mode in NVRAM 
 * PARAMETERS
 *  U8    [IN]    mode
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_pref_mode(srv_netset_pref_mode_enum mode, MMI_BOOL check_sim, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_req_struct switch_info;
    U8 current_mode = srv_netset_get_pref_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE2(0, "[NetSetSrv.c] srv_netset_set_pref_mode() mode(%d), check_sim(%d)", mode, check_sim);
	memset(&switch_info, 0x00, sizeof(srv_mode_switch_req_struct));

    g_srv_netset_pref_mode_callback = callback;
    g_srv_netset_select_pref_mode = mode;

    if (mode == current_mode)
    {
        srv_netset_rsp_event_struct rsp_data;
        rsp_data.result = MMI_TRUE;
        srv_netset_set_pref_mode_rsp((mmi_event_struct*)&rsp_data);
        return;
    }
	if ((current_mode == P_GSM_ONLY) && (mode != P_GSM_ONLY))	/* GSM only -> others */
	{
		switch_info.wlan = 1;
	}
	else if ((current_mode != P_GSM_ONLY) && (mode == P_GSM_ONLY))	/* WLAN on -> WLAN off */
	{
		switch_info.wlan = 0;
	}
	else
	{
		switch_info.wlan = 0xFF;
	}

	switch_info.bt = 0xFF;

	if ((current_mode == P_WLAN_ONLY) && (mode != P_WLAN_ONLY))
	{
        //#ifdef __MMI_DUAL_SIM_MASTER__
        srv_mode_switch_type_enum prev_mode = srv_netset_get_prev_rf_mode();
        U32 i;
        switch_info.rf = 0;
        if(check_sim)
        {
            for (i = 0; i < MMI_MAX_SIM_NUM; i++)
        	{
                mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        		if (srv_sim_ctrl_is_inserted(sim)
                    && (prev_mode & sim))
            	{
            	    switch_info.rf |= sim;
            	}
        	}
        }
        else
        {
            switch_info.rf = prev_mode;
        }
        
	}
	else if ((current_mode != P_WLAN_ONLY) && (mode == P_WLAN_ONLY))
	{
            srv_netset_save_prev_rf_mode(srv_mode_switch_get_current_mode());
	    switch_info.rf = 0;
	}
	else
	{
		switch_info.rf = 0xFF;
	}
    g_srv_netset_set_pref_mode_user_data = user_data;
    
	NETSET_TRACE3(0, "[srv_netset_set_pref_mode.c] switch_info bt[%d] wlan[%d] gsm[%d]", switch_info.bt, switch_info.wlan, switch_info.rf);
    if(switch_info.rf != 0xFF || switch_info.wlan != 0xFF)
    {
	    srv_mode_switch_switch_network_mode_ext(switch_info, srv_netset_set_pref_mode_rsp, NULL); 
    }
    else
    {
        /* No switch needed call RSP */
        srv_mode_switch_rsp_event_struct evt;
        evt.result = MMI_TRUE;
        srv_netset_set_pref_mode_rsp((mmi_event_struct*)&evt);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_pref_mode_rsp
 * DESCRIPTION
 *  Response function for set preferred mode 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_netset_set_pref_mode_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_netset_rsp_event_struct rsp_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((srv_mode_switch_rsp_event_struct*)evt)->result)
	{
    	srv_netset_save_pref_mode(g_srv_netset_select_pref_mode);
	}

    rsp_data.result = ((srv_mode_switch_rsp_event_struct*)evt)->result;
    rsp_data.evt_id = EVT_ID_SRV_NETSET_SET_PREF_MODE_RSP;
    rsp_data.user_data = g_srv_netset_set_pref_mode_user_data;
    (*g_srv_netset_pref_mode_callback)((mmi_event_struct*)&rsp_data);
    return MMI_RET_OK;
}


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
void srv_netset_save_prev_rf_mode(srv_mode_switch_type_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (U8)mode;
    WriteValue(NVRAM_NETSET_PREFERRED_MODE_PREV_RF_MODE, &data, DS_BYTE, &error);
    NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_save_prev_rf_mode %d", data);
}


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
srv_mode_switch_type_enum srv_netset_get_prev_rf_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_NETSET_PREFERRED_MODE_PREV_RF_MODE, &data, DS_BYTE, &error);
    return (srv_mode_switch_type_enum)data;
}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_save_pref_mode
 * DESCRIPTION
 *  Save preferred mode setting in NVRAM 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_netset_save_pref_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 current_mode;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_NETSET_PREFERRED_MODE, &current_mode, DS_BYTE, &error);
    
    if (mode >= SRV_NETSET_PREF_MODE_MODE_END)
    {
        mode = current_mode;

    }
    WriteValue(NVRAM_NETSET_PREFERRED_MODE, &mode, DS_BYTE, &error);
    g_srv_netset_current_pref_mode = (srv_netset_pref_mode_enum)mode;
	NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_set_pref_mode set %d", current_mode);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_netset_init_pref_mode
 * DESCRIPTION
 *  Set preffered mode global variable at bootup, DO NOT USED. 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_init_pref_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_WLAN_FEATURES__
    static MMI_BOOL is_init = MMI_FALSE;
    S16 error;
    U8 current_mode;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_init)
	{
	    return;
	}
    is_init = MMI_TRUE;
    ReadValue(NVRAM_NETSET_PREFERRED_MODE, &current_mode, DS_BYTE, &error);
    if (current_mode >= SRV_NETSET_PREF_MODE_MODE_END)
    {
        current_mode = P_GSM_PREFERRED;
        WriteValue(NVRAM_NETSET_PREFERRED_MODE, &current_mode, DS_BYTE, &error);
    }    
    g_srv_netset_current_pref_mode = (srv_netset_pref_mode_enum)current_mode;
	NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_init_pref_mode (%d)", g_srv_netset_current_pref_mode);    
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_group_id
 * DESCRIPTION
 *  Get the group ID of input PLMN 
 * PARAMETERS
 *  plmn
 * RETURNS
 *  S16 : group id, -1 no group
 *****************************************************************************/
static S16 srv_netset_get_plmn_group_id(const CHAR* plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 plmn_bcd = srv_netset_plmn_str_2_bcd_short(plmn);
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; plmn_group_index[i].mccmnc_bcd != 0; i++)
	{
		if (plmn_group_index[i].mccmnc_bcd == plmn_bcd)
		{
		    return plmn_group_index[i].group_id;
		}
	}
    return -1;
}


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
MMI_BOOL srv_netset_is_plmn_roaming(CHAR *sim_plmn, CHAR *bcch_plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_plmn_str_1[MAX_PLMN_LEN];
    U8 sim_plmn_str_2[MAX_PLMN_LEN + 1];
    S16 sim_plmn_idx_1;
    S16 sim_plmn_idx_2;
    S16 bcch_plmn_idx; 
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(sim_plmn_str_1, sim_plmn, 5);    /* assumed that Home PLMN is 5-digit */
    sim_plmn_str_1[5] = 0;
    memcpy(sim_plmn_str_2, sim_plmn, 6);    /* assumed that Home PLMN is 6-digit */
    sim_plmn_str_2[6] = 0;
    
    if (memcmp(bcch_plmn, sim_plmn_str_1, 5) == 0
        || memcmp(bcch_plmn, sim_plmn_str_2, 6) == 0)
	{
	    ret = MMI_FALSE;
        goto result;
	}
    
    sim_plmn_idx_1 = srv_netset_get_plmn_group_id((CHAR*)sim_plmn_str_1);
    sim_plmn_idx_2 = srv_netset_get_plmn_group_id((CHAR*)sim_plmn_str_2);
    bcch_plmn_idx = srv_netset_get_plmn_group_id(bcch_plmn);

    if (bcch_plmn_idx == -1)
	{
	    ret = MMI_TRUE;
        goto result;
	}
    
    if (sim_plmn_idx_1 != -1 && sim_plmn_idx_1 == bcch_plmn_idx)
    {
	    ret = MMI_FALSE;
        goto result;

    }
    
    if (sim_plmn_idx_2 != -1 && sim_plmn_idx_2 == bcch_plmn_idx)
    {
	    ret = MMI_FALSE;
        goto result;

    }
    ret = MMI_TRUE;
    
result:
	NETSET_TRACE1(0, "[NetSetSrv.c] srv_netset_is_plmn_roaming() ret= %d", ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_index
 * DESCRIPTION
 *  Get PLMN index in plmn_mccmnc_bcd and plmn_index table, the index is from string_index
 *  You can use this index to find specific string ID in MMI or check if PLMNs are
 *  from the same operator.
 *  The checking is simplely compare the PLMN BCD.
 * PARAMETERS
 *  plmn    :   [IN]    PLMN string to be searched
 * RETURNS
 *  U16 index
 *****************************************************************************/
S16 srv_netset_get_plmn_index(CHAR *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 plmn_bcd = srv_netset_plmn_str_2_bcd_short((const CHAR*)plmn);
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; plmn_mccmnc_bcd[i] != 0; i++)
	{
		if (plmn_mccmnc_bcd[i] == plmn_bcd)
		{
		    return plmn_index[i];
		}
	}
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_plmn_index_ext
 * DESCRIPTION
 *  Get PLMN index in plmn_mccmnc_bcd and plmn_index table, the index is from string_index
 *  You can use this index to find specific string ID in MMI or check if PLMNs are
 *  from the same operator.
 *  The checking using matching criteria of 23.122.
 * PARAMETERS
 *  plmn    :   [IN]    PLMN from BCCH
 * RETURNS
 *  U16 index
 *****************************************************************************/
S16 srv_netset_get_plmn_index_ext(const CHAR *plmn, MMI_BOOL is_band_pcs1900)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 plmn_from_table[MAX_PLMN_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; plmn_mccmnc_bcd[i] != 0; i++)
	{
        applib_plmn_convert_bcd_2_string((U8*)(&(plmn_mccmnc_bcd[i])), 3, (CHAR*)plmn_from_table, (MAX_PLMN_LEN + 1));
		if (applib_plmn_is_matched((CHAR*)plmn_from_table, plmn, is_band_pcs1900))
		{
		    return plmn_index[i];
		}
	}
    return -1;
}


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
S16 srv_netset_get_opname(const U8 *plmn, WCHAR *opname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_netset_get_plmn_index_ext((const CHAR*)plmn, MMI_TRUE);
    if (index != -1)
	{
	    mmi_ucs2cpy((CHAR*)opname, GetString(index + STR_PLMN_NAME_1));
        return index;
	}

    index = srv_netset_get_plmn_index_ext((const CHAR*)plmn, MMI_FALSE);
    if (index != -1)
	{
	    mmi_ucs2cpy((CHAR*)opname, GetString(index + STR_PLMN_NAME_1));
        return index;
	}

    if (opname && strlen((CHAR*) plmn))
    {
        mmi_asc_to_ucs2((CHAR*) opname, (CHAR*) plmn);
    }
    return -1;
}

static U8 g_srv_netset_is_plmn_table_size_checked;
static U32 g_srv_netset_plmn_table_size;

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
U32 srv_netset_get_system_plmn_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_netset_is_plmn_table_size_checked)
	{
        g_srv_netset_plmn_table_size = 0;
        while(plmn_mccmnc_bcd[g_srv_netset_plmn_table_size] != 0)
        {
            g_srv_netset_plmn_table_size ++;
        }
	}
    return g_srv_netset_plmn_table_size;    
}


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
MMI_BOOL srv_netset_get_sys_plmn_mccmnc(U32 index, CHAR *plmn, U8 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > srv_netset_get_system_plmn_number())
	{
        /* Out of range */
	    return MMI_FALSE;
	}
    if (buffer_len < SRV_NETSET_MIN_PLMN_LEN)
	{
	    return MMI_FALSE;
	}
    applib_plmn_convert_bcd_2_string((U8*)(&(plmn_mccmnc_bcd[index])), 3,  plmn, (MAX_PLMN_LEN + 1));
    return MMI_TRUE;
}

 
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
MMI_BOOL srv_netset_get_sys_plmn_opname(U32 index, WCHAR *opname, U8 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* string_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > srv_netset_get_system_plmn_number())
	{
        /* Out of range */
	    return MMI_FALSE;
	}
    
    string_ptr = (WCHAR*)GetString(STR_PLMN_NAME_1 + plmn_index[index]);
    if(app_ucs2_strlen((kal_int8 *)string_ptr) > buffer_len)
    {
        /* buffer length is not enough */
        return MMI_FALSE;
    }
    app_ucs2_strcpy((kal_int8*)opname, (kal_int8*)string_ptr);
	return  MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_plmn_str_2_bcd_short
 * DESCRIPTION
 *  Convert PLMN string to bcd code
 * PARAMETERS
 *  plmn        [IN]     input PLMN string
 * RETURNS
 *  U32 bcd code
 *****************************************************************************/
static U32 srv_netset_plmn_str_2_bcd_short(const CHAR *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 b1;
    U32 b2;
    U32 b3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b1 = (*plmn - 0x30) + ((*(plmn + 1) - 0x30) << 4);
    b2 = (*(plmn + 2) - 0x30) + (*(plmn + 5) == 0 ? 0xF0 : ((*(plmn + 5) - 0x30) << 4));
    b3 = (*(plmn + 3) - 0x30) + ((*(plmn + 4) - 0x30) << 4);
    return b1 + (b2 << 8) + (b3 << 16);
}


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
MMI_BOOL srv_netset_is_t_mobile_us_sim(CHAR *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 plmn_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE1(0, "[NetSetAppNWSelect.c] gHomePLMNNum[%s]", plmn);

    if (memcmp(plmn, "310", 3) != 0)
    {
        return MMI_FALSE; /* not in United States */
    }

    plmn_idx = srv_netset_get_plmn_index(plmn);    
    if (plmn_idx == -1)
	{
	    return MMI_FALSE;
	}
    
    if (app_ucs2_strcmp((kal_int8*)GetString((U16)(STR_PLMN_NAME_1 + plmn_idx)), (kal_int8*) L"T-Mobile") == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE; /* not T-Mobile SIM */
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_netset_get_noof_plmn_supported
 * DESCRIPTION
 *  This function returns the value for plmn_supported_num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_netset_get_noof_plmn_supported(mmi_sim_enum sim_type)
{
    return g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_type)].plmn_supported_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_adp_init
 * DESCRIPTION
 *  This function initializes all network related protocol handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_netset_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_netset_update_noof_plmn_supported, PRT_PLMN_LIST_IND);
#ifdef __MANUAL_MODE_NW_SEL__
    SetProtocolEventHandler(PLMNSelectionModeIndication, MSG_ID_MMI_NW_SEL_MODE_IND);
#endif
#ifdef __MMI_3G_SWITCH__
	srv_netset_get_3g_sim_capability_req(MMI_SIM1, srv_net_get_sim_capability_set_init, NULL);
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_netset_update_noof_plmn_supported
 * DESCRIPTION
 *  This function is a call back for MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND
 * PARAMETERS
 *  iMsg        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_netset_update_noof_plmn_supported(void *iMsg, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_support_plmn_list_ind_struct *local_data = (mmi_smu_support_plmn_list_ind_struct*) iMsg;
    mmi_sim_enum sim_idx; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_idx = mmi_frm_l4c_mod_to_sim((module_type)mod_src);
    g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_idx)].plmn_supported_num = local_data->length;
    
}

#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_inject_network_attachment
 * DESCRIPTION
 *  This function is message injection to MMI for network attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_inject_network_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_attach_ind_struct *nw_attach_ind[MMI_SIM_TOTAL];
    MYQUEUE Message[MMI_SIM_TOTAL];
    U8 loop_var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(loop_var = 0; loop_var < MMI_SIM_TOTAL; loop_var++)
    {
        nw_attach_ind[loop_var] = (mmi_nw_attach_ind_struct*) OslConstructDataPtr(sizeof(mmi_nw_attach_ind_struct));
    
        nw_attach_ind[loop_var]->status = L4C_RAC_OK;
        nw_attach_ind[loop_var]->gprs_status = L4C_GPRS_DETACHED;
        nw_attach_ind[loop_var]->plmn[0] = 0x34;
        nw_attach_ind[loop_var]->plmn[1] = 0x36;
        nw_attach_ind[loop_var]->plmn[2] = 0x36;
        nw_attach_ind[loop_var]->plmn[3] = 0x39;
        nw_attach_ind[loop_var]->plmn[4] = 0x37;
        nw_attach_ind[loop_var]->plmn[5] = 0;
    
        Message[loop_var].oslSrcId = MOD_L4C+loop_var;
        Message[loop_var].oslDestId = MOD_MMI;
        Message[loop_var].oslMsgId = PRT_NW_ATTACH_IND;
        Message[loop_var].oslDataPtr = (oslParaType*) nw_attach_ind[loop_var];
        Message[loop_var].oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message[loop_var]);
    }
}
#endif /* __MTK_TARGET__ */


#ifdef __MANUAL_MODE_NW_SEL__
/*****************************************************************************
 * FUNCTION
 *  PLMNSelectionModeIndication
 * DESCRIPTION
 *  Callback function for PLMN selection mode indication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void PLMNSelectionModeIndication(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_sel_mode_ind_struct *local_data = (mmi_nw_sel_mode_ind_struct*) info;
    mmi_sim_enum sim_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_idx = mmi_frm_l4c_mod_to_sim((module_type)mod_src);
    if (local_data->network_mode == MANUAL_MODE)
    {
        g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_idx)].nw_selection_mode = SRV_NETSET_MANUAL_SEL;
    }
    else
    {
        g_netset_app_srv_vars[mmi_frm_sim_to_index(sim_idx)].nw_selection_mode = SRV_NETSET_AUTO_SEL;
    }
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_idle_update_service_area();
    #endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_netset_set_3g_capacity_sim
 * DESCRIPTION
 *  Callback function for PLMN selection mode indication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_netset_set_3g_capacity_sim(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_NETSET_3G_CAPACITY_SIM, &sim_id, DS_BYTE, &error);

}
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
mmi_sim_enum srv_netset_get_3g_capability_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 sim_id;
	S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_NETSET_3G_CAPACITY_SIM, &sim_id, DS_BYTE, &error);
	return (mmi_sim_enum)sim_id;
}


